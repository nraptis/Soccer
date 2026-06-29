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
    std::uint64_t aPrevious = 0x9ECA643DFC7B874AULL; std::uint64_t aIngress = 0xCE5633AF27B3C8B7ULL; std::uint64_t aCarry = 0xDAD68D8B3CFDCC9EULL;

    std::uint64_t aWandererA = 0xEA9BE442895B66CBULL; std::uint64_t aWandererB = 0xBB529CF59C73A98AULL; std::uint64_t aWandererC = 0xDAECDF35077E5A3FULL; std::uint64_t aWandererD = 0xFE3005DF31E3F046ULL;
    std::uint64_t aWandererE = 0xD5FF117B337BE3C2ULL; std::uint64_t aWandererF = 0xA76955BE95D633FAULL; std::uint64_t aWandererG = 0xF5839947943F0380ULL; std::uint64_t aWandererH = 0xD9B1E8C8E25D02E2ULL;
    std::uint64_t aWandererI = 0xD06DFA990E07154BULL; std::uint64_t aWandererJ = 0xB021C7149F526950ULL; std::uint64_t aWandererK = 0xECD6002BCF2ED999ULL;

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
        aPrevious = 15187257218090186371U;
        aCarry = 9691593512467821618U;
        aWandererA = 16786718494847033659U;
        aWandererB = 10526042897334026708U;
        aWandererC = 14768302968006613270U;
        aWandererD = 10163533004082902565U;
        aWandererE = 10261868218177594754U;
        aWandererF = 14126584875309652008U;
        aWandererG = 13257079825900714612U;
        aWandererH = 10999133191885374301U;
        aWandererI = 16861598023893349868U;
        aWandererJ = 18049230648728791435U;
        aWandererK = 17218884241223857650U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: fire_a, fire_b
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::KDF_A_A(pWorkSpace,
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
    // temp storage: fire_c, fire_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::KDF_A_B(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::KDF_A_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Bowling::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xFA86E311B81E10BBULL; std::uint64_t aIngress = 0xF9359F48DA3F651FULL; std::uint64_t aCarry = 0xCE2838BFAEB42BD2ULL;

    std::uint64_t aWandererA = 0xBFE4998924203DB8ULL; std::uint64_t aWandererB = 0xE1EC77C82C1AAA39ULL; std::uint64_t aWandererC = 0xC93FE188060BE292ULL; std::uint64_t aWandererD = 0xCA7E8A4F68542155ULL;
    std::uint64_t aWandererE = 0xBAEE24FBCBCA1717ULL; std::uint64_t aWandererF = 0xF73E03977FE064DCULL; std::uint64_t aWandererG = 0xADA18BE6F5A138C9ULL; std::uint64_t aWandererH = 0x87883F8178A8FEEDULL;
    std::uint64_t aWandererI = 0x9FDB6DE9FFBF9461ULL; std::uint64_t aWandererJ = 0xF1A21D9E796A7310ULL; std::uint64_t aWandererK = 0x9B22F9D91379BAD9ULL;

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
        aPrevious = 16796618307294274075U;
        aCarry = 10740797470648199228U;
        aWandererA = 12954990623175428990U;
        aWandererB = 12417918407162923415U;
        aWandererC = 13804544738687215620U;
        aWandererD = 15292981839249204215U;
        aWandererE = 17430593857479673039U;
        aWandererF = 12232591697760195968U;
        aWandererG = 12442679406157913327U;
        aWandererH = 16130345078296235338U;
        aWandererI = 10461701472895135393U;
        aWandererJ = 10212852926568236655U;
        aWandererK = 12096043430723236378U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Bowling::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBFBFD9E7E232DDA1ULL;
    std::uint64_t aIngress = 0xE39D41AE88BC3E5CULL;
    std::uint64_t aCarry = 0xEF1347DB82600D07ULL;

    std::uint64_t aWandererA = 0xFD3CFBC6300BC9DAULL;
    std::uint64_t aWandererB = 0xA8035F839029202EULL;
    std::uint64_t aWandererC = 0x9BC946504CE84CAEULL;
    std::uint64_t aWandererD = 0xEA29F8F530B2B860ULL;
    std::uint64_t aWandererE = 0xC71607FE15FF348FULL;
    std::uint64_t aWandererF = 0x8D8101A850788BDCULL;
    std::uint64_t aWandererG = 0x8DF8A42C63F52A30ULL;
    std::uint64_t aWandererH = 0x8458C6D869D9D269ULL;
    std::uint64_t aWandererI = 0xF58A78797E28A537ULL;
    std::uint64_t aWandererJ = 0xA47B52A109D6C9E3ULL;
    std::uint64_t aWandererK = 0xECEE2E90035FC833ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_B(pWorkSpace,
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
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::Seed_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::Seed_D(pWorkSpace,
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
    // write to: snow_a, snow_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::Seed_E(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::Seed_F(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Bowling_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Bowling_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::GROW_B(pWorkSpace,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Bowling::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x81B166F8745CB695ULL; std::uint64_t aIngress = 0xD489FD13AA943F7DULL; std::uint64_t aCarry = 0xFE3A80979437A959ULL;

    std::uint64_t aWandererA = 0xE905E74E8C3AC928ULL; std::uint64_t aWandererB = 0xC7921EA60DA24BF6ULL; std::uint64_t aWandererC = 0xC188B702068B0FB3ULL; std::uint64_t aWandererD = 0xEF604FFDBEEAA0C4ULL;
    std::uint64_t aWandererE = 0xD55802DA84378C0BULL; std::uint64_t aWandererF = 0xA5B18A218542871BULL; std::uint64_t aWandererG = 0xEA75E94225A33D9DULL; std::uint64_t aWandererH = 0xAC2B826AAAC17182ULL;
    std::uint64_t aWandererI = 0xC755726F43D58D62ULL; std::uint64_t aWandererJ = 0xA07E64DFCAAE0A97ULL; std::uint64_t aWandererK = 0xE800C7F95AE64BB2ULL;

    // [seed]
    {
        aPrevious = 10572742118977526269U;
        aCarry = 14528522822661818986U;
        aWandererA = 11539002563532987553U;
        aWandererB = 17728600264397094593U;
        aWandererC = 16139174687484400030U;
        aWandererD = 12131385791743326355U;
        aWandererE = 17734196249363880610U;
        aWandererF = 15227280014062470415U;
        aWandererG = 10327524128571909241U;
        aWandererH = 14808196784800314628U;
        aWandererI = 15975951355466555855U;
        aWandererJ = 12241654695877468773U;
        aWandererK = 16937213637864868774U;
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
    TwistExpander_Bowling_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Bowling_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Bowling_Arx::GROW_B(pWorkSpace,
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
        // read from: aOperationLaneA source quarters 1, 2, 0, 0 with offsets 2540U, 129U, 6187U, 8040U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2540U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 129U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6187U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8040U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 3 with offsets 3608U, 6295U, 5899U, 2071U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3608U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6295U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5899U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2071U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 1 with offsets 4877U, 4086U, 2517U, 5232U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4877U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4086U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2517U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5232U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 3, 2 with offsets 3032U, 4564U, 7393U, 5920U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3032U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4564U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7393U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5920U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 400U, 1604U, 675U, 533U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 400U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1604U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 675U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 533U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 0, 2 with offsets 313U, 868U, 1208U, 89U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 313U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 868U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1208U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 89U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 0, 1 with offsets 786U, 1550U, 787U, 1408U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 786U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1550U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 787U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 0, 3 with offsets 338U, 1679U, 241U, 1739U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 338U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1679U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 241U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1739U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1857U, 1965U, 1484U, 1495U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1857U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1965U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1484U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1495U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 3 with offsets 7496U, 4116U, 3831U, 7315U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7496U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4116U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3831U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7315U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 2 with offsets 7109U, 5446U, 5723U, 1655U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7109U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5446U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5723U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1655U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 0 with offsets 5892U, 1893U, 8124U, 405U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5892U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 405U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 0, 1 with offsets 5983U, 3683U, 728U, 5172U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5983U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 728U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5172U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1483U, 3862U, 5976U, 1228U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1483U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3862U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5976U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1228U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1863U, 1391U, 1414U, 474U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1863U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1391U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1414U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 474U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1134U, 1571U, 912U, 1597U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1134U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1571U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 912U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1597U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1283U, 636U, 665U, 1212U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1283U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 636U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 665U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1212U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1448U, 801U, 94U, 53U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1448U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 801U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 94U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 53U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 1774U, 1786U, 1850U, 685U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1774U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1786U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1850U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 685U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseASalts = {
    {
        {
            0xAF96AF62974B982BULL, 0xEE343739974DC482ULL, 0xBCBB6F9829FD991BULL, 0x91395FE50015FC8DULL, 
            0x0DBD6B5C157A6186ULL, 0x91B466059C28DCA8ULL, 0x2C6C7EC7128FB121ULL, 0x22E3275C8CC83BA4ULL, 
            0xB0B498A79FFB3EE6ULL, 0x5C8703EAFA111742ULL, 0x90454384DF84C257ULL, 0xBA1D230F32C1B73BULL, 
            0xDE1DA103CA6E376FULL, 0x3B6E22DA0365F25EULL, 0x27B5DCE67B11F253ULL, 0x91A231DECC646ED9ULL, 
            0x21D12CDD471D798BULL, 0x13992129039622A8ULL, 0x7E8B09CD31EAB0EDULL, 0xF4BFA2C2639D9F6FULL, 
            0x0A0BCC3FAD9B3856ULL, 0xD1ABCF56E08CBDE2ULL, 0xE05E5CCCA846DDE7ULL, 0xDAE9FCACA8BC8A29ULL, 
            0xA2949AD98D634D65ULL, 0xBE545EECDD1D62C9ULL, 0x0595D4D18BBABFD1ULL, 0x54FB3B891B529070ULL, 
            0xF891DCB91B9A2568ULL, 0xEE011DDFD8961748ULL, 0x4E66F69840271A00ULL, 0x74DE8B0D7E5164FAULL
        },
        {
            0x4F2515295A6A09C7ULL, 0x17D29ED08D7B84BBULL, 0x0C97AEF2DDD3EC2EULL, 0x5CFC87CF19E3D2FAULL, 
            0xA6B21C1B6F39C06EULL, 0x665B61EBAA1911C7ULL, 0xADF5CAA07D84001CULL, 0x9B7CDFE0C5B724BDULL, 
            0x28BDC172082644E8ULL, 0xEDC0A8D51BAAC794ULL, 0x5CB8B6AAA713BF83ULL, 0x67F1491E87BB1265ULL, 
            0xEB03DD5D3484FACFULL, 0x9A4684BA17E17723ULL, 0xC247C69BB6AD423BULL, 0x87CA5DC712770BD3ULL, 
            0xA4866347092D3FEFULL, 0x961A6756C40D2DA7ULL, 0x9EF750312E18C936ULL, 0x7FB46FD666C79658ULL, 
            0x14799D49768F7C8CULL, 0xCD9A8A9F0A14AE94ULL, 0xC1C22AB18A169E73ULL, 0xD279D448AFBD6780ULL, 
            0xBBA7D10CDC497323ULL, 0x5BD004F8B6C88E90ULL, 0x175F790877430579ULL, 0x576833C6DF7BABE0ULL, 
            0x15C021C6B84B5B82ULL, 0xD50A646CF32F67BDULL, 0xE223EAE95392B61AULL, 0xC5CD8525DBB15D8EULL
        },
        {
            0xF46149EF7D83FD92ULL, 0x5E082E70FA192738ULL, 0x5D1C05267F4D5F8EULL, 0xB108DACC25C8281DULL, 
            0x5B8EAB416F95EED8ULL, 0x0CF3D592641C133FULL, 0x602A6884E8E77D50ULL, 0x1D65C28996728BA1ULL, 
            0xC1642C7B78B728B7ULL, 0xC6D0B6A13A5B682EULL, 0x445C0F37B13F1D8BULL, 0x480CD2832776A574ULL, 
            0x8BEE7A1D8BA59C89ULL, 0x7D12A42D12915B5BULL, 0x22631B55E8030D8BULL, 0xD4B80A453DC0EC05ULL, 
            0xB250F699C11E5F20ULL, 0xDA6F3C5E48400A6AULL, 0xD82563E9F13D27F6ULL, 0xD6FE17968A6A60EFULL, 
            0x5A110122E457255DULL, 0x964B65F740B5B470ULL, 0x3E4F7C3E207549C2ULL, 0x112896B05FD8BF8AULL, 
            0xCA2437AC12FB9421ULL, 0x9A6ABDD77A89C460ULL, 0xF2C6707B378F7F84ULL, 0x90D45EEF9F1443D5ULL, 
            0xBE139290FE22DCB0ULL, 0xB92B146905A08EE9ULL, 0xDBB89030743A3F8AULL, 0x72EBCFB3CB19E7B0ULL
        },
        {
            0x81C12C6CCA97DB3AULL, 0x15C8F4314F036837ULL, 0xB8D1C188539C71D9ULL, 0x3E444E1DF74EFAD5ULL, 
            0xE9FBDBB6E7B8BB60ULL, 0xAA7D91BAFCBCCA74ULL, 0xE2949B842329ACCFULL, 0x9D59EE932978038EULL, 
            0x30627460164E59C8ULL, 0x769D6C8F9158B776ULL, 0x8A5921AE797DEAC9ULL, 0x4A7725971E442578ULL, 
            0x8B8CAB196FF3997FULL, 0x97DE96B7529A5E7BULL, 0x907917C931E17251ULL, 0x9F0E8066DAB9266AULL, 
            0x2ABB52F5062C4AF2ULL, 0x3E0C4EAF795DA9C3ULL, 0xBD3F113DFF2FE2FDULL, 0x2C9CE6371F188710ULL, 
            0x28D782AC9A3D84CDULL, 0xEF00309C67B60A3CULL, 0xE939F203C97D9D35ULL, 0xEDCD15A794C0DB53ULL, 
            0xAB8AF6B8F100B39DULL, 0x86A84835B3E016C2ULL, 0xDA60EFA42F48022FULL, 0x143DE719A3DF5703ULL, 
            0x256ACAD8F3707E7EULL, 0xF9A10FBF27FF3881ULL, 0x540CF142FEE19354ULL, 0x82F873EFACF2BD6DULL
        },
        {
            0xFCC887A220EFE392ULL, 0xDA769C6C8182B4C7ULL, 0x91003DD45A342301ULL, 0x93F89C8F98320BC3ULL, 
            0xF8CEB7EE174144E8ULL, 0x6422C9B6626FA029ULL, 0x56BC25C919453EE2ULL, 0x266AF2418F4286AAULL, 
            0x2B017377644A47F7ULL, 0x01695A8CF3FB969CULL, 0xA19312CF06201D5BULL, 0xB826B5EF79292D7FULL, 
            0x533A2F165B839BFCULL, 0x5FF1D29999FE4CECULL, 0x69F465D756D343B8ULL, 0x20025BC42CB9EE1AULL, 
            0x5ED2885BEB5F8FF4ULL, 0xE5A84CCE79EFC97CULL, 0xC5AC88A376C29AC3ULL, 0x7E2D5DA061120781ULL, 
            0x8DF6F2C2B5865832ULL, 0xC404242F721299B0ULL, 0x45EFE6B5F36BD089ULL, 0x4EDF90BE577555ECULL, 
            0x788CB20BAF7063D0ULL, 0xAA8255CBC5374AABULL, 0xAE94BC5C46F8A9D5ULL, 0xA3926A6D06031169ULL, 
            0x89D1A19AA46C8765ULL, 0x3F2A142B2E1F4AC4ULL, 0xB495514103C71880ULL, 0x6BACEA86A5C3A3DDULL
        },
        {
            0xFDAE3D54837779C8ULL, 0x02B4FA1CE84EF69EULL, 0x2B06367F1EBC80C5ULL, 0x622E6390CDB18C07ULL, 
            0x60A096043F38F18BULL, 0xCF5920FBFC7F32D3ULL, 0xB023BBF62E499E99ULL, 0xF621D7186C7DCEDDULL, 
            0xB792D01E30232E88ULL, 0x5B2269DC7FFD2476ULL, 0xC49FFA69443E2CEFULL, 0x6125839CD88A1DE1ULL, 
            0xDEFDD39E0E6431E6ULL, 0xD1CCA86B54ADFCD9ULL, 0xBA7C4E183D13D6AAULL, 0x029EA966C3A1E106ULL, 
            0x84C85165AFB82FDFULL, 0xB879A3B02DC88A21ULL, 0xB3D8444794859237ULL, 0x79B5D9771E8046A6ULL, 
            0x6F75C7FAC3FB2D90ULL, 0x67AF56758148D5BEULL, 0xD76DB89944AC0BB3ULL, 0xBBB99F4AA9ED772BULL, 
            0x41532F1773A9A721ULL, 0x6C9D01738F6A75FDULL, 0xC8C65901E0E2DDECULL, 0x107CF0917C6A0C7AULL, 
            0x64FD7B5A59DC6480ULL, 0x25EDFC364CF8C272ULL, 0xECF008964A6E5963ULL, 0xE859C27955032F76ULL
        }
    },
    {
        {
            0x9441E81E6EAA0F05ULL, 0xA68C81410E515387ULL, 0xAE3DF2FA59B91CBFULL, 0x645BE20B4B6ABEF3ULL, 
            0x3403D5E24140F0E1ULL, 0x928763EC8B47EC8EULL, 0x36E3548DE124D957ULL, 0x5C40F35426BA67ABULL, 
            0x545FAFBD8A4BBAE3ULL, 0x4ACEC98F35314DD5ULL, 0xF2C1C1D0D660BF59ULL, 0x9A3AB27529CC2933ULL, 
            0xD97D5BFA89FDC34FULL, 0x5527054EC2C17E62ULL, 0x00ED6E5EC5E25C6CULL, 0x16B74E937A2715DEULL, 
            0xD3DAFBEBB6E33EAEULL, 0x361B24E0D38BBB9AULL, 0x2230D165CF3CE934ULL, 0x734080491F273606ULL, 
            0x0E6E585A3C80324BULL, 0xDD7DA575B9DE021AULL, 0x4BE64D8D146C5906ULL, 0x918C90362D48B410ULL, 
            0x02A1B6B0D2A2CC39ULL, 0x0291E2B6A3BEF321ULL, 0x5FF99EC581B67C36ULL, 0x8352224C41B0793AULL, 
            0x128872949861DD0BULL, 0x9CEF722C877C3E24ULL, 0x404C0B6CF966D780ULL, 0x40AB1B13A6D0EF94ULL
        },
        {
            0x006B5259C1FD72A3ULL, 0x6BEA7DB4F1E68E36ULL, 0x1C81B456344783EEULL, 0x071551DD47DDA16AULL, 
            0x490583C4268954E7ULL, 0xF56140F21550E7BAULL, 0xCA2FF96320DB2E7BULL, 0x8829BBFB5550C56AULL, 
            0xBAB16FDF4F8186B6ULL, 0x71166280B60D72A6ULL, 0x6307090E579039FDULL, 0xE04C80EBA4266EB7ULL, 
            0xA721CB469107E915ULL, 0xF9CEED8AA983F04EULL, 0x25C40E17754B62E9ULL, 0x37A29697EF2AE4E1ULL, 
            0xCF511A03F804FF9CULL, 0x29A5084F3AC4F06FULL, 0x9015E9F6146040DDULL, 0x3B72AA14F89CD1D7ULL, 
            0x625C0E29EE6F487EULL, 0xDEA2213C631F5EACULL, 0x7BC7CE2869966939ULL, 0x81A76C8B0D7C484CULL, 
            0x31488873ECBACAB4ULL, 0xBD91F0A6922334CAULL, 0x606EDA35E8F256EBULL, 0x086648C6F3CB071EULL, 
            0x622992D302CB59EFULL, 0xBE7484D6B29ED473ULL, 0x51C50A61A707FFFFULL, 0xF0C1A9EDAB027F98ULL
        },
        {
            0xD9C11D1839B28B11ULL, 0x62EE1EEE64D5E6BDULL, 0x4DA054F821F39290ULL, 0x38BAD39521D995E7ULL, 
            0xAD86A63CCECCEABCULL, 0x3F034C653D93DE18ULL, 0xDB98D77F595AC218ULL, 0x826C919A1F8EC0ECULL, 
            0x2B8593EF043D53BBULL, 0x5CDB8EA780FAD27CULL, 0x5977129AB329E367ULL, 0xF7C590A5B27620DCULL, 
            0x443D1AA1F5D1AA1DULL, 0x567AE1CF5D3ED8D3ULL, 0xC3F6AE279CC193D1ULL, 0x6FE476B0D39E70C3ULL, 
            0x50F1C9579CF7D980ULL, 0x8328BD1720827AAEULL, 0x7CEA4247E9728BDEULL, 0x7E34559EBAC219F6ULL, 
            0x6622BDB8D682BA89ULL, 0xB97D85A576D197C3ULL, 0x60AED32099B03DF1ULL, 0x46F16D25A3961B91ULL, 
            0x2858679EDD9A7A5AULL, 0xC3FAAA15BBD6667DULL, 0x87201762FEAC2DE5ULL, 0x1EA8F1FD9A2A448AULL, 
            0x596E878809A0A6FFULL, 0xF4B55342FCFBFB83ULL, 0xBC980C7AE96E24A6ULL, 0x569418645FF5339BULL
        },
        {
            0x8787B2F60122A31BULL, 0x008D6F5FCBA76232ULL, 0x8D8329C4B8740F7BULL, 0xF28907440BFC50ACULL, 
            0x2FA88909525D152BULL, 0xDFCB2D041E438739ULL, 0x0BB6B43E84E2E4A9ULL, 0x1641691370FB14A1ULL, 
            0x91C0F5180C0BB282ULL, 0xEB5DC0B1708C2CF1ULL, 0xB4490D876F51DE83ULL, 0xDDFE9B63A3B352FDULL, 
            0x8C78181336732318ULL, 0x691F668A348683EAULL, 0xC95A00C1BF3F1CB5ULL, 0xC7DB48F2FC709737ULL, 
            0x9946B5F2205477C2ULL, 0x8C6942B21BD54458ULL, 0xD3C78B165AAB670DULL, 0xB3949A48660D4D87ULL, 
            0xDFC92B5265C31535ULL, 0x89BB839D1E269EF1ULL, 0x08560C4FE6EEFEE8ULL, 0xF26DF1DC64644C82ULL, 
            0xDC196E816E06F5DFULL, 0x2F3D1E975F3DD178ULL, 0x91548A27FFCAC914ULL, 0xB55E23673EE1978EULL, 
            0xFBEBB45B2896F8E6ULL, 0x3F95A5DF2A4D31ADULL, 0x7DE4C6FA8A98D91AULL, 0xAB0816630FA930D9ULL
        },
        {
            0x2EA2D6E9604A3434ULL, 0x419C7666EA2D80BBULL, 0xD41AB6A87391401EULL, 0xFE03E44AABEB4BF7ULL, 
            0x16151A23578857ADULL, 0x533C8BD72B7740F1ULL, 0x78EC4CB409C110BDULL, 0xC18741ECADB2835AULL, 
            0x89882FEE38DB13FEULL, 0x6AD841309F89EA3BULL, 0x9FDAE427CE678FFDULL, 0x77621F63EB725C78ULL, 
            0xDE5D56B34958D545ULL, 0x5CE93F20EFFFBBDFULL, 0x3433A29F4F1B97D1ULL, 0x04045C4C1A5462E7ULL, 
            0xEC9AEC5FBF6D8EA4ULL, 0x9CDA3D25837F0322ULL, 0x5833B05943B63E7EULL, 0x0228ABF1B2B9105DULL, 
            0xE2AC9D7053E148F2ULL, 0x43BEFA0AE505C9B3ULL, 0xBA094D26B1CCE685ULL, 0x38CC410BE14458CAULL, 
            0x64546F2678C6BE04ULL, 0x139FA3B42BFFF7D4ULL, 0xC952D016033D49A5ULL, 0x7333E0F5FF2CA64FULL, 
            0x9BDD7B0A1C540227ULL, 0x5FDE98E2053CF092ULL, 0x489B2B7032E4884EULL, 0xF52FBABF47416705ULL
        },
        {
            0xD6D8DFA3B3A73573ULL, 0xFF3AFE1156E7D6AAULL, 0xE4AA1BF7DE9E8140ULL, 0xAB46CDB1D34DD937ULL, 
            0x061CCED141A144DBULL, 0x40F3FD64778F7347ULL, 0xABC7E610C3553DACULL, 0x7EBF7D1625104C2EULL, 
            0x30640DABB7BFB313ULL, 0xD9487B0A19D01A4CULL, 0x1B498D0A748F4E3BULL, 0x38E2E85E6CF9025DULL, 
            0x575F6A6C0FFD764CULL, 0x103AFD07B6E4271AULL, 0x3088A50D5784F737ULL, 0x6F478FCD638A41A0ULL, 
            0x577AFB3F26CD0302ULL, 0x8878FE17A8D28596ULL, 0xDBEFB81237F6F7E9ULL, 0xABE76D5F05813C34ULL, 
            0x4EB2FC58BE4E3960ULL, 0x3ED7ABF76A5F6B99ULL, 0xF802DD36A3DA7DEBULL, 0x46F28E5B1CD9577BULL, 
            0xD39B5B263FBF6D11ULL, 0xA857A57D09A1EA34ULL, 0xE5FF95DA94A3B92FULL, 0x29C608D2110E4A07ULL, 
            0xABFD56E9A718AA95ULL, 0x4C38EE098104A2D4ULL, 0x733C520655431AEDULL, 0xA7B4E53CC91A1D7EULL
        }
    },
    {
        {
            0x5888B306961E3F17ULL, 0x6D43C5AE3A100400ULL, 0xED136E2A65C0ABC5ULL, 0xBD6EE7FF1E071760ULL, 
            0xC23A97A3C4DADCA2ULL, 0x01FD9FB0EC399F51ULL, 0xCABC10E7DDAD2732ULL, 0xBBAE410F0277ED65ULL, 
            0x0E75B14D373575FFULL, 0xE88CE46EC8B8C2CCULL, 0x34086A2F423628A7ULL, 0x739DE72DB2C29F96ULL, 
            0xCA7716889E664FE7ULL, 0x3E6966FB959F2DB1ULL, 0xC80E4C8978A303D5ULL, 0x3DDEF848F7A8C052ULL, 
            0xF5CE86A53A995D7BULL, 0x8A1ECD80C255112BULL, 0x4005EA54CCBE7AB5ULL, 0x6F5F5A9685556491ULL, 
            0x6ED666D855BD954CULL, 0x9BC2F03CCFA2CC7BULL, 0xA73558C574D6CEBCULL, 0xA64F0E7CE7FD06D1ULL, 
            0x18278D6C3C0A5869ULL, 0x70B40DF2474CD92EULL, 0x14FDCBD2D3A3B177ULL, 0x4D5BC5D202B2965DULL, 
            0xA13C65EC4EE2B3B7ULL, 0x622C66E07422CECCULL, 0x4E446536BA0EB2E0ULL, 0x8659D1D9B2B32C47ULL
        },
        {
            0xEA2698FA5E65DB7CULL, 0x476C8215A9870C9BULL, 0x217A54B0EB8B0382ULL, 0xE4F8BCC20A105689ULL, 
            0xF99E9BE41E648899ULL, 0xB0FF75FD2279DFFBULL, 0x37D8ACE164B3EDDDULL, 0x4CA49E70CD78AC70ULL, 
            0x3F5AFFD3AED57766ULL, 0x81E3CE531D840C23ULL, 0x9CBDBC663DB0056AULL, 0x72BCD85869A208C6ULL, 
            0x5D60577F54A6B2F8ULL, 0x0A5459987A556004ULL, 0x105410B9911D9871ULL, 0xFB34EE24E2077DB6ULL, 
            0x5E452260A7807BC3ULL, 0x61C88C6F45B9A4C5ULL, 0xC8868A0E62A7B21CULL, 0x1AF5588AA6362195ULL, 
            0xDDAEBE494B31D682ULL, 0x694EED2F706E30E8ULL, 0xF063269B901697A7ULL, 0xB30F1C6818424AC4ULL, 
            0xAED67323181D6180ULL, 0xA11553AB630FD441ULL, 0x56E9333F5C390FDEULL, 0x71A027C39D8980C6ULL, 
            0x66F1B54286ED75B9ULL, 0x91B423C9B8AEB1B7ULL, 0xC2593AE98A64AC29ULL, 0xBB8817DE930BB388ULL
        },
        {
            0x8AFAE146DF3EA723ULL, 0xB9E3F7FB68F757F8ULL, 0x1D5C21D3E4DA667EULL, 0x81AC7136C88A9C78ULL, 
            0xB26C1413BD93B9BBULL, 0xD82B7011AEE13532ULL, 0x01281CD2DF7CA9DFULL, 0xAB991B8A1A7F3EACULL, 
            0xED1AC529DD204498ULL, 0x7A915F63F2EAAAC5ULL, 0x9F165D94026F8265ULL, 0x6CEC3229814FD89BULL, 
            0x52EDEB60A281FB42ULL, 0xAC312EF37C80A042ULL, 0x13DCB67FA35AD414ULL, 0x6443B41919A364EBULL, 
            0x5A35BF36AFDF55C7ULL, 0x0C479449B4FC79E9ULL, 0x6201419922ABB180ULL, 0x0B10C92DE7D96E74ULL, 
            0xAF450493F9E27AA4ULL, 0x1D809D1A510454D4ULL, 0x02D5D24B496348D2ULL, 0x0BD2BCFC4F473906ULL, 
            0x10592486D078D537ULL, 0x425BE111AA6D04CCULL, 0x63237A73CF5D4D75ULL, 0x6BF9D8E240A84D45ULL, 
            0x4DCAE677F67E4987ULL, 0xA7683E749E19656FULL, 0x63DD133569C766F0ULL, 0xB95ED75B5D72172CULL
        },
        {
            0x33945B9B1911FE9EULL, 0x4E0650C43BD9BF78ULL, 0xE0254C5185287877ULL, 0xA1E35F8F368A4FF5ULL, 
            0x8DB2E6B6F0F17595ULL, 0xD4998A0813BA901BULL, 0x3B3E003B5954FD1FULL, 0x8AEAB67079E34E4AULL, 
            0xF5E5ADA88D188157ULL, 0x672E364ABA9F1B78ULL, 0xA1E04708279B591FULL, 0x647F295176B97B3AULL, 
            0xE68852BB6C3EB403ULL, 0x60B14539ED0675E4ULL, 0x59DD7ADDFA121EDDULL, 0x4CDDDF2E3F124398ULL, 
            0x67B66337FD5B222EULL, 0x3211CBAAFFCBC198ULL, 0x00778F82D7C08D6AULL, 0xC37A234EF7C76039ULL, 
            0x1FA133ED5B4A6B39ULL, 0xF843C96590FE0A47ULL, 0xEDB7354DF29D1976ULL, 0x0C91DC1398487305ULL, 
            0xF6887DED4D7F9A0FULL, 0x8A34E2FFA5088853ULL, 0xC7A26FEF65A8BB9FULL, 0xD0DE2B1E10AF2EAAULL, 
            0x2AB2933AD6B455CCULL, 0x649D79A113095BEBULL, 0xBF003EDC1D09B187ULL, 0xF08769172386653DULL
        },
        {
            0x5899E4F8E4C6D98CULL, 0xF27EBD56ED20D3A8ULL, 0x7755647F52C7D930ULL, 0x75C0152052F63A19ULL, 
            0xF1073402DB3D4AA5ULL, 0x31ABC22174E0702AULL, 0xF445A8067B153565ULL, 0x187503E9C5ABA210ULL, 
            0x6B14A9C45F400D53ULL, 0x32CF425805B181E6ULL, 0xDCE49BF1D28AA23AULL, 0xEC321C95CA136E38ULL, 
            0xF62F6E3ADF8AEE6AULL, 0x7D71FF5A104DDE18ULL, 0xF14A8644002547DDULL, 0x2DB995F52D5019E3ULL, 
            0xDC8E15B6869E5E06ULL, 0xF3CFCBC99744EB0DULL, 0x82D9A8F30AFA328AULL, 0x78075CA4A6C0FC8AULL, 
            0x2DCCE241976154F7ULL, 0x12ED15EDE7CDFF3CULL, 0x8AD9F50E55E38E4BULL, 0x4B48B24A84FCFF32ULL, 
            0xCEF2DC69B4949963ULL, 0x0636151D006573F2ULL, 0xE91ACF35C463B5FAULL, 0xA87ECCA4F43F10DAULL, 
            0x33DD8DEB5813C7FAULL, 0x7A58493BE2075A68ULL, 0xF558FE5C735E9E66ULL, 0x5CB7F56FD98014FFULL
        },
        {
            0x4969A185D1D6FC38ULL, 0x63BE156AA490AE3EULL, 0x3C947C3CA9F1A368ULL, 0x05E8529F9FFAA383ULL, 
            0x3EFF1F70340182E9ULL, 0xE67DD14C1BF92905ULL, 0xFB56121869C608F3ULL, 0x345D94F0560DFF80ULL, 
            0x4F6343139791AAE7ULL, 0x6707F3024213CD95ULL, 0x49DC5FB357279367ULL, 0xA7857D48A123C56AULL, 
            0x602E8F5D5490D3B5ULL, 0xCDA9A51875435A4AULL, 0x740E3C859B5453C1ULL, 0x83C8F791E95A8C57ULL, 
            0xA2E72758FAE4E45FULL, 0x5AF1EB73F255BF92ULL, 0x1253419ECE8D82C9ULL, 0x26666BC4C2AE4D0EULL, 
            0x6A27EECCB6D968B4ULL, 0x23DB757C922F35C8ULL, 0x38DE8B6DC209A939ULL, 0xCFA483CF9D79129CULL, 
            0x2A49831D5B6496F9ULL, 0x65DFF1C8ED993B7FULL, 0xE86148E6140B2CBBULL, 0x6966CF5F30B38AF3ULL, 
            0x42F7A9D0385B4E74ULL, 0xFC5E89DCCE78103BULL, 0xB94A86D9995E20FCULL, 0x5DFA0CECF2113495ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseAConstants = {
    0xC01CA1253D39532AULL,
    0x647D60591492088EULL,
    0x7DDA86167B57072EULL,
    0xC01CA1253D39532AULL,
    0x647D60591492088EULL,
    0x7DDA86167B57072EULL,
    0x54717501D84F53D4ULL,
    0x4354016C160C552FULL,
    0x40,
    0x2C,
    0x95,
    0x78,
    0x79,
    0x36,
    0x14,
    0xEA
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseBSalts = {
    {
        {
            0x1E1D3290BF124A0AULL, 0x3177BBDACD059876ULL, 0xCE95BFC76AE61CA5ULL, 0x28C621A2549E819DULL, 
            0xB1927EF3F6D1AD4AULL, 0x83D66CECEB18D4B4ULL, 0x72408B5DF2A88473ULL, 0xE7F5AD10B7AE82C4ULL, 
            0x49C20D3CF3AF3E8CULL, 0xAA15E51DB4F1EDB4ULL, 0x7FC03B6A27A9AF70ULL, 0xB84BAE55AA9CDE88ULL, 
            0x1744301425B2E267ULL, 0xB9147EFE3449ABB5ULL, 0xA7FC663E92B50D86ULL, 0x25B3D9EEB0FA191FULL, 
            0x5F5E6B68E3D16EFEULL, 0x9F719640122BA36BULL, 0x5B7FD585735ECC4AULL, 0x6E7AE2F30651D4EAULL, 
            0x1BDE070C90CB0B84ULL, 0x0DD76DBB5EC3D2CCULL, 0xDEE495036DF76925ULL, 0x04A3B72287ADFB0AULL, 
            0x1AA7278AECC09B64ULL, 0x917E749E010FD74BULL, 0x99BB2D6E883F28C6ULL, 0x61BDA8250D749F7EULL, 
            0xA42B04AD8073C1CEULL, 0x454D80D81BE328F6ULL, 0x1A5A587CD29F5F0BULL, 0x2013D63FFDC9D0F2ULL
        },
        {
            0x094C1E0F95AC12AFULL, 0x1F06E60DC7615A51ULL, 0x26E2F6D995A0F2F3ULL, 0x41B6B1BD369FB5F2ULL, 
            0x924ACD324BF5B6D4ULL, 0x25E9C6D6DC6623D0ULL, 0x537A7073FA073E2CULL, 0xF75322E685D658F3ULL, 
            0xAE16267AF7B462C8ULL, 0xB46BD7BFB332F0A9ULL, 0x4B2ACD68900043ABULL, 0xB507D60C41D24752ULL, 
            0xCF3F66E07D84FEB9ULL, 0x79274EF31CE23589ULL, 0x99D561BA6675B9E1ULL, 0x971945FC798D458CULL, 
            0x187DF0139F64ADE4ULL, 0xC82EA739C4C43F0FULL, 0xA521EB7A3280C61CULL, 0x668DE63AF3F01654ULL, 
            0x2040F1E1EF4D1456ULL, 0xA3CE775BFA937E8BULL, 0xA5C06DE5738D429AULL, 0x8EB0775B9841C018ULL, 
            0xF720B11BDF86557EULL, 0xBDA266D91FF081D0ULL, 0x4F766A72568C58DDULL, 0x2FF92C1122001269ULL, 
            0x447274FC2F56046BULL, 0xBF7CDC092286DC98ULL, 0x2F81CBCD290015A6ULL, 0xE434F31D6F13260CULL
        },
        {
            0x39B5F2A4CC07D1D4ULL, 0x8B1B1C557ED43936ULL, 0x33FC9B2099F37D49ULL, 0xA187CB3DF4BB067CULL, 
            0x613467A69BABF3D6ULL, 0x8C246D1918D28652ULL, 0x677DB07C7E0B6077ULL, 0xC817D1CD8C68FE26ULL, 
            0xF6D56B4202471A4EULL, 0x4C2D4B589C07BB1CULL, 0xCEFD494394562437ULL, 0x799E7E15D37B36FDULL, 
            0x6203B1684C70C5D0ULL, 0x44E7931D31A06127ULL, 0x901CD0BC6808E6D4ULL, 0x3F8B15DBBAA3A8C6ULL, 
            0xCE96DB2C0D960C6FULL, 0x8B599FD6CF5E98C2ULL, 0xB8B2F93F6943FB73ULL, 0xBD488910F3FB7D1FULL, 
            0xBD56D09C374463A0ULL, 0x5A66F42036870404ULL, 0xF85DEAE7C5022A75ULL, 0x0A7EAE9514249C0FULL, 
            0xA6B0CB6F83B2F1F9ULL, 0x2736202168EF50BEULL, 0x190B960D45E303B4ULL, 0x03AEB5EC396644C8ULL, 
            0x1C20F8E04C304AF2ULL, 0x48208D0A63022860ULL, 0xF99BA55EF5825615ULL, 0x2540B3FD1AB18968ULL
        },
        {
            0x56332B6E5591B80AULL, 0xB32C6D62FD94F479ULL, 0x12CB81563C53C148ULL, 0x8A2CD4167607B20DULL, 
            0x9B59D19651347410ULL, 0x049670BD547AF66BULL, 0x8ECC259F19103276ULL, 0x199CFA307E22F08EULL, 
            0xC18377177BABA295ULL, 0xB6CA64F7F0BE897EULL, 0xE0870880F07B72DDULL, 0xA7FF588A09E7C7D0ULL, 
            0x6E0EC84326DB2C86ULL, 0xBFD1B965DE32B675ULL, 0x5FA56AE8D04AD820ULL, 0x34184385EEA6FD53ULL, 
            0xE97E92AE920EBE4EULL, 0x1BAC005EAB88F8ECULL, 0xAA0CB11769CEFACEULL, 0xF6CFB4FED48E59AFULL, 
            0x31E21F453485BA53ULL, 0xBF4C6E380FAB0285ULL, 0x742550EF199F7FDAULL, 0x456306534E921D3FULL, 
            0x607E730D365F9A28ULL, 0xE9E56F6834DC2D50ULL, 0x63B72A10802ABAECULL, 0x868E89CEC9CD8CA0ULL, 
            0x41099F8659B02F04ULL, 0x9E46AB589D972E1BULL, 0xDF148B7B469B924CULL, 0x056D6BB1297C7E5EULL
        },
        {
            0xE9145B14D647DFBEULL, 0xE738F7530405B71CULL, 0x4188F83660B71F18ULL, 0x4D6C24537E96E752ULL, 
            0xB568F69F54097269ULL, 0x5A995356FA97DA30ULL, 0x3BA87EF6EDC6DBEEULL, 0x2D72FCDC9612D906ULL, 
            0xF3BC73EA3ADBBCF6ULL, 0x1F7AA8C8BC5BF6A0ULL, 0xF940EDAB112BB13CULL, 0x27EB80E621A87EAFULL, 
            0x646C4EB890C1D087ULL, 0x95A6114829382E5CULL, 0x1557F6F52C29CF0DULL, 0xC407FAD535E59C25ULL, 
            0x267365F4A82F60C6ULL, 0x73206BF73F5EE240ULL, 0x98D4BAAFFD172701ULL, 0x70E296168F24B807ULL, 
            0x0F4054ECF73517F4ULL, 0x52D8677EBB50EAE7ULL, 0x233953F23FA567F1ULL, 0x87016272EFA94574ULL, 
            0x49CD9C9979C351A7ULL, 0xC3580E45D3715B8AULL, 0xDF7CDB8F30DED3CEULL, 0x84957BA039D773BCULL, 
            0x37772FE4A149550BULL, 0xAA9A25F5A2F87C1EULL, 0x7EB0B8C71F4927B1ULL, 0x9CBA22676C5F58E3ULL
        },
        {
            0x484440E14F0CD14EULL, 0xBE1013F53CD989CEULL, 0x964978B48B49F728ULL, 0x934500BB7B93401BULL, 
            0x59D2EAC98731FA82ULL, 0x318DF6F17F30026FULL, 0x30A512F91AE74C8BULL, 0xBE9B8D0C7BF2B671ULL, 
            0x0299A4063833E909ULL, 0x77625C9DF9A4E831ULL, 0x23180F867649B96AULL, 0x3163BFD607E0BD62ULL, 
            0x7BBA47299ECC723EULL, 0x18B5D761F79CF1C4ULL, 0xCD9064C65C6E6DEEULL, 0x1FB1ACF60EED58A4ULL, 
            0x3C711D912B3BED75ULL, 0xAA61C2DBC3427CA7ULL, 0x9DEEFCA32097AF82ULL, 0x801C06D3EB6C0B6DULL, 
            0xD8D67CF78DC7C7B2ULL, 0xD70D8A210498F567ULL, 0xAE1C8A715A8CF017ULL, 0x8C73D259521A4C61ULL, 
            0x61C10624163C489DULL, 0x609D5951DE2C0497ULL, 0xECAE0493DDDBC133ULL, 0x892221368DFFFA44ULL, 
            0xDF3ACAF026B097C0ULL, 0x687FC545008B7955ULL, 0x0987E82F3B757AAAULL, 0x2D535FD4DDE67B6EULL
        }
    },
    {
        {
            0x4290A2B37072CEB2ULL, 0xE208AB7559A43F5BULL, 0xB21AA33DA5F7CCA4ULL, 0x34294418A1D6D4D0ULL, 
            0x51EF309ECEAFD374ULL, 0xFEB7C499A8EA4CF0ULL, 0x4DF66B7FD948E250ULL, 0x9D13F498817E1FF4ULL, 
            0x0B9A36179F51303BULL, 0x651F85DBD080DFD9ULL, 0xD757DC3589B389F5ULL, 0xEC7609F3B043DE3BULL, 
            0xEAC06D4A90514467ULL, 0x6904B95EAA5BDBA3ULL, 0xC0744BFB42F1A14DULL, 0x283D94E6D7594B9DULL, 
            0xF681F82EB66CF8FDULL, 0x953BFB1DF2F5F223ULL, 0xBEAAAD0106FF90FBULL, 0xE2BADE8A64917224ULL, 
            0x2A1ED96776242265ULL, 0x7D11FC75C3B111E7ULL, 0xF38BDAFEC961984EULL, 0x18DC68364C14CCF1ULL, 
            0xF353798FC8874B77ULL, 0x84F02DCEDB6D5E79ULL, 0x62A2483BBAB3448AULL, 0x913D801C953428CDULL, 
            0xDD48A7AAB03AA20EULL, 0xF7328E3D1C020A50ULL, 0x72DE9C6A3896F04CULL, 0x4599ACF4F8FC7C88ULL
        },
        {
            0x03FC898412F8BCDBULL, 0x0DAE42A6685C7120ULL, 0x8D57E5499BE42B1FULL, 0x02507D6733754B8AULL, 
            0x9DB865E84E8DD204ULL, 0xDF33CB5CFFC30B11ULL, 0x76A015D25B0C660DULL, 0x91BC173325BE812BULL, 
            0xD48F2BAEAAC8F040ULL, 0x65E1F6997D5FD95BULL, 0x27925B6FB0742005ULL, 0xC1D619324E5993D2ULL, 
            0x36CD802A4B9BF088ULL, 0x49BC5F889A6AF42FULL, 0xEF5A23B024F3D381ULL, 0x2A1927F36781D6ABULL, 
            0xF40FE905EC32799BULL, 0x83FFC22BDFC45229ULL, 0x5BCA3B81154A82C7ULL, 0x13ED92B195B7AB4BULL, 
            0x8F14CBA1E21D46A6ULL, 0x8C20CB00171D0E7EULL, 0x7F476620B1C06E9EULL, 0xCB00FFB4C89C5C2BULL, 
            0xF8C0B30DEF703CAEULL, 0xBDB1F3C66DCF204BULL, 0x2553015DD7F5C335ULL, 0x8FFF80F8FE74E5B4ULL, 
            0x989D9380CFF4CAD5ULL, 0x71B66AFBBA3D69EEULL, 0x563CAEAA0B63BC80ULL, 0x622845EDAA1B3B4AULL
        },
        {
            0x4DCCC37FFF6AB8F1ULL, 0xB753B2D3401D30DCULL, 0x64E54CEA0C3A97F8ULL, 0x0668D51FA38E5067ULL, 
            0x2243232D8F52EAB0ULL, 0x54BDB486109049D2ULL, 0xB1A68D765398C877ULL, 0x95AC207376727A3BULL, 
            0xC32AEF1EFB95B37BULL, 0xDC5768BE05FBA3A4ULL, 0x9C71216115B9EFE2ULL, 0xB718091C79676991ULL, 
            0x9B0DBE31E2C84A2FULL, 0x106C611625C5037BULL, 0x9B0563EB562988CBULL, 0x935E3545B41384F5ULL, 
            0x1AED5C942F3D09A3ULL, 0x5D56095F06A28348ULL, 0x32F6EEA07589F662ULL, 0x94A5C057AAA58C7AULL, 
            0xB84F8AC9FA061F02ULL, 0xDCE7E50D1CC6D2E5ULL, 0xBE98102D50118D74ULL, 0xC561443C1E0D1CCDULL, 
            0x387D7B27484D54AEULL, 0xAEDF9069A9238AA0ULL, 0xB2BE3257A27FAE03ULL, 0x8DEA957E38739B68ULL, 
            0x5767D6F8AAEFFE43ULL, 0x646E86325713B90FULL, 0x0B496404448FF34FULL, 0x82DB9E00969C656EULL
        },
        {
            0x70D61D6B69C68920ULL, 0x8BEAD5E472DCF9D2ULL, 0x63416EE3329CAEE3ULL, 0x55F1B5EA7FF486E5ULL, 
            0xE2538D5290B389DAULL, 0x01C5AAFC776604E2ULL, 0x9C6A53AE7C2BE800ULL, 0x9219F7E538AAEAF3ULL, 
            0x8CEA8A03645E9E79ULL, 0x795DDFCED0E340C0ULL, 0xF195CF0BF79A084BULL, 0xD5B515775E829A2BULL, 
            0x10F1B7373111B336ULL, 0x8866C6DADFFD1CD9ULL, 0x6FC4B4923F60ABC3ULL, 0x7FD398263B73D492ULL, 
            0x26A0CAA7527655B4ULL, 0x0EFCDD80C6168FB3ULL, 0x011C514F1872D649ULL, 0x04CD07AA5FB19CEFULL, 
            0x0C290441C6725EF3ULL, 0xA1563938BD4357BDULL, 0xF48DFF991B222D13ULL, 0xDCFE152A558B20C9ULL, 
            0xB849C0E03477F77AULL, 0x8314CFE7C18EFE62ULL, 0x74CE29CBE1AD29EDULL, 0xB74CD8B5634D74F7ULL, 
            0x8B1EEE84998A6C1BULL, 0x5E5A1F917DB32B51ULL, 0xA7AA2A739B942C71ULL, 0xDEDE86C94B9DE005ULL
        },
        {
            0xB0FC89ADBD228361ULL, 0x15196D885983FE3AULL, 0xFF99405733F128FAULL, 0x3FB0578B430EA3AFULL, 
            0x4F8128DCCA93012FULL, 0x8C4BBED43C3F65EFULL, 0x05852584301940A4ULL, 0xFBE514856B39A618ULL, 
            0x41D3A3959EBAD788ULL, 0xEDB7B10ADC688D90ULL, 0xA5390E48C6228A72ULL, 0xBDB50276951BD7BCULL, 
            0xDF804E319A3A203EULL, 0x37E2FBEFCC59275BULL, 0xC2428AB0073AC547ULL, 0xE4ABDA18CB999B8EULL, 
            0xAC3CD18E9B767D13ULL, 0x64F4B76B58C5301BULL, 0x004BA023062AB53DULL, 0x33E9812DE00A29F0ULL, 
            0x972668253C57A39CULL, 0xCF25406EC6B1D210ULL, 0x749FDB6513D41BA3ULL, 0x1A27088C34876C42ULL, 
            0x3A686F3F6137EC9CULL, 0x01C5C6D06E0468A4ULL, 0x9D2B35385583C602ULL, 0x015F0442156E7F72ULL, 
            0xC4D7D3F4D737FBD2ULL, 0x0543F09CC15ABA09ULL, 0x66C8BA12B2236891ULL, 0xBEF1B084B2A095C8ULL
        },
        {
            0x9AD836FE6F6B11A4ULL, 0xA1A66266DA9A4390ULL, 0x74368216DA7AD235ULL, 0xEF596DBE6A6E5ADFULL, 
            0x6D08030491C1112BULL, 0x384921B17F62F9A5ULL, 0xAB51F28383336715ULL, 0xC229B82FFD5EEEBCULL, 
            0xD9A7F4642817C578ULL, 0xBCB806D5D9FAEDCAULL, 0x9DFA9B8AFBD6B964ULL, 0x34533DA7F9B0457DULL, 
            0x026864CF4A6429D4ULL, 0x2DDDDA4434870D32ULL, 0x7254CDEBE101F82FULL, 0x032BBF60EA1717A3ULL, 
            0x00595CED44FA2A14ULL, 0x65ACF18852BE95A2ULL, 0xFBA0AC96748D01D7ULL, 0x4160B2994DF0F28DULL, 
            0x5F456850167D1252ULL, 0x54D1296A005B0ED8ULL, 0x697E6296B092571DULL, 0xDB85DBB08BD8F3E6ULL, 
            0x0A2A58A60EA8B0B1ULL, 0x1728D95989AD046FULL, 0xBDEE6A8849CE06CCULL, 0x2B31498DA274CCBEULL, 
            0x1B10E018706CED25ULL, 0xE84E9882B59427D2ULL, 0x7FE143554DA213ECULL, 0x6A6B87E57C8E7EE5ULL
        }
    },
    {
        {
            0x8BE020362FE3C747ULL, 0x4B4E5FAF9A698110ULL, 0x1F9FEF06F1A34CBFULL, 0xA9EC2A0549736DEAULL, 
            0x48D0EC51BB3286C8ULL, 0xE50DED318E7D3D85ULL, 0x5B7B36296BDFED6EULL, 0x5CC236019D32BA84ULL, 
            0xC549B9C5159F3911ULL, 0x6B9D554BD0F04FBCULL, 0x06F637C55158FBD6ULL, 0xB1E9CDD2AC625477ULL, 
            0x2EF16ED45D97DAF9ULL, 0xACA74D3A5EFEA94BULL, 0x8CFBE90CDEAA2C90ULL, 0xBB4ADA45C44F98E5ULL, 
            0xDF22517A13FE77C7ULL, 0xDB44595066B7C54CULL, 0x7843FEC4CB2FC22DULL, 0xFEBF735CF5FDC160ULL, 
            0x5E2A9AEC09DC6CBFULL, 0x721D241118D90161ULL, 0xB497953B50DDEDA4ULL, 0xC5A18CF33672C39BULL, 
            0x5D49C07D38EB04E8ULL, 0x588B0EF72291ED7AULL, 0x6D50CFBDC61D6657ULL, 0xFE4FB51BA32D024FULL, 
            0xBA6EBD0FA7BCACD1ULL, 0xDB439D79D494CB1BULL, 0x0B9AAD70EF61466EULL, 0x2A0866059D7435B6ULL
        },
        {
            0x26B0E450B4529C0AULL, 0x6B0B9825E41F2222ULL, 0x2B1028CDB8703BB0ULL, 0x74C0AD931228AFABULL, 
            0xC1B1D3924F2E693FULL, 0xDC7BDD88BCB817A7ULL, 0x8098D76B196D7EF8ULL, 0x1AC54F05320F69D7ULL, 
            0x3463768015E407B0ULL, 0xCC42F59636131BFFULL, 0x2E6806C7C9F463FDULL, 0xA0FAA48A898878EEULL, 
            0xFD283CBEF2661098ULL, 0xEC2C94FAB0B85745ULL, 0x697B55590958BE82ULL, 0x80DCDC03AC5CCE3EULL, 
            0x687FB6A50085F338ULL, 0x8EE8AA32BE472806ULL, 0x272C6647CA0FB75DULL, 0xB37A4FDC59342990ULL, 
            0x311829C78D9B2FBFULL, 0x20AC278E9B77CB77ULL, 0x9A290E244C05B167ULL, 0xAA201697804BE26DULL, 
            0x924BC6327EFD868BULL, 0xC91FA07B57518A44ULL, 0xD70CBF780EBC087AULL, 0x6C2C837C4AE2F515ULL, 
            0x02693CD6BF9EE911ULL, 0xCA640640CEA35C9BULL, 0xAB1D37397428E07EULL, 0x22090E1232603161ULL
        },
        {
            0xB4ABD3BE5769D7E5ULL, 0x66539A6D75A003E8ULL, 0xF8D0494616D98ACEULL, 0x3F288A4C3CE210C0ULL, 
            0xF2936DDF2E7289D0ULL, 0xFF61081D5D21EB31ULL, 0x4659E7BCE27661A8ULL, 0x1AA1D1F7860E946DULL, 
            0xF979AB3DDD059502ULL, 0xA4293177C91EBD4AULL, 0xAA6C0408DEF834DDULL, 0x442E259DFA8A4727ULL, 
            0xD624064CC15A1773ULL, 0xE422F01581E7ED82ULL, 0x4A20587A427B1BF5ULL, 0x470D005E571F6748ULL, 
            0x234F84F925C8AA18ULL, 0x2EBB40EA83853CF0ULL, 0x82EBC2C9F2928338ULL, 0x3E204576BD564FB8ULL, 
            0xC0F9C58D3E0C6933ULL, 0x87D7C2FD3482E5E8ULL, 0xE1A447FEB98B31BEULL, 0x533C188A29D8267BULL, 
            0x00AD260C664E3FC0ULL, 0x4112C4FF3C2D3F88ULL, 0x0912235E62CBCE75ULL, 0x6D82E82051F895F7ULL, 
            0x7C839033F04449F1ULL, 0xCB022A81C0B4F9FAULL, 0xC48F2C10EC8CA530ULL, 0xEFEC98855044A93EULL
        },
        {
            0x249484EDD67338F6ULL, 0x12F44562B97BC951ULL, 0x70F07EB348865AC5ULL, 0x564EAB6DF6FFFF12ULL, 
            0x3E839B40868E44C8ULL, 0x9C1FA5BC75300167ULL, 0x2B29B3763194CC29ULL, 0x0625563055A4C4ADULL, 
            0x8D9408685302C4E5ULL, 0x0A0F9DBA4E1173BAULL, 0x3C858AE000922ED8ULL, 0x58CD398EB2987C76ULL, 
            0x2BF32B9898928ABCULL, 0x97A16D82B62C20FBULL, 0x2BCE8807A5367F96ULL, 0xB87A10C2743E5AADULL, 
            0x3D77052AA173B5AAULL, 0x9A82FE05DD8A07B5ULL, 0x9F6BE0049D8AA0AFULL, 0x688D2A5E2A5C82D6ULL, 
            0x0C5DE8CF5CD7656EULL, 0xA2A278F07B527D5BULL, 0x0A915ABAB35E6390ULL, 0x4DA3F331F4C6B055ULL, 
            0x7C27E22E6C25C268ULL, 0xF0333D26C817EF42ULL, 0xA9AB8609B2C964BDULL, 0x850AA85A11A31E1FULL, 
            0xDA8CBDA17D9F7A5FULL, 0x11A1C5C77845CA94ULL, 0xA9E70FDE16B57395ULL, 0xD4BDA2C13AA8D761ULL
        },
        {
            0x884745E857CCEB13ULL, 0xCF0980629D936FD4ULL, 0xABD3C963371FB461ULL, 0xA11546507132074BULL, 
            0x9B5CDF783D166A21ULL, 0xE192C01176EEB4CBULL, 0x14AF0149224E65FEULL, 0x68932F2842845C54ULL, 
            0xFC183EB9EB32A41EULL, 0xE710EDCB4C851D24ULL, 0x61A2A6EAE99F2A4EULL, 0x8DA51332F8259EACULL, 
            0x64E8CEF1AC5519F4ULL, 0x558E027EB46E220FULL, 0xB9909E157A7B82DAULL, 0xD1E9A6882916820CULL, 
            0x1E404D0894B87D43ULL, 0xCCD202A3456D1E73ULL, 0x695040DE412338E6ULL, 0xE012207B4AB320D9ULL, 
            0xF331FBA3EAB99908ULL, 0x36ECB8276922FD70ULL, 0x9F74DF0CCFA192F7ULL, 0x323DB2525BF2ADC5ULL, 
            0x42E82996FA8571B4ULL, 0x532B64C42FA31AF1ULL, 0xC67934ACDA0C9D3CULL, 0xECF6B484D8A2647DULL, 
            0xF5D1C378B580C724ULL, 0xEE7C776618DC80CCULL, 0x32E19615BE66A518ULL, 0x1B26691FE85A6071ULL
        },
        {
            0x8B1991FFBC039331ULL, 0x12A372043C6264D4ULL, 0xA5A547977BCE12A5ULL, 0xBB1DB5C3BDD2EF9BULL, 
            0xBDFEDBC2907C4B93ULL, 0xAD2C18D31D480D19ULL, 0xCBDD66D508CF02A0ULL, 0x5B7A80B9A569AD92ULL, 
            0x5F510187F1AFAAB3ULL, 0x241A6185C8B91C6FULL, 0x8AC7C2A825D30B9CULL, 0x28C9BA8A27B93794ULL, 
            0x60833A1E52D9CF78ULL, 0x3605579C3CBE4AC3ULL, 0x79B2D4C1801C4197ULL, 0x5B8D6AC8DEFF4043ULL, 
            0x44B7B178FEF257CFULL, 0xAC4608BB612D379EULL, 0x4F5C65A0E3CDDEC2ULL, 0x0202F556F8BE4469ULL, 
            0xAE1143A47FAF307FULL, 0x51ABFF8868CBBED9ULL, 0xFEB2295DE0CEEBC2ULL, 0x555E66600C56C5FCULL, 
            0x909641A878965C56ULL, 0x6AB0DC52C8F6958FULL, 0xC6B1338806CA9148ULL, 0x731DF59E124B6F8BULL, 
            0xAE2A464E0C5FDA28ULL, 0xEDDC792E0F53BEA9ULL, 0xC66219C8DEC3D5E0ULL, 0xBC68801C5107C22CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseBConstants = {
    0xA8288F417B70E8C8ULL,
    0x4E1C1A65EF8B1F63ULL,
    0x2995FC8B22332F18ULL,
    0xA8288F417B70E8C8ULL,
    0x4E1C1A65EF8B1F63ULL,
    0x2995FC8B22332F18ULL,
    0x1E02B788B0FB89F3ULL,
    0xB3A2B16513AF8A30ULL,
    0xD7,
    0xC9,
    0x34,
    0x4D,
    0x8F,
    0x9C,
    0x8C,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseCSalts = {
    {
        {
            0x3F474F032DE9F2BAULL, 0x0F2B4ABFEEC89402ULL, 0x38441E8A657CE25FULL, 0x45F8700C2760100AULL, 
            0xC686DA492395C26DULL, 0xD89344C9DCDFBD7EULL, 0x274A8FA42AFE3325ULL, 0xA9FE6DFEF60493A6ULL, 
            0xB2ED35E407C3978AULL, 0xDA4029080752046BULL, 0x31AA4F31AB1BB899ULL, 0x5259BDDC36D61CC3ULL, 
            0x98C6F61E04F6A5B3ULL, 0xBA7C86128FEFE441ULL, 0xC2AAF9A9CA2070C6ULL, 0xCB8CF1E3C2F7465DULL, 
            0x4A52A620201ADCC8ULL, 0x4094C7E6C5854049ULL, 0x82A1F67E0E84C7BEULL, 0x0570D323A3E8B30AULL, 
            0x99676ED67180BF2EULL, 0xE10A8ED0E6B9E8F6ULL, 0x2AD0411DB850BA74ULL, 0x1B3EA9E0899AE4F1ULL, 
            0xA53D3B4E1EA324CAULL, 0xF55CE5D903DEB47AULL, 0xE29836F01CA9E28BULL, 0xF7E40C57171F28BDULL, 
            0x08ABFD5CF438F969ULL, 0x7BBFF622386631C3ULL, 0x77FBA3BD0C384121ULL, 0x00C39AD151C7F2AEULL
        },
        {
            0xC80CEFFB8D01F998ULL, 0x9815B2CDD25905A3ULL, 0xD6CA78614A58C1C5ULL, 0xC792913951AB7CEDULL, 
            0x7C63BEE338CBEC48ULL, 0x5FCB892040C680D2ULL, 0xC4FE753407031C55ULL, 0xCA45AA1720A99232ULL, 
            0x6BA56BE902958D8DULL, 0x3679BC2BC91F6093ULL, 0x29B2C7823135B099ULL, 0x519C7EB7FEC06699ULL, 
            0x2D75CDAB66F00831ULL, 0x44F8F8669DB0557AULL, 0x215F9199AC768168ULL, 0xA7AD23AFF3211AB7ULL, 
            0x4FF365DB6D08EE5AULL, 0x7F0BC9A78566DBE3ULL, 0xFC13C0E6DD0F8442ULL, 0x93339D43BAF842E7ULL, 
            0x8A23B23627804502ULL, 0x265C58C4BCB0109DULL, 0x669CDB7D013C746DULL, 0x2DBF9975A82DC7CCULL, 
            0x6877BCB7EF46BC61ULL, 0xC2B8B65070EBB8BCULL, 0x3C4A850A7E5EB68AULL, 0x3890D14FF7CEF1D8ULL, 
            0x89DCCCCC7979B17CULL, 0x68BCE6D68800698FULL, 0x3490287A6155987EULL, 0x0EC94787C11E5D7FULL
        },
        {
            0x36FCE52CCD8FB082ULL, 0xC75F41E22878F3B5ULL, 0x8703FFDD1496559DULL, 0x4617F25DBF3F9D76ULL, 
            0xBA0E7F5BEF63CCE2ULL, 0x9E588F88ABCE6C96ULL, 0x1BC5ACB3E10B7F93ULL, 0xDA47B0D7535620C7ULL, 
            0x9FAF2D259194B2BBULL, 0xD9F444F59D776AACULL, 0x996C224689BE93DEULL, 0x0471749A6340554DULL, 
            0x2AC8CE9754D03928ULL, 0x25D57B339C52D839ULL, 0xD34A8973B46860ABULL, 0x8CE5C346C7C701F3ULL, 
            0x827681EFF3F36431ULL, 0x1093AE28272B1B39ULL, 0xF72AD2D852E14296ULL, 0xA75ACD1EADA5B033ULL, 
            0x8228489B8E2CF1AFULL, 0x12C2BF22460624A5ULL, 0xDFF517C25BDC6C89ULL, 0x0CF4678BEEB5DE2CULL, 
            0xE5A32BA33FC7E31FULL, 0x0D1DEA242201CD62ULL, 0x2912422D6CE675A8ULL, 0x48D37807F6906999ULL, 
            0x63FF66C121267694ULL, 0xA1E513C04B899FF3ULL, 0xD757BF9E7256A0C7ULL, 0x5CD6289DAC76BFA5ULL
        },
        {
            0x9C97F51D84B2D829ULL, 0x54E83B9AC751C993ULL, 0x61F934D58C73D235ULL, 0x75FF0988654EF6A6ULL, 
            0x79072BCFDE4BD07BULL, 0x761D1273808DDBE1ULL, 0x7706B4ECA98C208BULL, 0x117CCB0C48920B3EULL, 
            0x4DABCCEC49F60341ULL, 0x387F060B9310A558ULL, 0x380120351A121198ULL, 0xC5C12F2FA6E986ACULL, 
            0x8AD2351EADDD4B33ULL, 0xA2EC1F606A47C14DULL, 0x873D20D3E04D8496ULL, 0x85A56CAE52BFE946ULL, 
            0xB9A5E3D612541FC5ULL, 0x91B8AC7E8AD31D0FULL, 0x83C6FA50B8B1CD9EULL, 0x42594550412531F5ULL, 
            0xA4597144B8E52E6EULL, 0xDAD2ED28E07DE818ULL, 0x82A1DE9954E7C102ULL, 0xE873CBA0CEB24978ULL, 
            0x7CEB522FA188BC45ULL, 0xC79265F604B18389ULL, 0x41BB8CDA03C6CD1EULL, 0xFA511B5D06CA6D92ULL, 
            0x430BCD7E7645B9A0ULL, 0xB5FE9A1F63103FC2ULL, 0x71080A53652A08D1ULL, 0x2E7B6987C30BC8E5ULL
        },
        {
            0xC6A2D830540CE4AAULL, 0xF14F79788722B67BULL, 0xF19C9CEA0E06CF31ULL, 0x8D6F150A33248A9EULL, 
            0xCA2222DAF21E5455ULL, 0x7FC050806F2455CDULL, 0xBF3278CFA0934587ULL, 0xE5B8A8C9478B25BFULL, 
            0x272F794E71FD4C32ULL, 0x897DF4191761019AULL, 0x78347CFD706F6989ULL, 0xBDE35812EB293884ULL, 
            0xAA0A317676C1344EULL, 0xB9E70E7ABCAA7AA0ULL, 0xC20B6327014E6819ULL, 0xB416601C65C1A112ULL, 
            0x87E8C614B71F9C2BULL, 0x6B83B8C21B493034ULL, 0x0B5624A63FEC308CULL, 0x44CBEF09777ABA1FULL, 
            0xE5F4B14277DB6A17ULL, 0x7DEC775A57CA5751ULL, 0xDA1540132CD5508CULL, 0xC0F2B430DA1F594EULL, 
            0xE095FE1B231FDB4FULL, 0x240C18E09BD289BDULL, 0x1F210F305012A3B7ULL, 0x0FED3CEA365D072CULL, 
            0xF87286658900014BULL, 0xAEB1ED3E6ADB90C7ULL, 0x3EEA9656A5C7FA30ULL, 0x8D1BA1AAF8765AA3ULL
        },
        {
            0xF50DBA0A3FF578D4ULL, 0xD8BA7EEF0A9FABCEULL, 0x07533237F07A0280ULL, 0x5BCFBD2B3B375AC8ULL, 
            0x609AB3ACB5935F94ULL, 0x33D64135F7A853F9ULL, 0xFE49F40E2BA1CE80ULL, 0xAE54ECA36CD95ED6ULL, 
            0x27B83CD9295B1E71ULL, 0x804A4F3D5C9267E0ULL, 0x157743B795C11A2EULL, 0x90B8B4D265F4D9C8ULL, 
            0x3DB60D4F2427E1D2ULL, 0xC6A6836C9C2E59E2ULL, 0x938C937B82C8FDC0ULL, 0xB8EDA024C56B0EEDULL, 
            0xDD26F6804CE95D63ULL, 0x2E1D3042E202C5B8ULL, 0x97E8FA878A5B74D3ULL, 0x868C4F5BC3E64C33ULL, 
            0x9E788928F0A1DC0FULL, 0xCAB4540D34C5E286ULL, 0xA77CFFE1678EC42AULL, 0x97DC15CD75679D7BULL, 
            0x778AA48EDE38745EULL, 0xB4F128C773386144ULL, 0x3D4FF0535B901938ULL, 0x12D41CEDB256C683ULL, 
            0x8631A3E0DABDD574ULL, 0xD8E8BB37FED1D3F9ULL, 0x2D66A1E1F8A37ADFULL, 0xF13F7BCD51EE9A86ULL
        }
    },
    {
        {
            0x35D0DBC6E5D1BEADULL, 0x8056AC5F8F584720ULL, 0xE6DBAC418A764037ULL, 0xC35E7D53CD501AA2ULL, 
            0xD9220BFB2966849EULL, 0x8E022D686916A239ULL, 0xBD20BA677E642020ULL, 0xE03E25F0C45FB6C5ULL, 
            0x1B6F3BA574E4FDFBULL, 0x2899F0739B1C8909ULL, 0xFC7AB085B0A0A269ULL, 0xBF1CE98CF11B1F3EULL, 
            0x6ECFDED5DC5A9348ULL, 0x5F19A06F1413EA0EULL, 0x27AA2FA1CD5FDDE8ULL, 0xBECE9318CCA1DDF3ULL, 
            0x2F25A9BE51923778ULL, 0xF398994F82A0A3A0ULL, 0x3D51F136E9E563BCULL, 0x4D7D4305DB1349CEULL, 
            0x8338D98DE8B67C0AULL, 0x13C99BF34C0F7856ULL, 0x735A969DB14C554AULL, 0x71DDD14A8BBA5B86ULL, 
            0xECDFD2FCBC388729ULL, 0xF280F8B4F5C37A5EULL, 0xA0AD490E0E0CC8EAULL, 0x9BC9079DB3E57402ULL, 
            0xCE1C618C31B620F0ULL, 0x2EE851FDE27D5FBCULL, 0x5A7157975033C0D1ULL, 0x9DDF37F0118F5D05ULL
        },
        {
            0x2909A52519D9F24DULL, 0xB542F99B791930E7ULL, 0xACE4EC84A4B84554ULL, 0x2E5849DF2254A534ULL, 
            0xEC23E8F3C5AB328CULL, 0x133DF40D240B3EEBULL, 0x80CBDA5E108A0EBDULL, 0x790299E027B06F33ULL, 
            0xEF1FCEBB57476382ULL, 0x2BE79C449E6DBA25ULL, 0xC7BF2C0898FCCE3FULL, 0xD036932CCE28B5FAULL, 
            0x2DD85EB50C33DE11ULL, 0xF0A86FE50E199920ULL, 0xFFE5EAF6482236C7ULL, 0x8EA546C4B7723B4DULL, 
            0xD83F742C9C770742ULL, 0xE6D1B57F1C354882ULL, 0xC098A94D112A2377ULL, 0x855F16AAF8FB892EULL, 
            0xA2019CBC8C5DADCDULL, 0x14F36CFF893B994BULL, 0x74FF44188AF6D953ULL, 0xF68F01E72FFCA55AULL, 
            0xA6E21E815274F8CAULL, 0x32E5F8AF0C99E733ULL, 0xD5196E09B070132DULL, 0x98234BD2FC55F65DULL, 
            0xAE2540471D29A380ULL, 0x41B9BA36922172D2ULL, 0x17F036E78966F758ULL, 0x35E53764664C3EA3ULL
        },
        {
            0x342324840DA4F4F5ULL, 0x09CB8CF6D48A031BULL, 0xE0CD2E30DC8EB49EULL, 0xBB1A6B56AB98DDC9ULL, 
            0xC2E8164587F4BDC4ULL, 0xFFDBEDF5225FA711ULL, 0xF4B2429A90980342ULL, 0x97CD0C193E40176EULL, 
            0xEE71F8C410C09D44ULL, 0xF9507B13F54B03B8ULL, 0x98AB0A8A34F44F61ULL, 0x437CE77DF63010F5ULL, 
            0x076865BD9E30C401ULL, 0x1E22151C019DA258ULL, 0xEAA3A6E5C6169786ULL, 0x8E233AD9E9025C98ULL, 
            0x348A590E4DD4A573ULL, 0x51B97005516F86C9ULL, 0x6014BDA728F3AF41ULL, 0x783B2D46A46BC08CULL, 
            0xDBB9F6C61FC4ED21ULL, 0xBAFC145F1082D2CDULL, 0x9443BE7C79E7F827ULL, 0x6C758BB15B826DA6ULL, 
            0xF3A59CB4D1B95321ULL, 0x8CE5A0FFDDF70D72ULL, 0xDF02E0E491798BD5ULL, 0xCF0E578F0A716451ULL, 
            0x2DDE258E9038583CULL, 0x36C5B954E8152D9FULL, 0x1DA719371410E863ULL, 0x4A1975B24E52D42CULL
        },
        {
            0x62EC7333D08E2FBDULL, 0xF91C5AE47CE758A1ULL, 0xA6CEB0A090933504ULL, 0xA7A2C067D94F31FDULL, 
            0x08553CC6FD73FFBEULL, 0x11E00BD8FEC2ABE9ULL, 0x40E7882D21B81A7DULL, 0x8C3B48CEE6CCA65AULL, 
            0xBCC088FE92F9E50BULL, 0x5977718F162396C2ULL, 0xF0F7E5356BE1D168ULL, 0x41D374DC58F73940ULL, 
            0x3E60EC85F497BBD7ULL, 0x0DBB23BF1C1121AAULL, 0xED5D95284871CDBFULL, 0xB96850FCC9EE126EULL, 
            0xD454307339FA7B89ULL, 0x1952F2F8F0FF71C8ULL, 0x29DA5365DB3ED6DFULL, 0xFCA4815CAF09FAA7ULL, 
            0xE084A192E2D90486ULL, 0x1978F410FF2E51B5ULL, 0x65A26CCD38EF31ADULL, 0xA245BA2707BCF1F9ULL, 
            0x85CCE6182C2D944FULL, 0x927411964F674856ULL, 0xCC2216595476D689ULL, 0x7DEB4D3A3884E0A7ULL, 
            0x6031B02A4EB070C1ULL, 0x0DB4696E3995A1C8ULL, 0x1814203F5F8DE995ULL, 0x80924EBFB140D484ULL
        },
        {
            0xD4423E21FF2CDC4EULL, 0x451E75A8F986E876ULL, 0x3981B8DBD4B6DD1AULL, 0xC2CA7E200F0CED54ULL, 
            0x539602038C4D05A0ULL, 0xC233EDDD741744DFULL, 0xC44D783C4E91324EULL, 0x39976B2DF0FFCACEULL, 
            0xE75879401E3D997EULL, 0x70C20B04B9B84580ULL, 0x9452C90B47A4B4D7ULL, 0x8B8E6AF10DB81E9FULL, 
            0xC90077A5D34032BCULL, 0x5DAF0B6428224020ULL, 0x74A826AF1F78F6E9ULL, 0xDBF49DC8F78674FAULL, 
            0xCC0B70FC46A7ABBCULL, 0x3006B615716F8424ULL, 0x8D1A2D99819093A0ULL, 0x7F4D64F936ECEBE8ULL, 
            0xBA704F380229E962ULL, 0x11B39FC40A79BF58ULL, 0xE8405482046A6EDCULL, 0x8E50997CA79D2754ULL, 
            0x2569CE758C819456ULL, 0x07BEBA495B2AED6AULL, 0xD59039607FE78B2EULL, 0xE4DD78A9B9D18906ULL, 
            0xA0790C176526476EULL, 0x1CB4D87EBB1A3CB5ULL, 0xD537A06DF8CCEC01ULL, 0xC7A4C01CECE4F45DULL
        },
        {
            0xCAC72CF68090C0A5ULL, 0x3EDD32ECC090698AULL, 0xDB41C2CA9413006FULL, 0x4F4BDB52D74EA3DAULL, 
            0x0A138DDD936BB31DULL, 0x5C4EF918E001BA00ULL, 0x2461FBF88812A340ULL, 0x1F0AC12A9A6317C6ULL, 
            0xD427C1AE4D5616C7ULL, 0x80E5AB4C1F73EE94ULL, 0x976814E4E243B6F0ULL, 0x0CF80A87F64A019BULL, 
            0x9BE2B82A241B7EA3ULL, 0x7FA83094192E9527ULL, 0x8BD1441F3B0D18BEULL, 0x473CA3244E70157CULL, 
            0x494F69DB584FB783ULL, 0xD8675E65142EDF4FULL, 0x9D565BD2E930D5F8ULL, 0x47D5852BE70706C8ULL, 
            0x02DC99CD55891F5FULL, 0xCA7C57F931D69AFEULL, 0x9F63D57E3EE14F0AULL, 0xBF050001908A08C8ULL, 
            0x1D4B40E2865021FBULL, 0x24041C44F801AAC2ULL, 0x8832B8330A04D099ULL, 0x99D0FB1A1CD13494ULL, 
            0x26332D80A18E5573ULL, 0xCA618E70F75E798AULL, 0xEC56D39DA2668268ULL, 0xBA730E3F9E4A8B10ULL
        }
    },
    {
        {
            0xCC1A41F2B81211D8ULL, 0x2301E8B06C9CA8B5ULL, 0x5D07C42F2B782754ULL, 0xCC91526F32650E17ULL, 
            0xF6FAE7E026423706ULL, 0xD497F788B333C708ULL, 0x2E90AADD76EC0385ULL, 0x6298960CF6F5E0EAULL, 
            0xD503DF915596ABA7ULL, 0x1903D27ABF422ED7ULL, 0xDB078AF2E24981F8ULL, 0x4B0E2F706628FD66ULL, 
            0x873C56551BC6E6CDULL, 0xE231E31B31C41615ULL, 0xD26FC71BA0DC3251ULL, 0xE7B79D3616E98932ULL, 
            0x88EFDC4B3BB43912ULL, 0x66F7C4E19D019185ULL, 0xD7FE046754994266ULL, 0x1CF1E0B57ECBD4DAULL, 
            0x422F83280CADFC03ULL, 0xD01AAE8CF34598ADULL, 0x5159DD5553CA073EULL, 0xE137515B57CC34D1ULL, 
            0x704AA0C7598F829EULL, 0xC3D189F100740194ULL, 0xDDDF8B62292087F8ULL, 0xE109356EA83F97D4ULL, 
            0x81B35A50990E06BAULL, 0xB6E424B2F003EC9AULL, 0x139E300150D2892FULL, 0x3E5949C8C8379617ULL
        },
        {
            0x7400C8A376BB3D53ULL, 0xEDECEA47E962C7AAULL, 0xC5314AD44E6AA9D5ULL, 0x844948F9FE433972ULL, 
            0x466FD15004D37AD1ULL, 0xF9A56278C730EE87ULL, 0xFDBFB3C18FDDA02EULL, 0xE5363F498C1B2A9AULL, 
            0x869A4DFC0F0494E0ULL, 0x7C422B4F5B913141ULL, 0x5EF72007B94F8E91ULL, 0x172F262CF9EC85A2ULL, 
            0xEF279FA78F8AD93FULL, 0xACE7B640ACBAD92FULL, 0x34B3AC7491ED199DULL, 0xF44C87221B75BCCEULL, 
            0xE1D74BC1FAA07FFEULL, 0x1D07314F1CAD320AULL, 0xD43B06334FA7065CULL, 0xB2E3D65C94597735ULL, 
            0x03B97F721F4432C9ULL, 0xC9CE3FEE09AC65FEULL, 0xD6F703E39FCD762BULL, 0xCD5780764C88A365ULL, 
            0x3C88D3D3A3E09E1FULL, 0x0A48B94C04251A51ULL, 0x5F9DA0F5B0A11BEEULL, 0x6C658574C65A0C57ULL, 
            0x6013F155E1804742ULL, 0x3C366A78D53D19EEULL, 0x5C6B2C5209ED7F79ULL, 0x1B972E02B2C4BD85ULL
        },
        {
            0xFF182949212DCBF2ULL, 0x01F701D1F69255BEULL, 0xB2580DD20FAF7466ULL, 0x71FD20E6BAC78D00ULL, 
            0xE8E0CB66D842BC95ULL, 0xA6505C20D16C7D25ULL, 0xBDD182F92AA89423ULL, 0x856C6FF920415343ULL, 
            0x708A20B3DAAAD71FULL, 0x3FD6020756BF7F0EULL, 0xC6B2601C710EA071ULL, 0xCF9199D0B6B64666ULL, 
            0x901EEE8329A744CBULL, 0x2533253C6FD6610EULL, 0xC88F978BEB93C338ULL, 0x3171F02FDC49B090ULL, 
            0xF13BD1576AEEFD17ULL, 0x22750535581D47B1ULL, 0xDB97E80FC1666FF1ULL, 0x964758B1A6742BD0ULL, 
            0x8CA718022A3EC56BULL, 0x0D86C7D6ECAE60AAULL, 0x105EF08A93EB0BC4ULL, 0x7B689AA4DD4E0736ULL, 
            0x0AE7C0F438692348ULL, 0xE29B0B0A061D15DFULL, 0xFF83A47F1DE45D58ULL, 0x3122622EED29FE87ULL, 
            0x9916FBC2E6325F46ULL, 0x04926825E1BEE315ULL, 0x89583416BE988CF9ULL, 0x0250EA8D570A9A58ULL
        },
        {
            0xF8099B8EBA05B444ULL, 0xB9EA7F03786D5728ULL, 0x9D23F29F549B18B8ULL, 0x5A32F352ACA5706AULL, 
            0x48647EC0CF8C317EULL, 0xA441E9309FB315B7ULL, 0x14AF6872D5C69B5AULL, 0xB583B0834810906FULL, 
            0xCFCF067A14C1887CULL, 0xD0FB0C665A298E0AULL, 0xA966A7D0DF997838ULL, 0x2657E37988DBB897ULL, 
            0x3FBF2C0C72ED9F50ULL, 0x39F0E6078EC2D3E6ULL, 0xAA9650A89CB91067ULL, 0x5B13B2E3FDD48BA4ULL, 
            0x4C5C6163D50AF2C3ULL, 0xD223505642012A77ULL, 0x74563BA1CEB382F0ULL, 0x6961FCECC41ED4B8ULL, 
            0xD499D2345FA7B23AULL, 0x502454268B7DAB59ULL, 0x43DC33248230DB47ULL, 0x1011D2D5B66064A1ULL, 
            0xF642D8EA05857393ULL, 0x7970840C85A5CB19ULL, 0xF1781CA8DA0D3D07ULL, 0x5FFD01E7C50360EFULL, 
            0x1324DC0441FEF54EULL, 0xEA95A23C376B339EULL, 0x7110AA951920F05CULL, 0x87520590E4697ABFULL
        },
        {
            0xD57FBEB274A3AF3EULL, 0x6B34E1B7D4C19AFEULL, 0xA0618960ECE88F42ULL, 0x2387F42D878843C3ULL, 
            0xF2947A2F92D191C3ULL, 0x028234F93DF05594ULL, 0x0EF17844CA6D545FULL, 0xE5F10E4F4ECF3A36ULL, 
            0x29BBC62D588AEA9BULL, 0x1B5630C3796048AEULL, 0x24914A1ACCE5909BULL, 0xC08E1BEB9B222ADBULL, 
            0xBFF1F7FCB5EA23E3ULL, 0x5A19137EFF06D4B4ULL, 0xE63DDB37DF9689E1ULL, 0x1B2903BA2BD1CA0AULL, 
            0xACF03D9222FCD690ULL, 0xDCD6FFB4E5F8B966ULL, 0x844BC5B646D91D92ULL, 0xE80FEAF83B05DB8AULL, 
            0xCF5BA23FD8C2F59FULL, 0x8A9D4B5B939B751CULL, 0x905C93E74B708CA5ULL, 0x5F21F1654EF3B692ULL, 
            0xAB9C3B3A53658097ULL, 0xF4FD4BFECD8469EBULL, 0x3011B62FA5C25BFAULL, 0x6F92DEBC969679EBULL, 
            0x837B1920584C89A3ULL, 0x4B2C4B3644B844FBULL, 0xA09DCC8DCB064968ULL, 0xF18BA15CF6F88BE3ULL
        },
        {
            0x21A54442382A89FAULL, 0x395D7368B5C2DD93ULL, 0x77DB78071AC8255AULL, 0x581F35F263945667ULL, 
            0x940595A540C2CAF9ULL, 0x0DDD671AB6129504ULL, 0x31DF865B46833079ULL, 0xD096F1B8D715A799ULL, 
            0x7D662EF8553B9BB0ULL, 0xA22E204F6971EBA4ULL, 0x1A0BE60E0B57D051ULL, 0xA4BC816845EC8ABEULL, 
            0xEABB71E6D45AFDEEULL, 0xEBA11468DE9287D1ULL, 0xE1A692BE4E9A9E28ULL, 0x771E8133C8BEFC51ULL, 
            0xB8D190DE59F22A28ULL, 0x3F6BD65822190C05ULL, 0xBFF686352CBAD082ULL, 0x94C95F748DF774D7ULL, 
            0x26F102043C638F06ULL, 0x9BC26FB2B075E5EAULL, 0x1EE9D64D2E9CB5EFULL, 0xB41A55AB036FF8C1ULL, 
            0x3C6C3A584AC37082ULL, 0x7E269FCA03E06A18ULL, 0x4DD54079A25FF228ULL, 0x5FBD5A045A3A82FEULL, 
            0x77583CCCCA728592ULL, 0xD4DBDA71A364AD50ULL, 0x5985479D9E35FEBDULL, 0x504EC0990876DDCDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseCConstants = {
    0x756D4B61A241EA56ULL,
    0x4409C9E41855369BULL,
    0x3ED0AD4DF2D15627ULL,
    0x756D4B61A241EA56ULL,
    0x4409C9E41855369BULL,
    0x3ED0AD4DF2D15627ULL,
    0x0BE76FA83462F9A1ULL,
    0x2A870F0CB112B689ULL,
    0x75,
    0x86,
    0xD6,
    0x0E,
    0x05,
    0x5B,
    0xAE,
    0x27
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseDSalts = {
    {
        {
            0x13B36560706E82B8ULL, 0x42903DF6B4E7D312ULL, 0xD1562FC3F61E6F95ULL, 0xCD6B79F82F526A67ULL, 
            0x6C769B5A8B4338C2ULL, 0xEDCB4863D9878336ULL, 0x3CA0771A167FA060ULL, 0x6AFB178E9753FC29ULL, 
            0xDB6322A7CA6BB87EULL, 0x3480093708AAD0CAULL, 0x6150D4E43BF57C4AULL, 0x436434BC733A6E14ULL, 
            0x0F032AAF4CDD3784ULL, 0xAE5CB95F8286F428ULL, 0xAC44F4CD6D9EBD5FULL, 0x6F8838F6D0057ABFULL, 
            0xD7F850A31DF755BAULL, 0xD48F52431537D0ACULL, 0xFE57C99AB411BF0DULL, 0x73E6B99CD5663664ULL, 
            0xEAB8914B9216E961ULL, 0xC941B16CDAACA537ULL, 0xCB388503CD0BC474ULL, 0x107F4AC8EC4A6F8DULL, 
            0x0D24E65646803607ULL, 0x42E85E66BE5F2E91ULL, 0x1B28A6EA6554A10AULL, 0xC9B888B74B26E2A0ULL, 
            0x649E45924DF2956DULL, 0xA3661FC9306C85EDULL, 0x6CF8572C3321F9FAULL, 0x14C09812AF640E8CULL
        },
        {
            0x6391B599334497B8ULL, 0x473345EEDD0D6380ULL, 0x2DDC2F54551461E2ULL, 0x09D127611A53E80BULL, 
            0x1189605FD2AAA153ULL, 0xD239A504CFF8D04FULL, 0xA832A4F6C6CE3D32ULL, 0x4E9F72AD498891BCULL, 
            0x9B5CD75D0FDA34F6ULL, 0xA3C72E2C6244D730ULL, 0x47C53E15D27CFBFFULL, 0x63705C3F21E41FECULL, 
            0x29C6C1E870A6809EULL, 0x40DAEC1E666B0AA3ULL, 0xB6553CF3B1C3D863ULL, 0xA724F1C5B76ACCDEULL, 
            0x7460D4DE91D729FCULL, 0x917660319EF797B7ULL, 0x8F4707FB28CBFD10ULL, 0xC0B3C001DE8A8122ULL, 
            0x107DE3F622E33ED1ULL, 0xD10D2955842D59D4ULL, 0x20736C74232E5D4DULL, 0x80ED30DB26DFD321ULL, 
            0x80EE9BA887ACD601ULL, 0x8EFA28BE9ACDAF3EULL, 0x48A029720A30AE5EULL, 0x761F2E5FAF2081D4ULL, 
            0xB07AED51FA4C0F7CULL, 0xAB14E26C258F640AULL, 0x03B7133767ED6BE9ULL, 0x2CA4290F1ECE0AB9ULL
        },
        {
            0x6AC933C62F2DEB7FULL, 0x807E4201CE735925ULL, 0xAD87643C8AA8A420ULL, 0x375EDAD32FC32BCBULL, 
            0xF4F980088A9FFB1FULL, 0xC24303DCC3CB9F9FULL, 0xF63558598380D221ULL, 0x5493A5D802388703ULL, 
            0x92DA5EC252E68F5EULL, 0xE8C9787F4C7B8F80ULL, 0xFA589ECF2A8A2F06ULL, 0xFEE2C9016CCE89A1ULL, 
            0x882B207235141876ULL, 0xA182599CAF9D45EBULL, 0x652554F32D909B05ULL, 0x8B792F044C4ADF1FULL, 
            0xFCE6AE6B7AC95922ULL, 0x9C8A9F386C6A063CULL, 0xCE95A4BA349CA430ULL, 0x39555D1FECDE089CULL, 
            0x6952BB77983DF6ABULL, 0x62BF72113C72F31BULL, 0x40E046A542BEC293ULL, 0x8E0BD0034C6BD8C7ULL, 
            0xCF318AA07ABFDAE0ULL, 0x3D6BFA9FF182E4F6ULL, 0xB1A7B36B0CC8EEEDULL, 0xF81612B5F67AF735ULL, 
            0x1AD9050101DA7143ULL, 0x8830A8134BB37277ULL, 0x82E0E6548687D499ULL, 0x1FF1164AF7985B83ULL
        },
        {
            0x5A3AA58270AD865BULL, 0x14ABDEAE7E3E448AULL, 0x2F4B2198C4A491B5ULL, 0x4908D42631701FB9ULL, 
            0xCBE47261DB74FE1FULL, 0x02C10ED656A0661FULL, 0xC674595992404DBDULL, 0x7380A34A7386BEB7ULL, 
            0xCF203C0C4811418CULL, 0x06D9095704CBFA25ULL, 0x8EA21FAA25A72EFEULL, 0xDDB5B7E726F8AEF3ULL, 
            0x9F7A59D23D64354BULL, 0x6F606859732F5002ULL, 0xF6C79BE861B626ACULL, 0x96EB7A28DE5B4231ULL, 
            0xCB14D160DB04D59BULL, 0xCF6A46BBAA1B792FULL, 0x6D7E0837A5DA194BULL, 0x432ACAFDE1DD9688ULL, 
            0xABF48E948FE61BC1ULL, 0x09E0E828499CAECEULL, 0xBC667A166A571063ULL, 0xD97DE05EDD3F4D75ULL, 
            0x41DA4ED8E3DCAB34ULL, 0x8FC79B4355A45E16ULL, 0xF629EC4CF7779CB5ULL, 0x0C43EFA55C33CF0DULL, 
            0xFF12C83687767CADULL, 0xC6E1D26B89AFD342ULL, 0xE9EF7EE59FB8600EULL, 0x89EBB0DF2A691174ULL
        },
        {
            0x41B7C9BF4D0DE433ULL, 0x28B5890E08AC4B9CULL, 0xDBD81F94BA6C59F5ULL, 0x4E62963E69F76CBDULL, 
            0x19E5E24BB1729B3AULL, 0x48090CA2AAB91E95ULL, 0x35C7BC7D8B584C7BULL, 0x33B57A5B13E534E1ULL, 
            0xAC383FDA39BF7A55ULL, 0xE4732C494A451A11ULL, 0x27CDEC3645BF7564ULL, 0x7F1CF942801B6374ULL, 
            0xB11E7BFB8E2403E4ULL, 0x58391E7F8CEE0DADULL, 0x308D83929C74F30FULL, 0x73048B7305205BDAULL, 
            0x6ACA31893B6D21E8ULL, 0x53493076A9870C09ULL, 0xA9CEA92B0D3D2856ULL, 0x8071F9F235C0F45DULL, 
            0xE137BAB4F298A5F4ULL, 0xA761A8F29E43A233ULL, 0xFAC1E9F445E6D19CULL, 0xC92689F05581CFCDULL, 
            0xD7CD2B5967564F23ULL, 0x5AB10B7622134130ULL, 0xDB3B78FACD5700D4ULL, 0x43F34C97D390D237ULL, 
            0xF05EDAE0F747BDCDULL, 0x059661F1EEF43D64ULL, 0x50E63386B1D0AAF0ULL, 0x83F1DB11DB925DF0ULL
        },
        {
            0x700E9392D72D278DULL, 0xC2D57DBFDAFC938BULL, 0x5873C9FA8694435EULL, 0x2FFA6F98D064D38CULL, 
            0x543308C94E42C0B9ULL, 0xA76E429D3A1EF01BULL, 0x129FFAE0CD215ECBULL, 0x2C20022F4FB3B541ULL, 
            0x7AAE6645DA18DA5BULL, 0xB7C757454A69DEC1ULL, 0x85828FA56DAC07BBULL, 0x837ABF7759875FABULL, 
            0x8CA1C210AB0B8CF6ULL, 0x2CAF77DD6A6740D2ULL, 0x951582056B152ACFULL, 0xC00040916C4C4355ULL, 
            0xBBA504056BFB3199ULL, 0x06AAB0E687FB105BULL, 0x737066DBD6A504B5ULL, 0x9ECFFBCCBC291BEDULL, 
            0xF719E443F32887CBULL, 0x4DC86A249A8D4553ULL, 0x0F8BD265DBDD7364ULL, 0xB36D1DC7E2421A4FULL, 
            0xD62E024B8CD1F88BULL, 0xDFD555BB4A27F5BEULL, 0x31F9144FDE9BDD1BULL, 0x64511368FE900C9DULL, 
            0xAB859E296A929207ULL, 0xEE2CD77036FBA3B9ULL, 0x1D9C990769F39C01ULL, 0x7C8E3E13A7B19369ULL
        }
    },
    {
        {
            0xE0F9F0854521E61CULL, 0x9AF9C136F3348C60ULL, 0x86F5CE8F6D118C82ULL, 0x912E20F28B61E61CULL, 
            0x56222894BE2808FFULL, 0x6DCCC9509ABBC0E8ULL, 0xE60B2ACCD1279AD4ULL, 0xC6737BE305B88D26ULL, 
            0x44EAA8131D28BC96ULL, 0x5BA64ACF05C49406ULL, 0x3302F9882F459D16ULL, 0xD1F0216545EFBC86ULL, 
            0xAA4D70E8C122A829ULL, 0x5111F34D68655236ULL, 0xC8C497AD1D48ACDEULL, 0x5B0D812E65BC0726ULL, 
            0x04D4314C16CC5F66ULL, 0xB27921E39C4DA13DULL, 0xCC24092BBC40C548ULL, 0x7694D19A0CAC0637ULL, 
            0x452416059F25CC62ULL, 0x0D92E7962AB50E98ULL, 0x5803AB583C4DC75AULL, 0x624D8908C9D3C77DULL, 
            0x046E8B83667D2EF7ULL, 0xF6AC1439AD61E51CULL, 0x379875647D3136D1ULL, 0xC5E007BE9041326BULL, 
            0x7CF14615C09E4D76ULL, 0x63038E85ED460503ULL, 0x793939B3ABF4B691ULL, 0x975862B48A407336ULL
        },
        {
            0x8DA90BF0D185F3F9ULL, 0x94E7E58F3A2A7B86ULL, 0xEEBE8CA100E7B47AULL, 0xD04C3E58EA7236DBULL, 
            0xC46CBF77FA9C52A7ULL, 0xA4BDDDD2365F6ADAULL, 0xAEDCE3D5A9890405ULL, 0xEC3BFC0735F5A40FULL, 
            0x4AB5F287CA94A294ULL, 0x3A000D555B646D70ULL, 0x1A199395F2748D88ULL, 0x81F7D7BBCD40AF08ULL, 
            0x63D6129F694482F7ULL, 0xCDB1B0ACD9E6F9D3ULL, 0x5BA894E06F4D9E07ULL, 0x1F699484ED93ED20ULL, 
            0xFC492C957E1623C0ULL, 0x1AE5B73C9D7B755EULL, 0xB3DD741A5678497AULL, 0x59D9384E45A84591ULL, 
            0xDD89CAC82097BF7CULL, 0x0485A9E63839E128ULL, 0x285D2EB59571A635ULL, 0x66261210B6B6CE55ULL, 
            0x9ACFEF8801BDA817ULL, 0x9554BB8D8CD439BFULL, 0xECFEA26150D8D981ULL, 0xB32F95E9CFFB26FAULL, 
            0x9B8F8E797CB6DD2DULL, 0xA475B4D65193112AULL, 0xD28D2E434A8B0C78ULL, 0xE246592C456E8717ULL
        },
        {
            0x3FA551EA82F15D6EULL, 0xAAF0E0DBBD005B8AULL, 0x074FB009A2EA57DCULL, 0x29B15E9652315D00ULL, 
            0x36B477738AAA097FULL, 0x2A3740F77E924EBCULL, 0x5AC1BAA1160F02F0ULL, 0x2DE0DF61AFCB7C77ULL, 
            0x74BA6ECD45BA1D2DULL, 0x4D497825ACEE82DCULL, 0x82D5513E8F360FC7ULL, 0x8287E2E4A38F9881ULL, 
            0x42F22B2CD365DCF3ULL, 0x946577069DBA7F1EULL, 0x94D4C0106E8AA069ULL, 0x6CD9F220E5C7705AULL, 
            0x9E9626FDB23599B3ULL, 0xCB1ABE7B10E65CE8ULL, 0x0A0CDC8A6FC5B6DCULL, 0xAB4FAFD99A079C7DULL, 
            0x8B6C8DF0BA6A8128ULL, 0xB5A0F4E6ECBB8BC3ULL, 0x976080D51CCA03C0ULL, 0x72BB48C76FDEA95AULL, 
            0x1DAB4BD9D5BA1C4AULL, 0x3DB2DF8EAD8B27C9ULL, 0x7CBD1B967C37C7F8ULL, 0x47EDCAA9F9FCCD1CULL, 
            0x9740E689EEC366FBULL, 0x91808E0C121EF15FULL, 0x2BC44397B3AB04CDULL, 0x6D4211E6CCE89BD6ULL
        },
        {
            0x3BA44D43D500829FULL, 0x1FB59C6BE2D50831ULL, 0x53CE06EEECF4C2D1ULL, 0x8246DEA691685952ULL, 
            0x90AFBA85F8EDD228ULL, 0x7FDBC81BFC2914E0ULL, 0xDFE5389D2265C815ULL, 0x54F7EDB7208BB1DCULL, 
            0x76654FC424E11374ULL, 0x2B41CB16DDBBFC7CULL, 0xB682DF8E4C21A1A1ULL, 0xF257D5789CDECA0CULL, 
            0xAE6A361851A3C9FFULL, 0x08EA463FF6CC3FD6ULL, 0x1B70B93DC7866FDDULL, 0x0D6ACDCAB525F3A4ULL, 
            0xE034AA2CBF4E0711ULL, 0xE5B7BF824CB3CD07ULL, 0x5C7DD60222435234ULL, 0xC7E3BE723A7113C4ULL, 
            0xBDDB70EB6D5C9CB4ULL, 0x9E8571EF8A298FB4ULL, 0x2A7B6D8B9F96A8E7ULL, 0xA30880DC6B70C926ULL, 
            0x23A336D55AC9A61FULL, 0x8021859BDB8F34BBULL, 0x70608DBF7D37ECD1ULL, 0xAADD360ACC12DE4EULL, 
            0xA7F34D90C952BBCFULL, 0xC6697FBA24E58431ULL, 0xB48B72C834191616ULL, 0xB6BA2DBD606102DEULL
        },
        {
            0x7681D4C19E5A8FBDULL, 0x27B81D3A48A650D2ULL, 0xF17DFC05EC92CC46ULL, 0xE67DAF85F57FCA5FULL, 
            0x5766E6DDA8B5992CULL, 0xDCF84AFEF8257416ULL, 0x7092E5F05DE89534ULL, 0x1033157896B1AFB5ULL, 
            0x56DD606F2F100F5FULL, 0x2D580D596768C089ULL, 0xDCB9578266FE79D5ULL, 0x00AAAF5968C13433ULL, 
            0x3C6619DDCC3FCE72ULL, 0x2D0E99E3E2C99F86ULL, 0xFEF312019F2F4694ULL, 0x982F56819678104AULL, 
            0x9B6F35A3FC992E2CULL, 0xDBB5109B671BC86BULL, 0x853A1063A78C7C0AULL, 0x415EB6F76A038A39ULL, 
            0xA8FBB9C627BF6E65ULL, 0xCF69CAC2874C8987ULL, 0xD76AC68022220118ULL, 0x7CCFA7CBA53B192AULL, 
            0x69502769424FCD84ULL, 0x67F18EE32D39D8DBULL, 0x6FB83C1A4140E0E8ULL, 0xB660BCDC281257A9ULL, 
            0xEC2B34DF5F28F673ULL, 0x868A7015537BE444ULL, 0x920FF3BA74852993ULL, 0x5FEE0B66C5AB38C6ULL
        },
        {
            0x17252160A4256FC0ULL, 0xEEE4F434F8076A40ULL, 0xDCAFA515ED3DD15DULL, 0x6A4833B0B985009FULL, 
            0x4936387748FD32F5ULL, 0x36370F5AB8CE8E9AULL, 0xBDEC6753ACD1A4B2ULL, 0xCB9ABE94C6B33323ULL, 
            0xB58D26678D14EB9AULL, 0x628771934FA40DB1ULL, 0x3B68132563001AABULL, 0x96A2DE458E8AB96FULL, 
            0x2DF233C849ABBDFFULL, 0x6058B719BD2C6489ULL, 0xF4DDA5DE8816B961ULL, 0x63B1C252C7B33C33ULL, 
            0xE7596AA2CE71ADE5ULL, 0x76B1A528AF8FB825ULL, 0x897C1B54991B73EEULL, 0xC0065B4D7FA908D6ULL, 
            0xE30438B1747393CBULL, 0x3E0D00A5ADFB86FDULL, 0x3CD8FB8CC54B6737ULL, 0x0229FA80A8257816ULL, 
            0x0F3500E3F0EA34B5ULL, 0xBAE00B36F506FC8FULL, 0x55E5264D3883F8CCULL, 0xACE3F6E7A02DA9E0ULL, 
            0x8724DA0FE7C33A96ULL, 0xE1E4CB383B49F350ULL, 0x8D4E633BF3D8E585ULL, 0x0A791FFB279C4FC5ULL
        }
    },
    {
        {
            0xB2FC24744F1BE5B9ULL, 0x7014FFB5DB9A0D3EULL, 0xB29A64F46735BF85ULL, 0xE44FAA100F90E34DULL, 
            0x2AD4F10AA30D9E0EULL, 0xC8E51905303F4A13ULL, 0xA2845691D185A26FULL, 0xE4B467F3C3AE5438ULL, 
            0x7754A216398BBD93ULL, 0x75BBC81F3E77F7F5ULL, 0x55AC9C4778B832A9ULL, 0x6FF56CDDA2D6007AULL, 
            0x9080D3D5211B77C2ULL, 0x432196B1701D3212ULL, 0x85B8596DA29BE3B5ULL, 0x8942EDEF592DE114ULL, 
            0x5A40618317CD7432ULL, 0x13220BE355F50B82ULL, 0x259F2709FA3CFD93ULL, 0x7B21F36772666B32ULL, 
            0x1BD1420916FCF305ULL, 0x222045A51F1A3320ULL, 0x2F8ACA370346A65BULL, 0x3385599629308619ULL, 
            0x647E19BD984C1576ULL, 0x726B52ACCC61B39CULL, 0x0CEFD79175030253ULL, 0xD0C8EF1B0416680BULL, 
            0xCE6BB4D979E43D24ULL, 0x664F0C3EB537DFFFULL, 0x166591C21F097634ULL, 0xDBFAFE4B73CA78B7ULL
        },
        {
            0xE94AF8125815F646ULL, 0x62C67578AC41A33EULL, 0xF074788B4222EC07ULL, 0x2EFA52DBA64DB5BFULL, 
            0xA48CE73101B3F8B7ULL, 0x876BE4C0F97E735DULL, 0xBB07848E824E990EULL, 0x9D6E7A767DC93081ULL, 
            0x006D1132487F804AULL, 0x2F5EEEF073FC7975ULL, 0x07176C986273F949ULL, 0x48B6077BC8CC0A17ULL, 
            0x0A56BCA38E979FA8ULL, 0x59D6C5F1648AA547ULL, 0x7BB43B3D0A71D1F5ULL, 0x97B9A9091C5CEFA4ULL, 
            0xA31F4083BF2B0D93ULL, 0x97F47A71C9C11FA1ULL, 0xCED5DE0E1579E636ULL, 0xF9F87F02D988CEECULL, 
            0xAE34970ACC04964DULL, 0xADD7863C030AE57AULL, 0xEE5AF8C900263E5EULL, 0xB3C797B3FCFA8052ULL, 
            0x75204C4944E36189ULL, 0xDC1C9997CA20CB17ULL, 0x2D76350CA135FB58ULL, 0x2F2278DED4FC282CULL, 
            0xEB5C2220EF04B338ULL, 0x8E4654A53A831119ULL, 0x80FE6CEC13850498ULL, 0xC4039A60CA556302ULL
        },
        {
            0x9442D494D9FEF838ULL, 0xBD092EC4E8D616CBULL, 0xC4B7135495D51944ULL, 0x56D856827982DDFBULL, 
            0x2C02981F27D0933FULL, 0x263194351E9D3D8EULL, 0x789D95EAA29D7294ULL, 0x1B06CAD4D2539C73ULL, 
            0xABD4EA96C97B27D5ULL, 0xA3E5F87CF0229309ULL, 0xEEDA75B341CC2BEFULL, 0xD80EDA4B406E107EULL, 
            0xD3F24C1FC0575870ULL, 0x900B1E6FB50A00FCULL, 0x087F4E670C42A679ULL, 0xABBF8DFA6D5763F7ULL, 
            0x3AB27EBFAFC0B344ULL, 0xC4BE5948981282CEULL, 0xAAF214D70F929A4BULL, 0x45CE6F1B29D9235BULL, 
            0x729E6EBE8FF8AB0FULL, 0x92D91DBAB1A2F162ULL, 0x1001E7813B4F1447ULL, 0x668A34B064D33A2FULL, 
            0x3643EF7D22D6C160ULL, 0x686D74525E6F4556ULL, 0x8773BF580600A82CULL, 0xEF283E7805D9E98EULL, 
            0x429E9C1EB07A4D08ULL, 0xEC749713D29DE5A9ULL, 0x32CCA86212A7D94EULL, 0x4CAB499BD462B98DULL
        },
        {
            0x25DB4808EC9B8AC0ULL, 0xD1DD884357591E1FULL, 0x326C8A98AA59D0A0ULL, 0xABF4F42CA22A6DD0ULL, 
            0xE23916967A6211F5ULL, 0xF261461682C0904BULL, 0xBE1E2CBA2EDFCE27ULL, 0x65ED2D0662A3B6BAULL, 
            0xCE95445F7D1B5637ULL, 0x90259400BD815076ULL, 0x70921D0EAC90301BULL, 0x0ADB09168B23157DULL, 
            0xD95A8D6AEE0432AFULL, 0x7138F08DED50A2E7ULL, 0x7E4233F2CC9BDC33ULL, 0xAED83F82A7473D32ULL, 
            0xD204BFC23CF91C36ULL, 0xCCCCFE3F6DE1A84DULL, 0x28B17DDA6309F9C2ULL, 0xD92F7C3A3D5CA191ULL, 
            0xEF1B567EE80CB3E1ULL, 0x84FBA0A3D5CADCA9ULL, 0xB262304F165FA34CULL, 0x7752A2D6D7FFEC55ULL, 
            0xED7D51188F06FC51ULL, 0xEA8CDB825E5D6769ULL, 0x5AD1CD694A3D588FULL, 0x52EF68D9DAC0E9AAULL, 
            0x23F217032853A4D6ULL, 0x1C79CE31D06C98AAULL, 0x25DF17E99F7F6B90ULL, 0x49488B0E4829DDFEULL
        },
        {
            0xCBB3CD98E7E603C9ULL, 0x3642A8DA3A684CFAULL, 0x3544A3B65D624C4FULL, 0xE7280DAE5BFAA7DEULL, 
            0x979C24FE247F7F64ULL, 0x73B3B1B1EDA6F8C5ULL, 0xDA2A4415C5883A11ULL, 0xEC05E39168C518CFULL, 
            0x0E153A8EA91D374DULL, 0xD775DA1F271725BEULL, 0x36DB4550DEC0FFB0ULL, 0x9A8FEEB290D60B48ULL, 
            0x27F2707C1E16F897ULL, 0x90A86C3AA948E482ULL, 0x20C940FB6FE65827ULL, 0x04271AE39A6BBEC5ULL, 
            0xA2A208541B1B0A3FULL, 0x2C4E9D0049464D2CULL, 0x6EC043ECDF97EBC5ULL, 0x289395AC40CEDF13ULL, 
            0xF04A038C45EB0700ULL, 0xFD43CC35C4D663EFULL, 0xED19B07856ADBF87ULL, 0xAC2A5B7BB498CFB5ULL, 
            0x18D74323081990E7ULL, 0xD606AC249676BC9BULL, 0x9052A7E56BC24D5FULL, 0x62409B8C4F5C04BEULL, 
            0xDCE3017D1A8801F0ULL, 0x8F07F07BFEBCCC1AULL, 0xF6A6C1C6B64E1EC0ULL, 0x2E6CFE2F4B7BA791ULL
        },
        {
            0x3C4877732B15798EULL, 0xD124DF5CBCF92D83ULL, 0x0508E2EBEC093820ULL, 0xC0495C92D122E429ULL, 
            0xC66E36B479E9D730ULL, 0x621F3C6BE1603928ULL, 0xEF0B8BB0E31390FCULL, 0x348B847E1966D3ADULL, 
            0x2F1E07483B62945CULL, 0xDE07051FFD4EA819ULL, 0xF9F22D084D2B220BULL, 0xBA7692A9B28D7E95ULL, 
            0xFE35AADBD5F984E5ULL, 0xCA4D870B36059F8BULL, 0xF4E034F2F3B6A702ULL, 0xBF6AE1811B2B66F8ULL, 
            0xDC7B8BEF41A46AC2ULL, 0x7DD7B58ACB705681ULL, 0xDB630E01F0CC7B74ULL, 0xBCBACB54D1F4E384ULL, 
            0xB5AF9789E600BC8DULL, 0x08A615F030EC2162ULL, 0xC50D0049B196D90DULL, 0xA72B2ACDAAFC80AEULL, 
            0xEA18FA140F22842AULL, 0xC76EECD139E3A309ULL, 0x37AB935BADAFA7A5ULL, 0xB4DB6C1CB3ECA700ULL, 
            0x95C8DAA994FB40DAULL, 0xC0FDA454A827E2A5ULL, 0xA06B659D7DDC5E3AULL, 0xE7FC0B5AF4901497ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseDConstants = {
    0x8B8BCBAD6A4C0D4EULL,
    0x386E2617F7E787D1ULL,
    0x23394D94F5FF3101ULL,
    0x8B8BCBAD6A4C0D4EULL,
    0x386E2617F7E787D1ULL,
    0x23394D94F5FF3101ULL,
    0x391798ABB1A74CD3ULL,
    0xEF4D75DAE993C299ULL,
    0x2B,
    0x0B,
    0x8F,
    0x57,
    0x8D,
    0xCA,
    0xDB,
    0xDC
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseESalts = {
    {
        {
            0x93A12B95E72E3BC9ULL, 0xFD867A256B2ADF0EULL, 0x76D8F4AE2FCF5B26ULL, 0x4E8AE8E9CED75BABULL, 
            0x0B33554BF4D445F0ULL, 0xEBF7D3F44CE79927ULL, 0x4C9D03133EAF38FBULL, 0x52E003FA07D49243ULL, 
            0x4848BF7485FBDB4DULL, 0xCE0A8F310F661A9EULL, 0x9EB2AD4FC82F70CEULL, 0xE3D6D70CF21FE77DULL, 
            0xE1DCE3B219E2FDFBULL, 0x372F2EDF076E79A5ULL, 0x07E652E5625C2C98ULL, 0x565C5DE372ADC0C3ULL, 
            0x542BA778AD3881BEULL, 0xFD11E2EC98F8F34AULL, 0x38A302CA434B3A58ULL, 0x0789603FA57268A1ULL, 
            0x01B5F43A8647EA8FULL, 0x47BD398D80B64722ULL, 0xE1C329C7B90FAEB8ULL, 0x26E5ADC5D41026F9ULL, 
            0x3F3C1C8D8C06FF5DULL, 0x7F00214407833080ULL, 0x48FCC656EF1C7E06ULL, 0x02F36216AFE5F1C5ULL, 
            0x10D5E776B2F048BDULL, 0x123D7DD7425A6613ULL, 0x0F3F7A37A2EDB3E2ULL, 0x6AC5103C582152C2ULL
        },
        {
            0x3D71DD74DE93B267ULL, 0x5F1FF181F2B0C286ULL, 0x60E75E6344ED8A85ULL, 0xC700D340299A5821ULL, 
            0xAAB2A4D74343CBB6ULL, 0x9A9E53E9BFC5A9CBULL, 0x18ADAD6D0411290CULL, 0x05EEDDB75E1C1802ULL, 
            0x1D36FA9C767E3A6AULL, 0xC9FC0AA217C54060ULL, 0xE58697CA9E7F644BULL, 0xC869E7EC850FE643ULL, 
            0x084CD48CBE59877CULL, 0x17A8ADBC2B86F94BULL, 0xB9D8266875546D7BULL, 0x921FD44F3B63AF46ULL, 
            0x84878966BBE8148EULL, 0xE9D259DC10F68E14ULL, 0x9B64B916A49A95BCULL, 0xAD63EBF65F7A36DEULL, 
            0x367449368542AC94ULL, 0xF92EC9F576057C0BULL, 0x026073768542E617ULL, 0x8737E7C4AFB064A9ULL, 
            0x72AF2F89FEC7F78FULL, 0xB23EC64D8E47350CULL, 0x072081472F302952ULL, 0x0AA9080D6068A471ULL, 
            0x6CCE026C67D8A73FULL, 0x62CD017A36BAE3FBULL, 0xCE19BE41F88EDE3AULL, 0x244F2C430FD0354DULL
        },
        {
            0xEEEFF11B127320DEULL, 0x0ACA87DB16AAA7F9ULL, 0xE7A8BB286EAFC01DULL, 0x260E3BD044E942F2ULL, 
            0x341044899B288473ULL, 0xC82981F03CE78CCFULL, 0x7AA02880126A2C49ULL, 0x38979F6C4C85E1BCULL, 
            0xAD6DF96F37993126ULL, 0xEE3F0D34D49D07B3ULL, 0xAA929CDFBAD8B644ULL, 0x3A3DEA7AB309E77CULL, 
            0x7DE5C32731E0FE8DULL, 0xED0D71175F05C367ULL, 0x96F2EB942A990639ULL, 0x2CF7C1AC6DDAD8F6ULL, 
            0xEAF559A4101BD937ULL, 0xFABE5907AACF9490ULL, 0x8B9F881C199B17E7ULL, 0x5F24CBADDC285E86ULL, 
            0x4AF3D1D6B2901D59ULL, 0x10180D40C2785035ULL, 0x4CE070C89DD04021ULL, 0x5AEEBCBF371D2F4BULL, 
            0x2ECD22327A5D5C4CULL, 0xB19BD6BF4E14509AULL, 0x381DF1F96EC74D4AULL, 0x91C3EDBDF39D720CULL, 
            0xEF8965CBCB724E96ULL, 0x71E865E67E6DCD4BULL, 0xDA8378A98F69D161ULL, 0x25FEF86E0EB873BEULL
        },
        {
            0x3A4F5D8BA83DE2D4ULL, 0x1621347ED38828A5ULL, 0xD63164931AF3AE74ULL, 0x1DFBA6055CEAA528ULL, 
            0x10F541146BA38DB7ULL, 0xA0A8AE986D10A200ULL, 0xAC87056DDB7E905FULL, 0x4F38706CF74925A6ULL, 
            0x6F35E0DD23DEB278ULL, 0xD4A19264E59AE821ULL, 0x863E54B506ED4388ULL, 0x4A5EF8AEA616692FULL, 
            0xB93C8F855F10575CULL, 0xFDC3148390043D33ULL, 0x5661494AB7106E12ULL, 0x0D77D5DBF9196C39ULL, 
            0x2478514B2136672FULL, 0x2A6E69DF9AA1004AULL, 0xAC26A26EAE8B2AE2ULL, 0x4493AF1A74BA130BULL, 
            0x4BEAF4D3F407BE68ULL, 0x0536B5B96B689708ULL, 0x2A3E026B687C745EULL, 0xBAB46094DE6A4496ULL, 
            0xC1325953227B5136ULL, 0x28C09A6F23E3071AULL, 0xB7B8E1D6B90A1711ULL, 0x5D903387001C241BULL, 
            0x104355ACCB1E244DULL, 0x927C2A0B2CEFEC9AULL, 0x2449ED3C8378061FULL, 0x68FF1014968D9D3AULL
        },
        {
            0x75975311F2AC3D65ULL, 0x930F1BC8FEFCA9E6ULL, 0xB66AE238C7307C93ULL, 0xCE5E28F90274D613ULL, 
            0x7A224EB0767BBB8CULL, 0x5008BF70FD61D6ABULL, 0x4F63ED951EA79349ULL, 0x97C929A655EA7F9EULL, 
            0x8400DEC453E0D55CULL, 0x67B9BF8C512DB11BULL, 0x9626D0AEBF0C9E7AULL, 0x4B8495BD5103014EULL, 
            0x1197C32B8949F766ULL, 0x05E76E6C55278E12ULL, 0x2EC0499C69EE44B3ULL, 0x28D3C8F8E3840E6AULL, 
            0xEE1200987873D910ULL, 0x743F0864093EF082ULL, 0xEBEE0957B127A6EFULL, 0x145D72E454AC4B83ULL, 
            0x5B2E990C4B1CA50BULL, 0xF0F0F781F52E963CULL, 0x2AEE5A74FC73ABDCULL, 0x7DBB25CE9291D4BEULL, 
            0x1E6AE1F283C16ACCULL, 0x0DEA98B4EFD58609ULL, 0x6813972432672F4AULL, 0x6C18B7559CC3FD1FULL, 
            0x0917F735A3811C30ULL, 0xE921C3ADE5310CA1ULL, 0x01E5F74F59D90F90ULL, 0xD3AE8846F2B3C556ULL
        },
        {
            0xD602C914C5CD8080ULL, 0xE56C061B5B2E94BBULL, 0xBB386972516C4E97ULL, 0x559D5BF4F32B857FULL, 
            0xF25CD474A4FAAA65ULL, 0xF8D6F8334C7EB45FULL, 0xAF322C03097FD903ULL, 0xA645EBD0AEB88DCAULL, 
            0x7818E814EE6FE1BAULL, 0x8F02D48438A53C6CULL, 0xD9D29EBFBBEFB6ABULL, 0x8AE451494BF81A91ULL, 
            0x8048296369593291ULL, 0x1D1B9F3832F3B542ULL, 0x6D12AA5B4EFC1D6AULL, 0x0EEF0BA41BC5F233ULL, 
            0x8C9DA3BCA9449B79ULL, 0x93B1DEF1C3FD9EDDULL, 0x01F755364C889834ULL, 0xD6ADFB84CD7CFC36ULL, 
            0x673608F84D3ED8B7ULL, 0x981786AB6ED16DFCULL, 0x439283ACA974BBCAULL, 0xA849E1E3A42C5CD9ULL, 
            0xEFCCFABECB5191F9ULL, 0xEBFD8FC32DCFFB44ULL, 0x6F8C6DD349077588ULL, 0xDBDB7ABAB1DBEB16ULL, 
            0xD5470A8393298142ULL, 0x812B0D14D3761C0CULL, 0xE3264387E815CDF8ULL, 0x9A34CD11044D785AULL
        }
    },
    {
        {
            0xE1BA3851D4F846B0ULL, 0x4B875861ED8E44C7ULL, 0xA4316DF68E0ED132ULL, 0x2D71E1A140F405E0ULL, 
            0xDBBDE393BCBC1827ULL, 0x52FECC4D5EC61547ULL, 0x814CAE4EFF93A70EULL, 0xFC3099A4D4080255ULL, 
            0x41E51586002B2FCDULL, 0xFDCA5ECF24599FB8ULL, 0x3700D790A0D83B90ULL, 0x09742ADAEB4D0E53ULL, 
            0xD96DC21A69D74738ULL, 0xE5B879BCF9E99A4EULL, 0x624DF30A4807B66DULL, 0xF8AACAF9538C49D4ULL, 
            0x48B7B9ED26F78808ULL, 0xF256B31EF38E349FULL, 0x890C94F81B08E486ULL, 0x71CD4A5D65970516ULL, 
            0xC555B44A1E00CD42ULL, 0x22E0F8C1F9551B14ULL, 0x41304BBC9C95404FULL, 0x912FDA472C72EC27ULL, 
            0xB2E483AC54782617ULL, 0xCF27B7E4E2A22522ULL, 0x1D3150627CF6F0E8ULL, 0x0B8CE1AE6FFF3000ULL, 
            0x2983CA90FACB479CULL, 0xAD21D1A8892B5DC7ULL, 0xB9D61E63F2358A3BULL, 0xA4746EE148C4B90EULL
        },
        {
            0x70AC546699E52360ULL, 0xDB1F454CF93C958AULL, 0xCE67FA6535530F7CULL, 0x6FE63D12AA06836CULL, 
            0xDDDA11A760B99EE1ULL, 0x633FE31B2C93A99FULL, 0x763DE16D3A310451ULL, 0x8BA4E8AFFBAC079DULL, 
            0x0880A2FA40515FB4ULL, 0x4ABD7F30525F010BULL, 0x82F446C4D9FAD928ULL, 0x8CA63C30988E9385ULL, 
            0x31647D83B2028BA6ULL, 0xBAA069E22A48D4C1ULL, 0xA341DFD15A415FF0ULL, 0xA307E636222F5942ULL, 
            0xEAA9DE7B1B71FA0AULL, 0xFC2AA9BF1B5FCD52ULL, 0x666F9F44362343EDULL, 0xFACF0859F64C926EULL, 
            0xB903563C6BD7D8CBULL, 0x28DC519A5CACE038ULL, 0x52A7F842838911D2ULL, 0x833F443CC9185844ULL, 
            0xF19F3123F45C4CB4ULL, 0x53187FC001E92CF2ULL, 0xC3DEA79F59234319ULL, 0xB4584E82403D35DDULL, 
            0xB45B6E1272EBB0B7ULL, 0xEDD15873C17F2804ULL, 0xD34271C54B29361DULL, 0x2599AD12A65E85E8ULL
        },
        {
            0xEB35CEA062CC7A8FULL, 0x3FACB720766D1490ULL, 0xCDC4002757BBBCEDULL, 0xF3F792F81340DD23ULL, 
            0x122D6546B893C32EULL, 0xF2D1F4FE0CCD2279ULL, 0x739AF8D498C15630ULL, 0xF9604B1DB3F96950ULL, 
            0x2EF8AB47394B2014ULL, 0x638DEB61953517F2ULL, 0x207C2C7E6427D50DULL, 0x6B0F06D0C71050B9ULL, 
            0x7555F9D01C043BBBULL, 0x2B9F1BAF902580CEULL, 0x54D1342C80C07B98ULL, 0xB13CDF3765D9C03DULL, 
            0x0ADE7F312C7FF705ULL, 0x30E00EA422CBB492ULL, 0x999B21F1AD590E7DULL, 0x1D99469D0BB9CBA6ULL, 
            0x2138DB10A40847D6ULL, 0xEEBE82CB6F1840FEULL, 0x4BB9FB4DB9DAFEF8ULL, 0xEA691C8DF090FA0DULL, 
            0x5D3C066A240A5A7CULL, 0xBB974707D94B6548ULL, 0xD8299366E53F3E61ULL, 0x15EA3039646C95BFULL, 
            0xBBFECF99A6E8750EULL, 0x396FDD701E9F51CAULL, 0x9369823A239E73AEULL, 0x33A19E356E0AB262ULL
        },
        {
            0x8570076375B6B5C9ULL, 0xA364D5746E204BB0ULL, 0xB53212AA6A3AD24FULL, 0x0455066635F864DCULL, 
            0x2D4D0F9A695CC28EULL, 0x8990410F353ECC86ULL, 0xDDE6C8E5B74B844CULL, 0x7AFFC05F84514A44ULL, 
            0x385886EABC5B4835ULL, 0x3FC53FC3ABDB649FULL, 0x700CF89A393950DFULL, 0xC5DF1DCF645EFE0FULL, 
            0x5DF345F71A3122ADULL, 0xC4ECF2E08AA7B8A4ULL, 0x8B0BD8815154C86EULL, 0x7AE2160EE5323289ULL, 
            0xD30A39A9C286460BULL, 0x35BE3E77BB030D58ULL, 0xDD97451732808B42ULL, 0x10BB73877BB9C367ULL, 
            0xC27168D6FCF69B7EULL, 0x4E33933A1C6E9892ULL, 0x989FF516F7E6922FULL, 0x0C95E570F3BB7F32ULL, 
            0xB2ACEA4546CD7946ULL, 0xD5C4E0091290242EULL, 0x8308A1C43801D109ULL, 0x3B42E2CAD76CA5BFULL, 
            0xF2441BF5B274431AULL, 0x873F1EC279F7D560ULL, 0xDCE95AD4F9025579ULL, 0x5F66F2FD751B45AFULL
        },
        {
            0xF62C30998AF639DEULL, 0xAAFF271F286576FCULL, 0x0CB45FACF248EE22ULL, 0x64DEED3C86C834EAULL, 
            0xF6C6390E63B6C8C7ULL, 0xAA3C1835CEA593B3ULL, 0x000B1113130FAC0EULL, 0x3F68EC47CA686386ULL, 
            0xE81CD2EE4D12919CULL, 0xAF02CFAA1D57035EULL, 0x68A576DA91C7CD78ULL, 0xA8DCF30C35FC9507ULL, 
            0xBE6E2CE55E163B8CULL, 0x3A8084CAF0A55487ULL, 0xDD8ED1140B82E701ULL, 0x40C7EA4E97892B0AULL, 
            0xE33B04BDE088C937ULL, 0x9DFCCD6DE3ADA8D3ULL, 0x0DE11083267F0B78ULL, 0xCDB47E195C4746DDULL, 
            0xE969492BE4B06A3CULL, 0xDBDE01CAC78B0794ULL, 0x698BDEE6EB8E5EC5ULL, 0x1378B419369F7C57ULL, 
            0x224B847796AE5D0DULL, 0x5B4845B7F0EA1E64ULL, 0x46322F842DB0C4B7ULL, 0xEB7C14A6CA869ECCULL, 
            0xDB35EED748CABC22ULL, 0x0E173BB3D3BF0467ULL, 0x7B63DE5B474CA4BFULL, 0x386D2BC9AAEFBED8ULL
        },
        {
            0x746171A4DAA9B429ULL, 0xBFB5357EC9B149E9ULL, 0xDD2A4A9007DDF768ULL, 0x3773669FB7D97F46ULL, 
            0x550C207B1BD04CAAULL, 0xC71A2FD81FC2F19AULL, 0xC2C531EC8AE9D13EULL, 0x0F0C58F33B7B9688ULL, 
            0xD1ED2920BC3396B9ULL, 0xC19877C0910E087CULL, 0x283964D905921F01ULL, 0x9196B11450F7FFCCULL, 
            0xDEF64BDDFD790709ULL, 0x7B39121B38996A4BULL, 0xFF672820FBE33A8DULL, 0xDEFA2A5BC609BCC9ULL, 
            0xF93CBA21ED19063BULL, 0xF1E45F9F621EBD8CULL, 0x81CAD326B8AEC08FULL, 0x719AB995B2FB2790ULL, 
            0x666374D4A2155371ULL, 0xB42A465136E79ECEULL, 0xD9CF110DAD6B09E0ULL, 0xE31DD78CFCA6F58CULL, 
            0x1E00CEAC81ADAEE7ULL, 0x4490B37A875EBF6CULL, 0xBF0A83A7B8B50F50ULL, 0x0243A33A35477400ULL, 
            0xD4D10969FB134CF0ULL, 0xBA9AD362BEABB4EEULL, 0x25350FDEA0518FD7ULL, 0x2BCE6D83B87D1CB5ULL
        }
    },
    {
        {
            0x56E4D96D12DE7AB4ULL, 0x297FD43CA1635917ULL, 0x6376ECB7CDF49F01ULL, 0x9191C9319A08B8AAULL, 
            0xE13FCBBC002E95F1ULL, 0x8F0503E10015DA1DULL, 0x6B7699B2BCE05D9EULL, 0x1CE0BE1E522155C6ULL, 
            0xA8E0FB2F0914E407ULL, 0x3E14DFE1583138ECULL, 0xFA1B3E4484EF4935ULL, 0x5BFFFCC8977992DAULL, 
            0x796958438319996DULL, 0xDD848477784530B3ULL, 0x1901825D96C8C97AULL, 0x60DFBD5AE283BE8DULL, 
            0x5401CA5ED6583483ULL, 0x24CE297590D0447EULL, 0xBE8EF57CA0D3CF5BULL, 0x72D27231D7BC8AF6ULL, 
            0x9B732E6E5F212422ULL, 0x7ED817919977AB00ULL, 0xB175EB25B3EFE511ULL, 0x0340C6E8486D641CULL, 
            0x3CF7EC35FDB6E6CFULL, 0x6640D535B438D902ULL, 0x0BB745F4CAE34D27ULL, 0x8CB4B0F42C38ED4AULL, 
            0xF2AA7E7EE2CCB6E5ULL, 0x49C064E08477ADCEULL, 0x20D280146126B2CDULL, 0xBDB7E9BC1DFBD10BULL
        },
        {
            0x7B6DA798D61D534AULL, 0x40B6D17C5FB99CE4ULL, 0xC90B89265498F74CULL, 0x971B70DA03F41CE1ULL, 
            0xEEFB801A1AEFC745ULL, 0xCFC6C5255766CAEEULL, 0x49148EF1F1FB5E62ULL, 0x22824B56C6E7ACDEULL, 
            0x7491C94F398A1CC8ULL, 0x5D9AA4180CC8D7FFULL, 0xA48AB5A228D69966ULL, 0xF1E052C2F089722AULL, 
            0x1AF77E88B1C00EA7ULL, 0xD157A9375869A7BCULL, 0x7836F24E54612707ULL, 0xC0858E6DAEFE8DB0ULL, 
            0x7B458F65C0D03D15ULL, 0x7EF67ED5AD0DF553ULL, 0x6AA0789B2187BBC5ULL, 0x348207B6DD854634ULL, 
            0x865F9B00BE193564ULL, 0xE5D1B5671B2C9FADULL, 0x32BB5BE9CA2B070AULL, 0xFC1628E9C19C6C4DULL, 
            0x0E5FF8E050CD9235ULL, 0x41497E9AEA37C72DULL, 0xDB93210147AC0ADFULL, 0xDABC90F835FD9E4AULL, 
            0xF431AE828F09AEB4ULL, 0xA7B4F2D6E1CAC78AULL, 0x99BDD7ED5050F4B0ULL, 0xE3786F74D2D6D621ULL
        },
        {
            0xC82279B6B0CB00D2ULL, 0xD376ECBF9319B36CULL, 0x42AD5925A219EB3BULL, 0xB6BB6B60FB879954ULL, 
            0x1489DE63F5991B9CULL, 0x57A97A8CCC8EFDF4ULL, 0xDC7AC989B8601027ULL, 0x88AAC1EBD9313A40ULL, 
            0x2939FE227656C68FULL, 0xBDC3E52E854897EBULL, 0x295530C2B9D6B4D4ULL, 0x34B62031CE097C15ULL, 
            0xFE3F9422E799B8FDULL, 0xFDFFCBEA446103CCULL, 0x66DC1B6E31193D67ULL, 0x15BEA5DC0FAE1485ULL, 
            0x7EA3D4E10420ECD8ULL, 0x30A00848A18D0AF6ULL, 0x6ECD8EA4E3246763ULL, 0x5F7B9921CB9DCF7CULL, 
            0x8B615D5DE7D2E4DDULL, 0xCADB8913CFE82616ULL, 0x7DF73A48E947EABCULL, 0x819763317E29F97EULL, 
            0xBE2DCDC8D83B946BULL, 0xBB2A99B6F24D550DULL, 0x8DC5F9590402C47AULL, 0x1BDB6EBF94F62AA4ULL, 
            0x91D90449E3B36769ULL, 0xDC502DBD8A324E14ULL, 0x27CB2EB15312A50DULL, 0xB2A59E77419855D3ULL
        },
        {
            0x7D5F8FA91A14D213ULL, 0x755EE8886ACBCEB7ULL, 0x9C28D4C575683BC7ULL, 0x369ADAB2300D61FDULL, 
            0xDE8E744251A939FEULL, 0x167A8930D2C2F277ULL, 0x3EC8D45D1E16A96CULL, 0x3A4825449C34F14AULL, 
            0xA333FA2A2D761C72ULL, 0x9BB7AB3D621B8E25ULL, 0x99C89A8CE8000704ULL, 0x8F5656286E2B5416ULL, 
            0x8133D4892907886CULL, 0x4D409B101B3EB854ULL, 0xC6DED677154E7D04ULL, 0x43E145064D649E91ULL, 
            0x6E056DCDAA4CB92DULL, 0x6BE111ABC96606B8ULL, 0x54BE12DBFDC6E6D2ULL, 0xE111C3963E121871ULL, 
            0xF5A91AAA2A42C9EBULL, 0x78031FFFF29CE193ULL, 0x6C0BCCEDC319D2E7ULL, 0x63B227F2834100F9ULL, 
            0x0A678428E7D63778ULL, 0x4D6466E617D33E7EULL, 0x9E063839C20A29F0ULL, 0x2CF39DDC9368D069ULL, 
            0xAAD1ED6BCE162B7DULL, 0xE8A5EAC8E0A66E7AULL, 0x7802767973A9A93AULL, 0xC0DE1C3422D289D6ULL
        },
        {
            0x7FBEFB25C4163DC5ULL, 0xA9C169FE9E176A82ULL, 0xD6A71F9E96D951B5ULL, 0x61549DDAE16ED46FULL, 
            0x86E806A9808841DDULL, 0xFE9F0F5C82D2BA53ULL, 0x456F0EC31D60D5BCULL, 0xAEAC127E310701F4ULL, 
            0x6BD3021B05CB3F33ULL, 0x989A07B792F6D108ULL, 0x12856BCC591AFA8BULL, 0xBA9E82D1AB385087ULL, 
            0xB586239097E5B6A6ULL, 0x87B3120888BFD853ULL, 0xADE94FADFB9AFB5AULL, 0x29E8AB0D93A86AAFULL, 
            0xB215C3EEEA4A6A3EULL, 0xC08F4F4C12876476ULL, 0x0E1FC43D574BE810ULL, 0x9F2D2BA05FC34CCCULL, 
            0xDCB714635B80CDB3ULL, 0xC19DA77AA3343A6AULL, 0xFA54B9D299FD36EDULL, 0xAA7B0250EA48A6FAULL, 
            0x0CDBBF348F316B63ULL, 0xDBD5AD62FC6EDBE5ULL, 0x2D0312D36BA539FDULL, 0x518BDB7341F2AD0FULL, 
            0xC124D82EC7361DA4ULL, 0x75C73325998E1E4BULL, 0x044EC711A18F3606ULL, 0x85E6AD3153BBC8DFULL
        },
        {
            0xD152D398FC08C90FULL, 0x7F89639C374C03A8ULL, 0xC99AC84B902DE88FULL, 0x40EEA4756CF3148FULL, 
            0xEF03CB04D5573C5AULL, 0x391E2CF13A86B322ULL, 0xFCCA20705838968AULL, 0x410FB4371FD08FA6ULL, 
            0x0B2FAB41F6051D2AULL, 0x51F214CAE9052ECFULL, 0x9358E8AEC09FC946ULL, 0x1DFD826BD1591E14ULL, 
            0xA469427EC90CBBC5ULL, 0x3A0431FF8EF86546ULL, 0x3E061F5F9BFFDFE8ULL, 0x211F7EF47A9B2EAAULL, 
            0x70944E37F073B237ULL, 0x91AFE709F287742DULL, 0x391B9E4EBB7C38FDULL, 0x2E71EC92E5F726FDULL, 
            0xDEC5F6194B7FBFD9ULL, 0xB4DAFB21B7B4EA65ULL, 0xFE15F16858E79E5EULL, 0xDA085421DBCD6A96ULL, 
            0x1D3814014DCB5E1DULL, 0xDB015A66015126A2ULL, 0xABA59B7F159A2960ULL, 0x15A7E8060517F661ULL, 
            0xB62121729C9AACAEULL, 0x07796CEAEA674B3DULL, 0x18D9D1FC86E8E8A4ULL, 0x4D778F96C1C96E8EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseEConstants = {
    0xCDFD2936433EBE83ULL,
    0x4F2B6DB54CF72C08ULL,
    0xF03D0919200E8C08ULL,
    0xCDFD2936433EBE83ULL,
    0x4F2B6DB54CF72C08ULL,
    0xF03D0919200E8C08ULL,
    0x76E862868789D023ULL,
    0x788A56F1F4F64CADULL,
    0x58,
    0xBB,
    0x85,
    0x80,
    0x0E,
    0xD6,
    0xF0,
    0xFC
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseFSalts = {
    {
        {
            0x7AC8257B349C17D8ULL, 0x43B9A5CFA33B3729ULL, 0xC2495E8F80705A1AULL, 0x4766590598BE8F63ULL, 
            0x3B0A9D6C354386F9ULL, 0x8FF194C342DF10A4ULL, 0x20E1F4353194A845ULL, 0x8D3AE481CE54E649ULL, 
            0x116FE6A1C8BB0EBCULL, 0x8B7645CBE967B2DDULL, 0x9D41594E0795F795ULL, 0xE0BD42CB44F9C3A0ULL, 
            0x7C0C32027759A95FULL, 0x51AD00ACA8D7887AULL, 0xBF40BE10373694C1ULL, 0x6A0E98EF8580C313ULL, 
            0xD49949CD8E893EA3ULL, 0xB0CBB2BA8B8E5D33ULL, 0x0DDB089B90B31578ULL, 0xB23E7607A6C771F5ULL, 
            0x8CCF75D89A92B9CCULL, 0x008474711FD6006BULL, 0x3FB770F381847BA1ULL, 0xF6C3DA4B7E7E116CULL, 
            0x74ADB9B3DD284C1BULL, 0xF83FE74F4741992EULL, 0x358D1AE7F8EA690FULL, 0x585645D723A864FAULL, 
            0x236C3FCC404825B0ULL, 0xBF326EEFCA8C3BCEULL, 0x6539501B5A4D60D5ULL, 0x7AF336DDDA6EE19AULL
        },
        {
            0x07133FAA4180345DULL, 0xE4223A66336170A1ULL, 0x0A88A4C173DCA06CULL, 0x0D036AA98C742383ULL, 
            0x9C898F7FB75E321EULL, 0x1FE82B8E753C2185ULL, 0x7B64AD8BD6680ACCULL, 0x324D57FEB88AA1F1ULL, 
            0xE587525D6EBEF36EULL, 0xBC3968C57D92F00AULL, 0x382FF076EE780908ULL, 0xB51CB6CFF70E2D63ULL, 
            0xA1F0445D2331F610ULL, 0x0EB16C9D5E0E595EULL, 0x388D5F4934268CEBULL, 0x30C17AED0C3FC11DULL, 
            0x271BDEF0B920E0A3ULL, 0xE58986BAE2BB5065ULL, 0xADF808FFCECBB266ULL, 0xC7CA14D4E5F403B0ULL, 
            0x7B4D2126EEA2A943ULL, 0x759CF0C55E7F28FBULL, 0x26CE1D58C39D710DULL, 0x026E0A6734782CADULL, 
            0xCD7C936FA69DBD50ULL, 0x780D1F118ED30219ULL, 0x84DB2FE282395D4EULL, 0xD7A11B083925BE5CULL, 
            0x3068DF08DC24E8F5ULL, 0xA1DF41B8968B31E0ULL, 0x165A9E93A506C0FBULL, 0x8EE06D67D3AB215EULL
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
            0x2CC6D1C28FC1710AULL, 0x833454507971554AULL, 0x76056E874AC57246ULL, 0xEDCD62789E206372ULL, 
            0x4F7AEA59B7A685EAULL, 0x8A6961944A5409D4ULL, 0x7DEB7E6EB3D28688ULL, 0xA2BF76BEB5474217ULL, 
            0xB8B158F542E4149AULL, 0xF0D386EB550FCB2FULL, 0x24DCC77872A0AB42ULL, 0x4C307AC037713CA5ULL, 
            0x91BE095839D8F21EULL, 0xF3898BCF84781B44ULL, 0xDB59D62B2FFD2EB0ULL, 0x3E8508A078924B34ULL, 
            0xA1B727A10C1514E9ULL, 0x1A6070573D331265ULL, 0x9A6F5FACEBAE581AULL, 0x77D9E9529FC9373DULL, 
            0x3B2E593000885C84ULL, 0x8E07AA85814929D7ULL, 0x08AC53A0307543D9ULL, 0x0F7E983BDF9AFBD3ULL, 
            0xB119E5B18385EE24ULL, 0x709905E193E9E268ULL, 0x2B234118F3A98397ULL, 0xCBE755E5B2A89912ULL, 
            0x325F43B07D775D42ULL, 0x202009C2788A1B54ULL, 0xD8015FA8411635BCULL, 0x1F0E22ADFD5008CDULL
        },
        {
            0xA0B85F569B3729AEULL, 0x91D5A6DA887D6F97ULL, 0xE5CC52F33E25D49DULL, 0x9952872358AED193ULL, 
            0x2F099FE58ED09240ULL, 0xE5027B67FC01B76AULL, 0x4FC581A28DEBE908ULL, 0xADBB5C65EFF095B0ULL, 
            0x2858B2B11B602425ULL, 0x07FAC7624B5BC5EAULL, 0x671FE446A6CFB1E4ULL, 0xF0089F78E75463B8ULL, 
            0xDE9125D3B8B37AF1ULL, 0x76B35E58A98BDF07ULL, 0xD96CB673175FA32CULL, 0x30054FAE62F7970DULL, 
            0x6796B6D8CEFE2DB0ULL, 0x93CEBBC61A94D650ULL, 0x9F2C7D17F5971BBCULL, 0x4007DAA0A268AD6AULL, 
            0xF230DE2C461A183DULL, 0xF424AA8DC62AE952ULL, 0x189DC99B82410770ULL, 0x6B75009452D7FEA4ULL, 
            0x89D9013A2C66B816ULL, 0xA9C58F1253743370ULL, 0xCBCC88EAA30822ABULL, 0xAA2E5B2A6235D9D7ULL, 
            0x2B0DB90EB2C8EF12ULL, 0x8CB87002AB8CA635ULL, 0x2F81C0EE386664EFULL, 0xFA2A06C3D36005BBULL
        },
        {
            0xFBBFAD6F344265ADULL, 0x83E623B3DB5F2C7CULL, 0x21A1CAF57DC3A45EULL, 0x5D0108EF512B36F8ULL, 
            0x3C9E0B51CA7CCACBULL, 0x84C40E875AA4C58DULL, 0xD476427CC04D1BD0ULL, 0xAC81FD8EC199939DULL, 
            0x07326507516486F2ULL, 0xEE6BB201CA50ACC6ULL, 0x4EE18FC142275093ULL, 0x806589EC1D7BB79BULL, 
            0x04CDC9D9629F8D31ULL, 0xD104F9363CA2E166ULL, 0xF13612D22EC42227ULL, 0x8007D09F94BA5D0DULL, 
            0x5AF5FB76757885C7ULL, 0x676949BBECA53EFFULL, 0xAFF0EE71D6F0BBB2ULL, 0x37BC33D1C9FEA993ULL, 
            0x217C2C61A7190771ULL, 0xEFFB6B3D02FD5DFBULL, 0x3C1404ADEB499FB3ULL, 0x296854D020753117ULL, 
            0x9DF12897B89AC8DFULL, 0x81A148CD4A618B47ULL, 0x6CC31DD62C73FF0DULL, 0x652099BD99F66A14ULL, 
            0x8A0903E78860ABA6ULL, 0xBE641A2982A1B87BULL, 0xD4B0867993E4470EULL, 0xBC544414E6717B07ULL
        }
    },
    {
        {
            0x0C6268C0F6E9A59EULL, 0xAB94052DC7633862ULL, 0x706C631C63CA832DULL, 0x7752D823EEFC25FAULL, 
            0x83FB4ADA3E50FDCBULL, 0x45671680FDE98B9DULL, 0x28F6BD24611ECE18ULL, 0xB3879B670B51B018ULL, 
            0xF27BB9D0AEC0186CULL, 0x650D6D5AE031EC6EULL, 0x5B22B2DCE1701D75ULL, 0x262D86D6DD14752EULL, 
            0x6A574E8CFA69E367ULL, 0x3458970D4D9B530CULL, 0x1A68A2EA8C74D065ULL, 0x43F49D595F012B5CULL, 
            0x2688B9DDF8B3D221ULL, 0xA613B92FB0E1ACAAULL, 0xB9860E27DEF15EE2ULL, 0x580FC305A9216756ULL, 
            0xCDEE4BFFCF3C9728ULL, 0x4B6C23F925F33348ULL, 0xDC5FED44136DF258ULL, 0x4A81154A69F118E3ULL, 
            0x800E8E004175A84DULL, 0xDE32F3F6F5C49A5BULL, 0x93BA71CABA7F9B03ULL, 0x11905E4102FE9486ULL, 
            0xBF1719372188EE84ULL, 0x6B334EB4E7D56D93ULL, 0x83891F781FDDBDF4ULL, 0x02B90175860BE87FULL
        },
        {
            0xE015957453CF77CFULL, 0x102762EED4125355ULL, 0x2CB1BEFE3BA98FDDULL, 0x37886CD5C0E4A1A7ULL, 
            0xE00344CA1C6EA90BULL, 0x09DC62689B08C946ULL, 0xA64BF927B0C6CD50ULL, 0x90696412944534FFULL, 
            0x1CC018D058413F0AULL, 0x12435B6630B10DB2ULL, 0x2A9E51F44B5E803CULL, 0x6CE266CFC6CB3D71ULL, 
            0x01FFEB0BB78AC679ULL, 0x31C7217DE817427AULL, 0x9996543307D51541ULL, 0xF7DED5B4EE1B94FFULL, 
            0xC87567532160F8C9ULL, 0x438DB84BB364FD4FULL, 0xC4FFA18535582458ULL, 0x3CA699ED0495F05AULL, 
            0xB5329455A2A0E67AULL, 0x7B93C3ED0E80D109ULL, 0xA6C91B81DADA9285ULL, 0x15A57758DB0A9BADULL, 
            0x9AEF828936AFD05EULL, 0x4BB0256FAFBE4450ULL, 0x6698334703BA3CE5ULL, 0x2DB65A1A3AE9958CULL, 
            0x8CA8140F03E4394CULL, 0x2A8DCFB85823B729ULL, 0x57134DD8C6AB6396ULL, 0x98FE0626AB7A10A0ULL
        },
        {
            0x6C6620BE15F7A244ULL, 0x4C8D04F9E01BD7DFULL, 0x764BB58B31842AE7ULL, 0x3599621A8A98677DULL, 
            0xFDA3DF962F5E2186ULL, 0xE48DDF11E73CBCADULL, 0x5F32542213457754ULL, 0xCACA1A13CB57237DULL, 
            0xB1D0BB67AA6601DCULL, 0xFEF95633E10A335FULL, 0xFC30DC014ABF075DULL, 0x24EC42822BAAAEFEULL, 
            0x9E564F364264F9E9ULL, 0x59B2EEC029064E58ULL, 0xCF1B29FAFEF32DE3ULL, 0x1E2D748F98FD57F1ULL, 
            0x6D09B515374D42A2ULL, 0x6354A5D315311E25ULL, 0xED2DE0B956C88712ULL, 0xE39C658773C7CF4AULL, 
            0x0319F4D8C4FAB759ULL, 0xD5F3A2A31EB80C52ULL, 0xDECA84CA000C6915ULL, 0x9B9C1F6A4D5CE598ULL, 
            0xE4A501E907DB020BULL, 0xBB79F856BFA66221ULL, 0xCE44CBEB4B49E3F0ULL, 0xE3112FB2C154745BULL, 
            0x6C7B48BD8FD4D4E0ULL, 0xA72D3C689BFD8759ULL, 0x4700965441002095ULL, 0x4FBA7563E99412B1ULL
        },
        {
            0xC9F4C1CF339AA5EDULL, 0x560E0784B9D4D5C4ULL, 0xC99CE0AF480BBCCFULL, 0xC6A065C1C351A291ULL, 
            0x45CC2EEC147576B7ULL, 0xA67EB0EF0892C98EULL, 0x1238B927BF848AB7ULL, 0x9A3DBB2804C9E669ULL, 
            0x8D07551A178FEA88ULL, 0x4E801BF314B815FAULL, 0xCCF6F377B9D58F86ULL, 0xCE6779AA3B4424C5ULL, 
            0xB5E16EDAD179DC20ULL, 0x4B9E319C939DDCD2ULL, 0x275460280F51604BULL, 0xA235D7FF2D443339ULL, 
            0x1A09C4EEF390C99EULL, 0xEEE8E790E37DC131ULL, 0xEAB6B3E55D948572ULL, 0x8D72F890C35115F6ULL, 
            0xEF4EB95F16FD611FULL, 0x33A2189C1794D5F5ULL, 0xA93FD9786E9FD97BULL, 0xDDDB684CDBB50A33ULL, 
            0x9E72730EE542C654ULL, 0xCC7D57575D8986AAULL, 0x94E7DD31C90A68D3ULL, 0x08608E1C137879D3ULL, 
            0xBE027B9A71A2F509ULL, 0x07B5AF4AC37D19BBULL, 0x107D7E7FB667759EULL, 0x5BEF6D732A84EFDCULL
        },
        {
            0x2A6279E3642FDF71ULL, 0xC62D1DE3CE26B256ULL, 0x8DEB92169D671EC4ULL, 0xEB4D63E8C1C4B0D2ULL, 
            0xC27453CD9F07BECAULL, 0xDD5B07183FFBD7CCULL, 0x35E50F99F692A928ULL, 0x6C81F88732AAE3FDULL, 
            0x2CBCB7664A258270ULL, 0x0E71029B45AB504BULL, 0xB8A9166B5A8152B6ULL, 0x8B9C49AC84738E95ULL, 
            0x0FB512E62D9B3F08ULL, 0xD53E8E0A8D3F34C3ULL, 0x509870481A5AD82DULL, 0x124F2FA9BCC5E112ULL, 
            0x3D7F23D4F6AADEE7ULL, 0x09A71C38807717C8ULL, 0xD9B7337880460A94ULL, 0x2F3C7852E1A8565EULL, 
            0x0C0482CB90E60C6EULL, 0xE18DAE009D7EC7EDULL, 0x190B8A1DE969525BULL, 0xC6DD79C3E1F5240CULL, 
            0xAA0E90772C4E972EULL, 0x846338F3249BEC29ULL, 0xB913A3F79DA6E81DULL, 0x228808EFA7D9A2F4ULL, 
            0x623D0B9896C420D5ULL, 0x173244303014C50CULL, 0xE4A899E4BDF1B87FULL, 0x151C3675D7D15AF0ULL
        },
        {
            0x8EAEEE21643285E9ULL, 0xB8CC5F9AF593EA4EULL, 0xCE2DCB814B9B3F5FULL, 0xC99D74E0C784774FULL, 
            0x764E0F9592A0BB7CULL, 0x206811DBA1377402ULL, 0x11452593258EF940ULL, 0xD5542664D7DA9C6CULL, 
            0xA32EB1BE8197ABDDULL, 0x68EDC2B17BABFC0BULL, 0x46FEA4AD07DD37CEULL, 0x782B532CCFC16C4AULL, 
            0x39228AFD489B7652ULL, 0xE4569E253F98D669ULL, 0x3AB80A94A7406B08ULL, 0xD85CD7353716992EULL, 
            0xF69BF11919BDD44EULL, 0xB0B2FA63626D3FBDULL, 0x0AE6EBCAAAAACF66ULL, 0xCCB2C60278E460E2ULL, 
            0x34C654503B08AA80ULL, 0xF991435CDCB72373ULL, 0x7DF67F7F478FA4A1ULL, 0x3C336E2E17907CD6ULL, 
            0x0EBB52BF21F677F1ULL, 0x9CE9E3957227C8F6ULL, 0xF059772FDA0CDC73ULL, 0x28285AB618E55AE6ULL, 
            0x77084E3026304D45ULL, 0xAA25A9DAEEB8F39EULL, 0x4CF73B4C966A9441ULL, 0xCF41C427696EBE06ULL
        }
    },
    {
        {
            0x8CA48C8F1A09D988ULL, 0x4DDB93AF96D1C525ULL, 0xCDD7FB86ADE13567ULL, 0x9B15B0FC38D3FE50ULL, 
            0x49CBAB336D0ACD38ULL, 0x940BE9356005074DULL, 0xB8AE2B577CA3E46EULL, 0x2212672419C95132ULL, 
            0x6CF3309553C90A42ULL, 0x2491C426593DD5D2ULL, 0x29A7031521520D13ULL, 0x0ED30C269D2F8772ULL, 
            0x3E1F60DCA4585009ULL, 0x87A67442C251A6B7ULL, 0xC049865D7EB47190ULL, 0xDA3EF19A586FD9E1ULL, 
            0x295F4BCA25466F5EULL, 0x0904466024582FCAULL, 0x9259524C003D54C1ULL, 0x008F920184B9A7B8ULL, 
            0xAB271AECEDC548F0ULL, 0xFE9C798588D31AABULL, 0x5CDAB7B824BE29D8ULL, 0x3A486808D67F4CEFULL, 
            0x4C5A873322203288ULL, 0x0C28B61548848FD4ULL, 0xE51D6A4803DE73D0ULL, 0x8C3C0D1D0B276009ULL, 
            0x9D13A1DC2349CB5FULL, 0xE0A56AF64EF4C550ULL, 0x19B9DB8A1B184FA9ULL, 0x939DFE33D33C0311ULL
        },
        {
            0x1213F221EB5885F1ULL, 0x6D41AFC5DD44193EULL, 0xE04F46DD1A226B80ULL, 0xC86F0CCBBAC662A7ULL, 
            0xB12F84E6A3DF984FULL, 0xCB1754B5113A1343ULL, 0x3AAFE207075DB84DULL, 0xB7957E1A310770ABULL, 
            0x611F66EDE65DBEA6ULL, 0x63600A5E758FE80DULL, 0x516200DEFCED21F5ULL, 0xD60988CDAED9C387ULL, 
            0x50797C7C0AE3240AULL, 0x2D00077AFA02CB65ULL, 0xFE4F4DE340DC46ACULL, 0x9D69A6A88DD99BDFULL, 
            0x087E6F1E7E419B92ULL, 0xCA7DA1372902E479ULL, 0x376ADB7CDF4F0BB4ULL, 0x396B55BB4194B685ULL, 
            0xF3FC42B857D440D0ULL, 0x0D0EA57E33451EBDULL, 0x338EA0113C99ED31ULL, 0x69AD81BD32974CA5ULL, 
            0xA58C5D2987598723ULL, 0x5491270B876757E0ULL, 0xF5B6CC1BE915A028ULL, 0x4C837F37F1988188ULL, 
            0x2A07D76766786F1CULL, 0x413430E318763357ULL, 0xC57C3CCCAFE7AF5CULL, 0xAC3BA986BBBE31A3ULL
        },
        {
            0xB5EC5FB2F4166C0BULL, 0x1AB3755E531988F8ULL, 0x5363BC85E6DDFA63ULL, 0x5AE04A873BFCD850ULL, 
            0x3A7DB402E911728BULL, 0xA2EE2B5025D30DF1ULL, 0x260939EB0F5F7F98ULL, 0x02C0D9C33EBF8DADULL, 
            0x3FA8D0BB96ACA942ULL, 0xA113F06BEF8B8D05ULL, 0xD1FE4BCB473A9B92ULL, 0xB4729BA55E60F51BULL, 
            0x72E273214D3A58CEULL, 0x23CD68F2E45CE4F4ULL, 0xC6F5EB7A63935945ULL, 0xF162EEBB968DF272ULL, 
            0x8C8E79E938A6A51BULL, 0x4D4D5424E3FBB6AEULL, 0x6B87455D6D1CF5AFULL, 0xC8B44F1014F8F02DULL, 
            0xCD7F9E51EFCE72E3ULL, 0xB5D27DECC551AC96ULL, 0xD19D7090670B73EDULL, 0xB7D80F4FBADDC2A5ULL, 
            0xACC33AEE67FAF9F7ULL, 0x2662545191E81414ULL, 0xCE49607A1EE17EB1ULL, 0x55D97961667C5C62ULL, 
            0xB3BCB02F34AA9431ULL, 0xE18E6CEF1A14F66AULL, 0x81EDFDF95FF5B365ULL, 0x9DF76316CBAFC5ECULL
        },
        {
            0x454659417036A299ULL, 0x45AEE3AA2F3CD130ULL, 0x5C2BD014A33F99ECULL, 0xA88E978615592CFFULL, 
            0xEC7B2F3F45193A8EULL, 0x086A040ED29DF47DULL, 0xBB1CAEB458E2403BULL, 0x4B3946C60FF0290DULL, 
            0x0D174FC893364488ULL, 0x0C36E57DAEF06218ULL, 0xF5B74EE01484246FULL, 0x2BD4A5722228FB03ULL, 
            0xA30DB1001625B286ULL, 0x60C50D2C6BEC0D3CULL, 0x1F732294A2A5A262ULL, 0xCAF72CEE3B7ED5B9ULL, 
            0x535862CACF117F85ULL, 0xA163EBBE2D4ECE76ULL, 0x2C4A5AF65CA8CF86ULL, 0xEA27BFE5EC8098C9ULL, 
            0x8F6FFD140C53C44EULL, 0xC9591ED5CC742635ULL, 0x0EF647B77C5AB480ULL, 0xCAAF3B7E446049B9ULL, 
            0xDEBD2DE23772D523ULL, 0x4AAADCD26E9436ABULL, 0x07B258AB11E63C37ULL, 0x776E51E70085C3A4ULL, 
            0x93CE6927ED8535BDULL, 0xEF462B5F874D2A19ULL, 0xF7647923A4C877FBULL, 0xB126FAC77D862184ULL
        },
        {
            0x83DEDEFF0BB517ABULL, 0xAF10D7F1524D16B0ULL, 0x50A310E8F1232AABULL, 0x9644BCB84C46048EULL, 
            0x3E5264436CDDB737ULL, 0x449EA99915B2DC67ULL, 0x876A7703B82A6E05ULL, 0xF58ADD7FB8C690ABULL, 
            0x29D09BA8E1B6B459ULL, 0xC2CCC48587102890ULL, 0xC20591ABF096059FULL, 0x1928C9FF988B42B9ULL, 
            0x2A82D566FDDF8BDBULL, 0x2E0181901AEAB41DULL, 0xF83C2E8F5E2F8BB9ULL, 0xD9C9BC863EF80A06ULL, 
            0xFEA1B37052EB645EULL, 0x4C54155517324E9BULL, 0xA9A59CCE0687878FULL, 0x76F5C68B5D8F75D9ULL, 
            0xB25EB0964B530CDFULL, 0xD6AFCB82A78CB430ULL, 0x1525F233D051DCB0ULL, 0xE6E88E132D50C9E1ULL, 
            0x68FDB58BB610337DULL, 0xC09B16FC7968A5FAULL, 0xD73A6E3EDDF26784ULL, 0x001674E10CFC1897ULL, 
            0xD0876D2909753947ULL, 0x75612FFC4E164825ULL, 0xD29569313CC51256ULL, 0x3E5C9E003C1B20E7ULL
        },
        {
            0x6D2FA23B2B1E8843ULL, 0x594AE992A400AD43ULL, 0x44476875C87AD603ULL, 0x124D316500423B40ULL, 
            0x61AB20E56B7E40D0ULL, 0xCCC9D59C00A3BEEDULL, 0xC66C38321AD2BF72ULL, 0xC757E2CE89D84D27ULL, 
            0x16CDAD997BDD5308ULL, 0x63AFCCD33F43F442ULL, 0xB5377ECA6B627C68ULL, 0xF2E77314507E3F64ULL, 
            0x90FFC2D73C271832ULL, 0x99A57582CC9768D9ULL, 0x5CBAC666A5173D71ULL, 0x573AB8686D49A1B9ULL, 
            0xB76EE40BD8AFDCE9ULL, 0x8C6FD0CB73D73B73ULL, 0x08B280AEF4F048C3ULL, 0x1ABAA5CEF2C93EEAULL, 
            0x8C71E3F3716B3ECAULL, 0x68B8A569EABC1AD5ULL, 0x12A2C55F9917504DULL, 0x38DFE5CB8CD12943ULL, 
            0x9C3A8A0486DA7F07ULL, 0xEEC11DEA8FE446D7ULL, 0x2A59BCFC15F6C4BBULL, 0xE42CC5B1B955A167ULL, 
            0x186528F002C10C1BULL, 0xA1C89316C29A8D2AULL, 0x6C261A1A09B71B56ULL, 0x644138BF7464500DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseFConstants = {
    0x5767D4EAE2BE42CCULL,
    0x6BF29D586B6CA11BULL,
    0x0438E3542F9BAE0DULL,
    0x5767D4EAE2BE42CCULL,
    0x6BF29D586B6CA11BULL,
    0x0438E3542F9BAE0DULL,
    0xD97D4F8FE691B378ULL,
    0xB48CB7E2B5087B8BULL,
    0xE8,
    0x9A,
    0xB3,
    0xFB,
    0xDA,
    0x90,
    0xF5,
    0x2D
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseGSalts = {
    {
        {
            0x2CD8A7EFF428BD43ULL, 0x08B60D0F316F2CA7ULL, 0x9F4C3B9AFECF644BULL, 0xB389163645B95B7EULL, 
            0xC399D4107FAB87EFULL, 0xCE7EC3573F108E49ULL, 0x4FC9233E987F548CULL, 0x6D6663BC3444959DULL, 
            0xD9CAE357232D6E45ULL, 0xCB7E1EE156CA7941ULL, 0x92DF688529293970ULL, 0x39C14353A3E3EA20ULL, 
            0xFD846B7D4D02FCA3ULL, 0x37E949EB3B593681ULL, 0x3380B50A4EE66A22ULL, 0x4FDB4AF3B9403C80ULL, 
            0x4675488AB630CADAULL, 0x3F2924E60551272EULL, 0x1DE8E2EE6A6C1452ULL, 0x268C11A723687D9AULL, 
            0x7359C36746745773ULL, 0x4FC7169AA34317A9ULL, 0x8CC869157D98A922ULL, 0xEFB61AC9027B4A97ULL, 
            0x0FE133181B93C52AULL, 0x460F2641164CB4EBULL, 0x80C9ADA8FFAD6AC2ULL, 0xC3233656597D42A2ULL, 
            0xBBC7C903CFA7E3ACULL, 0xFCD721EA6B580950ULL, 0xDFFF501D03883DCAULL, 0xAD519E89936BC248ULL
        },
        {
            0x649F3D63B8B789EEULL, 0xA0DBCF872E3763C1ULL, 0x2473DDB6552C0E62ULL, 0x21C2ED37AC1BB5ADULL, 
            0xECB7682D88CE733AULL, 0xE64A147039FFD360ULL, 0x4C8037A4D99196F5ULL, 0x3AE0ED7A30A16C09ULL, 
            0x16362EDB5FD58865ULL, 0x71EAF899C2378C8AULL, 0xD83C8752652235B1ULL, 0x08A9294CDFFC5A42ULL, 
            0xB38F71FADE91CADFULL, 0xA31AFB2FAB8D95C3ULL, 0x64A7C25002D8F486ULL, 0x7008B47776764068ULL, 
            0x3BFA8D87C7E7BC54ULL, 0x614896C0FCF48253ULL, 0x5EBFE4E6658FC441ULL, 0xFFF88CD152049167ULL, 
            0x417EE6A4073B0006ULL, 0x501D9C1CB2917FC0ULL, 0x6FE4875F29627BE6ULL, 0x5491F865F9FB4373ULL, 
            0x6D9BB2B70426B1B2ULL, 0x35932A1F7DFC8B85ULL, 0xEE5C9E3CB5E2E27CULL, 0x60C4A08AA90D1295ULL, 
            0x3F9ACF5BC79189F0ULL, 0x346570D4A21FCF39ULL, 0x2D9ACDA2F6D00A74ULL, 0x6C0EC9EE62998A87ULL
        },
        {
            0x28ED75AE13DB56F5ULL, 0xC7B060B06C1F828CULL, 0x41B7F69F1F06752CULL, 0x6EF94F78663B3A99ULL, 
            0x7740646D2B4AEDD5ULL, 0x21777A24CD1D471AULL, 0x2F180C0549185586ULL, 0x9172C996C631A5B0ULL, 
            0x24246654E6E18711ULL, 0x64E0853D21AB938CULL, 0xD68D1DB3490014DAULL, 0xFD1622187BBB3BBEULL, 
            0xD63C5B6C88399FC6ULL, 0x4174D7FCD694AD5EULL, 0x9CE3B7AEF44E3A46ULL, 0x572FC336C3EE5FC8ULL, 
            0x00CD79677A73C23DULL, 0x545346179D484FE1ULL, 0xAC0F620BCCEE3A2AULL, 0x401F555DF6F8FD74ULL, 
            0xAE60AF4AB05EA98AULL, 0xBFF4F452C6BE9BC8ULL, 0x4ADA87230647A273ULL, 0xB1F4A2390A1B684BULL, 
            0xC62687F89A30486AULL, 0x92568DA57E51990DULL, 0x549EC9B367604CD3ULL, 0xDE76993390A9BF2DULL, 
            0xFC7F4C9282FB61E2ULL, 0x7FAE023B9D69D965ULL, 0x249FDBC7F5234F01ULL, 0xAA233537F69E4D00ULL
        },
        {
            0xD54437F64FD1DAF5ULL, 0x50CD2141BEBB4D93ULL, 0xDEEB46075729A5E1ULL, 0x1D483F5F0AF19343ULL, 
            0x22B5AC02544B0321ULL, 0xA0CCB96BC08715BBULL, 0xA95DB2A1FC805563ULL, 0x68C737485E563C3CULL, 
            0xA34DEF0F7076FC32ULL, 0xF5484FC2E0E197F6ULL, 0xEDDA410D02894D0AULL, 0x7CEF4D2BEA1CAC33ULL, 
            0x5E0ED2DA9AF1A5B8ULL, 0xA70E10880F112BF8ULL, 0x0FAC7B784BB1CB9BULL, 0x7FFD27CE12D2D480ULL, 
            0x23B7A63C84AC1363ULL, 0x9B5BFBA92CF64710ULL, 0x4FD196C3EF8189FBULL, 0xBF5354B92CE1A254ULL, 
            0xAF7FD9B436E33E83ULL, 0x35D1E3A53EEC6040ULL, 0xD4023E5A82D27FAAULL, 0x15C76B91F310475FULL, 
            0xE42E9BB9D33F5D15ULL, 0x8695F9B827586D1EULL, 0x4C257F0F9BC5B563ULL, 0xAF264AC0130E44FEULL, 
            0x7FF08C81D9DB0C77ULL, 0xDEC5AE1E672E1D26ULL, 0x5A9C5287AC9B434EULL, 0x39CD99F1F5862725ULL
        },
        {
            0x8D050C606FAF6BD2ULL, 0x29E082FF5FDE4B48ULL, 0x643F1C1FBD6E6AD8ULL, 0x3A3E8BB9FD64C058ULL, 
            0x6EDD5BCBF5243CD1ULL, 0x01B5E72D069A060EULL, 0x1F83BE9F8B93949AULL, 0x6EA60046067DC35EULL, 
            0x1379D10EAC6224A4ULL, 0x7702F7680B871E50ULL, 0x7D686B083FF5D63AULL, 0x53F31A673F0C977DULL, 
            0x7B3238A9D42CFD32ULL, 0x8A0282969E565778ULL, 0x28EDD16B313510B2ULL, 0x34E95BD81C5B13CCULL, 
            0x358DCE0681911AB1ULL, 0xD6D9446E47AED011ULL, 0x12F4FF8E99DEFEB8ULL, 0x6D531523095E5B38ULL, 
            0xCD7F64512EB61255ULL, 0x6A57A0670F769EBCULL, 0xD675A18F3EF95DCCULL, 0x75DDEC29D12F799AULL, 
            0xC62431B0A21AB394ULL, 0x9CC619D5BF28238CULL, 0xD77F90B8299A28A3ULL, 0x436C1FCBB615EC54ULL, 
            0x0586C925D3D94386ULL, 0x226578AC10CF07F8ULL, 0xAF7FD9911914D6A3ULL, 0x4D6CD64239CDAA9FULL
        },
        {
            0x22A9F162799922D1ULL, 0xA42D31692DA44724ULL, 0x15D592EBAFAF61F1ULL, 0x637131E35C4547BAULL, 
            0x1427C1850EB95F08ULL, 0x16FA7360A35D8D77ULL, 0xD87D73732D1AD043ULL, 0xE557D753532B4D3EULL, 
            0x07FCF6A1ABCCF435ULL, 0xB92522DBDAB09831ULL, 0xDC6E497519C5ED6BULL, 0x69897C72D14A8075ULL, 
            0xAC0349B1A03A2F2CULL, 0xA1464547E0F26DB1ULL, 0xBDA594E2DA46F38DULL, 0x83DFC7BB2ACF099BULL, 
            0x3E7D16E104FC45ACULL, 0x2468A066C4E02FE9ULL, 0x69678536C2A18CA5ULL, 0x8AFB675F57F6E9EEULL, 
            0x6879F509691AD140ULL, 0x445F1D3C2D64B8F5ULL, 0x5280930F2B026C1BULL, 0xA8809A363832B9D7ULL, 
            0xF0C952AFB2DF0EF4ULL, 0x2A5B6BEDD22BE919ULL, 0xCADAC0348EAA6E74ULL, 0xAF2AFAD1B8B6E6EAULL, 
            0xBD18C845A2E9F4F3ULL, 0xA5F3065AF33A8D82ULL, 0xCEF6CD783C6B692CULL, 0xE36253CE050EF97CULL
        }
    },
    {
        {
            0x568274A53A96D326ULL, 0x4DA07FA549FBC7D6ULL, 0x70CE43573E307567ULL, 0x0469A2A610EF780CULL, 
            0x1F728A49E1DE8F9EULL, 0x6EF565AC635D44F6ULL, 0x68F502AFC523C3DCULL, 0x0FB7F2A052CA2093ULL, 
            0xA03BB7F25C5AF586ULL, 0xC3F231F0710DF662ULL, 0x898A46B94579051FULL, 0x11E6821362FB979FULL, 
            0xB621A5EB9B73C106ULL, 0xAD60BA3BAD7FC8A8ULL, 0x25FB556C80DB4C3DULL, 0x513141805AEF2E39ULL, 
            0x30293818669A87FBULL, 0xB74129FC752AEAACULL, 0x0835139D7B44E056ULL, 0x535A89A30CD8EE49ULL, 
            0x9A7E1E892F6DF18AULL, 0xE562F35BAD89494FULL, 0xA10C02616B0F195AULL, 0xB80505F400C48F54ULL, 
            0x1F5D9A030292065FULL, 0x6EA3B33FCA7E5A26ULL, 0xB36898059EF3FE0BULL, 0x06BFEE4772A0E9D8ULL, 
            0xDC017B49E6EB0424ULL, 0xFBD1ED025888D9E9ULL, 0x397DD4AF9A2AA032ULL, 0xE86F34CA802482EEULL
        },
        {
            0x523AD13AA3821C6AULL, 0xFA78063D12E06FBBULL, 0xC38268897649242CULL, 0x2E34984B0AFE3B82ULL, 
            0x8FC6C91394BC3F36ULL, 0x793DDE4152690194ULL, 0xBD93BB3379D627F6ULL, 0x8A6C520E7ACA0D5FULL, 
            0xDD27114D9AC553E7ULL, 0x4935BC2D1E19F297ULL, 0xAF9BF4DDB89E5774ULL, 0x07B44755F85943B6ULL, 
            0xE8847D76E69F39B2ULL, 0xFCC1480D7F2A6EE0ULL, 0xC0B032644F2354A4ULL, 0xE25375ECCFC33AB2ULL, 
            0x927EB8A815746B03ULL, 0xB12461C5056C5109ULL, 0xE11BB10BF4367E5CULL, 0x9262F7A551A9C685ULL, 
            0x81818F81206BFFCBULL, 0x15F4AB60D5A66B21ULL, 0x24457BF36F235520ULL, 0xC4F32B5C7F3BB03CULL, 
            0xCADACD38B2EC2845ULL, 0x6DB92CDAC3E56A83ULL, 0x2A3C1F221BB3D653ULL, 0xAB52BAA13C78130FULL, 
            0x5A2E51D2F570E195ULL, 0x46A39C6134CE27DBULL, 0x4BCB6A2A5D445352ULL, 0x6515F54924406D83ULL
        },
        {
            0x0E1B175EC77FBFF5ULL, 0xA059620893055AD9ULL, 0xB615E474D365162FULL, 0x2FE5C919F3035ADAULL, 
            0x7A84F3C9D910D454ULL, 0x46DBF9B10BB562B4ULL, 0xDF16E5B4DC1DC709ULL, 0x52B0A946536F6527ULL, 
            0x43744C172AB0B455ULL, 0xDDDC85B32C39D2BBULL, 0x991B21995BE85208ULL, 0x5898EB2DE88C5FC6ULL, 
            0xAB665211E8F37B40ULL, 0x50328E89ABE87C5EULL, 0x0618B5678429A1A6ULL, 0x83B13CED2A1A6009ULL, 
            0x00F39559CC7DE852ULL, 0x7ECECAFBC11DC657ULL, 0x47B6278F0FD2EFF3ULL, 0x825969781942E38FULL, 
            0x1A7744334E20F881ULL, 0xC3026529822C0ECCULL, 0x4F92DDAD6E36C60DULL, 0x6E2E3C253C8A61F5ULL, 
            0xB347B076DE012A77ULL, 0x77FCCEFB37035CB0ULL, 0xDF3EB0A5490E092EULL, 0x174A1630E25292B3ULL, 
            0x523BA926399A3013ULL, 0x97CD997CDFE8C205ULL, 0x71348388D6C57403ULL, 0x5821AD2A0F098904ULL
        },
        {
            0x17DCD79534FD85DEULL, 0x56FF11E8E6FC00ACULL, 0x2CCEDF51EA5993E7ULL, 0x297F3A44DCF2A54EULL, 
            0xEBACF7DC860B64C9ULL, 0xAEE72FB7C387F8D9ULL, 0xBFB920BA4E450436ULL, 0xE74933046FDF7CF3ULL, 
            0x1DCDF995AD52CB99ULL, 0x5F279C0C46030E94ULL, 0x8D53221E53A8F570ULL, 0x6EB9BEBB808541FFULL, 
            0x435C9E45CC60692BULL, 0x7C96E10E31BC0022ULL, 0x6BE37E9D63BD8965ULL, 0x3F03F1456A07CA8FULL, 
            0x8CAA79DEC804BDAAULL, 0xA4A76559EFD0BB2CULL, 0x4DB2D48450D6F354ULL, 0x7461B49978432F58ULL, 
            0xD2052E058157A09FULL, 0x7A84FEF9E81F0D71ULL, 0x249F03BD87DE4D6FULL, 0xB1D340F15F46F581ULL, 
            0x6D318E550544F9A5ULL, 0x1B49B33BCD022135ULL, 0x6D2F8212FEA6B0E5ULL, 0x8B91A81066B218BAULL, 
            0xD47713BE79EB56AFULL, 0xF219769390D715FCULL, 0x0C63C78425CEEF3DULL, 0x0AE7845E2B9F9DECULL
        },
        {
            0xA51D62CC8BF2C91CULL, 0xD325AC9D2997FD5EULL, 0x8227531E7FB7347FULL, 0x55AF53CB9BE42E54ULL, 
            0x32D7377D8575BA1DULL, 0xFD0396B954FE50A8ULL, 0x990F7E2702FB7F82ULL, 0x991FF71886E524A2ULL, 
            0x4F8AF26B95FD6549ULL, 0x8D8F0239F1A8B222ULL, 0xCACF6016943F019CULL, 0x4C64B20765BF2714ULL, 
            0x182F04DCD0DD7607ULL, 0x2147835F144931D7ULL, 0x59E29DAB74BCD677ULL, 0x896B9627ACD84A18ULL, 
            0xC34F5DF80C4C8571ULL, 0x856A8E77AC439A1AULL, 0x8194D554FF209F7CULL, 0x5318ECA78420B359ULL, 
            0xBF61C563428AFDA3ULL, 0xA711696642E4D2DCULL, 0x8CC9BC99AE3C3BB6ULL, 0x2F222F0F9713D55BULL, 
            0xCA79AE528BA1FEC0ULL, 0xF91F60FB5449BC21ULL, 0xA40FAE70D8E21353ULL, 0x36F4BA9AC1CE80E2ULL, 
            0x71883268284098B6ULL, 0x342BB11BEC5FBCC4ULL, 0x6F253B15097797BFULL, 0x5C3406828F40842EULL
        },
        {
            0xEB5BF16015B2B728ULL, 0xEAADDFFFA60EC2F3ULL, 0x782249E56994A6FBULL, 0x297994906BE20257ULL, 
            0x839AD29C405C4296ULL, 0x66F7E7F49743AA20ULL, 0x75DA8208029C9A1BULL, 0xF298FD57AB424FD9ULL, 
            0x3B86478BBF046CF5ULL, 0x705E98BBA9B02969ULL, 0x9FA4777DE93EC563ULL, 0x9EFB510536B928A4ULL, 
            0x96496D6301E5D3C4ULL, 0xBE494876247C2EBDULL, 0x19C6C8A9498A280AULL, 0x96138DCF1267B177ULL, 
            0xD50B2B5F15F02831ULL, 0x726DAA30D5952FE4ULL, 0x293CE95E6A3445C0ULL, 0xF87495B741354E64ULL, 
            0x8E9B4B2F0D6D1340ULL, 0x92B3E2D88D30BF3EULL, 0xB7C9595743AD794EULL, 0x8E12B8F3A89A419AULL, 
            0xC777EE7D7D2CB8DFULL, 0x7B904ACF317B067AULL, 0x797E93FE533DAAC8ULL, 0xA7476FF860E8447CULL, 
            0x63E3619AB2D48BB9ULL, 0xD9C20AE4265D96F4ULL, 0x8D2E74A64B8A4339ULL, 0xC726E688DD6FC7D0ULL
        }
    },
    {
        {
            0x4A618520FAEFC448ULL, 0x66047FAACBD68A35ULL, 0xE94A2BF3B8D637A8ULL, 0xECF1C36FA687D825ULL, 
            0x426D0E239089F9C2ULL, 0xB091DE17FBE58217ULL, 0x27DA1F3B94CB3C46ULL, 0x8C2239C05921C3FCULL, 
            0xF7EA5EA0B61924D1ULL, 0x1D5139A6D4F0335DULL, 0xF41667F5CDD7114BULL, 0xFEA7F2BC1C3AEDCFULL, 
            0x6A9627BD9E5E93C9ULL, 0x001703C785B97FD4ULL, 0xE4936ACEDA5A2C02ULL, 0xED16C352BF688479ULL, 
            0x65694E1F39437C7DULL, 0x1C40773C71310330ULL, 0x859F3E12A7532751ULL, 0xF45A2D95E18D70AFULL, 
            0xA50ABC44455DCA1AULL, 0xE391591426FE69CDULL, 0x932ED127F8FBAAC5ULL, 0xE6D45B5DCC465804ULL, 
            0x3D1BBA7D8CD3011CULL, 0x96D5141C733F686DULL, 0x9C7D13337CFF8D70ULL, 0xCF79A5631F4B0BC4ULL, 
            0x24FC356852578BFDULL, 0x1EC9E99DED52E270ULL, 0x012079B10AC53E2AULL, 0x46F0CA3593C06F47ULL
        },
        {
            0x3CCD3BC44F342A2EULL, 0xEED98D542B6F96E5ULL, 0xBCB07FBC5EFDA743ULL, 0x99944CC0C03F5B34ULL, 
            0xE2B9758D2E99DE13ULL, 0xB9FD26174D086622ULL, 0x30A8367020888861ULL, 0xBE4387779F46B15CULL, 
            0x904859EEAEAFAD38ULL, 0xCBE697B4075CC5EBULL, 0x41FB9925169CE58FULL, 0x09292AF99202A134ULL, 
            0x7D0C72AF93A37F1FULL, 0xF517E7A85625E891ULL, 0xDA16D80CAD469183ULL, 0x0E44371C4A0A9B6FULL, 
            0x73028DC4BDD19B7FULL, 0x1DF24AB297998609ULL, 0xF5F14416EB12B9D2ULL, 0xEA6CE11F0C2D8B47ULL, 
            0xCF117EA2A263E059ULL, 0xE88E071B9C98198EULL, 0x68F7E364866C4484ULL, 0x7A5DFCE440149E89ULL, 
            0x007F90B8F3EA9AC8ULL, 0xA3DA8B6E2F70E053ULL, 0x31A00FAF60B65AC2ULL, 0xB56D668C88490C1AULL, 
            0xBD366981360F0513ULL, 0xDF21A15E30E0296EULL, 0xD15FDEC84F811AC6ULL, 0x106C6DCBFC0C41E0ULL
        },
        {
            0x8406D139100E2A3FULL, 0xBC13CB9FCAD8454AULL, 0x370EE7F9230C2AB5ULL, 0xE7130553107012CCULL, 
            0x5991C60E69F3A6A8ULL, 0x813205938FD985F9ULL, 0x0AD85756BA4F1493ULL, 0xF8DC6E2A8D44826CULL, 
            0x0F0B048563CB256AULL, 0x80EBC2380E6C2952ULL, 0x4FF1CA0F67E26893ULL, 0x92EBF55DBCE0646BULL, 
            0x3D4B06B5545311F6ULL, 0x249DA75BB0E0EBF0ULL, 0x48D54D50C9A1C50BULL, 0x3701903BBB14CE35ULL, 
            0x0C6D62133055E21EULL, 0xB038F50810B04C97ULL, 0xAB6F236CC684E1BEULL, 0x264D735B276A14BCULL, 
            0x34B58D3539B2311CULL, 0x5570A5E2789DE81FULL, 0x245A931226B3BF11ULL, 0xC06FB9FABB5D6CFAULL, 
            0x0852F45FED167232ULL, 0xE8B2AFDBC33FF3A0ULL, 0xDD3BE612821BD6EAULL, 0x8A053DACBDF55E90ULL, 
            0x85FC647C9701B445ULL, 0x6ED13FC619712822ULL, 0x6CB20F4BB503DA53ULL, 0xAA2C054497CC9A3DULL
        },
        {
            0xE339F092CADED487ULL, 0x0F0336CAA8126D3BULL, 0x933D6149574BDC6BULL, 0xAF043E1522A8DC78ULL, 
            0x0A77D722272E301DULL, 0xBE74DF16340312A9ULL, 0xBD38D820080D0402ULL, 0xA7DACF99D65AC1B4ULL, 
            0x086E45B7EA00CF87ULL, 0xB6D3777DA8DE70BAULL, 0x6C48A39141E02E8AULL, 0xFA3794425AEC6B0CULL, 
            0xCF67C226BEB6676FULL, 0x760990CF17B83F6CULL, 0x8999079C413CC0ACULL, 0xF2AA7E963D8AF513ULL, 
            0x5DA546C1F32CF6ADULL, 0xC3C577CBF9A5471BULL, 0x9E512E4FE5FD2BFFULL, 0x4AAF13E77D11D529ULL, 
            0x3072FEEC1444D814ULL, 0xF3AA66C35439160FULL, 0x52B0D9E3A2F89D7CULL, 0x6E13D18FFB2B8578ULL, 
            0x83F31CFFD9523AF6ULL, 0x17AF8AE37D9D380EULL, 0x12DBDE3006AE1DD9ULL, 0x9871020B21D28D3BULL, 
            0x455F415C0D66CF38ULL, 0xF37FE1D064AEB538ULL, 0x9E99B6CAA28AF29EULL, 0x51A36A2EB382BB5AULL
        },
        {
            0x24A410D0242B2C1FULL, 0x16EAE1C7DFC99FF5ULL, 0xEB3F4C72B2C10A3AULL, 0xA2DBDFBD9F8974CEULL, 
            0xC903AC8D5EEC2BECULL, 0xB6121E4F183B7F83ULL, 0xA3E70F09488D7F55ULL, 0xDDC69BE3880567EBULL, 
            0x6C5DFECB2F409754ULL, 0xDA1EF73D8CC04F08ULL, 0xC3773BF615EC49E7ULL, 0xDF726668B336D5DDULL, 
            0xBB2006D6265E63C4ULL, 0x221635EE8BE80ECFULL, 0xBF59AE7885D626FDULL, 0xD39F72B27A37BA1BULL, 
            0xE4A77A141F8A7BABULL, 0x2AB941FD6DD3AE03ULL, 0xADFFE63F3326B94FULL, 0x149B34DED78D7F03ULL, 
            0x2BDF347051CB3E46ULL, 0x36FA90C2AA7A101DULL, 0x6A88630C5D906939ULL, 0x086809B649A03AADULL, 
            0xE7E1C7066B6D3A16ULL, 0x54B4A4E83A4302B4ULL, 0x512823AE13FA650FULL, 0x4DDAABDA6C3BA4FDULL, 
            0xC2A3381921BB7F8CULL, 0x30B7480DDE41C794ULL, 0x9E79DE3C85C39E7CULL, 0x3C8DDA867A2B7FB3ULL
        },
        {
            0x0167F203410FBBF4ULL, 0xCC00A20C7560B8F8ULL, 0xE906C31117F2D407ULL, 0xDABDCBA0CA50AA4BULL, 
            0x8CD74E6003143E33ULL, 0xF591275E79C9271BULL, 0x245E7A1756F44F8DULL, 0x069F519E14A82BFDULL, 
            0xB094A197D5FADA9DULL, 0x2DD168D3DD292437ULL, 0x2BC650D97B42A470ULL, 0x0915213D01793B22ULL, 
            0xBCDEF56A71C45BF0ULL, 0xD40870E3900D7E77ULL, 0x7CF83A536BB257C6ULL, 0x631EE2A8199E67B9ULL, 
            0x3248DD6F929BE121ULL, 0x44CEF946B6803E28ULL, 0xF9CBA81FEED41ABCULL, 0x1A75CAD076781207ULL, 
            0x9A6161FE166903C8ULL, 0xA597F36CAE2F03B3ULL, 0x24E5DF5DA08C4737ULL, 0xDE183D4DA520B342ULL, 
            0xCC45C098597E0F21ULL, 0x836A949AD09E21C1ULL, 0x30B10520BEF4D0A5ULL, 0x00F23D67CD8D8E28ULL, 
            0xFE53D28FA141BB30ULL, 0x76556AC005CD2B58ULL, 0x4A91E9C4DEFA38DEULL, 0x9B27D344E1501C76ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseGConstants = {
    0x8F13F2648180FC72ULL,
    0xB93C67544FF8409DULL,
    0x632DEADEFF9CD6DFULL,
    0x8F13F2648180FC72ULL,
    0xB93C67544FF8409DULL,
    0x632DEADEFF9CD6DFULL,
    0xA08206206CD241FAULL,
    0x607042D330E40A99ULL,
    0xE2,
    0x7A,
    0xB8,
    0xE9,
    0x86,
    0x60,
    0x64,
    0x33
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseHSalts = {
    {
        {
            0x12719E8661A23541ULL, 0xCF97122E62BDE075ULL, 0x2743D479DC456A40ULL, 0xC7B55B8AB5D55549ULL, 
            0x175A91E391D2E7FDULL, 0x761B294F7939738CULL, 0x564595EFA294990BULL, 0xB88CBDD7180B3374ULL, 
            0x82B91FBABD6E5538ULL, 0x305A9BCE7E752E0DULL, 0x2FDE1CE91968D9CBULL, 0x793DDE4F006A1B78ULL, 
            0xF48BA27635768E21ULL, 0x9B9F5B09848BE216ULL, 0x8B9E93FF200DA22CULL, 0xBFF46DBB74D6E646ULL, 
            0x86F6E474C325435DULL, 0x3400A67A03502D52ULL, 0xC7553FD2781327E7ULL, 0x4D0235F6B26A52BCULL, 
            0x60E830A84EE1292BULL, 0xA50924E45A3FC2C9ULL, 0x31A400AC03685F19ULL, 0x9BF78F3ECE9DF6F6ULL, 
            0x0AAAC2AF4FECEFFEULL, 0xBC75D66694A3C80BULL, 0x52C5609BEFF16885ULL, 0x50B73BDA52DF6E97ULL, 
            0xA88F0B833EEF2FD0ULL, 0xFF69FF640A40F9AFULL, 0x4ECF4057D639E814ULL, 0xFDD69C1926CCB67AULL
        },
        {
            0x395B5CA6FB299F3FULL, 0x9D877CFD526858ACULL, 0xFEB1C12C4305679DULL, 0x658BBBF388A76E42ULL, 
            0xD2E4DDCE23CD99A1ULL, 0x27AABDA4AD99B1B6ULL, 0x81923AF0FABA56FDULL, 0xFEAC2A561244C883ULL, 
            0xCCAEFCAA2713A307ULL, 0xD15BC543DFE4189AULL, 0xDC690A89BBA1568BULL, 0x366C23E0B0220B56ULL, 
            0x75666F9C263F6054ULL, 0x2973F1D18406FA78ULL, 0x9F76E6755D616C87ULL, 0xAAAAAD39AC8C116CULL, 
            0x1E46F50651EAF1A7ULL, 0x8375D176B245495FULL, 0xF7A70B91CE358899ULL, 0x7E1226A762942B62ULL, 
            0xC1417F3E42A766F7ULL, 0x95842FF09F391202ULL, 0xF67367A740A29875ULL, 0x8C7AB009717DB3C8ULL, 
            0xF366204821D317DAULL, 0xDFB6DD028378841BULL, 0x379536868B7F0F9AULL, 0x174FB2FD0BD29751ULL, 
            0x2D3B4C06FCED6A33ULL, 0x04EBD0DE1C44BE28ULL, 0x493C35CCC7AF6069ULL, 0xD96F0A68E9438019ULL
        },
        {
            0x07590371FA8BAD59ULL, 0x87FAC220E1AF2529ULL, 0xDB32702BC55A47CAULL, 0x0BE7E9C532F36371ULL, 
            0x943F749D816BAF32ULL, 0x8DBA5EC05A68C3C6ULL, 0xD0FE9DB3197E280BULL, 0x8D40BF3261BF7F3AULL, 
            0xEE460FB0CECFA20FULL, 0x40096BA1752C7CA7ULL, 0x5CDC7CC12F651F06ULL, 0xE135031962F08FF8ULL, 
            0x438F2FA84DE389E1ULL, 0x92004A45C804E167ULL, 0xE6CAFDB69D5D804AULL, 0xB0631A44BA237EC7ULL, 
            0x4327FC2D78D64EA2ULL, 0xAE2675CA1574902BULL, 0x6E2D8CBF0259C913ULL, 0x49F9D568D197F8DFULL, 
            0x0D1D5B62F1845B78ULL, 0x9A49CACC2A6BADB4ULL, 0x69FBCE96808F261EULL, 0x42DBC0B9D8C32558ULL, 
            0x97ACA18648790A9DULL, 0x9CA5321F5FB09F25ULL, 0xB918ADBFCBE89E59ULL, 0x2EC8D5B2714FA3FFULL, 
            0x4A82E40980341943ULL, 0xEEB5669D7F501243ULL, 0xB4B431537BBB2CE1ULL, 0x95BCFE281CAA95B2ULL
        },
        {
            0x92B51844163CBD49ULL, 0x7D670FD626411D2DULL, 0x4BF59B71B76C78EEULL, 0xDDDAA7B264C38045ULL, 
            0x83DCB8F84E4F0FF8ULL, 0x942EEF1BF7D55F44ULL, 0x0B9049813CEE3D25ULL, 0xCBC03D0B769AE6E1ULL, 
            0x8A1F89692BB8A613ULL, 0x57E8F81535B98B5AULL, 0x387AAE62E623AE83ULL, 0x63687DC19A17EF19ULL, 
            0x4D2B2DE1439BE640ULL, 0x083B9233AA9A2C52ULL, 0xC26E528CCA3CEC77ULL, 0xB66B80542C2A317AULL, 
            0x078868829D31E1E3ULL, 0xC67E4D21AAD0564DULL, 0xC689AD10EF6D0EBDULL, 0x6C86276F5F618D15ULL, 
            0x71252FCB4092703DULL, 0x97ABACDCDE76D5A1ULL, 0x7FA800C8DCF6DB3EULL, 0x1358EB3054C0C0E2ULL, 
            0x7BD5ED3B8F35AF42ULL, 0x2234C3F7A06DD3D3ULL, 0xDA227F9B60580A11ULL, 0x84443B8A95CC55C3ULL, 
            0x3ADE34D695E28822ULL, 0x4A2F9FA0E8F0B0ACULL, 0xC25BC9BCDA2C1479ULL, 0x7C1CA124890691F9ULL
        },
        {
            0x631FDD23383B43FDULL, 0xEC5A03620EAA6BB3ULL, 0x26B4C7DA25C76016ULL, 0x5F63FA3622312741ULL, 
            0xE837912DAF8186A9ULL, 0x2C71B1B141DB24DAULL, 0xECF8E73700E6502EULL, 0x94397F87C3A99A22ULL, 
            0x9B1BE98ED958E7F4ULL, 0x71D79A34BC6A49BDULL, 0xCCB3D6438821CE64ULL, 0x173A556CE3FBE5B2ULL, 
            0x7B0FD22E4FBDA444ULL, 0x59BB59C6BCEBA838ULL, 0xA934A3058ADB262FULL, 0x7D8B781C6651327CULL, 
            0xBD3DB19C5E49D8E1ULL, 0xAA4A5A6E7A22B65CULL, 0x6BB1E5F19852F8C9ULL, 0x1FBFE8720B2B53DFULL, 
            0x5EF33DA2FE1895C6ULL, 0x0774BCD1A815F0D7ULL, 0x168E0FB6711CBCAAULL, 0x31B50F62B0091265ULL, 
            0x1BDD9D14BCD3C5D3ULL, 0x66FBD900D5BC9EAAULL, 0xB4EF7556202C28FFULL, 0x99F9CC81CA60935AULL, 
            0xEE6521562A637C50ULL, 0xB8213544AACEC41EULL, 0x7411A63AA5C1814DULL, 0xBD215EDAEF9E3DA0ULL
        },
        {
            0x8055BCB1B783DCD7ULL, 0x45C9028DF0936C4CULL, 0x5BBB3D486EDD3D49ULL, 0x7DEE73AC5F460AA4ULL, 
            0xB81A6839B745F904ULL, 0xA104449D5FE15C36ULL, 0x0D8755A029C76B8EULL, 0x7C8E0C0C87415C68ULL, 
            0x98A8BA932DB24FF4ULL, 0xB83BF9A830622AE0ULL, 0x16B3F8B4009CB026ULL, 0xA150A2709C46F77CULL, 
            0x894EEECF69C08721ULL, 0x587D06F44A11B370ULL, 0x8925E33B9E2EC40BULL, 0xE803D5A3BF6DE0C6ULL, 
            0x7DEA8C4650C0829AULL, 0x496383C6DA643423ULL, 0xF124A1856EF36634ULL, 0xC44F8696BA2A2ADDULL, 
            0x8689535A4C30A384ULL, 0xE6CD1E6ADD69F937ULL, 0xF5827A4CCA26CD90ULL, 0x8E74C0CE3FED2CCAULL, 
            0x08815E0313370124ULL, 0xBA34F6C422956C53ULL, 0xFD8E9ED1B71A5F96ULL, 0x5A2C5C665A090643ULL, 
            0x62F9851D86325DBBULL, 0xE3D6AE1B4F1E52E1ULL, 0x906E6902D0B61315ULL, 0xD948818E5B0F298CULL
        }
    },
    {
        {
            0x054ABDCB1C11C566ULL, 0xC70689E32B59C8D9ULL, 0x1A119CA322100D80ULL, 0xC1FD8A731B583F33ULL, 
            0xF12246F6A6E70163ULL, 0xBFFC4D25D8409AD7ULL, 0x2E072AE3346E9F2DULL, 0x83552C89E87F8623ULL, 
            0x772A460B7EB9F246ULL, 0x3095E437D0182958ULL, 0x5EDA925F8FDC8B58ULL, 0xF481614D949C1084ULL, 
            0xB59E9B1FFAA3F627ULL, 0x38993EF3A99EAA10ULL, 0x95718D7E6407A8CAULL, 0x2C2129A4D28B93B5ULL, 
            0x762ECBCD3C1A0DDAULL, 0xE4024E49C84695ACULL, 0xF797D63B76E219A8ULL, 0x617678B385F02183ULL, 
            0x5C512504EAA7C850ULL, 0x8CF913F26CD2D410ULL, 0xDA2CF0AFBFE8D28EULL, 0x3CB896BA5455240EULL, 
            0x6F92AA36A3B08A9DULL, 0xF0F631DD6B9E3802ULL, 0x5F5C0B3FDA619310ULL, 0xCED2D66850D993CAULL, 
            0xDEDB9069F2387F80ULL, 0x77F9DC790272B0FFULL, 0xC2EAB2A825D4B84BULL, 0xB1780B5ABA9ACD1AULL
        },
        {
            0x1A62C0261164B1D3ULL, 0x6906526544D9878DULL, 0xD42D4F4EFBE032D7ULL, 0xDA333D5F416EB7BCULL, 
            0x340253D9A80AB156ULL, 0x5FFFAB80D0A636C6ULL, 0xEA69F548A8700FA9ULL, 0x47D60164307AF381ULL, 
            0x52D8E13C161F8895ULL, 0x7C99F5FC73346A02ULL, 0x047E16D6CACBAF9AULL, 0x46E53AACD185CD07ULL, 
            0x2AD019304DF8F61AULL, 0xE7B3E75E68CB4675ULL, 0xDE88166EA7D53E3CULL, 0x2ACCB9410C73F956ULL, 
            0x9679BE80CEE9B3BAULL, 0x2D59467E56DA229CULL, 0xE94BEDCCF696E1F6ULL, 0x2DBE2D526FC98D29ULL, 
            0x0F9FC266C9BA0971ULL, 0x6F395C79F7539464ULL, 0x8EAFA74324B5D8A5ULL, 0x2DD23C0B747040EAULL, 
            0x421AE5FECA9FFFECULL, 0x25B235D3FA69A973ULL, 0x6206CA0F98CA6098ULL, 0x2EA4C6C86FF4F187ULL, 
            0xAC6F9A31380EF458ULL, 0x6F47F5308A115A6DULL, 0xB86F03665BB9EDBCULL, 0x3EF23BAFDA110CFDULL
        },
        {
            0x28648ECDE9D3EE79ULL, 0x1C792A2A7830AF63ULL, 0x9063EED0385DD28EULL, 0x95E8977374C062A9ULL, 
            0x424E1F9F0A705BEEULL, 0x07742BCFA460C3C2ULL, 0x84C3D0E1520CAB05ULL, 0x42389468EBFD253DULL, 
            0xE729BBC76F646ABEULL, 0x4B4F65300F8256FEULL, 0x15957F8E32550740ULL, 0x2162C44E5B5E38D2ULL, 
            0x10C631577DDE7B8DULL, 0xE0E97CE909781C73ULL, 0xA6E5B01D56147C0EULL, 0x394401DB4096DB0AULL, 
            0xA2FE3DB2BB598CE9ULL, 0x697D57E47A26E19DULL, 0x4B72020F1432B7ACULL, 0xB261D4C112998B3BULL, 
            0xD7F4E345F1D0ABD1ULL, 0xB1911E31D99A16CCULL, 0xBC47E6BDB60261A3ULL, 0x3EB8CDE5B62B29D3ULL, 
            0xEBD7C01B009F612BULL, 0x8529A872EC6EAF6AULL, 0xB2A3F05D678E9758ULL, 0x9FED27410ADB0F08ULL, 
            0x51F4FFE70AAB7828ULL, 0x73C1B38244C6BF23ULL, 0x230CF3A9A34E21AFULL, 0xE5B571710CC5B40AULL
        },
        {
            0xB0AEBDBA16DF2A2DULL, 0x10B362A26F7D6029ULL, 0xBAA6E99CD2B34701ULL, 0x734D50EF75D5820EULL, 
            0xDFCC79E68E82D717ULL, 0xD61EE6EFB36A8665ULL, 0x95298F03242ED951ULL, 0x1AF60FB545C9FEC4ULL, 
            0xA7C0855F791BE2B7ULL, 0x87F176C715B50538ULL, 0x0F491C9B052CF199ULL, 0x13D54A1CB1D0DCDCULL, 
            0x07FCC87679B68303ULL, 0x5926D1FCD8E3D6CBULL, 0x5BD17B56DFECE0E3ULL, 0x652E7C440B8830A2ULL, 
            0x3B2F3A9C33AAAFF3ULL, 0x4AFE40A006A553B0ULL, 0xCDACB036B3A5A9D7ULL, 0x014483E346A1A13DULL, 
            0x020F5FB97D028BE7ULL, 0x9BE04BDE0D0F0285ULL, 0xB9251D7BF1993157ULL, 0x0B32B484791246A9ULL, 
            0x92630BAA2F41683BULL, 0xAE6D1CF5A10F0DB0ULL, 0x4404229F2934F4FDULL, 0x429120822272B8A0ULL, 
            0x60BF047F19043193ULL, 0x4031E3F82E00695AULL, 0x3936DA4934B2362FULL, 0x2222F40F868C8521ULL
        },
        {
            0x75431E43E3BFD681ULL, 0xFE7C80F17326B8CBULL, 0xCC13B57FDEB1AEF8ULL, 0x8D006D2FE998A9A9ULL, 
            0x3784ACD4D5B63FDEULL, 0x75AF3A589C41C1CCULL, 0xA3138D97844A1C3AULL, 0xD72D34D9765CA303ULL, 
            0xD7AEAE0C61BD2839ULL, 0x37DC3B12AC8678F1ULL, 0x3682E350DEC6D31AULL, 0x4727CB6A37ABEFE7ULL, 
            0xD3736A88016A6AA4ULL, 0xAD6B8E9A92AE7EBEULL, 0xEB25CC9A901F19B3ULL, 0x623FE0880EF4D8DAULL, 
            0x79D5291CA4BE1B11ULL, 0x9847E1205FA3C49DULL, 0x09BE2F9CEA83C7AFULL, 0xAE1CC728349CC8AAULL, 
            0xA48E1F5A16876EEAULL, 0x284B2BE493783752ULL, 0xE9454E4ED293116CULL, 0xE41E4B8C9E0384CAULL, 
            0x16FD8F9EE4EA37A4ULL, 0xCAEBBAAD1A22C59DULL, 0x520C29B99B291F84ULL, 0x6B02319A3972135AULL, 
            0x0F6B88E83E2A315BULL, 0xC22AB5C6366993FDULL, 0xF5D25B15B688F7A0ULL, 0x50C53B80C2410781ULL
        },
        {
            0x96FA5E411CB8428CULL, 0x4BADFFABC3413329ULL, 0x48A62D9F9C63D3C2ULL, 0x42B4082D73205366ULL, 
            0xE52EE34712DA2385ULL, 0xDE151CD6249EB6E6ULL, 0x9AA2FAC2DC69C724ULL, 0xC7310383211515DAULL, 
            0xBB54B3781C3204DDULL, 0x57897F98F9B90F58ULL, 0xF0EC23BEA31AE651ULL, 0xEB3CE355A4A8BD84ULL, 
            0x3FAFCF00142A72ADULL, 0x06DA32A3028568ECULL, 0x5E078FAC6D7D5421ULL, 0xA489D60C7C9F6211ULL, 
            0xBE40D15CCA5AB4CFULL, 0xE9E4E73E2D39C490ULL, 0x6FAE399DE1C75778ULL, 0xD0F32CC6FEBD1905ULL, 
            0x24A28AE7EAEDA1A1ULL, 0xD6CC18DE51112CF3ULL, 0x97E8862BB546F7ADULL, 0xFB422787BE89CC72ULL, 
            0x8C56D67FDE4443BCULL, 0x1626C4E89D5A6AFBULL, 0x839C7EB094F53206ULL, 0xCD8425D7EFD2DC8CULL, 
            0x6D4F1A961217B6B0ULL, 0xCF2545A3F11297FBULL, 0x8628CE8841880135ULL, 0xAA37490EB203FB6FULL
        }
    },
    {
        {
            0x9B6BF5AE25B791EDULL, 0x550D92F4BE386800ULL, 0x3CA02367DF3B49DCULL, 0x07651AA423A69A2CULL, 
            0x7B51AD8096E40C56ULL, 0x370BC03218C32735ULL, 0xDB3E817E93D3C3D8ULL, 0x4C0F12C1FC2B8658ULL, 
            0x6E250F8A8AF869BFULL, 0x8BC66171F7A04A41ULL, 0x69C9E772789C142DULL, 0xEC64057CA8A83475ULL, 
            0x18D3910AFFC02044ULL, 0x73E7DA09D26134C5ULL, 0x655E09B0C885A66DULL, 0x2D4DC5A4B4674AA4ULL, 
            0xF4910E53DA0CAAAFULL, 0x4F36F7E8E3E9FB41ULL, 0x442672936A8C3F66ULL, 0x5459FD9817AA1746ULL, 
            0x262560135059752FULL, 0x69A68441652DC176ULL, 0x206794F5757349F6ULL, 0x4C2AE05C2BE2CF1FULL, 
            0xA1A9CA05EB515268ULL, 0x4ABD401C872BDEE5ULL, 0x9DF98CA1C255ED99ULL, 0x51DA7154219DAD6EULL, 
            0x1F506329C1BB355BULL, 0x777334D5FC1F16DAULL, 0xBA9BEA35FF87F6AEULL, 0xC6E56CCC84460BC7ULL
        },
        {
            0xEAEE98397FB1EB92ULL, 0x8F43307650C49128ULL, 0x26384D371D773186ULL, 0x9F8CA2D0241B3070ULL, 
            0xE8961BB85F4E769BULL, 0x46CA349E93741557ULL, 0xE096CC72FD595FA2ULL, 0xB4B2538842E55AC2ULL, 
            0x314ED242A85E8A1BULL, 0x2805AD50938E46D6ULL, 0x4A64FB8BF3480217ULL, 0xDAA9EE7FD6E5F216ULL, 
            0x1FEFE76D21FDA20CULL, 0x0B1E0937DE1D070CULL, 0x72ACA163D2E5279FULL, 0xA9C599721BCBF9E0ULL, 
            0x7F89A02B9FB9A652ULL, 0x1806E195F2943D1DULL, 0xD61D23C5B24F1FBEULL, 0x68D3DF6476C1EE1EULL, 
            0xCBDDB14AAF6DDB45ULL, 0x8878130E2511DFD2ULL, 0xA3E4CAC0FF8E14BFULL, 0xFA030B847C529A78ULL, 
            0xF381E5C94A88D8D4ULL, 0x4B7D047398144E07ULL, 0x08BCA80142A97381ULL, 0xAF1380573458D9DBULL, 
            0xE364C160A4A79765ULL, 0x0792C0E50F250756ULL, 0x7CB34DF7E0EE01BEULL, 0xF9D68D5A43D807F7ULL
        },
        {
            0x6B8E361E8D61AE29ULL, 0x4DBF72E446DEE0FFULL, 0x5D44A333840C1466ULL, 0xBFBC990FF30B0B08ULL, 
            0x5513D71AA203C5CAULL, 0xD072BF5A5FC168CEULL, 0xF7D32EAACF5FB7B3ULL, 0xCB58EE637295257DULL, 
            0x5C15AF591B27585EULL, 0xAE55A023098D03A5ULL, 0xD9C88EC8A3802DDFULL, 0x1E0C54FF44A60B6BULL, 
            0x37F8A48C388BD153ULL, 0xBA454443076E4806ULL, 0xD1CD2EBFFF19DE29ULL, 0x20E18D2BF05229D1ULL, 
            0x9FFC5782DF8D6ECAULL, 0xCB7B16497C663047ULL, 0xDB7C5ED21035ECC2ULL, 0xD660B8C78F1D58F6ULL, 
            0x87CF5B541C5768EDULL, 0xB9475324EAEFA4F6ULL, 0x079EFB51F81D6F5FULL, 0xBD513C54D30AC895ULL, 
            0xB3C7CE6C20DFB636ULL, 0x2D91F254485EFB2FULL, 0xA262C9790B49F1AFULL, 0x7E73C2050FA224B2ULL, 
            0xD22270964F599DC6ULL, 0xAA06A8BD411C35E8ULL, 0x48534930EEA8A4F1ULL, 0x6F60A471CE05E3D3ULL
        },
        {
            0x2285897857D3ECB2ULL, 0xB38883500D6C8C7AULL, 0xE8A7792E5BD0212DULL, 0x99585F9F75B0DE51ULL, 
            0x36FA5BF9EF52B01AULL, 0xFEE15846E7FF46A7ULL, 0x01AD123536FFFD1CULL, 0x8A7C8B0AA51FC7DDULL, 
            0x077B8CB945D92FBDULL, 0xDF3DCF7D3F4AF2E0ULL, 0x3B9BF4B1960E40ADULL, 0xDE6A72F0BEC2A57EULL, 
            0xFF836AD7BD361FB3ULL, 0xA0936DA9DC5F0B6AULL, 0x3CF91EEFCB239546ULL, 0x6A8FE6CFC7A601A6ULL, 
            0x46173B3D2FB8A5A3ULL, 0xD52223B13640DC50ULL, 0x6DA49CC1781957B2ULL, 0xCD169A0A01B17E30ULL, 
            0x242DE356DFA5FB0BULL, 0x6E300B2123CB5A2EULL, 0xF978EE90F524921EULL, 0xC87E1F2E0A301CE6ULL, 
            0x25764A9AFD48DEFDULL, 0xF0BA45C444EA44CBULL, 0x1EE032F25E94B871ULL, 0xFB026F4C3A1E0E98ULL, 
            0xB0046A57CB31B3D1ULL, 0x1DD990F7705CBF15ULL, 0xD3502049E52531D6ULL, 0x90440000AF99F187ULL
        },
        {
            0x96A8FBD7F641A2B1ULL, 0xF48C340382D0955DULL, 0xA5E6AC776A4AB88EULL, 0x2434C957B2D4448BULL, 
            0x1D2E3B9E2F54FE74ULL, 0x97E5A72A8C48B825ULL, 0xDE9B427B7C542973ULL, 0x01EBF0A009D11EF5ULL, 
            0xABFE4F781EE17EE4ULL, 0xFD1113E916137D9BULL, 0xE0DB49C62206434FULL, 0x1CC11C39A6705935ULL, 
            0x3EAA37AF5C085AAEULL, 0x574D2E3AE958B1CEULL, 0xCE6B51A0491A37E5ULL, 0x8F07D025954259A8ULL, 
            0x2D6A578739BF11AAULL, 0xF4B53E750F635B41ULL, 0xDA2086B0215EC28AULL, 0x29B2A3757BEFE9CFULL, 
            0xC1CAD2AE9ED9855AULL, 0x837239E3EE6A5862ULL, 0x714106F19C56882CULL, 0x7032AC2D3F82C0D1ULL, 
            0x1EF770AB648BD97CULL, 0x39447A46E63BCBD5ULL, 0x600C83C34B48D18AULL, 0x164A13458FE7C557ULL, 
            0xB25246A88501CB13ULL, 0x06909DC155681873ULL, 0x41CAAEF5B3961104ULL, 0xBDC3B5A20766EA97ULL
        },
        {
            0x7F6D2663C675DA66ULL, 0xF34D17DBC8E41EA7ULL, 0x403556134229F205ULL, 0x6000DC710931791CULL, 
            0xF69A89AC14A8B42AULL, 0xA717E8335224AA25ULL, 0xB379DCF04C90AF0CULL, 0x64A397457CE091F9ULL, 
            0xECFF7FAC1A697691ULL, 0x2508923C8DA9058BULL, 0xB32D0ABDD0711897ULL, 0xCB5C6FBFD7A85869ULL, 
            0x364AF1C34F6277C7ULL, 0x660BD7594A0685CBULL, 0x5C1F515E1DABB76DULL, 0x08298A18F2557BBDULL, 
            0xC5C32F74D2459704ULL, 0x04231A4B32BBF4ABULL, 0x1ACD5B9A6EFEB491ULL, 0x7DD6F7F3BC6E85D2ULL, 
            0xBD7D5FA5371924C8ULL, 0x9A1E840129DA947EULL, 0xFB137CEF00F5AD72ULL, 0x9D72740BC25D03AAULL, 
            0x965339C588E51F21ULL, 0xA80A41F8D85EF134ULL, 0xACAEB9BDC202FDE4ULL, 0xBD5F24B1F1536E8BULL, 
            0xCCEE287F205A6C38ULL, 0xFC128D28B431A7FBULL, 0x66AF0FFA0AD65100ULL, 0x41007729FBA44A22ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseHConstants = {
    0x01ED731E2732D74CULL,
    0xB90E809493292D63ULL,
    0xA7C5CE09B757EC40ULL,
    0x01ED731E2732D74CULL,
    0xB90E809493292D63ULL,
    0xA7C5CE09B757EC40ULL,
    0x421F5A0E45415C19ULL,
    0xA21275E84E40CA08ULL,
    0x13,
    0x36,
    0x91,
    0xA3,
    0xB8,
    0x99,
    0xBF,
    0x3C
};

