#include "TwistExpander_Badminton.hpp"
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

TwistExpander_Badminton::TwistExpander_Badminton()
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

void TwistExpander_Badminton::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 16323345331775019558U;
        aCarry = 11939368232790042954U;
        aWandererA = 13425986136936005361U;
        aWandererB = 12140209890641027355U;
        aWandererC = 10774782044311177673U;
        aWandererD = 18287249208371963485U;
        aWandererE = 15135843868644608353U;
        aWandererF = 17259328727161288806U;
        aWandererG = 16030711743992347388U;
        aWandererH = 16728795735233258420U;
        aWandererI = 14886547948556977346U;
        aWandererJ = 15991992711280160794U;
        aWandererK = 17698273150805701727U;
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
    TwistExpander_Badminton_Arx aArx;
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
    TwistExpander_Badminton_Arx aKDF_A_BArx;
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
    TwistExpander_Badminton_Arx aKDF_A_CArx;
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
    TwistExpander_Badminton_Arx aKDF_A_DArx;
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

void TwistExpander_Badminton::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12809284826629837714U;
        aCarry = 18181375313631667084U;
        aWandererA = 16637813479186866653U;
        aWandererB = 9816400605758554313U;
        aWandererC = 15209590082422545783U;
        aWandererD = 10804836076996916352U;
        aWandererE = 14116187208225163465U;
        aWandererF = 12415205809962910460U;
        aWandererG = 15183391218521278078U;
        aWandererH = 17718017290425873146U;
        aWandererI = 18309014734822223803U;
        aWandererJ = 9893206877633626162U;
        aWandererK = 18078537450418351992U;
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
    TwistExpander_Badminton_Arx aKDF_B_AArx;
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
    TwistExpander_Badminton_Arx aKDF_B_BArx;
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
    TwistExpander_Badminton_Arx aKDF_B_CArx;
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

void TwistExpander_Badminton::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBBE6B90B1281A945ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xC7AA72441265B4B4ULL;

    std::uint64_t aWandererA = 0xE3A722B42C442C94ULL;
    std::uint64_t aWandererB = 0xE0797AE3485F6BCAULL;
    std::uint64_t aWandererC = 0xDAF363D56CCB87D3ULL;
    std::uint64_t aWandererD = 0xB8BA21959BA1C12DULL;
    std::uint64_t aWandererE = 0xF92D5A13CD114A3CULL;
    std::uint64_t aWandererF = 0x989C866944D1A771ULL;
    std::uint64_t aWandererG = 0xC67172B727559D00ULL;
    std::uint64_t aWandererH = 0xD2491899D651A8A1ULL;
    std::uint64_t aWandererI = 0xBB0FBE4CCCAB16B5ULL;
    std::uint64_t aWandererJ = 0x9E601AC2FAB1BDF6ULL;
    std::uint64_t aWandererK = 0x8B4C91A76191E638ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_Badminton_Arx aSeed_AArx;
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
    TwistExpander_Badminton_Arx aSeed_BArx;
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
    TwistExpander_Badminton_Arx aSeed_CArx;
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
    TwistExpander_Badminton_Arx aSeed_DArx;
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
    TwistExpander_Badminton_Arx aSeed_EArx;
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
    TwistExpander_Badminton_Arx aSeed_FArx;
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
    TwistExpander_Badminton_Arx aSeed_GArx;
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
    TwistExpander_Badminton_Arx aGrow_AArx;
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
    TwistExpander_Badminton_Arx aGrow_BArx;
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

void TwistExpander_Badminton::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Badminton::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 14349071782350912868U;
        aCarry = 13568199111131212914U;
        aWandererA = 15641485655684041892U;
        aWandererB = 17176154023926709125U;
        aWandererC = 16219364061630815763U;
        aWandererD = 15464594988065993875U;
        aWandererE = 11967972217668191687U;
        aWandererF = 15299167371937696738U;
        aWandererG = 9789854765771344048U;
        aWandererH = 9492200098463689052U;
        aWandererI = 15105641368824244931U;
        aWandererJ = 15216023210171238234U;
        aWandererK = 13689238523182523350U;
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
    TwistExpander_Badminton_Arx aTwist_AArx;
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
    TwistExpander_Badminton_Arx aTwist_BArx;
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
    TwistExpander_Badminton_Arx aTwist_CArx;
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
    TwistExpander_Badminton_Arx aTwist_DArx;
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
        TwistExpander_Badminton_Arx aGrow_AArx;
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
        TwistExpander_Badminton_Arx aGrow_BArx;
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

void TwistExpander_Badminton::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 2, 3, 3, 1 with offsets 6423U, 1152U, 281U, 2970U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6423U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1152U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 281U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2970U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 1, 2 with offsets 6648U, 1328U, 1410U, 6151U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6648U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1328U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1410U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6151U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 3 with offsets 5775U, 7788U, 2831U, 4150U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5775U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7788U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2831U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4150U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 0 with offsets 319U, 3750U, 1436U, 7460U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 319U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3750U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1436U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7460U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 148U, 1495U, 256U, 121U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 148U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1495U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 256U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 121U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 0, 1 with offsets 617U, 345U, 26U, 1658U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 617U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 345U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1658U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 1, 2 with offsets 877U, 878U, 166U, 352U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 877U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 878U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 166U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 352U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 2, 1 with offsets 696U, 769U, 902U, 1750U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 696U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 769U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 902U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1750U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1650U, 954U, 1278U, 1524U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1650U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 954U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1278U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1524U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Badminton::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 2 with offsets 5433U, 2063U, 6052U, 296U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5433U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2063U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6052U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 0 with offsets 5943U, 2499U, 1712U, 3142U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5943U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2499U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1712U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3142U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 3 with offsets 6135U, 1179U, 7984U, 6934U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6135U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1179U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7984U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6934U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 1 with offsets 6851U, 588U, 265U, 5264U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6851U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 265U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5264U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2339U, 6136U, 4674U, 4700U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2339U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6136U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4674U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4700U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1799U, 29U, 1863U, 521U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1799U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 29U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1863U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1120U, 804U, 189U, 436U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1120U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 804U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 189U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 436U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 29U, 1343U, 582U, 729U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 29U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1343U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 582U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 729U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 571U, 702U, 1725U, 853U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 571U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 702U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1725U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 853U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 1, 3 [0..<W_KEY]
        // offsets: 1258U, 502U, 1316U, 1418U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1258U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 502U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1316U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1418U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseASalts = {
    {
        {
            0x82A624A52CA60B85ULL, 0xF4D20E8F5E04697BULL, 0x29022A18572D708AULL, 0x20068E5C6AA741AEULL, 
            0x61AA09A9178FFE29ULL, 0xF3B664D8D8CCA66EULL, 0x284AA21B4F203EF6ULL, 0x6DB8C58548D7434EULL, 
            0x030E195F41F80B75ULL, 0x5365F9A1C2233F71ULL, 0x7C9C0C88F4F590F7ULL, 0x7B661552F9DE1908ULL, 
            0x23573C8354801F1CULL, 0x01AAE30B27DB5AC5ULL, 0xD7423872A66DC4D4ULL, 0xB5804A6DF40E8B7CULL, 
            0xA1722089FF00DBB5ULL, 0x707AAB8283F6A9E6ULL, 0x3DEBA12F3AFAF99DULL, 0x8F23024E2A28736CULL, 
            0xD001DF33221534C6ULL, 0x228FAC003A669892ULL, 0xA62257899EFF3F45ULL, 0xE8913E4EF4BD73B3ULL, 
            0x122B7EDB2C353EF4ULL, 0x8FB1DA5FD62863FDULL, 0x43240DA7052BD14BULL, 0xB2395571B52E86D6ULL, 
            0x5B2E4589890DFA6EULL, 0x6F49A686609D949CULL, 0x1B89526940F994D5ULL, 0x92A8FF52101EEF38ULL
        },
        {
            0x0707F23FEBA323DFULL, 0xB48464BE31047950ULL, 0xA539AF1B16771836ULL, 0x8C69C16C0A1ADFA6ULL, 
            0xB3DE481085B45F61ULL, 0x1E68124283CEEF47ULL, 0x977B576A1D0640BCULL, 0xD5DB4043405DB547ULL, 
            0x1168D665C0F34C8DULL, 0xA1F4B488C9257E50ULL, 0x146F25FB5BE49762ULL, 0xF1FA638E91A87BC8ULL, 
            0xB8E2E160B317AED3ULL, 0x2C1E134EA258BD7FULL, 0xEF9B5238B3410DEAULL, 0xCBE839C2D5DEAB1BULL, 
            0x2115F971A57C1053ULL, 0x196C73ABBB636D4BULL, 0x93C409F883FB6906ULL, 0xBFA51FB6508370FCULL, 
            0xFE3B175B9B1D6EEDULL, 0x63CCC11A2CA34350ULL, 0xB20D00A6A8715B3EULL, 0xC071ADBBE6C15C4CULL, 
            0x72AEAB8DC2B962F9ULL, 0x9B5E69890BB307D8ULL, 0x56A502C7D7EA6CFBULL, 0xD25572AB8453D4ACULL, 
            0x8CC1F73E3E6D0D0BULL, 0x9272FD2B0C7B8B2EULL, 0x72D1870208BDD770ULL, 0xFC1C63D1E3B5E174ULL
        },
        {
            0x7F1A802F7B2C9B08ULL, 0xE29DCF6E5254DA8BULL, 0x9393A8347780D1EAULL, 0xD36D11048B6DBCA7ULL, 
            0x10B662B849182227ULL, 0x5DEE9E303D262F53ULL, 0x81F9FE6F18731A0EULL, 0x0CB7F1D2178F24F5ULL, 
            0x63B91C63A5110909ULL, 0xB8E82D49F644BD4DULL, 0x5E32E07675DED0CFULL, 0x8FEFCCFD171070EFULL, 
            0x2D2500CEEDA3831DULL, 0xD0E2DFBA94EBEB33ULL, 0xB82FC3D592C97DC7ULL, 0x7F91A3F590B0AEB4ULL, 
            0xE1089010E1819CFCULL, 0xC23645EBEB3B02A8ULL, 0x07DA9B5A8E795218ULL, 0x7D0225C5516DF3D7ULL, 
            0xE3CDAA98D7F8DDD6ULL, 0x9F2934DE4A8F1C88ULL, 0x954F51688671E2D9ULL, 0x6BDFBC2E179E109AULL, 
            0xD433F6B829895312ULL, 0xF72FE6E0CAF930A5ULL, 0x24AEFFDAA038D71FULL, 0x35F22EF13324D1C3ULL, 
            0xE68B02CA7642F5FAULL, 0x8703FF32CB6182C9ULL, 0xA32696176EA241FFULL, 0xCDB1E5F3B31541BDULL
        },
        {
            0x1BCA0D9D87B56F03ULL, 0x2AF30C683F7B5BE7ULL, 0x050B5EF62CDD8BD5ULL, 0x61B643FB894487C2ULL, 
            0xB8CA55E0F2CC06C4ULL, 0xC69BFB066A5BBF4BULL, 0xAC344E7481AA4E68ULL, 0x4F68B09454E074F0ULL, 
            0x16E9743833C9D09EULL, 0xC6A993201DCE968BULL, 0x94FA27D52327F1CAULL, 0xE34A8054FB615BA4ULL, 
            0xE25A338ECC2410FEULL, 0x489A1C8835AD681FULL, 0xBC4B3799B6A46A81ULL, 0xF73326DAF07BAA13ULL, 
            0x1C54D884BFD10D29ULL, 0x4D2ED4792F28C8FEULL, 0xE312C16BF3CD430AULL, 0xCDF94B50CE24721AULL, 
            0xC0D9B5A48FA2DD7CULL, 0xDD6BDD0826D64EAFULL, 0x8052881E50DF2028ULL, 0xC5BC869D8F4E5566ULL, 
            0x39E320D8F0C16B7FULL, 0x5F21349C5B2DF5DBULL, 0x74F36889C08E2AAEULL, 0x18BA4356ADE90609ULL, 
            0xF41C65F01D5712F2ULL, 0x064659DB24C72F27ULL, 0x5F293A4AA192E6E9ULL, 0x90A8F05E2E4F3F3AULL
        },
        {
            0xAF13458CE1012737ULL, 0xF091D0772DB010F2ULL, 0xECA76273312B1DC4ULL, 0xF868695421384031ULL, 
            0x78198E999355EB16ULL, 0x325E03CDB1C17A45ULL, 0x0CC2C8AD575DCA68ULL, 0x036DA123C9AAFDA6ULL, 
            0x065AC6CF0A6A88F4ULL, 0x5B87D240384C37FDULL, 0x959FBB7CA9A70513ULL, 0xA130A96540E18015ULL, 
            0x5E4548D5D0DA19E0ULL, 0xBC6FAEA3602707E5ULL, 0x40B5F878CFD2ED9CULL, 0x54FBC5251EDAC14CULL, 
            0x2BAF9163EE65BACFULL, 0x9680644E48CCF3F4ULL, 0xA23E6F7F4CD46C42ULL, 0x5FB84E4CBEEBF4DFULL, 
            0x6D8AD6B9E573DF0FULL, 0xF6AEEA0F6D8707EAULL, 0x226ADEC7C4671010ULL, 0x6805AE962002E5D9ULL, 
            0x159159AAB8D9E931ULL, 0xE483FBBC12FA6BF0ULL, 0x578F854A90CB6E39ULL, 0x0DC71400595C680CULL, 
            0xD33657CD7730363CULL, 0x62AA306A746CCE89ULL, 0x4AD8681DB1CC69FDULL, 0xE70A2C6841CCF767ULL
        },
        {
            0xFFDCE69DF48F24A5ULL, 0x35A191C910B70C27ULL, 0x82422DC1C68D8033ULL, 0xD516F382C82920D0ULL, 
            0xBE35B0C76B87AFA0ULL, 0x7208CA42EB7BB2FFULL, 0x94F9F39E73A093EEULL, 0x8346C70A4E8D436AULL, 
            0xC6AFE51EE6D3597BULL, 0x2C54BE4A15BA5078ULL, 0x70932ED88CD29A07ULL, 0xF48CF84FE2DC045DULL, 
            0x28B1BF849AC86025ULL, 0x2C1211ABE58C6BD7ULL, 0x6D293E2E30F0FF27ULL, 0xA5F9C945615C29F6ULL, 
            0x2A896F6579CBBD53ULL, 0x199B8C1CAADAB7B2ULL, 0x96451747B9328B43ULL, 0xB11CFE2F9165FF19ULL, 
            0x7287369D5A16E61EULL, 0xCB6E7EAE09336B1DULL, 0x838874FE0694F036ULL, 0xEC47368FA0CC9ABCULL, 
            0x1DD4C256840E403DULL, 0x40301B6B94F0BDBCULL, 0x19FD2EE02D397CC2ULL, 0x5905EE8D3C4A005CULL, 
            0x2B344E76FFFB23CBULL, 0xC04C1A389C6AF0F5ULL, 0xDE7AB52C7752E29AULL, 0x2AFC3CD04E1FE7CCULL
        }
    },
    {
        {
            0x7F10D204C604AAC1ULL, 0x7E055A70BEEE1CF2ULL, 0x74489B076DF60389ULL, 0x93C78A3778341404ULL, 
            0x2D3B51A6069614F2ULL, 0x9FACF4E91C77873AULL, 0xBC5BDB5FA063E512ULL, 0x1205B5A02129217DULL, 
            0x1D5B4B39C14EEE89ULL, 0x91DCBF558378B8BDULL, 0xF065E303FB8ECF47ULL, 0x29F5F498137B8A3BULL, 
            0x7E2D2B5B2CD1D984ULL, 0xBF209E324697602CULL, 0xB5F2E686CB515872ULL, 0xAC8F132834FF4804ULL, 
            0x60E7E773866F3C56ULL, 0xC46D6D2074FA9AD9ULL, 0xE830FA24307FE3FAULL, 0x37D00B9798DCB2FAULL, 
            0x280F62AE423C54ABULL, 0xD42C3FDE25AA3898ULL, 0xDE45E2604519F90CULL, 0xDB2C1E79F77291D6ULL, 
            0xD0A2B843A851F3CEULL, 0x31FBA2F899F83F88ULL, 0x0A78DAB667C207ACULL, 0x2730D3C2FC5132A9ULL, 
            0xABFBB747EF5E3663ULL, 0x1D501922BC6EC744ULL, 0xF80496F20ACD3FFFULL, 0xEBF628CE55B56DB2ULL
        },
        {
            0xAA6A9B664071F67FULL, 0x157D2E83F856E28DULL, 0xC9CB1F1D51DC9F9DULL, 0x58E3C4F274AF90BFULL, 
            0xCE3A061DC384B414ULL, 0x4D88E10D5D183754ULL, 0xAD649C9B79717D65ULL, 0xADBCB322B8DFC128ULL, 
            0x75CC7EB9DB8A13DAULL, 0xEF3601C8BFC75905ULL, 0xE57CB7B772980C66ULL, 0x40EC5426059FA467ULL, 
            0xE2CEC16C5F7E7E8DULL, 0x5039C3CF6D192620ULL, 0xB7ADB5F5B75EBD32ULL, 0x1F5F92DAC8A58844ULL, 
            0xCD97953A750D7A30ULL, 0xCA81D7E6752F43DCULL, 0x967709433C32DB4BULL, 0x0E400F876DAD111DULL, 
            0xB2214CA8354123ECULL, 0x32B16D6F7F322542ULL, 0x00EA8571DAFD3AFBULL, 0x80183BD9548B8905ULL, 
            0xAE2FFA52AA443168ULL, 0x7914AAB9F6F4A7C4ULL, 0x2486C66D3E3B1B4AULL, 0xF4071D9B1F2D9829ULL, 
            0x9CC05C5B701C6B45ULL, 0x98D599DA50C15382ULL, 0x19CB06504B60964AULL, 0xD92E4F2139C9CB55ULL
        },
        {
            0xD7E828CD9AC5DA3DULL, 0x96CB78D3FD881161ULL, 0x029AAC65AD5FAB61ULL, 0xEA6B303D12449474ULL, 
            0xF0F6F1742E7312D2ULL, 0xEC5DDF4631E7B898ULL, 0xD25DE8FEA0FEFB38ULL, 0x85C25ED311FAA408ULL, 
            0x2661EBB425DD840DULL, 0xE0FDE47986CA2319ULL, 0x772D99712E70D92EULL, 0x0E0D677CD965BC3BULL, 
            0xE2B6A49A5FCB32A4ULL, 0xA20FDB77A92E95CBULL, 0x13C1B57482159E7BULL, 0xBEE232CAB33BC81CULL, 
            0xE8DBA1FCC169C12EULL, 0xDC01AE3B70012842ULL, 0x462875154A96DDD9ULL, 0x174DFD7DCDAAE0FAULL, 
            0xADE700CB6455BE03ULL, 0xA6B11033DE841428ULL, 0xF8C82C0FD374A24BULL, 0x76BC8ECF64124565ULL, 
            0xF34F8D04AFF781A2ULL, 0x4AE05180DBF7A9F5ULL, 0x7BCFB98204AD671BULL, 0x5B67CC3839D9300CULL, 
            0xA2CED16161E0DA56ULL, 0x4822CF52BFBA2F53ULL, 0xE043E72EBFA1D334ULL, 0x3BE5154C21B3C580ULL
        },
        {
            0x92461ECA352C7C9EULL, 0x6EDEC53E092139A4ULL, 0x1BCF0007FABBBFDEULL, 0x64C27EC4EB28DD3FULL, 
            0x7FA90BB9B49549F8ULL, 0x4DAB44A545910D4FULL, 0x17F1A5F6025E19C6ULL, 0x9FC1A01D87E60454ULL, 
            0x0CC236D294E92222ULL, 0x785C7ED90FEC5EECULL, 0x121C9CA094CEF3CBULL, 0x311510F5F01AD835ULL, 
            0x5249FD3712C01A51ULL, 0xEEDA2DE0985F6512ULL, 0x7DB2BBFDD74C3B8CULL, 0x6AD2730230D6600AULL, 
            0xC51357DF67BAA6B9ULL, 0xC7F699FC62E2129DULL, 0x5B0039DE6E2D6109ULL, 0x53563FBFBD6A4A85ULL, 
            0x3A9576B04954BDE0ULL, 0x20796D9F13EC63EDULL, 0x58B77B98CF765917ULL, 0x37F819DDF661D86EULL, 
            0x00B553CD95D7B10CULL, 0x804551A413A6E89EULL, 0x506D87FFDCFA955EULL, 0x35577AF505BB06BEULL, 
            0xDA6D7BD5C5CFBC57ULL, 0x4A48CB4EA16D9F8FULL, 0xFAACD3D9AE86CB5BULL, 0xE1E7A43864377B8FULL
        },
        {
            0xA7AC38E2CD4FA6D6ULL, 0x596A74C419CE6931ULL, 0x8036749E77B17A28ULL, 0x4CE5BFB3BE055D58ULL, 
            0xF4643C3DCAD54D8FULL, 0x6B073E22DA64D670ULL, 0xCA2B25E6154E6112ULL, 0x2069CD55D67368B8ULL, 
            0x3C342EA11AF0F752ULL, 0x8CA2FB3EC272A9AAULL, 0x5390F0865778FC57ULL, 0x950ADD2EB5CFBBB0ULL, 
            0x2927FD9DBCAF60E1ULL, 0x08CA4ABFD19018E4ULL, 0xA3DC716B36DF5588ULL, 0x9BD3171CBB23E263ULL, 
            0xE1FB2699436BBA58ULL, 0x261F7A8716A7086FULL, 0xD987B4155429AD28ULL, 0xB3DF29D3464A2A79ULL, 
            0x74F8B0B455448E45ULL, 0xE0A2384C7EAB80B2ULL, 0xFDDA05E1DA168625ULL, 0x2B1A3A224528DEB6ULL, 
            0xD1A6AB2FD8F76043ULL, 0xBC8388C3D62EAFD8ULL, 0x90D49095161BB34FULL, 0xD93659B65F4D22F6ULL, 
            0x066250CDE92DC274ULL, 0xCE3A996489319404ULL, 0x2824C5BFF4DC17D7ULL, 0xDF57B51BA84201C4ULL
        },
        {
            0x95E88F47BEFF0A12ULL, 0x6095A9BA22C49BEFULL, 0xB491458ECE8927CDULL, 0xFDB75833FE71EFAEULL, 
            0x36242EADA2947BB9ULL, 0x597390B7FB9130F1ULL, 0x80476BBA770D284DULL, 0x4AAB06D1A504A36EULL, 
            0xB9067E4EB07F38ADULL, 0xFAED6069319B1694ULL, 0x3D1F44737B4D6C54ULL, 0xF240CDBEE3F6AD5DULL, 
            0x247AEE9EF1F398E8ULL, 0x3FCA415FB3314636ULL, 0x279DE3CE6FA7BDE0ULL, 0x98AA0C9C8F455579ULL, 
            0x9D530B2F5DE9C229ULL, 0x762D740AED434A80ULL, 0x433CC86D1020C525ULL, 0xA8CA27C853AD4265ULL, 
            0x4363AEF1196F4B07ULL, 0x9D5B276E72B1EA33ULL, 0x40958AD0C094F70FULL, 0xDF6BB0F7E6F5937AULL, 
            0xDD0783C32AD17D41ULL, 0x3495AFB18F5DAB03ULL, 0xDECECA2456110ADCULL, 0xC111EC5B1C8739F4ULL, 
            0x37299C82B8C8C730ULL, 0x4F5639A470A5D45AULL, 0xC71B948E96520F0BULL, 0x3B2FE279F29D7091ULL
        }
    },
    {
        {
            0xA858362EDBCDAA40ULL, 0x03C7A9F7B907C159ULL, 0xE0BC8F381317C8C9ULL, 0x212EFECA667C389FULL, 
            0x04A23C1917265E41ULL, 0x51D70FF9EBDBDA79ULL, 0x8B21417247685888ULL, 0xDC862B5F1B65931BULL, 
            0x06326108A596095AULL, 0x24DA6DEB6B408DD0ULL, 0x08182F8F955159EAULL, 0xE017C58DA98B9343ULL, 
            0xE92BDA974A7B5A5CULL, 0x107E7F99346F588EULL, 0xBB9B7F41A146EC81ULL, 0x0BE8E1B4B7BA7677ULL, 
            0xA8176A261B0996C3ULL, 0x2015582ACFE68083ULL, 0x5D6CD362A6135DB6ULL, 0xE9BED785960D04A7ULL, 
            0xA2FAA37CCB6458A6ULL, 0xE7DB2C79EADD055FULL, 0x731A43FC9A5F35B0ULL, 0xF26A57837B4919E1ULL, 
            0xE7E518D4A1892F65ULL, 0x15D7125F2316CC19ULL, 0x2163A0168293690FULL, 0x1636C7E3C1F56659ULL, 
            0x7AACFB0AF29DE771ULL, 0xC246125ADA5DCDBEULL, 0xE8E83C42849D5C58ULL, 0x738817649D9A4266ULL
        },
        {
            0x3EF952E6A120B5F6ULL, 0x9C4B7C15173FB357ULL, 0x64332767AD7982BAULL, 0x476EAFD5B7E95A91ULL, 
            0xB3671C676FE637CDULL, 0x80F0B2C9F0B1BC99ULL, 0x217843B83702D1EAULL, 0xEAF837E81AB8A255ULL, 
            0xACBF2D3BD6C5D95AULL, 0x9573A7C9D18C5E78ULL, 0xF965208DEEA448E5ULL, 0xFC1A090397D16171ULL, 
            0x8803A2EC9D220FB3ULL, 0x0F9919485E70224BULL, 0xF4A97B782B7D212AULL, 0xE0F5CA4C98B0D94CULL, 
            0xDDF70FCA9027DB2DULL, 0x0539CDFA166ADF16ULL, 0xB6E3589E7E3CC378ULL, 0x8A902608ACA7820FULL, 
            0x4989EB7EA7594DC2ULL, 0x6819AE60BB6AAFAAULL, 0xC6644C2626F748CDULL, 0xD3813FE4B6717A70ULL, 
            0x4E29B66A955AEEAFULL, 0xB033E6623C265072ULL, 0x16A14B963F8C74BBULL, 0x6A6BD5C1C7ABA9A7ULL, 
            0x8F7495227209685CULL, 0xB7DA32CEB166A7DEULL, 0xA15F2DA38727097AULL, 0x0B96C08A1450E1E2ULL
        },
        {
            0x9394C47AFD43266AULL, 0x77C2B5232DADF1DAULL, 0xC4EFD506D4E15C6BULL, 0xE6202818471E73D4ULL, 
            0xB2ADBFDD8ECB43ABULL, 0x15E257708408658EULL, 0x75039477BC1C3C5EULL, 0x6C17272EC66ED95AULL, 
            0x44FE619E9FD726F5ULL, 0xD762D54FBA01BE83ULL, 0xB4887F5235FBDD96ULL, 0xF1374DD3821CACCFULL, 
            0x35B3E6167A06B5C7ULL, 0x1AF94D753D6BFED6ULL, 0xBBEF2A25CB2BF3A9ULL, 0xC0DDCC6D743B269EULL, 
            0xB2C7B24F31219773ULL, 0x4D86F8F467B281A9ULL, 0x654FDACF57870D21ULL, 0x9B628C857E7D6258ULL, 
            0x3C0F382FCEE26C78ULL, 0xD9A9BB5B12EB0C64ULL, 0x514ABDEC1E18D884ULL, 0x35E52389951438DEULL, 
            0xFC5C43283AEE2D9CULL, 0x22E384B1A3483C47ULL, 0xEC24678DB8C6AB8BULL, 0x8D6A08265FB25BE4ULL, 
            0xC97E236F4CE0AD90ULL, 0x36323771E63C718BULL, 0x6BD91D9DF406AF4CULL, 0xF1605746F3BE02D4ULL
        },
        {
            0xC0AEA64D2AF76232ULL, 0x62A10EC1BE74BCAEULL, 0x19485D24E2A765EFULL, 0x4D004CE381D7339EULL, 
            0x1C8738E515ED0E57ULL, 0xD87EF4B984E560B7ULL, 0x6AEBA457514C0A39ULL, 0x751BFB154A6024FCULL, 
            0x0F7C0A893B816242ULL, 0xC9E5D182238ADD63ULL, 0xE51E45BBAB5D36A2ULL, 0xB5DD8CEDABF6A093ULL, 
            0xD606BAB3C3DE8B95ULL, 0x4FA2E2B4D54BD6B3ULL, 0x64FCBDAFF59CEB5CULL, 0x3006D6AF9C7BF530ULL, 
            0x34ECD2A9BA774D77ULL, 0xEDF99DACFA39AA1BULL, 0x82EAD7FE1DCFC4C7ULL, 0x930BA02B9E86A159ULL, 
            0xA5DEB2D77451EC99ULL, 0x2AF7F221D4050A04ULL, 0x5F1D3CBC39724E70ULL, 0xE43B5C499B521784ULL, 
            0x0ED7329857ACE829ULL, 0xAA704761B83B15CEULL, 0x06277A7D9E34279FULL, 0x6CF00B4C4175941EULL, 
            0xCDD90F640C5C70E4ULL, 0xF936A388CF225825ULL, 0xB26C43F58987162DULL, 0xF7632D38590F51B3ULL
        },
        {
            0x40D6D1CF18197868ULL, 0x203477F0AFA9DADDULL, 0xDB21ABD7FFB5E310ULL, 0xF0FEC5C9C739017CULL, 
            0xDAFE2E3A53D22555ULL, 0x4855B0BEF515162CULL, 0x038B047D2446C4A4ULL, 0x0193436C178DC4F6ULL, 
            0x5EDAF0A7B4E088F0ULL, 0xC9F86DCC66C3F130ULL, 0x2B44FC7B727055A7ULL, 0xAA8E17456E6DA510ULL, 
            0xCDE9CC47156A1A09ULL, 0x51396CCDC602DC1BULL, 0x4F66E24180F51C74ULL, 0xED484C68AC65AB19ULL, 
            0x09A61F1C12F2A321ULL, 0xFD2E571C4CC67054ULL, 0x472525346850FC33ULL, 0x00EC0F2FD0FFEC58ULL, 
            0x9648DD07A49ACAE4ULL, 0xBE30642FEDCC0CD2ULL, 0x4574D8256BF5FF71ULL, 0x8CB56B5B45C70420ULL, 
            0xD4EC9DC4B3EF81E1ULL, 0xFBE095129A5FA710ULL, 0xA9A708C3AB61505FULL, 0xB8AC547D49E25669ULL, 
            0xB51974CD1981271AULL, 0x1699A8D1CC4177AFULL, 0xE03B35DA6D29B8CAULL, 0x2F48F99B44446958ULL
        },
        {
            0xFBDF63858C3A11BCULL, 0x845B169E87F381D3ULL, 0x8910830954A7921DULL, 0xFDAF43E98AFAFE2CULL, 
            0xE20F78FFBCE33DD5ULL, 0x1319DA013A29849AULL, 0x0A839A2C338DCDBAULL, 0xA950F04BB56C78C5ULL, 
            0xF9F1DEADBD488438ULL, 0xDB7F6BFF4B3395F5ULL, 0x975A7BE0C92B3AB7ULL, 0x2290CF47303B8396ULL, 
            0xF21A8BA84A1916AFULL, 0xEB1564977AF26140ULL, 0xF44D1E76999D57F6ULL, 0x87DE8375566E7079ULL, 
            0xA0AE087225357268ULL, 0xF0E7F11B4948A52AULL, 0x7BF3775BA74F3B88ULL, 0xBD0106A9F071D194ULL, 
            0x2B5EAD9A7DEC4859ULL, 0xDA56155C59FFA9A4ULL, 0x128E27AC2C9269EAULL, 0xF9EE71952CB7C88EULL, 
            0x4A83ED566B3347F9ULL, 0x3D9315A61BB0AB5CULL, 0x6DCFDC07CF018A0CULL, 0xA0BED04F7AA9FF9BULL, 
            0x67590D513DDFA208ULL, 0xB0380D1664710C56ULL, 0x5C531C863450769BULL, 0x3B31D362C97F250EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseAConstants = {
    0x71DCE3A06ADA8439ULL,
    0x4B1D5D11A814A02BULL,
    0xB2358E9A3FFC9002ULL,
    0x71DCE3A06ADA8439ULL,
    0x4B1D5D11A814A02BULL,
    0xB2358E9A3FFC9002ULL,
    0xF28547B4E0FB5258ULL,
    0xB7246D53D669C59DULL,
    0xC0,
    0x71,
    0x91,
    0x2C,
    0xDF,
    0x9A,
    0x36,
    0xB4
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseBSalts = {
    {
        {
            0x99D66B1E8B4ED3D3ULL, 0xF27BD8660077089EULL, 0x5A59D6EEDD8B9108ULL, 0xCBA75E1C5CF4F114ULL, 
            0xF436E750BFA5816AULL, 0x9E90C9C122FF337DULL, 0x980739E2193DEAEFULL, 0xD6D8D4D9F8FA0B89ULL, 
            0xB9207374AC0E0A44ULL, 0xC0777614CC897FD6ULL, 0xC659004977DAD53DULL, 0x03E90D14D7214976ULL, 
            0x3331929C56BBBA4DULL, 0x57068E74EC1DCE25ULL, 0x295EB3589D472701ULL, 0x5725755CB4A92D51ULL, 
            0xA357DB45ACB6F7DDULL, 0xB6BA4C9B7EE33DA6ULL, 0x6472EEDC2B7A16D8ULL, 0x019D1AAC4CDD274FULL, 
            0xC7F9164655E02664ULL, 0x5E23DFB704C9D564ULL, 0xB288C60DE373F6B9ULL, 0x398B6B75BEEF04A3ULL, 
            0xA2FCC7EE1BD284B0ULL, 0x4F11C8A55D831B69ULL, 0x597C36A1927E6DD4ULL, 0x001D994A1CE88223ULL, 
            0x84C4D264E5525166ULL, 0x946541A56BC9C007ULL, 0xE4B590B16E9C2932ULL, 0x52FE1101E277E94EULL
        },
        {
            0x1278E96DE67A746FULL, 0x6A37E6184371B65FULL, 0x1774D1C524BD9238ULL, 0x80DBB82A76302348ULL, 
            0xD14429F96BF035CEULL, 0xB6C933FACF69CF80ULL, 0x183688C29689BB8AULL, 0x42F13BDB81EA8231ULL, 
            0xBF6C953DF06934D7ULL, 0x750ABCA3A21280FBULL, 0xA19897FD39776CC7ULL, 0xDA49506C080281A7ULL, 
            0xE9FBE75FE06EB545ULL, 0xF9EBD928E8A347C5ULL, 0x78D24CFF8FEDE3E8ULL, 0x597D8613A2E6828FULL, 
            0xA254F746C556BBCBULL, 0xFB0CADB1F0F2322DULL, 0xB3E4CF85E38CAC94ULL, 0xA8A64288C597A8ECULL, 
            0x48C1D3DF144451BCULL, 0x5FD3AFA3D7A3408FULL, 0x48BAE684657F9D25ULL, 0xDDC92FDE7FCA204DULL, 
            0x69B652C4955515F5ULL, 0x71FF3AA9377E9E56ULL, 0x711C63590F237DAFULL, 0x2E2E99D0A6BAB4E3ULL, 
            0x619AA1B728AA9F3DULL, 0x957D4F08A2D74146ULL, 0xCF5A7BECFE7CB514ULL, 0x69BB616D15BDEF3AULL
        },
        {
            0x2208F03318B8E77EULL, 0x4262927CEACFE038ULL, 0x4E323134F8DAB8CEULL, 0x3299C0E608442798ULL, 
            0xC2FAA446D0269215ULL, 0x46B04D706C994036ULL, 0x066E0597B64F010DULL, 0x225FC18F37375236ULL, 
            0xC3769202BBEFA1EBULL, 0x2667BA6047F0D411ULL, 0x6A23D4F206221301ULL, 0xE6C0779E3E473035ULL, 
            0xFD3680695402EC7CULL, 0xB4C5B22A344E7C4DULL, 0xD419B65528F0FE3AULL, 0xE7087F7D1F6EACD5ULL, 
            0x08F8114EB9AA5043ULL, 0x79282A4744926DD6ULL, 0x7B530105F417E0F7ULL, 0x8702998780535D1DULL, 
            0x210D708EDE2A47AEULL, 0x362D6F2CCA576A79ULL, 0xA21B82662363308DULL, 0xED29C882F99A87D1ULL, 
            0xBE7B15E01C8868A7ULL, 0xEDDA2F24B6112E74ULL, 0xBE6BCC902C74F44CULL, 0x4BC40EE60D72B33EULL, 
            0xBD3FBEC0FC8DC5F0ULL, 0x3AB6C1836D68DD94ULL, 0x32DE2F2DDE096961ULL, 0x6F47779A22B0C969ULL
        },
        {
            0x4FCB6F07490C3801ULL, 0x0E5F315192E09910ULL, 0x1D054ABED713C475ULL, 0xDB121A1CF2C17A6BULL, 
            0xBC083B9465D68B9CULL, 0xCA288E74D7E27FF0ULL, 0x1EC331306DFCDD9BULL, 0xF8B55E1ADF3F2FF3ULL, 
            0x1E48C855F8702BDAULL, 0x167A5FDE6FC997CEULL, 0xE4EBFF18B8B58413ULL, 0x776AE9B334E24449ULL, 
            0xFBC04E7B8A64269BULL, 0xCE2F1F70EEA5CED5ULL, 0x56D3764AE6968786ULL, 0x8B8C155E382FB581ULL, 
            0xC3DFEB60767C1AA7ULL, 0x967A78B2E473EB7DULL, 0x16F9D8C3866764CFULL, 0x5F311A7FFADE6C5BULL, 
            0x08AFB7F7665834D7ULL, 0x1F9D8CD6AB0F0621ULL, 0xF5B0579D0B8FCE8AULL, 0xD2866CDF139A98E4ULL, 
            0xB9D388891859A2C5ULL, 0x5401997036AA7FABULL, 0xF0F226DD2E465CEEULL, 0x04E6CC9E17A8C5FAULL, 
            0x8F14BA543341B084ULL, 0x81ADA7BBABB01883ULL, 0x0740C2E1CA8F7513ULL, 0x1F913C1C35E3FB9DULL
        },
        {
            0x9B71955146E86F4FULL, 0x7B22A7A2D98AE69EULL, 0x00496BD00901204BULL, 0x5DB5414699015049ULL, 
            0x35E73C9FB24CCDA2ULL, 0x1BC49ED9BC73F360ULL, 0x3B3C11BBBD35C1B2ULL, 0x06FBB25D7C0C7B9BULL, 
            0xDA4ECDEADCCD8477ULL, 0x528AD0FF37BEDD01ULL, 0x3939D9104DA4CC5CULL, 0xEF7554D573D6F1F6ULL, 
            0x4895514502A803E1ULL, 0x68D86B7181B254DFULL, 0x9CC4FA61EC2E31AAULL, 0x3F389661C4458F28ULL, 
            0x87F30C8B0DF94050ULL, 0xCD2B15D057AB968BULL, 0x068A3AF6FE18F210ULL, 0xE6BFE121ABA3DF4FULL, 
            0x36C9F187D512EAEEULL, 0xC37C428D8EFC4D01ULL, 0x4C0F517A59EECFA1ULL, 0x2D2C689AD787AC49ULL, 
            0x6DDCE19B12758047ULL, 0xB64F9F2C23354764ULL, 0x642E3310B0ED22FFULL, 0xB9954D2A4CDD1470ULL, 
            0x3D2479E33D9C3491ULL, 0x843DB37DB1279CA3ULL, 0xD45E11E071735BC7ULL, 0x7E6742EC21FF24F1ULL
        },
        {
            0x8D1F9185AAC4499CULL, 0x015A45EA99239C22ULL, 0x4B562CFF2F9EA006ULL, 0x2D74B68BDC805311ULL, 
            0x009CCF97BBCEB5A3ULL, 0x418D09CA9FE8160EULL, 0x41ECF3C8DD78C650ULL, 0x8AAA74E5D8F91E91ULL, 
            0x9CBE55F193E81310ULL, 0x93B2039D2A708BF5ULL, 0x2338473E24EEE079ULL, 0x22ED7EC71309B35BULL, 
            0x7DEFF1EF658E441DULL, 0xE5618AB3140071DBULL, 0x232F858F38CBDC56ULL, 0x2165111FF6D1751BULL, 
            0xE4E8B58B8DB0B5C3ULL, 0xD7A57E59BDFC2980ULL, 0x0DA5D05EC5C50991ULL, 0x1060DF1DEA260417ULL, 
            0xCEAFDF02D284E311ULL, 0xEAE66D8307AA601DULL, 0xBCA4B8354E7E68D2ULL, 0xC8A00B92DDF9DAA4ULL, 
            0x296E12EC5B08E16AULL, 0x11DC4C487301C78CULL, 0x796517A093CD8FB8ULL, 0x54668E74DB93F73EULL, 
            0xB5A393EFC3789B37ULL, 0x8D68670F9C3543DCULL, 0x3C8BA4ABE4FF2EEEULL, 0x1BC69D4EE3C023FEULL
        }
    },
    {
        {
            0x2DB084C8FF52C419ULL, 0x7E78FC8DA22C1774ULL, 0xC82E56D5B661224FULL, 0xD8B5E4F3FE680ED3ULL, 
            0xD81A3D24292C0069ULL, 0x069F331588E156BAULL, 0x8BB9E961A6D5ECACULL, 0x53DFE3E9354C8052ULL, 
            0x419853842218849CULL, 0x880830DCF816363DULL, 0xCB768934F1B5DFF9ULL, 0x0CDB208752039DB1ULL, 
            0xD97F52AFD6A3BF65ULL, 0xCFC17B056B80941EULL, 0x9D07432A56D4E72AULL, 0x785E37DC7A7D6F7CULL, 
            0x5536C63BF5C2EC71ULL, 0xCD98CF55ABEAB443ULL, 0x250AAF81B6B67E17ULL, 0xBED6B3F82668BA4CULL, 
            0x30B621AA8FFAF378ULL, 0x02A0F90CA2FF2BD0ULL, 0x1FFF40C2A160DD20ULL, 0xEF9C58EB771C4B25ULL, 
            0xF57070B693758488ULL, 0xCC3E0A6E20D67896ULL, 0x170AFC3E5B318DD5ULL, 0x138D17462A13D7A2ULL, 
            0x91DDFA92CB8A2E34ULL, 0x026445B00A7D1DF3ULL, 0x4259D1C2BE84F859ULL, 0x06F96EF7EDC0C309ULL
        },
        {
            0xE73F92B325F3DB1AULL, 0x5FC809CFA0121756ULL, 0xC094C34D25EA3538ULL, 0x16C3AFE0CC32022CULL, 
            0x0308D00D505887DCULL, 0xA7DDA61C0A24C023ULL, 0xF1AD8353CE6A5092ULL, 0x037E11AC4B6626BAULL, 
            0xF28B8A6050FA4C5CULL, 0xDE69C6741CA75FEAULL, 0xFB6E0D0F76561E8CULL, 0x76F9BFCAEE482A50ULL, 
            0x9F31C66CF98566F3ULL, 0x50AC54FE6088877EULL, 0x8B2A7FAF5C6CE325ULL, 0xE51ED5778F220296ULL, 
            0xF9623DE187C429EEULL, 0x91CD387FF9E11699ULL, 0xAC683904C48AAFC4ULL, 0x899A2B591D23FA9CULL, 
            0xF1E5DCC21FB88A0DULL, 0xE103E048699D4803ULL, 0x7D5DCB72DC1A8BBAULL, 0x245AEAAC67BA054EULL, 
            0x60DC56DB6771CF59ULL, 0xE3B06CD705EF53FDULL, 0xF335D134F5EAAB93ULL, 0x18D3211224444633ULL, 
            0xB53859F50A383DD3ULL, 0xA475F7389A674699ULL, 0x660A07945D364A15ULL, 0x3E354A18F5ED4032ULL
        },
        {
            0x0DFA9D01F96DC9AFULL, 0xC2C0E34478C72634ULL, 0x298C6CD7BAE75CF3ULL, 0xC9A09146BACBCCF7ULL, 
            0xF6B8823C66509A81ULL, 0x07FD38EDC6028CC4ULL, 0xA86B664FF69CF0E7ULL, 0x6EC65DB3CBAF41FBULL, 
            0xEA5426B39F9A3E59ULL, 0x69493BBE85CA5264ULL, 0x6CDBF8BD2B8F75BBULL, 0x0D00FE3AFC0A3FC8ULL, 
            0x2E87E6E00275E0D3ULL, 0xE15C9198E9CF0C77ULL, 0x8A7D777B3F127690ULL, 0x9CC2586B68488845ULL, 
            0x555B07FC37CD91B0ULL, 0x67C6C7B13CF4B8D7ULL, 0xEF7252919EBFC5A1ULL, 0x1DC61D4DC61301B3ULL, 
            0xDD8723D7B9196F81ULL, 0x3A837656E71975C9ULL, 0x73994625149459E4ULL, 0xCA3001FC285F0F77ULL, 
            0x88F12D0D4AE82AB2ULL, 0xC1601CFC90253AEDULL, 0x2A867B2F20370EE7ULL, 0x61E82C429C125344ULL, 
            0xF5E170712D98CBA4ULL, 0x108A47341AEB3DDEULL, 0x8CAFFF1C1BBEE6B9ULL, 0x86FAFAA44BCD4591ULL
        },
        {
            0x7E5F60109E2AE4F6ULL, 0x56B64EAAED974739ULL, 0x614F26F4CA09A5EFULL, 0xA43E99DC7D8FFDF1ULL, 
            0xE84B279452B15AA3ULL, 0x85E3BFF2AF7FB474ULL, 0x20DCA77A73183AD0ULL, 0x5777C63273081F7BULL, 
            0xA70F738BE9EB7DBFULL, 0xA8C2D46A04441ABBULL, 0x380925C9FFCAC470ULL, 0x9937F472EEBA6AA2ULL, 
            0x552F6BC003853A7DULL, 0xF08901B108BA0F7FULL, 0x7F55E848606B5CB5ULL, 0xEC1AA53D24E670DFULL, 
            0xA7158D5BFAFC2C2FULL, 0x4B4B4495AA6F6D5AULL, 0xC5C6AF555DB34964ULL, 0x01DA4D7ED791B12CULL, 
            0x1895604E902A19F1ULL, 0x9FE8785F698130EFULL, 0xCC479AC4BB133C5CULL, 0xD1D741EDF90F6AC9ULL, 
            0x8F8DACD8659530BDULL, 0x27F99AD062C2D78AULL, 0x38C0A06C98A50870ULL, 0xBA3781AB316770ADULL, 
            0x6A09C458522B240CULL, 0x60E52CA6F222CD80ULL, 0x63BCEC85F748743AULL, 0xCB5B7BCEEF80E75BULL
        },
        {
            0x0F1D82C5868B5D3AULL, 0x754A440CC6B50B41ULL, 0xDA2BA3E3C36D9C58ULL, 0x6B2C53A293F1174DULL, 
            0x5C85F26582E23A00ULL, 0xD55BB8DF7CF8736AULL, 0x951522E13953FC86ULL, 0x0333932DB409E034ULL, 
            0xCD1E0A8CD0C39D0CULL, 0x6C97BA372203CCE7ULL, 0xF796C3FBB981E7A7ULL, 0x07D6BB3AB7AE8740ULL, 
            0xCA17C1EC1749845AULL, 0x600B3CD989F5BD57ULL, 0xD7AE557653770523ULL, 0x10E2BAE2ED905985ULL, 
            0x6C3F9C6A2D302E18ULL, 0xFA69CA8CE5F75755ULL, 0x312DC41D41EA01B7ULL, 0xAC548812C1ABFD1FULL, 
            0xD2D70D786CE1615AULL, 0x5675EF5BE8534C11ULL, 0x8EC538DE91A231D3ULL, 0xD262B7D8FD3B44E9ULL, 
            0x02B2F768296A5180ULL, 0xDD8A9983AE96A1E1ULL, 0x5510933A6C47A1E6ULL, 0x9EEF0F15B6C10B01ULL, 
            0xA551B15BC1BA6483ULL, 0xE35ABE8BFAF33DA0ULL, 0x93366E05FB41CE0EULL, 0x462B4A99A0F6605EULL
        },
        {
            0xAB32B109F53F9C92ULL, 0xA2710BB6711FBE6FULL, 0x942A25499F116CEBULL, 0x5F6E82FC93E02206ULL, 
            0x619C13F937B56A49ULL, 0xD59AFC82380571B6ULL, 0x664E4AE5865700AAULL, 0x951409C00F57C340ULL, 
            0xAC8615E3A70D9D44ULL, 0x3B6DFA1F8F80F13BULL, 0xE918349EC6F0EBD8ULL, 0x82D881B1EF4DFDC2ULL, 
            0x57AF4C2B71F91038ULL, 0x2F02A7D198E4FF10ULL, 0xBF0B75BC98781F8DULL, 0xF69A7B949A84BE12ULL, 
            0xD65E3D5E35161675ULL, 0x986D1A20347A5E07ULL, 0xC65806200F88F4B9ULL, 0x82A971FF61A476DBULL, 
            0xFA2EEDDDC3F77437ULL, 0x22974677CB833384ULL, 0x94FF7DC484FEC53CULL, 0x8FA22E2D97524437ULL, 
            0xC9CA2B6AE8DAF25EULL, 0xC2B9365CAF87E5DAULL, 0xFD6EA6D1D32D42A6ULL, 0x3579B6630DD1898BULL, 
            0x8839289F1C8270E7ULL, 0x4659A4C13CA21B71ULL, 0x063DF83E15A26ECAULL, 0x17C05B0BC65B043BULL
        }
    },
    {
        {
            0x8525DEFB3D79A4A2ULL, 0x6B34C9C95903E47DULL, 0x8FA0883748F5A697ULL, 0xE18152CDF022C16AULL, 
            0x246F54C6A3E59BABULL, 0x4881624CB554F597ULL, 0x93EEFD0CBFE8D57DULL, 0x8A1E194226424704ULL, 
            0x3C1DF5897CD624C7ULL, 0x46AB98080893EF5EULL, 0x2A2C8944DD1E564FULL, 0x05DF74DF551880DBULL, 
            0x8059EB1C8CFAF65FULL, 0xEAC2E743818ABC2FULL, 0x15268B44A6A98E9EULL, 0x03E5C24D63260214ULL, 
            0x324D5BFE20907117ULL, 0x4A0C6DE4419572C8ULL, 0x660355C07ECCB14EULL, 0xA357DDFBA10D6BB4ULL, 
            0xF190A9911A1B03D5ULL, 0xE482FE2B4C0FB948ULL, 0xBA8DDA1BC1CA0878ULL, 0x14CDFC91BE686FFFULL, 
            0x1F048ACE4F49622CULL, 0x785FEB5592C9FA08ULL, 0xAD8DA57ECC2896DFULL, 0xC8AB39B3E34D2988ULL, 
            0x817BFD99979A2773ULL, 0x02D2F37A321C9D27ULL, 0x7AE1A3F66FF06146ULL, 0x79F8371339ED7F14ULL
        },
        {
            0x37379105EACE7FABULL, 0xD4EE7F696C2AC884ULL, 0x47F7F3F189DF87C2ULL, 0xFA52C473FDBCBAACULL, 
            0x456913482E92AFBCULL, 0xC928CD1E8256423FULL, 0x18D8B4F0E222C5A0ULL, 0x83B6C108B0F88006ULL, 
            0x114B233ECD06E108ULL, 0xD9B546AE9C010021ULL, 0x581FA479A24E0FEEULL, 0x6F336CC2B64A4B25ULL, 
            0x5B0858762B112808ULL, 0x40ECFCB137074E37ULL, 0xA57AAF6E1454B45EULL, 0x4DC871391C6AA552ULL, 
            0xE0C3CB023004865CULL, 0xDD59643C52761AC1ULL, 0xE57ECE4B3990D61CULL, 0x635174ECDD6AD459ULL, 
            0x10FBB209CBE91536ULL, 0xCC1BA37B01513998ULL, 0x9AD474C0E17BF526ULL, 0x4FC0137E077D3BE2ULL, 
            0x0DDC60777CD38106ULL, 0x32F5A9C46FC454E7ULL, 0xD6F6BB875A0794D3ULL, 0xD27E7BF5DCB83181ULL, 
            0x962B90F378C036A8ULL, 0xB6E78889F6C1C1F5ULL, 0xB3F4DD0F4C082A76ULL, 0x628D2A62410EF556ULL
        },
        {
            0xDD32D3B2A737141DULL, 0xB88185D79BA03EFDULL, 0x958735A2DB9C5559ULL, 0xF28D8980E36DC181ULL, 
            0x0C6CB118404AE76DULL, 0x3CA5BBCDD31BF36EULL, 0x577A3888EA0BEB7BULL, 0xD3358D11BA9D8191ULL, 
            0x3A20CAB9BD892C1BULL, 0xE86549D5906AFD7AULL, 0xCFEF3389A9473778ULL, 0xFA24A0E7A9FB7EC7ULL, 
            0xC7BD789000F0CE54ULL, 0x53AD78F2DA447F3BULL, 0xA158FEEF122D3C22ULL, 0x0D34E604BB2BDD8AULL, 
            0x3122588907FDBCACULL, 0x75A19C30CBF0FC36ULL, 0x493C680A1D53A1A6ULL, 0x7EBA6F30351EB245ULL, 
            0x43C4D288C9B965CCULL, 0x4BB6F46E13DBBC2FULL, 0x2204E43765FDA195ULL, 0x24C74AFD4FAF80D5ULL, 
            0x98FBD8071C86A94EULL, 0x0F171C300517E635ULL, 0x3EC45C023C98DC92ULL, 0xDF125A66740DD7EFULL, 
            0xC07F93B398F51508ULL, 0xB0410ED75D393579ULL, 0x066AA84E1C159861ULL, 0x0B9A12F6F2E0A700ULL
        },
        {
            0xB3F6003AFA8363C5ULL, 0xB760E0D7E6BEBC5FULL, 0xC638FC73F1F139CAULL, 0x7B2D223BDD6C7BA3ULL, 
            0x6E756E3DB53AC52FULL, 0xD3D4613B970467C5ULL, 0xE3ECCA00B4A49944ULL, 0x26A0104616D4744EULL, 
            0xAA8B66759FC8B838ULL, 0xE24BBECC59975B38ULL, 0x6BDBE0AA3080478FULL, 0x5D7D7843DEE5A352ULL, 
            0x68505A819606AE15ULL, 0x8854D8EB4BB0AF21ULL, 0x15532ABBC09DE7DDULL, 0xA77C22E7749B3C8CULL, 
            0x0514A943383B396DULL, 0x0742F617AEA70FFDULL, 0xC365154F41D1B619ULL, 0xEA23645541139447ULL, 
            0x050DE3F51A6646CCULL, 0x76E429F60FB1DF58ULL, 0x7186A3531319A60CULL, 0x83FC11F4B1C62E21ULL, 
            0xF78A1E38BDF5516FULL, 0x21A2052280AF0D3FULL, 0x26770848CA5AAC27ULL, 0xA003B9EA200DC0B2ULL, 
            0x74893E32516883D6ULL, 0x1BBB031C9A1F2596ULL, 0x910764743FA7C0F7ULL, 0x00DA345D41E451EEULL
        },
        {
            0x139F84E7C647F492ULL, 0xF70E3F15BD162341ULL, 0x11AE339F1729F0B0ULL, 0x94828255E6C8604CULL, 
            0x00358509FE98707FULL, 0x62AD2778A1D13F53ULL, 0x373A738DFE2856A2ULL, 0xF5373667D675869CULL, 
            0x29195DF3259F37C0ULL, 0xE5BC2A7F31ED68E5ULL, 0x3CB7C329FE567C45ULL, 0xBB89750F0F4A9677ULL, 
            0x7E796129D0399666ULL, 0x2147B1966B0B5A0FULL, 0x09495CFBC1AF07E6ULL, 0x0E6902956C35B865ULL, 
            0xF4AE7C62F675CDE2ULL, 0xC7A7485BCFF0C825ULL, 0x2667920D5AE5CD44ULL, 0xA174EC791BCD4DF2ULL, 
            0x9FE92732E51B8DBCULL, 0x65CDA2055E1770D0ULL, 0xCCFE25A1E687F23EULL, 0xACB4D227625C8AB0ULL, 
            0x615A4ABF19C6969FULL, 0x2860141C6EC3D398ULL, 0x1CDE3F484795DD90ULL, 0x33BDDC58CB0924E2ULL, 
            0x3E9269D73889CADFULL, 0xB423E81F507EE05EULL, 0x24A9B6C71DF72A83ULL, 0x244796B825E1AD94ULL
        },
        {
            0xA628F3AD23DB00DFULL, 0x836D67F5B187A6D7ULL, 0x93362FCA409B5B5FULL, 0xEBCFF4B4D3FA6D49ULL, 
            0x4A1C48D865FF7D66ULL, 0x3941C985DB16B293ULL, 0x6E24C832A044A1C5ULL, 0x35FB07FE368C09E8ULL, 
            0xBDB20D0CCD1C8098ULL, 0x6D4D18D6E684E3BEULL, 0xB663C50B9066EACBULL, 0xDBD671F5924C86E0ULL, 
            0xC28D606636C99DA6ULL, 0xEC4100B8B810AA6DULL, 0xFE0DFA913EDAD813ULL, 0x08A389896D0BC05EULL, 
            0x883803400A02D698ULL, 0xFD05BE53A71D7AB0ULL, 0xB6641A0312153C30ULL, 0xD9AC52634C326F8CULL, 
            0x3B63B017F383AE24ULL, 0xCE5E4E222816C998ULL, 0x87C35C2D2CF0A462ULL, 0x7762C9C9753B433DULL, 
            0xFB1A161904A9F106ULL, 0x6FEE8F559583D9D7ULL, 0xDBC13A30F83B2360ULL, 0x5107A92D488DE171ULL, 
            0x8206B0036BC518E2ULL, 0xB53EE6EBCE43D4BEULL, 0xF6548521B4BD3E92ULL, 0x1833E44C94543756ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseBConstants = {
    0x3AD4BF31D3200736ULL,
    0x713043B5157410CAULL,
    0x707BFC670365221FULL,
    0x3AD4BF31D3200736ULL,
    0x713043B5157410CAULL,
    0x707BFC670365221FULL,
    0xB37CA9CB874047D2ULL,
    0x20EA297E8DC3D8ABULL,
    0x24,
    0x8E,
    0xBF,
    0x6F,
    0x12,
    0x52,
    0xE7,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseCSalts = {
    {
        {
            0x0D4261BCD0569F83ULL, 0xCEA866DDB1FD34BDULL, 0x167681196147FD93ULL, 0x117CB69F01586848ULL, 
            0x49F021B54EDF1F0FULL, 0xFDD122352524F627ULL, 0x6422A2B798AA739AULL, 0xC0856DA65427E5F0ULL, 
            0xAC5CB29242C56DC5ULL, 0x972571B97A94C930ULL, 0xD62C34CCA65BC0ADULL, 0xCD087F58169A1D17ULL, 
            0x6EF7208ADA3A61E2ULL, 0x8F2F42EBB68CDD9EULL, 0xC23430069C227B51ULL, 0x831092C5001E1AB2ULL, 
            0x8BB1122DC9B4D363ULL, 0x3DEC181F7C140136ULL, 0xD8C5E682606AD23AULL, 0x01402DFFAEBD2029ULL, 
            0x85954D1B763254F0ULL, 0x719B74A0C6A15D8EULL, 0xBABDC8C35D403CEEULL, 0xA1BFD297531B0C86ULL, 
            0x2862EF0B9D79D736ULL, 0x6BBBB722E700B083ULL, 0x90DA2D4EF3927C15ULL, 0x159FC44AACCE695AULL, 
            0x9EB42F1E8130B4D1ULL, 0xE0DEF7EB41B51224ULL, 0x4C52DDFB4B9F820EULL, 0xE67F63A63B4DF337ULL
        },
        {
            0xE38F74BCEF113D78ULL, 0xBC14FF4E7B30388BULL, 0x532256691867D991ULL, 0x73390550A16F1F48ULL, 
            0xAD577C19157829AEULL, 0x89C5C679EC6E46B8ULL, 0xD01428C54A2C7195ULL, 0x860A2BFB237DF389ULL, 
            0x0AB36F4623D30D9DULL, 0xB145E032839734B8ULL, 0x2091EC0B3B364443ULL, 0x831E96E6EFC83C31ULL, 
            0xAB32182BB1FED80BULL, 0x83268F03E7816575ULL, 0x740666CD3D103E05ULL, 0xF8520B6212DC1AF0ULL, 
            0x008EA6B6AD68D62AULL, 0x96DB228D027675CCULL, 0x99B051205832F73CULL, 0xED68844CF32D5F8DULL, 
            0x447FDDFEE04D9EF5ULL, 0xBB22E9DBF36515EDULL, 0x017C074C72646943ULL, 0x8503040C77C34907ULL, 
            0x6A805AEB07440E95ULL, 0xE1D23073C7C2D5E1ULL, 0xFD5FB4614597941FULL, 0xBF671AC20D4E4890ULL, 
            0x028B2501B4F061A7ULL, 0x8B26DD26D9B8A1C0ULL, 0xB70E98585B3E9C35ULL, 0xAFFA34FCF256F935ULL
        },
        {
            0xB66F202DB2D372DDULL, 0x4EA0301B492A0E01ULL, 0xC7021CFA489062F5ULL, 0x30D9E547B5622937ULL, 
            0x93AEC6FA682B493CULL, 0xF79E23F15674CCB4ULL, 0xFABD1664E0C96130ULL, 0x897C4E841F125368ULL, 
            0xE01DFD8D47BA8AD4ULL, 0x8BFC0ABC567C52DDULL, 0x9ECAF6D1698EA801ULL, 0x9364CCF2349742A1ULL, 
            0x0CB6AA9FE586A352ULL, 0xFEB55C910998B4A2ULL, 0xD1C28F39C4CF7AFEULL, 0x20C31FA57C91F955ULL, 
            0xBB8752F8322BD47DULL, 0x0F9BDFA81498A89AULL, 0x186A8DE8C4785EB0ULL, 0x8E714DC35E7F2A22ULL, 
            0xE738DEE39FB8E0B9ULL, 0x545D7E213021B8F8ULL, 0x27812CE5AD99572FULL, 0x2B913FF51CC34B14ULL, 
            0xA245321CEF3371D4ULL, 0xF53259DD586D3F1FULL, 0x01393010E51E90BAULL, 0x120F604FAF2773A8ULL, 
            0x22BCC1908AFCD1F7ULL, 0xD002E3074D3869D0ULL, 0x9A56C4AD99672953ULL, 0x12B9A813A21F2EAEULL
        },
        {
            0xE7808027D9746088ULL, 0x77A4F25D59FC6521ULL, 0xDA58D850955BEC36ULL, 0x419D4AB0FE8E4941ULL, 
            0x0430DB9ED302CF5EULL, 0x872CEAFF72E03A72ULL, 0xE97D96197A4A5D46ULL, 0x7FA079ECFB30AB9CULL, 
            0x4FDE56DC6CC35A85ULL, 0xBDD1AE3B5B079536ULL, 0x0BF0D2DD64B3401CULL, 0xB759FEC632501950ULL, 
            0x7D35BC74A151EE62ULL, 0xE9C157804DC6E84EULL, 0x80ED197EF71A8672ULL, 0x22148AF339323BADULL, 
            0x2C83CDDF5B330E42ULL, 0x37A882D8C9917EDCULL, 0x20C43D91C1749F63ULL, 0x5184154A12BF892DULL, 
            0x0F37BE2164F22B40ULL, 0xEB2655C1CD42D043ULL, 0xBAB99D7952DAC3E8ULL, 0x960201B3C758CEB1ULL, 
            0x932FB62F9B49BFE6ULL, 0x5BBBF59512F02578ULL, 0xF644BA8B0A30F5CCULL, 0xACF9B997586390C9ULL, 
            0xF62F2D00D4B83B24ULL, 0xEE02F18FDC1920AFULL, 0x4A96FD5E229A4E48ULL, 0xA12E775F9091E8BFULL
        },
        {
            0x888FB07ACF28BBB0ULL, 0x33EEB47C5F107D75ULL, 0x31356EF133A9C982ULL, 0x2F8B34C5506887D1ULL, 
            0x147617BD495C5C89ULL, 0x6A1CCD9D6C6E3DC3ULL, 0x8041DF6FF622E8C2ULL, 0xB974C989619DBCDFULL, 
            0xF55D98A2FED14C9FULL, 0x71DC259DBD10F412ULL, 0x51D563B8D8A8031BULL, 0xDA718872FBD59D31ULL, 
            0x8547BD7ABA097567ULL, 0xEB9451C40878ECFDULL, 0x0CE6C6F367D246FAULL, 0xC42F9B66E5C59FA0ULL, 
            0x761C7EB3D3FED25BULL, 0x56475D007220F9EFULL, 0x9ADB5F58DA817269ULL, 0xA2B528B6F15302F3ULL, 
            0x862D350906CF2086ULL, 0x0B7A763FBCAFC6A3ULL, 0x7950B6FFCC8A6BF8ULL, 0x31EF4FBFDB44C7AAULL, 
            0xA786230CDA29CAD2ULL, 0x9D6B04ED845349F4ULL, 0x58E5C83E4F5DD9B3ULL, 0x90125CCDF283A5E2ULL, 
            0xBA5D9B26BD45FCD7ULL, 0xAC8D285C9D0ACD8CULL, 0xADB3C0567780C995ULL, 0x98DC9DDF4DBE203CULL
        },
        {
            0x70E0E2DF90131866ULL, 0xDDF542BCF95D9000ULL, 0x35CB87CB4D4A9C3EULL, 0x903676D9B0BAADD2ULL, 
            0x815B5BDCF4E37D1CULL, 0xA8F315C61ECD3F05ULL, 0x2FD2FBCE1ACF8A79ULL, 0x5E81C5E7EF156FDDULL, 
            0xF0A5556CC355221EULL, 0xEE0A84199C95D2A0ULL, 0x2FA639B722044C5CULL, 0x71D86E92935B9FBEULL, 
            0xA6EF6432277CE621ULL, 0x999B0C1CF1347D55ULL, 0xC1A8B4EB23AFBF65ULL, 0xA0EAC988AA543C16ULL, 
            0x5D7F6C8BE61017BAULL, 0xEC71C413D4AC1770ULL, 0xB2BCCEB3DC971F8FULL, 0xF9C60C90BA5615C0ULL, 
            0x81CC1C3A6083C3BDULL, 0xD910CBE6D1A69E52ULL, 0x34289BF9E4C4418AULL, 0x2E80605987913993ULL, 
            0xFA036326D8414722ULL, 0x6525642DC552A56CULL, 0xF1367C03AC66DB35ULL, 0x5D2B711B54BB992DULL, 
            0x6DB0641CA4F88D3DULL, 0x3CD2923735D14C3FULL, 0x01AF3EBC22B223ADULL, 0x15BA32D257C5CD7AULL
        }
    },
    {
        {
            0xDA529222B0572F69ULL, 0x477BEE5837FE9290ULL, 0x040E03AA7C4A66B5ULL, 0x916F97032CC32881ULL, 
            0xBB4966D4A153EE5DULL, 0x5AF1A3A1B65AC9F2ULL, 0xC74BA89261CCD1C0ULL, 0x30D3BA136116AF6EULL, 
            0x5314453A7D8AEDF5ULL, 0x35E5F3647299AEB5ULL, 0x58B322BA403C3F03ULL, 0x3D058961CD18C2FCULL, 
            0xFC65615F6CAC50D1ULL, 0xC169B2116DD2613DULL, 0x9CCF82A0D627DAF0ULL, 0xCBA54ED74E495DFFULL, 
            0x5BA8066F46049F99ULL, 0x4E7CD0EE238A5D42ULL, 0xC9F6A26058C4CFBDULL, 0xD2AC5CA911403C6BULL, 
            0xDA51E5290952EC89ULL, 0x88364A49CA50D33BULL, 0x9F3400223759B2A2ULL, 0x4DA822C95B3941C6ULL, 
            0xC6C6540D5DA2ADF5ULL, 0xF970B5BE9EFC171CULL, 0x90BB0F79A94CAE20ULL, 0x49451E55D06309AEULL, 
            0xF1EAB15CFB497192ULL, 0xDE9640A85FF69AAEULL, 0x467B24A49FC4A71DULL, 0x56A256CBB4E4B398ULL
        },
        {
            0x95D6A07D8772D7F1ULL, 0xEF6842AD562EE870ULL, 0x7F9C0340B46876E5ULL, 0x70D74AB5E9CF6301ULL, 
            0x35C7E744CBF69AFFULL, 0x0C11B4AD1247B905ULL, 0x45EB907FABBDD721ULL, 0xC68E4D0F642A0D71ULL, 
            0xB6A3708A586672B8ULL, 0xE96228182E816F9AULL, 0x5E16A90A3EB3FAEBULL, 0x64CF876A71F30B0CULL, 
            0x8CA22F30753BE232ULL, 0x29DAF168F650F748ULL, 0xC45EACDD224776FDULL, 0x06D043E970009E8FULL, 
            0xA4C07801866E5578ULL, 0xDF881F82E7DD9ACCULL, 0xA9489EFFD65A6AE4ULL, 0xBE148DC1D9600DE0ULL, 
            0xCD46E3FC3D36DEAFULL, 0x3B1AB6CD6F474BE0ULL, 0x21EFD1299C29BC76ULL, 0x81CBD084D3033E20ULL, 
            0x17868DD7AFD3DDB2ULL, 0x633DBF9EE68494ECULL, 0xC476E98403B3F52CULL, 0x6A18CE5D0F9364DCULL, 
            0x11DEEBE772395EF5ULL, 0x578EBBB4AB17342AULL, 0x7816B8AFDFE9F41AULL, 0xA0D75D4FD6BB8D39ULL
        },
        {
            0x4A00F7FAF9ACAF6CULL, 0xD917B5B5BC57E472ULL, 0x22CE463D92469346ULL, 0x53F3CCBB33C46BC5ULL, 
            0x98F5CC730D23BCD1ULL, 0xE1D01BEC3D53A50AULL, 0xE9E789F8D6AA7C0AULL, 0x32AE78E61EB0FA2EULL, 
            0x1501059618750A06ULL, 0xCD5BA2C40D7411BAULL, 0xDC261870D47C8023ULL, 0x2B9B55B4EF2670EAULL, 
            0x1D4B2E0820F47E3FULL, 0x4A7DFE6CDEC500DDULL, 0xC309EDEB01BC7732ULL, 0x790A3167E6AC60B0ULL, 
            0x4F587CED9F82972AULL, 0xE87637FD6C37DC82ULL, 0xAABAD1482A3A87C4ULL, 0x73938EAD6C758F93ULL, 
            0xBBBFE1E6A5244360ULL, 0x9074D6173A7BC8C1ULL, 0x48029082435B0C6BULL, 0x71B2E268CEF219F9ULL, 
            0xB48BC0328022857AULL, 0x6C8D8E03794AE164ULL, 0x8EFB5B84F5CAB9A4ULL, 0xBAFC42E475DD18E6ULL, 
            0x4F109B83DE0E5E02ULL, 0xB8DF8CF4786A7FEFULL, 0xEA3660B70FB65ED0ULL, 0xEE633FBFE46E2CD4ULL
        },
        {
            0x3D7077BB700C727FULL, 0xFA379D1B30AE6EB1ULL, 0x8A28D310B423196AULL, 0x54E5F33C4CEE7A1AULL, 
            0xAB01E217FDF681F2ULL, 0xE9B5BDA0D60D5174ULL, 0x239C5F0E5CB495A3ULL, 0x001FCCDD94066479ULL, 
            0x9F92261F996FC73DULL, 0x58135E6524599294ULL, 0x46F70A5DB752D160ULL, 0x065B10E68E2CAF4CULL, 
            0x207761C634844FD0ULL, 0x358238F12E5DF248ULL, 0x466B74FA8BAC3455ULL, 0xEFFEE3AE2D6E8290ULL, 
            0xDAAC7939C4B05281ULL, 0x5089C05E656D7D96ULL, 0x6AA380100027833EULL, 0x4E35A34AD998510AULL, 
            0x131B9FA0C08A022EULL, 0xA491E089D5966C3EULL, 0xCE4F38E6387FBDCAULL, 0xC80ABDE334CCEDB9ULL, 
            0x15CFDA162F6866CBULL, 0x9FA2C7C59527526AULL, 0xF0F2D798E4545D1DULL, 0x465FD10D41592A85ULL, 
            0xB206E99C8B43EA11ULL, 0x8E38054FAB7DF2B7ULL, 0x2D22A2A271E3C26EULL, 0x111B40C5F29E66A3ULL
        },
        {
            0x27022BC3F703CE6CULL, 0x8708D3894FBAA240ULL, 0xF767F6C4BAD6296AULL, 0xC7806E82AA905B8AULL, 
            0xEAD81F07A12675C5ULL, 0xE126304B3EBAC946ULL, 0x71CAB28139B693BBULL, 0x8C6DE6CF01632579ULL, 
            0x00B503B9CD71BD25ULL, 0x671807C7C72D921CULL, 0xFA7BEE2C9CB9F1F8ULL, 0x9C1B68772F74EC7CULL, 
            0x109778E30A43898BULL, 0x67DCF348F66E7796ULL, 0xCD24DD00E9F404FAULL, 0x29C1F57B3381F382ULL, 
            0x97A87F91B7437BBEULL, 0xED1DF8D9F9E3AA1AULL, 0x3BC1336A0201C91DULL, 0xAD0F0CB80C627B78ULL, 
            0x6F177A0239E666C6ULL, 0xF4A496E384056901ULL, 0xFAC990D0C0973695ULL, 0xC6BB79CEE5E480CCULL, 
            0x61DA7371D48DF003ULL, 0xA02F51040958A22EULL, 0x2154C075BD5C5076ULL, 0xBB9605097C186E06ULL, 
            0x9E563B3E93F14D80ULL, 0xD9C1E368B7C88D56ULL, 0x68CC7E99E59272CEULL, 0xFFE2E7D66D4A42DAULL
        },
        {
            0xF2F049FF9966058CULL, 0x38BDDC816F1E232EULL, 0x513D00B4FE8A80DEULL, 0x39856259ADF41A21ULL, 
            0xAE50E2BD1EDD76AAULL, 0x51E3DE6C307412C4ULL, 0xF001DBE935C5E586ULL, 0x6925E8D4FD34DFD6ULL, 
            0xA50F7669230D3AF2ULL, 0x7E9F8A867D64836BULL, 0x6EE8D8F69CC9AFE5ULL, 0xEC5A42C234F503C7ULL, 
            0xF2B2B7F48F9E31CEULL, 0xAA7F1C66AC80B402ULL, 0x44163025A002EDADULL, 0x4DF47600D12877BDULL, 
            0x005E20BE5D29F4CAULL, 0x10B991D30E07B004ULL, 0x246C00469C6097AFULL, 0x8F238D4932E8FAC6ULL, 
            0x4C37FD9E426F82E5ULL, 0xED0BEE3EE8B84C17ULL, 0xC0ED4FA4AA93D748ULL, 0x342317C51CF4FD82ULL, 
            0xA376976C2679BE60ULL, 0xE9141EFFAAE20AC9ULL, 0x76173DCDF14B014DULL, 0x65995F8BAD16229CULL, 
            0x0D2798B989916CF3ULL, 0x4B7D7189EED0C53EULL, 0x3D4EC456D04B775AULL, 0xE01A6B3722A581BFULL
        }
    },
    {
        {
            0x9407D1DA265EEC1AULL, 0x3D4B9E4E08338059ULL, 0x5BD1AEF2BE5C7AEEULL, 0x4248E437100829F7ULL, 
            0x61FC827923BFF249ULL, 0xF91EBADEE8C0B9E5ULL, 0xE8165DD5E3BB9B49ULL, 0xFFF967F4DC248018ULL, 
            0x5397F3DCAB610AFCULL, 0x7692AB19DA61ADD4ULL, 0x91FC9AAF0D777C89ULL, 0x9393F3D0CDEC22B8ULL, 
            0x96E66B9A15ACD784ULL, 0x03FC2CEE7CA512CFULL, 0x4BEEDD8888276419ULL, 0xABEE6CC692CA84F7ULL, 
            0x43F09E11E5E7F536ULL, 0x4C4D130DC69696FEULL, 0x4A40A86AFBFCC580ULL, 0x63AA5C4357ED4ED6ULL, 
            0x5E99014EDD5908A6ULL, 0x31BB7FEA1E938C6AULL, 0xCB15D286EE9A2068ULL, 0x07CDA672D3E8070BULL, 
            0x1F10D3DAEEFF7E5CULL, 0x5BE5EB1146083294ULL, 0xDAF02A1AF8E5AD4DULL, 0xAFE7B5DC10883F37ULL, 
            0xCB147ABDB98E54EDULL, 0x5D6ACF034CF8D777ULL, 0x58F384F085572224ULL, 0x6F0FC37E2B97D8D5ULL
        },
        {
            0x433F3B00F746A4C4ULL, 0x438FF19C31DC7E8FULL, 0x12CFC3AFCCDEB3FDULL, 0x65BC9DC5C30256E3ULL, 
            0x5AFE5AE851C2128AULL, 0x3BF84DA1D12A07DAULL, 0x732EBB8084B889DDULL, 0x3DA9BCE9CCE3E736ULL, 
            0xD581863166B72493ULL, 0xAD56B3B1A4B46010ULL, 0x86F018DA86A086C5ULL, 0xC0E2D43266C10049ULL, 
            0x6ED379867813E264ULL, 0x0B57C9991FF72CA2ULL, 0xF3F79FB44C818FE3ULL, 0x0CB0E3296C87F5F5ULL, 
            0x64D008E3681E4116ULL, 0x38921F4D491F56BEULL, 0xA5F4320B5B8E75BBULL, 0x638D36222BD4D9DEULL, 
            0x1F6FB896B510695AULL, 0x6B4257836E891857ULL, 0x90E20EC23661ED2EULL, 0xB26E9E94E951553AULL, 
            0xB61800B000FD4A87ULL, 0xAE067BA6A99FD396ULL, 0x79E17E799F27B719ULL, 0x72CA081E7E6706FAULL, 
            0xB3EFF79BCCD67D4EULL, 0xF6319E6777C942BFULL, 0xEE1BBB7AED788893ULL, 0xBA16F6661EC49C4DULL
        },
        {
            0xE6F8E06E1BD59911ULL, 0x542702C347FF5FE6ULL, 0x1F26AAC05CFF7B88ULL, 0x8CC1172DCD50B894ULL, 
            0x9755BA102F5D602DULL, 0x1BD41E87C18355B0ULL, 0x4C4D30D41A8EB81FULL, 0xF093D9A7E85AE625ULL, 
            0x3D71E84398A6FE30ULL, 0x50B7318CE1C60A96ULL, 0x76B609DCB5A1DEE6ULL, 0x8EEFAD49943D6FF9ULL, 
            0x73C50892CB54A31FULL, 0x88AC5C8E719BA5C0ULL, 0xFE9820CDFA9B0EDAULL, 0x03E828A8A7DF1789ULL, 
            0x6C00B55BDE957EFBULL, 0x242BA9E6699E6AC3ULL, 0x77089694DF4D5D0DULL, 0xD439B29E80CC91A0ULL, 
            0x953319890165B3BFULL, 0xBA2DCF3D660A166CULL, 0xC55A01D34F826C1EULL, 0x0F06EE9BCD7ED9F0ULL, 
            0xC174D665C20C9E00ULL, 0xF1A47FC3D2BE872CULL, 0x9A572998D3086BD0ULL, 0x61F87D70DA6E6E28ULL, 
            0x8291C3A93F6038E8ULL, 0xEFA1EC40ACA05D88ULL, 0x05613876FEE7E38DULL, 0xABB0258FA37ABBFDULL
        },
        {
            0x4661EC2D7EEEB77FULL, 0xD9E1F0C0C09D6E3EULL, 0x3E302E62C646CEDCULL, 0xC88615DE024EE34CULL, 
            0xB92B451B724790D6ULL, 0x5D1DC4D0C36BE2CBULL, 0xB7D4BE9AE85C20B3ULL, 0xE391C0523943A070ULL, 
            0xF568DB8DAEB92034ULL, 0x00BC6D9797552F87ULL, 0x8C3E4E558BC18222ULL, 0x9459F6F4459A64BBULL, 
            0x292A7B5D4047B1F3ULL, 0xCE59042AC0724807ULL, 0x0D71DBF5E6285536ULL, 0xE23B9381693BDE65ULL, 
            0x29163340C0CB97B8ULL, 0xFFA15D85DEDB9185ULL, 0x36EC684FB8E50246ULL, 0xB8EB60106D23429DULL, 
            0x9EBC53320FCC30A4ULL, 0x3FC0A0BDD57B8EE6ULL, 0xF5D4E1F72592EF21ULL, 0x97202D4B9A77467FULL, 
            0x70B30BE618AF6D55ULL, 0x17028E3B2DB17BFFULL, 0xC27B9B6E6595DC6EULL, 0x53764DCF44001625ULL, 
            0xB930F042F1364C89ULL, 0x612AD8A06225A720ULL, 0x405CC8CC66BBE75FULL, 0x16F1DDD4AC2EC354ULL
        },
        {
            0x4C09555105AE1CE0ULL, 0xA16DE819686D7D1BULL, 0x043F11D3F38AA091ULL, 0x6C7651B9FCD7DD95ULL, 
            0x49750A6DEB47CAE5ULL, 0x05F2EF3AF88538CEULL, 0x6EE60BF4548A0F64ULL, 0x96F85934E3F289D0ULL, 
            0x7554D90B11E46551ULL, 0xA154E341B229FBCDULL, 0xFB9886F1AFDC0E24ULL, 0x4985FB2AA5751481ULL, 
            0x0394D96E2C74858BULL, 0x6076C195B5A0BC63ULL, 0x892B8E1BA78AAF16ULL, 0x3F1465B89F0C6A21ULL, 
            0x732DC1DA6430681EULL, 0x3FA0332983505C01ULL, 0xE26DE9E970D4C4ACULL, 0xED85637A9CB3990AULL, 
            0x41550C10957DBAAAULL, 0x49A995DF0FD587B3ULL, 0xAE64CADDB13E113DULL, 0x0A2E10C76393F1DFULL, 
            0x3BA1C16737D47965ULL, 0x02C2DA51DE7E5026ULL, 0x2563AF8322472186ULL, 0x3B985C1B18F17AB7ULL, 
            0xB2130CE265808445ULL, 0xDE88A29503A93684ULL, 0x600A418FF4E459C1ULL, 0x93B962AD11130AB9ULL
        },
        {
            0x7A63F9B63071319CULL, 0xEC041A860B5197E2ULL, 0xC534A486D8FD02E5ULL, 0x26B14F8C5F36FE9BULL, 
            0x5D48B99548BDA53AULL, 0xC7116A4FCF95497EULL, 0x2C77C2BC69262F8FULL, 0x43599BC07C028D3EULL, 
            0x4658A63F5A3CA7A8ULL, 0xE98A5F83EB75BC8FULL, 0x7B6FFB2C46B38B94ULL, 0x769B719765D6BF08ULL, 
            0x207AA00B6CE2C74FULL, 0x01999354A28B90EBULL, 0x14C0B0FEB7090B86ULL, 0x684DD0F50CFFEA1AULL, 
            0x27DE9F79662AEDD5ULL, 0x9D70784A5F064663ULL, 0x0C2ACC9DE85D3B25ULL, 0x6C8E876F46FA6E45ULL, 
            0x34227F6DB2B9FCBAULL, 0xF1C6B93D025DBFEEULL, 0x9AE8D443431EBC6AULL, 0x8CAD8E660FB337C7ULL, 
            0xA67D4AC740225BCFULL, 0xF7206A44F1E1A49FULL, 0xE186FFB0BE391B79ULL, 0x559EB4DA3A2BD37CULL, 
            0x33CC94BF3E8BF1FFULL, 0xCDE9404DAB636B57ULL, 0xBAFBE386E11AD295ULL, 0x01B829286C83E6EFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseCConstants = {
    0x0DA89992F7FD40D0ULL,
    0x394E28793C2A49EAULL,
    0x6A35B1EB78D8EB09ULL,
    0x0DA89992F7FD40D0ULL,
    0x394E28793C2A49EAULL,
    0x6A35B1EB78D8EB09ULL,
    0x04E8204D79341202ULL,
    0xC87BC3E07408BDA1ULL,
    0x50,
    0x1A,
    0x02,
    0x5A,
    0xF5,
    0x82,
    0x2D,
    0x5B
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseDSalts = {
    {
        {
            0x435E24BB14B61CC6ULL, 0x111F9ACD6BA48EDAULL, 0xD5542504F043F6A0ULL, 0x267600E4B672C86FULL, 
            0xDD638213FAAD8943ULL, 0x24953191C6704F51ULL, 0x7CB370C3B9E8537DULL, 0x75A8C5603BAAE96DULL, 
            0xDBC299AD6FE28B23ULL, 0xFBD8A9F0B20C997CULL, 0x60924BE1E82AE443ULL, 0x864963FD17C5DFD8ULL, 
            0x5572CA21415DE6A7ULL, 0xB4EE7B6338A45E55ULL, 0xE781DEC467830926ULL, 0xF460C6F37FD4A077ULL, 
            0xEEEB408092B9CAC9ULL, 0xA1613C3FD5EAD9DAULL, 0x697F939D5581D6B5ULL, 0xF54938A4977AF4E7ULL, 
            0x5E55E33ED1AB6C4BULL, 0xC5788BFAF5BF1585ULL, 0xA50F601853A3B504ULL, 0x93B5ADECD5117AFEULL, 
            0xF4C615ED83FF432CULL, 0xF7748288FD15242FULL, 0xD3EB75E58DD8183EULL, 0xA20935AEEF79704CULL, 
            0x63BFB564635DD8E3ULL, 0x8759879CDA681540ULL, 0x7E20A2926B95E64FULL, 0x34E5AFE6CD367445ULL
        },
        {
            0x7033A31272E054D6ULL, 0x820FA557093672D7ULL, 0x95FEEC14F3F8B260ULL, 0x2CFE354AF3846939ULL, 
            0xC4EF6DD363195C2BULL, 0x008DB50F9AE8C9E0ULL, 0xD4850CACB9B5CC78ULL, 0x39A122FCAF7A7A94ULL, 
            0xB58F004733BAA7CFULL, 0x04AA370462344FBDULL, 0x680F31700BF688DDULL, 0xF03FAAF002FC782AULL, 
            0x2B4218E9931AF3FFULL, 0x72FAB30181C30D1BULL, 0x9D2E799D9B859102ULL, 0xB4729C4EC19C3546ULL, 
            0x694023943BCE5F08ULL, 0x12BEFD9576A8B021ULL, 0x94105668A688CD6EULL, 0x835BA881ED34EDE4ULL, 
            0xB95175213C4C797FULL, 0x4C147E62F542666AULL, 0x160238EA640F5354ULL, 0xB68FCECFFB7FBBBCULL, 
            0x1C24BFFD902B54FCULL, 0xD7A99E02E9BACA26ULL, 0x848A5EF262A91A3EULL, 0xD3382476A741DEA5ULL, 
            0xC441842F44EEE5EEULL, 0x07FA4CACBE686695ULL, 0x1130F7CEB3EC835FULL, 0xD8775DF7112E0BB0ULL
        },
        {
            0xE955CC64D7E8A447ULL, 0x98556F5071270D7FULL, 0x537A013BAE88FB20ULL, 0x3079017EF5CCCC77ULL, 
            0xF0DBC45E4A8D10F4ULL, 0x4086FE20CDB78DBDULL, 0x27C1F878A79028D9ULL, 0xA512569B6404036FULL, 
            0x6B34F86E2CA3F251ULL, 0x4362169393F8953CULL, 0x6719DE47B8565E2DULL, 0x157DB8788B7A2906ULL, 
            0x9DEB9D2497220302ULL, 0x40C897EF67095EC4ULL, 0x3BAC874C441D249AULL, 0xFF5758E147EE6625ULL, 
            0x5E14116AD4E169D9ULL, 0xC5BC409A6B29B224ULL, 0x3BCB2BEC21A4C0D2ULL, 0x20FA3C5DC1E7608CULL, 
            0xCBE60DDB4366471DULL, 0x47AD2F4F7D5833EDULL, 0xCFE99D9870250F75ULL, 0x95D1189E77665EC5ULL, 
            0x6FEB029C8FA7F0E2ULL, 0x4132791E3C3C3D7FULL, 0x025143035F139AB3ULL, 0xB6055C852269B1F4ULL, 
            0x6F8EA21D8E6BD919ULL, 0x1BB8BB279B342D1BULL, 0xD8C038FDED351670ULL, 0x61594FFBDFD521C4ULL
        },
        {
            0x51A9D9C03FFD21FAULL, 0x1299CE67C03B6632ULL, 0x4467FC0FD1C8225FULL, 0x366B9BD1BE84270AULL, 
            0x3076233927124EE3ULL, 0xA098CCCC014BE8A6ULL, 0xE268119B0D027F3BULL, 0xAFFA0B6E5F5E8CD2ULL, 
            0x70B8CBE23920DA96ULL, 0x4E26678826D50D8DULL, 0xC57844A392D54371ULL, 0x819878E857E8CFF4ULL, 
            0x6CF0228F4313BA15ULL, 0xB210A97FEA77DDF8ULL, 0xDC561F73391E61E2ULL, 0x6C8E04B03258AECCULL, 
            0xA1C0BFF589E4A3D2ULL, 0xF8ED88E1611DCA0DULL, 0x333AFB1BC87496B5ULL, 0xC83120DC0FA23C34ULL, 
            0x5893D03E2D80A3EDULL, 0xCAE52AB41785208DULL, 0x8073BF473BCEFC00ULL, 0x0F23ED16C150A736ULL, 
            0xAA4D8E167FE39CEEULL, 0x6F132C2E70334F63ULL, 0x78DBDA2412AB6151ULL, 0x835D533B3D175FEAULL, 
            0x7383BFCDA7E4E825ULL, 0xBF042EB8F732ABB7ULL, 0x802898532E44E9C8ULL, 0x7653A653FF91074FULL
        },
        {
            0x748354BB87808243ULL, 0xEBA29C5EF9BD410AULL, 0xBD19EFBC9EEFFA1DULL, 0x8C40C57BFDE21227ULL, 
            0xB428B336B8DB1E91ULL, 0x0212C56E21912AFFULL, 0x963EB7A4E0D87F97ULL, 0x431E4F98CAF1E092ULL, 
            0x9CC64CE2AA049FBAULL, 0xA9BD94F0F8680253ULL, 0xCEF99E9D39100587ULL, 0xDC0461115FF611B6ULL, 
            0x8CF27FDAA006F209ULL, 0x508640DFCE85EB5AULL, 0xC53DD5F18982131AULL, 0xB9AABE9B2625A62CULL, 
            0x6350E4C65123A348ULL, 0xB6D0D6E88B8C1127ULL, 0x001D8DA1565C0207ULL, 0x80E45B60644DFD83ULL, 
            0x44757D291B0D8CC6ULL, 0xACD3D3F4AFA6C07CULL, 0xFA84DAAE4DBD749CULL, 0x1AEA8069867B3CE4ULL, 
            0x8D7ECAC92730768EULL, 0xA163D75D64BB70CBULL, 0x1C0485B577F87966ULL, 0x8A7E129F0802F0A8ULL, 
            0x42FBB2238B870D1DULL, 0xD9446DD25217235CULL, 0xCFFF48F2512E1F1AULL, 0xB7B638B45ACFC248ULL
        },
        {
            0x01D8529DC7E66716ULL, 0xBB2C981C0526A2D1ULL, 0x62FBF43C82590ECAULL, 0x0B6BA7F6C6AFD9F8ULL, 
            0x31F4D2E659BBB674ULL, 0x7EE575F306E8CBD5ULL, 0xA78912CF68DFEDCAULL, 0xE181D4474F303C93ULL, 
            0x4C5717420C3A4A86ULL, 0x1CE435A7626EE84EULL, 0xB068276E2D2437D4ULL, 0x090F30AE5B592174ULL, 
            0x01DF885F1998149FULL, 0x8903D10780030FF0ULL, 0xBDBD75A1B42CA6DBULL, 0xA64B624CE96EB456ULL, 
            0x1071B0F4B7C4CBB9ULL, 0xCC0BBD2FD36B7E80ULL, 0x9000B146DA86F132ULL, 0xC6C3578099C55A62ULL, 
            0x3C57748603D6FDF7ULL, 0x2A38060D09B625BCULL, 0xCFDD072E29997E5AULL, 0xFB7C900BEEEBCFD6ULL, 
            0x5DD6D25540B6F84DULL, 0xA64328FB4100A1D3ULL, 0xA25EC6D96CDF8525ULL, 0x928080C3197C5F81ULL, 
            0xCD52B1C6389C03E4ULL, 0xF47FBACAC89B2296ULL, 0xFA6F0EAF332B8298ULL, 0x2C909814AF18CDFBULL
        }
    },
    {
        {
            0xC4029D61C3A717B4ULL, 0x8CA8C67CCAEA3FBEULL, 0xE347B0A08BD2E8DAULL, 0x723CED68A85F5D8FULL, 
            0xEB6E5A2B8343CDB2ULL, 0x3FEC7CF3BA69BEA2ULL, 0x51A68DBA7649E9A9ULL, 0x7C2CBEA327E2C71BULL, 
            0x737E366AAB9CFAE0ULL, 0x3821D3346AF5582FULL, 0x0DB1A15F38483548ULL, 0x27440FB9DAFCE00BULL, 
            0x8C7A895D4F2B60BBULL, 0xFDD27E2DFB1DE332ULL, 0xBF56061121C6FAB1ULL, 0xE486AD5CA9B7C538ULL, 
            0x8DDC9833C4375975ULL, 0x0114CFE473334AA7ULL, 0x1C3BD44821F05961ULL, 0xDB379210AF845876ULL, 
            0xEA6B86F4C94025A3ULL, 0x12BFB3AAC15062F3ULL, 0x33DAE8664694CC45ULL, 0x6CF3FB3D424906F5ULL, 
            0x9FC6C7BE74C05B41ULL, 0xEAE2E73CCE080577ULL, 0xA8188645E574A4EAULL, 0x1D8AA6CEF62FB9F1ULL, 
            0x9A143802ECD62682ULL, 0x75209EFFA4813D9FULL, 0x4430051F90D62A15ULL, 0xE749A967230B19ADULL
        },
        {
            0x03E78E6FA40F8588ULL, 0x0136A0F8EB35B07BULL, 0xA517A40C7F938F81ULL, 0x2D1717D7BF4C1B56ULL, 
            0x68D90A58FFE229B9ULL, 0x8D14ADCC09CE4702ULL, 0x79EE0054035D63A4ULL, 0xAC82444499F8858CULL, 
            0x07A6D85371A2ECF5ULL, 0x06A26DD9FBF93C7DULL, 0x70F8DD1739D6F415ULL, 0xBB5228626738E50CULL, 
            0x0E10AAC467A499D0ULL, 0xDF84C909AC615559ULL, 0x93F4966A918AAFB1ULL, 0x4C01D4F7C9F4355FULL, 
            0xB69E2D9D2D1E094AULL, 0xCE528E62D8F7CFEDULL, 0xBE9DDB8154FE1E9AULL, 0xB849F70B053332ECULL, 
            0x636C9FB13881A2A3ULL, 0x61F4CB014348BB8AULL, 0xB22AF5DC30CE785AULL, 0xB2DA05BD4A4EFE64ULL, 
            0x21A5E28C2D64168AULL, 0xC66B26CC2E9E049FULL, 0x0D9D0DEC1022DDF4ULL, 0x045D0493F21A3CA7ULL, 
            0xFB02639596AB0999ULL, 0x3FBA59D09B080FB2ULL, 0x2807553FD8B31805ULL, 0x9C4BB63088988817ULL
        },
        {
            0x51F2551A0437421BULL, 0x0DA3C5A3A6FD1A17ULL, 0xF4D5928BD375CC96ULL, 0x18A8AADB559E4E83ULL, 
            0x4377A2498ACD4AE2ULL, 0xD5A4678BA1AC73F1ULL, 0x33F1AAECCE3BB92FULL, 0x58C9A5DB09835A76ULL, 
            0xCD87E7ED2C764E7AULL, 0x6685205C681D9DEBULL, 0x5503D8A2060C9D7EULL, 0x569AF35183A9FDE7ULL, 
            0x462F395F15AD94F9ULL, 0x8595C9020A6C0ED1ULL, 0x1388755A399DE66EULL, 0x96BF1D46C235C9F4ULL, 
            0x3C66F542669C4095ULL, 0xB3A5AEE8DDC4B92AULL, 0x5FB853C692B73C40ULL, 0x853ADE23AD3E95A5ULL, 
            0x73940BE507BB4FC9ULL, 0x33B035658F4E32EBULL, 0xA1929F173FEEEA69ULL, 0x12B016F30560D053ULL, 
            0x662D95CC516A4FB7ULL, 0x0D382C43D21D1A9AULL, 0x7E87B2F2C0765ECBULL, 0x7E9321F7A65D35B7ULL, 
            0x6679EB09D06C8FE9ULL, 0xD29FA826894A6E23ULL, 0x07A9703610165926ULL, 0xFE9D6331533AC4B5ULL
        },
        {
            0x43FF4605564792E5ULL, 0xCD874F3896ACFF38ULL, 0x8399FC6D089AED54ULL, 0x4D68D77B6F796F63ULL, 
            0x8C7B563456191417ULL, 0xD83DD871A854AE26ULL, 0x6ADB25EAE6B043F4ULL, 0x5B15D75E9AC6EC45ULL, 
            0x7B573B0CE204D1C6ULL, 0xE45124D56A72C8ECULL, 0xEA88B8C44614E7C0ULL, 0x8072FD92C1EBBAC7ULL, 
            0x2C3B1E8529875068ULL, 0x6074D2AFE7D63155ULL, 0xC157C88689967910ULL, 0x18DD8198A5EF0145ULL, 
            0x38D73604850C4DE7ULL, 0xF53280CA22E7A25CULL, 0xB7046BA69DEBE5BAULL, 0xB43C90179B44CEF4ULL, 
            0x540D6D620AC331A0ULL, 0x04E8246D06C8A3E3ULL, 0xA6206D20DB910F41ULL, 0xA17D2A0FC3544ED7ULL, 
            0x5618C531D72C3407ULL, 0xC2540581699E5692ULL, 0xDDD213F6996F3B03ULL, 0xF18FD2F6C62DED6EULL, 
            0xF5FA7A82EF91FFC3ULL, 0x9E8CECDC4EFBEE73ULL, 0x47F2A804394D99F4ULL, 0x7270F2C2DC1CACA3ULL
        },
        {
            0x1128A8382D6BBFFFULL, 0xD1041C28BBA34B9BULL, 0x0A187539B672E8EFULL, 0x5EEA6022D99A4411ULL, 
            0xE61ABBFF796F8A77ULL, 0xD559D96CC5742711ULL, 0xF080E9F3454BAFEAULL, 0xEBD455417D8497F8ULL, 
            0xB9D403B6AD3EE0ACULL, 0x95A0F209033E498EULL, 0xDCB25417DE4B03A0ULL, 0xC66C3481E10F6ED2ULL, 
            0x9182FDC5CB97E9B8ULL, 0xC181F92244D3304DULL, 0xAC5946D8C0DE441BULL, 0x8D2C9BE0C5F3B3DDULL, 
            0xD85174BB8E43F668ULL, 0xD0DDEABFB06E32C8ULL, 0xBBBF1ADDEFAF3AD6ULL, 0x242736153856B870ULL, 
            0x23AF9F338FCCA5ADULL, 0xE840E7C652E0C6F0ULL, 0x9E030CC1712097CDULL, 0xD6217C8B7C3A7B62ULL, 
            0x514E293D244AFC48ULL, 0x4B24BE618C589111ULL, 0xCD7A137960E433E1ULL, 0x761C2B0702C73A0BULL, 
            0x803DFB85451F8F1DULL, 0x3A1C0C90A825E08AULL, 0x3A0C7DAB2EB37BDBULL, 0x3A6A6A7D286E0FD4ULL
        },
        {
            0xE135FC25F517E9C9ULL, 0x1080330D662F466EULL, 0x4F52534C0799576EULL, 0xBFDB8A1B95FE92E3ULL, 
            0xADDBE6B36B0D7C03ULL, 0x3224D50669458E73ULL, 0x9B3727584007920EULL, 0xF1D7C2A11AA55D7FULL, 
            0xE5A105C7615B74B9ULL, 0x3274BAADE704F3A2ULL, 0x0BF76915BFF6C829ULL, 0xAC50FED19D381043ULL, 
            0x274331C84A05A099ULL, 0xB56104C0C7BCB3BFULL, 0x7C2B6F33984D65EFULL, 0xE7C9B8027725EA0DULL, 
            0x4CB4E91893DA5C5FULL, 0x43B101443E1B8911ULL, 0xAB8C1537126746D0ULL, 0xF966B0FD2826E9CBULL, 
            0xA8DD335FC372B9BDULL, 0x71DB6B124566FEB0ULL, 0xC32329C56A827D5FULL, 0x6CF0B155B85C4F2FULL, 
            0x7863953720DA5EF5ULL, 0x6B5EF79972D42C56ULL, 0xD858ABCF583DB068ULL, 0x25E4E55C80592042ULL, 
            0xAEA8D9B768EB028FULL, 0x35CEE530286439BCULL, 0xAE93807D4006374FULL, 0x924464FCC4A3EFBEULL
        }
    },
    {
        {
            0x6CF34E2E1A000804ULL, 0x40AAF7905697D27AULL, 0x8A050512F01E063FULL, 0x40B24261B25090ECULL, 
            0x7BFC7FEF3113ACF9ULL, 0xCDAB20110AA606CAULL, 0xD6944B473E878328ULL, 0xC8C2797D987EBFB2ULL, 
            0x36CFAAB7CE7FB975ULL, 0x1976803644C928AFULL, 0x9A24EE608D8903EAULL, 0xD2771F363CCFD2B0ULL, 
            0xA94917C77561D5CEULL, 0x1BC1DE7900CD1B59ULL, 0x0E9BB96F83854251ULL, 0x151149721AAA27ADULL, 
            0x1974835D1C9B5941ULL, 0x178B0F55969FF90EULL, 0xD2AD6E207E19A9A9ULL, 0x33BFBA3A4BF205B1ULL, 
            0xC51931229AEAC13CULL, 0x90AF72CAED26A9F3ULL, 0xA1BA0808CCD57619ULL, 0x8A268A30F9CABB66ULL, 
            0x63DC33959EA2ECCDULL, 0x6E70E531FE6D60E1ULL, 0x7741FEB1508B1F57ULL, 0xDECED3EA518A2CCFULL, 
            0xE942003E7DA1C2D6ULL, 0x2FA5F09EE463E632ULL, 0xA8ACC990DA16456AULL, 0xA92C311C4EC054EBULL
        },
        {
            0xBD74CB13A7E9298CULL, 0xD69E588E8CDEFF17ULL, 0x07F9BF7D20CBD905ULL, 0xBC808C8D198641A9ULL, 
            0x740A3ED7E9FAF6AAULL, 0xD2AC699AFA248E48ULL, 0xC6FAB69F255FC202ULL, 0x2C744FF7715CF484ULL, 
            0x0DA298FB2C017D20ULL, 0xA66AA249ED7B2F5FULL, 0xF14A09CE8C12C345ULL, 0x59045C16BDEEAF33ULL, 
            0x71A111E8976B9227ULL, 0xA164506C6EE73BABULL, 0x53DB54941AEAB8CFULL, 0xF47B37F4EDCB344FULL, 
            0xA563EA01E77821C5ULL, 0x7A8A43B9CFF89F3CULL, 0x7BD0ED7F46AB0274ULL, 0x0B005CCF4A3EF54EULL, 
            0xA584B921FF2F5580ULL, 0xDA0F063964C7773BULL, 0x0819B8965B58187AULL, 0xBBFCA05732B0E362ULL, 
            0x0F6E2D21C9D6572DULL, 0xC9B6FF22F0E17B13ULL, 0xB5F8D33FBF647FD4ULL, 0x76937D064BB5F83AULL, 
            0xA5F12E99ABC2BFA9ULL, 0x06519116E73A1D21ULL, 0x8541F6F7ABCF3DF7ULL, 0x3A060C4EF6D3C3C7ULL
        },
        {
            0x91A85D3E4D54C66EULL, 0x60BABCA96402FB70ULL, 0x9D54EA943804538CULL, 0xC0548E9EBC334C72ULL, 
            0xBA5BA47550E40762ULL, 0x03733094D098CF3EULL, 0xB0CCC0CDE791E35EULL, 0x4478316CC40B332BULL, 
            0x856C9FBA3799E3BCULL, 0xA2F83BBFE0D91AC2ULL, 0x74DA9B49C50C00CCULL, 0x94E3BDED38280B1DULL, 
            0x5F360E6AD1E85B21ULL, 0xD34A28C61F49BC3EULL, 0x3AF79E052FAB11EAULL, 0xFB41C8B3E60CA7AFULL, 
            0x7F50FCDC8FA708B3ULL, 0xF920FD7C9D12B628ULL, 0xCAC04754DCAB3859ULL, 0x28690FBD6A174CA0ULL, 
            0x0BF3E23D3104A3CCULL, 0xCB1405A749034225ULL, 0x2D57953C7F2793B8ULL, 0x3AF1BBF3C64FE45CULL, 
            0xF7F9AE1B25D9B44AULL, 0xA5E327CCC0611A89ULL, 0xA44A16C0627C89C4ULL, 0x83657732613FDDCFULL, 
            0x7E68A3DA03AA0DE1ULL, 0x94A74B55DA89AE91ULL, 0x90B6713E47573392ULL, 0xE0D166E5B45C8506ULL
        },
        {
            0x3986168141BF5D5FULL, 0xAA313C278BB4BC32ULL, 0x0947F666F08179DAULL, 0xDBC3C406340FF53AULL, 
            0xDE2ABEA632449E09ULL, 0xD8682DCBB8A3A01BULL, 0x88837D327A6F4816ULL, 0xB02982DF85BF9AE8ULL, 
            0x7EA2EAF8BB762899ULL, 0x548BE4D2A4C06EDDULL, 0x533423197370524FULL, 0xDE5B674F837B5625ULL, 
            0x4E68C105A6E76AE1ULL, 0x1EC4CDE8CCA91618ULL, 0xC37FB97EB757CFC5ULL, 0xBBB88DED892F21E8ULL, 
            0x424D17BFFFBABB98ULL, 0x437BDD211AC199E4ULL, 0x56170717EDC0A781ULL, 0x3A8F4031B2B284C7ULL, 
            0xEC4EDF4B9D6D9783ULL, 0x534585A76E8796BDULL, 0x381EFD3700CAF1FDULL, 0xEF023950B58F9D40ULL, 
            0x67EF76C1FBB5F9AAULL, 0x4589B543935E8E4FULL, 0x1F962064E35D565EULL, 0xDF127B2038840B67ULL, 
            0x55D8BE08C1491E0CULL, 0xA31FBC9A0548DE5AULL, 0xBA6A918098577E43ULL, 0x32FB9002C9AE3960ULL
        },
        {
            0x8EF8FEC8760EF071ULL, 0x479C9CA0F2D4C2FDULL, 0xAC658B6E0B755C4BULL, 0xE016FD7F29A1A5E0ULL, 
            0xC4505DE0CC8587A4ULL, 0xDDD4C97F796D33CAULL, 0xDBBD50B1812A5CA1ULL, 0xBA553119378DAE5EULL, 
            0x02C402C2C95D672AULL, 0xF476982C88BD0138ULL, 0xA6CC50F75E157796ULL, 0xF08C88888214E1D8ULL, 
            0xB80ACF4576C5119AULL, 0x7C165F8CE0E23E78ULL, 0x955ABD8255F3E4DEULL, 0xCAB449FD4BE49504ULL, 
            0x2B2C559A6DD457C3ULL, 0x9A109F2DA6A86614ULL, 0xB73A5F762543C134ULL, 0x1C78B005B24FA138ULL, 
            0xA34B6DBDA32265EFULL, 0x8F2E2B881593E927ULL, 0x154C38101BCEDCEEULL, 0xAD84661D3F31E649ULL, 
            0x8DFCD5332E6E0EDEULL, 0x834A5D665DD02DAFULL, 0xB877B3D10BB89EDFULL, 0x1822D0BCBCE52A86ULL, 
            0x51D69B41C0C2B8DBULL, 0xBC6391521CC6872BULL, 0x12C4D30907F2FB32ULL, 0xD75166857BF0F161ULL
        },
        {
            0x378AED1870E4395EULL, 0x712A43D5578696F7ULL, 0xA2220BB074D45AC7ULL, 0xEE029F473D187FDDULL, 
            0xE2209854F676275DULL, 0xCFF1329181655945ULL, 0xEB8F1D9E2DF7CA3FULL, 0x8752E33E2A329079ULL, 
            0x64ED2962A5EA5F7FULL, 0x11A2FE19D5DDE108ULL, 0xE1D0EBEBDB5ECCE2ULL, 0xB71A46B54C71FD32ULL, 
            0x8B2B3CF52DB64246ULL, 0x550E9FE858124380ULL, 0xAE498DBF47D0EE8AULL, 0x7A5BFC62B44C921FULL, 
            0x4BAA6053DC4002C5ULL, 0xB1155D199A39B373ULL, 0x43367D6AAAA3AE51ULL, 0x4ADCE504BF4D47B5ULL, 
            0xB3A200A3DBFC5ECEULL, 0x5C008B8CB022EFD3ULL, 0x4CD1DF218D036105ULL, 0x16B568625E4C666BULL, 
            0x3FED6BC6AD6408BBULL, 0x63E6DE193F7B0F30ULL, 0x9912465A20A8CCD3ULL, 0xDB83B8F86BC4FC12ULL, 
            0x1F6CAF161B68127BULL, 0x30F35564C2A7CBC7ULL, 0xF95331D35502BCFFULL, 0x618047D8CE05CBEAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseDConstants = {
    0x46981BC5D25A433AULL,
    0xF86D4760D69EF877ULL,
    0xD5F14B2829D2CAAEULL,
    0x46981BC5D25A433AULL,
    0xF86D4760D69EF877ULL,
    0xD5F14B2829D2CAAEULL,
    0xE85B6406D13B7FFFULL,
    0x42FF3D5A9A81E81AULL,
    0x79,
    0x58,
    0x64,
    0xAA,
    0x85,
    0x14,
    0x2A,
    0x5B
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseESalts = {
    {
        {
            0x20DCB8BF2937BC1CULL, 0x42BF1495B261CCC6ULL, 0x472F446B818E4B95ULL, 0x0A9A729784DEE685ULL, 
            0x70D91FD1FB8EF8D8ULL, 0xDDF79CA367F3179CULL, 0xE890FC9498CC90E5ULL, 0x9915603FC1F15DB2ULL, 
            0x9F1FF95D87FB9753ULL, 0xE7E25166B83FF464ULL, 0x76854896591B2090ULL, 0xD87DF48CFD5C0049ULL, 
            0xAEE298AC3764DD9FULL, 0x1FB65C1BD2774CAEULL, 0xDA4FE7881E4606F2ULL, 0xF59FF2B319C7558DULL, 
            0xEF6C2040A84145BAULL, 0x71D9C510D919972CULL, 0x2D562A245F97F80DULL, 0xBF01AF8FEA706590ULL, 
            0x2F95AE7623BF10C3ULL, 0x60005ADECEEE560FULL, 0xE7A96D4FF8AC5F99ULL, 0x02D8F41218B03EEFULL, 
            0x776CE01D7E575B6DULL, 0xFB6AA83EF2487C8FULL, 0x9DBF31154CEC1279ULL, 0x947AAB0819AE6322ULL, 
            0x1A4B12C288E4AFDDULL, 0xDE385C4DCA14FCD2ULL, 0x5F3F2FAD16A739F2ULL, 0xF271203579548AB4ULL
        },
        {
            0x0FAAE2548420CA88ULL, 0xDBEEAA9F300FDEBDULL, 0x0BF95EE0289D14A1ULL, 0x4E14D8D5903257FDULL, 
            0xD6846481DDA187C1ULL, 0x1801470BAA6E4AB5ULL, 0x6DC644F8FC64E33CULL, 0x3C1FE78791D57987ULL, 
            0x8A3C3B11F1729903ULL, 0xC96263727AB968A9ULL, 0x103448005BF6812FULL, 0x93545BB25F67923FULL, 
            0x48465C90D0BEAFF7ULL, 0xF7D380C033E5BC90ULL, 0x3D3BBF19AC49464CULL, 0x09D3974950217DF7ULL, 
            0xB1437CB3E6AD99CEULL, 0x59059B39097FD1ABULL, 0xDCA66DC7804F3AABULL, 0x3A0177D422217AD7ULL, 
            0x509EF6057F1C567FULL, 0x4B4AAD733010B6FFULL, 0x59AC08372FC08169ULL, 0x6C940333ECAE7D27ULL, 
            0x7DBA0E493032ABE9ULL, 0xBBCCD0D1B919806EULL, 0x153A2D9D03BB5F41ULL, 0xAF45521741C191B9ULL, 
            0x24DCBFE54E0BFF17ULL, 0xFF41669AD05A1C26ULL, 0x2773AD608E915497ULL, 0x1617A96E3C3ACEA9ULL
        },
        {
            0xEF7089D44901EE44ULL, 0xA9E426C2E6E7E957ULL, 0xA01B64018C5259CCULL, 0xAD8775D5E92AEAA1ULL, 
            0x512C66C44228F677ULL, 0xB20B5E8ECE7D0976ULL, 0x586BBAD29421F097ULL, 0x38516A8A815340F0ULL, 
            0xA01FB65A078DCB05ULL, 0x08A85B971015496CULL, 0x34B8A9D783F10D6EULL, 0xAFEB1F520823F6A5ULL, 
            0x9D5773ACE18057AEULL, 0x53C1AFB3AE766DADULL, 0x2C711457DEFC100CULL, 0xD04DD495212D2F11ULL, 
            0x3221A1CCC7898DF2ULL, 0x5F2A00E6067CC9E8ULL, 0x5490E2E0CA6F941FULL, 0x351C98848F1C9AECULL, 
            0x838B0ED6DABCE6D4ULL, 0xFD83008A3A5EB0B3ULL, 0xAB0ED74D4F4D65D4ULL, 0x8B81857030A1B7C9ULL, 
            0x4E51B3318F192DE3ULL, 0xBDC3C82078897FA4ULL, 0x9FA3EA4EC1AA09F3ULL, 0x331072F418087682ULL, 
            0x180802CC25BBDD90ULL, 0x4E9115F337615F48ULL, 0xB43B0DC868EFC230ULL, 0xA76A0BAD3660241AULL
        },
        {
            0xEFA96CDF460C0B67ULL, 0xD2AC4589314B6F92ULL, 0xCB2FE6657EBAA5F4ULL, 0x5591E0A7203FC3EFULL, 
            0xCF01C50AB37FB6DFULL, 0x60BC4EBF8DA371EDULL, 0xCD9B108E74AF8969ULL, 0x2E88BF5E6C7D0F00ULL, 
            0x4A835B6C9ADD64F8ULL, 0x71AE00CCC8D9CC40ULL, 0x3EECDF3E2628FD1EULL, 0x63128A0A06D3350AULL, 
            0xF4DB558DC7C69963ULL, 0xBC3542EE8AAC5888ULL, 0x4BB2C79393AC1DD5ULL, 0xE172610024CD57F2ULL, 
            0x791038E52AF9EA31ULL, 0x0ADD07A195B85D09ULL, 0x15015F6868D8F95AULL, 0x529E46363497F705ULL, 
            0x9DE9881C8398EEB9ULL, 0xC8F6BB667C5DB776ULL, 0xBDB84815544E2DD1ULL, 0xF7893CAB924E705AULL, 
            0xD1BC12A559C88200ULL, 0x1F981A68BA908F17ULL, 0xC5EDC28E77394027ULL, 0x771FA0FCD1A49DC6ULL, 
            0x6E2297B54A4602B5ULL, 0xB49489272ED062D8ULL, 0x9F52F5B2C4F31812ULL, 0x90FC776F28DDD3D8ULL
        },
        {
            0xE755B7B4AFF2C75AULL, 0x5B738C0E285B6921ULL, 0x3F7D65FB74A4592DULL, 0x98C194BCEDED42E9ULL, 
            0x90529B965E5229AFULL, 0x0EE99C3A808AE314ULL, 0x8A5969011533FAC3ULL, 0x44D61D22C546AECBULL, 
            0x5B16C874F59A542CULL, 0xDF4F687651717800ULL, 0xFBFF4F05EB4D3D95ULL, 0x13C4280C12D4D693ULL, 
            0x71EE5C7D0136A1ADULL, 0xF543BB0DA91A8634ULL, 0x6AF73DB2A2B066DCULL, 0x7471D77A4C201F75ULL, 
            0xD1E80A1306C4D197ULL, 0x062CA36871F5C6F5ULL, 0x2E2869648DCAF0E8ULL, 0x39CC5CA1F012CF41ULL, 
            0x1EE89C1D4D8FEDECULL, 0x5F74960949E15AB5ULL, 0xC87FCB73EFA6FB5FULL, 0xDEF270DD0FA6AF5CULL, 
            0x0167AF32707E5B2BULL, 0x0BEA2774116A7F8DULL, 0x623992C5B4755E68ULL, 0xC6598773734BEFE1ULL, 
            0x488C61180E9352DBULL, 0x8656ED803EC79874ULL, 0x58B79E3EE0B3B8DAULL, 0x4E9BAB1C29D506E7ULL
        },
        {
            0xDC5819E542AEF351ULL, 0x53A083C73C2B3A2EULL, 0x09E542E03E1ADADDULL, 0x9A8107310417BA23ULL, 
            0x12A8CA0FFDF66C01ULL, 0xD05C3F0441AA50A8ULL, 0xD49BF7B6810CBEA8ULL, 0x6E15A86F020B172CULL, 
            0x2EF771A512849D4FULL, 0xA180D26EC46AEFEDULL, 0x70D4D29740C36128ULL, 0x3184D049D875500DULL, 
            0x564F528EF41B476FULL, 0xFE9AA809D8F41E35ULL, 0x493CF12F4F6B8936ULL, 0x2B9D2602F53FB475ULL, 
            0x1ED59FAFDFB1E987ULL, 0xF0EB15E2879D8874ULL, 0x08B20B287C9BC4FDULL, 0xC3790EA21D154595ULL, 
            0xB4B78EB8FA8C3DD7ULL, 0xA9907B6A4AF97630ULL, 0x73A631F43B1BE0CCULL, 0xF86F5AF07813863BULL, 
            0x83E88C0946D82081ULL, 0x005285617C5F841FULL, 0xDE0D03CAF9B031C0ULL, 0x97E0D8BE16D5CA93ULL, 
            0x69DE0FD8A2B7A36FULL, 0x319D57223F3AD663ULL, 0x4660205B0E475B57ULL, 0x7E26382DE67C62F0ULL
        }
    },
    {
        {
            0x460FCDE6723D441FULL, 0x0B9CA0E6F7417B97ULL, 0xB8334BA6B53C911BULL, 0x3F4ADC61FE5B7F49ULL, 
            0x4E6B2BADC77B3A9AULL, 0xB448B3D80713DBD3ULL, 0x340EBD6B9772D83DULL, 0xFFA7C8CB0839BCD9ULL, 
            0x4ED4F1B0A2B327E1ULL, 0xA252AAFB65AA63C7ULL, 0x609444AF7C248718ULL, 0xFF201324192AA57DULL, 
            0x47730C51321E3C78ULL, 0xC5D004DBB3E690A9ULL, 0xA4A3BAECD3B882A6ULL, 0xBF350D47AB7D4A74ULL, 
            0x25B0D33B02E2C901ULL, 0xFFDAB944EA452D51ULL, 0x03669C01533BA56DULL, 0x7D7B085A8C3DB2BBULL, 
            0x89210F1F48E9DCD0ULL, 0x88C8487BCB4800F3ULL, 0xB077B3DD8F550FD8ULL, 0xD1CB13CEABBE6E4CULL, 
            0xF58E2DB726089A2CULL, 0xB4C78910552DC79CULL, 0xD15F2BCDEEB49AD1ULL, 0x41FE4AF298578343ULL, 
            0x2B346BE974238498ULL, 0x651DB9BA173A58C2ULL, 0x779E50B04A7C1EABULL, 0x73D1369016AD8E62ULL
        },
        {
            0xBB2DF5A0A8491FC7ULL, 0x2B5FAB53E583F9BFULL, 0xF8B4E2D4918D88BCULL, 0x502AB0C23DAEF39AULL, 
            0xC05272DBA26CDD35ULL, 0x74EB06A04086CE96ULL, 0xE30412D4F23E8EF6ULL, 0x37712162A1B2329FULL, 
            0x3E0A365B0D5B533BULL, 0x2B253BAE9D08903CULL, 0xA81E6B1DFB2D72F7ULL, 0x9D7A4F237D1911DAULL, 
            0xE1B720D8B6D9A156ULL, 0x2EE86FF7E82B03DCULL, 0x7E9ED9C7A7CE62DEULL, 0x2D0675B22F11E5F7ULL, 
            0xB258EF2325DBB9CDULL, 0xE25F437656B1D97AULL, 0x714AE0CAE167DDBFULL, 0x0CDA58E650D1F5C5ULL, 
            0xCBE0A23CE4C840FBULL, 0x710BBB77A23B7406ULL, 0xFFB4C41D90FEAC63ULL, 0x0FC5ACD29DFFB5E1ULL, 
            0xE70AC71D8DC67619ULL, 0x659A46563999BED8ULL, 0x931E7201A62029E5ULL, 0x7D02A3A544A1E6BCULL, 
            0x29C3D1567D9744A3ULL, 0x86BA698BBD2BA910ULL, 0xB814D5DC55E252B1ULL, 0x3DD412360C0465D1ULL
        },
        {
            0x83903D1F19A5D716ULL, 0x316BA6B62BE9323EULL, 0xC187E0BDD385317AULL, 0x7D43E6034FDE53A0ULL, 
            0x6FD13CC762805C5EULL, 0xC7BA52219F696493ULL, 0x8A12A965F9E64097ULL, 0x3683AF0F5AF7B1B4ULL, 
            0x5C673500149A154EULL, 0x7870607E716D101AULL, 0x5BD26CEF041B1DB9ULL, 0xC46BC896073CDEFBULL, 
            0x951E121A8327EE04ULL, 0x7A086E2B155F6DD0ULL, 0xCB26C36E5C26494CULL, 0xBF802EE9F2A4AD66ULL, 
            0xEE4AECB805A2E4DFULL, 0xA806720A4A8ECE7EULL, 0xA067B24A960B875EULL, 0xE14AD14136F8BD2FULL, 
            0x96AC62B5805ABBF4ULL, 0xE37B85B21BDD099EULL, 0x7B41463E810290C0ULL, 0x2329707D167415BCULL, 
            0x87952496D22587C6ULL, 0xCA6B029CC108DF23ULL, 0x35F29A4288D3324AULL, 0x84487BC380ADF6ABULL, 
            0x87D7FE56FAFF23DAULL, 0xBC59770B44244E7DULL, 0xA73EAB5DC620508FULL, 0xFF3EB95E5CFAE493ULL
        },
        {
            0xA07E2CE6C4B006E1ULL, 0xA56F427FDFDFEC15ULL, 0x6210F3EA18A11CDEULL, 0x1F6575ECBD15B8BFULL, 
            0x699D5F45EA18A5F7ULL, 0x55E1793E09F842E6ULL, 0xE4DC1E7DFE4EB241ULL, 0x50F98688E71D0130ULL, 
            0x49C35E1FAD3891C6ULL, 0xD93605FD4E19F184ULL, 0x911963A3CA568D87ULL, 0x46525D13C113DAC8ULL, 
            0x65AE9FEE83089538ULL, 0x34A327285F893416ULL, 0xF943F1BCAF6EA9B5ULL, 0x2734B704D77C684EULL, 
            0x11BE0F274BB49577ULL, 0x28EE6BD3239C9B16ULL, 0xBBE50576CBD557A1ULL, 0x2F94B30BE01F6F7CULL, 
            0x0CADB90D4F2A1439ULL, 0x2D80B0CDA947C466ULL, 0x8145476CAA0BF8D2ULL, 0xF7A06E74F2D25CD3ULL, 
            0x03B86E77C15DEE1FULL, 0x8C7286D6C5508BECULL, 0x4B7F6FA67A3A3F76ULL, 0x6DAA105D2BD1E76AULL, 
            0x29375CEC3D790D47ULL, 0x53C7926DE8C81372ULL, 0xB06CB61A6661FBBAULL, 0xBAA712E36AA9A581ULL
        },
        {
            0x2A9E2CF99244C040ULL, 0x6DF7235EA5F0726AULL, 0x86568925AE873E45ULL, 0xFF9AD2A64CB5BF1AULL, 
            0x1C64C779F27494ACULL, 0x6BD8ABE48DF1F58CULL, 0xA72278AF9A199446ULL, 0x6ED2B632C0630A67ULL, 
            0x61E092628AE777DCULL, 0x63C1DC228BB4B998ULL, 0xDDAAD774B738F170ULL, 0xB2E6F1C13B86062FULL, 
            0x31285EF8D3EC0465ULL, 0xCC3074D610A6C580ULL, 0x100EB1BE818D9265ULL, 0x0E81C7BFF1F5020AULL, 
            0x23D2FE6ECAC38480ULL, 0x5F4AD917009B7A8EULL, 0x3BC74CB39EC935AEULL, 0xE02EF48648CC1145ULL, 
            0xFD12DA74B062D2B8ULL, 0x34102B007437B890ULL, 0xCB6F1C4D933E08C6ULL, 0xFF0EFD9EBBEDB741ULL, 
            0x92814C7A49A18D48ULL, 0x03BAB20A627225E2ULL, 0x37A6D0F990E03C39ULL, 0x57445D456F48EB60ULL, 
            0x1DCAF9D300C449F3ULL, 0x6ED08497F89FC940ULL, 0x09364845319EFD4CULL, 0xF904343C7A3EFFAFULL
        },
        {
            0xA3B9316E3FDEA86CULL, 0x07EB5A3DC63345B6ULL, 0x65B79A6BFC742393ULL, 0x11C87C8D83433D2EULL, 
            0xF9B1AF01726378DEULL, 0xB0CAF27E87582895ULL, 0x4EECB28FD2EBC3FCULL, 0xE227DDB97C80E72CULL, 
            0xC94094F63668F669ULL, 0x78983459F7B57CBCULL, 0xC4C361BE83339985ULL, 0x37638D98DE8D64A3ULL, 
            0xD337D2986E7D8305ULL, 0x2AF05A2618688EBAULL, 0x582CE59AB0FD420BULL, 0x4FDE14EC04436F1BULL, 
            0x065275D2CB5DCB27ULL, 0x5092C5954AD390B2ULL, 0x06B97A9D859830E9ULL, 0x9ABC3295B7F39AC2ULL, 
            0x5A1E6E15185AC4AFULL, 0x1AC71D4108CB1247ULL, 0xB9FCBA7D0767F6F6ULL, 0x8C0651DBF67B8351ULL, 
            0x20F173EB6375F347ULL, 0x89FF1291A919ADA0ULL, 0xC494F376D67A0518ULL, 0x498E9B772BFF8503ULL, 
            0xE40D6BDC7F89F91FULL, 0x90BB62C285ED97FCULL, 0x4710A4FCABDA219DULL, 0x377327EBF9C17BD9ULL
        }
    },
    {
        {
            0x7D6AFF0B5F22724AULL, 0xF6853A9ED314692EULL, 0x67463A7813B66141ULL, 0x82F931F735749503ULL, 
            0xE899DFCED02DDFF2ULL, 0x2E2395EF6DDF976CULL, 0x60A8F12C41A11684ULL, 0x9C5B07DFEE527108ULL, 
            0x89C4B3099FB76F32ULL, 0x0AEB68D60D77B2BFULL, 0x9E2A526C07939E89ULL, 0x27B718140B83B984ULL, 
            0xCFD264CDD8CD74BFULL, 0x83635CA57B086F4EULL, 0x8FB55F5BC27E6AA8ULL, 0x163C9909AEEBC70EULL, 
            0x71D4D9B858D883E7ULL, 0x2C12F13A741081D8ULL, 0x3CEF8D6A6DBA2D96ULL, 0x673E11C44C5C9F79ULL, 
            0x445E54B05C54D748ULL, 0x529C093B8F5D0C0CULL, 0xF6288FF08A273918ULL, 0xE3807AE6806CBBB6ULL, 
            0x3EC628124E533631ULL, 0xDDF60AA5B4905542ULL, 0x01EA3AFF7BC16E94ULL, 0x325545021B78E85AULL, 
            0x0B69C7984C3932D2ULL, 0xDA80A12C142F3B8BULL, 0x8E30D8B824B49694ULL, 0xAEE9891FA4DD5EE6ULL
        },
        {
            0xB49F8B373069F7ABULL, 0x50B87CBA79F1BEE1ULL, 0x7F3D5382FD8C77C9ULL, 0xC4EB50D44BDE3397ULL, 
            0xA7C500859AF221CAULL, 0xEB2B441E55A53CD0ULL, 0x30737F7C80FD1381ULL, 0xEA29D2F5DFADF54DULL, 
            0x7D6F8600EF0676A7ULL, 0xBDF1FB16028BFE1DULL, 0xFD0D632966DDB157ULL, 0x8D80A632B6FCECDFULL, 
            0xD816D316441C491BULL, 0x9E1621E4BB7F3C73ULL, 0x07E544BA06A5EF4DULL, 0x4D6B0AA51D421BBFULL, 
            0x220C494FE9DFE1BAULL, 0xF897B5564AAA83A1ULL, 0xF245CADD4906DA64ULL, 0x9A2171A3B690B39DULL, 
            0xFB337B7CFC36912FULL, 0x10081930560781EDULL, 0xDF9D21C73CC26832ULL, 0xAB71AFDE29341D17ULL, 
            0x61262266E735F50BULL, 0x27FF4059310ECC2BULL, 0xFA6A4FD12BC3D1AEULL, 0x38EA95E0A19D3FF1ULL, 
            0x29B276DF69DB5B74ULL, 0x69109E5B8647015FULL, 0xA7E70B443EE18FB6ULL, 0x7A544F87DE48C5C5ULL
        },
        {
            0x2C4752B9C141E49EULL, 0xA6CA10862FFBA342ULL, 0x3EAECEA8B4B7FD9FULL, 0x1BA6827B5823FAC6ULL, 
            0x03B889AAF797EC74ULL, 0xB2FE2F9656FD13E0ULL, 0xDB08C878077199D9ULL, 0x3A88C74FE7E99A4DULL, 
            0x1D6900B59FB6340DULL, 0xE6B602B007256D11ULL, 0x8A619ACAC94278D2ULL, 0x99C419CAB8FFFCE7ULL, 
            0xCE552B683EAA1866ULL, 0x359D50DD9A333236ULL, 0x363A922543C10456ULL, 0xFF8D7305A826E8E6ULL, 
            0xF23685B89E2B6FF5ULL, 0xDB39CD6C473445B5ULL, 0x15A1A2AF8B63597AULL, 0x807C9958048DA7B7ULL, 
            0x3D9B15D80F91414DULL, 0xC43336A280349993ULL, 0x7D6271D87A1180D9ULL, 0xB09317AF81A0A173ULL, 
            0x2A2D93F272A3CD48ULL, 0xE1B5E06139FEF47BULL, 0x54C08C88BBF246F7ULL, 0x1CF9AA4E22B45D07ULL, 
            0x177EE739C7EDF18AULL, 0xF2F9DFA2182E3770ULL, 0x6C1D9A5D1105CEB9ULL, 0xFA3BE4D6BBB2FD9CULL
        },
        {
            0x445175B6EB5895EEULL, 0x490B12AB5FFF5B71ULL, 0xDDC66443A4D59706ULL, 0x2581F011DBF982D1ULL, 
            0xB420B26B88EABCB3ULL, 0x9BDA399851F5DA77ULL, 0xB1D65AEB9E61810EULL, 0x6B182961AC030FE0ULL, 
            0xC1B4343DACFFA6D4ULL, 0x21B2EFE0807D25CCULL, 0xED567E8BF04DC4B9ULL, 0xC7D2A45C5957ADD8ULL, 
            0x13D9016404EE4911ULL, 0x8F6652588C175CABULL, 0x034D10BD8B5843A5ULL, 0xFB8F28943801F510ULL, 
            0xCF50389FF672147FULL, 0x713AE731F53EAA80ULL, 0xC72C9D1AEAB00B4FULL, 0xEC3B4CCCB2ED3CC1ULL, 
            0x6194C92FD8F9B615ULL, 0x1993560F5E49BEC1ULL, 0x762D7B7A2D3B785CULL, 0x1D5FEED13C81FC3CULL, 
            0x3A4BC740CCBFC298ULL, 0x1EE8F9C286212712ULL, 0xAC41E86E52169494ULL, 0xE05A663458B7BE8FULL, 
            0xC8C885CD3ED79C88ULL, 0x96D775CF9917E08CULL, 0x18A02E36CF08A558ULL, 0xFD119B7E6D1E4F9FULL
        },
        {
            0xD251E7F14F81E405ULL, 0xC54BCB57AB29E4A0ULL, 0xAF192B6BF840A5ADULL, 0x2009A57E13F16603ULL, 
            0x0EC3C008449B8E9CULL, 0x8095FBFA4B552CABULL, 0x016A60C8E81E0DE7ULL, 0x1A9DD362C172D4DEULL, 
            0x620CDD6EBE86EE02ULL, 0x78A729DF19AAA994ULL, 0xAFA2AFE4C0CE7CDAULL, 0xE20AEECB5A61A56FULL, 
            0x453FF59C54B749A6ULL, 0x7A022933CCF35D46ULL, 0x896F5ADACC26AB31ULL, 0x682D299C5A37C350ULL, 
            0xC8A29F27E1D96269ULL, 0xD468FEF5FB3618CFULL, 0x147E59D9252A140DULL, 0xF2E8CBBE9D07BE0EULL, 
            0xE3A8C801026018C2ULL, 0xE6A0CB0B30567FB1ULL, 0xFE4314A71705B89AULL, 0x91EE428CEC240535ULL, 
            0x325AE50888CCB222ULL, 0xC7C24B728E67CA20ULL, 0x11FB5528ACA287DBULL, 0x74A76D87AA8ED3FBULL, 
            0x5A757835844A5833ULL, 0x674CBC2E6386B896ULL, 0x7EE1B5038E8E5A6FULL, 0xB32C247997B80275ULL
        },
        {
            0xABD1C95B11B0EA9CULL, 0x57035ADF9B42F9F0ULL, 0x9DAD3E42A6F59831ULL, 0xC7153B7692292813ULL, 
            0x88AEDCD01ED0D329ULL, 0x5680CA1509CD3CDFULL, 0x9A7C378C22112FBBULL, 0xEA1849A9B9F5013BULL, 
            0x30BA4D350810EC55ULL, 0xF9729794C4C42F98ULL, 0xF0689AFBE2FACA98ULL, 0x08B2A0E4B2BFE7CDULL, 
            0xD34791EF1E47889AULL, 0xA0494EE97706A71FULL, 0xDB108FFF7E0BA8EEULL, 0x42FA4B6259827153ULL, 
            0xEE95CB81C02BA6ACULL, 0x4EE4967C36BA3A5FULL, 0x4A8BC6021A10B2EEULL, 0xD1C8684B8AFE4046ULL, 
            0xD1B572479421E03FULL, 0x086D125F3BBAA245ULL, 0xAB3666C93AB6D4FEULL, 0xE4C2F5F77C1D519AULL, 
            0x735B673EB6302F3EULL, 0x688F2818874DA315ULL, 0xDE972A6156AE6F39ULL, 0x97C595B67F94B547ULL, 
            0xE57ED1A15DCA1607ULL, 0xF66795417F17BD11ULL, 0x130D4063C1708259ULL, 0x1931DD3946BAA19CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseEConstants = {
    0x1DEBFA88B5A5844DULL,
    0xF897CA263A7B7C70ULL,
    0x193AE5B13915257EULL,
    0x1DEBFA88B5A5844DULL,
    0xF897CA263A7B7C70ULL,
    0x193AE5B13915257EULL,
    0x3CCCD00AA3B9AF2EULL,
    0x6F5DA181D0EE1124ULL,
    0x2B,
    0xAE,
    0xF0,
    0x10,
    0x1F,
    0x7D,
    0x16,
    0x3D
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseFSalts = {
    {
        {
            0x5700D7A23469D835ULL, 0x0F996EEFCAE14E66ULL, 0xF05086E155AC5746ULL, 0xB63E02249C89744BULL, 
            0xD6D103DB25B953C0ULL, 0xEA2F2D9CADA58A2FULL, 0x7633FAA382BE6C37ULL, 0xA7D3822B4BA62FBCULL, 
            0x9AB9CAE9DF88E2D2ULL, 0xC5C978AC3DF40ECBULL, 0x0FB8DDFF38514E00ULL, 0x8BA2259EBE1E56F7ULL, 
            0xF8557DC441C05E5CULL, 0x207B4120CEB331CCULL, 0x649B38F8BAC64C53ULL, 0xCF2F19FD837A5ED8ULL, 
            0x58FD3FD7AFDD29B6ULL, 0xC063F76FE93C3FBBULL, 0xDA42B47E59FD2DFCULL, 0xBCE8C9633BD210D5ULL, 
            0xD73DFADC5425DAD9ULL, 0xC45531FD5C96FE5FULL, 0x684CCDAEEA6ACF51ULL, 0x83297615EECA70A5ULL, 
            0x02BE0FF98DAFEC2CULL, 0x3EAD134814BF86CFULL, 0xD1D3FC6E11116325ULL, 0x27F16761050075EEULL, 
            0x1CE2EFF5C5818B3AULL, 0xA5B1A7FF9F7D60D1ULL, 0x469918CDD49BEE59ULL, 0x5F63BAA89EA304C0ULL
        },
        {
            0x56ACB6B6E8A4D585ULL, 0xDDF2D4252C29E3F6ULL, 0xCC0D179AEAAB17D1ULL, 0xE887B1864142AED4ULL, 
            0xD86F700412615ED1ULL, 0x3C5656071BC91F76ULL, 0x96AF8E86E2AA26AEULL, 0x5A3C298D5E21ADC7ULL, 
            0xB327E5E4570EBFEDULL, 0x885AD90D5771C678ULL, 0xE649CCEA434772D2ULL, 0x3DC70BD34BA44A66ULL, 
            0xA691ADBBC0770AABULL, 0x6FFFA45C520E7A57ULL, 0x79B6E04EE6063ED3ULL, 0x7D7D347F8F6D9656ULL, 
            0x655B9071B6F743B7ULL, 0x7B3E3CA94A9C1191ULL, 0x4359BA1C4FA085DCULL, 0xC123525D99BBE84CULL, 
            0xB1AEDDCF9D966964ULL, 0x0950C82F81E5814FULL, 0x0824B44AA05D6A19ULL, 0xF19F7DB87C7D0C80ULL, 
            0x73A1EAC905463F33ULL, 0xA5ACD395E28B2D5AULL, 0x50E09E6FC2780E92ULL, 0xDCADC696E6D829CEULL, 
            0x629B36F558160C5BULL, 0x3F4C56E27E9D201DULL, 0xA6CBF4C88259962BULL, 0x2D3C9BE57332923CULL
        },
        {
            0x4E402810786805ADULL, 0x7E7AEC5EE17DC3A6ULL, 0x49B49E4FD155B2CAULL, 0x3139EC989D20E004ULL, 
            0xFFA9EB44C30AC683ULL, 0x7131D9C820A6B95DULL, 0xC4DB8BC798D815BAULL, 0x8D2248E78A8E5281ULL, 
            0x2EF35E7618C04A38ULL, 0x094781677C2A93A5ULL, 0x8BF3286C0560F5D0ULL, 0x32AD7CA1C3A6CEC1ULL, 
            0xF551622B1467E3E1ULL, 0x4A559ED439727275ULL, 0xBC0A6C584255EFA0ULL, 0xCD7A720156152592ULL, 
            0x547AE5A6A6402546ULL, 0xAF12C8ECFE62B858ULL, 0x3DE0141AF4C31294ULL, 0xE100FDD554E9DEA9ULL, 
            0x1C88CA21879E5BFEULL, 0x6D872DC34242C7AFULL, 0xC7350F2681B046B5ULL, 0x073AF4090CB7FCD7ULL, 
            0x923066CC2E9D3048ULL, 0x0524CD2907A07EFEULL, 0x9BA9319753F3081FULL, 0xFBA97F299998C264ULL, 
            0xDA5E0A63412034FBULL, 0xA674B677DC7A1EFAULL, 0xA7BC2BA73399FABBULL, 0x4DA67B98B0C103A2ULL
        },
        {
            0x6F613A6092B15803ULL, 0x13A0DE3CCDAD429DULL, 0x73422BAE15D98433ULL, 0x5B26BD01F6B393D1ULL, 
            0xD4692249D1EE09C9ULL, 0x69062386DB191600ULL, 0x54C87AB10B9462F4ULL, 0x56E64D1CFCEAFAE3ULL, 
            0x0049D37B43DD2819ULL, 0xE174DF3FA7E473A5ULL, 0x50C5AF27AA336C5BULL, 0x784CF5477C4D2ED1ULL, 
            0xD2E329B45D0493B2ULL, 0xCD32F6D322FBC037ULL, 0x16DC858901F9A781ULL, 0x62EA5441387B077AULL, 
            0x6039F2A5423C2EEAULL, 0xC00BC2EFDF7D1431ULL, 0x0C3F25D49348C7D8ULL, 0xFC0C41E72C08E6B8ULL, 
            0x89E714D3B082D813ULL, 0x9DC7EEE371C4A6F0ULL, 0x11366ACFE40901EFULL, 0x4446A7555A03BC48ULL, 
            0xECDB47BAD4A6FD87ULL, 0x561475551CB9FFB2ULL, 0xD87EBF9E518238D0ULL, 0x5E43A6113032DE56ULL, 
            0x6D3C542AECD6F53CULL, 0x785E07A3CCF4F3C1ULL, 0xA37FFC6540C6B148ULL, 0xC96E5D2BD422A5FDULL
        },
        {
            0x48842575EB58F587ULL, 0x4C391D6BC67D4D01ULL, 0x28BED1DCD678280AULL, 0xC782F6E9F29F3EEDULL, 
            0x46DDA837E7F41C0FULL, 0xE41535016597C8B8ULL, 0x3CB05D5D9C92CF30ULL, 0x87D3223F37BD9F97ULL, 
            0x7C1E846C592541DEULL, 0x25411E91EA24A120ULL, 0xDCB2587CB74FD15AULL, 0x4783B978C6CD0BD4ULL, 
            0x65C2939B5532D348ULL, 0xCC0F4BA3FB5D2D40ULL, 0x5104E86B065EDDC7ULL, 0xDB686C16743C8D22ULL, 
            0xBB71253170DB63D9ULL, 0xC9BE19D365CC0AD2ULL, 0x203A09725EBBFB51ULL, 0xE448B7F8F890B381ULL, 
            0xA5FDF1C84CF647B8ULL, 0x0A91F8653C2962FCULL, 0x25BA3CD59FF97025ULL, 0x9DA507B8FF836E66ULL, 
            0xFC5629DC373B09C0ULL, 0xF48ECA3E2033CBE5ULL, 0x18C1184E5B83736DULL, 0xCBDD19FF917D9630ULL, 
            0x269FAEFE14527498ULL, 0x864779A5E2EF2E75ULL, 0xCE5122F6781C062EULL, 0x0CEE5FB4113FE9CCULL
        },
        {
            0xA9B518988B8F1B9FULL, 0x43A558669248A830ULL, 0x02BA69CE6427C244ULL, 0xC81ECC8B0173C74BULL, 
            0xBD7703574C7EF957ULL, 0x88F9590F295D1F96ULL, 0x9C9E355FC5CCA0C3ULL, 0xFD390B7FA3F4A41DULL, 
            0x24B17989A0D2C200ULL, 0x79A0A63613CAA69EULL, 0xDF51C3C46031EC0FULL, 0xC7137FFB38129A6FULL, 
            0xF440160EA145E92EULL, 0x3AD880516755DCD6ULL, 0x941BA51F5C374E48ULL, 0x9DD65AFA1B9AAE14ULL, 
            0xF763CBD95722FBE0ULL, 0x4631A4CC40C225FFULL, 0x2B4CBB422685801DULL, 0x856AEB2C7B7E2110ULL, 
            0x60CE0B2001C1B341ULL, 0xD1FBC588DCE4B2CDULL, 0x3227185F1A854AAFULL, 0x517237CFCF388932ULL, 
            0x07F458389027DFB0ULL, 0x552D161C202502D2ULL, 0xD1E8DC2839EEC92AULL, 0x9DCD03394267B003ULL, 
            0xCEF649200D45CCF8ULL, 0x65A1F592442179DCULL, 0x0C8CD84C600CAB82ULL, 0x83D0FD4B98998625ULL
        }
    },
    {
        {
            0x7A92369DEB947A66ULL, 0x104C510D99ABF926ULL, 0xBC794A239465D3BDULL, 0x171795819D40927AULL, 
            0x4D39B9C3D2F88099ULL, 0xE048123BC5BDD4B9ULL, 0x61330684E0809EA2ULL, 0x72D243BE2ED26ACBULL, 
            0x2636DCF28752A98DULL, 0x8BAD94177C2B7FA3ULL, 0x6342171D7903C18DULL, 0x1C22317F00875D41ULL, 
            0xC84F0E6BC668D624ULL, 0x262731E6E81C1712ULL, 0x5125BD66836CF750ULL, 0x13BBF2E713181594ULL, 
            0x1A36627D32A13958ULL, 0x9C78708F62148CDDULL, 0x33125702D151A3FCULL, 0xE75AB4DFB83FD68EULL, 
            0x2E6F4C53EBDC719DULL, 0x83BAEB71A1E705B7ULL, 0x968A112136DC333CULL, 0xC845CEAD73E23DAEULL, 
            0x4395169A28D8E2BCULL, 0xE39FCDD656F5A70FULL, 0x6F03CDB905620854ULL, 0x1A52CF7611CF78F0ULL, 
            0x9ABA6B5D6DFADEFFULL, 0xDC4944118FC6FC12ULL, 0xEB4249D8081EF294ULL, 0xC515B5D2E8A90935ULL
        },
        {
            0xA6704684642D4BA4ULL, 0xB7F3249CE315BB59ULL, 0x687DD3226301DC7CULL, 0x213DD15E520F86B6ULL, 
            0x262F742ED341BEA8ULL, 0x48E6809A8CBDFAE8ULL, 0x59C3B58608EBE030ULL, 0xB76DBB3367A97791ULL, 
            0xE1F63095E979EC02ULL, 0xDC6EA5D02B786AB8ULL, 0x862012C790BE8699ULL, 0x4450A82E40417DFBULL, 
            0xFD8B9A1F1E5AA606ULL, 0x8F345BAED02C6086ULL, 0x660AE6ADF301246DULL, 0x336A4497D7BAE5BEULL, 
            0x35C5893071EB746FULL, 0x7F31A37E75381200ULL, 0xD74C7E8FB1BFB481ULL, 0xD3B60D400791C79AULL, 
            0x700ECC03F5296357ULL, 0xD603F002BBBE2D3CULL, 0xC15CAA243B763EF7ULL, 0x5D17F71253D07DC6ULL, 
            0x9F40BC3B0D7EBE3BULL, 0xF448AAD4558A3D9FULL, 0x97A41126F21D27AAULL, 0x8F423ACEB5AE78FCULL, 
            0x30E807BB5CAA2345ULL, 0x9AF0117C6897A984ULL, 0x42DA7B5F39D24ED4ULL, 0x47ADEFF2AABE3694ULL
        },
        {
            0x6A37AD3B11844F07ULL, 0x5E978BCB0DED03C5ULL, 0xFA7659D4EAC1DADCULL, 0x5E172832C2E5B242ULL, 
            0x3A761C71F9F5EACDULL, 0x420E39CCDABE9877ULL, 0x1C156AEB93B1CBB8ULL, 0x1A77106AC108DD57ULL, 
            0xDF6A1D90B8D4EE14ULL, 0x62144D773ACB05EFULL, 0xF61ECBFC300470CBULL, 0x5F8CDE62299F9516ULL, 
            0x68A65232622F8849ULL, 0x3F68AF7C4BCBE5FDULL, 0x46BE15A34DBAA992ULL, 0x1263D0EBD6E3C263ULL, 
            0x2657657A3C333CF0ULL, 0xB835D0ABA46DEE71ULL, 0x3E1C4AD186C615FAULL, 0xAF47D895E7C794C7ULL, 
            0xC8544717622BDD8AULL, 0xD6188EDE97130BBAULL, 0x79BB2888A607291AULL, 0x13976419A3E44921ULL, 
            0x8A5512DC3246B975ULL, 0x5E4C3D627F2C5F91ULL, 0xEFA9D07DEE7BB1E1ULL, 0x5ACF790CBCA08871ULL, 
            0x9BE99C0326901D67ULL, 0x46B781AF2DF2F2A3ULL, 0xCE4FA4C4F08C9DD8ULL, 0xE35C0D48F434D9D4ULL
        },
        {
            0x90B83B1D2D9C37EEULL, 0x1DD9FF4B8AB5B2E4ULL, 0x0ED18FA8BE98F28FULL, 0x2A3520A757AF964DULL, 
            0xFE2E4D23FD38D52DULL, 0xC8D008C0D51ECD71ULL, 0x851D0068760CEB26ULL, 0x1F8344A946123B92ULL, 
            0x64C910E331337DDFULL, 0x3039383B51AC9213ULL, 0xA2E90386C92CA0F8ULL, 0xB87213B0A4C51867ULL, 
            0x72D45F6C42458367ULL, 0xBD409BDE1603E7D8ULL, 0xB8A99B9505F0D4A0ULL, 0x08E4738658397569ULL, 
            0x65E96405DFDA098FULL, 0xBDD3EAE09963FEA3ULL, 0x697A3D2CFDA13B3AULL, 0x87F4A5E063D7BC53ULL, 
            0xA05CD9C9574743E3ULL, 0x61B46162DA25986DULL, 0x305CC94224E78733ULL, 0x28924BB1E51E54B8ULL, 
            0xC80AD142B8B2E5F5ULL, 0xA42CF4C91B46220AULL, 0x9CEE135353C15434ULL, 0x56DCDA5E33EFFF65ULL, 
            0xCEA4F9CBA59EBE20ULL, 0xA06164C9A2C30BEBULL, 0xD07F3D26334457C4ULL, 0x2954828E2D22CB36ULL
        },
        {
            0xA4B795939C55C59BULL, 0xFEF0B9AEE82D4689ULL, 0xD5CA09D9B77B1444ULL, 0x1E51DF24868EF2B5ULL, 
            0xABA3695FF80F6942ULL, 0xF05A2A117021E88AULL, 0xB80F0E5BEC8BAC0DULL, 0xDC94C98DAD4F8C7CULL, 
            0x5EDFAA1EB5C50709ULL, 0x5C5E8ECFD9C6A690ULL, 0x2E28240F6CA167F0ULL, 0x3EE1AE9505335292ULL, 
            0xD2A62873F1010ADAULL, 0xCE70E281BB942D36ULL, 0x95B194C839F52841ULL, 0x7A519BB2BAD713F6ULL, 
            0x0101D3DDFC455FECULL, 0x6441C87BEC575EE1ULL, 0x95612EDE320FC935ULL, 0x89F91917C94019E7ULL, 
            0x57AAF5764760095EULL, 0x27127E7F82FB6674ULL, 0xB11D7CF0DB277374ULL, 0xD0BF60888CCE5A8AULL, 
            0xB8FCA4DB6D404C2AULL, 0x5B3C689DCA7760FAULL, 0xF578BE29AB3FD697ULL, 0xB719CDF38FB20159ULL, 
            0xCC7776383EF2EE58ULL, 0x7B2AFEB6844D9652ULL, 0xED6D7E1290DDAA6FULL, 0x9B93688B05DD19AFULL
        },
        {
            0x804BA8928144FB3EULL, 0xA486B5F7C16C3CC3ULL, 0xE7029888AC101F58ULL, 0x6A9FFB318F084110ULL, 
            0xBE94198FC75E3D89ULL, 0x5103EC659B2DE1C4ULL, 0x29F971C43BE8EAFBULL, 0xD3D545CEDD29EDD8ULL, 
            0x4F3319FD6150D466ULL, 0xB05585991AC552CDULL, 0xD6C5F434348F288CULL, 0xE92DBEEC8C7A656BULL, 
            0xE5345E60BF609734ULL, 0xC6C2E179EF967704ULL, 0xAB15FD4365C6984FULL, 0xD285C0BEB6562487ULL, 
            0x9DCE57DE7D10432AULL, 0x8E0F58452DDC5807ULL, 0x4BC04927E8A8CEEBULL, 0xB0CC4EB787959A57ULL, 
            0x3F0D72FD48276159ULL, 0x85C287537988AD06ULL, 0x1EBC70D7F46C701CULL, 0xAB3BD9995B2F1E36ULL, 
            0x3EBB6911A87F8234ULL, 0x181DAD0865C7B837ULL, 0xDAD8ADC8EA9E297EULL, 0x011D3FD83C5547D3ULL, 
            0x9379111BAB4D384FULL, 0xD92488457C654849ULL, 0x2C3CF9F3124C4358ULL, 0xAA489F2DC1A9B480ULL
        }
    },
    {
        {
            0xC86C7FE77173D057ULL, 0x004B8EEB2D4A2B08ULL, 0xAEA3061D947BEB3AULL, 0xC616801EDFD817E7ULL, 
            0x0D70858ACAFA911CULL, 0x76008598B733A7E6ULL, 0xC26A412A7D9F949BULL, 0xB730DE5B5540D057ULL, 
            0x98BE53F0B2327574ULL, 0x4D0F686F3DFF68FBULL, 0xFD87CBBE62875A8DULL, 0x51EE823D66EE6C6DULL, 
            0x0322482CE2A102C3ULL, 0x0FDC0E0A9ED6E9CAULL, 0x4DFE868627B01906ULL, 0x17EC8F5F93DBB771ULL, 
            0x9CB5D52466D62F47ULL, 0x3A945F95C36BB574ULL, 0xD782725F1793CFCFULL, 0x5FD57B1852DEE015ULL, 
            0x63AA46633A3336BEULL, 0x3E4558324F296747ULL, 0x169D9AB3277FCF98ULL, 0xC7C4801D9480A2B5ULL, 
            0x8C5D05947D2814C8ULL, 0x60970BD1B34104EFULL, 0xDC87BD2DA8811C9AULL, 0x19011B806C667085ULL, 
            0xAB799523C82A0155ULL, 0xFD1195690D9FAD48ULL, 0x458FA6C7300CB19AULL, 0x26758B45737B1902ULL
        },
        {
            0x353BBE9A870C8426ULL, 0x740DA4F433D19A94ULL, 0x92C4AA14955A74CFULL, 0xD523589267EA070FULL, 
            0x0F7D3D892CFC857CULL, 0xC1B21A7C16B265E8ULL, 0x0D36498653C98B21ULL, 0x2FDE64613D4DE045ULL, 
            0x60046E8CFECCB612ULL, 0x595F894B7F86596AULL, 0x165B84250181A27AULL, 0x4713E58FF5769C85ULL, 
            0x03B65B362ED457E0ULL, 0x1DBFD80C94D9D3CAULL, 0x2A2ABA940F034A58ULL, 0x0C74C9D78105DF1AULL, 
            0x90D951228BEF80BCULL, 0x74C1DCA391AD191EULL, 0x55DADC28956468C7ULL, 0x975FC508C6C870F6ULL, 
            0x96226A74B09C012EULL, 0xCEDB84671CD21560ULL, 0xC226162EE02E61BCULL, 0xE777C085C2439E12ULL, 
            0xFB888D133AD2D198ULL, 0x017AED0EED14F7D7ULL, 0x4843A67DCC847C7FULL, 0x269196E1F68EC910ULL, 
            0x07619A3D4E80C764ULL, 0xB24A42F1D1DD1700ULL, 0xB9C3401CF2556685ULL, 0x3544A131A0128539ULL
        },
        {
            0xE2D16A39CA4F44ADULL, 0xED60B1E504FAD549ULL, 0x965F581A0FB21F13ULL, 0x0B1B15E03E1A3B00ULL, 
            0xBBFDAFC56CEDA654ULL, 0xB76D79713C272F50ULL, 0xCA363F80EC441476ULL, 0x62EE9871FA8DC556ULL, 
            0x79FD8000F1675957ULL, 0xFE157EE586C322F3ULL, 0x1F5EE141EC2B6967ULL, 0x6B3A5A3381FEEB59ULL, 
            0x297AD722FF4B2053ULL, 0x8A498F45EC7C7B04ULL, 0xFFF56F16C347D984ULL, 0xD099577A4B66958DULL, 
            0xCE647459782E0D8EULL, 0x7E1C006CDE6C9A34ULL, 0xF55B62508281B680ULL, 0x4E2BBA33F7540963ULL, 
            0x044A9F5CC184DCCCULL, 0xA8B16271981DF1FBULL, 0xC3E15F6FEFD900E5ULL, 0x29A64815B15F116BULL, 
            0x72039C353DF2C74FULL, 0xBD3678C9A130AAB6ULL, 0xF456B534B94F5BDAULL, 0xFC8B805AEA4C27BCULL, 
            0xF0B89831E414506AULL, 0xCF93C39BB8075CEAULL, 0x163166EF3D320317ULL, 0x14CC3C412CDE790CULL
        },
        {
            0x0FDD3B085274DDD7ULL, 0x10625F309F6C6D0AULL, 0xCB01DA43C4E9D1E0ULL, 0x02B62D4E1194B3A6ULL, 
            0xD19A7D6532C2A451ULL, 0x0074377FD4E0A515ULL, 0x1EA2983FC8D82EC9ULL, 0x06830D66BB3615D4ULL, 
            0x24F72376681C13FAULL, 0xC93295864D20004FULL, 0xA31EA657574EF08DULL, 0xEF7BBED8A0C66F01ULL, 
            0x75CE87004354E135ULL, 0x735A777201B721ECULL, 0xDBBAC6B3ABB7828AULL, 0x9F5801412A02736CULL, 
            0x671DBDAC323520ADULL, 0x7AEFF1A601744B87ULL, 0x2C300CF5C6178127ULL, 0x1101270DB9E737A7ULL, 
            0x2C9A1130F5D9E024ULL, 0x3B93C15EBC1AC8AFULL, 0x8FF17B07D374ADCDULL, 0x6DB5CA93EFB0C685ULL, 
            0x380E0CC081CC99BAULL, 0x5EA9811FA7A59034ULL, 0x1FA86451297A288AULL, 0x2E8531B60A0252DFULL, 
            0x3F383D2A873B226EULL, 0x0CE7FE6D24F05561ULL, 0x1FE34402854A8D2AULL, 0x34402ED558AFAECCULL
        },
        {
            0xE1909E0632C8F3E8ULL, 0xEBEBC469380F5C3FULL, 0x5053CB2285A1F0B2ULL, 0xA393AE6FB0FB6903ULL, 
            0xF63C748D4E81FD43ULL, 0x01FC91147744C248ULL, 0xCA5659A2A843C666ULL, 0x114AEDA46DE47106ULL, 
            0x33CEDBF6C8B8DC3FULL, 0x7A0BC967BE6AEB15ULL, 0x057E555E24E03EBEULL, 0xC7ECC8A0A5B40B40ULL, 
            0x4F859108F2837366ULL, 0xDFB5A19B5E2B4635ULL, 0x3B95DA3C0578B011ULL, 0xE86321E15B60B2E7ULL, 
            0xD064083C6567DCC7ULL, 0x717711D155BF09BFULL, 0xED2C82F8476F6062ULL, 0xF2DB00484D3E21F3ULL, 
            0xCF836697D103A443ULL, 0x066D3B094203A8B0ULL, 0x9C542052674CF6C5ULL, 0xC176C99E7E8F56C9ULL, 
            0xD362EE367932AB53ULL, 0xC68B98999FCF357EULL, 0x6734506C1AF0985BULL, 0x22AD8B72A58074A4ULL, 
            0x78525EA980285F57ULL, 0x8F865C50CDA25205ULL, 0xCDDD24850FC74C1AULL, 0x6A5CD833DA703E9AULL
        },
        {
            0x027A188E8D6F6545ULL, 0xFF6E62D88BB9713BULL, 0x5356E38ECBA3A0F8ULL, 0x7152CE1481BF65E9ULL, 
            0xF23CCEA9C9DC53E0ULL, 0x251E15A604DC99B4ULL, 0x0901D2A7558806D2ULL, 0x45D8220B44958DA2ULL, 
            0x5E44F595FA4037E6ULL, 0x4E6EF38F24396784ULL, 0x0DCEF5A6A44A1704ULL, 0x7E856A5C8D00750AULL, 
            0x1EAA13B0ED01A2F4ULL, 0x7DFC1B3F035DFBC1ULL, 0xED47782BF8645D7BULL, 0xE5B37B04C87F7C8CULL, 
            0x98934E20AE476884ULL, 0xF9916C68673641E7ULL, 0x17B82EA702C15EB3ULL, 0x7F9638CB966D47F1ULL, 
            0x5EB907C458E987BEULL, 0x1E24A1FC974E0ED4ULL, 0x7126F5D29C4B3621ULL, 0x232FD05AD041CDD5ULL, 
            0x0BFBC8CB68592242ULL, 0x721E14E4A1471697ULL, 0x03DA514C247904DFULL, 0x273DEFD4D38DA7A2ULL, 
            0x002B60053053AF06ULL, 0x652B12111469B8A3ULL, 0xB753CF0AED523859ULL, 0x0F167F9343AC1D42ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseFConstants = {
    0x8492A554720A88DDULL,
    0x8CF3656E66BCDEF7ULL,
    0xA6F2CC8D08DBB9DDULL,
    0x8492A554720A88DDULL,
    0x8CF3656E66BCDEF7ULL,
    0xA6F2CC8D08DBB9DDULL,
    0x2745313B788B52A5ULL,
    0xA42555CEDD10008EULL,
    0x20,
    0x5E,
    0x15,
    0xB7,
    0x4A,
    0x87,
    0x88,
    0xC5
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseGSalts = {
    {
        {
            0x5827A028B984BC93ULL, 0x0DE656D913A0D0BBULL, 0xECC63B9659B868DFULL, 0x39F55F5823D75370ULL, 
            0x365B003286655B23ULL, 0x54395684D8A72BFBULL, 0x2C19BC6CEB2B7C60ULL, 0xC37E16F9DB4C113DULL, 
            0x284B2D0A644B0307ULL, 0xE3C23D14A040BDC9ULL, 0x5DAE55D163C57ECCULL, 0x9ABEC2146C8C5971ULL, 
            0x93753E6C3999A800ULL, 0x3CDC8420B9286372ULL, 0xF62FFF04E2B7E072ULL, 0x28875C73955F4A3AULL, 
            0x656BDF50800F9292ULL, 0x6D6936E10F6E6DB9ULL, 0x8C79F6B01A329886ULL, 0xF32065164E1B64BEULL, 
            0x575A81AA8CEC1CACULL, 0xC6B410706EB534DDULL, 0x72595DF093EA6312ULL, 0x0D432378ECFABC1BULL, 
            0x29A4B432421902A7ULL, 0x9AB9C6501918FA72ULL, 0x9B6DAE8896256615ULL, 0x6560D3CB5C5D0331ULL, 
            0x8C293B824B2B1343ULL, 0x8F4A6CE0AD70D02FULL, 0x516D6AFFA8C046C1ULL, 0xD0EF72EEEB527BCEULL
        },
        {
            0xA5CDC30568AA4910ULL, 0x3AA9B686B67101DDULL, 0xE48D06789C0A8CE3ULL, 0xFF6CCE98F5EB1D39ULL, 
            0x9325685A705C48B7ULL, 0x97E8747DA885ECABULL, 0xA91787945D49DA64ULL, 0xE15B2A2BECA6246FULL, 
            0xE1C218C4D00ECE3BULL, 0xED2A7BEBFBAF4102ULL, 0x6512A1C6E172E253ULL, 0xC65746BD937F432AULL, 
            0xE67827BD5C44657CULL, 0xA543788F4CBFEC20ULL, 0xF1867FB90CA1D906ULL, 0x1666A334594C7C3AULL, 
            0x32A6FB852F082B79ULL, 0x0EA836249F088AF9ULL, 0xA5F18DF7FA4BA1E1ULL, 0x6B19A70848CBA913ULL, 
            0x69E83ECC6FC3D790ULL, 0xD459E5B86B245B0BULL, 0xAF888D61F375FB1AULL, 0xF0CFE94F121F86C3ULL, 
            0xFBCC16D86E24D7A1ULL, 0xAFC055F71409385CULL, 0xB81CFCA91D6DB17EULL, 0xDB9EF4B737F61691ULL, 
            0x3AE2FEB06911CB9CULL, 0x5196AA6B3FE0BA0EULL, 0x909BF8135D62A6ECULL, 0x4CE18770BD448146ULL
        },
        {
            0x38D006AEA18D8C0BULL, 0x5DE008789686DCC8ULL, 0xA62DBADDCCDF033EULL, 0xAD315BDFB14F0502ULL, 
            0x5EBE25463FC555FEULL, 0xE66AF7A4B8805536ULL, 0xB091362F09BA2FFBULL, 0x7DAA0CA5BBE030A5ULL, 
            0xF9ECFA1CA8EF699BULL, 0xEF0B5543210A4CD0ULL, 0x0093AAFFDA31BA94ULL, 0xB5580358CCD4515BULL, 
            0xE36BDB0D378248B9ULL, 0x1DF74C227A0C1299ULL, 0xDB818E4814144EA5ULL, 0x5B427FC5664926CBULL, 
            0xCDB32075F9CFE8B9ULL, 0x40BD86FB02E6B99DULL, 0x0F38068D0E3347ECULL, 0xFDDF56D27A8A75AFULL, 
            0xF8C21D820D23F0FEULL, 0x54883743B1D5D477ULL, 0xDA430940CFA404D0ULL, 0x48F95676B3592A33ULL, 
            0x4E7E308CF7389680ULL, 0x3BDA2B1448E9F991ULL, 0x0A6B254A95488B3AULL, 0xD4F48CB2E7C497C4ULL, 
            0x75A2583648A87D4AULL, 0xA3168D5E18E40F5FULL, 0x05E261F32B3A309CULL, 0x9BBEBAB08E7D06FDULL
        },
        {
            0x50229D6BA048323CULL, 0xD70DF87E171EC252ULL, 0x9DCE02BDD00EE8B8ULL, 0x84EB8976E68B0679ULL, 
            0x9D82E61B23CE3CAEULL, 0xED707C36C80B672EULL, 0x272942D6620C029DULL, 0x00775BED83E16F7EULL, 
            0x645E9065B4DFDB7AULL, 0x7FF1727F80FC17A6ULL, 0xE182DB071790E606ULL, 0x810229B3B97EB9C2ULL, 
            0x23C6EDCF19A46FA5ULL, 0x8DA2B7210C61138DULL, 0x515DFF768CBFE8E0ULL, 0x29E9B9E3233CC562ULL, 
            0xA0E95B9A2231DB7AULL, 0x9B2306493325DCCCULL, 0x0836CE8737180898ULL, 0xF695E7C202382A29ULL, 
            0x7DA83CF92E34A67DULL, 0xAC44205A806CC195ULL, 0x175B7793AF3AC753ULL, 0xAB887B48B5F0CFB1ULL, 
            0x3D72EDACC50421CAULL, 0x4EB0264485309CC7ULL, 0xE0963E860BB95916ULL, 0xB5CDA1C2349F4A06ULL, 
            0xE7023353D327B2E4ULL, 0xFC3A3E41D8593EE5ULL, 0xCF167C6E04E3A36CULL, 0xAF9FDD000AD5A610ULL
        },
        {
            0x9C5C24A28F37A2ADULL, 0x1FB284761705AC7BULL, 0x4C886020E0D56D1AULL, 0x751A6D06303E6486ULL, 
            0x507F5FB62588131DULL, 0x91ACA0A4DCE69EA5ULL, 0xAC831DC5438F69BBULL, 0xA87CFFA32031942DULL, 
            0x11040A268ED8E99FULL, 0x73F7136553BF65ADULL, 0x15C0ED5FFAF29B93ULL, 0xE92ADA94F87FE192ULL, 
            0x06B93561376A9D18ULL, 0x05A39A7EBCE7C848ULL, 0xE2E28F9D50CEA245ULL, 0xD849B2B4B9A9A31AULL, 
            0xB384598DC5EE6F1BULL, 0xA93F78636CD8F11EULL, 0x8E8DA48C5349AD94ULL, 0xFF2D2B0E2E307EC4ULL, 
            0xFD8B7D243897ABF1ULL, 0x497C52E1E7BE2C4DULL, 0x710121F9604D37C4ULL, 0xDD390C8AF440404AULL, 
            0x1C9B0E7A38FA139EULL, 0x2113189F679E5D78ULL, 0xD4D3CAB7015556C1ULL, 0xC284785C425C55E5ULL, 
            0x52EAC1396BE5C022ULL, 0x8EB748C3BA1BED45ULL, 0xBEDA66640203532CULL, 0xBC3B7B91CDDD9CA9ULL
        },
        {
            0xBE88AD9A688B18F6ULL, 0xF9746AB81D4A4CA5ULL, 0x20C6C5D756DA6953ULL, 0x9B584E586A7827D7ULL, 
            0x61561A4C59182E74ULL, 0x3106A936EF06BAC2ULL, 0x867FF49AEB03413CULL, 0xC88951D75FFD42F1ULL, 
            0x42C8C7167B5408BEULL, 0xF25620D9BC4ABB71ULL, 0xC71FD3FAB9806B56ULL, 0x7754E5B547685746ULL, 
            0xA43A4997AEE3EF17ULL, 0xE70884A81D2386E6ULL, 0x07AD784C0DE536E6ULL, 0x6BD11F28263243BFULL, 
            0x9BBB720849669222ULL, 0x767EBE5261C54DF7ULL, 0x7C568BD18A9DBAB9ULL, 0x4B1BA0AE79BE845BULL, 
            0x1EACF8079A081DFDULL, 0xFE9CDF6D725A950EULL, 0x60141EEEC9FEB605ULL, 0x4EE685820345945BULL, 
            0xCEE5A8485930334BULL, 0xDA0A837A295072D3ULL, 0xB645CA459B8D1BAEULL, 0x2AC7EC28C0D4E027ULL, 
            0xE0DAE9FE3A99623AULL, 0xA14D0DDAFF90F25BULL, 0x2E71421A2DB5DBC0ULL, 0x132F3246BAF5D940ULL
        }
    },
    {
        {
            0x7726E4BD44D5E93DULL, 0xD0EBCA1B7D65CC0AULL, 0xAF5C2EC6AC5FA4ACULL, 0x57E918EC88CEB831ULL, 
            0x43D4794977344B20ULL, 0xFF9BBB0141D5D0F3ULL, 0x01B73A354DD359F6ULL, 0x6EF498BAD3AF2EABULL, 
            0xB1DF070780879F10ULL, 0x108E6B1A07F85746ULL, 0x72E52D69EF7AD59CULL, 0x9F586CE97B562031ULL, 
            0xCBB322387EA6CC4AULL, 0x600A80B9EB82D22AULL, 0xE70BD90B92A7FA84ULL, 0xD93D1F1765E8BBECULL, 
            0x19242A377D6647A5ULL, 0xCC1EBFB0C0DCEFB6ULL, 0xFFE4A154D6C45AC3ULL, 0x49E9BD62F93C0F74ULL, 
            0xD1BA950D4C123B14ULL, 0x838675E9E570BE0FULL, 0x4C9781AE5B03DD68ULL, 0xD39BF4F90874962BULL, 
            0x63550FDECA592B42ULL, 0x046A03F0211A2F4AULL, 0x8768D78D6EE15258ULL, 0x012DBF0B2CF1E388ULL, 
            0x8B56462620A37A30ULL, 0x52C0CAED0FC920E7ULL, 0xC6A03B18BDD9068FULL, 0x34A58FDF4A6E450DULL
        },
        {
            0xF48B4935B21C4302ULL, 0x78AF3BF6D5019A07ULL, 0x34F2EFA08BA70543ULL, 0x1589CE973E735EFFULL, 
            0x63D3AE1B4746A0EAULL, 0xAA51C0476DD8F3B1ULL, 0x579E46670C9CA83BULL, 0x7530B16773101832ULL, 
            0x296A988526C89A12ULL, 0x4930BF2C8CEE23DDULL, 0x2208BA79F5D01E83ULL, 0x062C8A9A4C2EAD78ULL, 
            0xBA8C320A6AFB02A8ULL, 0xB033541A7A763FCEULL, 0x69FA77D2CBE975A8ULL, 0x21EBB2340181456CULL, 
            0x0CFBE2773E48730BULL, 0x579033C1E2229A14ULL, 0xC9FADFF23DBEEB9DULL, 0xF199EF122CEAD08BULL, 
            0x49A2ABD70D3DD2D0ULL, 0x35CCB22226724F2FULL, 0x8E3B7042A8FCBEA3ULL, 0x003C2B3DDE0CD3C7ULL, 
            0x1EC807047959E2FDULL, 0x05B19354F1B35683ULL, 0xC55B69AA037762E0ULL, 0x3675A2B3FEDB1815ULL, 
            0x834928D285196EC3ULL, 0x47D3DF9F38A870F8ULL, 0xCF89C0BEC24DD1A8ULL, 0x39A5AEC805AF2FBBULL
        },
        {
            0x9A5CE388B8FC6675ULL, 0xF943AB831642DE72ULL, 0x3549D4D1493F00CEULL, 0x5B085E330E3F443EULL, 
            0xD299AE94C844C499ULL, 0x34E7AA504BFAFB46ULL, 0xAFEB23A4B90E6BFFULL, 0xDF0F4637B0A55BD3ULL, 
            0x03C7BF1CF0037B7FULL, 0x725D60BB9265B55AULL, 0xA643BCAC0B44C462ULL, 0x8B1B5A64447999DBULL, 
            0x944AB34FD7519D30ULL, 0x26733C0310F3F94FULL, 0x30E68BB0C6DEB216ULL, 0xA2B1EBE5CC4B5417ULL, 
            0x9F2FA7C616FB53B9ULL, 0x202F0BCC6B679493ULL, 0x37B0B57D01213187ULL, 0x605AC0DE6AD35646ULL, 
            0x726F19AFDC93D1C0ULL, 0x961F2CE7AB8BC1B4ULL, 0x91FB8436E465E182ULL, 0xA304D674BFD4AFCEULL, 
            0xBDF21C136042077FULL, 0xE9D397EDB18D9246ULL, 0xA58F192891E5D4FCULL, 0xEBB61A13CEE88550ULL, 
            0x37F9F7E44749446BULL, 0x52E9CB41CE44CFD8ULL, 0x22EF92DD8D06C8ADULL, 0x35BFAA2E1031C696ULL
        },
        {
            0x2D96F2263A9E32FCULL, 0xA18C5894D89558E9ULL, 0x1F16B952065FBF59ULL, 0xE581588D5FB1F270ULL, 
            0x7069E27CB206C70CULL, 0xC5FA5CFD57B993A2ULL, 0x3B31ED6797D96AD2ULL, 0x1A800636AB85D231ULL, 
            0x2122EBD3531EAE17ULL, 0xC72FE88AB7A6B38EULL, 0xA2CD67C17A3C348EULL, 0x972AC869B2E69ECBULL, 
            0x3F500A6934359C79ULL, 0x7082C42B425C0673ULL, 0xDD027FDC4B14FFCCULL, 0xF5E177B85EAB6450ULL, 
            0x5D98B328C491DEBBULL, 0xD1AF7E1952716D96ULL, 0xE85B655990165D81ULL, 0x464B558A04DB22D1ULL, 
            0x9223C5E5ADE95869ULL, 0xA21C9408F2D65DE8ULL, 0x7794CBD58E786B25ULL, 0x285965B7706C7EA2ULL, 
            0xE8F20AE151C9E375ULL, 0x1CB0B0087026DE38ULL, 0x09ABD8B595A1F887ULL, 0xB4C136E020538120ULL, 
            0xC085E71D17B0394AULL, 0x7342D2A5893DD007ULL, 0x1137C8B7DDCB20B8ULL, 0x714E6EE5803CF067ULL
        },
        {
            0x6226F007423265C5ULL, 0x3C850DC575235634ULL, 0x3C11A4A31A234AD6ULL, 0x791567C781264FDFULL, 
            0x8D0E2C9AD308B3A8ULL, 0x164137177E948374ULL, 0x0595D5F9CEE3B700ULL, 0x21A60E33D992DA76ULL, 
            0x4582C998B0FD9F5BULL, 0x8B048ACFB2DFC251ULL, 0xE8FA5004D52A8DEEULL, 0xD3C79182E40C531BULL, 
            0x5924E4B0C6A4DAAFULL, 0x01D131639F5A1A85ULL, 0x61246ABAE484BEE4ULL, 0x4FEF0E850768009AULL, 
            0xC321FDD1DE75359EULL, 0x89E7E23F13C3330DULL, 0x84AA836DCB963594ULL, 0x39FD5CB4004F4188ULL, 
            0x4DB8A54398C4CC94ULL, 0xD6013C2118832A14ULL, 0xC5028039DF99A1CCULL, 0x18A25FD213013A60ULL, 
            0x96A8D33B22E281ACULL, 0xB183ED7B889B4363ULL, 0x13744B6438A2586FULL, 0xA4E93382C4445F43ULL, 
            0x87B6F626AA55273CULL, 0x406E5771D416676FULL, 0x886C1E4368A15D57ULL, 0x8B7D6F47B3D9468DULL
        },
        {
            0x52274756B9DA1F2EULL, 0x7EDB4E62B862A383ULL, 0xEE539FE552D7CE7AULL, 0x58399DC762C49E04ULL, 
            0x543685907D225FBFULL, 0x591199B3F74E4648ULL, 0xF34813DA0874C1FBULL, 0x74CB0E8DE516529CULL, 
            0xBAA14DE67F942D71ULL, 0x562275D001A43275ULL, 0x3AA8F48153BC0266ULL, 0xE38AE88C5C52A896ULL, 
            0x85C4582C01022AD6ULL, 0x756780A4176EE564ULL, 0x6A8F6EAF4DB63462ULL, 0xCB55603C4AE70B6CULL, 
            0x139FC8857FFD0DFCULL, 0x5F822AE8EA51B89DULL, 0x72D2BBAC401B4EB5ULL, 0xC7CB486B8802E3C0ULL, 
            0x34CCF5E3C68B80C2ULL, 0xDD20BBEC28C4722AULL, 0x82C7CBC17C739D7AULL, 0x6A1435DF00C8A133ULL, 
            0x78B9F3B8C38F8317ULL, 0x2DE9ED0C2D35092AULL, 0xD6C94929EC7FAA72ULL, 0x07931A2E43739952ULL, 
            0x5F5FE73E348CA0B3ULL, 0x207760D115F31A0BULL, 0x4C52DA12435F298BULL, 0xF3857AC0C09ABB26ULL
        }
    },
    {
        {
            0x3463927344C0BF6DULL, 0xBB7097D8004A4FE9ULL, 0x01AD2B5E27E59F86ULL, 0xA9E0E0DE018BE20CULL, 
            0x99C827067411BCC3ULL, 0xF00F6C30918B4EDDULL, 0x814A1D74451773E7ULL, 0x0F5804EAE2B3259BULL, 
            0xFA3BC87C4C32D5C8ULL, 0x6A76D850ACE69E39ULL, 0xD598EAE9266C128CULL, 0x2F733297236B6FCBULL, 
            0x6FCDC3062E345A88ULL, 0x84BD231CE578332AULL, 0x25B22726F1F44C5FULL, 0x1B318F5C3C1E112FULL, 
            0x1A5F19DA82441FDEULL, 0x559622029041A690ULL, 0x7704A3210F9B43E0ULL, 0x502743BFC0DE264BULL, 
            0xCE4BCC1567C953ABULL, 0xBB1D16EB5FB8D1A9ULL, 0x1E8DB233228A843CULL, 0x27217ECD58486C14ULL, 
            0x135AA712D095FA4BULL, 0x3A7E63FD873C129AULL, 0x2F5C3EDADF64B009ULL, 0xF11F87B4CEBFC114ULL, 
            0xA7B7A17AC18E777CULL, 0x819898DABB129773ULL, 0x38E81A4574FB7305ULL, 0x2551A513F93826C5ULL
        },
        {
            0x0DB7EA363649BD03ULL, 0x30759F9E2F6EF215ULL, 0x6C4E8C8670CA507BULL, 0xE604E840D159B3E2ULL, 
            0xBEE9369361E96168ULL, 0x1A319515CDAAAD02ULL, 0xD459EBA6096BF6DAULL, 0x61D2C8BE04708712ULL, 
            0x213E7E54437ADE02ULL, 0x5BBD6694EE876ABBULL, 0xB861D2BF22210FBFULL, 0xB783675580D2BF92ULL, 
            0xA041AAF0531672BCULL, 0x42BC09E27D80807EULL, 0xC616B4CFD8738ED0ULL, 0xF81C732E88F1E3EBULL, 
            0xB6FC8853EE859E9DULL, 0x94261A98BBF11A4EULL, 0x9A79AB6D7DA8907CULL, 0xEED15A8C52410B8FULL, 
            0x2349F536C34C6210ULL, 0x9386CEC20FB6B3F8ULL, 0xC7214F7CE92826C4ULL, 0xE651DA1967096D6DULL, 
            0xE8A209F6A68DB291ULL, 0xEB8685A0AE7ECF7CULL, 0x12393AC21981064CULL, 0x41EF22041300E3D4ULL, 
            0xFD32838F896A820EULL, 0xC018B7B5E4EF41FBULL, 0x5ADFFC8DFCF9CEA0ULL, 0x02A51D439848C889ULL
        },
        {
            0xB7073AAB3AC76DB7ULL, 0x885B726C7776384CULL, 0x6F5142EE9FA11F24ULL, 0xBB55FDCA979D71E2ULL, 
            0x53BD71F9E12FE79FULL, 0xFB9261A3B599ABCFULL, 0x5295B1D7E5963F20ULL, 0xA3D604897CDE6F20ULL, 
            0x3861EF110C79CC12ULL, 0xBDE02B716B4C65C1ULL, 0x97ACF0DD73C87C37ULL, 0xCD0B1DCB7B1B2B29ULL, 
            0xCEE631ABF47F354DULL, 0xCE9E0B486297719CULL, 0x96E76CBF2CB19EFAULL, 0x507810FDD8DA7EE8ULL, 
            0xB8695A8929A8CB9DULL, 0xD9439F214A6BA512ULL, 0xB4A3ABB0FE622C1AULL, 0x83F98180C8D21FF3ULL, 
            0xCE6E1A9F32775C82ULL, 0x6E5B98A149459340ULL, 0x74019506102BB5A7ULL, 0x3AE793839A2BB0FDULL, 
            0x485AEB84467BE60DULL, 0x0A883D656E4A2142ULL, 0x29B4ED36B15FC372ULL, 0xAAB7FBD544BB0004ULL, 
            0x753EAF65C896B783ULL, 0x93AD4FB4FAF5BF04ULL, 0x119928EB548372FEULL, 0x5F31A09BC6D12730ULL
        },
        {
            0xE11DA97ED36993B6ULL, 0xFD2AF39A3A2D914CULL, 0xB291F4EBC3EE0760ULL, 0xEC60E9667789A4B2ULL, 
            0x6BA9379C28B96DC4ULL, 0xA9787A5056CC3842ULL, 0x235C31E1C4827AACULL, 0x76AC9F9AB084F6B1ULL, 
            0x3387FD604F5D46BFULL, 0x09C04B05F81F3BB7ULL, 0x24EC3681ADBBBE97ULL, 0x8A5F06F1F7BAB298ULL, 
            0xFA5738111B442D6EULL, 0x41F458DD8F75E5DCULL, 0x03B28670F30B1CE1ULL, 0xA0BC64B43EE43FEBULL, 
            0xB9ED31121716C274ULL, 0x08A5B6A4C052C56AULL, 0xDC58BCD51BE4ADEEULL, 0xE612396B47C759E2ULL, 
            0x1ADF3153506B924FULL, 0xA46C586308062820ULL, 0xD31D3890814739E2ULL, 0xE944D6641007C3BEULL, 
            0xF71E69520EB827D1ULL, 0x54BB9B085FCE8F23ULL, 0x576CD6566408B254ULL, 0x8C7662C07227FDEBULL, 
            0x6D44DDDB8F37BA1DULL, 0xADDBB44067429F31ULL, 0xE989D99F6675D089ULL, 0x90B897003D0583A7ULL
        },
        {
            0xD0063034871F9C5BULL, 0x45C53011DC1B40B7ULL, 0xA4675E5AB8E80935ULL, 0xAFB5B378D91BD74EULL, 
            0x68F4138DB1965446ULL, 0xD30A1195472179BCULL, 0xE530CA6964920EE0ULL, 0x2BC2621C7A65F42DULL, 
            0x7DB8D6D39A1A7983ULL, 0xD66FB1328766A4A9ULL, 0xDE286847DDBDDA1DULL, 0x6028934F8543BFBAULL, 
            0x41BB8FDBAE64E229ULL, 0x266630C8F0518C1BULL, 0x51A5D32AE8AF8F53ULL, 0x4C430746788A2559ULL, 
            0x7E7231C525AB3C30ULL, 0xEE0C18032580F6FDULL, 0x1F4D4783AE4482CCULL, 0xBB17F7E68D2EB3ABULL, 
            0xFA1F14508B174DA7ULL, 0xA3D15A1A4123FD80ULL, 0xD1015ECA794E0F60ULL, 0xF854EF77C65F7DE5ULL, 
            0x334DDA4CF30BBD23ULL, 0x984035AD92EB3F26ULL, 0x26CFB0C0546EC74CULL, 0x1A26CA964D7E330DULL, 
            0x16E0EDAE3CD7824BULL, 0x522E435A2BBB035AULL, 0x5554EF0D7096AED8ULL, 0x7F26C212E4CF4376ULL
        },
        {
            0xA1B0945642549DE8ULL, 0xB0DAA0B8D8AFA23AULL, 0x19C337D487D8D077ULL, 0xA54C9EBAA494468EULL, 
            0xB8C0D3816CF689DDULL, 0xF8A7EE8A6FDC5F59ULL, 0xF7DB3F7A2746F63FULL, 0x1AA79E32DA64A294ULL, 
            0x9FD6964910976314ULL, 0x9376C09FE3148A91ULL, 0xC1D12183BE72CC1FULL, 0xA0389149F37E9D0AULL, 
            0xE114CF1059333986ULL, 0x1F178861FC0796F4ULL, 0x2073754FEBF54D53ULL, 0x5DB8C1DAB6A39FA5ULL, 
            0xEDCBE03CEDE90D29ULL, 0xE09D7F63E203F098ULL, 0x6A50FFA00C24971BULL, 0x4A93E31C6D357AA4ULL, 
            0x54A013BB3D6DAC55ULL, 0x35F0CA6D2A7E29A4ULL, 0xBCB52E7C04ED85D2ULL, 0x809E9D4E6E53083BULL, 
            0x1DACDA0ABA48750CULL, 0x9E17A248CEA4C06EULL, 0x8C1640CE164D6506ULL, 0xD82A02922AD65EDCULL, 
            0xF06655D0AFC96C70ULL, 0xB8163EA3A74F5EB2ULL, 0x26D98709FA725FBAULL, 0x7E21D3DE6189AE7BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseGConstants = {
    0x385B6B2B973A1E9FULL,
    0x2C9B92B7CC1242DFULL,
    0xBD3A9863FCDBE146ULL,
    0x385B6B2B973A1E9FULL,
    0x2C9B92B7CC1242DFULL,
    0xBD3A9863FCDBE146ULL,
    0x427F691C9B994B5AULL,
    0x4BEB32F40FF5DA61ULL,
    0x2D,
    0x55,
    0x91,
    0xED,
    0xA0,
    0xD4,
    0xDF,
    0xC1
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseHSalts = {
    {
        {
            0xC53ECDD9891487A6ULL, 0x827E4AF4D6B98B00ULL, 0x06A3004B8FA30F8CULL, 0xB09DBBBA881143E2ULL, 
            0x0445D0F540120A48ULL, 0xC1F906A8A6C24ACCULL, 0x0341EE00F458D641ULL, 0x27076F6C7E598F4EULL, 
            0x3E2914883BBEE743ULL, 0xF04FB965E1CB1E41ULL, 0xC5039805BC2765E6ULL, 0x3823F7705E323FF4ULL, 
            0x846288B7953520ABULL, 0xD55203369E08D6DFULL, 0x80B463C05AC74037ULL, 0xA769A079ED53F642ULL, 
            0xD56C958283749C11ULL, 0xD09A4108E7911A76ULL, 0xE6F7102DE807E7D6ULL, 0x163223871D6E55DFULL, 
            0x181E7D345748A8FBULL, 0x31CAD6B2A239BB16ULL, 0xAB1B3C5BF630E321ULL, 0x30326C0AFD7A7D18ULL, 
            0xC5AB5CAF75489F75ULL, 0x9568BD6788F7282DULL, 0xA3EAAABC4A1354C7ULL, 0xF48671312FAC1023ULL, 
            0x702D5F3C4C06CA24ULL, 0x42F3B879EF6EB231ULL, 0x43CEA39F4A14BDCEULL, 0x2E74F0F6C212986EULL
        },
        {
            0xACBD94B6F88FEBCCULL, 0x3E1E2EEE4019FE3CULL, 0x08FBF9ED64AD712BULL, 0xC4CB91DC5AB8BC2BULL, 
            0x4E91536FBF959275ULL, 0x16208BDD9DFBF3ABULL, 0x462874C573D30CEBULL, 0x13BFC4FF8EB937CFULL, 
            0xB311C4463AB890A1ULL, 0xD3AC8ADD70EEE1E7ULL, 0xF29F5E65DF8CFD72ULL, 0x8B0C84C5B207DC10ULL, 
            0x4421F6CD42BADC42ULL, 0x3E728177748BA69CULL, 0x1DAB23A9A3DFAA09ULL, 0xD7C089C1B03AF545ULL, 
            0xD405F081E3C93531ULL, 0xE02E3C827C702548ULL, 0x6F15BC36A83D6943ULL, 0xA0033A4B049BD3FAULL, 
            0x667763B22A50ABE4ULL, 0x1A07C1187200FCD2ULL, 0xBDFC7BE2BAD705EBULL, 0xC9B03AEEB3624B2FULL, 
            0x55A45185D68F6EC6ULL, 0x94A0278E551DC5E7ULL, 0x7640008BC5320AF1ULL, 0x008FA7E2DF03CE9DULL, 
            0x28D3E32E4224FA67ULL, 0xD6D672E95642B67FULL, 0x5B75CAA45B41F261ULL, 0x3C993BE172B72FB1ULL
        },
        {
            0xCB6E5D9493B1A95EULL, 0x5BD0BCA0E33D0175ULL, 0x36CC6844FF5C556AULL, 0x4A1AD3BBCD7CC59DULL, 
            0xE08116722BBF0505ULL, 0x1F80225E9B1AC95FULL, 0xECF1FC96A64AF6B4ULL, 0xA3B220453CD811B5ULL, 
            0xD14C3050454EC8BFULL, 0x4643EFFBB561F877ULL, 0xB490E78FE90E0AB9ULL, 0x4F2599B239AEB699ULL, 
            0x11E8CB22CCBEAF44ULL, 0xCBCED91796686BD6ULL, 0x8F91B67300F0232EULL, 0x213A97FC4A3C4432ULL, 
            0x1FD1376D645DEF98ULL, 0x99BF2C984C306834ULL, 0xC6E3AADD58D5825BULL, 0x1D2372F5036EFA9AULL, 
            0x04827D1DAD77497DULL, 0xB1D1CA6D79C67F11ULL, 0xE36BA6261F37ED29ULL, 0x62F4C149840BA103ULL, 
            0x06F46B9F2BD10DEDULL, 0xB724CCE8BE1E9BD0ULL, 0x6C8AFA3C6328B5C5ULL, 0xA6C30203EF2A9103ULL, 
            0x98C7E0EAE68BB627ULL, 0x9C9B0424D9F1EFAEULL, 0xCC054003CCBB3C06ULL, 0xD23814034A7D75B6ULL
        },
        {
            0x308A9A5B58D807F2ULL, 0x2786388BA21E56F6ULL, 0xE28B97E9AF3028E8ULL, 0x38E76DEDF005FE1CULL, 
            0xCDEE0D0074D36BCCULL, 0x0E698D5A04EB8AC6ULL, 0x2F0BBD51EDA3221FULL, 0xA41CF309804212D9ULL, 
            0x3D998265613343A9ULL, 0xDB8059357ABF73C0ULL, 0xE923DF94571FC14FULL, 0x8809D491763C20B1ULL, 
            0x5BD649C01CDEA227ULL, 0xBC72BEF5A90FD432ULL, 0xFCC3216C1136ACECULL, 0xAF0265FCD2DD9080ULL, 
            0x11B32AE57CA8B6EEULL, 0xDC45A68937203A06ULL, 0x87776439B3CA7BC0ULL, 0x94AB3F14CCEEFA21ULL, 
            0x0C30184EF678C9EDULL, 0x2E6563FB2F563112ULL, 0xCFE23C831D23B668ULL, 0xEE324817A38D9257ULL, 
            0x02C6030AE58842ABULL, 0x1729D001ADBF2BDFULL, 0xDBAB6F58A680DF52ULL, 0x7EE96CBC41019339ULL, 
            0xCE70163A46D20C9CULL, 0xEF6F83C717E8301DULL, 0xE1B342FA365300EDULL, 0x6454D960514CFDBEULL
        },
        {
            0x7E3869F2DC29B210ULL, 0x81346B3B277963CDULL, 0xA3343D0D8078B0AEULL, 0x5089B9E2218C6719ULL, 
            0x409739E66B33D32EULL, 0x4D87EDE5A0B9A775ULL, 0x248AE0DBC70B52F5ULL, 0x59527448E2848897ULL, 
            0x7CCA20EDB7A5F5FAULL, 0x7E76E3F60A0BE6C4ULL, 0x0A4D5D572BBDB5C7ULL, 0x20C6EC1FFE69935BULL, 
            0x24A7907F8E6D5BB5ULL, 0xABD7B5CC5B86D55BULL, 0x1BEFB14FD33DC27DULL, 0xCD34D08FF9297B82ULL, 
            0x60C5FC91DFB166A8ULL, 0x824D3DDEDCEBA2FBULL, 0xD947D6A3BC5CEACAULL, 0xC19BF69B1855AA13ULL, 
            0x2998BAA44CA8B351ULL, 0x84CCBDD4E8E13C09ULL, 0x5D6BFFD73E419370ULL, 0x58E18C957A358F91ULL, 
            0xDE45BCDE322DE3C3ULL, 0xBCD1A31F7BC5CF07ULL, 0xAE592386CD62760EULL, 0xFDEDD6F0A6416294ULL, 
            0x29A5F19848320237ULL, 0x45ABB6F8BF37900DULL, 0xDBE94D926F6B479DULL, 0x7A92733F9A0EBE95ULL
        },
        {
            0x1A9FA44F7C332478ULL, 0x98112744E49F5922ULL, 0xDFEC58ECB2F81ACDULL, 0xAF85C7662149DBEAULL, 
            0xE544598EA920BF61ULL, 0x85D09ABF4FECA01AULL, 0x08E1F341B37EA027ULL, 0x7A53BF872CA6ABECULL, 
            0xC45848EF994E47DEULL, 0x24AE6E0711FF431EULL, 0xD4842DD2808A2625ULL, 0x9AB018E345575072ULL, 
            0xC026AB4AA5C53543ULL, 0xD74256A79CFEEDF3ULL, 0xCA52DF4C07D330CAULL, 0xBCB99600C1AFAEE5ULL, 
            0x3D1C9F2879490C6EULL, 0x69CB0303FC266D95ULL, 0x65A082B86B5FE94EULL, 0x9BC8A3CEF91979ACULL, 
            0xF29F3EC6415E41F1ULL, 0xA938C918F4A47901ULL, 0xC944084FA873E10CULL, 0x80482C085CAFBD50ULL, 
            0xC8B0867BB053397EULL, 0x05851F429716C604ULL, 0x13BF352DC90DC028ULL, 0x226E98CFEB7A0CBFULL, 
            0x62717FD2536D5DB3ULL, 0x93B6C05F92C93E80ULL, 0xD440084EF9AEBA0FULL, 0xD9B0B0AF3957310AULL
        }
    },
    {
        {
            0xA1160E1670FFE99EULL, 0xC60F4930ABCAAB7DULL, 0x29738BC532FF6001ULL, 0xA0231F20F753270BULL, 
            0xD5294B0EE3088DE2ULL, 0xAF9953B3D5363E01ULL, 0xD930B1F52351E552ULL, 0x2EFC5872BC9A705DULL, 
            0x3DD3A42ECE33D4D4ULL, 0x6AB77D17CF7AA68BULL, 0xE770A32D988BA7DBULL, 0x4254190C9B6E1D61ULL, 
            0xE608FD76962863BEULL, 0x80B6EC73C93DFCB1ULL, 0x15022893EEF6A36EULL, 0xBC531201397BEE68ULL, 
            0xB4556AA92658D6BDULL, 0x875235766426F61CULL, 0xFD8241777A36B95FULL, 0x5DEA587E08F9E8F3ULL, 
            0x8309EC1A4228BD6BULL, 0x2F489C94918FEB31ULL, 0x6AC0651A35628381ULL, 0xEDDF361E3F086A94ULL, 
            0x9E001A4024F87D44ULL, 0x14806003FBAF939AULL, 0xC49BFDFE7CD6F0A1ULL, 0x307FC022EEC80BD3ULL, 
            0x90EB2A58321316D4ULL, 0xE371DB26B4941F23ULL, 0x1EC6A1A29F1DE825ULL, 0xE1A58E5BF3347424ULL
        },
        {
            0x796A3393EDE3882DULL, 0x91686CF1A78F7933ULL, 0x3F15263F12355266ULL, 0x9374AE37F953E13CULL, 
            0xA7A82477D23CBD26ULL, 0x52382B23B29F7149ULL, 0x42C5F19381E24542ULL, 0x00139B5829307A8AULL, 
            0x154C67FD2DD14BF0ULL, 0x8F707ED3E3B635DDULL, 0xE81F8D9AA611808AULL, 0x0194CE5BD60C34A5ULL, 
            0xB097AEFAE488E162ULL, 0x2BBCF5A7ADE62DEBULL, 0x2305BF9020E493BBULL, 0x5B2B32B5BB89B434ULL, 
            0xB0E50279CDCBB3FEULL, 0xFF475099F350380EULL, 0xC815AAE4C9989179ULL, 0xA7714313CA6B52CAULL, 
            0xF5EC0C3385E14034ULL, 0x5BDD8C8757892B5BULL, 0x2D94293B92AAC830ULL, 0x2AAE7D08F57FBA29ULL, 
            0xCC29F87FA906CF24ULL, 0xC5DB1148F018B368ULL, 0xDFE1D300BFFB4166ULL, 0xAD01C072D8654AA4ULL, 
            0xD3879398EB203707ULL, 0xD189C6081628A791ULL, 0x7D78D240A18CA2ADULL, 0x4803B0AD966408F3ULL
        },
        {
            0x8A7C0F718069A176ULL, 0x9EEB678F822D5165ULL, 0x97DC0BDDBB944EB7ULL, 0x69EC81E1451C2764ULL, 
            0xE3DB745696675785ULL, 0x3E757FDBD7AA6295ULL, 0x05D7E33A2EDDC254ULL, 0xC235C7A80E73619DULL, 
            0x609FC6958E28781FULL, 0x738A585926EF80B5ULL, 0xDDEA48E7EA9152B1ULL, 0x8025D7482D0809BAULL, 
            0xCF25EBB337C880C6ULL, 0x44EB1CD307EF6475ULL, 0x1742774A12465D67ULL, 0xDB7DED27CD2F37CEULL, 
            0x71C4055D6D14E3F3ULL, 0xDFC16198B14DEE00ULL, 0xB077D732C25DBEC9ULL, 0x4A71C72DC9485277ULL, 
            0xB875CEBA460DF693ULL, 0xA3C3C3C6E0172126ULL, 0x3AE020BC76F94D80ULL, 0xF53588BA18C85FFFULL, 
            0x5E510E6AF9F28754ULL, 0xA4242E672BCF3A49ULL, 0x888027F74D2C37BBULL, 0x6DC5E92F09306EE5ULL, 
            0xDF666BC9C12EAB4BULL, 0xE76D13189EEB6818ULL, 0x7BF04E35EA3D1DD5ULL, 0x5525B4CDCC23AF10ULL
        },
        {
            0xA142E7B2E2BDD454ULL, 0x14F9D8429B9257E0ULL, 0x587903CE8F352EB4ULL, 0x1154F89C3132CF30ULL, 
            0x6D56562B9EE3E884ULL, 0xBCAD19800AC3834BULL, 0xE793D793B0628035ULL, 0x66FCFEABBA893031ULL, 
            0x13494FB969EDD124ULL, 0x09B6AEE7B5902D86ULL, 0xE0916933AF33B409ULL, 0x12B76A953E9692EDULL, 
            0x281BBA1085B2F2D1ULL, 0x565F367FEA92DF74ULL, 0xA9C80BBAE83AE6FCULL, 0x29DE395FB5BA2633ULL, 
            0xEF5A91486542DB19ULL, 0x851B0F1E2CEE81F6ULL, 0x8DAB3C3DC773099AULL, 0xFD49B0C97E494C31ULL, 
            0xACC999B4203AF02BULL, 0x638485E6260F43C0ULL, 0xF440F68E5B85BB24ULL, 0x66B746413B04A915ULL, 
            0x44E3C2C8FAEB90E4ULL, 0x62F4BC96C4156A0AULL, 0xA1432EB4C7B76416ULL, 0x0E691EC86E167550ULL, 
            0x95DCC6F4E07DC634ULL, 0x15C5D5A8295ABD0FULL, 0x0CF33AEEB269A50CULL, 0xB1F9B73AFD47CAABULL
        },
        {
            0x5C7EDA35BBDDC926ULL, 0xCADECEC2BBC9C61DULL, 0x03ECC2067D1C7705ULL, 0xEB6AB45E7955D5A2ULL, 
            0x98D8EAD9667B2FFDULL, 0x634A8F3F1BE508A2ULL, 0xBD343BA9F8B64887ULL, 0xB4F922D1160D51B6ULL, 
            0x14E30909DDCCE08BULL, 0x0B7CEAF96B57F7E6ULL, 0xF6563E2250A14120ULL, 0x892F3C8858CE6E50ULL, 
            0x2023B947FF4C8F8FULL, 0x6AB80B6CB16880A6ULL, 0x5190BB9EB95F41C9ULL, 0xD029C45BDA340FBAULL, 
            0xBDFF439BAFD55A50ULL, 0x07FC6EB48C242908ULL, 0x1263AE210D15B996ULL, 0x39C031A25D7860D5ULL, 
            0xFA6AE5996439D4AEULL, 0x09C44DF73D9818A8ULL, 0xDDEF5C05B50B7A45ULL, 0xF7782BFCFA99309BULL, 
            0x101DDAEE1E1D4C24ULL, 0xE847215E1BA6132BULL, 0x33D14AF4BBEE61A7ULL, 0x8CC1C9FCC9CD72E2ULL, 
            0x6FE1D668D295295CULL, 0x95889FD02B1B5830ULL, 0xCFE23CC180FB3C47ULL, 0x509887EC483EC533ULL
        },
        {
            0xFA95269CFAA68932ULL, 0x160E209255624FE3ULL, 0x0DEB8DCEC5DC8BB7ULL, 0x56AF6F5777EF134AULL, 
            0x9D8DDB3736439742ULL, 0xEA3419DDA3135502ULL, 0x56671EDF28AD8469ULL, 0x5FBF3E7670DA983DULL, 
            0xFF533C09DF771C91ULL, 0x8A3818258CA056F3ULL, 0x1AC3F3A66E7722A0ULL, 0x608E3D5D7AC0170FULL, 
            0x05FD0C567C206831ULL, 0xFF173487C437177FULL, 0x55D0FC2E17594EA2ULL, 0xCEE84C96C9E8CCFEULL, 
            0x98F5D46262580242ULL, 0xC96DA9F41C5BD013ULL, 0xA7176074C5F8D585ULL, 0x3ED9932931DF5EB2ULL, 
            0x6FD9CA1078BE01D7ULL, 0x8080F9C013144518ULL, 0x0103F3E19A7D5789ULL, 0xBFF40A6EF439B474ULL, 
            0x9736765CA9F129EEULL, 0x7C5ACB719FD48CCEULL, 0xEC7DC2E21AF33E25ULL, 0x2E637E3905B53D3CULL, 
            0xD51723FFE403B939ULL, 0x6C65F789086AB568ULL, 0x809D727617755B17ULL, 0x9D21E95079C75E72ULL
        }
    },
    {
        {
            0xBC2F602A97C25037ULL, 0xEF6F650EB9ECAD45ULL, 0x3428A138D0027C90ULL, 0x826554B884ABAA6EULL, 
            0x93572D11F95F8867ULL, 0xF2F8D938C7EEEAE6ULL, 0xB4D3F0FF6E00251DULL, 0x7F8A23B7290B5CEFULL, 
            0x345166CAC6367694ULL, 0x7A9FA47936B246DFULL, 0x94A59AE225A48406ULL, 0x592B512F041E285DULL, 
            0x91FBF2D69780177AULL, 0x070D4A7A7486CB85ULL, 0xC240E39DA7081392ULL, 0xC1D2D849740C4B37ULL, 
            0xE91DB353FE4B9D55ULL, 0x0C7F13D891819189ULL, 0xA50873AA5E15B6D1ULL, 0x734F54025F5D627FULL, 
            0x1B0056345A6A7BDDULL, 0x1E1E92EB0857CAE3ULL, 0xADF10E2CE666C00CULL, 0xA95587C4BEB1DBD6ULL, 
            0x35C6FFA60AA51707ULL, 0x02C2A575B1A3EB2FULL, 0x8A1C163993278E50ULL, 0x2774627DC02BD8E5ULL, 
            0xFC35EDD5738A84F8ULL, 0x68D11A60F24C1886ULL, 0xB0B1E485FD464070ULL, 0x93E703F02D3E5C9EULL
        },
        {
            0x6D63C227B373AAE0ULL, 0x2877918C0E287CE0ULL, 0x9E78ED04606D3F91ULL, 0xD6F0F25AE67328AEULL, 
            0x5850F9B87E01E8B9ULL, 0xCEC07A8B79D8412EULL, 0x317CAF86E2C4C8A9ULL, 0x9C09A3234923A804ULL, 
            0xE0E1170B85F1F3E9ULL, 0xBCC3FBBC36EF87B8ULL, 0xDD8583005AB4A2E7ULL, 0x8517F35814CCE4B9ULL, 
            0x23B65C1E4BF5C276ULL, 0x9C4E7904E9882E36ULL, 0x77F7FE77C0FA0263ULL, 0x984E9F251EB61003ULL, 
            0x8FF2164E51E481E3ULL, 0x680ABF9BE1D1B0C7ULL, 0x689F5DDC7BFE5FE1ULL, 0x38A272367BFAC0D6ULL, 
            0x41FAF08A3010E476ULL, 0x1B4530207F31ED17ULL, 0x145B39F810A58759ULL, 0x0668417A547DB4E0ULL, 
            0xE16205A91334F241ULL, 0x557F99B8B6049BB7ULL, 0x181AAC95CE311AD8ULL, 0x991E2266201D0ADBULL, 
            0xC78951D924A621C8ULL, 0x559B781693B53B1FULL, 0x2BF1D2B122CEC0C1ULL, 0x46D88D6908FB0E5BULL
        },
        {
            0xE6008D7A0F825144ULL, 0xFB0BEF1B69A00CD2ULL, 0xEF1AE218989E3746ULL, 0x233F65CBB87F29C2ULL, 
            0x7CD3630DC9DEB68BULL, 0x6D9FF0D718FCDF76ULL, 0x9859F79DD85321D6ULL, 0x63DAE5D116764247ULL, 
            0xC0117AFB776EE85BULL, 0x087969EA70E7D8DAULL, 0x3F939D5A86803FF8ULL, 0x7D55865D0851B7CDULL, 
            0x47AA0FDCB02D351EULL, 0x6FEB5EE68D508480ULL, 0x7CE9B416EE0DA817ULL, 0xC88D68BD4A7B81EAULL, 
            0xAEE01D739B664F3BULL, 0x256EC26FC4292088ULL, 0xEF7D8F57DCC4EEFFULL, 0xB338B2014DF94385ULL, 
            0x769D224C00AF93F0ULL, 0xDE5FE22077050EFAULL, 0x70BF148E0654AC2DULL, 0xFD00C50F36DF351EULL, 
            0xE828D812FE45D066ULL, 0x5F71F53B93671E43ULL, 0xF373923799890C6CULL, 0xEE4048C9375636B3ULL, 
            0x352908515C49256CULL, 0x07841553409AE737ULL, 0xBB927F66DCB4747CULL, 0x490900E768DEF55BULL
        },
        {
            0x2F3F235CBE414248ULL, 0x4805AEC35DC78494ULL, 0xE2BDCD402403AB1FULL, 0xE8F751674B751638ULL, 
            0x7BDC2B97970856CFULL, 0xAADEF21F12E3EFBDULL, 0x45DDD2258CE129EEULL, 0x73B4811B97A00543ULL, 
            0xA74A0B7BAA991691ULL, 0xA3A464891577CAD2ULL, 0xDF998056F4A2E5C6ULL, 0xC0F5B4DD991BF0C9ULL, 
            0x9EAFD0673152FC02ULL, 0x45C345C1B13CE713ULL, 0x6E6C23284079EFCEULL, 0x16EADB1FD126852AULL, 
            0x20F23B0A4F1645FDULL, 0x8AD7DCFB847F7D3CULL, 0x0B8A82DB4A27C230ULL, 0x4D5072B787BC3AA9ULL, 
            0x4422D6608D96B07BULL, 0x9712DE207096DDA7ULL, 0x478908CF8881803CULL, 0x41EEB26B0AFCF354ULL, 
            0x3FED0DA319D983F3ULL, 0xE43DF9EADE5BB9D8ULL, 0xB849F9E00937D5EAULL, 0xD78226C980B35E50ULL, 
            0x8BCEB6C900D0E3B3ULL, 0x60B8A40BE02E313CULL, 0xB43C58030FB0A54BULL, 0x7485B74DA3C6AE86ULL
        },
        {
            0xE4A545F4D8361F65ULL, 0xD3499081C9ED5B94ULL, 0xE1E2AF8C292EE035ULL, 0xA57665195D6CFEB4ULL, 
            0xFED93064EB01035FULL, 0xE45B1BEC12E804F8ULL, 0x83C48204B7A39E10ULL, 0xBB4CBF01D122C127ULL, 
            0x6598F547AE49131BULL, 0x61DAC1645B127F6AULL, 0x843B75E978B58921ULL, 0xE0F19CECDECA691CULL, 
            0x49EA21CFE09CBFEAULL, 0xE36A17FCC38902CBULL, 0xD55428B695B602B7ULL, 0x8976CE9502CA9442ULL, 
            0x0E3BDB9334A73399ULL, 0xDD432D119D8B214BULL, 0x7F869504245D502CULL, 0xA852365CDDE40912ULL, 
            0xD11A457990568D54ULL, 0x69EE1BED82C2F63AULL, 0x0CF25E8DDC18E373ULL, 0x702D8D710FDA2FD6ULL, 
            0x417C6CBF2EE7F558ULL, 0xB2DF1A8F5157673BULL, 0x6A06D9EBF36CFF65ULL, 0x9EA25EBFC0B6B9AFULL, 
            0xEC85A6651159A539ULL, 0x8A3716DC0E2D4AF9ULL, 0xC6B3E8E8D4B32923ULL, 0x1969122ACD1DC8EBULL
        },
        {
            0xABA8C59CD696B901ULL, 0x32B6F4209B6E16BBULL, 0x8475BE6E8F24A53EULL, 0xD66C23CED5EA4A09ULL, 
            0x545E81392D156373ULL, 0xB21D98EFE6746FD6ULL, 0xBE4D1E2BFDD076E0ULL, 0x824C06D82B96F886ULL, 
            0xA495832E0250EB22ULL, 0x07BD1E8366F468F3ULL, 0xEAB9341FD01A2BCDULL, 0x0A5504467D6FDE86ULL, 
            0x5D80535ACF13E26BULL, 0xE11B0C25692A2E1BULL, 0xF6715E4B54528974ULL, 0x4D68F41E7EEC96CFULL, 
            0xDE53DA737FB832D2ULL, 0xFC897726EACF4C8CULL, 0x79C160039C861CB0ULL, 0xC3A27E842779C49EULL, 
            0x52CA707DC9D3C926ULL, 0xBE76C59BEECDE93BULL, 0x9A22FC2BCBBC27BCULL, 0x1DD0C8C2DE42DECDULL, 
            0x164041F5F5222B19ULL, 0xAF00BC2B8A0A7D6BULL, 0x90F2F6F23F74A65BULL, 0x189E425DF39E0B10ULL, 
            0xCC7F8F8D5FC8B02AULL, 0xF01729A8C98CDCE4ULL, 0x1DF230A423D69EF1ULL, 0x6888838528D85779ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseHConstants = {
    0xA50B0D07A4BF9836ULL,
    0x8805D2A54BAF63F2ULL,
    0x2109FABE2FF9A743ULL,
    0xA50B0D07A4BF9836ULL,
    0x8805D2A54BAF63F2ULL,
    0x2109FABE2FF9A743ULL,
    0xDCCB5D68B00573FBULL,
    0xF50D24110F1483D6ULL,
    0x3C,
    0x76,
    0x46,
    0x9E,
    0xD4,
    0x7E,
    0x2E,
    0xEE
};

