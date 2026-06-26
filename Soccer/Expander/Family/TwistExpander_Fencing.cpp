#include "TwistExpander_Fencing.hpp"
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

TwistExpander_Fencing::TwistExpander_Fencing()
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

void TwistExpander_Fencing::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 14268188276281933805U;
        aCarry = 14482001223846025283U;
        aWandererA = 14508072672778531123U;
        aWandererB = 16962062646174184029U;
        aWandererC = 16691821566390364566U;
        aWandererD = 14069461779439621873U;
        aWandererE = 16099153947316133201U;
        aWandererF = 9227524994930901020U;
        aWandererG = 17387615057329103243U;
        aWandererH = 17277493717128348208U;
        aWandererI = 12182119804718463655U;
        aWandererJ = 16204165180234995259U;
        aWandererK = 12681942552710078441U;
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
    TwistExpander_Fencing_Arx aArx;
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
    TwistExpander_Fencing_Arx aKDF_A_BArx;
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
    TwistExpander_Fencing_Arx aKDF_A_CArx;
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
    TwistExpander_Fencing_Arx aKDF_A_DArx;
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

void TwistExpander_Fencing::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14413641865573102977U;
        aCarry = 11762163381682939453U;
        aWandererA = 13201597145848532524U;
        aWandererB = 10719169085988303456U;
        aWandererC = 9468802795617021992U;
        aWandererD = 12448351986647686619U;
        aWandererE = 13564434456050714531U;
        aWandererF = 9280024809368643196U;
        aWandererG = 11829978743710886687U;
        aWandererH = 11970309469612358302U;
        aWandererI = 9983824764424382005U;
        aWandererJ = 15903008445454584507U;
        aWandererK = 12981143698770960225U;
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
    TwistExpander_Fencing_Arx aKDF_B_AArx;
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
    TwistExpander_Fencing_Arx aKDF_B_BArx;
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
    TwistExpander_Fencing_Arx aKDF_B_CArx;
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

void TwistExpander_Fencing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9EA16E26C72B1F4FULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xBA6721DCA6E22D43ULL;

    std::uint64_t aWandererA = 0xD7AA86051B01E5CBULL;
    std::uint64_t aWandererB = 0xE9C6C431B2E58BF1ULL;
    std::uint64_t aWandererC = 0xCBDA56DEDBC22F53ULL;
    std::uint64_t aWandererD = 0xEB86056C581C4BF9ULL;
    std::uint64_t aWandererE = 0xED9DF53E7F9B7381ULL;
    std::uint64_t aWandererF = 0x9D6E8CB5CB3E1C05ULL;
    std::uint64_t aWandererG = 0x930098FDDE3EE668ULL;
    std::uint64_t aWandererH = 0xD4F9AB4DBCE51924ULL;
    std::uint64_t aWandererI = 0xDD11F869C2D92169ULL;
    std::uint64_t aWandererJ = 0x885225AA88459F8EULL;
    std::uint64_t aWandererK = 0xE8C03338EC973C14ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Fencing_Arx aSeed_AArx;
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
    TwistExpander_Fencing_Arx aSeed_BArx;
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
    TwistExpander_Fencing_Arx aSeed_CArx;
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
    TwistExpander_Fencing_Arx aSeed_DArx;
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
    TwistExpander_Fencing_Arx aSeed_EArx;
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
    TwistExpander_Fencing_Arx aSeed_FArx;
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
    TwistExpander_Fencing_Arx aSeed_GArx;
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
    TwistExpander_Fencing_Arx aGrow_AArx;
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
    TwistExpander_Fencing_Arx aGrow_BArx;
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

void TwistExpander_Fencing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Fencing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 10744671784110126426U;
        aCarry = 14352452067450676618U;
        aWandererA = 13248158317189051730U;
        aWandererB = 17544600832625723068U;
        aWandererC = 15458715787488512539U;
        aWandererD = 15053076359112390832U;
        aWandererE = 13702152327233761149U;
        aWandererF = 16758871142740770135U;
        aWandererG = 11393864157787027391U;
        aWandererH = 11234306542846549353U;
        aWandererI = 14062483104917126689U;
        aWandererJ = 11829415138866827992U;
        aWandererK = 9559763971751714095U;
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
    TwistExpander_Fencing_Arx aTwist_AArx;
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
    TwistExpander_Fencing_Arx aTwist_BArx;
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
    TwistExpander_Fencing_Arx aTwist_CArx;
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
    TwistExpander_Fencing_Arx aTwist_DArx;
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
        TwistExpander_Fencing_Arx aGrow_AArx;
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
        TwistExpander_Fencing_Arx aGrow_BArx;
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

void TwistExpander_Fencing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 1, 0, 2, 0 with offsets 367U, 5629U, 5709U, 6856U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 367U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5629U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5709U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6856U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 3 with offsets 202U, 2026U, 1790U, 4764U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 202U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2026U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1790U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4764U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 1, 2 with offsets 1463U, 3782U, 7951U, 7233U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1463U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3782U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7951U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7233U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 1 with offsets 190U, 1418U, 995U, 2267U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1418U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 995U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2267U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 292U, 30U, 1438U, 226U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 292U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 30U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1438U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 226U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 1, 2 with offsets 749U, 898U, 301U, 1309U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 749U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 898U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 301U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1309U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 179U, 1817U, 156U, 161U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 179U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1817U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 156U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 1927U, 659U, 916U, 1811U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1927U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 659U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1811U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1101U, 933U, 1778U, 1755U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1101U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 933U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1778U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1755U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Fencing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 1 with offsets 6525U, 6234U, 170U, 6717U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6525U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6234U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 170U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6717U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 0 with offsets 1155U, 7552U, 3636U, 1314U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1155U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7552U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3636U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1314U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 3 with offsets 3007U, 1311U, 2848U, 6509U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3007U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1311U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2848U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6509U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 2 with offsets 4977U, 2638U, 2693U, 5851U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4977U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2638U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2693U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5851U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7875U, 862U, 4027U, 4392U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7875U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 862U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4027U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4392U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1267U, 1071U, 1773U, 1928U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1267U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1071U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1773U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1928U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1282U, 1171U, 339U, 1827U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1282U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1171U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 339U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1827U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1153U, 119U, 373U, 1128U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1153U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 119U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 373U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 150U, 1340U, 9U, 1277U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 150U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1340U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 9U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1277U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 [0..<W_KEY]
        // offsets: 902U, 111U, 1554U, 450U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 902U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 111U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1554U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 450U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseASalts = {
    {
        {
            0x7A9A997F7ED5D768ULL, 0xCD84D408B9D34807ULL, 0x11F811907DA8C6EFULL, 0xBA2C9606BAAED7D0ULL, 
            0xE30842F6A946C840ULL, 0x6893F1E2CB0633E1ULL, 0x11623EFE3A496688ULL, 0x5193831F02EAD1ABULL, 
            0xEB017B35A3FA5ADEULL, 0x79B0C3D932024297ULL, 0xB4B35A322C2092E1ULL, 0x992597A139715695ULL, 
            0x9CD9F64D47029E53ULL, 0xE8004C634872D4FAULL, 0xEEA831123817A8B6ULL, 0xA102AC6239ECA286ULL, 
            0xDD54C94E057FD114ULL, 0x5F1A7F162FF08FE0ULL, 0x64EAE4EFF68D73D2ULL, 0x73C73331BB87B701ULL, 
            0xBCFCF2BB371DF01CULL, 0x843D35FA5486E79AULL, 0xB5380065919B8271ULL, 0xB518D3A0BD075496ULL, 
            0xE3678907BF354AC5ULL, 0x0C61CFE2F26FA4B2ULL, 0xDEE8BD9FD0473D57ULL, 0x70517FD9B03C9CB5ULL, 
            0x5D860BA862359DB7ULL, 0x3C0A15E0D24C8795ULL, 0x7830940B6FBFA6D2ULL, 0xC603034B0BD1E153ULL
        },
        {
            0x892A380FB2C94EB5ULL, 0x19CC295AB4D00401ULL, 0x247D63080504D697ULL, 0xB08518E7A0505ACBULL, 
            0xF5400C44E852D4ACULL, 0xCEF0622D130A6C33ULL, 0xA92E1C98D3C54C86ULL, 0x302A80648B5BB925ULL, 
            0x7B0623C862D714C3ULL, 0x9EADCB32EDDD7DE9ULL, 0xD064F0DE57B8EBAFULL, 0x71A24DE87F7C879BULL, 
            0xAD28A0E84649ED1FULL, 0xC81E0C0E45C6BAEBULL, 0x0460D6300345EAF1ULL, 0x9D11AFA43B14504FULL, 
            0x78130F7B741F7517ULL, 0xD2431800FC85005BULL, 0x3D16527B2C423CB5ULL, 0xA2A0F810ADBD975AULL, 
            0x0EB6CE29342EB45CULL, 0x7DFE86767A44272DULL, 0x2DEC084EA51C24BDULL, 0x3D80A3B3CFF8E583ULL, 
            0xD0922A1ECFB2A7D3ULL, 0xFBE914D6787A567FULL, 0x7A60BC2DCD005D86ULL, 0x4FDAA53DF2BF5498ULL, 
            0xE92C5253ECE05A4FULL, 0x3501A5264F8AE1BDULL, 0x54521B799F8E8E5BULL, 0x55BABCF91587EFA5ULL
        },
        {
            0x8C33A4CD89980D96ULL, 0x9C01C0AC980108CFULL, 0x4AB66E1A0723E9B1ULL, 0x2699FC9612136AB2ULL, 
            0xDB7A1496A5BEF844ULL, 0x53C3FCF996518F51ULL, 0x8B1B6568E0248DEAULL, 0x7B5B5C449706E692ULL, 
            0xD7524932A4671DE3ULL, 0x0B304DF053D4C647ULL, 0x3F49A8DBE8EAABD4ULL, 0x65BF694071D5B15FULL, 
            0xCD4E6FC8CB810227ULL, 0x231D2F5D4B08D63BULL, 0x5F6EC707FAD3B43DULL, 0x81D9E1A077AB4DE4ULL, 
            0x98606D46FFAB7453ULL, 0xFE44FD54EEED9C37ULL, 0xA0AA46F85AECB534ULL, 0xC03A3D3916C1D5FDULL, 
            0xC2EE1896608E8C70ULL, 0x7A8F6EDD5195E08FULL, 0xC97B5A6FF2F3896EULL, 0xF7A16E1A7C155D04ULL, 
            0xA939CCE294DFE60DULL, 0x8FFA17DE4C8C2D2CULL, 0x3DDF0F513FA9C6BBULL, 0x44F70008AB02AA3EULL, 
            0x70A4F26AD4C70553ULL, 0xFAA3F95060554FFEULL, 0xCF5E0413BA75DA26ULL, 0x1225A8B7F80B90DDULL
        },
        {
            0x20200C9829C58480ULL, 0x4BBE985BDA472B23ULL, 0x9A4E2EFF0F2226E8ULL, 0xDC33BA02B00C26C8ULL, 
            0x5A8F1A71EA2868C4ULL, 0x26255C65948FFEC5ULL, 0x6F2AA4B149A9D155ULL, 0xD8B16B64F78343D4ULL, 
            0xC87FC28C97F9C09BULL, 0xC1248B74F8779BDDULL, 0xE5614968BC3266BEULL, 0x50B87DBCA066566AULL, 
            0xDC329E7CB2837973ULL, 0x089BFCE1FC8590CEULL, 0x1CC0E828FA6C23D7ULL, 0x5B8362303A28CEC0ULL, 
            0x26E7E921B9D7F984ULL, 0x502BC1119C4B4E40ULL, 0x5EE3FA5951F1DCB0ULL, 0x0C482726E079868DULL, 
            0xE315095ADF244E68ULL, 0x7BE01C3A724F3B19ULL, 0x8E60546C811D8222ULL, 0x630416ED736CED5AULL, 
            0x4A0B3DA1FA1FE612ULL, 0x780EDE5FA56527E4ULL, 0xE366F702283FB560ULL, 0xCE7B0E5DC50A0D48ULL, 
            0xD5B32CCA5D9225BBULL, 0xF82594983B2C6E9AULL, 0xBF2691E350F3B1B8ULL, 0x8DB79E0A1DAE2FB9ULL
        },
        {
            0xF28C9D4C1FD6FE45ULL, 0x5FC5261F364BD010ULL, 0xF17185983323363BULL, 0xE8DB3065B39B9CF6ULL, 
            0xF3EDC21BA3F1E545ULL, 0x8EBBDB178E2EF80EULL, 0xEF0A9B154D9E7557ULL, 0xFCF4295E29E889E1ULL, 
            0x697E1F4AFC635FCFULL, 0x9C0B9C8D9E3C42D1ULL, 0x858CFD58C0674CC5ULL, 0x0C239B9103176EDCULL, 
            0x052B155D715253EFULL, 0x98DC49677F3FF67EULL, 0x69A57DF3C59A60DDULL, 0x006555432F29985DULL, 
            0x35D29AF7770CAC8EULL, 0x287CCF3FDBD7712BULL, 0xE46DD0D43FD8858FULL, 0x438FF3E52A97C47CULL, 
            0x7936F2C164173483ULL, 0x660A8272950723AFULL, 0xAA73E64DDB666626ULL, 0xDF430925F4BD870BULL, 
            0x3DB5F6695DA0708BULL, 0xC6798959CC6AFF69ULL, 0x211CF8D3F862D074ULL, 0x7DE15A000A08D267ULL, 
            0x0F5FDF0A4F8DAD39ULL, 0x7CF3896E64828286ULL, 0xB86800DB7E0FEE80ULL, 0x1A8AE05EDDE19D3FULL
        },
        {
            0x82A0E445EADD7BB7ULL, 0xFB39B2E8B0E3F70EULL, 0x453263C629253C37ULL, 0xCDE6446313819038ULL, 
            0xC6E427B18D3C4401ULL, 0x9EC257A84FD19982ULL, 0x887A886B0BDCD77FULL, 0x861BF801B7BFC54CULL, 
            0xC443961364B9C209ULL, 0x2C5A837A0951323AULL, 0x37CB7597C0321595ULL, 0xC348C36E9E86CCF6ULL, 
            0xE619CEC5FEB26841ULL, 0x1B369914E2082FFEULL, 0xA262508304CF6F0EULL, 0x6A4C7EB8A1DA0C9AULL, 
            0x4C00131DD2813F5FULL, 0x5377655E47106252ULL, 0xE035BA00630F778CULL, 0xDBD7ABA9AC11FBA0ULL, 
            0x78B9FFB9927FD86CULL, 0xAA2F524AFB694436ULL, 0xA67A3C296253D1E7ULL, 0x91D51F6AE28C49BEULL, 
            0xAA7AB2CC6B8C099BULL, 0x9EA2017905F2D74BULL, 0x7DBC545074F4DC00ULL, 0xA4C0D6B5C81795BCULL, 
            0x10DF15F700D533E1ULL, 0xF18CB87CD44A24A4ULL, 0xF1C5A65CFAE132FDULL, 0xE5D043D03C5AFE6FULL
        }
    },
    {
        {
            0x300E1C59867CC434ULL, 0x202AFD26B88FA471ULL, 0x0EAFE8C88BC8061DULL, 0x564C6CC9042C7C32ULL, 
            0x6B7E91923CCA75A1ULL, 0xDA4540BDB60AE6B7ULL, 0x21358FAD957C64ACULL, 0xACFC7840DE23A74FULL, 
            0xE126325834442B38ULL, 0xF5992F4FA432DB4AULL, 0x94E051B533F31A3DULL, 0x506F4DBF28164CC3ULL, 
            0x1A3EA2273D505407ULL, 0x2BC91D0A20681ACFULL, 0x9A24ADEEDCB17C57ULL, 0xFEA94E0F7CA76B67ULL, 
            0x5BDFD050315293C7ULL, 0xF7D3C0A98295B4D9ULL, 0x36FE34FC730AA8E2ULL, 0xE9A3BDF0A45D0396ULL, 
            0x9443E8B58F94A8E5ULL, 0xBA9C1A55031A67B4ULL, 0xF85B3595F4182E00ULL, 0xDDED2137C5AE15D2ULL, 
            0x952381BA144DAE14ULL, 0x7E1D6AF9882C1D87ULL, 0xAF4B28A8825E6188ULL, 0x915D03ACFC354536ULL, 
            0x7987958A7E63208CULL, 0x32C3CBF5A96B6C96ULL, 0x2C4122F1559AA168ULL, 0x357C92A7F802B2FCULL
        },
        {
            0x4C9557EB93CA31F1ULL, 0xB71C46C75FF460C6ULL, 0x3D692081F4036E8DULL, 0xC2E0149A444ABC0FULL, 
            0x044774F44984A5B4ULL, 0x395006CE2AFFEBE2ULL, 0xE5C3E4373A8CFACFULL, 0x51C8693B8321DD82ULL, 
            0x491F6F09FDC5AD11ULL, 0xC3A2B7830F7196FFULL, 0x0529C33E15ECF853ULL, 0x7BEF8598F899BCAAULL, 
            0xA9D0708A2E53EECAULL, 0xBD7E4815916A5DF2ULL, 0xD53FA0DF646CEEE4ULL, 0xAC64218BACDE8849ULL, 
            0xCC3EFC624E93B3D9ULL, 0x24F89E01648FC414ULL, 0x6C96BCD6E5B8FB44ULL, 0x5815302D7769CA98ULL, 
            0x5A40DAEBB3C7D472ULL, 0x4504F050BD96325DULL, 0x1689F46DD9D6F9DBULL, 0x0072352D89205B4BULL, 
            0x1381E655F2E691C4ULL, 0x7F0BC52F35942737ULL, 0x49E30FB20E208908ULL, 0xC8BF738EBC9034D0ULL, 
            0xC9E5AD1B6CE13B35ULL, 0x1537884CF2CB3015ULL, 0xCD235E40017602CFULL, 0x872A8CD9C6C4A684ULL
        },
        {
            0x1FC22A60B32FAD33ULL, 0xA445F4C3D97FDEC5ULL, 0xA3A0F8F5C41CB546ULL, 0xBF1724F92935F248ULL, 
            0xB1A4269D080A75AFULL, 0xC20821B63C9475F6ULL, 0x394A3E716523015DULL, 0xEAE196EF289F0211ULL, 
            0xCEB5DB795DFAF80CULL, 0xA617E290C50EEDBCULL, 0xECE5B795DC66E524ULL, 0xF5F814A22BE2BAC8ULL, 
            0x47D83387875FF19EULL, 0x349332E00D1C71FCULL, 0x591DF4F2BC699172ULL, 0x874300779A66895EULL, 
            0xE8512B9EDC335E62ULL, 0x35A0B2F5C1CEA1E9ULL, 0xD54FA00AFE78C1B0ULL, 0x06AB5F64156F4C41ULL, 
            0x061C37B32D462832ULL, 0x1D9C16BB0BBBCA0FULL, 0x14B6AA138A352BCCULL, 0xBEF6F18A26D9905EULL, 
            0x8F688CD8F3B56390ULL, 0x7FC3515DB004C475ULL, 0xDB6B02B044FF408FULL, 0x556FF8298647DC0BULL, 
            0xB1F40F3F2A1AE788ULL, 0x910066DA4BB4FE89ULL, 0x93400FE10198897EULL, 0xA336B71519219356ULL
        },
        {
            0x6F6286E7B20FE85AULL, 0x7089C6B8C9F39191ULL, 0x855833879414BAE8ULL, 0xDB0695DD67F06956ULL, 
            0xB1CD52AB388BC70CULL, 0x6136D047E3442D05ULL, 0x4DB96A1831300EBCULL, 0xBC1D3C8FA863CCC7ULL, 
            0xE74541E5EC46841EULL, 0xFBE7D33B4C7135CDULL, 0x252769CED91C85AFULL, 0x7938642B75E0CDD9ULL, 
            0xCD770DD1B89847C5ULL, 0x0280175467CAF196ULL, 0xDA25DCD3DA276A55ULL, 0x544482A43FCFF700ULL, 
            0x70DEB4C46B1DF29DULL, 0x8D0F3BE1D8D7DCE8ULL, 0x23351584B6D9A397ULL, 0x8396B1FF459835F8ULL, 
            0x515C57B4E060AD1AULL, 0x1CD05FCC9B5238DEULL, 0x5205B0E4B8D878C7ULL, 0xB39D95EA0ABBF0F8ULL, 
            0xBC3A403B3FD3BE5FULL, 0x34283750A2B885F0ULL, 0xCDB04C34EAEBD0BDULL, 0x9D4C10ED5DC01B17ULL, 
            0x02A2119149E42CDAULL, 0x38C7B3303113728EULL, 0x1155F75FA97E9896ULL, 0x38DAA1318C0E5DFAULL
        },
        {
            0x77FCFB36EAFEF13CULL, 0x12077AB6527D72C2ULL, 0xE809BAC4454ED159ULL, 0x113CC4E800E8B3B5ULL, 
            0x5E779C377FED7675ULL, 0xAE58FBED9735CD13ULL, 0xC69877F9E030F01AULL, 0xB9D4D42C55B98D4CULL, 
            0xEA8F5259E677946DULL, 0xDAB9859CA1E79E61ULL, 0xD37EE165CB26BE51ULL, 0x434C929FE7502A7BULL, 
            0xC7AD19D0E664E193ULL, 0xF3764AE71A007C5CULL, 0xE717563F9D8A68F9ULL, 0x02121DC7189FEDF9ULL, 
            0x91723B846AF46A52ULL, 0x913065E8CE1FF035ULL, 0x1BAC69FE3C593BE1ULL, 0xC0FFAB7088F14504ULL, 
            0xF128ECEA28CEF79CULL, 0xA3139B4E8FD98B85ULL, 0xF143571CA971F041ULL, 0x1F65B73777D6E40FULL, 
            0xE7E216CB82328D5AULL, 0x866704AC4895B163ULL, 0x5D639B689A13193AULL, 0x56312E2F891E75B9ULL, 
            0xF43D836785ABE8F8ULL, 0x91FDDA68F277FB8FULL, 0x56FCED89AC3C28A8ULL, 0xDD97DF4B2DE628A2ULL
        },
        {
            0xE4FE7D792D7D706EULL, 0x48955DE293FDC395ULL, 0x7CCB8EA7905867ACULL, 0xCBD415EA90498C3DULL, 
            0x1C53B1317CAAAED2ULL, 0x9D56C929791853CAULL, 0x2F1936B5A6DF25CEULL, 0x7880144BEE1DC723ULL, 
            0xFCA9BC69F47DAA37ULL, 0x980EA3F3E662A828ULL, 0xEF8C90CC30885965ULL, 0x80276446723F65D4ULL, 
            0x606608735534E046ULL, 0xFF87594F06D2F1A2ULL, 0xCEDCB0423DBA746DULL, 0x40632A7C81D4F67CULL, 
            0xBDACCC751C07A956ULL, 0xF678095A5817D782ULL, 0x94D959E25CA0494DULL, 0xB31AB8A13AC81875ULL, 
            0x43121C57A2C62401ULL, 0xB93C8D34FCE0C956ULL, 0xEBFB9C31C2755F01ULL, 0xC8296EC8F8ED92DCULL, 
            0x71A7F81D518DA657ULL, 0x960321DCF4211908ULL, 0x41CD1AA1C30C11ACULL, 0x9E2603BC22196CB4ULL, 
            0xE679948C2A7DC255ULL, 0x1ED0F06BADC5A93DULL, 0xF82AB52F01EF6939ULL, 0xB2FC91F75E21795DULL
        }
    },
    {
        {
            0xF75D1C1AB283F09EULL, 0x0F124B0C417C158AULL, 0xC96414824438E6FEULL, 0x9F1E6EC6EAEC990DULL, 
            0x44A80FE5A353E685ULL, 0x07902C3FCEF31EE3ULL, 0xA11D44A475C7E3F3ULL, 0x249491178249C7EAULL, 
            0xA44C9B91F99AA5E0ULL, 0xD4B9DACB033DAE83ULL, 0x58A8173B1E8A8C4BULL, 0x52AF25AD7EAC7AB3ULL, 
            0x2C681274FC53DCC4ULL, 0xDEE752246DEAE36CULL, 0x235CBD7B46A59608ULL, 0xF41C98594EED3626ULL, 
            0x7F27B2F60EADE8A5ULL, 0x17C3EFE42B3E9453ULL, 0x93EB09C898E4CF8BULL, 0xD2D6591534A9734BULL, 
            0xD2F8384F1B2EF458ULL, 0x111988E2A910EF0BULL, 0xAAD4BCC61CB329BBULL, 0x18E5A20FDACD674BULL, 
            0x88091D5C5125D5D9ULL, 0x8DA8A45D4CBE34C0ULL, 0x6B58E2AA48AC7952ULL, 0x3B89A294324DFA66ULL, 
            0x5007C465E71B4FB6ULL, 0x1C37A3990E63E2A9ULL, 0xA908A836EE311CC5ULL, 0x2103AD9BCFDE2771ULL
        },
        {
            0x57A6071B597043F7ULL, 0xD8517217A9DC8A73ULL, 0xE85FFF0B9B90B679ULL, 0xAD98E2B76FC2D4A6ULL, 
            0xCF432580D79260ECULL, 0x5D45ADD4D990592AULL, 0x76022BA1B5E5DBEDULL, 0x39861B8FD92CD6F3ULL, 
            0x8D2E866EC94DA583ULL, 0x886626C89106A684ULL, 0x5EF918EFD5214319ULL, 0xB7E739BFCAD49800ULL, 
            0x719BABAB893AC0BDULL, 0x618B06B58ADFD247ULL, 0x608197E5D320BD1DULL, 0xB56D23488A0AC50EULL, 
            0xA20C3199EEF5A1C5ULL, 0x2F01997679158D81ULL, 0x8CB9CDF4E9D5B218ULL, 0xCC5B09EC06606CA2ULL, 
            0x786D4CDE4667E9C8ULL, 0xE636FEA94E89FAB4ULL, 0x7CF9A4ED21A02F57ULL, 0xAF5A90F265E2B031ULL, 
            0x2A6B80E924E0E04CULL, 0x0072F6FE65AD4E05ULL, 0x36799CFB3E035E47ULL, 0x2BB38BEE39437EAEULL, 
            0xDEC5A93CF7CEE881ULL, 0xA4DC2ECCB86B2CEFULL, 0xB9B9910F3BE50559ULL, 0x84D09AA1A9F641BDULL
        },
        {
            0x95D9DB3028FA97DDULL, 0xBB4AED16198DD43BULL, 0x0DBC99A841F1B0A8ULL, 0x123EB48734AD67C5ULL, 
            0x961D4F1E3226E87AULL, 0x49A7C8DCC2C83252ULL, 0x2B7F0EBD6DF03705ULL, 0xFA5FF1270AE34D01ULL, 
            0xE71A8627E61413E3ULL, 0x0A090362EE4E0F3BULL, 0x4271501D16D2CA4EULL, 0xAAFB3E6FFC7D96F0ULL, 
            0x5EEB73E10A94F956ULL, 0x2AC683A8F45BA42DULL, 0xDB7C559CBE8B7133ULL, 0x8E8371697DDCBFE6ULL, 
            0x571A48E3A2EE38BDULL, 0x63C2B032C7F81144ULL, 0x6761D43F1F64414CULL, 0x0D3B9540BBE5EE74ULL, 
            0x2C07481CA10AB7D6ULL, 0xB152A34F9B41E7CBULL, 0x51B2DC1DE09EE3F7ULL, 0x733D523375DBD808ULL, 
            0xAFB1B3CF3774A2CAULL, 0xAF63448FB1472929ULL, 0x090CB4987F85EFB8ULL, 0x64C2A0D3798DCB18ULL, 
            0xFA7EF565808796CEULL, 0x5D4637451AD921C5ULL, 0x613B90D9F8AA9223ULL, 0x11F8CC081298E09BULL
        },
        {
            0xBC458B7A14D9994CULL, 0xF16164D5D6927E27ULL, 0x81FD9D73E10D6B9AULL, 0x4D4F1EB93702BE2BULL, 
            0x01427EFF2A8E86D4ULL, 0xE030D3696EEA0696ULL, 0xC0D33CCE62BB5D24ULL, 0x905232F235487100ULL, 
            0x8E8442CDD3678D14ULL, 0x7CA8A4ECC3F5CE81ULL, 0xD1DDD24287F43CCFULL, 0xDA2E2587E22B5480ULL, 
            0x17EAA58D1888B3E0ULL, 0xB1859AA19B57E4B9ULL, 0x6DC04287913AC121ULL, 0x02C2FF871519E6AFULL, 
            0x2C0ECEEAFBF737A0ULL, 0xDBB4C51AE157EC3CULL, 0x5A82A3920B60A475ULL, 0x8E245F2B89F4DAC1ULL, 
            0xFB1277ADB86F1A0EULL, 0xC2AD143329ECECD8ULL, 0xA138C5BFE48FD648ULL, 0xB18AFEB84B125723ULL, 
            0x3C83A2C0170B01B3ULL, 0xD61C34C80FB192A6ULL, 0x28218DEE08F1995DULL, 0xB9DFA312B9D36F87ULL, 
            0xBC78C5F925991462ULL, 0xEA3360FF0525C1D8ULL, 0x74AEF6945F5B8D85ULL, 0x6794BEB5B84EB024ULL
        },
        {
            0xA536170915949025ULL, 0xB832448016544E7CULL, 0x10FEE2859584D55EULL, 0xA87DEBC29FA272CEULL, 
            0x023CDD892AB9E233ULL, 0x678170812B201758ULL, 0x419CC02C4FDA958BULL, 0x3F04651D751C09B0ULL, 
            0xE4AD0EEF6FD36448ULL, 0x7E0B20E67AF16B20ULL, 0x07EC54D4B9C69E71ULL, 0x4591E13254BED1DDULL, 
            0x7EA0DB7489241DE2ULL, 0xE7BE419D4670E8CDULL, 0x9DD9A772C8FAD98AULL, 0xDB829B23A9763D36ULL, 
            0x081BB77CBBA54C78ULL, 0xACE0B1F93745883AULL, 0xB4745C969B81D126ULL, 0x521CD7C73524DC1AULL, 
            0x6630945B86E777F4ULL, 0xEDCD935CFACFAF43ULL, 0xFF4C839F77606339ULL, 0x082E511D0989D10BULL, 
            0x4FF0E26BE0173E47ULL, 0xF09869CA8479B703ULL, 0x8AE85988129B6491ULL, 0x81638F6208A8993AULL, 
            0x7D8A73E51422D2AFULL, 0x320879FDF123623AULL, 0x3D42459ECD4D94E2ULL, 0xE8241B2365105734ULL
        },
        {
            0xBABAE7B03776CE33ULL, 0x07A96438AEE1C853ULL, 0x7F38ADEC4531D248ULL, 0x84A07004C6E71566ULL, 
            0x2678DE1FDCF5E629ULL, 0xA18DA02CEEDA0DAFULL, 0x50D3D2ECE35C204FULL, 0x5D232669CB90873BULL, 
            0xAA2D77F4F825C11DULL, 0x5ABF48EB5E87E1A4ULL, 0x3325150C708A5887ULL, 0x2B92C72234DD030BULL, 
            0x0B0576FDF752A9D7ULL, 0x32BF8253D3D7C8FBULL, 0x5B0DE43B6087C1E3ULL, 0xBB50A9E4DB65C6DAULL, 
            0x56071F0C7FC098EDULL, 0x8C4C3779AE54D6CAULL, 0x3024771327F6E001ULL, 0x991E6DF84A244C42ULL, 
            0xE05205A2F737DE7BULL, 0x137245FD0B60574DULL, 0x642302A066A637E1ULL, 0x2E55586F31B204E3ULL, 
            0x825775AB0128BA5EULL, 0x16C4FEFA6EC5D266ULL, 0x83DEF943FBB154D5ULL, 0x20744E0BE44FFACDULL, 
            0xF5281B77AFC99825ULL, 0x4461F93A4D1EA31BULL, 0xF10948AC072F867DULL, 0x21BA5C8EACEFFCAEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseAConstants = {
    0x53F8A0318ADC1D69ULL,
    0x28E4857FA6EFB6BAULL,
    0xCB96373EBEB03F54ULL,
    0x53F8A0318ADC1D69ULL,
    0x28E4857FA6EFB6BAULL,
    0xCB96373EBEB03F54ULL,
    0x527500C2E21F5AA9ULL,
    0xBEBB4095E61DEC15ULL,
    0xF8,
    0x85,
    0xBD,
    0x0D,
    0xD1,
    0xB5,
    0x32,
    0xFC
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseBSalts = {
    {
        {
            0x48369BC9A2323772ULL, 0xCAE935FD5449A18EULL, 0x4478D3E9936F3C77ULL, 0x8EB255A19D4102D3ULL, 
            0xD96336386530E322ULL, 0x7C242A2BAA07BEEDULL, 0x008BE890B4D802FDULL, 0xED492864931E50F7ULL, 
            0xFA993FC431CAB2F3ULL, 0xCD6B48AAE6961B39ULL, 0x50D243A8C330B9ABULL, 0xB6523E9A5CAE23CAULL, 
            0xE7125E00D9FE3750ULL, 0xCD21CDB670F25398ULL, 0x20D1D3905D7D64F5ULL, 0x991CC37804F572DBULL, 
            0xBF92230375836EABULL, 0x56F70673EF3E1C2AULL, 0x6D2DE0CBE6522397ULL, 0x85EDC7AE7A9E0F71ULL, 
            0xEE7D1A8CEF26A028ULL, 0x01496DB840FA1EFDULL, 0xF85F948CFD032157ULL, 0x2FB0EB5792E33ADFULL, 
            0x03519D21A47129C1ULL, 0x9387C5D37EEAE045ULL, 0x70333ACEC220628FULL, 0x35A4B71E45D5EB27ULL, 
            0x38225F40661A08FAULL, 0x6D221DCDF3DE24ABULL, 0x14D3C0CA72635A65ULL, 0x1C21EFCF12CF3B48ULL
        },
        {
            0x05D7212A4C6AE223ULL, 0x2B1A41E4EFAE88F7ULL, 0x5DE82DCECB6F2BC4ULL, 0x3E18328ABE1F6281ULL, 
            0x896E6C576E7F28A3ULL, 0xCCD9F7CEEFEEFF97ULL, 0x31CC8352F8FCABA3ULL, 0xCD70E64E2FE20BB0ULL, 
            0xB69C7071C9C56BADULL, 0x925A824E64FA2685ULL, 0x592B7459E499BA6FULL, 0x1506897D5B8D67EDULL, 
            0x170D2D3CA6BC4D6CULL, 0xD3912D2F116D9529ULL, 0x4E91CA156D1A73EAULL, 0x9A121DC676BB693EULL, 
            0x26E152AC504B8EF3ULL, 0xB1AC2BD5B5D13118ULL, 0xC80BFFFEA827AB7AULL, 0x5830E94BD47C1E1DULL, 
            0xA3CB76D5394AB80FULL, 0xAD8DB8D65F5F6F0EULL, 0xA56C474A37B014EEULL, 0x6E6DE0BC01EA5002ULL, 
            0x34973FF72D95D3A8ULL, 0x4A08F9DE48298C49ULL, 0xCB2E2BE969357514ULL, 0xF2C7876F2AFD2DC3ULL, 
            0x6964C17915574496ULL, 0x1DEDF92D1CC39A6EULL, 0x65268C5F4A907F99ULL, 0x8B2A4DB46446BAD1ULL
        },
        {
            0x6C74FE511575107AULL, 0xF0664EFE15685E30ULL, 0x0530C6C202586531ULL, 0x06F4BFBEA3AE825BULL, 
            0xEDEEE33E265B502BULL, 0x46007BD0B69C48E9ULL, 0x2AD0AA0A0D388240ULL, 0x816D0D13E6A582D3ULL, 
            0x0AE2B9A3765AAD47ULL, 0xD9205D9E9D0DF652ULL, 0xA49E95C46A08BADAULL, 0x7D9822E6BF722382ULL, 
            0xD7020B2218134D8EULL, 0x4C2A56F88B65955FULL, 0x15B24BA4315E8536ULL, 0xFA3720370DB51F8FULL, 
            0xDCF3E77F3D58CA13ULL, 0xFBE62F034816BC2CULL, 0xAD87D3AFA1FD7FA8ULL, 0x00B24076C6051BDDULL, 
            0x88220658AC12788EULL, 0xA3A345B252C933FBULL, 0x49E11E6EA3CE0E9CULL, 0x2877A6CCC2DCBB13ULL, 
            0x467172B05CF1AC54ULL, 0xCAF4F6A7190DC032ULL, 0x3ADA009A01E21765ULL, 0x2E974FA29D4C8AD0ULL, 
            0x52C5F51896CC7F2EULL, 0xEACDDF3650E6A6CEULL, 0xEF1C07DAE7FE6C98ULL, 0x0B4462430DD1FE52ULL
        },
        {
            0x4D9C07E42CCA5B23ULL, 0x14C6EAD655435864ULL, 0x8A01CB0102C4A5E4ULL, 0x0328E1C68D7F9F2FULL, 
            0x9AE77EB0A084015CULL, 0x0C77B328AA582EADULL, 0xE3A3D0A5914B7747ULL, 0xD2BF70E33111ACCAULL, 
            0x491AF939664B8139ULL, 0xDB151C5885F3BD76ULL, 0x01CB4C8D819EAEC9ULL, 0xDC5B2C1073C05FE8ULL, 
            0xC6DE4DBC21C9152BULL, 0xE4D9C7F63E74E4DEULL, 0x2C77FAB16FEF6F1EULL, 0x5410F8FB24C9C888ULL, 
            0x4DFEC6068AEB8349ULL, 0xE54F0FBF0940C60EULL, 0x53CEAB4A47FFE830ULL, 0x46D5080CFA9A0805ULL, 
            0xE46C72A8DA905F26ULL, 0x95E62A39D14AF8E1ULL, 0x8A135575EAA55F6EULL, 0x78BB1CFAB040138DULL, 
            0x12BCF7A5EB6A829CULL, 0xBDAF7B036D96C7A7ULL, 0x432E75D5D47E6C74ULL, 0x2303E7DDCFCD1423ULL, 
            0x140639D6A226B463ULL, 0x326176FC77496F89ULL, 0x3B5B9CC2C6E4E111ULL, 0x26AACD160854C14EULL
        },
        {
            0x50C3355FC521DC6EULL, 0x2C5005994ADE19FEULL, 0x939C0549FD16472BULL, 0xBD47D0813F898446ULL, 
            0x0E28CA1404526073ULL, 0xF572380098062896ULL, 0xE9C2E0E94298C1CAULL, 0xC8AFFA9B0934075CULL, 
            0x2B32DAEBC54196F7ULL, 0x49457CD3127EF73DULL, 0x7C557ECC07A2FA13ULL, 0x699FFBCE0281534EULL, 
            0x266A0CD315BB4EB5ULL, 0x05A6BE5B2C2D6631ULL, 0xECE22D12F30B882EULL, 0xD610EBEB91C1C4AEULL, 
            0x22B8D71B9FAF20B4ULL, 0xFB1938BEF4F7C774ULL, 0x29DD4A6A5B6161ACULL, 0x1DB94A3E59BFF19DULL, 
            0x072D553923FF05AFULL, 0x3D1B715EA08E4DA6ULL, 0xB44F8446A1122CEFULL, 0x57B24B7AB72A0D73ULL, 
            0x521F675BA922522BULL, 0x5B119CA97051D8CFULL, 0xA06B440194861A53ULL, 0x8900D18B905EF86FULL, 
            0x501929D50ED318F0ULL, 0x46ED43FBB885EF66ULL, 0xCEF2C0DF7E03DA91ULL, 0x7C16E6A98A109B29ULL
        },
        {
            0x5FE0E60C92139DEEULL, 0xDE0232DF31072CD0ULL, 0x41B0AADA128D3D19ULL, 0x08F25E305F3448A7ULL, 
            0x6E40889C01D77CE0ULL, 0xBC4ECAC024F64F7EULL, 0x8340D44E5B90EF18ULL, 0x570135E884985B5FULL, 
            0x2D001AC23C978627ULL, 0x5228FBD57186C410ULL, 0xDF6ACF6F1216A6AAULL, 0x942CA50C614F618FULL, 
            0xD1E21922D8A9D5F6ULL, 0x3CCD15CBEB21D396ULL, 0x929C0F94E0DA3731ULL, 0xD1ADBE3BEFE7793DULL, 
            0xEA030DF8514046DBULL, 0x22B75389BB77E834ULL, 0x9DE9CBFC04B9933CULL, 0x958BF97F88783E5AULL, 
            0xB169D5731C13F451ULL, 0x34A92E52C47B7CC4ULL, 0x874410B7CAE78D8DULL, 0xFCE114990748DA88ULL, 
            0xA78D7FFF7E07CF8EULL, 0x9D6B8479719E2572ULL, 0x9491A9A86305022AULL, 0x226232F70B0A40B2ULL, 
            0x55DC69FF4D2A4AEAULL, 0xA2689E07009A065CULL, 0x83314D7BF12B2C3DULL, 0xEB54CE04B9280409ULL
        }
    },
    {
        {
            0xB8428B73927E2B1EULL, 0x0357440BECC26018ULL, 0xC436A5912B07EC69ULL, 0x7779960B3E34F929ULL, 
            0xFC68BCFEDB224BB3ULL, 0x3F74308B80118562ULL, 0x6F0C8A9993167010ULL, 0xCD056807E9B37693ULL, 
            0xB2B5902DA9C29A2FULL, 0x521B75DF2988879BULL, 0x9BAE8B8CD678946DULL, 0xAE4F304091C8346EULL, 
            0x3419D3E84A55644DULL, 0xCB35A11F18491569ULL, 0xE1A22641D405B0BDULL, 0xF0860B428514EC93ULL, 
            0x5C8AB739E58F4836ULL, 0x1F7E1434CEC3D65DULL, 0xA63FB7EDAFD5F367ULL, 0x6942FEB10720C771ULL, 
            0x6A078AC3715D449FULL, 0x862F900EB6F89DCAULL, 0xCAD25CBE20D7DFA5ULL, 0x9966C466CCD51674ULL, 
            0x5F4B4BFB1CD77D8BULL, 0xF8287FC2F22568C9ULL, 0x451BDD49C42B2BF0ULL, 0xF63739F6EDC74701ULL, 
            0x8F6DA50CE3DB281EULL, 0x67B76577A0610862ULL, 0x453654AC9A74CF27ULL, 0x087DDA7C8D24FAADULL
        },
        {
            0xE446FF9EEDB1F84CULL, 0xC371418791D423E5ULL, 0x971ED7EE7A21E776ULL, 0x37B3CAFB3007CE74ULL, 
            0xAB12BECAED4DDE2FULL, 0x7F71C699179D4ABAULL, 0x9335AAF4CBAF617DULL, 0x9AD34EB330604C6AULL, 
            0x55E73E39C46B1DA0ULL, 0x45271B0E9E7E978AULL, 0x537667031128FE89ULL, 0xEE13D9744B5720C3ULL, 
            0xC5DCE16AD9FC125FULL, 0xD99864F860719B27ULL, 0xFDC96FCF76C9118BULL, 0xBA16818CE323CD44ULL, 
            0xC354B0C2CEACE8F8ULL, 0x21196DD5CAF1D55EULL, 0xA2314CC6B36EAEB9ULL, 0x0FB00C3D43D0A1B0ULL, 
            0x9CE67B36DDB014DDULL, 0x39D314C6D6E8561CULL, 0xEE4B4EC22D603CC5ULL, 0xD42122AFFF9BE853ULL, 
            0x6824B33C7F08AFBAULL, 0xDD0392B14A3139CDULL, 0xB0F8E6DD027D16F5ULL, 0xC69DBDF4FECE556CULL, 
            0x828F295B69040B01ULL, 0x0DC0475E2138DD82ULL, 0xB1AF4CCA05E063C8ULL, 0xD268F673683C90B4ULL
        },
        {
            0x92F19055CAA2FDEEULL, 0xFCBB8989F39D84CEULL, 0xFDB3EFC315E179E4ULL, 0x0F6D3456669D981EULL, 
            0x85F702E8194D74D6ULL, 0x64C041DDF6CC7443ULL, 0xA87CB4C0D6B5C646ULL, 0x549992F4D79BB53EULL, 
            0xCFBF7F7F7F4E8591ULL, 0xD42B97A8CE886021ULL, 0x4389C23D0A898D92ULL, 0x66459D348A9A5544ULL, 
            0x86BD034AED1F822AULL, 0x33F6791F7D40DB3AULL, 0x9A8EF73617EA0E24ULL, 0x09AB37862D8398CFULL, 
            0x664508F2916FA3D4ULL, 0x518F442358EB3D5EULL, 0x24DEA508BEBA8CD7ULL, 0xADC1AF356ABA049BULL, 
            0x40CE2FA36C7B1C9FULL, 0x240892C9989E0D7FULL, 0x4E6DA90EEFD1CA75ULL, 0x04DE5CC0737724D7ULL, 
            0x87D4249F8FB8E4FDULL, 0x8CE58ED8DBC1105FULL, 0x04AE5B97A875A187ULL, 0xBDB839FC02BD2B36ULL, 
            0x5F2A08B6E240471FULL, 0xC1C5C4B162F726F9ULL, 0x40EEB2F5D6B6AB53ULL, 0xF9C8BA781FD5DD00ULL
        },
        {
            0x3EE49053CF2C0C5CULL, 0x7EBB3E74B90E9CCFULL, 0x942BA2CFD94D1DD4ULL, 0x0F7E9F2215E087A6ULL, 
            0xF2DFAE49437CD679ULL, 0xDABE190D5784D046ULL, 0xBE584D2EC60CF6D7ULL, 0x681096D9B5EE7378ULL, 
            0x4B20EF43B48E85FEULL, 0xA1FF3DD8000E8B61ULL, 0x04BEFEF15CA2619BULL, 0xB7C5087A770AC0C2ULL, 
            0xCD4B8B515628CBF1ULL, 0x943F329CA75340DCULL, 0xEE4FB6BDD649D7F5ULL, 0x2626D69767DC282FULL, 
            0x83FD0EB54AC5E37FULL, 0x9BE7B2A65606422EULL, 0x0FBDA6706EB387B2ULL, 0x52FDAF30DBD20B47ULL, 
            0xA22A27109516A4E4ULL, 0xAC0C01B739F4C04CULL, 0xE8A6E40C985C914CULL, 0x82944CB5FE644B79ULL, 
            0xFD03A4C4830B1222ULL, 0x3F3A8F58B01A3307ULL, 0xF7183D77B44AE803ULL, 0x1192A4B56D3F2A59ULL, 
            0xD352EC8FE1CB6593ULL, 0xDCC671E2BAEC122AULL, 0xE4627373CC361A0DULL, 0x2C6F5C6818E285D7ULL
        },
        {
            0xB017EB37B23D5394ULL, 0x1B24EE09965E7EFCULL, 0x8438D180C87C16C1ULL, 0x878F4FB53F4A9EF0ULL, 
            0xBDF44CF7AE72B27AULL, 0xD52701541B916D50ULL, 0xB932661E6D5101A8ULL, 0xC36647C71C9EB801ULL, 
            0x8AFBB51A18ED4284ULL, 0x2949ADDAE801D9B8ULL, 0x436579A126180601ULL, 0x1F062D7CECA052B8ULL, 
            0x1D82296385F7E7F6ULL, 0xF51F299A753502ADULL, 0xFD2279037637CD65ULL, 0x1DF8A6195BA4E3A0ULL, 
            0xFA5EA5E7BA425141ULL, 0x70EE5EDC499945C6ULL, 0x1684CA56997ED8B5ULL, 0xF7CD13E8B2638DB1ULL, 
            0x8FDBD2F299199AF1ULL, 0x55D2A183759AC4E9ULL, 0x268554D493C0F087ULL, 0x04262E04E620AD37ULL, 
            0xD130B54C6AB9EF88ULL, 0x955674EAE0FE4E0DULL, 0xE70A836B17205486ULL, 0x9C3443D8692890D3ULL, 
            0x970619A96FB0C583ULL, 0xC4143B86879C20B9ULL, 0x53D9AA50A0DEB10CULL, 0x42AF89B3213E2011ULL
        },
        {
            0x0A2CD3A2B61C38F1ULL, 0xEA8B425FBC97EC2AULL, 0x934ECDD6C993C1A6ULL, 0xA3CFD82EAAFF94FBULL, 
            0x3050D101265BBEF0ULL, 0xC47AAE405C5BD2B1ULL, 0x7AB006435F89C11DULL, 0xE4ACBE5CF17ACACCULL, 
            0x41FBFC4562DD8974ULL, 0x9F1699722BAFA58CULL, 0xA669E076257C6FE3ULL, 0x0BAA7FD26412A46CULL, 
            0x07F85FFA9A14BF61ULL, 0x6AFF9E454B3CDCAFULL, 0xD84AED329783AF03ULL, 0x5B99E853227A512CULL, 
            0xE0144CCDD81995DEULL, 0x580EA34711A1790FULL, 0x448D5A908953CE63ULL, 0x1BC9BD004B491030ULL, 
            0x925B86296AE09001ULL, 0xFBF255E0A8C1B16EULL, 0x78EE2EB90D9D8877ULL, 0x8104D80723E376F8ULL, 
            0xB20D0351643766E3ULL, 0x80B6A8D1185FCB49ULL, 0x7F07C1A1BB384F2EULL, 0x731048E04D8BFC8EULL, 
            0xF10ED28386777315ULL, 0x689A2DD370A974C2ULL, 0xBFA78C11D08EE9F8ULL, 0x4D082B2892EB0FE0ULL
        }
    },
    {
        {
            0xD9888F893CCCF97FULL, 0xD6D9C8310F484723ULL, 0x0CE070C7158DBBF8ULL, 0xAB2FC2E2C43A6225ULL, 
            0xFB27E5FE447672D6ULL, 0xE05EDCA6227C764AULL, 0x37CC69D20D2A9298ULL, 0xA2540AB58872AB61ULL, 
            0x27BCB80A49E7207AULL, 0xEE6BEA22DBAC7600ULL, 0x6120C9EFB104E841ULL, 0x209A5199B4D29EA7ULL, 
            0xA7923655D172D4BDULL, 0xE5C633D66CB788E3ULL, 0x2F4C75A191D23A85ULL, 0xA6C336C7AA879EFFULL, 
            0x43200BFA6331C67DULL, 0x74E121CE7C684F44ULL, 0xAA20EACB4ED23E43ULL, 0x38E1CA8A78CF1FC9ULL, 
            0x410046C005DCE495ULL, 0x26EEE285E45533FBULL, 0x51F3D4DC7D4BD958ULL, 0x5CE297BDE2D26836ULL, 
            0x1161B23BADF07A95ULL, 0x37E2569DEBE23238ULL, 0x0F63125D9F03B6A7ULL, 0xEBFC9E711CBA42D3ULL, 
            0x8BB469338A247B4BULL, 0xB35ADD457A30350CULL, 0x4CAA477964C0B7ADULL, 0x8249B1C838048AEDULL
        },
        {
            0x6721910CC842B54DULL, 0xE963F19EBA0C954AULL, 0xD2AEE8B0EF0EAECFULL, 0x9D192930F6FBF79FULL, 
            0x06C4FF8CB72E9B42ULL, 0x0034A8BCC635CC07ULL, 0x2E0A558D086F0B30ULL, 0x1EF3103C8EC90CBBULL, 
            0x142B1377EFDA6CD6ULL, 0x5088EC9F7F9F7059ULL, 0x6D18814842BDC2FFULL, 0xF28EAC28DC1D9B28ULL, 
            0x239EA0CA033FCFE4ULL, 0xAB80181F8314D0A4ULL, 0xE8F5EF1D4BAE79AFULL, 0x58CEA67377F63BBDULL, 
            0x9D8BC2F975E76FB6ULL, 0x4DCDD0F6D3425ABAULL, 0xAA23F6FB4014D97FULL, 0x91764652EA5B5833ULL, 
            0x70BD57EEB98DDE02ULL, 0x2BF7DDC3C9182672ULL, 0x826314E662C9E61EULL, 0xD4FAEA7B8732E39DULL, 
            0x69354FD3341DE42AULL, 0xF8FBA9699CA2B4E5ULL, 0x647A317EF0138E56ULL, 0x4C91C94CD87E231DULL, 
            0x63637D13DDA95FD7ULL, 0x4CC392D3BB2CE8C1ULL, 0x9BB0552D2F72B50AULL, 0x3B033E798B62646AULL
        },
        {
            0x8240748B2EEBABFAULL, 0x84DC69F8A5593029ULL, 0x21AFAB8EC0E94C3EULL, 0x39ACB88F23C447C0ULL, 
            0xA3E743186E63ED1AULL, 0x6EC2E1177CA0A5C6ULL, 0x85A572D3CBEAAAB2ULL, 0xEDB41D9B7F28CC5AULL, 
            0x033348CCD30343B3ULL, 0x4F606F76F9752D2AULL, 0xF1B82C5378F44A0FULL, 0x1D03388E949D25A9ULL, 
            0xC2FCDB86780F4E0BULL, 0x06886081AC4A3368ULL, 0x1233CB0267C0091EULL, 0x9D802437D33A9113ULL, 
            0x763CF6D05D8A5293ULL, 0xCC8B638CB66769F1ULL, 0xF4C54E9D12C204A9ULL, 0xC43BF196776A3608ULL, 
            0x4D80C0E727F33E54ULL, 0x490F5CCFA0842C27ULL, 0xF87C2A30D298F7EAULL, 0x6025F7867DAD0A15ULL, 
            0x145406B4B355C682ULL, 0x4DD41464CF886B54ULL, 0xA2E187BED0F3D906ULL, 0x1BE0F7EFFD1F4065ULL, 
            0x8DF408D84BBEAA63ULL, 0xE05040D8BC3AFC1FULL, 0x826DDBA356D49145ULL, 0x47742528C3935967ULL
        },
        {
            0xCFBAB4366CA1B017ULL, 0x61DD717FCA057DA4ULL, 0xC842684FFD393052ULL, 0x827CFB98B6E474F3ULL, 
            0x1C7971BF7736BF7BULL, 0xA88FB15D2E7D3533ULL, 0x88161764DCA81440ULL, 0xEE42827D81291967ULL, 
            0xDE30FFBE1EACA447ULL, 0xF129AF16AF8ECA91ULL, 0x53CC1F62C0F61FB1ULL, 0x20D909D8E0D46F5CULL, 
            0xB64E8BC2EDAA2F0CULL, 0x0E8B1A3FDC4FCE63ULL, 0xC3E67EA8CAC7F6F9ULL, 0x879FEC11400F37ACULL, 
            0x2E6843567DC1D0FBULL, 0xBCB594871298EF52ULL, 0xD603C6B15ED39C46ULL, 0xEAC3BFE75EFAA20EULL, 
            0x58D4E5306005C5C4ULL, 0xA8767FBB9C3C0B71ULL, 0xD320EF3C445D5907ULL, 0xB99A935B4F96815BULL, 
            0x357F8AD79E861AB5ULL, 0x6A59183D92C85BAFULL, 0x5C47E3D7E22EC34FULL, 0xFE86EF113CF04BAEULL, 
            0xE3C9A243B174716CULL, 0xA795F6FE548DAB50ULL, 0x457610F749157DE9ULL, 0x3A9732FCF76BA06DULL
        },
        {
            0x86710DA45CEB0B4DULL, 0x32F7AC4051910401ULL, 0x9942F879EB1681B5ULL, 0xE69374B8712FC6E9ULL, 
            0x4EFB1C576C89FBFFULL, 0x774CEF188BE838BBULL, 0x364D3DDAEED61438ULL, 0x1F7A2204BAF1A590ULL, 
            0x3ADD3E688C7AC1CEULL, 0xB4FAE20D5597E6DDULL, 0x8EF57A3FB48A389FULL, 0x6FAB23B1553CA418ULL, 
            0x072CDF246C517AD6ULL, 0xF097DE0BD27B64D5ULL, 0x5C29590374DB940FULL, 0x9B70987699CD1B0CULL, 
            0x78DE8AA23B058418ULL, 0x39B686AF70ED8F25ULL, 0x0C0BD5AC6294828EULL, 0x76EC749548583AFEULL, 
            0x12AE7FCF8FAD0758ULL, 0xC1512D7B3788C8FCULL, 0xE86C1C4FE9588073ULL, 0x97319830DE385BC8ULL, 
            0xC7B7B7D8BCE31D9DULL, 0x84EF37E5D69A815BULL, 0x610523AEA95D7F47ULL, 0xF7AEBEC5D4EF7A37ULL, 
            0x56F5A10F0D1C3530ULL, 0xF28B43645A790F8DULL, 0x8D33CE11056AF598ULL, 0xD082D63EDEA491A4ULL
        },
        {
            0x1F5447BCA34EE89AULL, 0xDF9D3690CB3C45D5ULL, 0x78A299AA163024DAULL, 0x83E425A40828E37CULL, 
            0xCD4D9A3707426DACULL, 0x29C826A40EE76E1EULL, 0x3E296EA54A82AD95ULL, 0x3F9E3EA58795CC50ULL, 
            0xC43A22B6DF8AD190ULL, 0x39CBFEB9F41F882DULL, 0x3F12D3F59FBC1067ULL, 0xC01AD0B9AE92DD73ULL, 
            0x6EF134C324C457EFULL, 0x2D38492D7AAF93DBULL, 0x9E7F25A50ED5AED2ULL, 0x8432AAC178131650ULL, 
            0xD6B1463D26B3264EULL, 0xE4C443DE997100BBULL, 0x26F2F478CD688098ULL, 0xBDBF0C04482E73F3ULL, 
            0x0F8432CE0379193AULL, 0x9E1B58A89B85246EULL, 0x5FBEDFDCA3CD50CBULL, 0x55981235934A9573ULL, 
            0xB6BC973981EC629EULL, 0x5A95DD4D1047DD58ULL, 0x149857E1F08C79B1ULL, 0x0509EA944C0D2B64ULL, 
            0x137E881CC1AC971FULL, 0x5AD1A6F16A538425ULL, 0xB8C4B670E5E1C647ULL, 0x363ADD5601BA7F1CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseBConstants = {
    0x562DED1E938F6DB6ULL,
    0x134607EF6A5B68E5ULL,
    0xE14CB894C6D5A257ULL,
    0x562DED1E938F6DB6ULL,
    0x134607EF6A5B68E5ULL,
    0xE14CB894C6D5A257ULL,
    0xCC3518FC5EBD8526ULL,
    0xF8BF39CA10C035F1ULL,
    0x1D,
    0x97,
    0x38,
    0xE2,
    0x5F,
    0x3F,
    0x55,
    0xE4
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseCSalts = {
    {
        {
            0xAA5CA9E3C2DB49BAULL, 0x3A8BDC39CCF54DDAULL, 0x89D1189C287A5F63ULL, 0x9B6299FF9E956524ULL, 
            0xD334C28803E86FA7ULL, 0x016B1778F594BC5BULL, 0xDCB203B743803D85ULL, 0xC8833D42CDEFCF73ULL, 
            0xD5BB155561D55BC1ULL, 0x7D52C4135C46DCA8ULL, 0x2CEEADCCEE3F3CEDULL, 0x553D15AB03719F12ULL, 
            0xDC615CBA74603274ULL, 0x9D686C07D96A17BFULL, 0xB05F575BD1BFE184ULL, 0xB33D95F943688C6AULL, 
            0x6A8917373243078AULL, 0xE4778D2FC35E170BULL, 0x7A1F94226D946147ULL, 0xB89A12648C4B3C67ULL, 
            0x6CD59808C04A4158ULL, 0x639EA7D2C16B1DECULL, 0x57504EA14DA6FAB5ULL, 0xA5F132168AD107ECULL, 
            0xB2BC478695987D35ULL, 0xF5823C4DA658BCE6ULL, 0x2FEC6448DDEEBBC9ULL, 0x4CB9BCD99B272565ULL, 
            0x4177F7FB6A9DA4FCULL, 0x2B30C19C08508836ULL, 0xF87C33C7BD4E207EULL, 0x356E116B4FBD8E62ULL
        },
        {
            0x6EC36720E6846557ULL, 0x10A4A3DAA053E9D8ULL, 0x73081B24F89E2127ULL, 0x55A1FE7965B22FABULL, 
            0xEC89D799300F9124ULL, 0x35AF8BBE1CB54C28ULL, 0x8041FF074047C0B7ULL, 0xE0EDC7F8B8F1A999ULL, 
            0x66FE9A1D2591F367ULL, 0x3882626AE36A4B53ULL, 0x98C73AABAF3719A9ULL, 0x502AE4DF8D643E9AULL, 
            0x5924E5B7DD01A6B8ULL, 0x10061102B97CA84FULL, 0xAA789C44B3233075ULL, 0x4293F087F0AC5933ULL, 
            0x1CBCB9D3D5DDCA9AULL, 0x731D5F056A3641B7ULL, 0x3FBC2FB114055D82ULL, 0xC32C1BC0A97C1087ULL, 
            0xD1D9DE9B84880E33ULL, 0xD4A94845DD59B17BULL, 0x1BFBE2EDA3AB6C61ULL, 0x3ACC89CC1F90C02FULL, 
            0x78975B5C6F30C336ULL, 0x8E6A2EF8C9F6C99DULL, 0x0B50AC502352C699ULL, 0xFB8474570B910638ULL, 
            0x6B51A25149A07463ULL, 0xFC18049EC47D84E3ULL, 0xF40F3286E7DAC1FFULL, 0x17313CA23AC2DE3EULL
        },
        {
            0xCD658DC4371C7769ULL, 0xF6746E477A2E144CULL, 0x48180F07FD9418D7ULL, 0xFE101319A5104766ULL, 
            0xF61BCCA59631D771ULL, 0xA60E04A6233B61E9ULL, 0xE56E4FC3650024D2ULL, 0x88B801CFF7AB3129ULL, 
            0x33F3C7914E420F58ULL, 0x0ADFD87267EE8535ULL, 0x85B305EC6A720BABULL, 0xBFD9DDA0B0AAADC5ULL, 
            0x4A630E63D2A717FEULL, 0x07137945DF041630ULL, 0x6C319AACD5C07526ULL, 0xCF20E6A73020FBDBULL, 
            0x1BAAAD769C703660ULL, 0x832EA6F41A84985FULL, 0xFD0A31864CCBE3D9ULL, 0xBC72F5171E9EC060ULL, 
            0x92C51CC4326D7F11ULL, 0xCC3ECF03C995DC5AULL, 0xD2C3CD3C166D5828ULL, 0x967A37DA42B70EBFULL, 
            0x56E837987BE4CBFBULL, 0xFCF039F35F51C53EULL, 0x0504FDB2DEFFE2B4ULL, 0x5B2EB2401B288DF7ULL, 
            0x9DF9B2274FEEC711ULL, 0x1202E44C121B9FB0ULL, 0xA65FABEC6903D992ULL, 0xC695939F186E3DB7ULL
        },
        {
            0x2C9FA32ED15F3E11ULL, 0x4C10DC65EAD7755BULL, 0x544EEDF35A34CF3FULL, 0x9F5389DBDBAD9A1FULL, 
            0x1E29309CF51E9B03ULL, 0xB652279C2BE0B9A4ULL, 0xAD39CF2480E349D9ULL, 0xFE0D7F9AA296DEFEULL, 
            0xBFAF4780705B7968ULL, 0x4D6F10E6E2555DE6ULL, 0xD53F95602298CA7CULL, 0x35FE9FC98EEBF47CULL, 
            0xBD3C1E5EE82424C6ULL, 0x5CE9CE322B1C7AE0ULL, 0x980689FBD8E55184ULL, 0x53F7B1998079BADEULL, 
            0x4F7BA4F959218402ULL, 0xDBBD2284D7A87FA9ULL, 0x6F6C40370428E890ULL, 0x5253DB8CC10ADF1FULL, 
            0x6F6C763D027678DFULL, 0x4559173A8AB12B3DULL, 0x3A030483B17268C4ULL, 0xB275E22397AFFD2FULL, 
            0x92A7DF6E7D91D218ULL, 0xD6B8E8D4FEC1C822ULL, 0x13138E531A2B759CULL, 0xEB5FE40884DE20F8ULL, 
            0x621602063AE2C07EULL, 0xD627C8C79EC2165EULL, 0x5E5E4B38413D3B41ULL, 0x03FD3C0678D70E67ULL
        },
        {
            0x12FE85E570A6AD6DULL, 0x7BF422F6DDABE743ULL, 0x9DF226785651AFB2ULL, 0xE0A425B36C72E5F2ULL, 
            0xF4208CA817BF86F0ULL, 0x9F2BD6E3C9B4CD41ULL, 0x55DBBB40DEE1760EULL, 0xFA0A9464F175D945ULL, 
            0xD56CDBF11A9B7C1DULL, 0xA950A3CB0C7EF04DULL, 0x0D58715DB12AC574ULL, 0x85C620831FB29348ULL, 
            0x63297F183A0491ACULL, 0x3CBA14F22B18AD04ULL, 0x743E9F4067135300ULL, 0x4607BCCCEC0B28EAULL, 
            0xFF83BED32D981F10ULL, 0x7157D8FD489F45BDULL, 0x4107180130626FB5ULL, 0xA39BAFCC88A0A14FULL, 
            0x43D353ACDCAC0531ULL, 0x4677CC003F2E2350ULL, 0xB91F9E7E5566E566ULL, 0x7E8DF8FBACD56B5CULL, 
            0x988F546FD1169735ULL, 0x648503075280EA4EULL, 0xE6DC37465F51DC8FULL, 0x5955EC43FD3F6397ULL, 
            0x9B74C93E81FA5E65ULL, 0x2C9143A26E82E0A8ULL, 0x51D920CA716F8BA9ULL, 0x0A395D1304647A20ULL
        },
        {
            0x7B4DF5150EF32891ULL, 0xE8433CC5C2607442ULL, 0x237A56D39DB36D85ULL, 0x57141E692CDDFBADULL, 
            0x6CA1886EFE28EDA2ULL, 0x04210F13220A5061ULL, 0x479C3E711ECBCCD9ULL, 0xA921E179F6C04EC4ULL, 
            0x8BACF3EE02170DF5ULL, 0xC1297AEC700F2687ULL, 0x101B7CB04D8B184FULL, 0x79B92C51046DB894ULL, 
            0xB8924B22A88F08ACULL, 0x7D2F16D4C66BB88FULL, 0x28C91DAEEFF48930ULL, 0x84070D3B8A5C0148ULL, 
            0x8D11389DFB56AB42ULL, 0xE902F040CB499916ULL, 0x2D242804FC5F6AD2ULL, 0x8510EFA5694D532CULL, 
            0x662DA50EAC13E568ULL, 0xE009270A9EF751DBULL, 0x7FE228695BCBD753ULL, 0x384C516251DF4790ULL, 
            0x964E77410B88259BULL, 0xF01A1F45029412BDULL, 0xF91735D94D4574D7ULL, 0xAF948B096FBDD205ULL, 
            0x186D7F9B54DE746DULL, 0x47984BE447FD3079ULL, 0x2437B685CE8148E7ULL, 0xE8B31BC5E0DE3EB6ULL
        }
    },
    {
        {
            0x146C0FBFE750BC97ULL, 0x2A0344A5A2D16E1DULL, 0x58E9F47B52F47B3EULL, 0x42BA0E8FDE64DFD0ULL, 
            0xE2213236ED637D91ULL, 0x7422A1EF4BF6CC9BULL, 0x38392E8280EEA3C6ULL, 0x08818BFA11FB96BBULL, 
            0xF803542A454B77E2ULL, 0x8942836C8572BDA9ULL, 0xE567C2F3498B8C64ULL, 0xD3B876D96953BBF7ULL, 
            0xFAB2B2C23BAFCE01ULL, 0x29661A05210A29A0ULL, 0xC6DBDF70D57F5140ULL, 0xB245A604D083216DULL, 
            0xC63B0FDDDD1BB3F5ULL, 0xCCCA130691A4C28BULL, 0xEE0ABB5B1A6231D0ULL, 0x3E188E154D0E3A0DULL, 
            0xB938AACAB735FDCBULL, 0xB5C0845D82920483ULL, 0x0D98E21E5E4BEAFEULL, 0xCA2DDC0EB035EF85ULL, 
            0x930DF56BCCBE3EDBULL, 0x4B07926725D3C9DDULL, 0x1DAC0DD21D5223FCULL, 0xB86D986D8DCA7AF2ULL, 
            0xC09708F2C9AD75B0ULL, 0xF690ACC88C9888CBULL, 0x66744A54F0BB304AULL, 0x8573DD0FCDAE7F59ULL
        },
        {
            0x41E555A5591C0D63ULL, 0x2301DB0578A5B253ULL, 0x059101CEA7D7BC79ULL, 0x63F599E3F1C8426EULL, 
            0x6F4F12707E2CEFAEULL, 0xFC0B908F494D11CCULL, 0x68ED7E469CE70D4AULL, 0xBD21F5B26B1DF204ULL, 
            0x552808236E0D0DA3ULL, 0x0E9464B667DBD5DFULL, 0xE2379C8BF3C4401DULL, 0x09D661653DBC2930ULL, 
            0xF5195A69C686BC21ULL, 0x4C3FC1D8EA9C6669ULL, 0xFFB91156C049AF64ULL, 0x4417A1AA52C06473ULL, 
            0x6C60B497B3F0A10FULL, 0x506CCFD96081FBB6ULL, 0xEB64DBE2CDAFD577ULL, 0xD5C4BC9A7D1EF5BAULL, 
            0x2070B27D30141E9CULL, 0xCB4F3538E743F7E7ULL, 0xA7F18C2B15C8A451ULL, 0x53B4B5E389E5EA9FULL, 
            0x330C922C75FB9FD8ULL, 0xB0FD2312D8DD2484ULL, 0x1F0C1086DB8F6956ULL, 0x30AA77E358207752ULL, 
            0xF4BEFABA6599B88BULL, 0x49E13FDAD7AD6E1AULL, 0x76AB6F1FD17E8EA9ULL, 0x777512795E84CE99ULL
        },
        {
            0xF048321CCECBDA26ULL, 0xFFBE95D1B4D34546ULL, 0xC3C04180654657ABULL, 0x497E549E34205961ULL, 
            0x9501C3A5A97A7466ULL, 0x3CA7B401492979F6ULL, 0xD2DC782E2E702041ULL, 0x1B8511CFF0A6547CULL, 
            0x828EF6CEE01B0ED7ULL, 0xFA913469597FC9F5ULL, 0x865F1C0E1F89634EULL, 0xD7397B29803A6AFBULL, 
            0x598AF79996AD9DC4ULL, 0xE5A6D678F756D0BCULL, 0xB4040ABF4E7465A2ULL, 0x14372D8F5E1A6C89ULL, 
            0x18C341FEEE862142ULL, 0xCE279287684B936DULL, 0x889EE34A48A78576ULL, 0xD6846AD5AD91245FULL, 
            0xA09B2AB3F7586C84ULL, 0xF0A3DADF633A32F8ULL, 0x8CD1D72451F4B2F5ULL, 0x30969798EF32735CULL, 
            0x6CC0CBA22D8928B5ULL, 0x1BB6175ED1F79CABULL, 0x9FD9ABAF2905BBB1ULL, 0x112BCD389135B353ULL, 
            0x49479199EB483378ULL, 0x869A41442DACD3CFULL, 0x5746F9AC55E9EBDAULL, 0x78C3376ACA40B784ULL
        },
        {
            0xA6247C7F23E5CFC1ULL, 0x92F462B7D58D0247ULL, 0xE97D218C18477CFEULL, 0x3E14E667761FA86DULL, 
            0x71446CFC85786015ULL, 0xA46FFFCFC01938B9ULL, 0xA36F9F8E23B6B3BAULL, 0x22BB3F6A97CB3C7AULL, 
            0xD7922F5EE7D5EA49ULL, 0xA3856422ED89571CULL, 0x8E2181D7A2B410EAULL, 0x17617A68AE74D0C4ULL, 
            0x40239C76D4EE0258ULL, 0x160F3B524CCD0A9CULL, 0x5C0F581AF9D0134FULL, 0x145717AD8CA3A902ULL, 
            0x5C6B97E5C1A805B4ULL, 0x37261F5B4E6CAD70ULL, 0xF8F03451347740CEULL, 0x07C67498EE91A06CULL, 
            0xC232694B6D998842ULL, 0xADE26A3B11E53FE9ULL, 0x9084EBB3C3C018E6ULL, 0xA71CF549840C5B91ULL, 
            0xCA0C1C127BA9B4C0ULL, 0x4671E13C2B4F31EAULL, 0x608E367B85F732D9ULL, 0xEC4A66F2BEF4C590ULL, 
            0x8DAF566E6BC14426ULL, 0xEE9D56330780A89EULL, 0xE024AFC57F6D971DULL, 0x4D66996A38705FEFULL
        },
        {
            0xFAFC0AD5E4B62691ULL, 0x306A7CFB287C641CULL, 0x24F0D75357E3261EULL, 0x718F6A16F825D271ULL, 
            0x37504CE20DCB2BFEULL, 0x5EE0D3F1700687DBULL, 0x45E9FDCE735C97C3ULL, 0x0D7EEEFC00363BACULL, 
            0x62814E63A50CA9B9ULL, 0x3F9FDEF77CF3BE32ULL, 0x57C77AEF89F736C4ULL, 0xD14D3FB019CE2039ULL, 
            0xEDE631FF03D38888ULL, 0x62146146E3C64571ULL, 0x8A114185B524E456ULL, 0xBB5467D2F799D0A7ULL, 
            0x8C1D260510F11B69ULL, 0x1D350297AC51B6F5ULL, 0x69000E46DA2211D5ULL, 0xCEFD5D96B84FBF13ULL, 
            0xC9F522171D80A7EEULL, 0xD2258BE875CEEA64ULL, 0xEF7F4C0F631E6BBFULL, 0x491348CBCA3D0A2BULL, 
            0x45589276638485EEULL, 0xD0AEF657E2F1B447ULL, 0x6F78AA85E6A511EAULL, 0x1646DDD9C8B26E90ULL, 
            0xF5E634DAF56AF15AULL, 0x0B60A52B968EBC1DULL, 0xA976E2D5350DCF14ULL, 0x9DB736FDFB82AD4FULL
        },
        {
            0x3F256AA74A8FEAB7ULL, 0xB3726818FFE0B9ACULL, 0x82FE38AED8F4AECEULL, 0x4FEE687B011F3E4CULL, 
            0x18794AC4D7E70C50ULL, 0x181DB06BE905D5E3ULL, 0x5608E57554AFDA6DULL, 0x1776E7A40E167B01ULL, 
            0xF8B861FFBD4F90C2ULL, 0xF8F64D43EDD88E54ULL, 0xDB443097E8F6FB29ULL, 0x47BA07CC1E46A942ULL, 
            0xCC5C3621CD343293ULL, 0xE318E731EEF14213ULL, 0x19A8946D45859D5EULL, 0x2603D7F0763B6DE7ULL, 
            0x811D32DA8025EA5DULL, 0x94B1602FFEC24F2CULL, 0xD79345C3BCBB5809ULL, 0x9AAB2B85F9AAD193ULL, 
            0xC5075FDAACD23C53ULL, 0x880B8C5819CDD3E8ULL, 0x3761A3B1F6C72C19ULL, 0x999E7BCB70FCFD07ULL, 
            0xFD9526D1D2C8205FULL, 0xAAF1517CEBFAA374ULL, 0x7E0F9E8CE3C7CD7AULL, 0xDF98C33BF57FB281ULL, 
            0x3DA688640D2826B8ULL, 0x39EC5F1CC9D817D9ULL, 0xE08B3792F4B8817EULL, 0xC854A4728D6A737CULL
        }
    },
    {
        {
            0x390E26646DE91A87ULL, 0xB27934F776B15756ULL, 0x785DBCAF25FC9A81ULL, 0x1FED3FB4FDCBD932ULL, 
            0x19035257AA8821F0ULL, 0x2E8D24CB08FB6169ULL, 0x3315DC0008A1B217ULL, 0xB7AD70501AC48F81ULL, 
            0x577AA2F22F0453EEULL, 0xE276CB573F645F29ULL, 0x870A456EFE11C2F5ULL, 0xD658BB00931A74C8ULL, 
            0x0ABFF68833AE7E7CULL, 0x89A2D5414A7177B6ULL, 0x0EF248E5C175BA10ULL, 0x4DD8FBD92B63066BULL, 
            0xAE22A0E0B45310CEULL, 0xAA57B3DC8B18458FULL, 0xB0D3D9A17B16571DULL, 0xE8F5A41FC41B8CD9ULL, 
            0x3CF58019764E29C2ULL, 0x0F2FCAF54EAF0929ULL, 0xA31B2CB24F762996ULL, 0x8403C95AD4C6E330ULL, 
            0xA6DE49A7573EE0F1ULL, 0xAECE1E51A86122ABULL, 0xA008ECA3208DACA9ULL, 0xE874264BDFA530C9ULL, 
            0x1682BCC4EA247477ULL, 0x6AF57DBA8AD5F805ULL, 0x9733254711491051ULL, 0x90B48480659B6D8AULL
        },
        {
            0xFE5C966E82A0F3B4ULL, 0x4F4920AFBB288659ULL, 0x33AE93D6557A7318ULL, 0x2A259DA19EF65674ULL, 
            0x5B0BE3F259807D61ULL, 0x134EF1F0E12B8951ULL, 0x3BA5A3CA22B92BDBULL, 0xA1D61FBA3C4E49E8ULL, 
            0xD95D2F8727E6D603ULL, 0xE3EE76545CF35EC1ULL, 0xDDB7FE07CFD3C42FULL, 0x89A92FE3B5977B8AULL, 
            0x6FF5D1B3210E2F2FULL, 0xC2A61A8F680E0D6DULL, 0xFA7F2F243553E10EULL, 0xC0C8FEA3C73DBE81ULL, 
            0x49304DA8E8230ED9ULL, 0x23ACAD42D8C9CC10ULL, 0xD04BE5DF2B531224ULL, 0x245102DE72146968ULL, 
            0xAE61493FAD390323ULL, 0xB9613E25B7DE1D28ULL, 0x048223BD5007AA7AULL, 0x162E90AA7FA1D229ULL, 
            0xD3A28492F69FD9C6ULL, 0xEE67B82137DB4343ULL, 0x5B2E6B8DFEC0301CULL, 0x2E1054D4D5942C2FULL, 
            0xA8C9032544143E8FULL, 0x8E3982858EB0F209ULL, 0x26EB05DD0737A990ULL, 0x08080228DC773C44ULL
        },
        {
            0x78B2AABD22643C02ULL, 0x3018F2EB5C4882ABULL, 0x93FA12CF17F050A1ULL, 0xC8FC1275256F9A28ULL, 
            0xA589D537D510D66EULL, 0x0B548744A86C72A9ULL, 0x352BD38D49759223ULL, 0xE83FE74BC3610C5BULL, 
            0xAC3EA25831F6EF26ULL, 0x66AB3D2E9918D05BULL, 0x7FD5BA45F4E94A04ULL, 0xE800364580E43668ULL, 
            0xEF5727E80D30E336ULL, 0x63ACEE7AC0F3AA5BULL, 0xF30689AD236580D7ULL, 0xAAD5426B8D34BCFDULL, 
            0x2747E40FA6DB00B4ULL, 0xA8895A8A410FF58AULL, 0xDF7E56683EEA612CULL, 0x7FB2F9057417958DULL, 
            0xD2843CDE3D6DFC7AULL, 0xE7F2D1890470D963ULL, 0xE31038F83A7E1E35ULL, 0xB600E1B2B50AA890ULL, 
            0xD2DF475B1002CABAULL, 0x923A57D28ACE4AB5ULL, 0x16BFB75EA53B5205ULL, 0x6AB599BEFCE5B79DULL, 
            0xEC9BC0F11D5FAA88ULL, 0xFC8A8FA0738D038AULL, 0xE17F15C1F16E4E06ULL, 0xDE66EA9C3E69877CULL
        },
        {
            0xAA71ADF610DA29BCULL, 0x651E965FF2483117ULL, 0x1BF07EE01A66297AULL, 0xB557D49592DFDE65ULL, 
            0xB96DBB0831A94B1AULL, 0xB4340A9A8DFF3EA6ULL, 0x97CCEB05B23CD7C0ULL, 0x0E56561E37D7CBAAULL, 
            0x24D9FA5BE8F6D0BAULL, 0xC5A8191C5DFB842BULL, 0x6E12C0BF9C74C62EULL, 0xFEC6A17429577F7BULL, 
            0x921881CA3A1CEBFAULL, 0x78E1C57E7948C43AULL, 0x1063B2C65CBE4DE9ULL, 0x93FE20CF9FB0F721ULL, 
            0xCB9340B3D6AC7D41ULL, 0x8AD69C3E85ECA5EFULL, 0xEA4D4B3C2EF0FBBFULL, 0xA5AB41AD4ABDCB62ULL, 
            0x2089D5D56ACBD96BULL, 0x6C720E38811620A9ULL, 0x8BA2F710DF7F13D5ULL, 0x9071A78F9C7B6002ULL, 
            0x87E6E7F9354B106CULL, 0x69F78E0AA1B370F1ULL, 0xECF65A02E165D205ULL, 0x089D0027218ADD52ULL, 
            0x78F42D1E0DFC91DDULL, 0x5BC249D3A3A23E37ULL, 0x4369E5C000F7494DULL, 0xE03E2ADD7424E339ULL
        },
        {
            0x587FFCF1788B9D10ULL, 0x63BB19456A1CC391ULL, 0xA63A806B60099805ULL, 0xAC9FCBF9BAB5141FULL, 
            0x39168A58273EF4DEULL, 0x2E0EDA483F16BF8BULL, 0x3CC6D5570917BBE8ULL, 0xB582DC380A90AFB1ULL, 
            0x43C663C09094B577ULL, 0x8A4C0274892E65EBULL, 0xB186404C7F458A46ULL, 0xA932161A0D7431C3ULL, 
            0xD664F0E46F18C802ULL, 0xE484711C9F993F7AULL, 0x45A22E34F4296BB9ULL, 0x71DA0AB173800BDAULL, 
            0xF9C27607AE269E46ULL, 0x1B0182627D0AB33DULL, 0x398FE3EA93F21C12ULL, 0x208114690E87BDD2ULL, 
            0x4E37DDBC70A6122EULL, 0xC64E1DD730E6DD53ULL, 0x77D874A324B2A7E4ULL, 0x19EA50D4F1DF625CULL, 
            0xE29DC744D2461261ULL, 0x992B0530447ABEFAULL, 0x88316750EC020AADULL, 0x250C3E99F50D9952ULL, 
            0xBC2C3B1D394DDF7BULL, 0x991CD691CCEC23F5ULL, 0x283AFC158BE2ABF3ULL, 0x3CA741810E4C864CULL
        },
        {
            0x58EDAB13C1E6F8F0ULL, 0x8ABB5FF1BE40BC2DULL, 0x79815C39E34C61D1ULL, 0xB53B2AFD4A039A92ULL, 
            0xF5967D2427448B03ULL, 0x7054199BBEC46DAEULL, 0x8D81955E2DB76C5EULL, 0x43BA6C0186A7060EULL, 
            0x5D6DD2F440664556ULL, 0xF7A413C2B7504C3DULL, 0x05C363B47A74A335ULL, 0x9BE1BCAE5BD90B25ULL, 
            0x8502F06927AF7A6EULL, 0x7E1E0567D1432371ULL, 0xA3493AEEBC07E139ULL, 0x29787611F34D2DC9ULL, 
            0x977B18EFE81985E5ULL, 0x20C803EB18CCFA05ULL, 0xB90B5758AFA02314ULL, 0x58EF3C103728DE1FULL, 
            0x5BB82E2150085202ULL, 0x69DD66324202408EULL, 0xCDCEFAD54C9C8654ULL, 0x2628645BA58EA567ULL, 
            0xA9907C8D63027CE9ULL, 0xB53932A00034BA65ULL, 0x7C129268D0611ACDULL, 0x5755D3F990F5E249ULL, 
            0x3FDC37E681D6F996ULL, 0x1434181DF3703847ULL, 0x8F2232339B25AD1AULL, 0x63BFFF7F4412D5CFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseCConstants = {
    0x8682B6FF74EC0CD2ULL,
    0x3BB600A73E27F4AFULL,
    0x6723145286B1FAD3ULL,
    0x8682B6FF74EC0CD2ULL,
    0x3BB600A73E27F4AFULL,
    0x6723145286B1FAD3ULL,
    0xB4603CF93F75746BULL,
    0x23E37CEF045E343DULL,
    0xED,
    0xD5,
    0xFE,
    0xD9,
    0x89,
    0xA4,
    0xB7,
    0x58
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseDSalts = {
    {
        {
            0x3C2906E35494AC92ULL, 0x35661CA91F625C70ULL, 0x8E58FD75599AA9D1ULL, 0x9481B267C1424410ULL, 
            0xBBE4C36BC55ABB76ULL, 0xF6DDAE8FDEE55C0EULL, 0x43E178F487FCCDB1ULL, 0xB0369434EE4D0919ULL, 
            0xF55ECA7177E5E4C7ULL, 0xAA15801E1ED8AA86ULL, 0xECB2B7710F5C1473ULL, 0x7C2DD913A919236CULL, 
            0xF1CAD9BE0D443F79ULL, 0x49264DCCAE6AA572ULL, 0x5B8165475037E602ULL, 0x5DA06CF3EB65A572ULL, 
            0x802DC2D7F1DA79C8ULL, 0xB189E17AB00D8FCAULL, 0x99F2E878613EBE32ULL, 0xCC47B7CAFD569BB0ULL, 
            0x1E9C846AB5F82893ULL, 0xBCF977FCF3153FDEULL, 0x103502108D64566DULL, 0xFC150876A71A2548ULL, 
            0xC30C5A9C4E24F66FULL, 0x7A7C8E08CB86B756ULL, 0x18418B91308B2480ULL, 0x4378AA095483E8BDULL, 
            0x037F4965EBB29692ULL, 0x2E6F8C2E9207080AULL, 0x8C5396EFD15D6676ULL, 0x8C8F6D961F15A19FULL
        },
        {
            0x9CD0E3893624DD49ULL, 0x8739A1320DA5D1B4ULL, 0x2D81686FE7FD7752ULL, 0xAB72A34F0B646161ULL, 
            0x762B37D060DCB969ULL, 0x08BBB4094B31EA05ULL, 0x8614318D5F913343ULL, 0x825A773CACEFB00BULL, 
            0xE65A72CC41E82EA7ULL, 0x0A073352484FF338ULL, 0x4146CE9CE8F6CB78ULL, 0xBBCDDAD8367A280AULL, 
            0x9BD6581EC5B02C03ULL, 0x3223FCF7543B7854ULL, 0xD71A554857382170ULL, 0x58E58CA56E93CDF8ULL, 
            0x906F564D1932742EULL, 0x9324240C76DB0C71ULL, 0x0AE88E83864C43C0ULL, 0x9A59F8D1E9DEDD2EULL, 
            0xA7CD850AE72BECB9ULL, 0x8FD5ADCD59AD1AC3ULL, 0xEB006E20AC5B64F5ULL, 0xFC7BF16E895C893AULL, 
            0xA240DBE3A8333C09ULL, 0x90D589CECAFE8D54ULL, 0x3C1E608D0AB44A3AULL, 0x2734185FFF8454CBULL, 
            0x8F617A962A1271EDULL, 0xE10A2C394C02661EULL, 0x718410E281001FE2ULL, 0xB7CC85072F5F4E84ULL
        },
        {
            0x44BAE7A13CE667C2ULL, 0x56E041724E045C60ULL, 0xBBFD60C546F34EEDULL, 0x7ABED6E113CC652AULL, 
            0xE06A868C92376F2BULL, 0x9969AD79661AE016ULL, 0x05C882ECC9335DBAULL, 0x6ACB75D5AA3D54A7ULL, 
            0xE370CC6166A5840EULL, 0x7AA3292E9F72FA01ULL, 0x79F79F40F199C0B6ULL, 0x53AB9B9E2D8C5011ULL, 
            0xA43672F79DF2A8BEULL, 0xAF475884545552F3ULL, 0xEA6D5DE5D7E7DDFBULL, 0x9E74DF8822204B17ULL, 
            0xEC248843C235B5FFULL, 0x7F8674AC04414F22ULL, 0xB6D5CFB6B09B0BD6ULL, 0x020240A282E595ABULL, 
            0xE1C6C3889C783C20ULL, 0x996FE93526A2C80DULL, 0xF69E46F2E8B4B245ULL, 0xE521619B56A8E47DULL, 
            0x132FBAA2F37EB677ULL, 0x89702D60B44A1BB6ULL, 0xAB8D086B66B2460EULL, 0xC3F73D9F1D732966ULL, 
            0x59EB88D2326212CDULL, 0xE22B2D559761E347ULL, 0x73B5695BB4E7F829ULL, 0x78ABCBA97F24761BULL
        },
        {
            0xBAEE1AEB3E42F4CAULL, 0xEB471166138323BDULL, 0x12723BA823D475EDULL, 0xD28328C233F67C14ULL, 
            0x72C67817DF080715ULL, 0xF6627426E996B7BCULL, 0x146E2541470A01D8ULL, 0x9D63B3CF5E1BBDF9ULL, 
            0xF7CAF95AED2DC6B1ULL, 0x2BCCB9654713677FULL, 0xC4AB211C9E4A3C7CULL, 0xBB25BA6DC1CB59C0ULL, 
            0x63D6BB384D005E8DULL, 0x9335B7A6C0AD2203ULL, 0x1EC2B755DC8D2030ULL, 0x32730AB491FEAC8CULL, 
            0x23CF2F072D45B0AAULL, 0xCC0C92704A3D3C9AULL, 0x39AFE2C76D95B130ULL, 0x18AFD8E73C942FE4ULL, 
            0xFC7E109C453BFC6FULL, 0xB8D4AE68FC081B9EULL, 0x1CBA014C2E8CCE51ULL, 0xB791580D07B2138AULL, 
            0xC023FBE02C608A5DULL, 0x0809A2000A8C648CULL, 0x911D31623EA4FAEFULL, 0xD19FC1CCDA49EA89ULL, 
            0x16817A57DABCF782ULL, 0x02540B9CF4C63C7EULL, 0x97A7AF1E71A7370EULL, 0xC95BB15077CFD69BULL
        },
        {
            0x66FA54FF6EFD9EA7ULL, 0xAE5C6399093563B7ULL, 0x944A0DFBEC4375CDULL, 0xC9608F7062CE830DULL, 
            0xBC962A6C267792FEULL, 0x0E3875720D6149A9ULL, 0xCD042C8405625EA0ULL, 0xA446B7F9A25CBBF4ULL, 
            0x76DA164F7C955F0FULL, 0x2E135D9BB9CC5DACULL, 0x03014AFA61F3C0D4ULL, 0x38359C874EC3E374ULL, 
            0x42C4A4A88BC5463CULL, 0x81799741B36D888AULL, 0x479DBAB501971442ULL, 0x7BFF7D1EF7BE6659ULL, 
            0x542AF62ACFE93909ULL, 0x3C9F979B819AF2A3ULL, 0x56C65CF237A939E2ULL, 0x73099E97D037AC30ULL, 
            0xD06E0FE0AF5A5F1EULL, 0x3255B4430DA99C85ULL, 0x5E8DBBD3B41C5753ULL, 0xCF2D63D9A85EF6E4ULL, 
            0x5FDE84F74F9F18B1ULL, 0xCCB04A7FA8FDA2AAULL, 0x245DE86E3FDF5993ULL, 0x493ACC2CFE41036AULL, 
            0x945B7EA19EB24810ULL, 0x21A49003F37837C1ULL, 0x787285F414F1ABEAULL, 0xF4060272C92BD453ULL
        },
        {
            0xD11BDEB65238F33CULL, 0x8BB9D5144C441644ULL, 0x7BB8996672C46406ULL, 0x0B6ED323EDCF45E5ULL, 
            0xA38609132C7AA67DULL, 0xE0ADF58142E3FB03ULL, 0xBBCF24C6B1B2D13AULL, 0x73E3A9AB0A87F964ULL, 
            0x48ED8D9A9C2B219CULL, 0xAE6913F02CD3749BULL, 0xED570BC07DFE9515ULL, 0x35EDCBCF2715E1A3ULL, 
            0xE42F682641550358ULL, 0xEBA55BE015DC3C03ULL, 0x0792FA182AE76585ULL, 0x42B82967A1AE6CA7ULL, 
            0x101AD39E910A4C1EULL, 0x3BDC1B9481361195ULL, 0xB280B6F61FF454C0ULL, 0x8959A0874EAE0C6DULL, 
            0x28784578FC5084F3ULL, 0xD6D6FFD200B299E9ULL, 0x9ED3CF641E260EBEULL, 0x1C4DD2917377A5EFULL, 
            0x79391F3462BE890FULL, 0xF34CD571C2C4659DULL, 0xD97564FF35B08388ULL, 0xA2AC586E9CA31D01ULL, 
            0xE2B32BF058528D06ULL, 0x34ABD1B956C67C46ULL, 0xA96EF3C938986629ULL, 0xFE6E7763C7E41031ULL
        }
    },
    {
        {
            0x6D5F40534C9F8011ULL, 0x558FAABFA54C2882ULL, 0x6D9AFFB326D97293ULL, 0x8BADD1947DD06759ULL, 
            0x43A5924A61114A4DULL, 0x7D58F6F15CA19D30ULL, 0x49181CB1D60F49D8ULL, 0xEDBBE9996790241CULL, 
            0x9282038C33E5DAC6ULL, 0x4C1D3C76DBCCFDDEULL, 0x6FEB15A675D7F9F8ULL, 0x071851A4D7B9ED17ULL, 
            0xE5321B984E0B7CDFULL, 0xD3B26929A26BE8F9ULL, 0x2C7961344DFBC8A5ULL, 0x09C61820753A2EC6ULL, 
            0x4C85C0F41EA84C4EULL, 0x529BC4F262FFF4CFULL, 0x4E45939FE1D1C547ULL, 0x49B42227D6DB0E92ULL, 
            0xC679AF5E30497DA0ULL, 0x4B0208AFD8DE341BULL, 0xC9C7C613D7309175ULL, 0x6C3459350ED3158EULL, 
            0x6FF9817FA05E0E23ULL, 0xD668BC7B5EAA018BULL, 0x9F616C6809B24BBAULL, 0x23CA1F7AFE258826ULL, 
            0xF182EAF8014CC348ULL, 0x6181A2DADFB55069ULL, 0xD5BF0BB63F2BDAA1ULL, 0xD01A346DE52697D2ULL
        },
        {
            0x43C49F3C207A615EULL, 0x536B726A6FDB1201ULL, 0xE93464DC10ACB9ECULL, 0x0AC835FA90AB8528ULL, 
            0x7571C37FBC1B2DDBULL, 0xDA2EC7EF4C38D9ACULL, 0x294C8C0527F91E8FULL, 0x3EBC79D838276E3EULL, 
            0xEA65C4A5E029F482ULL, 0x7A4381E27A903D21ULL, 0xF4164B484135B1D2ULL, 0x06B8F5A147281C26ULL, 
            0x39B5F72D2AED8570ULL, 0xC733C58145CD4C2EULL, 0xB2009A67DF7266A7ULL, 0x29F930EE1278007DULL, 
            0x161B5CBD900AA056ULL, 0xF4B6673B0642A8F2ULL, 0x2A9EC263E01742D0ULL, 0xF9234A539CDC8447ULL, 
            0x7BBEDDA4EAAB495AULL, 0x8DA2175FCA357AF3ULL, 0xC0EC69D362C81412ULL, 0x8ECF611B16959C18ULL, 
            0x5C9A8FEC7F496E4BULL, 0xA3F205D9A8B2153EULL, 0xA75BB20D64DB9E61ULL, 0x4151C209D5F5DA60ULL, 
            0x9A8A4B36CC25ADEFULL, 0x7EE098A7899A25DEULL, 0xB2416643A16CD94CULL, 0xFF72D181F3F949F6ULL
        },
        {
            0x2FF61C5519695F68ULL, 0xB98B936D41AC3EA8ULL, 0x0CD06BF6BE8B82ABULL, 0x34785EB49696A4C6ULL, 
            0x011114AC809B82C7ULL, 0x3AA9F955296BCC48ULL, 0x901E42B1D6164385ULL, 0x3153A38891DFCBD0ULL, 
            0x4177DBEDA16F257CULL, 0xB2E6D92526BF8B64ULL, 0x6D446E553D10E8B9ULL, 0xA03AA3929F58FA56ULL, 
            0xD58C4F3794C51855ULL, 0x82432A7308EC7472ULL, 0xBA291F2CE477DB07ULL, 0x4B0BBEBAEE238194ULL, 
            0x4F8B25CA16F94A09ULL, 0x1CAD03823FC65573ULL, 0xF2258431B2509C0AULL, 0x875C76B986124536ULL, 
            0x7E23E4AFBCFDB6E9ULL, 0x94F7426BD9CD76FCULL, 0x6CDAE18B4BD77D86ULL, 0x2D76829F3E039CD8ULL, 
            0x80FFA696F24950C7ULL, 0x455683E53D1F7740ULL, 0x6F4B23E2A28E32C2ULL, 0x407CE21D25299E19ULL, 
            0x013E3A275419C3C2ULL, 0x8EDB64C1496AD456ULL, 0xE4FE679A52C53D6FULL, 0x392F839AE96E676BULL
        },
        {
            0x5A2895C25AEA67B0ULL, 0x41B4EDA1B0B97AFCULL, 0x18E686E98956C529ULL, 0x93699FFF1EA336D2ULL, 
            0x2C3A96AD63F45A7BULL, 0x04780EFA369E5642ULL, 0x5AEBE43E7184A7B2ULL, 0x79D9837DDB07399EULL, 
            0x4DA75F65C0150B23ULL, 0xFE14357FA95DF99DULL, 0xAD435036121689FBULL, 0x3907DC7B5E1DE1C6ULL, 
            0x2327A1DD14B0E159ULL, 0x54FE5EF9B5E51A40ULL, 0x0B267F27BA5623D9ULL, 0x3DCA6E3419A4315BULL, 
            0xBC3E9620BE4CFD78ULL, 0x04BB50B43559C5F7ULL, 0xF116EC21E36DE7ECULL, 0x21C0BCCCD86B0A40ULL, 
            0x0F623D284F9B0B17ULL, 0x2AAFF32410D8089EULL, 0x3F1257418900D617ULL, 0x96A888BB8AD95A94ULL, 
            0xEB8CC0FB63EA2CE9ULL, 0x0F010274E412B326ULL, 0x5E566158CE27D025ULL, 0x49797CD6A503CF17ULL, 
            0x35D4DBC2DF48123BULL, 0xFF061BD948261164ULL, 0x28CB67FB0362AFD5ULL, 0x85F85CA28D6BCF2BULL
        },
        {
            0xD1F8004BC4CA8BB7ULL, 0x706493FA9080B6E9ULL, 0x46487D519DFEAA49ULL, 0x86E99AF99A83346EULL, 
            0x41B0FD3C89CE6352ULL, 0xD3F4E3DB22F0E93BULL, 0x6D756CD3D1F35F9DULL, 0x3FFBAFA9116D3229ULL, 
            0x8171A14C63E884E6ULL, 0x93CEA78AC355B459ULL, 0x0ECA06E7AFC4B093ULL, 0x554EEFDB463FD2AAULL, 
            0xEA4D0B17F59B3B25ULL, 0x99CF73C9CBD5759BULL, 0x66C6A466CB6BD1A5ULL, 0x9FE5CE3C94294924ULL, 
            0x7A33F5C099A51134ULL, 0x44B8431BF6888E04ULL, 0x26065B0EB0FAF7E9ULL, 0xA68FFBD14124F05FULL, 
            0xB6C12808E9E2E2FFULL, 0x05EAC5A3003DEBCEULL, 0x0EB112367DC4124AULL, 0x62FEACCDD54481CFULL, 
            0xF7C27FAAE40653AFULL, 0x00B0FE878DCA28B5ULL, 0x64B97DED0C427B4CULL, 0xD766611F5F42FD71ULL, 
            0x070BB87615F0D0B7ULL, 0xCD43577C27255BB3ULL, 0xCA0410CA84321785ULL, 0x7A04E6A0F6F87A4EULL
        },
        {
            0xEA0D14FF3074B3B3ULL, 0x0A1B150A6BF2F780ULL, 0x81D6391AD272682EULL, 0xAB8ABE1F6AD935A4ULL, 
            0xD6DDCB7864646DF1ULL, 0x428CEB8BC82CAA89ULL, 0xCEA879187FE40045ULL, 0x32F77B22A2D108FCULL, 
            0xCB90759901B4E357ULL, 0x861FEBF562E038E3ULL, 0x8DC43F0871076ECDULL, 0xC5B206E260F16864ULL, 
            0x6DBE7CADCD85F9ACULL, 0x7D0C0974AA3C72BBULL, 0x2EC5728D1B479D1AULL, 0x4707246E14A87CE8ULL, 
            0x18743E37C552716DULL, 0xBC26512D32AC17C6ULL, 0xB0FE48548E5B7E77ULL, 0xF71C196377998CF0ULL, 
            0x08921EBAC4209DF3ULL, 0x203A7C2695CB7624ULL, 0x9CB1700B004653AAULL, 0xA66963F36425D232ULL, 
            0x3E1F8BB79A218127ULL, 0xB3556D7B97AFA872ULL, 0x23FE4ED2D19192A9ULL, 0x9AA1B65589ED4C5BULL, 
            0x48975E2325D1C064ULL, 0x38F0FB87C9549BE4ULL, 0x43F637E55C62EC84ULL, 0x29CE87B2CCCBA722ULL
        }
    },
    {
        {
            0xC611EB4284E8CA30ULL, 0x99938E6934207821ULL, 0xC376E029D1A5DB04ULL, 0x7BA30C5229736601ULL, 
            0x0B92C867A45F9753ULL, 0xC2176B8D42C226BBULL, 0x05D16BDACA05FFD5ULL, 0x1DEDC338D0569325ULL, 
            0x9A8BF52EB2F0E026ULL, 0x5C8B26B956A5D079ULL, 0x83F07AFCD0B270A6ULL, 0x535056CD45875B6CULL, 
            0x8844820BA2941777ULL, 0xC5A3601632365DA0ULL, 0x16F7BC9E4AFB529AULL, 0x1743050AC4D05575ULL, 
            0xD242F17A96D2B7D8ULL, 0x00064A39AE0D6E02ULL, 0xFDC76817D0419574ULL, 0xD55BDC706F51163DULL, 
            0x3D75A1A1E31AA886ULL, 0x2B4693A9CA0FF5B9ULL, 0x10AFBF0F1D6BA08FULL, 0xA54BB9ADEABFCB2CULL, 
            0x9CB093DC7710155DULL, 0xEEB85AD5A180C700ULL, 0x0322A8FE7A25DF11ULL, 0x5343F7A205BAEFDCULL, 
            0x3CAC5AF9E4A04334ULL, 0x0E8609DB6AC57DBCULL, 0xCD17BFA76F960AEBULL, 0xD8A4B2136DCBF5A5ULL
        },
        {
            0x050ED3DB1CAE71A2ULL, 0x8144EEF5594A643AULL, 0x5C52783DBE2268D0ULL, 0x0EFBEAEAAA05599BULL, 
            0x76CF9857D5BA9990ULL, 0xB78912DBF4F3E7C0ULL, 0x041A61DD5F72D231ULL, 0x36C70BAF0C5CE012ULL, 
            0x9A17C6BCE4F147FFULL, 0x265E9439350361F2ULL, 0x3BCC01C2132A6B9EULL, 0xB27909D9FE2996B0ULL, 
            0x638CD37AAB8AE90BULL, 0x0EDD28A95BC554D2ULL, 0x64FA2988D86541D3ULL, 0x1F119162ACC5C4ACULL, 
            0xA263E623E6326D32ULL, 0xCF3970C53AB81444ULL, 0x854CFF5E6A93C304ULL, 0x91A974499E922B02ULL, 
            0x2B4C7454531D7F2DULL, 0x9D5ADD1A47177768ULL, 0xC0D5A75D3A0DC28CULL, 0xCBE7294B61C44657ULL, 
            0x9E16972E931C796FULL, 0xCEE218F0DEB69B09ULL, 0xBD2D472CDBD5C998ULL, 0xCDD93C328899EC31ULL, 
            0x0AD5A8D4B34AF527ULL, 0x90CEAAC8F08C8286ULL, 0x4E688FF1BE5F3801ULL, 0x71CA6BA457DDA602ULL
        },
        {
            0x11194CBE9F8FE9B9ULL, 0x609DD1A088531A64ULL, 0xF741C72A50878BAAULL, 0xB557DA95DAF386A1ULL, 
            0xD05ADDABC9646E86ULL, 0xA398DA616F2DD8F0ULL, 0xB1D16280625B0CDFULL, 0x6E99B591B805FBBCULL, 
            0x0A74BB82A6086F66ULL, 0xF77EF495754B84BDULL, 0x1D5C7DD4581CF7A2ULL, 0xD18DC256F25A300EULL, 
            0x765EA4428EA1965EULL, 0xDC518989A97244F2ULL, 0xA3B6187663F524D0ULL, 0xF58F8474094D59DDULL, 
            0xF3C9F694A42FB7DEULL, 0x61B6F4CB08A70A26ULL, 0x96E72E0E39054157ULL, 0xC51CA2AAFDAEF48AULL, 
            0x966321CA8DD12B2BULL, 0xFD198D79730FAFC9ULL, 0x39A87C1FDE6FBA2EULL, 0xF149E88F836E22C5ULL, 
            0x678BFD2A321D44D9ULL, 0xCA4F4A63F557ED24ULL, 0xDE61FC6A05568B5FULL, 0xBBED52D1E95D7C34ULL, 
            0x2920057AAB30C0AFULL, 0x18A1597B4272C137ULL, 0x9F36CDD97F64E564ULL, 0x27D359B3FCD0EAFDULL
        },
        {
            0x67013E6669C3FA2EULL, 0x9C916BF4012BCB6DULL, 0xF912D9F7AEE1C01EULL, 0x28937DCFC102B0E5ULL, 
            0x6A7740937F4CEBE0ULL, 0xA1560C1DE100C20CULL, 0x8568C7044AE0C605ULL, 0x0AEE7D61F7FA6DEAULL, 
            0x8AD2ADB81F033503ULL, 0x4D55C0AC2C8C31C7ULL, 0xB8E1A6ADB3CCD801ULL, 0x646DE0A7F96EA199ULL, 
            0x0D2DB29FF959F7D9ULL, 0x66ABDFA36F1BCF47ULL, 0xE24494F46C172957ULL, 0xE7AC450F85BDA46FULL, 
            0xE5BE0FD814654E08ULL, 0x00C00BAE5BE4C565ULL, 0xB1E85B4E4323D328ULL, 0x2B2911694E030984ULL, 
            0x4117D2ADDF342935ULL, 0x00F477AADD48FADAULL, 0xB5B8221C375CACF5ULL, 0x4F2F97D8128D9E8BULL, 
            0x8C62FE22C6BABD06ULL, 0x2B24293EE12BAD27ULL, 0x73B221660B9E4CC6ULL, 0x9629B0959BE552E0ULL, 
            0x680384BF9CFAF5E0ULL, 0xE05037AEFE629517ULL, 0xC806DCA30BDF2734ULL, 0xF26212FED1F8015CULL
        },
        {
            0x95BF15AF9E0B73EBULL, 0x787573730876CD0CULL, 0x072C3A0B30CC5379ULL, 0xCB4309205FB56BA7ULL, 
            0xDD6901A4D334CB99ULL, 0x0578C50A83935286ULL, 0x167C45E986202337ULL, 0xE92BEF775DF518B6ULL, 
            0x38F3F2FC0432B541ULL, 0x6F6866CBABE30345ULL, 0x26396C2909CDBCA9ULL, 0xBF8C4ACFBC0F6E69ULL, 
            0xC231CAFCA3097128ULL, 0x4BB4E4742B664A27ULL, 0x35B39FD3F3624FDBULL, 0x60D0A16CA77B3EC4ULL, 
            0x3B2D30B8BA217121ULL, 0x2B931A4A153CF3D1ULL, 0x25C99896C0319CB6ULL, 0x79452D16264D132DULL, 
            0x159B4E759EA88ABCULL, 0xE3613FB725352E72ULL, 0x7E6E8CB32420F051ULL, 0x36E1BC69570C7188ULL, 
            0xC8EF141299E5CB70ULL, 0xE89BE2E62F56DA1EULL, 0x149FB7007CD56894ULL, 0x0062DE670B81D5AEULL, 
            0xDA50B8143E91BC4CULL, 0xDB81C01B997657F7ULL, 0x34E3D1C7DE9FEE39ULL, 0x465B0014AD81DF54ULL
        },
        {
            0xFC3EF933B4DBAFDAULL, 0xBAD6AD8364356CB8ULL, 0xB1C996B025BD391AULL, 0xA1C11B5BCB516CDAULL, 
            0xC3E3660462BE0BA3ULL, 0xF6080BF0AA155D22ULL, 0x69422952C6B89DA3ULL, 0x8E3D6B6B468498E3ULL, 
            0x902B20EE839AA3FAULL, 0x7B5B2D1F85FE14D6ULL, 0xFFC1725266B551E4ULL, 0x620DFEFB277ADCA9ULL, 
            0x2CE57B24E4A597BFULL, 0xDAEB1056198DDB0DULL, 0xF15CDCCFDBDE2D6AULL, 0xABB5736AA1B52B27ULL, 
            0x01C618BB665E0EBCULL, 0xF60416374C5022EAULL, 0x75DB9C15CC8EA891ULL, 0x6DF621F349B80DD1ULL, 
            0xC691A15DDBDDA892ULL, 0xBE78C2DCA8465AEBULL, 0x6617985D1F518E94ULL, 0x53FF20065D1A462DULL, 
            0x759BCA5DB14EF991ULL, 0xD3D53944AE5BC986ULL, 0xEAE7EAF01D602C37ULL, 0x16604F98BD1843C7ULL, 
            0x4C17A60203CF06D5ULL, 0x21D467B2183CA38FULL, 0x56E92B0FCBC5642EULL, 0x636713276C69C51EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseDConstants = {
    0x46E21ACE391DC0A3ULL,
    0x7928306A36BCBC0EULL,
    0x3E8793F3C6B6AB01ULL,
    0x46E21ACE391DC0A3ULL,
    0x7928306A36BCBC0EULL,
    0x3E8793F3C6B6AB01ULL,
    0xFA283DCBC64302EDULL,
    0xB68B6A560462452AULL,
    0x98,
    0x46,
    0xF5,
    0x2C,
    0x49,
    0x7A,
    0x69,
    0x72
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseESalts = {
    {
        {
            0x8AC80404382D3C59ULL, 0x8ED406DE9D244A37ULL, 0x72A16374DDEED083ULL, 0x9634FDC743670046ULL, 
            0x2D36D23B2891E193ULL, 0x68A627DAC1D82C56ULL, 0xA56F1CDDD76CE556ULL, 0xD70D1465C5FC7153ULL, 
            0xA4B965E198BA7B45ULL, 0xBAA4D15D1FBEFCA3ULL, 0x62E9B4D5BE1A8660ULL, 0x60F71809837137D2ULL, 
            0x34ABA42F15B89BB0ULL, 0x188035435C885543ULL, 0x7057EFCBEB54BA0CULL, 0xF8D0017CECBFE38FULL, 
            0x76E1398F7974B5E4ULL, 0x5AD2DD926604F323ULL, 0x8A59AC880C5F8DBBULL, 0x540F509C28B6EFEAULL, 
            0x31446A10D2818E86ULL, 0x0772AB2044164A31ULL, 0x51CB342F4DBD11D1ULL, 0x7A1DD9D2F701B1E1ULL, 
            0x5DA9ACC983D5F484ULL, 0xAF8CF38ED0C0602AULL, 0x01C40C4333A971F6ULL, 0xFFF9EA1255D3C8C7ULL, 
            0xEC97CF1DCAD037A9ULL, 0xF0391EA1A597340DULL, 0xF9D65FA5B026F33DULL, 0x29B009CD1723F698ULL
        },
        {
            0x39ACBB0872C6484CULL, 0xB7161DC111053754ULL, 0x802D8C169ACA9F93ULL, 0xF8F88D66030397CAULL, 
            0x92D26BDA3B0462B1ULL, 0x0D9F450D5D554D52ULL, 0x795D0506AA3594EDULL, 0x2E628E5D981FD06BULL, 
            0x8FC3703BFD08D3B2ULL, 0x51C7701F2FA04AD8ULL, 0xD8E4A2291B0D21B1ULL, 0xAEA79C34F9229776ULL, 
            0x88BE6C4EC8C55BC6ULL, 0x63DB28D045151561ULL, 0xA8236DC8D045C8AEULL, 0x9221432C0546375DULL, 
            0xA166DEB975342FFAULL, 0x94A1B3F199DB975AULL, 0xBAA4BFBFFB8BC04FULL, 0x9D48F83322CB8ECEULL, 
            0x070D66902D119F03ULL, 0xEC15A7A2DD719036ULL, 0x8783DCC5E5E65C79ULL, 0xC076E45236212336ULL, 
            0x9F2490BE17D1D530ULL, 0x8F33AD32B9CC31EAULL, 0xC9A3CBC419F3E47BULL, 0x86E322FA7D85B85FULL, 
            0xFF2A3787609F933AULL, 0x7CE3F75A1AA1CECEULL, 0x697D01736586217CULL, 0x65A38F6D59A3B768ULL
        },
        {
            0xBB5D98B624A9C9D0ULL, 0xFA0B72B9A63DFA02ULL, 0x0FC30B9C8AFFDE6EULL, 0x3C6E16EA67CB8750ULL, 
            0xB85CB55D3EEDEE11ULL, 0xBC8186B61D136BCAULL, 0x3FAF2696F4BBF72CULL, 0x56A87CD22FCB05C6ULL, 
            0xE7F1200E5E3D51BBULL, 0xF11A457F0081FB01ULL, 0x7BD0BC3C9E14CA6EULL, 0xEC963203BEC8DC27ULL, 
            0x19B4993A09F53850ULL, 0xFD4C25C5943EB205ULL, 0x2FAFEE9302BA86D3ULL, 0x8CDA6BEAE4CB866FULL, 
            0x079279742CAA654EULL, 0xF178AB3B2385ED50ULL, 0x5958886DB4B6B861ULL, 0xD7DDA907060E5162ULL, 
            0x24DE3A44F70D25B7ULL, 0xF384E974678DC2D7ULL, 0xBE35E8DF1D2D3315ULL, 0xF712300F463E8A7CULL, 
            0xBE933DDDD8DAC543ULL, 0xD4D081FE7EE3C7B4ULL, 0x72FAB28A4B756834ULL, 0x9E96B5C4C56F8B3FULL, 
            0xB5DD42DE5F456D72ULL, 0x76F52CFA3CE743ABULL, 0x15CF3D4DB78082E9ULL, 0x86C8A6ABD8634C3BULL
        },
        {
            0x5E106DD3EF235BA4ULL, 0x7B1A4DC542D1B47CULL, 0xB4FCBCF36E359348ULL, 0x565096C886C7DEA9ULL, 
            0x7184CA3CD970FBC9ULL, 0x642063F668AB6632ULL, 0xAD825D43DAE145CBULL, 0xECE5A47741A21124ULL, 
            0x5D23E7827281561BULL, 0x9D2C3B7C8248A32BULL, 0xD2AB1C8CD2479C1DULL, 0x0EEE28AE3009D4A6ULL, 
            0xACBB1AAC21219261ULL, 0xAC3A001612062E90ULL, 0x820F85F2B90E992BULL, 0xC3FF6C9B3DCDFB8BULL, 
            0x7264425F0D3C7F3CULL, 0xFA3409882AC546E5ULL, 0xC96A268CA348019CULL, 0x6848C4C7D317AABFULL, 
            0xD19186CB4AD1A223ULL, 0xAFE53AE1A08F2A67ULL, 0x8722F936F8576A3EULL, 0xD6FEB2B45E62C21DULL, 
            0xF3B76736C2D86B64ULL, 0xB845ABB269811317ULL, 0x739A6D006803933EULL, 0xF2CA14A1B9CF95DEULL, 
            0x8173D202DA36D2CDULL, 0x04454AEA2869F0A4ULL, 0x6E8B1839D6A1D414ULL, 0x0D8A44C452E74C10ULL
        },
        {
            0x8194F1071B486AB5ULL, 0x0C3C536E2B865DEBULL, 0xAA12E6D9BD0BFC6DULL, 0x93396960DD44E4DBULL, 
            0x42DB4394EB92964BULL, 0x2CE079E9238E6634ULL, 0x483BE9D3A7F94631ULL, 0xB2E063AB2730E5B1ULL, 
            0xE8053C5B71F5B343ULL, 0x18F33D741E7D6110ULL, 0x1761C1DBCDDFA56DULL, 0x4833301C3A41E75DULL, 
            0xE0534296ED296B6EULL, 0xB56FC5EF87441CBDULL, 0x83B2E458E20D355CULL, 0x5A58E8E851A7873FULL, 
            0xC3BB1AF8D4EECA4EULL, 0x48D2E8FE550DFC58ULL, 0x6731676AC59A69CCULL, 0x137A5918CA2A0C99ULL, 
            0x026D9D96004B9363ULL, 0x6F999BAFB9EB576AULL, 0x9FEB80531683A741ULL, 0xCD9200C5F55CAAC0ULL, 
            0xA1143B62B43646DFULL, 0x210B09D61B3536C7ULL, 0x0ECF592598C554C3ULL, 0x3B320E5F88FD1214ULL, 
            0xBE94A2A200CDE456ULL, 0xDF97268D2ACE3E78ULL, 0x75DA482820CACAC6ULL, 0x858E40C7A9D9AB37ULL
        },
        {
            0x0CF79DB13BF1A276ULL, 0xFCF7B3FE1EAA1F6EULL, 0xAF08567EA915D7DDULL, 0xA4EBD4635EE6CC90ULL, 
            0xAD1D73F60ADD0A19ULL, 0x821293429E26BDD8ULL, 0x783A9B7ED6F06FDBULL, 0x3846FA0D7B5AEDD4ULL, 
            0x6CA036D0C83BC982ULL, 0x42B106EED0287E0AULL, 0xBE1B5EAB4A890496ULL, 0xFEDDF5E6465B08DEULL, 
            0x79F5AE42890F51C5ULL, 0x7B4E0CE72B6BD060ULL, 0xC7E08FAB9C18826CULL, 0x6DADF6A73BCAD361ULL, 
            0x443A541E1060E8B4ULL, 0xF7F3EB3A60B11DD8ULL, 0xF708F28AD16FDA44ULL, 0xCA92CBEBA1783C1CULL, 
            0x5BB19B750793BAD4ULL, 0x7597BA83BBE22194ULL, 0x78830C283F440602ULL, 0xF3B1146FA76334C8ULL, 
            0x442372D7F1B6B09FULL, 0x0573F46D2822B914ULL, 0x04EA1C228B51AAF4ULL, 0x9A01402DB16F07D6ULL, 
            0xAE85B3613F10F17FULL, 0x5A0FE2546D0BCED6ULL, 0x54F0CDC00D998387ULL, 0x17C75777B4C9CAFAULL
        }
    },
    {
        {
            0x70B99FE65D596843ULL, 0x85C1C266426508F2ULL, 0x4816F0FAC5431A36ULL, 0x1AA7260FA8CD24EEULL, 
            0x1A50D4B8748DD710ULL, 0x2C33CB87FA23A67AULL, 0x712F92D62904D6D4ULL, 0x477775116CB7582BULL, 
            0x4C6A92839D51AC1CULL, 0x8C50FEBEE77405FBULL, 0x7B80D5B7AA9A2633ULL, 0xF9DFD8FA3FCA897CULL, 
            0xC665F0CF820A43C4ULL, 0x81D27B864EBFD215ULL, 0xDB3E73B983371A8EULL, 0x8D18B0B10E119916ULL, 
            0x3F114F106BD5B260ULL, 0xE670406F01A4457BULL, 0x2F125C6B4D6B6322ULL, 0xAE8969C4E7C1385FULL, 
            0x84A168C0C73614D1ULL, 0xF082375246580F07ULL, 0xD0458D1A5B48604BULL, 0x93A00046AEC281DDULL, 
            0xD04E97DBEFA0EEC3ULL, 0xD1FA5BF2B886B7A7ULL, 0x18BF7AFD05BFCEBBULL, 0x78A323CC385AE461ULL, 
            0xFB708955A469109BULL, 0xB297D34E13ECD4D8ULL, 0xC3E5DF7AD9B3B51FULL, 0x3E47518B915D1619ULL
        },
        {
            0xB43203776CC03553ULL, 0x4E59C6AEBD05F0FBULL, 0xA772B7948671E849ULL, 0x371E04360BDD50F8ULL, 
            0xD19EE1A6CAF8D53EULL, 0x11D6BB87DD4BD50DULL, 0x371AEFA7842F1BF9ULL, 0x19B2196D0F8FA880ULL, 
            0x61432237A429B389ULL, 0xD3EB15A2EB77B623ULL, 0x5FD29C645E4929C3ULL, 0x5F9CD7DE258F1BC2ULL, 
            0x76BF875728C815C2ULL, 0xD760E8BAA7305C1AULL, 0x9058BAB978B9FC44ULL, 0xBE8AC37A88AC5834ULL, 
            0x646050031075CEFDULL, 0x3D901423219FDADAULL, 0x7D22DDE49820989DULL, 0x02BFD0B5252E17BCULL, 
            0x67B4AF359B646EECULL, 0x129DB141682FB1B6ULL, 0x2433F3CFB68AE69AULL, 0x6EA2988EA933ED4FULL, 
            0x108179FAECAEB506ULL, 0x17F21011956A5979ULL, 0x74809EE4F1699D97ULL, 0xABDF5F4174B29589ULL, 
            0x9812AA64194F5C7EULL, 0x456D0052684CEBE2ULL, 0x757605965A6ACF02ULL, 0xF2958D47D585105CULL
        },
        {
            0xE9EDAB7AA13B3F33ULL, 0x8049B4E40E636282ULL, 0x9AAA1B19888AD35AULL, 0xBBE46B754126A709ULL, 
            0xC8C15CF9B98873C7ULL, 0xBF5127D773B647CBULL, 0x48A53ADDA1DC1CDBULL, 0x5F0042B2A4BBDB96ULL, 
            0xB6C8A70A151C381BULL, 0xB908D5C640A53630ULL, 0x1A18334BBA024326ULL, 0x037BB229672A80A2ULL, 
            0x36614A2E3019A8D4ULL, 0x7BDB4DE441D7726CULL, 0xE778FE7A2E004A3DULL, 0x4EA96CB00008FBDAULL, 
            0xBE28EC3E545D3801ULL, 0x3029272D1AF53193ULL, 0xD791F0C81A87C327ULL, 0x8C1181E8890F83BBULL, 
            0xCD6891E6C70A175AULL, 0x73CE7CB5A89C75ABULL, 0x9DFE184062A95F45ULL, 0xD58015882AFAC0B4ULL, 
            0xE9EA323FD485D2FBULL, 0xB5E91FCC09B70E19ULL, 0x2BF8E4C8D69A8756ULL, 0xFC69D9963110C3AAULL, 
            0xEBC6DA44750560C3ULL, 0x7948EA15B5C08355ULL, 0x7F514C6D69FF68F4ULL, 0xA2528CBCB2BC8C22ULL
        },
        {
            0x26A9194ECB8AA537ULL, 0xEDB5CE51355AC5D1ULL, 0x248C2BBFFE3FAB1CULL, 0xF42AC7143E464C46ULL, 
            0xCB62C9EFD19E9671ULL, 0x18CCF2962F5370B5ULL, 0xAA110B9E3ED97B72ULL, 0x18B39DB2A4784FA5ULL, 
            0x3FD99972B5805C46ULL, 0x3F375276CE73F51AULL, 0x6E4C161800A087C3ULL, 0x6CC53078C00EBF5FULL, 
            0xE6222D2672215BD4ULL, 0xCB7C3C0A419240D1ULL, 0x322EB95B2EED13ADULL, 0xFC2C09401CD173D1ULL, 
            0xD3636D52D96925EFULL, 0xDAA55BA7093482E9ULL, 0x425AB0EACE856EBEULL, 0x0BD3D4FA0DB123F5ULL, 
            0x7774AA79104234E4ULL, 0x190AC06AADCF03A3ULL, 0x76A81DD57A16A70CULL, 0x936E0CCA667990FDULL, 
            0x99BAF64134C93809ULL, 0xA7AA5760B928DFF2ULL, 0x36BD363B9EFFD11FULL, 0x727929CD860FE1FBULL, 
            0xB776862CA7360272ULL, 0x2E5DE2D6B026434AULL, 0x2C67D4E12AAA41B7ULL, 0xEB5D986573DDDDD7ULL
        },
        {
            0xCFC1301FD3313402ULL, 0x0048FFE4118F1AB1ULL, 0x84697AC0EB6D0C06ULL, 0x2BE80BF44E8A5D52ULL, 
            0x20B0F20964D913BAULL, 0xE2700518077D6A5AULL, 0x6A4DD533171BC9C3ULL, 0x25A607CB04AEF594ULL, 
            0x03961C62D5AFBA4EULL, 0x9B72B1DB33DE757AULL, 0xC19384F13C4DFD46ULL, 0x081EEB82E2C1054FULL, 
            0x1C046295CC83B025ULL, 0xC30ABC296C20AA2FULL, 0xB3F078D4A51B0A61ULL, 0x663803802C0399A7ULL, 
            0xC8CFD1BBB7CBA7DEULL, 0x37DFB7605D4C3FE5ULL, 0xF8CEAE77E2295CEFULL, 0x8D48CE0B1DF33645ULL, 
            0x4768126D67E6BF02ULL, 0x84CA3D8996F3304AULL, 0xB37558E7B1268049ULL, 0x5F554DE5077CF119ULL, 
            0xAA8ECA514CCD833CULL, 0x83390E81A3EC67BEULL, 0x68047880C8C99A16ULL, 0x92657A5A9CA40BBDULL, 
            0x006A5D58DEC6B198ULL, 0x5B4F5F6F16A8A41EULL, 0xAA7BEE34BEB29298ULL, 0x300FDEA7287ADC84ULL
        },
        {
            0x7EFAE4B967999B42ULL, 0x9D965CD90CA369D6ULL, 0x91DB47250E139D93ULL, 0xB60A05BD841B0BBFULL, 
            0x9822A8018595F206ULL, 0x170CBC080CE52E91ULL, 0xB1006F551B8ACFA2ULL, 0x9AE066CA001ED14DULL, 
            0xB9948371CC3C56F4ULL, 0x50D481420CBF12ECULL, 0x4B49C9FC570E0FB2ULL, 0xD73E38A94542D7D9ULL, 
            0xDC6BF67ADFC1B494ULL, 0x1FF01BFB0BFD0C60ULL, 0x822A35DC167A6C6FULL, 0xC7E11EB2EF055B5EULL, 
            0x8F344975B9821806ULL, 0xD365D19F16C76767ULL, 0x9BB69D3CD480C995ULL, 0xC134EC611EB80BEEULL, 
            0x36B56E7E26B7F502ULL, 0x87F14DEA48EDE32EULL, 0x3B8CE0C28E82A955ULL, 0x2376F6029E9EADFDULL, 
            0xC58A7679345F336EULL, 0x07493214B4227EF4ULL, 0xF891A00074F69360ULL, 0x6215AFF393BC34B6ULL, 
            0xD9FA2FC9644679FBULL, 0x9F1A66213614CB36ULL, 0x63FC05D56424B862ULL, 0xF9B0B9A7AEDCD722ULL
        }
    },
    {
        {
            0x7531DAF3878E0504ULL, 0x6C8630C298B8737AULL, 0xF45BB78C8B54B607ULL, 0xD89C1C02DD53F3BAULL, 
            0xB628A9372A9A4816ULL, 0x4DE88FA3058E843AULL, 0xD2E22C8E28790BAFULL, 0x25248C8AD12A2303ULL, 
            0x3B10A6E64502A92BULL, 0x44613E09AFC5A24FULL, 0xCF61CA73070961D8ULL, 0x718F22DB424CBA64ULL, 
            0xD4971F84312C48BBULL, 0x6100B678D09EE06DULL, 0x7129860208C8DC51ULL, 0x00C0C2EB7AF1B297ULL, 
            0x3242B80AFC907636ULL, 0xB22695F3EBCE85CEULL, 0xA7ABF252C3942BACULL, 0x750C0E9CF381AF82ULL, 
            0x18670E1319DC4A2BULL, 0x74C157481628F987ULL, 0x9127D762D5E9D61DULL, 0x80EF1CD3406032E8ULL, 
            0x48B8C6703866C48FULL, 0x5A59C4C2B563C255ULL, 0x574EF365A6B93BAEULL, 0x0FFE479D8356094DULL, 
            0xE93C52AECB8B4282ULL, 0x9624EC3FDABCF714ULL, 0x55DAE04683F8D0C6ULL, 0x4CF6EA5C69F60590ULL
        },
        {
            0x40EA6080922948F4ULL, 0xB98AD5CD470BF548ULL, 0x62A0220C37E2F7B4ULL, 0x74C642F21215417AULL, 
            0x890AEB94DEE3E6E0ULL, 0xA301658DE0E1741CULL, 0x93FAE215CAFF4A66ULL, 0x3241FBA82FEA250DULL, 
            0xBD4076A1F78B55FEULL, 0x2B5A94885AF98099ULL, 0x68DDACC098213DEBULL, 0xC77AE60894046EA4ULL, 
            0xDF7392D85D34C314ULL, 0xD5A5A91A72FF4165ULL, 0x2EE31F2D36EE583CULL, 0xD3ADB21D3724D00DULL, 
            0x19D31B47BE5AA301ULL, 0xFF5055858F474796ULL, 0x81BFEDB8C2D7CF6AULL, 0xF05C93E27DB309D4ULL, 
            0x38EF9C4940A4872EULL, 0xA0E1C330F08EAD4BULL, 0x378166C33F794D16ULL, 0x90440099540A034DULL, 
            0x7942858697E9DBC3ULL, 0x02D5EE4C1995479EULL, 0xA6A114E8650F3C16ULL, 0x4C57AF08D73BFC46ULL, 
            0x4EC46F4C67C58FA7ULL, 0xF174674BE709B21AULL, 0xC2E9980DE07BF1DEULL, 0xC494EAF0DE8843B4ULL
        },
        {
            0xB75CA81949C6D8DAULL, 0x8433527F2C1F20CEULL, 0xEDCA2E077A2C0A7AULL, 0x88F9415DA5CB87C4ULL, 
            0x73DC73950B2890D6ULL, 0xC9B85AB92BDF0A78ULL, 0xE0A9BA3146BC7812ULL, 0x6B8AB884DA9BDA55ULL, 
            0xA3DFA3390CB2956BULL, 0xBDAB11A464B84EACULL, 0x8C3927B191099DE8ULL, 0x7901511F7B225286ULL, 
            0x773A04712792CE11ULL, 0x09A1067747F8E1F8ULL, 0x79C847D50B66FCE8ULL, 0x6BE20067FEBCD6F3ULL, 
            0xB87957D51930979CULL, 0x3D38004A87FE3FA7ULL, 0xB9D05F94928E8C4AULL, 0x335790353FFB6C9BULL, 
            0xD1DE4C80751B1FA3ULL, 0x8609BB5C9945D84EULL, 0xE6B88DEF14770DFDULL, 0x510AD5D0228FFDF9ULL, 
            0x25ECF07F7AE34EBFULL, 0xE1F164FF21B0CED5ULL, 0xCDD13AC65FDC6841ULL, 0x2E984FFB4FBCE552ULL, 
            0xD437E50C7152338BULL, 0x811330C2EDC87FF0ULL, 0xA86A55752516F8EEULL, 0x17954A54D44AEC37ULL
        },
        {
            0xCC5D79297D43B93CULL, 0x8DC71E44CD4F6655ULL, 0x213C74DB76BEF4DFULL, 0x8D0E947D72F36499ULL, 
            0x78587059DCF97086ULL, 0x0F15B60F47A70487ULL, 0x4DA5200A4591B1A4ULL, 0xB15258A772B51B68ULL, 
            0x098CCF209C20FBA3ULL, 0x4FC11D4957E46D20ULL, 0x421F305ADB52BB58ULL, 0x5D473CB976AAB78EULL, 
            0xB16034DAB77FB666ULL, 0x8E1D67F4DB62943CULL, 0x2D08A546B0D37D46ULL, 0x93EC3A1E2C543B39ULL, 
            0x30AB9229A159A974ULL, 0x59C64357D496F50DULL, 0xEEE86F2952A1C22BULL, 0xAB91C5EC8D961741ULL, 
            0x3B112AE0BDF21661ULL, 0x376D360F71D3DA20ULL, 0xB0FD8B638F4C0CC1ULL, 0xCCAE22C6A2BEC916ULL, 
            0x6379FE175DC9B759ULL, 0x2D941223A67ECB3CULL, 0x8D06599271ECD9F5ULL, 0x1F29603E1EF5D6ADULL, 
            0xF932855F47CFB1C0ULL, 0x2A5736002B7ADF58ULL, 0xE159AD6929BE67C4ULL, 0x431750FFD281F15EULL
        },
        {
            0x9336CDD715F9E33DULL, 0x88AAE575597455C7ULL, 0xC28A1E44D2C15486ULL, 0x06F27BF4200F8A1BULL, 
            0x919538326087E3B8ULL, 0x89721FC73C593F8BULL, 0x58BA03103CEF40C7ULL, 0xC60AB0EDE33686C5ULL, 
            0x75DB410FA88D81E0ULL, 0xB11B211666E36F68ULL, 0x1D954D99EFBB40A2ULL, 0x2BB88A68E9D9046BULL, 
            0x7531EF60B1BDFD5AULL, 0xBE43BFD9D4D62BC2ULL, 0x4AD4186F9ADEA374ULL, 0x6FB4C8FFE58883C9ULL, 
            0xD13204B2299D2100ULL, 0xB9B13FFE381166E4ULL, 0xFCB853EE02894D54ULL, 0x1AC463ECFC6A0FACULL, 
            0xB3F32B04897B6CC1ULL, 0xF7128136D7FB870CULL, 0x26D1E0DF738C9616ULL, 0xCB3B06866F76BAFBULL, 
            0xCAD1C9A498A23ADBULL, 0x9AC30A91EDF88989ULL, 0x80C58616AD49E10DULL, 0xC01D7D3D6E0BF5F4ULL, 
            0xC365BD339D702FA1ULL, 0x2BB274C99DEC25C3ULL, 0xAE0DC6D71C1177BCULL, 0xE40137939FCFCDF6ULL
        },
        {
            0xDDCC23DD4389219BULL, 0x871B5CF1DC1E4D95ULL, 0x7F07E91490E97E19ULL, 0xBAE4EDB09AB2BD45ULL, 
            0x248633DC1D2A6951ULL, 0xD59933D8EF4D5795ULL, 0x513B5BFAB80939FCULL, 0xD446D537571CEAF9ULL, 
            0x9D362722108CEB47ULL, 0x6913871A5DE29E89ULL, 0x9D0F2AADA08C2824ULL, 0x4A403A8EA1F177C4ULL, 
            0xE37DDF93803014CAULL, 0x4C61AA23C977894DULL, 0xB383069515DBC96EULL, 0xA99147F688BE6FDBULL, 
            0x0DE71F97E669224EULL, 0x334FDABEE42A97EBULL, 0xDFDA0016F460A63AULL, 0x92E8817CC80E84A8ULL, 
            0x16B69AF0091C3136ULL, 0x0902A3F4171E20A1ULL, 0xB59DD0DECF48C2C1ULL, 0xA1C32BB6D9749242ULL, 
            0x3A73BD1E9BDDE774ULL, 0xF4AF631B92236EA5ULL, 0xF6B31D0F1A1D6E8EULL, 0xC582F884D605D938ULL, 
            0x86C25EF3B3B7A48CULL, 0xA4CE3AEA35CC40EAULL, 0x1D73E61FE46E5E5FULL, 0x737A2BD961B43F32ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseEConstants = {
    0x62D7D1B6AFFBF1BCULL,
    0xA000B36783A7278EULL,
    0x172206E56DA44297ULL,
    0x62D7D1B6AFFBF1BCULL,
    0xA000B36783A7278EULL,
    0x172206E56DA44297ULL,
    0x691789761F676A6BULL,
    0xFB2295AEBEAA61EFULL,
    0x16,
    0xB9,
    0xC8,
    0xEA,
    0xF2,
    0x35,
    0x71,
    0xBD
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseFSalts = {
    {
        {
            0xCEB882B59D255396ULL, 0x78712BD2FCA3F071ULL, 0x858162DE711EC452ULL, 0x5796B54A1FD12BC1ULL, 
            0x341B8C9519CDCEB3ULL, 0x56169EF363D60A7EULL, 0x23C98FBC683DDE42ULL, 0x636C67D0E8263F65ULL, 
            0x54FFAD0C6D98FBCAULL, 0xF234BFF41986B69EULL, 0x7114FAD29E2580CDULL, 0xEAC34D3FAF6F87AEULL, 
            0x1971D9951D48A639ULL, 0xCAF9FB7C5C205454ULL, 0x6F15699C5C0E1DBEULL, 0x3B49D8724B9DE8ECULL, 
            0xA2DF97E6331F466FULL, 0x3965221E9A6F1163ULL, 0x8C6B6CB3C26F5CECULL, 0x0773D873CD999BEAULL, 
            0x70231ECB918D9913ULL, 0x9B67DA42D4AB9E69ULL, 0xCFE53B394D71C7ABULL, 0x39D7AB50FCDA6BD8ULL, 
            0x7AD83D42D165CF87ULL, 0x515087A7BAA82188ULL, 0x33285BA8BBE27B40ULL, 0x54F742C0A8C23AA6ULL, 
            0xC074EB3A9254B8CCULL, 0x8FBCEB3DABAC42E0ULL, 0x7B3BF37D58136C80ULL, 0xE1304631D01E7C6DULL
        },
        {
            0x22973AC74F04C003ULL, 0xBA9E741C08354473ULL, 0xE25AD1C495D66ABAULL, 0x6E53C8CC50CC83D0ULL, 
            0xEC9E1814F3269510ULL, 0x1D62ACE808D51892ULL, 0x7EA7D0F0F70314A3ULL, 0x224892CAF7242B63ULL, 
            0x0180F4255DC64D11ULL, 0x781919105D2A0738ULL, 0x08C80273126D2357ULL, 0xEAA635A3DC97EA47ULL, 
            0xC97EE26F76ED40FBULL, 0x00964775F3584333ULL, 0x771B2082B37C0236ULL, 0x8A9532E51458061AULL, 
            0x86FA23DCA3545070ULL, 0xA2A55DF3491B4D73ULL, 0x6DEB4F648AAA536AULL, 0xD7738D6096FBEAD7ULL, 
            0x4AFC39A7AB674DDCULL, 0xDE235ADE1B4384F7ULL, 0x59B9852DAB558102ULL, 0x5E3EE70CE62C4DBBULL, 
            0xB8D69E5078DA66D5ULL, 0xF88CD37659C13D06ULL, 0xA96EBAAB78DD1D78ULL, 0x19DAAFC1BA42DA03ULL, 
            0x9B7CD40C113A4039ULL, 0xD8142B42A8AEE31CULL, 0xFFAA574BA6DBCEE8ULL, 0xBC8ED999D920F58CULL
        },
        {
            0xCB105A601AE15199ULL, 0xE94DAFF6989EE1A3ULL, 0x2074F1950BD9AEF9ULL, 0x130998069AE7B46EULL, 
            0x26E283C018FF7EE2ULL, 0x6C05AFB919543973ULL, 0xD46C07C839CEE0CFULL, 0xC4C3FA41F7D86F7AULL, 
            0xBA4C462919A55360ULL, 0xCF09A7568DE6A5DEULL, 0x0914D810079D573DULL, 0xAF78E6F058EECE8BULL, 
            0xE482D85D3B8A858CULL, 0x22B70E727B743664ULL, 0x03DBFB17BBFC0CADULL, 0x2F6315B1DE938987ULL, 
            0x4D4E3FEEDC58F497ULL, 0xEA445244248A2E42ULL, 0x8C649935F90A54A2ULL, 0x72CFD67C2DC61353ULL, 
            0x2F04AA1B23A0CC78ULL, 0xC8E5E2D853B1267AULL, 0x5CC3585DBF2CE5CFULL, 0x71B89DB52CE7026BULL, 
            0xBFAFE65509373157ULL, 0xD15EB57EEC2F28F2ULL, 0x7E93B7AD53F66753ULL, 0x1C9F27B377E8CA94ULL, 
            0x0DF28AEE00878A64ULL, 0x64CD9789AE9B7A30ULL, 0xAE3E4BFBCFA7B3E4ULL, 0xB13FC1FFA76C5CACULL
        },
        {
            0xF0C052274CA14EC9ULL, 0xEB560CF9FF7355AFULL, 0x146E3FEBFF3FD6C8ULL, 0x686DBB76CC75D22AULL, 
            0x6ABD160B61657AEEULL, 0xD958EAF5E5BC963BULL, 0x94B21A2E99A20106ULL, 0xA2D6AA80C13F6346ULL, 
            0xFE2FDCE7424C6000ULL, 0x911DE9ECBF7049EFULL, 0x7BA18A9FA4A9212EULL, 0xFCD537C27044092BULL, 
            0x0F3C5C789BE67469ULL, 0xE6351BDC4DB7FDFBULL, 0xC498B72B48670689ULL, 0xD41CE06F89BCD437ULL, 
            0xAF36FC63E98955D7ULL, 0xA931413F4DFB4EFFULL, 0xBEB559F27770BCE3ULL, 0x8C3C165566FDF0F0ULL, 
            0xAA02955325EC7574ULL, 0xA660907E18638A4DULL, 0xD64448312D16899FULL, 0xE113D71423B70D0DULL, 
            0xD2EB104A1D642DFBULL, 0xC1C465E967FA11B7ULL, 0xB627770547611916ULL, 0x001804E647153397ULL, 
            0x4562EBB7256BC468ULL, 0x4EB2532836B342E1ULL, 0x0F73A342725FC96AULL, 0xB1A2CB7592BCA71DULL
        },
        {
            0xA6C549933AD33F70ULL, 0x925E0455190E97CBULL, 0x7F35751D04B7C4C5ULL, 0x4A0ED0D87CF8F779ULL, 
            0xA4991CBC649F0615ULL, 0x091298E229D02771ULL, 0x25CC92FA088E3DDFULL, 0xD68B6C033869166EULL, 
            0xE8A4B8B48A5BAFA7ULL, 0x380F83EBA0378FF4ULL, 0x81058BBF47E429E7ULL, 0x15B9323A1C1084DFULL, 
            0x5E8E7CD1129BB4A5ULL, 0xA1FC4B16C2E6BE18ULL, 0x98EB6B7ACE3F7615ULL, 0x4E070D902EDE86B9ULL, 
            0xA11F296CB35DE55BULL, 0x55F1DA6F69602A82ULL, 0xAC45D96B15334808ULL, 0x14AF3B723E069E27ULL, 
            0x762995E7A2E151EEULL, 0xC340AF216FA56743ULL, 0xC61A7B6ABF06BEBCULL, 0x1F9B47D43D9E54ADULL, 
            0x557A2CCC3B86B409ULL, 0x384FC6022DB4BAA9ULL, 0xF268FC11FE4E3FBCULL, 0xC4911A2247651D3DULL, 
            0x4D7CA177E60D7CADULL, 0x8BDCCD24521BD1B8ULL, 0xC84D87857A5A4027ULL, 0xAF26C10AC6A70205ULL
        },
        {
            0x299140FD22E786A6ULL, 0x9EA7F702DE8BADADULL, 0xAF79C223B8526F1EULL, 0xED0A6B2FA89DE422ULL, 
            0x65D927CC3ECEE1B5ULL, 0x6923331171C7A10BULL, 0x5E20AA0122A87388ULL, 0x47F37218EF3B50F8ULL, 
            0x5DB2F210B9010BB9ULL, 0x43D431431B80C520ULL, 0x3AFC3F4C7835FC0FULL, 0x714462F519CEED3EULL, 
            0x915CC52CB63CF8DCULL, 0xAF09AC80B4FDA886ULL, 0x82385CEAC99EB89AULL, 0xCD39596770785E2BULL, 
            0x120447A5E17A8E91ULL, 0x0F02D9CA94B8E16AULL, 0x24A5BD984DD9B9AEULL, 0x69B24A50AA6F7720ULL, 
            0x0EE8D3560A365862ULL, 0x05D0CA5260B17C62ULL, 0x63563FFD7D2FCD34ULL, 0xC97D30F0EB6B2020ULL, 
            0x2485FCCD2117DB00ULL, 0x7E55648EDFC3424DULL, 0x119688696447EC75ULL, 0x36F74746AE6B2706ULL, 
            0x1E399A15E5E337F6ULL, 0x598CEF13D1CC0514ULL, 0x9934DAC2E15D2A6CULL, 0x720E8265ED95EB89ULL
        }
    },
    {
        {
            0xA0D55053A3A2B570ULL, 0x20799A2651B0D353ULL, 0xA0614475B17A46C6ULL, 0xAD404970DE36410BULL, 
            0xAFBF000D2B9D1A05ULL, 0xE2ACF2A487D72D28ULL, 0x84F7490652D78531ULL, 0x960249C7D94A8CC3ULL, 
            0xE3B04E965130416CULL, 0x8E65CF9DDD0C5D21ULL, 0x46B38799182BC0C9ULL, 0x50AB9E79D60ABA80ULL, 
            0x8C30A6D2144B016CULL, 0x33983372951D99D0ULL, 0x7B3944B43742E633ULL, 0x7135C10190C7675FULL, 
            0x68309F697F233D62ULL, 0x7FCCE33F8BCA2830ULL, 0x824968AD88DEDDF3ULL, 0xA259CC5FF201E4C2ULL, 
            0xDE793228886EAFB4ULL, 0xB473F2F6DB7705DEULL, 0xC38E1E621D3D1823ULL, 0x923F0AF724BB0BE1ULL, 
            0xA7BBCC0D3A9A9D78ULL, 0xF5F681FF8BA42A31ULL, 0x361904FDECDBD581ULL, 0x5CCB22DA2FEBC36DULL, 
            0xA9A804D95E1B762CULL, 0xB49C8CF5601ED98AULL, 0x82944C636A6BD686ULL, 0xEAB70D84D232C5EEULL
        },
        {
            0x522A9453B15D3A79ULL, 0x5845CCA35F943C6DULL, 0xDFADD30DB177DAF6ULL, 0x33F77AA5F462C9EFULL, 
            0x7526AFC2C999E4B4ULL, 0xA6C13C47CC1AB62EULL, 0xB024359D7366E79FULL, 0x80682DE5653BB641ULL, 
            0xE01FFFD9D8D84C8EULL, 0x2A5856F9D08F906EULL, 0xAA78043774FCCB78ULL, 0xD40B5E609942F066ULL, 
            0x4BE2D87A99715199ULL, 0x4575C4A56574166EULL, 0x33A39F89C80938C7ULL, 0x7FAF0679871B7F41ULL, 
            0xE10BD509B0117CFDULL, 0x781E0548971DFFA8ULL, 0xB2314A2714D8A5C5ULL, 0x5E9EF38C6F9EF82CULL, 
            0xC2EBBA60DC0BD749ULL, 0x1FB68E4A018714C8ULL, 0xB436F32DD481EA5BULL, 0x84EE66087AD34C7BULL, 
            0x292E8A5A48D1B7C4ULL, 0x3632D641270BDD2DULL, 0xCAAD23E67155F188ULL, 0x0E2EB4EB946D5EF0ULL, 
            0x90358478258079E9ULL, 0x554D7E8771D4B675ULL, 0x16BC77F088D7946EULL, 0x6E15BD75B9A95D27ULL
        },
        {
            0x4EFC9F3A5DB16B97ULL, 0x9E122AD6C10284CAULL, 0x7C405957C234F84CULL, 0x663AD35893BA2E38ULL, 
            0x05686BF910C6A842ULL, 0x7D7ECCE49E722CA7ULL, 0x9D0F1A2F294B05C7ULL, 0xC552B7941305F7D7ULL, 
            0x8A4A817FDAA7481AULL, 0x261F767129EB8FC0ULL, 0x231442D2377D341DULL, 0x8EB12B1AE7DA924FULL, 
            0x43ED18F08FE005D7ULL, 0xB185AA0974CE3159ULL, 0x3A51D1CF48F6EB92ULL, 0x10DA6D7EB121869BULL, 
            0xBFEBBB56FA6CA4C0ULL, 0x3E1947D7B76E0F0DULL, 0x637B9091BF10983BULL, 0xFFF7C0AC724FAC7AULL, 
            0x9809F02D9386DAF7ULL, 0xFD9AF02DBC44590CULL, 0xFE709506CA821E92ULL, 0xB0013EF4B38495A2ULL, 
            0x63A88B0B0DD0AA97ULL, 0x7BD4DED35277533BULL, 0xB4786F0ACB55DDCDULL, 0xE89DCE1D189BCE5BULL, 
            0xB2CC947075728CB1ULL, 0x3E5B9534E2765D9BULL, 0x9A67471895C66C9BULL, 0x10C09A88CC69B8DAULL
        },
        {
            0x8934637E87BAB7ACULL, 0x09691DE563C5EAB2ULL, 0x563553629D6D68EEULL, 0xE1252BF28F4DA538ULL, 
            0xD61A1CB9E3904CF4ULL, 0x24D888B88C32266BULL, 0x15712E5378901255ULL, 0x6F25C120964590D0ULL, 
            0x58B740CD68A2F0C5ULL, 0xE7A84FC91CDAE62DULL, 0xFD3E11F6AFCDED23ULL, 0x05486D0F6E0D65B6ULL, 
            0x65E78B3ED080D9A8ULL, 0xBFC20DE53DFCDD33ULL, 0x44CFD1B0BBEE9EFAULL, 0x287F50ED4B5D897DULL, 
            0x74D3D5D4072CB763ULL, 0x6A8B0F22A9390B43ULL, 0xB08E0D7C6CEC230FULL, 0x00CC13C20127736BULL, 
            0x1CB25582DC43C87EULL, 0x341FE3A2CD17F5D8ULL, 0xB58D6C7E2ADB7205ULL, 0x8B0B67D3B879D884ULL, 
            0xF6B96089EA8E6A7CULL, 0x65FCB555CF29FECEULL, 0x0F303200E80EF0B1ULL, 0x554E1A33823B7013ULL, 
            0x5592BC0DFA1D387DULL, 0xB5A30B29420B4624ULL, 0x6D0278CC71F4A08CULL, 0x2F14B9E345B8BDE9ULL
        },
        {
            0xA5B247DB6D90F394ULL, 0xF6AE12B7B6A51864ULL, 0xD2D11F666E878ED6ULL, 0x4BC225F1A66A79F6ULL, 
            0xEB08D9C5CC902925ULL, 0x4B72B31A674E3CF8ULL, 0x1654C7182C51C09FULL, 0xA3BA6F5B61C943F1ULL, 
            0xE36F7EFF824FC19BULL, 0x6BA0882AE2919A87ULL, 0x6EEEB22DBA095809ULL, 0x19D6356FAA2EF182ULL, 
            0x3CDA1E819181E2F0ULL, 0xC0C3D5173F722776ULL, 0xA40F0F51BBC2CA02ULL, 0xEABE3F9C03CA6F00ULL, 
            0xC7275DDF422C78BFULL, 0xA1696F3EE52ECBA0ULL, 0x2CA17C5D20A43FB1ULL, 0x77445EDDEF70A43DULL, 
            0x510DD60761A95837ULL, 0xE2A3DF2A7B05BDB9ULL, 0x0366238ADBAF255DULL, 0xD0FF9516BF4B1203ULL, 
            0xC3093E726B31CF7BULL, 0x26712BCAD2FCBF1FULL, 0x75ACDFB3680220B2ULL, 0xF87130DFA679D1D4ULL, 
            0x85E5CB3408A9A54BULL, 0x8A0ADC7722D3048EULL, 0xF7120F5C9B04393EULL, 0xFAB1DA1723774817ULL
        },
        {
            0xE7121BFC61FBE4F6ULL, 0xBE4C4FB994F93F91ULL, 0xE76D22BD701C4DFAULL, 0x83C2268D4EA1215FULL, 
            0x0C2CF468B6F94438ULL, 0x4AF9F3A1CEDE3C59ULL, 0xB1541264EC13C0F1ULL, 0xCB1E94C73E27319AULL, 
            0x19672E3DFDF4DA98ULL, 0xBAFCCC8883666525ULL, 0xF1D9710D777EA820ULL, 0x34CEDD30F4E303B9ULL, 
            0x223CCB87B4292920ULL, 0x4CA0B5F6908BF994ULL, 0xB49DC8925B7B807EULL, 0xAE5FE4D676FF8EEBULL, 
            0xD3994B4797521447ULL, 0x74D92F69DA6BA20FULL, 0xD49F290A5B78082AULL, 0x03881E5014B78747ULL, 
            0xDC8BD98060419D8CULL, 0x387B6215C3EF31D1ULL, 0x46A643DF84EC6DE0ULL, 0x33EC47FF5F665C6AULL, 
            0xD06AA57ED567267AULL, 0xFA0B5C0D4BD5E7A3ULL, 0x0ACC3102824A4574ULL, 0xAE90812DB7FDF67BULL, 
            0x7C62061EC4F3C6EAULL, 0x9D23267478D7E2CAULL, 0x0055D3D6DC8EFF14ULL, 0xE89F82168F246A66ULL
        }
    },
    {
        {
            0xB78E88279C13403FULL, 0x89240114FC77BA14ULL, 0xCAC86395E7ADAB45ULL, 0xE1EBB99251B22CDAULL, 
            0xAD9C5B328B79F021ULL, 0x94161DD2E43E1CE6ULL, 0x6FA2BFC063F3A885ULL, 0x911C66AEE2AE3FB2ULL, 
            0x1D04925820096B6AULL, 0x6B37C8C53032D34CULL, 0x7EDBC050D57B0BD6ULL, 0xF29C03EFEC28F7CCULL, 
            0x2A5E135D205D44D6ULL, 0x3FA7C2EB8A55D8C7ULL, 0xE4D1AA742866296EULL, 0x82D3B4E79FDB7A48ULL, 
            0x2B2F5C586E88734FULL, 0x3E3678A462EE31B4ULL, 0xB25539BAC417D1AAULL, 0xD1C37A6EE16C0FE1ULL, 
            0x8EA822DAE75092A9ULL, 0xF223CA9D3EEDA815ULL, 0xD2184491A2EBFB04ULL, 0x70CA432B62539CE4ULL, 
            0x90273573CF1E7BD8ULL, 0xD1F2546419C417A3ULL, 0xEB9C12B764D0DAF0ULL, 0x39E4FF065953D044ULL, 
            0xD2B9A6379D4E0615ULL, 0x33BE326CEF1D1E30ULL, 0xFEFB8587300DB21DULL, 0xFD5CEC1084063691ULL
        },
        {
            0xA29741F5D4444C04ULL, 0x7327611AEF8D604AULL, 0x66E72C950AD7DC4CULL, 0x9385609A2E7DDC7AULL, 
            0x90B3603350815099ULL, 0xCEE202D172ABE728ULL, 0x81CE89F3DDF2D3B0ULL, 0x4A8431632F516573ULL, 
            0xAAD0FBB60E2E8F73ULL, 0x2F7B965ABC3EB9EAULL, 0xDF11B7D79B7C2F11ULL, 0x69D7875C6EA46100ULL, 
            0xF7525BAA98BF8659ULL, 0x5FEB1FB2FFC32FAEULL, 0x6DBDBA3D36B5DD34ULL, 0xC47192F22123D588ULL, 
            0x026D9CA899F076CCULL, 0x8C62264C1F2713EAULL, 0x99223C3530BE245FULL, 0x0F978F7CC1499DDDULL, 
            0x74F0CD41ECE7C54DULL, 0xAA7167C7331DFEEBULL, 0x7628DCC8FD24D0A4ULL, 0x4938BB9E052C2D12ULL, 
            0x52D760F2CE1E51B2ULL, 0x50AE17297147861AULL, 0x07807DD6523C2D04ULL, 0x8EE8CDB7B1965342ULL, 
            0x84B4E49CA450B4F4ULL, 0xBAC5FB175BF150FCULL, 0x95DF6DCD3DB57BB9ULL, 0xDCB17A1CA3B223CCULL
        },
        {
            0xAD9ECBFB4F398F51ULL, 0xEAC7775C573104DAULL, 0x079E4BB0A93CFC31ULL, 0x35C57FD8454BA4B8ULL, 
            0xE84AF18F231BCC97ULL, 0x1FB0357444E30B22ULL, 0x77A9766053F8C0B8ULL, 0x3705EA2C0A378607ULL, 
            0x4B9B678C5FA19EE3ULL, 0xA9434FB4EBE97688ULL, 0x050B4B3AE0C3FAA7ULL, 0xC692A6A0C52D265EULL, 
            0xC1EFBEA033F48008ULL, 0xD36E7C8759DA7AF2ULL, 0x10592E5AA99A5CCDULL, 0xA0030DF16600C8ACULL, 
            0x99E6D225F055BB3EULL, 0x4F4687D5E36D374BULL, 0xFC0179BCF474F2F7ULL, 0xFF5D2E8FE2A7C0B7ULL, 
            0x2FEEEEFEDDF3060CULL, 0x09EC9B803AF7C3FEULL, 0x3648BF0A51EFDE3BULL, 0xDF8CD58C0BFD95F9ULL, 
            0xB8F3483CEB41D216ULL, 0xFC750E2CC510DD64ULL, 0x535C481A8480668FULL, 0xED9984D4E1D36F67ULL, 
            0x8B45D5357D99BC5BULL, 0x9945FDBB6714B995ULL, 0x82E310442905EDBCULL, 0x686E37C2C168F277ULL
        },
        {
            0xB8AD6D83DB1AB003ULL, 0x8AC18F09FD27864EULL, 0xB04B83396CDB2613ULL, 0xF76DEA3F8FCBDAD1ULL, 
            0xBFB3DDE733422D51ULL, 0x0FA88FA34C3D7D7FULL, 0x48EEB851FDB116CDULL, 0x81DA3F35C34068F3ULL, 
            0xAFA881E68D4563CDULL, 0x06B9080594E20545ULL, 0x17B2A7BA865514F6ULL, 0x6C7A5FDEFBBE9B1AULL, 
            0x05DE23795D9FC118ULL, 0xCD7BBBBC01B12C08ULL, 0xF07EFBFFE77E4412ULL, 0x6F0BFE1E710F3184ULL, 
            0xF086416BAAB5FC37ULL, 0xD7D144C3705ED333ULL, 0xD21CB69E107937CEULL, 0x73E9816086436139ULL, 
            0x130B7D330E3F68A2ULL, 0x1AF4D61915B67A4FULL, 0xB40D2C18D1F44AFBULL, 0x318A58B97B6DA651ULL, 
            0x1BDE915E35039162ULL, 0x21C6B3BB378006A8ULL, 0x18348C108AB97C8FULL, 0xDFF544F5E2D7CE54ULL, 
            0xAE6197EFE8D16760ULL, 0xF583EA69B337EF89ULL, 0x2B0DF99D0FE31F03ULL, 0x8AFEB565EEE40A63ULL
        },
        {
            0xA042B0F37903851DULL, 0xB5AA258C190CF24DULL, 0x51451282BE0C30CAULL, 0xA7DD0AEAEC84C333ULL, 
            0x8ECCC20A8BC2B823ULL, 0x7645F6690380B37FULL, 0x93F2E45529043733ULL, 0xB3B463770BB18E19ULL, 
            0x94619F6AAE864A62ULL, 0x4169B046F41D2E97ULL, 0xB0FD1F1A902FC0B3ULL, 0xBDC452D93E893105ULL, 
            0x3E9E00D7395E19ABULL, 0x5017D8320839FF73ULL, 0x952CBF7593E92C9EULL, 0xB9F08EFC267D7831ULL, 
            0x32711FDC785A9FEEULL, 0xEFDFDAED703D4AD1ULL, 0x6FEE7D32970FFD60ULL, 0xDC122780832F1637ULL, 
            0x15FA3C4F1F0B9B9AULL, 0x97EADFF286FF2EE8ULL, 0x01DECB660075A5E3ULL, 0xAF62749D37423AFEULL, 
            0x2493A37F6DAA73C8ULL, 0x6E759BED110F3AE4ULL, 0x9AAD73A7139D98C3ULL, 0x591E8F408B9CE15EULL, 
            0x0E3DCC9CF44C7ABDULL, 0x25CA7D913E1838A1ULL, 0xE4BFF58991E2F6F8ULL, 0xB2DB6C4B59940391ULL
        },
        {
            0x3F3F29628380EF2BULL, 0xEC969520B46A78A5ULL, 0x9578732E40871901ULL, 0x498C263189ED34FCULL, 
            0xB62C69118A592E39ULL, 0x0A42DBC451155359ULL, 0x7A4226F4C739B2D2ULL, 0xFAA9A70F4D6AB008ULL, 
            0x0F788CD109088548ULL, 0xCA356FCE41D92843ULL, 0xB7735894092292E7ULL, 0x2D7CC760FC8A2FABULL, 
            0xD6A3DE6D89149835ULL, 0x017D8628C6860B0FULL, 0xA774412E3D5D1FDEULL, 0x7128958F0290A6FFULL, 
            0xECECAE7E50E97E4BULL, 0x612EA3B0792F9E43ULL, 0x1EEF14A600810E13ULL, 0xFD145C150A402AD1ULL, 
            0x8FBFB198F8A67D1FULL, 0xF7870B7EE005C65CULL, 0xC770F4E6225F3FB3ULL, 0x34639BA3A3F80BD8ULL, 
            0x2D5C27A3DD040F04ULL, 0x453D1A35686ABE32ULL, 0x1C995D9A3AC4BD44ULL, 0x7C4E47584B3C2D04ULL, 
            0xAE6A3F4C557E280AULL, 0x752F6D64ADE8AE0BULL, 0x7687A32731C736DBULL, 0x8737A7FE2156D0A4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseFConstants = {
    0x5DE9F50E8AA897EAULL,
    0x022452755F7E68E6ULL,
    0xB6E3240BCE5C4A14ULL,
    0x5DE9F50E8AA897EAULL,
    0x022452755F7E68E6ULL,
    0xB6E3240BCE5C4A14ULL,
    0xCBAE218AE0095BD2ULL,
    0xEA3A392B24DBB439ULL,
    0x59,
    0x2D,
    0x88,
    0x79,
    0xEF,
    0x0B,
    0x72,
    0xB2
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseGSalts = {
    {
        {
            0x3D46951CF691489AULL, 0xD6FE53BDBD213900ULL, 0xC5A9128BEFD71E28ULL, 0x027165A85E5A878FULL, 
            0xAAB21D3EE20B75A0ULL, 0xCB1035DCCA7C39CCULL, 0x6A60D679A5BCFA16ULL, 0xB8DF5A0487705841ULL, 
            0x68BE9EAEA4DAF20CULL, 0xA0070619D201E03AULL, 0x7F40B02686AE0038ULL, 0x0E21CAACA39B732DULL, 
            0x1215976C4A0D2CA4ULL, 0x612FE83F222681B1ULL, 0x9ABCA687E09C04DBULL, 0x09C49F568A1F5F9FULL, 
            0xD8EB4789173A0554ULL, 0xE9F2724C7AAFC3A4ULL, 0xB79BC68833C93754ULL, 0xFBE76F08EAC7846AULL, 
            0x8FD1F2B4B1EEEF3EULL, 0xBDEBF610D3285A20ULL, 0x3DE1E1B4963B9F57ULL, 0x510035B3FA6B0A52ULL, 
            0xEE432C3581D8CDFEULL, 0x0915C43DE59200EDULL, 0xACAF443A3C5C215CULL, 0xA27C56421540D009ULL, 
            0xAD9BD097C2626B16ULL, 0x50CDE0F33B90B001ULL, 0x2E4F7130AED3E82EULL, 0x25D248FE5CE80FF0ULL
        },
        {
            0x08F1C5C00B976F6EULL, 0xD5391A869A878AD0ULL, 0x291051B8063881C5ULL, 0xB788402151DEDFFBULL, 
            0x74FF3B9DCB756D5CULL, 0xB2BE31B48263B9BAULL, 0x2B63972F92329057ULL, 0x87F0F87179AA800DULL, 
            0x460BC0AA5FD109E5ULL, 0x4273709DF01F0D1DULL, 0x308E7B95C3541966ULL, 0x27C44E5E9DBB2D73ULL, 
            0x46E926C16DA9C28CULL, 0x13711CFF9846B095ULL, 0x10B66E425AADD610ULL, 0xF51224E6B5D10D02ULL, 
            0x72E4557FAAFD8F1EULL, 0xE57FEB8BE1B47E54ULL, 0x8EFBC42139699686ULL, 0x21697621D36F67ECULL, 
            0x513BAF17A8ED78FEULL, 0x21EF14552D043858ULL, 0xF3396009CA236063ULL, 0x9688D4DDAB9DE650ULL, 
            0x11B65B62B3F51916ULL, 0x067EA773AFB7EE6EULL, 0xB9CF446D146FC957ULL, 0x11A8EBF0E8F118B0ULL, 
            0xFC83D9AA7592CB8DULL, 0xC09AF855E2F40829ULL, 0xFDFBF7912587F119ULL, 0xD9F1C68CA285A4C3ULL
        },
        {
            0xEECA07057887CFD7ULL, 0x71EFBC47946F61F0ULL, 0x6BBCDE828CA7E566ULL, 0xBC0461CF9188C11BULL, 
            0xD40052AF1EBAE1D6ULL, 0xF490B56EEAA30C01ULL, 0x1C93770E753149F2ULL, 0x842F595056C67699ULL, 
            0x24ACAF45F1EC3AF3ULL, 0x0536426EFE60870DULL, 0x44001C8EA5D6C62BULL, 0xDE4592FF4DD454BCULL, 
            0x5C33123FB16EA93DULL, 0x69F6BC480D4466CEULL, 0x198AD6B03AA21FC9ULL, 0x11D1F9DA53A93CE9ULL, 
            0x5E4453F346A93686ULL, 0xF20CD908BB073330ULL, 0xC0B730083391D63FULL, 0xB0D2CDCA8A09CC3DULL, 
            0xD9DB05BBECF07C9AULL, 0x3A359889575FDA2BULL, 0x1CF5F9161DC480D1ULL, 0x1B89ED58110173C3ULL, 
            0xDEE5FE4821F4AE0BULL, 0xBB1F64BF85A21AE1ULL, 0x5D112FFBB00AC315ULL, 0xE1E442E7767C45B2ULL, 
            0x317F280DA06E4916ULL, 0x04DC5B53EF2002A6ULL, 0x17C2C6681A17D7F8ULL, 0xF70564A7AAC66868ULL
        },
        {
            0x21F6EBC35F691FE7ULL, 0xFB5A5EFC1D516373ULL, 0x9EF5C12D75626D96ULL, 0x8EA94A5DB3004000ULL, 
            0xC7FDDA721BBEB9D7ULL, 0x5B42EDEF2F92FE70ULL, 0x43040DF258A55A10ULL, 0x80B473653D4E1F05ULL, 
            0xB5AABE65A92F7E98ULL, 0x94820F81B48EB3A4ULL, 0x34750DD9376F8991ULL, 0xD5D786434E3065C7ULL, 
            0x72B6F2509E350659ULL, 0x23C724759322966CULL, 0x25A39F2B180915E8ULL, 0xAD51EF7E5B2352E8ULL, 
            0x4A71D81FBE1BC5FEULL, 0x151205A71BE9D7DFULL, 0x49EB4CABDCA50243ULL, 0x4279C8A9A93BD08BULL, 
            0x560F2C2057F75BB0ULL, 0x51C0B26335268381ULL, 0x6E208E683A276848ULL, 0x679038401AFA472FULL, 
            0x4DF890FDFCEAB4A6ULL, 0x97A741CB48CA5AD3ULL, 0x2C458FA37197022CULL, 0x6CB46E81A4C44792ULL, 
            0xE6636DC280E688FEULL, 0x9C53E53AB03C2C47ULL, 0xFB71242369BEB7FAULL, 0x2DF963E564D2DF08ULL
        },
        {
            0xBC13EB185BD30211ULL, 0x7C34938ED220D542ULL, 0xE0A7E8A5EDC36AE8ULL, 0xF4AEDEB6D93D021AULL, 
            0xCCA4EFB2C4A3A5B9ULL, 0xA16BB48A7435AE89ULL, 0xA76AC516FBAB0802ULL, 0x0F8803D52C829C85ULL, 
            0xC72A649ED5F1B777ULL, 0xB168384B6779966EULL, 0x7DFCCACBB0E0B4BBULL, 0xCB4DB059289676A5ULL, 
            0x55D87E62E68637DAULL, 0x71D720308775EF9BULL, 0x69AC6947A076DBA1ULL, 0x97CF669724AFB45EULL, 
            0x6435EC8351CC5AC9ULL, 0x1E6D30450E3D61D5ULL, 0xD1A870F7C3CC21CCULL, 0xDAEC29103A3A3A57ULL, 
            0x5B3F565CC4976248ULL, 0x3D1FB07F47B372B8ULL, 0x4236780B2365C145ULL, 0x88267C5F6DDCB04CULL, 
            0xEAB8D421151DD43AULL, 0xD2DA017CB17B64D4ULL, 0x4E8909452AFF729BULL, 0x61FB63974529DE09ULL, 
            0x6CCDDF0806750BBAULL, 0x72772D7F9E1EFDCDULL, 0x229E1B9FE03C8D5BULL, 0x669B1DB3A5A62233ULL
        },
        {
            0x833676A7174A212FULL, 0xAA3BD6D4CCAA0CE1ULL, 0x46FCEA54BE7BACA4ULL, 0xA21B73662D27184CULL, 
            0xE1A93713E5D5FE06ULL, 0x896C3E291BC91C88ULL, 0x2BF60B8C6B1C2543ULL, 0xFC2DC497C58D1C48ULL, 
            0x27FE0D6A2899F931ULL, 0xBD447F806C81BDE1ULL, 0x9552F08016B7A516ULL, 0x636732735F597484ULL, 
            0x84C7FD5184DC7715ULL, 0x8175FD644C809633ULL, 0x41A58B8F38B7A6F2ULL, 0x270018B616760F90ULL, 
            0xE4C356BD8AC11AD5ULL, 0xA3395A978CC21121ULL, 0xA323B7F0F1533394ULL, 0xAFB7725A219B4EA0ULL, 
            0x071983EEAE1EDB5BULL, 0x343508C06FDA8555ULL, 0x704752BA09CB025EULL, 0x66E752FAA87D8587ULL, 
            0xB8DA4CE33649E467ULL, 0x146624E8F9919C61ULL, 0x239DC8C7CE077167ULL, 0x6CF9CE0F0DD13849ULL, 
            0xD5F5FFF1D643A0F5ULL, 0x75ACE5910CBB9B91ULL, 0xE71BEA4F092BDAD5ULL, 0xB7E6E971FDDCFAC1ULL
        }
    },
    {
        {
            0x28755C2472F4038CULL, 0x99FA3D28936152FAULL, 0x284CFD08FB0CD3B6ULL, 0x8B1237B40B94F7A8ULL, 
            0x2742316B42B60190ULL, 0x2AD1C8389007AD99ULL, 0xBCF53BBC34957828ULL, 0xF86C80F9F6969DFBULL, 
            0x6CC5D529C492EF0AULL, 0x2D32751AD67FA1DCULL, 0xB52C68F365D969F0ULL, 0xC24AFEF3B31CAC3AULL, 
            0x0FBE0A4E0AEEB961ULL, 0xCDB4E9D34E31E513ULL, 0x43E4CCF81EA8AA06ULL, 0x17D62211B08F7CDAULL, 
            0xA06472AE697578FCULL, 0xB027649647E69827ULL, 0xDDBE8BC34F8AEB7EULL, 0x874AB4F741CE5631ULL, 
            0xD7C6D6D47F7B262AULL, 0x95236370566869E0ULL, 0xA4040DB3BE867EECULL, 0xE5947DB12E7BD635ULL, 
            0x85F77608FE314C0EULL, 0x1F259BB0AE7A1D3EULL, 0xD8C9ECD85FC3585FULL, 0xA941D8191B8C0ACEULL, 
            0xD8536831357878E1ULL, 0x2B4EA835FC25A212ULL, 0x1FE48E3F9E947A4AULL, 0x36F471F226123F5EULL
        },
        {
            0x3D25A447FB921C41ULL, 0x603AEE120D6FCB07ULL, 0x1F4AEE0143738F6AULL, 0x09F865CEA745287BULL, 
            0x9417D0FF074918B8ULL, 0x0F6F481D6250045BULL, 0xBE22CDA032368FBFULL, 0x77D23B8D288DC421ULL, 
            0xFD35365A7D80F438ULL, 0x7F0BBCFF305CD375ULL, 0x9F92B11A936B673EULL, 0x8D6DAAB56F04C748ULL, 
            0xC63924710F180CD1ULL, 0xD99AE65985120089ULL, 0x9C27D6862A46C12CULL, 0x05618173E969F42EULL, 
            0x96E467F74351A98DULL, 0x38692CA53D7F825EULL, 0x891D35AD75068AA1ULL, 0x9E34E3E21023C099ULL, 
            0xDD20CEA2801B8F53ULL, 0xC4ADEE56CDF6290DULL, 0x1ACA9C08B3212028ULL, 0xEF537A34C86C6ACDULL, 
            0x483917E71B6908FAULL, 0x00CD18369AD44AD8ULL, 0x597E06B4ACE4EE27ULL, 0x5DCAD05BAADBB311ULL, 
            0x8B4340A57905F0F7ULL, 0xF9AD921E04B950ADULL, 0x1BD75612CC998D26ULL, 0xC1BEB1A7C9A66631ULL
        },
        {
            0xFAC80DE8A8923B01ULL, 0xBD22BF41846B9F15ULL, 0xDB04F128264641D7ULL, 0xA5F63632BC90C02AULL, 
            0xFB92A7A63A5E2687ULL, 0x108DA4351F32F503ULL, 0x7223D04C46A42F56ULL, 0x0E5333F614CBA839ULL, 
            0x388B7C4B1697C134ULL, 0x6CA1AE4446E05D6EULL, 0x17CC607C6B82ED32ULL, 0xB707D87B17717491ULL, 
            0x43A90CE1DAEB8470ULL, 0xAC8C3AFA6BAB8303ULL, 0xB914BC0B721D7434ULL, 0xA8821D9F38E67C0AULL, 
            0x223316672DC4E0B0ULL, 0xD2D65F3EF95220B6ULL, 0x4E08663CE7C42BF0ULL, 0x4C230EDD85895EDAULL, 
            0x4F332BC655BE08A2ULL, 0xC0EE0127A8462F50ULL, 0x3346EEBC38373F3EULL, 0x86A44381EBCAD929ULL, 
            0xC9228BC37054B452ULL, 0xD0F14AC6711EDC6CULL, 0x97913841F5A855EDULL, 0xA4742E82B2E6F5E0ULL, 
            0x2374CEE215E23C34ULL, 0x1D79B519900BE342ULL, 0x03AB16080B55AB09ULL, 0xFCCF6B0B33BAC5B8ULL
        },
        {
            0x1F15C3135A6D82EEULL, 0xDA7DDE51DE0B7F6FULL, 0x23B09EB18E66FA4DULL, 0xCB62D012E8C80C46ULL, 
            0x6F8214200C25E1BEULL, 0x7ED8C8E3255CB809ULL, 0x8ACCBBA75402581BULL, 0xE476F7220B88A9A4ULL, 
            0x379430DA2D4C67F1ULL, 0x095EA757B2958C29ULL, 0x9EC80F085E409203ULL, 0x73476BEAA9A973D5ULL, 
            0x7A7415DFA1D02BDDULL, 0xD38CDC1466451BE3ULL, 0x56428A3A346C55C0ULL, 0x99A3530FA9D56761ULL, 
            0x876857D2BFD3EBD1ULL, 0xB3C240BAF225EAE3ULL, 0x6FA48BCC1645A4E2ULL, 0xB34FBC35C842560EULL, 
            0x499A7144E73E11ADULL, 0xB132D49CCA2A39EFULL, 0xAB6E95FBD9EFA8DBULL, 0x497108F0BE2FF1A2ULL, 
            0x8DC1D66787E1B212ULL, 0xFFEF23116374827DULL, 0x5FE555F48B2D7ED3ULL, 0x3998E9339229344CULL, 
            0xABE79D1F03C125A1ULL, 0xF2E1AEC4A745D505ULL, 0x902201E5EB429945ULL, 0xA6A0CE92D915411BULL
        },
        {
            0xB86AECDB2847D2EFULL, 0x308CAC8DACF04CECULL, 0x5AE76D2056947DA9ULL, 0x482B5BCB36062034ULL, 
            0x5551A7EC06C9D52CULL, 0x5ABA9CAA280AB3A9ULL, 0xE478539219404C66ULL, 0x626577D8778A9276ULL, 
            0xAEAD2D7DA5D27976ULL, 0xA9B71BEFC6216B18ULL, 0xF29049EB00FEABBFULL, 0x3DBA42FE610C5C4EULL, 
            0xB1B376ACEDA28C45ULL, 0x1E95226974D1F1CFULL, 0x640EDC041D9F40F0ULL, 0x69451E30026DF667ULL, 
            0x588A30BFDE7AE4DFULL, 0x25FD0E3BD50A79F7ULL, 0xDBD983BCB07968D9ULL, 0x03A17603CC76F96DULL, 
            0xB245A9614A428760ULL, 0xEC8188B994DCBA2FULL, 0x1FCEC249B6220D32ULL, 0x12C7C65D440A4B67ULL, 
            0x3671A1A62577FD1CULL, 0x6846B8EFBAF66997ULL, 0x2021D1FCDF1B9DBDULL, 0x4D4D4B1CE283CC6BULL, 
            0xBA490E1046649110ULL, 0x722E2B4DAA189B6DULL, 0x497E209F62D8968DULL, 0x7CED3EF8F1E8EE8EULL
        },
        {
            0x11035EF9BC95FAD9ULL, 0xA6271451770719A8ULL, 0x2A9EC4865ABDF177ULL, 0xB1B1651AD478DD44ULL, 
            0xCE330C46936C5004ULL, 0xE203E66AFE0A4FA0ULL, 0x799400EE4635E8E8ULL, 0xDD131E1D492A70B9ULL, 
            0x02220DDA3D201EEAULL, 0x729E3C3DD3D932C2ULL, 0xD99EEEC4C137B5A5ULL, 0xB0AB2147E3BF6EACULL, 
            0x6DA4AB303CD8CC1EULL, 0x867F8135807076ABULL, 0xD9F5BBD3BCA63C54ULL, 0xCEC30DDF6AB37336ULL, 
            0x29C0B6E3D90E265AULL, 0xED85E10CB6C28F27ULL, 0x389470ACF6743995ULL, 0xB729C1E2DDFB62C4ULL, 
            0x563AC2C5200399D0ULL, 0xA9DB5A9EB0C503C9ULL, 0x12A8EBBF2B19DF7EULL, 0x41F6FD71D0C156CCULL, 
            0xA33C6C6032586265ULL, 0x79D671B8A6B9F361ULL, 0xFE1B5BDC36ADF59EULL, 0x5F673C5C7C3F60E1ULL, 
            0x0ADDAC32BEE5CC95ULL, 0x77B5C94FF2A937B2ULL, 0xA82B6D7F9E1190A2ULL, 0x730270A06A83C34CULL
        }
    },
    {
        {
            0x651A3E15746D3858ULL, 0xD55E79F6660F5B61ULL, 0xEE6C17C967FE4D1CULL, 0x8AC2AB1B53C07448ULL, 
            0x56F25E360A13ECC0ULL, 0x2603ECE45693C8B2ULL, 0xC2D51DE300E4E138ULL, 0x93B7C54B5C93F7B4ULL, 
            0x5448AD6EC04DE2CAULL, 0x574BC7EFA9F79878ULL, 0xA07CCEA1494DF79BULL, 0x8F8301DCBDEB29FBULL, 
            0x3CE95376BA3585EAULL, 0xF19F9D2786278889ULL, 0x7BC3D080D02CB74BULL, 0xEABE8B9B01930AEBULL, 
            0x608356E052131F99ULL, 0x47D76592E9D1A985ULL, 0x5C41BEB71897609BULL, 0x1923155FCD66AE9FULL, 
            0x9AAFF0DD5BF4F6DFULL, 0xC6815F48FE5BD0C8ULL, 0xE21D4D8433330823ULL, 0x432A0866AD6B1759ULL, 
            0xE945C7A20BB87AC9ULL, 0x97B6C4AD26C269B4ULL, 0x4104E9FB4480940AULL, 0xCF72D8113812D0ECULL, 
            0x6E95BCD810283F85ULL, 0xD07B3E8536A2DF6FULL, 0xEA77AD6973060EE2ULL, 0x26DED0957BAF15AFULL
        },
        {
            0x6582CBFA555801F8ULL, 0x9643D03C0727D1B0ULL, 0x8D5B94820277C95CULL, 0x91CF822A2F3405E3ULL, 
            0x17C2A66A30F978F8ULL, 0xC64A92681AB99710ULL, 0x35CB57C42C0B271EULL, 0x640B256B858C8F34ULL, 
            0xD520CA03E9C1DB8FULL, 0x87197B52A718252EULL, 0x567FCDFD1213CA49ULL, 0x746906C282B2C1DBULL, 
            0x17CDFE713AF24ED6ULL, 0x89A8A8ADC8C9B0DEULL, 0xC8E0444706665E12ULL, 0xB2AF89B927B97926ULL, 
            0x6284797B4BFEED27ULL, 0xDBA6C3D72381B1EBULL, 0x236755B3A51A32A7ULL, 0x7CB8A980C6FB5685ULL, 
            0x1503F3DC023D56C3ULL, 0x51BE6EB16F1B9642ULL, 0xC75F00C4CAA88F09ULL, 0x90C14F18AAEA084AULL, 
            0xBA56616D38F378F2ULL, 0x0285C42C79D93E6DULL, 0xE04BE907C170E5E2ULL, 0x6D0BC563890E6A05ULL, 
            0xE9BF9763E525E0ADULL, 0xED9DDC3BDA20BDC1ULL, 0x5440DA39B0465EBDULL, 0x540B068F72083BD6ULL
        },
        {
            0x145227F4B4AC88D1ULL, 0x60A186C902993DEEULL, 0xE6BF01101AD8B004ULL, 0xFB6F3F895098AA54ULL, 
            0x6C24F2C84C3C36E4ULL, 0xC509E061D8512A4DULL, 0x11A7DEC2E8D6600EULL, 0x415C94AD795B4DA6ULL, 
            0x48A3891F9AD57A71ULL, 0x1F442E5DFE68055CULL, 0xF2005E13404B37B7ULL, 0x6063237EB53CD009ULL, 
            0x5F4FCC3704007AACULL, 0x37E904F294A665B0ULL, 0x1391B098103F03A4ULL, 0xAF9689436CE7B86BULL, 
            0x964EBC43FED2506AULL, 0x3291BCA3102AB87DULL, 0x4386E71D798B885EULL, 0x4311756CB9077D8FULL, 
            0x765F5E263DA7FDC7ULL, 0xA615472E4C3FF026ULL, 0xD49E49C9EB777297ULL, 0xDE93486256543BC6ULL, 
            0xAC706CFB7EC41CDEULL, 0x964A0669BCC5616AULL, 0xD474E85E0FC64722ULL, 0x04215C9E92D3FF57ULL, 
            0x3C8D4CF135D2C3F9ULL, 0x14664EF6BCC94E3CULL, 0xB14B8E49AAD0D42DULL, 0x4880C889A759B285ULL
        },
        {
            0x131A0FC001D2B0AEULL, 0xC8D130F084E4D3E2ULL, 0xA80583BABD93AC93ULL, 0x1D4861C6AF704C83ULL, 
            0xAFBE73221040E9F0ULL, 0xDB42FD4A32A0BC8CULL, 0x5F89BEF8D46E280AULL, 0xCA9511B9AE83DED9ULL, 
            0xB475364D9F9121A0ULL, 0x7E564B1120086960ULL, 0x9F4C34A129A50161ULL, 0xCE7B103988F85A85ULL, 
            0x386742A32FBC376BULL, 0x254537B55F9459F1ULL, 0x3477EB844C54A67DULL, 0x4750B668F5B3FEA5ULL, 
            0xA3023D6026037287ULL, 0x472A8154045D63D2ULL, 0x81372CCC53F4F203ULL, 0x044CBB7063B43ACAULL, 
            0x98537F8858D7B207ULL, 0x8331A00DC9159CE1ULL, 0x85D038A7E23FC230ULL, 0xAD01F95552DDD1B0ULL, 
            0x24DA8859DAA17417ULL, 0x6D6BDA0B2E71D982ULL, 0xCE5BF44656CF41DEULL, 0x67FDFBE6BCABDA2BULL, 
            0x4BB8256C1B4D0FA4ULL, 0xF060A5E988FC48FFULL, 0x369C4D84AA8D8F9BULL, 0xF01AB763EF5DE6CAULL
        },
        {
            0xB399733EDEA68E52ULL, 0x919160166A7984F9ULL, 0x8FD6102C5CD43AF1ULL, 0x87D57F620DEB7B9BULL, 
            0x1B3E613DC7D68ACBULL, 0x7CB49BDF8806D972ULL, 0xCF41EA5A5A3823D0ULL, 0xB666D2F4F556B57FULL, 
            0x0DEEBE6B34D5F28DULL, 0x4809C7DAA607B5DDULL, 0x9B1AC45B090313A5ULL, 0x19675D5CB58B6DAEULL, 
            0x33AFB5BA998BEEBFULL, 0x23A85035E757E0FCULL, 0x72D8BA86359A9C0CULL, 0xEC94F166CF1208B5ULL, 
            0x74AC9E1B1C69B1BAULL, 0x09DB9BB98A935104ULL, 0x99ACB3D46237E52AULL, 0xB45D6AD7F08A4E4AULL, 
            0x9CBB938E6A4F79CFULL, 0xDA108D19C82ED0F1ULL, 0xD6B502439D7FE1A6ULL, 0x564DCB42775875A6ULL, 
            0x54F0F41A800B44ADULL, 0x136FE46123B138BFULL, 0xF4F0282AD45028ACULL, 0x47A51DEE3A8211A8ULL, 
            0x67B64B9DDE25647FULL, 0xACD2C9376A49C310ULL, 0xD7C505930C2B2057ULL, 0x838FEEC19DA92F9CULL
        },
        {
            0x008351E2CBD7D76CULL, 0x413C6ED34724B1CBULL, 0x6D819A21D0794C33ULL, 0x3595361E6E62D7A3ULL, 
            0xD6BCFEFAFA0ACC61ULL, 0x3DB11FF9047D69DAULL, 0x3F890B54CDCDCF98ULL, 0x506F11E509D8D91EULL, 
            0xE352EFB339DFAFE1ULL, 0x0154916F24FE0B4BULL, 0x7C3F87FE8168F141ULL, 0x3844C33D4C53A196ULL, 
            0x049552806952C453ULL, 0x7D7F01BB972B120DULL, 0xFCDB07187EBF46DBULL, 0x867308ED511623EDULL, 
            0x93151D8BB39D873FULL, 0x5144764AD920E2EEULL, 0x5E18136D80D1A4E4ULL, 0x1A1F0B0F74A283D0ULL, 
            0xAC455483239C6891ULL, 0xAEE4C934EF3B0C4DULL, 0x5461D4A273AB2A23ULL, 0x972E087726B8C584ULL, 
            0x575C7798CC02B211ULL, 0x042A8F28568BE1A2ULL, 0x7BDB590F1B956263ULL, 0x8973618ADB8A1D5AULL, 
            0x10456FDD3D27BEEAULL, 0x8EA545503AD96289ULL, 0xDB3C6671BFD2079BULL, 0xE1E8E9E19AEAE2FEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseGConstants = {
    0x36782A93888D31ABULL,
    0x744A12ED88FB0F55ULL,
    0xBFFD9EF236ECF058ULL,
    0x36782A93888D31ABULL,
    0x744A12ED88FB0F55ULL,
    0xBFFD9EF236ECF058ULL,
    0x5B316BFD4AE0D489ULL,
    0x32A9789DA244A6F1ULL,
    0xC5,
    0x02,
    0xA6,
    0xA7,
    0xF7,
    0x52,
    0xE4,
    0x02
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseHSalts = {
    {
        {
            0x3E9FF17B8686FEA4ULL, 0x93E4B8C6ACEB1379ULL, 0x6F5BDC83A79BB407ULL, 0xB23787B4B07972FDULL, 
            0x759731E03ECE9EB8ULL, 0x2CD53EEECE180874ULL, 0x33A30F020A58DFCDULL, 0x45764FCADFDE2EABULL, 
            0xF55E4E619FA29711ULL, 0x8F797BD97CC388D9ULL, 0x9FB936CC4A03EE55ULL, 0x4C17E16D720714FEULL, 
            0x75CCAEDED3D299BCULL, 0xEA6D94AC173932BEULL, 0xC805F22A929891C6ULL, 0x55806276E2698DCEULL, 
            0xE2AC52A776666BFAULL, 0x36DA25307D4B055DULL, 0x2EC20C752A0BA8FEULL, 0x1FA09A55F81A5141ULL, 
            0xFE6C324C474FFC19ULL, 0xB747898A9149C643ULL, 0x31A222871D538B6FULL, 0xD0C1A9566D2C14C5ULL, 
            0x09EBD7A4AA7E6490ULL, 0xF9BC7C0646AA621EULL, 0xBA87C5F2731D00FBULL, 0x149D74A5FCE331B6ULL, 
            0x7F1DCAF8B4F9DC10ULL, 0xF5FD2F38DBA6884DULL, 0x80A8B126C3D5B058ULL, 0xB797DA151FA5494FULL
        },
        {
            0x543C86550119E7B8ULL, 0xA8FB90EEB479E203ULL, 0xA4DDFF3541EFDD28ULL, 0xE43BC36CA30B4479ULL, 
            0xEE88FA2861202DF4ULL, 0x5B7725984C631D14ULL, 0x144711AED7963341ULL, 0xBE2D052A120E5D78ULL, 
            0xC9BFC2AFCF7A1EA8ULL, 0x75B2408BF2F513BFULL, 0x7206D38B069FFACEULL, 0xDEAB40088D0031F2ULL, 
            0x020EC6406CCB416CULL, 0x5AA7FA2F8C06097DULL, 0x2F4FF63D5D9DB3D5ULL, 0x2A0851AED9E7429BULL, 
            0x0010076D1A80CF45ULL, 0x20ECBAFB262F1FA0ULL, 0x2D23E8F869965C0EULL, 0xC281E54809F0C706ULL, 
            0x30CBAE7A7C06D7D6ULL, 0x1C547AF41AA64C5BULL, 0x85F75563F9779A28ULL, 0x7969A12A495056DFULL, 
            0xAD979B574859E54BULL, 0xF48D8CB533A020CEULL, 0xD02788367D6834F6ULL, 0xF37AC8C19C4A17D8ULL, 
            0x934162A4409B5395ULL, 0x4988919228794C96ULL, 0x8B212B3E316F54D1ULL, 0xD6DD5330026F5859ULL
        },
        {
            0x0B00619E44CDA1E7ULL, 0x1D477EB8541A6EC3ULL, 0xD40AD8617CC2F099ULL, 0xBD74001E3207D25AULL, 
            0xDA0C846E4CE29905ULL, 0x66E763630A4D452CULL, 0x63D14C96770A9EC3ULL, 0x13601200F6E68F88ULL, 
            0x6D38C5AC6741E2BCULL, 0x2F960EBA7AE6D70CULL, 0xEF1C745CC41E86FCULL, 0x8EAB122CA8A54847ULL, 
            0x81FD6531BC772C0CULL, 0x7199CD7D56C76861ULL, 0xEBF8D72C834F531CULL, 0xEF506BA13E950118ULL, 
            0xCC894265DA3738CAULL, 0x11FC9BC2603E038AULL, 0xD89C8892C9DD5624ULL, 0xC6588F59F0B18451ULL, 
            0xEEE6329492128A8FULL, 0x19ECC875B0FEA4C3ULL, 0x96B327FC4C81956DULL, 0xFCDB94C2F70EA39CULL, 
            0x3E5FC25AF2A7B11DULL, 0x62072637B1D47631ULL, 0xD470C44EDFBB661CULL, 0xB9DF5A25DE9715E4ULL, 
            0x85E5504ABDB21F02ULL, 0xF4524C39E611F5CAULL, 0x7DD1E84C52C4F7E2ULL, 0xA685A0DBF241018CULL
        },
        {
            0xA4BB7AC22DBAE184ULL, 0x36C73D97EABC558DULL, 0x3F341BC2732FFDB6ULL, 0x34A2099E7869D51AULL, 
            0x164DFA8871935C80ULL, 0x27C1C933DBC241AAULL, 0xB9C4D3C4F0500DCDULL, 0xC6355E3B3CC7C63BULL, 
            0x1F8035B2F2D74186ULL, 0xBD083ED99CB7FBC5ULL, 0x9A902529D5424ED4ULL, 0x5ADAC758F8C8CEA7ULL, 
            0x081A6597F53C6EB6ULL, 0x4F452A69045F9230ULL, 0xF66F142862AAB183ULL, 0x620652C6CBBC106DULL, 
            0x4AB6930D639E0379ULL, 0x636785291D1E5A9EULL, 0xFB17EAB60B7CCEA1ULL, 0x26EA3384BBB3347EULL, 
            0x026FC868E7980B71ULL, 0x1F799AFD7EA1E3E1ULL, 0xACA0136B4FEC82D4ULL, 0xA298597CD9060FE3ULL, 
            0x7B8DFD71A9F9B1D8ULL, 0x6A853EB5312FC63BULL, 0x51DAB12C6FC5E6A0ULL, 0x0D2C2F8D906EF2A6ULL, 
            0x55FC3755FEA469C9ULL, 0x5F2F42DF5C3C4E27ULL, 0xA9062FB8AE621DB6ULL, 0x921AC9431354C5FCULL
        },
        {
            0x4F89E864AA26074BULL, 0x6CA200702D797413ULL, 0xF8E27643551633B4ULL, 0x9297323A35D8259AULL, 
            0x747709E2136F2A38ULL, 0x650743C3D1082820ULL, 0x20A111AE18076644ULL, 0x5D4C3339E2E895C9ULL, 
            0xCB4C5EB80F0D7B96ULL, 0x4A91EA8D5350649BULL, 0x453684E4AF63A75AULL, 0x35D1583B229EF7BCULL, 
            0xC935FC53B0399A78ULL, 0x08C08CEA988CAFB2ULL, 0xC879B0436C4F5C07ULL, 0xD45C7DDBB58AF288ULL, 
            0x7E4699D06C72CDEFULL, 0xB6586D5C09CA6563ULL, 0xF4A0B75B245B3D7FULL, 0x498F7636EFC65439ULL, 
            0x93786D97AA75B2D5ULL, 0x997A3C50DF9D1C90ULL, 0xCD18E5EDC63995CFULL, 0xD10274F5E043719BULL, 
            0x3D6C8196023DBA6AULL, 0x5EBF9F31FF3AC104ULL, 0xDF0EFFFB696AF993ULL, 0x292DDE2B8F9288C1ULL, 
            0x18A5C23FDFAB5304ULL, 0x1A4979003BB6ACBCULL, 0x5522B5423ED1A214ULL, 0x9DF023662708955BULL
        },
        {
            0xF5479932A4C2401DULL, 0x3081CB09B3D0B02DULL, 0xEF43785DF909253CULL, 0xF3F3CB6481C5580EULL, 
            0x0D16A057D990D735ULL, 0x41A94D609A1BDCC7ULL, 0xF7E72253868045DCULL, 0xC00487FBE42B63F0ULL, 
            0xCF0A55B8A7B5A49AULL, 0x8464D5307121B537ULL, 0xB26B3AEECFA1DB07ULL, 0x082751E3C84D72E8ULL, 
            0x2BC5C0310988D105ULL, 0x0D1C7CB3AA19A774ULL, 0x7FEA431C0F6F484FULL, 0x833CA8FB301F909AULL, 
            0x9B1962423ADBB93DULL, 0x27D1858B3A12F8B7ULL, 0x2E2DB0A326713CE6ULL, 0xED30402717AA52A7ULL, 
            0x0B4D0BBDB950733AULL, 0x5D4D1F0B4AA4C9E6ULL, 0xBB588A736DB7238DULL, 0x616B6446655BFB89ULL, 
            0x9CAD27232C811786ULL, 0xA8C8A9D522860B63ULL, 0x6A9D20529BA01631ULL, 0x26D8EA1AFCC9ACE0ULL, 
            0xF14F8C4E7C0F018DULL, 0x19F47BE8327C3275ULL, 0x3265231AAF9AB0BCULL, 0x0B312B1C815C02BEULL
        }
    },
    {
        {
            0x6997B4255E3DB424ULL, 0x17E974C79FC3B9FEULL, 0x2BF93F511060A097ULL, 0x6A7752EB01149138ULL, 
            0x9613559D29998E80ULL, 0xE4E57C3363258425ULL, 0xCE3F8267941E270DULL, 0xF7E1CDA80515FFA9ULL, 
            0xAF10DEAD670A2FB5ULL, 0xC61D3851E792D335ULL, 0xD4B71840E4862D37ULL, 0x84506E4018C1467FULL, 
            0xA50701AE5B1E8756ULL, 0xB6314876DC6F6E9DULL, 0x0AE2A341BF3FF7B5ULL, 0xBA03B2C009595E60ULL, 
            0x64820E0CA9E26DADULL, 0x1489BB1681610D8BULL, 0xC1E3D0DAB7EDAB36ULL, 0x02B9257F8E19B78BULL, 
            0x603A2C8E51C72762ULL, 0x5BB05C18DD3CCCAAULL, 0x9774C7595FCB3361ULL, 0x16DF5B031E4129F3ULL, 
            0x136B77C2F87283E9ULL, 0x5EE70487BC7B2C0EULL, 0x2679E72B6A88D267ULL, 0xF12674528B1CE229ULL, 
            0x1F519B3B5CB446B9ULL, 0x88E68AEF9F6BFDBCULL, 0x7EE12BBF6B0D2319ULL, 0x6A07F564F486AB22ULL
        },
        {
            0xA667476897D33251ULL, 0x08FEB63A1A1187E8ULL, 0x6F35F05DE21C11DAULL, 0x248EE82D6042B519ULL, 
            0xB154EAB79955FC32ULL, 0xDF7DC3AF2FA0DD7BULL, 0x1DE2CDC023493F41ULL, 0x1D6D89EE04E7303BULL, 
            0x010660EEC82F23ADULL, 0x75859CBD7A067ACDULL, 0x2828451FE5E164EAULL, 0x2219202EE08F8284ULL, 
            0xC8C3D8FACB42AA9CULL, 0xECADBE25ED73E4DBULL, 0x02413D1120D72FFAULL, 0xDE3DAC92B009A8EEULL, 
            0x328817B3FFB08043ULL, 0x4A7B23E2F169974BULL, 0x92DB28F67C52BA53ULL, 0xEF267F4E0F717F50ULL, 
            0xDCD19E7F7DC21CC7ULL, 0xA067FD2C6A8CB347ULL, 0xC7FB95320DED3D1AULL, 0x015F09006059848BULL, 
            0xF456DBEBB5A557C0ULL, 0xBBB68E1674BE770EULL, 0x3DE4C14D6598FD52ULL, 0x6BA71C8C0AB28B33ULL, 
            0x0C6B801DD54CD99CULL, 0x4DC301CC6959DFA6ULL, 0x813814340DE3B3F9ULL, 0xB48DDA130039ABDCULL
        },
        {
            0xDAEA004873AF376FULL, 0x609DB8819823E839ULL, 0xF70283B4275BE007ULL, 0x87D431BD6409BCC8ULL, 
            0xF5C59E74CDE7983CULL, 0x1AA361221C2F55FAULL, 0xAFBFF50D721A9CCBULL, 0xE4EA9E53586CC50DULL, 
            0x55FE83821C740A75ULL, 0x22A3D81254E927F2ULL, 0x874AF70100EAA911ULL, 0xF26B94709F951800ULL, 
            0x3688E2716A754531ULL, 0xA622AECDFCB172F3ULL, 0xB614666B0E06CAB4ULL, 0x9953456768D18813ULL, 
            0x194BBC549936898DULL, 0x3089DDF1813D2F59ULL, 0x60977241EC7C9E8AULL, 0x97338A094702CE3FULL, 
            0xA00654DD71815165ULL, 0x48DAB239889DB99AULL, 0xAC827CECDDF511F9ULL, 0xA46018474A4CA2D6ULL, 
            0x06D7384C98DFEBEDULL, 0xF51A8C6ECF2560AAULL, 0x0158AEA4B1C9AAAAULL, 0xB4E39A61FCE43B27ULL, 
            0x7E827FD73C6921CAULL, 0xCEBD76B4CB054547ULL, 0x7DC8118B90562648ULL, 0x1DF4E69EA6C107C9ULL
        },
        {
            0x209211474E7CD959ULL, 0x3A69D45D4CF577FDULL, 0x25C79869BEF4CAE0ULL, 0x0E3F0D7A0F754C2AULL, 
            0xD0FB00EE959501E4ULL, 0xDDB8660C8099AC42ULL, 0x2B6C87500353789DULL, 0x18657AA138BFEC99ULL, 
            0x163811212C85106CULL, 0x264E368C184ACB76ULL, 0xB6EBD9E1CC05CFADULL, 0x6EC9D1B1CD685405ULL, 
            0x6985FB6A62E026EBULL, 0xC06EA762956AD12DULL, 0xDBEE5B43639ED15AULL, 0x5CB788CE6A37A077ULL, 
            0x8DF402E5DFEA910BULL, 0xDDE19F18028D5CD6ULL, 0x930E6EFCE1423F46ULL, 0x1B9931B798693728ULL, 
            0xF5652622FC39B210ULL, 0xBF82C5B65724E73AULL, 0xE2B7A0A0D6B3E919ULL, 0xC85E999F080625B6ULL, 
            0x9DC566B98EBE519CULL, 0x7387701397D39CB5ULL, 0xDFC94CAA8ACA6004ULL, 0x4623A407A7553E06ULL, 
            0x55BD6B82ECCBD24AULL, 0x83313665F42BBA7AULL, 0x58E68446B2D15C8BULL, 0x4ECC6FE62AD7A19AULL
        },
        {
            0x2A048584A69BEDAEULL, 0x44EC7D2000215D6EULL, 0x0132A254DEE52C62ULL, 0x0E3456377044CF9AULL, 
            0xEF7D2A4DB485DDFAULL, 0xA84BFA07F7722D7AULL, 0xC39E5B53DAB21AE9ULL, 0x06932D6116FFC21CULL, 
            0x9C9D19FB104EC9D8ULL, 0x6E6175D00CB06BF7ULL, 0x2EFE068A8A1A311EULL, 0xCA08257B7E83AB19ULL, 
            0x111FE18355C05BF8ULL, 0x3BA18BC31184ADB2ULL, 0xCE0B82BCE2E24F80ULL, 0x2E7CCE3B0E2D16DDULL, 
            0x274D11AE4F150BC7ULL, 0x1407472C936B479CULL, 0x83600A96F5DDF588ULL, 0xCD45F78D87437A5FULL, 
            0x7192887EE4DCA144ULL, 0x83D9E9D5E7BD98E5ULL, 0x55196CAE33878F6FULL, 0x236B9BA6B873387FULL, 
            0x520F7F30AB3E9BB4ULL, 0x37213F45CFE13701ULL, 0x0F2A30008949A066ULL, 0x20B7516A29CC507BULL, 
            0xD6B914BECF85B635ULL, 0xD08CD3445CF4BABDULL, 0x0A4F1E0B9EACEC70ULL, 0x5480F20DAD890198ULL
        },
        {
            0x8095AF94B57F04DDULL, 0x6E5BCF2ECFF0BDF4ULL, 0xD56A1F62F2BD6259ULL, 0x2022F3376E8F463AULL, 
            0xA400FAE86276624FULL, 0xC48A3A620449F9E5ULL, 0xBC862CD95A6D0E1DULL, 0x446560F555D1B4C7ULL, 
            0xB51B98E641F7DABBULL, 0xF92DDCACEF4224BAULL, 0x77149407610C8B96ULL, 0x871EFD9C656ED25EULL, 
            0x89A0F872D3718462ULL, 0x7498DB46810F761CULL, 0xF7EDD76B587E1FBDULL, 0x1A2E842D349947ACULL, 
            0xADDC42C0F23F936CULL, 0xD0B2562D692258CFULL, 0x1E84A6654B5E5C2EULL, 0x3CE521509C4B1CC2ULL, 
            0x403DECD29D31F9ADULL, 0xE4F0D150BB334D04ULL, 0x90ACAED1D69DE2C2ULL, 0x070B8A6752A8B898ULL, 
            0x337CC35D52AE46ADULL, 0x0560B0F8A406D287ULL, 0xFB41BD37247AF81CULL, 0xA640E8E2E901A734ULL, 
            0x6855A911F8781EFEULL, 0xF239598007E0AF77ULL, 0x673399F7DC47A7AEULL, 0xDDA00255608DCA05ULL
        }
    },
    {
        {
            0xF0703FA9AF7BDDA8ULL, 0x01E25ED5904E4553ULL, 0x337B69AEF96B4A6FULL, 0xA694A65B13E7631FULL, 
            0x04B06676EC807F0BULL, 0xB0B208E9DB2E45E5ULL, 0xFDE704CAE9F5FC48ULL, 0xF2CFB8F684C813E1ULL, 
            0x9FA8EB3629D63729ULL, 0x152A45FF45449229ULL, 0x3D740FD08DE53268ULL, 0x6E7D4710A66CDA24ULL, 
            0x895C2B38AFB70980ULL, 0xD3CDB903CC842FABULL, 0xB782F732BF61BCA0ULL, 0xAFF129CB9ECAB703ULL, 
            0xFD62C45B57A42137ULL, 0xF3116706A5292014ULL, 0x604F883A390F6D2CULL, 0x9A607DF271271741ULL, 
            0x41E45D8E26DDFC08ULL, 0xD5308F4506E94CDEULL, 0xE18B2C4D6054E815ULL, 0x1CEBC2BA3BFFA109ULL, 
            0x393D565AAA711DA8ULL, 0x804BD44924958F40ULL, 0xD4FA5738084AB523ULL, 0xA9456CFA4BA04C84ULL, 
            0x7C9628632762DF11ULL, 0x5C552F15F45860EDULL, 0xCAF89F9FC024520EULL, 0xEB40448C54042CFDULL
        },
        {
            0x9D2A93585A7B20A8ULL, 0x18F412AB3EE4F452ULL, 0xF40982E79D938EA8ULL, 0x701CA8982EBFBDCFULL, 
            0xE25651021964796AULL, 0x7608DE026E01DCD9ULL, 0xE9EA58714C622A52ULL, 0x64CF7D85BE34694AULL, 
            0xCE9AE7484C7F47D0ULL, 0xFDFED932B18BB6F1ULL, 0xF4ABB2C59C37C9D1ULL, 0x978280B6523D2FD7ULL, 
            0xCA35DEA582DD05E9ULL, 0xDC6B75DD585242D1ULL, 0x7A7BB54A975CA6B0ULL, 0xC6E7C35059F24FF0ULL, 
            0x80BC6E373606CF0EULL, 0x8D29ECDEC28C8C98ULL, 0xA1C38F8E35C3281DULL, 0xAFA79DC263EDACFCULL, 
            0x0B0B8C2253ADC4E0ULL, 0xD1662393421A9810ULL, 0x202A958E0D64B621ULL, 0x7F65E1068C40C8B4ULL, 
            0x2055A18773F4FB90ULL, 0x83B432D21DE58C47ULL, 0xAB0F619F40D15D39ULL, 0xF45CA3FC94064DDBULL, 
            0x539C2E681668D4E7ULL, 0x11BC48AB8D5D1C62ULL, 0xB4EE309650EE2F0EULL, 0x2459D5AD0F0319C9ULL
        },
        {
            0x1F8D400D23C0421AULL, 0x1D349A8E2F019C40ULL, 0xB92919F1E609527CULL, 0x91903C928E3E0E51ULL, 
            0xD76D0DFE1EBC13EDULL, 0xDA4570C3376FA16BULL, 0xC3CDCF72736F74B9ULL, 0xC3B63FEDB0B625D7ULL, 
            0x2EE228081B158057ULL, 0xFFC92AEBE3FE1D7CULL, 0x17C816F55B50FB7DULL, 0x8456101588AD254FULL, 
            0xF7E7E3DABEF8A9CBULL, 0xFB362C782143E958ULL, 0x66621C7B49EB9DE5ULL, 0x86C1DB274D53C2B8ULL, 
            0xDA535DEF639CF571ULL, 0x17E0A07527387630ULL, 0xA06B6E399B1E9E0CULL, 0xCB158A61D3E82DCAULL, 
            0x8AF6DEEDFB635F12ULL, 0x952644D637CE5F4EULL, 0x4E0F4311400E186BULL, 0x6E60F6BBEF0B1E9AULL, 
            0x06E83B0F309A5AA6ULL, 0xD8B2061520183F68ULL, 0x3BB904864B5F183EULL, 0x93A76FC4B0634815ULL, 
            0xE69431C096E785EFULL, 0x334140AFA21A3A67ULL, 0x38C797421B623F31ULL, 0xD20BCE7797F7DF15ULL
        },
        {
            0x79BFA1C91CD986FEULL, 0x14B9874050711145ULL, 0xEB25D50DC785E801ULL, 0xE000930333821992ULL, 
            0xD763408972351EC7ULL, 0x793BAE8C905C30B8ULL, 0x5012CB8A492F3E5FULL, 0x638BF38680DDACE0ULL, 
            0x2F8F4433820A462AULL, 0x8E0E83FF6B0781CAULL, 0x4B56CDBD62581106ULL, 0xB79D3E8DC1E765DDULL, 
            0xBFD277C459E631CEULL, 0x35CB6851030E3B9BULL, 0xFBB3BB833CE0BCF3ULL, 0x4BAB95C6E283AB9AULL, 
            0x06C2A52AAA52F91DULL, 0xBDB45958DAD56910ULL, 0x8A3123DD575BF596ULL, 0xA779EE95E27797F4ULL, 
            0x416D7D0B3F7AE1C4ULL, 0x2E6D434DC2C3E21CULL, 0xBE39E2F041823BF5ULL, 0x2CA1F18CE3A77D5FULL, 
            0x239006ED3B64BE8AULL, 0x820764041E3E54B1ULL, 0xB469FA5FEAE924AFULL, 0xD82176F254084568ULL, 
            0x4938E15D7BFDD98FULL, 0xA6A8B129C090829EULL, 0x9037FCF30E76D041ULL, 0x1AA014C802856B76ULL
        },
        {
            0xAB9E9EE89BFF06B0ULL, 0xC6F5FCC25F4054F5ULL, 0xC5254437E5AE0D25ULL, 0x17394E3A94EA14DEULL, 
            0x9C21FD9B8B825F73ULL, 0x9AE4E1B6E9B68EE5ULL, 0xC61FA9A04C934C10ULL, 0x9C7E0F322BC31515ULL, 
            0xFEA92C3381C7BFC8ULL, 0xD654CF1514BDDDE0ULL, 0x63377DFCD42236DCULL, 0x3BE401EDD4E2A270ULL, 
            0x555F06B1E4D8A86FULL, 0x9914EBA78FACBFA0ULL, 0xBBAD52F44805BB6CULL, 0xF3A827C142F4895DULL, 
            0x657B8BAD25750864ULL, 0x22C32AB5DBC83161ULL, 0xA1DE20898B879436ULL, 0xA97D795F93905CB1ULL, 
            0x610561F896909865ULL, 0x66507DEBF1FB9364ULL, 0xFC983E8F43AA9396ULL, 0x76515BBEED347BCAULL, 
            0xEE3B3B31B8BDFBBAULL, 0x801F534B75329DA4ULL, 0x8F99646309C00EDFULL, 0xA58D45E4E1989449ULL, 
            0xF4E9C24223BD3E61ULL, 0xB10134058CA69BADULL, 0x2B41B6C7DDDA6B73ULL, 0x06A1DD401410BA67ULL
        },
        {
            0xB382A0998C11B0B6ULL, 0xCCFF211FA1E91689ULL, 0x41A698E9764F1C0FULL, 0x00B75819AAAF4D2CULL, 
            0xD10EEBF395C0D74CULL, 0xD56260A1C1595B77ULL, 0xBAC466638BCC469CULL, 0x7C94334359D70B77ULL, 
            0x864647763BAFEDB3ULL, 0xFB01B93C6C6DC6E3ULL, 0xFF529F607D760596ULL, 0x44E3F7EA1CF2CD36ULL, 
            0xEBED5343925DBC0AULL, 0x648B892FE0CE5C7DULL, 0xB325F4662B71C165ULL, 0x0D8A05FF9519F362ULL, 
            0xFA835E67740DD065ULL, 0x7714601DCDE8CAA7ULL, 0x108C6F14F6BED948ULL, 0x593D3A115DEACF0DULL, 
            0x6745D310AEA8F044ULL, 0xE3AD1B4A1B4DF8CEULL, 0xB19917501240617EULL, 0xC1B2071C7D6FCFA8ULL, 
            0xC05F8470CE726389ULL, 0x08C2064DC8FD8423ULL, 0x3429F5B8F8C4654AULL, 0x74C148994E3F8F5AULL, 
            0x8D03F0761302E429ULL, 0xE3AA7E9F67F92467ULL, 0x440D0B331601619DULL, 0xD75FB73AAE14EF1EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseHConstants = {
    0x5A1D4FE970B85764ULL,
    0x0439C392D56BC5DEULL,
    0x84859B8E72208EB9ULL,
    0x5A1D4FE970B85764ULL,
    0x0439C392D56BC5DEULL,
    0x84859B8E72208EB9ULL,
    0x00BEE1092B354567ULL,
    0x36E5CCF93275D9FBULL,
    0x6C,
    0xB1,
    0x7E,
    0x36,
    0xC2,
    0xB8,
    0xDB,
    0x9A
};

