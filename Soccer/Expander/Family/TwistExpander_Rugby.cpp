#include "TwistExpander_Rugby.hpp"
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

TwistExpander_Rugby::TwistExpander_Rugby()
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

void TwistExpander_Rugby::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC1145C4B788B85DEULL; std::uint64_t aIngress = 0xED11D730E5FF4ADFULL; std::uint64_t aCarry = 0xA246259E42FB2A93ULL;

    std::uint64_t aWandererA = 0x9061962298B71BABULL; std::uint64_t aWandererB = 0xB0D13B98534FB6F2ULL; std::uint64_t aWandererC = 0xD59DCC88AF0C8B2BULL; std::uint64_t aWandererD = 0xEE476651E4FFFB34ULL;
    std::uint64_t aWandererE = 0xB4322965BFAA4573ULL; std::uint64_t aWandererF = 0xDC6CB59631C5AB97ULL; std::uint64_t aWandererG = 0xFF41B5DE1AC0B7FDULL; std::uint64_t aWandererH = 0x8CD8B79C95F8A640ULL;
    std::uint64_t aWandererI = 0xC628F65CDAA73073ULL; std::uint64_t aWandererJ = 0xEDC4C353E88EEAD6ULL; std::uint64_t aWandererK = 0x9FCEE59B71E90ED9ULL;

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
        aPrevious = 17558854576244013721U;
        aCarry = 12167010378507973063U;
        aWandererA = 15744647403384885502U;
        aWandererB = 18399002571195202701U;
        aWandererC = 14529685059335983382U;
        aWandererD = 13423747799831267382U;
        aWandererE = 17410490912427676720U;
        aWandererF = 14768913138529476533U;
        aWandererG = 15187819733825070206U;
        aWandererH = 15975168552086759231U;
        aWandererI = 9833478936047590324U;
        aWandererJ = 14727572754342524865U;
        aWandererK = 15548392617346206442U;
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
    TwistExpander_Rugby_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Rugby::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xE5BB45711BDACC5DULL; std::uint64_t aIngress = 0xA2FAAB168ED5C8A1ULL; std::uint64_t aCarry = 0xF15C5A877845760CULL;

    std::uint64_t aWandererA = 0x94D30945A5A15012ULL; std::uint64_t aWandererB = 0xFE4D9D56E4B7A119ULL; std::uint64_t aWandererC = 0xAA56C41CC33D3443ULL; std::uint64_t aWandererD = 0xB271137E0B991B60ULL;
    std::uint64_t aWandererE = 0xA78162349FC2ACDEULL; std::uint64_t aWandererF = 0xAD18AD45787032E0ULL; std::uint64_t aWandererG = 0xF2C12B7D082AC063ULL; std::uint64_t aWandererH = 0x97DFF8ADEBCFA042ULL;
    std::uint64_t aWandererI = 0xE0A8FB1C646A7225ULL; std::uint64_t aWandererJ = 0xB23D461B71D2D67EULL; std::uint64_t aWandererK = 0xEE9AD183BC2EE16DULL;

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
        aPrevious = 14980222378220630993U;
        aCarry = 16227339264621612548U;
        aWandererA = 12062536569259737962U;
        aWandererB = 17165832526547375478U;
        aWandererC = 15226328542508794314U;
        aWandererD = 16486334482013522660U;
        aWandererE = 11854759151010426719U;
        aWandererF = 11841345424257171610U;
        aWandererG = 11771669248537361400U;
        aWandererH = 13507988956177601167U;
        aWandererI = 10316522524315355405U;
        aWandererJ = 12405633618370838034U;
        aWandererK = 12086269595982908038U;
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
    TwistExpander_Rugby_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Rugby_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Rugby::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x82079C3FB5CB5300ULL;
    std::uint64_t aIngress = 0xC3E1823392A6988FULL;
    std::uint64_t aCarry = 0xEC16108C018EB8AAULL;

    std::uint64_t aWandererA = 0xD5BA16BCA2B20959ULL;
    std::uint64_t aWandererB = 0xFE6B9DC148BC635AULL;
    std::uint64_t aWandererC = 0x957DACAFDACDF4D7ULL;
    std::uint64_t aWandererD = 0xB988355EB5615B5AULL;
    std::uint64_t aWandererE = 0xD09CFF7D44A5DCD6ULL;
    std::uint64_t aWandererF = 0xE700D92EB5646DC9ULL;
    std::uint64_t aWandererG = 0xF38C9C785F449F99ULL;
    std::uint64_t aWandererH = 0xE0A8F9F17C3EB24FULL;
    std::uint64_t aWandererI = 0xC4715BB259355A0EULL;
    std::uint64_t aWandererJ = 0xFE9D4B840276E582ULL;
    std::uint64_t aWandererK = 0x94A4A6BDB78FB7E8ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Rugby_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Rugby::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Rugby::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB9F7622C2EA6246BULL; std::uint64_t aIngress = 0xB4BE56D3A2DA903FULL; std::uint64_t aCarry = 0xE28E7FB079E8037BULL;

    std::uint64_t aWandererA = 0xA2C1913FE367A42DULL; std::uint64_t aWandererB = 0xD68E94BC0EC42ED4ULL; std::uint64_t aWandererC = 0xFA184622DF099563ULL; std::uint64_t aWandererD = 0xC983E3898C03A6F9ULL;
    std::uint64_t aWandererE = 0xF6A693C37EFCE295ULL; std::uint64_t aWandererF = 0x94271D8F2687EF3DULL; std::uint64_t aWandererG = 0xF49EED2C680303B3ULL; std::uint64_t aWandererH = 0x9A3214A4A8F44619ULL;
    std::uint64_t aWandererI = 0xE4C86772425A9AE3ULL; std::uint64_t aWandererJ = 0xB4C1DA6A1D544350ULL; std::uint64_t aWandererK = 0xB203717169F7162FULL;

    // [seed]
    {
        aPrevious = 17745858590499599145U;
        aCarry = 14887051080725434124U;
        aWandererA = 13640432112052628262U;
        aWandererB = 14181085616206984923U;
        aWandererC = 16064627609547611676U;
        aWandererD = 13114022687098692204U;
        aWandererE = 15972206095388371130U;
        aWandererF = 10661102134498364819U;
        aWandererG = 17602490628762099024U;
        aWandererH = 17328970506077342367U;
        aWandererI = 15184964944677160505U;
        aWandererJ = 12906153725652011482U;
        aWandererK = 17156569280467837824U;
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
    TwistExpander_Rugby_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Rugby_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Rugby_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Rugby_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Rugby::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 2, 0 with offsets 6377U, 1569U, 2238U, 4739U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6377U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1569U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2238U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4739U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 1 with offsets 2767U, 3479U, 1028U, 1207U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2767U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3479U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1028U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1207U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 3, 2 with offsets 125U, 958U, 3491U, 3976U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 125U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 958U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3491U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3976U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 3 with offsets 800U, 2873U, 257U, 3753U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 800U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2873U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 257U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3753U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 3, 1 with offsets 1982U, 90U, 679U, 825U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1982U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 90U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 679U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 1025U, 1725U, 1832U, 1838U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1025U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1725U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1832U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1838U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 3, 2 with offsets 656U, 529U, 4U, 1337U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 529U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1337U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 1, 2 with offsets 1995U, 1702U, 1614U, 1775U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1995U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1702U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1614U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1775U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 815U, 787U, 1350U, 16U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 815U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 787U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1350U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 16U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Rugby::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 3, 1 with offsets 2507U, 682U, 624U, 4828U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2507U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 682U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 624U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4828U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 2 with offsets 1358U, 294U, 5692U, 2639U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1358U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 294U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5692U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2639U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 0 with offsets 8126U, 3264U, 3222U, 6279U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3264U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3222U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6279U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 3 with offsets 5167U, 4264U, 7497U, 200U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5167U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4264U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7497U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 200U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4021U, 6602U, 3492U, 334U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4021U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6602U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3492U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 334U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1187U, 1868U, 437U, 7U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1187U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1868U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 437U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 7U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1097U, 315U, 1234U, 1546U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1097U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 315U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1234U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1546U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1978U, 278U, 513U, 1872U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1978U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 278U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 513U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1872U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1789U, 1759U, 569U, 282U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1789U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 569U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 282U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 1, 3 [0..<W_KEY]
        // offsets: 204U, 317U, 1783U, 651U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 204U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 317U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1783U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 651U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseASalts = {
    {
        {
            0x9465ECA6893DBE1FULL, 0xF21823078A179CCBULL, 0x2599DF1EA000B4DAULL, 0x79B0A171C0CDFE4AULL, 
            0xD31BF139C3323769ULL, 0xA9AD96B92FC9A3A4ULL, 0x789E668C7E52E5A0ULL, 0x8171A9368F53A001ULL, 
            0x8E5E00812E893838ULL, 0x7D758A6AD8D0A3E3ULL, 0xDDCF50BAA3BABC26ULL, 0xF2FA02BF6AEC1431ULL, 
            0x67CF348875D2BFC2ULL, 0xE270A337DD23B0F7ULL, 0xB802553761173BDAULL, 0x67C638F38F4C6E41ULL, 
            0x61812D2000CB7CC4ULL, 0xCA6BCF36E9C3A003ULL, 0x7435BCC0982D6BFDULL, 0xC09CA2E1D5F0FFB6ULL, 
            0x693E7E0E2E7EB035ULL, 0xF0F74DA989369565ULL, 0x8A227049C3287576ULL, 0xEE5FBEE5F7745676ULL, 
            0x4544CD07D0B13864ULL, 0x2E7BD76EC9935FEEULL, 0xCE01ADDEF603F88DULL, 0x93AD51CF81FA4E69ULL, 
            0x52D8A40D1B017243ULL, 0xA07682A489D3E858ULL, 0x933D1957C3A4C9D3ULL, 0xAC8F4A531B4CEF3BULL
        },
        {
            0x9C1BA5BB9C0BD5C2ULL, 0x1C45CEC6158CCD41ULL, 0x70C512B9BAB59DBAULL, 0x2B247F7B33697802ULL, 
            0xA13BBA3F38A821A5ULL, 0xBD05F57D79FB5E2CULL, 0x09569A52E54B057AULL, 0x551444C1B242022AULL, 
            0xC8D9695521F0DDF3ULL, 0xE8B807C4707353A5ULL, 0x7E8C545128249E15ULL, 0x5D43E3F2E3CC805FULL, 
            0xD5BD7E08B6CACECBULL, 0x9546C2D4577D60FBULL, 0x8C4C5B474088D5F6ULL, 0x4AF1712D865D967CULL, 
            0x264EA0FEA64E9B1BULL, 0x3E4CDF234DE37BD4ULL, 0x1155D54EBC54CE9FULL, 0xE14BF182A5426FFAULL, 
            0xDA44C97E13716A93ULL, 0xDF8C46E7A66F2A47ULL, 0xF9437D4F078FB6CBULL, 0x1795BC8DD7537A74ULL, 
            0x58C55200F012A6FEULL, 0xB4E042335141294EULL, 0x7F8D214D76AE9224ULL, 0x27011ED298722F37ULL, 
            0x9082F78E6D412721ULL, 0xFF157CA09879B01FULL, 0x07975C8A7DD8E32CULL, 0x98440C027A1F9D7CULL
        },
        {
            0xD8415FD266831801ULL, 0xA1DA0702CC0B86D1ULL, 0x066357C392CF1B55ULL, 0x5D72F851F82BF6C9ULL, 
            0x7D87CC7E1FA14B2BULL, 0x762DE5C032184582ULL, 0xEA21CE6C2C351389ULL, 0x326EBE96347A7898ULL, 
            0x457E74F85A8DF201ULL, 0xE7B2ED1F7CB53AEFULL, 0x686522F40DCB20BAULL, 0x6399D9584881BC20ULL, 
            0x1905C5C9D06F2F47ULL, 0xFE35428E071A7BD7ULL, 0x59C3221C6145513DULL, 0x735AD10E0B2CAC19ULL, 
            0x54F0E07D5156FD3DULL, 0x050FC9722D9D6C60ULL, 0xA4689DEAB0DF24A7ULL, 0x044803EECAFC26DCULL, 
            0xA45809C432555BC7ULL, 0xD434A7A6C7491E8CULL, 0x5F4494E86BD4FC6CULL, 0x0C59A52FF2892448ULL, 
            0x3E28BBBC17CF70F6ULL, 0x4B25ACF04897171CULL, 0x65EA5A5DE201B247ULL, 0x5806DB6E24C6D55DULL, 
            0x75FFD192D10C4118ULL, 0x191BF05A4EF4D550ULL, 0xE88EB8F7542A7860ULL, 0x7B07EFF0EE7E34E5ULL
        },
        {
            0x546C8346028AEBC9ULL, 0xF3318F3B3B9F4804ULL, 0x01FE1C209FC332FAULL, 0xF3F525D649ADCC5FULL, 
            0x9945DC031978CDB9ULL, 0x313F1023F22B8768ULL, 0x0422D9D19FAF8373ULL, 0x01C8A77893396119ULL, 
            0x3BF1DA973E359A42ULL, 0xE85407716DFC6801ULL, 0xE24341E1DD3F3C14ULL, 0xB18EA4886B052FAAULL, 
            0xCE8773932B5C9383ULL, 0x8313FF99AD4B74CCULL, 0x9BCA0A6BB94FC359ULL, 0xC4251220DBBE6BB6ULL, 
            0x2A106E0C970CA4DFULL, 0xA1080852928FBB39ULL, 0x2BC2754510B37103ULL, 0x16DAA036006FF0B3ULL, 
            0x8050F130C5CFB61DULL, 0x70CFF0EB74558FA9ULL, 0xFBD15F0C163C39DEULL, 0x9F81514E53E8BF3AULL, 
            0xE881DF287C429AC9ULL, 0xEB0F4409354EAA08ULL, 0xEC61B9F570A0314BULL, 0x5BBAD47B37EF54BAULL, 
            0xD34E8EB97446F7A0ULL, 0x9E36748958FF46E6ULL, 0xF1C4B02EE50C0CE4ULL, 0x5A0DAE856741AFFEULL
        },
        {
            0x140FEE1BDFEFB0BBULL, 0x3CADDF4DEA1AB4D4ULL, 0x50C784C71D12F139ULL, 0x6BEF53A896765E2AULL, 
            0x41B07B7B514E897DULL, 0x852EC33F9045B84EULL, 0x6081E823F6B46BEAULL, 0xFCF5A67A22947751ULL, 
            0xCE6E05B5CFDFBDACULL, 0x7F266F8A53F1C071ULL, 0xB3E9EEB0A0C80651ULL, 0x0D95623E29EBC00CULL, 
            0x6D9C67B6F87B8AF3ULL, 0x75C4A18A2877A2A1ULL, 0x2AEE5B66ED732E58ULL, 0x04EF050BE5CA65A3ULL, 
            0xE57EC96E5EC44867ULL, 0x10A454B9261AC308ULL, 0x695C88C8A197A782ULL, 0x73D86EE62C4D5F6EULL, 
            0x0EA04F9CF942F278ULL, 0x9BF84ABAD456D600ULL, 0xE0385A085155F4ACULL, 0x0B889F04AADB4D98ULL, 
            0x2E55E08BC196F503ULL, 0x5BF9DAFA9C139372ULL, 0x690F904B17C7CECFULL, 0xFE357C43E1821D79ULL, 
            0xFC1817F7C1A59B4FULL, 0x09E9E3543EA2744AULL, 0xBE7A15B1DB035230ULL, 0xE12822E6DFEF5525ULL
        },
        {
            0x92EE1827497138C2ULL, 0x4EB21DED2BDD3320ULL, 0xA6596981AF5AFF7FULL, 0x7200181457D91188ULL, 
            0x81C2FDDCFABD9C2EULL, 0x45C0A9BC41DE7F5BULL, 0xD8933F5996C68B54ULL, 0xF9A6384B93A894AFULL, 
            0xC06344B2A62952EFULL, 0x17F7358B0B8B21A6ULL, 0xE6A0C693A76511EDULL, 0x34BB628DB5DB3800ULL, 
            0x9057A3ED736FCC78ULL, 0x1536317C3CFC6258ULL, 0x72E6025E8B1484EBULL, 0x251F195C0A720F14ULL, 
            0x98FC7628BB513C1BULL, 0xECACC7D933893C01ULL, 0x27D593C361475C12ULL, 0x3CDE845D1462433FULL, 
            0xA3515065A48B554FULL, 0x8AD540E28AD42154ULL, 0xBE66F1053C4CC3E4ULL, 0xB177C312DE66CBEEULL, 
            0x30B9B45D226B3F09ULL, 0x45241BFC2902608CULL, 0x3F158CE3B5B98F17ULL, 0x78BDF221F62E1CACULL, 
            0xCFA59CE6AC04449FULL, 0x59303D299F26585DULL, 0x46485CB4D0BF113EULL, 0x0288C304ADEA12C4ULL
        }
    },
    {
        {
            0x5F420277BC8D0BC8ULL, 0xABF25A517D8610C8ULL, 0x7F65796CB4998109ULL, 0x7A933F6851D23E2DULL, 
            0xAD3C637186CC9C9DULL, 0xE3EDA6E55771EF39ULL, 0xF2C65AFF62120BA5ULL, 0xFBD9376BC3B3F166ULL, 
            0xACA740D37B5BEA52ULL, 0x5E57DBD76395D703ULL, 0x708077FD041E7A97ULL, 0xE8D2AA625900B8E7ULL, 
            0xE4D2F5890FE11452ULL, 0xC4855BEE58367823ULL, 0x710F7631E276B6A5ULL, 0x116809EF18F5EA3CULL, 
            0x78376A2D97987A13ULL, 0x731CB4A9ED817E47ULL, 0x0264105B6C824AABULL, 0xFBAADB3531B424C7ULL, 
            0x840E53142B5DE3CCULL, 0x0871E753DDB6D721ULL, 0x63CD7E3DBD51394CULL, 0x44C5338CA8778934ULL, 
            0xD6921D77505D0935ULL, 0x8D54BD42E492309DULL, 0x3B1CDAAB79A5FC35ULL, 0xC8007B9B866759DAULL, 
            0x4DB072DA2221DC85ULL, 0x9F5C04BF43BCC04BULL, 0xD1B75CE0F515CC8DULL, 0xE1F71E00A5E4B821ULL
        },
        {
            0x63C560E36C4F9B1FULL, 0x96F4965131E66813ULL, 0x3A415A926DC16385ULL, 0xD4307ACAB5BCFE8DULL, 
            0x21D2E10DA11B44ABULL, 0x031B9AB43354163EULL, 0x5FBC12B3F4522314ULL, 0x449D2DAECAC0ED9EULL, 
            0xAB1EE6DE380A18B5ULL, 0xC2AF942F88C8BC50ULL, 0xACFDF22966FEB33FULL, 0x268A426769647ADCULL, 
            0xE193D442FF96008BULL, 0x81E8B08574D4DF43ULL, 0x4F8ADFC1A124E24DULL, 0x9FE6C2623DE88104ULL, 
            0x12EB33A5294FDBCDULL, 0x69CCFBA4C2B03AF4ULL, 0x6C512A6EA75BE4FEULL, 0x8F5E71DF9CB7BBE0ULL, 
            0x38855ADD7688958CULL, 0x316A7769A17DA39BULL, 0xE5AE946AD5E552A4ULL, 0x593796A9020F185BULL, 
            0x62EFF74FC1DDAB4AULL, 0x60E3D3C237AD915EULL, 0x51A28EF39E87FC87ULL, 0x5BC74982D8F45636ULL, 
            0x9266194448A5B5B6ULL, 0xF5568583EDD50839ULL, 0xFDBFA21422C828B8ULL, 0x973A14FB521641D3ULL
        },
        {
            0x90EC70D3B51F9816ULL, 0x28D0B2F220064D5EULL, 0x16E7BD2A0242AA53ULL, 0xB2B69D4074DD0A0DULL, 
            0x8C1CBD4B411B66EEULL, 0xF187A5D2E8EB222DULL, 0x65359B6996B62EF2ULL, 0x5ED6A5BE7F14E5B7ULL, 
            0xC4CD211D4D7F0E9CULL, 0x789CC82747622DA1ULL, 0x77D7A364641DE486ULL, 0x0EBAA72C78E5D6CAULL, 
            0x7318DDFA80926ACBULL, 0x621E126FC25789A8ULL, 0x2990472A8DB50F2DULL, 0x80B5740A4B6EB50EULL, 
            0x515A50107F592955ULL, 0x1D49E0536B15BC20ULL, 0xE3D1A26E8971A5F1ULL, 0xF25159939B92B9BEULL, 
            0x2BEFB2C005A1BBD6ULL, 0x8657C795A3880556ULL, 0x7111758895CFBC8DULL, 0x48D5DCEA50D6A955ULL, 
            0xD44ADE8387C503F6ULL, 0xEA6A34AAE9532DD0ULL, 0x20B08A224F7DDB74ULL, 0xBD1C03A24CA3BA3BULL, 
            0x59F5FC97DA435D4BULL, 0xA398186D6DC68ACDULL, 0x2EC9D96CA7330A87ULL, 0xDA6E8EB356785E72ULL
        },
        {
            0xFC2AEB20DAFFA780ULL, 0x4348F3E8A1502FAFULL, 0x0C4393B5A7B91FD8ULL, 0x82CACB8B0C2C14DEULL, 
            0xFF31ABCB7F1D695AULL, 0x7B843E648D8B3047ULL, 0x8AC6337648090F7CULL, 0xBCB3D4ACD700D449ULL, 
            0x09B5BDAA363A0AFAULL, 0xE7E35B9767E600D3ULL, 0xC39E41270B660C32ULL, 0xC112D42E86244713ULL, 
            0x1F372567C8A9F64BULL, 0xF4048EC93B4CB9DBULL, 0x817B6354627AE4FCULL, 0x928B76035A32831FULL, 
            0xBB97D87DFD88D05AULL, 0x311EF56414461DF4ULL, 0x1E1B81C6CC6B8D65ULL, 0xCD41C1510D3884C9ULL, 
            0x4DC17DB41660F530ULL, 0x5BF1BE0CD1851E5AULL, 0x39F4DCDDE03FDF8AULL, 0xA71DBC2348A4DD71ULL, 
            0x55B9F80B4F443230ULL, 0x5B4AEC448F82A34BULL, 0xB18B9266E5AA6019ULL, 0xB40E225F5BC23E78ULL, 
            0x790E9BC57C12D930ULL, 0x356DB1BBA91F6988ULL, 0x079A21DC13B28A18ULL, 0xBBE85776BD9219F9ULL
        },
        {
            0xA1790BCA0B1A6FA9ULL, 0xF312CE64897E41F4ULL, 0x40436E73433E07FFULL, 0x6601141645FFAA61ULL, 
            0x0A91D8AF8A846679ULL, 0xB6CB38A940A6D71FULL, 0x93D1E92957F6490BULL, 0xD134F08AC3FE99EFULL, 
            0x6A743962B31C8A0AULL, 0x694B2138CA54B5DAULL, 0x55ABA853D115E315ULL, 0x91EB4F8BC0A3F3DEULL, 
            0x57EE9C8CE90EF76DULL, 0x95428E09D1C52690ULL, 0x1D88E85BF96C9E98ULL, 0x9731F0A9342787D0ULL, 
            0x42A6D032C68BBEB9ULL, 0x613CB04254FC7E97ULL, 0x67CA3B53D62799DAULL, 0x7009AAE330A5F108ULL, 
            0x8057BF1420B0B2E9ULL, 0xFE6ED9557ECBC87FULL, 0x72063D27344DE0E7ULL, 0xCFF2A67E179B4441ULL, 
            0xA6C06B9320CED22AULL, 0xB89DB45ED80CA11EULL, 0x04DAB1DB3DBD8414ULL, 0x9E46191FF03FD938ULL, 
            0xAEFC0C29143081E5ULL, 0x4846987987307206ULL, 0x90C7627CD72D62B1ULL, 0x3D51B9375EE755D9ULL
        },
        {
            0xF4BE731CFA36DF25ULL, 0x6F07799AFC89BA4AULL, 0xC0B00701DCD3CEFDULL, 0x5A6CB4AE07BEF83DULL, 
            0x73CDC9DA4EF9D4DEULL, 0x415CA3F3C433B18FULL, 0xBDCB6666D1700695ULL, 0x05B30BE22CBAE26EULL, 
            0xFBD75EDE28A0EF0CULL, 0x9D7D9A5FA1BB9118ULL, 0x3AC58C042169DD41ULL, 0xC97F056DECDEE44FULL, 
            0xB7CF539D396C4262ULL, 0x8CEF57364AF98FAFULL, 0x6208AB4CA4D7A302ULL, 0xE376D6370B8E1FEAULL, 
            0x070EE6B1F48D6D91ULL, 0x093BE3FBD590B7ABULL, 0x6021032409DCA045ULL, 0xC524663A0276B6ACULL, 
            0xBF6EB1359A0D2F0BULL, 0x66660EBE60F31315ULL, 0xF11CD2C54162DD3AULL, 0x6EF38A4067B9AC6AULL, 
            0x9DCF08DB7B5BD936ULL, 0x4CEEBE6E5DD16B44ULL, 0xC1A74A9FFAE30D94ULL, 0xDB3BE82E0967C2A9ULL, 
            0x816F3F5876E5C744ULL, 0x44FE39F23AAA9A91ULL, 0xE0165014E3F81B90ULL, 0xB985D87E28BD1FC0ULL
        }
    },
    {
        {
            0xDA40A35CDA387A46ULL, 0x294A77E60E7CF79FULL, 0x1236CE1D5C3872B4ULL, 0xFA0830ADDFBBD2A5ULL, 
            0x680EE015C3A3D611ULL, 0x241E12EB68139B3AULL, 0x7F9CEF20A2E068C6ULL, 0x81902913EE1FEC25ULL, 
            0x0163781EB6B02264ULL, 0xE5A4B8F44D431BA4ULL, 0xD7DB45D82AB9A003ULL, 0x5C270141E33B01CAULL, 
            0xD626135856DCE01DULL, 0x9A1AEF2F3D7D4828ULL, 0xD6CC4EE991735E09ULL, 0x3919F62754ABCA64ULL, 
            0x04787256F2F20D46ULL, 0x84C44BF8D620AF7FULL, 0xC2FDB6A745C7555FULL, 0x8B7FEF232AA40DD7ULL, 
            0xAA0957D57FBA11A4ULL, 0x4FD59113C20A6436ULL, 0x9FD191A9A0D37B7FULL, 0x75F18675B891EB49ULL, 
            0xA9D479918C2F69E9ULL, 0xBA94304E49CB4CEEULL, 0x5FBA511F098BB275ULL, 0xA77F7F47A2B0214EULL, 
            0x388DB013BFED6117ULL, 0x7C3B9D48C2962040ULL, 0x09B54D002320AD59ULL, 0x168D9C30751F43EFULL
        },
        {
            0xD51FB78ED471BC28ULL, 0x963079F7FE5B9864ULL, 0x2965991912A0FAFCULL, 0xF688B85046F35556ULL, 
            0x4DE1F2FCBB43D3D9ULL, 0x53223636FB5BCEA3ULL, 0x3F8A7EB8B2E8F05CULL, 0xC3C6620C8E31DA80ULL, 
            0x8F48854AA60FB6D1ULL, 0x44C41222A6A2BD7EULL, 0x08474342789151ABULL, 0xEF9686B64D3BEEE8ULL, 
            0xA71175F4029678DEULL, 0xF7685F0726F30663ULL, 0x0103F246EE182482ULL, 0x9002345A2E31852EULL, 
            0x1ADB130530270326ULL, 0x7D98F1D1E18768E0ULL, 0x45054390A94E500FULL, 0x915806863BB00048ULL, 
            0x607C4B000879D416ULL, 0x27E5F316ADBB2AD4ULL, 0xC4131CAB99D9B14EULL, 0x898FEFAE00E504E0ULL, 
            0x8042056FD41C5201ULL, 0x69C45BF4B91D11E5ULL, 0x3A5459DB1483B5BFULL, 0x23B7E076552EC1B8ULL, 
            0x9E09607C726AEF37ULL, 0xD63EC45E3215D394ULL, 0x2DBF743C993E8E79ULL, 0xA226CDF9A5DCEC4FULL
        },
        {
            0x5DA9933DFF841E02ULL, 0x8119268554DBC485ULL, 0xC869BE48E080BACEULL, 0x076277D6CFB628C2ULL, 
            0x7F2C76B6F4D7C12BULL, 0x3698D5C1F6FD70A8ULL, 0x0FB120D4BA30C810ULL, 0x92B17802956791FFULL, 
            0xE73BB5D353AE8BF1ULL, 0xFABC57A90F0CAF84ULL, 0x1CCB25B4E58C6B2BULL, 0x41D02CCA78C86631ULL, 
            0xC0B27AFE0F66987FULL, 0x7EEBCD4B4129F767ULL, 0x22978FF4EE1D9171ULL, 0xC60C5CEBA9722C72ULL, 
            0x6277EFE6454352D1ULL, 0x084DB0FA85DB08F4ULL, 0x26294F55EB317416ULL, 0xBF86CBBA6530F479ULL, 
            0xB0703F82A145A0B2ULL, 0x4085D76932FA2384ULL, 0x034E0F084C81CC27ULL, 0x63CF8FBE9085CA9FULL, 
            0x9071E48168E628FBULL, 0xD26F44D836384A1CULL, 0xC460EC197F36E94EULL, 0xB1F37F5DDE1639EDULL, 
            0xBE31CD149850F91AULL, 0x01D3F645D6856DADULL, 0xA4CD36EEEF4D01C0ULL, 0xA3593BC4BAD7E8A0ULL
        },
        {
            0x5ACF9CE995B037E0ULL, 0x3506E2F7F9644567ULL, 0x5569CD604DC120EFULL, 0x4BE04D38A992C5F6ULL, 
            0xE8896D2BECC373D6ULL, 0x7A411A40606D8190ULL, 0x90ECFBA30D965248ULL, 0x3D48A982A4E6E951ULL, 
            0x28D6A8DC4930D596ULL, 0xB83F1DE2F94A619BULL, 0x99CFB07D77CA0BC4ULL, 0xCE621A92523B3A7EULL, 
            0xAB13E8202248A012ULL, 0x44C7DAF59BDAC9E2ULL, 0x742210D58DEF1FF1ULL, 0x161A2D12C886D5B6ULL, 
            0xC12726135D741049ULL, 0xF3A9A09C960D9011ULL, 0x7DDA3ED7BA65E7E4ULL, 0xAE7B9BA249BE1BC0ULL, 
            0x6769E5BF2AA56168ULL, 0x4EAD13CFAF259352ULL, 0xE9CDE641D59A5521ULL, 0xBA9BF63A8B75595AULL, 
            0xE94A11D436E46714ULL, 0x0EEEF90A70E4023BULL, 0xE30539799BBAB73BULL, 0xCB37895873466212ULL, 
            0xEE17BD8EF0DC6FF7ULL, 0x22DB724452863BEAULL, 0x28259D7F7CD0F6B2ULL, 0x6FD66410180BFDACULL
        },
        {
            0x1D2EB65D140A6098ULL, 0xC1042FEEE331C136ULL, 0x70C006EC473E047DULL, 0xC8C8D93D321CB42DULL, 
            0x520ACA7820D7909FULL, 0x3C2F9506C05DE52EULL, 0xEBBDF0891E56B671ULL, 0xC5603266BDC59B46ULL, 
            0x6A04C3FF3384AB45ULL, 0x65CBDFED5EDDE0A5ULL, 0xC711A5E05BF896C3ULL, 0xF444736E62EB9542ULL, 
            0xEF10B92D3ADDCF89ULL, 0xDB3D9E3A2D4994C3ULL, 0xC932945DEE70A1ACULL, 0x6BD64E44AA3E9804ULL, 
            0x67701432AED12EF5ULL, 0xDBBF96A29B10243AULL, 0x5BE53B40E86B8427ULL, 0xC1BDEF1EA5404F71ULL, 
            0x209FB36E051E6EF5ULL, 0xF1E6E7E226F5A974ULL, 0x54BBF6C3F78360D0ULL, 0xDC38C458F2A268DFULL, 
            0xE81B83CA26CBB58CULL, 0xA7A9E5F6513F50D6ULL, 0x033BA8396C8B80A5ULL, 0x905E7D2025BDAB3AULL, 
            0x0A0052316BDF5736ULL, 0x86FB0ED28C20690DULL, 0xDA685E285F3CB943ULL, 0x082DA97A05A4CA52ULL
        },
        {
            0xEE8D018106B89528ULL, 0x8D01153CED0DF779ULL, 0x095D9C5D0771EE59ULL, 0xF1AD53D2ECA5562FULL, 
            0x4C85F623423BC8FDULL, 0xD93148E2F5E087E4ULL, 0x189669D71FBEB05EULL, 0x3564626FB93AB692ULL, 
            0xAE755114FED5B6D9ULL, 0xBE54F56480CD1C34ULL, 0x57ADFA2AC41DACA2ULL, 0xEFB101D30B7510CAULL, 
            0x7A0EFD0876A69306ULL, 0xC0896AE6B40F9B5CULL, 0xB26EAEE673227939ULL, 0x4E411AF19F58C6E5ULL, 
            0x708BC6772CCB9C16ULL, 0xC30AF5628C7BE60DULL, 0x1903E01A16725D13ULL, 0xF85355F6089F9DEAULL, 
            0xD8F62E56FD7403B9ULL, 0x87643DA5A7A04D63ULL, 0x132940F6A4298841ULL, 0xF337C2C2AAED88B0ULL, 
            0x6BC4D0E6040990EEULL, 0xB03472EE919BED37ULL, 0x6096E8EFC3BC8C3CULL, 0x6846A35517E93170ULL, 
            0xFD54A3242594B084ULL, 0x1FA2B83E19E1F797ULL, 0x6AA9E63D1C07C6EBULL, 0x4B93CB3E30CC4FE8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseAConstants = {
    0xF7713F38E52C2459ULL,
    0x17E5B1C4559CF20DULL,
    0x1592EA7CF9414DBFULL,
    0xF7713F38E52C2459ULL,
    0x17E5B1C4559CF20DULL,
    0x1592EA7CF9414DBFULL,
    0x96C64FDF51C5DCC3ULL,
    0x99FD8333DF9073B5ULL,
    0x90,
    0x4D,
    0x91,
    0x6F,
    0xA8,
    0x9D,
    0x6B,
    0x19
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseBSalts = {
    {
        {
            0x16AEA4C50F40836DULL, 0x5BB7B72E49C5DFDEULL, 0x725AD7FF1A057929ULL, 0x2BE9C40A4D84AC33ULL, 
            0x123FB50ECBBFB615ULL, 0x0206A0907239894DULL, 0x9E40F35463DB5FB7ULL, 0xD510741AF94C90B4ULL, 
            0x1FF0CAEC762F1E95ULL, 0xC95AEBA7F2311FA5ULL, 0xF7BE6D559D8C1C02ULL, 0x72025CD5CA9DA5B2ULL, 
            0xC65BD943D3E4D6C2ULL, 0x97EF605A6228E865ULL, 0x9ECD7AFFC94B47FFULL, 0x3345D7C692078F7AULL, 
            0x9FC675D99DE0D7D9ULL, 0xFE5A8A6313EC7036ULL, 0x4FF233BF6801DD71ULL, 0x7EBFFBE957F3154EULL, 
            0x5E50F7DCC5C58E3AULL, 0xBD4FF4ED69615ADAULL, 0xBE3D236CDA135621ULL, 0x1FF81D4993390F56ULL, 
            0x00919BFD8BD9D626ULL, 0x0CB4EDCE06C8AC80ULL, 0x59DC0901413FA9E7ULL, 0x98DEA3D9AFEA108AULL, 
            0x56582D421713647EULL, 0xB668EB629EFE49D7ULL, 0xD704195CDFC2AE0AULL, 0x8E52BFE1FD757DA0ULL
        },
        {
            0xC06634F1AF706707ULL, 0xFB243846CB768C55ULL, 0xC749D6E6B5AC47F6ULL, 0x8DA914B64C404F58ULL, 
            0x9E06AB788F9FAC42ULL, 0xC193795E4083208AULL, 0x120BA664D234426FULL, 0xA9E069CAC910782BULL, 
            0x14BA9B8AA346C7B8ULL, 0xF7BBFB80C5D1A166ULL, 0xCA9809027893EE70ULL, 0xE8ACA2FEE8F5D7F0ULL, 
            0xE1ECE6074D333200ULL, 0x67B1101D73081E58ULL, 0x55CAC0D0BBABDFAEULL, 0xB9F0C48B28235075ULL, 
            0xFE7A3475DEEFB00EULL, 0x0D105A078B4A278EULL, 0xBAD3AE85D49A7E63ULL, 0xA1F7B73A2742EF8BULL, 
            0xBD0B4E9D05369468ULL, 0xF0681E3E84EB8A41ULL, 0xF1D34E62BCE06C68ULL, 0xEB4FD2398671D620ULL, 
            0xA4D8D287C42505E4ULL, 0x2AA29BB507AF3828ULL, 0xDC06F610FD363B50ULL, 0xD49B7E6E5BCF3C1BULL, 
            0x5F1B5C328F0F5453ULL, 0xAC9EC4465AD3ADECULL, 0x6E21D07A2E75BE8BULL, 0x62370EA5B274583DULL
        },
        {
            0x114E27342E5A00FAULL, 0xD33ECFFF4BAD1077ULL, 0xA8E40E7977A660FBULL, 0x9477D362A1CC6963ULL, 
            0x8720DB974C09DE70ULL, 0xACE43052B7D96E4AULL, 0x3701E3EFE00D29EBULL, 0xF1D3E096D708A2FBULL, 
            0x4615734AFFB93A55ULL, 0xCD8A7A4C892E63D3ULL, 0x34AA8784BF864373ULL, 0x17727BA5C6536BB9ULL, 
            0x97C9901075037B4CULL, 0x96272F8B5FD45919ULL, 0x0DF7524254E28FC6ULL, 0x83ECA9BF6129AE52ULL, 
            0x38C612B2376DF5C9ULL, 0x75067E40D6BD122CULL, 0xECD4D53F63B35419ULL, 0xD379A36C5CEB8AA2ULL, 
            0x1C374E37527A30ECULL, 0xF421999AC0B25A51ULL, 0x13FA38FF93E36A83ULL, 0xD0E3574E4B1D59DFULL, 
            0x20069AFD320266A7ULL, 0xC6EE2980B9372185ULL, 0xBD49D3B989E0CB54ULL, 0xED8B147E860320A5ULL, 
            0x3A3D1D7767CC40F7ULL, 0xB8F08F8C4830F844ULL, 0x500B14BE84578116ULL, 0xA81426B30ECA53BCULL
        },
        {
            0x0FAA455638FADC23ULL, 0x065957353895AD30ULL, 0x84E78A04DDFF0D8BULL, 0xB05AA334EEA13B7FULL, 
            0x2994178E3E8561C7ULL, 0xD909FA9B8F7AFC80ULL, 0xA919366F99B9AD40ULL, 0xDAD22DB637F25F78ULL, 
            0x0F33909E2F9315DAULL, 0xE885FC641DF57570ULL, 0x5BF15314ED7BE529ULL, 0xA5BC310605FFC2B6ULL, 
            0x9627DFD4DEF9A357ULL, 0xDA46D114A21A2C5AULL, 0x99D7B7657904A927ULL, 0x5FC4691FDC0B1173ULL, 
            0x06413156B55AB4FFULL, 0x6C268D8AE753EDAEULL, 0x6E76091863FD682FULL, 0xF5B3B112CA7DB8F2ULL, 
            0x03BE7F803FD51B98ULL, 0x407D471E5E44051BULL, 0xF6329575FC694816ULL, 0x512EB35373041AC3ULL, 
            0x0C6DA3DAAEFA28AEULL, 0x213891A75368548CULL, 0xBE97A94520411DA2ULL, 0x9F6CF9FDF1769605ULL, 
            0x02A7B1769D26EA3CULL, 0xB10C58F40CEC0E66ULL, 0x2100405F7624E09CULL, 0xF419133BB22CD74CULL
        },
        {
            0x1925A9A9545BF9EBULL, 0xAEE0BD811CDF398AULL, 0xA72360C5173F832DULL, 0x887FFFE1CE3476EFULL, 
            0x81F9945B831B2016ULL, 0xC4BE590B5C57A233ULL, 0x251339A52BBF7F94ULL, 0x4728627EA9CE9A2AULL, 
            0x501E0F6C2FF6147DULL, 0xE97E5D2C35CEA463ULL, 0x9279EEC90D952701ULL, 0xD34F88F12D4426BCULL, 
            0x4D59700AE0936E7EULL, 0x54D29C075FD23594ULL, 0xBBAA9CFDADE8438CULL, 0xF231EB1CA076BE0EULL, 
            0xBC4A3E74CE873062ULL, 0x35EA81B47BE4E992ULL, 0x7E0B4CD5CBFC99B9ULL, 0x4A7AC629DE472C6BULL, 
            0x82D9329251FA288EULL, 0x3CE5CFE64E8C3711ULL, 0x6F8A41F6A6913FEAULL, 0xA1E395CF10A2CF77ULL, 
            0x61A4C03405751B71ULL, 0xB81F6A9EFCD334ECULL, 0x93B00C3310C58FC8ULL, 0x99CA6DE8464F6E39ULL, 
            0xC018740380202BC7ULL, 0xCA0EB84E4389441CULL, 0xB9FA84D6D1DB1042ULL, 0xAFBE06B3D79D12D6ULL
        },
        {
            0xB186B0A1EB2E4012ULL, 0x15DF93BD3F2DFAC9ULL, 0xD00E0CC39F458D7FULL, 0x376759E1BEFA5A67ULL, 
            0x603C2D020458B4B5ULL, 0x5CF520E07555506FULL, 0xFCA2E958C4402E61ULL, 0xB262D93DBC4FE438ULL, 
            0xB6B979D117875706ULL, 0xD66E1EA89A0B9EC2ULL, 0x57A886A23857664EULL, 0xFFAD5ACDCC10E323ULL, 
            0x792DFDE8F3446D10ULL, 0x7348D9E1002E1989ULL, 0xB829D04DD767FAC8ULL, 0xF13CF07FEF87E39EULL, 
            0x373358460F09A67EULL, 0x9F008DD1EC3559C9ULL, 0x903720EFDB57FFA2ULL, 0x17CB494B5937F9A2ULL, 
            0xC0182AE06D29FC35ULL, 0x56ABD18C35E54B74ULL, 0x947013F31EF1474EULL, 0x239D8253BEF9D260ULL, 
            0x8D10A67A4F9331ABULL, 0x43612453234FCA81ULL, 0xC67082CE0B869CDBULL, 0xF90E4EC0DDB75880ULL, 
            0x7427E02D490C34B6ULL, 0x5C249D542F5633F6ULL, 0xCB4673D66AE006B5ULL, 0xAAC587892496DB2DULL
        }
    },
    {
        {
            0x5223DEA48BD15B75ULL, 0x03AD3239FFDE90BDULL, 0xC8A0D2F2984318EAULL, 0x5F29CC2F74BEA28CULL, 
            0x6426A2A5655762AAULL, 0xFB94752D21A3D3EEULL, 0xCA65CE251EBA06E0ULL, 0x5206401BEB8987CFULL, 
            0xE6C75FF8BB536B5AULL, 0x53F971C715B83C63ULL, 0x405DD4A850B79349ULL, 0xD1115A58A160BCA6ULL, 
            0x8F08F19BA20FCF5CULL, 0x322C8D3E56054F52ULL, 0x02A43A86B567ACCCULL, 0x7991E0619F7076CCULL, 
            0x189E1019E1DB491CULL, 0x947842A3C03CB56EULL, 0xA725C96C006C4736ULL, 0x28CD67AA572F7D90ULL, 
            0x5836313DB23ED053ULL, 0x176199911514D4D2ULL, 0xC75B2DB29A8B9AD2ULL, 0x36942AF9200E9313ULL, 
            0x45C55B90D7A3F68BULL, 0x12D11D237F4CA803ULL, 0xC143D774DE77192FULL, 0xDB9287C40EEEEC38ULL, 
            0x197612414B63E43EULL, 0x81526A9DABD82735ULL, 0x8BA0CE25D2FFC26DULL, 0x201C59BB8B996EBCULL
        },
        {
            0xB092A048BD534312ULL, 0x8DDE8ADB988B0661ULL, 0x8DE2FAD84C7444F2ULL, 0x0FC5063D10F5B82CULL, 
            0x6E64112ACBA1D407ULL, 0xB76206DD3F708661ULL, 0x3506F295B0AB651AULL, 0xE626C14F1E344FE4ULL, 
            0xB4CE143880140E91ULL, 0xFF4B1EC7AA17C1FCULL, 0x80B40A48E47862A1ULL, 0xED6A953BECFF4057ULL, 
            0x63CA1177BC059E58ULL, 0x30562F33AFD0F4F9ULL, 0xA7C8D51DAE3A1F99ULL, 0x3F37679891596EDCULL, 
            0xD690BAB49A8DB62CULL, 0xE7530F7A5A04EE82ULL, 0x5839643AB2B83D71ULL, 0x217E49790AEBCC77ULL, 
            0xD4E43187F70A10BDULL, 0xDDD595027B5E67BEULL, 0x3B505F99D3C7FC06ULL, 0xFB4F57E8A5A6B4A5ULL, 
            0xA29BCD92DCC89C68ULL, 0x3A6A5654EE48EA9CULL, 0x2AB33F4820C37B3EULL, 0xB8D1811275F89FB6ULL, 
            0x24890F5D12C60BDEULL, 0xDF8133E68AC2AFC9ULL, 0xE2A217140F63078AULL, 0xA5ACBBAEC799C226ULL
        },
        {
            0xF957363F8C7B3215ULL, 0xE4914B6254FFDD71ULL, 0x5121160C60FD1654ULL, 0xD866DC5F873FA4A5ULL, 
            0xE1156EDE54E5FD91ULL, 0xE965C52217A399DBULL, 0x6F8214F324B0A053ULL, 0xCB21A2D859F0C9DAULL, 
            0x4C368D26D2E705F7ULL, 0x72382BFFE1226E36ULL, 0x0427FEB6FD84D2F9ULL, 0x053E9CA3BC1239C9ULL, 
            0xAAAA640C5C51F676ULL, 0x4F4F2E66815EDE30ULL, 0x0C30C790F833B3E4ULL, 0x56174FD73AC5C03AULL, 
            0x1A8C4F91940B2E69ULL, 0x0CD1E8D5BA7C7A41ULL, 0x3F893BAB4F536F84ULL, 0x5B83644244F4E0A7ULL, 
            0x8AE7E03EF074F75AULL, 0x9AB90E7A64E0FBA7ULL, 0xB017531DCADE6CDAULL, 0x25AF10A57533E4B8ULL, 
            0xF6FAE686BA14AE90ULL, 0xFF027C689AE7C652ULL, 0x969E3EB7CCE8984CULL, 0x82F7379902A8FB00ULL, 
            0x902BD45153BAA957ULL, 0x9AF1097DBCB676CAULL, 0x4BEBD208718CE63CULL, 0x84138DFC48984DE3ULL
        },
        {
            0x4A40D1C548255213ULL, 0xC2FC4168576B092AULL, 0x96D8061BB3529EFEULL, 0x2E369BBD45F3BAF4ULL, 
            0x96511B6B0BBB5951ULL, 0xD556211607CAC35BULL, 0x7FA624AAF3B332DCULL, 0xCC6257389CDA5485ULL, 
            0xE297C74F05BEC36EULL, 0x896F56A818A6290FULL, 0x0B6782A2330E0F8FULL, 0x5FE92AE5D9B9563EULL, 
            0x760FF8AB1258B72AULL, 0xD1D1EC95D3814ECBULL, 0xF0001C9311D86DD8ULL, 0xA211D911F555A845ULL, 
            0x6BA85C3140D26679ULL, 0xCAEC2FE2FB05EC3BULL, 0xA60CB04F909F42BEULL, 0x7CE2A88F67C1CDD8ULL, 
            0xD9A9DADE5C642BC9ULL, 0x2463289F87776BDAULL, 0xA4787FD7F2EFBDB5ULL, 0x5BB7D5C4BB13EFDEULL, 
            0x85B76EF57814EE93ULL, 0xB711AE1152221B43ULL, 0x1D94F0732248C51DULL, 0x7B78D073BC53ABD8ULL, 
            0x203FF01C7AC7989BULL, 0x1E44C2FCAE2290C3ULL, 0x769C127D09C45E5EULL, 0x2E5F0823D6E3B636ULL
        },
        {
            0xE731B5C1D5148EB5ULL, 0x5F685B0663407177ULL, 0xA1A47EDD42ADF642ULL, 0xF9FAEF2707C082F3ULL, 
            0xAE10418126C7767BULL, 0x5041DFF1C83AC27EULL, 0x173010BB27D9F0C4ULL, 0x0C9F50B479E16603ULL, 
            0xBACC36963F47E5F9ULL, 0xAF07B2AB0EF18745ULL, 0xAB908FDCB6CDC562ULL, 0x004A19CE040EF0D4ULL, 
            0xC20A9ABADE162B0DULL, 0x72D7EB3CAFC032E5ULL, 0xFBA5581A19F19950ULL, 0xED2D435DF5AF446BULL, 
            0x8A6F9C3489DED1BBULL, 0xDFC0DF71B07BE676ULL, 0xF3DA675865D30A68ULL, 0x2CD447D68191EA5DULL, 
            0x89026C8B4BD55E4CULL, 0x5CFB776622AE5215ULL, 0xB47440ED2FFE6E09ULL, 0x3720A65554DB1E7FULL, 
            0xA0A92E6D7CFE9E45ULL, 0xEF588FBD583BA4ABULL, 0x8D0434013AF180BCULL, 0x288116A4533DC161ULL, 
            0xD999FE1EFBECEF12ULL, 0xCF200D565210C782ULL, 0xF1F4124658B9FDAEULL, 0x84274976365A531DULL
        },
        {
            0x6FE61BC93E582B4EULL, 0xB1DA08B019178E64ULL, 0x70BF1A4F1D7F2455ULL, 0xF0B16B7CCF07A1C1ULL, 
            0x1BD391BE5B4C11CBULL, 0x2CAC8B89930219ECULL, 0x798DB1075AC1E613ULL, 0x9AA59D6AC228B993ULL, 
            0xC594BC26BB29717DULL, 0xBDC5F21C0D3FC1B2ULL, 0x18DA7B2729B20846ULL, 0x21178976A1EF98F6ULL, 
            0xF2F9E6BC268FC455ULL, 0xE134DE91D1D78394ULL, 0x2150846137FDD0BEULL, 0xC9405E158998B01CULL, 
            0x94542439584B531EULL, 0x3A4DE55C1165E139ULL, 0xBB2CBCF7C3A083E1ULL, 0xC93EAD0F369AA52FULL, 
            0x73F2B119B864E632ULL, 0xB2CC057AA1EB16ABULL, 0x39E3032F9B374F8DULL, 0x198EE5B519D0621FULL, 
            0x22858E5E8E010F97ULL, 0xBB2AA33A672790C9ULL, 0x57BBA3E36B319C6BULL, 0x4DEEA41398B5466BULL, 
            0xEE99240C454739EDULL, 0x5B7AD69995FBAF85ULL, 0x6A61A6F045FA658AULL, 0x3FE44BC880D953EBULL
        }
    },
    {
        {
            0x97D0AB9A971B34D6ULL, 0x99982B76FE534430ULL, 0x186F5B4557FFE872ULL, 0x243C03E0DAF75E52ULL, 
            0x57D5EE364D8059C8ULL, 0xC7CFCEAAB05E8860ULL, 0x51D4EDD2B91B85A1ULL, 0x81405CAB27127FD4ULL, 
            0x09D74FBED3598BDEULL, 0x91D85478048D3D6FULL, 0x3A4576141277AEECULL, 0xC2D679F508E7CE95ULL, 
            0x0E2D04F7068755C6ULL, 0xF76022B49E0DB4DDULL, 0xD6C1FC2E42280265ULL, 0x360DB22EA82393B8ULL, 
            0x7361EDA3C116BBFEULL, 0x92BF39E14AFDF459ULL, 0x67792DC2FAE4F304ULL, 0xCCE803306563E0D4ULL, 
            0xF8082A7EE43CE486ULL, 0x0A829ACB635940A2ULL, 0xCBAB15A3C4001D4FULL, 0x4935A2F516050AE8ULL, 
            0x3F115622FA3609C9ULL, 0xEA010611A4EC1A1EULL, 0x4CB01ABACE7B3B42ULL, 0x7B9BEFD7022D3CA1ULL, 
            0x2D4FF5CB2EA115CCULL, 0xAA03343957330044ULL, 0xB7A570E8BF987B98ULL, 0x09CCA056C290104AULL
        },
        {
            0x489F6E3F47D15E8AULL, 0xBAA3217484AA922FULL, 0x64B418411EF859F7ULL, 0x5D7E1F869A7F52E6ULL, 
            0xEF350D91CDFA1F2DULL, 0x92C0CC92D418B4A8ULL, 0x352F48C4ADCD7BB3ULL, 0x4F440C7321E07399ULL, 
            0xD024E8F9BAA18E17ULL, 0x4E368F9165058928ULL, 0x43DCD85667AE240FULL, 0xA6719D31BE490DA5ULL, 
            0xECE26811EC1EE8CFULL, 0x79B1D337B8D0C6EAULL, 0xEEA2BD2F3F754E7FULL, 0x2BE95B494BFC8CA2ULL, 
            0xC6E4607ACFBAC9DAULL, 0x5F13CA1549355B46ULL, 0xD69416512EE0D77FULL, 0xC28C911E9F0D7305ULL, 
            0xC40B30E5820FB8C6ULL, 0x4D61273803802BE6ULL, 0xA94B5F49AC31688FULL, 0x35D38E784F03D675ULL, 
            0xC946CE5792B8A7F5ULL, 0x3D517866FE22C6ACULL, 0x92CC40564D2A8133ULL, 0x816201E9B4A15320ULL, 
            0x42FAAF5CC355803AULL, 0xBAE6479002E37A2CULL, 0xEDB1F1C097FCFA5BULL, 0xD971B44DFAEE305BULL
        },
        {
            0xCEEC46FCB046D64CULL, 0xAA570E14802639E5ULL, 0xB68168DC0C1E9554ULL, 0x0A031895E170118CULL, 
            0x4EF6A084DD4B432CULL, 0xABE821992DF4A869ULL, 0x9BD1899DBF8A6D8BULL, 0x66328AA7B77D45C0ULL, 
            0xC0FF63AAFD4400D3ULL, 0x5BB0187ECFF7FCF1ULL, 0x458F2B3F998BFFB6ULL, 0xB8558FFED872E7F0ULL, 
            0xA439AEE5FA771370ULL, 0xB13A7C996A65E624ULL, 0x315E117B1D23DE22ULL, 0xDBDDA9E189D45160ULL, 
            0x654B8E9D8E9F964EULL, 0xB55BD2B0EDC24DC4ULL, 0x4E7AFB3909AEF28EULL, 0xF02D61E75395F39DULL, 
            0xF559277D62E4F5BAULL, 0x46CB8C8E8D56B340ULL, 0x4E2A477487E67EB3ULL, 0x01D623B2EB17E0ACULL, 
            0xBD3E31A80B3CC0E4ULL, 0x278C378A6A9A3E5DULL, 0x94AEAB14538874EAULL, 0x63F74D5AA13360DDULL, 
            0xA5A9261CAA36FE31ULL, 0x744BBF74041555CCULL, 0x07759BECA42F3032ULL, 0x56E505DAE21830EAULL
        },
        {
            0xF4185839FB641885ULL, 0xB5C19AD4BCB4CF54ULL, 0x6D817ED40C259D1CULL, 0xE6462935FB0C8B72ULL, 
            0xDA7C13AB57EA1E53ULL, 0x0C837FDA8AB63E15ULL, 0xEE5B47C41402DF19ULL, 0x9ABA59BF26695D95ULL, 
            0xFA483928988432EAULL, 0x3F1E5B0A837FC955ULL, 0x21AFD9BEED101E6AULL, 0x6D513FD88BB3CA78ULL, 
            0xB64EB77D55942395ULL, 0x03E1C882923804FBULL, 0x83A28BF314660C4AULL, 0xB9DFA9890874BCD8ULL, 
            0xEC68AFCECC69ED1EULL, 0x5B136560C42A5E04ULL, 0x2B87913E7A56E628ULL, 0x321D61472EE3CDCBULL, 
            0xCB45CE0E1612EF97ULL, 0x0DA1CD554F6DF629ULL, 0x76909DB6B4A44078ULL, 0x545D32E68155D00AULL, 
            0xF14D04729D6DE45CULL, 0xF62A7F04EDDABC6CULL, 0x9BA5E8F8532DED5DULL, 0xFD0FEE6C903E10F0ULL, 
            0xEF86CBA60A34087FULL, 0x0B15AFCD7AF21E95ULL, 0xAF82D41F11C1B919ULL, 0x992DF403C90D33C9ULL
        },
        {
            0x5BCC0F22F7CD3A69ULL, 0xBF2757BF8E67FBACULL, 0x67550885AF3D2C31ULL, 0xFF368634CBE8E2CAULL, 
            0x7AAC1B6A36E76E9EULL, 0xFE153A86711577E3ULL, 0x0BBCDD7923F6CC16ULL, 0x1C35BA52C13C4CB4ULL, 
            0x4892171023A55E19ULL, 0x7337FB4F490635C0ULL, 0x8E64AA35A32AADEBULL, 0x3DF62022C6DE83B2ULL, 
            0xAFED492FADB30B8EULL, 0x42F4E8695A76ECAFULL, 0xFE70C9BCFF8049B3ULL, 0xC59CF0B201406E27ULL, 
            0xB91DD28E5F217683ULL, 0x1C5A56ACA4D44293ULL, 0x95FBE049A200B1D7ULL, 0x9028B5619ACF2F20ULL, 
            0x0E996EADD5EA891FULL, 0x52FA1EB77D5A2E97ULL, 0xE84761E95DEF2D9DULL, 0x4E5E106A6341B106ULL, 
            0x2C781B455A096D79ULL, 0x879ACA18C3FD07DBULL, 0x0BBE045F00B45A30ULL, 0xD5637FAFACB3E232ULL, 
            0x9288ABBB2F32D0C6ULL, 0xDE6DB2DD702C6847ULL, 0xE32AB3794B0F08C9ULL, 0xE5F3E2034F5EA7F0ULL
        },
        {
            0x958F67649DB744B9ULL, 0x4267DA11DEF68589ULL, 0x34DB85A1059366CBULL, 0x6457F2A489E160CAULL, 
            0x9C9B6D42A81C2004ULL, 0xF235C774D4820CE7ULL, 0x4F7BE46CD7A28E04ULL, 0x032D85DC496AB81EULL, 
            0x750BE3C060F07365ULL, 0x3B4B7D4AD565C878ULL, 0x286E1CDB50ADF176ULL, 0x5026D1929215B640ULL, 
            0x03D65D92B97C2FDDULL, 0xA809A7B6D6EADAF4ULL, 0xA11143E119D9349EULL, 0x85FC22E6971CDAC7ULL, 
            0x615A8BBA69122977ULL, 0xA0BF8DD07187A757ULL, 0x754DD8248BC1E3A1ULL, 0xEA917F8BA71783E9ULL, 
            0x8782C255C3C9859AULL, 0x081D3DDBE1F6A149ULL, 0x5FEBB4FD447C421EULL, 0xF95B71D7D3D08AC2ULL, 
            0xC7DF057F6F60342EULL, 0xC4399B4E541ACF42ULL, 0x98D067C5753C4D97ULL, 0x4F978C81D87E8552ULL, 
            0x97372C25EE5E111FULL, 0x31DB550B612CBE6DULL, 0xE697C2656F1110B5ULL, 0x3A4F8C47FEF61295ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseBConstants = {
    0xA67693C554E2D24EULL,
    0x20DE683FFE0F794DULL,
    0xBCB722A82080C678ULL,
    0xA67693C554E2D24EULL,
    0x20DE683FFE0F794DULL,
    0xBCB722A82080C678ULL,
    0x25F3804999435606ULL,
    0x03587F78C9B9FFEEULL,
    0x87,
    0x99,
    0xC4,
    0x95,
    0x92,
    0x1A,
    0xC6,
    0xF9
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseCSalts = {
    {
        {
            0xCF5269FA5EA346E2ULL, 0xA5383CBDFC0C6369ULL, 0x7C2E85A4EE4D8EB7ULL, 0x23280AE5AF286E2CULL, 
            0x3D3140EEB3E6C8FBULL, 0x2BA8ECF78D8E5BEDULL, 0x6015BD714B343E0DULL, 0x3FF8A3729EB2D615ULL, 
            0x45E7327E278B4918ULL, 0x8FF41445BA120FEEULL, 0x10A4DE32E22B378FULL, 0x76CFB56186648362ULL, 
            0xA9D03AF61AD7ED55ULL, 0xB26A79C7AC4474FFULL, 0x1088392A5A537930ULL, 0xC40CA2319F965F90ULL, 
            0x61294B6BC7561783ULL, 0x32E170ECBE2B5A3BULL, 0x5622C5899570EFB8ULL, 0x31290C9409480DCCULL, 
            0xDE8A4954657762EDULL, 0x236204F4BB232F78ULL, 0xA6327692C1C83C18ULL, 0x938BEEF6F8C6D5FDULL, 
            0xEA990650E6870FD5ULL, 0x24ED051B77E5DD4DULL, 0xA6AD293AEF6F62CBULL, 0x2ACF2923ED61F6D4ULL, 
            0x534694A080C751AFULL, 0xFD8FC55B1B1362EAULL, 0xB4A73938530E3339ULL, 0xE1AAE469CFB33713ULL
        },
        {
            0x544A509CE87F8595ULL, 0xDDDF5FF6B687FAF8ULL, 0x466E8A4EA49DF63FULL, 0xA3DB58489110AD76ULL, 
            0x1D56BB16D953299FULL, 0x4E6907199F36C7E5ULL, 0xD0BB9D8EF825436BULL, 0xAD5496E615360D24ULL, 
            0xE44616DF36B761E2ULL, 0x9456C96463641C27ULL, 0xF4E8AB47E70A374EULL, 0x447C9E02F6C38BF7ULL, 
            0x4B4C90EC12DCD226ULL, 0xBC02FFEC43DD2ECCULL, 0xA45D0B9A5A35FAC7ULL, 0x2182797A45D16C0EULL, 
            0xD021ABE886CE85E0ULL, 0x03F5F9E798347747ULL, 0xAF49F46E36603282ULL, 0xB8E3D7B376A854F8ULL, 
            0x66F8408354700961ULL, 0x334EDAB92B493EB2ULL, 0xE8C0FBB5E4712144ULL, 0x50954343EC5F3B6EULL, 
            0x0EFCE9C2BFBFEBB1ULL, 0x2F77757A43A87CAEULL, 0x714C747E52AD1C38ULL, 0xA13072D4424C03A9ULL, 
            0xD5952B89B7A977EEULL, 0x20B30ECFBCD601A0ULL, 0xED5C6813A647C01DULL, 0x93D8044375B5647AULL
        },
        {
            0x4922A3DB66CD6424ULL, 0xFB80CB2EE1705B4FULL, 0x9D1DED57D96AC4A6ULL, 0x59665ECB21E432A2ULL, 
            0xB8C66BA4913B269FULL, 0x892EF8A0464CF07DULL, 0x1C8C9170FD8C3F56ULL, 0xB355B3FAD295EFC2ULL, 
            0x9A6B36B862FFBEE1ULL, 0x2EFEB68F935B242FULL, 0x7F61C0B27AA88305ULL, 0x53F68CC421749969ULL, 
            0xF9E2BAA2FA4ADEC2ULL, 0x6D4CCE307550FB66ULL, 0xD75E3656E519DBC1ULL, 0xCBD86BB0AB785088ULL, 
            0xE857174F25980DB5ULL, 0x679D484587038CD4ULL, 0x11B36AB4A6EF8137ULL, 0x91AE98F657D340A3ULL, 
            0x987F014D9621C68CULL, 0x82AFC6FA04B6304BULL, 0x5C6A4A7992177BF0ULL, 0x06056809E8A44933ULL, 
            0x26530168B2F51F79ULL, 0x3B93960FC3C04490ULL, 0x24AA396D0729B0A1ULL, 0xA9C2BBB00F1D6782ULL, 
            0x1E6F4FB3659953D4ULL, 0x0795D4A22630DF53ULL, 0xB10CB8B2BE145DC1ULL, 0xEB1ABC42A7DEA50FULL
        },
        {
            0x32EB4EFB5889ACD1ULL, 0xCA0ADB53A9614EACULL, 0x5E185A41A44A29C6ULL, 0x7050740FD2FAC3B9ULL, 
            0xFEDC807F639C6CABULL, 0xDCB7C00D12A3300FULL, 0xA86A99555671E92CULL, 0x8740B8A4F4767D65ULL, 
            0x5EAFC650FDFF2783ULL, 0xE4CD39DD0D58F294ULL, 0xACAF08D86C217B14ULL, 0xE46160949063D159ULL, 
            0x9EFF000D8EB5F2EDULL, 0x9326006239DAD76EULL, 0x1F9B22BA6165E940ULL, 0xA84B43E0140F3CD3ULL, 
            0x8707AF36371C2691ULL, 0x6E62DAFE5ACEE63EULL, 0x8BCDAC9CC928B19BULL, 0xD1076826F7400268ULL, 
            0x180F5F9D7AAA404DULL, 0x604C590722A01852ULL, 0x284D3F88DE45F15BULL, 0x8B37C9D4A4716D71ULL, 
            0xF636172C831920F8ULL, 0x65909946A6BEEB93ULL, 0xBD39CB830D3560FDULL, 0xCDAA9983C7F994D6ULL, 
            0xAACE4A99B6C6C19EULL, 0x64D9006179C80614ULL, 0xD033EDCDBDB62C1BULL, 0x23098FC0C19CD558ULL
        },
        {
            0xE033A4680644AE27ULL, 0x64ECD852FB676261ULL, 0x21752BE86102593CULL, 0x8C0D4B6DC69D30A7ULL, 
            0x20CBBC541D54EE41ULL, 0x0E687FFFC10A3A7FULL, 0xA54F015BB1E7F358ULL, 0x4B1F325348F41142ULL, 
            0x60843C574D5ADA3FULL, 0x7E97E068299EBACCULL, 0x04404D7CAC69E396ULL, 0x68299E49A47F5153ULL, 
            0x34A8924F14BB1D15ULL, 0x0C14229A746F0743ULL, 0xFB134F29E9F9D794ULL, 0x597844ED73A8B2A2ULL, 
            0xD1C23B86B62658D8ULL, 0x0676B1A73ECF08BAULL, 0xCFF122F8D84E2749ULL, 0x6BE451A5DCAEAEF9ULL, 
            0x65FDF8AD7D8A47A1ULL, 0xC4908962DC9A6B77ULL, 0xB9C55ABC906D1D07ULL, 0x0E08B14572025751ULL, 
            0xD27F74042AB71B05ULL, 0x147F62AB592EF769ULL, 0xC90C3152937260CFULL, 0xDA6834B939E41D3EULL, 
            0xBF569716E5846EE8ULL, 0x28C58C32432E81E1ULL, 0x7F7E3487331B0930ULL, 0x5C7E0435B693E734ULL
        },
        {
            0x2BDB9B400F4A0966ULL, 0x91B673EE9628AE18ULL, 0x8DC3EAA29E65E565ULL, 0x590D2E3808C81FC9ULL, 
            0x9CB87428BA32611EULL, 0xD9AED6D6C6C3808AULL, 0x56046C3936954E9FULL, 0xD979BCA1BB9D26A7ULL, 
            0x153A3DC0EAFDCC00ULL, 0x1C0699BD97708C0AULL, 0x706F967471B3F81AULL, 0xB29614A4D365ABD1ULL, 
            0x378AC7EF5C67695DULL, 0xA362867582ACBC38ULL, 0x485267BD5C6EAE20ULL, 0x2F44519C47899064ULL, 
            0x33FBD02F83E355D2ULL, 0xE59D32660ED0B0FCULL, 0xE16E9D44FE4C29EBULL, 0x1B36D88AD8D086B1ULL, 
            0x6819EBBD70BC3565ULL, 0x3605AE0390CF5115ULL, 0xA5F030AF18059B29ULL, 0xC2E86A84C75F9D3DULL, 
            0x8A1773A7B686BFEFULL, 0xDE3380EA7BC0E294ULL, 0x18278DEC25FBCE65ULL, 0x73A06845FE7F19AAULL, 
            0xE2C13A1459FAD07AULL, 0x1FE670CD1ED61EEBULL, 0xBF86B3C474A27230ULL, 0x873BA84CB6E6A7D3ULL
        }
    },
    {
        {
            0xEB833EA4931F1A97ULL, 0x30A4B9879195D67FULL, 0xF882A9DFB58937E0ULL, 0xB51524126F39CDB9ULL, 
            0xBC6B9F65AA050028ULL, 0x23763F1592CE6CDDULL, 0x446C7F94BE8EE27CULL, 0x8895538D6237EE36ULL, 
            0x96372C7BE0644603ULL, 0x2E6CC1A8EC2EBC4EULL, 0x875A29EA44B26B3AULL, 0xBC1B7A2A41A43F58ULL, 
            0xC3963CE354B65052ULL, 0x0D41CFBE5226205DULL, 0xABEED9CF7E6D9920ULL, 0x5647A53D8D5140FAULL, 
            0xB87A599CE648B502ULL, 0xD34920142FE1E767ULL, 0x76BAE29549724CDBULL, 0x3F5CACDDA1406B09ULL, 
            0xBC9487999E166B6DULL, 0xE4111C4E0DBEB61DULL, 0xAD585447D6119C85ULL, 0x819D91F101221F86ULL, 
            0x85FA01A6AD18AD3CULL, 0xEF9BBDBBC7951888ULL, 0x33DD8459A1F7B823ULL, 0xC542C4CBE11E9D9DULL, 
            0x73D95F7B4F3A694AULL, 0x739B3864BA399FB0ULL, 0x81AC44D8E290750AULL, 0x6CCA8A2240011E86ULL
        },
        {
            0x6EAF7C49C6688CB1ULL, 0x40CE047A5073E7EBULL, 0xD2082BC3B02458F6ULL, 0x615E68459EFA7465ULL, 
            0xFA768C593201ECB0ULL, 0x40B6DD5FA01A7F7EULL, 0x48450C1D2C125A52ULL, 0xD841857632C5D022ULL, 
            0xD5061C4223A10603ULL, 0xE36267108DB2B4E9ULL, 0xF459E7A8763EA8DDULL, 0xC71143E4F0A53EDCULL, 
            0xC40D9D59AA95A75DULL, 0x9293668273D326BAULL, 0xA18D9764FFD20F4AULL, 0x09D80D32DBD8A6A6ULL, 
            0xF66CAF633654A030ULL, 0xD990C277EF23AB2DULL, 0x8BA97241B4F9CA9BULL, 0x6C4D3022BA7B46E4ULL, 
            0x121507DD7160AAC5ULL, 0xBF0049377F975099ULL, 0x8007DD1FD36F84C0ULL, 0x1FFF842D52FDE6EBULL, 
            0x281BE2DFEDC49C2AULL, 0x03B17B61F92C978EULL, 0x0532C6F7B840244CULL, 0xF31824AD8239BDEDULL, 
            0x6002CBDA86BF7E5AULL, 0x57023F613E281860ULL, 0xB5BAF4172C01F50DULL, 0xA4329D2ABF5FE173ULL
        },
        {
            0x0EAAA1CD92D8E7B6ULL, 0xA7FD14B2EA35F3FBULL, 0x18B3885F39E57D74ULL, 0x3E0AF0B907DEA8F3ULL, 
            0x52B3950B7423FB0CULL, 0xDFCAB47FEB618DE8ULL, 0x7570C9BFEFE1C36EULL, 0x1123148A5D80AAF6ULL, 
            0x7667E0A576332F4EULL, 0xA73529F057D29FA8ULL, 0x12C574F082736B82ULL, 0x8B805A296F1814DEULL, 
            0x0C2C692E29DD3264ULL, 0xAECCEDD1114A375DULL, 0x42072B684859B6FBULL, 0x0788BF1C21452EADULL, 
            0x5B2F48BD6DB9CC9CULL, 0x46FBB44A8B18BFADULL, 0x8F6AD552CD181AE2ULL, 0xD8410D1B433DF2FEULL, 
            0x34DDB811BA09B703ULL, 0x1B5A6973A57DEB01ULL, 0x57F818E8B517C09CULL, 0x1A46738328A5FFABULL, 
            0x917590B7F89C0C09ULL, 0x20DC231D1B704FA6ULL, 0x80D6682E5DE049E6ULL, 0x523EB46AB8D7BA6AULL, 
            0x0DA4E38AA217548EULL, 0x66F1F49AB13751D0ULL, 0x276049665FB21634ULL, 0xD42211C54BF65814ULL
        },
        {
            0x9120A70D78A68286ULL, 0x85C8F7C9A51760DDULL, 0x88631EFDA3C68145ULL, 0x60C6DA07419C0739ULL, 
            0x682324D1456C3E8DULL, 0xA60DFEC08BDFA02CULL, 0x3309946791245C51ULL, 0x415C3E16ADD89C8EULL, 
            0xA0169E0A12B7E05DULL, 0x292BE097494CCD4CULL, 0x5E7DF0CD194493A9ULL, 0x42C25B5FAF5877BDULL, 
            0x13C39EF3142A25A4ULL, 0xCD2294AC3EFD9769ULL, 0x13F1EB8A54E9ABE7ULL, 0x6EF66AC64A26773FULL, 
            0xAFB22F4C4B37F716ULL, 0x4081DC36172583ECULL, 0xD73F087A7E9ED003ULL, 0x6FAAB120F174CCFBULL, 
            0x16EB742596B3C4B3ULL, 0x1AE498E8D62B7788ULL, 0x6F5FAC589FFCC600ULL, 0x77D348364E3538E7ULL, 
            0xE2F8D1FCB7A0D3BDULL, 0x9573CF2DD857BAA8ULL, 0x73E21E53113D8E58ULL, 0x050015978947D49BULL, 
            0xE18F831752E0187AULL, 0xF4D47EA953456C55ULL, 0xE62B464DB4A4713CULL, 0x711CEAFC247A88C6ULL
        },
        {
            0x8E68C9996A2065BEULL, 0x0B18F1563CBE1EB4ULL, 0xD83482B3D5682CD0ULL, 0x92D60CAD0A731953ULL, 
            0x94C7A8E503734DFAULL, 0x11CC011D99A126D4ULL, 0x772DEF6A8E3C6BE9ULL, 0xD32DCC8A4DB5A872ULL, 
            0x043ECA178F7B2E2FULL, 0x23120D027729E88BULL, 0xD423F303BE95868BULL, 0xE2FDBCDF94A08845ULL, 
            0x09CA6C931B818F62ULL, 0xA476E122369C9EDCULL, 0xAA279B10ABB3045CULL, 0xA3D83B15BC4CC38CULL, 
            0x542BFE908A9EA1F9ULL, 0x71BB8A3472FC8458ULL, 0xD9E4A830F49B74D3ULL, 0x691F30FF98A1F81CULL, 
            0xC8E53CB36E698F4AULL, 0xD67A62C25E9E1D7AULL, 0xD6420E8B4D9F2626ULL, 0xC592E8DE23DE39B0ULL, 
            0x2FB8CA3B74D30542ULL, 0xFDC496A276D697FBULL, 0xAC4D9A5D21354BE5ULL, 0x58ABB925458788ABULL, 
            0xE037DC65BF238A5BULL, 0xA947197B19B7F9FAULL, 0x91BD7749A8959B5CULL, 0xEC892B37D723D1E8ULL
        },
        {
            0x07DA90F6CB8D4D7FULL, 0x83FCAB5BE7C50C48ULL, 0x776284ACFB0495FFULL, 0x7B8CB448233F552FULL, 
            0x65EF1D3C8A8DE2FFULL, 0x3E0CDD689EAD237CULL, 0x5559CDB63BCBBF4DULL, 0xADFE1E2C13BD0056ULL, 
            0x4B22B06E7EA23DFCULL, 0x458CC51D3C4CE46AULL, 0x05F9AFC228467DA5ULL, 0x7A6378BC63C215D4ULL, 
            0x4CE3D7E2717EF95AULL, 0xCEA235DF66FCCF36ULL, 0x6B7ED132CC7B391DULL, 0xFFE321273B08AED3ULL, 
            0xFE334ECF3A6ED942ULL, 0xAF4D2A36E599B4E1ULL, 0x59D5A9D5F7CF12FCULL, 0x26D00458D9D693E6ULL, 
            0x88D65A8EF03E1346ULL, 0x689C72D592F548D4ULL, 0x9518325A3F564154ULL, 0xC93FA641A2093007ULL, 
            0x74EFE94B55793E43ULL, 0xE4C0045CD4E91629ULL, 0xAD7E0842BA6F346FULL, 0xD8A362DE9F0E0F3BULL, 
            0x5EE045F31FF1F3D5ULL, 0x3DD9F8336DF1A496ULL, 0x14153067EB145A75ULL, 0x686FA619809B6B99ULL
        }
    },
    {
        {
            0x5A40AD3878D69767ULL, 0x5FC4B43960D5E5CAULL, 0x162026075EE9FFCBULL, 0x66FCE44864F2D057ULL, 
            0x8006D946271C1AC2ULL, 0x27664344B90CE581ULL, 0xFD8E33505DB6AE61ULL, 0x29647834DB0C4052ULL, 
            0x03C27714730E5FA5ULL, 0xA96212D8A79D49CCULL, 0x40A8F8DFCCAD2858ULL, 0xFBCE86EF515826D7ULL, 
            0x8ACE7508E0F5C6D8ULL, 0xF5AF748584AEF6A2ULL, 0x360D7D32FFBB6FF5ULL, 0x1AEE554D01EED3D6ULL, 
            0x6FE9CC1F97A5BFDFULL, 0xC91B1AAD9204DB7AULL, 0x8E7C469BA1FF4641ULL, 0x814F355375EB0BE4ULL, 
            0x7D15936582D158E0ULL, 0xFB56305DD89B9C49ULL, 0x84D146AB6DD8AE70ULL, 0x747F51968BDAE985ULL, 
            0x52D8B9E18AA96EFEULL, 0x6FF4FDF1E18FF187ULL, 0xB4BDE6DD7C128C85ULL, 0x9ECB40CD57A93556ULL, 
            0xAA6A59084702397CULL, 0xEAAF8379DC65A1D9ULL, 0x497F468B389E8C1BULL, 0xE6637785613E74D7ULL
        },
        {
            0x12F9E6E7921BB730ULL, 0xD607343BD15CB345ULL, 0x3CF5F8B2E9762846ULL, 0x1A7977C0CBA4A0D4ULL, 
            0xD82F675FF391E144ULL, 0xDA4501C34FDFA910ULL, 0x0798E890AE718C12ULL, 0xB5095FBE729A7FABULL, 
            0xE0D2C9243299F34FULL, 0xF4F9F1B8AF9BA136ULL, 0x7F80F6AA0F96AD28ULL, 0x9A52BEDBEAEB9F73ULL, 
            0x3075F23B2ADCA8FAULL, 0x16423B9B0915F002ULL, 0xB7104B13E5C28E3CULL, 0x8192E80C6C5F60EAULL, 
            0xA0940DF6F924D71FULL, 0x87AC67292C58EFA1ULL, 0xDE2C88F104F3BDF0ULL, 0x35293DF8204BAEE8ULL, 
            0x5B304E96D9982776ULL, 0x0C8B281005BB6883ULL, 0x2FBA358F6A101939ULL, 0x05FD8A20167B77FBULL, 
            0x73E6635391414867ULL, 0x8EA4EF16B1A1A452ULL, 0x21FCDCE7D0AC5045ULL, 0x684D4C827869591AULL, 
            0x50D359FC8A0F37D5ULL, 0x65006D7CBA696BEFULL, 0xDAACE35152C688D4ULL, 0x56AE37243643302EULL
        },
        {
            0x9B32F156E31273B0ULL, 0x04D719A8D8898880ULL, 0xED6211CE48E35E1EULL, 0xAFBCEC584BE2F437ULL, 
            0xAC592C8AC82ACA5CULL, 0x5BE7BAB67B2E684AULL, 0x9F46A68AB7748CC9ULL, 0x020F5BD23582127CULL, 
            0xFD37D9C0908D1486ULL, 0xFC258457F5001EF6ULL, 0x0670C96EA23DB050ULL, 0x4770A19E50E221DAULL, 
            0x13B3CAC685E41B02ULL, 0xD03698E84A3766DDULL, 0x1F4E9243BD7DF11DULL, 0x4EA354FDDA63CD19ULL, 
            0x461D4BEFBB061625ULL, 0xB6D15CC0A73CE7F3ULL, 0x6A77E86A5C2A1DC0ULL, 0x1527D9A9E9362312ULL, 
            0x1D923A9660B769F4ULL, 0x9E061AE2C0718525ULL, 0x201C627909DA4716ULL, 0xBD29EDB83BCD4D48ULL, 
            0x5B3F971B3426114CULL, 0xE6095B1D7CFAB7CFULL, 0xDD81FD71D0D5DD91ULL, 0xEFF0610A8B450A5CULL, 
            0xA0AA2DC6C7BE33D6ULL, 0x56708F021F19B518ULL, 0x9CD4C2D861580CDCULL, 0xCE18A8FCAD619A0BULL
        },
        {
            0x17B7DA599E39F1AAULL, 0x8E58DA82B223A9DDULL, 0x0210685FA06D8965ULL, 0x82662263C5239319ULL, 
            0x6F0E689905BAA6C4ULL, 0xDEC2742281173425ULL, 0x0DF5E65DE318057CULL, 0x2B14E97BAB2AD58BULL, 
            0x68C90EF725A40B1DULL, 0x70F4B2487108CC0EULL, 0x25A5FA9B7A68B1A9ULL, 0x03CAB9AE480A4E3BULL, 
            0xC35D287363397EB6ULL, 0x7E70AB908573EA5AULL, 0x7496135E8050D887ULL, 0x6DE24FC23052F060ULL, 
            0xEEF52C09844397DCULL, 0x604DA7DCBFE3DF68ULL, 0x1CA221E6ABF81C19ULL, 0x29EA77F5BD06721DULL, 
            0x01DF23573E0B7450ULL, 0x836F6C5732069B61ULL, 0x3DE3E93E21EB3135ULL, 0x3573427434B1ECC5ULL, 
            0x14C28C907061C481ULL, 0xBF3B1648C93E6844ULL, 0xA79E7E676887FAE9ULL, 0x4BE593142DE87721ULL, 
            0xEB446D96A91F3825ULL, 0x741FECB15151A00CULL, 0xA8F6A0C82F1A3FCDULL, 0x7AD07CFDB6D1F706ULL
        },
        {
            0xD87B55CEFB4B72A8ULL, 0xE61FF285FB16A761ULL, 0x6A2C0935377DE245ULL, 0xF7187EF23DDC49EAULL, 
            0x7B761AB98C9090B2ULL, 0x337BEB5524E06B1FULL, 0x2F40547D13F26459ULL, 0x3A444C755FDA7F55ULL, 
            0xE60CB40CCFFE06E1ULL, 0x4FF63F497CD88B1BULL, 0x161B4E5AA911BB84ULL, 0x0A9895F77999CB26ULL, 
            0x4D48EB49BFA179BDULL, 0x87E95F5259BB9608ULL, 0x1E8F7C6431BB4DA2ULL, 0x4524E8E2E5B390E7ULL, 
            0x6084F89917315D51ULL, 0x5A003FFFAD8734E1ULL, 0x3DB7DF2197DD24DEULL, 0x53B681FB9A90D61AULL, 
            0x61B20F5B1DDA67B7ULL, 0x6FA029045C7F6B66ULL, 0xF3A59CF19A728D98ULL, 0x0BCEEA543D2DAF42ULL, 
            0x87ED304FFDA8441DULL, 0x513AC9517CEC16D1ULL, 0xA28D53D6EEE914BFULL, 0x5536A8916C7C10ACULL, 
            0x1B7B3B174F58BC44ULL, 0xD12D45CC7AC642D8ULL, 0x5FD941511E8D1014ULL, 0xD4AFA366C82781CEULL
        },
        {
            0x2FA76146AE0A7EDCULL, 0x6DFC8164E03A0A80ULL, 0xB63E84475172FB44ULL, 0x94F60970C7DF3897ULL, 
            0x99EC5E04FF38C02FULL, 0x2F335772851BA77AULL, 0xF329B721C8FA8EBBULL, 0x49738D34D6E04591ULL, 
            0xAE5C45879F6C533EULL, 0x235E3DABD9F370DAULL, 0xABAB742917D126ECULL, 0x717E5E66328FCAFBULL, 
            0x0FD5E091F91CBACBULL, 0x14082361DDE0E1AEULL, 0x0016FE2D5B627856ULL, 0xFA291C265098CB0BULL, 
            0x0FE5102C703785FDULL, 0xAC35646A3188BC17ULL, 0x596CFA0390A2A128ULL, 0xA6B48D5C5EDD9335ULL, 
            0x2A05562801A1331CULL, 0xF84C2D7C54DB4B9BULL, 0xF4BE8AFF6739D6B9ULL, 0x160D240110FAA3EAULL, 
            0xF91B933326AD7CB8ULL, 0x32E136A7DD09A8DFULL, 0xB210B34299D01EECULL, 0xDEC04A3DF9796287ULL, 
            0x3737696C377930E6ULL, 0x213A9C2A2E1DCB7AULL, 0x9DF589B44EA4E9EBULL, 0xCCE43174799D092CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseCConstants = {
    0x8ACA26E01F2E0CB8ULL,
    0x7A71B724C46174E2ULL,
    0xBBC706D3CB3F2706ULL,
    0x8ACA26E01F2E0CB8ULL,
    0x7A71B724C46174E2ULL,
    0xBBC706D3CB3F2706ULL,
    0xCB807DC97EEF8980ULL,
    0x2508FA373E7CC298ULL,
    0xE9,
    0x0F,
    0x1D,
    0x36,
    0xE7,
    0x4E,
    0xD0,
    0x65
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseDSalts = {
    {
        {
            0x0BE72E1019B6087BULL, 0xC1497D8450D4FDE0ULL, 0xF77B6F774748C667ULL, 0x2482E2A335262EEFULL, 
            0xAC3E898EC77FC36BULL, 0x3613FA3952D211E7ULL, 0x2E3E9F927AC5CDA1ULL, 0x76674E383D7F62ECULL, 
            0x1B327C51392DDCF8ULL, 0xF5D95D5763328117ULL, 0x02B05D3F4E9376CDULL, 0xE64323C6C3018C00ULL, 
            0x9059967BAA16D2E3ULL, 0x96C6811ECC671C57ULL, 0xB5C187E2A6B8B787ULL, 0x4C7EA97256DE7476ULL, 
            0xDBFBDACA8BCAF347ULL, 0xC38EEF41B4C04A22ULL, 0x21A82B4A5C124488ULL, 0x84BB90430931E540ULL, 
            0xB4CB7D7C693187AAULL, 0x92CD5A786718BCD2ULL, 0x6948C8EBF7E1D276ULL, 0xF49D52EA724B3E7CULL, 
            0xE468EA8D09034B1EULL, 0x161A4F5B911AF165ULL, 0x242804415DA2C98FULL, 0x2534329B69D140A1ULL, 
            0x48CD1B851F914F9BULL, 0x6928866175948B95ULL, 0xA82379499C622A9BULL, 0x3895AFDD183577C3ULL
        },
        {
            0xA7AB56283AF8223CULL, 0x324FAAF652165471ULL, 0x9411B28BA8272A2BULL, 0xAA56CC411F78FEA6ULL, 
            0xAFF112073F220597ULL, 0x520CC3D2093FC156ULL, 0xB76462BCE1E5E872ULL, 0xE557BE438ABA082CULL, 
            0x0B51721FF7D6EF43ULL, 0x3D3B42B7E25AE17CULL, 0x4086E870F4456245ULL, 0x65F4B2D565F087E2ULL, 
            0x07E781509E16D364ULL, 0x8CE6A308C65A40BAULL, 0x5354389F0BB6C271ULL, 0xC1EAD3C13DF84AD5ULL, 
            0xA2385B56572A0F49ULL, 0x98132D5BD33FD1F5ULL, 0xA551953807657F00ULL, 0x8F560E0C8705EF97ULL, 
            0xF5B7AA80339CE766ULL, 0x76D45753C37FE069ULL, 0xBBE3174C12377856ULL, 0xD6BDD5B77E970467ULL, 
            0xA5AD8B36E552DF16ULL, 0xB019A25FD7818D03ULL, 0x8D0CAFD16431BA4FULL, 0x8FED7C0A735DA6BFULL, 
            0xDA8370B9FDD41D2FULL, 0x0CFC3474D58A6A88ULL, 0x8B0BF5D97A79FD37ULL, 0x6C5B02C999926B36ULL
        },
        {
            0xBE8EDC597B2ADE7CULL, 0xC6DD7389A4AE847FULL, 0xAC02745F0B22F297ULL, 0x261555EEE4B76D82ULL, 
            0xDC5982EF5B343460ULL, 0x1A255BA0433739EBULL, 0x3279C282E2CA7C44ULL, 0xA84D4388C7133003ULL, 
            0xB31ECFCCF9621714ULL, 0xCE9310CA495B936AULL, 0x24F786A45B9BF80FULL, 0xA12E2F5CD216DBEFULL, 
            0xA4E86DD36956F918ULL, 0x9D8EFCF7487460B5ULL, 0x8BFF6BA83859F80BULL, 0xC0E610D281912297ULL, 
            0xE4D72464121F70E4ULL, 0xCD30F136571824F4ULL, 0x181D02AFD0C07063ULL, 0x2C156BF2217DB6C5ULL, 
            0x985C8C86CD2AB5F7ULL, 0x49AC4C05A4121952ULL, 0x37B93A0E94495920ULL, 0x357235A30F96CD1CULL, 
            0x87F6FE6C791EB4A4ULL, 0x78C6E197ACB10375ULL, 0x46596A760F41A167ULL, 0x6F66214D258FDAC7ULL, 
            0x53E84C3D6BDD5564ULL, 0xA4582EE0DAD97613ULL, 0x7BF485D961148149ULL, 0xAFAA42EBAADD321FULL
        },
        {
            0xD02D67A9E4E68DFAULL, 0x0C4B62A8D9334928ULL, 0x42A872C9128CA52DULL, 0x599CCDFADCCE53D8ULL, 
            0x88201113B7B4864CULL, 0x4789CA26A3EDFA8FULL, 0x61954DD98DA649E4ULL, 0x07598733EAAD36EAULL, 
            0x41A3F176DD8403B0ULL, 0x57D9CB13C2857C8EULL, 0x201B0D04D9DD8890ULL, 0x0BC44F14E90E9372ULL, 
            0x293CE8006EE446ADULL, 0xADA02F4292C5143FULL, 0xE42EB25172C30FDBULL, 0x13FEB64279E9121EULL, 
            0xFFBD90D1C1543423ULL, 0xF9DAE8363EA3C87FULL, 0x28B338091D70C725ULL, 0x04DB7E8D0F531789ULL, 
            0x876F4BB96C7CD602ULL, 0xF9B9C1FA0B0D8933ULL, 0x33FE099EF52A2822ULL, 0xC943F704415AC2F8ULL, 
            0x97A77FACF10C42CAULL, 0x00E677E5A532B90CULL, 0xAD38465B8F19ABCCULL, 0x3F88432575520D3EULL, 
            0x2A72FB502412681DULL, 0x6454D0DF1FECC0C0ULL, 0x77E3420CCF125EBDULL, 0x9F5797E4A8337078ULL
        },
        {
            0x8C4CD909B4E919ADULL, 0xD8DF321422666E4BULL, 0x80D7986958884CFAULL, 0x278DD02AA5C7DC08ULL, 
            0xB661BFA2697A9482ULL, 0xE616D716A6D13593ULL, 0xA516B5F5DD7C8FC1ULL, 0x128FF7E4141E3420ULL, 
            0xC0E5097A7B642DB4ULL, 0x0832A0BADFA5CFB4ULL, 0x6BBF35AF57976077ULL, 0x44402D1CD1288652ULL, 
            0x0F45742F70B0CDFFULL, 0x722FEDD7984A8B92ULL, 0xFD9707C1F9117D32ULL, 0x69AAAE560EB7DB3BULL, 
            0x4A849A36B54F3D4CULL, 0x2F70A2FCA4EB065AULL, 0xCCF74D18BF62FCF6ULL, 0x6E458032F882627BULL, 
            0x4BBC744D9BFF9418ULL, 0x2F44F529A78FD92BULL, 0xD92D88E71856703FULL, 0x502F3B4120634DB5ULL, 
            0x558F683463D83ECFULL, 0x599E2A52EFC6EF82ULL, 0x85920E0510B826A7ULL, 0x2B5223D003ADA6BBULL, 
            0xBE91619866C548BDULL, 0x8165460561B6A4C1ULL, 0x01C9CB0D6219FAF1ULL, 0x7FE47AC8FAFFA665ULL
        },
        {
            0xD2101CE129DF8713ULL, 0x040765321B0D1A61ULL, 0xA6F6A0943E3A4887ULL, 0xAE2FE8510E2D2736ULL, 
            0xEDADE1A2C8420BA9ULL, 0x100B51739FBDABB2ULL, 0x6A4F1B38911B31ADULL, 0x89D5C6001D08A32AULL, 
            0xDF95336CF297B2E7ULL, 0xC444426D42A42FEFULL, 0x009D4D8300D22F63ULL, 0x68525BBEB8AC5BC4ULL, 
            0x32AED891E78BC603ULL, 0xEE732409383856B3ULL, 0x5208C8200410E761ULL, 0x9B5094D261C880E2ULL, 
            0x4B0AD098E2820D92ULL, 0xE21BF43D9D973BC8ULL, 0xA326E2825C807029ULL, 0x378BAEE2A3089640ULL, 
            0x588DC89E2D859637ULL, 0xCB86A056C8787C1EULL, 0xB0999C19A830302AULL, 0x934F44BEE2D7E75CULL, 
            0xC9F6726376CC3FEBULL, 0xA851C9734B5F8DFFULL, 0x35225A3CF7C391D1ULL, 0x554846FF3CFCEE94ULL, 
            0x205F056B92B0C932ULL, 0xCFEE4A4CEA4C1694ULL, 0xCD2508FBC1283470ULL, 0x843D9764D44A0875ULL
        }
    },
    {
        {
            0x30C650F12C403CF2ULL, 0x8584B592C1EACA6AULL, 0x7ECDAC785E8F2A65ULL, 0xC9DD21D0A5B58BC7ULL, 
            0x3D69619EAFE7D1A9ULL, 0x1A59DC6268E2A72FULL, 0x5C456D32DA8416ADULL, 0xB3F34CA211006CAAULL, 
            0xB4E031BD471CD18EULL, 0xAAD727E63CD88D13ULL, 0x75871138CCADC923ULL, 0x511FDC4DBA168659ULL, 
            0x5FE0E078676C6D2AULL, 0x3881A0FAD17E2A2CULL, 0xE0E66DAC667EB899ULL, 0xFA066E1CBF19B935ULL, 
            0x3F6D51D1469651F1ULL, 0x25633D5A32092758ULL, 0x7564E838CF414CFFULL, 0xE812B1DEAD6038F5ULL, 
            0x5595FD6394D589DCULL, 0xB34C380B6B6B6194ULL, 0x61CBF956A529BCF9ULL, 0x55C749CC6B4655B8ULL, 
            0x0C42E1D54B26DFBDULL, 0x6B0566FDBFD4CAEDULL, 0xA113D191C6765C78ULL, 0x07368AF3B2318611ULL, 
            0xA61D3D995BE3AAA2ULL, 0x2A691181001FF665ULL, 0xCBC181FD39F7D41DULL, 0xC4EFA68957C923DEULL
        },
        {
            0xE7DBCC289417BD7FULL, 0x97DFC567270B2CCEULL, 0xB22B269711EA76A4ULL, 0xD1764CE4E95F11BFULL, 
            0x5171BF7D98487277ULL, 0x7B390923D40AE55EULL, 0x4BAB8EEE72E7372FULL, 0x184C6E05A562F5CEULL, 
            0xD443F7B6AF52C78FULL, 0xE5D1FD26ED2226E2ULL, 0x5BBF9DBE6780A397ULL, 0xCCF89BF7E2B4BB52ULL, 
            0xB667AC30726FFDC6ULL, 0x6011E87DF6FC22EEULL, 0x74DBCD0C7A1A656DULL, 0x95F6D95D8BA490AAULL, 
            0xC0A0878280EE74A6ULL, 0xA283D1BED570B259ULL, 0x49EFD2B80A986DA3ULL, 0xD1039B35FFDE564DULL, 
            0xDCD5CAA18856450CULL, 0xE4A8E79EC447154AULL, 0x4A74FCF04764F106ULL, 0x04F3D7B3ACCCD535ULL, 
            0x6FBE237FC7F29BEEULL, 0xC69EB35C78E74E28ULL, 0xA720F188D2E69D18ULL, 0x1A9655D3DC29FABBULL, 
            0x35B36AD23ACB9A3FULL, 0xEF30656008417543ULL, 0xDF0C5C303676BF69ULL, 0xFB568F8F0F37649AULL
        },
        {
            0xD742784C64845EF1ULL, 0x9726493CB4A0EFB0ULL, 0x3CC097FD8C707077ULL, 0xB122A7F81817C107ULL, 
            0x5BA60C947B15B15FULL, 0x02F9204DA3780DA5ULL, 0x8E6E2C42F7531E1DULL, 0xAA376CFB5EC32452ULL, 
            0xBA97ADCF1B9E8E79ULL, 0xF8C4DF9952DE4719ULL, 0x93B2A7238A85D799ULL, 0xEFAEF08396409AF1ULL, 
            0x54ADFE04B2200647ULL, 0xD8403A9EC34B58B7ULL, 0x5485EAAAA46843A9ULL, 0x2895BA6C83070A36ULL, 
            0xCABD773B5A50AD3DULL, 0xA35E53A6D763AEB1ULL, 0xEBEE30031E6FFB12ULL, 0x274BDA5D077AD2D0ULL, 
            0x8A72FA6BB2EB43DBULL, 0x9E923B9AF3542A18ULL, 0x25E4D136DB73AAC6ULL, 0x1B5ADEBA597B01B0ULL, 
            0x327B540A449D7734ULL, 0x7BE57412479BEE93ULL, 0x89E93035904D9660ULL, 0xB0029121CE8A6469ULL, 
            0xF7B08E013758B3B0ULL, 0x2418298089058819ULL, 0xBBEEBEDF42A021BEULL, 0x93FB3CCFD5DD0111ULL
        },
        {
            0x53E29A974ADCB49FULL, 0x1015B9EC1AAA90ECULL, 0x3F6C792AB4C18F10ULL, 0x0ABF81C44C7F4D3FULL, 
            0xF6DD55020EEEC3C9ULL, 0x65D76E1571EDBA78ULL, 0xEE49D0DFD9986D0BULL, 0xF60F3D036A44F148ULL, 
            0x0553A1C499170696ULL, 0x6FE63F0712F6594EULL, 0x050BF0EFB48ADF96ULL, 0x9927D1E7B3CE63B7ULL, 
            0x3E5A0DB2712CDDFAULL, 0x4688C8186376063CULL, 0xA185C1AFB805860CULL, 0xF9A50190AD090D28ULL, 
            0x41898D8531BAEFA2ULL, 0x8DDFAF748CBBD7B2ULL, 0xB974BF61A91AFB62ULL, 0x439734EF67384705ULL, 
            0xD6B7440423181057ULL, 0x4C4408EA42B35CCCULL, 0x017FDEAF6FEBCF8FULL, 0xC1364662336DF134ULL, 
            0x691DC3B32EC87E24ULL, 0x7304DEAC984E2FF5ULL, 0xA634D146BA9EEA31ULL, 0xFBDC49838A0766A7ULL, 
            0xB356ECE99096D8ABULL, 0xD94279D4254EFCE1ULL, 0x3CF32FE0DE193DA8ULL, 0x68458E55B58C6895ULL
        },
        {
            0x95DD0E2E0AB60BBBULL, 0x526FD43975AB9DE2ULL, 0x6DDC66B0F606F238ULL, 0x3260CDFB800FF5CFULL, 
            0xD02528CA3DAC0D5BULL, 0x734F701858BF8775ULL, 0xEBAF9292C913E37BULL, 0x68026F339F322827ULL, 
            0xA8ACCC0253B90423ULL, 0x4B6956875F8A5FACULL, 0xC8551E97932D172BULL, 0x2616922BE1AB5B22ULL, 
            0x8BC4755EA3D12561ULL, 0xA9FBA7E9540BBBFFULL, 0x949497A82D342428ULL, 0xC591739C0213633EULL, 
            0xA16099B642DC3286ULL, 0x529AC330AEDD1111ULL, 0x79D27B301CE30BC6ULL, 0x9FBD49D58E2A3987ULL, 
            0xFDD2D43FE6C88F18ULL, 0x0B059A0C523FEE18ULL, 0x899338163CB972A2ULL, 0xC9BF33A21AD7F6FFULL, 
            0xE81EFF04042FD811ULL, 0xBD5DC8457C90DF3BULL, 0xA5937748EE7A9D46ULL, 0x68514E4EF35EF22CULL, 
            0x78598C4B30E85CEBULL, 0x3C31973980E3F8FDULL, 0x2E4A8926F5AAD09EULL, 0x9A5C274CF9C1A529ULL
        },
        {
            0x9E2A5A9C1B03D590ULL, 0x7811BC3625454F2DULL, 0x67D57E52954CA3B0ULL, 0x96806F0DAAEAC08BULL, 
            0x9E83F72767FCD3B8ULL, 0xEF09D07050B7387DULL, 0xE0209566A5BB88AAULL, 0x9F7897071DE229C1ULL, 
            0x1B35DFC7FC0EED6DULL, 0xB274F5E8986830DCULL, 0x676A3DEECB951C7BULL, 0xE457C5894D5EFFB0ULL, 
            0x7D26C424FF34889CULL, 0xAA1975338EF098AFULL, 0x8A1C0FE7A62458E6ULL, 0xFA24606CE55A3855ULL, 
            0xEEB23C49E2D053FAULL, 0x1313D1FDE3A9DBACULL, 0xB5983ABEEA051C46ULL, 0xF520F774EB17B78CULL, 
            0xF9DF17E0987EBC79ULL, 0xA2E4A87D81B4D928ULL, 0xD6A017A05D7C28B0ULL, 0xA5573DABFE5595B6ULL, 
            0xE82D6B28124A47EFULL, 0xB1484B6B0E2AA224ULL, 0x990D89BA8E654EC3ULL, 0x5A235605E8BB8398ULL, 
            0x1B5A50492AF0D2D1ULL, 0x3213D97293348619ULL, 0x762BFC04B7136565ULL, 0x9805D986AB18817EULL
        }
    },
    {
        {
            0xB8579798B88D63D8ULL, 0x7A9029A6D0E7BED4ULL, 0x0A14B6F73DB32D0CULL, 0x73BD136D5C00D3EDULL, 
            0x31D882498D794EC0ULL, 0x4911EF12B3BA9A73ULL, 0x8843FE059F8D27C8ULL, 0x39DC9A741F72322FULL, 
            0xAA4BC061205C9BA6ULL, 0xEA67494BA04AA95BULL, 0x0F73EC4AAFFA9DA5ULL, 0xD2E2252D05447A66ULL, 
            0x9A2BCD3A45C31669ULL, 0x2E1F95A956EB1C72ULL, 0xDF63AF8ADEB88D31ULL, 0xB67522694AE20FF5ULL, 
            0x4EA19A942D94746CULL, 0x0764FEF3B2FAF186ULL, 0x76CE93E3E1436882ULL, 0x4F53940118E9E5A9ULL, 
            0x8E04A00862B5F61EULL, 0xC1D15ED9D2E4ACAFULL, 0xD08F497AD7D78762ULL, 0xECBC04908597222BULL, 
            0x362CDB94E1565582ULL, 0x7545B4FC26839716ULL, 0xED97AFFF389375BFULL, 0x921F77E8F7D95820ULL, 
            0x614431E8AAD3568BULL, 0xBBF8BD0F4320D6B6ULL, 0x85F2268E9AE288AAULL, 0x971839FBC81B4695ULL
        },
        {
            0xB8A8420EC456E698ULL, 0xC62AFFF95BA64C47ULL, 0x8A1D376D11A58C48ULL, 0x625708D549717CA4ULL, 
            0xBBB9C0B9485C3799ULL, 0xD7CDF108244D31EFULL, 0xF299E8211062B3A1ULL, 0xCCEB00C5402F25A7ULL, 
            0x467A19DAD1A00DFDULL, 0xB6A357E4FDF622B5ULL, 0x418986FE99237AB9ULL, 0x5B708AB62CC06478ULL, 
            0xAB4D8361404685DBULL, 0x984D6DA06FDF202DULL, 0x37ABDAB2D7ABFE92ULL, 0xAEE5B200935635F8ULL, 
            0xFBD83525EEA812B5ULL, 0xC1B09EAAB0902DC9ULL, 0x7CE5455B9BD2C10AULL, 0x1FE49AA75CA332F6ULL, 
            0x4A98DE0295723CACULL, 0x9E1ACD76D21C875AULL, 0x017195265F164FCDULL, 0xAFCBEC37C2CDE15DULL, 
            0xE5B4927889F1FA77ULL, 0xCCF7AE53C1B1A232ULL, 0xDB3684B0EE917534ULL, 0x6CE4841B5E4BC603ULL, 
            0x875A48409984D14CULL, 0xBCBB4F010C2DD95BULL, 0x35A33B392C5D1EC0ULL, 0xCF9AA2DA8DD2C042ULL
        },
        {
            0xB8A0EF55C872368EULL, 0x8F82142C2282D971ULL, 0x05EAA029ED1A63D0ULL, 0x42260B5D9B8D4E5CULL, 
            0xF74D8F75CEF15049ULL, 0xF4AE06EDB67BECBDULL, 0x6E069812350D4714ULL, 0x705A2647DC9304F1ULL, 
            0x1B436AE738DB4E5EULL, 0x9236EBD904E9CBC2ULL, 0x03D42564B8F1E81CULL, 0x36B71ECCAAA30E5FULL, 
            0xB062BB1F65890A26ULL, 0xC5C9896A796B9DAEULL, 0x1CCF840BFC89645BULL, 0x30B3B832D0AC1E31ULL, 
            0xE6CDA3A35CF1506AULL, 0xCC9E4DEEC0FBBC18ULL, 0xFC94DF728760FA78ULL, 0x50CCB122BCCB9F80ULL, 
            0xC5650C8B7324B1BDULL, 0x864F1B3097DA7DBBULL, 0x2B814ADAD82BB124ULL, 0x17B22700AB6D9055ULL, 
            0xB7358E66200EFDFAULL, 0xF670138A700FC37CULL, 0x23D91F7927D4D983ULL, 0x7CD159E0A8AD930AULL, 
            0xF374324CB50D0C80ULL, 0x5EC0F5D840A1E208ULL, 0xE5D91268704B2D6AULL, 0xB086DF3B38243402ULL
        },
        {
            0xDD7204AE8571D11AULL, 0x6E3B0296E6AEB7D5ULL, 0x0A9CD56B374F5871ULL, 0xEBAF917951189A30ULL, 
            0x362D5BDE92C751A4ULL, 0xC3AE8D35030E10E7ULL, 0x8E2BE3BAD7DD2369ULL, 0xF83AFF24084460DEULL, 
            0xAD4CE52D7FA6FBC6ULL, 0xC3E1E34B903FEDECULL, 0x42DBD2B9C0BAE702ULL, 0x95F9FCA9BF489128ULL, 
            0x379F7CA635E5EFAAULL, 0xD9769CA9BE1FAE43ULL, 0x96A53F66B98C63C7ULL, 0xAD3D0A90A6D08883ULL, 
            0x67491D8E884F8FDFULL, 0xD0FCBB3AB052C427ULL, 0xED350B87B0CCEAC0ULL, 0x75FEBBF365747496ULL, 
            0x03D46A00D5FBF354ULL, 0xF24CC205D54518D5ULL, 0x8C2D7E43B26BDF79ULL, 0x31DC40075EC3C405ULL, 
            0x29AA83C1FBE2D384ULL, 0x93CF0E1BCB0F9325ULL, 0x9686F3E456C32376ULL, 0xF1863411017AD852ULL, 
            0x2E39EEF5C8680F46ULL, 0x5792B66E149CF360ULL, 0x410A0175510D1C64ULL, 0x23094E00CBFEC7B8ULL
        },
        {
            0xCE3332079C07B6F7ULL, 0xC356701833394FD5ULL, 0xDABCACCE20BF6214ULL, 0x117A3D3FCADEBDACULL, 
            0xEAE1D46587E43DE7ULL, 0x794E4C128885F0B6ULL, 0x448A3B1637EEEF39ULL, 0x6C1E989072247945ULL, 
            0xC291EED63CF90CD2ULL, 0x582106CFCFDE83F6ULL, 0x026B5E8E822F3376ULL, 0x26D98B98EF347E29ULL, 
            0xD4034F93D1D421F0ULL, 0x7F3A523B92319E3BULL, 0x90F98B924842FC32ULL, 0xF627A90BA7535437ULL, 
            0xD05374BAAAA082B0ULL, 0xFEA43EE07501E0C9ULL, 0x8E839A532911A65BULL, 0x1CC29FF740709918ULL, 
            0x18FDD443C5E7403CULL, 0xB46310D7076E19B7ULL, 0xB69623C1500F44A8ULL, 0x6FD1DE51B105CDD5ULL, 
            0x9543267EDF9EB2EFULL, 0x0C8A65809B7B5FE4ULL, 0x37F895815D1E6CDBULL, 0xA564148C08BB5876ULL, 
            0xAF4CA6A43690A3E6ULL, 0x939035A5AF37D781ULL, 0x7AFFFFDAC0FBF202ULL, 0xD0EFA7CD1F8A7650ULL
        },
        {
            0x741B34CD9EFBAF2BULL, 0x1E15FB2CE2D60A62ULL, 0x4D4515B7A10EC391ULL, 0x3181FA3BB4CE9A77ULL, 
            0x7B4C3921F4652C1FULL, 0xB7F604137B6B4E28ULL, 0x34FF51C77E4E8D6FULL, 0xC1C2413578203372ULL, 
            0xCC4A69F2765C8EA1ULL, 0x4A24007C8428E525ULL, 0x220B39AD3E8BA17DULL, 0xDBCB185D7069139CULL, 
            0x10ED390446CE5EDFULL, 0xD87610F1E2F7D535ULL, 0x07946D627CDD6100ULL, 0x74A107A2E586E320ULL, 
            0xFE41E3CD270BC47DULL, 0x4A0BCF5E8EA4EFE8ULL, 0xCE1D23F630AE16B1ULL, 0xF33F29E0C4E852EFULL, 
            0x7924EE61421405DDULL, 0xC54E07E4B923D0C1ULL, 0x21979DE755ED9E10ULL, 0x8FB915956A66D91BULL, 
            0x66E2FDB308C024F3ULL, 0xDAC774496A29DA7CULL, 0x2990A46A26784574ULL, 0x4BF36597FFF74CA8ULL, 
            0xBC67F84E06024751ULL, 0xF247C10112ABCC63ULL, 0x0D2716E11C6E953DULL, 0xCBDB994D0F0DCC73ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseDConstants = {
    0x33A4357EC56A9066ULL,
    0x23B38EDDEE4771D9ULL,
    0xBCE5668B0DDE1119ULL,
    0x33A4357EC56A9066ULL,
    0x23B38EDDEE4771D9ULL,
    0xBCE5668B0DDE1119ULL,
    0x721BA721E31D17EBULL,
    0x5546C7BE6A2EB6D4ULL,
    0x61,
    0xD0,
    0x82,
    0xE7,
    0xEC,
    0xA8,
    0x04,
    0x70
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseESalts = {
    {
        {
            0x3729BFFE833748C2ULL, 0x0117C3B1E2DD2242ULL, 0xD2840D968DAC2BB5ULL, 0x6D507FC370C607CCULL, 
            0x12975A8A1B6F1E06ULL, 0xC18B413B490339A6ULL, 0x2FE07C4E6B989341ULL, 0x54B0C1AA1BD6F0E9ULL, 
            0x64C40E8849E53D5BULL, 0xE9855970FA9CA819ULL, 0x3615AD43B7E96BB8ULL, 0x10E4FD2C25697DC4ULL, 
            0xA728C9EF59DB3FD4ULL, 0xCBC96F6E84E6C752ULL, 0xC304DA67591E09BBULL, 0x70907B44BD46D726ULL, 
            0x60E1C9368F5FBF9FULL, 0x7B742954531DB6ECULL, 0x012A73EF28CB5872ULL, 0x482D395109821E28ULL, 
            0x76627B8ABB720D73ULL, 0x3A18DEC0F365EDB1ULL, 0x96011A61E2A69857ULL, 0x0AC13379BE810CC3ULL, 
            0xE567F6880C811FBEULL, 0x4AAC1C82465EDA5FULL, 0xBBE8E370D1FD2DB5ULL, 0x2F232D3138B91DBCULL, 
            0xADAC679A617E49DFULL, 0x6E836E56E68892B7ULL, 0xEB5982589F4C16B3ULL, 0x6ABC9CCD6A2C1AE5ULL
        },
        {
            0x29F4B2810B71CB14ULL, 0x3FDD07659CCA7D1BULL, 0x0895652B5CFF155CULL, 0xB3C07404AF5751EBULL, 
            0xB6DF522BFBED00D6ULL, 0xD1CD88CBE54D5A12ULL, 0x761507B3B76FF28BULL, 0x41A0EA98B61C3385ULL, 
            0xAC4F35B46E8FC92CULL, 0xBAF0797F43F4D455ULL, 0x2B2D7FFA1758E2FAULL, 0xCFD6B26647D2D800ULL, 
            0x52284A00290493EFULL, 0x09F6A16CD351D908ULL, 0xB7D102FFE64D1774ULL, 0xAAD6FD332667DD5EULL, 
            0x814BE6DF5C7DEBD8ULL, 0xC562240AE665C6F6ULL, 0x25E902382902D58DULL, 0x32B983DBEFDAA26AULL, 
            0x7E5D76BC7FF06C39ULL, 0x57A2B7B1C0B13381ULL, 0x1B232D5DAE64C3DBULL, 0x640C38D0BE049D2CULL, 
            0x870A76720F2F1469ULL, 0x895D585F1BD31656ULL, 0x0682A2ADE4B7DD23ULL, 0x782A09B86AE16886ULL, 
            0x59E944D483D1F0CAULL, 0xC248838785BD0950ULL, 0x14DAE8DF67D00C82ULL, 0xB2EA94D2F398E036ULL
        },
        {
            0xFCC9B545DB7E48F2ULL, 0xF2FC51607518CA95ULL, 0x51F227C5B1CC70EFULL, 0x882811CEAED42ACFULL, 
            0x638CB4128CEA44D8ULL, 0x01902A0D4A432EF8ULL, 0xC5CB414D97D229D8ULL, 0xAD97C9E8500467B9ULL, 
            0x7DA02387613451B9ULL, 0x9F947717779DDBB4ULL, 0xCD24B3A68607416BULL, 0x9178E196A91D8140ULL, 
            0xB11B57FD04934B18ULL, 0xEA3C7DA2E38EF508ULL, 0x1753CA3C905A2596ULL, 0xECE3DDCCE364FE18ULL, 
            0x105C956D08880027ULL, 0x6AC5C42422DC364CULL, 0xE1937CFD06B48668ULL, 0xD105B1AF0C3DC471ULL, 
            0xA3DED26B997908B4ULL, 0x448F43680E6AEEC8ULL, 0xF0FB7440F9A20D57ULL, 0xBC4C7168BD9822E4ULL, 
            0xF8AFEB3F4457CE21ULL, 0xC174FA04080B5FADULL, 0x85BE3F2CC7687E0AULL, 0x0E064A9612D63B0CULL, 
            0x734AEE03CB78EBD0ULL, 0x26D5D88B76EA99DFULL, 0x30106746336C30D6ULL, 0x1C642163D4D0AD56ULL
        },
        {
            0x712058FB303D12CCULL, 0xF80DAA6713BFF1ECULL, 0x9C639C224D2F2E40ULL, 0x573741506C9A6F9AULL, 
            0x0BC2427AC28123A1ULL, 0xCBB6057B4393DF77ULL, 0x9C56B79E3EDC20AEULL, 0x9C79AA741552005DULL, 
            0x0142707D98033B0CULL, 0x259638A599C4A38AULL, 0xC84A511D1E91F920ULL, 0xE5331A59DB61279FULL, 
            0xEB7791861AC67F43ULL, 0xB36637170FFD31EFULL, 0x61F2A38272012807ULL, 0xFFE41A11DDDBCF10ULL, 
            0xFBEB9F2F2864E9D6ULL, 0x3DB6E50F0AF0675BULL, 0xEF0370644AB56E61ULL, 0xAC3AE62DA4240D66ULL, 
            0x2C7654134B3AEF58ULL, 0xCECE01CD3C4C2977ULL, 0xC2DD250CF428E530ULL, 0x3F6137E8A7FB4A16ULL, 
            0xC4E6CC4119F95FF5ULL, 0xD1028A72B6788934ULL, 0x34B7532545DF4B2DULL, 0x7842773B7A5A13D9ULL, 
            0x12679EABACFDBC1BULL, 0x0C2B7DA493B90A36ULL, 0xE417698A544543F9ULL, 0xC2A9B3285EF956C9ULL
        },
        {
            0x35A82155F3E22EAAULL, 0x8523EE111026D0E4ULL, 0xFACF3CDF758CB55AULL, 0xE10590D77B779F37ULL, 
            0xA07E1C3BE9CC41AFULL, 0x384D84A66C237880ULL, 0x0E875AE860C1F9EAULL, 0xE511813BFA70EAD9ULL, 
            0x1B39D0F2B2AF2AF2ULL, 0xA87347A003C84125ULL, 0x8745071115491BAFULL, 0xDEAA244F733A5E7AULL, 
            0xA787AC790DAF07A7ULL, 0x87EE613AF34B4DAEULL, 0x4CFD2E052C7F8B09ULL, 0x48F0728275B1F0F6ULL, 
            0x9F34A8ED33686989ULL, 0x16786E7782318B62ULL, 0x7062F2A949A1C335ULL, 0xC929524D958DB74CULL, 
            0x4808CAD30C9D1019ULL, 0x21CED298928ECAA0ULL, 0x4EC72DAC44E7804DULL, 0x47E4E94B8EF0783CULL, 
            0xC44B94938256ED3DULL, 0x26535025EF1888A1ULL, 0xBAA8536DC5E3B238ULL, 0xA1833E2E608D4C6EULL, 
            0xFE636C3346DB50D4ULL, 0x082EF2E67AE32005ULL, 0x04EDFE197E95DDF5ULL, 0xD9BFAA2A9AEDFDF9ULL
        },
        {
            0x99E778FE38C49435ULL, 0x9E8AFD45D1F9B6E1ULL, 0xA1FAD0A9EC9A4CEBULL, 0x18DD0ADC6C7AECE1ULL, 
            0x14BFFC76563B14D7ULL, 0xCDD1D682CFA5A87AULL, 0xC574541D09D69FDCULL, 0xAD92E7282FD6D1AAULL, 
            0x18D47AC69B556BC7ULL, 0xF625E79771DB3729ULL, 0x59747D19057556C1ULL, 0x49BA8C1F64AC8D0EULL, 
            0xCF55AA0A06D4A3C0ULL, 0x1A31849CD214C5F7ULL, 0x6B7B655EF4F92876ULL, 0xCDA7DE31DD34DEFFULL, 
            0x724A98AE94D9C0F9ULL, 0x4C58A9A641C0D9C1ULL, 0xE65683F198EF1310ULL, 0x98C2A4AF7DE8A9D7ULL, 
            0xD39E22670D0719CAULL, 0xB8645D08007485DAULL, 0xC10DEBB66951AAEAULL, 0x2633FB583C5B2409ULL, 
            0xCD5930453E579C83ULL, 0x9E17D0C9DA447E08ULL, 0x3904DA1894085B59ULL, 0xE5A1032FBE072B7DULL, 
            0x2898F837890DD48AULL, 0xCE6B0D014EF1540FULL, 0x44C72A6EE56A4F09ULL, 0x7835E81A843489D9ULL
        }
    },
    {
        {
            0xAB7460C07AF126CAULL, 0x8DE19626FA2079A5ULL, 0x16BA6E66DC314371ULL, 0x9BE0B87BC46CF9A9ULL, 
            0xB27AE21074D9BFC6ULL, 0xB5C16442952BDDA5ULL, 0xF3616D63BE4248EAULL, 0xD4F1EC7BF0D91425ULL, 
            0x99E1C9132390C98EULL, 0x3A40E323B311C339ULL, 0x723C8DC73732F6F2ULL, 0x4BD1C854DADF8530ULL, 
            0x155DC2AED9BEFE78ULL, 0x3399AB352F043E76ULL, 0x33F3AFDD90BB1378ULL, 0x5D93A5D6E48AF5F2ULL, 
            0x7A91287EFFFC9064ULL, 0xB8592B4A6AA4D579ULL, 0xC9F4AD8AB7C560BAULL, 0xA00F466F8A965AA8ULL, 
            0x308AF841B8A1E115ULL, 0xBFAAF85B18CDBCBAULL, 0x47751A86E76E4FFEULL, 0x77BF478A5DD202E1ULL, 
            0xDB157B177EFBDF09ULL, 0xC464A1F50237535FULL, 0x7774CC7B8CFC3233ULL, 0xFDFB2EF3D37859F9ULL, 
            0x9CBFBCE43C259CD6ULL, 0xD190A750AE3AC856ULL, 0x7E5E5CC4F0344DBBULL, 0xA77626AE5EA8C010ULL
        },
        {
            0xF7212838B95D851EULL, 0x49F1D2E5A1FADA76ULL, 0x7156D03041F8EA63ULL, 0x76B755CFDADE9B23ULL, 
            0x820AADF252B3A41AULL, 0xAEE8BB2E41708C6FULL, 0x459B236D8F8B3B23ULL, 0xB6A7F3DBDC85E968ULL, 
            0xF2E19AA26CC1FFAAULL, 0x4AE1816BB696B437ULL, 0x375A6F46D6AFED75ULL, 0x57288EA073E9BC2AULL, 
            0x5153899EE2073D60ULL, 0x7D015DEF2C878E99ULL, 0xEF580A41FCCCD397ULL, 0x303AAF85C0C527B5ULL, 
            0x8E522D9F5B28114DULL, 0x74C798A98BA834E1ULL, 0x02BC6010D4CBD689ULL, 0xF2CEEE7C4F61CEC0ULL, 
            0x69A529DA26A45292ULL, 0x27DAC4623EE84BFCULL, 0x744B9D899AC1C62DULL, 0x4A70D7A45A9A8BA5ULL, 
            0xF7B624E3BF2FD858ULL, 0xF6F5CF2F9774323DULL, 0x8E80A3D6733B2B32ULL, 0xF26565C278A15D87ULL, 
            0xF794E8797F532757ULL, 0x600898104C401775ULL, 0xCD65CC390C3794BBULL, 0x9A34D673844E3DE6ULL
        },
        {
            0xA4FAFA0CDBB7F862ULL, 0x2F7250EAAE83279FULL, 0x43C13E0D135DF651ULL, 0xB637C7A19747873FULL, 
            0x7EE29DE22755024CULL, 0xDF347B0823100570ULL, 0x861639F2741EAA84ULL, 0xA0A519823B9600E6ULL, 
            0x48831E8357CFFFA5ULL, 0x6A1B2989B95E091CULL, 0xB3A598F37543447BULL, 0x46B44304FC771417ULL, 
            0xF572455002C92FCDULL, 0xE7DB983BEB10A35DULL, 0x1BA150F67D855F06ULL, 0x1557FDCA5FC15AFBULL, 
            0x9719D210A7A13EF8ULL, 0x6F4809C6ABE02BD0ULL, 0x055E4854D05618BBULL, 0xDC613E34847494E6ULL, 
            0x5D6553A1934F9C32ULL, 0xD5BD487F25B61CC8ULL, 0x0F0BE5E076899386ULL, 0x87798F53F758573DULL, 
            0x40168E4B861213A7ULL, 0xEAD5FB65D270C66DULL, 0x1020817F36B5CE90ULL, 0xEE3F8A906C23F852ULL, 
            0x357F006201E3915DULL, 0x5247C0E23CF0A7B8ULL, 0xAA0E75AE5DFC33F0ULL, 0xAF5ED08BA878BDAAULL
        },
        {
            0xC8273FD54DF8C963ULL, 0xFADF97BFAC34DA45ULL, 0xFF695F73FFE81FBCULL, 0xE1C53B47C5380D96ULL, 
            0xDDD9E06FEFE9B845ULL, 0x10831258DDC03FDEULL, 0x1BCEF234FDA75BB3ULL, 0x85C2A8F619C2EB5BULL, 
            0x7516B36ADEA8A94DULL, 0xCDE849D39B3DF52AULL, 0x2D36194C8B07AB06ULL, 0xA7F60F8194628D34ULL, 
            0xCF96F5577630FBDDULL, 0x52E9858CFFB9F73CULL, 0xD2B587FA62495771ULL, 0xC37C4294A9BFF0FFULL, 
            0x4937B3BCE727A95FULL, 0x3A9AC9EF4DE1678AULL, 0x204480F98DDE3B48ULL, 0xCC796C2E27265144ULL, 
            0x5B5CB3D6CFC503E6ULL, 0x667A847382446C90ULL, 0xC0AE1D72C1BE6801ULL, 0xC1161E88499E22BCULL, 
            0x97041E506EB795C8ULL, 0x0352F60622A3D72CULL, 0x3D253C0673E64F21ULL, 0x0BE6F9FE56B86EECULL, 
            0xB8CE3B1856A8F7F9ULL, 0xBBBDBDFDEB42A274ULL, 0x20E0841BBAB4B6C4ULL, 0xFD6372262D0D1620ULL
        },
        {
            0x6CD3D1EF079C0395ULL, 0x0968AC455C74DD37ULL, 0x6D973206F16CFA7BULL, 0x2AFB6B9383AF77EAULL, 
            0xCE1F1C23124CA6DAULL, 0x992738D3831661D3ULL, 0x8CABFB2237ECE827ULL, 0x3FC584603674FA8CULL, 
            0x98C9CF939158105FULL, 0xE1977645DEA00569ULL, 0xB2097EF52D986839ULL, 0x4F7B8C1A99B770C7ULL, 
            0x8C164DEC1CDF6B3AULL, 0x9203447EEF168F9AULL, 0xC9D36701275C982AULL, 0x5E1495A3B02AD155ULL, 
            0xCB54FB8B7E0403FAULL, 0x25F8B566E756F91FULL, 0xF3EBC9243688D57FULL, 0x3908040CE0F2325DULL, 
            0x1160DB58E18E6477ULL, 0xD08E61687741D7B1ULL, 0x4EDA0648780B1A66ULL, 0xD250E9186FAEC4D6ULL, 
            0x80D506AB4015E641ULL, 0xD62436BA73B31F70ULL, 0x1AE58696765E49CFULL, 0xB689C4371506000FULL, 
            0x9AC59DDE5DB205D3ULL, 0x644002F9FBA21F5AULL, 0xF0804037CE8B5670ULL, 0xC2CC07C2E0DD2B6DULL
        },
        {
            0x846F3ED2FE8A77B5ULL, 0x1759B64C963BDB18ULL, 0xF60FA427F3F164B3ULL, 0xD559083973022ED4ULL, 
            0xB721EDFC60786359ULL, 0x49986DBB36A60A65ULL, 0x225762291FF91ACFULL, 0x24396772A0ACB0EBULL, 
            0x6A56ED622F2A7794ULL, 0xCA055CD471747030ULL, 0xC5461774772F8A42ULL, 0xDF6EDD0A12051167ULL, 
            0xDAD8D1CF2DA90A20ULL, 0xDA1FAD2BAF82A409ULL, 0x91AF9B2C8DE0DFBCULL, 0x927B0B7914486217ULL, 
            0xF0C48F5BD1530005ULL, 0x9246E249AC2340FBULL, 0xA044481248896638ULL, 0xB912C839E864D7C3ULL, 
            0x602A584B4FD0E21AULL, 0x9AF91EAFFDE9EE14ULL, 0x1BB67EF744539E7CULL, 0x67BAF1D4698F92FAULL, 
            0xCA3D05EE054AC416ULL, 0x143438D5187DC5D0ULL, 0x35977D8F6EF0D23AULL, 0x0B6863A09E515ECCULL, 
            0xD5950C27B120D1EDULL, 0x918010A55258E5B3ULL, 0xAFFA177E5D083171ULL, 0xB7513C5250C03BE1ULL
        }
    },
    {
        {
            0x2FC1F0AC40D82676ULL, 0xB46D464C7453FAF7ULL, 0x75FB850C0A5C9841ULL, 0x474ED71AB316CD13ULL, 
            0x289A2CD7CC9D11D0ULL, 0xD81AFA38F9D61E85ULL, 0x5A845802DA20EE03ULL, 0xA177D1EA80AB5239ULL, 
            0x82087F4A99B71246ULL, 0xC29430C2526C413AULL, 0xF8BAFEF58FD31560ULL, 0x9E54A5E15129E3B7ULL, 
            0xBDAC96E4BB52DA6FULL, 0x07B1B289E1ABA8F4ULL, 0x2B54901256465CE6ULL, 0xFA1E2F19885A9345ULL, 
            0x87E1B67A8911D2ABULL, 0x0F6D1DE12032B247ULL, 0x5C149948EAAF5476ULL, 0x9A7B64BAFBE6D482ULL, 
            0x6ED2C28D09BD9C9BULL, 0x580F0316AFEAD766ULL, 0x367275AB66AB53F7ULL, 0x35BA6975A188FA0AULL, 
            0xD969C8FE3136505DULL, 0x5829346B76611849ULL, 0x1BB0D48584B5AE5AULL, 0xBE799558074309E8ULL, 
            0x3CB5C69B5A2F467CULL, 0x9F743871214B9AE1ULL, 0x584A3C83B70DC01AULL, 0xC8A70DF8620FEDCDULL
        },
        {
            0x6435A25AD079D10AULL, 0x2E5B2EA304A981B3ULL, 0xE148D99A6E01BAA8ULL, 0x9156EE66FC25380DULL, 
            0xD0913EC520B980E3ULL, 0x8B8CF65CBD9FE838ULL, 0xB63DC68BEF216C52ULL, 0xF5A3FFB5B4A8779DULL, 
            0xBAEF675470CF9585ULL, 0x7D551CE872D87E6DULL, 0x208D3F5AB577DB89ULL, 0xD1105F77EB0F4926ULL, 
            0x8BBADC0CF7409390ULL, 0x033D0E092A741D0CULL, 0x06B80C38260761AAULL, 0x8072CBB338979ACBULL, 
            0x3DA722D753BFD1FAULL, 0x5F985BC67A00699AULL, 0x8282FF2ED71641FFULL, 0x855F43DAB957D11FULL, 
            0xCEC41784E48E6B1BULL, 0x00925F91CADBBD64ULL, 0x9E020D18F6CE9E25ULL, 0x12AD16F25DD9FBEBULL, 
            0x973330BEA9A98723ULL, 0xD5BEB502E9398571ULL, 0x963CDDC577B6A580ULL, 0x0CA7B2899C9D8244ULL, 
            0xF2E4422752B1E54BULL, 0xD17C52BD825828F9ULL, 0xB9B7BC24ED404664ULL, 0x558E8F8E3CC5ACE8ULL
        },
        {
            0xD644A0F26E41DF6CULL, 0x079FD250936146ACULL, 0x8461C665D46AEE1BULL, 0x2566A1F034116F94ULL, 
            0x6DE4AD8C0970E4B2ULL, 0x9EC49EA69E8C80A8ULL, 0xE4425627BE858C57ULL, 0xC063EC7B00FF7D98ULL, 
            0x8E7F023AD43E5F3FULL, 0x951F1594C82372F7ULL, 0x62351BB3B0F8C628ULL, 0xDF387A1FE9E27887ULL, 
            0xACA1E8A605A84DDCULL, 0x09C3F0178DB25FFBULL, 0x3A1C755C0CE19FE4ULL, 0xD87DE570998AC037ULL, 
            0x1B27C18939E6EB23ULL, 0xC009CDB92C21710CULL, 0x77CDC759E2B42F4CULL, 0xDDB7788ACD8BC701ULL, 
            0x82FE04FC785A2BA4ULL, 0x6B8D0160E1092389ULL, 0x8747FCC135C82EABULL, 0xEC14269D2955C21AULL, 
            0x092C221F157A28D3ULL, 0xABAA8D38C74B6CF1ULL, 0x20921F57FCFB9575ULL, 0x5ED1A6FE93BD5399ULL, 
            0x0CD6CE55443CFF58ULL, 0x279BB05FCF277A98ULL, 0x18AA67D109EE4FD2ULL, 0xBF4092F527DC1367ULL
        },
        {
            0x1AE8F389BC8A9FEEULL, 0x916EB5531D9F5F22ULL, 0x102402586F28100BULL, 0x858FACAB79D8A2F7ULL, 
            0x936674BE10F2B4F2ULL, 0xA860B6C52EA863CBULL, 0x70914F60976404FEULL, 0x2EC539CFAECF6CA3ULL, 
            0x7987A4BA3859FE17ULL, 0x0C1D0BB76D04802BULL, 0x2988117BE876D5D7ULL, 0x71BFFEB36A4AD663ULL, 
            0x4F5173E96363EF17ULL, 0xAF2D356D6C2E7C13ULL, 0x271B51016994C192ULL, 0x223543EBE56EBF8FULL, 
            0x1177D372FBDB5448ULL, 0x051D08015ACFEBE0ULL, 0x9A22534825074D3CULL, 0x5912BB5347F044CEULL, 
            0x14B1C959360D6E35ULL, 0xFC7A04DE18A9F310ULL, 0xF7B63E5AC3242939ULL, 0x36F8CCFC04E5CFD4ULL, 
            0x2913B506CEAE16E0ULL, 0xB30817DF9E597C4EULL, 0x7E7517E1D85BEF4BULL, 0xC29FC835FAD3329EULL, 
            0xD8AD0EAE6E8692DDULL, 0x2DCB67C059D80009ULL, 0x64CF237606E2AD76ULL, 0xB3CC3CF3322439F7ULL
        },
        {
            0xFA5B2BF33DFF012AULL, 0x47D1E5E48E51BC5CULL, 0x7E3DE6564F824D55ULL, 0xDDB5398350777FD0ULL, 
            0xE4A7AD93A8B1A33EULL, 0x68F88EFBDD76F56FULL, 0xC26261AECB3CF72EULL, 0xE02C3E6AB7B349CBULL, 
            0x523C6B8CB2663ADFULL, 0xC71A174E098C1D67ULL, 0x0DC9BD2D2DC9D8C3ULL, 0x44E1A74F9F894A4FULL, 
            0x45922EA9CDDBE6F4ULL, 0x953C51A1C6EAD780ULL, 0x70152A69912D8D96ULL, 0xC329C3DB97471DFFULL, 
            0x092049509AFC106CULL, 0xE649AF3304965E77ULL, 0x660C14478C8D1D44ULL, 0xA64A7FF968760962ULL, 
            0x8C31AEE33B6114FBULL, 0x56ABD14F9977E347ULL, 0x2C52A4FD8652AEA2ULL, 0x436F40E11F04F452ULL, 
            0x6B3924E128FC7F18ULL, 0x4914213FCD0EBD4FULL, 0x580C7E60FED93BD3ULL, 0xE053850CC3491C6CULL, 
            0x6707B7FB1570B07DULL, 0xDC2479CE04515C48ULL, 0x23190EA7307A2BD2ULL, 0x7CCDEC7D39924D74ULL
        },
        {
            0xD18F7790B757CC02ULL, 0xEDE15652A7C1DBB3ULL, 0x23D770ACEDB2BF2AULL, 0xF683F248520DF2BFULL, 
            0xCAEA89EB68091554ULL, 0x0BF17CCBA65F2B80ULL, 0xBEE82EC69BEF5E43ULL, 0x8004B0BB17189378ULL, 
            0xB6974D82722A79B0ULL, 0x37059B29ADFC60B1ULL, 0xD8279B720A6DEF62ULL, 0xF6FB9DA2AB2DCA91ULL, 
            0x3798CE3F6C84F33DULL, 0x0A94B2D738A5F204ULL, 0x2691973EB364BFF7ULL, 0x13E6985F06D391E9ULL, 
            0xDF4BD17141855861ULL, 0x08CE109CE0911D8AULL, 0x2A61FFB7A0EAB1A9ULL, 0x61BDA58900C76273ULL, 
            0x44F5AC2B302778DAULL, 0x133EAD8D36179843ULL, 0xDF50C27462A8C756ULL, 0x09B51A189A5E7BBCULL, 
            0x318A740A1592A318ULL, 0x707F146D83B97F54ULL, 0x4BD74AC50C9C1568ULL, 0xE99FE7329E633BC8ULL, 
            0x8DB20D0645A731D3ULL, 0x9F2503079E9A8969ULL, 0x85B79AD5F42447AAULL, 0x8D0922AA784DE6A9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseEConstants = {
    0x63C4F20AC029F84DULL,
    0xE2794A3505E0F5D3ULL,
    0x93303F40AE10A293ULL,
    0x63C4F20AC029F84DULL,
    0xE2794A3505E0F5D3ULL,
    0x93303F40AE10A293ULL,
    0xE5E7A269DD43402BULL,
    0x65B2E22A728AA5AAULL,
    0x23,
    0x2A,
    0xB7,
    0x75,
    0xF0,
    0x8D,
    0x2E,
    0x1E
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseFSalts = {
    {
        {
            0xBD86F533EC242018ULL, 0xEE6977CB080DE49DULL, 0x73CF93CA475937E7ULL, 0x3820C7296FB14EDFULL, 
            0x248708FDCF9A6814ULL, 0xEC70CDF0F0F110AFULL, 0xB0B52ED7D5EA1CE0ULL, 0x1FA2632117678984ULL, 
            0xFDC7F2C00D5A8F31ULL, 0x1122D322B463D949ULL, 0x0FB1380A49E9B879ULL, 0xA12BC3E3250BF018ULL, 
            0x448EDA3CA16653BCULL, 0x5CB7340C045A2DF0ULL, 0x0D280D8A73B44EBFULL, 0x0B292363E335BE4BULL, 
            0xA41B787686F801DFULL, 0xDF4EAACAB0A39195ULL, 0x9299E4B622E1A975ULL, 0xCC4A0ED7C157A81DULL, 
            0x21D9A0795D7EE4E8ULL, 0x3A09533293A4C08AULL, 0x72750D2520DC2400ULL, 0xCED1014E7FB144F4ULL, 
            0xEB0F1CB167B2CA54ULL, 0x4B4A4CBC9F32AD0BULL, 0xADADC3D126AA1B72ULL, 0x7F5AA85E31316DD3ULL, 
            0xBCD548FF0F4A51D7ULL, 0x50FC552BF74AF564ULL, 0x8C702CF6905FD3A2ULL, 0x57CE350E92574BB9ULL
        },
        {
            0x258BAA05CBD1438AULL, 0xB32AB03483930329ULL, 0x306D3E8A83FFA6DFULL, 0x7CE5F6317F338E0DULL, 
            0xEB51CA204CB35976ULL, 0xFB41A31BAB9E360BULL, 0xCB8BA8A3C67BBEB7ULL, 0xED294F7EF5720AF5ULL, 
            0xD42A8ED247EABE55ULL, 0x213BC54193B6EADBULL, 0x25483692C37FD4E6ULL, 0x1FF00BECFFBF3F8FULL, 
            0x61560559B073CC44ULL, 0xEEF792DA81616862ULL, 0xB78EF57023D888C4ULL, 0x1F9F32B2EA5E10EFULL, 
            0xD7A0A2658F84E273ULL, 0x2BC04D5072CFABA5ULL, 0xDCE8164A1FCAE2DAULL, 0x5B67850484906E47ULL, 
            0xB5E43D4EC78ADC96ULL, 0x07EBE3E697C803E6ULL, 0x228D2A1ED6CB052DULL, 0xEC5AB16C1CD1ED7AULL, 
            0x521EF231F9F6D5ACULL, 0xB21FAD500B64A3BAULL, 0x2AE345815DD1ECAEULL, 0x5929F7360193200DULL, 
            0x2CE21B1A11340974ULL, 0x3FF12CF7282AD093ULL, 0x77C3E68A8626DF91ULL, 0xE78182C5D73CC42EULL
        },
        {
            0x3652C51ECB5612CDULL, 0x19A9CAD855D7FE6AULL, 0x8210DCC681E27849ULL, 0x46C3EABB83F4F814ULL, 
            0x05D566FBC2675C97ULL, 0xB1DD210FF9CFFDC9ULL, 0x8D34A797D6F30F4EULL, 0x0331BF211648FA4FULL, 
            0x745B8CD4F3B010B9ULL, 0x48313DAFD4B001CBULL, 0x8BFCEA88DF861516ULL, 0xD693B999B8921E8AULL, 
            0x8407B51CDB36A7A1ULL, 0x687550EBBE1A4A00ULL, 0x96E929C6AB9CA276ULL, 0xD30FF90416C1CB1EULL, 
            0x8C7234077DB6BA08ULL, 0xB4C37B8DD94F4F54ULL, 0x617951758D2A3599ULL, 0xB621F4B8C9BBFFBFULL, 
            0x001EF16240E9A7F4ULL, 0x7E3B438B96F20989ULL, 0x4D6A5AF9442BC658ULL, 0x6A207A7493E09101ULL, 
            0xC7A2CAF2AC9FFE95ULL, 0x44815521FDB0A6C3ULL, 0x60A475860277D42EULL, 0x27D404ABEC1F74B4ULL, 
            0x425BA338E1E301DCULL, 0x2772C66C4C4ED4F2ULL, 0x9A69968903542DD8ULL, 0x171AEB20B9CA180EULL
        },
        {
            0x87FD1F0E953FCD63ULL, 0x0231636F1B294C08ULL, 0xC50665E7B113F94EULL, 0x04DC6333B484D2B3ULL, 
            0xE713BD6793422EB4ULL, 0x18F45D056E8FD5C8ULL, 0xBD4B2B35F310CDE2ULL, 0xE077E493C9D29233ULL, 
            0x5C3412E008516222ULL, 0x5C3AEBE7FFFDAD80ULL, 0x128D8FFFC1BE3243ULL, 0x4F8A4019EF5B0E69ULL, 
            0xAF11422FFE2121DFULL, 0x82CD0FEA191BE0F6ULL, 0x95C57C246975121DULL, 0xCB245050A2109C5DULL, 
            0xD8AA100B60AF71B2ULL, 0x6B1FA7FFD8A2B7D1ULL, 0x3ABD857A465EA2EEULL, 0x5B7C0B72CE2CDDB7ULL, 
            0x0C247404B6D3CD41ULL, 0x2576B73D68885098ULL, 0x84DB5FDFB34799DAULL, 0xB200FC33C24CD960ULL, 
            0x48F50AD2670CD665ULL, 0x8F4412D4EE0CE633ULL, 0xECB82AD56819D2F4ULL, 0x9DF0C3FE79386411ULL, 
            0x5C885D622522EC6AULL, 0x73773D76BC03D269ULL, 0x227860BE6E6289F1ULL, 0x8CDCAD9B2C88A190ULL
        },
        {
            0xC07A0BAED750FDF9ULL, 0x1BB623B856A40761ULL, 0x7A409FE93963E542ULL, 0xAA7CBFC4FFED6AE8ULL, 
            0x47133D518C5A0DF4ULL, 0xD26129BC4F0DE0DBULL, 0xF1741BD7A802F1F3ULL, 0x52C5CE56F94F2C39ULL, 
            0x0FDEBA9FB418FDF5ULL, 0xEF2092DBC52A9957ULL, 0xBB1A5F5BC744BD98ULL, 0xF75EF8064E2716F9ULL, 
            0x2F8919FC321BAB6FULL, 0xD33F2DE9423231B4ULL, 0xE07C3B75A9187899ULL, 0x30018C6525D505AEULL, 
            0x7D7A747BE58EAECFULL, 0xDF25D05522AA22F5ULL, 0xF63FB247927DA6C9ULL, 0xCE78C624AEA7F44BULL, 
            0x5D9A9AF14A4BD4C0ULL, 0x36A214C67D5D2C54ULL, 0xBC52E6F52EB33143ULL, 0xCC1617701DB30909ULL, 
            0x83BC72996B0954B9ULL, 0x515B6D65720ECF49ULL, 0x53C1D702088A6032ULL, 0xE48BACA552021E70ULL, 
            0x1EA5B60072BDB530ULL, 0xF46902E971A2488AULL, 0x773817576A2ACC01ULL, 0xFB97652925F9D514ULL
        },
        {
            0x0527E2F1D485B28CULL, 0x07F64418E958DA84ULL, 0xE7A80E2C0D7E32C9ULL, 0xA9753A5F59A607CDULL, 
            0xBEDA5024BDC06C92ULL, 0x9DE24878C09BE14DULL, 0x387A3BCB3C3A55BEULL, 0x460055138EF120A8ULL, 
            0x452F2BCAC98AD96CULL, 0xF57E3A566E9BEF6CULL, 0xCBB472FB9B8C99CAULL, 0x4AC4362B75AD7247ULL, 
            0x04BA96D0B76D284AULL, 0xF758C5ED12821472ULL, 0x90B2C7980C3D440EULL, 0x7EE96281BDB3D45DULL, 
            0x367B3D3356FC7AF2ULL, 0x52F31C21BCE24C11ULL, 0x0C4B2D6086E56003ULL, 0xE831EC569F12D0A6ULL, 
            0xB911CB7B39FDEFB0ULL, 0x9BEA0E4A4695BF1BULL, 0xC22644138891B508ULL, 0x0AA0ACCCF7BBC70DULL, 
            0x2278546D397AE754ULL, 0xE8A2FB7C7575F15DULL, 0x0BDC5828B773800EULL, 0x25C91F487A170217ULL, 
            0xB22CEB3828AC0430ULL, 0x7DBA79CD8D2C319CULL, 0xCB48ABD06161E053ULL, 0x93604D59A3957402ULL
        }
    },
    {
        {
            0xF4391F401CE11D0FULL, 0xC80D194A1716250FULL, 0x3EFDB04CE06516FDULL, 0xB4C41E69633E9812ULL, 
            0xB7212645DD0D2B39ULL, 0xEB8EFBA590AC816DULL, 0x078347A1FCA47105ULL, 0xCB37AB459E3B5B00ULL, 
            0xA1657EEC79E9126EULL, 0x407FC4A353FB159DULL, 0xDE44324DFD3DF94FULL, 0x5E6913A8AD8996F2ULL, 
            0xC7CAA80480EE5F00ULL, 0x30931B910762F4E2ULL, 0x8035D457EF4474E9ULL, 0xA7417263D865C8CEULL, 
            0xF6A0FC0D71CF5F6CULL, 0xAAA98751E80266ACULL, 0x5D266B66A613F50DULL, 0x4A397ED8E27A07A0ULL, 
            0xA1907B5B8BE02A9FULL, 0xCBA1EEF00AD45057ULL, 0x045CA943DA0B4AE3ULL, 0x226C004CA2E39160ULL, 
            0x64FB93FD5C02B00CULL, 0x6769B9ED0D07E34FULL, 0x287D71EBABEF21ACULL, 0x69A9E5C5333CF10CULL, 
            0x958D549BDF5AFBEAULL, 0x88ACEF34E0CD0FC0ULL, 0xBA841F43AB0FC605ULL, 0x3F90157DD27B62C1ULL
        },
        {
            0x7DD389D9B6B83FB2ULL, 0x329AAA64136CA109ULL, 0x65995304753C73F3ULL, 0x25953C34D8C9B642ULL, 
            0x48974BE039026767ULL, 0x99B36D28D1949949ULL, 0x945377A9CF769B86ULL, 0xE264B954B8B66A6FULL, 
            0xB082F2AFCE7EC42DULL, 0x042CA87E9B21DC22ULL, 0xFB7E24059A5A8EF7ULL, 0xCDDA9D1E5AE0B2C5ULL, 
            0x6FCD62572F473B08ULL, 0x8B177C47AB6A37B1ULL, 0x45374B27D080C495ULL, 0x7AE2133438680D69ULL, 
            0x972897E996045CABULL, 0x0A77FCFB34D40200ULL, 0x67047E46609E60E4ULL, 0xC44859D4BEECFC06ULL, 
            0x3B230E3F179B4BBFULL, 0x99DE151441997832ULL, 0xFDC613F81FD85E73ULL, 0x3E91524C88457DBAULL, 
            0xB10835EFF3D810B9ULL, 0xA5E0D81F978A1324ULL, 0xED594F1B66971BE6ULL, 0x37EF219D68CF33DAULL, 
            0x44572C5CFCBDE88FULL, 0xFEDB018AEDBC0F37ULL, 0xFC9C059A98072763ULL, 0x76A5462E345C5FDAULL
        },
        {
            0xE26FC19B585909D3ULL, 0xD5DE53EE7AE3613BULL, 0x6B8E5D27C4028B65ULL, 0xE703B9875E35F791ULL, 
            0xCCD6AE70B548ED40ULL, 0xE7BDE2E5915B2D20ULL, 0x9F87803BF1208186ULL, 0xEB063B41D9E54C80ULL, 
            0x8786B500CEEC4BB4ULL, 0x4E67AA954FC991F2ULL, 0x949766A42A3C7AD5ULL, 0x8C37ADB08656B216ULL, 
            0x43C3480624ED6914ULL, 0x859A7BC74F85D867ULL, 0x78EFBBA23C433319ULL, 0x2061F099CFD5B200ULL, 
            0x68271B8F171E71A1ULL, 0x3A013CAC54BCF41AULL, 0x673FEE92C3FBE48EULL, 0x36435946C90DD5FEULL, 
            0x8B9E7D47EDCEB5DDULL, 0x54E9807144654ABEULL, 0x3544BD3F622F6156ULL, 0x8CD4298D56010A2EULL, 
            0x63EDB610F2A99C24ULL, 0x9657E9C8838592E6ULL, 0x9E8F29A5C48244D8ULL, 0x8FDCACDDFDC3102AULL, 
            0xB16EAA2F029BA834ULL, 0xC94896AF0394648BULL, 0x05337BF94970599AULL, 0xC58DAC09A0835564ULL
        },
        {
            0xBD39827116C64166ULL, 0x900026CB53789A00ULL, 0x1CF281FE601AE4A0ULL, 0x135F9F83923F3CF8ULL, 
            0xDFFF5401ADFC9A81ULL, 0x5CB4377024196A23ULL, 0x1932D45EE58B1F0DULL, 0x9CE7BABC2F8D8CA1ULL, 
            0x937AE2229C70B2EDULL, 0xFE1E94A3C7F3660EULL, 0x0CCDB792FEBE6301ULL, 0x935EBE7E7437AA5AULL, 
            0x27EBB4007D382A6FULL, 0x254E29471218E80BULL, 0x4F44E7EC8A1E89FBULL, 0x402E4C88AAC82442ULL, 
            0x8FD3CBB26CF5D2FEULL, 0x9A07C06B8DDAEF8BULL, 0xA57E2361301BB419ULL, 0x5C9EC87440A2B78BULL, 
            0x807565E103C6912AULL, 0xB69C65652F266C84ULL, 0x6057A39FC5B781A9ULL, 0x960ACCE769A82E7EULL, 
            0x2D19FA06E4E568DEULL, 0x14AE7FF1A897A9DBULL, 0x949530FF77AE70DCULL, 0x45C9BD3FABB59ADDULL, 
            0xC36B9213BD7C6368ULL, 0x35E216EBC42DBDC4ULL, 0x325BEB9D12715760ULL, 0x2B2FF9146E5096CAULL
        },
        {
            0x5DAE1DCA81AD3575ULL, 0x7E8DCEFFEDA3EE53ULL, 0x5CD047C50B0C4281ULL, 0xD1C20926CF826768ULL, 
            0x2494EE65AEAF9E4AULL, 0xDA36976D662AC420ULL, 0x94AD3EF4DE5B471DULL, 0xD6B9DABA60172796ULL, 
            0x33B9C3D26E13DD87ULL, 0x2AEDF35AACC9A29EULL, 0xB8F7ED08F745D348ULL, 0x249C375E06FA814BULL, 
            0x546620EB9D997B3AULL, 0xDC15A77750B500F6ULL, 0xE48FB3DF7386BAEDULL, 0x8DE62EB655519767ULL, 
            0x049B0621504CE5B8ULL, 0x8F1A164363B672F0ULL, 0xECFA012FFE401FCEULL, 0xE8E79376C6C01C7CULL, 
            0x7E31E2E86F1A47DCULL, 0x309F6CE9C785BA2FULL, 0x7017BF58FF9811D8ULL, 0x2392308F8993BBBAULL, 
            0x1D4A23EBCC11C55BULL, 0x10DA1464B48FB5DBULL, 0x65DEE8C6C9D89629ULL, 0xD651A4275A30CC44ULL, 
            0x4D52866ABFD2C1CFULL, 0x18FEACBD70934905ULL, 0xA829E76E33A0F69FULL, 0x34E23E1A5DD1FA43ULL
        },
        {
            0xDEC09701D51A38DCULL, 0x27554D442AAAEEC4ULL, 0x3F800885340CD741ULL, 0x81058808C161EED0ULL, 
            0xAB7E44076671C6C0ULL, 0x811B721406AEF8C0ULL, 0xB97E5F167658B827ULL, 0x80FE89B5013473B1ULL, 
            0x4ED8E9AB023C6188ULL, 0x0B75E16438F4D733ULL, 0xB1172C60FC8D1B8AULL, 0x239634B8D8D70ABBULL, 
            0x2C696905EC4CD5B6ULL, 0x2037E8EB8F3FFF25ULL, 0x137138BDEB028AB1ULL, 0xB8F185CE7C815910ULL, 
            0xA5E264F2A5628F3EULL, 0x17067D7A3198B668ULL, 0x8118D7BE47E0C001ULL, 0x118B3C97F80F4FF0ULL, 
            0xE7BA180A0453257FULL, 0x7F6C662420F4FF23ULL, 0x8B1BF0B5A8827D9FULL, 0x01BFF50079861950ULL, 
            0x0CBDCAF6F18A23CDULL, 0x7588615598B2136FULL, 0xEAE28971C63A4D5BULL, 0x970884CDCBB91A37ULL, 
            0x0E9F82AF1B0188A7ULL, 0x9A7C2F24CD86F910ULL, 0x46ACF53F1D2754A2ULL, 0x89D00234E3B32D41ULL
        }
    },
    {
        {
            0x1989E30EF4C3C4A2ULL, 0xD9C13C38F0D9607DULL, 0xAE1D82D8793BFF26ULL, 0xD1BA12202BD247F1ULL, 
            0xDB93E5551FD79E50ULL, 0x46088B47E9E367EBULL, 0x7E49E63FC9D3BEB8ULL, 0x9F3238FE5E4B94BEULL, 
            0x23B16483237A8280ULL, 0xE85FE33AA3422076ULL, 0x1E7BAB4CEE087E55ULL, 0x896CA0BA35FD0738ULL, 
            0x83B74BD759C1DE89ULL, 0x2D6C813AC05204FFULL, 0xB5519404FF3FA5FAULL, 0x3DDF5ABE2E786FB3ULL, 
            0xE0B611169F9972DDULL, 0xBBE2A35FE8379014ULL, 0x24F1C8E7B5D77682ULL, 0x32451383381B568CULL, 
            0x1FDE7E394A84920BULL, 0x38A2410E7E7BFF45ULL, 0x4386E4A685E19A68ULL, 0x145C974F09F81402ULL, 
            0xA356E2E83B9AE465ULL, 0x0046A21F991789E8ULL, 0x49ED5259C8461021ULL, 0xB6B56CBCEC33262EULL, 
            0x587E8131E0A442F5ULL, 0xE5979CE766E8A16FULL, 0x5488486077680274ULL, 0x18E144C47456E4FDULL
        },
        {
            0x2D576601E3EA35D1ULL, 0x30B3AE05796E2092ULL, 0x4AA576C8C62E300BULL, 0x8637C7F98635090CULL, 
            0x868BEB2F70A2F163ULL, 0x76759D81369ECFF1ULL, 0xDBC635CF84B427CFULL, 0x8A2599AEE60958F4ULL, 
            0x5AA02F7ED5ACF1E7ULL, 0xF9A9386BE968E4DEULL, 0xF85271FE066EFA23ULL, 0xB3EE341AD5CBC6CAULL, 
            0x3E44EC23559F61B1ULL, 0x97E85DB36409C8EEULL, 0x06D5114793B34A69ULL, 0xACB3C7E7E41D85B7ULL, 
            0x1F9AEDE0454D7DC8ULL, 0xB94AD7DBAFDECF9EULL, 0x28276E71648FAA6AULL, 0xE3C608EDD09FC5BDULL, 
            0x936ADF2A89504CE0ULL, 0x3F88724D7544BFEFULL, 0xB2F687230DBDCFE1ULL, 0x8FB2BCC75B7C9936ULL, 
            0x34B9BEFB6F9ABD2BULL, 0xFD37B77E339542B9ULL, 0xBF9059E02AEFBEBEULL, 0x7ACEB46BD3CB4EC8ULL, 
            0x2DA9133BCAB2498BULL, 0xF162503D2A07AFA3ULL, 0x7CD6B2053174E205ULL, 0x9246F259FCE4431DULL
        },
        {
            0xF4DDC225A168716AULL, 0x60D1ECF5D29220FAULL, 0xBD4AFD3D5140FE28ULL, 0xB5B85D5A482277B3ULL, 
            0x3FDA6D84BCCF809DULL, 0xB645AAD7E809540AULL, 0xB41507B4FCE7FDCBULL, 0xD54A87B320566C52ULL, 
            0x9E863659CA8407EDULL, 0x9780978094083C12ULL, 0xEABA8F7F5BA5099AULL, 0x6C2EB47340D6A4C9ULL, 
            0xFC63E961BDCDD631ULL, 0xF4583B88F5289A47ULL, 0xFB392C5EA2135300ULL, 0x2890D9871747C19DULL, 
            0xA1BBCA0D74949D54ULL, 0xDE8E639057FBE854ULL, 0xBE68BB9C77EBC0C9ULL, 0x70A8F37D37B2ACE3ULL, 
            0x48A35AE1A27673F1ULL, 0x72434B7FDBD79CCBULL, 0x846E9E38EF7B6C23ULL, 0xB262DED5F38FC186ULL, 
            0xE3370FBC2AE94C2AULL, 0xC2DE9A1BC9E1D386ULL, 0x0D16471A845D5B52ULL, 0x61075508592D757AULL, 
            0x7DCEDC13249A894CULL, 0xE642684321F0EA40ULL, 0x65266ED0D5209B48ULL, 0x057DDDE6C2CD17C5ULL
        },
        {
            0xD714D11B62459894ULL, 0xC70B8E0BDBA15A3EULL, 0x33297B62294C30ADULL, 0x690C9589EA208D66ULL, 
            0x57C5E416C02CA1F4ULL, 0x9F9F09D5D1631560ULL, 0xE812E7A4F48561EAULL, 0xA4600A95D5F7035BULL, 
            0x15C80663A9E4FF04ULL, 0x000600516B35CAF2ULL, 0x82C0AD8751224074ULL, 0xC937B8AA1A2CDC5EULL, 
            0x0A4B405A1CB7AB56ULL, 0x71C300453B4F5925ULL, 0x4E6520D1B3420C32ULL, 0xD7C4FF9BA249BBC7ULL, 
            0x0AA5E0C80A5C84BEULL, 0x3FF69744BC8426EEULL, 0xD9887FC5D1C640B4ULL, 0x7372770455A57CE1ULL, 
            0x86632E177BFA1DE1ULL, 0x5B0BD4D973AB16B4ULL, 0x6026887E1E2ED063ULL, 0xECF6F4B01C2B2FACULL, 
            0x96334A0F0233BAA3ULL, 0xAE0F9439CF312D68ULL, 0x895A3F1F9B92B589ULL, 0xBBEA5C334BAB5E1EULL, 
            0xABB9E82E8FDEA872ULL, 0x0CFDDAC4F4D9A5C6ULL, 0x2B826FA585483A4DULL, 0x3FD5998608916C6FULL
        },
        {
            0x0704DB71FB5128DBULL, 0x2A22AA79FBCCFBC5ULL, 0xF5CBC002B0929CC9ULL, 0x843FCF3E253B5B7AULL, 
            0xF01E60056671E876ULL, 0x435ABBD0BF87F6C8ULL, 0x367C8282D765AD47ULL, 0xD68A28A08FD40C63ULL, 
            0x81A74C0FAF516EE6ULL, 0x121278F55523B73AULL, 0xAA512F74C0A1A47FULL, 0x02E846359BFD10BCULL, 
            0x835D807A461AD262ULL, 0xC73E6C646E7B481BULL, 0xBE259C244AF7CAF7ULL, 0x70CA2C53983818A5ULL, 
            0x500DD58F35997E4AULL, 0x43FD7BAB8CA82CECULL, 0x9063196EBC29B2BFULL, 0x3F7D74F5D98D0CEDULL, 
            0xBE0FE0070E65A869ULL, 0x722BCCF0187DB5EDULL, 0xC6DD7775633BB88AULL, 0xD0EC56BF0D0ED734ULL, 
            0x52506C8636FC0B03ULL, 0x0C0EB0A1F455EF76ULL, 0x566C563953644E15ULL, 0x8328D32EC71E4FD4ULL, 
            0x685D46A89DEFBD07ULL, 0xA1D3BE71691CFA8FULL, 0xBCC23A98FD5DF908ULL, 0x1E96B7F5D2E3EE19ULL
        },
        {
            0xCE6F997B0AFE3DA7ULL, 0x6118F1FBE62AC226ULL, 0x066A949DE49BF5ECULL, 0x736BAB9ACFBCF5F5ULL, 
            0x9283969490259B29ULL, 0x2B9682F4FCD21808ULL, 0xEA8E2D2DA3148719ULL, 0x1C1FE5408A46D63BULL, 
            0xD49FE4296C0C1390ULL, 0xAF94876514C118CAULL, 0xC370C19AD8DFF02CULL, 0x22ED5E9C4360E93BULL, 
            0x10A3D03950FFC0CAULL, 0xB7DEE50CAAB86417ULL, 0x9E4F559FA832D15FULL, 0xBEBE82220C88CEFAULL, 
            0x0B04200C084892A3ULL, 0x5255BED3F04B623EULL, 0x3E0DC593A429A71CULL, 0x86B5B0482E5A3BADULL, 
            0x97F4E93A8FC8AAF8ULL, 0xD6F38A2094C74FC7ULL, 0xA0554495A020F29DULL, 0xFFB838D67A1B9468ULL, 
            0x165D2B126A66F58BULL, 0x4168FD28C65BCFF9ULL, 0x9D795698C9015797ULL, 0x34B6F1BD6D9934B2ULL, 
            0x6D023EB0035A42A7ULL, 0x598146E3DA5BC189ULL, 0x2C1C537B1B04B686ULL, 0x4B0565137DCE5B66ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseFConstants = {
    0x336E836F77936B95ULL,
    0x22355BCEB948DFFCULL,
    0xDBC8D9B05E4D8084ULL,
    0x336E836F77936B95ULL,
    0x22355BCEB948DFFCULL,
    0xDBC8D9B05E4D8084ULL,
    0x7B23481262B53646ULL,
    0xD4DFB677A92B4C82ULL,
    0xDB,
    0x49,
    0x14,
    0x2C,
    0xEC,
    0x08,
    0xD6,
    0x1B
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseGSalts = {
    {
        {
            0xC80C17480A52D061ULL, 0x27797FBA77079687ULL, 0xA6612394EEC95B4CULL, 0x48194B0AC5E196D6ULL, 
            0x8927B433BCAD46FFULL, 0xC5E92B4923BCFFAAULL, 0xC12DF25BA1A93333ULL, 0x55BE51E488B75ECFULL, 
            0x1255E408B41784F0ULL, 0x7148023A0A061F68ULL, 0xF5C9B3302743CEA2ULL, 0x831176483C912503ULL, 
            0x536C87EA5BA59839ULL, 0x9FEB81E5C13B8091ULL, 0x2E919D3583ADF791ULL, 0x47DA329F0C844316ULL, 
            0x9440045FCFB68C4AULL, 0xD4C8FC0A00706073ULL, 0xBCBC161949652BB7ULL, 0xB19BE2709BE3F362ULL, 
            0xD3B4EE62AC156993ULL, 0x6D1DB4C46DDFCEAEULL, 0x4F0BAE17A58DC428ULL, 0xC3ACA20C20F5F58DULL, 
            0xB7A5AF07ACF61FD1ULL, 0xF01B0F72EA53D40BULL, 0xD3BEDB24007CB650ULL, 0x8A6BA5F2F66DED84ULL, 
            0x6EFA6851440D08ACULL, 0xA660F2CE893DC96AULL, 0xD2108100073E8000ULL, 0x2EE8661D93E0DCC1ULL
        },
        {
            0xA151C80596747083ULL, 0xCE0166FF8846F401ULL, 0xE55F62CDAEE90399ULL, 0xA22B8C4BF186A08CULL, 
            0x82108CC7730CF4C2ULL, 0x07B740D666368368ULL, 0xC049CEF5A3DD49C4ULL, 0x55A5A21B825AC9F8ULL, 
            0xB10AA0E089EDD215ULL, 0x6A6E09274597DD7BULL, 0xBD3CAF33C7B6DDC0ULL, 0x1E9E08AAE06C535DULL, 
            0x50ED9E4046A7F7D7ULL, 0x7C6B5B9746DB61B5ULL, 0x7C59DE3AE1183D19ULL, 0xCE91546E9D63366AULL, 
            0x67DD7C54FE53A1DCULL, 0x39E0AB1C6EEDB466ULL, 0x26BE609F00539402ULL, 0x38EC2F9A61EB881EULL, 
            0x62AF9B9851E08D27ULL, 0x52383D7F51E4A884ULL, 0x2533C1D0B11B4B40ULL, 0xCC8925C483939B1DULL, 
            0xAB703153D2D2DF06ULL, 0x8C35BE4E6FDD7865ULL, 0x5139211FCA174142ULL, 0xA25BA723DA9A7D44ULL, 
            0x8959D266179EC8A6ULL, 0x3B0CDBD45C0CD5C9ULL, 0x30A5E8D955ADA870ULL, 0xF7B927966E62425AULL
        },
        {
            0xB33E581E60E71FB7ULL, 0x0392CB6DE8EF9829ULL, 0xDE8B3055243CA8B7ULL, 0xCA2FB1D462D2C64AULL, 
            0xB52BF5FB523F4AB8ULL, 0x4790D4FBE3D36004ULL, 0x100363A5D1738766ULL, 0xA4E014FBA7B6E9BEULL, 
            0x5F6970B99783AF22ULL, 0x3FF4FECBC777E3C5ULL, 0x130D221316C61B9AULL, 0x1DB620155657C1D3ULL, 
            0x6B4F2598572E1AA5ULL, 0xF2FE8DDF8FA0F89AULL, 0x797DCCD440212ACBULL, 0x495B13A5A4DD3DD9ULL, 
            0xB4FFCEE4CAC91D13ULL, 0xF0361A63EB2344A8ULL, 0x57D35EA93EB8D9A2ULL, 0x97668156777C9F9BULL, 
            0x1AE9940A659BBB72ULL, 0xBC87C04E9D9A22CCULL, 0x46BB484B48B0454AULL, 0xC3A30ACF6BD85DE5ULL, 
            0x5644800C3062F17DULL, 0x4EC117CCFFD041DFULL, 0xE27E0A1E8A6FDEA5ULL, 0x52C54632B3BA38E0ULL, 
            0x0D5EFACD478F8E51ULL, 0x4AAEA673CBB5CC72ULL, 0xBDBA65144E291A76ULL, 0x51FB3EF64A5FD9F0ULL
        },
        {
            0x37740939722475B6ULL, 0xBB6EAB6C16015285ULL, 0x9C77DA914499261CULL, 0xBA1B987C6A852992ULL, 
            0xFEDE4E984F315AB1ULL, 0xB93E2726ED253A9FULL, 0xD7E39465B2E8A7A3ULL, 0x3ED8D75A6A3B715AULL, 
            0xDAB32A24AB259E36ULL, 0xDFBA0672DD93B79CULL, 0x4DDE90B35E5C42DCULL, 0x81563AE8DE18FBEEULL, 
            0xF2C183A35C32DF8BULL, 0x88A1C7A8827CF0A1ULL, 0x21E74064DC73F961ULL, 0xDFE52AEA4F3D6DA0ULL, 
            0xC013372963B3543CULL, 0x2379B1529D500A1DULL, 0xB7976FBA29D29FBAULL, 0x899FFE7FE0182719ULL, 
            0x4CB03D4477501DDBULL, 0x25B396B1F1B7BB3AULL, 0xA96F9FAFA7E6B533ULL, 0x8BBAF7D773F242DAULL, 
            0xB130F6B7AC3BDCA9ULL, 0xE852EF5E67ABF496ULL, 0x955A289A1937DB92ULL, 0x4A4AF4FBC9AC5AA2ULL, 
            0x50F7FEF77CE52A64ULL, 0xA5022AA277B746B1ULL, 0xD83FE0723F467271ULL, 0xC4569E8768BD59E9ULL
        },
        {
            0x5EAA696B2E944F5FULL, 0x30E7565ACE5684CEULL, 0x1530B0DDA44DADDDULL, 0xE82A032E94E94E97ULL, 
            0xBA143C2F8B4ABB29ULL, 0xE69187C05AC19062ULL, 0xB8C04E7AA421EF73ULL, 0xE75A15FFF2AB2632ULL, 
            0x39FBC60B01D03BE5ULL, 0x554ED0567D70CFDAULL, 0xC77AAAA242BDCA42ULL, 0xC5EF66BDF9073813ULL, 
            0x356E620A8A653D28ULL, 0x6616787B228C9980ULL, 0x9060C4FEE7FEF160ULL, 0x98C8CD3B65122B90ULL, 
            0x9DE326CD8546191BULL, 0xF7C25C919C718A6AULL, 0x3DCD8BE17673C0B4ULL, 0x5D2B7113773F9328ULL, 
            0xF8A39C224F699C7AULL, 0xDC989A34A56E2AC5ULL, 0x1B8DEB5D11092DB3ULL, 0x6E0B63435E57D171ULL, 
            0x0085126E4F967A66ULL, 0x3AED3998DDA23A57ULL, 0xE29D125C5D634894ULL, 0xCA3E29F3855E44B9ULL, 
            0xB507A75DE3C853CBULL, 0xFB5934C402B2CF76ULL, 0xE0EDD49C68C95928ULL, 0x3CADBBFF1C7BE95FULL
        },
        {
            0xFD80A36846B9D4DBULL, 0x5640413BFC90B563ULL, 0x7FB1CECE566BFC64ULL, 0xEC0468272E850D35ULL, 
            0xC2A18368751D5244ULL, 0x9BFFFCA2F176C24AULL, 0x2B1E90BB3692C08EULL, 0x85BAF63B58C56EA4ULL, 
            0x8901BC85EC0EFC26ULL, 0x78058F3A220AD719ULL, 0x577457339E877634ULL, 0x2DA95C9FDDC21A6AULL, 
            0x677EABE30149CC0BULL, 0x5E1B4A7B944C407EULL, 0xE263911DE97D4D0CULL, 0x166DD671829D3D81ULL, 
            0x7C8CDB204F706F9EULL, 0x05F3B106D3FE6187ULL, 0xE392E3F08AE85EEBULL, 0x70EEA1B118C3DAFCULL, 
            0x0A09263C8E8A8CCFULL, 0x24C5A74AA5DE98CAULL, 0x738E5138EDE78AD0ULL, 0x55B2ED8B6E2D1FBDULL, 
            0xAF369E168370256DULL, 0x3B51C793C281C84AULL, 0xEA1B58FBE73B17F6ULL, 0xC55E3A5773E9CEFAULL, 
            0x2D39526D4E7BB665ULL, 0x99ECEC05565CF93EULL, 0x0ACD9A32DC42A5C4ULL, 0xA9139441A00D677BULL
        }
    },
    {
        {
            0xAC373D586D59129FULL, 0x4AF8BFACEB351382ULL, 0xB79223D4C114170FULL, 0xEC3F639E44D1DC3DULL, 
            0x8563EB8FCAB89E71ULL, 0x1D5B538B269CF778ULL, 0x00061B713382EA7BULL, 0x18B8E5AC9B415515ULL, 
            0x620DE2E3FD0B0E58ULL, 0x9D2F1A253C5202D2ULL, 0x9ABFB5DD4F499454ULL, 0xB6A52CF3DB8EE8FDULL, 
            0xAC803287C41C193CULL, 0xC58518F853DAF2FCULL, 0x9D71E023E36D4271ULL, 0xE66822195D2311FAULL, 
            0xF594FF14307C0806ULL, 0x96E45E072873262BULL, 0xE5295A1D250F53F4ULL, 0x262B532C9DC61744ULL, 
            0xEC43F756F79CB263ULL, 0x5C6FCA5471D2F78EULL, 0x92E51B97A18F4ACFULL, 0x183C734F4C28BA04ULL, 
            0xC8D915DC4BCF23EBULL, 0xBE9C4C3D05B6A8D5ULL, 0xAB73B2DC81387AFCULL, 0xF1E4DC99C3FFE5E6ULL, 
            0xE964862951B67C84ULL, 0x6DAC71F775AF4C35ULL, 0x355BF6506B736F04ULL, 0x6C2BAEE2870CE03DULL
        },
        {
            0xE8D06E4D1DB35D0AULL, 0x726BCA539ACF21F5ULL, 0x20078237458B229BULL, 0x8566D00A7C292FE5ULL, 
            0xD71512571D3AEFF6ULL, 0xC7CBCB9C3EAE75C6ULL, 0x0AB7D056143E4421ULL, 0x2B14791C0DA002C3ULL, 
            0xB0152E4287FA8CC5ULL, 0xA88EBA372C924978ULL, 0xE2087BD72E7CE7E8ULL, 0x25CEAD0CA3215D45ULL, 
            0xC677A4C697077975ULL, 0x158CE62082DB37F9ULL, 0x00F95458E33A947BULL, 0xDDF981337B787E2AULL, 
            0x65F29C87FFE22860ULL, 0xEDFD6732CA227931ULL, 0xE928E6559B035304ULL, 0x40B75BA4B020243BULL, 
            0x70D27138CD426FB1ULL, 0x309F7038A6F590ECULL, 0xC1F91EDC41E743B7ULL, 0x704944CE42CDBDE2ULL, 
            0x3A53A846EFC0ED9EULL, 0x4618A47DAD477644ULL, 0x067624DED8FB3858ULL, 0xA199B1D6249419A1ULL, 
            0x28734CCCE5F26765ULL, 0xDF11831FE10CFEC7ULL, 0x9F2D87334666D22EULL, 0x0D52750119627465ULL
        },
        {
            0x3D4F9A31BA683A94ULL, 0xE341FC0ACA3C4DCDULL, 0xA1DB6543A1661542ULL, 0xA7FD3AA11BCFC30BULL, 
            0x3524CD58590F3F92ULL, 0xBF9E80ED73AE64E2ULL, 0x1D70DFEF2D7B4564ULL, 0xA26F080DA1B8A2C2ULL, 
            0x8C6A1A17F9EA272CULL, 0x453D2C78288E6933ULL, 0x471126D88F52BE8BULL, 0x6206D5037E06049FULL, 
            0xD5E2F9ED71C5C301ULL, 0xA5580DDBC78803CBULL, 0x0D6430022A7979FDULL, 0x7486A841A5D34C62ULL, 
            0x079B8ECD93AD684DULL, 0x2F303261AA33B422ULL, 0xD855EA230F7519A5ULL, 0xD40499C05272DEC7ULL, 
            0xEB2331E4868D432CULL, 0x104898A10F01C164ULL, 0xB5F7704BE0259463ULL, 0x2B18EB0880A67E1DULL, 
            0x5BB4B746228FC1E9ULL, 0xC7CCFE8B452AA74AULL, 0x5F63057E4A4DC4D2ULL, 0x1D2A39E9395AD973ULL, 
            0xE3CC6E9295935965ULL, 0xF095D3E576B085B5ULL, 0x41D9FAD18643254FULL, 0xF4A6787CBEBC4397ULL
        },
        {
            0x852F65FCFBDF9A41ULL, 0xC9F780EE518B0112ULL, 0x75C05698AD03D583ULL, 0x4D08D5AA30F28A5EULL, 
            0x463AF1B7FD88F254ULL, 0xAFB2424A0938122AULL, 0x06BFD76A027A8869ULL, 0x2B3742A1A50BA642ULL, 
            0xD7083A69DC3B410CULL, 0x5CEBEF6247D6DE0CULL, 0x002BE82ECF0F63B7ULL, 0xA097739CC3431FC1ULL, 
            0x2D78D53EB79353C2ULL, 0x30C0123045049A6EULL, 0xBF4C7F9DDE509C17ULL, 0xDA80D324DF7DEDFAULL, 
            0x1803E765592D749EULL, 0x26EEEEE8D65BFC97ULL, 0xD2A12EA976ACB41CULL, 0xC06C66EB740B72B3ULL, 
            0x615E1C89F9069074ULL, 0xC238B7BA5163CD9BULL, 0x740DA13FD2CA58B1ULL, 0xD77904FB97CA2DF1ULL, 
            0xF7C84318AA902FA7ULL, 0xC5735A0773BA7EABULL, 0x2218958F8C8AC597ULL, 0xE227F2C1A72F7388ULL, 
            0xAB5A8CD8D4854114ULL, 0xC91983C9AAB38455ULL, 0xD788620346686332ULL, 0x9141703094ED2F13ULL
        },
        {
            0x63859226BC93AC1BULL, 0xD09BDBF2DB13E3E4ULL, 0xA1486892F4C97CCAULL, 0xDF5D3C500135922FULL, 
            0xB033C78C8A1336BDULL, 0xB02AE7C5CD5C263BULL, 0x54A2B9CFE9B4A16DULL, 0xC496E15C925C5A56ULL, 
            0x545984B8E1B4E316ULL, 0x3DCCC07C428E02DCULL, 0x7865A9EC101479FCULL, 0x144C0745E70DC75AULL, 
            0x6E0EDCF40F9AD769ULL, 0xC0AFA29FB1F0793DULL, 0x41BC59032BEE56FCULL, 0xA3FE5FD19C2350E6ULL, 
            0xB6F2E27528476470ULL, 0x3CC16B7B6237A23DULL, 0x3555A57BF2D6ABB1ULL, 0x5D2B0AC4B2F5B59CULL, 
            0xF5274B7F40664E80ULL, 0x0EAC306D1116365CULL, 0x0DA7B489D77EA741ULL, 0x8969E566D3E0E0FFULL, 
            0xC1916222DF0E2404ULL, 0x8B7753C899393187ULL, 0xB9904D806A199A11ULL, 0x90EB5BE6835C6F5BULL, 
            0xA00D7E30C041C9A7ULL, 0xCDC1877819151934ULL, 0xC22D4BDC669E7354ULL, 0xC3A250DFD48010F4ULL
        },
        {
            0x890578DA5B360284ULL, 0x0EEEEB5C8F2F7D85ULL, 0x203FBE2028722B2DULL, 0xEBE44E570CBC575CULL, 
            0x46A96F365B8AF8E2ULL, 0x27F7ABF5495F01EAULL, 0x60ABB3A9F6EA6C2FULL, 0x219B11C29018EE91ULL, 
            0xF4272BC4EB5C8AD4ULL, 0x5EEA1D3A3E044336ULL, 0x210713986F46E4B0ULL, 0xA69A3AF6B29C72B6ULL, 
            0xAD884F73B93DF906ULL, 0x19C76A2F3358C057ULL, 0xA64CD7D1F5E05309ULL, 0x9B5DA92268DC7E42ULL, 
            0x888A6D8A5A4835BDULL, 0xD5C76EC1E84CB1A5ULL, 0x8BC6942643EDA62EULL, 0x769F2D6AE5581931ULL, 
            0x892D18E5D2A81DCAULL, 0xC87BC39880A2911AULL, 0x6881FAEF3D2E6260ULL, 0xA2E371AC0624E923ULL, 
            0xD7B9B39CAB7605A6ULL, 0x5C2CC320131F6C74ULL, 0xC2370B69B1AF0A70ULL, 0x34E78865F8AF459FULL, 
            0xFFB7C5A44E53EF7FULL, 0xB817BAD26F3E9D1AULL, 0x923F3B77860C51BAULL, 0x5454D8C226443FE7ULL
        }
    },
    {
        {
            0x8D7827D979DD68F6ULL, 0xA7E8E79F74A6454AULL, 0x983725E59F76A90FULL, 0xD7DCB26DBEE77724ULL, 
            0x3836517A282E60EBULL, 0xF00250BF54EA46BEULL, 0x4A5ABCCC0A0C25AAULL, 0x8843E1CF7927D8AAULL, 
            0x0B15776605C338A2ULL, 0x3AF1F99AEC432278ULL, 0x7E737C9A2DE3EEFAULL, 0x063D9C0E2ED089A4ULL, 
            0xB1D13DAF70C18A39ULL, 0x1C0D37E6E252F903ULL, 0xE616A8B384CA2F9CULL, 0xE07247CB7940702CULL, 
            0x358B676EC2FF185CULL, 0xFA278D708C751377ULL, 0x0E3A008F9AB319EBULL, 0x44914DCFCF718BC0ULL, 
            0x14449959B816D839ULL, 0xB04B818D9C31CA01ULL, 0x8B5CD3CEE6047085ULL, 0xF96CE3374519A1D4ULL, 
            0xD69577F04D34F411ULL, 0x9415825A7B687CBFULL, 0x0CB1108493961548ULL, 0x4F310F1562C58311ULL, 
            0xDA21ECF3CD427CABULL, 0xCB29D1FEE03CD548ULL, 0xC5F9A8E17BA20979ULL, 0xA5A432054820FCC8ULL
        },
        {
            0xE592ADD007236C81ULL, 0x35484CC37859BA30ULL, 0x341F0C1BBF0DFAF5ULL, 0xE7B23EB54A8B5717ULL, 
            0x672CD138DB7E0820ULL, 0xAAD037CA3E70E6D5ULL, 0xEF3B0AC8D4321BE5ULL, 0x830BB8693539C3DDULL, 
            0x7AFDE75CA85FFC4FULL, 0x64836DEB6822034AULL, 0xB7DCB7CE1B56304BULL, 0xFEC9F429C1BD30D6ULL, 
            0x42BBAAB185C6B803ULL, 0x1FF956B082302847ULL, 0xFA11FB22F69D9E5EULL, 0x26D1EF4B4B8E13F4ULL, 
            0xE4A43C4BBDE360EEULL, 0xD9737370C581BFE2ULL, 0xDCDA88CB2CFC5A15ULL, 0xBCB2DD7BA518530DULL, 
            0x49DC0EC318E4E4E4ULL, 0xD8A33C7678C93281ULL, 0x515802C5A3BBEE9BULL, 0xFE3FFEDA8F23FA2BULL, 
            0x56EE41EB34475BC5ULL, 0xF7AFCC56B22ADE46ULL, 0xB16BEA7EE506BDCDULL, 0x30223EA32BD07D97ULL, 
            0xD5302C1397C12909ULL, 0x9BD57A22213EA304ULL, 0xBBD34557EBCF2AACULL, 0x0991A04608B0D47BULL
        },
        {
            0x6A2A648854116261ULL, 0xD8637ED61EC79BCFULL, 0x9A340A11FEBAC99DULL, 0xCBCAB6669DE57C71ULL, 
            0x835844C28CA5EE97ULL, 0x5100938B759C6E4EULL, 0x56C3A6F289928996ULL, 0xB1C6C52629B84017ULL, 
            0x3BAF302E758FB85BULL, 0x8A0E391674408714ULL, 0xEE6349336A4F5FCFULL, 0x548DBC433DF12919ULL, 
            0x7970DC0CE56898B1ULL, 0x1206D622696EC1D0ULL, 0x3F733BB65181572FULL, 0xE6B16AE9982A1F23ULL, 
            0xD0579C0E12D7E153ULL, 0x1664786DD8920E11ULL, 0x4AC759760883B410ULL, 0x191C10F7E7B079E9ULL, 
            0x29A5F952CC9099FFULL, 0x43976C585F4FC2E9ULL, 0x0497D43D9CBA98D9ULL, 0xF067C2A6E0F441E8ULL, 
            0x15A41EEB4C8FADC7ULL, 0x1E28ABD08B7EAB7BULL, 0xA1F5C4BDAF2CA2DBULL, 0xF09C70DDB5CF7991ULL, 
            0x9D64072A650CD418ULL, 0xD4BFA4B923675E4CULL, 0x718C11715D7245E4ULL, 0x3933EE9E31755F9EULL
        },
        {
            0x9AB67B91D4C90A98ULL, 0xE823EBE1A1265C71ULL, 0x4AA28A1259E0AC51ULL, 0x63A20BD0D89E3A42ULL, 
            0xD8EF70A89224880AULL, 0x3B05BD4CBA52B4C0ULL, 0x72F1233AE6275DD9ULL, 0xCC9A57C5951B0CAFULL, 
            0x556AD43831F94C53ULL, 0xE402E14BC4CA7742ULL, 0xDD2A0405FC1B080EULL, 0xFAF754E306696ED2ULL, 
            0xF260A719B5A29DF3ULL, 0xF5C4267758408D4AULL, 0x813D7C7312C5B497ULL, 0xE6521BF6CFECE8E5ULL, 
            0x899234A291009C7AULL, 0xEA10434188618787ULL, 0x00C0670B64350119ULL, 0x53E89ED3EB3A5444ULL, 
            0xC85EEF0FE05BCFC3ULL, 0x320115EE0A07A1CBULL, 0x21DE3A3C3FFC95F8ULL, 0x86CAF5DAF21B4690ULL, 
            0xA84B09FDD8AAFCCDULL, 0xEB4A04218C517625ULL, 0xC1953A71CFBFCC63ULL, 0x21BFC6C50DA0DAA3ULL, 
            0xC893851304CFF5A3ULL, 0x1E15B5671D5EB42AULL, 0xBF92B4D8DA3C2EF3ULL, 0xDC1E4F3FEDA8C64EULL
        },
        {
            0xA8D828EC0FE51144ULL, 0x0F59F5D7F3DA0E84ULL, 0x2E6F80AB45904DCAULL, 0xA94DF6582D50C4F8ULL, 
            0x98F4F58CED5F0F22ULL, 0x68D2B4A23937EFB7ULL, 0x64028AAC42929DC3ULL, 0xAE8AB1ED354B9E89ULL, 
            0xE3E73833006D8399ULL, 0x18600F053B5640BDULL, 0x0C8ADD6F08770EAFULL, 0x455B828E57E25783ULL, 
            0xA4850EBD0F95819DULL, 0x431F1CAD105F9475ULL, 0xA5D232692E24A937ULL, 0x62B13D2394CB4638ULL, 
            0x7446BA3D13FF880EULL, 0xB94902BD7D6152FAULL, 0x13D00EE15D3D07A9ULL, 0xAAED96F8A46D3E2AULL, 
            0xFCF530CB75223100ULL, 0xD5630F3F6D75797BULL, 0xE64E3551B0A9F079ULL, 0x15020880304388E5ULL, 
            0xBA8677ED16B8EC74ULL, 0xEFD155DC52C02BDAULL, 0x05DE4CC542201F3BULL, 0x90D1B04D214958E7ULL, 
            0xA60799D95DC8E403ULL, 0xFFC9E9620688B84CULL, 0x0BF5978C72B32BFBULL, 0x639D2EB885D9AB22ULL
        },
        {
            0xDFF8AE5A206720B4ULL, 0x62F39F15C635BBB7ULL, 0x1AB5B528797DA78EULL, 0x49953EA49401BB70ULL, 
            0x921F8632AEA7B0D7ULL, 0xD22EB8C4856BCF6EULL, 0xFF9182E08A0B1C9AULL, 0xBF88C687A3E34E6BULL, 
            0xFB4A07C1A33238E4ULL, 0x3813B50859597BFEULL, 0xF39ADB72EF16FB95ULL, 0x8237DC74813BE4B4ULL, 
            0x2D15956AB85ED6E0ULL, 0xD7CE4C1B9980F1DEULL, 0xA6A339CE6ABC1CB3ULL, 0x7B1050202FA43CA5ULL, 
            0xD80AAFC770D5074FULL, 0x1628D09797C28247ULL, 0x5ECD2E22384555F1ULL, 0x0D1608769B8B6688ULL, 
            0xCC8990EA765C430CULL, 0xA86327210930705FULL, 0xEF32B5AEC3546405ULL, 0x18197A54E6F6BF7EULL, 
            0x3287574DFB0F5A54ULL, 0x4773F3AB94A126BBULL, 0x2F02919AABB82268ULL, 0x9F629019C0059355ULL, 
            0x299B5C2CCAC5AFF0ULL, 0x7B6607E682A2632AULL, 0x8AC8BA2EE87E8450ULL, 0x006472E6638B4EADULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseGConstants = {
    0x3A829FF30504E2BAULL,
    0xF8C7CE91F89A3782ULL,
    0xF510E6961C8A9637ULL,
    0x3A829FF30504E2BAULL,
    0xF8C7CE91F89A3782ULL,
    0xF510E6961C8A9637ULL,
    0x28130284FBF5A6B9ULL,
    0x05278F950567E460ULL,
    0xAA,
    0x4D,
    0xA4,
    0x34,
    0x67,
    0x86,
    0x51,
    0xDE
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseHSalts = {
    {
        {
            0xA44CA77D3ED69D67ULL, 0x22052415C07444DDULL, 0x727F2136B7730554ULL, 0xB5573C5FBE33F198ULL, 
            0x5ABBA1B4CF417FD4ULL, 0x138BFD846251A8F4ULL, 0x3763A36E87D9FC13ULL, 0x53ED87FCBA307B61ULL, 
            0x6876A4B84D4E6610ULL, 0x85888A2C7CB52BB4ULL, 0x6DEDA50E5A9344E5ULL, 0xE05A663E5032720EULL, 
            0x69589791BB35EDFCULL, 0xC12ED8F5E7BBA09DULL, 0x022CE7C03BBA4C13ULL, 0x5AA1559BAF9F2228ULL, 
            0x90D15C3588875F1AULL, 0xC70CAD8203C6D18CULL, 0x8B1DA03DF2BB0DE7ULL, 0x95ECB6B94079FF0BULL, 
            0xF2F30A68B96E824BULL, 0x9315CCEBD22DB6BCULL, 0xF68471DACE423D4DULL, 0x71AFE5F76F68B022ULL, 
            0xCB1AF89F976D39AFULL, 0x6CE2271D1261AC08ULL, 0x1C085FCEC501AC67ULL, 0xB3A8AC2C7CA70C76ULL, 
            0xC957CD393367BCC3ULL, 0x77026BABBE20A9D2ULL, 0xA9D12E312FAA487FULL, 0x745024E3EA6E9259ULL
        },
        {
            0x59726F037DA3921DULL, 0x613F350A65754683ULL, 0xCC6E547446403DA1ULL, 0xA1597FEEF8C445A0ULL, 
            0x90A41EBA4973DC20ULL, 0x3BFD0B0DE959808BULL, 0x8006F20961507844ULL, 0x6037A4B54899D5A7ULL, 
            0x8C02024B9BF91C12ULL, 0x8337052DD1A14F5DULL, 0x5517BA6D014340B7ULL, 0x21FB93683A7ADAC3ULL, 
            0xDDE30B8772477C85ULL, 0xF3D3164BE9FBC17CULL, 0x293447390E079075ULL, 0x428F1E1E284F1062ULL, 
            0x09E345C42F02F393ULL, 0x31883236CC8978A3ULL, 0x35F72DDDA2606B8EULL, 0x35B788081F5F0687ULL, 
            0xA9D860479690BE98ULL, 0x4B8B2F90BD2BC08DULL, 0xAEAAD7009ACE9DCEULL, 0xD282775106B1D57FULL, 
            0x1DA2D1A8C5A62AC6ULL, 0x3E061D46BF489661ULL, 0x7CAD3A8BC63F21DDULL, 0x0DE485570A5CE4DBULL, 
            0x6C1C89B4E7CBC546ULL, 0x4538505B8153514CULL, 0x20A6B888B7588402ULL, 0x9F1B6755F56AD567ULL
        },
        {
            0x2A87264EAF8E3D24ULL, 0xEE732C7824E23DCFULL, 0xCD9DD95946615C86ULL, 0x79C8E7C3EE024425ULL, 
            0x963D87A3789ABD6CULL, 0x4C0303ECD040C6C1ULL, 0x12CF00C0A6DF5721ULL, 0x36D35987417A3F8BULL, 
            0x455EA1EED9813529ULL, 0x1F19FB399B5E102BULL, 0x4809A753F2D4BB26ULL, 0x8B7ED3CF1DFD0241ULL, 
            0xDB60C4E1D113E5F4ULL, 0xD0B23870D5C4DE80ULL, 0x875231EBB3465FA0ULL, 0x3A74B02967D4956EULL, 
            0x63DAAC9788A657CFULL, 0x07E3E7CD665E171CULL, 0x0961532ACADF4934ULL, 0x384917A492879583ULL, 
            0xC64E5129D2C3F9F9ULL, 0x4ED67845A26BD1CAULL, 0x2F384BBF2A1895E6ULL, 0xF4409752057E381FULL, 
            0xC47F574AA9539EC0ULL, 0xC57C4D5A69E9FA08ULL, 0x5DF7ADCF244246ACULL, 0x4D82C4CDC5A55222ULL, 
            0x3816F8BECB708DFBULL, 0xC33E4E12A0FA6861ULL, 0x14E392F64F21C1D3ULL, 0xBF37D492598DB991ULL
        },
        {
            0x5EC7902AB7A0AA4AULL, 0x63AB2168BCA7F9B5ULL, 0x1F939A4FFDC6DBC8ULL, 0x66C6AE4CD0D312AFULL, 
            0x7EED2601BD99402AULL, 0xD042C3E55A124EEAULL, 0xD8076397B39A64B9ULL, 0x5FA0CC5C46301AF6ULL, 
            0x14A0BB4DA012E74CULL, 0x001802C950BEAD90ULL, 0x9660ACBB2BA6A954ULL, 0xA6469554488E9F7FULL, 
            0x936B8A137D7BD828ULL, 0xFFF3096E3F962FA6ULL, 0xC709D33919725827ULL, 0x2C0702E6F7015605ULL, 
            0x738975BF1DF91C6AULL, 0x77F3BB933067F0DEULL, 0x8DA7F1D70B78E130ULL, 0x93547725CDA45BF3ULL, 
            0xD2776BE08A2ACC25ULL, 0xB4BDE76DD16ADE97ULL, 0x970613D6AEE45A27ULL, 0x9927A9E15D84A243ULL, 
            0x762F15A6C977C4F2ULL, 0x0F378B8317FD465DULL, 0x439CF0A2B823875EULL, 0x20C7444EA6C6EFC1ULL, 
            0xEF3D1BFB04589951ULL, 0xAD1F6B3F2F24F22DULL, 0x22BDE75C0017ACD5ULL, 0xA470998E77EC8BFBULL
        },
        {
            0xD23209B487D571C9ULL, 0x1CE19CBFEF3F5919ULL, 0xE41479C72D3807E2ULL, 0x457458C781F9BCA2ULL, 
            0x4E7E4660E332A759ULL, 0xFF4CC82666909A58ULL, 0x8381E9A8C8230B8EULL, 0x9A20F0795405E5E3ULL, 
            0x8C34D54158EA7477ULL, 0x02D31ADCB539D66EULL, 0x9541CA8592E5A454ULL, 0x8A03B476F22D9444ULL, 
            0x401D2A8E4E70080CULL, 0x82A0FF18ECFAB58BULL, 0x88E657D03A187AD1ULL, 0xF98513C809993525ULL, 
            0x760A9E69E291E327ULL, 0x531678F02C91A654ULL, 0xE83140CCBEEC5E5DULL, 0x3CD2B5314777F021ULL, 
            0x64DF4CE311AD298CULL, 0xBB4FC586F78122DAULL, 0x003A7F4CAEAFDBD1ULL, 0xB7152302E7B035DEULL, 
            0x573D22AE7FD73307ULL, 0xBFAF9A99234BBFC4ULL, 0xF6D307FF0D6D73AAULL, 0x5FAD79E930883650ULL, 
            0x4388131168605DFAULL, 0x289A038D86BD3CA2ULL, 0x6AA4274FCB688E7FULL, 0xED1460BAF43E041AULL
        },
        {
            0xF4A5E7D368257B95ULL, 0xCCB21ADA501CF43CULL, 0xBD9E32E5C355D9B6ULL, 0xFD9F1AEA25D9EB9AULL, 
            0x979DA77EEF1A65B9ULL, 0x4ECBFA7BCAFB1A83ULL, 0x09150D9D2055A71AULL, 0x0BDED23FA456DF64ULL, 
            0xEC7571C008BDF5DCULL, 0x5C341EB88DC4D983ULL, 0x4B9163192BBB4315ULL, 0x634F4073B0008C6BULL, 
            0xC1616D55B58297B3ULL, 0xEA3CF7D2630001B5ULL, 0x4518AF095F8F779DULL, 0x70EBF3343F0645D0ULL, 
            0xEE7046564FD628E3ULL, 0x98AE5ED9E0BD4911ULL, 0xFBCA08F19C452CD7ULL, 0x6FF0611BBDB7FE85ULL, 
            0x5E4EFB5346D7B7C3ULL, 0xCD5B3262548479F2ULL, 0xD477873D0BE8504DULL, 0x0DA8A862E9F10F25ULL, 
            0xE315326802316064ULL, 0xD0FC6F9EF9FBDF55ULL, 0x648E6FDFEBFB7332ULL, 0x6581760828CB1230ULL, 
            0x0E7871193D870CD0ULL, 0x0ADD7625C93A0374ULL, 0x6D6899B2657273BEULL, 0xEC9F3A6F8E7221F3ULL
        }
    },
    {
        {
            0x624F6000274BE699ULL, 0xA2FAE0131BEFE884ULL, 0x936A8422FEC228E0ULL, 0x70083DC5FF587E8EULL, 
            0x8659F82ACE25B767ULL, 0x32D218946DAF6329ULL, 0xEF930E5FA5DE4146ULL, 0x0C1A5F240F123766ULL, 
            0x2E5BDFCAE93AE38EULL, 0x138E79014F7512E1ULL, 0x19FC6463DC5E6E13ULL, 0xCB0B3A6975EF0052ULL, 
            0xF84A55C762BCF788ULL, 0x6FCE5EAFC4726783ULL, 0xE26875F895F0FAD4ULL, 0x051C8929AA1E980BULL, 
            0x0A0C83A492879231ULL, 0xDAA1CAA7ECC8AA8BULL, 0xE397ADC65F0EAC55ULL, 0x7E85E9EB9A4D6410ULL, 
            0xB4F31136D2383776ULL, 0xA7A7FA47BA3F36B3ULL, 0x854573A35F316D38ULL, 0x44B0AF67ED2E3F13ULL, 
            0xD917C3C0FDAAC512ULL, 0xE0A17042301876E2ULL, 0x70038964C4839DAAULL, 0xF792F8ECDA5842A4ULL, 
            0x9A10D5CF4F446AADULL, 0x54C83752484E7CFDULL, 0x19DE020390F9C1E6ULL, 0x84754800B33638D1ULL
        },
        {
            0xDC8166A2E2DE0A52ULL, 0x56397FCB1BA70CAFULL, 0x467CCA55652580C4ULL, 0x9F1E5968065C436BULL, 
            0xA6273DE7C7C36FCFULL, 0xDA3BCE7EAB820E8AULL, 0x2CF46FDB9EB3FC0BULL, 0xF772BE14740BB37CULL, 
            0x290B2286000DA65CULL, 0xF87D4E37DB88C675ULL, 0xBCB822FB26618214ULL, 0x792F5449D6FB3200ULL, 
            0x9947A7DFD5283FFBULL, 0xA5536BE16EE59488ULL, 0x6D43D3BEA95120EFULL, 0x0D90A2C7D0866310ULL, 
            0xACBCAF4AFAA245A0ULL, 0xE6C920B7EE0F648EULL, 0xF09EFE83875A3C8FULL, 0xD4BAC02748A985B6ULL, 
            0xC1FFC931C8E5FB9CULL, 0x9BE7E9CA69869D17ULL, 0x2699CD679E36B0C8ULL, 0xEEBB7370D333069AULL, 
            0x113BE05F855CC612ULL, 0x92CB2ED3C6E7F837ULL, 0x64BAE65518309306ULL, 0x8D734C40C2688DEAULL, 
            0x90BF55E201E2EFA1ULL, 0xEB7AC1004FEC6FD5ULL, 0x38ABB5808A79C5A2ULL, 0xC391008A19529ADAULL
        },
        {
            0xA83BB9FF8FF51519ULL, 0x7A9E54A6B64BF965ULL, 0x5C3F1B52584C1040ULL, 0x2930DA156F20381DULL, 
            0x68A1E661D8018E03ULL, 0x6CF2724F7D7F95E3ULL, 0x05E4A6F311293A8AULL, 0x9D7CE6FA3F5FFE21ULL, 
            0x0F2D83664FF86E64ULL, 0x4770FC3C37D137BAULL, 0x7887B595CEF866D2ULL, 0x7FB85365EC25B05BULL, 
            0x7FA36D30C5552F4CULL, 0x3B15C3BDC3FDFED7ULL, 0x87B0723FB2509D45ULL, 0x1B4677A99F3295F7ULL, 
            0xB9C98EEF8B6EFFC8ULL, 0x3B918ABDA2DA3746ULL, 0x7EDC201C84347F55ULL, 0xFB80DBD00A32B3D1ULL, 
            0xBDFC454590CB51CAULL, 0x6A696B24B6C59A0AULL, 0x4435E2500B4270CFULL, 0xAC144EA34F98C852ULL, 
            0xC7C1773394B1902DULL, 0xB54AC95BCFC07E35ULL, 0x8972D3F79A61499FULL, 0x52C898BBF9E3B8C0ULL, 
            0x752D438A2BF4CC2AULL, 0xCA25A06508CF8E67ULL, 0x69833EB52EDBC6ABULL, 0x3B03D9AC2AAA26D9ULL
        },
        {
            0x9C6A1F9875B18029ULL, 0x9DB860524CB599F4ULL, 0x82F302FDC487AE28ULL, 0x66CD409198D7FF6AULL, 
            0x15D28AC131EB154DULL, 0x06EACF69003AB523ULL, 0x09C7711D1B6588A4ULL, 0xF55FE93040728CEFULL, 
            0xDDC73174427C465BULL, 0x74B5190630E75D5BULL, 0xEA76EE35664AF37FULL, 0x3C79E698F26C11C6ULL, 
            0xAB040F38BD4EE848ULL, 0x7A366369062AD739ULL, 0x0C51950A531E0FCFULL, 0xB1D216B2EBBC5FA4ULL, 
            0x523D0EF43F92E33EULL, 0x2A898D302C18A143ULL, 0x99BF2313E6134D2FULL, 0x5C4BC9D729FAAB42ULL, 
            0x48EC3F3C9746C01EULL, 0xC84C4BB9AAC65A26ULL, 0x2A40151656D5C4E5ULL, 0x987B9AC1C0132255ULL, 
            0x00D5547ACAD7E66FULL, 0x90D08B682540149EULL, 0xC0463A4553F46AEBULL, 0x68DD06964388D6AAULL, 
            0xBAE6CC8F5380C65DULL, 0x4909526B0F2550B1ULL, 0xB535CC11B9B60804ULL, 0x17BF1079C4970446ULL
        },
        {
            0x9F945EDF0FA9DBB5ULL, 0xA1B461735235FFB5ULL, 0xAE4E3769D37CAB98ULL, 0x949D27C35F5CDC99ULL, 
            0x5DC0041BB4CE1590ULL, 0x9ED33207AC675F0CULL, 0x273B095A95FC4015ULL, 0x5E0E044672697D42ULL, 
            0x34D3DABFAF856DF0ULL, 0x5A6080094F8C92D7ULL, 0x3FA702AC9F35BF8DULL, 0xE08560710F1425B3ULL, 
            0x0DA0F3988DEDC07CULL, 0x8EADBEBD8C6C2DCCULL, 0xE16337212939646BULL, 0x1ADA3A998DFF3B2BULL, 
            0x319EC9BDB8CA5CECULL, 0xA3C1BE2CC8610229ULL, 0x0816D59FF37162E6ULL, 0x3F7AFCDDA01269DBULL, 
            0x5CE7171BE2D3B054ULL, 0x469AE58582A588E0ULL, 0xCE2906AC370E1159ULL, 0x0B1290D00BB6D9D4ULL, 
            0x5AC5550E6160907CULL, 0x9BAD4758B35D0B6AULL, 0x00CF36C565550E5FULL, 0xA2D07053C7A0C6C0ULL, 
            0x6FCA156F6D61F76AULL, 0xFE6E60380492CE42ULL, 0xD25BFBDE8C163F4CULL, 0x1F1E7F6F3DCF79E3ULL
        },
        {
            0x20CBC3E01AD07DEDULL, 0xD9F4EECE98023724ULL, 0x95071A824CE5AE73ULL, 0x8272B15A54115317ULL, 
            0x57AE51EAD5FEF232ULL, 0xF19D83CACF540206ULL, 0x2DB21BFD6C91E8AFULL, 0x0459D7802780752DULL, 
            0x56AC9A1D7CBA5522ULL, 0x81D45B47B3D3C4EDULL, 0x1800BEB4CA3B217FULL, 0x4B525C77FB11C37EULL, 
            0x7A585208BA5261CAULL, 0x7FAE94BD948ED010ULL, 0x690D0940097F3CB8ULL, 0xEF6F7073928F4A3BULL, 
            0xB09A9DE7CDB6E09BULL, 0x3DE0A6E3A0B37F82ULL, 0xD5D3AD6C526B9B27ULL, 0xE94BEAE1E602F61EULL, 
            0xDA9FD267D0A91F7BULL, 0x3EFE630F2F8B08B4ULL, 0xB153CA1BAB828B6AULL, 0xDA8998F8E3058F1EULL, 
            0x74C67D41077FB98FULL, 0x005F62D16128B620ULL, 0x9224F0DE4C1D883CULL, 0x539ED2A03BD02E09ULL, 
            0x634F1725E5FFB8BFULL, 0xBDE7F44EAD2A3AF0ULL, 0x542E9FAA1FF2AC0DULL, 0xFD1A84B0BE9349B5ULL
        }
    },
    {
        {
            0x6EECAD434D08723CULL, 0xC5D97758ACEA91FEULL, 0x8A46C27D2020801FULL, 0xC4E94E2B2D6BA1A6ULL, 
            0x38F0ABDC3E503B50ULL, 0x7D87575D5EAFE7F3ULL, 0x1C4D7D49B966A3FEULL, 0xCC27EEA00E2D6FC4ULL, 
            0x4687D4DFA5AC778DULL, 0xDD846BBEEF7F9C17ULL, 0x38BF5C56B98CD9ECULL, 0xEAC615C914A352DBULL, 
            0x17E2660FF4C20FE1ULL, 0xC89D7DAC2B028F77ULL, 0x466D8F96C47C433FULL, 0x0E427224433A18B5ULL, 
            0x73F06B2211221899ULL, 0x7501F1AF5DB118C7ULL, 0xF66FB06001B8561AULL, 0x1A8010D19DE9D79DULL, 
            0x35139C008A4AC788ULL, 0x70E7D03F2CD84C91ULL, 0xD50BB432F282D37AULL, 0x192C4AA2B58C404CULL, 
            0x7D946C1F1BFE79F8ULL, 0x22F5949185756F12ULL, 0x0B408FEE0B7CA4B7ULL, 0x9E6BA7BC307C0DC4ULL, 
            0xAF08A7D66368684BULL, 0xB4A88348E1A21D7AULL, 0x1151C990EAB0FD5DULL, 0x2BD2602AA426B2C8ULL
        },
        {
            0x1193D631B4A5D199ULL, 0x17A0D332896E3E6DULL, 0x5861C4B45304EC61ULL, 0xCD084128D83DA7E7ULL, 
            0xB67A082F157EDCA5ULL, 0x8F3B4BD487564E79ULL, 0x5D75B4773C3B009EULL, 0x79421F2270F804C4ULL, 
            0xA090C1BE49056734ULL, 0x253FC5FB35B8F4EFULL, 0x8413EE5D2A5958D0ULL, 0xDD8B315C51952894ULL, 
            0x8731EDB3EF7B607CULL, 0x55512417005EB81DULL, 0x9B67E78DB31131BFULL, 0x609CD7144F2F8E99ULL, 
            0x75696665F5EC83BAULL, 0x02377E5D5EEAD1A1ULL, 0x6FB66838EA43F4C8ULL, 0xF9434AE13A2B33F1ULL, 
            0xE5EDCFF46FAC6339ULL, 0xB5B520124CAB2A63ULL, 0xFFE58FDAC4036276ULL, 0xACECD04193F7E0D6ULL, 
            0xDB389F04A45FB4DCULL, 0x364FFF629F64433BULL, 0x34BA60FB3EB609EEULL, 0xD1CBA7AB3CAA3D00ULL, 
            0xF46180723A3D9794ULL, 0x6046192B068F6A0EULL, 0x75138C0592CD9AE7ULL, 0x732BE7285EC4C51BULL
        },
        {
            0x9DB83784FE5785DBULL, 0x18F59F07B5E481B4ULL, 0xC78C33C306D944FAULL, 0xE70D7E486F1FC8DFULL, 
            0x3A98DF54C7BA6630ULL, 0x3779B96502CB55B8ULL, 0xDA093CDC544B6D5CULL, 0x9A8FF6FADDB4CE5DULL, 
            0x83E6C50993CBBC9DULL, 0xEA82BFED628F1C57ULL, 0xB16EE987F3D2B9D2ULL, 0xE967FF5195775B98ULL, 
            0xF38DED855539924CULL, 0xAD7BF4ACE06FE235ULL, 0x16237C03F85DACE6ULL, 0x70F6521426AA67E9ULL, 
            0x2D8690BD6A890B34ULL, 0xB42DC0FD58BE7C92ULL, 0x9E7A0C5F4CF4736BULL, 0xACCBEDFE50A3B880ULL, 
            0x3148486EAA5EA2D9ULL, 0xFF34B3A9BDFDCBD6ULL, 0xC4738274AA2FF309ULL, 0x6F23A7EC0EC95E02ULL, 
            0xB89A20687B79C018ULL, 0xB1C0AC1279F76D8EULL, 0x04449FE44B94834AULL, 0x6A8DEB32B041B48AULL, 
            0xBF840F5308E99949ULL, 0x7CDE8889B812CFA2ULL, 0x6317A62CA883B2A4ULL, 0x783410B11CF2F8C5ULL
        },
        {
            0xA5629817DDC3F873ULL, 0x3DA1AB118C87BC6BULL, 0xA7761BCA14EF549FULL, 0x6645E95354866AABULL, 
            0x9FA32A5B00487CAFULL, 0x329E8E7ED9D9CC9AULL, 0xA6E7CC6710D8A611ULL, 0xAC8F0DAFE1618D70ULL, 
            0xC12855DAD262E8EFULL, 0xF2D67F8CB934EA29ULL, 0x680290B0D09D51F6ULL, 0x2D549EE0778C5F99ULL, 
            0x62E1193CE3F43737ULL, 0xA67D37310208CFEDULL, 0xA68C7F5D7B248B83ULL, 0xC52558B96D33A9C2ULL, 
            0xDC05D326C0BCF78EULL, 0x2545177A3C3EC6B4ULL, 0x14953C01E5E79C7DULL, 0xE1CE4F9638AFFB28ULL, 
            0xCDE4AD54C4844D88ULL, 0xD3F0104BB5B957FFULL, 0x4980987CB8399353ULL, 0x50418238A99FFB14ULL, 
            0xD4C4F6EF94460060ULL, 0x330E4F71640FF235ULL, 0xE89478EB19BBE299ULL, 0x1BC4A8EE57CF2356ULL, 
            0x1C19EC7616D1AC15ULL, 0xC4BD3A0442F8A0DFULL, 0x5BF0BEE2F09E6917ULL, 0xE07185C4D6FA2A5BULL
        },
        {
            0x7E876DD6373E6A7EULL, 0xBA0193EF2D6F4620ULL, 0x5760EDA9B5BC04AEULL, 0x04C927ADCA660CFEULL, 
            0x0D17405915FDAF23ULL, 0xC27A0546E284CA91ULL, 0x3FB4C067E36052ECULL, 0xBA22B249C9A7A45BULL, 
            0x6DF2AE369D10B4F7ULL, 0x9AE531FB6BA282ADULL, 0x4A8D09A6EC8D67CAULL, 0x272CC8384B6817CCULL, 
            0x99F5B7D774B39AA2ULL, 0xE44CDEA651EF32E5ULL, 0x5F780C3F4141DD16ULL, 0x3D679ADBA6BE5F38ULL, 
            0x9C3142666D4B0A88ULL, 0x54B48694AD1E2B8DULL, 0xE6FCD49C3F42154FULL, 0x311E89A02EC03C7EULL, 
            0x8EF39EEA4E8FF9ACULL, 0x256574685BDD27A4ULL, 0x7EA32809EF67D046ULL, 0x8C4ADFD1D339F04AULL, 
            0x9ACA7B578DF2F32AULL, 0xC27B8969A808017FULL, 0x75EBE8A52CF7E5F4ULL, 0xD00C0D86A02925D9ULL, 
            0x0640030D9BE93F23ULL, 0x27F67B2A4204CAEBULL, 0x1B9FE072C0690B23ULL, 0x60B4965EA1F4905EULL
        },
        {
            0x095D34BECDE3E198ULL, 0x985DA27C7785F486ULL, 0xD3FF0E3904A520F9ULL, 0x6FFB6D86BB4D9CE2ULL, 
            0x1C52B19C54336B96ULL, 0x98805A1B82CE1A0AULL, 0x67AF595EAB096F7FULL, 0xCF5249B3292F8795ULL, 
            0xEA7640BE67337190ULL, 0x7E04666A266B767EULL, 0x933CEC020E5B8233ULL, 0x7E773374B3D1DADEULL, 
            0xA7573242D1900642ULL, 0x193366F986C1D3F5ULL, 0x6EEC7E812606C1E3ULL, 0x02A9A73B88FBD96CULL, 
            0xF42D76C46F074DEFULL, 0xB97D0C003905A120ULL, 0xD743C5AD316A0962ULL, 0x1F3972CEB9620031ULL, 
            0xE181C694ADD2F6CFULL, 0xA64247E58956B9DBULL, 0x9CC32BC4D5AF9457ULL, 0x19E37F7B64DC6A92ULL, 
            0xF2EA0A47EF326B3DULL, 0x7CCA038D56D83248ULL, 0xFEAEDA21003E8BA2ULL, 0x1DF388A3E911FC9FULL, 
            0x5755EB14B8033B61ULL, 0x654EF85398CC5455ULL, 0x9911934349AB6F08ULL, 0xDE8815E509C25AF8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseHConstants = {
    0xC818C0F554A44559ULL,
    0xCBFB1F6335CE945EULL,
    0x24E7DE2DF36FEBD2ULL,
    0xC818C0F554A44559ULL,
    0xCBFB1F6335CE945EULL,
    0x24E7DE2DF36FEBD2ULL,
    0x1FB448E3F85EB9FCULL,
    0xCE3D7A36640935F8ULL,
    0xBC,
    0xF3,
    0x26,
    0xB8,
    0x02,
    0x6A,
    0xB1,
    0x09
};

