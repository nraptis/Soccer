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
    std::uint64_t aPrevious = 0xBDB366DAD08C64F7ULL; std::uint64_t aIngress = 0xF0095982F09F5FE6ULL; std::uint64_t aCarry = 0xEC751A0D8F3D4E26ULL;

    std::uint64_t aWandererA = 0x87C06EAD7EBD8325ULL; std::uint64_t aWandererB = 0x871F48AF57248CD0ULL; std::uint64_t aWandererC = 0xA032635E2400A85DULL; std::uint64_t aWandererD = 0x81E0E12ABF816A77ULL;
    std::uint64_t aWandererE = 0xDB933E39A9D6A168ULL; std::uint64_t aWandererF = 0xC856E37D9E51F149ULL; std::uint64_t aWandererG = 0xDA9C2A6294862042ULL; std::uint64_t aWandererH = 0xEA2BBED48F57B6BAULL;
    std::uint64_t aWandererI = 0x899CA5F78B7C599AULL; std::uint64_t aWandererJ = 0x9C530C5EDBC413DAULL; std::uint64_t aWandererK = 0x80B18B025CD39E30ULL;

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
        aPrevious = 12516519811052227633U;
        aCarry = 12619903923902239714U;
        aWandererA = 10475141766380768772U;
        aWandererB = 15977555417175150922U;
        aWandererC = 13034532392541429615U;
        aWandererD = 14562833985514119933U;
        aWandererE = 14219225303884193998U;
        aWandererF = 9474934183423472813U;
        aWandererG = 16226498560421097941U;
        aWandererH = 12021225484393064669U;
        aWandererI = 17114357316567497750U;
        aWandererJ = 10727778650879848951U;
        aWandererK = 14097671195794713537U;
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
    std::uint64_t aPrevious = 0xDFBE8A189AB25B61ULL; std::uint64_t aIngress = 0x82C167940427195AULL; std::uint64_t aCarry = 0xF01D15E034829582ULL;

    std::uint64_t aWandererA = 0xCB54B547E095C4D5ULL; std::uint64_t aWandererB = 0x97135C3B6FA37417ULL; std::uint64_t aWandererC = 0xB9252056E3BFABDAULL; std::uint64_t aWandererD = 0xDB4D02F150B1C43FULL;
    std::uint64_t aWandererE = 0xF41BFDCCF3DC945AULL; std::uint64_t aWandererF = 0xBB1FCE85AC70DF1FULL; std::uint64_t aWandererG = 0x888816EC4D9795B8ULL; std::uint64_t aWandererH = 0xD8FE68FEC19DBF3EULL;
    std::uint64_t aWandererI = 0x99A1DBA13F2B085EULL; std::uint64_t aWandererJ = 0xF2985CC56E7658B6ULL; std::uint64_t aWandererK = 0xE1B2CD6130FBC9F8ULL;

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
        aPrevious = 16327597418601079205U;
        aCarry = 17819005795450931484U;
        aWandererA = 13157060772392460358U;
        aWandererB = 13887000247820608935U;
        aWandererC = 17225031071142476351U;
        aWandererD = 9611223769102028213U;
        aWandererE = 16236455855083831459U;
        aWandererF = 11706817327001272639U;
        aWandererG = 13341346844285809321U;
        aWandererH = 13165567797711608667U;
        aWandererI = 16440931182410485050U;
        aWandererJ = 16551828873937059340U;
        aWandererK = 17354936787111813343U;
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
    std::uint64_t aPrevious = 0xAE849AF2BF0CEA48ULL;
    std::uint64_t aIngress = 0x9D42FF8A6AC54A30ULL;
    std::uint64_t aCarry = 0xF24B974D1CF807FBULL;

    std::uint64_t aWandererA = 0x8DB5655434393543ULL;
    std::uint64_t aWandererB = 0xE849DE55B80188D7ULL;
    std::uint64_t aWandererC = 0xA726C751484FC01FULL;
    std::uint64_t aWandererD = 0xAFB28F1E6AD8E20BULL;
    std::uint64_t aWandererE = 0x8BA94EAF3B03AFFCULL;
    std::uint64_t aWandererF = 0xE0ED430713C48BD5ULL;
    std::uint64_t aWandererG = 0x8FFE58B3261ABBD3ULL;
    std::uint64_t aWandererH = 0xE5E50431000D9315ULL;
    std::uint64_t aWandererI = 0x993B9F31D4EB5088ULL;
    std::uint64_t aWandererJ = 0xE262533C664E4252ULL;
    std::uint64_t aWandererK = 0xB46D2F175E05F34CULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
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
    std::uint64_t aPrevious = 0x8177B17952FBFC80ULL; std::uint64_t aIngress = 0xB8103D906FA03EEDULL; std::uint64_t aCarry = 0xE92F73D988D5949CULL;

    std::uint64_t aWandererA = 0xA5529F374C61BC86ULL; std::uint64_t aWandererB = 0xC5CCD6025267504AULL; std::uint64_t aWandererC = 0xAE231D337AEA1560ULL; std::uint64_t aWandererD = 0x8EAD2D8E8C7CEBBEULL;
    std::uint64_t aWandererE = 0xD35FC98729FB77E1ULL; std::uint64_t aWandererF = 0xA1B339BB5DE91CABULL; std::uint64_t aWandererG = 0xE55B332E82C85676ULL; std::uint64_t aWandererH = 0xCF9D053EF1B7B985ULL;
    std::uint64_t aWandererI = 0xF5FEB77FCA325235ULL; std::uint64_t aWandererJ = 0xFD424018D4B1E5FBULL; std::uint64_t aWandererK = 0xF665433BEEDD89C9ULL;

    // [seed]
    {
        aPrevious = 12932775090432178721U;
        aCarry = 10747452417925900280U;
        aWandererA = 16442070385654871585U;
        aWandererB = 10985201422060227282U;
        aWandererC = 17681617963992390446U;
        aWandererD = 14650706977488496224U;
        aWandererE = 16770360329953808172U;
        aWandererF = 12469153472362501835U;
        aWandererG = 10282914400088007628U;
        aWandererH = 10372024386048093120U;
        aWandererI = 14362080376628654857U;
        aWandererJ = 14896000620951273666U;
        aWandererK = 11840512585768252947U;
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
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 1 with offsets 6249U, 6938U, 620U, 2047U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6249U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6938U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 620U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2047U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 0 with offsets 609U, 3815U, 4356U, 7903U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 609U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3815U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4356U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7903U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 3 with offsets 6154U, 1181U, 3290U, 1026U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6154U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1181U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3290U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1026U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 2 with offsets 1009U, 6140U, 4363U, 6845U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1009U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6140U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4363U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6845U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 2, 0 with offsets 1105U, 1941U, 508U, 727U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1941U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 508U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 727U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 3, 0, 2 with offsets 1779U, 1048U, 1449U, 1000U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1779U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1048U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1449U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1000U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 1, 2 with offsets 1686U, 533U, 1403U, 1718U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1686U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1403U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1718U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 2, 3 with offsets 60U, 1248U, 2005U, 1132U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 60U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1248U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1132U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 561U, 882U, 365U, 1994U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 561U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 882U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 365U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1994U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 3 with offsets 3384U, 2442U, 7714U, 7463U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3384U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2442U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7714U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7463U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 2 with offsets 4120U, 8079U, 5501U, 6025U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4120U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8079U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5501U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6025U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 1 with offsets 1682U, 4251U, 2110U, 6437U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1682U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4251U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6437U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 1, 0 with offsets 7181U, 1870U, 1412U, 1872U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7181U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1412U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1872U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5785U, 4043U, 7939U, 2081U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5785U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4043U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7939U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2081U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1540U, 1987U, 132U, 1482U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1540U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1987U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 132U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1482U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 772U, 1416U, 943U, 1573U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 772U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1416U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1573U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 943U, 212U, 663U, 1255U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 212U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 663U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1255U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1393U, 2011U, 180U, 443U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1393U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2011U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 180U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 1758U, 1483U, 720U, 1548U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1483U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 720U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1548U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Karate::kPhaseASalts = {
    {
        {
            0xC45A773AEE4D5A24ULL, 0x84BC62852495BCA0ULL, 0xDDDA7BA427DB7539ULL, 0x82F4F7600DF98000ULL, 
            0xA397B4DFCA27338BULL, 0x2019F067BEF6191CULL, 0xAE22DC92725BA17CULL, 0x0245EEC2900BF777ULL, 
            0x7708B177085C0C61ULL, 0xF5020C78FBFD66C0ULL, 0xCBF98D78F69A2FA1ULL, 0x4FD57D9399797F3BULL, 
            0x3E3A9483B9F04F51ULL, 0x601BB27B7E0A8D75ULL, 0x2A2AE67B6FA5832BULL, 0xF9914195C96399DBULL, 
            0x98D273E220F88B33ULL, 0xDACF2341CCB8102CULL, 0x59FFB75A8C6FBC43ULL, 0x35954858E3193B57ULL, 
            0xF9ED77B206377348ULL, 0x82F3824E47C80F5AULL, 0x3CF7D65D40CFB3B0ULL, 0x915B3FA4856F0C78ULL, 
            0x44D7ADA28622EE5FULL, 0xFBB089DF32420EDCULL, 0x8F0F2D9E66DA0F94ULL, 0x66DB5FCBB3EFEB9DULL, 
            0x03A8F1C112C33B2AULL, 0xAB0D87CF5ED97C81ULL, 0xD697481A8730C5B8ULL, 0x7AF819B533C066A9ULL
        },
        {
            0xA8B6F88403E7ECA2ULL, 0x9FBB7CCFED245F66ULL, 0xF15B297BB479D252ULL, 0x8476D3748B43036BULL, 
            0x2D57D87DFE16CB15ULL, 0x7A126E65F6F0F9CDULL, 0xED23F3D47A4C799AULL, 0x61F2AECA337DB39EULL, 
            0x7C6F1879E520CF43ULL, 0x4123DDBE646A5A93ULL, 0xBC35AF57C19AB3CDULL, 0x031948C05150B792ULL, 
            0xB7519483C114799EULL, 0xE1B8C4CFD87F57BCULL, 0xA2A7F6664EAF4001ULL, 0x42442A61FB33851FULL, 
            0xA36B2BF6350B0E25ULL, 0x885474C50F458CE4ULL, 0x3D70E026BA74C887ULL, 0x731F1EFE7F51226DULL, 
            0x5C7B21AB1949DCCEULL, 0xCFC9A1DE2E9D8649ULL, 0xAE3922E47E49C186ULL, 0x9AAFA2F9C8C10057ULL, 
            0x6A1B2D4A61E205ACULL, 0x344DC637A96C8D53ULL, 0x0818CF19425AFBC6ULL, 0xA66E8F96DEDB25B4ULL, 
            0xD3B0C0DE6FE1CFB6ULL, 0xEA61DFA9FE7BA5D2ULL, 0xC81BCA23E70CBC78ULL, 0x9E7114B902E80470ULL
        },
        {
            0x89E55030251BA781ULL, 0x47BC8E1C4204DFE5ULL, 0xBB72D8B1A8B2E0BCULL, 0xF2B5DCBE8202EBC8ULL, 
            0x407212C4CC31310AULL, 0xD1D27296D7E747CFULL, 0xA04861BF8B8C0A90ULL, 0xF6F89A38AE40DF8FULL, 
            0x59E33F1E6C2B6866ULL, 0x89EE005BF71CAD0FULL, 0xF55E4B7C9B79A92EULL, 0xB0DC1133D52763C3ULL, 
            0x7DF4DC13D8D48572ULL, 0x6C4BA4ACDEFD9B90ULL, 0xD525762010D8174FULL, 0x4E9EB7FBE70FA9A8ULL, 
            0x9E47FD51B7FFCE75ULL, 0x9FDCADA6CDBF4B54ULL, 0xA952735F996C44D8ULL, 0xB8515B8F68AE3C48ULL, 
            0x229F3B693F584FEEULL, 0x5C821D21038CE5E7ULL, 0xF0195BAAD1B0F2D4ULL, 0xE3A7F7128DADEE5EULL, 
            0xFB221BD460C065EFULL, 0xE1FDD37DC9365678ULL, 0xB3316D3AACE93E0DULL, 0x971CE8A27DE114CEULL, 
            0x06F093F878BAD79DULL, 0x82A29B70FE51DD26ULL, 0x996908E3D04582B0ULL, 0x227068F8D24A5427ULL
        },
        {
            0x4FC397568B9F0414ULL, 0x41012BA431B654FEULL, 0xBDFCB98393DB35E7ULL, 0xDEA89805DFE80E0AULL, 
            0x2B671AEDE8BD0286ULL, 0x8038DF9B558CFE8FULL, 0xC353B0BB03F874A1ULL, 0xFB81667B7603BC0CULL, 
            0x6CB88677E425954EULL, 0x4CEFA9F0C106A357ULL, 0x553CCA511831CD9CULL, 0xD66E86C478584DB8ULL, 
            0xC4E0FA3D323BE329ULL, 0x92C89BE08A4098D8ULL, 0x681A770A5D01B219ULL, 0x1F848918FA7B2E0AULL, 
            0xDCFAD7D2838C2267ULL, 0x6B098E028B179CA7ULL, 0xFB3CE47A321A5A4CULL, 0xCEB8F2FACAE8C5DFULL, 
            0xE94861DF19E4A6AEULL, 0x803A7581BE93D43EULL, 0x806095DC615F9E46ULL, 0xC78B2598EB186AF5ULL, 
            0xF7A9C6B33B0AD526ULL, 0x1A0C5A2EBD4ADCEEULL, 0x81294EC9A68C832CULL, 0xFB4F994D47567810ULL, 
            0xC3FB3A32C53374F0ULL, 0x2D10250E5F315592ULL, 0xCD9238ADE344DF9BULL, 0x11842587DC02589DULL
        },
        {
            0xA7B675D4D736B34AULL, 0xDC61DEEE5C9CC95EULL, 0x23696658D2B2D5D8ULL, 0x0568F613C8EA6E68ULL, 
            0x76BB7B556925AE4FULL, 0x3BC27A5D3A143C41ULL, 0x3AF494D9E15C54F8ULL, 0x441A4DE49101D046ULL, 
            0xCEB5A750E0A9F228ULL, 0x09E18B270AADEF3EULL, 0xA829D8EB7AA7CA7BULL, 0xA09ED8830118A402ULL, 
            0x12ABD7E26F31032DULL, 0x0C6DEA73B77E0C01ULL, 0x20DB5F6D805194FDULL, 0x525616B6EF364EEAULL, 
            0x7D9DC4FF7BAA3866ULL, 0x8A4474C8A1B572E3ULL, 0x1A8928A94C5AB448ULL, 0x62986B23A5D5017EULL, 
            0xF8658BD392E8AFFDULL, 0x3FBE17E436566A5EULL, 0x7DA070455BAE18F0ULL, 0xC3FFA10B077255B0ULL, 
            0xC59D449B496A1135ULL, 0x8D978C5B9FFD0D3EULL, 0x96A51AA070D5BCF6ULL, 0x0D5E4D2C6742C560ULL, 
            0x7868D633777F500BULL, 0xDA0BDEAA84C7BC26ULL, 0x915F481CA839134EULL, 0x1A5DE3F053947D75ULL
        },
        {
            0x9D3A084B772D99CFULL, 0x97EF46C0F5C975D6ULL, 0x902F180DAFD0EEFFULL, 0x6674E8BF2BF8351BULL, 
            0x17AEB2719DCC264CULL, 0xAFA063BCEBF6AF05ULL, 0x3EE4D94CB9CC43B5ULL, 0x66A7065142A026DBULL, 
            0xA1EE73817302E679ULL, 0xBE5FDAF7C4835655ULL, 0x7DBB0E7FB9D39131ULL, 0x558E71D6AABA8388ULL, 
            0x930B512BED19D0A1ULL, 0x33927FCCC51F4CFDULL, 0x4268E1F0FF43B024ULL, 0x9D95B43BBF1DEFD0ULL, 
            0xE4FC8D98356BAAF3ULL, 0x2A3674E4EBB35791ULL, 0x10EB940AF4143EC6ULL, 0x4B1107AEF3C07CEAULL, 
            0xF99FDD3A647CDB9DULL, 0x30142D0B9529DF21ULL, 0x0C0E6DC6EF8EB920ULL, 0x1BFD125919045FC4ULL, 
            0x5A144F6DE0FBA147ULL, 0x8B1FCEF27994EF2EULL, 0xF6CBC3EA12E3BF98ULL, 0xB462461FDF0BC29FULL, 
            0x583B1F2C8B9C4EFBULL, 0x3A6DCEF5177646ECULL, 0x40E7C57387533C21ULL, 0x6EF7824DBC2CDCD5ULL
        }
    },
    {
        {
            0x879B48BF36004586ULL, 0x59895DEE2EF5FDECULL, 0x98AB081C312A97B8ULL, 0x81663BD111417F29ULL, 
            0x82C09AEAE3ED56C5ULL, 0xD4F92AE973CEFA07ULL, 0x6692F31F571AD0A7ULL, 0xD9ABEFCA9132AA89ULL, 
            0x9A74039A8080C9C0ULL, 0xCFCEF810E7481B4AULL, 0x2026A3041620997BULL, 0xE1405C2CDEF58763ULL, 
            0xA5AA5A5D0EBE22F9ULL, 0x20C12099E4D0FFF6ULL, 0x5DFF0F3D2B93CA3CULL, 0x2A657C15242C3B98ULL, 
            0x34865624AA377ED0ULL, 0xAC5BF9E013FC49AEULL, 0x6CA1DC0958AC7A7BULL, 0xB910EFA3BD7B247BULL, 
            0xFD74A026CB771D61ULL, 0x30EA1DC9ADE880F1ULL, 0xD0BA22B15B345C17ULL, 0xBF00A04190BCA43EULL, 
            0x2F93DF5B104FE251ULL, 0x5CC404B84EFBBD1CULL, 0xC696C4035F25F752ULL, 0xAED7CA6B0063B92AULL, 
            0xFEE68EEA2873A697ULL, 0xD05A6DA834D30369ULL, 0x1910BEB5C2A8B527ULL, 0xAA23AC4374FFC3AFULL
        },
        {
            0x59DF68845C96FDC0ULL, 0x96D8EE62E13A6530ULL, 0xB26071E6316E349AULL, 0x69B8B493E1791408ULL, 
            0xDE48D37E3481572FULL, 0x75FA15A6DDD14A7BULL, 0x3094B4F35B3A0F28ULL, 0xBC0A7FDDB8BD3AF2ULL, 
            0x9CA1B23BBCBF3834ULL, 0xE6F0CAF388C8702CULL, 0x268C76F6FC60935EULL, 0x41EDF2E276E98C33ULL, 
            0xB918798AAB808316ULL, 0x2618F019BE55C9DBULL, 0x1A11523E5A947FC2ULL, 0xFB04C0A09B629B91ULL, 
            0x7F1C5DE23C2A1F1DULL, 0x6D0C8F4D18B07DC8ULL, 0x4C6AF606CD64F656ULL, 0x80C5037A35BFF7C4ULL, 
            0xD253CD3E8BFF8EC5ULL, 0x656A6884E562420FULL, 0xBEEB685D06B37E52ULL, 0xDFE409724FCCD561ULL, 
            0xFD39F60111539703ULL, 0x9EECEA8E4B79714FULL, 0x0914CF5395D10AA7ULL, 0x38677FE6264D3A79ULL, 
            0x660F5446895DE4FAULL, 0x66B83B6B07545BA2ULL, 0x5FCCA7A7A8CF48D9ULL, 0xB2FE7449ED728E97ULL
        },
        {
            0xB52EEB0DE4DCC550ULL, 0x86AFEBB872294E9AULL, 0xCC0CF9ED867B5660ULL, 0x34C5434F68F53827ULL, 
            0x4CA663ED57E47A00ULL, 0x1A731458240853FCULL, 0xC4F88D29066F8544ULL, 0xAF55A8F4FF8F8C0BULL, 
            0xD4E471A5243A752CULL, 0x68CBED8B8FB714AEULL, 0x12D2DE0A259CAA86ULL, 0xDFD4CE6F86E353E8ULL, 
            0xB27A907EC5181DB4ULL, 0x710EFD4E8218A543ULL, 0xDA14F876CAA196D8ULL, 0x7A8E259B73DF97D1ULL, 
            0x8F25D3BED20858D2ULL, 0x2720FE60322783B9ULL, 0xBD40CAB131A54991ULL, 0x9387F6F8DD0B9FF6ULL, 
            0x3178FF4133B24BCEULL, 0x1030F696E497D8F3ULL, 0xD916C2875E0D2A7AULL, 0x2F91D52C50890BF6ULL, 
            0xC6BBFBFD002E2306ULL, 0x2812315158A89160ULL, 0x58D3C6F259B13284ULL, 0x8AEB7EB2F0792939ULL, 
            0xC817EFB38B8E7D27ULL, 0x99E2BC7483B241DFULL, 0x482C5E0036FCCB01ULL, 0x7455963793B75F65ULL
        },
        {
            0xFC7B5FE4117C5EEDULL, 0x8096F7D9C1362D05ULL, 0x79F9B16F10D0B06FULL, 0x7246670F65534C8EULL, 
            0xC2C26CB8D3BAC921ULL, 0x6A30530309A18B4AULL, 0x834944FACF3345D5ULL, 0x6510A74A110F719FULL, 
            0xB29DAA3A5B8D7F5BULL, 0x7917B7C5317DD2A7ULL, 0x90939BC10B2F7F3AULL, 0x1CC7E60C390EC12AULL, 
            0xB6F305A3856A42B2ULL, 0x00F010D40C1CB403ULL, 0x71168F7327014322ULL, 0x108A63D2E8B70ACFULL, 
            0xF89D0445B018AC9DULL, 0x03C7FF87469C0067ULL, 0xDC0BDF32B38D8A94ULL, 0xC85A2CFA93885501ULL, 
            0x4A0DB0D746A5F417ULL, 0x1DBC1CDBA4AEB473ULL, 0x1885CE71026E2ECDULL, 0xD96821609D726E4FULL, 
            0x608FBA5AEB3FAC45ULL, 0x6A5B53154D0D9671ULL, 0x48CEEF92F02C906FULL, 0x5CBFBA0100A91AB8ULL, 
            0x428D4C3789719E4BULL, 0x431F8CE6524CA492ULL, 0xBB2F0253BAEF79F7ULL, 0x78441799F3A6A24BULL
        },
        {
            0xA21E5675EBE7509CULL, 0xE53980F21FD52B1AULL, 0x5003371E8B22E845ULL, 0xD87BB580628C24A6ULL, 
            0x55B79EEB23D9319CULL, 0x81DBADF62F67D382ULL, 0x6B361C5EAB7DB625ULL, 0x1C3157309506663AULL, 
            0xDE5700FED7AE54B0ULL, 0x1116C8ED84C02DFBULL, 0x237B3CE57F6A98CCULL, 0xBDEADD783C2D6CF1ULL, 
            0x8F96CF7D0E9D9E4CULL, 0xD54A87004D41EBC6ULL, 0xABA405DE84283D6CULL, 0xB78C9AD846BFA871ULL, 
            0xEE78D85B0E6311DCULL, 0x28C74A76D83142B0ULL, 0x050D6AA8155F771BULL, 0x984E0C336E9D5A0DULL, 
            0xE32E6E3AAE19F434ULL, 0x047A5EAF09AE8AECULL, 0x99A77514E8889443ULL, 0x313C76231F42AD36ULL, 
            0xEB6A8A13BF5FC517ULL, 0x3B46BF7A9BF23248ULL, 0xD222832F45FDAC8EULL, 0x28639AB088B9B1F3ULL, 
            0xF5ED812BEACB0CEAULL, 0xDC2DBF69C0A0AFE6ULL, 0x9221652E07764849ULL, 0xDBD0FB6579A73DCBULL
        },
        {
            0x1C1474BC103BD399ULL, 0x457CA04304E65D18ULL, 0x6E2B18AF2D4705DEULL, 0xAEC4C67B194E9429ULL, 
            0xF4DB724845B77D2AULL, 0x9182DDE1845976D9ULL, 0xC9D09C6392DE47C6ULL, 0x5DAA4C656D4DFE94ULL, 
            0x3204DE99E3A1D234ULL, 0x59E003D58B2F04E6ULL, 0x80DA5AD0DBEE66CEULL, 0xCF3414C200F6EDAEULL, 
            0x3251809D4ABDE8A4ULL, 0xAF3A82EDFA9A0DDBULL, 0x0796B2F2D0138476ULL, 0xA0F7A5A72C9E8E65ULL, 
            0x841D40D75A5250BEULL, 0xAEA68ACEE16A522EULL, 0x37181A8BACAB865AULL, 0x674A07C7D8CB4577ULL, 
            0xA479F6D67FAC77E7ULL, 0x56F1C6CEF328B5FEULL, 0x8F2DFBF4F994F019ULL, 0x8B0B9ED6F4F823C3ULL, 
            0x19BE34CE0BC14206ULL, 0xB54D44BF14E88160ULL, 0xA17599A74D76BE8CULL, 0x7A836F157CA47CB2ULL, 
            0x18544FB875235E7DULL, 0x99CA36623E0A83D3ULL, 0xC38F699769FF11CCULL, 0xACE7BBBA7CB5E64BULL
        }
    },
    {
        {
            0x9D7EF44700316162ULL, 0x99B7C4382FBD4209ULL, 0x070F58B5769C8F87ULL, 0xF57609F019F7A751ULL, 
            0x54121B5AED9B7B41ULL, 0x6044731FFC881C46ULL, 0xDB700BAC38D0239AULL, 0x6503B94414FEB18FULL, 
            0x497925C523C07208ULL, 0x53DEF3960D93E4A6ULL, 0x759D52E31F9217B7ULL, 0x5464DBED6B4C0DB0ULL, 
            0x40D0E855ADBD9AD7ULL, 0x6E70E6A7705F70FCULL, 0x1C4F546AAD800511ULL, 0x6EC5A1FD9BA4FA9EULL, 
            0xEAEAF5D5AFC729B8ULL, 0x86E4623A3FB3E565ULL, 0xC460E9DF8DE80495ULL, 0x8E8A3581D1F12C02ULL, 
            0x461B5D5D6B6A0820ULL, 0x9153A7782D87D0CFULL, 0xB9045C3DB01AC9D3ULL, 0xC6AEAC188BB519B4ULL, 
            0x558AF114265CC952ULL, 0x5E4B403FC1E986B1ULL, 0xD7411BDE3A0765D6ULL, 0x792BE2CC2601B581ULL, 
            0xEE4DD877500C6C02ULL, 0xA98181F6C411C80BULL, 0xF030F1070DBB265EULL, 0x566C1BF013C2C695ULL
        },
        {
            0x39193D31390C7155ULL, 0xEA3B8FFAC0E8C56EULL, 0xD4FEDCE7D762D03AULL, 0x13485C3142E0D869ULL, 
            0x58B2C6673D8E7C65ULL, 0xAF830FEACB61341EULL, 0xF21DAB457C262937ULL, 0x34E7961833183C46ULL, 
            0x6625F9C6577FC282ULL, 0xB111F77FC258E92BULL, 0x83BB467857955345ULL, 0x6DA6D27DADEACC35ULL, 
            0xAD8D5A0B6EEAE755ULL, 0xD0106616824421FDULL, 0xE5A21CEDA900FBB8ULL, 0x6844DE0C9DA5E883ULL, 
            0xB4CD9B1437781062ULL, 0x8F2CAB3C62EC79E4ULL, 0x3CEEAF1AA8D1AB9EULL, 0x7EA9C80617C3D1F2ULL, 
            0x7A260AB1F4D4C307ULL, 0xA370D01AC8564D41ULL, 0x85345AC900A0C9EAULL, 0x44ECCBA6AF9126FBULL, 
            0x61815AFCF9F3A4A9ULL, 0xEB9332A933AA4CB1ULL, 0x5983950E0927D708ULL, 0x55187B6925A189F0ULL, 
            0x2784F6F35DD7803EULL, 0x7E2DD524AF0CDF65ULL, 0xF84C98057C8F69BCULL, 0xB134CB1440B26E92ULL
        },
        {
            0x2A852382B98B0733ULL, 0xC002D76EEF58EBDBULL, 0x5EE168FE838B1B89ULL, 0x0A5C7AE839B688D9ULL, 
            0x41A38DC818F48FBBULL, 0x32C734AD34093329ULL, 0xAF8223E7A4D19CCBULL, 0xC09168F9E1A01ECFULL, 
            0xA5D70EEA4416AF56ULL, 0xCD7BEC26A4D16685ULL, 0xB54379C4FB6B57D5ULL, 0xF6F963D72E1148AAULL, 
            0x3FF5DEC6691CBE02ULL, 0x29AE691E1F387970ULL, 0xCCCBDCDC21091C1AULL, 0x0F1087F69BAFF582ULL, 
            0xA11E9B615904C691ULL, 0xA7EE96ED5D9987B4ULL, 0xD1577FDA93562F98ULL, 0x47287D14D8B780B2ULL, 
            0x699362EA246122F1ULL, 0xC6FABED34920239DULL, 0x75B530901F354294ULL, 0x8758B23E92C8BFCCULL, 
            0x3B369141A1CD90B8ULL, 0xE7DB83E745D0F108ULL, 0x07909EF43AD90A85ULL, 0x6270FCBCF17FB8DDULL, 
            0xC6318B693B52566CULL, 0x5FBE7ABA94370F9DULL, 0xB65ED3F78285DF82ULL, 0x4C5A67822AC0787BULL
        },
        {
            0x132914993F486656ULL, 0x022E4A889B85FBEFULL, 0x5269410055579FC7ULL, 0x26EF5007E016286FULL, 
            0xF293E1DF21AC3ABDULL, 0xF17EC47BB64C3B7BULL, 0x481041C231132230ULL, 0x4F610E9BB96FA439ULL, 
            0xBE980055A1EC019EULL, 0xC7B86DF43AC70DDDULL, 0xACA67BE46BA1A382ULL, 0x390D4583F0115A76ULL, 
            0x471C0F89EE63BC35ULL, 0x1F08EC4D28B36573ULL, 0x4D9968C7B631E872ULL, 0x89561636477F90BBULL, 
            0x901F4E429137238FULL, 0x06245F5C070BCEE7ULL, 0x2BA16EB1AE8FE854ULL, 0x98543D895ACF42CEULL, 
            0x3CC35853CB4F7E90ULL, 0x526172F11060F6A2ULL, 0x64FC7A8737BE40A7ULL, 0x5F0C149258DD9D72ULL, 
            0xA42387ADD248C672ULL, 0x01E97D5385473F4CULL, 0x1C2060EB563BFCFFULL, 0xD7334ED166F1FBCBULL, 
            0x27234BEB949C97F0ULL, 0xEC346DFDD4C5FDC7ULL, 0x4705BE27729126E4ULL, 0x3C7CB966C65B0A74ULL
        },
        {
            0x44555F78CD2E0501ULL, 0xC3D071EF8682C915ULL, 0x3BF816156597D13EULL, 0x9C2961BA1D65ADCCULL, 
            0x8B56E243749B5577ULL, 0xDA4666725BEC99BCULL, 0x8A6082A4873A3DFEULL, 0x08E3B17984CB58BCULL, 
            0x2D83CA92175F1EABULL, 0x0125BF33E66FE365ULL, 0x564504175EBD98CCULL, 0x4958846411CEC3DDULL, 
            0x37A03E97749B01D7ULL, 0xB2465B942FE675C1ULL, 0x9E9B7B13E7C325FEULL, 0x0196CA2B107F9D6BULL, 
            0xB9EDB461ED60E805ULL, 0x453AF828507C19DCULL, 0xBCCC0013EC1891C0ULL, 0x8459AE75371CCBBCULL, 
            0x430EB2359B60568DULL, 0xD39243A8816E5AABULL, 0x2FB78402FE5A3450ULL, 0xAAAB62FE340C742BULL, 
            0x88847E50B4DF1B40ULL, 0x2CF263558A3162BEULL, 0xAB82251447D2C07FULL, 0xEEB064431DB2A2A5ULL, 
            0xE2B074D429744EF8ULL, 0xF3CCDD2453161829ULL, 0x24D398DA08391CE8ULL, 0x7F842372A3C52457ULL
        },
        {
            0xD6C19EBD6ECD40CEULL, 0x68534F1ACAFA2945ULL, 0x0C540DE7F366EA24ULL, 0x299E638CB91E5AFDULL, 
            0x15873F14C8CF44C3ULL, 0x010A72BF02574885ULL, 0xF5DFAC112F11B7CAULL, 0xEA6F90E46C3C1CBDULL, 
            0x0A53AD2939028916ULL, 0x80E35771F8157BD7ULL, 0x13E9C29613D31374ULL, 0x3E856907B73EA38AULL, 
            0x5805C48DD5A310F8ULL, 0x172D4F775F191533ULL, 0x642D8904CAA5C3FCULL, 0xA4012A567AE8B205ULL, 
            0x17C9630F84B0A20FULL, 0xE0943F9BF61ACBF5ULL, 0x94BBE9F22E053612ULL, 0x9C4788FE34EA0BA1ULL, 
            0x143C493EBFB23F56ULL, 0x6FE050D8FE8B71F1ULL, 0x1AA0FBE0B347707AULL, 0x60310F4B3530D0B7ULL, 
            0x4A304BE0E7A59622ULL, 0xAF3D276E3F9420F3ULL, 0xE1F3059E7C3186CAULL, 0x54F55778BE0A3815ULL, 
            0x3E80C4268E6443D0ULL, 0xAB240EEE535C0A03ULL, 0x74204B00CC612E48ULL, 0x20B4DA6FC76C4375ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseAConstants = {
    0xD337093080D2C07FULL,
    0x368D97CE6D78F017ULL,
    0x971ED172879F6B9EULL,
    0xD337093080D2C07FULL,
    0x368D97CE6D78F017ULL,
    0x971ED172879F6B9EULL,
    0x026E35630ED45F2FULL,
    0xB5E29E07426884FAULL,
    0x68,
    0x7D,
    0x82,
    0x78,
    0x51,
    0xD6,
    0xD4,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseBSalts = {
    {
        {
            0x3CDA2D4B302BCEF5ULL, 0xDAA7735244638EC8ULL, 0xFB6D471AE56F32FDULL, 0x8E3F2477ACCB0757ULL, 
            0x599C07EC9E5B40F3ULL, 0x90B0B93C1B6C5F7AULL, 0x2125511BE21CA888ULL, 0x288D1A5A8CAD8D07ULL, 
            0xA9E642BA2C130BA6ULL, 0xE44ABBFCD6E08CF4ULL, 0x7494911C9DB1D752ULL, 0xA8BFBBFBC3801BBAULL, 
            0xD7BFDD219F2FC402ULL, 0xAEE610C6CF350B9DULL, 0x29F2DB55521A71DBULL, 0x23405E30DEFC04FFULL, 
            0xA94AE322E90E95CFULL, 0x248ABAC00710B760ULL, 0xD9EB4FEC57A7C774ULL, 0x096F129FE5D5BF3FULL, 
            0x78C261A81601CF22ULL, 0xB34505D5B610FE15ULL, 0x21B5F35FC6E49836ULL, 0x50BD0630D39CAC02ULL, 
            0x59197CE62AA596FFULL, 0x422C99359209DB42ULL, 0x9A8F383906916B75ULL, 0x537457A6AEE05552ULL, 
            0x6A58DDC4831FC444ULL, 0x93EA89DCD291AC21ULL, 0x86ABD71C8F8154A5ULL, 0x3581F62D00B8B57FULL
        },
        {
            0x037FB63BA13D278DULL, 0x5D87DEA363B33DFDULL, 0x9C35830D6A7C6516ULL, 0xEEBD5944D863B61FULL, 
            0x94D9E0E1F00BBF7DULL, 0x354768C60606595FULL, 0x628AAD9DB78CEB04ULL, 0x75754514A5936587ULL, 
            0x5B23A893CFD38011ULL, 0xD12248157C2520D7ULL, 0x6F3E65AD3B76D3E8ULL, 0xB3A603E74149DA50ULL, 
            0xB15CE95A1DC53C13ULL, 0x310258658B9B8AC4ULL, 0x9DB4ABABFC8C9E0AULL, 0x9841F9D23BA0497DULL, 
            0x53053176159DFEFEULL, 0xA8360ECCD8E377C0ULL, 0x1AFB96281973009CULL, 0xC4C82CE25F7682DEULL, 
            0xE4B4F13D357CD496ULL, 0xFE68BC6F426BB5C0ULL, 0x145ACCFA76BAFBF9ULL, 0xD66EE4F2EAE19B4BULL, 
            0xEF31A1ED556CFF26ULL, 0x374CBF60AA7A8D21ULL, 0xDC84568900394571ULL, 0x1EDE17801E3CEF40ULL, 
            0xC584BE2C3A0DD23DULL, 0xA57C037FEF65209DULL, 0x2A00E982998606A3ULL, 0x41D5F1E903C56CE4ULL
        },
        {
            0x53605D5C46779D69ULL, 0xE36ECECA4BE2070AULL, 0xC43DC45C073B8785ULL, 0x8C4CE9FB5FBA7E85ULL, 
            0xB63D2EF819610382ULL, 0x47B60C1603F59D05ULL, 0x5D8D81065C7E0091ULL, 0x6D5B204A258BBB6FULL, 
            0x37E920B3E3234ED2ULL, 0x65B0631F549E4468ULL, 0x9E714F2C175CF841ULL, 0x63AA83B9D6934356ULL, 
            0x69EA8E7594FF33B3ULL, 0x68E631B03750376DULL, 0x22DF37023A2EAB11ULL, 0x398A92BA8F19CAB0ULL, 
            0xD8C813EA8383CAB8ULL, 0xB0C7696D2320250CULL, 0x109B6EAB94BA0578ULL, 0xF495D250F3C34679ULL, 
            0x3B999D5321C955BAULL, 0xB0B2AD3E73BC4091ULL, 0xEBA966D81BDBEEFFULL, 0x25892AAA279EC505ULL, 
            0x28AB30B63C6C5007ULL, 0x83379D23717A12F0ULL, 0xBCE5150B7C06E69EULL, 0x324C8963ED9EBDE2ULL, 
            0xC1282EAF93DADD38ULL, 0x1BC475A1AF232138ULL, 0xF275683730D44784ULL, 0x8B75EE6D1EBDB8E2ULL
        },
        {
            0xC55B4760C081C68CULL, 0xA00DD11F76BCA510ULL, 0x6580396540144AAAULL, 0xD149E91B8A5FBF73ULL, 
            0x8E7C8A2A459B690AULL, 0x7027437930742B4BULL, 0x5685A4CD04EFD1BCULL, 0x5628ADB36DFCF210ULL, 
            0x71BDE4D52243A6C3ULL, 0xC5C308948479BCEDULL, 0x97B520A66B0866FCULL, 0x8493773FE1DFFF73ULL, 
            0x551117E5A3908F80ULL, 0x59961B23CB8ED4DEULL, 0x237E72781F526017ULL, 0x10103F41F367235AULL, 
            0xB2027E82A64957E9ULL, 0xBC505B518BDFC940ULL, 0x67E5980E40E3923CULL, 0x57E2D39A0AF37B67ULL, 
            0xDE69CB33BE01B84EULL, 0x394F3892D34157FCULL, 0xD3C4D7AFC7627AC4ULL, 0xFAABEF856D4873BDULL, 
            0x096DBF9C95F5FEFBULL, 0x3E6D459A7537B009ULL, 0xEE168DE7A7D5DC86ULL, 0x8D12B03AD42F958BULL, 
            0x599CFAC670342A34ULL, 0x4F8F34AEFA36BE2AULL, 0x24F57D598590EF9EULL, 0xE07AAB9697247F11ULL
        },
        {
            0xB2A16A592A308F25ULL, 0x0092C932631FF371ULL, 0x23D88C13C67C2BD5ULL, 0x24D44ABD89FA9295ULL, 
            0x0C5287A36F0FBA42ULL, 0x3434A919A7B6432DULL, 0xAE22C72CCF7D5707ULL, 0x10F43ED80321EF7DULL, 
            0xD45C982AEA2564BAULL, 0x0D9B93060F099260ULL, 0xE0B7FB9F8998793AULL, 0xAB48F5F8A341C4E1ULL, 
            0xF5822FC5B202B449ULL, 0x6A55CD1F47B7A65CULL, 0x5C55B7D9D5D7139AULL, 0x180274116B7D1D34ULL, 
            0x6963920462AB00DBULL, 0xB3FD7BB67593DF3AULL, 0xB72FEA5D8624F47AULL, 0xA3CC0D3B0F2BA44CULL, 
            0x0222C67D3B2C73ADULL, 0xFC87B05EFA28B9C8ULL, 0xD2D0436040AF605BULL, 0xEF53C108CD8E2145ULL, 
            0xCB841149D780CDE4ULL, 0x704672B056E189BFULL, 0xED2BFA2E202AC3E1ULL, 0xCDB50C70C403DB9CULL, 
            0x21E913E06A91647BULL, 0x57F9125A2897BB04ULL, 0xFA1B48F116BB0699ULL, 0x7D34481B772A4419ULL
        },
        {
            0x33A04D094FB1254DULL, 0xD73FC91E4CC60BE5ULL, 0x2108648B853802A2ULL, 0x0DCC9D91C3416188ULL, 
            0x51DF16A36FC89D54ULL, 0x155B7554AE30129FULL, 0xBB15F4B24DA25A07ULL, 0xAFF9E0CD1754F1D0ULL, 
            0x3A5DE058E2FA6A37ULL, 0xD87259EDDFAA54A7ULL, 0x9148186A417BCD6CULL, 0x911F2034B081742BULL, 
            0x6A930A75775F4C73ULL, 0x22C4B0DBE333C5B7ULL, 0x79273663ED68FD2BULL, 0x20584B9CB10AAA13ULL, 
            0xADD8A18FFE63FE26ULL, 0x0D377AF90383971CULL, 0x941BE51A43A15417ULL, 0x0EF74722AB2168ADULL, 
            0xA6EA15B4CF00421BULL, 0x0D87490622DDB74AULL, 0x7A71D1BD0C2D371DULL, 0xCDB7039E9510995AULL, 
            0xC56992979EC2BC22ULL, 0x3E92F052183AB3DCULL, 0xB19C35AB187E8543ULL, 0x27EEF9ECE8311F26ULL, 
            0x8D8EBF9D8F49F6E3ULL, 0x08E5DC476D689995ULL, 0xF20882419CBFFE82ULL, 0x026619401093158DULL
        }
    },
    {
        {
            0x0B879FC4FD4C82B8ULL, 0x7C0CAEA992D5F4D4ULL, 0x8731D6DF6CDE7D98ULL, 0x19777F64FB00A8DBULL, 
            0xD6FE6B6195C1B1E8ULL, 0x469E8E94E7F7AF2AULL, 0xA35456FBB9D8959AULL, 0x1C13AB268A1DAD06ULL, 
            0x273805764309EE2DULL, 0xEE422E26904ACA44ULL, 0xF08E68E5607A871CULL, 0x7DE35EF0C316E4A5ULL, 
            0xFA16FD9D8EB97DF3ULL, 0x739EB100F462075BULL, 0xA9FC232F64E6FD37ULL, 0xEDF27AEC5C2457CBULL, 
            0x85C3B70036C89C4DULL, 0x3C4074DF0306554DULL, 0xDB635E509ABE355EULL, 0xAA7E48789E878E6CULL, 
            0x8A06DD727A12D4A6ULL, 0x4CC91F7BAE56742FULL, 0x8AC2C977EB6B7700ULL, 0xD9756700A8072E83ULL, 
            0x08159C01E0AD544DULL, 0x78C8E10023660FCDULL, 0x931415C4667A2CC8ULL, 0xECA9E135E8F74A64ULL, 
            0x238839D112CF25E2ULL, 0xA63D0EBDA8066397ULL, 0x3E1E2BBCA852CE22ULL, 0xCCD3FA7DB34FBD59ULL
        },
        {
            0x751A28F6904E50F3ULL, 0x3E78962FAFC586D4ULL, 0x7F26D88E56277415ULL, 0x14E545C2D519AC50ULL, 
            0x5AF182F94984DD19ULL, 0xF3B6B27AD11550C3ULL, 0x0E6D5309A27F4888ULL, 0xA461F207A7F62263ULL, 
            0xA9DAD53C64B5F990ULL, 0x40179B2C11B35FDEULL, 0xC89271593E0009C9ULL, 0xC2D371627E813FFBULL, 
            0x345E9D55A6A92285ULL, 0x1D3AB1A7CB1C7FF8ULL, 0xE085B7C48CDC7461ULL, 0x6559520D6BD0C020ULL, 
            0x9E13D1472724EFE4ULL, 0xF949487C3046B946ULL, 0x39754B9130A9E27DULL, 0xEF61755E9DE06E6CULL, 
            0x391866BEF7A3023EULL, 0xB1EB0D63813E17FFULL, 0x9FAF8B3F882CFDCBULL, 0xD64A88B7001DCBD2ULL, 
            0x859CE60DE4AE8CC5ULL, 0xA0DF44D5C7A4F817ULL, 0x1FF1EFCEA4BFD6FEULL, 0xDC5B6A547A3D3758ULL, 
            0x99021F949D425A76ULL, 0xD2050EBE82AAD20BULL, 0x874A240E9B3C801BULL, 0x75AC24C4ED063CEBULL
        },
        {
            0xB905572833CD9422ULL, 0xCCF136F20DE5C866ULL, 0xEB1D8622DC02F1D5ULL, 0xC4E099AC975EE113ULL, 
            0x19CFEC16C3E5882EULL, 0xCC2828B9EE8DBB04ULL, 0x3F198DED8A4C353BULL, 0x004F442C805FB528ULL, 
            0xDE24CC6D25403D45ULL, 0x07D4BF876CDCA59AULL, 0x586782D328EAE12CULL, 0xF6577C6725A71097ULL, 
            0x5AB88723E6BA8575ULL, 0x95B8A46DF1509C80ULL, 0xBC5CEE03512483CCULL, 0xC3BA4C3CE56351FEULL, 
            0xDB87A3CCB1A6F1A3ULL, 0xAC5092C9930D20DAULL, 0x67FBB5A5303C2827ULL, 0x6D7BF6614B8F9DBDULL, 
            0x24B974A6457529D9ULL, 0xD03DD83DCFC31FEBULL, 0xC731EA5F29EEFF91ULL, 0x978C10F2D2CE41C5ULL, 
            0x118ABA720A4B5C79ULL, 0x595BBAA01264B956ULL, 0x941B5FC04ED5A5EAULL, 0x279CFA2B801E885AULL, 
            0x78A1E2A380B72C15ULL, 0xF66F4E67C21531F6ULL, 0x2949BD53884DF698ULL, 0xB8CBF23B47CA444EULL
        },
        {
            0x06D7E1F43EDA6A72ULL, 0x399EA3CF61919B1CULL, 0xA4E7A5AFF0F3F24CULL, 0xB7CF6EFA5D5AA14FULL, 
            0x8C5EFD2A32722DC0ULL, 0x54092812CD98A154ULL, 0xFD2F7262EC383521ULL, 0x5E7F600E41E195E1ULL, 
            0x56EB94FE867C7F52ULL, 0x42814CB3E26A570EULL, 0x161DC3237F030919ULL, 0x7CB573E2730AE12DULL, 
            0xC7C608E6131AB080ULL, 0x9D345B04C0E1ABD9ULL, 0x0D1C7CC857406194ULL, 0xE0BDE587AB5C2A06ULL, 
            0x33581AE7EAD43FBDULL, 0x581AF2A7ED88AC93ULL, 0x09F84DBA95DEDE53ULL, 0x46528C0E5FA13682ULL, 
            0xD7D5054074C00D79ULL, 0xF584F39C1B6D77C9ULL, 0x2113C1AF499E1714ULL, 0x60AB6DBC647B3931ULL, 
            0xF93FCEEFC435E109ULL, 0x805D6940FB94759DULL, 0x3040B6E6110FDDB7ULL, 0x25B4F261273E665AULL, 
            0xC15507842BB0A26AULL, 0x94F1DB17050D6891ULL, 0x131E95E2564E0986ULL, 0x4650EEC116FB7D95ULL
        },
        {
            0xBF23D97B658DFEAFULL, 0x0067FB3DEF0C8D65ULL, 0x74D85A0E7D8EC363ULL, 0xD39968749C2F04CEULL, 
            0x7ACBC0D57870D75FULL, 0x0520E0ABD3119A41ULL, 0xEE119365755717B7ULL, 0xB5557F206BFCD8FCULL, 
            0x10FBBF322647FF00ULL, 0xBED215A3228D488DULL, 0x2C85DBFF7F81F11FULL, 0x4A2974C019B45A24ULL, 
            0x3F393B7466C52F58ULL, 0xB474F4F518962ECAULL, 0xE1D742465F4C19E1ULL, 0x5B400143B879D379ULL, 
            0x4B1EA5EA1FD2A83FULL, 0xE24100ECE0958A28ULL, 0x06D53A57C049B134ULL, 0xBE6BB2F81007C03BULL, 
            0xFFBD1404FCBE2685ULL, 0x68D56FE8319B80DCULL, 0xCE5E7AD67A94159BULL, 0x829930067087E458ULL, 
            0x3C983C07A9B69C93ULL, 0xD0E0ECCB3BB3281AULL, 0xFD6161DA898BCA06ULL, 0xA2274B90FE7C043AULL, 
            0xFBC14B98D8E93303ULL, 0xA667BB755DC082FCULL, 0x48182B2BB8106932ULL, 0xCDBC0BA4F1B4A916ULL
        },
        {
            0x18FEFAEF9E4DEBB2ULL, 0x2BEDD622AA186034ULL, 0x7BC0BEA590840EF1ULL, 0x658A5C7EDEB672D3ULL, 
            0x884F268ED645E84CULL, 0x71F8513A474BDA03ULL, 0xA20446CEDBF3BE34ULL, 0x1BD5AF8C2E12BB67ULL, 
            0x1509E12F3837113CULL, 0xE1A487A5BA4CE9FEULL, 0xD9460B1C816609B5ULL, 0xE8F33E3CD7D3827FULL, 
            0x37B6249F93B676E6ULL, 0xC0E2346AF8C02BB2ULL, 0xF9165D02064AC593ULL, 0x59467E7F5DDAEBA8ULL, 
            0xBB99C66FF6765E4FULL, 0xF2F6D4F1CAD55D13ULL, 0xB514CF9A64ED3750ULL, 0x83F49CFF8F735A20ULL, 
            0x60FDF5C7CFF18581ULL, 0x4A844EEA9D98C83CULL, 0x89010DF7FC319052ULL, 0x11A182BD3D4C651CULL, 
            0xD6F6F3A21D89FDFAULL, 0x5D75CCF1B35A48ACULL, 0x8959A9E7EA4ADC95ULL, 0x76650AC91D57C51DULL, 
            0xE70F06DF99C598FAULL, 0x934F535F96318DC4ULL, 0xF4B54D00085E13B0ULL, 0xF19510B249489B30ULL
        }
    },
    {
        {
            0x205924B2904E7015ULL, 0xFDC0A84C5429A5AEULL, 0x1870FCDC5806E171ULL, 0x20CC32D389AF9B7AULL, 
            0x4D6C964D2F313AE5ULL, 0xCAB0D90270BD59CBULL, 0x2F9DC4F990C1C75AULL, 0x6D5BADF3D4D4FC5DULL, 
            0x10E2C0D2D04AA536ULL, 0xFAE9E3D8B78CE421ULL, 0x626F4E898F14315BULL, 0xBEB7A44308A14C9AULL, 
            0xD8C2FD0779702E3AULL, 0x973EC852E31DEC2EULL, 0xE3F2A009F799898AULL, 0x23FF674BA6692B09ULL, 
            0xFCB1B13CD1AB52E7ULL, 0xAC07D93978DFF507ULL, 0xEEA7FA3D5175D21FULL, 0xB45FBD48B2717E5CULL, 
            0x3B4951E49B84E5DEULL, 0xA8A12107C2C7A7B6ULL, 0x749FFFDEFD6359F8ULL, 0xB7C305C12DD0C61DULL, 
            0x5499ABD841C1EA9CULL, 0xAB07BBB4451BCE5BULL, 0x96E55541F9ECA878ULL, 0xA3C1F5DFA951D530ULL, 
            0xF0DA55D737A2FEACULL, 0x2EE8EDFA095075C6ULL, 0xBE692F5713940116ULL, 0x1642FA303945093BULL
        },
        {
            0x2C461827DD4203FCULL, 0x2BC8C7BACF8A09CDULL, 0xE55F6F9AA67AF476ULL, 0x71C654EEF4AED717ULL, 
            0x61D04D597397FE86ULL, 0x9DFD4EF43316765DULL, 0x26B5ADD3B5016E8CULL, 0x5FCCF080C76DECFEULL, 
            0x918FE895712DE564ULL, 0x6BEB4583839870EAULL, 0x51619241EE7FDF05ULL, 0x411CA149B81E9CF3ULL, 
            0xFCF410AEE3F6BCBAULL, 0x1D273D65837AF157ULL, 0x648529F71B1E8E72ULL, 0x8345BBB4DD9F0260ULL, 
            0x8328EC507FC98800ULL, 0x1CA39C871337E756ULL, 0xC54B86ACF7F569F1ULL, 0xDE9C419EDE744BCDULL, 
            0x7ECCBDBFBBFE5473ULL, 0x6CF39C1DAE6F3D0DULL, 0x75FED4F199C17C2DULL, 0x6E2855CC3E834F21ULL, 
            0x0E0CA0E95C55A930ULL, 0x2B81FA988C76064CULL, 0x96ECBC6AB4A91A2CULL, 0xA5CC61E5F66547EEULL, 
            0xE7B22CBCF442FAC4ULL, 0x0228EC82DC17393EULL, 0x3F02EE01B203674DULL, 0xF143359B6D8C2670ULL
        },
        {
            0x16B08A8DFFD8C1AFULL, 0x8CC869D644B709DBULL, 0x86877CB16CA6F3AFULL, 0x99F19753C53D0CEFULL, 
            0x944EAD0BD0B21749ULL, 0xE96EB85050C7F15EULL, 0xB15808061E0CC413ULL, 0x7AE4896AE634149BULL, 
            0xFC2FAC545EAF1348ULL, 0x6A3C3175779008ECULL, 0x7380642342C17A10ULL, 0x9EB0774ADF4D56D7ULL, 
            0x6BAF41B2C974A264ULL, 0xCD7B95B8BA78CC61ULL, 0x4069542B5E651F1CULL, 0x5FC4B92A03745DCFULL, 
            0x5A383D36FEE20274ULL, 0x2E5718917923D7A6ULL, 0x900CF0FEC542EAA6ULL, 0xB6BE1F173AF05BDBULL, 
            0x1D5AA8344DD650ABULL, 0x86D937E7EAC79049ULL, 0xDCA16988B5DAAEC8ULL, 0x951DE2CB7F71A7D8ULL, 
            0xC05BC9414EA5795BULL, 0x70CD46EE0C94F278ULL, 0x475EA4F616FAEEC4ULL, 0x9052F28D51B4B61AULL, 
            0x3BAD637BCFE4AD7DULL, 0xF729F85937789D07ULL, 0xDAB800097D7B0834ULL, 0x13BFB7BE46A9E851ULL
        },
        {
            0xB1381342DF70537DULL, 0x948A88E3E03C983CULL, 0xA76B3F6A98F2C2E9ULL, 0x7E3EC9FAEA1A971CULL, 
            0x8A5CA66DD5223171ULL, 0xCA64C305756BC89EULL, 0x22DA45A618210793ULL, 0xC98D455BB3206A27ULL, 
            0x9FF2F0AB138B2070ULL, 0x260539554EC221CFULL, 0xBECE530AA40DE19DULL, 0x8C48CA0C1B3A8D71ULL, 
            0xE081064630B189D3ULL, 0xE9117360E1470D21ULL, 0xE162E2B6BE3FA819ULL, 0x415C58A74894D542ULL, 
            0xD4C9468174AB0CF7ULL, 0xCBBCB8EE8204E864ULL, 0xDA5F56127CFCECCEULL, 0x5B995FCD3F28A1FAULL, 
            0x8514C873DD293D3DULL, 0x769984D399663794ULL, 0xB64A7D67919A7F04ULL, 0x49061B9AA299691EULL, 
            0xE2D177BBA0568F12ULL, 0xC5189F45A2AE1182ULL, 0xBA4688DBE5BF8ADEULL, 0x6D11535F939766ACULL, 
            0x765DFA6C907C9A50ULL, 0xDBFCEF42984541E5ULL, 0xA816F54EC0017D30ULL, 0xF3381A3B4B8042D6ULL
        },
        {
            0x3BB84B53AC2813EEULL, 0xADE37DFDDA09CA07ULL, 0xEEFDE10AA05A9DD3ULL, 0xCEC6C1878AA33DACULL, 
            0x7D411A4FA8321DCAULL, 0xE959B7BDEEB29C2CULL, 0x69226B57384860BFULL, 0xB8EF4267E6C3107CULL, 
            0x9AAA7C2462D8C9D5ULL, 0xA18E5F1377044B77ULL, 0x1B4FE0C03E7AEC3FULL, 0xE9B273DEC669DC6FULL, 
            0x20F0DD40031D9A5DULL, 0x287B4280BEB0094AULL, 0x712A984EAE622D76ULL, 0x53CEF50722B80690ULL, 
            0x4DFCACE55376B65EULL, 0xFDAFDDF6085916C9ULL, 0x1B80E7B1E26DC154ULL, 0x7413C0C7A1594E28ULL, 
            0x48FB8EE9A4EF93EEULL, 0xB057B974FB146689ULL, 0x9276CE23486D3F78ULL, 0x3ABF7D47416F7E93ULL, 
            0xEE94C713E808708CULL, 0x173244B6B89D8181ULL, 0x9B1806F6DB1BA0E3ULL, 0xB333AC87E5B18885ULL, 
            0x26FE66C5E3E52679ULL, 0xA24BB3554FAB1922ULL, 0x158A0DAD9C7536ABULL, 0xFD4A8433B8437152ULL
        },
        {
            0xD1D5A19CD822BACCULL, 0xD43EBADA38FCBC34ULL, 0x57CE12CBA6DE4751ULL, 0x708C2EFDB993A466ULL, 
            0x3C7CEE35B1E2E0FBULL, 0x72FC1107CDAB260CULL, 0x0A85B1167ACFF581ULL, 0xD7B65A908E585381ULL, 
            0x4EEFDBE59B1CE5C3ULL, 0xDABD18C82D10B496ULL, 0x226E1790665DBFAEULL, 0x23E981257C4223A2ULL, 
            0xD7CA73EE14483AB2ULL, 0xB20C1525C3B6235CULL, 0xD39FC8E1B573AEE1ULL, 0x6AA4101588719E4FULL, 
            0x45C9D03D0EC8C1E0ULL, 0xC93EC90EBAE8B11BULL, 0x09F2C1A88121563CULL, 0x649CC02D802925FFULL, 
            0xF7C97AC06A3550B3ULL, 0x33A0FA4592723E46ULL, 0x6489383719DB2B62ULL, 0xA5857B16A1B67D44ULL, 
            0x44C4CF49770CAD83ULL, 0xE87313EA4BB31ACCULL, 0xAF1DD9EB2C17CE51ULL, 0x38C31B7391B479D0ULL, 
            0x2FC930115D673008ULL, 0x550CAF1462051260ULL, 0x401298B4A893C463ULL, 0xC0923042CC1DA2B4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseBConstants = {
    0xC5C27490AB0805A1ULL,
    0xD760852E32DC9FE9ULL,
    0x1A9A99C5FFC51A74ULL,
    0xC5C27490AB0805A1ULL,
    0xD760852E32DC9FE9ULL,
    0x1A9A99C5FFC51A74ULL,
    0x3D8C3BAFAF5B2777ULL,
    0x12656E3D8C451F0CULL,
    0x74,
    0x7E,
    0x8B,
    0xB0,
    0x78,
    0x1B,
    0x9F,
    0x22
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseCSalts = {
    {
        {
            0x94B1CB1CF189647DULL, 0xCC0BB25284811477ULL, 0x8B4E557968C488A3ULL, 0x411705DECC053620ULL, 
            0x8B763AE8EE26428FULL, 0x2F133314133E4A5DULL, 0xE7FF8C46CFDAA24EULL, 0xB8385F609187697BULL, 
            0x164CE05567625BADULL, 0xD750ED9F8AD3F486ULL, 0x116F9F95CBFBEDD6ULL, 0xB0ECE473FA2AE067ULL, 
            0xB608A2490DAE7922ULL, 0x5F9D0D994CC52DCCULL, 0xA4D2A47CFE071BA4ULL, 0xE4C506F05890381CULL, 
            0x71DF621A4EB12E88ULL, 0x33E2AC4A3D8852A3ULL, 0x01D17826DF9F7D31ULL, 0x41E45DD1EC9581BFULL, 
            0xD8E127CBD8E2831DULL, 0x2199AFBFE8DEE7B3ULL, 0x30A09CFE919651D6ULL, 0x406DBC07A82B0CA1ULL, 
            0x95962065D5DFBD65ULL, 0x8860FB0AF13CBFA2ULL, 0xD1782432AF8991F4ULL, 0xF6112467BFA5E86EULL, 
            0x550258EBE1F1B046ULL, 0x5C4E4AA194ED10C8ULL, 0x76357963FCF262CAULL, 0xBBEEF40384A95C48ULL
        },
        {
            0x742333B0335BBD34ULL, 0x53A6D6E628617A7BULL, 0xACA0D6308199AD42ULL, 0xDA9DA1C0FEE9A3ADULL, 
            0xF7612CC28AB93BC9ULL, 0x8BE4C084E92EB140ULL, 0x2EFEF8A625B86204ULL, 0x6D379F1101BD9535ULL, 
            0x723382C54ED13832ULL, 0x97DEC8DA2337A349ULL, 0xA28220827330D6D0ULL, 0xE420008D881B0234ULL, 
            0xA27EAEF9E6315E74ULL, 0xC29B086225F27265ULL, 0xF73B1E1F020C2CFCULL, 0xBE83F08AF25BEE1AULL, 
            0xEA76A9868623DC70ULL, 0x60123FD02B816CD6ULL, 0x8F4CBD5B15E47C68ULL, 0x2786DEE5583A5E14ULL, 
            0x9F6F70EF3BBEFEE0ULL, 0xB2747BB220AE1D55ULL, 0xE33D65AC860BF341ULL, 0xAA81EC353D1EED60ULL, 
            0x293D8A264049D83FULL, 0x264C8B29DB59A72DULL, 0x9881CD894E04EB5EULL, 0xD0E1FFB8164508A4ULL, 
            0xD2615AF72868FE9DULL, 0xDA512B26C820F280ULL, 0x864915677DFC02D5ULL, 0x813BB6429A748C63ULL
        },
        {
            0xDD26972E6BF2549EULL, 0x802F925CFA2C52E6ULL, 0xFFC630FC00E123B9ULL, 0x493577998D34430FULL, 
            0xA38FE032FAF3042EULL, 0xCD7FDC2945EDAEEFULL, 0xA318BBB99DE8FBE2ULL, 0x2EEF61DFB813C868ULL, 
            0x5E7B6B59707172DEULL, 0xEC4C13665037289DULL, 0xB3A254B7931C631BULL, 0x31E252C407CDBF15ULL, 
            0x9A61CC17C05EC3EFULL, 0x4F028EB9BF1C1238ULL, 0x6B97025CAFD80A5DULL, 0xDDC9B5611012D8F6ULL, 
            0x3F0E468E921289A6ULL, 0x016E734DE6158A77ULL, 0x715284DA1B875963ULL, 0x23D5E8AEF73C76D9ULL, 
            0x0DDF132170B7F331ULL, 0xFD9FAEFB5E7575EAULL, 0x888923DC48202BE8ULL, 0x2B150789612D24E0ULL, 
            0x1600367664445B56ULL, 0x6022AD2CD6763D03ULL, 0x4DC99A98A033C0E0ULL, 0x2858D313C8BF2814ULL, 
            0xA4F2F06574E84DC9ULL, 0x0D5B9E317B3D0091ULL, 0x422FD89A23263D20ULL, 0xC29B77E96FE6F9B7ULL
        },
        {
            0x4BA9C83E929628CFULL, 0x5CB8CAD237DB63CBULL, 0x421C59C4C2A95225ULL, 0xE1DA92D9901CF04EULL, 
            0x2F12A3A3FBBF0B04ULL, 0xB040F749F1EA36D1ULL, 0x4D8A2ABEE7B2E60CULL, 0x666E40BF290DF27BULL, 
            0x5637BF98E7C7DC2BULL, 0x100D379D0B7ECF92ULL, 0x3A547F9F025D486FULL, 0x7ED757ED815FBA40ULL, 
            0x994A195812E505B4ULL, 0x652527089576A2F2ULL, 0x6EF271AF3DB6976EULL, 0xFDDA5BF46823DF97ULL, 
            0x1261D9B52824F422ULL, 0x4D7B809C9BC4984FULL, 0x12454759BFD4929EULL, 0xD46EAAD770338337ULL, 
            0x1B70F88820497ED2ULL, 0xE8EFA91F7D4768BEULL, 0xA5F91289EA4E2BC5ULL, 0x3F4F0D64E9C891E7ULL, 
            0x1F56658BB3E51C4AULL, 0x86E75061A08FF58DULL, 0x4D0C2A8CCEFC285AULL, 0xC3A0E1CA499F62EBULL, 
            0x7A22DAA941A1A86AULL, 0x1DE1E5C0B69F0476ULL, 0x7B777DFA7D55538EULL, 0x61D2230C7BA5C958ULL
        },
        {
            0x1C52531977B28557ULL, 0x17E2BB18F56D208AULL, 0xB2FC24B480AEA819ULL, 0xA9F189F6FA50683CULL, 
            0x4426C07BED8E1C69ULL, 0xB5C1F2D37D27EC74ULL, 0x5FFE6109D16B6A1EULL, 0x4FA43DE8BF42DB3AULL, 
            0xC72B33CFBC3B015FULL, 0x9C8DECACB26ADD8BULL, 0xABEFA15CAB8452F1ULL, 0x3E8CCF834D8B08ADULL, 
            0x1AD8B2BD9EFAAC2DULL, 0xFB250CF97FD5F2BBULL, 0xEB337A99ED874795ULL, 0x36AA6ABE71D322B3ULL, 
            0x02DEE201045B6821ULL, 0x819CDE358FD7390DULL, 0x7E0D6BAA583E675AULL, 0xA64C1B94648BA374ULL, 
            0xEC18FC2609C61574ULL, 0xB5FC07C6F6D174DDULL, 0x76F59001EA169702ULL, 0xDC91E851741AA010ULL, 
            0x7FC3972C689FB388ULL, 0xD85B6FB93F980F68ULL, 0x3E14AB2ACAB3B081ULL, 0x0EAD815AA7AB73A9ULL, 
            0x7E1072A2031FF1ABULL, 0x58756E3188B8195AULL, 0xA23A72C2BDC39282ULL, 0x12075D567C717A9CULL
        },
        {
            0x472AEBE6DDDA4421ULL, 0x70EB6F0BC2911588ULL, 0x654DABDA5384D78AULL, 0x5C8A576FB5B5006CULL, 
            0x7C27A5F9FF69DDB9ULL, 0xDA23E18E5D766E91ULL, 0xD1986A3EE5F43156ULL, 0xF41F8A478A728A90ULL, 
            0xDB1253A70608F8D2ULL, 0x27ACCA5F42F83381ULL, 0x93E4B1A3BB690A03ULL, 0xA6A6F982E66624BEULL, 
            0x0494E3365264092EULL, 0x76B279E628E236AAULL, 0x60890E17934875C9ULL, 0x3DCE4F7D49C5CD63ULL, 
            0xE568968297719A74ULL, 0x0EBF5815478FE0DFULL, 0x19B99C6E5E1A9E08ULL, 0xB829DE3BDE3E35AEULL, 
            0x781DE7234DBD1D33ULL, 0xD950E60230BB73F3ULL, 0x22D5D3A960658500ULL, 0x2DA82F5D6679C66CULL, 
            0xDE2E8AC710FAA596ULL, 0xEA3EAB737B8E6E65ULL, 0x8A178D54212FB3E8ULL, 0xE7C53382D0217555ULL, 
            0x71849A82A121F45AULL, 0x1178656B53204E2EULL, 0x89A12B5F2A5AF601ULL, 0x0FB935DC05DD3242ULL
        }
    },
    {
        {
            0xB690D7981E574E42ULL, 0x25A5B2BACEA5D9CDULL, 0x07F85FB5A28C34FCULL, 0x53FF37D91068FEE3ULL, 
            0x3D21728FC4C7B49AULL, 0xDA8C0236E186701BULL, 0xB3221211ED6EBD32ULL, 0x2BE9AC345670F3F0ULL, 
            0x97F4D1BEE034D0FBULL, 0x4EC93822EDB71AD1ULL, 0x2B3FC61F984E0D61ULL, 0xC4C6F8D917984932ULL, 
            0xCE7B90D0E42D0D0DULL, 0xF07E36EC81EA1615ULL, 0x417B79E831B4AED9ULL, 0x68A9DA58052C93BEULL, 
            0x0FA5D6C344078317ULL, 0x4CCED370557CB60EULL, 0xEFEDB48949657BF9ULL, 0xDD5BBAE7155178D2ULL, 
            0x449AA5CD512F459EULL, 0x2928580589ACB7FFULL, 0x6B47B927DEA98630ULL, 0x2A3096EA87F977C3ULL, 
            0xAF2E44088B45B694ULL, 0x25E2249E519A4708ULL, 0x90BD0D6F06975C36ULL, 0x19E42085980B7B31ULL, 
            0x5778D3CF1BA9EB30ULL, 0x6E750BC37EA698ECULL, 0xEE94488632F92C9CULL, 0xD652939A9E7538D9ULL
        },
        {
            0xB099E14C56A5A42BULL, 0x26E10FE3AB8F2C27ULL, 0x330A49224248FEA1ULL, 0x709270A91B7897C5ULL, 
            0xC266A0591A97CB18ULL, 0x0A89010791045DF4ULL, 0xD6E4FB55CD0AA2DAULL, 0x91996CEFB6FA3C7CULL, 
            0x73BAA87B81187BF9ULL, 0x2EDFEA462AE41BECULL, 0x97CA29AC7B461D48ULL, 0x4200C4299ECDC263ULL, 
            0x9C8CBE77EBC004EAULL, 0x88438EA191ABFEE3ULL, 0x2D9DDC3383BAB836ULL, 0x7D363B113FDE6043ULL, 
            0xEFE5BD51A32B8C1BULL, 0x5D1DD66E8C6FD415ULL, 0x88B4C4A7866B90D9ULL, 0x4534B3D91B51CDB2ULL, 
            0x86570F8E392F52AEULL, 0xD784899C35C64037ULL, 0xA577BB1AAA6D0BAAULL, 0xA198AB61E8BEA649ULL, 
            0xADF367E3FDA6679CULL, 0x40459D0891FDCD07ULL, 0x161DDFE7B144361CULL, 0x943FC04ED7D30AC2ULL, 
            0x4F0CAF956DDFD084ULL, 0xEEA8F148413D7183ULL, 0x7AC621E800E9F8C6ULL, 0x485125D12E3F6A6AULL
        },
        {
            0x2707A317F0A9E41DULL, 0x0D2651F98786B116ULL, 0x45C066E99C59A48CULL, 0x6C3C0A79A668EA7EULL, 
            0x15C468A09926DB00ULL, 0x930ECC03D04556C8ULL, 0xFD50EC0C7BCEED2CULL, 0x46E870743327512FULL, 
            0xEFA181335E676F9EULL, 0xC0FE803720E52518ULL, 0x3FD8A55E9CC327AEULL, 0x432548D287DB8AD2ULL, 
            0xC3FF3FDD01522340ULL, 0x0A26D13591060860ULL, 0x8D3CDFBD1BBB64CCULL, 0xEFA999D8FEA3DB97ULL, 
            0x878E86362B356482ULL, 0x2302C7BA40FA83C8ULL, 0xAA2DD230F519346CULL, 0xB03EED96B749D927ULL, 
            0xC8D30D470F1EAB11ULL, 0xBCCD1EC97B503A5CULL, 0x39E29CCFB67A3543ULL, 0xEDB916CE59FB0DC9ULL, 
            0x4C39351B5D79D1DBULL, 0x167678925E35522CULL, 0xFBEACE4E1E52BC41ULL, 0x592CBFDB80D2A380ULL, 
            0x303ABD7D154F0F2FULL, 0x41D807EE5E92A52FULL, 0x571D1CF548F36A05ULL, 0xD0BB2190B94143B6ULL
        },
        {
            0x75A496BD5634A2C8ULL, 0x5F6B19E92A78DC29ULL, 0x5EE02D18EF4D2A93ULL, 0x55567E68F4B21FD8ULL, 
            0x1529AF4F3DDBB43BULL, 0x487668914D87C305ULL, 0x79028C4FD96A9366ULL, 0xAC06AFBAFA7A2A8FULL, 
            0xD1A37B8AC337A203ULL, 0x96EA0A64C7F53EECULL, 0x91B1C0FB353E42ACULL, 0xBE5CBFE8FDDF4CBCULL, 
            0x3E6FCB492A0AEBA4ULL, 0x5A147DD0EBF8FD72ULL, 0x01A510A1E4428CCCULL, 0xFB3155BFF8260D20ULL, 
            0x8B1EF686B846E456ULL, 0x6E8A8EB0C36A150FULL, 0xF9F15B527CC9CCA7ULL, 0x6E465F9398EDA818ULL, 
            0x9B27DAF21CAC96A2ULL, 0x23647F0F3C57CF44ULL, 0x828895860F3EFD14ULL, 0x1FD4D42525EE6191ULL, 
            0xE83ECC6C23C52115ULL, 0x1490E534F1443B58ULL, 0xC1C4B9DF7A5D7861ULL, 0xDD5C634E194E1ABEULL, 
            0xA3D6634048408C12ULL, 0x6B0A7A9F937F8965ULL, 0x6418FC4581C18EBCULL, 0xF80807A4D00FA6C3ULL
        },
        {
            0xD6F6E1A05CA51B7AULL, 0x8B9278ED7A4B5C48ULL, 0xEFB4864E07EF93B2ULL, 0x8D640E4AE515173AULL, 
            0xC985A8949BC5012EULL, 0x820DA90F8CC5A4DEULL, 0xB63C1C58F6D2C790ULL, 0xDF9FEDD69C96E03EULL, 
            0xB50A25183D70F66CULL, 0x128ACBC53826B460ULL, 0x6C0E8E4B5451E3B7ULL, 0xD7B2CC6B976B69B3ULL, 
            0x01B2EFEC1C5E9A5CULL, 0x47CCD767B7648F91ULL, 0x124451B733A8D513ULL, 0x2D56DA286DD7A3C9ULL, 
            0x7B0C538505BE88A3ULL, 0x506A64FD9458A681ULL, 0xFF53865CFFA4D238ULL, 0x6BC12FC6BFF47726ULL, 
            0x7B3EEBF6EFBC7F41ULL, 0x8CF85DA1317BC94EULL, 0x6F2AED348F31FB7BULL, 0x6F4AFDBB90A8F979ULL, 
            0x62233A2DD4EB9D00ULL, 0x6EBFEC66F41561D3ULL, 0x71CA726A50993D87ULL, 0x61C43F76E0102D17ULL, 
            0x79B20D1457F2FBE7ULL, 0x3C9472591C1C22BDULL, 0xAB043BACB7594DF0ULL, 0x5AF12C4C2A960D1CULL
        },
        {
            0x02BC7F03B1D4BF95ULL, 0x0C546F5346C4A4B7ULL, 0x255100BA1076E935ULL, 0xD59908212D3CB217ULL, 
            0x19746149DDD751A6ULL, 0xF729D7A0F923D73FULL, 0x61FC695A0556A135ULL, 0xEE4F61349EF0F335ULL, 
            0x0470C569A4AF9892ULL, 0x5FD05A5492B4646AULL, 0xEDFF3307797B2394ULL, 0xC2F9C5C8C15682C0ULL, 
            0x44E776BD59E6317CULL, 0x3C2E332F173C59ECULL, 0x37E7EF6D08E8BB8CULL, 0x81817F756BA4FE04ULL, 
            0x1BB556C7943BF63AULL, 0x5D2C5E2A7EDC6497ULL, 0x3DBA26A6BE08F9CAULL, 0x9C1B97216447B0ACULL, 
            0xC1A7A6697F2471A3ULL, 0xAD37E639799244ECULL, 0xEAC66EA5723EC621ULL, 0xD70B40C87BDAB09FULL, 
            0x69F35830D34DCA0CULL, 0xC125205D37EBE8ECULL, 0xA8644CB10B089184ULL, 0x50FA0186169B4BFEULL, 
            0x9D30F3BB3CDF6D2DULL, 0x0BABFF27961B6283ULL, 0x5FA089E6299DB1F1ULL, 0x0822813D28A6F0FDULL
        }
    },
    {
        {
            0x8B9D452E5C25651EULL, 0x356F5F42BBD4A9D3ULL, 0x7AB530D95F4C610AULL, 0xD1B077F6E21DF4FAULL, 
            0xEC456164D47C5076ULL, 0x97FD82AAB803EDC0ULL, 0x1F99E4529C53E912ULL, 0x4F197BAA2C2EE05EULL, 
            0xD78F3B0972796006ULL, 0x6108A1D8D8FA58E5ULL, 0xD180125F3323A495ULL, 0xD21EE73D29728B11ULL, 
            0x03F13A9F46623F88ULL, 0xF96A3671EDDBF6E8ULL, 0x6A542A76477BED03ULL, 0x1075C1CD89258B26ULL, 
            0xBA4AB8313D41CF21ULL, 0x7C61E9603E19A75BULL, 0xACE74A816934E586ULL, 0xA7726B94BD33051EULL, 
            0x68A4B59E9FCFE3B8ULL, 0xDFA8A3727133248CULL, 0x8A727C8317AAFF6CULL, 0x72628B914DBAC7C0ULL, 
            0x779E2549199DB8E3ULL, 0x09504CDD1EBF00BBULL, 0x22E09C0BFD11B992ULL, 0x92EFE81E9CD70C27ULL, 
            0x4FDA167A814458C6ULL, 0xB3545ED17E32EA07ULL, 0x3FA9D0F526F5C349ULL, 0x0401DC938B826FBFULL
        },
        {
            0xB5C35FC7739206AAULL, 0x3E4B8497E86967DFULL, 0x7658F51E86006D14ULL, 0x705A2DF12CC37B6AULL, 
            0xAF3FA4368B446B41ULL, 0xFAC641492226A978ULL, 0xF0571C15C4FD47D1ULL, 0x6861C37334BC552EULL, 
            0xACEA1F35A39F2000ULL, 0x982F44E67E77357DULL, 0x86FA950D8E90AFB4ULL, 0xC6C908EA6C011180ULL, 
            0x1C566756E8700A04ULL, 0x3238BF6A20A30923ULL, 0x11D4DB94918B2093ULL, 0x3FDBF85AB3D3A282ULL, 
            0x0F6CC937C549BEAAULL, 0x06D9DF33B28E09B6ULL, 0x0D33D97333AED78EULL, 0x0F145E2DD0427E2FULL, 
            0x93B8C2372FE344CEULL, 0x460C58805D250B77ULL, 0x00220671B36D8627ULL, 0xCFD87E7DC31A01A1ULL, 
            0x6789806C8B16AC3CULL, 0x45CB1C17E113412EULL, 0x991E8449A330EE2DULL, 0x60E23039C56CB272ULL, 
            0xF46DC93435E63269ULL, 0x6FA0DE722CE432C0ULL, 0x7DAC95593BA1C220ULL, 0x6CA0DA08155C2095ULL
        },
        {
            0xB2B4046C3C011214ULL, 0xC59EE3F9A84E08F4ULL, 0x90FC3E9119FC5150ULL, 0x893F3B5F1C4FFBB8ULL, 
            0x8112FC6E89767125ULL, 0x634BA6C5C30A68E0ULL, 0x73C99DAA87CF5D92ULL, 0xA43D0FCB52957157ULL, 
            0xB48F73047309FEB1ULL, 0x4ADC7608A3715097ULL, 0x8442CE746EABAF35ULL, 0xE52C0630F0E55534ULL, 
            0x28192C22C39A4354ULL, 0x4101AB79675966A5ULL, 0x90AC54B6EB45B857ULL, 0x12127B7A544CD6DDULL, 
            0x52220FD31B969EAAULL, 0xBC4C2386A716AFCDULL, 0xF9DD4E3B733A626DULL, 0x5E4CA738AF066C88ULL, 
            0x024BB729CBEDA472ULL, 0xEBDA764EF10599E1ULL, 0x3348389E3A3F5DDEULL, 0xC0796AE863249F03ULL, 
            0xF90C5D656B7AA396ULL, 0x31753DABC16043B7ULL, 0x17101842CD2290CAULL, 0x3EDCEAFDDA58ABB1ULL, 
            0xC89DA9C851F2C08BULL, 0xB637376276EA2AFCULL, 0xFE848BBF4F8F8C4FULL, 0xEC6C7B5FBAA967AAULL
        },
        {
            0x0FDE3DE075EEB1D6ULL, 0xBB80F4207CC796F1ULL, 0x3CE188216032CB17ULL, 0xA12A7C37C8F22B63ULL, 
            0xA182BD5CFB98355FULL, 0x5B6A89C8558A14ADULL, 0xAADB251158C9D286ULL, 0xBBEBA8C64C61A0CFULL, 
            0x39C005AE10685AA5ULL, 0x70758B28D5398530ULL, 0xD4C5392D36FD8302ULL, 0xFE5D6B9204419DB3ULL, 
            0x0EC44CF7D3F1FB62ULL, 0x416CCFF7271042F0ULL, 0x81DDA993B2D1FAD9ULL, 0xB56FAC6D9CE6DE0EULL, 
            0x48B778F13B304BBCULL, 0x8E7CF90EA56E5FF1ULL, 0xB73BC3C526359B9CULL, 0x7FD31D33570936E5ULL, 
            0xD0AF8D9B33FBF36BULL, 0xC2F524D8AF948620ULL, 0x2BAC9D9DCFC621DCULL, 0xA8D40457C7796509ULL, 
            0x9CECFCF63B0ED8CBULL, 0x240C9637C14C68A6ULL, 0x3AA4176F5FE71FA3ULL, 0x501FC39C75D97C48ULL, 
            0x821AC2F70E574742ULL, 0x96B3EF45CEBB6BD5ULL, 0xFA6917F473247783ULL, 0x761AB30DAB01A69AULL
        },
        {
            0xA9200C04CA35A76AULL, 0xC03693323F4CB764ULL, 0xFB7B1392AD0C8FB3ULL, 0x00E3EF52683F7773ULL, 
            0xDB183A3852B95256ULL, 0xA85548BAFFA45B57ULL, 0xA64D1112DDAD2432ULL, 0x9DCFF6323255D03BULL, 
            0x9DD5686A85FD5720ULL, 0xA91BF446BF233B6BULL, 0x5234E189D5A620E2ULL, 0x4A7A19330139D4FFULL, 
            0xF69A21ACFA37CAA9ULL, 0x60B3E7D50B4BE6DDULL, 0x84BB59FEAAE4FFF8ULL, 0x3F26E6C1E17DCB29ULL, 
            0x231F40B1E38DE4BBULL, 0x210C8A2DDF1D948CULL, 0x276B747659042E9EULL, 0x97A1047B3CFF98B2ULL, 
            0xEA1B65AB252D42C5ULL, 0x513C4167B349657CULL, 0xE297A747D811649DULL, 0x23D757BBE6B4C620ULL, 
            0xF2EDDCA921C73FA4ULL, 0xB77344DCC2C11354ULL, 0x92AE092BF9D0533FULL, 0x7CCA7F35E10334BFULL, 
            0xBAB3AD4D215EEF3AULL, 0x6170659C923258B2ULL, 0xB31B37679AF9C117ULL, 0xCFAECDB5DD20F218ULL
        },
        {
            0xB3747AFC431634DEULL, 0x8CE1069E9C2EABF6ULL, 0xBB08C4D79F35041DULL, 0xCF37AF850229B83AULL, 
            0x01E42EB7527E3407ULL, 0x172F1520C1884A81ULL, 0xB90DED3A02747CECULL, 0xADAAA745F4D3238FULL, 
            0xA324989C90570E46ULL, 0x1D93A45CE1548DD8ULL, 0xCB7DBB0F591005F9ULL, 0xCA69CECFA66D9FBCULL, 
            0x1ADD6134DB5403FFULL, 0x67AADD531E9527CCULL, 0xCE6448B4E27219BBULL, 0xC52DE0AC3D9F9186ULL, 
            0xBAA0F4647CB3D788ULL, 0x5A2E0254ADEC7D45ULL, 0x922DAAE26AF504ABULL, 0x6491A29E4E1BF94EULL, 
            0x98E6CAFE3CEC5329ULL, 0xFE4AB270988B65E9ULL, 0x5292CA6DBAD56DBCULL, 0xD8F68A8877E1FF11ULL, 
            0xAD50F421D30954C4ULL, 0x8B3FEBE3346021B2ULL, 0x34CB6E949BCA1C4AULL, 0x644A5A2984DFFC90ULL, 
            0x4B29CF95F399ACF8ULL, 0x46954F6F6B7EE60EULL, 0xE108A522585ADB11ULL, 0x0568EA7338F362EFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseCConstants = {
    0x7BC106595172D21FULL,
    0x5316DC36FD62208AULL,
    0xBF878217BDD5C572ULL,
    0x7BC106595172D21FULL,
    0x5316DC36FD62208AULL,
    0xBF878217BDD5C572ULL,
    0x176E1EA6DB4D9D6EULL,
    0x7CEDB2B4957571CDULL,
    0x30,
    0xE9,
    0x07,
    0x5A,
    0xAF,
    0x80,
    0x6D,
    0x0E
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseDSalts = {
    {
        {
            0x759955498499E45FULL, 0x8D5CEC859F976847ULL, 0x40015FF67D62D2E1ULL, 0x33B5DCBD91A74BE6ULL, 
            0x29F2E04207307DB7ULL, 0x822D6CAAD363D563ULL, 0x747D50ED2CD2C0DBULL, 0xD87B6D3333886F0DULL, 
            0x26FB9EBF196D1745ULL, 0xB61B636EF549DC0BULL, 0x2EC9D72EC5D8FBE1ULL, 0x7CA21ECEE128BA07ULL, 
            0xA52B10D55EA6F964ULL, 0x1B35033E5EB1208CULL, 0xB71E23D602E539F8ULL, 0xA38450BC3774BC57ULL, 
            0x04578AD09E9AA6FDULL, 0xF902AF9A13C586CCULL, 0xEB8E4E02ABC7AEECULL, 0xB74183160A005B39ULL, 
            0x1092CA2D7A51BC64ULL, 0xE90B352E2C778DD4ULL, 0x49BA04DA47F105AAULL, 0x98F84374CE31DA18ULL, 
            0x7317156565C6D8F5ULL, 0x6985C7752DA07A2DULL, 0x796E0CB7C6E549D0ULL, 0x12469572ECA762FAULL, 
            0xF227C5BEF9F7F1CFULL, 0x628797307194B566ULL, 0xC179CDADF33F7436ULL, 0x118262D4CDA5D107ULL
        },
        {
            0x92F46D69E1269C14ULL, 0x03A1167D0C016A38ULL, 0x699A931CA7E59607ULL, 0xC423A527C955DBF0ULL, 
            0x71E93678CDB5DC49ULL, 0x75A7FB0F917D3456ULL, 0x3B566C926A419AB8ULL, 0xA6B467C15B340A4EULL, 
            0x204A048A0BE46678ULL, 0x7180BA9FFF0920F2ULL, 0x92BBA32E6D10D071ULL, 0xCFE04A5BEFC221CDULL, 
            0x62D47F80285C7756ULL, 0xCE497487FB312025ULL, 0x9B81CB89E56011EDULL, 0xA4E837865F7A1CF1ULL, 
            0xF170AF76E3526D55ULL, 0x9CCACA7BDF5DDB75ULL, 0x93340C62B688874FULL, 0x926CADB4B3583826ULL, 
            0xEBAD252E663B5645ULL, 0xDCD7C01E8B3D3C94ULL, 0x0FB37E2D514DD9C5ULL, 0x7832A275E5952EA7ULL, 
            0x39F9F57494E4B6F3ULL, 0xFDBE9C83DD9C4049ULL, 0x245B99EDFDB81F6DULL, 0x1B00C41C4119C778ULL, 
            0x830D089EB76C4A23ULL, 0xAE01F5542D1FCB31ULL, 0xB48CE038C94F5E71ULL, 0x7D46B887E0E5D8C1ULL
        },
        {
            0xBCE6E76736ED3325ULL, 0x017E38DD7028AFAFULL, 0xA5E751322DDE5CB2ULL, 0x3DB9477A037769F3ULL, 
            0xD44177FE0108E111ULL, 0x5BF40935C15671FAULL, 0xEEC34AC9DDBF994DULL, 0x5DF2551D801FACF4ULL, 
            0x244454B7EF268E4FULL, 0x74F09CD384B75981ULL, 0x07B465A739AF24DAULL, 0x6735F87807662592ULL, 
            0x1FAEE3828E012B25ULL, 0xA6C3F559E23161BCULL, 0x89C0B4BAD44E778BULL, 0x41AFFA6445664EDDULL, 
            0x19EE11D090614BF5ULL, 0xC8B506EE260F96C8ULL, 0xA14CDF891E8626DAULL, 0x23B102653804858AULL, 
            0xB023841B75CC037EULL, 0xCA49E75804DD9D14ULL, 0x1F99B7029D8B90F0ULL, 0x909A4E2C2E3A4F43ULL, 
            0x7D97B92C12B8FE95ULL, 0xB633BF652A8CBF89ULL, 0x7F1266C1F7006282ULL, 0x8BCD4AD5584050A4ULL, 
            0xA3F2395C8403FC52ULL, 0x643C51FA7890270AULL, 0xD91B218FDA329075ULL, 0x416C80EB71B9B0CAULL
        },
        {
            0xFC5523344BF2414EULL, 0x8543C7F2990D5ED5ULL, 0x036E934C3B5FB588ULL, 0x61B61D3AC3D63828ULL, 
            0xA42570BD5CB5F73EULL, 0x9050BED76DB75F45ULL, 0x3047F9B4F58C7BB1ULL, 0x58B8B04E4583337EULL, 
            0x117792557563597BULL, 0x57EF874927194141ULL, 0x464C23E9FB375C10ULL, 0xD415513F0AA4BC22ULL, 
            0xE78FFCB70188B6EEULL, 0x17F4676CEB0268A1ULL, 0x745351BF652FA7FDULL, 0x3BCBC9C694794AEBULL, 
            0x09FA3A9487BD58C1ULL, 0x8C85FB16BDDA6573ULL, 0xFA1650265C1813D7ULL, 0x7BAA998A0DCFAB0DULL, 
            0x40CA481601E7B103ULL, 0xBB6AC8798C508C07ULL, 0xCAF575DB192D1A3FULL, 0x014C9957CB88C6E2ULL, 
            0xA5F6607B79B56498ULL, 0x984E7A7272754A72ULL, 0x8720E5490F86D096ULL, 0xE6771E08A4C3A579ULL, 
            0x2B0BA3A6DBE69512ULL, 0xCB091A882FBE5D33ULL, 0x494C5EEC03ACD432ULL, 0x5DABD316962EF958ULL
        },
        {
            0x9C651A00C3AB57E8ULL, 0x06D6361ADFD45269ULL, 0xBBF002836CEE049CULL, 0x8EFD6F2BD2C68695ULL, 
            0xC1EEC3EA70168355ULL, 0xAA3DF730A5FCDBFBULL, 0x5E3B3A2504C59F16ULL, 0xB1E84BED49C161B1ULL, 
            0x91B15F42050A8B1CULL, 0xD178BBDED6728D21ULL, 0xCDB5FB5A2C449026ULL, 0x1B6E5D82E7C41DB4ULL, 
            0xD39DCF744B557134ULL, 0x7134EC594D52B866ULL, 0x5753898E056B52CFULL, 0x18D2671A08180C15ULL, 
            0x285216EEECAC00E1ULL, 0xC70A82CC0CE74B31ULL, 0x774913E837C53C29ULL, 0x0CF9E71370D7D55CULL, 
            0x9EA2BEC1D5869A90ULL, 0xBFBF826AC083B44FULL, 0xCC39F4C422B932E7ULL, 0x319F0FF4FA3D4072ULL, 
            0x9277A325855ACD6FULL, 0x12D51B7028F698DCULL, 0x1AF16D5E6B7B590AULL, 0x70539117921A69F6ULL, 
            0xF921DE7A4491E6F8ULL, 0xB42AEA3ABA1E09CDULL, 0x22F48968502F7062ULL, 0x0F164ACCA3C3DABDULL
        },
        {
            0x04C3C5DEEDD0BAA6ULL, 0x6E61542E698211A0ULL, 0x7E069AE274CEA8BFULL, 0x741611A0C33A0604ULL, 
            0xB0D742E7B913871EULL, 0xAA01DABF76C10FACULL, 0x9EA03D2954D1CD0EULL, 0xEFFA3A084F58450EULL, 
            0x6B1691F5F07616ABULL, 0xC79FDB5ADF2493B6ULL, 0x4D7E1A4C30810046ULL, 0x4B966F0A2CC723F1ULL, 
            0x204DDED263CE946CULL, 0x1520842CA3137BE4ULL, 0x6AEA080A465E682DULL, 0xF0DCE832ACF6ED5DULL, 
            0xC29ADE73F7907001ULL, 0x34485A850B083373ULL, 0xF215C9FDA8680771ULL, 0x929547D754B9F220ULL, 
            0xB2E15FA8F25B6223ULL, 0x44C3475BB4303559ULL, 0x0B4B6B59C6ED2F1BULL, 0xF9F28D3CCF1D386BULL, 
            0x419F843A75F46F4FULL, 0x3C31142B9F39C7C7ULL, 0xAF4C9DA907A85124ULL, 0xFC0932086FFFA346ULL, 
            0x0134BE4C83FABE1AULL, 0x4D0C79165A792990ULL, 0x640D1AA237FCD5CDULL, 0x0C2C570C8B33151EULL
        }
    },
    {
        {
            0x7B1F8D81A3394CEAULL, 0x08B8B8BC57D8A86AULL, 0x48C0314EA005BFD6ULL, 0x2E4A6B56B5B0D38CULL, 
            0x431506C9FFDBBC49ULL, 0xDF4D11EE93899832ULL, 0x4FC50F74558CABDCULL, 0x9AF475B3D4E5552BULL, 
            0xB2DC01BD4D1E96FBULL, 0x116EA40875F46A83ULL, 0x289BE87EEDFF0353ULL, 0x3179B926748E895FULL, 
            0x5F05C0A5E5C5811EULL, 0x0BBD28BFF3B6CF29ULL, 0x72C53A4ADB9A4E90ULL, 0x08C8A4B38EA67D45ULL, 
            0xC79C44DBCE868E7CULL, 0xCB528FAB75D10CDDULL, 0xC7DB5E038629DC11ULL, 0xDF0F5F925F836294ULL, 
            0x1C11E8821F5738D9ULL, 0x5384CAAC754D745FULL, 0x4C410B4293537BB5ULL, 0xA421304CB7A2F9ACULL, 
            0xF130C717970B0DFBULL, 0x214E69B5B0570FE4ULL, 0x480157313C5589F9ULL, 0x226795E0265EF5DEULL, 
            0xD4FF1BBDF8EA70F4ULL, 0x3045886668CBE0ACULL, 0xD9211D47918EEE65ULL, 0xF419397F1F310249ULL
        },
        {
            0xA40F5194E34692A9ULL, 0x9DFC43EFC4B57179ULL, 0x696390485D7B478BULL, 0x986F73127C3CD385ULL, 
            0xA3CA536E8544D1F6ULL, 0x27402455ECE15137ULL, 0xA13A3EEBDB63D35AULL, 0x94BAD6A39CF81CB7ULL, 
            0x5407430A78755D27ULL, 0x388FE960CDE12EE4ULL, 0xDD72E43D543DD474ULL, 0xCCC15DE0523EAAABULL, 
            0xDAF4ECAD9A3F98D4ULL, 0x7386216F1527EB00ULL, 0x233958D19BD3408DULL, 0x223C3F3727D4E64BULL, 
            0x224D0BAE3D370029ULL, 0x7AA12373D8EF6274ULL, 0xCF60CF89C7713B02ULL, 0x58D1995B7041FD74ULL, 
            0x4031B8D6E306D906ULL, 0x5053D6F3F051CDFBULL, 0x3216B4D00550B794ULL, 0xCCFEEC916D58D83DULL, 
            0x61A42C2E28930F15ULL, 0xE3AD603376FFA703ULL, 0x3FFC85A67665D829ULL, 0x5CCECC6793C1D7A4ULL, 
            0x94063B1AD6D7681DULL, 0x7BCC0FE547342036ULL, 0xDD85B0E9FCDE7720ULL, 0x289B4D1D6118C08DULL
        },
        {
            0x7D84C19F835F70D5ULL, 0x825BC2C9B90FC00FULL, 0x7C791C29BEC79CE5ULL, 0xF059F27A072C47E0ULL, 
            0xB025F44EE0A7D57FULL, 0x936A1EA46CB94173ULL, 0x3CD768AD8E11A9BCULL, 0x7D983492BF9E4DFDULL, 
            0x16DEF21467428712ULL, 0xAB0D0BBC344BC428ULL, 0xAA4D94488ED19476ULL, 0xA201A05D90F08E62ULL, 
            0xCA4B30CB407E505AULL, 0x23DF9D2FB2BFF9E3ULL, 0xB2A9FC3324EA0339ULL, 0xE3D33F92C4FB2095ULL, 
            0xC6E21F0B0B8E07C8ULL, 0x0FC146B5D24F4816ULL, 0xFD330E3168E322CFULL, 0x63076562AA60EBC3ULL, 
            0xAE58AD169790B2EFULL, 0xEF28B043F39B91C3ULL, 0xA47187B1B009ED7EULL, 0x81EB315ACD44F43EULL, 
            0x7A78FBAE89268488ULL, 0xEACBFAB4D75AE090ULL, 0x4E5B95FD5431F207ULL, 0x289D0D89BDAB1169ULL, 
            0x35D98E948075FF7DULL, 0xEA689EFE982EF226ULL, 0x60DBEF6DF0868030ULL, 0x0665818FF12EC646ULL
        },
        {
            0xC114BA7AC18F3AB9ULL, 0xC2F58D037BB51306ULL, 0x9A858BACAB737365ULL, 0xDD7ACED95736BE52ULL, 
            0xF61AF4AFF97475D8ULL, 0xE0F6A8F258CDA172ULL, 0x50D76D30876D20C6ULL, 0xDDC4F12383224450ULL, 
            0x851CC235F5041192ULL, 0x8945044BE6A7F276ULL, 0x3059909A33BFD4DDULL, 0xDDD9C6853B599B42ULL, 
            0x0740FBC81EBA26FBULL, 0xB926CB5EFB6E9CA6ULL, 0xD646E6932CCC0397ULL, 0x0A84B0909421E0C3ULL, 
            0x800FF534A05C01B0ULL, 0xD3ECA685B1A3A269ULL, 0xC3D418026451F513ULL, 0x82BAD924B2011780ULL, 
            0x3F2523B5C481F49BULL, 0xE25B3D8AB401CA7CULL, 0x81339001C3925B37ULL, 0xE68664101D45C327ULL, 
            0xF5D63C12558A2848ULL, 0x76B11C8C3CF9C2DBULL, 0x6C36E7632B1F3CDFULL, 0xF18B1C8CF79B32EDULL, 
            0x00C50AAA015FF2CAULL, 0xCF24031D3856DAA4ULL, 0x860B990008C7A185ULL, 0x43BDE0E90A132902ULL
        },
        {
            0xECB4D74CF2C2FE73ULL, 0xEA377F64858299AEULL, 0x6264E381A8CEE02EULL, 0x74E6164B5914EB96ULL, 
            0x51A11B90F847EA60ULL, 0x7EB1E99E46EC650AULL, 0x80FCE97DDE8C7218ULL, 0xBBD7BA2B2A2D4E7EULL, 
            0x559EEF1DB791671FULL, 0x376DEEE46972706DULL, 0xB4920AAEE96364B5ULL, 0x2C5C53868AAE3389ULL, 
            0x2AE7BADCEFC75397ULL, 0x9990260F072250AAULL, 0x2ED5F893F7954D28ULL, 0xDE33BA32552AD6F8ULL, 
            0x43EDCC4D8D5EDDA0ULL, 0x370BE77B1B42A73BULL, 0xD19B07CF438895A7ULL, 0xF1AB4604628D9BAEULL, 
            0x8BE02654EA3FC5E5ULL, 0x37963A69B5D92274ULL, 0x7FE047FB6EDBCA13ULL, 0xCDFCF3CD7E6976E7ULL, 
            0xE17C2B8802CAC03BULL, 0x0EFD49A224C17DEDULL, 0x281171548FBD1024ULL, 0xE6F473A988D34E04ULL, 
            0xD2A4FA352C562573ULL, 0x50CF2A9686634434ULL, 0x859501D8D7644886ULL, 0x3E95A4037A737123ULL
        },
        {
            0x6ADB1C4E34F2C20DULL, 0x6D25B234E2ED91C7ULL, 0xC5974AF8780B2A20ULL, 0x2A1F9900AB996F7BULL, 
            0x4B0C9DA98F108B9FULL, 0x625947C5B583E7D2ULL, 0x4A93A9160D1342C7ULL, 0x96E2BCF7A4397CB9ULL, 
            0x491C901E7E8D5F79ULL, 0x409801799E9C9198ULL, 0x5CC29C66F1D93FCCULL, 0x61158C2321977809ULL, 
            0x6AA5149C9187BA10ULL, 0x309F5A922823FB46ULL, 0x442C91E7B2402BD3ULL, 0xE09E93A55A2B8D8FULL, 
            0xEDAA81AF4F2C88F6ULL, 0x3756D95195D49B7BULL, 0xC808AE9D2A8EEE54ULL, 0xA426AD871BFF946AULL, 
            0xEA7DFF28374983A8ULL, 0x85ECBB6FDEC77648ULL, 0x94E8C9B9AA994D13ULL, 0x3A185922163E716EULL, 
            0x879DDAD9CA21B8FCULL, 0xA46B02D222D7E6D4ULL, 0x185C44FEC38F44E8ULL, 0x46A410F0E25624CEULL, 
            0x0B5893C0FCB83743ULL, 0xD3D8ACE62DE8A7BBULL, 0x16AE5F63F2D4FC22ULL, 0xE6481EE74E17140AULL
        }
    },
    {
        {
            0xA8178FEA8C1648C7ULL, 0xFB5E9093FCF44F3CULL, 0x1426F52C010BB52FULL, 0x8084101309A88F66ULL, 
            0xF6136D5CA4B2BE7DULL, 0xB4AD6055F2EAF2A9ULL, 0xFA941204C35B6CD3ULL, 0x42B261FE38B5C3E0ULL, 
            0xFC1A8B55DF40D0F8ULL, 0x21A5C441FC87A791ULL, 0xEF7292463484978EULL, 0x46A4D51775418E87ULL, 
            0x61F66E92EF581C8FULL, 0x7377A7E1FAD110ABULL, 0x5E9F3E42B6900A18ULL, 0x359BCAF66CCF9EEAULL, 
            0x7D8E2548686699DBULL, 0x053B14DBF59CB20EULL, 0xB835BE9DD93F7510ULL, 0xC4ACCB69D850B0F9ULL, 
            0x70BDC60668C293A0ULL, 0x4962A99FB74D5E21ULL, 0xAE26A1BB7A0CC57CULL, 0x374764DEB796BC61ULL, 
            0xB2172D3D5BFE5C52ULL, 0x0B4071A92A42A9B3ULL, 0xE75402383D09D374ULL, 0x2966AD928CB036FAULL, 
            0xF32BFB98984B8CDFULL, 0x026077817B462A0CULL, 0xA199D1E8E7812632ULL, 0x99B228006D3F5B93ULL
        },
        {
            0xD6332CEA634D0AE9ULL, 0x84BC8F577D55671BULL, 0x177CF5543C95E92DULL, 0x9160F3CDD8897678ULL, 
            0xEB20D597B7DDF2CCULL, 0xC0BAA8691BEE079CULL, 0xDD96883444F765D9ULL, 0xFC397A4A0FEAFB66ULL, 
            0x5FD7B5CEFF33D63FULL, 0x348EECE727B8D681ULL, 0x43EEC751CC084FECULL, 0x7EFF8B9B0E154363ULL, 
            0x978FDEAFC87F4DF4ULL, 0xD284FC489770CB6CULL, 0x60D2CD389B3D7D3CULL, 0x0FD0520670A19AB5ULL, 
            0x1C3137C1F7ACE4B9ULL, 0xC41A5B43E7B66A73ULL, 0x6620940D05E1E178ULL, 0xB59FA838EC6E173EULL, 
            0xD231F286DE273FF6ULL, 0x2D0C9B13C00E10C4ULL, 0x4F8B00E9DA944704ULL, 0x66AF893C79643195ULL, 
            0x5FD178989E27DC57ULL, 0x0A87F7F867870019ULL, 0x717A796D9D5591B6ULL, 0xB059CD78BA4C5776ULL, 
            0xE185BF9720AF30F8ULL, 0x688D44FBD030D760ULL, 0x8684DCFC0AF059BBULL, 0xB373F59896FF4F67ULL
        },
        {
            0xCB0307E1A544AA8BULL, 0xC3074ED29A06AA81ULL, 0x68D292A3A980807AULL, 0xC46C43E9AD6CF906ULL, 
            0x891517F331A4E2F2ULL, 0x1EB16224AA97AC37ULL, 0x7ACE8C357A0C4937ULL, 0xBB2F28E6E978C1EEULL, 
            0x9F7314EACD59F80BULL, 0x2989F9816D535B89ULL, 0x3BB8D739B96028AAULL, 0xD6234A1E209CA16BULL, 
            0xC1E946619ADDE7F4ULL, 0xA8B1A4FA96337BE7ULL, 0x9CEF5390AD78F32AULL, 0xEFF3C21092A0AF5CULL, 
            0xFF364DB86E14E6A4ULL, 0xC87EEBA78E80CFD3ULL, 0x5FAF873AA9A62EA2ULL, 0x5D5266C09FF6AFAFULL, 
            0xF6DA2407CEE048BAULL, 0x20001DB95FC67BB1ULL, 0xDAE02407A1F144D1ULL, 0xB97E34803B4C2B7CULL, 
            0x7654168DB36208E1ULL, 0x1824905EA2BEF9A6ULL, 0x4DB6F1EFFC6FEEC8ULL, 0x810C9DE737B2CC73ULL, 
            0xDA9D4F99B2BEFC25ULL, 0x40A790DA22721538ULL, 0x49DD7B8E966AF312ULL, 0xFE014DFA3438E56FULL
        },
        {
            0x77EAB2C97829E2E5ULL, 0xD37E5313A4FBC2EFULL, 0x6D3D03AA40DAD478ULL, 0x9FBD4F015A5A1427ULL, 
            0x2BB50BC8687E03B4ULL, 0xDDC2FE4196B8CDC4ULL, 0xCA00E84CD1C29B98ULL, 0xDF2BBB9E1354E7F1ULL, 
            0x4C893F289699E94AULL, 0x1C07B1D82A78814FULL, 0x0E2629473B5671EFULL, 0x9319C79526D9FF87ULL, 
            0xDF1A0891F7249890ULL, 0xDE2DA6A78CB234CAULL, 0xA8FA87C84C82A257ULL, 0x7C3E69A11D29420DULL, 
            0x3D91CCF05B4947FCULL, 0xC1E11689B1014898ULL, 0xB06570443C74AF6BULL, 0x35B7C0A64DFCBB79ULL, 
            0xE26E8E0850C72247ULL, 0x1CD78FC6CEABB81EULL, 0x2326FB83977B648CULL, 0xBD0DF1C8B8EA857EULL, 
            0x8F0AA821869D6FE6ULL, 0x97CE6D8C9BFF85A5ULL, 0x04D2BBE606322B27ULL, 0x0D629F758D74DB15ULL, 
            0xBB8BA3C1CA2C76B7ULL, 0x1A2B105396E2B182ULL, 0x78E1D1E87CD92B0EULL, 0x2C8A79325459DC1CULL
        },
        {
            0x035ECEA351CE24C0ULL, 0xFF114B97D1355AC3ULL, 0x3C6007C28421828AULL, 0xFB989149E85F5F30ULL, 
            0x9969AEE3294C1057ULL, 0xACD78D8947B99086ULL, 0xA63F0CE629B339A2ULL, 0xD00FE1704287818CULL, 
            0xCFB40FFD1E4C81E6ULL, 0xB3E20ECCEF222154ULL, 0x75FFEB7C07F25B77ULL, 0x4B6E1F674868D2E5ULL, 
            0xE3660C89A78E4CB7ULL, 0xE643AA463765E2AEULL, 0xE5B40CEB5480FF8BULL, 0x6568EBAF9412EB1AULL, 
            0x5FB15A22F3F6273FULL, 0x569E0FBBE9F73200ULL, 0xC51A23AA372473DEULL, 0x6C0DC672B7E35F97ULL, 
            0xF579BB688CF61FC9ULL, 0x4781DF3EB77A1BCAULL, 0xAAD9793B2305F781ULL, 0x77BCC6B24EE19860ULL, 
            0xE73081CB460ACC08ULL, 0x65809A426D002E46ULL, 0x69F981B9E35AAF4DULL, 0x8230449D173D9757ULL, 
            0x8D47DB7C4F3D2D40ULL, 0xB36D095458FA83D1ULL, 0xB9C68DCFFDDE19C5ULL, 0x05C68E993BE7E025ULL
        },
        {
            0x032CA79EDB44DFC9ULL, 0xFFD3091227782BC3ULL, 0x0928C2849050620CULL, 0x2F60AD3DE5E614FAULL, 
            0x90A632BADE7F9CF0ULL, 0x4D1B2BEA2E0591FCULL, 0x6DC3D34DCF89E295ULL, 0xF07135168E21A3EFULL, 
            0x07F0FAEDD2D1A933ULL, 0x691F108832A539A6ULL, 0x57A24593CBE0F4ABULL, 0x965A70CB05E64DFDULL, 
            0xDC084650716F9B51ULL, 0xA0270C18D48C53CEULL, 0x876C6C1AEA6652D2ULL, 0x1735B4F563E5B034ULL, 
            0xE901CEE5CE422728ULL, 0xA5388FEA1860B226ULL, 0x9A10BBA9E8BFFEDCULL, 0x05FB87B7D731FCB8ULL, 
            0x2001FF3521CC8137ULL, 0x03EAFF656805943AULL, 0x8F5C64967AE08D41ULL, 0xD93981BC7055905CULL, 
            0x1849304787FA9EDEULL, 0xA12F7CDE2A5E20FDULL, 0xC107910942B9C58AULL, 0xC75C9B8A8064DE8CULL, 
            0x7C1DC8F538466B6DULL, 0xCE5EEAF1A307026FULL, 0x3F13740A0D6C515FULL, 0x0014A63C5429B1C2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseDConstants = {
    0x39E7AB5E53474A70ULL,
    0x552E92F8D6CC51FBULL,
    0x370088A6A01FCA92ULL,
    0x39E7AB5E53474A70ULL,
    0x552E92F8D6CC51FBULL,
    0x370088A6A01FCA92ULL,
    0xEEC2ECCE011DD6A8ULL,
    0x66C55D3B9D84EDADULL,
    0x5B,
    0x42,
    0x1B,
    0xDC,
    0x3B,
    0xB5,
    0x32,
    0x05
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseESalts = {
    {
        {
            0xA8888E7E60071A29ULL, 0x26E7E49CB4235109ULL, 0xC0B2A60FC532E771ULL, 0xA8569E02504CAB75ULL, 
            0x9F4E4168F806E96CULL, 0xA5D215CED90FBFBBULL, 0x2EB81552CFEFCAC4ULL, 0xE71D7C80888EC505ULL, 
            0xC00F321035E46B6DULL, 0x8AD4EA6ABC43D037ULL, 0x7640357317450FFDULL, 0xE1CBF9264DB78E4BULL, 
            0x6724C274DFC3133FULL, 0xB6326E785B7E9708ULL, 0x4B7731D0BE8250A9ULL, 0x2943FBA1266ECDB3ULL, 
            0xA48CB7EEB78FECE9ULL, 0xC1B46C5B3B07ABD0ULL, 0x3F85CAE44F717A68ULL, 0x4AACB990710C087CULL, 
            0x328AAF874F641745ULL, 0xD73F36065C4A0A2CULL, 0xEB49D49A9FFD6038ULL, 0x5C7EF7E4CEFE0D80ULL, 
            0x5203A9AB6868DFCEULL, 0x52FE58267C313F67ULL, 0x6F691F014027ACBBULL, 0x3F969AFCB495D08FULL, 
            0x38925B445B1B0D5BULL, 0x818E2A5F905C30ACULL, 0xFA74690111BF1591ULL, 0x241A700CF3D57816ULL
        },
        {
            0x10861751DD3339B4ULL, 0x6FAE8D3BA6763E2DULL, 0x13ED8077DF2C555BULL, 0xA29CE4D80CF80030ULL, 
            0xD706D015745B339FULL, 0x7FE778225C1005DDULL, 0xF8FA4F07CAC1340EULL, 0xE20679E54976B3C9ULL, 
            0xFD47F9EB7F27BFE7ULL, 0x6409D13F1DFD9495ULL, 0x6FB78937C61B750DULL, 0xC1333EA521DAE1D7ULL, 
            0xE9CE3CDD185D5AB7ULL, 0x45C3D565803268B0ULL, 0xCA063AFE81CCB98DULL, 0xB0367B9C96655F0AULL, 
            0xE6386C94BFE9A3B1ULL, 0xC48AC0647B6C38A5ULL, 0x9B2AD3132D0B8C1DULL, 0x5620B56FE4FA192AULL, 
            0x19B1FA71721D005BULL, 0xB685F684B304A697ULL, 0x756C535C8194CFE2ULL, 0x31D5DED31B8217F6ULL, 
            0xAAB70B4A6FC117A8ULL, 0xF6FBBCD4ADC47940ULL, 0xAEB07010CF2BFD9AULL, 0xD0F410AF005B4661ULL, 
            0xE2C966EEFB74C4ADULL, 0xEA885E3874CEC303ULL, 0x13311F6C9C6F1537ULL, 0x09E338EBA42B8A49ULL
        },
        {
            0xBC1E3AD8F1C70178ULL, 0xB117ADD290457738ULL, 0xC696B0011FDF5365ULL, 0xEDDDC7D3CAA28D71ULL, 
            0x3862CE91926AC82EULL, 0x2F05CD8A42CBA8ECULL, 0xD6FE5D0BF568080AULL, 0x2259DDE08C8E19B2ULL, 
            0x8AB9701F64C4EDF9ULL, 0x7F738F5AA0F52C23ULL, 0x676200D4231C6413ULL, 0x5158AE249372382AULL, 
            0x7683CF9D6FECAB96ULL, 0x6C17B638CB195736ULL, 0xE52F84FB2602F81DULL, 0xC3FEA50041AE45AFULL, 
            0x07F5DBA67B707043ULL, 0x45AF0FEA8928CFE0ULL, 0x8367D85642B5181EULL, 0x6A69D9B9E344447BULL, 
            0x802C8A782A96F0FCULL, 0x355D8EFB2CEE0897ULL, 0xA956438FEB5C8419ULL, 0xFEC4A615CAFAF5CAULL, 
            0x19AD086E97E19F80ULL, 0x650EA554EB4602E6ULL, 0x58F9FBC1FD5B0DCFULL, 0x965BB3E79D6F1DF5ULL, 
            0x0010998FA89F755DULL, 0x7216F6A391BD75C5ULL, 0x2BD6734218A52875ULL, 0x21D45E77BA9E3EADULL
        },
        {
            0x7DDE58E4C028C0D7ULL, 0x70D8ECE8AC4E2B97ULL, 0xD7D40102EC9079E4ULL, 0x2A5235B156645357ULL, 
            0x07449F5A65DFE51AULL, 0xE54B31C476EF55F9ULL, 0xC5979D326A8ED3EFULL, 0x768C034EEAD0BDD0ULL, 
            0xA30E704CAB5DD133ULL, 0xB2689406B3EC6961ULL, 0xF72648F90D5AEBF5ULL, 0x56AB1BA6F708A7AEULL, 
            0x8C45D11561B20D67ULL, 0x5CAA6F8049C2B815ULL, 0x7FD3E5F7F44BFAE7ULL, 0xD262D8C9B74084DDULL, 
            0x72B0C31600C372C9ULL, 0x12BB8B8A8C51FAFEULL, 0x95011DAC9CBEF854ULL, 0xAACC1282E01AB15AULL, 
            0x09924E2839333182ULL, 0x487D0960C9039E3CULL, 0xB6F08F1AB0FE4CF4ULL, 0xD5894DA7D4E4CC1CULL, 
            0x9048FB62ACB5E348ULL, 0x6628F49B36B055D2ULL, 0xCCD52CE69F03B49BULL, 0x52E7E21B7713D186ULL, 
            0x5EA7155CEBD13379ULL, 0x2B220C8C78F343CEULL, 0x0C1470FAB02B96CFULL, 0x96CCE3BA21B7EFB6ULL
        },
        {
            0x0EFF8BED7667C409ULL, 0xFE443929364D20ADULL, 0xD589281D04D501A2ULL, 0xFE51535550DA0608ULL, 
            0xEA33494524FDC6CFULL, 0xA0EDB6E2F8672548ULL, 0xD4E0556994684ED9ULL, 0xD1C77937C5019901ULL, 
            0xA86A5644328D2866ULL, 0x6369D1FB1527D113ULL, 0xB99DF7FBC57F4113ULL, 0xBA5BC36A607E152AULL, 
            0xA8AD1254B6AA1E06ULL, 0x192E94E4C80CC411ULL, 0x6F21BA24CEA957A3ULL, 0xFC943E8D2D13FD58ULL, 
            0xCC88C59FE2A5206CULL, 0xC692D14D664E372EULL, 0x5FEBEA077EE8833CULL, 0x0709312A67701D7FULL, 
            0x34AD71549DA4B177ULL, 0x2A9D0BCE8A872ED9ULL, 0x1A803402DA52615CULL, 0xDD96F6AA5536D446ULL, 
            0x73DAC89F07ECB971ULL, 0xF4BE6ADD31A8822DULL, 0x15BD49F0B2F8CBE9ULL, 0xBD6935BC2A5951ADULL, 
            0x00EDD8EB50118645ULL, 0x9540F1BA714D778CULL, 0xE1F1E694B0903E2CULL, 0x0B2919957C7012EEULL
        },
        {
            0x610DA8F7F73A7F5EULL, 0x069869AF841994ABULL, 0x67B5166EB5EC4F1EULL, 0xE003F0175571C4F3ULL, 
            0x18403ECF3630F7C0ULL, 0x7F8D4314F7CACCCEULL, 0x23037A3F9C853723ULL, 0xC5A62E4EFA55C4ECULL, 
            0xA2230B193F34AF65ULL, 0x37D9BAD413983E18ULL, 0x8B2F37B70EF7B087ULL, 0x10E20145AAFA886EULL, 
            0xDCB5786A0EF4814AULL, 0x715A3311668CAF3AULL, 0x9B1AA0263DA6C1DAULL, 0x130C037099A5B7ACULL, 
            0x75714E22146B75F4ULL, 0x11C4DAFEA3F2BE0EULL, 0xEFE73DDCC0896FC9ULL, 0xAC6FD24760D62DB0ULL, 
            0x02532940EA344E44ULL, 0x27731A16E28F3A7BULL, 0x8EDFC52BC6981C81ULL, 0x89A3521C589C325FULL, 
            0x7BBC9CB8B5355E82ULL, 0x2352457EF87DE6B2ULL, 0xA77AC23AD3B9E8A0ULL, 0xC047566BF8FE963BULL, 
            0x626889BF095FF4E5ULL, 0x799265080476FCBDULL, 0xFC4668EE73EBC604ULL, 0x37A5184B44CAB4DBULL
        }
    },
    {
        {
            0xC0BEF16572699F9BULL, 0x6FDB120F196F5550ULL, 0xDA11520AB6447F2EULL, 0x90CCFB2A410598DDULL, 
            0xECE268EEFABF525AULL, 0x8ADE74E15A629A6FULL, 0x6616B9587E17A5FDULL, 0x8F9C2470133FBB49ULL, 
            0xBD8844EB7BD76EECULL, 0x9577084A438B4316ULL, 0x43A56B8E3551D322ULL, 0xE053CE381F3630BFULL, 
            0x2EBBDB3E9BC9BFE3ULL, 0xA6129C79AE5B586EULL, 0x3BD7CB944CC24DC8ULL, 0x2D70DEA81CF6CD0BULL, 
            0xC410AD5A4E1E7223ULL, 0x3A11905DB2B6D07FULL, 0x10C166F23420A0F8ULL, 0xE742A89B36E3249EULL, 
            0x18D6CCE5171429C4ULL, 0x01A2242FDE48BF4CULL, 0xBDD0B9523F6B1B33ULL, 0xC7DAA208B65D5DBEULL, 
            0xC0DBD0BB2036FA52ULL, 0x58A03BCB34FE2C17ULL, 0x5A1D11B62C4F6FDDULL, 0x19BBDDC0A1F7762CULL, 
            0xE1B43182A2E54D4DULL, 0x178D66ED68D72E35ULL, 0x3696F66DA76790EDULL, 0x91F6A3ED1812CFCDULL
        },
        {
            0xD25AFD67A59B8222ULL, 0xAB0A754DE6EA27A9ULL, 0x807BE2E2E1C237E0ULL, 0x289443CC82478889ULL, 
            0x11CF5F64DBBC21CCULL, 0x5A4A62868C2206C3ULL, 0x847DEC1712797D54ULL, 0x7A2F62EF46DACE76ULL, 
            0xE269E84BE0DD7045ULL, 0xA975BCCF40082025ULL, 0x8DD72FD063C8E85CULL, 0x6E7B1FB396C1E038ULL, 
            0xAC4F2781A2B4AC62ULL, 0xD901621726F4B23DULL, 0xAF7C1503231A15EBULL, 0xF2701EA14BC044E0ULL, 
            0x1772121B962791D4ULL, 0xB087728A0BCE4421ULL, 0xE90B9A5199E5413CULL, 0xC3A0FCC6BA55B412ULL, 
            0xFEFE049B5E653E73ULL, 0x92B01E3C7A45B422ULL, 0x4DECF43DD15460E3ULL, 0xF6C7F936FEB953CEULL, 
            0xC7318E7FEA086B04ULL, 0xFDE6D27AFB308F78ULL, 0x3BE2A371774195FFULL, 0x4CC8CFD91EA5C184ULL, 
            0xF120A44CBBF101F8ULL, 0x6390417A44C4328DULL, 0xE5E78B3FF9D951F1ULL, 0x4DC410F2D5A1DC13ULL
        },
        {
            0x9A08E0A97CEB62FFULL, 0x8BEFE8A98567CC0AULL, 0x3A68682DDDB559DDULL, 0xA1C56B5B6892230FULL, 
            0xA10244E9D1ACE949ULL, 0x10F4562F34FEB77FULL, 0x7506676D6D24EEB9ULL, 0xFCB4B7A4E21CCAB2ULL, 
            0x908AC0803170481CULL, 0xD29531C46CF1AAFEULL, 0x5F25775A23BFE8DEULL, 0x4A72AC9B6706832EULL, 
            0x3B8B797E9B73D2DAULL, 0xE165BFFD89EBE117ULL, 0xA39D07118BB01538ULL, 0xA9A02C75043AADFCULL, 
            0x0C51C08EEA36F709ULL, 0xA29590FE94EA4DBAULL, 0xF6C20DDFB5818A13ULL, 0x0CBC4B2B815986ABULL, 
            0x3A97E72C591B2DE6ULL, 0xC9A728F3FEEB2BC5ULL, 0xC4B7A3C08AF8623DULL, 0x46ECB27807B0CACAULL, 
            0xEDF47289DD609B9BULL, 0xAF7593980D4A66BBULL, 0x8EE6284F99329BC1ULL, 0x09CCF3FBD23650C2ULL, 
            0x1C492E68B2258351ULL, 0x47D607CB07674F7CULL, 0x80CCB723FF4179AFULL, 0xAC43D75EF2DDB067ULL
        },
        {
            0xA9EB740BB6E7AFF2ULL, 0xE0DE933257EEDFACULL, 0x0C4A037957966D25ULL, 0xE416CCFFE9B9A465ULL, 
            0x998D5324C056E27BULL, 0xD7AC7F1E307021FDULL, 0xC78B8B8EEFEF6F5DULL, 0x10D0F3CC98B844E4ULL, 
            0x96F33A1498738346ULL, 0xD2215E806117ED58ULL, 0xCCF41C43CDEAD95CULL, 0x5ACD7AE9D25554ECULL, 
            0xE5EAB95A6764A384ULL, 0xE30DE4C77E1179D7ULL, 0x73D3280AF804F4A1ULL, 0xF192A9AFB63A7356ULL, 
            0xBFF5317B488918C6ULL, 0x5BAE0A377624AFE3ULL, 0x08E9E3B87917DFB6ULL, 0x64ED3DF57747A67EULL, 
            0x5B4A687C141C4C12ULL, 0x5A792947F0F4C80EULL, 0xBE44F167327B1FB2ULL, 0x2047BC9C63690D20ULL, 
            0xB5263C718C10CF7BULL, 0x217820D55282A091ULL, 0x3F215A0BF5F73C93ULL, 0xB537657EC406367BULL, 
            0x98E0A6F57C0023E1ULL, 0xE2A370F9CD3C0E0EULL, 0xA6AD6A5CB8B3D4ABULL, 0x4EA502C2E39CCF71ULL
        },
        {
            0x6F89F060A73990DFULL, 0x2787BD40BD96F0D3ULL, 0x147D51A87B711359ULL, 0x6061321F7B49BD29ULL, 
            0x72E5ACB1554EA05FULL, 0xF9263CECA43D7B5BULL, 0x8650BD78DFD945CEULL, 0x6BA0BEFEA7AEE8E4ULL, 
            0xC332AC7F1024CCB8ULL, 0x05063E81EAC5C0DCULL, 0x13281F03BF8B4940ULL, 0xD769E452058ADA9CULL, 
            0x1E8783793635F6B0ULL, 0x744539456BFE5D05ULL, 0x37B4832F1C2683C6ULL, 0xAEFD1CB7A9FD9DC6ULL, 
            0x9B6428F1B339BBC3ULL, 0xC622B1D8012E7FAFULL, 0x19D832D100950259ULL, 0x7ABE2916BA188AE9ULL, 
            0x03FA3CA1D859C8F7ULL, 0xC73DCD0F8F65FB25ULL, 0x40AC29757BB83220ULL, 0xBBF1B46445E08868ULL, 
            0x543797D193AFF029ULL, 0x495A820830C8C8D2ULL, 0x5AD41FB7C1184441ULL, 0x6DF5421A389FC4B8ULL, 
            0x2219D475DAAD0D1FULL, 0xC1C2A44DAB102806ULL, 0xB6C37A1F26057383ULL, 0xCFB888E4ECBD0FABULL
        },
        {
            0xFCCB0176B428677BULL, 0xA201ACF18377B215ULL, 0x622B1F45E67C54ADULL, 0x691CC793A974AB3EULL, 
            0x7E4F30850AABF975ULL, 0x89754BE941E1259EULL, 0x433804EC95258A99ULL, 0xE3BC84916D6D4843ULL, 
            0xB7A3098E1D99AF62ULL, 0x4F6790132567DDE4ULL, 0x4EAD9FF401E67B38ULL, 0xF3460FAE2BE41184ULL, 
            0xF0EC5F0F4956D1FAULL, 0x02F55EC5F604B1DBULL, 0xC434ED02F0BA6C0CULL, 0x0F6E2BD549F93FFAULL, 
            0x7CA1B165328CEC2CULL, 0x1870A4843B9F8182ULL, 0x5E85C699A3636561ULL, 0x45B3297BEA5DF4E9ULL, 
            0xCEDF99DBD56DA7B8ULL, 0x16289F86EF5465BBULL, 0x55DE7621B43FFCE8ULL, 0x4416CBB74C007624ULL, 
            0xB80B0E84B732C6AAULL, 0xE666ED377C2AD3A6ULL, 0xF1DD47BF6F6CFBBBULL, 0x9E5D2CC10EC17593ULL, 
            0x84C08372DDC190D0ULL, 0xD5463C2ABC0C6B37ULL, 0x8BFF6DC1865F7B9AULL, 0xDE2869B601227E02ULL
        }
    },
    {
        {
            0xB5255622AE424071ULL, 0x5E8E701A6D4E7219ULL, 0xD0B007A21ED01FB6ULL, 0x6B276951EC65AEAFULL, 
            0x563C3E3CA9DE84E7ULL, 0xA42EE7D64B21FE77ULL, 0x4FB6C07539FF98FFULL, 0x3AF807C85C7A4472ULL, 
            0x92505BF9E0592FF5ULL, 0xA79BA5183D1D5F28ULL, 0x46D2B488E4D29DB3ULL, 0x0E994047A91208F8ULL, 
            0x8C64669D1DFC0A4CULL, 0xF3B427E8A7F68B44ULL, 0x1C53D8480E0197DAULL, 0xC655E0E0A0FFA3B1ULL, 
            0x26624F523C1D28D3ULL, 0x5201748B3676E808ULL, 0x89DFB5FD84E3C878ULL, 0x40CBD562E8FC6BF4ULL, 
            0xD4D23D688568B606ULL, 0x2EAD6933DD054E54ULL, 0x73572E925AB01A43ULL, 0xAD2244B23DB50E29ULL, 
            0x7D2C2C70881F8F20ULL, 0x305263B7D60062A2ULL, 0x597689816FA2751AULL, 0x92EA994A9C4AF300ULL, 
            0xB936366D102DD317ULL, 0x505BB056AEC95859ULL, 0x142EA23C9632940FULL, 0x59B2E07EFB423BD8ULL
        },
        {
            0x8867B72E6CE3752AULL, 0x1E34A974FF71BDA5ULL, 0xA257016BA7055287ULL, 0x7A44BF84D6BCC5D0ULL, 
            0xDBB24A39F5F7C632ULL, 0x8650CDDF95C923E3ULL, 0x87B40BD6665E5C74ULL, 0xB580B8993A1FA46AULL, 
            0xE6F07A7A90705783ULL, 0xCAC078B9913E4A15ULL, 0x7D19CCF2C567CCDCULL, 0xD8010381305E113AULL, 
            0x8E468C393FB03D27ULL, 0x75AE3D93ACD2FB66ULL, 0x67F4E56DB2133D29ULL, 0x02244FBE4ACD4BAFULL, 
            0x9D1ED48C815D8D1FULL, 0x2FCF48786E160367ULL, 0xEE8FDAD72A3C2C93ULL, 0xDE8632AA93F32FA0ULL, 
            0xFF8619CA6C57CAC0ULL, 0x0E63302EE1ABC53BULL, 0x1956D674C3B283A1ULL, 0x52E782EC248FD4ABULL, 
            0xA1E6DD0DD3315115ULL, 0x7867F56C5A7B939CULL, 0x4C508C058606A1B2ULL, 0x3EC2EB726438E48EULL, 
            0x45377A0C0DA8CFBBULL, 0xAB800EFEC1D19D6CULL, 0xD34AA9DA56323972ULL, 0x3BA6D350C09455ABULL
        },
        {
            0xB4615C6006430F37ULL, 0x3FB3B7A7E9E52C8AULL, 0xA95C3637EBFC981FULL, 0x846ABC86B83170A7ULL, 
            0x98F1E4288737D5A6ULL, 0xAE30D84AF25262C8ULL, 0xEFDE3CCB080B8778ULL, 0x5C3F9C55D04C16C2ULL, 
            0x54B341125441CE11ULL, 0x73FAF696209D9E35ULL, 0x78B24C1C89A35868ULL, 0x37B1E6C882A098D1ULL, 
            0xBA0D03D0978901B2ULL, 0xC84581FAA5112A1EULL, 0xAF29293A76CE6CB5ULL, 0x6514792F2379DC17ULL, 
            0x567CAEDE4E53FF9EULL, 0x7BE697382559E52BULL, 0xF957927B294B7561ULL, 0x8FE153D073DFC924ULL, 
            0x68AC99C8912BEC72ULL, 0x68F4FBBB7462A7F1ULL, 0x1EFF1B03CA7C9F98ULL, 0xE9F11E0EBFB6A77BULL, 
            0x1D773ACD388DEEDCULL, 0x19A5C88005431E67ULL, 0x51EF069FCAEC65EBULL, 0x4CEA1E176250DA81ULL, 
            0xC846EB977614A39BULL, 0x9360A487717238C8ULL, 0xD852E6A008BA7C58ULL, 0x2D49E01310F18AA3ULL
        },
        {
            0x37BB58E78BD664DEULL, 0x1818A09480879AD8ULL, 0x9748D4B242A6AFE6ULL, 0x06B3E54A6DB86A2EULL, 
            0xDC4308662F5EF038ULL, 0xCA9CC92B35C5369BULL, 0x59DFF020343D49D8ULL, 0xF54E91A6CD14ADE4ULL, 
            0x70AC4A7D2132C6C3ULL, 0x8E4E77369610AB31ULL, 0xE4D4F4D70825A8F8ULL, 0xC1CBEEE2A60007D9ULL, 
            0x97609C7179A24836ULL, 0xD29C1A611A3A796CULL, 0x322392C601F4096DULL, 0x167825438A5EFB43ULL, 
            0xAE48F14D6EE231A8ULL, 0x3F97858EBE883B3AULL, 0xDE0C162D94404CBAULL, 0x2381C8A4F3922C70ULL, 
            0x9FAE4478E740FAB5ULL, 0xC1B87CB600345753ULL, 0x6A2278E2CE856C9CULL, 0x950E583103443B47ULL, 
            0x40A0EEF25ABC52C4ULL, 0x898D0143C90827C9ULL, 0x68683A8149524550ULL, 0xBDD2C4647DF42131ULL, 
            0x8136C3E2F2F956D3ULL, 0xA76E8A3CF03FAE25ULL, 0x190BF9F21F3E16ECULL, 0xAB63FF95DA6D6D20ULL
        },
        {
            0x58BCADDD463CAAF3ULL, 0x3C8FA4C7CFA6A229ULL, 0x79E02BA5E67E41D1ULL, 0x75E076F4BEA7BC69ULL, 
            0x908F4ECA68ACF14DULL, 0x3D81643040CC070DULL, 0x7C5C98D130828944ULL, 0x2466A83469391E69ULL, 
            0xB8FF5515870FF0AAULL, 0x1960ECFD4F02660DULL, 0x257839903DE344C8ULL, 0x13E9896F596B3D26ULL, 
            0xD45B99E57BEF2F20ULL, 0x64AF12EE9A282C69ULL, 0x7F2565685109DAFEULL, 0x72553666B379B63CULL, 
            0x9FD4177E052476B8ULL, 0xF47D3E2CC02E11DBULL, 0x1DDC4ED02199F33AULL, 0x73F6D2664BD11E21ULL, 
            0xDBDFF7DCCBDCA66EULL, 0xFC4942CE99931A2BULL, 0xCE28F9D2697A951CULL, 0x2172C4ABE68B83EDULL, 
            0x82F78FE05236C033ULL, 0xB64B3E4D480A333EULL, 0x5F6D4B8AEA7E8ED2ULL, 0x64DE311B86869221ULL, 
            0xBFACE6765AF8187CULL, 0x6E5179B9BA8BA31EULL, 0x465646CCC327EB07ULL, 0xD48DDD413ADFAD36ULL
        },
        {
            0xCF03785E5034D917ULL, 0xD2BC6C69CD6FFE0AULL, 0x593F4EF30F957C55ULL, 0x7325A1EE1872C3D2ULL, 
            0xAB8BD34DFE717A1DULL, 0xEC1A0C3ED4AF96F9ULL, 0x299EDFD815CB3CDBULL, 0xDD3261E1C1E85BF4ULL, 
            0x667F9ACDF30A37EEULL, 0x25284B8CE746D5E0ULL, 0xF496A9E622463BDBULL, 0x32B596D57A2A0733ULL, 
            0x15CFD569034D1BBBULL, 0xA18A30C373D8C0E5ULL, 0x199DD53787E71B6BULL, 0x6D63CFB689B4DFF2ULL, 
            0xAFE4CE9E3F10EFCFULL, 0x9B623FE42B245A99ULL, 0xD7694751BC4944CAULL, 0x849D3137DF7BD87DULL, 
            0xDC1D345C1FC42368ULL, 0x36DD2A22CE7213D3ULL, 0x66DAE477C522D659ULL, 0xD2BAC26C0C4FD749ULL, 
            0x279641CDEF527561ULL, 0x5960F5FBBB6E51CFULL, 0x3071EA8D688BCF1AULL, 0x9B1DFEA248790E4BULL, 
            0xEA4BCE5E7D492FCDULL, 0x0DC58F57E59247DAULL, 0xE7259B3A1FCAC9BEULL, 0x940FF66E9B830172ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseEConstants = {
    0xF739C671883DE1A4ULL,
    0x31EEEABD747E1E30ULL,
    0x1D32E8ADE9CFE837ULL,
    0xF739C671883DE1A4ULL,
    0x31EEEABD747E1E30ULL,
    0x1D32E8ADE9CFE837ULL,
    0x257C10B76D5186C3ULL,
    0x3E4A7DD6EA6EB73BULL,
    0x5E,
    0x8B,
    0x85,
    0x65,
    0xC6,
    0x18,
    0x57,
    0x10
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseFSalts = {
    {
        {
            0xBFBC1666E96A3ECFULL, 0xBDBA70A6A2BFA172ULL, 0x8BFAFE527BFCE54FULL, 0xE473FF09F0C7B95AULL, 
            0x904D3DC325E9FF83ULL, 0x27FA4AB258F22764ULL, 0xCB2BF9D782D897B9ULL, 0xDF0BC3BBD3312812ULL, 
            0xB8C1BB3B19AD10D0ULL, 0x773407F592B50E13ULL, 0xB4770CE86554B50BULL, 0xDA518181066DF5D6ULL, 
            0x9913E1E0177A44E6ULL, 0xEB33F7EE944352ABULL, 0x97F7BB133C5190C2ULL, 0x6C06C2B3CF025CF2ULL, 
            0xE953559182E94A76ULL, 0x93B2EF4CB39934B1ULL, 0x87F7933243685619ULL, 0x3604357302AB1517ULL, 
            0x1527EABDB81ABA35ULL, 0x4A76FD3997F711DFULL, 0xA210246C18B664FDULL, 0x53CA8F89A478A888ULL, 
            0x22974431E3FDACC0ULL, 0x7000285AEC7FF9BFULL, 0x2EBFD916B4D5BC5CULL, 0x7F05681EF1E298E2ULL, 
            0xC909464FE1560541ULL, 0xC86B4AC9E801CC05ULL, 0x766B31CE08199217ULL, 0x5FAC0D854AADED5AULL
        },
        {
            0xEA51718AFBE87647ULL, 0x0835735865BB2C6CULL, 0xFFB6C7C29687824BULL, 0x478FFD9066CE5661ULL, 
            0x904BB8CD6A06961EULL, 0x4D3E4A302876CAA4ULL, 0x55F73584EBBEF603ULL, 0xA8BF6418678EF22CULL, 
            0xE309379651D9FC98ULL, 0xBF8A8252BE9DC8F2ULL, 0x6698761FC6CCF8E2ULL, 0x40F31D2392BF5D19ULL, 
            0x930476E94FCBC19AULL, 0xFAE8D2CE4073B455ULL, 0xD1D586FA506F1CE5ULL, 0x5C6D341B604328AAULL, 
            0xA401F32E1F7429D1ULL, 0x35DBC97CC3A42B57ULL, 0x710BD211EE7EA8BBULL, 0xDB4BB0A6D902B29CULL, 
            0xF22313104777276AULL, 0x49F3A950989409D6ULL, 0x253E7F706F5F3EC1ULL, 0xAA1A0185DAC5C4D6ULL, 
            0xD63718AEBB476218ULL, 0x9ED99EE8015F43EBULL, 0x21864D14D0D0797EULL, 0xF5A5E1DD7AD208F3ULL, 
            0xDC7FAEEB942A4AC3ULL, 0xEF1FEC8A8A5ABEBDULL, 0x2DA246583A50ED7AULL, 0xE32EBF4926DE7E60ULL
        },
        {
            0xDD669AC8119BFF38ULL, 0x448156DD30308CF0ULL, 0xEE9EC7122B145DA4ULL, 0x0D24F70855BAB704ULL, 
            0x4D747E04472493C3ULL, 0xC509B73C95796BB5ULL, 0x516215B62A87EFEFULL, 0xB89967289B7CEFE0ULL, 
            0x9CB6A3CD3D844C2EULL, 0x401435E59AD09072ULL, 0x2C1B3A4E29BBC7CDULL, 0xD08C9D9CC541FEBBULL, 
            0x2EBF5C37923914CAULL, 0x62FC909717B9D8C8ULL, 0x4A9DD0B922498D1DULL, 0xB094AF5C03754C8BULL, 
            0x197681DC2B01D136ULL, 0x0E7D824623E3CAAFULL, 0xC2B2F91E92F25103ULL, 0x56090AA92D43107CULL, 
            0x0E1C217F96A75395ULL, 0x95AF65819D4C38E5ULL, 0x38BE4BCB9877F558ULL, 0xEF6263BE3C45F39BULL, 
            0x07D352BB044CC6CFULL, 0x254FCEE529412953ULL, 0xAEAA349A7CC62E41ULL, 0x389CE08E16FB2F7AULL, 
            0x764736FF2E6DEC53ULL, 0xD2FDD663BC12D7EDULL, 0x4E3DCD4132D812E1ULL, 0x995E9B9A205AD24BULL
        },
        {
            0x62FF0B039E373B6CULL, 0xE98C0C6D0BC028CBULL, 0x99E603A5F5CEF1C9ULL, 0xF8905D7A2DB50265ULL, 
            0x6510985A20E58475ULL, 0x90ED5AA4753B30D5ULL, 0x7F2EA6BC0EF32A27ULL, 0x4AE05686B20CAC6BULL, 
            0x1F0B38539BE47C19ULL, 0xB02B820127ACE38EULL, 0x9505E6B131F42856ULL, 0xAFAC7F48479F7F96ULL, 
            0x7638CAFC1806EB34ULL, 0x7306ACE46166254BULL, 0x4EAF20998ACC26F5ULL, 0xB7A0628F55E94EDAULL, 
            0x2EB3DB7D31A6884CULL, 0x1D5CB407EF0028CBULL, 0x3BDB5FF55759E2E5ULL, 0x90C893594D96A933ULL, 
            0xA8C0EF64E852BD76ULL, 0xF711AD625609FEE1ULL, 0xE74E12C6064129C0ULL, 0x06005D30091662F9ULL, 
            0x2EAD77FE4B6690CBULL, 0x130D94A844774893ULL, 0xD019353E8BF369B6ULL, 0x5CFD66B2EEDD991FULL, 
            0x1F1FA71256FD6C30ULL, 0xD09988F4B503D9B8ULL, 0xB3482EF0F04425C4ULL, 0x6DBAADB622A854E3ULL
        },
        {
            0xD8E931B3F4C8B6F5ULL, 0x5FDC7DC74BDA022CULL, 0x978856E152896D3EULL, 0x97F68348017B4CB6ULL, 
            0x2AC86DA09E707E4AULL, 0x8164A4F3F306C6B6ULL, 0xEB83880C3E7C1DF3ULL, 0xC97EA1CCDA52F8B3ULL, 
            0x4FD96702518AA0F9ULL, 0xFE77A965F075EA33ULL, 0x89F6E8DD3D37E1F2ULL, 0x95CDD1D90168E286ULL, 
            0x53EB48EEC1E2AAB1ULL, 0x78A743C462004D69ULL, 0xFA76075149147118ULL, 0x081B84D7BB4A8CD6ULL, 
            0x119305CE98090FE6ULL, 0x9D04CB348AEE9982ULL, 0xBBD2441A4972BE16ULL, 0x371CFF1F7602CD36ULL, 
            0xB810D95E32815AB3ULL, 0xC9D6F4E3BBC48C5BULL, 0x4F2D17ACF64F0AB8ULL, 0xC7A970B9FD2DFEE1ULL, 
            0x0FA0B1B904E555C2ULL, 0xA46237877C71CA43ULL, 0xED431251484FF2DDULL, 0x5D7FABE652929666ULL, 
            0xD3EB8EF034DF3AC7ULL, 0x0D0FC4710BA13D57ULL, 0x9208ADB803FD38D9ULL, 0xFB2A861C87D186E7ULL
        },
        {
            0x73AD3C329A86DD28ULL, 0xC2279ADAD1227F7CULL, 0xFDDD22F96EAF6AF7ULL, 0x935E45725F45A059ULL, 
            0x13E87C65941DEFB4ULL, 0x56E1D72620C00122ULL, 0xDB071A53A0ED30E9ULL, 0x242074E78D6F058AULL, 
            0x3957F3821F8FDF44ULL, 0xA0CA6B855D01821EULL, 0xC09798B7D3F93149ULL, 0x6734A13062EE9E73ULL, 
            0x86FD132E333EA48AULL, 0xC13A7ABDA0BD04D5ULL, 0x78FA6D6141BBCA27ULL, 0x3C82F96FA876FE69ULL, 
            0xEE05B67A91992A65ULL, 0x07CB4E90F353167BULL, 0xA86800BF7B89B44DULL, 0xFBAC90DF9BB285DAULL, 
            0x79DBEFA2BCF7FFC4ULL, 0x71C3EE01BE354273ULL, 0x934CA7C5EEA5AEA2ULL, 0xAC568E1EE9081EC4ULL, 
            0x6EC41BEFDFDAB87FULL, 0xC2C39B81ABEC7270ULL, 0xE01532DAA93F6378ULL, 0xDA5FFCF1A105F315ULL, 
            0x1301BF5B53E59F4BULL, 0x8CC4D3D6B34F357AULL, 0xA6C956C0958B63F8ULL, 0xAD5A97AF44E21E9FULL
        }
    },
    {
        {
            0x9904AB4AE4EB0D34ULL, 0xC10A7A7B4D0E9210ULL, 0xC0EF0BEB9DF189F3ULL, 0xDA7794AC303F020EULL, 
            0xE5150E2CDD9AA789ULL, 0x2A71A204C1F51A88ULL, 0xD3D9CF4DCA75FAA0ULL, 0xF61975D13C561A6FULL, 
            0x078BB0A0C5F0D4E9ULL, 0xA20AAC6C1C7C7AA0ULL, 0x3C21331EA41F7858ULL, 0x78F89430D895A21EULL, 
            0xD9EAD0E3FF41E5BBULL, 0xEC18B9C9C0BCE62DULL, 0xA902EC398D0EF057ULL, 0x1E77A9E42F43FE29ULL, 
            0x2DF565A3BC1D06F2ULL, 0xDD8D3F49D20E3108ULL, 0x50C2CC8391604789ULL, 0x5987CD8BA1F1B243ULL, 
            0xB3BA3E1B737886DAULL, 0x6543D7AC682144FEULL, 0x000C1B945093C6D5ULL, 0x61CDEF0969A9667DULL, 
            0x1FE26A6417DFE5F6ULL, 0x128685DC750E59F0ULL, 0x5E00F2B51142677CULL, 0xA1FD311BE1E026D8ULL, 
            0x694B2114B9AD39F8ULL, 0x07BD0319FB1BB32CULL, 0xC7D1C4353F33088DULL, 0xB461CB28B6218727ULL
        },
        {
            0x8AA238C820BDB622ULL, 0xB2221333A817C8DDULL, 0x25D1CA5E7A6AB705ULL, 0x5C59836760CC5BFCULL, 
            0x70D2F474F43F555AULL, 0xBFE2529AFED08DF6ULL, 0xB40FF1562E720F2DULL, 0xF5B88DC29E5BFD86ULL, 
            0x5AC658D96143E29CULL, 0xE8BC500EBB45E9C3ULL, 0x8605C772BED28880ULL, 0x0618482B73DEB24FULL, 
            0x0A136D838F44B39BULL, 0x1F82382A4BF38BF9ULL, 0xE21FCFA61AAC043FULL, 0x29743678D1748247ULL, 
            0xD93AE0B02E81440CULL, 0xE5D098A11CC3B610ULL, 0x882112807506F41DULL, 0x4294DE5792BB97A5ULL, 
            0xE7CF2FBC5CE69044ULL, 0x30505A06D02268D9ULL, 0x569B9619A6CF3A3DULL, 0x788DC9D49341400FULL, 
            0x365DF34CE9E47DF3ULL, 0x00980DFD450789CCULL, 0xC91A8C5C705EEB34ULL, 0x878436CC97725C3FULL, 
            0x7FDFF339CD975C8FULL, 0x3D8FFECC95AF14E9ULL, 0x2E52A1E6C8A90BC4ULL, 0xF0E8E55D57D72175ULL
        },
        {
            0x51538CEB6FA415EDULL, 0xDF029BDB891A3FDAULL, 0x5DE51389DBB6FC44ULL, 0x0103001E1AB60D83ULL, 
            0x85F94F2412E02600ULL, 0xA81C88C0F561353DULL, 0x6643E2F871DC3040ULL, 0xBD305E84D4AAE277ULL, 
            0x705EFADA8F6ACED1ULL, 0xC7501B2CF90556D3ULL, 0x1FA30C58D8394363ULL, 0xFF6B1B50FEF59AEDULL, 
            0x164CB80F145E4784ULL, 0x76CED59741DB9172ULL, 0x72F6ECE65B7F22DDULL, 0x1A1413AE4151A3FCULL, 
            0x8AD718AEB359DAE0ULL, 0x8D4CF36967940C6FULL, 0x6D4299B7BFFC2D68ULL, 0xDDD7998DA6C7480DULL, 
            0xB068C2374094200DULL, 0x38CB2F46F94EA93FULL, 0x8BEBBEFF5439AF1FULL, 0x354F74C1BF23E19FULL, 
            0xDC60B115B07A0E04ULL, 0x428D3C95EA0C3DFAULL, 0xD4EA94405E723C3FULL, 0xAC2B522D2877C427ULL, 
            0x27E890F0826FA599ULL, 0x96D9B7A38A88C36CULL, 0x8270D99D26038C9DULL, 0x4F0562DB48F1F277ULL
        },
        {
            0xA5CD9CAE12519CBAULL, 0xFF3396734BB8B28EULL, 0x632F9A7FECA79F2AULL, 0x0E48C2E049171591ULL, 
            0x39DDDD16555A670DULL, 0x0C56225D61E77891ULL, 0xECD0DEE5967E9C96ULL, 0x1A7786ED7706C8F5ULL, 
            0x2B508F375C2A3182ULL, 0x3448F9D28C6EE0AFULL, 0xB95DDD5006656BAFULL, 0xCF3C35F70F7501F3ULL, 
            0xB859A8ABD2F6ACA3ULL, 0x4779D2906F0ED106ULL, 0x0ADDF3FDAE49B3CFULL, 0x5D85C493A2CBDC68ULL, 
            0x8B310E6A03DA9DE0ULL, 0xEF22D1EC6F720D0DULL, 0x4EF0E2E6B965A431ULL, 0x0D8EFF92C431794AULL, 
            0x20BB021137098F16ULL, 0x6C8544A42FD0DB28ULL, 0x97ACE964B61C29F6ULL, 0xBF1F204D62A2B395ULL, 
            0x209742FD687E3A4BULL, 0x9C78FA5E4311DE92ULL, 0x8FF0BD1A492E3C0BULL, 0xB07F4D1678412B6DULL, 
            0x1501030F91DB41FFULL, 0xC59E8E1C462BFB17ULL, 0xF40A710ECC2DD0FFULL, 0x2AA9C44AFF707710ULL
        },
        {
            0x3420F84D4031148CULL, 0xE2592B6568E8038CULL, 0x7B1DBCE6B2B91B41ULL, 0xED574FC6B99D9584ULL, 
            0x8BD4004BBC51D897ULL, 0x2D786328C41B423FULL, 0x6AD8976AF309A246ULL, 0x159A03C122A449FFULL, 
            0x815BDFC4F05051DFULL, 0xB1B7E798E33B4507ULL, 0xAFECC1D4EC3521E4ULL, 0x598D7B9169AC0586ULL, 
            0x2FA6EC8C8DE572FEULL, 0x7D15078D01967C33ULL, 0xF97813DFD197B4ACULL, 0x57D93EF8D6CA342FULL, 
            0x7D6AE86C9EC5D818ULL, 0x040FBC5AF64DF3DFULL, 0xB6C3FA993C03F9F1ULL, 0xF3D4A4D8B4437716ULL, 
            0x7A83F498BA6E2D2EULL, 0x9B6AB62013A720DEULL, 0xB9141ED0D0B9B801ULL, 0xEBDE13325031B189ULL, 
            0x78800E1CBE4F110EULL, 0xAC593A0ECDC6DBC4ULL, 0x9022E096A5EB4C0DULL, 0x2611961D4491E6A7ULL, 
            0x2FB84DCDFF754FC4ULL, 0xB0A70ED1D9598FC5ULL, 0x96FBC510BBA4CFC9ULL, 0xC70961A311DD4BC7ULL
        },
        {
            0x514B2ED5C7DA7AD9ULL, 0x1D7F12389A6306A9ULL, 0xA80F4C972B1F18F1ULL, 0xC7B1D96F2212EAA7ULL, 
            0xA03B4959ADC3AF0FULL, 0xB20CFDF617789BEDULL, 0x88AACA61B56B7037ULL, 0x224842ED06F9765AULL, 
            0xF3D665E33C8BB02FULL, 0x4CA2C8352D70E25BULL, 0x7576A657495EAD0BULL, 0xEDA2CA688F3C9ACAULL, 
            0xEDA3D8BCFC873E03ULL, 0x98C985C501EDF2A0ULL, 0xE61203D1AAA95077ULL, 0x104E84BADFCBAE29ULL, 
            0x206B1BC0616B74B3ULL, 0x62F6BF2A3CF66AB7ULL, 0x01C171691537194FULL, 0xC01327C8BD20F100ULL, 
            0xBB48695398631108ULL, 0x61F2B5BE9E3B3FDFULL, 0xBA6410505F155F88ULL, 0x17EFE22F3962B957ULL, 
            0x57F10982F7953D85ULL, 0x81ADD89BC48E1EF7ULL, 0x15667840A7708FEEULL, 0x1BFAF0DF9FB17897ULL, 
            0x88BC73CB8E2A158CULL, 0x193B13B938CFF302ULL, 0x436BCD1ADF16A74AULL, 0x43EB0428FB354E78ULL
        }
    },
    {
        {
            0x4FB3D9BFB8949256ULL, 0x878998B35D84CC64ULL, 0x92F0F7B627A5F54AULL, 0xDE3542E3A1DCD52CULL, 
            0x54ED58F254BF1DBBULL, 0x08DCD33E8C98C475ULL, 0x1F7E18714C36E0DEULL, 0xB6F3CCBCECCCC421ULL, 
            0x958AB73EF818AD66ULL, 0x7889DC3E86F725E0ULL, 0x8CB90FB4A75E7E2FULL, 0x613D0094F26BC425ULL, 
            0xB63C4EE856093002ULL, 0x61E2374DD9A2B5E8ULL, 0x7191A32E3AD7DB13ULL, 0xFE863845EE684C5CULL, 
            0x54E0F7FD9D48FD5CULL, 0x09E85C92666F9CE8ULL, 0x36F9F48BC7FE957DULL, 0x2DAB34E3F70F2741ULL, 
            0xFAC5F01C41F374C4ULL, 0x9A64B9F322CC8009ULL, 0x3F4FC9FE98F0729AULL, 0x28D54C1AECE0A182ULL, 
            0x1ED2A05B6DD83E50ULL, 0xF2EC50988EE61288ULL, 0xE80EAD097CADBC61ULL, 0xA77D18E24560C801ULL, 
            0x1319C6ACF4BE8788ULL, 0x49428DEDC07EE886ULL, 0x58884D3570C54651ULL, 0x5C956C0A24617BBFULL
        },
        {
            0xC1F9D0088BA0FB8DULL, 0xF801CF0C6889A8B2ULL, 0xD8416E0E9A21411BULL, 0xFD64428D0D063C41ULL, 
            0xAC707C15959B5805ULL, 0x10DB44A26183A55BULL, 0xB301DDCE866398A7ULL, 0x61CB2E6DC0E7512BULL, 
            0x6518B0DC827D5498ULL, 0xE5E93F3B04F26270ULL, 0x61CB28FEF84719C4ULL, 0xC405F9F586B9CDC9ULL, 
            0xCB5F0A44AD0956D2ULL, 0xFAF3B88B85B7E1CBULL, 0xEC6FD66146739586ULL, 0xE90FCC6C29E5073CULL, 
            0xFC20E64BE035D841ULL, 0x6170EF5D02A28640ULL, 0x9149239EC7768FCAULL, 0x59D2E1C380358C47ULL, 
            0x151031CAFD14C7E4ULL, 0x1B78025721470806ULL, 0x7FFCE286DA3DF565ULL, 0x1D9BA783D0CD8C12ULL, 
            0xB2283A124AAD9B15ULL, 0xB60AEA26FBFB608AULL, 0xF62CC1112D731C8AULL, 0x428E39D216C65318ULL, 
            0x65FA797D8E319E08ULL, 0x7441B8F4998B02C8ULL, 0x72443BE15E1A2771ULL, 0x90E72FE9BEE5330FULL
        },
        {
            0xD07549E582001E95ULL, 0xC50F31066F90D4A0ULL, 0xE695ABB9348C4A8BULL, 0x34640268FB8052E4ULL, 
            0x735EBCFAB88BABDDULL, 0xE94F0EAC34AEBC34ULL, 0x91D56E0E3EB5DF97ULL, 0x3A5A7C37105C42B0ULL, 
            0xC2E9B8980609CB6FULL, 0x539ADDF3B38494D8ULL, 0x278358878411D5ACULL, 0x48B7CD4351FD545DULL, 
            0xA24B0D83145081EEULL, 0x42589B99F2E9CC98ULL, 0x2E97C666F751D214ULL, 0x24F3B2169CDE03B4ULL, 
            0xD869054E0B562458ULL, 0x07AA10753D0D0478ULL, 0xCC11FF1EAACAA8BBULL, 0xE0EDC399FDF639E7ULL, 
            0xEEB602D77AF2DCABULL, 0x243E32C6F3669CACULL, 0xE3E69DF690B91E79ULL, 0xF4A426378E82B5F6ULL, 
            0xB46E463FEE903882ULL, 0x247841F0BC6A2879ULL, 0x31D29A6394A390B9ULL, 0xD1636E044D3A6706ULL, 
            0x0DCFBBEC367F7DE8ULL, 0xF6272DAFB26F7EB9ULL, 0x897580551F40FA06ULL, 0x01A7377FDE87A406ULL
        },
        {
            0xB78EE2ED32ED073EULL, 0xAA4CE280E4FD2354ULL, 0x7519CCA42CC1D795ULL, 0x5F486CCA6769F242ULL, 
            0xBEB4AFA539BD86A0ULL, 0xF809AAE5CD50FAFEULL, 0xE928F974A078455DULL, 0xDC794AD678B9291CULL, 
            0x53293817FDF413E9ULL, 0x59820C77AEC519C2ULL, 0xAD24CB6CC74826EAULL, 0x5F2932C318D2EFA8ULL, 
            0xB37DE65419AE8762ULL, 0x22C71173169228FFULL, 0xEA3EBF3378DFC586ULL, 0xD376F7FF973AA55FULL, 
            0x5E6B3C3F078DA538ULL, 0x2DA239769012D51BULL, 0x7F8320F1234221ABULL, 0x800D48E866364CA4ULL, 
            0x8769BF40D73190C1ULL, 0x03D92F3057F59927ULL, 0x1CB9E77EEC016E06ULL, 0x9D2CC56838A996F5ULL, 
            0x6C467A2E63C8E292ULL, 0xE112AC28CD9E7C21ULL, 0x24E6AD515C5F5452ULL, 0xE3B63DB954D2BC5FULL, 
            0x4E803EBD71E914E5ULL, 0x9F321EA3F45BEF09ULL, 0x84A5D70830964C9DULL, 0x70205E07B0403235ULL
        },
        {
            0xB14900B3384A68D6ULL, 0xD30B0BA6764182DAULL, 0x66D6D50A93B3BB39ULL, 0x08D4FE44302D1C9CULL, 
            0xF7357FAD83C665BFULL, 0xBA3A586DC77B6FD7ULL, 0x37C402F4CF0605C2ULL, 0x733B7C78124C88B0ULL, 
            0xB20CFF27F20EBA22ULL, 0x6ED33A0CCB343399ULL, 0x4AE6DF96A3BF6BE7ULL, 0x4218F64F519A8283ULL, 
            0xFA416F98921F4826ULL, 0xC9A9EFCFFEDDCFD7ULL, 0x6417F7567C58445BULL, 0x39096E6C70F12DF8ULL, 
            0x283E4901309DD588ULL, 0xBF9FC3865F4C957CULL, 0x8E3404E83BBF9E11ULL, 0x2F3A2A25C7F8347EULL, 
            0x2C89E79BC809C754ULL, 0x1EAC994396165B1FULL, 0xDDE7A858C2EBFA83ULL, 0x20BFFA47C747595BULL, 
            0x860C3CDE3644128FULL, 0x265D74AC770B8BEDULL, 0x456B38E3E31262BBULL, 0x80B5433F04969659ULL, 
            0x0505BEECE9C70237ULL, 0x0C2ED9974EE7649FULL, 0x898BA4EFAF2FA1E3ULL, 0x7BB5E8EB0BA93B9BULL
        },
        {
            0x6318CCFD2905E010ULL, 0x9A5BAF84893F6FEDULL, 0x556AC21888E247F9ULL, 0x1D5403EF48CEA14FULL, 
            0x41E120132C0BE1BDULL, 0x549BEF0C8179B69DULL, 0xB7066C2978EA9B45ULL, 0x91143248B3E6749AULL, 
            0x398ECF9D8788BFD9ULL, 0x92308EEA73282310ULL, 0xB4C2907187E52959ULL, 0x1743B3F900BE5109ULL, 
            0x7DFF498A4F55F4B0ULL, 0xAD77D43E8BB0ED30ULL, 0x5B3B8D437A3D959FULL, 0x7269D5E93603EEF9ULL, 
            0xF3E1B64AD398983EULL, 0x49F30D8EC6021D74ULL, 0x0EF230F6EBFF3536ULL, 0x460445B2D166C7DAULL, 
            0x439E463465F4CEACULL, 0xF58F3D0FDF477624ULL, 0x435450404850FAB5ULL, 0x6F3A4A571499C0E0ULL, 
            0x004D2E9858472BA7ULL, 0x93CC7EEB2B1322E1ULL, 0x2C4CF63E2D69A701ULL, 0x2580D6195E77ED72ULL, 
            0x7C3A69455F6EA411ULL, 0x8A5C31625A3F1AD7ULL, 0xF286AEAC46693C52ULL, 0x7033A3C72BD612ACULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseFConstants = {
    0x4E8A486E2F90FC82ULL,
    0xA83C2239DB20B3C5ULL,
    0x2AB80F720171828EULL,
    0x4E8A486E2F90FC82ULL,
    0xA83C2239DB20B3C5ULL,
    0x2AB80F720171828EULL,
    0xF0B3A683DACD71E2ULL,
    0x1B5EE4973DE57120ULL,
    0x2A,
    0x82,
    0xCA,
    0x09,
    0x17,
    0x76,
    0xFF,
    0x03
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseGSalts = {
    {
        {
            0xCE58E8A91890C88BULL, 0x2404B049DDCC220CULL, 0xF0DBA7767200DEB0ULL, 0xE026702CC203B035ULL, 
            0xE09C9B84FCC3F7DFULL, 0xC9BFD72ABDA8CE4FULL, 0xD388CF0AC6659DF5ULL, 0x313FC6BDEDAB6DF8ULL, 
            0x617A02497831D6ECULL, 0xD7BEB8E8699DF175ULL, 0xADE2590450683FF4ULL, 0xF4D8B3E5C68B8C68ULL, 
            0xBE7404AEC973AEF8ULL, 0x1F850C41006058FFULL, 0x75CF1F5F095E6415ULL, 0xF9406F71053F35F0ULL, 
            0xA7B039D125415019ULL, 0xA1B478AB170C892DULL, 0x8F32765310DD37D1ULL, 0x43CF1949AB3B8994ULL, 
            0x3AE71723CB592718ULL, 0xE89B0176FF274A25ULL, 0x3F1B0CC7CD609252ULL, 0x82B38DFB64849C4DULL, 
            0x6D509EA403BDD3A8ULL, 0x21ECD49E95FBCC13ULL, 0xB60AE7659BF82A41ULL, 0x461863F45A300F8BULL, 
            0x416AB25591DDBAEEULL, 0x0D9101798EB00CEDULL, 0x173C9FE4B3AB21B4ULL, 0xE723FC3764BEDBABULL
        },
        {
            0x4CC2E8C2C7BFA42AULL, 0x0869C09AB5D1B5EFULL, 0xC0E582821A14BE76ULL, 0x12631CB6634CBE0AULL, 
            0xC31013E7CE051369ULL, 0xBBA46F7C7A30FE54ULL, 0x0F7CC6698AFCA542ULL, 0xAF96C23047A8BDD5ULL, 
            0x59078C67ECCF26CEULL, 0xA64126C3DA6BD973ULL, 0x5F9B72714FCF0D00ULL, 0x5882AB814488C893ULL, 
            0x998E8C6AB70B615DULL, 0x15A73D7BD0A3D164ULL, 0xB50C0CF48E9975F4ULL, 0xD90D516E3BD97E9EULL, 
            0x78C04DD93BEF9616ULL, 0xD9626E761079284AULL, 0xF4AEBA0841729ED2ULL, 0xAD455B8E38392A12ULL, 
            0x2576EF8C3B0AC35CULL, 0x67A1B191058BF54FULL, 0xC67A6C237DF22B5DULL, 0x4E2EEC1BC5B59A3DULL, 
            0xC19B6DB867F89567ULL, 0xFEFE7EF7750CE1FAULL, 0xA3322EA28A7EC755ULL, 0xE3AD04F0E15E4E3CULL, 
            0x86575462D656DA40ULL, 0xE4E4CAEA1E0B456AULL, 0x847189B6FC8DA042ULL, 0x3A27AC6BCB649DB8ULL
        },
        {
            0x8BCE25FB4239E991ULL, 0xD236A1AE68423831ULL, 0xC335A8CA6D45F73BULL, 0x4C9CBF9725C9FAFBULL, 
            0x379767E16D89D3EBULL, 0xEF473D20E2FD96F7ULL, 0x424C8B62751DA1C3ULL, 0xFE2C41615D67388DULL, 
            0x3BD75BAEECB3F7FFULL, 0x9CF3B113E00EBD94ULL, 0x690D20625CD8C327ULL, 0xB7A09B159FE813C3ULL, 
            0xDDC1E190DAF9B9E8ULL, 0xFFA6D757885C1C00ULL, 0xA65E2AE33ABE5C00ULL, 0xF273974EAF25B5A4ULL, 
            0x04A2AB18C4910DA7ULL, 0x9811F483DA8FA656ULL, 0xCC18A56F9718720EULL, 0x98D8B56B93FE9CF9ULL, 
            0x837D78440DD25BAAULL, 0xE40D2351A54275A2ULL, 0x888503C94AD3AA6DULL, 0xA3C33DCB3A8661C8ULL, 
            0x1F932B746A4B35F4ULL, 0x4F4EEFFE3CB0C37FULL, 0x44698ECD82BF7A78ULL, 0x2BB30D249055A75BULL, 
            0x1E1C0D2228E4A0EEULL, 0x9617962703FBD8B5ULL, 0xBF0ED757095771FDULL, 0x9408C2E1DB65C5F3ULL
        },
        {
            0xFB1ED692875CDFC4ULL, 0x22A10942A42DCA43ULL, 0x27916266F33A1183ULL, 0x7C1724F9B59DDCFDULL, 
            0xB4E7A8673D0CC696ULL, 0x1F4592D71C039B77ULL, 0xCDFBCEEEFF56E2E6ULL, 0x5517550F9C625B69ULL, 
            0x29BE030B89E8BFBAULL, 0x6770B6BAF97F375EULL, 0x62A5A6E39355EB41ULL, 0xBDE9F5DD80982CB1ULL, 
            0xEA4DAAED9ED52242ULL, 0x289FA408B20F44B2ULL, 0xBDEE1BBCD9734207ULL, 0xC8C4F994F5E37208ULL, 
            0x82E4B088776E2FEEULL, 0xD84CC3287617746CULL, 0x4306574DEA63A481ULL, 0x54D8ED56F64AC670ULL, 
            0x75554DF4AC06CF5CULL, 0xA63DDE7A63B05F66ULL, 0x2273F6E2EEB639DAULL, 0xCE648589F3EBA5D6ULL, 
            0x211EF1B915EAD907ULL, 0xE7815595661994B4ULL, 0xF16E0903ABB77254ULL, 0x378087F973CCA69CULL, 
            0xEDB87EC17DFE7F47ULL, 0x63517569D9435D83ULL, 0xD7769C9E03623BEFULL, 0xA81346ACFE25CE50ULL
        },
        {
            0x0CFCC24C588897B2ULL, 0xAA27F000555846B0ULL, 0x36B42C1239E72B5DULL, 0x2A05B4D71422DA60ULL, 
            0x012F238C35BF53DEULL, 0xE7F94287F1582573ULL, 0x350B6B1AE071A093ULL, 0xACBBEF53C0730A75ULL, 
            0x045BE87A40633AD3ULL, 0x434D9D299BD85323ULL, 0x81B689AF4F60488BULL, 0xD7B1CFD21CD6F7DFULL, 
            0x8416F297C59B39F3ULL, 0xE0F77ACD95349E58ULL, 0x6AE1F06738C9ABA1ULL, 0x51625B804EA0A69AULL, 
            0x176288038F9E0B96ULL, 0x0A295ADDF6DD2E4DULL, 0xAAD614E2ADE476A8ULL, 0xEA2D4525E9555E30ULL, 
            0x54FF2EB513753DE4ULL, 0x884EA5E56921DBBDULL, 0xF41422AA723FD8B3ULL, 0x2C08B79C8D00F38AULL, 
            0xBA30639FB278D737ULL, 0x18D67F226E39A4DFULL, 0x31CA36CAA94E0D76ULL, 0x33E65AFA4B16BE35ULL, 
            0xA8DB4AB71FCC2244ULL, 0x7706CB1BCC79C0C4ULL, 0x752BBAED6DA19380ULL, 0xC1C8759E4B548544ULL
        },
        {
            0xED84F2603874438CULL, 0x49354C121B27DEEFULL, 0xA2E45AAD025E9BB9ULL, 0xB313DB54993C94EBULL, 
            0xBDC0C4A0DBB1860FULL, 0x318FDF507AD01C0BULL, 0x546F922A4294DF79ULL, 0x1D59B0DFB06A2FB2ULL, 
            0xA9C7823BF5877D88ULL, 0x707C938FD3E4F126ULL, 0xEDCC1D3BCA7B03FBULL, 0xD8BF6195C413771DULL, 
            0xC95C187E63B91A4DULL, 0xC24ED641E76929D3ULL, 0x43F237D081460557ULL, 0xBD7868962CE08645ULL, 
            0x21EA075E3314A6DAULL, 0x669A301C219C6F66ULL, 0xF96A090DEFE68BA0ULL, 0x6B5197328244D95BULL, 
            0xB593A83598B70CC8ULL, 0x1834D5F22DD8391BULL, 0x32DCDF715E203C0BULL, 0xC8CF0DD50369F183ULL, 
            0xE4FE1FCBD1C39086ULL, 0x2D8BDF9820CC0979ULL, 0xA16A3A5E39A4F888ULL, 0x2B93259BF5C249C1ULL, 
            0x38C9E104E2DA6A0BULL, 0x4B6863C1E4B4AFA7ULL, 0x8168E57320C9F08FULL, 0x9099807983219111ULL
        }
    },
    {
        {
            0xCFD0EA42C48EB964ULL, 0xFEF9B25253B030C0ULL, 0x12AD9ED55872A86BULL, 0x8F82BBA8DFAAAE9FULL, 
            0x1F870656104EE381ULL, 0x898276840A0653E1ULL, 0xC9757EF942C7B8FBULL, 0xBFBD48B96D3A73F4ULL, 
            0x53D4D4DFEAF50DEAULL, 0xE8A57A4A1B3920BBULL, 0x4D4E96B1D5E28C34ULL, 0x740CE00B991B98D9ULL, 
            0xC4C0FAFC2BB31DF1ULL, 0xA2A86821052EEE9DULL, 0x12A8767F0D7AD159ULL, 0x41F8FB1739DB4A5CULL, 
            0x7ADE710AFFD66494ULL, 0x8B02B1AA949FA30AULL, 0x036D614A907D647EULL, 0xB70CCAD1301448ECULL, 
            0x624038A40BBC35D8ULL, 0x8055D9E2C5979E7FULL, 0xE4646448A2FA6AB1ULL, 0x0F5BFF654D9E0B81ULL, 
            0x853C1B7A90995576ULL, 0x7A9830A863260CE0ULL, 0x30ECF79C2EABEA88ULL, 0x188B26F851C897EDULL, 
            0x79DA765F73E64943ULL, 0x75B138162452C4E4ULL, 0x96AC22E75595841EULL, 0x9D5B59BC3AC8EF86ULL
        },
        {
            0x397749EFCEAB4DFDULL, 0x2C88558D00EC7649ULL, 0x4E6B5D8C8559CA30ULL, 0xEDEBC64474D53463ULL, 
            0x9BB30B082749B380ULL, 0x013B1762BBDFE58BULL, 0x8AE044916AF086B1ULL, 0xFBD6101D8509E17AULL, 
            0x4696D32B2C0CBA54ULL, 0x2E8D7C73CEEE388EULL, 0x7A41A94F6700C9ABULL, 0xDC60EA67221D01E6ULL, 
            0xCD6AB19DDB025872ULL, 0x836318FA9A9F2BCFULL, 0x6F50DB556A454442ULL, 0x553820244D0FF199ULL, 
            0xDA1BB37636D18C44ULL, 0x6230644CB3245E2CULL, 0x99CD7096D833A27BULL, 0x5719857150022FE2ULL, 
            0x3C3C6DCCCD66F331ULL, 0x23C8919FAD1C559CULL, 0x22228CD1A4AAEFAEULL, 0x875C94C372A1F660ULL, 
            0xEC9D8B7A36F92313ULL, 0xEC7B492708A15794ULL, 0xF51DF1D287933238ULL, 0x3309665B106A820EULL, 
            0x765D8253594A3945ULL, 0x80BF632D58750206ULL, 0x8FE3A4240943C8A7ULL, 0x086682454CDD3525ULL
        },
        {
            0xD95AB8F9E6BA6533ULL, 0x5D11373728C6E111ULL, 0x51C8BDACC10B100EULL, 0x1BB619422952C98AULL, 
            0xC3ED0AE7F9E0A72BULL, 0x3CF4911987B30D99ULL, 0xCCF329C87FD28094ULL, 0x20F1E887AEB4ED12ULL, 
            0x276171B80080E489ULL, 0x14F4B47AF44123A6ULL, 0xD13B5F0CBCCF11AFULL, 0xED32409EE3D477E6ULL, 
            0xE289462D40725F6BULL, 0x6BB1E8995BB4704AULL, 0x4DD994C8B3380AD8ULL, 0x388B29B15423B932ULL, 
            0x3A178E6DB4F95269ULL, 0x9E78284B843E61CDULL, 0x7767D12ADA4852DEULL, 0x286B2E212F52A01DULL, 
            0x614160630D395CAAULL, 0xB4C880C8E834E17DULL, 0x23E4058FF973F3D7ULL, 0x16A1EA9147FC87BEULL, 
            0x4BCAF550C8CF2B9DULL, 0xE85B00F8B9714970ULL, 0x305614609604EE9FULL, 0x69A502151D71A41DULL, 
            0x77932385A6788A7DULL, 0x521B84CE5ED59BBFULL, 0x8D5617E6DBEB3D85ULL, 0xC85D6A09B48C648CULL
        },
        {
            0x06241E15C6EE7A4BULL, 0xDD674E052231DF0DULL, 0xE4FC335A543FC699ULL, 0x0A432741942386CBULL, 
            0x5F37FD617992EBDEULL, 0x8ECFFFBE47643827ULL, 0xA16A8129ECA2ACAAULL, 0x4E2B0946D3BBA455ULL, 
            0xB6805ABEBEE6E472ULL, 0xB936DED192642608ULL, 0xD3301D3BBA51C63CULL, 0x8FB596E5513E1791ULL, 
            0x923B4D30151C0444ULL, 0x37FA4829CFC9EB63ULL, 0xB1DDF0B01A6189ACULL, 0x1EF5BF196BEECB06ULL, 
            0x51E60C5DE2E82D4FULL, 0x449374E139CF141EULL, 0xFE7B1323EDA60251ULL, 0x8152DB842F4BDD26ULL, 
            0x3307A706C356E773ULL, 0x4BE386FC7E69CE09ULL, 0x67F9A7ED7562CEABULL, 0x5DBF9C749FA2AE1DULL, 
            0x9E3F882DF065479EULL, 0x5022B7417B3F8ED0ULL, 0x8AB5AEDDACED02E3ULL, 0x43E0BD0A2BB7C454ULL, 
            0x1E4D0218E71492E7ULL, 0xC8507FF384F86F82ULL, 0xB90617FD846E2F03ULL, 0xDFED54029F2BD5A2ULL
        },
        {
            0xFD34D3F18FE40EFAULL, 0xA8C9B3C33C480B0FULL, 0x941344BD82BFD1EEULL, 0x30BA1BAAC60A0775ULL, 
            0xC78EA30C8A2268FAULL, 0x64A5ED0796324027ULL, 0x789E01F77DE6B8C3ULL, 0x11F266B4C78D1737ULL, 
            0xD13454B8420B30FEULL, 0x71D360BD30F7D1B4ULL, 0xD271529DC604BD8FULL, 0x16B71BEA9D356B04ULL, 
            0x9AD608BCD08F889DULL, 0x0AFB46E249C61A43ULL, 0x2FE5C220CC168D49ULL, 0x1A8D110C221DED1DULL, 
            0x35FE37EE6B8232FBULL, 0x21A2B2B178456BD6ULL, 0x46C4FAFB63016D64ULL, 0xCA598C459DBE72DBULL, 
            0x8B7B64C3AA3C9255ULL, 0xEC314F619902B09DULL, 0x5BF7B857C456C184ULL, 0x2CFAC31641F79EDBULL, 
            0xFA93444FAB5379C2ULL, 0x8640E4A67AC1E66BULL, 0x913E6C326AB292C0ULL, 0x7DD4DC73C53701C2ULL, 
            0x78A674272DE52424ULL, 0xD1C437E9C2DE1E56ULL, 0xF51C57497BFD2987ULL, 0xD6ABB359ECB756E1ULL
        },
        {
            0x279683CDE5F14AE2ULL, 0x97A30550C7C1586CULL, 0x4EAC7E04140F36A8ULL, 0x658184F93F6A1CF6ULL, 
            0xE691830E63813719ULL, 0x1D353F7A2F409484ULL, 0xA13786EAA6FC6400ULL, 0x109291C699A7C0B8ULL, 
            0x97829595A371EDECULL, 0x4806DD535AE058B0ULL, 0xF006CC7BC9327FC8ULL, 0x3073A32F882CBDE3ULL, 
            0xC01AD3EA4782F01FULL, 0x7BBE89DDA0B940E8ULL, 0xA35CC19A3A4BAAFAULL, 0xA16695D433D4D0A7ULL, 
            0x91962CDEF5BD9643ULL, 0xC99458BC35BA6EC4ULL, 0x4ECAE6C2D4D2AC7EULL, 0x8CE02CC1E10680D2ULL, 
            0x168510B6570B053AULL, 0x338C01F36B8DE5E2ULL, 0x3789C3549901CF85ULL, 0xC27C2405393C5354ULL, 
            0x22B2B05AC0C5BB86ULL, 0xDD95184670BD0815ULL, 0x7BE8A19068040FEAULL, 0xAC329E9CD3D018EDULL, 
            0x5003343CA873727BULL, 0x4946E0A12E094C91ULL, 0xB59C5F421FF61774ULL, 0x003653464191BB98ULL
        }
    },
    {
        {
            0x55B9319CB248E052ULL, 0xADED8FE283450BF4ULL, 0xDCB2D5DCC345B153ULL, 0x2AA1564E4193E2DEULL, 
            0x9C0305F57CCB8B1EULL, 0x031DB37064E99728ULL, 0xA01C6F7D93B3BF6CULL, 0x5BFF96FF76EE6D95ULL, 
            0x3B844F6E425265DFULL, 0x43500EC948190ED2ULL, 0x4FBB1D4AA2FFD7F9ULL, 0xAF0BF593DBC36129ULL, 
            0x69A3B08E51C893CAULL, 0x0F052F97811E6D13ULL, 0xA3A54389723CA0E2ULL, 0xB32D5FE96AF021BCULL, 
            0xE63983AB412A71FBULL, 0x4EBD4FF30959EE3FULL, 0x1FBED3306CFB6ADAULL, 0xD34586BD5145F371ULL, 
            0xDE484E3CE54E4B49ULL, 0x00E2BE9D22F0348FULL, 0x5D293A97E36ED18FULL, 0xCEA2051E1FE75170ULL, 
            0xD88883E7552886CCULL, 0xFDE1125316CBC99BULL, 0x72C55BC560A2F698ULL, 0xC57C3D30FF3A15D1ULL, 
            0xA4903CA01C5EE4BCULL, 0x4322361290A8DDBDULL, 0x76C636E23094A0C1ULL, 0xBCC1853F0BBB1AE7ULL
        },
        {
            0xC2AE96EB29233D66ULL, 0x2D90A18A6532EB6AULL, 0x5184A011D9DD9846ULL, 0xF286CD495A867C98ULL, 
            0x49575C99586810F4ULL, 0x84C6D621AAC49FCFULL, 0xF540083189A163B0ULL, 0xD95FAD85F4896112ULL, 
            0x88BA2E8EF71BE37BULL, 0xF289773BFFD818C9ULL, 0x924EF6D861FE39C1ULL, 0x94BC595072E84236ULL, 
            0xEFCDAD42E3E6ECB6ULL, 0x8059197BF1CDDFC7ULL, 0x20E74BE7ADAAF121ULL, 0x88DEF9F61DBA1661ULL, 
            0x5611812A97544D86ULL, 0x4018C7C2F2809E8AULL, 0x7083EB9994796E47ULL, 0x37DA35192EEB150AULL, 
            0xBB433A44CFDCC9B2ULL, 0x74BA84A60CF6AEFAULL, 0xD6D4CABDD6E9B01DULL, 0xBBFE075975700C34ULL, 
            0x40C3315EFD2C1098ULL, 0xF4C30A9BB94C96CFULL, 0x4C5DCDC79092FF74ULL, 0x6BF81084614AD669ULL, 
            0xF401731BB11C25BFULL, 0xDD803CB75603DB1EULL, 0x7312EEBC60300740ULL, 0xBE2B66D0A60635B6ULL
        },
        {
            0xC642A23D263EAFD6ULL, 0x3BDD11821D4D019CULL, 0x980870B88745C267ULL, 0xF8124D489261768CULL, 
            0x141AB819A1AE9B8DULL, 0x1AE97BA1E40E192EULL, 0x9C1353C469DDC522ULL, 0x1830540478B35C4CULL, 
            0x2DE29BC20470A007ULL, 0x83360FC7E98015B8ULL, 0x7216A11511D227ADULL, 0x02E15A2FD3964C64ULL, 
            0xD4FB4C54FCEAEC3DULL, 0xA4AD20E7420DF011ULL, 0x52CA5740C3B62C91ULL, 0xFC3E3DEFFFF3311CULL, 
            0xF7C0ECA79C6B5D20ULL, 0xEB351AAEA411CE95ULL, 0x226CE289D3338C70ULL, 0xF9C8DFB9657A35F5ULL, 
            0xF847BC8821DA9B65ULL, 0x89480C2EBF24DD9EULL, 0xFDFCC2040BDFCEB5ULL, 0xF2D0C36E560A6EB0ULL, 
            0xB4DD29CDD7E5A01FULL, 0xA4B441A58A4E616FULL, 0x5B5011DA39381DFEULL, 0x76435A8A935F8544ULL, 
            0x8732D7AE3A6D0C24ULL, 0xB33B388B70C607D2ULL, 0xAC93C50751E59D65ULL, 0xB4EA5B26CDEFB2C3ULL
        },
        {
            0x113E7F155B9C14C1ULL, 0x592E9574E9A2FE0CULL, 0x286C001A1A091586ULL, 0x15F62913F9D876CFULL, 
            0xB4D6D05CFB77704DULL, 0x2355BF1E4DE9FEDBULL, 0xE340B088DF0015DDULL, 0x65F35F0E104D8F73ULL, 
            0xCE5D3621E05D1720ULL, 0x931E6B1C31F4F6FAULL, 0xBB030EAF7CD355FBULL, 0x6D44B11A68E47F7FULL, 
            0xCAD54ED1C31244CAULL, 0x11670C1E73D379B3ULL, 0x019D76806F9DD502ULL, 0x42A15E9B37A832A1ULL, 
            0x819B5B4177875F9DULL, 0x9089CC41CB960AE2ULL, 0x4CC3FE6866D4DB31ULL, 0xF518CC2DCE46BC42ULL, 
            0x95743573A4F95442ULL, 0xBDE63F2E72842A0DULL, 0xCA0A134291E6D66FULL, 0xA02F58ADBAB4C7E1ULL, 
            0x8A10491FFB0720ABULL, 0x3200D1492941B2A2ULL, 0xE032CB18D823318FULL, 0xD865D031D04487C9ULL, 
            0xDE5623892054D5BEULL, 0x38AFFDC0AD40F170ULL, 0x1025A0030BB89C97ULL, 0xFE4C2589E1C1F26AULL
        },
        {
            0xC69218C4127AF185ULL, 0x76ED18CD102C120FULL, 0xE7B3D31CA4B8AB42ULL, 0x9D09CE16673E96A6ULL, 
            0x7059B31CE5419B70ULL, 0x02D3B57B9142798FULL, 0x541E7DDEBCF08D78ULL, 0x7B055E2BA5D41C35ULL, 
            0xC1F55B8C741F1528ULL, 0xF86777F016608E9BULL, 0x253A35D24B5AEAF8ULL, 0x02AAA402BC889969ULL, 
            0x8CCCCE5A66879C86ULL, 0x05CF592346717D8CULL, 0x16FC76FD074C3443ULL, 0x21F0D5943398B614ULL, 
            0x2494F1FE5C170013ULL, 0x5161A501C004DF9FULL, 0xD2054C614781EC62ULL, 0xE46FC1C1C2E28C7DULL, 
            0x8FE39F70B69DC425ULL, 0xA53919A1330DC381ULL, 0xCF1D2F8334EE20A7ULL, 0x2F39A8D559B60181ULL, 
            0x21C2F509C7776BE0ULL, 0xD51AA9FD449DC529ULL, 0x6B487DE76DA8F03BULL, 0x7EC9641950DE05E5ULL, 
            0x6E36BD1C624F6D38ULL, 0x3F4096B60419339EULL, 0xD688C02C16D47AC0ULL, 0x93345F98E09B13D3ULL
        },
        {
            0x99E823FF7D80BD51ULL, 0xBA665990225E9042ULL, 0x40C8D20725E5FDB2ULL, 0xFDC4FEE6FD6EDCC1ULL, 
            0xC2EC159090D44BA3ULL, 0x607C87BD7E84991CULL, 0xFD4B27B4C5AB45D5ULL, 0x0A0FC570E6C69662ULL, 
            0xD6285A2705E11FDAULL, 0x00C2B42EC5FE1202ULL, 0x23C62E66E6D99D23ULL, 0xC7835A0E5D31B56EULL, 
            0x69F8CC7C37553726ULL, 0xCBA611EDB29DC5A7ULL, 0x7AFC6E4CB763117BULL, 0x3DD9548F9096BE93ULL, 
            0xAEB3B70CB7FA558EULL, 0x52926998B7B0DA68ULL, 0x42A5D44959F70953ULL, 0x142B40E473AA4F7FULL, 
            0xC30C471441EB4670ULL, 0xDD977AB35F18353CULL, 0xB37204DE810F6F67ULL, 0x49DF63B442C08A47ULL, 
            0x5C62CE98A6D6BF9EULL, 0xEDE4F3071D111678ULL, 0xE99377D2E486890BULL, 0x8A98ED9C5F2064BFULL, 
            0x49DFB9B8E15A8AFAULL, 0x62A80CBADBB8B6B3ULL, 0x788D18C46792BCA2ULL, 0x0E6327991EC2E2DCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseGConstants = {
    0xFE65B975E75B0E9AULL,
    0xD617FAACBF6539B6ULL,
    0xA8E3A8AEDB254BADULL,
    0xFE65B975E75B0E9AULL,
    0xD617FAACBF6539B6ULL,
    0xA8E3A8AEDB254BADULL,
    0x4BE2F1598585FE0BULL,
    0xB4428C995FBCAEC0ULL,
    0xFD,
    0x2D,
    0xA1,
    0xE2,
    0x30,
    0x56,
    0x95,
    0xC8
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseHSalts = {
    {
        {
            0x79E322D4F3C7AE0FULL, 0x04B420412C4645F9ULL, 0x7D4BD2D71A6F1618ULL, 0x3DC4A4CDE8D1076FULL, 
            0xA81023D00E84B02FULL, 0x3FC67070E5BFD93FULL, 0x5DF27344DEAFAE06ULL, 0x8FD55778D3207961ULL, 
            0x418393477BD8B689ULL, 0xACBBD5EAC1FFBCBFULL, 0x1BB5C37B3CC930AEULL, 0xB170BB00C2E61ED2ULL, 
            0x3A8034EAE08CD665ULL, 0xBC4E917ADE3A3C6FULL, 0x64B349CF633DC2CEULL, 0x1365C8F2BE7B5A14ULL, 
            0xFD65C386F68C64BCULL, 0xFE5F631FB7955D67ULL, 0x85A29D33286226F0ULL, 0x98889F67F6608436ULL, 
            0xCE9E475FCCFD996FULL, 0x235D1343488696EEULL, 0xABB7A033446D084DULL, 0x4EB7F048DA253FE0ULL, 
            0x202B6C68A0F8A4F9ULL, 0x95A72EF6A52E7DD1ULL, 0xB48B894CEBCB93A9ULL, 0xAEBD6FC86A9CD122ULL, 
            0x81546514627BC7E3ULL, 0x649AEB99E5FD84BEULL, 0xDB36EDCF567326B2ULL, 0x5E51F28349FB969CULL
        },
        {
            0x426138D24E538A25ULL, 0xDD42666665FA20B4ULL, 0x860824DED731A3A3ULL, 0xD4CAC534415B54C1ULL, 
            0x0AC49BFD515124C7ULL, 0xDAA2BCD518085C79ULL, 0x6D8217196C78D48EULL, 0xC724F3605095CFADULL, 
            0xE310CE55F9DBCCFFULL, 0xA63206C6D22D7766ULL, 0xB2BB6838E8ADD5F8ULL, 0x1C4E99596B2021C9ULL, 
            0x8EC5A377FCB2774AULL, 0xD239909351258A7CULL, 0xC3CAC9FD5971A01EULL, 0x84288D8E950806C0ULL, 
            0xED9266E7392864A8ULL, 0xF31FE7AC1E5654FCULL, 0x94B4E53D37EB9CBBULL, 0x928BBB7CDD918B2EULL, 
            0xB5D683BF3108F4C0ULL, 0xD7A3AA624274197EULL, 0x8CCE255066C9457DULL, 0xAB2C39EF06EA9846ULL, 
            0xE0C8796311D6ADDEULL, 0x9C8AF65F7DF5F31EULL, 0xBA6BD5EABEA5119BULL, 0xCDEC477C3B2370F9ULL, 
            0xD33297163AC82719ULL, 0x4038F370A915C5F7ULL, 0xEC8D661240CDE527ULL, 0x226905B9E54003FBULL
        },
        {
            0xDDDEC49F7AA3B963ULL, 0xB7966EBF1226A166ULL, 0x6C3A21AD47A5484AULL, 0xC5526F3522EC8D4CULL, 
            0x84CA611C629C93B9ULL, 0x3640219A7BB8FD15ULL, 0xE8A64850F2181695ULL, 0xA6233EA1104F6F65ULL, 
            0x67884F8DBBDF0D5FULL, 0x3D67208AA54F31D5ULL, 0x18E4BE0CF1D27E04ULL, 0x5481EF7CEC252CD2ULL, 
            0x386D10528E395514ULL, 0x49DDD77240ABE24EULL, 0x95751D5F8959930CULL, 0xE316E629FCA35FFEULL, 
            0xBCD4DA956EB94C1FULL, 0x870831731A1D1CDDULL, 0x7F7E88B3191177CFULL, 0xFF7693BB5202BF4DULL, 
            0x60EA60D4D510B9D7ULL, 0x1FE7212E8E7FCF1EULL, 0x804042C443E4D772ULL, 0xF6F0A811F5D2CA72ULL, 
            0x5307629928909D38ULL, 0x44900781EEABB0D6ULL, 0xE6738398190DB819ULL, 0x785F1A8D4F7AC571ULL, 
            0x6D0540CD747FB136ULL, 0xF585320E6D558333ULL, 0xA4F5846E1C579C8AULL, 0x446C8C4C44CED784ULL
        },
        {
            0x72E5B66CFDBB4B8BULL, 0xE94C264B6F797AF4ULL, 0x8463409EEEC41C74ULL, 0x4BCC5679C775B4D6ULL, 
            0xA680E7F97777E4DEULL, 0x0CF50AF364565BF5ULL, 0xB52B547D7B38877EULL, 0x4E71C200771BB239ULL, 
            0xF7469ACD94B79C42ULL, 0x64179D97A1EF28A2ULL, 0xDB369FA025973324ULL, 0x997BC90BBC547D0FULL, 
            0x24F521015655162FULL, 0x9496FEBC1B0FB722ULL, 0x445EEA54160A353CULL, 0x727C4009C4FF6842ULL, 
            0x6FD123B6C1618706ULL, 0x4811E7A50EACAE55ULL, 0x64D96D0E1F892843ULL, 0x15DA77E14041F118ULL, 
            0x12A744324E7D5B37ULL, 0xB60F2638FB4DD155ULL, 0x3FE72A900467CBF5ULL, 0xCE65E48104F376FBULL, 
            0x9CB5D9A368D79042ULL, 0x8A1FB62F66FE28B5ULL, 0xEAA127CFAF6F7424ULL, 0xA0CFE0CD1F318C4EULL, 
            0x69E09B93D11EF131ULL, 0xAFC2B4E4231DD47DULL, 0x2CFC8600CD6BE525ULL, 0xBF84CB6993A4F11CULL
        },
        {
            0x8B30E296A56384B2ULL, 0xCF717383F824C885ULL, 0x29500145416F6492ULL, 0x601903D05456CDE8ULL, 
            0x6A96C2C3FD7206C2ULL, 0x5F4F1605B0A5352CULL, 0xE3301FE5782BF96AULL, 0x3710A66EE5E9B480ULL, 
            0x15FDCBCDD957123CULL, 0x82450133D18ED16AULL, 0x111B9C0B1698F6F5ULL, 0xE3996FBE76F50D47ULL, 
            0x3AFCCE55FD068292ULL, 0x48A4A6734B885E74ULL, 0x76E17B2EC10D4A1CULL, 0x787C501F0B20D386ULL, 
            0x54816A670B359539ULL, 0xAE8C6E759D1A99F3ULL, 0x959E72ADAE02D669ULL, 0x3A4DE7D04EE9E24FULL, 
            0x356516F1D85131FFULL, 0x045E8EC49D9C1574ULL, 0x8C64CDB1077E6EE1ULL, 0x9B068645D01612E6ULL, 
            0xEAD987470F00A461ULL, 0xD7C6D60D85526A60ULL, 0xCC0908DEDF7F5615ULL, 0x87AA79933FA28270ULL, 
            0xB0F0AE47906F3E67ULL, 0xA65BB44361A24BE3ULL, 0xD1A0A04C652C1C0AULL, 0x27A0327C25CF80AFULL
        },
        {
            0xB9AE9921F194FE2CULL, 0xF8D691739867C13DULL, 0x511CD847C37442C6ULL, 0x6D28336FEAF1071DULL, 
            0xBCF0F7B5375AECE1ULL, 0xC89E1C0448D723C6ULL, 0xCC9AAB7A3666FB93ULL, 0xD25D669E52986759ULL, 
            0x0591E507478B927CULL, 0xAA1F6BA46E015B6BULL, 0x4A5553074E710D79ULL, 0xFE358DB2404835DEULL, 
            0x68D8E508220DAFF5ULL, 0x00E97E346BE87AF4ULL, 0x68CC967DAEF0FE15ULL, 0x1CDD734C97BB3C4DULL, 
            0xB311162337BCCCA4ULL, 0x4585E30342238830ULL, 0x9056FD05739927E1ULL, 0x3EBDD7C89ED52BC6ULL, 
            0xF893883922A0B51CULL, 0xFBEE0920565902B6ULL, 0x6B85DFE3B2FACA3AULL, 0xEC9209664715C77CULL, 
            0x83E84883936CDE7FULL, 0xC6B73F1F60854197ULL, 0x7FEB1E286D0744D2ULL, 0x593ECF57E33DD405ULL, 
            0x42DA66644962D6E7ULL, 0xC004B7101DB3B79BULL, 0x680DFFCBD0476991ULL, 0x9CEF7456D7454CFCULL
        }
    },
    {
        {
            0xD60BB81AC4039F67ULL, 0x06A13E5670193F18ULL, 0x64457F3B4F59FB8FULL, 0xBC94A045F3E3EF10ULL, 
            0x858534B9D38EF6ECULL, 0x9511B65E6348CBF9ULL, 0x7FF76CD1146BC66AULL, 0xBC8910C7FE983F08ULL, 
            0xE0985E53FF79CC84ULL, 0x54A42DE6FED71175ULL, 0x6F0FC304D04034A8ULL, 0x97B980E71419F01CULL, 
            0x014F726EF5B18D73ULL, 0xBF2C4445AF4FA789ULL, 0xB0BBB910A1C9677FULL, 0x12C47FDEF645B373ULL, 
            0x0C13FCFD0014C303ULL, 0xA3B4EDD4837133C6ULL, 0xB0B456C601A66AA5ULL, 0x54B1BBF14EC4301CULL, 
            0xEC508E26E1E77064ULL, 0xD9CCB974965781DEULL, 0x5C34AD2A3A242799ULL, 0x3F0FCCBD0C90436FULL, 
            0x78CF3460D1DEDBC9ULL, 0x7771C5B6206470B2ULL, 0xD207607FCF8B2E2CULL, 0x029B9CEB12B33870ULL, 
            0x9315377D3CCB1751ULL, 0xBA1DD1242E8C7E12ULL, 0xFC5AB5B1B0E2CBE2ULL, 0x9F7D750F2EF107D8ULL
        },
        {
            0xC719EB391D1234ECULL, 0xA5EC5686C158CE08ULL, 0xDDF7DBED30625A97ULL, 0xFC41DC1CBF1F3B34ULL, 
            0xDA43111473A47411ULL, 0xB90B3745F273D2F6ULL, 0xAC52C3D899498914ULL, 0x41522620F4B28406ULL, 
            0x688C6719B26754A6ULL, 0xEE3B95264B3723F2ULL, 0xB73BEEC33D03B2BEULL, 0x1ADCFCE4AE482513ULL, 
            0x1F0FDDA38F564552ULL, 0x6264EAA11F5562ADULL, 0x70AE3AE197914F77ULL, 0xD7856727FD21A704ULL, 
            0x263EE7F93B9F9272ULL, 0xD00071E33635EE72ULL, 0x9E996ACC836E9172ULL, 0xD5AA3AC2007106A1ULL, 
            0x25B9BDD8898B238CULL, 0x40AF436B2993691AULL, 0x73D1D6189DD65661ULL, 0x2BBFB894BE814893ULL, 
            0x37683303BBC300D9ULL, 0xF2AF4920FFCF3C12ULL, 0x5A3085640CD8745EULL, 0x709BAF8CF7E8F871ULL, 
            0x880A14902C40D86CULL, 0x73A4601DD53566E4ULL, 0x59C115CF5ED967E4ULL, 0x2F57A2EDE453D153ULL
        },
        {
            0x98852A35FC662BA5ULL, 0x3CA793C6766B37DEULL, 0x3197973C6681FB6FULL, 0xAF05D999810F77E7ULL, 
            0xD1A78603AD03C3EBULL, 0x4934D49DC8929A46ULL, 0x1C669A64C0946B1AULL, 0xD43E16F077552000ULL, 
            0xCAAA4A57BE338C9EULL, 0xADF630C908F666E8ULL, 0x7DB39EA5CA184E63ULL, 0x3C39D4DB49DB1895ULL, 
            0x77FA35F4A9E58155ULL, 0x0BE059C247679F4BULL, 0x465111AB5D387B6AULL, 0x1C428C981AD29637ULL, 
            0x4E5E392190ADDCE0ULL, 0xD1234DB62E5194F2ULL, 0x7F1A00AE79715656ULL, 0x25BCBFBC5D7D1A85ULL, 
            0x3E65CF2F8371F755ULL, 0x41EDE951E04CFA14ULL, 0x9EC027D0420DF56BULL, 0x1326F71EC01D1330ULL, 
            0x5124DE5A66AB2E90ULL, 0x782879591A449A8EULL, 0x854914D2B89CFB06ULL, 0xEF18AF52B1BB2DAFULL, 
            0x92387B7536C6B8B2ULL, 0x324CA7D609DCEC24ULL, 0x56DA211AF6BBC3E0ULL, 0xE91E0464C124C3C5ULL
        },
        {
            0x353F915C597105FEULL, 0x646AAFE0B1B37628ULL, 0x8034E895460EC724ULL, 0x0DFBD4EA32A033C5ULL, 
            0xF1B9CFBD5CFB0A58ULL, 0xDD882FA6A8DA4CB6ULL, 0xC1DBB7F7F179767BULL, 0xB6940F7FCC33E9BDULL, 
            0xC3F32C55F712CC60ULL, 0x58097E53E88A85A4ULL, 0xE4E4A1D25A2F69C8ULL, 0xDB47D841605C789BULL, 
            0xCEDFB359CBB31FC7ULL, 0x515F8F18510EEFD1ULL, 0x9BA26E97C0765881ULL, 0x117FCC0D1316DED9ULL, 
            0xB2A9AC1028E029F7ULL, 0x111D50D6BA820E18ULL, 0xB61C4F52D81947C9ULL, 0x7440B23785AA3BE1ULL, 
            0x91C56C12BB25085FULL, 0x9B703A900C5AB260ULL, 0x44A82CB15274E87FULL, 0xAC6556C86E013694ULL, 
            0xC2EF19F85F092B79ULL, 0x110B4CA2A907388AULL, 0xFA1E7C5093D066D1ULL, 0x505930A361539F66ULL, 
            0x96E7B5D0CB51E56FULL, 0xE45469A1FEFB9CE4ULL, 0x5BA98ED19CCA9B24ULL, 0xBD3AC118274F2FD5ULL
        },
        {
            0x589F9795F0F4901CULL, 0xC8C837A5F01AB3F2ULL, 0x4B8FB4313C95D640ULL, 0x92E671A8D8F24A40ULL, 
            0xF9CD64B96D4F0A75ULL, 0xAAFAB0D4E8FE9FDFULL, 0x92F9D4F235ECBDA6ULL, 0x8E247D4FB0AC64D2ULL, 
            0xE8AF8EA6726C0457ULL, 0xBE2A32EFD4ED9AE2ULL, 0xE0D527E7F2B9A738ULL, 0xDCB21E51148AFAFDULL, 
            0x12CC9B10018AC965ULL, 0x7F47D7D530C8275BULL, 0x96D075459859EFCEULL, 0x5C327D63D7519863ULL, 
            0xC72AA3061CF071EDULL, 0x3C81D94960254A0CULL, 0x904DC65E73A4EE42ULL, 0x82D7D7832B40200DULL, 
            0x143AE0BB6CA49DA1ULL, 0x7DA5A72F96CEF075ULL, 0x2177B782F6D9DC7BULL, 0x53DB40E577103F68ULL, 
            0xF4D1614D7B378DFAULL, 0x1DDA9014CAF081FFULL, 0xA7896856F9AF41A5ULL, 0xE1CF4FD35E426FA5ULL, 
            0x367958CDC619C589ULL, 0x54CB5EC4026777F4ULL, 0xCB024AC3B87DAD58ULL, 0xBB3884872930A506ULL
        },
        {
            0xB64E1A26EDEE2796ULL, 0x718FEC6680CDAB9CULL, 0x9FE4D0D036EF5406ULL, 0xC45954AFCE304EA4ULL, 
            0xC9066B16FB2ECF5DULL, 0x5016D6F62736ACDAULL, 0xCD58A10CC1171B1BULL, 0x19FF78427542F4A9ULL, 
            0x50D71183BCFA5FE3ULL, 0xFABABC4AF1BE7B30ULL, 0x5AA0C8010CCF8D13ULL, 0xCC09CC28B4AE6097ULL, 
            0xF9A4AE70EABE9054ULL, 0x1875EE569E7122DCULL, 0xAFAB008C90C4AB80ULL, 0xB5D32689D4AC9877ULL, 
            0x91AE89AA519FAF7DULL, 0xE68EF60DF5EC06E4ULL, 0x3F4D01CCF77CE070ULL, 0x13AD9830638C5D51ULL, 
            0xC640EA8749A13559ULL, 0x71D3FBCE44A66959ULL, 0x5780B6515C59EB94ULL, 0x7155B392E7378747ULL, 
            0xD9168A25789F4B3BULL, 0xDE3725925ED60BB8ULL, 0xA6568C1299E337E8ULL, 0x0C1932A18C9D9D76ULL, 
            0x17938082BB2F9014ULL, 0xCD191C4E46459893ULL, 0xFA66B8FFC6B663DFULL, 0xDD9DAA189B934F2AULL
        }
    },
    {
        {
            0x06BD8B81F85F1D0CULL, 0xF68742E4B8498ECCULL, 0x7620BE7D49B46402ULL, 0x4B297B499EDD12D4ULL, 
            0xF6958166D74C93CBULL, 0x911D7E395ACB3E53ULL, 0xD20BC13CEF8C1AC0ULL, 0x046BFAD852581EACULL, 
            0xD03DDB6DDEF3E9A4ULL, 0x7C9B3E8E6AE72EA3ULL, 0x86F897BAFE845DF8ULL, 0x57F0DC62F419B4F3ULL, 
            0xE7C60643FD2CA17DULL, 0x3A27999AED382A9BULL, 0x48A7FE46C1A8D657ULL, 0xC1B9B25DE7F87ECDULL, 
            0x64B2F33E9CE10974ULL, 0x797A6FC0E598773BULL, 0x111374D4DB0E8B5CULL, 0xA7EEE96014618F0CULL, 
            0x6353575966D0EEB8ULL, 0x427FC5B0C305BEE9ULL, 0x1CFF74694AEC44D4ULL, 0xE829A91C67CA0736ULL, 
            0x6EA925957A56B3FCULL, 0x2AB45817B777B0BDULL, 0xB8F21388DBF0C2F5ULL, 0x85713EA905FD1A25ULL, 
            0xDAD125B800041B82ULL, 0x5E522AC523DC1CB2ULL, 0x1E8D63F1B2E87DC0ULL, 0x5D531394372C7531ULL
        },
        {
            0x356F9DDCC1213013ULL, 0x8B90BB38842E03E4ULL, 0x457DA5985BB4B67BULL, 0xE0AFD3D2C8E9735DULL, 
            0x27C03846FC91B623ULL, 0xB23ED5CC21834B16ULL, 0x7E9BF9E83AB6BF20ULL, 0xB8DA1A95C366C0A0ULL, 
            0x76A139CB70E2BBE9ULL, 0xF34E19D25DF53511ULL, 0x94BECA87225F1B10ULL, 0x993741532B0C76B7ULL, 
            0xF84833E54124F457ULL, 0x91CF1279D8431FACULL, 0x127403AF70C08E93ULL, 0xC154FB0D079E1D55ULL, 
            0xEAD9F2B6625D8DC7ULL, 0xF6077E6E8C0B40B8ULL, 0x3810D1540C2FCCAFULL, 0x859DE4F19A40850AULL, 
            0x477C65585CAE8393ULL, 0xBBE31321689A90CEULL, 0x0FA5CA40C7CCE636ULL, 0x53A92C269F3724C4ULL, 
            0x6274C6D3C494FF1BULL, 0xFE8860C6C36367D9ULL, 0x00FC526305609A93ULL, 0x072ED20C6E840068ULL, 
            0xED8ABCEA221A8118ULL, 0xC7AB6DDD583F7700ULL, 0xB0A87FE1EF4B3751ULL, 0x0E27DC41BD8FFFAAULL
        },
        {
            0xCC36390D6E6CDF6AULL, 0xD5F67143C807AADBULL, 0xEE89CE026BA17749ULL, 0x6F3431C22C6E5A4DULL, 
            0xE24DBE01E92063ECULL, 0x41F0D3ABC9C9821DULL, 0xA07F290FAC484662ULL, 0x6EDC1660FE170149ULL, 
            0x5D4D1BBED419E8E3ULL, 0x0135CD193A805D5AULL, 0x4EB54608CE391EA0ULL, 0x4B4A64C329CF469CULL, 
            0xEF8D288F250F1CB4ULL, 0x4F89D94B07463F1AULL, 0xA3C90EB626DB1D9EULL, 0xE16EE1B77EF17341ULL, 
            0xB0050A5EBA13A7EBULL, 0x23FF5E4BD2563608ULL, 0x44B2A091FF675B6DULL, 0x5C7D0580CE942D52ULL, 
            0x10A06DE378D352A2ULL, 0xF9EB9111C8AD7945ULL, 0x8D07F7B3BF9AE661ULL, 0xC9A6DB1FBE408513ULL, 
            0x4D50113BEE88F9B9ULL, 0x53E227EBF3E388DEULL, 0xED92276A308C81B3ULL, 0xA88CBCF53BA1FEBBULL, 
            0x78573EFDFFB0EE6DULL, 0x7BD0D14CC8C9FD6FULL, 0x62301A6964420AF9ULL, 0x3BC155E10CBE29DDULL
        },
        {
            0xC50D0AAC8F8EBA3CULL, 0x329C6F096DDCE6A3ULL, 0x813AA44231E83FB2ULL, 0x94D281BD8889B92AULL, 
            0x56AFEB3BC23E9369ULL, 0x9532CD9AD37F9E7FULL, 0x9E4A1F6521CCBFACULL, 0xFDB683DFEB172ACAULL, 
            0x371DA625CEADA7E6ULL, 0xB3A5F2FCC4137C38ULL, 0x5E45C9A2FDAEBB3EULL, 0xE597745CBD92DCC1ULL, 
            0x994602C9C64430A8ULL, 0xC4ACA2FE3539BB79ULL, 0x1E004BCB77A02674ULL, 0xA372BA32561E0F4AULL, 
            0x83058BF0CE075685ULL, 0xDA0A7DA07F025E32ULL, 0xE98A17243B43ACE5ULL, 0x45CE3CBA6EA46306ULL, 
            0x7A0A82455EA2E107ULL, 0xC36C2A0E2D7648C4ULL, 0x1A93986977DC114FULL, 0x7AAED8666E98F753ULL, 
            0xD6977673599EBCBFULL, 0x50327492BE5C7BC5ULL, 0xA911DCF031931203ULL, 0x93A4ACDED942AC8DULL, 
            0x835FB0407890B934ULL, 0xA14A7CCB95FAB2ECULL, 0x078717C6EA38D54BULL, 0x37E3B1787E6BE399ULL
        },
        {
            0xBABFF9584B630A73ULL, 0x649ECE827197EC4FULL, 0x480AF0FA7A1145F9ULL, 0xC886659FDAEF7A5BULL, 
            0x62807474B49A3216ULL, 0x5EBDF10CD87EE41CULL, 0x4D2D746BFD4B35CCULL, 0x7BB21CEB5AFE8259ULL, 
            0xF182044E76BA2F62ULL, 0x301E7F93748E5191ULL, 0x8421F258339BBF0FULL, 0xE05E86EBF03DD379ULL, 
            0x1E4CAAB61CCB23B4ULL, 0xD753964B877DF658ULL, 0x1A2BAE8D9743B8A2ULL, 0x5950E496AE61E660ULL, 
            0x6229F479E35162A6ULL, 0xF6356B0412910E43ULL, 0x955CBBB50C075C0FULL, 0x921E4CE223ECA8B9ULL, 
            0xFBFE36F88DE50849ULL, 0x72A1C09E49C646F2ULL, 0x8000761D75E8FA1BULL, 0x4DF586EEBB85BF82ULL, 
            0x97C967CE958FD518ULL, 0x0FA6399B86D21A14ULL, 0xAFB33AF391E4E455ULL, 0xB1F7EDFF9FE15B61ULL, 
            0x8D98FC6A3863B0C8ULL, 0x1D771355315D611CULL, 0xAAE39B74C5633750ULL, 0x41186DC1473163A7ULL
        },
        {
            0x523E9807EF231EECULL, 0x2079B51A6AF97FAFULL, 0x9BA5F95FA06221CEULL, 0xE34870F01AACE445ULL, 
            0xAB00691E98B8E356ULL, 0xE0F46CE1D3D72C15ULL, 0x4D923C6BCE5B2CE2ULL, 0x712044E97DDB9162ULL, 
            0x677196C5A40B518FULL, 0xC985FE4F19FBB96EULL, 0x109514D972993967ULL, 0x7F0A4D3D5B4B5190ULL, 
            0x3D6EF3776D161B4BULL, 0x6A54CE04A5BE3EFAULL, 0x04506CC61CDB3DA1ULL, 0x139EDF8D31679843ULL, 
            0x629B714AE708AE06ULL, 0x116B7397FD0F2BBCULL, 0x5F163C0808F251F6ULL, 0x59E9FD463F212CD4ULL, 
            0x29411ED6443D2A6BULL, 0x65FB6FB8703BC84FULL, 0xEE1A4E66F3353959ULL, 0x4047F59341F2BC07ULL, 
            0x06C2C05A4528834AULL, 0xE925218F88B433DAULL, 0x64F0BF220D21542AULL, 0x52A2C6388F77E8FDULL, 
            0xE510E8E14843BD7EULL, 0xB6043D0E6A72DFCCULL, 0xA7337ECB1C294517ULL, 0x79063576A6B10897ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseHConstants = {
    0xEF9032DFC225455AULL,
    0x31C41691BC33DCEFULL,
    0xF22603F2E19BF63DULL,
    0xEF9032DFC225455AULL,
    0x31C41691BC33DCEFULL,
    0xF22603F2E19BF63DULL,
    0x7F07387B28D39D75ULL,
    0xF6F56A4A7E1373F6ULL,
    0xF5,
    0xBE,
    0xAF,
    0x11,
    0xE3,
    0x25,
    0xAE,
    0x1C
};

