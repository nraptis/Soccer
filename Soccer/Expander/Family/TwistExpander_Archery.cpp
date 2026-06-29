#include "TwistExpander_Archery.hpp"
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

TwistExpander_Archery::TwistExpander_Archery()
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

void TwistExpander_Archery::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8BBEBDFCCBB18ADBULL; std::uint64_t aIngress = 0x8AB365E767057DA1ULL; std::uint64_t aCarry = 0xFFB0E5825B53CB64ULL;

    std::uint64_t aWandererA = 0xAFF2CF975FC78529ULL; std::uint64_t aWandererB = 0xEBA42A56FA0EE98AULL; std::uint64_t aWandererC = 0xC1C80B2EF29D2088ULL; std::uint64_t aWandererD = 0xF2B7302015E661A7ULL;
    std::uint64_t aWandererE = 0xDE7811BAE2DEC94CULL; std::uint64_t aWandererF = 0xC3F487C8C2A367E9ULL; std::uint64_t aWandererG = 0xA3065192F07B05F2ULL; std::uint64_t aWandererH = 0xB26F7B26ECD80F6AULL;
    std::uint64_t aWandererI = 0x9E14DDA2CCD3602FULL; std::uint64_t aWandererJ = 0xE3F41B9DA6E10AEFULL; std::uint64_t aWandererK = 0xF10DAA47B547B4ADULL;

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
        aPrevious = 14528621195712813139U;
        aCarry = 9437805759492764141U;
        aWandererA = 13000162330142540592U;
        aWandererB = 13921179419650002184U;
        aWandererC = 13760350675982895614U;
        aWandererD = 12019498129160535285U;
        aWandererE = 9740969318603041558U;
        aWandererF = 9520094564093064746U;
        aWandererG = 12849084739122074228U;
        aWandererH = 11203660572846529269U;
        aWandererI = 10181134593223984512U;
        aWandererJ = 13499316045463250052U;
        aWandererK = 15982838909826133047U;
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
    TwistExpander_Archery_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Archery::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD6B4A7730A397017ULL; std::uint64_t aIngress = 0xD59EFC15CB3C706DULL; std::uint64_t aCarry = 0xAA6BF942504EDBA9ULL;

    std::uint64_t aWandererA = 0x846B89A87EB81E6DULL; std::uint64_t aWandererB = 0xBEA0F6B940037944ULL; std::uint64_t aWandererC = 0x98AB5EFF1285853FULL; std::uint64_t aWandererD = 0xE9A738CF878148FDULL;
    std::uint64_t aWandererE = 0xC07819F3A6439351ULL; std::uint64_t aWandererF = 0x935752C918E05C2EULL; std::uint64_t aWandererG = 0xA0871ECF293EFD4FULL; std::uint64_t aWandererH = 0xA061E2F598322890ULL;
    std::uint64_t aWandererI = 0xDE70C5F9DE7782CEULL; std::uint64_t aWandererJ = 0xC1A8FCE5DBCAA599ULL; std::uint64_t aWandererK = 0xA093BB895BE272C4ULL;

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
        aPrevious = 10608179173071945968U;
        aCarry = 18159788208701333835U;
        aWandererA = 17471461370964035565U;
        aWandererB = 16473497272716858259U;
        aWandererC = 9584134033891810647U;
        aWandererD = 12170713134619066406U;
        aWandererE = 16355003544461244575U;
        aWandererF = 12570699245846783020U;
        aWandererG = 11352992609474732009U;
        aWandererH = 9919152376814644313U;
        aWandererI = 11109604239045026917U;
        aWandererJ = 9630781046862136751U;
        aWandererK = 10129028606429276979U;
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
    TwistExpander_Archery_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Archery::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9BC607F0642FF162ULL;
    std::uint64_t aIngress = 0xF66E08F72DB3F528ULL;
    std::uint64_t aCarry = 0x86E41B949DCE33CCULL;

    std::uint64_t aWandererA = 0x960F701C24984C55ULL;
    std::uint64_t aWandererB = 0x858600B50319B02CULL;
    std::uint64_t aWandererC = 0xBEDB39CB1B112D4AULL;
    std::uint64_t aWandererD = 0xC21FAFA938D356ADULL;
    std::uint64_t aWandererE = 0xD0B16D790D1E576AULL;
    std::uint64_t aWandererF = 0xA8D7F065623F8CB7ULL;
    std::uint64_t aWandererG = 0xE51C137168389340ULL;
    std::uint64_t aWandererH = 0x8BF90BCB16ACECCAULL;
    std::uint64_t aWandererI = 0xC7ABCE99AFA25F6AULL;
    std::uint64_t aWandererJ = 0xDF672DC7B167BB24ULL;
    std::uint64_t aWandererK = 0xD2C3B22177E761AFULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Archery_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Archery::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB9CA68BD11096EF5ULL; std::uint64_t aIngress = 0xDC6B52CB44700090ULL; std::uint64_t aCarry = 0xD9A4FE4F0B7986A3ULL;

    std::uint64_t aWandererA = 0x94CE7E9DC647D1D0ULL; std::uint64_t aWandererB = 0xCD92FC7164AF5656ULL; std::uint64_t aWandererC = 0xE1BBA6C25F39E6D2ULL; std::uint64_t aWandererD = 0xBF6ADB9032D655BDULL;
    std::uint64_t aWandererE = 0xAF2EEEDDE99F3592ULL; std::uint64_t aWandererF = 0x91B11AF1EFA4DC90ULL; std::uint64_t aWandererG = 0xD249F9437E7F2745ULL; std::uint64_t aWandererH = 0xA828E0AECA3C8838ULL;
    std::uint64_t aWandererI = 0xA9A7D16756C44CA1ULL; std::uint64_t aWandererJ = 0x8F742A38ABEAA7C3ULL; std::uint64_t aWandererK = 0xE3A2DAFCC61E55F0ULL;

    // [seed]
    {
        aPrevious = 15098555925215786805U;
        aCarry = 13141388683927288117U;
        aWandererA = 13398796392433603598U;
        aWandererB = 12397096614363177450U;
        aWandererC = 10990478311954635960U;
        aWandererD = 14821194092085413026U;
        aWandererE = 18300802170100641070U;
        aWandererF = 18434294477570894180U;
        aWandererG = 10108902346669936082U;
        aWandererH = 18337233391893391824U;
        aWandererI = 14396680255776667179U;
        aWandererJ = 9493459016939767750U;
        aWandererK = 9311283014931016698U;
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
    TwistExpander_Archery_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 1, 0, 3, 2 with offsets 7905U, 3396U, 8073U, 4121U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7905U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8073U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4121U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 1 with offsets 5647U, 902U, 4534U, 6078U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5647U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 902U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4534U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6078U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 0 with offsets 298U, 8126U, 2627U, 5329U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 298U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2627U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5329U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 3 with offsets 5516U, 1061U, 5008U, 4568U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5516U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1061U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5008U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4568U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 with offsets 205U, 900U, 578U, 1770U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 900U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1770U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 3, 0 with offsets 1853U, 1254U, 507U, 1164U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1853U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1254U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 507U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1164U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 840U, 1713U, 1838U, 345U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 840U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1838U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 345U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 0, 1 with offsets 766U, 1106U, 348U, 103U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 766U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 348U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 103U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 527U, 689U, 163U, 1330U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 527U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 689U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 163U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1330U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Archery::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 2 with offsets 7769U, 477U, 7591U, 248U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7769U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 477U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7591U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 248U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 1 with offsets 1898U, 1520U, 7901U, 883U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1898U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1520U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7901U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 883U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 0 with offsets 4057U, 1757U, 6776U, 255U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4057U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1757U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6776U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 255U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 3 with offsets 7607U, 6511U, 6083U, 5166U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7607U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6511U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6083U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5166U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2830U, 6631U, 2104U, 3840U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2830U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6631U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2104U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3840U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 401U, 464U, 860U, 226U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 401U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 464U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 860U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 226U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 576U, 1157U, 1043U, 252U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 576U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1157U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1043U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 252U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 298U, 2038U, 1385U, 181U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 298U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2038U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1385U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 181U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 760U, 1943U, 534U, 371U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 760U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1943U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 534U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 371U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 [0..<W_KEY]
        // offsets: 1871U, 846U, 2006U, 1198U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 846U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1198U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Archery::kPhaseASalts = {
    {
        {
            0x7E5745ADD28CB799ULL, 0x248B653E768BF4DDULL, 0xA50DA49E1CEA4C97ULL, 0x896C1092AC51878DULL, 
            0xCFA6FCCA5B812543ULL, 0xCC6BD30C004755B2ULL, 0x111170DC7A65907EULL, 0xD2C4D9E27327B0CDULL, 
            0x43C2313DA59C2C11ULL, 0x10FD8709842F7FC4ULL, 0x4D79DFFFEA80E28CULL, 0x24750C76C2A39339ULL, 
            0x2A5BAEF872A697D3ULL, 0x12E1AB619EE37210ULL, 0x3F12822BA48E9D65ULL, 0xCABB731A577BFAC3ULL, 
            0x760A54AB6D02539AULL, 0x3C3EFE9BFAA2504BULL, 0xB4185863A5CC5841ULL, 0xD245C6926140476BULL, 
            0x88CEF3913EB3676CULL, 0x502E657B5E6EA589ULL, 0xDB30D2EC4C4C2983ULL, 0xA7BE4937C4D47B93ULL, 
            0x3E7A93AE2DEC22D2ULL, 0xE7014C0F2F5EF28FULL, 0xE967A8C5F575F3B9ULL, 0x8580CBD1D85D6F39ULL, 
            0xF02B85168C070D4BULL, 0x0CB0C242EE10800BULL, 0x6E0425FD112B60E4ULL, 0x84A8C89FE87A5936ULL
        },
        {
            0x26B78772062DB9CDULL, 0x038999312053FA39ULL, 0xD6268A0BBF10DE7BULL, 0x38D109A5701E09DEULL, 
            0xE0B863DDCD04DEF1ULL, 0x5E32ED40067994E8ULL, 0xB39BC1398AC69B87ULL, 0xF14486D8518B6241ULL, 
            0x89971BFBEC92AAA3ULL, 0x579CFACCF9900066ULL, 0x5C60090641C7CB6EULL, 0xB6C417357D4771A2ULL, 
            0x25A2DE7B34006906ULL, 0x35A728F24F5A3FDAULL, 0x5EAE5989275C88FFULL, 0xCC5AAD7E8A29E791ULL, 
            0x8E5D0E5A55015448ULL, 0x6CD4B18630FE2891ULL, 0xD9B906B7FBB5E259ULL, 0xBA4D263A8AE82A07ULL, 
            0xE2C91277E27451CFULL, 0xF32E18CDEDB1F235ULL, 0xD955F4A0CB53F620ULL, 0x8B0094BAF4DB5E12ULL, 
            0xC0393A3FD03BFC46ULL, 0x05DA306727A306A4ULL, 0xFDC40CC3F24F953EULL, 0xFDE2CE6C9846DCFAULL, 
            0xE4BBA2D5AD5FC718ULL, 0x521CC5AA4537B05CULL, 0x33B1A4F825F2F652ULL, 0x8F05CF173AB4CD7AULL
        },
        {
            0xA7C02B8FFB976471ULL, 0x072303374D5B0F59ULL, 0x3F45A9B875BC7652ULL, 0xD356E01515A4E523ULL, 
            0xC6BEE024563B54AFULL, 0x5163B10FD34E6683ULL, 0xA4E0427964B7422EULL, 0xA5B24C9342FCB40EULL, 
            0x3DAD7BE4EC270CF3ULL, 0xD76FA5F3AF927C52ULL, 0x9E1CE5697FD148E6ULL, 0x0221369637E6CEB6ULL, 
            0x34EF948BCB0E33AAULL, 0xA27030F149FA6CB8ULL, 0x16FD9AF225A37F96ULL, 0x62D4F1DB3532A4D0ULL, 
            0x780C010DE531A498ULL, 0x631108326CC2F804ULL, 0x8FEDBA6D468FA6A9ULL, 0x1B6D015FDED65957ULL, 
            0x80F3E9393C187DBBULL, 0xE7638ABC40547430ULL, 0xE02FE79534C93985ULL, 0xD8DA64A20EBAB123ULL, 
            0x11EF9E7797F6E541ULL, 0xF209BDB99DDD7BB4ULL, 0x69BD89D447E021CAULL, 0x3216A43D5EA412EFULL, 
            0x122E201E2AB918A2ULL, 0x00FECBA9082D27B3ULL, 0x108D845E9298A02FULL, 0xBFE26AAF79F078B9ULL
        },
        {
            0x0E0A8EBB34CBE402ULL, 0xEC7BFCCCC65B8333ULL, 0x6B9AF34F1FC0EDEFULL, 0x276B8CFC74D810FDULL, 
            0xD4AA3D54A0EE3D6AULL, 0xDD1EA3CB7AA3A92CULL, 0x246F4BD297BE7844ULL, 0xBED2A4454B4C96F1ULL, 
            0xBBFF8D14FA99D3A6ULL, 0xC77A0528A6FC2AFCULL, 0x4C064F32C9066E8AULL, 0x4642D374455FA680ULL, 
            0x001E8BA2B233619CULL, 0xFED62CC0DF1C8A1CULL, 0x7B83CFC501E981B2ULL, 0xE4B397F8AEFBF356ULL, 
            0x8E0757BA3D28ACB1ULL, 0xDE4BBC241FBBFF21ULL, 0x953533B6E942070AULL, 0x8F9128A294F10BCDULL, 
            0x28FF799FCA917C05ULL, 0x70D63B09057C7232ULL, 0x3F29E746766359CBULL, 0x53C12C06CEDD4D7FULL, 
            0x1EF5D164BC0892D1ULL, 0x1BA18D1540C51C38ULL, 0x1E39677CBD05B4F1ULL, 0x8EF1738AB82ED1AAULL, 
            0x78735E8B9654B728ULL, 0xE03FBBE86D5081F3ULL, 0x18B10C89B041C46BULL, 0x506A955F7FE27F2FULL
        },
        {
            0x2BFE747441A5EF23ULL, 0x568D4D8AF79AEE86ULL, 0xEAD53A9299BF3333ULL, 0x3F9D2113284AE4B0ULL, 
            0x106EA0A9268FC063ULL, 0x2A01E8A4E1C408B6ULL, 0xD6ED20277042140BULL, 0x2AE81E733CAB369AULL, 
            0x00CE30E80C7E6554ULL, 0xCF861EBE0E2E03D8ULL, 0x988BEE82132F5E89ULL, 0xD4E9C71AAEA01E77ULL, 
            0x60E186C72E4FE07BULL, 0x8097580AB20DDF42ULL, 0x1144187212EDDF82ULL, 0x78268740A7247204ULL, 
            0x71509494D4DEC792ULL, 0xE50108E09838BB3EULL, 0x472AD0F83651F10DULL, 0x5E7F7467024645DDULL, 
            0xC759FBFE7CA64771ULL, 0x43D869A538309FCCULL, 0x9FBBD4A7A41A3237ULL, 0x7627D874A438043CULL, 
            0x0F43E878A8EE50E5ULL, 0x437CDEE0F014ED5EULL, 0xF8C879C48F56F278ULL, 0x87D63A80F274C232ULL, 
            0x4F51A94D66CB947FULL, 0xBA510E4481469779ULL, 0x0115DB4DBBF3FAC2ULL, 0x03339AA6BA8629D5ULL
        },
        {
            0x29F7554A288984EFULL, 0x0BF24D897EE7A9E0ULL, 0x12CD043D50046C9FULL, 0x314C282F754EE40CULL, 
            0xC531BE8E375A4347ULL, 0xB1559D9156BA3C55ULL, 0x687CC584E017A912ULL, 0x3F1BDA7104B513EEULL, 
            0xE6CDEC568B6AC3CFULL, 0xFD7CAA47632B5972ULL, 0xA55325B681505663ULL, 0xA8BFE8602A20E45EULL, 
            0xA251AA416E351107ULL, 0x0BB34ED061E0ECB5ULL, 0xE25C4C92AD113C09ULL, 0xF8390D51CFCDA6CAULL, 
            0xDCB3A1E3DD92C7DCULL, 0x4C1022D0756F90C8ULL, 0x74AB89FCF5342DD1ULL, 0x3853B8574DA2B2D8ULL, 
            0x0BA8601E3048FAE4ULL, 0x19B9122476FA7D43ULL, 0x4943EE5AD77147D5ULL, 0xE244A9E6BBF28E43ULL, 
            0x26301645115B0C87ULL, 0x2AEE5913D3FB29B9ULL, 0x6AB8D30D8C6CFEC9ULL, 0xC55209E02C948084ULL, 
            0x6E0465E28886223CULL, 0x9980483A063E3BCFULL, 0x23A882E0BA3C16B2ULL, 0x04501CD76641A9F2ULL
        }
    },
    {
        {
            0x4D279FDB09161861ULL, 0xEFF46ADF36198C57ULL, 0x7FEF6C301FD4F9C9ULL, 0xAF6DD6C4F6DA9D04ULL, 
            0x563749AB2CFFCDB0ULL, 0x22B47266F5782C2EULL, 0x131DD3CC556B1DAEULL, 0xC78DA1C2B8AD0BF1ULL, 
            0xDB6C108193957530ULL, 0xEEAB226D2B614323ULL, 0x1709C138F290FA15ULL, 0xA40703DD3DAF0675ULL, 
            0xBCE21FF7F6ED3D66ULL, 0x849E31AA9C3B071EULL, 0x39A69CDCBA27C251ULL, 0xE25892C4C431C4CEULL, 
            0x01EC231F49A354DEULL, 0x98E489F26FE310ECULL, 0x9926A0654819D8AFULL, 0xA1F3CE8673AB364FULL, 
            0xB01069201AED1761ULL, 0x42AFE1C18788B0DEULL, 0x4D8A41BBD3F22CFFULL, 0x8A44C87EE6DA0082ULL, 
            0xF77C4C5D2EA7EC58ULL, 0x112220424D7BCE8BULL, 0xC3D68CE6249ECE8CULL, 0x0285CCD1618DAE29ULL, 
            0x6A6B17DBDB2862F1ULL, 0xB09A88FDD5DED3D4ULL, 0xE8D43BC83BA76F81ULL, 0x96C79C1035FE0CDBULL
        },
        {
            0x03BE91668823FC7CULL, 0xD5E10F446E9A62B6ULL, 0x78E09DAF59CAC4AEULL, 0xED88DBB51F80614AULL, 
            0x20F2FD5A1CE1FD43ULL, 0x0B2BF39FC014C8FCULL, 0xE909AE163B605EEAULL, 0x58368E30EE3F599BULL, 
            0x15F3B7AC1C02A0FEULL, 0xC22F29C39A52CDEAULL, 0x5F28545E4E32FFEFULL, 0x04830DE449E48991ULL, 
            0x00D23F301442AA66ULL, 0x3DAA9CFD4F9CA48BULL, 0x83BAAF04BDA45197ULL, 0x2430D417126A1B6BULL, 
            0x17DC6E6CEDCF4029ULL, 0xCD40A9B2875F7810ULL, 0xA030F428A306DE98ULL, 0xF9A68B1F6464033AULL, 
            0xC828CE196BAE7B84ULL, 0x733F565243297814ULL, 0x772B281F2A7DD36FULL, 0x0312E3B58CEDB2C6ULL, 
            0x1D39E334A72C5C72ULL, 0x6A3D421BDC600145ULL, 0xF0C4EEA52E6D9D64ULL, 0xDFA06924D6FD69BAULL, 
            0x9F8256E2605585ECULL, 0xBCE416DE9B9501C5ULL, 0xD3C910B9B10094B0ULL, 0x99A10FB0DFE1F38AULL
        },
        {
            0xDE90124044F7F44AULL, 0x0F07D4434230E499ULL, 0x8B4D47AD6AB3B550ULL, 0xE731B6218AD5A49FULL, 
            0xC2714C78D5F2CA3EULL, 0x068FAA3DEBE78BABULL, 0x6D1E82B91D906681ULL, 0xA2505D4171979E62ULL, 
            0xE837AF7DD18E4081ULL, 0xC25A869FD79761A8ULL, 0xA55E81B8E3CB4B62ULL, 0x66D361186DF77765ULL, 
            0x7EB0FACDE17E90DEULL, 0x5EAFD0C5E4ABB5C7ULL, 0x328265DBBB455FECULL, 0xF63B5B46422E9AB8ULL, 
            0xAD42D8809FC249FCULL, 0x0AA87D06CC6080E0ULL, 0x0282EC8D50137029ULL, 0xC6C76DD66ED3650CULL, 
            0x19D63728480844C2ULL, 0xCA565FE4F1E09EDFULL, 0xE8F2A5121F968866ULL, 0x3ECD9DE1AAD78727ULL, 
            0xC16D6800C54EDE26ULL, 0xB3E33F3239CA5DB1ULL, 0xD7D6632E23BDC32BULL, 0x0C8784BFBA5F72E5ULL, 
            0xF8955BD5A50C7B41ULL, 0x77BA5BFCE51FE450ULL, 0x8DEAB124CC687CB5ULL, 0xFC998CFAF84D51B3ULL
        },
        {
            0x970670B00E270505ULL, 0x6EE3297C46FCF6C7ULL, 0xD396B86CC99BC4FEULL, 0x87062367DFDFB7D0ULL, 
            0x4C2C28B455FC9412ULL, 0x0534B9B6793FBD17ULL, 0xBC639EE637D9B914ULL, 0xBBC184074D77C712ULL, 
            0x58F1A52CD6ED97F5ULL, 0x2713D8262B9ACEA4ULL, 0xB49E2DB3854BA57AULL, 0x8F93FDF9BABCFD6EULL, 
            0x8898C1DBB2DB8E04ULL, 0x71BC315E55B53F13ULL, 0xC3DBDF561773D7D9ULL, 0xB1251A21F33B42A4ULL, 
            0xBC3369528371ED09ULL, 0x0CD5A741813CA343ULL, 0x1CCB71CAE54F86E1ULL, 0x8D8F1EC9B27C232BULL, 
            0x3F1233D77632DE43ULL, 0x8812418B8F40E0A1ULL, 0xF3F9F9AEEEF3EB94ULL, 0x83DA47C1AE7D6D74ULL, 
            0x188E94F5CE4C2410ULL, 0xE68BB8B3DE7A7A42ULL, 0xAABA6D8ED1286ED0ULL, 0xFE688210728D2012ULL, 
            0x4E8944CA489A0767ULL, 0x813E7ECAED8248C8ULL, 0xE9C7AA8C3E60298FULL, 0x96804F3C99506F68ULL
        },
        {
            0xA4F93551BCC8D64CULL, 0xAE218A0F43F13CD8ULL, 0xCFD5C01122EE31B2ULL, 0x7360A470B6D8DABCULL, 
            0xAAAD292B33939893ULL, 0xC436DBF6F3C65708ULL, 0xE94C8708A1DC1CCDULL, 0xBDA87D6BCDB40D33ULL, 
            0x48B8C9F081FAAC1EULL, 0x3A834529977CF290ULL, 0xDB8F3D4C3BEB8965ULL, 0x8BC4D4D039339011ULL, 
            0xDCB10CEB5F29C716ULL, 0x8625009629E7507CULL, 0xC2FA3A741BF5337AULL, 0xC9EEB79845A59A6BULL, 
            0x99B28B2A5832B470ULL, 0xA849EF0CEF6B9850ULL, 0x3C82A5D092622EB4ULL, 0x0FF1975173609310ULL, 
            0x736757F519F45550ULL, 0x69379A670D372E0CULL, 0x47096F807F031988ULL, 0xAA5B88B48CD44F4BULL, 
            0xD6D3610643F33702ULL, 0x3C91605D9C452D86ULL, 0xCF00FE85745A7245ULL, 0x30A0FAAE8C1592A5ULL, 
            0x4106C1BB1B61BCA1ULL, 0xF55D513DB4668B7DULL, 0xDB03F6913779B0E2ULL, 0xBCCB01D5E3947E08ULL
        },
        {
            0xECDA73419328967EULL, 0x04A65CD79B8BF6E0ULL, 0x6D170BCB7095AD71ULL, 0x5107E034BF61D1DDULL, 
            0xBD8EB3BE5B49AC2EULL, 0x21B1F3688F72ECB4ULL, 0x0B35EDDB4F8D54AEULL, 0x3E32B9662EDCEDF5ULL, 
            0x1ED6AFA46129E5EEULL, 0xFFA6D7649EAB72D7ULL, 0xCCF4072FA4A13D29ULL, 0x8659194B4991FD7FULL, 
            0x3A2F5497BA837C56ULL, 0x4B1BE97E2592F91EULL, 0xFCE177277BF35B5EULL, 0x4344FA997028D73AULL, 
            0xA4AA08156E706EFFULL, 0xC76A10620A5209E1ULL, 0xBEEF08EAE92AC695ULL, 0x4DBC1E9FD98A704CULL, 
            0x3BEBA81565A66650ULL, 0x6E22BC62E2D7D761ULL, 0xA3B95673078DEA39ULL, 0x1076CFB30462FD94ULL, 
            0x84DFFE4B4300E7EFULL, 0x9D3EEE3937AAFB1FULL, 0xE2AA49B7A0201DD4ULL, 0xD69EB9AC0F508372ULL, 
            0x24D34925C512B162ULL, 0xC74279B266AB977BULL, 0x5517E2DAA4019EB5ULL, 0x9CE365F231CDB3B8ULL
        }
    },
    {
        {
            0xA0A9CB74DBC4ED3EULL, 0x010AAFFDFFBA4538ULL, 0x5DE51CB7D4123B5FULL, 0x1525B172A3A3595CULL, 
            0x01CB6385C18B97B5ULL, 0x7945EDAFCD1BBDC9ULL, 0x1D7A525BECE7CC26ULL, 0xD329AE8B15E69B22ULL, 
            0x7C8A46293FDE991AULL, 0x2C96362F632B3D24ULL, 0x3F946045A80B0B76ULL, 0x18B9FD11C1DA7263ULL, 
            0x6A3F67BD0F314E00ULL, 0x665EDD219EC5CC19ULL, 0xED5AC190641B2622ULL, 0x3F250468693092FBULL, 
            0x78915F7170F3AEBFULL, 0x710385B4DD21A218ULL, 0xD371C772F3FE0F2DULL, 0x0D158669E9EADBD8ULL, 
            0x575B6BF5780BD97CULL, 0x2D6976027C77B912ULL, 0x033FD7DBB7A9D730ULL, 0x271D7053D501F777ULL, 
            0x8B37ED3876A27723ULL, 0xABBED371D0B95BD3ULL, 0x1D46BF7A85BD66C3ULL, 0xE9E39449EFCF8AD5ULL, 
            0xE0DA02D2464EA1F7ULL, 0xB53D4CCF1110426FULL, 0x448A9D3649458EA6ULL, 0xA87777C0DB38C422ULL
        },
        {
            0x7A710CFFF2659848ULL, 0x8D554E7D4F7C24ADULL, 0x12665C21A57B2ECCULL, 0xF5E6B36F3DEB74F8ULL, 
            0xDAD3D320CDC9CBB3ULL, 0x9C5F844FBB89194DULL, 0xA287097E1E0ABE4EULL, 0x16207BC8260E57F3ULL, 
            0x8978DF6D9B1A7268ULL, 0x7D28717F54DCB7D7ULL, 0xA706CEA41472BD91ULL, 0xE9159BE55CF3741EULL, 
            0x32573B21C3A60D0FULL, 0x751DC5BD275FE18AULL, 0xA482BB7E58E1742EULL, 0xF68E56B721B91C16ULL, 
            0xD7760CCB409F5D7BULL, 0xBFE46D56A5FA4692ULL, 0x69920F01A84E4575ULL, 0xCC6B0CC2D6D63C80ULL, 
            0xC60B3CABAC20EE27ULL, 0x876833F1C2BBE830ULL, 0xA8C70A527A663301ULL, 0xF0A039AA7A8DA4C1ULL, 
            0x7CD60846DEA31262ULL, 0x97B8E8B6C1C85BDBULL, 0xDB6A108BB25685C9ULL, 0x742B69EC156BAD6BULL, 
            0x2C03B99604D3401CULL, 0x986359368E251291ULL, 0x667C1C23C14EF587ULL, 0x0451F503C0A51B94ULL
        },
        {
            0xDCF335CF2593DA73ULL, 0x2A394459447E983BULL, 0x5C982B5064B8C275ULL, 0x0A0465C107D9599BULL, 
            0x3A40074FE37D4FDDULL, 0xBB3B263033BF306EULL, 0x56AAAE4334027A3DULL, 0x3F4AAEAE22C04533ULL, 
            0xD73CB2D3C25DE53EULL, 0xBF6CF1FE57EA6A0FULL, 0xD247EC1BFF92EBACULL, 0x6ED46C0E09859053ULL, 
            0xD47CF87636782D60ULL, 0xE3D419CF0864F309ULL, 0x81BC38D2B2CCE1C3ULL, 0xF3CF0C8707198AABULL, 
            0xD385E7B2227193FDULL, 0xC3E049105FF9C33EULL, 0x53793C577D397B8BULL, 0x051204563915470FULL, 
            0xBCF73228CC8EDDF3ULL, 0xE0B2E63BBCE10433ULL, 0xA9C8B38C83B11196ULL, 0xACC1A49F67D34DB2ULL, 
            0xF8AF379C6451A9AAULL, 0xA671DF62E9B099A4ULL, 0x4FC1CA5EB2EB19DBULL, 0xE5F6DF17B7858843ULL, 
            0x1F8A9331F1F05EF9ULL, 0xE760AD0C7436EEFDULL, 0xE42D73053A14B874ULL, 0x05E1FBBF039D1440ULL
        },
        {
            0xDE719B1729E79A46ULL, 0x79C5EF08E7FB81C8ULL, 0x5F06C326103B9A98ULL, 0xF3F9D912BF61CBA1ULL, 
            0xCAD6578D4D0EB39AULL, 0x76EFEE79D2A6D278ULL, 0x9D91CB4C621BBF39ULL, 0x7FC87AD481B1383CULL, 
            0xD2A5A5AB8EF60E15ULL, 0x31A91DA82E395A47ULL, 0x031426D7D576DE94ULL, 0xA13977AA8E547823ULL, 
            0x9CD8DC19A8AF248EULL, 0x21ECE94419FE5F70ULL, 0xC04314A94C8D56F1ULL, 0x24A7AA588073DD45ULL, 
            0x631A90C91447D707ULL, 0x9C430376BF4AD31EULL, 0x39462BF785CE41FFULL, 0x76C7C52BC126E597ULL, 
            0x0F798325247B9DFDULL, 0xE9DAD3CD8E45A31EULL, 0x26F89D9BCDB0DD0CULL, 0x600A816FD018CC77ULL, 
            0xB0ECCF2505690013ULL, 0x4E607AA5355A28C7ULL, 0xE2EE2A3C59C83B2FULL, 0x0869EA07E58AAB83ULL, 
            0xEEEA29F0B63EC1EFULL, 0xF5C6C8EC351248BEULL, 0x78C0758AE956A720ULL, 0x3E002C502A6401A3ULL
        },
        {
            0x66BC1C901282B651ULL, 0xC373057EFE81277BULL, 0xB086B0D5289CDF0AULL, 0x5A40C24ABA9DAF2BULL, 
            0xB3083C52FC9DAB98ULL, 0xD1386882D15D3428ULL, 0x497170A563F7CB00ULL, 0xD16FEC7ABF1F0B07ULL, 
            0x5EC14B3A5294B5EBULL, 0x3E6E0ED33BC68462ULL, 0x3C3320ADEE795778ULL, 0x35A91D3021F4B716ULL, 
            0xB2575F69F72E075FULL, 0xFDE74CC01840F659ULL, 0xC78BF0763341C54AULL, 0x3FFF2B734487B63EULL, 
            0xEB3CB759F6C6CAF1ULL, 0x92DA838AD3E753CBULL, 0x0D1C2CAF39E93F2BULL, 0x84D3C7CCE2D1633CULL, 
            0xE586AF4078DB62C6ULL, 0x4EB1C461480061CEULL, 0xACE8E52B490CE812ULL, 0x1F7F1CA5CE2B7977ULL, 
            0x04DCFE5B6E500C25ULL, 0x9F31C110A309334FULL, 0xE1650FE35DB76CC6ULL, 0xED02643AC46E11BFULL, 
            0x55217B6B02FDC514ULL, 0x147CD4B6E675D051ULL, 0xD587B96E0D008D0EULL, 0x6789DB0C7972AB51ULL
        },
        {
            0xD7E2892EFC0A2D88ULL, 0xB2E7ECFF57DCA466ULL, 0x43A3F028B03771F9ULL, 0xE1DE10E721E43A4AULL, 
            0xA17A6BF4D694E716ULL, 0x52719D04C3285944ULL, 0x04F0A0A8DADD7FFCULL, 0x26BA69B17E8EF24FULL, 
            0xCA219B7D54EDBD03ULL, 0x09FEDCD827A7EB55ULL, 0x5AF859225780E6D6ULL, 0xACBD502F5842D772ULL, 
            0xDC111DEF1361D504ULL, 0x5A34581D7BAC40CBULL, 0xD136DC1FA291B2F2ULL, 0x0E1EAFCCBFA1299FULL, 
            0x7EE595ADEC10B1E2ULL, 0x78A4AAEAD110DAFBULL, 0x949E685E806BCDBEULL, 0xCB30DF16118E2F3EULL, 
            0xEE2E1BF94F636211ULL, 0x25B7CF465D8576DCULL, 0x250B7E9D0D1861EDULL, 0xEA34051FF75B0E9AULL, 
            0x0B59435B5618CB76ULL, 0x48958BE1AF3A1702ULL, 0xCCDBAB7A1EED8D9BULL, 0x0259BE3E472608DAULL, 
            0x53A6661BE60503C2ULL, 0xB97FDC094027C08FULL, 0x063786539887ECC7ULL, 0x021DAB8D0AB0F997ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseAConstants = {
    0x5FF200BDFB4C4A5FULL,
    0x912203E7D2A5830DULL,
    0x5BDEF94D0276BC6BULL,
    0x5FF200BDFB4C4A5FULL,
    0x912203E7D2A5830DULL,
    0x5BDEF94D0276BC6BULL,
    0x8B02C1F44D30FCF1ULL,
    0x85DC0E42972015CAULL,
    0x74,
    0x56,
    0xDA,
    0x21,
    0x88,
    0x93,
    0x2C,
    0xC0
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseBSalts = {
    {
        {
            0x4A6A6FE949BCA3B5ULL, 0x8A0C4E27AF0F9E19ULL, 0xB6F63438FDABE79EULL, 0xB3BC6DB124C5977AULL, 
            0xD68132B8912FE63CULL, 0x0C8046F38E847644ULL, 0xD85D9D6975EFA6E9ULL, 0xA50DE09F9F40B76CULL, 
            0xB73A16D3DD01C935ULL, 0xA5B302B20E264BC2ULL, 0x1E30BE4BA434492BULL, 0xCBD9E147429F8C24ULL, 
            0x3437743F778FCF55ULL, 0xDAD0139BE4A54F7CULL, 0xD7227D3A87B585BAULL, 0xFE10603FFEC4540AULL, 
            0xBE2B0D06B2341533ULL, 0x96CDA6939B6B64A4ULL, 0x132AFED00F3993E6ULL, 0x05A7A1C169B3593CULL, 
            0xB9BA9D2CA85BEABEULL, 0xBF088DB75D569920ULL, 0x5618CAF2705BDC92ULL, 0x8111F312AB2025C7ULL, 
            0x762939F80AD8EF0DULL, 0x6A6ADFF86FAADB89ULL, 0xACA0E652CE3DA29EULL, 0x4CC4722565A104B9ULL, 
            0x992811E1EBF9C90FULL, 0x62EAB14E649C5E6CULL, 0xB0EB9C2A04D978F0ULL, 0xAA94665C657EEA0FULL
        },
        {
            0xC5D1A044750E33EEULL, 0xAA70B58CFA429FEDULL, 0xD29B499CBC3ECF05ULL, 0x926C6138F21FC23CULL, 
            0xDB5509AC35DBA7C6ULL, 0x66C20A6E3ADD4207ULL, 0x048AE4DDDADD113FULL, 0x2187B23DFCF2123DULL, 
            0x2C7B87320A1341C2ULL, 0xAD7409DA5F857DB5ULL, 0x811C09253F052605ULL, 0xF7971CDA1EADFB26ULL, 
            0x661FBEC90F72C81DULL, 0x92E6AF9A91314437ULL, 0xBD99103BE14BB36FULL, 0x985C34926086EADEULL, 
            0x0DD7F7516DC813B9ULL, 0x5BCBB7DA4EB16DBAULL, 0x9AF1B0E4E8DE66F2ULL, 0x393E359A40DABA6EULL, 
            0x7856D9A6662ACA2EULL, 0x69D895E86AEFC772ULL, 0x10A064006EE4E845ULL, 0xC09216D491C62843ULL, 
            0x91488E5D86ADAC03ULL, 0x4FC3DCCAD21CAB09ULL, 0x6A91318DC55F84D2ULL, 0xB9B46DC82273BBBEULL, 
            0x4F7FB439F823DE10ULL, 0xB8FD15871C965785ULL, 0x7D9A44EEABF146D2ULL, 0xB2FE4743A9B135F0ULL
        },
        {
            0xCA91BAC7EC2D18C0ULL, 0x37128529E6FCDB74ULL, 0x836FEEB4F5B9E188ULL, 0x3B3612615614A58DULL, 
            0xC334EC8317B03C15ULL, 0xC478D7A1CF1AB0D8ULL, 0x5B0CD1349852BBC2ULL, 0x56DC7A3461E45EADULL, 
            0x0A636864402B14A2ULL, 0xFD78540C557A4F54ULL, 0xA955E7CC0E958895ULL, 0x9A17DB1C996472E4ULL, 
            0x6189AF6A8DD49DE9ULL, 0x469C868AEE33BC74ULL, 0x72260FA731F27EE8ULL, 0xC01E9D6C13AAAF32ULL, 
            0x7B785CCEBAB7AFD5ULL, 0xA2538C80FB416B0BULL, 0xAEF8732740E30B34ULL, 0x459AE532027D017AULL, 
            0x5A6BE090F550CEC9ULL, 0xE0E7434E1C6C4741ULL, 0x88FD6B9F0E46D66AULL, 0x45AD6BDE0FB99354ULL, 
            0x3ABC7432FBB71721ULL, 0x658201F6BBE0CAAAULL, 0x23A2C523FB66215EULL, 0xF54169E0B34D7015ULL, 
            0x20222508753121E6ULL, 0x4A570E825799BFF1ULL, 0x54C93DC805EB3093ULL, 0x5CE33A61A9CA5092ULL
        },
        {
            0x9A44D5BE9221C167ULL, 0x52A7A4AF850D37E8ULL, 0xC0BEFB4F965D9FC6ULL, 0x9082D82EC8F2689FULL, 
            0x913C0A3D7CEBD8E2ULL, 0x5FA7CFBF5310F1F2ULL, 0x72DFAFC1C3CED2A1ULL, 0x7D906048DB623B55ULL, 
            0x2218690608D41B8AULL, 0x78A0706AE709CA54ULL, 0x37D17BCEA0F213B6ULL, 0xB767BB8FB4EC3157ULL, 
            0x65DBFDE6CE77F135ULL, 0x3DEAA5033330A09BULL, 0xA2A638F04343094AULL, 0xE7BD8EB0631102A9ULL, 
            0xEEEB8971F6A06550ULL, 0x238841354CEA754DULL, 0x5E2F7945B0FE42D3ULL, 0xA5ECA772A23BD0EDULL, 
            0xB2D4873EDD1CB8ECULL, 0x542263A29E76EF07ULL, 0x23448C6ED848AAB2ULL, 0x5D3D92E66D07926DULL, 
            0x5232A6438F8C6165ULL, 0xEEBCD57AA1D484FFULL, 0xC8187A50A993F14FULL, 0x381CDD3E60947AB8ULL, 
            0xDE79ED46F4FC61DFULL, 0x49012DD92CE3C625ULL, 0xA735002CCAA4EBEBULL, 0xC6FFAE08C5F1309BULL
        },
        {
            0xB6DF5BF8C1A52E3EULL, 0x6DE0079725BB48D5ULL, 0x43A7E2E181D4DD07ULL, 0xC949F894161F767EULL, 
            0xFD92055FD932DCAEULL, 0x2FF8E4C884A734D0ULL, 0xFECC914411F66958ULL, 0x87F4DD73866A7D5FULL, 
            0x092C6BD0056197C4ULL, 0x0C556890168161A9ULL, 0x69C600E62E095573ULL, 0xDDA37B81C590EF45ULL, 
            0xB2C35E3CC0B2E6CEULL, 0x6610F2B3133DDF2CULL, 0x8D474A85055B4E17ULL, 0x0266FCBF39AC44F0ULL, 
            0x4AEA739F2FA69393ULL, 0xC97BA239D89C3FCDULL, 0x4AECD4855C48E16DULL, 0x2DD5DAA85F3D01A7ULL, 
            0x00AF9442CC5CBCABULL, 0x864F9ABE3302EE9FULL, 0x729B3BAE63A76D55ULL, 0xDA2B07CB6447D69FULL, 
            0xD018B6E5A9464E23ULL, 0x2B80C067914701D4ULL, 0x22B917FC3EA106B3ULL, 0xF2748B82EF0BC637ULL, 
            0xA524307A6F113AE3ULL, 0x32726F20F1D4D5C9ULL, 0x336F107DF4BABA42ULL, 0x240F524E631DF80EULL
        },
        {
            0x55FFE5672A588A83ULL, 0xFC05152609BAD27DULL, 0x1C8CC9BAC39CA07DULL, 0x025536A2577FE5DDULL, 
            0x5B0E9E53A3E3AEB2ULL, 0x64989301855D0BADULL, 0x96BB6EC0EBE20BD6ULL, 0x65EE7A58A0B6C76AULL, 
            0x0DADEA10FF5FEB21ULL, 0x54F07AA715C63DD8ULL, 0x8AD3C73204325F24ULL, 0xCB642F7771039E47ULL, 
            0xA8A5E1D666EBB0B7ULL, 0x8C184B264746DCCEULL, 0x242C104187F3ADD4ULL, 0xEF1F2C7EFAEBE30DULL, 
            0xD02859A21222D6D2ULL, 0x0BF6114162EE46B0ULL, 0xADE6D86BF4FF7B65ULL, 0x415FF0A89D19913CULL, 
            0xBEFF1EEE515DCAC5ULL, 0xA4A2F7C73548DBE3ULL, 0x9494A82CF343085DULL, 0xC29DB94B10E695E2ULL, 
            0xA136670850A7F706ULL, 0x9432418CFA37FDF1ULL, 0x9FB008AE12697FD6ULL, 0xFC68CAE1DF4F8896ULL, 
            0x41BFFD8FCCDFB748ULL, 0xB693B659A1914E11ULL, 0x814A0034BE0B1388ULL, 0xC3D5803AAF93DC1AULL
        }
    },
    {
        {
            0x81D5717D18A53DF1ULL, 0x113AE9AD35E90051ULL, 0x2F72EAED90D9C143ULL, 0xF6E98430CD22FE71ULL, 
            0x7C8B9D600B681595ULL, 0xCEFDBE1E956D2636ULL, 0xEF1F85399D1E8C5DULL, 0x36E8D23654D98C99ULL, 
            0x8166EBD89E61505DULL, 0x77CD4D79B5D0CDA9ULL, 0x310B830909445E3FULL, 0x8F7F27CCB913E189ULL, 
            0xF3F274DF747D0D42ULL, 0x7848CBCEC6CC30F2ULL, 0xA2EC8891E8644F3EULL, 0x1A3BAA253C47601CULL, 
            0x44E6C3482A536077ULL, 0x4052BB5B5FE8E218ULL, 0xECC5F7AE572F5BCEULL, 0x24DD0F46BAD55374ULL, 
            0x109CDCED5C6522A1ULL, 0x3CB30971AF93EBB5ULL, 0x0F025090D799E5D1ULL, 0xE02B9F9C4DD24CB3ULL, 
            0xF587DB289B436016ULL, 0xF07DF2941D29AAEBULL, 0x9CE00FC0179A087CULL, 0xD7A7B49502FC8DF2ULL, 
            0x00D94C757E78FD9CULL, 0x784213A934740C6DULL, 0xEC0F4374F8302A5BULL, 0x427EB671D1B10E6DULL
        },
        {
            0x1BB7CAB8E04D2D73ULL, 0x013516A9571BD995ULL, 0xE5BD0B7B7AF90739ULL, 0x26B72A9439EB4BF8ULL, 
            0xE77711D25B2264F3ULL, 0x9E96284E9F96653FULL, 0xEA0A6BCD6D37ECA0ULL, 0x244BA7704D79DDFCULL, 
            0x3EC6B2BD60106B4AULL, 0xC3315536A2710D9AULL, 0x00A2C7F4FA81DC18ULL, 0x09A131909B0FB89CULL, 
            0xDC0B5049C1B95915ULL, 0x946EFFC4C5884934ULL, 0x9F60A69DE43E176EULL, 0x5AFB604E7E3656AEULL, 
            0xCDF5AB1BDEE1E7B6ULL, 0x512355A00BC3033DULL, 0xED4ABDF069C591B7ULL, 0xF4D9A1F32C64982AULL, 
            0xBC84243C33597D93ULL, 0x6FE14B50B422F9BEULL, 0xFCD4036AF3D128E1ULL, 0x671EB9E83725D15AULL, 
            0x5E52702C9A3BA15CULL, 0x747D187B7BD49783ULL, 0xE433A731FA08FF61ULL, 0xF8AFF8A78C8ED6D7ULL, 
            0xB3E99B68563F847AULL, 0xBA4888A9C6A801F4ULL, 0xD973904F5792C717ULL, 0xA550AD67782205C6ULL
        },
        {
            0x2F1D8A45877E913FULL, 0xEECF3B10E48DED33ULL, 0xE886FFD4EBAC4E6AULL, 0xD52FE525C74F0889ULL, 
            0xD11B0180B3AD117DULL, 0xD0FF442BF188748AULL, 0x2C25958CAB43CAF8ULL, 0xC4C48CFB40BD0BC0ULL, 
            0x40C3AD19C2263818ULL, 0x4713766418F3AD5DULL, 0xC238B3B179D95AFDULL, 0x77BBAABAC45304BDULL, 
            0x9E93D854B5CADA4BULL, 0xAD002F52943C2F11ULL, 0xCAAD7708E5CC39CFULL, 0xAC017E668B6D0BC1ULL, 
            0x2E814731851D2200ULL, 0xF22CC774AB8CBA3FULL, 0x239466D0BAF8EFB5ULL, 0x431880A54E816074ULL, 
            0xE564F9305E690E13ULL, 0xD5B5890A193BAC85ULL, 0x14275BBC6656D0E1ULL, 0x692ACFA45B62A2E4ULL, 
            0x76C9141A5A540F34ULL, 0xD835A03F3ADD6248ULL, 0xF61C3E87AAE2D3C3ULL, 0x6C84F9C945C06F9FULL, 
            0x8DEDDD6906BEDF1BULL, 0x26DC8B261386FECDULL, 0xE680BD02818C8B5EULL, 0x30B5B6DFA6CCB217ULL
        },
        {
            0xD791D2946864B915ULL, 0x21E2B6F21FCB9212ULL, 0x35E4575FABC5B74DULL, 0x290A4C1A46DF1322ULL, 
            0xA9B3DAE9F939CC33ULL, 0xBB48046D44449B80ULL, 0xE4B1FEE0B8BC2DADULL, 0x9896EF34166FAE0FULL, 
            0xF06739C764573E39ULL, 0x25C470C9C4A458E6ULL, 0x60899F12E5D49696ULL, 0xFA497880A7F4B344ULL, 
            0xE9E858B059604547ULL, 0x47164A6E2C5B0FD4ULL, 0x2DD5AEEBB55AF7C0ULL, 0xF9832555963753B0ULL, 
            0x8E5921CDF5719196ULL, 0x4014DE1FE6206B9DULL, 0x39AF2819528FB40CULL, 0xF015DA451102C178ULL, 
            0xBAE8E80C11221C63ULL, 0x57C7CF3EFCA258F6ULL, 0x74FFA0AE26120296ULL, 0x67105B0C0644A5D5ULL, 
            0x8BA3582424E65C46ULL, 0xCCB737D2D17E5317ULL, 0x51A446FC4069CE62ULL, 0x1D18F25A2B7421E9ULL, 
            0x8B80A45BC9E13410ULL, 0x7EE56502F41C9FB9ULL, 0xB32D3FED7DDC8824ULL, 0x93C948FC5D36FE9EULL
        },
        {
            0xD5B592B38DB9A674ULL, 0x960CD7C79D34DE17ULL, 0x0AA2C982C91CAC11ULL, 0x8C86F8358AE11A94ULL, 
            0x26D2A93AC94CA4F6ULL, 0xE94A985D0491D350ULL, 0x6530679C49E94035ULL, 0x8EDB1CF3A1E0F0B3ULL, 
            0x47FCF0615A9E9500ULL, 0x749397D9116B4941ULL, 0x5799E24727909465ULL, 0xF336F014F6D44D01ULL, 
            0x5C652984C82BBA93ULL, 0x2D4560DA95512474ULL, 0xFAE285473019FD18ULL, 0xDD2536CA2607A4F4ULL, 
            0x379F8C405A8226DCULL, 0x45D454C75510A944ULL, 0x0C6497B2A5A23DEDULL, 0x852A8A6684F91549ULL, 
            0x54007351C79C2702ULL, 0x23FD9ADD2C3480E8ULL, 0x9177E12F8DB83A70ULL, 0x6DA8828B7D0440DDULL, 
            0x32673B1239D24E20ULL, 0x9260057E25069F60ULL, 0x7FCBDF42060D0F81ULL, 0xE05F5BA173D77E10ULL, 
            0xAAD9455E710B982AULL, 0x8067719D8F096630ULL, 0xC759B2C9C76065C0ULL, 0xC5156B07A2774581ULL
        },
        {
            0x9DDF1752A0555642ULL, 0xC8151A7E87256CC6ULL, 0x6845ACEB707A9508ULL, 0x1DF68BB750B3F2D5ULL, 
            0xBDEB2604306135E7ULL, 0xA7EAE4200C6ED3D7ULL, 0x2D5241B608C16207ULL, 0x06C8BA82BE19B17CULL, 
            0x1CD1082C37FDAD86ULL, 0xB34DC1C5EA506A75ULL, 0x70CBBD1219EAFB23ULL, 0xE0D4E132B6AC47DDULL, 
            0xFF6A216D53B88CCAULL, 0x554814BA8C027096ULL, 0x19F9996A36654940ULL, 0xA5D08542F51F401DULL, 
            0x9B16C30362E46DA7ULL, 0xAD2FB4789474249AULL, 0xB7D0ECAA646984D5ULL, 0xE7F6E55183136AEBULL, 
            0xAFA0E21ED63E3FD6ULL, 0x07A5B9BEED829CFFULL, 0x3DBFC2A1F2465013ULL, 0xC0A67D41A2E47628ULL, 
            0x468BD58831D3BB1EULL, 0x56B10385489D2E1FULL, 0x357DB185848BAC58ULL, 0xCE9F7B8997F9A707ULL, 
            0x018D043E81138031ULL, 0x1205F61A876480C2ULL, 0xC898B6B05B7DC800ULL, 0x421B00ADB797B38DULL
        }
    },
    {
        {
            0x75621D1B3AF98867ULL, 0x58A0CCDFF3C119A0ULL, 0x13E8B5A0719C8F41ULL, 0xD8B6C2183654917CULL, 
            0x9D1C58111977357EULL, 0xC3BA5C27FC22F996ULL, 0x0A7D5F57F0401A15ULL, 0xE6A9478C5D86B228ULL, 
            0xB41310DCCD38DAFBULL, 0x92626EC1F5A20844ULL, 0xA8DAC220DAC6CEEAULL, 0x4B9008662E7B1A84ULL, 
            0x81C91F6E4EC01BACULL, 0x8381CE6C021FD95EULL, 0x1D6438E47E2BCF9AULL, 0x624988138F347771ULL, 
            0x286416B831E1CA95ULL, 0xA0D860378A4A2784ULL, 0x98983D032C3A50DFULL, 0x753DF6BA98BB1313ULL, 
            0xFBC854472FC039D7ULL, 0x051AAD5A0C4721ECULL, 0xF11C081E5DBC68CEULL, 0xA1B95E0DDC2982D7ULL, 
            0x0FC182BBEC1FA3FCULL, 0x8AC88B61DD45ECA4ULL, 0x3AF5086C908B66DBULL, 0x14D40C262855F873ULL, 
            0x70CEC5E960DEB9FFULL, 0x2B1B9BC0BB57678DULL, 0x6D8A8C0CEB1B31EBULL, 0x55295CA4AA98C3A3ULL
        },
        {
            0x3A2DDD949C71DFBAULL, 0xDB684F05BCEE4B23ULL, 0xC088F022EFA3C69DULL, 0x2D2678E61EA28173ULL, 
            0x3C38DF97861F5A20ULL, 0x60B1B5394CE932D7ULL, 0x57D10A3C9C8B74A1ULL, 0x26A1D0D7362D0119ULL, 
            0x972B0ED39A73243DULL, 0x32BA93C7CA4256F6ULL, 0xE36B3E35A7FB257AULL, 0x314795191EE0D33AULL, 
            0xAAA8C02BF7153661ULL, 0x5FF4692EB2194F86ULL, 0x6D4982F95FF7ECE3ULL, 0xD988AB6D619E469EULL, 
            0x2E9FE3D1729E04ECULL, 0x7847B0C084A9F271ULL, 0xAE44AB3BFD53EDACULL, 0x8E16FC9BE073AB27ULL, 
            0xBE6B71631628B27CULL, 0x93137594143E6A30ULL, 0xD5090A78D64337B3ULL, 0xD0A8A3E72CF39EBBULL, 
            0xCDDE96512FE176ECULL, 0xB2BFB1AF0885C6ECULL, 0xFB2D5A94E2D35B7EULL, 0x05C0D15EBBA85B41ULL, 
            0x607E6931AB467CB8ULL, 0x66C6DD181CBF4857ULL, 0x69B5F4871C58DE32ULL, 0x92B9AA3012BF4037ULL
        },
        {
            0xDF67B4B8142ACE59ULL, 0x3C9388E3942709DBULL, 0x6BE4876786F08694ULL, 0xE0E02F71A5A177F2ULL, 
            0xA3DA99A001214B4BULL, 0xF82BECA4D3F23F6FULL, 0xAC9AE4F41295A737ULL, 0xE16BFA503A1A174AULL, 
            0x9EBDBE30A18DA0E7ULL, 0xA3F89B63A1F573E0ULL, 0x3F80294349977C51ULL, 0xE9A330D58E2509A1ULL, 
            0x089765A85D570556ULL, 0x6B2867A8B472DB95ULL, 0x038351E173E2CE70ULL, 0xAEB3899373503020ULL, 
            0xB0AF25B9C889EE23ULL, 0xF3DF59EE103CB9DBULL, 0x00113CB607047B49ULL, 0xF9C850148DF039D0ULL, 
            0xC04AAF2A159C8B34ULL, 0xD1137996792A523BULL, 0xFE23B935FE06E317ULL, 0xF462E2A56B6C769EULL, 
            0x1AC9744900075A58ULL, 0x0A6DC22CDFA31900ULL, 0x7BD6607211771DB5ULL, 0x1890AD3D05C57FD4ULL, 
            0x8C357228E685F937ULL, 0xBB670DCD0B1B3420ULL, 0xFAE345E32F28BF65ULL, 0x62B9312F24716985ULL
        },
        {
            0x53EA42E3FCAB43CAULL, 0xC90F404491149766ULL, 0x9B14EE50ACB6FBB6ULL, 0x945303985D4BB607ULL, 
            0x302B393578CFA913ULL, 0xD62157F5519A3549ULL, 0x2C81691732B9152DULL, 0x9DCE7FC604BFF5E9ULL, 
            0x648F4AB4977EE258ULL, 0xA3810030A2D3DE7BULL, 0x93CE2FC9ABFAA525ULL, 0x974EB69C9DB0ABACULL, 
            0xE9F19030C0BBC872ULL, 0x7D090D3A01D265EBULL, 0x55F498BC7DD8784EULL, 0x5DAB4A592E3BF5D0ULL, 
            0xD552681A236F8128ULL, 0x2104AA0497963F7CULL, 0x453FC41A7BC69880ULL, 0xEAD171161704310BULL, 
            0x1068D4E5615B23A9ULL, 0x139B09719E95193FULL, 0xD0DA0E7350078611ULL, 0x9D6F5195410DFBE4ULL, 
            0x6C75144AB6A48866ULL, 0xBFA91A8B7378696EULL, 0xA5120F52910F1F87ULL, 0xE3D5A94FBE7DB611ULL, 
            0x3EB0B6967D506B56ULL, 0xA075F0C17D92F546ULL, 0x8D130BB508E2D8B7ULL, 0x9F32B3F0544E6DD6ULL
        },
        {
            0x6CCBD5B0FC1A8747ULL, 0x474586ADDDE5B1E7ULL, 0x91B23A23F4454FC4ULL, 0xADD6E2F8776FAE9AULL, 
            0x81561259400431F9ULL, 0x0ED6E5B2A69ED026ULL, 0x83930F7239B4DDAFULL, 0xE9C4F98C9E755C6FULL, 
            0x39AAD10AE19AB1A4ULL, 0x04B7AB23B585BAD1ULL, 0xD5B1B5B19CC94355ULL, 0x37A37197EC02E283ULL, 
            0x6F251690156F8A4BULL, 0xDF1F926E842C22E1ULL, 0x0ABDF89AD9D676A7ULL, 0xF92A330C5A19A4A0ULL, 
            0xD7DBC81810DA53EBULL, 0xD63F0E7DE2ED03BDULL, 0x0082055410796566ULL, 0xB94E1FFE1750AD39ULL, 
            0x29009D0EC722FF9CULL, 0x389254BD9B34793EULL, 0x67AB4D910FF393D4ULL, 0xECA9A906BA56B394ULL, 
            0x237BE2AADA29A4AEULL, 0xE437E11DCE1E8D88ULL, 0x535A05256661B04CULL, 0x0257EBCF489D59F3ULL, 
            0xDAD1A02040465124ULL, 0xF7B9398F81BE56D5ULL, 0x31ADD3A32C40E78CULL, 0x046FBDB08C99313BULL
        },
        {
            0x170DA9CD9EDDFA34ULL, 0xD6208208AB8C5D71ULL, 0x19641A366A593551ULL, 0xDAF70AB16D272FDCULL, 
            0xCE2A07CB3FA7BAD1ULL, 0xDDE82DBBA3D9B7E8ULL, 0x86D5A932E50325B5ULL, 0xD7442093D0FEC610ULL, 
            0x02B0D458678AF4C6ULL, 0xE6D0459B9558A81EULL, 0xE9AC6BEC77866999ULL, 0x4A44CA1F649F89B4ULL, 
            0xF1355D9301CC0BA2ULL, 0xB1A458C098608203ULL, 0x2374181219147D2BULL, 0x97E177CA6CF39AF2ULL, 
            0xBB8A37D176C7408CULL, 0x7824B40112CE5932ULL, 0x32023851D16321F5ULL, 0x76D263FD1D6ECD9EULL, 
            0xB65B16B8AA460C86ULL, 0x3D1DBB3F61E51D3EULL, 0x1512CD6B16F72061ULL, 0xD7BE0A3571DB4944ULL, 
            0x52960572CC62E0BFULL, 0xAD7A01D1AB112620ULL, 0xCDB408DC36267AE3ULL, 0x0E4BC2DC2F148647ULL, 
            0x8FE384FADAE6F58FULL, 0x648AB9B7507928F0ULL, 0xA8A25DF2E3254A27ULL, 0x84A05A4A5FC3A2B1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseBConstants = {
    0x2D31F6AC24719146ULL,
    0xE60676B1C479817BULL,
    0x2045349563A1C4BEULL,
    0x2D31F6AC24719146ULL,
    0xE60676B1C479817BULL,
    0x2045349563A1C4BEULL,
    0x18DF7B9024E6F6EBULL,
    0xF16BAC5FB0C71765ULL,
    0xED,
    0xFF,
    0xBF,
    0x41,
    0x42,
    0x9E,
    0x59,
    0xDE
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseCSalts = {
    {
        {
            0xFE2F0545AE4F4304ULL, 0x4F752EA21323C32DULL, 0xB1238B1615D5DFB3ULL, 0x90085B257A0081A2ULL, 
            0x299D4EA68FAFBD59ULL, 0xE4E291F96D529456ULL, 0xF58E7EA5B28CBB17ULL, 0x082235B316DECDEAULL, 
            0x0CDEAE1F1CA9CD9FULL, 0x71CA4875E2CE9B69ULL, 0x97A8B00D65D158B3ULL, 0x9A598AEE660B838AULL, 
            0xC691F8730261F8BFULL, 0x7711C21764A91C46ULL, 0x0964018E5F02BB08ULL, 0x796DFB718CB8F709ULL, 
            0x22CD7BD1E9201BFBULL, 0x909EAAF2065AF47AULL, 0xE3223B9B074EA4E8ULL, 0xEF1EBF8F67039F43ULL, 
            0x20343DBB20033411ULL, 0xDD710EE651399013ULL, 0xB5D44155FBDA8321ULL, 0xD426E6A0EE8DAA09ULL, 
            0x446C10A7DAB6997DULL, 0x7D5FF22694797916ULL, 0x73722AB4FD93C934ULL, 0xA5964B8C2CDEA6F2ULL, 
            0xE4D51A41A664EDE6ULL, 0x08772B946500F7E8ULL, 0x7FCADFB7357702B7ULL, 0x39BDA35142C14E2DULL
        },
        {
            0xCE1ED7C93C5FA02CULL, 0x2C37A4FE640E060AULL, 0xE3DD8C7B9BF438AFULL, 0x102ED02F9721F69AULL, 
            0xB30B9FA69E37162BULL, 0x35F01A8C130B3FBAULL, 0xFB60733E0D975246ULL, 0x899151D909E14326ULL, 
            0x34B6CDC07826C58DULL, 0x1F84C0ABD065A1F6ULL, 0x8FD3F540CEB96A5AULL, 0x6BCE1ED13FFD5647ULL, 
            0x65A1780778D21C63ULL, 0xF10C04CDDA2964E0ULL, 0xAA7C144FBA62C63DULL, 0x2A6F2B9BD7AB25C8ULL, 
            0x4A6193E0046907E7ULL, 0x86DFBE1F3CD3C1BDULL, 0x8C8938F36B10EFB8ULL, 0x118AD3DFF9CC485DULL, 
            0x6E828DEDD88932E0ULL, 0x20A487187EED27B6ULL, 0x7A1F9BD6FB6774FCULL, 0x4AB861003C17A744ULL, 
            0xA9993F8A9AC50E38ULL, 0xCC47A822463BAC92ULL, 0xDACA012F328AC4FCULL, 0xBFC458D3D4E6EE4AULL, 
            0x93D4E3CBCE3C7A7DULL, 0x6EEFF40440E6C6AFULL, 0xA0AED4F1BFBCDDC3ULL, 0x3C0117D6B9448BEBULL
        },
        {
            0x6F8FD576881307A9ULL, 0x91273F16A3929F84ULL, 0xE55EF3A6CB583C2CULL, 0x2231E51F6DA06851ULL, 
            0x269261BA7421EEFCULL, 0x0998174A65204C15ULL, 0x8A87E50421653360ULL, 0x0CC20749FD1F39C8ULL, 
            0x4AE50DB8EB434773ULL, 0xDE3A7976681520AEULL, 0x99BD01596B6D645EULL, 0xDCDD886DBC737F49ULL, 
            0x0B1DD72C28A99353ULL, 0x8B45C742673F857AULL, 0xC0DA8355FD4C94F0ULL, 0x73D19617AD63884BULL, 
            0x2BB05D85F28DD3FCULL, 0xCBE3A341B8304B71ULL, 0xA5076F7B2404CFB6ULL, 0x6430CBBEA305ED62ULL, 
            0xE58AF8759835D788ULL, 0x67AF3C4F3087CDA1ULL, 0xAAACF8336EA590CCULL, 0x4BB0A609C06671E9ULL, 
            0xD8D353441DC0A859ULL, 0xF6B6B8DC53CF3CB9ULL, 0xA6444C0E9AFB0F7EULL, 0x203A65A525AF652CULL, 
            0x9B88023183F86D68ULL, 0x863191A126316DF8ULL, 0x22F260D52769F203ULL, 0x38D4F8906E78CE3EULL
        },
        {
            0x6B29ED5F506479AFULL, 0x6932D52219F1E99DULL, 0xCB4022A4B945CCAAULL, 0x83F0AC0225823495ULL, 
            0x313884459AFFBE9DULL, 0x69A045F56FE5696CULL, 0x557C60FDDBAF4086ULL, 0x154261A048DA6A38ULL, 
            0xB94D6DF3AC0C43A4ULL, 0xCE63FF3CC2D7F514ULL, 0x01E78F7359982312ULL, 0xEE55F50468AD4833ULL, 
            0xB0950DA8AB044D5BULL, 0x631ECA410F908851ULL, 0x048EA65214E3C661ULL, 0xB219A2A3600C80C8ULL, 
            0xF2E85EB22C34C5AFULL, 0x2D0CC27C523A9468ULL, 0xC10042A8FD2A91FEULL, 0x5116645C602FB861ULL, 
            0x83F4BF2EED1459C8ULL, 0xD230D025289D60ECULL, 0x318B075F5C80397CULL, 0xC12FD18D8583609EULL, 
            0x0BEFC6D9BBFC4AC9ULL, 0xA48FA1B24F22A9B2ULL, 0x766999AA38CFD446ULL, 0xB17ACB974D0DB388ULL, 
            0x52A5D5E6B5C5244AULL, 0x1EC4724B63EC8A83ULL, 0xEB0BAB3B3E84CCC3ULL, 0x6B5EDF0BE2A0FB7CULL
        },
        {
            0x1ED9D122B7D69CB9ULL, 0xC8988F9721AE0A22ULL, 0xAD84BEAC3BEE2972ULL, 0x0ECC9ABD8C3A28E1ULL, 
            0xCC168A72699A8C55ULL, 0xBBD7B1B254B34F28ULL, 0x6D1866679915EDB3ULL, 0xFC65C8F7E25B745BULL, 
            0x7B0FA23C15DF1D5FULL, 0x2220D9E7477B32BDULL, 0x915676E52B48F7DFULL, 0xD80D2A4804850774ULL, 
            0x4CE0BD5F8C88255AULL, 0x2A6E73412242AF00ULL, 0xA0449093C45C0F24ULL, 0x7D4DEB6048578800ULL, 
            0xB40783E2DA0DBD85ULL, 0xB3DD56B133ED18A0ULL, 0x121D923E9E44E753ULL, 0x86A570736F7AFEB2ULL, 
            0x626810315C8304FEULL, 0x4B33FB4403927811ULL, 0xB63A8DFDBF7C5B98ULL, 0xCACCCAD1C3184657ULL, 
            0xA709EA3866CC51C5ULL, 0x260125229A1A9783ULL, 0x8E1236B8B941CB73ULL, 0xA1D91F501ECF1E8FULL, 
            0x622F9B65EA8700B4ULL, 0xA1F6E5258B1D11B7ULL, 0xADD137B52535A945ULL, 0xB158662A12F834B6ULL
        },
        {
            0xB8B95CB8FE52E258ULL, 0xB301E5FFF4C6593AULL, 0xFFFE57C2F72936D2ULL, 0xF45AAD146E9890E9ULL, 
            0xDDF6663CE6058D5DULL, 0xCD9C4B9BDE5BEB7FULL, 0xE0F78ABBD6159B36ULL, 0xE6F68DB087CB83C9ULL, 
            0x67A9A2BC50A212CDULL, 0xAB119370A40EA504ULL, 0x85EEEE3806335B72ULL, 0xD0202EF73E335DC9ULL, 
            0xAAAEF18DAE794F6CULL, 0xD8052BEDFF633AF7ULL, 0x4341D177264C90F8ULL, 0xE138E2A43FFEC858ULL, 
            0x32B9A7AC63CF3D42ULL, 0x8023ECA0C55911D8ULL, 0xD6E8CA703C2C0A5CULL, 0x4A6F79D00B91721DULL, 
            0xDA25DE5AF2B29666ULL, 0xC944FD6DCE55EEEEULL, 0x2FAB94953E047EABULL, 0xE12F5032FDDAF301ULL, 
            0x338D3591EFA22B06ULL, 0xF24792AAA2C35A79ULL, 0x250B71A59B1ED3E5ULL, 0xBBEE49FCE29A745FULL, 
            0x9528CA11B30EE8ADULL, 0x2DA22B2E5D9C6C54ULL, 0x4F80BF228CA3DF24ULL, 0x3408F82C6F70C2A9ULL
        }
    },
    {
        {
            0x13C2522A03FAC3F6ULL, 0x2761B9E1D174206AULL, 0x037D5A4211EA8217ULL, 0x56063D27063C4325ULL, 
            0x72C9FEB0E7617087ULL, 0xD1AF9F35374C3F00ULL, 0xA80260F1E9EF1805ULL, 0x006FB97CBFB9E360ULL, 
            0xA644ED7F4B5970D3ULL, 0xCBF9F3960EA56DBFULL, 0x769B8C6DAB337959ULL, 0x9FCBFC4446CA756FULL, 
            0x81EEBB844BC74792ULL, 0xA7F1AE1CB24B92A0ULL, 0xE0CCB12A8DB9AC80ULL, 0x4FA7A707EAE43AD1ULL, 
            0xA0F49706AE4DA1A7ULL, 0x4453814F4CD534D1ULL, 0xD566F063A5C9FCB7ULL, 0x5BB9CF6B49EB9D5EULL, 
            0x8498D3FA5CEFD5D6ULL, 0x32E8D622715DC75CULL, 0xB309774D1C528950ULL, 0x69788800DE1ABD74ULL, 
            0x7F2E4AEEF1038F6CULL, 0xFB416D0F83CBAB65ULL, 0xC19DCC3AC18BFC0BULL, 0x547A0D5E433B0501ULL, 
            0x712F16DEF13FF3D3ULL, 0xD6A53D232D9E82CBULL, 0xBA1DED82042C34E9ULL, 0x6BB06E1B95B57131ULL
        },
        {
            0x31926BF900C2E140ULL, 0x2CE9F05E93083E54ULL, 0x6987366A8B45ECC2ULL, 0x390BAE9E33B56594ULL, 
            0x879C7DEB91E723A4ULL, 0x0A94D70868A484F5ULL, 0x22D420A1B3917610ULL, 0x74BDF159456E982AULL, 
            0x0C0D42C9CC91CBDCULL, 0x294547596964AD0BULL, 0x3202BDE191D7C0F5ULL, 0x5D6C0AD33463522CULL, 
            0x23A74A16EEA5A8B5ULL, 0x871ED148543889B1ULL, 0xB95D75AD2CB124C1ULL, 0x92F1CD6D1F9ABB1BULL, 
            0x7A886D29CE6E8DF1ULL, 0x36B563328017F7B5ULL, 0x68A155AD3728B35FULL, 0x01A31FF16D440B57ULL, 
            0xD1E243E4CB3D6CDEULL, 0x91366B9674B485FEULL, 0x3B30F97477E79DC4ULL, 0x40E68DDE8DBF6316ULL, 
            0xEC7B0E98C35801ECULL, 0xEFCBDD309E5427D9ULL, 0x219C2825676A3CAFULL, 0xE3F78E83AB326E1EULL, 
            0x3D80D082CEEEA34EULL, 0x4BAC0076BDDFAF89ULL, 0x5F8179BB417067DBULL, 0x92FF69CCB420B7C8ULL
        },
        {
            0xA201A54E92FF8228ULL, 0xC5EA3A99158BC77AULL, 0x00A757F352DA4843ULL, 0xABF025A59785F531ULL, 
            0x4887FF66EE9F5A84ULL, 0xE482D8A8B17B5A83ULL, 0x9B1E0434AC70F61DULL, 0xF6756CE61B542F97ULL, 
            0x930A5A586CF96039ULL, 0xFAC6D116972C839EULL, 0x7882AB93162C47EAULL, 0xD25C077E4255B75EULL, 
            0x9B6D978D7912ACA1ULL, 0x6F048AED5F58C7FCULL, 0x6D0A92765789A560ULL, 0x50734CCB9E15F8B6ULL, 
            0x73BC8853EFEAC6E4ULL, 0x76F3F11B642E7480ULL, 0xC08D8111EDF16D93ULL, 0x78CAD2C891E54AF7ULL, 
            0x8853B1A39E591307ULL, 0xCD1265CADF3BC920ULL, 0xEBBD581A4C92E3B4ULL, 0x514380FDF8E53878ULL, 
            0x1DE2A6477D8C391AULL, 0xDE94C1EF690CC07DULL, 0xA6DA8677C7E06408ULL, 0x2F77BA39838E4A90ULL, 
            0xD78A9E8869CFEFD3ULL, 0xB35FDE80A07E8352ULL, 0xB91AAEEB2C2BC915ULL, 0x48F036DEAF022470ULL
        },
        {
            0x4ABB613BC6BF22D9ULL, 0x06F027EB067EE657ULL, 0xB1A7954481C4F847ULL, 0x5E241EA9BC5CC75BULL, 
            0x62A2F1A87367D323ULL, 0xA359E5CB2A706A45ULL, 0x65FA01991E1A94BBULL, 0x180F9729346D3C68ULL, 
            0x6CEB8624F738FE01ULL, 0x5F3DDDB1428A31E2ULL, 0xA23D0945049F5D72ULL, 0x53008063A802B5C1ULL, 
            0xA6AD8D9F3E547BBDULL, 0x95EB2B0AE43DC8D1ULL, 0x400D444EF7B7D1E4ULL, 0xFCE25A831844A483ULL, 
            0x64AD4CF3E3D6F10AULL, 0xBF425F1FA03AA86DULL, 0x092382A3D50CFB84ULL, 0x13D61C736D9D6547ULL, 
            0x9C70D41F7A963603ULL, 0xE85BCA54A44730BDULL, 0xE4E68F218AD613A6ULL, 0xDFAE32284D0E3327ULL, 
            0xDC18674FB3EF279CULL, 0x165FA620A8A0EB09ULL, 0x9CAA4552B913E27FULL, 0xB97996E808E76E3FULL, 
            0x164D8853DDAE5313ULL, 0x4A9D672563A119D0ULL, 0xF8DA052F9C68284BULL, 0x57D13FE2983D2E43ULL
        },
        {
            0x472875F1C7645E50ULL, 0xA1104DCA37D5DB8AULL, 0x5DEFBF4FCCA7D6DCULL, 0xF57A887487C01FFDULL, 
            0xD1325A2EF87AF26EULL, 0x8286673BCECC5524ULL, 0x8121FF1F13CFEF70ULL, 0x5A018D0AB8C1BB50ULL, 
            0x11388DAAA6C97A9EULL, 0x0519AA893177AD52ULL, 0x10BA29574DB95E46ULL, 0xCAE988D555037F99ULL, 
            0xC3FAC39470307200ULL, 0x06C9A0665889DAE6ULL, 0xB397A38623AA46B7ULL, 0x8AEE805118A17248ULL, 
            0xCDCF62FF2CAC01A3ULL, 0x897BF3D44453245DULL, 0x55D47C06BA25A470ULL, 0x7D7660068D7D0A59ULL, 
            0xBB443C8753828731ULL, 0xDCFF570C18876811ULL, 0x52082F93032149F0ULL, 0xD9CC9BE477AF8978ULL, 
            0x6D10A3E9497A8B94ULL, 0x546591D059309B7FULL, 0x8EC66C495430A212ULL, 0xF4F59D3986165C9EULL, 
            0xE299642C64B2B465ULL, 0xAB1F9EA67929E8EFULL, 0x44624AA86E00A19DULL, 0x1A91BC3E5654EFC5ULL
        },
        {
            0x294BC2249B470939ULL, 0x4D78298573E65CC9ULL, 0xC6048F2544F2927DULL, 0x048988DE44D71997ULL, 
            0xB80117AEB8CD71C9ULL, 0x581D958A16B6474AULL, 0x15EAF5AE54817BC9ULL, 0x8C2ACD4E6D9517B8ULL, 
            0xC5D8ED772056F5C5ULL, 0x8CE5B3E2F2E1E2AFULL, 0x2D7C90907E7179D0ULL, 0x5481494A16BBB248ULL, 
            0x1C7BC767D5E45AAAULL, 0x0BCE7F4248ADCD2CULL, 0xAFBC7DC384A605B2ULL, 0x9C1451B3C59CA773ULL, 
            0x66489AD583124685ULL, 0xDA42D376DA348410ULL, 0x26EE738B0CF863BBULL, 0x179E7C5136A6DEC8ULL, 
            0x1EA26988E3D76D9AULL, 0xE7506E7BA1C1189AULL, 0xFD17E8E812A814D3ULL, 0x82E4A17280F8E821ULL, 
            0x93C5696C050DF23DULL, 0xD672CDD3043074E9ULL, 0xC61B61512F08B795ULL, 0xAA815C32FBED8BEBULL, 
            0x1C7F0233189A5754ULL, 0x9C619C784C28DEDDULL, 0x8C36709F576FC361ULL, 0xEED2118953772D62ULL
        }
    },
    {
        {
            0x1A698B217344FFBBULL, 0x8C53545889728E88ULL, 0x12ECBD468C5EE714ULL, 0x3B146A618BC5D215ULL, 
            0x95644500E70C52EFULL, 0x12FD5EA4B9C00026ULL, 0x89F68FFEC4F5F7A5ULL, 0xA4EE12977622522FULL, 
            0x9F39D44F2D5FD7DFULL, 0x66389877280304D5ULL, 0xEB4069B7A5C25A9FULL, 0x94D982E20D6DD785ULL, 
            0x037D4C1E1F20DA7CULL, 0x219BD17250CABD97ULL, 0xCD78B367DE578F56ULL, 0xC85E5F3084B973E4ULL, 
            0x572ECDA74E15068FULL, 0xBEFE0142AE7C6066ULL, 0xFC4C9600CCC1C9CAULL, 0xA73F1B121A307570ULL, 
            0x44CABF3C2EA9374FULL, 0xA9460CDD3A6B90DAULL, 0xF1043604847676E2ULL, 0xC453891A00F2BAECULL, 
            0x4940DC0379A77363ULL, 0x984414060B64405FULL, 0x66D2F9E0DA7D9FCBULL, 0x26494959BAE6B1A3ULL, 
            0x96029C9380848430ULL, 0xCF7895E5AD4B5DABULL, 0xB97121D3AF5BEA03ULL, 0x3B3AAC3BE7EFA1DDULL
        },
        {
            0xACD38FC2C70CCBCCULL, 0xEA539C00E314C8A6ULL, 0xA3CE773F42D1EB75ULL, 0xDFC64CAA7EC0BBC2ULL, 
            0xF4EDA66E6C0F88CFULL, 0x3DF6E51CF25C0711ULL, 0x3EEC2B4E68BDB555ULL, 0xC5266770A98DB2BBULL, 
            0xB097BF641B123625ULL, 0xF6DCAC03B4E3E73AULL, 0x5403948A26EA3A9AULL, 0x59F1125BD8732C97ULL, 
            0x43FFB2CE50B038B2ULL, 0x74D4E3F48A82E05CULL, 0xCA7E22F24EBEB450ULL, 0x1A52A86D84D37464ULL, 
            0x98D7B8398A0F26B5ULL, 0xC98B9DA02EBFAEBDULL, 0x5C7FF434222CDA2EULL, 0x7C53A5E32DD4CEE4ULL, 
            0x3B3EA871339CEB96ULL, 0x11F2C2A04ACE3E23ULL, 0xBFB53C1D11E76610ULL, 0x380BDA2E98C5BEB5ULL, 
            0xD99FAB09C6A1BCDEULL, 0x2A948384892B6643ULL, 0x8A59FBA3B6E3D184ULL, 0xED6FAC1427A5CAD4ULL, 
            0xFD9B524E1EE1612DULL, 0x6818ACC11C91B658ULL, 0x1C2A28BAD1F5175AULL, 0x22E080ED77C6D07FULL
        },
        {
            0xEE22B769D50ED184ULL, 0xBE936C2A2DE7D9F8ULL, 0xED61CBF3B6CACC2FULL, 0xA9AE2184AAC6F7F0ULL, 
            0xE149ED25335ECEECULL, 0x988A744F48FA5874ULL, 0xF13B0387D4348F9BULL, 0xC960E7F068F3876EULL, 
            0x681A07C94A3B4BA5ULL, 0xFE266CFCCA2AD042ULL, 0x4FF8D2720D715462ULL, 0x173011B748C5B808ULL, 
            0x7ADB4D493A0B0498ULL, 0x286ADC01023CB7F4ULL, 0x184B9740B64E0B0CULL, 0xEEED75BE44800284ULL, 
            0x65AA835BCA8D40AAULL, 0x31F3F32D73C0B9CFULL, 0xD17DCA7825AAADE8ULL, 0x2B43E29394563138ULL, 
            0x727A182122F6F8BBULL, 0xCC21ADD7DBAD0410ULL, 0xFACFBE61DF79E770ULL, 0x42CADA36BD38ACC7ULL, 
            0xAED907A83316D11DULL, 0xC8EA4FF23FAC94CCULL, 0xC9800FC70A86A60BULL, 0x1E86C985AB7AE734ULL, 
            0x3B4F12E6CF126C3DULL, 0x3E58DDC16BCD6D4CULL, 0xF10BC9831BBEE15AULL, 0xFB22984BF8697372ULL
        },
        {
            0x389447F7A74A9B57ULL, 0xF9774CD8F0D443BCULL, 0x0F20D24F4F0B91DEULL, 0xE0B93505372CED1DULL, 
            0xC2B583C939FC1EC3ULL, 0xC0BDB14454FA84C7ULL, 0x7B59EAA2746E10F9ULL, 0x70003E42F1561910ULL, 
            0xA73CE0996D75C930ULL, 0x85CBDAC46BA153EBULL, 0xAA14E9D471D039A6ULL, 0x28CE059E43B479B9ULL, 
            0x0AC259B55D1345D8ULL, 0x962921D50EA5F293ULL, 0x86CE5F93F7A8F4ECULL, 0xC3E0F3ADD86A4ADDULL, 
            0x4ADF588AF7640C6AULL, 0xF6A96298EFB18843ULL, 0x4E7F8338DC1D0730ULL, 0x27222314713EFBF7ULL, 
            0x900CB45AC801D179ULL, 0x57E07760C5C2EEABULL, 0xDE5B66C7D971CD0AULL, 0xF87E3AE1AFD058FDULL, 
            0x123B05723DBEFD8DULL, 0x1A6BB75A5DBEBD43ULL, 0x4F2D449DF8679D59ULL, 0x5C3D7AA0F59EA399ULL, 
            0x0D06B0B827B3C8D0ULL, 0xFB430A8896679094ULL, 0x4564D34B0D097E64ULL, 0x1890CA0BA3FFB92EULL
        },
        {
            0xB4844F59149F0FECULL, 0x433F951AE83E0D73ULL, 0x6B8CB82AC8B1C74FULL, 0x7461532CACC9DC95ULL, 
            0x1554D94AF63DF87BULL, 0x51B81E550EF09EDEULL, 0x3E478ACDC36E2D1BULL, 0x424169611B51FB10ULL, 
            0x7D50E4345A814AB3ULL, 0x1E5B71ECE70D82D4ULL, 0x62995F7211EA85ACULL, 0x695607603A961997ULL, 
            0x25A72416629DC54CULL, 0x2B1D62E50978CA44ULL, 0x8D9D4B81C47CBE75ULL, 0x3B9C7B73082E0DC3ULL, 
            0xD49E4950A76365B0ULL, 0x1E303C7E519C5F4FULL, 0x61B3FD03C1A83251ULL, 0x8E6A462201F9F81EULL, 
            0x4B8610D40B3CEB1BULL, 0xEB6B0C574595AEE3ULL, 0xD43B7A662DE17CEFULL, 0x211E6DB8BB752D90ULL, 
            0x0D1F0B9C0D5EED4BULL, 0x83659D428998ED88ULL, 0x4750503ECA008382ULL, 0xC44F5466879B2E8FULL, 
            0x01FD0B65AE04CB89ULL, 0x8DC079C0CCA0C516ULL, 0x49FB6B2EA54690CFULL, 0x580ECCDF32FD0B56ULL
        },
        {
            0x9B35AFC9DDCDA16BULL, 0xA96ADA7605227D4DULL, 0x08FA5870AA806005ULL, 0xE95962FF7748DFF4ULL, 
            0xAE90DE19A5E1B31AULL, 0x1F2383B89FF468EAULL, 0xA6C6C79337549BDDULL, 0x53DC40F2ADBE4D06ULL, 
            0x28153480E660D66CULL, 0xA184585B8A7AF38CULL, 0x83E521FA1AF81A35ULL, 0x0813E8B397C9CDEEULL, 
            0x66EE79A710D8E8E9ULL, 0x7CAC2B26EBF140F1ULL, 0x93927D515F7FE66DULL, 0xE69C1F23692E1B13ULL, 
            0xE179A5345F2FB24EULL, 0x24D076686751C8FDULL, 0x6121719E95B15DBDULL, 0x450D8B2772DBED9BULL, 
            0xDD508DF647833647ULL, 0xE0B0639802864A27ULL, 0x767BC524BB4D5C60ULL, 0xB44F4578F9754098ULL, 
            0x0741DCA6B4727085ULL, 0xE04909EEF1D0B3BAULL, 0xCDEBB09D3B9F3F46ULL, 0xF2941AD47B4D2736ULL, 
            0xE8C62619D05CF175ULL, 0xC4EBA59C86BB4B27ULL, 0xFDE54235EF9ECB95ULL, 0xFD10AFF73F3B047AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseCConstants = {
    0x14B63A1E66DFD243ULL,
    0x532440713841884FULL,
    0x65B0908191E187A7ULL,
    0x14B63A1E66DFD243ULL,
    0x532440713841884FULL,
    0x65B0908191E187A7ULL,
    0x671370172CA7F2A8ULL,
    0xA24D0D0F8A2B500EULL,
    0x0C,
    0x3C,
    0x17,
    0xEF,
    0x2E,
    0x09,
    0x7F,
    0x1E
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseDSalts = {
    {
        {
            0xA35A3693157FA5B5ULL, 0x40738FC90C882083ULL, 0x75BADA88EDC1345BULL, 0x8F4CC8449D9E377AULL, 
            0x82454C833906AA8FULL, 0x89AE58C86BF9527FULL, 0x492AEC55CD02DCBDULL, 0xB6B2C62241651EAAULL, 
            0xB7DB69CB560BFFD7ULL, 0x2B4765FD32985CFEULL, 0xB9D3A1CDEE20A595ULL, 0xACAB58F72EEA8F87ULL, 
            0x835419D273F6EA7FULL, 0xCBF2255715B55B9BULL, 0x79E4926E5B3045E5ULL, 0x139C2E1ABBCBD617ULL, 
            0xE7B15564952786C1ULL, 0x0754B7930B87DBBCULL, 0xBAB75010C78FEF63ULL, 0x46C13ADD269DEDB8ULL, 
            0x4E3E727869B4FE06ULL, 0x6D46C37F5BA9AA8EULL, 0x46BAA325DEE7E4ACULL, 0x37D0371C43746F26ULL, 
            0x21D45C4DE8B4EB69ULL, 0x965991668D7CECD4ULL, 0x4FE3829048BFEF82ULL, 0xE68833551413A57DULL, 
            0x6C82C63C10004857ULL, 0x903739E31AFE72AFULL, 0x9ACCFE49054CE9D5ULL, 0xE4232E3239542D4EULL
        },
        {
            0xDE99793540520572ULL, 0x252062DEFE8253B2ULL, 0x03EEB35100006DE0ULL, 0x522D4D5E673E44E3ULL, 
            0x43C1083FD34C969FULL, 0x9C51F90263C9B1BDULL, 0xE3442EABDF7A5D45ULL, 0x7A6F3E13CE5A0689ULL, 
            0x7A77B7A849B3620DULL, 0x4206C2A05DE956D1ULL, 0x22F651A261CB3579ULL, 0x945E22AECBCECF0CULL, 
            0x754728D80A42050DULL, 0xA9815052E622C896ULL, 0x2031679797ED1228ULL, 0xA2FF13AC46D4AB91ULL, 
            0x3A7C7F5A012EB124ULL, 0x4468AFF22556A38BULL, 0xA4AA9A607A5A75B3ULL, 0x6D4869448FF1A7B8ULL, 
            0xE880970DF6D16EFEULL, 0x164112B2ABD245BCULL, 0xAAA3AD97ADA25FAEULL, 0xE1833D897F3D6FBFULL, 
            0xA68022B9C5BFA4B3ULL, 0x717A3D455425E00DULL, 0xE08CDE9948EE40ECULL, 0xD3B0452DC5861A33ULL, 
            0x10EC7F70EEEA6347ULL, 0xAA1AE980AB6FF115ULL, 0xE7FAE4DC30ED418CULL, 0x08F071596D959F4DULL
        },
        {
            0xD19C821DE933AF98ULL, 0xCC7DCCC559911133ULL, 0x7FE878471C14780EULL, 0x6B401AF3B4249ED4ULL, 
            0x69FB406FAB75F32DULL, 0x4DF48FAFBDCE22DCULL, 0xEA5195F48EF260CAULL, 0x41270F34CBC2A05FULL, 
            0x3FEF0F7359C72DCDULL, 0x965823AE60E38A57ULL, 0x4CD78A6F3D3ED196ULL, 0xEA960F4E46A3CD3CULL, 
            0xBA2A0EBA6F74EA4EULL, 0x2CB09367E0DE45BDULL, 0xA26756A384B16BEBULL, 0x610F6D61E47781CEULL, 
            0xA47882C7A14394FDULL, 0x9C6268320DE6E53FULL, 0x0F999B691A8C82F6ULL, 0x20651CB710B01F90ULL, 
            0x9754A7E694C65783ULL, 0x6DB018073DF061D8ULL, 0x667FFE4631FF156BULL, 0xCA8EBFA08ECE504CULL, 
            0xDD20A53452C4798CULL, 0x58394B3F981948C2ULL, 0x104D789D1D7FD8BBULL, 0xE724E626E5DFA312ULL, 
            0x356C487FC15241BCULL, 0x6286DE98EE451A5AULL, 0x1FE6E27D5E0AA18AULL, 0x4D3572F6EB0158DEULL
        },
        {
            0xBB5FB348CCCC1300ULL, 0x6A0C0BBD009BC5FBULL, 0x5D8D70BBC81D40F6ULL, 0x0A6FF895E2B64162ULL, 
            0xB093980737F89B65ULL, 0xF4989959B16D20EBULL, 0xDA10F2CE998FCBB2ULL, 0xAD5A55B1777CFE3EULL, 
            0x9C6A4176686D79D2ULL, 0xDFF648EF8A5EE4DEULL, 0xF9EA38A09077DB60ULL, 0xAA0A1C283F5B408AULL, 
            0xF3688DF2FB295C77ULL, 0x13121B2F99690EAEULL, 0x2CDABDDF8F2A304AULL, 0x81DE1AC6994F26AFULL, 
            0x2078A7A5CCA0E16BULL, 0x75AD19DCFABB4AA4ULL, 0xF1E85FE0471F56DBULL, 0x1198F339FD61D81EULL, 
            0x90C81BBE68532D71ULL, 0x5086067D72C8E187ULL, 0xFC5CCC31D55AAC1CULL, 0xB9AFDA2830DFCC1FULL, 
            0x29CF0797F55D73B8ULL, 0x6CD7440170B74C2FULL, 0x3187010C0A49339DULL, 0x7FF9AE932038359DULL, 
            0x75FA91E02006B5EAULL, 0x065481EC83D1FCFBULL, 0x3194EDA2C4BFB0F0ULL, 0x933545F0FAA005F3ULL
        },
        {
            0xDD87318E76F1D173ULL, 0x6077BEAD875534F9ULL, 0x7FC4D1C8F5335F2BULL, 0x9BC2C8D9395D2A6BULL, 
            0x1866381E4EF8F606ULL, 0x7BD4492B133AAEDCULL, 0xF53F8DBE9304E8D6ULL, 0xA6D072E6C922B12DULL, 
            0xE49F4BC1902B50E8ULL, 0x91CE920AF8877006ULL, 0x6C2A831A727E4C87ULL, 0x99D9515673CCC8CBULL, 
            0x4CD05DD0DA024605ULL, 0x28575C92BC02F33EULL, 0x59BF33841E59318EULL, 0x5F11608C1D81D5B2ULL, 
            0x48598B26867BA6F0ULL, 0x9C5F465D7F2447E5ULL, 0x6684D8E2A5C846E8ULL, 0x3B0655B7EEEBE21FULL, 
            0x1FF92741816E173EULL, 0xF3D27CC97B27D194ULL, 0x2886B5E7CF3FE9BBULL, 0x383EC60987CC82CBULL, 
            0x35D917BEEE853BB8ULL, 0x6022D07BC8558411ULL, 0xA0C27E379C07CC7CULL, 0xC8EB490602DF840DULL, 
            0x84439E4839775BF8ULL, 0x1E3D2FA1AA65A51FULL, 0x3190DD1460DAA9B4ULL, 0x945B953E15F8F493ULL
        },
        {
            0xD250630C2F33145DULL, 0x6986A7A2D1E02B5DULL, 0xC756B993DFC36354ULL, 0xADF0E90573D1D5FCULL, 
            0x607D54713219D1FBULL, 0x1AD7D4280E891CD5ULL, 0x28EAF912314CD9F9ULL, 0x410A150BB4F61F92ULL, 
            0xFD15F5CFFFBD53B4ULL, 0x27D531F499C80735ULL, 0x799795737562C3CAULL, 0x569AEC0505B09248ULL, 
            0x88BC66ACD57968C5ULL, 0xCE9555F31BB0726AULL, 0x3DDE4D9842FC9AC1ULL, 0xC98A898F13B05BFAULL, 
            0x4F610FCC61F1888DULL, 0xC29E8C683F5EE329ULL, 0xCD22E48456CE78F7ULL, 0x98DE4F4DD0E7EF9CULL, 
            0xADA16615B389D083ULL, 0x67A0DA9B8E5014C3ULL, 0x149FFE61FD89BA31ULL, 0x01AD5326BF8B12DEULL, 
            0x98FB6C53FCC93E30ULL, 0xBA8DE9F8E1E9F345ULL, 0xF9C5EA3B86AD7F10ULL, 0x44E04D3CC2643ECCULL, 
            0xFA4AF80606896C12ULL, 0x4063EABDD54D5E2CULL, 0x169D03ECC1FFB626ULL, 0xE319C01141C09EB4ULL
        }
    },
    {
        {
            0x2D2EA5A1983DA72DULL, 0xAE9E71BD156205ADULL, 0x9D5323FE8E873F4BULL, 0x81A32FFC61DD1E5CULL, 
            0xC29A54113D9367D6ULL, 0xB77350B0BBE1865FULL, 0xB514A9C67A6A22BBULL, 0x3B99BC237E864F95ULL, 
            0x24967D792C86756BULL, 0x8FEA0BD84D85AECEULL, 0x9BC316A69E61E1C9ULL, 0x6E23B082DAC08DCBULL, 
            0xEB9B3352C427B303ULL, 0xA83BA913684A6267ULL, 0xC3D1FC500D09A3B8ULL, 0x17D972B728AC274DULL, 
            0xB971EB2E3D7A6D59ULL, 0x768407B9F6C0D46FULL, 0x25E57A0D66A07801ULL, 0x6B5FBFE71D653085ULL, 
            0x94284130DB683342ULL, 0x93ADD0BAB6CC97F6ULL, 0x24403809099FCF42ULL, 0x987244C2EB55E81CULL, 
            0xFE7E076C6B59428BULL, 0xD211EE77F2C8C108ULL, 0x408AF97552C8AC88ULL, 0x06FE43498E221AFDULL, 
            0x9170267F4C4DD6A8ULL, 0x74464B3F86209986ULL, 0x01EED59AC3705118ULL, 0xF27640C668807E12ULL
        },
        {
            0x2F6FAF9EA1AD4243ULL, 0xAB12664EA08F8F48ULL, 0x0004E8898F0AA375ULL, 0x9C168CC0749B4FFEULL, 
            0x91ABB372E8162FD9ULL, 0xD959444281CBB9DDULL, 0xB64EA9C87403129AULL, 0x9D504B1D3BEEF000ULL, 
            0xFD66CDEA9409D827ULL, 0x8467660C3375380AULL, 0xCB3F75548C7D3B59ULL, 0x90E4D8D1DA491E34ULL, 
            0x5B9C108584E92BF9ULL, 0x9D21B02C1BA7EC7EULL, 0x4AF435F58A0DDEFBULL, 0x1D2CE95C948CF666ULL, 
            0x6A3114D2E8B0090DULL, 0x3ABD6AD335C91DD9ULL, 0x322026E6E5C0DB08ULL, 0xDA29FF788F2D79D9ULL, 
            0xB828321C22DAB4C5ULL, 0xB705C70BC10907EBULL, 0x982A434F7295B61AULL, 0xB3B1D1C8C8A99EEFULL, 
            0x570A2962DCB2C235ULL, 0x1780440DAF9BCB6DULL, 0xD7DC9B9F4FC96E1BULL, 0xF6555969D9613E90ULL, 
            0x574CC723083BD625ULL, 0x9FFB064FCC96B084ULL, 0x706F0DD84429A6C6ULL, 0x13D0506787A4CE6EULL
        },
        {
            0x2865F06C742B2892ULL, 0x0FED5067902B17EAULL, 0x0706FB8055293CBFULL, 0xA90A50B15FF7E2F2ULL, 
            0x4565991201A9C289ULL, 0x9FE25E9B4EE61041ULL, 0xDF43AAF9BE9FAD8FULL, 0x7AFE9B7B444F9D23ULL, 
            0xA3D3AAC82EECEAEBULL, 0xEFA6C00B349B99BDULL, 0x75AA2FB34573D7EBULL, 0x9DB5DF97D3BD4EC8ULL, 
            0x0743130DEFA7136CULL, 0x73B9FA3631B94952ULL, 0x47AB6242EE727C76ULL, 0x7805EA4CCCB736E2ULL, 
            0x88ADE4B0202EB31AULL, 0xBC41B089622DB235ULL, 0x68BBEBA0B08A2CB4ULL, 0xC975456CAD8D0080ULL, 
            0x1815742551F11A4EULL, 0x4A3D7B386DEB4BD1ULL, 0xE979B23A80E2A96FULL, 0x15315D44BC6F11E3ULL, 
            0x616BDCAEDB2318FFULL, 0x2C8044CE6C07B616ULL, 0xD01C8BF67DD1C4A0ULL, 0x8C3C76081DCD9BCBULL, 
            0xF52467584C7605E2ULL, 0x466F6AAD62A66A68ULL, 0x9EBA4CB126DE3C65ULL, 0x3398C38AED791C86ULL
        },
        {
            0xA20BC004D93990DFULL, 0x4E770E4C7609A51DULL, 0x13963BE44118D517ULL, 0x2D63B22032052E76ULL, 
            0xE33D1AB0D622FB78ULL, 0x4A81108BDA127D13ULL, 0x57573FF16D275F76ULL, 0xCF3676AAFABC17F1ULL, 
            0xFA6D06DC1302C8AEULL, 0x937F59B585FCDB72ULL, 0x944F71F32B6107CAULL, 0xBFD4B427CCACC9EDULL, 
            0x7021FA52F434458CULL, 0x1789B93619A7B8AAULL, 0xE8B4FC113E0D4E0DULL, 0xE25D7583B66D4290ULL, 
            0xDF5C2ECC196F4E21ULL, 0xBC1D838D256DB8F3ULL, 0xF152FB7C938B29D3ULL, 0x16CA33B869662ED3ULL, 
            0x4B75EFEFA02C4F79ULL, 0x31C140AFEB0DF446ULL, 0x47E47FE167987B23ULL, 0x831062F992195C61ULL, 
            0x4AE888CCF253B3EAULL, 0xF2EB77C05891B8EAULL, 0x5484EE72B688D4C3ULL, 0xB91713AC80128A11ULL, 
            0xEF64224600E2B94AULL, 0xB925D997DE1D510AULL, 0x595AB1495112DBBFULL, 0x40069DB62E49528FULL
        },
        {
            0x0CB586C99C9DC248ULL, 0x05D887BBAD8BD053ULL, 0xAA5D4ED930CEC580ULL, 0x3576A60F02EA00DFULL, 
            0xE318443E5A755C6DULL, 0x986C4A9FE51D3720ULL, 0x61695CB5CF65B4B8ULL, 0x300FB52528F54F1CULL, 
            0x4CCBB4BA03401E9FULL, 0xD161DBC92E5EC191ULL, 0x362E2865C082A81AULL, 0xDE0688E5A053BB26ULL, 
            0x7C5AD77A95A9DF74ULL, 0xAA9B208A56AD20E3ULL, 0x2555FB496D4796F6ULL, 0xB9CEFC62BFD5A833ULL, 
            0x4A8F419B0E1822DCULL, 0x5666922D0020D95CULL, 0x96D0BFC8DB458734ULL, 0x8819CDFF33DCFBC3ULL, 
            0xBC3694405686E9EFULL, 0xDB14F2504A5737AFULL, 0x25427BFD029F7879ULL, 0x00B353DF1E47DA9BULL, 
            0x0B24D1FF63502619ULL, 0x42BCAF2C27F4ACFEULL, 0x21A195A05F00D494ULL, 0x5DD6CB67D5AE5D18ULL, 
            0xD3DDCCCDB5DBF271ULL, 0x4A78DAFC40535359ULL, 0x34E22D0DA2C206F8ULL, 0x4BA11DA7F449B489ULL
        },
        {
            0x2D37F0209B1DB908ULL, 0x343F59E9EE053B76ULL, 0x58B9CE59B7AE9A9BULL, 0xBCF9D41CBFC13FECULL, 
            0x38DC39E76C33BFBDULL, 0x1BF1856EE927DF84ULL, 0x6447E316D03496F0ULL, 0x5461F1405691B3E6ULL, 
            0x1CA4EEAAB036CFC9ULL, 0xF4B3CCD214C37737ULL, 0x550C889ADE1C6E8DULL, 0x618C687D8E8AC93EULL, 
            0x85305A7BE7BA61E5ULL, 0x444379C640D562B1ULL, 0x2B688ED3AA7F7A08ULL, 0xCA80591C8DB0F8ACULL, 
            0xD0CE86F866BF2CB4ULL, 0x9FF03F0E529B0315ULL, 0x3925FB933263716AULL, 0x4D7AA6572B448472ULL, 
            0x39C38B0FAA2D47C0ULL, 0x37D431908748A1DCULL, 0x152887DD6CF63E7BULL, 0x60B0C3289D5A5034ULL, 
            0x36C5F982614094DEULL, 0x9A336C89220CE917ULL, 0xA3D98ED907F5C443ULL, 0xD75B20C8B9A37167ULL, 
            0xE25AF682FBFE0B92ULL, 0x40F9B37ABA633822ULL, 0xEE531BC917BDFDAEULL, 0x9C5A33EBAF20E858ULL
        }
    },
    {
        {
            0x6918EE6F25862193ULL, 0xED389E1F0D1E9A6AULL, 0x63D9EF07D4F534F7ULL, 0xB2FDD11A8861AB52ULL, 
            0x1670FF2A6E7CB6EAULL, 0x8C47CA1F720F4FA1ULL, 0xF26A6F912F3BEB6DULL, 0x99A041875A677DEEULL, 
            0x16ED5DE70341A6A5ULL, 0x48A167163F8FF5F6ULL, 0xBE4171ED0E7459B2ULL, 0xE902854D1FAD4132ULL, 
            0x437CFB4F2BEE7330ULL, 0xD3B7FA504346CAFEULL, 0x3B4BB989DA555966ULL, 0x20BBBD841DAF8EB4ULL, 
            0x80C3EC204F263755ULL, 0xC09DCA2B650AF905ULL, 0xC81589D61772B463ULL, 0xBC7440BB72CBE305ULL, 
            0x68CC2B2ACE5FBA48ULL, 0x402F9235A078780DULL, 0xCC7A12A51B9A6A1AULL, 0x25C78FCF42FB7744ULL, 
            0x7F6EE7BD1B80522EULL, 0x578AD7B0BDC0FA0FULL, 0x2C919FBB6399C79AULL, 0xA72BC09C287C5935ULL, 
            0x2F84345BBBE7711EULL, 0x1FCB8B3CCB3EDE5CULL, 0xAC5803EE7C093A0AULL, 0xCE672ACD5C8A3F4EULL
        },
        {
            0x94A0835327BC6DF2ULL, 0xB10D7E0A1905EF8AULL, 0x7DFF65A4CEC9630AULL, 0xAD4EE8E8879C91AEULL, 
            0x779C6F62F0893702ULL, 0xB568EF8E568D6B62ULL, 0xF7A15CE29803A9F9ULL, 0xFE4079AA09C6F696ULL, 
            0x33B6AE1F21846613ULL, 0xDECBE219845A7DDEULL, 0x2FD5A66E7ED87454ULL, 0x4A804995F7C4C38FULL, 
            0x7609C6BAEECA1762ULL, 0xB19F318A9B14E285ULL, 0xCAF5837D59A050EBULL, 0x33C009FBB6E6AC96ULL, 
            0x777384F28CF248F5ULL, 0x18C146C1180FA6BEULL, 0x055939F469C1F2E2ULL, 0x81992FB0BB1770EAULL, 
            0x7F6A6E9B64EFD469ULL, 0xC3BFC03125717314ULL, 0x8F0B56482399253BULL, 0x2DFA15FEB440E0AFULL, 
            0x965601AA52CCBC2AULL, 0xB2F1E85A1E22FE14ULL, 0x47BE724AF52453C4ULL, 0x9CF3D8DBC7E1309BULL, 
            0x908DA485BAFCDD1FULL, 0x80E8AB7FA1CFB36AULL, 0xADF5A80E211A7FF3ULL, 0x53C5136E8C089A07ULL
        },
        {
            0x217ACCF69B2DA829ULL, 0x169D21C7DD54ACBAULL, 0x3419D1AFD9167F2AULL, 0x80905925752FD8AAULL, 
            0x49128B4612E32618ULL, 0xE05CEE3D16E086A7ULL, 0x483B8175B2755589ULL, 0xAC28B5CEBC7C561BULL, 
            0x0292BE91574EB154ULL, 0x92EF37F7A5E18E43ULL, 0x0BAB894383BC150EULL, 0x2313015CAA11C41AULL, 
            0x48D46B141370C572ULL, 0x1D83C2EC33CC5A6DULL, 0x3236271FD20327FAULL, 0x76982BF7A6E7F74CULL, 
            0xE23E7FE7D1C479C7ULL, 0x7BF2B26FF89CC1AAULL, 0x06B6564B3DD4F263ULL, 0x8C5EA866B0CDF1E2ULL, 
            0xF7D62A41DDD7F006ULL, 0x79012C276D19CDC1ULL, 0x36DAC18DE4B5EF81ULL, 0xACE0DBA89CD3AFACULL, 
            0x2B029200E6C36968ULL, 0x03B6900861D7EFB3ULL, 0xBD97289C0F2418B8ULL, 0xAF42E1B399101FACULL, 
            0x7B09E05407DA16A3ULL, 0x39FA969247003742ULL, 0x283CD52D6B3FC9B8ULL, 0xC2A431B0A280967FULL
        },
        {
            0x007DDD01147E5DE1ULL, 0x321F7E2F184003B7ULL, 0x8CC33C21B9522396ULL, 0xA905ED59B6A733C0ULL, 
            0xF336839147D791D0ULL, 0xC7A5D929A23E5D1FULL, 0x1F627BF4A2556099ULL, 0x1E63471867CE4ACDULL, 
            0xDF1AF04D77508026ULL, 0xDBF0A7593D0459D8ULL, 0xB20EE5E0424EAD58ULL, 0xA140D07282C3FE79ULL, 
            0x2C999674BFB97BEDULL, 0x36116A65FE01A645ULL, 0x0BF6F8154C1B67CBULL, 0xE2A38ECB75F4299AULL, 
            0xDC9621011D77120EULL, 0x950EB69A03CA678DULL, 0x398977C8DD7D33D4ULL, 0x27EAB8689331B76CULL, 
            0x6A289781E3B3C0A5ULL, 0x28603BD369375587ULL, 0xE599BAA87C3DB332ULL, 0x0E945DA128E266C3ULL, 
            0x41D957B4F9A7AC52ULL, 0x8F3C06A94C752CFCULL, 0xC5A3602854D3D2BEULL, 0x37CA72042C6D069DULL, 
            0xA7B1BB12DB641247ULL, 0xC2224C4F8A32E885ULL, 0x0CC902F3ECE16BCAULL, 0x6E7F12D5675B04B9ULL
        },
        {
            0x106FDA4AACF2B8CBULL, 0x6739B534E3EFF4BCULL, 0xBD2E1AE5D5C2E49BULL, 0x0FF139FA44DD2676ULL, 
            0x034CACF309E34F54ULL, 0xDC087B837625F48CULL, 0x15CDAE8CC8FFACB7ULL, 0x7A5D768048D37F09ULL, 
            0x5FE751D1ED92C719ULL, 0x90F79EEDABBD9CB4ULL, 0x157B789899A23178ULL, 0xFADBBAA1D1D3A233ULL, 
            0x27365F8400AB8F33ULL, 0xE4DC14334A3CF838ULL, 0x47AE7076C11A1EEEULL, 0x76AA4E46EA54F89AULL, 
            0xD05FA3C117D1EBA1ULL, 0xD023CC6246329635ULL, 0x689F16FBA76AD5BFULL, 0x2A35AA464CD06671ULL, 
            0x7B90FC03168D273FULL, 0x304090D4324C9194ULL, 0x3B83DF2F853B989FULL, 0xCA7A2AC56527BFDEULL, 
            0x746361802FBA11E9ULL, 0xDA5859D1211287B4ULL, 0xC63E303742F38DAFULL, 0x893AE9D9D9A9EE82ULL, 
            0xD1D272AF1BF6C407ULL, 0x24E4B7894DFA446EULL, 0x877532C1921A5EBBULL, 0xADD3EF092F30CC6FULL
        },
        {
            0xE51C33342939D50AULL, 0x4FFEAB298D9CB4D4ULL, 0x1DB9563558FA0F4AULL, 0xECACF105909CE0BAULL, 
            0x98834FEB11436642ULL, 0x997B2CEB813059B8ULL, 0xF86EA03C27FB93A9ULL, 0xA492FFC8FEF694C9ULL, 
            0x16C27556675BCC28ULL, 0x870C49AFDD1AC18BULL, 0xC1C673F12F54F1D5ULL, 0x24F946ECCCA03E87ULL, 
            0xF4A20C837B6506E2ULL, 0xD7DC1B3D41DA1DB1ULL, 0x87BA3CCD4ECAA9EFULL, 0x6E4410A6E423A80AULL, 
            0xAAC8D55CB1F004F3ULL, 0x534B667EB486E99DULL, 0x27F945CB3BB05FA7ULL, 0xC8F4B63824698FCDULL, 
            0x5E7497A367FCE272ULL, 0x3C6E7A5B5B9F36ACULL, 0x4F11EBF0AB5D70C1ULL, 0xC80354BE717A2C2DULL, 
            0xEDB46D387D78BC74ULL, 0x2A8EA0C586088CF8ULL, 0x8A95845C55FBF899ULL, 0xFD3734A5BE909308ULL, 
            0x7F5D82464C3A1CA5ULL, 0xC94D08A3D87FB904ULL, 0x92FAD0A68CF2006DULL, 0x278DC2F728A4D2DEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseDConstants = {
    0xF74FC1247C8F1467ULL,
    0xCA2F74B9E19CAB98ULL,
    0xD12EC38A419A219AULL,
    0xF74FC1247C8F1467ULL,
    0xCA2F74B9E19CAB98ULL,
    0xD12EC38A419A219AULL,
    0x37D9A202C021DA79ULL,
    0xB9AFD9098B521B1CULL,
    0x23,
    0x84,
    0x8F,
    0x4A,
    0xE2,
    0xB8,
    0x32,
    0x95
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseESalts = {
    {
        {
            0x2D8C7DA27B31B2C7ULL, 0x5516099EDD02A45FULL, 0xF203AD6E81C7A83BULL, 0x8AB4F75811ACFA4FULL, 
            0xC722E63C132F8A36ULL, 0xAD67DE332E016C99ULL, 0xDDC0DFEDBE6F2016ULL, 0x167549C5C76A5097ULL, 
            0x2CB2723CA18AE411ULL, 0x2C2B180253CF12D0ULL, 0xEAB3475AB4422256ULL, 0xC8CA909DCA53DFA7ULL, 
            0x44BEB8FF29BE96ECULL, 0xA9F3C6BDCE155E53ULL, 0xE6C89BAB231B6F36ULL, 0x1D6B65DF7390F511ULL, 
            0x362B2B59191325C4ULL, 0x3DC847599A78EF01ULL, 0x92CE7F2F04261F0EULL, 0xBBEC6399510E21BAULL, 
            0x913FA95125B7E31BULL, 0x32EA5B86FFA667ACULL, 0xD61C0F3EE1806DCAULL, 0xD5B701E4969E0E52ULL, 
            0x4EC73FF80ABBD89DULL, 0xF2E65CC6E1B91486ULL, 0x88F5943876A03208ULL, 0x541BB2C71024EA7AULL, 
            0xBED6F6E72AF2DC6AULL, 0xC60FC863B99FA3E3ULL, 0x794797F295B667F8ULL, 0x993EBC7F31042174ULL
        },
        {
            0xB9F5FBBB3EC930F5ULL, 0xA06DD81F7984A01CULL, 0xB7188BE3C0B3CF90ULL, 0xCF526247536107B8ULL, 
            0x73C1577313777CD2ULL, 0xBAB1AD1D44B3430EULL, 0xE14C3E5F118FC23CULL, 0x68826B206DCEF474ULL, 
            0xC0F0794A14DA9AA3ULL, 0x19F8BD3A202E3765ULL, 0x19E1E40779EA8780ULL, 0x064DAD4FF956E21BULL, 
            0x7D234566565C5F08ULL, 0x98DA4375421B5297ULL, 0xD99706BC58E0AE11ULL, 0x1527FAFB0217E372ULL, 
            0x1148FFFF052496EAULL, 0x86AA14EA3528FB32ULL, 0xC20C9E9E371CBED3ULL, 0x0D76DC7F88D5DF52ULL, 
            0x6180930B901638B6ULL, 0x789CDE16D34684EBULL, 0xDF6B54FAD0DE9447ULL, 0x620F5928F994BA3DULL, 
            0xED058DCEAF57751CULL, 0x752F31A3F4B8A50FULL, 0x7F4C541AD2C5527DULL, 0x995038600BBB3CA6ULL, 
            0x16742CA1382AAB6BULL, 0xFAFA5F32E17149CAULL, 0x4D228280C33804F9ULL, 0x7342C6692476B82CULL
        },
        {
            0xEFC47F0E70649B3CULL, 0x2E0FF4616D92DF84ULL, 0xDF8C3F64DE074059ULL, 0xACD4B748E6FF6614ULL, 
            0x4F7745F1C6C42787ULL, 0x2C26E1CC00B4CF7EULL, 0x01699ED08D1CD17BULL, 0xA5808A8B585E7977ULL, 
            0x243E989BB56C0B33ULL, 0x460629DF365B9B74ULL, 0xDDAB712C75D36EBBULL, 0x55676E3D6A3EF1C2ULL, 
            0xDC280AAC4F0DDB58ULL, 0x961F349D1AAFA676ULL, 0x5F7E0AC2921CF2CEULL, 0xC91E3CC48C46FB36ULL, 
            0x9204D85EBA1ED35AULL, 0xAA429AFFF25EFC7AULL, 0xF6D72D3F581C8B26ULL, 0xE695DABC43EF56A6ULL, 
            0xB71A23E48FD8DF13ULL, 0x08DF180057D5A7D1ULL, 0xED80CE826DE1DCE1ULL, 0x3C57D97F2AB61063ULL, 
            0xA4C35E6414C17473ULL, 0x5325FF9DB8CADAC7ULL, 0x432B11A22CC0E47FULL, 0x72545616973673ACULL, 
            0x84A580B9CB988FB6ULL, 0xF99170C9BA6C044CULL, 0x12EE09A87ACC0D45ULL, 0x78A1C263F1C07789ULL
        },
        {
            0x9BFDF09E31D8464FULL, 0xBF70A77036C52A45ULL, 0x4175231AAE787E68ULL, 0x9F84A7CB7EB281D1ULL, 
            0x00692021EB260079ULL, 0x279B8FAADD2B9C15ULL, 0x893AB2F4604072CCULL, 0x2C3DFF35AAE60DB2ULL, 
            0xCA7D489974996B86ULL, 0xA7B63044740FB29FULL, 0x72CB77069AA83EEDULL, 0xE067CD81DC313E4CULL, 
            0x91C0F179A01B341FULL, 0x3EEE10502F006440ULL, 0xD86D3E4331E87A3FULL, 0xBAAF74CF010468D1ULL, 
            0xAE03FB39B888CD6EULL, 0x734048D022A549DAULL, 0x80C8DF54DFD60828ULL, 0x40EAE9753ECF2011ULL, 
            0x71FAFDDE5BE3566DULL, 0x682AAD4AB34EBD18ULL, 0xA05FB2AB8C8CFED0ULL, 0x6DEEB4CE6DAD55FEULL, 
            0x45886A76CFC43FF7ULL, 0xE72A232606A97BE1ULL, 0x26A74C3AC1D06D9BULL, 0xC1AE42783EB77EE8ULL, 
            0x9ECBC8233926BFB9ULL, 0x379DDAFF1E71AF70ULL, 0x5792E4838294C07BULL, 0x17E42A0E254A121FULL
        },
        {
            0xB61CAFDE583ED7C0ULL, 0x4D56438FCD0A6A9EULL, 0xAFA2E8BF048602F5ULL, 0x17524E38CBD53145ULL, 
            0x3453530655EA279CULL, 0x98E530B6088C82D0ULL, 0x5A5983C210249B85ULL, 0x6DE0D4AED171089CULL, 
            0x8F1D8AB857E35684ULL, 0x1AA0A494B43D907FULL, 0x26919179FDE9B409ULL, 0x3D775C3B7AA212F6ULL, 
            0x56ECF52887399A6CULL, 0x5E2584CA24321C5FULL, 0x561C159FB7209F09ULL, 0x481B0C6D118B6972ULL, 
            0x5974B048DCED3ED4ULL, 0x44A755F850DA46CDULL, 0x1FAD6BD1F49C89C8ULL, 0x2093FD856E68DDA5ULL, 
            0x5955CAE2D820E520ULL, 0xF2D4D52B3A054408ULL, 0x8418ABC473BD4B7BULL, 0x27EBC04BA105EB19ULL, 
            0x92E1901FABBB42D2ULL, 0xCD2B29A74503A076ULL, 0x796951798A3ECC6BULL, 0x4DA45BDC1209DD5DULL, 
            0xC8BEDD40DB6632B0ULL, 0x795D61DB12F8E81CULL, 0xD59E40FC03E196EBULL, 0x755BDDB343780CB2ULL
        },
        {
            0x3A314803B9B8C230ULL, 0x778513C8B7C893F8ULL, 0x18DF7B82BDC81E8CULL, 0x32F54AE70D6137E2ULL, 
            0xD67E3232CCAD4016ULL, 0x10D17C57F63EB58EULL, 0x0CF72B464F390B69ULL, 0x7DF5E9873961F410ULL, 
            0xAA64B60CA45696E4ULL, 0xE175022DB7701001ULL, 0x85C52C46A061DAF8ULL, 0x7D8F439ACD30C59FULL, 
            0x11F63E906C74A37FULL, 0x6775E6D47E3CE623ULL, 0x9EFDB1B64A402E4AULL, 0xBF07AFD7502A1786ULL, 
            0x20BA52C24DF46B94ULL, 0x75E8FD920F0A654DULL, 0x7AAE09F874EAEAFDULL, 0xA114A8D1E1DE10FFULL, 
            0x9E65502428E46D8EULL, 0x031FFD0EEC3CA7D2ULL, 0x2489C484B48C2B91ULL, 0x53C23FD547F84F37ULL, 
            0x8C5D0F0202BDA3A3ULL, 0x0994B67E42D3E5B0ULL, 0x600CC7FAB8D27678ULL, 0xFE62827DBCDED4DCULL, 
            0xA33C1BB41071D3E7ULL, 0xA81C6483BEDC2F89ULL, 0x7566BAD54D7B8C41ULL, 0x67F7EDDB2491919BULL
        }
    },
    {
        {
            0x63B80709E56210EDULL, 0x5DB84B787529A62EULL, 0x4A5EB59F0034F5E6ULL, 0x11C3C9B1E7F964F6ULL, 
            0x1E87A9D5C6311743ULL, 0x2DFC383018EFD10EULL, 0xFECD859884DD7D29ULL, 0x91818CE011244AFBULL, 
            0x1E6D2C3E4EC2EFD4ULL, 0xAB386F4C81F5FA36ULL, 0x8F492C20C645FD3CULL, 0xEB3E6BC67FD954A9ULL, 
            0x9C8BB25DE67A5544ULL, 0x45F63DE6D361543EULL, 0x84622E7B76CE0A65ULL, 0x48FEBFF7C1C8655EULL, 
            0xC95F415A34017C0AULL, 0xD917C3FBF66431ADULL, 0x7A4BD76954585AE2ULL, 0x3656A65085292AD6ULL, 
            0xC17661E8DDBCFA0AULL, 0xF065F69FCAE0B212ULL, 0xB40D17DDAED61114ULL, 0x16B09F526E71626FULL, 
            0xFBF030DB52275261ULL, 0xF3361D4DA9C2BCB0ULL, 0xF697E92E8268829AULL, 0x4F74CDBAEF9C54BDULL, 
            0x94FC4740821BB97BULL, 0x4EF300BF82C642B1ULL, 0x226787AF223C63F3ULL, 0x902CA01CB0A5E583ULL
        },
        {
            0xB1B82FBB8DBC1413ULL, 0xDDD17AD6FBAD71AFULL, 0xCF9999332B978B59ULL, 0x16F9BE737E62389EULL, 
            0x3A6FA3ED4379157AULL, 0x2E2B0DF8C7B965F5ULL, 0xAA88E326FAA057A3ULL, 0x00B6C0CCD65720CDULL, 
            0xD8000EC6E693962DULL, 0xF9BA019A1E4590FFULL, 0xA4FDC8027C976B09ULL, 0x7425F334AE63C047ULL, 
            0x103C566F1F9A94AFULL, 0x95664A49B80DC8AEULL, 0x183AF18AFA196BECULL, 0x43F98BA1FC80754EULL, 
            0xED5A8A3EEB079A88ULL, 0x715090E1C3A20EF8ULL, 0xC25E10ABB5EE013BULL, 0xFDAFCD416DAFFBAFULL, 
            0xB2D8F3ECCDE09403ULL, 0x63801172A73595D9ULL, 0xB3015E2DC2395ABBULL, 0xF561A720F17426FAULL, 
            0x6CA7185FACD7ADF3ULL, 0x2609AF33B47D1A6EULL, 0xDDD3B3BA5CDDB256ULL, 0xF297E9F25DE4DC8CULL, 
            0x4463B7351D985E2FULL, 0x3AE099A599952617ULL, 0xF318700871775D98ULL, 0x9DAD2467DCFCC73BULL
        },
        {
            0x843A97E9C58A4116ULL, 0x4C21F49CEDBEEFDEULL, 0x7FF19171EEF5FC10ULL, 0x4682CF478CA13D93ULL, 
            0x786EC79CB435AB86ULL, 0xEA9032C82F39E37FULL, 0x72D5273EF2D6567AULL, 0x1E56839EBA2974A5ULL, 
            0xC2213509F987E2E4ULL, 0x4805387F111B6DB7ULL, 0x616FE1ED82DA4356ULL, 0xBB4C49931E6BACA6ULL, 
            0xE6E2EE3EDFD3161BULL, 0x2700D9D65F35B83BULL, 0x3B1AC94BCED521B6ULL, 0x2E838B221D0D6F7BULL, 
            0xFAA0D5BA9AF6FD72ULL, 0x5E86555E4EB1782AULL, 0xD6F92EB6A76D9BF0ULL, 0xA5D55C43B6C81995ULL, 
            0x250DFC058FA275A7ULL, 0x5211CE99CF89AEFFULL, 0x9A87A0CDF17A43CDULL, 0x678362B4624A9FB1ULL, 
            0x658FE10CA96FA76FULL, 0x941A60DC0546181AULL, 0x1E05E9EE5969D96EULL, 0xB976A23DC5AEC9F8ULL, 
            0x6DC364680C71D727ULL, 0xED3A8149D362EC3DULL, 0x4902F98758A5F89CULL, 0x5F2375568E086EBEULL
        },
        {
            0xC83EA6A1F8672229ULL, 0x8DD77D34CE17FEE4ULL, 0xB27E60866A934151ULL, 0x6D990B58DA76A4EFULL, 
            0x1AD7E5151295331BULL, 0x833FCF55841857F1ULL, 0x4B31886D293D95DCULL, 0x31D55A34A9D06A11ULL, 
            0x07754F1D87F3C212ULL, 0x6E1D6CC5BB91057BULL, 0x9C21211B0F5812C8ULL, 0x02E1227C3D5924F5ULL, 
            0xC5F88A8E7621BF0BULL, 0x46A76FE492DDEE6DULL, 0x0C02549BB33D2CEEULL, 0x2E83CA28B3B1D887ULL, 
            0x7049717D5373D3D2ULL, 0xFF402DAD0E3A98B6ULL, 0xE64CB87FCE449CE8ULL, 0x26B8AE0FFC2B1B99ULL, 
            0xA170486F09CAB1E7ULL, 0xD11539C71BF1E053ULL, 0x8DD40D67006AA427ULL, 0x846E104750954D5EULL, 
            0xDA9DB2D476F32DC1ULL, 0x789326B232EC6BBBULL, 0x581F732DAB208C8BULL, 0x3A23D13E89B18F35ULL, 
            0x1CEB9A42697A4D0CULL, 0x6CA218BB66AF506CULL, 0xC5131222372435D2ULL, 0x3EC09C4ACA2347F8ULL
        },
        {
            0xFFF7E5FE0DC5A073ULL, 0x7453CA34616DE6AFULL, 0xE8487BEAD872DA9EULL, 0xB00CEB395CD7E2F4ULL, 
            0x80AE0E3AD87FEF55ULL, 0xF043778F3044BADCULL, 0x5AD6307BE667E9B9ULL, 0xD2B226FE3425BF1AULL, 
            0x6FC6E1B785B8E1C8ULL, 0xD92E7F8798BE2527ULL, 0x72491574B3263171ULL, 0xCA87DE1D692E3DA5ULL, 
            0xE0CE9CE077253F85ULL, 0x46E1CDDE7BA57645ULL, 0xF6B07645821662C3ULL, 0x9C4CC7BB9D6EEB2BULL, 
            0x8F8EC907B235A76CULL, 0xF12E8C32922F7EBBULL, 0x41BC59814E3A8AADULL, 0x4C5F4092E1DD25ECULL, 
            0xF369620EE8005DDFULL, 0xA6155C58889B38C2ULL, 0xC45ECED258AAEE62ULL, 0xDD608B0DE799C902ULL, 
            0xAAA411C0E35EA846ULL, 0xA8712BDA39AADB2BULL, 0x52993618E1AF2028ULL, 0x3E6C7FCDA8E0B56FULL, 
            0x1AB4792EA55075D3ULL, 0x26D1D7B992FB9B4EULL, 0xD5D4649D77B4EF3CULL, 0x4D54CE2B6B86BFA5ULL
        },
        {
            0x84F019AA569C64ECULL, 0x9EF4C82A35F76B2DULL, 0xE96B0EF5567AEA93ULL, 0x964DED84187AB470ULL, 
            0x4E11736B6E30F3FBULL, 0x3069C24580E5EEB8ULL, 0x5BA1988E12FAA2F6ULL, 0x61E65A9B62A6ED4BULL, 
            0xE124E834D6B99075ULL, 0x9F644035DE971EE9ULL, 0x903396F16DF812D3ULL, 0x8E6704C0BCF4903EULL, 
            0xE8011444E3ACDED3ULL, 0x3B9BC2777A5D3C6CULL, 0x2B328E55391AE2F0ULL, 0xE7C1F7AA61E3BB83ULL, 
            0x0C0DC37782248567ULL, 0x7B5BB420673802BFULL, 0x154DCA8F103B3EF4ULL, 0x97C3689C42BCB505ULL, 
            0x455254B2D4E3B708ULL, 0x042432A73F56D2B0ULL, 0x6C3E570CB58A5CFEULL, 0x54AAE3CBA56EAC1AULL, 
            0x55CD50581A3DDFDAULL, 0x1C09674B0412A706ULL, 0xA9CAB7D05F56590CULL, 0x747855A649F6C017ULL, 
            0x92455D0E8D16B8A4ULL, 0xD2E449D0AA3CDF79ULL, 0xADDD08686D20C79AULL, 0x40C425152E4E5949ULL
        }
    },
    {
        {
            0x99857EFA604FDA3CULL, 0x6EB5A3B4308C9FA3ULL, 0xC89A7D69E17B4567ULL, 0x6ABAFA4B07E848FCULL, 
            0x3D64F80D480FC455ULL, 0xAFE8D2DC3158AA57ULL, 0x59E2C6E488943D09ULL, 0xF5B054AA29DECB46ULL, 
            0x8D7D252CAD36E125ULL, 0xEF125FC8A3BF3C7DULL, 0x73CA1304C6F9CA4EULL, 0xC1B816BC26D2F76CULL, 
            0xB0CA1AE9B7DDE63DULL, 0x7569A723C111F2C0ULL, 0xD80FADB8979DA251ULL, 0xDFF6DCEE5D9B1611ULL, 
            0x24063E8755CC02D1ULL, 0x304064D63E1C265FULL, 0x4DC286A16B56A673ULL, 0x37E306B8BD54CFE4ULL, 
            0xC472FE5A5D9685AAULL, 0xE8A81E00ABDA4383ULL, 0x762224496ECD4B25ULL, 0x70BA4D72BC794EF3ULL, 
            0x438E8C67315A8D8BULL, 0xC3DCC9AF9178578BULL, 0x72FC26F62B4BC1C0ULL, 0x1E13F61129D4DEB8ULL, 
            0x171C5496CA7FE35BULL, 0x0926A54E1E227BD6ULL, 0x2B5A5ED1CB4DB6D9ULL, 0x99161DC0FA7A3315ULL
        },
        {
            0xC6057E9A66443BAAULL, 0xBDBBE964ADD863B5ULL, 0xDD03B22FA6873CA5ULL, 0x5099BAFCD6481E33ULL, 
            0x4C3F96B6A4B945FCULL, 0xF214A3E79F377934ULL, 0x7747D667D92E033CULL, 0xFF6121D8C9BA2BCBULL, 
            0xF146905EC115EDE8ULL, 0xE4E54780FC5A6199ULL, 0x5984FCB5ECAE6797ULL, 0x95621AEA931D6AC0ULL, 
            0x78E77BDDAA6F3C92ULL, 0x435AD7744011EC16ULL, 0x7EB82DD58D604304ULL, 0x92EE34035AEB7ACDULL, 
            0x84DDCCDA9F569713ULL, 0x13443E22BB45437FULL, 0x6BF1FEDA8F93ABF3ULL, 0x5A49E8B615CD0D1EULL, 
            0x1E46E08DD620B023ULL, 0x06665231BBAC89E9ULL, 0x7BCC2F97F7862668ULL, 0xD1680AB105C9E65EULL, 
            0x7A77299547B30566ULL, 0x38825A7730EAB67AULL, 0xECACE7C66EF9E99CULL, 0x7A52AE8E11AEEEA8ULL, 
            0x99A7184394086F78ULL, 0xD50A2298481E4473ULL, 0x9A5C0B417228F288ULL, 0xE31947923E2E997CULL
        },
        {
            0x226BB1F24B7F3E6EULL, 0x16A2DBC28428F28CULL, 0x669BFD1817C56725ULL, 0x158CD2517242D24AULL, 
            0x48A1B794C90CF875ULL, 0xBC600803F33E983AULL, 0x976A6D0FBD718A83ULL, 0x689FDF1838D66389ULL, 
            0xF34CB16DB58E5CF4ULL, 0x3918762BA011EFDEULL, 0xA60E053E7856DB61ULL, 0x493C7E740296017EULL, 
            0xB940A21FC24D94E9ULL, 0x2665E7AAA5500336ULL, 0xDD2293B7F1AAFD98ULL, 0x679DA5308B80148AULL, 
            0x3FFFE545483FAD10ULL, 0x8BA5D6B1A5E162EFULL, 0xC0D2DE4C5B5FD32FULL, 0x0215D3A7B510840DULL, 
            0x26F4824E5993E8F2ULL, 0x4B74C0DDDF0F0D7CULL, 0x15FAB727C4B1FA49ULL, 0x2B072B32F545AD4EULL, 
            0xBAF8379BF8EAA4E7ULL, 0xE950BC962FE8C858ULL, 0x129CC755C7A781DFULL, 0xD16DD7D518519A6EULL, 
            0xF4C34E61B3BC4514ULL, 0xF962021B7B9624EAULL, 0xE584BA555A080E5BULL, 0xFE72AE9320063434ULL
        },
        {
            0x979B4113070C3656ULL, 0x7A23DE0BC38EA503ULL, 0x82F30009A5EF3772ULL, 0xA69ECFCA0D42332DULL, 
            0xE3B2190AC0E263EDULL, 0x3024DD9C2D1ED21CULL, 0xDA888B6C1EB697C5ULL, 0x8328C6D5CC07263DULL, 
            0x331E11462A2D27E0ULL, 0xF0350C18D48D3776ULL, 0x21E16D262CDB5EC7ULL, 0x4F7B11BD8BE72EB9ULL, 
            0xD5EF6C59A9308C81ULL, 0xBD468AC350F9C096ULL, 0xB3FA25C150489E19ULL, 0x4C050749B0B62E9DULL, 
            0x51D53B231FFCB529ULL, 0x834E427075600375ULL, 0xC44D3058673E3907ULL, 0x369C994884016D49ULL, 
            0xA5E944181A0C7E00ULL, 0x4DC0E37101BB177BULL, 0x9C59B0112A08BD50ULL, 0xFDA528BAE1B448B3ULL, 
            0x5DF9331A7D7C04A4ULL, 0x3F9AD9B6A945793DULL, 0xC155DB6938920AF1ULL, 0xD5725E91467A58CDULL, 
            0xC0663E6FFEA3FDFCULL, 0xF279104E3E3FF0C3ULL, 0x4D552FEDEA6D7CC8ULL, 0xDF909B23FBE4BF64ULL
        },
        {
            0x6A2A301F371AD412ULL, 0xD7F9E5EC4AB925FDULL, 0x482525FCB2A984F5ULL, 0xE5743CAED79FD6A4ULL, 
            0x2AD17C4E93BAA03AULL, 0xA1D95587BF48E051ULL, 0x667218A3970AA152ULL, 0xFC92503923E8BC6CULL, 
            0x8DFA34EF6C828C76ULL, 0x481D9D212F83B754ULL, 0x4847B4199BEB434AULL, 0xE933BDE205A5CF33ULL, 
            0x23B8DED32FEBEAC0ULL, 0xB2162CC4A21F0F26ULL, 0xD7694325C6F23B14ULL, 0x3CD3FE9EC859C696ULL, 
            0xAB8D1BEDFFFB5A41ULL, 0xF60D4DD8D616870BULL, 0x2FD1B612FE262E0BULL, 0xF67E4267881F7077ULL, 
            0xEEF7A34B20727B2EULL, 0x3930477D5A21829EULL, 0xA4C5818518A28CF2ULL, 0xF24A60FFF782D89FULL, 
            0x470C10CA5C1B9088ULL, 0xC42BD8594A5DFF3DULL, 0x861BDB05A2FBD082ULL, 0x59D8495BCBF994ADULL, 
            0x12652585C58FF355ULL, 0xB8DFA06FFE47EED8ULL, 0xD04316E7BF6D4982ULL, 0x59DA0AF6253C1D77ULL
        },
        {
            0x225E53F5BD3E876EULL, 0xDEBECB778A12381BULL, 0x150827AE1BC356C0ULL, 0x1C0F7FC85878E04CULL, 
            0xB56BACBE49E792BEULL, 0x65F5C75C85EAE3C5ULL, 0x9610492B85B0E676ULL, 0x1304A93D5506DC94ULL, 
            0x4F68F1A2CFEF4882ULL, 0x58CE750418CAB8F0ULL, 0x7E9E70D5DDAE3469ULL, 0xA6DF3B1A03FD56D3ULL, 
            0x622D2B0ED48A46C5ULL, 0xEE481090E7935127ULL, 0xB5A94429F949FBE5ULL, 0x3980C88171D0BF90ULL, 
            0xED3636436F348909ULL, 0xB5F859B6E566A503ULL, 0x7F918F8D30BF0367ULL, 0x3B9F67B66E993CBCULL, 
            0x4D501D4F15D4ADE2ULL, 0x607A09878F439A6EULL, 0xA61B6A5FA108C965ULL, 0x39C89F57D97675A6ULL, 
            0x4DF884B9828D9203ULL, 0x338D94DD490C42D6ULL, 0x05D99D0E4768ED07ULL, 0x1D3A7BC78695DF35ULL, 
            0xEBD7F41641B1B6CDULL, 0x130AB724594F7CD8ULL, 0xC9F8E816E99EDFD8ULL, 0xB728E868F0CE462FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseEConstants = {
    0xF47438FCB21F4A8AULL,
    0x4D551C013AC2974BULL,
    0xCF34DAA3A01C4C7AULL,
    0xF47438FCB21F4A8AULL,
    0x4D551C013AC2974BULL,
    0xCF34DAA3A01C4C7AULL,
    0x90ACE1D181299D06ULL,
    0xBE232E9CBF85CA0DULL,
    0xA2,
    0x28,
    0xC1,
    0x2D,
    0x15,
    0x94,
    0xE4,
    0x72
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseFSalts = {
    {
        {
            0xE978050B7C4C6FA9ULL, 0x447FE7BC1D3B1FBBULL, 0xF3864C6D666F43F8ULL, 0x429675886E125D76ULL, 
            0x72F4CE897921BBE5ULL, 0x41185D3C8CE11C4EULL, 0xBAC3314E0EFE039CULL, 0xA46D9FEB03D06557ULL, 
            0xC0BBECD5A178B790ULL, 0x15581E495D439A15ULL, 0x9F663178F1FB5175ULL, 0x33A546531F57844EULL, 
            0xCF9CBDA4E747EC54ULL, 0x5AFB6F8BED89B486ULL, 0xA1B906C2B67EFAA4ULL, 0x3BB2C09DBA366582ULL, 
            0x8B86999F8DEE83DCULL, 0xFA1D0AAD9537620DULL, 0x60498AF709A2F685ULL, 0xF4C5B451381E90B4ULL, 
            0x789F2F7EEB918B84ULL, 0xFC31C18FE6316A4CULL, 0x238E52FF9A601766ULL, 0x5907228DDDB438BEULL, 
            0x72FA657F38485D65ULL, 0x5C0652435E23DA57ULL, 0xD9FCA7EAA47A2829ULL, 0x951E7205E0155C05ULL, 
            0x8294EE4C19821859ULL, 0x81AFB03CE38C3C24ULL, 0xDD9B13FD3D8BB616ULL, 0x8771650E6E66B7B8ULL
        },
        {
            0x8479709944DBE2E9ULL, 0x6B23F3572DF3F4B7ULL, 0xBA188835F552E6DFULL, 0xA43C5AEAABA028B4ULL, 
            0xA5558E0BE1CC6C2AULL, 0xDF07436B1DEFCFBEULL, 0xD56E56E8E6E8265DULL, 0xF799C880B3A1D06BULL, 
            0x1811B4283631BDABULL, 0x9082A6EF81C2BE5CULL, 0xBA5084BE17EF47B3ULL, 0xCC4434B9A4EBB4C2ULL, 
            0xAD7698F866CF499BULL, 0x0C7138547C1C1353ULL, 0x507BEC5AD03A9D68ULL, 0xC8BB7731456A406EULL, 
            0xDA3AEC267035C673ULL, 0x8C99C2E7A9D43733ULL, 0xEC8FD930AE9D5670ULL, 0x709CB908118C3DF6ULL, 
            0x0BF33EC3A97096B6ULL, 0xB9E9E044E9CD9C50ULL, 0x7C1C277FE7905F31ULL, 0x756EECE1FC6A04B8ULL, 
            0xDAE0901047E16A6FULL, 0xA496454FC14F5670ULL, 0x91F0185CE74990B3ULL, 0x9688FEAC2E83A879ULL, 
            0xD1086FD8358D3D50ULL, 0x29F17002EA27EB77ULL, 0xCD3CE6336D71B871ULL, 0xB6FE7ECC6860DDF3ULL
        },
        {
            0x3878295C8F0EA521ULL, 0x9CC4F14B7A567147ULL, 0x654BFCC47C66E981ULL, 0xB42E6977388077FFULL, 
            0xE2CCEF2ABA3C13EEULL, 0xA115BE3B7E1B74DAULL, 0x06D34E273A9821AFULL, 0x205BB7BBA847D54DULL, 
            0x9E7363FB267946A6ULL, 0xFC4F20408112EDFAULL, 0xF899C6D192462E6BULL, 0x82A4251FA34D8E66ULL, 
            0xEB7EE8ACFC08CBAEULL, 0x1AEA2D1D0F9BC090ULL, 0x366E4C795E16703BULL, 0x4AD8D78ADBE1E7CBULL, 
            0x6D18195D9AA94B68ULL, 0xC373A0DBFA5E6243ULL, 0x21A236C50B195511ULL, 0x977A76D81547D730ULL, 
            0x63147CB0D6412A11ULL, 0x30418C1CDDD20994ULL, 0x0E865A659F431E11ULL, 0x5E8D9F36BDC8B45AULL, 
            0x683C26C7713F5C42ULL, 0xB70F0B56D0D43D2EULL, 0x88302BF53EAFC2BBULL, 0x12CB821357997C3EULL, 
            0x208997913D55D443ULL, 0xCE018550F4C29E19ULL, 0xF18BC27702418FC7ULL, 0x9985CD2C7E839DD9ULL
        },
        {
            0x96470D58C100E180ULL, 0xBADDDFC237D416EFULL, 0xDF0A85E4F62FDA52ULL, 0xF61D6910C12A9B07ULL, 
            0x308B52D2C72D8197ULL, 0xD4013FE32595DBE8ULL, 0x44E489A81E787C97ULL, 0x6EA999EA2959897DULL, 
            0x455BDA4831B6D9ECULL, 0x4552454C97771B42ULL, 0x1DEE2704070C6071ULL, 0xC293272AFBB7BEB2ULL, 
            0xC44CBD58D679C56CULL, 0x1AE7E03E899CD14AULL, 0x2918BC45AE986AFAULL, 0x419212AF0795A4C2ULL, 
            0x55C334C84747F938ULL, 0x64264C6489265371ULL, 0xB17AA1EC1CF49562ULL, 0xD31D1F0708AB97CDULL, 
            0xA19FEE27ACFCE0D3ULL, 0x883F577CF6F368ABULL, 0x97936BF7630E3630ULL, 0xA7C9C3585ABF8C37ULL, 
            0x8413B0337828B49DULL, 0xEECDE9F55FB681C6ULL, 0x601779FB96DDAFC0ULL, 0xB52E745DFD7EDE96ULL, 
            0xA0A4F30CEA0F9F56ULL, 0x9C37F5F63B1B204BULL, 0x325EAB4E907CE173ULL, 0x003DB4533D77316CULL
        },
        {
            0x3168F0A609D47900ULL, 0x36BDDDBD6CB6AC89ULL, 0x348957217A7927B3ULL, 0x6924D7BE69D97158ULL, 
            0x99759A2E5862DC84ULL, 0x300BBABD5B4BE7D2ULL, 0x99368BEE3564E7E4ULL, 0xE4354CDC65B72667ULL, 
            0xF3EE850F2F658CB6ULL, 0x353AD12A4897BA4CULL, 0xAE9BC0573B6F8DE3ULL, 0x453CDEC097BFF0A8ULL, 
            0x6E0B0AAF7A9933FBULL, 0x949FCB39C6A41D08ULL, 0x1AA6D5CBB8DD685DULL, 0x17FAC9D44176680DULL, 
            0xD86DD6CC21340642ULL, 0x26AD762F2160BF92ULL, 0xBB14A0E117B8722AULL, 0x5B3D6A1C378988C6ULL, 
            0x82711E2E5861C36EULL, 0x03C9FCAC8C17F871ULL, 0x6931E36555886579ULL, 0x2BE02D9ADAB1F206ULL, 
            0x903FD8A5A5661A1BULL, 0x93401DCF10FF5ED7ULL, 0x56072726693919ECULL, 0x43181B629180FCC4ULL, 
            0x5312D7F5B851C4A0ULL, 0x41F74E14874FA28EULL, 0x37E8D809DC3DFF13ULL, 0x6B1EE5FFDDD165C6ULL
        },
        {
            0x4039A6EC4D952363ULL, 0x20602DBF16860E7FULL, 0xB50DDF16E673ED8CULL, 0x9254671E951FF3D4ULL, 
            0xA0C6DC2C95A836A3ULL, 0x6653A2283BC6D3EAULL, 0x20603B17C14E0C9FULL, 0x6353F8BC432F1E3CULL, 
            0x5D774A529DCC069BULL, 0x4EE4C883C9A33A9CULL, 0x22E3EB676F732B45ULL, 0x51C769D0245F89ACULL, 
            0xB37CFCB9DB3AB783ULL, 0x11929E097E6DAF86ULL, 0x870E063EC1D29A2FULL, 0x824DDB92B4C1AA53ULL, 
            0x97BA6F4B3C3BD1AEULL, 0x09BF8809FC98275FULL, 0xE7802BA4903D7E10ULL, 0x637A8601198DFB7AULL, 
            0xB69BBA97E029FF5BULL, 0xC4C886B18474DA2BULL, 0xABAB3CE125029D02ULL, 0x6753D76029C10D97ULL, 
            0x839F413DFA2F0EF1ULL, 0x132CA8C6FBA05473ULL, 0x6F25B48E809AEFFDULL, 0x8EDE65ADFEFC2ED5ULL, 
            0xD77D594802743CEAULL, 0xEC773AADDE85629CULL, 0xE241234D8E5BA2FCULL, 0x547760E9C5EFFF7BULL
        }
    },
    {
        {
            0x68FF0163DDB23C48ULL, 0xF47138A0204D4732ULL, 0x11F14D02C1B42D2CULL, 0x2B589880C613E985ULL, 
            0x51EFD7EEB6CF4458ULL, 0x6240D99351AC13A5ULL, 0xE4F0C61773E20DE5ULL, 0x0454690A7A504201ULL, 
            0x1E0E003CE13D118DULL, 0x358CE662C293D3FAULL, 0xF01946DE396CF231ULL, 0x90D9E8284D13186BULL, 
            0x7C66F1BB434E9BCCULL, 0x09FD626CA37B3EF6ULL, 0xCCB4F798F34577C2ULL, 0x7B48E1B42D18FD7AULL, 
            0xF3A78E2AF79FA5BDULL, 0x4C029451F32267BCULL, 0x0E5AD71696C1901AULL, 0x7E22C7F98D376EBFULL, 
            0x441F6B13528C2A78ULL, 0x081B180BD72CEC91ULL, 0xEF6342DD421FA033ULL, 0x5A275C782A796794ULL, 
            0xD3FD2C94888D28A4ULL, 0xCA06784E5AA38988ULL, 0x0F9790E455E134C4ULL, 0x67B11CA69ECEA707ULL, 
            0xC67B2034BE61041FULL, 0x4DAA870D0BB5089BULL, 0xA3DCD048E6CDA9E8ULL, 0x0BC0063A2CE250D3ULL
        },
        {
            0x18E797B77F438F84ULL, 0x88B858F6849DAA4EULL, 0x0B3B626415685B0FULL, 0x2D6C31ABF48CCF1CULL, 
            0x9B1D021AA4C83756ULL, 0x5C35368E983FCBD8ULL, 0x957A8289C57C1E2DULL, 0x6A72C2EC4404893EULL, 
            0x42502FE343A1A2A0ULL, 0xDDC7B9F5BAA33979ULL, 0xE1660FD8C86EEF89ULL, 0x87FC7F79FC7691A4ULL, 
            0xC3180F86E8EAC05BULL, 0x1EB484FC1BC2642DULL, 0x074F148E2FC9AA45ULL, 0x66625666CC4DD3B9ULL, 
            0x82F9DE056D41ADDFULL, 0x48C2ADE5A39E2728ULL, 0xDBB8498BE6D0349EULL, 0x4CE5CE3D42A5EE27ULL, 
            0xACFBBE645C39FC99ULL, 0x5E96BC5FAA18CCDEULL, 0x385420C8C7E9194CULL, 0xCE958BCE3ECB7A74ULL, 
            0xDE5CB8E135D37EDEULL, 0xEECC9627A896EE23ULL, 0x67995D05E9C3A3E0ULL, 0x06072B1FF7B5CB29ULL, 
            0xC3ECFD1A6AF69334ULL, 0xA177876D6999F625ULL, 0x144ABE605F79A8BBULL, 0x12B971CAE1A0C4B9ULL
        },
        {
            0x5EB520A3270C927BULL, 0xFDAF603E8703927BULL, 0x58DE09C7612937B7ULL, 0xCD6C20FA7CC362C5ULL, 
            0xCFC79D1CD6754702ULL, 0x416930ABE274180AULL, 0xC0BAC6555B37ADDBULL, 0x5FD90ADE9906AB7BULL, 
            0x1DA72EFB2BFB9F9DULL, 0xDD868659A5CA3573ULL, 0x07B4E025892F1154ULL, 0x78DC082D4DFE691EULL, 
            0x40D07981948DBCFEULL, 0x28932BE030881B5FULL, 0x1012EE490F6D4B19ULL, 0x20B67B88EF83A8A4ULL, 
            0xFD1B2F3DEDF2FD11ULL, 0x25E7C834F7ED1AFDULL, 0xAB2EC8B4EDE0003FULL, 0x5EB6C7EED021060DULL, 
            0x7D77C0DA7184526EULL, 0xC4822C24EAAC217EULL, 0x337AC3226A44A8CCULL, 0x1008E300C100C885ULL, 
            0x12FCF20E5977B3B5ULL, 0xAF083D309A7D56F2ULL, 0x1FB10673109A4043ULL, 0xAA5F1C64D9867167ULL, 
            0x72F4B2B140444978ULL, 0xD679DC9AA35AB954ULL, 0x392828367B283A57ULL, 0x84F8B18BB61578E6ULL
        },
        {
            0xDFC2408F8D58B4E7ULL, 0xDAF778BD7BDB05D6ULL, 0x45C2AB8B954801C3ULL, 0x5132512C3EA06073ULL, 
            0x44BCA078FCBDA7D4ULL, 0xC1F3D9A1FB3781CCULL, 0x82474943CDAC56FEULL, 0x86B747A95F0F6D8AULL, 
            0x434EF7342235D0BDULL, 0xDF5F60BF0D2F22B4ULL, 0x02518A78D370EEEAULL, 0xEDB6828FA202D29DULL, 
            0x4FDC8503EF884C23ULL, 0xCEF93458155952D9ULL, 0x85AD0C073BE2585EULL, 0xF7ECA1E401B39F31ULL, 
            0x81B7AE746D1D0D12ULL, 0x145D98F438B196EDULL, 0x9562263A48A24E32ULL, 0xCCD60F5C9002153FULL, 
            0xADFA22F107778A51ULL, 0x0F9CF300A79702DDULL, 0xE69F960DC0A15719ULL, 0xBC1E72D7C0E7239CULL, 
            0x5A26D68E13326F13ULL, 0x5492E0B52B324CCDULL, 0x6FFED038BEAB23DAULL, 0x50669CC24FFF518DULL, 
            0x2733E8E8765C4A05ULL, 0x6BF345768D827F6BULL, 0xDA92CF3ADC1B7B83ULL, 0x3F3B819F0DDA5C64ULL
        },
        {
            0x217988E93E6FBB22ULL, 0xCB24B915C40BA0E2ULL, 0xB86232D1A44BBA4AULL, 0xF6167C90EA9C3B9BULL, 
            0xA714FC522C9A1D24ULL, 0x290A3777DD65D9EAULL, 0x820429C1D5A0423FULL, 0x4BE66D2494EDE6D9ULL, 
            0x26170807AA7366A4ULL, 0x4EB4A917A24C8802ULL, 0x7826132AA3DD84C7ULL, 0x27D3892D4FFF7F74ULL, 
            0x5DDBA7CE3B08FB6BULL, 0x708ABDC8A7B269BEULL, 0x1C12D052F3A27840ULL, 0x3E511732738798C7ULL, 
            0x99F4E521276F6882ULL, 0x6C5E80ABD5A2A9D5ULL, 0x7836BA30BE572F25ULL, 0xD99DBB4FC248BF52ULL, 
            0x5FB9E1E02F032B93ULL, 0xCFC3CE6D228D854FULL, 0xB5A94302F4CFF1E7ULL, 0xA69CB7AF615AB6EDULL, 
            0x0E911265E136B6BCULL, 0xCB5E8127E4549C52ULL, 0x29CEF62AC1F40438ULL, 0x59B3C933B4826729ULL, 
            0x07DAC14397744308ULL, 0x11E68334EEB21665ULL, 0x0A786F0C9F7093DEULL, 0x88E6C108761AC798ULL
        },
        {
            0xBB7823067DAD13E4ULL, 0x7BE00F9632E8B0A1ULL, 0x71933267503D5207ULL, 0xC78DA7C151C034B5ULL, 
            0x5DDB7FD6DFCE5CFBULL, 0x7C47EFFF541AE5F5ULL, 0xF2F0A475CBC67475ULL, 0xEA44FEE1226F1C65ULL, 
            0xE433E77464BE4B1CULL, 0x9B3AE1594C01396CULL, 0x95E974451EB6106CULL, 0x676586D3F71810DCULL, 
            0x2B5AB9D3551134DBULL, 0x0614193E2D13F926ULL, 0x5AAAE530B735A4BDULL, 0xD8D19AC95D47C5B2ULL, 
            0x6DF3DEB36B199A85ULL, 0xE81253A339142116ULL, 0x00F0873C9EB2E5ACULL, 0x20FB3CB5D82DA460ULL, 
            0x5BD41C6A6CE65610ULL, 0x8DE3186B79A76014ULL, 0x69AF61E28250426AULL, 0x23273D486C47054EULL, 
            0x047F1B86D71CB51DULL, 0x92821AC07B256390ULL, 0x6D3D72693DE60A2FULL, 0xD4CF50819814BE21ULL, 
            0x8D504454565412B3ULL, 0xF72265BE907AC5E4ULL, 0x9A7F90B3709074B7ULL, 0x33A5E602DA0F6F32ULL
        }
    },
    {
        {
            0x04D65F2FB09662AFULL, 0x0202A8E15AB95986ULL, 0x58762BF92FDB7954ULL, 0x55839D5EA4555A9BULL, 
            0xC9FCEFE251C3AD4FULL, 0x46777422213A149DULL, 0x0EE323566BDBCCCEULL, 0xA6ECDDB14CB81B1AULL, 
            0xBCC9E4ABE723461FULL, 0x026897016AC94F41ULL, 0x6C3FB64341B8B99BULL, 0x10D52E89E34309DBULL, 
            0x0F0E0E03F12E1F0DULL, 0x3BCDACAF055F7903ULL, 0x89A8EEAC33F2817CULL, 0xFD77430DA2DCA94DULL, 
            0x4ED9CF466AA1C86DULL, 0x43803E45322C5DDFULL, 0x2B0CDB38D21505E0ULL, 0xA5CDB7BBD1EC7AD0ULL, 
            0xB62AE267DCEBD972ULL, 0x1531D0739186050FULL, 0x83C551DFEB517394ULL, 0xCBB21B567C24566EULL, 
            0x5B3205CB710BB2EBULL, 0x582118A9D269A989ULL, 0xADCC78675C428562ULL, 0xE607272F09CC907EULL, 
            0xE6159EFC7B88F40BULL, 0x91C977C15D4D6D6AULL, 0xEFA824C2BD2F2CCCULL, 0x7735F6AA98601822ULL
        },
        {
            0x51DDD69AA7A8FE5DULL, 0x95027140B3DD39C9ULL, 0xBB30C3ED399FF6CEULL, 0xCC40630CA87A108DULL, 
            0x6759A4970170923BULL, 0xAF9B1AB63ADAA5E5ULL, 0xDFB572E3800F39EBULL, 0x9D0AA480330BEE89ULL, 
            0x4C1517EB9ECBCCFCULL, 0xF34CE9FF5E54FD6FULL, 0xA6402250C64A83EBULL, 0xCCA778BC92429E26ULL, 
            0x90A0DF0D82B609C3ULL, 0xD5B6FBF8DAB533B2ULL, 0x7A3C34CBC4F502F7ULL, 0xB5AF07EC53070C99ULL, 
            0x655C9F6F96E5482AULL, 0xAEDE0B82FE7BB053ULL, 0x8576C03DAEF77E5AULL, 0x640D8AD06F6A8301ULL, 
            0x537F0F1131377D81ULL, 0xDF6A3355254A3A54ULL, 0xCD6E91B37EDD64F7ULL, 0x3B9E564FC2410AFDULL, 
            0x23833B0C58F50739ULL, 0x931CDF77393AD787ULL, 0x2A6B66890130365AULL, 0x31E06774885B2368ULL, 
            0x333C03786E69248EULL, 0x120DC6DBA6D1648CULL, 0xBA28B9E3EE8B03F2ULL, 0xEF547BF8DDB2BAF9ULL
        },
        {
            0x7D2438C4A7B6D716ULL, 0x46C7D0FDC1190B5EULL, 0x9629EC1476914568ULL, 0x7962AB91513FDDF1ULL, 
            0x0A6AA57A1F5AE92BULL, 0x2CA7E14C5198FBF7ULL, 0xC1C7D5BB8C96FA1EULL, 0x50A24A2F2825814CULL, 
            0x75AA21200C3C226DULL, 0xC410962A88001C01ULL, 0x8CCE303FACD8FBD1ULL, 0x853CE2EB65FF049BULL, 
            0xAD2E97E14BDE1971ULL, 0xFA44EDBD87B16592ULL, 0x44CB74039F5DB474ULL, 0xF1C42BBA31C03031ULL, 
            0x7A94D271A21A76DCULL, 0x0703F66892E09CB3ULL, 0xCD5F5632F874F7C9ULL, 0xEC7D87444875FDADULL, 
            0x9AC5C007704F6987ULL, 0xEC7F387EC8F474FAULL, 0xE349ADCC8FD025F6ULL, 0xB21493FFFA3BE5CFULL, 
            0x0C05936832BEF70CULL, 0xCC6F7EB7078CEBD0ULL, 0x30FC99765D4BC341ULL, 0xE091008ABC137C7EULL, 
            0xA2E9510F36351A1EULL, 0xDD47016A38CE65A7ULL, 0xB64B3E5E3F123EA0ULL, 0x2972BCEAE3DE25F8ULL
        },
        {
            0xD85293DA7E1D9A50ULL, 0x021A24E683EE94B5ULL, 0xC634C8B807DE6BEDULL, 0xE048B0D8FC04DDABULL, 
            0xDE14C5614809C057ULL, 0x400154CA9FE2441DULL, 0x60114F89845372FFULL, 0x5A1B4D8C42C2EE8AULL, 
            0x7031E29BAA5B6013ULL, 0xB7B4D491C82572E0ULL, 0x312A295BB816AFE0ULL, 0x594595BD010791B4ULL, 
            0x3A3C9C744B3DBFEEULL, 0xA7949957C2087954ULL, 0x1DAF194B8164E5DEULL, 0x1C73D1C859B6AD50ULL, 
            0xE7569AC48625930BULL, 0xCE64045DD1FB5C56ULL, 0xCE66938A6A569E32ULL, 0x90047A55325066C6ULL, 
            0xA3D217CAC9DC3996ULL, 0xA6CF74B2F07E69E7ULL, 0x47393460AE3691EDULL, 0xEDDE47C4121F5DA4ULL, 
            0x560553CAFF2A9823ULL, 0xECE4DF0E07EFF1EDULL, 0xC1A02AD6B6E6CCCBULL, 0x26B9B7E0FC46A7C4ULL, 
            0x784BAFB0D873C48FULL, 0x9F6062825C453CCBULL, 0x873ADAA0E35192D9ULL, 0x6D51E6726872A7FDULL
        },
        {
            0xC56CCCBAC53E48C8ULL, 0x7B0F498DCD14B0FEULL, 0x20641348E6077756ULL, 0x1C8FA7472D61C522ULL, 
            0x7E0480F692A5FF3CULL, 0x7524AA525A01728EULL, 0x4BD16B89FAB94323ULL, 0x3126518BEE41B87CULL, 
            0x79C92E86278993BCULL, 0x46CAF84379DA5275ULL, 0x93649F376B241382ULL, 0x20B16B8D71D59DB8ULL, 
            0x9C43318E81C1C3ACULL, 0xAE7B0CDAC8C0E854ULL, 0x4F3287FB2E304427ULL, 0x12E5F1F4A617C003ULL, 
            0x4013C8414C12D687ULL, 0xA1822AE01A833E88ULL, 0x4CAE29C3041E748CULL, 0x982E5D91C1C0B1BFULL, 
            0x148853044BDBB03CULL, 0x83E21791AE5B3E53ULL, 0x844D9D7D3788F36DULL, 0x14AFD130E6CAB337ULL, 
            0xC2949944A199ADF1ULL, 0xBD2061F73F219ABDULL, 0x327DF2897C41072EULL, 0x4BA16A070B45E36CULL, 
            0x47CAD769DF1AC774ULL, 0x83A1E2DAF0487B6DULL, 0xFE6F92524F72A8B7ULL, 0x2C2598981FDA822BULL
        },
        {
            0xBB75AC8A8C121943ULL, 0x57AB156611CB771EULL, 0x8F91FAB41CE017A5ULL, 0xB79EBE05B5417851ULL, 
            0xD22968A39B97EC0FULL, 0x49D9B52B3D199D03ULL, 0x7D9CFBD27FD57B25ULL, 0xD8DD7CCF3205834CULL, 
            0x43C59D50B029A001ULL, 0xA92B650DD467E69FULL, 0x698AA12733C252EAULL, 0x263CFD98F0A361ABULL, 
            0x3D6E7F10FA085E55ULL, 0x1183B4F5AF2ABE9EULL, 0x0F3D87072E7839CFULL, 0xD3777B5DC734ABC8ULL, 
            0xD246B8655328588DULL, 0x7297BD797212599EULL, 0xF5F695CBDE2FB37AULL, 0xE4A47625453AE678ULL, 
            0x4ED86114ED7C408DULL, 0x98A6C5EC0327BC20ULL, 0x4B94B19A788358C4ULL, 0x982B70DAFB2D3563ULL, 
            0xBE1A00208A3DDE64ULL, 0x269CD4B7B1F0181EULL, 0x14259698438D68F7ULL, 0x02BAC36A18583505ULL, 
            0xD79CD570D402776DULL, 0xCCFBE772ACC4F18EULL, 0x9F2A37ACB1586ACBULL, 0xEED343039681E320ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseFConstants = {
    0x2171023730EAA41AULL,
    0x5D58E74E88EC7576ULL,
    0xF76C83772EC19D75ULL,
    0x2171023730EAA41AULL,
    0x5D58E74E88EC7576ULL,
    0xF76C83772EC19D75ULL,
    0xD9DF24FE93E3D039ULL,
    0xAC14A0CF6342EBACULL,
    0x6C,
    0x0A,
    0xFA,
    0x97,
    0x52,
    0x14,
    0x62,
    0x9F
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseGSalts = {
    {
        {
            0x1681DC99A44AAAF5ULL, 0x210EE85377057D96ULL, 0x6412920CF539424AULL, 0x01EB690E4E387D7DULL, 
            0x4186E98BCB7A3B7FULL, 0xBA059BF9D85F68ADULL, 0x53FDAAB22317242AULL, 0x1AA4802FB0FB386EULL, 
            0x6F7BDCD38F092F02ULL, 0x5EA1DF4E32875A17ULL, 0x3C0FAE765678DF94ULL, 0xCD06C26C6CB6AF37ULL, 
            0xA3CBC58A28247557ULL, 0x99D44CF48D26AEB9ULL, 0xD6611F2A8602CDC0ULL, 0x563515D8E9384A98ULL, 
            0x60C176D3CD50F9D8ULL, 0x38AB5D49DFD79DE1ULL, 0xF0C67A3BA723514BULL, 0x9E365949605305BEULL, 
            0x42743F6CBBEC58CEULL, 0xE952919106500999ULL, 0x35A5E32C64066ACCULL, 0x23FCFBD836123BE0ULL, 
            0xF36632F72356AB32ULL, 0x6B3578CF7F67A5DDULL, 0x2AF648A84AAAAEF2ULL, 0x62E4A90B6EECE755ULL, 
            0xFECC76B02391E8BDULL, 0x9994F9A5601383A9ULL, 0x06722EE113A1BA05ULL, 0xD5D6ACF48EF32E11ULL
        },
        {
            0x71B2B594C7230D86ULL, 0x61AD167BEB6EE97CULL, 0xA121B839411CC62FULL, 0x0985FDA6F80595BEULL, 
            0x7BFE459829CF8231ULL, 0xDE78C2EA743754F9ULL, 0x3DA0FB5F5E395F03ULL, 0xACD9DD773D4AC135ULL, 
            0x3AC97055AF2823BAULL, 0x058D520A3AC38674ULL, 0x4D904E6F1CADCCDDULL, 0xB3BAA777050C1F12ULL, 
            0xCDB111356B46A0B2ULL, 0x2F479B854E7BB7CDULL, 0xE2C2139AE5502629ULL, 0x0B3ECFAB02ADBC0BULL, 
            0x38EECDC8AD585C8BULL, 0xBC343A44387B7049ULL, 0xA96173EE686F216CULL, 0xA45881D96F0C6ED3ULL, 
            0x2020F1BCDCACAF40ULL, 0x554FA58CB0D5D141ULL, 0xB5EDBD25F1F57281ULL, 0x700C69CBA1216A1DULL, 
            0xAA47E5E6F3430329ULL, 0x6105FA578B7B2067ULL, 0x566375DE5B00693CULL, 0xA37455F2CA9397CDULL, 
            0xB7FC40FE6AED1B78ULL, 0xE31DDFBE406802F5ULL, 0xFEF6182B147DDDF0ULL, 0xD1075F085306389BULL
        },
        {
            0x49C90C9DC166B8ADULL, 0x8645F8B62873935CULL, 0xDF3ABDB30BA6948AULL, 0x72F42E68850986B3ULL, 
            0xAA7B0CD1DA62180AULL, 0xB5E65D852B5E89D2ULL, 0xC466F2A870514D52ULL, 0xDB8B61288677C33CULL, 
            0xC2AB76213986B6A4ULL, 0xFD253C944032CB03ULL, 0x48401D4BE2FA7E05ULL, 0xB10C5AD97F85D390ULL, 
            0xA3F4649BFE428268ULL, 0xD462CF26EEDF8F5AULL, 0x69032964C226FCC0ULL, 0x67B01BB535277931ULL, 
            0x9AB736B5DEF50C75ULL, 0x22C08F7918DEFC16ULL, 0x4852CF2499157CF4ULL, 0xDA9FF435CF279A5AULL, 
            0xC5F9D5D158662015ULL, 0xF3DEB9E26D2355DBULL, 0x6E85A634CDDF37DDULL, 0x3C5B592224AD8504ULL, 
            0xF29AB4224B0C9EE6ULL, 0x79A00CD2E93D58A0ULL, 0x177BD480FA147219ULL, 0x59E013BE17A5D547ULL, 
            0xB69FC0A8EBB3F556ULL, 0x3E2ADDC3EAA7D4D2ULL, 0x3E711A5FBC5E81BEULL, 0xC223A01AC90E40D4ULL
        },
        {
            0x37233B7D4BFFE752ULL, 0xF7A9BF5A79BEBAA8ULL, 0x23EC3B28DCBF10BFULL, 0xA0FA995F15B82B40ULL, 
            0xFB3DEF455F5D04F8ULL, 0xCF3490FE8723C765ULL, 0xF94D130849F7F0BFULL, 0x68BE23FF6A9ACC3AULL, 
            0x979A04CFB37ADA22ULL, 0x668FFD7E60AE8C67ULL, 0x4D00119BDEE9D06BULL, 0x4E5195D8C223A134ULL, 
            0xDB872683D2BF59F1ULL, 0x44C02BD22EB20AB8ULL, 0xF7F409B3F0E1168BULL, 0x8003A1E1751B70E0ULL, 
            0x186D77BFE2BBB7CFULL, 0x290BE434D7CD2B1AULL, 0x0F8DD6CCF615F9F3ULL, 0xC3E01610BE4A4904ULL, 
            0x1AA243F82E412866ULL, 0xA43D7CB83441E3DCULL, 0xCB0C95543F32223AULL, 0x69BA47596857B94FULL, 
            0xD6468E737F179DA4ULL, 0xB2D82385154537A5ULL, 0x03C75FF202F84877ULL, 0xEEC6BDA8AE739283ULL, 
            0xC86A2826506D33EBULL, 0x619ECB0E96C49F9FULL, 0xA6F8D08998FFA40BULL, 0xA573E8F309561E72ULL
        },
        {
            0x35275D3DBA6570F8ULL, 0xEEEE9223AF8090E2ULL, 0x76ADCDB0474ACC28ULL, 0xF5892622D85ACE9EULL, 
            0x065C6CC24856E015ULL, 0xA14D541FFFB23E06ULL, 0x09F29B313C41B7CFULL, 0x9E8FCCE30A9FFA25ULL, 
            0xA53A3A830E94526AULL, 0x1741CFF0E51BE72BULL, 0x9A9A9BBFA6A828EDULL, 0xF3E12D09885741FFULL, 
            0xB238D1BA476B7467ULL, 0x87A9A2B4A8FAD98CULL, 0x2559F483DB52ECE3ULL, 0xBB25B655115F24B3ULL, 
            0xEF713FFE19BB091FULL, 0xFFBE5FFEE437491AULL, 0x0AFEAA1B2F94858CULL, 0x9D3B82620239FC82ULL, 
            0xE62DD82DF16C199DULL, 0xD58B43D06950131BULL, 0x76E6FFF4E193A572ULL, 0x0A4BF3350EB897BCULL, 
            0xC1E52234AB7CF543ULL, 0x1D00EACBA8FA5029ULL, 0x539B4A0E8F445B31ULL, 0xD8E899171C98844CULL, 
            0xF2DFC092668CB1BBULL, 0xC834C3884613C4AFULL, 0x7040809FB7EF01EFULL, 0x42399B149446E4B4ULL
        },
        {
            0xC9BB2421B2EC0E6DULL, 0x1E9F1088952E2A6DULL, 0xBD6E96E2CE62695FULL, 0xD2864793DA3EDE2FULL, 
            0xFFED7B8936EED4C1ULL, 0x4BD1F77491C3AAC6ULL, 0x34B20AAB9EED0480ULL, 0x8CD677D94C9AB22CULL, 
            0x010A564CCBAF481CULL, 0xA8DF85FD219BB62DULL, 0xE15EC12E1E8678A7ULL, 0x8C48FC7F227BAEF7ULL, 
            0x72CD1BDA02AEB13DULL, 0x430DD34A9D5FAC1AULL, 0x08E514FE249A7FCCULL, 0x2D35CB5459F00184ULL, 
            0xCE5F762CCA97066AULL, 0x8CBD0450C279E225ULL, 0xD1D53EF1F6F9C432ULL, 0x27E0AA62E8C22FC1ULL, 
            0x8CBEAE6D79100291ULL, 0xC7668ADE0E9F5DEBULL, 0x2E9C05FFA562095AULL, 0x5628278A35EDB994ULL, 
            0xBDDF085E7CCCD9E8ULL, 0x92A63ECA935C201BULL, 0x709414D6FCC4B50BULL, 0x4B5CE90514699311ULL, 
            0x597E66D11C58E904ULL, 0xBE9E70C6942EBA2FULL, 0x041D569436FB2934ULL, 0x75043274ECEDE5A3ULL
        }
    },
    {
        {
            0x5AB633EB9A0D27AAULL, 0x7C0BA1B05097653EULL, 0xE36AF33240EDF251ULL, 0xFEA226D760B79D68ULL, 
            0x43B251E6429C6ED2ULL, 0x9BFF475F4874E40BULL, 0x8153140FD4B4E2B8ULL, 0x84636E908D526077ULL, 
            0x3F02D07E2202F7FFULL, 0xD150AB99AED8FF8DULL, 0x89744E919B8EDF5EULL, 0xB2C58C43BF6E6FC9ULL, 
            0x63380C6FEE1D614EULL, 0x95F8E68885E1CC52ULL, 0x286F278AA6C42FC8ULL, 0x3637595106BDE482ULL, 
            0xC5E3F492C2E38335ULL, 0xE28DA5C65797F419ULL, 0xE56D5DB4C0EC1207ULL, 0x991A78CF891F3836ULL, 
            0x6C05435831E916B6ULL, 0x4F95BF68BCCD0C92ULL, 0x5532BF9582EE1F80ULL, 0xFAFB0B213555BE01ULL, 
            0xB97C228ADA322F39ULL, 0x377DF7C552D314D4ULL, 0x3BA92446380C8EECULL, 0xEC09F8D3D041B936ULL, 
            0x2B1D9B9C98484D44ULL, 0xD5C2CD2BBF4111A4ULL, 0x752B650B5A7480F9ULL, 0xBA885A84107C14C4ULL
        },
        {
            0xB20B29E9FC287195ULL, 0x62CECD4FF178AAB8ULL, 0x533E886511B9D007ULL, 0xECB34A7B14CE6615ULL, 
            0x9D08C87505248666ULL, 0x8C349EFA48BB1A28ULL, 0x07F7371962E1291FULL, 0xA7D6AEB2650F8E4AULL, 
            0x68A5F0525778A080ULL, 0x58AE9718D5CDD788ULL, 0x9E0C5A4AD7D5390BULL, 0x32252E938176DBB0ULL, 
            0x1E75840D6E1C85D1ULL, 0x2399F5407224A6ECULL, 0x6544706F3D911192ULL, 0x10DDFDEFD18CBC39ULL, 
            0xB9EC5DC83C399F81ULL, 0x294D2CCB8D06F65DULL, 0x44012D240F8BAE7BULL, 0xB74F9D6584F08012ULL, 
            0xC1D0A9F2EEF113BCULL, 0xAC04C2540E595E22ULL, 0xA83ED84E70FBC6AEULL, 0x651D19ABFBA8DF41ULL, 
            0x19F563FA779A7860ULL, 0x2BF2F0C6EA416168ULL, 0x69D42B2C21C9CC40ULL, 0x8E12C99204E1E603ULL, 
            0x4BC024FD530C9E0BULL, 0x3B1BB18255BA9DB1ULL, 0x17CEA916D9FFD371ULL, 0xF51A9000B586A511ULL
        },
        {
            0x6D9143F2A8007DDCULL, 0x394DE9C843C3D71EULL, 0x6F182E5FA7CB0848ULL, 0x73F435CE10D41CCDULL, 
            0x81601B4F60D49906ULL, 0x09C98A17EE39A6CBULL, 0x50B09CE038DB61F5ULL, 0x8711CA47D4F6F82DULL, 
            0xC83527B24CFB208AULL, 0xEFEC2E82D72F1461ULL, 0x373B8EE9E2CA76F6ULL, 0x33B19922B45FD366ULL, 
            0xB8D46566B2215FE1ULL, 0xFB8FF7E4F1079649ULL, 0x90E86FF91A253DDCULL, 0x9ED8C649C84FFB52ULL, 
            0xFB0902F0967BBC77ULL, 0xB3862FDD03C98F2EULL, 0x9CDC16E264687D53ULL, 0x7E0A04CBAFBB8C55ULL, 
            0xAE7B41268FCA5994ULL, 0xF1DB1013B0288827ULL, 0x116439EF0DC1A3CEULL, 0x8382832033CF3059ULL, 
            0x5AA3E8283656A837ULL, 0x519AA5828D8A2167ULL, 0xEBF59C5D686E73A6ULL, 0x791C63D4965A73B3ULL, 
            0x8B6014201BA149D6ULL, 0x7DCF69EE34B67774ULL, 0x00789F4EF01492EAULL, 0x6379272CC8A4D60BULL
        },
        {
            0x9E7BD87EAF9DB78BULL, 0x1FC6A11B2FA970ACULL, 0xB960A8DC2F0345B6ULL, 0x1D438C0C80370FAAULL, 
            0x6D0EABC5F5D5E23FULL, 0x12FE2C8F5FCE9C27ULL, 0xE4CDC6CBD020A268ULL, 0xCF30D6EEA5B8590CULL, 
            0xDB7715E252C64FA8ULL, 0x5A3018AD3A6472B4ULL, 0xEF1BD473D8844E25ULL, 0xCB9BB7D724262D6DULL, 
            0x7C3F6C9E74A2036DULL, 0xA66CE526B1FAC234ULL, 0x734031EE405797C8ULL, 0x25F18809BC44ABC2ULL, 
            0x7C5143514078219EULL, 0x81276FC6E0D6B6BCULL, 0xAF88E66741B58C4FULL, 0x28FA4EE6DD3C4737ULL, 
            0xAA348CCE6E358E4DULL, 0x1B8CB868518BD23AULL, 0xA1E7B75D163429D8ULL, 0xC6E2CF5EEA8C16C0ULL, 
            0x9673E1F4C2B3ED46ULL, 0xBB40414FB0B2A8D5ULL, 0xE3EEA223123B1608ULL, 0x88337F4D39A6AE2DULL, 
            0xBEE11C3B523BF42FULL, 0x3BAC3F588C3B6EC3ULL, 0xE98E016683EFAC8EULL, 0x3D25092169A1B8EDULL
        },
        {
            0x9B7B61FB85B3E8C5ULL, 0xA07522E56D0A18D9ULL, 0x4291F956F8DDC9A7ULL, 0x2D9B4DBF5DB6BF3EULL, 
            0xC21BDEA215F8DCBFULL, 0x9F1462CFFDAA4257ULL, 0xCE0A5356407B6205ULL, 0x7118B4BC8487CEACULL, 
            0xCB4610A37ABA2B35ULL, 0x6E05B72EDFA76626ULL, 0xED19B75CF3CAC37BULL, 0x45B014CF3BC25990ULL, 
            0x829DFA448FCA7F78ULL, 0xF25C58C28DF8737EULL, 0x7DC7E790054BB860ULL, 0xCCB36E91E696874FULL, 
            0x608628BAE9619F2DULL, 0x92B151DB408A3A4AULL, 0x3EE65967723296B2ULL, 0xDDFFFC99FB56E4EBULL, 
            0x5516061362289DA2ULL, 0xE9B49ADF9DE34FEBULL, 0x11D406B986C93082ULL, 0x66A62FE988E87C00ULL, 
            0xB13B5C09D9B040E2ULL, 0x76F48F13E0CDC4E5ULL, 0x765CADBF75CA26E7ULL, 0x58901350393A61C6ULL, 
            0x1EDF3AC6D006D7ADULL, 0x5D5E44A56B4ADB65ULL, 0x1C3B65E188A430E7ULL, 0x13BE521D1D58204FULL
        },
        {
            0xF69A687D51E3B899ULL, 0xC467A79F56B59FB7ULL, 0xB2E67EBB29EC6A77ULL, 0xA483AEBC4B031AAFULL, 
            0xA736EF778ED373ABULL, 0x17D94DB3D00E4F55ULL, 0xB78F0E64AE2DF26BULL, 0x4C7B724E6975E0B3ULL, 
            0xA8E9598E076DA462ULL, 0x62FB7879D62372DBULL, 0x7EDAF8B98E0C7068ULL, 0x8B96FD90DCB0E3AEULL, 
            0x2158AF800903B64AULL, 0xEB60536F38C27A27ULL, 0x4D03A6811D041C19ULL, 0x5F723AF390F22809ULL, 
            0xE45CEECDB19DA27CULL, 0x958B2515C82A23DDULL, 0x9C1510834106008BULL, 0xDF2D27A4630E899EULL, 
            0x21BD267722E07934ULL, 0xCEE11BD0E777A57AULL, 0xD293B1EC5BEC3647ULL, 0xFDA935036023C2E4ULL, 
            0xFBEC55F5265E817FULL, 0xF450D2EEBEAEF07DULL, 0xFF559F89E1C75582ULL, 0x577A5F6B3D92FDCAULL, 
            0xA8C181F32960C0CBULL, 0xE67DA503CB4BE99CULL, 0xA2AA0EEC177871B3ULL, 0xD4923ECC08A75711ULL
        }
    },
    {
        {
            0xFAC330EC7F8B9425ULL, 0xD55AB866F9C0A2EEULL, 0xD92AD6325F4C5F10ULL, 0xE421068CC3D375EEULL, 
            0xACD889D42830F3DCULL, 0x23AF6A6592D7556CULL, 0x4D0EB834A2EAE755ULL, 0x9C328E05E057261EULL, 
            0x8C2AAD67698C4628ULL, 0x6ADAF2D20A615FAFULL, 0x7935E7EF71F17C02ULL, 0xF424AB3FA08B0570ULL, 
            0x4193ED732E2513B0ULL, 0x6128BE6BA07C00C4ULL, 0xD063AC993470249EULL, 0xD7F543A2CA89CFB5ULL, 
            0x0C091EF435503A43ULL, 0x3519E06F8ED8239BULL, 0x10348BA26968E50EULL, 0x29BA4E1E2CE928C6ULL, 
            0x9A6BE4BE0F3C7F27ULL, 0xCB6BB428FF736F01ULL, 0x0A78D2D2F44E6B5AULL, 0xD556FDFE8BEBA574ULL, 
            0x30E3A669B7C6BEECULL, 0xF772F14BD4431BF2ULL, 0xF188DE481CE23FCAULL, 0xDAFA9122331EF331ULL, 
            0x5CF14DA52A8582D1ULL, 0xA4E577ADA764B8C8ULL, 0xF438596C76EA88FDULL, 0xED5A6F4117070555ULL
        },
        {
            0x4C72A6E4C4CB4A73ULL, 0x9D87FB205358151EULL, 0x8C471BB4CC88DDC3ULL, 0x1FFB91E3C967E267ULL, 
            0x0A32986F334587E0ULL, 0x7443CC7063DD4E6CULL, 0xF081B41DDCED9992ULL, 0x8ECDF8CB4D68045DULL, 
            0x79F2368B8D99DE98ULL, 0xE9BDFCD707EB3F21ULL, 0xF86E586C46326F5FULL, 0x49B5A9C3D9432ED0ULL, 
            0x9771436F7DC7723FULL, 0xD9772FCAAC0495D3ULL, 0x4EE3176E039334F3ULL, 0x89B6A8273A0ADAC0ULL, 
            0xE394AF0AC27694A4ULL, 0x1FEB06E7C374D991ULL, 0x7BCE4C2BF140F7E8ULL, 0x41E1C843DC35B87BULL, 
            0x8D2072CBEC58FECBULL, 0x71E50EEA8871DCC8ULL, 0xF805CCDE5C75423CULL, 0x142C4D564D667B9FULL, 
            0xEE656111AA07E4F0ULL, 0x4142CFEBE6519290ULL, 0xC5175249A3158F1BULL, 0x0A2CA3A5CB596240ULL, 
            0x2E3A561A6B8E14AEULL, 0x5760FEDBEE9978EBULL, 0xF8E5584A2DD483B7ULL, 0xE283BCD0DC12CE0AULL
        },
        {
            0x4430C24D5CF7C8F3ULL, 0x984B39002EE142DCULL, 0x7383A87E328D31A3ULL, 0xB1C338F829A188CAULL, 
            0x2ED67AE6C831CB27ULL, 0xB951F9732D5B3A50ULL, 0xA4F0884DB8AE8402ULL, 0x92DDC1F97B064CDFULL, 
            0x0CAB7E57F6D2352BULL, 0x01F8A4E1FF6D9189ULL, 0x32130B7A3A304136ULL, 0x813B70F8AAFDB70BULL, 
            0x3CC552EF7A258F3FULL, 0x7BEB5B036E20F255ULL, 0x164FA8C59958D4BBULL, 0x4A1D556EAD89C592ULL, 
            0x88BBC89E451A69C6ULL, 0x89781D54E3D4D488ULL, 0xD23A412111FB564EULL, 0xC7EAFB01ED881580ULL, 
            0x95C6804B55958155ULL, 0x55BA3A7618768B16ULL, 0x63E94AA4B601E61DULL, 0x009847FCCF920423ULL, 
            0xA94FF5F48BADC4BEULL, 0xDFD12A590297B111ULL, 0xFEB385C3B9678D1AULL, 0x8EE686E128241BAEULL, 
            0x330E1A7941736336ULL, 0x5B8A8B1DFBF668CBULL, 0x98342F5F3772419DULL, 0xA77C90516FD068B2ULL
        },
        {
            0xBA53B91FF4281D52ULL, 0x1F3B09B9A6D66358ULL, 0xD69718ECA1103BC1ULL, 0x60EA7F7D1EE2BC8CULL, 
            0x365A4BC36C6D6D97ULL, 0xD042D97ECF95D4D7ULL, 0x77D19C3C93565810ULL, 0xF956FDC59748B563ULL, 
            0x82D8A6DFEFC3C488ULL, 0x0330DBE9A5271CD1ULL, 0x3A14255F6716D7E4ULL, 0xA77BD6F446C1BC5FULL, 
            0xF16816CA2338EBBFULL, 0xBCF1BBDE7708078CULL, 0x1337EE52DE3D675BULL, 0x04FBF95AECA91CF1ULL, 
            0x739ED8FE0C486B57ULL, 0x6C7870A3086DA486ULL, 0xA7443B99448FAA5FULL, 0x0533197301835B12ULL, 
            0xBA83DE9202F5BC79ULL, 0xC881F75156A5A0DEULL, 0x177859352AE9B131ULL, 0x16D52039B9DCF6B8ULL, 
            0x49BDFC2ED7AA7805ULL, 0x21A0580BDDC1A14BULL, 0xEE5125B8BA3A2111ULL, 0x0281BE808306D476ULL, 
            0x32404A1709B25401ULL, 0x2E78D8D39CDB0BB5ULL, 0x776D42D5C9735415ULL, 0x2B2A3F7E8A4CDA6FULL
        },
        {
            0xDAFA182EE1B5E170ULL, 0x58A452C49E8A6FABULL, 0xB00D9CF3B652D261ULL, 0x7083DFCE53CF1DB0ULL, 
            0x1A953DD4F7AA3BB1ULL, 0x3A3057F59D4006FBULL, 0x3F27F7572D363B0FULL, 0xB5EE8E3F815197C4ULL, 
            0xEBCFD15E4C6360EDULL, 0x30A7E95450B3CD62ULL, 0x29FE3655EE91B4A6ULL, 0x593375C511599F6BULL, 
            0x1DA0CC0CD343B6CAULL, 0x3D83F4AFB6CB5DC3ULL, 0xF0A2C434FBAA4E14ULL, 0xB17412BD66C86B9EULL, 
            0x46941230DF116614ULL, 0xB8B5271A93E56143ULL, 0xB4FD5B7EE0F42BA9ULL, 0x05E73E4BD32E152BULL, 
            0x69CF19D383B65954ULL, 0xAC5DCC32582662E7ULL, 0xA5DE89CD03203377ULL, 0x1F68BEE56C55C3AFULL, 
            0x9CAD477EE928C466ULL, 0x9D3E4FD7330EE6B3ULL, 0x17EEC0473EBDF53BULL, 0xE44A5414AB90A842ULL, 
            0x7BFFF83E2B0D5041ULL, 0xD426639209CC4733ULL, 0xFAE2607CE93813E6ULL, 0x25D2908CE7AA9CDAULL
        },
        {
            0xA03CD9204E47FABAULL, 0x5411461C9A0ADAC5ULL, 0x36EEE5D4B32595CDULL, 0x9906B6B5F48A5DF8ULL, 
            0x7DFFCBD1106112E2ULL, 0x55B6A37574E8561BULL, 0xF80E754B432F1DE0ULL, 0x26BC2CBA469F4321ULL, 
            0x542B63049B14C6E0ULL, 0x0F70584C8C987523ULL, 0x66C81D6C4C731D2EULL, 0x539E6739EC1FE938ULL, 
            0xC163781AFDF527A3ULL, 0x4F1041105178FFDBULL, 0x6AD61F7875E7FBEBULL, 0x7AE45157BE0073C4ULL, 
            0xAD71259D266D17D1ULL, 0xCF67150AF5F0D2C6ULL, 0xEFAF9B4C7936B67BULL, 0x704839A62C175BA3ULL, 
            0xCD364F0960984591ULL, 0xB4C49F11AEE8E5A4ULL, 0x7962B58B58A02EC6ULL, 0xB0BFF643D373CBFCULL, 
            0x7D48DB4FFBA61F24ULL, 0x56AF7249D0E54D7CULL, 0xBE995221B0BFCB19ULL, 0xBC026C957C408997ULL, 
            0xA4ED1936DC1863D7ULL, 0x2E51025D2A8E4950ULL, 0x3CC303C0509B754DULL, 0xB680BD57AD15AEC9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseGConstants = {
    0x5DB0F4744042D22CULL,
    0xDB996AEA2406E2C9ULL,
    0x1BB051AD1042645EULL,
    0x5DB0F4744042D22CULL,
    0xDB996AEA2406E2C9ULL,
    0x1BB051AD1042645EULL,
    0x7E9AF3E039AE466DULL,
    0x042A6CFDFD537657ULL,
    0xEC,
    0xFE,
    0xC3,
    0xA4,
    0xC2,
    0xF9,
    0xBE,
    0x4D
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseHSalts = {
    {
        {
            0xBCAB585D089418D4ULL, 0x30F171059E880CE5ULL, 0x720B2AE11D613399ULL, 0x0DC02FE19E7E420DULL, 
            0x9F972ECA82713B7BULL, 0x6583A097AFC484FEULL, 0x82F0ACB4A930CD49ULL, 0xB8BEB7018C7B1161ULL, 
            0x60885A54A23D4C15ULL, 0x3A27C836554DDB39ULL, 0xAD2E367E45A38C5AULL, 0xA1FA7B5C90CB0358ULL, 
            0xE3FEE18FB30973C4ULL, 0xB40030F301D2D55FULL, 0xBF6FD700415751BFULL, 0x34F26109BB22BA9FULL, 
            0x9950472A15295A92ULL, 0x1BBC08A3DB6F06AAULL, 0x514D5033D8464AFAULL, 0x743D3932E96604B3ULL, 
            0x2FD74AF6A008CF91ULL, 0x2DB22403C3ABAC04ULL, 0x004058ED667208CFULL, 0xD41BFE93112BB969ULL, 
            0x11E0B7A07B92C74CULL, 0x385E65F1918EC67AULL, 0x245438953BD76915ULL, 0x7DF3480B6815DE2CULL, 
            0x6855FFA60EDEC009ULL, 0xC22F15494C4137ADULL, 0x2F62C6CD5AF7616FULL, 0x37925491885E14B4ULL
        },
        {
            0x520781612199DA75ULL, 0x00DD16CF8F717C39ULL, 0x7DC43B1FE725F1BAULL, 0xEFE9F4C91FC9A0F7ULL, 
            0x54137B2827769635ULL, 0x4E3BFD8EB290DFEBULL, 0x9C0D3919AF243D05ULL, 0xF96D8F7DE6C02DA6ULL, 
            0x69EE79A70E831711ULL, 0x3635C1B15C46C32DULL, 0x3E789AF06B912BAEULL, 0x9D8911450DBAB1BFULL, 
            0xA38A500037E147BEULL, 0xC6DA36349E962B3BULL, 0x3EDCADC7A1E76167ULL, 0x73C67339C00103DDULL, 
            0x186BE57C770FEB35ULL, 0x0EEF6FB16DC877EEULL, 0x60CCCF050639DDAAULL, 0xCB992949EE1538F6ULL, 
            0x0ABEBAE7294CB3C3ULL, 0x18053375BB58FB6BULL, 0xF3D1A45C1546C938ULL, 0x3A8DDE9BE8CDF13CULL, 
            0x32E651C25889E7D9ULL, 0x6C5F95A337B07AFFULL, 0x16837F71A1B6593EULL, 0x172AF50854A765C7ULL, 
            0x25CCA5687A132465ULL, 0x9AD0933BFA43FC3EULL, 0xACFF9AE81A57C1D8ULL, 0x28CC007F3ED44275ULL
        },
        {
            0xD1FC4FB7CA1BC7E3ULL, 0x1EFB196E5EF0D3D0ULL, 0x2089CFB25669A2E3ULL, 0x0D4315C74DD5EF0CULL, 
            0xCC0F660EDFD0E9F1ULL, 0x2B2A73C81C11C47FULL, 0xB04DEC56205319B8ULL, 0xC0C7FD901E40BDAEULL, 
            0x0C379E1A1EDD88E4ULL, 0xFA4A2BA179B98B06ULL, 0x4877B2A9895C44F2ULL, 0x967BF1CD4AB89E08ULL, 
            0xF2E1DF9730DF1E65ULL, 0x24CA7BB606D10AD4ULL, 0x898DB18F6400655CULL, 0x16225843DFDBB98AULL, 
            0xC102164529B3FF98ULL, 0xB457688C9471973EULL, 0xF56D09C70C7A32ABULL, 0xF4F43AD2998142DEULL, 
            0x1C59F4B0A9DFDD73ULL, 0xDA9B584FE14ECF83ULL, 0xF1D0A77FDD2F91F3ULL, 0x4116648E26AF3956ULL, 
            0xFD8E64E526AA157CULL, 0x791D86CD4C8052F9ULL, 0x2AEAEE662EC4FF83ULL, 0x8506EFFDCD6038B9ULL, 
            0xF34986DE0B0DDD9EULL, 0x990EF0BF89495C7BULL, 0xDEAA4F8DA4C25FD3ULL, 0xB4C67A57B3506152ULL
        },
        {
            0xDE3DB093E20BFFF1ULL, 0xE140E7FA0411DB5EULL, 0x9670263DE7F6A8DBULL, 0x21BFA70B67F7E9C2ULL, 
            0xB25DB228FB5AB65CULL, 0x30F3F91A25DF2FB3ULL, 0x2AA9833DF6C599A8ULL, 0x48EE65F6376CCB77ULL, 
            0x864C73FAA519EE85ULL, 0xBCE4E6EFDA71DA4CULL, 0x2311DBFE5BE429CEULL, 0xAC590FA704D37E9AULL, 
            0xAD4AC655EE74E506ULL, 0xDC1F699E547889F7ULL, 0x7382CAC40D1F3BBCULL, 0xDAA5C77B6248D675ULL, 
            0xA880F86C3AF1EC22ULL, 0x457E3D1DA08F1F6FULL, 0xEDD63E8E8027F8BCULL, 0xAF586882EF09B7B3ULL, 
            0xD99794FED1A2F10FULL, 0x239C0F76CB0AE385ULL, 0x4D4D1C7F5639FB80ULL, 0x435B12A47399EAE2ULL, 
            0xD7A24ACAD93AA5FCULL, 0x0A30FF79867DBFE2ULL, 0xA6B8263248BBF03EULL, 0x833FE613AE5F3479ULL, 
            0x36BF10BB30E3468BULL, 0x4A60564D64CE0201ULL, 0x17D76545AF15E6A7ULL, 0x7DE1948FC22C0791ULL
        },
        {
            0xFA52D7FB607123E9ULL, 0x5AC713E4BEEFD564ULL, 0xD2C43604991AE18AULL, 0xFC622F468F866D58ULL, 
            0x19DE7565680D746EULL, 0xD39E19E4DE6C1038ULL, 0x487CB217F8B8AAF7ULL, 0x5DE317354E4C4DADULL, 
            0x69BDE416A0930EB6ULL, 0x369A24CED4E33F9EULL, 0x445D7A57B249888DULL, 0x63C798BF4FD59530ULL, 
            0x66786B9B70361D42ULL, 0x9955342B1D20595AULL, 0x975AF3EF8CEC4411ULL, 0xB5D50E06E3E4D216ULL, 
            0x03DCF1B3CDF3CB86ULL, 0x1D1462C00B20E936ULL, 0x5D7B992EA63E508CULL, 0xAD0DB183E3B5577FULL, 
            0xADB8E7A91FBB21D3ULL, 0xA7AD05E97C62E36CULL, 0xB2EEBECCFDA26A3DULL, 0xB0D1FC8F8EB2C81AULL, 
            0xC3650DC12BDA5E2BULL, 0xF090B79A28BA31ABULL, 0xD54BB2CC0FA28E1EULL, 0xB1354C1C6BD3C0AAULL, 
            0x11EE8A69AF88FD4BULL, 0x02ABC2DA67084515ULL, 0x0EFCA1DB399AED51ULL, 0xB2304580E45F82CCULL
        },
        {
            0xEE1B52923B671508ULL, 0x6A6F19BDA988BBBAULL, 0x8ED7587F9E15315FULL, 0xF0A9A76F00B272DBULL, 
            0xE822F8935C191A60ULL, 0x3CDAF53353994DBAULL, 0x4498BF02EAEEB01CULL, 0x9BA795CF74DBBF74ULL, 
            0xE630D9733D98BBA8ULL, 0xD0854B76F5AE6F3EULL, 0x5430E677F151B840ULL, 0x54CAE7EF6853AEC5ULL, 
            0x849408F4EE0167D4ULL, 0x6FD59C4AE31305DDULL, 0x6B8F388F339C51C0ULL, 0x06892A329A7516C4ULL, 
            0x914E36EB071C5620ULL, 0xB2E687BD9B3E8003ULL, 0xC4FB5A3D51B3CF75ULL, 0x87ACC6F9EFFD3B1DULL, 
            0x7DDAB812EAC6382BULL, 0x329CF6DB50F99CF1ULL, 0x11CCF7D8B877C88AULL, 0x17B548B85F8B7349ULL, 
            0x7AD9007474DC2480ULL, 0x9E0CC14A83EBCEB4ULL, 0x84855420C0017074ULL, 0xF719342A46B17A34ULL, 
            0xEE9E638A3B440CD2ULL, 0x3F043FBFA9025564ULL, 0x460D3E5DC3D1ABC5ULL, 0xE22540439B812427ULL
        }
    },
    {
        {
            0x0D54D5389F83D033ULL, 0x0F8A0235F625F568ULL, 0x1FC902D982B6F231ULL, 0x8D18676334A43B85ULL, 
            0xB777933C12AD8880ULL, 0x1D9317995FE647D9ULL, 0x88540DF99FA27039ULL, 0xB70A543C182DA28EULL, 
            0xCF15CF0E6ECB9B58ULL, 0x3C495541709F389FULL, 0x942A59E43AB5594DULL, 0xB7A5C71226179157ULL, 
            0x335E6D9D0A27BD5FULL, 0xCA6916E910E2C194ULL, 0xFE338926A64C8A7AULL, 0xDFC2485FF8F7FC33ULL, 
            0x78D1CA9885720C8FULL, 0x4B6DB70E01CDA269ULL, 0x94E12FE2596225BBULL, 0x085E89ECB25216C4ULL, 
            0x212AB3A29B35EF68ULL, 0xD474A5E567F5D0C6ULL, 0x75AF7E5B667360D5ULL, 0x19311262950C456AULL, 
            0xE8E63AE0549E6335ULL, 0xFBD07ECECE77E7AFULL, 0xE2B8A586DED9A0B0ULL, 0x2992FCDEF1D94ACFULL, 
            0x71406AE781BDE791ULL, 0x160422490522BA53ULL, 0x807885CAE8699C1CULL, 0x1D8BE83F09C6F61AULL
        },
        {
            0x898903CD7B4EF0E6ULL, 0x691DD32C3629B49DULL, 0x35B3CDF00D66FC3BULL, 0xC3041B0A50A5A7E9ULL, 
            0x77A2129C58E92640ULL, 0xDEE0045AF8688EB2ULL, 0xEE17B43063A1DBD0ULL, 0x972CD553B48803D1ULL, 
            0x4289DB443184298FULL, 0x70C682EA7DB30487ULL, 0xC9A038E1504B1983ULL, 0xF0B3841B7B897E0CULL, 
            0xA132D320ABAD1FE6ULL, 0x6AE1CB1820150910ULL, 0x3D0892084C4331DFULL, 0xD566D248E176757AULL, 
            0xB3D0AE78E0C9806CULL, 0x4571E09ADD780B79ULL, 0x136D5A4938A8A07AULL, 0xADB001C8F8A85A1FULL, 
            0x32C96AFCE0FCD67FULL, 0x6A836262228D032DULL, 0xF51EAEFF121CBD39ULL, 0xFD016EC824AC6B69ULL, 
            0x02CDE3E0763112C2ULL, 0x822E7D88999B86FDULL, 0x55B58B007AC5649CULL, 0x3B5F1D525E209151ULL, 
            0x6EEE808EA7C2BA75ULL, 0x7B637F76E05E6B9FULL, 0xD12D7671F7EEACC8ULL, 0x44400574E577F95EULL
        },
        {
            0xA130DB315D0CC5B0ULL, 0x9F2F2EFD2525C607ULL, 0x03DA630C127A5796ULL, 0xCA2E787A09C573E6ULL, 
            0xD828C0EBB32D5418ULL, 0xEF56D8D4F91322ACULL, 0x886587C784F35600ULL, 0xC8013316362C0B4BULL, 
            0x06CE9306580B27E2ULL, 0x901E827D38FD2080ULL, 0xFE7F4A90929713AFULL, 0x08B68EE30BF51340ULL, 
            0x40D96A53DF0B5B7CULL, 0x35152A8D909C47E4ULL, 0x057E360764765DF2ULL, 0xB28F97B7DD9D6639ULL, 
            0x42287963354C0A72ULL, 0xFEE8E67902491E9BULL, 0xB7FC0DC618058E55ULL, 0xC801D92FF343B7A8ULL, 
            0x7C6B9D495E8BBCA2ULL, 0x66FD175A1174E530ULL, 0x20B38B2E17895790ULL, 0x2A1489F8E155368AULL, 
            0x2209CD1E8FB63BCDULL, 0x5D724A79E50DEDD7ULL, 0xAACDC53A1DF65542ULL, 0x25DE5604970C9DD4ULL, 
            0x75C64DB29F70C8EAULL, 0xCA0B28EDB4A8D90EULL, 0x64C68B43DB43E842ULL, 0xB4EBA4FEC696D0A1ULL
        },
        {
            0x71AE6F97FF23C360ULL, 0xD869F9431FCF4FA0ULL, 0xF64463A4E8037E7AULL, 0x05D910DD5585ED44ULL, 
            0xAD254E9EB55CE3C8ULL, 0xFD20EA3CE4D4FF2FULL, 0x858A76EEF8960F63ULL, 0xC86D0193656B95B3ULL, 
            0x4DD2411352B856F1ULL, 0x716A8F2360E3EF49ULL, 0xB86F74E38515E257ULL, 0x29D13DB712CEF8EAULL, 
            0x96FFF6EF57AA6F80ULL, 0xC42FAB5E1091AA1DULL, 0x18D5E3689DF10733ULL, 0xDE4DB2F19C91BA79ULL, 
            0xF9A8452D877D86AEULL, 0xE0274EB2CDFAE1C6ULL, 0x5FF5423C1FDE142EULL, 0x8D7954FBAA164EBEULL, 
            0x99530D3F3626CD36ULL, 0x1D8640C421756397ULL, 0x077B7FE316356D4BULL, 0x48FCC61E82C90576ULL, 
            0x37824236E1C657F0ULL, 0x07BB9B4D7A2CBCAAULL, 0x7ECCA5E0833D9A58ULL, 0x0265D77444E96ECEULL, 
            0xC6AE77F32B0A7DFDULL, 0x56AF9E9D4119F09BULL, 0x9877DFB023301EADULL, 0x5C63C154EE672A0CULL
        },
        {
            0xAC805FF726967988ULL, 0x5024037AA53028FFULL, 0x0DF902E92CFAC464ULL, 0x6FE2E81E58C3C4CAULL, 
            0x920FE59B489FE30BULL, 0x7C12A02E86997247ULL, 0xB5B7835364637ABBULL, 0x1C5F89757C0D8127ULL, 
            0x630E6788564509F1ULL, 0xD92EC6C1C7A552B4ULL, 0x4F513FD2397F42BBULL, 0xDBFEE251C02A9AB2ULL, 
            0xC6D3580C1A42639BULL, 0x9FDCE1E6E24DF9C8ULL, 0x85DC97D2FC1FA33DULL, 0x33E547AD522E22DAULL, 
            0x4857206E59AA3448ULL, 0x388A692EF3DFF919ULL, 0xD3126986E4A71FC7ULL, 0xD2803EDC114004D8ULL, 
            0x57B9FBA21AD8166AULL, 0x6A27D76DEB730D49ULL, 0x3B399629202CDF77ULL, 0xE8FD1A5B1AECF94FULL, 
            0x02939B853358EB2AULL, 0xFF4815900BBFD468ULL, 0x95073193FA4CC88BULL, 0x5697ED80A56C918DULL, 
            0xC9912D9B13F7AADDULL, 0xC7374686687AFCDAULL, 0x8E2413FBD567D373ULL, 0x37EE7AA40A02579FULL
        },
        {
            0xC6DBC4B1896F2404ULL, 0xBC932265EB762C0BULL, 0x995F2ADB232A11FFULL, 0x3452E71F54C02FE1ULL, 
            0x896742189A96654AULL, 0x312FB75405AEB74BULL, 0x67DE1319D8AAADCBULL, 0x10F543E80ABAA20EULL, 
            0xDF23EF205D5DD6C8ULL, 0x8D9D96BFA40D6031ULL, 0x5135A26A3BD74961ULL, 0xA7104ABA489FC0B3ULL, 
            0x37A95BF7CC42124EULL, 0x0A79998A5D247B83ULL, 0x80496E8CC5CAD694ULL, 0xD5940127B4691D95ULL, 
            0x8E2DB362554D56F5ULL, 0x18E22304EF9DF041ULL, 0xCFA6AC5051C38BF4ULL, 0x2CE7FCBB0BE2C7D4ULL, 
            0x6ED5B69F63074F0CULL, 0x0FA1A0FEA4EEFECAULL, 0x3C1894D44C719848ULL, 0x04CACB4A1FCD3FB6ULL, 
            0xB7932E6D030D2863ULL, 0x92F729A4FBF45584ULL, 0x57C21D63DC609A27ULL, 0x4E9F205264363A6CULL, 
            0x4CAA88204C4924D4ULL, 0x0440A536D6941645ULL, 0x8918E872BA18A94CULL, 0xCE1F589357DCFBF0ULL
        }
    },
    {
        {
            0x18C78F7AEC45BF53ULL, 0x0BEB33BA8C68FBCBULL, 0xD9655F1ED753B772ULL, 0xC986198571AB86DBULL, 
            0x026A61EBEB5A5526ULL, 0x8B80DD4DEB61A060ULL, 0x8226B3C45A628ACCULL, 0x5B5EB55DF3AB43FBULL, 
            0x962C7981B96518F4ULL, 0x02F789386C2B07F1ULL, 0x4BDEB6BC81B41B37ULL, 0x2905F426956A1A51ULL, 
            0x50E55C22B16DEBBDULL, 0x76921E5BB1083DD2ULL, 0x83DB8D64EE0B311FULL, 0xD1342D7D9539D839ULL, 
            0x5DF86FFBAAD92CDCULL, 0xFE4F4F8D9D75FB59ULL, 0x8DFCAEA720709040ULL, 0x9C830C57E616DE87ULL, 
            0x6E1BC5F0134AB039ULL, 0xDDC90CEFD48B086EULL, 0x75B5E50A08F4D118ULL, 0xFFB94D871F39F039ULL, 
            0xC7DA1DBF3C4B41F9ULL, 0x1162B9F511494C09ULL, 0x548B97A136D66DB8ULL, 0x571C323BD093BF3CULL, 
            0xFEC8AF8914F558E1ULL, 0xA3F6C8149E87D9A5ULL, 0x11E92F52718BEF61ULL, 0x1C4909D9572D842EULL
        },
        {
            0x8AC1BF7F3C85974BULL, 0x81BD1DF95BEE3C15ULL, 0xF5FD07164D09D0A7ULL, 0x0450009B288C5DE2ULL, 
            0xF1A0B192816D2A60ULL, 0x6CF49725DA8294A8ULL, 0xD2A4B9239456E9CDULL, 0xD8AD131603CF7438ULL, 
            0x2D21E26594F0E98CULL, 0xF800BD3885EC097DULL, 0xFD03B4A521EA6135ULL, 0x9E729BDAB310CF4FULL, 
            0xF4ADC0927477C076ULL, 0x1BC15DBDE49A2C13ULL, 0xA1319BF57AC03E42ULL, 0x5D34A77D0EA404BFULL, 
            0x41FB9E85F221B73CULL, 0xF482F9148439CCD7ULL, 0x3A5EF9B6970071BDULL, 0x8419B859850CC274ULL, 
            0x308EEEDC6833105FULL, 0x8EE67A9BCCE3C420ULL, 0x20318915460F3E49ULL, 0x0D6BA5A764E24C48ULL, 
            0x33C61DEFAC927CE3ULL, 0xF3C96AC19538C1D9ULL, 0xF1E90EC0FCEE683FULL, 0x2DB79033EFC353D7ULL, 
            0x5902D5914F72BD6DULL, 0xBFC968FF70786880ULL, 0x2544C5313F77D155ULL, 0x4F4774977A97FA1EULL
        },
        {
            0x44DEFC296E6ED352ULL, 0x5D2E047F2A56740EULL, 0xAFE10896B2F682D0ULL, 0x36AD5FD1685F79C1ULL, 
            0x293147A36DB5D0A5ULL, 0x2DC5E08A969ABBFFULL, 0x3AD4467A7EACABC2ULL, 0x2B2227F0EB3C168BULL, 
            0xE2AD2C998B7251A5ULL, 0xC3A81F1EFF80A73CULL, 0x35F028DE632988CDULL, 0xC1B45B48019F6D85ULL, 
            0x7AC0AD8F8F471AB8ULL, 0xB28A2DD0F1946127ULL, 0xF6F9472EA7759BABULL, 0x1BB4C09A3136A6C8ULL, 
            0x30EFF1CCD37A589DULL, 0x1267F8A0583174A2ULL, 0x23BDF167306A777DULL, 0x24F1F7741CAF8ADAULL, 
            0xF42DEF3DDAB6234AULL, 0x6F495DDFAA927CBCULL, 0xCAA0B66C80387D73ULL, 0x6EC71C5103316E2EULL, 
            0xA25A44DC220310A1ULL, 0xD497CA55853BF633ULL, 0x13E684AA532B5F3AULL, 0x1EB4C01F821FC17FULL, 
            0x649BACF183EED38BULL, 0xC7F06DA239DC0FD2ULL, 0xC18A335404E968E1ULL, 0x277F55F06A688C08ULL
        },
        {
            0xDE344F36B09169B6ULL, 0x580F3B7E80C4182CULL, 0xB7E88EAB823EA7B6ULL, 0x278D3FF99DCFA069ULL, 
            0xF7D0C1F1C8D077D2ULL, 0x8E629AD94C2A1F1AULL, 0xCA07559688450519ULL, 0x3183C742E7AE6139ULL, 
            0x3A5960328F4342CFULL, 0xEB40A46DD35A3C65ULL, 0xB90FF160CF04501BULL, 0x4041E2728D5A489BULL, 
            0x2929FDFEB251D965ULL, 0xDBC8D7123BD0E50DULL, 0x767327035D682ADBULL, 0x204D0B4F51FA34F3ULL, 
            0x8B47F2ECC2877E2FULL, 0x9501E386F4155735ULL, 0xFE67AFFF11783200ULL, 0xDF1C46D13F28E763ULL, 
            0x55112C1E7F9518C7ULL, 0xA4F14AFD4AAAF5F2ULL, 0x74FD8AC0147F06FFULL, 0x4E4E35A82945283DULL, 
            0x4E6CC2D6A21FDDF9ULL, 0x9DE7B6180329F442ULL, 0x71EAE2F73BBE8C4EULL, 0x058E86CF5D4B472FULL, 
            0xC9C7AF58B27E5B61ULL, 0xF1D4A983822FEA06ULL, 0xB3C36CCE42B4A2BCULL, 0x54D41DDFF9C37E52ULL
        },
        {
            0xEB11564BB082F774ULL, 0x88F5A3E489C56E7EULL, 0x19AB2971A7336D3BULL, 0xA5BC137232EAF073ULL, 
            0xAB8B028FA938AF22ULL, 0x6C591D5B67F54886ULL, 0xC7989DB8227F1F01ULL, 0x76439A57934D1CBDULL, 
            0x974E58BC031244F1ULL, 0x460A426AF3303DF5ULL, 0xEDE4510B8695C3CAULL, 0x0F67C0F8485273D9ULL, 
            0x7F2CA4DCE2A89E26ULL, 0x5BC34BCF6A2F3654ULL, 0xC706344B7506F31EULL, 0x8DC5BCB199821DDAULL, 
            0x6D9CCCA72D535B51ULL, 0xC38EDCB711D06D8EULL, 0xA4B37A2F9D2761D5ULL, 0x53F747A94864E9C8ULL, 
            0x32B1350E504FBF6DULL, 0x1A7AEC4A53DFFED8ULL, 0x8BAA8CD779726287ULL, 0xFB9D2308366ED130ULL, 
            0xC033F4A11841CEB1ULL, 0x87DD6EB73457290EULL, 0x0E0A3799A8F3EB4FULL, 0x850F327BA0014435ULL, 
            0x9A64015FF3ABC93AULL, 0x7FB44A7CAE74BD14ULL, 0xE93FD1FE21CF62DEULL, 0xB637914F01EBC3D2ULL
        },
        {
            0x0306FA4C4CB429B9ULL, 0x724AC570C5EB76F1ULL, 0xB82D9CC66B4C2CE5ULL, 0x74D672164DEA87D4ULL, 
            0x816F950EA1622FBFULL, 0xDC405B71ACF200DAULL, 0x8E97A9A4278BE636ULL, 0xDFD583EB733E2F89ULL, 
            0x71D5348DF0ED41BDULL, 0x9551F7D8CCB19EF4ULL, 0xE3A1A8C71DB8B7FBULL, 0x7CC0134656A18D34ULL, 
            0x2E9CB88A52C11462ULL, 0x8FE75459A082B953ULL, 0xF1131F553927E03DULL, 0xA0083AF76DA25A98ULL, 
            0xD3EEB5253428C560ULL, 0x90258C6A1E384439ULL, 0xD9C1177DCABEC9A4ULL, 0xA3580C3A8DE65830ULL, 
            0x31EEC4022943B22BULL, 0x4C27EE318A21BD55ULL, 0x03CE802867AAFE8FULL, 0x8F32A458A838E38DULL, 
            0x2AD91A544DADDF81ULL, 0x25AA76101AA47B3FULL, 0x2F3CC692AC70F2A6ULL, 0x683E6632DFEFD22FULL, 
            0xDF879A34C5CFD800ULL, 0xAE1D829E08384655ULL, 0xF535E61186104D9DULL, 0x65BEB84C80E07026ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseHConstants = {
    0x5094D6FAFF9A86CCULL,
    0xEB27F40D7AC29816ULL,
    0xCDBB39D4B2ABA8B1ULL,
    0x5094D6FAFF9A86CCULL,
    0xEB27F40D7AC29816ULL,
    0xCDBB39D4B2ABA8B1ULL,
    0x9928747C1AEF3812ULL,
    0x816842FD8E52B606ULL,
    0xCE,
    0x58,
    0xE1,
    0x6A,
    0x4B,
    0xD2,
    0x39,
    0xC2
};

