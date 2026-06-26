#include "TwistExpander_Soccer.hpp"
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

TwistExpander_Soccer::TwistExpander_Soccer()
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

void TwistExpander_Soccer::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 14360931574010332622U;
        aCarry = 17805124199711479247U;
        aWandererA = 15796277656228364207U;
        aWandererB = 11503299846049570463U;
        aWandererC = 11409399886501023571U;
        aWandererD = 15524495345800536040U;
        aWandererE = 14160565057704488489U;
        aWandererF = 12176500296021968735U;
        aWandererG = 16916155395876562865U;
        aWandererH = 12613277120680078913U;
        aWandererI = 14236895613950061150U;
        aWandererJ = 12746115299503029742U;
        aWandererK = 16656773848049799946U;
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
    TwistExpander_Soccer_Arx aArx;
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
    TwistExpander_Soccer_Arx aKDF_A_BArx;
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
    TwistExpander_Soccer_Arx aKDF_A_CArx;
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
    TwistExpander_Soccer_Arx aKDF_A_DArx;
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

void TwistExpander_Soccer::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14079997426305734243U;
        aCarry = 12677900350809330808U;
        aWandererA = 16834148723092150299U;
        aWandererB = 11711562532200802755U;
        aWandererC = 17236735046011885994U;
        aWandererD = 13808535544953997366U;
        aWandererE = 16655083234089819302U;
        aWandererF = 10977082512477352618U;
        aWandererG = 12907475313715865884U;
        aWandererH = 9414926243173738362U;
        aWandererI = 17932433809393299640U;
        aWandererJ = 16326227500525052972U;
        aWandererK = 16453942324660117423U;
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
    TwistExpander_Soccer_Arx aKDF_B_AArx;
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
    TwistExpander_Soccer_Arx aKDF_B_BArx;
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
    TwistExpander_Soccer_Arx aKDF_B_CArx;
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

void TwistExpander_Soccer::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x96FA984643A22335ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xFFB805A7876BFF80ULL;

    std::uint64_t aWandererA = 0xD0909B69813D3B62ULL;
    std::uint64_t aWandererB = 0xF0D4B73392111895ULL;
    std::uint64_t aWandererC = 0xFCC0CCCEF2FF3B3DULL;
    std::uint64_t aWandererD = 0xA5141A41435CE7A9ULL;
    std::uint64_t aWandererE = 0xA317C7FFB52C10C5ULL;
    std::uint64_t aWandererF = 0xF4E1CC83C5FF9A33ULL;
    std::uint64_t aWandererG = 0x89D2679622C644A4ULL;
    std::uint64_t aWandererH = 0xFA88375C4DF5D888ULL;
    std::uint64_t aWandererI = 0xFA8F351EE014DC6FULL;
    std::uint64_t aWandererJ = 0xA903B91274A2C07BULL;
    std::uint64_t aWandererK = 0x9C57D34E2B9AD5A3ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
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
    TwistExpander_Soccer_Arx aSeed_AArx;
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
    TwistExpander_Soccer_Arx aSeed_BArx;
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
    TwistExpander_Soccer_Arx aSeed_CArx;
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
    TwistExpander_Soccer_Arx aSeed_DArx;
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
    TwistExpander_Soccer_Arx aSeed_EArx;
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
    TwistExpander_Soccer_Arx aSeed_FArx;
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
    TwistExpander_Soccer_Arx aSeed_GArx;
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

        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx aGrow_AArx;
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
    TwistExpander_Soccer_Arx aGrow_BArx;
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

void TwistExpander_Soccer::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Soccer::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 10528220708910186405U;
        aCarry = 13232495757128209208U;
        aWandererA = 17480393958770182150U;
        aWandererB = 12586443599471444809U;
        aWandererC = 17240562660132733247U;
        aWandererD = 11526761438268038911U;
        aWandererE = 10930102643163197231U;
        aWandererF = 13929096012258826018U;
        aWandererG = 14630065090780270951U;
        aWandererH = 17280562165044003098U;
        aWandererI = 15699486355489056795U;
        aWandererJ = 17753687400568601465U;
        aWandererK = 12724996917272399902U;
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
    TwistExpander_Soccer_Arx aTwist_AArx;
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
    TwistExpander_Soccer_Arx aTwist_BArx;
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
    TwistExpander_Soccer_Arx aTwist_CArx;
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
    TwistExpander_Soccer_Arx aTwist_DArx;
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_Soccer_Arx aGrow_AArx;
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
        TwistExpander_Soccer_Arx aGrow_BArx;
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

void TwistExpander_Soccer::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 3, 1 with offsets 7934U, 5454U, 8002U, 7452U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7934U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5454U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8002U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7452U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 3 with offsets 2283U, 3548U, 1036U, 133U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2283U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3548U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1036U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 133U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 0 with offsets 2737U, 289U, 6830U, 2713U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2737U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 289U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6830U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2713U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 0, 2 with offsets 5753U, 2117U, 6985U, 2667U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5753U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2117U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6985U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2667U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 with offsets 1856U, 563U, 445U, 295U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1856U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 563U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 445U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 295U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 0, 1 with offsets 1294U, 553U, 862U, 1581U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1294U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 553U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 862U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1581U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 2, 0, 1 with offsets 136U, 87U, 133U, 1390U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 136U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 87U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 133U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1390U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 0, 1 with offsets 686U, 1640U, 817U, 1182U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 686U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1640U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1182U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1265U, 1111U, 1375U, 198U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1265U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1111U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 198U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Soccer::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 1 with offsets 582U, 4841U, 4915U, 5218U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4841U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4915U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5218U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 2 with offsets 1886U, 4750U, 7202U, 4318U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1886U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4750U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7202U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4318U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 0 with offsets 200U, 1307U, 1658U, 1782U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 200U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1307U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1658U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1782U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 1, 3 with offsets 5004U, 5558U, 4370U, 5787U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5004U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5558U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4370U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5787U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 543U, 985U, 5087U, 2491U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 543U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 985U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5087U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2491U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 517U, 666U, 1393U, 709U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 517U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 666U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1393U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 709U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1902U, 1746U, 1031U, 71U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1902U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1746U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1031U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1401U, 1986U, 364U, 1851U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1401U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1986U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 364U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1851U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 903U, 1957U, 482U, 1571U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1957U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 482U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1571U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 [0..<W_KEY]
        // offsets: 24U, 1716U, 1189U, 1292U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 24U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1716U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1189U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1292U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseASalts = {
    {
        {
            0x598E1815182B29B3ULL, 0xE85BF2AE22C5E994ULL, 0x5847760C3240896AULL, 0x18C42571B5B87F56ULL, 
            0x64ACB56278703C32ULL, 0x8B7FA38C0235CD0BULL, 0xB086A4432565C84DULL, 0x775136C98ADAA053ULL, 
            0x72FD13ADBAC4CED4ULL, 0xF104FE96059F30A4ULL, 0x3BACD5D95E4CF2F1ULL, 0xAE51954A6647A043ULL, 
            0x73247FB159029557ULL, 0x5907C96779C40B93ULL, 0xB6A2DB172B8197B2ULL, 0xCFF4BB718C2E2B86ULL, 
            0x60D7D9552FEB8EFAULL, 0x0EDD0B9486B07E31ULL, 0x790F3CAD84E22961ULL, 0x8225A7B738B1AF3BULL, 
            0xAAAD45B97A2ED9D7ULL, 0x6F6337064572715DULL, 0xE07F75D19A9D0490ULL, 0xAF18FA1AFF1BA3DCULL, 
            0x7FFB7C28941203A1ULL, 0x3F52DD6E43E2D3A3ULL, 0xC15D7A431E1EB50BULL, 0x6494856BC11BF535ULL, 
            0x446E72516A3B29A6ULL, 0x158170FC4604733AULL, 0x14130BD01BD25472ULL, 0x62F9B4DB979E922BULL
        },
        {
            0x3BD37CEED698AA73ULL, 0x1B5A61BD16B1BAD7ULL, 0x2FADC702C7DBB714ULL, 0x6463F3628113761AULL, 
            0xF49D36CB2CCA3777ULL, 0xAE1DBBF28BBE9664ULL, 0x0587B1DE4A509E3AULL, 0x69193989DFE0E825ULL, 
            0x05D9458D16C245E4ULL, 0x48065E36C6FA25ABULL, 0x14B5F21CB8CEB409ULL, 0xFAB15D0B480C1DC5ULL, 
            0x041686278D0FFCCBULL, 0x22335B5737453007ULL, 0xD6F01575E38895FAULL, 0x9BF6AE0D82E8A6C3ULL, 
            0x04C91F27A134D65FULL, 0x1AC2409AEAAF6E96ULL, 0x6D72851EB1362396ULL, 0xD574530D79143AA2ULL, 
            0x51095C28AAD78B69ULL, 0xF0C9FE964BCB5A72ULL, 0xB0433CF1399FEE47ULL, 0xA8C6A53084EB5F3FULL, 
            0xEC37122896287131ULL, 0x886BF01FBB176B21ULL, 0x5E70B65C878B3CFDULL, 0xB5FD1BDDB34ABA07ULL, 
            0x2DAA5EC83F3371CFULL, 0x6B59EACEB22222EDULL, 0x9F996D8F3182122CULL, 0x061FE261FBA5A829ULL
        },
        {
            0xBC4640168A242955ULL, 0x35A9F56B9D80E43FULL, 0x33F400B5926055BCULL, 0xEB6EADDA17607D0EULL, 
            0x9906263F61565C9FULL, 0x073A192E64B82996ULL, 0x68E134E69FA5C996ULL, 0xE705F443358D610BULL, 
            0xC325B4E8B332C626ULL, 0x47B0D7863F88B998ULL, 0x154D48A4CC53F8ABULL, 0x1291410CBED4A9F9ULL, 
            0x4F5CD64E3247F524ULL, 0x167CAD1F0B4AC7D2ULL, 0xABD2CFFC7BE51A8CULL, 0x2E58803F3F8E4F71ULL, 
            0x831A6FEF2A7E9BB2ULL, 0x6518B1315F9CED35ULL, 0x957B0E13CAE1A503ULL, 0xF7A7E6320350FED1ULL, 
            0x8CD0245F5BAF4586ULL, 0x87B79E953AF862F1ULL, 0xD35FF747C7112B35ULL, 0x980D8681A754ADC5ULL, 
            0xB6F3204F0281D382ULL, 0x9236F35FDAB1A290ULL, 0x3803C4F05D86B9F5ULL, 0xD86E4FB5CBD9B4AAULL, 
            0xEC4ADFE2B98EBE4AULL, 0x255603E15998CED8ULL, 0x5FC0D9C766A733D5ULL, 0x572D80B3A51EC874ULL
        },
        {
            0x62E671CFBBA66FBEULL, 0x2E7A616CAE55DF75ULL, 0x694AC51D226BB737ULL, 0xCB9D635D197580DAULL, 
            0xC612B16FEDA05B82ULL, 0xFDD6D16AD1EB0AB7ULL, 0x0AFB1D589D30461CULL, 0xC8E178CF2AB75BEBULL, 
            0xB1CB459AED7F8E6FULL, 0x4D561D3D46BC5B83ULL, 0x035F2561A3474E10ULL, 0x89B8550E3B01A92EULL, 
            0x283B774FB3F2FE57ULL, 0x096BFCCC1E3E8561ULL, 0x880CBFE404438333ULL, 0x84A3C2A075836EFAULL, 
            0x54FA5AEA20C37C04ULL, 0x779170A99188C1F2ULL, 0x59ED96829A7DED84ULL, 0xA8FA0A7E19458704ULL, 
            0xC1497F3ED217D9B9ULL, 0xB6E1B98DB07862D4ULL, 0xE2C54FA4CAECED15ULL, 0x9EF9576E1D0BD847ULL, 
            0xC0C56A12205A8F50ULL, 0xECBD9EF1E681AF41ULL, 0xC2CB94951CA89915ULL, 0x372FC6588F1135EEULL, 
            0xC66F0E888F75CD5CULL, 0x1EC16FDBA0F9148EULL, 0x1B7E0CF649F0D3E9ULL, 0x5883BDBD79C846D2ULL
        },
        {
            0x8E95DE75B7DFB7F8ULL, 0xE3C7DE9D6EC1DFBEULL, 0x8BE57CCC372D7EF9ULL, 0x5B4CCEC5DC039401ULL, 
            0xCEB1FB1227EDDEDCULL, 0x7A12A9D838AD29B3ULL, 0x6DE82BDA0E4A2AB9ULL, 0xC8022E2CA0E0450DULL, 
            0xD12FDAF553FBF765ULL, 0xAEA253AB6FD872F1ULL, 0x6886ABA35CC77714ULL, 0x2E295F692FA9C0E8ULL, 
            0xAB2131CA72355C3BULL, 0x1E9A97A381D5B1E7ULL, 0x7DAB8E88EFD3186EULL, 0x257A4414B6BA9701ULL, 
            0x71B5EE5568FE6D5AULL, 0x855030934F1334D7ULL, 0xEB602BCBEF8CADDAULL, 0xD0C8CDA1A3566701ULL, 
            0x747648DD56ACEC22ULL, 0x050E4FE3DFE4237AULL, 0xBBCED98D285663BEULL, 0x7292A4D2E4A585A8ULL, 
            0xBCBBBFA98AD5FA8AULL, 0x73D2E6410D713500ULL, 0x6B035FC8588A9B3CULL, 0x54D26865A868720DULL, 
            0x0086774BE1D3F885ULL, 0x0F6242F4533AD5EFULL, 0x3977397DC51A40F0ULL, 0x270714C35FD47141ULL
        },
        {
            0x0EA402E93DBE8053ULL, 0xB00DA7695B757860ULL, 0x31FD449EC3F171CFULL, 0xD6C2B35756289FDBULL, 
            0x0D1B1DCF1719EB11ULL, 0x243F04D8E1FAB21FULL, 0xD6301911ADFDC8E8ULL, 0x73DDAA3743214F34ULL, 
            0x51457620A948A47AULL, 0x0DC15FB3BC0127FCULL, 0xA179EC8991459B14ULL, 0x8B4AFA6FFB7EAF45ULL, 
            0xED38397560AE01ABULL, 0x8A4F0CF7DA32D700ULL, 0x057D810C9CDE8583ULL, 0x8B1B84795929E2CCULL, 
            0x76872FE3AD560A09ULL, 0x258DAC8F492C1304ULL, 0x8D4024F60BC5826BULL, 0xB62AC03AFA959380ULL, 
            0x4640623B8C240C1CULL, 0x428DA416AC987EEDULL, 0xCD16D710488272FEULL, 0x490D86442849CA3FULL, 
            0x94BCDD11ED00814DULL, 0x53A272B272E4F9E5ULL, 0xA2FA99AA3E7AE936ULL, 0xABF28C9826012A0FULL, 
            0xFD67B7B88BF078DEULL, 0x36CEADC4B56F376EULL, 0x157CB9A1AAA11F3CULL, 0xE60836856807D86CULL
        }
    },
    {
        {
            0x878708FAD192C144ULL, 0xA1A729C1728A3DD7ULL, 0x57226130982F883FULL, 0x5A6057D8EF93EE79ULL, 
            0x8AA02E5011BE5DEAULL, 0x729B98244A614274ULL, 0xD17B6551BA09DFE8ULL, 0x554FDF4723DEB847ULL, 
            0x6068C29BCD1DDEB3ULL, 0x8E3ACC7292EF153AULL, 0x7E44034A2513E6F9ULL, 0x76FD7D64B605937AULL, 
            0x17C486B847E5F382ULL, 0x68314C5DB6503DB9ULL, 0x4116B77A18479BE9ULL, 0x4853AC1044285353ULL, 
            0x5E24D6D6EC06E1A1ULL, 0x87D378EDD988B262ULL, 0xE11AFA648772EAA5ULL, 0x8515704F73A360F8ULL, 
            0x424A53EE8AA53191ULL, 0xD52486D251E4A246ULL, 0x5A63100F1EE0DD36ULL, 0x05CAAF37C94C9149ULL, 
            0x0E181D7D18A9BD37ULL, 0xFA4EAEF25754F8D5ULL, 0xDC20133DD62E87D2ULL, 0x364A4452445FAF34ULL, 
            0x86CCCC497E5CEDEBULL, 0xD751F62311F44DE7ULL, 0xD3154B07370D42D2ULL, 0xF3044EF9348506D9ULL
        },
        {
            0x6F84C0E9E90D3DE2ULL, 0xD96D368F471E4FDBULL, 0x026C0FD5FF840EBCULL, 0x370FAB82337B899CULL, 
            0x8537702F3B236CDBULL, 0x37A3412AF8E5C554ULL, 0x4D4A8E4A250F099CULL, 0xEE96F0BFCF3B35CEULL, 
            0x7798E53335B9559AULL, 0x10073A92A1295DEFULL, 0x6A4C58CEF4C68FD1ULL, 0x49CFBEA97645F0DFULL, 
            0x5F3E70E894D64793ULL, 0x12B1AC63479304D7ULL, 0xE1E7115208073602ULL, 0x9656BC22B40E92AAULL, 
            0x7D343B5D6CC88269ULL, 0x6023D5DE011C9C78ULL, 0x96D0A4DAB9027BF3ULL, 0xE87C29BF19EAB1D9ULL, 
            0xC3D935202CA2D252ULL, 0x5FEA3075B4E83E0AULL, 0xD8FD8CBD12AD1802ULL, 0xFF9A45A3BF6E6E05ULL, 
            0x880D7E87F1C9E919ULL, 0x82F6443D9F8CD247ULL, 0x276DB85F400283EBULL, 0x3A9BE527003525BEULL, 
            0x89B4741B80A2C3CAULL, 0x4871C300297F469BULL, 0x7408EF20A3017562ULL, 0x5F50B66B3DEBAE2EULL
        },
        {
            0xB75964106387DD36ULL, 0x748BD7DFAB5C9274ULL, 0x1CABF3961F46BC90ULL, 0x6DCB2B7391DA58A6ULL, 
            0x13529C3A23FA2D4EULL, 0x4BF8A9C3B798E680ULL, 0x44A7EA27531B3572ULL, 0x5652AB9A78E6572FULL, 
            0x1736B6CFB5591733ULL, 0x89FC56CC84047CB2ULL, 0xF4EAC387F0685154ULL, 0xB150A17848A04A78ULL, 
            0x24150352D456EEC0ULL, 0x1D1AD0DD3732B453ULL, 0x20FEE140039DE5C3ULL, 0xF1BE595880A520E2ULL, 
            0x3B70AD2C817F3C4EULL, 0xE2CC69281254CB21ULL, 0x52BD34EFC39365AFULL, 0xE792E3BA8AE3F111ULL, 
            0x851A31B8CDD504BBULL, 0xD2599BB61D462669ULL, 0x09C6F587A6D0D2DBULL, 0x94E34721B15C7F3AULL, 
            0x4D821F23AC3E763BULL, 0x60AD535D7EF03C81ULL, 0x3F86D5B755B47058ULL, 0xDAEED878B663AF0FULL, 
            0x2BA5DC43BC3C3A7EULL, 0xB465F7F7D57C44DCULL, 0x9A3B2236F6129728ULL, 0x30F954A8DB2671ABULL
        },
        {
            0xD0CFEA462767684BULL, 0xDBCB39EED02B59DFULL, 0x4A604ED748DF57C9ULL, 0xE2599FEC12C61635ULL, 
            0x4C16D3183C789ABEULL, 0x9C23D222E3F7BC9DULL, 0x1578518D1DBD4778ULL, 0xE1421E80E05F6F63ULL, 
            0x17EA0D1D32D764E5ULL, 0x8F1A6D4A42050FEDULL, 0x13801337E0C85427ULL, 0xDE4DE95F4E7FC681ULL, 
            0xFF0D0B4900207765ULL, 0x7E3A45EA13385E3AULL, 0x750501A5ECBCCE34ULL, 0x5F35C2AD75BC9DCDULL, 
            0x333555E172BF7ACFULL, 0x8190587034D69885ULL, 0x730F159D91FC3A9EULL, 0x0A959AB2D4ACEF1DULL, 
            0xB093FA08B5A23066ULL, 0x8C30CACC89839E94ULL, 0xF7911008BF794FE3ULL, 0xF424D8A60979DAD8ULL, 
            0xF4EFBAC9D0B47CB0ULL, 0xA0BAE6121617DF75ULL, 0x43981B9E3FCB8CACULL, 0x133A38F810915BADULL, 
            0x9F489B302A92612EULL, 0x52FCC6F0FBAE2193ULL, 0x687AC5FF89B0E31EULL, 0xD81EF8606860A9C2ULL
        },
        {
            0x31396A8089FEF323ULL, 0x8A7DE192091AA943ULL, 0xDD5CDA7BE1B3948AULL, 0x9DEF0650D37819C9ULL, 
            0xE706145363435BD9ULL, 0xF42E0BCB0ECE7788ULL, 0xEFA6F2AA94B76429ULL, 0xDA6464C45577634CULL, 
            0x7FE636A5250A288DULL, 0xED515975D29B2C42ULL, 0x0525DFE6211EEA0BULL, 0xB38D676F372AE259ULL, 
            0x25E9FAA61EC384C9ULL, 0x0FBEB40FE893D7EFULL, 0xC14EB55C69D492BBULL, 0x603ABBA98A4B8372ULL, 
            0x3FD4ABFD3FD07946ULL, 0x9FC8EC19A6C0CFABULL, 0xD2ED2DC79D623607ULL, 0x816B9B6D5050BC11ULL, 
            0xA400E778282CFE38ULL, 0x28A569C7AE44184EULL, 0x1C2864B5175213F7ULL, 0xA40B751901129352ULL, 
            0xBB13DB1871EAC7F2ULL, 0xA19E12B502FA0E63ULL, 0x21D77382135C9709ULL, 0xF2ED06F29BEFF6FFULL, 
            0xC474F318520B2EB4ULL, 0x2B3EB8136DD14927ULL, 0x2C9601FA65C8D090ULL, 0x0468A6578369197FULL
        },
        {
            0x52560B068AD133CEULL, 0xB9F75FD5313B0349ULL, 0x5A50B8B5D867DC83ULL, 0x700E21F7D36B9B90ULL, 
            0xB9633AAA1B6B4C70ULL, 0x2D1F9DAAA27467CFULL, 0xC513C062419BF1D0ULL, 0x19E03942ACD11264ULL, 
            0xCD5496F3CAE4F50BULL, 0xF277A0D76A320FD7ULL, 0xD506C22B3D982A8EULL, 0x37CB9A1A2ACCC430ULL, 
            0xC9EBF5584A637957ULL, 0x96E99A63F437D2F4ULL, 0x0EB094DF5A429E4CULL, 0x4FC58196DE67BC1AULL, 
            0x26F883800C412C07ULL, 0x032EAE00B726337FULL, 0x017398DD1E3D9180ULL, 0x4EBE40EEAEB56F5EULL, 
            0xA0D5728B65415BD4ULL, 0x1C1229D05ED62BBFULL, 0x177FF44570872569ULL, 0x9332424B63A4082CULL, 
            0x2054204AC6590D14ULL, 0xA189552A36DCC5C5ULL, 0x68D0A60D90EDB7DCULL, 0xCF7261576D78ABF7ULL, 
            0xD87DE7973AE38764ULL, 0xF062B68DD151E47AULL, 0x485AE83D1217E69EULL, 0x8E12B36C3D61E8EFULL
        }
    },
    {
        {
            0x442F15AA66235441ULL, 0xBFC646BE131D0BF9ULL, 0xDFE7DF1BF10C27E5ULL, 0xD7C2011940E3C5BBULL, 
            0x57E970AD40FB6968ULL, 0xDB33BDA2FFE24B4BULL, 0x666F8F5545996F53ULL, 0xE154842BA538F340ULL, 
            0xFD2F6A242F2763A1ULL, 0xCB525AADF5D14BE4ULL, 0xD47C890E2C0D87A6ULL, 0xF82AD107184C1676ULL, 
            0x76895C237E3F9C3BULL, 0xF63644CD6E6BCC82ULL, 0xBFB9112A390B8FABULL, 0xADB45E28A52B3559ULL, 
            0xDC707E808D9F0DCAULL, 0x91F219E670F88F0CULL, 0x9A1F529C1B6647A6ULL, 0xF13E7ED525B3D9C7ULL, 
            0x02A0B9C0ED188391ULL, 0x989CC23E981D047EULL, 0x99E0601AEA83284DULL, 0xEB30C822E04D3603ULL, 
            0xF95E80DC18640477ULL, 0xB882E8AC28941525ULL, 0x4D33DE2EB4FDD22EULL, 0xC5A428E8E8126644ULL, 
            0x1A3ED231363BCAE5ULL, 0x6CAF30619DAFDD10ULL, 0x47AFF2AAB1DF855BULL, 0x14CF63217410A927ULL
        },
        {
            0xB06D888F591BECF6ULL, 0x1AD49BCFCA3DA488ULL, 0xF192CA2D5E36C98DULL, 0xDD8A73AB1E34F1CEULL, 
            0x2D3510D5F19959E4ULL, 0xC3AFCAB1C5F38CDEULL, 0xDC2B09D20FF7182DULL, 0x9735AA9541C5ABC2ULL, 
            0x4E191C234A71BB93ULL, 0x493C1D533F68CFE4ULL, 0xEBBBEEBABC57EE60ULL, 0xE26E17CDCB983137ULL, 
            0xBB12BDA5D6B0B2DFULL, 0x8E57985B969212BBULL, 0x96FCCC8FCE082815ULL, 0xFA094CDD0932A7ECULL, 
            0x19CC288D3713AD01ULL, 0xE528D7780AAABA54ULL, 0xC7C9CD9E172B07A9ULL, 0xA58E68782BA2A171ULL, 
            0x396B0903333F7407ULL, 0x8277ABEC12CDA506ULL, 0x95E0DE78E9A9B36FULL, 0xCF3875E050236421ULL, 
            0x30256F5B053CC747ULL, 0xB97B8DBBDB5F55C6ULL, 0x0ADCDF5983438AA4ULL, 0x50592588B2446CBDULL, 
            0x89840977AFE9D6D7ULL, 0xEC210A0C8D92F909ULL, 0x199ACC49917BEBDBULL, 0x0C00A6979E15E4F4ULL
        },
        {
            0x8DDA1AC9FCE32A2EULL, 0x38A7A65DFC2CE174ULL, 0x153C69FB89364F3DULL, 0xBB45D3A2527163E9ULL, 
            0xB496DF8E77D2376AULL, 0x8E9A6044411AC654ULL, 0x8F804106C7DCC366ULL, 0xF83A73DBA89B1298ULL, 
            0x77D9255B3F30AE1EULL, 0xE417463C6F445470ULL, 0xA4811BB595A225B2ULL, 0x4919187413AB2AA7ULL, 
            0xAAF50C0F0D5E2F64ULL, 0x46E4E506915577DDULL, 0xE999C733297DFDB5ULL, 0x2C281876BC4A5B3CULL, 
            0x8263E6638AC7BEC4ULL, 0x837DFCF1DF62FFC3ULL, 0x89CBCC2B7A96EC9DULL, 0x13EC145C39009E79ULL, 
            0x325FDCAC32CCF4B1ULL, 0x0C1A3C15EDE5B8EBULL, 0xC7CB50B51740DADAULL, 0x8843F89FBFABB493ULL, 
            0xA4A91B078E5FD557ULL, 0x2782419A02176243ULL, 0xC797A03B98EC1C6BULL, 0x14FC1D903C2D6C58ULL, 
            0x7A95CE5E7CCB04F5ULL, 0x2195E27545262319ULL, 0xFC780B9CCDB0022FULL, 0xCDE751CA0867B4F2ULL
        },
        {
            0xDDBADA2AA1F25F6BULL, 0xF531BAEC6759DF86ULL, 0xB0A72649521B436DULL, 0x36675D9DD097A726ULL, 
            0x5F6886EB1FB586B8ULL, 0x1967A444BBF287D5ULL, 0xA296CB959A2CAFD9ULL, 0x7D422AFE9547A998ULL, 
            0xAD5AD1AC50BB4913ULL, 0x548A125BA720FE4EULL, 0xF1C6B0D82145C3F0ULL, 0x9BA2969138F03980ULL, 
            0xB89A68ACDA4466AEULL, 0xA37866ABE6CC6BB2ULL, 0x2B738C7F4A011B1AULL, 0x4B4F4E75C45A7CEFULL, 
            0xD1C5AF069E9E27FBULL, 0x21BA2785AAA1C1F1ULL, 0x702DBC1A9ACC3450ULL, 0xB15C3EF0F1D0F8EAULL, 
            0x92CF9FC10783A041ULL, 0x7DCE7E55F02A00E0ULL, 0x0A3905D8BB614EA9ULL, 0x3E0F4B3CE32F0CADULL, 
            0xA10F30647621B3BAULL, 0x8736145A904D68A1ULL, 0xA0D46B47E8C70162ULL, 0x53E77F33F919D62AULL, 
            0x78FDEEACB541E408ULL, 0xF73C034B44915F53ULL, 0xDCD9D15D184F075EULL, 0x818A214310235BAAULL
        },
        {
            0x8D9471DC1E220E8BULL, 0x4270D8E78708A7AFULL, 0x875F4E0E398A671BULL, 0xB1654BE19A6DC774ULL, 
            0x1FC08F167CA37266ULL, 0x8257CBF65BF1D693ULL, 0xE51F8D60975AC9DBULL, 0xE0A5F6C0C7006753ULL, 
            0xD23F21BF31BB3648ULL, 0x16D2FCF12674E8EAULL, 0xA5DE1289E3563DE8ULL, 0xD4ED60234418EF5CULL, 
            0x83D84CB97D40F375ULL, 0x7E0CB280BE11DC17ULL, 0x6CE14DD670454BADULL, 0xB90F66AE0AA970D0ULL, 
            0x18AC99C1CE32280CULL, 0x20962BF1399AEB68ULL, 0x7B4724D97E461391ULL, 0x845C6122DA6DEB5FULL, 
            0x07D124137340816FULL, 0xCAABF27093620DACULL, 0x4CC2D05B7F491013ULL, 0xF7886CBB0B34CFAEULL, 
            0x755392501464DE3BULL, 0xC2D64F20EA596CB7ULL, 0xC9E1B49D72291B8EULL, 0xEA5667111F2B42CFULL, 
            0xE87F9E0F7475833CULL, 0x0841951A6C26F178ULL, 0x5BA05B32A862A734ULL, 0xA0DE2D45FBDFE528ULL
        },
        {
            0xBC2093A24314B85AULL, 0x82DA70CD57238E87ULL, 0x457DB2A1CD3318D2ULL, 0xEE036FE88A2DC455ULL, 
            0x18D0E962C8642189ULL, 0x178406445FA003E6ULL, 0xA67B8152BD9BB0A0ULL, 0x073005149E942F08ULL, 
            0x77BEA0AA0D48D99EULL, 0x56BCD103D6A6D09BULL, 0xEC58DB18AD59B3A1ULL, 0xBBEA7D4633AFE47DULL, 
            0x126768BA397B3AE0ULL, 0xEA26F92EA197D9D8ULL, 0xF40FE4949AD8D418ULL, 0x2AA67BD2C2A8DC79ULL, 
            0xC56EF557ADA22989ULL, 0x6CE3DCA7C8312C46ULL, 0xD928E14BDECA88A6ULL, 0x071AE9AFA726978DULL, 
            0xEE3F6C4D4B0508B5ULL, 0x2F8DB0EE04E7F738ULL, 0x32372E3E90E86C13ULL, 0x9D0F4135BBD596CAULL, 
            0xEF7762F2B9376FB8ULL, 0x769392C7A8485C99ULL, 0x7C92274CF55CBE7FULL, 0x47A6589E5D46910AULL, 
            0xFB86FF32086507BCULL, 0x551F77BE8551231AULL, 0x13C95F95EAF1170FULL, 0x512BA68518088FB9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseAConstants = {
    0xE7D8060EEAD074F8ULL,
    0x985E1BF070D89A00ULL,
    0x6EDE38E4A690622EULL,
    0xE7D8060EEAD074F8ULL,
    0x985E1BF070D89A00ULL,
    0x6EDE38E4A690622EULL,
    0xC2EA0E2C5F7E5990ULL,
    0xCF54ED1AF7B86A6CULL,
    0x2F,
    0x80,
    0xA4,
    0x2D,
    0x96,
    0x50,
    0x1F,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseBSalts = {
    {
        {
            0x2F25C4895D75EEAEULL, 0x8F756FE9F0A654F4ULL, 0x1A6933E0E8BAAB31ULL, 0xBF6CDF84CF509559ULL, 
            0xFB1C13B26C8B2FF8ULL, 0x53A33D1E270F1257ULL, 0x71550D8B565ADBD1ULL, 0xF7506A57CA388440ULL, 
            0x9A280C0A7C611020ULL, 0x52E5A378714C592AULL, 0x59C2A7F8EFD04603ULL, 0xF6A99823842DBA8EULL, 
            0x32A1562B4D0D5CBBULL, 0xB2509BA5EF95E880ULL, 0x6E599434CAD5B161ULL, 0x5158997BD79391AEULL, 
            0x20338F3A29ECD171ULL, 0x6CABDF384D74975EULL, 0xB5E64EE4B876EEEAULL, 0xB17F43CACD49D4B1ULL, 
            0xFA806DBE2F33404AULL, 0xE052C6D61279718BULL, 0xB8B21A92BA6EC58EULL, 0x1B541DDAE7D90820ULL, 
            0x86CA39014B6138D9ULL, 0xB7BA2B876A03A49BULL, 0x9657C7C9070F4653ULL, 0x28057F266106CB84ULL, 
            0x3EB88AF2D65C557DULL, 0xEB938B18D90DC8F2ULL, 0x596232EE03C5F181ULL, 0x97EB70557B91C176ULL
        },
        {
            0x5BF68B1EE9453237ULL, 0x9A7C726D024EEA10ULL, 0x369623A432B08F89ULL, 0xF2C28469B168898DULL, 
            0xE76ABB61F04AD947ULL, 0xE417AE304E297C65ULL, 0xFF41B1AF2D82765AULL, 0xA404B50CDA667C5FULL, 
            0x00E7EE14C10351F5ULL, 0xB53EC1C70BA26560ULL, 0xD716D8CB29A18CF8ULL, 0xF85CB35A99BDEFA9ULL, 
            0xEF222A821D6EFD41ULL, 0x718F805996608F5FULL, 0x8437775C513EDCB8ULL, 0x18C8E1A5448D70DBULL, 
            0x0C2B4BB4F65328C2ULL, 0x1A79CDA7AF9A0C73ULL, 0x2537362FE53C874DULL, 0xA055E63B1302F7FAULL, 
            0xCB4D582A37D40D98ULL, 0x17DCDFE5E115823DULL, 0xC40E384CF3CE1F0AULL, 0xB0CEB7D6D7F8BB49ULL, 
            0xE04046125CF427F7ULL, 0x12F02EDA0E8C8534ULL, 0x2818B5F80D99E13FULL, 0x915DA6795E35017AULL, 
            0x1393B1BD0C9B0330ULL, 0x52FE2A8B86941487ULL, 0x2EDBC058B8FB21B2ULL, 0x57C12085149EEAC5ULL
        },
        {
            0xF9BDB296FF561AA4ULL, 0xD51B98A0F5884E3FULL, 0x8CF6575040116069ULL, 0xC72B564150BE0FD8ULL, 
            0xD3D2BDFCE6792570ULL, 0xA5C67E79FB4CAD33ULL, 0xD3FFE99C12087F4CULL, 0x33F62B3F7D19F3A1ULL, 
            0xF4E3E6A8826968FDULL, 0xDF54E1DFF6DD4384ULL, 0x1D41BAC306C381FAULL, 0x91D9DB6A3370BFF7ULL, 
            0x3D2F8A242AA7D206ULL, 0x9D17B14CDE11F6F5ULL, 0xC408CA538F4ECDC3ULL, 0xBA3346B938EC4892ULL, 
            0x5BC6D08E71733677ULL, 0x2A79C20F2F2D76BBULL, 0xAB0C03E68B9BABEEULL, 0xDFBFEAEDBE6C4F19ULL, 
            0xF685BC22D66E089CULL, 0x633365AF0875CF43ULL, 0x065989FA59ED71F5ULL, 0x289BBF2B514E3FC4ULL, 
            0xFA83902C8FBD0895ULL, 0x493DDDFBA8E3F876ULL, 0x063AA676A49DD5D7ULL, 0x1378CF06871E5E5AULL, 
            0xD101E0333D2C2397ULL, 0x56A6ED8CCA96B99EULL, 0x8CC298A309EC5DD7ULL, 0x317E321419E00F3DULL
        },
        {
            0xBF7107FE30091D30ULL, 0x8252CC0848A8FA3EULL, 0x57A3AC28CFB37BEDULL, 0x58F6F52FD7AD3DE8ULL, 
            0x205B8C9A863D9978ULL, 0xFFC5B24DDC7FA3AEULL, 0x0029CA988C49196DULL, 0xF465C01F23F5BCF0ULL, 
            0xFD06C439C01625C7ULL, 0x6C96C157494ACE15ULL, 0x58B58A13EB1BBF1FULL, 0xB6AC90DE9E6DB3C2ULL, 
            0x5EE0C73E364DD6FCULL, 0xE62C594D53BE8384ULL, 0x298D5BFCE52103A3ULL, 0xF2B3DCA6B8F4A229ULL, 
            0x58E5AF97F0443C82ULL, 0x0E1C24600A5A7B71ULL, 0xA611EFA5C3E11EAAULL, 0xA615392E05E39558ULL, 
            0x96A545B49E32676CULL, 0x1604A12F6CF1B50DULL, 0x401DFF2064E5184DULL, 0xDB7C13A1CDD51516ULL, 
            0xB840F667014BAA16ULL, 0x1E00F49C313AE657ULL, 0x609380D4FAA129F9ULL, 0xD1A51481065DA2A5ULL, 
            0xCC3599163F877C93ULL, 0x063D87FE91D20BDFULL, 0x3AA8B00740AD6B9FULL, 0x226F7C7DF63BBEC5ULL
        },
        {
            0x0DD410F7250E89A3ULL, 0xD623D71097A286A3ULL, 0xCFFB4DD7F5E24D64ULL, 0x413CDCB93C37CA5AULL, 
            0x4B26E3D5B8D4DECFULL, 0xE3D3C4588BCAEE23ULL, 0x1FA3F7B4EEE29CDFULL, 0xC7F8C421CEE7AF9DULL, 
            0xE7EA904F177C6603ULL, 0x15B8E860AD7A7E37ULL, 0xD52B1A252E47D9C4ULL, 0x473D46C8A7B92C09ULL, 
            0x8F8956D6F8A40F79ULL, 0xEE70A7558586C49BULL, 0x7353D3071BFAE29BULL, 0xD361A2AFD8FA09D2ULL, 
            0x73512F7E46A23AC8ULL, 0xBF718CE4103484E9ULL, 0xB9DF5F8D1A430AB9ULL, 0x87FC03B5C6F8A657ULL, 
            0x20B8BBB67D82C4FFULL, 0x51567B50F520C852ULL, 0xA383DB3CA346B21BULL, 0xD293D996CFEF550AULL, 
            0x27D9DF7B2A827B85ULL, 0x735A468794BC5C3EULL, 0x6EBB4284CCACB53FULL, 0x9C6B31515DAF8DCCULL, 
            0x26E23CDA9A84D8C4ULL, 0x1D1DCDE7858BDEECULL, 0xACDB82F94E74E511ULL, 0xADB202752D225723ULL
        },
        {
            0x6F46F9531D1B17FFULL, 0x1B1233165B04A2C6ULL, 0x11F34C1B6CA3F439ULL, 0x153FF9C68AA9BEA8ULL, 
            0x873281B9A0CFACAAULL, 0xB6D5A05F8159019DULL, 0xBB5F427FDF7315BBULL, 0xA6E36E7C215D05CBULL, 
            0x921F57AEB8594D36ULL, 0x2D78DE4BF42A0612ULL, 0x84E451E365BD6163ULL, 0x8D6B1419FC902BC3ULL, 
            0xAADA7BBA4A693036ULL, 0xA9CA201BFA2E3E95ULL, 0x457A522BB5B01B81ULL, 0xB1A74988DEB9463EULL, 
            0xED84F6367974EBB1ULL, 0x5013E98485823023ULL, 0xCC3B8E7A52927053ULL, 0x21E996F51FCDE0FBULL, 
            0xC30F388848FAE702ULL, 0x6BB45A2E0FE3500EULL, 0xFD71914E08B1322DULL, 0xB25DFACD41FFEE24ULL, 
            0xC4E3A1B4F424887DULL, 0xA2D36E1386A19D18ULL, 0x70D26B8EF9D12267ULL, 0x1D6A17FC9C8E424CULL, 
            0xB7690AE2EE3086A1ULL, 0x9561F3B6D4F8614AULL, 0xCFD9B38861E53167ULL, 0x7568D50366B2B98BULL
        }
    },
    {
        {
            0x2188A45BFA59587CULL, 0x0587CA8C7DBF8E45ULL, 0xB8E443294C513A73ULL, 0x28EE84BDFA52FDA4ULL, 
            0x5AFC036B39F35930ULL, 0x48BBAF8A51D558A0ULL, 0xABD7E9CAEC108662ULL, 0x947C3D6848205D0CULL, 
            0x9DEAA2E45AAE0369ULL, 0xFD2BAB906A145CABULL, 0x0DBA633F66EEC989ULL, 0x5519434A05BC88B4ULL, 
            0x1E1552993F1D07FAULL, 0xAE7996869E59CE65ULL, 0xE3C331BF102FA2EDULL, 0xD57909B635D4EECCULL, 
            0x575D2CA83324EC08ULL, 0x41E96201F92CB513ULL, 0xFCF7D4BD67F6F3A4ULL, 0x47B7841C8895DB1AULL, 
            0x8C574CEEF656CB17ULL, 0x3FF9E4530C9EEC2EULL, 0x23CCA438C0BA571AULL, 0x3EC4F50F7C7FC88AULL, 
            0x77C87ECB986BC2C2ULL, 0xD2CB670E18C60C4FULL, 0xA0698B11E2B22E3DULL, 0xB67C8567752E8A0AULL, 
            0x61C71711B5E5E916ULL, 0xB6144C33542F3B1EULL, 0x9E15B8167989E9E3ULL, 0xAD354DF79109D36EULL
        },
        {
            0xA34FA55485132693ULL, 0xF76BC6E5DBE64826ULL, 0x71D11D12AF5340DEULL, 0xC28BC72D5C28778AULL, 
            0x9FA8FB57525326D1ULL, 0x74FF67CE4606390EULL, 0xD77AF26926F00068ULL, 0xAD38B88609EFFFC7ULL, 
            0xCE10BA17CF81CCD4ULL, 0x865DB0966AB6347FULL, 0x16A60B9C1518D52EULL, 0x2F5D1D421997FA0FULL, 
            0x7A2EB44DB58C7A88ULL, 0xE9D92FA16E4A93B2ULL, 0xE7E5F1A8F3F406ACULL, 0x8EF3E014166F168EULL, 
            0x089DEEAA0B08EFEBULL, 0x49D100A7E96E9781ULL, 0x4B8D86AAF866AE75ULL, 0x3A51FB464D7A0200ULL, 
            0xC4BC7BEB359D8198ULL, 0x714054B7B0D04FE0ULL, 0x720F83EDEAD9A64BULL, 0x87D3E6948486DE9AULL, 
            0xA6D72AACCE6B2183ULL, 0x41ABC1709CD5E3E0ULL, 0x8CBD5CD4BDFFA239ULL, 0x116B9DF6A60CA288ULL, 
            0x70288871FCF3CBE9ULL, 0x637BB603E8F8D102ULL, 0xDE020CE5B103CE82ULL, 0xB47F8BCA20AD93AFULL
        },
        {
            0x06E564A8AE22D74EULL, 0xBF37CEDA354849ABULL, 0x52FD85C70A8C83F1ULL, 0x2F32BD7AD950AD60ULL, 
            0xFCED3EA6A5556F15ULL, 0x78AC6D1C8E806BC7ULL, 0x04DDAC7F39D9E035ULL, 0x6BE5E866BAEC2624ULL, 
            0xDA4CD338BE23ADEAULL, 0xDD6E94909AC492FCULL, 0x92F6177EB565A8FEULL, 0x911FA06A150AB86FULL, 
            0xBBDEABC19E59FE3AULL, 0xFD5DA9F5CDF270A7ULL, 0x46A95810EAC908E5ULL, 0x9740C6B91112F7AAULL, 
            0x3EBA6001140544BFULL, 0x5CEAB673A670906AULL, 0x5458B06895653881ULL, 0xB1322A4ACEADD89FULL, 
            0xE1B352DA1B4333E1ULL, 0xBFC93C73F37AA644ULL, 0x31D75CF5A2A8BD66ULL, 0xC85E55AC197BDBA5ULL, 
            0xCB5A2B25BFE90D33ULL, 0x8A00DBC440C7BDC4ULL, 0xA3390564567F0DBEULL, 0x12337D2CA90A7B7DULL, 
            0xB925307406494B99ULL, 0xF447CEA669998BB5ULL, 0xC0E55DC4976A0B52ULL, 0xD74FE6C57621AE52ULL
        },
        {
            0xE57BDE76E77F310EULL, 0xD48E66FDD2D5BB2CULL, 0xC5A9830DDB4663A5ULL, 0xE70E3F5F1AB8E364ULL, 
            0x2541D728B768A228ULL, 0x69D3DA64A724FB8EULL, 0x946CDEF42C4AEE73ULL, 0x1247602F44C335F4ULL, 
            0xCD2CBAF1E3EDD0C4ULL, 0xF7F0735F7609AC85ULL, 0xEBA088F321B8F8ECULL, 0xE7494FCFC5B32CDAULL, 
            0xE8F023D6D2F78C8DULL, 0x591F31D1034BD12AULL, 0xAFB72C7EA4A6FA36ULL, 0xEFCA58B806E3E698ULL, 
            0x29D309CADD0054A2ULL, 0xF678AF31FDB3A3DAULL, 0x10F7B34503389E4FULL, 0x9BBB49B556C5A9CCULL, 
            0xF65B81B0EF914674ULL, 0xF71E9129EB47B6E4ULL, 0x6FC4BF2FF100DB17ULL, 0x2E13F6B68CBCF1DEULL, 
            0x315F35998AF505C1ULL, 0xBD4AF3E7DDD9711EULL, 0x22C3CF57479426F9ULL, 0xE5A69C8E717E7242ULL, 
            0x4AE7BD83EDB8D28EULL, 0x9299B905EFC0ABC8ULL, 0x339D5A46A9CC0B05ULL, 0x2C11A7DB9AFF4560ULL
        },
        {
            0xB8A116A96ECD5AD1ULL, 0xB74F35D341C9DCC5ULL, 0x4B6B97D8A27E5371ULL, 0xFEB216754FD95585ULL, 
            0x34F0BF25A45D059CULL, 0xDDBD261C41849C88ULL, 0x263076E19898BB64ULL, 0x5A773451FAB27616ULL, 
            0xCBC3C08A63ABC45EULL, 0x767D0728FE3D8B8AULL, 0x5EAF294CA477C853ULL, 0xCCF2C012D3E2C2A4ULL, 
            0xADAC6E078E0D49EDULL, 0x0AF4E9B31F73F0A1ULL, 0x15F371FE540363B6ULL, 0x4B45955EC858B9B3ULL, 
            0x4FCD9B6B72DA00E5ULL, 0xBF39245BB1BB4667ULL, 0x78B5876D1DD96FC8ULL, 0xFE6A406C77C05082ULL, 
            0xFDD38683ED05130DULL, 0xAF983BBF7DD908D3ULL, 0x3DF9F46C104E9B3DULL, 0x9A476803C8461C44ULL, 
            0xA3B0280D0074936CULL, 0x387F38AE94C325AFULL, 0x8B9F975241861BAEULL, 0x9E0ED408D2E578B1ULL, 
            0x5E8778D0E1AC8BFCULL, 0xC2E830EEA145B0F1ULL, 0xFE835C480CE420A3ULL, 0xF172DE4E1CC89139ULL
        },
        {
            0xB778D8C7399E888FULL, 0x9E383B9487C40EB9ULL, 0x19D8D8060A9AFD7DULL, 0x7A71286BD391CDB1ULL, 
            0x3ECDAD4710267714ULL, 0x3547E15370015700ULL, 0x567EB40754AE7437ULL, 0x649F4C9595EE536EULL, 
            0x53B87CB7A46AB337ULL, 0x05CB2465FC4357C6ULL, 0x354BF121AFE791AFULL, 0x251DB46CAAF9F981ULL, 
            0xA93DDCF5C32D4872ULL, 0xFEEC6EBE7846ECCFULL, 0x47887D6470594392ULL, 0x1405CAA2920745E0ULL, 
            0xDE655D3CE62A298FULL, 0x3473215DD106B580ULL, 0x78D4B2A4F871CD8DULL, 0x44E490C8B32509A5ULL, 
            0x7A5506A55D1AA7B2ULL, 0xE9C5AE5FB9A5C57DULL, 0x167AD0B4391082A3ULL, 0xB174EA1B431B6442ULL, 
            0x694AF31F533BD416ULL, 0x600757D415DC5B6EULL, 0x78AC69DAEC93B8C2ULL, 0xC6D9315AFC409972ULL, 
            0x7D9923CD5C348F95ULL, 0xD12E60457C50B1AFULL, 0x0F6D53EDEAA3E464ULL, 0xDB0117F5BA265C7DULL
        }
    },
    {
        {
            0xA7C1A504F834DD7FULL, 0xDD39BF0C330FB693ULL, 0x6454311D8050A04DULL, 0xA049A3B7A9072A7DULL, 
            0x354117FAC8C0D1A1ULL, 0x86B5E055C5FDE8A4ULL, 0x313974E2C6359306ULL, 0xA802AFA12ED94210ULL, 
            0xA1CAD6EBDED3E4AFULL, 0xC994B19E594C29DCULL, 0xCF70270EFB704409ULL, 0xF03BDFBB0D05F690ULL, 
            0x60557E7CF36E7F44ULL, 0x1812566D5FEDC9EDULL, 0x28B824F2565F279EULL, 0x0B9C9410F5E11778ULL, 
            0x822860F659089428ULL, 0x6D47D0BCB223A610ULL, 0x2E3FEC8FDA1541A9ULL, 0x734E4C612CCF2D45ULL, 
            0x895FFDAF7796D630ULL, 0x3A7C2C8479446ABAULL, 0xBE2533956CCF9577ULL, 0x8BA04DC9B38EF218ULL, 
            0xB965BBC68785E0A1ULL, 0xC90F376B449EC8EFULL, 0xB604419FB5736C7BULL, 0x080A7784B025A957ULL, 
            0x2FA52E73ADBD70F9ULL, 0xE1767FFB21DA053BULL, 0x3EC87487EF1ACE7CULL, 0xA15E0D4E25D41F83ULL
        },
        {
            0xE61F730207AF50DEULL, 0xFDB1ED586ABB5EAEULL, 0x030ABECD0B4B232AULL, 0x717AEE8282CE4A74ULL, 
            0x2ACE43D7B0C679C4ULL, 0x639B679F066F75B6ULL, 0x6328F305D0ABF5C7ULL, 0x9594FB1FEBF3374CULL, 
            0x2652FF359EB1C213ULL, 0xC4A2ADA97A0567A9ULL, 0xEE97EB36A3DD0A46ULL, 0x0B2320296A298A53ULL, 
            0xABA9D64BC5F71606ULL, 0x0022044237D3818AULL, 0x4881E44653FD8497ULL, 0x5A39BBBDE1260369ULL, 
            0x2E1137605D050C17ULL, 0x557EB5F94C2AECA6ULL, 0x6E274445C79CB525ULL, 0x7BE75981A3C12D38ULL, 
            0x8E436DAE3C0FF047ULL, 0xCA5FF32662906F34ULL, 0xC1ED400ABDCF414AULL, 0x173444123B8CAF3DULL, 
            0x342E049E73C8A399ULL, 0x5F8B04F54F5E6989ULL, 0x19D2AB30C2448CB1ULL, 0x143EDA143F37E894ULL, 
            0x234925CB714B6444ULL, 0x8B0ABD3D7D160D05ULL, 0xEE4A11944859253EULL, 0xD7A764A0C40F0782ULL
        },
        {
            0xDF4FCA7773EACD4AULL, 0xB5B139E0CDD9EC34ULL, 0x4B2AE9EEC015FBF8ULL, 0x873879874597E2BEULL, 
            0xC3E73D00320DFEB8ULL, 0x707B039992AF81F5ULL, 0x91587ABB7E9735CAULL, 0xBDA8A9194A7434BBULL, 
            0xFBEEC84588327D46ULL, 0xC48881FB4E6A6DE0ULL, 0xD54029016C499230ULL, 0x238F8EB57B93E812ULL, 
            0x66131F1ACAC0C74DULL, 0x4680EA479139F3ECULL, 0xCE3BD45DCD13A93DULL, 0x5807CD878353B3F9ULL, 
            0x23FABA5BEE1E43FFULL, 0x06FBF584B4D17FFCULL, 0x40C6C9C7B65D6FBFULL, 0x7B0D83EFE4412007ULL, 
            0x4BD67DDD6D1AD8C6ULL, 0x66E3A2E04191FE0AULL, 0xD89F1C40EFADC153ULL, 0x686C7469C002ADC2ULL, 
            0x679A68B9EE4A05DAULL, 0x8085FEA375BC8648ULL, 0x35F193DAF6EF9B1CULL, 0x1CA5772EFB9AEA4CULL, 
            0x55D974B1668B7CD1ULL, 0x6C2282520DD78989ULL, 0x5B9D241887333EE3ULL, 0xB93C5B12597B49EEULL
        },
        {
            0x666665CA94D44881ULL, 0x2361630CDD5E14B7ULL, 0x66628E385D383976ULL, 0x06F1CE2135DA424FULL, 
            0x9A680A38A05A4367ULL, 0x0B6F738B69FD451EULL, 0xA7D09061EFA31C4AULL, 0x9B0B456E6BE31257ULL, 
            0x8AEB3995043FBD9EULL, 0x0D7F214E0B119038ULL, 0xBADD267B49CAE4DFULL, 0xEFE98EAE66CCC403ULL, 
            0x8632E070DA41F609ULL, 0x7B303A9E3497416FULL, 0x4397A212BAE3DBFFULL, 0x2AC7A51F3779EC87ULL, 
            0x333A0130B35E2B15ULL, 0xB57D4CF4BE2BAA93ULL, 0x1B430D55E18037DBULL, 0x86F3BD94AA8FBDD6ULL, 
            0xA8E4BECA2A6BA501ULL, 0x0D29A851EB26A691ULL, 0x047439FD5ACC0D93ULL, 0xA39B380EAF746F64ULL, 
            0x3D1842B70F289439ULL, 0x5A106BE3D5EA9546ULL, 0x04D5AAFFD7AB564AULL, 0x817F18EA1AA7F400ULL, 
            0xCEFC89AC3F74CED0ULL, 0xA4A2130D5839EC65ULL, 0xE334C11422DCC92EULL, 0x98C720108E1795A2ULL
        },
        {
            0x4A5962F48978C423ULL, 0xCCF3C9EE700FFB42ULL, 0xF2BF0D2F96398609ULL, 0xA0AD98079FF71525ULL, 
            0x9606296E2FEFCC61ULL, 0xBB2FEE52B2BE80FBULL, 0x5E4A420152758425ULL, 0x4F3FB64D5A9559F5ULL, 
            0x398CA6D521608DD1ULL, 0x1A0B312A246AED04ULL, 0x4FA5E6F0BED381A1ULL, 0xAFC1889A3D32C662ULL, 
            0x9B7FB469DB5B121EULL, 0x379E0AE72B994102ULL, 0xC58E3C4D36F3C13FULL, 0xD0BD53421ED64B46ULL, 
            0x01B5DA634EE01F6DULL, 0x2E6A56FCD9D8A479ULL, 0x9BB9C24F034FAD0EULL, 0x965443D54ED4CE99ULL, 
            0x6279A02FEBC701E1ULL, 0xBA84506819960D75ULL, 0x151BA00201F25FBEULL, 0xD26A379CB78AB09FULL, 
            0x59F070C288CE199BULL, 0xB227B910523EE21FULL, 0x3F8E52BCD48C504CULL, 0x4F6E943DFDE0293DULL, 
            0xBB9543B0785CAD77ULL, 0xE078212A626F5495ULL, 0xB9B969FE36981464ULL, 0xD4EECE840835897CULL
        },
        {
            0xF8467BB26142AC7CULL, 0xDE77F7AE56A9329EULL, 0x25486E4629BF8F97ULL, 0xE73690DB4E31E2DBULL, 
            0xFFF19A01C5D8153BULL, 0x4FAFEE2A0853A3E4ULL, 0x841C40DF1F94BC15ULL, 0x97D0CA1461A0D400ULL, 
            0x625F345030EE7509ULL, 0xD56D7046CC3362C7ULL, 0x2FCCDDFE2FA47980ULL, 0x9EAEC39317A4B688ULL, 
            0x8EB216707814CD94ULL, 0x83C7DB6276595A8FULL, 0xC351827883A87F0CULL, 0x37E44C00C1348B47ULL, 
            0xA5D9A4459CCDDF7FULL, 0x650362BD9D71C71AULL, 0x1915DCE0728B2DA8ULL, 0xEF541B9E2860B42AULL, 
            0xDE1D8C7B84864AFCULL, 0xA9ABC689F023E39CULL, 0xC6617194D1F724C0ULL, 0x1332B2A553240072ULL, 
            0xFAA61DFCD00A5CF5ULL, 0x5312333157AA812BULL, 0xD746B5D0CC841C09ULL, 0x74BA8C1D53E0C81EULL, 
            0x358F0DEE3FBBD1E9ULL, 0x9BE99AAD29A5DC30ULL, 0xA5E3C49EB610F0DEULL, 0xFB9C8980A72A75F2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseBConstants = {
    0x53D0E04022F1E22FULL,
    0xBD95E8085EC00DA2ULL,
    0xF0BFF3A5D962BD40ULL,
    0x53D0E04022F1E22FULL,
    0xBD95E8085EC00DA2ULL,
    0xF0BFF3A5D962BD40ULL,
    0x92C8E5F48E42C3D4ULL,
    0x9FD2B945710FA9B4ULL,
    0xD7,
    0xD6,
    0xC5,
    0x3E,
    0x9A,
    0x5A,
    0x54,
    0x2A
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseCSalts = {
    {
        {
            0x14BE3C0D37438401ULL, 0xDBBA0FEF0EA55ADBULL, 0x608E40307868B773ULL, 0x33FF3B57378FEDA7ULL, 
            0x9FC0395B536DDD27ULL, 0x5BEC2E4E0C30A48FULL, 0xB0614F2FB860DAB5ULL, 0x73B8BDD126F27B9EULL, 
            0xE03E4BF8A9D43B45ULL, 0x6A552B909C3FF6CEULL, 0xA80C3F5AF315F550ULL, 0x1A0D212028EC2115ULL, 
            0xEBC241BBC6E14839ULL, 0xFCA07DEE6ADF07A4ULL, 0xFF8DAC377EC4E2B0ULL, 0xC6BF2E00FE4E6C4FULL, 
            0x6F3D03C2A2FFBC91ULL, 0x876315D29E58BEC3ULL, 0xE5C3A73738B41C45ULL, 0x699614632DA1D417ULL, 
            0xEFB4AECE2384F7B8ULL, 0xD4981D2E7A9703AEULL, 0xCE13441ADD6B9E7EULL, 0xA3E8A1C476395F1CULL, 
            0x947B2412ECB12709ULL, 0x1234E30DD6255EA3ULL, 0x6AAF4B18E378E76CULL, 0xB0203B9E7D097FBFULL, 
            0x3EAA653FB43AB442ULL, 0xB17DB9B37AB164A0ULL, 0x7946B438BAAB22F0ULL, 0x19B1849D981B2106ULL
        },
        {
            0xE3EAD13A085398EDULL, 0xBA1D01995C357995ULL, 0x0BDA7FBAB60FAA76ULL, 0xF7E60EE881A2ED95ULL, 
            0x7255C7BB39DEC0F7ULL, 0xD83365D54A930D4DULL, 0xC424FC3821317645ULL, 0x5A8AF911FC28BA2EULL, 
            0x8A42FFD394D48294ULL, 0x499E84BF999C47DDULL, 0xB461809697B906ACULL, 0x5CF99D0A429BD584ULL, 
            0x4AE53DA9478DFD98ULL, 0xD27DFDA5E20851F1ULL, 0x0348C4C0CAD78F9BULL, 0xB45779DFD263E750ULL, 
            0xBC58FDE33E3C926CULL, 0x7B339E4E5E5E458FULL, 0x1F0CAF24B29A3508ULL, 0xD505F4822F618921ULL, 
            0x96EF4823C9FFA3B6ULL, 0xA172895346E75246ULL, 0x9DC74B03B0C7E932ULL, 0x1968903BD2D9F216ULL, 
            0x09F03AA71635F417ULL, 0x855494288AEAD889ULL, 0xA1D71B7A6F97E869ULL, 0xAF3E93C40C0504A8ULL, 
            0x895030CD112337A5ULL, 0xFC36730CFA445155ULL, 0x91E513362E3FE258ULL, 0x3E519EC40DD4CA73ULL
        },
        {
            0x2A48C7D34C69714FULL, 0x279CC4816BA15341ULL, 0x2A0D7EA95AB94DAAULL, 0x103515159CFE0957ULL, 
            0x78F4920A2574EE22ULL, 0x6837611C23022CBFULL, 0xFA0A68C4BF61BA78ULL, 0xD74CD8083FE61B47ULL, 
            0xCAD7A2BC111691E3ULL, 0x90E2EE8B1409A22CULL, 0xA45743C23C0AFA39ULL, 0xF31168FF72ADEFF6ULL, 
            0xC23FE0779DC7B906ULL, 0xEEEBEBF2AB9DDF5FULL, 0x3B88B3FF17C5620EULL, 0x1A17FB0927139999ULL, 
            0x7164BEF4D8B7AEF6ULL, 0x283EE071D038EF26ULL, 0x7A44D905A7D804D3ULL, 0xABA66AFC72A03608ULL, 
            0x5A50A5D6EE7A9142ULL, 0x25767585E5BB4634ULL, 0x2ED83B25D3A91FEEULL, 0x6227EA698856223BULL, 
            0xB9B856D35D078EA1ULL, 0xD6D36DCCC9AC7BD5ULL, 0x16903B8CCC456EC3ULL, 0xE067705592216FB3ULL, 
            0x70D9B361B099B5AAULL, 0x8568D172C25195B1ULL, 0xE4E431C7A6485917ULL, 0xD15EEF0BB3ECCA69ULL
        },
        {
            0xA22E9C0DD2B68B73ULL, 0x24BB054905019940ULL, 0xC234BFE60D40C06CULL, 0x08AC9DD4518ABB5DULL, 
            0x1CF94AF60FB909B9ULL, 0xD54AD1AFB6D5C877ULL, 0x9EDC5BBE44ABBEFEULL, 0x65994A6D8B1E7A73ULL, 
            0xC711159ADBE4A930ULL, 0x72CBC75C85CAC4D6ULL, 0x5DC82F150FF58EB4ULL, 0x1729FC6D9879BCE9ULL, 
            0xA0481EAF0128BA69ULL, 0x90FEEC2B102F01D8ULL, 0xE57C3575B77ECC01ULL, 0xA91ADB3541D273D9ULL, 
            0xB66FDC0AB05A6223ULL, 0x88877925B4568025ULL, 0x55124968158C0DF9ULL, 0x7888619ECB7AAF2DULL, 
            0xE3F745B3F3B0E771ULL, 0xE51605C9CEB397B4ULL, 0x3A2292F49D318FDBULL, 0xDFE3A63202FD97E3ULL, 
            0xC8E08D1E8D83CA65ULL, 0x8D8A8B262CBA3628ULL, 0xD2DA807A2C0EE9C7ULL, 0x9317BFEB79ACB883ULL, 
            0xB6EACCAE0C3FCC8BULL, 0xEAA9D89016620783ULL, 0x83529F1CD49EAE62ULL, 0x5BC6DD533562BA4AULL
        },
        {
            0x0D6019B600BA97FDULL, 0x7621AE5069F31F2DULL, 0xE2A1C33053C87A65ULL, 0x9C7FB5F422267F08ULL, 
            0x17ADCAA4261F506DULL, 0x707D3103653E1339ULL, 0x57D44FE2D08A7977ULL, 0x34D7036EA48B1787ULL, 
            0xF07C1A6C60C6DA56ULL, 0x2563237E4ECE0DF9ULL, 0xCA16D36EA639198BULL, 0xCC4A0859BEFB2882ULL, 
            0x97883560D68144B6ULL, 0xE67B99EF93ECD26FULL, 0xF267EE1DB4022262ULL, 0x20F0FFAF89F52EF5ULL, 
            0x96094BB5DCB5A1EEULL, 0xF5F5B1AD1EC2EDA3ULL, 0x4F667D145CA234E3ULL, 0xE539FB1E702D523BULL, 
            0x40C9741CC83CE102ULL, 0x5ED8844D3B10EB02ULL, 0x100759B1BA0601A3ULL, 0xD03818BE14388728ULL, 
            0x5F90917DFDE5705DULL, 0x5D2440B85D916FF2ULL, 0x7B1CE8DC54E0D278ULL, 0xA9359C27F10F29AEULL, 
            0x7ABF47A4C34724DDULL, 0x478BBF7A5BAB3FF8ULL, 0xC149C820C3FFB63AULL, 0x676A59159AE05368ULL
        },
        {
            0xEA39781443425A73ULL, 0xEB2A20B3E5078BA0ULL, 0x8C33E183091B5E7CULL, 0x239773280F7C0B4CULL, 
            0xFB7E7361F16EE715ULL, 0xD6996892954732EDULL, 0x090E01FA72154CC4ULL, 0xED180D1325EB3213ULL, 
            0x766D8657079DAE98ULL, 0x618670F7AA1F7F85ULL, 0xAD51C394EC6A5319ULL, 0x341ECD4C5C35EB40ULL, 
            0x42AE3E8DD3AD8C1DULL, 0x656124E5BF2CA4A4ULL, 0x304DEDDFB6E0FE6AULL, 0x50F704A88835E5F5ULL, 
            0x798C987944469012ULL, 0x57271EE6FEDDCFB8ULL, 0x3CD37BEF54A3181FULL, 0xDB414279DD65BC6BULL, 
            0x4256BDC625D90D8FULL, 0x29A47C23599D4D40ULL, 0x4FA17A341B8126DAULL, 0xA775C5E748E3708BULL, 
            0x6912B74D436C6F40ULL, 0x270EB985BEF23591ULL, 0x58A970A0E6D062DCULL, 0x3818415B961D4688ULL, 
            0xD18B12735DA9B260ULL, 0x485EAB5715A9A9D1ULL, 0x09F827E8E90E3B27ULL, 0xB1611B91B0417E50ULL
        }
    },
    {
        {
            0x50A308E59273BF68ULL, 0x3BA474E6ABB2858BULL, 0xFB62C8BB5448B76BULL, 0xB53D047FE4779643ULL, 
            0x53BE6B0CD27460F7ULL, 0x34A3CEEC75DD5692ULL, 0x110CD7D09B03FD9EULL, 0x442E3656C5DC8857ULL, 
            0xC10822377049D2AEULL, 0xAAF9B8F578F5F7F0ULL, 0x439EA26D0476EEF5ULL, 0xB3CC67BEAF83494DULL, 
            0xD35FBABFE071502AULL, 0xD5D1F80B9B36C8A3ULL, 0x09D788F6EB891A2AULL, 0x55C65E7FE12B1CC2ULL, 
            0x266EB954A9C005F2ULL, 0x25EC012F4B425CE5ULL, 0xC372FC76689E1D3BULL, 0x6284FA7C20DD8832ULL, 
            0xD93220AE6F12C417ULL, 0x6660CA241A1FBD28ULL, 0x84FD69E5BB269DD3ULL, 0x8CB82B08FB8C3DA3ULL, 
            0xB439BCB203A16462ULL, 0xE71B628CD6FC9FAEULL, 0x60228A27826F6722ULL, 0x26C9DD62A75CB957ULL, 
            0x9CE0A7F90482A1BEULL, 0xDB5874546CBE66E9ULL, 0xB0EA705283E7E402ULL, 0xA89885691638A91FULL
        },
        {
            0x2B93AA66FA7C6EB0ULL, 0xBAC2AA91AC7AD41CULL, 0x21D5954738B33556ULL, 0x9D040997D947D003ULL, 
            0x82094D795FB7EE05ULL, 0x86D28E17A49BCD2AULL, 0xD25CDBFC0617ECC1ULL, 0xA8A1AC6359D7AAF9ULL, 
            0x1EC0836062E71EB5ULL, 0x3379FCDDC74B094FULL, 0xE67C03D15C44736BULL, 0xCE80474E6405D371ULL, 
            0xAD7D6E3120F78598ULL, 0x5CB3A9ADCEB478A5ULL, 0x8A12CD244F869022ULL, 0x673420624F3FA15FULL, 
            0xAE7023A28B6323A1ULL, 0xF3A01411428E81E0ULL, 0x8C2EFE323F1DEA5EULL, 0xC5E2D68857BFFE68ULL, 
            0x306673738072B0A9ULL, 0x8B37A5EACF265765ULL, 0x4B3478090727DA52ULL, 0x2B31584DA7225697ULL, 
            0x94BDA4A35E581731ULL, 0xDB2C3DDAFA6534ABULL, 0x2D581F159E13ED95ULL, 0xB9923E7A6B6FB0ABULL, 
            0xFB491278F4CA9F45ULL, 0xAF2A0EDE7D3784BCULL, 0x8BCDA6DA7F356B98ULL, 0xDDEAF95BD947BD62ULL
        },
        {
            0xC7321DCF54C83095ULL, 0x0D2C17FB9913DCD4ULL, 0x187B11B1C951C404ULL, 0x929B6D98B7451EC6ULL, 
            0xD4AABD7CCD04252FULL, 0xEC0A0128201D095DULL, 0xBC23890548DFD7C3ULL, 0x08FF1E91EB1B21E3ULL, 
            0x5CCB76D085B7EF27ULL, 0x3F7ABD4CB6906325ULL, 0x72798792D0CD9209ULL, 0x2A702EA0869D4A99ULL, 
            0x5964F435EB7D9B4BULL, 0xEED75A85CA521408ULL, 0x4EF6BCE78FC5AB92ULL, 0x0B346ED664FECB86ULL, 
            0x5674A3DB46DAEC5FULL, 0x5F6836354B81B241ULL, 0x294E2912F5FFAC07ULL, 0x556F3D725B30AE85ULL, 
            0xFF5583A528C395BEULL, 0xA8C158C9342BAB40ULL, 0x1A0039CEE119358DULL, 0x2B9E2858D9E81CE0ULL, 
            0x2A0584E241CBB832ULL, 0x6250851EFEC48FF4ULL, 0x2624C4945C06834DULL, 0xCB34E6D982EADF96ULL, 
            0xDB7EFBBBBD16854EULL, 0xDCCC86379662481AULL, 0xE4DC66502E30D4A1ULL, 0xD08E60C55FD2590FULL
        },
        {
            0x203B9178D2114AEEULL, 0x837309F1AE999736ULL, 0x7B1AD0927D5B4FB5ULL, 0x16DB511878E39C7FULL, 
            0x86F9BCE690AFF18CULL, 0xDAE633ABC7128AE3ULL, 0xBE539B5D052314ACULL, 0x20B3D294C87485D4ULL, 
            0x43310651F1745627ULL, 0x3B5684967045426FULL, 0xA0DDC12DD03835ABULL, 0xDE684B254EC19374ULL, 
            0xF54F40FF666F0E78ULL, 0xABE96AA5452CD4DEULL, 0xAE12481AF0A43DBDULL, 0x86F73E07F8B49602ULL, 
            0xD708C007046ABD11ULL, 0x83FFC1AFAF7114FBULL, 0x19149FD269E8DC58ULL, 0x009DCF721EF58C19ULL, 
            0xA990FE0AE8AD9A19ULL, 0x9E5BC0B3F8AC041DULL, 0xAB22C013EA9E0153ULL, 0x448423C69859A233ULL, 
            0xC781116585B9BF9EULL, 0xFC3B16DD11A316F8ULL, 0x236B2128DCD2B858ULL, 0xBD675926A888F083ULL, 
            0xDB2867D9C26F4321ULL, 0x841C69E888CB4B76ULL, 0xCD174A7C196B6CC0ULL, 0x2A658B939AA2725FULL
        },
        {
            0x26C5FD324D82EF55ULL, 0x47900E897F7E2BFFULL, 0x3CE8BC9030AA6776ULL, 0xD6F85285AB1783D6ULL, 
            0x3993A605454531B5ULL, 0x5506335FB07CC501ULL, 0xC6C06DF18207B822ULL, 0x827CEB5B44FBD199ULL, 
            0x208C824E4450B626ULL, 0xE326F6469956C479ULL, 0x2410C87FF967C121ULL, 0x7558E18B5BA596E7ULL, 
            0x09A4595CE69FB1C2ULL, 0x3DF83F1BBA660DA5ULL, 0x01B32A824341A7BAULL, 0x6F0BEA96589D0DEAULL, 
            0xDC31BD5E820846F4ULL, 0x393C7D1EDA596833ULL, 0x2CA61670A7AE802AULL, 0x039E7E440E510D13ULL, 
            0xADA3853AE5C3D08AULL, 0xF02D92B1FD03D6B4ULL, 0xCE22CD939FED80C3ULL, 0x39B2A11238A2BB38ULL, 
            0x83A19FDAB08A776EULL, 0xC355F77D694F9537ULL, 0xA4EF0EE3EFE1FF94ULL, 0x7A9ED3B17DA4C3F6ULL, 
            0xBFC3D3D019520847ULL, 0x41B1BA9392B22238ULL, 0xA71BD29E8022AE4FULL, 0x2FAEB7F24A64C344ULL
        },
        {
            0x00D9C615D25694B6ULL, 0xFC659C7876C31461ULL, 0xD4F5D6B5960BD664ULL, 0x0F3151ACBFA720FCULL, 
            0x1A8C4C9E7780E7A2ULL, 0xBA5EC734E6C28F7FULL, 0x1BF240FC6C42C6BCULL, 0x1AABCBE763011C71ULL, 
            0x3DB695DA210FE874ULL, 0x8C1DD20C561C6E59ULL, 0x8E96E45D650CC433ULL, 0xB1A75329E4BAB516ULL, 
            0x03DC5B0BA24AD290ULL, 0x1983F53F876D7E1DULL, 0x0A449023EDF81E50ULL, 0x63B194EC7FB2F95DULL, 
            0xB6F91C0B0DDCE93AULL, 0xF287042AF9551F3CULL, 0xAE4C97E2681F514CULL, 0x65070147BCD4FFDAULL, 
            0x2D4F413AC266AA28ULL, 0x44E621741D7A3442ULL, 0x803E0D6FD1BED871ULL, 0x24D1D903CAF922E0ULL, 
            0x600DAF91CAA0FED3ULL, 0x0F944872F79A9F33ULL, 0xE2ED80926C7D0FB2ULL, 0x1C92559C4221DE41ULL, 
            0x9AFFB134E31EAA5CULL, 0x8E00A2643E89AC3BULL, 0xD8CDCA091784A7BAULL, 0x37EE51E1AC1128AEULL
        }
    },
    {
        {
            0x513FF7F55B92212AULL, 0x5806175F50D7D80DULL, 0x5DEBE16B26ECD976ULL, 0x326AE811381777B3ULL, 
            0x470197414FC93C6AULL, 0x5B9DE0D8F33D0B87ULL, 0x8A5A130562E0EFAAULL, 0xF279E74F09470C85ULL, 
            0x17EF2AB056301BE7ULL, 0x52FC9D22EAF251F5ULL, 0xF48CB5F2678A5751ULL, 0x7816A2DC594B9703ULL, 
            0xB164906B6EC39C54ULL, 0xE199C01CFD5C7F34ULL, 0x06273DDBC379C144ULL, 0xCF26FEA53481CAD9ULL, 
            0x38A72E0FE7202485ULL, 0xA65D026E917A75CCULL, 0xADD2307B54C70AFDULL, 0x39A3FC045474ADEFULL, 
            0xBBDF85724D0326DBULL, 0xE412F429EE666A28ULL, 0x21608BB369926653ULL, 0x352241D979E6AE18ULL, 
            0xFF3762B8BFF33CAAULL, 0x63CDA9D6E9D3BFF5ULL, 0x02BF58BEEB21D594ULL, 0x5C2F49743047B926ULL, 
            0x5566F9E4BBB047E2ULL, 0x066A400B1C75BAB4ULL, 0x1519AE8C52BEF37BULL, 0xCF7CC2D3DFC5D4D1ULL
        },
        {
            0xBBAA3A3B59F19037ULL, 0xAD0A5715E5FBBCA3ULL, 0x4185574ED1CD38B0ULL, 0xC91EBE9E57979D6EULL, 
            0x1C03443BA343BFA0ULL, 0xF695F9F6276C7399ULL, 0x7CBC3623311EA312ULL, 0x47FD3EB7652A69B4ULL, 
            0x1F4D9C65A131C260ULL, 0x0833A7ED310F3D12ULL, 0xE2E2457B3616CF4EULL, 0x4CFAE3512CE22974ULL, 
            0x213B2BA8DE464309ULL, 0x1AFCE2C77F1BF790ULL, 0x925654DBB7AB42A4ULL, 0xE862566D91A156CDULL, 
            0xD57B463D29B1AFE5ULL, 0xC3F6EB0988B42AD0ULL, 0xBA7F74C467FE6F58ULL, 0x52496888D2ED8577ULL, 
            0xEA2FF9F38F468127ULL, 0x799478E26E9ACF90ULL, 0xB3D73AB7DF7F8AA4ULL, 0xF8BF5D9786BB2518ULL, 
            0xE7ABC91E53870CCAULL, 0x73AB6AD5FE117663ULL, 0x15208E531973AFF8ULL, 0x439C24894B6E4478ULL, 
            0x784EBE33505B7DE3ULL, 0x5AC6276EB6E27921ULL, 0xF1951FC3C2C2D8B5ULL, 0xCC55118D6CE8E5C4ULL
        },
        {
            0xDA19407B7336ACF1ULL, 0xEB875CAFB660917AULL, 0xAAD8B9F2AD48E18EULL, 0x884484A4023D0345ULL, 
            0xE070BAC104324DDBULL, 0xD9D3682C2C5C32AEULL, 0xB5CFDE4EBDE75548ULL, 0x127C930DAE9A1D12ULL, 
            0xACF0E722C646F46BULL, 0xDF908D12A59A45C6ULL, 0x0281CC0E7EAB7F91ULL, 0xC6797BA6B245006EULL, 
            0x6F71F55118BC9319ULL, 0x5C2520771ED77BEFULL, 0xCAF0B44CAFA81CD3ULL, 0xE5DDCC0D601A476AULL, 
            0xA85974FA9F46E9DDULL, 0xE6E514FAF19D33B8ULL, 0x432EC4A82E51D818ULL, 0xBBA7163CBB4D670DULL, 
            0x02DBF4993102DC31ULL, 0xFE9662BAF3AFD807ULL, 0x5A4BE5575A77E72AULL, 0x4F4BC1EA4C79002EULL, 
            0xD632DFC510B46E73ULL, 0x8C3AD16F3440B76BULL, 0x8DF28C3B26147400ULL, 0xC3386F19531067C2ULL, 
            0xF5444D197722C157ULL, 0x42F8E65FBB02A8FCULL, 0x9C7597F0F25F1814ULL, 0xC68B21B5FD006BB6ULL
        },
        {
            0xF71596D1B21736A0ULL, 0x0CA5661998E004C4ULL, 0x1B9001DB97049223ULL, 0x5194035C2159E9DFULL, 
            0x0FB51C67F5A407E2ULL, 0x00065BEEFDBEC9B8ULL, 0xBC5A4EF1D9343FCDULL, 0xF4ACC0AFF3E6766BULL, 
            0x2F69B9F5ABD28E69ULL, 0x26E3DAFB2D75F60EULL, 0xA4B2E74AC7AEC585ULL, 0x307594C5AEF8EAF6ULL, 
            0x837D6E3E9FD347C2ULL, 0xE22ADFE683D7CE8DULL, 0xCE45D09D9CF57FC4ULL, 0x6722871C778E4F52ULL, 
            0xB111CE135F15F0B3ULL, 0x543042EC68D85459ULL, 0x0453C5D21BDEE86EULL, 0x311CA926EECA6FD0ULL, 
            0xA020A8E4224A9601ULL, 0x41EAA04EF21048F0ULL, 0xE9C6CF7617FD18A5ULL, 0x56DCF9DC09B7A72AULL, 
            0x87AAA207F28F293AULL, 0xC33FD1D4D16A5E10ULL, 0xBB5D9BFE17696838ULL, 0x91664CA900F46284ULL, 
            0xF27B97439EDBDD61ULL, 0x8C50F9E06E079681ULL, 0x53F4AD33A342F7EBULL, 0x1033734313577186ULL
        },
        {
            0x103268C7DE208915ULL, 0xA07B5D0413E55C9FULL, 0x64A73D7AB4647378ULL, 0x5169C2B04B0D29A6ULL, 
            0xDDA1DE8A1293E85FULL, 0xD289E8B3124DF4ABULL, 0x6AD5025E0917AAC3ULL, 0x2A9C1400B4CCBF99ULL, 
            0xCF870915A8415976ULL, 0x02C1B5E0F34DF954ULL, 0x529846FD5F662163ULL, 0xB2072298CD6A8639ULL, 
            0x5872E34B1411BE76ULL, 0xE8186EF2A97DD769ULL, 0xF1357EC1966D6124ULL, 0xF97D1BB9637F98FCULL, 
            0xB8E4AC7690D9D9DBULL, 0x248862FFC8922007ULL, 0x2B8B471554956BA5ULL, 0xF3446B7F962505A1ULL, 
            0x10AAA4EA9C734673ULL, 0x61301FB75B0F7FC9ULL, 0xE364319F014EE45EULL, 0x4D5FF617DEB05FF1ULL, 
            0x772311C722E81D7BULL, 0x75924916ED223802ULL, 0x72C8A7818E777479ULL, 0x3C06F7A2DF8820A2ULL, 
            0x6F957E97F2F4F69FULL, 0xF37EE3652E15718FULL, 0xAE5B4426F1496668ULL, 0x4D91219008483F19ULL
        },
        {
            0xBE25267448C95969ULL, 0xA8C4FDB5120E1DB6ULL, 0xDACDCB9F3C639AA2ULL, 0x4BBCE196431608E5ULL, 
            0xAA0CCEB25B30BAE9ULL, 0x9E1819EF21E2F74BULL, 0x76B0CD2DED894FD9ULL, 0xC2F9864F1825A1EBULL, 
            0x8A25F71DA81041B8ULL, 0xB4C6BE2E1FA9FCDFULL, 0x2C54F2BE6FB30FE0ULL, 0x29B41DF144F3C3DDULL, 
            0x86A1E5E5D1229589ULL, 0xD1E5E59D33AD0982ULL, 0x71BD98B0F95FEAEFULL, 0x0BB18F43C2ECAB5DULL, 
            0x6F6FD39184151553ULL, 0x50419DCB1DBE4E1CULL, 0x5CC462A5A3FC854DULL, 0x4EF7DC8E19DA24C0ULL, 
            0xDA34B557EB1DD9E1ULL, 0x44B2A7A9DD18531EULL, 0xAA6170D0284139B8ULL, 0x84EABEEDDAA3B216ULL, 
            0xF323097A098B844AULL, 0x4213FFFC7B73F4C1ULL, 0x7D512299D2C77655ULL, 0x8031D536A8FD7F69ULL, 
            0x9CF160D69D2BC08CULL, 0x2C48503BBA83136BULL, 0x94F82C4697458A60ULL, 0x8278E284C352F84BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseCConstants = {
    0x481AFF60784345A0ULL,
    0xF7A25493F0DA1C11ULL,
    0x103510388B50EC61ULL,
    0x481AFF60784345A0ULL,
    0xF7A25493F0DA1C11ULL,
    0x103510388B50EC61ULL,
    0x1766A12932B39021ULL,
    0x4E55714B320EBC2FULL,
    0x61,
    0xA0,
    0xF5,
    0x57,
    0xA3,
    0xB9,
    0x6E,
    0xF6
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseDSalts = {
    {
        {
            0xE975E2B1848BF6C7ULL, 0xF5883477C1E00EDDULL, 0x9376571BEB1BF242ULL, 0x5E3193CFEAC5B2C6ULL, 
            0xB5D32D76B199379EULL, 0xE33BA2E23F31DFF1ULL, 0x669046440DE0CE49ULL, 0x98C11DA4D0F96040ULL, 
            0x0FE1576889B65396ULL, 0xC31438ABCD76E59DULL, 0xD6F5DFBAAF44AB3AULL, 0x00E0CBA812242160ULL, 
            0x104AAA60C46890D0ULL, 0xFAEC25AD3847DB5FULL, 0x57ADA1D8AED0ED17ULL, 0x6AA6F3B25DB709A9ULL, 
            0xC19DBB61E699442AULL, 0x5DDA7BA71252EEDAULL, 0xB14FDD2C914FD9E5ULL, 0x70A6E32DB9AB6221ULL, 
            0x3FE01B214AF94296ULL, 0x67A1F9CA6502A368ULL, 0xB193AA75902968C3ULL, 0x185ED1A95188AA71ULL, 
            0x836E54AC59BE9FFDULL, 0xAE453349CA8D0612ULL, 0x0C2F458FCD3BB3EDULL, 0x56ECD56DB2580190ULL, 
            0xDA8205B7D2B11410ULL, 0x14F205CAB177310AULL, 0x2E247115A1422892ULL, 0x45B5B759C553F34BULL
        },
        {
            0xE5C8FF7C81F2AFCAULL, 0x46D50B7881AB3CB9ULL, 0x61CF296A5CB4007EULL, 0x8FC32E3782D65269ULL, 
            0x08F23B282EA1F96FULL, 0xFF3E56D50561CE55ULL, 0x33F24972BFE6A4C3ULL, 0x27980D62A99CD943ULL, 
            0x0E76B854C05BEEF6ULL, 0x1AE1C70AC610D787ULL, 0xDE18979BB2CC24C8ULL, 0x5CE6312577F40AD2ULL, 
            0x71B3FEFCDACBDB44ULL, 0x950A1981880523CCULL, 0x1C51C387D2DDF5E3ULL, 0x352A69CE8AC85BA6ULL, 
            0x341AB3E390D1F9E8ULL, 0x727DD13F893D0088ULL, 0x61EBA4F2AB15AB93ULL, 0x0F228506334F87E3ULL, 
            0x1F997BE9900B4BBFULL, 0xDC9315CBCE41B8D2ULL, 0xC75DE2CE4B0977D2ULL, 0x8CD49560861D4E0AULL, 
            0xBA6537D40C7937ACULL, 0x1A7C268C8D54E92CULL, 0x91423FBBE7FC83AAULL, 0xFDE5451E67C692B2ULL, 
            0xC68856466843F81AULL, 0x914AA006902E1707ULL, 0xE565BBD328573949ULL, 0x65A8C0929C32DE1DULL
        },
        {
            0x43C387C3ECDF0F1EULL, 0x47FEE9D7EB4CD48EULL, 0xFD02AAB589F1BB31ULL, 0x2ECA5A40A43AB6C6ULL, 
            0xA8751508CC1788B6ULL, 0xBA5F81B3A60D6138ULL, 0xDCB29B4742CF7B53ULL, 0x61A1C3A09784B273ULL, 
            0x2CB8C8B818AE42DDULL, 0x3A16DE957133D2D1ULL, 0xD3294EBD87320E33ULL, 0x7C53CDF430B1C471ULL, 
            0x1BE43466C4845FA4ULL, 0xDD310DEE5B269A65ULL, 0xE023AF61F21A2B00ULL, 0x3822F670EBB20665ULL, 
            0xA883EC17C2C24003ULL, 0x8BFA26FA22B003ADULL, 0x4171465B41F178B4ULL, 0x300477521C080138ULL, 
            0x43F496AAD3805EE6ULL, 0x3412A75032F923A5ULL, 0xE5DBA4B18108A39DULL, 0x2B9269262C5C72CBULL, 
            0xD1616C15D97F7FBFULL, 0x9EA6BA88B0B5D19FULL, 0x19CC08E3D5E45FC0ULL, 0xDE890ABDA4F97040ULL, 
            0x412EAFB82CD62CEAULL, 0x36B8F7B4B9D96607ULL, 0x1089743E1CD5074AULL, 0x59BF622925F14923ULL
        },
        {
            0x417D756FBED76C66ULL, 0x048ECDD152F61C02ULL, 0x199EBE15E580ADE7ULL, 0x53538A5248A5B4E3ULL, 
            0x1ADF897FF79DD6C2ULL, 0x24FA91628B5D058AULL, 0x11B1045F530F917FULL, 0xAD13C01DB2889CEFULL, 
            0xD583A1DD298E3CFCULL, 0xD1A82A40B3DB37EFULL, 0x9D6835B06880DB5EULL, 0x608AEEDBE48F080AULL, 
            0xD0C0880F609353E2ULL, 0x81983247A506BB6DULL, 0xECBEF12497C21298ULL, 0x164BC96CCD4B22AAULL, 
            0x5F68F2E8CC2AAD49ULL, 0x8DA56CC35FF5C377ULL, 0xE12B1AF8343D1721ULL, 0x88A1C0B43CA58ED5ULL, 
            0x463B900B8B401E3FULL, 0x9FECABEB64F5A777ULL, 0x01FABB078EBB7005ULL, 0x28D8CDD510DA90BCULL, 
            0xDBCAB132845C2C43ULL, 0x8FDBE57D00B4C2BAULL, 0x4763340105B43A33ULL, 0x0A3848751E1D224FULL, 
            0x7681C0E61D8AE786ULL, 0x03DE71D651149EE2ULL, 0xA9C927B4B706FB45ULL, 0xD3A24A7F4C0CCA8CULL
        },
        {
            0x456033AE377AF77AULL, 0x084E990EF3268DAAULL, 0xFB6EC2D29B495841ULL, 0xBE4569D7139565C8ULL, 
            0xF9391A91E67E7F2FULL, 0xB5B2274CA04F372CULL, 0x6397A382AABBDDF3ULL, 0xB34CF13E45848EEAULL, 
            0x4A72F4010792BED1ULL, 0x4FDBAA8AB060A395ULL, 0xD826677A6750AA26ULL, 0x19DE6B8E28F9A930ULL, 
            0x04A12D6079DF257FULL, 0xA24740C0890817E8ULL, 0xD959E61411B427A9ULL, 0xE712274C4E04A969ULL, 
            0xCF28C73D8872AF90ULL, 0x7A1EBDE55D826E8CULL, 0xD8D25258AD2627AAULL, 0xF1A82840A816437FULL, 
            0x35F8739E64CE5D18ULL, 0x9552BFECEAD8874CULL, 0x3E4D8F2BCB598ED2ULL, 0x6ABE3F95C7AFED81ULL, 
            0x516B1DB8FC303118ULL, 0x343600FCFC497495ULL, 0x151A438CB5776B9BULL, 0xF0E7C51C3BF2AB9FULL, 
            0xE4F6F0DFA69A13D0ULL, 0x7053390356929AFAULL, 0x20EAF5E4E44BAEDDULL, 0xE395279F38DC374AULL
        },
        {
            0x7036600073DBEDA7ULL, 0x72ECD802E58B1A8AULL, 0xFE9F01A6ABF8F574ULL, 0x6967383B03588281ULL, 
            0xC978404AC1786270ULL, 0xC2F25FB0A4BE0AF6ULL, 0xF0F4DB99A23CCF78ULL, 0xEF1D58BA26374E13ULL, 
            0xD7C47016DBF944F3ULL, 0x34619485F074EC37ULL, 0xADBCB54F874F326AULL, 0xCE65D5658669C9EEULL, 
            0xE974EDD2CD543AE4ULL, 0x5C482F0B4F3AA4D4ULL, 0x65602A08A769E558ULL, 0x1A7A75F7BEBFB254ULL, 
            0x21A5109F689C18DBULL, 0x186199C5D9082109ULL, 0xA79BEA78935FEB76ULL, 0x1382D4CAB8E79973ULL, 
            0x3332038B18B96249ULL, 0xDA8F66242188C5CCULL, 0xE9E205FCD185BADFULL, 0xE3B76252BC4A0C5FULL, 
            0x07732B5758014D20ULL, 0x980EAE72E263B9A2ULL, 0x9824A646FDAD2209ULL, 0xD751EC9399A347FAULL, 
            0x3D94940BDB6CB57AULL, 0xC1A616CE1207497CULL, 0xA35CBAC4DB937431ULL, 0x09466EF18DCE1B5EULL
        }
    },
    {
        {
            0xD96538129888F013ULL, 0x856C9434661A6BE3ULL, 0x523AA66F243EA713ULL, 0xD992BBEEAF499C9CULL, 
            0x9A12016762C5521FULL, 0x9C4721AE69C90904ULL, 0x33AE47628E507A39ULL, 0x01BEAA0CEBEEC270ULL, 
            0x9A2B076A22E0CBC2ULL, 0x129061F8C3438E9EULL, 0x11545F0CE671F470ULL, 0xBFA67B156596166CULL, 
            0xAA8CCE55640D7909ULL, 0x0F42BB91997C537DULL, 0x1A4DBCA7F5B6B2E6ULL, 0x841EFB962E2D5293ULL, 
            0xD59502FAC7956A0BULL, 0xBAD8106BD60E59A5ULL, 0x76869D45347B59E7ULL, 0xD89EB44BCAC2E5E6ULL, 
            0x97F301AE5CC5F1A3ULL, 0x2451BED94CAB9CECULL, 0x52DD9BC32D2C1AAEULL, 0xD109FB3ECEEEB2D1ULL, 
            0xD92C56E9FF781DD7ULL, 0x4FC41BD6618E792EULL, 0xC9BC912C941D730FULL, 0x7BEFAFCA414D6F3FULL, 
            0xBDEE3CDC555FE6F5ULL, 0x6D7204BA4CB2A64AULL, 0x6DF053681EDC9BBBULL, 0x1D71343253EE283FULL
        },
        {
            0xEC399052D360899CULL, 0x189184310E363EE2ULL, 0xB12AD9D313BBEB4EULL, 0x1D4F52F646DD66E7ULL, 
            0x3E1AF7FD66CC58EEULL, 0x3CE75DAF90BAF5F3ULL, 0x0D01248482A1BEACULL, 0x9EC7762B2ED7F229ULL, 
            0x3301736DC418D73EULL, 0xDE9B7D955AA35B1DULL, 0x229755B8D5B15080ULL, 0x45F7627BBD309232ULL, 
            0xD2F184731FC6A10DULL, 0xA0237A11661B2F72ULL, 0x16D4951F097AAEF5ULL, 0x6DC09CDE3CC36DC2ULL, 
            0x9C3DB4591CC8A2F3ULL, 0x33AF770B118EF893ULL, 0x3D34632FB2404904ULL, 0x5F73DC62CB7AC205ULL, 
            0x1DFDBB6D77813E58ULL, 0xBC9B483C57DEAB2FULL, 0xCD8F980507A7BCF1ULL, 0x6E9848540D2A361BULL, 
            0xBD31CD7F6E8FC1B0ULL, 0x6EDD916D819EB17FULL, 0x9209B2BE9BCEA51BULL, 0xB9963321B0FFDD29ULL, 
            0xA49D5BED46789FE7ULL, 0x1C7A74D8889EB5A2ULL, 0x35EC99530935C4E8ULL, 0x79FEAB540E0C20ECULL
        },
        {
            0x5FB621DC24C849A7ULL, 0x5CBF9A9261044CB7ULL, 0x8AED0374F8FA1554ULL, 0xF3F617875F5F1535ULL, 
            0x824AC03F27A320CCULL, 0x0E86E8D996FA6A7CULL, 0xFA3D7BC104E03A73ULL, 0x31320B4495354D09ULL, 
            0x0C06CE48FA8F5378ULL, 0x84ADCC6E904ADB96ULL, 0x2640EE691E1EE7E3ULL, 0x8B5664C012257ABDULL, 
            0xF3BEBF21D3C58EAEULL, 0x01B2A900DD28C9D8ULL, 0xB5D4793D1194A880ULL, 0xB17709CD85AA6C3EULL, 
            0x82CB86559053ADE4ULL, 0x2211A6920DF12A89ULL, 0xE8B23447D710BA30ULL, 0x2D40935C4D9A6AD3ULL, 
            0x53317A0CD9F29BB8ULL, 0x50FDDC2E948D1725ULL, 0x7CBDE37ED6AB6648ULL, 0x75AA007A73069A13ULL, 
            0x7926014D990A0B70ULL, 0xD7CADA7887F7C1BBULL, 0x8881828CA50695F7ULL, 0x660C3F9F89BAA496ULL, 
            0xE7D75532C58D1CF8ULL, 0xC51936FD1F6BC454ULL, 0xC401B1F4702431DAULL, 0xE3808C08890A145FULL
        },
        {
            0xDE98DE3E6D33F26DULL, 0x573799754C89C2D1ULL, 0x398B33BE95EB282DULL, 0xDF18F8390293A85EULL, 
            0x55C724FC7259F2E3ULL, 0x8FCB072D4DAAA939ULL, 0xEF25653CB48EBEAFULL, 0x37B7FC8FD9B7DA85ULL, 
            0x6B346EC5C8EB252CULL, 0xF5C4A49E3FDB9FD9ULL, 0x2939CEED8C1130EDULL, 0x8D98D61B5BE55F79ULL, 
            0xDC541245FDE62D96ULL, 0x3B447717428128D5ULL, 0xB3A6ACAC1CF44049ULL, 0xFDA9AA2800E2427CULL, 
            0x5A9AAC681CB4B691ULL, 0x1DD999F4E02402F5ULL, 0x67E5D209E7A5F359ULL, 0x7B65F06D9B8E89A7ULL, 
            0x56783A3DC0208AEDULL, 0x49056F40ED916911ULL, 0x148DB6EFB56D1906ULL, 0x575BEB9CAD44DA0FULL, 
            0xA55AF6E241A26F07ULL, 0x5C7DC1209229FE29ULL, 0xFBB604803198E14CULL, 0x0AFEFA84CB4777D8ULL, 
            0xA81F74645837C975ULL, 0xCFE4713D8E7AD508ULL, 0x9C3F55A3C8E692C5ULL, 0x4C12798B1450FF86ULL
        },
        {
            0x857F717B1C7C8351ULL, 0x429D09E266BFC5F0ULL, 0x150AF04CAEBB5B0DULL, 0x7225B8FBB77DFCD1ULL, 
            0x6267647468F31B8DULL, 0xCAD5D94AEFB43205ULL, 0x418877F03092C73AULL, 0x0394F49A032ECA55ULL, 
            0x6BFCBD347A2051B5ULL, 0xDCB72BDC9C0C73D8ULL, 0xB157EF08309A9AABULL, 0x4540E3092BF1C057ULL, 
            0xFA18B600E4E78431ULL, 0x81C716F19198A584ULL, 0x3CFFEEE38EA9D879ULL, 0x17E879A1162E74EDULL, 
            0xF03CBB8B35ED56D1ULL, 0x77DCE824F23AD461ULL, 0x13341664A6688961ULL, 0x431F7FABA4711D80ULL, 
            0xEAE4D9E921243CFCULL, 0x7C1FF15F78E7F37EULL, 0xDA77D53226631C1EULL, 0x8A4EC82172A2DA46ULL, 
            0xE72CA9D667F18A2DULL, 0x19965445D0574621ULL, 0xD0B7E0091B917BE0ULL, 0xDEEFED36FFB50475ULL, 
            0xC406F635B4F38FBFULL, 0x3E4468B8282A2D6CULL, 0xE6F2C21666E87AFDULL, 0x684A25A3E4FF1068ULL
        },
        {
            0xD36FD41D987FA5B6ULL, 0x3A3157078F0A86A7ULL, 0x58826661EE873B9AULL, 0xD3894D6E39D5D1AEULL, 
            0xDCC22AE59D7547FAULL, 0x2CC4D8B1AF11FA5DULL, 0xFF325A413C8876A6ULL, 0xA1DFD93574A734A8ULL, 
            0xBC605DDEB01EE7ECULL, 0x5EA78F659C12B288ULL, 0xE8797DC2356E193EULL, 0xE2CBCC1EE3FD5E7DULL, 
            0x922DAAABBB1C88E9ULL, 0xDE3BEEB1F29DD642ULL, 0xFF079524BFE24741ULL, 0x90415CA51D1BD9C1ULL, 
            0xFFDE2084020791D7ULL, 0x60460E605B9F8573ULL, 0x263E7D5F89EE1685ULL, 0x2D1ACFA29238ED7FULL, 
            0xA01A2FBC31451C00ULL, 0xFC1ED12BE17B83BBULL, 0xE270D9398871395BULL, 0x9F3E1BC352226194ULL, 
            0x47B8BF3654C5CE7CULL, 0x0864945384E4B649ULL, 0x60001A3FA74AD665ULL, 0xA9CD7038E97383EBULL, 
            0x7EFFDDEBD92B1845ULL, 0x53CA2CBF778DEEC5ULL, 0x8FC4485EA5D3BF5AULL, 0x7728BFBFB92E584BULL
        }
    },
    {
        {
            0x147B2BC2CDFAC666ULL, 0xA2115326268C5B06ULL, 0xB58790AC80172D81ULL, 0xA0A16D4E70A6BF03ULL, 
            0x698EB5A3FBCD2457ULL, 0x18664B806BAE182BULL, 0x15317A9967329B41ULL, 0xA116B4997F4662FFULL, 
            0xFCFF21D119A9B622ULL, 0xEFEF4A60279357FCULL, 0x633A6312FAFE0874ULL, 0xD7AF61B9B77054FCULL, 
            0xB4DDCE884E7A56B8ULL, 0xD8767DB397D08CD8ULL, 0xF1EB096BEACF266CULL, 0x9ACF82B32FA7F5E6ULL, 
            0x36350C43F71AD032ULL, 0xA7DA89015ADC80DEULL, 0x9B336088D0F04A73ULL, 0x0F2CAB5A6A5BD1D7ULL, 
            0x1BC5A1C1BAC416BEULL, 0x1E5D5D13C43BCF80ULL, 0xD6DFAE3DB4B7C51EULL, 0x4A0BCA67C1B94AEDULL, 
            0x1832FA703F720AF6ULL, 0xEA4F87292E940BF2ULL, 0xF9F7407D4C033153ULL, 0x4E33643031D900E8ULL, 
            0xA3091D243C242720ULL, 0xDB0B5BDE7BB7CEB0ULL, 0x38CA3CC2A3ED5424ULL, 0xF70CEBADE94BA72CULL
        },
        {
            0xFE6C66595DC99E32ULL, 0x7B2F5930769191F3ULL, 0xECE1319388AA5E5BULL, 0xB98B9CBCBFE17C3EULL, 
            0x30B9EDBB837344E5ULL, 0xCA7B38FF742C4BD2ULL, 0x9381C34F0222FFF1ULL, 0xED014FFA74052AB1ULL, 
            0x7EDE3704EDB3E517ULL, 0xE1DCA9C7A1F19136ULL, 0xE2DCE78CB68A2995ULL, 0xC2F252EB635C9ADCULL, 
            0xF4AF57B6DC48AE1EULL, 0x230B8D675FFC1B74ULL, 0x9F8F8F4B38694198ULL, 0xF47F699658AFBD23ULL, 
            0x96C7EAB2C0B5BBE5ULL, 0x53F2C0620C1B7E01ULL, 0x8468A6BCE25E5C30ULL, 0x0C7CA2F4B871F9C3ULL, 
            0xF29A02C59D08AB1AULL, 0x55390239577426CCULL, 0xCD0EF6855E6AB121ULL, 0x707409CFA8523DF7ULL, 
            0x27E6B4533BB3FC36ULL, 0x28EC4B8FF63EC724ULL, 0x646B5F83BDEB738FULL, 0x03D6E497CC432DF6ULL, 
            0x9727C20A72BEBD38ULL, 0xDA9CC622B5C52A9DULL, 0xE89CC7A331582A67ULL, 0x950FEDFEAA1EA1C0ULL
        },
        {
            0x901657F58EE23DCAULL, 0xB82988A34CC91C88ULL, 0x7C2B8B9E42001676ULL, 0x3CAD255DCC025E47ULL, 
            0x6653998CC9E446C8ULL, 0xD1F15BE7E9F1EDCAULL, 0xF7425714BFA46ED7ULL, 0x7166D40A0F2D0DE8ULL, 
            0x28B4CE8F177460EFULL, 0x349EF92B3FEB5FE6ULL, 0x7D5B057AA880CAF0ULL, 0xCCE2559AD5095B52ULL, 
            0xE06BE9F671B64DE7ULL, 0xCC2572699ED4FAFAULL, 0x0990AD5DAB304AFFULL, 0x529AA54415877543ULL, 
            0xDEF38A66EAF5C8A3ULL, 0x54A37BB0E1E2C4D1ULL, 0x6D1C48F000DB63A8ULL, 0x5D4A662790D9BC1CULL, 
            0xF84D16FF5B5B66FAULL, 0x031956CC9BF07884ULL, 0x6296B05CC636CD74ULL, 0x7F12DC73E9CE9D48ULL, 
            0x6CE0E3AB1141865DULL, 0xB3FF8D7CC408BEA4ULL, 0x633B0886F4D97A95ULL, 0x8733033059CCADBEULL, 
            0x33044D2089BB9FAAULL, 0x916D1B2A01A99E15ULL, 0x81FC3DD8077F1A9FULL, 0xA3CFD57010CFC95FULL
        },
        {
            0x1EC201067220ADCFULL, 0xA2498E4BF01B490DULL, 0x045E2C350E1BEE69ULL, 0xAC52CC89A291E0A6ULL, 
            0xAF666D2D0EE44223ULL, 0x0939A4A66054D4CCULL, 0x9A347D23F201B29FULL, 0x3071ECFF1367C209ULL, 
            0xAE14D7129CB274C6ULL, 0x7A377192B6AC3A1FULL, 0xD2A7CE97EB893C51ULL, 0xE918E3292D0484D7ULL, 
            0x2F2BDB940D093ECCULL, 0x7640B1F5F5E70BF7ULL, 0xBCFE27F93DD1C557ULL, 0x88D5CC6A4798669CULL, 
            0xCB10585BADF0EC46ULL, 0x00DB57B8070CFF0AULL, 0x8AFE9061B7E521A9ULL, 0xA9478FFC8DE7BEC9ULL, 
            0x1D4A5955F51140DEULL, 0x28EF528368EA5EB8ULL, 0xE4C5D168C752A313ULL, 0xE0EB023C33C31ABEULL, 
            0x347E01A5BC52594BULL, 0xB55E6C8A5C653248ULL, 0xC09C83B512F851DCULL, 0x08651045BE49CBA5ULL, 
            0x8D986E42926C8654ULL, 0x3376815F7E08B8B5ULL, 0xEE790F0BDFA6B8F1ULL, 0x04601EF9DBE8BBE6ULL
        },
        {
            0x030B43DA0BDE5D71ULL, 0x966F1580F8239488ULL, 0x782D82CE1DC7D790ULL, 0x7E17564FC6EA42EFULL, 
            0xFCE1243C97A1E00AULL, 0xD70F86FC654C4453ULL, 0xDD1861C0DEC33A8EULL, 0xADE4E3297AC6B567ULL, 
            0x62C94DF3C3E9CFC4ULL, 0xCD63B733B8A07768ULL, 0xD7AA2195A4DECF48ULL, 0x92013D9670CCFD02ULL, 
            0xD260AB0CED1B94EEULL, 0xC82B27379E1DABAFULL, 0x2CF937F623926A8EULL, 0xB5CAF5E4FB1A11B7ULL, 
            0xEBCE2A84B607C27EULL, 0x4D7F593BEC9F7743ULL, 0xCACD1D5A436DC2B7ULL, 0x63A4B30FD48E09B1ULL, 
            0xAF5076F18D53BBF6ULL, 0x976A5D94E7BEA190ULL, 0xD506E64E4131AF35ULL, 0x9DE9E220A9655708ULL, 
            0x8002A478ED74E9FDULL, 0xBB36B3BDA0D2619CULL, 0x782DE276AD940BC8ULL, 0x45073302F04B90DAULL, 
            0x3788D9FCC0A627D9ULL, 0x6F899E12AE1F80A9ULL, 0xBEF2D564502AC56AULL, 0x302AB63DA988A0BAULL
        },
        {
            0x2C021D7399BBA16EULL, 0xBE4DE896D4E55125ULL, 0x24F5245AC82A028FULL, 0x0A460B28D49579EEULL, 
            0x4F8365AC6502E06AULL, 0x24F5A5B11ADECACDULL, 0x64BA21E23BF4A6B1ULL, 0x8D37E2B0FFD23E7AULL, 
            0xAC0CAC0ABF88CF92ULL, 0x149868679424DCA0ULL, 0xF20F789859C20EEFULL, 0xC7E83E1D34194E82ULL, 
            0x3FD95B2B39AABAD7ULL, 0xD06B29BC95B29663ULL, 0x9CE295DAD03A19DFULL, 0x62F1125E57F2C545ULL, 
            0xF21EA5B20ADC2FD7ULL, 0x0832E0450D147772ULL, 0xF46D4988B9315598ULL, 0xF540741AF885E089ULL, 
            0x9D74B499D55EAF51ULL, 0x916619B0929F2278ULL, 0x28B406C44CCDBF86ULL, 0xEC6F259016E64BC9ULL, 
            0xC4534DFD471DC2F0ULL, 0x757E8BACB90BF7E9ULL, 0x69AF14ACA351412CULL, 0x74D71947E633DF90ULL, 
            0x08830773486F0BF0ULL, 0xB171C6BC886A391CULL, 0x20A2759106BD5209ULL, 0xB2D75837528D7435ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseDConstants = {
    0x458169E4B0232F2EULL,
    0x2CF5337534B209B5ULL,
    0x3B50D4ADCC180C26ULL,
    0x458169E4B0232F2EULL,
    0x2CF5337534B209B5ULL,
    0x3B50D4ADCC180C26ULL,
    0x3756A9EE7DE2391AULL,
    0xC2000885B686175CULL,
    0x6D,
    0x7D,
    0x39,
    0xAC,
    0xD2,
    0xBC,
    0xFD,
    0x04
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseESalts = {
    {
        {
            0x43EFBA21E22DA667ULL, 0x18EB5184BF43C023ULL, 0xAA2AA87C801341E6ULL, 0xB3A5736255F7E87AULL, 
            0xB183DB918384FDDCULL, 0x219C47165466648EULL, 0x9DFADCCC16CD23B8ULL, 0x27B4746A627DFCBDULL, 
            0x49D91D7AA279957DULL, 0xA3385EEFC2DA7607ULL, 0x0933E22F8B088502ULL, 0xAB0F892C24F26071ULL, 
            0x9B639FC2DC7B0065ULL, 0x50D56A74B2AF748CULL, 0xBF100DF1A4C5A908ULL, 0x6B54E1A27A83A8CEULL, 
            0x6FDEAF6A50B6E97BULL, 0x68A1179610DFA000ULL, 0xF21684E0CE641DA2ULL, 0xA86D0B3455B912E6ULL, 
            0xDED3C051691265E6ULL, 0x5DB35D93ACD835D9ULL, 0xC5196748FA26EB22ULL, 0x08287ACA4DD3DAFDULL, 
            0x19A964BB6B335820ULL, 0x2BB4A58238C83B87ULL, 0xCBD08A95D6396DCDULL, 0x6E0C063FED2FE1C0ULL, 
            0xABE4D81E595F6BCEULL, 0x97BAEFB4CE44ED71ULL, 0x3ED71E1486A6507EULL, 0xCE0028190E77EF51ULL
        },
        {
            0x52550FB356ADC7D9ULL, 0x930F850FF18C36AFULL, 0x665ADB4EC48003E9ULL, 0x8186E78EF6C97CCFULL, 
            0x94080AAACC569058ULL, 0xA303763683759AFAULL, 0xC126995895C098E8ULL, 0x0A14B8FEEB0DC39EULL, 
            0x6087CD4000D0DC17ULL, 0x2B5EB227DC184182ULL, 0xF4D3110589DC1C8DULL, 0x8368497EF3F3DDB0ULL, 
            0xD5E2A438E49C80BBULL, 0x4ED4440C28589A20ULL, 0x818DFE7A16D5725CULL, 0x5670AF6AD68D52DEULL, 
            0x87954D2E7A3D21C9ULL, 0xAA00BE25CE4B41FEULL, 0xF5A3F53EBA4F890DULL, 0xA4B261DC5E5DBCB8ULL, 
            0xB1BA0E2CD0081BE4ULL, 0x8DE66DE55698DC56ULL, 0x623A6011DC7C0782ULL, 0x529424677BFDD744ULL, 
            0x0820BA3B642EBB07ULL, 0x47AFB1602F7E5A1BULL, 0xAB9BFDCC62BE817DULL, 0xE381ED0F4B7F49A5ULL, 
            0x772E61FE25560663ULL, 0x92F9827504ACFFCCULL, 0x3D3595A8B1FF4147ULL, 0x8503434965C5C577ULL
        },
        {
            0xCBD6E2A33AE8E9F8ULL, 0x5BA704748FEFDCC1ULL, 0xD5A7DB01436B9C0DULL, 0xC751C5D9D56E7F33ULL, 
            0xB4AFEC7ACD674E53ULL, 0xF4CEFFC653AC5BB9ULL, 0xBB13A0172701C4FBULL, 0xE1CA3D53D1B7EE4AULL, 
            0xE8CDE030F11B0302ULL, 0x8F07EA832C52BC50ULL, 0xCCFD379F5428E175ULL, 0x3958719615F54613ULL, 
            0xFEC7E01F86CA5CC5ULL, 0x8F9CA1C4004FB0A4ULL, 0x8678988D3D4F0E63ULL, 0x7D95D528CF037F7BULL, 
            0x86EF2432FC89A71AULL, 0x259929B3055B2FB9ULL, 0x95B8A8372AB166A1ULL, 0xA7C1EF316A26BB12ULL, 
            0xB0E54B9976CAB49FULL, 0xB906C5A53C349DAAULL, 0x65F63953871BAC5DULL, 0xDDEF8D7E24D7FF65ULL, 
            0xC2B4906CA65E44AFULL, 0x7D412E1394051F17ULL, 0xA5CEB54D344FA55FULL, 0xDC2240554F38CAFEULL, 
            0xA9A2BD1F2C428F58ULL, 0x0B981D00EE174F39ULL, 0x277DE13C893B8DC8ULL, 0xE0C78B27A4008134ULL
        },
        {
            0x1A27B76C3F8AC074ULL, 0x2F3475DBDDAB98C5ULL, 0x11F7330DEF382CC9ULL, 0x6E9FF7DF65930A1FULL, 
            0x915E29CC8F972265ULL, 0x787AB9C4CF15331BULL, 0xBDA1530DD62438EBULL, 0x51B18BEA31C7BFC4ULL, 
            0x8352860E7796B6C1ULL, 0x46BD84EEDD7147EDULL, 0xECA3907ACDE7AC8AULL, 0x1BA4394CEF89B600ULL, 
            0x0B260C1F4E0C4599ULL, 0xE97C05D1D2DB201EULL, 0xEE5FEFE2CC26FBADULL, 0x4EEA84F2A773FCDDULL, 
            0x5E31CDC9C66032EDULL, 0x972882643903E92EULL, 0xA5B71A11AEAA1DF0ULL, 0x40230E7141D6F88AULL, 
            0xCBD2E926183378FAULL, 0x9E88DE13455642A1ULL, 0x3FE1BE2869C38528ULL, 0x189A68F89808B28DULL, 
            0xE6D6560586CBFCF6ULL, 0xDD458523EC4AB655ULL, 0x113F32DA7A2AC101ULL, 0xAB952DE649EEEFA7ULL, 
            0x47448972894BE976ULL, 0x50D32C066005D853ULL, 0xF52661A607ED56DDULL, 0xCA4B7A5073C388B4ULL
        },
        {
            0x83548179DDB6928FULL, 0xBB55397CC48D12F5ULL, 0x172CD379F664E4E1ULL, 0x0FFCC4973941B14AULL, 
            0x9498BBD90887C416ULL, 0x04A393FEE1223411ULL, 0x3B855C775124175BULL, 0xB352D96E3B5BEEAEULL, 
            0xB91F81437C8B67A6ULL, 0x0DB94F691A0F6742ULL, 0x9B652AC6A73C90EBULL, 0xA9C2DC2B7349F60CULL, 
            0xE802F8687EBB9B6EULL, 0x4B96A55F0505DB7FULL, 0x9D3D9F104FBAEBF2ULL, 0x0A480153BF1B3699ULL, 
            0x505BDF611B096D05ULL, 0x51CF98BAC1505C1FULL, 0x320788D7F6539198ULL, 0xA16A9F10635D5127ULL, 
            0x49E2F51D9132CB9DULL, 0x752E265F3A247538ULL, 0x22326B12D96BC068ULL, 0x4D8EF13A7A45CF3FULL, 
            0x835DC4DF55EE110BULL, 0x844655F7F7814081ULL, 0x32C094489FC0FF03ULL, 0x6CC2FF05A065CFA6ULL, 
            0xF0EE199A58B49A41ULL, 0xEBA3CB0DF5F95519ULL, 0xC6E69F0216359F63ULL, 0xFDB04C0FA6FF7574ULL
        },
        {
            0x290ED694DDE2667EULL, 0x694A77B0BD96BFE7ULL, 0xF71E8566A76A5AFFULL, 0xFD19FB14BDC5A357ULL, 
            0xABA3A78D4A425C19ULL, 0x2F515FCDCD83D6E1ULL, 0x6F8CDDCDF7CCE88FULL, 0x99C97E55FD7F519EULL, 
            0x0D6FD409DEEB40F6ULL, 0x12A3C83A75944779ULL, 0xB15B19724EAB74ADULL, 0x861B17FA396A6545ULL, 
            0xFBEB4FC24195697FULL, 0xED22C6F9B75D0C6EULL, 0x3B733DD2C6ACFAE7ULL, 0x8A0CB9E862DE3368ULL, 
            0x69622C31714144CEULL, 0x6833AAF0C75A9CF0ULL, 0x399B4D2EA7AB457FULL, 0x655C01E660919708ULL, 
            0x929AFE895CE92517ULL, 0x872D0AEC7C623316ULL, 0x5D8EB8D0473606FBULL, 0x5A2A1D0EED2AB81EULL, 
            0x7B230E07D6F17BA8ULL, 0xC3847C1C3E7C25B2ULL, 0xAD23FAF50D1D7486ULL, 0xF0D723D2506CD969ULL, 
            0xA7E7DB8536044821ULL, 0x5D2AA03F43AD2070ULL, 0x5622AEC81105BAD8ULL, 0x3F5DCFEE5A4E05D7ULL
        }
    },
    {
        {
            0xC333616F584F0ED3ULL, 0x4718DA8AE8ACF4D2ULL, 0xA77A7CB2626BFBC4ULL, 0xB7411C38CC72295CULL, 
            0x9C71FF43E7461BC7ULL, 0x0BC2AD7D4AE12ABFULL, 0x292F9FC861A368DCULL, 0xA7A426AEBB2E139CULL, 
            0x8FD36152FAB74159ULL, 0x7B484D598436FB91ULL, 0x7726AF17E54C4DF7ULL, 0xAC01F1460F4D0DC5ULL, 
            0x1797CDB5A06E7938ULL, 0x0AAA70820DE4E38BULL, 0xEAA8F864E150B9CEULL, 0x1AB43BFEBADE9B8BULL, 
            0xBB2845565F03AFE0ULL, 0x8BF98E3A0B8BE0D5ULL, 0xC8C61031F1C6A8AAULL, 0x10E0487E7AE88DB4ULL, 
            0x36F58127C3ECFF05ULL, 0x0915D6838639EE71ULL, 0x999D5979D95CBC41ULL, 0xDAFBFF4B0E286662ULL, 
            0x528754A6F2A8166CULL, 0x204D164686F367E9ULL, 0x9143D477519B8DD3ULL, 0x1B2960024991E89BULL, 
            0x279064F468DAB921ULL, 0x664F97FE09DEF00CULL, 0xBA8159693D95D460ULL, 0xEC1E59B9C6DF9F4BULL
        },
        {
            0x6B7CF012096F5189ULL, 0x9C91569B50352EA5ULL, 0xD875EACFB7E4A548ULL, 0xB2208D4E86202054ULL, 
            0xE34B3EADF1C68591ULL, 0x497FBC6E8239E247ULL, 0xF9FE2F194571F677ULL, 0xFB5952514E0827FEULL, 
            0x1DAEE9EF6FC7834DULL, 0xB470FB31EACE9183ULL, 0x703384746CBF9B21ULL, 0x9E69CF9E7FFD9821ULL, 
            0xA54DE464FE843609ULL, 0x61D2D2761BB8F9E1ULL, 0x4FE878037EA633E3ULL, 0xD1DB02674EBA056EULL, 
            0x3909E881319AA84DULL, 0xF4334E18EB4FA087ULL, 0x49C1BD036927C233ULL, 0xB560D21693FAF175ULL, 
            0xAD99CAB32C30C451ULL, 0x160EEC8A685F6FD3ULL, 0x30241200428FCC06ULL, 0xEB0DC82BF37A2D3FULL, 
            0x811B5BF19E30BC00ULL, 0xF21D087F955C1F62ULL, 0xB98A901BA3EF4107ULL, 0x98FCD31D58214AA5ULL, 
            0x1DCD865939590281ULL, 0xE0B4925F82E4BFFEULL, 0x2129BBDC6F5AA2D2ULL, 0x0486C158AD4F56DFULL
        },
        {
            0xD8C00E7BB4CF9C9CULL, 0x0B74F777996DF840ULL, 0xF0ADDC8519CFC44CULL, 0x0D73F5B6DA2D4111ULL, 
            0x02E8C0715A2C99B6ULL, 0xAE471176DFEAB4D0ULL, 0x2EEEFD644A14DA6AULL, 0xF6BFE49413B118CEULL, 
            0xFB76F3113424B64BULL, 0x7857663BA81EB66FULL, 0x27A9CA3142987697ULL, 0xB91576D1E1F5776EULL, 
            0x10874645054DFFFBULL, 0x5BD5C6FF5710201CULL, 0x58EBE5989E68C970ULL, 0x6B8069CAA7E0DC09ULL, 
            0x9B2EC83D35E86656ULL, 0x9122923D1F34E2FCULL, 0x1622DCDD348E740FULL, 0x5446383F10C282ABULL, 
            0x5CF41DAF9303913AULL, 0x1BBA8F0ADD1B6A42ULL, 0xB2BC8755F1C19E1AULL, 0x04AE2990E7CD33DBULL, 
            0x36874CE713BFBCB3ULL, 0x27A5502F08F7D0E5ULL, 0xFF201EB936D004C8ULL, 0xBCD4376FCBA773E8ULL, 
            0x9D3A0A3480B9481CULL, 0xA7C18CC99F7474CCULL, 0x1D4DA04201B5D342ULL, 0x7C2C457CF1D8754BULL
        },
        {
            0x0F22448A0337B471ULL, 0xA11FF70F41AE5350ULL, 0xFE60134FCEEEA8ACULL, 0xCEB87194CFDE1CCCULL, 
            0xF165DE5F6440DFB8ULL, 0x4DD9019026EB7150ULL, 0xCBEC5E62B1848DF6ULL, 0x59E5B7203AA4278BULL, 
            0x0E1BD29C6B799063ULL, 0x57B1BF22849F8637ULL, 0x2CCA451B7F759066ULL, 0xDB4E8678E43B0D8BULL, 
            0x08B03BDCCF178469ULL, 0xD8FABEFAB062637EULL, 0x1C24400629614E5AULL, 0xFD4570C7EC093AF7ULL, 
            0xD723EC8718F0340EULL, 0x8F3A4DE51F292B0FULL, 0x27ED12C18C2EDF69ULL, 0x005F7D21C543B8E1ULL, 
            0x59F7B6B9607A6F8DULL, 0x507BA86D0978B3A7ULL, 0x9727C06BB4E3DD13ULL, 0xE337229663A4770FULL, 
            0xE12AA22639C3DAC9ULL, 0xB705545F642F1EF6ULL, 0x6FCB38FB00F06AA4ULL, 0x66AE49705938E283ULL, 
            0xABC34D1E69FD1F61ULL, 0x3481906E148402FFULL, 0x87CF92DACF55BD52ULL, 0x0EDB50A087F5D176ULL
        },
        {
            0x6D1E21E1C1FFEEBAULL, 0x4940BCEF3958E9CEULL, 0x1D7F66306C590376ULL, 0xE70172483AFF0A94ULL, 
            0x8D7BA66976BF4B46ULL, 0x16E5DB6C264D3D33ULL, 0x13894931B7E3E6EFULL, 0x386494429FD9CB16ULL, 
            0x01FE73EC748E6796ULL, 0x328A1DED81E81607ULL, 0xD487599ECA857E5AULL, 0x64C702AD796BDDCEULL, 
            0x69E1957654A9A43FULL, 0x56010DBBD61F84B2ULL, 0x9FFD6F9F3EC671DDULL, 0x754E419197C50DE0ULL, 
            0xA2676C6C89A336E8ULL, 0xA76243F5A3F1EF8DULL, 0x99E96AD96A46785CULL, 0xB20CB03B97661206ULL, 
            0xBAA51B483B412788ULL, 0x4D2D3BA7F7E9E4F8ULL, 0x5C06C55178731B84ULL, 0x5419C0B8C453DBADULL, 
            0xE69A34311BFD5617ULL, 0xD3B42D7C5A05B55EULL, 0x2CBCFBC66031A7AEULL, 0x5C022551691FC359ULL, 
            0x3A2316FDA29EFC19ULL, 0xA920E9045EBD2F26ULL, 0xBF2EB36DA4C0D784ULL, 0xC0D3E2793EAA2780ULL
        },
        {
            0xAA043B3C469A2312ULL, 0xAFA02907DC6675F0ULL, 0x52A271C4A53A0476ULL, 0x9AA8318B10B28859ULL, 
            0xD37AC1FF9999DE07ULL, 0x18B57C19937865E7ULL, 0x628B32D582F4D17DULL, 0xDD503218A3D6CCD8ULL, 
            0x6EC0A9744393E58AULL, 0x7A8E60734674EC44ULL, 0x6924AFF79D95ADC4ULL, 0x0667E820CE372605ULL, 
            0x49099D2C05A14946ULL, 0xF2FD90C276E7EDC2ULL, 0x00BB09C585FA9F4EULL, 0x41D24DAC97054BAFULL, 
            0x44B022563E21CC43ULL, 0xEC7434B2D6EA0344ULL, 0xCE014AAE686508DEULL, 0x24A66CA34947EF3AULL, 
            0xFEF190F3BF8EAC9AULL, 0x9E2BFB70FC3090EDULL, 0x6259B676B1B7F13BULL, 0xF5DFBB4C60DB0C76ULL, 
            0x4A836E9E2D8F346AULL, 0x068F52E81248FD2FULL, 0xAF0E8F577F2767FBULL, 0x4B875EA6386773E6ULL, 
            0xD70B3131D45C2336ULL, 0x3B48DBCAA490999CULL, 0x39141E56C11B7AA6ULL, 0x9AE794791DAD80CBULL
        }
    },
    {
        {
            0x68A1ECD4A0A4923AULL, 0x683639D9B98EC450ULL, 0xF495E9350B526D30ULL, 0xC35C1049EF5298FCULL, 
            0xEAE373B60F3B5E60ULL, 0x1094F9CA0F359550ULL, 0x9CC435ABBD173B21ULL, 0xCCED5A783B5FA0AAULL, 
            0xC0D1775775D6EC8CULL, 0x53ECE9136102C3BEULL, 0x6D785AB812D39764ULL, 0x6954ED9F7851357AULL, 
            0x8308C6E92D1243BBULL, 0x022368F72E9DB604ULL, 0x2A35F23EF36D0FE9ULL, 0xCEDFB5F6484A46DFULL, 
            0x6CECA501AF0805B5ULL, 0x345535BCBA8FE50CULL, 0x1390E7106111F812ULL, 0x4E3C3082FDD89861ULL, 
            0x773F498850B59D52ULL, 0x58DAE6EC9FA9393AULL, 0x59CA58E02935FB69ULL, 0x91C3A4D5A645C772ULL, 
            0x3D94C98FD1FE0D82ULL, 0xCB364A459675F1BFULL, 0x05C55596ED5196C0ULL, 0xE6056AF6CE7F6D73ULL, 
            0xC58256769C1E0409ULL, 0x53CAB25AF5AD2F70ULL, 0x63E9F25F838B2238ULL, 0x83D8EE0427BA4867ULL
        },
        {
            0xE31E17A09CD5E5C4ULL, 0xB7822E703104361FULL, 0x78139C403740F7CDULL, 0x3E585276ED213CDDULL, 
            0x05E6070B5A537A76ULL, 0xC70D1CC2014B3200ULL, 0xE6144C1E540292F5ULL, 0x583D8430BB2E9F5EULL, 
            0x2A270A38F0497DA3ULL, 0x754189D6F3304F46ULL, 0x9B320218BE15148BULL, 0x8A078B3D8152BE09ULL, 
            0xF051A07DCD9A3605ULL, 0xF006790452A1EDD9ULL, 0xCF00E968A0B00E02ULL, 0x555B272F497FF42BULL, 
            0xAAC79EE9D695A3C3ULL, 0x69CEF94080305EF2ULL, 0x191D8DBC00E6161DULL, 0x46CFDB498D4DBF09ULL, 
            0xB2C7FA0CEBFDCB37ULL, 0x58F48ECEF469E4B8ULL, 0xD5C962EAC4EBF30EULL, 0x73074CB63DA227F8ULL, 
            0x0ADF8041B6ED6CE7ULL, 0x864B524FCF17724DULL, 0x121C8D5BE89A765EULL, 0xC9497857FBE65D32ULL, 
            0x3D84B754F36D5657ULL, 0x7AD0B1171696461AULL, 0xE58B81C5F592FE6DULL, 0x9207104DE755DE60ULL
        },
        {
            0x7E6672D7C6FE4099ULL, 0xFDB910DA14703BB4ULL, 0xB2CAE053F8A8031BULL, 0xF832C914A26029A8ULL, 
            0x313441EE0E9F6CDFULL, 0x267ECFED12C9C93CULL, 0x7C0D9C81488668EBULL, 0x705F7B7B3A9611FFULL, 
            0xE43383377477C747ULL, 0xDA2E640EADE834E8ULL, 0x5A7C13AC47A5EB98ULL, 0x93893495FA9EAA30ULL, 
            0x612E29641322BB1CULL, 0x1F2B8B614BF0655DULL, 0xC07DF5C3AF4999F7ULL, 0xF2F9A4D1AB1A0EA2ULL, 
            0x2F37B1EC7A49F89CULL, 0x5886813971D064E4ULL, 0x26B791116727746EULL, 0x3FE7C35595EBFC1FULL, 
            0xC3C8C5C738485A2FULL, 0x11AE8E726C45A79DULL, 0x6EDE30008EC03B64ULL, 0x86364B931170D514ULL, 
            0xC35E4DB842A588F2ULL, 0x88D2B0150DA9CD68ULL, 0x3613423B40D4CA4BULL, 0xA5EFD86E69949C65ULL, 
            0x60DAB65D4C025AE4ULL, 0xF9B040A2D1D119BCULL, 0xA2895BF0E749A121ULL, 0x033F0737697A2491ULL
        },
        {
            0x69D5BEA37D8ABF9AULL, 0xBCDDD19EB83AB3EFULL, 0xE7543CF285E41359ULL, 0xC2375B9D474F2A04ULL, 
            0xD26BCF1B2DA6A198ULL, 0x4358B5B5603521B7ULL, 0x6DA3247113B21758ULL, 0x3FC98128B5E32171ULL, 
            0x54467F2507293395ULL, 0xB7C8CA27B0E3121AULL, 0x461FC451821EFF1AULL, 0x4611F327C3FA2629ULL, 
            0x893375EA930A822EULL, 0x96D1E38D5A973A2DULL, 0x8B69FC6034208151ULL, 0x5EC7A7D71A9CE505ULL, 
            0xDB2BB27FF5165A52ULL, 0x92FB17D11A1732D9ULL, 0x51CA6FCE8AA57C87ULL, 0x85C27C44AD9E0C2BULL, 
            0xE242F7B181A95FBEULL, 0xC9FDDC1C275D7A0DULL, 0xAD8F8B223360E762ULL, 0x7ACF3F699B7BC0BEULL, 
            0x0419A0B4C29875CDULL, 0x2E5B4F3957F8798BULL, 0x4FCB474104ACCF4FULL, 0x5698C63323640EEDULL, 
            0xF0BDCB0D249FE5B0ULL, 0xC0255C3AD6A37AAEULL, 0x5CB1C22EE23EA2C2ULL, 0x9574247A45B849F6ULL
        },
        {
            0xBADDBBAC8A369AA5ULL, 0xA3D006E1BBE1888CULL, 0xBDC35C92406AC216ULL, 0x76456E97C66BC690ULL, 
            0x57540224A7FAB403ULL, 0x30A8E506FCFF0E38ULL, 0x8C08270FD74F6093ULL, 0xE5A09B77AE5DD51DULL, 
            0x1D95C5240056BA4CULL, 0x586649004DD998BDULL, 0xA4491547BDC8AFFBULL, 0xEE1637D23CEA5D46ULL, 
            0x9C2E011E63B03737ULL, 0x5BEE32FB1055DF79ULL, 0x5C18527F7D55965EULL, 0x11DA8CBBDA38D760ULL, 
            0x7DAF98083ECA8BDAULL, 0x7422231F3226E094ULL, 0xB2B4457ED88FF240ULL, 0x787D572539FF802BULL, 
            0xBE9B3CC28C7C5439ULL, 0x4308CC64F4B1C2FCULL, 0x489D2778B9F8E898ULL, 0x3BE5E27249112559ULL, 
            0xB19F31AA83AC70C5ULL, 0xB6DD8C67FF2AB806ULL, 0x3AFA5AA80F920DA5ULL, 0x8B52366D03159BEDULL, 
            0xE1CE52205968C6DDULL, 0x8D90D914DB515FF1ULL, 0x8606FCFC0A14D8ACULL, 0x8448C32E612A7BF7ULL
        },
        {
            0xF0C9FFB064E2F9EAULL, 0xB951F9EB02367A7EULL, 0x6277D028A21A041DULL, 0xEC13F5DF86394FE9ULL, 
            0x05A80FFBDC36DB62ULL, 0x5517C42E1A273F1EULL, 0x81C6DBB6BEE544EAULL, 0xE398E248B7BCFB15ULL, 
            0x4ABBA7DFB95713C5ULL, 0xB5D73F859F9B897CULL, 0x6C91FAB494814F14ULL, 0xA7420E77E50A8068ULL, 
            0xBD74A2EDA813D663ULL, 0xF5656422660722FBULL, 0xF88FA1A69F8D5416ULL, 0xA111D0A32224CFDFULL, 
            0xC87BA217248B0BA9ULL, 0x2B5DBFA5D27649C1ULL, 0x4D6052BD931AAC6EULL, 0x254D1E09296CCCE9ULL, 
            0x17B8FD59EE31FC2FULL, 0x2E042BFC95FF8E05ULL, 0x0EBA903C519419B1ULL, 0x0A8640B4D33F6EA0ULL, 
            0x82CE3FEA0590DD50ULL, 0x06D997C27FD4FF14ULL, 0x53730B99E93AE177ULL, 0xACA40C8823DE52DDULL, 
            0x225DA3E4F4B13B2AULL, 0xE503FAEC0EFB1044ULL, 0x0F08A00DD2F6B2E1ULL, 0xC47FC35F625FA2D6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseEConstants = {
    0x4E24C718274B5FBDULL,
    0xB0B85AD3ECAE62DEULL,
    0x942D596B22736299ULL,
    0x4E24C718274B5FBDULL,
    0xB0B85AD3ECAE62DEULL,
    0x942D596B22736299ULL,
    0xC44911854C61C697ULL,
    0x39A5A944EE527B7EULL,
    0x90,
    0x5B,
    0xB1,
    0xB1,
    0x96,
    0x8A,
    0x5A,
    0x7E
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseFSalts = {
    {
        {
            0x2D4AE1CC6F711E13ULL, 0x38B351F21EFD408AULL, 0x89C953D0462A8817ULL, 0x1E2236F4D0F9134EULL, 
            0xE7AF4DF8A6CA9B42ULL, 0x16A0CF5DEDF0C853ULL, 0x1D03AC8FD76E1F9FULL, 0x30AD0D5791777D76ULL, 
            0x7307F40FF5FE4E0CULL, 0xC7006FB7A0127771ULL, 0x1AF75F28BCA06326ULL, 0x588548DEA7AECDCAULL, 
            0x7EE760841395BD69ULL, 0x816DBAE3313CD5AFULL, 0x7169530B8013FD09ULL, 0x811D2AB23ED541F3ULL, 
            0x1A248455DF46D1D5ULL, 0xF632056836CF4CCBULL, 0xF82819512226CCA3ULL, 0x6A76B159A4AA63E1ULL, 
            0x22A9D6E32BD587A8ULL, 0x2FEDB605995B839EULL, 0x2183CEC899669244ULL, 0x75DB2F10673F0554ULL, 
            0xBF33E9815CF0BDD8ULL, 0xD8CF5D0DE13B8EC4ULL, 0x2B9770D0C20C51F8ULL, 0x2A5F10ED57D7D331ULL, 
            0x86CD7B668AF98CE3ULL, 0xC9721A5BCD6B7202ULL, 0x5F9315166506A7AAULL, 0x70B59B8F9706C914ULL
        },
        {
            0x28F855751F52F133ULL, 0xBAECA2BD818185D3ULL, 0xAB9901B9870D5482ULL, 0xFE2D4100F6630106ULL, 
            0xEF2E4D3F29F70617ULL, 0x9A2CF46F6C09432AULL, 0x0660944386AD5753ULL, 0xFDD68CE2183797BDULL, 
            0x37E2B4894450FA15ULL, 0xBADF063FD982C6A3ULL, 0xE68E4CF0EF63AA43ULL, 0x41C48FE6F0BF9E6CULL, 
            0x483912AA8F6E5EADULL, 0x9A5B068F97318D9AULL, 0xDD6ED20F3CC0092CULL, 0xB4754EDB302F3B7AULL, 
            0x094DFFA73B0C03E2ULL, 0x306BD5DCD217D538ULL, 0xD130A9450C45B1A8ULL, 0x009AEC977C4B2E0BULL, 
            0xE7409C8251056392ULL, 0x7C258048F653C99DULL, 0x8A4C6AC687D282E4ULL, 0x2ACF73F8819000DBULL, 
            0x75CF28FFD50B1A24ULL, 0x3DEE4BD0CF5BE799ULL, 0xCFB758F41FA78D9BULL, 0x974AA2D5CCE75F72ULL, 
            0xE3F143C764EECB11ULL, 0x20BE1547EFCED6E2ULL, 0x9E2BB6B43FB7AD4DULL, 0xB746756439EC030FULL
        },
        {
            0x4970756466617F14ULL, 0x37085E1BEE011A4AULL, 0xACAD6095E87C0877ULL, 0x66A16B6B73ECBE25ULL, 
            0xAB640DEC31BB292BULL, 0xD635D2150EBFAFC8ULL, 0xAD44B391A3332D9BULL, 0x5D8EFFF3526FD7FCULL, 
            0xB506DE6AA09DDCD0ULL, 0x745CCA87D1B29144ULL, 0x587255C3DDA0475FULL, 0x60BC3644B0DD455AULL, 
            0x1413469716284E94ULL, 0xC30A8B5FCF0F860EULL, 0x831029739F41DCF6ULL, 0xE7B46607B3E3E0A5ULL, 
            0x30B30992A6A3906AULL, 0x51A6A9876FAE9C44ULL, 0x7F835F196E1F8675ULL, 0x8F5CA34976ACBE98ULL, 
            0xA11CBE971F557820ULL, 0xF9AF627F4C88C3F9ULL, 0x1EF82DD6C22910CDULL, 0x519FA664942D7196ULL, 
            0xED56585EE3DD73EFULL, 0x5F0B37AB2101BD1EULL, 0xC47C8C029D6698F6ULL, 0xCAD5EF1C1F5929F1ULL, 
            0x35210984C6D43725ULL, 0xCB8F6917EB36A47AULL, 0x6558C43E4C40A5CBULL, 0x8F6F8085447B72ABULL
        },
        {
            0x762CD3388BB7C678ULL, 0x2DDF613D118134BBULL, 0xF5A16A234EAA1437ULL, 0x74BA0E1222F4DE41ULL, 
            0x6A0F8E1A5BEEFAA5ULL, 0x9D79CF8CC229005BULL, 0x6B68B29CD753AEBAULL, 0x6A890CA6F6E1DF9EULL, 
            0xE57F936568CB3681ULL, 0x8D8DEF65923024FCULL, 0xCA884606E356194FULL, 0x278C46D1CAD11FA9ULL, 
            0x45A4E7AD0AE51295ULL, 0x17CD75A871160FF6ULL, 0x94F369FAA6229A07ULL, 0x4FEF21BB33CBD375ULL, 
            0x17D98225E63A2331ULL, 0xD5CF8F8C8FACCE5FULL, 0x041BEBFB163D1C90ULL, 0x6CD2694C85C60E7EULL, 
            0x0AAE25FB3884E4C9ULL, 0x288D665118246986ULL, 0xC577C9454C1EB5FEULL, 0x6318F3291DF2D4DBULL, 
            0x2D5A7310C9DB2C70ULL, 0xE58F2DF2DEC5CFCFULL, 0x63FC1D365D60BB52ULL, 0x5D1A46677ED84389ULL, 
            0xD127C2666174B033ULL, 0xF9CD55B2705391BAULL, 0x83BCCD1C467E2E33ULL, 0xA3E4103C1D9D08E8ULL
        },
        {
            0xC9D2D2176BB77AC7ULL, 0x92E39F9CCE3EAF1FULL, 0x6B46138D2C09FEC9ULL, 0x58CB5A7F97C998CAULL, 
            0xB026D9A9EAFECE99ULL, 0x365D5476C624CC11ULL, 0x63E7FC58A44E5F22ULL, 0x05F53B8C23E35742ULL, 
            0x96D2FD35A3AEA78BULL, 0xAE4EEA31635C888CULL, 0x4EB08827B54BBE90ULL, 0xB718D0051773F87FULL, 
            0xD81BF84BC89D8B72ULL, 0x5D7CB8597C24FA4EULL, 0x3E67E617D5448494ULL, 0x0204DF1EB32273A0ULL, 
            0xD8FD49DCA0A31F75ULL, 0xA7CA72E0880049C4ULL, 0x83A4AF6317E62779ULL, 0xFC7F297AFC2F5616ULL, 
            0x24FDF1A864F061FEULL, 0x45225987B0716CFDULL, 0x04437C7DEA12C3A4ULL, 0x3E042A07C18CCF85ULL, 
            0xD590D27F732CA135ULL, 0x4CD562EB8293294CULL, 0x81AB5F179C8BD8A0ULL, 0xBE36147F54953298ULL, 
            0xFB1D57B1217B7602ULL, 0x701A3D671D5DCF65ULL, 0x36CB2F9704BC035FULL, 0xF8B914F94FFDC564ULL
        },
        {
            0x98D5BB88B459083DULL, 0x8AF7F37E1115B119ULL, 0x236EA349782E5AFCULL, 0xD6E5FA2CE967A4F2ULL, 
            0x6BB23F978C7D58D5ULL, 0x4E8E364BAD7A3707ULL, 0xCE776EF77C940388ULL, 0x6324A8B7C69F1F91ULL, 
            0x134E8E18B89B4468ULL, 0xE237D7C6647D0CD2ULL, 0x0BEA4BE05456776AULL, 0xF42E8295C2E9541FULL, 
            0x961BBEF49DB2A2E9ULL, 0x7D450EC9C705C062ULL, 0xDD805845FDABB8A3ULL, 0xF416FFC1569DA9AAULL, 
            0x0F20432DCA9871E0ULL, 0xDA5C092070DAECDEULL, 0x6E86F5E8A7072255ULL, 0x7BE638CBA91376F0ULL, 
            0x1FEA13DC9332DBBEULL, 0x6AE44368C6D9F5AFULL, 0xDCC8D915DB405F14ULL, 0x64D1093ACDC334DFULL, 
            0xF4D9828322DA7FD2ULL, 0xF83CD0093515321FULL, 0x432AB5969D329C00ULL, 0xE27FCBA45D2BE310ULL, 
            0x5E1E71C375DECDD4ULL, 0x5B37D2031E40B650ULL, 0x7089CBCA9C97EF98ULL, 0xC2B9FA611CAAD9D4ULL
        }
    },
    {
        {
            0xE48252E977CCE4C7ULL, 0xB90CF265BC18E8D8ULL, 0x35B7740DDC0F1B28ULL, 0xF719A29097F28C68ULL, 
            0x1D5769E52B95F30FULL, 0x72BE9D4CA18ACD88ULL, 0x733768F8591CC915ULL, 0x009B82F24FD561EEULL, 
            0x05F3E83D2BEA6A0AULL, 0xC14421395650394FULL, 0x133CA9DF3956EED8ULL, 0x085687C768A14C37ULL, 
            0x3F40CA3BE266F320ULL, 0x0C383C467B2421B4ULL, 0x29F5C168BD9145A7ULL, 0x5BDFC4E4400A95FBULL, 
            0x9C69C6795EAD8AD3ULL, 0xC3696A22F9070A53ULL, 0xABF1CF29BAD91246ULL, 0x5DB7FDB0F9F2145FULL, 
            0x335F3F93AA132FC4ULL, 0x289EDBA014BCA337ULL, 0x8FFDEED4CD39A983ULL, 0x8DA532AE3E9DB3F1ULL, 
            0x41C49FDEAD7337BEULL, 0x45D47A474FF9A803ULL, 0x37C456A4F63AB3DBULL, 0x1C1AD88F618AA956ULL, 
            0xE2EC2B605C3123D8ULL, 0xAA9AB1911D8E8AD2ULL, 0xBFC8F519236D89AEULL, 0x5777EBA1C4D1B5ADULL
        },
        {
            0x7974F580C6366BB4ULL, 0x055B5924CE182F01ULL, 0x1D1D27C07421EE67ULL, 0x518B196BF8C8D255ULL, 
            0x0CF87A515CF2B346ULL, 0xF26B38B91CB20BB2ULL, 0x2E88DFC834361C19ULL, 0x50D390B15A1E3133ULL, 
            0xAECECC69745B2628ULL, 0x10AB922D248AB078ULL, 0x714DA9770D2A0465ULL, 0x1ED74335494A7176ULL, 
            0x2B9CE0FDFA498D61ULL, 0xB625FEF0A7EA41D9ULL, 0xC25E2F773BECE841ULL, 0x6A68AD593F77FC84ULL, 
            0x9885F0A180A32505ULL, 0x80BA4A8E5B55F8C0ULL, 0x69B8FBF74A7A287EULL, 0xE8B20B1D8706D105ULL, 
            0x2BE8E9A5AE2CC874ULL, 0xABAD685625157515ULL, 0x90054E9750C36A65ULL, 0xE2D6BDD0A3E40328ULL, 
            0xD2A92A721F28B4D1ULL, 0xBBAC304B1C700BBFULL, 0x33FB55EE10E95717ULL, 0xE74D70D298EC280FULL, 
            0xB7010E769842F04AULL, 0x6D691F6FB2715A86ULL, 0x3595AD34DEB9894DULL, 0xDBEB24707F9469EAULL
        },
        {
            0xE9BE7ABFD5258782ULL, 0x1B141E0425E2672BULL, 0xDD59C2FE47FC40CAULL, 0x7CFA549A249B894DULL, 
            0x038FF3977741A000ULL, 0x5B727A3A07A1C0A1ULL, 0xF7E3A2F52A3FF2B8ULL, 0x7C07B466A184D21DULL, 
            0xF51728E848409844ULL, 0xC560D1802355078CULL, 0x42068533F7A9922AULL, 0x4E056565D0E4F559ULL, 
            0x9B61028902922BF4ULL, 0x09DA2693F803592BULL, 0x9C42D2678EC51E23ULL, 0xE0AB2958E2CED71DULL, 
            0x84F6220A67557931ULL, 0x435123B21BEDCE8BULL, 0x508CE0BD5AD381AAULL, 0x27722CCD504884EEULL, 
            0xB44500BDF73369C0ULL, 0xF726660A3EFE06E4ULL, 0x8F2AC562AFD483FFULL, 0xDBA1AD5C70E14CF2ULL, 
            0xA1F7214365766614ULL, 0x8B3BB4CAFF74C339ULL, 0x019A24A0FDA66EC4ULL, 0x5B752CD64017E082ULL, 
            0x17EB9842C9029553ULL, 0x317D617E3F6438B1ULL, 0xD1B1349FCCBA8FFDULL, 0x41574BC9670EDD46ULL
        },
        {
            0xA4E285B63CD2D9D1ULL, 0xD0FFBEB34BAFE9B4ULL, 0xC103073554467FCBULL, 0xA10DFCD4A73CE73AULL, 
            0xABA6F32B849619B0ULL, 0x9DF598604F872622ULL, 0x059B75D1436D1EEFULL, 0xBFC63436D6C431CCULL, 
            0xF793D0BDC31C6DC7ULL, 0x27FE4E9A96E5C2DFULL, 0xBE456AA01E7B1698ULL, 0x7C960F770E13D9C4ULL, 
            0xE45F75DAC77DE6D1ULL, 0x570AAAE46587F852ULL, 0x1234F6C2EE564DD7ULL, 0xAB924C978FBA96D7ULL, 
            0x577BA2820A1C21CAULL, 0xF71B253C19936EC6ULL, 0x2C5247FB51B8FE54ULL, 0x285D56A2CBB1F2F2ULL, 
            0xA4765C29B0A0FA2EULL, 0x6B2D26E389C2F3B9ULL, 0x8DFB0E5F4F7D09CDULL, 0x13F56C8CC796D29EULL, 
            0xFA18B20745D01AFDULL, 0xFA2302862BC66749ULL, 0x949DA71ABDA34A42ULL, 0x6567594C7D3A123EULL, 
            0xCC2CD05A8C8DA6C8ULL, 0x2EA011CDF632330EULL, 0x4E20B3845A917F8FULL, 0x9B3B332E50B45C76ULL
        },
        {
            0x84CD1D97D792E746ULL, 0xA13BC07F6C67FB7DULL, 0xE5079BA0B0654AA3ULL, 0x82FC170D23E31D61ULL, 
            0xD7C67BBD038883F9ULL, 0x09D89CA97B1A3A21ULL, 0xC4650E1B428E8AADULL, 0x4052DB85ECABD947ULL, 
            0xE13044309C7F2FB1ULL, 0x88CFE205F85363E6ULL, 0x7CFC3CD156C71FCBULL, 0x21C4B5FA7FFC091DULL, 
            0x5FB82D0D1622583FULL, 0x38096443069B499DULL, 0x673C415543B71609ULL, 0x8FA4F6D5147E02F3ULL, 
            0xEA04CB8B4865214FULL, 0xB5AAFCEFFB6CCFC7ULL, 0x88ACAA671F05E541ULL, 0x2B08F8A29EAE8E52ULL, 
            0x5E3300BC2E1ADFE5ULL, 0xC2DFF3DFA3CF8A4EULL, 0x83BD26A636B3E9F2ULL, 0x787959D4D8CCBAA4ULL, 
            0x3BDF0F12EC509E5BULL, 0xDBD30D7D0D8AB5C3ULL, 0xA10F0C4E3DEC4AFEULL, 0x3D9AE6E30EF999AFULL, 
            0xF1DAF36E32220717ULL, 0x2B9F26276D1B12A7ULL, 0x15C289625E3D874CULL, 0xAA896F52477285D4ULL
        },
        {
            0xFB129AD258544CAFULL, 0x789F0FB2F8AE2360ULL, 0xDAC1CB43A41E00E0ULL, 0x5932FE6A1883CFB7ULL, 
            0x1E2A0F4C410F4E2AULL, 0xBBD76AE94C8B50FFULL, 0x56993D5C0DBEA624ULL, 0xD93777FAAA9BB857ULL, 
            0xFEBF5C9101AFC351ULL, 0x829C16FF011AE403ULL, 0xA6118FB5A3C88C3DULL, 0x70C68A8A6F85E863ULL, 
            0xE8E79301BF6E895CULL, 0xA4F4BDF29085EB52ULL, 0x9D77A6DFF91A1C54ULL, 0x59BA68817193238AULL, 
            0xA1AC37E7F0ABB282ULL, 0x5570051EDDA910B4ULL, 0x2AEC1D1016FE3923ULL, 0x272D34D16888E034ULL, 
            0xA271A348DC481D37ULL, 0x6F969A6146FCF8B4ULL, 0xB15115A1526C86F9ULL, 0x16B04B6902D3B098ULL, 
            0xB4C40B2984BC1D76ULL, 0x84308197F3FA9A86ULL, 0xDCE08EC4D0754CC9ULL, 0xE13C3212B08CC0BCULL, 
            0x10226B11638425D9ULL, 0x5846704C63C3C8EDULL, 0xAFCBAF189372B7C2ULL, 0xCC25146DEAC0FFBBULL
        }
    },
    {
        {
            0xFE844A5758F573DFULL, 0x25BC037B6FFAC186ULL, 0xF4CE1EBC5DC1FC76ULL, 0x963F381E48768B65ULL, 
            0xF991932EEF4BE29AULL, 0xA23C8C116E3064CCULL, 0x081951DC918AA97FULL, 0x47F23021B1749F5DULL, 
            0xF049FD339DC163CDULL, 0xB7EEC2B13A400FBCULL, 0x4A5C073F1A17A370ULL, 0xA0DD1D3B078D96C1ULL, 
            0x52C7FE237EAFFB3EULL, 0x5B6E9ED96A10BD37ULL, 0x4E3FCDE9F5C16A76ULL, 0x41E8F57DFE57430AULL, 
            0x83811EF42B2CF0ADULL, 0x114E3616911ECA66ULL, 0x6E66E3159FCE365DULL, 0xC3F7038B38FBBDE1ULL, 
            0xAC655D6FC460343DULL, 0x50BD9D02DE103DC9ULL, 0xFDD29027579159E2ULL, 0x2DBA7C5C3E0861D7ULL, 
            0x6CB7B00BACE4B628ULL, 0xC8887C91AD60F57EULL, 0xBE94A0F2CFC56E15ULL, 0x850751EECCB547EDULL, 
            0x25C7226EAEA8AFDFULL, 0xEEEDE7AA82A697F3ULL, 0x6D20159EFEB7E799ULL, 0x1AD08128680108A5ULL
        },
        {
            0x932F0AA9A2956C5AULL, 0xE329AC7F152561F0ULL, 0x90A17373151706C3ULL, 0x394EB9FD7465CF18ULL, 
            0x11FC5B7939CACAACULL, 0xC8CD43FFB40E4029ULL, 0x580D1B1A4DEE65F0ULL, 0x0AEFE687B618530EULL, 
            0x69776896838A4B31ULL, 0xD52A9516E2AE9B21ULL, 0x484A51843F937104ULL, 0x4FCB56002E46E1A7ULL, 
            0xDBE7F19E43F5A60BULL, 0x5CAFCF0C4EC3F165ULL, 0xA54BEB46E188C755ULL, 0x449E36A0910A59CFULL, 
            0x71CE214CDE4E8468ULL, 0x8927B83FFF9CBFEEULL, 0xB9FB84D3C4B67044ULL, 0x2463151A7037733CULL, 
            0xA3BFD63EDDF55A2AULL, 0x5573AF515BBCC4F1ULL, 0x74E0D2CCB9EFE3D4ULL, 0x373C6DA3F7EB23ACULL, 
            0xD80BC84319D83C77ULL, 0x8C3179239729C001ULL, 0xAE65937D4DE179E8ULL, 0xAB252255F59A9249ULL, 
            0x8F2E6D0C08A444B7ULL, 0xA276A440FB81AC0BULL, 0x259F093F323BABC4ULL, 0xF040D90EC1A3E3D0ULL
        },
        {
            0xBCD701865F768CF0ULL, 0x7AE9F94DDD2FA6B6ULL, 0xE61770395336A314ULL, 0x67888CCD4435B36CULL, 
            0xBE339CBE3A1FE04DULL, 0x74DD7F47A1CE3887ULL, 0x25D7898F87F9AC46ULL, 0xA364B85B9332CEA6ULL, 
            0x53692800F0413E86ULL, 0x05EE7D7462A4C600ULL, 0xAF732AAB9B1DFB18ULL, 0x186CA45812EB274FULL, 
            0x77C4A848A6AE1CBAULL, 0xF265B9ACF547837CULL, 0xC5C7FECE85E17F49ULL, 0x69641D2869B0282CULL, 
            0x76BB1770332ED390ULL, 0x6DF5EB089545B605ULL, 0x72F85B50E584EB7FULL, 0x2281BE9414FA9E4BULL, 
            0x0B5031FDDC8F3678ULL, 0x76C25EE8C3D094FCULL, 0x219BCB5C31197840ULL, 0x7F2D95E569505400ULL, 
            0x3CD9D292E308F772ULL, 0x3D6FD3839EFCF4E9ULL, 0x82E6D91D256F5DA8ULL, 0x6E071DD6B7D9AFB7ULL, 
            0xC8755172D774363AULL, 0xACAF102792847752ULL, 0x0327C949AF1AED95ULL, 0xF3217EBB267FCEE1ULL
        },
        {
            0x83CA83781627A9DEULL, 0x33DAEC4CEC311093ULL, 0xEA441F5CA7AEF40BULL, 0xB9F5FC3486B4E303ULL, 
            0x67BE8A431FE98294ULL, 0x833267174FE8D78AULL, 0xD6C0D9B2CCC73DCCULL, 0xB232C85031C660D4ULL, 
            0xCF667CE13B4CE894ULL, 0x16607523B5436F1BULL, 0x7A38FB4A69B3D981ULL, 0x2DF92E491A995622ULL, 
            0xC7C5DA4C8EC3E75AULL, 0x329619901A4C2379ULL, 0x395317F8B27FC3A1ULL, 0xA2D8D9C5783345BFULL, 
            0xA0979896A6EEAD19ULL, 0x66C690E7AA7B2ACEULL, 0xFB75F4CA4FC56F23ULL, 0x671D8E0A60937569ULL, 
            0xC5901212E24F7F04ULL, 0x35B2C1FFC9A79B1DULL, 0xE0AA66D518525AA1ULL, 0x34DF8CD70706628FULL, 
            0xD95BA0C88AFCB35DULL, 0x1F030AFDFBFDFEDBULL, 0x775AC0AF65054102ULL, 0xBE1ADA19416282B6ULL, 
            0xBB93B918C8F00A8CULL, 0xA89385DA3444B4D5ULL, 0x606E17AEBFFE2A9CULL, 0x3D80994E0324C724ULL
        },
        {
            0xEA68370CF4F9697DULL, 0x586778C37DA522BAULL, 0x3A8F0B3ADE1E1B68ULL, 0x20574A8D7E40BBCCULL, 
            0x4B553717C8B44253ULL, 0x4B68D5FAAEB64502ULL, 0x775DC160F8176632ULL, 0xB098752326DE7799ULL, 
            0x1DE3DD2D747BC114ULL, 0x2E7666AFFA63C1E4ULL, 0x8DE562B911509A70ULL, 0x67752EB2E9D6FD3BULL, 
            0xBDFED334A8E7FE0DULL, 0x713B2AD413A6BDF4ULL, 0xF1B66C1B3ACCF7D5ULL, 0x761991018275C4CFULL, 
            0xCB46DA5A3EE33A92ULL, 0x46AA475DCA520DB8ULL, 0x5125FC2A30EB501DULL, 0x96B4F48478F97A3CULL, 
            0x4269E4E1745A43C8ULL, 0x437A75B2929D171EULL, 0x89E1EF5B55208C9BULL, 0x6502F0CC268327FCULL, 
            0xF1E6D30A9852D2D1ULL, 0x001BCD7EAE2D0DD0ULL, 0x7598A9496547C1D9ULL, 0x06F4F7D795581B0DULL, 
            0x78D013EC02E5B096ULL, 0x2130A069999938D2ULL, 0xFBD0D78CDF97F8C8ULL, 0xF24F988E2096490DULL
        },
        {
            0x80ACB51A7105A5BEULL, 0x0A6F9006BCE607CAULL, 0x9288D4932869F8FAULL, 0x7BDCF43EF64FE89CULL, 
            0x5030E21E65153966ULL, 0x1C0C296C9A1A5CFBULL, 0x5DDBB0F2E9F3B468ULL, 0xEA068E9E663DCDFFULL, 
            0xCDF81181AF8CFA07ULL, 0x8E4756DF330E1572ULL, 0xDD44B502A3F8D3E6ULL, 0xC0D8E06DBDBBAC08ULL, 
            0x64BB4494D0B96448ULL, 0xB07755001FA26C58ULL, 0x0843C6BEF3AACAE3ULL, 0xA53C7B05982FF23EULL, 
            0xD19137053692F1C2ULL, 0x4D9D457D13397A1FULL, 0x4EF2BF5FF59A1271ULL, 0x13A5DA5C4AA87D7EULL, 
            0xD0839F5E4ACEBDA2ULL, 0xF9776E8303E1CCE2ULL, 0x7E1B07AA6CC7C7A1ULL, 0x978E21DDF660F47BULL, 
            0x80BB374F9E92E3EFULL, 0x79D4433B641B0FE0ULL, 0x37DA8540A8E8AC4DULL, 0x060DFC27D3A82E45ULL, 
            0x7272FCE60DA90E37ULL, 0xB682E3A364AFA42CULL, 0xFC95A0AF5E1AB891ULL, 0xE025AE5724CC4839ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseFConstants = {
    0x4E6710D9DCDF7610ULL,
    0x40AED83EFC331431ULL,
    0x212EC2AFFBEF5C29ULL,
    0x4E6710D9DCDF7610ULL,
    0x40AED83EFC331431ULL,
    0x212EC2AFFBEF5C29ULL,
    0x3C21920AABD82A1AULL,
    0xA83174E53FF669FFULL,
    0x76,
    0x38,
    0x9E,
    0xE2,
    0x24,
    0xAC,
    0x8A,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseGSalts = {
    {
        {
            0xD5687872271A0415ULL, 0x754BE002BFA59E4AULL, 0xCCDB7E1A28196855ULL, 0xADAAB70DA08DAC24ULL, 
            0x94BC237E0BDE54C0ULL, 0xFF26AC26CDA26091ULL, 0x196FE956607DBA0EULL, 0x9862011BE5D2F641ULL, 
            0xE999AC14F5EA383FULL, 0x80622892A056EDA8ULL, 0xCB029A3DF7A4AC2BULL, 0x212DB285047BAE69ULL, 
            0x230EDF955AD5D6BFULL, 0x580EB628FE1CF39AULL, 0x8F238A89FEB7D387ULL, 0x6A6D7E3B9989ACADULL, 
            0x6CA0E91487334B01ULL, 0x8FB0AE3FA2333BACULL, 0x8C6FC27D39647D18ULL, 0x1B98C6B593F3D895ULL, 
            0x426D547599143384ULL, 0x94F9FD29545557B7ULL, 0x2F5B43B0BCF32335ULL, 0x7CF98396FDF9AB01ULL, 
            0xC54EF59134EC8BFDULL, 0xEF60A2779C595F73ULL, 0x341B86D1F47879D5ULL, 0x61CD7303CFB91A4CULL, 
            0xEEABFB031F0C6456ULL, 0x059C3CAB9FF510FEULL, 0x2E628876EB5B63B2ULL, 0x7BE2AFF4281F148CULL
        },
        {
            0x7D45938D626B3976ULL, 0xE5A3D0BA35F12F74ULL, 0x038666F8A7E07826ULL, 0xA2501E3888952B47ULL, 
            0xAF616CF78E525586ULL, 0xF4A1C93C5DFF9726ULL, 0xC07893CF6782CA39ULL, 0xF52D43CF6320FAB0ULL, 
            0xE1B59BE6A93E6AC0ULL, 0xEBC1C1E03271D896ULL, 0x0E31E5D9399F841EULL, 0xD732EEE83759F1AEULL, 
            0xD12ACC8A4144B48CULL, 0x58336557C0D0C6BDULL, 0x68D008FA1CE78AE8ULL, 0xBA244CF3DE72EE82ULL, 
            0x14DDF7FBE881EFC3ULL, 0xE044600925952002ULL, 0x4D7B92EE48B8BB86ULL, 0x9DAEDD7F67A410CEULL, 
            0x1472C8D1E108E4ABULL, 0xF5C67AF54D8DA361ULL, 0x545A74767E7FC281ULL, 0xAF52D379CA0BEDB6ULL, 
            0xB2187943F55AC883ULL, 0x55269FC365C20017ULL, 0x0998179B601831B2ULL, 0xC0B3BB17E17076EBULL, 
            0x14C85C2BECA27616ULL, 0x521E08F5314B8AFBULL, 0xD1F53096E2A3C89BULL, 0xA901E40F2E961808ULL
        },
        {
            0x4F58D8C4963C8DC8ULL, 0xD80B909124F4A4CEULL, 0x9C813765DB9853C9ULL, 0x023A3D292DBF551FULL, 
            0x50073D6D1C7F1C65ULL, 0xEA2F8848A83890D0ULL, 0xE1523BF57D83B98BULL, 0x83978967D293E2C1ULL, 
            0xCBAEE1C10375C842ULL, 0x15A8F60F71B744B7ULL, 0xF9F837D2A98F7861ULL, 0x9FF80B2AD9100094ULL, 
            0x44FEEF3573B9ADB2ULL, 0x43D71BA87C3A19E9ULL, 0xBD200F7C0AF20379ULL, 0xA76C74C367633440ULL, 
            0x5EA043A2DA54ECA6ULL, 0x1500269B09313067ULL, 0x2ECF193505FA23EDULL, 0x1FEA3E499ED81F11ULL, 
            0x38B706FE943BFC87ULL, 0xC9F432CF41E8964FULL, 0x51C612CDE23A8074ULL, 0x76F49947594B30B9ULL, 
            0x52B9D2C315053AAEULL, 0x4A9C27B2E654C20BULL, 0xFF8B10A767EE0B1BULL, 0x9AB03DA4CA5B6A1FULL, 
            0x2DDFD71EE5E8F1C2ULL, 0x75F7E16499D535A2ULL, 0x5A4D59543055626AULL, 0xFA1CBF38231026E5ULL
        },
        {
            0xB931BE3092BF0B70ULL, 0x21584ECDC520F6AEULL, 0x8642BAE0C73DDE5EULL, 0x75B256EFB7858760ULL, 
            0x90AE5B505FE7F7CFULL, 0xECEE1B6F33134918ULL, 0x8496F7B9F32797F4ULL, 0x19D2FEDA18BCB7F0ULL, 
            0xACF91669735E56C5ULL, 0x514333B53383FA37ULL, 0xA14084BD557CC694ULL, 0x1E4F6A48191AB3A4ULL, 
            0xF036BFBBB5761E4EULL, 0x6C6FA2F0E69F3E45ULL, 0x3624B708EFD29DA6ULL, 0x79667C9557110C96ULL, 
            0x9607BCFE97FDAF51ULL, 0x8E1F7793EB31CC6FULL, 0x06F7473123BA7785ULL, 0xAB48FAB7C5A2810EULL, 
            0x7DF99D61DA622005ULL, 0x398544D2E41BE8D6ULL, 0xA9619CE97E08D6FDULL, 0x6F4EF56BA3F68A8DULL, 
            0x9F0E19D01FDAD478ULL, 0x8BEF4FF89B94632AULL, 0x7C616E928961D910ULL, 0x0556B4F4657B1370ULL, 
            0x050D170A474E1F9DULL, 0x2417F79C41A371E1ULL, 0xC195653AA8EC5853ULL, 0x1CC7D5D0D35870F3ULL
        },
        {
            0x70485177CCAA6CC2ULL, 0xDFA43F92A5C85C00ULL, 0x343C7677A0225C04ULL, 0xFB093E80B219918BULL, 
            0xCDA2B0F8871975CFULL, 0x0901C5B42436EC16ULL, 0x63A2A6EC0EABE442ULL, 0xDDC2F732FA1404C1ULL, 
            0x3ACE59BEAF5345DCULL, 0x3E45636935BE912FULL, 0xB5BD83DCC4DBA0C8ULL, 0x156891C93586A771ULL, 
            0xD92A2C081C74C78DULL, 0x90E403A808EA36BEULL, 0x1FDCE66A1DFD443BULL, 0xD71870C22C40A3BCULL, 
            0xBB632026025DBA9DULL, 0xA3F888F12A9D7783ULL, 0xBF5F46FBEAF8AEB1ULL, 0xA7D6A42300C40841ULL, 
            0x9BF933C9DAF8F148ULL, 0x95200FDA67BB38FCULL, 0xAE3F7C18E74E73F0ULL, 0x88B0848D076A6CA8ULL, 
            0x0154AE70E3F3508DULL, 0x60376DE82C40B258ULL, 0x323796D410574C47ULL, 0x3591E6CE7538D131ULL, 
            0xD578151D2F7B4BEBULL, 0xB1F4D39E0590AEA7ULL, 0xD316C997B0EE5AC0ULL, 0x436C96E5A955637AULL
        },
        {
            0xBC910D339984A040ULL, 0x3DD33BAFDAA5989FULL, 0xF2AE061BD566B4EFULL, 0xADA7444B81213DA2ULL, 
            0x9BB6FF26C9CE5EA8ULL, 0xFA05B8C8D7170A60ULL, 0xDFF199948D36BFDBULL, 0x175902C1FB78E635ULL, 
            0xBD3ABBDD602C1BA9ULL, 0xA804042A1B81ACECULL, 0x157344DDD01D0D3DULL, 0x4BD37432B437B800ULL, 
            0x50BE31A631970E1DULL, 0xD4CD9F2090F2FE87ULL, 0x0CF6A534507042BAULL, 0x8B548AAF40B724FBULL, 
            0xB455E93CC6B84786ULL, 0x9D32F632B98B86AEULL, 0xAA098A568F12B5D2ULL, 0x4C6D7519A4D5A13CULL, 
            0x059733D9E8A90BB7ULL, 0xEA32766B717EFB9CULL, 0x8E125E6F4DFE951DULL, 0x005B4D798C0CD4D4ULL, 
            0x745E2B1D5D4D390DULL, 0xC83D3F8B6612FF33ULL, 0x8C3AA3E3A09DC01CULL, 0x081D4C9150BF99CCULL, 
            0x5CA0E8B2DA79D6CDULL, 0xEA443685ED14F96BULL, 0xA6CEB0204715F57BULL, 0x850A05E627B6701EULL
        }
    },
    {
        {
            0xCDF2983905A325AFULL, 0x6DA135052E22B0B3ULL, 0x83DB2365497DD9E3ULL, 0x4512295859F96A6CULL, 
            0x233B23551E4854A1ULL, 0x46A6C8A463C7D9C1ULL, 0x676C4847C6DF9EB1ULL, 0x22D0C3E4E82AAA93ULL, 
            0x50D3EF40D32FB0FCULL, 0xDA78D5ECD8C27CAFULL, 0xE9C32543DA0C5F2CULL, 0xDD77D114EF42688CULL, 
            0xA25ED66D604FF4DDULL, 0x1974156EF8D98CABULL, 0xA9627DAFFC3F0942ULL, 0x3F31E47897889385ULL, 
            0x047CF79AAE3D96A7ULL, 0x9536B9B16FAA5D5BULL, 0xD7739434E5081A67ULL, 0x272E0D7EBADEB7BAULL, 
            0x6A8F692BA6459292ULL, 0x05AE704473BF8AD2ULL, 0x0503B7AAD99EE70DULL, 0x29E523A83FDA040CULL, 
            0x124682974F8FE473ULL, 0x5E5EAF5802E57A54ULL, 0xEFEA77B1407C7A64ULL, 0xB61EE9A923F8637FULL, 
            0xCF63A176CF982B2AULL, 0x82FA48A8F60FFB8FULL, 0x7CD437BABF39C5F7ULL, 0xC51AF9C5149995F5ULL
        },
        {
            0x7BDE57459B7F03F2ULL, 0x8EC5DED93B5FDF10ULL, 0xAE6AED74BE7A0DC5ULL, 0x47AF92C96BA87FC7ULL, 
            0x4797DE9E9EE4AFD4ULL, 0xE37E227B06EBE4A5ULL, 0xAEE434844AC7C939ULL, 0x27F7EB0F8E527089ULL, 
            0xF92D14D3521A49AAULL, 0x06836068685B77D9ULL, 0x8D9DB912B2322553ULL, 0xDF9195EFA3A340AAULL, 
            0x9166288DC54305FEULL, 0x5B4AB21CCB8C3757ULL, 0xB2C70EE67C0E7CACULL, 0x77ED849ACF3B52F5ULL, 
            0x89CD17E4A65D2EFEULL, 0x05E3C3A84CBF1730ULL, 0xF595BB39D3983B3EULL, 0x174841CF621E9A01ULL, 
            0x433472E70E9C8433ULL, 0xBB3D63F7417B6BAEULL, 0x7D69FBF8B1BB3FBCULL, 0x99A20AEC994BDEFCULL, 
            0x9C483C137DD5AB96ULL, 0xA1D0B6B91CEC8F0EULL, 0x4A6830D8DEF7EA74ULL, 0x19CA368CEBD79100ULL, 
            0xCA39A809F3B7F074ULL, 0x8666C36D3CDBEA7EULL, 0x79B3600C7F493CA9ULL, 0x3026CBF113E130F1ULL
        },
        {
            0xFB6F73526F6D4E11ULL, 0xC8BCCDAB27DE55AFULL, 0xBCD20846AE4627E3ULL, 0xDEB617201E70B332ULL, 
            0xB4F618903489B895ULL, 0xA922B105BE4F90B8ULL, 0x1D75CF440269B682ULL, 0x9AFA819F65BDA59DULL, 
            0x23D28561633BF083ULL, 0x47FC75535C0BC214ULL, 0xC0FD7361D24D8906ULL, 0x5F3A35A6D94FA960ULL, 
            0x194220C44F5F4DF3ULL, 0x44A4B16DA836C6B2ULL, 0xF72C00B5307D97A7ULL, 0x3ACDA89A162AC8E0ULL, 
            0xE7C80621672AE64FULL, 0xD29FCFE558C7316BULL, 0x69F0968BC6212809ULL, 0x4AF6994126528B9DULL, 
            0x905E7727ADFDC0E6ULL, 0x7B555D42E49C5CA7ULL, 0x825BB87873AB6A44ULL, 0xDD39D8CE2CA191D8ULL, 
            0x65696743D30B9E39ULL, 0x3E73FD301F56CF3BULL, 0x72C7F4E9251FCF20ULL, 0xEFB049ECF0E70314ULL, 
            0x162575581A0C0E7FULL, 0x3D4CA65A51ADFFEBULL, 0x12A9E0D7D8F2C71EULL, 0x46E3C955475F89F4ULL
        },
        {
            0x8362D5ECF64C44D1ULL, 0xC54759E5EB19AE60ULL, 0xAC695BEC120C1D1BULL, 0x6C77BBB059CF60D8ULL, 
            0x910511DE25FC92F8ULL, 0x4B6B2AA8132ECF53ULL, 0x1FC7E30DE848907FULL, 0xD395241308D72D39ULL, 
            0x95DE4D107F8C9258ULL, 0xDB42601C22C13119ULL, 0x3968B492121D1570ULL, 0xDF72BAD9A9912352ULL, 
            0xEC78B3159E08EF5BULL, 0x5027666BA4CAAC22ULL, 0xE39FF50090D03112ULL, 0x6D34721BA8BB6A09ULL, 
            0x4A24A93981196943ULL, 0xA3F54D85DE08FF93ULL, 0xB1F2F2DE24CEB6BFULL, 0x6FB87F23E0962AEEULL, 
            0xCC406F65078F86D9ULL, 0xC55D75D8BA4F7102ULL, 0xD36B99295D931EE2ULL, 0xEB13C777F3D4DCE6ULL, 
            0xD8974516A1308C1EULL, 0x481EEEC652065BA1ULL, 0x1268CDAABB125B21ULL, 0x8F5AE2510237275CULL, 
            0x3963CB07B9A4B22CULL, 0x39001BB63E117EA5ULL, 0xB77F16AA4173A1AEULL, 0xCA718DD7ED61F1CAULL
        },
        {
            0x71483AA80D034737ULL, 0x555B94C0F24A31B7ULL, 0x66E4DB29DE66625BULL, 0xB9245E0CA02AFB37ULL, 
            0x8080B0A82FBFFA6DULL, 0xD821329CAB89DDE9ULL, 0x066936A916CA3189ULL, 0xB331BBD066F7E57AULL, 
            0xCA394891BF839221ULL, 0x21F300194AB25453ULL, 0xBA3BF95D99E30F39ULL, 0x84A5B8FA36B902B0ULL, 
            0x8E5E1DD41486AA0FULL, 0x03A6DE98CD3E4B60ULL, 0xB2B8A4157B49358AULL, 0xE232A15F6C813893ULL, 
            0xB43DB44515DBCA69ULL, 0x29A936E932563670ULL, 0x00CB3DC909FA8A10ULL, 0x0C5EC20E44C88C4CULL, 
            0x623623BA5A615684ULL, 0x630B59413A4E2401ULL, 0xED966CD6421003AEULL, 0x0E65449119C80654ULL, 
            0xC4BCC925A5F34621ULL, 0x87686BBA45AB97F0ULL, 0x90594ABB48A05FE4ULL, 0x99F8657191CD0A03ULL, 
            0x7E895A6ED90B1DABULL, 0x75443C7EF9EAB26CULL, 0x081A248C2B5BC747ULL, 0x56DE3E975532E4CEULL
        },
        {
            0x4517A1EBC38D0BE1ULL, 0x9174F06921DDCC71ULL, 0xB1B19D4897B308CCULL, 0x097D2B705AEEFDC6ULL, 
            0x23A53DC9AEA4761BULL, 0xBCA1E39DC6132959ULL, 0x3D4B6DE52F84DF3BULL, 0x0FEC1D8AB8AA9D4EULL, 
            0x87B270302FD4333EULL, 0xBAE84C1FF8B8016DULL, 0xA4B1A03B27F54D8DULL, 0x2A0FC9797C5E66D4ULL, 
            0xF03FD50C8E685F0CULL, 0xF8F917F7FF57DD03ULL, 0x9CA06D8152457E4DULL, 0x847D2F75BE4F734AULL, 
            0xC03D34713F792D2AULL, 0xE214038A99AA5D8CULL, 0x244E62773DC2AB5CULL, 0xAA8BB5AEFBAB5BCBULL, 
            0x64B91109453DC006ULL, 0xC8441C9B3A881D94ULL, 0x0566C3CECE0E48C1ULL, 0xD3487124E3428398ULL, 
            0x0EEE7CBC5D95A497ULL, 0xC30B520BBE0B5A86ULL, 0x65A49C784EBE9EFFULL, 0xB8161B9D1C87B42AULL, 
            0x84DE6BC952E7C16DULL, 0xC5725FE13A1D23A9ULL, 0xE493555932013875ULL, 0x4485E9C6137F4D2AULL
        }
    },
    {
        {
            0xE4AFA786C492B841ULL, 0xBCE198F0BF6F84AAULL, 0xA8ACAF4E95CFB81EULL, 0x1F3F8B6E83C019B3ULL, 
            0x589ABF736B134EACULL, 0x2B411B57F20DA495ULL, 0xF009EB3BF076363EULL, 0x95A2D3839787F6DFULL, 
            0x73C8D861C454A060ULL, 0x6E8CE7984CC5CAF4ULL, 0x039C97105C278544ULL, 0xF0949187D741A74BULL, 
            0x68A16646107D9486ULL, 0x8C32B3F1D246444AULL, 0xD34C7E19E5649EA8ULL, 0xD76BE86654925237ULL, 
            0xC6FCD0A5D2B9FA0BULL, 0x7EA69451F45A691EULL, 0x7A80B864CF902DB0ULL, 0xF74D1DA8410A1C37ULL, 
            0x90430267A2B0F2CCULL, 0x3F3DBEEF870A8976ULL, 0x986DC9EDE385B304ULL, 0xEFD06FBA0B46A171ULL, 
            0x0EE0F959802D008AULL, 0xC914C5528C9D64B5ULL, 0x30A3EE29293FEEF7ULL, 0xE572C401A3F9F28CULL, 
            0xE94E0FA872559980ULL, 0x703307F997353D09ULL, 0xDD732BE77A64E353ULL, 0x29466A32ED58CE8CULL
        },
        {
            0xE7F679B4F5417B23ULL, 0x7C57244ACB35F4A8ULL, 0x3CAD4753C265B701ULL, 0x177A4EDBBDA371E7ULL, 
            0x6A96739D563E577DULL, 0x24053D0EDD5CCBA2ULL, 0x7F8F145EF1015894ULL, 0x7B5C288DBC337809ULL, 
            0x681BD34887FF6CACULL, 0x0691EC2E9F56ADE7ULL, 0xD16D4682F0F9299BULL, 0x93F370882A86F82EULL, 
            0x3A4EF796694DE01BULL, 0x1647D0C7FD4F2A7DULL, 0x3CE63257E1548DB2ULL, 0xDFAC7E462DE605A0ULL, 
            0x98E2A1658BF889E2ULL, 0x97D8E29A85890C2AULL, 0xF1257DD06C0A1340ULL, 0x508FE32C2DC4D39CULL, 
            0xC944AE963855B815ULL, 0x1AD5B0E49D11CC04ULL, 0x7500BC65D14FB3E1ULL, 0x969272E43385CBDBULL, 
            0xEC553A7B7918277BULL, 0x467C04FB95C3015CULL, 0x214AF4E036BCE02EULL, 0xC33905F2F707FF8FULL, 
            0x9A867EE9A9C44DAEULL, 0x44522D371FBC8D48ULL, 0x152DBF1C23EB5C44ULL, 0x7D2D86E57F956421ULL
        },
        {
            0x9CB014F097059020ULL, 0xDB9E57B327E74177ULL, 0xD2E4DC48B6EC265AULL, 0xBD95A0E7BF01746DULL, 
            0x32BC92A5214A9124ULL, 0x8C9DC930BC91623FULL, 0x758DEC1A683FD55CULL, 0x972D0E61892E2D73ULL, 
            0x3B6E8FC651715ECCULL, 0x67323347E9C4DFA0ULL, 0x529F68323ECBEAF6ULL, 0x040C20955385B18EULL, 
            0x5AF79C83A8EC688BULL, 0xBC5DA7FC06FF8788ULL, 0xFA43FA57FAFE154FULL, 0x22B8BBC6205306F8ULL, 
            0xEAD2C95FF23C04DAULL, 0x45FBDC6ECA506825ULL, 0xD781684A01BFF5B9ULL, 0xBE94591196F835F6ULL, 
            0x2ECC784EFA68D082ULL, 0x056B6D6D779CCF0CULL, 0x14197B55852B0D79ULL, 0x07F4297CFDD6DB6DULL, 
            0xB625AA2A0AC4775DULL, 0xD30FBB661093B6FDULL, 0xE3F77E5AE7E1428DULL, 0x5D196745158C5C05ULL, 
            0xB97D2263D29F494AULL, 0xB2ACD0A65D1DB6E4ULL, 0x9F067AB109579797ULL, 0xFDD1396F8B93C18FULL
        },
        {
            0xC1CD14AC5BD89045ULL, 0x3295F281E1489032ULL, 0xB47EB87BBF43E40BULL, 0x26FAFA4CDEB9FBFBULL, 
            0xEC6630CC1E17B028ULL, 0x4C992D12514A7AE5ULL, 0xBDB08E0D665C7123ULL, 0xECEE3D5192A033FBULL, 
            0x2A8625020143CC2BULL, 0x143ECD46C02D806AULL, 0x9447406BFCDB6B4DULL, 0xCB6830E849B1005BULL, 
            0x3CFB81E6013CC917ULL, 0x106F2D3F075A9DCFULL, 0x889CB60991BB7E60ULL, 0x550F891ACA2AC007ULL, 
            0x958A3BD3281FE762ULL, 0x7FAD1E1D48ACBF7EULL, 0x18B925E1C4B3CA98ULL, 0x3297B408303E5A7CULL, 
            0xB7AE29360EB79C22ULL, 0xDA14FA1667A3BF9DULL, 0x8E271F13D360993CULL, 0xDB7592E615E6EB65ULL, 
            0xC32F049B2C04DE59ULL, 0x606A41175AC3EB9BULL, 0xE926F90BE049332FULL, 0x9774AFD5282B90B4ULL, 
            0x316D3F115C76084EULL, 0x1D3A639B4094BF43ULL, 0x7FD7EAA0B06618DDULL, 0xD9052B2AE0B0214EULL
        },
        {
            0xF5FD77157850E51CULL, 0x556252AB299185EEULL, 0x03C966305932CE0EULL, 0x0916A7C7A5772D6DULL, 
            0x7B57F896138F6D39ULL, 0x3A9CF3FE530903E7ULL, 0x1F158CC8BD1C5B5AULL, 0xD36F0F3F8F69FD3FULL, 
            0xB7278306966754EEULL, 0x326A8766E265A8CAULL, 0x5D37892BB3FAA3FCULL, 0xFDE50A2CBF0BEC12ULL, 
            0x23614F2AE15E4A18ULL, 0xDC880E6FC380C7F4ULL, 0x0A5E365F2D670805ULL, 0x50A2AE63E26EC9EEULL, 
            0xB7F2510A0A4EBEFCULL, 0x0A65942E937757A6ULL, 0x980A16F6978BBC55ULL, 0xC6F9753519D7D05DULL, 
            0xA0429387B110F459ULL, 0x9A617E7D3890594DULL, 0xF624E66F4A80EE6AULL, 0x5BC1C6A162687B58ULL, 
            0xE38D7115AC562F5EULL, 0x333B3CD0D2BE0793ULL, 0x628F9F83CCDBCEF0ULL, 0x54577CB068B0EE72ULL, 
            0x95987209A69EDBCEULL, 0xD64D6FA54B11305AULL, 0x3CA4FA578A2B6762ULL, 0xCA70A4BE4063F2C6ULL
        },
        {
            0x65D92FE2872B39B3ULL, 0x873B84C910E64408ULL, 0x2DF65F9C526196DCULL, 0xE4B46CD22E4C0636ULL, 
            0x5C49A541AAC0DCE8ULL, 0x2903567E47F92234ULL, 0xF3AAB37932150A77ULL, 0x877276A574CAF28BULL, 
            0xD8A75CB805386A50ULL, 0x7BD6810456EA13C7ULL, 0x464026BBB5059732ULL, 0x1861D0E6D3263D4DULL, 
            0xBC3B3023E5BC59CBULL, 0x2FCF514405C37271ULL, 0x1DD90059599018F6ULL, 0x58278DE71D900DF5ULL, 
            0x6E1D7E681F996C56ULL, 0x29CFBF7F4B8205F5ULL, 0x763601980224745FULL, 0xB28C3C1BF7E39DD9ULL, 
            0xBA0D2B7762A7DEA8ULL, 0x35B1F4CEFDD99C68ULL, 0x027016A573962C9FULL, 0xFA84B68AF45ADE5CULL, 
            0xC067527F50529DDFULL, 0xCE69A1B6E1FF85D8ULL, 0x8FA1D8E4A0F3AF77ULL, 0x8596B679777548E7ULL, 
            0xA9047A77E0C499E1ULL, 0xBA3EA89C2EAFCE4BULL, 0x960F4041A8C19197ULL, 0x40A30B827DA28531ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseGConstants = {
    0xE77813C0C1DA334FULL,
    0x17C724401CB9236DULL,
    0xF0C76F6E69831D78ULL,
    0xE77813C0C1DA334FULL,
    0x17C724401CB9236DULL,
    0xF0C76F6E69831D78ULL,
    0x09CB20FD5E002D38ULL,
    0xDA057EDFDF74F503ULL,
    0x5E,
    0x5F,
    0x17,
    0x5D,
    0x61,
    0xB2,
    0xE5,
    0xEB
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseHSalts = {
    {
        {
            0x7C371A14736871D5ULL, 0x147A78D0EF98BCB7ULL, 0x10EFA5777F3D166AULL, 0x8B4D51DA014709E7ULL, 
            0x6FB41344CDA7026CULL, 0xA6B8EC6BC0FB4B9EULL, 0xC61551081AB4D89EULL, 0xA00F1B6EA9E5FFA1ULL, 
            0x8E3BA69EA0638C88ULL, 0x2D3A6EC952B1C894ULL, 0x3482A6C510B03EE0ULL, 0x441BF76399F28E1DULL, 
            0x6A646733F7F56B20ULL, 0xA7196F196F78BEB2ULL, 0x4C3350960668BF8DULL, 0xD57C00AEBB4567D5ULL, 
            0x33ED9D2A644EF796ULL, 0x633DB8E718D136F6ULL, 0x3CD992EDB87E970AULL, 0x759FFEFDF81876F7ULL, 
            0xA403CE62FBFFD238ULL, 0x8B660381ECCAE3E8ULL, 0x3466DE0A44A7A4D8ULL, 0x0401A2BD607CBD7EULL, 
            0x5FBFE5D02BBCA5B1ULL, 0x80B9A5F68D5A3BE7ULL, 0xAB4101201E266A41ULL, 0x0720496B45FCFE72ULL, 
            0x19EE84EDDD98AC60ULL, 0xE29D62AC4AAC9B75ULL, 0xC176F4F3DF9E9525ULL, 0xDD80084CFE72CF60ULL
        },
        {
            0xA51C82A3A37CB44AULL, 0xEED4E7642C818C88ULL, 0xC2C9DA3CB3E20B5BULL, 0x18EAE63C9134AFC1ULL, 
            0x314B1CDEE13B01F8ULL, 0xC71325031F440A2EULL, 0x44116622D1841B2CULL, 0x21C6BA90055A17CDULL, 
            0x14DAD1B11CE53AE7ULL, 0x8FA906A304CB9C40ULL, 0x8B364FEA7528CC82ULL, 0x6607BED197FB8D5DULL, 
            0x855DD61DB54EE163ULL, 0xA296B5576AAB8EF1ULL, 0x99B71E887B14E33CULL, 0xC5FB62313D858303ULL, 
            0x76FF47F7B9CE46AAULL, 0x2FA095488CE3FE89ULL, 0xEBFE2EE7C5AE8422ULL, 0xC0CE6F5533E4B808ULL, 
            0x1093D4B73D26CED1ULL, 0xB292E1526888BBD2ULL, 0x3258537169D52A1EULL, 0x286BE655EED12BF0ULL, 
            0x6F5E02AB6568D6DDULL, 0x4767419179DCBE40ULL, 0x11E91A2F2FAEA0B3ULL, 0x5EC7CE77FFA84515ULL, 
            0x9D813A86B568F117ULL, 0x7542D1D134D0316DULL, 0x15E021A83F4469F0ULL, 0x9182BD60273083AFULL
        },
        {
            0x60173207B3C43B63ULL, 0x82BA88AD1441D9D6ULL, 0x711EA8210EDACE25ULL, 0x72389FB8D1FB2ED4ULL, 
            0x8B9C55E1A93C5E41ULL, 0x63B5843AA3CDEB37ULL, 0xF8D9CE2CC2E7C5B8ULL, 0xDC459965A1A764A7ULL, 
            0x239F8E0E1DB32579ULL, 0x7E9D0DDA95309C2CULL, 0x7E7FBA1CA89D8B51ULL, 0xFB5D61D2EC01E367ULL, 
            0x7C8ACAD78EF3CD5DULL, 0x0DB5EB40733F7D1CULL, 0x4B72E9E7E738ECBAULL, 0x0CAC213D757F9106ULL, 
            0x043F0C491C5531B6ULL, 0xF5132AE2DF4FE11FULL, 0xFC12545AF5F55070ULL, 0x0060EA7D021553C5ULL, 
            0xF8648B03838E9DACULL, 0xF349C6FE66503563ULL, 0x4107C5CCC9298E2DULL, 0xEE393C9F67A6F555ULL, 
            0x2777D034085C0BDAULL, 0x394682866DC95483ULL, 0x1E23EAB3AC2E2166ULL, 0xABEBA8BE44255387ULL, 
            0xD91A8CD6350ECEDCULL, 0x6686F35997FF378EULL, 0x94AA11941492ABB3ULL, 0xBB88A718243549C7ULL
        },
        {
            0xDBD07F6AEDDBEBCBULL, 0x3828B9A26240EE6AULL, 0xC9411611585E5854ULL, 0x1871BA33DB5E7BE1ULL, 
            0xA009F07772026117ULL, 0x727FE2FCCB107C52ULL, 0x5B3F6508ED8D2C56ULL, 0xA0E7824E72CFCAC5ULL, 
            0xB48F4520FECF5DC8ULL, 0x8B18A31B0171C822ULL, 0x4A00CAD2107FF7A6ULL, 0xAF0D8A0B2104F94AULL, 
            0x6CB1DCDE5E7778D0ULL, 0x973E112D93E8D275ULL, 0xACBE99F4A1EE3099ULL, 0xEC551D6611813745ULL, 
            0x117DEBBB54512028ULL, 0x5394DA0914CDA744ULL, 0x25914D37110814B5ULL, 0x0E5C8D7CDFB2F243ULL, 
            0xA7362D7182998586ULL, 0xAFBB9498A0A7A604ULL, 0xFEF0F7904EC851DBULL, 0xEE5192A062A28E34ULL, 
            0xA386F2A82A6A5B1EULL, 0xB921E12A14637BC2ULL, 0x524B3D4FCEAC56F8ULL, 0x27E510A30FE4D7D2ULL, 
            0xB4ABF3697D1184A0ULL, 0x62A6A6FEDB2B182AULL, 0xFDDAC62FAE1926DDULL, 0xD83BE951E453A4AAULL
        },
        {
            0x35AF77133AF88489ULL, 0x97199D4371B23449ULL, 0x96B1F40B0645B951ULL, 0x75F5A8AEB82836CEULL, 
            0x747E2F9D1085BA47ULL, 0x311C5474E19E9215ULL, 0x8F7C583849AB6D15ULL, 0xF8BC939F6536E5BFULL, 
            0x4DF8FDE0BFBAE038ULL, 0xE7691BF623631E55ULL, 0x2A7C59F5EC6EBABAULL, 0xC13BFEC48DC10F25ULL, 
            0x9992D31FD4087CFFULL, 0x2DF44874D3D00A2EULL, 0xE78152278E98765EULL, 0x76FA046FC979B75DULL, 
            0xAE99FE698238FBB2ULL, 0x9293FBBF3EC326E1ULL, 0x433F1522C5D1BDD4ULL, 0x46A76F17DA707EC5ULL, 
            0x1E4A9AD8744047E3ULL, 0x78A899E7A87495C3ULL, 0x8DA4C71138F9B23EULL, 0x5D9D9F99249B36EAULL, 
            0x05CA6BF526B6343EULL, 0x859B964DE2FFE72EULL, 0x4BCA8453B8819AC9ULL, 0x1E0090C789EF2E2FULL, 
            0x08DEFA6CAEAC6D1EULL, 0xC32A8EEDE170C501ULL, 0x083D7534FC8EACBFULL, 0x2D6670D379973CF3ULL
        },
        {
            0x9576B008292924DFULL, 0x038289D19BFD6F85ULL, 0x52167FA45EBD2306ULL, 0xD3114BA0FAECFA82ULL, 
            0x7891F171D292A0E2ULL, 0xFE4C47CF2EA22E3AULL, 0xCFE9FCF06D6B6B5EULL, 0x14854F64BD7D84B4ULL, 
            0x15AB0F5C5CCCD1E2ULL, 0x3B4813EA2CDEC820ULL, 0x6791C4F65624AA30ULL, 0xEA949B19681066C6ULL, 
            0x4F7766C0322E1F96ULL, 0xF73D7CE9A9C90C43ULL, 0x2F93640DE3C25D73ULL, 0x156B1E441EA5E6F4ULL, 
            0x98F589369E7A3665ULL, 0xE01E4C647A279331ULL, 0xC783A95D3AE8F2B2ULL, 0xEB6CA4D2D957E1B7ULL, 
            0x86897022717D4A5CULL, 0x7AEFD53E2E815D15ULL, 0x7BFC90C798F91656ULL, 0xE311637A3136C624ULL, 
            0x0DDF7F9FF98FC487ULL, 0x4CC366665126819DULL, 0xE4112CB80B32FE35ULL, 0x23BFF9E99CFE873BULL, 
            0xDB3B26CE537A36DBULL, 0xD5976622C2E4FB5EULL, 0x96A697EA0D1168BCULL, 0x26DCCA40DD5ED2F8ULL
        }
    },
    {
        {
            0x05793C8AA1E7DD3AULL, 0x2DA1BA3E95755162ULL, 0x95C20B1064728639ULL, 0x2B58ABA3C09F46AAULL, 
            0x5CFA580BC350748AULL, 0x2A9546D1B204E053ULL, 0x7F39226015B16792ULL, 0xF574D8C04ACD4ED6ULL, 
            0xC9631938F32D7CE5ULL, 0xE52A4008F448B4EAULL, 0xE4FCD381A19552EAULL, 0xC443B67E196FE5F5ULL, 
            0xCC51C461072719B8ULL, 0x76F4DDE5AFC48C3BULL, 0x3A1D02C1A19DDF0FULL, 0x706A11018B6E5428ULL, 
            0xFC26233BFFCB2479ULL, 0x5EAEB68B22631387ULL, 0x13A2E4E8D5E02659ULL, 0x8B435137369A0040ULL, 
            0x09906028A1550016ULL, 0xD91A0567FCB3618EULL, 0x0D43223153A5D37EULL, 0x6A507185A6B77683ULL, 
            0x32CB4F2ECED5EFDBULL, 0x369DC3F28A33A4CEULL, 0x3A2A5B1CB2CA4DD4ULL, 0x55948EC3A7E046C0ULL, 
            0x7FDE3C107A4CB314ULL, 0x9D85488D86A0A510ULL, 0x931B3943CCCC6A68ULL, 0x0C8B089F1A332B70ULL
        },
        {
            0xDBD08FE39304F03DULL, 0xCC714B5B90E2288CULL, 0x223440DD29F66BA0ULL, 0xEF5E9B39334A1A14ULL, 
            0x2578FAB4026D1F46ULL, 0xDEF67DA05E323B7CULL, 0xDDF5B0F7935A3748ULL, 0xFCB0B2977D89B6CFULL, 
            0x971DAFCF76ACC95FULL, 0x6201AF2A44E6CFB7ULL, 0x0CBCD146D6CB4851ULL, 0x71FBC2F284F73CBFULL, 
            0x093F0E2122FF3F61ULL, 0xB6175307C80CFF3CULL, 0x9D098B8F16BF8D59ULL, 0x48D5C23395171D76ULL, 
            0xE159AA1365CC2EE2ULL, 0x44B7342E22C5C34BULL, 0x0A636C86208AAF38ULL, 0xF28499F2C81BEFBEULL, 
            0x461A735CDD319501ULL, 0x67E0703E6934C40AULL, 0x8540A9115F177ED4ULL, 0x92873CEC3258C4BFULL, 
            0x59D3936AA0D7A1A2ULL, 0xCE1633AA4DE896BEULL, 0x28FBE6DB328C7F1DULL, 0x6F3B984EF645F655ULL, 
            0x63542CCB7AA7A03CULL, 0x05D7608DC2CF8C8EULL, 0x2621D058831D83C3ULL, 0x484F26F8612DA819ULL
        },
        {
            0x8593D24958952027ULL, 0xB271EEBF48159459ULL, 0x7E44142A4024A874ULL, 0x7C57161FBB96301CULL, 
            0x2D6EE8EFB82B0BD8ULL, 0x71ED5289CACD218AULL, 0x2E0F3B2406340BE1ULL, 0x8EF37308F5AA64F1ULL, 
            0xD9C55DA44A20182CULL, 0x51EF9078D18FAD2FULL, 0x5C40147DF14AC628ULL, 0x1838CCFF5B34A9B5ULL, 
            0x62D635CB8310D02AULL, 0xB624175747080A63ULL, 0xFFF482F3EAC5CE08ULL, 0x44E97D15DD9CC8D0ULL, 
            0x67360AFB48DCED77ULL, 0xCCAF038BD83550C1ULL, 0xBE8CDC6ABA2BDB14ULL, 0xC87D099CCCB8D84BULL, 
            0xAD042F9CAABC75AEULL, 0xFA87C78532570A97ULL, 0x8BC9E015D77F7FA4ULL, 0x91D17245D5D3046FULL, 
            0x484B5D1786E88ABFULL, 0xF706BFF8E0B863F2ULL, 0x4C49F60DC3896AB0ULL, 0x4E9015195569D4DFULL, 
            0xA188A337FA15E544ULL, 0xA17C285BE974BADAULL, 0x182EDEE3307E7D0CULL, 0x88BD63CD9CA1ACADULL
        },
        {
            0x80670AF12B01B35BULL, 0xE00E68F1F94FC876ULL, 0x6466412267CA6F66ULL, 0xE9A7FAFCCAA6C1A2ULL, 
            0xEDE5F8F089FEBC56ULL, 0x2EF1FF8006D09D79ULL, 0x361762193BE6404DULL, 0x8C44FF2917EF8D0FULL, 
            0x03D87D7B660EF66AULL, 0xD0121F48CF8BC089ULL, 0x00362F081792DF23ULL, 0x0492A39C0123F13DULL, 
            0xD601708A3B7BBC0AULL, 0x37E3AD585EC8A080ULL, 0xB76DC9CC4E4B6CAFULL, 0x9F36E308CA9264CDULL, 
            0x875A3D889E681FCBULL, 0x4FACFF1B082CB61DULL, 0xDCFE5775EA403EC5ULL, 0x5FEC41F7DED7A946ULL, 
            0xB72D0ED1EBF22A21ULL, 0x83B6F43160C553D2ULL, 0xB64BEE6494D07D4DULL, 0x46F25F4ED9BF6596ULL, 
            0xF9877FB0802DC9B2ULL, 0xB5DADF4B7D60B72AULL, 0xEF3FFE7FA11F01AAULL, 0xC57CE201FA6EEF41ULL, 
            0xC09678CFAF3D1B1DULL, 0x4415E2F8138F1D3BULL, 0xE30FAE55F96A3858ULL, 0x5BEBB6E061916466ULL
        },
        {
            0x9EE08E691FE679F3ULL, 0x17EB802A3B3789BBULL, 0x2BF5010408749C7BULL, 0x5C4BA1FCBBF17344ULL, 
            0xAACEDCD7BF650025ULL, 0x8CF57DA4E30D4DE2ULL, 0x26F5AE09509BE56BULL, 0x134F2AE38EFB4AB3ULL, 
            0xF044523B67165DC3ULL, 0x60634F13A9AE1A5BULL, 0xE7E4AA72EE6D8484ULL, 0xF7683BBDDD7FCD95ULL, 
            0x703D7C144BB5104BULL, 0xA645A1FC29EEC2DFULL, 0x64D848435709BE04ULL, 0xF141F48C01104FFBULL, 
            0xC3BBBC17CBB5C593ULL, 0xF75083E4AC9CBC97ULL, 0xB52E742C2A49BDF6ULL, 0xCAFA3E36FAA9864AULL, 
            0x35C8B59C97CC26DDULL, 0x3C0E93F70A977981ULL, 0xE616A5F8A68DC1E7ULL, 0xF03EBB24D3B18191ULL, 
            0xA8DFF7259CF6B302ULL, 0xE785B390808FF0DBULL, 0xF656B0CDC3CDC19BULL, 0xA7CA241381BB2C06ULL, 
            0x073B1E566520D5EFULL, 0x72858CFE1F398D93ULL, 0xAD3405F1E657D7F1ULL, 0xE4E223A732AD3752ULL
        },
        {
            0xF0E6E48E242F8BA3ULL, 0xA4F7BDF9B74B9C34ULL, 0x9861B21498CA148DULL, 0x0B5B6F0E6BDD3389ULL, 
            0x277D927C5ED4E170ULL, 0x3C6FF59AFCDB2858ULL, 0x344D4095C891E9BAULL, 0xBF2714AAC1CDE9F0ULL, 
            0x33E9562C8D717C0AULL, 0x19F45AE73E96753AULL, 0x110893522E4A1D5FULL, 0x44822EF83E184A42ULL, 
            0x5A4AD480760653B8ULL, 0x4F14F21BC6DD1CBBULL, 0x6B3B79189C7C5542ULL, 0xDFCF831F605E326FULL, 
            0x0C11B58A1CE26CD4ULL, 0xE27F8EBEF08308C4ULL, 0xFC989E8DD9F6478CULL, 0xC5874DA73375949DULL, 
            0xA68E312A6FEF9C6CULL, 0xEBA3A2ADE139F18AULL, 0xD89B356B20A37841ULL, 0xC2EF5DEAB6B4A065ULL, 
            0x0B6B1B88E5EE4512ULL, 0xB826513BAABEB3A4ULL, 0xE8068828AE44951EULL, 0x322E3754A11F5C22ULL, 
            0x63D45CEB441D32A5ULL, 0xB71141F430C4A330ULL, 0xF315195268EE2949ULL, 0xDAE887A9CBAA3B48ULL
        }
    },
    {
        {
            0x9A78483C3695F962ULL, 0x9225B674D825F1B2ULL, 0xD5E9212DA8B2CECFULL, 0x22B93E356D2C1AF0ULL, 
            0x2329933AF162DD32ULL, 0x4286058D66B6D0BEULL, 0x07DE2C372C3588D9ULL, 0x4963F6875BDCA3FEULL, 
            0x131ED394ECAE407CULL, 0xF8D4505934DED18EULL, 0x4EDF65F1E8BED6F3ULL, 0xF8A29DF65408CFB0ULL, 
            0x5369DA87AE17800EULL, 0xA1E1DB7A10DA5A9EULL, 0xA313CC465A2859DBULL, 0xFBE3EC80941166D9ULL, 
            0xD6CA8F37924E87B1ULL, 0x722CEC0A0E3340F3ULL, 0x6F84BD5F6E61B0C6ULL, 0x9F423591DF6451BFULL, 
            0x0F22FB162F6C64C0ULL, 0x7880E9DEDC93ECC2ULL, 0x6C6581D8392AE513ULL, 0xB2769F0ACD55AEF8ULL, 
            0x11A9DD8B452D389AULL, 0x4074DDB2769C9F80ULL, 0x79ACA1849BDEDE81ULL, 0xD2608A80564818A1ULL, 
            0x5ED36E05F487C13AULL, 0xE42E6A006D4F7968ULL, 0x5E057EE0E4539572ULL, 0xDFF9D55B6B1A84ADULL
        },
        {
            0xBE7DFB175E0FE9B4ULL, 0x65C58F0769A7BF41ULL, 0xEC3EC60A4E320288ULL, 0x7DC16B87E370F4E5ULL, 
            0x614552DDB6E002B2ULL, 0x241F5AB1167D2AC6ULL, 0x50F86076CB307833ULL, 0x2B299DD612B07278ULL, 
            0x5BB0BCB91EA83375ULL, 0x7B0A6389886A84C3ULL, 0x60AF40C55CD98430ULL, 0xCD1A2548D2BC14B2ULL, 
            0x39EB2276A6E3329FULL, 0x3E66168879B02E9DULL, 0xE9A1FB2D9BD88A9BULL, 0x970C457E9BCBDE15ULL, 
            0xEAD03538C65A1449ULL, 0x46019496F5DB12A9ULL, 0xDEF6B67799B6F234ULL, 0xAEE078A392204C28ULL, 
            0xCB8B0D4957BF5717ULL, 0x61FD347818E34438ULL, 0xB589BEBC7217CA9EULL, 0xAB7B29BBC4990F6AULL, 
            0xC7960920E7C47845ULL, 0xB834840D879EA786ULL, 0x5AE6C02BA84A6161ULL, 0xED0DCF7260F4067BULL, 
            0x4BF3215A1575C9B9ULL, 0x52F11935F9B92518ULL, 0x48D96E906FA5E0B6ULL, 0x1A68CD9EFB5E9385ULL
        },
        {
            0x7890256656EA88EAULL, 0xBDF69EB3CD3C83E4ULL, 0x296CC8CAA7083B7DULL, 0xCD5E876EFCCA2238ULL, 
            0x991220F044002E13ULL, 0x14E93ABEAE154EA9ULL, 0xBF094733C94AB5F5ULL, 0xEA1D897E09EA443BULL, 
            0x8F4743A1ADBB7313ULL, 0x89D54550F0F0FB55ULL, 0xA7EB7F17E7D0AB64ULL, 0x2B7C81EBA5F9D232ULL, 
            0x3EE0C7D7249B2A8FULL, 0x7823CEBC28D50DD0ULL, 0xADA15CC338B1AFD1ULL, 0xFD43953E55E132F8ULL, 
            0x4DA44CA7C6F6A2CAULL, 0x107C6C21F752D968ULL, 0xF4BC81A8D214D12CULL, 0x0CDED4D7876AF2A2ULL, 
            0x3CA87BA7B91A8DF6ULL, 0x635E50BCEDF37260ULL, 0x563B5D92084337E6ULL, 0x754ADE1E0DC8EF81ULL, 
            0x9F2E3A50890430E4ULL, 0xBC86ED51166E1EA6ULL, 0xCFB303FDC98E078CULL, 0x01B135552C355877ULL, 
            0x05B57DD5BEA401ADULL, 0x41FA3610F3E92FD1ULL, 0xD47EDE8E6BB71BFAULL, 0x96106F0727697303ULL
        },
        {
            0x20354317539E3168ULL, 0x55D05CDC5F780F9FULL, 0x36A68D8F30610F4EULL, 0x10818699D5561DD4ULL, 
            0x83092E918CD6AFDDULL, 0x83436C95197E12B9ULL, 0x7F507FB4A4D09B3DULL, 0x195231923F0DF0A0ULL, 
            0x39A7A4D8E5E1E2D6ULL, 0x488D673F0ACE3885ULL, 0xCD544247E83F0844ULL, 0xBC2D259A7753BB0DULL, 
            0x93B974EF3ADC992FULL, 0x9BDF0B5E405E155BULL, 0xF93C0808ADA44F37ULL, 0x5CB1B0617253BDC3ULL, 
            0xD50924D49372520FULL, 0xD567945564EFC779ULL, 0x66A55FF5B36320D8ULL, 0xC8305A017C01D80DULL, 
            0x46D8A86E3EDE6139ULL, 0xAD5C44AB5644476FULL, 0x0A0E65063915DE01ULL, 0x10E07C91B8D08B7DULL, 
            0x6290BD1B39245D37ULL, 0x3295D42C82F671ADULL, 0x2303A593468F2C28ULL, 0xDCC0C2BC62E5D181ULL, 
            0xDA83864F16B11E42ULL, 0xF65FA56D9F02CFE2ULL, 0xB50BFC4792D9B851ULL, 0xCB1D598E20E4ED85ULL
        },
        {
            0x297BA1BED74200D4ULL, 0xA0C621A654FD378EULL, 0xCDEEDC344AB2E95EULL, 0xC849495C5138C050ULL, 
            0x58EB213D47EFCBBDULL, 0x6BCFD08A88F4F1FDULL, 0x8444C9535A00A840ULL, 0x99C1063A6CA04182ULL, 
            0x45907D96A0A46033ULL, 0x4657E7EB3FAF69FFULL, 0x934DEC058EC0BB5EULL, 0xBDEEC1D32C413E7DULL, 
            0xE4D3B004782FA43CULL, 0x04ED2DDCD6FCEB4AULL, 0xDBAACBC8A943770DULL, 0x184EA5417FFA68C8ULL, 
            0x64B4D4230FDBE611ULL, 0x5418FFA927B7CF15ULL, 0x415EE22ABB03BAE3ULL, 0xC25E53DF426EA49FULL, 
            0xC16ED46611243EA3ULL, 0xCDE6EDACE626F89DULL, 0x3E5EAE0ADBF99F0FULL, 0xB3D17E06B25A826EULL, 
            0x7E9B1E9E4AD42FE7ULL, 0x068112438B514103ULL, 0x793B82F766B249C8ULL, 0xBC7672D9EAA30C83ULL, 
            0x7C526CCFCFA6DE67ULL, 0x482638AA4587C810ULL, 0x03A8F8794F88F649ULL, 0xC753C3BCA8FFEBD9ULL
        },
        {
            0xA0679D2DB5DF11E4ULL, 0x567F990E2C71E551ULL, 0x40EAB65B9D1E0033ULL, 0xBB92922B7BE9E1B4ULL, 
            0x55AF1631EFB7F5E6ULL, 0x866F5404BA8E7491ULL, 0x4E354EF36621D7C0ULL, 0x277A48231D78A2ABULL, 
            0x938C338320633671ULL, 0xADBDF171A8B86BE1ULL, 0x0B76338DD0E94EFAULL, 0x171056EFBC39745EULL, 
            0xC8D3F2A0A1BA8DA1ULL, 0xC92E1664A4D12521ULL, 0x92AE59F194206283ULL, 0x6D9FF250163565C4ULL, 
            0x121974BE6D6F6809ULL, 0xD0FC7CD33CEE6DDAULL, 0xA837D542D7B6907AULL, 0x89D1E127478B437DULL, 
            0x44F8277EC8F25E34ULL, 0xDF8307D5BCE0806EULL, 0x447B5FE6F79BE1D5ULL, 0xBB5B447335CB991AULL, 
            0x1432A1011854851BULL, 0x2642C347F26EC18FULL, 0x07BF6CFA28217AB9ULL, 0x16D09875A92901ADULL, 
            0xE064E892E6C1E98CULL, 0xF30BA0E72AE09608ULL, 0x64353718EA88D3DDULL, 0x18254BB8B26D240FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseHConstants = {
    0x79D11A3BA45C83D4ULL,
    0x076B493DE3AB39F6ULL,
    0x384AF1C1057970D1ULL,
    0x79D11A3BA45C83D4ULL,
    0x076B493DE3AB39F6ULL,
    0x384AF1C1057970D1ULL,
    0x250517E583ECC08DULL,
    0x8A8832F3F5987960ULL,
    0xBB,
    0xD7,
    0x8D,
    0x57,
    0x8B,
    0x12,
    0x8A,
    0x61
};

