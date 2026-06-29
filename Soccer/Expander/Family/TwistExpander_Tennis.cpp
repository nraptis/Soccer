#include "TwistExpander_Tennis.hpp"
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

TwistExpander_Tennis::TwistExpander_Tennis()
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

void TwistExpander_Tennis::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD7EC16B14480FCD1ULL; std::uint64_t aIngress = 0xC2FC469C3FF20D39ULL; std::uint64_t aCarry = 0x852BE43B89FC05F4ULL;

    std::uint64_t aWandererA = 0xEAB41DEEC0B33D73ULL; std::uint64_t aWandererB = 0xFE6E1441CFABEF3DULL; std::uint64_t aWandererC = 0x9986E54731FEAD68ULL; std::uint64_t aWandererD = 0x91144E8F12D4BCCAULL;
    std::uint64_t aWandererE = 0xB16742B61EEAE6AAULL; std::uint64_t aWandererF = 0xFA0FC05E4E3A4334ULL; std::uint64_t aWandererG = 0xC0AD36B83887C826ULL; std::uint64_t aWandererH = 0xB012EB73F5CD8970ULL;
    std::uint64_t aWandererI = 0xC64D33CC412D1688ULL; std::uint64_t aWandererJ = 0xD39C75B2A9BD27AAULL; std::uint64_t aWandererK = 0x983D594D7C63ACD6ULL;

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
        aPrevious = 12143205386126337305U;
        aCarry = 16169518793766327086U;
        aWandererA = 15888449207238790148U;
        aWandererB = 9529162811209529561U;
        aWandererC = 12085732836281402961U;
        aWandererD = 9275948102011747386U;
        aWandererE = 16054939455627596078U;
        aWandererF = 17778105425593908461U;
        aWandererG = 9782448873592426789U;
        aWandererH = 12376112892059858659U;
        aWandererI = 12268314517072112973U;
        aWandererJ = 11749265571387058059U;
        aWandererK = 17066148097519760483U;
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
    TwistExpander_Tennis_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Tennis::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x99CAC5E1A93F4DB5ULL; std::uint64_t aIngress = 0x9737450316D62A09ULL; std::uint64_t aCarry = 0xF1A31D6CFDA581D9ULL;

    std::uint64_t aWandererA = 0x9118C6A64FCDC693ULL; std::uint64_t aWandererB = 0xE366DB4C87975EEEULL; std::uint64_t aWandererC = 0xB90385B7AB2FB8E7ULL; std::uint64_t aWandererD = 0xD2D3439146012AABULL;
    std::uint64_t aWandererE = 0xF8904D9427582C01ULL; std::uint64_t aWandererF = 0xF11091548AF48182ULL; std::uint64_t aWandererG = 0xA070D06E29AAD665ULL; std::uint64_t aWandererH = 0xB7D23A9E56EAC8FAULL;
    std::uint64_t aWandererI = 0xF0391F24FC12DB7EULL; std::uint64_t aWandererJ = 0x8FE0F3CE3D3C298DULL; std::uint64_t aWandererK = 0xBF7579C1AE314F56ULL;

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
        aPrevious = 11624323534130530713U;
        aCarry = 18043038513619044472U;
        aWandererA = 18161837435182974439U;
        aWandererB = 14921712127591381220U;
        aWandererC = 18219066054103109050U;
        aWandererD = 17545983262273939709U;
        aWandererE = 16733607024003952718U;
        aWandererF = 16907720341844234386U;
        aWandererG = 14985774452553971545U;
        aWandererH = 10743421050139080978U;
        aWandererI = 12070795427058155266U;
        aWandererJ = 10544021322237016308U;
        aWandererK = 16142143532341991443U;
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
    TwistExpander_Tennis_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Tennis::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCDF3034529BE4207ULL;
    std::uint64_t aIngress = 0xF26A2387A0938A1BULL;
    std::uint64_t aCarry = 0x8F356742F6178FEBULL;

    std::uint64_t aWandererA = 0xFAF96CF3DBEA74CCULL;
    std::uint64_t aWandererB = 0xD2DE6FEE8C19912BULL;
    std::uint64_t aWandererC = 0xE4B90FBEFE91CAA6ULL;
    std::uint64_t aWandererD = 0x9536ECC2D559B1F6ULL;
    std::uint64_t aWandererE = 0xCDC61EB83F8E72ADULL;
    std::uint64_t aWandererF = 0xF95510D4C1231785ULL;
    std::uint64_t aWandererG = 0xC7D7F4D71C6609EAULL;
    std::uint64_t aWandererH = 0xC31209400FD8CA5EULL;
    std::uint64_t aWandererI = 0xE5FFDE457980EC3EULL;
    std::uint64_t aWandererJ = 0x9E0F4B72BD712DE2ULL;
    std::uint64_t aWandererK = 0xC091E51E1E86B865ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneB);
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneA);
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Tennis_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Tennis::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Tennis::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8F3B4737329A8796ULL; std::uint64_t aIngress = 0xB2B5EC3816096C0FULL; std::uint64_t aCarry = 0xF87C51252F5417F4ULL;

    std::uint64_t aWandererA = 0xE4723909450C6B03ULL; std::uint64_t aWandererB = 0xAFD946F3BCB8F496ULL; std::uint64_t aWandererC = 0xFDE3D6A1B8AB1130ULL; std::uint64_t aWandererD = 0xC94838D322F77DB6ULL;
    std::uint64_t aWandererE = 0x865A1886EE5B62D1ULL; std::uint64_t aWandererF = 0xF3521E7090FF0875ULL; std::uint64_t aWandererG = 0x9242F0535DF1080BULL; std::uint64_t aWandererH = 0xF65FD49BE95D563AULL;
    std::uint64_t aWandererI = 0xF22D0D96D11D81F6ULL; std::uint64_t aWandererJ = 0xBC542BFFFBA426BAULL; std::uint64_t aWandererK = 0x85B31A2A52DF0E97ULL;

    // [seed]
    {
        aPrevious = 18065080460140071571U;
        aCarry = 18065697727213031866U;
        aWandererA = 12176164035787589592U;
        aWandererB = 13745808852261009324U;
        aWandererC = 16190138904481051946U;
        aWandererD = 16166324261415778772U;
        aWandererE = 17843748313940761859U;
        aWandererF = 17137530844021702379U;
        aWandererG = 17695954528576821310U;
        aWandererH = 15175471452070456724U;
        aWandererI = 12301399385390385374U;
        aWandererJ = 11721185134549003670U;
        aWandererK = 11181171344150507841U;
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
    TwistExpander_Tennis_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Tennis_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Tennis_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Tennis::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 0 with offsets 5066U, 329U, 4442U, 3675U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5066U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 329U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4442U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3675U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 2, 3 with offsets 3927U, 1331U, 2306U, 3027U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3927U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1331U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2306U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3027U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 1 with offsets 6001U, 6901U, 3947U, 6547U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6001U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6901U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3947U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6547U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 2 with offsets 7320U, 7562U, 5412U, 4932U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7320U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7562U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5412U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4932U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 with offsets 98U, 1509U, 1082U, 398U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 98U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1509U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1082U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 1, 0 with offsets 1369U, 832U, 669U, 99U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1369U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 832U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 99U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 1, 3 with offsets 1494U, 1149U, 726U, 1512U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1494U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1149U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 726U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1512U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 2, 1 with offsets 1414U, 572U, 680U, 554U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1414U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 572U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 680U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 554U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 751U, 1638U, 485U, 1494U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 751U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1638U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 485U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1494U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Tennis::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 3 with offsets 4798U, 4589U, 1282U, 6299U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4798U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4589U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1282U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6299U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 2 with offsets 2124U, 151U, 4216U, 6777U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 151U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4216U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6777U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 0 with offsets 1245U, 489U, 6570U, 6242U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1245U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 489U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6570U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6242U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 1 with offsets 2895U, 3013U, 2146U, 4397U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2895U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3013U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2146U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4397U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4673U, 6046U, 6949U, 1732U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4673U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6046U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6949U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1732U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1742U, 304U, 1363U, 1422U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1742U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 304U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1363U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1422U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1861U, 572U, 1847U, 1655U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1861U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 572U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1847U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 155U, 1146U, 831U, 1743U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 155U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1146U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 831U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1743U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 627U, 62U, 461U, 1284U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 627U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 62U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 461U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1284U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 [0..<W_KEY]
        // offsets: 2010U, 664U, 870U, 1566U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2010U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 664U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseASalts = {
    {
        {
            0xC4471E952C11621FULL, 0xC07AB1C4A34B3D06ULL, 0xF5DEB8834D241102ULL, 0x9A0391D97143768EULL, 
            0xE56F66DE0EAD1B1CULL, 0xF71A5246E60CEBC1ULL, 0x2DA3DC5210C0371EULL, 0xEDD8C405749B58FDULL, 
            0x5868D6F636F996E7ULL, 0x077D1E574AEA4D80ULL, 0x4CD1FC2B48A7A837ULL, 0x468A86355562E4EDULL, 
            0xEE1E7136C8F21C15ULL, 0x71C72EA95BC6FA61ULL, 0x627334211F5359A0ULL, 0x49428A038DFE49D1ULL, 
            0xD979A73DC436F4E4ULL, 0xDA321422DDF9B04EULL, 0x0992C2F0CA026652ULL, 0xCE17BECD191413CFULL, 
            0x5B81737172304262ULL, 0x3D3CBE0DBAAA196BULL, 0x81429F2100D4FA27ULL, 0xCDC79F60D120B7D5ULL, 
            0xBC3F0448EBC0B6D1ULL, 0xF1110469116838C6ULL, 0xF37C03CE20E1ADD3ULL, 0xEE7E9009B959A32CULL, 
            0x10DA590EF58C5CD3ULL, 0xF60104FF52C7C8A3ULL, 0xE10B994C41D0C41AULL, 0xCC847FBA48628A8FULL
        },
        {
            0x94BB577FE2EA7E22ULL, 0xAB2675CE01634D57ULL, 0x7AFACE46266DBA4DULL, 0x80AA99265EC3A0B5ULL, 
            0x32EC4A3E03AC041BULL, 0x1FE6BEE6B58812DDULL, 0xC4EAE5707FF78E9CULL, 0xDCE46EAB2790EB9CULL, 
            0x957F545E6172C63AULL, 0x0E1F2D00743AB38AULL, 0xFD5E65BAC48782E1ULL, 0x13B7C29FAF8307D5ULL, 
            0x558F93CE69DB7ED5ULL, 0xE366E19AC44E61B1ULL, 0xE6680AB7AD7DE247ULL, 0xAEFD5C4C415C23F6ULL, 
            0x4B9B9992E5DCA54CULL, 0x9140C1B97A9BEFA7ULL, 0x4816336239C0B0E3ULL, 0x43F3E7B3B61E85E9ULL, 
            0x176D2B084FCB4FFFULL, 0xAC783FFE98B88BF0ULL, 0x449F937E7A43AFEBULL, 0x26FDFBDA0A22E227ULL, 
            0x9310501DFEBFA9AFULL, 0x226A62BF08407819ULL, 0xA696EE45A11FA172ULL, 0x967E98E1D9FA554BULL, 
            0xFCA029C4997AF143ULL, 0x5A6416BE313F9219ULL, 0xE0152D22B8314AFEULL, 0x75B2949331F819ADULL
        },
        {
            0x410BD0D9A9616AA8ULL, 0x0C8D80AAE521A62BULL, 0x095DEA642451087BULL, 0xBE3D0D27E336521AULL, 
            0x3A27B1AB2D28796BULL, 0xBE46C3C05B1491D0ULL, 0x6BBE2F5B51104CB5ULL, 0x8EB6ECDE1A2B1F90ULL, 
            0xF9626E2BA179440FULL, 0x2C0710C0693DE6F5ULL, 0x180BE907B10459F6ULL, 0xAE173BA697FB8E78ULL, 
            0x67C6B9AF3762295FULL, 0x707EEB5383DD4E7FULL, 0xD0BD3FCF00E93837ULL, 0x27EB893DEC9AA852ULL, 
            0x9282576DAB340CB1ULL, 0x13D5668EBDB281D4ULL, 0x7193B951AF6BFCC2ULL, 0xCBF588D78F4AE658ULL, 
            0xC31CD0A816D91DC2ULL, 0x707E41913F04D144ULL, 0x8B4865D16A998D01ULL, 0xD32741ED13272978ULL, 
            0x98D92D92B59F1466ULL, 0x9D5A033D67DAE8A0ULL, 0x6911800194487F74ULL, 0x58869FFA71DF6BE1ULL, 
            0x43777ABC79A147DCULL, 0x144E51A3599D1615ULL, 0xCAB92D057B52622AULL, 0xE52DDF961DE8FA36ULL
        },
        {
            0x79A4FCE71251CE62ULL, 0xF9E4C09C12E5DF14ULL, 0x39987C2ED06E04B0ULL, 0x44DAA447BC1552E0ULL, 
            0xC223A56FB1AEFE4EULL, 0xEDD2E0FB7FBE09A7ULL, 0xA9AEE87793D1634BULL, 0x53BA26108663D7A8ULL, 
            0x1C36E4E54BAC8011ULL, 0xDF541625B0919BCDULL, 0x9287613988D64A11ULL, 0xF11C00ECD393D37AULL, 
            0xBA06EC852DEB2A74ULL, 0xC0CBC7DE01DF1483ULL, 0x7E4D4A9E908A3DB1ULL, 0xDDA65EDA5EF50569ULL, 
            0x76E299A1F887FA13ULL, 0x48C404E990306DBAULL, 0xEC241D7C973646D4ULL, 0xCD314488EBE724E5ULL, 
            0x69AD3EFE1DA8B77EULL, 0x296E26C3E58CD10BULL, 0x219921E4BEE436B0ULL, 0xAFE0D1519B7B6C98ULL, 
            0xD2A419227570AC0BULL, 0x34F580C5923227D6ULL, 0x47DF62284206305FULL, 0xA8A8FEE310132713ULL, 
            0xEC970497C46BC3A7ULL, 0x26E0AD077E4C1EA6ULL, 0x2E83A7F668CBABA1ULL, 0x81E7C817F7295E62ULL
        },
        {
            0xCB041DF116B303B8ULL, 0x411DC6D0DCD05B86ULL, 0xA69FBF9E59B09031ULL, 0x391199090FEE1A0BULL, 
            0x8BC77CBF3F2AE523ULL, 0x7C9E239444549FB2ULL, 0x04E65D00BA54C037ULL, 0xC0C113F23052B2DBULL, 
            0x52512C33672FB38AULL, 0xF35FD7CBAC3FE473ULL, 0x5578E6EA1E0A9F51ULL, 0x91ADFB05DF8A7678ULL, 
            0x848173BD36DD224DULL, 0x61F1BBC36110B8F8ULL, 0x54F6C8D7A6A47B54ULL, 0x091642DE43DE7042ULL, 
            0x87D22C96A6C88FADULL, 0x9625ED3C2654E851ULL, 0xF659888CEB8135E1ULL, 0xDCA6830709628032ULL, 
            0x142D13A67840423EULL, 0x7EF4DFBA72A7FD68ULL, 0xFF8C99B7CC39FD27ULL, 0x086E7F49260732E4ULL, 
            0x83FC76FEBD625A9CULL, 0x8C61416EA59889BAULL, 0x1D71C64A11B2E60AULL, 0xDBF313373E59CAF6ULL, 
            0xBDBF2D87BE48F69FULL, 0xF77CEF56397EA0C0ULL, 0xDA7584048BEC8924ULL, 0x17672D9E62343BBFULL
        },
        {
            0x23DCFEF25C536BE3ULL, 0xA854B03CA3AF0B34ULL, 0xD5EBA5B63074BA6BULL, 0x12A4B995A6B471D5ULL, 
            0x69286AE449F7A891ULL, 0x0543582A262F020AULL, 0x8F7CCBA246EB7827ULL, 0xA89A3601AD326870ULL, 
            0x3008CEE1ABE5E84CULL, 0xF79A4A645193D589ULL, 0x33EE176150CD928DULL, 0x12A0A9A6202F8CDEULL, 
            0x1A0E49B2585BB4A3ULL, 0x94752075C1F49285ULL, 0xC5F4D3E394662E1DULL, 0x53EE61A317BB7D6AULL, 
            0xD2DC740F90AA2647ULL, 0x999D4BCA021BDBB3ULL, 0x790FE612D039BDE5ULL, 0xDA9898C64E8C6320ULL, 
            0x0C23C24C61296F77ULL, 0x14FAA2F610364C3BULL, 0x0C620FA91B352FE8ULL, 0xF8705F2B12261D10ULL, 
            0x28DBB20267DC7C91ULL, 0x0BC280E13FED273EULL, 0xDB81F99EB35B897FULL, 0x26EDC423016E70F1ULL, 
            0xC8A17A2A33B65A93ULL, 0x469E323BB06E14A6ULL, 0x7CD6D01D2DF7303AULL, 0x8958BFC0A8DE464EULL
        }
    },
    {
        {
            0xD122BE8A1764874DULL, 0x6D326F951F820C91ULL, 0x7C12D43F9819110CULL, 0xB42107C2A3EFCA0BULL, 
            0x87C54A22C7D5C71CULL, 0x949F294EE07DBB76ULL, 0xFB9D12B09CC67392ULL, 0x50EFDF09C6C8A897ULL, 
            0xBDC14B3612F7300BULL, 0xABA833464A825C2FULL, 0xDEB74A8C133D2A3CULL, 0x582566074DE86D64ULL, 
            0x31F8288AD229083FULL, 0xA201324D1AB7F0D0ULL, 0xF1255E820B428C17ULL, 0xF0A71417EBB917D7ULL, 
            0x815ACD212995ED1DULL, 0xB296B8E96C502EB2ULL, 0xCFD219A51AB484A2ULL, 0x4D820BE14D6D3B36ULL, 
            0xDA66EB6D17269777ULL, 0xAEE34EE899BE71D2ULL, 0xC2338F818E09DBDDULL, 0xDC2CF87DB45EC182ULL, 
            0xE925427BFBF87FB4ULL, 0x34B43F742719F71FULL, 0xFC64AD65B78FA30CULL, 0x22E31DB582B0C2B4ULL, 
            0x483F6E7C01839E82ULL, 0x69681FF4D1FBF484ULL, 0x36626B0CF77F0AC1ULL, 0x35D16D3ED33B0DA1ULL
        },
        {
            0xEF6C6B0658159CC2ULL, 0xC2619F928AFAE756ULL, 0x3910615C7F289F86ULL, 0xBB640577B2985689ULL, 
            0x753A338E9D16BD28ULL, 0xE0FFD4FDFEC3532BULL, 0x733D7DA1BD6B918EULL, 0x3CF6258C728154ADULL, 
            0x0AFD28E46C265676ULL, 0x1218E02F7E2798A9ULL, 0x4723D695A692BA4EULL, 0x09197B1C27370D7DULL, 
            0x0A5D0746D3CDBA66ULL, 0xED58597C53667E6DULL, 0xACAA5C98F93F2672ULL, 0xA434522BA93E80EBULL, 
            0xE0CB55176A995CDEULL, 0xA4F055AAE2AA0209ULL, 0x2D44558E89309B80ULL, 0x38339B9EFDE712A6ULL, 
            0x58DE5F842357B692ULL, 0xC8F3455E2DF1C299ULL, 0x7E2A5FB7B1BBEFE9ULL, 0x1646A35F5A0D23D7ULL, 
            0x0FC149837F22962FULL, 0xDB659A3DC0379485ULL, 0x41AC6BC1A0A7F341ULL, 0xA5DEE728AA2FA93DULL, 
            0x9F717A9276FC2633ULL, 0x752A5CEF61CCB959ULL, 0x19CDAED837A70E02ULL, 0x7B4D7CA3637276D0ULL
        },
        {
            0x4263832A2CA5321CULL, 0xDE9584EDE190A9F7ULL, 0xEC08BBB728EC6041ULL, 0x6871A947132A3A56ULL, 
            0x6C9A8C43565A6A42ULL, 0xBDB0B82F3CE34068ULL, 0xF58BA119714A89ABULL, 0x3344D1B7169B804FULL, 
            0x93C750B10C2BC0D9ULL, 0xD4DE85978E093F1BULL, 0xDB6CD4260660C171ULL, 0xBB9B95D103E998D7ULL, 
            0x3C8A8104117656BEULL, 0x05C2C9FF3457EF46ULL, 0xA04FE2E9963533AAULL, 0xE0D6D36835B363FBULL, 
            0xB7A6CD2A280DA7BEULL, 0x69FEBBE6A37AE023ULL, 0x9A2983047954CB21ULL, 0x8AAFEFE98D6229CEULL, 
            0xE76AB9CFB9B0263AULL, 0xA7ECC1ABD3BB32DDULL, 0xB79493DAD0EFA636ULL, 0x3878C663C3A0A346ULL, 
            0xB20189AD016C7C31ULL, 0x57902012C67337BEULL, 0x26DB695D3F474BD3ULL, 0x0D499820F00A51EFULL, 
            0xD4F4A51C412144F3ULL, 0x05241B2EBE26B0F8ULL, 0xF2B93E20694781E0ULL, 0x800C78D0C120B1E5ULL
        },
        {
            0xD9E157286EED6FE0ULL, 0x261995A1B0DB1BB4ULL, 0xA7C2D4AD95C9C825ULL, 0x3B08BBCC908DBB29ULL, 
            0xD6074F236E387471ULL, 0x106AB74D71DE8837ULL, 0x6E7E592DC7C297CDULL, 0x5547DB421479EB55ULL, 
            0x1A64D547E134B937ULL, 0x497E60AFF92B01D2ULL, 0xD93303BC819EAABDULL, 0xAB54FA061D3C1E7CULL, 
            0x8F77DA0655AC588CULL, 0xBC30E80B4497D338ULL, 0x906A1561831ADD7EULL, 0xCD20367F644E7B79ULL, 
            0x8C5AEF64D3876690ULL, 0xB3C7323ACD7105B1ULL, 0x2F6EC1C28827DF00ULL, 0xC9E8FABDE4D00CB5ULL, 
            0x95AF3781170FB72AULL, 0x93BBF4CA1616469CULL, 0x18DECEE952ECA249ULL, 0xB06D515C9BD4C568ULL, 
            0xE2C48895C167691BULL, 0x4F5B5709DF5A53A1ULL, 0x99EB0262AAD623FFULL, 0x20190A59C56A2D0FULL, 
            0xFC281D5B67D6138AULL, 0x6CC2B04A2101A7B6ULL, 0x338ABEFE09EB61D5ULL, 0xC5D018A016D16988ULL
        },
        {
            0x798FB8ABF3E950C7ULL, 0x0A67F4FEEA2171D1ULL, 0x58BC437F8C9A8B3AULL, 0x1660670EC14F8F4DULL, 
            0x25947B24F0AD8065ULL, 0x015887FD90DFFFE4ULL, 0xA0D610C65B59E70AULL, 0x81378529CE772510ULL, 
            0x828AFF4D98E4C7BEULL, 0x93E44D8B8466F035ULL, 0x82F0324D9790702EULL, 0xB395EAAEBBFCD078ULL, 
            0xB517AC7F5C958901ULL, 0x6713A1F9A5F90094ULL, 0xCE046BD317219CD6ULL, 0x3B47AC9BE8F25097ULL, 
            0x8ED3AB6292F05FB2ULL, 0xFCD2A5A1669C1DDCULL, 0x9B640656D180CBD9ULL, 0x3A133DE720ADF49CULL, 
            0x95D82F1DA1453F50ULL, 0x64B51B5E11134847ULL, 0xE843DAE8A454D1E3ULL, 0x4A3E330A286E16B9ULL, 
            0x740C73F7DAF5BD27ULL, 0x7ACD6D3937A5D127ULL, 0x68E110DB24CA695FULL, 0xBF7422B89AEBF9E0ULL, 
            0x52CB4B8133C9281FULL, 0xF49AAF5B4FB7754FULL, 0x708C71A30A28FDE9ULL, 0xA1F9E3B4EA955955ULL
        },
        {
            0xC388DFA8321EA089ULL, 0x6B82B5B7BBFB62DAULL, 0x44E7A869C3AE9633ULL, 0xC3EEC33873C3ED7AULL, 
            0x656759E374CEF4BDULL, 0x5E0CB3132AE20083ULL, 0xCC5F252B16F9D555ULL, 0xF76D106B518EA048ULL, 
            0x710254293FA6C824ULL, 0x6547EF53546F264AULL, 0xDAE25B2066277934ULL, 0xA547DC47F60DD164ULL, 
            0x156EC1EEDEB4FE6EULL, 0x1BD817BE0B5DFFF6ULL, 0x4AB7C46468E08289ULL, 0x4930D13DA754188FULL, 
            0x3AE8D9110C49C016ULL, 0x91D9DBDB1A6DD8F4ULL, 0x3AF97040E2B36339ULL, 0xC5C44258D4614E0CULL, 
            0xB865466EDE19E944ULL, 0x78D78C2332499814ULL, 0x750E47048797B6B7ULL, 0x8D03166ACB40A112ULL, 
            0xC42248EA8A8FEACDULL, 0xAF9756AA53B9FF73ULL, 0xBE41A70D9CA6DC17ULL, 0xAFF84BC7C09AB8A2ULL, 
            0x04B0302CF4B46978ULL, 0x9498C38FFCD157B4ULL, 0xAF850A8287984134ULL, 0x5FB87B62368F9063ULL
        }
    },
    {
        {
            0x59AB7740309AFDFDULL, 0x5E37651E7B77FCF6ULL, 0x0E085F0CCDF77D8DULL, 0xA5480F8DAC20AFDEULL, 
            0xC0C5F12916CD766DULL, 0x3B3D36AE310D14A9ULL, 0xFBCC2620E2CF4CCCULL, 0xEACE35F6B09E5B07ULL, 
            0x2BC28D8E99DB7F18ULL, 0x6B1BA5EADB803E5CULL, 0x656D42E33C4A560BULL, 0x888C533169F1722FULL, 
            0x48C1815C07E90DB3ULL, 0xBA7D11C54C54A413ULL, 0x0F84FD6A3FD83AA1ULL, 0x6DEAEEC22311C9F3ULL, 
            0x99FEA0AD6DCF0B7CULL, 0xD7D4A5A5412FB5BBULL, 0xA5E571AC577C846BULL, 0x193C735F07746BBCULL, 
            0xD3BF5D8E1A98629DULL, 0x6DAAC83EBCDA4484ULL, 0xC8089CD6786674BEULL, 0x0D3ADEEEBF87A656ULL, 
            0x9033C37DDA22938EULL, 0xA149FA7C0603B099ULL, 0x08CF3F90BB032B55ULL, 0xC74E5B844C049964ULL, 
            0x253637DB35D0B318ULL, 0x74AD680C698D9336ULL, 0x739D78D8E35D056EULL, 0x0D35B7DDF0A22EE8ULL
        },
        {
            0xB2EC04A63FB7887FULL, 0x3F1C38F48C8ADE41ULL, 0xD9B5E728B8D54AE9ULL, 0xE7DA7DBA70E5472AULL, 
            0xDD166D1ACD0C7ED4ULL, 0x9923F91069ED3C1EULL, 0xC25A23F12A6AC352ULL, 0x041F308D5F530F69ULL, 
            0x84689848A8ED6ABBULL, 0x2047436C17BB0192ULL, 0x8DF6479DE0CB33EBULL, 0xE4F52DADE748A383ULL, 
            0xC12EC7DBFC583084ULL, 0xB94239E2449F23A8ULL, 0xD47A9709F529C981ULL, 0x3423C1F14035C8A7ULL, 
            0x662283CFCA64E0C6ULL, 0x842A7C71CF76F5ABULL, 0x02C3770310D151E3ULL, 0x8B526AE83B74681BULL, 
            0xF1559ECDAB32FB89ULL, 0xC9C08F0676EB314CULL, 0xEBCA2D4A18F3CD30ULL, 0x9830D81C6F20A62FULL, 
            0xD5A892645DF23FEDULL, 0x5C113E33498CB810ULL, 0xEA13AA65D9A86CCBULL, 0x5786A4EC09926C45ULL, 
            0x974081A614349098ULL, 0xD14AE6D80A106157ULL, 0x283C8437E0BF1714ULL, 0x7064A732B6B07268ULL
        },
        {
            0x12269AFF4C1B5CE6ULL, 0xD712BFD2BB780E59ULL, 0xB8A0A96DEBDC600CULL, 0x625BBDC583F56D63ULL, 
            0xF5572F6507FAEEE0ULL, 0x44077F2644C73388ULL, 0x7366C359093D9A92ULL, 0x52F51610CCF8DF73ULL, 
            0x2C5D0E1339C7FD72ULL, 0x08C80ACEBBB31574ULL, 0xCBBCE7B2724A2EE8ULL, 0xF4FD1D61DBD7219EULL, 
            0x5769E4D940F6BAEEULL, 0x406CA2DD5BECC2D8ULL, 0xAB1DDDC74E0C2DFAULL, 0x938ABBA318CF060CULL, 
            0xAA3C53B9322D8F76ULL, 0x3D5FD855315ED00EULL, 0x0078FB51A6666319ULL, 0x4368E5B76AA6DAEBULL, 
            0x0965B42371E82D41ULL, 0xAEAB239C9C8C055EULL, 0xF069C57CF375BF84ULL, 0xB90044D42B699661ULL, 
            0x370B2B3E6ADABEEFULL, 0x444CB0BA54AD13ADULL, 0x57DEE6AD3345CF3EULL, 0x96E60A75446D3606ULL, 
            0x7D76D003C43A9919ULL, 0x1594CDAFC81E4FC8ULL, 0x2AA34A0E13FA13FFULL, 0x8D133189B0B88C5FULL
        },
        {
            0xBD6D37AC900AFB7FULL, 0x69BD840876EB1622ULL, 0x01CEAAAFE412647FULL, 0x7B923775240CAFC2ULL, 
            0x0C284B8D1AEF8BCDULL, 0xCE6BFBAAE04C4B4DULL, 0xF7E4D25432805159ULL, 0x857BF5572D91EDFAULL, 
            0x270D9FE82431A2EEULL, 0xC77A7E52F6C26CC4ULL, 0xA2D4593BF4D6F724ULL, 0xF03E106D63B4114BULL, 
            0x32D03965E75B4F71ULL, 0xD17B6A1D2B4AE25BULL, 0x47E1500E06CB35B3ULL, 0x57252E662D532D2CULL, 
            0x31612E6CE5507E62ULL, 0xAF8B656A9B254250ULL, 0x1B97DEA3A508C97DULL, 0xAFAFBC133D8691CDULL, 
            0x96EA1E4C72B967D0ULL, 0x7D98CC9DCF490AE3ULL, 0x51CB066EFC6B3776ULL, 0x761EC538DCA1D57AULL, 
            0xD9E2567117CCB364ULL, 0x8748B92BC5812DB0ULL, 0x5AFB4D926EEBADFFULL, 0xB7403295DAD547A1ULL, 
            0x0B677302F162082EULL, 0x2512E61BDEC540E7ULL, 0xC5B90DA963ECA591ULL, 0x52BF0628D14CC7E2ULL
        },
        {
            0xB184131F97F582A4ULL, 0x029D941F981B4A2BULL, 0x607A3230F2E5C8EDULL, 0x40E49FB413C6B3E0ULL, 
            0x7E9D29A2FD4D8985ULL, 0x4D84712BFC1AB268ULL, 0x9438F32FD3D47433ULL, 0x3CE65720482BE019ULL, 
            0xF407BC501EC6770EULL, 0xF8870A90C86F1CBDULL, 0x21EC9EDD9DCF0EE0ULL, 0x4BEA2396BEFDC31AULL, 
            0x11585048C35DA747ULL, 0x4A16BC7B67CA0006ULL, 0x021A3384E6B0BAA2ULL, 0x8DE96B5A22BA39CFULL, 
            0x7A94FF45A61DDBA3ULL, 0xB922D206A489DD01ULL, 0xCE5378110BFCCD45ULL, 0x080AA798C0E36D19ULL, 
            0x81E428F46738DF12ULL, 0xE89662647BB52F1AULL, 0x74A548629C1E060DULL, 0x03CEF422C517B7E0ULL, 
            0x32552AE7480250E5ULL, 0x355224CB49169F01ULL, 0xCD8C0A1C768EC8B2ULL, 0xB67F138703ECE7AAULL, 
            0x68B2751C1021E00FULL, 0xAEB903571CBCA635ULL, 0x24772262BEE4B718ULL, 0x824C2043F7B272EAULL
        },
        {
            0x837BEDE0512372FFULL, 0xD58D81400B8A6015ULL, 0x88D3383BAF2EB6FBULL, 0xA3E0642C7A1512C5ULL, 
            0x42FC73EFA0EDE1B5ULL, 0xC3E4BDBA24869EB6ULL, 0x2D205D61EBB0AED3ULL, 0x27F5C2C5053AE4E2ULL, 
            0x10ACA8A6DA773101ULL, 0x299BD8DB57A084C1ULL, 0x38DD9DA6E9ACE9BCULL, 0xC2D891E4482470FAULL, 
            0xDED4DCC4D5BA34AFULL, 0x916CA5B66C5D9D3DULL, 0x87813C4CBAD87181ULL, 0x8B3F71AB24320146ULL, 
            0xF12688518DF846CAULL, 0x50414DA080AC4A26ULL, 0x556BDD4E82736883ULL, 0x9171AA13944063BDULL, 
            0x1C89711A229FF5D5ULL, 0xFB59F56CB8353624ULL, 0xD34473C178A9DFA6ULL, 0xFD12904EEBF522B5ULL, 
            0x4CBAAE5196333C5DULL, 0x974BF34D03D8C159ULL, 0x6CFB03E0780D26C5ULL, 0xA4481D6E2E7C561EULL, 
            0x71AD56E4F4F4B4D0ULL, 0xF722A923B9A2F079ULL, 0x6B1175B574D31CFCULL, 0x1E46A76CE3887B9FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseAConstants = {
    0x22C6BC03A86CCCD4ULL,
    0x009ED8368C92B84FULL,
    0x04B70C05350583F4ULL,
    0x22C6BC03A86CCCD4ULL,
    0x009ED8368C92B84FULL,
    0x04B70C05350583F4ULL,
    0x66C37C7FAA350ACAULL,
    0xDC0E6F7485409082ULL,
    0x8B,
    0xE3,
    0x5E,
    0x8D,
    0x1A,
    0xAA,
    0xD4,
    0x08
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseBSalts = {
    {
        {
            0xA0CFBE2F473FD3E3ULL, 0x842C7C1BC89ACEB5ULL, 0xD51FFBEA33CAF0D5ULL, 0x7AA7B5A116665FCDULL, 
            0x1116B96AD87AD7CAULL, 0xFBA902B6797A30C0ULL, 0x1FC60F313A64ABEEULL, 0xCD5F21B67817379DULL, 
            0x57C1F966B3A09015ULL, 0xAE3FCCC39AAB26D9ULL, 0x205DC3ACDDE67C00ULL, 0xC9697971E5507978ULL, 
            0xAEEEBFD172BBBFDEULL, 0x67E5A4B0A4957676ULL, 0x007243D068210707ULL, 0x3AF738AE2699CD9AULL, 
            0x966414AA99FD59ADULL, 0x11C005475FD8CEE2ULL, 0x9D4E7F680B6595CEULL, 0x92751A2915FCEC9EULL, 
            0xEF23DDF985D2A3F3ULL, 0xA3547D85DFDBE235ULL, 0x34C7A9497D52468CULL, 0x40C700943109A60EULL, 
            0xF1CA32E514F6C0BCULL, 0xD5E87752E716C04AULL, 0xE2AEA069775A4D80ULL, 0x76DFF49D135499E0ULL, 
            0x8DB92CC0497FD191ULL, 0xFD17B7932EA91EC9ULL, 0x2599678CB1C82BAFULL, 0xCF1A2A1509F5010CULL
        },
        {
            0xC9A3F065EAFCC9DCULL, 0x8320F9A8246FD083ULL, 0x14202DC7A14E91E7ULL, 0x74E7AB8F8A05F1E8ULL, 
            0x871A66D4373F7504ULL, 0x994FE5341C8DE464ULL, 0xE169C83574905F1BULL, 0xEADEB58DA1CC5125ULL, 
            0x32179228C72941AEULL, 0xC34E185BAA63D3DFULL, 0x76B3C32E069A68F0ULL, 0xC33036574B4611CEULL, 
            0xA491084C1C47A4FFULL, 0xBD92C16272A1726BULL, 0x4BDC4FB8C49B0C30ULL, 0x5D209616A07100C7ULL, 
            0x5B6143F98A811B24ULL, 0x7F1CC2BDACF75EB2ULL, 0x3FF19B8D7D54C267ULL, 0xA3A7737243C1CB03ULL, 
            0x1D17351F449B9897ULL, 0x636509649A7B0A31ULL, 0x9255005176864857ULL, 0x5A15A4B1F7DC93FEULL, 
            0x217B7BE18C0D8D94ULL, 0xFBEF2689EBC4A0D3ULL, 0xED69E0B1E1A3F645ULL, 0x388D2CB02D5FD265ULL, 
            0x882C824696A390B9ULL, 0x01E0D17AFB665CD1ULL, 0x2046097DEFA2FA84ULL, 0xD0B795B0C74C0271ULL
        },
        {
            0xCAD8C1E26924434CULL, 0xC2F213D6DAE48C3EULL, 0xBB1E171F48760273ULL, 0xB8E42752FA7500EDULL, 
            0x2280AC9EDD55A1FFULL, 0xAD13BBE672C4C7B4ULL, 0xAEDF282CE5138332ULL, 0xF528DE7448E70337ULL, 
            0xB6E4693C2197F218ULL, 0x3C30ACE40BA937E3ULL, 0xE630C0BC8D4BA57CULL, 0xBFC018C6415B09EFULL, 
            0x8FA4F359477114B7ULL, 0xE8ACA577059F3E08ULL, 0x52AEB4DBB6A02733ULL, 0x6C7C3B440534520DULL, 
            0x9AE0FC616C33C1E2ULL, 0xB7A304217154C9D6ULL, 0xE27AEDC56D77F2D1ULL, 0xC64798BDBD936993ULL, 
            0x9985FCC8591C5B4CULL, 0x3CD22EF53603F083ULL, 0xAB3F1A035696B1DAULL, 0x98960635A2D7F7B1ULL, 
            0x41414C0FC9FCB421ULL, 0xDD89B2F38423DFEEULL, 0xDF780A3F127D9136ULL, 0x3209EFBA761618DDULL, 
            0xE837D99BF4DC82DFULL, 0x5C088D6BB2320CCAULL, 0x326B3C478E36C378ULL, 0x40C70975CECA8016ULL
        },
        {
            0x79D371FDB4E52B8AULL, 0xD5D025978A3374D4ULL, 0xFCFE96DDE1812D36ULL, 0x116315877A0F225EULL, 
            0x7FCCB653BBB67827ULL, 0x8315235327AE05D3ULL, 0xF342CAA757918C83ULL, 0x6EB38266723E86E2ULL, 
            0x86F82D25896ACC73ULL, 0x3C01E1D72CA627F3ULL, 0xEDABBB5AD9326C97ULL, 0xC84D259FC0E11744ULL, 
            0xBA731C0A254A4D71ULL, 0x519D3D2B5C295962ULL, 0x4C2D2E029929D998ULL, 0x060105567B5AABE5ULL, 
            0xE1DB132BB3537655ULL, 0xFFA58BF1DCC40634ULL, 0x9CD71A91BD971005ULL, 0xC5E6A43206897EE9ULL, 
            0xC2B2EA51FFB8D46FULL, 0xC1F24C2BF9ECF693ULL, 0x93009F7069613CF2ULL, 0x07FC2BACC2963775ULL, 
            0x2F6B34B0CA5FEDF9ULL, 0x55DCC262AEE6F01DULL, 0xF44CB53F92114227ULL, 0x4AE642B191D6AC1AULL, 
            0xE7DE0C9690409E1EULL, 0x6398A30FE66489ECULL, 0xFA5B5723D276F844ULL, 0x441F109523F53E58ULL
        },
        {
            0xBC127A7827357528ULL, 0xE4EF0CD9E7B5B6A2ULL, 0xF1D588C0AD501F6FULL, 0x16B9F739F4918D5CULL, 
            0xA1EBD3C26DDACC3FULL, 0x3E3DA50A15782E44ULL, 0x18704DC12E838999ULL, 0xDCFDAABFA631C40FULL, 
            0xEE3BB85B3C356AD9ULL, 0xD30276EEED87112DULL, 0x7A221648E03CB99BULL, 0xAD18E67DEE79C252ULL, 
            0x2CFE6EC3BDE19C1EULL, 0x8EFFBDD25D11C6B6ULL, 0x5DE216E93B65AF02ULL, 0xA76FAA02AEBFD5FEULL, 
            0x7D3A826C60F2FA92ULL, 0x82C774EFA30B66C8ULL, 0xEA8AD7EC0A0BEAC4ULL, 0x1AAAE744EFFD0970ULL, 
            0x25300336F56EDB68ULL, 0x62C762349116DFE2ULL, 0xE13C8B5809B6DEC1ULL, 0xCC54E6D3657F1D34ULL, 
            0x580C863630EDA8F8ULL, 0x01A785EFFB0A2726ULL, 0x2A598D1DD49BD054ULL, 0xDA66B4006C86EE34ULL, 
            0x743507A3237C31A7ULL, 0x950B9074DAAC7188ULL, 0xC4310B4475327311ULL, 0xAFC413A47B1EE01CULL
        },
        {
            0xCA42C81FE52613EAULL, 0xE365C321F1B2304AULL, 0x975F1B462D22205DULL, 0xA7239D9D07527096ULL, 
            0xDAD31909A88CDC37ULL, 0x58FEEE5F0A812B05ULL, 0x07C32DBC32C15C22ULL, 0xF166DE1631DAE6E0ULL, 
            0x1E77F09D0A6F8013ULL, 0x299925A04E09938FULL, 0xD55B6DC618D6F225ULL, 0x1052334460528DEBULL, 
            0xCE287136ADB887C5ULL, 0xAE91E02ECC8F86F4ULL, 0x49D7AF9F6C5278D6ULL, 0x8B66A8A377B03FBEULL, 
            0x98952552F37D2E1BULL, 0x577501FBF2BF6F82ULL, 0xD54E45A37108891DULL, 0xF31F7E4BF071D07AULL, 
            0x938AAA0BC9B3B635ULL, 0x9472F8E29FA619BAULL, 0x686AC3E8E071C279ULL, 0xCC62707311236D65ULL, 
            0x4D6D2DF2EB9394D7ULL, 0xF72643F2425BDC3CULL, 0xD40814FB806C50B3ULL, 0x6D3C755CFFCD8B11ULL, 
            0xA24D5DD5D6FBB7D0ULL, 0xB94508950EFE33A8ULL, 0x50001A2623FEC0CFULL, 0x9D9813AE33822CE1ULL
        }
    },
    {
        {
            0xD639CBBAA94D3EABULL, 0xFFD41C9942AC7605ULL, 0x12F9D1081E1220E6ULL, 0xD80A0359FBE6B5D5ULL, 
            0xD4256F6FCEA65BFBULL, 0xD436FAE160B7A791ULL, 0xFE52A1B417DD14FDULL, 0x878F862C45339410ULL, 
            0xFC54F2336067FC01ULL, 0x37F40B7E1DED7433ULL, 0x9314580465D24E63ULL, 0xEE461A544647C6E8ULL, 
            0xDA3247BAC6306C5CULL, 0xE8F18E46B46C76E9ULL, 0x85122E0A845A52BBULL, 0x00C91F85BCC63226ULL, 
            0x4D16BC22946A9C00ULL, 0xD1303EAB43125501ULL, 0x27DE5C14B6777100ULL, 0x8F341ED4EFC9B8D3ULL, 
            0xC5DAE6999D261014ULL, 0x03BE9DD61A154AA6ULL, 0xFDA4233C0A11CE5DULL, 0x5E23D06271D5872AULL, 
            0xA9AFBB78CC6EFB0BULL, 0x0FB6817FC48EDF3FULL, 0x605FBC2F5F5C922AULL, 0x8C665DBDB392E55FULL, 
            0x9EA64597181151F5ULL, 0x1D2C0C3AC778D988ULL, 0x149623E0F362E416ULL, 0x4225DDFFE17BD935ULL
        },
        {
            0xC8662DC8B5D86033ULL, 0xC0A421B65A6F84E5ULL, 0x6B641D21792DB751ULL, 0xA391B3E684E2031AULL, 
            0x53BBF4049BB1F348ULL, 0xB3CB85132FB720DFULL, 0xB808CA3E52D5912BULL, 0xB9258813E5773F91ULL, 
            0x0A210C93F6BB9258ULL, 0xAD6625F09BC3992DULL, 0x98ECF2C1AEC06FCAULL, 0x5B5F23D7BAFC68F8ULL, 
            0xE7215199C23A8570ULL, 0x392E2F236D70528BULL, 0x4C2B0C3D0BD337AFULL, 0x87724485FC152FB5ULL, 
            0x402B5168813E80E5ULL, 0x1CAFBC1046A0E65EULL, 0x1ED305FFBC0DB576ULL, 0xE2D21BE6AC2079AAULL, 
            0x59E8FE50F343B8D2ULL, 0x7FB7D68FE5ACEA56ULL, 0x3F12CC94F392242DULL, 0x284DAB438B6930F2ULL, 
            0x639CE7323481C393ULL, 0xBE83765A992EFEE9ULL, 0x6B2A52A61C5DD42FULL, 0x2753E4B8DC721A51ULL, 
            0x60DCCE2E79080466ULL, 0xD606E39DA68EBBACULL, 0xEBA2FF1E951AB156ULL, 0xD9E9A6239EB7DAF7ULL
        },
        {
            0x69E2F2B1E837CB1FULL, 0x93722B352AF4F355ULL, 0x33BE53CE1E60FC40ULL, 0xEC94DB0F7F3DC19BULL, 
            0x6C26D9B637AF7419ULL, 0x4F5936CC81413333ULL, 0xFFDDF2F4A98C5B50ULL, 0xCD0E17596EFC83B9ULL, 
            0xC649496171A4205BULL, 0xCA7B054A7CD6A8C2ULL, 0x5C57397530260974ULL, 0x247CC1337ABCF195ULL, 
            0x5916192C1D3D4A02ULL, 0x73C093B54000FF7EULL, 0x926D78984D5095B3ULL, 0x53B4F9D91E31CB31ULL, 
            0x6DD8B7F5C4136DAEULL, 0x86CC39FAA069D9A3ULL, 0xD9DD08BD38F3BF86ULL, 0x3BE43742A1618635ULL, 
            0x6BBC4C6C1BF95217ULL, 0xE743FE4882135E90ULL, 0x3B1C46BBF11141C1ULL, 0x947D2CD7A02D94E2ULL, 
            0x4D107FBCF5B57B55ULL, 0x7F632862EB7E3E91ULL, 0xBBD664FD9EF250AEULL, 0x2742424179C86DC8ULL, 
            0x16B69F5B52305F09ULL, 0xBAFB221B807AC1EEULL, 0x1F1DE17AD873EBC0ULL, 0xA9A8B6F346B3A088ULL
        },
        {
            0x4EA727BFD946E0E6ULL, 0xC5ECE68BFE2846BBULL, 0x07E359C11D6566BEULL, 0x270919F4D02BA3E4ULL, 
            0x2B35FEB318F05B80ULL, 0x0572E64826D1F40FULL, 0x4B4A1EC653C768CBULL, 0xC495375AF3FA50E3ULL, 
            0xCAAE96E6885C7AFFULL, 0xBEB801FE7CAED3BBULL, 0x00D558E2E74C7935ULL, 0xC66727C61129EF6BULL, 
            0xFEC0BE3857E6A8D6ULL, 0xB908C715F3EA328CULL, 0xF0E00F3BE96FFA1DULL, 0xA7911961ED29994DULL, 
            0x04C67137319D5C9CULL, 0xCEFB7387403EE14FULL, 0x3FE2576B125781F7ULL, 0x768983A23F1095C2ULL, 
            0x3E1FF4AA3A732180ULL, 0x90097A1A5D27470EULL, 0xB32F4D5363506CCBULL, 0x878D67420B51F305ULL, 
            0xAE06ED1043ABF2D8ULL, 0x7CB983BE1396F6A0ULL, 0x94071B5ADC7C5C2CULL, 0xCC556683212E4B40ULL, 
            0xC4B5F7D66080303FULL, 0x4C846AEA5D0E54F1ULL, 0x0187F260602E4C08ULL, 0xE5C9C8B4565A472EULL
        },
        {
            0x876B447581B96EDFULL, 0x27D48F2D4E398E23ULL, 0x8751785E6C9337F5ULL, 0xC29A184C2820833AULL, 
            0x990424C9382B5E77ULL, 0x3E7400A46F85B5A0ULL, 0xECD3D75281BC3E4CULL, 0x3324A58638BC0DB3ULL, 
            0xAA1C8AA7DE370ED0ULL, 0x3C131A12DBD20BFFULL, 0x6D584B1A6F6117D4ULL, 0x232896026EDF5062ULL, 
            0x1AABBCF5D0E55467ULL, 0xF0AF8BB23EEE2417ULL, 0xDB3FB2762FA57563ULL, 0x62422F822FBE3C42ULL, 
            0x80C3C40C20B503F8ULL, 0x3EB2E3DF3267AAF2ULL, 0x8B53E1168D3B4857ULL, 0xD78C0B0540B1F2B8ULL, 
            0xA5DEBDB084B02F29ULL, 0x877F2ADF6FCCCEB7ULL, 0x309660913F3F5A08ULL, 0x01D979FCFCC552D4ULL, 
            0x22D74BA5D51FCAF3ULL, 0xCC3090EF7FCE1F54ULL, 0xD69887D275A6D889ULL, 0x540932AFE9374DFCULL, 
            0xE39C6DFF46058853ULL, 0xFE97DF60EE512D77ULL, 0x46B85FF259655425ULL, 0xCFC2557F7FA69793ULL
        },
        {
            0xE0ECBB97FB8F1E60ULL, 0x3ABC1133B6BDC181ULL, 0x1D89DF65007FDE2EULL, 0x17950EF5F3B84CBFULL, 
            0x44B45D39F3C352D3ULL, 0x46E5966D3F409899ULL, 0xFE1AE0BF505E7A1EULL, 0x42785F7C1825679CULL, 
            0xC4A42BC4BD29A90BULL, 0x2DCD8AD30F7B0D62ULL, 0x023B843259A47A3BULL, 0x944DAA57617202EEULL, 
            0xE1B150C9C6BCEE50ULL, 0x7242DA889485713DULL, 0x864FA3E027B431CDULL, 0x42E216B2E8F1DED0ULL, 
            0xB8B887705D7CA757ULL, 0x538E890E9E2B0F1DULL, 0x469D77002BEBE754ULL, 0xF88290385BD41D90ULL, 
            0xB522D61B4291B6B0ULL, 0x928408D2DC3CA3D5ULL, 0x41089AD964B2D3B4ULL, 0x38B2303F0DC06CB9ULL, 
            0x10C2668EC1F25737ULL, 0xE2F84673F0C9908EULL, 0x87509CADC89DFCD4ULL, 0xF1B6590523980E4DULL, 
            0xF0934FBC799DF869ULL, 0x4DFF0E7416C321A3ULL, 0xB953B848E99F8E85ULL, 0xFDEA7281A153D7D9ULL
        }
    },
    {
        {
            0xE66EFC47713909BDULL, 0xD2A14BE0744B3F2DULL, 0xE7E2DC8D1552F199ULL, 0x63B30646812E0BCCULL, 
            0x5DABB218BD155970ULL, 0x0C0957395192F1E1ULL, 0x7040CD788F95093FULL, 0x80E0713D48EF1EC5ULL, 
            0xD60F98D6FB447704ULL, 0xD21A865A405CC59FULL, 0x6D6EFC586DFF2323ULL, 0x36133F57A12DA3BBULL, 
            0x1DCE134322BB2AF7ULL, 0x1A5B5FB9CBB03C71ULL, 0x2D8C7230DEF915BBULL, 0xE92DDEB0474CDFDFULL, 
            0x4A7AF730F359EFF5ULL, 0xDC6EFB40BBAA2BF0ULL, 0xF24957049DD2E172ULL, 0x58B79E2A9AB5C93CULL, 
            0xCF27252EFC9251F5ULL, 0x808C8C850993F52EULL, 0x21864EA37DA6BD90ULL, 0x8FD7556B1F075359ULL, 
            0x7E82B2AABA381305ULL, 0x5710FF3EBD216C19ULL, 0x6717ED70CB5BEFB3ULL, 0xCF28019C45AA32DCULL, 
            0x30985ECFE75E7921ULL, 0x3E82DE2091AA39AAULL, 0x89660B83FA167221ULL, 0xBE29F09F89EED457ULL
        },
        {
            0xF7FB45A8627A92FBULL, 0x547F6F6B3150DDD9ULL, 0x0DAEDF1233C1C401ULL, 0xDAB92FAACE5EC13AULL, 
            0x690D5D5D3DC6293CULL, 0x3215DCE01D1E6CA4ULL, 0x14A95A5C6FDF5B2AULL, 0xCDA81E7D7F417ABFULL, 
            0x26717A872A9CDD69ULL, 0x28DBAD66A3AAD2DCULL, 0x021C40B76D3AD92DULL, 0xD100A79823A6D34CULL, 
            0xCB9F3587260874F8ULL, 0xCEA1B841B2700D29ULL, 0xF13AAB634B71CF00ULL, 0x9089324CCCBE7C54ULL, 
            0xDF3166D1D4C6DB71ULL, 0x289CA587221F8830ULL, 0x3E2DBA18B949F93FULL, 0x2BFE4A8932D71519ULL, 
            0x3EECECC3FB0AE522ULL, 0x3090017E82D76A87ULL, 0x5D2076252901A48DULL, 0xEF7D0B207879D6F4ULL, 
            0x8D6F01F16FD41CCBULL, 0x9BC3E72161D8C8EFULL, 0x7C2501ED034322D4ULL, 0xA5FB33F181875475ULL, 
            0x7E95B9F1F6E8627FULL, 0x6820A74249A35701ULL, 0xB24F7F5F3EEEB3BEULL, 0x6BA8F61AE5848D32ULL
        },
        {
            0x7859EAB999087BEAULL, 0x0A87C3E38A01CA59ULL, 0xEDCEF7B2DAEC04AEULL, 0x86D5D89FFFBD8452ULL, 
            0xB2CAA1F634749951ULL, 0x0D508A9588F50C36ULL, 0x3C7CC11D903326D1ULL, 0x5A9FDCE07B1DD97EULL, 
            0x9CEDDBAC263E2602ULL, 0x57935237A3BB57E7ULL, 0x269C0621EDE53D32ULL, 0xC53CA2EF97DB246AULL, 
            0x69D58CB9C3A39F49ULL, 0xDDD4B7B9245B915BULL, 0xD281058A038E6AE3ULL, 0x381A2E51EC7C50C8ULL, 
            0x7CA40894DD3927B2ULL, 0xDC196F334A9C9BAAULL, 0xF2C90429A552FAADULL, 0x7FB62093407A03C3ULL, 
            0x0722A732A512C8B7ULL, 0x3768F6441019E5E5ULL, 0x499F1E18B251ECF1ULL, 0xA180EFD2EE65CA94ULL, 
            0xEC2936B52E3F03F0ULL, 0x45C812AF541553C3ULL, 0x325E0546E7180B39ULL, 0x5A5961FB2D829B6DULL, 
            0xA457B7439D2CCB9CULL, 0x30A5033989EC9918ULL, 0x90958FFDC30A996BULL, 0x635FB6652DC1906BULL
        },
        {
            0x4B2A68330B8C2CBEULL, 0x3DD4BF32933F724DULL, 0xF0461F053D4D5937ULL, 0x99EE14399F0D39FDULL, 
            0x23952E1B6FC2CB7AULL, 0x288B076117AEA2E8ULL, 0x95E246A0E33C8C13ULL, 0x0906964C4A9CC187ULL, 
            0x4AEE069E5307ADB1ULL, 0xD9AAD03BAF20B123ULL, 0xE29BAC1B6B57ADBAULL, 0x9D1A3FF9B03D909AULL, 
            0x31906CF7BFFF7E37ULL, 0x88518831A75576DBULL, 0x04358007DD528BC3ULL, 0x5C0BA6F6965D2532ULL, 
            0x46E6C8D5A00C903BULL, 0xB4A6D28B3C940421ULL, 0xCAC05BB8D568BAE3ULL, 0xA78887C9D0F824BAULL, 
            0x662888B3A123620AULL, 0xB4A9E2019F1291E4ULL, 0x6B7375A391AA3838ULL, 0x9AE025435CCEE1C3ULL, 
            0x0980807ABD0FC43EULL, 0xC09B74B04B34F0C1ULL, 0x09F4EBD6E29874D0ULL, 0x69E34C4A5523CFE0ULL, 
            0x80516F11724D9769ULL, 0x32CA5A800249FBF3ULL, 0xE34F3A58162F4B54ULL, 0x57F548EFB385AD87ULL
        },
        {
            0x7C24DBD7A8E5F9A1ULL, 0x027A500F10DB6233ULL, 0xA04800E6FA6C4D23ULL, 0x6E257406084C570BULL, 
            0x868BBFC37397851FULL, 0x8CA1C38E5F2BA415ULL, 0x21C988758C32A895ULL, 0xC41C3E9AC6358824ULL, 
            0x061AFF05D6A90A29ULL, 0x30D3B94456050468ULL, 0x406DFBA1F04FCD8EULL, 0x72F0B53281284841ULL, 
            0xA10ACD1619B10207ULL, 0x7F30CC88691208C2ULL, 0x9D234986C1DAF442ULL, 0x9199649487FF394CULL, 
            0xEA4A0A1247E44F2DULL, 0xB3167C4BCE9135B0ULL, 0x1BAA5A9247D341C0ULL, 0x5C830A5C9D7717F1ULL, 
            0xBB885FE81F72D26BULL, 0x0F3E09B034CCA876ULL, 0x28A5E62560B7A1F0ULL, 0xB5A222098F066D72ULL, 
            0x5F91C6A9260867B5ULL, 0x013C08F3F1C51580ULL, 0x561880A059B946CCULL, 0x2956F6DF0F1E7C65ULL, 
            0xDC45AA4EEDD8C40DULL, 0xC20734C04499EAF5ULL, 0xD58D3EAB8656EBFBULL, 0x3364AF274D1F7D0DULL
        },
        {
            0xDF8944FE21852B9DULL, 0x33D58FB3CD98D232ULL, 0x96E555F9F519069AULL, 0xC83804A0CE30FA3CULL, 
            0x98EA9AF2A42C1CABULL, 0x2E8C19ECEBB17C87ULL, 0xB44DBB79433AA288ULL, 0xB7A64DE86BAB07C1ULL, 
            0xB0172F972AE3C469ULL, 0xFF596F32D59EFCA5ULL, 0xDD8C7ED1E21ED42AULL, 0x41E9BE29C72B8F82ULL, 
            0x504EE1F13A5F7A69ULL, 0x20A8EE5B530E1480ULL, 0x94FF7323A00490E7ULL, 0x59F703866FE89950ULL, 
            0x97E3EFBF8ED874EDULL, 0xA0362489BF927A65ULL, 0x0BB3A8028591E9C3ULL, 0x05C6567C4EB430CAULL, 
            0x958B3C1576DBBB35ULL, 0x80E3665CB86E81CFULL, 0x06BEF85654E1B25FULL, 0x4A67BD3C1DC073F8ULL, 
            0x3C0ECCEDE681E9C8ULL, 0x6866358322873A00ULL, 0x18FD523D5049F803ULL, 0xA147DB184D5BFF7BULL, 
            0xBEC3A1861BFCCC61ULL, 0xBCB1ED1B67BE4FC7ULL, 0x1EB029254F05191AULL, 0xBA4B9F5300FC26BCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseBConstants = {
    0xEE257B42542FF5F0ULL,
    0xAE66F8C608BBFEEBULL,
    0x88CAF753DA4CDCEBULL,
    0xEE257B42542FF5F0ULL,
    0xAE66F8C608BBFEEBULL,
    0x88CAF753DA4CDCEBULL,
    0xA22288F8B399B9C5ULL,
    0x39A74CD7D42C222DULL,
    0xBD,
    0x17,
    0x83,
    0x6D,
    0x33,
    0x32,
    0x27,
    0xB6
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseCSalts = {
    {
        {
            0x1CC9CD7CFB214E8DULL, 0xFD6B08D38A2A59F2ULL, 0x14A04A644DA3B0DCULL, 0x0D478F0C0BB151EEULL, 
            0x1B76C2AEFE86A8D8ULL, 0x6A5C6C3C6210C18FULL, 0x1EFE3431BAB88487ULL, 0x677FD0F83C79DA43ULL, 
            0x71140398E96419ACULL, 0x5AC6FD59066CBE1EULL, 0x87600E8A98896170ULL, 0x3DEE7D00CA82F6DBULL, 
            0x7F600742403101BEULL, 0xFB4A917BA68B1F8AULL, 0xBB6773394670EF1DULL, 0x74E25AD80A619CB6ULL, 
            0x7257E7FABFEEB448ULL, 0x0228290DD0985DAFULL, 0x6A99507EC30A96EFULL, 0x31B461E7DBB265A4ULL, 
            0x2A1399B8C47CC7B9ULL, 0x4C298950BB585BCEULL, 0x6B896184A91A92A1ULL, 0x07E4C9268E9319E1ULL, 
            0x268B9A42C89EEEB4ULL, 0x1E7B663D9BF76F45ULL, 0x9B90B99CE764A439ULL, 0x85B6144944C770D8ULL, 
            0xDFFD01EB5277B3BAULL, 0xD2AD99721C6B0146ULL, 0x458F297EB46DBBCDULL, 0xC7892B78762C6ADFULL
        },
        {
            0xE1D451B74487C40DULL, 0x1587F3BEBFCD24E4ULL, 0x20A89CF7F2055C00ULL, 0xF70F8C49374746E0ULL, 
            0xA9EDA902D2660B50ULL, 0x06DECF90A694FBF0ULL, 0x6F610D7AA1B236E7ULL, 0xEA6BDDFBC087E552ULL, 
            0xBE2A5A6E0ADED39CULL, 0x5BF3D7CEBBD9D066ULL, 0x3C783A07B80DCFC4ULL, 0x53DA21592033B101ULL, 
            0x0805DFDF38159C02ULL, 0xF45D9B3C0C0D10C1ULL, 0x4B5B55A69DC72FC5ULL, 0x4555BD435EB92AB1ULL, 
            0x59DB5CB6DA113A9BULL, 0x5FA6894011933924ULL, 0xF1A9ADB2C806AB08ULL, 0x233496A5A6ADCDA5ULL, 
            0x7E60352B11A07A82ULL, 0xBF4C09E6BEDE5D8EULL, 0x88E53AEABA9B21A1ULL, 0xC1C23F901BAAA2F1ULL, 
            0x9BB5867ECEAE9752ULL, 0xAB85D13ABE09D66DULL, 0x72FB58433108D4DAULL, 0xD9C314A830241F60ULL, 
            0x0EAC86194959D7E0ULL, 0x2A1A29E94992692FULL, 0xA7543A7FA8667104ULL, 0x604158EE1E272699ULL
        },
        {
            0x05DB683D0A6E294AULL, 0x2873E07313BE64EAULL, 0xEFEB50E90F9C4B0BULL, 0x7E3102C711234C85ULL, 
            0x93C779D7FC742A98ULL, 0x080E36FB24A3D286ULL, 0xBF06167DA06435B9ULL, 0x137A29F988DDFAC2ULL, 
            0xA2FDF5A32D5A4504ULL, 0xE9D4ECA7A945A372ULL, 0x650D187AD23C8D46ULL, 0x228E3853BA63AE8AULL, 
            0x2311272EDEA1888DULL, 0x2FB5D8ED9C6CB36FULL, 0x21F456BCC61FDF7DULL, 0x5540CB4104B0A987ULL, 
            0xB8BE1E9C7D12EBCEULL, 0xD95F58103302454CULL, 0x92086B490339C561ULL, 0x47647ACE70562B13ULL, 
            0x1A3F412335D04908ULL, 0x293FDADE055DC957ULL, 0xA82C0143DE3934E3ULL, 0x3B4BFDBD8E7673D5ULL, 
            0x90DA18A00EA17AD9ULL, 0x74DD34E56BAEE767ULL, 0xDC73783C132B3CC0ULL, 0x3D83D442E9E74A71ULL, 
            0x2E69424583A2C8BFULL, 0xB46AAE35EB31EECBULL, 0xA772B54EB05CF71AULL, 0x048EDA539CD55EF0ULL
        },
        {
            0x7A5C3ABA7EEB4DDDULL, 0x8BB5345D528232E6ULL, 0x80EEF91BE6792725ULL, 0x869207A7069D0215ULL, 
            0x2E86810C969EF1FBULL, 0x2922A8F7E5B85D9AULL, 0x3D5DD7DA40224894ULL, 0x08B5F349E3582CF3ULL, 
            0x106B64C052AB1179ULL, 0xABD67720C98C878AULL, 0x913FBF16A07B992CULL, 0x7D9D6AEDF6529398ULL, 
            0xB8E627E32FFADFA3ULL, 0x15CC995EC759BF52ULL, 0xD2E851016DC6C1B7ULL, 0x8672DCE9B2C3924DULL, 
            0xD7B835C92ADEDEE3ULL, 0xCBB96C966C69255CULL, 0x7E3C9CDD9B7FB909ULL, 0x4058F2DB60160404ULL, 
            0xBE46CB9E37887808ULL, 0x291ACC7F011ADD42ULL, 0x541DBD2C2B5EFA67ULL, 0x1BAF13E304395255ULL, 
            0x019F7E1583A314FAULL, 0x6317C2CB7203414AULL, 0xC50615B912B5E718ULL, 0x431D384C0D691BEAULL, 
            0x3AD9D21C8D1DEB8DULL, 0xAB5D850625CDFE94ULL, 0x4EFFA9361BA13873ULL, 0x58D123E8E59538EDULL
        },
        {
            0x3C3713B3AD1DD8D1ULL, 0x63C59BE92AB3BD16ULL, 0xE56CC6C4AD5E4254ULL, 0x1D4622E49BD210B9ULL, 
            0xC089C43168A12A36ULL, 0x056B96989CEABB52ULL, 0x82A5A67AE2D26CE4ULL, 0x2219749F365BC6F8ULL, 
            0x3D3DFF13D0733BB3ULL, 0xECDA1BAAE5328D64ULL, 0xE518D13F676B89B9ULL, 0xC3536D7AFF9950F7ULL, 
            0x2A703D7A75D4AC0CULL, 0x3E518D322AD771E7ULL, 0x0239046866F7994EULL, 0xC8B5B8A786021B8FULL, 
            0x3E586F4B21B19B56ULL, 0xEC187E2AEA85F530ULL, 0xE8D4CA32056688DAULL, 0x7166B011FFBEDFA6ULL, 
            0xBAE0D015F5B361CEULL, 0x1A5BDDAD1D6A79ECULL, 0x26572F5AC1DF3C6AULL, 0x8285B555D543851FULL, 
            0x7B111736F81886A6ULL, 0xC6910F25E5F70E07ULL, 0x2E25CAF4D784D813ULL, 0x05CDDE32AF75E85BULL, 
            0x35681F92907FF49FULL, 0x4E8A8F7363899D76ULL, 0x02D34E7C59959B6FULL, 0x2FBEE623D443DCC6ULL
        },
        {
            0x63DA3FEC526A5B0DULL, 0xEFD877618BBBA8A1ULL, 0x133F6062BC0C4209ULL, 0x1A0DB43EAF337F92ULL, 
            0xA214F7903A563775ULL, 0x3FD792B833B276F4ULL, 0x74D78CC5A4330DACULL, 0xCD68997AB870BD2BULL, 
            0x4A9BDBA793F47284ULL, 0x0A547BAC957323A8ULL, 0xF30BC2CA5AB1F4A9ULL, 0x440A1FCEEF5ACBE2ULL, 
            0x3A841AFC8C7EE274ULL, 0x3CE544E0AAEFFDFCULL, 0x0D656F5308F382D0ULL, 0x460A74C856748155ULL, 
            0xDE7282580CB68BA4ULL, 0x5FE3773D9A0E053BULL, 0xD115EF9101D1542FULL, 0xB82D1B266B47B01AULL, 
            0xF7634A0113CB96C7ULL, 0xFE917D7E704326B8ULL, 0x35BB1CA734C13818ULL, 0x2DC8AFFB2F71D1BEULL, 
            0xA9BE3E9449B067E3ULL, 0xF0FA577FD82F26C8ULL, 0xCE9BF9507863B311ULL, 0x3446EC2EA727EBDEULL, 
            0x90EFE8E297D51596ULL, 0x13FD2222608958C5ULL, 0xF0A29E94B95EEC38ULL, 0x7878A11D39F43900ULL
        }
    },
    {
        {
            0xF817DEDB7465CED0ULL, 0x945B07668ABBBDDDULL, 0x30EA54723BABEDA2ULL, 0xAAFF1758B35BD6D1ULL, 
            0x2DAFED122F1059A7ULL, 0xB87250B2F8386E41ULL, 0x9DB916B841FAD14EULL, 0x611E214007ECD577ULL, 
            0x8ACF318072330B98ULL, 0x2D1B3DBEBCAC989BULL, 0x4D640AD1F032C421ULL, 0x4CC92C1EF6D78E68ULL, 
            0x23BC7A0183E2E0E9ULL, 0x16FB9A2E745F8D1BULL, 0x7528790D3C3A21ECULL, 0x9C428AD1AA055B9FULL, 
            0xBFD1F44D62701B72ULL, 0x92E8111CF610F9E7ULL, 0x4478D55C69A4BD84ULL, 0x565E45220738B1FCULL, 
            0xFBA49441BF56706AULL, 0xD810E3139BC70548ULL, 0xF48C7DAEF9CB2C57ULL, 0x1A9AB497D51C0DA3ULL, 
            0x359E82FC6380087EULL, 0xA897D4838E1338D3ULL, 0x9C084032BF05FA8CULL, 0xC734F50E6520435AULL, 
            0xF9503CEEF2940330ULL, 0x2F9A2CC69BE9C3CAULL, 0x995CA9BD71FA94F3ULL, 0x7491CB74EFC7064EULL
        },
        {
            0xEA3DA4CDE2FDE166ULL, 0xCB157B0B184FCD62ULL, 0xA1D49329841540EEULL, 0x8557A0C6BFBA4344ULL, 
            0xD4D5458B7CFF6101ULL, 0xD519636D7C10ABD9ULL, 0x1334D70CCEF03117ULL, 0xDE26EF29B61819C5ULL, 
            0x32E9437E8DB957E1ULL, 0x762C66ACF3D9A8FBULL, 0xD377BEF1D150CB33ULL, 0x7A28943318C27AABULL, 
            0xCD035B3B48432703ULL, 0xD38A6E74953A74C3ULL, 0xD7577CBE174A2650ULL, 0xA3D54DB8E43A20C4ULL, 
            0x75315F1055A51A77ULL, 0x58FE83DAED8D9458ULL, 0x8FAF31B58CBA075CULL, 0xCC34417ABD83583CULL, 
            0xC1148C378E6DB4BCULL, 0x24579CF0861A4FF5ULL, 0xCA984ADB968AE512ULL, 0x3B246645B12EA18FULL, 
            0x176AD66F86824138ULL, 0x6D544B09E52B7492ULL, 0x610D14EE3FDA8D24ULL, 0x8B1CF0BCB9A037FFULL, 
            0x063F870B9C4BA337ULL, 0x35112F7C09F39168ULL, 0x373078FF6B33E5ADULL, 0xDB2D61D99967DCDDULL
        },
        {
            0x87BB64DDE3A6C568ULL, 0xED5ED9231EE4CBC2ULL, 0xA48CD9F6C7617C26ULL, 0x0270C06B2738E0F2ULL, 
            0xEFAD40F92005B954ULL, 0xC5C2CAC525C7FB5FULL, 0xB9DCF1CDEA36EF9AULL, 0xC48ECE451C6AE174ULL, 
            0x65446B1AF0F250CBULL, 0x6DAFA03546092E27ULL, 0xF8B4F1C24416B282ULL, 0xBE8F022731958514ULL, 
            0x33BBA85745118C8EULL, 0xF1103215C7A0E004ULL, 0x7AFF5E75B11A5978ULL, 0x05A22CEBE95F473DULL, 
            0xC07A3F20E5C8AEF8ULL, 0x54779803D1EE3F9CULL, 0xFACE0535A9E5461BULL, 0x5E567160C4B70351ULL, 
            0x2E2FBFE0A051FB74ULL, 0x2C842C620F34CF63ULL, 0xA408557596F3953DULL, 0xE6560C7EBB8BD7BCULL, 
            0x523276BD9C377026ULL, 0x8B26792AB35157A9ULL, 0x8AE66AF490475F9EULL, 0x5E53B59EC6A4A99DULL, 
            0x510514C91CB694C6ULL, 0xC827A00330BDDFBEULL, 0x64AF5903A289418EULL, 0x389C7D775E13BD06ULL
        },
        {
            0xF47B706F2BA70F64ULL, 0x0E7D586B74CC5ED2ULL, 0x278BE76E5AF59F4DULL, 0x61FBDF1CBBCAEA48ULL, 
            0x6753C3F840E7E837ULL, 0xFF2A25BE0B375613ULL, 0x9704EA6E0C950160ULL, 0x8191A2DA22FA14C2ULL, 
            0xB565D6A380B17BA7ULL, 0xBBB0EEC84F606856ULL, 0x4909D921025210DDULL, 0xF5CCE5FFB54CBCE2ULL, 
            0x34869E469E097A07ULL, 0x99AD5BC16AB173F5ULL, 0x7680C5BCD579ACBDULL, 0x5BC21E20A0217C0BULL, 
            0x4C4BABFAAC65D846ULL, 0x5440CA538BB3C0E8ULL, 0x3BF7FF93131FCBC4ULL, 0xC15FA4D3F5C8A068ULL, 
            0xBD6D1BA60E5E2237ULL, 0x04332AA65C16D569ULL, 0x99BC4EEAB953056CULL, 0x64F111F496E20C25ULL, 
            0xBB1149E72D65ADA5ULL, 0x4F0FF1D7DEB1BCEDULL, 0xC8F8E58DDA8C8A76ULL, 0xDD785758206A04ACULL, 
            0x588235AA953273A4ULL, 0x6752C08F503E0073ULL, 0xDBFA4DF2C74F9BD0ULL, 0xB47238493BFAAA26ULL
        },
        {
            0xAEF89565FF4C4F0DULL, 0xF8837FF5C25C81B4ULL, 0x4FDB216A070CB454ULL, 0x52E7934C2020150DULL, 
            0x0D36A689D9B19806ULL, 0xA1509CB18A5EF501ULL, 0x8F8C0978D8E7EE38ULL, 0x5EB196006132B535ULL, 
            0xA38CE8DD64DE6444ULL, 0xE058454782034B83ULL, 0xEA14936E2F87717DULL, 0xC680A0907C2F863CULL, 
            0xABAD8C7D7277324FULL, 0x02BA070D94E2DE9EULL, 0x2D2840617F85FD26ULL, 0x89FE9CF066C51063ULL, 
            0x8340B46E55495605ULL, 0xC71D3FD87CE206D8ULL, 0x46786F58592710C1ULL, 0xE7B78DECF4C672B8ULL, 
            0x6A1DF89FD210CD40ULL, 0x3070E577B662B39FULL, 0x6E73C15EEE201807ULL, 0x83CEE12B70DF6BCBULL, 
            0x9AEBB5FCF8BFECF6ULL, 0xE0D072F9A6BBD11CULL, 0x844908ACA0CE6000ULL, 0x86F7C0BB3ED2210BULL, 
            0xBDAB7FC9C0A979B8ULL, 0x910188BE4585D3B5ULL, 0x5D1BA003559092F7ULL, 0xE9E453C669ABCF05ULL
        },
        {
            0x55A818992313074BULL, 0x7AF4DC6853905CBBULL, 0x6D879DA75F324556ULL, 0x327A584C97A3EF95ULL, 
            0x0499C18F04169C70ULL, 0x1CE137BC2D4DEA77ULL, 0x3E198A58DF492F14ULL, 0xCAB79ACC240811FFULL, 
            0x195B47906E525F16ULL, 0xCBF6F228283AC5F4ULL, 0x179EFCE1FAB955FBULL, 0x869E975573DD721FULL, 
            0x369CA6E30C1E7BB6ULL, 0x351B871634FD38C6ULL, 0xC09258A888DACE85ULL, 0x8D8E830D9ACFF0A1ULL, 
            0x62972CA1317150DAULL, 0x0B07BFD01272951FULL, 0x69304958C78ECC41ULL, 0x6C1C4C8D18657D0DULL, 
            0x0FEBBECAF095C9C5ULL, 0x28DA78BD4425DA2BULL, 0x4C1DFF01FCF93A38ULL, 0x3A47D990C8EED501ULL, 
            0xC436F5B4B0B445C9ULL, 0xEEC94BEE51DF225FULL, 0xEBA6B808301A46D5ULL, 0x26A628953BF13554ULL, 
            0xF5AF247024415FB5ULL, 0x4F402231383BCF20ULL, 0x1A6CDD1E8FC0BD69ULL, 0x97F6E1AB7774A534ULL
        }
    },
    {
        {
            0xF729488308F18560ULL, 0x47FE3EA2DBC4F9ECULL, 0x1D067E3767E2B74FULL, 0xE517B508102F7291ULL, 
            0x77E4615F077D3C04ULL, 0x0465C81CEAF2446EULL, 0xD4F1E690701E2EF6ULL, 0xC1F86F9DF35999A9ULL, 
            0x591A31CA0B6184ECULL, 0xB2D84F3747EA58F0ULL, 0xAADC196BD0E45397ULL, 0x967E0CA4EE5ACF54ULL, 
            0x670F870A5059AA10ULL, 0x32DFE34851B22D20ULL, 0xDF6A1B79D64D5F21ULL, 0x817B5624DF256824ULL, 
            0x45ED10388D7DDDD9ULL, 0xEEED85582EF44058ULL, 0xF972E075B1C9A187ULL, 0xED7B069B37EFF452ULL, 
            0xA17B548F7EB8BD07ULL, 0xF65B488C432CAB95ULL, 0x92624F714977B2C2ULL, 0x5BD39CD85BC05B11ULL, 
            0x19D2801C196661EBULL, 0xB9CFECDA1A160042ULL, 0x6A483F465C4F5167ULL, 0x66578F94DBFDDAC4ULL, 
            0x3866DF9A36B4A4A1ULL, 0x809EB3727A8EC9F7ULL, 0x598E5D7F9CDA7CDDULL, 0xA599DC4B6BAE8C27ULL
        },
        {
            0xFF241FAEB4AA82E7ULL, 0xBC29806CA7F5BAF2ULL, 0x88312E245D94D78DULL, 0xEACBB336712E3969ULL, 
            0x0F3B9C5FEF00AEC7ULL, 0x61CEF0A59D986CC2ULL, 0xF97D919DC9C0114DULL, 0xCF97A659EC27D20CULL, 
            0xDB2CE63AACB7D395ULL, 0x170382ED800A114AULL, 0xD504B279CF3D23F9ULL, 0x5B12904180F45BFBULL, 
            0xC0353D5023C0AC7EULL, 0x59AF23A478AA10B1ULL, 0xC2C69705B19193ADULL, 0x441814C7781ED99AULL, 
            0xC936D5780E45144CULL, 0x240FADCAC3893E09ULL, 0x4B828EBC1ADC8034ULL, 0x9E3737B16FAAFE39ULL, 
            0xF5841D7163858779ULL, 0xD530B1C1BE2F1059ULL, 0x9CF7BCCF28E2356EULL, 0x2C1AAE8D5A0AA372ULL, 
            0xE3F77184109BCE91ULL, 0xE7704BAD1B029050ULL, 0x79F9989843C0C198ULL, 0x361A017384EEAD77ULL, 
            0xC63359649EBFD571ULL, 0xE6A4C9242AB5D3B0ULL, 0xD1165193F6D064BEULL, 0x862322E359E745C4ULL
        },
        {
            0x34620794C85BAF8CULL, 0xD2AB07EDDA2A1715ULL, 0x09F36CA077924F77ULL, 0x39435AE0541B35C7ULL, 
            0x0D49072D33302C45ULL, 0x192AD9A4D3FA2272ULL, 0x9A22BF4CB6BCF344ULL, 0x65436BC5DA249A9DULL, 
            0xD9E5FB8EACC60B30ULL, 0xDF7F7373B167FA75ULL, 0xD70AEB6B48B391A2ULL, 0xB810112967F5BB6FULL, 
            0xD1DCC2096AF1F72EULL, 0x5504CE1C6E1AB145ULL, 0x0A4337674C4F6587ULL, 0xFE3F75DE924AE1A2ULL, 
            0x22ADD0790A814D5BULL, 0x3C03933712A1E2EBULL, 0x6F6F7B0109DC74DEULL, 0x06C11A56BB7F1B14ULL, 
            0xDADB1D9374C247C1ULL, 0xB5F0F084C9D72428ULL, 0x5F6970A827B33323ULL, 0x983DAE829D72905CULL, 
            0xF3081D38D2EFCDAEULL, 0xB2BB951AD025BD11ULL, 0xFBDAC9AEAB605890ULL, 0x0C1A0A3602BC7BF7ULL, 
            0xB2A669A2A757F899ULL, 0xA5180BA479BDBED1ULL, 0x9CB81676EC4FE7D9ULL, 0xBF48A837AC6A8126ULL
        },
        {
            0xE649364393DBBEAAULL, 0xBF0D6641269B4816ULL, 0x3892B397409D0D21ULL, 0x8025D754B44D71D4ULL, 
            0xCCBE664CEDC3E161ULL, 0x82F0F642FE96EE46ULL, 0xBF0DC10B25B845B5ULL, 0xB03FF1BC11191D7EULL, 
            0x563F82F080E47065ULL, 0xEDAEE127F1750620ULL, 0xC737250C1827C227ULL, 0x06ED2CDF056096BBULL, 
            0x8658FD0C87B63CB3ULL, 0x1D255F745F747592ULL, 0x0F4BB89CCA72A482ULL, 0x29D4FD0ABAF03D7BULL, 
            0xC85D4A92649834A7ULL, 0xB91B3DAC4DB5975DULL, 0x807521B16114122DULL, 0xF4CE111F45DB2963ULL, 
            0xEC4B01C2EA447B09ULL, 0x3E15410849385F53ULL, 0x808FE0F963A58224ULL, 0x8049D5808F5965CAULL, 
            0xF178EF65AC316708ULL, 0x7ED7AC6738D6AA64ULL, 0x308F37A0CEAF8386ULL, 0x7B2034DFDF8F7847ULL, 
            0xBC1179BDCA9B1C9DULL, 0x305A34A8878166BDULL, 0xBF99996DA7CFF765ULL, 0x2A6F84B5D2919ADCULL
        },
        {
            0x3D7DD150028E6AE3ULL, 0x7A1310AAC42C37C5ULL, 0x8CF1E722D0FB57C7ULL, 0x3F323776DAD8DE25ULL, 
            0xCF5D0F6B2F3734DAULL, 0x0DAF087DA5A68834ULL, 0x944DC4DA07CF4F76ULL, 0x8711F5D6D907D31FULL, 
            0x9B3C1FB9F65F747AULL, 0x3673DCC94775D171ULL, 0x3E1BFCE325F3A177ULL, 0x780B8454D968C3F7ULL, 
            0x7458F83E90F645F3ULL, 0x4C485F0BE0039292ULL, 0xA6445ED52478DFB4ULL, 0x835532CAE44A9278ULL, 
            0x86A7BDD434F9178BULL, 0x025EEC2EF38B8AF1ULL, 0xB5B1DDE47AF21FF6ULL, 0x96685503376D00C8ULL, 
            0x2A43CC25C2A2FA70ULL, 0x490BFCA690E0F846ULL, 0xBB4F1F534298C779ULL, 0xECD81CC5A302FB7BULL, 
            0xACC9DCF64863B3F5ULL, 0xE97AE2CF399BBF07ULL, 0x05DFCA42DACA5BFFULL, 0x9DFA2AA69F580DA1ULL, 
            0x1FA4582486AD3768ULL, 0x6E72D8E5BE533688ULL, 0x826DF65007196DB8ULL, 0x706561F575497E0EULL
        },
        {
            0x9188EB90B1431B44ULL, 0xCEBE4B5DA3869C04ULL, 0x0EBB58887E95A6B7ULL, 0x91BBBEFDA6E40ED4ULL, 
            0xF41D1CF541D6A282ULL, 0xB2BB22F3F31337C6ULL, 0x73B624A76E20AF52ULL, 0x2F90C1DF80D8CF08ULL, 
            0x66E1B3E1BDB59108ULL, 0x7C83125693142488ULL, 0x1E00C0EE48942A89ULL, 0xDB5B5A34CE508431ULL, 
            0xD233F6C6E9C66004ULL, 0x3A5FAADB3852B427ULL, 0x6E3033C4215F423EULL, 0x01D2E5E2980686A6ULL, 
            0x2CD73A8BF1BAB4FFULL, 0x5BD5DC92D4E7760AULL, 0x52670AEE66DC3F27ULL, 0x4A89868B22842396ULL, 
            0x7BF7166C48E06C1AULL, 0xF9AAB14BC40EAE8DULL, 0x80FE36D8D4DFFF1AULL, 0xE7B6CB7BE4119D0DULL, 
            0xB57238110C656C29ULL, 0x3C90C3B3C81B4311ULL, 0x8E06D7A55C664BC6ULL, 0xFB09D14B05A43450ULL, 
            0xCD036D739C27904CULL, 0xB7AFE86C6D104CA8ULL, 0xDDC9F516349DD14CULL, 0x6394EAD7C701827EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseCConstants = {
    0x12B0FFD32A4C3DAFULL,
    0xF3642DDE7ABBB7C8ULL,
    0x6CCEB6B38CC8293BULL,
    0x12B0FFD32A4C3DAFULL,
    0xF3642DDE7ABBB7C8ULL,
    0x6CCEB6B38CC8293BULL,
    0x0F9FD1794289A373ULL,
    0x5AFC4889B206861AULL,
    0x15,
    0xD9,
    0x59,
    0x4F,
    0xD4,
    0xFA,
    0xD1,
    0x8B
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseDSalts = {
    {
        {
            0x10800891B077845AULL, 0x0C07E8A68263FFB5ULL, 0x0D6BF82664981CADULL, 0xAE10A3853BE9622AULL, 
            0x10194D695A6D7B85ULL, 0x4A9BC3BF899CB8CDULL, 0xA13B2C55F62160A7ULL, 0xF6DCF9F6315294ECULL, 
            0xCE33D697874519BAULL, 0xD7E103EE56EB8436ULL, 0x43FAAE194491D236ULL, 0xAF56046B219186A0ULL, 
            0x86F88912A0A26D77ULL, 0x3C47BB48012F6825ULL, 0xE5F88CAE45A46B98ULL, 0xEB219A5A2E913C9FULL, 
            0x0E14169E17395959ULL, 0xAE177D4F6C15DAFCULL, 0x995F04BCBBB947FCULL, 0xBB776536A43A893EULL, 
            0x334730C9E68CB52DULL, 0xE2AF8CDAB591D2E6ULL, 0x9C38070912B2965FULL, 0x29D5B65A2427C590ULL, 
            0x9F4BB69D6C5C83BCULL, 0xDA0CF27203F46728ULL, 0xB3D231CF530EFEEEULL, 0xB04F8F55268C017EULL, 
            0x5137BAE0B6180DE8ULL, 0x53FA83734906D448ULL, 0xA6907BFFDF69C482ULL, 0x93781708B4CC9079ULL
        },
        {
            0x5CE5B2B829D400D7ULL, 0xF382984D16470491ULL, 0xD3909BBBC92CD7ADULL, 0x27B0BF60D9C18236ULL, 
            0x81D1537D6EAB6E00ULL, 0x46C33F1327111AD8ULL, 0x8A3CA09AF96AB931ULL, 0x5F41FE09947465E4ULL, 
            0x27AB41F33877868BULL, 0xA9BF8F30077F332AULL, 0x140B04F841DB727DULL, 0xDCD6317960449DE5ULL, 
            0xC264525E21C8052DULL, 0x1004023C696BF567ULL, 0x62F34029ACF9B09EULL, 0xAF77E983F4D1363DULL, 
            0xC5A8330BD8920A5EULL, 0xED9A9F59A4371E1AULL, 0x41335AE8673FD7DEULL, 0x982D62D403BB7D5AULL, 
            0x7E9534940D881DFDULL, 0xD16510A3AE66D4BDULL, 0x7AA13E6A911FBAECULL, 0x789683EE8BBF14B4ULL, 
            0xD80C9F26A8B9C4FFULL, 0xE4278C817784C5ABULL, 0x936939AA87C8066BULL, 0x566A3CE8AB2F09EAULL, 
            0xFDB7307B6F1B7D75ULL, 0x6522837111C18647ULL, 0xC3B00BFF67532403ULL, 0x0CD271A5527CAE24ULL
        },
        {
            0x0E1DA09658E82F9AULL, 0xF2FEF0797B4000B6ULL, 0x0B6885E2634F9E76ULL, 0xC36D1243596BA358ULL, 
            0x36B888AE9CAB5F5AULL, 0xC0800850293E3341ULL, 0xA32E1C235DD59A81ULL, 0x564FA07EB735C4D9ULL, 
            0x09312B9D91A7C08FULL, 0x04C0A44431C15EADULL, 0xF61A034388E6140BULL, 0x7C16DD2D19FD56B1ULL, 
            0xBB1BA850DE4B1718ULL, 0xD814CF6F61750757ULL, 0x1FA3E8863F59B48CULL, 0xD50F61FD7FCE0DC1ULL, 
            0x5DCE934ADD48C98CULL, 0x09A76157758AB414ULL, 0x6F5CE9F6AF5A9EE7ULL, 0x3B8155BBA441F1BAULL, 
            0xE75872DB85984405ULL, 0xB99DED1A413657B9ULL, 0xDDCA67EC778098E8ULL, 0xD80EB90702E716D3ULL, 
            0x7F7734ED4F989A97ULL, 0x4171F4ECC378EAA5ULL, 0x98669F6E5C70072DULL, 0x5EED1225F2C567F5ULL, 
            0x37CB311BFC962EBDULL, 0x3BBF53DEEDF8CE7EULL, 0x3CA91AE5E5D0788BULL, 0x921EA89EA1DAB2E0ULL
        },
        {
            0x9BE607E9EA99203EULL, 0xF9656B70A23AE1F7ULL, 0xE5618214A0484E90ULL, 0xC1FD16DF17CBA527ULL, 
            0x368C4FF28A284B12ULL, 0xDD3FAC8C1703DDC1ULL, 0x42C19D7126F8DEFAULL, 0xDEFCD0C90D36626BULL, 
            0xAFFD1219F92D89D8ULL, 0xB30F20185AE1A53FULL, 0xA6324A5878DD464DULL, 0x00C64D7443EDA0ACULL, 
            0x7EB83D47C5B40D05ULL, 0x9A7BD2CAE8293857ULL, 0x21D5DDAB496EBD55ULL, 0xBEB92C622F5FB386ULL, 
            0x03C6A38CFA008821ULL, 0x9BB12223541A8595ULL, 0x62964B37F2C4F2C9ULL, 0x7AEE79983E54B764ULL, 
            0xEAB6CD02F1BA471AULL, 0x4ABE190F16003B51ULL, 0x0E5FF1B7DABEED19ULL, 0x79B04493AEB76AE1ULL, 
            0x96619EE7581E31B7ULL, 0x677492AB6292B452ULL, 0x73F257F31FC2118EULL, 0x2B20A5358E4B240DULL, 
            0x6829AA0A6A844992ULL, 0x9C89F82BF72399E7ULL, 0xF942A08A30A77708ULL, 0x7CD5661C0B6A64ADULL
        },
        {
            0x0C426C0420D02BAEULL, 0x687341548A1DE7BBULL, 0x983D796F2E6AD74DULL, 0x0DEA094668677DD5ULL, 
            0xE962B91AF8FC924FULL, 0x6C5A4D3E73B4DF5EULL, 0x7A1DBE486D80FF0AULL, 0x6B44517FDEE9B6F0ULL, 
            0xF323179B4CE0387AULL, 0x546CA7F73B57AF63ULL, 0x64FFB054AE75443AULL, 0x01413E09DF3D119EULL, 
            0x293BFB9972F0ED66ULL, 0x40EC11EFC466EF0EULL, 0x2349F710C013A1BDULL, 0xD72B75997654A01EULL, 
            0xEB6F416D6F242A96ULL, 0xB6F1E3285B2E5F2BULL, 0x4AF9D3C31652FE9CULL, 0x9F9F71E5FE918E7FULL, 
            0x00CED57320DDD5FDULL, 0x073AA440F2D38C4BULL, 0x80E6C00BDC22A446ULL, 0xD02C4416E8353516ULL, 
            0x0E7D051473FB171BULL, 0x042B49A5CD2619C1ULL, 0x5E6904286C024343ULL, 0xED868FD7A5073346ULL, 
            0xB05A94DA40C71140ULL, 0x35942E8D47AEE129ULL, 0x3A451CD89A7EE436ULL, 0x24DA04D8AD43DFEEULL
        },
        {
            0x19331672EBE339AEULL, 0x1EBE34D9C1F8B330ULL, 0x5FF36B3DE1213A52ULL, 0x74413457ABEC8B33ULL, 
            0xBCF645440DD7903FULL, 0x2AF1790ACCA42E02ULL, 0xB7EFC75AA69AE4C4ULL, 0xCBD978887EF786D7ULL, 
            0x3B1800842F54E135ULL, 0x0F88BC940E56347FULL, 0xE297003382160F3BULL, 0x002BAAE15D507C64ULL, 
            0xD592A2E5243F40E8ULL, 0xDFA4EC126E6206DDULL, 0x9BFE0467917748D5ULL, 0x89598B8B0149BB31ULL, 
            0xFE52779A4FBCCFEEULL, 0xFE3E2774E5DF084FULL, 0x58995599523D6E45ULL, 0x5E884BE550D22301ULL, 
            0x5C568047D84347D1ULL, 0xD1C84195BBE10A64ULL, 0xA10A020EC9E9C73BULL, 0xE30280AC12016EB5ULL, 
            0x786F0A9BD3360908ULL, 0xC4AE877B51E2294BULL, 0x0877415B5C3B8F9DULL, 0x9154567689E42831ULL, 
            0x21DC2DD2041BD066ULL, 0xE2562C74696176C3ULL, 0x8A5F8B19EFB221DFULL, 0x1DF509C30D4DD88FULL
        }
    },
    {
        {
            0xB997186D5CAFD544ULL, 0x33ECB60176D8F8A0ULL, 0x6CA0E0F4D7F1A5DAULL, 0x14EFCF287D85CC5DULL, 
            0x890973F580FAC80FULL, 0x393CAE0C2DEC2D45ULL, 0x60D09F39E37ACD9FULL, 0x02FC31C279DF3B4BULL, 
            0x811CC01E84790BA1ULL, 0x5C2143238E05BD57ULL, 0x5FADFA73395FB286ULL, 0x111B1279F457C907ULL, 
            0xAEA011FA62F79643ULL, 0x8BAF8977A6073D63ULL, 0x3A4CF2B2C8B7D0B1ULL, 0x42DBF2E031A333CAULL, 
            0xBC30FD78FC88339BULL, 0x04CD4B3AC557DFC5ULL, 0x3E3510A6695B2D4FULL, 0x43F2DEEC580CD948ULL, 
            0x48BC54762585E0CBULL, 0x2A0A27C1489041BBULL, 0x0C58D8557324C4FCULL, 0x25DDB4D893E45AD3ULL, 
            0x4C3791E1986219D1ULL, 0x0D479A82175F4A04ULL, 0x3A283AC84A148B20ULL, 0x59A91FE9300F04CEULL, 
            0xAB9E875A89B4EC6AULL, 0xA42D47C106C46801ULL, 0x82FF795B532D0D22ULL, 0x3C5E9BEAACF6F9D8ULL
        },
        {
            0xFD53EB5AD67B8E6AULL, 0xA97A6903D9447878ULL, 0xB81AF1CA44EE87C9ULL, 0x6C0D0FC6E7660AD8ULL, 
            0x9FF47647307DD540ULL, 0xF3FA1CBFDD6EC95BULL, 0x9BD07E0A9AE738E4ULL, 0xF55B74A530E41042ULL, 
            0x7F3811E8144C56B1ULL, 0x44AED08E9AA3CCEFULL, 0x3756ABED14E14D97ULL, 0x263F438C75272609ULL, 
            0x490D82D767C0BC39ULL, 0xEA8CD52CEEFAC673ULL, 0xFECCCA27FD0D0DF6ULL, 0x322BC8D77930735AULL, 
            0x5458533BE05501E4ULL, 0x72127DDB2174A224ULL, 0x373B87E745CCEFCAULL, 0x560B3F894F7E9075ULL, 
            0x6A8CA6B8061C431BULL, 0xD88C800935679F9CULL, 0x3636538CE2220CA3ULL, 0x414A70AE33DD1294ULL, 
            0x8478D027DA8B5D74ULL, 0x02C4E385F9E7F912ULL, 0xBB75EC89D67CADE6ULL, 0xCF8A72E270E8D52BULL, 
            0x72175BCA4E07CE99ULL, 0x2EF43571003F5B98ULL, 0xFC7D3052DFEBF7CDULL, 0x91136D846CFE09ADULL
        },
        {
            0x5390D88EA6BDD34AULL, 0x0F8453A6B2F410BCULL, 0x4C75D19FD01B5594ULL, 0x761E481B690E3D32ULL, 
            0x22029D6526F2E5D7ULL, 0x912A446A2875293BULL, 0xCE29724A5EA20ED6ULL, 0x0043C3917C0FCEE4ULL, 
            0xAEBBE334516A3564ULL, 0xEC637C9BEC0BD9F9ULL, 0x54B9E67A80ED73E0ULL, 0x9080961C0F9823A9ULL, 
            0x74F0412957F5FCCAULL, 0x29BBDDFEF575AEC4ULL, 0xCF05D1CA87D46F40ULL, 0x079EC051CA3BF4CFULL, 
            0x00780A1B98C1D29AULL, 0x3E306C98C20A4B07ULL, 0x9A57D7D4F19DD969ULL, 0xB32C6396B71FCF34ULL, 
            0x1CF9C1D083F95DE0ULL, 0x3D3B53DAB51B737BULL, 0x4F8264887489978DULL, 0x07758BEAC7DC976DULL, 
            0xABAAFE0C1B6A5ECBULL, 0x121318CBE4BAF751ULL, 0x5F91EF76F5CE6760ULL, 0xD12D5B3E85F5C6ADULL, 
            0xD365B1C455A024FDULL, 0x40C9F6FCD55824E4ULL, 0xDAD00F6FFF89D11CULL, 0x1E264156ADCFEF15ULL
        },
        {
            0x6E5F383B7F8F69C9ULL, 0xF30A0DDABD894F18ULL, 0xD6059296D1FA019CULL, 0x846F88350E7ED255ULL, 
            0xA5E2F437E5BB1CFCULL, 0x0DE8F9FF5DA69ACCULL, 0x5484B58DC0DA38EBULL, 0xD164E7186BD16629ULL, 
            0x47E2D12823DBE199ULL, 0x126DBC41C5C6422CULL, 0xB33FDEE11D51F84FULL, 0x296D67267F71BC52ULL, 
            0xEB4AD39FE66D9075ULL, 0x01A6A9735BC773CCULL, 0x214EF9D613B2CF53ULL, 0x833E5F277255C215ULL, 
            0x06F298249886A7E5ULL, 0x47DEC8DD4FAE4226ULL, 0x27A6D527255D9E92ULL, 0x9F4CFF7D5AA8BFDBULL, 
            0xBE2E22C29996E7A6ULL, 0xE9C6F5034ACA463FULL, 0xE4DCF39A718F9FFCULL, 0xBC083D4E5446A217ULL, 
            0x12F027E7349F9504ULL, 0xE9D2259CCBEC8AC1ULL, 0xD978E7943ED2552AULL, 0x9F1413AC41E3A9E4ULL, 
            0x30E0D84CAF93F1EEULL, 0x48FBCA6638F82FB9ULL, 0x3F0A5D0A300847CEULL, 0x79277FE9AF5890DEULL
        },
        {
            0x124A5FB70B932028ULL, 0x23B76AF8FC01B8FBULL, 0x626645666D44EF48ULL, 0x8690347A837F6EB9ULL, 
            0xFC1E5BC2C7865283ULL, 0xD7D0F58096A31BAAULL, 0xAE55006DEFC7E586ULL, 0xEEE144B8DC97C32DULL, 
            0x1881D85FE63958E4ULL, 0x03573ED669E2CE19ULL, 0xED949CD5C6F83B69ULL, 0xD14523B4C2FFD412ULL, 
            0xF91F7E60860BA972ULL, 0xEF52653B9EEC6E55ULL, 0xD86F35CE9DEF0B5EULL, 0x96E625C86B41D3FEULL, 
            0x98931E7EEE21C71BULL, 0x009BCE50ECF77837ULL, 0xEAB49AE5E6A5C104ULL, 0x83E9CD9364310168ULL, 
            0x17F554F4CD3ECB44ULL, 0xBE9477E64958F657ULL, 0x048E3815CD3620BDULL, 0x38DF3A9F6ACBCF97ULL, 
            0x7338EE3EF98B0B42ULL, 0x2223120AAC80D42BULL, 0x48B34FDC5B9880B6ULL, 0x4231096E7E40D4B7ULL, 
            0xE610309BEFE0FB49ULL, 0x60FDA3504E13FA4AULL, 0x16BCF8583DA84C82ULL, 0x5ED62C32AE4BFD4BULL
        },
        {
            0xEE890FB4FC779A6DULL, 0x0638EC2A04312A4AULL, 0x5E30B7AFFCDEB9D5ULL, 0x8552892B9D049566ULL, 
            0xB57C224387C0D65AULL, 0x5A7628AFE1F41449ULL, 0x334C180B2ADEF379ULL, 0x2075E3B6B0C4A34BULL, 
            0x1F01C53F90B16EFAULL, 0x9025BC45A04A4E79ULL, 0x9A7AF0DD7D0A3C69ULL, 0xB708DD4FDEB6EE7FULL, 
            0xE74122CFD1981AB8ULL, 0x754895067F3EE09DULL, 0xD1FE4A70E0DECA6AULL, 0x73F045B3B7F431FBULL, 
            0x18DF695A605A99B7ULL, 0x5C698128BD26DEB1ULL, 0x0B423561698181E3ULL, 0x98088E8AACF50A72ULL, 
            0xCEF93762AD0FED4AULL, 0xB70816BC1173EC2CULL, 0x80B3384AF3A56D33ULL, 0x61FBC2F580BD2EADULL, 
            0x74FF7D401CC919E1ULL, 0xAE1A997DA20B8AFAULL, 0xCC19EBE9D95A26DEULL, 0xF105EAF15944CE7CULL, 
            0xEFA8A88BB119FB4BULL, 0x1A462C237AD63893ULL, 0x8427D2AF181BDDF5ULL, 0x2B5FEC095FB3B047ULL
        }
    },
    {
        {
            0x3DEB9BE3A40288C7ULL, 0x6EA2A29BA024AD93ULL, 0x05017F062AE773FDULL, 0x4B228FCACF8C47F6ULL, 
            0x4906FD9EBDAB5F41ULL, 0x23705E50649F0EE1ULL, 0x983D4E766D9E20E6ULL, 0xE86C6E26E8370482ULL, 
            0x359C2945DD0A6AABULL, 0x16A3E5267E8C5DB6ULL, 0x52E02879A3AD89FCULL, 0x04F9747C0BE4F91BULL, 
            0x08A0615E23411439ULL, 0xF249B18749F45A03ULL, 0x6C8D16D863DFF2E5ULL, 0xD184881AF15E707FULL, 
            0x8C795D5680D043BFULL, 0x1FA460045DE95BA3ULL, 0x9A22BB0331508EA6ULL, 0x133AA7AF7F9994DAULL, 
            0xD9E4A603A0F6B72DULL, 0xB306ED5F26A0B6D2ULL, 0xD78F4CA50DF6B475ULL, 0xD3C2E00AB9EB0995ULL, 
            0x6AC03B3AA375D63FULL, 0xB3E888185DD9BC3EULL, 0x9B76AF0F5E12CEC5ULL, 0x5F1863D5F82B1637ULL, 
            0x3B8982627F213FCCULL, 0xB4BDFB970DFD3187ULL, 0xF0B0D5B1AA065E3DULL, 0xE07893A01575AD69ULL
        },
        {
            0xB02654BA5D4172ACULL, 0xEF4B2DB88557D214ULL, 0xE82469C122D5B29CULL, 0x94EF7ABB85152F8EULL, 
            0x16E133DF56A32BE7ULL, 0xAEBED1D801294B03ULL, 0x20B5C235A3CEAD9CULL, 0xE58E573D0837529CULL, 
            0xA690ACAAFD16229FULL, 0x2DCB26183848977AULL, 0x4D59FBDE30CC57ADULL, 0x667CBA3E3F6440CBULL, 
            0x7091AB45E5B59F59ULL, 0xADA586CC43059265ULL, 0x25B0511589299631ULL, 0x4DFBD81AE0F36010ULL, 
            0xA8284DB80943E9DDULL, 0x71B99C0D9F42B505ULL, 0xFA7329E233E66C51ULL, 0x8FDDAC5907684D27ULL, 
            0xB6353750A9D57355ULL, 0x6D72BB51018FEF4DULL, 0xA8FD7B1EB12B13E5ULL, 0x82E18E39E3169535ULL, 
            0x1F13858EF66DE171ULL, 0x0EDBD055246DBB3FULL, 0x3676A240432F8774ULL, 0xEA8807C0DBBCD7E0ULL, 
            0xE29D00B80AB27888ULL, 0xD7901BCEE4887FE9ULL, 0xEBB622997AEAB39DULL, 0xF25726454FC64FE1ULL
        },
        {
            0x69EDAF8F7B8097C6ULL, 0x46351DB1DE0F5DE7ULL, 0x4571D27602A11C07ULL, 0x43FEF1F46ACBA17CULL, 
            0xEE89AD1B31C0CA61ULL, 0x03A8F4D768EDFAE7ULL, 0x779E2211CD738724ULL, 0x109CEABE3B24E42EULL, 
            0xFEE5285F32504190ULL, 0xAD6F5197F512156FULL, 0x691F2E856C2D4F12ULL, 0xA65EBE841C9DB9DFULL, 
            0xE9C0E521849DEE69ULL, 0x3E7124582AE2FC67ULL, 0xE41B447B1B2998AAULL, 0xE369C1FD46063197ULL, 
            0x90F3139D8DEFD3BDULL, 0x36ECECB0993930CAULL, 0xF75B386D7819D78AULL, 0x629CD90E9F1C0447ULL, 
            0x339D21E845EF3F5EULL, 0x7A1F4B0067D8281DULL, 0xCC56202D52FC7489ULL, 0xA77C7785E112D615ULL, 
            0xC0C9B8A950C54ED3ULL, 0x018E30C196BAC930ULL, 0x0C7724A8DABFAE64ULL, 0x11DAC8F34AA06300ULL, 
            0x634707F5D657D87CULL, 0xD5C6A66012080C1FULL, 0xFB3AC521D915D67CULL, 0xD4915C70ACD5EAACULL
        },
        {
            0xC3B8184D34107853ULL, 0x8351C10CFE3CA41CULL, 0x30F08933406A6677ULL, 0x32BA20A2423F2D6EULL, 
            0xE50FB584F81B1053ULL, 0x8E13CF02168D6732ULL, 0x64A4DDD4939BC457ULL, 0x0943D284FFBED395ULL, 
            0x4512176F7E0E99D3ULL, 0x77EF52DE88A19DC8ULL, 0x4C343B7B52EDCF99ULL, 0x518FD5AE5B04893BULL, 
            0xBC9A5AE649F84B92ULL, 0x5FA4D85F209B8F94ULL, 0x3FE29F28CE5F2F8FULL, 0x7D784F6A059DAB95ULL, 
            0x9D001798FD6580A3ULL, 0xDE6A652359CBCF48ULL, 0xC689F178696147CEULL, 0x345C0EF4FAE109FEULL, 
            0x3D2F1E60B07CF094ULL, 0x7BE9801D6BE97CF7ULL, 0x8F9DD3B91AE3DABBULL, 0xC19836129FE06FDEULL, 
            0x1DDD9E0076E2E448ULL, 0xB937728903420BF6ULL, 0xE12DCC9575870342ULL, 0x1F163B35CDEABE89ULL, 
            0x83087A230377BF9CULL, 0x2147EF45D47557AAULL, 0xFC9BE748888F39D5ULL, 0xC8D6900F79CF174DULL
        },
        {
            0xE7A037BE5A52B1F2ULL, 0xD121D7B5AB354F7BULL, 0xF925532F2E506317ULL, 0xB2BE77618161DFB7ULL, 
            0x2398252CFEF269D1ULL, 0x22EB0BF58FC49C67ULL, 0x82ACACEE9413F28DULL, 0xBF88DDE75D306A01ULL, 
            0x1E1B1665E576A6A1ULL, 0xDA161CE76F24FB26ULL, 0xDD4A4FFE2A7BE8ECULL, 0x971A3CDA76E44665ULL, 
            0x89DC9B3B58814F87ULL, 0xAF5FE0350B58B099ULL, 0x2296C135AACD6039ULL, 0x427E0AEEE27DD7ECULL, 
            0xF6A847C5501AC8CBULL, 0x303A8B4ABD9E6DFEULL, 0x34A82D5498152236ULL, 0x3024BF5540A0832BULL, 
            0xAB74D10609BCA705ULL, 0x66B4B81DEEC77DA9ULL, 0xE6BD1769F6E61D18ULL, 0xD4A0EAD144F3D106ULL, 
            0x074E03D01D7FCB17ULL, 0xF107D3550D959818ULL, 0x3F417139DB0C2835ULL, 0x34A130F60AF1AA7EULL, 
            0xFD79F4722371817BULL, 0xDB47D89F81FF1178ULL, 0x4F059FAD5E05ED8DULL, 0x051C7617E0D4A8FCULL
        },
        {
            0x8EEEB1BC04BC5A60ULL, 0x395DD8965145102AULL, 0xB34C10C67D3A7286ULL, 0x12C157ACD359EE14ULL, 
            0xBE5FC0CF9E95A539ULL, 0xE5D6EBA4FC81DBEEULL, 0x793A4600E6B34EDBULL, 0xF41E2C82C086AC4CULL, 
            0x34C68EA78BAD4CABULL, 0x74678CB229BE2C9AULL, 0x1E58887E71EDB7DDULL, 0xAC85E403941F7E08ULL, 
            0x4C107E5422B79D21ULL, 0xF292E5EC1D560FA5ULL, 0x63E79D2209CFB8FBULL, 0xC41899831CCD9135ULL, 
            0x06478E0EDED77B76ULL, 0x577FED86C4956169ULL, 0x9C6913BC29919849ULL, 0x6ECE068CC0FBE735ULL, 
            0x21747032B7C9A1E1ULL, 0xA5F088F405EE8791ULL, 0x16FAE39E6A3B8AF1ULL, 0xA27FCB4A6D0D7348ULL, 
            0x8A783298F026B26EULL, 0xEF0D4315C6E69E01ULL, 0x18E8217D096E638DULL, 0xD9EF9D6D1E4D3505ULL, 
            0x43181590BB19ED09ULL, 0x22C3F654D398329DULL, 0x34843CDA4AAC47FEULL, 0x8C31E1FCF29C4A1AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseDConstants = {
    0xC776A5F12BDB75EEULL,
    0xA169A2DA2769E7BAULL,
    0xF47552A06CDEAF8FULL,
    0xC776A5F12BDB75EEULL,
    0xA169A2DA2769E7BAULL,
    0xF47552A06CDEAF8FULL,
    0x98E4D18259CE49A9ULL,
    0xBD9E7705E7F489DFULL,
    0x9B,
    0xF5,
    0x64,
    0x91,
    0x70,
    0x06,
    0xB2,
    0x1C
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseESalts = {
    {
        {
            0x166B0BA063E1429BULL, 0xB8786E3D31172DDDULL, 0x91068EBDE86C7B67ULL, 0x3EFED069853D8C45ULL, 
            0x25A60DB92DB337D9ULL, 0xC3E091FAD65FADA1ULL, 0xEE2FF966A7D101D6ULL, 0x0CA84D6901498E41ULL, 
            0x7EA699FF9824D88FULL, 0xEE852389AB194F67ULL, 0xC085C8D921927ED5ULL, 0x1593675131C46CBCULL, 
            0xE4C563AB2C2F7DBAULL, 0x440C615B1A38B1D9ULL, 0xFCD964FBA6FB6A67ULL, 0x3B6CC4BFD2530C7CULL, 
            0x698EA0DB53D4B3DEULL, 0x2AE546726A7E52F0ULL, 0xC630CE14CD62BCC6ULL, 0xA1C1E25EF2171D9AULL, 
            0x99E02CC74A5663F0ULL, 0x61E404D5906E9081ULL, 0x9A210C0CD7FE87E2ULL, 0x4A9058AB0C40F946ULL, 
            0xC2B84007F0913765ULL, 0x8E1A65A57CCD2784ULL, 0xF51E4CF6E5E1F79FULL, 0x3F3D1E7E57652D99ULL, 
            0x2C5B657ACC519252ULL, 0xD1A10B626F53407BULL, 0x07AD97CB94B58A9EULL, 0x82EB154D62DE3059ULL
        },
        {
            0xD541F77237BB9356ULL, 0xD08838EDF85AE3A6ULL, 0x027514AEAFA7744FULL, 0xBB614A17F134E6C9ULL, 
            0xEFE0C46C167C72FBULL, 0x1359B4973A87DA69ULL, 0xC3EA175303702C38ULL, 0x91B392EBA0097FC5ULL, 
            0x6FEA472C2CEA28C9ULL, 0x4F450539DFB0F624ULL, 0xC4F1DE3F9735AD2AULL, 0x58CCBF5E6E46BFD7ULL, 
            0x6FE1DCF3ACBEABDCULL, 0x2B534EC8574F4374ULL, 0x9200DCC55410A829ULL, 0xC5E5847655E61A2CULL, 
            0x851093E4A8C12ACBULL, 0x4F7100D2A10A6354ULL, 0xBAF87816976E14D3ULL, 0x12B278DA569D595AULL, 
            0xE8EC3E3D3CCFCFEBULL, 0x50932F7CBD6B9A17ULL, 0x5011B56F20622DE2ULL, 0xBB4001010DBEC03DULL, 
            0xC95F442680CA0E0CULL, 0x2741068347DCE5CBULL, 0x378661CC332C2790ULL, 0xBCF8A617B1242B14ULL, 
            0x9135707D2FDBA7F4ULL, 0xE071F7C0CDC86139ULL, 0xF1D1F7C0B727C2C6ULL, 0x62BE942396AEFE7CULL
        },
        {
            0xDC85B2726B62A0DBULL, 0x1985FCD335371BC6ULL, 0xFFD5ECD83842BF24ULL, 0xDD7F90363E2368D5ULL, 
            0xA0EBCDB0130DDA10ULL, 0x134A5C264D34A63EULL, 0xBC105DC0B142D7E4ULL, 0x0C925A61B0525235ULL, 
            0x806895D7AF25EBDAULL, 0x6952E8623EB8BA11ULL, 0x4BCBC0B102A54698ULL, 0xA50600121717F7DDULL, 
            0x3CB7D6EA5071CB0EULL, 0xC2D389D1B8F83395ULL, 0x0D53E4B31185890DULL, 0x60A9011F358BE006ULL, 
            0xC4AB480197279563ULL, 0xD96782884F780528ULL, 0x17461608C9DABBA5ULL, 0xFB8265E03C0571FEULL, 
            0x784FAF21999C48DFULL, 0xA47FF6A67ED6878AULL, 0xF958822E1F6D1348ULL, 0x0C46F30DDD86FBE8ULL, 
            0xAC39E3D86F94C478ULL, 0xDACFF361687BBA6FULL, 0x8926E9C70A234113ULL, 0xA85004CED8096280ULL, 
            0xE4D82CE42E1E8710ULL, 0xFA094E521E09997BULL, 0x626FC32037F57940ULL, 0xF3CDD90A8C905E74ULL
        },
        {
            0x38D6C8D3366FB937ULL, 0x7DCD845D537512A7ULL, 0x20170A7C01B22D94ULL, 0xE3E5D9804C6582F9ULL, 
            0x859E358E3D6514A7ULL, 0x2C2880D18D08F8EAULL, 0x0B147DCFE88150EAULL, 0x95A4D15A1D9677A1ULL, 
            0x8032067A05CA4F3BULL, 0xD6382AB7784A2CF2ULL, 0x441B64697F46CB8EULL, 0xC546DC6E09EEAD86ULL, 
            0x5F614B6840E265B3ULL, 0x5940B747BBDDC3FEULL, 0xD657BDD11C53FE47ULL, 0x0F415DC03BA1197BULL, 
            0x1F92877439C84402ULL, 0xB7B8C8EDC64E36FEULL, 0x7063CE4D353722ECULL, 0xF77E42680432DE3AULL, 
            0x718B137E1D631A54ULL, 0x5DCB6938683792A3ULL, 0xF3A3A66890ACD6A6ULL, 0x0E79F3020ED9DF61ULL, 
            0xE2027214FAAED4BFULL, 0x3CC4DE54FA49F1DCULL, 0x168B3E7CABA0D88FULL, 0x9686C01CC945533FULL, 
            0x9929EEDE097D0BA5ULL, 0xC33A74A98610FA55ULL, 0x46C6BCBE634D9515ULL, 0x3C439DC41CB7D922ULL
        },
        {
            0x9CEF140EE76336DCULL, 0x697F8B26E600339BULL, 0xE414E385AB88A7E1ULL, 0x9943ED7846E33C5AULL, 
            0x2F0F471AB4ED2B45ULL, 0x3AC4AB3C23BA4B4EULL, 0x5EEE8D530872B93FULL, 0xE818F62BF3316C51ULL, 
            0x0F145269B708B324ULL, 0x2BCE6FEE459D33FCULL, 0x5306FFC5D24790C0ULL, 0x56C3FB72A907A150ULL, 
            0x7566D517A62785FFULL, 0xEDCCD8A02A6899DBULL, 0x2D3FA3DB48D334B4ULL, 0x7E40BB4AA41A9DE1ULL, 
            0x38C0A31E8970A2E4ULL, 0x0B7216A1C12A98B8ULL, 0xBE292CE5D87FC30BULL, 0xDCB6D5533A315813ULL, 
            0xC795E7788AF4BCB3ULL, 0xC459519A160393C9ULL, 0xD5D9F857852746C4ULL, 0xE25A5985167E0E79ULL, 
            0xFB5A5D16BF82F3C2ULL, 0x3F7FB58ABA60071EULL, 0xB87F177C48497983ULL, 0x35827AE7F399B261ULL, 
            0x9B074B9D962A0EA5ULL, 0xCE34C009007499D6ULL, 0x3E2A924F03216903ULL, 0xA6F8D1DF0550936FULL
        },
        {
            0x4DFCA8E3ACA7F12FULL, 0x676B17517C870A25ULL, 0x963003DA3DE25244ULL, 0x7450D2850525D5F8ULL, 
            0x1EBF2EAC3F9354DEULL, 0xF82A081EDCFBD3D4ULL, 0xD60E955B35CDB605ULL, 0xE2D2D7ED9593829FULL, 
            0x9E02324B759C4F59ULL, 0x63BE3C62E4C5EE16ULL, 0xF26653854B896CADULL, 0x93B63DD91FA50ED1ULL, 
            0x3DA4D42D0ED82B6BULL, 0x33BCDAE59CB5C581ULL, 0xA3400C65EA9302C1ULL, 0x1D87D4DF6F45EDDCULL, 
            0xD497659E1DDD6897ULL, 0xC6FD29E8F61CE392ULL, 0xFECF420D9E507A77ULL, 0x89CBC133B7C5F205ULL, 
            0x77A153D0C01D81AAULL, 0xA2A5A223540693E9ULL, 0x9E842D78CF58578DULL, 0x905F31BFBF5070F1ULL, 
            0xAE1F19C0A0E2F881ULL, 0x9D23F83C3BDF145DULL, 0x77B044864A0BF227ULL, 0xA15519A66A88E226ULL, 
            0x44E1504590A150CEULL, 0x82113D341BEEF15DULL, 0x4E17CCBA4A3888ADULL, 0xFBBF9E582176B206ULL
        }
    },
    {
        {
            0x44EDD812753A6C83ULL, 0xDE5F736C527BB09AULL, 0xA96F1CBB7417DC48ULL, 0x52947C1178241AC2ULL, 
            0xCC88DC6173B4886BULL, 0x6536811BBC3D3CDAULL, 0xB52DAC2F4EAE779FULL, 0x883CE3E65135F1A5ULL, 
            0x69978C528B3D61E4ULL, 0xB94A587AD42D17C9ULL, 0xF3DD9BA9F3950F7BULL, 0x98920BF78DA40FC6ULL, 
            0xD65BE89F4CB1D087ULL, 0x7B54162AD5580E91ULL, 0x3DDD5C1972331114ULL, 0xC37647F8EA99A00DULL, 
            0x0BEE2F7C69B471D3ULL, 0x06AD699C9DC1A926ULL, 0x84705295AD2CD8DFULL, 0xBA586C87EFBAE1BFULL, 
            0xC887BF97721B99E8ULL, 0x0900B98F43F62BC4ULL, 0x7899FF6F37669CC7ULL, 0xB68C5950FA93AB9EULL, 
            0xEABA98151E606711ULL, 0x29D4AAD850A572D4ULL, 0xBBD6EE392B18BFC6ULL, 0x4A1F9FD10E0725A3ULL, 
            0xBAE0D1CD923EDDEFULL, 0x8560B83C7CCC4F17ULL, 0xCE0484F229D1BB0AULL, 0xE68D1034958FBF58ULL
        },
        {
            0x8DCECC791B4A4547ULL, 0xF5C245FE4A2D07AEULL, 0x23DF40C056B3CE5EULL, 0x5ECA11B8A0B45788ULL, 
            0xD805495AE904ED74ULL, 0x081D8ACD4D5A603DULL, 0x4B8D5E6176C8F239ULL, 0xC6BD03C681190976ULL, 
            0x7073B843CF00E09BULL, 0xC5244B7132D306CCULL, 0x453E087D64DF18A8ULL, 0x243DE3E39B9CC7F4ULL, 
            0xFFA46EB248DFAE58ULL, 0x1900EFD7A1B3F0DDULL, 0xE851781827DEDDEDULL, 0xA2FCD213E514634BULL, 
            0xE55D923AA8CDD3B4ULL, 0x64B7B4C9EFC75EC8ULL, 0xACA306A7F8774BC5ULL, 0xFDAAAB18D9945B92ULL, 
            0xA8C1E851A66FCF43ULL, 0x51E2C912399D9635ULL, 0xE9C99F176108B089ULL, 0xC30C09D7684F9F3AULL, 
            0x4706717E92F8BAFAULL, 0x7269AF609E01699FULL, 0x3755D727842D311FULL, 0xCE5D9689013C345AULL, 
            0xA1DA503487B3B945ULL, 0x0657587E38A1D40CULL, 0xCA44F789380C5D8FULL, 0x5AA109204D92E05CULL
        },
        {
            0xE29D972E52C25628ULL, 0xC95ABF55126E7296ULL, 0x6DACDCADDE387EFAULL, 0x1B71AC0975357A8CULL, 
            0x40BC0D01F514C93AULL, 0x8E175C150B5C2FBDULL, 0x4DC55EE85F7A2832ULL, 0xE1EF21231D0A6339ULL, 
            0xA490217A47D7B3B2ULL, 0x5EBCE13248CCB93BULL, 0xCE5FADDEFEDC09C9ULL, 0x972EED6F6181B33BULL, 
            0x59B2FBF82F48C69FULL, 0xBABB9235034312AEULL, 0x81B9FB86739D4351ULL, 0x848726E3924B60C4ULL, 
            0xE8523E1FDF841C4FULL, 0x4306E8126ECA4738ULL, 0x1B73EAAFFD6FCAD7ULL, 0x55A3EAB80098D732ULL, 
            0xE0F4724D9AF90E61ULL, 0x8D38399F405C43ECULL, 0x5366778C7D967511ULL, 0x2F0D779AEFCFFE44ULL, 
            0xCAE4227A0377AEB1ULL, 0x4136C77AB7B3DD96ULL, 0xD9C090D5EBA47DBAULL, 0xBF8BB69D530CAE36ULL, 
            0x474E75F93A0E2E9FULL, 0xFBBD29DC4BC50ACDULL, 0x79FC3D509ED65571ULL, 0x89CE0F1751D32767ULL
        },
        {
            0x7A997A13BBE1932FULL, 0x3792F5F6A9173D3BULL, 0x94B1E7293FF76887ULL, 0x9572472EE6620876ULL, 
            0xEE89DE243F7DDA84ULL, 0xFA0B812761F82329ULL, 0xB66A0188CDE8CF88ULL, 0x35FEF1ABA5852C3AULL, 
            0x4E91C2446AF579C5ULL, 0x50AAC3D09085C8CBULL, 0x30A8047EA1B82CB9ULL, 0x13F4CD32A80F8BEDULL, 
            0x19EFDBA9F5C9C606ULL, 0x2B2BAB280DDE8541ULL, 0xDD789EA8AB3B2A61ULL, 0xA3239C2F6A45EAF5ULL, 
            0x01302A444881578DULL, 0xBBE383118D0C1D1BULL, 0x16BACF8BBEE70E9AULL, 0x5B732979DA27B0B8ULL, 
            0x2205D0971A4474D7ULL, 0x504C7AC14CAAEBA2ULL, 0x86D5911DF0D5980EULL, 0x67299165C9550976ULL, 
            0xB88FF0D1607F4745ULL, 0xC3FBCCD0D880EB7CULL, 0x4F58709A2A308605ULL, 0xDABE2073A5D4B027ULL, 
            0xEA406BF5E0418AC3ULL, 0xAC7C22A8054A77C8ULL, 0x5613BABADFA33F8FULL, 0xA3E6BFBFC673C07DULL
        },
        {
            0x56CE01668796179DULL, 0x3EF671088224848FULL, 0xBCEAE7E751A5982AULL, 0xAD4AFC09EC90A897ULL, 
            0xE26951B8ACBE4FDFULL, 0xEDCBB4549B35B9A0ULL, 0xF1CBDBE960A4569FULL, 0xD03EB5E8BC423165ULL, 
            0xF360237209D3177EULL, 0xBB9D1FC1F7BF44AFULL, 0x50BD8BCBA6101D8EULL, 0x9DF879C6ACC84DB8ULL, 
            0xA2B3E9B842E376AFULL, 0xD592CA8D90672892ULL, 0x6C23970C8F9636F6ULL, 0xF68C4B41AA92DFD4ULL, 
            0xC7E0AA8DED8342BAULL, 0x5345B1AF413D47BEULL, 0x484AA7B27AD4D6DCULL, 0xF3F2DDDA2F98F216ULL, 
            0xD171A0FF55E98CD4ULL, 0x5EA5FBD31CB1E283ULL, 0x13C985A5FA95247AULL, 0x67ACD090465B8770ULL, 
            0x4998F13EB5872C7CULL, 0x660690166700138EULL, 0xDA90776B9C465081ULL, 0x8833A3834A547111ULL, 
            0x377615D7D9794CA4ULL, 0x30630FAEB999AFCBULL, 0x02A7FF1C9241EE6BULL, 0xC131522DFE4EB148ULL
        },
        {
            0xD9EF0015CEECE593ULL, 0x4485253F508FB9E1ULL, 0x3AADE6CBF0BD4ABAULL, 0x3D481544E2523A21ULL, 
            0xA656BD9B40B45A56ULL, 0x7AD7DFC9C0630EAAULL, 0x560E53C85EAA50A8ULL, 0x020C5F706E724E92ULL, 
            0x785B28E986F03025ULL, 0x48A28CCE32497A6EULL, 0x4F06EC8586AEEF95ULL, 0x6692479DC1939F85ULL, 
            0xB3FE9A294C2E9BE9ULL, 0x7A9274B21B860B15ULL, 0x661B5D4EFC4E5A59ULL, 0x3A994A12CCF938DAULL, 
            0xCCBCBAED938BEEDDULL, 0xEE6D2D7173FB13C0ULL, 0xA2C417F22B1E0918ULL, 0x0AD18452D88C39C4ULL, 
            0xF9E197F113062409ULL, 0xD0025FD5A348B9F7ULL, 0xAB73930E0A892C0AULL, 0x5E578A1D53E75A92ULL, 
            0xA33A9F65BB56231EULL, 0x9FF1DABC0A12AA82ULL, 0xC01EC00CC846B988ULL, 0xA79A7A1F952832E3ULL, 
            0x667EB4389AF82422ULL, 0xE7E63BC6C886ADFCULL, 0xF9797C0151DF3132ULL, 0x33C9FBBF593D1864ULL
        }
    },
    {
        {
            0x3302A14A11CCA8D1ULL, 0x06C181889F1C202CULL, 0x84569289D4A2C0F6ULL, 0xF58D973F7170F019ULL, 
            0x155B8B72AF005CD9ULL, 0x3BE5DBF28CD8A041ULL, 0xA622FD8A492D2A24ULL, 0x443BD190CF8F32D1ULL, 
            0xCE473339D3EDE715ULL, 0x43641F1E5BB6ACA8ULL, 0x817400B1E8ED5373ULL, 0x1F64E346DAA56FBAULL, 
            0x0DD8718B4078B9BAULL, 0x705D55881869246FULL, 0x0B3932423BDC1599ULL, 0x53E1D90784BC5CFBULL, 
            0xFF4D51D8F552A985ULL, 0x0E9A0D2D3FFA1C15ULL, 0xF8ADBC2D5398DE85ULL, 0xBF7DAFCDC16EACADULL, 
            0xABD3336C7A6CD044ULL, 0x141A6A0DA31AF4B2ULL, 0x6BF511DF86F543F8ULL, 0x96BDA76A12DE5D2DULL, 
            0xC91AF4F3DD0F9E85ULL, 0x78E018AEC7EADB7BULL, 0x0B921C1C31002767ULL, 0xCF79769268002B96ULL, 
            0x6A9DC1830C4C499BULL, 0x638AF035FDED3DB4ULL, 0xDB3993F769DDEDF1ULL, 0xBED0CBD9E71CBD4FULL
        },
        {
            0x20CCE802DACFC60AULL, 0xEA0EB13C2165C380ULL, 0xE2EA5BC96430F5F3ULL, 0xAE3F46556CDF8D2FULL, 
            0xADE0A3F6C01F84BCULL, 0x0B2E26F235FBF500ULL, 0x697C3ACF0CAE0D9BULL, 0xDFC38BCCBF2EF16FULL, 
            0x93C76274B45B2E32ULL, 0xDE075DCA63E0796EULL, 0xE79FCCEB8B0B6A9DULL, 0x8DD04C57D919CD02ULL, 
            0x3AE23374DE2645B7ULL, 0xEB7B1401733C6BD0ULL, 0xC66C84BE5B50EA71ULL, 0x80F64BF907120BEDULL, 
            0x40A65FBECE04BB66ULL, 0x09493150CF84B351ULL, 0xD883DCF1EB80E1C7ULL, 0x1AA213E00C916E85ULL, 
            0xBFEB0AEF80BBCAD5ULL, 0x03724316D7E40AB7ULL, 0x06D8DCB57C85C66DULL, 0x9DA438488B681D14ULL, 
            0x76BC043F0C969093ULL, 0x920DD14A78041149ULL, 0x7D82160972E363F3ULL, 0x3064E551B1A6B16CULL, 
            0xCD7C248C73BA1C0BULL, 0xEB1BC5AC906E71DBULL, 0x203678955285EDADULL, 0x1329F6BF529C28E8ULL
        },
        {
            0x7967460EDB7C832BULL, 0x744D2702E1F31E6DULL, 0xC0275866AE028DF7ULL, 0xA905F25AC7783A60ULL, 
            0x09AA1F2709452BE7ULL, 0xEE03A2A4AC628EFAULL, 0x72021E19335BAB40ULL, 0x19998A1033A1FE16ULL, 
            0xC279D12BC8A25F29ULL, 0xB64321A5BBE6E115ULL, 0x8F2D89D6DC11D352ULL, 0x8C27E196ABE85874ULL, 
            0x1216313FC6D9B205ULL, 0xDCBCF93591FFCBFCULL, 0x7280307805FFAC91ULL, 0x39042FB0AD5DB632ULL, 
            0xB695513A2AE847E1ULL, 0x392C0CA72B58F2BBULL, 0x8A23DA2F6D8B9D88ULL, 0xE7679E1E195E8D81ULL, 
            0x606A24DA649F7434ULL, 0xFD665C5DE1C2A618ULL, 0x5DD3538A7D14FEC5ULL, 0x282A1E73A07CF70DULL, 
            0x0188A4E7B7EFF242ULL, 0x467341FAF248BF3AULL, 0xDF079F9DF4C8773AULL, 0xFDBFEC0F7FA8C6E3ULL, 
            0x3FA97CDA2334725DULL, 0xB5846C524B428A19ULL, 0xE8B50C0E1596C2F5ULL, 0xC98A345AF9458F31ULL
        },
        {
            0x0C5F2F56EBEE44F0ULL, 0x2000B877A42CFF57ULL, 0x71735CDF572C6D99ULL, 0x5F1D4A6F51A2ADF8ULL, 
            0x62A51DF41AD28E27ULL, 0x37F1D9F272372AA2ULL, 0x8FEF9322C932AE4EULL, 0xCA599FDBD1EEDBCFULL, 
            0xF8C7E6563F6E89ADULL, 0xE29D3400F6F6657AULL, 0x51B0CC6080FD6A00ULL, 0x89FE602504FC0579ULL, 
            0x0B7652CF1B494E6FULL, 0xE006726D99383F16ULL, 0x8CD32F0F21AC75E3ULL, 0x0BF4D750BB3B31F6ULL, 
            0xD2990EC27D4E6C6BULL, 0xB129BFF838A63C54ULL, 0x2696F7FCCAB71D91ULL, 0x612D514ED9849608ULL, 
            0x587AA5919A8139B0ULL, 0x94C6F3BB471D698CULL, 0x6BE0F0C160D55DFBULL, 0xEFCDA7AE49988613ULL, 
            0xF216DED5ACD500BEULL, 0x56E3B08D453ADDBCULL, 0xD952F12C3A3EC3EEULL, 0xBFF51D903A5C1771ULL, 
            0x4F95D44CDA06D376ULL, 0xE30FA4D5568BB869ULL, 0xC10446F40AD847C1ULL, 0x91CEEE25FD10031CULL
        },
        {
            0x09C760443B8129F6ULL, 0xCDF2E1E349E19937ULL, 0x7C12D9805DD7A5ECULL, 0xEE774926A5FF5C88ULL, 
            0xA398503DFA7DA715ULL, 0x490348F3435F0FF6ULL, 0x02CFA6EA0F4B0535ULL, 0x5CE5460750FC47D2ULL, 
            0xB2926252B9CC8FCBULL, 0x9647B64760C256ACULL, 0x0E6C468C2322A4D5ULL, 0x5C163004049E7EF3ULL, 
            0x498FD918A2AA9D9AULL, 0x8AA6EA78EA903F11ULL, 0x951EFA67F2DC0557ULL, 0xBC67074EE294582BULL, 
            0xD6874691CA75A8C9ULL, 0xDD87E723FB20902CULL, 0x8D3B3465A89F3DA9ULL, 0xD7598320F9FBF542ULL, 
            0x28139F21459F617FULL, 0x4DB83A5EAC89E590ULL, 0xE0D9906918549416ULL, 0x4EBE6B8CCDAE6659ULL, 
            0xC85A364B917C6B7CULL, 0xFDEBA0AD8DD2E39EULL, 0x923BC8B4E1802335ULL, 0x8A49C5B63985F25AULL, 
            0x345634395688C64FULL, 0xBC54D3F0838152A0ULL, 0x619E00E516509882ULL, 0x5D48790BD4428679ULL
        },
        {
            0xC94A239D97A9231BULL, 0xF0A3F07D08CB4C5BULL, 0xADDCB7822C14BF12ULL, 0x97CC35B8D9E2183CULL, 
            0xAB4CE7F755744752ULL, 0xD99F8484CC8E9A88ULL, 0x511E77726E939554ULL, 0xA1BB4798AD4251AFULL, 
            0xDBFD4F775FA3E05DULL, 0x346BF5CED7D9D933ULL, 0xFEF1C90D2AC87A7EULL, 0x3161E2B1BEF97792ULL, 
            0xEE6B7E708927B457ULL, 0x5A77AA689262BF99ULL, 0xE54C266C884F553AULL, 0xA1073FD7DA6C2223ULL, 
            0x365A0AB264215296ULL, 0xA82D4361702183B5ULL, 0x889E73CC4C04763CULL, 0x85C33FDFB12D055DULL, 
            0xACD22C637D8B462CULL, 0xAC4A54FF4904552BULL, 0xAC6BEDEE540A5E0CULL, 0x4F5D4D99D67E3763ULL, 
            0x57FB7776BB7CBDAEULL, 0xEFE2410A0B99DFBAULL, 0x1512847F2AA0449BULL, 0x5C6F90F324AEBBC8ULL, 
            0x6CE959E14BE0F39BULL, 0x08A2A7E606A83628ULL, 0xABAE06BED0D7561EULL, 0x23053913B4ACD23EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseEConstants = {
    0xD74613AA93F4F39CULL,
    0x40747FD716E6C514ULL,
    0x2CBA2FAF1DD6AC0DULL,
    0xD74613AA93F4F39CULL,
    0x40747FD716E6C514ULL,
    0x2CBA2FAF1DD6AC0DULL,
    0xEBA5318D31505D6CULL,
    0xD98761D390E3BB63ULL,
    0x97,
    0x5A,
    0x5E,
    0x34,
    0xCA,
    0xA1,
    0xB3,
    0x49
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseFSalts = {
    {
        {
            0x439B6B532A5648F9ULL, 0xD7D429CABE048463ULL, 0x4087E3FA7FC1F522ULL, 0xC05553053B7A30D9ULL, 
            0xAD1EB127F7F4142CULL, 0x6A950CD86D07E165ULL, 0x26B1C53C47EC7274ULL, 0xEEC61E274DF19D88ULL, 
            0x7DD98DB4555FF3FEULL, 0x8E901C071F3412C1ULL, 0x26756A0349DC016BULL, 0x1D3E1565FFB422CEULL, 
            0x49360C5D999DBFD7ULL, 0x8C70F5B8D39FCC0FULL, 0xD112E3C25BF049D3ULL, 0x0020FCBB5E7FDBECULL, 
            0xBB236B65484DCF58ULL, 0xCDD1D0BD5A8778A1ULL, 0x444ACB3B05CD067EULL, 0x620B0D6D554B7F85ULL, 
            0xF62F852EE41BCD94ULL, 0xAB6C6CF9F3B76B37ULL, 0x3915F0B3F5D203B9ULL, 0x3AD9C6FE20522CC8ULL, 
            0xBA620072562287AEULL, 0xD1C66568227163BBULL, 0x9E9A2459A5230698ULL, 0xB12C80BF7FED60EBULL, 
            0x763EEA8A393AC577ULL, 0x7B7BEEEF404B6D11ULL, 0x8B9A0AA6AA1C0DF7ULL, 0x1CC291278DE2D388ULL
        },
        {
            0x55FF86AADB1724D2ULL, 0xF96945AC36D46B63ULL, 0x34C5AA9D05787287ULL, 0xC846BBD6536496C6ULL, 
            0x29796C0FBCD6079AULL, 0x761DD5A67113C515ULL, 0x93F5A38DB92E7579ULL, 0x6173C2826E497C34ULL, 
            0x193F78B4C087736DULL, 0x5F06017294F3EC67ULL, 0xCE5F0575B14D3F7EULL, 0x008A193EDE1D6A46ULL, 
            0xFEE35194EE891159ULL, 0xD91F63E9DEF18098ULL, 0x6681B5920A7E0CD5ULL, 0x02B5B5BC88161BE2ULL, 
            0xEB3AF7FBAF6B82D0ULL, 0xB58C4DDADF3C4CA5ULL, 0x0722797C9C9151D8ULL, 0x5FD79230B74DCAF7ULL, 
            0xC8992B8FB170B701ULL, 0xEB55F1285E11A197ULL, 0xCB73664F3C3915A5ULL, 0x6970EDA94E983728ULL, 
            0x4D7DED93B1BF85A9ULL, 0x705E02F704869C1FULL, 0x98B30245F4497625ULL, 0xF60D551729A3BFABULL, 
            0xD928429A122B89BAULL, 0xE9B97F9814A4C1B0ULL, 0x2BA54C0B90942B32ULL, 0xCCF82E1E0FE7D2A7ULL
        },
        {
            0x2F04D2A57AFF9615ULL, 0x735257C45583432EULL, 0x7144E2793A84D9C9ULL, 0xE712073B6EA8F7F7ULL, 
            0x93E9D0DD4B4F109CULL, 0xD60CC99BADBA449EULL, 0xC6DA3669A8EC54B7ULL, 0xAD52BE27E3FAEA64ULL, 
            0x600888A18C570B3FULL, 0x971F41186F2A8FF5ULL, 0x4DF9BB6F196633EBULL, 0x2DCB1DAFE25AECD0ULL, 
            0x85265956C6F9A3F1ULL, 0xCAEB30463B7B4973ULL, 0x97316F71BDFF3F06ULL, 0x23E1B38DD8EE8BE0ULL, 
            0xCE8AE205B1ED1F5EULL, 0x92724BBE85AA15B8ULL, 0x337E367340D7403DULL, 0x1ADBC9647F8B0CCFULL, 
            0x5FFDAAE9F390967BULL, 0xED368DBF22F75B26ULL, 0x31F08A8EF3D38B3BULL, 0x6D4AF4F56B890BADULL, 
            0x1FA7FD4A78B30DACULL, 0x476C93EAFE654B04ULL, 0xFA6A387F15D1FA17ULL, 0xC78267A3FC039E53ULL, 
            0x52D2FA7455FF5383ULL, 0xBE327A1DB79BB537ULL, 0xFEC07904D510486FULL, 0x5B02852304A8B4E4ULL
        },
        {
            0x619568A216599E37ULL, 0xA99C1454570622CDULL, 0x94FD2144306E4D78ULL, 0xBDDA38EEDF6C99B1ULL, 
            0x57367A227C27595FULL, 0x51BAD3AA72610D9CULL, 0xB7F559CFF59EF70CULL, 0x6B21B8330A34CE47ULL, 
            0x1FD32BA2193CE327ULL, 0x751BD67666C679F9ULL, 0x2FD2A8F20700773FULL, 0xBC3C76C66A0F3C66ULL, 
            0x29E7F8BFE3470DE7ULL, 0x3C5516DA837918E6ULL, 0xD5F97AA19C72529CULL, 0x943704AED1F09A84ULL, 
            0x6C0AB8FD8BA9FE18ULL, 0x9F5E0ED6AB2AEEADULL, 0xDB6A0B7BFD8073C3ULL, 0x9511B90E2421393BULL, 
            0xC3EF98BE37DAAA30ULL, 0x43351E166C36235CULL, 0x097A8CBB708AFDB8ULL, 0xFA821A37B29DD1D0ULL, 
            0xE2E86B510A25D272ULL, 0x1B33B2696858A2DBULL, 0xB1291E1EB4E279B5ULL, 0xF8AE95DF1C3365F2ULL, 
            0x20BE69DB1A8744B5ULL, 0x2C97CD68E13DECEDULL, 0xE7650F2F33CE4A05ULL, 0x28DC43005A3630EDULL
        },
        {
            0xE5470112467649F8ULL, 0x64C8A05A0D819122ULL, 0x527C8D6063BBE28EULL, 0xAB78647281427CD2ULL, 
            0x50B8EC6028D3EBF5ULL, 0xA1CD985C01D49648ULL, 0x9A89C124B4292354ULL, 0x834BDAEDE3031B99ULL, 
            0xCF6EDEFB38F8BCF1ULL, 0x35E737BD725FDB1DULL, 0xE1B043E7628B433CULL, 0x4DBEC76824753CA7ULL, 
            0x3145C8CD042C72B0ULL, 0x43E6DDBFE35F940EULL, 0x826A039A4F81133FULL, 0x01C1EDE65432A64EULL, 
            0xD8941E3A364135B2ULL, 0x6AE446FF1D36B98EULL, 0x1BBC992B0B9380EBULL, 0xB030E03A7865011BULL, 
            0x938C2D18EA619EF1ULL, 0xD9562C6CF490FD82ULL, 0x508C7CD10593480AULL, 0xA915857041E7CA16ULL, 
            0x15470A50CB1C633AULL, 0x365CC3A09A0EE79DULL, 0xE976E5F0BB7B7234ULL, 0x9632547386361A5BULL, 
            0x4DEAF844AAE930BBULL, 0x847C12288081424EULL, 0x7420504D52DBF481ULL, 0xBBEF1991E97F294EULL
        },
        {
            0xB2A20675B3E36D4EULL, 0x608FCD1197C56E41ULL, 0xEDBD44833735A8DDULL, 0xEE2689D6920BACC8ULL, 
            0x9FFA8242E28FA3A9ULL, 0xEB6902467075A2CAULL, 0xFFA03BEB0D17478AULL, 0xBAFF03FB21715CC2ULL, 
            0x1B997EAEBA05AE65ULL, 0x163B2D352217029CULL, 0x432C90CA563C53BAULL, 0x5EC5B20E0399F88FULL, 
            0xD2F66E00EDD277B3ULL, 0x7E57B1E46A4E4754ULL, 0x41FF7C49C63C0FEDULL, 0x761B25FF9DB16999ULL, 
            0x07B2A9DB9E71531EULL, 0x432FC7C6F0F00FA6ULL, 0x2B31CCE61343E65EULL, 0x0BC14406716023A5ULL, 
            0xB008640732807863ULL, 0xDE9E88CD9AB3CF2FULL, 0xBD934786AEA0B482ULL, 0xE5E4C42246C70E45ULL, 
            0x5CC0788D850BD4ABULL, 0x5F194E72E4A63D5FULL, 0xE2AF494D217C8A87ULL, 0xE7BA79E7DCBCFC1AULL, 
            0x5366FE685A1FE82DULL, 0x9DE989A1AAACC4C5ULL, 0xA09EFF34D85C0E40ULL, 0x20189E67A75F8E3CULL
        }
    },
    {
        {
            0xB2602CECD7B696A7ULL, 0x54D7BB5C50AFB77BULL, 0x78FF823ABD862D9EULL, 0x5AA9EEB8AA0534B5ULL, 
            0xA77B75041D6F6BA7ULL, 0xE835924A1434023DULL, 0xC4EFD502975F6BA8ULL, 0x6550507A4A306F3BULL, 
            0x51C85912F015A619ULL, 0x2C9E0B99BB48DCFDULL, 0x8D8699F709F97789ULL, 0x05F81C2360AC1C75ULL, 
            0x7D0449EDD8FFA52BULL, 0xE14AC10125BBE18EULL, 0x052D45925792FFACULL, 0xC1D98E1A2782160AULL, 
            0x30692185F2D772EFULL, 0x5507862B0F62F5F0ULL, 0xD5C400F92F58F407ULL, 0x0F5F19647141F85BULL, 
            0x8B1FD72170722E10ULL, 0xA798F904BB4BBE86ULL, 0x7658D4ECCE0D09A7ULL, 0xD9EAD6A11435C497ULL, 
            0x8C648A0159396F03ULL, 0x5E9792D0E4A46BA6ULL, 0xC06AB3552628A218ULL, 0x675CBF3CD0499D73ULL, 
            0x6D34D18DC4F8CA90ULL, 0x199888E4CCB47EC0ULL, 0x3F33E6507E0A981DULL, 0x64936CC9765ABCEBULL
        },
        {
            0x5A1433C8AA59DCDAULL, 0xA2A32F05EC19A446ULL, 0xB4164DCF5BF73F1CULL, 0xA9CDC02AC10D7E5FULL, 
            0x13E7157EBB16A637ULL, 0x23FC203F6C293762ULL, 0xEC218F33A206859FULL, 0xDA0D61CA97C0A2EAULL, 
            0x0C04D78940CB69A9ULL, 0x3C569B244DC29479ULL, 0xFBA0282A00F9F9C0ULL, 0xEA2602670535C5C5ULL, 
            0x7EDE019EFC90A916ULL, 0x0321553DACD90FAFULL, 0x476ABE95D9B767B1ULL, 0x61F66ED8268373DDULL, 
            0x6F1631E3E71C91A9ULL, 0xF2E11AFCD3E31849ULL, 0x428ED1CA23D02DFBULL, 0x458BE9F17DD7DFCEULL, 
            0xE7AC7F8754F9FEABULL, 0x3CD8AFF9D3A4B929ULL, 0x209F834FFA2B082FULL, 0x5854993D8F0431A0ULL, 
            0x8B6AD9A4DB8EFA82ULL, 0x8A75722E87CED9FEULL, 0xC0FA01EC9F0C4277ULL, 0xAEF72F47145BFA2DULL, 
            0x21C71F8E4CA65228ULL, 0x15582D5123C3F750ULL, 0x8386F42B6D4FF312ULL, 0x6AEAB8A9C2C30790ULL
        },
        {
            0x7DBD9DFAF1E831ACULL, 0xA32D4D278BEB3391ULL, 0xF482E3D160D9C300ULL, 0x7CD2A66B1964FCD1ULL, 
            0xC0463C69B846AF2DULL, 0xD97DE1A348CDC5E8ULL, 0x15198C650306FF92ULL, 0xAE8CB6CB678A47C3ULL, 
            0x3A48D2547D31A4FCULL, 0x8A2D1B1ABC12634EULL, 0xE762E8736E511C43ULL, 0xF39690D8FF17F3F9ULL, 
            0x31DACAAF743137D1ULL, 0x6E34BED5EEF28347ULL, 0x4D7ECCC58E805BD5ULL, 0x4C79C669CEDA1B17ULL, 
            0x199A4709CD8C0E76ULL, 0x9CA3B98CBB4145F4ULL, 0x4E84522A9AC95941ULL, 0xA9CDF8541A3A7F3AULL, 
            0xA902B7A5D9C34930ULL, 0x5F31C0B0583A636EULL, 0xB07455E0C644DA8CULL, 0x0A835274FDE30CD6ULL, 
            0x3CDFAC23F0A7EEB7ULL, 0x983BF1B544B1C485ULL, 0xEF6348250BBCC69AULL, 0x31B437E3A57FAA88ULL, 
            0x1554D340B8F87944ULL, 0x03E90E1BADA58D16ULL, 0xA1FAD7D9BCE68385ULL, 0xBC0A01C9D3FAA1EDULL
        },
        {
            0x83E6ACDF612B801FULL, 0x107F91C5D3EF83B5ULL, 0x50AF1BF8EFF25F8EULL, 0xEBB2F071AC2F8819ULL, 
            0xD15D21E061C0EE35ULL, 0xA401CA9C765F1162ULL, 0x09BED65CDC472BE0ULL, 0x03669F79A86424C1ULL, 
            0xBF17A67B0ABA93AFULL, 0x0ED9344D3E8E4A05ULL, 0xB0047B003BAAECC5ULL, 0x54715B292278A42CULL, 
            0x611D91BF9A570635ULL, 0x3554DB65D88C9316ULL, 0x2D0005BCD1BCFCE3ULL, 0x27DCA6EDA32391BDULL, 
            0x82F4C11A0752AB6EULL, 0xC9215EA2717B6BE3ULL, 0x6101EF65E188EC9EULL, 0x4E70FF46C9DB8ACEULL, 
            0x0BAB2FF2D4A3B452ULL, 0x60E71495FC9A53E8ULL, 0x6466EC8707F4EF73ULL, 0xD134C2ED5AB3D49EULL, 
            0x959F685ACF45A939ULL, 0x38A8A149CCCDE461ULL, 0xEDE87034760A8C7DULL, 0x8B8B578376A60525ULL, 
            0x98E19FEE94E83636ULL, 0x82815AD1985A47CFULL, 0x26848F718962B4CAULL, 0xB1E8EC59F4DDB26DULL
        },
        {
            0x4F90AB10DC41D255ULL, 0x48ACFF51D52992EAULL, 0xE5DB7626BC7CB485ULL, 0xC47FBB94FE77B94FULL, 
            0x8E151827DCC6214DULL, 0xE1BE2025BF662E81ULL, 0xDD1E316081085744ULL, 0x77B294709EE16E4DULL, 
            0x02F2AD6651150D07ULL, 0xF9DC58CFDF169A8AULL, 0x9365DE3D7D18F35FULL, 0x63B5F5695CEF53DCULL, 
            0xCA3216CA32D5B47EULL, 0xE8124D8BDACC3AA3ULL, 0x17648CB71FC70C21ULL, 0xCB426D46E458E874ULL, 
            0xB826904C3A3A552CULL, 0xD4EB2BB6AC600178ULL, 0x49255CC984C2983DULL, 0x0356143C85C4295EULL, 
            0x1376BB0D22870F6DULL, 0x9DB1ABD6531CB5DCULL, 0xE9A0BADF0535526BULL, 0xF6CFF0CFD4B777AEULL, 
            0x978884E58A4C06ACULL, 0x943774E0BFBF0ABDULL, 0x3D3C7F13A4052E76ULL, 0xA7E1EC1A18805785ULL, 
            0x4928F69201BE1E1CULL, 0x1EE2D41BF4087F88ULL, 0x2A77CC6D0BBEC845ULL, 0xD0B49E77DE617AD1ULL
        },
        {
            0x54BBA32B2AE9F2D7ULL, 0xEFBE2B3C8D9A470FULL, 0x315EC8C55A1DFDADULL, 0x70B68F7FE02497BFULL, 
            0xA7DC783E1E6B85ACULL, 0x3FEDCED81D94A6DBULL, 0xF13F500780796CAAULL, 0x677E48270E9BD874ULL, 
            0x78A54846A5DAB8C8ULL, 0x3D397F93F08B3F3CULL, 0x22C4D0CA9FD4B733ULL, 0xB647B9EA6529BC9CULL, 
            0x40DA27CCCD94191CULL, 0xA40B6294F4F20F09ULL, 0x49B430FE85553AE5ULL, 0xE8650D1E6A8100F9ULL, 
            0xF2AC4471E8416BDFULL, 0x4CD05DF332906CA9ULL, 0x19639A01EAEA61B3ULL, 0x601C3B6B0D8B5F86ULL, 
            0xD94313EF9C36E2CBULL, 0x720B919CAEEF1FCAULL, 0x863AE70FB833F273ULL, 0x6BAEC96CE0AECBB3ULL, 
            0xAA40CE0D73DA4C13ULL, 0xD4AF54D3F3DF8361ULL, 0xCA3BD89DC3BA5101ULL, 0x0FA5390DF3E1CAABULL, 
            0x0E7B186E04DF34FDULL, 0x693B7A44511E6847ULL, 0x1EF3B7F3633F37EFULL, 0x9E568FB64FA852BEULL
        }
    },
    {
        {
            0xFFBE56C7EE19C11EULL, 0xFF23E3A5EB598135ULL, 0x9539835768CF8A6DULL, 0x20467DFDDA50EE25ULL, 
            0xB31D539E06FA9408ULL, 0x977E9508FD36B5D2ULL, 0x230F743F40DBAC70ULL, 0x8C6A587F36175599ULL, 
            0xCFBA4FD461965436ULL, 0x8BBFCFC32F7F5807ULL, 0xD9A459D7E9917C23ULL, 0x94B3F3C29DE87DFCULL, 
            0x4E743F700E8FF1EBULL, 0x04C2150CC3DA85C1ULL, 0x86CD316FB3876877ULL, 0x369084198A77F5DDULL, 
            0x39755C7A41476C18ULL, 0x1589C774B6E84209ULL, 0x87C86F528FE83947ULL, 0x62DF8910BD761DCAULL, 
            0x3E48006DE52FA6CFULL, 0x18592A94CE07F99FULL, 0x75E8B33B9355BA5DULL, 0xF2FD298FB16C4F24ULL, 
            0x191F6ACE7E2603F2ULL, 0x437B975E85CC8074ULL, 0x20F97A647F34B4E4ULL, 0xCE7BA179E0DBF012ULL, 
            0xE777978CBC9C2F4AULL, 0xEF23B571B0C8C87AULL, 0x3E2C5DA2901DE541ULL, 0xDAE6675C58B7C36AULL
        },
        {
            0x7C402CE3110789D7ULL, 0xB10B3E538A2D49B9ULL, 0x2403D609AB0622FCULL, 0x992B72171191B07BULL, 
            0x706E021F5676C3BDULL, 0xE6A968D5F32589A9ULL, 0x45E68EDFC5959777ULL, 0x2DE3817782E47EC4ULL, 
            0x0C1291F2FB870DD4ULL, 0x0854A8E191914619ULL, 0x67FB5C1D7CEC9D3DULL, 0xF81DD18248D7894CULL, 
            0x7AE344CFB01BF2E6ULL, 0xE3DE2D09CD541BA1ULL, 0x70DDCD040D90985EULL, 0x958E4B53AA3CB7F5ULL, 
            0xD0F908700CE2C50EULL, 0xDC5D40AADB93882BULL, 0xD81A82F3E784B712ULL, 0x9BDDC56FB0DEED8DULL, 
            0x2FBAEACC2B3107B9ULL, 0x5B391B4AAC37EB9BULL, 0x9B63B7D27FFD80CBULL, 0x548FF3AA9BAAA740ULL, 
            0xC05309A037EA8758ULL, 0x79C19271DE3DB540ULL, 0xFFEAA3CAF90926F3ULL, 0x547195E316371EE1ULL, 
            0xF33ABD2BE932B22BULL, 0x02F3140136AFDEE6ULL, 0x1FC198CF7E49C23AULL, 0x42108C10B804440DULL
        },
        {
            0x3ADC3C293F59683BULL, 0xD0E32751D0788E08ULL, 0xE1CBA6F7B551558AULL, 0x72BB59FCC4C6A544ULL, 
            0x9C5D0AA7AFA75BD0ULL, 0x98FE95754C137548ULL, 0x2ABA168F9C46958AULL, 0x9C43E2B13EBCD14EULL, 
            0xEF6A3FD4B7F5A2EAULL, 0xC5888054E82AED8CULL, 0xEBA0BC679ACBD5A0ULL, 0xD55F7B11557B0AB4ULL, 
            0xCC1062505A2DB8F0ULL, 0xC587CF024474AB50ULL, 0x8E7C63B85A87936DULL, 0x4C40F0267C323C92ULL, 
            0xC9D5EAED07CE7F03ULL, 0xE4E75D37C70ACF3DULL, 0x1713E090502712ADULL, 0xDC3A838D30BCB915ULL, 
            0xFFFC2BECDFD51507ULL, 0xD6096D76B904DAF1ULL, 0xB28011CA4258546CULL, 0xE2B2D6069C8431D9ULL, 
            0xD038941D9AC03DF3ULL, 0x6D15CFD008D77FC3ULL, 0x9D87B4FD345F8CF2ULL, 0x43FBD145136362A8ULL, 
            0xA5F093BBAEF41F42ULL, 0x194B802AC5D0EE99ULL, 0x470746DE2886099DULL, 0xB3A54D4CABB05EE1ULL
        },
        {
            0x5FFDA40C0E8C6C18ULL, 0x64C6F8ACA55FF138ULL, 0x2895930D94F76266ULL, 0xCE35AF48D4630CF0ULL, 
            0x48D1554628C8C4EAULL, 0x42AED68847A2B080ULL, 0xEAA51927F41AC889ULL, 0x85A179617C0F2419ULL, 
            0x5784191DEFDFEA27ULL, 0x4118B3F43D2AD758ULL, 0xA51CD8137CB05774ULL, 0xFE0A2F2E2F1A9F37ULL, 
            0x0308B20398670410ULL, 0x95F96115213E4BBFULL, 0xA484DCA380156651ULL, 0x53C366F71FF8C5C1ULL, 
            0xB75A30641E1030BFULL, 0x64FBBB0A1EE54FA4ULL, 0xBA7E0E14709EAFADULL, 0x35B10C85E0DB0333ULL, 
            0xC779964C58A8E2B9ULL, 0xD4DE0970245690A3ULL, 0xE822C98071D8B6B6ULL, 0xB546E841A4A7640EULL, 
            0x70E1930B985CB45CULL, 0xC5E2D3171FCCF0CCULL, 0xBB57E6FB6DC8A874ULL, 0xAB3B7F32185635A5ULL, 
            0xDB1C35DB76C8F1B9ULL, 0x3BA86771793C5BD8ULL, 0x4F8F172BBDA110EDULL, 0x563725AC9B30D0D9ULL
        },
        {
            0x787FB6F1DAD24EBBULL, 0x874CBF725DEED034ULL, 0xD5B6A14BB77A35EEULL, 0xFAA879F2A28B807BULL, 
            0x9CA82084556FF873ULL, 0x0A80161BA0DDB01DULL, 0xEDE3595C51CF5643ULL, 0xD51E6B252D1E3AA5ULL, 
            0x4C33144F7064C9C4ULL, 0x7FE858148F8DA8BDULL, 0xEC2E15ED8C4233A2ULL, 0x484E110BCCF3D99EULL, 
            0x80985FFBBCED7B45ULL, 0x13A69BA0BF2C50E9ULL, 0x1A60C6298C7B920BULL, 0x7F5B65B65E3D7073ULL, 
            0x4C718B350B4A66ECULL, 0x29B6DBAAB5280BBBULL, 0xB207033D53BBBDAAULL, 0xA96B4E4BD9ABFD04ULL, 
            0xE79A02B066C453E8ULL, 0x5D0C7CBB6E33B7E7ULL, 0xA7214EA0C0A33C02ULL, 0x50ED2B2F0C4C7E8FULL, 
            0xDDFCFC60C166E412ULL, 0xD336A5CFBFDE6EDFULL, 0xD81C949CC63B0843ULL, 0x5F80106A7B004273ULL, 
            0xD86FB5F4AE8DD40CULL, 0x2D760653563A0DF3ULL, 0x52986D8F3E6F24D0ULL, 0x431667123D9FC2B0ULL
        },
        {
            0x8E967F1C8C79D54AULL, 0xDE3A01FDAFBEB9A2ULL, 0x0344AE5F6532670FULL, 0x2EF0691DD363AC6BULL, 
            0x6966488B39127172ULL, 0x16E1E36CD6704F5DULL, 0x2DDAF6C45689327FULL, 0x39E526AE7B8B0F9CULL, 
            0x99A325EF337FD2A5ULL, 0x18DF5284C9E81C15ULL, 0x6D3D2B35E76D04C5ULL, 0xF0EDAF116EC71881ULL, 
            0x44DDE52914ADA038ULL, 0x8DCD243BD229B9BDULL, 0x200E2C7990D1447AULL, 0x1E9B3F8ABCA7CD0FULL, 
            0x38E63E651CA3A904ULL, 0x1C03B0F2EF04A63AULL, 0xC7F8B8ACFD3DDD34ULL, 0x8EC049462BCBDC47ULL, 
            0x274B1837AB99A021ULL, 0xFD263C612B1FFFEDULL, 0xDBBB69CB7B3D3ECDULL, 0xA04F1838659B74F7ULL, 
            0xF55B48DB60B4C81CULL, 0xA195F090EB4A2960ULL, 0xB67396702F0A0A46ULL, 0x849CC1D3B662D48AULL, 
            0x8A38B6E5B3903E82ULL, 0xFC466E9570BBA5F3ULL, 0xCB2D06A6AE74059FULL, 0xA130EBD5CB2C9D47ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseFConstants = {
    0x501088C9F4AB1309ULL,
    0x62115791CFBE2952ULL,
    0xD68E2358A3846690ULL,
    0x501088C9F4AB1309ULL,
    0x62115791CFBE2952ULL,
    0xD68E2358A3846690ULL,
    0x9F5B69260CB1744DULL,
    0x393314C59491CD66ULL,
    0x38,
    0x7D,
    0x19,
    0x28,
    0x23,
    0xF4,
    0xA5,
    0xB0
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseGSalts = {
    {
        {
            0x67DE206DD2AE2E3AULL, 0x2F78CE3764CBE4F6ULL, 0x67854AA62073921CULL, 0xDDD244AC17D33C1BULL, 
            0x0A6AD9E0CBBF64E5ULL, 0xA10000DC8452F4D4ULL, 0xD6AA6707A91EF35DULL, 0x82CC886A3D83CE1AULL, 
            0xEAFCD6328180E56DULL, 0x6EA7650B72A8612DULL, 0x3BC48696B42CF598ULL, 0xDA494F25B9A134CFULL, 
            0xB9EDB98B12E979F4ULL, 0xDEC19973FE371712ULL, 0x71E02E12D442E91FULL, 0xDC142BC94161D4ECULL, 
            0xE095B9DF74EAEC31ULL, 0xD1629EA054337F21ULL, 0x62C4147D5E844BA8ULL, 0xF441D2099DD80009ULL, 
            0xECCC779772A8E7F3ULL, 0x5F9D13D8A9CEFE68ULL, 0x457F84710C6E73DEULL, 0x67181C694B0B0AF8ULL, 
            0xA68C7D88B8881AADULL, 0x5B2FE4594B124E0DULL, 0xE72D0AE6E1ED4119ULL, 0x6E52D19E8E5E3A5AULL, 
            0x04F87269A9D7C360ULL, 0xDB8363881F3816E5ULL, 0x2FE92725AC87A0CEULL, 0x0FC5670B5986FEACULL
        },
        {
            0x6B10019C8BC555B2ULL, 0xBAC9D5DE7472C6C6ULL, 0xA11E4F540FB84A9EULL, 0x0DF49B80F56BA329ULL, 
            0x4B963B8E3BAF8C83ULL, 0x99FE184DB93627F2ULL, 0xAD523C616F54CB36ULL, 0xC002496C889504C2ULL, 
            0x54B910E776F25986ULL, 0x30D9B468D651AD9FULL, 0xA1C37B301BE7555BULL, 0x209E1DD14A48D210ULL, 
            0x53A7ECF1833000FFULL, 0x238400A1BB71BCB0ULL, 0x591976C83FD64851ULL, 0x7AD811416107AA99ULL, 
            0x9A411E3DA4D132FCULL, 0x3C614911CD9BB202ULL, 0xF1D9EF428826AB0AULL, 0x078CB7579F69B371ULL, 
            0x106BEA337A2010FDULL, 0x814734091ACF7382ULL, 0x8BF8A9DD4C754DCCULL, 0x41C87D85C727D9BEULL, 
            0x43C4387286E72D10ULL, 0x4857AF0633B2907AULL, 0x8BD7CD827A605BF6ULL, 0x3DE429066888719BULL, 
            0xC9CF7A3F47D51D94ULL, 0x99D140B88EE0961BULL, 0x004A428E83D3BB31ULL, 0x1367344BD04E5D18ULL
        },
        {
            0xBE6D791F739CCF59ULL, 0xD8F63F4F14C9A97BULL, 0xC6638F3B3D4F6DA6ULL, 0x656013887223C2DEULL, 
            0x16A5014D81601CCFULL, 0xF5F04337B35263E0ULL, 0x0AAA56788D57BF38ULL, 0x9A33AB2F6B4D6566ULL, 
            0x5CDD5A3AA5EFC7E5ULL, 0x412EFE7A8D52D49CULL, 0x6157772C9FC3D3B6ULL, 0xAABAE1BED523395CULL, 
            0x0CF9721A2717C97AULL, 0xA3F7E7A76522CF11ULL, 0x6759A58444C59F55ULL, 0xEDC733960FD120F3ULL, 
            0xB2CB5022ECC39158ULL, 0x0A02025612A0A640ULL, 0x75CF3C8A8A87F55FULL, 0x10698B9175B6EA23ULL, 
            0xDEF54C5DBC07A488ULL, 0xD0E60898710ABD75ULL, 0xA16C3AA31B8051C0ULL, 0x336B16A5908227E5ULL, 
            0x3F5043884A30C7AEULL, 0xCF1D68659A3B13E5ULL, 0x923E4F9D00BFA889ULL, 0xF95C4561263E85FBULL, 
            0x65353CB9344E2BE5ULL, 0x0D356E8E11E8AB72ULL, 0x7518B2F18160837FULL, 0xED942466BB2220B4ULL
        },
        {
            0x68DB8C5659F8E79DULL, 0xDA07EA45B861A4FBULL, 0x341AF64DA324F85BULL, 0x49A63A6651EEB9BEULL, 
            0xD644C7662748A9ABULL, 0x4CED990D2F646BA9ULL, 0x7D564DBC4D29629EULL, 0x5EDD90EC9A9BA8C8ULL, 
            0xCC0BD99386F20B72ULL, 0x5D581A36669DDE7FULL, 0x1490727FA6D89102ULL, 0x41F15894A3765962ULL, 
            0x43D5DE026DC90C99ULL, 0x9EA7ED5C10077A20ULL, 0x0E0076ED60B42559ULL, 0x6E9F939FB7A0DB56ULL, 
            0x215F4293C1D94E2EULL, 0x9BAD31CB2311E9F4ULL, 0x33E5E6BDFA83C9E3ULL, 0xB939D9EB77BBFBC3ULL, 
            0xE8FD75D4AE7CE747ULL, 0xC01B5C90094EADEDULL, 0x88252519A477F741ULL, 0x6D9CAC03B1F13EEEULL, 
            0x03C3D06255DBD74EULL, 0xBC69B68AC8714082ULL, 0xA3A22856411AE7D8ULL, 0xF7ABD6F892524945ULL, 
            0xE27BA357E0A7447BULL, 0x739A2401FEEE32D0ULL, 0x4DA86A8505A66CBFULL, 0x2C1CC7C3F190A3F3ULL
        },
        {
            0x767C95FA5677E32BULL, 0x2DA2ECA7C8B48E18ULL, 0x98F21F7EA1DD16DAULL, 0xE80B43A7DFF70C06ULL, 
            0xC7EA7B6D6DF00FFFULL, 0xE3DE124D71DE6D27ULL, 0x738A511DAEAD8561ULL, 0xEFEAEAC296C0C412ULL, 
            0x2CC33E06F19307B9ULL, 0x2A10E978B08337DCULL, 0x43774CEAB2EEABC3ULL, 0xC903EBDF0DB17596ULL, 
            0xEFB111AE4DCEF36AULL, 0x9C69CF6F0C6E56A2ULL, 0xC04AF581671C86FDULL, 0xB8714D9454FB1571ULL, 
            0x9B59FA3E400D5899ULL, 0x9FE82D15A45C9A3AULL, 0x672B9C1869E7937BULL, 0x5CD15D1A515F3D7FULL, 
            0x41292E62B0B934DDULL, 0x177958E1B2C1E37AULL, 0x54C029CAEF45EBE5ULL, 0x89D85AFD3A6F6A8EULL, 
            0x3C3918EB51C725D7ULL, 0x6776634082C45D50ULL, 0x35AE864093FFBA4AULL, 0x47912E7FC14F374FULL, 
            0x56504E468FD81AF3ULL, 0x51B12CC56002359EULL, 0x16CD3E39EA60238CULL, 0x309BBA17161DAD96ULL
        },
        {
            0x3EAD042564CD4E8DULL, 0xDEAD018772D7E7C7ULL, 0x5DB3AE03615DC854ULL, 0x74840957130C355AULL, 
            0x058F0050AD783076ULL, 0xD865789A3FA45289ULL, 0x41A7F2EBA128AA3FULL, 0xA35A344650054622ULL, 
            0xA0E2A75E315C2BDBULL, 0x57E052408D06DC9DULL, 0xED2C37EEB4BB0308ULL, 0x0F558741BCE74D13ULL, 
            0x45B5615B4F749117ULL, 0xF0D42CEB4C0B3979ULL, 0x4A38F4EE883FE08CULL, 0xC1662C8B916E5501ULL, 
            0xEBAF646BC4352F9AULL, 0x5FDF9E5AD08790C8ULL, 0x60E0AECD47EEDF45ULL, 0x28C4FB7B4B4F8EB1ULL, 
            0x06FC0C3C4605D243ULL, 0xE70B070D397DDDABULL, 0x97E7855DC67FC94BULL, 0x83F0003B54BCD027ULL, 
            0x4017E788CA065875ULL, 0x5357CCB919B2B498ULL, 0x378FC3D2E837F341ULL, 0x43DA54D8B2143A10ULL, 
            0x475B4E49F8803A1AULL, 0xC8DE5887296EFF19ULL, 0xB87A637C32643569ULL, 0x86AEE070F45D9306ULL
        }
    },
    {
        {
            0x9C7CFF80885155ADULL, 0xDA70D98BEBA3E731ULL, 0xA023947BB9924A0CULL, 0x601526FC8D8C4420ULL, 
            0x0196640B8943A72BULL, 0x6EB3FE7287D23352ULL, 0x72C8AE2210D59808ULL, 0x8DFDAE4EB28EA3CAULL, 
            0x483D177B4E0CE0F3ULL, 0xC43C849E16C972A4ULL, 0x27626FDADABBE568ULL, 0x62BC2791DC7A2946ULL, 
            0x8FBCE8E6F49E23FCULL, 0x23BC90F17675F32AULL, 0x6AE3FB4E8DB369E9ULL, 0xB85A11570A9A4134ULL, 
            0xEEF60D33331CBF97ULL, 0x651D2878A8A138BCULL, 0x72FA4DFEBF0261D6ULL, 0x172AE1A863668465ULL, 
            0x11F2E20153F003C0ULL, 0x4CDED170734C5D78ULL, 0x8B6C28F4F876D336ULL, 0x5DA57CF27B5EACF6ULL, 
            0xD1BE53F3CFB4D0FFULL, 0x0C2E336ED46F51C8ULL, 0x3652805773B509D7ULL, 0x0DE648A482F2C4A4ULL, 
            0x354EF25D8E109027ULL, 0x0D45EB6FC2C7C50CULL, 0x59F5619B1083199BULL, 0x7B4C26A08AD7306BULL
        },
        {
            0x84CEC9FF1515828FULL, 0xEDA72D3402A6B581ULL, 0x65B9F18A9C03CEF7ULL, 0x3EA7AF29B9EEEF8CULL, 
            0x1329F7362D58718BULL, 0x98B1B4788F62C088ULL, 0xC04F36E4849076FAULL, 0x54E9F237D785B02CULL, 
            0xC42B8D700A96A3E2ULL, 0x3D0B2C91386C9BA9ULL, 0xC91EFC1A5CA33105ULL, 0xF41C1AB6B56A85A0ULL, 
            0x4200941429078ACBULL, 0xD998CDA5AE5A6E47ULL, 0xAE07C25FA08EBB82ULL, 0x6AF37E5B46658B98ULL, 
            0x761C2D74FE368EE5ULL, 0x18519604A290FB98ULL, 0xE2D5CD461BD0794AULL, 0xF9C4D26689445FEEULL, 
            0x46FC2BC20FBFD903ULL, 0x2E19D3F83734EBA5ULL, 0x685D5EBF258CA359ULL, 0xC0D9F480B8BEAD5AULL, 
            0x4C686F24E7E75885ULL, 0x0E9491BE35EDEAEDULL, 0x456178F68E7B5202ULL, 0x500A2EC645A28FC3ULL, 
            0x0DCB9EF55386A5FEULL, 0xAEA2D844C6406110ULL, 0x2B0B9C0E92124636ULL, 0xB8757AC946108FE0ULL
        },
        {
            0x35CC6D9DFD3B06A9ULL, 0xAEBA4154F0E1B44FULL, 0xAB64FB1A02E18E8BULL, 0x6E3821621F1A427AULL, 
            0x2DC3388449E6E152ULL, 0xAD1AFBDDA6537BD4ULL, 0x9F0419026448DCE7ULL, 0x88A0704E5F9C2A26ULL, 
            0x2A899FEE7D9BF0D5ULL, 0x2085DCE33D4C4C6CULL, 0x801B2485ABD924AAULL, 0x33E818589B2F6760ULL, 
            0xDAAAB39A02762022ULL, 0xFD280401913CAD7AULL, 0xA0ADA53CCDC2463BULL, 0x00EB8E06B0A3F725ULL, 
            0xE7CAA77191D3769BULL, 0x0F1859859E70807FULL, 0x5F155329A283A9BEULL, 0xF60354B1C8C07740ULL, 
            0xF6FACEF65EEE2674ULL, 0xF82972B73E977E2DULL, 0x830A3D0210CE47F3ULL, 0xA61AF2F28C84AA65ULL, 
            0x417E398475DC791EULL, 0xE2FAE7D3BA6EE6C4ULL, 0x5896227CA8628A34ULL, 0x50242B7E485DCDE6ULL, 
            0x27D477758081D096ULL, 0xE28CB0ADD457A6D9ULL, 0xDAD83497810DBA95ULL, 0x567B387E26F8DADCULL
        },
        {
            0x79B2CE2B9DB7A35EULL, 0xCFD5F9662B64674EULL, 0x6F6314DC8D1B3A6FULL, 0x81BBF6AD33D3DF57ULL, 
            0xEBA1A6E6C8C6A57BULL, 0x9ECFA7FFA42097A0ULL, 0xE931E6ACC2C7419BULL, 0x1E3ABD976D4175E1ULL, 
            0x8F6344183E6E43D0ULL, 0xB29340E6D51982FCULL, 0x56A1EC8B713C56C7ULL, 0x0B6A6B6B25C9E863ULL, 
            0x556987DA33D093D9ULL, 0xF75788F41318EBFBULL, 0x4C7D25BCE85AEB35ULL, 0xD64FF78B2BA5F85BULL, 
            0xA0C7141AFDF14F37ULL, 0x8C7C09C59BF49CF0ULL, 0x816C6AAE7D17595EULL, 0x82FAD42BAD6BB1D3ULL, 
            0xB859F7D682BA3F40ULL, 0xC628C97F14A4B47BULL, 0x4DA3BCC56D9767D4ULL, 0xDF7F61077E7556A8ULL, 
            0xA6ADB77B383DEA36ULL, 0x446D89A2A37CE4A8ULL, 0x837C15DF94E3F8AAULL, 0xEEB406C455FEE0E6ULL, 
            0xB7FCA922EFC13FB7ULL, 0xDB65A6604A579A6AULL, 0xDBB0D50778BAFA2FULL, 0x04374F046AE4A495ULL
        },
        {
            0x6076DD8B85AE4E54ULL, 0x46A87907F5CAE752ULL, 0xAD9DE487B82160EDULL, 0xAB63E2C3B6494504ULL, 
            0x13292923F1C0110CULL, 0x9B502A977541D92EULL, 0x8BE816EE3166AF9DULL, 0xCD05AA7B7583EB6DULL, 
            0x27FDEED5EDD8A2EEULL, 0x65A9A2BE048028A4ULL, 0x2C1DAE324257E7B9ULL, 0x893658B6DB8638FFULL, 
            0x5004D891A5B2B132ULL, 0xBC62B2F77B0204ABULL, 0xCB6ED2E71578D99BULL, 0x52D319FF06DB6E0BULL, 
            0x46A263C623C1BDCCULL, 0x76DBB92DE114018BULL, 0xDF560246695FE04AULL, 0xDBDE8D3C3F32373AULL, 
            0xC0209CC1918B8087ULL, 0x7C6AA4511BC76FF8ULL, 0xC1711EB97A0A4B13ULL, 0x1D917CCB33713F7BULL, 
            0x0985197AEFBE1FCEULL, 0xD745FEF6304EBB61ULL, 0x8B25AC1062ED7316ULL, 0xC1883EFF56C6F425ULL, 
            0xAFBBD775D7D84AEBULL, 0x8F723F406BB59117ULL, 0xF627F1DA019A99B1ULL, 0x979AE608A081B4D9ULL
        },
        {
            0x74BD689D2DDDC641ULL, 0x2756A2F4A60100BFULL, 0xCFCCB655F579D4F6ULL, 0x89DF2E78BC363890ULL, 
            0xC08BB57BE484FC74ULL, 0x003CC9E0C08D2349ULL, 0x5385F95917BF6B55ULL, 0x44CEAAC5D7A6D988ULL, 
            0xF7C86F9F43D7DE6CULL, 0x90A43F715255BA3CULL, 0x993D00A4E4DE6B3FULL, 0x081C41CC6A4D3AF5ULL, 
            0x33699B8A8FD76AF7ULL, 0x4AB50002188993F8ULL, 0x6BAD57BFDC9377EAULL, 0x94A741A103B95141ULL, 
            0x2C66F1FF2F83B5A3ULL, 0xE2A3B3AA4B248395ULL, 0x45E8F28529CF2693ULL, 0xFF7A72F1DB4AE7A9ULL, 
            0x2878B5A054EF670FULL, 0x006C536939B20DF3ULL, 0x37A95D2389DC61E2ULL, 0xFA9F3CE9EDE3A90EULL, 
            0x59FACC4986807FD1ULL, 0x5897460EFE0A95CEULL, 0x277964AF37473652ULL, 0xBE807DEEFD9890AAULL, 
            0x7D5B2541F4B1D5B4ULL, 0xCA1D26682648FB6EULL, 0x69EF2F14FB1A158CULL, 0x8EF05DE582AF81CEULL
        }
    },
    {
        {
            0xBB0D2153CB6921A3ULL, 0xB89C3B3EA9392F03ULL, 0x08269B9224DC77ACULL, 0xEB8AFD429B52570EULL, 
            0x47B0B66AFA186D40ULL, 0xC6BD511FA7429423ULL, 0x232E71434556FFF9ULL, 0xB30BF459AC1E303AULL, 
            0x8184CBF2F6C070B4ULL, 0x8A732D07D020597BULL, 0x827E202D44011CECULL, 0xCD9638C79CEF3748ULL, 
            0x74B17051807809A4ULL, 0xF7E442222932EF45ULL, 0x24FB2D7BF78565E4ULL, 0x727CA4098F183AE8ULL, 
            0xA47777D7F8F42390ULL, 0x90192B515AC33C26ULL, 0xADF83B0ED4ADB49AULL, 0x64AD8CF690AF8812ULL, 
            0x26BA65BFDEE9A986ULL, 0xDB754F9E62FAA50FULL, 0xD891C5C40F559B9BULL, 0xF7EBA39CA8595CE4ULL, 
            0x26EA0DEB3BAE71C5ULL, 0xDA9AF910E70981EBULL, 0x64A7BD00A2E312F6ULL, 0xA54B1A5F812884BAULL, 
            0xFF2BA7DEE1CDA422ULL, 0xEB0FDCFEC7D57278ULL, 0x93E4680BAF4D6502ULL, 0x809F269AFB689036ULL
        },
        {
            0xF919877A517ADC03ULL, 0x00FACB30999FF1F9ULL, 0x4C2CF49D5B1FF4CDULL, 0x0C51AA2130C9ED02ULL, 
            0xBB831C89E685EAD9ULL, 0x230664AF4256BE60ULL, 0xD7B6231874A4B2F4ULL, 0xD6809371D8D114F4ULL, 
            0x446CEE2A45949BBEULL, 0x7CB57060749B5F2CULL, 0x8061F36D2F521C58ULL, 0x258408E7CDF9E53EULL, 
            0x6CCFE2E6C437A827ULL, 0x25B3EF5EFB572A6EULL, 0x544CBFB814E36A06ULL, 0xA3621A02C2C5FD71ULL, 
            0x75B3DF88A16FD616ULL, 0x59E454314DC3F7E0ULL, 0x51E539B4AB4FAC3AULL, 0x83C5FD7C810B265CULL, 
            0xCF6BB7AF4EC54BA8ULL, 0x51AC820A1729946BULL, 0x02579DE6DBFA5333ULL, 0xF3AF5CD278BA2B05ULL, 
            0xA10D868ACD978ECCULL, 0x08CD9FE5F0CFC7ECULL, 0x13D1D940D78B84EFULL, 0x64ED2EC0B805F923ULL, 
            0xA6105C92BF2427C7ULL, 0x37BB4FDC447E9BD3ULL, 0xC1DEA9967D9520BFULL, 0x1766ED129019EE8FULL
        },
        {
            0x3FCC2D7E56EACEF3ULL, 0xA5FCBBB97B84E386ULL, 0xB56FC2515A3E3769ULL, 0xDCBBEFFCDE5B25B9ULL, 
            0x3449D79DF6DD69ADULL, 0xA118C236FB714227ULL, 0xF4C125C610B2559CULL, 0xC82D1B25E19EB45BULL, 
            0xB495F6DD1F5412B5ULL, 0x8624BD3B96FE82C2ULL, 0x587EEA9E7E87D7B0ULL, 0x0639A9D4CEFDC809ULL, 
            0x8D477B38ACF3776AULL, 0xB09941C90AA8C090ULL, 0x29EF3618FDFBFD7EULL, 0xDD51B015D306606FULL, 
            0x6CDBB71F8CED9D33ULL, 0xE203645A65215260ULL, 0x7AB470302035B26BULL, 0x5FF395B0B5C09A53ULL, 
            0xA52305718D173376ULL, 0x78097985F8C4A147ULL, 0xD1C4FC7CBD16C216ULL, 0x72EB71881AF1DD86ULL, 
            0x6821F313B5976514ULL, 0x8E1FA98F57B7F9DEULL, 0xA0E25E5668AC0E8CULL, 0x340EF9C56FC125C6ULL, 
            0x9B69984F12703E03ULL, 0x0E37980AE18FA2C3ULL, 0x30B487FE8FAB7B3BULL, 0xF212F70BE8DA0D7FULL
        },
        {
            0xCAF8008BDCFFDA93ULL, 0x2A8889E88625C5FFULL, 0x8CA355A2DD95938BULL, 0x4D7A6DEB5B724FDBULL, 
            0x772D3F39B9B6181EULL, 0x160A9670BAE30D97ULL, 0x8DA390AFC6A2E938ULL, 0x915B0DB3B64E6D69ULL, 
            0x8EA34A9D1E00D328ULL, 0xF8756B5DF7B11E19ULL, 0xB9532927361762A0ULL, 0x77AD24D70DF641EEULL, 
            0x901DE9548F337BD1ULL, 0x78D430D70653D022ULL, 0x4562823392402A08ULL, 0x08F8D1E73BA1A7BFULL, 
            0xAB7B6EB30C3B8496ULL, 0x883B0D09DD03384DULL, 0x6F85E8C72DE69DD7ULL, 0xFF840C7CEA6FA235ULL, 
            0x39162839D8E28BE7ULL, 0x21718D9A6472F19AULL, 0xE26E9B9387B4454BULL, 0x108DF6B9BFAEC962ULL, 
            0x300951F664C59258ULL, 0x0E0782CA986AFFD8ULL, 0x45E65AB7351538C5ULL, 0x32C3EBD5743AC85FULL, 
            0x00F386881AD55F13ULL, 0xA0A0CB24F69CF3F5ULL, 0x3003100DA0CA0428ULL, 0x98802070931CBAF5ULL
        },
        {
            0x9385CEC6C1A87353ULL, 0x59956484D8430546ULL, 0x606DA97C38667D06ULL, 0x325C64A579A45F08ULL, 
            0x863BC35A4E506A55ULL, 0x1B3C9FA9E18B19BAULL, 0xB4303C3A1ED18B84ULL, 0x5D5020F300A035A3ULL, 
            0xE75A6B80EDC0E8A0ULL, 0xB1592E592592879FULL, 0xCACCFDE950E0D6B3ULL, 0x38F50DB6E1516641ULL, 
            0x4696D2EE8B8EAFA0ULL, 0xE9D31851B31E4108ULL, 0x37416CBEF570ABBCULL, 0x059D359E4138F8F5ULL, 
            0x4B64B2DCEEF6F7A6ULL, 0x7A3408B7189338A2ULL, 0x153E829DC4FC3E0FULL, 0xFD588E2F458FE47EULL, 
            0xDB2645AE21C3B0DCULL, 0x10EF07C456176529ULL, 0x009831842F3DAB21ULL, 0xAED3F00D97FE855BULL, 
            0xE2ED2EF8969C9E61ULL, 0xCA12DD4727D7A5D1ULL, 0x886A5561FCBD1424ULL, 0x6186D46AFFBD45D2ULL, 
            0x9236684924350F02ULL, 0x735D4F8240D68254ULL, 0x3A6A27BF9F282AB2ULL, 0x41A420F42E3DD2E8ULL
        },
        {
            0xE699926FD6FEA414ULL, 0x15E39713B86A1423ULL, 0xB51E34FF15210D46ULL, 0x10642FB533FE95FAULL, 
            0xF606F9E590445E86ULL, 0xFD09A1324956AA46ULL, 0x150F4B56903C3C57ULL, 0xCD95B31DC1EB1D8FULL, 
            0xE7180D58D56E2937ULL, 0xA2616721E15BC413ULL, 0xF6A2AB1F600560CEULL, 0xC287000FCCA48D9CULL, 
            0x55854360AD679EBBULL, 0x8FE318F559FFC1FCULL, 0x55F2095FDB2AA83CULL, 0xAB905FB26D29CB5FULL, 
            0x567048636E02D81AULL, 0x472C469853EABAFAULL, 0x76702D68930FF1E0ULL, 0x0A5709511B8482AEULL, 
            0xA6A6E4C0931293CAULL, 0x2C24B406253DA904ULL, 0x2C03E04ECFE0A213ULL, 0x6EFF349A950F6E67ULL, 
            0xF2A2AE6F7D28B370ULL, 0x729A3991C493BA8CULL, 0x76300F801F7A58A3ULL, 0x0176F25AECF59290ULL, 
            0x58BEF91EA7484B0CULL, 0xEEE79CB152248019ULL, 0x82AA31BB8BDB3E50ULL, 0x086774D4EB85164EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseGConstants = {
    0xDE1275883B112592ULL,
    0xAD87083FBFCE84D9ULL,
    0x07C6981336D8E253ULL,
    0xDE1275883B112592ULL,
    0xAD87083FBFCE84D9ULL,
    0x07C6981336D8E253ULL,
    0xD161F21150A57737ULL,
    0xE2865C835139CDC9ULL,
    0x2C,
    0xD1,
    0x04,
    0x34,
    0x8B,
    0xF6,
    0xA4,
    0x27
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseHSalts = {
    {
        {
            0xDDC1385DF64022B7ULL, 0xFE3AE5DCF75A3615ULL, 0xA9871777894044C4ULL, 0xE6E83023602564BFULL, 
            0x9BB4901465E536BCULL, 0x42A790408782D289ULL, 0x6F87A9836968C834ULL, 0x8FA3D927884CD17FULL, 
            0xE39095DC53CB38ECULL, 0x49C1CF4C01A484B8ULL, 0xDE08531F2E568A54ULL, 0xD9BDC39A8046333BULL, 
            0x821AD5D9419E1AE3ULL, 0x6C6273F84CB6863DULL, 0xC50799C838D3812DULL, 0x6C74A2CB782B626FULL, 
            0x256D9A2720A0A10FULL, 0x0A4DED288A6D32AEULL, 0x7973732ECBA1E0E2ULL, 0x137D260D2C714F4DULL, 
            0x3B479BFA4AD7F9A1ULL, 0xD1B65134CAB57E95ULL, 0x5ACBE5BCBBF816DEULL, 0x43F8DD88431888B6ULL, 
            0x124A7A0358616096ULL, 0x8782840883F3A79AULL, 0x4B16B64ED10E9DF0ULL, 0xD5E4BED8D014CFB5ULL, 
            0x19352A498DB58A34ULL, 0xB862F433D4EBA0A7ULL, 0x5759F2E98F4B4A0BULL, 0x68A3D6C1D881CFE0ULL
        },
        {
            0x3AE5507B5861C1E5ULL, 0xE82BA30B0B369547ULL, 0x0992579C1CCA240BULL, 0xDF5C72AE844B1BF7ULL, 
            0x4625B9A048CA3CDEULL, 0x7A3A855FC818AB7BULL, 0x1F80F67AB5E862C0ULL, 0x8EABE7D75441F3A9ULL, 
            0xFA25D260DC3B24D6ULL, 0x349D2E1890E147C4ULL, 0xA1C7DA0F414E9A56ULL, 0x88BEDE0DF2E8B0A8ULL, 
            0xE31DB958ED231B65ULL, 0xEE1FB9465C9CB5EAULL, 0xCDF2EB858F47BF89ULL, 0xB775AC41171B6315ULL, 
            0x3B7737D2426D7FD8ULL, 0x2630DCE8683C2BF6ULL, 0x5EDC3A645B7F8D60ULL, 0x74DD8EF698283220ULL, 
            0xC6B988F36605324CULL, 0xE7735457E13E9B05ULL, 0x9DA88CF95440C59DULL, 0x0AE092369CB59ACCULL, 
            0xFD9B8B2D90217B89ULL, 0x77C55CDDA0055AA6ULL, 0x95B0385583F66BE8ULL, 0x8842745E2FEA86D7ULL, 
            0xC1A0A2B5AAAD78ACULL, 0x62C5816F4AAFA766ULL, 0x99C0C61C37790F21ULL, 0x8D88AEF21F9D460AULL
        },
        {
            0x4AE3018452A0DEF1ULL, 0x4580363B92379880ULL, 0xD97C3365B2A0D452ULL, 0x2DE7E5067E42A9ECULL, 
            0x8F0AB62ABC27A30EULL, 0x4436746A995A7745ULL, 0xFE07436A5D95AD34ULL, 0x998B1D72FE7738A2ULL, 
            0xD3840DC27201D896ULL, 0x9D0B2ED914116617ULL, 0x3D0FC79B679531C3ULL, 0x5DFB2B0F153DA9C3ULL, 
            0x0177B4B63E49A8DEULL, 0x11DF780DFC3C7C62ULL, 0x5AD0E35C39CEAD84ULL, 0x991D508AE78DBE7BULL, 
            0x2C21D919C6263BD4ULL, 0xC405A0D66AA6D2AAULL, 0x057AB88E21071B6DULL, 0xBC5BF852A0DE9728ULL, 
            0x9F9860FA7E359484ULL, 0xF4C5E2A60FB80962ULL, 0x2212F75D0156BF48ULL, 0x14ABA69C3832B7B3ULL, 
            0x3B853029940E0E34ULL, 0x8DF11092ADA19491ULL, 0x0DC896A38D8C6361ULL, 0x642A2F0B67BB4A59ULL, 
            0xF2EC6F02223514BAULL, 0xFD803FB760D41854ULL, 0xB210937F2ED95E83ULL, 0x0D63247225E1E180ULL
        },
        {
            0x72C452BEB3D558E9ULL, 0xFBD2FCF3549D70EEULL, 0x94EF0BE75C5113F1ULL, 0x47FF292174472F35ULL, 
            0xD499BA55D86D7DEAULL, 0x808D3933F6D120AFULL, 0x47EDE3E0B8FE7B70ULL, 0x6F74363283DC44EBULL, 
            0xCD26911C89A49449ULL, 0x21F5A0464E2EC5AFULL, 0x9240FB08CD116EFBULL, 0xC3E412F895C4B57FULL, 
            0x9FDA7FB811C89213ULL, 0x7B5AC7CF33E500A2ULL, 0x306A182FC7D11C64ULL, 0xB051B67F45E460AEULL, 
            0xC49CADA535FF7444ULL, 0x770E63211DDEC07EULL, 0x6424409DF562D23EULL, 0xEEFFFBA408C59C16ULL, 
            0x83F3FC522A2A7416ULL, 0x2EFAE13E4DF82D49ULL, 0x7585F75496C998D8ULL, 0xC98EBE962BD97DCBULL, 
            0x387162A4F8DB761FULL, 0xA7846F274E8BD85DULL, 0xEE12049FBC92FBF6ULL, 0x94A1EC788A35BA6AULL, 
            0x7F3F888AE9A8BA16ULL, 0x92BCFD96AAD92D1AULL, 0x2E63021AA7D6AEA0ULL, 0x88D980F034564D26ULL
        },
        {
            0x54679FCE6FEA033CULL, 0x6E8D36B78CF47D9BULL, 0xF4118FF5DE6AEC95ULL, 0x9692CF4C7C2969AAULL, 
            0x8522322433A73BFDULL, 0x51DB11491EBC12EDULL, 0x5674CA3C7130ACDAULL, 0x601ABC4191DB9ED5ULL, 
            0x4D83CD550C51AA5CULL, 0x7CC30745D4343302ULL, 0x9DC5AD59A8C66E92ULL, 0x56A746A9F0F48F43ULL, 
            0xF99651D5841310D8ULL, 0x5F3286111DA9215EULL, 0x1AC40C2B78097957ULL, 0xF45A0F273B0CD527ULL, 
            0xE970DA55C14E79AFULL, 0xD84A7DCDDD4B5E6EULL, 0xB32BF0E856E07E40ULL, 0xA0386C4D6B7B5D86ULL, 
            0x7A47DC6923E4B9A4ULL, 0x9BED8266024B8C11ULL, 0xBE8E998C1EDA8A02ULL, 0xA8C6CFA14648BEDBULL, 
            0x6807822384EE9B23ULL, 0x2E2135D6E15FCB2FULL, 0x4403752FC28D7683ULL, 0x4B72972EAC5F72B7ULL, 
            0x074E593B08B07D7DULL, 0x4A155B2A003A6CDFULL, 0xA2355F95D3A87B7EULL, 0x84E60638AD340D5DULL
        },
        {
            0x0CEB8509BDC5D695ULL, 0x24E143F12737CA04ULL, 0x3234C8D87C23839FULL, 0x7CB99BDBE5F357D1ULL, 
            0x82F0F2A873059D62ULL, 0x51BCBA8EFD91AB99ULL, 0x5CF396A635BAE64CULL, 0xB1811706CD0E2326ULL, 
            0xCF07DC452DAF5ABCULL, 0xCF9BBC21A8A5E20DULL, 0x19E98A520E0C78ECULL, 0x6BFA64C958D92828ULL, 
            0xAED67D443210A40DULL, 0x91E18E40C4CCCFE8ULL, 0xFA34CFA7A0BFA10AULL, 0x03440D26D88B3D2AULL, 
            0x85DEB2C6577056DAULL, 0xDC7919DC79238649ULL, 0x493AEE75F8C04D16ULL, 0xD03DFE9287E83E68ULL, 
            0x835E697D885EECD4ULL, 0xC66A539813AE75B7ULL, 0x85D5673B0A4988C9ULL, 0xBF6D01932C0F07DAULL, 
            0xAFC8931854FA1C48ULL, 0x27DCE2139D23F29AULL, 0xCFFA036B9E26A3D9ULL, 0xF79E03CB4610D97EULL, 
            0x65E683F6C66BDEFFULL, 0x6BFF0A45FB9F7312ULL, 0x48F2A417DFB086DCULL, 0xE8AE01480D6BD9FDULL
        }
    },
    {
        {
            0xFFC1D60CA4F096BBULL, 0xCCF1858E6C44F98AULL, 0xF52474C82DE741FFULL, 0xADD7C60F0416417BULL, 
            0xF240AB92B5514746ULL, 0xF7D1BA54F3175415ULL, 0x1312C8789077AC72ULL, 0x9AC542D16F8414EBULL, 
            0x3B7F1A0FB04FBF4EULL, 0xF42AE586928A010BULL, 0x62EC77F58939609AULL, 0xB3B79468664399F5ULL, 
            0xE67112A6F3BDC60CULL, 0xA549DCC948CD9D42ULL, 0x92CB82CEC1B3EBD7ULL, 0xD03C7F2F6B26F3E6ULL, 
            0xF00421C6C40FFBDDULL, 0x97F755BD0B928746ULL, 0x94AFD91B5C2BCBE9ULL, 0xFDD8637D0B9C21F6ULL, 
            0x17C141D4F5AE75B8ULL, 0xC2CBC7467616F93EULL, 0x34ED59A4FEC6E21CULL, 0x0C77B0B4505FEBA6ULL, 
            0x72EBBC56C0F76F5DULL, 0x481A317F0010D5B7ULL, 0x4B10CD8AB99B6119ULL, 0x1DF3E130121A764BULL, 
            0xE9FC5D31EE316C30ULL, 0xB26CC1B144852B75ULL, 0xCE4E0CE3CE1F6C4CULL, 0xA1877A87D5F0C5B7ULL
        },
        {
            0x7892C88AF4E647A5ULL, 0x762E78D64F7B52B4ULL, 0x9CCFDFC8E60DEF03ULL, 0x58AFC7AF152B7AABULL, 
            0x6CA42EE7DDA6B7FEULL, 0x964DF40CDFEE79F7ULL, 0x307849037F7F9FA6ULL, 0x993F359D2A59615CULL, 
            0xE43CCFA52E472560ULL, 0xA4515C3AED405E4CULL, 0xDFE355C302E214B2ULL, 0xFC75B1573A21E665ULL, 
            0x171FBC7850C882C6ULL, 0x4ED8608C65CD6D12ULL, 0x0A15DA2A216E6D85ULL, 0xF7E348AB85CE3864ULL, 
            0xF1BC480B5ACA5E30ULL, 0x8BEC193310BCB5FFULL, 0xBE4181EFC063CFEAULL, 0x44398A67EA1D3DA6ULL, 
            0x646198C511DD2AD4ULL, 0xBCBD367E8D791102ULL, 0xBAC2FC0596813311ULL, 0xEF5EC6AEF23E95D8ULL, 
            0x91AAEFD895820345ULL, 0x07F72E51678DE593ULL, 0x72908F82D5709949ULL, 0xCBE1D390E7364F2AULL, 
            0x2DC2FB12AE114848ULL, 0x766376D8504428ABULL, 0xA3E1D33E04382423ULL, 0x3FC68E187618DA95ULL
        },
        {
            0x675FE17672514D33ULL, 0x1FE298CB14884A8AULL, 0xC2E00E615E9485F3ULL, 0x0C84A0059B16C03AULL, 
            0x8DE5CB9DC8093C16ULL, 0xA8C6C4BFC8E0F134ULL, 0x8B35AC91D415326CULL, 0x10F3DABA659B79BAULL, 
            0x198A1B4DE2123C01ULL, 0xBBB05C396BC27800ULL, 0x175B27FB27C6C58EULL, 0x37EA6C48B027FFFDULL, 
            0x864C6112C0D06038ULL, 0x4B1B075088A7B76DULL, 0x4CFD7970B2953909ULL, 0xC457A19F150E57E9ULL, 
            0x6D6A0D181D46AFE4ULL, 0x04ED73299E3A3EF4ULL, 0x4B375ABF9B114DAFULL, 0x0EF22F973C5BFF97ULL, 
            0x87329DF0A39434E9ULL, 0xDFBA49B2092E10D2ULL, 0x3715F9B22D8A33D2ULL, 0x472EA11FD8899C04ULL, 
            0x332F58DD191CD366ULL, 0x4A08B63AACF5F1B1ULL, 0x01B755ED335BDA85ULL, 0x11B18BB64092E5EFULL, 
            0xAEA51E8F9AB85F59ULL, 0xF3758EE7435A2344ULL, 0xACD5792416E6FDEAULL, 0x1B0E1ECFBE6BE8C5ULL
        },
        {
            0x323395F83C3A07CCULL, 0xF7B2B2E0789B6F8EULL, 0xA43F5C26699C240AULL, 0x6DE1BB1475FFD352ULL, 
            0x792F596F13B11E12ULL, 0xB7E61B96A3A8D165ULL, 0x7A4858261B1622A1ULL, 0x915412362E9F117FULL, 
            0x73B2D4743AEE1F6FULL, 0xB7672836A02B9624ULL, 0xDFCD84FC71C458B6ULL, 0xF3A0A4B7350E9DE1ULL, 
            0x2C6C3DAB10BE05B8ULL, 0xE799A86E2641B954ULL, 0xE995F44604E7EC7FULL, 0xA11E11EAC479C029ULL, 
            0x6C927367A078EAE9ULL, 0xF538A5E53DA55A29ULL, 0xD46058E298A02D34ULL, 0x57C473743AE074C8ULL, 
            0xE31E103F829AEFB3ULL, 0xC70B41EE40FCB5A1ULL, 0xD92FCC0FD8DED738ULL, 0x303BB9264C5CF224ULL, 
            0x4A572CC4CFC9582FULL, 0xAD93839988621A86ULL, 0xFDB4E9C5B1A1BF7DULL, 0x423CF9F85DC22658ULL, 
            0x4F0AADDBC6222903ULL, 0xE67BAF29FEE1A2EAULL, 0xA943E4CE4ACE103CULL, 0x28E315B818151A4AULL
        },
        {
            0x3150838A25515250ULL, 0xC1D37227F43C04B1ULL, 0xADBF2305928BE880ULL, 0xA49C1087E6E75477ULL, 
            0xA05EE2A2DFE2683FULL, 0x47AB68F6C94D8CC6ULL, 0xF286F96F0FE9BDC8ULL, 0x18CACF9B59CF60A1ULL, 
            0x9635AA5EE7666404ULL, 0x0ED4269CCDBC1B15ULL, 0x4847ECE5E8351CC5ULL, 0xAC9D1AFEC0060F04ULL, 
            0xF02657BB4CE3318DULL, 0x6EF344EC9FADE0EDULL, 0x2C2A459E4C0C3148ULL, 0x97CEFCC17E9D81B4ULL, 
            0x8166FD7444DDB1DFULL, 0x205CA65749E7FE41ULL, 0x209320D3D5DD4C60ULL, 0x6074E5B006FA6988ULL, 
            0x7C7F655EAB38D220ULL, 0x7C6D2D081B68DFA3ULL, 0x301F9A0C0FC9BD80ULL, 0x86073C7D3D52BA51ULL, 
            0xFD9E182FCB00FEAEULL, 0x1AAC0E1E7924354DULL, 0xC4F6466805A43F86ULL, 0xA208E906D9A8084AULL, 
            0xDFDCABCC42D17C42ULL, 0x2FE07761325902A2ULL, 0x0B5117F46B8E6827ULL, 0x8AA777883C53712CULL
        },
        {
            0xA8DFBD43702912E5ULL, 0xD021EFA1375A22AFULL, 0x56EB84E2FD63A24CULL, 0x13904D840FDF60A8ULL, 
            0x79BE85FAAF62DB96ULL, 0x89F6DBB65F6938B9ULL, 0x2AE2FB283EE2F388ULL, 0x66F470D7710D5899ULL, 
            0xB61C79DC4E3EE56FULL, 0xA5FA49439DA49D6BULL, 0x65D0851FF437B1CEULL, 0xB4C7D37AE71E464FULL, 
            0x47851630E151DE65ULL, 0xAE6F4644C57604C9ULL, 0xE68F5E116424C9ECULL, 0x764E149795EFEE91ULL, 
            0x09D5840629EA16D7ULL, 0xEEFCED6C3C45B598ULL, 0xBC2B3F1840115DD8ULL, 0xF2E8455EB45CE131ULL, 
            0x862AC21DAA39C355ULL, 0x96D402EFE5C7E054ULL, 0x9D05E59308CDBA15ULL, 0xEF03DBDFBC341981ULL, 
            0x2BA62103CF06489DULL, 0x14F90CBE9BDF59B1ULL, 0xE9F44D3A7FD71318ULL, 0x1B47835E37945EF6ULL, 
            0x1EBE51476047FB4CULL, 0x6DB4E58376C44F55ULL, 0xAE7DFED333B43286ULL, 0x8060A1E1744FB8A8ULL
        }
    },
    {
        {
            0xAA769CF6A82B1652ULL, 0x25838ED5F5A8876CULL, 0xFF37D82928A392D0ULL, 0xB5298CED260AC433ULL, 
            0x6E250EBBA3F3BEE6ULL, 0x2E3F5A06166075F4ULL, 0xCDC401EB1863FDF5ULL, 0xFA97375BD46DF5E4ULL, 
            0xE415C696161FAD7EULL, 0xB1AF898CBBAA9680ULL, 0x17609B82E039EA13ULL, 0xF990B128BA4643F0ULL, 
            0x30D1D390A7E60CE7ULL, 0x1940D2333905D78CULL, 0xBA411091DC81745DULL, 0xF51DF56341A2CA7BULL, 
            0x9A226D02F8828F6BULL, 0xE6C3D3AA150DA7A6ULL, 0xC02AD55094AB84EEULL, 0x1864F0F77AF3DC26ULL, 
            0x453456850C1BD36AULL, 0x8D4DDFF1A752B552ULL, 0x4AB582238AF4D34FULL, 0xC93CE7758E6FD84EULL, 
            0xADD52EBFA4A93D72ULL, 0x3C4AE610A9385503ULL, 0x30ACEE7F395F1CE6ULL, 0x37D085A9391ED108ULL, 
            0x63AD7B13EE34731FULL, 0x4D6741D884C67058ULL, 0x154B80F43D622C63ULL, 0xDF419633BB522165ULL
        },
        {
            0x635EB37E4F96EC02ULL, 0x0472276303585842ULL, 0x342B40B47769C674ULL, 0xAE792937DB15F70FULL, 
            0xDB8509A509A253C1ULL, 0x8BA9DEDE517AF6F5ULL, 0x943DC8F43CB8ADA7ULL, 0x0BCA9C438C3ED1EFULL, 
            0xCB723679DBB2C21DULL, 0x88124174EB862ABEULL, 0x3DBC885EF0C74667ULL, 0xC817B9DDA16FECA5ULL, 
            0x049B74B903E66F75ULL, 0x221B65A8676E7C8EULL, 0xCAFD1C88887E40A6ULL, 0x07BB1E3201CFBB1FULL, 
            0x68697BF13E0AEBB0ULL, 0xB403E4C378C0AE33ULL, 0x957FD6BC622A760CULL, 0xA7C628564FA2A7B5ULL, 
            0xAB897297D16A3435ULL, 0x1839639D77F9D581ULL, 0xEEA049B3F66D9F5DULL, 0x405F5C6D0F8C9115ULL, 
            0x84C9C28843A917A9ULL, 0x7BD2B6ECA742DFBAULL, 0xCFCF4E2403C2C212ULL, 0x3AEB08B3FD593576ULL, 
            0x26CAFAEF72112BE8ULL, 0xB6A26D0A1C287A68ULL, 0x491FA3E196FE3B73ULL, 0x92D1768446A82E23ULL
        },
        {
            0xDAC7538D43768C73ULL, 0x4BCBF19056ED59B4ULL, 0xDD7508A3A04F0E52ULL, 0xBB33FC71B9FC6061ULL, 
            0x9A7B1C30A3CB7DC1ULL, 0x94704721F04CC151ULL, 0xECCC26268CCA49BBULL, 0x8B0CB7DC63493EBBULL, 
            0x0327259310433615ULL, 0x2213EEAB6C2FF1B1ULL, 0xF3C1809B9D05E632ULL, 0x9FE6444A80B83C5DULL, 
            0xA85F10D5C95CCC9BULL, 0xAB3345BAE10028B2ULL, 0x0AB2F6051C02BEA2ULL, 0xB3ECD6868A1C1803ULL, 
            0xF9500D66663E37A8ULL, 0xA3BC322E1681D452ULL, 0xCE32D88A48FB4567ULL, 0x07EC8A794164FAD4ULL, 
            0x28BA2D5DBFD1842BULL, 0x6BA6F2DA0C47857EULL, 0xDDF4152767366456ULL, 0xF88229841AA89A75ULL, 
            0x0FEAA42C9E4CFF23ULL, 0xE309F1BD5947E1FAULL, 0x73C551B39C7A4E53ULL, 0xEAFE08C63D9D3454ULL, 
            0xBA20E026216C0F08ULL, 0x1626D01FB692E406ULL, 0x143B7D886C0AEF03ULL, 0xAFE4A497407507FFULL
        },
        {
            0x44F7CD46F311A884ULL, 0x0F671E1841EC57F9ULL, 0xDAF3E1408D6451F8ULL, 0x2706CA9DCBA2887EULL, 
            0x1D8BFF8B3B62503EULL, 0x543D17EB019CE62CULL, 0xE441097E4F57EA75ULL, 0x58ADA7C80B6090BFULL, 
            0x44DF654E8A6D101CULL, 0x096E951F4F66835BULL, 0xE219772514D4AA52ULL, 0xA2F7233DE38B1AE2ULL, 
            0xEF84A1265A296C16ULL, 0xDA1920EEEBB9D86BULL, 0x19BAA2F0F704B654ULL, 0xE00AE230812D06BDULL, 
            0x06D7A0F7E0B89D13ULL, 0x08252C99830CCBFCULL, 0xB6033A9DE9C4DE77ULL, 0x51543823ABD6729DULL, 
            0x09078514306524A3ULL, 0x407170EF0A00E996ULL, 0xAC8B1298560677CCULL, 0x2B2D0EC49F0DC07CULL, 
            0x9C45924A766D7BDCULL, 0xCBC40E5BBD11A239ULL, 0x2281C554C7B15222ULL, 0x2A4694C81581848DULL, 
            0x62BED16840CE9726ULL, 0x38AED3CC53AF99F1ULL, 0x3FF2688E532BAE15ULL, 0xD4F5662E35A10BB5ULL
        },
        {
            0x2C79FBC5EC44BA5CULL, 0x0E55828155A568D7ULL, 0xDF84023AC13971DCULL, 0xB67D2D3AD4DD7A29ULL, 
            0x392E61F4FE14701EULL, 0xD0FF631ADBA49724ULL, 0x59647262C67D5A39ULL, 0x76CD5177705C1F53ULL, 
            0xE57B714C25619C71ULL, 0xE398B5AC02D8DA4AULL, 0x6E1EADD33C8A4D4CULL, 0x24CFE6BBA27192FAULL, 
            0x240C3927C4CE9E8CULL, 0x40150FDCE5A252EBULL, 0xC90F5041FB51793EULL, 0x0598611D1E2C5EBEULL, 
            0x2502457C5D904F72ULL, 0xAEA6A6BFACC05104ULL, 0xA410FB271F60CB66ULL, 0x6623A5F0BC845746ULL, 
            0x7BFCC8EB8B313141ULL, 0xC69961A231581E3AULL, 0x856AEEFD6E7FC793ULL, 0x2CB04194297A7473ULL, 
            0x1F3AD539B814EE49ULL, 0xDB4CA2AAE6996687ULL, 0x9E7F1235333B5D13ULL, 0xB0B4892A01281E43ULL, 
            0xB538ED3A8C54F22AULL, 0x86C53CC3111AA598ULL, 0x3A5315A70A4FF981ULL, 0x6744062EB1D442FDULL
        },
        {
            0x05E81F4E1B16D68FULL, 0x8F2C25F7C1697046ULL, 0x4F505F5327BC1641ULL, 0x4B9F03B41591E137ULL, 
            0xB307FF2520084178ULL, 0x57A1698EFEABB691ULL, 0xBFAE1B3F90591037ULL, 0x4F92A1008DB803C0ULL, 
            0xA5F8A23D4D8C2137ULL, 0x8E2A76DAC18E1980ULL, 0x8C67BF219DC3E696ULL, 0x5E0636540AD77DC1ULL, 
            0xEF43C305FF821548ULL, 0xCAB3E56B07E614BBULL, 0x014AF41945EDD64CULL, 0x5BD49828FEC3EF96ULL, 
            0x34D4C0FB010EA81BULL, 0x0570F4A38BEA1E6FULL, 0xCE8FC2DBD3AB9B5CULL, 0xF3E57528B28FB77BULL, 
            0xEBCCD6891339BA76ULL, 0x08E890E987630171ULL, 0x5B0DB8250087F724ULL, 0x863E625972FC94D4ULL, 
            0x49284BCF4CD03DD0ULL, 0x32FCEAFF97F72C1EULL, 0x92495F867F48DD63ULL, 0xC192FAF98422CF14ULL, 
            0x43D29CF5008A1704ULL, 0x5BC2F190DB30C23DULL, 0xDC5A44EEECB1B2EBULL, 0x1A0AFE788004B7FEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseHConstants = {
    0xD1E1509F674A2062ULL,
    0x5AC97F149AC5F3FCULL,
    0x29E2E1A8961D03AEULL,
    0xD1E1509F674A2062ULL,
    0x5AC97F149AC5F3FCULL,
    0x29E2E1A8961D03AEULL,
    0xF266ACB4EC2E7ABFULL,
    0xE7D6CD3EFD396F35ULL,
    0x9E,
    0xCC,
    0x14,
    0x07,
    0x2B,
    0x04,
    0x44,
    0xF3
};

