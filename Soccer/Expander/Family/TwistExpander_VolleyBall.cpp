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
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
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
    std::uint64_t aPrevious = 0xDC8D5C7EF2D1F79CULL; std::uint64_t aIngress = 0x879E875EB215A53FULL; std::uint64_t aCarry = 0xEE374E32257B29F9ULL;

    std::uint64_t aWandererA = 0x888B0593D80EB5F7ULL; std::uint64_t aWandererB = 0xE034F34F7D7CC69BULL; std::uint64_t aWandererC = 0xA4F3D09A0A92B2D4ULL; std::uint64_t aWandererD = 0xA08AF78DE6504232ULL;
    std::uint64_t aWandererE = 0xCC3F4D040A79F0FEULL; std::uint64_t aWandererF = 0xAE102EF7A5CFAA66ULL; std::uint64_t aWandererG = 0xC281BB21B78D1034ULL; std::uint64_t aWandererH = 0xC0C7258C49A3D5DFULL;
    std::uint64_t aWandererI = 0x9FC699B9EE7DC2A0ULL; std::uint64_t aWandererJ = 0x8F1C9E9946ECB61AULL; std::uint64_t aWandererK = 0x985B416EEE48A309ULL;

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
        aPrevious = 11293332780687162766U;
        aCarry = 18428605582061944296U;
        aWandererA = 9817535926591658388U;
        aWandererB = 14778325596270429494U;
        aWandererC = 17577739431616126433U;
        aWandererD = 17763973358356129134U;
        aWandererE = 15563681069785602632U;
        aWandererF = 15899204786355126033U;
        aWandererG = 13409808285740976219U;
        aWandererH = 11206096090843114543U;
        aWandererI = 16043644091984271332U;
        aWandererJ = 17047041863668189800U;
        aWandererK = 10916958510336610890U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: work_a, work_b, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::KDF_A_A(pWorkSpace,
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_D(pWorkSpace,
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
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
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
    std::uint64_t aPrevious = 0xAF8F505ED015D98FULL; std::uint64_t aIngress = 0x829787A956EDA5C5ULL; std::uint64_t aCarry = 0x8F4327AA8AC023A0ULL;

    std::uint64_t aWandererA = 0xA2AF427AB0776956ULL; std::uint64_t aWandererB = 0xF117C9D7AF3DF290ULL; std::uint64_t aWandererC = 0xDF1C8E557A261E02ULL; std::uint64_t aWandererD = 0x9FC2A66B80817DA3ULL;
    std::uint64_t aWandererE = 0xE04B07486C375B00ULL; std::uint64_t aWandererF = 0x96A8C340E1EE999DULL; std::uint64_t aWandererG = 0x8AF660A14BD56744ULL; std::uint64_t aWandererH = 0xE52DA70668C79A77ULL;
    std::uint64_t aWandererI = 0xD157F9A6D3ACD9FAULL; std::uint64_t aWandererJ = 0x976EA04AAD562E41ULL; std::uint64_t aWandererK = 0xFA0D691161F8E59FULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 16771307704865094302U;
        aCarry = 11938373776989272485U;
        aWandererA = 11545499631582629643U;
        aWandererB = 16598915820856029909U;
        aWandererC = 9399050696859544477U;
        aWandererD = 16226952838915586133U;
        aWandererE = 14892356359959367568U;
        aWandererF = 11884412741403382200U;
        aWandererG = 12728741462452245419U;
        aWandererH = 16123208785534293780U;
        aWandererI = 15711158391149730204U;
        aWandererJ = 12320342712485958353U;
        aWandererK = 9700731697073828805U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::KDF_B_A(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::KDF_B_B(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::KDF_B_C(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aWorkLaneA, aWorkLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
                         aWorkLaneC, aWorkLaneD, // output lanes
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
    // KDF_B_D kdf_b_loop_d:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::KDF_B_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xCE636E912B9B887CULL;
    std::uint64_t aIngress = 0x83CCBB58CA357D89ULL;
    std::uint64_t aCarry = 0xE4AF58DBA0B885FBULL;

    std::uint64_t aWandererA = 0xA3ED100DD3E5E3D7ULL;
    std::uint64_t aWandererB = 0xC46D8625E4AC840FULL;
    std::uint64_t aWandererC = 0xC8FDABDE3164E504ULL;
    std::uint64_t aWandererD = 0xAE3D9E8C62D99B9CULL;
    std::uint64_t aWandererE = 0xA9FC5269342199D3ULL;
    std::uint64_t aWandererF = 0x86F63360659617ABULL;
    std::uint64_t aWandererG = 0xC8D89A6E3F5EF2D0ULL;
    std::uint64_t aWandererH = 0xD8C39FE66D301319ULL;
    std::uint64_t aWandererI = 0xD7242437E820FC75ULL;
    std::uint64_t aWandererJ = 0xB85E0690AF756240ULL;
    std::uint64_t aWandererK = 0xD7587E07477C7B19ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Seed_A(pWorkSpace,
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
    // GSeedRunSeed_B seed_loop_a:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Seed_B(pWorkSpace,
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
    // GSeedRunSeed_C seed_loop_b:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Seed_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Seed_D(pWorkSpace,
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
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Seed_E(pWorkSpace,
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Seed_F(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aSnowLaneA, aSnowLaneB, // output lanes
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
                         aSnowLaneC, aSnowLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_h:
    // ---------------------------------------------------
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_VolleyBall::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSource,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSource, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    std::uint64_t aPrevious = 0xB1F5EC90F33C4691ULL; std::uint64_t aIngress = 0xF3D01F6266EC9B30ULL; std::uint64_t aCarry = 0xE4A691A2216B18AFULL;

    std::uint64_t aWandererA = 0xC1EF801AB945C2B2ULL; std::uint64_t aWandererB = 0xCBBAF4DDE595E69CULL; std::uint64_t aWandererC = 0xAF6EACE73BC9FA35ULL; std::uint64_t aWandererD = 0xB479183AED9A7C99ULL;
    std::uint64_t aWandererE = 0x942BD1C8424F9EEBULL; std::uint64_t aWandererF = 0xDE08A09FA24EA1C9ULL; std::uint64_t aWandererG = 0x8DD4207A08E1ACD5ULL; std::uint64_t aWandererH = 0xD6191C5E206C84D1ULL;
    std::uint64_t aWandererI = 0x86F0A7DA20B839EFULL; std::uint64_t aWandererJ = 0x9A5ADEFE15C325F1ULL; std::uint64_t aWandererK = 0xD900150941C71A42ULL;

    // [seed]
    {
        aPrevious = 12731055016079288971U;
        aCarry = 13601590484522966485U;
        aWandererA = 10131762065775236695U;
        aWandererB = 13230247593521812425U;
        aWandererC = 12304518522951126790U;
        aWandererD = 10606853547544691031U;
        aWandererE = 11717293788229082853U;
        aWandererF = 12160525385761717930U;
        aWandererG = 10159744023163723636U;
        aWandererH = 12185667434959120321U;
        aWandererI = 11013109243735994465U;
        aWandererJ = 9307366278879405456U;
        aWandererK = 15645385650360885160U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Twist_A(pWorkSpace,
                 pSource,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Twist_B(pWorkSpace,
                 pSource,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_VolleyBall_Arx::Twist_C(pWorkSpace,
                 pSource,
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
        TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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
        // read from: aOperationLaneA source quarters 0, 1, 1, 2 with offsets 6303U, 4911U, 1959U, 6414U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6303U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4911U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1959U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6414U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 3 with offsets 2936U, 3709U, 3612U, 5239U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2936U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3709U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3612U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5239U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 1 with offsets 6153U, 2880U, 4605U, 6246U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6153U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2880U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4605U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6246U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 2, 0 with offsets 7462U, 4619U, 5574U, 3028U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7462U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4619U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5574U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3028U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 1302U, 237U, 696U, 400U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1302U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 237U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 696U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 400U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 640U, 8U, 124U, 1851U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 640U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 124U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1851U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 3, 1 with offsets 1571U, 1794U, 708U, 26U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1571U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1794U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 708U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 0, 2 with offsets 1944U, 323U, 1603U, 540U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1944U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 323U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1603U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 540U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1260U, 515U, 1715U, 1836U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1260U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 515U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1715U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1836U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 2 with offsets 3679U, 6110U, 616U, 3229U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3679U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 616U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3229U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 0 with offsets 4916U, 1691U, 57U, 2833U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4916U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 57U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2833U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 3 with offsets 2518U, 7285U, 1678U, 4490U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2518U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7285U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1678U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4490U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 3, 1 with offsets 992U, 6546U, 5249U, 2635U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 992U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6546U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5249U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2635U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5936U, 158U, 4950U, 283U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5936U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 158U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4950U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 283U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1321U, 996U, 1717U, 1395U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1321U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 996U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1717U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1395U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 517U, 1619U, 1403U, 1212U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 517U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1619U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1403U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1212U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 971U, 2045U, 1711U, 171U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2045U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1711U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 171U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 2009U, 621U, 874U, 856U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2009U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 621U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 874U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 856U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 [0..<W_KEY]
        // offsets: 412U, 1207U, 1514U, 1399U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 412U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1207U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1514U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseASalts = {
    {
        {
            0x143778B2AF5A2385ULL, 0xAE79C555EA0260E5ULL, 0x713663B3939263E8ULL, 0xFD7E187A5B50B21BULL, 
            0xBA23F2D17EFEE68AULL, 0x0D539DCE8030646AULL, 0x036B707B0AF15778ULL, 0x8C28F7FC673916B8ULL, 
            0x4D4057594A2EF0CCULL, 0x3DECFA38F978DF43ULL, 0x2844C4BF11AF733EULL, 0x9515ED867DCAA0C6ULL, 
            0xEDA8CEA8880BF9E4ULL, 0x32C20C3427112CAFULL, 0x89D0E2CB6CA68C36ULL, 0xF9AFB3E7BEF1BC96ULL, 
            0x55117FAE659DF6C2ULL, 0xF18DEE837045242AULL, 0xE96FC0D431D72070ULL, 0x9E135DFC1FF1CA21ULL, 
            0xA6B74A34FC1439B4ULL, 0x15E1185F38AD9A93ULL, 0x31A7EEF5CEBCFFDBULL, 0x026C3CFD5FE5AD91ULL, 
            0x20137CDCC24D7DC4ULL, 0x353A49817FFF13C7ULL, 0xEF24CD720EFAF8CDULL, 0x1216EE999927F796ULL, 
            0x15A85C1F182593C5ULL, 0x27107C5EEAFA987EULL, 0xAF549BEF7AAB8E17ULL, 0x29BA7B8B3BBE0F51ULL
        },
        {
            0x0A5B92CEFF26910BULL, 0x461DC520AEE53BA2ULL, 0x7A9A4A43A91088DEULL, 0xEC3335B313BE08EAULL, 
            0x7ECE39D6738501B5ULL, 0x7922DB98CA5EC470ULL, 0x5E1F8030775DEDB5ULL, 0x8FA6C28FB9C3F0AFULL, 
            0x352F2E56B25D2D2FULL, 0x037BBD1209926C93ULL, 0x30BDF9548C0E90F8ULL, 0x77D4A598297AC467ULL, 
            0x2745D3F89069BF65ULL, 0x9E3FC4F65D812DF0ULL, 0x0F3EAEC985FF38D6ULL, 0x127CA33768E1F9ECULL, 
            0x5F8A034805A7C919ULL, 0xE127BD7A94B91797ULL, 0xD559888C08B62924ULL, 0x191BC48A21795B99ULL, 
            0x9D9FD1441B75274EULL, 0x80CCA5B1D6F83ACFULL, 0x45A9861CA1C1B964ULL, 0x21B1FEAB6109D368ULL, 
            0xDF4D777EEBAF4167ULL, 0x63E4D5D937F344DAULL, 0xA31B08D26CD6BB24ULL, 0x96A77D648F42995EULL, 
            0x6E72541170A3D3BFULL, 0xB63D65CCFF1E323CULL, 0x35809F645F55548CULL, 0xC20F67B68F14170AULL
        },
        {
            0x812EE450B38F2AC3ULL, 0x851FA9D65FD196E3ULL, 0x0410B7E91093D5FCULL, 0x764D0A4B2AE6FFACULL, 
            0xA7FF864D2B7395C4ULL, 0x8CF6D3C76F075C6BULL, 0x67B5EBADC383438DULL, 0x3DBE5F0AC158AF24ULL, 
            0xE6160F9B5C9A5D1DULL, 0xF6A8784BB97A9799ULL, 0xD71820280E2AD7AEULL, 0x8715D11038B1DA9FULL, 
            0x098CAC382FB9E608ULL, 0x2001D6B9E6B057FFULL, 0x287DFBF6C35EAB19ULL, 0xE4913AA8430973B5ULL, 
            0x581A8EA8B626457CULL, 0x44511A3146672403ULL, 0xC2D567E90E9F725CULL, 0xB9939595D61DF518ULL, 
            0x3ED35EBA285C4340ULL, 0x73F226FC314835CAULL, 0x238B787474770A26ULL, 0xF6FBA6503DF8EFC9ULL, 
            0x91284271C640D920ULL, 0x030B8F279EEB4CCBULL, 0x4AF9962547F6A705ULL, 0x2DC77BBF840FB501ULL, 
            0xF69C7F800E7D5891ULL, 0x2A2CC09DBE74BC25ULL, 0xFD973C1C9CCD8CCDULL, 0x0C880E3B378FE2D3ULL
        },
        {
            0x61F1DDE5E5C4C416ULL, 0xF9F5FDD23BF3F6A5ULL, 0x683C1664A2C1224CULL, 0x24928A32CD5FD397ULL, 
            0xCC429305790EC755ULL, 0x6E72AD9065D6FA02ULL, 0xA466301EAFD8B4BDULL, 0x1D5398267BED8ABFULL, 
            0x003BA964F551BCE3ULL, 0x3A4BAB13B7E446C2ULL, 0x570312C1AC02ADC3ULL, 0x9FD192DE3FFC970FULL, 
            0x2E5E8DEC983B024BULL, 0xDEC2087E5B640AE4ULL, 0x262EB6F28572E620ULL, 0xE2395B7778E8813CULL, 
            0xBF7FB9A5E618701FULL, 0xB13EC251F0B91C72ULL, 0x48A2836418F78325ULL, 0x0C79BAB9417BA589ULL, 
            0x75C178F3B3762D34ULL, 0x29E0062495EA0EC4ULL, 0x4539185A663DE4D0ULL, 0x9FA06DBF7BF76878ULL, 
            0xBEE2E67FE63D13DDULL, 0xE00F541106FC693AULL, 0x11094C13E6457D9FULL, 0xEFE5F695BAC3D7D6ULL, 
            0xEB63FC1F49EA6CF9ULL, 0x460C9DFCAC17BAC3ULL, 0xD45B6FC6E6FAAAE7ULL, 0xF2C669CBCF4B01CEULL
        },
        {
            0xD548953B553338A2ULL, 0x786803D12632E1FEULL, 0xB7780E7F45D4A4C5ULL, 0xA55A7A478ADD4479ULL, 
            0x84BF12F8C6467C66ULL, 0x4011271A5D9EAF4BULL, 0xC8E3CF193D2D0DA6ULL, 0x95ED39A35E9B8682ULL, 
            0x400BBDE0C8C074BEULL, 0x5D6E8F1788510C7AULL, 0xC84AB3AFBE416E92ULL, 0x2FD302EF4B877CCDULL, 
            0x3574EC5183E69FC8ULL, 0x5626166133F4E684ULL, 0x1077B25B5B08092FULL, 0x2EB4FFDF70CA9606ULL, 
            0x488B08641B2D6319ULL, 0x2974DC8219C902D8ULL, 0xB763D54853DF57E1ULL, 0x280AAECC026165B9ULL, 
            0x6449BBC4AD0C0A4FULL, 0xE1784B950E3ED7B1ULL, 0x7133A28E0BA0AC10ULL, 0x95B994573BA7D864ULL, 
            0x4D6879CEB3D27E0DULL, 0xF1A289970536BF19ULL, 0x99DD49E4FA3F1157ULL, 0x618168D694DDD9C6ULL, 
            0x95888F871404BBFAULL, 0x3F46F718D3B7CE4BULL, 0x39647C88D3FC99F6ULL, 0x4DFEB834616B9425ULL
        },
        {
            0x3D0A48951E7BC51AULL, 0xE74B7845344AB1CFULL, 0xDC62AD44AA389AFDULL, 0xE5A460C9973FF62DULL, 
            0xFF8A5A04CC74429BULL, 0xC701B94EE8ECCD07ULL, 0x6B5C0B7A4554D597ULL, 0x9BBA83574F29415CULL, 
            0x0385B17814857C3CULL, 0x1D519DB063B4A870ULL, 0xB51FAFAE212AF58FULL, 0xD8ACC5771F1E4DC4ULL, 
            0x99E56CEB5EDFF59AULL, 0x75D3562DDFF550F3ULL, 0x67F05EBBA1BFCFF4ULL, 0x2F45E5FC5503823EULL, 
            0xE51EE905D133F515ULL, 0x46FAAC6E85549FEFULL, 0x43F0D237FADA99FBULL, 0xF06A573AE6CA05BFULL, 
            0x6258061FA3DBD55CULL, 0xD3EA7BD23B0B2B44ULL, 0x941BD1051534BE56ULL, 0xABF00A93D942DF70ULL, 
            0xD0831CA94AA2BDE3ULL, 0x6268D91CC8DE6BCFULL, 0xCA691F2777189A93ULL, 0x89566ED34BD094AEULL, 
            0xDAB22AE5D1222E26ULL, 0x50B989AFBAF5AE01ULL, 0xBD953E05A9FB5BE0ULL, 0xB7209C9964AAB177ULL
        }
    },
    {
        {
            0x26B38622E5A1CD83ULL, 0x85CB42968DDB5621ULL, 0x9196656884743612ULL, 0xAED187A0114892C6ULL, 
            0x8298FC1C87F35DBCULL, 0x583F8081FECF977CULL, 0x7E32C0CF7FEFBA86ULL, 0x0916F75B442F5837ULL, 
            0x0A07D5E1153F1678ULL, 0xFCC7D692ADEAAF9BULL, 0x3A112D3E65D91A2BULL, 0x0425ADBBE5694487ULL, 
            0x3BF1FFF6C87E82A6ULL, 0xE0CFE86150407C43ULL, 0xC9E14F69E5DCB0B8ULL, 0xE67444D3A88AF1B9ULL, 
            0xB4952DBF2380BFA5ULL, 0x867EE71399B3CB4EULL, 0x32085FD383A8E9B4ULL, 0x50EB0A5301BEBB02ULL, 
            0x320D2124275735DBULL, 0x8934C52EA23FE831ULL, 0x0F1BEC9E63C11FF9ULL, 0xACA0E8EE760B3DBFULL, 
            0x38776536708F9CA6ULL, 0x8D1AFC90B46CCBA5ULL, 0xDFB3A67239044DF9ULL, 0x40484B03B783C980ULL, 
            0x186D4CFCBF7BE263ULL, 0x749F652E6608CDB1ULL, 0xDC01070A3006168BULL, 0xA54A2E7A5AC5B15BULL
        },
        {
            0x2452F46E24C114B2ULL, 0x277935920476C989ULL, 0xDED3B5B97BE02B34ULL, 0xB36EC3F19E8C0926ULL, 
            0x7B7FD49C5BB70175ULL, 0xFDFA677C12C1EEAFULL, 0x36F627A4F754DF63ULL, 0xBB39D899B72E94BDULL, 
            0x101D2AA6B7A0C3A5ULL, 0xECC1C0241550717AULL, 0x96CAD8DDE32DD93CULL, 0xB20A15C42778067CULL, 
            0xD886B7355615927BULL, 0x0C675B6E8E105001ULL, 0x64477953E439DACEULL, 0xADB7B984EF131EB6ULL, 
            0x1A67D50BC3BFC516ULL, 0xD9CBA2C050F40E84ULL, 0x3F32AE6D29E41FA9ULL, 0x9D10CBB8F3E8A771ULL, 
            0xD3ACFDA7A9F17F0BULL, 0x6CB5BEEC1DC7E9B6ULL, 0x208B443C5BA288D4ULL, 0xBAC9B6EEA7851EB7ULL, 
            0xA9F2D1243175F950ULL, 0xB166738FE500A9C0ULL, 0x0FA6CBFBCC45D296ULL, 0xFCF501BBE3EDC586ULL, 
            0xC8A5F3AC12906C67ULL, 0xFDE10973B489F356ULL, 0x29D21ADD43BFFA65ULL, 0x84A0CE68630F0089ULL
        },
        {
            0x7020A35E658A7426ULL, 0x077B9D8936025F17ULL, 0xCDF94EDFA1BEB0B6ULL, 0x9991566B64F02964ULL, 
            0x266D311FE9B5DA75ULL, 0x9EEDAD307AAA63E8ULL, 0x27A50F7DF80B725CULL, 0x503D3AE2702BE9DDULL, 
            0xA19D4E801E66831CULL, 0x1747AA5C0B1D241EULL, 0x4776C7EF43030CDCULL, 0x8F7EA36B4ACFC071ULL, 
            0xD5F0B297FE45C205ULL, 0xBBDF10D8B240E2CAULL, 0x218699C79FCE6BD6ULL, 0xC442E7AF450FD4C5ULL, 
            0x456A2BF973E28620ULL, 0xD606214AA2D804AFULL, 0x71A64DCA23DC772EULL, 0x7F4DC5070AC115DBULL, 
            0x55CF69EC78BA4C12ULL, 0x86FEE9A211E5C7BDULL, 0xB69BD47A3F33CF34ULL, 0x68B226C17F513B96ULL, 
            0xF0E4C715577F2313ULL, 0xD0459FC54EBC5BC6ULL, 0xD2CCC9CD57042B3FULL, 0xECB62B1D23FDFF31ULL, 
            0x569BCA192D1E07C7ULL, 0xEE50E68212C11506ULL, 0xB91E931AD7FE4308ULL, 0x05ACFE38A59B5578ULL
        },
        {
            0xDB91C120DB78DCB7ULL, 0x85799D121FBD2CF1ULL, 0xBD95BCBEFAE76E93ULL, 0x70E76AD236CA8F26ULL, 
            0xD194515C282C8E07ULL, 0xFA850967018DD81DULL, 0x651749636A5B4C07ULL, 0x386994D157A75A77ULL, 
            0x515B82109AB09E24ULL, 0x90D37387265F3B13ULL, 0x537A692D06657F03ULL, 0x7635DEB1B989DB1FULL, 
            0xD663F2FBCF9172E1ULL, 0x2C798D3F8974F312ULL, 0x91F55BA39173DF40ULL, 0xCCF5B76BFCEBD378ULL, 
            0xEE68D9F71F3A0636ULL, 0xF450F2A5A3C7F6DAULL, 0x27EE283C3230E1C7ULL, 0x76F1E6E160A6C3D0ULL, 
            0xD5DF7D78A1CF8E53ULL, 0x41BC69006482647EULL, 0x742E7BE880A7922CULL, 0xC24CC3B87B3A0DC1ULL, 
            0x85AAE5F2891E8807ULL, 0x090152E8707E32A2ULL, 0x97A41E26D50570F7ULL, 0x9D014BC49A3491A3ULL, 
            0x6EB1C65516FD556CULL, 0x01F661FA80AB4188ULL, 0x7E79C8317B9D186FULL, 0xBC12DEF5C65DFE40ULL
        },
        {
            0x60256128D9FA0274ULL, 0x4997EF5AB63C5268ULL, 0xAEA5C22894843998ULL, 0xCAB4C754845C1D22ULL, 
            0x4FF257B6DB1C7F42ULL, 0x925B3ED42FF0C9E8ULL, 0xC650298E1E8CD73CULL, 0xE98AFEEF5E6D7DB4ULL, 
            0xD421CC80E812FB3AULL, 0x5D7467219A450B70ULL, 0x393ABDB64C3F3C1AULL, 0x60E07DECA00B0914ULL, 
            0xF744BB810B5AE054ULL, 0x81568A207E5F36DEULL, 0xCCBA01993FC02E21ULL, 0x373AB2BF51121FF4ULL, 
            0xCA506B76D15F969CULL, 0x699E7FC68FA65721ULL, 0x08901EA3357AABA3ULL, 0x4B76314F799085F9ULL, 
            0x6734DC455E513570ULL, 0x6E02C9AE976B0571ULL, 0xA206CF5519C77856ULL, 0x17247A53778569C3ULL, 
            0xB4312B19E2CC46AAULL, 0xCE0BD345B74A8222ULL, 0x1BE8670E25A7C1FFULL, 0x8267FA64FDB28283ULL, 
            0x001E9CB3F7D9A763ULL, 0xC665DA76DB349F46ULL, 0x03C79B1C0EBEC326ULL, 0x9FFE218D8C2C9C6FULL
        },
        {
            0x07F1EC525ED1B5EAULL, 0xAA286EE70101EBC5ULL, 0x015FF29CD4F07007ULL, 0x84F904603030A546ULL, 
            0x2865FE945E1F4C72ULL, 0x53920633B8CD5B67ULL, 0x49A8BBCDCFDD60B4ULL, 0xB0FB3F6B10C5A303ULL, 
            0x599B8CB6A06DABE0ULL, 0xBA97EE23E2C5539FULL, 0xDBB5D07349B1D333ULL, 0xB60918044CEE8D59ULL, 
            0xE3E93F6B173C63AAULL, 0x1DBA24940EA0B476ULL, 0x54BAEA745237E7F7ULL, 0x9EB1E87F25492AACULL, 
            0x9A277C690C70D827ULL, 0x3A7DC0DFCADEC318ULL, 0xB690A70F3B75D8C4ULL, 0xB645CC5440C5B0A9ULL, 
            0x66A2E4628778F68DULL, 0x5BA31318E17C6C49ULL, 0x8218AB3889A863ACULL, 0x6BE7BFFEAE5CC111ULL, 
            0x34CCD27D1EA4BFFCULL, 0xD531E5B7E0C24A98ULL, 0x81F896B6AF35CA28ULL, 0x5B0BFED18E02718CULL, 
            0x54B0F5F51A41EAA4ULL, 0x4644C8F15618BBBBULL, 0x4C3C51235D084EC8ULL, 0x14610B0304352755ULL
        }
    },
    {
        {
            0x6D23CAF1BD28347EULL, 0x826007251442E003ULL, 0x061F9A7EFEAAC156ULL, 0xBAEC757D10F26459ULL, 
            0xD78375B94578AC9FULL, 0x71609719E87FAB7FULL, 0x8C071D6AF56CAB53ULL, 0x287218784B275035ULL, 
            0xA283B833B9022361ULL, 0x5CC957AA447DAEB3ULL, 0x97FDE9C4070A81CBULL, 0x45A1ABF7ED4F740FULL, 
            0x394020C514D5C6A5ULL, 0x44E80C66365D9AAFULL, 0xBB9E4DDB63A2076FULL, 0xA99E9A1E6B29D5AEULL, 
            0x8B488EB6F50782C3ULL, 0x78184C695AA98483ULL, 0x31544B0A2736B965ULL, 0x3461D7ABAFDD4BC6ULL, 
            0x235E70601A6D5AA3ULL, 0x19DFE90E7F63E318ULL, 0xDCC3ED204B35ACA9ULL, 0xDCF60CF6AA19B46CULL, 
            0x652A1BF49BD1B5D9ULL, 0x9FA077F41490A39BULL, 0x57EF90D85F01A38FULL, 0x24AFF069546F7BE5ULL, 
            0x9F55D7D4498F8456ULL, 0x11226A54BF20CA5CULL, 0x5A4E54A1A611FC4DULL, 0x6A2189BE75F1CF12ULL
        },
        {
            0xDC51CE780DFD5073ULL, 0x491E21BD55E81934ULL, 0x16F6638ED54B6902ULL, 0x0903B81E7F35CC48ULL, 
            0x8F01F50C572F18C4ULL, 0x24B9A83E66231D29ULL, 0x6796822E814E995CULL, 0x5C2FB08BCA6E3251ULL, 
            0x471B19AD4F868413ULL, 0xCA546874BA7FB126ULL, 0x273DDCA40ACF3159ULL, 0x668CBCE84437D125ULL, 
            0x769CA92389E00B95ULL, 0x15D6AF5D1F1EBA99ULL, 0xD00C53010452B4CFULL, 0x048358C87C3AFA97ULL, 
            0x71FC56D362AD453CULL, 0x647AA142AF09E952ULL, 0x7FD18F90753B76CCULL, 0x664E7ECD329521D0ULL, 
            0x1F310A51BFF6472FULL, 0x90CBD33837A9F5B1ULL, 0xCD23143E11E66C78ULL, 0xD54BB376DEA98D1EULL, 
            0xB761EEE02CC53FF0ULL, 0x95D688717D514D3FULL, 0x32E2A09BAC7A6B53ULL, 0xBB4C32873923EA74ULL, 
            0xFD403B5239945EC6ULL, 0xE2AAFBF98EA5C398ULL, 0x52E1EA25C82E88F4ULL, 0x94B51D3364D6459BULL
        },
        {
            0x3DCCF5C9EF7DCF36ULL, 0x179DFB86ABF562A4ULL, 0xC067E0323ECA1DB6ULL, 0x6A9C63C17A4C7AC1ULL, 
            0xF463940DAFCA3285ULL, 0xE8516C7AA3EA5E1AULL, 0xEB9BBA74D2095981ULL, 0x5B27204AF524ACF9ULL, 
            0xC88FA0578359B644ULL, 0x04C616553F7589B8ULL, 0x809C67B4C9131EAAULL, 0x9C3866B2093E2186ULL, 
            0x3DC64C3797534315ULL, 0xC911857ECCA467D3ULL, 0x7B49E45CEAD02C4FULL, 0x5130BEDFE2559714ULL, 
            0xD2E75ED325DC1C8EULL, 0x632BBA7FED254B00ULL, 0xF75C720A1ADC383EULL, 0x5270C14E18AC71EFULL, 
            0x9030AFD95E9DB25AULL, 0x1C5F268DC55E7BF9ULL, 0x7BA54D412E0F61A9ULL, 0x28704C15DA6EAA27ULL, 
            0x32F865D930CB6F33ULL, 0x452A46E69980EEF9ULL, 0x685ED32C25C0B9E1ULL, 0x38C7EBBC7BA04ADEULL, 
            0xF2C3442A02B3D269ULL, 0x8C503662479D1AA5ULL, 0xB0AB24BFB9AC48EAULL, 0x64853D7CFB11F56FULL
        },
        {
            0x54DBC43231265D27ULL, 0xFDEB675F3B98130DULL, 0x275A4CCE3D0333EDULL, 0x76E108C2BAD5A525ULL, 
            0x7F755442EB448E52ULL, 0x03A7125B52902F98ULL, 0x38352DEC420F196BULL, 0xD2491AECA666022EULL, 
            0x9FF1D0346BA6C1D9ULL, 0xEC8E1CED70649FBAULL, 0xCE295571F11F743AULL, 0xF5D973A0260AED27ULL, 
            0x16AA26AA250120EEULL, 0x3159C26C299F08ACULL, 0x022F708ACCD104E7ULL, 0xA5BF66A5A64D0EB2ULL, 
            0x7690838293BA869DULL, 0x8D3ED911C5259231ULL, 0x2A814B2859DCE8DCULL, 0x6FB08D323100E4B8ULL, 
            0x1DB7C11DC1117BA4ULL, 0x5F82F9E84B863F50ULL, 0x0A8D0ADB41B39DAEULL, 0xC24DFF9BD4441B49ULL, 
            0xF07E360040176AB1ULL, 0xEFAD3B1FB8AFD476ULL, 0x0291AF78ED2152C6ULL, 0x188EB98F3153FD0FULL, 
            0x1BBF7123093FAA1EULL, 0xCAE58DD7A45AB9CAULL, 0xF586F2963AC5A802ULL, 0xB117F1FA73B4F8D1ULL
        },
        {
            0xBB89329A311A5BA4ULL, 0x8F6070AF5FD5CA3AULL, 0x72221D00E553665EULL, 0x7D8B9078147009E0ULL, 
            0xF4D73CCF027088F2ULL, 0x4BF0B6DDB5045FFDULL, 0x3AD8710391BF62C1ULL, 0x3AB3CB8E2CA5D554ULL, 
            0xFD3BA56007136A85ULL, 0x1922B1EEDD85FD49ULL, 0x144E4EC915E69E16ULL, 0xA69657DEB2DFB151ULL, 
            0x0FBDFCBE93DE1E06ULL, 0xA996A52296AB84FCULL, 0xF9D289F89E14FDD8ULL, 0x180C4C01250A5444ULL, 
            0xABE529702D8C9511ULL, 0x35610A1AEA73B84CULL, 0xFD935E0B04078E72ULL, 0x8E90F4F3442A05B9ULL, 
            0x3B17A10ADC41B3A5ULL, 0x754DC8A139F54C2DULL, 0x77CCFEE278FB394BULL, 0x2184B9F1571AE269ULL, 
            0x7F8A6104F444E6BEULL, 0x02141D92BCE0CAB4ULL, 0x07EE50472710BE37ULL, 0x80C6EBA66E25EA42ULL, 
            0xCF57145323074E5DULL, 0x65DC8907931E20FDULL, 0xF2001391AEAD92C3ULL, 0xCF03EBA9DD6ADB8EULL
        },
        {
            0x4DE50A0651A05404ULL, 0x35C5552CEB7D6C0FULL, 0x022548975ACE2895ULL, 0x245FAB1607BE8548ULL, 
            0x84125EFCA7012877ULL, 0x6E3FE2C4058130A9ULL, 0xB0983B3D6C9A1E3DULL, 0x45E43DBEFD1838FFULL, 
            0x08F990AFEB33090FULL, 0xC37D70B5A6D733FCULL, 0x94330A899672B71DULL, 0x48FF4939122E549FULL, 
            0xAD42624AD46380FBULL, 0x21EB48287F449894ULL, 0x52D0E188BF95B43DULL, 0x0D9AE11FA498926AULL, 
            0xEA9463CBB0EFDB02ULL, 0x5603DE42E0F907FEULL, 0x76A217859232F8A9ULL, 0x1942BB5D16193C46ULL, 
            0x1ACF5C7BFC4E99E7ULL, 0x99F1A9800850BB60ULL, 0xBC4D80277DFD2852ULL, 0x99C52E245DF5CE6AULL, 
            0xE298F100D59AD5D5ULL, 0x5BD6E56191BC34DCULL, 0x1B295E495E51A068ULL, 0x22F38409C71BD50EULL, 
            0x9C5768AC0310D259ULL, 0x09A04763DB7C493DULL, 0xB3E3D8C9AAE398CEULL, 0xC6A1E77F3CCDEEB2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseAConstants = {
    0x5C55508D7C38910DULL,
    0xDE0A2A1C0349B85CULL,
    0x2CB3FB47662DECADULL,
    0x5C55508D7C38910DULL,
    0xDE0A2A1C0349B85CULL,
    0x2CB3FB47662DECADULL,
    0xB0A20A1AEB13F84EULL,
    0xB14DFADA579D6DD8ULL,
    0x1C,
    0xD7,
    0x01,
    0xF9,
    0x4C,
    0x87,
    0xB7,
    0xC4
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseBSalts = {
    {
        {
            0xE7230C092B3B3C0AULL, 0x111C9C8FD16D2511ULL, 0x7216E4C61B053004ULL, 0xDDC6A8C7FD0B7A11ULL, 
            0x62F23701647DF5D7ULL, 0x73B8FFD1331593EBULL, 0xF1E9B0D5D0F65E0AULL, 0xCB6A78CC8E9EA238ULL, 
            0xE04428A2D2F4CA6FULL, 0x65E882DABDC109B0ULL, 0x2C5513B89F65790BULL, 0x1A07E78DFF17C83DULL, 
            0x10AD723231643B3EULL, 0x0D048041B5E60A68ULL, 0x3BA91FD04EDB3100ULL, 0xF604D60762197AD1ULL, 
            0x5CE59016BF6DB20AULL, 0xFB3C9C20BDD44F5FULL, 0xF7CECDAAC58B3E17ULL, 0x1BD2B09FA78750C7ULL, 
            0x56CC947CEBD98F29ULL, 0xEB7D9BAFCF21D888ULL, 0x93469E3E50BCA3FEULL, 0xB97F6FD818C7C120ULL, 
            0xC8BBDF33581ADF3BULL, 0x3677716A50836443ULL, 0x7E81E4B7A86F9C0AULL, 0x892531B8A0BAD383ULL, 
            0x05B3A86682D840D2ULL, 0x53400E1E098F785DULL, 0x3130EA0C0A91C59BULL, 0xC152BC4C3DD5D80CULL
        },
        {
            0xD7CAA252D1C60E57ULL, 0x2CF52D367CA1813CULL, 0xA2E6C4D29A3E8E7AULL, 0xA629E59784BF4248ULL, 
            0x0D45EFE20AAA055EULL, 0x6B67A0BC666D325DULL, 0x82AA7D8E4779A1BDULL, 0x2F8895170E2779C4ULL, 
            0x4DED718F163C3FB5ULL, 0xD4A212D478B1DFCCULL, 0x9C8365582FF182D0ULL, 0xDF9A8454EC78E145ULL, 
            0xCD6740EC24332BE0ULL, 0x363CA728C0AB32F7ULL, 0x60722FBDC7DA4FEBULL, 0x14CC974A8F0CEE88ULL, 
            0x94B151AEE60D25B8ULL, 0xE478EF1697587FEDULL, 0xC9EDA9F79F87FE61ULL, 0xBD91614AF358B344ULL, 
            0xD1F940C564F3B8BFULL, 0x2DBE4389962D9483ULL, 0x485AEFE1A9060EC2ULL, 0x50F107FFD5FD05D7ULL, 
            0xB6B9280A0D1C4C60ULL, 0x5D6A702D2EDDD2E3ULL, 0x94A2C9A130655DC7ULL, 0xB784D390174C2F1EULL, 
            0x6B832C8973E1A20DULL, 0xB4AC0FB2660D959BULL, 0x5F3E2C3DBC108036ULL, 0x78C1CADA08A73FFBULL
        },
        {
            0x643B78C828724F76ULL, 0x02C417E3CB35420CULL, 0x4A28D0AAE4700B57ULL, 0x5BE3787E2781DE06ULL, 
            0x5795A3237D97E915ULL, 0x3EC975A93A54BA1BULL, 0x20514A8D53D3D74FULL, 0x75AA90E5B39E277AULL, 
            0x9FF3352317608DB2ULL, 0x9D536EAEDF1FF12EULL, 0xFD02308D240A062CULL, 0x6FE93D8005AB1D1DULL, 
            0xDC87F3BCB969B27CULL, 0x33CD62A952D7B245ULL, 0x17A73BAA9336C5F2ULL, 0xE8992FA01CC2E146ULL, 
            0x17A28A83C5ABEA20ULL, 0x01B9FA0052A5193AULL, 0xA624BC3B30DF73F2ULL, 0xD0A4758B60103EA0ULL, 
            0x8C8127462F009383ULL, 0x530FDA4F7E9EF011ULL, 0x5754ECDBFD4D46EBULL, 0xDBAAA1DF10C14C39ULL, 
            0x6FCD584192C43BF1ULL, 0xFF9C37F341319413ULL, 0xBD08D89DCBB885E4ULL, 0x5DF476652ACC2324ULL, 
            0xFF831B287CA17541ULL, 0xC870152621B84E2DULL, 0x96A7397EBD15030EULL, 0xDD3DD04CB36FEC28ULL
        },
        {
            0x976AE444C7B5A4F7ULL, 0x103F0EBB7829A830ULL, 0xB62DA937E07CD707ULL, 0x8A5FDB17E9D93CD7ULL, 
            0xB36E1E6C74A0015AULL, 0xCBD6B23380032F85ULL, 0x915636AB7EB0BE30ULL, 0x6ADD513C97DF1FF4ULL, 
            0x57D6EC35E7233213ULL, 0x854AE6D2509707A7ULL, 0xCF29EC7DD6B6707FULL, 0x56DD5616C20E732BULL, 
            0xDC698B7AEF441FF8ULL, 0x2C865053444E152BULL, 0x3F7A69384F1D3EC4ULL, 0xF05D7868ACA57CD1ULL, 
            0xD54FC459732CADE6ULL, 0xF29CCD0664525B85ULL, 0x079B7C11C5BC13CCULL, 0xE0C061FCBC84DF85ULL, 
            0x9545766F23E2CCF2ULL, 0x8171FB92E88C9828ULL, 0xD2E6DD97444620EAULL, 0xD62F6AC1AD81CECCULL, 
            0xB7471DB8F9EA3943ULL, 0x4546E4DA39038D24ULL, 0xA488190D86766957ULL, 0x5F43EE3004034851ULL, 
            0xF33F8E6A6BC1853BULL, 0xA74B356B18F6F30AULL, 0xB88C8D0AA9EDE6C4ULL, 0x3104FA6B07F05A87ULL
        },
        {
            0xE97515D94D199518ULL, 0x4A4BD49C633726AFULL, 0x73E526E26C956999ULL, 0x0459ADC995297F5AULL, 
            0xD17753214D4C74C1ULL, 0xADE7EF6E1E6518C6ULL, 0x0276578E8B15C9ABULL, 0x3AFFDF1AF4E41A20ULL, 
            0xEDC927A16146DBFCULL, 0x26215FB0F014CAA8ULL, 0x3D67834694825C0BULL, 0xC3C531AA4903D917ULL, 
            0xCA7EBB140E19034CULL, 0x2AE41898C7BBE0F0ULL, 0x362EE4187D04EAF8ULL, 0x21DBF204E5D2C458ULL, 
            0xE391C358619EC314ULL, 0x44AD9EE864BA8AB2ULL, 0xD341D54DA506DA90ULL, 0xF08DB87864F9F334ULL, 
            0xD32733AD228BC84FULL, 0x625E866F09641272ULL, 0xD263EF11E5656C44ULL, 0xAA089E04165C4F5CULL, 
            0xA39B2448CE1730F4ULL, 0xD0A07F527CBBFAC4ULL, 0xD4D7DDBCA302BB76ULL, 0x64D375CF8AE10CBEULL, 
            0x176F2F5EA6ABB940ULL, 0x15ECA0F68A8991D3ULL, 0x1B52CC71BFB36109ULL, 0xAD8E70852CF6588CULL
        },
        {
            0xD2DD83B05C2BBA45ULL, 0x128AE6CEBAF885EEULL, 0xEAF242495582A600ULL, 0x45EEF400B2C1425BULL, 
            0x3AB6DA2E39991AB8ULL, 0x44EE0ED8C14009C2ULL, 0xFC1435EEECD099E3ULL, 0x4047542E5D889E2BULL, 
            0x8210DE408E3627DCULL, 0x164A11C781E2E3D1ULL, 0x3799BA45505543E2ULL, 0xA39FC2D66B545A9AULL, 
            0xFE84FD0270AF55F9ULL, 0x2289714931054975ULL, 0x1BD853F7A1C69628ULL, 0x82ADCB39C35E3D9CULL, 
            0xC12D2BD1B8B260F0ULL, 0xFD752670174B28E4ULL, 0x6E0E6AB6CE69D9D6ULL, 0xDEF88D16726BFA86ULL, 
            0x547ABD6FF9E090A2ULL, 0xCEECAEC499B4DAD6ULL, 0x8AA32AD357004E27ULL, 0x6F03489C869D9E10ULL, 
            0xD6F539DB90C1FF0CULL, 0xC8CE3C27B720B3FEULL, 0x27E71B39F900B58AULL, 0x38F8DB12FCCC786AULL, 
            0xA8DE45B65D418D5CULL, 0x7E91DD378962D7C2ULL, 0xE4CAE8FFC3412E40ULL, 0x269CC3E05BB98440ULL
        }
    },
    {
        {
            0x3B4AE3826D895E2BULL, 0x57E141A03099762BULL, 0x6987CD709681B7E8ULL, 0x76E99A233B3C1180ULL, 
            0x9BD935BCF6D97D04ULL, 0xC4CE7DD153D6ACFDULL, 0x50D845EFF8B7D5CAULL, 0xD298071402A8EC05ULL, 
            0xC58E8952398FBEB7ULL, 0x038E95A761382AD9ULL, 0x2D228C3EE2FF4901ULL, 0x1216CAAE0D8AEED1ULL, 
            0x80421E5E4DA0B7C8ULL, 0x2F4D374760244D13ULL, 0xBD9EE4999B1E9F3DULL, 0xE1307B2C963846D6ULL, 
            0x96C6040C039F79E9ULL, 0xDC20FD1ED0D21DB3ULL, 0xC9161B9340430C5BULL, 0xB91ECA1323D60A2EULL, 
            0x3075A110B5F29915ULL, 0x412D7B4C51CF535EULL, 0xBCBB6957477D4B3DULL, 0x9FD4FFFA0A8FCA7BULL, 
            0x332EDE341E1BD301ULL, 0xA545EE5144A3874CULL, 0x12907D1C02345A49ULL, 0x4AF767A7758EA9B4ULL, 
            0xBF8B198601F103E8ULL, 0xDE8B7B67E3D0BF7EULL, 0x64AEC90BFA37009FULL, 0xBE422D4AB5432E97ULL
        },
        {
            0x312F8AB0B72A043AULL, 0x737B215CEA96D66BULL, 0x838655875C961643ULL, 0x7745DA71CDE3C182ULL, 
            0x1481A6188B57AB1AULL, 0xDDD5357A760AD741ULL, 0xCF105D0EBDD24285ULL, 0x33160C6264A21ABCULL, 
            0x03A6FA58C3A7A7CBULL, 0x61D6F2F3E18825A1ULL, 0x94D6C6DB65EE638EULL, 0x3A1B89A5D864B264ULL, 
            0x74F6CA277E36DC5EULL, 0x4F62D660500358B2ULL, 0xB85F14268E5078B7ULL, 0x96FBC198B9C999D8ULL, 
            0x698847086D4F19F1ULL, 0x6FB2599122FB3607ULL, 0xB5FCEB540D2DC31BULL, 0x5E283AAF1B78F6C3ULL, 
            0x63B997E8A208A8EFULL, 0x7D84D207E8E9ACFCULL, 0x758910D8FDF921F9ULL, 0x2C3F4B9C19BA345BULL, 
            0x1CD82DF142DF3402ULL, 0x665263AE95666D19ULL, 0xEE3D28EF12346EB5ULL, 0x7224333466D80547ULL, 
            0x73A755B1D670FB95ULL, 0x8957DEAB6465EFE3ULL, 0xB9FBB6BCE1F10753ULL, 0x774BF360F0B2A5F2ULL
        },
        {
            0x6CE39889A08BFD45ULL, 0xB9A0CC7B0962E974ULL, 0x7CD3F773BB8D3FE7ULL, 0xD478017F63629EBEULL, 
            0xC4609EF2305180BBULL, 0xAE4B485E32E83529ULL, 0x1EAABEBB41BC7032ULL, 0x3D7DAF419FDDCB63ULL, 
            0x81697E8D8D69ED77ULL, 0x7707F17567A168B2ULL, 0xB91B5014D18D93CBULL, 0x6A01747FCA23AF0EULL, 
            0x85CFBEF8252D2CC0ULL, 0x7D1F554D183117D2ULL, 0xFFC3283464297AC4ULL, 0x5912B71EF640DCBAULL, 
            0x0A164590066D2856ULL, 0x8C74E3A0612F8BD0ULL, 0xDBED38E2B2B21645ULL, 0xB1AEAE9312B1BE2CULL, 
            0xD37B6A0BDDDCEFB1ULL, 0x135FCE8401D3E8BDULL, 0x1F2B7A184A1923FAULL, 0x697E70FEF5C64E29ULL, 
            0x826D30D3A27E55A4ULL, 0x3045EC1273A8813CULL, 0xF297D2C6D3E427CBULL, 0x469A6233DEBD7759ULL, 
            0x9CAFD2BC24FEAA3AULL, 0x46256E60897CB1B4ULL, 0xA79E7ECFFE17B90DULL, 0x0419F86D1B81BA8BULL
        },
        {
            0x4E2C1428A48D452DULL, 0xDB922BBE680E0111ULL, 0x3161E813E63E73D1ULL, 0x2C3DAD0D003C793AULL, 
            0x8634717A003EE4ADULL, 0x8C3837D0117EE5F7ULL, 0x16B1936EDC7966CEULL, 0x74BF290F655C03BEULL, 
            0xB38032A83BDD1B19ULL, 0x76CE71082AE97759ULL, 0x6C839062549C6FA5ULL, 0x3FDAB9ED94DE1EDCULL, 
            0xFB24B04413C33AFDULL, 0x32EB707FF920F3D6ULL, 0x5DF199A9982507CFULL, 0x325BFD217B9EC3AEULL, 
            0x4995BA30D21666D5ULL, 0xD6CF750CDD00C487ULL, 0x9FAC8BB056F8E0B4ULL, 0x14353A1D9FEF4C09ULL, 
            0x10AACDCB17BBE708ULL, 0x3287A3BCAF2AE10CULL, 0x10724A1C7F59EB15ULL, 0x91DD1F02228ED2C5ULL, 
            0x9D83BBA55A391266ULL, 0xE994EAD9AA2C15EEULL, 0x05BE252611FAE1F0ULL, 0xEE070BED13E54A10ULL, 
            0xB72DB76F5462C690ULL, 0xCBEEC0D33E15924AULL, 0xC0E6F32E2334692CULL, 0x93515E7DAC59430DULL
        },
        {
            0x93F09563FDDF14ECULL, 0xF1F40F7D2E171B8DULL, 0x9201BC6F9BA2318AULL, 0xAE8DB423AEE82836ULL, 
            0x75D7898BD025BF26ULL, 0x5DE8747173BCC811ULL, 0x4AB658E7E52812C8ULL, 0x76F10F54D4056E41ULL, 
            0xC0C5A9FB164E0B33ULL, 0xB9FC238DD1F56B96ULL, 0x79CB1A03869E2111ULL, 0xED10E5756271C737ULL, 
            0xB970B3C48E4F2A92ULL, 0x5EDB3BF68ABB8DCDULL, 0xF1906A0EC542D989ULL, 0x565FFD00ECF3E2BCULL, 
            0x653A2C584C2DA367ULL, 0xEAB54B2AC31B0096ULL, 0x156E74E0007A60D5ULL, 0x0732E20256F04636ULL, 
            0xFB3C96B35BA647BBULL, 0xE0A0881E75BAB56BULL, 0x839FBB8D1003D669ULL, 0x3EFA1B8BFD909942ULL, 
            0xB31B369E889CEACCULL, 0xC835B945E561D52FULL, 0xE01D3A6C475A41AEULL, 0x63CA74F72B81B5D2ULL, 
            0x6868FE293610199EULL, 0x532D8CD84231A954ULL, 0x3B1B74A779B2FABBULL, 0xAD533C16CCD6BC02ULL
        },
        {
            0xA3C8264180353A4AULL, 0x9BEB08FFEBF83E1AULL, 0xD8C33789949CD04AULL, 0x8A95A8A0D19648FCULL, 
            0x979DAFA7FDC00E68ULL, 0xF3AC42042EA8585BULL, 0x7E791777EAE8E691ULL, 0x5841C757342ACBF6ULL, 
            0xEC7DAE7DA1B82246ULL, 0x8ED0A189AD9BC20FULL, 0xDEF0919F9B14869EULL, 0xDEF97FC1D34DDBF1ULL, 
            0x4453023A3149B613ULL, 0x8391CB113EB70940ULL, 0x5E28939FDE325856ULL, 0xCAA0CB16087FC81AULL, 
            0xA650DF468D1DA36AULL, 0x8F3C021A78770362ULL, 0xF25F80DC25263D96ULL, 0xF93809DE5769C079ULL, 
            0xDDDFBE6CDCE99F23ULL, 0x47457DD030839343ULL, 0xFA9DEAD457451601ULL, 0xBD206DD4DDF463F3ULL, 
            0x64998EBBE5559171ULL, 0x79C0FDAF9E504810ULL, 0xD4609EA805DDBA67ULL, 0x81DA1789B008B29BULL, 
            0x23F5C726DA77EB6BULL, 0xB6724C1B3E926696ULL, 0x7178733D7B5E3E02ULL, 0x4E6D659046A4399FULL
        }
    },
    {
        {
            0xD6F3EDD1950D7903ULL, 0xDEB5EC092C1CCC19ULL, 0x0BD3E54BD744DDB5ULL, 0xC3CD54555EBDF293ULL, 
            0x7FDD983123472FB3ULL, 0x062C44801C557ABFULL, 0x70E6D561CEBD193FULL, 0x592A64256AFDE01BULL, 
            0xF8D1AFABCF99A08BULL, 0xE0D8E19E4BEBB46AULL, 0x55B25CDDDCABF4A0ULL, 0xE6DBB012005A89A7ULL, 
            0x3B53BA39C4E6298EULL, 0x3C0CD263159D9CBFULL, 0x848126316E2AF0E2ULL, 0x25A764989F9A76E4ULL, 
            0x6D5A0988B7606F9CULL, 0x8B7FA21255A94F0BULL, 0x1543CAAE33D30331ULL, 0xEBCBEF140A422175ULL, 
            0xBD25948321F5D927ULL, 0x4324A6A164EF8479ULL, 0x5BE79B805D5A301DULL, 0xB3E534D6D21389DDULL, 
            0xD7DF9836EF55A294ULL, 0x6C396CE5A87E6BF0ULL, 0x9685223287C0793FULL, 0x118BA62D29198A13ULL, 
            0xC83C2D2D0D1E818FULL, 0x37667E058E1A71B0ULL, 0x23B6BCAAC89C4F45ULL, 0xCA494342C823A805ULL
        },
        {
            0xD666A7C9180743C8ULL, 0x6A7D60CD6F351290ULL, 0x70745A1BC042E4C6ULL, 0x385926FB11F0DF67ULL, 
            0x6710138CF450B875ULL, 0x45D3A54E2E025D95ULL, 0x79375907491DC647ULL, 0xCA50FC79EB5FBBADULL, 
            0xFC462D0ADCAB2C32ULL, 0x92328721C2CAF316ULL, 0xD09B208BF6188494ULL, 0x724BF6E31B997209ULL, 
            0xEA8F9C31AA5DD802ULL, 0xC62DC09FB4ED47C0ULL, 0xDD3484F168D2F915ULL, 0x3F315DEF358968A6ULL, 
            0x40B668990394D6C2ULL, 0x5CF1BF235DA8C2AAULL, 0xD8567EB36283D68DULL, 0xD172D33EDCAB33A6ULL, 
            0x1364D867463E38B3ULL, 0xAC7AFBE2D184B480ULL, 0xC7A14E24E161CB99ULL, 0x8C4C93C9ACDECA98ULL, 
            0x19C32E01BE302084ULL, 0x491F3372F5FA349EULL, 0x749A203CA1BC2F4FULL, 0x0C8A56205F456DA5ULL, 
            0x796B5BA2009340B1ULL, 0x827E4A622BF67DB0ULL, 0x7D27CFAA39DED2FCULL, 0x9EA14F6A80ECDFEDULL
        },
        {
            0x0F965ABEACB7E8AAULL, 0xF8AF4FA5DF7E187CULL, 0x408BA573FE334CDDULL, 0x02F20AB68B47404DULL, 
            0x79B97B59D4864D7DULL, 0x2D443924599310A0ULL, 0xE808F17F998A6495ULL, 0x9F15064944609C27ULL, 
            0x880EED553F43E8D8ULL, 0xA5740D76AE6CB8C6ULL, 0x612434F3F8AF13BFULL, 0xFC39C28EA23B93CEULL, 
            0x97B48206CCED5A00ULL, 0xC2B5786439AB8295ULL, 0x582DC8ED4E6B3784ULL, 0x4ED53E7C3A22DBE3ULL, 
            0xF633E1EB041A2F00ULL, 0xB00ECCBB92CBEC59ULL, 0xAE1B321E1ED0DC2CULL, 0xCDDC195CE2EC8BEDULL, 
            0x2EA616337F34E03DULL, 0xBE5A5CE5AB29BC50ULL, 0x911592AE02C71109ULL, 0x5E4E70DC03ABE7A3ULL, 
            0x16D8649989D6ED18ULL, 0x2E56C637814C53B7ULL, 0x7B72B518E59603E8ULL, 0x3CA57197301A8D2CULL, 
            0x74EE5DB242BF5BC1ULL, 0x8C4DF9C8E8848313ULL, 0xB998500C5B3FF8FEULL, 0x778E97DDB956A125ULL
        },
        {
            0x7FDD10EC1F2974F5ULL, 0x9C98FD2FF7D97FCFULL, 0x31B6B10307DAC8CBULL, 0x5CC9A1499C2F515BULL, 
            0x4003BA44B898B2CEULL, 0x0595E4B0DE2C951AULL, 0x10250656CEF7890CULL, 0x735B2E0ECE0A36C1ULL, 
            0x30D73710589D3C54ULL, 0xDD984BF6395297C5ULL, 0x328EDBBA3291D400ULL, 0x832515C614DE624EULL, 
            0x56ADB0EA67929066ULL, 0x9E6DAF480C7C7E15ULL, 0x05CB2735A83D92FBULL, 0xB13AADB0700D5B9EULL, 
            0x4D5BC1D948FDBDEFULL, 0x9E3E2566BA9F4FFDULL, 0x4DBD18B16123CA1EULL, 0xC0000BD979594BE9ULL, 
            0xD256742BBF82FB6CULL, 0x4BBC26AC28E2356BULL, 0x24E56963E4F92D7EULL, 0xA5A7FC9A5C5EAF98ULL, 
            0x6ED0D5C1F9E2B159ULL, 0x8121E7EF80331A03ULL, 0xF91E2EB5D8562357ULL, 0x6EBD21D202030B3AULL, 
            0x2927D6E48E27E524ULL, 0x05BC5B4DA98F6D45ULL, 0xF7475D73B862E1B0ULL, 0x37446300A8D130AAULL
        },
        {
            0xEBFA0DCE1A0EF77FULL, 0x35D4E3503C396880ULL, 0x4ADB3942EED83207ULL, 0x973390A76C3145ADULL, 
            0x3DC5BB17D9CC515BULL, 0x2E18360ADA29272CULL, 0x4463BABB795D5B1DULL, 0x7BDBBA6F8084BB8CULL, 
            0xFE79E92C6B765BDBULL, 0x4E51C7E6CA9D7908ULL, 0x72AE7B7B8701ADD6ULL, 0x97DCC65616B0C8D2ULL, 
            0xBE0959DE2EE7A4CCULL, 0x7D075AF24C42505DULL, 0x1FBAC794D43E7162ULL, 0x8DABAB285A423F65ULL, 
            0x37B6F30DACD5EB40ULL, 0x6B8AB5C60563D355ULL, 0x583452EA7CE9D547ULL, 0x63B2FE61227DAC8BULL, 
            0xA81D2F4548F9CB0DULL, 0x7B22F8FA88693FCAULL, 0xA53B4CF9D5C06D48ULL, 0x38331F4F64BCA79FULL, 
            0xB4F9CC70B1633F5EULL, 0x4975568EC455BECCULL, 0x672A5789C00ADA1DULL, 0x5D767E7EE39332D7ULL, 
            0xEEDE17C456CEEEE5ULL, 0xCBC3C638F13C3F12ULL, 0xA255BF55BE6D16F7ULL, 0x9D101B690F6649FBULL
        },
        {
            0xD1185D684473AE50ULL, 0xF9F4DD20D9A73208ULL, 0xBD5401EA04CB6CC4ULL, 0x6012F5A1FC3BFE5BULL, 
            0xCA9B0227D30D0653ULL, 0xF4819F301A082CD2ULL, 0x4235C1A232823307ULL, 0xD960A7C8FCEAA3FEULL, 
            0xFB465DFC647A900FULL, 0xC7F8E01E30A5771EULL, 0x59910798EE003DE8ULL, 0x3318EA70F321C330ULL, 
            0x09E5A2A2FE8FEC2CULL, 0x2C49F2B20BFEC30BULL, 0x1B5BF2F9809A6051ULL, 0x1B0ECFB012BBE93EULL, 
            0x3D0528616CA53A4EULL, 0xDCC30697E8101B18ULL, 0x9BB92DA3BA2AE12AULL, 0xE52C53E62275C0B4ULL, 
            0x20B8051B82597235ULL, 0x1E7C34B0778164A9ULL, 0x3E9BEECDC5FAEF25ULL, 0x90012B988AE4CA28ULL, 
            0xD4449FB96C1E3182ULL, 0xFA4A18D1145188FAULL, 0x2EA3075B7977C8C4ULL, 0x8493929240E5456DULL, 
            0xC72E4967AEA5E5A2ULL, 0xFC3BB2C887B65246ULL, 0x5F1DD416A369A7A9ULL, 0x831A861EAC5D6F08ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseBConstants = {
    0x4D6A76A484AD7903ULL,
    0x38848520A9B3CA94ULL,
    0x6C8CD799B2A966B3ULL,
    0x4D6A76A484AD7903ULL,
    0x38848520A9B3CA94ULL,
    0x6C8CD799B2A966B3ULL,
    0xF29F8A1B8871D170ULL,
    0x2317AB49E38541D8ULL,
    0xC0,
    0x1D,
    0x7A,
    0xC0,
    0x7B,
    0x1F,
    0x68,
    0x84
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseCSalts = {
    {
        {
            0xCD6566B03AC67AB9ULL, 0x77E79504833B4AE0ULL, 0x0DB629822BC8547BULL, 0xDA0E68CC6C7575A0ULL, 
            0xCD1B822841AB725EULL, 0x2C7AA66E7E780ADEULL, 0xBE76AC243C95ECAAULL, 0x4E7519B773ECA720ULL, 
            0x91830CD31F2A95BCULL, 0x8C5A52CA1AF4BD2BULL, 0x5F7AE33B416710B6ULL, 0x175AFD17795D04FBULL, 
            0x57553E72F4029145ULL, 0xB925D20CDA10B4C2ULL, 0xCE0E19F605BEB9EDULL, 0xCCEB55282B3B8ED7ULL, 
            0x19CA1F1FC0A54E1EULL, 0xD45E43F78DD173E7ULL, 0x90F23816B3EEB0BEULL, 0x6B25E195E05392DFULL, 
            0xA5519979C1172E64ULL, 0x4EAA9447FEAA84D0ULL, 0xA201590F7F42E13BULL, 0xF88BE34D43236686ULL, 
            0xE2BD4B6075CC8452ULL, 0x43382C07C1B5F890ULL, 0x7D5DDD03B5602F53ULL, 0x9E2213DD5B7A121BULL, 
            0xAB968C5800883904ULL, 0xD85169B55EBE00B8ULL, 0x38EC457447354908ULL, 0xF46AC038C80DA3E2ULL
        },
        {
            0xC5C030D8D006F642ULL, 0xAC3626B1C4F39D79ULL, 0xB1B2B70E668B84AFULL, 0x035A3C812A0E8406ULL, 
            0x31E75D08BAA22B84ULL, 0x4511232A6B440DDDULL, 0xFD618C85270B5BC1ULL, 0x4ECDFAE323751928ULL, 
            0x1505A6051159FDA2ULL, 0x9DEB151B769C970FULL, 0xB2F2C4D97E1EB95BULL, 0xB53C9CCA8E3DE5D4ULL, 
            0x4938141C0AAF782FULL, 0x0A2726809E41DDFCULL, 0x63BE1FE059CF55FAULL, 0x80E625ED1473C6F4ULL, 
            0xA42544D80DD6969BULL, 0xD45CFC1A343F0A33ULL, 0x927A543DCA2DC10FULL, 0x4DB45077ECDA9DD6ULL, 
            0x48BA6426969A4003ULL, 0x371BFDEBF86153D7ULL, 0xCF13FA3F6063AF3DULL, 0x62829907E2944AAAULL, 
            0xC88D40A3B7CF4433ULL, 0xDF7BA6745720244AULL, 0x5F1CB8E119FD6699ULL, 0x63BFC333424862D9ULL, 
            0xFA0221D42D76522EULL, 0xFC35CBC18707CFF1ULL, 0xA9BB0851351D3764ULL, 0x848CE1D6CA44D677ULL
        },
        {
            0x7192F59688F6C9D2ULL, 0xF6BE87552EB5ADCBULL, 0x51875BB2DFF969AAULL, 0xDE364CA5619F66FDULL, 
            0xDC1C9EF61B096BDFULL, 0xC9D932AF92B05078ULL, 0x5DF78CBA67D6EA73ULL, 0x5CF9DF2A45E87DB9ULL, 
            0x8641E315A80D3A4BULL, 0x3C45A365AF5E8695ULL, 0xEE27B07E108F3AEEULL, 0x6D63BEECEBB82C2BULL, 
            0x0A42165C21B9FF99ULL, 0x90441353D189785EULL, 0x27635D8DB13EEA47ULL, 0x72CED9E2CEF5B5C9ULL, 
            0x26632E66695FF637ULL, 0xD7FB60F9C49C7896ULL, 0x314E6990E9ABA048ULL, 0xC52047CB7B7EBBA7ULL, 
            0xA488BF9BC161D1EDULL, 0x724F7A055409F02AULL, 0xCB02E569121ED8ACULL, 0x8497D5C7A7D58406ULL, 
            0x1B21C3C8847E1392ULL, 0x0C9985AA6C6C579CULL, 0x9D99109CC9B5A832ULL, 0x40FF2E1AEAEF6822ULL, 
            0x373F764356451925ULL, 0x24E37E74C58FF2C7ULL, 0x7249B71DE870E94BULL, 0x094CD28BD02D67E1ULL
        },
        {
            0xDA9037AD120FABA1ULL, 0x0500D15DC31D5CEDULL, 0x3DB8EAFF5A63D87BULL, 0xF83D85354967D843ULL, 
            0x34B0AE9DB8A5F7C9ULL, 0x1BFF56089A918C68ULL, 0x1F58908E4931DD5DULL, 0x5300C55DE0B55FE5ULL, 
            0x00F5E8ACFD0EBED1ULL, 0x46FA32262D1244CCULL, 0x1FF8DFC4079EA341ULL, 0xCD334A4990546595ULL, 
            0x4FC302B5C4238F87ULL, 0x29DBA979144D21BBULL, 0x3AF7C49ABD46B33FULL, 0x030EA11562D468EDULL, 
            0x684C33080943FF86ULL, 0x61C14679B5B72B99ULL, 0x6382535AE35841BCULL, 0x8F556D8E4010F83CULL, 
            0x97531A8C2B1A2056ULL, 0xBF77F429A98A932AULL, 0x9790D9A7FA1D85F9ULL, 0xF07E715DB14A083EULL, 
            0xEB68F034158BD97EULL, 0xCE5A73F1ED8CA025ULL, 0x892FCFAD199805C5ULL, 0xBCFA9E35C0EC747DULL, 
            0xE2FBE4BB70717B6FULL, 0xD80394F24C72BFF5ULL, 0xF64162678FE3E65DULL, 0x7F9D594E7529C1E6ULL
        },
        {
            0x9D7604EBA51380E4ULL, 0xB086B010F35B9DFAULL, 0x89315493F37FC2D1ULL, 0x45A89E271A8D2AA2ULL, 
            0x17B3F247187AC556ULL, 0xABFA37610E4E515EULL, 0x5E9E7785D1049EAAULL, 0x7390718A6BC3FC40ULL, 
            0x86BA0C58D78D1F5CULL, 0xC0B4519C92114690ULL, 0xFE88CE3F08F46CD2ULL, 0xFDCC6C01563423C9ULL, 
            0xC68D06CB8F8666D3ULL, 0x1D093649592EEF13ULL, 0xD3C1C97E669B882CULL, 0x6A29591ECC517468ULL, 
            0xDA7F6767E3AB4A9EULL, 0x8229E84FB4EF2791ULL, 0xE2A89AE07164C04BULL, 0xBD1AF4C5BDB5CE8FULL, 
            0x89ECC23F937DAF55ULL, 0xBA8CC96C5282A055ULL, 0x3CB24A0B527676DAULL, 0x72B878088E29D83EULL, 
            0x2E59B0A1E6A297BDULL, 0xAF45C6B3414F5787ULL, 0x36CFF9ED33BD7D07ULL, 0xF1D9A7DEF892B413ULL, 
            0xAECA78B8E7F8EDE3ULL, 0xBFA1B977D8E9014CULL, 0xE604B7A386369ECDULL, 0x6FD27AE5EEFAB318ULL
        },
        {
            0x46DFEAC83CD255A7ULL, 0x6A10281604419345ULL, 0xC1C4D1BB4BBB846FULL, 0x555D9A546BEF6D87ULL, 
            0x6D8B5BD2A5511CC5ULL, 0xB5FA577C4B4187B1ULL, 0x455B3929410475E4ULL, 0xDF0F2379489108EBULL, 
            0x605346B71FBFE7D8ULL, 0x80C8EE9BE2B13927ULL, 0xAC3F635B7EFF3DF5ULL, 0xA818F71EF6413CF5ULL, 
            0xC0F711321A659DFFULL, 0x133F2C734D029B0AULL, 0xF2FF1E4674F8D0B3ULL, 0xE08AFD452C3E8D0FULL, 
            0xDD9233E1F5EB5DC9ULL, 0x48E5FDF880AAC644ULL, 0x7791B414349E7263ULL, 0x858EFDF166B98365ULL, 
            0x4D9FCAEF1C6176C0ULL, 0x4B76F5B2BE335CDDULL, 0x93BCCC5F036B1079ULL, 0x9B39D135A5A885B4ULL, 
            0x6747346E06B1EAD9ULL, 0x07D725D2D1B7AA29ULL, 0x1189305AE84658D2ULL, 0xB4D065F2270BEBCFULL, 
            0x09FCEAA3AF2CA50DULL, 0x80348C4A6E253064ULL, 0xC7D2117B5BD232C4ULL, 0x13C95D8F1A92949EULL
        }
    },
    {
        {
            0x4E5515B48FE6F4BCULL, 0xC3A54053BA2DC228ULL, 0xDA24B761B478435BULL, 0xE0920912C76E3E75ULL, 
            0xF2B3FCA070EC5ABEULL, 0x4571D0B0A35E165AULL, 0x853F50B2711F2190ULL, 0x0F254DFB034555B1ULL, 
            0xF29BCFEE578E249AULL, 0x477AF27814350FFEULL, 0xE3A22A6743FDEFD1ULL, 0x939DCD7072384693ULL, 
            0xB52CBE2C954B13D5ULL, 0xB37B28FD4B7AB755ULL, 0x54005EFDEA38D5EAULL, 0x25F2A2B550C5E8C4ULL, 
            0xF18C9B5FBBAD4558ULL, 0x3B3FA478850E1235ULL, 0xA4781D39AA7126F1ULL, 0xDA548C5ED77E88A4ULL, 
            0xC2C8789A1369D71CULL, 0x1B406D8330514235ULL, 0x7B428EAB3E700517ULL, 0xC410D2AFB0E7EED6ULL, 
            0xA8FE864A5E9576EDULL, 0x42EE6FCF0F497D48ULL, 0x790C0C052041E27CULL, 0xD3FC2FF4CFDEBA48ULL, 
            0x6A2BFCBC4A593F88ULL, 0x98DD7220CD2D8E0DULL, 0xDC8B0510719FA340ULL, 0xF219AEEE8317E3FCULL
        },
        {
            0x35159557904728DEULL, 0x41618528471A8953ULL, 0x5E1DE27426286345ULL, 0xD3E0CBEE1012E894ULL, 
            0xE5EB6FA63BB21A40ULL, 0x0082047EC6424086ULL, 0xEA54013B46D396A2ULL, 0xE38AD03B6D13010CULL, 
            0x689E71D1FE91956EULL, 0x29822106F3DF5E49ULL, 0x1E4ECF71CDF4878BULL, 0xA158057F242F41D1ULL, 
            0x2C466965BBEAF0B4ULL, 0x7122A79255788CE9ULL, 0xEB45B596F8213A39ULL, 0x745BFB8C1C95B29BULL, 
            0x867DE58BC73A5900ULL, 0xE70EBBF3DE6DCFF4ULL, 0x5CEF80F43A3B2964ULL, 0x5EF1140FF079C6E3ULL, 
            0x280C96CC661F23CCULL, 0x9CA566E3B899900EULL, 0x0BCBEDF2BCAF8635ULL, 0x6270C2D4702BBA11ULL, 
            0x0CA2D2953E935847ULL, 0x0A6925EC83F9CB99ULL, 0x2395234147B75CD9ULL, 0xF0DDBBCB382598C9ULL, 
            0x822B9C4EFCF5DA0DULL, 0x3AEB696330A238C7ULL, 0xD08E68B32F5B549DULL, 0x518A29DCD4C128EBULL
        },
        {
            0xF2412328AA4DADDEULL, 0xB44911BCDAE7019FULL, 0x88A3333BCE28EEF7ULL, 0x173A4A6C9D94ACEFULL, 
            0xEEB26B96C2ED838FULL, 0x08CC293BE9339759ULL, 0x14029E375292A665ULL, 0x358A7BE8F2F67EB8ULL, 
            0xF6FC59F486B8221BULL, 0x6E4CC60E527BB532ULL, 0x80EDFCA1DC97E83CULL, 0xF08BEC0E9D2A6B64ULL, 
            0x5917D38486F05674ULL, 0x2CD7F24E5D963CBCULL, 0x6D87579816F00F55ULL, 0x8C3F4574F0D421ECULL, 
            0xE77D5792390BA6DBULL, 0x1C099D538F48B807ULL, 0x593185E98E1F7CC1ULL, 0x53176371DC3A48F9ULL, 
            0x7867D047C0FEDF6EULL, 0xBD90F1356E03C064ULL, 0x289ACF6B8294D746ULL, 0x3116221D8FD5D417ULL, 
            0x5E6D6D2467664CE2ULL, 0x206521BE92923C0CULL, 0xFC16185CC2EC1D2DULL, 0x9339A42DEAC95D04ULL, 
            0xFB0A1A97F6D21A4AULL, 0xD2961273587B30C6ULL, 0xF120D59101502970ULL, 0xBEF0E61A7A8740D5ULL
        },
        {
            0x0AD95015F16F2749ULL, 0xEBB97AEE465D86B4ULL, 0xE50E93AC930BE7F8ULL, 0x9655DF266F9AFC4BULL, 
            0x11C346E592FEE489ULL, 0xC39A573EB96ED3DFULL, 0xAC6F9FD4ED0FAB2DULL, 0x3431EC5D69CB0796ULL, 
            0x6DBB1E0F2572FB3CULL, 0x90374ECADB609BA5ULL, 0x6ECCA0C6C4702D48ULL, 0xDD2353A6A76D19DFULL, 
            0x41F0169AC7ACDB37ULL, 0x53572152FAF3B9EFULL, 0x3DBB33FE566CAFE9ULL, 0xC98C1E0FE141CC16ULL, 
            0x4A2C27578EBD3217ULL, 0x47D2455322BE7807ULL, 0xFC94233C541D19E2ULL, 0x5F038BEB5E74FE93ULL, 
            0x5FC038D2376A52FDULL, 0xD1EE07321026B1A6ULL, 0x96A4618A701C7BC8ULL, 0xC679D1AD67D2664AULL, 
            0x0A5CC42C0B6EA7BCULL, 0x1892CF81C912E1E2ULL, 0x26F03F46EFEAFC76ULL, 0xFF48DA1FA5DAE48FULL, 
            0xE2662E22B512994CULL, 0xE3B7337DC3E8AD92ULL, 0x9E39F54C3BF995C8ULL, 0xC5080A831ADEAD0EULL
        },
        {
            0x24A5D8803B602903ULL, 0x90628B17ACE3608BULL, 0x72EBF57B49E414C0ULL, 0x0FE5354C41B28D20ULL, 
            0x797276557599D394ULL, 0xDEC400AB93A3A2F2ULL, 0xD1A0E24FC3BFFE96ULL, 0x2BB113F22EFC89EAULL, 
            0x57B3614CB9B22303ULL, 0x29E2324F284A9F55ULL, 0x3091D5894AF17875ULL, 0xFA2553EF1B645D0AULL, 
            0xE02089E8CC72E403ULL, 0xC885FDC6E3FD6227ULL, 0x0899D1CA22B7A52FULL, 0xBC9279F64168BA4BULL, 
            0x0898651A226EBAD9ULL, 0x2ED59090BC3C0CD4ULL, 0xAA4E6482EF7A39EAULL, 0x57AAF13E9C2CE130ULL, 
            0x3F22564869B0BAECULL, 0x5D683DA005C2B1B7ULL, 0xEDCBA80C97D9B7EDULL, 0x9B86E347B4D0B986ULL, 
            0x86181EDF71EA1A16ULL, 0x7A237771A56CBBF5ULL, 0x22451B1BF08160E0ULL, 0x29980CC562A25208ULL, 
            0xBCCCCE67B5137657ULL, 0x79067A8CB127C030ULL, 0x95EBDEE42BDE81D7ULL, 0x59648C5F7C0CEA71ULL
        },
        {
            0x7896C4A7B7F142DCULL, 0x00D74BD31A047B73ULL, 0x186D41FC1ACFDBB8ULL, 0x49070ED432D8120FULL, 
            0xA0AA22C23E52F0BDULL, 0xC68476D3ABA8E833ULL, 0x5FF9D4FB4EF8721AULL, 0x7F1256F4A3288A06ULL, 
            0x5E23FED5682DBF4EULL, 0x4915673D1291AF60ULL, 0x4EDC8BC20EC458DCULL, 0x7BD237E817160494ULL, 
            0x3FF041CFDA4F0EDFULL, 0x64E351E05E827D01ULL, 0xF7A4D0B77FCBA2FDULL, 0xEECE8D242B354C32ULL, 
            0x67CC95E3517B3719ULL, 0x44B4AD1A05D50DD6ULL, 0xAA12D5731397471FULL, 0xA846DC98001E0F36ULL, 
            0xA7EA67EA7F86A145ULL, 0xE616B956AC1EAD91ULL, 0xD38C2DCB80D61008ULL, 0x56387CC4C88E4AE4ULL, 
            0x670CF8126E42BD87ULL, 0xE89A45E49F45E8B5ULL, 0x7618163DBBFAB0E4ULL, 0x1A5AAF2CB24A4724ULL, 
            0xF4F3D13808D58BE4ULL, 0xB63DA4DC8B38AC18ULL, 0x01494D2CFA9E87AAULL, 0x093A6FDD6246A02DULL
        }
    },
    {
        {
            0xFA920868F6732B2BULL, 0x226A55B8DD33C995ULL, 0xCEE75E9A268F0F0CULL, 0xE9BD6655E5A721D1ULL, 
            0x32255A3A5DB9171DULL, 0x244F56960934E716ULL, 0xEC7E192688E08376ULL, 0x700727EA1B45D74CULL, 
            0x2173F9E866BFB403ULL, 0x710A0A48691D274BULL, 0x5892A46786A34C6CULL, 0xC850794DB0EE517CULL, 
            0x0F36FEFEB7E3B90DULL, 0x7185CC2C43478779ULL, 0xA7E7A02B5141C9FCULL, 0xE108F26765706DE7ULL, 
            0x69747F09CC154304ULL, 0x24CA068D1EAE99DFULL, 0xEBCF4AFF5BCA6AF6ULL, 0xE4B650E1E2C5A15CULL, 
            0x832E7B146E54915BULL, 0xBBA6706D6FBD6833ULL, 0x89D77A2BDE5515C5ULL, 0x1974E86C5C033BA1ULL, 
            0x659524757B90E2D6ULL, 0x3BEDC9AE52BA4DCCULL, 0x8BE7CAC98A96C3CEULL, 0xF8A5B3EED8D5C645ULL, 
            0xFE17E6B92796E39CULL, 0x700C4E31F0EAF58AULL, 0xE3844A5703433969ULL, 0xD0848E47C9374ED8ULL
        },
        {
            0x6602D0ECF02E151BULL, 0xF260738E4499E21DULL, 0x3CCFC3D6AFF9A9ADULL, 0x986238F0C79FFAABULL, 
            0xBD05EB01AA368E1BULL, 0xD579BA9AC89FEDACULL, 0xF86DAF35C0DF1EE7ULL, 0x29FE66F3612D334FULL, 
            0x501C7B6743C225B0ULL, 0x065540D3847C16BDULL, 0x645850A4D55E4BCDULL, 0xB258AE7FCD625A6AULL, 
            0xBCEF629D0DB8BEA8ULL, 0xBBB6C86CF3DA008AULL, 0x64429FC667B76A49ULL, 0x40863BB3B904D225ULL, 
            0xE74105CD9E7DEEB4ULL, 0x12D9ED30508A066CULL, 0x43292AC0B7260369ULL, 0xB07F6196821D6893ULL, 
            0x770B47BB09DFD0A8ULL, 0xA13A731FA139FD30ULL, 0xB85C9813F3D88F06ULL, 0xC0F1107A44355BF8ULL, 
            0xC9F5DD8C57C39F07ULL, 0xF3B2DA9F769A5E92ULL, 0xBFF6518E87421F3EULL, 0xBFF80FDB91B84ECCULL, 
            0x6A9F6CD1146088B0ULL, 0x8F4B1D3037C3A057ULL, 0xFB3A523046551A0DULL, 0x92771084F179D2FDULL
        },
        {
            0xABA1D96AD6031001ULL, 0x7D96704CEC3E7F8BULL, 0x24755DC2322CAACDULL, 0x414E4B6B166F2605ULL, 
            0x2AA7EF21F01F5465ULL, 0xCEEC994C08D7E899ULL, 0xBE7C115875323307ULL, 0x9CF9EB4B85F4E1F7ULL, 
            0xA7189F46B4B568D0ULL, 0x729A6961A9F66D36ULL, 0x82A06073F21655C6ULL, 0xE9901CC3F9FBA51FULL, 
            0x4F3B5AD6D8EB6910ULL, 0x9C128C0A16F41E18ULL, 0x5003BBFF23701570ULL, 0xB7F0DE854D70C2DFULL, 
            0x4348F7AC98257E3FULL, 0x70D84F408C33050AULL, 0x793FF8F8F82BB365ULL, 0x3FAC62349B092F90ULL, 
            0x8D99B3FC062B339DULL, 0xB911A09BFB89C331ULL, 0x6F825313D4F1DA39ULL, 0xA096AACD4256FF44ULL, 
            0xBC3E29288C6C9746ULL, 0x1F6B1E060FC52A04ULL, 0x9ABC81ACACC6C91AULL, 0xD8174FECA8A3AC16ULL, 
            0xB24BE03D6A641C76ULL, 0x1BB8B7BD1C988998ULL, 0x24AEB7C4F2A4960EULL, 0x43ACBD73053D2FEDULL
        },
        {
            0x504CD149C77540E4ULL, 0x24124DE0EFEEBB29ULL, 0x70CF6509AD4A72F1ULL, 0x524E53BFDD12F5D2ULL, 
            0x95A476C61A900A97ULL, 0xB26A7E2A349E620FULL, 0x371278F2FBD5D379ULL, 0xEE55BA8796015A30ULL, 
            0xD5A3982FB834D2D9ULL, 0x145BBD6DB32C7DF5ULL, 0xEE5C8742A792C998ULL, 0x1FE92CB08C30A49BULL, 
            0x2FAF94B76A02721CULL, 0x30567DC7AC7F620FULL, 0xE28E8B035DE102DBULL, 0xEC13B91429147A67ULL, 
            0x900067B3E47975BEULL, 0x6D8D332368F0D02AULL, 0x43D7317EF8026A39ULL, 0xB5B53B518413CA82ULL, 
            0x02B224B4FDF94458ULL, 0xA31135972A9D72A3ULL, 0x8376440080501660ULL, 0xFBADE9FE01E57936ULL, 
            0x2B0A4FDA3D84987CULL, 0x57639B1C7B3E00DEULL, 0xB1F25E613764AB7EULL, 0xFDF26DBE3AB33EFFULL, 
            0xAF7CC4B56AF83BE4ULL, 0xC1EA0B8CC1EC432EULL, 0x508E42B45BB44C91ULL, 0xF1C5DB69A80FC9FEULL
        },
        {
            0xEE11808851A8E648ULL, 0x3F25E20C51BA9EE3ULL, 0x54B72FF954074DC3ULL, 0x19D5D6DE16F89C5AULL, 
            0x4B64AEB1577BC8C9ULL, 0x9AB7A247975D6CD2ULL, 0xC4AF5811EF6D1212ULL, 0x4AC7DB0E9ABB7B2CULL, 
            0x975B64D704CBF6CFULL, 0x4ED7841A5B68EBD2ULL, 0x6C20EF933C119C1CULL, 0xC342C475957332AEULL, 
            0x9D7E1A09D733E354ULL, 0x8037B1DA0FF12A4AULL, 0x18F170DA30A7C925ULL, 0xDA9045A661895E13ULL, 
            0xAE6F8A781114D544ULL, 0xF36309392EF23CF6ULL, 0xC309895688758712ULL, 0xAD77B8E3BD5EB0E8ULL, 
            0x32584E72E013563CULL, 0x7D10CAC6BD139A6CULL, 0xDDAAE5A5EC006492ULL, 0xFD2B5D394ECC810EULL, 
            0xD01D3E04C74B0547ULL, 0xBA08BACCB37AD2C0ULL, 0x56DFD50332D8994DULL, 0x0EC6F5F0C3868AD7ULL, 
            0x33E9D085CBD1F677ULL, 0xF4C2CBA40783993EULL, 0xF4E23412AC26B188ULL, 0x179C503E6414BF5DULL
        },
        {
            0x2C8E9E0DADA36D98ULL, 0x48570CAE0092510CULL, 0xBC1BC23F3CEC5654ULL, 0x8FC039B1B835E43CULL, 
            0xB92B78139A726103ULL, 0x0628CBE3D31D5CFEULL, 0xF597180D1221F43BULL, 0xA3C779B7F8A5D5CCULL, 
            0xE3C62738A7CDCEC7ULL, 0x8C07647C0A92898AULL, 0x0E6EF951763823A3ULL, 0xA1B3B1C848C346AEULL, 
            0xA6607FAFF9E2319BULL, 0x891F2BF0C87FB448ULL, 0xB6A4AC683BF9134CULL, 0x8FD05A18398F1811ULL, 
            0x20DB8C8FDFB2859DULL, 0x230ADA6EE654A2FCULL, 0xFDBC78D1099CCF15ULL, 0x595B793907E2B45DULL, 
            0x524048F07D8CE9CFULL, 0x63276539E516B720ULL, 0xFA0EABC8785F38ABULL, 0xB8C890CA6C20AD36ULL, 
            0x34294A50CE9CCBFDULL, 0x2D33AE027B8CCF7FULL, 0xCE610D591A731AC6ULL, 0xA52AAC7CD73FD4E4ULL, 
            0x1859783163EB3951ULL, 0xABE7DE40ECEB971FULL, 0x928D417076EACA0DULL, 0x2C5A78CE5B523B78ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseCConstants = {
    0xC912071CCF7ADE26ULL,
    0x09F07565DBE3C518ULL,
    0x76BF9BACC2202EE7ULL,
    0xC912071CCF7ADE26ULL,
    0x09F07565DBE3C518ULL,
    0x76BF9BACC2202EE7ULL,
    0x40E02CA67500B0BBULL,
    0x8DFB9B458DDE2EC1ULL,
    0xDB,
    0xDE,
    0x54,
    0xF6,
    0xED,
    0xC8,
    0xFD,
    0x5E
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseDSalts = {
    {
        {
            0xFDEA8E91158C3DE2ULL, 0x71040D97A787A778ULL, 0x48541FC49D1110A5ULL, 0xB57F220BBB63275FULL, 
            0x9831BE9C1E8660A9ULL, 0x6BC34B68ED28AFDDULL, 0x1936BD00ADC375FEULL, 0x65B46A76774CCE3AULL, 
            0xE664902C171A9BEDULL, 0xD93E5D9B333FDA06ULL, 0x3FA8F4F57672ED88ULL, 0x1450A0164C704B2AULL, 
            0xA51C81C13842733CULL, 0x89CE43A1E1171C92ULL, 0xEFF152F090455439ULL, 0xA332B4847DFCD186ULL, 
            0x324A545208D17B90ULL, 0x4643A13DA13E714BULL, 0x446770344485ADA0ULL, 0x3326FD95243EF07CULL, 
            0x155A04CE25D5819BULL, 0x9280390D3CC5A177ULL, 0x4464B742551FC8DFULL, 0x7BBACC27B286605AULL, 
            0x5A0249F22195B4BDULL, 0xEDE1F973136AAF6DULL, 0x5D766D2627AE5BDAULL, 0x21388A14AFE821DBULL, 
            0xB77D518F7974F2FEULL, 0x98F353927932AA75ULL, 0x98EB9425B9DE31A3ULL, 0x3E5CE8FEE7719739ULL
        },
        {
            0x604ACA36CF0CDE19ULL, 0xEE1C75731A97508FULL, 0xED9AE2ECBD8D3BEAULL, 0x2748CA048CCDF4B2ULL, 
            0x88201A724B36328BULL, 0x95BC8A559F0CA52FULL, 0xEEB044109750151DULL, 0xCFB099C039308D35ULL, 
            0xFB22ECD0648E1341ULL, 0x9DA525DAAD4075F8ULL, 0x42339CF8C46EEBA9ULL, 0x3870592B37D7766AULL, 
            0x50B4FEDED294EF33ULL, 0x212B58AA6B177697ULL, 0x6A961637DA4B03DEULL, 0xECA510C63BB47A04ULL, 
            0x7B6DDCD6BA4AF6D6ULL, 0xF027F760E8A48E6DULL, 0x07C71BC0416CC20AULL, 0x51E59009F90EDAF1ULL, 
            0xDB98DF18F0BE7F4DULL, 0xB04D274FAA7E292BULL, 0x4566FBB4E63B1645ULL, 0x91494E699F1079A1ULL, 
            0x04B01867D026E91AULL, 0x19E6079E7D61B348ULL, 0x60498096E1BAFB4EULL, 0x2D4C42273581B3F2ULL, 
            0x5324AA09AECCCA42ULL, 0xDAE2D75D84CC1F1BULL, 0x05D2B3394143D61DULL, 0x5FF4167E97058675ULL
        },
        {
            0xAA1FA1B8E2EFBC63ULL, 0xAF7A534257B47C0EULL, 0xCADE134B9B50C67EULL, 0x161911AB7993C96BULL, 
            0xFE7F0314B439C902ULL, 0x653639B9B4F48D76ULL, 0xE381578E698A6406ULL, 0x4214C229EBE8C266ULL, 
            0x3DB34A989F36AEC8ULL, 0x845FB582EC55771CULL, 0xAF2E146ED3C0AF21ULL, 0x97D3075061502841ULL, 
            0x43513EBD5E5D7923ULL, 0xC52FCFA8021DEF5AULL, 0xEDD47F78C5498593ULL, 0xCF3F58F722FE2568ULL, 
            0x1AC7F5FF81FFEFCBULL, 0x296E5651BC3231D3ULL, 0xB66AB20020345DE8ULL, 0x9A4030B6672D08C7ULL, 
            0xCD15DC55AEA1D33BULL, 0x4FA1AE4DB8D25F33ULL, 0x2CF17C46DC6353C6ULL, 0xB153B2885ED9BC81ULL, 
            0x44786820DF659074ULL, 0xE64E0731B89CDF78ULL, 0xE5BE898D2A50617BULL, 0xD6FAB85D47A83A7BULL, 
            0x01AB0684B79A7CFFULL, 0xA9FB23CC6FE7D8BAULL, 0xBE7A441F073B1886ULL, 0xE350EE394076D9F4ULL
        },
        {
            0x533ADAEED552A64DULL, 0xCB2393107DC987D8ULL, 0x7E446CC8024782B7ULL, 0x95CBBDD2C1E202FFULL, 
            0x0C19AC3CF711E9E7ULL, 0x9A828579399328A9ULL, 0xC90164EBC2901F00ULL, 0xE2E3DAFCB1495D59ULL, 
            0xF3B8E3184984C2E4ULL, 0x754FB939D26FBF2CULL, 0x161D3C32E12F42AAULL, 0xC1FC10986A860E7AULL, 
            0xB6948BDC12B55ED3ULL, 0xCDD4C0261EFE637EULL, 0xED6D2329F4929CF2ULL, 0x7FE95C708E457A09ULL, 
            0xBCA34760179BCFA5ULL, 0x1BB2F4817639C7B0ULL, 0x2EE5D7B3BF20523DULL, 0xCB16DB2A3299B9F2ULL, 
            0x860934C919025955ULL, 0x9F487220878672F8ULL, 0x82E67DDD669D76E2ULL, 0x082A5549C1343CF0ULL, 
            0x32FEEEDE5625B25CULL, 0x8921F97A1B36FC2FULL, 0xDD9DED4B85821892ULL, 0xF3515D28F4761A60ULL, 
            0x74A36D9CBA108723ULL, 0xC34603C43C35D91CULL, 0xC5EF0621746502A4ULL, 0x86E8478CE60E378CULL
        },
        {
            0x29F99621117DAFB7ULL, 0xE24B7DFB34173F26ULL, 0x5EB9B129C250D708ULL, 0xEF3F8ECD266869A3ULL, 
            0xA73712785AA71C06ULL, 0x378AF2DDBFED423AULL, 0x964E790A3FAA0873ULL, 0xC1F37A70ABBCBDD3ULL, 
            0x28BD868533ADADE2ULL, 0xF4180398DB3907B3ULL, 0x9EA2B94D27AB8EDFULL, 0x78512A254687B77AULL, 
            0xD288C273D9F593C8ULL, 0x6A69D50AB828316FULL, 0xDE0647E76A3492A9ULL, 0xCA95BF2B4DE394A3ULL, 
            0xF8F3BEC2433DD88FULL, 0x92C00B978D456990ULL, 0x1A16309E5CD1B3BCULL, 0x3725657A1B88D4A4ULL, 
            0xBDE52A3860ED8F61ULL, 0xBC4F01C29B7E1B1DULL, 0xB50721D811644209ULL, 0x0F97301606F1392CULL, 
            0x4ECD0DB6CC428995ULL, 0xEEBFB4AEB7053F41ULL, 0xFB101717562AB5C9ULL, 0x1066428E1315186FULL, 
            0x7694D943C18D95E5ULL, 0x71F3D9E2BE7AAA7AULL, 0xB4B726075FEDE5DAULL, 0xEF0894F6EEF76F78ULL
        },
        {
            0x7129E79A4123E891ULL, 0x95F14D4AAC40F602ULL, 0xA11A4496D13F817BULL, 0x7FDEE1E1E189555CULL, 
            0x7AA6DA4A6DFE5773ULL, 0x75045BF8779B2947ULL, 0xEDBAC464D3323600ULL, 0x6BAEF9B58AFCF291ULL, 
            0xD87588610003DAA2ULL, 0x6202E63EEE7A7632ULL, 0xF79D0E7651AC598CULL, 0x9C8FFFCD488E4A3DULL, 
            0xAF9A0C1D368E30F2ULL, 0xF0FEA229DF7C7BAEULL, 0xF8E473EC760CB6E7ULL, 0xE8C0455A5B4A6F08ULL, 
            0x7FD37B3F970DAC8BULL, 0x94FFBA97A02B7E5DULL, 0xA224C87EFE645787ULL, 0x3312CCF67369C605ULL, 
            0x4E10654807062F63ULL, 0x0A0B0E86989D0AE4ULL, 0x22CD67678DC3335CULL, 0x2800072D633B2316ULL, 
            0x680A523F3919B7F1ULL, 0x784A484985F031BBULL, 0x18DA4B3A57C3E7B1ULL, 0xF2D130453A47667DULL, 
            0xA496395D0FFF8DEDULL, 0x2F2D996407A6F451ULL, 0x90B3993BCA03EC7AULL, 0x36559FEA473D07CBULL
        }
    },
    {
        {
            0xC9C8F2282128535EULL, 0xD8139287CB62095BULL, 0x097CD68F2E0FBDA3ULL, 0xBFA1D114776B97E2ULL, 
            0xBF30D80AC08870C2ULL, 0xDE91C7272972E1B3ULL, 0x24846F1339CB8B11ULL, 0x5FC767A6DA5C2F9EULL, 
            0x609D900D430852A7ULL, 0xA05221E834BD8600ULL, 0xD18E350D5D191BD6ULL, 0xD6D53845FC21125DULL, 
            0x1F08BC0C00CE46FBULL, 0x3BCF2EEC5D6376ACULL, 0x72CEF2CE89942612ULL, 0xF18512D437896949ULL, 
            0xA8C8B18B8F2F5C62ULL, 0x48FDA905A1A098C9ULL, 0x6E384DFE4065319DULL, 0xEC9E60D332FB3493ULL, 
            0x267DB89FA121FF03ULL, 0xCB3263416F5F7E97ULL, 0xCBF237456F47DE1EULL, 0xFC02981F99CEA98FULL, 
            0x289B4F32480873BDULL, 0x75B7C24775277BD2ULL, 0xE05DC376B87FD58FULL, 0x7E37F957781BDB89ULL, 
            0xD907F8E4BF439351ULL, 0x0C7AAF9324F95A78ULL, 0x6839884ABE21E28AULL, 0xD10E0706CE5B5DABULL
        },
        {
            0x2AC3BFF3097FFEE6ULL, 0xFBEF84DAED019DA0ULL, 0x6E80099B2DBC413BULL, 0x1D2D86AF02EC8DABULL, 
            0x19BD48FA60616286ULL, 0x005E4CEF231291E0ULL, 0x8B0AE86F9A1122C4ULL, 0x9B396C5CFE7D8355ULL, 
            0xD09266B328D61142ULL, 0x9FF7E03398547A47ULL, 0xF9BFDBE337F4F41AULL, 0x2513E299D88B9D0FULL, 
            0x5F26CB694336C8A3ULL, 0x125F5867D09D9077ULL, 0x3587813103ED133DULL, 0x073786162F6D7D10ULL, 
            0x428765075DF3888EULL, 0x4C735D49BC9ED16CULL, 0x75C9839E514B06A5ULL, 0xB226AD3EC1C7022CULL, 
            0x556BCDD4D9072442ULL, 0x16B48E7E02D75FCBULL, 0x50CABD7CA1518567ULL, 0x3BB05B2AB64F55AFULL, 
            0x7F33067281011669ULL, 0xD8CA873736B28C45ULL, 0xD0293734A0574A73ULL, 0x79FC4AA18E3F1E7AULL, 
            0xFEF7D67F2B319EE2ULL, 0x1A939791376FED78ULL, 0xACDCC95FB3A53BAFULL, 0x826D918E92A9E80EULL
        },
        {
            0xFB6537FE80B4712FULL, 0xABBCC66505A42B09ULL, 0xDAB3B4C6F9E0CF95ULL, 0x4A879F97D181D343ULL, 
            0x464B3C6BAAEDCC49ULL, 0x1B2448F872A0F77FULL, 0x062C7F2AC73DB182ULL, 0x9D22BD091CCA7309ULL, 
            0xD76B3711F941225CULL, 0x473EA199D9133050ULL, 0x821C62ADDCC1BD9CULL, 0x93FCD68163C9BA1DULL, 
            0x00B62A23C01889C4ULL, 0x868CA5D855BDB56BULL, 0xF81C1A0B8CA78EB0ULL, 0x68E71C8BB56DA898ULL, 
            0x5AC0207C925352AAULL, 0x48AAD8F5614C9A51ULL, 0x40530BDA3087C605ULL, 0x0C43F76557A8FDEDULL, 
            0x40F898780FB5FA9BULL, 0xD9FA1F28997D626FULL, 0x8C6911DA7397CD8BULL, 0x4BFB6C0F576B92BBULL, 
            0xBF5F5F86380B5B61ULL, 0x5ADDA68813D2D382ULL, 0xC817C74A331FBBD1ULL, 0xF41C1C0BF5403ECCULL, 
            0xC2FC74762EC6073BULL, 0xA4A28A2B46C384A5ULL, 0x5F5312F6D79D6929ULL, 0xED145AB413E1805EULL
        },
        {
            0x530AD71764C4437DULL, 0xD6D00E93B712B8E5ULL, 0x401F92CC825E5415ULL, 0x344BCB2177255B8FULL, 
            0xDEFDB59E7EF65592ULL, 0x4C864EA7A502CF3BULL, 0xE16D861880BAD9DEULL, 0x9A02B628209FC97DULL, 
            0xF5983BE4B62D6E4EULL, 0x0FC14E1DDA414E76ULL, 0x96FA9ECBD9B5D14DULL, 0x14EA0D245455D520ULL, 
            0x837FB70EF201194DULL, 0xA41BAF2B765590A2ULL, 0x7F604FCA9E42C84CULL, 0x10F4B6D262A99EFEULL, 
            0x2B827D8264FE06C1ULL, 0x742DE3B2AA143AE6ULL, 0x04EE2C1B583F311CULL, 0x560F5F8588142A59ULL, 
            0xEBA750B18DF9AFCCULL, 0xEE59341385723D58ULL, 0x9B76FC35925C0D29ULL, 0x6222A4E07E8FA388ULL, 
            0x6DB79F97FC63E2DCULL, 0x5F1997958F8EE15CULL, 0x2E4709094E611D6CULL, 0x479DBB3587AB5DB5ULL, 
            0xA4982BAC9CC877FCULL, 0xE4D713A4457A3A7AULL, 0x9D9BAE900B2996D8ULL, 0xC519B646FF54A450ULL
        },
        {
            0x10E159E64C7EE7B3ULL, 0xB6E0F3E411D30D98ULL, 0xEA3984995F63B344ULL, 0xE6249A3B96AA9AD2ULL, 
            0x7372A4E27C280C2DULL, 0x67904976FDABA815ULL, 0x47810C470D8945FDULL, 0xA6C03D34B0A5DD58ULL, 
            0x933C85DCBD8B3B26ULL, 0x781F2C2F56488717ULL, 0xB7F867595B2DCB16ULL, 0xCA2B5DE231426C6FULL, 
            0xC96275643A31CE96ULL, 0x79930A110A3D943EULL, 0x60D9462F11521020ULL, 0xB9D9CE0DE10F1250ULL, 
            0xC40D7E9BB72166FFULL, 0xB7693D73A22EFF2CULL, 0x1CF8F901A1421165ULL, 0x94BB9FC74FC23CF9ULL, 
            0x0D9DDCDCA8F8822FULL, 0x048F26B095AC86D0ULL, 0x0CF518E4809ED491ULL, 0x4528C2766CD1989FULL, 
            0x1B7EED1FB8FF7D07ULL, 0xC4D26BF3D6008766ULL, 0x4EC6397FA76962E3ULL, 0xC62AF0A8D9894057ULL, 
            0x5823CE88683D1EAAULL, 0xE100A26668DBE63AULL, 0x87B46CFD3E343F92ULL, 0x234B8239607BD779ULL
        },
        {
            0xC26A12201304A6F1ULL, 0x0205B2A46C3EF6D7ULL, 0xFB3C4459F7DD1B16ULL, 0xA326BD0BF4BFFC2EULL, 
            0x194F210AD1F0E378ULL, 0x08E5DB10C138C8A6ULL, 0x78625EDF821FDD53ULL, 0x9661E798F6E0FC19ULL, 
            0xFB8DE1D4AD9803C9ULL, 0x0455E24A14465A2DULL, 0x2E6596623070D5E8ULL, 0x890A7641F7A0BC3BULL, 
            0x58CA01F35CE0D620ULL, 0x437F153C07FBC02AULL, 0x2965B00654E37D16ULL, 0xDF27C236EF30E48FULL, 
            0x456F6B74B00795DBULL, 0xCF7931C9673EC93BULL, 0x95FC050AEF43EBFCULL, 0xCA2E9B6BD267AC10ULL, 
            0xA1EF3B61C49BA9DDULL, 0x489B83DCAC1DC0E6ULL, 0xE726079470EFAE15ULL, 0x18FF0E3DC6F621A9ULL, 
            0x7538A2073EEDF724ULL, 0x7275130B1BE58581ULL, 0x857FA21880646707ULL, 0x464C33B7772E838FULL, 
            0x9869DE5090E187CAULL, 0x52B8F8FD9CCB2540ULL, 0xCC3E67EF6CF0BA2FULL, 0x8BE107A1459A2238ULL
        }
    },
    {
        {
            0x605B8CF757723967ULL, 0x2091E1C8C6C6B174ULL, 0x83AAE54898999D7CULL, 0x7A5A2213D2FCEC39ULL, 
            0xBB31169374769E6AULL, 0x3631D7CCE1C8C02EULL, 0xD717D327E41A49E1ULL, 0x77A9F358761E54ACULL, 
            0xDD37E18A4137F6C2ULL, 0xAF63D6F7EBE55B4FULL, 0xD91C160CC2354C10ULL, 0xAB3C1504F70E38A1ULL, 
            0x0928165660C41F29ULL, 0x2CDF682D6C6C6106ULL, 0xEB3CAE021E4332CDULL, 0xD1B1616AAEE49E07ULL, 
            0x05B80EC8ED4CC817ULL, 0xDAE87C220CB75385ULL, 0x0F936539F8BB273DULL, 0xB3BD6D06FB02C41EULL, 
            0x6F9AEA764EC52B54ULL, 0xC1473BD40537CB84ULL, 0xC953C6128152CC55ULL, 0xE6CD4FC4964591D7ULL, 
            0x8638F90BC7839D79ULL, 0x6E955306EE1D852CULL, 0xC4FBA3A2FA1797D0ULL, 0xE248465BE28CBCA4ULL, 
            0xA30B014072832264ULL, 0xE923B69C56031AF3ULL, 0xC2351DC67C64EE0BULL, 0xC2E85DAAB2027827ULL
        },
        {
            0x9A8338E4B6F3F369ULL, 0xE6451A29440DE8C9ULL, 0x665ED0887DE7609AULL, 0x2416B7B1C782F532ULL, 
            0xE9BBA41F5BE9FEDBULL, 0x9FCEFCEFC243DC5AULL, 0x30E8129684B6FA93ULL, 0xB0B632920DD49D07ULL, 
            0x3413CBF9E7A7DC34ULL, 0xE6189EB524208806ULL, 0xB501B9647F628DA6ULL, 0xA44F22A5C574ADD4ULL, 
            0xAF048F5949C822D1ULL, 0x188082914348EF2EULL, 0x353E5D7E9CE57D8EULL, 0x24371FC886B392BDULL, 
            0x2B19214B8011688CULL, 0xD7959F9585FF8A0DULL, 0x08AC5D21BA245901ULL, 0x4AAAD76F04AEE129ULL, 
            0xB4E6D2BD57B2639CULL, 0x3FFAB75E61B76934ULL, 0x8AA1EAF91B66C9D0ULL, 0x6B28BD5231D5DE30ULL, 
            0x9312E4378E7C4A3CULL, 0x6EC2F847C4C19B94ULL, 0x2B05F5A7491568E8ULL, 0x9C3873386055A612ULL, 
            0x6661E1DEFE9F4D2BULL, 0x926F3FF51BEB6B9AULL, 0x60D7233582116670ULL, 0x0491817B072E1BB1ULL
        },
        {
            0x5099BC6545FAB1D9ULL, 0xFD8EFEA131A7ED69ULL, 0xED477689532E0E17ULL, 0xE0C69262A075571EULL, 
            0xF9E2F006960F4E8DULL, 0x3A3D442165961949ULL, 0x6C71FFB58CD88E7CULL, 0x7F8ADEF4FB553593ULL, 
            0x101FA16311639D90ULL, 0xAA754D4B02CC1FF3ULL, 0xF5E138C126A7A1B2ULL, 0xCADFCFF7BCBFF79DULL, 
            0x1E5D7DBC83C77FDFULL, 0x321EE082AD4C9AE4ULL, 0x1FAB6FF0951B8BC2ULL, 0x0AE114A261F7B6E3ULL, 
            0xD39FD47E6AE713FFULL, 0xFDA7BD12869302CAULL, 0x4EEAA652F5AB87EBULL, 0xA3F3E9E28562D904ULL, 
            0x4F368284F7D44C1AULL, 0xB9BA81FAF1EF01F9ULL, 0xE0057531063462FDULL, 0x3E81AF4E7092AC67ULL, 
            0xF0C106103075B04AULL, 0x67A1B7604ECC8ED0ULL, 0xC97E62004FB1459DULL, 0x0F6F027357F98623ULL, 
            0x43299302724E8765ULL, 0x108725B2D097BEA7ULL, 0x7683FE686A5C192EULL, 0x7689FB01BF45D297ULL
        },
        {
            0x8A3955C295227B0DULL, 0x2C31DC8C1CD6FF5BULL, 0x1F6EC92630921C75ULL, 0xB3D250C64CD90047ULL, 
            0xB8D4C78D0428634AULL, 0x2145335E45F48BACULL, 0x4D017C46B2170228ULL, 0x6D1C489DE9495227ULL, 
            0x9E7A4A7B68789D2DULL, 0xC2C6724FB9761C10ULL, 0x77B6AE43CC95E86FULL, 0x77F8B183603ADE30ULL, 
            0xA78D5003C042E833ULL, 0xD7199A78AFB04527ULL, 0xEDFE1D8A98B1F241ULL, 0x3854F8FD9730BC6FULL, 
            0x32BA8D9E0CD19B94ULL, 0x3625732A25930466ULL, 0x764C08145972C14EULL, 0xCDF8E2CA742F8DFEULL, 
            0xF1D71BE5D8DB846FULL, 0xE3F5062DE74D6568ULL, 0x464508788EE464B6ULL, 0x3301F7BF5AF9991EULL, 
            0x4F7DC2F125D8D96BULL, 0x7177A783CA741A88ULL, 0x2848AD2A3F8B1457ULL, 0xCC5E8BF13E8B19C0ULL, 
            0x3EF34998A427EB48ULL, 0x081D63C0AD020911ULL, 0xAAE74BA92E296C4EULL, 0xC2E27C3E5AC72E3BULL
        },
        {
            0x51D9F5AF51D88CD1ULL, 0xA306A731F91113E1ULL, 0xDCCBEADAFF1D6919ULL, 0xCA0CD5D3CE1030B3ULL, 
            0xC3E8EA2554BD4AD6ULL, 0x8C472C6DCC822BBDULL, 0x6D01B0AD1649AB4AULL, 0xC6006010683B5FE1ULL, 
            0x295DBC303F7EFEB9ULL, 0xE2776B4052A2A128ULL, 0xC0AAAE1C2D5A9875ULL, 0xB561E1C4C54E8242ULL, 
            0x6061B461EC8DF38DULL, 0xDFA8B9FF56AB98DDULL, 0xB026E9F4D240A88DULL, 0x200A216A48DFC4C2ULL, 
            0xA432B13B9F330616ULL, 0x788E050160D88544ULL, 0xF147F29FE4BCBF58ULL, 0xE3A4DDB84D1C53EDULL, 
            0xD8B32360D8B5550BULL, 0xD72AC02F9C983849ULL, 0x899D4F33A3964D5EULL, 0xC0EB07B4E60E645FULL, 
            0x343B29D763CCF8AFULL, 0x412291658ABD8D41ULL, 0x909826FF55B2040AULL, 0x3CF34A4325A10DBCULL, 
            0x05EC65488C5A65B2ULL, 0x01AE3F37955CE6FFULL, 0xD8D0FCA02983CD78ULL, 0x35DD4F781EDDF74CULL
        },
        {
            0x9E289C3B92768D09ULL, 0x9AC426E7A0CBA568ULL, 0x85F20025CAC1E6C3ULL, 0x1EDDC940BE52F96BULL, 
            0x139BEBC1790D1E7AULL, 0x6FD422D7AB9C031FULL, 0x951B03FC55A659E9ULL, 0x7A2354B89ED358BEULL, 
            0xFE8FDFC1070FD595ULL, 0x10933942B5B88811ULL, 0xCED1516A12052198ULL, 0xE30548D0ACADF976ULL, 
            0x3F4ACEF2947F9587ULL, 0xB10DC7CD189AA127ULL, 0x37A69F1F4E68E8B7ULL, 0x3766C0CE3D116EEFULL, 
            0x56845914E448D650ULL, 0x11E966A7251BC571ULL, 0x9195B3F0224004C1ULL, 0xC4C2EFAF38B845FAULL, 
            0x965B8DB7BE6154DBULL, 0x1D1E6E42EADC8D67ULL, 0xECC8821C220F38B4ULL, 0x1522AEFAA8389C64ULL, 
            0xD133FA31F85157D0ULL, 0x2B5CFF64FC74EB09ULL, 0x8E7C7A56188EB994ULL, 0xAC46A11A1FA9AC8DULL, 
            0x45125D7B0965589AULL, 0x0471DDCD3F756E4EULL, 0xC3519C181D44E3FCULL, 0x15CC761452E8F2CBULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseDConstants = {
    0xD194D900DC7AE2D2ULL,
    0xBF0CE429AA38DF91ULL,
    0x728E24D043289A78ULL,
    0xD194D900DC7AE2D2ULL,
    0xBF0CE429AA38DF91ULL,
    0x728E24D043289A78ULL,
    0x761ECD5ADDA9C795ULL,
    0xA1941EF1FFF58F80ULL,
    0x77,
    0x73,
    0x46,
    0x88,
    0xA1,
    0xAE,
    0x73,
    0x17
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseESalts = {
    {
        {
            0xDA8EF4771D24C783ULL, 0xE58AADC7F3EC6E77ULL, 0xC58053B031686B16ULL, 0x2CB2A890E0F113A3ULL, 
            0x5B7C5F04157A3092ULL, 0xD682652BB4BFAE19ULL, 0xEA4168F08A6AA36AULL, 0x6E0E864F8A4BA1F6ULL, 
            0x3CCAEB2AC4F85D51ULL, 0x6798FEA40746E5F8ULL, 0x6A1E162A07777417ULL, 0x458F3A96A4ADACB5ULL, 
            0xCF185A39EEA9F953ULL, 0xC2B64641F5C40460ULL, 0x295E3FCF8F60F0AAULL, 0x89E95594DA0D2005ULL, 
            0xB85F7FF900010574ULL, 0x3C814AA19A10935DULL, 0x4ADA2AC1ECE934FEULL, 0xF4D5473D7B360D74ULL, 
            0xDCCD73F1E5D0420AULL, 0xF3E614419228224CULL, 0x29882FD09EBC22ACULL, 0x68EAD91CBD43E7CEULL, 
            0x218B98DD16390AC4ULL, 0x520AA915C71EF68EULL, 0xCF52E6F355CF8753ULL, 0x0B4CE92ECEEE418DULL, 
            0x019E93F3080BBB29ULL, 0xAABAC13ADE2CF635ULL, 0x6D7F0D248B4B4689ULL, 0xE616B0AB09753D05ULL
        },
        {
            0xE7D8EEB905E8E760ULL, 0x5AD3AF025C104760ULL, 0x4E0E9910A00918DCULL, 0x749200A0973B155DULL, 
            0x9DC9DAD6115D8FD7ULL, 0x25C4BD1C3EC2EEF9ULL, 0xFE115E0192BE7D0EULL, 0xF24DA1EE1FD579FBULL, 
            0xF928729E57C17964ULL, 0xDF29AB52B7273816ULL, 0x9BF4661AB769AD83ULL, 0xBEA507E6D0CF0978ULL, 
            0x25B3BAC00D9CA798ULL, 0xE0FF781D47E8ACC2ULL, 0x8915832B84F2DDEDULL, 0xE0284176AF436A9AULL, 
            0xAA7C9E47F91DFB97ULL, 0x5C5F6C6AA0A0580BULL, 0x3E85C753B7B72198ULL, 0xBBAC342637848FA8ULL, 
            0x0B2C9E77696C7B0BULL, 0x8A6B6268F095C2ECULL, 0xDC1CA2934D614FE4ULL, 0xAEB2BD395F52BB14ULL, 
            0xA52DFB0E6BBAE72AULL, 0xD8837B8CD4F05A9BULL, 0x6361C7B93FAF5988ULL, 0x0F024CBB04938999ULL, 
            0x5C6C18EB125D62E7ULL, 0x4775BF50BF8378BAULL, 0x3AD6D7EB40435D2BULL, 0xD9C54EC35DF5CB2CULL
        },
        {
            0x803EBC2F2E9EFEB1ULL, 0xEDEF162676C206BAULL, 0x1CB19A0DE9F6C920ULL, 0x6498DAB4E4BA218AULL, 
            0xD0473224BF8EBF7BULL, 0x15B20564FC8FD35BULL, 0xB21CAF0CD7FAAD1DULL, 0x8CD566EC52CE6C85ULL, 
            0xAD6525D557CC663CULL, 0x046B2D2CDFDD37EEULL, 0x0568E0C6E35834E7ULL, 0x98ED8C21E099AFE3ULL, 
            0x007601AE1E716605ULL, 0x1A25718ADD193E10ULL, 0x384B440E5D944308ULL, 0x1B7BD559B565C499ULL, 
            0xBCDC5F52D9EE8743ULL, 0xF9C20D92227DFA67ULL, 0x62BEF92A837F605EULL, 0x64F654CEFDA1B091ULL, 
            0x5714B22BBBC42769ULL, 0xE4FDB3F9FD0BA710ULL, 0x47FCED1B52F74C7EULL, 0xF2B2A10AEE90EC6AULL, 
            0x43F4BE03B3228618ULL, 0x8E360EF15E345DC4ULL, 0x7D11E6FC092FA4D4ULL, 0xE49F31EE7DEE4BB0ULL, 
            0x8C72B1D244ABCC1CULL, 0xB9194081D875C953ULL, 0x044DE8C2AE497D51ULL, 0xE590C31564876850ULL
        },
        {
            0xC042241E173E4218ULL, 0x76E37427F3A7D6FEULL, 0x2FE9C54935753D6AULL, 0x43AC166B13F7E8BEULL, 
            0x18EB43EF355422F4ULL, 0xB9787B2AE05F9C53ULL, 0xBE11E654C8FB018AULL, 0x380E3A5BA82C3822ULL, 
            0xF7534B81DFAD7A7DULL, 0xA0DFC32ACAACCCABULL, 0x6610629453CEE671ULL, 0xF9C9529B3D394B1AULL, 
            0x563B9758ED70F7F5ULL, 0x0DA70714E7462E7EULL, 0xB03839E83DB8F656ULL, 0x538FA3EB2EF3AEAAULL, 
            0x81C7D39A01268E80ULL, 0x36995C8029FB11E8ULL, 0x4BF6C3237E22D1E8ULL, 0x416E020D790C2A06ULL, 
            0xC8DCC2D86A457C5AULL, 0x3C3211FAB4CD2667ULL, 0x8471C2D271513621ULL, 0x9B302BEF7139A68EULL, 
            0x5C1D5E33DFB17D09ULL, 0x13A7F1A3EF6A2EB1ULL, 0x36B652363F1D29C4ULL, 0x2EF2988331673822ULL, 
            0xB56D19FE2BB7DB74ULL, 0xE4D9080960A37384ULL, 0x0574022D72B2BCF8ULL, 0x191E221063CE8ED4ULL
        },
        {
            0xCC5ED170F12D3188ULL, 0x0094870EBF9F47A3ULL, 0xC44D94B140138900ULL, 0x64B744F87741FD84ULL, 
            0x76C52BA5E0F95C0FULL, 0x4FE0571C1A2D5DE6ULL, 0xC9AE847763FCB816ULL, 0xF4AE5F1AB544E737ULL, 
            0x6AEB9891CA252AB1ULL, 0x250AE5B29E201CE3ULL, 0x44D7255432CF7C09ULL, 0xD7E4CC2CCB272779ULL, 
            0x5F29871B707D205BULL, 0xD6CFFDF514FC5356ULL, 0xB80E2C06048D5CEEULL, 0x52201DB71D0CD44BULL, 
            0x1041CA189A95F36EULL, 0x6892794A63B349F3ULL, 0x9BD41B60E9395AF9ULL, 0xA77D77652A95877BULL, 
            0x7AB1CE0D3509D498ULL, 0x3F1E58FC33EAEE4EULL, 0x4937E0E5E116E68DULL, 0xF21EE752CC896CCEULL, 
            0x8C4CC3AA6826BD1EULL, 0x740807D7EC6FA569ULL, 0x4E76D4CAF0BF2B36ULL, 0xF9D9C20CD39C5F9FULL, 
            0x572FE586DF7A54CBULL, 0x14A822D384CF5906ULL, 0xA72E831ECB3A72F6ULL, 0x11AD71B077FA71E0ULL
        },
        {
            0xFA39CF6148C9D952ULL, 0x4991407AC459FC95ULL, 0x2C4BECB7DBA616BFULL, 0x66AA357566DCC2B8ULL, 
            0x5944D92A24EB1650ULL, 0xE856256F0ED8E1FFULL, 0x53941AB9B63AE26AULL, 0xB2C4BFF0069CE3EAULL, 
            0xC4DEF69921BE27DAULL, 0x8D4AF249EA011D31ULL, 0xAD26CC3C39EB978DULL, 0x0E080FE2CE574DD7ULL, 
            0x51C0E527797E09F5ULL, 0x3CEE36A7270CA9ECULL, 0xD4A0F9D22DAEA8CDULL, 0x41DF910F30A461DEULL, 
            0xF3F5BDA15AD0F118ULL, 0x2192F620F876D180ULL, 0x630A365A40DF015CULL, 0x07FE59DB49BA31D1ULL, 
            0x25EFDAFD10532637ULL, 0xB1C24EB43AC618D8ULL, 0x1C37F8DEBE5DA51FULL, 0xCD31882335E9FA92ULL, 
            0x1D787D97DCDD110FULL, 0xF776153DEFA559D0ULL, 0xE80D1B07B55A2F65ULL, 0x415750C2E98085B8ULL, 
            0x2B1D1BEDE3929B89ULL, 0x759FF1FDBD2A3D09ULL, 0xC30780E646AA78EDULL, 0x86CF68AAC9D8ECEFULL
        }
    },
    {
        {
            0x34CC45E5E0D6F50DULL, 0x4D5B3C06102BC8BDULL, 0x436EAF1C9806F5AEULL, 0xB1ABC87CF8B5F722ULL, 
            0xEFBFFEC961829B27ULL, 0x4EB2426C571C3F24ULL, 0x3D7CAE6924F5D6ABULL, 0xAF3E786C2F66A2CDULL, 
            0xCBAEAEA524FA4246ULL, 0x08AD60B0B7C2A903ULL, 0xF940BD44F8A688D3ULL, 0x9AAA98BB02A03E31ULL, 
            0x1DC5186CB8767B5BULL, 0x3592D5642BF5841AULL, 0x7D7B4719769FFF95ULL, 0x24B991F274622108ULL, 
            0xDCBCC5555BAA72DFULL, 0xC5816522D76BD903ULL, 0x3D25FC112DF024E0ULL, 0xFA1E194B5CF41C4EULL, 
            0x72D51D4812A529DFULL, 0x36F7BC08E147A462ULL, 0xEC574D49FC443F11ULL, 0x3134257E6E6C7944ULL, 
            0xFE63358E9F0677CFULL, 0x072396E9F00762B9ULL, 0xE067141019FFC7FCULL, 0xDD80193B61924B99ULL, 
            0x7EABE7ADA0B9C136ULL, 0x73E1B443DD68B86DULL, 0xC60226B011BA6568ULL, 0xC501C9746735E6D0ULL
        },
        {
            0xB94D3695A5B24E85ULL, 0xE0664584325469FEULL, 0xA11090FFEA6F03C4ULL, 0xB05CD464D91EA129ULL, 
            0x50786F71FBEC5ACCULL, 0x962D872F8A138F07ULL, 0x4A3F457473EF12F3ULL, 0xD0E94B4CC813585FULL, 
            0x1B41379AC677214FULL, 0x074C0BBE79989ED4ULL, 0x145EC0EE225B7D45ULL, 0x027E2A58CEEF5A78ULL, 
            0xF3ED7BF860D2F1D3ULL, 0xF7226F025F29FA7BULL, 0x316AF27B77DF59BDULL, 0xC5C6E5E1EC9F6F5EULL, 
            0x46655D31E22666A6ULL, 0x60893630AFFE3BA3ULL, 0x05BCBC4064A3AD99ULL, 0xF1E7F46354AD7C03ULL, 
            0xC199B5F746711780ULL, 0xEB354EE2843A1E9CULL, 0xB2FD9B6F0176CD2FULL, 0x8F6B77C847D87A13ULL, 
            0x9844A381A373E93BULL, 0xCA38132128C889A4ULL, 0xDC1208BC3B340DD7ULL, 0x52E03519A8FF25EBULL, 
            0xAC86E5EEA5CFA5C5ULL, 0x7D83E28C2A38C62AULL, 0xFDDA44566FF9D85BULL, 0x3D242AE917D98B4FULL
        },
        {
            0xBBF6C0E7AD8E980DULL, 0x093CA6AC8EFF72A6ULL, 0x0470B4F917BE06C8ULL, 0x772772AEE87D1588ULL, 
            0xADAD8641BC56F2B3ULL, 0xAD334F8227077B42ULL, 0xC395401CFB88BC37ULL, 0x40B30309F3EC62CBULL, 
            0x7F56718D1C6AA8D3ULL, 0x9B6F50210772A9CBULL, 0x5E22A2A7ED84429DULL, 0xDFD7264890FDCB48ULL, 
            0x2A1DFED2C510E0E4ULL, 0xA747BAF7E1B58F66ULL, 0x91E34C9C787E31BDULL, 0xCD1EE071E5A08E75ULL, 
            0xE2D6F058D0B02325ULL, 0xFEFCA43524425759ULL, 0x55FCAB344D9FA813ULL, 0xBBA5E92D52118B1BULL, 
            0x2EDA492202C3676EULL, 0xD79E361BEA1EF51FULL, 0xC1BBE83237AD84F4ULL, 0xFDC46366E936D381ULL, 
            0x824999D9610AFFDEULL, 0x5A491108253BBCDCULL, 0x454379B9F06A2341ULL, 0xD2C16224027814D3ULL, 
            0x5E1538B40EC90363ULL, 0x32575F64D9D114F7ULL, 0x329F4207EF98CE05ULL, 0x1B8BA4D8A653EE32ULL
        },
        {
            0x1BAFEE41296833F6ULL, 0x528702616BE650F1ULL, 0x4CD7B40E45458642ULL, 0x430C97FDEC2CCFCEULL, 
            0xC29B9BB3B882156FULL, 0xA860A6C984A8017AULL, 0x0F5D4FF5F8A5F355ULL, 0x19E38C0CD06677E7ULL, 
            0x187C5EF211327337ULL, 0x29C717C8AA0D1221ULL, 0x7B08242ADC5BE01BULL, 0x9EC39F4F9F24606EULL, 
            0x70355BB16945A42AULL, 0xA8A0EF3BD90DA0A8ULL, 0x58B672E1A3DE103DULL, 0x6F363FD2880657FEULL, 
            0xD9894DA3E85C0481ULL, 0x8ABF58F4B6EC6232ULL, 0xEDD9DEF1A3100532ULL, 0x6128FB775352754CULL, 
            0xAC5A42A5AB41C120ULL, 0xC051D8F2C7BE1AACULL, 0x11969A8BAE3E9C4BULL, 0x8F69C9766D8BA9F0ULL, 
            0xC12DCE0001E8A0A7ULL, 0x676ACDB0A86111B9ULL, 0x4A63741971D625FCULL, 0x6A9FD4A9AA356CA1ULL, 
            0x8DAD4BDDD8EFB80AULL, 0x02E5D7B470E63D68ULL, 0xB03A36AD86FAB353ULL, 0x0A460BC67DF4CC18ULL
        },
        {
            0x44C2484DAC187C54ULL, 0x4F6A2A96BE1848E4ULL, 0xF361B9CC4E3B5DCBULL, 0x313B83A14E3C446DULL, 
            0x171747F464D5146AULL, 0x7258A3AA0F0E6AF7ULL, 0xA12C616A9FFE28E9ULL, 0x17F0C26F6F6B51EEULL, 
            0xC29BC63CA8068A4BULL, 0x1D75A0D19AD2A024ULL, 0xF7ACB0E6A5D40B1EULL, 0x75D65E54475D5712ULL, 
            0x08683C1B5A60C641ULL, 0x45E71E415C8717D3ULL, 0x18BE91CA994C8F12ULL, 0xBF020967F93E6681ULL, 
            0x98B7A2802A5AFC63ULL, 0xFC80F5460761CCAEULL, 0x255719ED5ED36B2DULL, 0xA04C9D574C95A085ULL, 
            0x341A1B9B506B6A20ULL, 0xE68D4F4C1890C113ULL, 0x2733701AF084945DULL, 0xC4BF69218088B8ADULL, 
            0x7F2BB4640554A639ULL, 0xBFFB5415CEA3B6BAULL, 0xE203420189FA8D6EULL, 0x1F54BCC89AF9FCA9ULL, 
            0xF247482DF42FF0F8ULL, 0xD9F0E12865F13A85ULL, 0xDF82EC74EACE94B5ULL, 0x7D3FA505F8807B8BULL
        },
        {
            0x57D680FE28CA7BCAULL, 0x135247AAA59B3918ULL, 0x944D64A48A1779F9ULL, 0x7989A5951526F2C9ULL, 
            0x2BFD2D52B27681EDULL, 0x63A6B6AC5438F29AULL, 0xCE6E0AE3B265D98CULL, 0x5D47CBC66BB74878ULL, 
            0x5212CCA6445958F9ULL, 0x1E8384F9DD25C4ADULL, 0x46913FA1A06741ADULL, 0x97A684E168972AA3ULL, 
            0x159EB7F2D935297CULL, 0x44ACD9266BEFE830ULL, 0xE782A472DE9C238FULL, 0x8208408EAD6795C4ULL, 
            0x34EA94FAF4AB80EAULL, 0x6ADF773D9E154B8DULL, 0x59478131E007768AULL, 0x32A9B310E0EA8F30ULL, 
            0xCF3240164F6E7C3AULL, 0x1A715A35DF502C09ULL, 0x170CD653D0579BCCULL, 0x7252BA31B422137EULL, 
            0xAF7BFDCF3960F8C9ULL, 0x75DB56E59171ADD9ULL, 0x6719A027F282F6E7ULL, 0x5B3FF9BCA8782F22ULL, 
            0xBF0F0627C20D7D6BULL, 0x1E2F569A8F05A5A5ULL, 0x359B87BD731DB97FULL, 0x03BBC45B943A93B6ULL
        }
    },
    {
        {
            0x473F2D6EF686D260ULL, 0x974AD9D577E03E92ULL, 0xC2B5901C8AF87A5DULL, 0xBA7D314C2761ABC0ULL, 
            0xFBC2B04D2AB27FFAULL, 0xE261E0AEC80268C2ULL, 0x30841CA05BA30EDBULL, 0x6D40EF0D4E84E930ULL, 
            0x3E3958289792E972ULL, 0xBE932C8042DB20D2ULL, 0x5FC94D07E66FD4DCULL, 0x912FFEF49F711177ULL, 
            0xFE00EDE37D5C94BAULL, 0xDA27579C0C787CCBULL, 0x7D35C4840F108D65ULL, 0x99143595F3FE3592ULL, 
            0x0638C2D3C8D39EFFULL, 0x6B0D5BD7D694B65FULL, 0xF1117CEA354690ACULL, 0x24F2C4F23D671482ULL, 
            0xD2F3AC4A63A95E20ULL, 0x3973E2C2E045ABD8ULL, 0x521DD08ADED16F7CULL, 0x055AD5A7C8057452ULL, 
            0x0EEB747B4B314339ULL, 0x8C3A708204BFE99BULL, 0x0D1D7306CFD4CC3FULL, 0x5977EB73D99F41AEULL, 
            0xE73B63B227113998ULL, 0x6C36C108690BB06EULL, 0x4E4128FC11D9E026ULL, 0x2028B9F7E9FFDE37ULL
        },
        {
            0xD10B6388F03A2DD7ULL, 0xE010AE9C823323B2ULL, 0x1501AF7C8CC497B9ULL, 0x4D005ECCAF58E91DULL, 
            0x17E715EB37F2D4CAULL, 0x5634A6F3D06EF65BULL, 0xC8DAF40F841930CFULL, 0x0F90790BCBD7B2DAULL, 
            0xF0B2798279A174A0ULL, 0xFDF5AC940619087BULL, 0xAD982386BD308EFAULL, 0x2987822DB27E83BEULL, 
            0x4862DFA273C01E4BULL, 0x99E979D8B89F222AULL, 0x7BA1EFD4EA676364ULL, 0x8B4974FA7154807AULL, 
            0x79D51523A4FF2AFCULL, 0xA87B2945CF2DC368ULL, 0xD39FC7A587A9A3DDULL, 0x1DFCDFAEBF357592ULL, 
            0x363BC42134CC8E71ULL, 0x0CB89234539BCCE4ULL, 0xEE504DDDBE87AF40ULL, 0x6EC196E4415CF580ULL, 
            0x3848905E83471CCBULL, 0x533D5D149D8AC822ULL, 0xA7CACA7CB93BFF8AULL, 0x6F637E3C95EE3BB5ULL, 
            0xB255D26C09373903ULL, 0x42AD682CDA535D45ULL, 0x91719B67B817511BULL, 0xF3419DF43CEDA9FEULL
        },
        {
            0x5038F2610AEFE8C9ULL, 0x41A80C36D9431F90ULL, 0xD51446A1332A4756ULL, 0x5B35EBC935F58451ULL, 
            0x850E42EFF1538BBDULL, 0x6B0107FB2291FBCBULL, 0x9E4465F6435F2405ULL, 0x69D868F4A7F4405BULL, 
            0xDE5BFB72972728F6ULL, 0xFA6C4EA19BAB99CDULL, 0xAA4B3A574603EDBBULL, 0x862A46ED5D6883F2ULL, 
            0xACEBC81B3CCED6A8ULL, 0x2FB6516BCAA1DB4AULL, 0x520F7DED3F439B7EULL, 0x2D5093C89F1A3434ULL, 
            0x1A505ACA3BCE76FFULL, 0x436FF3E02231710EULL, 0x9FA517D92F11E38DULL, 0xD605713905E18CE8ULL, 
            0xC9AB49E041933F79ULL, 0x119EDE13EEDD7F05ULL, 0xA17A396EA0BDE9D6ULL, 0xF1078F11DC5F819AULL, 
            0x1065913394CAE5FAULL, 0xEC9B37F3F2925915ULL, 0x4D79B01AB887DD10ULL, 0x8BF53DABC438861DULL, 
            0x0272D3140256BAF6ULL, 0x9B5ADE31124875E0ULL, 0xE36255076A0AA1BFULL, 0x7536FCC2C8AD0301ULL
        },
        {
            0x8C1DB4B8B4D4E0E2ULL, 0xE22321A95272AD74ULL, 0x254C738778143F38ULL, 0x2E47F3C8D8BBE409ULL, 
            0xB9580696B5C81D6EULL, 0xC0F7ABE1A2D76BAAULL, 0x3607C67D9FB707BAULL, 0xA853C835595C83BFULL, 
            0x27BE0A4101D263E8ULL, 0xA719757BC0DCF3CDULL, 0x4286BC7AF9EDE843ULL, 0xCE0E1671588F4092ULL, 
            0x64F6B2EF78FA861AULL, 0xE2F1004460CBFD7FULL, 0xA69F65B352AC5E7CULL, 0x2D41A77FB595B8F2ULL, 
            0x4A15F3E64226E753ULL, 0x564FAABD9B7F3087ULL, 0x7ACB01F7B2062145ULL, 0xF1089580CCD31D55ULL, 
            0xAAF36DB5A23B12C8ULL, 0x8CCA4343BF1E4419ULL, 0x45D6B2C2004C9744ULL, 0x685F2B4702060ACAULL, 
            0x83E9E04D87E87EA1ULL, 0x24751625E8F3B061ULL, 0x081872D15F9FA74DULL, 0x2E801F1E3C20D0F5ULL, 
            0x72985B194888C1CEULL, 0x36391687018634CEULL, 0xEF07E3CF868701E4ULL, 0x7EF2C212C7E98BD4ULL
        },
        {
            0xAA4EB36EB1C0F290ULL, 0x15F551505D533B7EULL, 0xF4EC3C07E3FE60FDULL, 0x3DF844711F7525BDULL, 
            0x966BEE5F888C1AB8ULL, 0x898015BC4E682886ULL, 0xD4E0C236BF56292AULL, 0x5AA4D4FDDB9585E2ULL, 
            0xD95B32CA7CF06C58ULL, 0xC769056BEA08483CULL, 0xB30CBB40B8F36849ULL, 0x1834A109575EE41CULL, 
            0xB18A6E4AD2850ABAULL, 0x028F928A85B8A312ULL, 0xCDEA6208D834D550ULL, 0xE9BB8CC000D820DFULL, 
            0xE3A34569C8F42C4CULL, 0x66B1A03792385FB6ULL, 0xE7419EBFEE6C3FBCULL, 0x5954CA3752F43683ULL, 
            0x124478EA9C13280DULL, 0xA2B7C74409C82BF6ULL, 0x58924B0FD5893534ULL, 0xAFEA2F9D7C80592CULL, 
            0x6D2E63FFE4E28C03ULL, 0xF8F0943CEC50D120ULL, 0x84D257E859C0B333ULL, 0x1EC231CF204D4189ULL, 
            0x32E3F83D279D6E59ULL, 0x3D377583CE3E0251ULL, 0x6BDB15F13A37CC0CULL, 0x1ADE9152B684ADD5ULL
        },
        {
            0x35DA73219C55938AULL, 0xCF7E476D214CE52FULL, 0xDE2CC30B26F254D0ULL, 0x296C7D6556D911B4ULL, 
            0x8E140339356B743AULL, 0x7F97817C856BA802ULL, 0x6A6868CEE6986F97ULL, 0xA0BF3D4E21FA34CFULL, 
            0x788F8B44FA775FEFULL, 0x06858BFB56CF4854ULL, 0xC0D7D72586991F6BULL, 0xB5E9574A74116596ULL, 
            0x796764028848A8D1ULL, 0x20A5664D506263C5ULL, 0x6A9DD96677810851ULL, 0xC9234C432583699CULL, 
            0xE410B8CC434799A8ULL, 0x20FBAC100C574A03ULL, 0x1DFAF50CDC16B2B6ULL, 0x08D010F1035C12C0ULL, 
            0xF6EF5CCB688ADD30ULL, 0x945816D03ABD39E3ULL, 0xEDC133C721A57DC7ULL, 0xC093BE640405E83FULL, 
            0x2A20DDA513F96883ULL, 0x736447A10CD007D5ULL, 0xEE66FCF719B43CA3ULL, 0xB5153100BAA36F75ULL, 
            0x833361E2DBC7FC3AULL, 0x024BF0F4DE9CB5B4ULL, 0x7EC0BACC80833F98ULL, 0xD8FB3FC3FB54FF6EULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseEConstants = {
    0x1059A89CDA81E535ULL,
    0x14CCDD9073C675B1ULL,
    0x51FAE12FC3ABE11FULL,
    0x1059A89CDA81E535ULL,
    0x14CCDD9073C675B1ULL,
    0x51FAE12FC3ABE11FULL,
    0x475DAEF2F66E498DULL,
    0xEA8F8E31401532DDULL,
    0xC1,
    0xAB,
    0xAE,
    0x5E,
    0x31,
    0x60,
    0x86,
    0xB0
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseFSalts = {
    {
        {
            0x5DED3DBF42168F10ULL, 0x25CCE5D50C893D69ULL, 0x3F7F5B757DFC138AULL, 0x8F75D391A6C90591ULL, 
            0x8E62BCE0A23D6F71ULL, 0xC595F46F84F6BCDAULL, 0x59B6651D9C2D7BDDULL, 0xFCDF53A2E4796ADFULL, 
            0x73EE6B67E26404A3ULL, 0x9F3DC43BD538A100ULL, 0xFB826FAF95A1FE7AULL, 0xBA8B70D505925486ULL, 
            0xD40E1FD7361BBF88ULL, 0x96DD8528114E7069ULL, 0xE73144C896DCDF71ULL, 0x47DFFA700D22147DULL, 
            0x83492236C1057457ULL, 0x771F4400E808E7E3ULL, 0x0D54B86747C4047BULL, 0x3359CF98E61E53D6ULL, 
            0xBEE5D1EA085B7F6EULL, 0x9C1BB3282F66031EULL, 0x1A838359A5D9AF19ULL, 0x9B8F0D8BAA0C064EULL, 
            0x28B50E13B36C3C7DULL, 0x06A15CAE493BC7BDULL, 0xD555F7B72781C5CDULL, 0xC59802B7AF9BA745ULL, 
            0x483313641FC7A604ULL, 0x4A67F806412AA844ULL, 0xB99BE376424BF5A6ULL, 0x159C38AEB6F40666ULL
        },
        {
            0x33D930730C6A50ABULL, 0xD0339691588DFBD8ULL, 0xEE6732632477B98FULL, 0x80E3AB65DAE7732AULL, 
            0xB04D41C93E7943B1ULL, 0x568FAE0313700E00ULL, 0x5F6D74C56257EBE2ULL, 0xEF1709280AC5CA7FULL, 
            0x0526BA761E59C82FULL, 0x0BFDB147012510D9ULL, 0x267901FDF897DCB0ULL, 0x5A9017C87A6E6100ULL, 
            0xBED5FC38BE7455F6ULL, 0x3701436A4F7CEDDCULL, 0x2A9D30ADC76BC27CULL, 0xF1C7829E1DCD7508ULL, 
            0xDF2163D6AAB8BD37ULL, 0x7F2E66E5EBBF30D1ULL, 0x8D8C7D4269190481ULL, 0xB4280262E074D8CAULL, 
            0x66CB03D4048D1017ULL, 0x7BA2334D4E081234ULL, 0x35CBCFEBA4A45CCDULL, 0xBACCBAA539896B90ULL, 
            0x6F4C1EB9D76B1C11ULL, 0x37A68D4A77C35850ULL, 0x4F55A4362C7C93D1ULL, 0xEB6A01432686D81BULL, 
            0x2A9E42EF579E12BEULL, 0xE2C1F8B600C5FD7DULL, 0x3E07EE33CFF95C98ULL, 0xF8EB6E56E34B6409ULL
        },
        {
            0xB838392BBC9EAB04ULL, 0xA360C197C1B41BEBULL, 0xD2C325E1E2BA5DB9ULL, 0x328A6B706895FAF1ULL, 
            0xDD6EF80CD309D112ULL, 0x68C1338811F9CCD9ULL, 0xED909784E43FAA3BULL, 0x04AD39EAD559E165ULL, 
            0x9F95B505245AD140ULL, 0x5761C19C363EB2D2ULL, 0x8D104F46F172271EULL, 0xD63B69713B11E824ULL, 
            0x0F7E4D3F037AF102ULL, 0x33F950A8FEDE791BULL, 0xF2D6FE842C70FA6FULL, 0xC4C4D3392C3D5EF5ULL, 
            0xD0DD4091F00F05C1ULL, 0x51DDEDE638EFC90DULL, 0x4F5EABF4DF5F005DULL, 0xE5EA21983C8AE2BAULL, 
            0x7CEE784635891A13ULL, 0x13AFF1F600533137ULL, 0x4CC66D160465E3CEULL, 0xF32471F863243775ULL, 
            0xCBCB5F2CB26D9421ULL, 0xEC9A07106C57A9E2ULL, 0xFF02511B12B1C51FULL, 0x0685CE98C5F4BAC4ULL, 
            0x3842A70C9884B374ULL, 0xEDED7F00EFDDE4AFULL, 0x1044E5A6345EE376ULL, 0x609B9D5DCFF3C686ULL
        },
        {
            0x922FC0A0AC6C6877ULL, 0x01D30FDE8B455479ULL, 0xB02DEE1381A72A47ULL, 0xB6C3833F9CAA977EULL, 
            0x1781BB83BB51A585ULL, 0x29F846BCAC07957BULL, 0xE29C61CDE569152DULL, 0xE9ABFD0647CAA9D3ULL, 
            0xCCFA5DAA6876139DULL, 0x8D6A01EA163F1995ULL, 0x93DE5C4EE56E115AULL, 0xC3A53BDE4494BBFEULL, 
            0xD43E337D873DAF2CULL, 0xCDE58FB0CD04115FULL, 0xE1F95DF1535D0E95ULL, 0x54583FD0486D205EULL, 
            0x3DE60B3CB3617462ULL, 0xB0147C6C7DA95065ULL, 0x7733997800D96779ULL, 0x792DC4D34F56890CULL, 
            0x4C42C07D991BE92AULL, 0x6D6A2770FC24CB6FULL, 0x780A5843DA7BC0C5ULL, 0x8494ACDCC2E6ED2DULL, 
            0x1C1B8140995CBDDEULL, 0xF99EDB91592C1214ULL, 0xDF0353354543FA88ULL, 0x9AB94304CF00A919ULL, 
            0x8664A75CB7BBBCA9ULL, 0xF37D8C9F89B2308BULL, 0x59F7700F1ACC3AB1ULL, 0xFEAEBCDC9FD42716ULL
        },
        {
            0x01E3F1A721202320ULL, 0xBDB7940BBB81AF37ULL, 0x9289C6C7CB7DD3E9ULL, 0x7289FCFC130A56C1ULL, 
            0x6454B4C27984CE22ULL, 0x6BCABBF361BBEB1CULL, 0x57EF99AC3764BA1BULL, 0xD36E815297FBC354ULL, 
            0xEEA6C2157BE17500ULL, 0x675579972F9BF92DULL, 0xC04E9DE0C209BB91ULL, 0xA8935C089C04A630ULL, 
            0x99EC032A4D138524ULL, 0x82C63DD00E918EB5ULL, 0xE857711872FD1620ULL, 0xD4EB3897E2BBBA06ULL, 
            0x58E3D0C56E996D74ULL, 0x7C2F898706B31384ULL, 0x4D5290C5739376F4ULL, 0xE8C153F482F5C94FULL, 
            0x72AF213F0A16A4D2ULL, 0xFB888BAA8A5394EBULL, 0xEE190933D58412ECULL, 0xEA7FACDF3F7BA99FULL, 
            0x59CD392DCB75D754ULL, 0x65203BC6461E5386ULL, 0xBE17F8865F706046ULL, 0x151E7932E0E5053FULL, 
            0xE1771741FA0DF66EULL, 0x220A59786A4ECCAFULL, 0x27CD87A1F1AE6DA3ULL, 0x7D3A7FD3756D847FULL
        },
        {
            0x0A99612FE753BD47ULL, 0x5A808BB150402618ULL, 0x20E980595848FCEBULL, 0xCCAAF50FA59F5D8CULL, 
            0xCF87803782E35C42ULL, 0x149A7D469E5F525EULL, 0x6005F27AF6B50704ULL, 0x906F1D32C700C3DFULL, 
            0x60C360E92738090AULL, 0x388C2B1A584925FEULL, 0xF64AA850D7630F6BULL, 0x2DAA07C7FE9DD6E6ULL, 
            0x0247A03F170B2DB2ULL, 0xE184A6038E94F518ULL, 0xB3F59BBD064E71E3ULL, 0xDFFB7C9F2CD7DEFAULL, 
            0x1286256272F26AC5ULL, 0x0669E1723E88EB3BULL, 0x8665CCFD9607BFA4ULL, 0x633E998D9B2DF80EULL, 
            0x3A5C5022F1484441ULL, 0x7802B0FD9B3FF3E6ULL, 0x0F8251576842B421ULL, 0xA49C4CA090F98CC7ULL, 
            0x2DC368845FFE543AULL, 0x00303FFF804EA6D4ULL, 0x29B74B8BA81695C4ULL, 0xF47FAC7BF8303A58ULL, 
            0x1EF718981E430F99ULL, 0x629B764DF9AD20A2ULL, 0x1F8B8E831E295361ULL, 0xD4172ED6F25276A4ULL
        }
    },
    {
        {
            0xF3A85FF29106E516ULL, 0x2B3CD439F1A8CBC1ULL, 0xD09093C833D3EA45ULL, 0x3D4D96443EC8E998ULL, 
            0xC664A3FCA93C5CE3ULL, 0x448D97C66A5272D4ULL, 0x5B6754FE8377D0F4ULL, 0x2FC22864D6267BE2ULL, 
            0x5017B2244EB70FBBULL, 0xC82D16A9BECA03B2ULL, 0x2DF84B50C973ECDAULL, 0x6D9279DCA1E6D269ULL, 
            0xA1AEAE6536628C70ULL, 0x22F9B3AAB7D67209ULL, 0x95130EB524AFED1CULL, 0x455F99F9C978E76EULL, 
            0x3C2E60FE58D94FE5ULL, 0xEE935392C6660640ULL, 0x87341EED650927DFULL, 0x644E0E2DF2ED4CAEULL, 
            0xA27FB91C281870E5ULL, 0xF354D73C5A8E9633ULL, 0xDFF3393006B986FEULL, 0xCC8A52CD1E8DEAC9ULL, 
            0x907A21B1AE42817DULL, 0x8CD67BAAEA1B08F4ULL, 0x1D88A835D85A0208ULL, 0xFFA7266DD424C4D0ULL, 
            0x243EE7DBE751A174ULL, 0x65A696B339546DDBULL, 0xC4598BFA3BB803F4ULL, 0x6BB1B3C279755834ULL
        },
        {
            0xC8832114FDF78330ULL, 0x8CFBF879D9E3BB2FULL, 0xA6481ED14C391FD2ULL, 0x135678D284CCDECDULL, 
            0x65ED8D20855F22BAULL, 0x5510BF1CBF7238F3ULL, 0xDDF6E423DAE856F3ULL, 0xE6536BA651B28A17ULL, 
            0xAF4C090FA07AB978ULL, 0x1A2CB4EA4D32B3F8ULL, 0xC6A2546D8D2B05C2ULL, 0x69D0068C417A4F97ULL, 
            0x502C000B8E76566BULL, 0x85D5DCE092436817ULL, 0xDBEEC56AFB0011A2ULL, 0xA57F9309C9E264F7ULL, 
            0xB3AC8BF7343B1DB5ULL, 0xEB0D9C3E1798EF88ULL, 0xC8EDCE95C3CC4170ULL, 0xD454B493BF35211EULL, 
            0xA160EE348C954A44ULL, 0xFB2F89FEEDF98265ULL, 0x8FAB4D99F37C05DEULL, 0xBEE36C792E3B7CEAULL, 
            0x4E6F8FA50E640900ULL, 0x5A5C623E746002E8ULL, 0x50716592C7BC8021ULL, 0xECB5D1FC280AD7A0ULL, 
            0x113946A8DEA3D1F2ULL, 0xB59B74F8A723E929ULL, 0x9E26DDA51671813DULL, 0xD7468575D8477C31ULL
        },
        {
            0xABB49EAC1C509706ULL, 0xF6DDE7CDEC3D22D7ULL, 0xF78C99410A214DA8ULL, 0x828B9802F0A368C3ULL, 
            0x1418BF440974DC5CULL, 0xB78F9866AEC1DDF7ULL, 0xAE10A475BAFC1C20ULL, 0x0088FA7B0E8BE14DULL, 
            0xC397847DC7518C16ULL, 0x6BF35191AA65D466ULL, 0x85A09AA3B2454859ULL, 0xDCD93627E49F7166ULL, 
            0x37E358CF63177DB1ULL, 0xE2D086074004AC5AULL, 0x2BBBB7AC6ECB6F20ULL, 0xD2967D9D380F360FULL, 
            0x2F45F2BBEC7CB933ULL, 0xC84CEFE9D5A47513ULL, 0xFAD69FA8BE607F7CULL, 0xC8628B0653B6A8E7ULL, 
            0x95F49636961815FEULL, 0x33B437D0570154C1ULL, 0x3AD6D4B044993021ULL, 0x634C500D3D00DD07ULL, 
            0x2A415A25BC1CEF33ULL, 0x2B5DC06FF0D4E380ULL, 0xD1C97605F6CB4D86ULL, 0x04E213AB28310747ULL, 
            0xF93DAD20C499E190ULL, 0x3B6451DFF5EC57F0ULL, 0x7D2CAA06BD5BCED6ULL, 0xD8EFDE76B481EE4CULL
        },
        {
            0x64785E9FAEE60E4FULL, 0xF3FA6BB13851D76DULL, 0x061B37E8012EFD3AULL, 0x919DD6113A8AFDB4ULL, 
            0x3C7C5269FE6DE5F8ULL, 0x14BDD0D15781A06DULL, 0x08E71911689B14EFULL, 0x4FA59F8925DD0D84ULL, 
            0xAFF634285C1E66F7ULL, 0xB8DDBCC8B5EA8081ULL, 0x395CE2035057CC70ULL, 0xA56E68EDA2DA8B1FULL, 
            0x7A258D0595E75F09ULL, 0xCB241A928B42CB3AULL, 0x9EBF8CB8C2D3DF9FULL, 0x56653CE235F321B8ULL, 
            0x6B5D6B324A3E5CA6ULL, 0xEE4E411931E9F4AEULL, 0x3C18E56E5723FC47ULL, 0x9107409E8438D116ULL, 
            0x826A3A56614975E0ULL, 0x46C02F83CF95ED39ULL, 0x591B5055054B51ADULL, 0xF6425629016770A0ULL, 
            0xA5C7327D99B6BEA8ULL, 0xFE21335B4BE80B35ULL, 0x6BF9F8DC4BB70B1FULL, 0x82D9556AA60EC28EULL, 
            0xDEF91831ABFC061AULL, 0x780B6BD57484450FULL, 0x55F750F82BED9040ULL, 0xA373B0E18D3499E5ULL
        },
        {
            0xB8377E867F36E1C6ULL, 0xBCF0C5CA1979AC09ULL, 0x5ED21F96B06B16A7ULL, 0x03025882C5714B6AULL, 
            0xF08398D50ECA3FF6ULL, 0xF4A60BA83A73EC0BULL, 0x2353814648AF91E0ULL, 0xB15EB5F3A4DA6B79ULL, 
            0x5A285990B49860C1ULL, 0xBB415C6C20D14E77ULL, 0x8A561626E546E775ULL, 0x9CF5D4210888A77EULL, 
            0xCC8E86CD484106B0ULL, 0xE75DB374D8BF090DULL, 0x8386248FF9E85C20ULL, 0xDBBE0F5BE593FB6CULL, 
            0xDF4695DE13399A6EULL, 0xDAF36DAE768372F6ULL, 0x4731952C6E381BB3ULL, 0x54399A754B071E16ULL, 
            0x753B0EDB892CD11CULL, 0x48EC57D1AF91CAE7ULL, 0x00CAD6FB6364CC54ULL, 0x85F087415AE2B669ULL, 
            0xCD375B85040B14ADULL, 0x773849EA0114602BULL, 0x79D59BC24D126AC6ULL, 0x626EA98B3D95479FULL, 
            0x17C51AA663F42AA4ULL, 0x9949A6533859CD65ULL, 0xF9D4E939C3F3B77BULL, 0x3DE69971AE55FCE8ULL
        },
        {
            0x9271AC879CD47ACCULL, 0x3FF30E6939EE233FULL, 0x57675C9CEA6CBD94ULL, 0xAAD6E1A691B6E2F6ULL, 
            0x96DC775EE015790BULL, 0x12CD49E958B21355ULL, 0x2F849914C9C7A75CULL, 0x73983CBF33A7B0CDULL, 
            0xA014F3E6BCA321CBULL, 0x561D254EC077413CULL, 0xA8BE2BA2A8A9D1A4ULL, 0x6A68A3F1DB149029ULL, 
            0xC9AF5A1492D82742ULL, 0xD83933C3CD5E9884ULL, 0xDACAF1760E81EDA4ULL, 0xF2718B9846AA13A4ULL, 
            0x8424EB55CAB67C33ULL, 0xD7E3EE1CC320AB35ULL, 0x8CCF8C17F97FC594ULL, 0xCC324CFEC29CEF14ULL, 
            0xEBCB6993781A58F0ULL, 0xA262124E4885EC86ULL, 0x6A15CAF2C18D9DBBULL, 0x76BCBFE38851CD4FULL, 
            0x422538B778149307ULL, 0xC489987449CF3856ULL, 0xB0C84315D4D520F3ULL, 0xEAB9E2DFF44AE27AULL, 
            0x9B3070D3F4F067C9ULL, 0x475E177F31555D28ULL, 0x5C26500E87C8EB9EULL, 0xFA4408CEAEC4B0B8ULL
        }
    },
    {
        {
            0xD4891688E476BA3AULL, 0x962A2E8232030749ULL, 0xB02F5F5A2D253BEFULL, 0x0E7ED58264000356ULL, 
            0xF80A538EEB043E5BULL, 0xA2235D323B1D8F15ULL, 0x27A6201B08D37255ULL, 0x33281FC58E432642ULL, 
            0xEA4ED0EFDA001B3CULL, 0xDBB32F2B7F7FB4A1ULL, 0x23E17C42944BC128ULL, 0x2BD17106E8C8226EULL, 
            0xD48181D92AE352E6ULL, 0x70CC847C5753E90DULL, 0x71EA0E512CF853ECULL, 0xC06950AAB8BA771EULL, 
            0xD880824D8B07D24BULL, 0x9BD042E4BC0E86D8ULL, 0xEFFE50311D2695FCULL, 0x47047B7D3A70A649ULL, 
            0x8DA0FDF73E228392ULL, 0x8D10FDDAC4421266ULL, 0x0A3BBA6EF811E1E5ULL, 0x76ADD72BC414D8C5ULL, 
            0x805E9867A92C2FD0ULL, 0x8970EAD1FA459C3CULL, 0xCCA8B853184929EDULL, 0x5259C08B1BEF73B7ULL, 
            0xF61D21663A177630ULL, 0x93E2CE9CFB795A8FULL, 0x7BB25D529F61B302ULL, 0x5C2780B616CD5FE4ULL
        },
        {
            0x095140D37D5235A3ULL, 0x2A310A1F2E5B8AB7ULL, 0xD22955DBE2A17B00ULL, 0xD3C0FF65E884D961ULL, 
            0x3944232B97411D17ULL, 0x3CBF4B3B1D8A6AE3ULL, 0x7409473B942D687CULL, 0x78107D24F6EF72C7ULL, 
            0xE5ED15C9C65B10D2ULL, 0x05E8773B9FCA4BCBULL, 0x06B96CC7A241EDC1ULL, 0x66A27EECFCA3E3C8ULL, 
            0x9449FA6CE3B2B972ULL, 0x38CC5E157284C063ULL, 0x586E00437B4A59B1ULL, 0x6C68E0C5E56AF90BULL, 
            0xF99C52F593558524ULL, 0xE4089A9ED34B913BULL, 0xF64F91413FFCA1F7ULL, 0x78301EC3716AF49CULL, 
            0x8C452F591A5422A7ULL, 0xFC65421F9CEEE67FULL, 0x66B24424D40E1FC1ULL, 0x96C68D4C286F4143ULL, 
            0xF853EFF940799CBAULL, 0xD7AD9948B0AD7CB6ULL, 0xC2FD61453D9F10B2ULL, 0x76270777FC627DDCULL, 
            0x03A0ACF794746E63ULL, 0xDCF05AE7C51DD229ULL, 0xF721A23AF6316F38ULL, 0xE441236F6A9E9EF7ULL
        },
        {
            0x1505F30C1BC02C4CULL, 0xD8612AA32CDC3F2FULL, 0x45699A957D1F3126ULL, 0x29893AFB8FBA2A12ULL, 
            0x37DC6F674BE66C41ULL, 0x811C6F4254E539B2ULL, 0xD7D5BE3635BF213CULL, 0xE60A1C1A51F93CC7ULL, 
            0x3057CB303C150FA1ULL, 0xAE02C4F191C3F698ULL, 0x069644D1691CA33CULL, 0xCFEC443BBA95129AULL, 
            0x86837332C40BB306ULL, 0x168166CB4D10BF4CULL, 0x7B762D423F6243CAULL, 0x2AC244CE1CB04C29ULL, 
            0xA39C58F33F54A1C7ULL, 0xD988ED20CEFD8963ULL, 0xEAFED47483066375ULL, 0x7EC6A5056E0D8DD8ULL, 
            0x280098924ECD4DD7ULL, 0x97FCC5250DF16813ULL, 0x453E93B3687C3656ULL, 0x6D01E549BFD32B6EULL, 
            0x216306BC8CF4CBF5ULL, 0x8B96730606CB9E22ULL, 0x3AD11BFFE44F9153ULL, 0xDBBF70216FFA9736ULL, 
            0xB1DD9850D9CD06EDULL, 0x0A3B65CCB0806BC5ULL, 0xF1E4184C1C4B1420ULL, 0x665745BAC10B939FULL
        },
        {
            0x17A5D88247C0BB73ULL, 0xFC8638C97BFEE2BBULL, 0x6189855730E677EEULL, 0x778C015D77AB7254ULL, 
            0x4BD46DB352AD8808ULL, 0x96B8FEDCA7B410B9ULL, 0xBBA3FB2B16D24965ULL, 0x0F7B9FA6D269BCCBULL, 
            0xB58405B5A45D9EF6ULL, 0x9C04DC4AE21D94F9ULL, 0x431043F17D29F90BULL, 0xDCE6B76AAAC0EA22ULL, 
            0x51E3714999FFA9E4ULL, 0xC9F84DDEF37FD9ECULL, 0xB60CF28BB56B12CFULL, 0x160EB17BC7032B4CULL, 
            0x705F46C5961F76C3ULL, 0xA501A255938543D6ULL, 0xF36BD33A19BA08BEULL, 0xE9D46B116341A938ULL, 
            0xF8A542D512E69CC5ULL, 0xAEC67CD7C8B5BF0BULL, 0x4961F8CDF65BC427ULL, 0x2BC2B04DC7383A7DULL, 
            0xAC7FF22D7006C031ULL, 0xAEB5E7AD1913FB73ULL, 0xE99A08F5943A64E5ULL, 0x49FA3870F33CECA5ULL, 
            0xFB55DCE2478C4BB6ULL, 0x2705C7AEE5C29947ULL, 0xFC674F18AC0138DEULL, 0x485FD81F012E65AAULL
        },
        {
            0x75D54D9BE1F03676ULL, 0xB513A879C268355CULL, 0x21564F49F7844C24ULL, 0x3E7F021D87B88B01ULL, 
            0xA06A5EC65E01D5A6ULL, 0x86D6A6E0EED5CB61ULL, 0x4301029647F60934ULL, 0xB2C72393849A48EBULL, 
            0x9B78AC43E6BE779BULL, 0x52D7E3CE6BFF3265ULL, 0x94DF0C9159DC42ABULL, 0x90C6044E055825BFULL, 
            0xC4E4BE0B890FB6E8ULL, 0x9863D21D8A27C56DULL, 0xA4142C28D533F0CDULL, 0xF984E7E286EE186AULL, 
            0xE751B1AF142B3175ULL, 0xC6446224371C0891ULL, 0xB3C7286420994670ULL, 0x4859E1C2EC634882ULL, 
            0xCD0C0C6A61F6C8AEULL, 0xAC0B7F9EEFA6B541ULL, 0x9EDB630144965F30ULL, 0x43B1C40590A7F7F7ULL, 
            0x12321852E563DC10ULL, 0xDEE87105146BD15EULL, 0x50FBFE2CCFA7453CULL, 0x0BBE4568DA3D84B5ULL, 
            0x1BAC0E3591608041ULL, 0x977342B137ED30BDULL, 0x510AE036D8D1350FULL, 0x0C995C87BE2E6E63ULL
        },
        {
            0xCA1C8CE8CFC7FB0FULL, 0x56FF82B082F1CC4FULL, 0x9182D59332DF9589ULL, 0xA3D75D97F4B47BD2ULL, 
            0x5EE2547342A31572ULL, 0x3C53BD65F0B56020ULL, 0xA47794CFAEADDAC0ULL, 0xC65A1DDDD348999AULL, 
            0x8EE9B79524205EFDULL, 0x8AE043512E3FEF3BULL, 0x70181ABDC95047D7ULL, 0xD05C8754FDD5A5BFULL, 
            0xFD67169202618EFDULL, 0x966902C5FC012564ULL, 0xC2358AA02FC7428FULL, 0xB498C21C56C76E3FULL, 
            0x39523E2899941A7AULL, 0xAF0EADEE9F04AD47ULL, 0xD39206988F3FFD21ULL, 0x3416C614710FE94DULL, 
            0xFB28247497342F33ULL, 0x401B865D6B3792B9ULL, 0xF8681A07B88EA0BCULL, 0x4819F1169E8A57CAULL, 
            0x155E0E6EFB12F759ULL, 0x0886E0410FC7FC3AULL, 0x225D5B75A79EFAA6ULL, 0xFE6733A70B8C8762ULL, 
            0x8B9A186D4A5C7594ULL, 0x29123740F235ED2DULL, 0x24EA63548B7A0DBFULL, 0x4A6F1ABBCF8DF88BULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseFConstants = {
    0x728A17FACE654942ULL,
    0x87CCD82B6B23AC9FULL,
    0x17D96E298B69C734ULL,
    0x728A17FACE654942ULL,
    0x87CCD82B6B23AC9FULL,
    0x17D96E298B69C734ULL,
    0x4C09F52FC7EE6052ULL,
    0xE2C5FB2050B7B322ULL,
    0x0C,
    0x79,
    0xA6,
    0x49,
    0x84,
    0x23,
    0xD2,
    0xB0
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseGSalts = {
    {
        {
            0x15D1F9911D1EFB99ULL, 0x9623C2ADF652A640ULL, 0x0109276149247434ULL, 0xB33617AFE5033B4FULL, 
            0xD080520B95BD4C6DULL, 0xCD3638A09EDFB786ULL, 0x8AB5473361E477F5ULL, 0x7904B504980B8A66ULL, 
            0x07CDA8ABC8C7EC7DULL, 0x780771CECB3D4F37ULL, 0x953EEE661F66E3C5ULL, 0xEBF5928AB4F71CFEULL, 
            0xEA47CD6ACF321765ULL, 0x7D7D62AB1F4BFDB9ULL, 0x464D0D5FD3E4B6C2ULL, 0xD8F6281446BA1F8AULL, 
            0x4E9C036B6248FDB5ULL, 0x0D7065812439475EULL, 0xF36EF650A1176B70ULL, 0xDE9A3729E6C87032ULL, 
            0xCDD56E6A4B1B8AB2ULL, 0xD09ED9368DD623BAULL, 0xFB8B2C47E54A7CF0ULL, 0x901897D0DAFF8BD5ULL, 
            0x8898E6AE1C113302ULL, 0xEB2E2F982EBEAF37ULL, 0x30F892ED5EA780D5ULL, 0x5B65BC354BBF275CULL, 
            0x4A8A4B61D77021F4ULL, 0xB2E75F287FAD12BAULL, 0xE7B77DA2A2629982ULL, 0x60958A659A3B232FULL
        },
        {
            0x4B59E1F2717FCAA8ULL, 0x2F199DFC5754E4A5ULL, 0x32A94924E0F1A13FULL, 0x5624533C3292C83BULL, 
            0x9C269A478D3A39F0ULL, 0x5E795C43AA78CB58ULL, 0x0B62831821C2A338ULL, 0x3C78D41C108478F8ULL, 
            0xBD858907B8BF2FDBULL, 0x8B08BA29ABFC1914ULL, 0x99D901409BABCF84ULL, 0x25F73ADEA8E22EA4ULL, 
            0x43A23871FF6ABBCCULL, 0xB95BEB28DD89F2A4ULL, 0xD79D782383986E84ULL, 0x48244AF4D76AE8CAULL, 
            0x6C3F1CFBC8116FC6ULL, 0x3588022334464C9DULL, 0x104E5DE73AF802F4ULL, 0x13E5ADD2B45C9820ULL, 
            0xAB1C073A3E8F60C3ULL, 0xB951199452E48FD6ULL, 0x5948FA354BDB0EEEULL, 0x8D613325B595B934ULL, 
            0x984B6446EF4EF178ULL, 0x05433850EC3213B8ULL, 0xA892076B9731804FULL, 0x17B74A3CC69DDDDBULL, 
            0xAB2E7F9156A8BE40ULL, 0xC70FACAAD10DDBA1ULL, 0x8541D8C5D6E844EFULL, 0x8ADA73799F18EF37ULL
        },
        {
            0xBCD9E50DE42D2526ULL, 0x09B617862374D9DFULL, 0xBC16F5AFAC842F7DULL, 0x1B4E08A00C93F647ULL, 
            0x2624A3F7DD7E34FFULL, 0xC2B9D7D8EE53B1EEULL, 0xB2E79674FD4FFF31ULL, 0x784AAB24629CC05AULL, 
            0xB15731D8D87E115AULL, 0x2617539C1646CC44ULL, 0xD36B7621CDA28393ULL, 0x2607B87E30881B68ULL, 
            0x091A2AEC227EC767ULL, 0x8431309B3BA71A12ULL, 0x1343D4B825F41660ULL, 0x2AAF6723D8A4C705ULL, 
            0xCDF1E52D6D860CECULL, 0x119DF3768E217BE8ULL, 0x69A92D7AF377E4CCULL, 0xE5CD86418D497487ULL, 
            0x14911A01F973C3BCULL, 0xE155244C16B41DF7ULL, 0xCD7DE995C8B6BFA8ULL, 0x2E792CB3F13A1919ULL, 
            0xD1353C9A421D795AULL, 0xA0145679BB92D105ULL, 0x61F886A65720ABDBULL, 0x556E007704A299E9ULL, 
            0x373BCD281AD80BCCULL, 0x726B0C3BBFDCABCDULL, 0xA606768C8739F74FULL, 0x582E5643413D2F82ULL
        },
        {
            0x47ACC9BC166B601AULL, 0x86C8E97E69CD323EULL, 0xD9BE7D9E70331699ULL, 0x9A9D25334EFA7599ULL, 
            0x04567897D4289DD6ULL, 0x72386B06F4714C5BULL, 0xDA6F334AE47EB2B3ULL, 0x87CB81BB0418308BULL, 
            0x6C5678B1505DCA80ULL, 0xB6EDA2881C94B098ULL, 0x733C3963B89E7862ULL, 0x6CB501B7BA58D616ULL, 
            0x6DC62DD58F1DB349ULL, 0x1A104A386050ADE4ULL, 0x004A1BEADC14EDD3ULL, 0xFCB20F18D352D3C2ULL, 
            0x0FFFAC980A0A29B8ULL, 0x33769B26F230D4A9ULL, 0x4EA6312A47C78662ULL, 0x0780327F0AE67E99ULL, 
            0x56C977113ACA5325ULL, 0x7909B4D646D1242DULL, 0x50BAFA275F892447ULL, 0xEC226D22BBDBD3C1ULL, 
            0xE6A754C01F17ADB9ULL, 0x65A7DF6B3E3539B0ULL, 0x83929865125E6EFBULL, 0x88F8212FD9125454ULL, 
            0xE359D975F66B3EC8ULL, 0x0D1F1A7698D89D11ULL, 0xDF04CE6588C8ED96ULL, 0xA2ECF048CE3B72B2ULL
        },
        {
            0xC4E199D1A2EE7EADULL, 0xA082E668D04D29DCULL, 0xC07C64F1D7AF651CULL, 0x812751B5F786DDCAULL, 
            0x7B9D569718C3B7A3ULL, 0xDA846BC8C28EC650ULL, 0x96D12A121531AFB6ULL, 0x512D36D1D420CE69ULL, 
            0x4A114C947BD7104CULL, 0x234BF449A8D390E4ULL, 0xCE2E0C79FAEF617DULL, 0xD5D121F312556561ULL, 
            0x1E0720D93F39572FULL, 0x3FD27F1A11325158ULL, 0x1F178E5242044C1AULL, 0x20838FF3F5518897ULL, 
            0x8A45650C80C58C1EULL, 0xFA60B886D2343112ULL, 0xFD756934109AEB69ULL, 0x158BB913B85C4954ULL, 
            0x79B0E9AB714A136CULL, 0xDE752A20658D0131ULL, 0x344FA4EC96210ED6ULL, 0x55ECBDAD11353234ULL, 
            0x91CDB41803BBF08AULL, 0xBEDFE21627CA1022ULL, 0xF68D470EE90DEADCULL, 0x65FC875ED7023A0BULL, 
            0x77ADD58E2EB45785ULL, 0xF3360F1EC679F6E5ULL, 0xEA3F2F60235161B2ULL, 0x06C08FFDF0428D93ULL
        },
        {
            0xD2315A8973577B0DULL, 0xB8B8C48766237554ULL, 0x738A37CEC6C03654ULL, 0x041EB0E8BE137BB6ULL, 
            0x160F6C332FB41BBCULL, 0x161CFB8B2882BCCDULL, 0xF1C706A6F237E582ULL, 0x1AA0575C6A12EE19ULL, 
            0x4665CEBAE8C25658ULL, 0x54AF6720B1462D86ULL, 0x93D6AB3526A8E5DCULL, 0x42ECE4DCE9E6B384ULL, 
            0x0F535819E15C39B8ULL, 0xEEEA19D977063540ULL, 0xEAB10F4F919D377BULL, 0x738657A6E59A7558ULL, 
            0x92B57143AD32F942ULL, 0xCE2C2A78BEE92ABFULL, 0x695A316A2039A4ADULL, 0x5ADD4273A3AD0E20ULL, 
            0xF6D237C14DC182FDULL, 0xCB1E29BCD9301365ULL, 0xA9D21BBCBB2251B1ULL, 0x96F25EBAC56ABB72ULL, 
            0xB691D099E3059208ULL, 0xE2B4F2F60FC98386ULL, 0x0B9E4819A89BBFC5ULL, 0x6A6CE80D77E137C3ULL, 
            0x528C7458B3BB186BULL, 0xC3FAAF6AA4A01A49ULL, 0x614EDCD2AC9827AEULL, 0x6E67AA720F7B500CULL
        }
    },
    {
        {
            0x586904EA836F61A4ULL, 0x00B694B8B904F961ULL, 0xAF636E172ACABDC7ULL, 0x2491737B71D630E7ULL, 
            0xBAA2F51B3423861EULL, 0x64935AF89C0B7E3AULL, 0xA7371E63879A7D64ULL, 0xE77CF668A0B08F8FULL, 
            0xCE7702D236FDB8F2ULL, 0x6F4AEA110C6CD3E6ULL, 0x4513994A49CA1C41ULL, 0xA9BCF890D2AE8F3FULL, 
            0x9363031F362CD2CEULL, 0x494091BA7045D47CULL, 0xE42E1BEDBA27E63BULL, 0x932F597215794723ULL, 
            0xCB2528E5EB715FA0ULL, 0xD21264D5FFBE58E2ULL, 0x795355158646D752ULL, 0x9BEA77915A845E06ULL, 
            0x4D4DD30CCB39FC77ULL, 0x0B9152C7325823A3ULL, 0x86F5CAEA733D012FULL, 0xBFA1FE8C39E1CB37ULL, 
            0x3D7BA5A0EE2FAFD8ULL, 0x368C8C7939EB3B41ULL, 0xF8EE9C2C9BDC701AULL, 0x5775E18A642F91C0ULL, 
            0xDDF8E225FFADA630ULL, 0x5CC9FC3E4258DAE0ULL, 0xA5DDAC03DED9025DULL, 0x550F020675F3C54DULL
        },
        {
            0x778989B840F7CDA6ULL, 0x61062EA2D5FA316AULL, 0xE89346705470EC1AULL, 0x0BF57CE506CA3AC8ULL, 
            0xF7D0AF48A4C1328DULL, 0xEC6B8E717A82664EULL, 0xB4157683CD3018EBULL, 0xB8D8FEF14469E4F3ULL, 
            0x5B5EC59E1DEFC315ULL, 0x42733F53D8C3B05EULL, 0xE2E3098D5567E7BBULL, 0x06E768EFD8F5B75AULL, 
            0xB09B68EA71BC20A4ULL, 0xC06C6B7558DFF68CULL, 0x96DB8046280344D8ULL, 0x47D68F87302D2AC5ULL, 
            0xD2178631B6C14E09ULL, 0x3F4F063BE7773841ULL, 0x28B4864C9FAB3620ULL, 0x742FFAC8A3872C18ULL, 
            0x3B5E135C6C0B984AULL, 0x536551AAE2DB3232ULL, 0x2AC5EBE17B1C0B61ULL, 0xE572FD7CDBEA21C2ULL, 
            0x46231EACC6CBB5BFULL, 0x73ACACED73217581ULL, 0xBBA7E0273E6A3725ULL, 0x2A01FCCF53A17512ULL, 
            0x45A1D2C859ABE4C7ULL, 0x993F8FC3B58B0A68ULL, 0x6F0A07C0B146E886ULL, 0x4BC7482C23A12D5BULL
        },
        {
            0xFC00AAC68C657D4DULL, 0x49DFB3632888A7B4ULL, 0xB3A35C7C78CC3429ULL, 0x7DB39F0D3FC244C3ULL, 
            0x7CD83A6644E38AD7ULL, 0x5F2F82441047CE70ULL, 0x0EE5F8C06E5EB717ULL, 0x7911CDC97D77D4C8ULL, 
            0x9962DA1578010621ULL, 0x693AF6EF2F8B84ECULL, 0x58492E686DF68A77ULL, 0x28AB005CB3ACB3F4ULL, 
            0x603137685B3610AEULL, 0x54040CA0225720DBULL, 0x3EAEB9F04E938C68ULL, 0xAA9267C9B9DA5B59ULL, 
            0x0F17C8E2ECDDA7C2ULL, 0x5A5FEA6F1D929DCFULL, 0xDAA06C66F328E4CCULL, 0x9F8F99251379DCA8ULL, 
            0x19296CDED8273C32ULL, 0x0CA5632DCC988F29ULL, 0xE65DB6D5881D9F9CULL, 0x37F3FFE810A87419ULL, 
            0x3D9900E783ED7F01ULL, 0x23F586D153BA3D97ULL, 0x4E6CA30653611456ULL, 0x52DF6D57462842CBULL, 
            0x1241CA506F327A30ULL, 0xDD53F6B0A67F253FULL, 0xB268D31D0C06109BULL, 0xC39283CD402ED6E2ULL
        },
        {
            0x30FF4B89F9BAE962ULL, 0x16FE065832AB8A2DULL, 0x76DA517FA865FDDEULL, 0xDDFCE170630B9B86ULL, 
            0x8D59B969B02A3B63ULL, 0xC7F2565983CE7DC0ULL, 0x36F09A187A410BF4ULL, 0x7257E288DB0DCDC0ULL, 
            0xBD4B45B9EE11653FULL, 0xD7D89515AA2D9452ULL, 0xAD43A4369B4F77DDULL, 0xD256539926B2C67EULL, 
            0x882EFC991448951DULL, 0x581FA73856FA4CD6ULL, 0x6E151C5F36B8FBC7ULL, 0x38088DB30F3BD1BAULL, 
            0x6D872C07D0C6A652ULL, 0x57E05CFA496E34E9ULL, 0x1CA37578770BB253ULL, 0x468858BA31943D7DULL, 
            0xD5E2F4099DA96BFBULL, 0x7C2C976ECB1E210EULL, 0xD9F8933A61321E1EULL, 0xAFD3EAAD64B5F25EULL, 
            0x6937112E23C52099ULL, 0xFC7F8B2610D3AB20ULL, 0x00E70A7BA5CEEDCDULL, 0x3E911522295E95B9ULL, 
            0xC2C6AE1CA726B726ULL, 0xCA810062D7A4ED98ULL, 0x22D09A9B66282751ULL, 0xFE7CD3D99E08E6FAULL
        },
        {
            0xB5E50D7D34A1B029ULL, 0x765EC62B2E35E09CULL, 0x6077E507C5D13FE6ULL, 0x743D4CD93D1FDA19ULL, 
            0xCE181644D45AE581ULL, 0xB61938B13E9D5362ULL, 0xD6DA390A324DC421ULL, 0x7F955043CD8E5C47ULL, 
            0x9666EA2B6C73A8DBULL, 0x22E745A190B5E8D7ULL, 0xCBBBD707B9340C38ULL, 0x958B6A426F7283C8ULL, 
            0xB26D4831A8AC9146ULL, 0xDD939C4A55A086BBULL, 0xA59C23906C43D566ULL, 0xCF2BA8DD3E235668ULL, 
            0x2FFD189CD8840B94ULL, 0xE7564B9D783C422FULL, 0x77EF26A33CD627C2ULL, 0xF8CCE1CC118096FBULL, 
            0x95B9A06DF346ED49ULL, 0xC5959B2F8C4830E5ULL, 0xD9DD6E8B9D1F5D02ULL, 0x6977BE922CDEB950ULL, 
            0xD0C83F6FEEAB70F3ULL, 0x4C91A33DEEB35410ULL, 0x300DE844BC3A2446ULL, 0x6BF37D54492AABFAULL, 
            0x4205DC3E05A3FC57ULL, 0xF9018880F7239971ULL, 0x03BC3C430F97A618ULL, 0x2D9C25EF912B3A3BULL
        },
        {
            0x8F47B73163B8E769ULL, 0x0080432FF875F740ULL, 0xB30C29B7FE34C831ULL, 0x13FFAFB43B080C46ULL, 
            0x79A02A45A905F782ULL, 0xD560573AC364CB98ULL, 0x0DDD19BA7A357E99ULL, 0x6EC478DEFFC1354DULL, 
            0xB8F9A94714A536F4ULL, 0xDA174B6B819CB0ABULL, 0xCBEB226A8DAFFC44ULL, 0x5158BCD4790ECC1DULL, 
            0x8679191475DA5A0CULL, 0x161766ACC77462D6ULL, 0xF20C6F67B28684ACULL, 0x0F335968089DABD5ULL, 
            0x94D351552336EFC8ULL, 0x49DE7E6627FB0B9BULL, 0xFC3D8FFF4E01E00EULL, 0xB17107FE8CC22CA0ULL, 
            0x91171659E6EEB437ULL, 0x9F37F4AB18100F53ULL, 0x1CD6D2CFC5708583ULL, 0x127933359F636C07ULL, 
            0xD219C4DE33493107ULL, 0x546444875CBB427FULL, 0x94308D398D47D672ULL, 0x4B0B2209B6ED97B8ULL, 
            0x95F8316CEC12B4B6ULL, 0x5942E58520CC68ACULL, 0xA9E8FB98A6190A9AULL, 0xF904FCF2862F4F24ULL
        }
    },
    {
        {
            0x779BB2A7DE11AED3ULL, 0xE7993B99537A453DULL, 0xD9B3884116827FCEULL, 0xEE44AC63DD2CF034ULL, 
            0xE8D0FD2D90C16E12ULL, 0xE33B95BE590AA8AFULL, 0xD9365C1168A33ED3ULL, 0xAB372D1B79BF7EDDULL, 
            0x20116ACD9E9ED6BAULL, 0x2745D09849C5A49BULL, 0x3D1F0D220A53551CULL, 0x24D3F762B570DAB9ULL, 
            0x9A1E86B29D06BFC8ULL, 0x55DD68FAA737C752ULL, 0xC96ECCC66B33C095ULL, 0x41A6A75BEAB810D2ULL, 
            0x3ADB0AD013A738D7ULL, 0xDE916490E3C89F88ULL, 0x0732A124EF864F5CULL, 0xDD6FBA013009E477ULL, 
            0x5FAD4D467BB2828CULL, 0x40D8E0D1C023F9B1ULL, 0xC9B3C104698CBFB0ULL, 0x486D4B274293A7E0ULL, 
            0x586AAB46863024F1ULL, 0x3AD7C0E523957F2AULL, 0x84AD57EAE81092A1ULL, 0xE967A6E9F3FDC66AULL, 
            0xB42321E31EB5C81BULL, 0x90268C8F3479A379ULL, 0x68E91A7721701162ULL, 0xAC4C5FA914F41984ULL
        },
        {
            0x62CA7DF7938BA675ULL, 0xDC91AB4FF9EF5855ULL, 0x717372399378ECBEULL, 0xDBC7D043630F5E75ULL, 
            0xA58BF595ED42AD4EULL, 0x746C298DF6DA9660ULL, 0xA0BCA7683D720E38ULL, 0x6239FB33CDFD04DCULL, 
            0xB804620CD3AC3349ULL, 0x7D52C31E84A38160ULL, 0x6350D532932292DCULL, 0x8F8B3BB76C46F6B2ULL, 
            0x1675C56B792CE9F4ULL, 0x8CACBDC3ED190818ULL, 0x7B809AA8971453D4ULL, 0x698A4BE2B65E6F3FULL, 
            0x5E44D556303E00F3ULL, 0x5485B4F8344A3239ULL, 0x4D3482EB7FFAF18DULL, 0xA144FCF36874DA99ULL, 
            0x4D69178634C449A2ULL, 0xEC9051FAD24B88EAULL, 0x24A41CBFB0CF940AULL, 0xC98EAD178AD1879BULL, 
            0xD810CA742EC43758ULL, 0x70B297E466263502ULL, 0x025BAA46375A98B8ULL, 0xE707290BC577626DULL, 
            0x9451E8A349110CA3ULL, 0x377BB01DFCBFDAA5ULL, 0xBE611181E117990DULL, 0xA04EF4BBD872DB02ULL
        },
        {
            0x77E0728BF2FE3D4DULL, 0xBA30F791724FB228ULL, 0xE6BC5CE0D3514D60ULL, 0xBB7794EA28BF3179ULL, 
            0x7DC6340326BCC881ULL, 0x9A3EB2FF9B3ADD8EULL, 0xCDF05666C83A7545ULL, 0xD9F595FBBA6E246FULL, 
            0x317929C855196C5CULL, 0xE99F78F6250E0150ULL, 0x4F2E3A04B88AD5E6ULL, 0xA3A392CDBF7C5819ULL, 
            0xB65A8285ADC140EBULL, 0xEB43F529417AFC73ULL, 0x15305906BBCC658BULL, 0x8E8E1E4D6C357F42ULL, 
            0x50A2C7D629C51D38ULL, 0x9C373C629FE2C4F2ULL, 0x1C6442144B795826ULL, 0x17B501B610093FD6ULL, 
            0xBCE00C000279B343ULL, 0x48484E395D8D51B3ULL, 0x496B8C2EA9411A64ULL, 0x414E2670C3A6602AULL, 
            0xCF016E4F0A64CCFEULL, 0x18F9F3E7B69CF2C0ULL, 0x66E0EC3CE15CD3C6ULL, 0x5C688307FDEF40F3ULL, 
            0x109BF5882DACD952ULL, 0x4FF1D7DEB4EFBA3AULL, 0x6524D93A33DE9370ULL, 0xB597ED8EE67C154EULL
        },
        {
            0x8D9211CD339AA1D4ULL, 0x470FC17EEC154B96ULL, 0xFBD48D1ACA180B73ULL, 0xEE39816399283636ULL, 
            0xEF9248DCD738E2EFULL, 0x3036345DB1BA99BDULL, 0xA9AA3A33886FB1FCULL, 0x9426D5E1192C6DB9ULL, 
            0x54A76EE02E2A55D4ULL, 0xE7C35AA2610F834EULL, 0xD908085C7942FBE9ULL, 0xDA3F50D4C7F76BAEULL, 
            0xCB410F86DAA832C1ULL, 0x7A349A096C63914FULL, 0x13DD114923F8669EULL, 0x99ACBE6A64ED26EFULL, 
            0x8DB33B414273D58EULL, 0xE12C0A2FA41FF763ULL, 0xE35EACB671512277ULL, 0xC004CC23689AC0C4ULL, 
            0x656FE4775120EB18ULL, 0x5084D0F84A3C4AE0ULL, 0xF2FF4B1BE829F066ULL, 0xBC1B0A19B1C54AF7ULL, 
            0x94A31A771D90125FULL, 0x2E1CB7B0DA10ADD3ULL, 0x862407C2C4AA855EULL, 0xD56F54E9A713562AULL, 
            0xD17F5F7DD5FBB545ULL, 0x85F638ED6848532BULL, 0xBFFED9D594FBC821ULL, 0x60FAE0B31C2A6E54ULL
        },
        {
            0x9EED821A3D2D874AULL, 0x50F1FF7E92C8DE7BULL, 0x0D9BDAA64C06EDEAULL, 0x2E367354C518EE6EULL, 
            0xFAFF19EF9683BBF1ULL, 0x0475EA7E5C85805DULL, 0x488E5176E5F7919DULL, 0x4ADB2C62CA9EF22AULL, 
            0x18F93EB3A23E4F19ULL, 0x04F15FDC16B963F9ULL, 0x428A8B89B3601D45ULL, 0xE000D568D015ED56ULL, 
            0xF0A6B2A5D484F358ULL, 0x0DAE06B288D5DEA7ULL, 0xB6A0F50210EF0846ULL, 0x130724EF23C5E07AULL, 
            0x0FE67DB5FD5A9136ULL, 0x591A160EE28DADE6ULL, 0xC4D8129976784506ULL, 0x199B922EFA6E6AE6ULL, 
            0xBEDF7641962AC0BFULL, 0x77AF4E7AD51265ADULL, 0xA988744B9D5FD626ULL, 0xBBC9F8BF31027185ULL, 
            0x7145A5A87AED7BEEULL, 0x95DEB5E72E1C6FB6ULL, 0x799B7E9D92DD8DD8ULL, 0xDB624D919CC275C3ULL, 
            0x1BA81E839FEB1466ULL, 0xEDD7F6B440A9B3BFULL, 0x7A225A4C6809BE48ULL, 0x801E7EDD463902E7ULL
        },
        {
            0x55A6A7DADCC29189ULL, 0x53A114BE853D6CADULL, 0xE8B5CFC68BAE07B0ULL, 0x0C4E28E7157C8336ULL, 
            0x885478488CA69CD4ULL, 0x595CDDBC98882F3AULL, 0xF595B8C3B9830AD0ULL, 0xD5F76674079B01FBULL, 
            0x69F16366E6DE7570ULL, 0x8D744A009B010DC6ULL, 0x4757CBCDDCDB89DAULL, 0x1F75D0BED3AA018BULL, 
            0xF201B14E85D7A6A7ULL, 0xD61048100DE762B5ULL, 0x501313404E258C50ULL, 0x3C3CD0A7D97745E4ULL, 
            0x184A2EEEC46E7C12ULL, 0x0BB11BEF0C111BE8ULL, 0x407724CE8FD1B019ULL, 0x70F61AD3A3D3863BULL, 
            0x6F280FF518FCB474ULL, 0xAB6B1F9105802597ULL, 0xE872FAE91E3E4088ULL, 0xE09B4A188AF55AD9ULL, 
            0x89FC279EEB15C4B5ULL, 0xD1EBF74F31BC8BF1ULL, 0x97B3568846F34310ULL, 0x764F9186AB918461ULL, 
            0xC02BF2532F24A618ULL, 0x5F2D23E79D714923ULL, 0x57D7F67344874A43ULL, 0xF7B45B14610D1AB7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseGConstants = {
    0xA5E9946FE768AD14ULL,
    0xEF7439A493B94BA6ULL,
    0xE6E2718A43322BF7ULL,
    0xA5E9946FE768AD14ULL,
    0xEF7439A493B94BA6ULL,
    0xE6E2718A43322BF7ULL,
    0xFD62B8D4CB6A186CULL,
    0x20B6C0B747DC93C4ULL,
    0xE4,
    0x36,
    0x3E,
    0x02,
    0xF6,
    0x4D,
    0xAE,
    0x8E
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseHSalts = {
    {
        {
            0x1D4554264D3BAE4DULL, 0x6F73E9327EB3E7C2ULL, 0xF14027617E509C95ULL, 0x966895D77B83F2ACULL, 
            0xC349A666D855E956ULL, 0xA93A1389D4B6F91EULL, 0x25D3A7A5BA979D64ULL, 0x76D700222875D90DULL, 
            0x3448BDC3A6C6EA45ULL, 0x8F677708696D9686ULL, 0x8F3FE30CABEDC13FULL, 0xCF1CA8D89645C2C0ULL, 
            0xFC7F710BCB27D522ULL, 0x0F51E9530B3493BAULL, 0x015C3A483683D346ULL, 0xD47E2A20FA5DA2F4ULL, 
            0xF06E861AEBD9B9DDULL, 0x8667EABECEF34FD2ULL, 0xED6E982E772C823DULL, 0x6DE6B4749D7F7009ULL, 
            0x402AD65F539A44F0ULL, 0x48889D2F08089D1CULL, 0xEB74FF4E2869AA54ULL, 0x55556B5E890CC490ULL, 
            0x033A85A8E3A1BB3FULL, 0x4D7206255BE587D7ULL, 0xEE01E68502F6D6CAULL, 0xA95CB5C853D897B9ULL, 
            0x5E056B3C71C8F26DULL, 0xBF18A48981846C3EULL, 0x72EF2717A658CF04ULL, 0xF0F23197D7F3B291ULL
        },
        {
            0x44571BE470B9438BULL, 0xCEE15E5EB1C1545FULL, 0xB757A7BACEDD626DULL, 0x338A26A008F22B35ULL, 
            0x80E95BB763C8125DULL, 0x34F08D5D6E34F61EULL, 0x3B8D239A6DA7143DULL, 0x75652FDDBCA24B86ULL, 
            0xB74DE106805C7E64ULL, 0x1C25B25E55568389ULL, 0x889A723B61CA4669ULL, 0x4AC6987EEFA43AAFULL, 
            0xE45632BB9F88A05BULL, 0xEBD20D4C3F32D70EULL, 0x7D457CF424EA8982ULL, 0x5BCC059078010901ULL, 
            0x64B6C359804BEE6AULL, 0x976ECE0B8527D2F5ULL, 0x8D122AB90195B3E7ULL, 0x83B04C8EAC254B08ULL, 
            0x1006E883975A09CEULL, 0xB36CFB01580ADB24ULL, 0xBFEEE84271957A29ULL, 0xD5B89A5D3F167DCCULL, 
            0x8FFBC19EF73B206DULL, 0x5198ADFD6BBAA0D2ULL, 0x6D2BE168FAF00622ULL, 0x59613107359D5A9FULL, 
            0xBD1426CE32CCC56BULL, 0xE07EE25E0E6AD7B3ULL, 0x278D402F1FE5D042ULL, 0xE4FE9A822657D8B9ULL
        },
        {
            0xC49C47C91D1F946FULL, 0x16BA2706A52EE80CULL, 0x33C2D7BFB6A7E6B8ULL, 0xE2363258A182E54BULL, 
            0x5AC81DE0A631FE4EULL, 0xF3C1CACEB9E6F29FULL, 0x4DB88350270E9167ULL, 0xB6D9400B5C4B9B15ULL, 
            0x44E9D14C5B544E38ULL, 0x6B7C564841C3FEF2ULL, 0xF32A889BED77A9F5ULL, 0x4924231A62A55C36ULL, 
            0x420FF912782183ECULL, 0x261BD14E9690E516ULL, 0xAA5CFD1FF2DC7EE0ULL, 0x7FC2D9447BF4AE9BULL, 
            0x03E9F008CDAACD45ULL, 0x323AF352810F6F6FULL, 0x80B4620012CE03B2ULL, 0x1A96D9EC57C7793CULL, 
            0x70E0ADC5C52CCA6EULL, 0xD3D57202F2D574B3ULL, 0x98F202CF3BA2A014ULL, 0xB9AD0DCBA41849B5ULL, 
            0x4C5D48AB6A1E8964ULL, 0xF4A07CE47424146EULL, 0x273037619A5DAABDULL, 0xE0857C9D2FD60987ULL, 
            0xBFDF331C32C73E79ULL, 0xDE02F0745B07276EULL, 0x026ACE6AB035B696ULL, 0x982426A466E06EE1ULL
        },
        {
            0x828790C35C76016CULL, 0xFFF852EA2F2F471BULL, 0x1E5DDC3FD1C5F32CULL, 0xA4C11039758590ADULL, 
            0x337D2F042DEBAA68ULL, 0xDDEE16B9DEB8D4CEULL, 0x521C227DB496F3B9ULL, 0x59015A7A27B0C5C4ULL, 
            0x77DC029755C0051FULL, 0x5F291DAE32B843DAULL, 0x1700E18519E86CD5ULL, 0x3E7EAE0D26F08D99ULL, 
            0x0E6139F0F45AD300ULL, 0x90ADDEA133FDCE92ULL, 0xEFD2E571BD3F5FCFULL, 0x42D104768F56C8EFULL, 
            0xE2D1376484CA18F9ULL, 0xEB791C2C1DA096C6ULL, 0xBBC089F403088A83ULL, 0xD9619EEF74B0F18CULL, 
            0xBB7E630C0DD687FAULL, 0x18ADD6776E18CEDEULL, 0x02D86115646B08EDULL, 0x4D635049A5C403E2ULL, 
            0x1AD2D7C510843C0DULL, 0xD9B5C19C557F5230ULL, 0x27DC9CDAFE42EDBEULL, 0xAD294F11FE58215DULL, 
            0xCFE6883DBB28EA7DULL, 0xB82DB70876AD1A8BULL, 0xEA9D9D8E56940BAEULL, 0x30993F8A9F0CAFE3ULL
        },
        {
            0xEAEC94A6FD7F2943ULL, 0xA2F6EE606E93E048ULL, 0x68EF522B6E397232ULL, 0xF1022E02A1D152A2ULL, 
            0x26215A5CEC902AA8ULL, 0xD2B40306B8B153C1ULL, 0xF8D91D05795D85C6ULL, 0xF1C316FDE0E3231BULL, 
            0xA08EACF515BD37A9ULL, 0xDCA4BEDCA57463B7ULL, 0x35ED9D4BA06E17C6ULL, 0x9E6D96E933EF3FE3ULL, 
            0xF86D09D730C4361FULL, 0x0993B0C4C8868EF9ULL, 0x56897522F7C0D017ULL, 0x643B7890FABB8603ULL, 
            0xAF9F25CFA0ADFF49ULL, 0x30BAF3D41BF7C5B5ULL, 0x58B038B8337881D6ULL, 0xE9D2BEBBA2407F93ULL, 
            0x91B913454BE5AD03ULL, 0x8FDB869E3966E3D4ULL, 0xC868D747FE147C88ULL, 0x2080026F0E374720ULL, 
            0x2533B08C2C7416B9ULL, 0xFF7CC9F567987AF0ULL, 0x978F4A184C067989ULL, 0x1C4C6B318940F773ULL, 
            0x5A77559D9158870DULL, 0x7B06A032A71AFFE7ULL, 0x5801C0F7EF7EE061ULL, 0xB16B9CA6575A91E4ULL
        },
        {
            0xAFBBE268952F5FADULL, 0x1B27FA348F66C511ULL, 0x695FB171E79442A0ULL, 0x7B5677B7D9623914ULL, 
            0x8DD835027405FEACULL, 0xD3FB30A64C953C6FULL, 0x9E74CCBF1F5F5669ULL, 0xDF89A3C9B93644EFULL, 
            0x4D4BEE048F795BDDULL, 0xBAF8A7FBD125AA46ULL, 0x408451A876DC6AA9ULL, 0x1662D3A2ECA02F6BULL, 
            0x34B04A36BDC3E396ULL, 0xB2D4686B02E26561ULL, 0x2BE121CD8A5BA071ULL, 0xA79DF4921E7FCA87ULL, 
            0xF326CD6671EF7D0EULL, 0x950A7CC06ECEE20CULL, 0xDEA11533DC992FBAULL, 0x8370DA095C0883EDULL, 
            0x1518FF17E83860B8ULL, 0x324BCE48AF039393ULL, 0x6E3474878A742655ULL, 0x79B54137CAFBFB12ULL, 
            0x676E120709342C4EULL, 0x282941C1ED501B7DULL, 0x79B6B117BB800506ULL, 0x6DC0338BC972B3ECULL, 
            0xB91F96C8A70A6872ULL, 0x79E70A66DB91F32AULL, 0x6D4F73323EDE10D3ULL, 0x1549C72F056E543CULL
        }
    },
    {
        {
            0x3742EA3FD95788A1ULL, 0x63050498ED4E3F73ULL, 0x3E708CBC741CF0D4ULL, 0xD8FE0F643608DEE4ULL, 
            0x91786DEB1AE80346ULL, 0x68763417212839B8ULL, 0xD5750CC9E777C8F9ULL, 0x470261450F1BA5C0ULL, 
            0xE8C4208C2AA04CEFULL, 0x8BDA688993FDBF0FULL, 0x1D59BC54BD8F3747ULL, 0xF51B68DBC68CBD47ULL, 
            0x910B169311C22C27ULL, 0xA9B387593E379F66ULL, 0xCD8EB6C494BA16DBULL, 0x019DD7F94EDCF5A2ULL, 
            0x98485E5A175984DFULL, 0xCA229F4677144B6AULL, 0xB31FA5FF5D008D37ULL, 0x778B6AD32C734598ULL, 
            0x51C8EEDAD5238CC3ULL, 0x35003A53A6C49E9EULL, 0x98DFA2D681D280C6ULL, 0xDFE53B3072887416ULL, 
            0xDD110227E8CFC584ULL, 0xD9E04137945FB2E9ULL, 0x03EC4E79CD52B6E4ULL, 0xC63E593CCFF2A9FAULL, 
            0x4181DCE405AA3F9CULL, 0xEC6B31D0E72140DEULL, 0xC8E3940018C24F1AULL, 0x0407A63B9C18DC7DULL
        },
        {
            0x10C0A75F5318982CULL, 0x9269975F38D1A4F7ULL, 0x8D321144B2B079ABULL, 0x388D1B3092DFF772ULL, 
            0x8EB682868E00F66EULL, 0x94702DBD69B667E4ULL, 0xFE20D9207E4C31FDULL, 0x5B7EF09A9EB59D54ULL, 
            0x6790143505711BD8ULL, 0x248C971DEC92F81DULL, 0x9A5F2D72E7DB1453ULL, 0xED132A3AAEDE1173ULL, 
            0xAAF7CB0C8F08791CULL, 0x6B3C06A8FA5B17E7ULL, 0xC54B1416357B396EULL, 0x0CCCE551CD0C5922ULL, 
            0x0B6C648C9F1B651DULL, 0x3B3CBEFA4A53A86DULL, 0xC06072786F89F673ULL, 0xCD6E189C33E04BE8ULL, 
            0xF3A263C6D87D4BB7ULL, 0x3B6FA4FA7D414408ULL, 0x3729AEA08736276EULL, 0xDBC9394C7F52151CULL, 
            0xE4CFCA1AA89635FEULL, 0xAA802AD4C56213E5ULL, 0x0945BB8973F08D81ULL, 0x8795C7740BB0D7B9ULL, 
            0x9D175C05FCEC87B8ULL, 0x8564D14C2A6F90CFULL, 0xEF16454B97A7A03BULL, 0x9B24AC5148CF73D8ULL
        },
        {
            0x68116F45BE5DA948ULL, 0x0EB2BDC04ECEC5E2ULL, 0x5CF88108577F865DULL, 0xD8A70097B753880AULL, 
            0x2152EE13C3FF8B21ULL, 0xD8F43F4155EEE450ULL, 0xAD3B2F9DA6DDFC89ULL, 0xEBFF12B01FCAB661ULL, 
            0xDA786DA260BF18DBULL, 0x4D4669AFDE2BE245ULL, 0xD83A17957409F6BBULL, 0xE9CEA470216F67C2ULL, 
            0x20F9A49365627452ULL, 0x3A9E7C891629AAF1ULL, 0x43999E8EC16C7660ULL, 0x2772FD3BCCC30784ULL, 
            0x5903DFA950748D85ULL, 0x56022AB09E746A45ULL, 0x866579B43CD3976BULL, 0x864DBBD9BDBE33D9ULL, 
            0xB0B1F7E9FE73ECBBULL, 0xDD4DAD728728A676ULL, 0x316E7D9C699458A0ULL, 0xF8AF942C31FD011EULL, 
            0xD0168DD35083584EULL, 0x6263B708F836484CULL, 0xC9C395D6ABB14662ULL, 0x7374E93DCBAD0D28ULL, 
            0xEF96CC992A091D92ULL, 0x0DEAA0215B0A2857ULL, 0xA61EC222FD482C13ULL, 0xCAFB36D550986F9BULL
        },
        {
            0xAB074AFF801086C4ULL, 0xF12EA8FFCB787FBAULL, 0x6232ED7382F22441ULL, 0xEA5A998B540EE0A8ULL, 
            0x21AF9B7CEBFD7523ULL, 0x2124F4573E1AE5F2ULL, 0x6A3C3F39E89A1EECULL, 0x98ABFC8561E0E62FULL, 
            0xACFC1ABDC7FCD8D3ULL, 0xC833D5E4F8D02628ULL, 0xA2DF8E64F7F3E3A5ULL, 0x101DB33D7BFA2CE6ULL, 
            0x55A62FB226189CACULL, 0x79910334187DF16BULL, 0xE9926CFFCE713028ULL, 0x63142389AD770F35ULL, 
            0x91E1D2B5ED47E1F1ULL, 0x8C6F1FE989AF3242ULL, 0x0D10543A0515CFA2ULL, 0x4C25567CD3481134ULL, 
            0x87D483342A2618DFULL, 0xE18C2917A5B3E2A8ULL, 0x3C5539D0BA44C52EULL, 0x26933A772972881EULL, 
            0x4489C9CEF22F2688ULL, 0xFD40A0727615FBC3ULL, 0xADE8B3C7DD1FDF31ULL, 0xFB347EA0FC2DC2A0ULL, 
            0x7513EC3613D441DAULL, 0x80849CA0A2D2C39AULL, 0x6BC51154A29F3ABCULL, 0xF367A31B5404B97CULL
        },
        {
            0x82EDE7F62BC8F5F5ULL, 0xEF9C244D1A69289DULL, 0x5FC04FAFB4AD3CCFULL, 0x72F46A0716509B68ULL, 
            0xF09E43CBE4652E4AULL, 0xFD6E49C8FDC769FCULL, 0x97069C865424F161ULL, 0xABFE063B4D89F177ULL, 
            0x48BBC0805385EFF6ULL, 0x6BCE72BF80813FC8ULL, 0x9820572AD26A9D68ULL, 0xDB051EFEF895E460ULL, 
            0x843F129FB9BF9EDDULL, 0x0353F5C46EE38F7AULL, 0xAACAB6DFCCEBEF55ULL, 0x391D740C639C9D29ULL, 
            0x9EB5FB4D645D1A09ULL, 0xF8CC8529CA966E3EULL, 0xD07995F6B2E16D9FULL, 0xFAD45CB8E4500C13ULL, 
            0xE164F3BACAF62C55ULL, 0x92CE265AB6AF6286ULL, 0x06D2B707A1BE061EULL, 0x7AFFE87FC4289F74ULL, 
            0x36EB00CDA39342C2ULL, 0x59411FC7FDB0B86AULL, 0x004B1E8D7EA39827ULL, 0x49D2074AD5E3F442ULL, 
            0x15DBAC1A398EB1C3ULL, 0xF57C9BC090DB5B08ULL, 0x918B66826F1B8FEEULL, 0x39F85CF125D1CEE0ULL
        },
        {
            0x8CAE680BDAC806C7ULL, 0x302585F67C1CD824ULL, 0x1D0C97E535944454ULL, 0x3CC0FF3F4894F8F8ULL, 
            0x93B4B4EA06155BB9ULL, 0x58D4947E8E3B3240ULL, 0x28CF99FCDFB7A26FULL, 0xA19D17F8A211420FULL, 
            0xAB79292317415323ULL, 0x67484627DDA28103ULL, 0x1328D94B6980BC8CULL, 0x3E8489F4FF820604ULL, 
            0xAE437C8E7B03CE02ULL, 0x98585104D09A23AEULL, 0x8CC8F1ACF5889269ULL, 0x2B9F48946D73FD2AULL, 
            0x01CBA92A526F6A41ULL, 0xBF6665FBB2423B7FULL, 0x854C8D9017B9D249ULL, 0xA6D5D1B32FA990CBULL, 
            0x54E3500CD363916AULL, 0x619D34A1025E7A60ULL, 0x09CA54A15732D1D6ULL, 0x34A63EDA6FB003BCULL, 
            0x4C7F66C0089F2AC5ULL, 0x25882C39D3B2470AULL, 0x962439E3D4A97605ULL, 0x4371C62C0B508399ULL, 
            0x3ABEC27BA2A40547ULL, 0x895989294A8D51E0ULL, 0xE71108C9C4C1ED85ULL, 0x40CDD7D6F088B6DAULL
        }
    },
    {
        {
            0xAA43B2A7CEB26526ULL, 0x6D321F53AB2A7FA2ULL, 0xDF32F47F17061992ULL, 0x0FA8859DE373FFBBULL, 
            0x470ED5BFC8A3DA58ULL, 0xEC4A19E0DE03AA6CULL, 0x30E86D9E7E12DA7DULL, 0xE7C26C51428A8C13ULL, 
            0x01D3AEF7FA4E8B52ULL, 0xC0BDA6158575D2D9ULL, 0x9DD911C2C37A87B3ULL, 0xC28A38EB4190DC65ULL, 
            0x1B07A729EBB33F68ULL, 0x3FA82602B1B9E6F9ULL, 0x0238A9E051D5AA40ULL, 0xB9BCC49C4570FF19ULL, 
            0xD283757C18C54D5CULL, 0xE1DC1CD3A97A268CULL, 0x71B6119FC5982B40ULL, 0x646240EE983F38AEULL, 
            0xB830DFF0CEB682A7ULL, 0x61BFE5B1538CE5A5ULL, 0x5DE050141C94755CULL, 0x869054A0D29B9A5BULL, 
            0x633B6303B758EA3EULL, 0x65926CB7C30F3AF0ULL, 0xA61133AE8B59A0DEULL, 0xB4CA6DE6BA6E8BA2ULL, 
            0x5012BF943BD218AFULL, 0xD3AC76980F39D465ULL, 0x2C69A36A37052AF0ULL, 0x7CCD391522B2FA2EULL
        },
        {
            0x514CC6CFBDED5C5BULL, 0x9ED4183128D1F089ULL, 0xE8AC3A98B273DD81ULL, 0xFACC0985C3BE5299ULL, 
            0x9ED2C464E728B09CULL, 0xF50E30CC7881CFB4ULL, 0xFF1053832948DE2CULL, 0xE6653B2E109F97C4ULL, 
            0x15364B4D861236DDULL, 0x4C46F3984032DD14ULL, 0x8E4A6E4594BE28C1ULL, 0xF70B6014DEA4A8FFULL, 
            0x98D72148CB3E8E7FULL, 0xE2CDCF74AA93CE1CULL, 0xD014BB9E8709B4D9ULL, 0x15017306853209F4ULL, 
            0x010F72F8FFFD07CBULL, 0x14109B8765A5B554ULL, 0x1117D7D552888B15ULL, 0x2F3DD6AFF68DDD41ULL, 
            0x795741BF910B2055ULL, 0x396A009217124CA3ULL, 0xFAE767CD741AD60FULL, 0x2136E0CB754E9D0CULL, 
            0x459FF2C1FAE81BB0ULL, 0xDC7769B6C4239227ULL, 0xD337C3A9FDA3F46BULL, 0x3E3DB6C4C8222570ULL, 
            0xA43560805206CFB8ULL, 0x507068584654B6BBULL, 0xAD1D6E3AA7E922A6ULL, 0x48F19C85E0FE40DCULL
        },
        {
            0xA9893D68B15747A7ULL, 0x9BA03F5A50173F97ULL, 0xC4FC2D62FE4359F2ULL, 0xABD12F9B0D39EE7AULL, 
            0x47B8422DFB301BB4ULL, 0xCB2FF3015357371DULL, 0x01F4ECABF571DF05ULL, 0x07E7A81E1ACFFB7BULL, 
            0x3F851EF8AAA1E3FCULL, 0xD3FD721990EE909DULL, 0x7983C159C2E69FA3ULL, 0x0B5AE86646036E68ULL, 
            0xFE7EA69C2EF62DEAULL, 0xD09275593377D7FBULL, 0xF638691EF0F86298ULL, 0xCFD9CBC177AE2028ULL, 
            0x0EB3B6C829A88ABBULL, 0xFD4A70E13A7F6541ULL, 0x092CBF197A4B4CA6ULL, 0xD6AFCF1A33C66C7BULL, 
            0x7A9E4DB7493B34CAULL, 0x7638144BA9B3FB8AULL, 0x01DF5460D6979FCEULL, 0x4BE372CCF634B3F5ULL, 
            0xBF759C0338D72BA3ULL, 0x79E4BE14FEA1F9FBULL, 0x2B1C55CE722BF214ULL, 0x4327356B000E1757ULL, 
            0x40957462E91CC82BULL, 0x143F362248CF7222ULL, 0xEF07CF1837667316ULL, 0x85D47C369103D035ULL
        },
        {
            0xB7E004C4B5D7BFFBULL, 0x34F777B9676BD191ULL, 0xE38B83CD1AF52846ULL, 0xAF638C4EDC6306D9ULL, 
            0x0DE4D53E759778DDULL, 0xC75F593099C63577ULL, 0xEC86BCDE50944843ULL, 0x3582361367806F0EULL, 
            0x5067D240DE50C2C2ULL, 0x28AC6563E75FD52EULL, 0x71AD578B8B6E095DULL, 0xB9A6FE255C9C9D83ULL, 
            0x194C5D1FD62C733DULL, 0x49824DA84C5194DFULL, 0xEA5BF72918B9932BULL, 0x721BE505E803B4B2ULL, 
            0xE0D34738DC33E851ULL, 0xF6C2B01D45F9FD06ULL, 0x684D62ED2FDFFE85ULL, 0x7DDBEC9DB4422ACAULL, 
            0xDEE7C4D17BDB9A30ULL, 0x1AC117C7A5BD2CE9ULL, 0x3C2112C5EF5F7E1EULL, 0x66DD552A1E61AF2DULL, 
            0xAACAFEA738156CD7ULL, 0x8BB06B030E8AD884ULL, 0xF187DFBD934FDA56ULL, 0x75CD89EB4C0B6F71ULL, 
            0xF56E639BDE0ACDA0ULL, 0x6C390B90EEEBA6E7ULL, 0x40D2DDF007773547ULL, 0xABD8BAE536F0422FULL
        },
        {
            0xA7E87BD17F0E3BE0ULL, 0x017831C277198BE6ULL, 0xC4D98C5C46337072ULL, 0x62E170C54885E909ULL, 
            0x64687BCF3E9E96A9ULL, 0xEBBF180F94AA2EA6ULL, 0xAC39D5AF4A2B85F9ULL, 0xAFFC26BEB35F9778ULL, 
            0x80D2665D9536CFC8ULL, 0xEDD7927BAA3FB16EULL, 0x286F5248C58B2FCFULL, 0xC52DEA386732392CULL, 
            0x26AE57204CDA3A0AULL, 0x1E4248A5481242BEULL, 0x5568125B0BFA363EULL, 0x85DA7522786639B9ULL, 
            0xBB2F2503AE3BEBD8ULL, 0xDA35B85EA1F85BBEULL, 0xAE3B2AA9221E875BULL, 0x1F2239A6633E0665ULL, 
            0x63B7E319DC60E220ULL, 0x698C48C163147B90ULL, 0x9722F9593D777B09ULL, 0x4DB121C8DBD075F5ULL, 
            0xBB943D316BC5E4A6ULL, 0xCAD8AC825C29B62DULL, 0x602B684C5E6680A8ULL, 0x84957FE16105E773ULL, 
            0x886A7180F58C18C8ULL, 0x2B5AFBADD24016BFULL, 0xA62D98BECED00F7EULL, 0x97E82C895BC69009ULL
        },
        {
            0x2A7AD51C00003067ULL, 0x8BAEC83F7120542EULL, 0xC9FF4AE40E641986ULL, 0x25B35DDD0D869A01ULL, 
            0x460C754A16BC3BCEULL, 0x0EB754043F9DD085ULL, 0x07674B521EF3ED3EULL, 0x1CD775A56FF53918ULL, 
            0xF9DCECB72869593EULL, 0x1794B1BC36621ED5ULL, 0x874EFFF039DF2CCDULL, 0xECA1D0EF67B65F11ULL, 
            0x27B800FB5F22CAD1ULL, 0xD61B082EC6E9A1C7ULL, 0x68D1FC3A1DEA6775ULL, 0x47D0A8A64FAFA4EEULL, 
            0x3D9996E66ACF020BULL, 0x72446592B4C25FE3ULL, 0xCD97693AAF82E1FDULL, 0x4DE504D069786E55ULL, 
            0x1A526856437A03B4ULL, 0x46E2C86B415F723CULL, 0xC02985150D0F8160ULL, 0xCEDAC5F7282443D6ULL, 
            0x6317D3D2897FDDE6ULL, 0xF8EC1B9764C67A93ULL, 0xDBD64A1A66C6E2FEULL, 0x1369C2D79C3CD393ULL, 
            0x4DDE383495318221ULL, 0x6A57B527BDA8BED7ULL, 0x703C3BC84ADCBB08ULL, 0xDC22581C2536978EULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseHConstants = {
    0x65EBA622ACB9BDAAULL,
    0x6A1DC45EF0105F5BULL,
    0xDDDD30D89B3EAAD0ULL,
    0x65EBA622ACB9BDAAULL,
    0x6A1DC45EF0105F5BULL,
    0xDDDD30D89B3EAAD0ULL,
    0xD97E8181D1335CADULL,
    0x0DD925D567A4E135ULL,
    0xC9,
    0xA0,
    0x75,
    0x28,
    0x77,
    0x88,
    0x71,
    0x86
};

