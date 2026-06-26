#include "TwistExpander_VolleyBall.hpp"
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

TwistExpander_VolleyBall::TwistExpander_VolleyBall()
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

void TwistExpander_VolleyBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9972945907828449144U;
        aCarry = 12236373562777802245U;
        aWandererA = 14916505599389978475U;
        aWandererB = 16334107479495151399U;
        aWandererC = 17173473157867686482U;
        aWandererD = 11051317996764169696U;
        aWandererE = 15109030400650571386U;
        aWandererF = 11770094038747480853U;
        aWandererG = 17544601978805700046U;
        aWandererH = 14787645303941491822U;
        aWandererI = 14423755852208898936U;
        aWandererJ = 11348699795962723511U;
        aWandererK = 15100398061777434330U;
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
    TwistExpander_VolleyBall_Arx aArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_BArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_CArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_DArx;
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

void TwistExpander_VolleyBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16588616839479311865U;
        aCarry = 11735707473324663014U;
        aWandererA = 15600342160369092908U;
        aWandererB = 11444360667077590254U;
        aWandererC = 15347448897700778015U;
        aWandererD = 13613684260816898637U;
        aWandererE = 9421538638265762139U;
        aWandererF = 11153637544134903972U;
        aWandererG = 17807269138039803253U;
        aWandererH = 13919485411421259609U;
        aWandererI = 11973289983231586772U;
        aWandererJ = 12951021849452223310U;
        aWandererK = 13274361959349585968U;
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
    TwistExpander_VolleyBall_Arx aKDF_B_AArx;
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
    TwistExpander_VolleyBall_Arx aKDF_B_BArx;
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
    TwistExpander_VolleyBall_Arx aKDF_B_CArx;
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

void TwistExpander_VolleyBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE514DF4AE3C1741DULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xE65CDE00CC17DD6EULL;

    std::uint64_t aWandererA = 0xFFEBC7D5A2B95F9CULL;
    std::uint64_t aWandererB = 0xFD18464E57750510ULL;
    std::uint64_t aWandererC = 0xA6107AFD460C6F2CULL;
    std::uint64_t aWandererD = 0xB93B26F14B7DD301ULL;
    std::uint64_t aWandererE = 0xDD21DACAC370F446ULL;
    std::uint64_t aWandererF = 0x92C3D1F115970A9FULL;
    std::uint64_t aWandererG = 0x9EEB11CB7934AEFEULL;
    std::uint64_t aWandererH = 0xBBAD679C8CD67A99ULL;
    std::uint64_t aWandererI = 0xA5DD50C20B386EDBULL;
    std::uint64_t aWandererJ = 0xD5DC79F7BCD0E5E5ULL;
    std::uint64_t aWandererK = 0xB4EF2FFC39261D3AULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_VolleyBall_Arx aSeed_AArx;
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
    TwistExpander_VolleyBall_Arx aSeed_BArx;
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
    TwistExpander_VolleyBall_Arx aSeed_CArx;
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
    TwistExpander_VolleyBall_Arx aSeed_DArx;
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
    TwistExpander_VolleyBall_Arx aSeed_EArx;
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
    TwistExpander_VolleyBall_Arx aSeed_FArx;
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
    TwistExpander_VolleyBall_Arx aSeed_GArx;
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
    TwistExpander_VolleyBall_Arx aGrow_AArx;
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
    TwistExpander_VolleyBall_Arx aGrow_BArx;
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

void TwistExpander_VolleyBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_VolleyBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 15870683281138361823U;
        aCarry = 12720232027074822071U;
        aWandererA = 15297054420957086150U;
        aWandererB = 18043536245902938119U;
        aWandererC = 14523925390667992989U;
        aWandererD = 13251818218496321983U;
        aWandererE = 17994795652359732311U;
        aWandererF = 14798100503106316265U;
        aWandererG = 9506046203074982616U;
        aWandererH = 17797490731932406144U;
        aWandererI = 14468088226463580235U;
        aWandererJ = 14072978342558876180U;
        aWandererK = 9685621954870838021U;
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
    TwistExpander_VolleyBall_Arx aTwist_AArx;
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
    TwistExpander_VolleyBall_Arx aTwist_BArx;
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
    TwistExpander_VolleyBall_Arx aTwist_CArx;
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
    TwistExpander_VolleyBall_Arx aTwist_DArx;
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
        TwistExpander_VolleyBall_Arx aGrow_AArx;
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
        TwistExpander_VolleyBall_Arx aGrow_BArx;
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

void TwistExpander_VolleyBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 3, 1 with offsets 5990U, 6571U, 2316U, 3080U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5990U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6571U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2316U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3080U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 1, 2 with offsets 4575U, 4214U, 3072U, 4211U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4575U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4214U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3072U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4211U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 3 with offsets 1647U, 3866U, 4287U, 3069U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1647U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3866U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4287U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3069U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 0 with offsets 711U, 4844U, 6393U, 7068U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 711U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4844U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6393U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7068U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 with offsets 369U, 1311U, 144U, 634U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 369U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1311U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 144U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 634U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 778U, 1165U, 765U, 884U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 778U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1165U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 765U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 884U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 1, 2 with offsets 1622U, 1020U, 1296U, 614U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1622U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1020U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 614U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 1, 3 with offsets 1192U, 1757U, 715U, 1365U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1192U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1757U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 715U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1365U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 898U, 1209U, 1194U, 540U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 898U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1209U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1194U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 540U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_VolleyBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 3 with offsets 91U, 6044U, 1287U, 7569U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 91U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6044U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1287U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7569U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 1 with offsets 731U, 2368U, 5487U, 6995U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 731U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2368U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5487U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6995U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 2 with offsets 1090U, 4659U, 4658U, 4077U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1090U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4659U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4658U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4077U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 0 with offsets 688U, 3612U, 5146U, 4990U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 688U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3612U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5146U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4990U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2277U, 5086U, 2673U, 4811U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2277U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5086U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2673U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4811U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1999U, 210U, 614U, 1670U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1999U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 210U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 614U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1670U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1074U, 2042U, 1615U, 1669U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1074U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2042U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1615U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1505U, 1295U, 1724U, 1170U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1505U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1295U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1724U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1170U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 487U, 1476U, 1017U, 1559U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 487U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1476U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1017U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1559U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 [0..<W_KEY]
        // offsets: 1540U, 690U, 691U, 353U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1540U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 691U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseASalts = {
    {
        {
            0x266DEF4FB468BB5EULL, 0xB90071713DC8BB67ULL, 0xC6ABDC5BAD2AF94DULL, 0x54243998EF7E2DAEULL, 
            0x4E684F3DF96BD216ULL, 0x698C79F8FDCE41D7ULL, 0xB4553DC5E1905951ULL, 0x0A69E8A1EE071B6BULL, 
            0x37AF5DC38195172AULL, 0x1B4BCC81D72F8D47ULL, 0xDEBE8D33E0B35D92ULL, 0x7762AEBAEAA7BA25ULL, 
            0xE73ED187D2CC4BF4ULL, 0x2F9EF92B33BEAE41ULL, 0x610C6F5B545FA8CFULL, 0xD847E3CF70EA6870ULL, 
            0x68ADAA89CCFB8185ULL, 0xF54A5B0E1513CEA5ULL, 0xACD868C7E48FE669ULL, 0x674568B9C0FECAFDULL, 
            0xF4676D26FA711B0AULL, 0x6CA576AD128493A4ULL, 0xBF18819B00F77619ULL, 0x6D81D194764094E7ULL, 
            0x27AECAA535A0246CULL, 0x8F5F064F30E49557ULL, 0x654A37E72521182CULL, 0x6EBDA40DD4F5A566ULL, 
            0x153A4CA7D8A0A8B7ULL, 0xED423CE378812986ULL, 0x5998FEB4C0461C08ULL, 0xEAB3798CDFF85CC6ULL
        },
        {
            0xFDFC91F7ABA31B97ULL, 0xE682F980EDC975CCULL, 0x7DFF410D57B9485FULL, 0x7E40D8DB1EF43DEFULL, 
            0x7F1391BE911DB19BULL, 0x43E289898F37E1BFULL, 0x49D9D552B3259654ULL, 0x59161B0CCFD5963EULL, 
            0x3E4CE0E29DBCCEDAULL, 0x5D4AF66C2BFABBA4ULL, 0x0C245D739B7D43FCULL, 0xF1DDBEDDE17EFC95ULL, 
            0x8D054C6BF35C3409ULL, 0xE609B1EFE24C8F49ULL, 0xDAA6B7183EE0BF8DULL, 0x9AE9CD638B5495F9ULL, 
            0x78EA6BBBBB041F08ULL, 0x2560CF66E2B79D4EULL, 0xB4C9963AC4CF68DDULL, 0x8D2BA501582F66BDULL, 
            0xB89DA36A67D594F8ULL, 0x2BE7DE273E164124ULL, 0xEDF83D0DD775ED1FULL, 0x49D985740174651AULL, 
            0x1B53C921F37CBB74ULL, 0x44839EDC064C4852ULL, 0xA12C745DF55D23EDULL, 0xE0715C54E124EA0AULL, 
            0xB30ED9896ABACDC5ULL, 0x3D1F5FBCF15C8F91ULL, 0x0402E7B11C52B6CEULL, 0x4D1A8BACAFD401ABULL
        },
        {
            0x4EC48439D1C61718ULL, 0xD4F466BB9528F38BULL, 0x16530236561BD600ULL, 0xF1728B901A91C60AULL, 
            0xF0F96CA1580F15BAULL, 0x234FEB1BF203F329ULL, 0x6CE0FA885AC380F9ULL, 0xF47839E4BE1C7BBCULL, 
            0x4E2CDF463599C37CULL, 0x9A517D493298CA2AULL, 0x323492EF80E8C31FULL, 0x900F4A08C5712089ULL, 
            0xE57558B1EDCC1A32ULL, 0x383846EBFEEB166FULL, 0xC6033E26BF5AEE17ULL, 0x60214578F8EA5A6DULL, 
            0x9E9B70D45FAE4174ULL, 0x407EC1ECC17236E6ULL, 0xF2F40D1AC80D5DEDULL, 0x6113F01276836313ULL, 
            0x1BD3562B541B3E60ULL, 0xA0FACC2B88EB7C43ULL, 0x945961A3E40F2731ULL, 0x0A8EC601D7BB7EFFULL, 
            0xF005417546FD5CD9ULL, 0x46DBC426A2E416D4ULL, 0xE4EA75F4B7BE137FULL, 0x95E96A8EC2E52F9AULL, 
            0x3B66DA94D4FF592EULL, 0xA43AEAE784D8CEDFULL, 0x49576730A8156B2DULL, 0x502514A38F80903EULL
        },
        {
            0x12AC7F5475FA7AE3ULL, 0x78FC15951B16EFBCULL, 0xC05A82562EC2D51DULL, 0x869C59E64F266821ULL, 
            0x5B8F613F7A307695ULL, 0xC7E9491F756E4103ULL, 0xE1613E7545D01C54ULL, 0x73B1F6C6A07908BAULL, 
            0x2493847BCCF634D6ULL, 0x6C9C2FA4FF3FA978ULL, 0xEEEBEEFAF7749730ULL, 0x4938528C33AEABD0ULL, 
            0xAD1FE384C5257AF2ULL, 0x1A9C466A670E5043ULL, 0x1FDE7C1BB69FBA1AULL, 0x39922093021CA5B5ULL, 
            0x55E2EA9357AFE3ADULL, 0x8847FE6444260A5EULL, 0x3CD54304FA4658E0ULL, 0xCAAC44B39A11AC19ULL, 
            0xC178D5D3781F59E9ULL, 0x5FEA504323665AC7ULL, 0xA7C3ECF5A8AF9BB7ULL, 0xDEA30C6CEC60BE78ULL, 
            0xAA4CC7E2F90C6604ULL, 0xC096F716570F62CFULL, 0x2AB9DF8E54F29873ULL, 0x3D45ABCF7B9418B9ULL, 
            0x5E31C3A4C031C0D9ULL, 0xA16B26A08BFE5B42ULL, 0x0D39EC98A60D9CBFULL, 0x9CDDE68C134814ACULL
        },
        {
            0x87A2AC4DBB3636E8ULL, 0x23083E4B0FE00395ULL, 0xB37A7C5EF683ED5EULL, 0xE1BFEB7B54AEEA0CULL, 
            0x48972FF374749EC1ULL, 0x2C0D5E4B19442884ULL, 0xB586D38583471F3DULL, 0x5CBD70CD33F8A5D6ULL, 
            0xA0079B78D9D0ADB7ULL, 0x2B5DDF2A6D42E1B1ULL, 0xA196C75900313831ULL, 0xFAD98676617BAD6EULL, 
            0xE36757E7E2FC0C3BULL, 0x6EF91740996B82DDULL, 0x0C8006D29A7D36F9ULL, 0xFEBAA3AA4AD6C982ULL, 
            0x25C818457E4FB27BULL, 0x36B81802BE389FE7ULL, 0x22B602C536729931ULL, 0xAFEB83932DA6946BULL, 
            0xFE7882130115108AULL, 0xD3BC4BED23110A8FULL, 0x6A697E14E1A4D7B7ULL, 0x7AF547BDDE489B96ULL, 
            0x34B7E755F6D05971ULL, 0xD3E41DBEDB2AC18AULL, 0xF3530C28FC896E78ULL, 0x577C1CD7F7C1807CULL, 
            0x86F2724AFA17725AULL, 0xA9EEA96F410DF32FULL, 0xAD95846717ECC4CBULL, 0x89CCE97C4899DDC6ULL
        },
        {
            0x2BB7CC76BF4CD1EAULL, 0x8A6B0E5636F622F5ULL, 0xBDF8BEF9484901BBULL, 0x47E0CEF73A690ECEULL, 
            0x3875874796D570FDULL, 0x24C4AB8C7680522BULL, 0x48233C3FCB1108E5ULL, 0xCEF04D6FF20C0B08ULL, 
            0xA60F0F383238DE59ULL, 0xB57A425B864139EBULL, 0x80CF3B411A19E035ULL, 0x3D49D97495D3EA7CULL, 
            0x149964E4B52C8474ULL, 0x7C384594B0774150ULL, 0xDCC059B662BBA513ULL, 0xA33D3536D334CF5AULL, 
            0x56FFC994A84262A6ULL, 0x54DC430A8795F3BDULL, 0x21C0ED397663BFAAULL, 0xCC6F8B78F8FE4B18ULL, 
            0x12151D00877D488CULL, 0x8364DDD17A0DD05AULL, 0x6E8F697E0DF6EF40ULL, 0xC19864B878A70D2BULL, 
            0x071B1454F4C91626ULL, 0xA1D0A55FAAEC2647ULL, 0x7155F1E7B7D32A7FULL, 0x687FDC7D01B7852DULL, 
            0x3902B536906E5314ULL, 0xFA2E2DE14D009CA4ULL, 0x40EBD837C510D67DULL, 0x6228CAD54ADA1D84ULL
        }
    },
    {
        {
            0x052632F413D997A4ULL, 0x82DF97E7098C138BULL, 0x7606CB21675DC211ULL, 0xBD7E13F1F87AFBCBULL, 
            0x492E384A60BCD5A3ULL, 0x27782D6BD5D4AC92ULL, 0xB4888B44BFE06BA4ULL, 0x041F984324384D10ULL, 
            0x60EB89D715B894AAULL, 0x37F8D16B7FB11AD9ULL, 0x747DCA26F78DBDFBULL, 0x8C9219BE4068E8A9ULL, 
            0x4460614363682CFDULL, 0x805AE55D68C72FC8ULL, 0x81C2394D89C8C66CULL, 0x19583D710E51E6A9ULL, 
            0x338F553D457E73C0ULL, 0xFF1DAA695D675A6EULL, 0x21D2EB7C4090A99EULL, 0x70AB4B031E1E64A4ULL, 
            0x9D25BC1FE69380A1ULL, 0xF8011A8BCF641249ULL, 0xE9DE225C51FE60B9ULL, 0xC90441D998C66CC4ULL, 
            0x3C9209FA6DF86C5BULL, 0xA25875583F946681ULL, 0xB99C547B8B61F1E9ULL, 0x554B7B607259B5E2ULL, 
            0x8D04593586D2FABBULL, 0xC489E6A9F158B2B5ULL, 0x868AC9AFB5D67552ULL, 0x9856980D44DD6104ULL
        },
        {
            0x5380C922BDF81893ULL, 0x51BCFDCCDF66A62EULL, 0x65FFBDEACF71B13CULL, 0xF22DA265144F9DCDULL, 
            0xEDEFA2B724A6E2D5ULL, 0x336760372E552914ULL, 0x9A98C82727267000ULL, 0x06829094450BFAE3ULL, 
            0x7D8C5B2C881A522FULL, 0x6A0BCE619544D393ULL, 0x9E0A9E50B3B88345ULL, 0xA638E87BD6C153FBULL, 
            0x6B98CDDC17E06C6BULL, 0x01291CDAED3D6E59ULL, 0x1DA63601D1AE4A35ULL, 0x5AED33F5CB61A24AULL, 
            0x2B9B8CF01BD835DAULL, 0x0EB5A83CB23CE87BULL, 0xF7F5F800F8CD2AF6ULL, 0xCA8FDEAA256D06B0ULL, 
            0xDFE8C83E64D429D9ULL, 0xEA5636205E31AE3AULL, 0xD8ED06B3FE7DB400ULL, 0x6BFAEDD62511CAA9ULL, 
            0xAADCCF20F421153FULL, 0xF44DF661A11EA1F6ULL, 0xCE883A3A600E95C2ULL, 0xD75B561675BE0B7CULL, 
            0xFD0514DE52E7BF94ULL, 0xC87E27E696579340ULL, 0x0349750A4B8E10F2ULL, 0x6E2144454EF02DE9ULL
        },
        {
            0xACB6AA3A7E63C01EULL, 0x24816B08E8A94922ULL, 0xEE1EBF6D388EDADFULL, 0xACEBDDB5848DAF06ULL, 
            0x0615C879884C146DULL, 0xD2909F907101FADCULL, 0xD6AC7130DE8A33CFULL, 0x1085097F348EC029ULL, 
            0x0F316BE9DD1517E6ULL, 0x140B3D987FA8A666ULL, 0x434840780B4AA291ULL, 0xAF3083D4C04072F0ULL, 
            0xE3555BDA166A31BEULL, 0xA7D6BCEBB7D71762ULL, 0xA391527C6839C009ULL, 0xC8E552030A9C28E0ULL, 
            0x90E49F3F726C21BBULL, 0x57EF07DD1BC16787ULL, 0x2A3A3537B5E13356ULL, 0x57E5DB763A265786ULL, 
            0x25CAB451730446A7ULL, 0x778F9E5BCB9E6834ULL, 0xF98201358BF9B005ULL, 0xD83140D714F54D09ULL, 
            0x09A7FA9EC91E90C5ULL, 0xD231ADC1C33BA9F1ULL, 0x21106B1E55EE2226ULL, 0x672967E0AE8E3175ULL, 
            0xC158C299E30E1473ULL, 0x91AFF80EA7FF68B0ULL, 0x92E7779F6E3E65A7ULL, 0xEF0EF184E03C82E8ULL
        },
        {
            0x555A8493D9B1EDA1ULL, 0xCA88DB05B558DF7DULL, 0x477BC7B009875DF0ULL, 0x49EC3AB106C99195ULL, 
            0xC28FD27C93AD8837ULL, 0x2E4BF68F2D614D3CULL, 0xCE9D1BF510FA4860ULL, 0x9F70F030DD0143BAULL, 
            0x2816E76143DB51B8ULL, 0x961A0ECC91763243ULL, 0xFBD5DB596A2CF849ULL, 0xEB799D9AC2FB03B4ULL, 
            0x52EDE64D65A4AA61ULL, 0xF9809732A21266FDULL, 0x708327012881D22FULL, 0x070137710BAC15A6ULL, 
            0x203F1A8ACDE1D8F0ULL, 0xC0858C9213939746ULL, 0xE805CC92C4967D27ULL, 0xDC78A9CAD484A3C9ULL, 
            0x4765D4D93E43C043ULL, 0x8878AC2FD0A7FEE0ULL, 0xDA1D2B9DDBD7619EULL, 0x6EACF3161B1C7BBCULL, 
            0xD3D8D8CE749A7CAEULL, 0xB1A57745CC5E7543ULL, 0xDA5ED8627483880FULL, 0xE53D452A553DD8F6ULL, 
            0xAA8F4B2E62A7A9C2ULL, 0xC6505D69CBD52F79ULL, 0x01671824EC4BA2CDULL, 0x064DD84231E16DB2ULL
        },
        {
            0x843A6B40C5E154A2ULL, 0x56A603913FEF18DEULL, 0x0D529E2208EB90E6ULL, 0x4C0B4E0708D4D4F0ULL, 
            0xBD30F37533D9545FULL, 0x3FEC3664E59575FDULL, 0xD9E31B124C05F48AULL, 0x4E052510798F1424ULL, 
            0x00B09B666C0CADDFULL, 0x990089F3357B297BULL, 0xE5BBBA0B38C731B3ULL, 0x978D4974509956B6ULL, 
            0x51EC4E80FAD88272ULL, 0x481E2ECF4667750EULL, 0x638B99AC29ED58B4ULL, 0xE872EA241E339E5CULL, 
            0x6A8AC3D11806D992ULL, 0x1BF889651F21C4F7ULL, 0x753D9078FE892608ULL, 0x4BAB85BDB809D86FULL, 
            0x6B5420CB8E26ED98ULL, 0x71653C548BDC2227ULL, 0xCA1D8CD2E677791CULL, 0xC739CB248FC35EC6ULL, 
            0xBE3C6B13AAE36FA5ULL, 0x28693524B8FE147AULL, 0x4ADDBCAD6F5BBE2FULL, 0xEFC977A6B8472626ULL, 
            0xD459AD37002F1901ULL, 0x0941D29B49315045ULL, 0x1BA71AAF3C2BD22FULL, 0xCF818B9E1BB45D85ULL
        },
        {
            0x610BDF493B080637ULL, 0xBA440CA0154DB1CDULL, 0xABCD0AEB087D70E8ULL, 0x640120D7D6768AA4ULL, 
            0x23DCF1379D92D7F8ULL, 0x8CDC077DAB84008DULL, 0x69EFE46447AD5229ULL, 0x45359F4232A21E41ULL, 
            0xBC2B8F69B5C52405ULL, 0x09209ABAE9C7EC5BULL, 0xE628AC02AB7C1F1DULL, 0x3CFEF1DB95C9DC98ULL, 
            0x6F2D7E7B46DE6A5DULL, 0xEFE784C7BD30BF4EULL, 0xF618121CB5E708BEULL, 0x825634E10B5194A8ULL, 
            0x84AA77F3329F5576ULL, 0xD97DFD628A841D1DULL, 0xA615B1A6AF2A2258ULL, 0x0D2D7DA27CDE57FFULL, 
            0x996388B12A908788ULL, 0xE6B43C9908CE2B17ULL, 0x38A91518FBB3BE12ULL, 0xA46EAA75CD2CE0F0ULL, 
            0x39F422959804D03EULL, 0xF6345BF27A2E5A82ULL, 0xFF076DA25CB411B1ULL, 0x4A64FE21EDB36D29ULL, 
            0x083940C118F0A4B6ULL, 0x9BE23156BF61DD9CULL, 0x55CD3D3AEED55B52ULL, 0x3F66C1857990CFA5ULL
        }
    },
    {
        {
            0x1265B5E1E86B0A75ULL, 0xEDEAC6E9EB969FF5ULL, 0x36B503DD482D31B6ULL, 0xF736509F42671707ULL, 
            0xCA06B0798912187EULL, 0x8380F24A8AFC862FULL, 0x033BA0F707042D94ULL, 0x84618BED62468063ULL, 
            0x76AD2168D1BA755AULL, 0xFDB1D421E6790ED7ULL, 0x27A832476A385110ULL, 0x6D65F96A03473899ULL, 
            0xAF80AAFEE32763C9ULL, 0xB00B4B0D49A9C3E4ULL, 0xF7F066D0F385FB26ULL, 0x8DBA99BB6352D918ULL, 
            0x5C1EC94729D5293AULL, 0xFF1B9F874083FCCDULL, 0x5C7EB08F8A72F441ULL, 0x95F65A26E004D838ULL, 
            0x5B3823D65E991699ULL, 0x0D4D7BBC24A26EAEULL, 0xC3A2704AF8E54FA6ULL, 0x60FD6BAF81B60C4DULL, 
            0x26B041EB219FFE2CULL, 0xAC65BA024F7F7DF0ULL, 0x98B181AD61A3A22DULL, 0xE72A9164D98AC245ULL, 
            0x084337AD6401F12CULL, 0xEB469053924B4A39ULL, 0x04E09FEFB60CD3D3ULL, 0x11BF98E5B5F7B7A1ULL
        },
        {
            0x5645F9F41C4FAF46ULL, 0xA7B1EC4AD30976D6ULL, 0x637E93E21D536C67ULL, 0xD4FCD36D46F419B0ULL, 
            0x5293F0CCC934CFB8ULL, 0x2C6714F8DE716A78ULL, 0xD5FE05820A57BE1EULL, 0xDC7BA23F1DB516F3ULL, 
            0x0EB99B137167C51AULL, 0xAACE68C24AC35ECFULL, 0x98935FD362622CC4ULL, 0x8B7E8404C45E15A5ULL, 
            0x65B6A71412810D72ULL, 0xAE94DBE700AEC4ABULL, 0x4CAD4D1C9B5ABF01ULL, 0x285362950697266AULL, 
            0x4BD05DD8D9F7447CULL, 0xC291837609F94B4BULL, 0x6CA29BB6C45802CDULL, 0xBB2C9540E67C9B8EULL, 
            0x58DC93EF34AB2F37ULL, 0xE8B7EE78DD6A840CULL, 0x0FC52784216A4767ULL, 0x5FD3AEE025BC8FF1ULL, 
            0x76693FC18C0B9413ULL, 0xEE8DD3E2118441C9ULL, 0xA857F98B4A30C17BULL, 0x56B555AAF72D295FULL, 
            0xE54D3CC5BB9F9C7CULL, 0xF54E900140F16F27ULL, 0x1133E62937E30F54ULL, 0x958A19B70D8D33DDULL
        },
        {
            0xA4B0E736841D930DULL, 0x6E6B3963351B0F60ULL, 0x5BE9E876A5C245E7ULL, 0x4CBC2A9764BCC33BULL, 
            0x89D624FA3429DB98ULL, 0xA71ED51836F6191CULL, 0x9876CE6FA13B27DAULL, 0x097BA437E97D4652ULL, 
            0x1F6958AE07D2DDC7ULL, 0xA83EDDAC2A529D64ULL, 0xF642DD703B330A0CULL, 0x57A199DB263030F6ULL, 
            0x6FCCC9A3CB0D4882ULL, 0x1EA7F0ADC73A1B54ULL, 0xC559BF2BA1A132B2ULL, 0x73F630908FF2824EULL, 
            0x1CBB5F0581E4C14EULL, 0x323AB5A40A9B7CF6ULL, 0x853696E1641D2465ULL, 0x954342C6375D1066ULL, 
            0xA1AAE895029A3E11ULL, 0x77F37969778D9055ULL, 0xB1C564D2B3BA0A51ULL, 0x87E69B732CBCE6FAULL, 
            0x061A36120422CC8CULL, 0x764A875909EFC334ULL, 0x8B9F3068ACDBEA06ULL, 0x5CC3627083D35EB8ULL, 
            0xDC82A3A0E4F34D70ULL, 0x838837964A254D3DULL, 0x9F01DE4CDDE35FFCULL, 0x7860C1EB888D4FD7ULL
        },
        {
            0x4D8BC90652B92716ULL, 0xACEFD19C472FACBBULL, 0xC7B63221A22A5E45ULL, 0x41C5562FA2DABC82ULL, 
            0xB0F2D4B757E21DB3ULL, 0x1F20913167E95854ULL, 0x853EF52F082A2E11ULL, 0xA2D2CD34169C729FULL, 
            0xE9758B0850BD7131ULL, 0xBA185A1B10224668ULL, 0x158E019BBEA5452AULL, 0x3E7E36E994166D4CULL, 
            0xEF0747437FB36CAEULL, 0x950ED708AE0A2FE0ULL, 0x4D9A7BE799FC17FAULL, 0x7CCAADD9130B68A5ULL, 
            0x6F1BAC87C4E9BEC5ULL, 0xC304B6D26DB2706CULL, 0x35337684FBA62C41ULL, 0x64BE1665196B8FD8ULL, 
            0xF0939CF941FBDA58ULL, 0xD3CC68054B0E0CBBULL, 0xF4BB958CFD8087BFULL, 0x5B387FF2B4A1B2F8ULL, 
            0x3E23337E6C02E2B0ULL, 0x1788E74325C6453CULL, 0x9B7B88276C27B01CULL, 0x2C95B7A6B09150A3ULL, 
            0x7FFE3C268D57C724ULL, 0x1128A3BE45009B03ULL, 0x04A97836F8276315ULL, 0xD44768595DF99E4FULL
        },
        {
            0xDC43E2164D50F561ULL, 0xF2CDE610EF68031EULL, 0x31DF7C11AD9B61AEULL, 0x5A570AEB7638B462ULL, 
            0x025D267F93632A31ULL, 0xDA01698968E1905CULL, 0x11F75C194871B2ECULL, 0x7784308C083D7BE8ULL, 
            0xB35E1AD67203C6DDULL, 0xE3F96EE7F14EC436ULL, 0x5946F462A861432BULL, 0x7BF84DC8A183B8CCULL, 
            0x3006363D3F0AF131ULL, 0xA6E41259F27BDB87ULL, 0x9A2484401A1F309FULL, 0x4D8C02FBA6621246ULL, 
            0x2EABF10E027A85F8ULL, 0x43143CB7C5E432BEULL, 0x858F27529B616DA8ULL, 0x587DEB988E57A937ULL, 
            0x799D9EFD20CA4D3EULL, 0xE9ECA752BF004CD0ULL, 0xA384199BF1692719ULL, 0x656498431266BB25ULL, 
            0x3D67FB469B849365ULL, 0x82D25A91A07C1567ULL, 0x0CA311D6EF2FF689ULL, 0xA29DC2A8A446B51FULL, 
            0x54B8CE7ED7D4BA71ULL, 0xD1A6D679C97C82E1ULL, 0x804444925915C5C8ULL, 0x9648A753D4CCE458ULL
        },
        {
            0x94705C0C33B70D2BULL, 0xAD4CB429EED94361ULL, 0xBDB2056E9149C526ULL, 0x07E8B83FBA028BFFULL, 
            0x3B910618F4E8557DULL, 0xB9DBFCE8F9CB8423ULL, 0x1783C1748FF1FF2FULL, 0x29A39AB40A8135F1ULL, 
            0x78A547AACBF62D45ULL, 0xDFE59D9D946EF846ULL, 0x20D678D0CC492B7BULL, 0x5C1063682B990B0DULL, 
            0xCFC573CCEEFE1178ULL, 0x1BFB17A551EF4B59ULL, 0x02BA7937775AB331ULL, 0x0ED58EDC35AE9986ULL, 
            0xB9E614DF5C7DAB25ULL, 0x47B31B0090E43695ULL, 0x0E87180CE9B7443DULL, 0xF28BEFDC9692F643ULL, 
            0x40E943738A116A50ULL, 0x16A799D2029CA557ULL, 0x83D9EF5D19DB90D3ULL, 0xFA3AEB651AB438B4ULL, 
            0xD1EC0DE97D4D12D2ULL, 0x0875D5D2EB5C2435ULL, 0x3BE9BBB95BA7BBEAULL, 0x209610A6FD47DC28ULL, 
            0x9C8D937593E3833FULL, 0x5B7D4FAFC69994EFULL, 0x067214628F03C896ULL, 0xB5EAE35EA8793CB7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseAConstants = {
    0x9840B56EC508ED30ULL,
    0xB06077C054B22879ULL,
    0x2A5A7CBCC8FF463BULL,
    0x9840B56EC508ED30ULL,
    0xB06077C054B22879ULL,
    0x2A5A7CBCC8FF463BULL,
    0x3016D230D3CB8297ULL,
    0x5742D7A36BCED88FULL,
    0x5C,
    0x92,
    0x91,
    0x0B,
    0x09,
    0xAD,
    0x2E,
    0x77
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseBSalts = {
    {
        {
            0xEEE1E43BC04F3CDEULL, 0x37995CD3F7CCBE5AULL, 0x141E8AC164E558BAULL, 0xCE9E7FB2FA037C3CULL, 
            0xF479D9295807FF4BULL, 0x92CD645887DBE8F1ULL, 0x4A9F1828D9CEAB8AULL, 0x1C9681A43E2A5A80ULL, 
            0xE3242E022D3C3663ULL, 0x66AF72C240F54B43ULL, 0xFE7E13C270447E2CULL, 0x9BB487D386D4B7A2ULL, 
            0xF63B85963834E46AULL, 0x53FA9459B48BBCF7ULL, 0x05AC21D456AEFD58ULL, 0x2E58056D1C537BF6ULL, 
            0x189EB82055132127ULL, 0xAE9ADCE971BBF77DULL, 0x7FDF9BB9E2B4406EULL, 0x59C6C3897686583BULL, 
            0xBA16711213308916ULL, 0x17479F6318108FB4ULL, 0xEEFB9C3A9866188FULL, 0xE17DBCF4925D4730ULL, 
            0x705E16E5645F3364ULL, 0xF19B0ADF69ED8DBCULL, 0xC4422D840AE60060ULL, 0xE0D15DD37E7443E8ULL, 
            0x40E1ACF8D16E7A10ULL, 0x2A303C39A51BA609ULL, 0xEF848FB92A7D34E1ULL, 0xA4A1D90C67728518ULL
        },
        {
            0x622ECDE7347E06F2ULL, 0xDDFA24BF1228CE7BULL, 0x1E70C1380DDB7B51ULL, 0x0D618887426A6D94ULL, 
            0x31991A408D75F472ULL, 0x121B67D9166792E6ULL, 0x737434A105A9C086ULL, 0x03AB4EF3A61842E4ULL, 
            0x8336505C847EE465ULL, 0xA1702BC94121C490ULL, 0x54185BA045236772ULL, 0x2D37F68766FA42BDULL, 
            0x9857D203A3BA7491ULL, 0x6BC1AF768B0927A3ULL, 0x670C5B7C5952BF9EULL, 0x73443D1C9AD9CEEDULL, 
            0x6D01A4A494F8C699ULL, 0xEA3841BA94A0DA69ULL, 0x50791BD322C7BB62ULL, 0x51BEAA78B7A56031ULL, 
            0xBAEBDB12CB4EA4FFULL, 0xE982E473556F8BDEULL, 0xD4A120478B8BD7C8ULL, 0x04A28D1FAC30DA7FULL, 
            0x51E4210940E42C69ULL, 0x75D2D410A21AE427ULL, 0x343F050F372EA7F6ULL, 0xB23CBFE134009FF3ULL, 
            0x7825F9D5DA4C46CFULL, 0x154FCD4AD1514F50ULL, 0x2708E1F5A7F73750ULL, 0xF3194605DBDFA547ULL
        },
        {
            0x4EFF1E0FCAF49FEBULL, 0xA826B1E24E41D785ULL, 0xDC147FD9C55150E9ULL, 0x1CF09544F2261B04ULL, 
            0x4CE1B87743A6B45FULL, 0x8832A1042C0BEB54ULL, 0xD87241A460FDCF09ULL, 0x5056469A528E08D2ULL, 
            0x63BC9618BE7F8442ULL, 0x4233394DF944E71CULL, 0xCA954A88FD5E4E2AULL, 0x5FECC8596EEBFD09ULL, 
            0xD2587A5ABF0DA09EULL, 0xF8C0A5F2D5E916D9ULL, 0x4BE42D1256B75DADULL, 0x4A018CC79319836EULL, 
            0xCDA8767D9D1D3DBFULL, 0x850025AEA6FA3DAAULL, 0x7A753E5BF325596DULL, 0xA581D486B44AB39FULL, 
            0x16FA239C2A97D225ULL, 0x4DF132998D522C56ULL, 0x7D3A12AF58C7EE27ULL, 0x9B00EA702FE6CA8BULL, 
            0x6379261C6A82F67BULL, 0x1EA22516855AB73EULL, 0xB733394115A19B43ULL, 0x17E81C65E2897613ULL, 
            0xB6D77795A4EEE42EULL, 0xCB9B58BC1C49662DULL, 0x5F9B72119F562D71ULL, 0xE68EF021DEA5DDE7ULL
        },
        {
            0x81F1AA93E829BA5FULL, 0x9DF890B355024BFAULL, 0xD37CB1F4D9407140ULL, 0x8EE96CA8A5BA61C2ULL, 
            0xDE7A04CA1580157DULL, 0x0C00288F65AB2AFDULL, 0x74421543FD9056FFULL, 0x6D4444CCC0B7B235ULL, 
            0x487319563836FD87ULL, 0x464A0044FD436AF5ULL, 0xC428AFB4170D6B3FULL, 0xDB0BFB6708E90CBDULL, 
            0x48115227B5DF017BULL, 0xD364EB49DF994922ULL, 0x84D3EE37F7755353ULL, 0x7D92BD642AA75C95ULL, 
            0xC3732752D1857615ULL, 0xAC137584925296A6ULL, 0xDDBC9EFADA580322ULL, 0x9BF0403A6424050AULL, 
            0x09FC3F5DBA694A22ULL, 0x15CD64E70C839082ULL, 0xBFEB3D29EBE87D02ULL, 0x4EDC5AD071BAAF11ULL, 
            0x1CAD09A12450F969ULL, 0xBBEA4BC0B3DCB167ULL, 0x1E6E6002FAB6B2CEULL, 0x7A591E4A9BC15DCAULL, 
            0x8F8AF818E7D8768EULL, 0x195629B4983C9F0DULL, 0xB4B7143DAA8DE6FCULL, 0x39B5CC114AEF6329ULL
        },
        {
            0x0D06CFE6A4C6CF55ULL, 0x83A6035613DEAF0EULL, 0xE736D8E27044CA33ULL, 0x692A846E9DCC3BA0ULL, 
            0x091192FB959876F4ULL, 0x8B018B6DB4A1B87DULL, 0xA68EFDB19782550AULL, 0x98480A6AC6875544ULL, 
            0x7C3CBF91D04265A1ULL, 0xFA9E6B4DF5AE1C85ULL, 0x09FDFB8468B387E6ULL, 0x37D0F05B207C55EBULL, 
            0x11A8A65410647E06ULL, 0x8995EF6FD6DA7C92ULL, 0xF2B2F2164623C76BULL, 0xD45877E5CEDC8418ULL, 
            0x71436B6C1E8EAD58ULL, 0xDC126612680A6279ULL, 0x1213CA613A67F7FAULL, 0x89F2F70FCD8F053FULL, 
            0x998C17025AB11B84ULL, 0x3743D3C8B6F3DA99ULL, 0x0B874504C1EDC6E0ULL, 0x1019F8D76231E9CDULL, 
            0x20E5BCB5FEDAF761ULL, 0x986502B102A453EAULL, 0x1EBEED7A7F973D30ULL, 0xB567120F9C2A5376ULL, 
            0x49DCD899900F8060ULL, 0x2A8CDCEA93756998ULL, 0x47F9DE172D9BF002ULL, 0x633CC4ECCB7CFBFEULL
        },
        {
            0x8EFC9985BDA96DEAULL, 0x9959FB95A1234A95ULL, 0x793E98DDE48CA17CULL, 0x943385943EFFABA2ULL, 
            0x166971AE29A120FEULL, 0x9A4E859C1CD52A62ULL, 0x5844E9C265EC7A3FULL, 0x66EB37D3F00B271BULL, 
            0x23A619A2A7B36388ULL, 0xAA6E3F5441952E76ULL, 0xFD4918BA9F170181ULL, 0x0078D2688B9BF4F9ULL, 
            0x7BFB6BA112A6C925ULL, 0xA37F9DB4486134C7ULL, 0x6E72E708C22D5E8BULL, 0xA2FBF0418E831BC3ULL, 
            0xCF2B594E8A54A5E5ULL, 0xB156B855FFC48010ULL, 0x8A6F6BD50BEF6A36ULL, 0x86D821251DB0C4D4ULL, 
            0x84EC758C4A354DADULL, 0x40C97F988CFA86DFULL, 0x2EF86D707133CBA4ULL, 0xBF88EA41A1E16AFAULL, 
            0xAC258515B92A8686ULL, 0xCCDB8282E12DAEC5ULL, 0x6DA06457DF107478ULL, 0xA90A24E0F59D4F81ULL, 
            0x60FA7B7B163AD1A2ULL, 0xBE787CE655C7F628ULL, 0x3838D1540E8B294FULL, 0xF97D26052B97602BULL
        }
    },
    {
        {
            0xA3BDE7A50BF21E93ULL, 0x735CD329239116F5ULL, 0x661CC866029F50C1ULL, 0x7FB4603AD0710DB7ULL, 
            0xFAB1308F6ACDA2DAULL, 0x6760317555EA3A49ULL, 0x4104E58659AA3283ULL, 0x360A5E1F58B5D8CAULL, 
            0x18307C3A2829C691ULL, 0x589976E08B735BADULL, 0x8F0B361B449F9DF7ULL, 0xBEA7AF21181D7BA1ULL, 
            0x6372308D290FB794ULL, 0xE0F56B1921A5CD7CULL, 0xB1E557754F1D47D7ULL, 0xC4A42FEA0D79509CULL, 
            0xABD3ED5BE6577323ULL, 0x9BC428049F507DF7ULL, 0xE3C9266B79313A0AULL, 0x2CA0A1858B9666D3ULL, 
            0x08153A3093294991ULL, 0x7E283C2509AAF694ULL, 0x037F2E560EC61F8BULL, 0x2C13C49ACC64F854ULL, 
            0x68BDE3E149C1FFB6ULL, 0x272F6EBEDA14350CULL, 0x75EFC14FE2E02E9AULL, 0xD537B10852AA6C43ULL, 
            0x5B5776EE42E043BCULL, 0x893EC8930C4BF24FULL, 0x7F68A8E712939F1AULL, 0x309642E8532A16A9ULL
        },
        {
            0x463565DF7AFE952FULL, 0x0684E8930BFA08E0ULL, 0x62F6E3F6E1738FF5ULL, 0x8DDD4E9D2E1FD60BULL, 
            0x4F7B3C4C632EC783ULL, 0xAFAAB8474E891BECULL, 0x2E02ABB7C3996E17ULL, 0x27AD62192B44AB30ULL, 
            0xC243D120281EA014ULL, 0xD986D008D8FA51C0ULL, 0x475EE750A57C2665ULL, 0xEED9C5527269E847ULL, 
            0xFB7BFB18EFFA2395ULL, 0x010F7A9B64376C27ULL, 0x448CE6A899831E5AULL, 0x88C5F2C9FEF06B9FULL, 
            0x89ADAC4333599695ULL, 0xD8BB40911A45EF34ULL, 0xA8447FAE5FE14FF4ULL, 0xCF3AC6B58301E48EULL, 
            0xE4978C59DC197B7EULL, 0x9D7FA08F2775BE0DULL, 0xF2E3A3DD02B5C71FULL, 0x45F91D3DE99E0FEAULL, 
            0x6D6A65C1C8A501A8ULL, 0x3B10AA9A39B17C32ULL, 0x2E7A4E6A37F872FEULL, 0xE78438F0454906B1ULL, 
            0x1B8021DED26FCFFDULL, 0xADE3392C63D668EAULL, 0x91AC56A50D6F48F6ULL, 0xF326FE858D233D2FULL
        },
        {
            0x985E48D4DC0D28D4ULL, 0x0A24A9806C337DA3ULL, 0x4852E24592D424B7ULL, 0xD3E039BAC7D4DF8DULL, 
            0x3CA11353118D6882ULL, 0xB6465D22F0D62A9BULL, 0x90CB0578C46C017FULL, 0xA05C4D7F5C51AEF3ULL, 
            0xE25B67066AA3AC2FULL, 0xD2A2120308785BDBULL, 0x7529D956DA22A790ULL, 0x0704D098CE14A2A7ULL, 
            0xDF54507A0BD6F55DULL, 0x247E23289ADA49CBULL, 0x68340CDD85C2E9F7ULL, 0xB6F77C72464F0D99ULL, 
            0x05992C848F5BDCA1ULL, 0xA321F72C29369B3EULL, 0x15D43402F7112704ULL, 0x75860ABFE595A782ULL, 
            0x37B0CC8C9100D54BULL, 0x8D85BBAACBFB636EULL, 0xB1E67AFA573631AFULL, 0xEFF1EE1AB5564A85ULL, 
            0xD0535C8A2B2FE34EULL, 0x4722A8F2A93DFA08ULL, 0x6FB0BAB5740CA76BULL, 0xCC05B9E0D1F92C3DULL, 
            0x6B6E7E90422AD5E6ULL, 0x62AA197488196804ULL, 0xF7AE7EC157C84FC4ULL, 0x65EFCEBCF44E6118ULL
        },
        {
            0x8BD459AEA45D1F72ULL, 0x60A0B3CDF54D9EACULL, 0xB6620A956B0FCE2AULL, 0x99C172B32ADC6737ULL, 
            0x35C5A539C7807E8CULL, 0xF6469C53D6FDC6CBULL, 0xB6A0E080CA8F0CFFULL, 0x0D7504E26239D568ULL, 
            0x10093E55955D2581ULL, 0xEFF5363598006E2FULL, 0x961270EADC67CC49ULL, 0x276AFC3AFF1D0687ULL, 
            0x83F7DE7761716C7EULL, 0xC14DD40EB0343A27ULL, 0xBC285F954534EBD6ULL, 0x3F1CE38FF59C479BULL, 
            0x452CD7203A2BD98EULL, 0xEE38650125CE49ACULL, 0x774E84EC3EAF6AAEULL, 0x30ED875316D43393ULL, 
            0x3FE34EE1C53137A9ULL, 0x3516DEF656FFB30AULL, 0x5DC83ABA5F8CCA50ULL, 0x8F1EE98A94E9F8AAULL, 
            0xB50EBBB9BD1E7510ULL, 0x28E46C8A333B787FULL, 0xE58959F1373FD4D4ULL, 0xAB6DC00095CBD37EULL, 
            0x205DD51726396485ULL, 0xBAE33B83C6534318ULL, 0x6142C366743D798FULL, 0x98CCCA233612CD98ULL
        },
        {
            0x39CB38CB77BFB6B8ULL, 0xEB67B51C98D8A6F8ULL, 0x90FD1F215981E91EULL, 0x5F9E91CEFE48512BULL, 
            0x6467AB6C77B0CA83ULL, 0x0FE48DA821BD98C1ULL, 0x5A7876E22B897E59ULL, 0x552184EECDBB4A25ULL, 
            0xEE968A3DEC390DBBULL, 0x6632E6D57209AF1EULL, 0xC3C2A4C442F9C9E9ULL, 0x0202F073776B959FULL, 
            0x1B656CFDF9510B18ULL, 0xEBA9AAE51B500F0CULL, 0x675D3F70722E92CDULL, 0x00595C1399248E3DULL, 
            0xCC95B28D034621A2ULL, 0xE31D4B9AA4A9850BULL, 0xC2C359454008BF67ULL, 0xF991A8FE75F2187DULL, 
            0x3B5041CF90630F76ULL, 0x542BD776961D002DULL, 0x92A8DCD07A974BE7ULL, 0x4FA18BF6FC4224C1ULL, 
            0xBA98B44563745C55ULL, 0x85DA976BD6FA873BULL, 0xD52EA5C78619DC45ULL, 0x0935D5BDD81FC2C9ULL, 
            0x86A5B31F919BC3A7ULL, 0x7E2CC986B5C0B1BEULL, 0x2E80F9D715BC27BDULL, 0xC1FA3AD23545A93AULL
        },
        {
            0xE3459E100082FC85ULL, 0x4EF64B133DD4C54BULL, 0x50B21B649D98ADF0ULL, 0xF6123073C9A179A3ULL, 
            0xB6F38A1F9AD958CFULL, 0xA16BD05DA335FF1FULL, 0x7885028EC6340E95ULL, 0x0FC8DBE8CCA6540DULL, 
            0x33BE8231AF2787BFULL, 0xFA73809CAFF5A268ULL, 0x20CE3E98F61821B2ULL, 0x43205DD65DDAC7E4ULL, 
            0xF1D4699A4AD46628ULL, 0xE75BB0A6BC5AAD44ULL, 0x601209603B2F0280ULL, 0xE8D982BC821EE29FULL, 
            0x99E78956D1F165B5ULL, 0x71028E283425BDEBULL, 0x850AA116FDDE5640ULL, 0xEF7A08E933113652ULL, 
            0x588A0B545CF36D62ULL, 0x7D4121F424302E5CULL, 0xFCCE6A1D51185605ULL, 0x92D5AABB39B30B9FULL, 
            0x4F95AB4977ACB80FULL, 0x3DE328A0EB4551D4ULL, 0x6B01C2E13043A26DULL, 0x3C5F09BFC2A63FB3ULL, 
            0x8A62BEF8179D42FEULL, 0xF42AFA49910C926EULL, 0x40E97F05AEB3A647ULL, 0xAAD4779A0B4C6A46ULL
        }
    },
    {
        {
            0xBFE762BAF8CB5D3AULL, 0x4C1FBBE0CAD3709AULL, 0x0E1293D79FE28266ULL, 0xD7624BBD338588CBULL, 
            0x867E716B4DADFFF6ULL, 0x37DA8BB8EAA1D04CULL, 0xF7065169844F5ACEULL, 0xBCDE8EDCF9DD2696ULL, 
            0x8FD867613B87D74EULL, 0x698871741B1292CAULL, 0xB1B1D54D3EB0F74EULL, 0x542D09B395092149ULL, 
            0xE7355EA9D462CCE5ULL, 0xFE6AE819D4CFB47BULL, 0xE926F811184B0558ULL, 0x15E4B388AFCB7238ULL, 
            0xE00292834C38C0E7ULL, 0x0BAD223A48E5E47FULL, 0xED45C4249B6816F9ULL, 0x108A1129B0AE3BDFULL, 
            0xF3BAA4CD8376223CULL, 0xFD70A5DF9EDDCC6AULL, 0x9E03C5C6A994A764ULL, 0x0E004D83BB2A961CULL, 
            0x90373E3246349388ULL, 0x5FB497714BEC860EULL, 0x1802F5BEC199E513ULL, 0x36FF0FF3BD041BC5ULL, 
            0x529FA6C48F51EDADULL, 0x08AF0355DEE19653ULL, 0xA332960729257090ULL, 0x9C06C04E5BBD71A0ULL
        },
        {
            0xB00BFC4D6D01C964ULL, 0x03C32E108E41BD8CULL, 0x304738D897C12D33ULL, 0x3FE900DC10B0DE02ULL, 
            0x931137716E93FA1CULL, 0x5A1D9E95D3AC7603ULL, 0xDF7865AE05161C57ULL, 0xC110A84334112ED4ULL, 
            0x77B0F18334F2BFA2ULL, 0x75AA858EF635B220ULL, 0x98D180E7F0244FF5ULL, 0xC1B1EE7AC9E0C2BBULL, 
            0x44EF1C8BC030EFCFULL, 0x4CFE60843D4AB7B6ULL, 0x922CB0B118208AE6ULL, 0xA2FD213082A66E27ULL, 
            0x4DD8319ACEB04101ULL, 0x8B32F0F7D1784E1DULL, 0x0D0EA6A04E574A16ULL, 0x111CF7741E8AA249ULL, 
            0xE140D58F0D70536AULL, 0xC01DFB3DD49E5B06ULL, 0xEEDB65E8A545D180ULL, 0xBB7E65720B022710ULL, 
            0x62E4461C78171805ULL, 0x9A02C59EF3A0E702ULL, 0x6B9D3E674371D1CCULL, 0xB5265FA79E92D61BULL, 
            0x7C931319FF3FF899ULL, 0x906BAFCA524C2D46ULL, 0xB9E7F09D886FAAF9ULL, 0xEDB2FE9A3A2D9193ULL
        },
        {
            0xF535C18EC821D31FULL, 0x56AD027458B943F0ULL, 0x91DC5474622DBD07ULL, 0x951A1B22D2361EB4ULL, 
            0xE98455E892AB04E4ULL, 0x87F00355B90767B6ULL, 0xDAD33892A5AD2320ULL, 0xF60393146A25822DULL, 
            0x4C7BDD443BABF655ULL, 0x51CD9D91FB5A5646ULL, 0x310903E75CE64025ULL, 0x185997502C97CCA8ULL, 
            0xAF6CB08554DA823CULL, 0x64E31225FBA2AF74ULL, 0x0D3601D676094D67ULL, 0x4AF2C40F6B862E06ULL, 
            0x4325D9CB3C862364ULL, 0xC2CB6AAF5BA435FAULL, 0x1171B07D3C581700ULL, 0x4A9FA96921B9DB9EULL, 
            0x6318A6817D8757DDULL, 0x89EDCB3E096DE7ACULL, 0x6C938C85C9CB2EFDULL, 0x8369FAE9869CC0E3ULL, 
            0x5B7907207EF3DAE7ULL, 0x4B53DF3A120C7AA0ULL, 0x2F4A18A2AFC99E42ULL, 0xD9119D948783253EULL, 
            0x368DBABE70E7E7C8ULL, 0xB38AF06BBF0676A6ULL, 0xEF95DCAEC277D436ULL, 0x6DCD9FA6232260A1ULL
        },
        {
            0x36314E5F60CD55E0ULL, 0x600CE989E8B2295AULL, 0xB4B45102CEDF9A2BULL, 0x888576B84B033314ULL, 
            0x20F68031F2B59111ULL, 0x453CE24BC024483EULL, 0xF05D0B8A8D890666ULL, 0xE75669F4E896B1F3ULL, 
            0xFFAF6F8DCE56876DULL, 0xA989B83E0B14AB37ULL, 0x6C8632C84DFA9EF1ULL, 0x790667910834378DULL, 
            0xFD6AC9B28771D51BULL, 0xDD30235BF6F9C2C6ULL, 0x1045AC31B16805B5ULL, 0xEAFE971DB8B9F63BULL, 
            0x40850CE977F5846AULL, 0x9E3024FE729BE588ULL, 0xAC04B48D346B51F1ULL, 0x7F454999B96659CDULL, 
            0xA1E87B0226B54CE5ULL, 0x0624A26888C605EAULL, 0x53A434F86F4136A8ULL, 0xB9CE8898AB71B4BEULL, 
            0x48F6F125F6FF8F0CULL, 0x8FE94AC06857FB07ULL, 0x52C3F3B4E5795886ULL, 0xFC1F925665ECBAAFULL, 
            0xFE5067B505BB0F65ULL, 0x1B92A523D92EBD76ULL, 0x2187A6A23B59B6ECULL, 0x927FE27F3C788BA0ULL
        },
        {
            0x1C92B4CAF7820028ULL, 0x9D499710D71FA445ULL, 0xB773D5441CCAFC35ULL, 0x614A70ADDEF68699ULL, 
            0x5E45910A554E4E72ULL, 0x83CD5442AAF44E01ULL, 0x07624189D21872B1ULL, 0x2884ECD623A4A381ULL, 
            0x93A0614E115F5428ULL, 0xDBD39998FA65C43DULL, 0x942ED792470DCF62ULL, 0x246A8E52F6CF5843ULL, 
            0x3D67473BD3220ACAULL, 0x977620D2AF133242ULL, 0x24204D5BD8296853ULL, 0x7973CFC6CA68DD8EULL, 
            0x31CE0D7ACD79CBD8ULL, 0xCA6995C88233BBE6ULL, 0xFB9F2AF8A42B2F4CULL, 0x6DCC3FE32B22C97FULL, 
            0xE4556631CFB869FEULL, 0xB8D9F03BA39B87B0ULL, 0x36547C6884BFB08BULL, 0xF091E285C1E92788ULL, 
            0x164EFD539FA31B6CULL, 0x42F3F4C005CD9D30ULL, 0xE5E8DBDBDA9CC5F7ULL, 0x6962F6A3EF57CBB4ULL, 
            0x73BD919BB74160F5ULL, 0x11FD1D4F9EA177E1ULL, 0x9F57E1F66F7B9BDCULL, 0x336DEB7AE4207508ULL
        },
        {
            0x25637E40474D3FC4ULL, 0x78C54CBC9161CB2BULL, 0xCD608F4D11ACC344ULL, 0x583846E9D32D24FBULL, 
            0x95D615246885AF40ULL, 0x280804CEEC2C2FD5ULL, 0x8737B2BC601189E8ULL, 0x81DC63E047102BECULL, 
            0x37016EA5E7FA5798ULL, 0x7E5B875600FDD6F0ULL, 0xD0F4CDA5EE17A0BBULL, 0x8C4BA516D82A1F13ULL, 
            0xF5C5F597425DB952ULL, 0xDB0566864A00D957ULL, 0xFF687385AF517C5FULL, 0xA887A530EAA7A34EULL, 
            0xD1E261DC61093373ULL, 0xE5162A8FCD623494ULL, 0xB9477A104CD5AA59ULL, 0xAAFEC5BDEEFFA553ULL, 
            0x5A835C8B9712BA56ULL, 0xA8C644A0FEBE31B1ULL, 0xECCB72EFB64D5F12ULL, 0xC1283F9CDF0B8012ULL, 
            0x1BE72B6D73EB9908ULL, 0xD6DE9DFD4EC4B13CULL, 0x87E8A413EAFD2348ULL, 0xF2016E10F55E78DDULL, 
            0x3DCB1879A3766621ULL, 0x5301D2849D52B047ULL, 0xA001CAA39E9CDE7FULL, 0xC504F71CBDA1874DULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseBConstants = {
    0xC927EEF55FC4A048ULL,
    0x4BC58539A66BDA5CULL,
    0x1C06495F151ED309ULL,
    0xC927EEF55FC4A048ULL,
    0x4BC58539A66BDA5CULL,
    0x1C06495F151ED309ULL,
    0xD9F9BDFB06869ACFULL,
    0xD3970B8097966D4DULL,
    0xBE,
    0x23,
    0xC7,
    0x2C,
    0xA8,
    0x36,
    0x14,
    0xC3
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseCSalts = {
    {
        {
            0x0EA65196A625DC46ULL, 0x8434625BDC472A8BULL, 0x9B597096DAE89834ULL, 0xC69837E4EB4A1259ULL, 
            0x30CCD9547A248405ULL, 0x3A5363B30807616EULL, 0x50C714FD825C8EB3ULL, 0xAB33F0A2AB36A31CULL, 
            0xEC460F2C00270717ULL, 0xACF3A0DC9C15A03DULL, 0x932576622941261AULL, 0xFC184D753EA71C72ULL, 
            0xD7B471ACFA0B298DULL, 0x005C1B0688F4957FULL, 0x7D26B49C3454C9ADULL, 0x7ED6F25EC67AC349ULL, 
            0x6CFFE746342C6AF3ULL, 0x124B115D26B3E802ULL, 0x9D265B488D736F64ULL, 0xAB23E50C1FF7C213ULL, 
            0x78AF58EB416757CDULL, 0xEA91192772B475B3ULL, 0xC37F3A82A1093AFFULL, 0x0AFE22AABBC7846DULL, 
            0xE997B0621105471DULL, 0x9209E5AA43688849ULL, 0x3654F0136E93F75CULL, 0xDFF0E3367EB893C7ULL, 
            0x69D9E4523CA29874ULL, 0xB35821429A5D644AULL, 0x556AA7AB7F70E1C5ULL, 0x9B250CA146B35628ULL
        },
        {
            0xA408CB371CBE99BAULL, 0x8FC8DE35CA5FDF1EULL, 0x88E2B84F173889ACULL, 0xB3DD89C3B8241F58ULL, 
            0xEFD3A1CA7995BB74ULL, 0xDB6C173EDF977732ULL, 0xE3CC85BA35606125ULL, 0x8D904FE2CF870084ULL, 
            0xC3107EB4A7AA0E72ULL, 0x906E0AD4D3AAD93CULL, 0x68B2100B49DE218EULL, 0x2614B8F3AA7C7686ULL, 
            0xFF438BC3F9D158A3ULL, 0x56815514C5377998ULL, 0x653DFC08281A2DE0ULL, 0x1F54B12E1BF70215ULL, 
            0x99EE6BAA393715E8ULL, 0x86EB28BF7D7DCD4AULL, 0x82E31786AAAD5CA3ULL, 0xE40D877783E49842ULL, 
            0x7CB73AAC8B963B2CULL, 0x1CCCB2DF388AD3A3ULL, 0xDCBB51C2910D6427ULL, 0xBA944B9DE4CD7C6CULL, 
            0x76D73AA4989767C3ULL, 0x419213B9F1A3B9D5ULL, 0x713B07BA0E3B024DULL, 0xED30E8023F490BC9ULL, 
            0x74ABEBAC6EBAB0B6ULL, 0x726747486BB8EC0DULL, 0x97B88C9DBA6D7974ULL, 0x9523093F75886D71ULL
        },
        {
            0x4B0C0408F9A3421CULL, 0xBD396AA89DD21CCFULL, 0x07E2E1B1D0F39107ULL, 0xE38125E6347209A1ULL, 
            0xFDEB9A3EE18F6ADBULL, 0x3554A1D8DBD0EBE3ULL, 0xC20BC6C7948B6AFAULL, 0x43703654AFCC9C46ULL, 
            0x18C812EA7A0B14BAULL, 0x37D22EFF646CF5DBULL, 0xD5EFE69211C9E22FULL, 0x27F4B291034A0E9EULL, 
            0x171E62A529C823F0ULL, 0xEE7589107B4FC1C1ULL, 0x6F8FBC551CB007B8ULL, 0x99D35855011FF323ULL, 
            0x454CEB06A0401FBDULL, 0x04792A6252E01364ULL, 0xE57E641D4C329433ULL, 0x0C836BF05B28AED1ULL, 
            0x4466CCDAA2FEF8F9ULL, 0x9BBB5DB6ED3C9E5BULL, 0xDC48151CD9CC78A2ULL, 0xD2021BEF963C1260ULL, 
            0x2E24397F6F19A607ULL, 0xC07AE3EE708E9523ULL, 0xB4D753149D12036AULL, 0x8C65F6E8E83DCED6ULL, 
            0x19E1304160291E8FULL, 0x7E4C1C5F998F3BA6ULL, 0x31DABF6A7A276C7DULL, 0x828779C02E1F0DA5ULL
        },
        {
            0x65920C50AA0237E1ULL, 0xA08BD1268BC5F790ULL, 0x72520332BE18DB1FULL, 0xE6FFC986E1BB6B18ULL, 
            0x03A045A1A2B4528CULL, 0x4217907B6ACAEBFDULL, 0xC4CE36B23B47040AULL, 0x73AC051172871F73ULL, 
            0x234C46B014569A3DULL, 0xC27B16FD1F7A402CULL, 0xFBA70C929DF340DCULL, 0xA2E046E575DDD6C4ULL, 
            0xC95D3F2E26781E6EULL, 0x0AC80C1B4C01D6C6ULL, 0xDEAC743C455A2C94ULL, 0x1127DCDC96117DE8ULL, 
            0x49BB6300A36228ADULL, 0x227F6836C906802DULL, 0x862EA95D2C07CF5EULL, 0x7FDD65A87DD618A6ULL, 
            0x31D081FDEFEA12B1ULL, 0x092BA8DD8E77B081ULL, 0xB46B73E9A5F1F629ULL, 0xA96A7C58FE5A5F9DULL, 
            0x8F4F263D58B6F69EULL, 0xFA8B74313BC1F3BFULL, 0xF659C8BFA4DE7C1CULL, 0x486354FEE9A283DEULL, 
            0xA4584684813C75CAULL, 0xD400803EE8C933B1ULL, 0xC5FB7FF94590D667ULL, 0xBE0496CF0CA10587ULL
        },
        {
            0x90D4934F9C3B5763ULL, 0x89104AC0EB3D24A4ULL, 0xF69F6164E4592FD2ULL, 0xC3A1B5B472510095ULL, 
            0x46A44696FE3DDC2EULL, 0xA4CA7AFFB1DBEA58ULL, 0xDA9381A4A4D7DE92ULL, 0xFD8BE12EEBE05754ULL, 
            0xC74FA76B58276954ULL, 0xA55C9F7AD2941607ULL, 0xA192BB6D7F276597ULL, 0x375472027CD8AB6DULL, 
            0xE7BFB4FE9FA28A9EULL, 0x8CFE2EE604CF96E0ULL, 0xDB4AA32584DBDFF5ULL, 0x5CACD6A47E3A8A28ULL, 
            0xC927D34067230254ULL, 0x3D43A9DB8BF45C1AULL, 0x9B2D4751269DB86BULL, 0x64759E6BCB55C749ULL, 
            0x3B87B16FDC1B6A2EULL, 0xE2E0DB79D30E335DULL, 0x58F22462EB4C430DULL, 0x99D0129173EA7F2EULL, 
            0xF075EC25C39CE28AULL, 0x93203951F7978CFEULL, 0x85BAEF412BF1975CULL, 0x8E6B8ACBD06FD7CFULL, 
            0xF17C7AF1A0931753ULL, 0x0B6510A5CAFC69FFULL, 0x8370C0517D087BD0ULL, 0xA0FAF4476366A1ADULL
        },
        {
            0xE637B1C7E40999D5ULL, 0x96ED3AB8ADED7131ULL, 0x96B181073C7B6FCBULL, 0x90CDC83FA8F81DADULL, 
            0xECB0A1045BFAC0BBULL, 0x8AC9E82D7C983347ULL, 0x3CECDDAA74CF3E6CULL, 0xAB889015795A1E87ULL, 
            0xA3B96695E80DEBEFULL, 0xF161FAB58A7BD79AULL, 0xBD78E836C41AD8B0ULL, 0x8068CF99B7D55B00ULL, 
            0x9E1D266D69F4797CULL, 0x9B9F4F2B45E9C30BULL, 0x79201BBCEFD12DC1ULL, 0xD6F86CD2834D5EBCULL, 
            0xBB1820725963BCC8ULL, 0x71E2F6ED9F34A705ULL, 0xEC551326696F9550ULL, 0x3F4F770063F7DE1CULL, 
            0xADBEA683E19A502BULL, 0x7E10D756ECE04EFEULL, 0x6CB9252124F371F5ULL, 0x9A47BEB786DD9597ULL, 
            0xB875B872D23AE374ULL, 0xBF32095AE74D7732ULL, 0x568E91CD11E34DC9ULL, 0x4784279D9143AABBULL, 
            0x0F1E358A55EFED16ULL, 0xF060B11CA03D23B4ULL, 0x284B57E6FD0D97CEULL, 0x6EAB56AFD3F5B9B1ULL
        }
    },
    {
        {
            0x861B625A21E66FCFULL, 0xF71368EC3CED2AE2ULL, 0xEAC4567B38DE58ABULL, 0x579A39B167514127ULL, 
            0xAA5EBB48242245E9ULL, 0x549657AD7B53D606ULL, 0x3728F7C37F8DCE41ULL, 0xF0CFDF3AD7DA7BB1ULL, 
            0xAF4A995B0D4C04C0ULL, 0xEF4D7F6E8D5A8F5EULL, 0x39176789D1408AFFULL, 0xD2D0E0E922979AD8ULL, 
            0x768A8EEAB90621FCULL, 0xAFE8154E0E2C6BC3ULL, 0xBE51827BDCBB3F73ULL, 0x83A62E786F7B6D8DULL, 
            0x7FD42569E96DCAEAULL, 0xC91E39F4A746E3F7ULL, 0x669D18B07DA224BAULL, 0xB43B1C6333DE3AFCULL, 
            0x50E5BE924F006B0DULL, 0x0C2B77851D674E7EULL, 0x28E5EC25DE342A8BULL, 0xDEA8FD1069BD11F0ULL, 
            0xB6DB47360243295AULL, 0xEFDCC7F39214701CULL, 0x33F8BAF683D864DCULL, 0xBA5C68D84BBB6D48ULL, 
            0xF1FDF1396EDDD821ULL, 0xAEF08198689A3103ULL, 0x3829648DFA69D463ULL, 0x286C4CE70F018156ULL
        },
        {
            0xA212D8496A5F1FCEULL, 0xC28E685760ACD011ULL, 0xF4842FA1EC64DB73ULL, 0x3AE38963EEB82263ULL, 
            0x4AF93BBCAF93CDEAULL, 0x6A0C61673464D50DULL, 0xEF4FF757256DD154ULL, 0xE9566ABF3067DF88ULL, 
            0xFDEC1B37344D66DDULL, 0x0A4A4D6335E22BA9ULL, 0xC0E00A0175ABC57FULL, 0x1E6BC3D55D2B3320ULL, 
            0xCC1137F7EC862378ULL, 0x12794F71DEED37D2ULL, 0xF4196A39976D9A77ULL, 0x6DD56DB7E5B655EBULL, 
            0xF63B8FEF2A1738D6ULL, 0x0AF18107FF27029AULL, 0xF487512506BB7483ULL, 0xAF608EC870981DC8ULL, 
            0x7475FB288C39F409ULL, 0x2C3DD91FBB903AC7ULL, 0xD3F1BD905AB3DD30ULL, 0x1ACD422AF049D699ULL, 
            0x0357135CD7A16283ULL, 0x0942852BBA1758E4ULL, 0x2B15DFCECA28E1ABULL, 0xEAFC898F51B2BAD5ULL, 
            0x190E4041C7227B8EULL, 0xE2110B25BE4394DFULL, 0xD27D0A8215B3B97FULL, 0xBB1A52B721761BE6ULL
        },
        {
            0x6200B0537B49D4A5ULL, 0x0EE2803EF341F27BULL, 0xCFD6CC2516EEA80CULL, 0x69BEECC6AE8758EDULL, 
            0xD351535CF17EF1EDULL, 0xF9461F229412443AULL, 0x37B7B2D03D3638AEULL, 0xFCC77EA6C303C7D7ULL, 
            0x6A35FB020116CF73ULL, 0x109C45470DD5366CULL, 0xD689A0DC3FB95AF0ULL, 0x8599C0FDB77D8599ULL, 
            0x68612ACDD5F79AEDULL, 0x015FB8038F47E109ULL, 0xACCCCD159C683EFCULL, 0xA0E2164CD6431009ULL, 
            0x139FF5AEEFB07F49ULL, 0xEBBE950C3A5000C2ULL, 0x05EF97B765B83AC5ULL, 0x18F93FFF8FBC5437ULL, 
            0x16B9816DF5721A52ULL, 0x030A55246FC4E887ULL, 0xE0BCD3658EA23FE5ULL, 0xB146D6F94FB006FDULL, 
            0xFFBBE2AED75CCC4AULL, 0x1CE197A08250C8B2ULL, 0x1F0F7575529E9DEFULL, 0x499510AFF86AAC64ULL, 
            0xFA41E0D18BB48B4AULL, 0x854B8781207A0E17ULL, 0x804E2C8301BE6081ULL, 0xE2E15AF268B5275BULL
        },
        {
            0xA71FE008FABCE553ULL, 0x9B701EC321B3AAB1ULL, 0x6BB035D5D1E79C8DULL, 0xA2194E26156A8900ULL, 
            0xABFA9D2CD3A1EFB5ULL, 0xA86A70423B6B4826ULL, 0x7D5C7C3E1A912DAFULL, 0xF286D3D045B71416ULL, 
            0x0E6A5BFEA8625A0BULL, 0x439CE64963C76500ULL, 0x5E7BB092FF6AC422ULL, 0xD24BE36C577231A7ULL, 
            0xF0FD8106797D521CULL, 0x37E124E151329138ULL, 0x0CEFEC9185856BDBULL, 0x0C46D6FDD119F04CULL, 
            0x04E5174C88872A0EULL, 0xA92BDC95A0B3783FULL, 0xC453D4E31E8EDB7CULL, 0x2D23C0A2AE17AE3EULL, 
            0xED25A2B2227B92CCULL, 0x8E6C6A304E9EF6EDULL, 0xF563B0C9C863C77DULL, 0xD8FB9A3777A22A5FULL, 
            0xB6F91C9097A84A2CULL, 0xC158F14BBA35DD1BULL, 0x93A9FA3E64C6D9E6ULL, 0x76253FF5BA8CCE4DULL, 
            0x9A5D9B7E7DAF1807ULL, 0xD2FD18298D749B34ULL, 0xD9E356197B4B0EB5ULL, 0x398D9AF515B3EAD0ULL
        },
        {
            0xD3AC5ECC2D7164EEULL, 0x17BDE4A7DB100664ULL, 0x00FB52BFF03F2AE6ULL, 0xBB405E7AE77FA9E3ULL, 
            0x7F9101429C947F34ULL, 0x5690E324DCE979A1ULL, 0x083815C792AB7A03ULL, 0x2CD67AD35188B576ULL, 
            0xC5AC00E25602E355ULL, 0x9BBE9A38BED2FCFCULL, 0xBBA6DF093D86DF7DULL, 0x9B2CF7369B259CEEULL, 
            0x1F6FC223ACFFA25FULL, 0x743E4FE00EA00284ULL, 0x01737A5956E74760ULL, 0x19F1B3AAB8BECDFDULL, 
            0x66FF7E121B36E896ULL, 0x1A59A13EFAE89E7AULL, 0xBB876CFE1DD4C6DCULL, 0x24DEAD82DED11C86ULL, 
            0x74C5ABD57FEAC007ULL, 0x246E243FF1FFDF79ULL, 0xC9D6B0E471D19AE8ULL, 0x826782140EC8000CULL, 
            0x8968CDE847DB0E97ULL, 0xB20A9060BFEAB598ULL, 0xC9357F162F9DF33BULL, 0x00ADFEBFB746F0D9ULL, 
            0xCF03B1A0868CBB39ULL, 0xA9D7A029A3F34DB9ULL, 0xBAA966E9DDF5C87AULL, 0x04A12005FA04D91BULL
        },
        {
            0xF9B26A74B2ACF551ULL, 0x2441157698D8973BULL, 0xF86F5B8CA2804974ULL, 0xE67926057BA745EFULL, 
            0x7D41B866F91848AFULL, 0x6930754F9D0F6405ULL, 0xA8EDD26014869A1EULL, 0xF11A1B2BDADFD3B8ULL, 
            0x45FADFC20575164CULL, 0x24B8DE8F24B3C237ULL, 0x3D0E514C3E40A6D0ULL, 0x0C04689E715EA95BULL, 
            0x9877F22DBEDB9B92ULL, 0xC0CA083D695C9A52ULL, 0xC879727D7B1E0B52ULL, 0xCE92643089C2BB9AULL, 
            0xFF47867C26A847FAULL, 0xD9A0B7B83957CC05ULL, 0x795B33697391449FULL, 0x115A7E913FC9871EULL, 
            0xF4E9EC4C252AED46ULL, 0xA13544B0E75BBC3CULL, 0x65B32E50064A57E4ULL, 0xFAA367E5A352E6E1ULL, 
            0xBDCA566F3E0F019BULL, 0x952FCA6E53163F89ULL, 0x0794D69B55C54CBCULL, 0x63DE705D77D4B6D2ULL, 
            0xF644272E84618737ULL, 0x7288A2B3EC75032AULL, 0xBABE5BDA239C3B9BULL, 0x5B905BED2804C6EEULL
        }
    },
    {
        {
            0x808B49A87165CA8EULL, 0xF02D4B55DDFBB5CAULL, 0x2A919727023D6FF3ULL, 0x7BBC98F12C983884ULL, 
            0x0C39CA67E84EE28CULL, 0x8155FFEAD65AB754ULL, 0x4ABBCC1EB89B463FULL, 0xC939C366823D17A7ULL, 
            0x7E84EA734F64D922ULL, 0xC7633FD5B57259F2ULL, 0x68BD1A8B3F5830E3ULL, 0x9FE3B9373EC38B5DULL, 
            0x320CE9367400389FULL, 0x99A17013EECF1074ULL, 0xD4EB7E565F4B6F27ULL, 0xC5F259B7FB3CCDCDULL, 
            0x28C830F0D45C38A2ULL, 0xD42B6062D9D036A5ULL, 0x7FF5AB43EB5883D7ULL, 0x599C02E3D256067FULL, 
            0x5C21AF1272595031ULL, 0x6472750BFDA894B5ULL, 0x7B074260D061DE11ULL, 0xAC660A6DEAE99AB0ULL, 
            0x49E6FC9D0448CB7BULL, 0xB3124810A90D1010ULL, 0x64E9B07A19F7C04FULL, 0x5DAC4226A1925F25ULL, 
            0xE2E0A8E05009DDA9ULL, 0x27BAB9773171E158ULL, 0x3DE60F93C169BE70ULL, 0xACDE5B3727FB3A83ULL
        },
        {
            0x7F3182C1C88B64B7ULL, 0xFFE8BFDBAB1C0D87ULL, 0x57191B8A54C077D2ULL, 0xF73D507787D9B502ULL, 
            0xEB903CC733AB8847ULL, 0x7DDC1C2128CCE086ULL, 0xAD4E40F843F31C7BULL, 0x3513808E02321EF1ULL, 
            0x52FE96C09656453BULL, 0xFE5EDC1C39EBB052ULL, 0x3E45ED7E1BB8AD9AULL, 0xFE0924FD9CFFC361ULL, 
            0xC3E1EBC4D49AFBABULL, 0x2D5749F61A04C193ULL, 0x90E442433EBB1D64ULL, 0x4AABFEB8D4A036BDULL, 
            0xDC798BBF46CB462CULL, 0xBF38DC195E32B0ECULL, 0xCE99934A13E0F1B5ULL, 0x8CFD90B041B3A108ULL, 
            0x0DFE1930D467ECDDULL, 0x2E5272720A0877A1ULL, 0x947629A1364EB5C6ULL, 0x628FBBAD10F9F65FULL, 
            0x0B67A94EAE8D8BC1ULL, 0x8AFA47631E0FC56BULL, 0x3958B7CFB17F740AULL, 0x1183FDFC763C02BEULL, 
            0x85D8DF309D1AAAB0ULL, 0x4F7E2BB979C62360ULL, 0xF9EE6939F4D34619ULL, 0x1D7A94A661FA0AC0ULL
        },
        {
            0x41D4DE08116C125EULL, 0x55C1CC49863BB667ULL, 0xCB9356CA138FA775ULL, 0x5CB37B3877A04F89ULL, 
            0x8798BAFE1D050EE7ULL, 0xB7AB2676795F5941ULL, 0x76C1496E644B730FULL, 0x4DE76E3A8D1DA7F9ULL, 
            0x1E8ECF5B3EFF9D72ULL, 0x95ED799A2BFEBAE4ULL, 0xF2FCDE044F283471ULL, 0xE8ABD1AB50B6F387ULL, 
            0x8408A7F3FA18757FULL, 0x8585837878FE70CEULL, 0x6D26091E4D573008ULL, 0x539F5045F770A817ULL, 
            0xF4E11401C9F7E376ULL, 0xB5BC73CA7E31EB2AULL, 0x4CF489DBACD6586DULL, 0x6DC20D7F5ACB9B06ULL, 
            0x024AF9266E72E48DULL, 0x79155A0DA3074CAFULL, 0xE61B15B95D9F65FAULL, 0x9862069215CBC572ULL, 
            0xE5F0B2D52E9F16F8ULL, 0x27D113137966CEACULL, 0xE6633E3D85D5BEAEULL, 0x63E578BB70CB07B0ULL, 
            0x286B9B3B7139798AULL, 0x4AE9A7B7E0C74614ULL, 0x6FEC26EF8DF64D62ULL, 0x1AE5B36CD744A12CULL
        },
        {
            0x06B9CEC2A735E3F3ULL, 0xEC5103FDD59D5F21ULL, 0x298B63EF5A5D6A4EULL, 0xC6A02E953154FD7DULL, 
            0x6D4DD072BA00ACFBULL, 0xB66B4F0F23E5989EULL, 0xBBD012B0F0E85DE4ULL, 0x618CB51B20B52ED5ULL, 
            0x56013635CB5378FFULL, 0xF5E8EB177ABB1262ULL, 0x79C186637F09E872ULL, 0xE30BD48483ADFC78ULL, 
            0x6E44EE7C78AC5CC6ULL, 0x937230049612A90FULL, 0x313DF7F938C54D75ULL, 0x712FEA3E63A23B05ULL, 
            0xB786BB4AAE16E685ULL, 0x3071812BC692A6B2ULL, 0xCB5ABDAC0EAFE8B5ULL, 0x6D8BE659A51DD0ECULL, 
            0xF6EFF18909DEB57CULL, 0x0685E28AB2954C19ULL, 0x997F12556EF1A0E0ULL, 0x2571917B0309FB2DULL, 
            0x14327722E25763B5ULL, 0x033D403874723997ULL, 0xFA7DC045AEB7641FULL, 0x40AAA14D13504E89ULL, 
            0x70FFB5D97E990059ULL, 0x95855B34AA9B2B5BULL, 0xFEBBABA641B258E8ULL, 0x63050BFF5FD4C680ULL
        },
        {
            0x78CD31D11EDAEAE3ULL, 0x548E8075A51C6FFDULL, 0x4A8A3A9BF0EB7F9CULL, 0xB4D36AF909F25B7AULL, 
            0x21158D543347542AULL, 0x17CF7B151EE77ECEULL, 0x2D0AA3A49BF206F8ULL, 0x7AD6BAA8EF6F44C9ULL, 
            0x7D15757C66245A73ULL, 0xEC631FF4F8CAC0D9ULL, 0x681C4BA516A6B9F7ULL, 0x1B7BD1FF3AF763F0ULL, 
            0xD1F146B5810D131FULL, 0x1A73F6D266850503ULL, 0xC28C8DB4F3F8176DULL, 0xDCD64DF3382B01CAULL, 
            0x4C59DE058663D57FULL, 0x96F3C3992844FB63ULL, 0x4CF838E34B01273EULL, 0x43694E94498EA2E6ULL, 
            0xE43387B23175167DULL, 0x536DF914E908AA97ULL, 0x71DECEAD9ECE2365ULL, 0x29F91ED8D4E0D874ULL, 
            0x9390BE462A9238F0ULL, 0x6A5A390B694ACFB4ULL, 0x536653C5B5D6F7D8ULL, 0x6D7F925E74F3C273ULL, 
            0x54C5927251FC163BULL, 0x93563D79FB924D41ULL, 0x46055AEF22797C98ULL, 0x7FA608E138660486ULL
        },
        {
            0xA342F1851CA31CA8ULL, 0xA78D237474727DF0ULL, 0xF91CAA5D3A64F46FULL, 0xE7BDA29CA6FC32CBULL, 
            0xDBE099069E5DB859ULL, 0xC90C2673C295D44EULL, 0x536EBF6965379965ULL, 0x86AB23F7B2EE98BCULL, 
            0xC924C05116A19CE6ULL, 0x9BA8D14DED1974DCULL, 0x9D5F032D4446ABECULL, 0x23DF4F84060DB391ULL, 
            0x7E745E2896D7831EULL, 0x37486668F3C097DBULL, 0x561E340AF50A15B5ULL, 0x6ACD5858DD8769CFULL, 
            0xC6FFE514C78BF128ULL, 0x77361AF5C9A13C57ULL, 0xF4D09B39B013A1B6ULL, 0x95FCF5281DD7D492ULL, 
            0x0A8D91B200864832ULL, 0x94A5DE664CA414A9ULL, 0xA6B45806C3334B6FULL, 0x146516B9EF2E1DD4ULL, 
            0x3D8D8F5798A7F315ULL, 0xB231DDD5E811B979ULL, 0x010EE87FD99A7548ULL, 0xB308A170EED5A745ULL, 
            0x3A425B613E03DB5AULL, 0x1E12DA7D7CF5071DULL, 0x66BC3B01BAABA03BULL, 0xD579414D2F1FEBC6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseCConstants = {
    0x9018A7C4434100C7ULL,
    0x4C1BA129257C5472ULL,
    0x516B70D77208F6ACULL,
    0x9018A7C4434100C7ULL,
    0x4C1BA129257C5472ULL,
    0x516B70D77208F6ACULL,
    0xD350E851BA008579ULL,
    0xD34070DEA0901DD6ULL,
    0xF3,
    0x7B,
    0x15,
    0xC8,
    0xD7,
    0x9A,
    0xCA,
    0xBA
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseDSalts = {
    {
        {
            0x495FAD245BB78F80ULL, 0x5D5DE812012B11EBULL, 0x338C6864DACC04DAULL, 0xB3904FE104D466D7ULL, 
            0xB9E53481C8A7A1B7ULL, 0x93588461C44A4CF9ULL, 0xD9FD66E9A1ABE922ULL, 0x191593CF667DAE84ULL, 
            0x5BE4B216E7F78369ULL, 0x683C23204D9BBCB4ULL, 0x45F8BECEF6DD9CAAULL, 0xA8B6BFA00D40705DULL, 
            0xE4589F77C0568968ULL, 0x6923F600F1488FADULL, 0x30B4FD3767B37E45ULL, 0x3E3AEBBE4B955B56ULL, 
            0x5DB47B1662FE34F2ULL, 0x14BB99882C02CCA8ULL, 0xDE3F591B7BB4177FULL, 0xCFB70AEBEF088348ULL, 
            0xFDC404243BE20AEAULL, 0xB4BF7EEE405D0E9BULL, 0x26B5A4E4B35ADDA0ULL, 0xF86DD8A1064F28DDULL, 
            0x2BFBAAF3D231F01BULL, 0x3ADF87192A533418ULL, 0xBAB89D87C503E479ULL, 0x4FDAAF82CF29E2E2ULL, 
            0x9AA3A4B1BA94A137ULL, 0xAAD01F4BCB0AFA85ULL, 0x50515FD14C9C755EULL, 0x7AEE19E0EA342D79ULL
        },
        {
            0x4F91E062F06B9EA1ULL, 0x7D9E3F9DD7B71ACDULL, 0x7EFDC40AF6F5B507ULL, 0x37B19C83926BFF32ULL, 
            0x693F3BF4964E4BE6ULL, 0x9585FB9570C40175ULL, 0xCC40E0501ECD10DCULL, 0x3962EACCE650A477ULL, 
            0xA181B4A037BA3844ULL, 0x648461547E966CFDULL, 0xA21B511BD689EA16ULL, 0xED35CC5C11AAFE15ULL, 
            0x69FF682E69351EBAULL, 0xB9775E93964FFC3CULL, 0xECEA0B78233EB821ULL, 0xA4FB751DAA05D8F8ULL, 
            0x088D2FEBAB012207ULL, 0x6C5E9BD1C5612F3BULL, 0x597F9474459C70B8ULL, 0x99A43F00D0C783ABULL, 
            0xC1CDBEF314B39488ULL, 0x53B71DB4A04444FDULL, 0xA8E5DC949112827BULL, 0x70FAE66CECECFB67ULL, 
            0x7D5CE044C9DE6C18ULL, 0x92172B2C24FF4417ULL, 0xCDBFA03DDBE449C4ULL, 0x991DC42E1B8C1961ULL, 
            0x8864CF91ACE93660ULL, 0xB578A8ABEFCE6603ULL, 0x17F77EE89A75BF8CULL, 0x0D100D4A04813C34ULL
        },
        {
            0xE7647DB09F9809BEULL, 0x7E8D1D633F07A8DCULL, 0xFD59C317858D7CCBULL, 0xF6667652F36A6AA5ULL, 
            0xA0EA07B50FF3FC70ULL, 0xE212CA9D198713C8ULL, 0x1A7063FE8FAB1EF6ULL, 0x7EC99094ACEBA70EULL, 
            0xAD441611C68A00EAULL, 0xA526B6ABE60B0EFCULL, 0xCE521093168EB424ULL, 0x35C393AFAAE2125DULL, 
            0xC4C3BFA3EA32DA04ULL, 0x773499A326860DF1ULL, 0xE87C131863B0949BULL, 0xA7BD5F6505A66832ULL, 
            0x8C587EBBB64A55ECULL, 0xA186BE1DE38FA530ULL, 0xC7CB724A74747D8DULL, 0xB2B330E073EDC46CULL, 
            0x7BC10A5049EEA2A1ULL, 0x60B6269A8DEE6457ULL, 0xD67B34E6F3AAAF35ULL, 0xFEB08C7163DA9466ULL, 
            0xD2AA94312E060EC7ULL, 0x776D05D9B3F07828ULL, 0x7EDDF3F16DB7FF4FULL, 0x0BE8A4A72F9607F5ULL, 
            0x25EBF4607FB05579ULL, 0x06369F4D2C176266ULL, 0x760B07FE5BEDB94DULL, 0x5885A3DF9ED7FD87ULL
        },
        {
            0x4961BD99F42BC45BULL, 0x83B28045526FFE2EULL, 0x268C69FA782FDEF1ULL, 0x6FB53583F7923351ULL, 
            0xAAC5800F75F2DB82ULL, 0xF5DDA31B5E1BBCDAULL, 0x5C3B4CC8CD681CE2ULL, 0x25A14194BABC04BBULL, 
            0xC76A59FDAE263ABDULL, 0xA25AF73F140D9DC0ULL, 0x96D085DDDAA0CF3AULL, 0xB91B816F31B67840ULL, 
            0x79423D8F50F9C2F4ULL, 0xEEF18ACA26F02C2EULL, 0x3CFEE1C2B5BA202BULL, 0x0F2D2FF7DFAF8047ULL, 
            0xC40220F19F671093ULL, 0x5B0808601BEFDDE8ULL, 0xB2BBA3C5BCA269ECULL, 0xAF58F1C54808ADE8ULL, 
            0x63C956A98C5075F8ULL, 0x70378D4722DBB12FULL, 0xC7B385415B9DB756ULL, 0x8FBB3C98C7CAB6C7ULL, 
            0x4058DBDAC9026A73ULL, 0x25D3E17B6E4B8975ULL, 0x76DB76D831026C22ULL, 0xC84266959309942AULL, 
            0x9C82769ABD1F36BAULL, 0x9F5D15C3F585D200ULL, 0xD346553B074F8E90ULL, 0xC5EF33F8CB9F986DULL
        },
        {
            0x6654763F5A731777ULL, 0x75F85790CE89B232ULL, 0xFB6AE894D53F3E67ULL, 0x74DC1236FEF5C0A0ULL, 
            0x6412BD81B9502DD8ULL, 0xA4E79D9A62A2D9A2ULL, 0x5028E662A0D1E99BULL, 0x4238ABE6B126666AULL, 
            0xA60954F5E709902FULL, 0xEA6CE12AF24F8972ULL, 0x9F4F5FE770C4CBFAULL, 0x1E84D749607BC000ULL, 
            0x0B370CE026E2A8A8ULL, 0x3B129CD774887F0BULL, 0x6C5F6C594DF1A432ULL, 0x94934C17A8F38DBAULL, 
            0x818ADC3A02D043C9ULL, 0xFA89209F755EA9E9ULL, 0x090925203B4C36D9ULL, 0x036BBC536F4EF183ULL, 
            0xB515122E1A33AF59ULL, 0x34FC4BD308955C7CULL, 0x46B81A73715659B2ULL, 0x1A574E55C2D8B47AULL, 
            0x0DF88FF73187D67DULL, 0xFFA6F762FBCB5498ULL, 0xFB120975106F87E8ULL, 0x4D1F9451783E12C2ULL, 
            0x83EE7B91DEA84AB1ULL, 0x7F3E1C9742A84CEAULL, 0x85E01C0D770632E2ULL, 0x0E2E56E33ECEFA90ULL
        },
        {
            0x56042818DE2248FAULL, 0x421639AA7FAD8662ULL, 0x7B6A47610FF4871AULL, 0xAA830B12C63E8656ULL, 
            0xD9E10CC8D32CC729ULL, 0x7AE3709D259D8525ULL, 0x26AE16954330F9C3ULL, 0x49F19AF27E990083ULL, 
            0xF12A9FE78EB4BF1FULL, 0xBB07376D27111060ULL, 0x9C22ED0BC6C5EBFAULL, 0xAE1FFC81B59BCC0AULL, 
            0x6BC703C077CB840DULL, 0x3747A5FAF5A650E8ULL, 0x8953B4397CCE09F9ULL, 0x227A882DA6E2B70AULL, 
            0x606B1E96736E6769ULL, 0xACB61BA97EEDB5CDULL, 0x8ED5D97DC354F370ULL, 0xB8E214A567E069ABULL, 
            0x91F16EB5442B16CBULL, 0x662B296B8B2E660DULL, 0x85B0C951A683B28BULL, 0xBBCE548C175A8F23ULL, 
            0xFFFED6F12F7BA98FULL, 0x70EC91A9C4254044ULL, 0x330730AC7E1DCFD2ULL, 0x434ECE26890166E8ULL, 
            0x51057C5F5F77CB57ULL, 0xCAD7F254E9C05A75ULL, 0x1764BCF035BF433EULL, 0xA93F71D5C760C9C6ULL
        }
    },
    {
        {
            0x2087D7C5588B98AFULL, 0x18045FA154279B5AULL, 0xD629975DF53DE19BULL, 0x1705B1DC7818A551ULL, 
            0x2BC14C721D16E228ULL, 0x3CA13A87FBA1F93EULL, 0xAFBB77BC97533346ULL, 0x6A76D0347D22A3A4ULL, 
            0xDB87923B78A0CEAFULL, 0xCCC227ADFEC1D759ULL, 0x2D0AEA71AEF30645ULL, 0x0C143F4FFD159713ULL, 
            0x4E0B9A5EE2C7B044ULL, 0x044FA2511695E532ULL, 0x7D90A48D2F6DF50AULL, 0xA3786EF98C286BE2ULL, 
            0x9EDEEA3FB3E09827ULL, 0x78C8535ED72959D3ULL, 0x51C4A6232DDCD45CULL, 0x7C4B63760308693FULL, 
            0x83743D5D5D5F5089ULL, 0x02354B55E75CC886ULL, 0xED973946239CA682ULL, 0x2855D7B7B1C67F30ULL, 
            0xFD5792931193BE36ULL, 0x622ED08B45E82882ULL, 0x53C2F938B74495F1ULL, 0x950C6A2A045C2DE2ULL, 
            0xFEC47358A4AFAAEBULL, 0x2E060AC4D510081FULL, 0x664380A7D9E003E8ULL, 0xF26FE7F3362E6C85ULL
        },
        {
            0xB3BDB470FB6E633EULL, 0x07D5E9B4EA1BEBB5ULL, 0x79B17290EE1584F0ULL, 0x1FD08664E933B686ULL, 
            0x7F7A9199CCCED4FAULL, 0x87C22195DD09DDBFULL, 0x4F4C8D9B2AEFE85AULL, 0x1C5CC82700FE3D6FULL, 
            0xAD4083EF08A27A26ULL, 0x4E8FC4E2201F65E3ULL, 0xE4B96D588B0CB976ULL, 0xF38C558105E8FB9AULL, 
            0x6DFD3DB3CB0508C4ULL, 0x45189770A337E072ULL, 0x974810D0D1A0C87FULL, 0x4EB0A71A96860A4EULL, 
            0x490939D75333D94BULL, 0x3987A6B75A47CCD8ULL, 0x8D43B7DDD8F449B9ULL, 0x72D0704000FA052CULL, 
            0xC7DE0F81CA1B3CC4ULL, 0x7411D30B7DA159B2ULL, 0x739C3A802C88AF23ULL, 0xE4C162F4D8F41C5CULL, 
            0x9E18BB63EAB95B35ULL, 0x7095EA31175C46D5ULL, 0x44B1A307D1F8E837ULL, 0xA538DC720C9B0E94ULL, 
            0x4C6AAC0E80DEBD22ULL, 0xDE51E819F9077ED1ULL, 0xE413D16F5316D3CBULL, 0xA682D451D3744204ULL
        },
        {
            0x662CBFC1C0A00987ULL, 0x827CAFDCA7891AC7ULL, 0x7B0614C9EA74A3E8ULL, 0xD3CFA33900D4E257ULL, 
            0x8585EE33C61CFB7CULL, 0x2C84648C24F31592ULL, 0x64C907B4AB3396F0ULL, 0xEF513BDFA7FDB754ULL, 
            0xBDB4BE39C21D9B85ULL, 0x6FF9D01DA1FF0ACCULL, 0x7373B8DFE43EC6D4ULL, 0xFF7877C55C55F0ADULL, 
            0x251B797F0E5F7EFFULL, 0xF4B5D85D1206CFC9ULL, 0x90B068CD36BEF74EULL, 0x7F8DBE082CB03FE0ULL, 
            0xF87185C714083DE9ULL, 0x2C1B56287A57CCB9ULL, 0xB43F853F8B61F7D7ULL, 0xC3FBEC6E2BEFF692ULL, 
            0x0983411876A8D324ULL, 0xB9F764B82E4C1B04ULL, 0x5632BAB0649C7FEAULL, 0x457326E518061D50ULL, 
            0xAE8466F02D9E12EFULL, 0xF78434EEA6ADA5DBULL, 0xE6F11A9CB9995A66ULL, 0xAA579EA18E4E672BULL, 
            0xC614055592BDCA6FULL, 0x793C6EA3863138D9ULL, 0xB648E72332251209ULL, 0x4E657D2E35028FF9ULL
        },
        {
            0x6821EECB3A888DE3ULL, 0x4678F2E78D36F31BULL, 0x9BB06A4467195A10ULL, 0x44B8D83A40C20AA8ULL, 
            0xC560ADBEDE8330CAULL, 0x4FCAFAC53EE6C0D7ULL, 0x2A29CAD1E4D583FAULL, 0x02A86028A7466978ULL, 
            0xCE56976A6E4F4CEDULL, 0xE93B059934EA9382ULL, 0x917559AFE3EFBA9BULL, 0xA912818A3D73086EULL, 
            0x1E7BA41F2B608897ULL, 0xBCBDD3D25D26A865ULL, 0xD0575F313B426501ULL, 0x55E2FD34339A4217ULL, 
            0xC130E973CDACCBFCULL, 0xBBA98EDFAAD9B91EULL, 0x629D0CC267B810C8ULL, 0x69BE0E03888EEE9DULL, 
            0x2C75DD45E1CD012FULL, 0x4BAD4EDB63CD68F5ULL, 0x0FF87F72E60D6AD4ULL, 0xEBC562712F0C706BULL, 
            0x04F2EAEE667B71B8ULL, 0xF1169C560C9097ECULL, 0x26B1D4519DA681A3ULL, 0x2F3A6E0DF0168774ULL, 
            0x8E69F39725094E4FULL, 0xF58EE8902EDC9B7DULL, 0x0BF1C3404DDB8EC9ULL, 0xA1C2515E25F486BFULL
        },
        {
            0x9273960F52991491ULL, 0x07FD53B412B0C918ULL, 0xB116A0B36096D2B8ULL, 0x9CDD0AB5EB41A8D7ULL, 
            0x0B9EA742D89BB8FFULL, 0x33449A218DDDB2DBULL, 0x6F36224C20CCF129ULL, 0x2BBE5F1CED5416CEULL, 
            0x581963A66E42AB9DULL, 0x39645CFA481FAB7AULL, 0xE817ADCC33BF7176ULL, 0x52FC16B901A9D2E3ULL, 
            0x2E4EAC8814ADEE98ULL, 0x0C40B0F4B1FEBA23ULL, 0xA5E00792E655616AULL, 0xBCBBF5BB2165F421ULL, 
            0x4AF6F694F0D1887FULL, 0x2ABFA08B77094120ULL, 0xACE6EF5B1FB7FDE5ULL, 0x503671E8A90CF33DULL, 
            0x316096858DFDD1C0ULL, 0xD2D29023353BA4CFULL, 0x6D76797A642A2360ULL, 0xED90BE4BD7E9F959ULL, 
            0x1CC1175B2818BB80ULL, 0xC57B519523139ACFULL, 0x7B6AA294684E9315ULL, 0x0279659E772D6DCDULL, 
            0x0D53D3D1EE1FE925ULL, 0x7A8CC3E7B8DEBB04ULL, 0x4922EAA6673DEF5AULL, 0x5EEE88053F40BB59ULL
        },
        {
            0x8EC8A66D61A15603ULL, 0x192B8A2E0ACD661FULL, 0x9EC18E79BD3DC158ULL, 0xD2865BED3E66DB38ULL, 
            0x48C95F629522A743ULL, 0xEE9E54F5B9921308ULL, 0x667C67059BD83D0DULL, 0xCDA45B12FD57D906ULL, 
            0x25FA5EA16B226E5CULL, 0x3AE63C7AFFAF2F65ULL, 0xF3E241EC9564EF6EULL, 0x8C0527679F6EA2C2ULL, 
            0x6FC00575635A45C5ULL, 0x7984F20F146DB1DBULL, 0x09C005E386AAC498ULL, 0x3DA80450FD1DAA32ULL, 
            0x5BC4FE6FDCC070F2ULL, 0x163020D9C5E98F1DULL, 0x2D0244A9152D7C3FULL, 0x4A0201691C7DBEDFULL, 
            0x0A5B2B3F2B652CB1ULL, 0x0309A9575C7E3F69ULL, 0xEAD9AF71870C5271ULL, 0xA897E59CF78BFC17ULL, 
            0xEEDF4CB62E8CAE65ULL, 0xA060072F7941D3C5ULL, 0x56416CA6D7177141ULL, 0x8E2778BB9A4C3CA8ULL, 
            0xCD4441321BE9BCF9ULL, 0xE0D2226C98002FE9ULL, 0x2E9F01BA0335C15CULL, 0x680C40D7399E6349ULL
        }
    },
    {
        {
            0x2CA3E6712153AC43ULL, 0x4386A057A24A10BBULL, 0xED24ADBC394532DEULL, 0x51CE1B731942A72AULL, 
            0xCFF48455C69ACE16ULL, 0x28FE0E0CA8BED5BFULL, 0xD77DA0EE9C3F15B2ULL, 0x2A58B517D8A3EBB5ULL, 
            0x53AB256C7C6239DBULL, 0x165B6EDA976BEFD5ULL, 0x288741B96B1F1F13ULL, 0x801FB458275810B2ULL, 
            0x030DAF4379993321ULL, 0x6BE57EF579C6979AULL, 0x02FFC863E8814813ULL, 0x1BD8738323F92CA7ULL, 
            0x785B48C3F81A8AF2ULL, 0x038D4370C266A64CULL, 0x404603E47842F164ULL, 0xFA622CF294C7F8C8ULL, 
            0xEB702C8174093373ULL, 0xDB520D38D5DA4704ULL, 0x02EED967AB5F2750ULL, 0x2F35E5F0EEC1CC39ULL, 
            0x469CF18E73D49F86ULL, 0x96BFC58A7185D334ULL, 0xB16ADCFDED31F7D5ULL, 0x6E9000D61294CC74ULL, 
            0x4079CF81F9CE9C76ULL, 0x0931F214A22049D0ULL, 0x97631F97324DB9E3ULL, 0x20C7A5FB210E4997ULL
        },
        {
            0x1D7491DF0B3B96F7ULL, 0x5E0A22B237A699CBULL, 0xC490F229CC111F78ULL, 0xB12A6B21ED54F2A5ULL, 
            0xF537DB9098E6888FULL, 0xCEFB647BE3C094B6ULL, 0x697BED082BF16E74ULL, 0x1B69F151765EEE7DULL, 
            0xA2105490B2E435DDULL, 0x0B338C5C2E9F1C3FULL, 0xC35B3A697D1B6CB3ULL, 0x079400F2A59FB787ULL, 
            0xEEC080418CDD4CFFULL, 0xE6A6DC053EADC83DULL, 0xB825FA3CBC06E454ULL, 0xF63FD5C8B215B35BULL, 
            0xD9AF7D4466629E28ULL, 0xF1F18F84044A7471ULL, 0x5FF3E19EFF246CF6ULL, 0xBEC8C9ABFCB80B96ULL, 
            0xCEAE49C0405408F2ULL, 0x06AD939891DFBF0AULL, 0x098511E4F948ECC4ULL, 0x2E8E4B24D1D3C61AULL, 
            0xAE041B19B3710589ULL, 0xCE65F9C3F43B160FULL, 0x8977E83E6D8A8380ULL, 0xBE2DEC52A77A25B4ULL, 
            0xF583B014F7A2CCF1ULL, 0x9A5ED438E0E327A2ULL, 0xF0D11F9AC69725B5ULL, 0xF8A3CEF3D494CDBEULL
        },
        {
            0xB942CC39D5F71840ULL, 0x730A8AE417C69B8AULL, 0x1030EE8F9A9C5A50ULL, 0x9531BD71E0E6D2D2ULL, 
            0x6E5263CFF0868162ULL, 0x262342998CB0DF10ULL, 0x6DBDD5AEEEEE9882ULL, 0x195C1D02DE5507D1ULL, 
            0xF24D23B961111EECULL, 0x96ACEA3E3C15C7F0ULL, 0xA2FFCAB19783D176ULL, 0xBEC32E407C0B8197ULL, 
            0xC9021262A671D763ULL, 0xC2C99153C4AC902CULL, 0x6301BAFFA08B5446ULL, 0x417B5F4966B1BA8DULL, 
            0xAB512800ECD19120ULL, 0x14A545D0CDD1EBD8ULL, 0x3BC958BCB5523DAFULL, 0xB5D8656D2B4E0B4BULL, 
            0x9C75E05D547E4BD7ULL, 0x4A62A64A0C180F1BULL, 0x518DD3DC55E4FEC4ULL, 0xD8D7294B3ED3E13CULL, 
            0x081B583459C8A59EULL, 0xE88C31DFAE57EE2FULL, 0x8D3854155B32D793ULL, 0xF5F1DBF7B37ECD84ULL, 
            0x32B3E5B7D5F770FFULL, 0x7C8706B2C3380FF1ULL, 0x00AD9EBAB7673E78ULL, 0x5DFCB87C6369D62FULL
        },
        {
            0x4406E4ADC7422C26ULL, 0x47AC085A4E5FE36AULL, 0xF0FC86D91FB62A95ULL, 0xD705BB348E69E35BULL, 
            0x73FCFE43C41A4B9CULL, 0x96A479C35C1022A2ULL, 0x5192477EC6DD5D41ULL, 0x93F228D785697E61ULL, 
            0x513150498F2DD45FULL, 0x9DFFED6E4CF5CD11ULL, 0xC60410F99E0A263CULL, 0xA42C01E0F1F1C5F1ULL, 
            0xD12B990F9C84837AULL, 0x8F8BE3C7C363545EULL, 0x49C9876A72D4CB72ULL, 0x793CA4B9E2AF012EULL, 
            0x1A574CDDAE4390D4ULL, 0xC2F9B45B9AC94062ULL, 0xDCE503070EB50223ULL, 0xF53C1B34A02D3E73ULL, 
            0x9C875299932376D1ULL, 0x1F398C52143B66C7ULL, 0xB174AE6AEFC7E4ECULL, 0x680AC8FFB19DFD3BULL, 
            0xB1EF3F90A8F5D79FULL, 0x4461C34DBAE26C22ULL, 0x8675EFCE059507F2ULL, 0xC990B59CECEF561EULL, 
            0x7CD8687EA1DD21A9ULL, 0x483D666959C24B77ULL, 0xE9C0D99AA4233104ULL, 0xB408D338A0C52F33ULL
        },
        {
            0x9C0EA9F9F62E8D63ULL, 0x3399E0A161E9BA5BULL, 0x8061E307432200E3ULL, 0xAA8D10DEAF18B95FULL, 
            0x8A725792DEF06A27ULL, 0x811BCFE9F6344375ULL, 0x087F63027FAF5FD0ULL, 0xC093244A3A972CFFULL, 
            0x76C743053557F74EULL, 0xE2BD0DCF2AF4D118ULL, 0x3B655FB6C3605111ULL, 0xE081BF6FDF77AB42ULL, 
            0x92BAE76368F25079ULL, 0xFFDD232563599C76ULL, 0xA345F028C5CD83AEULL, 0x2E0BC3A8426D8ADBULL, 
            0xF156D83080E8C0C9ULL, 0xC3B754CF6076DB3AULL, 0x3F68C0CB7F659F22ULL, 0xB99EBC8EBFC28D3DULL, 
            0x633F87639A8C1940ULL, 0xEA8CDCCB7294A38AULL, 0xD48FD649E197A29FULL, 0x2A725CE2B47B1D7FULL, 
            0xB716D885A5606800ULL, 0xD8726FBB50F28F95ULL, 0x882B78522BA9D795ULL, 0xB4BCC8BD46C38767ULL, 
            0x97C6AC4651620A7DULL, 0x39DE0E1509249938ULL, 0x0987963D0219C8A0ULL, 0xCA797854611F7904ULL
        },
        {
            0x92E4786203B51CF5ULL, 0x6E29E92656B70E2FULL, 0x6C86D702BD852295ULL, 0x007D972E28C342E1ULL, 
            0x6A2BEEEB0E9E4F45ULL, 0x07E8E942601665B0ULL, 0xFFCBE67E60E806ABULL, 0xC8E4827524297716ULL, 
            0xFA4F8E4CEC0A36C3ULL, 0xFFA969F99A8383D2ULL, 0x5BFAECCA77FEACC4ULL, 0xC7497A0C5084E6B1ULL, 
            0xF8F12B3EC1C655EEULL, 0xBAC5AF58753DDF5CULL, 0xFD365250207BA103ULL, 0x4D42D3C53B5FC5C3ULL, 
            0x04E43DFD2E7A0F0BULL, 0xB81EAB53704A5774ULL, 0xC3CF942FE620714BULL, 0xB8A2FB7FE8295F10ULL, 
            0x929102335F18CBC1ULL, 0xD2584A70C77962C1ULL, 0x087B9935545FEA98ULL, 0x3D27D4E0348D8706ULL, 
            0xE12F2930094C782BULL, 0xFFD7A4DFA9F79521ULL, 0x22C530C703DB327EULL, 0x45AE3D989476AE61ULL, 
            0xBB060B001B7136DEULL, 0xA86D7400A5187FFAULL, 0x8D3823408B6DA583ULL, 0x513B99DA90B2A171ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseDConstants = {
    0x7ABB09AAE91DD1D7ULL,
    0x924221CD040CE4E4ULL,
    0x7E7424A5B4C79A91ULL,
    0x7ABB09AAE91DD1D7ULL,
    0x924221CD040CE4E4ULL,
    0x7E7424A5B4C79A91ULL,
    0xFC205E5A2101B854ULL,
    0xC4054662C59232E1ULL,
    0xCB,
    0xCB,
    0x1F,
    0x50,
    0x84,
    0xBD,
    0xA0,
    0x6D
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseESalts = {
    {
        {
            0xDBE8C9A1AD51DFF9ULL, 0x2693FAB6F25BB8E0ULL, 0xCFDD1CC6ED408239ULL, 0x06CBC35F933C0009ULL, 
            0xDFC76F4C601A7FF9ULL, 0x44098BBC2917384AULL, 0xBF6A79783B3A5681ULL, 0x293D6067AFB5987CULL, 
            0x86A8603A3E88996AULL, 0x58C2128892E2015FULL, 0x37FDC428C84698D7ULL, 0x7A4B742EE9D63E79ULL, 
            0x97F866538ED2ED69ULL, 0x8DD9D3E5F9BF2253ULL, 0xA42F501E96FFBADBULL, 0x0E6307FEE5A47559ULL, 
            0x3CDFA362A73D539BULL, 0xD530EE095C9A6D92ULL, 0x06BDA82E449FBC28ULL, 0xE03C731F9303420AULL, 
            0x24A5A10D5E58E70DULL, 0x5CDA0D4C0DD0E94BULL, 0xC9DA943A611C174CULL, 0x47CA9116C5F6F9B5ULL, 
            0x54A507571557F49CULL, 0x028CD3296AE126A0ULL, 0xE429BF6623608608ULL, 0x71AD46D52FAA7CA4ULL, 
            0xBE5F0AACD84F85EDULL, 0x8C6C42A8F708119AULL, 0xB17466EA989568E6ULL, 0xF77290AF2C71F538ULL
        },
        {
            0x180220B4B1EEC55FULL, 0x2797133F238E13B2ULL, 0xA0852B00A8B01C06ULL, 0x45DBE2445AD21830ULL, 
            0xABE3E0F58A0900F7ULL, 0x434BD471B542C763ULL, 0xDCE69049CBF34422ULL, 0x501D774263851968ULL, 
            0xA6362B70A65299C1ULL, 0xB9042490FFFA0528ULL, 0xD6924DB1732F64C4ULL, 0x5DAC582D46AC038DULL, 
            0x575A2D2B86B2108BULL, 0x8E0C681256E7C4ECULL, 0x0FAF4733D0E4C0CFULL, 0xA60FC62913796CACULL, 
            0x41C6F7244813F99DULL, 0xBB4D3AFD2E3BB745ULL, 0x7C7513B09EB0867AULL, 0xAE3E43F604A8DA57ULL, 
            0x0022BE1DE6C0F937ULL, 0x442B202ECBE7EE41ULL, 0xA1312F68DC53C5EBULL, 0x33AD107A9872F40AULL, 
            0x6CDFDB832C30645DULL, 0x12148BC8825D2675ULL, 0xA0F69E8C5CA16E81ULL, 0xF31FE128AACAEE33ULL, 
            0x3786798580F52DB2ULL, 0xF67D612814054919ULL, 0xFC7327E1A5E33B0DULL, 0x3B2DCBCE532A0F65ULL
        },
        {
            0x604A54D17D5438EBULL, 0x763A5B68C0428ACEULL, 0x41FE702F7252B177ULL, 0x3F5F6E47A9DC1803ULL, 
            0x3B8E3573291E3FE9ULL, 0x190E93EC126CC758ULL, 0x3997322F2FEFFB8FULL, 0x452F909990ED42E5ULL, 
            0xB2FC475E21530DFCULL, 0x51CEE41188A50426ULL, 0x87C2C90DC3E0ADDAULL, 0x05DD1D295516E222ULL, 
            0x21206BABCC996547ULL, 0xBBE7F1706A9C421CULL, 0x3EB30CFD3329F690ULL, 0xE8EA35CA068066BFULL, 
            0x9A31A4393321D6DEULL, 0x09F643B9F1ECF5F9ULL, 0xF9C2E491AA4040E9ULL, 0xFC37181D705C1230ULL, 
            0x737287647A708297ULL, 0xCEC612B43762290FULL, 0xF4CFD49E9B45DE39ULL, 0x371BFA5014ACE168ULL, 
            0xB0180A869D1A2654ULL, 0x63B77DD69368D222ULL, 0xBD9072774D8BC5FCULL, 0x7DC96B312CB2052BULL, 
            0x2969A706DE892364ULL, 0x5751D7EDB7891B24ULL, 0x358D0B005FDEBD4BULL, 0x72CDE733E4E2B9B3ULL
        },
        {
            0xF54071DF9CE6E06CULL, 0x55A92584A14B1211ULL, 0x337679BFD2FD88BCULL, 0x38139765FC22644BULL, 
            0xDFD42518BB4C1994ULL, 0xD3D8C5C1F70B2F67ULL, 0x371301D13F66A04EULL, 0xE4708562B2731F11ULL, 
            0x978F3BFA736C0991ULL, 0x72534C113AB4F571ULL, 0xA6CA831B12A80950ULL, 0xCDB78A7A32EC987FULL, 
            0xBDA14A7E7CB6B18CULL, 0x109B054A42DD0C51ULL, 0xE0FC368EFD0E38CEULL, 0xA24B7967EBFA86BCULL, 
            0xF70B186E29006172ULL, 0x999B2C84FA0F060CULL, 0x690AAA5E2D08832BULL, 0x23F8BAD7F1DFD9A4ULL, 
            0x6BE71D7DEFF3F5CDULL, 0xB05A73AC6E8810EFULL, 0xBD900514C4CD0FDCULL, 0x57595B18B9A25881ULL, 
            0xDEE0A824C5A88E0DULL, 0x22F48B10898859DFULL, 0xBC852254473DD353ULL, 0x78B161BC064F1B84ULL, 
            0x5915528212A9CBBDULL, 0xCE5A64D9975E3372ULL, 0x3BFABF463D0A0CC2ULL, 0x991ACFF74E7B922AULL
        },
        {
            0xBA9906CC46E072DFULL, 0xE77F1AF4FDED4177ULL, 0x29E5535E593843C5ULL, 0xE17F8CBD7DA2BE97ULL, 
            0x2E6A744DFB0DDC2EULL, 0xD2C9AB9037C27946ULL, 0xBAE7A0E517954BF1ULL, 0xF39175F862098CBFULL, 
            0x8E93AC281CE4DD75ULL, 0x693B63C9DBCF243DULL, 0x30A19D541937205FULL, 0x3656C0F1C425B782ULL, 
            0x6E99FE03145238A2ULL, 0xD10890C5D8FF2B2DULL, 0x6860EAC9DEC381E0ULL, 0x1A231E5952D98755ULL, 
            0xE64300A6CDC09340ULL, 0x623A9AA9D5E3B7D7ULL, 0x922B77B26D34165AULL, 0x50FB7CB8F09DDD80ULL, 
            0x2D5156E98C2CA8F7ULL, 0x55ABA655B4F7AB3AULL, 0x2F2E7D50EEC20C7CULL, 0xA0A89E9341359CB5ULL, 
            0x67C576D7747858F8ULL, 0x9D030DF445E5F825ULL, 0x3DFE30793E7D261FULL, 0xB91C96EAD4C009C1ULL, 
            0x04F9A40E1DFD1736ULL, 0xA0B0F0C20B0796F5ULL, 0x1D12E4F8F201A8E9ULL, 0x0308347BE51A596FULL
        },
        {
            0xD858F99C01F91989ULL, 0x7A068FE81708BD45ULL, 0xCD00E1C7CF72210AULL, 0x915B28B12AEE1DB0ULL, 
            0xC608D9EA543743B2ULL, 0x31D0C189DA562D3CULL, 0x75BB8446CF23243DULL, 0x2E3DB62C4A9DEFC4ULL, 
            0x3C6BD5516E21DA4FULL, 0x3A8D0CC8767858A0ULL, 0x4326B72F756520B9ULL, 0xDA74CDE5035D0EE0ULL, 
            0x06BB1010C72D4EE0ULL, 0xFDC83A808A59DA74ULL, 0x40E70FBD15C39F6AULL, 0x0595976105ADA061ULL, 
            0x25C2B5CAC501C5B3ULL, 0x6A2C910B2116E1F1ULL, 0x1BC840986CE2E7E1ULL, 0x7975181B01905BE9ULL, 
            0xA30CE0D16B5621D8ULL, 0xEC5DB4E7A44F1CB7ULL, 0x3328019564D72E3CULL, 0x6B7AD215D4798CDDULL, 
            0x9CBED763377AB769ULL, 0x9E98A47B4CD49E5BULL, 0x52D49C6412F9B707ULL, 0xDF9CF89D9DBFF06FULL, 
            0x9005D3AC26BA8F7DULL, 0x9035316605A86F36ULL, 0xC7C9D47A474663B4ULL, 0xB7D207164A6C5CB8ULL
        }
    },
    {
        {
            0xBEE824E8C868A971ULL, 0xA50C463855202884ULL, 0xCF20B636798D93A8ULL, 0xB678391E58F07306ULL, 
            0x650D361580FC9096ULL, 0xA76B9F696DCB8015ULL, 0x11BC89F31C433E54ULL, 0x73F5AF4C5A964969ULL, 
            0x5F5CC431754F49E2ULL, 0x7E4B1345782ED74BULL, 0xF1A248D4CD7AB2CAULL, 0xF343972646E3D312ULL, 
            0x2A112D501566268DULL, 0x73BF44492C6FD398ULL, 0x80CB123B92E0036DULL, 0x475CA8672C857890ULL, 
            0xE8394F2A90FBF0D5ULL, 0xA4390CEB5646733EULL, 0x71C3D688AB9A5BEEULL, 0xB20346D82F9F860FULL, 
            0x46002CE9FE79B8AEULL, 0x353E8679DE7C3B81ULL, 0xE073961C05EEAEA0ULL, 0x05DE1DE050FC041DULL, 
            0x6DC221DE2B065877ULL, 0x8EAC31B8A5BD4857ULL, 0x6B705FBF875D43E3ULL, 0x43C71A92EAD2D8FDULL, 
            0xFD74AFCED7BD0B2DULL, 0xE43517BC506D638AULL, 0x9025ECD6B57DC022ULL, 0x8E47F29AAB1D120EULL
        },
        {
            0x217F84917A826E9CULL, 0xA7436E55C1182B09ULL, 0x43F2F5CBABEE6FD1ULL, 0xB60E09E2D5B15C9CULL, 
            0x283949DF386CB7C2ULL, 0x863F98F9F04FB610ULL, 0x89DF76AE1F185754ULL, 0xF450453888C30DCCULL, 
            0x3C6F4520E84F676FULL, 0x76F1FF313F48189BULL, 0xE04D578F3979435DULL, 0x1F70ED3538829A84ULL, 
            0x7B9BDB647194EA63ULL, 0x293C204E1228DFADULL, 0xB6112218DA6BBB7BULL, 0x97D52BCF17449B95ULL, 
            0x64EAF704C61ABB09ULL, 0x91A1CB794A2AFE00ULL, 0x5DC6485CFED931B6ULL, 0x2BFAF4B544BCA9F1ULL, 
            0x569D42EE6A98025AULL, 0xD2B62FDEE6F20D79ULL, 0xB228ED77B96D847CULL, 0xBE2C2E68B7CF861AULL, 
            0x2CD2D89AC31DD52DULL, 0xD44903D9A42D45E0ULL, 0x274BB518E82AE20FULL, 0xC2622CABD1111FDFULL, 
            0x98E2E8C85721DE34ULL, 0xA183D73C38AC3A59ULL, 0xEAF4AD3C03970884ULL, 0x8B7F4B3107880678ULL
        },
        {
            0x2193444EAB90CC92ULL, 0xE1DB3337D4E36905ULL, 0x95D76B9740C0FC79ULL, 0xA84864DB955AC8E3ULL, 
            0x68B0AFE9FD845226ULL, 0x829E82843987FE94ULL, 0x7E1A44AD51AA1B2FULL, 0x87B680CA0015AA19ULL, 
            0x1D3DBCFCCB8A98FFULL, 0x22DE67878E61B3A5ULL, 0xA1CEF80D852D087FULL, 0x2C01ACA5CD48D9A7ULL, 
            0xAB4705154BDF1672ULL, 0x9AD5B6461D1D64D0ULL, 0xDA7A7E10809E6CA9ULL, 0xBE0B75A4DE8A29ECULL, 
            0xBA8F694986AD58A9ULL, 0x16E8A9261BA25E31ULL, 0xA70CB80FC50ADB48ULL, 0x3F9325648B99DDC0ULL, 
            0x235C22A1311518C4ULL, 0xCE722A22C1CE0E20ULL, 0x56E12645D7C2BE89ULL, 0x3D326F4DC83C7D59ULL, 
            0xC260C99F43640645ULL, 0x072D2354DCD5DFB9ULL, 0x87A365612498E970ULL, 0xAB7E726B3A743D7BULL, 
            0xD396C286486C56D5ULL, 0x1C4778CE3BBCA9C5ULL, 0x5F42311C327262FEULL, 0xFDC9DC87E8D6D090ULL
        },
        {
            0xD99D1794DEC0C175ULL, 0x7206ADA8C12DE680ULL, 0xE7AF099A30B8111AULL, 0xB4FF8BE8FBCC4CF7ULL, 
            0x95A4955C4A31B085ULL, 0xB0CAF0598A0610BFULL, 0x3D4660E250504033ULL, 0x7ADF07F1C5182A81ULL, 
            0x0717DFAC44F18D97ULL, 0x5BF748340EDB1229ULL, 0x8346BD4C4807CBDAULL, 0xA5997A03F1009120ULL, 
            0xC4B5D6DB0BEC95FFULL, 0xC3FE706F2FBC170EULL, 0x8E095B189CF03086ULL, 0xCAE7FA0181500F26ULL, 
            0xFD0FA5624DBDB2F5ULL, 0x3CE7C1693C061F59ULL, 0x2D4223636562E48DULL, 0x71894C597DD5B276ULL, 
            0x655125DAC6DFFEC6ULL, 0x4B5245DB15F34D69ULL, 0x5490C1832BAD5875ULL, 0x484912A95AD4D3C5ULL, 
            0xA5B9E93AB252BD43ULL, 0x9A46786A55A90AF2ULL, 0xF7276439389EC74BULL, 0x1F2A55C39AB215A4ULL, 
            0xB0A2A11251872B68ULL, 0x1F822499D909A9E2ULL, 0xB1DE15B5BFE1E978ULL, 0xE890FB40DC0F6982ULL
        },
        {
            0xEB691AB0588F1DC3ULL, 0x47AD596ED5436668ULL, 0xDDC6CF64812C766BULL, 0x6147DC9EC79DA194ULL, 
            0x2561B7AED7D293F6ULL, 0x9D7D54824B8B4772ULL, 0x3A4431F2E6D9592CULL, 0x3FD6CB032634BBD9ULL, 
            0x264AC886006DA3AFULL, 0x53F75136B0017D86ULL, 0x8588BA34081E9484ULL, 0x26F02DC0CF7EFC55ULL, 
            0xC05F1F5C8C3F7D2BULL, 0xF9B51BF14E274EFEULL, 0x3632D6E5B0C656B1ULL, 0x5E65E02ACEAD2BD4ULL, 
            0xE9C4C28BEAEE9B70ULL, 0xAE125AD4B208FF65ULL, 0x7E2D35D25277688AULL, 0x19F5FFBA8E122CBDULL, 
            0xB62021222DA57DABULL, 0xBFBC9ABA7D1257A1ULL, 0x34B76CA2748BA31AULL, 0x65A756367B13143DULL, 
            0x197F2BF1A622E470ULL, 0xB961ADF812BC6ACCULL, 0xF975B0E0C288845CULL, 0x84BE9DE4265A8E3AULL, 
            0xB7749D5858F33581ULL, 0xF76AFD2E842A5EC8ULL, 0x135AC8D1A48D1385ULL, 0x0E44BA7E66233386ULL
        },
        {
            0xDB0E71BB07C3DCD9ULL, 0x208B011B457F2685ULL, 0xCB9AEE91109C8B82ULL, 0xB4E07CB63343ECFDULL, 
            0x3F8C5BBC14D0C2BBULL, 0x244CFFDF10F26CC3ULL, 0x2CAE5D5358E8C927ULL, 0xDF88D8469A71EEBCULL, 
            0x8FF3A3091777F341ULL, 0xE4221D6F11C88195ULL, 0x259188EE7148F140ULL, 0x57A98A7786E84552ULL, 
            0xCFB504BAD4F5EBCFULL, 0x874A77D6882CBC23ULL, 0x6CBE11A5F6933BCCULL, 0x097158D3E167B071ULL, 
            0x58BB180F79999507ULL, 0x0B5891E1231286D0ULL, 0xB03A1D04D29E3D3EULL, 0xEC25C0C6E7186C96ULL, 
            0x78490A2DEAF864E8ULL, 0xDBB26DA9CB5B1730ULL, 0x93C8EE612F541471ULL, 0x11AEE032425CAFA5ULL, 
            0xF039438F7C8C859BULL, 0x59EEEAFA3A3CB534ULL, 0x9403067F0E99A5D1ULL, 0x221E6AE5F76DEEB1ULL, 
            0x8E9D4E7C6050FD6EULL, 0x3653860691300E98ULL, 0x7E05AC229A18FC37ULL, 0xEDD7DB94EFFB409AULL
        }
    },
    {
        {
            0x90CF07241B1B569CULL, 0x836B2B17874FF6DEULL, 0x45A9F55A2717912BULL, 0x89C96E7FD8F6966EULL, 
            0x72E4C58574835D75ULL, 0x1566CC3F1543CF95ULL, 0x1068BC9850126C87ULL, 0xB5B11EE6B96F6A6CULL, 
            0x5AC984C3A23628C2ULL, 0x93168F5AEA7CBDFAULL, 0x836480B5E13A22CDULL, 0xEB1CEBFFF6642210ULL, 
            0x3572F00815F1E1B1ULL, 0x3A34964A1FFE442EULL, 0x9707E2423E9C01D3ULL, 0x6A351C840F32C4F8ULL, 
            0x77893DFC56F1F818ULL, 0x15DEDC8D38ADD727ULL, 0x3BA34285193F933BULL, 0x6DFE1B03DA0792B2ULL, 
            0xEE9DC5EBFDA2B294ULL, 0x4ED9B173062B6A9EULL, 0x488995211B70FE50ULL, 0x572F6C0ACF825A16ULL, 
            0x1C14403FE5843582ULL, 0xE26F0A1FC0779FA5ULL, 0x4FD4ED6A3B9ADD7AULL, 0x79003836107495FAULL, 
            0x6194398B59AA3EEDULL, 0x658A4D1369F76577ULL, 0x218B6393A96AB2BFULL, 0xAD7F5EE5AFE2F8A3ULL
        },
        {
            0x27D9581DB5EFF1BBULL, 0xE802D5D14CC581D1ULL, 0xF70DE117FDE0DDA5ULL, 0xB37339DD75978147ULL, 
            0x8F49A794F3D72488ULL, 0x44EECDF478CE2DD4ULL, 0xD6E31E455C8F234BULL, 0xA975666758BE6D86ULL, 
            0x3B6B263199510B91ULL, 0xCB96DE31B4BCF145ULL, 0xB2B232D2BB601305ULL, 0xD509F627F799DAACULL, 
            0x272934902534EC0CULL, 0x468F81D9BCA6AC9AULL, 0x5781ADDCF8F85AE8ULL, 0x950D57B29DD39EFAULL, 
            0xB7F943F2A26ED39EULL, 0x0269758A7E38A16BULL, 0x4D3EEF784490A042ULL, 0x6A77BD661B4E20ECULL, 
            0xF320AA2A3B5D4765ULL, 0x717E870B80DCB5A1ULL, 0x08D3A0F77FC4CFA4ULL, 0x881CF3338DD88208ULL, 
            0x83D2F4514AC22D4BULL, 0x74566834F1D32296ULL, 0xC53EFF94B4953A8BULL, 0xA9230B377298DAC1ULL, 
            0x3414273F8E9B98D4ULL, 0x661EFB1F0CC6ABCAULL, 0xDDFC1DFB593E84A5ULL, 0x4CA8EAA9711D1000ULL
        },
        {
            0xD6B634398217F1D0ULL, 0x542FFBD601C918CFULL, 0xBA83ED86B3D5D425ULL, 0xE3404E460578A975ULL, 
            0x1DD21610BC192434ULL, 0x465B87898EB2EDBEULL, 0x82393478A5C3F134ULL, 0x2618ED88115FEC3EULL, 
            0x7C58038E95308E5DULL, 0x5396F5162707E0CCULL, 0x0FF8036255DE1784ULL, 0xE51DB35141E323BCULL, 
            0xA94EC6DA1530D396ULL, 0x91520551068DC499ULL, 0x94549F633A09A3FBULL, 0x2EFEC746F4384D79ULL, 
            0xA260409E708EF38CULL, 0x244592FA865C3E7AULL, 0x97F4551617720EDFULL, 0x3A91B5612D4A2BCFULL, 
            0x1E55F614BE027BF8ULL, 0xCF91E58EA6A7BEFEULL, 0x2216B291DD6B6BA1ULL, 0xDD01D0434A627000ULL, 
            0xF4238A67AB9E9070ULL, 0x466144C0C296C7B1ULL, 0x23A360651FFE21FEULL, 0x2FDC441C5D4CB099ULL, 
            0xC32107E1C26351ABULL, 0x4656CA11A9B08C72ULL, 0x9D6F1B2DD16684DCULL, 0x518E6C34D0D0AE77ULL
        },
        {
            0xD3411351548B5120ULL, 0x18D2695DD5C573A3ULL, 0xA652B9CE9DF6C932ULL, 0xD87681673CE6DFB5ULL, 
            0x2D2338234EEEFF66ULL, 0xFEC899F3C860BA4DULL, 0xA81C5B4442B2A7D1ULL, 0x5FB2F2014B75639EULL, 
            0x687FEB88A0B284EBULL, 0xF7B209527EF7EB04ULL, 0xA6031E3B5B0721E9ULL, 0xAA9D0A5CB98FE754ULL, 
            0x388A6D80F21C30FAULL, 0x9AAE9E70137AF825ULL, 0xF5D37B28C1B2CB2FULL, 0xE642D097860F3004ULL, 
            0x26F7B7996E37D34CULL, 0xDF4D1A02BB344CE7ULL, 0x0E1509E975695CBBULL, 0x50E56B73A4CE647AULL, 
            0xFB767F31AA46E166ULL, 0x64D36DF4574CD21BULL, 0x8B83CBBBE74780B4ULL, 0xEC008E12CF3DE70CULL, 
            0xDF2AC65841DD6677ULL, 0xF6F42B0E23289343ULL, 0x17B01FFD7B62C5D0ULL, 0xE1F16703D23183F0ULL, 
            0x5E87C3B271D275F0ULL, 0x06FC00F03203C3B7ULL, 0xFBA794E653AD7956ULL, 0x5840F5F12EB6599EULL
        },
        {
            0x3325BB214F2FFBC6ULL, 0xEA092836B47A5B7EULL, 0xBA5D34E492BA60D2ULL, 0x1797CF4BE6C39D41ULL, 
            0xDCCBA514C6EC768DULL, 0xCCA08CBE635D8C93ULL, 0x37D8EE4E08A57B3AULL, 0xDDDCFD9F9D929BCAULL, 
            0x3BFA0A590FF2478DULL, 0x6C0810AB06EB38F5ULL, 0x0CBCD7CCE4DF6811ULL, 0x613B4FE9FDBA5942ULL, 
            0xCFD1A6ABE8D81D2AULL, 0x8D787FC7F8F8F390ULL, 0x66881F28EB471F67ULL, 0x71E86DC0F0E271F6ULL, 
            0x51CB8349A6748094ULL, 0x1593B13E4DC4B495ULL, 0x1ADE52EBB1231291ULL, 0xDA5C24336B9AF675ULL, 
            0xB066053F44EB6661ULL, 0x66ABF683F4805918ULL, 0x2738A42F339BF35AULL, 0xD6070D631EB15211ULL, 
            0x8C26E29C436823F2ULL, 0x8EC4A6A63924B6D0ULL, 0xC5DF630CE88C2CEBULL, 0x8B8AD5EAE4B11BABULL, 
            0x5D69E42F205CA404ULL, 0xE4BAF2C76E41C436ULL, 0x7EB28CD9D9FBEB4DULL, 0x787901DA9773A9CBULL
        },
        {
            0x7B89034F276EB778ULL, 0xE2B27FC9D0742FE9ULL, 0xCAC69E340601BB05ULL, 0x9F39CBBE3FDC34BCULL, 
            0x02A75293BD123EA7ULL, 0xF9FA1F43F1650F91ULL, 0xEB7A63B68B168257ULL, 0x7D779DDB009B3644ULL, 
            0x138BB0D3DE393E03ULL, 0x8D824315BE68EA97ULL, 0xC1B634A4A9CFE5B9ULL, 0x06023915EEDA6C2FULL, 
            0x474107EDFF4C5034ULL, 0xC3B74363AAD0CC4AULL, 0x27F2644BEE2A6434ULL, 0xF8B32550849FB856ULL, 
            0x7C1773E3A7D9AE95ULL, 0xA2601A887751897BULL, 0x503795C4A58A71E3ULL, 0xEDA98844B72D3AD8ULL, 
            0x21BDA6C8FC8BD761ULL, 0x8EB44E91174F77CCULL, 0x405A39D11002268FULL, 0xB19BD60F4021C287ULL, 
            0xD2F410F95B6DF313ULL, 0x77A7EA2155B6D10EULL, 0xF14D6912A81367A5ULL, 0x16DE168844E5FCB6ULL, 
            0x162A2EE09C283198ULL, 0x6184DE68FA5C696CULL, 0x2268F6CC81730986ULL, 0x73795F578EB651EDULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseEConstants = {
    0x71EB95225CBA0921ULL,
    0x12BAD2457E83B557ULL,
    0xA01161217950DEC4ULL,
    0x71EB95225CBA0921ULL,
    0x12BAD2457E83B557ULL,
    0xA01161217950DEC4ULL,
    0x4B2478056B85B3A1ULL,
    0xED2868E33AF549D2ULL,
    0x0E,
    0xD8,
    0xFB,
    0x22,
    0xBA,
    0x46,
    0xDB,
    0xFD
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseFSalts = {
    {
        {
            0xD72AC576EF316758ULL, 0x3F1F7CA396FD9126ULL, 0xDD79860A11EE17E4ULL, 0x3B5D4758EFD2247CULL, 
            0x31E9656C302C9590ULL, 0x280858105255B90CULL, 0x59496D412BC663D7ULL, 0x3C12D655917CAB53ULL, 
            0x0B745D0798730782ULL, 0x604511BA401112E4ULL, 0x0D23AD6D0865AD43ULL, 0xCEB7C75A4B446992ULL, 
            0xD0D894CC73919B70ULL, 0x7BC5C0A3A84B5CEAULL, 0x337D285C0E4C2A50ULL, 0x6816D6B11A417790ULL, 
            0xC7969F249C2D17B8ULL, 0x23999D59D10D2898ULL, 0x7F69190F0881BF14ULL, 0x52183562EB69B8A8ULL, 
            0x062F48EA71771F18ULL, 0x08BBC94B263A8880ULL, 0xD0E6737912167D26ULL, 0x2C9A5F0D57FA082BULL, 
            0x4F4ED4FC9B6BE84AULL, 0x49322B4C188018A9ULL, 0x774B722A0E15962BULL, 0x3BB7B0C1B96EE2D1ULL, 
            0x32BCC8C858DA96DEULL, 0xE28A366FBCF913DFULL, 0xA604C80655CDB975ULL, 0xBD81BC1059C0D6E4ULL
        },
        {
            0x76C3D4982528E6F3ULL, 0x4E245D7D455EAF10ULL, 0x4AECED1157723883ULL, 0x8F97DEBE1E010386ULL, 
            0x35DBE993B44BC135ULL, 0xD7E7C5ED1F87D0C5ULL, 0x83DE0C2BA1A1CD16ULL, 0xDD62E32642FE02EAULL, 
            0x7E37ED7D179BCAAAULL, 0xF1B75F7135536CF8ULL, 0x3B8996984AE8ADEAULL, 0x44AE25264773F639ULL, 
            0x39A78570A885BC88ULL, 0x37C1CF66EFE0E3E2ULL, 0x28708553BBD195CAULL, 0xD88A3C4F4D2C3FDCULL, 
            0x7AF63FAC6CC81A24ULL, 0x214CAD1E04098314ULL, 0x9B284D23D67FE8ECULL, 0x80EF261558279F8DULL, 
            0x7927F723047DB2F7ULL, 0x4541FE400375417BULL, 0xE23B6E34770C58B7ULL, 0x31FEDD60375035D5ULL, 
            0x0AFE94E356297809ULL, 0x8A5DB57BA63B5730ULL, 0xCF2F89AF58927C99ULL, 0x422BEA90DC334FD4ULL, 
            0xBEF1A3BD59795240ULL, 0xBC9B94E5146E1EADULL, 0x5AC0A7FD29130C48ULL, 0x1E3F695C01351704ULL
        },
        {
            0xCEE99A24B83B8AE1ULL, 0x25D5F861A11E977FULL, 0x15FE4814C535C857ULL, 0x4E7D42C29A52756BULL, 
            0x142D2D6DDB64FA90ULL, 0x0A1D24BF38C7E2D6ULL, 0x537AF7A0F95F7C14ULL, 0x18E2F2EE3E5D1A2CULL, 
            0x723993F7D6F50205ULL, 0x2E6A04F4AB2550BFULL, 0x178A9FAA6BBCA8EEULL, 0x4AF68A8AAFF68C9AULL, 
            0x07849DE3E32F49A6ULL, 0x47D21C76A83FAB44ULL, 0x2BB8523DD26D6832ULL, 0x17467B2E647EFE75ULL, 
            0x3EAF16D335CC3D89ULL, 0x97BEB8D3AE981D9EULL, 0xA20BA123887CE8C3ULL, 0xA80EC8070237E7E7ULL, 
            0x63C0E46BAA9762E9ULL, 0xC5A95EAB9DBA9D6CULL, 0xC44990C52CB3087BULL, 0x25E053AB4B63832BULL, 
            0x9C1542764FF2C2B2ULL, 0xDA5837AEBCC775C7ULL, 0x2F27BBFFCA078167ULL, 0x054E030142CC9D73ULL, 
            0x99374D1D73B0D52FULL, 0xEC11FA0B439D4AACULL, 0x79F7036A04C60751ULL, 0xB9E5F28DA0DF8A74ULL
        },
        {
            0x8EF7DD895DB10257ULL, 0x8F65AAFE23DD57C1ULL, 0xA0AFA9FBD7661566ULL, 0x58DA36D6CA470EB8ULL, 
            0x23EEDED2A5CF2C70ULL, 0x574499ADB20E489CULL, 0x9A05FE77A22D64A6ULL, 0x5BD4776561755CDCULL, 
            0x4D8B08CB5A2BBBFFULL, 0xB5266803B8C023C9ULL, 0x35B9F0CEAA024071ULL, 0x8B590A059D41DBF3ULL, 
            0xBF470125ED43C48BULL, 0x09D0E630A428F20CULL, 0x0E9E84AE441F5613ULL, 0xA0B77B3FA26F38CCULL, 
            0x35E76662C8F8318AULL, 0xCA2E6068283360C2ULL, 0xC4DDE1B610EF57FAULL, 0x8ED1D64770A73195ULL, 
            0x6E079F537CD91F74ULL, 0xD367B4BD7B18CB2CULL, 0x6120EFF529095E23ULL, 0xE07EB8128804E7ACULL, 
            0xCF3772EE3D09001DULL, 0x20D7F2CC9360E29BULL, 0x90A4E96A505D3E6BULL, 0x8D889F0F97680743ULL, 
            0x8C04651281ED30A5ULL, 0x207944057D369779ULL, 0x0BB00B196A34128DULL, 0xE4F7AB4157257230ULL
        },
        {
            0xE2E89EA6A73A4D22ULL, 0xB4D07978A3D79446ULL, 0x517A0BAE00E90422ULL, 0x45CC69901C95F793ULL, 
            0xDDAF3CA200D15DE1ULL, 0xBAF4889975053B2FULL, 0x89BF56197E987077ULL, 0x331F2545B8970271ULL, 
            0x5A418D266DAD2DC1ULL, 0xEB8E098C75A48F1DULL, 0x02FFC2AB53587F85ULL, 0x0FDD1C416B2049E1ULL, 
            0xFA08E7C810DB12D7ULL, 0x546B8E91D3AADA71ULL, 0xF031D410D3A99746ULL, 0x7BEE05A9AE8025A0ULL, 
            0x7DCE10751283ACA4ULL, 0xFAA40F069FE895D4ULL, 0x9A2343E3D508E186ULL, 0x493C8A9A46D24BAFULL, 
            0x7E76EA6C2496304FULL, 0x90FD1DEFB69FBF12ULL, 0x37B2A219066644CDULL, 0xDBD8E83E730C8A71ULL, 
            0x6EE95A4B10A54F96ULL, 0x0AA0B5BF773C2BAFULL, 0x60EBCA180EC3BCFEULL, 0xA2AE5E25A4087B5CULL, 
            0x2F6166CCE2C98C76ULL, 0x4789FBC9E5AED3EEULL, 0x2E1CB2EE0BF9167DULL, 0x6BE66ACF196185E2ULL
        },
        {
            0xA1A719F0F650DBE2ULL, 0x8595F1251A40D566ULL, 0x5B00158F0FFB72D8ULL, 0x8ED88DDE4E1D6AD1ULL, 
            0x64014A703F397D0AULL, 0x57369B5E5933A9B3ULL, 0x7C9F594B971FA1A2ULL, 0xBD39187E3D13652BULL, 
            0x07324B1BFFAEC040ULL, 0x398FFE52C41882D5ULL, 0xBE4E3F7F1C643284ULL, 0xEB5538DA84D3460BULL, 
            0x4BF8F5FABD62272AULL, 0x92A0A4BCBFE768B1ULL, 0xB2C2B7E490C3311EULL, 0xE68FE07A9AD333B7ULL, 
            0xA620837FC4D6E951ULL, 0xF5679AB3EE5D84A2ULL, 0xA4DF540BC739A09AULL, 0xF9BD71A18D3618C6ULL, 
            0x325F8BAD9B106A58ULL, 0xDFD1EC9BB85FA19AULL, 0x8C131468529C4094ULL, 0x9A943B1137D8AF0BULL, 
            0x3FB36E3A1923667BULL, 0x856C306DB142AD37ULL, 0x3C3C6375B7BE5E90ULL, 0xA3DB5D62DDBFE21FULL, 
            0xA8AE926BB486356CULL, 0xC442F213EA1E45F9ULL, 0x533EA5EAD8CF7CA4ULL, 0x08DD2506B6087920ULL
        }
    },
    {
        {
            0xDC5F6C0E0E690103ULL, 0x4784A139775BC5BAULL, 0x5BDEBC8169CCF592ULL, 0x4376CDEDE0AC4A6BULL, 
            0x9873426A6C53FD13ULL, 0x1DAD71E0E8288AE8ULL, 0xE2226A80D6DA27D4ULL, 0xF50C5768114D069FULL, 
            0x5C3C01B65BFB5FE2ULL, 0x0E52D01DB8709743ULL, 0x0AB166B39FE0B1E7ULL, 0x3212A194449DAAFFULL, 
            0xF266D82DE2FA169DULL, 0xB51008D72AA9812CULL, 0xD97C49B7C0439EA5ULL, 0x98BCBCFCDE08B88DULL, 
            0x0433D3307EBE1D77ULL, 0x2241129F95479F52ULL, 0xCB85334FB7CB9AEBULL, 0x9D35A1D91600C3C9ULL, 
            0xF88E980EE9F00FBCULL, 0x2E07C8E906C700D7ULL, 0x560FB06DCBF89359ULL, 0x78F7583DB2CBFCDEULL, 
            0x300B8B27F2EA8C74ULL, 0x7673D39BFD116D1DULL, 0x9A641D1CAFC6B08CULL, 0xEC9BB2E05E52FF7DULL, 
            0x2FFCEEE7A95CB84BULL, 0x437070A436E9FECAULL, 0x9753477C10803555ULL, 0x095084B16FBC5D27ULL
        },
        {
            0x88646DEF50DEA89DULL, 0xD6D5A825521E9BA7ULL, 0xEBC0522198DF35A2ULL, 0xF1B90BB4F53F76C0ULL, 
            0x57CD3BFDCF0C67D0ULL, 0x519A14C349BB1489ULL, 0x031B3A43E356249AULL, 0xA4B20A0C8330FFBDULL, 
            0xCD34755F164255C2ULL, 0x888B8790E9AB9B50ULL, 0xABDE8471E05DF46BULL, 0xAA8E2E0A7265BB36ULL, 
            0xCFBD20A2C4B2920BULL, 0x5F5C74AD6263434AULL, 0xB916CD94DEF8C496ULL, 0x40C3D0CBF1AC31A2ULL, 
            0xC8464E1738E9178BULL, 0x78260D02B2109B27ULL, 0x03BE4976C169369EULL, 0x020C09B60F4048D7ULL, 
            0x3B04992D68F95AB1ULL, 0x85EC054DA7504511ULL, 0x753F44D4CC9AAEC9ULL, 0x3E5DB6CE342C5591ULL, 
            0xA23991C90FA24487ULL, 0x9A3AF4AEB3160CDBULL, 0xCD22C1144C6B2A22ULL, 0x6BF97594DC649119ULL, 
            0x06F810AAB6938FA5ULL, 0x00B0452A98CD2C39ULL, 0x1AA203B4E9F1786BULL, 0x6AD8F967E442396EULL
        },
        {
            0xEF7C584B84BDC53CULL, 0x50A747722687A5AEULL, 0xA033CF7F0B481D15ULL, 0x0E4B3BF92FD1DA2BULL, 
            0x29AAA2D49722D017ULL, 0x2AA63845362EF43DULL, 0x7A4ED5118DD4420BULL, 0x82715AA5FF0E5107ULL, 
            0x0ED76A583D49173AULL, 0x312AA47B02A85559ULL, 0xAAE9ABD4498B4A4BULL, 0x6B1C97661C19E7F4ULL, 
            0x2C38FF732C118A62ULL, 0x9B8F7FD53398DE03ULL, 0xD01218C8F14A5401ULL, 0xA15F8C94174A44FAULL, 
            0x8CBE378AD674C0CAULL, 0xECFF0CC53EC2C4F4ULL, 0xDAE6F5689B407D94ULL, 0x7D87A1C0E974C344ULL, 
            0x2DC3B615FDAD21B3ULL, 0x9CF54DAB01FB547CULL, 0xBC90998F6D008604ULL, 0x2B28F369B535E9A8ULL, 
            0x71B9042FC505D0B6ULL, 0x2A43650819981D2DULL, 0x8C94DE2007B7162EULL, 0x14F56EDE75025F9EULL, 
            0x9A99525BC4A4B2B8ULL, 0x0218F920407D3AE5ULL, 0xDB59ECA26F985A61ULL, 0x804D0FE80978491DULL
        },
        {
            0xC1B5F7A19C94D2A1ULL, 0x124231CC17EFCF1EULL, 0x36763F732D8FA2E5ULL, 0xEF390497A1DF7222ULL, 
            0x8846B346F37B6BC5ULL, 0xA6C7002771DCD79CULL, 0x384BBF0633F71331ULL, 0x60A0F4F8CE8C0C59ULL, 
            0x660BFB418E11B8CBULL, 0x0A3F8B34A817B188ULL, 0x67BE8BD6884B5DA0ULL, 0xCA95F6D7BC557D93ULL, 
            0xA1F9985D72371D76ULL, 0x776B10EC76EC3498ULL, 0x3C1AA480FDB5F427ULL, 0x57290C32A60499D9ULL, 
            0x38382ED643386568ULL, 0x4468444A9E6AD082ULL, 0x02F70E71613091F1ULL, 0x37EC53784B9CB663ULL, 
            0x544ABCB73E54304CULL, 0x6C2E7F0D6B94DA0DULL, 0x21ED058B4CDADF73ULL, 0x247DF9B3437056A9ULL, 
            0x6195C8D084BF2504ULL, 0xC848CBD5EE1322B5ULL, 0x5C96BF8189CAA011ULL, 0x5D030F051F148A70ULL, 
            0x9B06C99DC6A31625ULL, 0x369F4142A0105C1BULL, 0x7A731181D3C60440ULL, 0x349BE93E321372FBULL
        },
        {
            0x79CB1C59F2E12632ULL, 0xC9A6CA593C8466E4ULL, 0xD46EB21E8E727016ULL, 0xD4D7800275759144ULL, 
            0x44BC9EE52C036C3BULL, 0x37A2FC8ABF530141ULL, 0x824626E93869896DULL, 0xC29639B7E4687D62ULL, 
            0xF2230BA96A8E891CULL, 0x4561F8B5D47386A3ULL, 0x098E9CF3478DC85DULL, 0x486710C3708EB4CFULL, 
            0x798A2FE7801E2D29ULL, 0x7FD9F63E49FE7118ULL, 0x66AD51146D268745ULL, 0x7C8E80843825C7F5ULL, 
            0x21CB684CABDFF0B6ULL, 0x024294B03D7E71CCULL, 0xD0C3E44D735C6E86ULL, 0xE63317B122368A77ULL, 
            0x2ED2438C1E23E3F4ULL, 0xF9340C81840C8D91ULL, 0x98E835B4106A384BULL, 0x22CA313270E61251ULL, 
            0xC3D218BF2287B207ULL, 0x1DF14FAAC72B7950ULL, 0x07E4762288526FB0ULL, 0x83D3D19C0B81D4DFULL, 
            0x214C8974EA289149ULL, 0xA9E052B2E2C7B0BFULL, 0xC4EF3AEAFC161CFAULL, 0x4ECA95AE27588E44ULL
        },
        {
            0x88EF273637F34972ULL, 0x74D0D06329BCA48DULL, 0x708CE51FA93F7B60ULL, 0x3F65346CFDA7F2F3ULL, 
            0xB1C1D92D636594A7ULL, 0x3AB6EAF1B90D5F22ULL, 0xCED4C720B43E0E39ULL, 0xA115A7EAC04A0CF6ULL, 
            0x7D3AB6ED7C65A71EULL, 0xF7547F6B04FB86AAULL, 0x072F541870E1C612ULL, 0xCC24417D6337FA3EULL, 
            0x50BF314B96BB280AULL, 0x224857CB637DDD51ULL, 0x53A0FC35FC595C04ULL, 0x7AA2DEAA45798C1AULL, 
            0xDC7BDACA83978679ULL, 0x60A781BA49FF3BC5ULL, 0x9A9FBC1B1EAD50C1ULL, 0xEEFE2C76EA6BC592ULL, 
            0x9AE43865B1130BE7ULL, 0x77AF4F5F7615E4D6ULL, 0x4AA3019E85D23567ULL, 0xEEB2085206D7FA41ULL, 
            0x5E7A615F94BABADDULL, 0xD4BD1A35ED3F8E86ULL, 0x674C69595BEA1817ULL, 0xC8930F08E026D59EULL, 
            0xA76F7683504AA2BEULL, 0x1A3266460C802517ULL, 0xC6F44E765631F83BULL, 0x969C5EE67C567568ULL
        }
    },
    {
        {
            0x6BA8B1C11B74711BULL, 0x79FBA219AAF4BAFDULL, 0xA011B45CD08FE64DULL, 0x42576777C3A61666ULL, 
            0xA09A28582D84A164ULL, 0x682AD10CAFF3E729ULL, 0x6C705361608087C0ULL, 0x0410E1835FC7D3D0ULL, 
            0x7FB5B503A91E1341ULL, 0xBEC96337C3C1EFFCULL, 0x7857C0E99817EEB1ULL, 0x15C456C23B24A765ULL, 
            0xD0F9F575AC1B7BE1ULL, 0x61F83673A4F0139BULL, 0x53BD593E4CB2A4B1ULL, 0xD9AC458D897D8BD1ULL, 
            0x526B0EB89645DFA3ULL, 0x8179A9A218A45BB3ULL, 0xD31D35268916A25FULL, 0x723E216F8422CC1DULL, 
            0xDFE7CB6925982FE1ULL, 0x59507FC0E001BB77ULL, 0x6181C3C4D9916462ULL, 0x11DA479BAF380092ULL, 
            0xE51EE35D238C2E46ULL, 0xCFE82262C5C7B33AULL, 0x1A3970D2AF5D4DE8ULL, 0x1CDCD5361CA0F25AULL, 
            0x1945A89C9A3AFC3DULL, 0x06C9A21CB897FB2AULL, 0xC501A7DD1B431157ULL, 0x4CDD3A247C4BCE63ULL
        },
        {
            0x48237616E81E62FBULL, 0xEAB764DFDF90F354ULL, 0x9FF95DDF7994D052ULL, 0x77F67419325AB466ULL, 
            0x96B4D3474AF3251EULL, 0x96DCE9D079C587B8ULL, 0xAF151A157A08B5DEULL, 0xB0739B2328ACEBC7ULL, 
            0x4D4D4017EE2928C1ULL, 0x56539F1503E9E003ULL, 0x86291112E6BFA147ULL, 0x1C3E8E140FDE29C8ULL, 
            0x9D1538E2F658D3FFULL, 0xECE4226BBF110A1DULL, 0x8AAE3E6CE9EBF93FULL, 0x998E2D26E2B79FE3ULL, 
            0x837400C9AC37CB67ULL, 0x06C7A7445A324452ULL, 0x0CA2553F2284DEC6ULL, 0x26C9C8B7B5645AB5ULL, 
            0x6DBA2A878044E343ULL, 0xECCF44CA3D6914F5ULL, 0xEFA6C2B239687AB9ULL, 0xC440A6962DD31C44ULL, 
            0x8BDC599A434C3892ULL, 0x2237B05C849DA19AULL, 0x704DA08C4D73092EULL, 0x79D66842288F1856ULL, 
            0x3C89A978E1A0F4A2ULL, 0xDB51DE7EF31F462AULL, 0x4F4B4839290BE666ULL, 0xD261708003773006ULL
        },
        {
            0xC95732DCD649DAD6ULL, 0x6C22446E536E7CB2ULL, 0xF0E69F877EE0B485ULL, 0xECE98F10872ECAA9ULL, 
            0xC6ADCDFBBE52DA51ULL, 0x67663D6C65AC5960ULL, 0x9AAFE84585F627F1ULL, 0xF8DD733BC82A741FULL, 
            0x44F068595C7DC5BAULL, 0xAA35D82FB36D72BBULL, 0x724BA4784D1F4BDFULL, 0xF41E866D8E0D2C80ULL, 
            0x3DBEDDF6DA8B9CB6ULL, 0xD7F42F7DE41D0A7AULL, 0x6DC4E5930807C0D9ULL, 0x6989119FC6BA519AULL, 
            0x09B3D9E47687E27AULL, 0x1DBF705626E6B9A7ULL, 0x1E0391C966D225EEULL, 0xB4E598FFBF22AD08ULL, 
            0x1A977E0082FB3B0CULL, 0xF265397911BBED19ULL, 0x4BE00C99B7805430ULL, 0x2C102B5A0654069DULL, 
            0xF70761C78E92E646ULL, 0xB94D621944D3206AULL, 0xAC8E221140DD5780ULL, 0x982F754A90E55B74ULL, 
            0xB7BD1B24ADD17BA2ULL, 0xD768C2FE21BE7C77ULL, 0x54911FD08CB45993ULL, 0x77534EA30F4975B2ULL
        },
        {
            0x9CC53DD75B03575FULL, 0x0941A8FC9388EEDFULL, 0x0E87110D3AE3A426ULL, 0x07B0985EBFDD0D32ULL, 
            0x74DFAEA551966410ULL, 0x63DA14DF5AF355E7ULL, 0x00DA73D334925BDDULL, 0x86101BA4A188EE23ULL, 
            0x7BD95053807C18A5ULL, 0xF27AB2FCA9086228ULL, 0xC37885E95F28A033ULL, 0x2D873841F2D87ABBULL, 
            0x0751628D2131FCB3ULL, 0xED202CA93338A9E0ULL, 0xD5E67DBC16A42CCCULL, 0xC9C7DE6C9512C468ULL, 
            0x342421B983000279ULL, 0x48F4AD9E0001AE2FULL, 0x8492E5CD7C58D9FBULL, 0x8701541502EDF31DULL, 
            0x55C762A4DC37757AULL, 0x105F0303E086574BULL, 0x96C5E3B5DCF7EDA5ULL, 0x4DC74E9BDBD6CD81ULL, 
            0xA9C337255668C85BULL, 0x73BF980AAC7200FAULL, 0x5C585783BE90FCDCULL, 0x0FDEEC4034859C39ULL, 
            0xCDCBB33CD300498FULL, 0x4C208965E2ABF6B4ULL, 0x8688495AE77F8230ULL, 0x02D804DF9BC2238CULL
        },
        {
            0x7C21F2D0A15A6FECULL, 0xB9DB9FB0BBEB6596ULL, 0x4B18496893C747A6ULL, 0x0558F075AB527D00ULL, 
            0x68EA2BA038C8B970ULL, 0x7474AF9B21FB4F9FULL, 0x133F767F8EFFFB84ULL, 0x9FF7C9650C8555F1ULL, 
            0x0192E5012B662E4DULL, 0x9F55176A50055F22ULL, 0x64791CAF0CC18A85ULL, 0x3134D4B951554F8BULL, 
            0x3BD64F88E8DF5EDAULL, 0x1557F35CF6710FCAULL, 0x463FBD79570A6940ULL, 0x7828D62B7CCF39F5ULL, 
            0x759501755F1907C4ULL, 0x47768F1211BA9426ULL, 0x6B6E84A5B12A501DULL, 0x2CE8CBD6ECF080F7ULL, 
            0x070E7F9A8C250B7BULL, 0x231DCE8F66F3FB10ULL, 0xCDFD393E20FC7267ULL, 0x095AE0C9CEE86565ULL, 
            0x40CE23A802C43FC5ULL, 0xA2077EE2D74FB51BULL, 0xF1AE09EAB9E4F04AULL, 0xF4BFDFDF966E1319ULL, 
            0xA5B91E0FE9810FEEULL, 0x2B7E0692BD4D13F8ULL, 0xDE640883C375C792ULL, 0x75262860EDBBF95FULL
        },
        {
            0xF2E8961CF5D9E7E0ULL, 0x372306573973FBA7ULL, 0x6F717FEF298D0770ULL, 0x3EE361192A9C0931ULL, 
            0xF5E3F11F609C606AULL, 0x82CD54E5876F8003ULL, 0xFC38B6B062C62394ULL, 0x609A8DC6E9AE2EDCULL, 
            0xE74BC6A3EE5CF558ULL, 0x942AD801FE7278E6ULL, 0x051ADA58FE48DC5EULL, 0xD271C0369D180E6FULL, 
            0x8805DFD0BEDCF680ULL, 0x65BCF9D56FAF4312ULL, 0xE73C92298F276ABAULL, 0x50132BBD98B76F9EULL, 
            0x602B21948F8AAEEEULL, 0xE5516DF3743A3D17ULL, 0x5DE1CF9910CC54B5ULL, 0xBC6AAC0057A6C25FULL, 
            0x74261C28E21B850BULL, 0x05DF0567B45D7EA2ULL, 0xB2189A38DC8380C2ULL, 0xEFD00AA837AE53EEULL, 
            0xE0A9468A0AB00233ULL, 0x53AC114F7F40A350ULL, 0xAE195708218E36F0ULL, 0x022FD582990995ACULL, 
            0xD57E96C29E5B1E98ULL, 0x51DACD2CF662B4B4ULL, 0xF640DCC795F5B16AULL, 0x3B0E4B00066625B5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseFConstants = {
    0xEB2B6A871193DEF2ULL,
    0x3DC98655D3FE6C8DULL,
    0x6BA35E882B84FEBCULL,
    0xEB2B6A871193DEF2ULL,
    0x3DC98655D3FE6C8DULL,
    0x6BA35E882B84FEBCULL,
    0x6178871CA5F24B26ULL,
    0x7566E40610F10BBBULL,
    0xE0,
    0x2A,
    0x78,
    0x99,
    0x2E,
    0xBB,
    0x01,
    0x22
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseGSalts = {
    {
        {
            0x3493E2393C8A3363ULL, 0xFED8EF9CAD0B75B0ULL, 0x1B43166D8D590F23ULL, 0x950C6A5F96186F02ULL, 
            0xD920955ED40EAED1ULL, 0xC73347DFC2098E7DULL, 0xDB318753B45668ADULL, 0x6FFF47FBD1ACA11BULL, 
            0x403E0FBA897AC1FDULL, 0xD360FC3707E0CC52ULL, 0xB716DFDC9AE30A4AULL, 0xFF051B6F979F097EULL, 
            0x290D848FCE56D2EFULL, 0x1E123459027B1323ULL, 0xD9C7686DC64E0554ULL, 0x2DA314EBA0C91C4BULL, 
            0x7F5C46085C09D27EULL, 0x8905A8A180ED7AC2ULL, 0xF0F3DE6388BC0747ULL, 0x6E7C8F05A260CCDEULL, 
            0xA0341329C5F9C6F2ULL, 0xD21C7EB56E9BE9B3ULL, 0xC2ECB6F1A5AE2E74ULL, 0xB8B4280029F04C04ULL, 
            0x16EA4D142F3EA538ULL, 0xA089601BBBF4F525ULL, 0xF9E369C12195D4A1ULL, 0xBD7BCCC8731676E8ULL, 
            0xD387DFC9913068FFULL, 0xD5BB9484BB6CC833ULL, 0x7A90505BCA6A4EE8ULL, 0xC8573B0D817936A5ULL
        },
        {
            0x4AAD90805A5A9248ULL, 0x1230395870480BFEULL, 0xF5CF37293AB20A04ULL, 0xB258CB98E2C76449ULL, 
            0x217D5346C37DE0DCULL, 0x42C2EF967DF1BB6BULL, 0x6E36A5DC29EAB821ULL, 0xAF145B4ED0E03DA5ULL, 
            0xB88D95EECC0F2BEFULL, 0x4A7A37D44D922956ULL, 0x17AEB2234E14D798ULL, 0xC14CA1305AAB7BA1ULL, 
            0x93E5587596B6911EULL, 0x8A322373A01C70BCULL, 0x7A9C955A1E9995AFULL, 0x008D34A7CF4587FAULL, 
            0x160E4656D060A854ULL, 0x64F5F543D05859DBULL, 0x847555A56DA265CFULL, 0x7EC5B4496EBFE7CCULL, 
            0xD7CC7E11BABD41CCULL, 0x5DCF74EFA0AAE60AULL, 0xBC589F2160AF417BULL, 0xFB739F2A42875160ULL, 
            0xE83EBCB867DC0952ULL, 0xAA09FFE0D1E6462FULL, 0xC37E68F2EBE22F76ULL, 0xFCA5808E68219EA5ULL, 
            0x2D1D35F3CDF12417ULL, 0x8609DF2805D9CD96ULL, 0x19A1AF08017E2FB0ULL, 0x926253C66F165709ULL
        },
        {
            0xEEAA9502A0BEC28FULL, 0xC75A4F4B88B538BBULL, 0x569DB476F15AB1B5ULL, 0x80DF53FEB39E5388ULL, 
            0x0B3A75BC5EBCFAAAULL, 0x2140D84E6CDEA1CBULL, 0xF5E50739EA5ED040ULL, 0x47AF8B9A8D8BE4EEULL, 
            0x3AE0AC68E52E30CAULL, 0xA379D6625638CEC1ULL, 0xFCD9B07196B08DFAULL, 0x5446D93BE101530EULL, 
            0x192BC649230F7E68ULL, 0x9C09028B544623A5ULL, 0xAE8767FABD7BCDE4ULL, 0x407395C2BF9D823CULL, 
            0xBF67BEC6CD2BD6E9ULL, 0x83049D585E91C253ULL, 0xCBB6A32321637389ULL, 0x59ED8658AC847E00ULL, 
            0x8D6E3836B8FE1DF7ULL, 0xA78A1098191174E5ULL, 0xFF6268F78B9EFE83ULL, 0xF210252342B55237ULL, 
            0x7FF2BD22491C755EULL, 0xF6D3FF3584B73D52ULL, 0xEEFE84EEE22E2690ULL, 0xD0DD3D740B2EE3B8ULL, 
            0x0D5146C0F88D7A7DULL, 0x50DD1C54BEC1F7E1ULL, 0xAFFB704DC36E5942ULL, 0x989C07FB33ED3991ULL
        },
        {
            0x8036FF83D5D91BACULL, 0x7CE7DDFD0FAE76CFULL, 0x0384FB71BF0BCF4EULL, 0xE286573B3DE1D1E6ULL, 
            0x31DA22A6F22E9E88ULL, 0x81BD40DC7A0E0F7DULL, 0x87819F932267CF99ULL, 0x7526E08FA61494DEULL, 
            0x4451A4C136C049CFULL, 0x3300C4670D81D4D3ULL, 0x794303F6E60001F7ULL, 0xD456C2F846E04384ULL, 
            0x8725778B38723F1BULL, 0x403849365E4D6D63ULL, 0xC254FF113177A2EDULL, 0x28A4DBB1F29E635AULL, 
            0x841FFE326CD2FE63ULL, 0x24FB8F5AA9A50123ULL, 0xDE7FB733A4EBC371ULL, 0x5A87F539F46F59EEULL, 
            0xE107C717CE353EA7ULL, 0xE30150A6B95FA71FULL, 0xD1692124A11CCB2AULL, 0x48A42053E81522E1ULL, 
            0xA954F9F77A0DEBD2ULL, 0xBBAD61525525643FULL, 0x0ACBC1EBF018FCCEULL, 0xF34C033BF49B4E18ULL, 
            0x11DA3737D6F4DDA8ULL, 0x041E98B147525A94ULL, 0xE8D55FD59C71F72AULL, 0x3AE20F2D376A9CE9ULL
        },
        {
            0x7C9EAB0940E9EC2AULL, 0x96D9ACD7609486C7ULL, 0x11A7D272D912EEBDULL, 0x3ADFC8C45A3D2F22ULL, 
            0x1244DF03BBCC5EACULL, 0xDEB0169A9035B61CULL, 0x4A56C950AE80636CULL, 0x1B9FD34D552F1595ULL, 
            0xB31F772FC95A1221ULL, 0x7DFF39926C9B55D4ULL, 0x860B7F6FA53ABA2EULL, 0xE00F22D349C5978BULL, 
            0x82769DFD9BA23FB1ULL, 0xA9C3EA373DC5872AULL, 0x5488853B4171D5CCULL, 0xDC87A67899D42FE9ULL, 
            0x8DBE356AAF096A57ULL, 0x6B4CE95735EABDA7ULL, 0x379FABFF873A9151ULL, 0x6245997DA5824F0FULL, 
            0xC175A4E6BC23A6C4ULL, 0xD85DE5BBBAC9295FULL, 0x668540830A37D929ULL, 0x0AAE1A8AD3C02915ULL, 
            0xB0F475C5058797B3ULL, 0x9EC1A188F5E4F5A0ULL, 0xC64118B66203C8DCULL, 0xFBB524D750D3F834ULL, 
            0x7F2134D549BEE29AULL, 0x844882B501EFE802ULL, 0x65A19FE417F43D97ULL, 0x93D25A90A83E47CBULL
        },
        {
            0x4A8EA8810CCFEF38ULL, 0xBD12CFEC93A80093ULL, 0x9A3423F9877CD483ULL, 0xC1C283E8B3053717ULL, 
            0x28F693F2E61A4DC1ULL, 0x6844677E79DAE623ULL, 0xCEAB1158B7A812B2ULL, 0x5DF38A0FD0961347ULL, 
            0x4CB15B9F7DFA0C81ULL, 0x7876A9F28E20D438ULL, 0x242C5F6AC109A356ULL, 0xEEB43D9313F3EC89ULL, 
            0xD24B26F6772C75A4ULL, 0xFCB7343474E272F5ULL, 0xE9BDDD97C9262C71ULL, 0xBA7648ADC06427ACULL, 
            0x98327B0750754578ULL, 0xDB634BCB91AD92FDULL, 0x48DE6F8D3C6F3027ULL, 0x25FC8C2614E65B7FULL, 
            0xA1D383EA1526D83EULL, 0x9A8CFF48919CADB9ULL, 0x1CD4CB489E39D9F4ULL, 0x362D3999848370B2ULL, 
            0x7E3369FDAF908620ULL, 0x03ACD22D886D6689ULL, 0x5D19FD970C917AC1ULL, 0x87D46D34E845FDECULL, 
            0xB0AE791A08CA59C9ULL, 0x892C6044470C3F8CULL, 0xDD57E8BA2B39CA48ULL, 0xF2D69ADAB469F70FULL
        }
    },
    {
        {
            0xE026A88B334F9CD4ULL, 0x0AF23EC10D41380BULL, 0xB233175A23AC6888ULL, 0xF0683F0B1416CF61ULL, 
            0x9E3C683DCDBFF384ULL, 0x03AFD4ABC3B3DBC8ULL, 0xA07359EA368BFB6AULL, 0x314473814A16DF8BULL, 
            0x1F8987D8B9193076ULL, 0x20275C679E42D0C3ULL, 0x71621218448EA3F4ULL, 0x6830ACBEAB38FAF7ULL, 
            0xBD2304CB2AA57DAFULL, 0x76E42D05B8404883ULL, 0xC8FA8C05A472A01BULL, 0x717F3475415AC5F4ULL, 
            0x144BF46BDCDA2E06ULL, 0x2BD84E2C65C08A86ULL, 0x109E82FEADC5AF49ULL, 0x5772E100B814845DULL, 
            0x6877119AEA09BCD4ULL, 0xF24211863F58873AULL, 0xB596595161DE329AULL, 0x4597B2FCAF36F63EULL, 
            0xE12845A35C5AECB3ULL, 0x89898BEF3D07A29BULL, 0x8A321C44FF1C0FE6ULL, 0xF95A896BEB60A619ULL, 
            0x8AE2BE272A08DF9DULL, 0x89DBEB7CBD0F6660ULL, 0xE72A6E79A681ECC9ULL, 0x49B3A27928942E2BULL
        },
        {
            0x4C14598BF6FAB193ULL, 0xAD4E7BF5B2EFE499ULL, 0x0F96BB2656322B88ULL, 0x6368A8524179A1C8ULL, 
            0x5E15D481306E1DEFULL, 0x5B625571B7D099CEULL, 0xBC48EA9A739D788EULL, 0x4D5BA3F7CCD9C12FULL, 
            0xC09D366F4F263DB7ULL, 0xE3FEF18FE2766DA0ULL, 0x2926EBD167E82A80ULL, 0xC056001ED4693D86ULL, 
            0x09E3A46BA87F4D83ULL, 0x7E3B4533F14544F5ULL, 0x58FEA0EC09449ECEULL, 0x73BDFA3DDA1A2AD7ULL, 
            0xBBC625BA71880E53ULL, 0x0F3BA0C32E63CE00ULL, 0x7957092E42EE5519ULL, 0x600E015F0514A779ULL, 
            0x88916F4EA334D172ULL, 0xC6A9A904F3246979ULL, 0x91E632AE84CBD59FULL, 0xC9F99A075ED541D1ULL, 
            0x7E2A7802E5B345BEULL, 0xAAC2E36DADBF5947ULL, 0x73D0F9EC4D760BD4ULL, 0xACBD70FD5D33BC31ULL, 
            0xFA281D3F9FD02C21ULL, 0x347114F43F7C57C3ULL, 0x464246289717F029ULL, 0x005A8F7975461744ULL
        },
        {
            0xA15C9F65F057AA06ULL, 0x9FAAE50D9BCC699CULL, 0x2DB917FE83196943ULL, 0x1022E2B2D5433BD0ULL, 
            0x43053973B21E4703ULL, 0xEB261E5937160B60ULL, 0x04F222B962938AE7ULL, 0x95DF038350EBF84BULL, 
            0xDA700B58D3EE6015ULL, 0xCF8E50FA59CD427CULL, 0xF5A8516A1460176CULL, 0x2B359E90BB19CD36ULL, 
            0x517A1A24A1AE1415ULL, 0x00733CB7C11EE32DULL, 0x5FE6632C9E424A8BULL, 0x62BD32BAC02C38CBULL, 
            0xE14BF55ECFB07EF9ULL, 0x3DDF5AE8CBCDE39CULL, 0xAA25218853F0BCE9ULL, 0x900C0F56C70D501EULL, 
            0xB213384C55EA2FAEULL, 0x35851197EA9EBB20ULL, 0x9BD90BA186712AB7ULL, 0xBD5E595D11B59B45ULL, 
            0xA7BDDDD8A4F9304CULL, 0x951F2251AE3BD2B7ULL, 0x29C738BA9C37FC53ULL, 0x4E31C91B2DCF6944ULL, 
            0x73E32C674BAE7471ULL, 0xFBC87BDE25D78368ULL, 0xF87C96A3359B33CEULL, 0xC6E64504A1618C45ULL
        },
        {
            0xAFF42853207D8D4EULL, 0x9FF0D05827DADC13ULL, 0xE9E305ABA9DF0322ULL, 0x801480EDFFA6DC5BULL, 
            0xB869E20D6F29327CULL, 0xA9A70411C4FED800ULL, 0x4E3D952C734BA63AULL, 0x0CC2DB0F23AC5538ULL, 
            0x943B5CDA5C401E99ULL, 0xAD2851F604102A9FULL, 0xBB8D8007DF5FD292ULL, 0x6B96D0ACBFF291E8ULL, 
            0x886FF2AA7F970E52ULL, 0x7F364991A4244F28ULL, 0xD1CB0DCD1F408752ULL, 0x2988DB60693B5DB8ULL, 
            0xF835828032E37B90ULL, 0xB4A11C26758B905EULL, 0xDC00537421EBE1B5ULL, 0x6C7F65640F916173ULL, 
            0x2E74266658F1E2F3ULL, 0x00FFE025EFFF7082ULL, 0x316B6430149B576CULL, 0x01724AD03F7DE3A2ULL, 
            0x216EFB154DF03214ULL, 0x491225CB196286C8ULL, 0xB5511FA38A7F0D4FULL, 0xB46E9700E03231C4ULL, 
            0xF4E4E6427D4751DEULL, 0xA5F94A42206B2E24ULL, 0xB09CE142FAACB9ABULL, 0x62EBAD9D7D5E86D4ULL
        },
        {
            0x54C0D68617794ADDULL, 0x0A0BD6E180DFA93DULL, 0x7F5F147AA3D211F9ULL, 0x026D58F04604DE9BULL, 
            0xC1CF2B2D7629BD98ULL, 0x31A830233010BD4FULL, 0x4DC060C2A3F6D9B2ULL, 0xF897177C68C4B00FULL, 
            0xC6E408B146B213EBULL, 0x209CD7C83F59CBBBULL, 0x039F8A64D4D8D9C9ULL, 0x6B82B683363EA251ULL, 
            0xCD3DD12BF314638DULL, 0x755CC3D5FFA8F587ULL, 0x15F45B28C3F151F8ULL, 0xA4FCF29FFE1CECD5ULL, 
            0xD29E694A4D75875EULL, 0xC46F40141859FB8CULL, 0x5AB25D9F82C1823AULL, 0x820BAEBC82563DB2ULL, 
            0x64A32661619EC277ULL, 0xCB5C2875D050845DULL, 0x9AA1CC9A44181B28ULL, 0xCA47CD7C690CB38CULL, 
            0x50BB717B111CF120ULL, 0xE350973BFD846F8AULL, 0xCB76C5AA347B62B4ULL, 0x6C9BF5DACC375ABFULL, 
            0x6241523ECA39B487ULL, 0x09BADB2B01AE735BULL, 0xAC28CAD728116DE1ULL, 0x52702862ACB651C2ULL
        },
        {
            0x9B605A4DF0CE643CULL, 0x5DB56E28A31078A9ULL, 0x91992183CBAE9BA0ULL, 0xEF7E6B4F6A8DC551ULL, 
            0x62379CD0F88434F4ULL, 0x3CE4E1128947D2BDULL, 0xA41A1ED362151D1EULL, 0x718C8F3B5100B00CULL, 
            0x0B19DF3D2BBB5548ULL, 0x35AB78EFA5F01710ULL, 0xCE7A026383DE72DCULL, 0x6AB4B7C53F8125E2ULL, 
            0xF41502DF235D0F16ULL, 0x0C6F2C9A9B64DD38ULL, 0x326A5EC7C14A3668ULL, 0xCFFA24561F964A2DULL, 
            0x800214413BA1A39FULL, 0xDC48BF9FC2FE6D1AULL, 0x660EDA7843FCFABDULL, 0x1CD7C0A4DA19BEEFULL, 
            0x1A3CB17E22A1D7A1ULL, 0xF70DF99EDC6FB4DAULL, 0x9A4BFC7920D8BD5CULL, 0x1EA7B8CBA91F81B0ULL, 
            0x96CDBA35A1EFA6EBULL, 0xE9049FD72304D282ULL, 0xF2E42FC74FE99929ULL, 0xAD55F8D0CBA448FCULL, 
            0x704CE68A02FAC8EFULL, 0x1FFACF172FC7740AULL, 0x51B636E67785C5E1ULL, 0xB79EF9C94EC17D9AULL
        }
    },
    {
        {
            0xE1BB04E3A179DC56ULL, 0x6E761177941E02AEULL, 0x306EC4EA93C11AC1ULL, 0xF7527677125FCD75ULL, 
            0x409C3B49BCD29784ULL, 0x74ECED7D2592C92AULL, 0x0022493A8210C0ABULL, 0xDC21AB747AA3AF11ULL, 
            0xEB847F694B4028D7ULL, 0xAF2A4A81B661E3BFULL, 0xECF66DB09B2C5E0FULL, 0xC4FCAA915A5537C9ULL, 
            0xB741AFF45B573008ULL, 0xC6C3EA42E41DAAA9ULL, 0x9ED420180C2A740EULL, 0x062E7705AB66DF39ULL, 
            0xBD3218A1B1B3EA91ULL, 0xB83F0DBA9C6E85A4ULL, 0x758C8B2035339ADBULL, 0xAACA64937CD41C83ULL, 
            0x83CCA022349995C4ULL, 0xAC42608FD5BCB207ULL, 0x81512A62285623DCULL, 0x43AF7B3152CEB96BULL, 
            0x0A20671A6147E340ULL, 0x2664DE17F81068C0ULL, 0x7CA486ECBB89D163ULL, 0x4591D562E8FDFD18ULL, 
            0xF944F84E85DFF213ULL, 0x42CEB8DB39483BD1ULL, 0x951933C37AD68C9AULL, 0xC905CF18519903A0ULL
        },
        {
            0x4C957EDB5E07FA98ULL, 0x2E5D6BE9E1CF6240ULL, 0x9943F82FE02A0EECULL, 0x63CEC770B810B286ULL, 
            0xC779728430E3D607ULL, 0xB5A0F15A06ED4452ULL, 0x30643AE7CC42799FULL, 0x184B56479F20D4B2ULL, 
            0x57B0E1A805DB3B47ULL, 0xC23762026BEC7252ULL, 0x2976AC5223230E8FULL, 0x1DED94A38931FEE7ULL, 
            0x2D46F242E973F9A3ULL, 0x2D8D2320CC4DA088ULL, 0xDA030A005307CA77ULL, 0x5FE2B175FBB875BCULL, 
            0x9AFC5E83D915B600ULL, 0xB26B1E60667C0744ULL, 0x8181064694088A04ULL, 0xFC0DFBB546A78B55ULL, 
            0xF94B0652CFDF5EDEULL, 0x302567ACFE94FC71ULL, 0xE78F09F17D1AF5EBULL, 0x13F22E37AEED717CULL, 
            0x1B06647BD3BB09E2ULL, 0x65ADA36D70DE3C85ULL, 0xBE0440F13FB6EB75ULL, 0x8EA6F144452B6AFFULL, 
            0xC93A3EAD1573F03FULL, 0x1C61093D7A6E7C1CULL, 0x1BEF3292B2499EEDULL, 0xC005264A3A904719ULL
        },
        {
            0x43646E461829E248ULL, 0xD433F5CE6D8F6B00ULL, 0x1D2B3580D4A8CD73ULL, 0x9C7B606A9138833EULL, 
            0x34AA53A6BE027A6BULL, 0x45DAA6DAFF138D44ULL, 0xEC6EACAD37365B6AULL, 0xBFCB5DF98783CF64ULL, 
            0x1576E1935C645AEAULL, 0xF547810228917BB6ULL, 0x80EA1D78215ACBB6ULL, 0x5D550EE75CB94108ULL, 
            0x64A4B4BFCE29DBB0ULL, 0x9B8DC214A3039132ULL, 0x9651DA0622F92235ULL, 0xDFDBD28239FFEB6EULL, 
            0x34505471FC3FF72FULL, 0xB46F908828C9AF52ULL, 0x5CAF628DA9733B5CULL, 0xE412101EE664D3AEULL, 
            0x998F35CF3A8A1BA7ULL, 0x224D0EA5811160CFULL, 0xDB6A760FD17957FFULL, 0xD58814C6AAD4831AULL, 
            0x856099977AAF3A62ULL, 0x551D7BE0400CE27FULL, 0x7AEF752E3ECBAC68ULL, 0x5EDA69F21759B9C1ULL, 
            0x337B2A67505258EAULL, 0xE6574C0C99F1B0D0ULL, 0xB01EAAF99A602FEEULL, 0xE616304B1126E5BDULL
        },
        {
            0xC87276A784C08D2EULL, 0x6BFA8334972FFFB0ULL, 0x8519CCE5DD2AE815ULL, 0xA28B9CD5B497960EULL, 
            0x5103F483E1809D28ULL, 0x96C26D3766C84EC6ULL, 0x665BB96EE1ECCB75ULL, 0x2D534B4B16885BF8ULL, 
            0xBF7E5616F635A697ULL, 0x2C452030FFDF3F4BULL, 0xEAE2B91683F50C70ULL, 0xC4FEF7C3EC23D2CBULL, 
            0x21945A7124B6F8D3ULL, 0xF4329AA4E84414F5ULL, 0x9E2F69EBCF0204E5ULL, 0xBB777F5E461EB72CULL, 
            0x467897CAA08195EEULL, 0xF9289730C6A7649CULL, 0x8A27D5136A4F0845ULL, 0x114CF15A46DAD4F2ULL, 
            0x581CE9C723EF68D4ULL, 0xF47BD3C8CE7FC53AULL, 0xD6D16C6B1FCC9D4EULL, 0x940065417472761BULL, 
            0x6BDEA7FFA88EED7CULL, 0x5B3E740BB0E7201AULL, 0x0163B4DCA311498BULL, 0x08A207D0E4679E8AULL, 
            0x57F9FB157D200F83ULL, 0x55D3BFA867012320ULL, 0xCFB54430A94A90B9ULL, 0x95B004D7877AAC46ULL
        },
        {
            0xAE245140D3266A3DULL, 0x25C7749F86C5A2FCULL, 0x2ED7F6E2128662C4ULL, 0x33B635A772FD2383ULL, 
            0x1634B174C557B5B8ULL, 0xADD69C08CE706503ULL, 0x6886B784AAA22123ULL, 0x16DE49CEBEF006BEULL, 
            0xD456ACB265F8F1C6ULL, 0x572A05A24A0D2314ULL, 0x4E2FBDAD50604ED9ULL, 0x32A7E7373E750510ULL, 
            0x8D576B455D7DDEE7ULL, 0x89FCF48BC24EE7CAULL, 0x781C25374CB874C4ULL, 0x69CA7911EF875A6EULL, 
            0x219DD4BAD1C7C3E9ULL, 0xADA4C5512D00D835ULL, 0xE8F6221D4BC107A1ULL, 0x860979ADF108C401ULL, 
            0xAB52023B28CED9F9ULL, 0xFD3014BA6E6A0A87ULL, 0xE3CC4C869F357656ULL, 0x89058B5F7B32E337ULL, 
            0xAD2F2E5B06A4D40BULL, 0xE4F39011AC355AB6ULL, 0xA922F377270C0154ULL, 0x805D401DF1895BADULL, 
            0x76DD02693F950BBAULL, 0x5C4535E80FF418DBULL, 0xC89D7902D256A9C6ULL, 0x1E7AC81D72B22BF2ULL
        },
        {
            0x2FCBBB61F41EE7F6ULL, 0x0E749D87C157995EULL, 0xBFE6E96A8F225AEDULL, 0x110C510697CA16FEULL, 
            0x8BDCF634B472744DULL, 0x88CC7E976A56B825ULL, 0xBCF64C60D5A8E381ULL, 0x1DA4312FDCB5C40AULL, 
            0x80AF33B6164A8DCEULL, 0xA3F3B7A6E62C07F0ULL, 0x2566005C6B9A6C2CULL, 0x54A651C6372F1D91ULL, 
            0xA986B6B4AC225BBEULL, 0x9FFF28D4E2C9B5DCULL, 0xE84C42EF75677DB6ULL, 0xF71E9FD1BD4A3336ULL, 
            0x52882320F6E5F8F5ULL, 0x33BF8C0030C15964ULL, 0x3ECE21607BFA4397ULL, 0x95E36665BECF0985ULL, 
            0xCD6A552B80D3BE71ULL, 0x21DCFF58C0C6AC57ULL, 0x5BB8399DE3F3BA5DULL, 0x8E72EB52FD46F26AULL, 
            0x57B45AC569D4EEE2ULL, 0x5232CD9C4538BF5FULL, 0x5CF073A7ADE9F638ULL, 0xF84551A77CD18591ULL, 
            0x9A5CE47C743D4EB2ULL, 0x6B33316503943A82ULL, 0x5ADFC30B2E369838ULL, 0x0170B08A51BFFA01ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseGConstants = {
    0xEE8202121E036132ULL,
    0x8A6ED4CC3F0E5CEEULL,
    0xBF05D6E8396EA865ULL,
    0xEE8202121E036132ULL,
    0x8A6ED4CC3F0E5CEEULL,
    0xBF05D6E8396EA865ULL,
    0x9513369C309674CFULL,
    0xE897980688C2A941ULL,
    0x84,
    0xAF,
    0x79,
    0xD8,
    0xE7,
    0x6B,
    0x70,
    0xCF
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseHSalts = {
    {
        {
            0x2C1D0D0AE2CE4DCFULL, 0xA140472E41964E54ULL, 0x15F3436DAAED104AULL, 0xE96C57E09F387815ULL, 
            0x3494148ABE6D3F0AULL, 0xFCE600E84A6938FFULL, 0xFF34C7F932CDFE4FULL, 0x4F4F1264C1385419ULL, 
            0x6D35D722A78B3560ULL, 0x753FA7D3BC129278ULL, 0xB59FBE4141252810ULL, 0x5894FC264EC09FE3ULL, 
            0x161BC2C2942F8464ULL, 0x1CF42166D5930029ULL, 0x37D71B51AF01EC0AULL, 0xB76721EE7329BB19ULL, 
            0x42AEDC333682C21FULL, 0x3C2E75B4ADF379BDULL, 0xB2CD19172926690EULL, 0x955C99D95B9E7E22ULL, 
            0x8D62918CF9072AE3ULL, 0x6D2625340473D624ULL, 0x39A055A63BE43770ULL, 0x6D915F6B41E217EAULL, 
            0xF22201075BD064E8ULL, 0x1ACAB86874B895FFULL, 0xA5EFC04090EC50EDULL, 0xCBBB6AC35F77D3B7ULL, 
            0xD39E5E581C8041A1ULL, 0x5445719B88B34A53ULL, 0x564F21068F13F72AULL, 0xD6B9695C5775C370ULL
        },
        {
            0x69231E89F0583484ULL, 0x9F0A99A47C6751B4ULL, 0x3618B55F68CB3A76ULL, 0x1D79F690F663B8B1ULL, 
            0x483AF154BF399D5AULL, 0x206367459E7B0646ULL, 0x64018B0C99DE32E9ULL, 0x2C95D58C3FEE1A94ULL, 
            0x68EFC6541DF05EFAULL, 0x4088CA6CDCCFB3F4ULL, 0x425CF797344B7991ULL, 0x00370E11F7A03916ULL, 
            0xCFBA11B7E627FE04ULL, 0x5E22F99082B29506ULL, 0x012AB70559BF2570ULL, 0x521B321AAEE8BF98ULL, 
            0xA4CD7E6FE6F7682CULL, 0x0A30A21257DB322DULL, 0x066092A5EA42DD75ULL, 0xBA77D5BF6052AEA7ULL, 
            0x154380CE369D4939ULL, 0x8BEF4DFDDC3EC202ULL, 0x9B743DF59E55BC3DULL, 0x683F958FD33E9754ULL, 
            0x96EDF4F7759EFE12ULL, 0x2F538646D3FC5D10ULL, 0x50CA2F1889B3A0D0ULL, 0x9EC1F3227CF5EDA2ULL, 
            0x208680C53C983C00ULL, 0xA7703AB1F058812EULL, 0x0450F4C92DC80900ULL, 0xC830F205518F9533ULL
        },
        {
            0xB08C0044AA3BADB0ULL, 0x057DF36EE3906222ULL, 0x3ED8966699B23FABULL, 0x816D72BB89A7634AULL, 
            0x6A52DD3DF1C974A1ULL, 0x7B0061116050FB1FULL, 0x1D1A34C45DC96AEAULL, 0x3A7BB53047DCBB03ULL, 
            0x7489B9F711F45B77ULL, 0x51DF19C74717E2A4ULL, 0x168CBF12E2AE275CULL, 0x0AEF75F488251480ULL, 
            0xC359D9E3DCFB3445ULL, 0x0E73AB9ADCB80A3FULL, 0x3159FFAA1D813F36ULL, 0x9CFAC9486897F1EDULL, 
            0xC6CAFB8688AFD66AULL, 0x032A68F5EA16AAAFULL, 0x70AD5D1E7F9ACE4EULL, 0x3BD80CA86AECA71AULL, 
            0x4B1F973F20FFC32FULL, 0xD93DA65FDF9F3E6BULL, 0xC0A6D9CAA936F00DULL, 0x5D6B376ACB4A1155ULL, 
            0xE57E624A588B38EBULL, 0x696BF0E7176347DBULL, 0x1679EAE7E917709CULL, 0x1790509FA777B41CULL, 
            0xF861512EC6172A7FULL, 0x0C2DC60FE7E73F12ULL, 0x9CD39F7741227939ULL, 0xFDEDF0E075E27CDEULL
        },
        {
            0xB16110D3DF512995ULL, 0x7C3E7E9D460466BEULL, 0x3AEE15F7B1315305ULL, 0xFDCAACC03C06A275ULL, 
            0xA807A0371E9B8881ULL, 0xF0F4009CD1588FE9ULL, 0xC771F1D700B548FFULL, 0xA662CEF4363797DBULL, 
            0x88FD3403FDF676C0ULL, 0x623FFCF5F92A710AULL, 0x834C268C30814D51ULL, 0x78FFBDFDB115039BULL, 
            0xFF784F0F8D028D40ULL, 0x30D98906D9A2DCAFULL, 0x3433EDC79FD52168ULL, 0xCC35E70A050CDAF2ULL, 
            0x30C90CDFB5CFD49FULL, 0x6ABA03A5CCF711A1ULL, 0x9497B95172AA617BULL, 0xBF76021998AD4DD5ULL, 
            0xB1A62DE6F2436633ULL, 0x8B1071A1770BA053ULL, 0xCA7CD55376CF77DAULL, 0x081D5F1854DEBC1AULL, 
            0xE74F9FCDFDA401D2ULL, 0x491F23C84BB148EFULL, 0x80FC589572D4B37BULL, 0xA011F5445C2185E9ULL, 
            0xABF48847035FA097ULL, 0xBBB5EED93BA545CFULL, 0x20A810049E13A5C6ULL, 0x4C542A8BC05230DDULL
        },
        {
            0x7D9551F1A3C10720ULL, 0xD40955AC8B5A5EECULL, 0xE64FAFDEAE230225ULL, 0xD9D5E8A6AC5462F0ULL, 
            0x01182BC450E1447BULL, 0x520E77E01BE9A248ULL, 0x96C6DAAB27319749ULL, 0x58F8B71BBDBF4CF2ULL, 
            0x04324A19F8C6BAC2ULL, 0x420D88A7DC7EC8AFULL, 0x8E96A30D681438B3ULL, 0x62D195D3C22BBC7CULL, 
            0x6A37ACB74A4DC576ULL, 0xC4ECD10196E82287ULL, 0xC0A03F1C1FDAEB54ULL, 0xBE7C08423D52F106ULL, 
            0xDC1F8AC291F23355ULL, 0xF08536FBAAB2FEDCULL, 0xD0A610AA5A9C02AFULL, 0x65D70A4EFE1CF1C5ULL, 
            0xAA042A1A7D259B6DULL, 0x96BFC51360D7BDF0ULL, 0x48061BAE385D37E3ULL, 0x673283824E848D1AULL, 
            0x0B261F218626AADCULL, 0x76C0A00049CA5075ULL, 0x80216FA03C87BD62ULL, 0x4C275DCB42C52DCCULL, 
            0x7FDB838B179CC122ULL, 0xD2C297984F4082BEULL, 0x887DF6408DE37DFBULL, 0xFC7CCB5EBAD9992CULL
        },
        {
            0xBC0EDB376F9345FAULL, 0xA843FFA705512667ULL, 0x8785548359E4B79CULL, 0x71300121DAF498C5ULL, 
            0x6E16E50211FBB222ULL, 0xDFDC68C3B6968565ULL, 0x78BCCCFCF0607E70ULL, 0xF45B9130FF60E042ULL, 
            0x4D3CD49E88A176DBULL, 0xCADD03D9A575A170ULL, 0xE1DC4DD9422DFEBDULL, 0x65111ECB138F42F6ULL, 
            0xEFAF12DAFE6A831AULL, 0x7222852FC9C25BE2ULL, 0xE765E8C310928CEEULL, 0x436F7873577BB3ADULL, 
            0x1B386660C8D504B9ULL, 0xA2F1E917B1570452ULL, 0x2A811B127910CF07ULL, 0x8387C5050AB77AD5ULL, 
            0x16A1E27BCF207E5AULL, 0xBE23F854B45D7D43ULL, 0x73552800571D8872ULL, 0x96ABA57F65ECBA66ULL, 
            0x1873C24310C5A068ULL, 0xBBFC300A2E9E60B9ULL, 0xED237C00576F891CULL, 0xE871EE5F638C36E6ULL, 
            0x2BC361728DA21F4AULL, 0x1C23E75F9A87C6E2ULL, 0x8979B58D272E8957ULL, 0xD63AC6108C6D01CBULL
        }
    },
    {
        {
            0xB380EB7088D9536DULL, 0xF0DEA78DDBFFF6ADULL, 0x0F92325CCFDCEFA0ULL, 0xA722AE69D1467F5BULL, 
            0x129FD1EB4F9E40BAULL, 0xA64D8E2E46F1679DULL, 0xA7D5F70AC00F3FE7ULL, 0xD4B812D626663CC8ULL, 
            0x951E6541CA9BCF66ULL, 0x6E2B143549D4124FULL, 0x8B4987F09C0C543AULL, 0xEDC9F96A981F1B3BULL, 
            0x6AE7D3F8DC119840ULL, 0xA96248953EAE9915ULL, 0x37E56EB088CFE2C2ULL, 0xACE78131616E17FAULL, 
            0x0AFB52AD8BF9E223ULL, 0x777ABA0373ED49B1ULL, 0xB4C9B6AB26057C5BULL, 0xAA6DBDFAFE3CBD5DULL, 
            0xFE4E5B378EBD87D6ULL, 0x143E488533D143E6ULL, 0xD6F2CBE4109F847EULL, 0x9430EE04F2356185ULL, 
            0xF317EEF666D9DAFDULL, 0xB013B7987F3F38C4ULL, 0x96D030B53A60DF41ULL, 0x5ED4D1F957B1D732ULL, 
            0x688A96F10E67C10FULL, 0x399F28900DAD0A21ULL, 0x7332023F5B948BD5ULL, 0x8F4360A0CC23FB36ULL
        },
        {
            0x8FFA4BB91B31DFCCULL, 0x83F0F0F374C7D320ULL, 0x9B29F0E1B30794CAULL, 0xA633569E936C11F8ULL, 
            0x2F220DFC583F6B9BULL, 0x73ED7A55AA01F8CCULL, 0x0A289501FC17A1E8ULL, 0x8706CFFFBCBA7A13ULL, 
            0x4EDD6F09B8547D6CULL, 0x02F2ED2DC96A6CEBULL, 0x39810804B23900E4ULL, 0x37DD23541810349EULL, 
            0x80E690AD3CF1FAD3ULL, 0x7202C6FBAC0EFE19ULL, 0x7CA79F2B9767C6EEULL, 0xB21E3CF9E240A4F7ULL, 
            0xC529C7A9E57D2741ULL, 0x41DE38A60ED2DBA6ULL, 0x53563E959308FC6FULL, 0x889578FFED775CE4ULL, 
            0xB6A23CBB916DFA56ULL, 0x10C694DA697B7743ULL, 0x13A5E632C272C5EBULL, 0x4B8844109F8DB7C7ULL, 
            0x0BAF259CD361983BULL, 0x505D79745DE780FBULL, 0xBEE16FD2083DA8ACULL, 0x03E3D1ADEEEED873ULL, 
            0x2F2122046CB67601ULL, 0xBFD20CC0513BCEFBULL, 0xBC8B60A6542173E0ULL, 0xE732C94D956D72EEULL
        },
        {
            0xC0BA148551F6C2BEULL, 0xF19A9C1B734D4786ULL, 0x5DC21EE7711E766CULL, 0x8FDCCEE8D41746D0ULL, 
            0xE10146DFD062C49AULL, 0xA0C2535696F0599CULL, 0xB585296FA5275CEAULL, 0x0AE877BAE592FAFAULL, 
            0x2D37E7E0D62AEA3BULL, 0xD4E7C725C5DA240CULL, 0x4FA6471ECE0AF9EEULL, 0x793B6EF0C9A1D2BEULL, 
            0x84F6F4BB67D3322BULL, 0x634933E6F080F163ULL, 0x19EA73039441A4F2ULL, 0xB673B81D73FA2243ULL, 
            0xCA697635C4382949ULL, 0x3DEFD666D8C94324ULL, 0x8E87D88C5A935199ULL, 0x62A376E8C97CAF13ULL, 
            0x25A15DB0F3D522ABULL, 0x320DC4BB7BCB5D3EULL, 0x89F185F321D0F751ULL, 0x0C0279F5A3632CB5ULL, 
            0x694DA543F91BAAE7ULL, 0xEF4D54F4D835C6A3ULL, 0x8E49CF5C266C6345ULL, 0x48080BA813777B29ULL, 
            0x88E75F98CA5D50DCULL, 0xF20EE4F3CD684E85ULL, 0x02E80632F56F408BULL, 0x413EA40AF3818B1DULL
        },
        {
            0xDAC78CBCB1748E71ULL, 0x736F1D0C7FA8BE35ULL, 0xFCDC89ED64965557ULL, 0x59951F616480AF7FULL, 
            0x0F1EA3226D6D2C02ULL, 0x69E9CC76DC523FECULL, 0xB0949E0FD86CF44FULL, 0x77068CF0A5A3275EULL, 
            0x01AEA0FF676379F4ULL, 0x95505ADA65CEA1B8ULL, 0x343323000B2BAC07ULL, 0xD3306E55A5332080ULL, 
            0x4ABB264ABA20FC61ULL, 0xA671C152920B02D9ULL, 0xCAB00C173B733104ULL, 0xA4BE6F1049B944F4ULL, 
            0xFBE8D54903D223D4ULL, 0x35A617A5CDECBA27ULL, 0xEAB58E1D0E23DF28ULL, 0xC68CE0B54B68D4D1ULL, 
            0x831C044CC67A1D39ULL, 0x60B90C07D5A94604ULL, 0x81CBACD32D27BB27ULL, 0x5288761FEBF6B6ABULL, 
            0xFF746DC57CB63FE2ULL, 0x8B9190E3DDE20D79ULL, 0xDC562A29CA782EC7ULL, 0x0BC01232C94944B8ULL, 
            0x7A387E9CB034AB19ULL, 0xBB54885638911104ULL, 0x01191F93EC602BF4ULL, 0xF8249DDD3B3C02C2ULL
        },
        {
            0xB4D5285A1D9F75FDULL, 0x46A3BFF2E555876AULL, 0x40DD7C95AE688B12ULL, 0x3F15FB091DC5E844ULL, 
            0x77957AB9F7FA6496ULL, 0x64F8BCAED349CE65ULL, 0xBEB5F263A4D3D297ULL, 0xEB9231754A9E9991ULL, 
            0xCD93FC375275EC0DULL, 0x3CEEEEC268CCA0E5ULL, 0xE340060138A81DF9ULL, 0x86A4392FA4B8C162ULL, 
            0xC4A913E87420CCBAULL, 0x669594F61ACEA6ADULL, 0x6464A7A1F2675118ULL, 0x1EFBF3C8CFADACA3ULL, 
            0x9A30BE292FFB31C7ULL, 0xC93E7A1CF3980EDEULL, 0xE38B0509E71B476CULL, 0x54B3285A4E2ED73BULL, 
            0xAC534E831D39BCB5ULL, 0x3C96982FC9C48B82ULL, 0x35C30A2A87BAC9B7ULL, 0xED0C9F5D0123E2B6ULL, 
            0x77C1C600BF5A2A55ULL, 0xC5C318F03C96C302ULL, 0xC6F9ADBF2E35283CULL, 0xDBD4E55B180D295AULL, 
            0xD0469B81F15E1352ULL, 0x765540B4CBB6D5C0ULL, 0xE11CD115CF5A4B04ULL, 0x0E03123628808FD3ULL
        },
        {
            0x6DC9E46F960D6BE7ULL, 0xE55FB370F2842FB6ULL, 0xB42C4B1A64AB6EBAULL, 0x179B254E562E68D8ULL, 
            0x1DD00DB3744A141CULL, 0x8EA6CD9BF81CA3DBULL, 0x3553810007DF5E79ULL, 0x1771ACE4252FBAE4ULL, 
            0x6728B302CEF38A18ULL, 0x69D7AFC78D5AB23AULL, 0x57B61414A1A2A2C8ULL, 0xE9FA81A904BA00E2ULL, 
            0xF172499A8E51F576ULL, 0x138573BB1AB24FF2ULL, 0x7C6F848CC2DA991FULL, 0xB80AB060015BF6BEULL, 
            0x40D84BC4A3FDA73FULL, 0x8C9DFEE001CE6356ULL, 0xB6C57A4EF7095870ULL, 0x8C8F8C5D38530077ULL, 
            0x992EC79EE904F20AULL, 0x0D17BBA8780AA271ULL, 0x2854DC96D81265B9ULL, 0x54E5A3D89E5D7D14ULL, 
            0xD091E4047ECF6E5EULL, 0x9399B3F9CCF99BA2ULL, 0xF83718E2ECD3852DULL, 0x40A07D0BB380CC92ULL, 
            0x8B798DCDB8E07577ULL, 0x2FBD1B55A86EBEB8ULL, 0x736CE21071CD1884ULL, 0x88D4814C3509FF2FULL
        }
    },
    {
        {
            0xDB5087FEA53C0E0BULL, 0x608AB2F41F984920ULL, 0xAE150860B229CF00ULL, 0x3D6C16E2DFF42C1EULL, 
            0x6CCCC070E3BA7ADAULL, 0xE2A538DE273C817CULL, 0xE7281FE89AAA0D8BULL, 0x00FF15917D315C11ULL, 
            0x3683BA99745F0626ULL, 0x2138DB19F0872377ULL, 0x46979364FDDEAA85ULL, 0x339CF1FED2C079E2ULL, 
            0xE7001A50E3381DD0ULL, 0xBDCCBFE823F24112ULL, 0x34F69D3CAC609CCDULL, 0x48A31C2801B759D7ULL, 
            0x64C4ACC089C0CAAAULL, 0x1A8B295BA7D89E3EULL, 0xA554E7D6DC64ECCCULL, 0x49C6129BCF0DD449ULL, 
            0x74EAD958A19EAECAULL, 0x2A2F571FC42E4E5BULL, 0x7640D1AE29433878ULL, 0x42F26EE3721BE890ULL, 
            0xF9B24939D07B5ADEULL, 0x33B3AD915236921EULL, 0xED4F1D6D10224505ULL, 0x9D9A47397A593BF9ULL, 
            0x43096E0DEC17C8E7ULL, 0x9C9F4260E5466273ULL, 0x0B111192B8AF1CB4ULL, 0xC165C4FEA343C366ULL
        },
        {
            0x9887F60A3784E807ULL, 0xC1E35FB8BA71A36AULL, 0x9710C36B61F8181DULL, 0x24A474E222F3A6FEULL, 
            0x62813BE9365EEE41ULL, 0x966A7ADBEB7EDD58ULL, 0x0B337F41E511CBAFULL, 0xD3104CC2D9FFE4A7ULL, 
            0x2CC6C951B0B3E098ULL, 0x6EC67F6FCBE89CE2ULL, 0x167F79E248BD75A8ULL, 0x92B33B49ABDFC6B7ULL, 
            0x07E64B96BC91A0E9ULL, 0x23DFDDCA045B2936ULL, 0x6B29F48623111040ULL, 0x7D6505F7C06F9BB2ULL, 
            0xF8AF7E965EC52FA9ULL, 0xF446BE32597939ADULL, 0xACF3B847CED60CDDULL, 0x5A1B03D8FB1B8D45ULL, 
            0x543AB058A60D2CF2ULL, 0x7AADC14BF5BADE91ULL, 0x247007A9DBA05B28ULL, 0xB3955F53A5FF5CFEULL, 
            0x006A9E65B3095E9DULL, 0x9F81A08EFC199DA1ULL, 0x170D106A6DE4B668ULL, 0x933371D4AD5E27EEULL, 
            0xD10D7A5254D41FF6ULL, 0x20F6BD32EF49D694ULL, 0xC8F39FB231ABD328ULL, 0x23B1633F15D98F99ULL
        },
        {
            0xCCBC976D7FA57CE0ULL, 0xA873AAEFEE472FA9ULL, 0x2E7306C1FA34B745ULL, 0x227AFB2908EB3642ULL, 
            0x0DA0A70C735CB5E6ULL, 0x97EDBCBA73290BE9ULL, 0x904E873D8FFA636BULL, 0xF890250F439BA369ULL, 
            0x3073AFFAD42063BCULL, 0xFE35EDA542FDF675ULL, 0xECB77B5B2A028391ULL, 0xFD670EEEF46DF59DULL, 
            0xA8F48D05DF54BD4FULL, 0xB5A641AFB1CF5937ULL, 0xFDFA726B2CC52E8FULL, 0x45A59BCE0853569BULL, 
            0x1CE54568B24C18EEULL, 0x1BCE8CBCF2A911CAULL, 0xA6879C76E5E14D52ULL, 0x053E43D841AC5407ULL, 
            0x6A8822669134677AULL, 0x7E1F75F224A4C237ULL, 0xF55C19C668590031ULL, 0xAABFC4526D8B373CULL, 
            0x490A932AB6F980DBULL, 0xFA5CF291C6F08A15ULL, 0x67F5DED055576375ULL, 0x4D44D0DD8E11ECB2ULL, 
            0x5077E76454B85E72ULL, 0x9F9E3DD7E11E6970ULL, 0x431C59991F9DABB4ULL, 0x73444D33DC01990EULL
        },
        {
            0x1CF554F8C07DC916ULL, 0x08B528F29273C858ULL, 0x7FF2DC6C9F90D9D6ULL, 0x59CED1C7AFFFF883ULL, 
            0xEEBE0D561DE15886ULL, 0xAA04D0DBB1B1A555ULL, 0xFECBA15C83903F66ULL, 0x9C60038EACECF211ULL, 
            0xD35986E5298D0383ULL, 0xE92DDB242DC58A20ULL, 0x0E6D4F4F68BB700AULL, 0x69B71BFF7808301CULL, 
            0xA579D1518CB8E495ULL, 0xF119E11CA272921BULL, 0x8E7A24B023DB4A0DULL, 0x0C00B6451D182B87ULL, 
            0x3B9CE7B753D580A2ULL, 0x8D688BBEC3568A4BULL, 0x7F9E9321B20FE045ULL, 0x79D2B59D3BE27B2DULL, 
            0x6BCEEE6DBFD56F28ULL, 0x6BC2EFB4C4A9EF83ULL, 0xB0FD69596365DDA4ULL, 0x2C78A2DE7BB7D08AULL, 
            0x504384425D089F0DULL, 0x93D269A6994F7EC7ULL, 0xF8491FD606B88D81ULL, 0xFC4B01422582B5C3ULL, 
            0xE5BE1A635A46B706ULL, 0xA750E582FEC10BE1ULL, 0x42F3D4ECE3370886ULL, 0x4277E47441DDF59AULL
        },
        {
            0xA0BBBF1C35F58559ULL, 0x1F18544AD9166D07ULL, 0x755509ED0E703227ULL, 0x1D0BB09077919651ULL, 
            0x6315FF744FEEA80BULL, 0x0936041CBA87368AULL, 0x97AEE4F1032BB10EULL, 0xB30C37BCF8215538ULL, 
            0xE0275BB4E0FB6A34ULL, 0x7AA64FA2445B993CULL, 0xC300E5A5B83C2EF0ULL, 0x6E331A1BEA605D90ULL, 
            0xE7DED484B0291ABCULL, 0xA679415C126747B2ULL, 0x6C945EE804B45227ULL, 0xE38DE4A460D1E6C6ULL, 
            0x698C97F79A7A0CA3ULL, 0xE893EF8ED35C846FULL, 0xD7D8C28B5CBF913EULL, 0x78C4FF128FBCE6C9ULL, 
            0x96D5458EDA4A160DULL, 0x473ADC9DE1F881A4ULL, 0x28F95FBD14378E6AULL, 0x016EFA1241228D4BULL, 
            0x49B0B4D359552DE8ULL, 0x18CD505C1997F089ULL, 0x3DB78502483F47A6ULL, 0xC59459745F6B983EULL, 
            0x33C83B11307448DDULL, 0xD7913ECC2CC45F91ULL, 0xAFBAEE4DDD58C2AFULL, 0x161954850E52EBE1ULL
        },
        {
            0x5EC19CB800D6C3BFULL, 0xC7E8B597AB16BC90ULL, 0xC5BD7A5C02EFE7A1ULL, 0x4D80ABC4D6F82646ULL, 
            0x7E77B691A0D954F4ULL, 0x1A26B6532C188440ULL, 0xDBC30BF123F113AEULL, 0x13E256E77022171BULL, 
            0x1836FD7254F8AB32ULL, 0x6C47940BDB724627ULL, 0xF9CBAFC7557073ADULL, 0x61246A986EF40FFEULL, 
            0x5347523E438436F2ULL, 0xF2847D18B8AD3403ULL, 0x962267A4039D67A7ULL, 0x678E4A8E63A1A375ULL, 
            0xA7FF0A73786D399BULL, 0x6A6E10C03363C1CBULL, 0x26479EDF4B0FDB68ULL, 0xB54ED343392E8A78ULL, 
            0x839AD5F966240A1CULL, 0x84C57F9F41DBDE70ULL, 0x5202B78560160487ULL, 0x1F9EDB66B05B9E94ULL, 
            0x509347738AB4E145ULL, 0xE9FFB2534829DA7BULL, 0x5AF4F75AC136E94DULL, 0xC418E1457E4ED6FCULL, 
            0x75196A0E9ED529BCULL, 0x905C525B7BBAADAFULL, 0xB87852943C4A31CBULL, 0xD0C65F896504E5AAULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseHConstants = {
    0x4AE4D0C1AA83EA22ULL,
    0x81BD591B3EE0A866ULL,
    0x3CC2794A2CD206ECULL,
    0x4AE4D0C1AA83EA22ULL,
    0x81BD591B3EE0A866ULL,
    0x3CC2794A2CD206ECULL,
    0xED5BB74267E800CCULL,
    0x5D4F9B18EC4BF150ULL,
    0x86,
    0xD2,
    0x15,
    0x01,
    0x35,
    0x6E,
    0xED,
    0x9E
};

