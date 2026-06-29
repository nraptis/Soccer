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
    std::uint64_t aPrevious = 0xFC82905664E626CAULL; std::uint64_t aIngress = 0xD77DCF7EF2B81B91ULL; std::uint64_t aCarry = 0xD69631FF88972165ULL;

    std::uint64_t aWandererA = 0xA0D9A91770BE75C6ULL; std::uint64_t aWandererB = 0xC00C99018B979F7CULL; std::uint64_t aWandererC = 0x8E3E47D0C86DB9C2ULL; std::uint64_t aWandererD = 0xC36632DE44706B0EULL;
    std::uint64_t aWandererE = 0x9826CC51FF8D7F69ULL; std::uint64_t aWandererF = 0xEC302826D35502D8ULL; std::uint64_t aWandererG = 0x96B55D4AF271A310ULL; std::uint64_t aWandererH = 0xA2AC034CA4F38CCEULL;
    std::uint64_t aWandererI = 0xDA8A2C9B330D6387ULL; std::uint64_t aWandererJ = 0x85AECBC488166E22ULL; std::uint64_t aWandererK = 0xB05620CEF527FAD6ULL;

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
        aPrevious = 16775436912503595298U;
        aCarry = 12415586042461468359U;
        aWandererA = 10254612978307746747U;
        aWandererB = 10464576937346412748U;
        aWandererC = 14687348817964157167U;
        aWandererD = 15410683250007844938U;
        aWandererE = 10783281835925144928U;
        aWandererF = 14398029583076330485U;
        aWandererG = 16860995498612073995U;
        aWandererH = 11548319390262558284U;
        aWandererI = 10037758301929496777U;
        aWandererJ = 17782568019155738891U;
        aWandererK = 15227286626322661110U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0x9533BCAA44726E80ULL; std::uint64_t aIngress = 0xA7F767180DAB3AF7ULL; std::uint64_t aCarry = 0x8FF188768BA67A97ULL;

    std::uint64_t aWandererA = 0xD17486996FB54AC2ULL; std::uint64_t aWandererB = 0xA2A5F31CEEE0F399ULL; std::uint64_t aWandererC = 0x9C49243ADF7CA74FULL; std::uint64_t aWandererD = 0xCBB9391F651EFA71ULL;
    std::uint64_t aWandererE = 0xEFA6C9819CD01C9FULL; std::uint64_t aWandererF = 0xBE27FD39D36321FDULL; std::uint64_t aWandererG = 0xFB4296003372869EULL; std::uint64_t aWandererH = 0xEF9C284D16661A1AULL;
    std::uint64_t aWandererI = 0xDC0D66CF51B95355ULL; std::uint64_t aWandererJ = 0xAE8F0155E832AF57ULL; std::uint64_t aWandererK = 0xFD6D2F32E097011EULL;

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
        aPrevious = 11784782225923286453U;
        aCarry = 10568573530031677264U;
        aWandererA = 14419914355495144916U;
        aWandererB = 12719811594729430084U;
        aWandererC = 15503444265913495422U;
        aWandererD = 9873803359698783118U;
        aWandererE = 18362602585543021619U;
        aWandererF = 14866539912869330897U;
        aWandererG = 13500636153770183964U;
        aWandererH = 16411218185877755853U;
        aWandererI = 9771554269014572718U;
        aWandererJ = 11825523021729913503U;
        aWandererK = 10344705052218475051U;
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
    std::uint64_t aPrevious = 0x8BB883A3E7A23B41ULL;
    std::uint64_t aIngress = 0xBFD75C674DFE44B4ULL;
    std::uint64_t aCarry = 0xEBCC5E00C6CC9681ULL;

    std::uint64_t aWandererA = 0xB94F3A4465FD195AULL;
    std::uint64_t aWandererB = 0xA2CDBC85B045EF63ULL;
    std::uint64_t aWandererC = 0xDF9E8085E2FC65C7ULL;
    std::uint64_t aWandererD = 0xE14EACA84A586D2EULL;
    std::uint64_t aWandererE = 0xBFC3CC5E53436E36ULL;
    std::uint64_t aWandererF = 0x9E18038B81530A79ULL;
    std::uint64_t aWandererG = 0xDAFEBB7B175E4727ULL;
    std::uint64_t aWandererH = 0xE93B4B816B93E7D4ULL;
    std::uint64_t aWandererI = 0xCFA9960DBCC5E0C1ULL;
    std::uint64_t aWandererJ = 0xACBE5835CD13AD77ULL;
    std::uint64_t aWandererK = 0x862B9F413AF8E947ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneB);
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
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
    std::uint64_t aPrevious = 0xBC976DB787753E90ULL; std::uint64_t aIngress = 0x84B350150B236EEAULL; std::uint64_t aCarry = 0x9D0ED0FCD469356EULL;

    std::uint64_t aWandererA = 0x950CBDC7F2C866CBULL; std::uint64_t aWandererB = 0xE152D70DD3BB7453ULL; std::uint64_t aWandererC = 0xCCF9E1B75165CAB1ULL; std::uint64_t aWandererD = 0xBF653DA06059B06CULL;
    std::uint64_t aWandererE = 0x9479320A523797D9ULL; std::uint64_t aWandererF = 0x9D594B047789E6F3ULL; std::uint64_t aWandererG = 0xC76D36170B312043ULL; std::uint64_t aWandererH = 0x98E044A651F8F2CCULL;
    std::uint64_t aWandererI = 0xFCD6ABB05B92E3DEULL; std::uint64_t aWandererJ = 0xB2AEAFA5F7A02ABFULL; std::uint64_t aWandererK = 0x9C03F607721DD70DULL;

    // [seed]
    {
        aPrevious = 10077190931655043334U;
        aCarry = 13918510896362707272U;
        aWandererA = 14851755516516333891U;
        aWandererB = 17538814846822765037U;
        aWandererC = 14829070968306701227U;
        aWandererD = 17461672110506720369U;
        aWandererE = 10634214480164907745U;
        aWandererF = 13177845856976475903U;
        aWandererG = 11590596699388773114U;
        aWandererH = 13991961467556972501U;
        aWandererI = 13692271901769553428U;
        aWandererJ = 16880852463462504556U;
        aWandererK = 11145988844982568464U;
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
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 0, 0 with offsets 1833U, 3915U, 3414U, 5935U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1833U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3915U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3414U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5935U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 3, 2 with offsets 2190U, 915U, 1471U, 1807U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 915U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1471U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1807U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 2, 3 with offsets 3614U, 3893U, 3804U, 347U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3614U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3893U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3804U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 347U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 1 with offsets 214U, 4855U, 2636U, 1671U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 214U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4855U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2636U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1671U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 1104U, 1556U, 1484U, 480U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1104U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1484U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 480U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 1, 3 with offsets 11U, 878U, 1871U, 1271U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 11U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 878U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1271U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 1, 0 with offsets 1908U, 1681U, 1404U, 2046U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1908U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1681U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1404U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2046U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 2, 1 with offsets 518U, 1885U, 243U, 631U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 518U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1885U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 243U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 631U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1171U, 676U, 1997U, 1145U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1171U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 676U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1997U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1145U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 1 with offsets 2339U, 3036U, 7240U, 4963U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2339U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3036U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7240U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4963U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 0 with offsets 3704U, 8115U, 3293U, 6842U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3704U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8115U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3293U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6842U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 2, 3 with offsets 1879U, 1806U, 1784U, 3211U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1879U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1806U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1784U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3211U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 2 with offsets 33U, 4079U, 2208U, 7833U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 33U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4079U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2208U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7833U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5390U, 2797U, 2200U, 1615U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5390U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2797U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2200U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1615U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 667U, 727U, 1169U, 1987U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 667U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 727U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1169U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1987U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 670U, 565U, 89U, 2010U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 670U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 89U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2010U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 376U, 78U, 1673U, 191U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 376U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 78U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1673U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 191U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1441U, 1527U, 2022U, 1486U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1441U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1527U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2022U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1486U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 [0..<W_KEY]
        // offsets: 1264U, 567U, 1459U, 1102U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 567U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1459U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1102U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseASalts = {
    {
        {
            0x90BE06844B1305F0ULL, 0xE19EBC39EA84A611ULL, 0x14EEEA67A76F8539ULL, 0x91C05B8C2D5FBDE1ULL, 
            0x7EACCD1F72EF886FULL, 0x2339BB1F0B5D0FABULL, 0x062AEE6B3CA43952ULL, 0x7D815E32D8AED336ULL, 
            0xF921C411907042F6ULL, 0x8CA21928B162BC61ULL, 0x3A9FBA6C9FE95BF4ULL, 0x03B120472FCA7C70ULL, 
            0x62F3FD1DD380BCFFULL, 0xB8EA99A962157195ULL, 0x90513EE2E4B36ADCULL, 0x67CE4650694E41C4ULL, 
            0xBEE55FB0E8681F69ULL, 0x6F43ABF77BBFC153ULL, 0x7643F0B47E8BB39BULL, 0x21AAFF425809C4ACULL, 
            0x6ACA11E2979FF39DULL, 0x11AD844EB38B8310ULL, 0x69C8524F801ADD47ULL, 0x60B2E899CFF628B6ULL, 
            0xEF1CC615FB548B70ULL, 0x9E07A919D5101F18ULL, 0x114DFACE46E96208ULL, 0xFA61402E687F3E5EULL, 
            0x0441080B899BF826ULL, 0x1503C7AC4095778EULL, 0x27864BCA6D4A5674ULL, 0x6BC836334FE74589ULL
        },
        {
            0x05889A58B3327AE3ULL, 0x3A4D37A42547856AULL, 0xED0ADD1B292E01E4ULL, 0xEF111D3A6A32A32CULL, 
            0x295EC18B4E56B094ULL, 0x2DF070FA172CBC4CULL, 0xDBD38B4B2D1D29F1ULL, 0x6ACC146AE64D5CFBULL, 
            0x03131FA3E8DB0C8FULL, 0x545E6DF218E20AA9ULL, 0x8D301CD074D78949ULL, 0xA41053A3BD0F2627ULL, 
            0x2D7132BE284C56EDULL, 0xFA75864A7750C293ULL, 0x653231441A3509DBULL, 0xAC9E43572AD13EC4ULL, 
            0xE29DFD7A67AC6C85ULL, 0x4E27539E5FCCAE12ULL, 0x21425000B5C05A56ULL, 0x03C18D9ED493714EULL, 
            0x7FE04D1811175A9EULL, 0xDC7BE5CD00C4F503ULL, 0x49EB47F08ED36EFCULL, 0xE596911B99D28AC7ULL, 
            0x5A8991B84DA83BF3ULL, 0x10600D0FA7040DC7ULL, 0xB94FE53A36B878D6ULL, 0x42AB3C624F1FBDF5ULL, 
            0x782DEAC158D13BBAULL, 0xDF4CD755DB942674ULL, 0x8E430DFFF0E0BB32ULL, 0x4E1A8CEC38FD6236ULL
        },
        {
            0xAE2786E3438327F5ULL, 0x142191956DA6A1AEULL, 0x180B0204BABEFDD8ULL, 0x67211B1953D67D80ULL, 
            0x4EF145DBED2DFC37ULL, 0xC4C7B17C2B061838ULL, 0x8DA5917BF0A4AEB0ULL, 0x4F937FB6F9BD7CC5ULL, 
            0xB0A07DAE932B0E3FULL, 0x57C9A8ABE6EA5176ULL, 0x49441834EFB624C5ULL, 0xA772E8511D6E39C7ULL, 
            0x1B0260B3219BCAE1ULL, 0xB8C63A1A2CB4954FULL, 0x03604ADB36520BB4ULL, 0xA90DF234EEA3217CULL, 
            0x8870BC34D3E15285ULL, 0xA53D034662F53F74ULL, 0x3C87CBE80AFBFE22ULL, 0xA6516B94C0B6D55EULL, 
            0xD47574498CEE0DC1ULL, 0x61C3753E4EF778D7ULL, 0x4E89F0582A0DCB81ULL, 0x8E38F2D7012F3DAAULL, 
            0xD81EE9C5A6A3F528ULL, 0x319D9765BAAB5CCDULL, 0x53A961CF6DC9C4AFULL, 0x8BCB85B42967EE85ULL, 
            0xEB34604F7F3D1280ULL, 0x1DC69C20E10541B5ULL, 0x9595EE743DE8525AULL, 0xF507455EF796051BULL
        },
        {
            0x861C657F636D30C9ULL, 0x6DDF48CB36FEC885ULL, 0x5F341AD7EEBB927DULL, 0x866258CB45AEBA76ULL, 
            0x5E4F136537BF489DULL, 0xE4A9C2AC825BC2E2ULL, 0xDE0929AD3B71D35CULL, 0x4047D9B32AD3CB59ULL, 
            0x4BC68892EF54A63FULL, 0x63D2A9E682852C73ULL, 0xEBB486402F85E54AULL, 0xCC4A0D07FD9AA0AEULL, 
            0xD8684DED66333BD3ULL, 0xD41528941FB8D514ULL, 0x84A4448B546E8061ULL, 0xD05D93575EFFD5D1ULL, 
            0x6A61AC88E5C5AED1ULL, 0x8D1AD29FB3D5E3F6ULL, 0xAE13E76DE8F6563AULL, 0xF6D14E30515FC2B7ULL, 
            0x4F1730CE17230228ULL, 0x6F9E2F8C6BB405E4ULL, 0x9E47EC307AEF94BDULL, 0x234E8229F588C4C2ULL, 
            0x263B4D6778495C22ULL, 0xC5A17492D2725315ULL, 0x30E5C106B4A745BFULL, 0x3F360602B986AB12ULL, 
            0x9112A990F5F55BCBULL, 0x76AC73F55AC4B05FULL, 0x09A4E10CC645B4E5ULL, 0x1E469A0F111FF15DULL
        },
        {
            0x223A5939CA08F887ULL, 0xA7B64FA01ACDAD7EULL, 0x099EB0975C624BF0ULL, 0xF434C79D5D99DF17ULL, 
            0xC50B1100508C603AULL, 0xB07B88F621BC2191ULL, 0x977CB3724A214322ULL, 0xC84EF6EC4FC05C71ULL, 
            0x78650ACBEFFFF3BEULL, 0xCA4C5B332C9B0100ULL, 0xD0AF016671BC2F05ULL, 0xF5EDBE82180D80C1ULL, 
            0xEB2EC96BA58D1A63ULL, 0x85A2BA12F476C353ULL, 0xC04820A2BE5317E6ULL, 0xEB9402C12DD7AFA6ULL, 
            0xA1B08D4651714A69ULL, 0xB1E5DB59A8AD69F0ULL, 0xF6CDB0FC64CD7E79ULL, 0x96325710DF97289EULL, 
            0x387F49EF5CF37266ULL, 0x3B4B745D2A3BBD20ULL, 0x2B7A6377ECDAF985ULL, 0x0AC64CA2B330C7B1ULL, 
            0x0AAEF98BC08A99DDULL, 0x40D2F8CEAF6187BDULL, 0x5F2A031F545EBA45ULL, 0xC1B262128FFCBC50ULL, 
            0x53A1320009D49CFFULL, 0xC0E10B54148FF889ULL, 0xDD435E14F0399C48ULL, 0xDC45EBFC93550331ULL
        },
        {
            0x222A5041AA54D36FULL, 0xB396ED270B48A544ULL, 0xB475989AB0FE6DA6ULL, 0x59079E93F385607CULL, 
            0x835025FE17A0833BULL, 0xB3AE06D8EA28D8E9ULL, 0x951551A417989A6BULL, 0x4E4BDC0E7F57F40BULL, 
            0x0F89C1DE5F73429BULL, 0xAFE88F84A0F7CA99ULL, 0x3420E9576644C162ULL, 0x75F9ACFA668DA497ULL, 
            0xAA35E1F644C15BCCULL, 0x7783CF2FD07BD98DULL, 0xE5DCC97E1192D3DBULL, 0x025D0CB07AC2EB40ULL, 
            0x28401E04540D1917ULL, 0x7F526DD5BFEAB106ULL, 0x9F16763C9941F8AFULL, 0xBCC4EEA0A2DF50D8ULL, 
            0x8BD23EA16E0D0E7AULL, 0xBCD86C68BD4E98B0ULL, 0x4E1A2B022A59983FULL, 0x6C108E3A551D74B7ULL, 
            0x57FCA6B77B9B8D6BULL, 0xDC690BCF044CEF86ULL, 0x871AF22539B385E0ULL, 0xA9CC51914936DD5FULL, 
            0xAAAD22AD0D7EB391ULL, 0x808EAA3E65895028ULL, 0x8D736EFD8520176DULL, 0xA839FFF9788C0A02ULL
        }
    },
    {
        {
            0x1A2B31F500210AEDULL, 0x0A225997393127C4ULL, 0xC232DF05328BD270ULL, 0x0BF04A7528F8D4D0ULL, 
            0xC1103290169D2FBDULL, 0x1CF4781335887684ULL, 0x1AF8D017651DE65CULL, 0xDFF0560FAD8C6AD5ULL, 
            0x65EBA6A3A1C642C0ULL, 0x939B80F441B6000BULL, 0x34B6A1D6CCCE37CEULL, 0x1CD1F188F0B76BF3ULL, 
            0x8FD849A909567AA5ULL, 0x71879C984900CBDEULL, 0x828F69591B68520EULL, 0x72BE849625810114ULL, 
            0xD36DD290494FE349ULL, 0xEE7F8770DB191A3CULL, 0x1FD88A3CBA839AF5ULL, 0xF9FE1ADE9258167FULL, 
            0x25364FB29AD90359ULL, 0xF8EB52499B48C347ULL, 0xD5A8A84C7A1BBE52ULL, 0xA2916B69EA8285D8ULL, 
            0xFE560EB57D0A352BULL, 0xE1C98CF656B049A2ULL, 0xBEB308C5535B57A5ULL, 0xA40057211D6231B1ULL, 
            0x4151ABB767EE6DD4ULL, 0xC996AEEDFB8A8C99ULL, 0xE0B6AFD01EC0138CULL, 0x5C85544D2A81A961ULL
        },
        {
            0x0A063A675E28B1A9ULL, 0x46B17E71A982E555ULL, 0x67EB28A0B21C3B29ULL, 0x48EFC6061A317EE1ULL, 
            0xD42E0F634B08FD32ULL, 0x908182693DE392DFULL, 0xFA895DA0C6E09F3CULL, 0x99C2A2313015E406ULL, 
            0x7CEA26ABE7DD4BEEULL, 0x604B4D0F4938DA70ULL, 0x2216F6470DED4996ULL, 0x6EEC34765BA60E7CULL, 
            0x9F402E59F7613EC8ULL, 0x94C6C2D0CAACB1FEULL, 0x530AB1CDD3C5F3DEULL, 0x71A9E990F5ACF979ULL, 
            0x008C09984CAC6D67ULL, 0x6494824AFF1FF151ULL, 0xCF82D5ECCF9909ACULL, 0x02A8C1B209C30A58ULL, 
            0x01DF5B3122376B0DULL, 0x2C8CE736CCE1294EULL, 0x7178C1C87D4F11A9ULL, 0xF48B1E08CAE29507ULL, 
            0x1568B38D398ABD97ULL, 0x9658C04C228FBE54ULL, 0x5F39A31DE62022BAULL, 0x82F03864EA6AB7F5ULL, 
            0xAFD3DD631D7296CDULL, 0xFFD935EDB12C76FCULL, 0x8E307C47967D3877ULL, 0xF332861913672403ULL
        },
        {
            0xD3F1926A0A5B28CDULL, 0x80DBD68BD0A09E4BULL, 0xF9CCC865A97A3806ULL, 0x1C2B2C13C780CC71ULL, 
            0x1204EC49454AE229ULL, 0x18CC57DB4D0FFCE5ULL, 0xD0E90FBF3646F659ULL, 0x89A7BCF4AC709844ULL, 
            0x7F8DD6FD19A15C65ULL, 0xA89B3E345E746E0BULL, 0x0EA5DBD93FC124EBULL, 0xE868C0AC084330C2ULL, 
            0xB203392949B6BBACULL, 0xD32C38F22B9068BAULL, 0x54E07E908EF9B60CULL, 0xBFE8D786EA32489DULL, 
            0x9DBDC8DA2A8E123EULL, 0x329B2C73D20F2628ULL, 0xB8B394DB30A02FEDULL, 0x53FEAA965310F44AULL, 
            0x4535BE0DB1B1A8D9ULL, 0xFDD84CE9D664C761ULL, 0x4F5692CA70F7440BULL, 0x1943D25C4C750D91ULL, 
            0x388BFC1E01BED6A7ULL, 0x719E6FB8BA51FB08ULL, 0x1AE6E5F480F3E8C6ULL, 0xFE89F2853BB33D17ULL, 
            0xAEC4221F1E7A4B44ULL, 0x759C0D57DBF01A27ULL, 0xA6B15131A607C2C3ULL, 0xE56C7C505DFE8D93ULL
        },
        {
            0x996A78C9DD7B6777ULL, 0xDAB0740410A81B46ULL, 0x68E9B0CF6B3F8EEFULL, 0x3CA9B920465AC970ULL, 
            0xF143DBEEC28FA9D1ULL, 0x4F7C26EDEA518AF9ULL, 0xCE55628FFF366A6FULL, 0xF9A8154EE8E49E39ULL, 
            0xF7D8AEDD8940B3CFULL, 0x3B3756A475EC813AULL, 0xD0393612723FA1B1ULL, 0x03F8962FE7CECD08ULL, 
            0x4EB03C293AF3F8D4ULL, 0xCDB2DC70ABE75235ULL, 0xDB86E1DD24CD2BCEULL, 0x5FFA3FC726B23A15ULL, 
            0xC709B835DB3C48BEULL, 0x73853D0558DEAECBULL, 0xE1C3974977EAE308ULL, 0xEFFD740E2F8D61E0ULL, 
            0x29FF85032444F7BAULL, 0xA471EB373E2D8A2AULL, 0x9757498C38BAB55BULL, 0x2DFEA76203057B47ULL, 
            0x14F2F900B9577296ULL, 0xCEB45A7B36C68297ULL, 0x397D9A5A1AD02B37ULL, 0x43CC8F5EB861467EULL, 
            0xAF5792B5652947BCULL, 0xB7C4237D8DBF1787ULL, 0xA60AEBB00C5E87CCULL, 0xCA33E1C26EED01C6ULL
        },
        {
            0x5078DCDB7B1C8209ULL, 0x9B4CAEE8F50E6EA9ULL, 0x8C472745621FD115ULL, 0x0CE0B46C1BD7B137ULL, 
            0xAD44E69DEAA01D55ULL, 0xE49841F5DE483306ULL, 0x79BDDCC2A5E4C54AULL, 0xF185D51748D4DA9DULL, 
            0xD98B142802B60747ULL, 0xB9335E005B10E8C6ULL, 0x62DC26D041C93799ULL, 0x5F263B537D693CE4ULL, 
            0x1AC6C405D2948DE0ULL, 0x1EDF5E803A484830ULL, 0x994CD344AD1CF9C0ULL, 0x429FDCB11A0D0DE0ULL, 
            0x266FC5043E255445ULL, 0x8D386A9852DCCBD9ULL, 0xAC217A97009A0982ULL, 0x24A050B9672CA238ULL, 
            0xCD1AEF30BEF6ABD2ULL, 0xA1F7D77000244BD6ULL, 0x7C1606BD8CCEBD3BULL, 0x5A793E0510AF0855ULL, 
            0x532DE24904B041BEULL, 0xC69AE02ED1AD231BULL, 0x91FB2A8199F40DEDULL, 0xC9950ED14EE260A6ULL, 
            0xD6C37E9C0A3EFEE9ULL, 0xCC9795A022AAB25CULL, 0x5015D4B618109E95ULL, 0x7B8FD0081E529EFAULL
        },
        {
            0x83D62839D13F89EDULL, 0x44CB0FD164476182ULL, 0xCD0E5636C67EBDDBULL, 0x9C236A56E3DDC16DULL, 
            0xCADC7A185ED0AE71ULL, 0xB40A4403D1843FBCULL, 0xB630F507BFFA408EULL, 0xD12A7C05BD6CB709ULL, 
            0xA04488E696A9C88EULL, 0xCF525FDEA7995B21ULL, 0x962AC689CFF13B7DULL, 0xB1B2EDBF5F764C37ULL, 
            0x7899FA92075B0239ULL, 0xDCEF5D8C2EF0B82EULL, 0x6ABA56787AA3589AULL, 0xAF868B3910BB158FULL, 
            0xC6E76298B3DE1165ULL, 0x28166AD55174BF1AULL, 0xBD9D2BDFA06D6BD2ULL, 0x6A2A9A2431330766ULL, 
            0xB0FEB9E87C07105AULL, 0x66B67F4A49CD55EDULL, 0xB6C8D23B3EC12A57ULL, 0xC003E0BF3640260BULL, 
            0x86D52998B8B30596ULL, 0xC89CFDA22EBFEA8BULL, 0xE3776601C2AC07EBULL, 0xD3EE0A951F241710ULL, 
            0x75297F9F815A11FCULL, 0x367EB7FD3077EAC0ULL, 0x271724C00DA9BC83ULL, 0x7405C292F90309D6ULL
        }
    },
    {
        {
            0xAB6CD2EB1730D0ACULL, 0xF8C6D9A91DE2798FULL, 0xC8B170E3C52EA820ULL, 0xA381037D49955D43ULL, 
            0x4855A2D04BD82E13ULL, 0xC0372D0F7701E843ULL, 0xB7A1CE456B49D12DULL, 0xF772A49AE8CB2DF3ULL, 
            0xC262966CA79C9528ULL, 0x0D958E5808DC4CCAULL, 0xCB1F46AEA95F965EULL, 0xF717D8F3BDCA1314ULL, 
            0xC143D0AAA6CD11CCULL, 0xC7F605F451D83E0AULL, 0x84B0A2AEFB7D56B3ULL, 0x995BC8F3B556C3B0ULL, 
            0x6D5C9DCCDA941B4DULL, 0x93525AD0061E1512ULL, 0x295348AE6C250290ULL, 0xB92B4E12420DC012ULL, 
            0x79AC7ED402C29F4FULL, 0x1A8B2C9462EC62E3ULL, 0xD72A66DBBA1959A0ULL, 0xD2A0FA9D82697B71ULL, 
            0xCD6199E35D52DCD6ULL, 0x079F899F4EEC7262ULL, 0x606E30F291B1E880ULL, 0x5418CC284B82488FULL, 
            0x8D5DF58937661BF0ULL, 0xB0D52D71A128A72AULL, 0xD7E3203007A72153ULL, 0xFE27F4CBAD4D51A6ULL
        },
        {
            0x90CFD6C2C12C8C2AULL, 0x95115FD2C933FDA6ULL, 0x5DE671702FD60403ULL, 0x713FE2DE7E8ACE5CULL, 
            0x01A05241CD66AC56ULL, 0xB09DE2BA30F9642FULL, 0xF568F5F996E46A84ULL, 0x3CEFB9F510549E3CULL, 
            0xA601906D46AEC4EDULL, 0x40B363C7857FFD00ULL, 0xF066F045B0B6190EULL, 0x61FE56021E84B857ULL, 
            0x8A9E6BCF97C2B87EULL, 0x99611A0B8B6D3CDCULL, 0x6DC90CE88C61E2CDULL, 0x93CEF7BE50C3EC98ULL, 
            0x6AFF5E5C29861799ULL, 0x9FFADD8BA392C0D9ULL, 0xC8EE51CE3009606FULL, 0xBA7153B993821C54ULL, 
            0xDFA507EC6064B85EULL, 0x2E7AE9DE0AC0B518ULL, 0x9801DEFD8A62C5B3ULL, 0xAD06A4EB4F6C68D5ULL, 
            0xD2F861B2FFCE3783ULL, 0xCBB2A731E41FF9BFULL, 0xED3910417562195CULL, 0x83C8371837A7A70AULL, 
            0x21DB3BE10454935BULL, 0x16C978CE13DB9A24ULL, 0x5803AF75C26727D6ULL, 0x91741E598ADAD98CULL
        },
        {
            0x45AD55D0DF824AD2ULL, 0xE8719165559F0F2CULL, 0x8F868EB0224E113DULL, 0x8946E25A6B6B5933ULL, 
            0xA742BD5184B0D579ULL, 0xBA83D56E34EDC8CBULL, 0x25AC4FF5BAB49684ULL, 0x0A6F197C4717D42FULL, 
            0x15A0820088758D66ULL, 0x2371CA4D37E2A529ULL, 0x0C201EBECD3E2CA6ULL, 0xD3CA71065895BFA3ULL, 
            0x839DD41F03E5CF67ULL, 0x896523D4A49B2C9EULL, 0xA78B7BB931F25219ULL, 0xEB17F5C895CF469DULL, 
            0x54BA4530D6C3049BULL, 0x6AF92D485C06BF96ULL, 0x21ACAD0F49D80473ULL, 0xFB0826169023BE10ULL, 
            0x76D8577BD902C74FULL, 0xFFC64FFD9098A1B5ULL, 0xEEFE461D192AC044ULL, 0x9C8D58583749F6F3ULL, 
            0x6785AE7C24922BD5ULL, 0x2CD90DF1B2FB5169ULL, 0x9D296B908EC81422ULL, 0x284D7E6F05BD7734ULL, 
            0xCEE8C916F8D45283ULL, 0xDDF940E45B8319D6ULL, 0x432FF5692C2BBC37ULL, 0x0ACFFB93DC4EC01BULL
        },
        {
            0x3629C0257485D0F1ULL, 0x497A8734B10BA15AULL, 0xD02EDAF3A8BE39F7ULL, 0xDE4DEE401D590B81ULL, 
            0x2EBDF3BE8EC6A4B3ULL, 0x1AE290D36ACD8095ULL, 0x39DD1553C8827E06ULL, 0x349E143107690183ULL, 
            0x3674318B939A8BF5ULL, 0x361ABEFE039DC9BEULL, 0x4F523055E9D6AF8DULL, 0xAA760C154138A94FULL, 
            0xA99976C7E54B2B78ULL, 0x09346E13D18DCEFDULL, 0xD08FF5694859CC9AULL, 0x1BDD54D7462D35ECULL, 
            0xAFA1D54390A40C86ULL, 0x77E9C1772854E58CULL, 0xDD2D89AAAFFCFB30ULL, 0x8BF5E7A9A74E3A30ULL, 
            0xBB42CF3E08BD879FULL, 0xAB33BD24E3DFC165ULL, 0x31C849625D43F423ULL, 0x00D66107CA36B69BULL, 
            0x30A5B9241F675EEAULL, 0x6B5C96A0B10880C0ULL, 0x07B37EF4EE0DD8F6ULL, 0xE38660AF0FAC087BULL, 
            0xAFFBFF3E02ADD78BULL, 0x314EFF0B56B5B1DDULL, 0xD0474AEEB768B184ULL, 0x88B013C7DE34D92DULL
        },
        {
            0x8A82B56AFD34B9C1ULL, 0x74E78DB6466D3A6FULL, 0x9DF52E7C75020FCBULL, 0xE374D89315FC6B4FULL, 
            0xC2889ED505F31656ULL, 0x7E3D2B3018672CFFULL, 0x711E4F29C7B1E54BULL, 0x314539933C0F7D4CULL, 
            0x0DA6FE613346B547ULL, 0x0BA9B2BA6A9784AAULL, 0x8157EA00F67C27FCULL, 0x9A9E0266F0E318EEULL, 
            0xD4BC1861146E32B2ULL, 0xDDD70EAB8BA61213ULL, 0x57C5AC541EF1B217ULL, 0xFEC8ED978285DD3CULL, 
            0x413387CFE2201851ULL, 0x1387F4E616229AC8ULL, 0x755021E23D952067ULL, 0xEA83A201E7BA66EFULL, 
            0x4524B49992E56FC2ULL, 0xC0A5C0ED91043761ULL, 0x0751BD06501768CCULL, 0x41253B78879A2D89ULL, 
            0xEECF9CC55B30EF80ULL, 0x31DBD8FCC8EB26B8ULL, 0x3AE633E99E17B0AAULL, 0xBA1B36319A21BD8AULL, 
            0xDC4FCD9CF345FCE6ULL, 0x7D272F594CCD3F78ULL, 0xB9AF36543CB236D7ULL, 0x90512356BA96C2ADULL
        },
        {
            0xADC98CC4193BE87FULL, 0xC29C9D00970BB21FULL, 0x993B7200AC7840DBULL, 0x8E2C46789C67B58BULL, 
            0x9E401E31472A9206ULL, 0xF8A625FC9350F922ULL, 0x8BA2612F72BC9DC5ULL, 0x5B88AB166E7C490DULL, 
            0x8BF315C5659AC392ULL, 0xBD209F97A4F7C20AULL, 0x1AD44E12FF76E4E3ULL, 0x99ABD80A9514CB7EULL, 
            0x0138AD9827CD98A9ULL, 0xA929FAF0E1921CC4ULL, 0xD718C07E968C13E9ULL, 0xD68D00107160BE71ULL, 
            0xACA164DE1312C28CULL, 0x4858B9FC75D4F571ULL, 0x3210C79EED7553BCULL, 0xDC6F09649A89DC4CULL, 
            0xD5F2A967C7433AA8ULL, 0xE5F2030EB6994EB1ULL, 0x3C0BA396371D3168ULL, 0xDF91148E1BA3F5C0ULL, 
            0x081F35DF72AC8C86ULL, 0xB5BFE8E2FCD5247BULL, 0x90B7EB20948B77CCULL, 0x264FB8B1BE6CEA67ULL, 
            0x08D41AF24DB53DC1ULL, 0xCD7E941BDFCFFC70ULL, 0x2BCE1170D6E99A51ULL, 0xE3F4D80BDF62FA71ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseAConstants = {
    0xA73F3103092DA9EEULL,
    0xD6D71F8320E10783ULL,
    0x39B7D8FEED4D6718ULL,
    0xA73F3103092DA9EEULL,
    0xD6D71F8320E10783ULL,
    0x39B7D8FEED4D6718ULL,
    0xBB4195DE31300E59ULL,
    0x858C47AEEAB351B1ULL,
    0xE4,
    0xEF,
    0xF4,
    0x14,
    0x18,
    0x69,
    0xC3,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseBSalts = {
    {
        {
            0xCF5CE8BF16CEE671ULL, 0x9A57673ED611420CULL, 0x30E0B0F16415FF5CULL, 0xD9E9791E5D9FC4EAULL, 
            0xC21C366E3CE7E59CULL, 0x3F1052E5C28A5992ULL, 0xD1D653146C4FFA3FULL, 0x3B5D821493A12B74ULL, 
            0x6D0C10A2A3A82101ULL, 0xEA94BF2D086105E6ULL, 0x64774CD8F20AEB37ULL, 0x2E2EEF17DF708D53ULL, 
            0x19A8FD706B5CADF3ULL, 0xBD4A52E8CF497E16ULL, 0x9391BFCB36C64BE2ULL, 0xB5E8A26222B2EC2FULL, 
            0xF2184F8B68E6C80FULL, 0xFCE19F3421D5D191ULL, 0x2996385642545982ULL, 0xA6D2FF5B424B9509ULL, 
            0x5234CDB0EC27EF3AULL, 0x2871795A3121D366ULL, 0x38F4B13796BE75A7ULL, 0x2F900EF7485D025BULL, 
            0x9E91714F68DADCCCULL, 0x24E6BD04EB352E8EULL, 0x24F3AC2132003C33ULL, 0x9153C19E1D7ECAB7ULL, 
            0x97B898A7B9C3252FULL, 0x100100EC29195BD5ULL, 0xBD538A68C703EB39ULL, 0x12434AD5FCDF7814ULL
        },
        {
            0x2DE7AF464EDA8EB9ULL, 0x719D354173C81696ULL, 0x8924E51D93E6C561ULL, 0x9E920C3C59D9AA49ULL, 
            0xCB0836A4A09EC364ULL, 0x3135C5CE548B3BE0ULL, 0x4B8A1CF189E6611FULL, 0x29A029111AF51D4EULL, 
            0x047AEE678010ECECULL, 0xBADF546E52B92D97ULL, 0x8CA9764E4BAEE799ULL, 0xFC4F96C30FBF9083ULL, 
            0x106EC04FA1C0E66CULL, 0x831637BE4B00741BULL, 0xFF2F1B2EF7787723ULL, 0xE7056E68021A1E8FULL, 
            0x7D005A0965CEC5A0ULL, 0x7BFB58F3B49DE121ULL, 0x03610CB11E691C3FULL, 0xA7410BF20FB4F899ULL, 
            0xA06C1E8C131153A6ULL, 0xA27542C3201BB616ULL, 0x38FB97B51D3F8E96ULL, 0xA3C02E4AD848E149ULL, 
            0xEA8FBAA6CAA0B37AULL, 0x4C2414AD649D771AULL, 0xEE21B08C205056E1ULL, 0xAF64773F4E5B1C1BULL, 
            0x52E58157C1E9FC01ULL, 0xC4550427A411A2F8ULL, 0xF262AA91157AC9E3ULL, 0x0BDD5EA62E95AD3AULL
        },
        {
            0x098ED7B7B592E9A5ULL, 0x5B2ADB807537D8EEULL, 0xDEF697A112FD56B5ULL, 0x0C090B91111BCF37ULL, 
            0xE3E57B58B34ADEAFULL, 0xB31E3A1ED06B53F2ULL, 0xFCA1FDFD6F8CC242ULL, 0x484BCAA77EE93576ULL, 
            0x5FF8F5CEB6249DC2ULL, 0x74FD95518C5688C8ULL, 0x4EDC1F886EA866B6ULL, 0xAC1A99FBEE9CAF59ULL, 
            0x1F80DAEE43A5412AULL, 0xFCC2175175FDFCF2ULL, 0x895DB8A425446FBEULL, 0x0794FBC33B6E6761ULL, 
            0x0CA6DA9B547C4208ULL, 0x771C09301FBF3A83ULL, 0x9C474D886FFB7523ULL, 0x8985BB35CCB296AEULL, 
            0x3E41CECD6EBBE542ULL, 0xFA4AACF4003B391EULL, 0x6A8E7B0CC400D547ULL, 0xF39BA61F3DF0AE63ULL, 
            0x1FDAA81FE5F2114DULL, 0x29C730BC54CF881AULL, 0xC51B3FD239F054B1ULL, 0x35FE813CCEC1FCBFULL, 
            0x20A7E493AF5794C5ULL, 0x829892DD39766EA8ULL, 0x78E8DABBB2367428ULL, 0xFFA2040C3272E42DULL
        },
        {
            0xB7F4B1F8E5048D54ULL, 0xF2A890115EDCA142ULL, 0x068D7D3AC007AFABULL, 0x94A144E47664C3C9ULL, 
            0xD37B489EDA138585ULL, 0x3CDFBB63F1C1E7CDULL, 0x5E2EFF07D4B507E4ULL, 0x510B29DE9BD228D0ULL, 
            0x625FFFF8F6639DFEULL, 0xF1A7B0F380AC0F9AULL, 0xB2C6720D428D5EC7ULL, 0xA49826E3F1D4D25FULL, 
            0x78DD43995F69F77FULL, 0x4C1F87024496529FULL, 0x181209B601340484ULL, 0x236E4E1B648E6152ULL, 
            0x4F31E4AFD65884F3ULL, 0x620E27EB691B9134ULL, 0x0B2B162B5293C011ULL, 0x20C730A9DF322D7AULL, 
            0x007E4B300B81A711ULL, 0x22F26DA929ABBB92ULL, 0xBA5C46357A95D635ULL, 0x9A42545247055EAEULL, 
            0x2A97745008FD993CULL, 0xF893641ACEBE8874ULL, 0xD928A74E1052AF2AULL, 0xE5FC9A89D90D58D6ULL, 
            0x80D2FFE277023912ULL, 0x3AAB57D9CBE41BBAULL, 0x1BED53A50A5AB834ULL, 0x12654BCD5CD50BB2ULL
        },
        {
            0x4F3770C1A0C785D0ULL, 0x7F5B6F94C5596934ULL, 0x7A4A3BFAE9F8A9ABULL, 0xDD9CD02861242518ULL, 
            0x595696FAB43C5390ULL, 0xA61E6F05C9D96337ULL, 0x4EF892211A46335CULL, 0x8A69A2CCA3B4B621ULL, 
            0xA1E5830246EBEC0AULL, 0x9DD0B202B66D37BCULL, 0x813A4801EA493635ULL, 0x7D221F956D6935EEULL, 
            0x027093B5198E1FC6ULL, 0x82F499ED9AEB63F8ULL, 0xF9F345E1A0F0405AULL, 0x5483CD00A1312D3FULL, 
            0xB022A385548C37B2ULL, 0xD369C9FBCA015C47ULL, 0xB577A6A0228466EEULL, 0xA18930CB8F01803AULL, 
            0xD39C1D7817A9C69DULL, 0xEF3F19DE1C4A5F18ULL, 0xD8938590A4A32744ULL, 0xDB443802BEF84E60ULL, 
            0xA74E5CAE6EF4EF9EULL, 0xE99079CD037936ECULL, 0x6CE9B1A9C71ED75EULL, 0xA94A09E3974C0E27ULL, 
            0x48B79F6F12AF4239ULL, 0x8F948A1F225BECC4ULL, 0x6B1B404B9C252607ULL, 0xDFC8415E7645047EULL
        },
        {
            0xE42A9BADF894E49FULL, 0x35840C0D7C62CC61ULL, 0x77E6478F36A17C79ULL, 0x2B7D8C2DFECCF978ULL, 
            0x57E49F798DE7D20AULL, 0x575221FE29C3EEDAULL, 0x7C9B7696C3B43C6EULL, 0x72059BE03BB52B6FULL, 
            0x59BC840AB7DBF233ULL, 0x4ACA01A1FAB16B35ULL, 0x145C9E8A030BD0DAULL, 0x694A9D345716F5CEULL, 
            0x10919B44675B6C7EULL, 0x7A91A3F909D0FA18ULL, 0x7ED449859BA26F58ULL, 0xE9C93A1294BFD634ULL, 
            0xEB2DF7A591F3B0BCULL, 0x8D0A33B0CBBCE0F6ULL, 0x658BDE576341B057ULL, 0xD115326E05BC0DD5ULL, 
            0x084C3D65579C3320ULL, 0x67F472903C9A1DA6ULL, 0xFAE89D831E3D103CULL, 0x8476E562A52B6097ULL, 
            0x5CA10CD59E78E538ULL, 0x6E2FCD14971F21B4ULL, 0x60B393FBFE49C47AULL, 0xC68BA4EA137D1ED3ULL, 
            0xA28BC7DBE1FA4828ULL, 0xB191E07B7825E624ULL, 0x4DD10AFEC5401732ULL, 0xBC9B79BA97048B67ULL
        }
    },
    {
        {
            0xF754B15D970BF5D4ULL, 0x067397D764AB76A5ULL, 0x8B2875F5D23C7CF0ULL, 0xBFA64B3B5FDF2795ULL, 
            0xDA7A9C4EC21052D8ULL, 0xD65AA25E723EFF84ULL, 0xF16A116B944A79F5ULL, 0x45369D90CB86510CULL, 
            0x5BB5F62EAF8A593DULL, 0x663C4C2094DC71C2ULL, 0x751267617B753EFFULL, 0x704CC17E928DCC2BULL, 
            0xAA3E986F44C363BBULL, 0xD40484B304B51833ULL, 0xA4DDD36BBB4AADCBULL, 0x60BD070AA07CB256ULL, 
            0xE615BA869B863D5FULL, 0xE94A5BD8EAECD913ULL, 0x29C4087B1518BA3EULL, 0xC162AE876C103F63ULL, 
            0x38166471A44DAD69ULL, 0x79DBF3A21AA6D194ULL, 0x415B8434B034C91BULL, 0x7EEC2ED4462036B8ULL, 
            0xD473AD8A63D6C232ULL, 0x4D0CC6919DF0517FULL, 0x824BDC3DEC4B68F7ULL, 0xB6F9FC5C3F3AA026ULL, 
            0xA30F6EB80AE6C8B7ULL, 0xC8E519FCE0A64D8BULL, 0x2944AD5433FB87AEULL, 0x330243DBFD44FCF6ULL
        },
        {
            0x7F3201914043C30BULL, 0x01214F8D483DE28EULL, 0xE5E27D7EFF3527CCULL, 0xE2E6E07596646C52ULL, 
            0xEB65B1730CA2EE81ULL, 0x4CB53119B9FB53EBULL, 0x93A1446DDE667368ULL, 0xCDB9546C3AEB6D7CULL, 
            0xD495FC37E1140AC0ULL, 0xBAD74E49913C34EFULL, 0x7053C9E5B03F50AFULL, 0x50ECD31B1F258672ULL, 
            0x608136EF3CCF7F41ULL, 0x35016A589026028AULL, 0x1FF26A2B69AE749AULL, 0x4AE7F4FB9BF9BECCULL, 
            0xB9EC937C9D9A4880ULL, 0xD5F972DEFF974D6FULL, 0x7854A88D81D21EE5ULL, 0x1854D251CAB1F357ULL, 
            0x38EDBF778FD1A581ULL, 0x33B537C6B7633060ULL, 0x26CADBB988F552C1ULL, 0xBCC5E75D799B11C3ULL, 
            0x2B4E78E7A0BFEA1FULL, 0x957A754396208C43ULL, 0xBA4D2F3B5A6CF48BULL, 0xB51E5328E6B6FF66ULL, 
            0x865DBB9101B760A6ULL, 0x32925198DE1956A5ULL, 0x3E6BD81E8634BE8AULL, 0xA87761F634753F68ULL
        },
        {
            0xDB40D86F411E1BE7ULL, 0xCCDBFDB673097E8AULL, 0xD5913F88455365CFULL, 0x247E46F2813DF535ULL, 
            0xEB08A651204AA3B5ULL, 0x7CE44E9550A65F27ULL, 0xE6D792522CFD5D78ULL, 0x984F19870FFE5349ULL, 
            0xBE5673EAB57D1A92ULL, 0x7E7B081AD7215CDBULL, 0x8926C63F0AEBFDDAULL, 0x8BDFE369411D6A20ULL, 
            0xE0C6DE4A2FCDEAECULL, 0xB736BDB607791407ULL, 0xD4C49AC597512181ULL, 0x9F1AFC621372A283ULL, 
            0x325DB228B747BC4DULL, 0x48D739BA5E0198BBULL, 0x625CD63F5C42DD7EULL, 0xFE3DF82A6B04DD74ULL, 
            0x5A51215CCFAA52BDULL, 0xA5153B716F2C4875ULL, 0x71412D006D6474D4ULL, 0x60C0EF714CB7FF44ULL, 
            0x321735619BE4B596ULL, 0xC7CD809BC6023669ULL, 0xAAEFC4BB7217BBDCULL, 0xA874431A4E5EB0D1ULL, 
            0xE19394D5E0BCC0F3ULL, 0x4811A2B1F00C9138ULL, 0x49A67FEEEE19577BULL, 0x59E17C74E151F18AULL
        },
        {
            0xBB991EAC206A3DC9ULL, 0x22CF6A4E636BF155ULL, 0xF048B927530E8FAFULL, 0x792FF7BFE6172DE7ULL, 
            0x143BB14B1A65E9EEULL, 0x6A41C91693523BC1ULL, 0x9F71BA1482751F0DULL, 0xEBA3BD3E528F1953ULL, 
            0x420381697CE1BE81ULL, 0xB8C80C5D0553C881ULL, 0x33815421460EAEF7ULL, 0xC1C2BB2D8E920F3FULL, 
            0x19E0B1ACF4959B79ULL, 0x7005328F45748440ULL, 0x8B744A4F31CDC91FULL, 0x6E70D9A3B608BE81ULL, 
            0x6FE4CDC3E663113DULL, 0xB20485FC3667056BULL, 0xAD6D72310EC552F1ULL, 0xC8D8F6039FDE9B52ULL, 
            0x04A39DB6E2557207ULL, 0x460F50CD58E28ECEULL, 0x86371595FD12D3B6ULL, 0x8E245797462B6610ULL, 
            0xF75B023CAA954F7FULL, 0xFC1E1F4919BAF45EULL, 0xE8A63123448E31E8ULL, 0x5B95ACA206DBE780ULL, 
            0xC8F6EF943ED0145FULL, 0xC2DC0A834CD2C812ULL, 0xE62D21B0AF308AE3ULL, 0xC079CDEB5D61AF4AULL
        },
        {
            0xDAFD44511DD6A8F9ULL, 0x62572A8647C40C91ULL, 0xB3122A00AAD72D53ULL, 0x459460CB2C8595A1ULL, 
            0xDB7861A3ABDE415FULL, 0x2598CE1BD925F342ULL, 0x08E86CE01A6277BBULL, 0x52B4CC1057A0AAAEULL, 
            0x7198547DEF2F7F74ULL, 0xBCF14D37B952BBC9ULL, 0x69B6A53836F71A87ULL, 0xD496620E107F886DULL, 
            0xE97FC68FFA41439BULL, 0x4A8A92CCB6DF54B0ULL, 0x16A62FFC52D0281CULL, 0x6EEF6A76D8BDE7C2ULL, 
            0xDEA8E1F2C59BD0A1ULL, 0x42BCB0B86D51CB40ULL, 0xF3F74033B95E974CULL, 0x0FAE2018BC4EF2B1ULL, 
            0x9FA6D6EB45AAED86ULL, 0x4E3B20801D86BDCCULL, 0xB027443E0900F269ULL, 0xAD135887E6D9E821ULL, 
            0x33BC7EE0C1877CB7ULL, 0x9EDFF9A20F0164EAULL, 0x1B0CE879052F8E83ULL, 0xECD67D5D9B64A777ULL, 
            0x7BA162075DA1844FULL, 0x9B57B86CFC93D151ULL, 0xD42DF49016A16F21ULL, 0xC837486AB6A083E7ULL
        },
        {
            0x9AE804465CC254FDULL, 0xCCE0F14953B6B94CULL, 0x7A94064268D91C32ULL, 0xF188EFC65A1FAF86ULL, 
            0x451306363CC2DAA3ULL, 0x37691B45C14810C2ULL, 0xF8A031D56CE96BB3ULL, 0xE6B69F6239B31BA2ULL, 
            0xA1D03E7FCCD9D02BULL, 0x3D0437912E21866DULL, 0x4DB1DBBE3A131430ULL, 0x61DD4CDF484E4C58ULL, 
            0xA97843A632BB2DE0ULL, 0x245D970888C91A45ULL, 0xA1A0740FDFFEFCAEULL, 0x58B0603927003217ULL, 
            0xEE408401ABECE75AULL, 0xFD1DA4735B895C9CULL, 0x7A6D46F65AA78D1DULL, 0x454B2D014AE8CF83ULL, 
            0x2A2BBEE9539405EDULL, 0x93DF936E4D25E2C1ULL, 0xC5323A397514BB28ULL, 0x6C403EA88C891A3EULL, 
            0x8055E21C03A595ABULL, 0x4CB01BC0A553CCB6ULL, 0xCEE3DEFD27B8310EULL, 0x9DF7F9AD241100BAULL, 
            0x503442E67B39F410ULL, 0xC7826453FC4F1D79ULL, 0xCE0110C9E0D9DA80ULL, 0x4F26AFA0154E30C6ULL
        }
    },
    {
        {
            0x00A4CDE9F1DF7606ULL, 0xF8B4977362512676ULL, 0xBF4E4B7430B2C9FCULL, 0xBDA620E670739C5DULL, 
            0xB5E22B44D63B378DULL, 0x2ABDB22B9083F980ULL, 0xA7897AD491B66B28ULL, 0xAF8AF62FEC366C20ULL, 
            0x87B7FFE8A8B88AEFULL, 0x654C35984D4839C0ULL, 0xFB970061CF49A4B0ULL, 0xB575F4ED7F404E15ULL, 
            0x5D9EBA9F22026200ULL, 0x09BE5C57F0D534A7ULL, 0x5E85CAF2445F702CULL, 0x7721DCCC07896155ULL, 
            0x15A02EE864361D78ULL, 0x21C4DCD7530AA233ULL, 0x76A9DA9CCD1E6124ULL, 0x24E62D471C6F609AULL, 
            0x763C7E76C0F5C612ULL, 0x6959F259FE09C8E1ULL, 0x846B64A849DD1BABULL, 0xC1B7A8548E02B7A2ULL, 
            0x00D933F3FE6089A7ULL, 0x17A462B31C627332ULL, 0x2EEB89757882734EULL, 0x0D87DFDC6E79136EULL, 
            0xC7773D5462CE3D5DULL, 0xF338F0E43B274585ULL, 0x70434274542AA136ULL, 0xEA695BD4D614E2D0ULL
        },
        {
            0xE829FFB5DD44BC0EULL, 0x4B66DCDF31D10118ULL, 0xDA6BCDF4977BD571ULL, 0x6E1E5B8898F45847ULL, 
            0x0809A3F34C58AA04ULL, 0x7C2745E6E617C970ULL, 0xB8AE5B68EA1FF42DULL, 0x0A437CBDFE88AC1CULL, 
            0x11F1FE4CF19875C7ULL, 0xF996CA785AFE395CULL, 0x0BFC4F1AD8539A92ULL, 0x8DA5C64434F02CA9ULL, 
            0x42CF835AE9E2B91EULL, 0xF165D35A80315C26ULL, 0x7ACC0BDB775A72B9ULL, 0xF9F9B518E9738149ULL, 
            0xB46241825F13A867ULL, 0xFDCB1FFAD484579EULL, 0x5326D17A0F461E52ULL, 0xD3B5E6D9ED7768CAULL, 
            0x3487EA3BD6D09BB4ULL, 0xD0CB63F16AA97E6AULL, 0x7E7AABB42107A5F6ULL, 0xC87D5131F2D54A54ULL, 
            0x47BF39F5E6F1478AULL, 0xF934A05650423044ULL, 0xB8EA448862725CCDULL, 0x96385EBADD09C4A2ULL, 
            0xE88509AB64E41FE9ULL, 0x13F4AA44257C24EBULL, 0x12D1D2F730646065ULL, 0xDBE13F9C8DF53119ULL
        },
        {
            0x535246743130CAF4ULL, 0xF5E8C276AD880FB9ULL, 0x3BC001DD0FC1CDFAULL, 0xED517643BC58485EULL, 
            0x9D72F99682341544ULL, 0x561D3E13DC793AB4ULL, 0x8CAC8A30AB43C60EULL, 0xC037AAC27A904AECULL, 
            0x7CDA266C5150C4D1ULL, 0x0E03CA5CC9E65D4CULL, 0x62B67C77EB45BABEULL, 0x06138F5D04640F13ULL, 
            0x96728B40FC750FD9ULL, 0x9EFCE4D28102BAADULL, 0x3934F1CC424E4816ULL, 0x3B3730EF18E3142CULL, 
            0xF0137BF4591A777CULL, 0x4AC00E49AD4E293FULL, 0x420F526CCB05161FULL, 0x144924F226FDA76DULL, 
            0x9A1CB7C3E6E4DFB5ULL, 0x912402B38DE1DDA4ULL, 0x2AB1EADAB9F90920ULL, 0xA3DA7F40AB3D4697ULL, 
            0xAEF2EFAF3D96ADBAULL, 0xDA4AD9D2CC322062ULL, 0xC3307C7F6205B2ABULL, 0xFC49FF55642884B5ULL, 
            0x1B6C62C7B664F142ULL, 0x0DA4E75356E2AB1BULL, 0x0747A42D7A3C6ED1ULL, 0xA3FED2FCA8E0548EULL
        },
        {
            0xF585C61938EA2700ULL, 0x25AFF3D476681555ULL, 0xF26C91BC62255D88ULL, 0x60711B9360026E28ULL, 
            0x16BD4F5A90A6218EULL, 0x774A29248A646166ULL, 0xE740700F758EB171ULL, 0xE10159895DFF34EEULL, 
            0xB4E2D9F09F502713ULL, 0xF8B25B8045BAD92AULL, 0x8FD882684709A6CAULL, 0x9FB0B83DAA06FA65ULL, 
            0xE1D281604B114FDDULL, 0x99794B04E0832416ULL, 0x33EB40EEE864AE13ULL, 0x2971D3F04D01C9ADULL, 
            0x1BD1DF4A37ADFD48ULL, 0xD06B5444A11E937EULL, 0x35741AD4678C65D4ULL, 0x020D56533EA8FC85ULL, 
            0xFABED6CAC7BEA919ULL, 0x75971BCFD6A6698BULL, 0xC17DA2FE5B69B64FULL, 0x80DA08F6DBDCD9F6ULL, 
            0x95202AD3F9F181E9ULL, 0x9C843E6F3F60AD99ULL, 0x7DB8DC97C93B716BULL, 0x2A8E4C97DA4BBFF1ULL, 
            0xEC331FBD23857C27ULL, 0x5714589813D31354ULL, 0x0FA8A4857FF21993ULL, 0x13380551C30371FFULL
        },
        {
            0xAAB0741BFC09FB4FULL, 0xE3F5456A352B8539ULL, 0x4068C29ED053D059ULL, 0xEA518FC442282ADEULL, 
            0x9341310B6B136622ULL, 0xFA14DD75C33306B2ULL, 0x809B0781E1E3098AULL, 0xB435634CA0068C2FULL, 
            0x59D954EE85358120ULL, 0x7A6F085B4B57C0CCULL, 0x72C533889E3D01A0ULL, 0xB1EC16C06BB92CB6ULL, 
            0x898BD26466AA02EFULL, 0x659658EA16EBB11FULL, 0x4C3F3183EE7B51DCULL, 0x4DE0F3BC19D95E0EULL, 
            0x37F21948652ACAE2ULL, 0xB50545E7692A4AF4ULL, 0x090183C5B9CA9DB5ULL, 0x3B2BD04F665D4D03ULL, 
            0x10B326C407CBDBDAULL, 0x8C70FF93DA2745CBULL, 0x5A1D495E524575B3ULL, 0x7FAC48D3B0D48E92ULL, 
            0xB9E77634E67867CEULL, 0x4C859CC34D48D2BFULL, 0x454A0B9CDBA18EC2ULL, 0xD77C7518BDC0CE4EULL, 
            0x49E750B7A92923FDULL, 0xCDD113D040C863E1ULL, 0x411521133DF59356ULL, 0x2B05CE4CC8E03E9BULL
        },
        {
            0xAAAFC42C960F753FULL, 0x7829FCE4563F6C56ULL, 0x835DC2470AB0D96DULL, 0xB99B11E01CBE4B0BULL, 
            0x1135D41A9EC9B9C6ULL, 0x06E02EAEE3013939ULL, 0xA7E3BFEFE3A1B428ULL, 0x621922B82A4F4740ULL, 
            0x52946F8A9ED8FBCBULL, 0x0B8E8565FB48D69AULL, 0xE6B3C971B47E697CULL, 0xB6A2CD63037F7F6BULL, 
            0x36761530938703D0ULL, 0xC85B6D70C2F510CCULL, 0x187EC16010585CE7ULL, 0x8282D4AFC7D7EB3AULL, 
            0x15B209BEA9C0E966ULL, 0x4417D2BFE985047FULL, 0x9D607A297056CCD3ULL, 0x9563C6EFEF03D84AULL, 
            0x50CD784619AC9DBCULL, 0xE1B9F6EB9D034F48ULL, 0x38916B68D91C81B4ULL, 0xD83838D67C3D57B0ULL, 
            0xA1244AAE4AE23914ULL, 0x3F8E71C77E5260E8ULL, 0xF7968833C0522F13ULL, 0x1437D20EE1BAC572ULL, 
            0x61D9BC7886BB53F6ULL, 0x9D6397E1DE67508BULL, 0x68C004B25DD4EFDCULL, 0x9A10024EA6591754ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseBConstants = {
    0xDD3CDFD2D7C2A18CULL,
    0x0E0527743BD7106BULL,
    0x4BA1AB2F597DA968ULL,
    0xDD3CDFD2D7C2A18CULL,
    0x0E0527743BD7106BULL,
    0x4BA1AB2F597DA968ULL,
    0x4AB941C960A372D3ULL,
    0x0B65CA2B67D68663ULL,
    0xFF,
    0x7D,
    0x74,
    0x04,
    0x31,
    0x1D,
    0x11,
    0x23
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseCSalts = {
    {
        {
            0xA730F291107DA280ULL, 0xC29FFF376E37D81FULL, 0x46B452FC7C040FB6ULL, 0xFFCD9404ECD6D057ULL, 
            0x36A10FF3255A7535ULL, 0x93C342BBEB2BA7B8ULL, 0x4DD9C8BB0C4A4E07ULL, 0x0988C35940008E5FULL, 
            0xDA6A3C84B20D95E4ULL, 0x3EEB4B6D213955BAULL, 0xA0ED97CAA2816DECULL, 0x98A2B8E470084D32ULL, 
            0x381706A45B5F575EULL, 0x97573258CE34D65DULL, 0xDE7E5BC401EDD3B4ULL, 0xA604918D786D3C93ULL, 
            0xD8E65488E123B42BULL, 0x742D331A4E46B53BULL, 0xF73D67CAC029283AULL, 0x3CE4C8ABDF81A3AFULL, 
            0x4813265A61B82C3EULL, 0x808D86553376D737ULL, 0xEFFE433AC2A6B6BDULL, 0x067FB9ED731AB72DULL, 
            0x1A39F477BD63DD01ULL, 0x02AF6FEEDA3EBBD5ULL, 0x5AD0F570EA875EB5ULL, 0x40F06EB4017D78A0ULL, 
            0x76358E0B8BE19429ULL, 0x7183707E0E455995ULL, 0xCD3A2F57C9CB5747ULL, 0xE6B7E1E7F831A200ULL
        },
        {
            0x8F04D8D25B54BEF1ULL, 0x03612B214A2FE3D2ULL, 0x8C06B3D71690820DULL, 0x4AFCDEDF305CC4B4ULL, 
            0xA9868284969A69C7ULL, 0x185B0CAD98C437ABULL, 0xFB48C268F16E976DULL, 0xE4EEFAB266E6933DULL, 
            0xC8B7D548F89C388DULL, 0x87BF844E91EF9D7AULL, 0x059D8AB526CB7371ULL, 0x2C46687541187078ULL, 
            0x38273D235337FA29ULL, 0xF0B927FDB0381E19ULL, 0x9DD0A80970C68D72ULL, 0xA3B9B7AFF0100934ULL, 
            0x6AA18CC39708A876ULL, 0x1B7A68913AA56B3BULL, 0xA9880249289934EFULL, 0x200A44E768338010ULL, 
            0x5A37D17E7F665A24ULL, 0x928037C973CD098FULL, 0xB3C59459095DED81ULL, 0x1D3CB62429BA44ADULL, 
            0x86344A0A06634B31ULL, 0xD9C4AFEB422C7BF3ULL, 0x4D0850E10B9B1DB0ULL, 0xD609632F08B46694ULL, 
            0x96C12013A906CA4DULL, 0x4AC41C6FDDA7618BULL, 0x018112F30E56B1CFULL, 0x1166CF2093065564ULL
        },
        {
            0xCCF4F266098C656BULL, 0x59181F10C4C517D0ULL, 0xC03E72F38BEC90E3ULL, 0x63282FD2F14C1297ULL, 
            0xBFB0006F275C6700ULL, 0x9A623C255CB8DBFFULL, 0xF259AF3024CBBB33ULL, 0x966B8CF702859BF2ULL, 
            0xEC0BCDE7FF2E41C0ULL, 0xDFF93586CE814F67ULL, 0xD53CD174AE3C8012ULL, 0x2FDE9EF3364DC3AEULL, 
            0xD2999E466A754480ULL, 0xD04D95391C88F0CEULL, 0x322733B9ABAE96E4ULL, 0x23B3C548AA70A7B7ULL, 
            0xE5364005DE7D3EF9ULL, 0x0E78B4123D082121ULL, 0xB3937A2092F0AB34ULL, 0x41249E7F0B36899CULL, 
            0x522072B55D0907CAULL, 0x4EBBD8FDDE6E1931ULL, 0x6CFAAD0499F2EB28ULL, 0x2F5C3129D023CD9AULL, 
            0x83F0848292E5E4ADULL, 0x4A66CCF10B2CFA82ULL, 0x3BA74031603079ECULL, 0x8D399A033D9E4F59ULL, 
            0x1821779B1ED3DB17ULL, 0xBF0419DAACAD5656ULL, 0xBD132E4EE66A1357ULL, 0x3CF0EFDCF35A44EFULL
        },
        {
            0x405C44C44A048430ULL, 0x23BEF76808A8819DULL, 0x496371A49486F44AULL, 0x43FC082FCD9D6042ULL, 
            0x748B5C8ABBF7B71DULL, 0xAAD2DE6036223619ULL, 0x6E041D02950F7FAAULL, 0xE531BA37DECDC75BULL, 
            0xC35DFDFA2C137E90ULL, 0xE0C7793227BD98B5ULL, 0x19B1ADE6745C7DA2ULL, 0xA71C26A395A9A19CULL, 
            0x15906D6C85E284B3ULL, 0xDBFD985BF59251C4ULL, 0x7407C42435E30A91ULL, 0x36F491218EC76692ULL, 
            0x77180DBFCA5C48E9ULL, 0xC28A7542EAA30133ULL, 0xCB2A92D3E87F1CCAULL, 0xBFBACBD043754400ULL, 
            0xB6C24D3E09ACF74FULL, 0xAAF0C72A9196FDB6ULL, 0x435449F7F7BAB547ULL, 0x08320B43D8CD2607ULL, 
            0x19997AEEE88CF229ULL, 0x2EE830BB1CE0A9D1ULL, 0x9170C07CE060632EULL, 0x4107077E57542A23ULL, 
            0xA4732734D8935FC1ULL, 0xE40AA34D4EAAB49EULL, 0x2E9C66DA9CAAA47DULL, 0x41D763314CB065DBULL
        },
        {
            0xC8878BD7DBCC5FF4ULL, 0x9DB9656D88E99EEBULL, 0x1DFFB879A3960426ULL, 0x3D2A2F4F5EB43C6CULL, 
            0xF6DD728820AF04ABULL, 0x5574768A9AFD02DFULL, 0xCA5929D9A0FAD605ULL, 0x7DEFC52A81BA56D6ULL, 
            0xD9CF8FB734E5DA28ULL, 0xBA4DD655F0E8EE9BULL, 0x6E175942E8E0B8D5ULL, 0xF2C7CF211F4D08B0ULL, 
            0x257BA24DB8E12A3DULL, 0x44839D4A75A95CB8ULL, 0x80047EDB8C092F2DULL, 0xE24DB3FB45B1F974ULL, 
            0x451813072BD8B869ULL, 0x7B466041042C84E7ULL, 0xC519EB55145070A9ULL, 0xE99CEFB5251160C7ULL, 
            0x861C24252C853B23ULL, 0xFBA5C5A626A010ADULL, 0xBD8FFDFBECD5F445ULL, 0xFB772A82663EED5DULL, 
            0x633E77AD49602EC3ULL, 0x093185386BD94FDCULL, 0x45AC58C3B9D572FEULL, 0x0D0B7376427E0354ULL, 
            0x77586C19332393A0ULL, 0x9F39CB21B3A1657AULL, 0x01B1206CBF3D289FULL, 0x1A620148D8988A89ULL
        },
        {
            0x4EE95D8CF90035D2ULL, 0x8BDD8032F97D8E84ULL, 0xE709C4FFD9C58446ULL, 0x71840A833FB9E311ULL, 
            0x135D03C1EEF0D835ULL, 0x67D56FCD9C55DCFAULL, 0xAF98A8328375E865ULL, 0xCFEB752DBFAFE315ULL, 
            0xAFF32189B6780FC5ULL, 0xAC3A619082BAD0AFULL, 0x59C0FC771C141FFCULL, 0xDED8B65ED5CE824EULL, 
            0x089CCA434A13F12FULL, 0x3D425936A4D2513CULL, 0x7EA35028C946AC6CULL, 0xE4FD97EE2BD7F8D7ULL, 
            0x191B8FF41F4EA70EULL, 0x45A6FC0E7EE9E799ULL, 0x5E769F34E05002FAULL, 0xC8268F8D13D8F46DULL, 
            0xAC5F6B372AFBBF59ULL, 0x80CE66467093DA15ULL, 0x23C190E21DF061DEULL, 0x1679038EF67CE4DDULL, 
            0xB1A2465447B9AA49ULL, 0x1E6A27DE8EBB5932ULL, 0x16AE969FA8E9D19CULL, 0x6302482DA2DB5E43ULL, 
            0x821EDD7F4EE0D2D1ULL, 0xD743AA0982E237D9ULL, 0x9F0A0AFFC5191AE1ULL, 0x8BA8556FABD4323FULL
        }
    },
    {
        {
            0x18DA51E112B919F2ULL, 0x64E0B1ECEE986257ULL, 0xF2BA4A04D3643F5FULL, 0x97EA425466F82BABULL, 
            0xDAC15842844EC95FULL, 0x8F342458A61F020FULL, 0x40696C97C828CAA3ULL, 0xC24592D8199174BCULL, 
            0x1CA7D1A774255FD0ULL, 0xF6F2D07EA6D9C7FBULL, 0xBDD15E45E0ABD7A3ULL, 0x7CAD0A141606D296ULL, 
            0x2852380635CB6F48ULL, 0x901D5F2DDF5843CCULL, 0x4B8907EAC068BABDULL, 0x00A6C244FA09C54FULL, 
            0xD11F8111ABBE781DULL, 0x37B773FEB45BBABDULL, 0x15305E5B6F15166FULL, 0xF03A24A4894B502DULL, 
            0xE7551E6A4CD13ED4ULL, 0xF995540BD4674557ULL, 0x4328D4AA67F4BF2EULL, 0xD6A98AC061EFD94EULL, 
            0xC9CDB48F6F5D8291ULL, 0x1F58AB2554C4B604ULL, 0xD20030F4E23D8394ULL, 0xFEB4350FECCE2B33ULL, 
            0xFE983C527999F89DULL, 0x9E09A57C3AFEA0C6ULL, 0x67BB536E6312BC77ULL, 0x65282E55469A0837ULL
        },
        {
            0x6B96ACE122F3FD7EULL, 0x2F4D31C532FD5BE9ULL, 0xCBCEF0B91B07B770ULL, 0x1B874CD060B4C36CULL, 
            0x2E798D82A950A8F7ULL, 0x170C826A42CAF269ULL, 0x44B3980711303404ULL, 0x03DE73FB70C58A6CULL, 
            0xB987146AA881EC0AULL, 0x253DBA7FE7116D36ULL, 0x7FF4F44C28560A04ULL, 0x10DED7670DB57F98ULL, 
            0x7435BA69E39B2E02ULL, 0xF48AEF7CA47E4026ULL, 0x26B6C90F89113123ULL, 0xA4DD46387F589464ULL, 
            0x9A2DD5623C3FB3BBULL, 0x3E1B9D712F98C60EULL, 0xD551AF8852F670B8ULL, 0x5A8951026C3DE5C8ULL, 
            0x78AA435E9E422B83ULL, 0xFB934177A0C0384CULL, 0xEED173E18FF92C51ULL, 0xA57A5E9BEBCD25C9ULL, 
            0xA7D525952A62EE59ULL, 0x935D2DD16BECBBFAULL, 0xB75FE60291227D99ULL, 0x279C0A09FA83E320ULL, 
            0xFE112A15F4536651ULL, 0x81F5E2A8B5F871FFULL, 0x9F292842CF41D15FULL, 0x8AD1CA2927BA0DD0ULL
        },
        {
            0xAAE94305514AC383ULL, 0x654E641E7360B356ULL, 0xF71F24F25BD9FDCAULL, 0x03839D5D411488A9ULL, 
            0xC0DAC820B3195F39ULL, 0x53F5DAF36BF7CFFCULL, 0x9FCB4D8EB4558D66ULL, 0xF51CE0D1D7E8E955ULL, 
            0x54C534E780647A47ULL, 0x1FF2D5022ECED9B3ULL, 0x8BB22CA78A1DA26CULL, 0xB46CE345BAE76FFEULL, 
            0x19A3F8BBC991F2D3ULL, 0x44920502C905AF23ULL, 0xFFB3BFC96791FB90ULL, 0xDFFA1BB924F12C17ULL, 
            0x015B4630CB9A3DD8ULL, 0x62F9BAE444F6AF2CULL, 0xC958502497FAAEC3ULL, 0x89EA07E27AE46EC3ULL, 
            0x79011711AD601DA9ULL, 0xF8861B0E3294868CULL, 0x3EB8AB39F108AA72ULL, 0xAE8ABFA43C0000EBULL, 
            0x62598AC19C4902BDULL, 0x52E70D6A8CCDDFB3ULL, 0x0E6A0E65C62FDAC0ULL, 0x09433CEB090386E0ULL, 
            0x49DB52F4E6A46387ULL, 0xDD35FA977406549DULL, 0xBA1FE530C05EDAA1ULL, 0xFCDD812B1B053CE8ULL
        },
        {
            0xADED0721D4A504A2ULL, 0xF4000D6765731B5DULL, 0x0789D5A41FC1C9E0ULL, 0xBA62C7CF15FE8B74ULL, 
            0x9E64677161B638DBULL, 0x170E3F9E58C52F43ULL, 0xF2794D1C86487BD6ULL, 0xB106E701801C0365ULL, 
            0xD3E1D72168204750ULL, 0x1194C1001C43D71DULL, 0xAB599DC58D649EA2ULL, 0xCD5E20567CE5BCD0ULL, 
            0x93FFDEC4B43F079BULL, 0x87A8F3458CF56B86ULL, 0xF4F020E90FEC6BCFULL, 0xA113AE3DAA7E0071ULL, 
            0xA789147B29D1D5E8ULL, 0x30FD13CEE7EB906CULL, 0x985F9B751DC67352ULL, 0xEAD42949CF6F5CD8ULL, 
            0xDE889B5F874BCD39ULL, 0x4BCFAAFF946AC705ULL, 0xE00003A6F633D53DULL, 0x6094646DEB0EF0FCULL, 
            0x43E28BCDE70F64DCULL, 0x8B82415C77F6792DULL, 0x016C0F1439D768D1ULL, 0x6B9BAA8C26711D58ULL, 
            0x1005C96168D9AAA5ULL, 0xFAF369BEE825018DULL, 0xFE2362B8312D5B95ULL, 0xE31CC5744993D510ULL
        },
        {
            0xBB92E4DADB6D972FULL, 0xA6E6DB3626740A8BULL, 0x3FEE196D5DA6741EULL, 0x3FC302CFCD2D1305ULL, 
            0x2646EF3E9FF54478ULL, 0x3993E5B97AEB625FULL, 0x6174285B1419D634ULL, 0x99FE9BEC7E69768BULL, 
            0xF990C0F134C333D2ULL, 0xA419BD385E3DF482ULL, 0x4D15DBABB1D3FD25ULL, 0x83C6249EFEB93A09ULL, 
            0x1174511ABE0635C9ULL, 0x51744B8E12359893ULL, 0x6FF9D8CFB28721ABULL, 0x4A0E798B67AB880DULL, 
            0x2088BE86AB989AB0ULL, 0x7AED8CEFD7C7F6FFULL, 0xC32FCCDA44EAE20EULL, 0x78B4B63D8A1BD5D6ULL, 
            0x8F5C4A5A14E844D9ULL, 0x9C68AD6037204094ULL, 0x6148910FFE2A7247ULL, 0x399DEB4FDF5539FFULL, 
            0xFE3C80C5208E221BULL, 0x829F2146F82231F1ULL, 0xDB4D378E85A5BBA2ULL, 0x79D4EDD8D10E89F6ULL, 
            0xC750E0A103E49779ULL, 0x80724C100CEEFEFEULL, 0xA65C4ABF8C5384AAULL, 0x21EA72725AB19E98ULL
        },
        {
            0xAAE8A35034C0911FULL, 0x9D60DC4C4CCFAF85ULL, 0x8F45DC598CA3287FULL, 0x577D489455B98E2DULL, 
            0xD9E2777468555768ULL, 0x93B5481036F87C93ULL, 0x99EC8E4CCDF76B3AULL, 0x2172A28241B76953ULL, 
            0x96BD726F1ADB1FB7ULL, 0x6DAEF55671EEC961ULL, 0xFF4253AF59A77ACCULL, 0x8A371BEB0E0A042DULL, 
            0x62CAA656780DD693ULL, 0x9DC06D877F330FEEULL, 0x72E7DE83031F32E3ULL, 0xC524C287F8C80B2DULL, 
            0x688254C1BD32DEDAULL, 0x67D70201E084785EULL, 0xE7CD8D3C1709B35BULL, 0x3DCD7B86EBBE27B5ULL, 
            0xB008EF2528DE7AACULL, 0xE23FA74DE89C5818ULL, 0xFC8F1FA133013EB1ULL, 0x55145AF0012B0B04ULL, 
            0x986BB78C5AFAEE4DULL, 0xD4206B4D90460C99ULL, 0xE8DC086C56F94AADULL, 0xCACE73601B9E1283ULL, 
            0x1E1C75140CB795F7ULL, 0xB9F57FCBF4914643ULL, 0xEA93D63F07AD95F0ULL, 0xE924865133CBAE33ULL
        }
    },
    {
        {
            0xDA914AB4CFE95050ULL, 0xFC0DA115E4F20436ULL, 0x80A47E6D001BA00EULL, 0xA79D199E28BADC72ULL, 
            0xA212EA19D50CA015ULL, 0xBCD9583FE8DA7680ULL, 0xD709BD44C289AB07ULL, 0x65576E19F30E1B12ULL, 
            0xE8DCA8EC0CE1D207ULL, 0xDF7BA91AF6A951C0ULL, 0x15BE36503A808236ULL, 0x12800EADABBB976DULL, 
            0x642915558D433E2BULL, 0x40D4AD76A88B5013ULL, 0xC95BE182A8BC954FULL, 0x35B76E6C493777B2ULL, 
            0xE7764206B348E25AULL, 0x62A3F759FE40D67BULL, 0xF4B187D329027EB3ULL, 0xB0E10C04136B0D5CULL, 
            0xE8E2896650DD25B5ULL, 0x6470F861EEE46173ULL, 0x6DEA50E7DBB897BCULL, 0xEE0B46F7516AF0EBULL, 
            0x04D070ECA650A5CFULL, 0xC384640187C631B5ULL, 0xD1D9F9B947AF04A7ULL, 0x4CEBEC10E8C8E957ULL, 
            0x69ECA5B8462539FAULL, 0x2F45B6B07F656D6CULL, 0x9829B7197B207D1FULL, 0x10E4ED937697793BULL
        },
        {
            0x2BBCFC12D3435B61ULL, 0xFFD0FFD23965A536ULL, 0x50F6E00CE385D075ULL, 0x0D22DEF59962B3F5ULL, 
            0xC8F34F688CAD7DB1ULL, 0x94349CFFD7F80177ULL, 0x26F76CF91E12E429ULL, 0xE9B46D1AA00745C4ULL, 
            0xCD9AD519176C0764ULL, 0x982021B97DA2BF38ULL, 0x357AC71808BCE776ULL, 0x87F29CC039BADAEAULL, 
            0xDED77E09A4C42D67ULL, 0x736C99CD37F3E0CDULL, 0x35DDE07F28765B25ULL, 0x8D1035790D702047ULL, 
            0xB9371D9EBD3B0DF4ULL, 0x2848AE366E9F699AULL, 0xFE465F2415367327ULL, 0xB87529B91C3CA172ULL, 
            0xB7635BEEFFFE7A94ULL, 0xBA34F196A5F4A5C1ULL, 0x5973A673B6F99D2AULL, 0xBE64CB0A6E1DEA54ULL, 
            0xD6E7C2EA6CFD1CBDULL, 0x2A7D89442CD0AA34ULL, 0x21E3275F133C70EFULL, 0x4937B3503772C3E4ULL, 
            0x43D2BE0000579628ULL, 0x90744BD1551D6D3CULL, 0xCD04DC099827ABF4ULL, 0x010CB77AA5DE430AULL
        },
        {
            0xFD74BAAE99E44B88ULL, 0xBECC343C981D5F31ULL, 0xFFB0BD1F6E624A83ULL, 0xE66CC8670DE3D83AULL, 
            0x0F5D5365FDE9EED9ULL, 0x6F415C39D748AEE5ULL, 0xE267C69FDDCE7BB4ULL, 0xF7C76EA3531ADA3AULL, 
            0x966E20C658D4CE4AULL, 0x3B8D7418CB9656B1ULL, 0x87F4D56D0DBC93DBULL, 0x7DAFC337E8DC9910ULL, 
            0x9D73FAE49D741B7CULL, 0x79446CBF0FDCC560ULL, 0x5AA6B6B679BB97F5ULL, 0x48C9A2219C820BEDULL, 
            0x8819C977BE02A979ULL, 0xA18D17C9276D11DAULL, 0x6E0E6EC27924A27AULL, 0x91E5CAF140EE5B0FULL, 
            0x5EEC8EEC7B21CBB6ULL, 0x6E13204673C06111ULL, 0x38C22B730D4A0966ULL, 0x6DD5914EF3E82C13ULL, 
            0x4B13AC1A8C144491ULL, 0xA33083A73887F57CULL, 0x20AF575BF3E1E1FAULL, 0x9FADC379010B96A5ULL, 
            0xA456671E213B1479ULL, 0x1B6B711AA75B7AA0ULL, 0xD26DA57BE9858F8DULL, 0x034127894587A6CCULL
        },
        {
            0x898FB0EB997714EAULL, 0x616B9FBF277C8E44ULL, 0x23C507388B66421CULL, 0x18D672302D2B65B8ULL, 
            0x3E986B7E46C0E8E7ULL, 0x074216C92F14A48AULL, 0xEC8AAA90E8CD357AULL, 0x7EFD08DBD12B0A29ULL, 
            0x114BA035DBB497A5ULL, 0xCF4653C601DB642EULL, 0x40C5C89313932EDAULL, 0xD47FC1D8F7C7C882ULL, 
            0xC6C2435CEB57C105ULL, 0x54CFEA6A831820D0ULL, 0xB569AC5F4D675AD5ULL, 0x44A490FA59568AA5ULL, 
            0x0D47D7F81C690A68ULL, 0x178634987E8B7AACULL, 0xF913558DEA922199ULL, 0x3289D10CBEDFDA4AULL, 
            0xF0D2F70F0AE4E718ULL, 0xA257E693BA6ACCAFULL, 0x79F8FFB5A086DD7BULL, 0xAE3BF0D36034B969ULL, 
            0xB55346A3E68217DAULL, 0x5DE1427165715E61ULL, 0x44BA2AC994CD202FULL, 0xBAE14E37B0995990ULL, 
            0x01EAEAEE7BAFEE30ULL, 0x666763F9E025DD04ULL, 0xFF6533DCA187EF40ULL, 0x06DC8AE503093EE9ULL
        },
        {
            0x9C341749088E645CULL, 0x02ADE8CD7F6E48A5ULL, 0xF6CBC26F1D82C74EULL, 0x6A785E31DAF1B6DCULL, 
            0x2E3F85DF1ACFD8B5ULL, 0x71AC0A9D3AF537B2ULL, 0x11F3E71106D1B84BULL, 0x5CEC08709DB223D2ULL, 
            0xD28FE9881336AA17ULL, 0xA0C31ED4BB00622DULL, 0x47379707AEE44944ULL, 0xECEBC802C2E6F099ULL, 
            0x6252174A2516C0FAULL, 0x1FD337DD428A5BD0ULL, 0x70A5F7D74F79B32BULL, 0x74119D5B5FA9A7FDULL, 
            0x60D997344FFC314DULL, 0x33854AE3B12B3090ULL, 0xBDB5D2BCAF0EFD3DULL, 0xD95859A8F50F11ECULL, 
            0xA362DA1B22B56711ULL, 0x23B75FF2A9C7E461ULL, 0x27514CDBFAE0982FULL, 0xC36CF5394EA683D0ULL, 
            0x981B3380D1160672ULL, 0xAB5272E792F803A4ULL, 0x19744058B223A081ULL, 0x51B3E3595829A7F8ULL, 
            0x9E4BA993C7B90504ULL, 0x3EBD56721B1545CBULL, 0x66776120BCAA0C57ULL, 0xD6A0F4DA4524E330ULL
        },
        {
            0x6262724AC922A202ULL, 0xA94D6467725E0F3AULL, 0x07664C426638FBECULL, 0x5E2DE7476252C192ULL, 
            0xC961F70F25D663B5ULL, 0x6D396C12243D3B65ULL, 0xD1C810A961A54249ULL, 0x12C8168D13DB7FE0ULL, 
            0xC15C6C723BA0D2DBULL, 0x1641D1A18E9CC2F4ULL, 0x704A51608D36C03DULL, 0xBDC46ABF82D6679CULL, 
            0x050B7C7C146E8C75ULL, 0xB948B3BDAF95AC85ULL, 0x31254D949812D438ULL, 0xD8E139970590303CULL, 
            0x43C0C2B03E418D65ULL, 0x3E2A9F7A07BFE3E0ULL, 0x9D95EA66D0E2BC2BULL, 0xFB5DC01A396C5F6CULL, 
            0x549120A908CDB5BFULL, 0xA94C482C31D0B81EULL, 0x838A81E08C231411ULL, 0x195C9972EE8B28B9ULL, 
            0xA98FD1A817F89ECCULL, 0x9897FE576D6DCAD4ULL, 0x5F37BAA8C0779797ULL, 0x50F3702CFF8DAC2EULL, 
            0x02A8FCF3FF45D411ULL, 0x084A24B69E48671CULL, 0x2BF0B06C8589B8AFULL, 0xC002732A31FCEBC4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseCConstants = {
    0x09FF7F91D005B828ULL,
    0x8B60F7C7BCBE1BA0ULL,
    0xCA96EC42D83861FBULL,
    0x09FF7F91D005B828ULL,
    0x8B60F7C7BCBE1BA0ULL,
    0xCA96EC42D83861FBULL,
    0xC32C0A8146FD4F3AULL,
    0x897036934280BDFBULL,
    0x8C,
    0x27,
    0x8E,
    0x7F,
    0xFE,
    0xE5,
    0x31,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseDSalts = {
    {
        {
            0xBE43A90F9390E442ULL, 0xC65BD97961ABA0C4ULL, 0xCC42EFE884475981ULL, 0x5E6D2002A7FB1E95ULL, 
            0x703EF225DD5B3E60ULL, 0x180F705FF074A9D9ULL, 0x74649B3940AB61D4ULL, 0xEBAECEBF52394207ULL, 
            0x9C3034799899D95FULL, 0xC164674EB9F8419FULL, 0x04C657F211EAAC90ULL, 0x156506D96689BB75ULL, 
            0x3E2FCEE3BABD24C2ULL, 0xB901BA83BCCC7A43ULL, 0x5BB3098BFC4EFA84ULL, 0x5BEF9C993FE4773DULL, 
            0xB5D49C1D30C304F7ULL, 0x6165458A1AE7079DULL, 0xC23E868032066F6EULL, 0x5DAB3176AB5A3372ULL, 
            0x8FBEE08AEE35B2C4ULL, 0x8E2CD3BE3EE5DCB7ULL, 0x835AB696120521F2ULL, 0x7C914EC6C15A5F46ULL, 
            0xAF46CFA1B2152645ULL, 0xC9B3113213181C26ULL, 0x2B873FEEB5D6CC3CULL, 0x046973E859BED9DDULL, 
            0x7853FB04FB02204AULL, 0x4B6383EB6F89D428ULL, 0x86EB7BE9C0DEFC56ULL, 0x043BFC5DEF4DF199ULL
        },
        {
            0x645CEDA46DEDC687ULL, 0x75BF77297FA76C8DULL, 0xECB651D9F2E64EE5ULL, 0x986CD54771C89A5EULL, 
            0x76FE33FFE19BF43DULL, 0x10C61F6507EB466BULL, 0xD28500449F1B6C73ULL, 0x30DBAAE429C6E75BULL, 
            0x97373752BE9FE237ULL, 0x9EFED104CB0D3A9EULL, 0xE32338315152EA68ULL, 0x7B5DAE59072CBDC2ULL, 
            0x4A9EE8D6DD8D9C9DULL, 0x5C6756E37BAA24EAULL, 0xAE39B6FA781A1A41ULL, 0x5B15C21D37CE0F0DULL, 
            0xD58204508FED4102ULL, 0x5675E0271E9DF80DULL, 0x266C4F4BFD1857DAULL, 0xB4B4C0FEF56808A5ULL, 
            0x7A502A72EDE9E27DULL, 0xF9F39617EE3BE372ULL, 0x7605E5FC0C6EA407ULL, 0x6E75FE3C29277A05ULL, 
            0xA1BE4DAE2BAFA2A2ULL, 0x900240B966DBB8ECULL, 0x102987468BDE7C73ULL, 0x1A8112D26150BCB1ULL, 
            0x69CDBB7FBEA16DC6ULL, 0x09471ACE2088F495ULL, 0xB01D4F446A1EF242ULL, 0xA0863615579678F1ULL
        },
        {
            0x9E81DD41C42DE331ULL, 0xA4F8330963F96DD9ULL, 0x8A59662D4886BFDAULL, 0xC8C6FE8BA7F93EE2ULL, 
            0x44B877BAF61CD502ULL, 0x5C93E49DF95661F7ULL, 0xCA46193E9CEE81EEULL, 0x929476D7175F577BULL, 
            0xE4E1EC8C7809EDF5ULL, 0xBB96C9439BFD76C5ULL, 0xEEC63CD3AF6A5AF4ULL, 0xD890B5295A775EA0ULL, 
            0x0B496052E8699753ULL, 0x6CA817E31658C525ULL, 0x0CD1FC3EE0F1D6D5ULL, 0x2C00728CC2586343ULL, 
            0xB4184FE1793E7EF6ULL, 0x449F352067D506A8ULL, 0xABED2346ACF9A939ULL, 0x06C148A43D09B622ULL, 
            0xDE586E528D3ABF30ULL, 0xDC2E57EDD74D0F04ULL, 0x0CF49044491BE04BULL, 0xA788B2C57A7610DCULL, 
            0x6D386D661A16A5C1ULL, 0x8703A70B40786ED6ULL, 0xD12FF83F404503E8ULL, 0xE0C807D21B0B5192ULL, 
            0xB2B01356495219DCULL, 0x709B6DC7BC731A2AULL, 0xE1A7664F81DCE164ULL, 0x935A78A7F8082289ULL
        },
        {
            0xF55E368C8FF43D79ULL, 0x45996615ADD5640EULL, 0x852A3CF8F88C88EAULL, 0x2952801B8514D4ABULL, 
            0x31E8F73E95D3A5A7ULL, 0xC00C0156BF95DA04ULL, 0x3CF1FF3EF3C41FC4ULL, 0x32B43857DB6117CAULL, 
            0x757F23C206979969ULL, 0x4284B34D3EF917A2ULL, 0x7EC2846F9A304DC1ULL, 0xF18EC957A9A188DDULL, 
            0xC8A96515BAA7BC25ULL, 0xA4D6E93D26756597ULL, 0x342029C1DA670A3AULL, 0xE4D1D7093A985679ULL, 
            0xF39DF5E3B5F69BF7ULL, 0x258AD6A7142A5A41ULL, 0xE5B736F86FADB416ULL, 0x49490EBE888FF618ULL, 
            0x6221FC0F1CE18873ULL, 0xD53FB76EE2D97289ULL, 0x9D9764AE4724CF29ULL, 0x69B3CD69D473BCCFULL, 
            0x6A6A2451F3B75705ULL, 0x2DE7FE4C9D5A5A91ULL, 0xFDB6482330EDD864ULL, 0x65E9E9F4E231D9A0ULL, 
            0x28A9EC261B39647AULL, 0x0EEBABF8D451EA6AULL, 0x8374F98BFFA3A849ULL, 0x5EE24EE5936CD845ULL
        },
        {
            0x631BC98C864D4D0EULL, 0x288DCE97D627C88EULL, 0xECB32B5204B8567EULL, 0xE0B15D7A1CA041E6ULL, 
            0x74E12DBFAFCB066AULL, 0x0D9CFAF82A28A489ULL, 0x960CE5D692178933ULL, 0x1734427E1A89A95CULL, 
            0xE916BCD92C575B6FULL, 0x7DA6F61883D50C4FULL, 0x97950A92B5E41448ULL, 0x015D9D42BCBE4AA1ULL, 
            0xBA2388F8DFBB18AAULL, 0xE81BE3FC18D449A3ULL, 0x39091810C23BC7B0ULL, 0x4378EDA36209FF35ULL, 
            0x9243311A998155C3ULL, 0x3144980262B948DDULL, 0x8F8673E469C8D3BDULL, 0x10DAAAE0D167891DULL, 
            0xCF0E27A2413A49E8ULL, 0x3060EAE75262E9B8ULL, 0x88818387D522436CULL, 0xC6CAD6D8139EB19FULL, 
            0x49F96B832F8580A0ULL, 0x709C057FB3B9A378ULL, 0x530CEF35265A49D2ULL, 0xBDFFFBBAB54AA8C5ULL, 
            0xF45D7C318AF5760AULL, 0x0363BABA3C9D8984ULL, 0xA67546B5D4E24DF6ULL, 0x71CD52F15E3C04AFULL
        },
        {
            0x2AE6DCF867E651ECULL, 0xF86BEE760BD44965ULL, 0xF11C5993492A163EULL, 0xD0A2A543D621805BULL, 
            0x2BE55902D241EACDULL, 0x27130848C871F936ULL, 0xE5D0BF68E2A7D297ULL, 0x3843A93122D5F577ULL, 
            0xD2BE6AB5E8F26321ULL, 0xF63265F1ACEAC344ULL, 0x60563B87478DBEB5ULL, 0x1D257A5E99B68A06ULL, 
            0xC319D2558D32EB43ULL, 0xDDD0DF51803FA755ULL, 0x53C09AB7F302CCA9ULL, 0xE8BB732478950F01ULL, 
            0x9D313F60879CB115ULL, 0xBB1FC043F8F458BAULL, 0x291EA6B4E2C0E1E1ULL, 0xD519D338B275C103ULL, 
            0xBA927CBD5EE03CDAULL, 0x38F1F34B83C7D648ULL, 0x97D59985D9B6163DULL, 0x3FC150E527E2FD44ULL, 
            0xB7016273BBA3F8AFULL, 0x596DD969ECABB02AULL, 0x6221B95AEE6CEB9AULL, 0x0EC3780A4B2F0734ULL, 
            0xE4043205A3CD93D2ULL, 0xDC840B165765F61FULL, 0x009FAB60A772D6A2ULL, 0xFD9989446C79C12CULL
        }
    },
    {
        {
            0xAFDB7817A20728FFULL, 0xA558271D9BA1634EULL, 0x17D789F179FB3B26ULL, 0xB1173B4E0DB152D5ULL, 
            0x9584EDCF92ED406CULL, 0xF7D5A82BBAC097ADULL, 0x474C568571B2B238ULL, 0x3FD7339FF8FD0672ULL, 
            0x568B2EA5111439DAULL, 0x221DFBA868134274ULL, 0xC76A8985AF668630ULL, 0x1677BFDF3BF4F405ULL, 
            0xBB2AF61DB77D5D13ULL, 0xD5238FE2E8812EC6ULL, 0x73A0390E776F3D81ULL, 0x3CC10993D688F80AULL, 
            0x147623C0E75028AAULL, 0x179CF15E41D5B1F9ULL, 0x2A51960AFB7888BAULL, 0x66ACC6B18DB78E77ULL, 
            0x919BF56715CA75E9ULL, 0x0ED81135109496C1ULL, 0x2CFEE2008B00EE14ULL, 0x522D731A7D8BC886ULL, 
            0xDCE79531B9D548E9ULL, 0x80BA846655DDCE21ULL, 0x88A88F49E4021CE7ULL, 0x01CB4955FB3A5B51ULL, 
            0xF1711524EE74495AULL, 0xF085F53B6EB480EBULL, 0xBFCB9998F80655A1ULL, 0x7DE886C5BC29FEFEULL
        },
        {
            0xF97624A6B13BBA8FULL, 0x642BB1272395761DULL, 0xBD2E64ACE1DBC287ULL, 0x03278957369638F2ULL, 
            0xD3FF73B90F071BA7ULL, 0x07F3F0BAB4EED759ULL, 0x4ECF88BCBF92617AULL, 0xD69ECA50AC9B0EFFULL, 
            0xEA83ECA116B7DA51ULL, 0x55A3973768BA5314ULL, 0xF040E3ABC20D4A18ULL, 0x1948B199F28074FDULL, 
            0xBD3EC6CEBF3FD734ULL, 0x9AED31766BDD11B4ULL, 0x4DE958616F01CD5EULL, 0x35A1938A3456E92BULL, 
            0x407C9AF8C19107D2ULL, 0x9C6AEBD37C7AA67EULL, 0x578027BD16EE125DULL, 0x9F3A312425F49CBBULL, 
            0xDF8FF71FF0C74831ULL, 0x82F9F41067E1BF4AULL, 0x00E3A5B48545B330ULL, 0x9D3B20699BCDFBA2ULL, 
            0x5D40ED1AB4C841CCULL, 0x482E8D80C7150EDAULL, 0xD7FBE0CBC4C7C486ULL, 0x2DE14A44FA8189B4ULL, 
            0x488A712E7632DB98ULL, 0xD394B9220581071EULL, 0x714875197D426BDAULL, 0x410D2FBCC1DB0446ULL
        },
        {
            0x320BFFF60AB9BFA4ULL, 0x077592CF6ABE0095ULL, 0xD9602CAA56BDB8FAULL, 0xCF8580D89775DFF5ULL, 
            0xDE6D2F11264FE4D7ULL, 0xCE949169F242347EULL, 0xB0D4FFA44A75D2B7ULL, 0x9DF8969F417D2CBFULL, 
            0xE9D2ED4BB01A290BULL, 0x5BA9B39B131ACA3EULL, 0x961BAC15D470FB6FULL, 0xADCD7E480A0AE736ULL, 
            0xC12A54DCF93D5021ULL, 0xBF8971B8BF02AD50ULL, 0x345FFE6073CA3969ULL, 0x1BDFAE5E1B2EF304ULL, 
            0x0F568AA085A5DB7DULL, 0xA2F5DA8D341337D0ULL, 0x1ACEAF9A87F7AC8AULL, 0x9F8623A58B6E7366ULL, 
            0x0947131D50FB57B1ULL, 0x80686A53F5AE705AULL, 0x6D3D4053CFC730B9ULL, 0x6D710CFE62B0C2EFULL, 
            0x18E2C2F6E9AC6821ULL, 0x815D8AF987FFD98DULL, 0xED39442C725A7DAFULL, 0x5FC3880E29E7BCBAULL, 
            0x07847F73D1845DAEULL, 0xA38944D377FFC4F2ULL, 0x2483F3BA055675D2ULL, 0xE427D3FEB992D609ULL
        },
        {
            0x8BA3E20E195805F0ULL, 0xF3C0BD4421261299ULL, 0x44FF3F7918F8B194ULL, 0x64790722C8748D36ULL, 
            0xA8C117AB3B1D27F7ULL, 0xF9F629D3EBE5B625ULL, 0xD04E2C196801E02EULL, 0x93A72EEFCE1459EFULL, 
            0x5985E484B81A86F5ULL, 0x688821AB4395A4F9ULL, 0xAEDC34CC5F0FD200ULL, 0xE280D0620CF0AF5CULL, 
            0xFF98F3814B5FCEB2ULL, 0x892ED9BAE2FFB437ULL, 0x367ED42C0CD06FD4ULL, 0x4DBF9BC9BB9C2C71ULL, 
            0x21C8F1150D771395ULL, 0x3462D8D61B4D0E1FULL, 0x9575398DFA9E3035ULL, 0xBC4B4C429BDABDD2ULL, 
            0x1384AAE4C7F088A5ULL, 0x7563B67EDA04D6C8ULL, 0x91823D63A62490D8ULL, 0x42F9A5976F27557FULL, 
            0x2F9E873583CB881DULL, 0xE746818266D23D02ULL, 0x8388F2DF61C9FA81ULL, 0x940D90D016BED05DULL, 
            0xF92C813E575F3BE1ULL, 0xC1069A54A7F6E6E1ULL, 0x03F0E221B2408A6DULL, 0xE59ADB2F68291AB7ULL
        },
        {
            0x0575AD3457A9C2D8ULL, 0xCCB0D0B48E333596ULL, 0x22B9CA6D14867F04ULL, 0xC88DCDB12BF0EB38ULL, 
            0xAD7B4D6AE7EB473AULL, 0xFF5F2E11AF936449ULL, 0xAFBB9F9219EF7447ULL, 0xC5A8512B3A11BD58ULL, 
            0x04CD14DE6ABA00F3ULL, 0xD475ADAD17554460ULL, 0x90152237064BFACAULL, 0xDE3E32DED5094129ULL, 
            0xA85B685D13E83C63ULL, 0xA33544358D7C469CULL, 0x620F588AE3A5ACC9ULL, 0x201322F4248F7948ULL, 
            0x3E4810B5EEE3F061ULL, 0xDCA4900526097E1BULL, 0xF5B3A90F6D36E78CULL, 0xB3E5DD33599AFD5EULL, 
            0xE1356DB20882DD3DULL, 0x97AFFE1843A3882BULL, 0x80593BD5C4312EB9ULL, 0x81BF1DA953DA9331ULL, 
            0xD003494A88A6B792ULL, 0x63714DA1DD2D68E0ULL, 0x2CAF9E4D72C79579ULL, 0x77A360071601F34FULL, 
            0x892FB5004388971DULL, 0xA2746E0EAF11EA21ULL, 0x5C2DCC0BE4B6F80AULL, 0xDAB4827E93C14EAAULL
        },
        {
            0xB64CEF2003285BDFULL, 0x249D66B1DFCB58BFULL, 0xDAB50049B4E8768FULL, 0xE52DFD0F2FF6D689ULL, 
            0xC41F166F20C3E41DULL, 0xDE29C91A1309CB3CULL, 0x198E27BA2E9A37FAULL, 0xAFA4D3D375B4D621ULL, 
            0x452BB0500D475B90ULL, 0x3E3B840D1BFB1782ULL, 0x5BEC46AF476512EFULL, 0x440478912A21839DULL, 
            0x3B22C3815836F6C8ULL, 0x4AAB02B494C9364EULL, 0x25EC42C4DA103352ULL, 0x23ECB2ED71E1F040ULL, 
            0x29BB6B0A95F95C73ULL, 0x301626DD8A2A85FDULL, 0x55ECAFBC6697C597ULL, 0xCB046BF7ABA6DAF2ULL, 
            0x67F53DE28BC71284ULL, 0x90DC1C64648164C4ULL, 0xFFA151AFCE812AE7ULL, 0xF4ED2608B793FBA3ULL, 
            0x4AF19E5B860013EEULL, 0xA85D03085AF72686ULL, 0x26D9777D52A7FEB6ULL, 0x41188E4710C08A64ULL, 
            0xCF8FF01815932545ULL, 0x1FFF30F648DE9B55ULL, 0xBBE375FC88CEEF05ULL, 0x306F87124865CB43ULL
        }
    },
    {
        {
            0xD8B7CD9D734D78ECULL, 0x678B648B0DF7B1AFULL, 0x06A3AFC7933EFE9DULL, 0x91DCF4E34CFDA6A1ULL, 
            0x87A8411DEA369950ULL, 0x4109B8412C6E9796ULL, 0x67C9367A7E8D7CB0ULL, 0xE061D7B3BB08C033ULL, 
            0x4429F900C66FB4CEULL, 0x11521F6F4D40E4FDULL, 0x0F8684A8F3276735ULL, 0xDD342547FD752968ULL, 
            0xBFA72B800A43079DULL, 0xA2E15144E0ED3A59ULL, 0xD9B8EAC0BC3EC8EFULL, 0x6FE25103C444DA0CULL, 
            0xF7F3127E6E8236CEULL, 0x6823BEBD8BA78223ULL, 0x5DEA3F33C88A7425ULL, 0x5719E9D550DCD20FULL, 
            0xD25E37BEC1644284ULL, 0x4030DEF5CA86AF33ULL, 0xB9C9B42696C54D59ULL, 0x9D55B4B72BB511AAULL, 
            0xDFF53F2E8499A001ULL, 0xFA68E7508E46A445ULL, 0x70CA0FFBB2ADA050ULL, 0x120CC2F0E08AD4B3ULL, 
            0xD8FF72BA1F0C6E7FULL, 0x4C8D35E0E03E2A16ULL, 0x46D6270C1CAADB2FULL, 0x3D97E475768B15A7ULL
        },
        {
            0x6AC7379B8B8522EBULL, 0x053830A9D2368342ULL, 0x8F0584C7CF7F3C29ULL, 0x097AF80515201935ULL, 
            0xE0E71CCF529B66E4ULL, 0x1EC7EFCBEEA87D39ULL, 0x32EE1A713DAA060CULL, 0x10AF75677029095BULL, 
            0xCB8ECDDF4A9E1CF9ULL, 0x0BDD2799F78F05CFULL, 0xB27A5BD5837ACEDEULL, 0x4C59E541F938F608ULL, 
            0x08AEAC3140E6ACECULL, 0x16BA8AC89E1B203CULL, 0x6EDC0F1EF84C00CCULL, 0xD67C0007BEBE4224ULL, 
            0xD07631D8DCD9EB9EULL, 0x97466D3A92639A3EULL, 0xA47F85B825FD72B0ULL, 0x3B729F10B00F4FEFULL, 
            0x14031F6DE9E57698ULL, 0xFCC38946E5A9288EULL, 0x8D3D8BAAEF9B2A81ULL, 0xE1555011C36609E9ULL, 
            0x44A7E168BD975C7EULL, 0x634C4B06E03DC603ULL, 0x80A2B73D3A05E00FULL, 0xBD78CEB0407C8A1BULL, 
            0x92CDA6BC8C1105D0ULL, 0x940ECE3AE42EEB0BULL, 0x8764098F8319AE54ULL, 0xD81D33CC3D870DFDULL
        },
        {
            0x9B28004015B70D81ULL, 0x3DBA2E6861F69AD7ULL, 0xF930EF739FBC8D42ULL, 0x27E688FB8DFD35E7ULL, 
            0xD05835013F06ACC9ULL, 0x594AF6ED1743B99AULL, 0x96F152C86EEA5CD2ULL, 0xFCAF3D434F02F849ULL, 
            0x48BB5C59E728DA23ULL, 0xBFA193A9B058DC53ULL, 0x44BDC498FC790F40ULL, 0xF9488766AB150994ULL, 
            0x1654EBCA130320A3ULL, 0x6D820E529A29295FULL, 0x65A714B2E01ABCC4ULL, 0x509807FE41D9EEA1ULL, 
            0x307BEF7A43BEC408ULL, 0x797E21807C28EF98ULL, 0x24747852E737D2B3ULL, 0x2923EF147150B050ULL, 
            0x7A5380DA419026C5ULL, 0x873725861F150E59ULL, 0xCECD5E35F0589292ULL, 0x004AF310FBEA94FBULL, 
            0x4F07D2A092CC8066ULL, 0xDB0A41826844813EULL, 0xC7A19D0420C13BB9ULL, 0x73C8DC33C5FD3FDBULL, 
            0xBA21979AAB2FB6B6ULL, 0xC728700687BB7EC5ULL, 0x81B6C5D750C4FAEBULL, 0x5271FBAA0855C77BULL
        },
        {
            0x5AAE40F9D7F0BDABULL, 0x17C4797FEE4A88A3ULL, 0x8994079FBEB117F1ULL, 0xD6EDD9250691DCDAULL, 
            0xF1E4E1CF506F17C6ULL, 0x0D944A1A09D7F00EULL, 0xAC66EA88D9B2B386ULL, 0xE3BE74F7A5C82239ULL, 
            0x0DFC39D8CA118C1CULL, 0x6C5E8781B266DE76ULL, 0x20EEF51AF867790BULL, 0x2F62C7E1504A2675ULL, 
            0xDC115FA23F80170EULL, 0x9ADC36A00B21D517ULL, 0x487805D378B53303ULL, 0x64B1029710955820ULL, 
            0x2D75774992CB6852ULL, 0x1C829CA00F7ADBD7ULL, 0x15185BAA52259C95ULL, 0xA48DD3DC1F577A3EULL, 
            0x06FE36D962A887D8ULL, 0xE595FF720584C97BULL, 0xCF41571564DC0B8AULL, 0xE9F06019DB587E42ULL, 
            0x6C28A31EEBCC0FA2ULL, 0x6F28B6FADBA6F406ULL, 0xC360C0F890DF0ADCULL, 0x69824BFDDAD676DCULL, 
            0x9B779453FD51456CULL, 0x65678232194653BDULL, 0x3D14329F22D07DF3ULL, 0xDAC38918D99B6947ULL
        },
        {
            0x38353C51459CBA30ULL, 0x60BEB1215D5EBA64ULL, 0x54F756B22D81E1E3ULL, 0xFA794655F9FEB584ULL, 
            0x547DF21561095F72ULL, 0xE628CA2EFF745B9BULL, 0x55D39175CCD8FB6BULL, 0xF00399FF7E81D097ULL, 
            0x7DEA26CBFBF65B04ULL, 0x34E02E1BA4009715ULL, 0xF3017320D557EAC5ULL, 0x11DE89913E0280A4ULL, 
            0x7FD5D6438177D90CULL, 0xEDB0FACA1893BCC2ULL, 0xD587D2D28353CDEAULL, 0x5774E97798F4ADBFULL, 
            0x1CF63688BF36AA30ULL, 0x3676236B4A4CFE2AULL, 0x6933D0E44F568A5BULL, 0x985CA13C18E7585CULL, 
            0x8CAF84F95116A70CULL, 0xB1CA56B8A7B1BE13ULL, 0x1A82CB16623B2E72ULL, 0xCE21D561C2865E8BULL, 
            0xBA95C106A327F7A3ULL, 0xA9DE0AE2097FC3A9ULL, 0x0D38E03692F86EF8ULL, 0x9072BD4CEDA72C46ULL, 
            0xBAC7E3227CD28790ULL, 0x68AF2ED83FCF007BULL, 0x055658805D639B4DULL, 0x33B566113E985BE8ULL
        },
        {
            0xB1C8A9C325DEC8B7ULL, 0x383ADA4FD2103399ULL, 0xD70C8C1D47311BF3ULL, 0x63389D70E95CD65CULL, 
            0x50858828AC44D735ULL, 0x45AB9F6F7681870CULL, 0x3CA2EFFB4DAF0EEBULL, 0xEFEA761DC90D6900ULL, 
            0x4747AAAE5A19B32BULL, 0x16BE56742469504AULL, 0x2FB002DDA78E88F0ULL, 0x5E9937F7A8D24A0FULL, 
            0x02E180CCB97DB883ULL, 0x1537502F8B1F6175ULL, 0x6F69E3332FD5B35FULL, 0x5375B84118E38D4AULL, 
            0xDED1895464BF50A1ULL, 0xE10CB60BAFE52E1CULL, 0xCE6FEB471A0C550EULL, 0xEA03E8BDA1B6554DULL, 
            0x564FE382DE63D017ULL, 0x287AF5D65110DD68ULL, 0x325A95AE70B945FBULL, 0x7994378FB592AAC5ULL, 
            0x81D945EE333AB23EULL, 0x399BFA29753EE1F9ULL, 0xD99B6375AA62CBBFULL, 0x826EBBAC1F13AB4EULL, 
            0xA8FF7408508D3CA6ULL, 0x6EF70F37444B2D92ULL, 0x6ED2581B98CF35E8ULL, 0x952A0E1457E3116CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseDConstants = {
    0x62C80F0A15942B68ULL,
    0x15B8BC777CAE7A84ULL,
    0x86EC7851B2F286B6ULL,
    0x62C80F0A15942B68ULL,
    0x15B8BC777CAE7A84ULL,
    0x86EC7851B2F286B6ULL,
    0xCAC32ACA8E4B8B34ULL,
    0xFDB4DCDC7E4C7D3EULL,
    0x1A,
    0x4D,
    0x83,
    0xEC,
    0x76,
    0x5E,
    0xA9,
    0xFB
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseESalts = {
    {
        {
            0xF2101A714F4B279CULL, 0xB2014485C490971DULL, 0x3C0635326DBF1727ULL, 0x33AF87145E2C6FE6ULL, 
            0xE86EDBAD5796261FULL, 0xCDCA0F7BCEFF6B3CULL, 0xE53E0F1A8AB13263ULL, 0xAB3E6C9B2C2F19C5ULL, 
            0x987441AE76B7ABFAULL, 0x62C7353C99C447E8ULL, 0x6613AA6432C9D54AULL, 0xC8DEE5A964067751ULL, 
            0x00F531E4013D6A7CULL, 0xF618465FE225E99FULL, 0x1C5AEE8945E87930ULL, 0x3AA89C30CF7D30A3ULL, 
            0xEA45FC16FBDEAB43ULL, 0x28A3433073135F6CULL, 0xF97530174CDABA07ULL, 0x60FEB746674AF75EULL, 
            0x025CA17B53D24309ULL, 0xA3C602ACFE67DB67ULL, 0xE6DB9846AE5B25CCULL, 0x730196C564A808E9ULL, 
            0xB864C1FF29509A4CULL, 0x0AECC8954D202D8DULL, 0x05B5E5FD37E36F53ULL, 0xD1B38DC5CD102346ULL, 
            0xB845EA2858FA9EF8ULL, 0x47E80D3741FF77F7ULL, 0xC0F1274BE3A4FCFEULL, 0x0AC3042A94E304F8ULL
        },
        {
            0xDF7C433088EC1333ULL, 0x24D7B6A2C7730B76ULL, 0x3AB632473DBADDBEULL, 0x7A67DD220157C999ULL, 
            0xFB4444F1E2FE8CC0ULL, 0xCBACF3973166339CULL, 0xD06D39E63C338177ULL, 0x5EBB3A54C6B30944ULL, 
            0x56E8460E78F66A61ULL, 0xF3FA25175455D9C7ULL, 0xC58FAA7967696598ULL, 0xA4B80F394CD856D0ULL, 
            0x49B75FA27BDB8614ULL, 0x4A78C73F530F897EULL, 0xE02F734A576EC829ULL, 0x113BB22C08014B87ULL, 
            0x30EDC6AEF50C4C95ULL, 0xF07C44625DB40387ULL, 0xA79E6DAEC1A07FCAULL, 0x2D383CFDC984FC36ULL, 
            0x3939F2FE6A4484B6ULL, 0xBF64A2898A3C2082ULL, 0x78CED9685075B9DDULL, 0x8441ADA676F6E77FULL, 
            0x5698ECAB29FFC296ULL, 0x707A051B8536FD8DULL, 0xB72AFD3F738636F2ULL, 0xF0774F038A170063ULL, 
            0xE70AD505A0BAD3F9ULL, 0x883B3AC6723E2C37ULL, 0x1F39752F1478E9BCULL, 0xBF7675E19E48D998ULL
        },
        {
            0xE4B230D3AFC74E6FULL, 0x6084E34FE2884B13ULL, 0x5C226E2AC6040370ULL, 0xA295AC54BB2E1F33ULL, 
            0x472C142D741E6988ULL, 0x5A98D81DDA662A75ULL, 0x454312F0440D660DULL, 0x2A1B1176A44E5A4BULL, 
            0xD499BE200B431589ULL, 0xD7019AAA0705F609ULL, 0xC15FDB72FFBFDFF6ULL, 0xF3DCCEB0101F78DCULL, 
            0x1668592A28170921ULL, 0x9DC62F005976E232ULL, 0xBCBF48627EED5829ULL, 0x328BDD4C48EE0EFEULL, 
            0x72B1603AD9609A24ULL, 0x6C535EA106A132FBULL, 0x3C01A249E4348C75ULL, 0xE66C693B8C347EB4ULL, 
            0xA1E2297456DF02C1ULL, 0x4B5CF99AE71F65A1ULL, 0xAACA61F23E3585E1ULL, 0x9289D5E9470A30D1ULL, 
            0x33A14E6B9D1EBB6AULL, 0x5B12CC1F60A77D39ULL, 0xCF3A31AC2704ECC2ULL, 0x65AD41D13B398A6AULL, 
            0x50CA7A0C0D530FECULL, 0x1530ACCD5953F060ULL, 0x7551532E09C0AEB7ULL, 0x5BCB344C182CF98FULL
        },
        {
            0xF22D7A96AE518FCBULL, 0xDAA08A8A7DF48931ULL, 0x2BCF64A779D7ECB8ULL, 0x00D36750DC1FE7DAULL, 
            0xB9A099F3CD2B7E3DULL, 0x0B736F0A40200FFCULL, 0x15943AB7F2E16EE8ULL, 0x70DA69A2D7AFE84FULL, 
            0xEBAD6FB9FEBC6CD8ULL, 0x138D92D5053B7834ULL, 0x1DB278ADE080272AULL, 0x7DEE46DAE70DD354ULL, 
            0xABD13DF3928AEF9BULL, 0xEB01B798F6021695ULL, 0x61B5CBAF5E21451FULL, 0x45220BDB9FBF18A2ULL, 
            0x3B2D8C7BA8DF16A7ULL, 0x413EAF7872A4F1AEULL, 0x9701943C1352E930ULL, 0xDCA47F3A9F58393CULL, 
            0xF65B9E100D4A676FULL, 0xDB96904D5898EA8FULL, 0x1A33CB59539AE602ULL, 0x7DA8B29A5A39B142ULL, 
            0xEFB5D587E71054B2ULL, 0xA82FD5C1E4538F11ULL, 0x0EB4D24F1AC6BCDAULL, 0xF7FE30A236AFD380ULL, 
            0x0FEE99E22B6D03CFULL, 0x6504CC4F3A2A1F3EULL, 0x1E3602A1DCDA9721ULL, 0x072471FF83FDE9BEULL
        },
        {
            0xBEE789EBB48CC6E7ULL, 0xC20C4F8D167ABE5BULL, 0x5B1FEA11C166B99FULL, 0x105691F86BBAA73DULL, 
            0x2A4B16E6CCAB5BDBULL, 0xCC66B0C4B382FA2DULL, 0xFD0F5F09B3CA36CEULL, 0x49CFCFFF9494B252ULL, 
            0x9246912BA8676A60ULL, 0x9BAB4129171295F7ULL, 0x85266092A1FC7587ULL, 0xDD9C97A2F5520D06ULL, 
            0xE606749CA56F36D1ULL, 0x6F5B129375D6C25CULL, 0x2863A9952A930D6FULL, 0xC5FC208457C14ED1ULL, 
            0xB5A7DBADB02922A7ULL, 0x5957AC41B6C287AEULL, 0x54E9D020C90FB401ULL, 0x8772DEF8FADF7CA7ULL, 
            0x8B61FCEA64FDECC9ULL, 0xF55C23B11C543CF1ULL, 0x3D0DED0E59279308ULL, 0x9C122033D99E7922ULL, 
            0x091BE1C5C6578EE5ULL, 0xAEA54B72097BA482ULL, 0x641C5BE311703EDEULL, 0x5656087BF9202141ULL, 
            0xBEEF5F5AC38B3B84ULL, 0xF2F005D5928A914CULL, 0x78F446F9FD42904DULL, 0x0B2693E843838A5FULL
        },
        {
            0xC7F1AA1FE9D5E462ULL, 0xB450BF2DB3D71E56ULL, 0xCF2BF94CCE227FE7ULL, 0xCCC4EF923AF0E1EDULL, 
            0xA9E16DC8156CFBE8ULL, 0xDEC2024071E655FCULL, 0x54A8495A95C99E0DULL, 0x07F771BD92915A2CULL, 
            0xF87BE60EECBA8DC1ULL, 0xC4429B2FCA869655ULL, 0xF2647A387A5CBCBCULL, 0x3ED1C7C04E149697ULL, 
            0x2A5F96A0E01CAF39ULL, 0x70CD58D3328A3315ULL, 0x1092E3AFE4A675D6ULL, 0xBB3B6CBC2536B014ULL, 
            0x9F7FF2ED5C6A5B55ULL, 0x31CB772E6C32316EULL, 0xA427F53DDB0105ACULL, 0xD26F76B5189F408AULL, 
            0x07F0C17F6B479CFEULL, 0x5A1B223546F946AFULL, 0x069DE476FB77FD35ULL, 0xE60CCC723E66D9C8ULL, 
            0x6BEEF5327A939B04ULL, 0x1034F4C40A5914B2ULL, 0x582931F257C307BFULL, 0xAEC350EC3DBDABE5ULL, 
            0xDD5115272C381651ULL, 0xEAAA1AEEEAAE8E72ULL, 0x65EF5AA1FD38D7F1ULL, 0xD15279B01473E8B0ULL
        }
    },
    {
        {
            0xA5B3E61A2A518AC4ULL, 0x39BAF2C638D567CEULL, 0x50ED19B65AD2DECFULL, 0x2BF9BF18933E7449ULL, 
            0xE24218AB161ED097ULL, 0x635FB9C7F6102B51ULL, 0xAC70FE628BB83F2CULL, 0xD36592D911DBFC08ULL, 
            0x26DDF534BB91578BULL, 0x2412DE4B6544CCBBULL, 0x8343937577D98568ULL, 0xF6275C405353F3B1ULL, 
            0x14D6A668BBF6E20FULL, 0x6230500AB52ABD34ULL, 0x25E05806D57DBD21ULL, 0x086955D51EB143F7ULL, 
            0x7245B7D9652DC361ULL, 0xCD698B5893EF1FDFULL, 0x7CF7C0171BCFCC1CULL, 0x6109315CF84106F4ULL, 
            0xF3B75FD2F68C10BEULL, 0x517128FC3F8F90E1ULL, 0xFA7852505E439074ULL, 0x25DFE4F1A1895895ULL, 
            0x6847030BEF7A027DULL, 0x6FC978BAAFE370ABULL, 0x54BE794DA5C1FE51ULL, 0x1E2697C0AB505D92ULL, 
            0x2D6E8336F15A1933ULL, 0x563947885ECF492FULL, 0x748E608E03E44B4CULL, 0x4505209232D2D905ULL
        },
        {
            0x19E2ACCA6AC59A50ULL, 0x58ED22638B90722FULL, 0x5C8FD0B77F4D84D6ULL, 0xAE5FEBDEE4A803ADULL, 
            0xB540AF9FBBC980F4ULL, 0x545068DF7E16BEF7ULL, 0xD105CC68989F6844ULL, 0x4C341689FEA1F0C9ULL, 
            0x308406E537394DC8ULL, 0x91FA10E03E64CFFDULL, 0x98A71B993E429910ULL, 0x330AD7047CBB2E52ULL, 
            0x245EB15D4441BB6CULL, 0x5471AFBEB54613FEULL, 0x7CACD1CB073B10ADULL, 0x19C92EDCDEB3E728ULL, 
            0x0E3676690FBDE330ULL, 0x46FAA64158ADA2B0ULL, 0xA6ABFBE261A59B2AULL, 0x7C8E4E80F7392882ULL, 
            0xD042D0141A788012ULL, 0xE1276DD451D2A799ULL, 0x5AC40954EA20D46DULL, 0x0E23B515D0F1C53CULL, 
            0x1C73921F889EE257ULL, 0x22AE3AC140DE442AULL, 0xA087D2C742E262A3ULL, 0xADF30C16EDDA4DDCULL, 
            0xBEA15CC9DB1E7959ULL, 0x34450ED9BDC42D70ULL, 0xA2DE3DF9689220B5ULL, 0x74AA29187A3242DAULL
        },
        {
            0xF849BB08F6D83F9DULL, 0xB894EC206FDE4CBDULL, 0x34E54463911F5A11ULL, 0xA034456BE5BB5EA6ULL, 
            0x632A6705DDF80BB8ULL, 0xB01F4EF77D031AD5ULL, 0xAE624B8638164102ULL, 0xE82F7E28B5780A03ULL, 
            0x7900794BEAEC3E9AULL, 0xC29106F0CFB61793ULL, 0x5CE523318D362599ULL, 0xC373112CFAC37AA4ULL, 
            0x4E5EF36C2FFA886EULL, 0x40A463F95B94339CULL, 0x4D997C5998634428ULL, 0xA45DBD0BDD6106D1ULL, 
            0xFB082A4014672112ULL, 0x81AA8EAA9C93862FULL, 0x8AC39394516D04B6ULL, 0xA2070EEDC95C9BAEULL, 
            0x39B22B484FAA07EDULL, 0xA45FAD2BB521CF84ULL, 0xF21DCBC8DA554ABFULL, 0x4BE7E9FF28B79B43ULL, 
            0x3B5E8567A6FA83DEULL, 0xECFC2E3C40356A68ULL, 0x6C3AFF2932CAED87ULL, 0xB3283D66E72BB2EFULL, 
            0x02F911605CBA6FDAULL, 0xC9423B257178CEECULL, 0x202A48B893E898DCULL, 0x86F39C2FCA0EC434ULL
        },
        {
            0x60A00488FFFA05C9ULL, 0x38A6EC95E8AF82E6ULL, 0x5D1A58049AB64CCEULL, 0x6DCFF18485BBF630ULL, 
            0x8FC0D6C0856D13E4ULL, 0xEB170B96C9B3FE47ULL, 0xCD2F0BFB6B0210F9ULL, 0x7D9AD2F31F439A68ULL, 
            0x47C02618F0E1B785ULL, 0x96EB384FA7121B73ULL, 0x154484B7DB113780ULL, 0x5AC45A18361B0251ULL, 
            0x415ED5A3A66EBB03ULL, 0x50DB259E6D2A3706ULL, 0xB45CDFB950836F29ULL, 0x0D71D068EBF69DEBULL, 
            0x2CCFD8CCC120EF5CULL, 0x3EF9B373B5BD90F7ULL, 0x79FDBD14FC877BC9ULL, 0xBD97E3F641F27EDEULL, 
            0xFB319430B3BD74B3ULL, 0x1D4E8C587E61E48EULL, 0xF625B1B5156A46A9ULL, 0x1CAAF5660DF250E2ULL, 
            0x11A413C4ABF2D03BULL, 0x69B6A096E9BE0917ULL, 0xC1A606FB68AAE893ULL, 0x3020882196B036D6ULL, 
            0xDBC7FF626159181BULL, 0xEEA058C13B6775D7ULL, 0x25350F846B716773ULL, 0x508BB459A5CFF5D8ULL
        },
        {
            0xD85E4FFF7D432820ULL, 0x3CB56D68E598333CULL, 0x19A264EB454FEFB3ULL, 0x608A55B86F9197C1ULL, 
            0x3B8A84D6E998CADEULL, 0xA0F6B549283270F3ULL, 0x7C6751006A58EBE3ULL, 0x160BF35B543A5753ULL, 
            0x94D6B295DA75645DULL, 0x57D9E5FF94701C6DULL, 0x58239002CC894E08ULL, 0x95A5CBE84BDDBEDEULL, 
            0xB4C884C7C808C37DULL, 0x8949ACCEF5CAC64EULL, 0x5343995B30E1F561ULL, 0xFD6EAE9E2D421E00ULL, 
            0x4A38C44E9BD37D2EULL, 0xE1190C4B32B5B9D2ULL, 0x8665D976A553DBA9ULL, 0xB523B8893476F3B8ULL, 
            0xD1AE4A01CA0CD7EAULL, 0x89113931A621E102ULL, 0xC9D8642DE29884E5ULL, 0xC65BF531829F799EULL, 
            0x07B071D7BDCD8E32ULL, 0x1CDD93794D830FE2ULL, 0xBEE54EE47495C41BULL, 0xDF7274E7867E172FULL, 
            0x566A1510D590D946ULL, 0x279636D79404A8CEULL, 0xCF11D17C29ACA81EULL, 0xE1206E08EFF640F4ULL
        },
        {
            0x69246C94546FFFDEULL, 0x8AA9E9BC70D06F38ULL, 0xC9229357F263E36BULL, 0x26ADE8EAA21F43F3ULL, 
            0xBADC50FE91DE9821ULL, 0x9EBBCB7E8A595ED4ULL, 0x29F162A529C9EE29ULL, 0x26FCDDD745E69AD2ULL, 
            0x2F5F39B2852A7B1BULL, 0xEE3D3F09FB089721ULL, 0x190574485A9ED237ULL, 0x8031331410CD8849ULL, 
            0x57B97390D11B7A28ULL, 0x965AF6E18A036C94ULL, 0xCD40F1941924E22CULL, 0x9D8ADD6CDF7624A5ULL, 
            0x85810ED628E68863ULL, 0x45882B340692D874ULL, 0xE5C00299CB43E4B9ULL, 0x0FA2BA3EFE8E6286ULL, 
            0xEC1547236FF1A6F7ULL, 0xF6205C7507174B0CULL, 0x0ED26166FA2D2604ULL, 0x03588D34F118700DULL, 
            0xCE38560A035500BCULL, 0xA45DA838C64E6C63ULL, 0xCFDFCD85F30B487DULL, 0x24455B37439EA87EULL, 
            0x51AB87384DC4A904ULL, 0xE386629B0735C3B2ULL, 0xC2BB8CF054FCFF65ULL, 0xF9281E980DE945E5ULL
        }
    },
    {
        {
            0x938D75DCE379F412ULL, 0x013620754C1929DFULL, 0x857F55FD39CDB7BDULL, 0xF70A0DF628792D5AULL, 
            0x7343ED830B4E228DULL, 0x5A8817B460C08838ULL, 0x7CF9F19D48319A03ULL, 0xDEEE197D74E77302ULL, 
            0x80DD368E593347F1ULL, 0x15C4133145080D0CULL, 0x6697BABD5B6A662BULL, 0x2FD1A69A07E75E99ULL, 
            0x8323AF1F7D925152ULL, 0xDE57481956025B09ULL, 0xE0230973CC6F3DE9ULL, 0x8E3B764D3D5F9120ULL, 
            0xC051AF26ABD7AF21ULL, 0x2EF9E16CBEF68997ULL, 0x62CCBB315DAAB433ULL, 0x9AA7B158AB2F3FDFULL, 
            0x3B9E46325A4DDF30ULL, 0xF5A14523C86DBC3EULL, 0x83DECA6DA6100D60ULL, 0x2CBB03CC92D6C02CULL, 
            0x3363E1B69E8C0125ULL, 0x8785DC8840F835A0ULL, 0xD7A9C3219B4BEBF2ULL, 0xC9260725E30FEF21ULL, 
            0x8084D700DFE3A467ULL, 0xB367D223CC3901D4ULL, 0xE4C486F13A4B0538ULL, 0xDAF3DA7A1B1DC3EEULL
        },
        {
            0xEBDFBF2FC587A8A5ULL, 0xB2E8D340E426F8AEULL, 0x9F9446F2F4360BE4ULL, 0x45C752DA53033457ULL, 
            0x8CD52BBA388B470CULL, 0xBCC7C28E29D89DC3ULL, 0xFF9E33D218F4D823ULL, 0x28713C16BBAE306FULL, 
            0x2EDBB02ECA0CC31CULL, 0x8F2A4457FAF825CDULL, 0x93077F291D8F0352ULL, 0xF65C689B186ED95CULL, 
            0x8BBEE8C0686A6D6FULL, 0xEBE12DCE18A7479CULL, 0x02F8235A997AA007ULL, 0xE487F86B79DA9C07ULL, 
            0xF260F8E2EB43F68FULL, 0x7A305256ED5C7A24ULL, 0x005FEC9888679114ULL, 0x258D3ED2BA48BD03ULL, 
            0xF79C080E7A887B19ULL, 0x88E482CF3D376174ULL, 0xB777633977141190ULL, 0xC7FB144C07F5CDFAULL, 
            0xBF67A6ACA4BF8D11ULL, 0x4935C0F2802E382DULL, 0xE72369DC9A1B876EULL, 0x35C1A2A534B71A3CULL, 
            0x94794CB363C6EF4EULL, 0xCBF63EDF4588E60DULL, 0xF0E5BBE5A3905867ULL, 0x8CCCA348D083570BULL
        },
        {
            0x0297F65A6671F5EDULL, 0x231FFBAE2D173F03ULL, 0x1D2EC3560524E49CULL, 0x309E7F7E81864ED2ULL, 
            0x4496745AC107FD94ULL, 0x10EAF8321DA659E6ULL, 0x15057C103C249D60ULL, 0xF190A2AB67ABB08AULL, 
            0x236E8D33D0FD1EBFULL, 0xA781988295275328ULL, 0x8B305B2360F98AB2ULL, 0x6F2B1A0FB4A68E76ULL, 
            0x8E91425AD1F8DE4DULL, 0xD2FF7B2556A94A28ULL, 0x5B176216CA29E84BULL, 0x01D2D128CCE64A7BULL, 
            0x0088A891F6B5639DULL, 0x6A30AE8DFEF04D0BULL, 0x9D9B0DAD64380AD4ULL, 0x7D71EA68A373F914ULL, 
            0x42DCB97AA9BC1458ULL, 0x2AD7EB6193615D66ULL, 0x6816DA058682BDE6ULL, 0x9EB9BB8A34E4D65EULL, 
            0xEBF18F7AEAA86CB3ULL, 0xEA58447FA27E8B31ULL, 0xE109453709055EFEULL, 0xFB836B9D75F233AFULL, 
            0xFA2B6A56BCC723FBULL, 0xB426FDA089BCABCDULL, 0x52A7A410F9770294ULL, 0x798D0682A93E9E6BULL
        },
        {
            0x6E2455F531902E3EULL, 0x5D9BB7FBCB89BA2BULL, 0xCC129908BBB7C18EULL, 0xBD15DDA820CB34B9ULL, 
            0x43F80027523EF0A3ULL, 0xE4F16103838CDFE2ULL, 0x5FB9116A85F546ABULL, 0xD21D57BB52A68B72ULL, 
            0xF6D5F0CF2D5B72EEULL, 0x66AA52D7D9BD0882ULL, 0x8BA3F974650CA75DULL, 0x07973B32A76F952CULL, 
            0x7574DF39F750A7BDULL, 0x0234860AC35760FEULL, 0xB7FC45D647BC7D47ULL, 0x26F19A2214874115ULL, 
            0x2784E877E1DA24DFULL, 0x1CCCA3D97B61CF08ULL, 0x48E4029082C24C17ULL, 0x31F1AC26D77629E3ULL, 
            0xA2972478162986DCULL, 0x1856C77B9E6C6088ULL, 0xBFC1AC8F71EB6FABULL, 0x2E81EB32F915F5FAULL, 
            0xE2F68E1C5559641AULL, 0xD8BA6BDB9968D3D5ULL, 0x14778E509EF26DF7ULL, 0x51D7802A9E00EFBBULL, 
            0xA34D43C44EBFB7ABULL, 0x68A72B00FB2AAFC6ULL, 0x9ECE221A6072FD46ULL, 0x7D74E6F135DC8489ULL
        },
        {
            0xA3B3A10BC1DE0DACULL, 0x8FC12FED8530020BULL, 0x2903791C0A1F2294ULL, 0x001252A605638CD7ULL, 
            0x28E3B558238B40C4ULL, 0x7E8569178E5DBC39ULL, 0x45EA1253158A2192ULL, 0xBFB70436DD0EC2C8ULL, 
            0xFB6955B3C1677501ULL, 0x1DCB9E8BE609B579ULL, 0x1D12AE6CA96934FFULL, 0x715BC8D4E25867B6ULL, 
            0x7951F9DB3D8A3674ULL, 0xAE19FD678516C830ULL, 0xFFEFF537A441E0DAULL, 0xB09F5A1AB6E9BCB6ULL, 
            0x8F577B7599024518ULL, 0x0D847206DD65AA18ULL, 0x5CCFF7550B559E3FULL, 0x5E884B9844B8F476ULL, 
            0x03B91AD67D8FEC66ULL, 0xA69BFD3833EAC368ULL, 0xE0C38EA34DE8E65EULL, 0x8575A04FDB878F7CULL, 
            0x40D0528CD283D5DAULL, 0x6A869E24E3578403ULL, 0xAC64A5E87094CE7EULL, 0x4978F6758B8299FCULL, 
            0xE4BD3DB2381AC127ULL, 0xFB0272360BBB65B0ULL, 0x4766C7700993D3EEULL, 0x801E65A95E58B8E3ULL
        },
        {
            0x02FE8B2C29AF57D0ULL, 0xA7D08D4B1953E16CULL, 0x466735F188390B78ULL, 0x955E9C363AF7B10EULL, 
            0xBCDF654C8A8D40C2ULL, 0x7E78940D22A20491ULL, 0x8057330F687A6E36ULL, 0x8BDDB1892A95D5A8ULL, 
            0x3C6C25880A7ACC14ULL, 0x52816CBE40AE2EF6ULL, 0xA19E5394D0B937F9ULL, 0x08116247EB1AADDAULL, 
            0xB6FE2687D5CF66C1ULL, 0x2E66631150660FF2ULL, 0x08B6735689F58293ULL, 0x0C1A75076E41B8D2ULL, 
            0xC76A9465926B7EF4ULL, 0xA4661E413CE829F4ULL, 0x9FD4F18DBF8B57A5ULL, 0x3A39D4117173AF67ULL, 
            0x5FC29123E554706AULL, 0x4602DDE7A2468192ULL, 0xCB4960557CBBC9FAULL, 0x95D37EED9169C64CULL, 
            0x615D0295CF886FD4ULL, 0xAE530187AA27E15EULL, 0x6E71727A54BB732FULL, 0x1A5F52323A52AE63ULL, 
            0xB812712605334115ULL, 0xBAFD0ECB8923D7ACULL, 0x6C2F4C9F44E98EBFULL, 0x5E2056B37F2930B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseEConstants = {
    0x268CD50A76AC081AULL,
    0x6416BDE66A6458C1ULL,
    0x7D2E6189AB4045ADULL,
    0x268CD50A76AC081AULL,
    0x6416BDE66A6458C1ULL,
    0x7D2E6189AB4045ADULL,
    0xD242E9A0E7001C1AULL,
    0xB66FF0AA2CE00A66ULL,
    0xEA,
    0x33,
    0x92,
    0x62,
    0x02,
    0xBE,
    0x68,
    0x84
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseFSalts = {
    {
        {
            0xCDD4FE4F7E4672EAULL, 0x67CF9FCE6839A826ULL, 0xCEDBCA0FFC38A322ULL, 0xDA1C8A83F9DAF896ULL, 
            0x09EA11979EA0464EULL, 0x267AF165B8BD0957ULL, 0x95BF559CCE4C2E11ULL, 0x90A1F1BD8548CCD1ULL, 
            0x0F12F6E954F77C61ULL, 0x2ECE05FA128F24F1ULL, 0xE89272A8B6AB915FULL, 0x0A9BF8D27CEF35DAULL, 
            0x72686229838C54F5ULL, 0xDB750A37F72C107CULL, 0x4006CBE87853FCA8ULL, 0x214740466770A34FULL, 
            0xD54C66D67C944A0BULL, 0xA4C9EE1801CE627EULL, 0xB87DE3D8B9FED6A6ULL, 0xA79FEC2636B9139CULL, 
            0x9D54D4F84B008808ULL, 0x895A6F40F5F9E728ULL, 0x3FC8C806FEA55B1CULL, 0x4A0AF24161BCE868ULL, 
            0x7490CA2E50E0E4A1ULL, 0x242106DBDA1C235CULL, 0xBA1D471E30F1C0E0ULL, 0xE9E3F91F27B5D227ULL, 
            0x619BBB9E9F64440FULL, 0xEFB0EDC620F12A83ULL, 0x5C8A7AA7577CCA0AULL, 0xE52C7C5C2977D5D2ULL
        },
        {
            0x1EABD8B6F2D1CCC6ULL, 0xEB895B82CF7485EEULL, 0x7ED69784A540C349ULL, 0xB3A17C63EAB974D8ULL, 
            0x70B3ABC9305905ADULL, 0xFF4A9287A1A79791ULL, 0x86826948CDB8E2EBULL, 0x74AD8218F01AD702ULL, 
            0xEF3BF65DC58038ACULL, 0x3E00CE87014ACAB0ULL, 0x5615C9AC08A887A3ULL, 0x54D9F7D60D572C0CULL, 
            0x5144B8DFCEB2960AULL, 0x802E9C58B1FC0BACULL, 0xA6393CDDC2A6446DULL, 0x317A50A322BD7380ULL, 
            0xC04CEC6EA78299A5ULL, 0x758B1D515AAA6432ULL, 0x3AEF05F3BB4375E0ULL, 0xBB9DFBBC0F99B38FULL, 
            0x234AF80B233550C5ULL, 0x363BC7F4C3AA0114ULL, 0xA31DAAB43DEEA52BULL, 0xBCB691DB28D8405FULL, 
            0xB9EC78A94CD8D1EBULL, 0x29B0996461A46F68ULL, 0x5CC41077D0EAE719ULL, 0xE235BCBFF9922E8CULL, 
            0x474F1085CC75BAC9ULL, 0x8AAF7B3C1D6397FFULL, 0x9A1D8DF869CEBB86ULL, 0xDCADB8CD52B099AFULL
        },
        {
            0xDE1E63AA91F33C66ULL, 0x0923FCEF5005BC19ULL, 0x372ACCC40984B8FDULL, 0x207B3F79AA6E221AULL, 
            0x10DC54B4C8391CC2ULL, 0x9C2BD24DC7725516ULL, 0xCF134FFE40D64F39ULL, 0x94C03FAB6EFF0EF3ULL, 
            0x25695C4491CFBD72ULL, 0x67217A2132659E84ULL, 0xD9816526DC6E7E87ULL, 0x7F1E082112D096FAULL, 
            0xD09DA0BFBD3E3560ULL, 0xCC1E24F23F037BE5ULL, 0xE8DB98734DA617F6ULL, 0xD4904E88754473F2ULL, 
            0xB566EDAF41C0E9B6ULL, 0x22ED44B9BA2664F0ULL, 0x6F231549193E57F7ULL, 0xB2236BA002824488ULL, 
            0x884814B092E01058ULL, 0x40DC11CB3310A496ULL, 0x8C1E98944300C0E2ULL, 0x26A0F51EEF2623D4ULL, 
            0x74FEE8F81498BDB2ULL, 0xE02A764A6887300FULL, 0x272F51C22DF985BCULL, 0xA7B3EA40C981EB93ULL, 
            0xDE8EC8C7416282AAULL, 0xCCA9F149F09C9A28ULL, 0x84FAC82B43718259ULL, 0xF2071EBD28259EF4ULL
        },
        {
            0x0670121A9982A543ULL, 0x0063DE4BD0B27984ULL, 0x221A505172906CACULL, 0xAA2F31183A4A2703ULL, 
            0x5A6591B030967179ULL, 0xAA113FD2B37C8C1FULL, 0xFBAE40D51F8E37DEULL, 0x29A39C7217504AF4ULL, 
            0xBAF589A974CC9D6CULL, 0x2585516FE8FAF437ULL, 0x508E8535D2F741A9ULL, 0x56D6BCF54DD30E44ULL, 
            0x7AF84DE4127A5D85ULL, 0x987901DAE5420C1BULL, 0x793F3B844AB3FE14ULL, 0x8928FEF557789BB2ULL, 
            0x55EDCC89C215B7FCULL, 0x91564A1E7B2D1DD8ULL, 0xA101BBCDE5EA0B50ULL, 0xE387703ACE9FA096ULL, 
            0x9AABF7B679461DD9ULL, 0xC309B0952682C5FEULL, 0x9B559ADB2996DAB9ULL, 0xB4417F8FA78BA596ULL, 
            0x6E0CAD9023183D25ULL, 0x99E89017841E2D64ULL, 0x06ABBA9C0996A3D8ULL, 0x40ABF63035CE1C58ULL, 
            0xE5E7738681A14085ULL, 0x98BE2C0B379E559BULL, 0xCE178E378DD881ADULL, 0x235CED3BD2FCC1A3ULL
        },
        {
            0xCE60AF9AF8385156ULL, 0x93CF2F2C41C72EDEULL, 0x0D0859E48E4867E9ULL, 0x96A53D3C14E3C2F8ULL, 
            0x86B6F121A616FB9AULL, 0xACFEC63CDCB6543BULL, 0xE0D3707F9FAFFAD7ULL, 0xDD25BA4EEB9247A0ULL, 
            0xAD293E7D59639227ULL, 0x976C2CD868BB0FE8ULL, 0x0FC6CA661993FE2EULL, 0x667ADB11EE699BCAULL, 
            0x99A4FC4C063672BAULL, 0xD6072BE221C7F87FULL, 0xB76FAFD2900067EFULL, 0xBA9D592C3514D785ULL, 
            0x0152C6B502D491CAULL, 0x69D6738927CA9028ULL, 0x4E5F34864C242888ULL, 0xC62004F8541E0F7EULL, 
            0xFAE8225759C72A5FULL, 0x9FBAD59891FE8666ULL, 0x6B34F11FA4086143ULL, 0x2F1CC59A59D010F6ULL, 
            0xDFAE74B130EA207EULL, 0x4AE1960A3A28BE67ULL, 0xF318B296FB9AC7A0ULL, 0xD25C3BE4ED0ABDE9ULL, 
            0x5BEFAEC88D773B58ULL, 0xD8CAAD41B6D30481ULL, 0x75B8B02A65431EA5ULL, 0x233CFEA43218EF68ULL
        },
        {
            0x61FB113E30C48EB2ULL, 0x5BB786064399B813ULL, 0xC868F6AB4C5871E7ULL, 0xA11C2F7AB38A334DULL, 
            0x2B314F31DC401721ULL, 0xE056EEAE47216B76ULL, 0x1599455FE3ECF501ULL, 0x26263577F65DCA49ULL, 
            0x5AF80E96E2CA8389ULL, 0x1DC109AE30895A86ULL, 0x3179BAE64349A588ULL, 0x8CF60BA5A8435F7AULL, 
            0x25E14824552215DFULL, 0xF74269B1FEF109FFULL, 0xEFA6A045A2FFC8D1ULL, 0xF682A012F9FCAD01ULL, 
            0x82E5132447EC6E71ULL, 0x624DE114A891EE15ULL, 0x125776F8CAC56E23ULL, 0xC290C1888D538484ULL, 
            0x5BE0C1CCB76AD2E0ULL, 0x2B3F42B4C95AE9D8ULL, 0x4719DD1A41939A34ULL, 0x8C7993B07859CB6FULL, 
            0xC0250E0AF3E8D45BULL, 0x876E6848D77501BFULL, 0xB1F004E5D60F0D1DULL, 0x6A19477081DF3511ULL, 
            0xBE4546899B42CF8AULL, 0x7EEF048160322C0BULL, 0x52BB76EFB3B66C3FULL, 0xEA1F4E499CE4E81CULL
        }
    },
    {
        {
            0x99F1A72D7152D1F9ULL, 0x76BA585A7A781382ULL, 0xBA797BEB1F9163A3ULL, 0x553F8C8C28E4ED23ULL, 
            0x212EA1789388212EULL, 0x9B864D3D3EEEE67CULL, 0x679DED67D0ED4371ULL, 0x76DADABC33E59692ULL, 
            0xBE8CDF6C4C224108ULL, 0x039F6931D4BCA026ULL, 0x8D6862227CFA1A8CULL, 0x3D4C279367223B2AULL, 
            0xE3B51BB942F063C5ULL, 0xAFD70D79296787F0ULL, 0x2C7316D1A80ED1E7ULL, 0x06AE5197773357D6ULL, 
            0xFD7762A370252046ULL, 0xFD7CF4C15C4409B2ULL, 0x7E197E74A6D380E4ULL, 0xA3DA4725A3A7A242ULL, 
            0x56C0FFED80D049AAULL, 0xCCC98F1A80D47350ULL, 0xCFFB03E695D6C9FCULL, 0xF5EB8F4370FF8EFBULL, 
            0x6606626F9B20305DULL, 0xAD1156477F071517ULL, 0x721064ADEB3C95A5ULL, 0x8D9FF750A85EA63FULL, 
            0xD5C455F8B326C04BULL, 0xCFAA49DCC7D12918ULL, 0x904E390E72F96538ULL, 0x5517359B1467280EULL
        },
        {
            0x1E62CA8EA6CB6188ULL, 0xA9D216D500A6E84AULL, 0x51E382F9D4A98157ULL, 0xA14C43710C1B8C94ULL, 
            0xF7E8E49DB6742F4BULL, 0x23C221B63EC5BC65ULL, 0xF9F7561EE847D975ULL, 0xDC6C452893196A94ULL, 
            0xAEC42CA0F3DBC214ULL, 0xE18871A48A206A49ULL, 0x6D4D8588F80E5AB8ULL, 0x3E0101C613B143C5ULL, 
            0xBCE467D99FCD4D5AULL, 0x2293A5F0D472CFA6ULL, 0x4BD999979000ECF7ULL, 0x2681AB9DB6BC66F7ULL, 
            0xA8631DDDCA7D33D7ULL, 0xA27C9DDC5E2CCDA1ULL, 0xA8D18CE33DA11FEDULL, 0xC3ACD2310CD25F74ULL, 
            0x696212C71790D875ULL, 0xAB9E04C410FC6CC6ULL, 0x820214E00A17C140ULL, 0x5FC4E1E14E7D5F6CULL, 
            0x6DECDB9A963A3A5AULL, 0xCB0037271D68E543ULL, 0x95CF169B0FB6F490ULL, 0x3004E4DE0B6E8152ULL, 
            0xA16DC4AC3748A813ULL, 0x9088860C95B435F9ULL, 0x6B7E97996D5436F2ULL, 0x527B1B9D0E1223CCULL
        },
        {
            0x91F91ACAC0C756C8ULL, 0x8C1B056C8ADF2EB4ULL, 0x8EBD36D592650D2DULL, 0x22F87E382D219ABDULL, 
            0x34DC1E04BFF29874ULL, 0xE5EF74E247D71F2EULL, 0x14168B50CD4C4E1EULL, 0xF39E401EB377DE49ULL, 
            0xBD27C74E952C5A92ULL, 0xA9B85EB6746B42AFULL, 0xB500C2A0BD78BB9CULL, 0xA29A25B5E84683FBULL, 
            0x4F8524598C104432ULL, 0xD8B5DCB5F3F3E05DULL, 0xE188258CFAD66893ULL, 0x0D59419FCE6B92D4ULL, 
            0x01719A5804280AB2ULL, 0x26B24F1A8D62C8ACULL, 0x672105AB095CAE8DULL, 0xE7A5E652B0CB71E1ULL, 
            0x203CAF20361B6F2AULL, 0x33FD099DFDFB37BDULL, 0x02B863BF6BE1A462ULL, 0x24DA92F2C689DCB5ULL, 
            0xF30D38D4F2C9F4C9ULL, 0x6254599D8C099B18ULL, 0x79806B61736514A1ULL, 0xC3A5F107A06ABBEBULL, 
            0x082CDA1DF59F3233ULL, 0x5246857DE91513C1ULL, 0xEF4FF21756634C91ULL, 0xF805E3572A721C56ULL
        },
        {
            0xEE21AC3CC403C8A7ULL, 0x5B942A4337C308B0ULL, 0x30B3DBE8B27640B4ULL, 0x9EC6DD04F06A3D32ULL, 
            0x528682BC16A0CD3CULL, 0xF6F85BFDB23EAF66ULL, 0x872CBE893C426B86ULL, 0xD8AC67248711024AULL, 
            0x61DC28B1D04173AFULL, 0x154B27631B8CF341ULL, 0x0632E1E419A41458ULL, 0xD2371D5BBDB81B69ULL, 
            0xEDDA691A10A5748BULL, 0x583C26E16C3AC1B0ULL, 0xD5F378999950707FULL, 0x5CF98FE8E150128EULL, 
            0x571279753DC7CAF9ULL, 0xFF77DE85A9CE25DAULL, 0xBDF67413AA4DC0E9ULL, 0x5639874B8303D639ULL, 
            0x5B5B4B016019E131ULL, 0xC54D7BBCDB14B198ULL, 0xBB2A0649FA91DFC8ULL, 0xDEE70671D37E43EFULL, 
            0xAC87B619DAD603DEULL, 0x25FA81BD02F5D6D2ULL, 0xA1BEA395AB6329CDULL, 0xEF48A6EFA20246F6ULL, 
            0xECAD48857609E77AULL, 0x519EA7C0D81354FAULL, 0x6F78FE99DAFD022DULL, 0x03C802CD3E7BBDAEULL
        },
        {
            0xACA6007FBDBEA5E4ULL, 0xF48CA717558BAE63ULL, 0x658D3B3564D0FE5DULL, 0x5A69AC009D423649ULL, 
            0xD395FB411D12FD31ULL, 0x428430020030D9C9ULL, 0xD784B587CBF18268ULL, 0x537385E4667A2BD0ULL, 
            0xFD76F5B4E37B0080ULL, 0x396DDB562FD48A51ULL, 0x07EF630DFBA63787ULL, 0x201286886597CF4FULL, 
            0x16AD3AB63E2A659BULL, 0x16F3FBCF31FBB3B4ULL, 0x71BBEC71C7CA2835ULL, 0x69F217AE70D38BB6ULL, 
            0xD144BB4B40B89CCBULL, 0x178C8B9233B052F0ULL, 0x597F6F67DFF4E28EULL, 0x9393B188CD2D7505ULL, 
            0xAE8F02853850AAD7ULL, 0x263CCFCC18DE9A7EULL, 0x809F03E08B655CB1ULL, 0x241D306052CE8D02ULL, 
            0x383779D15B827DA3ULL, 0x8C9FD2640272250AULL, 0xA46C1C48A9D1E850ULL, 0xDEA3BB5426EF612FULL, 
            0x7018F081BECB5226ULL, 0xF3B164D33EC7595FULL, 0x1168CE0094DEF831ULL, 0x46464400EF273BA5ULL
        },
        {
            0x0DE8D8D23A2371FDULL, 0x50CDD811C1F9E7CAULL, 0xF64F27FADE37847DULL, 0xD8E7F220D8282DA7ULL, 
            0x86C13FE2DDF62484ULL, 0x01FB7621DE666C37ULL, 0xA06253D281FA57ACULL, 0x18DE267685A5B7FDULL, 
            0xA8CA3F2DB35E5D08ULL, 0x382310600784473EULL, 0x2EC55E48F7557FB5ULL, 0x3051263466D32388ULL, 
            0x949CF6BD1607F466ULL, 0x24A13549699D26BFULL, 0xFF17E19B8E74B42CULL, 0x89F5BDD6EA938712ULL, 
            0x8435DFD811A2BA5CULL, 0x6690BE186C2283C9ULL, 0x89D2791ABB0F0C75ULL, 0x5D9BC09BFB146167ULL, 
            0x77F88F2F6A011730ULL, 0x384A4E233E909EC9ULL, 0xFD885FA67AF799DFULL, 0xC5619D8CE846AB07ULL, 
            0x2711FBDA02507E66ULL, 0xA201E4037903B273ULL, 0x241365B170DFD4B5ULL, 0xC69E0445C82301C6ULL, 
            0xFEFF85BBF6709088ULL, 0x5ECDF8ECA4012C03ULL, 0x9F0D732DA69E0291ULL, 0x0C54C1DD9D2F5689ULL
        }
    },
    {
        {
            0x360F97DF038DB05DULL, 0x851E9E7FC164DB23ULL, 0x513512402CCF0A12ULL, 0x914D7992EF06AEAFULL, 
            0xC639920BE4CC9AC1ULL, 0x135714ACBBA7EC54ULL, 0x4BC27D7936D4E262ULL, 0xD1B2D57C3BD05FB6ULL, 
            0xBE4F24D336F9251DULL, 0xA8376EBF5EBD2FD9ULL, 0xA2A9DA2737381CC7ULL, 0x6EC6C4A6E343D8A5ULL, 
            0x61032AC79377CB7FULL, 0x73EE16569847AE1CULL, 0xE64D20C2829C1ABEULL, 0x891952560D76936BULL, 
            0xD5B4C4D9972F2F38ULL, 0x761CE384D11A7448ULL, 0x44F99DFC2F4DFB83ULL, 0x2BBB8CB371DECB99ULL, 
            0x95CDADC1495F0A7DULL, 0x5745745A62E88140ULL, 0xBB8CB6D05EAF906FULL, 0xCFA9E090BDD0DAE5ULL, 
            0x1614DEDDE6FBFA79ULL, 0xAB4889EF02CB5424ULL, 0x43523F36F89397F7ULL, 0xA1A9878777A0ACD3ULL, 
            0x9D9F2493D4DC1CBAULL, 0xCE21923D8B7194D7ULL, 0xC12792D05A154199ULL, 0x78740BB90BE3155EULL
        },
        {
            0x89B3CCA28CFD9119ULL, 0x9D14AEDBB6996A82ULL, 0x5FF0253A83E4E133ULL, 0xB71FD21D60F443E1ULL, 
            0x2ED904B5D9BEAE65ULL, 0x096B986E3584419AULL, 0x290665AD5F34B490ULL, 0xB06B344D11826F6EULL, 
            0xCBAFB4E639A7F707ULL, 0x83376FE09D7FF687ULL, 0x65C020186F761BF8ULL, 0x4430142559DCF1E2ULL, 
            0x695310880446258DULL, 0x4FFAC2CBFFE8BF3AULL, 0x11B044DE3B7B000BULL, 0x14FB289A77B3332EULL, 
            0x8DD886B4D5526DCFULL, 0xB5394135B815BED8ULL, 0x481715C9C1BC2F9CULL, 0x9ECC8E9716E0E3ECULL, 
            0x5B71E837DA365510ULL, 0x86EB63A220D7C8BEULL, 0x592A7A56EEB45D23ULL, 0xF5003271DDCEEA36ULL, 
            0xD35F132C19A9B4C1ULL, 0xE5EB6DA01DEF1DF9ULL, 0x7FAB6FD0904CA82EULL, 0x05F11B5F844EE452ULL, 
            0x26A183304E985ACDULL, 0xDFDEBF079229BBC0ULL, 0xBB2CB9A4F2698802ULL, 0x589D150E9E165FA0ULL
        },
        {
            0x97E98461BE7FA232ULL, 0x069BE130D3EE8AC9ULL, 0xDF24EA6AC491901DULL, 0xFF8B9B1C0D0756A7ULL, 
            0x797BD184866C3C35ULL, 0xD1A1AC4CA29E95F7ULL, 0x757FF763DBAD2CB5ULL, 0xB40EEA4CC8D56A70ULL, 
            0x827510E0A0D19DCEULL, 0x413F8C9D2B223533ULL, 0xEBD88AB76F10B2BAULL, 0x032690C1E3ED56EBULL, 
            0xEA6DF47DAA1F659BULL, 0xFD0E853AB39E9203ULL, 0x9729101D9A1C9C4AULL, 0x3E27FE94A055A0A5ULL, 
            0xDB72A145E94C235FULL, 0x681F53D204F1B733ULL, 0xD8D153137C0A1DEDULL, 0x27117EE9C6CD7D1AULL, 
            0x12E268E51B46DDBAULL, 0x05C816AA7ED04C24ULL, 0x6DF7A551F0BD1B28ULL, 0xD36CBFBD56997897ULL, 
            0xD698958A1542B42FULL, 0x01BC21996E9AE4BFULL, 0x36224AE9EE2C67BDULL, 0xE6974169B89BBB39ULL, 
            0x5845F611FF0B28DBULL, 0xF36A6A6D116AF776ULL, 0x6AC5180B14F12EE8ULL, 0xA16D7F7768CBAB78ULL
        },
        {
            0x4BD9966E2BD62B80ULL, 0x23632E3DB7059541ULL, 0xF3DFDB592BFBAF71ULL, 0x3E0E919DACDB8CE6ULL, 
            0x042056D4EAA14FD0ULL, 0xB16FC11EFA8D232EULL, 0xB34C06F5CE5ABAD8ULL, 0xF1B4A4EFEB6C311DULL, 
            0xBC92280AC277328AULL, 0xDB4E05565521400BULL, 0x6EB0DD3AED902A98ULL, 0x70329A53A95575D0ULL, 
            0x8F5CFEB157444572ULL, 0xEA087CBFE96D1C17ULL, 0xDFE8184E03923A2EULL, 0xFF2D609CDA106F53ULL, 
            0xFD69E29BDF0D5A8CULL, 0x912730DFD09CD09DULL, 0x5660D929E1AE7184ULL, 0xD4D1DDA86231B1C9ULL, 
            0xA7B502B631542080ULL, 0xF963857775FE9497ULL, 0x3F83BC69EE4FDB57ULL, 0xEE39B97CF6D7FC4AULL, 
            0xDC2E8740E5289D92ULL, 0x6EE704728EBB4D10ULL, 0xF958117778729C51ULL, 0x2972A31207235351ULL, 
            0x78AA45B4FB45B74FULL, 0x001E8C67F27447EFULL, 0x1FE7B44A19E18A0CULL, 0xDA9FE37150D40411ULL
        },
        {
            0xF6E0B10DB23583ACULL, 0x2B0F33C2AD7FC431ULL, 0x55A1E86574232C09ULL, 0xC53DC9FE8C1AA786ULL, 
            0x7DF7ADD975696C9AULL, 0x010D1F3339357056ULL, 0x5F2E77CF4F065E39ULL, 0x90B23F0678211596ULL, 
            0xC5FDD6270DC68E59ULL, 0x0A7C5EAEFD369A60ULL, 0x1A84C1EF55393C4AULL, 0x8BC09DFFE089AD10ULL, 
            0xF4AF8BDB633BA32FULL, 0xCE86B4DD7C57D049ULL, 0x6CD7CEB0C8C0A6D6ULL, 0x2E0E9F6A6553EE59ULL, 
            0x22B582838F693311ULL, 0xF0B0750239F0E343ULL, 0xB632FE6BCD715AD4ULL, 0x4155218B832D5435ULL, 
            0x13B8F772FE5171E9ULL, 0x15F0EBDF627D8563ULL, 0x4D44A0BE62009393ULL, 0x161F612378C0D1B6ULL, 
            0x91AC7520650F69DFULL, 0x3178FE6FECBB4535ULL, 0xB3C25ADFC9E3C4B7ULL, 0x04CE0D84AC016A8EULL, 
            0x423AA38E365CB059ULL, 0xDE50417682C59815ULL, 0x19E13DC5354C9B1AULL, 0x507C90235B304294ULL
        },
        {
            0x1AB91EC79E8712F4ULL, 0x9255CE70F5AFFCABULL, 0xCA13D845B6114989ULL, 0x40D8B4031470F275ULL, 
            0x19288F29104F0AEBULL, 0xF3D9EA5CB72B0912ULL, 0xF02446A5EF182D5EULL, 0x3BD404DF2E0E5163ULL, 
            0x8AF8971CEE0C8126ULL, 0x19642B23654A21AAULL, 0x22CBB1457D76DF6EULL, 0xEF1FA5617833B3E8ULL, 
            0x0FC5AE55B3867234ULL, 0x62A67D3DCA2DC852ULL, 0x1C124AEB4E951A2DULL, 0x6CBE4CCE23DA27C4ULL, 
            0x2304CAB9AC07ABA9ULL, 0x47E407E8339DB901ULL, 0xBDC5CFF33A2C9885ULL, 0x860FCA6FC136CF28ULL, 
            0x187D581EDA66A787ULL, 0x6207D3BF0FCADE1BULL, 0xCC36633722F6D209ULL, 0xB1C3A93C40CDF4CFULL, 
            0xF5B696645982DF5BULL, 0x94B5A75DB2057C9CULL, 0x2AF8CD5E1AFC186FULL, 0x74CE98757B19773CULL, 
            0x6288C8F9D46283A1ULL, 0x10DA92481240CB65ULL, 0x808BDB8A758400E0ULL, 0x540C62F6D76BFCE3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseFConstants = {
    0x5626AE42DDB44A9DULL,
    0xAE7806EDA0A224E1ULL,
    0x0A424195EB14E2D7ULL,
    0x5626AE42DDB44A9DULL,
    0xAE7806EDA0A224E1ULL,
    0x0A424195EB14E2D7ULL,
    0x87B04F50413231D1ULL,
    0x50589CE9C333CDA5ULL,
    0x82,
    0xD5,
    0xC4,
    0xCD,
    0x2B,
    0x2A,
    0x57,
    0x45
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseGSalts = {
    {
        {
            0x35B173A9EC77501EULL, 0xE0584BA43CF2BF4CULL, 0xC42C3B28D129B487ULL, 0x9544599645DC1870ULL, 
            0x7639F3E1FBA3F48FULL, 0xDD8FB6AB3E53C648ULL, 0x98D9405A29518C8FULL, 0xE5F3A7F43BA11B78ULL, 
            0x8278E1DB846DD6C9ULL, 0x7FF07E05060DC6DDULL, 0xBEB99D0CDF64F286ULL, 0xC15E7D77E1E368EDULL, 
            0x61AC4BA853FAD1B5ULL, 0x1B83AD7E2B56F1BDULL, 0xA3267A8B3C37A206ULL, 0x3E0ECA5B8E5C30D6ULL, 
            0xB469FC883A947B18ULL, 0xE3256B687EE2E301ULL, 0xC901A12EE5DAA148ULL, 0x227DD46987AFA29FULL, 
            0xEAD75A4B296E6C13ULL, 0x97413ABFF0E8E707ULL, 0x1615CFDAACE98EF4ULL, 0xCC7B2784527DA975ULL, 
            0x6D0B771888DA6EAAULL, 0x7FF0AE170C9FA5D0ULL, 0x6A1A48DB2596EFB7ULL, 0x059DD531133B61A0ULL, 
            0x07903A37E20C1B5FULL, 0xC9CE113316F04DFAULL, 0x960B32531012090EULL, 0x29F89EED106E9DE5ULL
        },
        {
            0x4F050B74C1B9FBFDULL, 0x71382A0E412BE312ULL, 0x1168A3231F7E8615ULL, 0x9EE9D119EAA89298ULL, 
            0x52C1D4540BB554B1ULL, 0x0804C88778DF0F5EULL, 0xC0B372A80BB2E798ULL, 0x97FB1CA1E6921EB2ULL, 
            0x2FE6B0C93E387D42ULL, 0xF1658AE906D3B779ULL, 0xF17D0443157A4A60ULL, 0xFD93B49AFDD7A4E7ULL, 
            0x5AC44CCF7BED099FULL, 0x60E1FD84FB0195B1ULL, 0x9B2457F1524B8B48ULL, 0x76D40CF974E16E31ULL, 
            0x0692211F213D4131ULL, 0xC8143E72FE0A72FBULL, 0x6B0B06C606E9E430ULL, 0x5C2D4CD0F49498DAULL, 
            0xB7E853B4F78C58C9ULL, 0x2BDCC6C7B7A99352ULL, 0x685376AF922C3D17ULL, 0x5B83AF5E5CC8A407ULL, 
            0xA7F74BBCF82E2C8CULL, 0xDDF67C7B23B7A886ULL, 0x01ABDD16D4276097ULL, 0x9BD1F8A5E56C37DCULL, 
            0x2F1029E793A9CB6CULL, 0x0EC159E1B2038454ULL, 0x1A52B70B12E314A1ULL, 0x684C2586BB5C1D6BULL
        },
        {
            0x88573B8A0C022B78ULL, 0x0C0EB4FF8C9C9A25ULL, 0x8FC8F07E221A18E7ULL, 0x62F6CA173DBF5A1CULL, 
            0x02DF4584E7B8E28EULL, 0x3C05D9F9374CFDE0ULL, 0x834D8D1928DEF18CULL, 0x581A715E3B64A6D8ULL, 
            0xAC566CE93C2D6C71ULL, 0xB4F816F7354975C8ULL, 0x705238F8809B27D3ULL, 0xD960D6F29C75CBA8ULL, 
            0x9238BE3D69DF96BDULL, 0xFB0576FF61081E79ULL, 0x58371CD15C267944ULL, 0xA1DC78405CE36C72ULL, 
            0x37B76D14DC12E8E4ULL, 0x9D875C9E7BBEFF28ULL, 0xF4A92A0B7CDEED16ULL, 0xE0B0EEFA7CA770D4ULL, 
            0x8D03C3CBE84F0A88ULL, 0x2FC76D5835FC5C60ULL, 0x23EE5DB4A9040D3CULL, 0x8B6CE1A5B66E0E44ULL, 
            0x642E7175E1490E54ULL, 0xFC9B5CFFD9C9E8DBULL, 0x6429984C3AF48EE0ULL, 0x07355500ED275203ULL, 
            0x1E24D4C14B13CBA5ULL, 0x2E9D0E2C37361D63ULL, 0xD01151ECFB8A23B1ULL, 0xEAB201DF0BE3A61EULL
        },
        {
            0x73D93E02678968B4ULL, 0x1F9947FEC27EC226ULL, 0x9131167522AE7DA2ULL, 0x38168049227227A2ULL, 
            0xF61EA88075A1F6A3ULL, 0xE2B3AA41ED4087DFULL, 0x4897DAD5378D2C5CULL, 0x96AD6609F4937740ULL, 
            0x4C394D7EBFD4767AULL, 0x5B1F73C9FA31A8C8ULL, 0xE47B79B79A7598E8ULL, 0xFEC5F50FAF076E56ULL, 
            0xC07A22900D80B68AULL, 0x43040F10555DB64BULL, 0x422ACA6F452AD5CEULL, 0x1F1BEBCE85BCD752ULL, 
            0xC889141620753E92ULL, 0x5512F34FAA2AE3C4ULL, 0x1674B2EFA23BD161ULL, 0x5BD368156B5053ADULL, 
            0x78F5DC7C105BBA17ULL, 0x6E02DF31A04AAFBCULL, 0x7549C58DBEC2050DULL, 0x0EA893C5E99B8FD5ULL, 
            0xB76111D5ECA557B3ULL, 0xA45DB66D0C2222BCULL, 0xB496309E589ABD5BULL, 0x2FE0A4BDE9BA0F82ULL, 
            0x60052C2AE0025170ULL, 0xF1338FF7439ECBB6ULL, 0xBCA9E7D1B4A2F3D9ULL, 0x394B79BBA9476B15ULL
        },
        {
            0xD83C9E93254DD69DULL, 0xC0D94303CC089F70ULL, 0x8B903C201F188E8DULL, 0x6B0D949294EE1250ULL, 
            0xD31E07FCC23E2975ULL, 0x67E1B89ABA579BD3ULL, 0x6A5F7A34777F04D4ULL, 0xFDF50386571B5B27ULL, 
            0xB2EEAAE307B7BC7CULL, 0x51DE2AB481D25F0CULL, 0xD2B945FFBE4E0AD5ULL, 0xBC764AEB18C8B5ACULL, 
            0x442076340B03C99DULL, 0xF032500DFE306F7BULL, 0x14DAA1359854A58FULL, 0xF384BC7A540D4EC9ULL, 
            0xCB45E11936AF4C48ULL, 0x8EEAB5C64EF367A8ULL, 0x0EBB6409277FEC9CULL, 0xBB066DF34E05FCC1ULL, 
            0x87B69D1738C12E77ULL, 0x12E1D77B09FDF543ULL, 0xB92B687DF7410FF2ULL, 0xE7FF6B1AB2939363ULL, 
            0xF055CBB22A04FA7AULL, 0xC8D240F8BE6A48C0ULL, 0x39CBDB5756A6DB98ULL, 0xF2625147C2296812ULL, 
            0xA49B6CD05CC114FAULL, 0x9790D58EE9DB70ECULL, 0xA94174ED189BA36AULL, 0x58312E200B73E750ULL
        },
        {
            0xE31D729501EE67F3ULL, 0xFC88F181BD6E70DDULL, 0x2C64102008112F77ULL, 0x692AA65B16843319ULL, 
            0xCA35DBA89911050DULL, 0xFA012BC2173BD6E6ULL, 0x6214DAD9C48DF991ULL, 0x48CECBD96A0A9AB1ULL, 
            0xEAD58D9E1512C176ULL, 0x3931AAD19E341435ULL, 0x683E7DBBAAC83580ULL, 0x1789656C4A5E5093ULL, 
            0x743461E6F3BE1A22ULL, 0x002E551984DDCCF3ULL, 0xC4F069E75EEC7ECAULL, 0x7EDFBB2D291C6F99ULL, 
            0xD6A05FA729DB2BC0ULL, 0x51BD0943F81C3AB4ULL, 0xC23143F2B411CA71ULL, 0x5061F89E2FEA5CF4ULL, 
            0xCDC825744BF15407ULL, 0xF902EB4E4409DBA8ULL, 0xCDADB77D5AB56426ULL, 0xBA571A280D201208ULL, 
            0x000732F636358A81ULL, 0x3752DFD385913DE6ULL, 0xEBB8ADBD047CB73FULL, 0xE762886661D20721ULL, 
            0x32982B711A828E0FULL, 0x0B8F4413261D62BBULL, 0x637DB3F5F8DF2FECULL, 0x06BEE96550163412ULL
        }
    },
    {
        {
            0x561FAE4785E52CC3ULL, 0xDA8D392E219F3A0CULL, 0x2C4B1AACFA00B83BULL, 0xC3F27FDD2F3C0BCFULL, 
            0x7AA4CE2F40A1E47FULL, 0x1B747A696CC4ACBFULL, 0xC647AC7974A2C8FDULL, 0xAEEFC76CEB46EDB4ULL, 
            0xB2BC81E9EA2A9469ULL, 0x425422B4759A2F4BULL, 0x6FCE25A1E1E94ADEULL, 0x852EA65FA1628047ULL, 
            0x4EE22CE51F69A4BFULL, 0x005C53CDE3CF58D6ULL, 0x9CE3952725C3C86EULL, 0x73A04F5647E17B48ULL, 
            0x2F10E6773EEE6568ULL, 0x88740EF504D825AAULL, 0xA588412F6CEF2378ULL, 0xEE87F39A111E649BULL, 
            0xA377A82949C7BFD4ULL, 0xA36ED729BA728BC3ULL, 0x78A5F4122D8685E9ULL, 0xC91D0D58665E4EBBULL, 
            0xD07BBBA4B32744CDULL, 0xDD6118DE0E56C7F4ULL, 0x72B46F150ED02337ULL, 0xB4EB731B55CF5571ULL, 
            0x0C127BE28F51A32AULL, 0xA177F3427F294F61ULL, 0xD8C2C869B5A31525ULL, 0x4AAFF4900D522635ULL
        },
        {
            0x75F3EB32B09A9B28ULL, 0x38FD2E7F6D91E23FULL, 0xD6EC8176CA2F2500ULL, 0x2BD6C8D4824BBE39ULL, 
            0xA5A625957A7977DDULL, 0x3DAE2AA56B58D33CULL, 0x5EB09595B3DF192FULL, 0x9C86CFD860D21BBEULL, 
            0xB8D79D1372553EA6ULL, 0xA1A17C95BE76833AULL, 0x2D7F9D9B7352668AULL, 0x157B1671E33D70C8ULL, 
            0x0BF213BEC8EBDA71ULL, 0x0834CA470F027284ULL, 0x98DCF3E2BC731085ULL, 0x48E96C59F7A94A27ULL, 
            0x5C17F8D4CB651DF9ULL, 0xF7EFE3168ED7A38DULL, 0xF1DDBFDA7E6E285BULL, 0x110BE45C6097F16BULL, 
            0x7CC161AB8E69D710ULL, 0x0EEB034FC715A533ULL, 0x8C7C39FB747D6A34ULL, 0xEFFCAFA6B9D77665ULL, 
            0x1D8B4C8C39738695ULL, 0xAD1A1F24C2EE64B4ULL, 0x912AD6EFEC454373ULL, 0x57AF0BB1D901E417ULL, 
            0xE889A1FEC19E5FF3ULL, 0xC54D9B52D9832035ULL, 0xA17D2B728E10D98DULL, 0x20D0C9D38E37159EULL
        },
        {
            0x0C3669B658B501E8ULL, 0xF4020CA75BE5BDF5ULL, 0xDBC1108FAC4262D4ULL, 0xCFFD46BF5E18E2DDULL, 
            0xDFFA46BA38EE2ADCULL, 0x917A55C983863AFFULL, 0xDF054A3BAF651A81ULL, 0xEF4819BE823AD5C2ULL, 
            0x689643580FD777B1ULL, 0xA0C3A9185054B706ULL, 0xFDE43AD6514247AEULL, 0x47689701513435BEULL, 
            0xBFB8CE9F1DB0BF72ULL, 0x88645B9C2CB3E6D7ULL, 0xC09AF182FF0A9663ULL, 0x5B4EDF8D7A8371ABULL, 
            0xB3866C5481396278ULL, 0x888C9875A6F1E2BDULL, 0x3C83106C46DC0428ULL, 0xC17023F98FA4F254ULL, 
            0xBCFA2CC5959077DAULL, 0x8555452965E9328CULL, 0x7D55F19D25784B66ULL, 0xD5D5ADD674980F39ULL, 
            0x4D3C98A4EAE3516AULL, 0xE829C3B8ABB3DD5CULL, 0x26FB9153BB414BCEULL, 0x9061269BF339B10CULL, 
            0x5166991E319017BEULL, 0x83D3CCBCF50CBA38ULL, 0xDF98FDC8BA5715E1ULL, 0x6BDE4F1977223CFFULL
        },
        {
            0x0EDDBE61B392673BULL, 0x0D89F97C11887D70ULL, 0x8AF84A94E32AD770ULL, 0x4E8988A98193A652ULL, 
            0xF7D62456604349E6ULL, 0xBC6E652D709867CEULL, 0xEEB5202B012C4C5AULL, 0xF5F158183A611926ULL, 
            0x70DE5C2643B0A5DCULL, 0xA6CD41AAD719BEC0ULL, 0x2B7A40BDE447D73BULL, 0x2C5C1D9B402FE378ULL, 
            0x97B57C0027354EADULL, 0xC8CE117115A59AECULL, 0xBD707F9FF922A2CFULL, 0xB5DF057739A3CF40ULL, 
            0xF9B26FC710B5B5B8ULL, 0xFE2633C45BCCC0DDULL, 0x48B336C6D6D258AFULL, 0x50C7AF51AFD5A5E1ULL, 
            0xD88D4065BE3AFC9CULL, 0x30C4CECD601D9AF6ULL, 0xB9E239A72A8DF81FULL, 0x3F148324170A5AECULL, 
            0x16F0195CD23CE339ULL, 0xB7CA5877B83EBF3AULL, 0xB8661FB8D9657D47ULL, 0xF33B50F52271E53DULL, 
            0x1D7F08519DCDA034ULL, 0x1AAA19F5D9BDB2E3ULL, 0x3D1C4F371B1F1442ULL, 0x08B6365500B2A7FCULL
        },
        {
            0x83928D446C7B1EB9ULL, 0xE33F6BEA8F91A9A1ULL, 0x7002D5FC614180EDULL, 0x53758D63F2FA6C01ULL, 
            0x640549CA634A286BULL, 0x30B84069CCF6DDA5ULL, 0x93B68EF15E8F075FULL, 0x88229E4FEE01DD87ULL, 
            0xE4D58C66A3C9FE5BULL, 0x4FFFF1F8158EA020ULL, 0x575C825289F97FDDULL, 0x534E9BC9F7D0E95CULL, 
            0x2F8DCD798CA2439CULL, 0x260BC54E6F141520ULL, 0x8978DAC97A26F184ULL, 0x4DDE41948A350904ULL, 
            0x2E7562B69522DC7CULL, 0xE574F0EE57D324D7ULL, 0xD180B0AD63DF369CULL, 0xC3A1E34CED9D70D1ULL, 
            0xBFFF18B77FD50698ULL, 0x16E814C2EF6F2DC2ULL, 0x4A2405AB8977C9C9ULL, 0x8E4FBEFDC4B01C85ULL, 
            0x959383DA5ACCA3F6ULL, 0x422C775BA4526620ULL, 0xA0192BA1BCED2A73ULL, 0xAC0C8A019EEBFD7AULL, 
            0xCF2DC30AA5781E64ULL, 0xD7807DF97454D017ULL, 0x8577C3ABAD466D89ULL, 0xABB6BF1B30AC4424ULL
        },
        {
            0x93476E86C5709848ULL, 0xD93D661C840E1C07ULL, 0xAAD2393BAC8E495EULL, 0xE2449463ADA3B54FULL, 
            0xD9FEAEF3516F246FULL, 0x6861DF5943C0ACA4ULL, 0xAECA5124A9083830ULL, 0xDA426084BA872E2CULL, 
            0x66B3F518C338685BULL, 0x9A5EA581595F89D6ULL, 0x714DBEE424264C66ULL, 0x3DC8B54A48EC384DULL, 
            0x9CEA46183AE5502FULL, 0x8B9E75DBEAE97EB2ULL, 0xFE485B13BF2D6B19ULL, 0xF6EE290911D890B9ULL, 
            0x07C06145CFDA39DEULL, 0x971EAF3E81D10FB4ULL, 0xD87EF6705FF47798ULL, 0xDE53FF54BCA0919BULL, 
            0xD5BC7794C2EA419AULL, 0x9E91D3FFB6BAB7B4ULL, 0x016F2F2BCECE92A3ULL, 0xB2BA2BE2C8F7BF45ULL, 
            0x9DA519074AEED483ULL, 0x6AAC12EC29ED5197ULL, 0x684F2470D720A7B4ULL, 0xE8027633C53F9064ULL, 
            0xEEE158C4E85EE53CULL, 0x3DF9DCAE7CB7E3A5ULL, 0x3A0CA49245543C27ULL, 0x9A04CE387A236E80ULL
        }
    },
    {
        {
            0x48800C4A281C89E1ULL, 0xE41E72290BC397D3ULL, 0x17EC24656959D896ULL, 0x432AF06500137A97ULL, 
            0xAD6C8337BEA613BBULL, 0x16FE98E9FEFAB933ULL, 0xD2660E2E8BE7E9B0ULL, 0x8EADABD8711BC994ULL, 
            0x617F17E9952D74A4ULL, 0x3F89681EF53CCB9EULL, 0x74BEE827770B86BCULL, 0x4DF4D56501F8D472ULL, 
            0x8ECA1D20F7E8549BULL, 0x325D9B8E18EF60FCULL, 0x4EAFE2354CBB9EDBULL, 0xF48E00443B81CE81ULL, 
            0x55AFDACABFCF20A1ULL, 0x5E6E00F3011CBD19ULL, 0xBBCC383082E3B51FULL, 0x2C7C58DA2B68C03BULL, 
            0x92AEBAA0044D0C57ULL, 0x70DD749998C331ECULL, 0x9790C5F4C97E48ABULL, 0x72E059EA3FCB3B1AULL, 
            0xA0465E464EBD0238ULL, 0xED301F5CBD400553ULL, 0xB39C93AF8B13D601ULL, 0xC05DFC9400E6571EULL, 
            0x40BAC497C13C673CULL, 0x0F04E6250967BC82ULL, 0x54C7AEEC035F1FA2ULL, 0xCC8AD68B4C44B6B3ULL
        },
        {
            0xA99596D01B9651E1ULL, 0x68A2D6FCAB081D9DULL, 0xDDD6BDE315D00AC7ULL, 0xF951C75236B7D0DBULL, 
            0x0B94A9D950FB47D9ULL, 0x698D632861554B9BULL, 0xFF052E1610020B3CULL, 0x726413F9150B32EFULL, 
            0x88387C253A0F4C01ULL, 0xE255E5FF6340AB4DULL, 0x130FC26F700F806DULL, 0x3BB92196A5C4B2E0ULL, 
            0xB43158D113F2D3FEULL, 0x0CC3EC7A84A751A2ULL, 0x3CE693388F33E0B6ULL, 0x5C6F3FD811080644ULL, 
            0x2A736F048CFF2B33ULL, 0x8D6F7BD95C8B061FULL, 0xB157CF8E26950C7DULL, 0x3CF52EF1015B5C72ULL, 
            0x83899BCE5F65D648ULL, 0xFDB58A0BFF0C383DULL, 0xD05C94CFA66DFB32ULL, 0x0BEAD78DE48EC92FULL, 
            0xBA611055A4B23940ULL, 0xBF8127ABFCB5E713ULL, 0xBBFF131510DB08D0ULL, 0x9FBFE48525CA470FULL, 
            0x777D17C812D199CAULL, 0x92E9FEC32F3E2562ULL, 0x551F5A508C6D042EULL, 0x3FCF5C568D3A15E0ULL
        },
        {
            0x1C3C63688C042113ULL, 0xF902445EE1778EA2ULL, 0x788BFB3A2A9F4731ULL, 0x9601F8F2BF2B87E7ULL, 
            0xF431F772C09170CEULL, 0x5CA0145EE183E414ULL, 0x06A364606407D3D2ULL, 0xB1467C41CDE7908DULL, 
            0x4CC1D99F651BBE27ULL, 0x389BFDA0613ECCA6ULL, 0x2F38C10BBBF42F8AULL, 0x611406A6F1C7C245ULL, 
            0xB91019278139E5C2ULL, 0xA883ABCE0F6D45F5ULL, 0x90B8558E1FC2DE5EULL, 0x0B69118BA8005AA5ULL, 
            0x2C20C78239B33451ULL, 0xC7F4CB8E73187A7AULL, 0xD9E85CCAE686A7C4ULL, 0x603ECB5CF162332BULL, 
            0x70E1354E221DFCA4ULL, 0x2061A24468C71EDBULL, 0x49C1A23A478BDB8FULL, 0x22F4C584FDF14DDAULL, 
            0x7AF37D00698F6AA5ULL, 0x3187436B83FA12F0ULL, 0x30571441F9814D94ULL, 0xF60EC6460831D331ULL, 
            0x6980E3B7C8A118CEULL, 0x6398E1358D13519FULL, 0x5F14AA38CB72C93BULL, 0x24559A6A328F66F6ULL
        },
        {
            0x13CE19D7A984D9BAULL, 0x85CCE60DE3437E8BULL, 0xAB1A3CAA206D5437ULL, 0x0B32CAE0A7A55EF2ULL, 
            0x86E8CD5413EEA738ULL, 0xE1E8115440862287ULL, 0xE7FB8584444BA4EBULL, 0xE9594FF5624D25EBULL, 
            0xF54652F6C23EE67EULL, 0xCE6B056C336BBB0AULL, 0x7204AA13F2EA9E49ULL, 0xA91A33868E3DB506ULL, 
            0x3CE5BDF356F4FC5FULL, 0xE32734A91F702548ULL, 0x5375C69062765AA8ULL, 0x50D35845A8A97E19ULL, 
            0x81681DF3B715D1AAULL, 0x2F90D0FFA145305AULL, 0xD98A991BC7DD68D8ULL, 0xD839ACB6927D70A1ULL, 
            0xDCC289E279840079ULL, 0xAF4E5BCB3139E25BULL, 0xA7CE7E95C3997135ULL, 0x48A611F2699BB57BULL, 
            0xD339B5D63A63BBC5ULL, 0xEB21BA4EC698E8C9ULL, 0x22F352FB0C945266ULL, 0x915B5F7746E1EF88ULL, 
            0xD99C295A9D486F9EULL, 0x7CDF4CA2F785CD51ULL, 0xD429A5B63615EB7CULL, 0xC09DA9A733C60D27ULL
        },
        {
            0xF0FB03A7F0566942ULL, 0x1216A5F23D7C0A24ULL, 0x4D36A18F6A7D6B66ULL, 0xECD1A3143F6559A0ULL, 
            0x5720AA815693D61CULL, 0x47535B32AC5D969BULL, 0xCF07DDA3168AD123ULL, 0xAF7A0BD28477735CULL, 
            0xF4418F4285571FE6ULL, 0x60A559654C3D065EULL, 0xF46D0D36D7C0742BULL, 0x6E64D22105D3FC4EULL, 
            0x3A45C7789D93F310ULL, 0xF2DC6BB95C916008ULL, 0x91F099962DBDDA56ULL, 0xAC03ABB6C6D57459ULL, 
            0x5E88DA2899421DC9ULL, 0x9F61BFC67E85C298ULL, 0x8D17EC9A6B830754ULL, 0x3E569F2D4D39EF4BULL, 
            0x14BC6865FF5D4E5EULL, 0x8CE9CD2928A49B5DULL, 0x6831596F648490C0ULL, 0x009B7EC5F8AD467BULL, 
            0x7750B800F1E36325ULL, 0x80FD6D4A3B08E744ULL, 0xB82B6DFB584B0AC6ULL, 0x14266FB180F4AD14ULL, 
            0x6D692D17E9689AAAULL, 0xCADD2FF4BF37EB3FULL, 0x419F7A614364B3B2ULL, 0xF5DB6F7041F70C82ULL
        },
        {
            0xE32B38554271A0C9ULL, 0x0E53E76E621D605FULL, 0xC9011D7F3E29E73EULL, 0xC6588A988FCDABC2ULL, 
            0xE4A51F19A04B4F6CULL, 0x94BBC1928D9A08CDULL, 0xB7AED0D135A41874ULL, 0x7B7148EE65D8D48BULL, 
            0x04CDD71B9945BCCFULL, 0xCFDCE3441FAB2394ULL, 0x1198FDD383DD0195ULL, 0x9D0700A878D9911FULL, 
            0x5EF50FDFF9A1D4D5ULL, 0x61909AB13C5FF279ULL, 0x018719A26D4DF5E6ULL, 0xE4DF856AF6CBFB41ULL, 
            0x9E031B3CEA0F6491ULL, 0x571F2909C1A7F051ULL, 0xCA114499B6AD288BULL, 0xB7EB1F9887A00FF3ULL, 
            0xFDC21CD9E01BF1FAULL, 0xBD7B01286308A4E3ULL, 0x8FE82B210B5639BAULL, 0xC31961721B50B888ULL, 
            0x0B8849C153A01E43ULL, 0xB07FB5C9C2097790ULL, 0x77B2E731638E621CULL, 0x1A978455F800216EULL, 
            0x9A116B4552CF9B6CULL, 0xD05A17180F8ACBAFULL, 0x5C4ED98AB2B10234ULL, 0x8BF1CBFEA6784889ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseGConstants = {
    0x7BF1B836BEDE333CULL,
    0x48873165AF3C857FULL,
    0xF84D9646485D8369ULL,
    0x7BF1B836BEDE333CULL,
    0x48873165AF3C857FULL,
    0xF84D9646485D8369ULL,
    0x7F65BA52959B76C8ULL,
    0xF6381FC63CB45CCEULL,
    0x84,
    0xAF,
    0xD2,
    0x29,
    0x48,
    0x8A,
    0x27,
    0x6B
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseHSalts = {
    {
        {
            0x6FB8DBE103437BFDULL, 0x65A6974A19B151B7ULL, 0x2F31F6F2E18BE819ULL, 0x7BC640029B58BFA2ULL, 
            0xD6DB6BACADEFD0DDULL, 0x9EFC7F6C502C5ED1ULL, 0x5B7A4B4DD3AD6BBAULL, 0x0DE80D3FFC255D03ULL, 
            0x4FA4A778B6B19B23ULL, 0xCEB0D5F76960D11BULL, 0xDAD0ECC9E7E21361ULL, 0x8C3C3408BC307A3DULL, 
            0x7E3CDE01529944C8ULL, 0x92F6492C00969B96ULL, 0xF20BEAF8078FD1C1ULL, 0x96BCE54AE33885E3ULL, 
            0xC7466D3725D1F98AULL, 0x0297E10C8EF7BBDBULL, 0x1C45E04DD4A80CD2ULL, 0x8D9A538378D349ADULL, 
            0x4730451428123264ULL, 0xB82D011A65F84A9BULL, 0x1D9E712AD4E13F82ULL, 0xF36F09E92BBAE183ULL, 
            0x3F8061DE2B6F3651ULL, 0x43FDE5CFD15CCE74ULL, 0x9DB3F8861C64EC41ULL, 0xE026E60BC81794ECULL, 
            0x5DDDC4BEE279F14CULL, 0xEBB34B27BD0D6FA0ULL, 0x6E6469590B74290FULL, 0xFBAAF9B2426F417AULL
        },
        {
            0xAE04207A6E4A2763ULL, 0x4DBC377D2D8DA036ULL, 0x8411DD425252C88EULL, 0x263A734772856064ULL, 
            0x5BDDDC6F3DFE3402ULL, 0x91DCAC51C8ED9348ULL, 0x1449A71B5A5E8D3AULL, 0x9915673F25A2989AULL, 
            0x08748703F99668C9ULL, 0xAB30DB8797341DF2ULL, 0xF8F6E70B77ED34DFULL, 0x36EDB671E34D4694ULL, 
            0x977DAC6EA706A4B9ULL, 0x8EF8B86689F7E1B9ULL, 0x92EAC468B45C26CBULL, 0x3BE7853304D34CAFULL, 
            0x96303523641E06BBULL, 0x13658BCB2807DE92ULL, 0x0F36799C3E784586ULL, 0x40D8EB08E88AAB10ULL, 
            0x0BA24A15A535342FULL, 0x5CBAA4F02F9AF1F2ULL, 0x7018675D97A28963ULL, 0x1B750E0EA5425A8DULL, 
            0x7BE1FCB945B695C5ULL, 0xCE95277F564BA26EULL, 0x06D53B099FF180F3ULL, 0xEFD2EDF9385E49C7ULL, 
            0xA9E517899A1A1BCCULL, 0x3BAD17315206910FULL, 0x6D6B57C117B2D782ULL, 0x2265F9D7BCFCAD6AULL
        },
        {
            0x89285BA0B4A9CC10ULL, 0xA16835DB382155C9ULL, 0x401F37A5959544C6ULL, 0xEF8E6C8A4782D919ULL, 
            0xF92FB2B6E160DCD6ULL, 0x0E1836F09543630DULL, 0x47C5D0AD07B210BEULL, 0x24FB11B19295CCB5ULL, 
            0xFB2F45048F837477ULL, 0x45CFD69F9CE4CA0BULL, 0x7F5AA4677D0557A0ULL, 0xF46342EC3B669853ULL, 
            0x91E0383204939AF6ULL, 0x5C655BDCFED84523ULL, 0x5DFA701F522FB84AULL, 0x34A81642FE328285ULL, 
            0x416E5C40B49E5043ULL, 0x2B0C2849FACDEB8DULL, 0x9744EF7DB0668C13ULL, 0x1B17EB5BECE8C8A9ULL, 
            0x0712F5F054A21052ULL, 0x1A398487611943BDULL, 0xC25874B615CDF71AULL, 0xCB75AAD871A78F1DULL, 
            0xA7D1D4056DA8F513ULL, 0x41275B1144D9F973ULL, 0xAA7E73279EAA8DEDULL, 0x38E9DC04C1D823C3ULL, 
            0xEDAB257831881706ULL, 0x13CD4846CDBABC6CULL, 0x76F6EB2445CB1A16ULL, 0x8A704EE5F541EEA0ULL
        },
        {
            0x6C215C691C8C240BULL, 0x9E550E5DB3677336ULL, 0xA8D956EE8ADA172FULL, 0xCFB85D75CD57C714ULL, 
            0xC815264361B5D3DAULL, 0x4B6D21ECC4B01DBCULL, 0x0357DE535DC0E44EULL, 0xE7FB750DF3297183ULL, 
            0xC0B7141FAEDED49CULL, 0x1EFF108CDA470761ULL, 0x3EF04B8C9E250520ULL, 0x011A3A1DFBA15E1FULL, 
            0xD2BB51D1CC4AABDAULL, 0x24540EF0105AC37EULL, 0xCE76AEBB2E079610ULL, 0xC79AF45AAEE5E673ULL, 
            0x1AA802FBA99B464AULL, 0x1777B28D27D6BC39ULL, 0xB7749B978A9DD1B2ULL, 0x8239867D36D45B69ULL, 
            0xA107DC0D701DB98AULL, 0x1A411D395E72525BULL, 0x3D92AE0429E408A0ULL, 0x83C9F07B94EE6C48ULL, 
            0x298FDA4E12886FF4ULL, 0xA36B962C6F7975A8ULL, 0x7177680B5B760A90ULL, 0xEBD8ADC911872F3AULL, 
            0x35708AEFBDDD1FE9ULL, 0xAF42B90D527C8D73ULL, 0xA06DCAFC3FECA9F5ULL, 0x65DDA0F23AD3646CULL
        },
        {
            0x080931442D4226EFULL, 0x039F94F65896E500ULL, 0x5EB3184EFBBCE9DAULL, 0x187D232CAAA63183ULL, 
            0x13696EF3A60602DFULL, 0xEDABC11DD17A5C8AULL, 0x5226DEC663333C49ULL, 0x744E24C269417FA6ULL, 
            0xF745DA8CAD0E285EULL, 0x8EFC1D45C1DB7626ULL, 0x1971BAAA744C743BULL, 0xC9C386197AFF6AADULL, 
            0xB6120F8483E1F6B3ULL, 0xF6C5CD15C3EA10ABULL, 0x8204564A4F78FF6CULL, 0x953311583730A56FULL, 
            0x6FEA2505FB57D69EULL, 0x18E026ABF5109B1CULL, 0xA9E777D5BE0235D9ULL, 0xE14407503B7E78D5ULL, 
            0x0509EF7B0754D402ULL, 0x35120580ECDA526EULL, 0xEC3E9E06D1ADFF8DULL, 0x5F84081BF45B3E98ULL, 
            0x5130EE8DA469C99CULL, 0x1FBECEFFB15D45EFULL, 0xA6B19C3911A48EA6ULL, 0x8BE3E0658102AFA0ULL, 
            0xB923EE9EB19BB555ULL, 0x23ADB701C4956FEEULL, 0x9C1499684A67CF6CULL, 0xCCF38268EC047674ULL
        },
        {
            0x968D806545D2C954ULL, 0x6C90F740F22E15EAULL, 0x3A939DDADADD6D17ULL, 0x3F6A815D89C15BEAULL, 
            0x078071FF22DED2C2ULL, 0x4EC08E7FFB07E8F5ULL, 0x7DE306BB8CF56276ULL, 0x21EABCCBFBEF178DULL, 
            0xE82E5A97418A61BDULL, 0x3CC96F2FF02A82DCULL, 0xC9AB10F28FDF52FAULL, 0x7A0DAFFA54A4C0F6ULL, 
            0xC88EC461A3618598ULL, 0xED6B7EEE35B76477ULL, 0xE26FE49B92651225ULL, 0x8311C1733EB37B6DULL, 
            0x66BFCA6A1D6EF947ULL, 0x8C708BFAB56B62DBULL, 0xCF8D52A8C7DB9B98ULL, 0x688991EE1E3B23ADULL, 
            0xF41B50116D7BAAD7ULL, 0xCDC0F5F4D1C5CC92ULL, 0xF997127CA311D1ECULL, 0x1A59B7AC70B2A332ULL, 
            0x917C06D3D2F9BA56ULL, 0xD5CF99168E5A03C9ULL, 0x586B423DB7FBF9E3ULL, 0xA6687D4C51C82595ULL, 
            0xF2B6C39651911E14ULL, 0x19EBD43490BFEF9EULL, 0x5E5E63ABCC1CD074ULL, 0xA2A963023F0FDEDEULL
        }
    },
    {
        {
            0xE3A2EB2262116954ULL, 0x1E959B24BD7A2A13ULL, 0xAAA734399C047543ULL, 0x9FDC19B198DCD071ULL, 
            0xE707C79063A4FC6CULL, 0xD76524743F5390ACULL, 0xFF2E2774910EAC73ULL, 0x844101F3F3CA3BCDULL, 
            0xEE8DCDC21294129CULL, 0xA4262FB196C1FECBULL, 0x37AC48AC0DEED538ULL, 0x38191F979EE412EFULL, 
            0x1FEDCB1EEB255C36ULL, 0x8E4A1748C98CDBCFULL, 0xD1FEF7BE804819C9ULL, 0x0EDCDA5D5CD2CE1BULL, 
            0x4B1C75B04D257BD9ULL, 0x552594D2A5B8B0FDULL, 0x6EDE8051790B2548ULL, 0x04B9DB4C357B8F32ULL, 
            0xDB7349915032606FULL, 0x3008996AA39A3278ULL, 0xBD55585F2709439CULL, 0xA5AD0BF3479E9D0FULL, 
            0x590277A30978709BULL, 0x15EB17AEB60A1788ULL, 0x1EEAF961658CE254ULL, 0xA4BDFE98D20847A0ULL, 
            0x1140F97724712873ULL, 0x8201DD1E0E90561AULL, 0xF6528E8FE82C669CULL, 0xF05E55DA56931857ULL
        },
        {
            0x0B463B13D6E490C6ULL, 0x9AAE6E5185FC87A3ULL, 0x107B8133B6A4E16FULL, 0xA94EEF3A9FCC1832ULL, 
            0x42D41D73C14B753DULL, 0x86FABE2D98170CAAULL, 0x37001C7BACE621C3ULL, 0x7CDD3CD96FDE8F1CULL, 
            0x91B050D267CE30A9ULL, 0x0BA7A90DC081655DULL, 0x0C0ED1C8E823B063ULL, 0xC14EC04CB4442FC2ULL, 
            0xE5AA317EBEABD1B2ULL, 0x765EE3DB3AA56441ULL, 0x40B41757365317A0ULL, 0x04EEBA658ED0D1EEULL, 
            0xE801A464D98C6F71ULL, 0x243C2C6B005CB962ULL, 0x03CE97D676A1E541ULL, 0xE7CE489C4985FF49ULL, 
            0x35C1CFB793CB164EULL, 0xCFD31ED34A9E192DULL, 0x964A891C859BA3CAULL, 0xBD2A4527F5777B87ULL, 
            0x72B1556A4C4BD4C1ULL, 0x7DCD408757F62B21ULL, 0x1A8BE5BFF740D12DULL, 0x13803DDB7609D1A6ULL, 
            0x797763E7509971DBULL, 0x1B5C2EBFB32BC165ULL, 0x30FB65B129EC69D2ULL, 0xAC524B0E82EF2102ULL
        },
        {
            0xB00289A9743FDEB6ULL, 0x43ECAEC5450DE5E1ULL, 0xBD1AB17F748FB530ULL, 0xE4445DBBED81FAD3ULL, 
            0x6EDF8F6B5826C10BULL, 0xC0AA6982A538759DULL, 0x48DF4B390A2FCAF6ULL, 0xA61D234C535C9B8BULL, 
            0x47DD18354F1A9FF2ULL, 0x322ED8C241ED5613ULL, 0x212CD9C63E2E5E2AULL, 0xC3B02A321C6D3917ULL, 
            0xBE1C692A9897D151ULL, 0x457324CAC3B32764ULL, 0xEDF5E3100C1EE175ULL, 0x3A90DF3B915CF3EFULL, 
            0xFF9005E133BAD571ULL, 0x3D43730CC2695813ULL, 0xEE646B233B82CC29ULL, 0xA2D2B6970C4017E1ULL, 
            0x924B7B886AD3AC8AULL, 0x126307DF8AA96D5FULL, 0xF61C27224A4B7A94ULL, 0x4C906959C6028D61ULL, 
            0x78E18EBDEB4A3982ULL, 0x2F4FBC70F4AD1619ULL, 0x2266552E68EE30C2ULL, 0xE4CA5D169D24DF28ULL, 
            0xB56C14C3C6066A78ULL, 0x710278E57DF613DAULL, 0x5494BF312A5A8F06ULL, 0xEF1681730D6DDDEDULL
        },
        {
            0x2C3BF42D27EE08EEULL, 0xF03C2C9E09CA239CULL, 0xC6D4281FE8600196ULL, 0xBFC0CE33E2912785ULL, 
            0x4BDBF081954A1831ULL, 0xF8547545DDD3B812ULL, 0xD5D62A263345D784ULL, 0xC6ACF0DABD5A4C92ULL, 
            0x15FBDAB682DC134AULL, 0xDE00A045BC32F008ULL, 0x5397817C48265C79ULL, 0x68F8EBEF21B16887ULL, 
            0xF91272BF3D6728A0ULL, 0xF241133CACAFF76DULL, 0x130ADA462BE58859ULL, 0x6B212B4D7BD3F9F1ULL, 
            0xFF45688A9B4E5B22ULL, 0x89011FDFEC5629F1ULL, 0xA312ACF5CC43233BULL, 0xB0365B1B019FA22BULL, 
            0x34A9F35B5257F214ULL, 0xE3EE1E8EADF2544BULL, 0x9D5B0A2718FA481EULL, 0x22480B071D2661E5ULL, 
            0xBF7B3752B84949DCULL, 0xD6CB25E8E6118C9EULL, 0xF66236B097C03671ULL, 0xC1E1F5ED35B0911CULL, 
            0x5946CE60C1441BE8ULL, 0xBAD17D5311A624A4ULL, 0x179E54621979C402ULL, 0x9A72E76E19E520CAULL
        },
        {
            0xE904087654C0DCDBULL, 0xDD0F7A5884DECA97ULL, 0xAB8D70F72E93E775ULL, 0xFA8AFE8DBDEC2A76ULL, 
            0x1E0548350FFE2FADULL, 0xD022FC26B5327E8FULL, 0x281EF2FFD9FD5F3DULL, 0x041F571F86509D82ULL, 
            0xB6BD8ADAEF756001ULL, 0x58B9818CDFA4E8FFULL, 0xA75A1982B4FD116BULL, 0x49F6731884E1CFABULL, 
            0x827A9CACAABED72AULL, 0x10F8D1584E5E56DAULL, 0xAA7CE5F780C5EAD0ULL, 0xC39CC2195FF1C64CULL, 
            0x5277595A31DA2DA3ULL, 0x8844BBF2591F4152ULL, 0x1322833F55BA6143ULL, 0x37113D40B3774EA3ULL, 
            0xC3C1BC647332955BULL, 0xE049926883A32BA5ULL, 0x044AB7A6D4844BF1ULL, 0x0963E204BE4DCEC0ULL, 
            0x45D33F7C507498CCULL, 0x3BBEF72106C89BF5ULL, 0xA4F6D8745F946BA4ULL, 0xA231EBA44512E1CEULL, 
            0xF789AB2D26AEFA78ULL, 0x578278305982C301ULL, 0x9991331489BED312ULL, 0x50B1C46B7E6F0291ULL
        },
        {
            0xAB806E3F77DFDA78ULL, 0xC57663C6119D7A52ULL, 0x36FF059D21A0CED0ULL, 0x74B214B902E83380ULL, 
            0xA8F13C9E0BCD92C8ULL, 0x7C7FE4C683CC2B5CULL, 0x1EAF0AD16893F0CAULL, 0xEA52730968AFE136ULL, 
            0xD24DA44046427747ULL, 0xA1C71A1B67E8008CULL, 0xAF309A61FD21C5AFULL, 0x0E73EEC98F9AB41DULL, 
            0x97E1E5180E73BB48ULL, 0xC9EFFF9BD6F47646ULL, 0x46232DE3B5308423ULL, 0x8F687089BD31E5E3ULL, 
            0x12D028A21AF6CDA2ULL, 0x9028220CC6315565ULL, 0xB99A0213ADC778EFULL, 0x535FD9DB5D823E4EULL, 
            0x51BCB94BA34FD61AULL, 0x568450A4E03A2994ULL, 0x5310130147A51DF7ULL, 0x9CAA83643B3F79B2ULL, 
            0x8F8CEC7A3F5AB0C7ULL, 0x1A7F6F2AEE20B820ULL, 0xB603A3B9F5C41982ULL, 0x3C67A92024FA0A5EULL, 
            0x8390C3ABF7B1B682ULL, 0x9337CA2A33827368ULL, 0xB37646E2F0DD3799ULL, 0x2EECE96518914776ULL
        }
    },
    {
        {
            0x2EF363C8F4E0F41AULL, 0x6DBA85DA12D0072EULL, 0x6B98E6DF6317CC55ULL, 0x54A4615E53A12F38ULL, 
            0x67C45EBC93E2073FULL, 0xCFF3D2AC9AF3AE4EULL, 0xFCAB13918B1DE7AAULL, 0xB009A4F8318F2FD9ULL, 
            0x5AC557168194F6D3ULL, 0x5780CEE5067BACF4ULL, 0x32691AEEB021ED5FULL, 0x8F24DB4970342EC2ULL, 
            0x05764969B16C4BFDULL, 0x5C78CBDDBAE81E40ULL, 0x7DC0AC7EF5506F93ULL, 0xEF10AAF8D3DF27CBULL, 
            0xCE71863E1D3D4A23ULL, 0xCD756D8196E0A231ULL, 0x6317105BBA3FE784ULL, 0x796076FF43AABD26ULL, 
            0x65E1F03B9F1C5D40ULL, 0x1CD2ABF0F552E517ULL, 0x84F6731DE8D86D16ULL, 0xCD7555C7E6568B83ULL, 
            0xF3920B6B3AF95483ULL, 0xD25B3FA721EB67CCULL, 0x5C554F63BE0CB9C5ULL, 0x834F488E0E831968ULL, 
            0x3F63DE56B81BAE14ULL, 0x52B78952E0F7FE46ULL, 0xE892D1A279894240ULL, 0x70C2662B16E53870ULL
        },
        {
            0x2BDC458E594CD510ULL, 0x08853F536B049EF7ULL, 0x847AD0EC6AB0517FULL, 0x936B7F3AC1DABBDEULL, 
            0xA467FC2B215C0A89ULL, 0xCE087C647E0A55D4ULL, 0xC28574B4669E31B1ULL, 0x657BE291DA830915ULL, 
            0xCA479899575B0DA0ULL, 0xA1FD064E951E45F8ULL, 0x14CB092DBA67906FULL, 0x87725A646861BD94ULL, 
            0x942B39AB65B2AD8FULL, 0x19B003E79B687C95ULL, 0xDEAB32E3C0E98AA6ULL, 0xE2836ABC4E221FD3ULL, 
            0xA71ADA46242B2A4BULL, 0xBF97CCBDC79158C8ULL, 0x643CD9A54D68766DULL, 0x66917C8DF3E5D49DULL, 
            0x71E91E9AF36EDA82ULL, 0xC578A932A41FB0AEULL, 0x12F8755DBCED2FAFULL, 0x2722CD2D35BB6835ULL, 
            0x4163B6A2E72126ABULL, 0x973EEE84C9CBEEABULL, 0x50641495F94C5309ULL, 0xD7FAD7D789E496A2ULL, 
            0x2E4B083D51253F37ULL, 0x3C3BFC9B34B45555ULL, 0xEE83B174CE62E0A0ULL, 0xB2AD73D96807FA97ULL
        },
        {
            0x384436829B1F9E0AULL, 0xE09E3FD63A97C0B1ULL, 0xDFB59C925AD54567ULL, 0xA7D1039C5F12C42FULL, 
            0xA4414E2A87732D5AULL, 0xFFC51F91F66E5D47ULL, 0x46B1C83003908DFEULL, 0xDE95FC6581A0400DULL, 
            0x143683EA994F1F7FULL, 0x935761B90E54829DULL, 0x48C314B7E6138CE7ULL, 0x508F6DDD28056008ULL, 
            0x680F147B5316C2EFULL, 0x4BFA14271EF45F1BULL, 0x6AB73F8A8B34A220ULL, 0xE3052B33176452CAULL, 
            0x1CC6AB812A904E77ULL, 0x74A4547F4C021767ULL, 0xE48823AEA7542E49ULL, 0x18BABDA411DEF1E8ULL, 
            0xB1EF70068D784053ULL, 0xE5ABBA169B81C5BBULL, 0x1C8098DDDE67449DULL, 0x682A46B879D13335ULL, 
            0x37991D293CC701B4ULL, 0x61407F3D380DA1B6ULL, 0x4085E8A103F9FC9CULL, 0x67A881A2E298F98EULL, 
            0xF5FAE47FC2100C4CULL, 0xBC20E4DAD7133462ULL, 0xE2EC339EB016F41CULL, 0xF26BD77F8B51BBACULL
        },
        {
            0xAA17AF8BEC423689ULL, 0x13891835AEBB300DULL, 0xC5CD047EDE97B740ULL, 0xB2061650BEF98518ULL, 
            0x6CB704E39FBEBCC2ULL, 0x4A6E24B30B980CA8ULL, 0x6BB2D0F391F6F97BULL, 0x7E9D2F23EFB8898AULL, 
            0x6989A8FC3DC7D0ADULL, 0x0ECDB4322B7E87CAULL, 0x651382AA949A17B4ULL, 0x31C43925931CCC66ULL, 
            0x51803F77A367DD28ULL, 0x294125CBDE3FEAECULL, 0xEE8E9F13C03C3B60ULL, 0x0408B8C7F5475217ULL, 
            0x98CBC732AF559AF4ULL, 0x923654BC02CB959AULL, 0x874BC5C3FB810DF6ULL, 0xFFE8A96726705EF1ULL, 
            0x60E974F4946ED180ULL, 0xB7E73407852E377BULL, 0xEE7643A87319BED3ULL, 0x041B6A79AF332579ULL, 
            0x3330B8B3BBB2A866ULL, 0x3716D9F56B510C2EULL, 0xA7A32E1AA016C39CULL, 0x290F8F6F6838576CULL, 
            0xF9A60AB89BD346DBULL, 0x1B0E09879A477AA8ULL, 0x3B33C8594C9A1B73ULL, 0x096CD5C76BD06E71ULL
        },
        {
            0xEF840F7490D1AAB9ULL, 0x5C746420A075DEB3ULL, 0x91B475566759F398ULL, 0xB63B605754D1EAC4ULL, 
            0x8F309A50CC7D930FULL, 0xF8746FE8B9D26BDFULL, 0xED779E0F9C222EC1ULL, 0xBB4CBE1A45667BA8ULL, 
            0x572AD57F0E3C65B7ULL, 0xE31DD47D5B6A5659ULL, 0xED50E0D735D30093ULL, 0x205A77C0282952ECULL, 
            0xF01E4398978AC773ULL, 0x27C696AC17539105ULL, 0xA08F0EFDCC0791C7ULL, 0x09C2EA5B34A53C3BULL, 
            0x581DA5B06A85E72BULL, 0x0CADFA88540B6FA0ULL, 0x0AE46D31A75A990FULL, 0xE6BE5C055FE6913DULL, 
            0x75139883E4E3844EULL, 0x5076BBC21136C636ULL, 0x6BABFB3997101513ULL, 0x574487924A9F58D4ULL, 
            0xDAA69F649BB8E230ULL, 0x1954B3A87C41139AULL, 0xCEFD8AE4670ED82AULL, 0xB267D82D1C650329ULL, 
            0x26217997D8A265FDULL, 0x9089890BA625AD4AULL, 0x8CD1BF373D5B4133ULL, 0xACA92195FA67ED65ULL
        },
        {
            0x94351FC2C6879C05ULL, 0xC2E5FF4D03CF58F4ULL, 0x4F80EBAD0FC01AA5ULL, 0x5E9E48844D3D08E8ULL, 
            0x7A5CDEE34EA99DC4ULL, 0xA7E914963A04E8DAULL, 0x1B7CB0FB7470B6B9ULL, 0x07D0CA227E457455ULL, 
            0x119E747325F93059ULL, 0x4F895BD497390387ULL, 0xAF9E528BA78B6620ULL, 0x27507E204315904AULL, 
            0xE2FF8C9E4412BFB1ULL, 0x7CDA30D7AF517321ULL, 0xF80EC8B1E8709849ULL, 0x89DAD750CDB72716ULL, 
            0xF0539462130FB501ULL, 0x1A88876C8894DD26ULL, 0xB06CBD132FF5C257ULL, 0x53B2E1C01BD8023CULL, 
            0x9E05DD1DF710C657ULL, 0x92D046351E5FE971ULL, 0xC41665FA448B5467ULL, 0x0DCE65D1E882A8A1ULL, 
            0xE594DD2CE3CE66EAULL, 0x9D77B090FB6AF655ULL, 0x337A021B982E3915ULL, 0xFD802BAF944379A4ULL, 
            0x9C72786F419A9743ULL, 0xC162B8922F183471ULL, 0xA63BA34ABC1673C4ULL, 0xF4E1336DBE7F270BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseHConstants = {
    0xC8414A9776D90636ULL,
    0x3C159295D931BB5DULL,
    0xC10A06514ECCA8F8ULL,
    0xC8414A9776D90636ULL,
    0x3C159295D931BB5DULL,
    0xC10A06514ECCA8F8ULL,
    0x5532DFBEFFB88D59ULL,
    0x4698E25501ED33A3ULL,
    0xB3,
    0x14,
    0xC9,
    0xAF,
    0x74,
    0x72,
    0x87,
    0x77
};

