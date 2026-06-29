#include "TwistExpander_Boxing.hpp"
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

TwistExpander_Boxing::TwistExpander_Boxing()
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

void TwistExpander_Boxing::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC1849D160A036B29ULL; std::uint64_t aIngress = 0xABBAE8FAA7331414ULL; std::uint64_t aCarry = 0x802CBDD655C582D5ULL;

    std::uint64_t aWandererA = 0xBD2F46792D319FA3ULL; std::uint64_t aWandererB = 0x907F969D0F2A94E5ULL; std::uint64_t aWandererC = 0x9F2CA916897E9F07ULL; std::uint64_t aWandererD = 0x90B9308175BC1A4AULL;
    std::uint64_t aWandererE = 0xE4188923809B5152ULL; std::uint64_t aWandererF = 0xC9058E9E4253A35CULL; std::uint64_t aWandererG = 0xA8E97ABD624BEAC6ULL; std::uint64_t aWandererH = 0xDFCDD453C887A292ULL;
    std::uint64_t aWandererI = 0xCDDFE8759C9B41C6ULL; std::uint64_t aWandererJ = 0x8176B3EA752E451FULL; std::uint64_t aWandererK = 0x9460E62B6E36C561ULL;

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
        aPrevious = 17835523280406057686U;
        aCarry = 11019850528887544894U;
        aWandererA = 14238628834205391040U;
        aWandererB = 14868924783480726212U;
        aWandererC = 16474446401717569391U;
        aWandererD = 15736394047907271842U;
        aWandererE = 14720457793790777836U;
        aWandererF = 11898374609097563757U;
        aWandererG = 13882080758397291325U;
        aWandererH = 11407601540179310808U;
        aWandererI = 13466382694466982838U;
        aWandererJ = 17492787708163609013U;
        aWandererK = 16927128164762527768U;
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
    TwistExpander_Boxing_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Boxing::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xE08C3126F2AC8E19ULL; std::uint64_t aIngress = 0x810387710E9C90F0ULL; std::uint64_t aCarry = 0xE756039146FCEB32ULL;

    std::uint64_t aWandererA = 0x910DCC4507304305ULL; std::uint64_t aWandererB = 0x9D38A634CF0EE990ULL; std::uint64_t aWandererC = 0xD3A3B9B54D0FF0E7ULL; std::uint64_t aWandererD = 0xED013A04CCD42E63ULL;
    std::uint64_t aWandererE = 0xEE54F4695661F471ULL; std::uint64_t aWandererF = 0xF01323A7747C6D88ULL; std::uint64_t aWandererG = 0x875FAD84303F5DA3ULL; std::uint64_t aWandererH = 0xAE8DC26474974785ULL;
    std::uint64_t aWandererI = 0x9FD2123C1CBED8E2ULL; std::uint64_t aWandererJ = 0x8B73F02BF666C4B0ULL; std::uint64_t aWandererK = 0xE4AEC358B8D7CF95ULL;

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
        aPrevious = 13449119753110298772U;
        aCarry = 10759458676693165874U;
        aWandererA = 15026268542977828159U;
        aWandererB = 9931086272958799722U;
        aWandererC = 15753528783262933115U;
        aWandererD = 17724412818858648660U;
        aWandererE = 12465748238871047162U;
        aWandererF = 11908183164967900569U;
        aWandererG = 12153548148480446842U;
        aWandererH = 11717720367432901595U;
        aWandererI = 9865056680970562113U;
        aWandererJ = 18360516705198147208U;
        aWandererK = 17914261651861385403U;
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
    TwistExpander_Boxing_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Boxing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBDA2FBCEB4B816BDULL;
    std::uint64_t aIngress = 0xACFD4249CD05E47EULL;
    std::uint64_t aCarry = 0xFDABEE0DA03EFE96ULL;

    std::uint64_t aWandererA = 0xBF6E640F636066CCULL;
    std::uint64_t aWandererB = 0xD295F39893097213ULL;
    std::uint64_t aWandererC = 0x8B1E50F33AA41FDEULL;
    std::uint64_t aWandererD = 0xB0FDADCB0CA3ABBCULL;
    std::uint64_t aWandererE = 0xB12DE3E6714D1479ULL;
    std::uint64_t aWandererF = 0x9AFB3F645F9EABABULL;
    std::uint64_t aWandererG = 0xBC58C029466A1D3DULL;
    std::uint64_t aWandererH = 0xBA3DD3927237BC59ULL;
    std::uint64_t aWandererI = 0xE51CB9F8F2DC3352ULL;
    std::uint64_t aWandererJ = 0xDB9E2AA191A3855BULL;
    std::uint64_t aWandererK = 0xE42CA89F5250710AULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneH);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneE);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_Boxing_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Boxing_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Boxing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Boxing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x95F47D423F04B699ULL; std::uint64_t aIngress = 0xB6F72DD2704EDC02ULL; std::uint64_t aCarry = 0x89154EA1E2C74AF6ULL;

    std::uint64_t aWandererA = 0xF31DF21392044B19ULL; std::uint64_t aWandererB = 0x968D19D7B63BE688ULL; std::uint64_t aWandererC = 0xE7185141A99C4122ULL; std::uint64_t aWandererD = 0x9992B37C2913EC46ULL;
    std::uint64_t aWandererE = 0x9FF8EF37EDA2C8AEULL; std::uint64_t aWandererF = 0xA08A7AABD5C834D6ULL; std::uint64_t aWandererG = 0xD9BB84C7FF686DEAULL; std::uint64_t aWandererH = 0xB6E0891338C6D18DULL;
    std::uint64_t aWandererI = 0xF64AFED083C4CCDEULL; std::uint64_t aWandererJ = 0xA0B6F8BD735676DAULL; std::uint64_t aWandererK = 0xCA0EA80E9D2A7EA0ULL;

    // [seed]
    {
        aPrevious = 13279725721189446668U;
        aCarry = 14531049425223868295U;
        aWandererA = 12227767327496568480U;
        aWandererB = 17695921259593461668U;
        aWandererC = 14345102931586770497U;
        aWandererD = 12652618046201451991U;
        aWandererE = 9271533817025002490U;
        aWandererF = 11896857316139825115U;
        aWandererG = 12439742100323661467U;
        aWandererH = 12415157798030746021U;
        aWandererI = 11955454201686303335U;
        aWandererJ = 10742418046599345902U;
        aWandererK = 11898409401968156601U;
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
    TwistExpander_Boxing_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Boxing_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Boxing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Boxing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 0, 3 with offsets 3982U, 4366U, 2243U, 7140U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3982U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4366U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2243U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7140U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 0 with offsets 7810U, 1288U, 1978U, 5867U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7810U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1288U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1978U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5867U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 1 with offsets 2503U, 5222U, 7566U, 3229U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2503U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5222U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7566U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3229U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 2 with offsets 2382U, 7944U, 6631U, 7921U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2382U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7944U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6631U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7921U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 with offsets 1446U, 3U, 64U, 679U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1446U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 64U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 679U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 1, 2 with offsets 1932U, 966U, 1687U, 1261U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1932U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 966U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1687U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1261U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 1593U, 1452U, 1705U, 1460U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1593U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1452U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1705U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1460U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 1638U, 658U, 967U, 598U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1638U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 658U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 967U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 598U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1806U, 1869U, 592U, 2038U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1806U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1869U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 592U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2038U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Boxing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 3 with offsets 4764U, 7472U, 4662U, 2029U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4764U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7472U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4662U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 0 with offsets 6499U, 1464U, 2798U, 2328U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6499U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1464U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2798U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2328U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 0, 2 with offsets 6088U, 7282U, 2866U, 3920U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6088U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7282U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2866U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3920U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 1 with offsets 5664U, 6369U, 4501U, 4746U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5664U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6369U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4501U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4746U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 664U, 178U, 5373U, 1599U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 664U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 178U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5373U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1599U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1618U, 1985U, 534U, 1878U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1618U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1985U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 534U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1878U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1841U, 1220U, 289U, 594U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1841U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1220U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 289U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 594U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 478U, 1746U, 404U, 422U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 478U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1746U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 404U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 422U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1978U, 585U, 1880U, 1708U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1978U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 585U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1880U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1708U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 1704U, 264U, 1612U, 1622U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1704U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1612U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1622U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseASalts = {
    {
        {
            0xA30A32A4B2BC1AF1ULL, 0x9AFEBE4F370D6593ULL, 0xD426FF68CFE291C9ULL, 0x3D619259CBD5BFD8ULL, 
            0x18B3E648E4B205F9ULL, 0xA2466E22529D334EULL, 0xC1CD7F2DE63BC4CCULL, 0x1AE283C5196D2F25ULL, 
            0x06C658A15CC9589DULL, 0x3449097135A8A41CULL, 0x2279E387B2C01F1CULL, 0xA3916EF7F8B363D1ULL, 
            0xA49CAA3453DD1E94ULL, 0xEADCDF20B34AFDE3ULL, 0x995D9954878E8E67ULL, 0xF3B57CCDCBABEA3BULL, 
            0x56E35550B2329632ULL, 0xB97538EA7335BEC0ULL, 0x11DBB025D312DEA3ULL, 0xE228B2E19EE88AD4ULL, 
            0x1B8134A7936D4EF5ULL, 0x7EC0258B0CC4ADC4ULL, 0x96C4636A1E009FE5ULL, 0x6B888FBB3C304AFDULL, 
            0x55102EB839CAB78EULL, 0x75C7935183490D55ULL, 0xBC2293E8C6145A21ULL, 0x01B7E4584AA1ED1EULL, 
            0x5AF1208BBF2A3FF7ULL, 0xDC09BB61FE973191ULL, 0xDF71F90FC806995BULL, 0x1DCCFF8B48FF56A1ULL
        },
        {
            0xC998A67001372EE8ULL, 0x48E666FB003539B3ULL, 0x4977E433138BCD63ULL, 0xE9532CF6076D190EULL, 
            0x3425C790ACF8FCA3ULL, 0x53AFF74896BAC302ULL, 0x488AC36275FCFEB2ULL, 0x7F8773790DD2FB8CULL, 
            0x2B3F59D6DCA577E8ULL, 0x9BC3C1DB9F1B97A2ULL, 0xC6830CC748306E9BULL, 0x13F1246DDC545487ULL, 
            0x845D134D23A2AEDDULL, 0x74E488D9460C3211ULL, 0xE63B70752E7F4878ULL, 0xC7D3F74B3B231AD9ULL, 
            0xB7BC64BC12183259ULL, 0xA433E0655C1D0886ULL, 0x6A8EC99A863ACD20ULL, 0x26AAE0B7632EAE35ULL, 
            0x7714DBA00C130F8EULL, 0x0B9BE1D37588D73BULL, 0x38DA320DE193BB37ULL, 0xB8AFA60C37B2232BULL, 
            0x9765A51F799C539DULL, 0xA2C75B3705EDCDCCULL, 0x53607AD70B1A39D1ULL, 0x7090F8F8182901A2ULL, 
            0xA9A4833F5A92ABE2ULL, 0x89A6223A61085D7BULL, 0x8F4E43529B3151D4ULL, 0x67D1F9F6CAC6DC8DULL
        },
        {
            0x0E4B1C78D6B0882CULL, 0xDA2698F09ACF3A9EULL, 0x86E2561B2D80CA6BULL, 0xFFE7D90EEB679A20ULL, 
            0x1932C79DB70C32FDULL, 0x3DBCD60AFC01EC97ULL, 0x61610B2378BD1DCBULL, 0x98179E8EACD09C87ULL, 
            0xA812311BD35F40D4ULL, 0x1E42AE3CFAFC56C9ULL, 0x0ECD49A05D6A3DFCULL, 0x56022FE6D6538674ULL, 
            0xC286134C045711BEULL, 0x0DD912B23165CB42ULL, 0x3DF8469FC1B5FADEULL, 0x51C5C07D015F54F9ULL, 
            0x0A80D61A764810F6ULL, 0xDEB87949152C532EULL, 0x2E0702281C74F2D9ULL, 0x1E14BBECDF7A66DDULL, 
            0xD57DDDFC84684751ULL, 0x59CE1A533642C869ULL, 0x24B2F05E8C32E677ULL, 0x1A4A52C341DE52E3ULL, 
            0x1F446B91A9ED36EFULL, 0x43B1546E6D81E48EULL, 0xB4F631837E964EA1ULL, 0x4C14F9187AF4EF18ULL, 
            0x606E7AA0A7619F82ULL, 0x6D23791D20B07DB2ULL, 0x49422E0780F089B3ULL, 0x7482AFA94482EB4BULL
        },
        {
            0x3CF57B1687100EFBULL, 0x4767D6E670AA15E2ULL, 0x0999DC75541971AEULL, 0x6408418A40F80133ULL, 
            0x15384AE78A3BED0AULL, 0xB76FC3E646D2EF73ULL, 0x212D0C38DC30DD9EULL, 0x56F189139002B998ULL, 
            0x6464FF8B905F385BULL, 0x77F4C1138E509E14ULL, 0xC38296AEFAEC9AB4ULL, 0x710C93E0CFD6C88AULL, 
            0xD77574D6346B0461ULL, 0x8C3D7C1A1CDC2141ULL, 0xDBA241283ABC7727ULL, 0x0D39EA581FD12009ULL, 
            0x7B4D0C07D1F735CBULL, 0x3ACD1C3954074724ULL, 0x25F64BDC78ECFB4CULL, 0xB8C3CC61B53AF811ULL, 
            0x1B7F0602CB2FDEBBULL, 0x89DD9563B5A71BA8ULL, 0x24B95E58DD5E0061ULL, 0x7462828D0185F9C5ULL, 
            0x65216BB05B94733CULL, 0xEA914242F3296F0EULL, 0x05BA1C6DC42F7546ULL, 0x05F8D7E709D12CB9ULL, 
            0x988A5051D881E391ULL, 0x4F3DBE79A41CFD64ULL, 0xEEE447D7D6DA8736ULL, 0xFF4C039F1B8E1729ULL
        },
        {
            0xD54E7A51B98D7C00ULL, 0x29BC5D90C5E86ABFULL, 0x828A394C559C4113ULL, 0x6A4CEC4F67630B93ULL, 
            0x047BF32CF1BF8453ULL, 0x8C46C8F77E2FF482ULL, 0x5D51E1BD3B0575D4ULL, 0x2934F691EDD72B64ULL, 
            0x2DE89AC65DB3213FULL, 0x6B0C9763544A8ED4ULL, 0x57C7A819D445B047ULL, 0xDD65599CFE114AB0ULL, 
            0x9DCF1C50382C8A79ULL, 0x6A6F05153581113EULL, 0x1EFE9E3263665C74ULL, 0x16A467097C047835ULL, 
            0xBA0AB7B5F6112D97ULL, 0x94D612A7A20DA6EDULL, 0x540DB48FEFCB78FBULL, 0xC5C07692772C6C0CULL, 
            0x83E5B57BCA770497ULL, 0x65B07342E0669AC7ULL, 0x6849B5AD491829EFULL, 0xFF8ED946B888F1B5ULL, 
            0xE0D9B4201FFC880AULL, 0x1AA8DE6B56469389ULL, 0x6ACE314679AD9CD9ULL, 0x47AD32E738F34652ULL, 
            0xA89D356B5FD30BA4ULL, 0xB0813AEBC5ADC2D4ULL, 0x564C879D9255AF24ULL, 0xB0FD679EC6101CF9ULL
        },
        {
            0xE95BCB71FAED5DA9ULL, 0xE5CB535AD1ACA073ULL, 0xD1AB091EBF528960ULL, 0x291769F631C48B0CULL, 
            0xC257EA90716D1E73ULL, 0x2C874B699448619CULL, 0x510ADA2526C1E1CEULL, 0xBC02B1FCCD785D90ULL, 
            0x8D7AC5C70F7438E8ULL, 0x3DCA2B0C87D379A9ULL, 0xAFEC4D969C230C24ULL, 0x9FF231DF7A6325F4ULL, 
            0x18E36254D0D43BF5ULL, 0x42C8C2C71384CE1EULL, 0xB9847A4033E8AC42ULL, 0x501CE3FF4BA5F927ULL, 
            0xF985A47A04B10FEEULL, 0xE0DF587D280489C6ULL, 0x5A3CB1E1F5EBDE60ULL, 0xFC100155C6E741BCULL, 
            0x02C7740C94E6D385ULL, 0x06AC701721A37F09ULL, 0x24467B1F86564862ULL, 0xEC925A735D8E0423ULL, 
            0x2B173AB41C29183AULL, 0x969EC3BFC0DC4542ULL, 0xF5E09CA3FBF7EA62ULL, 0x0B4110148090510CULL, 
            0xBCE3A76FCCB79413ULL, 0xC3B0CB589F935674ULL, 0x2033C7F9682BB8CDULL, 0x0D639C1CA31805B2ULL
        }
    },
    {
        {
            0xB1CBF608C3B767C9ULL, 0x4C704351216B1847ULL, 0x6F7EBB06485139A5ULL, 0x8622EA91E2A1790DULL, 
            0xE102537B0270CAB6ULL, 0xA3650ED7EB776D69ULL, 0x13C149E351406B87ULL, 0xBF5E86AEA8C477A3ULL, 
            0xC9EEDC3FA7CC9389ULL, 0x8245C875443B3AC4ULL, 0xEAE35952BC86B271ULL, 0x371ACDEA31EB6083ULL, 
            0x8EAF196970E88A77ULL, 0xE0B439A214F6CCA8ULL, 0x38BD7A16D2CD7C08ULL, 0x1BC50545DBF7CF67ULL, 
            0x0D5EE146BA6470BCULL, 0xB77F2B9C72915D97ULL, 0xFB72C3896AE81D9AULL, 0xA31360E1C3A95A73ULL, 
            0xE1443112B4FDDE94ULL, 0x97D861A7F73E1DD4ULL, 0x5DA0043365687013ULL, 0x9D4E0CEC9B3CF461ULL, 
            0x361966F2563F9287ULL, 0x4402C473E6829F9EULL, 0x08E36C67C0CC3B83ULL, 0xB9B57FB171994740ULL, 
            0x1084369B282A2254ULL, 0xD498862125812235ULL, 0x9BC371F14B0D48D1ULL, 0x5EB972F2D9FBCD2EULL
        },
        {
            0xD3E7B2D75DF656AAULL, 0xDC92F2FD4EB7167FULL, 0xD850C19415699E6AULL, 0xB87B0E92BAAECCB4ULL, 
            0x7875F72B73EB863DULL, 0x51144E0794827688ULL, 0xECDDBFCB26819004ULL, 0x82857C6BFCF49EF4ULL, 
            0xA5C097A4775A71E5ULL, 0xBDDF1F152D417915ULL, 0x6908DDF57F59784AULL, 0xC55354C8D3271139ULL, 
            0x2290EB21565CB88EULL, 0xABDD343E90AC05EBULL, 0x015AB3E498383BAEULL, 0x5AD0A3BEBBA12D0FULL, 
            0xBDE42C6DBDA8A959ULL, 0xE6EC5418E8CBCF6FULL, 0xD552CD04A0692465ULL, 0xC973D7D97A36094DULL, 
            0x4DA8559BBB3D1EB2ULL, 0x65CC70F6A5538D21ULL, 0x4958FB86EF3CC18FULL, 0xAED9A88578289A7FULL, 
            0x9CC18CB08DD50E50ULL, 0xC73925FC0B5106F6ULL, 0xD2F277E16F494D0DULL, 0xBD1E912E5A1ADDCCULL, 
            0xD0C0EDB2C0377295ULL, 0x0DE24CAC8CFA1804ULL, 0x8BE7B1B9CF527B78ULL, 0x0784D501B52C3F06ULL
        },
        {
            0xA74B7D8D14771FADULL, 0xCBAF71ABB9DB80C2ULL, 0x7485858386C10B5DULL, 0x90F583C11761592EULL, 
            0x8079C32DEFB98E94ULL, 0xFAB954CF2A768163ULL, 0x0D57C29F10A72E03ULL, 0xE174B4800BE99BB0ULL, 
            0xF9CEF764CC4A3FA1ULL, 0x5B8CBD106E0C170AULL, 0xC450DAE0C29B01F0ULL, 0x26CAD25F133FC985ULL, 
            0xF16EE26630FC5A19ULL, 0x891217A81AA5725AULL, 0x4C8E2F2F3A884257ULL, 0xCB43A6C4563991CCULL, 
            0xE3E78859D4DBAEBBULL, 0x88A65042AB1D0A57ULL, 0x2A9157DCA74076D5ULL, 0x111F8E2A0873E1EFULL, 
            0xC0EA50CFDABBB44FULL, 0x85E99187A2AFB010ULL, 0xFE473F8CC766B89AULL, 0x2AE79AB1F80E099DULL, 
            0x992EB7289FD09455ULL, 0x8ED1C50FC77B0C1AULL, 0xB416BE7B31FE7BC5ULL, 0x053CAF9ADBB5FE87ULL, 
            0xF8D1B82DA72EBA89ULL, 0xBB9C5F6790F1197AULL, 0xE3599790A4AE7B55ULL, 0x77959086ADFF40E3ULL
        },
        {
            0xF64E3BF8CC0B91A9ULL, 0xAE9E57061FA3E261ULL, 0x9314EEAF5433D3EEULL, 0x383B48672AE800CAULL, 
            0xD37BBAC91498A615ULL, 0x6017EC3A023E712AULL, 0x852C9C0F6890A4A1ULL, 0x538F2D0617BA623FULL, 
            0x0C7EE1F01091330AULL, 0xB7E76ECAF0E31F5DULL, 0x974951D17EC9957DULL, 0x80798EABE9F89267ULL, 
            0x82C6982C462AEA94ULL, 0x909462916B78503EULL, 0x7F39D9CA870795BEULL, 0x515D1EF30DAA8361ULL, 
            0x2FBFB83428C75036ULL, 0xF7341848D07FB64DULL, 0x0A9F44E90D391112ULL, 0xA717D859D7E62CFAULL, 
            0x74FE0583871653E8ULL, 0xB88FBADD695005ECULL, 0x104E74CFE3A919E5ULL, 0x4A4584432AD82C01ULL, 
            0x8942A34446D575F1ULL, 0x23D54A081DD43004ULL, 0x72BD1B4BF822D992ULL, 0x78A3CEBB302ED9CFULL, 
            0x417FF4AA839996DBULL, 0xF2555F32B95CD3D2ULL, 0x9064F1DF2086A6CFULL, 0x9BEE4D4B752B8649ULL
        },
        {
            0xC78F2B362EDD8A7DULL, 0x43C5A4107CC95191ULL, 0xB6B366CC6C3F94BAULL, 0x41A0443C487E64EBULL, 
            0x0B992638922C53E5ULL, 0xE9017BA5ACF5DBBBULL, 0x664F7BD93D09D2E3ULL, 0x59302B1136D426ECULL, 
            0x3FD94DF45887706BULL, 0xEECCCDA5627D888FULL, 0x1AD87980D809D04FULL, 0x2BBD8455C3D3A3AAULL, 
            0xB55CF64902EC1EFCULL, 0x77227EB540E8D0DFULL, 0xD2126C12A4B1A3A7ULL, 0xB1179C9B13404FB1ULL, 
            0x6BC3DD675FC09EECULL, 0x670020D3D4049D64ULL, 0x52ECFEBDD20A9012ULL, 0x32EA8200565473DAULL, 
            0xE315A7B45C4BB9EDULL, 0x55AE97551EF39128ULL, 0x46B1DD50101571AEULL, 0x5C31CD78F4E94DDEULL, 
            0x496A0932EDB0FCF8ULL, 0x57C39103D9FE2C37ULL, 0xFCFAD6BBE47EB708ULL, 0xA2F97145EE113ECAULL, 
            0xD4CA464E00120BC7ULL, 0x57F8EE22432F86AFULL, 0xF65C42643669E361ULL, 0xC55042E4ACC7C121ULL
        },
        {
            0x8E5318E1C53B2995ULL, 0x2FAD2D061C0E27D9ULL, 0x96DD4CD8FD1A0A02ULL, 0x1BC1BC95E74213AEULL, 
            0xA9B0A4551007CA99ULL, 0xF46D06B8989BB504ULL, 0x59DE9F98AC1BD83AULL, 0x45E2F7B798B4F305ULL, 
            0xE86EE71C51505EAAULL, 0x615002CE523677B7ULL, 0x51D1F2D0B3254D4DULL, 0x59C3E7B8FB0D31D1ULL, 
            0xDB20FA60749F3FBCULL, 0x23F0E9FF4882ED73ULL, 0xB360ED11F71AD17AULL, 0x19C2B134275E7AE4ULL, 
            0xEFB239ADBA9181E7ULL, 0x5190B977DB7E223EULL, 0x6CFA2AE679A98EE5ULL, 0x2E0625E82D3FC25BULL, 
            0xA5027DAB8B550ECEULL, 0x3D26E7C7208F7DE5ULL, 0x6AC8DE25696610FFULL, 0x3881B06CF3CDB6B1ULL, 
            0xA9EC506F513CB6BAULL, 0x7C2433578E4288D7ULL, 0x806F90C2DAAF26DFULL, 0xF5F3ED349B17504DULL, 
            0x566671A81A2BB3DEULL, 0xBDE7EE4012A73A64ULL, 0x55DF8917CEE05DBFULL, 0x37ED12992450030EULL
        }
    },
    {
        {
            0xA2EE9EE5F9E74F5DULL, 0xE2875882D038FB41ULL, 0x088E47172F20739EULL, 0xA8104D248E0DD639ULL, 
            0x64CE7172CEC6C92AULL, 0xB8C75E4FA2FED802ULL, 0x2E7F11928B8450DAULL, 0x13A63993F3A92EC2ULL, 
            0x8812FFDE482C4C0AULL, 0xEDD88270CB23C801ULL, 0x2F21AC5683BB2DE2ULL, 0xFB96F9007E20E7CCULL, 
            0x8BBEBBDE9FB7C81DULL, 0xC00BB1ECFF7BEBB9ULL, 0xF1E4E2326C70E2BAULL, 0xC10BFE79C1FE66C2ULL, 
            0x8AE1128B3B535986ULL, 0x85977ECA849677A6ULL, 0xAA6DB7FEB1D4D1BCULL, 0xC7A7311F71181252ULL, 
            0x43B8F3FAC2B652C7ULL, 0x88DC2EE9E371922EULL, 0xECFDEA56D24A80DBULL, 0x6E3CBC2DC993D889ULL, 
            0xE121EEA1DF54F814ULL, 0xAE2EA687EAE6A1F7ULL, 0xA78264AAD4BADC94ULL, 0x211FC28464D1126AULL, 
            0xF19D7671CAFF9A03ULL, 0x0927FEEE5B40E34EULL, 0xFDBC46C640B559D6ULL, 0xB4671B58C2A3634DULL
        },
        {
            0x0C1F15AA20824E56ULL, 0xF40C6A9617B50630ULL, 0x5F60B4D14EBDF8A8ULL, 0xF2D0166B2FD5187DULL, 
            0x2E199BD8C29DFFD7ULL, 0xC8926EA48E751711ULL, 0x6552777092839501ULL, 0x8CBC5FCDA781AA75ULL, 
            0x81B2D223DA847FD8ULL, 0x76BFFDBEA0430865ULL, 0xB8570C16CE10B824ULL, 0x177E08A50B6E0ED2ULL, 
            0x926D0E37EA76F4A6ULL, 0x7D52CC8FD815D016ULL, 0xF7CF5DC4A2591FD2ULL, 0x692C97D56C6EF4FCULL, 
            0x7081EC3FF49C69F3ULL, 0xB7676E03C6FA3865ULL, 0xC40A893024ACD073ULL, 0xA33140C23FE72A4CULL, 
            0x0E326C749A589538ULL, 0x64D1BDE5942AB9BFULL, 0x385AEE8DAD2C133CULL, 0xA1B4D89AAF7378CFULL, 
            0x8E33CE86F29E3116ULL, 0xDDE76DA941D23064ULL, 0x462F786C6E966B61ULL, 0xEB59810BC409B5EFULL, 
            0x25654B32E2315629ULL, 0xEDCBB52B7A196843ULL, 0x7F36766A0507C91CULL, 0x21BDCDB17481D458ULL
        },
        {
            0x474315E18706025FULL, 0x161692AB6CFC3D5EULL, 0x5FD37A60E71980F4ULL, 0xAD35607137C32B57ULL, 
            0xCD98A5206D58ABFFULL, 0x832BA63EEF913FF2ULL, 0x8DF631B6B4BBB523ULL, 0x2C0D124512043CDEULL, 
            0x9487D51818F08257ULL, 0x9D8F15C275ADC74DULL, 0x04BAB539EDB21F80ULL, 0xBFC2918799CABD00ULL, 
            0x3F588AA6B6F1600FULL, 0x2AEF7ECDBE9E5A1AULL, 0x81376E8FA2A14E74ULL, 0x5A683DD619BA929DULL, 
            0x395014E280E76339ULL, 0x4522D657F102379CULL, 0xAEC82D7B18A6C0D1ULL, 0xF2AC0BF4F01B207BULL, 
            0x3106DD092A32C8FFULL, 0x795007B31F32871BULL, 0x645B534E53AF40C9ULL, 0xD33229D1903266FDULL, 
            0x79E8A4E885C08746ULL, 0x856C09CAAF9E3D1CULL, 0xA1C09DC0D5B4BDA3ULL, 0xCB70B40C81AB3467ULL, 
            0x2A94FC0E509F4E96ULL, 0x3924FB6009D1F938ULL, 0xBE375EDC6D0DA29EULL, 0x9E1947DE7C812C10ULL
        },
        {
            0xDDE1BB4876EB2BF5ULL, 0xD4F9BB758A3817D3ULL, 0x5B182201385E2366ULL, 0xCB18ACA5E4EDE93FULL, 
            0x82F2D0CE7F33EE2AULL, 0x5FCEC43D697A8D37ULL, 0x8F47EC79BDAEF8E7ULL, 0x7D248C50B29CF7C8ULL, 
            0x04642BC48832CBDEULL, 0xAF3F6EA9B4089CCAULL, 0xCE5202CAB9EF9231ULL, 0xAA0F4B4C6102F7F5ULL, 
            0xA50788CDB13F1DAAULL, 0x0D3A9803032EAC0AULL, 0xA211B9DB14B8ABDDULL, 0xFD3DC34D877767E4ULL, 
            0x05286CBF735DF22BULL, 0x7005A2B682178EC4ULL, 0x9229D4FAF517B5F5ULL, 0xAAFD0AD56479C411ULL, 
            0x1589D0DB4BA099B4ULL, 0xA68C3C67EF4D34E8ULL, 0xB2C8213C6C22C432ULL, 0x31434085359AFD25ULL, 
            0xC46FB91245520506ULL, 0x1751D3D34C5F537BULL, 0xBB39DAED9532CEABULL, 0xEF2E5C2B1EA2EC79ULL, 
            0xCB398AD046B044E0ULL, 0xFEF90A70361AD2E5ULL, 0xA7AECBDD71BA7DFFULL, 0xFFBDA77A9E7A8B09ULL
        },
        {
            0xEC4E53B169D8DF9BULL, 0xDD72E9E446FC3917ULL, 0x0A77A5595252566FULL, 0xA283E287FCA218F4ULL, 
            0x22257CBCC80BDB8CULL, 0xE8A995503CA0B6F8ULL, 0xFE13C0E3B133FDE2ULL, 0x37EC2B5AF734C5B4ULL, 
            0xE9E22959E7558988ULL, 0xB0FD86CAC42D2089ULL, 0x25DD5E33F787D62FULL, 0x4B8A2DB2D877BB53ULL, 
            0x0AA800B53A5FCE5FULL, 0x54B65E969EACC4E8ULL, 0x4381A47281C42435ULL, 0x384C9439A5EEE0F0ULL, 
            0x2BC6867E32999D51ULL, 0xD49705E711E1C5A9ULL, 0x134A149E2A210AA5ULL, 0xF3A8EE527A408B3AULL, 
            0x2249E49651CE5C33ULL, 0xCB4B4C9D8A5C0930ULL, 0xD454A543980C7466ULL, 0x5BD006CAC119CEDAULL, 
            0x7D7F70212B4EDE64ULL, 0x435521A4749EF6A8ULL, 0x606E8069A0D495FFULL, 0xE005D4265427A129ULL, 
            0x7CCAD518254C86BAULL, 0x00E30966781A03B9ULL, 0xF89A961B23B8A9BEULL, 0x6962BF11A1B342DDULL
        },
        {
            0xDD9B14804EE144E4ULL, 0xAAD83F3447E3D343ULL, 0x8F7131776029F4C4ULL, 0x0D6092020D55C370ULL, 
            0xB42F386D67AFFBB1ULL, 0x3D2A7895B9AE97BFULL, 0xBD9230D89745B110ULL, 0x935A9243FADFD156ULL, 
            0x838A58F7E2695F0DULL, 0x69260A3FD4B633E5ULL, 0x76B6ACE5A6C70E4EULL, 0xBFCBA12B588808F8ULL, 
            0xF49577040DC35669ULL, 0x25DB7EBBE56567FAULL, 0xBB547C1FFFB0671CULL, 0x2349D6276E7FF8CCULL, 
            0xD86D537C1E462DD6ULL, 0x178BA03439A668FFULL, 0x00F1C150B1C489C0ULL, 0xBFFBFD13BBD4AF86ULL, 
            0xA2D3BD8081F3EE80ULL, 0x843018704FC7FD14ULL, 0xB1790B31F1C9BF35ULL, 0x8C7715B78479BBF9ULL, 
            0xD1323796B618A635ULL, 0x958A50BDDDFEFE68ULL, 0xA1AA30C5C37D7C62ULL, 0x1AF77404BFB5793AULL, 
            0x052FB30C276E0D0FULL, 0xDD1E8749BBD2AC6AULL, 0x59B89E54C7F82088ULL, 0xE911430C66583A4DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseAConstants = {
    0xCBE4E19A63AE82ABULL,
    0x33F0CBE706DCEA07ULL,
    0xE69B1B5B32D1FC7AULL,
    0xCBE4E19A63AE82ABULL,
    0x33F0CBE706DCEA07ULL,
    0xE69B1B5B32D1FC7AULL,
    0x04CBBF6CF1F617C5ULL,
    0xA31C2E3030A9557AULL,
    0xD9,
    0x1B,
    0xC1,
    0x85,
    0x5D,
    0x3B,
    0x6B,
    0x14
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseBSalts = {
    {
        {
            0xD10188416A414E11ULL, 0xA79960D880306C24ULL, 0xF9756184F407A6DAULL, 0xF69612327AF8C56AULL, 
            0xAD82F9E88F7E4420ULL, 0x407FB4D898965BE2ULL, 0x201137DB8DF372CCULL, 0x912BA12AF4882731ULL, 
            0x4F58D183496DDFB6ULL, 0xF9C2BC09B0150975ULL, 0xB7E598248BB1AEC2ULL, 0x744BBC6BA352BEA2ULL, 
            0x3B2A472FD3289E4FULL, 0xF7A7E29EC6F3B2D5ULL, 0x68A8F6EBF16BDC5BULL, 0x6BB84241A1757207ULL, 
            0x3076070C5A308FCBULL, 0xDA23ED2F39756C0BULL, 0x2A90C8D7665E0796ULL, 0x5947C8DF3EFB5BE5ULL, 
            0x4DC169B8F7D11894ULL, 0x3D64105A294605ACULL, 0x2E649AFC5984107DULL, 0xBBB680DD0DC81A3DULL, 
            0x1E8B0742EFFF8360ULL, 0x6AAFC90CD9E8445FULL, 0x8EECDD8D22138CF1ULL, 0x1896DC85D1566C34ULL, 
            0xDB4FAF0EE8925343ULL, 0x6BF9135CE78FBA1AULL, 0xB071F88B57DA42BFULL, 0x9A7A1472FE6ADA4AULL
        },
        {
            0x0D67B7A0ED408186ULL, 0xF738C44C3AEABBFDULL, 0x1AD8EEEC8F7C40C5ULL, 0x0419727852E80AB4ULL, 
            0xA294D6A17F888AA3ULL, 0x1B40F91C3C0629EAULL, 0x863E873953A2C33EULL, 0xE37B377384D5E1A8ULL, 
            0x35EDA598D1A0EC51ULL, 0x253F4D7643C033B9ULL, 0x17DECCC699C8C57AULL, 0x1DA604AB69199BDBULL, 
            0xA35DD91074DC6FE0ULL, 0x1F329DAD5E6C256CULL, 0x7604DBF0D49E9AFEULL, 0x164BD55AF596459AULL, 
            0x988ADC4B67F5ABFCULL, 0x6C6BEEDB7216DADDULL, 0x83F063FF77D1B3FBULL, 0x659F5F2C104F61FCULL, 
            0xA756672564571C67ULL, 0xC8E71132C1A334A2ULL, 0x82FC989DF6CCA0B0ULL, 0x9F66FC15F2EABA51ULL, 
            0x381F8E350E25B575ULL, 0x46379A10DAC18CBFULL, 0x130A099C7B66D883ULL, 0xD67EBE02FBB77122ULL, 
            0x77040CEC68FFFA91ULL, 0x332322F0D940AF9FULL, 0x770161668FCCCE9DULL, 0x28AA17CAAB9329F3ULL
        },
        {
            0x57FD021855EECCF1ULL, 0x1586052A7DF51E53ULL, 0xAC3A4EE848BDA3A8ULL, 0xCD17FEABA0C27CB0ULL, 
            0xEB3368E566203B15ULL, 0xE05725183874586DULL, 0x67005D52A7BB0FABULL, 0xD518B3139BB320FAULL, 
            0x2E62AA75400FCD72ULL, 0x42BD57FF27609AD6ULL, 0x73344707FA456C85ULL, 0x025C0DAB6A2CA07CULL, 
            0xEA5C7DFFF25BD37DULL, 0x1E896F5D3F76C76FULL, 0x3A344DE81CD5E3C5ULL, 0xCF31F706AACC954CULL, 
            0xAC1EE547B6E4723DULL, 0xD83EF193BFE68AAFULL, 0x549353E59C39011CULL, 0x54E4123CB3B0DAB7ULL, 
            0xE00E759A13C3514EULL, 0x2E8CA172928190A7ULL, 0x485B23005258DE98ULL, 0x9BC676F999013DC3ULL, 
            0xD35568B30BBFF7C3ULL, 0xF741E04FD5746E95ULL, 0xF000A9030F0B69C9ULL, 0xF0F6AFCCD6237A43ULL, 
            0xA2A66479EEF0CB74ULL, 0x8FFFDF6DD3AB8A3CULL, 0xBFFC4DF2246CE0E2ULL, 0x69A75B9A23741C20ULL
        },
        {
            0x41BD53E448FC25F5ULL, 0xE645D5681028293FULL, 0xD94E4F358CE67F06ULL, 0x2EF7A9D5C93A433DULL, 
            0x0AA93FB60E17CD85ULL, 0xD8AFE5D013CA455BULL, 0x59ACBD37FD0E9862ULL, 0xD933D3208329C65FULL, 
            0x28CA8CC230BE974BULL, 0x39BF02BD2F3F0620ULL, 0xC2C2E0EDB8B6FB64ULL, 0xAA27077455A4EE02ULL, 
            0x3CAD78C593CCF050ULL, 0xB497723BD03DB384ULL, 0x9E0A576FBF5AB50BULL, 0x1368BF83032B2AF8ULL, 
            0x570B47FAE9287E81ULL, 0xCF6404EEC7BA6E66ULL, 0x87EEECB9490C6962ULL, 0x6AFD515836B0FC69ULL, 
            0x6E134F2BCDC15F50ULL, 0xD05DE98770ADE772ULL, 0x97B7A5F03961526CULL, 0x7EE26A61E4C4EC17ULL, 
            0xEB0A72C58296CBD8ULL, 0xEB017E0E81B78B4DULL, 0x6B071EFB71188DF4ULL, 0x2F50CAB3F7F2178BULL, 
            0x6196DC1D1E9D5AA0ULL, 0xB7CA6DC3AAD0CE9FULL, 0x5666823AE6E7492BULL, 0xEFD409DD225DE94FULL
        },
        {
            0x415434D7B11957A9ULL, 0x0DB4F26540A7A69BULL, 0xE405D3A80C2BF56CULL, 0x1E5BB1E947294742ULL, 
            0xEA5BE57986898AC9ULL, 0x95AAFABABAF241F8ULL, 0xBD0DDD112B620E7EULL, 0x6EDCB71546845BF5ULL, 
            0xA9A4E9327165C4F8ULL, 0x46530766C3EBD916ULL, 0x24D870A418A37FB7ULL, 0x27255F20859AECB2ULL, 
            0xEFD9A36FCCB3FD37ULL, 0x4A8ADE0889E12F3EULL, 0xFCFA34B85CAE3C07ULL, 0x849698FBCA905A1EULL, 
            0x53B28153C89108E3ULL, 0xC5C9962B0BE5087DULL, 0x16224B6E9EE291D9ULL, 0x237AA5DD4723D858ULL, 
            0x3D3B9B205000AAA2ULL, 0x1EB263DB34331EA2ULL, 0x897958D4467D68E7ULL, 0xDBB2D1A1A815AA6BULL, 
            0x851E2B49104A19EFULL, 0xF1FEAFC327233142ULL, 0x73AAC25EBAB63C38ULL, 0x696345AE16AC8369ULL, 
            0xB17C26B34AC2A364ULL, 0xDE8FFD405114099CULL, 0x374CFE27F1E9E060ULL, 0xB944B5B767CD560DULL
        },
        {
            0x2961C85DBEB54935ULL, 0xB133F6C3918DC91CULL, 0x63A0C6679B3FEBFDULL, 0x2464824502C64D4AULL, 
            0xBEBB88BD616946A9ULL, 0xE5C81A1C52F746A5ULL, 0x6D7DF2B57DCC6E6EULL, 0xC6D6251372325859ULL, 
            0xABC7EA0BD3A162C4ULL, 0x851210BB75C85D7FULL, 0x364D611563B1DD47ULL, 0xB3B7A1B5276ADC62ULL, 
            0x2B161C26C555AB6AULL, 0xABE2B385F4FAD609ULL, 0x903E1DAF93F7359FULL, 0xD3896DAF471752B7ULL, 
            0x91EB7A96883555C7ULL, 0xDD1D69A4E55AB3C1ULL, 0x15699BA583886AE3ULL, 0x232CE533E4367A5CULL, 
            0x43227F70E8B067D2ULL, 0xAB52DB9B35FE1F2BULL, 0xE7A770D94E8919D1ULL, 0x12D900B42D672FB7ULL, 
            0x15202EB4CA7541CBULL, 0xBE67923A9F166DBAULL, 0xEABE5F4B025EA16FULL, 0x32AC94144BFD8ACFULL, 
            0x20202CF5C63A1347ULL, 0xB75217D8F1DFEE6EULL, 0x85CC6FB81B28DC57ULL, 0x7A1B9579CEB9AC58ULL
        }
    },
    {
        {
            0x3D6839801CEE9741ULL, 0x9761EBD1BDDEA013ULL, 0x1E39BC9D0E130FB2ULL, 0x88E919F8A2195B75ULL, 
            0x7490D6AE68821930ULL, 0xFF05A1FC66F131D1ULL, 0xF2E517A92AE09AA1ULL, 0x4150B23E240AFC8DULL, 
            0x30E96D6B59862ACFULL, 0x244103A3FDD179DBULL, 0x5F09A26FF4703CA4ULL, 0xCA84410274C68C90ULL, 
            0xFEDF399E4DF0ABA4ULL, 0xA5DD240A726E75D3ULL, 0x5034FC9E39E56589ULL, 0x1B6999D63F893A88ULL, 
            0xEF04547D4C7BBF06ULL, 0x0436E178A453F071ULL, 0xEAD0C21D5ACF4D8CULL, 0x88FEC077476EDFDCULL, 
            0x4941AC7771963DBBULL, 0x1A3BC791152C6975ULL, 0x5770D57A8A40633EULL, 0x1A058179DFC8B8ACULL, 
            0xB74305C0604CEE1CULL, 0xE9E0A831643E6EF9ULL, 0x3DA04D0F4E959A16ULL, 0x854F1F1BDCB9716DULL, 
            0x63A6A2B56C7CD0ACULL, 0x8951D5530474A4EAULL, 0x4EC13898C69E3616ULL, 0x1482A633434C946BULL
        },
        {
            0xEBA7AEB639D50832ULL, 0xF4517D9CBFB389D5ULL, 0x139A4BBCA117FED7ULL, 0x132E1908FAEC98DDULL, 
            0xEBB053CCB7FD41CBULL, 0x65D523A335835A46ULL, 0x778286CE50DFE558ULL, 0x22A3CCB7274B556EULL, 
            0x017B0148E5DD9E59ULL, 0x576D88FD034A2618ULL, 0x908360B10062ECAAULL, 0xC56D511F56BB8854ULL, 
            0x8E07AFA6E764B8E2ULL, 0x0B519EDE7B4856BDULL, 0xE4B753BDE01BA00BULL, 0xD90E35C51FAEC8B6ULL, 
            0xC808A792C58E6EE7ULL, 0x6F67C34F1E870696ULL, 0x7D25652DD0AD8F4BULL, 0x10E24B42A687FCF6ULL, 
            0x4141394C6297DC04ULL, 0xA224F8435C81E147ULL, 0xEC9A5A258CD728EBULL, 0x7F94BB5D1AC90755ULL, 
            0xD4A076FDF925432CULL, 0x4331A27CD8FBADBCULL, 0xEC3B401C57504B74ULL, 0x5B7F4451643F8CFAULL, 
            0x3C9F951EAA1ECC83ULL, 0x66EED13CA94E7463ULL, 0x7B91B2417042A02BULL, 0x8CBB901DE313BBA2ULL
        },
        {
            0x1823919444FCE4E3ULL, 0x4287EE2B3B1677B1ULL, 0xE90AB7EFBDA16B82ULL, 0x78348505E32B5F67ULL, 
            0x980C7059D6E6C9C4ULL, 0xC7932A01A7A9ECE9ULL, 0x47285BF7DF0721C0ULL, 0x0B402AC72D76FC8CULL, 
            0x27D40C748C191542ULL, 0xB2C7CAEBC9404B75ULL, 0x35B9D1B88E7705ACULL, 0x0F4609D228370B5BULL, 
            0xBB2D6EEBF302CB71ULL, 0xEDA99630663BEF06ULL, 0x21482C77B1A2E87AULL, 0x0088A9322CBA5C59ULL, 
            0xF508D5F7B3184A6DULL, 0xC093FFFBCF32C4A9ULL, 0x111AD59C173F62E6ULL, 0xE9550187BF90303DULL, 
            0x42E2B5B6C67D24BFULL, 0xCA0797E8EB648977ULL, 0x49242E8B7EF36EDEULL, 0x17B1D337D63416C6ULL, 
            0xEBC0890589A93B16ULL, 0xD02E0DCB7B5405BBULL, 0x1283606C93836C87ULL, 0x83A2FBC105413EE5ULL, 
            0x8C17C1B0AFA419EDULL, 0xBD7F70AF171BF101ULL, 0x90327A4130E53F12ULL, 0xFE5DBC3383124362ULL
        },
        {
            0x77FB2E164E77F15CULL, 0xCAFB508E2AAA50DDULL, 0x9B14286552D1A486ULL, 0x43D4E6540CE8B5D7ULL, 
            0x76E21BBB4A6988FBULL, 0x0C9B9392F37FAEA4ULL, 0x17E92FA78C0583AEULL, 0xC17D493412B92487ULL, 
            0x356411A4DF54533EULL, 0x86D9BCF5486A116AULL, 0x41BB7466F3480A0EULL, 0x69C86682A5F988CBULL, 
            0xE679C059FC2FA621ULL, 0x0983C0B54796315FULL, 0xD2F5C46649325394ULL, 0x4EEF8DE3F885A660ULL, 
            0x7D21B1951E3FC851ULL, 0x9EAC65914A03F077ULL, 0x9861D5EE62E61DF5ULL, 0x38BC0BCA569CABCFULL, 
            0xE5FB83054A0A8037ULL, 0xCE81FBC4CB81CFE3ULL, 0x4B7FE064C0C63FF8ULL, 0x8E0BE5477C9B6C32ULL, 
            0xF13A300AD8A4D8A5ULL, 0x5349C2DEB6004F3BULL, 0x4B7F44840978E716ULL, 0xF64E8E05BB44C697ULL, 
            0x041B9C94714E59CDULL, 0x81F86E5868231AC3ULL, 0xFA566E6968D870E9ULL, 0xB6E59622AD78383CULL
        },
        {
            0x71FA3F3040CFA405ULL, 0x5B4426EED8D1BB25ULL, 0x17D012383C607698ULL, 0x679FDAE4CB2B108BULL, 
            0x80F0FA999E8CDF63ULL, 0x2DCBC4189673DBCFULL, 0x1B4D7F655E154FFAULL, 0x497209F3B8AAE6C7ULL, 
            0x0000D9C3E898F2F1ULL, 0x67305E72A6D16548ULL, 0xF1C8957E82C19109ULL, 0x5E5715A5D601223EULL, 
            0x34149F45D3CC32B6ULL, 0xE32F549C62D76DBDULL, 0x3EF79DE319EC3CF0ULL, 0xDF3C69122AEBFB24ULL, 
            0x9871422DFD44C3E8ULL, 0xA5A965AB21B113B7ULL, 0x6E566DA178869668ULL, 0x7FA7320E55552E22ULL, 
            0x85FB368117D7F906ULL, 0x8F4580B376598B13ULL, 0x2D6AF561A9DC5AB0ULL, 0x3E53B89578893638ULL, 
            0xB4BA12BA81F3EC11ULL, 0x78767220BA62DA29ULL, 0x7746E91C5F056D4CULL, 0x6A1050B96924F569ULL, 
            0x732433C2275B2998ULL, 0x24BA625918FCE40DULL, 0xA427D7F791CD43D7ULL, 0x259D6E8B4715F714ULL
        },
        {
            0xDE412E744A6874F9ULL, 0xC61E8D9DEBB441CAULL, 0x00BADC6D1E1AF4C0ULL, 0x7B1BAE7C57786016ULL, 
            0xC2F7DBE3E075A111ULL, 0x74674C9EFEA330E8ULL, 0xD79E60AFF54DE622ULL, 0xD3FB888A017313AFULL, 
            0x63DA2F4F21F8FF14ULL, 0x0D968C48A0D7860DULL, 0x2799DCCFB453B030ULL, 0x14829606E00CD031ULL, 
            0x69887BD009A7C743ULL, 0x8CE30C6D2F358AE9ULL, 0x04D4FC16ADEBA260ULL, 0xD3F712460A61E826ULL, 
            0x77999432D183B9CEULL, 0x3229FBFE48564D5FULL, 0x22774689FBB78DADULL, 0x6E39CD33F5C79AD1ULL, 
            0x712B28239E81E438ULL, 0x1044421EF42B926EULL, 0xE6F937667E7A48A1ULL, 0x56CF8299C933D78BULL, 
            0x6B22D58DED8A4E15ULL, 0x058D25FB09C3BEB3ULL, 0x49D1216724ED92DFULL, 0x23B0B565E083DC86ULL, 
            0x9550F1160E9D53B1ULL, 0x96ACFD27AB3C24D9ULL, 0x5F696E0A0C85E03BULL, 0xA04C94410D6E9BE8ULL
        }
    },
    {
        {
            0xE413DE57CA78BBA4ULL, 0xFB1490D89F30F5BDULL, 0x4AD0ACF6F44D7E23ULL, 0x82560C8E3405EC04ULL, 
            0x0C54C0B9531889A5ULL, 0x9D14E8797AE70382ULL, 0x882367343679B238ULL, 0xCA94F23D655C1472ULL, 
            0x287021578A98F088ULL, 0x242D0C9CC33E1596ULL, 0xF5671B2A76CB1822ULL, 0xC8F0723BAEBACBFFULL, 
            0x3DB968BAD59E851EULL, 0xF1B3549BF5182F9CULL, 0xEAF2A12B114BEB2FULL, 0x6028661A6FE7BDD8ULL, 
            0xE5F6D0739DC7A108ULL, 0x331AE6E63FA749AFULL, 0xD3E46BE2AF81C958ULL, 0xC3213905DC598850ULL, 
            0xAF82D39C6E7C2AEDULL, 0xCE73BCACE9756A81ULL, 0xA031FEF288B7153EULL, 0x2ABF0349E7F366B1ULL, 
            0x544630C1DEA33C56ULL, 0xD7A232173E5FBEE6ULL, 0xA66ED636CE219AC1ULL, 0xFA696FD4A9B32CD6ULL, 
            0x88E2E642F3F0E1B3ULL, 0x59C95331251B4CDBULL, 0x0771D7B8E38274B5ULL, 0x5B155296254532B1ULL
        },
        {
            0x44EABCA1F3FF0DC5ULL, 0xD9BAE836EABF4AD7ULL, 0xA85487D2329C4FD4ULL, 0x51EBDD741F29B6F2ULL, 
            0x073A69B2148E6795ULL, 0xEA511C09D4354459ULL, 0x6717F0A7E8C1A313ULL, 0xD3E16268A0123E8EULL, 
            0x43FFCC29F8CE9946ULL, 0x41CC5AF45AC86016ULL, 0x0A0B63619AAC07B9ULL, 0xB64502F7750D1513ULL, 
            0x44ADACAA9712DC3BULL, 0x5A81F38E7EC7DDB0ULL, 0x59B255F5BA72749EULL, 0x602E1A24D650F561ULL, 
            0x8DE4A8B770B1D39AULL, 0x172479F9CB39AFE3ULL, 0x4F52095D19212FD1ULL, 0xABCB24BAF2A9FC0FULL, 
            0xF8C15CEE41C4913CULL, 0x41718E3DF977DE4EULL, 0xA7AD14F0730B42DAULL, 0x40E4B13857551F4FULL, 
            0xC6F7F9E0B3A03524ULL, 0xD3A37096B7C73A56ULL, 0x6C9D6ABFFC15D8B5ULL, 0xC98DF6CF7F44B7CDULL, 
            0xCCA40BDC6BFE643FULL, 0x5D7C171134AA0B6CULL, 0xE8970CF3F0473C59ULL, 0xF16BF9C723B1ACD2ULL
        },
        {
            0xF5E4B7E9747B3637ULL, 0x2EAF478C5AA3BED9ULL, 0x1E3FBC22A399AFBCULL, 0xE4BD88F7210C8D54ULL, 
            0xF2287F58A8B9EBB8ULL, 0x986A4D9B4BCA81AEULL, 0x30271779776DC203ULL, 0x4C07EDADD58967A8ULL, 
            0xC98A179FFE95DDD8ULL, 0xF38480ED9D4AAA62ULL, 0xCD5331C108794EB6ULL, 0x3CA1B62C130B07D1ULL, 
            0x0A4DC3066D2CF908ULL, 0xFBE8D2629EB5DC77ULL, 0x3C25DBBAC3BB4465ULL, 0x71E0E4BDD089FC85ULL, 
            0x7492BA79707CE9EFULL, 0x4811FE8FBCFA0C39ULL, 0x826C601802618925ULL, 0x1A0B5E27AA587B46ULL, 
            0x49D5AE2AE31B8123ULL, 0xF7960B641FF265E2ULL, 0xB47C4B6F8E20DB6BULL, 0x0C0EB9C123FDF606ULL, 
            0x83891D9A8048D9E6ULL, 0x27A2855AE1B8545AULL, 0xE6F0097ECCEB1840ULL, 0xAD6DA8335A80ABFDULL, 
            0x318FEC8E23C35045ULL, 0x18B9CC7703A9EBF1ULL, 0x410C0A06A54EFB3CULL, 0x80A0E2AC0AFCD12FULL
        },
        {
            0xFE33DBC734EF7D29ULL, 0x435018B22B47856AULL, 0x0825B776B3BBCE14ULL, 0x7F0799A3B3DBB1BDULL, 
            0xCF61D05EE7D24A50ULL, 0xA46A23790865939FULL, 0x31421393969DBFDFULL, 0x2D862FFCDC4099E7ULL, 
            0xC2FB6920DE738DFFULL, 0x2240718086DF0257ULL, 0xDA9C7D3430391F16ULL, 0x6E1C37806BDACF9EULL, 
            0x42EF6F322228DF1FULL, 0x35232BE23B17BC3EULL, 0x672A61C905F1A9E5ULL, 0xC6590E90C350FA75ULL, 
            0x505527CDAF55F4BAULL, 0xB254F8A180E02B81ULL, 0x5273755216B8C6B9ULL, 0xE9599A6AF839DC82ULL, 
            0xF6668A702CE26496ULL, 0xAE0C8AB32B29A15EULL, 0x122F8963C8D04090ULL, 0x9AD6D2F3BCA81A16ULL, 
            0x77C5F8DB97B1F11DULL, 0xC3661C23BBC875FDULL, 0x929548AE8557B57AULL, 0x6AFA8199DD32DD3DULL, 
            0x20EA3DEB7D0FE814ULL, 0x5F0C454237CFEEB6ULL, 0xCA5E81E9888DF30DULL, 0x7542D92453C9B83FULL
        },
        {
            0xB851003926394E76ULL, 0xCFAF1FF19F8720C3ULL, 0xB09E523687F1FF10ULL, 0xAA02CAD2F91B7534ULL, 
            0x2D3FF1D1B73538EDULL, 0x81720EF107F89059ULL, 0x8037C522848D344AULL, 0x6FC93410B7DE1170ULL, 
            0xED76D2D859D43020ULL, 0xB8D992B6A746C0DAULL, 0xF458EEB5763CB967ULL, 0x2C4189AAE2DAA5ADULL, 
            0x9D1E50DFCE891192ULL, 0x5821D513CA11B192ULL, 0xEDC0DA3E6685FC2BULL, 0x498AEC9BE420BC02ULL, 
            0x597040257B18B0FEULL, 0xC9A04A673320536EULL, 0x2FF0DD2DE0BD78AEULL, 0x80665AE76A8B26D2ULL, 
            0x5EC900984F813E44ULL, 0x99280741950E9BBBULL, 0x301C7C0619064CE2ULL, 0x6E987441699FE485ULL, 
            0xDBC858AA2E4127ABULL, 0x474BAE74772BF944ULL, 0x1843001BFAFE1210ULL, 0x1B50FBD8F0B85CEBULL, 
            0xD428CB96D9796393ULL, 0x6A61517AA4E87BF5ULL, 0x1963CD3743AC9041ULL, 0x19658A6B704DD646ULL
        },
        {
            0x8ADA7B7BF7FAEE6BULL, 0x2B7EEE77C598EF66ULL, 0x04F580F895E100E3ULL, 0x4AC38B4020A30087ULL, 
            0x8FA70E5156B46E13ULL, 0xB262F5D9795BE6D1ULL, 0x342884FD03944315ULL, 0xD71A8BA34C2C361BULL, 
            0x1FA19503014517EEULL, 0x3EA8E3C41B4BA4FAULL, 0xF28FA7438F8EAD2EULL, 0x75F9A26CFCCDFB07ULL, 
            0x47489B289FBFEC67ULL, 0x34FA2E859CA2978BULL, 0x4C13C66CBB110B29ULL, 0x76E2D17C4A66AD48ULL, 
            0x01BE56A019ACCDC0ULL, 0xD0FB041A7E8AE3ECULL, 0x2C09696A7A977628ULL, 0xC60C1B8144758084ULL, 
            0x4D8D6145455CEBE4ULL, 0xDC8F6DB8787EAD27ULL, 0xB568FB67C5419E69ULL, 0x3EAE5EFF4BE205A3ULL, 
            0xFB02316070621722ULL, 0x0245FD12C621B3A5ULL, 0xB71781C1AB68F086ULL, 0x85D230556BC628D0ULL, 
            0x2657227D000EF2ECULL, 0x4BD4002EB1168F09ULL, 0x5387654BF4B39804ULL, 0x8441620C20A6AEA4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseBConstants = {
    0x20D672FB12831C59ULL,
    0xE3CF343BDB009338ULL,
    0xFFCA0CD8FFB6458DULL,
    0x20D672FB12831C59ULL,
    0xE3CF343BDB009338ULL,
    0xFFCA0CD8FFB6458DULL,
    0x544747FBF8298756ULL,
    0x1314A91159E947D0ULL,
    0xC8,
    0x5D,
    0xBB,
    0x39,
    0x17,
    0xD5,
    0x47,
    0xD1
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseCSalts = {
    {
        {
            0x95D66D794BE1E93CULL, 0x9E052D6E2BDE34CAULL, 0x83A09B7FE3E234D6ULL, 0xDFF8C4AA8621C403ULL, 
            0x5D06D66F8E72EA87ULL, 0xA39E6058E939F167ULL, 0xF9D313FE42471396ULL, 0x47471A7D4DA8A4E9ULL, 
            0xFED9BA84DF62E96CULL, 0x63CAEAF8E8D64FC4ULL, 0xB3D88430551E9348ULL, 0xE3A5C6727192F52CULL, 
            0x5F6A50E8D3076A2EULL, 0xBF72D9EAAD900D30ULL, 0x34944E61CE22EBB9ULL, 0xBC6955D512127638ULL, 
            0x05CB7B7C1FDF5CDAULL, 0xF573837EA2C73244ULL, 0x7BE39AF089FA75C1ULL, 0xE3EA855AC78146CEULL, 
            0xD8A783C259E35CA8ULL, 0xA50F98AD5EAFE7B2ULL, 0xBF4774FF50E9C6F1ULL, 0x77C091F62B36FE60ULL, 
            0x38CA6A45EF7DB80FULL, 0xEF71A9D4ED925B8EULL, 0x385E20CE1F951EC6ULL, 0x804873774262F94BULL, 
            0xEF666A1A1734C851ULL, 0x41E97CE352D40EA6ULL, 0x9D1102E08BCA987BULL, 0x82DE19AA61181671ULL
        },
        {
            0xD90F91C1DF14C36FULL, 0xC44F3FE9F30CFCD0ULL, 0xBC2034C0BF2E9AA0ULL, 0x33402EF6F6D0C6F5ULL, 
            0x87799230F1169469ULL, 0x4CF28B9DD4554C1CULL, 0xC119295EAACCBD44ULL, 0xCEF883A5CA507F67ULL, 
            0xE48D7CE774163A4FULL, 0x7EA4B8715AF839F9ULL, 0xA4125F6DFC515A53ULL, 0x50A51F0B9A8AE847ULL, 
            0x30E94BE88B0DCA8BULL, 0x6381C6C5643E69FAULL, 0xD368566357342257ULL, 0x2CE229C38DA854D6ULL, 
            0x0A56365995536FE1ULL, 0x253412E84E86D67AULL, 0x5B719CF3146C653BULL, 0xAD5A83DFF0F8A17BULL, 
            0xC309F42C5E67A426ULL, 0x4CFEDDC350163538ULL, 0x7E2EF4584BF03B15ULL, 0x0791AE1F9008C46EULL, 
            0x28C2FDAF665020DDULL, 0x095D9D4E1C9237F2ULL, 0xB05C6C8A1A2FEF47ULL, 0xB6F5F2309C29B118ULL, 
            0x14282FF0F48EA895ULL, 0x3E147D71DA8FB669ULL, 0xDDAFA298165D8B73ULL, 0x0B35A661199BF72AULL
        },
        {
            0xA312DA2AA6244B1EULL, 0x863D9556DDA89836ULL, 0xEDAAC912A2DE405FULL, 0x21BA3FBC03A7887EULL, 
            0x1340463B84D30828ULL, 0xD004D00C3AE93476ULL, 0xB1E68CF696A60C58ULL, 0x1AD596FDEFCAA929ULL, 
            0x0E9088EBAE330E59ULL, 0x4C9A8177B8515210ULL, 0x854A983F270D8DC6ULL, 0x4856AE496CD98A59ULL, 
            0x3CC73C7551A42937ULL, 0x6AF6410923BBE246ULL, 0x513FF398C387C369ULL, 0x84C3EDC6586283D1ULL, 
            0xC1E6A8CA93C6B7D8ULL, 0xDCD41529D56C28DAULL, 0x31775A10A2560C2CULL, 0x8320AB9D5B716954ULL, 
            0x944142F3A1B221D3ULL, 0xE8C02E3E5CB396E3ULL, 0x75C9DB2D21950E39ULL, 0x94B92C211AD36321ULL, 
            0x15B1C25106FE30F3ULL, 0xE7682CBD153DE77DULL, 0xBBB66509157DA894ULL, 0x64D1F13C5033964AULL, 
            0xF7D19E8EA58D8C84ULL, 0x957EA7FE85A119DAULL, 0x6FF90C9850B4BEEBULL, 0xBE9F457F359BC5DFULL
        },
        {
            0x11FAF5E00082E703ULL, 0x96B5F7347597CC02ULL, 0x551BE983EF543D79ULL, 0x7568B66364D331EBULL, 
            0x871B8E0B98C9B295ULL, 0x3CC0DB26D00F3D07ULL, 0x9A28221F6A1C6C19ULL, 0x20EDAB1E1F6E2A20ULL, 
            0xC47D0B9E618EDEEBULL, 0x15C7BBECEBD3B7DAULL, 0x64190E3FB8D3FB49ULL, 0x67126D09670CB89EULL, 
            0x824D5EDAA9A20391ULL, 0x6B868EA56FADD3A6ULL, 0xEABF1D0DAB907E92ULL, 0x5FE9D63512B88AAEULL, 
            0x96CD45107DF0599BULL, 0xBAC2FF11394DE053ULL, 0xC66060A99EAF2FC4ULL, 0xC993B50F1D31AC8EULL, 
            0x72E46D2349E95489ULL, 0x4CA3333260A9B5BEULL, 0xD19C9DCAAE0959B8ULL, 0xCAB0601FA243E028ULL, 
            0x0874E0AE7E3C7574ULL, 0x75A9C72D4A00E8FCULL, 0xDF795C3438A65EEDULL, 0xF24743DE4B38885EULL, 
            0x24B712622AF4DE2CULL, 0xB66071E17AAF42F1ULL, 0xC7B9BFA85FEFFD39ULL, 0xD2763D80FA55A328ULL
        },
        {
            0xAA4DDE2DC4C06706ULL, 0xB934FFAAEBA4428BULL, 0xBCC37809C80BC3DAULL, 0x0E15F98DF83EF411ULL, 
            0x7F54EA4C5800BA2EULL, 0xE7B68D66DFB88A06ULL, 0xF72A1C91BA4775BAULL, 0xE7AA89D1AE43A3E1ULL, 
            0xAADBC82745B5FA80ULL, 0xCA5E449136A74D23ULL, 0x931F2FC7EF3A9C21ULL, 0x11E55F77DFF95EDBULL, 
            0x3CE17A5A7A19BC60ULL, 0xC7897EE96B211AC3ULL, 0x04248F21455203F2ULL, 0xA35FA2B96E7DAEC1ULL, 
            0x3E9CC793FB347486ULL, 0x4C6D38D10401DD1AULL, 0x5864631FF33ECF8FULL, 0xAC94735EA2E07E45ULL, 
            0xB9166C7500DB2935ULL, 0xC7874491F6472322ULL, 0xDAB5677CD90B9C6DULL, 0xD5165F6698ADD748ULL, 
            0x3C5094E61CE9DBADULL, 0xD5A5C4BB0A7AEA2EULL, 0xA5BB5AE9FDB75D58ULL, 0x385931F442AA7E5CULL, 
            0x69CBA37564C58124ULL, 0x5C06CA63AFA69DA7ULL, 0xB38176AE0CA82DDBULL, 0x18D544818DC75246ULL
        },
        {
            0x3A3C99AF803FA1B6ULL, 0xA4527D30A2017DA5ULL, 0x31E59DC18D643524ULL, 0x6DD17A87DD7F5844ULL, 
            0xDFBA5B7CF738A148ULL, 0x7372DBE637E40C86ULL, 0xE3444A84B26C2EF9ULL, 0x5A47F44C65EF555BULL, 
            0x1E765A46CE88B7DCULL, 0xAE3553B29BCC3A93ULL, 0x5ACCDCF2E6C1F7FEULL, 0xDC8210CCC4ADB8BDULL, 
            0x199FA0A75BF20AE7ULL, 0xCA6FE152B7F8D0EAULL, 0x7F30B308BE92AAE3ULL, 0xA09A479A4BD215C6ULL, 
            0x81BEEAA0EBE95107ULL, 0x2A5B200CDA65E976ULL, 0x0E5EA9AFC801BD73ULL, 0xAC418FC3E67432C6ULL, 
            0x07BB3E77E3C84473ULL, 0xB9E587CB9648F133ULL, 0xDD1064DBC11FC894ULL, 0x8DEB1C6F5B6F3E66ULL, 
            0xF50122BBE3CA7AB2ULL, 0xE2B3939E4C8D77C8ULL, 0x6B26BE7DC57539A3ULL, 0x2A4417AEC5A8E1D2ULL, 
            0xF6FA22ECF6F4E913ULL, 0x72C7ED4AC38886EEULL, 0x26224A2A3472771BULL, 0x906ADD6993B443DBULL
        }
    },
    {
        {
            0x8FC2A5F171C39415ULL, 0x934A84D8A82FDEC1ULL, 0x901B1C787573DBD4ULL, 0x3D03BD6ED3E6DDFDULL, 
            0xB47FF4833712DDD6ULL, 0x8C191CCF905E300FULL, 0x6818C8DAAF0F6C08ULL, 0xA0C060ED22AD7D19ULL, 
            0x20748D638531CDEAULL, 0x37629A5A87DC0EF8ULL, 0x2291B94A80038646ULL, 0xD1802F1DA0652B7BULL, 
            0xB41BD11255600825ULL, 0x532D9A01B1754CF2ULL, 0x8BEBDA5639E43F68ULL, 0x9E2D9FFA88A60234ULL, 
            0xEFBB167A14860020ULL, 0x1D4F3446094588E3ULL, 0x9BEE8C15551494B3ULL, 0x9DC880840F7E965CULL, 
            0x035B8EADD517922FULL, 0xECC1F744C146727AULL, 0x8C7251C8880DCFFFULL, 0x24F5536C8322B491ULL, 
            0xB25FBF823FF1465EULL, 0xD54081F03C034C31ULL, 0x5FDD458D4809A207ULL, 0xCE3DBA3198629029ULL, 
            0x6DDBE40F5CF4040AULL, 0x2356F19B6A04F7E3ULL, 0xA3F3D89FFB0E24FEULL, 0x1BFEA1D8B44F9C15ULL
        },
        {
            0x487EB872064F4C66ULL, 0x99255328C3C784DBULL, 0xCB39752F475DCD91ULL, 0x94E814DD5953A46FULL, 
            0x80F785DB10CAFC9AULL, 0x6A3130ED626C52A1ULL, 0x69F6FD87000AD6BFULL, 0xBF5783422EEBCCC4ULL, 
            0x0B10F0FBDD0D9ED0ULL, 0xD94AA5E70D7289FBULL, 0xB48FDFF756C7F428ULL, 0x6A08DAEAED3F197BULL, 
            0x8A445244959F1411ULL, 0x9F1318809587ECBBULL, 0x70640714CE2B4487ULL, 0x5F98637B19FBF4C7ULL, 
            0x2A68CA6E70D57BC9ULL, 0x3E94800D495FE6DCULL, 0x94C3C9B913FCA864ULL, 0x8F773A22DBF9BCA5ULL, 
            0x42F0C2A8375E0341ULL, 0x5775230FB1EE602FULL, 0xDC93797DA4A1C3E4ULL, 0xAED25D3B5E3C6EEAULL, 
            0x8A62BAE8AF19029AULL, 0x2307DE2BF8A53DA8ULL, 0x51A456EFF87E44D2ULL, 0x0781310940392299ULL, 
            0xF1C51164E7402AD0ULL, 0x787BFA2A7A8242BCULL, 0xD014C9351341158BULL, 0xC40A4EF93B930FADULL
        },
        {
            0x66A41A9A329A08E1ULL, 0xB720A42944CC86C5ULL, 0xB1A27D470C1DE345ULL, 0xC1A0B4622F63702EULL, 
            0xD8DC0163F265F0E8ULL, 0x5961539F811C6F79ULL, 0x906A0C9A8CB60C2EULL, 0xECDE711CE8B00AD0ULL, 
            0x9AD87CA262EE8C92ULL, 0x6CB1386BE582D878ULL, 0x825CC3F3AAE6DCBAULL, 0xCCF4176130544AF8ULL, 
            0x8AF1576D08705A2CULL, 0x8A9EB5D415EDDF5EULL, 0xE07573657B17BCA3ULL, 0x2AE95A894E25EA25ULL, 
            0x668D618CE16679D7ULL, 0x2C868B2D9288A751ULL, 0x0155588722F41719ULL, 0x20474F39619020BBULL, 
            0x5467D3C0B44FBE3AULL, 0x1513B054A6E0ABCEULL, 0xA643B28592E73866ULL, 0x1A617A62CBB6004FULL, 
            0x42AC187DDA3E046BULL, 0xCB5C677E13ACB749ULL, 0xC3580071F9A418CFULL, 0xABE3BC0EE9295FB3ULL, 
            0x66F0D2119A455507ULL, 0x7D5F5A07E5B9AD28ULL, 0x61DAB2C65EFDBD0DULL, 0x0B1359AA48592110ULL
        },
        {
            0x0D45979D55016247ULL, 0x1102F2AFD7E86BCFULL, 0x10B0281249A60738ULL, 0x66CB419EE499F9F9ULL, 
            0x1681AD949A5BD8ADULL, 0x5C50D96F0E608546ULL, 0x9E0F97D9E7D63CC7ULL, 0x16952ECF377D410CULL, 
            0xEE73386CC81B6680ULL, 0xE7B5096EF658D4A1ULL, 0x5255A5828900AB87ULL, 0x008D36B1337DC57AULL, 
            0x189AF379842E6DC5ULL, 0x6827F4F67D68AED9ULL, 0x42CFA7622A13B4FDULL, 0x9EF12C4B0FB711CAULL, 
            0x20784C467301404BULL, 0xEE4BF11EB9E48079ULL, 0x6E09511D090D5493ULL, 0x1B83ACA7418A42C2ULL, 
            0xE200CD21B4F6CC18ULL, 0xC8061F31B862A75FULL, 0x7BAD065B8FECDA75ULL, 0x5DDBF102F224BEC8ULL, 
            0x9865AE074FA075C0ULL, 0x339E7472C343E89AULL, 0x1524593CF8BAC00BULL, 0x5BC798A3D0571A45ULL, 
            0xA4D32C2531DDA396ULL, 0xB51F9DFF0A7E4D01ULL, 0xA363ABF34B28BB67ULL, 0xCFE6C293A4A816CCULL
        },
        {
            0x88E921305DA76445ULL, 0x6435E7DE25E24D3BULL, 0x85DA1AFDC9C27EB0ULL, 0x8AD63197BF3BA171ULL, 
            0x87506C33D33258AFULL, 0x01829B1360DA1958ULL, 0xBFC723760A0E2667ULL, 0x61A8EB84CA60FBDEULL, 
            0xFDCCD0E5B2CDB5FCULL, 0xE50F19851F3AAC8BULL, 0x755B8568586C1E7BULL, 0x43607111EC77D19FULL, 
            0xCCA1039A39461752ULL, 0xDFB40049FA87922CULL, 0x3E570594FC8CF33CULL, 0x676C6CBCE56D8D1AULL, 
            0xF1114AE28114FBEBULL, 0xEC3BBE6669E715E2ULL, 0x8A88051FC6E697ABULL, 0xEF1CD9A62E6FE8A6ULL, 
            0xAED9E595078A16D9ULL, 0xD838D92C7B55ECF8ULL, 0x23B2AC771478A077ULL, 0xCE5EF37D5395E659ULL, 
            0x6F728BA03CACB457ULL, 0xEEA6584EA900FA9CULL, 0xE105C779F39EC7ABULL, 0x19E7A6C4CED7AD69ULL, 
            0x2EA3A799FA24AA95ULL, 0xEB73287BC57C6B25ULL, 0x1F2372AA2602F9A0ULL, 0x8292A8A71730032FULL
        },
        {
            0xAB2F141C344F9E75ULL, 0x46BF8C7DBE7AD58DULL, 0xEC20168F18A4EC5EULL, 0x98F05866F85580C1ULL, 
            0x2F3E9694051F4EEEULL, 0xCC7F1D43934E3699ULL, 0x7E2AC2E016BF27FEULL, 0x09F26BA95C6AA532ULL, 
            0xB96E87349CA9BD08ULL, 0xFE822FEC762B013EULL, 0x3AE876B3612F00A8ULL, 0x456549B4FC5234EBULL, 
            0xB55F82138A4D0C86ULL, 0x1FE4ABF3481AC5B9ULL, 0xCEBF9AC6866D3325ULL, 0xC05B148A21BCDEF6ULL, 
            0xAD96D0ACE72B8196ULL, 0xB1BA309D40163F9DULL, 0xD017017C75ABBF23ULL, 0xCA81773A2597FC3DULL, 
            0x9A793D9BB70B9CA6ULL, 0x8C68A0DEFC588C42ULL, 0x8E9190025C13468BULL, 0x7465A5778A5AB74AULL, 
            0xCAACAE9D20714326ULL, 0xBC9AFC0C01E7CE21ULL, 0x8C6659B0DDD45054ULL, 0xF90A3DEF299EAE32ULL, 
            0x7240A7045A197CE6ULL, 0x1EE1E74ABE34E2AFULL, 0x17B9126CEACE5C74ULL, 0xD4604EC51FA303D2ULL
        }
    },
    {
        {
            0x7A51B9BC24358A24ULL, 0x9AF5A0958BF3883DULL, 0x464947493D19B7DDULL, 0x6C89D0FED6B1F4B6ULL, 
            0x5D966A52A68F1561ULL, 0xF3E0C2DFBA7CB5DAULL, 0xE2CBB9C5AAE6A89AULL, 0xD4E9EBF45BF6C608ULL, 
            0xC527AB27B203E328ULL, 0x3E6B190EC83A5E6EULL, 0xB1C3676F4CA70A35ULL, 0xD929AD1FBD14BF53ULL, 
            0xA6A7F1FCBCC6E7BFULL, 0x0E51BBEE8A53C5D9ULL, 0x3054FA441F986E5AULL, 0x1E65ED46526E46E1ULL, 
            0xAD04494671ED690BULL, 0xFA1850B91A737BD3ULL, 0xE05D1ACF9747EA58ULL, 0x322CED3E1873847FULL, 
            0x54BCA19DFAB3B973ULL, 0xD4713D2177F20AEAULL, 0xC36BD12109699296ULL, 0x4949CE7EE60E06CEULL, 
            0x1AF5BE18C2E41F93ULL, 0xB8F38059B2AC4BA5ULL, 0x39A54D8100409B5FULL, 0xDE10E612B946A97FULL, 
            0x4DB40319E95A9383ULL, 0x9020F87B25CB6DDFULL, 0xF70E4437E7A1FB93ULL, 0xCEF9B4EAB81CCECCULL
        },
        {
            0xB100DB865DE4001DULL, 0xE33FCCD25DDD889BULL, 0x40E1F3F9AF9908D0ULL, 0xD398DCEC5F0A5EA3ULL, 
            0x6ABE1E33142DE4ABULL, 0x2547A5F014294750ULL, 0x162129799385F74CULL, 0x9C239CD823D82734ULL, 
            0x01AE94AB0978C92FULL, 0xA2D94787F5979A58ULL, 0xE2C95B6C42A65F22ULL, 0x2B49187E5A4222A7ULL, 
            0x0F552C8E3E68B71DULL, 0x3BD1EFAB0F2AD73DULL, 0x41F9EE7DCB49A774ULL, 0x6C7DF587E8F30905ULL, 
            0x5FD26979DCD3EDAEULL, 0x6DBC1929B5A4F37CULL, 0x3C4C92BB796A6DA3ULL, 0x71487B5264C14267ULL, 
            0xAAA0FC3EE2FC6443ULL, 0x4AC93070E7E4FE7BULL, 0x987FE150CA777D7DULL, 0x9DCB732FB334F79BULL, 
            0xCDDC895D10C3F165ULL, 0x211B071D49890023ULL, 0x2573CFE89F3DEB92ULL, 0xEB9A3F5361F0ED14ULL, 
            0x106A8E6980484BA1ULL, 0xB7A90BB4A197B4BCULL, 0x82A19F4F44AB93F8ULL, 0xEF3A353FAF028EB4ULL
        },
        {
            0x4893818D63473FC2ULL, 0x9241E2F124610209ULL, 0xFBC69499BB915984ULL, 0xE4558AFC4D5968F6ULL, 
            0x2CA19CC00506A8DDULL, 0x319573FDB8BE7230ULL, 0xEF7DA3EB6A41B710ULL, 0x0A2ED5392058BBFAULL, 
            0xC4A90CE0A909BDD0ULL, 0xA76377EFF42A1531ULL, 0x300BBB59D78FDE17ULL, 0x7F8DD637086EC449ULL, 
            0x4D08533A6491B6A3ULL, 0x88AE76A79A725500ULL, 0x823F274B00D6D25CULL, 0x386E2C56D3CF70C2ULL, 
            0x97EE8A8C8DDC8495ULL, 0x007CE792F9EB6DDBULL, 0x9C25206EA190EA83ULL, 0x84E21C86320A6201ULL, 
            0xE4775E388ECF7CFFULL, 0x46721634BE31E61AULL, 0x833B39CC00B5E5EAULL, 0xD4232037A063CB9FULL, 
            0xE7C26FC51D8C6C87ULL, 0xAE937E976B8A15D1ULL, 0xCCE43375A8FD57DBULL, 0xCF0A1652F32F76EFULL, 
            0x60BE4556E6BCDFEEULL, 0x5BA176F8210D40BCULL, 0x92F885E041B7C3D3ULL, 0xD2354A1B77A0B235ULL
        },
        {
            0xC97893F2ABCA7BE9ULL, 0x4E5F0FE2C7D75630ULL, 0x01BB8C1546381CDBULL, 0x35271DDE6ADDA301ULL, 
            0x73C85D93B55ABAF8ULL, 0x017CC80FA784AEAEULL, 0x448FE2C530473D57ULL, 0x13FED405677F6B0DULL, 
            0xB72F04DD1AEC2848ULL, 0x756A1CB13D2177F7ULL, 0x131290587119FFB3ULL, 0xF7BEF4AEA280E036ULL, 
            0x7B4738F80C36A0C8ULL, 0x2349EF9FB880ED35ULL, 0xD2CB03C10A428E32ULL, 0x4E12B45CDBA4412AULL, 
            0xFCBB42DD9358B81AULL, 0x345CBB6465A06E35ULL, 0x19CBCE88282A6AD1ULL, 0xBC169A5462D6F076ULL, 
            0xE0609A0F3E84E3DCULL, 0xF1B9E368B13D4F58ULL, 0x723817D8EF8C7651ULL, 0x045FEBC4FEC97A1AULL, 
            0x2BAA81CC420D2F92ULL, 0x0825B657828DA4A2ULL, 0x581F46C858E342C0ULL, 0xDFE056BD877239F8ULL, 
            0x0A705CD133F30ED0ULL, 0xACC5859EABB040A6ULL, 0x6099E5EC88D80836ULL, 0xA5DDAF2861A5FFE7ULL
        },
        {
            0x10C5933434C4F1E5ULL, 0x752F72D0C9E3FB76ULL, 0xCCE873F5E5586DC1ULL, 0x77FC8470B13830F7ULL, 
            0x3156BD65DE32DBDEULL, 0x2BACD3AD75DC5423ULL, 0x9EE73E4FE1D3BCD3ULL, 0xA24FEF7B7F9E71F2ULL, 
            0xE18137E6F5895ACDULL, 0xB958213EF3301DE5ULL, 0x6BEB4EB7F233967DULL, 0x080E375A9EA5991EULL, 
            0xC4AB6545A7598401ULL, 0x89CA90AEC2E4C424ULL, 0x92D114B0926E4306ULL, 0xDA8F879BCAD4F333ULL, 
            0xECCFB5ABDE70F4BBULL, 0x9866DA6844174A08ULL, 0x6285322952353FF7ULL, 0xFB878D547CBBBDD0ULL, 
            0x6C0F39ED39C098EEULL, 0x3CBB4D60E9F6BC2CULL, 0xEE4460EA1DF03A51ULL, 0x4C36192FF1BD0C9CULL, 
            0x2A3BE1480A2860B9ULL, 0xFDA12A044784BE7DULL, 0x2097037E7C676CCDULL, 0x5CCE094097C6AC55ULL, 
            0x54C19CFCF16DCB9CULL, 0x60BF72F2F8520280ULL, 0x21A82A809F0A980EULL, 0x19890D8AD8FA15BFULL
        },
        {
            0x1CF2D775B664BB5AULL, 0x7D4508357797B309ULL, 0x56F9358D20D03E25ULL, 0xDB2A30FEDD233F0DULL, 
            0x333119A382FCED57ULL, 0x1171A033EAC3D929ULL, 0x53FC70E4EDA13855ULL, 0xC86FE872BBC2508AULL, 
            0xECC7183FCFA0B448ULL, 0x00A8667CF04D68E3ULL, 0x475A6549D0A2B156ULL, 0x1D38E80FF673DE89ULL, 
            0x8051FD3A4FCBA125ULL, 0x6ABB2E257E457A78ULL, 0xEF3FE809579933E1ULL, 0x880DB22CA792DB1DULL, 
            0x145153CB71EB89E6ULL, 0xCF6059D683122EF4ULL, 0x60BA6FFD489C9BA6ULL, 0xE0177CC22977A00BULL, 
            0xCA0B2E2A84AEC431ULL, 0xC962273E02152261ULL, 0x61B7D40420BD8974ULL, 0x10D097E7863B4D2CULL, 
            0x93FD472EDBED9024ULL, 0x2A783011A9721564ULL, 0xA2E58FF8775D9CE5ULL, 0x8F6023238575CD92ULL, 
            0x0D183E01D5C71001ULL, 0xC96935E97EB4CA7BULL, 0xA46E01E7CA9E6BEAULL, 0x478C84D5352B56D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseCConstants = {
    0x1788C58D5AB98DD3ULL,
    0xCFD5EB0B44DC1FAAULL,
    0x8B0F1D7A097D8716ULL,
    0x1788C58D5AB98DD3ULL,
    0xCFD5EB0B44DC1FAAULL,
    0x8B0F1D7A097D8716ULL,
    0xC6D1485D87ADECE2ULL,
    0x18C3584048FD69B7ULL,
    0x25,
    0xD9,
    0x31,
    0xA0,
    0xC4,
    0x67,
    0x97,
    0x69
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseDSalts = {
    {
        {
            0xB4E8A787F71DD42EULL, 0x4920808F94B48D2DULL, 0x132AA85454D35A6DULL, 0x3DA379FE160B96B5ULL, 
            0x6227B9A6DFC7514EULL, 0xFFE1C15C9371AC1DULL, 0x5AB726963C7FD5FAULL, 0xE67F3964A1ED6481ULL, 
            0x0A8E7D729AAA94CAULL, 0xC63FB71CE1227F4BULL, 0x4A4351556769D8F9ULL, 0xA6CECB17C7582989ULL, 
            0x0CA7FAAA9FD01BF9ULL, 0xF51D0CA5038C7B78ULL, 0xBAB5314C804C99B6ULL, 0xDFAE35D1367B058AULL, 
            0xBE53EF8A7DB329DEULL, 0xFF1A07AFE1F75684ULL, 0x87BB77F052A76B4DULL, 0x263E55C9BFF7610EULL, 
            0xD12A5A1C8D597832ULL, 0xE86C9F72ED7876CAULL, 0xE89A622E6B9493F8ULL, 0x0F3779B608CCFACEULL, 
            0x812DDE8E33983D43ULL, 0x4B2182EA7E2206CAULL, 0x33A1C43EA9FBE411ULL, 0x39C85D4633A58ACAULL, 
            0x010D727EACF3567FULL, 0x132D715CE551FC8FULL, 0xDF981A799B3C731EULL, 0xE2D6BAE704E30CF7ULL
        },
        {
            0xAB890A89743A0181ULL, 0xC369522529D7CD3BULL, 0xF890F489EA5F4A96ULL, 0x15A5A3B671363F3CULL, 
            0xC12084F651DAF915ULL, 0x8B05BBBD78CC92A9ULL, 0xB7B4D6D843A44242ULL, 0xFA4EF061A496030EULL, 
            0xC9C08DC1C33373FDULL, 0x38EFC5DD04BDFFD2ULL, 0x3C43DC0BD70F0F55ULL, 0x9A74BEDA7C16DE7EULL, 
            0x7EC3F1EFD313F51EULL, 0xDAC0655CC095015BULL, 0x33A53A363F4E328DULL, 0x9E8DCB1B471909D2ULL, 
            0x5F2245608BFDE065ULL, 0x224864E8F1048098ULL, 0x7C2A401A04CBE589ULL, 0x9FABE8007B5835ECULL, 
            0x520675DA44FE03B7ULL, 0xCB5803FFF9A41720ULL, 0x876C3D415BF9C0EBULL, 0x097CF47C47CC3F52ULL, 
            0x1A5F2ED65CA3575CULL, 0xA2D9B2C563547920ULL, 0x4AB98D293C8C7F4DULL, 0xB512CFDB58408F77ULL, 
            0x21F7FE6FE6D54F8CULL, 0x6396646E85EA99B3ULL, 0x1578F578AA44F9F1ULL, 0xFC55322B851E978AULL
        },
        {
            0xBE42B347909BEDF7ULL, 0xA7C1070F2D0852D3ULL, 0x8A69CB7E93F4569FULL, 0xB75BD50C39011A54ULL, 
            0x1E717F4CF6FC0CA2ULL, 0x550B668592BCFE04ULL, 0x8D81B527F347DE3DULL, 0x7E1A07534071B146ULL, 
            0x93E26FD2BF03C39FULL, 0x0C30EB4DAE60ACBEULL, 0x5A601D63B8F8D06CULL, 0xA0B828A1BE1016B3ULL, 
            0xB42951C6BDB5A653ULL, 0x0241CE6DD9E64549ULL, 0xE0D7E8B8C4806608ULL, 0xCF804F0FD2D07747ULL, 
            0xB1FE24DDC07DCABDULL, 0x578EDB842816E27BULL, 0x43D60D7755445C82ULL, 0x6F18BCAB55DB1207ULL, 
            0x64C22F22E91B561FULL, 0x4CC06881C0EF0A39ULL, 0x153635D4976B6161ULL, 0x79317BD7D448DABFULL, 
            0xE24DC3722F79890BULL, 0xB5D83108E4ECBF11ULL, 0x2CF86C3DC0C5872AULL, 0x20135704B3E13A15ULL, 
            0xAD76548C24BD265AULL, 0x78C1B99B5964444EULL, 0x7D4E2AA7FE5A8850ULL, 0x11E1516BF24C3277ULL
        },
        {
            0x0CDF12C9DF857265ULL, 0x9D6FE128ED043376ULL, 0x5C38BC59758294FEULL, 0xFA8CD6104CA3E858ULL, 
            0xA456447EA0F0F52AULL, 0x8550CF8E89ED90AAULL, 0xA95AB20879FF6F06ULL, 0xF9FA0973C06E4465ULL, 
            0x3CF56136F0B89FFCULL, 0xB379E29973987727ULL, 0xD686B08325919823ULL, 0x22EA7CC41A27A746ULL, 
            0xB69D6AFEECA9D99CULL, 0x21002C3923CAA867ULL, 0x330AF273627A5DA7ULL, 0x8868E9A5B3BF3EB1ULL, 
            0xEF8AA25E2D414FBDULL, 0x6C097E22C2BEFAA0ULL, 0xFC6CE86C45304FB0ULL, 0x0CC74D1FF88E4F6CULL, 
            0xA5E4CC506A0A3167ULL, 0x125222A6E37FBEF2ULL, 0xA1E1E8ADB2187573ULL, 0xD7D989A27EE250F5ULL, 
            0xA90792759CBE32B5ULL, 0x29E5864F233D1605ULL, 0x333CC311AD26F10DULL, 0xDA16866AA1F166A9ULL, 
            0x042D267D4E2CE4FFULL, 0xA9F697B6AD4BF7FEULL, 0x4C589AF7BE967AD5ULL, 0xF09218F7F222505DULL
        },
        {
            0x9055A771501C96BCULL, 0x3512827CDBE3C6C8ULL, 0x813A78E2545D2B19ULL, 0x9AB893D197150F89ULL, 
            0x74B00BC8AA4B1AB1ULL, 0x8BE059F7E72B07B7ULL, 0x07BF2BC3FFDEE6A2ULL, 0xFB9940CE825DED99ULL, 
            0x71011812EF812F4EULL, 0x5B67AFC3FA6BA767ULL, 0x947998AC4066BC7CULL, 0xEAE410378B4AD1D7ULL, 
            0xDC64ED24734CB3D3ULL, 0x010F89A2BBD4F8F8ULL, 0x8D71ABC5265047CDULL, 0x14E689F451EBB521ULL, 
            0x693431A9C46EACBEULL, 0x84CEAC77847BFAE7ULL, 0x5A224B22D1196248ULL, 0x121ACCA6ECB7419BULL, 
            0x61221E3B7259C9F2ULL, 0xB73516D8313C7474ULL, 0x67AD17DAB4105355ULL, 0x9FFAE7A311FE1619ULL, 
            0x1943E35DA41D808CULL, 0xF82F36391025BA90ULL, 0xC37ACEF4BA0813D8ULL, 0xAB22208E95118461ULL, 
            0xA39EFE97ED666159ULL, 0x3F266EFD22809A74ULL, 0x1F6BBEB90CED8866ULL, 0x8737CC39FC653DE1ULL
        },
        {
            0x43876D5ED447A5F3ULL, 0x9B99EDFC518E41B7ULL, 0x8E54846A7A13A4B2ULL, 0xA14DBE0A79B2F2E3ULL, 
            0x553EF53FF3676F24ULL, 0x2FCF03FBA92B3E24ULL, 0xE880A09F56AA14D7ULL, 0x0AF8D7C1BC9B1696ULL, 
            0x4166C561595B7E74ULL, 0x644BE18F6E4F02B5ULL, 0xA5407C986ADD1B29ULL, 0x9186F4C339E008CDULL, 
            0x5A64A6B8A837DF08ULL, 0xA1B8813ECE036DACULL, 0xE8F6E68788A1505FULL, 0x79590DC9E9E5C14AULL, 
            0xD44AF9DA45BEFE4BULL, 0x598C6D7EBE80B206ULL, 0xD57B94806F68CC03ULL, 0x4F2F22DB76D67A66ULL, 
            0x9B276B1BA97343D1ULL, 0xA446296EB0BD1F7BULL, 0x0AB14CA28D0C398DULL, 0x93E51190013E52E7ULL, 
            0xB527DD531492B91BULL, 0x28B68C94B06CA964ULL, 0x331AE1DDFD78E070ULL, 0xF61EA27A8D3EEE27ULL, 
            0x30DE95FC9984C4A9ULL, 0xFBE53CFC02DA9955ULL, 0x0EE3382E59C1F75DULL, 0x1A18163469028CADULL
        }
    },
    {
        {
            0x99A4A12A44AA6D54ULL, 0x4D4E7EC1E7EDA52CULL, 0xECA1D77AFC2AEA58ULL, 0x421F61F27375E0C2ULL, 
            0x55DECFFD13650C0DULL, 0x59DC5FB324028544ULL, 0x45C5588648FEEBADULL, 0x8534A9EE6504CB81ULL, 
            0x277C32057BB8870AULL, 0x62F38BA5BCE97DFDULL, 0xFBA0891DF3D7EFBCULL, 0x884CF0641532B6DCULL, 
            0xDCC5C31AD1A61952ULL, 0x65E469910B8AEEF7ULL, 0x6E9C989C57204A2DULL, 0xBC3D6B2D9AFC50DDULL, 
            0x11A58A657FDCDB1EULL, 0x6564C5ACFA70DE80ULL, 0xA436DF51581DB500ULL, 0x131C7909AFBDEC26ULL, 
            0xB32FCBB592B8170BULL, 0xC74429B0128B7906ULL, 0x3BD4D6C20351187CULL, 0x2CD31DBD0D00D91EULL, 
            0x0FC02ABE27805611ULL, 0x8B6959A76F057984ULL, 0xE81A627EA46A4D77ULL, 0x66163FCC577E3474ULL, 
            0x3E464FF147D4B7DEULL, 0x5789837DDB7B47E4ULL, 0x119CEEF025CB9CB4ULL, 0xD37D9277FCD3E949ULL
        },
        {
            0x4468C16392F59890ULL, 0x23A8307D34D451AFULL, 0x74A07FA831D760EAULL, 0x7E96D1D62D23BB41ULL, 
            0x003BB30E83ACFCA0ULL, 0x5C127DAF1E5A4088ULL, 0xE7108C8F85462E01ULL, 0x129A052FDC72DF10ULL, 
            0xA5D390901B2A2EE9ULL, 0x672F68FD83A15733ULL, 0xD8387121CAC6342DULL, 0x006CC7CDAD0838BDULL, 
            0xC1F7C3A0208D7EA5ULL, 0x6B0742AD1D44D9F2ULL, 0xCC9D09AC9E928C8EULL, 0x21581DE7C25FE1FCULL, 
            0xD715667C99433B9CULL, 0x91B83741EF3C19D3ULL, 0x44425DE127BAF3B0ULL, 0x4C42B21EC01B1C2DULL, 
            0xA92ED8E886CF2DD2ULL, 0x05C1005F7F8F5490ULL, 0x06CF8A71DD6051B6ULL, 0x56CD2243E15A9E18ULL, 
            0x05B297BB9FDF82B8ULL, 0x8343EE5EF3DF8488ULL, 0x900DD4AA10370ED7ULL, 0xF0F530A6F5959DE1ULL, 
            0xCC9986AE8EBFDCFCULL, 0xAF8717930DB6A767ULL, 0x4CE8F9F5C6F98D41ULL, 0xC593D524929F47E8ULL
        },
        {
            0xE560318FC912E149ULL, 0xF97C8D4A002A4535ULL, 0xC7C12901A8E4BCC1ULL, 0x9FBDC1BDE10D3A3BULL, 
            0x089760B1D8C4F678ULL, 0xDE9497941F79618BULL, 0x31FD81914FEA36DEULL, 0x127C3FB8705777D0ULL, 
            0x6F16BACA8A4413C6ULL, 0xE648360E17D09EAAULL, 0x380BAC967478EF65ULL, 0x9B92C512B3C3F503ULL, 
            0x6FC46F30F18D8B40ULL, 0xDE1D6D975C8A35CEULL, 0x3EEEDD57977B451EULL, 0xA8526E775E23542AULL, 
            0x1BEC2CEAF8C9A12AULL, 0x71B2F38D354B9A4EULL, 0xA2115F587810EE15ULL, 0x08B4663D6C552A76ULL, 
            0x504CF2EDF692FEE2ULL, 0xDB43307AF82BFD08ULL, 0x3E65DEF136603441ULL, 0x5E68D22EEB006282ULL, 
            0xA22A1708931B5190ULL, 0x92EB762D51209F7DULL, 0x0BA4EA953DA97DDAULL, 0xE769338E02409C97ULL, 
            0xA0D1D7B74FD2DB27ULL, 0x407D825B9B4BF35CULL, 0xC884E0E0A570DEEFULL, 0x90B11361230CF62DULL
        },
        {
            0x5EB5196D40E8664AULL, 0x4D403F3AFBFCD4C5ULL, 0x8A89040DB427FBA8ULL, 0x4C7405154FE88751ULL, 
            0x6FBFEE585129BEC0ULL, 0x6D56AE6FB2F207E2ULL, 0x80198337114568C4ULL, 0xF6C079956BCF5084ULL, 
            0x197A13A3361CBCBAULL, 0x5A8C5CF696262E4CULL, 0xC10806E6A6C98F75ULL, 0x4139D8ED6D0B4D86ULL, 
            0xD9271339B8717EADULL, 0x72FFF906D86F5D62ULL, 0xF9DAAC1398A275DEULL, 0xE589B803A9DACEA0ULL, 
            0xBB29B630AB8E4BF3ULL, 0x6DCE629D3A751128ULL, 0xDF807DC18F2E4B2DULL, 0x40246C69C24BC54EULL, 
            0x1EFDF02748704716ULL, 0xDD958991D25745FDULL, 0xCFC7CD7B4FBC840BULL, 0x4BC6805D9948F1FCULL, 
            0xA5D39125C8A38407ULL, 0xDB3FB824C02F043BULL, 0x175BAAEE8AFB6E9DULL, 0xAA8ADE6BD7238BC0ULL, 
            0x4E8A4B01F86F28AEULL, 0x571EB2C0F4CA9138ULL, 0xF1DAD48EE4E18E83ULL, 0xA9EA1F98013014ABULL
        },
        {
            0x10BFCA3280813669ULL, 0x7AD6C41156DED6C5ULL, 0x5399379435A525F8ULL, 0xD63875F0F6250212ULL, 
            0xE8F8402BE6C91EA7ULL, 0x4071AD8E001B142EULL, 0x458E467A69D60B4CULL, 0x11948AEF1D8AD50FULL, 
            0xD7A587070AF30354ULL, 0x542CC33CBB6A5427ULL, 0xB3F08A84F5052C64ULL, 0xF2E26F7E6421493AULL, 
            0x6463B19EBB186FE0ULL, 0xD4E4A06210EF6B85ULL, 0x19F58A3FA3DCA73EULL, 0x28A36C24BEE49C4CULL, 
            0xD45426BBF998EB1BULL, 0x4E2252B60065CA33ULL, 0xE4797493EE1AB9CFULL, 0x7AE0CE62A5B87C1BULL, 
            0xF869930C64E02432ULL, 0x2798A9B791E4AA0BULL, 0x4C0DC59569BCD536ULL, 0xDF1D2516B2E87A4CULL, 
            0x596509CB3A7DB151ULL, 0x1099E452C5E540D1ULL, 0x2EE11CD57BD02DF0ULL, 0xD6A7340C96ED5873ULL, 
            0x4DDA79992E7B7903ULL, 0xD28849B402025E5FULL, 0xFB8BF887D27309C5ULL, 0xBDBF0FE7CB37ADC2ULL
        },
        {
            0x4CBE3706B6B03AECULL, 0x03A62996C0879083ULL, 0x10CDABB7244BC26DULL, 0x78DE7018DF6C2A38ULL, 
            0xEA0DB86D9C9835FBULL, 0xDA93BEB5FC9ACCA5ULL, 0x86FED85787250C8AULL, 0x98ED8C06A3026377ULL, 
            0x25937A92A78B2B81ULL, 0xE594A77F44A55618ULL, 0x5FE75ED1470A8F93ULL, 0x36DE0BE78BCFBE12ULL, 
            0x399ED8429310E24AULL, 0xD55CAEBEC74A75C0ULL, 0x04DC6CDE4F58E31DULL, 0xA2F24F837A18EAFDULL, 
            0x6748EE755F6069D6ULL, 0x6DCBF73F1A2E2492ULL, 0x2424E1692A01F99EULL, 0x8CE367C88BE1933AULL, 
            0xB1C3A2D5E28F3839ULL, 0x904EE98FB23C8E6BULL, 0x0E797097CBC101B3ULL, 0xB8E0944FC392793BULL, 
            0x2052F34B62CBBBAEULL, 0x39D7BCA62CC4E302ULL, 0x54E0C3DDE4C73EFFULL, 0xD6447A81744D26EDULL, 
            0x2847ED5581C37F1BULL, 0x21754A1C675F15A6ULL, 0xBEC7F497F0558FEEULL, 0xC734F039944CE513ULL
        }
    },
    {
        {
            0xDEAFD917A61F795FULL, 0x9F6F9D41B01955F4ULL, 0x5BDFDFAF92B599F4ULL, 0xE657553B463E4FFEULL, 
            0xAEBF6A081DC640E5ULL, 0x7688516DEA637F39ULL, 0x22AF5B18C9AA09EDULL, 0x272BB819A309E050ULL, 
            0xF920A8ADA9D9245DULL, 0x56CA107323EF4A84ULL, 0x247F8DB6293B7BB5ULL, 0x569F72689AD25722ULL, 
            0xA028ED2A54104CFEULL, 0xB9B30D2593AD0643ULL, 0xC92F046DD4367865ULL, 0x5957C4B5B5474301ULL, 
            0x2E0DB286D0606334ULL, 0x2728CAA32FC9BE40ULL, 0x392FC396D9A0FAE1ULL, 0xDA8C8AE297305E1FULL, 
            0x7469EEF5FE5CFDF0ULL, 0x2632A75E79583DEEULL, 0x55677B752A1B08ADULL, 0xF6D438A4D21EB64BULL, 
            0x6B389082429BA2F5ULL, 0x4F6371E2FA4B34DEULL, 0x0BC78F67F530CE72ULL, 0x3D838F9BD9C14B24ULL, 
            0x8EC5A4E56451688DULL, 0x30FB89FFB5F5083FULL, 0x7BED966F2D39F129ULL, 0xE518C35F48C13C5DULL
        },
        {
            0xC843ACA4C8D960DAULL, 0x29DBB0737B70D105ULL, 0x0A1ABCD71D860FEBULL, 0x5961230DD745573CULL, 
            0x56ACE51C6AACB1ADULL, 0x5D94DB9C0711E9F0ULL, 0x1673302A0AF3EC70ULL, 0x6032DAAD7F59D053ULL, 
            0x0A2F6852D3478272ULL, 0x76BCCF4B858C4B9DULL, 0x8ADD290ED453CDC4ULL, 0x109A1FB826755DD5ULL, 
            0x81FBFC8128ACA5BDULL, 0x94B1AA350A6B9A24ULL, 0x1863CB0BC8F949E0ULL, 0xE0FA9C5DA53869C9ULL, 
            0x8D04030F460C30CDULL, 0xFF8319F775DF29DBULL, 0x580B60B975641E59ULL, 0x099FD91D5F7D7715ULL, 
            0xEE74B5A23A5BDDD1ULL, 0x60418417E0E5AC3DULL, 0x35B88CD0E8EA248AULL, 0x5D1709EC6E6B867CULL, 
            0x47C96753E435123BULL, 0xDB9B7B8DC292331AULL, 0x53BD3ABD3FA086B4ULL, 0x8A720E7034ACD0BEULL, 
            0x221A6D2C235CD8D7ULL, 0xE0C8C5D87F2B27ADULL, 0x5BE133D6454E3929ULL, 0x03C1689B9EA07466ULL
        },
        {
            0x7BED6FC492E6D99FULL, 0x5343E8BD88967E2FULL, 0xC8FF96A6E07DFD75ULL, 0x47A2252B935888B0ULL, 
            0xF785A46F5804E979ULL, 0x87820C17B84A884FULL, 0x44E4442E59C9E28DULL, 0x84D1A4217A097547ULL, 
            0x4FA2EC6BEAC34919ULL, 0x358BA2293D3F98BFULL, 0xDCAB992BC8CFD9A4ULL, 0x2FF1711F02510334ULL, 
            0x669CB42F68603F72ULL, 0xE9BE0367755C21B2ULL, 0x7F5AA87CDE4E5B8AULL, 0x8504C3F9DD7EA825ULL, 
            0xB82687C1D185ADE6ULL, 0x8CB30A70A2686072ULL, 0x6CFDF696D0207597ULL, 0x7F916396BBB3E6EAULL, 
            0xBBEBA1331FAD606DULL, 0x4861F63AE0789529ULL, 0xBED8B3C86EC4A3FEULL, 0xB25E114E7B6506E3ULL, 
            0x578536E05751A035ULL, 0xC489060998AC4E06ULL, 0x764A1B702FCBC0FCULL, 0x3022C2E88607774CULL, 
            0xFF3BDE31B3246042ULL, 0x345C376B8743DAC3ULL, 0xF6D0D3E69BB830BAULL, 0xEFF54E9B26DD1C2EULL
        },
        {
            0x8AD87F02A964BD27ULL, 0xED212F7C403ACF38ULL, 0x5A60B1FADAECCFB7ULL, 0x2577D1915854CAAEULL, 
            0xDD5557A45746085AULL, 0xCED4991B09700B1CULL, 0xA2B8CFCBF8505ACCULL, 0xAD0241F2D6BD4048ULL, 
            0x68A4AC2E5BA685E5ULL, 0x95C559ADB3F54877ULL, 0x377096864302D053ULL, 0xD453D863CC92D879ULL, 
            0xEF75A767A12F58CAULL, 0x2537B283F711F549ULL, 0x900C8462875D039EULL, 0x9032D32D03636887ULL, 
            0x3EB9067097217E08ULL, 0x79AE9361EBBB21F6ULL, 0x6EAB2F034FCC67BBULL, 0x66DD5118A291DB45ULL, 
            0x93C37DAA024C214EULL, 0xA1BB47A6FEEABD58ULL, 0x1BCBDFEC69FD5B05ULL, 0x9B962B45BA0ED092ULL, 
            0x221E0CC2EC69BE98ULL, 0x1A5490F5734A5BFAULL, 0x3DA3F193A37B3276ULL, 0xB59C5D3D27B8FB59ULL, 
            0x1FB99CB6FD388B19ULL, 0x42B47283EEE1D623ULL, 0xCE66908AE16AC719ULL, 0x19D2D7C6CCB5B633ULL
        },
        {
            0x4CFC43118BEE3C14ULL, 0x405C4BF962CF76F8ULL, 0x8E3D70FD2EF36031ULL, 0x7D7F6E01CE660F2EULL, 
            0x476F0A77EA3566ECULL, 0xD2292D65572A4F48ULL, 0x96CE9B88E835401AULL, 0xCE950F2907C17130ULL, 
            0x4B9B54303A66EB62ULL, 0x8C1C62B7628A0AD2ULL, 0x736E20825ABF648DULL, 0x47ED0EFD5B65C87BULL, 
            0x8C43BFDB56C13EE9ULL, 0xDC4A4CC1BCF6D182ULL, 0xBA6EE7C18C558528ULL, 0xAA09CD8058210DFCULL, 
            0x1B27BFF1D34A27BDULL, 0xC51A7AEFE2AF9C20ULL, 0x2A30B76687A86AD2ULL, 0x465B1A7A8B1F8642ULL, 
            0x7F8AD30DBE6A87CFULL, 0xCD90196AD7B312BBULL, 0x610FB9D41E10A9EDULL, 0xE6635B0A90DB20ECULL, 
            0xA97BC62D179EA13AULL, 0xC1EE5052108AE3A4ULL, 0x8D32B8B50936D899ULL, 0x62D9361F1B95FC30ULL, 
            0x78191A1FB9F91DBDULL, 0x028908A3F6EB189DULL, 0x196957F6E042398CULL, 0x5A7E201E6829E324ULL
        },
        {
            0xB03EB3FD46FEC04EULL, 0xD81B4983BC298D4AULL, 0x6486EE7D707B0C36ULL, 0x450799B55BD29AFAULL, 
            0x8FE87B2462105160ULL, 0xE6809DBC40D321B6ULL, 0xA53D5DE2F76EB8E0ULL, 0xD8D7452D801EC8FAULL, 
            0xB65E519C20C506F2ULL, 0xB71F8B62C200F899ULL, 0x925430829DFE5E6FULL, 0x95199553AC84A9A4ULL, 
            0x0D739640E6424532ULL, 0xC883A2F57961D720ULL, 0xC96068ED8B60BB9EULL, 0x27B3D050D8C210D0ULL, 
            0x59C94ECAA962F19BULL, 0x49B405FFD8A73A04ULL, 0x15EC6B660BBBC06CULL, 0xC3278005741F82F3ULL, 
            0xE2F6D1ECFAAA0315ULL, 0xB37492379DECDC5FULL, 0x9270FC9F701E947BULL, 0xC2E66CAD9DD19582ULL, 
            0xF5E697CBB2A945F5ULL, 0xC89F982764121F41ULL, 0xEFEB189A117936E4ULL, 0xDD786E0999ADB21AULL, 
            0xE368C18CEC8E815CULL, 0xA37B0A089BC67105ULL, 0x8BC72336B940D8A2ULL, 0xDED346C71466A383ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseDConstants = {
    0x7C9F80BC4CE37EC9ULL,
    0x3D1131EEBE2D52ACULL,
    0xDECED6B16D8D73CCULL,
    0x7C9F80BC4CE37EC9ULL,
    0x3D1131EEBE2D52ACULL,
    0xDECED6B16D8D73CCULL,
    0x6A40584B66CA82E1ULL,
    0xA4DD06956B690221ULL,
    0xE9,
    0xF0,
    0xCF,
    0x88,
    0x09,
    0xDA,
    0xA9,
    0x12
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseESalts = {
    {
        {
            0x8B8A94B3664ED7B1ULL, 0x3BB0A5803DD3761CULL, 0xFE453D28F95B1E23ULL, 0x947EA18DE166DE8BULL, 
            0x6C72BEBC253E9DB6ULL, 0x752F59E0B015A203ULL, 0x2F9AF6754360D8BEULL, 0x1301E68595637D23ULL, 
            0x623592AFAF849BF2ULL, 0xBFBE892B00491AE2ULL, 0xE1C03B4E6598A196ULL, 0x0B948DD219FFB58DULL, 
            0x3322315CD74B8079ULL, 0x8A5EF22ACC810A93ULL, 0x8DF2D807A56EC29CULL, 0xA2526E3C47802F1BULL, 
            0x925181B30ECDDE37ULL, 0x6D7C958A323B463BULL, 0xF892866B5CB22948ULL, 0x2237A6F2AB2BCF6EULL, 
            0xB8457CE8610AB626ULL, 0x9C9377D78B61BFBAULL, 0x0A7C6D5D56F81AE1ULL, 0x4CB6669AE9824864ULL, 
            0x33F0BADB073F322BULL, 0x5C507BA0DEB76805ULL, 0xF365D4072B825039ULL, 0x50261A4827ED79D3ULL, 
            0x9988EF1CF7D3E88EULL, 0x329DE47B267D5886ULL, 0x8EEDEB67D9E3C6E4ULL, 0xBD01A02FABD4385AULL
        },
        {
            0xAC922BD9D6C22FABULL, 0x7A04D7110CE1F5FBULL, 0x3E7A39D810DC4B5CULL, 0x27B49585A55E14D9ULL, 
            0xF9C4429805A9B056ULL, 0x40C8A221A892D697ULL, 0x02052276FC5C892BULL, 0x9E074FA133D9A5F1ULL, 
            0x41B79EA9301640CBULL, 0x9FBD5C36C61BCCC4ULL, 0xC26045B5132FDCBDULL, 0x455E0572A137BF0CULL, 
            0xB37016E97B59C9A7ULL, 0x4281A1A627603EA8ULL, 0xD738F230926E8D12ULL, 0x1A9792C75AA872B9ULL, 
            0x9FF35CBF4C59CFF8ULL, 0xAAEA895759F47105ULL, 0xD0C2ED438C9B60CAULL, 0x39804DE7AFCC90AFULL, 
            0x403A32918935079CULL, 0xBF7CB2654D8F98A6ULL, 0x671F49457961CF8BULL, 0x67151A3CBF6899EEULL, 
            0x70402D98D32BF1ACULL, 0xCA5F3382CDF33AC7ULL, 0xABC29E8EBE7E0DE9ULL, 0x0C0FF66ABB21067EULL, 
            0x24E89084DC625F0FULL, 0x559F05C16ED3CD64ULL, 0x6474215839ED477AULL, 0x3E0893C0DE5AD9DFULL
        },
        {
            0x26605F37CBD52AB8ULL, 0x7DB2B0B0BEF596FEULL, 0x3DDDAE35F4D15B83ULL, 0x00985591991267F3ULL, 
            0x16345B0267F84DE3ULL, 0xB4CD191B2ABE1EE3ULL, 0x70159AB403F0222BULL, 0x31D1F019B77174D8ULL, 
            0x53766075CCAE0920ULL, 0xC816B1772375BFEBULL, 0x8A43B96621C2554BULL, 0xC377C5E6CE2F9EDCULL, 
            0x420E931D7C83BF15ULL, 0x487B0CF399EFDC07ULL, 0x9FC2DF0F6106A26EULL, 0x79DBFAC04ACDF9B7ULL, 
            0x030D408FACD7DC36ULL, 0x841E661D47A4748DULL, 0xD939FBB5155BA763ULL, 0x1A4B74E6DFF9EB10ULL, 
            0x785B505780BA2035ULL, 0x73A35BD8518E3130ULL, 0xACBDC43F8F429209ULL, 0x08D238256DEA4D0CULL, 
            0xC5E90553F8CDE47EULL, 0x2310B69B53897BFBULL, 0xC563235263863512ULL, 0x5D6FFEF2591118C1ULL, 
            0xCD3879105895C96EULL, 0xE5F4C3C4A201C230ULL, 0x76D96ACA2A500E69ULL, 0xF443338EF0917985ULL
        },
        {
            0xF9FB22EF08AE29B8ULL, 0xAF3F885961DDACDDULL, 0xD4C77829F17620BFULL, 0x7AE4A1282E5FDE77ULL, 
            0xA06FBC3022BCF9F4ULL, 0x275E536B99E27694ULL, 0x857E0F28B0EFFC2AULL, 0x0E8D9DAFA99CAF3AULL, 
            0x2BD9EA1B4A5D20D2ULL, 0xF1F554215E3BD41CULL, 0x2F1830FCD15D21A5ULL, 0x463EEF89685C3A43ULL, 
            0x7A2A462BB7096833ULL, 0x99F2506B1376A781ULL, 0x0111E19D45512CA3ULL, 0x96C302B9EDEFFF5BULL, 
            0x7459C9F4E5733CB0ULL, 0xF60FB23B870DABFFULL, 0xE74C22F7BAEA2654ULL, 0xB71E184F60021CEBULL, 
            0x7FD2FD861214AC8DULL, 0xA1200C157E2DCEEDULL, 0x0E00B09B29F1C5D2ULL, 0xDED9A539DAFF2E08ULL, 
            0x619EFEADD5F5AFD8ULL, 0xF8DB09B5D1F0CC41ULL, 0x066FDA500E73CF13ULL, 0x60FEE175A6174907ULL, 
            0xB1ACD8B9375D1A64ULL, 0x328376679FCA4433ULL, 0xEC8B4123061101A8ULL, 0x5B3E0A64AEF37BA9ULL
        },
        {
            0x124E7CD7154630FDULL, 0xA8DF739536126B27ULL, 0x9C66B7511B2C7646ULL, 0xD31A30CE35265FDDULL, 
            0xF30D4FCDACCC947CULL, 0x3C1C1D2BF0766790ULL, 0x81D33EB73479AA7AULL, 0xD5BD0CFAFC359677ULL, 
            0xC36876602E88AE3EULL, 0x1EBFFA0992E93BDEULL, 0x0584F5689BE179F3ULL, 0x26D7223BCF8A5498ULL, 
            0x2233B6B43B70A40EULL, 0x249E9B280EBCCD4AULL, 0x78AC8DD94B302136ULL, 0xF73B744F65CBAAACULL, 
            0xD903EF57E9E3CA6CULL, 0x97E12FD56591473BULL, 0xD225AF6CB89888EBULL, 0x94289749392030B5ULL, 
            0x0362A6FC1B72CA6AULL, 0x4C5A842903ED0B3CULL, 0x8625D7DFD7C3DD2EULL, 0x4E666A14431AFBAEULL, 
            0x464ED317D776322DULL, 0x86144C2DBE592499ULL, 0x42E0C91D48A3CAC9ULL, 0x5F8AC51963938C44ULL, 
            0xAC160D94AC3DD901ULL, 0x6A627C6AC997573EULL, 0x0D99B08F376AD20FULL, 0x86DFFFB3B96C1D51ULL
        },
        {
            0xB3FAD1D29C720578ULL, 0x18874E9486C1909DULL, 0x67C54131E6578FE8ULL, 0x1F5E65BFA4B14FE4ULL, 
            0x9543891F7573DBAEULL, 0x62E5EA9D98090247ULL, 0x8FBCBABD07CB886CULL, 0xF5381D925F024FD1ULL, 
            0x72F09CFCE3069BC6ULL, 0x4B3A961BB70A2525ULL, 0xE3AE82451BD5B212ULL, 0x63A474F1A03CAFB8ULL, 
            0x7C504A45413D4DFDULL, 0xCC622F12147803A5ULL, 0x789F355C4C3CEEA3ULL, 0x8DA1AB345350E753ULL, 
            0x6FB900A2342BBC13ULL, 0x371DE00AB916EF70ULL, 0xBEB4421CD7C18ED4ULL, 0xB076CDA2EE9D635AULL, 
            0xC596B3750432AF9EULL, 0x6A95988339FF0DDCULL, 0x86FA369519450C8FULL, 0xD8F17E8D4FF2C30AULL, 
            0xAAEFB2D79C604451ULL, 0xA3DBEE9C2C474E18ULL, 0x8518B593E640C658ULL, 0xEA10D7C7ED7AB5D4ULL, 
            0xBC1C7E075A56330EULL, 0xA7A5EAEF12BDAF68ULL, 0x2FF5F1A93A6195E3ULL, 0xC042C5E70064C1CCULL
        }
    },
    {
        {
            0xB453DE4DFD1B7371ULL, 0x12549D85F2BF933FULL, 0x9151C115FF1197EBULL, 0x80CFBF2B348B78D4ULL, 
            0x05A1D4D46AB58988ULL, 0x54514ECD9D342316ULL, 0x9DA661B16F8C0E19ULL, 0xDAD998F7DD49AFF0ULL, 
            0x53B555C44DDE6A5AULL, 0x05CD18E744B65B73ULL, 0x5E56EF5DF00A3190ULL, 0xFCCD7133498CA798ULL, 
            0xC4DB563D73A76EC6ULL, 0x1109FEC5DB5A2C87ULL, 0x7EF7FF324481FA0AULL, 0xA947FCC15CA90B2AULL, 
            0xF9B87AD6F739BEB3ULL, 0x2E3559951D6F72B8ULL, 0x70750D3C08BF8DF2ULL, 0xCD4C1CC27B2C2C70ULL, 
            0x5DFB8944FEEE6C29ULL, 0xE73F5F0B43FACF6BULL, 0xAE4ACBBD6563CAF7ULL, 0x1630D36EB98FA3C6ULL, 
            0x79368F53BC8E30EEULL, 0x2299889E479B543FULL, 0xCD74672346C7C6FAULL, 0xB7A23E14C773BF51ULL, 
            0x750F081FC46F582CULL, 0x900BF02FF7BD1237ULL, 0xAC6881FDDD760354ULL, 0x597851A0BDA03137ULL
        },
        {
            0xEC0D3A170265C4E4ULL, 0xD655FDE555996EFCULL, 0x33AA0E582934CA93ULL, 0x359A96D394CAC1D2ULL, 
            0x1512D8BCF8A6253BULL, 0x61D1D1B361C8A696ULL, 0x29617BB241EEB8D4ULL, 0xEC681F081DCF4FE1ULL, 
            0xE8EBD98137892701ULL, 0x27C7674F96B30620ULL, 0x2E0A43A3BB267ECAULL, 0xA7A7CAEA4E9B6E98ULL, 
            0xCACDC0B11136C922ULL, 0x694C7FE59E13CBCAULL, 0xF151295B876D7506ULL, 0xB4DA1ECB1672A43CULL, 
            0xCEC6C77FCE582FDDULL, 0x5B670B3261125574ULL, 0x8C8C69976DC8BD09ULL, 0xCF3D4C7195B838FBULL, 
            0x302ABF64F112FE8CULL, 0x7F274E30ECAAC79BULL, 0x7969C11CBB07AED6ULL, 0x535956FF4674E866ULL, 
            0xB3B6EDC1CA584351ULL, 0xA0F32BBA8A1A4B1AULL, 0xAEC541EF6C37FAD9ULL, 0xF8EDBC298ED07C15ULL, 
            0x5584B10652F32ABCULL, 0x6BC53BA131D8D0E7ULL, 0x86B9C09F030B7137ULL, 0x543DC9ED55F28468ULL
        },
        {
            0x29FE53B1A1F3E834ULL, 0x0FF8FE93545F5980ULL, 0x36137E29B0F922D6ULL, 0x58FCA3F0AA36353CULL, 
            0x1DA0268A8068AEC3ULL, 0x1C082F5B916B0DEDULL, 0x105EAE4004DC37A9ULL, 0xF0B14D1BC2E605AFULL, 
            0xCE2B61417E99812BULL, 0x3D80E55088E13A8AULL, 0xEDEDD937F26DC1F5ULL, 0xE77CA337CB5796F3ULL, 
            0xE879569A8E3B64F2ULL, 0x13D03FDF890D2A09ULL, 0x6DC7EEC5F484D45EULL, 0x3677E6BB651564C2ULL, 
            0xCC7E6BD26DADC254ULL, 0x390C163B34A3F213ULL, 0x1A6AEB1558191D83ULL, 0xFE2253B5DD209ED3ULL, 
            0xA5AC7DABBB5003E1ULL, 0x6CE1F73470CD4421ULL, 0x34A69472E42D1916ULL, 0xF8AF9CA53139577DULL, 
            0xBFCA19A6504F739EULL, 0x882BD5A5901139F1ULL, 0x9A94F330AF5BCFCBULL, 0x0F264174DEE933CBULL, 
            0xEDB61819A915CD90ULL, 0x4ED22C287EC5097EULL, 0xAB8C05BB9867E510ULL, 0x318B2E407F91B189ULL
        },
        {
            0x3EC7C782517FD9E1ULL, 0xE05C5C8212BC55A9ULL, 0x973C2809E42129EDULL, 0x7CF97FD8A48B76B4ULL, 
            0xC68E302226924F56ULL, 0xC579E23533AB21B0ULL, 0x8438278C28148FFBULL, 0x7590AF6F644A759DULL, 
            0x5905D5047B9255D9ULL, 0x049738498D9728CFULL, 0xBF4DDE02A547BB03ULL, 0x8DB6AD7A34AAFB2CULL, 
            0xE46ED9B8CD20A77AULL, 0xF65C44C412B467BDULL, 0x59E384BBDF521D31ULL, 0xFF1D4D69DDAB5A88ULL, 
            0x57335935091BEC61ULL, 0xC920E108A030DC60ULL, 0x0D619D622D778943ULL, 0xA8F550907E4784F2ULL, 
            0x24677A58DE530EE1ULL, 0xA65CA4F61683B8B9ULL, 0x52CB1BCD68B3FC21ULL, 0x3087EC4661E7299DULL, 
            0xDFDC1603664D55ADULL, 0xBED4B85DCBC68071ULL, 0x7F7156D35A25F094ULL, 0x81A4C70C1D42A11EULL, 
            0x3FE8141A5777E1D8ULL, 0xF83D26557DAD74B7ULL, 0x21624B57F2FF8D89ULL, 0xC399E649CACDA083ULL
        },
        {
            0x52B6E98E05FB559FULL, 0xE5D55F42B8438FB5ULL, 0x0F39F588B966F3F1ULL, 0xF402C6856E2CB039ULL, 
            0x07BC2F23A6AE218BULL, 0xA7E66506BDAC0ED4ULL, 0x52E8CD88AAD425ABULL, 0x7389FADF46F8BD03ULL, 
            0x1FABF6D617D23E88ULL, 0x63C958BE4E0F8A21ULL, 0x466B592B651952A8ULL, 0x9BE231E78A631258ULL, 
            0xC564301B23EDC3B8ULL, 0xEE7A1F67EF099718ULL, 0xA366191EFFD9C29EULL, 0x0186C0A9677DCB3FULL, 
            0xB6B58D30BC6935ADULL, 0xF211BADF6341A250ULL, 0xEEAB9C9C800C2BC6ULL, 0x113687DA84DFA483ULL, 
            0xE0A43F87A6E135D4ULL, 0xBBC6CB75CE8DCEF7ULL, 0x27A37E7745BA79ADULL, 0xAAD81AF8EE707566ULL, 
            0xAF1BCF2ABF1095D8ULL, 0x605789C0CC7C36A6ULL, 0xA351FED171A7DA5BULL, 0x210516343AF5755CULL, 
            0x8A1F15213AB81394ULL, 0x9865FD0A8ED5865EULL, 0xAFF5D5C37D586140ULL, 0xB27770ADC50A077FULL
        },
        {
            0x18B90B15726AD152ULL, 0x683642062F081FCCULL, 0x4F7BCDDE9F78247DULL, 0xC58A82724446D8C0ULL, 
            0xCA0ECC74D0AFCE59ULL, 0x270B2DC188BCF9A8ULL, 0x59441DD6437DD421ULL, 0x1CADDD054FA86895ULL, 
            0x89EEFE4327575CCBULL, 0x95983EC7CDED8D14ULL, 0x5A1F97EED896675EULL, 0x43F8708A4E499550ULL, 
            0x1980E381E483CBC3ULL, 0xCC02F510DB31E657ULL, 0x08BD069DF8C4B60EULL, 0xE8B3649F9EECA150ULL, 
            0x5E6E5204601E28CFULL, 0xAB67B191DB664EFAULL, 0xDDBDB830CE69EC1EULL, 0x5924AEB6BCD4A71BULL, 
            0x0C40F033B1944856ULL, 0x5CDC08B5AF45D0ADULL, 0xDF1EE4FF5E4254E3ULL, 0xB5E761BDD23BED7AULL, 
            0x6E144A556EDDB3ADULL, 0xF5C5FBA3E5B35981ULL, 0xB0073F51BD6F11C7ULL, 0x64429A13EF27EB27ULL, 
            0x1F3CB8CBF2511E46ULL, 0x42AEFC8FB1E85BECULL, 0x523132F2A69798CEULL, 0x6AEA4969644BCF7DULL
        }
    },
    {
        {
            0x47CF80A4FA2BE88FULL, 0xD589BB8331984D29ULL, 0x1802C452F7CAE91FULL, 0x75E54D8EED03E359ULL, 
            0x6C33AD98FD0A99C6ULL, 0x06CA971B57AD9EFBULL, 0x320C93C14A3ECB36ULL, 0x39C89335448EDF10ULL, 
            0x353C2F7B4D5443CFULL, 0xE07B1F0B3E636784ULL, 0x9BE92FFC2C677995ULL, 0x714CA910E51678D0ULL, 
            0x209A150708074963ULL, 0xF89E8B5DD45EEC56ULL, 0x544DCB28A7368932ULL, 0x68E4D65E4C5D9DD3ULL, 
            0xD52F34B6F8675E7AULL, 0xB0163802EF0A72FFULL, 0xBE511B6B3C4AC3DDULL, 0x712BF73F933EDB1AULL, 
            0xF2551BE2F756DAFAULL, 0x870B7201A8D086C4ULL, 0xBFFCC77EC7A392ADULL, 0x1316BC446E577B80ULL, 
            0xB0E435EC67096365ULL, 0x723EE7C4E299A274ULL, 0xBBE56648728754FCULL, 0x6575BDD5E4E70A03ULL, 
            0x0B98661C286A199FULL, 0xEC4741F384F9F71EULL, 0x020C5E6F806C70BAULL, 0x427E34181062C9E8ULL
        },
        {
            0xF2F9531CC98CA194ULL, 0x4CE1EAEAD5205B0AULL, 0x76B844B81496A125ULL, 0x719092D8DBD9C85CULL, 
            0xF455C673EF495244ULL, 0x615B6CF290E53C6AULL, 0x70F3C2EDEDD5A8AAULL, 0xA11F1927C9FE827EULL, 
            0x9D5AB410A901B9E4ULL, 0xFCBDC6DB35E8E86DULL, 0x643224733572AB10ULL, 0xCA8993A1E729A024ULL, 
            0x65499255E93DA5ECULL, 0x146DA90C7B4FD2DAULL, 0x201BBF8D748DBCEFULL, 0xDC4D8503444DFBBAULL, 
            0x5507D470684E3176ULL, 0x1FBC9EFF75483B96ULL, 0xD2B0335C3923A21CULL, 0xC273C28140A0BBCEULL, 
            0x204B1C27A25DC008ULL, 0x80300E0C1F78758CULL, 0x0019EE3456F35685ULL, 0x81A7B1DC0B4D22BEULL, 
            0x54E86FC32179D9C8ULL, 0x0BE217D465AC0036ULL, 0xD2160EC2EEEEDBAAULL, 0x92686DC6E3B6B48FULL, 
            0x8C9D4A978A2E2B33ULL, 0xF3CB04ACCC3B9F01ULL, 0x6B55689B7FCCC4E4ULL, 0xC4E96B08B3F83775ULL
        },
        {
            0xC65E2EA2A21580D0ULL, 0xD0D9A64EF4BAF850ULL, 0xBB8D63FDCF11C973ULL, 0x3A72C17CAF60AA19ULL, 
            0x7297A3CC270F04B9ULL, 0x143CA47812C8D047ULL, 0xC070662ADB4193A6ULL, 0xBA99CB7980A1AB0FULL, 
            0x012E8557B3FAB860ULL, 0x3598D7B519559B62ULL, 0x1673EBC4097C9CD6ULL, 0xC020615E5D24F221ULL, 
            0x7323972CDB3F83C7ULL, 0x97A418D0AC76210FULL, 0x7E05C6EC67A22024ULL, 0xB19EBFBCBFBBF516ULL, 
            0xF79EBEDE5C06E07CULL, 0xD621BA8E22F70D28ULL, 0xBAFB59FE1A767008ULL, 0xE8DE73C66178ED87ULL, 
            0xBE2072266827BE11ULL, 0x98D7B09052D1E745ULL, 0x68B66AE5B63B883FULL, 0x7C418B5CFBDE7320ULL, 
            0x094446FCAE143C9DULL, 0x544CF1AFE33A6769ULL, 0x508D08D92F89606BULL, 0x5C1B1D7521C1345BULL, 
            0x21B737F2211B0BC6ULL, 0x73F9A2FC5EDD76EEULL, 0xEBEF06605B229B41ULL, 0x500138108538EEB3ULL
        },
        {
            0x249EA8F53622B2A4ULL, 0x402F57F531EDEB47ULL, 0xC7D08D955A80B459ULL, 0x13D2AD44C04330BEULL, 
            0x3F72DD543D4C0B9BULL, 0x8CE52DDD3234B61FULL, 0x94BF9C4874885C17ULL, 0xBEE9A029E6304A33ULL, 
            0x840CD7435B5415B8ULL, 0x1D66AF7455251BCAULL, 0x6B17F22DEE918A76ULL, 0x59A2D51CFCFF2162ULL, 
            0x88A9790EC1190A0CULL, 0xD41A49C75159795FULL, 0x6F99BE7A5162C5EEULL, 0xDB55BF8D0D70CCB2ULL, 
            0x081EC196584EE109ULL, 0x48DD929BBFAF64A0ULL, 0xAB9EA48569650764ULL, 0xC48213BD87438E62ULL, 
            0x7CDD53409BAFF5E8ULL, 0x15CDC3399B3DBCC2ULL, 0x0E1931D7E52E474AULL, 0x47547DBF1B7D81E5ULL, 
            0x99EAEF8B7B9628CCULL, 0x51DB0C8E6A6E8B8BULL, 0xA23F581CD9C893FEULL, 0xA010CB3A152A613EULL, 
            0x3D257621A96AA267ULL, 0x71C87C209CF2AC16ULL, 0x9406604DE83B9890ULL, 0x6942729891C4CAB6ULL
        },
        {
            0x1B4A135E9A45EE5BULL, 0xF5F4AE6C63E5C88DULL, 0x0C6DBD6717FCAFF6ULL, 0xA48A941B349E5F4AULL, 
            0xF6A3E00414ACF741ULL, 0xA96593C49F45EF23ULL, 0x3800005F54703C2CULL, 0xBBA0CD788EE9A313ULL, 
            0x6CDC63F66414ADC0ULL, 0xF4DF83E3F24588D4ULL, 0xE58ABB85AE25978CULL, 0xE2886902DCEB1365ULL, 
            0x74B4C7BD4E9C565DULL, 0xB0048942B3FACFE6ULL, 0xB833ABCE42D41C7BULL, 0xC0C1E6B83FD88E43ULL, 
            0x2BF0BD6A449E42DEULL, 0x1939FDA984D545C5ULL, 0x23542BC3D5076778ULL, 0xC083FEFDC621A4A3ULL, 
            0x55C6FA18EC0CDE7AULL, 0x72C0F49E6A4C98EBULL, 0x8B0D4A2496E3D931ULL, 0x161161F034D8D9A4ULL, 
            0x85EC16A9AB934451ULL, 0xA5CE6D9A955045EEULL, 0x730EC2E31EE9E327ULL, 0x5FEBC2D0DD7FE44BULL, 
            0x0A10E9B0346FE2A0ULL, 0x69D8F581DB9316A3ULL, 0x38461CEBD547D0DBULL, 0xDFBAA3C733CB33CDULL
        },
        {
            0x5B6CD0B64F47D183ULL, 0xF78CCAEBE52999B0ULL, 0xDEA7FA78D3BB53C0ULL, 0x44852C4EBA63CB3BULL, 
            0x36A1A441A6DD7E9CULL, 0xC65081D343C651A9ULL, 0x1B8FEA5FF7B374AFULL, 0x838D92A16BB19C7FULL, 
            0x20547A9728B236A2ULL, 0xF1776385F67FAEA9ULL, 0xC3746C170EDE19AEULL, 0xCEBC605B1DE5A5AFULL, 
            0xF42C1064CBB05249ULL, 0x258FB166DBF1C036ULL, 0xA7D1BD4E8C929EAFULL, 0x65C28CC6BDE8EE5DULL, 
            0xF7D6DA60BB6BA707ULL, 0x435914453CB6A185ULL, 0x55DBB813B7131430ULL, 0xF19A67396B6B9851ULL, 
            0x327E2AD5358F5924ULL, 0xA3F17FD3786DACA0ULL, 0xEA46BF4055937D96ULL, 0x8226A56D7F5ABABFULL, 
            0xDAB676C1C60057EFULL, 0xA5CF349E5419A6FBULL, 0x8BA3DC8BE29562CFULL, 0x0F454CEC8DB714FFULL, 
            0xF22C95F3F2EF8C45ULL, 0xE10A3169975BCE75ULL, 0x1C7205AE1AC91109ULL, 0x3F67643D021C7795ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseEConstants = {
    0x42FC6E0676330AAFULL,
    0x3728B9BC4B537AEEULL,
    0xB063132D25615763ULL,
    0x42FC6E0676330AAFULL,
    0x3728B9BC4B537AEEULL,
    0xB063132D25615763ULL,
    0xC2C1F4C42346FEA6ULL,
    0x5E6D02765A051EA8ULL,
    0xDE,
    0x50,
    0xE9,
    0x2B,
    0x55,
    0x12,
    0x24,
    0xBB
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseFSalts = {
    {
        {
            0xD8DAC715064696A3ULL, 0x95C4B239B74954EAULL, 0xCD2C66C815F61037ULL, 0x8E6F8DC917241CC0ULL, 
            0x7588FD9F833BC247ULL, 0x1D4794A3CEEF407BULL, 0xCF677791842BF0AEULL, 0x417252239F7F1151ULL, 
            0x76F44EE5F430EFA9ULL, 0x85DECC09067B8336ULL, 0x9FE5DEB4177E3725ULL, 0x3361B5618B473248ULL, 
            0xF2920D62570EB063ULL, 0x3BBF584E41062C28ULL, 0xF1878FAC66BD0721ULL, 0x3E0A1F6A16C52684ULL, 
            0x19F3ABB3D45BC5DDULL, 0x0F0038060BD38D6BULL, 0x10AE9D5B5D892EDAULL, 0xD3A3373643D9A7A7ULL, 
            0x5DA318831870A809ULL, 0xB67B1CC7E5C14F42ULL, 0x9B2CEAAA7D09833CULL, 0x466B867725469BF9ULL, 
            0xDAD5168972C1C8C1ULL, 0x46D579838B55E9D0ULL, 0x32007CCF9A568590ULL, 0x9798375C4CD53768ULL, 
            0xBE8EB47EFA9C66B3ULL, 0x5A926E2A16BB542DULL, 0xB390814AE9004D74ULL, 0xC8CCC87C4FDDA4CCULL
        },
        {
            0xDD4307AD3A5CC953ULL, 0xA7612042AE572358ULL, 0xF4E9F6037530D3CEULL, 0x6F141B265E7BF34EULL, 
            0xC0DE2B7237584B44ULL, 0x1B7CB710E3CD9329ULL, 0xB6E035771ED729C9ULL, 0xD67DA6707B330D9EULL, 
            0x1AC205426FBB5690ULL, 0xCADB3DB4393DCC4AULL, 0x75F1E2CAF3BE6E25ULL, 0x8F123915CFAE6200ULL, 
            0x08C3610EE2A77A57ULL, 0x9001F03689C31C04ULL, 0x11DE108AE1E605D3ULL, 0x40DD91C3A10FC12BULL, 
            0xD8539F63F60DF288ULL, 0x72DE59CC4C2666AFULL, 0x89279A68F981E1FFULL, 0x7CFCC430E1DBA037ULL, 
            0xAB7EEA33C096166CULL, 0xF839BCDAB3B61933ULL, 0xB68D8C4710D8E6E3ULL, 0xD996240D564EFF62ULL, 
            0x21E9CDB57A639DEAULL, 0x652AD87A92779AF7ULL, 0x575CDFC36E2BB7A1ULL, 0x3D5F4C5D8F5999E2ULL, 
            0x2E108D60573E5EF1ULL, 0x9B5DE0C297E6FCE6ULL, 0x78E921CF86B69F7CULL, 0x135CFACC2501C200ULL
        },
        {
            0xF7BFE5D5FBAAA981ULL, 0x1F70A50412A4C403ULL, 0xBD5E2743242F8938ULL, 0x08BA31F0689B69F4ULL, 
            0xE6227D555FF5C68CULL, 0xF51BDB56BCAC518AULL, 0x71F03D52F0D0D133ULL, 0xDEE44C6DBE18F832ULL, 
            0x85DF49997E9F6D38ULL, 0x57EB4DB6E9070630ULL, 0xDE1E41369E277DD8ULL, 0x6588DB9207E0DC9FULL, 
            0xEDA307BA6CD71E6EULL, 0x508851A5E087AD80ULL, 0x4BE223C3234BEBCEULL, 0xC14A2437212D2E83ULL, 
            0x38543A436AD8630DULL, 0x62434BBF8C159CBEULL, 0xF3F83F18D8A4AAECULL, 0x16D129D060D9A52FULL, 
            0xFEA64D7086926980ULL, 0x462946E4DB8E57E8ULL, 0xC1FAB7034E0C342BULL, 0x102C34D988FC3008ULL, 
            0xAD71C0A0626E94F4ULL, 0x34F850D65794C73DULL, 0x79CA3131AE46AEDCULL, 0xB9D6614AE3109AADULL, 
            0xD0D480EB8930C262ULL, 0x9DC3EC373E8ADCA0ULL, 0x6AA2B61137801FB0ULL, 0x2521471AD4D9B7A0ULL
        },
        {
            0xCFFAE52A4EC38B09ULL, 0x1FA45CDC64F9BE53ULL, 0x8A59799854A1CB91ULL, 0x24484833CB6FBDEDULL, 
            0xAD72A267935DEA0AULL, 0xCE9B43063CF03A42ULL, 0xCF982626D4D237A9ULL, 0xB4C55A13C9B701DFULL, 
            0x5045A59074AEBDB8ULL, 0xFB7B3382E4A43A17ULL, 0xCA21E72E6FEDD7FEULL, 0x904D00D3D5546EFBULL, 
            0x821258066A783CB5ULL, 0xE8AE68646A4DEFB6ULL, 0x52F8DA12DC6676F2ULL, 0x64A032C8B8DF6123ULL, 
            0x6D8BA1B8C476BB6CULL, 0x1E751CB4E6D5C3F9ULL, 0x6AA6D4F7DDD048D6ULL, 0x7DA24A39FB96AF55ULL, 
            0x6596AF5151131F3AULL, 0xB54BCF87DDD5C333ULL, 0x2E6533D7B6144065ULL, 0x521F6CF03FFEF4B0ULL, 
            0x279BB3C2A6D7D9C9ULL, 0x720EF6ED6799D54BULL, 0xBE77159CA3CADCFCULL, 0x8621D18DAA8CCDBDULL, 
            0x7669FE29BF7C2BD8ULL, 0x5C5A2E76850858B3ULL, 0xBC19D8B5C11B9243ULL, 0x510A0F4DFAB15136ULL
        },
        {
            0x28AE786AAEE939BEULL, 0xDD4E9700F33C0081ULL, 0x0011445D0531369EULL, 0x877A73C3C2D5B9B7ULL, 
            0x2D3A495B034AC0BFULL, 0xD03B2A1BA035F128ULL, 0x7DB6CE5FDC80E5F8ULL, 0x1AD184726397CC2EULL, 
            0xD8ACBE85B277F967ULL, 0xC16ED7E2FE67E617ULL, 0xA8EF1EA66BFCF77CULL, 0x8F827F6C563D36C7ULL, 
            0x4E78F8319D68EB3EULL, 0x75F49D0A46B09F28ULL, 0x4631BC506E0137F4ULL, 0x07E64327008A046DULL, 
            0x73F5EC97652E5B77ULL, 0xBCF3CE417AC57AE5ULL, 0x48EBF7BAF95C8C2CULL, 0xD190729CFA02BB49ULL, 
            0x98F62ABAB7651893ULL, 0x57B1CE8EBF10C6E1ULL, 0x1982B28C302E41C3ULL, 0xDD33497526CC67CDULL, 
            0x51ABAB9E504D37D5ULL, 0xE1452584C5AF6392ULL, 0x69BA626C5D3F90ADULL, 0xA18A6B57DBB6CF07ULL, 
            0xEAA17CFBDBF2715AULL, 0x65A0255CA3526A81ULL, 0xFE6F8268FE616BC7ULL, 0x4C97640937042B39ULL
        },
        {
            0x08482919F10063D4ULL, 0x2FF378357871F9BBULL, 0x442D8B0C2ABD38ABULL, 0x88750B93AA6E6FDFULL, 
            0xE9F2189DF5F4BB7BULL, 0x8B3FE90B2636B65CULL, 0xA91C43B4C4C6ED2CULL, 0x127208EFCB2AF72EULL, 
            0x770DCDBC1611B56FULL, 0x785130820EC03D8CULL, 0x95264B3ADF951D0BULL, 0x48A837D5039BD178ULL, 
            0x6C9F4A1739ED7E83ULL, 0x78CF67B619BDD847ULL, 0x9C71BE11C58E5109ULL, 0xBD8E8CA7B6E5CD13ULL, 
            0x0C3C1EA15D42A748ULL, 0xC2832EA9F0940417ULL, 0x72BF674E4596533AULL, 0xF87D49968E9A8F7CULL, 
            0xB1DAC221FEA3AFA4ULL, 0xE4A7F9B22B3951A6ULL, 0x5C794AD1D5AB42DEULL, 0x4DBE82EC18E9EF26ULL, 
            0x1BC91218C0D2B2A5ULL, 0x906C7A57E670AE9EULL, 0x5A7B627F7B334E27ULL, 0xCACD64899F1BECF9ULL, 
            0xC34E48EA6DB44A8FULL, 0x6327E64A393A56AFULL, 0x21D2689843D13BE4ULL, 0xEBCE7B5904A005A2ULL
        }
    },
    {
        {
            0xA87E965F86C25EE3ULL, 0x1AD9A6896EB2F78CULL, 0x690FD444D5ACDFACULL, 0xB857E53E118457FEULL, 
            0xCB7CA2C6977927DEULL, 0x3A35D8BE8E356777ULL, 0x1E68631745E7C3D8ULL, 0x507F3399AFA25024ULL, 
            0xA4F23E462F6068BBULL, 0x07A33BEF32928081ULL, 0x9E31A35CDCA90B77ULL, 0x7AA493480864E16CULL, 
            0x48B902D587F541CEULL, 0xAEC346F3C0B46B87ULL, 0xE710BF346E310A13ULL, 0xB3510BCA80657AC8ULL, 
            0xEEBD38AC2A971811ULL, 0x4D12CF2AC5CB31D6ULL, 0x50B5C2E2C032C6B6ULL, 0x7618B62DF4D2A15AULL, 
            0x0A525BB0EB3B70B6ULL, 0x900177A4D8C5AEFBULL, 0x8F524441E8435248ULL, 0x33B230E68025EEABULL, 
            0xA3AB62658188EC52ULL, 0xBD22AF17CCF0119EULL, 0x5B353DFC25A315C5ULL, 0x43C05CD45FF54B3DULL, 
            0x880F13CF8C04680FULL, 0x11EC0E2B3D2C16A6ULL, 0x43CDFA55DE95062AULL, 0x81ABFDCE8E8B269FULL
        },
        {
            0x39599C5ED8C50D0EULL, 0x6653CF6563EB0D28ULL, 0x57A6DE5F470DD872ULL, 0xCB783CA9C0A8BFB6ULL, 
            0x0C0C104C92568DF5ULL, 0xA9A34630D302ED51ULL, 0x1434DAE8ECFAA5B3ULL, 0x9810349DD87FC2AEULL, 
            0x4A63E1EA480FB91AULL, 0x95DF031FFCCD3607ULL, 0xB3CCA3DF41A9AE0CULL, 0x9DF9EDDDE8E84376ULL, 
            0x13552B123C747577ULL, 0x1E52C3FB0227F4BFULL, 0xF6811D042F76D3C3ULL, 0xB69E3AFC880072B5ULL, 
            0x19E5AB4BAF74B86EULL, 0x766438E664257043ULL, 0xB47C5D206617D10FULL, 0xD45AE01DA49D1E83ULL, 
            0xCD060A3067541E6BULL, 0x030AD91059067742ULL, 0x1BDE46EF625E8AB8ULL, 0xC34A6E4A787CF54BULL, 
            0x223C39D017A7E846ULL, 0xE1FBDFB30142AB7EULL, 0x0E600C7DAC0EFD52ULL, 0x5247D6089ED3D948ULL, 
            0x3ACCB23032B24608ULL, 0xC57803E30B0D15C4ULL, 0x1E9DA030993FC537ULL, 0x9431BFBAB77CE4AFULL
        },
        {
            0x2DA926E29D7B022AULL, 0x313171A396412C84ULL, 0xE1E3D4AA9BDCFD5DULL, 0x00A9FF5F82F0B628ULL, 
            0x95DAACC804EA2814ULL, 0xE16D55BA79439339ULL, 0x1D77B1B3A29E087BULL, 0x6F1AA1F45C6CA737ULL, 
            0xF24D00B6F4197E59ULL, 0x2418D3E78A15D448ULL, 0x8BADAD847F775C14ULL, 0x36D0CF667D465772ULL, 
            0xB435C715BC4287A4ULL, 0x31B05F333C5993E1ULL, 0x0B2D8DD5315E903EULL, 0x59988398FAB3CF33ULL, 
            0x70F0226517755D47ULL, 0xDBF1E5F36285FF0FULL, 0x24E8F8109CA085B8ULL, 0x76151D154D74DB9CULL, 
            0x189A0F4F871DDCEEULL, 0xBCA02B16B8BA0B88ULL, 0x2A63FB370C5EB9ACULL, 0x04BECE057A34E557ULL, 
            0x73E7A4D8E162DF27ULL, 0xD6B9D19603EC38DAULL, 0xBDE1680806706EB9ULL, 0xACD999B36F5658CFULL, 
            0x56C3F66C632389B8ULL, 0x256D0BD7F9983EBEULL, 0x6621B95CBF86BCD5ULL, 0x88060D8980A45D21ULL
        },
        {
            0xB366A3BEE66206CFULL, 0x0C78FAF632269C94ULL, 0x3D344A9E9F4DA87FULL, 0x9D5A11A40C06A4C5ULL, 
            0x26A6A83CBD78EBFEULL, 0xF2F70A9131FB90F7ULL, 0xE1DA49B6583DEEB8ULL, 0xEAE1D6ECFB651377ULL, 
            0x355DEE90B0002A1FULL, 0x647B53E29FB1646DULL, 0x7CAC73ADB1779F28ULL, 0x85DD558471D7B858ULL, 
            0xBEA38A409734D4DEULL, 0xC61F3E080FA6711DULL, 0x114019C888C3000AULL, 0xF50DE1A92074BB60ULL, 
            0x5E252CE2E5310F45ULL, 0xE68F77D64AD5D71DULL, 0x350742D6BA4F1362ULL, 0xFF2C42ED555F016AULL, 
            0x9BDF133DADD78627ULL, 0x00213A0338144E57ULL, 0x71208B69581827FFULL, 0x6660E967044A4739ULL, 
            0x39A0977614B58A44ULL, 0xAE348D5CABA65F7FULL, 0xA5AE0DDF0678D354ULL, 0xB6F61001112833C7ULL, 
            0x4724902743F32381ULL, 0x0C0338727C83C369ULL, 0x521C30EFD1118911ULL, 0x218F375BE042B1FEULL
        },
        {
            0xC0C966C533F21167ULL, 0xAE3E4F81D9FBF4D7ULL, 0xACFFD0C0C91FEF67ULL, 0xDE9B59F3005D433BULL, 
            0x3B6BB60A1DB7579EULL, 0x87E7295A9AFA43AEULL, 0xBF7F6566B527A472ULL, 0x29BCBB0A25CA488AULL, 
            0x394A6F595C80F9C2ULL, 0x03F158C6DA2C0DEFULL, 0xDFB14CD9560ADB3DULL, 0x03AE78B839ED13E5ULL, 
            0x4A79232FAF45A563ULL, 0x03A8E75756F2C159ULL, 0xA2E9E28F7E9FA993ULL, 0xE55D4D80DD654B9CULL, 
            0x892C316429EE4C69ULL, 0x5D6F0A1AC3BF930BULL, 0x4EBCBE65D2B7E0D8ULL, 0x7F1E6A5D1288C4FAULL, 
            0xB80B76CBE84489FAULL, 0x1C83E0DB80EF788DULL, 0x388D884473F9F83BULL, 0x68F67E0818B982BCULL, 
            0x80101C282E7B8299ULL, 0xA77F59C1F6F1ACF1ULL, 0x03BEEECA50657067ULL, 0x3C43CE0D27798CE1ULL, 
            0xD403797F1EE257C9ULL, 0x11627AA484A724D0ULL, 0x16D10B0A6460DBF3ULL, 0x65AA15A2FBF6AB38ULL
        },
        {
            0x1A910D8AEADF32A6ULL, 0x634ED9C4D3D4AEBAULL, 0x1A75948F841A7D66ULL, 0x4DA2802F667783B5ULL, 
            0x2ADD3D0ACB0648AAULL, 0xB973ECEF4717D626ULL, 0xCEBE28C156BEA09CULL, 0xF74377949360FE00ULL, 
            0x9DCEF7D4B9AE9B1BULL, 0x73C64E8156546214ULL, 0x611C023B0802A073ULL, 0x4A69444363B9F93FULL, 
            0x6C3564B08A2189DEULL, 0x99644B442943F1C2ULL, 0x5D2083994DADABEFULL, 0x3F4F8882EC5AFF4BULL, 
            0x148F18443DEEE590ULL, 0xD1E64B0A4D4D103DULL, 0x3D0475F7C048111AULL, 0xAC41462383317A6CULL, 
            0xEF12AE2861785D18ULL, 0x5AB6F8EF948C5926ULL, 0xB16E7C851FBCE944ULL, 0x23BE5B804302EEAAULL, 
            0x4BBBE4B6412EC79EULL, 0x6D414CE531F453FCULL, 0xC25B850AD71214F3ULL, 0xD4ACEC0721EB781CULL, 
            0x810E1447CC1927D6ULL, 0xBE61067EADE76137ULL, 0x4B01846B6C2D6588ULL, 0x703632BC23EB1F31ULL
        }
    },
    {
        {
            0x27BED5C897DBBD70ULL, 0xDA8F5943670A99B3ULL, 0x30D890307A15F3C4ULL, 0x5A0F277CB610908FULL, 
            0x9CE216980A843ED1ULL, 0x1387CC0CE9F3D747ULL, 0x472EC11F17CD652BULL, 0x3E4ECCEA826D9747ULL, 
            0x69F5E08D932A6326ULL, 0x5B39C179076064C6ULL, 0x6D9417C08458AFD4ULL, 0x69E0C9323DAA08AEULL, 
            0xE6816757C5D27841ULL, 0x21CD4FD4357D88A4ULL, 0xC230C2351589FB98ULL, 0x9DD38CCD9FFB49B2ULL, 
            0x72EB76FD350F11CBULL, 0xB0B1D20514472A21ULL, 0x4BAC119A15403972ULL, 0xFBC1A463A36666A8ULL, 
            0xE6F8C650404DFB2FULL, 0x6ABC406D7C9C5BA2ULL, 0x02BCA2E7CE8A4095ULL, 0x71182F2C524F926AULL, 
            0x80A92F1F7466BE8DULL, 0xE658080AF1B4EA1BULL, 0x0FD1BB2B2CC5672BULL, 0x464090C971AB14B1ULL, 
            0x5F0CED6C61A234F5ULL, 0xAE3A44A6A64A4426ULL, 0xBDA29096D7F364F3ULL, 0x739DB7E1365D8889ULL
        },
        {
            0x3A82C64F67C41815ULL, 0xEECD905C60ABC42AULL, 0xEF8BDAF64279A4B1ULL, 0x6C74D5353CB34536ULL, 
            0xF1B39A069F3955ACULL, 0x9FA91B6D541BD3C0ULL, 0x76FD1F680A818252ULL, 0x6A3DD2120735BE7DULL, 
            0xEEF5C74628D7B4B6ULL, 0xDC55A3EC4A677148ULL, 0xE1A19EE51F605190ULL, 0x99D3035E14BD04A8ULL, 
            0x721A1EF47B6FE9E1ULL, 0x2DE5DF03E45EB612ULL, 0x0C84715F487969C0ULL, 0x4CD0A9B562644959ULL, 
            0xE302E28FEBB7B409ULL, 0x4137CF01BCEABDC2ULL, 0xF068841307ECE337ULL, 0x24114BD47DA82A40ULL, 
            0x07B8E79B3C00410BULL, 0xED114BE4F48B7B8BULL, 0x29E65766395D0303ULL, 0x5EC398E93DDEE77DULL, 
            0xC73FAC8E19A23A49ULL, 0xC0C9CB7DFCAE246AULL, 0xC5230A325E5D0644ULL, 0xC45B078D7AE1B097ULL, 
            0x7960105C274D566DULL, 0x3D768B52659C8B94ULL, 0x1CAF8C1AC1CEF7EAULL, 0xFF6A67A25D649395ULL
        },
        {
            0x35CBD89D54E4E78DULL, 0xC429651820EA3D24ULL, 0xDD89A4124D32D6B1ULL, 0x87F5DAFDD01AA545ULL, 
            0x0F92A42E517986B5ULL, 0x7F3F2955E1FA17E0ULL, 0x23D98633A08A43CBULL, 0x64BF693C4E7D4C2AULL, 
            0x3EBC4D7B490B0559ULL, 0xA6E6844B105AF9FEULL, 0xBD201F0D484B6F95ULL, 0xFE5DF410FA700C2BULL, 
            0x01F3ADD07FBF8C3EULL, 0xFA5C15868181DD14ULL, 0x60F27ADAE57A750DULL, 0xF48B556686781907ULL, 
            0x2C59C31CF91E3B45ULL, 0x96E63D7E6EA4F33CULL, 0xFE6AE7A74FB70489ULL, 0x81DD3F4831677416ULL, 
            0x8C27E74EB45186E0ULL, 0xFC5A5D7D1A567C01ULL, 0xD8D19D33899DF897ULL, 0xE088CA3F632F4A5AULL, 
            0xB39F53D595AF6EEDULL, 0xE5B9642CF121F9E3ULL, 0x345E0A976CC7FA15ULL, 0x44503869E65DFBE8ULL, 
            0xBD6042B63D2E3A4AULL, 0x5C7AB98AFB6BD74FULL, 0x32FA3C9878971D2BULL, 0xFE2F4EF19D15DB20ULL
        },
        {
            0xADC57EAFB258E16CULL, 0xD901BA8A828702BDULL, 0x2436BDD64666B1BCULL, 0xAF97755C487C947DULL, 
            0xE01AD8EEC99212D1ULL, 0xF9BF141ED482D310ULL, 0xC32A1E1A1DF1F290ULL, 0xA931229237E058ACULL, 
            0x4D8BCD8E72CE8211ULL, 0x87567C5DCEAEBA1FULL, 0x0A83F9B66F895655ULL, 0x437DF48AFADA842AULL, 
            0x98DFC06747B6AA0CULL, 0xBEE005D2DD9AC8F4ULL, 0x8B09E6A9D8EEB6E7ULL, 0x4B0FD963EF6DE0E2ULL, 
            0xE427E4CD9F025356ULL, 0x4E4D1B550583DDAFULL, 0x682A3E34F608E021ULL, 0x5F34CDA00AF1FF45ULL, 
            0x792512EC97877B8CULL, 0xDA6C0F949FEE6DF5ULL, 0x28A6CBFE796C92DBULL, 0x61D5B99D8092819AULL, 
            0xAB537AB5A32C8EFDULL, 0xBFD31E848E9EC9D5ULL, 0x87976FDFFF27874FULL, 0x2358AEBE7DCCD6A3ULL, 
            0xCBA19D0302674AEFULL, 0xE6209F56F5F61D2CULL, 0x05597B178CD1F386ULL, 0x4E87EDC5E5F55182ULL
        },
        {
            0xE319BA40F609C326ULL, 0xA921D864E18915F5ULL, 0x5C66591914B1BEA3ULL, 0xB4868A68DDE44123ULL, 
            0xF440A339A0FB2F81ULL, 0xFE75CB2650D3B81BULL, 0xC2EB47566D6D015AULL, 0x1A2301470406551BULL, 
            0x3AB95EE06BA9AEF2ULL, 0xE6F170D90F61F590ULL, 0xC03047415B88D389ULL, 0xB3D618FB5CC1C07DULL, 
            0x52656568D4EF7BFEULL, 0x93207B2300BC4500ULL, 0x1F5C0D73B797A2E9ULL, 0x4AFFF4731C176C27ULL, 
            0x2E75CF48A6690B91ULL, 0xBF254A6DFDF5143BULL, 0x8C08C1E349BEFC18ULL, 0xF1BFF7503F9D7C3EULL, 
            0xE549333B11BB801EULL, 0x6EB7127D173F9521ULL, 0x28D7F296DA36B185ULL, 0xE433ABEB87E8F596ULL, 
            0x9BB1B9517BB72EC5ULL, 0xF5AA86A116034503ULL, 0x7B83C7262F3295A0ULL, 0x2D181B502FA3BA7EULL, 
            0x2226855041BA5261ULL, 0xB5D109B4CD8DED05ULL, 0xECEA0DA8DB204B10ULL, 0x669158F28E6772CFULL
        },
        {
            0x3538740C0D8E4121ULL, 0x383FFCB3D01E062BULL, 0x48ECBE9AD09DAC7DULL, 0x0DE2EAF6280850A5ULL, 
            0x79780DE1829B22FEULL, 0xB02434281F8B77B4ULL, 0x997C4041A7D05160ULL, 0x3363E4D654FA99F6ULL, 
            0xCE79FAE0F0DD3A5BULL, 0x63374700D30CF01BULL, 0x6C681B8CA0B4D6FEULL, 0xF35521E04E72F4F2ULL, 
            0x47D1022A14439CFDULL, 0xCFC3810DD3CD82DDULL, 0x2B4E64AC075699E3ULL, 0xFA5E38AAA5A6AB85ULL, 
            0xEEDEFA6F908EA31BULL, 0xB838552415878CD1ULL, 0xB7428CA09CC6756DULL, 0x52FA9CFC9AEE0B4CULL, 
            0x41AFFE9E7708E1B6ULL, 0x85E49C3AFE741619ULL, 0x501B7A97F23112DCULL, 0x51EBEEECBFA9E5E8ULL, 
            0x39184A67229D9630ULL, 0x7412F06C03008240ULL, 0x752B388941C66798ULL, 0x58D1CA427C0FF2F0ULL, 
            0x7ED71972A58921A9ULL, 0x3DD8E405191ACEDAULL, 0x1E35C62C7D9CEDE3ULL, 0xD87CB95E1EF78FE0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseFConstants = {
    0x4118C98B2FA42296ULL,
    0x0790F3B2F678DA38ULL,
    0x74DDFB51DB03857FULL,
    0x4118C98B2FA42296ULL,
    0x0790F3B2F678DA38ULL,
    0x74DDFB51DB03857FULL,
    0x4E4AD51C53424754ULL,
    0xA1E9C21C093F1075ULL,
    0x32,
    0x3D,
    0x76,
    0xEB,
    0x39,
    0x97,
    0x69,
    0x90
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseGSalts = {
    {
        {
            0x0372069AC654433EULL, 0xCA27F7784F54F42AULL, 0x437F4B469822EBF3ULL, 0x7157B36A4210DF52ULL, 
            0x8373072122996ABAULL, 0x55432AD0FC244F34ULL, 0xDC78EF11A9C6F047ULL, 0xA7F29675EA3EA30CULL, 
            0x022D3761230CB09FULL, 0xECEC727353AFFD1CULL, 0xEFE054D214B36941ULL, 0xDD41E925BCF1A897ULL, 
            0xD7935B3E0E4A473FULL, 0x3E7792DF7E20103AULL, 0x53716A4C3DE1A866ULL, 0xF185005F3589C2BAULL, 
            0x92ECD74C9F84E101ULL, 0xD6139E15605E7923ULL, 0xA41FCCEF1CF7B706ULL, 0x60F97ABFFDF5535DULL, 
            0xAF151A0332CD884EULL, 0x8BABAB8FE697956EULL, 0xABBB34DDB163295FULL, 0xC0DDE997ABF309F6ULL, 
            0x501EA433B47D6ABFULL, 0x21DED3711972C1D6ULL, 0x3D4A5C23D38C7DB1ULL, 0xF1617A803532D540ULL, 
            0xD3A148DB369CE1D7ULL, 0x2A3D6DF0DDFDFA7AULL, 0x0DCAF28B9C560269ULL, 0xC78B899F6619AA9EULL
        },
        {
            0x45979971C97480D5ULL, 0x67EED8D5937560A9ULL, 0x1DDD0E06D49A0946ULL, 0x405647ACDDCEF2B5ULL, 
            0x8CE68509EDE903BCULL, 0x5CEE0C8C509FF09AULL, 0x8349A44DCA861872ULL, 0xE0308FBBEBFFE5FFULL, 
            0x23F79A36F1577BCCULL, 0x134C8AE518825792ULL, 0x2C1E06B49B9E21FBULL, 0xB90C91A8A709809CULL, 
            0x502F343232EDD156ULL, 0x2E2F09F2250697E6ULL, 0x8808D93F75841BA1ULL, 0xEFD7854149323EC2ULL, 
            0x1B447E1DB8D7403AULL, 0x22FD5E4A6EC47C14ULL, 0x93675258722B578DULL, 0x5A126218A7F35CC9ULL, 
            0x3739D44B668AEC1EULL, 0x9AE47A9C1FD3B5B5ULL, 0x9A668AE7171C87ABULL, 0x8933AC96EDA9C755ULL, 
            0x6E1997DBAF66D3E8ULL, 0x5490197558C80255ULL, 0xECFB2ED1B2769F7BULL, 0x7BF3FAE818BEFDC0ULL, 
            0x21337EEA566097EEULL, 0x2B4321B97DA3C0DBULL, 0x8AE9461F1ADB6F18ULL, 0xB4632C99C04F2BC8ULL
        },
        {
            0x0B9EFD1A09A70782ULL, 0x19BF6567C345E20AULL, 0x25EB5C367B8360D3ULL, 0xED914D313403DE85ULL, 
            0x1BE80DD44B89E9F5ULL, 0x46DD70F9411639ECULL, 0x03D3B0D8289C62C9ULL, 0xA812AAB9995D890EULL, 
            0xEE8F78A6A7ED358DULL, 0x5C8E559F6BF25FA7ULL, 0x6BB14157E841D56BULL, 0xEB6E575E2BC9A00AULL, 
            0xE05EE70F5BBD6A15ULL, 0x0289AA0008C96909ULL, 0xC1CAE8BAB941E226ULL, 0x04FA98C03F158BCAULL, 
            0x08EA86EFE99372DBULL, 0x47553289033468D4ULL, 0x9E505B43055E646DULL, 0x46D3BF645E17CC5FULL, 
            0x77BF66B41680DB51ULL, 0x42A365E84E7309ECULL, 0x069E2B7C9A81EE1AULL, 0x09D2B8312CA8485FULL, 
            0xBCC7C46F86CB3F2FULL, 0xC68AF7821A0079E0ULL, 0x8BEFA03295FA3DADULL, 0x9896CF046D100496ULL, 
            0x1E4EB659AD11A9ABULL, 0xC80B9D8C5DAB2449ULL, 0x5E86F6166FA434EBULL, 0x5F9C096D6EA53FE9ULL
        },
        {
            0xDBD885C669A21D02ULL, 0x3D1A21E8B03BCA67ULL, 0x112C93BFFE941A3CULL, 0x8EC73268D3D68778ULL, 
            0xF43789C2E5FD9DB4ULL, 0x48AC0B583345423CULL, 0x6417D3CA14D13484ULL, 0xFCB4B250037CAAC6ULL, 
            0x8646DB177336E1B3ULL, 0x5843BAC523E8FD72ULL, 0x0C9029D5D3BB5217ULL, 0x78C583D4B0DE8D65ULL, 
            0x72F372792B24E956ULL, 0x75E016B8CB3D7172ULL, 0xB6151808980D3FBBULL, 0x9D0B35C8A5DB8F44ULL, 
            0x97081535941C53FCULL, 0x098E97C4326B7085ULL, 0x8CFAB278BA74BF30ULL, 0x4753C0D9E3F6EE45ULL, 
            0x3A1180F93D975352ULL, 0xCC0EBEAED18E69C1ULL, 0x583705F1A46DA639ULL, 0x803E74EEE377C6CCULL, 
            0x8409DD21AD15EDBEULL, 0x5F65AA31ABD050D1ULL, 0x3C79E169612C7AA6ULL, 0xBD132BF1E526BB4CULL, 
            0xFE99B67427AA2D94ULL, 0x92FC3428F2C23347ULL, 0x2880374CB4257582ULL, 0x194DF3C7EF8E92B5ULL
        },
        {
            0x888FDF5F274BA7C0ULL, 0xF30F8CACFF93B031ULL, 0xDC733742917642E7ULL, 0xE54F3B0DA3E93157ULL, 
            0xE404071D5DB8D97BULL, 0xB121607083BA37C7ULL, 0x344655B70FF9E641ULL, 0x8953E21F64533AC8ULL, 
            0xF65FB9D0C422724FULL, 0xD8A7D8C0FD6EC2E2ULL, 0x7575B015F4BB824BULL, 0x77A40342B9215DE0ULL, 
            0x1D1246BAFD18FCE7ULL, 0xFCBC7B841C61AAA6ULL, 0xFFA765F9437CA199ULL, 0xCB5F5829546E9774ULL, 
            0x722779960BD3C538ULL, 0x39A8ACD08666E318ULL, 0x818A5723F9FDE501ULL, 0x975E15AC83317FE2ULL, 
            0x4FFABCE3D57B5D8BULL, 0x7075849A784DF931ULL, 0xB63A481A12B526AAULL, 0xA8F2D85F74D66682ULL, 
            0x2305579AE7614768ULL, 0x6E02DA453618F33DULL, 0x77AC6E09189E5CF1ULL, 0x8BE30D9305FF0ADCULL, 
            0x080AF928DBE55106ULL, 0x7557FA681EED642BULL, 0xBAF9C2112E999B13ULL, 0xF8C5117F30165429ULL
        },
        {
            0xCA8D4BCB7A66D1B3ULL, 0xE30E488DDE6728F4ULL, 0xF6A800AC22D93F05ULL, 0xE2315F21B52B31C2ULL, 
            0xB78D9FC1231D6C7BULL, 0x90CC7DCDC07220D8ULL, 0xD8550EA48B43FFA3ULL, 0x0B418D66D06640CFULL, 
            0xC5CF937EB584F6E0ULL, 0x455592C995F7C6A1ULL, 0xF644F05BE182ACCFULL, 0x655C4FB54F4C2BF4ULL, 
            0x9DB733CE049CB34AULL, 0x1BE961EDD2F42FBCULL, 0x28EF333F0D92585FULL, 0x42FBAE3CE8E9CE87ULL, 
            0x6BAF713D18E0B60EULL, 0xD081E71DDC6E6E16ULL, 0x592D7383AF96C138ULL, 0x906737FD917269EEULL, 
            0x469DF99DB54B6B60ULL, 0x0ADBD2C60A52C71EULL, 0x99C36778A087C857ULL, 0x54B17EE1C9E0B257ULL, 
            0xE7E750A322622C6EULL, 0xB68036E017BF2996ULL, 0x33913A6BDD074773ULL, 0x08A039127660DA35ULL, 
            0x14DFC707B5DF7079ULL, 0x32057C0935991AD6ULL, 0xD3B19A26BF47982FULL, 0x31346ACA57C4EE89ULL
        }
    },
    {
        {
            0xF5D0D57533639C31ULL, 0xBC089318EE2CE81FULL, 0xA4FFB7CB5EF54CB3ULL, 0x5812C477D77BA5EEULL, 
            0xF1EB1B65F8924FB3ULL, 0xC9DDDE41A49590A3ULL, 0x3DC0B79608018BE7ULL, 0xBA046C003AD554A0ULL, 
            0xA8031E9A3568D2E4ULL, 0xA33862DB7556298FULL, 0xB1D7C209F8446E31ULL, 0xBE90BD99CA2F50E2ULL, 
            0x2FE27CA1490BD5E3ULL, 0xAB12B47E81B3C52EULL, 0x2E1BD9E2FDE09F59ULL, 0xF5F0991FE9758446ULL, 
            0x51CA989A4EF24C5BULL, 0xE63BBDA3C7A1EED8ULL, 0xA66984780501ADC8ULL, 0x7FBF6F476AD5658CULL, 
            0x2E316274ABCE9101ULL, 0x31A30BC0885776CCULL, 0xEB3B8DE5E930187CULL, 0x2057D2C8680B79BDULL, 
            0x3675E8AA1BA5755FULL, 0x3C76EDB7691A961EULL, 0x9769200DB889C9F1ULL, 0xDEB881F2A9ECF26FULL, 
            0x7F6D22E08E2AD3AEULL, 0xB73E8D1C1A45A0B1ULL, 0x7EBB5D9E8C370AEDULL, 0x1EC50779DC2586D8ULL
        },
        {
            0xE3D75AB25529085BULL, 0x4A59A700EA0AD513ULL, 0xCB2CB510DB3146A8ULL, 0xE078E9BC96EB10C7ULL, 
            0x79AA3CC9B065CD95ULL, 0x70F6AD760B697C1EULL, 0x71C7E0CD0F16A626ULL, 0xF0F956EDBB0A96D5ULL, 
            0x5340A007B191F068ULL, 0x94078F20F5D7147EULL, 0xCFFEF2CAA888B261ULL, 0x78C395698F859456ULL, 
            0x27DC99672CBF3491ULL, 0x7C0A1ACC5DBC37CDULL, 0x545557CCE93BB3DAULL, 0x156E481A956A1DE3ULL, 
            0x706E36D6B349DFB0ULL, 0xF73711A1FED720C8ULL, 0xB95557C90AE41FFEULL, 0x0646F70A62AE0E01ULL, 
            0x0250FD216D5081B9ULL, 0x72498A17E3CE80ECULL, 0x322AFBDCA6A2A0C2ULL, 0x0EAFF3FE56F30889ULL, 
            0x69AD5C3101E03EE2ULL, 0x885C8AA0E3B38B69ULL, 0x79E78C23E12D0E2CULL, 0x25CD6BA964081633ULL, 
            0x74460ECCAA790D70ULL, 0xED13A3367E1DBB5DULL, 0x1C8BB38CA858D66AULL, 0x0F670CFCDBC37A8BULL
        },
        {
            0xB9B29C25B5792B38ULL, 0xCB280BE1D7FCAC65ULL, 0x28F0DE0754F2682CULL, 0x85FF1AA4DB011E99ULL, 
            0xA4A2FC60E4C722D1ULL, 0x2D9EDD776F3ACEFDULL, 0x2482FB4F63266120ULL, 0x97C46108978DD08FULL, 
            0x2E36E7164280D802ULL, 0x236CED1B71556B37ULL, 0x25AF66611286B83FULL, 0xF66B2F5A9066F5CEULL, 
            0x5C7798A835FD6A8BULL, 0x95CBF4B8CE0A88A8ULL, 0x534418D2E16FDF32ULL, 0xABAB479E9D1A4D1CULL, 
            0x278CB6F8731C9056ULL, 0x3D4F99BE3D78EB1EULL, 0xCF95A8118D2FD6A4ULL, 0x325FD0EA0522F41FULL, 
            0xF009D9D5B49F22E0ULL, 0x559BF0FE4FC0D7FDULL, 0xF5B970F4460E97B2ULL, 0x13BD4C858264F2F7ULL, 
            0xB6E1C1079F53B884ULL, 0x92274F57AE047A7CULL, 0xB2E8293B64326724ULL, 0x9AAA5A5F1CE52EFDULL, 
            0x7C9950AFC68AE387ULL, 0xC1BB4915C35E6D01ULL, 0xE79FEC59F5F61764ULL, 0xB38CF099C6859CC0ULL
        },
        {
            0xC7B695A54911070FULL, 0x56ADB5F432016E9AULL, 0x58F26801BCFFC2D9ULL, 0x7BB3B70A4D702896ULL, 
            0x30424C361569DD76ULL, 0x18252806E24D7369ULL, 0xEDA3F36A8244249CULL, 0x9C99F2F8EB437E62ULL, 
            0x1CC0A57FC35971BCULL, 0x155D89076D87AB2CULL, 0xD33F05F90D91F5C9ULL, 0x4256B9DC3E575FEBULL, 
            0x8E562E31871E8ECFULL, 0xA02C71802FD313D2ULL, 0x87B930B5D28A4EDAULL, 0x14AE786C78A0676DULL, 
            0x2FC8851C20081D71ULL, 0xA01080170B69D372ULL, 0x9A0FD6C48ACFA077ULL, 0xE2C8827FA5B9BFDBULL, 
            0x4393A79B51B472E6ULL, 0x889AC25925135ABAULL, 0x3850A0C0F1676FA5ULL, 0x6167406B20D6F612ULL, 
            0x6CCD8A246BD21184ULL, 0x65DE5534FEF7EFB9ULL, 0xD1D465476946D28BULL, 0xB71766640E84017AULL, 
            0xF38BD7FBD92980A9ULL, 0x4965BEFB62AC8CDFULL, 0xE9B57DAD9A248A87ULL, 0x502D70E4C9FE0774ULL
        },
        {
            0x3D04A2699990E972ULL, 0xA7FED109AB85BA0CULL, 0xB49ABF0061A5C170ULL, 0x0FF2D0587CED4474ULL, 
            0x7FAD76DC5CC0BF94ULL, 0xCE4A5AD0DE349986ULL, 0x6FD035A1DCFEC73EULL, 0x840CBE3A02E9F32FULL, 
            0xAD5B5B1F5A19902FULL, 0x506A927911C8A8F5ULL, 0xDF24894751C008C0ULL, 0x2972286F0A3415A7ULL, 
            0x39BD09463523FD23ULL, 0xFA40AF13E31BED12ULL, 0x510384604EC43130ULL, 0x23B34314C1348DB8ULL, 
            0xD3DA4AD1C647E0ABULL, 0x599AAA3D2B7B15DFULL, 0x22E303B2D17534C3ULL, 0x8769502059795123ULL, 
            0x65CF0DC47522AD17ULL, 0xA732261F19DB5047ULL, 0xDEF3B28E06DFB420ULL, 0xFDCBA36369B54085ULL, 
            0xFAF9C692E9F65E0DULL, 0x11947A0C87728CA5ULL, 0x0F2B3789C0656CD6ULL, 0x3FF9D8CB6EC2DCEBULL, 
            0xC95339A5778DB8C1ULL, 0xE7D776E099D50253ULL, 0x1AE014D38BF23E28ULL, 0x610B8CFABAFB227AULL
        },
        {
            0xBD740D584EF38F0AULL, 0xC7A0BCCA206865A5ULL, 0x7761B68BF5DE383BULL, 0xE9B1BB37D796D5DEULL, 
            0x5799FD9FFA3C4A2CULL, 0x157A55BADBCB311CULL, 0xFAD658A6E07B51E4ULL, 0x593E4AD2AA16DC21ULL, 
            0x978EC7668563473AULL, 0x5B2FD34B25A23AFEULL, 0xD024BE9D8A106D6FULL, 0x3F943888E1E2B55BULL, 
            0x3BE5CEDDFF289209ULL, 0x42908A65ECB0D659ULL, 0xD69330CAAA56E474ULL, 0xD3907509179417D5ULL, 
            0xDAF48BA440274E71ULL, 0x0702A0731CC8E927ULL, 0x9BC19FABE88467EAULL, 0xA47081F97D3BFF17ULL, 
            0x2719DF086552AFB7ULL, 0xB8B0122101D509AEULL, 0x1178884C22B7E921ULL, 0x6398E2AFE7495847ULL, 
            0x226D9AC84ECBA038ULL, 0xBAE347B0A9BF848EULL, 0xCF2F64BFDD8029B8ULL, 0x14A887AE9E47F753ULL, 
            0xC6F92E654D3B2230ULL, 0x325D23D767AD93F5ULL, 0x4E6957E5CDEB8D31ULL, 0x135672EE72ADF376ULL
        }
    },
    {
        {
            0xFFF05DDFCE58694EULL, 0x08FA269D6A42A461ULL, 0xA5CB23F87E60A3F0ULL, 0x2AFD807B8396C6B2ULL, 
            0x98A0F81709343390ULL, 0xE5E5CAF9F59003D0ULL, 0x89CCCB6BBEFEFAF1ULL, 0x3239B032C06FCFA0ULL, 
            0xB0715066F74D537AULL, 0x88F77209E55784AEULL, 0xC79C52C93D2021AEULL, 0xC2DA11270A142B17ULL, 
            0xEAF17663CC76EDBFULL, 0x0B1CB19EA717EDE5ULL, 0x8C42FBEBE8DE3F27ULL, 0x5912CE4838514ABAULL, 
            0xC294AFC9A153A823ULL, 0x1465D0D8E288E47FULL, 0xA456760A894BCDB6ULL, 0x9D42B7D18026422CULL, 
            0x2E3A925FFD7BC44AULL, 0x4A84193A0E2B363BULL, 0x02B354DFC86E81D5ULL, 0x1D5C8229A2E44679ULL, 
            0xFFEDBE6AF62536F3ULL, 0x4817FCEE22D9BAF7ULL, 0x8BEECC081F528536ULL, 0x399612EFF5272B36ULL, 
            0x07FE212A8BD6BEDCULL, 0xE7E90B3B05BCC967ULL, 0xAD219E3CA6B80291ULL, 0x54234A2D7039F4C6ULL
        },
        {
            0x819EE650A6C35D4AULL, 0x3A93E1D3CC24C5E3ULL, 0x49D0FD5A36B6291AULL, 0x53152F1505A0E11EULL, 
            0x923EA5F1CE366DABULL, 0x844D3CE311E07AD6ULL, 0x21669BE00D037C9FULL, 0x784F14374BADE582ULL, 
            0xB64E6043D0A6EE3EULL, 0x64E08D8196569025ULL, 0xDF39651627F8EDB1ULL, 0x06FAA8358CCA5E6DULL, 
            0x009287A6981E41AEULL, 0x4FCDD1BC178F4FA4ULL, 0xFDA37F165821B259ULL, 0xC796346245FA5303ULL, 
            0x3170C935842FCEF8ULL, 0x183CD0AD98AE6FA7ULL, 0xBD05AFC9F76325A6ULL, 0x1C06A819286BECB4ULL, 
            0x1ED4C6FF4CBFF0FCULL, 0xBC8FA93E64F92AD5ULL, 0xC20C94E49B7BD3B3ULL, 0x25FEF75BADCDD937ULL, 
            0x42B85A84C1787AA0ULL, 0x116CE4CF29380B6BULL, 0x8259A78EDFE65708ULL, 0x12CFFAC53D7E27C5ULL, 
            0xE1AD13408D22B3ADULL, 0xBE4DED7E980CE9D7ULL, 0x33B444059E4D7B44ULL, 0x2E672DB5FBEF09CDULL
        },
        {
            0xA1D28C0FE8CB1705ULL, 0xD5C1F65D96437D97ULL, 0xEA16D5DE48B35F58ULL, 0x79EB2078571E14ACULL, 
            0xA007AFDB5E38283BULL, 0x1793096D0F9F18E7ULL, 0x7561ACB9EB1E1240ULL, 0xB10BD804C59698F5ULL, 
            0x7AA9A505A88770B1ULL, 0xC0C3E7F34882B9A9ULL, 0xCACE1CE7E18A6E5AULL, 0x0396403A468A1CA0ULL, 
            0xC1DB35F2D0CC5569ULL, 0xD7AA7B0B0209DE5FULL, 0xC7654805DC4AA3E6ULL, 0x73E46D1755CBAC13ULL, 
            0xECFBA92D9F785A21ULL, 0xC438D144E257707CULL, 0x97AAC8ACEEA86FC4ULL, 0xFB50D690F21EA22DULL, 
            0xC94B0E6D84C0CB2FULL, 0xF863269555974D46ULL, 0x91175202DB08258AULL, 0x50ADAFEA2EE2D11DULL, 
            0x1377CBEB49DA079BULL, 0x30DC92336FBBF656ULL, 0x07D6AC5E84489128ULL, 0x7320794CE0B0690FULL, 
            0x60F0F450FC661954ULL, 0x73E7DBF0FA3F94F0ULL, 0x8F4CCB378AB8BD34ULL, 0x5B68CE3E1F9548CFULL
        },
        {
            0xE75AA4FF2092237EULL, 0x926D3EC81B47FACFULL, 0x4F76CEEFAA214F0EULL, 0x0E8357D342EED03FULL, 
            0x6C8E863EE0E79DE3ULL, 0xD3AD8D70A3E059D6ULL, 0xB91D037E0C86B2C4ULL, 0xB2C719136525B0FAULL, 
            0x5297D318C0B34C2DULL, 0xC67518A13BA737FEULL, 0x2D26163F9168AEA5ULL, 0x1113E9833B8BF328ULL, 
            0xE0B749893C816C17ULL, 0xAB740D17CB340D48ULL, 0xB207AE981E7A6AC1ULL, 0xDFB3A5BCED7A9AE8ULL, 
            0x93BFA6A21967EFB7ULL, 0xC2F4CD02D5930DBEULL, 0x0F85EE9384611F2EULL, 0xC9EF376DAA2263DCULL, 
            0x9E3E3217D9A287CAULL, 0xFA2D7497ED4C270BULL, 0xA6D37D73A5DF4403ULL, 0x35FD3DEE922993A5ULL, 
            0xD42760908AB58E4CULL, 0x5A52A5AB57655EFAULL, 0x4467B7F9393D5AFDULL, 0xBE0A7CA07BCDC1B6ULL, 
            0x44DE1B9F5E3FD83CULL, 0xB1167E592EA612A4ULL, 0x4E228E37A2D1334CULL, 0x62D1EE759A81CA28ULL
        },
        {
            0x302C32A007008189ULL, 0xE3B7DD09085AAABEULL, 0x9BEAF0D683421319ULL, 0x9DD634170C8D3444ULL, 
            0x3DE849E8C692DB38ULL, 0x70F3E6F62E93D744ULL, 0x54C5F645DACF2B72ULL, 0x6BD54875AE0FF333ULL, 
            0xE8B15EE89E30E722ULL, 0x207CCE9C5ED8BB15ULL, 0x635D566FA9E1452BULL, 0x6D7EC39C89E39F5DULL, 
            0xBC9741F3C8A7061DULL, 0x3301BBEAFE16D7A1ULL, 0xCE9687BA163E508BULL, 0x75552760B793CCF8ULL, 
            0x3DF05C20434195A3ULL, 0x74394496BDEC51FAULL, 0x1B1EC4735C4C36F6ULL, 0x94B54845FB6702AEULL, 
            0xCB3CEFF3C3DB8458ULL, 0xD2ADE8306DB3676DULL, 0x34610F5E19E0D1B5ULL, 0xB02565943E885C28ULL, 
            0xD0CF2E7B4D96FD74ULL, 0xDF112F1AF4282D5FULL, 0xD5AB4E0B191FEBFBULL, 0x23B41E922BCE7F17ULL, 
            0x9BC6C4ED3F96F5B3ULL, 0xD6E38E274136C4F2ULL, 0xE312D830B5196D16ULL, 0x4BEBE2D8E0858AD4ULL
        },
        {
            0x062F4C99D0BC6546ULL, 0x498887533B533EBBULL, 0xA153EDB8CED142BAULL, 0x5C0316E86AD05DF8ULL, 
            0xFE5B2A3AADE7DFF5ULL, 0x60918F614B5603B1ULL, 0xC889A5CA90CB13C7ULL, 0x1694BBE493FEFA9AULL, 
            0x7A053E741119D419ULL, 0x1E39B2B6C214D4ECULL, 0xAE950F347A3E80C3ULL, 0xC8DC4E842D49EA2AULL, 
            0x2B729C5CBD3F7B47ULL, 0xE73ACEC4027DB3F7ULL, 0x7C9057FF8E208307ULL, 0x7C9FF303D990A7A2ULL, 
            0xE6C403C0CC3AA47BULL, 0xB8326CC0DBA1E397ULL, 0xC83741D14DBAC3D6ULL, 0x0F4F19E49ACD6117ULL, 
            0x61D66952EFCF3486ULL, 0x34D775012673E0CBULL, 0x4E1A7A293F6D47D5ULL, 0x370BDF2EE760661FULL, 
            0x2CEE82356831A92FULL, 0xEF41E2D600846304ULL, 0x17A86BC21AE2654DULL, 0xE0AA441BC470E50EULL, 
            0x13A4960E8DCDAEEFULL, 0xAFF12DCF8AFB6330ULL, 0x23209C5BC9B51A9DULL, 0x587F7BCA259AE46DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseGConstants = {
    0x54A62D898B37FDAFULL,
    0xAD912048AEDE3EF5ULL,
    0x13B237D1CBB9A977ULL,
    0x54A62D898B37FDAFULL,
    0xAD912048AEDE3EF5ULL,
    0x13B237D1CBB9A977ULL,
    0x5528E0602D081CEBULL,
    0x022E2ECAA834BDA3ULL,
    0x88,
    0x60,
    0x7D,
    0x68,
    0x18,
    0x27,
    0x66,
    0xE0
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseHSalts = {
    {
        {
            0x6D04B4748D23F4D7ULL, 0xF0B2179C34C8F7BFULL, 0x3C653D7B191947F0ULL, 0x26CB25D6AE5146E4ULL, 
            0xBA8544EB64259235ULL, 0xFF4C0E370A8A82BCULL, 0x7EFDD5C290484418ULL, 0xA1937769AA9D6127ULL, 
            0x8B259D6A92160AB4ULL, 0xDCB5E31AFB340B36ULL, 0x0B4509F57950B9A4ULL, 0x3847EFAB6FE82C5EULL, 
            0x99FDCA21F04A1EC2ULL, 0x4886B347FBA25EA5ULL, 0xF642CAF45DD55214ULL, 0x6307AEF0FC2518C6ULL, 
            0x6A22CE63A836122CULL, 0xC652C637BE0414BCULL, 0xB08CBD96D7D5189FULL, 0x424611CF2062725DULL, 
            0x80D5308B9AE9B68CULL, 0x6B8DEAB3DBA527E8ULL, 0xD4C71D257BFF895DULL, 0xFE1C741AEFEECBFEULL, 
            0xE5CE0B717D50C910ULL, 0x99D4A07BA4685A9DULL, 0x8C7D4B9D34B1BC58ULL, 0xC5A02C28C2470843ULL, 
            0x8CA3ABE6CC50F7D9ULL, 0xB80683F7AE66FE8FULL, 0xE99385A142986AD8ULL, 0xDB55A18D617CC1F4ULL
        },
        {
            0x521CC0EA4D8BEE73ULL, 0x1B1ED17F9514F073ULL, 0xB7C97A1D0586BB31ULL, 0x13233F4864B65D8FULL, 
            0x00C3F7E8E127723CULL, 0x8F1E8EF351FC1941ULL, 0xF6EBF188BC10454AULL, 0x578658B6A5C090DEULL, 
            0x7BBD35418F0F0806ULL, 0x60484D4ABDCC7C9FULL, 0x8649258AB4763F41ULL, 0x86AFFAC3AEE0B26EULL, 
            0x6223FDFB4DDBEB82ULL, 0x979965C8D324092DULL, 0x0781C62FB241B77FULL, 0x25DBA840BFF8E882ULL, 
            0xDF697C53B475E040ULL, 0x6363C0D05BE0288AULL, 0xF8B3ECA3E45555E2ULL, 0xE9036C951152C1B0ULL, 
            0x909768FF5171EC19ULL, 0x389FD344BF8C3F41ULL, 0x1BE6E63258B07C09ULL, 0x3DDC46D5A35BB64DULL, 
            0xF56E2F9CA2B11843ULL, 0xFDC3B3160F3ED93AULL, 0x873C3BE57A43BD69ULL, 0x626B5BAA4EA127D1ULL, 
            0x34B0731B272D63CEULL, 0x94099594F283BE03ULL, 0x5D48A9A22318D9D6ULL, 0x449B886257C2A51BULL
        },
        {
            0xFFCF8E91A7FE8695ULL, 0x6472825435482A41ULL, 0xD117C37E55D3626DULL, 0xF3C0063DD3A20401ULL, 
            0x256303550A02FED5ULL, 0x34BCC8A8740590AFULL, 0xC38CA3E4FF820562ULL, 0xDC8024FD01311384ULL, 
            0xF6F8BC17C2ED17DFULL, 0xA94A890FEEBEC6B3ULL, 0xE48D2DEAC56BF6C4ULL, 0xD3A7E47730A35BFEULL, 
            0x41F7BC5986304579ULL, 0xD16C36AAA833398DULL, 0xBE7D4AD729ED8E12ULL, 0xC2DEEEBFD91E7F7AULL, 
            0x5A1A50B61BBC97E1ULL, 0xD82C28725A18BC01ULL, 0x99D325933443CD22ULL, 0xA47B5B6922688295ULL, 
            0x51C2D817B656A4BDULL, 0xD280042AB035D960ULL, 0xFCEFAA715A36116CULL, 0xDD201884F062AA5CULL, 
            0x60D2E4E41271F465ULL, 0xFD3D535A0174C68DULL, 0xB75B1A72E2FC1A3DULL, 0x7BC1EC19A2703601ULL, 
            0x5E6C7D398F352C8FULL, 0xC65D8CAA51CFB022ULL, 0x6B2640BDFBB954BFULL, 0x35F2AC4DB7244150ULL
        },
        {
            0x8F3C41BD361398A2ULL, 0xE3531DD0F58CF938ULL, 0x0C411AE136452545ULL, 0x3BCD369F2D567ED6ULL, 
            0x67F8D24094E2CBF0ULL, 0x63F6E578738444EEULL, 0xEECEDF1A03AEFD3DULL, 0x435E021095AA85D0ULL, 
            0xF38D2776288BB85DULL, 0x8221D72E5A373027ULL, 0xD1567F31365E2960ULL, 0xE12DD1878054BFADULL, 
            0x7CACAA91E9A0134FULL, 0xCB266E572B665088ULL, 0xE106A16E9BBFFC40ULL, 0xF682B0BBFD1E2171ULL, 
            0x62D5FFB615FD5FDAULL, 0x60384A4FD520F0AFULL, 0x1DDA8984679555D0ULL, 0xB5034041337D14E6ULL, 
            0x002A2FAB9B496E22ULL, 0x2BB13D7299B247D3ULL, 0x4C707E649EC2C24CULL, 0x3C9DD985697B94F3ULL, 
            0x95084FEF6495B21CULL, 0x2013365746CA85D3ULL, 0x2A21013177871DF6ULL, 0x3F95B475AF1AA978ULL, 
            0x5B985C13CBC25C89ULL, 0x479D5B5875D19E83ULL, 0xA1B8C97B3C229ACAULL, 0x891D21CE1E4A35A7ULL
        },
        {
            0x6DEF68CD9AC33EB7ULL, 0x4E830FD70049BC54ULL, 0x20B8AB13ABCE4060ULL, 0xE9AE30237411A94DULL, 
            0x86BDE1A0E1D1B1D4ULL, 0xC3642D4B81EA2AECULL, 0x2AD66BEF2F23ED61ULL, 0x962AE78B1A57E31FULL, 
            0x3EA7D058EBD94CEDULL, 0x9507CFA65F925C4FULL, 0x0F11E0BC9E6087EEULL, 0x110B45ED47D4891BULL, 
            0x4926877148985CD7ULL, 0xEAD3A1F9F08589E7ULL, 0x48CE2C6D24D7B7DFULL, 0x4E92F6285D687B05ULL, 
            0x0252E24DC2B48512ULL, 0x23A04B55953322EEULL, 0x5FF0C6C78A99FA3CULL, 0xA98187CB19EA19D3ULL, 
            0x97FBC4D3214D3A3AULL, 0xAB404B7A0229FDE2ULL, 0xB1E621DE87A7D4F7ULL, 0xB73DCCD252022458ULL, 
            0xA47F757F0E3A2775ULL, 0xC692EBD4295A4A92ULL, 0xE9B8852D049CC37CULL, 0x3BA4C2F2AD448B42ULL, 
            0x2241D9DB27CC7208ULL, 0x50869A1DBEDD9406ULL, 0xB2F89277CEBCA262ULL, 0x1D6238079C7494FFULL
        },
        {
            0x9A83F794B24FC8E6ULL, 0xEC0CB692F7FF0D3CULL, 0x01577BBC63519EB7ULL, 0x3527800D6A43BBABULL, 
            0x74B310A4A4AA533DULL, 0x6245D91ECF656CBDULL, 0x23D892F959777315ULL, 0x8C2AA2DBA2DD60F3ULL, 
            0x91FA33A261967EB3ULL, 0x0614900DFA5A6A24ULL, 0x179F45495F7AEB72ULL, 0xF908289199E5092CULL, 
            0x988313831A265D90ULL, 0x36086E768B9DAD5EULL, 0xA7B018CD4D013615ULL, 0x648F49773889C5A3ULL, 
            0xD24FFB8C51ABE519ULL, 0xE4E371F73154EEA8ULL, 0xE2353627389C178DULL, 0xE1FE89519CE497DFULL, 
            0x929F5FA831C86557ULL, 0xB4D1C43CEAEC4A14ULL, 0x888E5516920C7C2DULL, 0xEBA8AFC436862DE3ULL, 
            0x6A6F4DC6D44A067DULL, 0xA9897A97508D9589ULL, 0x9EC4344CD252C62EULL, 0xA345CF84FE012858ULL, 
            0xB5F5E4D8EE703225ULL, 0xFB95193E8965F9CBULL, 0xA07DBB0AABD4DEB4ULL, 0x2C92221E074AA8E4ULL
        }
    },
    {
        {
            0xC58BEDF6B1B46C7EULL, 0xD725FB44676530DBULL, 0x26FF4DE1C7583E62ULL, 0xA5066662EAD60009ULL, 
            0x3403BCD1E44A9174ULL, 0x7C55C67476E88EBEULL, 0x275623FC44FABB09ULL, 0x768FC5F53955BC4DULL, 
            0x232A259176CB8B46ULL, 0x6F50E11FA5CA9D74ULL, 0xA4BDDD14E8041414ULL, 0x1616F1D9EFF1B0E7ULL, 
            0x88581D67E31662FCULL, 0x8084628B1DDD18A8ULL, 0xBFA1385DB593D216ULL, 0xF29B490F7C58295AULL, 
            0x9A167E33C9E4DEAEULL, 0xBFC29B2F98CA055CULL, 0xF75A361535F322ECULL, 0xD1DE7E64FA87597EULL, 
            0x2995DBD50BFC8F24ULL, 0xC5D2EF5DA979F8AEULL, 0xE35A0454D269F0A6ULL, 0x4B725C12445FB208ULL, 
            0x97E5F1337C4415D9ULL, 0x88385235E80ACD3AULL, 0x4AF34B927DC31FD1ULL, 0x4C11968A7AD5DBF1ULL, 
            0x147CA853452DA70CULL, 0xF01EAE93FC9EEDB5ULL, 0x3B363421891D203BULL, 0x383102B6469BCE5AULL
        },
        {
            0x5ED9326F7F26C8A1ULL, 0x1238F297E7C42CC2ULL, 0xB470D52407158E1CULL, 0x4E29233CE0183DEBULL, 
            0x41162A0E297AFA91ULL, 0x34B8AF768F523CB8ULL, 0xF510832C7CA97512ULL, 0xA35EFBE02E8A4C91ULL, 
            0xE2D2A9ABADC18437ULL, 0x4676B214AC9A3815ULL, 0x7669BF645AF1318AULL, 0x6AF39BB9AC309225ULL, 
            0x1CD79D8280550D8DULL, 0x7A1FFB5671576A1BULL, 0xE88CE83B17B946E5ULL, 0x6F15A025DE3FC332ULL, 
            0x2484CE3D295B8EBAULL, 0x15BF5E8AED0A5ED4ULL, 0xFD8241448BF6A651ULL, 0x27D7B8B837B09717ULL, 
            0x526EFE51E0455CB1ULL, 0x413F928DB3E153D6ULL, 0xAD851836FAA3BD1FULL, 0xEB44034D51F38634ULL, 
            0x9267F90A6DEF78CCULL, 0x7B706F92C5A5895CULL, 0xAE6CA735CA814436ULL, 0x02A7CA649809E085ULL, 
            0x7FB4726958127BE8ULL, 0x09313B4D7D88EB12ULL, 0xA686FEE551C55A53ULL, 0xD5926E3FE9C38F88ULL
        },
        {
            0xDC0DE3CB72620A7DULL, 0x1737C171E0E7C782ULL, 0x08F6E6211FC94231ULL, 0x789B72A83CA192C0ULL, 
            0x6D759A98AC37581EULL, 0x5A70CA35EA31E28DULL, 0x2A4F4625DC7A4250ULL, 0xD647D09355C059BBULL, 
            0x0BF49EEE7A6A7693ULL, 0x7E8C4EBA9EA10FECULL, 0xE2B6F752A9139D5DULL, 0x6132A2FBB5128E6BULL, 
            0xD248170F673EEB95ULL, 0x63C509F46C77F6CCULL, 0x0591814CFA73A7EBULL, 0x36C89A2A7FD44B99ULL, 
            0xC40092B1D943FEE5ULL, 0x162F4CF8CA7A4AE2ULL, 0x9D09D0634209702FULL, 0x8FC8EDF1E199348AULL, 
            0x6445AB05C380340BULL, 0x3305F35ADB92BFAAULL, 0x1876F659F3E66EBAULL, 0x0EF023D0000772AFULL, 
            0x78E7E021B687464DULL, 0x0F4F43BF3FBF0F0EULL, 0x90B4D9230BC915B1ULL, 0x1074FF527DA2D424ULL, 
            0x15C328EC6F2A8A25ULL, 0xA4D98E4AB389766FULL, 0x405E4A7367A6E598ULL, 0x1D4F506C0154E663ULL
        },
        {
            0xB1A9A058B2B0119DULL, 0xDE1653E6A51D9596ULL, 0x768E95964B523324ULL, 0xB3469E03BBB76D42ULL, 
            0x3DE832BA7142561EULL, 0xCD185F16BD63A220ULL, 0x5514FE5B95F59772ULL, 0x44ADE3B4B13E287EULL, 
            0x868F50BA84DBF1ACULL, 0x90479D2328FCF059ULL, 0x5EB786B01787098BULL, 0xC95CDD95F05DA17EULL, 
            0x8E2A5DE8D8E4EDE9ULL, 0x7FC51A99EC593A8BULL, 0xC20D20DFDEF04D27ULL, 0xD304F049F01F09EEULL, 
            0x43F8FE1B77EB1831ULL, 0x5BCB315BA15B4D1CULL, 0x1E502A9DD74C74A1ULL, 0x60B38776017F19F3ULL, 
            0xF4DD53DD41EC0B87ULL, 0x8A9C513BA1864AC5ULL, 0xD0693C05B448C2F0ULL, 0x02901B3544E2E7A0ULL, 
            0xB31F205127299B5EULL, 0x6E34E01EE8BDA607ULL, 0xDF04368F066470DAULL, 0xF0FD78C37B4B48E4ULL, 
            0xE5C055836B1C9313ULL, 0x941470C2C7CCD603ULL, 0x9F3C6DA9DA27CCC8ULL, 0x4282CAF632AEA498ULL
        },
        {
            0xA7CA3EB035268C81ULL, 0x11A3D9ED54B31114ULL, 0x50D616DC6F31436AULL, 0x6B8B97C0A71C4928ULL, 
            0xC381FB72B5757844ULL, 0xAB5F48F02ADE65B3ULL, 0xD0365BCF21026B60ULL, 0x6F469ABE3252B850ULL, 
            0xB10FC887F3B4E6C2ULL, 0x3CF91CA00C02D447ULL, 0xD35210DB86E91958ULL, 0x3A26C7E706B5B67BULL, 
            0x06FF748B8F0E380DULL, 0xDC62DA1733340093ULL, 0x50A3781292649FA2ULL, 0xDB3F512CE83612E3ULL, 
            0x94F2095E56F52707ULL, 0x7B0DC242D0088BF5ULL, 0x63EC4E62EB7E217DULL, 0xD1FEDA704BA808B1ULL, 
            0x2DBFA374587ADD53ULL, 0x245501EF7D3EDA50ULL, 0xA9A69C8607A59699ULL, 0x6633235C05C85DC1ULL, 
            0xFDA43FF9998878FFULL, 0xC833A989E5DF40F5ULL, 0x9964E7FE66C9E8C8ULL, 0x97FCA7F304328302ULL, 
            0x1BDE3A2731DF74CBULL, 0xD41B5629B1255F94ULL, 0xA2E36F7E40684657ULL, 0x7AB34FADE234D672ULL
        },
        {
            0xD067C54EBA372B38ULL, 0xB22D0E08F5CAE173ULL, 0x7ACEB0659F58BA87ULL, 0x2DD744923E1C5EE5ULL, 
            0x8D3F95DCC94682EFULL, 0xF707254E924B45FAULL, 0xD68B524860CA547EULL, 0xECACE1ACEF0672CAULL, 
            0xAFA7303DD4AA2F40ULL, 0x2B59D6E612C2B661ULL, 0x58B0E148FAECE737ULL, 0x2A88A6505369EE72ULL, 
            0x37483A60E8EFFD49ULL, 0x1C46AB6B862B307DULL, 0x7F699ED37229DB4EULL, 0x27FFE9A77B6A7B59ULL, 
            0x7E14672FF56F1934ULL, 0x5F90B4176675D23BULL, 0x059CF96F43892027ULL, 0xAB49DC298BC5CEA9ULL, 
            0x97831B7DE6E1444BULL, 0xBAD7C82BD1CA9C8AULL, 0x64F792A9A081C5AEULL, 0x59EBE9E959376456ULL, 
            0x42D87D376E4D99ABULL, 0x0ECAF12485DDBFAAULL, 0x20DA35A94846A122ULL, 0x46DA70CFF7027EDDULL, 
            0xF9E0FA413DF019FFULL, 0x4DAE6175EB092740ULL, 0xD63AC12BA2169989ULL, 0x59C84CD278F23550ULL
        }
    },
    {
        {
            0xADCAC66E03500DA3ULL, 0x664CA63D428E20DAULL, 0xA5240D6FD0A3113BULL, 0x7A37A46F385225AAULL, 
            0x087C35FA55AF0E5CULL, 0x96E89FF6FC5BBD48ULL, 0xAAB1A09B6B5CEF2EULL, 0xF516D7050D61BB8FULL, 
            0x518F386E2CD089FBULL, 0x2D20BD7B817B5B7BULL, 0x627847488DC23EFFULL, 0x8776A5CC51A8AA27ULL, 
            0xEF45DD53460FB49FULL, 0x15FB1B32B2C163B5ULL, 0xCF5961421827EDC1ULL, 0xB8603C884A57C491ULL, 
            0xDA653B75048183BCULL, 0x45850135A4550CE7ULL, 0x8B904B9D2CD21365ULL, 0xB70843DF1E384C84ULL, 
            0xA0E94736C8A67595ULL, 0xE715263AF078A67FULL, 0xA9214D0BA6FD7D30ULL, 0x7EE4FAE09A7A2BD2ULL, 
            0x42C4B36ED3E45E0BULL, 0x9078FFF909F41AABULL, 0xACA68AC20C00CA4AULL, 0x127E6EA34BC4892BULL, 
            0x11B9511428AEF7BEULL, 0xEACD3148C25D3938ULL, 0x17877459E2AD7A53ULL, 0x8A1C6FB7FB4B4E50ULL
        },
        {
            0xF8355EE5CE7595E3ULL, 0xCBD1DC2150650096ULL, 0x21491CEE8FFCC8CEULL, 0x6D1A217F71FC3E8FULL, 
            0xD8811C835913C310ULL, 0x1A79E89C6657DA98ULL, 0x382DD0E62F1DA110ULL, 0xA67A65D3D1E0095EULL, 
            0x906F226124140690ULL, 0x6D6D5F9CFDD26432ULL, 0x76B0B6B9F5FA772CULL, 0x95653DE953DDAB5FULL, 
            0x239D0DC43467AF8AULL, 0xFBE335EDAAC1590AULL, 0x3E6475FB2730A5C0ULL, 0x2799E11696F43056ULL, 
            0xA6C1FD90DF45EE2DULL, 0x96AEAC48E74FE8F3ULL, 0x2FF9CA036F66FAFCULL, 0x6F7D1ED62AFCE261ULL, 
            0xB198855D5D2FDC70ULL, 0x24A6967F8C4365B8ULL, 0x12BA1D68068577EFULL, 0x3D03303A40687BA9ULL, 
            0x781C26273648F2B9ULL, 0x31542F86318B7020ULL, 0x77E80EAC04506763ULL, 0x22ABE9C2A4B5031BULL, 
            0x53A3C10F486AB2DDULL, 0x702EDF339BFC3301ULL, 0x7C61441A5D38B791ULL, 0x44879A901282FE3FULL
        },
        {
            0x4FDE48C48FC6C246ULL, 0x2784011089D95DA4ULL, 0x0AB94C28C904AAF9ULL, 0xAECE98418CADF7F0ULL, 
            0x87BCAF437FBB7E8AULL, 0xDFB3488944C0485DULL, 0xC791923B82E2DB62ULL, 0xAF1962BDE76FFFB4ULL, 
            0xD432464432EB04B5ULL, 0x428A18E8E6C1F11DULL, 0xD6D2197DEA7446F0ULL, 0x731852D1A6E0B043ULL, 
            0x8DD8559D5F6D8326ULL, 0xA1F25E13853BF2F4ULL, 0x09C92558FD481A40ULL, 0x24C3185B1AF69835ULL, 
            0xF1DDB87BECE8D38AULL, 0x43500AD1816B6C2AULL, 0x28B87A9C9A942ED9ULL, 0xD114DEE04060C934ULL, 
            0x46BC8A822933B134ULL, 0xC7FA2D492BF635BDULL, 0x3DCDE28C03EC88E4ULL, 0xD7D4500E0CDFC099ULL, 
            0xAEA42623E35C5C46ULL, 0x17676B1DB8F7ADACULL, 0xB29F4DE90D7C9E4AULL, 0xA1494B73A811A9DAULL, 
            0x0A5B55BDFC232938ULL, 0x5A8B115AB03590D0ULL, 0xFCEB9F19092ED44DULL, 0xF9230164A266E8C1ULL
        },
        {
            0xB1E43232598F37E3ULL, 0x83710FCA93A35228ULL, 0x9AD878B95192CA77ULL, 0x3AF958F3A8085B2FULL, 
            0x025917C88BE99E03ULL, 0xE1D416099CD0EDEAULL, 0xEE02E21C5542E47EULL, 0x4008E17948AC5A59ULL, 
            0x850544A747E8E513ULL, 0xD270DC1742E71334ULL, 0x1C41A3B96A36D656ULL, 0x9AB304B2E4B0EECBULL, 
            0x7DB1EA13FBE91AB4ULL, 0x790D0F8929743CBEULL, 0xAB61E6BE2A2245E5ULL, 0x9B6AD8E8D54CE102ULL, 
            0xFF1E3B2EB30995CCULL, 0x303E8BA8823C5A07ULL, 0x51930796BFFF0734ULL, 0x52604FC1D1793D9FULL, 
            0x8B0E68F1D47747ECULL, 0x409C419C6F2286D9ULL, 0x831B55294038C7EBULL, 0x982382D19FF4A8D8ULL, 
            0x2B219CD099C6E98AULL, 0x24E24D0BBA4D4D94ULL, 0xCEB3B47E83D8EE3BULL, 0xB11139F3B8B30518ULL, 
            0x47977175C08ADD6BULL, 0x5E0B1C1FE874430FULL, 0xD3FAAFEF7327D510ULL, 0xD0FD21C84AEEA7B7ULL
        },
        {
            0xCB619E67F0A9E507ULL, 0x48EA4C72C4532E37ULL, 0x384D1FEBB7686589ULL, 0xDFD514F11ACBFD3DULL, 
            0xB221799D4F3D93D3ULL, 0x7114208C085FB680ULL, 0x8069BD99C96D0E23ULL, 0xB5A23EADFB7D437EULL, 
            0x6DAEE34F13D57D13ULL, 0x38845AE64197FA78ULL, 0x23E850AE8D7CB17DULL, 0xE7813F14B57B154CULL, 
            0x0B54A12113184525ULL, 0x42BDECE72776C282ULL, 0xC2C15B129CFB9D44ULL, 0x73DA580A15868290ULL, 
            0x9D34A73BECC667B4ULL, 0xD275B691E1A9E28AULL, 0xB3E070A5F116CCF7ULL, 0xEAED8BA2908315ABULL, 
            0x19E1F91DCA1C2108ULL, 0x6B686B7EC399FD41ULL, 0xF851E448DD8537BEULL, 0x8332D4409B0B5C53ULL, 
            0x6B1CC988DC4AAA07ULL, 0x1424C233B569B387ULL, 0x4DC1C617126B641AULL, 0x4BEAFDD34576AB3AULL, 
            0x095F77C6568371A8ULL, 0xD5ECAD403D93E612ULL, 0x71EE718E1CF6D042ULL, 0xBA0BBD45E595A0C0ULL
        },
        {
            0xC3209AF7B2E3A603ULL, 0xFA52C0C98DD1D2C8ULL, 0xAB626099DA7EA37DULL, 0x1F90AD6AC0121863ULL, 
            0x0130B87F6C9338C9ULL, 0xFD7796199AD76CF2ULL, 0xE86E259093B9AF6FULL, 0x7617BBE2BAE1AF98ULL, 
            0xC2475E6DBCAB015BULL, 0x617F3FF19C3253B7ULL, 0xF91FBCC076B29435ULL, 0x20012568CBC06D92ULL, 
            0x637FF614073C139DULL, 0xE526EB6190BE59BBULL, 0x4C8D8CA64B36E534ULL, 0x73375A70F9D0DFE0ULL, 
            0x99C67B5FBB771C97ULL, 0xDA96FDFDF0274B24ULL, 0x4A9DB0C6ED833EACULL, 0xE81E35DA8172DD88ULL, 
            0x2C70F58EF8B04EF5ULL, 0x9C63073BF45A7316ULL, 0x7350C85634F3A25FULL, 0x182B958E6E5A93C1ULL, 
            0x5DE9516548DD8DB3ULL, 0x01EF9E8672EBFAF2ULL, 0x02B2762149221C4AULL, 0x192AE5BFEEAB6E8EULL, 
            0x9E42FF33277FAB3EULL, 0x22898EBEE21B0067ULL, 0x55B04DA25FE5F6A1ULL, 0x09C388CE3374CCD3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseHConstants = {
    0x5392C45802FF5B1FULL,
    0x2A08D6416C1FC148ULL,
    0x63780D498EDDA5ADULL,
    0x5392C45802FF5B1FULL,
    0x2A08D6416C1FC148ULL,
    0x63780D498EDDA5ADULL,
    0x17DE45E9306988AEULL,
    0x938A4AE9F60B7BCFULL,
    0x5B,
    0xF3,
    0xDE,
    0x60,
    0xC0,
    0x6B,
    0xD9,
    0xD6
};

