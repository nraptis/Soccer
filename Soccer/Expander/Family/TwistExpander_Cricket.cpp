#include "TwistExpander_Cricket.hpp"
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

TwistExpander_Cricket::TwistExpander_Cricket()
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

void TwistExpander_Cricket::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x95642F690A893129ULL; std::uint64_t aIngress = 0xDC18B5D2A2981087ULL; std::uint64_t aCarry = 0xF05BA87AC9AFF910ULL;

    std::uint64_t aWandererA = 0xE264BD77BEFA99A7ULL; std::uint64_t aWandererB = 0xAEA30D407AA08023ULL; std::uint64_t aWandererC = 0xD50A1491CBA1AE04ULL; std::uint64_t aWandererD = 0xBC0481FFBEB2DAAEULL;
    std::uint64_t aWandererE = 0xFD0F7957724AF97BULL; std::uint64_t aWandererF = 0xE858A6C5BB8A48ADULL; std::uint64_t aWandererG = 0xAABB4E9F1661257DULL; std::uint64_t aWandererH = 0xD8385E95BB992BC4ULL;
    std::uint64_t aWandererI = 0xC53559411A7CF501ULL; std::uint64_t aWandererJ = 0x8153795B3129F263ULL; std::uint64_t aWandererK = 0x9126C7783E029A24ULL;

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
        aPrevious = 17845273873009007899U;
        aCarry = 18364146243024464967U;
        aWandererA = 15042518403895535279U;
        aWandererB = 10431871491412378899U;
        aWandererC = 10955742832702105143U;
        aWandererD = 12923759976910854458U;
        aWandererE = 16504466349401379915U;
        aWandererF = 15319114709774964390U;
        aWandererG = 17782550195083121982U;
        aWandererH = 15764258833380839889U;
        aWandererI = 15710136221270057830U;
        aWandererJ = 16875954101801728648U;
        aWandererK = 9749845783842748092U;
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
    TwistExpander_Cricket_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Cricket::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x84BB0E17B4A1BA93ULL; std::uint64_t aIngress = 0x9B9B7A150670C03FULL; std::uint64_t aCarry = 0x8AC8C35DA68575CBULL;

    std::uint64_t aWandererA = 0xE0EBCB904FB26740ULL; std::uint64_t aWandererB = 0xFF523CBF58FA810EULL; std::uint64_t aWandererC = 0xC33C951E95DBDF7DULL; std::uint64_t aWandererD = 0xFD3BF1A883FF2C36ULL;
    std::uint64_t aWandererE = 0xE39D15543DCEAE1DULL; std::uint64_t aWandererF = 0x8FC06529F9AEAD1DULL; std::uint64_t aWandererG = 0xEEBF8408143526E7ULL; std::uint64_t aWandererH = 0xF67DE2932AB7A37BULL;
    std::uint64_t aWandererI = 0xB1DAADE06B7CF8D3ULL; std::uint64_t aWandererJ = 0xAB80E7BC1D224D7FULL; std::uint64_t aWandererK = 0xFBD6EFEBC425F64BULL;

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
        aPrevious = 10214118117146723251U;
        aCarry = 16363797623372471030U;
        aWandererA = 14789049955854380291U;
        aWandererB = 16981555129107510661U;
        aWandererC = 9867701959818447549U;
        aWandererD = 10184731291601812528U;
        aWandererE = 16443379809604670440U;
        aWandererF = 12003952739573726839U;
        aWandererG = 18041864921079620320U;
        aWandererH = 16292208844100225563U;
        aWandererI = 10262691339837085158U;
        aWandererJ = 17093299531351423163U;
        aWandererK = 10346861659555311172U;
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
    TwistExpander_Cricket_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Cricket::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF4CAFC186A416787ULL;
    std::uint64_t aIngress = 0x95A1AFCF2EF02EC1ULL;
    std::uint64_t aCarry = 0xA41BD6FE18DDF3F3ULL;

    std::uint64_t aWandererA = 0xABA92F8EA3831C62ULL;
    std::uint64_t aWandererB = 0xCF1EF0F91BEA9179ULL;
    std::uint64_t aWandererC = 0xA04AC0AA53170C88ULL;
    std::uint64_t aWandererD = 0xE381C894A2800742ULL;
    std::uint64_t aWandererE = 0xBC354D3F91961842ULL;
    std::uint64_t aWandererF = 0xBD33B2B5ADD310E8ULL;
    std::uint64_t aWandererG = 0xADA3E73699D86295ULL;
    std::uint64_t aWandererH = 0xD10A367E7A284F4CULL;
    std::uint64_t aWandererI = 0xA8C0AA7D67A55437ULL;
    std::uint64_t aWandererJ = 0xC21395FA627D96AEULL;
    std::uint64_t aWandererK = 0xE950D24630EE9D3FULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Cricket_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Cricket::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB51A3C0D0D80E8F1ULL; std::uint64_t aIngress = 0xFB164FFE8044F581ULL; std::uint64_t aCarry = 0xAE87049C3F58D265ULL;

    std::uint64_t aWandererA = 0xCD5EB74342227A5DULL; std::uint64_t aWandererB = 0xE75FA3A1A9D6FE5FULL; std::uint64_t aWandererC = 0x9AFD516DE06EFDF7ULL; std::uint64_t aWandererD = 0x8E4D9F6732400A47ULL;
    std::uint64_t aWandererE = 0xF9B56AA9A3AF37CEULL; std::uint64_t aWandererF = 0xF48D7FBF4A6C8C4AULL; std::uint64_t aWandererG = 0x8D9E2E185DA68A6DULL; std::uint64_t aWandererH = 0xE74EFF7BE3B7606FULL;
    std::uint64_t aWandererI = 0xDD0C98902482D507ULL; std::uint64_t aWandererJ = 0xF2E6EFE11550C0EBULL; std::uint64_t aWandererK = 0xAC4AE0C082BAD582ULL;

    // [seed]
    {
        aPrevious = 10087422685738880030U;
        aCarry = 16587956369805133881U;
        aWandererA = 14545718319904002078U;
        aWandererB = 15299498111580574944U;
        aWandererC = 16496158610590237386U;
        aWandererD = 15180168328425019830U;
        aWandererE = 17346952491439415634U;
        aWandererF = 9310537469320298149U;
        aWandererG = 9805384552018290170U;
        aWandererH = 12056582514777431995U;
        aWandererI = 15499401351492738745U;
        aWandererJ = 16432575623225211645U;
        aWandererK = 14748967906123736620U;
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
    TwistExpander_Cricket_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 2, 0 with offsets 4331U, 2584U, 7299U, 3557U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4331U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2584U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7299U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3557U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 1 with offsets 732U, 2269U, 4773U, 7898U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 732U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2269U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4773U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7898U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 2 with offsets 3898U, 141U, 5351U, 7030U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3898U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 141U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5351U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7030U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 3 with offsets 6106U, 6442U, 6332U, 2135U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6106U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6442U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6332U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2135U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 with offsets 788U, 131U, 1809U, 595U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 788U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 131U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1809U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 595U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 0, 1 with offsets 1911U, 1700U, 1037U, 935U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1911U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1037U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 935U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 3, 1 with offsets 1330U, 1389U, 1949U, 156U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1389U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 156U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 3, 2 with offsets 1884U, 1857U, 68U, 882U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1884U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1857U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 68U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 882U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 601U, 436U, 102U, 28U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 601U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 436U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 102U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 28U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Cricket::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 3 with offsets 5293U, 4422U, 7171U, 2116U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5293U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4422U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7171U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2116U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 1, 2 with offsets 2502U, 4577U, 4880U, 6073U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2502U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4577U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4880U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6073U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 3, 1 with offsets 4907U, 8150U, 3029U, 1217U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4907U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8150U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3029U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1217U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 0 with offsets 6930U, 320U, 7768U, 6604U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6930U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 320U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7768U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6604U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 329U, 7728U, 8051U, 838U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 329U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7728U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 8051U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 838U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1478U, 296U, 138U, 404U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1478U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 404U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1906U, 1128U, 1706U, 1571U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1906U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1706U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1571U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 522U, 1510U, 1162U, 531U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 522U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1162U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 531U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1772U, 841U, 1628U, 1111U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1772U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 841U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1628U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1111U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 [0..<W_KEY]
        // offsets: 583U, 827U, 1473U, 569U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 583U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 827U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1473U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 569U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseASalts = {
    {
        {
            0x906B162D85E7B882ULL, 0xB20C16C9B3B813EBULL, 0xBB2FD13D03FD829AULL, 0xD0F9061F60F77C8CULL, 
            0x8A7DC4204AB2C980ULL, 0x28A06AF8C1E72B21ULL, 0x2F0D9A4269816397ULL, 0xFE4E7865ADAE8215ULL, 
            0x08828A60C1B6D1C4ULL, 0x492A19A4C49AA4F1ULL, 0xD4F18F1715BCE896ULL, 0xF204D46520BA0809ULL, 
            0x8267F7A9AC2BDE6DULL, 0x9453D3DA6DCB8E4AULL, 0x66657B8502110F20ULL, 0x4FE01882070EFB63ULL, 
            0x1089A1A675097C00ULL, 0xFFDE8899E7A7D8DAULL, 0x6A6A577001DF9C1EULL, 0xB2C2A6BF75BF53FEULL, 
            0x51C183645751D9E2ULL, 0x121EF4FCDE99F4E8ULL, 0x6C635A82E4AB9906ULL, 0x2B6FC331DFD0A371ULL, 
            0x5D1AB45FDF4B5CBAULL, 0x70BBABAC628179B1ULL, 0xC757494B04F48813ULL, 0x04E68CD7B83659D3ULL, 
            0x4CDAF26156ED1A79ULL, 0xD0690EBC05714571ULL, 0xF696AF4A33BE6F31ULL, 0x58586CB3688AD3AFULL
        },
        {
            0x00CBE8C3C141953BULL, 0x914E1D04E5EFC60CULL, 0x1C671FD04C80610EULL, 0xD2AD6AE4787AD846ULL, 
            0x5558F3BDB4704CB1ULL, 0x9B91A3837D7D0E6CULL, 0xC665704C1943024DULL, 0x658838618822F71BULL, 
            0x317FDC471729674BULL, 0x211F93F3A976D365ULL, 0x509D31F5D7D7B1ABULL, 0x4D10C429033082CEULL, 
            0xD460D2D10131B96EULL, 0x5E2E54BB6D75BDFAULL, 0x438FDFFC8AAA5E05ULL, 0x73235D6D6B9673B8ULL, 
            0x47D4BB742C3AD49FULL, 0xC7C4DF41FE064338ULL, 0xE92EA0CC11765373ULL, 0xF1BFAF135ECD063CULL, 
            0x17AC7076BD48C6B1ULL, 0x82993419EFCFF843ULL, 0x1052F26F37A87C5AULL, 0xA03A1397463B9E81ULL, 
            0x426E2EE39D39E22FULL, 0x98B869C01D5615E0ULL, 0x1DBEB72BEB9C660EULL, 0x941FF32438874B50ULL, 
            0x67EA7B5F22996629ULL, 0x22742702A3AC1979ULL, 0xD6FAA8AA49888FCFULL, 0x8CB16547FA58816AULL
        },
        {
            0xBEBA179EB554DEE5ULL, 0x7442A71AC9C70CC7ULL, 0x9C839CC1EFA3B8A7ULL, 0xDA94383D25B2ED5CULL, 
            0x994CAFEC3D262799ULL, 0x5E66D1DBACC17BCBULL, 0xCAED808DD209E6ABULL, 0x0543422BC60D8F0FULL, 
            0x75F19A191A947D3CULL, 0x87407102C5092D3BULL, 0x0D31695EA5D0D8FEULL, 0x5CA33672A6B13C5CULL, 
            0x2FF286051F511848ULL, 0x0ACCF1796891F4FFULL, 0xA1C77874945E87C3ULL, 0x5A9C4AD2EA2CD7A1ULL, 
            0x99A297A4A14B6B1EULL, 0x5CAD7ADADD58D38AULL, 0xEFD8D618C40795EAULL, 0x3E52E34AF316B6E6ULL, 
            0x1FF8FC8AE1582788ULL, 0x0136AF019326CC91ULL, 0x37DD7F2899478CEAULL, 0xD49F4450AA3090EAULL, 
            0x3DEAAB13546E05BDULL, 0x98BF037A3F216693ULL, 0x22DC535B420324E8ULL, 0xAB2312E4B7CE7861ULL, 
            0x384F7D7EA754DA4AULL, 0xF90C675CC7CA9F28ULL, 0x512A9F1816FC1AA8ULL, 0x6B03AD90808BA331ULL
        },
        {
            0x8562AE54FCAD1B51ULL, 0x07363527DDED96EEULL, 0x2F7A5F72A4A97A79ULL, 0xD928D348E81932B1ULL, 
            0xF2B5D2A47100B1FCULL, 0xE010964CFC9D7DEBULL, 0xCB433D54EABE6232ULL, 0x5292C69BF77F841BULL, 
            0xEEBA94D67D1FC5CCULL, 0x848E9F8BE665D531ULL, 0xE496EEF1A00A6D7DULL, 0x1AC69A239292BA6EULL, 
            0xC64F1A7AA8F2FFB2ULL, 0x293A0037AA317255ULL, 0x4E9DB0C625233136ULL, 0x766F9EA39D797D9DULL, 
            0xF7BBB1227BD32990ULL, 0x3D235F3AAD62D5B4ULL, 0x3EA4D8347BC108F5ULL, 0xA3FDBC0913EC9631ULL, 
            0x96080FF7502E7EAAULL, 0x1A2156D747FEDE00ULL, 0x66F41EA945E7D4C3ULL, 0x52603740713A9D78ULL, 
            0x51291EAD48FAA9B2ULL, 0xCA988A9F8042503CULL, 0xC2A771998CDCFA0BULL, 0xA9FB4A9ADDA34D66ULL, 
            0x8D3D8CBA64C9C5EFULL, 0xDD0040E363A70AD7ULL, 0xFA93CBF8FFF3BA27ULL, 0x9F5B9AD40AC3B2A7ULL
        },
        {
            0xBDC7C405A618BDDDULL, 0x4941A84B622DEAA6ULL, 0xDF6F9E7D1C2B5E82ULL, 0x286B394471C1F550ULL, 
            0x10ED8684806A1045ULL, 0xB25B13C8C9BF2007ULL, 0x27B6E477FF341966ULL, 0x68B87E53260EEA58ULL, 
            0x28D59335B948FECCULL, 0xF575DB56E1ABD1EAULL, 0xD1C808FC8B62B696ULL, 0x91A666BEE0D4716CULL, 
            0xD991BCC83BA431BBULL, 0x1E080C26572841A2ULL, 0xFA11B2B53DF0E5BEULL, 0xA5F6039E4F805DE6ULL, 
            0x083FA6881C9930D5ULL, 0x59939D0917362CA9ULL, 0x406E63ADEE4A394BULL, 0x3055CE161E9EAE25ULL, 
            0xABDF992968F75A63ULL, 0x07325FE4E78CBAD7ULL, 0x92C06975466836DEULL, 0x189E852E7B179C40ULL, 
            0x572648F86DBCCCF9ULL, 0x1CBDFD061D612A4EULL, 0x1DE2DD00F79858D4ULL, 0x0A10456F000530D9ULL, 
            0xDF735CB17BBC42CDULL, 0x47D0FE483A34DF35ULL, 0x6E414D166183CE47ULL, 0x71CFB254A18D47DBULL
        },
        {
            0xF33A3F9B73758A78ULL, 0x1FA3E3B696F0D101ULL, 0x101D8EBE7EA8FB43ULL, 0xF798691D54C96913ULL, 
            0xA0146FBE38206A74ULL, 0xA61D2D8B1C19E100ULL, 0x733D547161E0F726ULL, 0x4914D0354481A2E5ULL, 
            0xCC3AABA44A95C68CULL, 0x640D1063CEFE897EULL, 0xA5A9C39F3D759CFDULL, 0x5D3BD799F1A8C69FULL, 
            0x81D7B65BF0CA9381ULL, 0x43448442D2AC639EULL, 0xD234CDAF7DBD18A8ULL, 0x984C593EBE854AE2ULL, 
            0x522AB44DDC2C0651ULL, 0xC366C9F1CD7B101DULL, 0xED513D9BCBBA9171ULL, 0xD9B3435FE648C2DFULL, 
            0xC8732F895C797BF4ULL, 0xA64CFC837239462BULL, 0x3A211DFDC3A73D1FULL, 0x11385CE09FF0FDBFULL, 
            0xF243CF6A59DCE5D8ULL, 0x713BE017C43EE9B3ULL, 0xBA32B557B5324A85ULL, 0xA5103FAD7C828823ULL, 
            0x4E70E7745E4746CBULL, 0xFFB1EF61935F19CEULL, 0x911D7D881FFDBC13ULL, 0x3B9093A38A4418ACULL
        }
    },
    {
        {
            0x072E6E448C9AD655ULL, 0xD67DC1BF326F1A59ULL, 0x25074D5A4976F99FULL, 0x62E81444A6F3A580ULL, 
            0x4D8D26220F90F926ULL, 0x9657B88F0CBCB514ULL, 0x78D171CEF52C608DULL, 0xA7D30EFB3994A17CULL, 
            0x6FA1360C7F118588ULL, 0xAA66FDB64A1334E0ULL, 0x1C8D9250365AAC9BULL, 0xCED7648DD63EC318ULL, 
            0x7812897B79E2640AULL, 0x587EF3C3663A6348ULL, 0x6B6AE03CEFB4B576ULL, 0x4E20692844812367ULL, 
            0xA220CBB2F67A8F15ULL, 0xC1A733E98FFFA1F4ULL, 0x2463DF8A5D618678ULL, 0x403FA29D9FA5DA7CULL, 
            0xE8FC75274DAF49E5ULL, 0x2F828131CFE4FA63ULL, 0xC8129D8E224FB288ULL, 0xD2676031EFFA1363ULL, 
            0x6334501D77044354ULL, 0xF5CD70BAD10BAE98ULL, 0x6E9B32DA03338AEEULL, 0x664B88013199750BULL, 
            0xBBD2E934B03321A0ULL, 0xCB157B6675F3EEF5ULL, 0x680BAD0BBE42EB25ULL, 0x07BD333BDC86DD84ULL
        },
        {
            0x0B4F555402EF705CULL, 0xB19DCE993779C5BDULL, 0x91BA6B1CF3C77F71ULL, 0xA1312DA09F286A09ULL, 
            0x437F7391E18A64B2ULL, 0x2F3545BEB3453622ULL, 0x67EDD036B1296D54ULL, 0x677CFBBB55232B0CULL, 
            0xEFD222318FF468ABULL, 0x9037DAF0884074DFULL, 0xB305ECB74FEC58B7ULL, 0xA072A0316F6BA884ULL, 
            0xDFD9A1E099C0BE9AULL, 0xA6C58A574DA52E9BULL, 0xA7D98EAEC847B341ULL, 0x071B93C21DA59A25ULL, 
            0x3C8588DE566B46E1ULL, 0x8E4B469E355CE3BAULL, 0x46EE14742566BE77ULL, 0xD79918D1594CE31FULL, 
            0xBD2BB73F42EF8FA8ULL, 0xC7915BC02DE5A9F1ULL, 0xA6A0CDFA7DB717CCULL, 0xCE03D2A420314E84ULL, 
            0x597FD98B150F43DFULL, 0x72D8974365302CA8ULL, 0x92F80C36E682805FULL, 0xD5C81ACD763A87AFULL, 
            0x5D3870140A689D2CULL, 0x657EC95A03EBCACBULL, 0x4E3A3CA5AB3D1205ULL, 0x432419160197A041ULL
        },
        {
            0x97D8C8BAF12E1CFAULL, 0x57488DB46C785E30ULL, 0x224369EDFA465FF2ULL, 0xB995FBF7BAE7A597ULL, 
            0x01B6568D74DFC4A7ULL, 0x249DCD1DECF3AFFBULL, 0x1E1A85C368DE66ACULL, 0xF6157B2B6F533DB3ULL, 
            0xB0AE121EAD8D4927ULL, 0xC23D3ACF906221E2ULL, 0x3B63B20C0480715CULL, 0x6008DC94F63CA8B1ULL, 
            0x1C8ABBAFE7E606DFULL, 0x5DA422C779325680ULL, 0x7FD4BF50A2339720ULL, 0x85B1E4BFF8580E90ULL, 
            0x5389DD4C1D7DE177ULL, 0x245250420BCBD94DULL, 0xFB4B9793FCE0B63EULL, 0x299963A8479CBFB4ULL, 
            0xFCC366364CE9A7C1ULL, 0x08286DB1FB29DC9FULL, 0x89C2DFBE6D38029CULL, 0x59B137ECD5F2D417ULL, 
            0x85D47FCC622AEC35ULL, 0xDE3F531C088D1060ULL, 0xEE3D4A316CBC1C1FULL, 0xDEA633CC4BD68E4DULL, 
            0xA5345D5AAC559416ULL, 0xF348104B78E65784ULL, 0xC089C577627F6EF2ULL, 0xF7EDA1676AD5CE1DULL
        },
        {
            0xE3B50728B35483B5ULL, 0xB052C9DD63CC32C9ULL, 0x6AD7F72B012F6B35ULL, 0xF166EC2D16894B5EULL, 
            0x611C9B7FEDF75572ULL, 0xECE9CB643053674CULL, 0xFFF4BAD6DE5976AFULL, 0xA675B5F2E21428FCULL, 
            0xE036E3CB2CBA2112ULL, 0xCBD702F3503C6409ULL, 0x4800828F75F4D64CULL, 0xCA73F3533AD88D13ULL, 
            0x8A7082B946ABD2CBULL, 0x8FC2ABF9B7CC80E0ULL, 0x8532E59B52A2B0FAULL, 0xD1C1C8DF474CA0DAULL, 
            0x157F27E69D47800CULL, 0x899B696E94E21532ULL, 0x226A3B7548791954ULL, 0x7A7C707BDCCC667EULL, 
            0xE1EAE05F035ED835ULL, 0xF43A180A73FECACBULL, 0x9D08DF57733FEEBAULL, 0x66A06607B3D26FDFULL, 
            0x801DDBBC5D5B767BULL, 0x00280F5C870FF9B7ULL, 0x340B5EA7FEB0A6D5ULL, 0xEA9F1DB5B6B94581ULL, 
            0xAE0FE25B57BA4B61ULL, 0x131A3BA39249C969ULL, 0xC99C4FC97D187255ULL, 0x1BB62C345E34CB1AULL
        },
        {
            0x49F217C51C70C8F8ULL, 0x84B7254A735ABE3DULL, 0x3505EB67699DC8AEULL, 0x25623A8B1168069BULL, 
            0xE71B4EF952176536ULL, 0x5E93341F961A852DULL, 0x26B6571A291564D6ULL, 0x911B46A1BFC27992ULL, 
            0xA09CE6ECFFF67F21ULL, 0x40F2C3844DFB391CULL, 0x97C155FD39EDF9FDULL, 0x9927926F439D6517ULL, 
            0xFF1827A122CE2EF6ULL, 0x737AD5E65CBC45F4ULL, 0x603731655B224DFBULL, 0x8C3E27F98D49AA72ULL, 
            0xF0A31B1E5E008576ULL, 0x4422505BA0B7C3D0ULL, 0x55EE5312028823C9ULL, 0x9BA6ED216257BC4FULL, 
            0x67B14B3C41290CC9ULL, 0xF8F8EDE23CC58740ULL, 0x6DC3AB4D16C8303EULL, 0xB020AD30D2349ADEULL, 
            0xA53F59C64175C51FULL, 0xCCD8028063B627D6ULL, 0x13AEBC3BDD672E61ULL, 0x46B020507DBBDED0ULL, 
            0x263462FF80204CEBULL, 0xB2EEA4C39CF7F869ULL, 0x6295148E8E06A2E1ULL, 0x80B66EE300EF6B28ULL
        },
        {
            0x467219D0998B0B81ULL, 0xBED32EEDB64F2D90ULL, 0x9E2AD1F35C753C5EULL, 0x8C12A1C929FBAA97ULL, 
            0x424F4FDBFD5A1086ULL, 0x33D0749A49537D2AULL, 0x465A26154CDAC085ULL, 0x6C2312576EA0D4A6ULL, 
            0x2A93F956D57316A4ULL, 0x3EF00C6C89F1BB5FULL, 0x8A3597D08A5AA4DAULL, 0xA8A49E37FD5BEF7DULL, 
            0x14D79F984E82EB04ULL, 0x4DE47E8B20D8E388ULL, 0x09BAEB8EB09E4E48ULL, 0x08F2DD4701E7F3D6ULL, 
            0xFB9AECF9DC9019F7ULL, 0x6CDF422D0321D7F7ULL, 0xBD616C6E9F796B13ULL, 0xCAE09E44EE142B89ULL, 
            0xE078744255C571C1ULL, 0x1EA479B364FB9FB7ULL, 0x3CA9DAAB4F575F3FULL, 0x45A2819C48EDD3B6ULL, 
            0x6DC469FF80737A11ULL, 0x64F1F8016597B87AULL, 0xA2FCBBEED70F2028ULL, 0x04939A168C80C841ULL, 
            0xF5A3EBC4BA08C6D5ULL, 0xA86A22255BDA8C58ULL, 0xA5596F68F724FD39ULL, 0xE9E79B54F01C54A8ULL
        }
    },
    {
        {
            0xC39B74509C289B8EULL, 0xECACC36AFA4A5842ULL, 0x257A277E064500B0ULL, 0x25F4DE58E4DFB7CBULL, 
            0x1E00F64DFF88633FULL, 0xF0A6E2431E2CB08BULL, 0x1E554A0271C04FEAULL, 0x04F9C02646CAD33EULL, 
            0xAD0A63BF63B21083ULL, 0x084635948727CAC4ULL, 0x04F30ED561BC3046ULL, 0xCD2939B577AD0020ULL, 
            0xEA2E73C67E4A3F3AULL, 0xD9CC2170285ECA69ULL, 0x02B444F017B615D3ULL, 0xF1FE0B40EECACF9DULL, 
            0x8349DD6650CA59B3ULL, 0x251608B36D9427FCULL, 0xBC632406D75C8036ULL, 0x6B3A92093016CCEAULL, 
            0x3BEC31AC137A5F70ULL, 0x11DC1A391BA31D91ULL, 0xA97C8B211C12FE1BULL, 0x228CAAF42E0E0853ULL, 
            0x88AC27BF4FDE08FFULL, 0x5A0EB91A86CCC164ULL, 0x24C93C2A48F9BE92ULL, 0x65B78F9332513380ULL, 
            0xF24D3336E3BD188FULL, 0x65C8A835139FEF3CULL, 0x29C1F183BD932074ULL, 0xC0C30E8EF82075A4ULL
        },
        {
            0x958AB4D10AAA40E2ULL, 0xD1411EBA97A00EFFULL, 0xC6FDE7810E8F8918ULL, 0x4425943E0232573EULL, 
            0xF05C8F8251E9A06DULL, 0x2A5F7A42CEC16F11ULL, 0xEFE64D22C0010683ULL, 0xBBBCBD6D639FE332ULL, 
            0xE5030EBC65E80794ULL, 0x4BAC493D5F6320CFULL, 0x3167B5494F44C3B0ULL, 0xE3CB4DDBF12D7E72ULL, 
            0x904B96D35822C14AULL, 0x6710BBCB02417193ULL, 0xAFE590953D846226ULL, 0x32791F61173D166FULL, 
            0xD1F85B6872E51904ULL, 0xA85913B2C5374887ULL, 0xBBD35AB76E3F6247ULL, 0x19EF4C287B51DBC9ULL, 
            0x900A21CBEE064738ULL, 0xF501ADDAB1D39DD2ULL, 0x0D4CBDF6413D23F1ULL, 0xC57233FF3627D7E7ULL, 
            0xF09E2B6322AA7C6BULL, 0x86EA9F551AD7204BULL, 0x39321044798186AAULL, 0x1D172F9877170FF0ULL, 
            0x189DD5EC653F37F1ULL, 0x366EFEC980F9E634ULL, 0x80870E542017DC94ULL, 0x54089D4094EE1603ULL
        },
        {
            0xFE8BE6DFE7F9FC8DULL, 0x941B9A5A46B7FEE7ULL, 0x01AD669B922D3E76ULL, 0xA0F289EEAC9D4480ULL, 
            0x2A0319B9B98DCDE3ULL, 0xF03095EEAC67FBE2ULL, 0x44E431E0F046DBD5ULL, 0x283F7009135462B7ULL, 
            0x3259499964073470ULL, 0xC1E8D6B9EAB6B33FULL, 0xC123DC7762926675ULL, 0x3F389C7C956F0001ULL, 
            0xAF255FA32F763488ULL, 0xCB624ADB42DF7C6BULL, 0x72525B909F0EC35CULL, 0xE77385FBAFADD537ULL, 
            0x54B5A8C87F56F669ULL, 0xDCDB7195C61EE17CULL, 0xC6C394AEB6D04BB2ULL, 0x6DA7EE7DBE88250CULL, 
            0x04C72799822AB40EULL, 0xBD3E0201ACA5F718ULL, 0xD7394C0A9C113B23ULL, 0xAE8415E9409E250BULL, 
            0xD6686B590FF2E43FULL, 0xA6D063FBCABA6017ULL, 0xE433530D3EC2348CULL, 0xB397C5596635B711ULL, 
            0xFBABCD30CEBF515AULL, 0xB5C0112138ACF35BULL, 0xC47CEA3B5FB17A1BULL, 0x27CD0D51B88507F8ULL
        },
        {
            0x32292BA58F80B040ULL, 0x820B41A8F46E44D2ULL, 0xAB14D8606FBF302FULL, 0x4A5629625BF9D503ULL, 
            0x6BA154515110B870ULL, 0x93C1687205546900ULL, 0x0AEEFD55D5FEA204ULL, 0x4A56E9D3177CC900ULL, 
            0x7CB818398967A65DULL, 0x7FAD6754891A1AD0ULL, 0x9EEE13DFAFAA6457ULL, 0x8BF225FC1A087CD2ULL, 
            0x23982EE029C85A7EULL, 0xF2614EC3342E7D9AULL, 0x7F39E61D80DC3523ULL, 0xCDC50FD92503E372ULL, 
            0x98DE0E8BD0FDAB1BULL, 0x70F546D234F4AE50ULL, 0x012AE8344C5399D0ULL, 0x08B1569DE823FBC4ULL, 
            0x42163785B6E871D8ULL, 0x2082E8090CA0CB61ULL, 0xF60B3BF863D1D935ULL, 0x6DC4D4AC1EDC1254ULL, 
            0x1EEEBA813328C9DFULL, 0x089EF646F220587AULL, 0x6F2B3EA456B620BDULL, 0x8AF6FA3A42CD4895ULL, 
            0x3975B757CB1B6929ULL, 0xFBADF8247D085CD9ULL, 0xA31EAC55D1D8B0C4ULL, 0x70F6EBAB3889693BULL
        },
        {
            0x13B2DEEA9254C1FBULL, 0x761141370D92E614ULL, 0x5368169C0BD93FE1ULL, 0xF5D6290E5EA9E2BDULL, 
            0x332F574CD7E6D11FULL, 0x9E838EBC6ABB0728ULL, 0x6D32DF5433E593A8ULL, 0x4429683A1E60979AULL, 
            0x3C50E4D3055DDEBCULL, 0xB7FD1195C1E55AACULL, 0x5140F5249C3CC2CAULL, 0xF0A9967C0033CEF8ULL, 
            0x09D96FD986CC3143ULL, 0x2CB6758EC559FFA8ULL, 0x77428D2779C87E11ULL, 0x09A7C4DCBC1679FCULL, 
            0x9D40F0BE9594644CULL, 0xBA257E8AD9307E36ULL, 0xE1049A4124516335ULL, 0x56B8401DD80A629DULL, 
            0x30547593F0F73F31ULL, 0x107F7DE0E39CC874ULL, 0xC53170041F977ADBULL, 0x060F956C243F380DULL, 
            0x7DE1B8C310A8CCB0ULL, 0x295E06FB8C7049F1ULL, 0x90C1BAD8326F590DULL, 0x27AC4967B96E83F7ULL, 
            0x6FE350D4681859D6ULL, 0x0174D7F28F910AFCULL, 0xDFA98BF6B8094BFEULL, 0x55F18813FF8ED521ULL
        },
        {
            0xF0AE351B04FE754FULL, 0xBF089344515A34A4ULL, 0xE4068F2D0572798BULL, 0x9E097ADB974B164CULL, 
            0x127380756F211CA2ULL, 0x5C582E968FE337D3ULL, 0x9B8418FC8C971044ULL, 0x84543A835C83E82FULL, 
            0x92B95A1A5D943449ULL, 0x8A3BF5ECBEF3BFB8ULL, 0x254688A3B671080AULL, 0xAB3FD59959E9D9A1ULL, 
            0x37DCC5CEB36E4F06ULL, 0xEC2C46196B362C27ULL, 0xE8146D4C0CD1F77FULL, 0xE94709B59A19F72AULL, 
            0xA57CEAF82BFBA340ULL, 0x73256CDDCEEF67E8ULL, 0xFF3F9E73DE43E8E3ULL, 0xA8FA9BDDB3657B06ULL, 
            0xFDC9AA912F003961ULL, 0x7890DB3DC33C2399ULL, 0x4185913BBF957778ULL, 0xD95C04F2D6002105ULL, 
            0x2664E642C4493C2CULL, 0xBA48FEC7ADC95189ULL, 0xD5DE1FB3C7D07445ULL, 0x821B057C1A32F953ULL, 
            0x6B7E8B3158A9E5E6ULL, 0x931CFD3A8F72AD52ULL, 0x93D49314B01B563BULL, 0x2B0DA84F4C7939EBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseAConstants = {
    0x063F67ED99AB7466ULL,
    0x73C853C289C01A15ULL,
    0x335539A964385456ULL,
    0x063F67ED99AB7466ULL,
    0x73C853C289C01A15ULL,
    0x335539A964385456ULL,
    0xC31BF7F71D854880ULL,
    0x15BD4EB6F344D8D6ULL,
    0xAE,
    0x0F,
    0xD5,
    0xEC,
    0x1E,
    0xAB,
    0x5E,
    0x55
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseBSalts = {
    {
        {
            0x7EF2270F62DF6B8CULL, 0xC321996CB9F96890ULL, 0x38A1612C70ADD47AULL, 0xCE474A3D43501102ULL, 
            0x35735D15ECC0F060ULL, 0x4ED898CA3E116772ULL, 0xF5EF14B26AF67E9CULL, 0x1AA58547F7351A79ULL, 
            0xFE9B84DE51EBC9C1ULL, 0x94D1C256CCD77D01ULL, 0xBFABB2ED46A9145CULL, 0xB9007292BF1AD39DULL, 
            0x8CED4D86BF77E4CEULL, 0x287A61D90D0F3024ULL, 0x880F999DD9F54434ULL, 0x7C40158E4962B846ULL, 
            0xD9997647754495C3ULL, 0xB452038C99EC3EFEULL, 0x77542819BAFD56D1ULL, 0xDAB7A1877DDB18F0ULL, 
            0xE1B48ED1BF8BE3C9ULL, 0x900BFAEC54500AD9ULL, 0x3EF2E36606B40E78ULL, 0x762180587CFB5173ULL, 
            0x6D5C9544F7925D2BULL, 0x0F912EE0AC2594BCULL, 0x6F63EA5583F69FE6ULL, 0xEB28D405542AF85CULL, 
            0xA459967A95E59364ULL, 0x258E168F55E13215ULL, 0x30790A4533577872ULL, 0xDEE2B4452B518618ULL
        },
        {
            0xDF1455E584E62EBEULL, 0x0F6C58905ECD29EEULL, 0xA8F28535C7F8AF6DULL, 0xDDBE81E24A751358ULL, 
            0x1151E67E526D8912ULL, 0xD593F4CE3ACEFDF7ULL, 0xE2F3D2E30227CFD6ULL, 0x6DFD930EEC7E142CULL, 
            0xC8FC631940F1FD78ULL, 0x4C34E29105ED0057ULL, 0x7221D707FB639C96ULL, 0x9D87E8EA6D3A153AULL, 
            0xED142B7624452DE8ULL, 0xAD8944B2B36A34CEULL, 0x7FEA04134478B8E6ULL, 0x3B695FC695BC2499ULL, 
            0xB7BBDF6444C21CA7ULL, 0xA0149E43B748BF84ULL, 0x751C1163F757F4F7ULL, 0x57C648EBE547C502ULL, 
            0x87DF522BE67C2C77ULL, 0xB07EFD9878993E8FULL, 0x7B3C1948D78277EBULL, 0xCECCFB7F10724DDFULL, 
            0x4B83B9E00C3ED2C8ULL, 0x9447C42E2D947695ULL, 0x885A49F26FA85D07ULL, 0x85673278B9509DE1ULL, 
            0x8C1339E8604330D1ULL, 0xF9F8A52BF396FC62ULL, 0xAAB4F6F114AB83BEULL, 0xF8DD4C2C9C70F60BULL
        },
        {
            0xBD0FC6AA7776D3B5ULL, 0x6486B7FB79CF0F33ULL, 0x5DC751191A6810B2ULL, 0x1AAB99424A74EDC1ULL, 
            0xEBDCDC61E5AD5FDEULL, 0xD0CC0D792D0C3096ULL, 0x1EDAC0553215CD57ULL, 0xCC0EB62813ECC64EULL, 
            0x74C054AE910625B5ULL, 0xF2E12FC76889478EULL, 0x38FB017C0BF905C5ULL, 0xC833DD73D5C288E7ULL, 
            0x5F198637D0A695D8ULL, 0xC0B5712E3A7BD25EULL, 0xE6E2F2CCED637C4AULL, 0xC60C84B87DFB2AB4ULL, 
            0xE0E6FB1588F5C45FULL, 0x33B61457C8BF73B0ULL, 0x8340D130E160FBEDULL, 0x9EBEEA533AD59B24ULL, 
            0x56CB698EF9813F27ULL, 0x079B3431FBCC8CFBULL, 0x0F73B26CA6B92F47ULL, 0x83F16689A5A593A0ULL, 
            0xA17C0850F2594FB4ULL, 0x2D42B1FD18FF39E7ULL, 0x97D697A18B22D920ULL, 0x4F86AC4D1DDE384EULL, 
            0x3F77569F77100324ULL, 0x42CAD9A816F228B8ULL, 0x154DFF38C5D10134ULL, 0xD78C280117522D46ULL
        },
        {
            0x86474BA17CDA86E4ULL, 0x1E94755C3663FE9EULL, 0x1507298CCC3A1F8FULL, 0x3CFA90941F2689FEULL, 
            0xDC49002E425E2146ULL, 0x4A5C266CE9C297D9ULL, 0x02BE9531A61A39FAULL, 0x81BF91917C33EADAULL, 
            0xCA6AF921C3FEA790ULL, 0x80C1C579E49395AFULL, 0xAFE6976F386CA284ULL, 0xC3F0ECDD8578E4F5ULL, 
            0x5E2602AC24C837CAULL, 0xBC0CB9DB0298DA0EULL, 0x4B5059C65A9F4B4BULL, 0x9069930FC493FDE1ULL, 
            0x38A92C2B55FEBA82ULL, 0x05096B21BE40C6F1ULL, 0x054030E9CE98DC4CULL, 0x36F245318061286CULL, 
            0xE053B29404C76B92ULL, 0x66C6761965C653A7ULL, 0x87D358FCABCE41BDULL, 0x3789930A704629F3ULL, 
            0x702C78F2ECCEF26EULL, 0x9D7E07C0DD90D8B7ULL, 0x57CE6C566B6F6013ULL, 0xD0D988CAEE33611CULL, 
            0x81C456F346539D59ULL, 0x0982C6505D53D417ULL, 0xB30B7ED618CAE604ULL, 0x9083D35E37EC7594ULL
        },
        {
            0x74A84876D3B4466AULL, 0x0A6EF6BF7D268F73ULL, 0x1A372AFB0C0BC90FULL, 0x27ABEF8307D7BCA2ULL, 
            0xD333FC4946D34F64ULL, 0x2499F4DFB79B8916ULL, 0x86EAAC10C0561035ULL, 0xDED2FFA12421764CULL, 
            0x1FA52C8D12A3DAECULL, 0x0F4DC660111E37ADULL, 0x6F5435ED4E668BCEULL, 0x80E40B77D75C9CF2ULL, 
            0x65BD42CDF2F7F932ULL, 0xAAAB7F3F9F29BEF6ULL, 0xF0E244373E76508FULL, 0xE7E453B5377A09E2ULL, 
            0x4ADF32755724505CULL, 0x6C3FF6E673662D5EULL, 0xFEC3D089AAFD4CFFULL, 0xC458D9E6A97B1280ULL, 
            0xC329B207FBCE7194ULL, 0xA4EBD69B2C5932A0ULL, 0xD8DEE6C98B870524ULL, 0xAC824144E774BEFFULL, 
            0x3C8834D9D45C222AULL, 0x6B3AD4CE7BC89324ULL, 0xC8CD8A0097F464AEULL, 0x2329D009F4CBD69DULL, 
            0x3907D6F5215C16E3ULL, 0xD3503D9270A0F28EULL, 0xE7766E9AB3B4AC8BULL, 0x21C80A70AD295659ULL
        },
        {
            0x99BD70462163F8DDULL, 0x28B527A00E26E374ULL, 0xF02B1C6DD659452DULL, 0x2A85AB9AD10ED426ULL, 
            0x83EB36C21F971759ULL, 0xBDED267F98D07CE5ULL, 0xBCF3872F4DA9B90EULL, 0x853356C0483E983BULL, 
            0x3FF80FA3229326C5ULL, 0xCFF1C2DC2F062C1EULL, 0x1C2636ABAE734153ULL, 0xC0BA9CBFD18C07A6ULL, 
            0x05A399DCB1E465CFULL, 0x21AEC15001AEB1C4ULL, 0xE40FA12B87DD0C6FULL, 0xBAE8FF5F8F668E2BULL, 
            0xAD7DCD6DC7F7DFC7ULL, 0x2029F526F7555BF8ULL, 0xE8027B6E39400451ULL, 0x852DDED8E7696235ULL, 
            0x73502EF60D776934ULL, 0x48DCC51A8A927382ULL, 0xD7FF3DCD7790DB03ULL, 0xF7B5A0107A7C861BULL, 
            0xDD5F5385329D0844ULL, 0xC483162C33927570ULL, 0x5F10BA1A02F3F571ULL, 0x42C736E08CF28BFEULL, 
            0x155C2F7B47D1F58BULL, 0xF95F1381590DB8F8ULL, 0x1299801455AC6DDEULL, 0x3FDEE08941071A66ULL
        }
    },
    {
        {
            0xDA47CADCE7903122ULL, 0x0EB5B4BAED754520ULL, 0x181E2421DC17BEBCULL, 0x2C8B6773069C434FULL, 
            0x8D78D8D2E97306D0ULL, 0x4C9DD3B9169EDA0DULL, 0x3AF2F5910C8D7588ULL, 0x94347B0E876526C3ULL, 
            0x3276F48CD80165C0ULL, 0x609118218B1BAC6DULL, 0xD611D285376380AAULL, 0xBE4F73C6198BDC05ULL, 
            0x445EA7C701AC0198ULL, 0x73DC6C249EC8451FULL, 0xF6AF2D4B1540D233ULL, 0x20CF2B109B44A5AFULL, 
            0x4286746FD0ECD1BDULL, 0x4CB8C42659236F72ULL, 0x4F462CEEC8D88043ULL, 0x5A11D8DF9A11C3E3ULL, 
            0xFCC246782E3488E3ULL, 0x114D416C25BA49DCULL, 0xA6AE566CF3D5F029ULL, 0xAAD661D75654C658ULL, 
            0xFEB30C5B40B7F24DULL, 0xB83247947785B877ULL, 0x0FE9A4F393107D28ULL, 0xD37E84DE4CFBF2B3ULL, 
            0xE9DE0ACC3BCE1A34ULL, 0x9FC160616B874AF6ULL, 0x1F66C6238778B724ULL, 0x6C2D303939A564C0ULL
        },
        {
            0x26BB544821AB9C35ULL, 0x1F1466D33A83FAF0ULL, 0x889E90D48E88CEADULL, 0x63AFD2F7A2316E2DULL, 
            0x03C4F394E60273B1ULL, 0xBC2CF09AAA6BB5E9ULL, 0x69213C70387ACA1BULL, 0x991B64EA514A5353ULL, 
            0xE7A7BE0DF70F98A6ULL, 0x4506DDC6AB66B9DBULL, 0x150D10B460131D1EULL, 0x9022C312F38AFBD1ULL, 
            0x979987F0C378A3EEULL, 0x5EEB06909EA4CFB5ULL, 0xD94A7FB0654FE190ULL, 0xE5874E8D80E4B773ULL, 
            0x63D9123E4155A949ULL, 0xF7A2559C98A3D4F0ULL, 0x344AAB8CE5FB5986ULL, 0xD81E1C0441C9349BULL, 
            0x3ECC0B9A2D15CBE4ULL, 0xB11D1798CFBD3746ULL, 0xBF0720C544CF6D1BULL, 0xA57DA6541FE2FED9ULL, 
            0x651CD78B3824147FULL, 0x856684F2652DC4D7ULL, 0x0A766A92EA20085AULL, 0x745395BDC0C905ABULL, 
            0xC9C3063657B54506ULL, 0xE9E9E3FB54B17831ULL, 0x70215AA9EF80B753ULL, 0x7F5FADBC8662531CULL
        },
        {
            0x1E32C184F8EE298FULL, 0xF78AB07022F1FB9BULL, 0x7C8DBAD4355820B9ULL, 0xBECF90D9486A28C5ULL, 
            0x4D3AA9A17BBC4847ULL, 0x240DD49C005FDA62ULL, 0x82D8B1D5B9E855A3ULL, 0x616B62E5B09B8637ULL, 
            0x72991B89E805836BULL, 0x21F366CAB9FE5937ULL, 0x8C6DFA5C9E40FD67ULL, 0x5DA79246D0D0911DULL, 
            0x0E993DAD2AF06551ULL, 0xB91C84DFC521F5AFULL, 0x2D89BFC63DC200C6ULL, 0xBA01B3089C39715DULL, 
            0x5B70BF29CC7540FDULL, 0x0D7CE9F309EDFC9AULL, 0x35E84B4FD13E7672ULL, 0xF0608DCD6113E0C7ULL, 
            0x05CA3948FBDAA9AFULL, 0x6582EC20E5A3BEC0ULL, 0x2D2C9523E3CA657EULL, 0x70CB301D84E1B5F1ULL, 
            0xB503F4A4F3EB484EULL, 0xEF6579E9830522DDULL, 0xFE05EAD9C6320BF4ULL, 0x101726F9B14E6C1EULL, 
            0xCB35D6BC806F241CULL, 0x954194065E0609D3ULL, 0x3849E489FED4A54AULL, 0x9D05776AB2E5EC39ULL
        },
        {
            0x2326B8275710FA74ULL, 0x1C04E381451FA508ULL, 0x8903930F2C0A7279ULL, 0xC3EC2DCB18FB17CCULL, 
            0x7E7CF5F6A1DAE86DULL, 0xAA1994E8F36D3EFAULL, 0x99EDD4C7C9A05BC4ULL, 0x6966F7593BA71215ULL, 
            0x3FC57FE33F736F63ULL, 0xE46DD1C9DB35CB82ULL, 0x50EAAC75833BF735ULL, 0x85ADEA30B7E9C4BDULL, 
            0x1E3AC2DE62CD5E73ULL, 0xA84C827025DEC407ULL, 0x5CBDC9C4A9225201ULL, 0xD7F0DF9481E74EC4ULL, 
            0x05E291B71A7BA848ULL, 0x31D9071870E93327ULL, 0x4F291D8630CA47C1ULL, 0x0F18B7D3C94A3CDCULL, 
            0xEA54E0DF17868140ULL, 0x551E8109CCD245C1ULL, 0x2BB901D49C522CB0ULL, 0xB652755C69AF55C7ULL, 
            0xFB360A058D28E0E5ULL, 0x4E6C253A247F8A07ULL, 0x465A543EDB0E142CULL, 0xEA2CD17FD9B3090AULL, 
            0xE1AA0CB8C8A1C78CULL, 0xE96E25C9D75CACFFULL, 0x5270F35EF105DFB6ULL, 0xC3080F9BB0B89632ULL
        },
        {
            0x23F3EA02AC041062ULL, 0x7C7E7003A06F9C45ULL, 0xAC1D04CD9B7EB5A0ULL, 0x2418E9966D5AEE33ULL, 
            0xB513CE47E5438A19ULL, 0x42A0C1602A515D50ULL, 0x975F2C2DE7FF6370ULL, 0xB1C5E36A3E3FF3A9ULL, 
            0x61BC4B424B7AE86FULL, 0x9410A98A7C8E2BF8ULL, 0xF519B7CEA07EB181ULL, 0x751C0950A7C28251ULL, 
            0xDC625979F52E881AULL, 0x2ED4363428481196ULL, 0xB871C20F0ADA86AEULL, 0xC6A2FE164901E898ULL, 
            0x76656AFFB81541A3ULL, 0x4A3882A15F8EED8CULL, 0x466F4F24D2F7DF1EULL, 0xD94907CDD7E417FFULL, 
            0x4FDE276957220A12ULL, 0x2284E7929DD2D347ULL, 0x3B9D773C1981A030ULL, 0x54B13D420DDC059CULL, 
            0xF6AE08406A9D3087ULL, 0xA13ABD40AA93AAEBULL, 0xB4383CC251E97433ULL, 0x2BD959029C88F1F7ULL, 
            0xFD4711F9B538BCE9ULL, 0x9E79D6783F2B4037ULL, 0x2B0511C48269B89EULL, 0x6386299B3676EA17ULL
        },
        {
            0xE97AE90CA6AD3F58ULL, 0xF989F6F3819123E3ULL, 0xCD9E7778E528D668ULL, 0x1CD587C391D90147ULL, 
            0x34C73CE10ADDE845ULL, 0x16AFD300D6F49762ULL, 0x816DCB57971987FBULL, 0x09E2C300230E01EAULL, 
            0xAE5A970E55B45124ULL, 0x19B001F77B7D0596ULL, 0x5DBD3C961DF21F7EULL, 0x26DA65BFBF5C8618ULL, 
            0x981C41FF35C9E7E5ULL, 0x6116B3A609225810ULL, 0x423BD59257F05648ULL, 0xD86B41B47F5BF1D9ULL, 
            0xF3BF3A8D25A45DBEULL, 0xB2E21D963F995B26ULL, 0x451AE0433D05D41AULL, 0x35D1170A1143B071ULL, 
            0xFD73B971813C40CCULL, 0x26AA8AC09D3E052BULL, 0xA5FF44AB12B670E0ULL, 0xF998E12D5409C4F8ULL, 
            0x9096C34F5B24FBAAULL, 0x0063EA50AE8A2211ULL, 0xBC2F6E680024619BULL, 0x986E283E63F084E7ULL, 
            0x552D5B19CCC9A9CAULL, 0xA92146C0B5DC2B95ULL, 0xDB6908E7093D9729ULL, 0x013ABD923E4BA47CULL
        }
    },
    {
        {
            0x7048670EB82397B1ULL, 0xC8899E3EB5A911FDULL, 0x786356FC324C3F0CULL, 0x27CC6B9C4B3C872AULL, 
            0x6E6E4450A9FF07CDULL, 0x9F37234987A3D8C9ULL, 0x471B2904F993B42EULL, 0xC57BD1744829DF1BULL, 
            0x47B96704452A1145ULL, 0x3D570D3AB31012E9ULL, 0x2530B3B88496732BULL, 0xEAF075A9A99BD903ULL, 
            0x8CE9F0D02B0EF433ULL, 0x225F3903C3E60336ULL, 0x9FAA207D7CDD50B1ULL, 0xF68280FA2078DFB0ULL, 
            0xE255C2D62D64B2BDULL, 0x62FF1A03DD4F4EC7ULL, 0xB070BCC5F57AEC29ULL, 0x43301B143AC427A4ULL, 
            0xBBC4A56155527640ULL, 0xF618EECAC80C73D1ULL, 0xDF96ECFDB6FFE3CBULL, 0x67F5A2E59CB83BBEULL, 
            0x0D83F335B46AF1A5ULL, 0x7F2F0267A6A8EDDCULL, 0xF3A2C701EAC54572ULL, 0xB1641A37378C2DAFULL, 
            0x0DDD09964683736DULL, 0xA77721D704C3DC16ULL, 0xC89532E9A71DC365ULL, 0x5C1D9F42CF63BB6CULL
        },
        {
            0xE8819F198278DA63ULL, 0xA6A1621468C8BC7CULL, 0x772EEACA7CFF06F9ULL, 0xEE0DF27444F6C5A9ULL, 
            0x10988F975F43033AULL, 0x9E73FBF36173DE89ULL, 0x8DE269992E1C37F4ULL, 0x608DB2ABF2E51D04ULL, 
            0x4958172C1228E74FULL, 0x2BA0E7B5408963DCULL, 0x1B268F1C07A37E53ULL, 0xFA95C6B9A5D5A61AULL, 
            0x9133380E6D50ADB6ULL, 0x6E75E8085569E89FULL, 0xBB6650913958C0DFULL, 0x78640D2F807CCF63ULL, 
            0x8C0299A5414EF8F4ULL, 0x53B183D87228EDA9ULL, 0x4144B5E9D1878F4AULL, 0xFB903819A2169489ULL, 
            0x204F9E77ECD9DC05ULL, 0x0858A869704EE0BBULL, 0x14B06B65F3248905ULL, 0x7134668930A7CDFDULL, 
            0x9769DF3C45CD641DULL, 0xA322090E506EB947ULL, 0xBC92DAD908A89CBAULL, 0x7CD717367BC9449FULL, 
            0x6B355B67B5D5A817ULL, 0xB01C7F3E85244CA9ULL, 0x745518B645CA17C6ULL, 0xC733328B0A1871D6ULL
        },
        {
            0xB9293B83311187DCULL, 0xFFBBBB9D708B69C8ULL, 0x50FEB0AEC6824744ULL, 0x9683EBE4EBC38B7FULL, 
            0x09258382523F2412ULL, 0x28AE5E2927346893ULL, 0xF1095F15F03854E7ULL, 0xE00DDF710DCE30F3ULL, 
            0xCA860C8016E4AAE0ULL, 0x56203A4B2439FEF6ULL, 0xD4F76BF9F1F9FBC5ULL, 0x087AE6A739E6FC0EULL, 
            0x3174345A5B0E7140ULL, 0x9AF50E27BA863B3CULL, 0x3965F1AE2FF9AF06ULL, 0xABC50D40FCB1739BULL, 
            0xF808E6511D24E5DBULL, 0x0006127F4070232CULL, 0x06D28CA59FDBF3D5ULL, 0xC771D5FB92C63A96ULL, 
            0x9368E5426FD09C95ULL, 0x19923C600FF0638DULL, 0x9CA014376529152AULL, 0x58E824BF8B1DDADDULL, 
            0xF189814C22757D3AULL, 0x31DDE3ED1F711551ULL, 0x611BF1E15ACB0FBAULL, 0x4B48DB5A0675EAFDULL, 
            0xB9963D7062C41716ULL, 0x607416D34C0DE9E6ULL, 0x5594E0F721659C13ULL, 0x9BDAA6428055BE6AULL
        },
        {
            0xA8B0D9C5B5333D22ULL, 0xE7612513D7894988ULL, 0xBA19E22AD59E9B4AULL, 0xF10A29854AD7B9D1ULL, 
            0xB0386BC7E79E7490ULL, 0x67B635B55B94401CULL, 0x34CA5AC9BD40F31FULL, 0xB8ADD403331FCBBEULL, 
            0x53C9AB43C6FE71AAULL, 0x56285423823C542DULL, 0xE6566FB2C6D89D50ULL, 0x8C6BA813D188E2DDULL, 
            0xDCFF81329B3AE505ULL, 0xA465A26E7F43574BULL, 0x9B19FB17B075D1D9ULL, 0x06EE235E7E801282ULL, 
            0x97A5EE1AC729EA6DULL, 0xAD8EC17B8DC55393ULL, 0x618637AEFB77D1B3ULL, 0xC575C4610B1C11F8ULL, 
            0x7EA07ED1E21A9F6BULL, 0x3F6A136C692A6973ULL, 0xAE16B7B74F81DDC7ULL, 0xE249769F9BE2572BULL, 
            0xF507BC60AC55F38EULL, 0xBC89A78232BD8A2EULL, 0xA9C561DAD131F0DBULL, 0xA31DD39EC9A0E97CULL, 
            0xF0C5425A689B3E2BULL, 0xD61BFCA5591FDBD6ULL, 0xEE6ABEFC25B8DC05ULL, 0x13EC147D8CBAA571ULL
        },
        {
            0x37CC777283F397AAULL, 0xFD1C0E207D55CA0FULL, 0x5BD4BBD31C3E6040ULL, 0x6819B009DD64D680ULL, 
            0xBAC636E0C7296632ULL, 0xD0FE570FBDA316C4ULL, 0xA5B163ACA9275E3DULL, 0x196855E49EFFBE1DULL, 
            0xB1447179DC905E5CULL, 0xC14048D9D480C717ULL, 0xD29642D0B8AC6D44ULL, 0x3384C7FAD0FF0562ULL, 
            0x53DCEB3AF7C8C5D7ULL, 0x31FCCC82733D27C0ULL, 0x7B45D83B66BAD59AULL, 0xA2D6A58663367DB3ULL, 
            0x989CE25B0DD9F8EDULL, 0xA13D38E3DBA7E573ULL, 0xCD41CD31EC5422BCULL, 0x75CC5B7094F3B63BULL, 
            0x4D10D7B72C910F5AULL, 0xF813956BC6DAFAA1ULL, 0x96808ADDEB5FDDE1ULL, 0x6C4A01E04B65BDD8ULL, 
            0xE7D1A86085AD5964ULL, 0x8D224C6B172477A1ULL, 0x190AC28FB2A994CFULL, 0x0E273229E4F71F9EULL, 
            0x6C09CAFD825CA8AEULL, 0x9D890EC2C5BAFD55ULL, 0x8E5B89B90A504DE7ULL, 0xEE4768AA0296DC2AULL
        },
        {
            0xA2C18A37FDE84637ULL, 0x38992B5336CD8174ULL, 0xD808E4841C053923ULL, 0xF8B6B828D0CDB523ULL, 
            0x99A9D01AEEA86065ULL, 0x78B75791133ABCD3ULL, 0x52A741E3AE79FCFEULL, 0x2A912BD8FB04A0E2ULL, 
            0xF6CDC40BC3810C9AULL, 0xD8FCACAAB6F7F27AULL, 0xE23FFF40EF7D39C4ULL, 0xD6BB6E79706CC97CULL, 
            0xFCE3AEEB8E0DFF3DULL, 0x41F5280D71BCF496ULL, 0xB8F9A43B7AD39E74ULL, 0x1D3C82CCBECCD9DEULL, 
            0x815DDB56E4B7B096ULL, 0x2A2D9DEB14055A5EULL, 0x54A9376F62D396D0ULL, 0xB1E985B18849A3EDULL, 
            0x06E0570DF5B75625ULL, 0xEFAA0220EE80AC2AULL, 0x3AB7F52680D8BA4AULL, 0x8EFAE6E8E38E195BULL, 
            0xAB2C63F2B197E5A6ULL, 0xCD85D9223B6A41FBULL, 0xE818CCA67B4680D5ULL, 0x951F094E7E1B31DDULL, 
            0xAEACEE487C9B62F2ULL, 0xF7A3AD536F745873ULL, 0x900BD29959DEF978ULL, 0xD3779FF3D92BBDAFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseBConstants = {
    0x0A431C50C1FAD42CULL,
    0x898AE63651477BFFULL,
    0xB8027CD6A358155BULL,
    0x0A431C50C1FAD42CULL,
    0x898AE63651477BFFULL,
    0xB8027CD6A358155BULL,
    0x79E061338035BA5FULL,
    0xDFF88963A509C202ULL,
    0x9F,
    0xA2,
    0x52,
    0x8F,
    0x89,
    0xB0,
    0x40,
    0x4B
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseCSalts = {
    {
        {
            0x637EBD80DB4665E4ULL, 0xB1B6B636114F5344ULL, 0x0EE70EDC41699CDAULL, 0xB8BAEFBDF0C055CFULL, 
            0xA89F0697A2672C2FULL, 0x7AED1E64FE730E3BULL, 0x7527CEAA4D9642BEULL, 0xCD6CE688F8F84747ULL, 
            0xBEFEDC2B5BB05847ULL, 0x4895E51C57106FF0ULL, 0x4046337BD8D7C317ULL, 0xD0716D050100AA0CULL, 
            0xBD822D40B4E70BD7ULL, 0xA03AE11447972630ULL, 0x2C8DB7A86A35F8E0ULL, 0x987447DF6D1CD69EULL, 
            0x16DAF934EBAAF92DULL, 0xCBA6CE3153CCA0DCULL, 0x6EC2313F07DD66C2ULL, 0x2BC5D5E82CACE30DULL, 
            0x2C2FE8682AAA4E65ULL, 0x5755264F15900D76ULL, 0xFC854B9D47E69C40ULL, 0x0BB85B45118FE6AEULL, 
            0x9D77BA76180FD681ULL, 0x5A86711A6212DF07ULL, 0xF0742684D4A5A4F1ULL, 0xE49A10D1C238B235ULL, 
            0xDB2BDC00583193F1ULL, 0x80AC788CE15FDA1FULL, 0x923115B6F219F9A2ULL, 0xE05D3DA9332FFD9FULL
        },
        {
            0xAF65C7B1BE10CCF1ULL, 0xE79B477C073EFC93ULL, 0x9A4FBB6467647201ULL, 0xD9DC8A3D7070817DULL, 
            0x424DA4EB0FBF9615ULL, 0x96B6012B4C53D492ULL, 0x7CE2AFB579407363ULL, 0x6BBDCFDCDA5AE707ULL, 
            0xF5B58B2BBC7251A6ULL, 0xA1FE4987398B3646ULL, 0x3620AD704B8FF388ULL, 0xDA36751C603EB2A9ULL, 
            0x37AD05160E525F13ULL, 0x32658704FD5093FBULL, 0x22802C0D29634A85ULL, 0xCBADC921A406028FULL, 
            0xB05AA38E11E90B71ULL, 0xB346749980D3797AULL, 0x5E2EECB62A41E855ULL, 0x8DED19C79769577CULL, 
            0x3AEDE86B1808CF68ULL, 0x58D558C2C7005CA6ULL, 0x99689E585B8222A1ULL, 0xB6B488C33BF91269ULL, 
            0x6A9013337DAE21E5ULL, 0xEB8F5F0389B1BB9BULL, 0xA40DAC637D49B275ULL, 0x5DAD5FEA14C28F07ULL, 
            0x8D188D1A99CCF6B6ULL, 0x0D831FE881F881D7ULL, 0x6E9A74AEFE540835ULL, 0xAE285BED65F0DF54ULL
        },
        {
            0xCE467C89BC7C3FCBULL, 0xD621FB4297B8125CULL, 0xC146D3D124EB9EC6ULL, 0xB5EB62FFD15123E2ULL, 
            0xAF506600D0651A12ULL, 0xC7CBB44EC9779BA3ULL, 0xD39BB42C002CCF4AULL, 0xD120243E105E8BB6ULL, 
            0xEBAEDD44E6E7ED3DULL, 0x7A78A4578EE5A741ULL, 0xAD7C8E6C8A55CC39ULL, 0x12C82406CB9F1660ULL, 
            0x789C691A5675DD31ULL, 0x002E5458B288218AULL, 0xA69A937343AE1BDCULL, 0x20C858611BAA1E3CULL, 
            0xD746E12DFB99DAA1ULL, 0xA67BA946CE6895AEULL, 0x4523AA9A6E439F58ULL, 0x345FAC0906DA10D2ULL, 
            0x61D50D5A588AD415ULL, 0x79FFA0648ECAFD0EULL, 0x90AC5FFAC8592640ULL, 0xF69300FB267A152BULL, 
            0x6A498C11BF5A3993ULL, 0xDFA3B0FA224AA213ULL, 0xE9CFD4D5D73303C3ULL, 0x9338E4445576C28BULL, 
            0xEFE3351402C76362ULL, 0x8F18182FD12D6FE7ULL, 0x3B097B51FC9DC5B4ULL, 0x211834E9B5F83437ULL
        },
        {
            0x1BA71A8AD6FB990BULL, 0xA57E83E6CB6B4D1EULL, 0x38364660C1C47CD5ULL, 0x758414843B06FF71ULL, 
            0x354C8CB6AAD72CFDULL, 0x5A4FE7D2EAC99895ULL, 0x5EBC52A61315FBC2ULL, 0x75FFB07C6CB461F6ULL, 
            0xA3E8A0AE976F812EULL, 0xDCC40D705478A1C2ULL, 0x3260A87375D7DF82ULL, 0x206634C8F36807FFULL, 
            0x7BA6EC284B7BA0D9ULL, 0x57E66C5B16C7A74CULL, 0x7753F12B9E477979ULL, 0xFCCF32BCFCDD8416ULL, 
            0x6C42927AAA978B4DULL, 0x058B45C9642BEC9EULL, 0x37679844886F9F9FULL, 0xB993A786A7C0A2BFULL, 
            0x2AA9CC9DF27C9AB1ULL, 0x87522297AA90C2F0ULL, 0x41ED60830E23C04FULL, 0xFE3EEFC9AE5B6E30ULL, 
            0x762E9867D22D957BULL, 0xCE852C369E60F62CULL, 0x78B4DDA1B719E822ULL, 0xF70D0237B1971F1FULL, 
            0x211025854B1BD77EULL, 0x524A6F0528512C2EULL, 0x1034596D136C76C8ULL, 0x8F2A60315694EBC0ULL
        },
        {
            0x30E93F322355E931ULL, 0xD81EF9BC2A4633FDULL, 0x3E052F8B1A35CD3CULL, 0x3B642D08064F5BFAULL, 
            0x2B9E9355BDBC8A2FULL, 0x98ACE8767C576BA3ULL, 0xFC039F9C4958CCF3ULL, 0xCABAEE925F362B88ULL, 
            0xAF14AA5419847070ULL, 0x2116D3B334AA6EC9ULL, 0xCF5928A413C4F66FULL, 0xD245C89D9A3C0C6FULL, 
            0x5AE8B0660AEAD332ULL, 0x419306EDED281427ULL, 0x6199F8E91101E40EULL, 0xD12FF858C3560E09ULL, 
            0x3F42C58A6EB7D6C1ULL, 0x2745785EFD10620FULL, 0xEB7BE1393EB65B72ULL, 0x93941401F24E5EDDULL, 
            0xA823AA7CA69349C7ULL, 0xB6FF2C7BD891F11CULL, 0x16FD9ABF629D3402ULL, 0x6E24430441A37BDEULL, 
            0x7FABEF9BEBCD1D3BULL, 0x25DCC1682252D24BULL, 0x0DC133AEB9C117BEULL, 0xBBA7D44C648376D2ULL, 
            0x277224B00B771CB9ULL, 0x5B13BA0C1C47B127ULL, 0x1E1853D274863319ULL, 0xC3DCE02F818258E2ULL
        },
        {
            0xC003C3E97C25B910ULL, 0x3B72E27310067D3BULL, 0xFF50343A5139D8ACULL, 0xF59A59ED6E4DCCDCULL, 
            0xFDBB0E90E2ECA281ULL, 0xEF5310F388EA6671ULL, 0x5BCEBFD96C93AAC6ULL, 0xBF40E3E425317E16ULL, 
            0x67F425FAA6AE36C5ULL, 0x39D522A207589860ULL, 0xF219A2DAF26B3058ULL, 0x4C94FE6F085CF874ULL, 
            0xD9758AE98FAD536FULL, 0x725C7DFA6C568293ULL, 0x93E6643D24214D89ULL, 0x59B7A9FAE157829AULL, 
            0x977B7A91786A576FULL, 0x29034D1F09957C79ULL, 0xD49C8B71CA057561ULL, 0xC0241C1A9B777141ULL, 
            0x4A3CC1A9F88E40FFULL, 0x61BAD3B3B61A2A48ULL, 0xCAA65F2CD7646F27ULL, 0x271AC22247FBE46CULL, 
            0xE78886A3AEC20D26ULL, 0x76DE74CD28B2DFB4ULL, 0xA05BDEBA1391F227ULL, 0x6634945CB0A42EB4ULL, 
            0xE106C6422042AC8AULL, 0xBA56CDC091B3F943ULL, 0xBBD63D626012FC6CULL, 0xA46954E45B7E26DFULL
        }
    },
    {
        {
            0xE7B9380876A07C17ULL, 0x2177E3798BB5D532ULL, 0xA04820D5121D6FA4ULL, 0xB3668AAF68F4241AULL, 
            0xA3289C7346C6232EULL, 0xD2C30400FE78D256ULL, 0xA6008FB56962DFD4ULL, 0x39941CD14FA4F297ULL, 
            0x905205ED5D00C859ULL, 0xC3CC5761B0B8C1A2ULL, 0xB8648E1C0F6290CBULL, 0x25CF38522E00333AULL, 
            0xE5820C6CC3FCA4F6ULL, 0x202FFF20FDA45F8AULL, 0x06C29432A4000CF3ULL, 0xBE4120609FD2A1E5ULL, 
            0x4F9F0B0EC6B323B6ULL, 0x929B24ADCF826FC9ULL, 0xD95999269B1AEDC0ULL, 0x73520A18CF68932AULL, 
            0x664AAAF0A3D68B1FULL, 0xE76FD5D13A0F016EULL, 0x724F32E273D4BED3ULL, 0xB627E43A31CFA8F4ULL, 
            0xD9E6BDB82E6E5D04ULL, 0xAC2C37D8D84AFDF1ULL, 0xA12997BB40D2498DULL, 0x1FF5E27D3ADF2350ULL, 
            0x3AE0E886CEB13831ULL, 0x4334C611DABF2413ULL, 0x95B09DD2C9AA7A6BULL, 0x5B3D77F905DC8D32ULL
        },
        {
            0x4D65842F50FEF84FULL, 0x21F8091EEC52390BULL, 0xF61F4411F299611AULL, 0x9432C8A586C406F1ULL, 
            0x36A620D8092E8AA7ULL, 0x7F7AEEC159939593ULL, 0x2B1D2435425D8264ULL, 0x591EA1733C3072A4ULL, 
            0x06114C341E235DDBULL, 0xDA18925B7F15BF67ULL, 0x816BA73687A43250ULL, 0x9BA2D4F3AF14886AULL, 
            0xDFF07A96A30C025AULL, 0x59E2CBDD6BF6519AULL, 0x19E19AAC34175BCCULL, 0x0B4601D9F8AD7C14ULL, 
            0xE4FAF8CECDA44D4CULL, 0x41ABF00BBF172D9CULL, 0xF8657F3F95F86915ULL, 0x1F39CD50148AB079ULL, 
            0xF9673E43DDD08425ULL, 0x6AFA665D59C5F460ULL, 0xB1D7570A6738405BULL, 0xA7DB79DF63469DA1ULL, 
            0x0B37BE988E2AFC74ULL, 0x387DBBDF8969E443ULL, 0x445FC75DFAED129DULL, 0x6AB411B96C01364BULL, 
            0xF110321DDCF4B585ULL, 0x4D2DEF875458023BULL, 0x0D8438FE34649BF8ULL, 0x2CF0C124E26A5C38ULL
        },
        {
            0x6272F9A0C2CB571BULL, 0x3F248BC18A497632ULL, 0x85FBB058472CE257ULL, 0x8C041C018849BE86ULL, 
            0x598D881CC289DC34ULL, 0x20E5963BE191E40AULL, 0x1682EEC004C1FA7EULL, 0xE8DDBE80B7E61E66ULL, 
            0xAA19BFA8D0EFB1C4ULL, 0xF8A3563D76757E58ULL, 0x8EA2D5C899821ACEULL, 0x583FF6D234CA268EULL, 
            0x1CEE474CE7513A20ULL, 0xFB320CCC7A82C0C2ULL, 0xBE8819C341AD631FULL, 0xECFC20069EBED801ULL, 
            0x55B12E8BC5EA7579ULL, 0xDC23EE209E8101EEULL, 0x2DC4FE04730D90A2ULL, 0x2D7CCA430505AED0ULL, 
            0x23EB21A9F9C34CBEULL, 0x73C9E0E01CFAC284ULL, 0xF948EEBF1DE07BA5ULL, 0xA31C54FD37738C9BULL, 
            0x1C8DE555FCBF0B9FULL, 0x07799C8DD81A68EAULL, 0xB1CCA6E42C8AA8D7ULL, 0x505D57150A699AB6ULL, 
            0x2681F780D8374490ULL, 0xAE0683E489CA5662ULL, 0x9E072CDEB7018246ULL, 0x823157855E9E870DULL
        },
        {
            0x7D1D2506385FF1CEULL, 0x8003F08D87BBEA55ULL, 0xB3DBAD96B7F28C55ULL, 0xCECB768A3EB5F593ULL, 
            0xF04371120F1DF8B8ULL, 0x4111C6DFB9172C2DULL, 0xA3BB83DFCA758D72ULL, 0x6FA59FF58399EBFCULL, 
            0x4092EBDA6CE419E0ULL, 0x84389BC2AD28F06DULL, 0x17491F53359E674FULL, 0x80D429EDE00D68F3ULL, 
            0xB4DD0860426A1E69ULL, 0x7B73AE1C1F73A57CULL, 0x1838C0FF256D05FCULL, 0x6D56EAB138C879D3ULL, 
            0x1D58D93CF11A647EULL, 0xFEFCEA37CE2E9EA7ULL, 0x9BAC76DF51F4D3CFULL, 0x0F5DE616F6CAB1E2ULL, 
            0x45C5C4DD0BDA199FULL, 0x35E6EB74AE48D850ULL, 0xD0CD658709EC0B57ULL, 0xDD9F66174C5D4D64ULL, 
            0x49D796348E2B47C2ULL, 0x0DA58A68C66FE90BULL, 0x8E338A862835B62BULL, 0xB77D22301208D957ULL, 
            0x52AF2A44FE297596ULL, 0xDB5787220FA84BD6ULL, 0x96482E00A2689439ULL, 0x8D3507CD0973D53CULL
        },
        {
            0x0B5B9E217A1F49B0ULL, 0x3C9E1A6BCB416034ULL, 0xA6225A9814FB34BFULL, 0x425F025DC737CC11ULL, 
            0xC6B8BB0CAA666799ULL, 0xE133809982D5EE03ULL, 0x0790C98FE3EE8944ULL, 0x34826EA9F0831E52ULL, 
            0x3E41BADADEA9BDE8ULL, 0x79542CFFFF5EA8F5ULL, 0xA3D177C722B2F2B1ULL, 0x56E12B553044F8E3ULL, 
            0x6BA79EE3025FF492ULL, 0xF1CB876F4D231C95ULL, 0x6A1BBA21EF53033DULL, 0x25177337D5234266ULL, 
            0x2E47B7B404F37D47ULL, 0xF96A8C8648DDAD60ULL, 0x0D869BEA58C5EF26ULL, 0x3BC569CE12BCB1B6ULL, 
            0x512F6CB1D794A8F9ULL, 0xC4D3C8108E3E951AULL, 0x3D12B430E55E4E48ULL, 0x48A28376128FEA31ULL, 
            0xCD360115C686B9ABULL, 0x3E7B7AA8C602E540ULL, 0x1E3207644C42B1D4ULL, 0x6C747B8F65CDD14BULL, 
            0xC60B9DA404162577ULL, 0x2A89293AA3AB4208ULL, 0xE63C4B4BE97BC51CULL, 0x48C3AC04E94E8026ULL
        },
        {
            0x2802E1B6A6C71643ULL, 0xA20F0FF6EA5A866DULL, 0x954F44FB7E639025ULL, 0x6E2F46E240CC5466ULL, 
            0x0992EFC4593EC660ULL, 0x2918F79D78DA48B8ULL, 0x7306451E41BB04FCULL, 0x1CBEB95DAF8D6E61ULL, 
            0x223E0DD9F766FAA8ULL, 0xCBDC1CE888626BC8ULL, 0x05EF644BD2ED3E9DULL, 0xA8EBE9E16AC71EB5ULL, 
            0x397B825B30EBE6C2ULL, 0xA019BDC8131E68CFULL, 0x1A105B1F8577BCF7ULL, 0xF7D94E6CE4A98795ULL, 
            0xBB9233D7D21677CBULL, 0x1610B30BA8B0B88FULL, 0xB299588AF303BC77ULL, 0x508CECFAD630CFC8ULL, 
            0xE8E162B17A02D238ULL, 0xAD07B6CBD20946B3ULL, 0x19A8C4D40F19B441ULL, 0x4D8B9DCF09D8E2CFULL, 
            0xE28B707270FB5AD0ULL, 0x8C0F4BA2A157A1CBULL, 0x19AB4FADABB610BEULL, 0x48728CD9EE1A92F2ULL, 
            0x2DEF66282408FC51ULL, 0xBD80AE082E059E41ULL, 0xD0BFC768F6AE40CAULL, 0x774B6BD58983B505ULL
        }
    },
    {
        {
            0xC199E1C9FD2E0672ULL, 0x383C6422A29905BBULL, 0x58D4D68D17AF1952ULL, 0xEDB0C59BB4A4527EULL, 
            0x042F1EF2532FE55CULL, 0xEE5ACB8FDE78A51AULL, 0x794170D937F249A6ULL, 0xCA9425971C83C43CULL, 
            0x6302FEA50A7C50F8ULL, 0xCF338CD70106E133ULL, 0xEE58F20EB85D6AF5ULL, 0x1A8D050FFB15F6E1ULL, 
            0x8AC93F4F82CAEEAFULL, 0x222337E632A2C68EULL, 0x3D50785413D55B11ULL, 0xA1AACCCE36D21E86ULL, 
            0xCE11567BE6D6F3C0ULL, 0x94BCEA20C3AB15B1ULL, 0x5A15D4CC62AB927EULL, 0x20DBDB07F48BC49FULL, 
            0xBE98CD2E5DCD7778ULL, 0xC0CBCE67AD675DEBULL, 0xF024F423DC5E9641ULL, 0x06E6DF7C37F98F9DULL, 
            0x1D867DE675E10242ULL, 0x41AB6D07EE818328ULL, 0x6B4B65842DBFD67DULL, 0x4C604773B7D6B1AAULL, 
            0x4B198E4E08888E88ULL, 0xED8465001F7D987CULL, 0x82FBE883E0107350ULL, 0x0955396432778DFDULL
        },
        {
            0x36B0ED0D5CDB2F95ULL, 0xF70F61F0BA55C0E7ULL, 0x472FB34C44463C78ULL, 0x7594DB7F73825523ULL, 
            0x8AEC570EB1A6F94AULL, 0x6D64BE8A341D2227ULL, 0x480A7F27E6734E36ULL, 0x7D68A3D503A589D5ULL, 
            0xB5CEF5734A99F1E6ULL, 0xD98B4D588044B478ULL, 0x9C47987E4B33E110ULL, 0x7050E141ED9575E7ULL, 
            0x25C510D402E370FEULL, 0x0A748FAEB0227767ULL, 0x6C46985C99A7A299ULL, 0x3112A3DDE8257EDEULL, 
            0x1958D58054B174CFULL, 0xD2CAAAA081B3110DULL, 0xEB8636B450E50399ULL, 0x55E82015E925FCFBULL, 
            0x57C1A80B77F3AE6EULL, 0xC97ED0754BE75F67ULL, 0x6ADAAF5A8F8CC23CULL, 0x8C174DBD64D88F5AULL, 
            0xA54844EAC0F72658ULL, 0x0A2416F814C31D38ULL, 0x3F6E358E1A97C9B0ULL, 0x1C9B7DB945EB271AULL, 
            0x0DBF5694949B8FB0ULL, 0x58D8A58CA53A3DACULL, 0x4824E7FA04F8BDD3ULL, 0x4F95E8A405FD6D0BULL
        },
        {
            0x7FB3A73DEFF97EECULL, 0x1D2BD3DB034F1A0BULL, 0xB596215DE5A4BEC0ULL, 0xA44EB70F41C64130ULL, 
            0x47A711F06358EFCAULL, 0xF67E445348830FE7ULL, 0x93FA80EAF43378F1ULL, 0xA3180F83913A827BULL, 
            0x7826EE09FBDADDCEULL, 0x6832E56255339ED6ULL, 0xA6B5B3295AFD82DDULL, 0x571ABE4F02622A63ULL, 
            0x32D09C933A5235F1ULL, 0xAC00D669DF9A09A9ULL, 0x7ACC1644B0416D82ULL, 0xC076A7635C911316ULL, 
            0x8AD1B6779F37B33FULL, 0x4785EE852C8A7236ULL, 0x02EF3E729E33EC21ULL, 0x496D5470EEA38780ULL, 
            0xC4419CAE571DC85DULL, 0x877C4350D0A9C121ULL, 0x02A0F76EE460E1D5ULL, 0xBD89B2F8BC56D811ULL, 
            0x557F81D67D392E94ULL, 0x6838D8D0FB28577DULL, 0xCCF7457FF56717CCULL, 0x41F67D06510E65AEULL, 
            0x42A7E0E3B97D35E9ULL, 0x5E6834FA95D4CF86ULL, 0x8BCACEEC4AB39C00ULL, 0x67114A1DD3081263ULL
        },
        {
            0xF383305B2D78F894ULL, 0x4E60E0A7A0AEB116ULL, 0xEDB32EEF46D8FC6BULL, 0x9DD075414E73F52FULL, 
            0xD27659C1BEA7405CULL, 0x72FAEB9F91F3B77DULL, 0xBE89F417D087C87AULL, 0xCE85A3C12ABDAD8DULL, 
            0x0395C1F4154A9BF5ULL, 0x49B961B570E16849ULL, 0x94102EB8617828BCULL, 0x1E1048E7292130CEULL, 
            0xBA0C20DADE7ABDC1ULL, 0x51E4941204E618C0ULL, 0x50EFD4517B1B1CA0ULL, 0xADE7159348178FF2ULL, 
            0x78918B3859A85749ULL, 0x25E9201917EAADFEULL, 0x3AA46B5CD4A3CF58ULL, 0x0C983BDE10A61369ULL, 
            0xB14DC49F857F6425ULL, 0x086711A7ADD3AC42ULL, 0x4CD049D3CC54A7C0ULL, 0x1C2C602C872F879CULL, 
            0xBF8CE03156609677ULL, 0x850742C04ECF539AULL, 0x2EC5E2EB36BC1C21ULL, 0x4E7746AF96490B54ULL, 
            0xD54C81192F3849DAULL, 0xEC4E4D5C871E5096ULL, 0x64DC5761E12362A5ULL, 0xFABFCCE2296ED28EULL
        },
        {
            0xFF4AC316EC574985ULL, 0xC7BB5A1ECB4245FEULL, 0x6AEF7465C2409911ULL, 0x13D66840A026D352ULL, 
            0xB4C66101C124FEDFULL, 0x85C31C6138E06E1CULL, 0x200A6B2930AD6FC4ULL, 0x8B987180FA943C54ULL, 
            0x422F88384E06A396ULL, 0xB6480B2FE22E294DULL, 0x7CA7E5C1F5830880ULL, 0xEC48A432A3AF8D82ULL, 
            0x00BD90BE13EC9B00ULL, 0x7D9AE17992DEA7DEULL, 0x7E0CA77E42D3E426ULL, 0x8A70A5B1CF0428B6ULL, 
            0x37D34B4291310CFBULL, 0xA3BFCB1DB789C753ULL, 0xC74C3BE50B46C7C0ULL, 0x0B17ACE28B7F384CULL, 
            0x357F78DA553C7D91ULL, 0x1BDC85768F974811ULL, 0x85B7E96DC8E9FF74ULL, 0xBFA5D7F11B4ABC59ULL, 
            0x7B13060A86081C7DULL, 0xD03DE76CCB882E64ULL, 0x9F9B73B4D33DB8EAULL, 0x0213D7442BAB321BULL, 
            0x098B647988FA9863ULL, 0x5DD516F9F3306867ULL, 0x23A1103187050139ULL, 0xE470FBA35CBE46DCULL
        },
        {
            0x9690EE1918C2E403ULL, 0x538050CAEE6E0ED0ULL, 0x3EC0EFA02E048752ULL, 0x5126A084EE6E24E0ULL, 
            0x8A938060EB30D9B2ULL, 0xE019039B2226A29BULL, 0xC9866FE7AF110F54ULL, 0xCE0562FC61213EE4ULL, 
            0x5F635132964668E6ULL, 0x370AF0B95423393FULL, 0x3A41B229B06B5775ULL, 0xF0B413AACDBA202AULL, 
            0xC8990A7047F35A0CULL, 0x72F94595740B463EULL, 0x374493CB1F2A0EC9ULL, 0x7192BB4D9053F757ULL, 
            0xDA7CBA37C41BB0C4ULL, 0x7E762A05724C442BULL, 0x93699F573A5A524BULL, 0x65D6874711034A2AULL, 
            0x82A34BB0CB3D60CDULL, 0xFB7947EA97836065ULL, 0x7A656470FDDAEBC5ULL, 0xDCE66975FA5D18E9ULL, 
            0x5ADA3D226DAC70E3ULL, 0x7C7FFDB04530C0FCULL, 0x565239C50FF8B0D2ULL, 0x221856610A4CDBC6ULL, 
            0x1223CF8009E54286ULL, 0xB2C25965AEC93029ULL, 0x9D8D07FFE733E241ULL, 0xE23AD7A17521D0D6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseCConstants = {
    0x848A95B2011EFC42ULL,
    0x66FCBC5A41FF2C90ULL,
    0x7764E60564220AA8ULL,
    0x848A95B2011EFC42ULL,
    0x66FCBC5A41FF2C90ULL,
    0x7764E60564220AA8ULL,
    0x903476EA376E0B88ULL,
    0x601AB6114527C4BCULL,
    0xA9,
    0x4E,
    0xD1,
    0x78,
    0x85,
    0x41,
    0xE3,
    0x36
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseDSalts = {
    {
        {
            0x97EB897E22439A16ULL, 0x2D334A9FE9A8C6CEULL, 0x91B180996CB6532EULL, 0x744467C7091147A4ULL, 
            0x5614EFECF32C0D01ULL, 0x127662C1FB852CCAULL, 0x8D0C205028B92D59ULL, 0xBB3F2625D47BDBB8ULL, 
            0x1A2B6E85D8A25803ULL, 0x80EE820B86FFE913ULL, 0x1F13447543B9AD0BULL, 0x75B0784D356920D1ULL, 
            0x71CF5E75B08C6C86ULL, 0x0F5336FB583958E7ULL, 0x8E49884E71DFB721ULL, 0x544FEFD66D7DF87CULL, 
            0x16FDBAF564898FF0ULL, 0xA27016B8168346AAULL, 0xD83A2506D9C54A73ULL, 0xCB893597A2A14D70ULL, 
            0xDBBBB446AD3C34CCULL, 0x8DAF4DF62142026CULL, 0xAA045C50699CFF5EULL, 0x245A3D54DECCA2EEULL, 
            0xC42422324C90A143ULL, 0x15924235AFB18E22ULL, 0x0D26DEE2DFBE6D6CULL, 0xA62D6CAB42F794C3ULL, 
            0xF6545A7CA3B7FC5CULL, 0xEE3E65DB7A529527ULL, 0xE295F553BC873017ULL, 0x6C63AE26FBDCD6DAULL
        },
        {
            0x14AC160E10E2DD43ULL, 0x6643FF331EB9593EULL, 0x1BD117DF6C261934ULL, 0xADB106A97FE853B9ULL, 
            0x4B3E1E5AB5F199D5ULL, 0xB0C3E0DEF281B2B1ULL, 0x0E15D7E1CB30CF63ULL, 0xB94BB65DAD8459CFULL, 
            0xF1EFB68F3182542FULL, 0x18068CE832C37139ULL, 0x978215950B62F6AAULL, 0xA3B855D52A5774DCULL, 
            0xF8F8D134B68A8A13ULL, 0x7905748199F823F7ULL, 0x01E3CFE2335FEABEULL, 0x6C551FDE65908359ULL, 
            0x8B943650F4B7DD80ULL, 0xEA3592DC79D98614ULL, 0xD608F455155A26C6ULL, 0xCF1CA9DCB93BA92AULL, 
            0x0948A3A7D72D3AD1ULL, 0x1675AD2ABE1F5972ULL, 0x63C80BE283B04803ULL, 0xE7FF826822C96A9EULL, 
            0xF06F985BD2858B9AULL, 0x0C1F32D21C7005BAULL, 0xE1EEF794D6A1BAFAULL, 0x51D0220C838C1AA0ULL, 
            0xE6071A8AEE35A8ECULL, 0x7A2708A86C65BE29ULL, 0x87AC7940FDEFEE41ULL, 0x35B6DC87A2C4B085ULL
        },
        {
            0xE8A36A52A8F58F7FULL, 0x4732522D6703C351ULL, 0x6E0AC5112D5C6AD1ULL, 0xCBB928712D0ACD3DULL, 
            0xB655BAB6980921DCULL, 0x3C94FDA78B377B01ULL, 0x26A0F4C2AEBA7399ULL, 0x3248D28FD5C78FE4ULL, 
            0x6A78844D85E9728AULL, 0xDF5E76E0B9495079ULL, 0xBFBCB79EC5381B94ULL, 0x3DC3FF16A68BD08DULL, 
            0x164CBAE720D802A1ULL, 0xDC2DD320CC18A547ULL, 0xD95EAF072B52130FULL, 0x209AC71D01967C8CULL, 
            0xC785E51C92569371ULL, 0x7DCE69F852A7952CULL, 0x253FEB48599507E8ULL, 0x7EEECBAC5A451130ULL, 
            0x75BF4E23F391DD2DULL, 0x28660EFCB5FD2E8BULL, 0x32AC36F5C5A61830ULL, 0x2EA7DF66A4E13049ULL, 
            0xC879B75045C1820BULL, 0xF13B19997181FB88ULL, 0x8CC5639BF4DBAFD6ULL, 0x251B8744B4DA6FF4ULL, 
            0x1802108DD4449441ULL, 0xA1DC74C59A88E915ULL, 0x1F1691DCCCBB9645ULL, 0xB2CDAB45EC70CD76ULL
        },
        {
            0xB06CAE3800F442EAULL, 0x0E8DA16ADC2D31D1ULL, 0x9857999F7A4C102BULL, 0x8E83E183EF3E190BULL, 
            0x0DF4EEEA92EAF7ECULL, 0x7AC1FCC646FC605CULL, 0x11F190B2DD5E4D7AULL, 0x4733B12540333732ULL, 
            0xBA0C5E0CBFCEA436ULL, 0x7DA896FFF21E1EB1ULL, 0xB2176F589A116C29ULL, 0xE3CAD3C336299F2CULL, 
            0x9DCAAFF2D109F5C5ULL, 0x97564E2B3C053047ULL, 0xE8D055CF891A03A5ULL, 0x26C4A190E3118264ULL, 
            0x39D9ABAB63F5776EULL, 0x28BEF5650F0A7552ULL, 0x858754F437DA658BULL, 0x35E0DECA449C34DAULL, 
            0x5DEB1F94326CA378ULL, 0x9242FD897875465AULL, 0xFFFB40980BBF325AULL, 0x659D68D8B691B1F8ULL, 
            0xA969B72EC6C06D19ULL, 0x1C08154E14EC9194ULL, 0xE49E466A179713F8ULL, 0xAEFBD3A538BF0BF1ULL, 
            0x3DE59CB55F53B072ULL, 0x188465FBA0BA2884ULL, 0x357FF0F068EB8837ULL, 0xD9B033EC989E05D0ULL
        },
        {
            0x3981C1AFD7B6DA04ULL, 0xD0DEB8EDACA06F55ULL, 0xF5391F43D91A860AULL, 0x40C36C0A2A19B320ULL, 
            0x42F2C741E32C6302ULL, 0x3BB900A9AE285382ULL, 0x4483B8F2671DE89BULL, 0x246DEAFEA7C680D4ULL, 
            0x8B66D1188D1063A1ULL, 0xDA6E5F0A25408DABULL, 0x93F6F65DCF64EF55ULL, 0xB491315D753FE9A8ULL, 
            0x54E9F4F2B9444556ULL, 0x222A946DED51E40BULL, 0xB54D9916A847B09EULL, 0x8358415AF93D4D75ULL, 
            0x8923374EF19902CEULL, 0xAD39A4BFDACD2C18ULL, 0x6A6A0028A003F225ULL, 0xF59D988CC63A562FULL, 
            0x852323F0F060BBE9ULL, 0x7DF1E83C302CE446ULL, 0xF237DB5329326266ULL, 0xE39D7F887C483A93ULL, 
            0x771C5104E0B80F9CULL, 0xEC0C68F3004D0F4CULL, 0x33153C89504B5164ULL, 0x96DE647809B32859ULL, 
            0xD2FE25AB332277C2ULL, 0xC1FD93B4307BBE45ULL, 0x24DDD87090C6E858ULL, 0x0BE0D9B714746C6AULL
        },
        {
            0xCC8AE9FEF6F1E563ULL, 0xD2232F1734C2DDD4ULL, 0x9ACB39F7C66C35D2ULL, 0xB82FCD9A07FCA7DAULL, 
            0x34CB82F66F3625AEULL, 0xAB73F48BE874E73BULL, 0xA279D56B03B34E40ULL, 0xEAE47327E15107BBULL, 
            0x278F2A8F6FA47191ULL, 0xF8BD86D651640E41ULL, 0x67709CBB076A0068ULL, 0x5FF69DC9F01FB4ECULL, 
            0x7F5270097E3C4DB6ULL, 0x954467D973A08D1DULL, 0x36D203D329E8DBE9ULL, 0xA441378958038881ULL, 
            0x2D8186EBBE00088AULL, 0x84C551BA950D23B0ULL, 0xAAF504B3DAA0F935ULL, 0x41FD3AF8AE28F5D0ULL, 
            0xD6C4DFF080E6044CULL, 0x65DB78E087E205C4ULL, 0x10CA1EA089B58873ULL, 0xE5C0B085E5AA75AAULL, 
            0x74D9905F23AEB085ULL, 0x5EEC95574777A432ULL, 0x275EA56AECA18424ULL, 0xE565038783DC84B7ULL, 
            0x2123121D73427061ULL, 0x4B219FBE3DB69CA5ULL, 0x75019D2A700ECF91ULL, 0xC176D77E0CCF3A85ULL
        }
    },
    {
        {
            0xA716235A271F7739ULL, 0x9223E68C7661001CULL, 0xD64B5AE855A00601ULL, 0xCCDC139E982362DBULL, 
            0x245DCF8C532E9858ULL, 0xA6306358D458A5FCULL, 0x6396DAA9EA37E2B9ULL, 0x1F394320EBF2A81CULL, 
            0x8DDBA98A4B90EAAAULL, 0xAED8350D0B8AC72AULL, 0x3FE4694BC786DC28ULL, 0xE3E3CA0A0EE50F75ULL, 
            0x11C32CC8AF60A71FULL, 0x2E8C196CC74E2082ULL, 0xE38D18983F6F4ACAULL, 0x7D63E2A1A95E151AULL, 
            0x7BDE99C42DCA4905ULL, 0xA154DF807D059410ULL, 0xF77B032438EFE2D1ULL, 0x47D23E2402170D03ULL, 
            0x6A6F3FBC93835142ULL, 0x91DB547DD8469E80ULL, 0xBF6FDFFEBAC14B45ULL, 0xE9DA9F99ED3C7A70ULL, 
            0x66CF4E3863B72509ULL, 0x6FCD376D121DB2D9ULL, 0xF7EDFA482A435241ULL, 0x3A8377B44731CD68ULL, 
            0x8475FC2ED76E525AULL, 0x39CAFB584943DDFCULL, 0xBE75E079F3375842ULL, 0xE16DFD16D8D54848ULL
        },
        {
            0xA178034572C71BF2ULL, 0xE50E9FC91C48D6EEULL, 0x415245051E0C95FEULL, 0x4BFAA6BBED93ED8EULL, 
            0x21CA657B8FDB77D7ULL, 0x5E90E23B4FD53BDAULL, 0xEE7EB0B32F4C7BCDULL, 0xE126E1F939442B1CULL, 
            0x169B33BE015D0104ULL, 0x166338D62EA56DBAULL, 0xA180EF8AF7B95066ULL, 0xABAD7748ECC86EF0ULL, 
            0x5F5037AC0266ED49ULL, 0x9818F87D9D744CDCULL, 0xF03BDF278D50B597ULL, 0x2AE506E11A2E5F25ULL, 
            0x70878B1F07395AF8ULL, 0xF2BD6EB3FC564F21ULL, 0x2138004185456748ULL, 0x251BA2B1CF45C639ULL, 
            0x2272608E40BA5B9EULL, 0xD8EA204DC9E3ECDCULL, 0x8AD3FBC1B36F9BFEULL, 0x7BC018CB89C0AAD1ULL, 
            0x36DCD67D71DC534BULL, 0xBB5BD4DEDC3113E5ULL, 0x52D41D838F0708C1ULL, 0x9ABF47157D1FF248ULL, 
            0xF6013884804BDD5EULL, 0x59FAB59713789167ULL, 0xAC3203E811364B6EULL, 0x9AD92602E7931A39ULL
        },
        {
            0xD55E2781436FAD74ULL, 0x53BA8E18389D7435ULL, 0x65CFAF9861F7CC8FULL, 0x4258B98F93EF7BCBULL, 
            0xBA64162265029886ULL, 0x988C4EC95C049957ULL, 0x1FF8087E5A8E58C7ULL, 0xCB37115523BE1836ULL, 
            0x3D61883ACA0F0B24ULL, 0x3283322FA23FD90AULL, 0x117B7B6433C69DB4ULL, 0x02A11DFB34CB05B7ULL, 
            0x074B5C555618A1C0ULL, 0xB4EBBEDA92EFB9CFULL, 0xB196440F9E47B152ULL, 0x366A7CA43FD25A72ULL, 
            0xCEF9A7B999A7C8A7ULL, 0x825084508049839FULL, 0x1A1B0AE1AFE8AD8AULL, 0x0BF0861CBC3FC617ULL, 
            0x69A9EC7F6C674E06ULL, 0x6B60054218F1D69EULL, 0xDE335EB26DF80AD4ULL, 0xCCD1F3CDB00DB4E5ULL, 
            0xA4F6BD5DA24AFDD8ULL, 0x3943EC484B5F0D8EULL, 0x020AF0EB36374018ULL, 0x7672122918CADC29ULL, 
            0x9748D1BC4F713D4BULL, 0xE95AC34C934335D2ULL, 0x33A6B838B5B2B913ULL, 0x6ACB89F01C2F9906ULL
        },
        {
            0x81A8D990B46AF89FULL, 0xDE6A8532E81F716BULL, 0x0513799F88FBBF6AULL, 0xC9AB847F97A3E5C4ULL, 
            0x7179971C3A2831F1ULL, 0x19B48430A9B03758ULL, 0x9F5300F60AF0EFB9ULL, 0x04CA01B066BE2946ULL, 
            0x6EC6CC45AE787918ULL, 0x1A25A042E0E756D5ULL, 0x8B181629FDB08566ULL, 0x29A8D3A24C91A595ULL, 
            0xCCC21C5837392CF0ULL, 0x4893FDDC58F86CA0ULL, 0xE3FDC254548B0AD7ULL, 0xAE3322AD54865200ULL, 
            0xC6ACD9063949E85CULL, 0x09101C45F37E32ACULL, 0xADB50514517EC1B2ULL, 0x25833C129401F60BULL, 
            0x2C385B44FBA9290BULL, 0xA047BA86700DE9FBULL, 0x1D4C1E7C83015ADAULL, 0x16039D8DD4FDD8FEULL, 
            0x43E3035D32D67074ULL, 0x2F5CFC9523E70258ULL, 0xE0B0ABB89A8492D1ULL, 0xA3C6A50E2A65985FULL, 
            0x7C95FAEBD12004C2ULL, 0x6DFFCAD29220A759ULL, 0x7E3B3BA8BEC79F05ULL, 0xD1AAB5E06C4B9E4CULL
        },
        {
            0xFEB39563CA48402EULL, 0x2C0CE48742188256ULL, 0xD504EDD347D866F0ULL, 0xBDEFFAEDEB09CD71ULL, 
            0x405BCD34977646E4ULL, 0x08FC60C595ABBE48ULL, 0x37EA546B7D9B063AULL, 0x04076C55B4CC5269ULL, 
            0x2E1E30FE8B67414AULL, 0x0A0F51953A31DCE4ULL, 0x4F28EB538C0D5405ULL, 0x6F6CA604A4EEA623ULL, 
            0xBDC11C5E234F0877ULL, 0x4A00F5EDF5C4DD60ULL, 0xC9D5289517AE16D7ULL, 0x4D6497FAF3A38C57ULL, 
            0xA30682E30AA84387ULL, 0x139889630F60B63AULL, 0x63D666A3DE5C4681ULL, 0x59DE9CE907813C91ULL, 
            0xCCABD8DCCD1C2634ULL, 0x1FBB951C3F422796ULL, 0x06C9B6239D0DBC0CULL, 0xD0C80CCC670C7EFCULL, 
            0x8512E1B7F1006B20ULL, 0x9509E67701CCAF1AULL, 0x6E785B778060FDA5ULL, 0xC8D9DF7238CA7C73ULL, 
            0x23517F5506A32DE5ULL, 0x82C4E25411C18ADBULL, 0x265EA965DEBE32F2ULL, 0xF7653CC05686F830ULL
        },
        {
            0xB9A5A9BA25FD2A9EULL, 0xE0A28E3E8E877145ULL, 0xC1A85E69F835E46CULL, 0x1BB58C1ABE24C86EULL, 
            0x97CCEFF1C6191189ULL, 0xD7BCD5F2052FC723ULL, 0xCACB57175B7A19E5ULL, 0xD5BCB06F39E23C53ULL, 
            0xDA7B9CD9BD14C044ULL, 0x9305729CECAF7CEFULL, 0x039F997293A6CAACULL, 0x36B0B22967157BECULL, 
            0x3A23A9079FE25F82ULL, 0x41568A10DD52D06CULL, 0x980E320FF7E34C7CULL, 0xABE615501E215A96ULL, 
            0xDE53FA08D827509BULL, 0xDEB8AC7121CF01BCULL, 0x173F4F4097703413ULL, 0xE76B56B755F0A7EEULL, 
            0x3E5610041A16CBD3ULL, 0x5728EFD38B795F57ULL, 0x40292F22D46872D9ULL, 0x768B27A4EC202715ULL, 
            0x7EF2E409D1B1B136ULL, 0xF2FBED4D743B6B0CULL, 0x9C2E08BBEB8726A9ULL, 0x28747500BF3D85EBULL, 
            0xCBEAFA7399C323B6ULL, 0x2726B348A23D5CDFULL, 0xF6B6D1691F43B30DULL, 0x7BF5BD8A3448297BULL
        }
    },
    {
        {
            0x3ED336BD8E0AC996ULL, 0xB3DC0EF07FE81253ULL, 0x3037F1551305112DULL, 0xB31CE7E9576265FBULL, 
            0xE7FA022FED5594E1ULL, 0x5FFBEB9480353C0CULL, 0xC2B2B6FFE1C8E8AEULL, 0xCBA7B42114DF4AB0ULL, 
            0x43F07044B69EB471ULL, 0x2B202E4B24692013ULL, 0x8FEE0496FE511038ULL, 0x99830558AD684816ULL, 
            0xC5A677E5F20145B1ULL, 0x06186D9665D8FB1AULL, 0x8D147D057B7D84D0ULL, 0xAB84477819FA556EULL, 
            0x5F569E06B8093CC3ULL, 0xC5728F20A2307237ULL, 0xE75921AED15619CCULL, 0xB800733D6455481BULL, 
            0x08F34F026DB54F84ULL, 0xA6794A37B7AEEA7FULL, 0x266CA23B856D12ECULL, 0xAFE39B3439F48114ULL, 
            0x740F454B77ABC4CCULL, 0x909B35E9970CDD72ULL, 0x9289C09657935CAFULL, 0x06E209B304A6A13EULL, 
            0xBC17441734479B57ULL, 0x09A5E0E592EECB79ULL, 0x1976BA3C8C7BAE53ULL, 0x2EC9FCDE8C5BB0A8ULL
        },
        {
            0x453D49F3768D3BC1ULL, 0x38FC3B4CB7C017D3ULL, 0xA28F82611A9749F7ULL, 0xB0F10A60D936915DULL, 
            0xD17DE79F2E89D00EULL, 0xC40BC10A519D3E05ULL, 0x2F0EE76E3EBE5DF2ULL, 0x91847095D7A9D6AFULL, 
            0x37C89CC0118CB602ULL, 0x0D952F55961622FEULL, 0x6AB361FAD64BC6BCULL, 0x0CB6E2CDEFE5DAE4ULL, 
            0x0E9D1C853EF0B69BULL, 0xD52A4FE66A2E940DULL, 0xF430AADF7BBB0EA7ULL, 0x7B65A0DC9F488BA6ULL, 
            0x9C505BC2A8B00477ULL, 0x38ACC5B6559807DDULL, 0x7434C470C39C989DULL, 0x2FE4BD2EAD75AD69ULL, 
            0x418E43628B751E75ULL, 0xB87DDC8C9DCB61D6ULL, 0x56D3A89802435027ULL, 0xAD7D580226F833BAULL, 
            0x95061A4667833551ULL, 0xC2BDA2678F32A853ULL, 0x8C4067CF2EE5A539ULL, 0x108396DCE7C3D2C5ULL, 
            0xF04335F675161CCFULL, 0x5974339C56410EF3ULL, 0x3E28C2B4C87A4EFBULL, 0x4AA1D0A6CBB7377EULL
        },
        {
            0x46295FC5FA82A444ULL, 0xB92DF3573966A93AULL, 0xE3E15DC7ED4D623FULL, 0xADEE1D56DC73567EULL, 
            0xA2211672651AA6C9ULL, 0xF7069148A83DE8E8ULL, 0xFD85ED37702139BDULL, 0x0F2B5ECA01E2F900ULL, 
            0x38D1EEBF99A5B4B9ULL, 0x2E727417D61B666DULL, 0x05554EF56B9000A5ULL, 0x801C8803B90A9CB9ULL, 
            0x7421F2A809C8226DULL, 0xB2C2AF359E94A496ULL, 0x717DA3839CFA979BULL, 0x66C4414DBB91E674ULL, 
            0x8383E5E247D21779ULL, 0x8FFDD21371D5583DULL, 0xA44B6C6523E16145ULL, 0x560D06E17774B91EULL, 
            0x977DF2E351A83579ULL, 0xF3FE6C9043E1387AULL, 0x4A61623A18271046ULL, 0x20E9A36E3D698CEDULL, 
            0xD8645BB44D3DA51FULL, 0x0BDFFE8E1C93804BULL, 0x579944A93CB78CF9ULL, 0x597ED9A0892DD7BEULL, 
            0xA077BBE8B1B8274FULL, 0x8DA8B9EDC4C8638EULL, 0x719BEA4E068686F9ULL, 0xD114FD8C2C70A1E0ULL
        },
        {
            0x3AE5529D36654246ULL, 0x5504F31A5906B309ULL, 0x98638482AD693F06ULL, 0xA02F079804025485ULL, 
            0xE9DE19695B476BAEULL, 0xB3AAE118E7CD92E5ULL, 0x8BC38C3682268B38ULL, 0x09004D6B77C654DEULL, 
            0x542384B1DF852B6CULL, 0x2D31EF52B015D498ULL, 0xA9C8526F31229490ULL, 0x3D28572C69D38127ULL, 
            0xE40BEF50CE364A72ULL, 0x81A8823954A7DE5CULL, 0xDFDB9D7D82A04A04ULL, 0x01784E3C5CE92CEDULL, 
            0x66EFA0179D9FAC75ULL, 0x905A20CD3AD6B819ULL, 0x93A54AB0989F8E6DULL, 0xAF3DE63B524F7729ULL, 
            0xD43C6E0EEBBC7C1DULL, 0x9BE9122513A8F624ULL, 0xB88DD83385C1EB18ULL, 0x403FA3078662411EULL, 
            0x94FD5DB2FE4FD81DULL, 0x8BE3C9FAF8CC58BBULL, 0xE5A7CFF8F9C2DCCCULL, 0x09907FD56A64D6AEULL, 
            0x8D3629B4F50509BAULL, 0x824DD9BB0D56CE18ULL, 0x80FDF7C3F2394AE6ULL, 0x8C300E884ECE23F2ULL
        },
        {
            0xD7457FDE6B846A60ULL, 0xDCA575A72A68261CULL, 0x8E509DEAFACBE6B1ULL, 0x5590CB1F9C0F8AB2ULL, 
            0x5D9F369E919303AAULL, 0x590942A8AA1159E8ULL, 0xA81183BD332637B0ULL, 0x986DC84AAD090E64ULL, 
            0x28950EF1BECCB363ULL, 0xFD205D70F8B659DDULL, 0xDB5AC92B6F97CCCCULL, 0xF0BCC31100E41650ULL, 
            0xBA76647E7D1DAEA0ULL, 0x2650D2F10D3CA407ULL, 0xCA7BF6D14215322EULL, 0x91B1936206E502BFULL, 
            0xCDA44380475FF5CEULL, 0xEC42C675B1E6575EULL, 0x12AB98DE385B3ACAULL, 0x10B119609AB1D6FEULL, 
            0x805B5F6894AA72CFULL, 0x3A004A7FC3FB5543ULL, 0xE43B75B7B59BB44DULL, 0x80796A92CFF153CBULL, 
            0xEFBC5DBAE0F60C76ULL, 0x62E57FB0CC5738BFULL, 0x929167B27681347AULL, 0x823FAB5236464926ULL, 
            0x1FFC502B00C34449ULL, 0xED0CEAB71296E21BULL, 0x3713A35C28E6FA95ULL, 0x16945C4EBB34F79EULL
        },
        {
            0x06FF8BBAF6E366C8ULL, 0xB652ED45E33AD8EFULL, 0xE1629D3AB6861D44ULL, 0x67EA9D21D5300A36ULL, 
            0x4409BF5758D5C99CULL, 0x4C9C5752F1CFB242ULL, 0x503916EAC157A585ULL, 0xF265B6FD972F471AULL, 
            0x4A4A56E1023FDDF4ULL, 0x65CD4E291427764EULL, 0x99B5F107199A3B5AULL, 0xA8F08FB94A4C17F7ULL, 
            0xCC7E8834050FB263ULL, 0xC62474432E7C6447ULL, 0xB3B6590A6E6E636AULL, 0x9CCD59B490F4FBC3ULL, 
            0x11B8A68D441F1097ULL, 0x0592E85022320E86ULL, 0xCA458139F2C5297DULL, 0x5EE933A3AFD7E477ULL, 
            0x1EBA357DAB3E7D18ULL, 0x967B29D28DF00671ULL, 0x2F9D4AAF2C0D0B1BULL, 0xEB82A30E6A75ACA3ULL, 
            0x47012A42E3294F2BULL, 0xE7D71B17B4A48C98ULL, 0xEDABFB8502487EDAULL, 0xBF4FAFADD1A0A7D9ULL, 
            0x983FC606054464B6ULL, 0x94AC12886F4A263BULL, 0x568E06664837ABEEULL, 0xD951DE63BC4195B9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseDConstants = {
    0x51B8AEB7E63CE6ECULL,
    0xAA29A5003A720584ULL,
    0xAC71A221313BA4F4ULL,
    0x51B8AEB7E63CE6ECULL,
    0xAA29A5003A720584ULL,
    0xAC71A221313BA4F4ULL,
    0x2EFAC0C4A0063A2EULL,
    0x9B675FFF8870E955ULL,
    0x99,
    0x73,
    0x24,
    0x01,
    0x22,
    0x9C,
    0x2C,
    0x60
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseESalts = {
    {
        {
            0x93C846B510FF42E8ULL, 0x1CC78C9C86A68E3BULL, 0x8E7B72102098AA66ULL, 0x9E53209F4A4E14FDULL, 
            0x31AD10D6FB7FB59DULL, 0xEA27BF79B6A94C93ULL, 0x3C6D6B7C5AAC9C52ULL, 0xDDCAD33E855EAB0DULL, 
            0xCC820E2F2EB5BE31ULL, 0x0B0D3AB82A5E3A2DULL, 0xF454BC24EB1D1498ULL, 0xF0354E4230715BD2ULL, 
            0x09D545E637876AABULL, 0xD818C64481A6C73BULL, 0x50D2587C99EF02A3ULL, 0xBB9A91360671FC91ULL, 
            0xDABC998C87DA087BULL, 0x72F388119515A8DFULL, 0x8555FE46061F887EULL, 0xB3D0744E362BA4D8ULL, 
            0xF166E2BE01C515CFULL, 0x489215C759E933A4ULL, 0x22E2082ADB8717FAULL, 0x437F7F1E7B0D498BULL, 
            0xBAD2CDC71E94778DULL, 0xE82F00930410E1DEULL, 0x720282BEB8817178ULL, 0x95AC9470E1900EE1ULL, 
            0x2DC80959F70D093CULL, 0xC0FED788CA00207EULL, 0x1AD6EA6D443DEEE8ULL, 0x0027844350741487ULL
        },
        {
            0x60C0799E9F445576ULL, 0xDBBF60B5BEC9194AULL, 0x2EC54EBB732C233EULL, 0x1BAFB9404C43CBE0ULL, 
            0x6D5E36E96C6DB742ULL, 0x103CB9A835268579ULL, 0x4497431B86F47107ULL, 0x31A64108D474E60AULL, 
            0xE2E36A73AE9CC6A5ULL, 0x7BD9030B107269E1ULL, 0x68EDE4C36AE0C298ULL, 0xE6B8AB2AA9BA192EULL, 
            0x41EF4252687C015CULL, 0x5974D4A31444222AULL, 0xAC92F7F0D4A07E17ULL, 0x1E9CC22BB6464EDFULL, 
            0xE0C222782AB919ABULL, 0x5AD949DA671E7326ULL, 0x605D64DB718170C3ULL, 0x78B6390013DCC063ULL, 
            0x0058AD15CBAD1A10ULL, 0xFD052687997F088AULL, 0xB9684E83986D7E12ULL, 0x351CADFC6A4EEF92ULL, 
            0x091D38DAAB1203D3ULL, 0x587A625340482B25ULL, 0xC55F439C038F6A08ULL, 0x0A5AF772576BE216ULL, 
            0x0AD95797ACEE5762ULL, 0xB6105F2C48485E69ULL, 0x80E77A9078B66A43ULL, 0x473ED7AB7DCE94B6ULL
        },
        {
            0x3762023D958C18F0ULL, 0x473021E82A8DB17BULL, 0xD9774943526199F9ULL, 0xE798D319F65A02C8ULL, 
            0x948C6A87A99D17B1ULL, 0x642233D342EC54EBULL, 0xFF63D15FD51B911BULL, 0xD5F874C0398F8C2CULL, 
            0x49509B05F7B6052FULL, 0x7E904EF240905F64ULL, 0x0CE51362588D9F63ULL, 0x7FB02AAA085E6A4FULL, 
            0x67645ABE5D7DA7F1ULL, 0xDEE5DD215C827F14ULL, 0x986BAB1A3B41A3B2ULL, 0x6B47491641F979D5ULL, 
            0x6AA057A43FD4A0F7ULL, 0xC7D6EFD571439F67ULL, 0xD9069EEBD32609EFULL, 0x2A0E04E958A43EA4ULL, 
            0xD51C55F997BF36B4ULL, 0x1185285D6370CD33ULL, 0xF59C609157C513DEULL, 0x923480CED54FB644ULL, 
            0xC3530AB1C7034DFFULL, 0xF37651BBCACFBCD4ULL, 0x41B96D3BFFBA80E1ULL, 0x5C73CDD39ED1193DULL, 
            0x49C49CA91D81F018ULL, 0xD28929A388E37750ULL, 0xBBBEDA3599DE7A8DULL, 0x1F69E15E66FF573DULL
        },
        {
            0x11672E2E40045A78ULL, 0x0B7DDA706735023BULL, 0x1FC0F05360601094ULL, 0x090A745C79F199FDULL, 
            0xE9D6A6139915BB5BULL, 0x0A76B011EC610CD6ULL, 0x9BB7247023054FCAULL, 0xD76516DEC1264FE3ULL, 
            0x96ADDBD6C454821FULL, 0x499E5FE518D39ACCULL, 0x7A84BB05162A8263ULL, 0xC3DF17DE27BB091BULL, 
            0xB1506532A8C894C4ULL, 0xF819A657A2DCCCB4ULL, 0x46109115158DEEBCULL, 0xA6CAB6CB7A6AD7F2ULL, 
            0x12F8263673801C1DULL, 0x0C1FAE560B87164EULL, 0xC3B361AEC6810229ULL, 0xE2F5DB084402BE0EULL, 
            0x745FEB4632644F6EULL, 0xB62E1E083DB67AFAULL, 0x9BF3228E9D03FB25ULL, 0x2D224B33B20E589AULL, 
            0x201DA39C8828935EULL, 0xBF6A5DAEA6D423C3ULL, 0x3436417F152BBFE1ULL, 0x0A03BC592608DD29ULL, 
            0xD52FCB04BE9D6549ULL, 0x1B22C703048452BFULL, 0x9E1C63EA9D91253DULL, 0xC21BD631148DD58DULL
        },
        {
            0xCBDB53A38CA441A6ULL, 0xB87611C2353C798CULL, 0xD4DEA65D3693CAA6ULL, 0xB689B237A321C823ULL, 
            0x3AD06EE59AAF49A2ULL, 0x33DEF1E31C1DFEEDULL, 0x88A5DBCBE8D4D731ULL, 0x32A34458175682C2ULL, 
            0xDF2AD192E8CC2C4FULL, 0x4D84C91AAD66AC98ULL, 0xE699A342382739AEULL, 0xA0CA3725341AA470ULL, 
            0x201B30F322BB9401ULL, 0xF900D98695693FBFULL, 0x576B0030722249D3ULL, 0x0970772AA5E7F713ULL, 
            0x5756CFBBCD8EC456ULL, 0x7AFDD139DB25F036ULL, 0x1E9BDFC21958BB6DULL, 0x0E9A4610E3994265ULL, 
            0xEF85123DF4EF14C0ULL, 0xBB216E58753E5936ULL, 0xAEAE738719FC94CEULL, 0x56B2241031C7ACFEULL, 
            0x9E257318EED9CF52ULL, 0xABB1F6C90CA2DB49ULL, 0x45EEA31A390BFDB5ULL, 0x4C31890996DD5334ULL, 
            0x82068D24C45EF44AULL, 0xA96F208B6496DFE2ULL, 0x30CF0C6BE98478E5ULL, 0x1FECAD41EECFDA03ULL
        },
        {
            0x06E507F43A61BC22ULL, 0x5608E717D7F69005ULL, 0x142C822C3899E00AULL, 0x5B92231DB2AFB307ULL, 
            0xF4D9B9F1443E43D6ULL, 0xD0C1757063929247ULL, 0x6753ADA492D2E588ULL, 0x3889199514E2CA26ULL, 
            0x385FF08876370588ULL, 0xEAA9B298B771AB17ULL, 0xB90FD351F01A055DULL, 0x0099057176ADF390ULL, 
            0x86629BCA8527374DULL, 0xC4196FB4E91FABE2ULL, 0x373AD0DB57D4036FULL, 0xD640C38B857B2B34ULL, 
            0x0E1F10AEBBEFACB5ULL, 0x3FE493C37E313F03ULL, 0x6665208FDA3DAF1DULL, 0x8C66E9758E40B7A1ULL, 
            0xD33FA692EBA531D5ULL, 0x311809A9552DD71FULL, 0x95DB751C6D62EE49ULL, 0x6335D8D2A057390DULL, 
            0xDB0391D7E4902DFCULL, 0x801B30F1B32AB1DCULL, 0x6B8C1A478DB9C98EULL, 0xFBB1370245E2968CULL, 
            0x620EBF8A994ADE36ULL, 0x5766D74196B4D7E4ULL, 0x9F6A4A7095207E11ULL, 0xBF42EB0C57F4705BULL
        }
    },
    {
        {
            0xAAFDE7FCC4BA856CULL, 0xBEE82A1320ADED16ULL, 0xBBD098A5D7B165D0ULL, 0x5A86A0DD0627B8D2ULL, 
            0xAF3C9288FB140773ULL, 0x83711125FA8D4D77ULL, 0x53CA5B9324174F9BULL, 0x8BCF020272D8D7DDULL, 
            0x209DB04378B34EB9ULL, 0x15A784606CB3CFB7ULL, 0x8485EE399C6276A8ULL, 0xE557F3AE87D5A352ULL, 
            0xC3240D41BA9109C5ULL, 0xFE185ED6B477B190ULL, 0xAE047066B69CAD9AULL, 0xE12EE6A7347099BEULL, 
            0x08773680F30A4011ULL, 0x5D5449B2F080C55CULL, 0x28C2718F1E06AA56ULL, 0xFAC3E4783B0066A7ULL, 
            0x8F01D7D29E16D311ULL, 0x5947366F4B6B9667ULL, 0x0396DE4B60C9ADE4ULL, 0xEB1059664CC4830BULL, 
            0xD26846F68BBB7B16ULL, 0x14EE15A927DDB024ULL, 0xED4DF3EACA4B3BA9ULL, 0xCDAFF6C6F9BB33B7ULL, 
            0x6DEFD9426BDE156FULL, 0x79F7134DA4B09BB1ULL, 0x706B54273C3DAD6DULL, 0x6AD4A2F0813DBECFULL
        },
        {
            0x34BB278301BC03D7ULL, 0x3799393E43EE31CEULL, 0x536118702B96BC3FULL, 0xC88FCE89D61B94C7ULL, 
            0x6B5E85344A2E6383ULL, 0xEEF68765901D7D93ULL, 0x5A16FAD61CCA7F4DULL, 0xE8826CE288FE1B9FULL, 
            0x42284820EDE80211ULL, 0x8EE474671100FF77ULL, 0x2590A275F2AB2756ULL, 0xFE8384F2403E8873ULL, 
            0x5F5BB9CCED4D8213ULL, 0x5556E5DC09FFF312ULL, 0x45083B6EBFDE2FA3ULL, 0xFA9C3F0ADEAA5D4CULL, 
            0xC1E6D746A746FF36ULL, 0xD0B6A3FEA3D8C406ULL, 0x8C69C80DD743D3B2ULL, 0x307AB700A0503EB4ULL, 
            0x7973864533CC970EULL, 0x89E99394E072CDF8ULL, 0x03276D34834239E6ULL, 0x3C206EE988A89DD2ULL, 
            0x30F519D5FD520DE3ULL, 0x5E01545A1592667CULL, 0x4C90B7417E556C74ULL, 0xB7624AE6FDC612DEULL, 
            0x351D55EB97EB387FULL, 0xA4071482855B2BCAULL, 0x7E93717277B349E9ULL, 0x7219DECE48605D2DULL
        },
        {
            0x964F4ED35E4B8EEAULL, 0x36539D1B074E03F1ULL, 0xB975DEE7C0024A92ULL, 0x37EEECFBCA3C58E3ULL, 
            0x515B4A30D92D505FULL, 0x89D2949E0ED42982ULL, 0xC5C3C0342CAF1BEAULL, 0x23F269695A5356D0ULL, 
            0xAA99B729E29A1717ULL, 0x7841385AD20F6488ULL, 0x70A8851693957102ULL, 0x6BFF2663E68807AEULL, 
            0x59A5BEF1FC5707DEULL, 0x017CE4967EC9F4C6ULL, 0x5579C44973154940ULL, 0xE792C78D443A75BCULL, 
            0x5F34EE09D5FC51B3ULL, 0x380D9F69B445DFAEULL, 0x017DBE7F0B121D23ULL, 0x293EA15F31077A53ULL, 
            0x5E2F25CF63E8D08BULL, 0xA3DBDCD008BB515BULL, 0x6E1FCE003D5A1EAFULL, 0x0BB0225B6D2E44E5ULL, 
            0xADDCF67BAE421574ULL, 0x5F400416298A66E5ULL, 0xE1B8AE4642C4F3F9ULL, 0xC09103B73556B8CCULL, 
            0x9C5BD01F68B1AB07ULL, 0x3E47B6257D1B6FF5ULL, 0x5468C80F95AB56A4ULL, 0x36E93042913AE167ULL
        },
        {
            0x2FD756E06FC889EEULL, 0x0135D98E11F5EAC7ULL, 0x10A942F2410C7532ULL, 0x7DBD29FDFC1239BFULL, 
            0x333D18486E3DF154ULL, 0x355A9EB9EA2977F8ULL, 0x56304DE3D8A341BAULL, 0xF76E7FE70CE53DAAULL, 
            0x35EA3488BC7BD37EULL, 0xF0EB2E1B4CAD969EULL, 0x3BAA7070F681E4D6ULL, 0x8FB0D66AFBB15BD8ULL, 
            0xFB870A6EDDA27CD5ULL, 0x3A0D7F83D50292B9ULL, 0x2FC85D03AA0467C3ULL, 0x4C66FCDA9468115CULL, 
            0xBE912A24C698DDC2ULL, 0xC9CF68BCC0960A61ULL, 0x6C39E671ACCFCB4DULL, 0x75D0D7A265495BDFULL, 
            0xC6CB21FD3102C29BULL, 0x6B8960B18D33B6DDULL, 0x1912F7A60D47493FULL, 0xC6DE9419E0760B06ULL, 
            0x54CC97B831F4A62EULL, 0x2B9ECA78A6E6DD34ULL, 0x8715BFBE8199DBECULL, 0x0F9BAD639925160CULL, 
            0xC7A708B2EE522358ULL, 0x64211066D94770BEULL, 0x3EFD288BD62D82D5ULL, 0x82E647A45A98EE2EULL
        },
        {
            0xD06B8E5F09C04B48ULL, 0xBF413E8E87C1ED4FULL, 0xF5BC99CF3E854E03ULL, 0x459D698747BE50FDULL, 
            0x903394BD286458B7ULL, 0x5FEA60C36879835BULL, 0x88F8FA825394D0DBULL, 0xF8720436D1074E39ULL, 
            0x4509A44AEAD9FCE3ULL, 0x563DFD8657C1D368ULL, 0x0DCFD8162C5EBC04ULL, 0xF16735620BABCA5CULL, 
            0x58DC894942C7C82AULL, 0x87F7CFA15EFAB140ULL, 0x0640A799EC4BFFC2ULL, 0xCFD1A8B3FF581D11ULL, 
            0x099069EAE64F7938ULL, 0xFEB97026653D03A2ULL, 0xC8E6B827076D520EULL, 0xA9971821CB500427ULL, 
            0xF95AA484FBFF7A76ULL, 0x2C8B7EF40CC4B1F4ULL, 0x7CAE7784D127D29FULL, 0xDFDEAD84F68262BCULL, 
            0xBAEDDBD771AEA13EULL, 0xB7F3F0B93709AF62ULL, 0x270868121AB58C0CULL, 0x8E9467FC9706F8F9ULL, 
            0x875377BD25F9EE39ULL, 0x019BE3D101A9C974ULL, 0x3785D2A5554AFC8FULL, 0x93D9DBD4E61DD44DULL
        },
        {
            0x323848D3A3CBDA99ULL, 0xD5590064F81E26CCULL, 0x8AD9D9121E3402DDULL, 0x84BE091A9BD7FFBAULL, 
            0xEE03FA83CDB95775ULL, 0x58D488708D04E70DULL, 0x3F53C3638C471EA5ULL, 0xC9E46004158D72FEULL, 
            0x5797086600654473ULL, 0x3A264391F5A201DCULL, 0x8DB7D99D98353930ULL, 0xE08478D2B64F26EDULL, 
            0x51DC0632E91DE210ULL, 0xFB2C1C65F045C8D7ULL, 0x8422B9233C27B4D2ULL, 0x2E8EC3A128F4D0B5ULL, 
            0x5C0ECC6D944F10D3ULL, 0x531550E610562514ULL, 0x67995F2F550C2515ULL, 0x4694E5A15421B7B8ULL, 
            0xEE12941F7A3B02A2ULL, 0x4CE98B59ED554A6EULL, 0x2B7C891287A36F26ULL, 0x5E6DE43B14E00590ULL, 
            0xCCEF88ED25076840ULL, 0x177B6648AD9A3FDEULL, 0xA50D9EA044A80889ULL, 0x393BBA7E1F774E6EULL, 
            0xD91EC2D871C52E42ULL, 0x1BABB57C0C6F6421ULL, 0xDB524B0BECF0A297ULL, 0xE7E9E25CCB848C12ULL
        }
    },
    {
        {
            0x60DE8AF9BE82DAD7ULL, 0x290009220AFBFB4DULL, 0xA998A1E2CEDCB30FULL, 0xBCE74B5FE6D18449ULL, 
            0x0C74D6A71D86D5EFULL, 0x22E23B3AE0A18587ULL, 0x529759BBB18DB8C1ULL, 0xAFBAA2DF62368C52ULL, 
            0x28462787B5841B97ULL, 0xA743EF8EFDBFE5A6ULL, 0x917F7EB33FE237C0ULL, 0xF5F56D643B6E9A02ULL, 
            0xC01B56710EB40D59ULL, 0x771111E2A1A744E2ULL, 0x3CEE45EB23B98359ULL, 0xF8A61BFDE65E326CULL, 
            0xAA2D99B5169B64DAULL, 0x2519924FF0EB744EULL, 0xB5F4D4FC25004795ULL, 0x1AA85FC53AB3B4EEULL, 
            0x39448B314ADB8467ULL, 0xC0EF0F997A5F0CDDULL, 0x9ED40FF240154F8BULL, 0xD4C3E3B6D130EF38ULL, 
            0x6A2313A9A461EFE7ULL, 0x3E963CBCF83C31BCULL, 0x0A9531DEB1B3D471ULL, 0x6A5143C497807D17ULL, 
            0x9C9C029A3A04CC60ULL, 0xC524D3B959B755F7ULL, 0xB47401A65127F13FULL, 0x68F5B680F31719CBULL
        },
        {
            0x675A718955E3B5A1ULL, 0xE27E2242208F42ABULL, 0xF7094783722FB655ULL, 0xA5678BE2DE9583ACULL, 
            0xA0888719CEA0518CULL, 0xA16F3DF3FFA45F7AULL, 0xE8D4944D6708E4A8ULL, 0x65C7E795DAADFCA6ULL, 
            0xEEBA028B0AFB9B7DULL, 0xD723E622677D7A8CULL, 0xC1B97C0073A9C7FFULL, 0x267D91167C316D64ULL, 
            0x84B978B4773FB6DBULL, 0x4B6BE2B179E139B8ULL, 0x1E478D774D55016CULL, 0xB5BEEDD0CCC863E7ULL, 
            0x7154EDB37311BAABULL, 0xF30908E830A96BFBULL, 0x242A173B0EC4E861ULL, 0xA7CABB14F585A564ULL, 
            0xCBAD4FB003CD6F3AULL, 0x99714E505C9D81BCULL, 0x3566CD319C9EB62BULL, 0xC87E30D7B5BDC145ULL, 
            0xD3A18DFCAB02EC36ULL, 0x7D4C5D5042B42E41ULL, 0x70E2018C48EEF607ULL, 0x326DEA88E1FFEF9FULL, 
            0x056DDB63394FBD22ULL, 0xC4E44DF3298EE0CAULL, 0x901D3273AE844D7CULL, 0x3B341835E013C90EULL
        },
        {
            0x8DC656608B058181ULL, 0x0021A9D53E08BE5EULL, 0x6C747A227C4C6BECULL, 0x648A831AF0E27A23ULL, 
            0x42BB1DDA41128074ULL, 0x3C45091A70D67E90ULL, 0xC9425080CAF7185AULL, 0x556125B62173A29DULL, 
            0x0ED0280C85EB8C06ULL, 0xD7E12F2CFC5B9E0BULL, 0xB1CA136DABAC8CE4ULL, 0x83D5AA09BD295775ULL, 
            0x9BCBF483BA00584AULL, 0x3AB7473608E271BAULL, 0xA85983BBFBA58703ULL, 0xA1BAF7B24089A582ULL, 
            0x7B737E4FE0E65243ULL, 0xBF8BB333E54DE9B4ULL, 0x30FC3144360CDEF2ULL, 0x5F449F1C8A5923BDULL, 
            0x8E0EB61CC7EFA2EAULL, 0x9D13F06202288DE6ULL, 0x84C625465D3527F3ULL, 0x773B6F580F10F3C8ULL, 
            0x09A557A3C18BE9AEULL, 0xD6FAB9EE5940C624ULL, 0x76B3382DD8E2FFB3ULL, 0x50593C4EEB42ECC2ULL, 
            0xBD40B504AB6AF220ULL, 0x327787DD376075D3ULL, 0x41D41A5EEA518796ULL, 0xAF7170BE9F5F77AEULL
        },
        {
            0xD39C022158AC8DB0ULL, 0x26063C8299CF793AULL, 0x19F35BDC513FC6F5ULL, 0x2515EE74C6377FB7ULL, 
            0x0EB330C640E7CB9EULL, 0x2E671BFC8B68FAA7ULL, 0x60A40B7D9F43F280ULL, 0xC0300E130EC70F22ULL, 
            0x566E778E5CDDADE1ULL, 0xF2147ED5FA5971A3ULL, 0xBE5639E9B158C556ULL, 0xF44CAEDEECE3C8EDULL, 
            0x70EFDAE08950A760ULL, 0xE4DC878642D8B77BULL, 0xF3E8F78387179B0DULL, 0x36FF3262F82662C8ULL, 
            0xAE9736C0FC486E69ULL, 0x387F0E0A363CEF99ULL, 0x4F0C916A2DF38C8FULL, 0x0D2D31C94B4121FBULL, 
            0x03A09BD27DA5C6ABULL, 0xD41645EF185B4500ULL, 0xB11E219E1C147C37ULL, 0x37D3FA9897DE64E5ULL, 
            0xC93BA365DDDD5255ULL, 0x09F09D96701A5EFBULL, 0x2DFE8C94A65D36AAULL, 0x8AD1AC939B4E7CB7ULL, 
            0x2FEE0FE9817AEA9FULL, 0xE6E0DD11FA61720EULL, 0x8AB0DA30DF5737F2ULL, 0x3BFB6A44037BB256ULL
        },
        {
            0x15FF146247E942E3ULL, 0x453087AB937D7E19ULL, 0x81977BB7CF7FE513ULL, 0x414721C4726AC40AULL, 
            0x3D31D27E2B440DF9ULL, 0x68E67411FB6189E3ULL, 0x0CB43789A5ACB645ULL, 0xF6C68330A2715054ULL, 
            0x6D185B47AD6E3F78ULL, 0x49C946A16FD252ACULL, 0x2EDB824B2C5D7B1DULL, 0xC264DA1555DAE252ULL, 
            0x98CFB1DC49A7F33CULL, 0xB5C6B11C6AF09AB0ULL, 0x057B58A2D42E9457ULL, 0xD1A58D2BD56F8A38ULL, 
            0x2BD8A5FFBEB35AE9ULL, 0xD0BDA0F898240BBDULL, 0xB6E5E4D79FEDA288ULL, 0x03A447AC3284E4D3ULL, 
            0xFA3ED837600A0ECFULL, 0x2248BAB917BAF4E3ULL, 0x660E6030FBE2E3E7ULL, 0x975E6FC5E713E644ULL, 
            0x03802F66F5CDED4BULL, 0x3C554BB6F8932EE2ULL, 0xF9F7D75D7AD273B6ULL, 0x580833C114CEF74AULL, 
            0xA0B2A31BACD2364EULL, 0xB80F3C548B18CACEULL, 0xF490E8700AFE5631ULL, 0x898D644946704828ULL
        },
        {
            0x577DF88B0CF10A24ULL, 0xF82D82DA4E3896E6ULL, 0x12D8F6EF37743B9DULL, 0x00754C0624232F01ULL, 
            0xB52A8594EACA0D61ULL, 0x91B724EA746B578CULL, 0xC024701093144AC5ULL, 0x1F5B2181B90F8F47ULL, 
            0xAB33E7E5CC239E1AULL, 0xA8562E939D47EE97ULL, 0x92D952817796BBF2ULL, 0x87BBCCCF1CAA1747ULL, 
            0x61F9693D90CB87C0ULL, 0x758A18480F86E182ULL, 0xE07FA9CCD6173B71ULL, 0xDB65386F271AF69BULL, 
            0xB4968A7C40EF7B70ULL, 0x75169A958A6E905DULL, 0xCE3A360C25D413D1ULL, 0x59E52EA9C19A265DULL, 
            0xE380DA2A4A4DD910ULL, 0x9E3440F78EC4434CULL, 0x33FFD0B01D98E8ACULL, 0xA20A77EE93E383CCULL, 
            0xF3B9A2CB375AB291ULL, 0xEE3935B1E9526B5FULL, 0x024A2E8B665D36A0ULL, 0x1DBBB2109B148BE5ULL, 
            0xC25C3C298D92EFFFULL, 0x93F66E3DE951837BULL, 0xB0EB4F8CBBCA8A58ULL, 0x4852E11390F36419ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseEConstants = {
    0xFA8FA9D85C21054AULL,
    0xBA3E79A573C25EEDULL,
    0xB8B1E8120ACB49C1ULL,
    0xFA8FA9D85C21054AULL,
    0xBA3E79A573C25EEDULL,
    0xB8B1E8120ACB49C1ULL,
    0x6C32B668665A3B99ULL,
    0x27B75A70A72FA02EULL,
    0xE0,
    0xBD,
    0x61,
    0xD1,
    0x74,
    0x34,
    0xC4,
    0x5E
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseFSalts = {
    {
        {
            0x753C2C0E0BCAA483ULL, 0x5B3C3095F6F52B02ULL, 0x759B44A9CCCCA9CAULL, 0x55BC409C8478073CULL, 
            0xEBC00B07D73789B0ULL, 0x8CCBE0964EECB911ULL, 0xFF63A5D789FF21DAULL, 0xBAC6EE0EBEB5C251ULL, 
            0x34FCE0041F9CF6E2ULL, 0x13C507AC357BBF27ULL, 0x8F90FA38B342C4A1ULL, 0x36DDA7A3ED2930F0ULL, 
            0x64267229488C87C3ULL, 0x4CDB70BFA41FAD0EULL, 0x949485A64B1D5FA0ULL, 0x3D7989C8C08ACD6AULL, 
            0x20598541DADE73C0ULL, 0x3E35AAFA1C513AE1ULL, 0xEC2273C596CBF045ULL, 0x0C14562C6EB9A4C4ULL, 
            0x9BF64756C9ACA52BULL, 0x948956733FD2809AULL, 0x503423B200D01204ULL, 0xB285075982794AE8ULL, 
            0xFC404CD54583E5FCULL, 0x2CBF96926BA101C8ULL, 0xE7AA8B63BEA3A6E5ULL, 0x6140F979C4B4A2FBULL, 
            0xAAD2A21A09805C49ULL, 0xF65993114741A2F3ULL, 0x6EABB675AC2B083CULL, 0xCCBA9FB053C15E46ULL
        },
        {
            0x26AAEDDCCB869B4EULL, 0xD154C35A04BE4727ULL, 0xE8FDA56E06C2AC54ULL, 0xCA18C573BFDE48D0ULL, 
            0x5C993AB7FF404872ULL, 0x9614F83778726E2FULL, 0x260AD22ED1F7504BULL, 0x0022D526F6CFCA00ULL, 
            0x8325E535F2AB962FULL, 0xE4B29795C8BA8302ULL, 0x013A2E1DA33B991BULL, 0x800DD98863F003FBULL, 
            0x330750FC162ECD5CULL, 0xDAAD90194B25C0B2ULL, 0x3F3434CBEA540490ULL, 0x1203183819F777B2ULL, 
            0xD05B102A6155EB82ULL, 0x6F27624878932609ULL, 0xD6C7BB09DA763B51ULL, 0xF9627E43F2C954E0ULL, 
            0x0A7C32AA1D3E630DULL, 0x6A56A494B6F66DD3ULL, 0xC435BC43F716815AULL, 0xEC8912866630501DULL, 
            0x3E4F7951DBAAB7F8ULL, 0xFAE960BEAC3636AFULL, 0xE58BC6300CDFFBECULL, 0x6E2D0CC2321E0E49ULL, 
            0xF6F7F91B058CB94EULL, 0xB534078BD6412FB1ULL, 0xB17B478F804F2733ULL, 0x728F39967417450AULL
        },
        {
            0x593A02F998492234ULL, 0xDF425DA3F6FEBC9FULL, 0xD45F73807BEA28B3ULL, 0x00E1BA46CC1FC222ULL, 
            0x91B2EF5EF44032F4ULL, 0x1900964A73972AE7ULL, 0x5CF1231125AA6D4DULL, 0x76EB0106AA3EB2A1ULL, 
            0x3FC447FB16C175F1ULL, 0x1FDEDA3A86B51955ULL, 0x0799BB52258D2E87ULL, 0x4F4AB5DEEF2594F8ULL, 
            0xC2C39BBD23BCA0A6ULL, 0xB80E004BDA646860ULL, 0x40B0A74E67D3F17BULL, 0xEC62E55B07FB3981ULL, 
            0x4F1765CE9CB0834FULL, 0x8B2411902757013BULL, 0x4FB78BB5CC4CEF78ULL, 0x69B444ADFF1295C3ULL, 
            0xFF3665FC1611901BULL, 0x3654FE3BC0782A62ULL, 0x0291A803B21D8DC6ULL, 0x7736B992A4542175ULL, 
            0xF94C83AA7714EDBBULL, 0x44A2D4EECF5C9A4EULL, 0xEEFADDCCD6AE27C5ULL, 0x83ACD7CFB65A6C3CULL, 
            0x33396E0918658B07ULL, 0xE44E835371210033ULL, 0x7BE10BF7E9CEE641ULL, 0xAEB54A5DEEF029B7ULL
        },
        {
            0x03D8333CBD1A8758ULL, 0x13D69E35A8FAA440ULL, 0x5C61A7A354A6A216ULL, 0xF7338CDB919E1E09ULL, 
            0x86D5A2BC8BDE6472ULL, 0x3BAE25B66A438913ULL, 0x829B73CC54285D92ULL, 0x657A6D98B75666ACULL, 
            0xEDBCDF2090947F82ULL, 0x2111DF9C60D4097AULL, 0x88BFB431480873FBULL, 0x97AC42EBE50D9A80ULL, 
            0xE4300D26B6131667ULL, 0x534DD142F2C5C58FULL, 0x9AF8F67C5FF08D60ULL, 0x4D1333162BC8F425ULL, 
            0xBF91F6A64294AD54ULL, 0x5A5B1D926C3F0025ULL, 0xB59A9ED30B267767ULL, 0x914151F776F61AC8ULL, 
            0x44DF469370FF213DULL, 0x58F5DDB937300B57ULL, 0x79150A3E8B0D8EDEULL, 0xABF060B97948466EULL, 
            0x66D6743FE20EB1F3ULL, 0x7C0C56951692D351ULL, 0xBFBA86F3CC7134D1ULL, 0x5F02BCD6579FB359ULL, 
            0xE8112CD55D857386ULL, 0xC92B0D486352C392ULL, 0xE2A177290AEE9E7EULL, 0xE8052347429C8FBAULL
        },
        {
            0x6ECF45C2E1D930E7ULL, 0x618F25E14A2C9C04ULL, 0x9E76BEEADCD47B84ULL, 0xB14FB011489F21F6ULL, 
            0x5AF9F9EC07818A66ULL, 0x09D5CF8921EE740DULL, 0x4A10ADE96ABDC82BULL, 0x02D5C622A1A7864EULL, 
            0x18537FB8A9C3305BULL, 0x71E2A06EA1621BCFULL, 0x16530D6810AACEE7ULL, 0xAEB6DEED7784C954ULL, 
            0x9D82EF45170A23C2ULL, 0x67471C91A4222CC3ULL, 0xD557384BADCF27FBULL, 0xA7046C1017E4F7BAULL, 
            0x574D7B1C933DD6F9ULL, 0x3614D7731537B8F4ULL, 0x57AA4E27BFC5217AULL, 0x0E6966C858A3984CULL, 
            0xBDB50C546D3FEA39ULL, 0xEC9096629DBB4C30ULL, 0xD7032EF5866F4494ULL, 0x227804BFDFC3C044ULL, 
            0xF8A3A5834F2E8554ULL, 0x09253AC551674396ULL, 0x046E938DBF02F957ULL, 0xBA1B556FD84E55E1ULL, 
            0x332A03DE4142CF54ULL, 0xA241BC8312BD6A62ULL, 0x1BCB779DB4D7578DULL, 0x6BC89B3288103FBDULL
        },
        {
            0xBFDEB363661D1881ULL, 0xA8A4F5C5292FB036ULL, 0x25D1E16DBD1131D6ULL, 0xDC9A56BE542221DBULL, 
            0x5C84DBE6B26320C2ULL, 0x0A35880C76BD1084ULL, 0x89131F00FBDD365CULL, 0xF8D3B6B35C1EE9F4ULL, 
            0xD64F3CC26F656267ULL, 0x97D6F06B8F570354ULL, 0x595588D3A12C83E9ULL, 0x2D2A4D6C21C7C773ULL, 
            0xAAD15D17EED55767ULL, 0x62F21875B500BDC0ULL, 0xF33E4C8824684D99ULL, 0xDA02279A47B5785AULL, 
            0xC51451558658C06BULL, 0x63D744C762623E88ULL, 0xCAC3DEB33499B2E3ULL, 0xF2F0C78FEB6C289EULL, 
            0xFF791AE5063EB8D3ULL, 0x3697062D9024B3A0ULL, 0x031654F7D30C21B6ULL, 0x9F970D5AC1F8E676ULL, 
            0x9E48FABF7484028FULL, 0x1B056F4CE1AC68EDULL, 0x99B5413F1F1D8B90ULL, 0x9AB464848E0754E2ULL, 
            0x9F1B5B7276106284ULL, 0x7DAF485687025C1FULL, 0xD1F0064E92F108DEULL, 0xF0B615364E85338DULL
        }
    },
    {
        {
            0x567FF257B4ED35C0ULL, 0x2DE0AD6183E6ED9EULL, 0xF06C2A82FB9E0249ULL, 0xA2CF94D492DFDC54ULL, 
            0xB86AE45A83AAFEECULL, 0xE039A128C174F16EULL, 0x2FCEEC055DF2AF71ULL, 0x80E999A3BB9EFF0EULL, 
            0x843241846114782CULL, 0xCF9FDA6F48BE5C26ULL, 0xB95C4CE396B0A50AULL, 0xED42057E8625D9C4ULL, 
            0x46656D7437C7FA11ULL, 0xACD83AF36FB51116ULL, 0xB3E53D9679F3F62FULL, 0xABA1C1377BA4041FULL, 
            0x6349DC1F85B39609ULL, 0xB02045FAE7C6DCD9ULL, 0xC0733F6FA05BA5ACULL, 0x640F90139E810A2AULL, 
            0xE71B40F2A5EF5726ULL, 0x76D5D6CB4CEA51BAULL, 0xD08C97B88613EFFBULL, 0xBDA9B857DB2A628AULL, 
            0x11B9F61EF5803EC1ULL, 0x2BC02222E1D927C8ULL, 0xE163A1AA26C613EDULL, 0x0C75D46630667F27ULL, 
            0x80E4BFD70698948FULL, 0xF7331BFB991DD2F8ULL, 0x99F2B5D285868D40ULL, 0x5B128C408BBFC4E0ULL
        },
        {
            0x834B4883EFA5C484ULL, 0xCC36DA432904B956ULL, 0xCD7683FD710A6A82ULL, 0x3EAA445825D86C42ULL, 
            0x40585CAEDADF6B5BULL, 0xB552D1D13659FBB3ULL, 0xA63C1BE0B5A1E26DULL, 0xDE4E0B3544F2454DULL, 
            0xE1118235F4B48269ULL, 0x13AF64CC92B99AC5ULL, 0xC1D1A0D5E719511DULL, 0x3CC751EFEB91E5D2ULL, 
            0xE6801F7584DF74C0ULL, 0xDEE8AEDD94A97F35ULL, 0x949075FCF6884C9CULL, 0xBB5DD5C31CA053D3ULL, 
            0xE16DBA362475FDE0ULL, 0x142DD5CB940C5A83ULL, 0xC44BDCC06897293DULL, 0x5FCE7E3F4D2E0002ULL, 
            0x7027A43ECA6E6444ULL, 0xC721A1E61B728777ULL, 0xB91D7836998D6C56ULL, 0xA1F2E295E301E007ULL, 
            0x801729460F62BFAEULL, 0x44556508F5718FEEULL, 0x2413E4E7CE775129ULL, 0xEAE153D76E9DFB08ULL, 
            0x316852D0CD3A7FB0ULL, 0x96A02D9991509D92ULL, 0x5EA60516CA3F529FULL, 0x226A2F3EF7E00400ULL
        },
        {
            0xA7EE0E20F8751D0AULL, 0xA673FEA8F820F6D5ULL, 0xB9FEF8BD53431013ULL, 0x58E9B7E7BB13CF29ULL, 
            0x4D68C03DD8796BCBULL, 0x545132B72DC5BFB4ULL, 0xCB1E1839A4918A2EULL, 0xF3A30026A368B6D0ULL, 
            0xB31C569E10F8FBACULL, 0x3F706F31592B83B0ULL, 0x294EDD914729BBC3ULL, 0x7742B9F47053BDD3ULL, 
            0x370C65CEAC29A2C4ULL, 0x88D609656E29FAFBULL, 0xA7E28180AB3C571AULL, 0x89275A50D77AEFA8ULL, 
            0xEEAB154BCC143839ULL, 0xB0922A5999F53F9EULL, 0x2B78EA13A33BB1FCULL, 0x163201824188DAD5ULL, 
            0x8B80E09FB805D1C3ULL, 0x7456AFD23E4E9782ULL, 0x0095ADCA5084C63EULL, 0xFD71A34AAEA4CE26ULL, 
            0x9FBD98E3EF3C68BBULL, 0x9E2FF73B29DDD61EULL, 0xA83B2ED00BD56B01ULL, 0xBB20B7585D0D843EULL, 
            0x0FE9B58C5548CFDBULL, 0x763251CD6D271825ULL, 0x85817EE4EF2F6844ULL, 0x75514D5E3AE6DAD0ULL
        },
        {
            0x5E6BEF46CA8A0B88ULL, 0x53784A9CE9E7978CULL, 0xAAD7CAE960C95282ULL, 0x05AD12766E41432DULL, 
            0x7589E150F27B02B2ULL, 0x3DC36CFF7AF5F57DULL, 0x266750FC37EFF03DULL, 0xA554FF9C326C5932ULL, 
            0xB833F470C9350ED8ULL, 0x3035CFD703A9C922ULL, 0xC6839223A1432BFFULL, 0x5EFB2D4439794BA9ULL, 
            0xAD77851F108271B3ULL, 0x21C14AD8B161FBEFULL, 0xEC21581C918EBDCBULL, 0x522A9584B24034EAULL, 
            0x74500B2EAC3582B0ULL, 0x57FCE90486C2B00FULL, 0xA7AD59B9695DADA1ULL, 0xFF411D6B87EE05D1ULL, 
            0x0807F0FF1C507250ULL, 0xB950706EBE76FDAEULL, 0xA6F7E04DE2120E7BULL, 0xAF31DABFAB852E06ULL, 
            0x8FC0F5C3D8EF6842ULL, 0x3BC303D0F663D9A7ULL, 0xA3842913177913B9ULL, 0xBEC956619620005EULL, 
            0x9E017F243C0F3112ULL, 0x964C9382442C4CCFULL, 0x17E7968E040015DCULL, 0x3A95A924AB8B29CCULL
        },
        {
            0x2934335932A34791ULL, 0x9FBD36C78410D038ULL, 0xCE3318968850C300ULL, 0x5193A70EDDB28C6AULL, 
            0x11B2E01E38ABB10DULL, 0xA67B7BBA6BA6FBD0ULL, 0xBED161DE53EA2DF6ULL, 0x3EFD176FD39C8419ULL, 
            0x21ABBADA12678B99ULL, 0x6BA42AA0248F4315ULL, 0x789CCA24203767CFULL, 0x4AD54C0F37F5547BULL, 
            0x8A4AA455F3ADA925ULL, 0x9CBC030A7AE80544ULL, 0xB85F133C5F4D894DULL, 0x98DB7DE85475CEF5ULL, 
            0x369152770A03306EULL, 0xAB82B60508068B9BULL, 0xF9CC243CB2981ABDULL, 0x786DC61F22D9ABDBULL, 
            0xE66C3D9411CE0F3FULL, 0x9E034630D2EBF8A9ULL, 0x94B727E87C6EC78AULL, 0x86F1FCBC907AAC45ULL, 
            0x178612E6973550A5ULL, 0x4894289CFAE5A747ULL, 0x6806F1F0094B4574ULL, 0x537D258D28C35208ULL, 
            0xF7D310AFE0965F09ULL, 0x37994001E7F6FFF5ULL, 0x0B85FF18BD0FAAA6ULL, 0xDAF6FB907CC16F6BULL
        },
        {
            0xF61BB14B428F40DAULL, 0x9626C5557F6B457AULL, 0xC74A583C267012B2ULL, 0x0912000E3C8B5439ULL, 
            0x0ECBBB8C9F202482ULL, 0xF19C59169DDC2182ULL, 0xFF874976CF396E4BULL, 0x76575E65F548635BULL, 
            0x2483772A20AE03F4ULL, 0xD78EA8998E550ED7ULL, 0xE6C55D99E7EC4316ULL, 0x275981B0C6AFD7E9ULL, 
            0xA2BC1A243C6828F5ULL, 0x92BD30174D9EBBA7ULL, 0xBBEE77CA3693AE6AULL, 0x978E400E263A72A2ULL, 
            0xF057AC77EA93043CULL, 0x2EF23D787BC01D24ULL, 0xB7E059EF8A34BDC7ULL, 0x45094A9BDA737F2EULL, 
            0xE93D59D7D9B9AC8AULL, 0x8A30F43215E5E15AULL, 0x0C2C29670986F111ULL, 0x7BB1C5D01A894FE6ULL, 
            0x61BDFD7D0E99BC88ULL, 0xDF33336D9D753981ULL, 0x61F2319F34B4FF9BULL, 0x0389FA20A644863FULL, 
            0xE0A4840C734B7F9FULL, 0xDCFA46C59C16B174ULL, 0x0A892E26A92BCCB2ULL, 0xA453A54C78906EE2ULL
        }
    },
    {
        {
            0x8A9819D24202575BULL, 0x539DFB1576C92BD3ULL, 0xC17D20FAABD851CAULL, 0xD4551605F529303BULL, 
            0x07D46E71088FB9C6ULL, 0xAA17AD4542F0E11FULL, 0xD8360CA202D6BAE8ULL, 0x9358F4A0BE0829A2ULL, 
            0xF91A023907FC7B3DULL, 0xCBFCF21FF58E5D2DULL, 0x33E909BC8CA7FDE0ULL, 0xA27F7CB4A36CE89EULL, 
            0x672FE3853445EB71ULL, 0x01CCC5A844C84A85ULL, 0x72EE96951744D8EBULL, 0x4B018748DCEC9DF2ULL, 
            0x39D67ADFFE5363B0ULL, 0xD5212B2C62A85470ULL, 0x6A356024A4C6228AULL, 0x10F8897E6D169311ULL, 
            0xB56F8FFDB96D602AULL, 0xEF89249C22BFA756ULL, 0x4A10FB6CBD99188DULL, 0x03E1076B794C3034ULL, 
            0x71E3DDF2A4BEB5A1ULL, 0xAE4F6F06B19407FFULL, 0x02FA8D3B6874AB75ULL, 0xEB11ECF9CE3FA78AULL, 
            0x7254A5B3CDDD6D58ULL, 0xBE1CB3ED30F18515ULL, 0x814910B1EB03495BULL, 0x470BE21F6EF162D7ULL
        },
        {
            0xB1DA2CABF8253CA1ULL, 0x56F6F1DD7822EAB0ULL, 0x86BD0CF9808431F3ULL, 0x97D5A1A59BC5A06BULL, 
            0x1FB38BB70DE789E7ULL, 0x09799AF6662B579EULL, 0x13CEA7871FDE4557ULL, 0x63DF58633C5BAFA4ULL, 
            0x7151F3F5E96ACA6FULL, 0xB8AD9C6934C3DE12ULL, 0xF9127BBA290B79EEULL, 0x06E453522A12D967ULL, 
            0x5036E7712FF29185ULL, 0x1F741147E1C7B0ABULL, 0x60469AF8DD649465ULL, 0x1C44B03011998D7AULL, 
            0x1FEEEF6034B4D9E5ULL, 0xD5CCB83102769195ULL, 0x3738B48EAFAB88CEULL, 0x982028F25A2E901AULL, 
            0x35485780DFA1BEB7ULL, 0x870FBDA837FC2B29ULL, 0x468BA27C7EF711FBULL, 0x09A157CE914CC3DDULL, 
            0xD60457B1A6E7AE40ULL, 0xCE40635018500F2DULL, 0x7A0AC7156332DB62ULL, 0xD91F67F461859C88ULL, 
            0x1604DA8103BE6953ULL, 0xFF35A334D74D2538ULL, 0xFF04ABE0C07C825FULL, 0x18FD5F45D6E3ACFCULL
        },
        {
            0x803039C5EA05ED8AULL, 0x4C6C98003B25E54BULL, 0xC77D21D31E12B04BULL, 0x09D98A438C7DE586ULL, 
            0xF41D34A91531398AULL, 0xAE0904636BCDDC3DULL, 0xBDFC4E6A54ABDDB3ULL, 0xB9BF748AF80B4BBCULL, 
            0xB874D84C1A2E752DULL, 0xC07C2F7EE5B255C9ULL, 0x2BF33D37CE386BDEULL, 0x71BFC332951D48CBULL, 
            0x110C89BCB6866186ULL, 0x90CDB8C0DE8EE20FULL, 0xA61289C189C866D5ULL, 0xA5C674B610DE9E2CULL, 
            0x13D822243F388790ULL, 0xF96AAE956C4E08BCULL, 0x3ED4CED66B93D4F4ULL, 0xD2ACED365CACD5E4ULL, 
            0xDDCD377DAA8DA5C2ULL, 0xCCD930792E68302DULL, 0x1B8535BB9385A2ABULL, 0x01EC551FAC7A54A3ULL, 
            0x5FED598968678AB9ULL, 0x3721C4B6A88C5291ULL, 0x9ECC1924D0D45E13ULL, 0x4B519A19248091B9ULL, 
            0xDD02CBCD7D665B2AULL, 0xED91D9981AE340D8ULL, 0x311A5DAD49DA6447ULL, 0x44F86EF0847A1C73ULL
        },
        {
            0x1477BB0D97754788ULL, 0x3BBA5830D473DD9AULL, 0x05E2C96970326C3DULL, 0xAB9F0309162472BBULL, 
            0xCBA0176E0D2BA42AULL, 0xA3716F07E64F5586ULL, 0xC284B143451A2B0DULL, 0x5C36F9D34D9432FEULL, 
            0x672BFB305B3FD5F4ULL, 0xE63E5B94A5387513ULL, 0x403206DCB5FFF923ULL, 0x881C73A20DB9514FULL, 
            0xB7943FBE16B0D2A7ULL, 0x7D97102F6DA74F65ULL, 0x19076A080DCDCDF2ULL, 0x023474981B4B60D0ULL, 
            0x25D91D098813ECF2ULL, 0x3A22C7516C456DA0ULL, 0x9AEEB42B44FE2A05ULL, 0xD90BBEF94C9BA241ULL, 
            0xC4BA230ECAAEFB37ULL, 0xC927B698DD10D8B5ULL, 0x6547289B24C19A37ULL, 0xBDF780CA8A2EC0A8ULL, 
            0x3C70B74876F2435EULL, 0x5EB9D8F8DECAB7EEULL, 0xED4E4FA565A6A1C4ULL, 0x82622A3014C850CFULL, 
            0xD3CF56182CC4DAD1ULL, 0xB3682685B3CB1CB7ULL, 0xDB2C47FF7B8C2547ULL, 0x4ACDCC3BC6A926DAULL
        },
        {
            0xFAC66DC609DDC9DAULL, 0xB3A2C9DE0575966BULL, 0x230C243EC141E5BFULL, 0x33BB5B69C19F2396ULL, 
            0xB0F2BBB6847CEB59ULL, 0x9681974532253361ULL, 0x731B8AA69BAEAD28ULL, 0x7F5CDCF2FDEA83F5ULL, 
            0x6FAEDDD3801E2D1FULL, 0xF784CE4F57335478ULL, 0xEDBE8B94A5EED151ULL, 0xEDBC20A359615DC7ULL, 
            0x48883B17681CEFC2ULL, 0xE8FB59C97BFC0930ULL, 0x77234CFC7BC2C44CULL, 0xC04CCC5FA490A002ULL, 
            0x501AB1B0C97A6118ULL, 0xDBCDDD44067E0FC0ULL, 0xAB5CA1B913F09C94ULL, 0x561DB1D971C125C2ULL, 
            0x88A0B8D574668A93ULL, 0x259DCA10C0A84192ULL, 0x7D6818718185CFE2ULL, 0x749A1D6ACC0B36D3ULL, 
            0x232ACD3BE014A3ADULL, 0x05C4E866FA0E357EULL, 0x44970BD5330FD815ULL, 0x9970E96D3242A5BEULL, 
            0x90483C35D545BEFDULL, 0xF25BF7BF61FBFCDDULL, 0x4BE71B19A3A1CFC4ULL, 0xE9BC18B4933FD1A8ULL
        },
        {
            0x4C4E52FCD2938AD7ULL, 0xD4B8CCD6C62E103EULL, 0xC3ECE7DD91FABE11ULL, 0x2759AE5204C8477AULL, 
            0xCCAF1E045EF277BEULL, 0x552B8AEBBF629C43ULL, 0xE32E5CA5DEB56CE8ULL, 0x89051B00C01BF7FFULL, 
            0x69113EC18DE2E022ULL, 0x77D7C2AAEF088EE1ULL, 0xB462F8EE0A825B7EULL, 0x0C676670ECB3E506ULL, 
            0x37AB3190202C1E44ULL, 0xFC4F3BECE1A65637ULL, 0x4B82B9E3DE81495CULL, 0xDCDDAB8E96BE71B1ULL, 
            0xC89C4A4C8BB2A596ULL, 0x34A00F2152E17E2BULL, 0x00B37F8D36AB8ED7ULL, 0x0C8D6A3E160E6E2CULL, 
            0xF330EC8BF35C1DEEULL, 0xF3D94C5498F630C3ULL, 0x188BBA6FC48B15FEULL, 0x7B5CAD20A05D1104ULL, 
            0xDB1B9FCE79A86919ULL, 0xE6966CE0B4E93B10ULL, 0x130CB7E1FE4EF75DULL, 0xEDB443AD9DC59083ULL, 
            0xEB8B9F66426A4D5AULL, 0x9C54DFBA283CBE9DULL, 0xD8F58FBE51FDB53DULL, 0x65F6067271ABC96BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseFConstants = {
    0x02C9053B8DFC25DDULL,
    0x941672AE90C1D716ULL,
    0xD0D349E874452755ULL,
    0x02C9053B8DFC25DDULL,
    0x941672AE90C1D716ULL,
    0xD0D349E874452755ULL,
    0xEC8EF335187EA3D6ULL,
    0x9DECBA24255F5D95ULL,
    0x08,
    0x04,
    0x2F,
    0x4F,
    0x71,
    0x71,
    0xB8,
    0xFF
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseGSalts = {
    {
        {
            0x8C4B54B3E9D7BB76ULL, 0x231C8CBFD1A3CB31ULL, 0xA0EB69BD7146D844ULL, 0xD692D399388A621FULL, 
            0x625112A95A93D880ULL, 0x067966C8B09215ABULL, 0x1C9209459FB74E7DULL, 0x6927A79BC2C5E440ULL, 
            0x0A46E73AEBB23AA9ULL, 0xB247AF0230975112ULL, 0xC9CC04391CC1C012ULL, 0x276B3513D16B24E4ULL, 
            0x4E5AF7BA1C52D33BULL, 0x7F64DE34BC1BDD3DULL, 0x4E152C4A3D74E6B5ULL, 0x2B9FA63FA3231C29ULL, 
            0x471089FF5432B58BULL, 0x263108316B64F163ULL, 0x579F7C7B82A11FC4ULL, 0x6A05830E117261BDULL, 
            0x5DFB8F8B83BED032ULL, 0x7328EAFA31B9445BULL, 0x8C128471A0AE84EAULL, 0xA58FAC617866D44BULL, 
            0x1F624E2BF237011BULL, 0x57F7490669653663ULL, 0x3B12BF9F1BCED8D3ULL, 0xD08A8FA3FDCBD78DULL, 
            0x5E0BC282A3CC2384ULL, 0x7A041DB3C9D69A56ULL, 0x8A2819CA453D57E2ULL, 0xF95652BFEA3F8A15ULL
        },
        {
            0x0E685C8D325AA75CULL, 0x06812BEC47083459ULL, 0xBC52819350BB74FAULL, 0x8A5291063D4DA462ULL, 
            0xB109782E41A7AC76ULL, 0xC0E7EEB8B70A3B6DULL, 0xB1578C4180B04E8CULL, 0xD6B067EE47CB1D0EULL, 
            0xD58040876ED4D7A3ULL, 0x14D95470416B1D5DULL, 0xB14B96B9D840B63AULL, 0x2532D9DBB05D6550ULL, 
            0xDE5D05E4C2D6FAF7ULL, 0xF117BF44BF01B4FAULL, 0xBAADD7A0A949BEB7ULL, 0x171CD23BE9BD39E5ULL, 
            0xC9C1C4BAC9C6BBAAULL, 0x1C43A1292F1E5623ULL, 0xF9D8655F2842BA75ULL, 0x58E3AEB499A46B28ULL, 
            0x4A96104360056437ULL, 0x836F65FA6E215C4BULL, 0xC933D1C66301A8E0ULL, 0xC123AB1F4E216D60ULL, 
            0xDDA02ABF3DABAC6EULL, 0x7F3649ADDD7A4200ULL, 0x85C276B214B623D0ULL, 0x3EAF796647468969ULL, 
            0x207616FEC087D937ULL, 0x04BCF293AB1585CFULL, 0x3E7AD8378B5FC975ULL, 0xBD6773E6570403A4ULL
        },
        {
            0x436F30AB7DC23D8EULL, 0xA3789EB65547C2F3ULL, 0xF3F3DAEF672BD0B1ULL, 0x67EE62280D00A900ULL, 
            0x3AC1126B8BEDC950ULL, 0x943F397AEDDAE678ULL, 0x60C2F6A420795DB1ULL, 0x7D906843CACBEF39ULL, 
            0x003AFC4B5B7D89F5ULL, 0xDA759ACEFB6644D2ULL, 0x5C41E2FA93C8E7A8ULL, 0xC42B414A3577E549ULL, 
            0x76A77E397AB95D85ULL, 0xC78199A7FDB67D7DULL, 0x939905F96F31F993ULL, 0x188A10809422BE23ULL, 
            0xE7BEAE2A6A91E239ULL, 0xE1C093EEC32681C5ULL, 0x6F123BBB5ADD224BULL, 0x0633313B575712D1ULL, 
            0x04C2EC327E1E64F4ULL, 0x6D3CEAFFE9E49823ULL, 0x914AD1C148B46894ULL, 0xAFF2D545ED477F70ULL, 
            0xC5C0505E9F1DF8C9ULL, 0xDA522BF18747F098ULL, 0xEDCF19C8C60E1B81ULL, 0xB567418B6C6A129FULL, 
            0x83D73EF05E0F0430ULL, 0xED485F809D7262D4ULL, 0x019345C8F6ACFE44ULL, 0x88605670909B7359ULL
        },
        {
            0x82B7FB8CA4A6FB31ULL, 0xAB66A27E068D1FFBULL, 0xBE02AB01E848EC08ULL, 0x1C852E3B0E38468EULL, 
            0x3F922646B99437D4ULL, 0xA7EE711E5FF9A6A8ULL, 0x0610CC17F86185BEULL, 0x5955884EB8A8F08FULL, 
            0x33685E165BBDA753ULL, 0x9B90B9FB25D50CACULL, 0xC6F9EF1C0C89C68BULL, 0x18A0570753317CE5ULL, 
            0x8C25C2EB6658BE49ULL, 0x2B4799314E470229ULL, 0x48742869A524918FULL, 0x6F31B6994CCFE620ULL, 
            0x2CBDF4A8E02C0BB1ULL, 0xFA7FF082FD4F6D9CULL, 0x3D177BA27217A07FULL, 0x3372827F3A7D55FFULL, 
            0x8F42613709CA6D57ULL, 0x04BFA50BAFC7774FULL, 0x6488E9B28B2D5119ULL, 0xFC3D90A17BE35665ULL, 
            0xB7DCE2A4961BEBC9ULL, 0x9B06A957B6864D88ULL, 0xB247930A1BF3CE38ULL, 0xCF7732690544E0D3ULL, 
            0xED20769782EBE714ULL, 0xECFA6E644B62C8C0ULL, 0xA0DF9B10917D9495ULL, 0xE57FEFA1AABBB17CULL
        },
        {
            0x535D4CCC8A93E169ULL, 0x68D04C7C8D3BCD39ULL, 0x76B0352E5CD6562EULL, 0x7E07547998347050ULL, 
            0x504D8C54AD21E4B6ULL, 0x38F5EF7808A3C772ULL, 0xAB12B5DF58031564ULL, 0x999A8750309EFFC8ULL, 
            0x2A657F9F3D46557AULL, 0x328379A91A7943F1ULL, 0x811C5A81ECA26E60ULL, 0xACE38E923C87B854ULL, 
            0xAE26E696DD29E638ULL, 0xECB850BF28C0A9E0ULL, 0x9CC8693D13118CC0ULL, 0x1E3F7B8A1373ACD3ULL, 
            0x3BF7A219DAB6F831ULL, 0xED31F2671C38E14AULL, 0xB843FF19914E58E6ULL, 0x9E7A9A29CA320B59ULL, 
            0x1A0238292703F538ULL, 0x45376C39C5AD5578ULL, 0xF5ACDF0F3A9BEFE2ULL, 0x8AD8977CD4313482ULL, 
            0x6787A98014AECC11ULL, 0x7A6E2949FAC30708ULL, 0xA9AF11D0448CF703ULL, 0x6209851E4ECE6999ULL, 
            0xAE89776AF36BD188ULL, 0x0C423A1809E3A69EULL, 0x96E7F90B69D9017DULL, 0xA284CF242410358AULL
        },
        {
            0x265A2F6DA79C6265ULL, 0x5F0C749DD93F43A9ULL, 0x17B65A0485864A64ULL, 0xF07C50F214801D34ULL, 
            0x4A3E3C8B689E4AD2ULL, 0x78E3020F7E61F498ULL, 0xB3D7814334E8C644ULL, 0x7A72DD052368A0BDULL, 
            0x195B4063CBA696F1ULL, 0xD5DE59DD72826173ULL, 0x52081F5942310712ULL, 0x1CA7984F571EE008ULL, 
            0x5C8543E2B6D028B9ULL, 0x894819FCDA4527EFULL, 0x62E2385BFF53CA39ULL, 0x3CE22D516CA33F8AULL, 
            0x9F0C8B06115B6B92ULL, 0x444564B664F0A392ULL, 0x114737BBCF8CE800ULL, 0x2563EFFA6CA9DA7CULL, 
            0xEF3DEDF5C566C9DEULL, 0x7278C80703A50E4FULL, 0x16D992B5AFD72A73ULL, 0x0812407B29F7CE04ULL, 
            0x6FDA5BC65020AE01ULL, 0x1DA80F23F850E4D2ULL, 0x1E941828029D043EULL, 0x6A946887617F6699ULL, 
            0x349A7E9AAC5A5CFCULL, 0x4AE166FD516687FFULL, 0x2CF7130881855189ULL, 0x4D290B6B54DA42C7ULL
        }
    },
    {
        {
            0x4FC6E557F098630DULL, 0x6C6CA111C75F1656ULL, 0xA1ABE073DA5AF754ULL, 0x98AB99CCC7B7EC09ULL, 
            0x76CC468C70D692CBULL, 0x73EE264A2644047BULL, 0x3ED4D5ABA8A1CB03ULL, 0x9524A78E9C036CEBULL, 
            0xE175EC3F13DD3B88ULL, 0xAD28ED47090116B1ULL, 0x17D0B009DA1D8AFAULL, 0xBA6ACB89B2D0A36AULL, 
            0x40520272FE7DF78FULL, 0xCA3BD6B4DA6E599BULL, 0xF3264A32B73D3C8BULL, 0xC791EE8447B088CDULL, 
            0x2078054F4B7C7798ULL, 0x23C470EEDF497DABULL, 0xE763C8867872119EULL, 0x1CF7A60E132E70B7ULL, 
            0xB4C3056050A5A0A8ULL, 0x19902F8379209A2EULL, 0x7DE00A72680894A0ULL, 0xC449BE05480FC171ULL, 
            0x7D3CEFEFD9995158ULL, 0x8CA6738E544DD766ULL, 0x140A4576B93559CAULL, 0x63FFA8257F2A6BA8ULL, 
            0x68C2D9C7B8D5FB38ULL, 0xAAD1FBD4D12E94F2ULL, 0xFBBB457F818B5983ULL, 0x6596D74DA26A3C56ULL
        },
        {
            0x4FC2D7D99AE8A878ULL, 0xD73D705D2273BD96ULL, 0x50FE215B8B8CB7ADULL, 0x9C0B9F2855E7D74DULL, 
            0xF0C77763ABEA579AULL, 0x9A775DA8A8CF343FULL, 0xE2CA320FAAAC3B58ULL, 0x2486E910FE9EBBD8ULL, 
            0xBE5E6C2E60F51926ULL, 0x9C5F45766D694230ULL, 0x5888711F10B14002ULL, 0x3562116AF0B00C77ULL, 
            0x65D546618A36F0AEULL, 0x4C5B437164BA2B51ULL, 0x14FCEA6704FAE939ULL, 0x70CEF89543562844ULL, 
            0x54D428763A810F42ULL, 0x60168742AC18DA3AULL, 0xA457AC76A7DBA1F9ULL, 0x384891CCE29F5139ULL, 
            0x6D8F0EA5DEFF63E4ULL, 0x8781C3A66BAAD321ULL, 0xF1A9DC8964985C32ULL, 0x990FCA3370F33F07ULL, 
            0x1395655CA071C90DULL, 0x1DA0C8D5A235A83EULL, 0xF4D17A58D6D8506AULL, 0x6FBCB556FE913346ULL, 
            0x857F594594CDC059ULL, 0x33869A307BFF4899ULL, 0xEA13584154E0B5F1ULL, 0x566A45F9082F0CA1ULL
        },
        {
            0x5F668A3D62975E1BULL, 0x85C2F4930F30849EULL, 0xEF360277ED74F766ULL, 0xBF503F4035B9A63CULL, 
            0x01B6B43F0887A01FULL, 0xAE93748A2FA3119AULL, 0xDA3568A43F1B805CULL, 0xAB76C1286BD2D1F0ULL, 
            0x6A8369EF688906F0ULL, 0xA7D570B929763573ULL, 0xCF18786F51F6E8F1ULL, 0x63F2666281794B01ULL, 
            0x61BFD32B66068089ULL, 0x75F2BE365C495857ULL, 0x4B338FD66186DFD4ULL, 0x7BCF721056C274EBULL, 
            0x3B35FACDE023DACBULL, 0xB13C3B8F873DFCABULL, 0xECAD7F8C6A064E36ULL, 0x0016821BD1B86DADULL, 
            0xC702E26834660682ULL, 0x7845CCE77AAD736DULL, 0xCAA79E7B97CD48ABULL, 0x0674377446C78FAAULL, 
            0x49E38FF9F69393A6ULL, 0x7289A179860BC7A7ULL, 0x614D0CB495D2500BULL, 0x682FE46491276AE5ULL, 
            0xB1B8358929166105ULL, 0x6A3E07719B12E2E4ULL, 0x93332935D2577DE4ULL, 0x31D6B826BB51C5F1ULL
        },
        {
            0x0589481380E3DA25ULL, 0x9A03B20184DCB159ULL, 0x38B027D9C10864B5ULL, 0x7ADD6C3414E325F8ULL, 
            0xF92C1C4AD8EF2010ULL, 0xF9E02391EE0CA1AFULL, 0xF213A71634DE4FA7ULL, 0x75BA37BBECD55F88ULL, 
            0xA4633BF7AD2B43BCULL, 0x44A435375029D78DULL, 0xA7F0D6BFF59C967CULL, 0xD720049AB1506120ULL, 
            0x50561AC5A4FF8D17ULL, 0x628E76DC6885BFC7ULL, 0xC3119B55DFA55DF6ULL, 0xB778260C33FC14EDULL, 
            0xF5BC0D438BB5EA07ULL, 0x9BF3511F0FD40F74ULL, 0xA9D9EE5156817C52ULL, 0x4B2E9488BA6CB8ABULL, 
            0xFC9EBB4A92EE615AULL, 0xE8E2FC070576AE41ULL, 0x31D74E3C178996CFULL, 0xB9DDC9189ED99A56ULL, 
            0xECA33D0D57331E79ULL, 0xD16559A6E513B53BULL, 0xCFB98D82D97368B5ULL, 0xEE1F22432FEB4813ULL, 
            0xAB6526B0ECD1A61FULL, 0x532F5C40255E5C44ULL, 0x593E9E03478F3AFEULL, 0xDDF2DF39D6BA5E1BULL
        },
        {
            0x90BC0B1C5E085B06ULL, 0x626096E098F5870EULL, 0x119B99779309228AULL, 0x059847328E6A9D27ULL, 
            0xF720112BE37CCD8FULL, 0x061379A08C7D3E5DULL, 0x4CCC90BA3C9E1961ULL, 0xCFFA68C7E080A29AULL, 
            0x6682202E9FB64163ULL, 0x46BF839AD376FFDCULL, 0xD7FFC560045ED5E0ULL, 0x9E65F0301852EC68ULL, 
            0xCA48600188DC57CAULL, 0xFDB562F452764CB7ULL, 0x47E7DA724289A88BULL, 0x35EEC2E5EB91EDAEULL, 
            0xC4E50D247E0EE69FULL, 0x87C8E609BA19A03CULL, 0xB9F05679105FF944ULL, 0xD93D924831422B60ULL, 
            0xEEC30DC814E76DD8ULL, 0xC9D9E568447713B9ULL, 0x0C7CAD7E2DEA10C0ULL, 0xFF7FD9573221F26DULL, 
            0xAB889EE6359D3486ULL, 0x91E87E88239E4410ULL, 0x49F2C6027DAE4A32ULL, 0x0C7ADB65C31FF145ULL, 
            0xF6A91B0389F0902CULL, 0x1D0A13DD4DE0E232ULL, 0x86C03293FE53729BULL, 0xB4CAAEB0880E9EB4ULL
        },
        {
            0x880026099C73FD3EULL, 0x67A92E93E7D4CC34ULL, 0x4BF16360382ED96AULL, 0xCC2CBE36D13CEA93ULL, 
            0xBDB532571FF7BB88ULL, 0xC1570AAC1DFEAE29ULL, 0xDDB96640B67AD7CEULL, 0xE472C2A526206A8EULL, 
            0x99D3EB1EFAAFB825ULL, 0x8D12084E6CE671D7ULL, 0x08D9A997710DA85AULL, 0xD34BBA4530F53E98ULL, 
            0x57EFF9E053D9E883ULL, 0x71ED12304A96E72EULL, 0x085058EDB7211B2AULL, 0xCBE49C3694AF6B9DULL, 
            0x264E59B36ABFD61DULL, 0xB0CA22FD2FF8F33DULL, 0x6B0159BC25BA5BD0ULL, 0xBFC34B73132C0980ULL, 
            0xBCC820E9448D6A2DULL, 0xC44967543202FD29ULL, 0x2BFFF58E328F4490ULL, 0xD264B3C23F98BA0FULL, 
            0x2E1E23CC7685AEA1ULL, 0x5BCF92DB48EBCB13ULL, 0x56D1D3F57AEDB6EEULL, 0x2685187A89BD70ECULL, 
            0x07A7E601A7119095ULL, 0x9F1A72C6D92D3923ULL, 0x5813DCAE3E1919E1ULL, 0x12E9F5F3392109D0ULL
        }
    },
    {
        {
            0xBCE9245E853231EFULL, 0x25AA8440AB84842BULL, 0x63FC0A73A129521FULL, 0x10F666C732452F2BULL, 
            0x52C7D87EBBE162E4ULL, 0x5463BC58A967C736ULL, 0x63465A4ABF4C4A00ULL, 0x2B42BD64DE245714ULL, 
            0x3F50D6C3520F856BULL, 0xE469CC956E3B9A78ULL, 0x605D3838B683798CULL, 0x114FA5766A922E90ULL, 
            0x74D3C647AB2ADE5BULL, 0x99CF1F48EA30029EULL, 0xB8DA5E44A647FE3BULL, 0xF8180B0D2BD07B95ULL, 
            0x7E949D83B933E0F6ULL, 0x792994F9D8D66BA4ULL, 0xA09A58B23B7A9F2CULL, 0x9F12C9F14C36681FULL, 
            0xC1C4D223E4258566ULL, 0xCA8D50ADC1F75BACULL, 0xE6FC4BA240013C77ULL, 0x171D5580EB2F1B98ULL, 
            0x745B4FEDBD6E13AEULL, 0x6FE3762449C0AC12ULL, 0xF561FD7FBEF8B611ULL, 0x7BEB5944C020151AULL, 
            0xA59967D1E801E51BULL, 0x6D2E9FE1C4A57811ULL, 0xEC665A75733AB52DULL, 0x139B27D8A7F2D6B8ULL
        },
        {
            0x59F273054432EE0BULL, 0xD446A42E9F18B67FULL, 0x174FC3EE06E6B596ULL, 0x0B6C4F3BE5C4BC82ULL, 
            0x93603EC905B81346ULL, 0x8FE640AAC55F301CULL, 0xF8E9F9E4F81A7187ULL, 0xE1495DA14C562CECULL, 
            0xFD5DEDD0A928DD08ULL, 0xF2CB32AECCB281A0ULL, 0x7C0F9420EE3B5402ULL, 0xA6F384E18C6E2A83ULL, 
            0x99603CB7343BF4C8ULL, 0x567D2389411F758DULL, 0x3A320B09DFCCB8CEULL, 0xF653726A7B42DEB9ULL, 
            0xD66F7F1EA7105F26ULL, 0x9A76D21A05CF9206ULL, 0xEF0F84836C50D33BULL, 0x4A1E07CC11C6C61AULL, 
            0x30B5D8BDA8D1CC0CULL, 0x520D1AA9B8C6A258ULL, 0xCFD529D976390117ULL, 0x1973061EC7677806ULL, 
            0xE515C2068AF82EA5ULL, 0xB90803B4AD31B43FULL, 0x3CA0B1F89026087CULL, 0x1C26D566666EB8DCULL, 
            0x27513E9EF3F239D0ULL, 0x3E1E6C1347DF4C6FULL, 0xF36397DA10CAD1A4ULL, 0xCAF7CCA39299CEA0ULL
        },
        {
            0xED56901AC8C32A2EULL, 0xEC434BD39B937CAFULL, 0x7A9C43D34A69B0C9ULL, 0x157EB0A0E531A085ULL, 
            0x9E7516ED86907164ULL, 0x2FE8B9862D27A326ULL, 0x7E9DD3801B3217A6ULL, 0xFDB43DDA9DE2C007ULL, 
            0x5CE08976DC08233CULL, 0x388118A27FD51361ULL, 0xB39CA48C93FBA8EDULL, 0xB1A0BBDA69B5926BULL, 
            0xDFA387371F082089ULL, 0x3CBA33C624F1595AULL, 0x1E7F9B1C394A4B53ULL, 0x4AB9D8F3D53108BFULL, 
            0xF327379DB7394712ULL, 0x517921AFB50A4BD8ULL, 0x41DB1796BEF7A851ULL, 0xFEA36C376E68BD84ULL, 
            0xCD381C53CB15CCCFULL, 0xAFE1BF9D42CA3DECULL, 0xEA09989D8D963E12ULL, 0x7E69E6EE904113E5ULL, 
            0x26D09181C65E3B0AULL, 0x1BB9D46F44F353A3ULL, 0x18AD570F4A54687AULL, 0xE3691BD31EA82D15ULL, 
            0xF826C4B207197A97ULL, 0x2A40CEA15473157CULL, 0x77E6F20B50C75BF4ULL, 0x2B7D8493DD1F3043ULL
        },
        {
            0x54BF9027F4C1A5E9ULL, 0x6AAB676DC29FB762ULL, 0x4D4DC7A91000DC7DULL, 0x62F3CE33ABE27B29ULL, 
            0x9922D213D0F5A572ULL, 0xDC9A2BA70DBE628EULL, 0x8B8A58059AE0E7F3ULL, 0xF521F9DA74CEC2C1ULL, 
            0x215A1A01707694E5ULL, 0x714B285368556B20ULL, 0x9906BC87CF5CC1E5ULL, 0x57266E68232140EFULL, 
            0x422D21A0A377C6B1ULL, 0xE4AFE326E5B6C712ULL, 0xBC388AD10482F54EULL, 0x1277012E6C1B5759ULL, 
            0x3945BC9A5AED2B15ULL, 0x64030AFCF6D27D07ULL, 0xAE65381A93DA76FFULL, 0x3630CAB24C08B7A2ULL, 
            0xB6E398193085642BULL, 0x563CEFEED360CD80ULL, 0x4FABFDD2E2F6327BULL, 0x16D612DD923BFF5BULL, 
            0xB88E0898C8DB76C7ULL, 0x64D0640476A71C12ULL, 0xD8207DE6AFB08E2DULL, 0xEE935540A959CC05ULL, 
            0x24E787F3B268C789ULL, 0x5506B3285BC2F097ULL, 0x5FE22C9F2EA25EA2ULL, 0xDED158D78CA4CE9EULL
        },
        {
            0x04A77EC1A85BC58AULL, 0x4F5A2A96433765CCULL, 0xA266CDBC43107158ULL, 0x83EB6C1EBE350953ULL, 
            0x5909EB4C4CB80009ULL, 0xF54D8288220811ADULL, 0x8D36740999A241D9ULL, 0x36E5344D06D71DF1ULL, 
            0x55815F4ADE660BBAULL, 0x73538EFAAF100316ULL, 0x67CE4A5B62E8934CULL, 0x380FC86988E943AAULL, 
            0x48FDD448017D49ACULL, 0x74790CB0C72B2D4EULL, 0x60C8662326D07BC2ULL, 0xCEE69FB8464A3C5BULL, 
            0x00D757321F4CA051ULL, 0x0E8E5DBF2DE066AFULL, 0x929340F522BFE85DULL, 0xAABCC868DD48BB82ULL, 
            0xC7BB3A009EE4CF7DULL, 0x8D93CFA361783DCDULL, 0xF1E34822E649B098ULL, 0xD639D31D16AE7389ULL, 
            0x5B21CA21E854C7B2ULL, 0x6045FE0E06954C25ULL, 0xDDAC92272F566C65ULL, 0xA9ACBEF1F7BC08C6ULL, 
            0xE360A5C57D6A7FDEULL, 0xA30EC917B55754FEULL, 0xBCDC88FB74E23DCCULL, 0x0604C2650742E0D8ULL
        },
        {
            0x155A7D6AB116BABBULL, 0x14F36488B3970FB8ULL, 0x3C44B7FC19AFE50AULL, 0x69FC0792944F4D42ULL, 
            0xBD3F56FC2B005C54ULL, 0x601C6CC287C0670DULL, 0x23FB369E0DBC332AULL, 0x2A6F8CDD5B731C9EULL, 
            0x1245EF0A4A33D513ULL, 0x1015F42D994555B9ULL, 0xFC4112A03DEF56BCULL, 0xC64DFF6818975124ULL, 
            0xEE8CF90781AD9ED8ULL, 0xC409148A46969FCBULL, 0x9410AEB2D0D3AF60ULL, 0x50A8859624E6E13AULL, 
            0x245F10F8DE16A9DEULL, 0x405775A714411A4AULL, 0x70B4A62A043FD10FULL, 0xE13DB5E13186A0B0ULL, 
            0x7565B1B04B182AE4ULL, 0x930E9B4BFBD1AB63ULL, 0xFF9C59B9D825CA44ULL, 0xE7710A133666B32AULL, 
            0x0D9BF411779147F9ULL, 0x55FBB198D528A4F7ULL, 0xEB68692838245911ULL, 0xABCB3FC553A5CAF4ULL, 
            0x2B3816471A03DBD8ULL, 0xEEF2FEA43287D82DULL, 0xE253D7AA7649BE02ULL, 0x1A598DFFF38FF93CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseGConstants = {
    0xDE3456CE6B3776F5ULL,
    0xACEBBE0906D4976CULL,
    0x15CDE3CCEE6C314CULL,
    0xDE3456CE6B3776F5ULL,
    0xACEBBE0906D4976CULL,
    0x15CDE3CCEE6C314CULL,
    0x5E31F39C1DB534F2ULL,
    0xF84085FEEF71E172ULL,
    0xC1,
    0x57,
    0x68,
    0x64,
    0x10,
    0x65,
    0xC4,
    0x31
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseHSalts = {
    {
        {
            0x23000BB0928AE719ULL, 0x2AF8F4EC624A7116ULL, 0x7C348964558DCDC3ULL, 0x25AEB5439E3E798DULL, 
            0x9CB4EE236C580189ULL, 0xC9EA54B56A2F5611ULL, 0x4F1A4B36A9602C26ULL, 0xCEFA1757B055736BULL, 
            0x3948ABB9CFB4A6DCULL, 0x7578E92C04338203ULL, 0x77A91A9C7ED4F6F2ULL, 0x3588540250240DF2ULL, 
            0xE1FA7B5BA67ACC48ULL, 0x5D59E7CABA846F18ULL, 0xE7D408657EA61EF6ULL, 0x8040523410B46B05ULL, 
            0x71AAA07340B962E3ULL, 0xEB5A837A7DDF1155ULL, 0xACE1C0847885EDBFULL, 0x92763500A8661B4EULL, 
            0xA2E314765B645533ULL, 0x1D3878A3402DE282ULL, 0x3EDBCD1098F1B372ULL, 0x16D8D302B498C9B2ULL, 
            0x2C09F4C8FBBE8143ULL, 0x3E6F8C32C8031FC6ULL, 0xB5F487B77D6D7A5DULL, 0x323C794DDB93CA81ULL, 
            0xEE7A0A7176555972ULL, 0xCF1E33C5E712ED51ULL, 0x3EB32684FCCBD46DULL, 0x1640C671A3B4D3CBULL
        },
        {
            0x4B98B40FC361A28DULL, 0xBF781608E2BC2BE5ULL, 0x5C3BEF6A33881423ULL, 0x5423CCCBDA6C5F86ULL, 
            0x25FD4F608872E97AULL, 0x51F3DD0A05BAE28BULL, 0x0B475E90D4447B6BULL, 0x6BE202EF311961ACULL, 
            0x49805126FE2B526FULL, 0x21156D99E7042795ULL, 0x1C9EC5746E04AEBDULL, 0x81A0756928EFCBDBULL, 
            0x9F0CCDA9B4CD54EDULL, 0xDC2F152C605E2C27ULL, 0xC03D036EB4C65180ULL, 0xE5E38AF44426EC45ULL, 
            0xD21217A8949CABFEULL, 0xE11F6DF910F08744ULL, 0x38C5EC13FB9D45CEULL, 0xB5516C9C3A52E8B0ULL, 
            0x83FD46F3F3546A3AULL, 0x24958B93CA2884C4ULL, 0xECAB1B850D4EBAEFULL, 0x3F202C9452329281ULL, 
            0xB97AC90FB0DF0BA7ULL, 0xE21FB3D5FF09292EULL, 0x2C76A686AC26F8ECULL, 0xC3F545461BC68A10ULL, 
            0x80258640AC44D4B8ULL, 0xE61A4A4451588011ULL, 0x7543013094E28FC4ULL, 0x954FB2861A88B8CFULL
        },
        {
            0xB6B3A3B1C7A8E39CULL, 0x20518AA80E40E394ULL, 0x01F6867846567197ULL, 0xA8FF4D5F1830D9AAULL, 
            0x24469FF6711822B6ULL, 0x238075BD93903CA7ULL, 0xE0663809D9C06AADULL, 0x2C420B291ADA9853ULL, 
            0xCF7692E428F70BDBULL, 0x98A73240D7B640CCULL, 0x1FEA61A60DAF55E2ULL, 0xA910A501F5ACA8D5ULL, 
            0x1969B66688D36D11ULL, 0x08DA2054AC6B16F2ULL, 0x7271A9839F4F1289ULL, 0x8A23F96E3C69A29EULL, 
            0xEF29B628F37C5803ULL, 0x26D4D03D18FFB430ULL, 0xF95875CC3750F4DDULL, 0xAFA0AFEFB52A670EULL, 
            0xE9C02456E07BCECAULL, 0x87C22D77EF5BB6B2ULL, 0x6555B6B564E4E9CEULL, 0x11A2CCB765591186ULL, 
            0xBF4E920E9DC38ADDULL, 0x72248B51B75FCF2BULL, 0x059128F820243D01ULL, 0x2FDF7A616FD4EE47ULL, 
            0x29912F475564B9D9ULL, 0x1146656A3F35D847ULL, 0xB0B3A78F9F3876DFULL, 0x226B07D051E94C73ULL
        },
        {
            0x39E13794A06FF941ULL, 0x0D965243C3E8C2B3ULL, 0x2D66EF9D53952226ULL, 0x2C65F019D8AF4F7EULL, 
            0x5B264EDF04E393A4ULL, 0xDB1154F74F818284ULL, 0x19847A75D6F21EFBULL, 0xBF13A9508DF8AA55ULL, 
            0xDD41D1F52B816BB0ULL, 0x869657EDC4A87B32ULL, 0xB852F239E65A51E6ULL, 0xB6668FF1BC283AF7ULL, 
            0x5B028F8AB249EC27ULL, 0x171B2278F7E4B87BULL, 0xAC16725D619F8C61ULL, 0x1B0F4C43C88B7025ULL, 
            0xCD19CCA388365A65ULL, 0xFED1E66A5B0250ACULL, 0x447C5A695E6F109BULL, 0x066FF27290F6F0B3ULL, 
            0x06031C43207580C7ULL, 0xC1B86EE0FE69D79CULL, 0x24696B4A16745557ULL, 0xFB5CC8E192C2AEE8ULL, 
            0x14D33788E51FC60FULL, 0x2CDFF795939F705BULL, 0x4EAC640A45A7858FULL, 0xC56FD9095882D71FULL, 
            0xDD897F20AB858150ULL, 0xADE3E204F5704CECULL, 0xF8D0E9F45B9587B4ULL, 0x9E541B1A04696146ULL
        },
        {
            0x5C7FE5BFF4F7FEEAULL, 0x454385C03AC9C68CULL, 0x29C20A3A12DFEF6CULL, 0x595D4420665720D0ULL, 
            0xAA6D47A725499B53ULL, 0xDD81AFCCD9B68407ULL, 0x4524185A7BC20F19ULL, 0x4F3FAC3B45FB2A89ULL, 
            0xBDB3ED00783E5568ULL, 0x499DB51FC13157DCULL, 0x0186F7974CD713D6ULL, 0x85414CDAFBC71658ULL, 
            0xBBF79472FA603BECULL, 0x1FF2602C5AC5AF23ULL, 0xFD5A1F2F2B3A06A1ULL, 0xA1E0CF6ECAC5E25FULL, 
            0xBAB86719A564C9C3ULL, 0xC43CFA1B59876B5EULL, 0x7E126F4714532F96ULL, 0x5488B5F54683F721ULL, 
            0xBE623B72DD8978F6ULL, 0xF2358F2D9B79DF12ULL, 0x4C7D3C6152391E46ULL, 0x7E448173116E0783ULL, 
            0x886325BB70698D90ULL, 0xC1D92819296B84E6ULL, 0x0A6E9475BD208AB3ULL, 0xDFE0507B60A4263AULL, 
            0xF1AF452487629E76ULL, 0x7E30CBD1DA59FE00ULL, 0x483AA01DDC50561FULL, 0x8210C7FDD3B98ECDULL
        },
        {
            0x5FCCE58D70C004DCULL, 0x20779F15DB5C2D47ULL, 0x79DECA9E8F9CAF1DULL, 0xCDAAC519D12B0F5FULL, 
            0xB8ADC1FA06EF462EULL, 0xACAA45456B7F2479ULL, 0x65D186BF47F388A4ULL, 0xCCAC19F33CA9B9DCULL, 
            0xD949632C9FE3A023ULL, 0x4D0297271748192BULL, 0x8F753A7729F9C20FULL, 0xA2B163DAA3B87A2CULL, 
            0xE1164B8DB771D877ULL, 0xB204E330A224D2D5ULL, 0x304BAB397A1B0EAEULL, 0x79274DA9E580F804ULL, 
            0xA12B6A8CD292B723ULL, 0x3050352E84E38BA7ULL, 0x1153A64F36B1A915ULL, 0xA4336C247A3A2FCEULL, 
            0xCDC1722D42C4FB4DULL, 0xA30848381549AA19ULL, 0xDCEC98596DF5A7F2ULL, 0x6097A19D24A1C9C8ULL, 
            0x7310D060CA459B45ULL, 0xE8C8240B05C86E62ULL, 0xA46CC87569B82AB5ULL, 0x6D7AE135654173BEULL, 
            0x9855D0ED4CE5EB65ULL, 0xBE3DD7C83D7A7CD5ULL, 0xAF6D334CBDE82C0AULL, 0xB66DE271B6AD311DULL
        }
    },
    {
        {
            0x2ECD9E7A2C6F3B43ULL, 0xF9255C2874F4AC6BULL, 0xC43C01FC43D38365ULL, 0x093EB77927EC611CULL, 
            0xE9288BABA5510661ULL, 0x03F9E12E73A2A0F7ULL, 0x82E5928EF2894B92ULL, 0x0C7882D7319B373DULL, 
            0x326F6EA4E612608BULL, 0x8DFF9C4719D2D797ULL, 0xD98159E00C5FA112ULL, 0xA1C567766D5DEEF6ULL, 
            0x8B7E0F1DD6246CD6ULL, 0xFE8794F7B6D30136ULL, 0xEB449D2B1C41500BULL, 0xC41EE10A33B4F85BULL, 
            0x9372062DA5A4BCBBULL, 0x98F17ADCAF79380CULL, 0x27BFAFE7ADD36F87ULL, 0x9B306C50051FFE6EULL, 
            0x974D6263C4085030ULL, 0x88A0C95B418D9796ULL, 0xA0CCAB2FE8336F1BULL, 0x122437B7936538F5ULL, 
            0xDF11B7CE88B2EA35ULL, 0x15C8CEDC1B18B26EULL, 0xB62114A77439873FULL, 0x4B8AE098908B12F7ULL, 
            0x1794CD9C1E98EADAULL, 0x3B3DB231089C0295ULL, 0xB0197BB9FF14793DULL, 0xCBE5A242BCC6A37BULL
        },
        {
            0x2C4B4C5B51FC51E4ULL, 0xD48AFB68921BA371ULL, 0x016587E15887B159ULL, 0x36398943C036049FULL, 
            0xB3EA02BF597AC109ULL, 0xAB05E58E0A404D92ULL, 0x13B595D82C2C3872ULL, 0xE84ECAE7CAE81457ULL, 
            0xD2D81340C183E518ULL, 0x0917E8E9FA14F8FFULL, 0x1C757C8A8BFF2BE1ULL, 0xC50363A5691A7E82ULL, 
            0xDF2E6A95BA954B96ULL, 0x634239C99A21E0F9ULL, 0x81A322CE5CD54EA3ULL, 0x61722677EC52ED1EULL, 
            0x16D74E970828219CULL, 0xCF3325A171F5AA07ULL, 0x45E582B8B81BB390ULL, 0xBA066E09DEE793EBULL, 
            0xB58CE17371D5840EULL, 0x96FBB3D64A3F7F3EULL, 0x246AAED4C53444FAULL, 0x285DADA350E23B50ULL, 
            0x23A38B8ECD3C20C7ULL, 0x2407555E7AE3AF18ULL, 0xA060EA8FE52C2C30ULL, 0x7C576AE3BFAD7AC5ULL, 
            0x67CB3AC0B90AE1C6ULL, 0x083650CB3F6E801DULL, 0x5C2A40FB99E3F4E3ULL, 0x8A75FD5C1F230943ULL
        },
        {
            0xF51EDF64B3F08FD9ULL, 0x42CB232DCB6E98B5ULL, 0xD8D16E617EFB22D8ULL, 0x04F0CCD2486356C4ULL, 
            0xDF20ABA24AF5DA35ULL, 0x4F1709EDF45DF53BULL, 0x8BF897C1D0E360D5ULL, 0x47EE58738453BDCFULL, 
            0x002044865AE42644ULL, 0x244495F58166580EULL, 0x2BBFB62E813F90CAULL, 0x4495724AD8F26A26ULL, 
            0x7D562369653E9235ULL, 0x75FCBA8E64B41372ULL, 0x8F739A8AE498405BULL, 0xD15AC3113818449FULL, 
            0xA919645BF96B0ACBULL, 0x08AD6A950F789591ULL, 0xB4DA7A006F65F41CULL, 0x2723CF6189F7F607ULL, 
            0x275BE5B85E8C04C6ULL, 0xF48D7E02D0BC9BB3ULL, 0xF342A23EB6CEE0DBULL, 0xEEE3BCD7BEE4EEB0ULL, 
            0xBAC8BC374FFD5986ULL, 0xEB2F3E8CABA8B757ULL, 0xB46AFE47ADB87B04ULL, 0xBF773CD6EA66A966ULL, 
            0xE39945E471B4AEBCULL, 0x170A6E71CAC4DDF5ULL, 0x94477994698B6E7CULL, 0x895401863F39E281ULL
        },
        {
            0x7F5D53AA4736C046ULL, 0x86AC97D0ED09D765ULL, 0xCC13E7E51ABFC7D4ULL, 0xAE528C135C117745ULL, 
            0xB4114B0A7ADF7CF0ULL, 0x19124C94136838E8ULL, 0x47A1395177172770ULL, 0xE21D1685EB3ADFD5ULL, 
            0x4E5C5688A96CD9F6ULL, 0x96384FD5168C84CBULL, 0x985CA6CEB3D05B8CULL, 0x0CF635A12005C24DULL, 
            0x91C448152E92D810ULL, 0x269C23F7C5969866ULL, 0x6D2AF6288A4A5B98ULL, 0xD18D8D758BD10A44ULL, 
            0x6075F25CAE5F2137ULL, 0x2E68F3B22EEB3EA4ULL, 0x5C6A832EDCA04A39ULL, 0x3A29914619539ED6ULL, 
            0x8B2A43B4A6DDD09BULL, 0xE6ED2AB79C51FAC0ULL, 0x120C6B10F8E142D4ULL, 0xFBC64057C4FEC816ULL, 
            0x6DDF16CBB849395BULL, 0x40670A3DB750FDD0ULL, 0xE18C2748C8860666ULL, 0x0C6B0E2E2E97563FULL, 
            0xD0CA328EFF3708F1ULL, 0x3B114CA1C40483FCULL, 0xC8D2C9FD8BE98A0BULL, 0x4449EFB55BC8EF06ULL
        },
        {
            0x6425AB983D18667BULL, 0x6C625330094F4924ULL, 0x123A6D07CDFBC24BULL, 0xC4FFAA1AABF630BEULL, 
            0x4B856E8EDF77125EULL, 0xF61135C0511E3841ULL, 0xC00F15094E07A516ULL, 0x126A8AA124D5F5FFULL, 
            0x54CBD14A602681EBULL, 0xEA3098C93B668ED0ULL, 0x074B1E97BB14786EULL, 0x8740C7377140FAE3ULL, 
            0x253618803609AFEEULL, 0x2D7BB2E545C98DF2ULL, 0xA64B321440901681ULL, 0xFEFB8D469C7EDD81ULL, 
            0xE5620B28E75972C4ULL, 0x28445EA98575EB87ULL, 0xEC36371663D814C8ULL, 0xC874A7D4F3714828ULL, 
            0x2A36B6D23BD2D067ULL, 0x8566A4E0059D2D13ULL, 0xB84B7B473B7351C1ULL, 0x97864FD9B02AEDB9ULL, 
            0x7C171239811E242EULL, 0xBB2A83D2BE09DF4BULL, 0xF962210CC16E038DULL, 0xD01FCBD0FE2B88FFULL, 
            0x4B7D8A35A203B731ULL, 0x393EC57B1726E7DAULL, 0xBC2A22E263B65526ULL, 0x2DC9D85C696CE8D7ULL
        },
        {
            0x8DC131380B670AA6ULL, 0xAE3733A77300186EULL, 0x57C05CE93BBB5E75ULL, 0xD524CA8F1F194212ULL, 
            0xB5ECB1DC52E94625ULL, 0x7D568F4044E07E72ULL, 0x93C563F2D3B70D6AULL, 0xB8BC5E646EC58D3CULL, 
            0x75E5D21821A841D6ULL, 0xEAC1AFD265718978ULL, 0xF902A5F45858FC3EULL, 0x9FB944039E0C92E2ULL, 
            0x3284ECC6797D6FC9ULL, 0xBC8AF6E9E2CAA369ULL, 0x1FB65A91C6CEA104ULL, 0x36F1A6F6E1B1BE5AULL, 
            0x2DA0C56E8EC62392ULL, 0x1C5CEEEF200B596CULL, 0xF4D17D9BEB75038FULL, 0x93CB7D12E28BBAC7ULL, 
            0x2BEF57723AE77198ULL, 0xAD015F418EF4522EULL, 0x31A164BEA041278DULL, 0xAEE847BB5548804EULL, 
            0x6899EE8D6C5E7877ULL, 0x37D9859398714B5DULL, 0xE7FB3A6459D1F585ULL, 0x0E85618BB4A8AF63ULL, 
            0xF3E09F5290F4FCEDULL, 0x43B0B8A822F6A08AULL, 0xE8F959F46F050AFEULL, 0x43CA4B8CDC69286CULL
        }
    },
    {
        {
            0x524F1EEAEC909C4FULL, 0x0731A5D967C0D0BAULL, 0x95BA779E40A9075AULL, 0xC81A840BE0816540ULL, 
            0xE15C5A49DBE7DF26ULL, 0x94BCAF518332E780ULL, 0x77F4F265F72D3746ULL, 0x6F0F0EA875EB7CC9ULL, 
            0xB7ABB9750956534AULL, 0x315A876E9488F153ULL, 0x7324E42D9F50BBF0ULL, 0x68D6C2C7D9F0463FULL, 
            0x6DE2DFAFCA564FA0ULL, 0x621B7103DA5149D4ULL, 0x70048A83A441796AULL, 0xD78D0D369AC67C5EULL, 
            0xD81789FBBF614165ULL, 0xF9399CA3A4B6B57CULL, 0xD7F214C12E06A8E3ULL, 0x179E39DF4FE5613AULL, 
            0xB8C0A03EA7AA3788ULL, 0x0C6C6104E7CE85E7ULL, 0xB103C43AC9C28FFEULL, 0x3651AED3E8BC50ACULL, 
            0xAF9DB988E2A2A29BULL, 0xBD39A935E4ABCEEAULL, 0x60325C36294C9309ULL, 0x48B3503167579D90ULL, 
            0x391C04BB5EE7D79FULL, 0x7DAC71E532210002ULL, 0x92E2F376B82812FDULL, 0x4A274F685A258A7CULL
        },
        {
            0x87B89E2C645B562BULL, 0x4C3D446A600DC4C4ULL, 0x56F96047B6DD6541ULL, 0x9E99F58677806823ULL, 
            0x8E32A078F66E1836ULL, 0x4DF3A2374212E9D3ULL, 0xD3D18C0761996920ULL, 0x3B38E9EEC1BFF5C1ULL, 
            0x182661B157DEFF70ULL, 0x5D14C5BED1041871ULL, 0x44CB331AD9E2D252ULL, 0xF6D904FA0FCC6CCBULL, 
            0xF89AF316243EEAF1ULL, 0x2ED05BCF74DD7C77ULL, 0x5E74628F6E458A10ULL, 0x0A8DC641BB963420ULL, 
            0xB2F02929F22A1D7FULL, 0x5BF8D617B51A846FULL, 0xDB8704E7DD43C2ECULL, 0x271EAB3E4BA82A9FULL, 
            0x7D284A05A4D1B884ULL, 0x7E7D1EBEAADB0054ULL, 0x4657969265899BDCULL, 0xC8B359E3B32B5F60ULL, 
            0x58F8B251FFAA89EEULL, 0x7B397E26C574B364ULL, 0xFA41CCAE1888D22DULL, 0x48E6289139203D48ULL, 
            0xEF9E136F36724B31ULL, 0xEDF0092B7ADAF96BULL, 0x3E69A2F77089B37DULL, 0xEB229C59498E735BULL
        },
        {
            0xF233E6ABA97EC573ULL, 0xD52BEB787FC528F2ULL, 0x47E42C196BB87D87ULL, 0x172B85482539A429ULL, 
            0x78B6BACEF5EF1B64ULL, 0xC7FC343AC1F9ED34ULL, 0x8ABE921369673239ULL, 0xBCDC300175EBF444ULL, 
            0x2FAB5870B1821280ULL, 0xE91F4454837662D2ULL, 0x525F454D61CE004BULL, 0x3C451E48B0A0D7F5ULL, 
            0x7154649A16351025ULL, 0xCDDF171E0439DD86ULL, 0x1B87C1A6A9DCEE33ULL, 0xF670C89977E9B17FULL, 
            0x0EB25ABC1FBC0430ULL, 0xCB6D649C8E09B6CAULL, 0x14D7508C1478C345ULL, 0x326FE87A28D1E8A4ULL, 
            0xBD6017B8581EE587ULL, 0x6F9D6A5C3EDCD285ULL, 0x3B241FC379409406ULL, 0x7550848BA4A0A334ULL, 
            0xEED8280BC481E8A3ULL, 0x712B68FA9743AB2DULL, 0x65DD3B253AE9AB7FULL, 0x3B347CA521A322E4ULL, 
            0x6AB907E6B85BC050ULL, 0x3C9DF26D82551204ULL, 0xA7ECD62AE115CB22ULL, 0x1685D9CC705EA78EULL
        },
        {
            0x2DDE396D60630EA1ULL, 0x89CC1B746DD8AE96ULL, 0x7923D206C3B0DEC3ULL, 0x20D408B2D8E3F4DAULL, 
            0x9615D3D815ED8023ULL, 0xB47A26E6DA980A9CULL, 0x8A2570117DB335D2ULL, 0x231C05D32D0A2710ULL, 
            0xCAD62E104FA834BFULL, 0x33BCD618812A3928ULL, 0x4C1EE236C3E8F55FULL, 0xEE1943E652670C40ULL, 
            0x1AFA50AEF0996FC2ULL, 0x9056E49C462D958FULL, 0x53FB245770A035BDULL, 0xC7AE0AE4FE52A5FDULL, 
            0x683192923C0EC917ULL, 0x2976DCD9932B25F2ULL, 0xB3DF9EBAFF0FD936ULL, 0x32AA0C21D76D2B74ULL, 
            0x6A407BD69159AAA4ULL, 0x0EEACF43B810307EULL, 0x5CC453FB0508024AULL, 0x13FFC70E40439FE4ULL, 
            0xB5B6103BDE6B59C9ULL, 0x59D9D6BEF61FEC19ULL, 0x7F5785A2DCF548B7ULL, 0xBEA3FBFE75AA44F8ULL, 
            0xADD50888A0333B1AULL, 0x4B0BE88945C93764ULL, 0xFFF4E99C5E0B02ECULL, 0x979A4CFCC9AAB395ULL
        },
        {
            0x438B50F003CC0072ULL, 0x47F22F7EFB3D6BD8ULL, 0x2A3DB38A268827F1ULL, 0xDF344ED53693C0D6ULL, 
            0x61241D63734E2D06ULL, 0x5F80A72FA724918BULL, 0x630AF16F8DDED2CFULL, 0x9F54E61471DD3032ULL, 
            0xA6BBA3B97368894EULL, 0x871C1953785DD3EDULL, 0x2DCA6448163FB801ULL, 0x41F2CA5FD5D4484AULL, 
            0x88EE081A30F5FEA3ULL, 0x41CEA3DEE4E75772ULL, 0x2847C4B2292BAF7EULL, 0xF094869D43302986ULL, 
            0xE0859F013B4B122AULL, 0xDB3E6864A3C71C1AULL, 0x80FEC02510D52589ULL, 0x8D329ADF96D7332BULL, 
            0xC1BF9179E03B865FULL, 0x4219F29DF5DB44CFULL, 0x0D986869ADD940AFULL, 0x2AF5788EFEC63EF5ULL, 
            0xB6C55F7C0A23787CULL, 0x9A0667A2C5DF0C0EULL, 0x1958514D20A529EEULL, 0x9C25475A99CC45D2ULL, 
            0x204A92EAF2A3BFDEULL, 0xBC3F9E79FA054433ULL, 0x4C271AB512F34A0CULL, 0xD35903AEDD970C68ULL
        },
        {
            0x65A398449D00D7C9ULL, 0xF57CAE2BA42E0997ULL, 0x01293D7D898D6C82ULL, 0xE7BB5F31EB3E93BBULL, 
            0x9C219E1BEE976822ULL, 0x88DE3D27182BCA2AULL, 0x18966736C0960ED2ULL, 0x55967FE9AADFBF7FULL, 
            0x7B20A7EDBEB8A96EULL, 0xFF1D270957DE20AEULL, 0xD576A8F62CEA0007ULL, 0x1670DD4CEFFFD0A8ULL, 
            0x1FB10DFA268C0D37ULL, 0xD381F6291DABD4DCULL, 0x5EB475333FE056D9ULL, 0x8D529748370B4C35ULL, 
            0xF97DA11012662867ULL, 0xDBA1654AA3E85996ULL, 0xE2F4A3C4077A18E4ULL, 0x70E1D48CE64C28DCULL, 
            0x2FBF017B959371A2ULL, 0xAF4A40A27A773194ULL, 0x2E95B3D25A5CE2EAULL, 0x3D75881DD5065D1BULL, 
            0xC44F3A40C77514A2ULL, 0xFBB1B1F34522836EULL, 0x6A509F1EA2B44D59ULL, 0x73F611C433972EBCULL, 
            0x4650D78B9C0BFB2CULL, 0xE3683EE6E71D343CULL, 0x4E28873B0B6D728EULL, 0x4CD5A6BF6E154703ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseHConstants = {
    0x64380265F0B6B1A0ULL,
    0x05162F0DE45D047EULL,
    0x72B56FA27D66CD91ULL,
    0x64380265F0B6B1A0ULL,
    0x05162F0DE45D047EULL,
    0x72B56FA27D66CD91ULL,
    0xEE04F103CE73D530ULL,
    0xB1C7A6F0CE325136ULL,
    0x22,
    0xD8,
    0x21,
    0xD3,
    0xE9,
    0x53,
    0x9D,
    0xFF
};

