#include "TwistExpander_Karate.hpp"
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

TwistExpander_Karate::TwistExpander_Karate()
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

void TwistExpander_Karate::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8EA1580D578A5375ULL; std::uint64_t aIngress = 0xB0A59FCD3AE270F1ULL; std::uint64_t aCarry = 0xF3DD6B36AD2DF036ULL;

    std::uint64_t aWandererA = 0xBA5E77D56AD52757ULL; std::uint64_t aWandererB = 0x867550479D2D92A9ULL; std::uint64_t aWandererC = 0x8315D3A0E7AB4693ULL; std::uint64_t aWandererD = 0xAD1C164B2F837501ULL;
    std::uint64_t aWandererE = 0x8FC2D7FDF0F48C49ULL; std::uint64_t aWandererF = 0x83B92CFFC9D6C498ULL; std::uint64_t aWandererG = 0xBE07D1F82680CBECULL; std::uint64_t aWandererH = 0xAD3AB8B25A21A85BULL;
    std::uint64_t aWandererI = 0xC81D26E77F9480F8ULL; std::uint64_t aWandererJ = 0x81E4C75D4AA133BAULL; std::uint64_t aWandererK = 0x9EEF6514AA61745AULL;

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
        aPrevious = 17253396721401803882U;
        aCarry = 17709256995028088726U;
        aWandererA = 15575427324814761109U;
        aWandererB = 16636730837158861765U;
        aWandererC = 12145537070960681235U;
        aWandererD = 9790902929870259117U;
        aWandererE = 18117040624328034826U;
        aWandererF = 10938843269217819182U;
        aWandererG = 17382826811503948498U;
        aWandererH = 17403390886517104980U;
        aWandererI = 17705771242117673391U;
        aWandererJ = 17795930515472465841U;
        aWandererK = 13551552090075279855U;
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
    TwistExpander_Karate_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Karate::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x971AAF7EDED3092AULL; std::uint64_t aIngress = 0xAE445B69306E87FFULL; std::uint64_t aCarry = 0x9263E00912033235ULL;

    std::uint64_t aWandererA = 0x82E3EE4740874E50ULL; std::uint64_t aWandererB = 0xFDB7B5DA286B9925ULL; std::uint64_t aWandererC = 0xDB06785A478F97B1ULL; std::uint64_t aWandererD = 0xBC9DA6056486EEB4ULL;
    std::uint64_t aWandererE = 0x9F98C3A7DD5DB461ULL; std::uint64_t aWandererF = 0xC3C63201D44F6A65ULL; std::uint64_t aWandererG = 0xE9DD973786096E8DULL; std::uint64_t aWandererH = 0xCC254651D37CFECAULL;
    std::uint64_t aWandererI = 0x9CAB4DA0D0EB0F50ULL; std::uint64_t aWandererJ = 0xB4B74F3550A96ED7ULL; std::uint64_t aWandererK = 0xD5FBCE5290F36CC4ULL;

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
        aPrevious = 16968263117633469437U;
        aCarry = 10340939167766493384U;
        aWandererA = 12197973689156803163U;
        aWandererB = 10722880525261099709U;
        aWandererC = 11850461035418787688U;
        aWandererD = 14669094023327290461U;
        aWandererE = 16269915400357527879U;
        aWandererF = 15849280415388964545U;
        aWandererG = 14958482341365242518U;
        aWandererH = 16545548428018708226U;
        aWandererI = 10137969388655489940U;
        aWandererJ = 12467252894467228361U;
        aWandererK = 14605867889382093894U;
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
    TwistExpander_Karate_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Karate::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9DFEE22CFA31A149ULL;
    std::uint64_t aIngress = 0xB28E8C582059C2EDULL;
    std::uint64_t aCarry = 0xF98E1491B4892CB7ULL;

    std::uint64_t aWandererA = 0xEBBB4558497F91A9ULL;
    std::uint64_t aWandererB = 0xF918B7EF3CC78C85ULL;
    std::uint64_t aWandererC = 0xD5F64E4AA8E93F2CULL;
    std::uint64_t aWandererD = 0xA060916758AB47C4ULL;
    std::uint64_t aWandererE = 0xF790C045ACDBB9C2ULL;
    std::uint64_t aWandererF = 0x86F96159853EDE88ULL;
    std::uint64_t aWandererG = 0xDB97373A21F419B7ULL;
    std::uint64_t aWandererH = 0xADE5474B1F09D806ULL;
    std::uint64_t aWandererI = 0xDF09726E20F48870ULL;
    std::uint64_t aWandererJ = 0x8B7DAF7E17C0D5C7ULL;
    std::uint64_t aWandererK = 0xC6E27870D47C7EB9ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneB);
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Karate_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Karate_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Karate::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Karate::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE98B7AFC14C87EA9ULL; std::uint64_t aIngress = 0xFA0B7D7D5EE41226ULL; std::uint64_t aCarry = 0xAFB05F16D034F011ULL;

    std::uint64_t aWandererA = 0x891F2893AB36F18AULL; std::uint64_t aWandererB = 0xEE07E53252789DD7ULL; std::uint64_t aWandererC = 0x84D07561C222FFF6ULL; std::uint64_t aWandererD = 0xFE7C5549BC2A799BULL;
    std::uint64_t aWandererE = 0x92D215DA9CA594F3ULL; std::uint64_t aWandererF = 0xB31D0A9ACF85F5C5ULL; std::uint64_t aWandererG = 0xDDF7C6A3C4E0F9B0ULL; std::uint64_t aWandererH = 0x8C1A2F7633B9FB7DULL;
    std::uint64_t aWandererI = 0xF3F7FE3848ED22ACULL; std::uint64_t aWandererJ = 0x87A6FB5EAA4D636FULL; std::uint64_t aWandererK = 0xA3D157E92A6A693CULL;

    // [seed]
    {
        aPrevious = 16044949348745091936U;
        aCarry = 10063453217658222210U;
        aWandererA = 12903714335147140592U;
        aWandererB = 13786300444746777321U;
        aWandererC = 13619989368084322880U;
        aWandererD = 10650184954501459854U;
        aWandererE = 16485241576887855249U;
        aWandererF = 11370894199501975811U;
        aWandererG = 10551764170600393617U;
        aWandererH = 11465776241018425163U;
        aWandererI = 16438116054934716560U;
        aWandererJ = 12607535572759829781U;
        aWandererK = 13069239577508724520U;
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
    TwistExpander_Karate_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Karate_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Karate_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Karate::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 2 with offsets 4917U, 5036U, 7014U, 1092U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4917U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5036U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7014U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1092U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 3 with offsets 4852U, 3525U, 3779U, 7366U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4852U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3525U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3779U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7366U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 0 with offsets 1417U, 5408U, 7107U, 5011U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1417U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5408U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7107U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5011U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 1 with offsets 7575U, 1462U, 4789U, 6423U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7575U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1462U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4789U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6423U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 1619U, 1568U, 1922U, 371U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1619U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1568U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1922U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 371U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 2, 0 with offsets 1324U, 407U, 873U, 711U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1324U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 407U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 873U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 711U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 2, 0 with offsets 382U, 1133U, 635U, 371U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 382U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1133U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 635U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 371U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 1, 0 with offsets 491U, 635U, 727U, 1931U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 491U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 635U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 727U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1931U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1134U, 771U, 1187U, 1048U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1134U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 771U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1187U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1048U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Karate::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 2828U, 6506U, 6214U, 2306U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2828U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6506U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6214U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2306U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 0 with offsets 7232U, 4448U, 2612U, 6230U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7232U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4448U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2612U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6230U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 1 with offsets 7060U, 1679U, 1398U, 802U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7060U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1679U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1398U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 802U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 0, 3 with offsets 30U, 7917U, 4238U, 6480U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 30U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7917U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4238U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6480U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4532U, 6055U, 7980U, 6971U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4532U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6055U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7980U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6971U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1426U, 669U, 1335U, 502U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1426U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 669U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1335U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 502U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1651U, 1725U, 1238U, 797U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1651U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1725U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1238U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 797U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1661U, 1517U, 925U, 978U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1661U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1517U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 978U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1465U, 1417U, 434U, 1663U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1417U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 434U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1663U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 907U, 1458U, 299U, 1645U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 907U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1458U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 299U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Karate::kPhaseASalts = {
    {
        {
            0xFD8F831A30D196C9ULL, 0x292DC8A48AE2FFCDULL, 0x070F4259DB04DD2AULL, 0x9DFA53400DBCAC31ULL, 
            0x0849D20863211863ULL, 0x69CB9A9382FB78A9ULL, 0x21825397FE8761F4ULL, 0xE7E98C7CEBCA7E01ULL, 
            0x951D69146E680348ULL, 0x5B59F5EFDE42EC52ULL, 0x7B0EA94F8D3F5B35ULL, 0x168745BBC52F69AFULL, 
            0xF092D31C2646E62BULL, 0xE7F41EEB7A681901ULL, 0xBE9D180548B195CCULL, 0xF653790D9B158AE9ULL, 
            0xEE51BD81E06D2BCFULL, 0xDBA658F9696CD075ULL, 0xFB00895C6B278256ULL, 0xC03082233B5F78F8ULL, 
            0xD0323D542879D492ULL, 0x0E6EB9E5CFAE8645ULL, 0x06B9EB483D88BDAFULL, 0x782727BCC764C60DULL, 
            0x5CC7D2BF679926A9ULL, 0xD1872A27C593A7CEULL, 0x6AF447A9C07B4551ULL, 0xB5075F816494E3D0ULL, 
            0x409A6FE4FF586C2AULL, 0xCECF19FF67EE09F1ULL, 0x782308FA6F1752CCULL, 0x16B465BAF001EF19ULL
        },
        {
            0x1DA843208BEF0B01ULL, 0x7165AC07DD048212ULL, 0x6EA937CE8CD42C33ULL, 0x15712AB0957F794DULL, 
            0x911250019C22AB15ULL, 0x64DF4126EB779808ULL, 0x87A6F0C5231F2270ULL, 0xF333475308366288ULL, 
            0xB671B961D1464CB0ULL, 0x25B7BB8528255BD2ULL, 0x844B32E5B9C200D8ULL, 0x5F8DB11081BEEB81ULL, 
            0x0ACB1949CC0D7564ULL, 0x71BB8DBBDC4CA39CULL, 0xB7995958C2E7801FULL, 0x61C98F2837916A39ULL, 
            0xF8DE74596AEE245FULL, 0x1B8383E88029FBBBULL, 0xE46E8ACCF5780D25ULL, 0x6EAB5AEC516F26A2ULL, 
            0xC5A949906A5343BEULL, 0xEBA4A7A0ECC40531ULL, 0x5755A27B4160CCCBULL, 0x197FCFF2DE2D8980ULL, 
            0xE55B374C17A1D3CAULL, 0xC9E364FD8D7C1D74ULL, 0x43433ADB88DF8E8FULL, 0x96E030E581B288B6ULL, 
            0x8EA5A5C5CF07323EULL, 0x51472AF0F557FFB2ULL, 0xC1BAA83A85CA5CAEULL, 0x67606C6EA35C8D23ULL
        },
        {
            0x4AA9F54E92304CAFULL, 0x56851039CA8465DFULL, 0x6753F798BD7552A3ULL, 0x94B1B753E3ACBEA5ULL, 
            0xE933C1A5F04E878BULL, 0x0CE68D1A951186D5ULL, 0x9F079C579836C890ULL, 0x6F9C06A1C40F8DA1ULL, 
            0x37624274672A642BULL, 0x5AA19EB57304A470ULL, 0xDCC95879C8BF929FULL, 0xD1C74BA688594650ULL, 
            0x71C75CFF4A9F45A4ULL, 0x4EFC66B0F1076871ULL, 0x3C7EF742500E76FEULL, 0xE16A1CF7A55EB037ULL, 
            0x9F0686AB9F445719ULL, 0xDADE86CC1E994735ULL, 0xE3D6CBA42488FE4DULL, 0xC47C9ACDBA79163FULL, 
            0x5E508691CFAE0AC7ULL, 0xCE4B8FB5966DCC84ULL, 0xCC1AE40BF709EF43ULL, 0x18EC30E557AE39D4ULL, 
            0xD139420AC9F8DED6ULL, 0x6BB582644354FB73ULL, 0xCB3B114B89C90116ULL, 0x943FA7E8608E0A8FULL, 
            0x694FB664B2537658ULL, 0x50CD2445696C9605ULL, 0x7C4261E7ACB2FAD3ULL, 0x42A2B20A3F7A2D90ULL
        },
        {
            0xF89AEDC859E102DEULL, 0xA0B83AC440EC5237ULL, 0x938E34C6BAB24770ULL, 0x794176CB47CE3C95ULL, 
            0xB88B2FE1ED33DD3BULL, 0x59AF3BE95A16C5DFULL, 0x87BA10F24D20A0F8ULL, 0x07ACE8768B238E66ULL, 
            0x934C21A9F423F01BULL, 0x530BDA58849F25AFULL, 0x6DD323D19CEE8EBCULL, 0x2228880F4C3DDF3FULL, 
            0x0FCB8654971ACBCBULL, 0x98A2A246C01153E0ULL, 0xB8D3A9FC251671FBULL, 0x3829712B53CD3149ULL, 
            0xF911DCC481386723ULL, 0x30F352B7747957D6ULL, 0x2056F9950FD8BEBCULL, 0xFDF54148B6A478C5ULL, 
            0x1FA984CD733093D5ULL, 0x9B3F64D67A188046ULL, 0x0060FD3499A7D6BAULL, 0xD6C68D867BCED6FCULL, 
            0x0C8F306341A91F38ULL, 0x56CE29E70F12B395ULL, 0x6DAEA0A972A968C4ULL, 0x010F7D020642F89FULL, 
            0x574B919CCB88533CULL, 0x6C36A9E3156AAA92ULL, 0x7C9AB5BFB7C1F1C4ULL, 0x258FFBC3096B9699ULL
        },
        {
            0x1C3509B0991838B0ULL, 0xD37C8CF1F4F9152FULL, 0x6009E242C5A605E2ULL, 0x08E6F205041B2D4DULL, 
            0xC4778F46B607B6FBULL, 0xD7FFC7317016696FULL, 0x59CAF8DAFB70B111ULL, 0x42BFEEC73BA5E552ULL, 
            0xAB48C26E3AAB6DB1ULL, 0xDE30D0825D8156D4ULL, 0x79854EC61DAFDDDBULL, 0x309E09F1C66BA729ULL, 
            0xC831A85E8FA703E5ULL, 0x56AC513A46CC2927ULL, 0xD93BD3598B4DF078ULL, 0x0DC8E840A64035C5ULL, 
            0x4B238B5917A7A593ULL, 0xA9007B592130F128ULL, 0x67710B62FC95989BULL, 0x7B7FD40AC59ABDB1ULL, 
            0x7BCC130DCA66B13DULL, 0xC475CEF1EF5D6F14ULL, 0x95CA1C07A591F6D6ULL, 0x34EA85C6F55027B6ULL, 
            0x7B0E537E9B151C53ULL, 0x91C7301CC20EACCCULL, 0x6138ADCD4D822DF1ULL, 0xDABD724C1E97552EULL, 
            0x43584482768CFC1EULL, 0x90B817B20028055FULL, 0x29AD983821B38E3BULL, 0x42666298DB045107ULL
        },
        {
            0x5F19DBFE947CFF32ULL, 0x706D24E2FFF20A52ULL, 0x70096409F49552B7ULL, 0x7839F465599BD431ULL, 
            0x6175A1177252CEA4ULL, 0x52BE49B811D1B924ULL, 0x4FC27E2E1CB79C93ULL, 0x85E83ECB7CF74933ULL, 
            0x4176CE741E514642ULL, 0x9B2018B205DE0DE9ULL, 0xF01F9983DA715958ULL, 0x7156565FC2D5B6D4ULL, 
            0xD95FD91D190E4C20ULL, 0x066A1E4F33CA42E5ULL, 0x6D4EFEA31C1CA048ULL, 0x66FE30EB433FB195ULL, 
            0x43D32B6796AF7CB5ULL, 0x23798D816AA7E7EAULL, 0xB2138D18E9F7F8EEULL, 0x82F2A53298B8E677ULL, 
            0xBBFA46B74A4B6706ULL, 0x3D84066B3E0E6285ULL, 0x599DF9C710F103F6ULL, 0x054FF4230CB1FB0BULL, 
            0xB515D9C56BDB3A46ULL, 0x75BB9C401B1F5AA9ULL, 0x7BBEE13CF75921AEULL, 0x8E00E8E661E0972CULL, 
            0xC322CD9B0FB6A9FFULL, 0x8BAA3722B8C4F400ULL, 0x78E266430AF71076ULL, 0x7305CCB477B9391BULL
        }
    },
    {
        {
            0xDA2FDE863AB2545EULL, 0x6C97CBAC3659A8C6ULL, 0x212ED22147FA0218ULL, 0xC16C32C642B28F0CULL, 
            0x1349614273DE2948ULL, 0x594064937994967AULL, 0xEC5749FC92971800ULL, 0x354D61EA8F413AD7ULL, 
            0xB846D8FF074C06A0ULL, 0x5A0D7EE530DD67C4ULL, 0xE7CEE2AAB1CF9DE6ULL, 0x95A9BEDF439758B4ULL, 
            0xEFF174A56268AF9DULL, 0x9A847B8D22F48353ULL, 0x862984E9996CA3ECULL, 0xDCD05AD11B522A44ULL, 
            0xDFC039F646252E33ULL, 0xB2E08DE57B49742CULL, 0x1D665822906957F7ULL, 0x331496B673FF5F99ULL, 
            0xD77019AB42110658ULL, 0x6D4ABA31349253D9ULL, 0x1603C47230244C79ULL, 0xC7E0578A2922CE16ULL, 
            0x029C0A9D90BD9755ULL, 0x0E19E6E96377AC12ULL, 0xB532C4474B2A74A0ULL, 0x1DEFFC66FE847025ULL, 
            0xC5470C376A203F9CULL, 0x621DDB4E72E08585ULL, 0xDFF37AC2DEEF95EEULL, 0x6BD991BE95A14D82ULL
        },
        {
            0xFD4668A458121748ULL, 0xF7638434B79F5D8BULL, 0x19CA41FB02FD20A6ULL, 0xDA58117725781948ULL, 
            0xE740F0E4ED36F659ULL, 0x52ED086449B1F448ULL, 0x78DF074E4EAF7875ULL, 0x83436361BF8AA1EBULL, 
            0xC4B193537FA135C4ULL, 0xBCCC6D16E03BAE75ULL, 0x0B43C23F54F0B530ULL, 0x96D7FC6DFA9C5566ULL, 
            0xFD5D943E14827140ULL, 0x7DC2EBDEEFD1D125ULL, 0x6E8DD9D3C23C9BFFULL, 0xFA0F9CD61F12E250ULL, 
            0xDCB85A0AEAFFB3BDULL, 0x304FB7C6F9FEB1BDULL, 0x828E367A89F707CBULL, 0x025E074B263DF86FULL, 
            0xC1B412A51AA21A52ULL, 0x48B341E055844DB0ULL, 0x480180CD42100877ULL, 0x170BE67C39258C7CULL, 
            0x13245805E9BB9126ULL, 0xB4D13620983C9E97ULL, 0xCD0E63E56BFCB499ULL, 0xBAA1BF069944C8CDULL, 
            0x3A0F230FB6B6257CULL, 0xB6C40A9192946059ULL, 0xECF3AC329FF5FD95ULL, 0x768A6828BFD2F462ULL
        },
        {
            0x5B98AC084E304368ULL, 0xE4E0194EF6C5DBB3ULL, 0x17EFD5FB07D6EE9EULL, 0x8F7909AE6EC092E4ULL, 
            0x2F2BEF4AE4F95733ULL, 0xBDAC8DB7864D8738ULL, 0x33F469D5D4393EB9ULL, 0xD0ACE0225B50F481ULL, 
            0x49DB77161593B674ULL, 0xE97D6FB85E502F6FULL, 0x1F76C0C147185303ULL, 0xB367A922DA81419DULL, 
            0xB51D27CB66B4253EULL, 0x7E34CD6082EE4CF2ULL, 0xE305FEA7BB396193ULL, 0x52C0DA63932DDFCFULL, 
            0x09C1653E4A769BA8ULL, 0x89AA5A3E229E3603ULL, 0x0F0A716CBCB8237EULL, 0x7B0F815F0F919AF7ULL, 
            0x1F83723D4A9297FAULL, 0x12820E284F137968ULL, 0x96308DEEE44CD9FDULL, 0xEE9D38352F04940FULL, 
            0x8542C64FBDCB637BULL, 0x7125CCE6208C7E70ULL, 0x7ECF5BEF8CB3B383ULL, 0xBA3D03BACE6EDB12ULL, 
            0x19EB5A19A89178D7ULL, 0x4436666CC899B039ULL, 0x6D17EEFA949CA598ULL, 0xBFA6E35CCD38E1A6ULL
        },
        {
            0xBB33AD92FBA7B66CULL, 0x8755FF7E03596C97ULL, 0x97E95B122ACF4998ULL, 0xB144BA4D263642C6ULL, 
            0x546F6B1D89015348ULL, 0xA8DEF211155818E4ULL, 0x4348151585DA3B55ULL, 0x063067964AAEDECDULL, 
            0x717D07CC9ACA05AFULL, 0x3AE1C54A28FD2E48ULL, 0xB679A7DF62A44E8BULL, 0x6A8364A39EB4CCE4ULL, 
            0x988C4B579D180942ULL, 0x5251BA26723DB99CULL, 0xEFBE2231B076E839ULL, 0xCEDDF046838B905AULL, 
            0xD3636DFC1EDCF0C9ULL, 0xE50BE513F5D35A79ULL, 0x6FD8275283B8FA40ULL, 0xB30C4CE03A338C59ULL, 
            0x5A2B97165A161F5FULL, 0x34DF602C9DC48C3CULL, 0xCFD1FE1DBD15174CULL, 0x0D968F2E585CD00DULL, 
            0x035DC9C80A10B7FAULL, 0x23955A269353F582ULL, 0x2FA4607058E47FC4ULL, 0xD03147EF96F55A06ULL, 
            0xE5955C81BC63DEF4ULL, 0xF251AF424C86E8D9ULL, 0xE9EBEF77816B5DD6ULL, 0x977895E78C521F3AULL
        },
        {
            0x19281592F079AB25ULL, 0xE98A222B7808440BULL, 0xA4AEEB24468B29D3ULL, 0x9517B7A3CD5026C1ULL, 
            0x5440DB8E2C91CE57ULL, 0x7A31046D1356CB9BULL, 0x7F384E86912FED88ULL, 0x556ECB3B6FCBD60FULL, 
            0x509C6102F937E8DEULL, 0xD65B70E535F4375AULL, 0x5574B854F5111A40ULL, 0x537B635F82C8D48FULL, 
            0x648F07F920452CCBULL, 0xBC96DEE0C02358BBULL, 0xB5A8DF68739145CEULL, 0x527F89AA093EDB21ULL, 
            0xCFB0377DCF7815E2ULL, 0x5649BE5D8034BF7BULL, 0x81D29D55A2D4387FULL, 0xB82B9AD36DDBA357ULL, 
            0xE381582C866101C0ULL, 0xC3B2999CBAB77B4FULL, 0x9F39A1056E4EFA00ULL, 0x000D83A2A73A753AULL, 
            0xBAF2CED83A46F963ULL, 0x18DD5E798C53998BULL, 0xF82B560C9D9AAF2DULL, 0xA1F8CD6AE84B37BFULL, 
            0x1D5B0F113A46D9B5ULL, 0x3722BD66D9365DD4ULL, 0x805C6B71B63B8DE5ULL, 0x9498686703BE2826ULL
        },
        {
            0x6099C87FDC526393ULL, 0x87FA61FD19C1F346ULL, 0x8346CA181CF8D8A4ULL, 0x3F937D023BEF22EFULL, 
            0x26E47DD8146357C0ULL, 0xADB5ACEE8F9F1FB3ULL, 0xDD2075A2B8C9C761ULL, 0x0A55641988366F1FULL, 
            0x55455938C1C884D3ULL, 0xD77354EC5E259ED8ULL, 0xBEC0C44F50765590ULL, 0xF7F56120D5880EA1ULL, 
            0x695DD404565D51EAULL, 0x392FB069B2899E3DULL, 0xB7CA42EC21AEEC69ULL, 0x2BAFF3D1D95D69B6ULL, 
            0x78E36DFD0D69A28CULL, 0xE3AC4D7B6B4784BEULL, 0xE7EBA74A9FE32FB7ULL, 0xC7B61A10CA598D5BULL, 
            0xD1CD6086C4A7FAC9ULL, 0xEFCCDB578825A10DULL, 0x6D088251571F5533ULL, 0x242EC4C3021D4462ULL, 
            0x75E1F81B88C56273ULL, 0x01B4522A1F40E100ULL, 0x8A92A4D83176C853ULL, 0x8259184F5359B59BULL, 
            0x4FAB0ED9992255CCULL, 0x1300FEAD3D73E669ULL, 0x92072B1621A8F189ULL, 0x4EFBC0E09B7B517FULL
        }
    },
    {
        {
            0x57BEDA1AF0A8AF2EULL, 0x84D0FD21068DE026ULL, 0xD1823CB921CE1048ULL, 0x3665C1A67CA8B493ULL, 
            0x33043941FC335703ULL, 0x2BDD7B570F5143C7ULL, 0x6A55391DF0DA1FD0ULL, 0x3DAD4704BA77793FULL, 
            0xCC794558941095D3ULL, 0x65898DCD4B3A4FC9ULL, 0x9DA5F2070B6EE639ULL, 0x77CB257558350B7CULL, 
            0x9BBA0763E5013D1DULL, 0xDF78D77491B302DCULL, 0x73B11C7BB26AFA7BULL, 0x3D06694C633F8FF9ULL, 
            0x198D95E4CC90865DULL, 0x964E2EC7E406D70BULL, 0xAF01535CAB84F027ULL, 0xB8B232545FFF3577ULL, 
            0x9A265D5BCD6DA769ULL, 0x22C6F5D8E1671F09ULL, 0x66B3F2C0527A8F09ULL, 0xF047C211D0017C1CULL, 
            0xF1B7911B8449573FULL, 0xEBB9245839B0B0F2ULL, 0x05807E089505CF44ULL, 0xAC27ED314E89B695ULL, 
            0xD4395D8C53236DFEULL, 0xD89337A967685952ULL, 0x9C6B62F8B9AE2BF1ULL, 0x71C58A5555978578ULL
        },
        {
            0x54E33F18C32F2978ULL, 0x80AC7F3205DE2094ULL, 0x286A8D051354A7F1ULL, 0xB8CF81B5CB4F6782ULL, 
            0x9F74F89D1F2D18A2ULL, 0xF70743A39E78E50AULL, 0x8F971C15AAEF8C83ULL, 0x0492976F19FAB7A5ULL, 
            0x5FA4687EDC6EE27EULL, 0x9AE34C20B1FFCBCDULL, 0x5C9FDBE17ABC928BULL, 0x94FCBE98BE144BE5ULL, 
            0xB4B9C24A7368B934ULL, 0x04B6EB5505D8A266ULL, 0xA3D37BE89CA5E9BBULL, 0x0F9C86B2884BD8EEULL, 
            0x24A78F3C882138CDULL, 0xAC4272ABEE7F1A81ULL, 0x66A76034212E4859ULL, 0x44316E73151990C1ULL, 
            0xAC15F2C95C2DB80FULL, 0x2721716FC3E5FE5FULL, 0xAE6C58C33456D00EULL, 0x57621693455BFBB9ULL, 
            0x0963E64A8ECA7D29ULL, 0x6604C5770AA3822EULL, 0x089012BB967F8428ULL, 0x0A02AE0078D5C280ULL, 
            0xD206F2C5E951A85FULL, 0x47C3FD200AB76645ULL, 0x100B438DB315C4B6ULL, 0x0A1AEB9947E1C4BBULL
        },
        {
            0x2E8A1CA87EB7EB8BULL, 0xD499AE231792BE63ULL, 0x18DBC1E5CFAA21C4ULL, 0x7BB34E4D2862FBD5ULL, 
            0x4A9B9FBADEE340C3ULL, 0x3A64454FE80045A9ULL, 0xAE1A13396C25B291ULL, 0x00A03AA7C7CDBCF7ULL, 
            0x8407D254357DE00CULL, 0x5584549FCF2E6B60ULL, 0xDDAF616C7C61F1E5ULL, 0x18B0732233889EC7ULL, 
            0x2F4D960CD94EEBC4ULL, 0x5C35691EB251AC3FULL, 0x9BFE255615635B58ULL, 0xDA3CF7CA902E1021ULL, 
            0xEE5ADCD50E8F54EFULL, 0xB64DF32CB8012921ULL, 0x4B617B7446686A3DULL, 0x6EECB81A05C0959DULL, 
            0x2A356A838C637C8BULL, 0xBEBBB5BB5410AC51ULL, 0x5D2EB11176A351CFULL, 0xDE1C9234D2F1AD82ULL, 
            0x6F5BF01578C0C8B4ULL, 0x3E38812B93428DCEULL, 0xB8715FAB1190C25DULL, 0xA84BB48CC7367DEAULL, 
            0xB041D21E93C77100ULL, 0xE371A17E70EF5620ULL, 0x9F7267FB8DB7231BULL, 0xB69083B5F9D32DC3ULL
        },
        {
            0xCF715435CD91285AULL, 0x375613B25F859F8AULL, 0xC89A2557B7F49915ULL, 0xFA82EB2B0C59A74BULL, 
            0x3737F289BC9F3457ULL, 0xF3D6602E0DBFAC1CULL, 0xBBA4BBF315BD98D7ULL, 0xEB522A1F4B7BD8E6ULL, 
            0xF4958FDDE4D79F57ULL, 0x1A9F23E22C46EACDULL, 0xE625F361908AF2D3ULL, 0x49C961A0CCC1A229ULL, 
            0xC820BCAF37E15100ULL, 0x7CF4A6683026EC22ULL, 0x236A6CE23A00818DULL, 0xAC215AB1C62A79F2ULL, 
            0x4670B55AFB2EB17EULL, 0x3D0F12BF26908307ULL, 0x90E4609BFB0222E3ULL, 0xC304FACA2DE87A48ULL, 
            0x5F7969A11AAF5899ULL, 0xDD3DA0AC656461A1ULL, 0x03200A2DC8516661ULL, 0x6C93C4808A3687E9ULL, 
            0xE760ADECA9CD5A07ULL, 0xF8857ED616BAE9DAULL, 0x043780A92D309F61ULL, 0xB32DF1D89727989CULL, 
            0x97C09916988E3CE2ULL, 0x1CE7353DD9B7AB71ULL, 0x8F6AA7244633E111ULL, 0x5F7C44CD498D6428ULL
        },
        {
            0xFE0DD5BB7BBA92BBULL, 0x7F3DFCF8062B0172ULL, 0xCABB2E021B7D1AF6ULL, 0x1110429751D843C0ULL, 
            0x1F17667F0D724D74ULL, 0x5528BA1D28486C1EULL, 0xE9F8FEB09B775523ULL, 0xB8CEC5F929196F24ULL, 
            0x756ACAD4C6C71840ULL, 0xA496D01A038C17D2ULL, 0x2A134B1369DE5EB1ULL, 0xD918115A015A4A5AULL, 
            0x0B01F99A7AB528EDULL, 0xA89235965F3FA809ULL, 0x568C34D868AEC68BULL, 0x8068F7FCE89C6B62ULL, 
            0xF0B7D0520FA5A6C4ULL, 0x9D5B555A9012576CULL, 0xE783A40543FD48CAULL, 0xAB81DA1EF9B35047ULL, 
            0x96F470709F8DAAE7ULL, 0x8F730532D77420A5ULL, 0x6764E40EEC146EF4ULL, 0x22E0EFCEAB619D2CULL, 
            0xF02AB3FD51BDD188ULL, 0x389336C5DC79E471ULL, 0x801F9C8C9D828445ULL, 0xAFF36B364B1B5E79ULL, 
            0xEFE05723EF0A710BULL, 0x50E7CD3D33ADD282ULL, 0x9D9A57F63F40AC93ULL, 0xACDAD204AFF68A0FULL
        },
        {
            0xEF92F65F3800E787ULL, 0x65FFB2DE96CDBDAFULL, 0xCAD416D943DAC0A0ULL, 0x0D4A3E3F1EF8621CULL, 
            0xA1556EB04BCBEC96ULL, 0x76D945CFF425A8B7ULL, 0x9B5BA3B075A75225ULL, 0x27E32751D717C517ULL, 
            0x716A849B0F480928ULL, 0x0A01C3EA5F566E57ULL, 0x25C0475F157D651CULL, 0x86EF73741A1BF7C0ULL, 
            0x13A37954597732F0ULL, 0xC55B5A840242B1A7ULL, 0x4C91063F6E9CD0B9ULL, 0xB64FC64698ED7FB8ULL, 
            0xF2D2A4691264776BULL, 0xBA1418FDD1D8607FULL, 0xD493072FC776AA87ULL, 0x360AB656723B77B5ULL, 
            0xC796E199386B4873ULL, 0x21EC82747EB66ED4ULL, 0x08402B650A60C861ULL, 0x193AEBC79EBE5E65ULL, 
            0x47EC26F4ECA5A651ULL, 0xD1A8504346D70C50ULL, 0xA32866176931DB7AULL, 0x0FBAA1B3EB5EE5BCULL, 
            0xCA5FF56D86D8A66EULL, 0xDF3102A11A6683F9ULL, 0xADAF2B2A16AB1C32ULL, 0x6C0D0A2CAE5785AAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseAConstants = {
    0x808E8B45764DF3A8ULL,
    0xB1D59A7A15080F46ULL,
    0xD356E09FB497D9D4ULL,
    0x808E8B45764DF3A8ULL,
    0xB1D59A7A15080F46ULL,
    0xD356E09FB497D9D4ULL,
    0xC9C3163D18FD4429ULL,
    0xBB836F16756EF356ULL,
    0x85,
    0x9F,
    0xFE,
    0x96,
    0x64,
    0xD2,
    0x6E,
    0x6C
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseBSalts = {
    {
        {
            0x9C1CBB5A6F7B189EULL, 0x5F6E68F50AF3C83DULL, 0x62048DB6D27E3F4FULL, 0xD0510F52CB47BF32ULL, 
            0xFC7FAB12B02CEE74ULL, 0x244795209A0B390FULL, 0x484DE97A531F88D1ULL, 0x105A7DA5B41B9D1AULL, 
            0x0DAF33D836C21410ULL, 0x2A065AD8DDB4D6DFULL, 0xCE9A3F21BCAA6398ULL, 0xBDA75B9B4147DAD4ULL, 
            0x4FF857BCBD444B90ULL, 0x4A3D2B2C07455A64ULL, 0x57ED6DE5532A3838ULL, 0xD4B85EEAB4A5D0EAULL, 
            0x9FA61B5111892F68ULL, 0x4D2D442063E04031ULL, 0x007AE6EEA0299234ULL, 0x9D2E15076A889BC0ULL, 
            0x371EC416D2224075ULL, 0x1A611181F287174CULL, 0xEE44BFBAF66BE120ULL, 0x81C34EE30F35F83EULL, 
            0x22077934FCBA15CDULL, 0x8E4046EB9BB73907ULL, 0x58D57BCEEE182FA3ULL, 0xA8F1FB0D5D54590BULL, 
            0x1399C790D9D108BBULL, 0x2C0971DC66D7CFD2ULL, 0xD0B93DE697E3E4B3ULL, 0x2EB3397B75D346E2ULL
        },
        {
            0xD1E8E2C92BE12658ULL, 0x9E894BCDFF089085ULL, 0x292AAB25E2BA0581ULL, 0xA8776CD56CD1095EULL, 
            0x3AEE7B649460890AULL, 0xE49B58D62A7ABDF0ULL, 0x2C85EB5D53B35512ULL, 0xF752DB8BE3314B12ULL, 
            0xAFB31EAC2A6F1EA6ULL, 0xEEB525E2CE03A804ULL, 0x321CB816EB9F672DULL, 0x42AF902649929B9FULL, 
            0x9061F92BB82C48A9ULL, 0x83A0B33A7CE20290ULL, 0x6DB9678DE2143858ULL, 0xE1F28FA92B8FD5C8ULL, 
            0x0DFFF591D1257722ULL, 0x6C5D81B10E773CAEULL, 0x05879B54BE4908C3ULL, 0x946BB1C8984D62ABULL, 
            0xD793203652E00277ULL, 0x407887EC58F11876ULL, 0xAC3E1497B8DB1829ULL, 0x5D46D6D29E9BAF02ULL, 
            0x4679D2B33FE561F9ULL, 0x35406274010B9EF8ULL, 0xFADA21E8CB8881AAULL, 0xE4EB0AB3C3D330CBULL, 
            0x76DC66C46BB01B9CULL, 0x3F2BA9DBCD48D8AAULL, 0x168DA0F927ADF600ULL, 0x18EE9026FFDD4DA8ULL
        },
        {
            0xC8DDC99EAECD7D7BULL, 0xF0E50A1F8C4B3ADCULL, 0x11D61D554CFF9A4DULL, 0x47BC267DF45A43B0ULL, 
            0xE3942817D629F405ULL, 0x511DE841A5A717CFULL, 0x396B7C602E222CBCULL, 0x527E69E07E30C3D1ULL, 
            0xF0011FA629028D80ULL, 0xA5086E5D8C6AB56CULL, 0xA19436C18E6A5F9BULL, 0x6DB340D2771522FEULL, 
            0x3DCE45EB56FED431ULL, 0xE5701554EA692E5CULL, 0x321582C5D3D9861BULL, 0xD31A7504CCF12366ULL, 
            0xDC32AF8371F1C983ULL, 0xE730E3754A1AC448ULL, 0x88704E5AD873F0AFULL, 0x3E6CEEE16984D9D7ULL, 
            0xCE7CA38A5A8FC946ULL, 0xB2050D11EAA60C11ULL, 0x10878406A2C54F14ULL, 0xF6C7562A3924AE9CULL, 
            0x2C02789F893879DDULL, 0x06F9347847881D04ULL, 0x3CAD95F3470D316DULL, 0x3EDC08DE5E709075ULL, 
            0x75E8142537B8A3B5ULL, 0x591071B2AA8C8A49ULL, 0x388DF89B3BDCDD9EULL, 0xCF522A5CD2FBF9C6ULL
        },
        {
            0xF6264195C4DEE316ULL, 0x15E70566E0DF76CFULL, 0x75F5872A1135D7DDULL, 0x4C2290C911F53439ULL, 
            0x5CBC5C33F4C868D3ULL, 0x9E0951833E75B5A5ULL, 0xA267BA220581B408ULL, 0xE1C4258F9721305FULL, 
            0x47AF34E8401FA777ULL, 0xE1F4DB320AF55016ULL, 0x860DE7859C5456CDULL, 0xC3AE5DC929E27259ULL, 
            0xC8F2649100C2C6BAULL, 0x46034C9F65DE6526ULL, 0x218DE1E3839F8804ULL, 0xEC61D0041AD0F92FULL, 
            0xFCD493528198CB90ULL, 0xEF61387CF4CE330CULL, 0xB672E8E776F2DDE5ULL, 0x031C376D3A7379B7ULL, 
            0x935E7B259C46BD6AULL, 0x28C9DA03A84792C7ULL, 0x2576F80EE43BF1F0ULL, 0xCD2BA404DD2BC052ULL, 
            0x6F2CA74A79788786ULL, 0x5D01B26E3EFD739AULL, 0x39346B58A0591103ULL, 0xAB21779E323AAE79ULL, 
            0x7F9F307AA99D320BULL, 0x2E9CF7AF7728898AULL, 0x2896C0DB0C08C055ULL, 0x73B7728435513C64ULL
        },
        {
            0x0683B00984669C93ULL, 0xAE183FA4EC059550ULL, 0x27C6E3BDBEE0A568ULL, 0xB7BE1586A489A7D2ULL, 
            0x2713996C13B76DE8ULL, 0x68C1DA9899EBDC6FULL, 0x22D8D100F323C044ULL, 0xB121B963F2584060ULL, 
            0x7876B8F429219ABDULL, 0x2266446E64E0A36DULL, 0x51042D954A6D5267ULL, 0x9DBBC2F08EB5FD8BULL, 
            0x4BA8407F611372BCULL, 0x8F86832B70F543C5ULL, 0x0415066AF2353049ULL, 0xA868F2DEBE6AC8B1ULL, 
            0x35DB39E83F4DF500ULL, 0x5AF18602DF96BE48ULL, 0x121A070744821B47ULL, 0x5B4C19C928BA0EC3ULL, 
            0x39984D34144832A6ULL, 0xE9E16B9C83A4CE6DULL, 0x89BBC845C77E81F4ULL, 0x8A6E68178B0FC9B4ULL, 
            0x0F95A459AB6B1025ULL, 0x878AD79FDCD899A9ULL, 0x2028F67959532B4FULL, 0x1C5118023CE91323ULL, 
            0xB2032972541C47C7ULL, 0x49ED120F59CBC7A5ULL, 0x460F91F01913A3DFULL, 0x55A2264E49E16F7AULL
        },
        {
            0x2DFF8679F92029DAULL, 0xBC793C5E01C8EA6BULL, 0x289C7CB8D7347540ULL, 0x1A1C090E5C859EACULL, 
            0x1893A286D3976C01ULL, 0xAC2FD5E0440ED0D4ULL, 0x694F42E8851C933AULL, 0xD1FD56909A007944ULL, 
            0x1420BAA04A9A5A32ULL, 0xE7AC758DF367D5AEULL, 0xEE824565FCF3565EULL, 0xF0C9F511338137AAULL, 
            0x29AA64FDFBA50EE1ULL, 0xC4CDB4087447A537ULL, 0x5016DFF4BB48A414ULL, 0x70990EA541757D96ULL, 
            0x85DED03A4F843734ULL, 0xA19B834E8BD14581ULL, 0xC8088EF200899BFBULL, 0x4335393A499EDBE4ULL, 
            0xC03071C05DCBB0B7ULL, 0xC378060D240077E9ULL, 0x17FA22C4B2542D72ULL, 0x66A59DFEE81F9E40ULL, 
            0xCAFDD1067D0A2A09ULL, 0xE77524C26AD4BC18ULL, 0x90A2FAFF78730EFDULL, 0x4E9416D164B8857EULL, 
            0x0BD7F419E50D485AULL, 0x81CA965F435E9B2CULL, 0x6B41398313B3CA16ULL, 0x17BAB770B1904B9EULL
        }
    },
    {
        {
            0xD7F62A9682283A80ULL, 0x41E4AAA17ABE3646ULL, 0x5CDF1BCC712B10B0ULL, 0xC879DC8F8C04F3D4ULL, 
            0x66373BC6AC89C085ULL, 0xEDA492289E622948ULL, 0xB08B61951D444546ULL, 0xA99DBEC810FA2F1CULL, 
            0x088C3578866FD93FULL, 0xC9C5E3078C3B05BDULL, 0x44A3AADCE6B7083BULL, 0x7F1F1461170A0D29ULL, 
            0xB761703E724F98CBULL, 0x5D45D58F5DF0623AULL, 0x7FE2070EBCEC4D81ULL, 0x6A2AA553FBBACDA4ULL, 
            0x05F5B929C848BDBFULL, 0x4A11035E6A5A1BE8ULL, 0x52A95E311A2B418BULL, 0xD6A9CFF3127392E6ULL, 
            0x49A34281E7E39905ULL, 0x8A7E6BBFBFA9058FULL, 0xC26CF53911DE7F7BULL, 0x2FFF412BDB47F490ULL, 
            0xDF5B775CFEEBB9A6ULL, 0x9CAEEC0D199FC48AULL, 0xB6D39654C36F9B2EULL, 0xDA746BA8C3D8CB5EULL, 
            0x1F6074BE9BDB2656ULL, 0xD233793C1985BB5FULL, 0xB26B53CCE2BB816FULL, 0x16E3B8E7D8DBDF7EULL
        },
        {
            0x6B578F9CFA235A65ULL, 0x2CAEA670C025BA70ULL, 0x54942389FBE95236ULL, 0xDD368DA50AADF66EULL, 
            0x5280255ECD730919ULL, 0x21C439FDCA4ADDAAULL, 0x591E4F46F6FA425EULL, 0xB74B153F66E74639ULL, 
            0x5FA9CAA4A734F466ULL, 0x7B1C6CFE341B284BULL, 0xA135EC448C7004B6ULL, 0xA8628ABEF39EBDD1ULL, 
            0xEBE8C851283FBD70ULL, 0x1B98B9C985E32DDAULL, 0x9C1CD3843B434C5EULL, 0xFA10B917FF5B84C7ULL, 
            0xA898793F6A986635ULL, 0x9624B2ED46923845ULL, 0xE4175BDB2D3F395BULL, 0x55F1E6C18CA8B562ULL, 
            0x6BD0F6859CCDF1B8ULL, 0x298C11553B0A2B2EULL, 0x60FFB09732105E5FULL, 0x1DA11C6652A93713ULL, 
            0xEF4E73E3498C5BF5ULL, 0x8E213B72B7850C78ULL, 0x3AE653E8B428B790ULL, 0xB6728B7985BE35D7ULL, 
            0x45F90742782EE4A1ULL, 0x615BB70CD89731A3ULL, 0x03919E4223C5F1C0ULL, 0xD88822D7EA54725BULL
        },
        {
            0x0D93C4D7EE4303DDULL, 0x377554388BD3E0DAULL, 0x13E89EF290511EBDULL, 0x7F90F9ACA7895D25ULL, 
            0xBEE4685A68A2F865ULL, 0x58E9133455AD384EULL, 0xD6300EB3ABFDB318ULL, 0xDD0BE35CCE22AFCBULL, 
            0x10152226BC1D86C7ULL, 0xEF5D7CFCA9446E31ULL, 0xE97A7CBE6B784369ULL, 0x5D3ED570412792BFULL, 
            0xE037AC19A790282BULL, 0xB21B940AD2FE9249ULL, 0x1714A50EE02102B0ULL, 0x25E4760D3D27CB08ULL, 
            0x5FD74B8957200FCEULL, 0x573064D6887260EBULL, 0xEA7F49F2FE87679FULL, 0xFB4F789A956603ECULL, 
            0xB5BB06EB8BC8F53AULL, 0x980DB814B663B9B8ULL, 0x0DD204304FBCF1B7ULL, 0xC8BD80BF4085FA67ULL, 
            0x677D020FCA7492A1ULL, 0xC29177E012EF4C80ULL, 0x6CDC086708E31251ULL, 0x718B67E4292F9199ULL, 
            0x9E87215456680913ULL, 0x20EC2D3378F0B96DULL, 0x1F032947C17341E1ULL, 0xB82D431A49E928ABULL
        },
        {
            0x5EE8CEF44E3F3122ULL, 0x2BAD6AF7E612DCD6ULL, 0xBED1F27EE68EB3A2ULL, 0x50734CCA79AD61D8ULL, 
            0x51C79B972672A9BFULL, 0xD1C14E1C58E96E63ULL, 0x7BFD877C3766551FULL, 0xD5D1223626C97913ULL, 
            0xEB20FF8BAAE85CC0ULL, 0x5E08978385FCEF85ULL, 0xB8CA5AF6C6A15CEFULL, 0xB330DE18B7CE1A21ULL, 
            0x88D682D7ADBD3366ULL, 0x9DC302CC7517FEB3ULL, 0x8B4302AAE24EAE81ULL, 0x6474F95267FAEA74ULL, 
            0xFB2CCD766523BCE0ULL, 0xECB9065380E491FEULL, 0x6FDDAA0BD0E38464ULL, 0x889B3ACCFC34776AULL, 
            0x495DB3B07E2463A2ULL, 0x208B892281D6271EULL, 0x3CF15A3D2415A094ULL, 0x2B80F5AA2171BA09ULL, 
            0x63A9171BF7B5BEC2ULL, 0x79F80570E83BE3F2ULL, 0xC2ED0CEF9262F794ULL, 0xE18F19F6496D915CULL, 
            0x8F3687A675E00615ULL, 0xD01E8701932C9EDCULL, 0x17DE6D6231B06557ULL, 0x33DB02A08A5A3B13ULL
        },
        {
            0xCEEAA6FF5358EFD3ULL, 0x3F539AA3C0808E8EULL, 0xA3F9758347891DFFULL, 0xBDC55B0878DF5AB6ULL, 
            0xABEAD557CE2180E1ULL, 0x61D840D4C30AE153ULL, 0x4B183C6D85EEA27FULL, 0x47FFAE028E3A21DBULL, 
            0xB54ACD9CA6DCEEA5ULL, 0x4186CB313CD608F5ULL, 0xE98E4D3979D95978ULL, 0x9A9A484E19A52F24ULL, 
            0xE3C9E43C08EBE291ULL, 0x8B0EF6821423D37DULL, 0xE470904315738A66ULL, 0x94A82407FE16B89EULL, 
            0xB26A801133334BE2ULL, 0xDBF4D9B5A587E1D6ULL, 0x1579B210FB313782ULL, 0xCB3EF5633AD98514ULL, 
            0x74F0A3F440D20D5CULL, 0x31F3DB363D7CF95AULL, 0xBE438E4E0114F4AFULL, 0x4358198255E45F53ULL, 
            0xFC5118D128823BF8ULL, 0x1C0A892762C10FA5ULL, 0xEC82D9667119DBBFULL, 0x193653E2B993702BULL, 
            0xD4B51797FF493B9FULL, 0xB382E9F7D8D5EE3DULL, 0xBA92DF16CDB6E598ULL, 0xBB33A9558805AB99ULL
        },
        {
            0x8A1D42070C24DE89ULL, 0x64CD54769BFB81A3ULL, 0xA489A5833A164F8EULL, 0x8B4164022EE53C44ULL, 
            0x268BABDAAAD96D40ULL, 0xBA14A17E8D630E74ULL, 0x5977B966B44101CBULL, 0x4412A590D75CC8B0ULL, 
            0x539F314B9758FF76ULL, 0x834F31EBACF5321EULL, 0x5E1052FE3BF771B2ULL, 0xB8791EFD49693651ULL, 
            0x5ECC4ACD329C84F1ULL, 0x0DFA9F43EA13681AULL, 0x254C6BCD6A13CF7DULL, 0x48CBD84852BE5681ULL, 
            0x655214FC46ECFBA4ULL, 0xCECB144ED65FFAEBULL, 0xF62E81B7F3115441ULL, 0x1C58A63E6A999F88ULL, 
            0x44D3F5791887A76CULL, 0x042F4E54C8CA1476ULL, 0x2E1220F8883AC9F2ULL, 0xCB310004F77C6FF4ULL, 
            0x663149EE39A3E2B4ULL, 0xDF32734A8DD3C8ADULL, 0x9FB988D00DB8D286ULL, 0x8D71563596E2DFE7ULL, 
            0xF24C6BA28FF99585ULL, 0x939188CC6227E2E8ULL, 0x62E1D6DF2CD9F1E1ULL, 0x12CB3E8E38A6EC38ULL
        }
    },
    {
        {
            0x98FF0F9716639AC5ULL, 0x6DAD25AFBFE39C93ULL, 0xBB6AAE32C278F057ULL, 0x26A7D296BC72E0B1ULL, 
            0x7CD6C13997D222F3ULL, 0x58C6AA3EDEE08BADULL, 0x645AD155A0BB0F7CULL, 0x0ACB3DE07104AFE2ULL, 
            0x512CECED697766D4ULL, 0x6E1F885785633AE4ULL, 0x45354CD2734005FAULL, 0x3C47411BDA83C1C6ULL, 
            0xD32585EC3648D7B6ULL, 0x84881CC890EF0573ULL, 0x1B1444B6595601E0ULL, 0x8BC1F56105D5CAE3ULL, 
            0xD4F1029CB8981B98ULL, 0x0CC3D042DA561E00ULL, 0x780FDF4AE91FB262ULL, 0x6149615F059C642FULL, 
            0x5D98DB89FFDD229AULL, 0xA35DC40E8C9EE548ULL, 0x017454AEAAB4CCF5ULL, 0x4E7309781D17DD6CULL, 
            0xADBF9933B6A82B58ULL, 0xD8F3F3155A8DBB47ULL, 0x5A2CD4938B873431ULL, 0xF8068638AFB7E133ULL, 
            0x0572724E97AB62DDULL, 0xCA219DAFEFCB11ABULL, 0x681817827A20B66BULL, 0x97DD30949C659210ULL
        },
        {
            0x2911AC53393A5C93ULL, 0xD5098A41156CE244ULL, 0x713107FFC9FCECE5ULL, 0x094C2AFF8C824018ULL, 
            0x792431DFA926CD85ULL, 0x457B87842FC9259DULL, 0x9886FB0905729F72ULL, 0xAF0721CBD4096B28ULL, 
            0x9761CE207A3E309EULL, 0x48CBA9CEEA7A82FBULL, 0x6765CBB32B683017ULL, 0x20B8FC32561961CBULL, 
            0x6BC894A82691B1DBULL, 0xE2DDFBDEE86DC20EULL, 0xFAA74A4ECDEAC8DCULL, 0xB5E20437F780D058ULL, 
            0x154D9FE49D6FDE4AULL, 0x5F6301576D9418B0ULL, 0xEC828683DE37A10AULL, 0xA7A57FA79A81B85BULL, 
            0x26F0C7780790A572ULL, 0x9B3D6F0F05D94506ULL, 0xC26DE58F4AEB6ACBULL, 0x9D5A4D3828F06832ULL, 
            0x48B1DCE4B7CF1353ULL, 0x703F76CB493EF663ULL, 0x494C35DCB7A4EA61ULL, 0x7ACF17ECDC376BA4ULL, 
            0xF3894E1BBB02B897ULL, 0x160579E0D7B7A11AULL, 0x6D615479E540AEDEULL, 0x1E64011BCAE2A13FULL
        },
        {
            0x412E951F4D5C5B86ULL, 0x281F12F970456129ULL, 0x3FDB5E9D5B8FA1B3ULL, 0x7608B436DA18A19BULL, 
            0xF404CE23C8458365ULL, 0x956A5494683850E9ULL, 0x06FD54116F778FDBULL, 0x42942011F8BDCB6EULL, 
            0x36DB94CCA6052BF4ULL, 0x5F2385AFA98E7F20ULL, 0xD1602B857DD5B618ULL, 0x08718B552768C9C8ULL, 
            0x85E56D3FFD8C1499ULL, 0xA9EC4803DD911653ULL, 0x49DCF6782831EEE7ULL, 0x84D956EAD53FDAEEULL, 
            0xBBC2A683249D87BFULL, 0x4DF166917B61FA5DULL, 0xA752D181C3E58387ULL, 0x1425D13F3956E33AULL, 
            0xF4A0A7FA6CBE2350ULL, 0xE913CF6F8E4B48ABULL, 0xAEDE1279006B7B13ULL, 0x46A211D0B182BCDFULL, 
            0x3D77659BA657FD3BULL, 0xB2965059ED98610AULL, 0x6D04217CF8C1E717ULL, 0x5E1FC5E7F0297EE0ULL, 
            0xCA33B047CA3C47D3ULL, 0x80FE3A3BF7313B1BULL, 0x751587C1ACB6F416ULL, 0x813EF787E70EDB8DULL
        },
        {
            0x075FCBA2CF380E47ULL, 0xF09744FD3778F592ULL, 0x291774CB45203BBEULL, 0xF01165ADCA018300ULL, 
            0x813EB1DC160E33C2ULL, 0xDCC6DFE3AEE92A7FULL, 0x521537D01A63497FULL, 0x2344A2EB9DB35BC5ULL, 
            0xE35AB20B4DE0F48DULL, 0x7E9C81B2A1322A2BULL, 0x1D769D66F0E12A17ULL, 0xD36E0B52C51C0607ULL, 
            0x887D963CEBBB2B03ULL, 0x62BEB963C24468F4ULL, 0x8D605C72B06BFA6FULL, 0x6816BC5499603714ULL, 
            0x200BCB0FA53D14E2ULL, 0x45F0B14AA07E9A41ULL, 0x3B70588F9FA496E1ULL, 0x77601B2C6B7D3F14ULL, 
            0x4FCF938AB35B2519ULL, 0xC7FD69087AB60540ULL, 0xA97793FB708DAAAEULL, 0xAEE03E066A9A0CEBULL, 
            0xC75FE801E63C6444ULL, 0xB219A9AD102685CDULL, 0x073CA95440069E56ULL, 0xAB2153037B2C2A42ULL, 
            0x24612FF555CB8462ULL, 0xED2EE95D856646C0ULL, 0xD31B31B2CCF77A8FULL, 0x0060B0B5419E1F7AULL
        },
        {
            0xB4A8FD42F1B61D03ULL, 0x29D504C6B9AED314ULL, 0x2B907423184041AFULL, 0xA1CDA4F4B7DEA3D9ULL, 
            0x6F5E949D806333D9ULL, 0xE3DCA5F0714FA8FAULL, 0x90806771600F90E3ULL, 0x60A8942B27272D13ULL, 
            0x287219668C4E1ACCULL, 0xE83CB7F17B962E5DULL, 0x72C8C030C1AB4065ULL, 0x4EACCC5A7302AD0DULL, 
            0x618BB58A5C43F358ULL, 0x5597F00B88EE1D08ULL, 0x13E266B10ECCC6A6ULL, 0xF60D427BC94B880AULL, 
            0xA938A057D4B74AC9ULL, 0xF100A6DC3B66944BULL, 0xC442AF6C802FFA80ULL, 0x2B38E0D9B4AE3FF7ULL, 
            0x5F5AB102EFF1F7EEULL, 0x08DE2828B392E023ULL, 0xCCE60829CC83D325ULL, 0x08749788051B9CF9ULL, 
            0xF19756EFAE42B5BBULL, 0x9E52E4C31F2DA838ULL, 0xB1495835850458D9ULL, 0x7CC5A389B6DBB092ULL, 
            0x05D3280ED2BB552EULL, 0x0D7EBCCF52E715C4ULL, 0x1685A54E84410D60ULL, 0xD0DCC8F7BACDC3CAULL
        },
        {
            0xC06637DAD7FB9B44ULL, 0xD183CF10653D5306ULL, 0x8B36809A8C34E270ULL, 0xD229A3A9FA67002DULL, 
            0x56DF8A904B729397ULL, 0x46CBF7269B875F92ULL, 0x0BCA4D42680A2710ULL, 0x3496A3DF80F05A1FULL, 
            0xA158914BE8703CF5ULL, 0x0F9DA92DE88C6264ULL, 0x607159C803817FE4ULL, 0x5C5EF4FFC4EA7ECDULL, 
            0x4B519590F9264423ULL, 0x6A8C965550BED1BAULL, 0xDBC8604CD7E1D790ULL, 0x18C5B9A5D28ABBB2ULL, 
            0x92BFF6AB989164DEULL, 0x9FDDF16B52E6BB08ULL, 0xE9F2D9A1E97DED52ULL, 0x6FEFCCD0B4434BD3ULL, 
            0xF29893DE3A40683FULL, 0x5A02D73231AF4001ULL, 0xD1DCACA361B7E2C2ULL, 0x5FCD8584875FDECCULL, 
            0x8E412000C94EBB23ULL, 0xA35F8748356BAD8EULL, 0x20E85EFE4D9361FFULL, 0xD46AA7773A9B24DBULL, 
            0x077E7512CC0BF2CDULL, 0xD98CDF466557C1C9ULL, 0xF69CF08FADA8974FULL, 0x83E880184038FBFAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseBConstants = {
    0x783D005B796C5BE0ULL,
    0xDF049A4F2AFE6A2EULL,
    0xC0CCE8E511D51DE0ULL,
    0x783D005B796C5BE0ULL,
    0xDF049A4F2AFE6A2EULL,
    0xC0CCE8E511D51DE0ULL,
    0x58EDF4B1384E900FULL,
    0x50CDF5F7D4E0C77EULL,
    0xE4,
    0x93,
    0xC9,
    0xF8,
    0x12,
    0x91,
    0xD1,
    0x39
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseCSalts = {
    {
        {
            0x3C39AF6FAAC4DE75ULL, 0x6FA3E088921C3D55ULL, 0x6EE3AB8A933DEDC1ULL, 0x2B821EBFC1136E2AULL, 
            0xF76068F56C592AC7ULL, 0x9DD5F1DB72A6DE28ULL, 0x4EFEC2D6E2D92C12ULL, 0xD775A5602EA1098FULL, 
            0x9DEA4A6FB8418866ULL, 0x069FCD2963A0776CULL, 0xA6D74B157426897CULL, 0x635160D45833D2A3ULL, 
            0xFAF047B1C071C7EDULL, 0x3FCB746E28DBB71DULL, 0x12E474E410795296ULL, 0xEFFA686ACBD00AD4ULL, 
            0x8A4A53F4A35A2CF1ULL, 0x211E63E9AC32C2CAULL, 0xC8CCF26782C4AE99ULL, 0xCE1AE5AED88CAAD5ULL, 
            0x85871CCDE4AB14A9ULL, 0x199511FF8BAFC650ULL, 0x4C659A4B21AECC03ULL, 0xBA69F8E24521E032ULL, 
            0x778BA37416DF4CF6ULL, 0x1ECFC98E6191FBBEULL, 0x6F52654604D66D06ULL, 0x12B783F85A85CCA5ULL, 
            0xA2789A164CFCBA9EULL, 0x687117D47E7A0923ULL, 0xFFC442876215E708ULL, 0xDD26FC064931084BULL
        },
        {
            0x7066C92BEDD832DBULL, 0x3431A09F12E8B457ULL, 0x9B3A5C85144D2D25ULL, 0xA90D5BE5369334C2ULL, 
            0x13D9FF486B8885A5ULL, 0xD39E430904605B58ULL, 0x5DE8F2E091C47403ULL, 0x6404AD5AFDCD288EULL, 
            0x5DC8953A21B8837AULL, 0xD2CCB9D9FF28ABBBULL, 0xDCD6A5DEEA39FBE2ULL, 0xD4276EEF109C7F96ULL, 
            0x9F2E09F2CDC6D128ULL, 0x3578E1F911B65D37ULL, 0xC2B52E3DBE7A1311ULL, 0x02F58D5563415A77ULL, 
            0xDC1F1161310D9047ULL, 0x6A158500FE88145BULL, 0xAC1C6C39E2B508A0ULL, 0x9E124BBAE6F06C5FULL, 
            0x0BDB4BB0D63BDEFFULL, 0xBB03A7EE67937BEDULL, 0x0ABE01439E7332BAULL, 0x00675B71CA383584ULL, 
            0x7F01116BCEA5893DULL, 0xBBD0C7B9E13595EEULL, 0x7550EECB9BE15C45ULL, 0x6C9BFB4E06EAA749ULL, 
            0x5475A3F451EC0D69ULL, 0x1198D09E8F6C4BDCULL, 0xD08EF978E77446BFULL, 0x96F2E0EC25C39985ULL
        },
        {
            0x905DBB4DB8CBA1E3ULL, 0xC19480737C0E151DULL, 0xCCCB6DFC6D51C22BULL, 0x48F0B391A722E1ABULL, 
            0xAFAC1D12AD15BF82ULL, 0xD0B73A6F9FFDE8E4ULL, 0x1B1E39FEAB66B1E1ULL, 0x6327ADE2F11DE48FULL, 
            0xF99AF4DEA3F80937ULL, 0x4D79301E6C0C72EDULL, 0x2CCA06CF92D6CE7CULL, 0x1F391BF74A26A969ULL, 
            0x72CFF68BAFB04B5DULL, 0xEACD419DF1575E09ULL, 0x71C694410AD78C24ULL, 0x9B33F8A4A92AC951ULL, 
            0x858BB7241D2DAE85ULL, 0x3B521AC92F81BF5FULL, 0xD34C8E7D3CE92640ULL, 0x8D90C679C49E4CF1ULL, 
            0x3EAD0BF8EE0481DEULL, 0x9950E835C1F02FA8ULL, 0xB2DA0B4BAE4AB0B8ULL, 0x64775B496714DD2CULL, 
            0x198D0C428A5AB7A7ULL, 0x097A0BDF5B260E95ULL, 0x7954614021F3AC82ULL, 0x4820213025B050A1ULL, 
            0x1987FAF47EA8B540ULL, 0xD1C873A82777CF38ULL, 0xEB0A9B74A19F21D9ULL, 0xE951E79B21915547ULL
        },
        {
            0xEEF2FE3AFB10A1AEULL, 0x4C5FCEAF7273D058ULL, 0x5A3F53087D8E1056ULL, 0xB1AE761691428DDFULL, 
            0x7F2BCF0A1F2DDB70ULL, 0x994E348E073BFF51ULL, 0xC0B40179D61C75A7ULL, 0xE70B03C1B66EBFFDULL, 
            0x4E2E0D9E9690BBB1ULL, 0x495063F0E79C4A95ULL, 0x7AE90714B66EC588ULL, 0x12DB83C6B36243BDULL, 
            0x99D32A83F0CDC830ULL, 0x8EB874991D1DA592ULL, 0x8ECA72FA75E8ED47ULL, 0x580FBC37CEA1873CULL, 
            0xFA33D242B9429B63ULL, 0xF71DE4AA4F7789F9ULL, 0x139C1418ED6182FBULL, 0xE385B7112A5FFFBDULL, 
            0xED1C31692014424FULL, 0xF6B0463DF2EFEA7BULL, 0xB3A5ECBDD8C7B7D2ULL, 0x6B61E34604AA234FULL, 
            0x4B8BBA5E83F45A50ULL, 0x8351DF87958561CDULL, 0x775FD4B2EF912036ULL, 0x2934CA69AEAAF7E0ULL, 
            0x3D5B1678F533F9E4ULL, 0x98695F143541F4E2ULL, 0x5F280AA5BB10822EULL, 0x64E754B773880C43ULL
        },
        {
            0x7882316C6659634DULL, 0x962450989B7710F9ULL, 0xE614FCCD64F106FCULL, 0x78E4AB57C48B1EA0ULL, 
            0x1DE658A7CE4E519BULL, 0x293F42FC632202CDULL, 0xF63BC241D16139F0ULL, 0x7D4C69258509335FULL, 
            0x163169AF488475B7ULL, 0xBA7B61D8702175F8ULL, 0x2FBD48552C9670FAULL, 0x57353C646CF5C24FULL, 
            0x74DF8653F95BE50EULL, 0x65C50946796B79C4ULL, 0xB6C5D457148EAD0FULL, 0x7F2FE16857B2C167ULL, 
            0xD31A275027429D43ULL, 0x3CCD8DCC0377AC38ULL, 0xDEDD4001649C7627ULL, 0x9674DA8142A96913ULL, 
            0xB816C4F2104E0409ULL, 0xC6A1E8FD5BA2B31AULL, 0xFF671F91860EA068ULL, 0x86EB6B4C1C54AF94ULL, 
            0xE9B543C462E127EDULL, 0x491D55A9492A1441ULL, 0x05BC09677E50B971ULL, 0x0E83DD7677D68D8EULL, 
            0x4B4A8AFD7368097AULL, 0xF3D2650FEFF15109ULL, 0xB2DE9508F2FC912DULL, 0xB678D76076F3ECA3ULL
        },
        {
            0x0CF2ED1BD5B44A71ULL, 0x2BDBA4926441F9DFULL, 0xE6E6DFF066EBA2D0ULL, 0x770E70DFDE366826ULL, 
            0xD8179FA59090D256ULL, 0x50B2804AFE009AFCULL, 0xEDC592BA80578F06ULL, 0x2AEFED7F87EF0B2DULL, 
            0xCCCD5B3BA4311A1CULL, 0xF0C31E0C379FC214ULL, 0x39813FD034614AC2ULL, 0x678C4CA56EE12C9CULL, 
            0x275C74B457555186ULL, 0x8C099A2AE9FDA81EULL, 0x64995F292F4EEAF8ULL, 0x457FE0F0E60085E2ULL, 
            0xE277F32FB4849D64ULL, 0x706F6FA34E30846DULL, 0xDF9A790A851EB20AULL, 0x27BF90909DAB55AAULL, 
            0x234A9FB5CE00F65BULL, 0x7A8B95647C4E9074ULL, 0x29D11C6E090CFF13ULL, 0xC3CB9F463FBA9937ULL, 
            0xE831C715187EDA1EULL, 0x408583D14EB99463ULL, 0x60FF6CFE349B12C3ULL, 0x789E1F7282586971ULL, 
            0x188F1E8EEDB62BA0ULL, 0x3F4C5C1E336F7869ULL, 0xFA505CAF37101BCFULL, 0x898272A70C5368F3ULL
        }
    },
    {
        {
            0xEB4F732F1C15A4A2ULL, 0xAA891BA95A175F3DULL, 0xFFEF367735EF83CBULL, 0xF94DF045B7BF37B6ULL, 
            0xDD899F5A37DD78AAULL, 0xEA5B41B2D8F54F60ULL, 0xFCA58553A82C9262ULL, 0x713EE482FF46677CULL, 
            0xE26AB125E1870D14ULL, 0xA053A451A173BD85ULL, 0xE4A4E677DC2A9D4EULL, 0x5F11B28FA1C6594AULL, 
            0xB2CB389B6A5AC16FULL, 0x90B7DEEDD8E8B9C1ULL, 0xCE48B1A3EC443058ULL, 0xE65B8857DA6CA858ULL, 
            0x32FFD7B9FBA614B7ULL, 0x25424A4302C79D2BULL, 0xB31081FCE0B27319ULL, 0xCE5729EFD8AED832ULL, 
            0xEE844A37E557CD2DULL, 0x331BDB956E581D7DULL, 0x090CF741E21029A8ULL, 0xE80E41F35CAF60F4ULL, 
            0x580F1E6C972A0549ULL, 0x47B8C71C8C5E9788ULL, 0xBC0B0550C673BEC2ULL, 0x0A3AB8081EEFB38CULL, 
            0x1C0AAB6400579372ULL, 0x27408812AFC4E054ULL, 0x193B9004F11E953BULL, 0x1D89B6C4E3E88D13ULL
        },
        {
            0x3EB40EEC862BFD10ULL, 0xBAD277735FA15818ULL, 0xCAC153CE55F36000ULL, 0x0754FD62329F8AA8ULL, 
            0x8CDA1E6F98866B29ULL, 0x13DB0666F431648FULL, 0x90BAE6A3004A5027ULL, 0xED9E671E8F3919BFULL, 
            0xEED982F39FF5EB5DULL, 0x2EF380EE993DD8CEULL, 0x7BE359353ECF4FF5ULL, 0x773ADCC9DC59689DULL, 
            0x7E52A926AE154CAAULL, 0x5A44C1BCB00401DEULL, 0x863421055B93EF63ULL, 0xAB6DF6E5EAD3B31EULL, 
            0x9760046BD1E0301AULL, 0x3114A6B778F6EE69ULL, 0x0074B458CA82545CULL, 0xE942F96C73098A79ULL, 
            0x55AA013FCED407EBULL, 0xCD9E9F56D42B11A6ULL, 0xD58FA64901FAA1ACULL, 0xF5682ED088FC7380ULL, 
            0x3F5C7506900B54EDULL, 0xCA5829275215EF1FULL, 0x68E9145F5FB2E0D7ULL, 0x266FA2809388CC5DULL, 
            0x7D91443E1506EBCBULL, 0x9CA423926EACE985ULL, 0xD6BE02B964200A64ULL, 0x7C192810EDEDFAFCULL
        },
        {
            0x2AE526B831D988DEULL, 0xB6F139A92CFA5DF3ULL, 0x33736364EEFB1097ULL, 0xD4C9A68452E625E5ULL, 
            0xD6BE0BC57244E1D9ULL, 0xE58548D6CEFFECFFULL, 0x8ED9CDDD4EE20B78ULL, 0xF15C0B579028746FULL, 
            0x9C4DC02575561753ULL, 0x57B49E0E69986432ULL, 0x2E16F9B7CF38ED64ULL, 0xA313D30D1234A256ULL, 
            0xC130D5E3790D4D88ULL, 0x60DC174EA5EF1F22ULL, 0x1921794A5CAEDD71ULL, 0x344782F2FCA82436ULL, 
            0x6631F1684F8F45EDULL, 0x27B08FD56A659BC4ULL, 0xA0F6756807D5F8FFULL, 0xDAB06DA701488C96ULL, 
            0x86DD9C00B0FDAED7ULL, 0xE56D60A6B09A231EULL, 0xE0B1D4DDDE9097A8ULL, 0x40BAC5322C5CB1DDULL, 
            0x0376B38DE885B1A1ULL, 0xAFBC564E40CA0F6AULL, 0x7CBB8BBDBD50F0D5ULL, 0x52E7DB180C490DD8ULL, 
            0x0DC7106040B352D3ULL, 0x601138667324CFDAULL, 0x07C99F8AF44DD8F6ULL, 0xE6D152D0CE31FE5AULL
        },
        {
            0xE88D85E916E58417ULL, 0xBE0BF12523B9614EULL, 0x07C6BE8E99A847BAULL, 0x3C4EBB83C6E42098ULL, 
            0xE98BEE30004B5614ULL, 0x5AB3306E37DD0FD6ULL, 0x87506BC87E25CD75ULL, 0x0BF1C9C6C43DAEC5ULL, 
            0x556829F223DF6A1DULL, 0x947F31951AC92F0EULL, 0xEEA28A5D272CE3F9ULL, 0x3685443B42CB45EFULL, 
            0x021B30B0B3B1339DULL, 0xF42DC512E55D113BULL, 0xC30C1D819E35DBA1ULL, 0xBB0637F1AC6C26A2ULL, 
            0x5F834A86C19613A6ULL, 0x6729882A85CEBB4DULL, 0x282A0C23EC558718ULL, 0x27437B14CAB1E514ULL, 
            0x3EFA9FA27C2889FAULL, 0xAEFD3CBAF5B2A58FULL, 0xA55A7A32E1F0BD0BULL, 0xC3227EC92BBC200DULL, 
            0x7170DCD8257FBF44ULL, 0x1B390E893DFD5141ULL, 0x0CED371FA569C684ULL, 0x9788E03015ED219EULL, 
            0x6D25686AF5D93D27ULL, 0x5AB4CE88A18378E1ULL, 0xA22FFB9FF36C48B7ULL, 0x1C08B400B3C86F31ULL
        },
        {
            0x4A9A9BBC2C05630AULL, 0x47CBAFDD77241001ULL, 0xA18D746BE22F7715ULL, 0xA62E3CF4C59B1BC1ULL, 
            0xB7A8B3748617D710ULL, 0x5DA43DFCE2482B96ULL, 0x90424D3C16A5EE5BULL, 0xF5CFE83663C917FAULL, 
            0x14808C7DBD72187DULL, 0x65318F58F6C5BDEAULL, 0x12AE1C5037E69562ULL, 0xF900CE14702FD1D7ULL, 
            0xF07F91970F64C569ULL, 0x5BDAB0441721C2FAULL, 0xB0AB08F44395A0EBULL, 0x0156B13E71A9D2F5ULL, 
            0x38064CE8D76709AAULL, 0x2E977881A177A8C7ULL, 0x7D061F1488E0B7F4ULL, 0x59B0245CD3E7DC03ULL, 
            0x8EBDC8406F6C78CEULL, 0xD6E1D6304EED1D11ULL, 0x2FE3365BF7E46657ULL, 0x0E4D1004A849D721ULL, 
            0xAD4A0FEE8BB5EFBBULL, 0x9385E70F6E5589CCULL, 0x11ED055364F623F4ULL, 0x84181E197D60EC55ULL, 
            0x41AFB1180C6B5CD4ULL, 0x7C21E9DD3796E009ULL, 0x3F0A2B3461C6769AULL, 0x0972AB66AE78247FULL
        },
        {
            0xC1B0427088BA6C98ULL, 0x2BE0ACA91EA3DAEBULL, 0x820EF87A1B20A399ULL, 0x13D9743EC3480C1FULL, 
            0xF97A83774B1422D6ULL, 0xF8251F198BFB0E11ULL, 0x7D1C3EF135B5578CULL, 0x8C9E9E0C1757DF13ULL, 
            0xC19E305664559CD3ULL, 0xDD0EE8E5D6EC1429ULL, 0x1E1D1D91BEB6753CULL, 0x00F9B7E35F832C52ULL, 
            0xE77ECD1E5556AA88ULL, 0x7412D52FA85EFBC5ULL, 0x84EB917553971D3DULL, 0xDF28A5A33565CE51ULL, 
            0x4EB19172A7AB8C65ULL, 0x91D83E8B990C80CCULL, 0x1D389CFA2E9FDC50ULL, 0xDB70B870F52859EFULL, 
            0xC5A7294B18D3CEF5ULL, 0x943179C240DA50B9ULL, 0xE3F47662D7C47C2DULL, 0xB0CE1EA97C3B6217ULL, 
            0xF52A6D806CA832FAULL, 0xC9BF541822A233E9ULL, 0x3A4A07E5E44228A6ULL, 0x3F5775FF5C0B6FBEULL, 
            0x30244B966FA41193ULL, 0xC6FA81D812FA35C7ULL, 0x9B9D8A341EA1A4F5ULL, 0x82467FC9C5FEE60BULL
        }
    },
    {
        {
            0x29B8DDD4452EA5EBULL, 0xB6C1E50192475D04ULL, 0x92443F94861C6044ULL, 0x2D1CE6DD6B9AD333ULL, 
            0xEDC354D51B996C05ULL, 0x709D46EED0F2ABF5ULL, 0x88E0823BFDEAC2E7ULL, 0x541C59F51D34E17DULL, 
            0xCD4499AA80AFA612ULL, 0xB65014DE2E2BCDAAULL, 0x76B3AED2FA96E026ULL, 0x57B992BB8873E1FCULL, 
            0x40B050D76E5F99DBULL, 0xF9FBB8770173FDE0ULL, 0x9779B78D9142A59FULL, 0x2D17DA81D7DA9395ULL, 
            0x392F39A57FE31DDCULL, 0xB4D07B1CE065FF8EULL, 0x07D1360DA6C9FEBDULL, 0x3768A1A9E922FE95ULL, 
            0x8907583591FB1833ULL, 0x57FE82CC303D3C0FULL, 0xC51BADDBFA932C8BULL, 0x6C253DED2DC5AD25ULL, 
            0x027FFD0030A7E87EULL, 0xF9214189ECA70E0EULL, 0x3552D07237C7C440ULL, 0xA5456313FEA6295CULL, 
            0x54B72FE59D620BADULL, 0xD9E190AB1C2E1A09ULL, 0x4D6A84C01BB8062FULL, 0x7C9BAC773CD7CB93ULL
        },
        {
            0x8B32170FB4D87293ULL, 0x23C543E0574D5406ULL, 0x6F0B0073A9376BC8ULL, 0xED921E4650410DCBULL, 
            0x483812309A5937DAULL, 0xA58B5C7D249730A4ULL, 0x096DEF3D8413A162ULL, 0x53AEE7A2EE43DC3BULL, 
            0x1AF7890390F42038ULL, 0x5E01BFEBB85CE1F6ULL, 0x99620B95F404A1DDULL, 0xF45DD5A532BFC6E1ULL, 
            0xDFC20DEFBA7AC3BEULL, 0xDAE0A77C3ECCB5B8ULL, 0x43E4505E95335BE9ULL, 0xAD5E1C241F573371ULL, 
            0xB12D6965D5AB9B33ULL, 0x5D5D35B29C6C19BEULL, 0x234E750A46ACFE17ULL, 0xCA2A8024FCFFEF05ULL, 
            0x92FC04556B94437DULL, 0x3A08787637B2CB76ULL, 0x2109BDB24001D24FULL, 0xED317874195F0F02ULL, 
            0xAE02B9F054F4562AULL, 0x325F1BCBFB47ACB5ULL, 0xE08B588F6B72C1A5ULL, 0x75457D4B94E078D1ULL, 
            0xB7F295564991D5A6ULL, 0xFDD7C83AD722639AULL, 0x6FD2A97A9103ABA5ULL, 0x87187AB7053592A3ULL
        },
        {
            0x7DE61836AF2F68DDULL, 0x015AAF7AEFFC699CULL, 0x919038996CF1AB51ULL, 0xF0EFCF71AD806B20ULL, 
            0x997047141B31C929ULL, 0xE5C20B46E7F730C3ULL, 0x66145D0092CA46FAULL, 0xC8F43E187999C0D2ULL, 
            0xA0E10E92C9A6209BULL, 0xB7794E22D0BEF874ULL, 0x203BFA461E9904B6ULL, 0xCABDBFED9BDD026AULL, 
            0xFDF3B71C578EF5D5ULL, 0xFF99842DDFF5D6FBULL, 0xBB864899944F7D58ULL, 0x3D405FF52E3DC695ULL, 
            0xE56BF2EA4D8506F3ULL, 0x6B8492C3464C80F4ULL, 0xF31FB30FBDE0ED60ULL, 0x6B4F3EAFF6244C09ULL, 
            0xC032FBBC3DD9501AULL, 0xEB44437C275BFBD1ULL, 0x36323665E67DD7D1ULL, 0x96269B63356A61D4ULL, 
            0xA1BAFC95DD665909ULL, 0x2C866C93B8838DF0ULL, 0xD2897F1850597480ULL, 0xAFEF04D146461E30ULL, 
            0xBCDEB08CCEB6661CULL, 0x1EE218AA9A430B2CULL, 0xDD3687BC1EE959D6ULL, 0x911CAD4D2E8FA06FULL
        },
        {
            0x87BAE824E4361D69ULL, 0x8EBA951C73D00632ULL, 0xCBD8C72052E700BEULL, 0x145C0476831A5A47ULL, 
            0xA55FCF40F984D32BULL, 0x981D77E56171A544ULL, 0x5555A01CD27F9F67ULL, 0x2C980A903CD2ECD5ULL, 
            0x2349EAB16D6B8902ULL, 0xCC0A29877AA98778ULL, 0x98156E893FD63336ULL, 0x2DD5B33D2597961EULL, 
            0x5732B6360FFE056EULL, 0xAD64019735A6C8D3ULL, 0xA9E026417C1DA1F7ULL, 0xDDE27BCD785E60F2ULL, 
            0x2C84AFA2D1000B10ULL, 0x165C1F5F1FCF7CAFULL, 0x41AD66E3DDD1C4C2ULL, 0x47EF0F064A7DD2E4ULL, 
            0x40E240137E5D7455ULL, 0x43704466E4EE6B05ULL, 0xF974481ADB2DB9CDULL, 0x42B6E256E154FDC7ULL, 
            0x52821BA9DE6CC820ULL, 0xF14268CADE624295ULL, 0xE7949F7FD024BDF3ULL, 0x5FE7E0E63A31B152ULL, 
            0x1538B9F14F5E05C3ULL, 0xB0A24B2C5E7163B4ULL, 0x378DFD835DE0EC9DULL, 0x6A18E9CEE39DF4BDULL
        },
        {
            0x3AC085D74963F5CBULL, 0x78E89E4E7B5EB6F0ULL, 0x1AE8AF96679694AFULL, 0xCC2B7B3C0A82EDFBULL, 
            0xE3ED1044C392B529ULL, 0x17600E6A3FF48FE7ULL, 0x227D450B8A55CE55ULL, 0x8A8BAE5F9599C12FULL, 
            0x5BB6BEBFE70EFD60ULL, 0xADCB1F66E68E9504ULL, 0xF978DC995D63B086ULL, 0x87E2BE1E2A36A2CAULL, 
            0x7ED07D20BD0B646CULL, 0xDA8E82CDD3E8EE79ULL, 0xEF0FE7994F5D3FC7ULL, 0x8C5B5704199D8CCAULL, 
            0x2C16DE95D4F5DDCEULL, 0x16B09AF14F6F45F1ULL, 0xBDB111D978D21CC8ULL, 0xC5D4BE7A2BC4668FULL, 
            0x7C6898E9621E9714ULL, 0x26470625745E29FCULL, 0xE879AC1D7408D19FULL, 0x72D30F13C0BBA6AAULL, 
            0x03ED797C84037110ULL, 0x53D1AA93F2069408ULL, 0x03E9549882A63F12ULL, 0x64A2DEF2DDD4F9D5ULL, 
            0x3AA88E8025848019ULL, 0x7C1C1D5F262BC12FULL, 0xB4F1261C058ACEF7ULL, 0xD01360C4F9FDE72CULL
        },
        {
            0x6F8BE64EB032FB88ULL, 0x861E894E2D593399ULL, 0x433760014E06ED02ULL, 0x052B5D07ADC8C13DULL, 
            0x0D06ECD6AB2EBD18ULL, 0xDE2504A2DF40ACB4ULL, 0xE880E06C87FD71B8ULL, 0x6B9D41CC72ADFA46ULL, 
            0x56C3D8F7725C0897ULL, 0xB1F7AD320F1D6BB3ULL, 0x6FA8FAEB0A91D709ULL, 0x071C3A3438BC56D0ULL, 
            0x50E6ECA03DAC9F87ULL, 0x3BBFD41B130883A6ULL, 0x4CD22AEC48022AADULL, 0x8B2F8B33531F247FULL, 
            0x72AC48720ABA89C3ULL, 0x52D588F83E93DB10ULL, 0x1727FDEF17F12067ULL, 0xA4EE217E5FBB8F04ULL, 
            0x57D8B3FB97F759E8ULL, 0x61DB04D714CFE824ULL, 0x6A35F919EABC1A95ULL, 0x003DF421FC5C75A4ULL, 
            0xB8233A20F7B59864ULL, 0x1ECE4DCDC183E478ULL, 0xC58250BB800A8F22ULL, 0xE1B07BE6E0984818ULL, 
            0x668F95834A2E5095ULL, 0x8017E88C39B3ED8EULL, 0x5D6A9A1FBAA334EEULL, 0x34A2463382F647DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseCConstants = {
    0x22DF833BADB61E53ULL,
    0x44945D57D89DAE21ULL,
    0xCCC0B3EF45FAD71FULL,
    0x22DF833BADB61E53ULL,
    0x44945D57D89DAE21ULL,
    0xCCC0B3EF45FAD71FULL,
    0x2DB207ED33AE5D94ULL,
    0xC0D7FCFA925FE0E7ULL,
    0x8B,
    0xD9,
    0x58,
    0x3D,
    0xEA,
    0x6D,
    0xEF,
    0xE3
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseDSalts = {
    {
        {
            0xD507F91E91B62D49ULL, 0x9A2423BADA1B1536ULL, 0x86E6FD77F95BAB97ULL, 0x5532EC715B22AF84ULL, 
            0x9B06294AA39EAE3CULL, 0x2315E57B1439FCDDULL, 0xE9C004A949F71DA5ULL, 0xB57DA4DA347B1A11ULL, 
            0xB223C0D8236D6239ULL, 0x906C74144B1D8B81ULL, 0x67A62381A5470C65ULL, 0x85CEF82AEADD66BFULL, 
            0x9D27457D4FAE8C25ULL, 0x46702B0EF22065AFULL, 0x9DCBE3B88ED1111CULL, 0xB2E64E1E81D09809ULL, 
            0xC7E16E2FBB8184FFULL, 0xBF90D77B3234F098ULL, 0x920E661E6F9B67F8ULL, 0x6308E2D97937C267ULL, 
            0x0F9CD191B9A98025ULL, 0x6CA125E7A4BB7E2AULL, 0x2868FAEB3C1E1B8BULL, 0x57AB043CD188946AULL, 
            0x4158F1B2AEF7B837ULL, 0x3D39D9E2E0443B76ULL, 0xBFAFA74FE69C71E8ULL, 0x147234061B048173ULL, 
            0xF4153FE51CE959C8ULL, 0x4C05EC6350B9113CULL, 0xC4813C3477312179ULL, 0x84DD4EBDED7AC0D3ULL
        },
        {
            0xCA5667EB3FECA0C2ULL, 0x5FECBF21F28D66D8ULL, 0x9E7280D30C56662BULL, 0xBCF0A65486189938ULL, 
            0xE7116492E5CA437CULL, 0x1C7750051B8118E0ULL, 0xA2F1764FA153F362ULL, 0x09ABC7C91BB7CA0CULL, 
            0xBB1FC278962EDAF8ULL, 0xF7010F9CE754C71EULL, 0x71910FD4D55E94B7ULL, 0xA07B36882F446A28ULL, 
            0xF2057E49EE931278ULL, 0xB5CA59C497581030ULL, 0x847B7B47962092FBULL, 0x3B4EA321D9BF44E8ULL, 
            0x43A42E7817A5FE67ULL, 0xDF4A57D8E431F125ULL, 0xC234A4525CAE1204ULL, 0x05426F045E7258AAULL, 
            0x25599F6ABE69334BULL, 0x571D1A082DD9AD1CULL, 0xA07651B2A41BDD96ULL, 0x222555D861715AE9ULL, 
            0x468F4360BFF49A96ULL, 0xB97AAD6CA8BB7A73ULL, 0x115F387C2EC88BACULL, 0xE9A7F8D322FBC784ULL, 
            0x65DF148E4B7800FEULL, 0x64FE5BC5AD4F600FULL, 0xA093FA51E2D6ABE9ULL, 0x22C447D91A8B5DBFULL
        },
        {
            0xEF20DEC02C0EA5CDULL, 0x9D92D1C79A02E787ULL, 0xF9C5E754A581DB41ULL, 0x421292172255D793ULL, 
            0xB5352CC7E847391AULL, 0x1D40CFDE6731C636ULL, 0xFA2CC1755798941BULL, 0x3A4D23B3F60F29E0ULL, 
            0x70676D3C1D54A694ULL, 0x5F575F0C9CA0954EULL, 0x13CFE082EE7520EFULL, 0x3BFC2DC92934A725ULL, 
            0x8AAA9F1DF6327364ULL, 0x7681800D766490A5ULL, 0x63B9BF03E150098CULL, 0xDC2F891AA870DF4CULL, 
            0x43E0C7FF0AC48CCEULL, 0x8F6B70D2EA585DE5ULL, 0xE81156B1E19255A7ULL, 0xC992F448AB831FD4ULL, 
            0x32A6F3FC0787E3A5ULL, 0xFA8925545FEC45E0ULL, 0x53BA8382092DB1CFULL, 0xF5F5053873AFDA76ULL, 
            0x66BFC532F53E118AULL, 0x1CD679BD3A50CE29ULL, 0x63028D7BBC307497ULL, 0xA1F98DE3A9104DEEULL, 
            0xEC1E3C4001E6BC7FULL, 0x3FB7F84D458AC575ULL, 0x1F659DD6AE4D5696ULL, 0xFB51FE90A614E36BULL
        },
        {
            0x42DE2BA3979B839BULL, 0xC12BFDBD4A77F0D0ULL, 0x1FC93D1B3A700D53ULL, 0x096F53F2FCA507D6ULL, 
            0xD1D6AB54A601B0E1ULL, 0x79D2FFA50CC9DE62ULL, 0x4268B7736550457DULL, 0x072F23A52B2244A8ULL, 
            0x7A0CA47620AD7F13ULL, 0xB9214DC877A95439ULL, 0x4B06F4FC4725737CULL, 0x5D04C2E45040E54CULL, 
            0x96921B93518BD5A7ULL, 0x14F1B8489CDC3BDFULL, 0xB5F7A553423DE333ULL, 0x3B787CAE35594553ULL, 
            0xCB293FBBE8BAE5CAULL, 0xD2B7AE4A9DF331F3ULL, 0x8D862CB67C35FC31ULL, 0x9EC9A7B1352EEC94ULL, 
            0xA02D1CAB68D12A89ULL, 0x333D4032B54AB3ACULL, 0x40415F8788E9245AULL, 0x9767DD761F952C9DULL, 
            0x55902B3185BF56F4ULL, 0x4A44420A369F9F0DULL, 0x3E5A1386307C9F54ULL, 0x0589842638C6184FULL, 
            0x9318C5FB93201981ULL, 0xB77698E59B1FE34EULL, 0xA73CDB680CF12D02ULL, 0xCAB1D4FA6D23F5B9ULL
        },
        {
            0xF530EAA9164B5650ULL, 0x3EC0F34BC6B83237ULL, 0x27AA6516AF565A08ULL, 0x907A9C9A5B7E3170ULL, 
            0xCC22A40EAB5A3DA6ULL, 0xAB489855399A769AULL, 0xDA590E38C8BF24C6ULL, 0x286593A715BD0938ULL, 
            0x0B40C7AF12F2651FULL, 0x102F223BBEC9EE26ULL, 0xCC591B6641B17D53ULL, 0x2D966FA280B15AA4ULL, 
            0xAD13B17AD7ACC3BEULL, 0x8F731E7D3BEFBC9EULL, 0xDB6172E5F3F6D1A7ULL, 0x033F9193B9859C03ULL, 
            0xCFB1A067EB421066ULL, 0x68D709279E5E10DFULL, 0x3007C176EC6DCD11ULL, 0x72DF5EA28560BE6BULL, 
            0x9BD339DB476D6E79ULL, 0x24938D370A63F3E3ULL, 0xE4432A4F40A18EF6ULL, 0x4DDC35C7F6802CFEULL, 
            0x704C25841F02753EULL, 0xFC741A2795E5F20CULL, 0x4E8C234130F10BF0ULL, 0xC7A547F31CD7A2A1ULL, 
            0xF60CD96232DC36B2ULL, 0x522738AB79A98576ULL, 0x9540F4FFD0189C2FULL, 0x38E42BB9195716CDULL
        },
        {
            0x73F322131B52BB0BULL, 0x706418396A256283ULL, 0x865BC2C570C4C9A8ULL, 0xA52A0CF90BBF1434ULL, 
            0x0183FDE57E2F222EULL, 0xB755F100BDCAA0F8ULL, 0xCEFA647459213C4DULL, 0xC3B733BC9066BCEDULL, 
            0xC6F7D595C879510FULL, 0x7B9D4EBCD43A7CEBULL, 0xE7E0346FD8ED8732ULL, 0xB86D77C53368E9FCULL, 
            0xD96A06304D28C7B6ULL, 0x82745AF8BB58C63AULL, 0xCDEDCAC8A6A87A47ULL, 0x0F06D7AC7FBEAE72ULL, 
            0xA7F4B89A159CF4B7ULL, 0xCA59FC6DB95C46B7ULL, 0x2745B28D38FCB3AAULL, 0xCF35B969DD2B2619ULL, 
            0xE6A911239E743B42ULL, 0xBB68116C4313E294ULL, 0x1F06D4E9664AF458ULL, 0x9059D9EA673FD9DAULL, 
            0x14020DCE09E3CBB2ULL, 0x305A07547CFB33D3ULL, 0xA4A80BA6982F29A6ULL, 0x3FF4D34D039A603AULL, 
            0xC9DFC21F27BAC9F5ULL, 0xAB02F9018BFF8CB7ULL, 0x84689F63CA5B9264ULL, 0x368DD14FD12CABBAULL
        }
    },
    {
        {
            0xF23937F7C3892900ULL, 0x1B625C49DD00C070ULL, 0x403918DB72796E61ULL, 0xC795F07D89549A08ULL, 
            0xC28D76FBEDF317BAULL, 0xE93DC95B9D8984B8ULL, 0x5F1C6611B1A58CA7ULL, 0xB169773162ED5E55ULL, 
            0x5E3F1236DE5F23A5ULL, 0x97FB1AD0B72F745EULL, 0x22DCC54DB5C5B1E7ULL, 0x20BE75B74CA1E64BULL, 
            0x9F9C26480655A5A4ULL, 0x1F2FDB0735F20A0FULL, 0x295D4C66820DC27BULL, 0xE672051ADF806F39ULL, 
            0xABEFC18529E3F966ULL, 0x2DB5E12FE826597BULL, 0x69FD5EA8483E58BAULL, 0xA000E09D327C8E2AULL, 
            0xDE556164440B7DDBULL, 0x767E349C190A9B26ULL, 0x4BE72BC234B7D4A8ULL, 0xEE536E16581BA770ULL, 
            0x3A5F649FBB8B15BDULL, 0xBB7C54037160A106ULL, 0xC99B0B9921D38B9CULL, 0xF7C2CE6BFA72D551ULL, 
            0xFC3EBA976EDD67EAULL, 0x2D9742606ED4134EULL, 0x3DA1AF788DA7B03CULL, 0xDC74E49D112092FBULL
        },
        {
            0x4C24D010ECE606D8ULL, 0x43AADDB70FDC89E2ULL, 0x48CE2826937CA5D4ULL, 0x2C6A73294962AD9DULL, 
            0x6039C78B3B007AF3ULL, 0x39760AADEB5809ACULL, 0xE827F4E9F0ACAE34ULL, 0x96A0BB4682355A62ULL, 
            0x0BABFF54567DD84CULL, 0xC206BC6722AEAC37ULL, 0x809ECA6CAB87192AULL, 0xF8C5317E7BC2C3C3ULL, 
            0xFFB0E0565825A678ULL, 0x3A6D07FA7DA6A2A3ULL, 0xEED17F6C3E4FB0E0ULL, 0x741F428D838AD27AULL, 
            0x3FFF83E153163C0BULL, 0xC2A5B31AF7B8CBBAULL, 0xC7946576EC131F05ULL, 0xEFB74E31AD98EBCDULL, 
            0x2C9AE1D0AF313378ULL, 0x41070B1AC0A10899ULL, 0x013513C9011CF10DULL, 0x04FED53683191911ULL, 
            0x8FFEC61F2A9B2C9AULL, 0xA580D2255C83C8FCULL, 0xF284AB5FC9B86EB2ULL, 0xC31FF24D245A81B6ULL, 
            0x00851D12B078E679ULL, 0xD1716C73D749574EULL, 0xDBCC1EC1957CEDD0ULL, 0x60E0C411C9FDA1D6ULL
        },
        {
            0xD365107CE31C5413ULL, 0x39556BD41DA5190EULL, 0x99B3378876405597ULL, 0x8AF4767351AAD116ULL, 
            0x83CC66EC1496A714ULL, 0x0857BB4768E83DF1ULL, 0x50A0797B0B829340ULL, 0x7CFF4290D45BBBBFULL, 
            0x74DAD38EFBA5B865ULL, 0x6EF19A35B7DD5BAEULL, 0x1C2A1FEEBFB18C14ULL, 0x18B21C90CCF39B92ULL, 
            0x6E2DFE743C5FBDE2ULL, 0x66475A510559F615ULL, 0xFE83388AFFC0DE6EULL, 0xC20FE533A7DF5C2DULL, 
            0x408EFF0F3338F8A4ULL, 0x118BF94F88FFEA4CULL, 0x6FAAC5CE69E3D743ULL, 0x1092E921EBC89EDAULL, 
            0x2977EB62D072F7E3ULL, 0xB1569B1D9DBBF459ULL, 0x1101A94D01188590ULL, 0xA4904D38E66ACB8EULL, 
            0xDF9DFEA68644BCF2ULL, 0x761270643FE80D53ULL, 0x78FFADE0B1CE31A4ULL, 0xFCD6A5124295552EULL, 
            0x4559D0108EAEBDC2ULL, 0x4805FBBBB59D2F13ULL, 0xDEC523D659AD6B0AULL, 0x859B995411E883FAULL
        },
        {
            0x8EA83BF0767A4B53ULL, 0x9C70CF65BE4860FAULL, 0x1F8135736D4C7B5FULL, 0xB9AF337EF7C68A61ULL, 
            0x80FE77ECAA83F024ULL, 0x4A42EF8C8C486737ULL, 0x558172BE52871A6BULL, 0x1AE45261A700D1B6ULL, 
            0xD658700522994616ULL, 0x35213BFB9A301CEBULL, 0x9256BA28F9507553ULL, 0x325E539DE8E63649ULL, 
            0x24E10F46CA4FB0E9ULL, 0xDBF43C4D7FC96171ULL, 0xD2296DAC862588F9ULL, 0x631FE415998790C2ULL, 
            0x8B3025DE38D7609AULL, 0x82BCD1F99215BECBULL, 0xA94AC5D262B790A8ULL, 0x1B9E4FD7EBB40A3AULL, 
            0xCE091224147D0FCDULL, 0xA85B0814DDA7669DULL, 0x82EFA1B0428567B7ULL, 0xB733EF7E08343A47ULL, 
            0x1197475007D28D56ULL, 0x1B31C02CD0B06C27ULL, 0x483F23AEB889A00CULL, 0x263242517D36FA46ULL, 
            0x97215DAACEAC6058ULL, 0xEC290C95D0D66ED0ULL, 0x5CFCB7E205F30064ULL, 0x9F32DC20564159F4ULL
        },
        {
            0x08BFD129101DCCE4ULL, 0x8FC6493BB8D1701AULL, 0xA7023BB9C7E66B7DULL, 0xB164D68FC6CECC2DULL, 
            0x0908C29626170F5CULL, 0xB74C39AC64608DD5ULL, 0x04B63303272CF12EULL, 0x7D88B933D77C1F62ULL, 
            0xE856CC190BB9317BULL, 0x5C6B8127970F2A67ULL, 0xE886A0C5215B5E31ULL, 0x9F12BF068BB35C20ULL, 
            0x48D9400702AFCCD9ULL, 0x36F0DA5A83EF0326ULL, 0xF2A98301F3BFF33EULL, 0xEF04D6D0BF8E4C8EULL, 
            0x4692680511FDC360ULL, 0x937FE767144A4582ULL, 0xFEDF67E1BF18EA47ULL, 0x882FA382FD39FB7AULL, 
            0xFDAD01F214D5D539ULL, 0x0970CD6CD51C6A62ULL, 0xC0E6377F97CB919BULL, 0xE9C356C26B741832ULL, 
            0x41C64EF61B8BF3D1ULL, 0x79507B2FB209AC19ULL, 0xBCB707D7C196D42FULL, 0x54A35247738FBFFFULL, 
            0x854DEA748E32457CULL, 0x681AD86BBFB2351AULL, 0x4D5C38709942CF83ULL, 0x1C590870D34206CAULL
        },
        {
            0x7B3323BB0C9B716FULL, 0xD89EC4CC1A581EADULL, 0x01921EA223698601ULL, 0x80B6AB6008210DBDULL, 
            0xAC235B23A0C6F51DULL, 0xE3DF3B274242A15FULL, 0x21D2FAE3BFD73B37ULL, 0x47F2F4757E409024ULL, 
            0x3590A1B0C9148A00ULL, 0xCF5F6B91BD396C3EULL, 0x0CF8498B988E3D1AULL, 0x42FDAC7953945F8BULL, 
            0x3EC9E646D24C3C10ULL, 0x4AF13F01B416497FULL, 0x0A54FE17C7976E78ULL, 0x5B194834A371E9D4ULL, 
            0x62814AED8D8D2D28ULL, 0xA56F4AA461F98A10ULL, 0x2A92438CADC3FD4BULL, 0xAD9D8C91A2795206ULL, 
            0x87D31890D7C80138ULL, 0x2DE96DB9A3F54CD0ULL, 0x0CFEAC7D62002A84ULL, 0x25E059BD41D38B30ULL, 
            0xAB96505793DD1484ULL, 0xABABF5D954DECAD1ULL, 0xCF2CAC9E5B726775ULL, 0x65387FEC5841C2F6ULL, 
            0x7B59FE237E58874AULL, 0xF9AED7B5A1B690D0ULL, 0x6B19C048B516CA77ULL, 0xC5CD414159D850F1ULL
        }
    },
    {
        {
            0xAA2D346C19AF842EULL, 0x6C9780BDF0F6B25BULL, 0x814E8AD6AD719F8BULL, 0xA22CC8AC84544ABCULL, 
            0xA3C9E656DB623AE2ULL, 0xAB55E1D6545D1BCBULL, 0x07F77141ADEAA4D6ULL, 0x893CE8998BBC36D1ULL, 
            0xFBA48B09BA6E9C17ULL, 0x486B82685D48A3F3ULL, 0x5EF9072509EC9AF2ULL, 0xFF96E8384EC54EA8ULL, 
            0xE8D4F6F45226157FULL, 0xB0DED58E1836581FULL, 0x80FB36B6101B2D36ULL, 0x2CB4A10027EBF16AULL, 
            0x47DF9D7E08C73E01ULL, 0x23FF5FAA5B584ED1ULL, 0x4725E281BADA164FULL, 0x4852B445860AD8E6ULL, 
            0x36046C551ECF5E60ULL, 0x09A298E220891371ULL, 0x2305BC862C9A813BULL, 0x4A28A8E956064715ULL, 
            0xF13EA8034207AACDULL, 0x05E0537289DF9323ULL, 0xA0E43FCF3A25ACDCULL, 0xFE44411865343244ULL, 
            0xEAA7A0EF9DF034E4ULL, 0xD5A0E5EF45D96297ULL, 0xD22E34133C30E103ULL, 0x5DBB542A95E02DE6ULL
        },
        {
            0xE20FC037378C2E4AULL, 0x256C49645DF8C9B1ULL, 0xCA22C33ADD83C29FULL, 0x30A2B1AE0B91737AULL, 
            0x7BF30EFA2804F84AULL, 0x45B5CFEE9F52F763ULL, 0xE8DA201E5E5E084FULL, 0xC00CCE099F2E68ACULL, 
            0xD7E4C85148BE1817ULL, 0x3DE6BE2364BF3D95ULL, 0x5012E36381258D23ULL, 0xC79A940ACF608B40ULL, 
            0x4DA4323B1E9F10BFULL, 0xB1A1C16C25601C0DULL, 0x3423E54923067660ULL, 0x685CAFC2217DDD87ULL, 
            0xD9D1BCFC111758C0ULL, 0xD97AE4E6D294D8BCULL, 0xD5B0BE10A312FA48ULL, 0x6004446CF8BB1C9BULL, 
            0x0E8670B047045DDAULL, 0x17C41CF3A556F2B1ULL, 0x1EF5F907B0C53822ULL, 0xBFC82A50AEE58E19ULL, 
            0x7A1FD94FDCF61C7CULL, 0xB4D0CC607BA81E9EULL, 0xFB7E23E4BC8277F1ULL, 0x837DD78D48CF9B95ULL, 
            0x2C5B664AEF59C58DULL, 0xF4127D472370AEFDULL, 0x1D133B7ACF7C8919ULL, 0xCFA5E529150750E5ULL
        },
        {
            0xBAD2B5C216A77016ULL, 0x7B52C52F6F7D437BULL, 0x5B18E7C07C171A97ULL, 0x6CCC141834E2B0A4ULL, 
            0xA3F28CD100F599EFULL, 0x6DA3047F964C9E7CULL, 0xC6CD32A94DEC92C0ULL, 0x4FB8E063E8EE6D38ULL, 
            0x7552E943781AA954ULL, 0x276DD0B5FFCE8699ULL, 0xE3167F3505E067EDULL, 0x7DBEEE0D2E7CFECFULL, 
            0x685F3518FC3C9790ULL, 0xD4E8C60F308E4673ULL, 0xF45BB0D0CB228B9EULL, 0xDE862299E0F9C8A9ULL, 
            0x7062CC3FAB68FA6FULL, 0x34C54E7685C98711ULL, 0x4360D5F82C1FEBA6ULL, 0xB8ED3E6A9CCAB430ULL, 
            0x8DB5FEC1C19BFABDULL, 0xF4AE444499763532ULL, 0x40D0FA0F4EE53BA0ULL, 0xEC8974AC0046203BULL, 
            0xF52C65DD17A96847ULL, 0xE0883C663A34E319ULL, 0xB957D3CB7619959AULL, 0x1A92F11884D4AE57ULL, 
            0x8273B872F1EC4F09ULL, 0x69CE4D90B02C9E27ULL, 0xB9D80FECB64DC661ULL, 0xBBB765777D8BF7ABULL
        },
        {
            0xBF52E75F8F222445ULL, 0x0E48C0B9F6DB4114ULL, 0x4D5DA1ADF9F5D631ULL, 0x893E5F2A2E8E3229ULL, 
            0x87B8A099C8EC725DULL, 0xBB325DF20B61B878ULL, 0x786EBE98728CBE17ULL, 0x904ADED05E1FF76CULL, 
            0x1B5F809851E58396ULL, 0xF4570765F270D81FULL, 0xFAAAAF25746BD0E8ULL, 0xEC52EF2C111189D7ULL, 
            0x3880FF22F2E7FAA5ULL, 0x9F148B100131E80FULL, 0xBAD80A991A84C4D0ULL, 0x229ADCA5ABCECD81ULL, 
            0x3F1D78AEF2F46581ULL, 0x36774F546C2B22A6ULL, 0x4BDF1A82CB0A336CULL, 0xE6F75FE323217B51ULL, 
            0x889BF0BF649FEE01ULL, 0x5E69E9E0A3A854AAULL, 0xBDA88351BA9DE866ULL, 0xEFB775810B257CBCULL, 
            0x6157F14465A3E592ULL, 0x4362394981C48C3FULL, 0x4FF8C0AED7B712D1ULL, 0x568BF033CA65882BULL, 
            0x00613316AA78D1D2ULL, 0x6F5E2C6A54ED2FE9ULL, 0x5004F62A5EAF82F8ULL, 0xFB1DFD718026ECB3ULL
        },
        {
            0xF96092FB96211B5DULL, 0x969759CADA81D892ULL, 0x2B58831E069060D5ULL, 0xF9BE5DFB4442499EULL, 
            0xA55AA9C376FADA85ULL, 0x6158AC53F84EC5BEULL, 0x2BFF36D5BA30B279ULL, 0xEE5608F73EB09E3BULL, 
            0xE18FDED87482348DULL, 0xD4EE569D5530F409ULL, 0x5C6FF761F8D6DF5AULL, 0x29D5669C2FED686BULL, 
            0x26671B31E2359C47ULL, 0xA00A7D86E07635EEULL, 0x1D5A1407F88CAECFULL, 0x02F2F726EEF5850DULL, 
            0x8CC85E3F789DCFD4ULL, 0x6505DF1A03C8E359ULL, 0x3250F8857C7D834BULL, 0x32CAB70B7367D8E4ULL, 
            0x0C3A58756C26412FULL, 0xAAF10155639D3A8EULL, 0x60C6B59B4E292C27ULL, 0x09B2CCB1FD07BBD6ULL, 
            0x074B7C01E5B4934FULL, 0x8D86DFE74729B632ULL, 0xF0F7CF28012E40E3ULL, 0x2CC9E04F8A8F9EE9ULL, 
            0xEAF9ECC54D28501DULL, 0xDE79979D8066A4EFULL, 0x84E56D1B34AC764FULL, 0xFDB0DF03EF68D2A8ULL
        },
        {
            0xFDBE8E812FFFD50DULL, 0xFAC75F591FB05FC1ULL, 0xE790306317809480ULL, 0x3C282201F7556D3DULL, 
            0x874712D52ACF029BULL, 0x2D2C88E437BA0D14ULL, 0xAF05BFDB45FC5C3AULL, 0x27F5890E62E28F44ULL, 
            0x493940EBDDD54B63ULL, 0xCDE7DC58E504749CULL, 0x9BF1C9E1A86703D5ULL, 0x1A57A88436B6EB78ULL, 
            0x77C501B34C203787ULL, 0xC25B818C31E453E9ULL, 0x62ED4F57BF0A337EULL, 0x9D164F7118A5C067ULL, 
            0x8DFD4A2356BE1249ULL, 0x332EB92F7E2E4B99ULL, 0x42E0BC957946CC96ULL, 0x1FD365DB24AD04AAULL, 
            0x5DE68A72B34D9F1DULL, 0x60A7F528DA1E53DDULL, 0xE97DE33BC18C5B52ULL, 0x5409652F7EC54B67ULL, 
            0x97F4290747533702ULL, 0x0CA939FB40926A31ULL, 0x7C1E6589690A4575ULL, 0x9A0E259B5CC21F6BULL, 
            0x190761678313824DULL, 0x01552F709B2E94C6ULL, 0xF708D9C787985A05ULL, 0x9939039F927DD576ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseDConstants = {
    0x3CA74B8E134B03D1ULL,
    0xF0FDAA9C880C9C11ULL,
    0x58307F394358A6A9ULL,
    0x3CA74B8E134B03D1ULL,
    0xF0FDAA9C880C9C11ULL,
    0x58307F394358A6A9ULL,
    0x65590FCE37F760A3ULL,
    0x30CFE9368EE78597ULL,
    0x38,
    0x38,
    0x0A,
    0xB9,
    0x11,
    0xBE,
    0x97,
    0x43
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseESalts = {
    {
        {
            0x6CE03F4B798AC566ULL, 0x538E611C29EBE224ULL, 0x89ACDB22A1B9EBFEULL, 0x2953077EB2609978ULL, 
            0x4F10EC169C6C1051ULL, 0x930446BBF8F06F61ULL, 0xDDF8C3B5798973F5ULL, 0xE6AB943D215724B3ULL, 
            0x42904E88E3E91C79ULL, 0x7FA0285537690FD4ULL, 0x354B85AE394022A5ULL, 0x1A9987353FF0C784ULL, 
            0xC3CA53C1A5FCC014ULL, 0x6DF17D158F924967ULL, 0x142F8CC687583D4DULL, 0x68AAAFD343858480ULL, 
            0xD675412A8E01C131ULL, 0xC70550FEA7FC252DULL, 0xAC55B92D51020E76ULL, 0xCEBFE65043ADF848ULL, 
            0xB48B61D04EB3417AULL, 0xC2827C2E1D1317D2ULL, 0xEE35A1A21C0D01C0ULL, 0xF0EAD01FAEFCDB78ULL, 
            0xEA69936120B22C24ULL, 0x12F85D7924FDCFD9ULL, 0x957F9CC77D1650A9ULL, 0xCFD29CE05AD41086ULL, 
            0x4A326BD52C480BAFULL, 0x117857F8A0DC6B86ULL, 0xB4057D6E1D1F6BBDULL, 0x3356B568532AF5DBULL
        },
        {
            0x2302764318A85652ULL, 0x40AD31812FEFA888ULL, 0xB5C53D90BDB4B0C2ULL, 0xCCD6600DD889FDC8ULL, 
            0xE5B03984A55ED2EAULL, 0x7CA1421B90ECA8AAULL, 0xB58B4CDDC064457CULL, 0x77ED76A7E3927F39ULL, 
            0xC428519B898B5FCDULL, 0x4757CECE988CAC2BULL, 0x904945856A8A727CULL, 0xB06E2403D8D6C20FULL, 
            0x722385CFD69E1BE1ULL, 0xD318FE0A46C0DF5BULL, 0x405ED067E929883AULL, 0x96EAB3528F95C73DULL, 
            0xFAE93E2B67A8196CULL, 0x156C9AEE40338505ULL, 0x1C32AA8464ECEA0AULL, 0xC9D90E84AF00D1B9ULL, 
            0x6A004753D86A28ACULL, 0x58B7E20D634E1E2AULL, 0x5F9623B9750427CEULL, 0x59C297108DF52604ULL, 
            0x5D626C254178775BULL, 0x9709EEA3CD5F1B36ULL, 0xF787E90315A9FA26ULL, 0xF415E9338BF4B5A3ULL, 
            0x8D20C074912654E0ULL, 0x54B3B4A7ACFA56F7ULL, 0x78385866D11D6AFAULL, 0x0CF73C08ADDF1A96ULL
        },
        {
            0x8329CA163876F009ULL, 0x51273DA176C071D9ULL, 0x809174B1BB13EB49ULL, 0x84C2FADE1AD2D49EULL, 
            0x0EF446925F5F765EULL, 0xDF714736F1E3974FULL, 0x57E0FE3D55B631EFULL, 0xD3663A8E76F2FFB4ULL, 
            0x2EF26A292419418DULL, 0x5D84CEB632294F6CULL, 0x828AB31E336638F9ULL, 0xB259A1E0D9E8BA09ULL, 
            0x1E58E405024C362EULL, 0x35960FB88A2E2912ULL, 0xAADE7D082B5ABB73ULL, 0x4E894A30D84B5C86ULL, 
            0x9FE4CDB45F0A3E26ULL, 0x57B03AF35AD6F38BULL, 0xCD92004A6A1E461EULL, 0xAF076F14656205F8ULL, 
            0x757760172EB3ADDCULL, 0x5576C0DD9123AA9CULL, 0x3EF39836247BA4B0ULL, 0xE935D384A9EA340BULL, 
            0x6E44DC1484FA40D9ULL, 0x44BE722112DD8F3BULL, 0x4E72EB833F068CC7ULL, 0xDF7287AB5CF2D11AULL, 
            0x9F0BCE87C8E75E55ULL, 0x2BB00A4DB41EBDD5ULL, 0x2E1C7F17E51A5A4BULL, 0x4CE3596E205EB43CULL
        },
        {
            0xE51F658489ACF5F6ULL, 0x9132BD27A1F91A34ULL, 0x181C289FD204F4BAULL, 0x01255A8EB46DB1EFULL, 
            0x4C5482C0506B9AC6ULL, 0xD55A5CEAACD068FDULL, 0x0B595DAFB5CA5467ULL, 0xF938BF1257C889FFULL, 
            0xBCB2F9C403A82BCFULL, 0xB6CB678BF6E954E8ULL, 0x3384E1693D8987CDULL, 0xF68CA35D50F978F5ULL, 
            0x3F10E614643AD0D9ULL, 0x7760F32A9CBFC52AULL, 0xCF18C014D6687932ULL, 0x47B33627D9B67E0FULL, 
            0x21B3BA3EDA2585EAULL, 0xEDCFABBB4A988702ULL, 0xDB4DCD67DBB26099ULL, 0x104DA85D0DC17044ULL, 
            0xF954FBE736A1D939ULL, 0x3BEA729432CF1ACBULL, 0x5959871058C3C922ULL, 0x09C81CC2C863F1D9ULL, 
            0x57D1D57F000BC028ULL, 0x9740B5CD71251389ULL, 0xD8F56DBC5AF34166ULL, 0x025546D73B80D81BULL, 
            0x9F015FFE55A6D3D0ULL, 0x53F4357B517207FEULL, 0xCA0147523F6F001EULL, 0x2AF1A82A6E0F8741ULL
        },
        {
            0x5F73CE08E16FD6AEULL, 0xDF8DB902F8612892ULL, 0x49D0853869D5D879ULL, 0xAF946D07814AA3AEULL, 
            0xCF89C3C30120C72CULL, 0x7210F5EE60F0087DULL, 0x4B4CE071C6625364ULL, 0xA8300F53D1589128ULL, 
            0xBD83B8DD97B511F1ULL, 0xFD2EEF6C322AF28BULL, 0x52942E7BFDBF7DEAULL, 0x7C8571A8A8EC347EULL, 
            0x14B3E31F7DEC25BBULL, 0x0F812C3A939AC288ULL, 0x65164A4A842A81ABULL, 0x5691546DC84B2E30ULL, 
            0x36CE8E19413FCB15ULL, 0x01F62D8248DA5FB6ULL, 0xE97C536ACDF64566ULL, 0x72E8741707BD0A18ULL, 
            0x7980D3B39EC998B3ULL, 0x3A76AB280CA8EB2BULL, 0xFDDA71D70F9AEE47ULL, 0xA977BCF1A7817615ULL, 
            0x22569790E4D8C890ULL, 0x78022F22B2CF622FULL, 0xB94025AFB1811929ULL, 0x58A8C8529F2A7A52ULL, 
            0x7CCE80893E488E82ULL, 0xAAE531C73D0ABDD8ULL, 0x4421ADA351FA42E3ULL, 0x5B1E1185436E8836ULL
        },
        {
            0xCDD8D02D6C20BBFEULL, 0xC878081A7798F252ULL, 0xA10CE1A855AA49BBULL, 0x1A3BB46B0DE02688ULL, 
            0x7EF0EB2812BACF65ULL, 0x8B8DD215265D56B0ULL, 0x831D62F74B6EAF0DULL, 0xE73234DC20CDCBF1ULL, 
            0xA230B14ED05AEE8AULL, 0x92B00D192BE39545ULL, 0x31B181094E173C39ULL, 0xF8C42A92F1F4D033ULL, 
            0xE7C6F637D60724E8ULL, 0xFBEC55CEA486E820ULL, 0x241F927894FB096CULL, 0xF33B36C89DF6DE0BULL, 
            0xCA29A362B5AF8EF7ULL, 0x5CCC66591A21F36DULL, 0x2F205FC4B219E026ULL, 0xCE84E1D0A3D5DDE7ULL, 
            0xBBF51D19C11975DAULL, 0xA7405CC015E2A3A0ULL, 0x222A11228EBDC280ULL, 0x53C2B6A5F7F713B9ULL, 
            0x8A76DED0971CB591ULL, 0xA6FC85E60B0FFC5EULL, 0x83687DB865755BC6ULL, 0x89E6B1BB368ABF33ULL, 
            0xA4D8DC46B6CD9412ULL, 0x5D3F47A109F48199ULL, 0x8923A379EEFBE5EEULL, 0xF846A8E7359DE28BULL
        }
    },
    {
        {
            0x65185BD513186109ULL, 0x0C80873290CD0927ULL, 0x79B9F2C1ADD5A555ULL, 0x1C32A08921D805E4ULL, 
            0x10E7C39C41CE1969ULL, 0x465A231778E6D311ULL, 0x39EDBF9DAFD74B85ULL, 0x76C6913A489A9B31ULL, 
            0xEFC0C5732686861EULL, 0x5AE6C3E498D15C93ULL, 0x2B03C4F2AE690CC0ULL, 0x560CF3A3E17C7A8DULL, 
            0x746B371BDADB97C9ULL, 0x45EED72113AB6829ULL, 0xFFAA6B09EA8A1A63ULL, 0x89F51FD19358920EULL, 
            0x8C39EA18B3BF9DEEULL, 0xC7D452DD1C9B4612ULL, 0x35D8074782A79E38ULL, 0xF01040FB77BDD971ULL, 
            0xA416C14CFBD56D1DULL, 0x4780810DE1206EE4ULL, 0xB95729A7D1BF553BULL, 0xBF921B573C8EDB4FULL, 
            0x9BAF5FBF970AC020ULL, 0xFCE62D2CB7AF9A6EULL, 0x3CE644A8A6075AF5ULL, 0x5CF0BF7714661193ULL, 
            0xC36F9BD6B0611AF4ULL, 0xE27066E15B114089ULL, 0xBCBE417C98EC2E27ULL, 0xEEDD5EDA932A81CCULL
        },
        {
            0x822607344CE4E5B5ULL, 0xDA06A0B7193BEBB6ULL, 0x75FD71BF0474BBF6ULL, 0x846ED9689D754AE4ULL, 
            0x12F3749089AB58C1ULL, 0xC509DA7AB9256C27ULL, 0xBF06FB09B2D9C05CULL, 0xF56425DA91606474ULL, 
            0x98EB07DFDB717555ULL, 0x12845A4896FBE3ADULL, 0x9145EC3BA67A7230ULL, 0x38AC3CD16DC974FFULL, 
            0xBE898B362A2EE0C6ULL, 0x214D8E3E7D09CDABULL, 0x6CBF223A19C6788FULL, 0x58AF36108C247047ULL, 
            0x25F3BBAC4B24A032ULL, 0x2E99F9D9639873BFULL, 0xA2DED79CF05724B5ULL, 0xC256320E646C2DE8ULL, 
            0x798187FF610B6C32ULL, 0x5FE54985E9DE97AEULL, 0x4B64B5A3A4133529ULL, 0x17FB0A71A8FFA7FEULL, 
            0x1877EA03A541DF51ULL, 0x285248D19F9E3E3AULL, 0x27E45149970D2BCAULL, 0x23DA5CC765D010D1ULL, 
            0xDF1EC1E3AFFB748CULL, 0xE9FC424962D316DCULL, 0xE77A347564B5B033ULL, 0x0C8294C289AAC336ULL
        },
        {
            0xEDD8A89FC6B8D07AULL, 0x5B397390EEBF512CULL, 0xA2810BAFFF58A7FFULL, 0x8A416DE55E3CFD73ULL, 
            0xF04FEC1B90179487ULL, 0xCC1D5D398AB7C12AULL, 0xA5B433CBEB2D3625ULL, 0xA2A424C82B3FBA8DULL, 
            0xECEEB121C3EF2207ULL, 0xBC9B0921ADDDACE3ULL, 0xEBBB50CBB7ACB42CULL, 0xDF2511F55AB276A7ULL, 
            0x060070CACC725258ULL, 0x228160876415C5EDULL, 0xDE284A3E7E621DC3ULL, 0xEFEDDAD2D2B92BFCULL, 
            0x7A1AB3ABE1B8D68FULL, 0x8E75D2440F5D0B76ULL, 0x73943E8D6510AC10ULL, 0x9D4743EA309D6D5AULL, 
            0x36F608F358D99227ULL, 0x0BA5193DF1ED3139ULL, 0x6B12D4E0478C03F8ULL, 0x3CA4FB87BFA5D14CULL, 
            0x650598B463B05E0FULL, 0x80D89FCA3BDF0366ULL, 0x7DEF95BC0751598BULL, 0x17F227B3E5DB815BULL, 
            0x64A9450D409470CDULL, 0xB37A645A67938B94ULL, 0x1117DC81FBB2E117ULL, 0x9D2FB08D9A695D6BULL
        },
        {
            0x27DB8477E2580EE0ULL, 0xBCD0339081B7A276ULL, 0xEE3B56ACCDB387A3ULL, 0xC6CD9E5792646CF4ULL, 
            0x355E311E944AD807ULL, 0x7154DAD87B926C65ULL, 0x0D7B8D692C8DF735ULL, 0x1EE923391B861C0DULL, 
            0x3124F64965509DBBULL, 0x60D9CF136FFD0FC9ULL, 0xCACB5C8830C13189ULL, 0x2EC9307CF58C83FFULL, 
            0xD130790305CF2710ULL, 0xEAC023DA00B7AD95ULL, 0x4A8A9EBCB607AC68ULL, 0x204D305C086D6DBCULL, 
            0x7034ABCD4605C824ULL, 0xBA6CC15799BAC49BULL, 0xEEF83DA5F88A23D1ULL, 0xCAC8CCB66923F79BULL, 
            0xD0A56896543B3FADULL, 0x4E59CCBAFF0EE894ULL, 0xE9059CF0E0C0B848ULL, 0x4DB4D1E8C0602425ULL, 
            0xDC9775232C31D041ULL, 0x51172D6B014AC2BFULL, 0x5302CD3E3EB6072FULL, 0x62D19579CF461EA2ULL, 
            0xDE92BE044707355EULL, 0x95724B0AF220B6BAULL, 0x1BC923C27CDDA990ULL, 0x11FE40039E6EA103ULL
        },
        {
            0xB74DBF89A1197C08ULL, 0xD260E5D0C539F68FULL, 0xB88338931DE809A4ULL, 0x2ED215EC40624668ULL, 
            0xAAECE2CF1D7910D5ULL, 0xB5663BFC2DCECF5FULL, 0xE2E33AA600204570ULL, 0xF2D7667DB1E121F3ULL, 
            0xCC4634B781A91390ULL, 0xEBD9AEABBC635428ULL, 0xFC95D9399F2A8567ULL, 0x30536AFBFA34E980ULL, 
            0xCF2497A40FF8BFA8ULL, 0xD83C8F014B272B44ULL, 0x2C1FF4FFABB4510EULL, 0x2D2C5D77052F52D4ULL, 
            0xE46191C8CE335CE9ULL, 0x24FCC6BDAD928301ULL, 0xB5D671A7A1F869EFULL, 0x4CC6FFE693EE2551ULL, 
            0x60A55F1B4D7D3076ULL, 0x0379C6D4303B9F64ULL, 0xEC827DE939214446ULL, 0xB88C8C988BB13B2CULL, 
            0x0D08502D7C4E1D1AULL, 0x28A2766078D336F3ULL, 0x5393A208AED28847ULL, 0x7502C66C1D56D21EULL, 
            0x4BEADEDA56A04803ULL, 0x3FC347A4197D8058ULL, 0xD5EAFE14E6A2BC7EULL, 0x745770EFD8FC6901ULL
        },
        {
            0xEE233738AF6B94EAULL, 0xEFBE5956262A5781ULL, 0x5DFF80823FEF5F2CULL, 0x14E440724E276835ULL, 
            0x137CFC0F88C97938ULL, 0x6151E98DF75D2289ULL, 0x0D5CC2CACEF99971ULL, 0xFC1E3AA8A0578D82ULL, 
            0x4F12CF054274EE12ULL, 0xAB064A1ED09FCC59ULL, 0x65EF459708F6EC8CULL, 0xCA0706B87FD361D5ULL, 
            0xD9CF636D8174C22FULL, 0xF4C75A551A7B16FBULL, 0x5788852E74C6EB8BULL, 0xE7B3927EA94F4801ULL, 
            0x7D90BEA5B141986AULL, 0x9E423D06CA17FB67ULL, 0xDD7167E209ED267EULL, 0xACB814E7FE91FD0EULL, 
            0x655267720A2FD4BFULL, 0xE396A86F028E7DF9ULL, 0x782D0C98429DEE2CULL, 0x8641856EB606F7A2ULL, 
            0x45236AE143182E4EULL, 0x0B5478FF918CCD8EULL, 0x867EC158E3BE82A0ULL, 0x8494E1DA501A872EULL, 
            0x1A14A126E638852FULL, 0x8D6B75DC6E726FB0ULL, 0xA4FA0510CCA2E618ULL, 0xC8AF8451B12E5DBFULL
        }
    },
    {
        {
            0x85949AD0C2C97899ULL, 0x7071B2AA342B91D3ULL, 0x60EC34B89B57E2D9ULL, 0x707317A0FA72EF4EULL, 
            0xFA0C29E9E7B80DD0ULL, 0xFCCCB92F2C05EEB2ULL, 0xA2B666F7A0B617D4ULL, 0x3056D61A72BE3DC1ULL, 
            0x1FAFAAFC7CD82986ULL, 0xEE407977656D23B9ULL, 0x029EADE9F6D638E6ULL, 0xAE878538E431EF16ULL, 
            0xC3F52EEFD9FF70B2ULL, 0x2CFE267B8CCE23C8ULL, 0xDEEB81A7804D4BA2ULL, 0x8BCED57572661E4CULL, 
            0xE35C7F54C1FC2574ULL, 0xA7FBE21F7E149B5EULL, 0x984441A36704F5C3ULL, 0xF4197700DA747C41ULL, 
            0x46E8273D27EF6634ULL, 0x61E1CB58DCCDEFEEULL, 0x6065B294EC5E1079ULL, 0x7D2A2FAF7A7B7337ULL, 
            0xB8774011426E01F1ULL, 0x10F1B3317B4B4887ULL, 0x66CDA327DE07E5D8ULL, 0xC2C4679E72431086ULL, 
            0xF21DF1562C323738ULL, 0xFB63442ADCE1CDC5ULL, 0xB999AF8CA143C172ULL, 0xB918E5A4530BEE64ULL
        },
        {
            0xDCC9F1B84F6EFA4DULL, 0x276A68C88F94BB5EULL, 0xAE5A92FB1F458BADULL, 0xF6FCC3E91F8E7E4EULL, 
            0x67EB06AB236DA1A8ULL, 0xC13A629F8EF8B959ULL, 0xD3A6B154B6A78584ULL, 0x5C1E6B676672C0F8ULL, 
            0xD44718F9FEE0C81FULL, 0xC7F3F12EB30B4DA7ULL, 0x26E35C95203DC55FULL, 0xDACEE5DA631D887DULL, 
            0x0BB32F3127424BB5ULL, 0x534BC044559B4157ULL, 0x02C89D2E699BCA6BULL, 0x90FBE2E1BED7F819ULL, 
            0x50D70B50FBEBDBCFULL, 0x2774137D94B34D74ULL, 0x77DD98A189EC7917ULL, 0xAB24CEF2198A0090ULL, 
            0x7D57E8266668FF28ULL, 0xC0D2E025CE499177ULL, 0x1DE6BBED65055D0CULL, 0xF25455D334AF118BULL, 
            0x4A7ED29F19904D0BULL, 0x5AC11137F96A4E1AULL, 0x2CAA43EE56A76A10ULL, 0x376548FCE15313C4ULL, 
            0x666EB52A338F8175ULL, 0x95F491F2FF621DB4ULL, 0xD8A70A05D0E26A72ULL, 0x81866520BAB3B95BULL
        },
        {
            0x821C726A3EC8E4B6ULL, 0x5298C8CF90FE2603ULL, 0x08AA653D2A5784EBULL, 0x075C10DDEEFB72F4ULL, 
            0x879E0A4E0D5C6D91ULL, 0x9F2B34D88666D01AULL, 0xE1011ABC11C8A468ULL, 0xC5FA22C652931D0EULL, 
            0xD01187E13B6FA6F5ULL, 0x31FD888CEF97E3AEULL, 0x91CBCF1F489C3E6EULL, 0x30EA1D8326E97A59ULL, 
            0x17E59E01F0FB40A9ULL, 0x2D38E592CB5F5104ULL, 0xD4A8E541E6CA0E14ULL, 0x969B05A69F9ACA6AULL, 
            0xAD49C2D3C630AB8FULL, 0x7287FCD9C299D4E8ULL, 0x0C22387E46EFE0E7ULL, 0x5C71807542D43195ULL, 
            0xBA69B0B6863C0D3FULL, 0xB7DC25DBCC2522B9ULL, 0xDC5DA28238463496ULL, 0x7E969A05563BEA06ULL, 
            0x97DF0C5C827CE5D7ULL, 0x637BEC2BD7C1A270ULL, 0xC3016A5E29695074ULL, 0xAB11FD5247637C52ULL, 
            0xDAD07EC5C097E7A9ULL, 0x5ACB424C4A7D9E7CULL, 0xDC5356303A6709E9ULL, 0xA1AC5D0CA6B20AB9ULL
        },
        {
            0xD8EC8C7955270932ULL, 0x9265EC9FAC2E4BDDULL, 0xC81769A1C10DDE2FULL, 0x8D87F0C9F3308A09ULL, 
            0x18CBA946FD168604ULL, 0x1F4789B952534388ULL, 0x47402D90FFF8C2FDULL, 0x2B10CE9B42DC6CDCULL, 
            0xC7CE1023DBA3519FULL, 0xE3CD2B55AA68FDA5ULL, 0x0B1FBD553A1ED345ULL, 0x5C387646B124D889ULL, 
            0xF60F7BFD09BA28B8ULL, 0x7B1214403E90E2CBULL, 0x498BE8F87FDF93F9ULL, 0xAAA3691BC26B3626ULL, 
            0x7F91B70C90FB8754ULL, 0xF792099A0883CA84ULL, 0xBDFD1368D8581F38ULL, 0x3085F2C7E355D68BULL, 
            0xFC9A17EC2DEA2DC0ULL, 0x49B6B447560214CBULL, 0xE8213769D785B881ULL, 0x57C13D9E68AB935BULL, 
            0x432865CBDEE20909ULL, 0xFB424695AABC1183ULL, 0xCA64285873F8B2B2ULL, 0xBE9B3796B9B197A1ULL, 
            0x39BACA5456C4F622ULL, 0x326897BDE4020D84ULL, 0x08832B361B13DAF0ULL, 0xDCDBB676E6CFD675ULL
        },
        {
            0xEDD8B80E6264297FULL, 0xBB41046A2D241210ULL, 0xDF795C5B82435C81ULL, 0x2B69D46228826180ULL, 
            0x620E2201A36EAFF4ULL, 0x4832D44677DDA8D7ULL, 0xCC35B1E6CEF0D096ULL, 0x3A6B99E4A25874B7ULL, 
            0x29DB6033D935D0A3ULL, 0xA6253952C88EA6A9ULL, 0xAEBC3867BE96EE22ULL, 0x6C86D4E7255A4D1DULL, 
            0xDABD31D3C0463789ULL, 0xE8DE91534A318A73ULL, 0xD60185173F3839E5ULL, 0x5F2CE32839CC4CDEULL, 
            0x342A393FBB8F4F18ULL, 0x70D2B01D4A12B718ULL, 0x27A6D21F123B4440ULL, 0xB2227FE11444118DULL, 
            0x3DCE23177EFDBA52ULL, 0x1EE27227EBA3D4F9ULL, 0x0AD8AD33A4D4A75EULL, 0x8D6171A4921CADFEULL, 
            0x0262B44C0106AFD6ULL, 0xF79615000F86FF04ULL, 0x730AF0DDA2F25FA2ULL, 0x29A2C5FF060819B9ULL, 
            0x7138153E43CCE684ULL, 0xE31CF1478E1050A4ULL, 0xDB5A742DE85BE790ULL, 0xB74AB5520DC22ECAULL
        },
        {
            0xEB227FF94998CD9DULL, 0x63C72ED6F624495CULL, 0x9861EC3C2479CDCCULL, 0xAFE39F97E4DE8C24ULL, 
            0x97387AA0C9519067ULL, 0x1D1FE57C7BE89FAAULL, 0x369470D8D16483E0ULL, 0x068ED68DB6EE955AULL, 
            0x374BFD2A8F31B49DULL, 0xE6C903697D47F079ULL, 0xFFFAA264DD790FF6ULL, 0xFAFA2FAB9E8DD667ULL, 
            0x3678B34EFE63B705ULL, 0x2E892F0A6864E208ULL, 0xB226B56A6C72B1BFULL, 0xD9897794977055B3ULL, 
            0x951EB172D3451DFFULL, 0xDDFCC06DA8FC4F3FULL, 0xAAD6F3D9943C3E37ULL, 0x9C88DF8B44588296ULL, 
            0xD0A140B6A762DA83ULL, 0x571B387A00E957DEULL, 0x019FCF9C4FF67829ULL, 0x326BD0F29D5AF6D3ULL, 
            0x84FAC1B059F25013ULL, 0x3D66CB89BCE45745ULL, 0x9FF9FA7EC3DBD33FULL, 0xBDD021974679401CULL, 
            0xF81BF00120EEEC4FULL, 0x8ED974A61379FD47ULL, 0x8BD48C43836ADD33ULL, 0x880307094155806CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseEConstants = {
    0x0B6CF6326121F3A8ULL,
    0xEE183EA95EC60128ULL,
    0xDDB286207AFA1746ULL,
    0x0B6CF6326121F3A8ULL,
    0xEE183EA95EC60128ULL,
    0xDDB286207AFA1746ULL,
    0xA904D60FDE50BB9DULL,
    0xF2D0150C0258FF73ULL,
    0x7B,
    0xFF,
    0x5F,
    0x17,
    0x1E,
    0x06,
    0xAD,
    0xBA
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseFSalts = {
    {
        {
            0xAB7A558606152DB1ULL, 0x81FFD2E4D001D3D3ULL, 0x5D6D7973AEF8C76EULL, 0x9337E3671F3B0779ULL, 
            0x8381F1493F32ACD1ULL, 0xDC2419BB74AEAC6AULL, 0x0BD081BCFAC2A222ULL, 0x5C4B4385389F0DFBULL, 
            0x1076D385A06AFBD4ULL, 0xF40144B8AE543DCCULL, 0x4542AA917359D510ULL, 0xD9C7E701A8B00F06ULL, 
            0xD83471B962FBA479ULL, 0x45E9588DC4808E2FULL, 0x9F964EF15423CC57ULL, 0x43D7FF9CC49661C8ULL, 
            0x6EAA62F70FD61B70ULL, 0x31FE5C0E783FBCDDULL, 0x3066B62F4E118665ULL, 0x0E3CDC99B169FD68ULL, 
            0xBF099C9DDC1492D3ULL, 0x41EA3E65DFDAA58BULL, 0x7077D2CB1A64DE10ULL, 0x56E158CDC9BFD796ULL, 
            0xC9085FAF38CE862EULL, 0x6A97F1EE055359B1ULL, 0xFA41565C29B5FB6FULL, 0x205E8161CF6DE7B8ULL, 
            0xA60D78E5388F363FULL, 0xE12A4AC2C253D492ULL, 0x252929488ACD8CB5ULL, 0xAF1FB9CA99AB2E36ULL
        },
        {
            0xAA7973EE4CDDAC1EULL, 0x7A97249234C36326ULL, 0x348A3CE81A151314ULL, 0x03999C2AC936BF95ULL, 
            0x46A500317DB5DF8DULL, 0xC74C2C9D089D8D42ULL, 0x4F1A4F8EE9CAE1E4ULL, 0x5DA5EED8D91B236AULL, 
            0xEC4CAEA40BF6DF9CULL, 0x9E9728CA8F7BE184ULL, 0x9BB875C24AC5C900ULL, 0xBEA8CE7C5888429AULL, 
            0xB5C80858F8FD8F11ULL, 0x23658E31247035F9ULL, 0xBB5EF4F23C2B61EDULL, 0x79B248014E07D01AULL, 
            0xED15EECDBB346BF3ULL, 0x2B3354FDD4742686ULL, 0xDF32E5FC31D2E4EFULL, 0x1F16F488C436BE93ULL, 
            0x3A5B82EE33017B73ULL, 0xE20E25C70D04D118ULL, 0x4764BB4346DF3F7EULL, 0xD1096ACFBDFFBFB8ULL, 
            0x52E787AB661A16C8ULL, 0x1EEEB7333EB47D3EULL, 0xF80E9FF1029C844AULL, 0xF212E09A356E27D2ULL, 
            0x74D35C2FAFC185C7ULL, 0x9F1A598A7138AAEFULL, 0x895CD0F2C0C3DEDFULL, 0xDFA0D47ECA3EA1E5ULL
        },
        {
            0x7E12B84ECA2E1D87ULL, 0x7DE90DBEB6F74863ULL, 0x1F6E923C6F317710ULL, 0x0A11D3E4A99E86E5ULL, 
            0xEEA6B36F50AD6A1BULL, 0x801254E020D1C236ULL, 0x0411ADA98A1D5C09ULL, 0x2C8C5ED014CF3569ULL, 
            0xCEE2ECCA8B3CEB58ULL, 0x7EC91A3DFA0BDD3FULL, 0xFAA3006CA9F2DCFAULL, 0xC58EDC8BC06F3CEAULL, 
            0x3411BD0950CE68C3ULL, 0xF5DA49CCFF2D1603ULL, 0x52BB2173FE550F68ULL, 0x45AE958C851ACC3DULL, 
            0x76298062EC056888ULL, 0xB2870281C74E1C44ULL, 0xF29D68D371F9BB15ULL, 0x5A1CC15A7486B500ULL, 
            0xFC7F817AB3061737ULL, 0x723F90A65F1E0B51ULL, 0x493DB0D95713CF0AULL, 0xE733AE2F7B0B38A5ULL, 
            0x34F62D8FB5E591C8ULL, 0xC57F777D9C8316C0ULL, 0x50478ED0D56B8488ULL, 0x83EF255087122A79ULL, 
            0x3FCDB21B97BC0560ULL, 0x85C11FF81D8A3791ULL, 0x0C4BAE06A4CADB93ULL, 0x54457B1EA6CAD242ULL
        },
        {
            0x5E9C6AC07440519EULL, 0x8031A253A8299052ULL, 0x600F3CD9599E11DEULL, 0x51AE73ED835B9B33ULL, 
            0x962F10EA551793B3ULL, 0x52A2B07DC7FF9D03ULL, 0x5B1E55ED86E8187EULL, 0x1F77AC058A24042DULL, 
            0xD865AE80DAEB8E28ULL, 0x7F252B48C5E7C7D8ULL, 0xCEBEFCCFEC65490BULL, 0xE749CCB9BAE8F3E4ULL, 
            0xDAA10CC46148C813ULL, 0x347AE6465B0D1A7CULL, 0xFA6537280CC146B0ULL, 0x0C107CFE83DBD071ULL, 
            0xAB1940A995C1A699ULL, 0xD52C7F9EC77E9165ULL, 0x7E4E66FB31AF8DD4ULL, 0x57B9D29BD7B90CA2ULL, 
            0x96727962579C4806ULL, 0x3F47E1202EF3A35FULL, 0xD60B38EF385A4C14ULL, 0x3F58D8B323D188C9ULL, 
            0xEDD2D90F46CADFB7ULL, 0xFE8950A4CE079CE5ULL, 0x02A3E61801D6AA21ULL, 0x7879B928D2260F1EULL, 
            0xB9F993DE16AFA23EULL, 0x97B56ACBFE4F81BEULL, 0x9BDB67C5F9B623B9ULL, 0xDEF60DBCD4076C10ULL
        },
        {
            0x5F52B056CA661CEAULL, 0xFB2E3579E6EB0F3DULL, 0x42348B8DB9A40E43ULL, 0x028A7C436937FF2FULL, 
            0x17879E5746176DF1ULL, 0xFABFF2666176D26FULL, 0x8F43E96A0EE29E78ULL, 0x708D489E965986D2ULL, 
            0xDAD6D3536F08254FULL, 0x86BC7951B38C43BAULL, 0xD5D61ECDF0DEDB5BULL, 0xFF03EBABC4584E95ULL, 
            0xB313573270B92382ULL, 0x6F1B71332FCADC4FULL, 0x7AE71F9DF9F0978EULL, 0xBF0DC07F881F6E98ULL, 
            0x44908C4E2B43C9C6ULL, 0xEDC5063FA5E9D835ULL, 0xD1769D0EEC34A7D2ULL, 0xB6610E062ADE22D7ULL, 
            0xA485168A8381DD43ULL, 0x931DD8F20E8DBE0AULL, 0xE05786A9C7097E16ULL, 0xA1EEF34B1F3F4320ULL, 
            0x31C7DEE272C6B771ULL, 0x711A93D941B37717ULL, 0xC3270EA779154608ULL, 0x908C36E5E9DB13D7ULL, 
            0x728953BFC32A01A3ULL, 0x006DD6587B0458ADULL, 0x2223B9CBA3000BFFULL, 0x0AEB960C9DD439D4ULL
        },
        {
            0xF2D1E26439780A1CULL, 0x01FB1CE250FCF224ULL, 0x5E6660AE1139536FULL, 0xCDD74B4641B67B8BULL, 
            0xC09F9FB00A42DD96ULL, 0x50CE521DA99E04B9ULL, 0xBE1EF2701C7BDBDAULL, 0x2FB2E510D741F308ULL, 
            0x93D3E4BE3E9828F8ULL, 0x4C5D93F48AB146B7ULL, 0xF980FCF123D15FF3ULL, 0x89BB53EF1220ECCFULL, 
            0x92AB738EE331B179ULL, 0xA4EA2CAD535CF434ULL, 0x88CF31558CA48943ULL, 0x1241FEAEAF88577CULL, 
            0xF062882EB05EFB82ULL, 0x39041F85C9E07B18ULL, 0x1F59A4CDD0398071ULL, 0x60B564DD251A3DE9ULL, 
            0xB9547252B588BF94ULL, 0x2E0A1E8BA88102A9ULL, 0xD3A9C267B35B79C4ULL, 0x22C8D062E7C17195ULL, 
            0xEDA4F3E67FCDA699ULL, 0xB9C580656A493017ULL, 0xCF9B84EB47ED4652ULL, 0x12671297123F3695ULL, 
            0x557A1E7F5F83D852ULL, 0x4AC18B585BCD2C95ULL, 0x4352C66F68DCE50BULL, 0xAEAC58DE9A737DE5ULL
        }
    },
    {
        {
            0x847EE7977126F28CULL, 0x32BF018F9EB3F26FULL, 0x5F242CA400004FD0ULL, 0xE233E76349F5BA2DULL, 
            0xDC95122EC7CA5D84ULL, 0x227573C94F8EC5DBULL, 0xEA6252C369B13F9CULL, 0x5E2823717BDFDAAEULL, 
            0x3E1D8587F06D15C0ULL, 0x1717391864A4F45FULL, 0xE2AD8EF19858EE48ULL, 0x81E652E26E11662CULL, 
            0x8B6F15B3098F5EA2ULL, 0x1E796B4591FC5ADEULL, 0xF00966E4AD284564ULL, 0x3F3A5312EBA1DD72ULL, 
            0x53613DDDA224D90BULL, 0x6BEB87369D4E003BULL, 0xD015C925ECCB9E1AULL, 0x2F4162C282C9E515ULL, 
            0x0308E78E01481449ULL, 0x89A57C96EF3AC9C3ULL, 0xDBC72798638CDDC0ULL, 0xA4F5838E2E2D3C6EULL, 
            0x9553C53CB7565DDEULL, 0x1239524743DD4074ULL, 0x85D826B78E80B042ULL, 0x6FEAA5EA2756E50EULL, 
            0xB80BAFA3EDC98EE0ULL, 0x2CEAFCD02EFCFB3CULL, 0xEEE397BEF2BB34F4ULL, 0xB5BC37B86C25E898ULL
        },
        {
            0xC86B6517221AFB8EULL, 0xA2CDDA03CAEFD8BBULL, 0xD1FE4C15E34BFACCULL, 0xE2DBEBCCCC589484ULL, 
            0x1BC0B698A5450142ULL, 0x3BBFFE54F2BD2E9CULL, 0x1FB55665A0DA41C4ULL, 0x96248A6347B15D89ULL, 
            0xF9B2C4DFF3E4C0FFULL, 0x2BE140CCBB519CCCULL, 0xDE8ED787F254EDD8ULL, 0x5C648E397B812BE4ULL, 
            0x7F226702158297ABULL, 0x4461A98ECC1361C5ULL, 0x7D9A16A33B8A64A4ULL, 0x6D260A73BC399D31ULL, 
            0x3D8641F085B79A30ULL, 0xE807D21BCC20FC6BULL, 0x3127330C86A03046ULL, 0xF6050B55306ED9B8ULL, 
            0x80DFEECA43EFF617ULL, 0x7BF53A0F2374EDAEULL, 0x584D0729D8844AD0ULL, 0x8574315CCB6E2B8BULL, 
            0x58F59E8CEE401B96ULL, 0x3FB5F2C9B9EE498CULL, 0xF065CCB531F86EA5ULL, 0xC1523EF7F9784E9EULL, 
            0x6774A587BEB2D87FULL, 0x2EDBF2C921A6835DULL, 0x40A0D6AD3CDFE698ULL, 0x4E6C4990F9243F36ULL
        },
        {
            0xC159D7E86826D41DULL, 0xE561233863D404BBULL, 0x7AB21CDDCED44D0FULL, 0xD25672BA03D4EE52ULL, 
            0xE3D6E465007157D9ULL, 0x9763C042AA5C5A5BULL, 0xBBD413F1DAEA8202ULL, 0x19291EB5402BFEC0ULL, 
            0xF26941C286E73EFFULL, 0x044E45209BE0B412ULL, 0x9799F68A03397D06ULL, 0x58BEC00D58989872ULL, 
            0xFA773ABD9844E5CCULL, 0x7993E8E8A1ED641EULL, 0x6466DB9040230FF4ULL, 0xDBA360AD08FFE2B0ULL, 
            0x1A721BF7D0B2FB70ULL, 0xD9AFCC52EC906064ULL, 0x469F6AB8A9C7FDACULL, 0xF5D0D319EFD8EFE0ULL, 
            0x706659A79847D417ULL, 0x69BC4D8C5110CB17ULL, 0x1FE90F05FCBA5FF1ULL, 0x5C849DD98E7B399AULL, 
            0x5AAD8A607B8F56BCULL, 0xDC630E229EE8FBEFULL, 0xE5D3D98575467A93ULL, 0xD4B0A4D3653DBDAEULL, 
            0x9C337996CA3AE8C7ULL, 0x178535A20E077D51ULL, 0x554A4F7D2FEB27ADULL, 0x969D18B2FAFB3919ULL
        },
        {
            0x81579AEA42F27CE3ULL, 0x3447145B4457ED3FULL, 0x5FF6CE33ECE86785ULL, 0x325712AB7F69872BULL, 
            0x3A1F4E3F813B2296ULL, 0x54EA6D0B4533DA80ULL, 0x39DABFDC5D5BBBE0ULL, 0xFA30046C5536B0B2ULL, 
            0x5829B6219C857E67ULL, 0x3E5067DEF8FFA614ULL, 0x460B15C0B2F19516ULL, 0x6EA53D6CD393C547ULL, 
            0x117F4B3971164D5DULL, 0xD695A4A686D142D3ULL, 0x5DDC05E60911363CULL, 0xB8B00DA7D59BC6C8ULL, 
            0x1DAD151CC713FAADULL, 0x229E9D21AF882467ULL, 0x5A9612562323AA06ULL, 0x06110E7AAFD15A8EULL, 
            0xDF8A6DBB21CF2FEFULL, 0x305DD09B258EAE8CULL, 0x91BD2E1586E44021ULL, 0x70F406253E76A5D8ULL, 
            0x3463339BD2546D42ULL, 0xD9386838D067AFACULL, 0x3B8264BE0DD34EAFULL, 0xACEEE5EEA5741404ULL, 
            0xD541FDCE53C8B5D2ULL, 0x6D12E0D7747BF204ULL, 0x03C4894F566997D2ULL, 0xE08ED3933C47A6EDULL
        },
        {
            0xA7BA0D1948FF88A1ULL, 0x90DF7BFD8E67C680ULL, 0xA85D6707F76D65E0ULL, 0x3269B9396B7F1927ULL, 
            0xA9778F814F844A7DULL, 0xC9F61C0E415D6BA8ULL, 0xC56FBC801D1E217CULL, 0x6168019D9B8ABD1FULL, 
            0x9DC1E2044EB2554EULL, 0xB42C67792CD8523DULL, 0x9ECF6FB257776326ULL, 0x4D2092199EFDA07BULL, 
            0xA2C72804D3039389ULL, 0xDD8CDB98F059878EULL, 0xF28D8CAB52AD40F2ULL, 0x4C35FB4ED997F981ULL, 
            0x1AF00E7DF3E5C787ULL, 0x6C31A0EB5CAA644EULL, 0xD65E5F9BAC453D10ULL, 0x3DCAFF4BE19C620CULL, 
            0x6D15C876036EA9A2ULL, 0xACADDC1711171F9BULL, 0x2C2E2C89F4A529D9ULL, 0xD2EC96567DBD985AULL, 
            0x0C78BF7DBCC03F50ULL, 0xDF37710E09A43E7CULL, 0xA211A25ADCDA3E8AULL, 0x6D89FF74925DE4D4ULL, 
            0x9D17D3DE2A9AA302ULL, 0x46AEC711900127C4ULL, 0x15E9E3C2CC9F392DULL, 0xC0C742EB53D47B17ULL
        },
        {
            0xE7EB10226DD9E9A0ULL, 0x11F8327D24955742ULL, 0x1971C5E443CD7B9FULL, 0xE7929BD25F7C18C9ULL, 
            0x2F8D057709035F10ULL, 0x04B70E822C4BD6B3ULL, 0x6BCA294C7DE1230FULL, 0xE2530F8B191F9462ULL, 
            0x69F677B9351204DDULL, 0x952BCC0745B34004ULL, 0x7FA6E12CBB885FF7ULL, 0x5F071082F0C0CEDBULL, 
            0xDAABF4BEB939D590ULL, 0xBC06C4649369AA8AULL, 0x1E697232854B0B7EULL, 0xCD7DA8CA5D3EAC1EULL, 
            0x6F80DAAF12BF529FULL, 0x26CFDD743DBB4416ULL, 0xC256A2FCC84BF230ULL, 0xA84314F52EE04782ULL, 
            0x21DDD1B1ADFEC5E2ULL, 0x6D45F40EC59C71CCULL, 0xA05F89FEF821D98DULL, 0xA0793DDA02271104ULL, 
            0x64090F226C3D2D0BULL, 0x263EE515395287A0ULL, 0x1BB6CC64E5F1A146ULL, 0xF1DCC5E7297C9338ULL, 
            0x325C8E40E4970C64ULL, 0x484C03AB637DB129ULL, 0x4598442845DF2723ULL, 0xA2021312B33F74B1ULL
        }
    },
    {
        {
            0x60A66A55CF001FEBULL, 0x32116ACE76AC2A45ULL, 0xF007DB9D9EA00B1EULL, 0x90016712742CB266ULL, 
            0x9C9C85C6AB7E980DULL, 0x6238C021B102D3EEULL, 0xD6CE19F50E1108B5ULL, 0xC194BC47AA5C6A19ULL, 
            0xAD7491AF97A346ACULL, 0x6A34B87B180421FEULL, 0x1414A908011C9B00ULL, 0x858611A9808791D4ULL, 
            0xDA2D9606C16DCC36ULL, 0xF9ED82F2A943386BULL, 0xCF239DAED163966DULL, 0x5A48624391C3C8EEULL, 
            0x884A63366E59761FULL, 0x940D45F2C7160630ULL, 0xA39422BE0081A05AULL, 0x594233E74600B279ULL, 
            0x70046AA4FCF953D1ULL, 0x8EEBC18B13D10309ULL, 0x05A9253439FC6024ULL, 0x50875634258509C2ULL, 
            0xCABD850300459E01ULL, 0x5A8F6CE74CB95841ULL, 0x3CB07168749338E9ULL, 0x383EB7705BB1CF14ULL, 
            0x1B70C6E5A6793DC4ULL, 0x7F18CC75F3B449DDULL, 0x7FA40A3A81C007E2ULL, 0xEB8AAB35BAD89CB8ULL
        },
        {
            0x1BFDA8B75332092DULL, 0x21411DC2F5DF9B71ULL, 0x5DEC18CC8BA966DCULL, 0x0E34D2E54745FA8BULL, 
            0xDC59046EBA6E9418ULL, 0xFA85B3406E6A2305ULL, 0xB5D3604C56B8932CULL, 0xB986292E6A71F3CFULL, 
            0xD769C0B41A3372FFULL, 0xEE6F044D65B0D8EBULL, 0x6335E3AA1A5188A9ULL, 0xFA8D3E3D3C859130ULL, 
            0xAF5B5FE93BFF9EF5ULL, 0x5CE540AA08C1BBE3ULL, 0xDA8F78A4496775C8ULL, 0xF5FA299DA091FBD9ULL, 
            0x17B5C232AE6A599DULL, 0xC9E5990E168B76D9ULL, 0xE64D34951A5E6F71ULL, 0x69021C9E5A9CCFE2ULL, 
            0x4E27BFC4A00531FDULL, 0x36DF63E33DBB2C9DULL, 0x096C3C5BCAD88F98ULL, 0x48ABAAC5B3DB5844ULL, 
            0xEDC146BD0513F4F5ULL, 0x9165B85119267980ULL, 0x041999055EAA94D2ULL, 0xD2807BCA9F813CE6ULL, 
            0x9A18F64E7B6190C9ULL, 0x676E9A7015812E22ULL, 0xAE77B04EF2A0E334ULL, 0x972B70CE3347603BULL
        },
        {
            0x9D69832A02603CD2ULL, 0xEC34D2178F96A229ULL, 0xB3147D7E7D658376ULL, 0x46217AEC7541A64CULL, 
            0x2E9654E90274A591ULL, 0x3D09CBE08B8867A2ULL, 0x4BC52F9CBD29FB03ULL, 0xCED4F5BE31D1C902ULL, 
            0x2723CA60F1B8CE21ULL, 0x0043C55321CB283CULL, 0x8237334B29AF0363ULL, 0xBF12B8CD2F6E50E9ULL, 
            0xF75A2C018A9DBA3EULL, 0x4FF0E10500629656ULL, 0xF50F567E8D8679ADULL, 0xC88CD99C46FBBEC1ULL, 
            0xC5B67342E7E0583CULL, 0x145405B300D64410ULL, 0x1AB36E2FD46CAF3FULL, 0xE43EE7D01D7E5435ULL, 
            0x66F031ADE6404C27ULL, 0x4415EEB97C80D97DULL, 0x8DE0B8653F7E31ABULL, 0x7FA31782079C57D7ULL, 
            0xEC71DC5DFEE68706ULL, 0xD83E5FE62D41ECAEULL, 0xBB855E98FCB4F820ULL, 0x12E3AAE1D7CE1B52ULL, 
            0x3FFD85F573FBAE5EULL, 0x3215A83820C8590CULL, 0xE83B33667E96CBB3ULL, 0x9DEB877C1C890947ULL
        },
        {
            0x9BCE00068A4AB353ULL, 0x9B9405F48409633BULL, 0x7F81F1ED01A885EEULL, 0x16346DC3DF9969E9ULL, 
            0x80038E7FE578ADABULL, 0x7AE6D581584B949BULL, 0xE538BB6A02D94FA9ULL, 0xC53C689EDD817477ULL, 
            0x4CA0C63C88840D2DULL, 0x036290BC7063BD0CULL, 0x58E44B180F3ED406ULL, 0xDEA33134BA8FF257ULL, 
            0x71A64EEC4899DEA1ULL, 0x506A18CEEE4092F7ULL, 0x83136549073F8456ULL, 0x1C674D5117E5B592ULL, 
            0x7C1F6D0BE423A087ULL, 0xB02C335C825BAA5CULL, 0x5E06D77F101E05CBULL, 0x99046BDF8D4EF912ULL, 
            0x227150D944BF739CULL, 0xA77423203839B682ULL, 0xF5A42B81C5E14F16ULL, 0xAEA76BC67745A943ULL, 
            0x612563A687A99A3DULL, 0x1A890F0E3FE4F34BULL, 0xDE136A1B10D872C2ULL, 0xB0BA67836DD68245ULL, 
            0xF46520F84884EE3AULL, 0xA27E5FEFA8D30393ULL, 0x3E533A838EB0EFC7ULL, 0x49BCAE99E0168263ULL
        },
        {
            0x4E0CE5430425C6E9ULL, 0x5E9D592E91A74BBFULL, 0x1668FA71CE5B82CEULL, 0x5367705E11DAD9F4ULL, 
            0x173A92013EFEFE18ULL, 0xB9FB5D58AA826877ULL, 0xFC916EAC41E3CD83ULL, 0x841D13953C47AE15ULL, 
            0x48FD6292C0016C22ULL, 0xDF11F371FA0A9DB8ULL, 0x9A29345D0A6CAA9EULL, 0x1BCE24573090061EULL, 
            0x701736803889A58CULL, 0x6EC52FE8BBD10845ULL, 0x690D3FF953BBD33AULL, 0x2BF1511ABB41329BULL, 
            0x7F15918CAA10E293ULL, 0x8DCF0E6CF021936CULL, 0xF6705AA753236DC4ULL, 0x1CF1F4C23DAEA227ULL, 
            0x077F35632462F420ULL, 0x17B5B2517D5DA87BULL, 0x2FE17077559F8BFFULL, 0x7AF9BD389B317879ULL, 
            0xFC6E7F98D09E8AF2ULL, 0xD7F69F3B2724FF78ULL, 0xEE56AC9BDCBC988AULL, 0x14C09D8BF004B41CULL, 
            0x5F4A6AD8D816E500ULL, 0xDAEB363AC7406814ULL, 0x06ABA889099BD30DULL, 0xCF703D3B56C5DBBCULL
        },
        {
            0x73938672C404EF57ULL, 0xAA60A18D10E008F2ULL, 0xF2384C1722AE550BULL, 0x4BB2061B49A283CEULL, 
            0xD7F1FCDF51066432ULL, 0xBB6BD7E5A1B38C62ULL, 0x2CC09F515C1328EFULL, 0x2BF5169E83380356ULL, 
            0x6D54E7BC7779E1DFULL, 0xE9A5C783792F6172ULL, 0x1D357C7F64B6C383ULL, 0xEA23206FBDF8D91CULL, 
            0xB4945C778E33DE69ULL, 0xBE362596B09A47B2ULL, 0x0868BE594445C7B9ULL, 0xBE6697540D04FD6CULL, 
            0x10EA5F7D43798042ULL, 0x7501E662D6BA270FULL, 0x6278E07FB4E0EE90ULL, 0x23F3DB3BD94FC12EULL, 
            0x47ADD91D2F6E1DF4ULL, 0xBD83E0E79A0A7281ULL, 0x6FD0ED018CF7D3CDULL, 0x2F8699ED7656B469ULL, 
            0xE8047D19F6AE1B40ULL, 0x2B661B80F70C8E57ULL, 0x68A9E497AF2FD2D2ULL, 0xDBE3125033A45AF8ULL, 
            0xDC7ED3EB0F4F925CULL, 0x2EC2A6C73C9C92E0ULL, 0xE1D691857E7E91C4ULL, 0xAD594368992D0081ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseFConstants = {
    0x57B503FAD42D8E02ULL,
    0x165FE7E7F0A7D510ULL,
    0xD8F48FEA3327E5DBULL,
    0x57B503FAD42D8E02ULL,
    0x165FE7E7F0A7D510ULL,
    0xD8F48FEA3327E5DBULL,
    0x6981AB27624FFA21ULL,
    0x5FCBAC0D7EA04D98ULL,
    0x4A,
    0x04,
    0x2A,
    0xBE,
    0x3D,
    0x09,
    0xB8,
    0xB9
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseGSalts = {
    {
        {
            0xA206A30E80BAA542ULL, 0x58F9E91ABE30959CULL, 0x7AFB708DD13D2356ULL, 0x089E22C3A90E1C16ULL, 
            0x12F098499A185A82ULL, 0xDAAA878B23C7AC35ULL, 0x366D9BCD78368504ULL, 0x543DF60AC670EDF6ULL, 
            0x06F7D065B6F27632ULL, 0x7B5D196EB34BA48EULL, 0x0935B6E78F4277DAULL, 0xC15201A0F0617F0BULL, 
            0x52DAA87C1BE9319AULL, 0xFA65611C82E754ABULL, 0x89AD1E730F94701DULL, 0xA5598A91D3125885ULL, 
            0xE782AD400442C953ULL, 0xA51F42FB24DE3618ULL, 0x2DE9487CBF2D0B6AULL, 0xCC9145C8C2C90218ULL, 
            0x339F18B98D3CA60BULL, 0xFDD18EA2AC72D5CCULL, 0xD202D1D28FFF48FEULL, 0x252CFF7D72440E2AULL, 
            0x50CBF8C200CC1900ULL, 0xA5189DF88BD54D86ULL, 0x8BD8A1D010F177C5ULL, 0xF1AE42DE8D87CC58ULL, 
            0x2D3BEF2ED3D061B5ULL, 0xAF92F88F245AEF90ULL, 0x13F51C992F25615FULL, 0x5DE526348FB2DFA6ULL
        },
        {
            0x2705020D9C6D8C52ULL, 0xEA77D0BDBABB6BBBULL, 0x27D83ABBADCA8EB8ULL, 0xCF547C568A0FA54DULL, 
            0x63E88755BFCD9CA2ULL, 0x90CAE23287AA4B67ULL, 0x1BF8DCCE68A03F83ULL, 0x674F69BC827E7E85ULL, 
            0x5D6A2BBD9D0AEFF2ULL, 0xB4787534EB576820ULL, 0x1AEC8E42F76E2194ULL, 0x18E34E45D2712BBAULL, 
            0xEB352C324AE3A9CDULL, 0x6365FA1736B55EEBULL, 0x35D9E75C9BFA02D8ULL, 0x7FA7336EFE650EB2ULL, 
            0x6B1709B7C5E5BE91ULL, 0x057D37480FF99A3AULL, 0x494F0287772C5093ULL, 0xDCBB35F60D980E99ULL, 
            0xECCF0ECC8B0DFE16ULL, 0x891FA50439FD3F36ULL, 0xD8CB318C903EEA83ULL, 0x6411A3208BD8A0EAULL, 
            0x250C668A00145057ULL, 0xAEA28634EC631B81ULL, 0x2D474673AC844206ULL, 0x4C28BF8AB615FA89ULL, 
            0x6DAB8D5ED30C2D4BULL, 0xF9A0B11840959EEBULL, 0x8DD8A13A130B29A9ULL, 0x3176D773792DB279ULL
        },
        {
            0x9BD3561B40F961ABULL, 0x60628A5F709DC4F8ULL, 0x24B26BBD6B11776AULL, 0xF918FBCD8B7738B2ULL, 
            0xEB95B1574A96C742ULL, 0x30F5236189F4A9DDULL, 0x8FD9A958029718AEULL, 0xD042D41A28A1D43DULL, 
            0xA3FA4A7D871A79EDULL, 0xA27F99D0D71FCADCULL, 0x4A471A823FBA2F3CULL, 0x7BFC8BDA869E4C3EULL, 
            0x32CB320369427742ULL, 0xF70CF4EF66E4D53DULL, 0x823886BC8325F2BCULL, 0xD6BE571AC1F8DE89ULL, 
            0x5DB7FAC8DF421233ULL, 0x65DB6A477ABEA00CULL, 0x2636913E5A1186A8ULL, 0x365D6121993910B1ULL, 
            0xAC39F0D8CABA6DD1ULL, 0xA14E0CDE9F546D12ULL, 0x5531DCDD4094AA3AULL, 0x6A77D5C76BCD9D5FULL, 
            0x2B6FFA8D99D1F1BFULL, 0xFFE4EA6CAC671F99ULL, 0x0EA0821F344F5AB4ULL, 0xE71184FAA520BBFFULL, 
            0x5E6352D595FFB548ULL, 0xA33EEECD29158234ULL, 0x717007727ABCAD0BULL, 0xE308A32896D365EBULL
        },
        {
            0x6EC63B792C829918ULL, 0x9CFE6DA294A081A6ULL, 0x63EE37A07351FD87ULL, 0xF83101FB531169DBULL, 
            0x9C45494A679E0903ULL, 0xF33EED950F754D2BULL, 0x51C19D45265A268EULL, 0xBC965BF84C53DF10ULL, 
            0xE7E11B4B47052E1FULL, 0xE0F2D28A492C44DFULL, 0x21DFB051381BB291ULL, 0xCCBFC5556E957C72ULL, 
            0xCD049DA2127EA6E7ULL, 0xE98CCCF4C946E174ULL, 0x26B0D7BC9DAA1868ULL, 0x545D8A9654B088CDULL, 
            0x89676CDE410E9373ULL, 0xF0CCAEE17F43B281ULL, 0x163C46E926DCFB7EULL, 0x671C656C7BFD10F6ULL, 
            0x9D59721F15922A12ULL, 0x449F06B42BACD2FBULL, 0x922494818028CD8DULL, 0x8F5FCBEAC7748078ULL, 
            0x1B79DCA99E884761ULL, 0x253573FD1094CE57ULL, 0x123305E71A987090ULL, 0x896C1DFC9CDE13D5ULL, 
            0x8FD9C5A2A01D3CBCULL, 0xB0AAB83CBA727B51ULL, 0xCF6DC4DAA67BCC2DULL, 0xB1343651ED360F0FULL
        },
        {
            0x7DC2101F21B4EEC6ULL, 0xCD36E5740AEB3FC0ULL, 0x0F527C00EB991F9BULL, 0xA473007914DA461CULL, 
            0x2F72682AF1C9CF75ULL, 0x2C9B81A43287EE46ULL, 0xD021A91E011AB754ULL, 0x0645D690B73D8FD1ULL, 
            0x916F46648A05B21AULL, 0x51D7C009C3A2EE95ULL, 0x26D47DD90A076DDCULL, 0x965AB2461F6A57FEULL, 
            0x1D15B19FA81F958EULL, 0x912A7FE7BE3870DAULL, 0x4C08A6F45DE67B21ULL, 0xA371BC7EFE072276ULL, 
            0xC0A5134483EDB672ULL, 0x3D8E872473F2E8AFULL, 0xFAB5794106EAA3E7ULL, 0xB255AE5D96ABE90DULL, 
            0x9F1D8656992D60C2ULL, 0x5029FE382810DA3AULL, 0x90D87562E97BF830ULL, 0x05D48CCD26C9FDBFULL, 
            0x3A11EE8A73AA75E6ULL, 0xE03CDE5B97F929AEULL, 0x15087714718D4246ULL, 0x0056AB9309733854ULL, 
            0x37BF59CB209D4D84ULL, 0x19DE9FF4D91DBCE3ULL, 0x4DF6411F45B0322BULL, 0x3619D8EC6087528BULL
        },
        {
            0xB5D1C3650CF18C8DULL, 0x22A3D855C9548158ULL, 0x50990ECD2BE49BBBULL, 0xBE51D1034CF8A244ULL, 
            0xF7CD6701C15827AAULL, 0x9B26A664BB380C34ULL, 0x2196AA0EB56039FAULL, 0xB17081233AB9B3F6ULL, 
            0x53D3A0F1F04AE857ULL, 0x9E48EB59534EADA1ULL, 0xD2A3FCA586830AA8ULL, 0xDDE7D129F733CF51ULL, 
            0x86BF6807E8C1E543ULL, 0x332DFD3718FC58D6ULL, 0x3152559842A066D2ULL, 0x84469956838ED0F2ULL, 
            0x0B29BC17C3E4FA37ULL, 0x4BFFD6D66E54CF76ULL, 0x664BFAD5DD74E39BULL, 0xB4007F25660D4998ULL, 
            0xF6E0C3EA5F55537AULL, 0x90EF77C07C0A3A1CULL, 0x4593102C85776AB6ULL, 0x855F181B2C9B03C3ULL, 
            0xA599A5CDDBAD7BBEULL, 0xF62DDB4DC3C41382ULL, 0x12349B93E4580B25ULL, 0xED0E9198B629BC9EULL, 
            0xB064E412F252151AULL, 0x87C2FD8DA9DB41B2ULL, 0x46A768F935BE63CEULL, 0x31F190B7C4F57303ULL
        }
    },
    {
        {
            0xD405195202123682ULL, 0x6E6D18741B7BBEE0ULL, 0xCBF8C420FBCC2194ULL, 0x0A4D08948628145CULL, 
            0x79F3266DA7F55D66ULL, 0xDCA92A9F40F3B12CULL, 0x6DB716AE09471840ULL, 0x2214D6F02201DCCCULL, 
            0x527F476E83D268B8ULL, 0x1DE37295804E958EULL, 0x789CF8CD40821553ULL, 0xF5FDBC2B2F1F9DF2ULL, 
            0xE226CB3D651477A5ULL, 0x1525EE1C45B4EB54ULL, 0x5E5EE23EE1072D27ULL, 0xC731B0CF56274232ULL, 
            0x503FABF29C096B64ULL, 0x6E7CF8879B70EDC2ULL, 0x6B9F0A8FA192177DULL, 0x8C76B195240F522FULL, 
            0x104159AC677ACEF0ULL, 0x17703CDA3088A005ULL, 0xCF56F837C6DFC18DULL, 0xC1C65C8FCA55B1C3ULL, 
            0x7DE55C4A12D2088DULL, 0x72673889608E796FULL, 0x8ABC609E48801BA9ULL, 0x08A6CA1E6293285BULL, 
            0xCD1D98D8E86AA080ULL, 0x38326A4D329ADF11ULL, 0x860FE7EFA32ECCBDULL, 0x8E578C0D68F3D301ULL
        },
        {
            0xCFAD5AED4D52AE04ULL, 0x0FFB401F6A047516ULL, 0x68C9CC0F6DBED47FULL, 0x4BDBC2DF8A2F2E82ULL, 
            0xF0634933797D4484ULL, 0xAEECCBA2C2DB41C0ULL, 0x668B5D97D96E23C5ULL, 0x82579BCA8E0C7D5BULL, 
            0xD0DAC7E37A64BDF7ULL, 0xE14995C817A88872ULL, 0x378A4E1DA171BB27ULL, 0xDDDBE8FE5859309DULL, 
            0x10B8ECC64744151DULL, 0x9BA0DE079031DEFAULL, 0x1FF9EDEA33A39050ULL, 0x045DC3562CFC45E8ULL, 
            0xD5B65F51CD166C71ULL, 0x6B4C087C3029CE99ULL, 0x275F0E1DACDA3AECULL, 0x2EBC4D899AC4A95FULL, 
            0x5470781B095F0F14ULL, 0xFF5187219DB70BCCULL, 0x0C00E34C8ACC70FEULL, 0x8AFEA9EDC2C01F9BULL, 
            0x97DFA3E13232D00AULL, 0xF2A5221E51A95502ULL, 0xA70A982AD4D6CB1AULL, 0x9A9B78D4948521D9ULL, 
            0xFBD332B699B59080ULL, 0x645D4D1A0F98336CULL, 0x1D1031196D94FC56ULL, 0xF4406CE203F91399ULL
        },
        {
            0xE0355C4C56F16642ULL, 0x851A7DBFC951DDD9ULL, 0x54E87C92E8657E1DULL, 0xF25608CD90880AD9ULL, 
            0x991BF3448454EE8CULL, 0xA7646B11F49239F0ULL, 0xD2C122B97AACBC10ULL, 0xB08BD8C52CEF9303ULL, 
            0x352A407C04531700ULL, 0xD83821434E012922ULL, 0x81CDC446E305C059ULL, 0x7EDAC199E4BEA875ULL, 
            0x85923C3F90667E05ULL, 0xE669F30EF90F89DAULL, 0xDA4766292EF1AF2FULL, 0xFB53ADED3407CCC4ULL, 
            0xFE914691E141A2E7ULL, 0xC3A4545882342597ULL, 0xF96907B10BE4C26AULL, 0xB0B8A7407330C54CULL, 
            0x244060A8AEA305C8ULL, 0xFE2ABD3C1CEC57C1ULL, 0xB196208FB37FB10CULL, 0xDFAE4BD3EDA955A1ULL, 
            0x89561DF90FCEB17FULL, 0x63F752C225F05E10ULL, 0xE6CF26EE29047859ULL, 0x37278799A9D8AD9AULL, 
            0x20473D086C4A4451ULL, 0x5EBF04CAF0EA8A68ULL, 0x8A88612EED1085E0ULL, 0x1B4F7438140F2A65ULL
        },
        {
            0x1816AF75D2B91EB9ULL, 0x353435582C9E052FULL, 0x27BCDD17F327CCE3ULL, 0x790C42E7E27A81B1ULL, 
            0x724747A458F6D2B3ULL, 0xA0CC96A08D84F9EAULL, 0x1C23704B710FEB3BULL, 0x5A912DC80CA27FF6ULL, 
            0x5CECE5952FFF2FE8ULL, 0xC7F103AEBD1FE1BFULL, 0x4DDE15F38F72A0BFULL, 0xA9B0B4CF2B970694ULL, 
            0xE012272EEE51D057ULL, 0x14102924141A5892ULL, 0x020F53FCB35F18ADULL, 0xDC213AF0BE144E90ULL, 
            0xDD439C67D03E1CBEULL, 0x2AAF849ADFFF5312ULL, 0x231E85C1E8BE6461ULL, 0x22B82C600DE53BB7ULL, 
            0x404DAB28E8622404ULL, 0x8B7B35881393BC30ULL, 0xE8038BFA10606BC7ULL, 0x0660B049169FF691ULL, 
            0xBF7D0B14469B95CFULL, 0x71CC0CF5E9CCDE80ULL, 0x71F54AFB8354B1DFULL, 0x1FB349DF39161DA8ULL, 
            0xBE63264A43A6AD40ULL, 0xBD07AE6048AD302BULL, 0x381DB96BBF424C19ULL, 0xF1B543DDE188B396ULL
        },
        {
            0x71EDBFDC4DFED88DULL, 0xB77D51BF7CCA1D94ULL, 0x870222B0082E4FACULL, 0x1BCE39E91107F97EULL, 
            0x8D7A019003E6D5CEULL, 0xBEE6FC1061FC89B6ULL, 0x4F7041908D9AB87FULL, 0x969EB57D7014475FULL, 
            0x303E169423CCA7F3ULL, 0x1D623CB44318CF0EULL, 0x3E68874D7230A52FULL, 0x0DF751A46D0EA43CULL, 
            0x45DEFDBD195DE7A4ULL, 0x9576877366577288ULL, 0xB0F9A71D3C6988D9ULL, 0x9DBF5EB4329EF9D8ULL, 
            0x58845D92D6C1B348ULL, 0xC163E95398DA385BULL, 0x053EA44998BDFA21ULL, 0xC0F8B87CD012AAD4ULL, 
            0xD0A84B724115EC0CULL, 0x0CDF6B712E40860DULL, 0x49CDDAF547ACCD9AULL, 0x1AF827F51E97053FULL, 
            0x8C532061139C2588ULL, 0xFAC2D7EEB5042CB5ULL, 0xCF98B4095284395EULL, 0x78E412BA2761CF24ULL, 
            0xE6330ADB755C7B98ULL, 0xF8FD6AD6865B0720ULL, 0xF38B17AF92926C17ULL, 0x01BFA14E2E33A793ULL
        },
        {
            0x4206570B4A662415ULL, 0x308426E1E1C2CB14ULL, 0x06F5667A2AB8275AULL, 0x5D6739F8F17CA41CULL, 
            0xD2AB77CC90152113ULL, 0x8E04990BF014CEB5ULL, 0x49D2F72D169F3CC2ULL, 0xCB6F7CC7B3D702E9ULL, 
            0xA8D70F1DF9AF0E6DULL, 0xDDDFFB8B70251B12ULL, 0xD03FEC25CC481D75ULL, 0x42A8B9EC6F0A9AA7ULL, 
            0xF6A9ABDFA706C5F8ULL, 0x4D958DD76FF23233ULL, 0xBF2F4F2BEA2105A1ULL, 0x92D8F10BF82BB786ULL, 
            0x0A7524DBEA9A9C56ULL, 0xE61F78FAC2868EE9ULL, 0x59EC75CBBD471C2EULL, 0x3026C5C9DB5A0F76ULL, 
            0xE08E3BD330396696ULL, 0x3BE3B45475AC4E06ULL, 0x5426D27F12F7348FULL, 0xE7430933F80FA74FULL, 
            0x59A872BF1F7FE21DULL, 0xBA406C05A8D66510ULL, 0x2BA01C9F70C5B0B5ULL, 0x557A0CD21EB18C94ULL, 
            0x4035F4C4FAE687B8ULL, 0x2ED44894DDE22998ULL, 0x6D14C53D07C22AEFULL, 0x5AA97C781C179FBFULL
        }
    },
    {
        {
            0xF379FED07AB7AA25ULL, 0x909E1F0C29E70068ULL, 0xD80D666DFB587A2AULL, 0xBEFDB6214957604BULL, 
            0xFDB355842F13DEA2ULL, 0xB3642503DE566E35ULL, 0x511E7DDF05E8BC8AULL, 0x973B41A954DF5B1FULL, 
            0xFF2FC9ABB7FF23ACULL, 0xB89D07B592DAE8B4ULL, 0xBF9A539A80B42D88ULL, 0x6F6735C00D7F2436ULL, 
            0xC90BF67ABFDDA8E8ULL, 0x0E15736A23257E0CULL, 0x5996849737197384ULL, 0x30DF3CBD91051748ULL, 
            0xC69803F9776E6148ULL, 0x52261DCDD601FA59ULL, 0x789C038ABAF85679ULL, 0x0EBE4F6541B65DF7ULL, 
            0x914A890377BA8DC9ULL, 0x4CC54B07D03797B8ULL, 0xE8A5ACEAB656C60CULL, 0x54599B0978900B65ULL, 
            0x6B8EBBA14F6D8F27ULL, 0xF6A568FBD9EF1FCCULL, 0xC17C50528DB052C4ULL, 0x0E23209520037E36ULL, 
            0xB5511D2E45178205ULL, 0x0D184CF30236CB2BULL, 0x4337B4F12DF07753ULL, 0xB41BA1D216FC4190ULL
        },
        {
            0xD5F28C7BF1CB66CDULL, 0x0C86FD0B7C1D8B5BULL, 0x10BFCD241C7CB71FULL, 0xD7054CEB0481E08BULL, 
            0xEE20E330CFEBC378ULL, 0xE8B45DDAE2D64EFCULL, 0xC78E38DCC3E277A3ULL, 0xC57DBF3631A3D378ULL, 
            0xAA5D8D73FDDC124BULL, 0x600BAB95C1A31AF8ULL, 0xB4B6490D8D3CE800ULL, 0x72E153D790DE79F0ULL, 
            0xD88382FD0D073EECULL, 0x4D15455C78ED3430ULL, 0xFDCB3930CA5867B4ULL, 0x5EABCA1AD7F979F8ULL, 
            0x148F3C11869278B1ULL, 0x003EDF4131A27E95ULL, 0xD8B6446C909A0E76ULL, 0x5542FC04AABD1116ULL, 
            0x9072CE2C987CD6AEULL, 0x3E49E92F73CC8B57ULL, 0xED59D69E4E3FA129ULL, 0xAAA7CECC9262CFEBULL, 
            0x9A0F8AAD65BD0357ULL, 0x434D06F1DE6265DFULL, 0xCF362E045E1B27E7ULL, 0xF3D2038FB7A3D84FULL, 
            0xB08543A69A2C2E49ULL, 0xBF7C1BE34F82DB9DULL, 0xA79B81C5AAA79A75ULL, 0x00F825947542A68CULL
        },
        {
            0xB7576FD024FC5A51ULL, 0xD487965EF6DA9D18ULL, 0x488B39D31F914C80ULL, 0x0E26799409057C4FULL, 
            0x2A0E9468B82334EAULL, 0x3F63EB2EC4BF4F95ULL, 0x15317FBEB028E8F7ULL, 0x0BF80B38C820A0FAULL, 
            0x088E1B22412660C5ULL, 0xD1222C8A686F0F5BULL, 0xCB932A8915D3C223ULL, 0x496617F318D05D36ULL, 
            0x491DBAB3B489BFAEULL, 0x081109314C7FC71EULL, 0xA4F76D3F775BF7D8ULL, 0xBB57520CD14C0852ULL, 
            0x21DDD92E448A574EULL, 0xBD588EA894A4A75CULL, 0xEF1EC4A58981D299ULL, 0xAE73FD50AAE19DFCULL, 
            0xC59006B4FE1082BDULL, 0xD0054BE51FCD375DULL, 0x6C05BA0EA5B98BE4ULL, 0xAA154CF06CDAAA3DULL, 
            0x72DCE1EFA31770FFULL, 0x63DAD99CB528427EULL, 0x6F8CE4DF2204356DULL, 0xA2B85A01B725BBCFULL, 
            0xEB220C12C49603B8ULL, 0x31AABAA001928D5FULL, 0xF189A2AE0C02570EULL, 0x88816AC78A8CB594ULL
        },
        {
            0xB71C743811082278ULL, 0xC822E4D19AAA4D27ULL, 0x2A1B84FFF893A71EULL, 0x838DA426374FF952ULL, 
            0x0CBDDB974053C853ULL, 0xB1996B48E6C66413ULL, 0xEE63B60F8D4FABCDULL, 0xC824C091758919CDULL, 
            0x42CFF60DA58D5234ULL, 0xF2310189803214C7ULL, 0x1C0B1C25CA4A7AD0ULL, 0xEAFEDFAD56B02329ULL, 
            0xD32B23FC64BC0E6CULL, 0x6256DCCC8F3BE23DULL, 0x69C9400F7F9C823CULL, 0x196FCC4ACB349346ULL, 
            0x4E23E229353D71A0ULL, 0xED6FA38293223704ULL, 0xF6EBF9DB464BDAE9ULL, 0x27A7556D008778CFULL, 
            0x0D3BF571125DED56ULL, 0xA3BDE431DF29DEB7ULL, 0x44A6A273CF2DD6DBULL, 0xC17FDC4E5353D2D0ULL, 
            0x2C2793182FFC340AULL, 0x1F643A277E1E2E3AULL, 0x9FFA973D5E26ABCFULL, 0x17F29CFC9472407FULL, 
            0xCA0BD8DC6031473BULL, 0x070980344CA7EDB0ULL, 0x97D8133E73FB59F8ULL, 0xBE1270A70148A99BULL
        },
        {
            0xA8D55D0B9DB9F351ULL, 0xCAB111FCE478BB16ULL, 0x6BCF1E4830B98515ULL, 0x90386E9E4F81F53AULL, 
            0x7CE4DEBC87E4C536ULL, 0x1A30F88BC8A94EC7ULL, 0xDC11E4BBD92E65DDULL, 0x25C3ABE828200F13ULL, 
            0x08F2EEB414499D6CULL, 0xFD0FCE77E41C6EC3ULL, 0xC4F77DD4B1CFFDD2ULL, 0x4BEA8410CE4CDEFFULL, 
            0xFCDF61380E6F06ECULL, 0xF4469D8898124124ULL, 0xB00378B4768EC646ULL, 0x9490A7580EA72881ULL, 
            0x61798823B4F621E5ULL, 0xF830FE5498111FEEULL, 0x1B1C4313A4E579CFULL, 0xEF2C1E2899EA3B95ULL, 
            0xF2A7F857050E7F93ULL, 0x456CC32D451EA15AULL, 0x6727AB660EA8009FULL, 0xC4A3275E091C2FCFULL, 
            0xB22F2B38AEDF9982ULL, 0xA0701AF5A7C84BF3ULL, 0x1DFD3C8F0E709E4FULL, 0x946DE1BBF03EBD01ULL, 
            0x988C77448E6D26F7ULL, 0x931B436C157161EFULL, 0xFE0332087891F03AULL, 0xAACF1EA72DD2550BULL
        },
        {
            0xD106AB62E6965682ULL, 0xD0D5C33E7F605910ULL, 0x23CB9C8748EE7E93ULL, 0x5A61C7BF8C37E614ULL, 
            0x88A206D180CEA0DFULL, 0x20D171135D18D3C5ULL, 0xFBF65B24E696F13EULL, 0x356AD7413D234F82ULL, 
            0x0172708AF52E9A07ULL, 0xD93318E03204005EULL, 0xD0D9409F3371BCCBULL, 0x49255B88C4735B56ULL, 
            0xFB9AB44D037ACE01ULL, 0x9DB4C71AF3C2C220ULL, 0xD4CE7E6ADB84358FULL, 0x5DB2B9ECF03F66D9ULL, 
            0xDF0A3BA2B8FD496CULL, 0xF8A6C1922B6C11BDULL, 0xA415C507C8967A15ULL, 0x8D3B14BABF61E6F7ULL, 
            0x0CEA533C1B440A90ULL, 0xBD5C73E780A2FC22ULL, 0xD731CE3D2417B137ULL, 0x2BD466906E7368A1ULL, 
            0xE8ECB5F5421A36E5ULL, 0x1A3B1B2D58604C99ULL, 0xAC1C0910ADC17D09ULL, 0x1BBC46957E170170ULL, 
            0x057736DF52BFBE74ULL, 0xE0D1CF8A576C2B94ULL, 0x05231A75E2338594ULL, 0x99E2FD6AA1B3515AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseGConstants = {
    0x5E2EBD59CEF1AC49ULL,
    0xD68A76BC7B036B3AULL,
    0x33C6C70D29675974ULL,
    0x5E2EBD59CEF1AC49ULL,
    0xD68A76BC7B036B3AULL,
    0x33C6C70D29675974ULL,
    0xDDAF785013C3DA65ULL,
    0xDADE62889805B53CULL,
    0x2B,
    0xF2,
    0xAC,
    0xBD,
    0xE4,
    0xFF,
    0x60,
    0x38
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseHSalts = {
    {
        {
            0x555B670339BB3E54ULL, 0x802FCB8F1C71220BULL, 0xC7FA3C13F1D424E4ULL, 0x69B069E811344D11ULL, 
            0x1EA2E0463E79E82DULL, 0x7F52EE1F33E2CF12ULL, 0x067E68A583A6E3CEULL, 0x61E5785085EE0BE3ULL, 
            0x73ACD3453811B634ULL, 0xA5FD22A4AD74A7A9ULL, 0xAA735DCD42500FCBULL, 0xD8B01587266D384CULL, 
            0xB52B4A0BDF97BB3CULL, 0xB7889A1C29653DF3ULL, 0xA2739B347C88B95DULL, 0xD23F79F6DCAA1D22ULL, 
            0xA96EB3788B55FAB0ULL, 0xC292361FC67E3A33ULL, 0xE179A5EA91FCE96CULL, 0x68163082441FAFAFULL, 
            0xE0D2FC34BA0B1E4BULL, 0xACD2C78C38525625ULL, 0x8991A701ED75FD0AULL, 0x2BE0A949B7F384DBULL, 
            0xE0BF351C38B6E665ULL, 0xC0CA8EB9A0E480F1ULL, 0x1C64817009784138ULL, 0xB548CD29C8B3F99EULL, 
            0x6593B82143D05741ULL, 0xEBFFC57DABFB364AULL, 0xF0A3BE1BA97152F5ULL, 0x9CDA1958B3FED619ULL
        },
        {
            0x235D6B87A24A3C25ULL, 0x71A31ABDDB7EEA72ULL, 0x2AA316ED6F7FF6F4ULL, 0x0287F7A84B7DF4CDULL, 
            0x3C14E724E9880E8DULL, 0x22A4FC2B134228F7ULL, 0xE5B35207E3A2E6BAULL, 0xEB4CC39BAC19DD25ULL, 
            0x7E04144A22E5652AULL, 0x6DE46E56D018A819ULL, 0xC99BB12F4F1D7450ULL, 0xAA3CFA6DE572E4B3ULL, 
            0x29B39C5FFA0D2497ULL, 0xAF3F5D580F327ED9ULL, 0x031285C82FCB653AULL, 0x409392F7DD5DAEFAULL, 
            0xE8AB232BA1CA8EA7ULL, 0x9A7B96CF40174C7AULL, 0xC906BF8B33C63F1BULL, 0x3430DDDCDCEEA266ULL, 
            0x8478CD7A7C078355ULL, 0x17ABE26597B842F4ULL, 0xC35BB5EE366865F4ULL, 0x5DA5810AEBB0A7C3ULL, 
            0x7677D59760BCB9B9ULL, 0xB950E522F141B80CULL, 0x02AA0C263B78C7F6ULL, 0x743909A430A7D47CULL, 
            0xD80671DEEE5FEC0AULL, 0x9D4AEEB9537AE105ULL, 0x3931AF114B0C344BULL, 0x2DC5F844370B4835ULL
        },
        {
            0x04995A2EA26FE72AULL, 0x1EF4603C0339D96CULL, 0xDF2DAFE0F5DD5D23ULL, 0x3BB12EB27D1E82BAULL, 
            0x9E545C54CDD2DA71ULL, 0xA3715CE28329517AULL, 0xA4990CE918CD7BE5ULL, 0x7C7EB5C302A00292ULL, 
            0xFA5CF938B320CA82ULL, 0xC8D4FD9E042A61D1ULL, 0x71D8B4AE8CB0450EULL, 0xBE9C15B2D12C156FULL, 
            0x797133E24CBC3437ULL, 0x984D366566CB46DBULL, 0xB2C9AD31DC93CD82ULL, 0xE103076485EF33A9ULL, 
            0x6DF5216B7FE33306ULL, 0x9CD4DB2B63A00EF8ULL, 0x7B31DBBB9A0E1038ULL, 0x61F8FDC5554F2DE2ULL, 
            0x5B9312F9B40389EBULL, 0x827437030420D533ULL, 0x4D0C6423FC3C64A0ULL, 0x648763F0FBFDBDDDULL, 
            0xD9EF867BF6B871C4ULL, 0x79752FB9CDE7DDE6ULL, 0x0EA7B599B1F8B24FULL, 0x53F375BCB55E9745ULL, 
            0xA443AB6495FE9F04ULL, 0x7B8804749AAE8FC6ULL, 0x0CD49E03679A855FULL, 0x0C5D002D50202728ULL
        },
        {
            0xF3AF1F31C1F70EEFULL, 0x3E2AB63D9FA2FCB1ULL, 0xDC8442779C72ABDCULL, 0x0703017851B52386ULL, 
            0xA79045FF6F939053ULL, 0xEE4D2343DA03A064ULL, 0x0952065CF886D7E0ULL, 0x659FD03DB7A90D10ULL, 
            0x08EF7115BE168EEFULL, 0x63B9ACE35C09273EULL, 0xB7A37266182DC14EULL, 0x753D3E0DFC1CC321ULL, 
            0x4D27AF3FD85B237BULL, 0xFE7762B1E45EF467ULL, 0xA178AC5C52EA9297ULL, 0xB8A4F0D378181E21ULL, 
            0x1E693E7550AB0D11ULL, 0xAE3823100C7F5A68ULL, 0x5CF964060F12C71EULL, 0xAE41FBDE59099F86ULL, 
            0x880121F5FFFE3924ULL, 0x90EC424E2FB9D1D8ULL, 0xEDCF26E49771DC2AULL, 0x55E82B44F2EA0974ULL, 
            0x00106EEDFCD0BCA7ULL, 0x2B5099670AC9BF94ULL, 0xED4F182D8C4DDC97ULL, 0x617B662227037347ULL, 
            0x061F707BA5E6A389ULL, 0x938E576815AF61F6ULL, 0x8D1387505006C351ULL, 0x85B7867219209BE1ULL
        },
        {
            0xB51CAEEDECA7C7ECULL, 0x589E77A5F80B142FULL, 0xF09DFC9F53D37E89ULL, 0xDB6A0F233EE2C0FEULL, 
            0x252BF33A8DBB183AULL, 0x726E97967262357FULL, 0x2475CF1729E1FF6EULL, 0xDA67FA85FE7F8DE3ULL, 
            0x38182E04B8FA4F6FULL, 0x3D63264DAEFAAB69ULL, 0x324DEEE97E471F33ULL, 0x584CDEBF949C9A0FULL, 
            0x9C8C5D7D1525FCEEULL, 0x5F0816E7D2783D63ULL, 0x48BAF74A2C5303E5ULL, 0x9B568DCFC9BBBB9FULL, 
            0xD23685633D5A228FULL, 0xB9610A5E6BBF1CB4ULL, 0xE3B66F3A0DE9B319ULL, 0x6E5F8E4F155096C5ULL, 
            0x21DD03F884E7BBF7ULL, 0x09F7FD710DBDF298ULL, 0x6A79F28F6285227CULL, 0x453D42A930522E93ULL, 
            0xCEBC91506767F77EULL, 0x89E04646AA848A59ULL, 0x52D9CF2911B4F8E1ULL, 0x0257C26FA6D6D856ULL, 
            0xA947BAE0DCE731CDULL, 0xA382FD4DCF718E58ULL, 0x7E8BB7D194415145ULL, 0x9D37139480B47FFEULL
        },
        {
            0x36C942C6B5705FBCULL, 0x52B9BD0A3F5F1D67ULL, 0xF27069614E5720B5ULL, 0x3B34D0DFFC508407ULL, 
            0xF4AC2300EA4781AAULL, 0x023A565E63918DE5ULL, 0x5599306DA7485AA7ULL, 0x4090A0C8CCF8C673ULL, 
            0x7940861DAEF98C14ULL, 0x498ECE0A415B6D8CULL, 0x9568A5A191125BB1ULL, 0x51F16DDBA8BAE86BULL, 
            0x3F287159930E2E12ULL, 0x0ECAD96A498FB622ULL, 0x554D04B1B5D32A00ULL, 0x05F2D8C2E45C8DACULL, 
            0xABF6449728CF3705ULL, 0x766DE5B38A4CA655ULL, 0x3BC7A7785D3779CFULL, 0x6A0E750D57EDA144ULL, 
            0x7FF1CAF0CD60E792ULL, 0xD5EDA4F75F9CA496ULL, 0xF9269E660A78A4DAULL, 0x755E4AEF8B35C1BDULL, 
            0x62B61414DFF59FBEULL, 0xF73DAF6AAEDE16B4ULL, 0xA46D29E08795FA29ULL, 0x06EAF71E72E66F04ULL, 
            0x7EB0140F762483BBULL, 0x9A10D76889463E76ULL, 0x92AB3E1001DA7475ULL, 0x1B8B4A1295349EA1ULL
        }
    },
    {
        {
            0xD0765902BC5A22CDULL, 0xB042C35D5170FF48ULL, 0x622526698BB89EE2ULL, 0x1D757B4778DD7002ULL, 
            0xDA7642983937B867ULL, 0x81B4E2B7B69AE22FULL, 0x04EA11CE02EFD437ULL, 0xA92CD4A4CFBB4331ULL, 
            0xCC453664807B7227ULL, 0x4E622EA933EA58F8ULL, 0xBED51E79F05361ECULL, 0xA7DF5974A497736EULL, 
            0x307AE3FFF660CEF1ULL, 0x55DCB3A136A2D2D4ULL, 0x1A8F8A3656265C8AULL, 0xA943E7294A841566ULL, 
            0x8BE9E7567CF7A72BULL, 0xC2B82F260F3A6F52ULL, 0x9B2F6983AC152688ULL, 0x41D83913C089E383ULL, 
            0xFB56B2E3592C4B8AULL, 0x37257D117A945466ULL, 0x471854803C434CD3ULL, 0x0AC5EBEB8EF4D01BULL, 
            0x9E0ED7978F90D14BULL, 0x7758CE1F06B86705ULL, 0xC96C4EF259B8E01FULL, 0x94F1A0962DAF59DEULL, 
            0x63B6074DC848D3AEULL, 0xBAA3BC4C0B9394E0ULL, 0x82C168EFACE91990ULL, 0xAC8873BEF3304804ULL
        },
        {
            0x4F8BB4FB95E704A3ULL, 0x28F826CF290DA742ULL, 0xC031AEDDE051468BULL, 0xE9771D2A52FEC98FULL, 
            0xEE9F46531A657BE3ULL, 0x6A388BB811C10D9AULL, 0x519044CB54D53B71ULL, 0xE2A009A614C1CBDDULL, 
            0xA67C964DD1A401B4ULL, 0x102C67CFD3B1DB39ULL, 0xE9D9B8DAD164B2BCULL, 0xB3F9DD4F123FF0C7ULL, 
            0x3DD90F75E15E1CF9ULL, 0xF6055E78776BA2A1ULL, 0xC49428C6C97B9119ULL, 0x18FFA9E575C034F4ULL, 
            0x563ECB41E93A3D9EULL, 0xC59C0482BAA4DBCBULL, 0xBEB85E76C19F5F61ULL, 0xC71A608543E62D34ULL, 
            0x734B075DDEBDAD11ULL, 0xA1846ED76AC6FB06ULL, 0xFAB9BAFCADEB1851ULL, 0x560FEBAE3ADF9ECAULL, 
            0x030676A12129541AULL, 0x48F5ECF127888C7AULL, 0xA977325A17A474A1ULL, 0x42B418CA0ED90D16ULL, 
            0x32138A8299D0938EULL, 0x486C5756351B331DULL, 0xD2160C125FDF2397ULL, 0x09649D2D56DB0B9CULL
        },
        {
            0x0DB84DFF9D048A88ULL, 0xFB8449CAF2E1CD1EULL, 0x3D30C999E450AD8EULL, 0x3EE0788ABA1C3223ULL, 
            0x56F31AC849EEF1A9ULL, 0xA20AE571CC962F85ULL, 0xCC30DCB2290198A2ULL, 0xEE2380C69E67EE8EULL, 
            0xBDDE67D862DA3E2BULL, 0x5FDBF8E06BF7EA30ULL, 0xE4CDAA20D3A47123ULL, 0x2DB8FE5F9B5020E0ULL, 
            0xCD5316B82C09CD1EULL, 0xC0296DDA0EEBF5C6ULL, 0xB73A160300894BF1ULL, 0x96079901D0FF5F53ULL, 
            0xFED4180764F775F8ULL, 0x00F2A5AF1D2D906FULL, 0x4F6EAC3A72B8E5BBULL, 0xE2DCD2CD8AA8E2B8ULL, 
            0x8FEBB8BD10EAA4A3ULL, 0x1C91CD18B4E7B774ULL, 0x4BA84C07E43DAFDBULL, 0xFED299B7692FABD9ULL, 
            0xB4E5929BC50A7187ULL, 0xB62F3ED2A95695D3ULL, 0x17649D36F77881C5ULL, 0xD4661812A87BB1D3ULL, 
            0x39C19495F19B988FULL, 0x49E845764DCA23A0ULL, 0x14C445A19D78C0B6ULL, 0xF394AC8182F6C9ABULL
        },
        {
            0x7C3F96A1160FC63AULL, 0x7175A8D4B8DC1FAEULL, 0xDC0086DADA457EFDULL, 0x49A2CFB59737A3E5ULL, 
            0xB69AE41889E74F26ULL, 0xDD78794003750D43ULL, 0x052E3F4D21274C06ULL, 0x0AEA55BBD5497036ULL, 
            0xA3649A33BCC064A3ULL, 0x3BF34ECE80694462ULL, 0x3074AD112FFE1607ULL, 0xB10954D6A9DC7266ULL, 
            0xC8C3E232EF0C96ADULL, 0x5D51310B1BCA3D3CULL, 0x23E53272F497557FULL, 0xEBE96F0A647839B4ULL, 
            0x04457BAB1F8AE0F4ULL, 0x4A78060BF81BAE11ULL, 0x527C074BE410D5B9ULL, 0x8226228731F7C9A5ULL, 
            0x692B1E824606BD38ULL, 0x121146AC9A272A46ULL, 0x01BD493C31B647B6ULL, 0x0880D3898C37FA7FULL, 
            0x4891AE973AB67006ULL, 0xA3169CDE8C7C65E9ULL, 0xF24D4858C86A10DDULL, 0x9F7206578630660FULL, 
            0x904DA49AF2312F5EULL, 0x84C01C88C1920257ULL, 0x500841718B4A5EF8ULL, 0x4C43AA0ED49F6829ULL
        },
        {
            0x614B006F556FAABCULL, 0xCFD1EE4CDF7F6CDFULL, 0x544003532867C3CCULL, 0x9720FDA2D8411183ULL, 
            0x2E90B8A3AFCDCE15ULL, 0xB57672A9B7B0C143ULL, 0x7495C09D166F8D28ULL, 0xBF4B689EE19023E8ULL, 
            0x2C187A08FBC63D71ULL, 0x7C6B02BE12073DE4ULL, 0x3683CCA7ED09ED99ULL, 0x0B810C6D5667C082ULL, 
            0x7A403DF6F815C998ULL, 0x30730D789ED00F95ULL, 0x168796A4349CCDE1ULL, 0x0293DB887B4456D1ULL, 
            0x9F54F74378C4AA70ULL, 0xF99DEC5C7D02BB07ULL, 0x3427073F8E868874ULL, 0x1E34E76FC2BDF6D3ULL, 
            0xB46B9252D4853D8FULL, 0xC3909B7A698BB924ULL, 0x5CD8F1E55988EAEEULL, 0x20CF1D45B66E9951ULL, 
            0xB741329FC59DBAD9ULL, 0xB98642429797D3F1ULL, 0xD60FE21D1364BE29ULL, 0x8B995773E0E98A0CULL, 
            0x9EE36471178BCA7BULL, 0x8F3E5769493734E2ULL, 0xDA7E527A66729E16ULL, 0x6F8079A2CA85EE31ULL
        },
        {
            0xBEB09AAFE68ACEB3ULL, 0xFD3417210CFB05B5ULL, 0x8E7A23E29691C97EULL, 0x04B2793E33B1B041ULL, 
            0x031F45DA17204322ULL, 0x31EA1F9450CBD4C9ULL, 0x5C21E2C8E28EB7EFULL, 0x898A7D1CF8246948ULL, 
            0x53C456AACB060089ULL, 0xDD3692A225EDE33DULL, 0xC19CB92171AB0515ULL, 0x2161D80C1FBC2472ULL, 
            0x6341D1764174EFA9ULL, 0x2C7BD601BC1FDCB2ULL, 0xB229988ACF34D882ULL, 0x4E303EBDFF8105D3ULL, 
            0x56E15EB511E1F03FULL, 0x78C6679D69E5BB8AULL, 0x49DE0C1B320BD20CULL, 0x939FF69A9456046AULL, 
            0x179F518E3802F179ULL, 0x7ECB6434F4B9D198ULL, 0xF69ABEEBE0FE67AAULL, 0x401C5757E1A41EFAULL, 
            0xF0CACDF113120691ULL, 0x36AE7D59312CDA70ULL, 0xB23693308EC30009ULL, 0xD798C0F5AE262080ULL, 
            0xE68B2F2972F955B8ULL, 0xFD1D496F473B7B9EULL, 0x4BB0DCB8F7F5417BULL, 0xBD89D381A630E26EULL
        }
    },
    {
        {
            0x3710D6A20F06F22FULL, 0xC389ACFEDEA3C51BULL, 0x54F0AD09DF9DB20BULL, 0x1908535CBFF3A1D8ULL, 
            0xA85356BC1A20F400ULL, 0xFE9379DF6EA294D7ULL, 0x08A7136702DECB53ULL, 0x9EE725CCF3C7F43DULL, 
            0xA15EF43A1D2AF2C0ULL, 0xF9EF4C53388C6072ULL, 0x543B74F688D7C5B1ULL, 0x50C6B4AE417D1A67ULL, 
            0xCD2B2AF1D56A4442ULL, 0xB1AE05E94A3280B7ULL, 0x413E9241A9E1FD72ULL, 0x86A4C4AD55C5F8E7ULL, 
            0x1EA497A700E27E93ULL, 0xC2FCA860EDCC9D84ULL, 0x22CA87737EA5F11DULL, 0x125026F8A4B4C987ULL, 
            0x9AE059721024D615ULL, 0x12FB0DC305C80D6AULL, 0x72A5DC30FE05814FULL, 0x03B52301E011F0B4ULL, 
            0x9866A72CD218F51AULL, 0x3B0CD5B34AB4D8DAULL, 0x4890C0784E730701ULL, 0xEFE171F8C10210ADULL, 
            0x20972A1DAEBC35C4ULL, 0xA0151782C0ECA19CULL, 0x0A4D0798E5A99D07ULL, 0xB541183572CEC123ULL
        },
        {
            0x7F500C20A204C772ULL, 0x912E7DB8681AD7CFULL, 0x75B90451CF997C5CULL, 0xB34CAF8068E30EF5ULL, 
            0x5F83CB3DD279F87CULL, 0xDDAD0AFB096109ABULL, 0x57573817B1C9FB36ULL, 0x74762D7088DA006EULL, 
            0xA3399C9B1EF0E3FCULL, 0xD9DC4E49CF734B23ULL, 0xFD72C52FCCD694BDULL, 0xB5B2EA1AE301A6C8ULL, 
            0x86A5EF4E4D719275ULL, 0x16F4A05D2E2EA9F0ULL, 0xBD5D432EB1B7871AULL, 0xDBBBDB0C7AF9ACAFULL, 
            0x11BA722DC6AAC602ULL, 0x2920A5DBBD2E13CAULL, 0xF9A3444D7F8774D7ULL, 0x3C57F73EEA266833ULL, 
            0x72B04F5FD1EFA563ULL, 0x56D677029A6D3D73ULL, 0x606AA05EF6B802EAULL, 0x6D2C019E75CAF23FULL, 
            0xEC438B3FA7F4B6F9ULL, 0x82E9E198097A5E71ULL, 0xD2FD9A51DDF823A1ULL, 0x18FC3610997402AAULL, 
            0x6491F7FD0B94C761ULL, 0xB79C1AAB2D7AC7AAULL, 0x9AC2468A4D9A23D1ULL, 0x73395B9ED79B7622ULL
        },
        {
            0x9D02B13245A55346ULL, 0x8D45E9C2D2DD56E2ULL, 0xA4D14B71BA15D600ULL, 0x0F6C4262CCF47AEBULL, 
            0x0F3DCA39DF9F97CCULL, 0x2578673B89605A72ULL, 0x567DC42BED903446ULL, 0x2C7A603FB3A063F1ULL, 
            0x3271E2ED9C86AF4FULL, 0x59915EA3ED456F9EULL, 0xA8E35A4059F83AC5ULL, 0x1FE12224F90E8AE1ULL, 
            0xDB2DB9428DE7F487ULL, 0xCD2F32DA4478A551ULL, 0x29D2376756EA6D49ULL, 0x6D95E95C8F81C648ULL, 
            0xD3747CF1B7361E23ULL, 0x2B299C7A86300EC4ULL, 0x3238B4CA2C7ECCDFULL, 0xE6B02C9504C157B9ULL, 
            0x5D6B513E6AEA5966ULL, 0xA42C7E6A9D53BAC5ULL, 0xDF2D0746B52BEC14ULL, 0xAA94596CB2927D44ULL, 
            0x5E65B18F2DF70994ULL, 0x3963B503E9D83EB1ULL, 0x2F751E2AD2F83A3CULL, 0x064005D3FE28AC9DULL, 
            0xCFAA325DFE2B3ACDULL, 0xCE87FC07610305D3ULL, 0xAA85F69F60B12EDDULL, 0xF65EBCC36C698946ULL
        },
        {
            0x9132725F5FD19ECFULL, 0x368909AB4550DDAFULL, 0x7BB4A50F82A3B222ULL, 0xFC259522CDF31A6AULL, 
            0x339FA7295238C59FULL, 0xD8C513968716DDF8ULL, 0xF9EB16B41727E6DAULL, 0x6B09169BEBA4458AULL, 
            0x074D3D178FC478ABULL, 0x5F2534ABEF487B89ULL, 0x6C22B076E9FC7273ULL, 0x4A13ADA004704502ULL, 
            0x024FA853804BC04AULL, 0xA054BE5D5393FE77ULL, 0x3A66495C5632105DULL, 0xB7459C99A160560AULL, 
            0xAD0DC92081A19A07ULL, 0xDD32BA0C5C6F30AAULL, 0x9B13CCB9F6572037ULL, 0xB622D08FC84FBE02ULL, 
            0x4C074F34D3D27D8FULL, 0x693E469A21F60241ULL, 0x2FBA2922A5763E0EULL, 0x20F402975F204649ULL, 
            0x867EFDFC8E1DA8F3ULL, 0x81BEF25B968B61CAULL, 0x1E1124ED68F7413CULL, 0x6B58351895374210ULL, 
            0x86B2047E3A434480ULL, 0xCB053C06A88E91B5ULL, 0xADE2C166DD9C6CF0ULL, 0x2F7199878A22DA24ULL
        },
        {
            0x9FD9A470B300ABDDULL, 0xD3A5CCCD4982CBD2ULL, 0xA33ADEEAD22F6B1BULL, 0xB2B81248971E1496ULL, 
            0xB1B179F8A84A9512ULL, 0xDD97094E4EFF8258ULL, 0x8B43611006B0076DULL, 0x11F4640A84FC434DULL, 
            0xB1EA1E152CF5A3BAULL, 0x672700F7452481C8ULL, 0x61293D9114FCE622ULL, 0x292DDD92EAC4A562ULL, 
            0x761323BE311526E5ULL, 0x2C158F20BA8E0276ULL, 0x12C94021D9705ED3ULL, 0x32AC6560DA6063C0ULL, 
            0x37B2C26E6DD75AF0ULL, 0xB71C01709FF8ABA6ULL, 0x6F7F1786FFDF8E32ULL, 0xB23AF15FE5C20D53ULL, 
            0x23E64491354A161DULL, 0x21731788192F4552ULL, 0xB900AFEB184B0923ULL, 0x2411B4886DF8DC2FULL, 
            0x915CE4F3A98481A1ULL, 0x6B6CFB471FC40960ULL, 0x62CFB8E62C1491E8ULL, 0xBABED8C59A6A8983ULL, 
            0xC2AEDBC63AC4A407ULL, 0x293FA5507EEB298FULL, 0x445D8572F9C038EEULL, 0xDC45FDDE454F0B2BULL
        },
        {
            0xE3AF336E57C1AE01ULL, 0x1DB33187EF4B4B1FULL, 0xC497C8975A08ADD0ULL, 0x1E16E740BD96C3BEULL, 
            0x2EC95691DE8E48AEULL, 0x20F641C0259BBCB1ULL, 0x3FDCC135A566F565ULL, 0xC3C20BEA449EEA08ULL, 
            0x26645676FF517E80ULL, 0x24FDFCCA80E28B7AULL, 0xA74C4952B4891A70ULL, 0xB15F1463EDBFB2E0ULL, 
            0x267B668EB541A2E7ULL, 0x7C2D34FC72724597ULL, 0x7C667573A1EE9561ULL, 0x23D7EAC31808C869ULL, 
            0x7815143E8C72B1B4ULL, 0x71A9C3180042688FULL, 0xD43260FF6434E068ULL, 0xC7CAE7922AAAC6E4ULL, 
            0x5AD594C444E2D684ULL, 0xC467EBD299B46687ULL, 0x1D2AEFD565325FD8ULL, 0x965B81D7C419EEE1ULL, 
            0x1141CDED1B11AC2EULL, 0xB76B50B19FAAED0FULL, 0x2F7117ABFB80E955ULL, 0x87F03B41ED023641ULL, 
            0x9B4125D1CEBD64A2ULL, 0x8824C487496A6AF9ULL, 0xC566F564706D4753ULL, 0x7CD770A533B7CA26ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseHConstants = {
    0x68BC593AC609B51EULL,
    0x9B83FFCDCBE60619ULL,
    0xDDABE41F72525DAEULL,
    0x68BC593AC609B51EULL,
    0x9B83FFCDCBE60619ULL,
    0xDDABE41F72525DAEULL,
    0x6A801B7C147C33F7ULL,
    0xCE4CF386E60E6DBFULL,
    0xC6,
    0xDD,
    0x2B,
    0x67,
    0xF6,
    0xB6,
    0xB0,
    0x6C
};

