#include "TwistExpander_PingPong.hpp"
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

TwistExpander_PingPong::TwistExpander_PingPong()
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

void TwistExpander_PingPong::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x92FCA61BCC69F6AFULL; std::uint64_t aIngress = 0xBB6CA62D0B3B0953ULL; std::uint64_t aCarry = 0x95242423016FEE11ULL;

    std::uint64_t aWandererA = 0xABAF85AABF6C018CULL; std::uint64_t aWandererB = 0x89A29BED046F9968ULL; std::uint64_t aWandererC = 0xFE535EA8A1BEEA8EULL; std::uint64_t aWandererD = 0xBBA0D0642BCE5ED3ULL;
    std::uint64_t aWandererE = 0xD8984163289CF471ULL; std::uint64_t aWandererF = 0x8A5E0F3B103BBAB6ULL; std::uint64_t aWandererG = 0x8298542074E1C663ULL; std::uint64_t aWandererH = 0xD4D8EAC18F349095ULL;
    std::uint64_t aWandererI = 0xAE068B5ECAA2A6E9ULL; std::uint64_t aWandererJ = 0xA999C3B962196B39ULL; std::uint64_t aWandererK = 0xC248414C5E951C4AULL;

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
        aPrevious = 12481755642742841844U;
        aCarry = 16559004750594572240U;
        aWandererA = 12771824828430101801U;
        aWandererB = 9336996902334365027U;
        aWandererC = 16842658780322916234U;
        aWandererD = 11607049804129652285U;
        aWandererE = 17229075971750290798U;
        aWandererF = 15656712754589199177U;
        aWandererG = 16555000146977441750U;
        aWandererH = 11489820648937386543U;
        aWandererI = 14674523290803914789U;
        aWandererJ = 17296856721210347134U;
        aWandererK = 10246570264290299995U;
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
    TwistExpander_PingPong_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_PingPong::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD8218745E375C848ULL; std::uint64_t aIngress = 0xFD5D67671412E593ULL; std::uint64_t aCarry = 0x8754872F96E0A986ULL;

    std::uint64_t aWandererA = 0xD83AD5EF8F903994ULL; std::uint64_t aWandererB = 0xA48AD09B54E87385ULL; std::uint64_t aWandererC = 0xFFD29FA5722B2A61ULL; std::uint64_t aWandererD = 0x80F29C87D5C52E63ULL;
    std::uint64_t aWandererE = 0xF1B56CE9B9DC881BULL; std::uint64_t aWandererF = 0xFB04641984F69B6BULL; std::uint64_t aWandererG = 0x9B66D63CBB64E96AULL; std::uint64_t aWandererH = 0x8592C616C1ECFA99ULL;
    std::uint64_t aWandererI = 0xAA81413833AEDCA4ULL; std::uint64_t aWandererJ = 0xA205175F27389CEFULL; std::uint64_t aWandererK = 0xEBA476D8BB49CCDBULL;

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
        aPrevious = 11291636434219835214U;
        aCarry = 10213126906265399908U;
        aWandererA = 16426514472198854691U;
        aWandererB = 15923209931721877722U;
        aWandererC = 9925319293720968290U;
        aWandererD = 17924589343919415305U;
        aWandererE = 10261515496638778700U;
        aWandererF = 14833919351276917956U;
        aWandererG = 18440009146837763201U;
        aWandererH = 17526536636045242085U;
        aWandererI = 16869577283642947597U;
        aWandererJ = 13525944017451305190U;
        aWandererK = 9705279367475192412U;
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
    TwistExpander_PingPong_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_PingPong_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_PingPong::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDB3EDC33AFFF0C48ULL;
    std::uint64_t aIngress = 0xBDD2D0A413AFAA17ULL;
    std::uint64_t aCarry = 0x99EE872C3647F966ULL;

    std::uint64_t aWandererA = 0xE8D2FC0D6DA12E09ULL;
    std::uint64_t aWandererB = 0x93918DC18A93132FULL;
    std::uint64_t aWandererC = 0xCA0609EFFD89EFFCULL;
    std::uint64_t aWandererD = 0xB700946F5F61F86BULL;
    std::uint64_t aWandererE = 0xFFF14E28E16CCD6FULL;
    std::uint64_t aWandererF = 0xD2882288AFB23ACFULL;
    std::uint64_t aWandererG = 0xABB8C67337D8FAEAULL;
    std::uint64_t aWandererH = 0xBA6C3E5CDC4DE0D9ULL;
    std::uint64_t aWandererI = 0x89C373247E449766ULL;
    std::uint64_t aWandererJ = 0xFAE1B38573A4B8E8ULL;
    std::uint64_t aWandererK = 0xA62ABA4C3B40F83EULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
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
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_PingPong_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_PingPong_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PingPong::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_PingPong::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF31B85459EBE1458ULL; std::uint64_t aIngress = 0xE9B90C565D404E29ULL; std::uint64_t aCarry = 0xEA3E4CDB71C26ADCULL;

    std::uint64_t aWandererA = 0x8EC5BD2326626438ULL; std::uint64_t aWandererB = 0x9CBAA9DD09307F0CULL; std::uint64_t aWandererC = 0xD0809DC1097A41A4ULL; std::uint64_t aWandererD = 0xE9BA709EA4D92407ULL;
    std::uint64_t aWandererE = 0xB61CC2FB1F45BD93ULL; std::uint64_t aWandererF = 0x8C7A05B17AA89C0CULL; std::uint64_t aWandererG = 0xE75EF9BDCD7A8F9CULL; std::uint64_t aWandererH = 0xB1A9CE2EFEA25926ULL;
    std::uint64_t aWandererI = 0xA3BB07EF1930EE13ULL; std::uint64_t aWandererJ = 0x8C76526AC1F76DF6ULL; std::uint64_t aWandererK = 0xA5D3EC226A61E8C1ULL;

    // [seed]
    {
        aPrevious = 13299443570814747024U;
        aCarry = 15760352814518533274U;
        aWandererA = 17955196351061306096U;
        aWandererB = 17898350480228599111U;
        aWandererC = 18016303582977721430U;
        aWandererD = 16577051110688677776U;
        aWandererE = 11191581840535518237U;
        aWandererF = 14980902612511455818U;
        aWandererG = 14262767831837568659U;
        aWandererH = 11448866432590870027U;
        aWandererI = 11891556534349423414U;
        aWandererJ = 15609933153847470285U;
        aWandererK = 10618635503351294947U;
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
    TwistExpander_PingPong_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_PingPong_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_PingPong_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PingPong::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 1 with offsets 7973U, 5502U, 7424U, 5868U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7973U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5502U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7424U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5868U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 0 with offsets 762U, 5654U, 6969U, 3088U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 762U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5654U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6969U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3088U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 3 with offsets 1145U, 6589U, 2393U, 6313U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1145U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6589U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2393U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6313U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 0, 2 with offsets 705U, 5424U, 256U, 4990U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 705U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5424U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 256U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4990U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 with offsets 1241U, 468U, 1201U, 1205U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 468U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1201U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 0, 1, 3 with offsets 1854U, 163U, 1797U, 630U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1854U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 163U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1797U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 630U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 2, 3 with offsets 352U, 1173U, 1462U, 1811U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 352U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1462U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1811U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 0, 3 with offsets 327U, 1984U, 1121U, 802U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 327U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1121U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 802U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1629U, 383U, 1347U, 5U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1629U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 383U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1347U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 5U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PingPong::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 1 with offsets 6940U, 4895U, 8161U, 789U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6940U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4895U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8161U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 789U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 3 with offsets 8041U, 4691U, 2186U, 2622U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8041U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4691U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2186U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2622U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 2896U, 2479U, 3367U, 5009U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2896U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2479U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3367U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5009U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 0 with offsets 1537U, 7381U, 3482U, 7658U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1537U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7381U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3482U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7658U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1372U, 6879U, 3489U, 1599U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1372U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6879U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3489U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1599U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1776U, 129U, 127U, 613U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1776U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 129U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 127U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 613U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 558U, 531U, 1448U, 1008U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 558U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 531U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1448U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1008U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 488U, 88U, 1147U, 252U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 488U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 88U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1147U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 252U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 702U, 1223U, 446U, 1354U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 702U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1223U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 446U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 3, 2 [0..<W_KEY]
        // offsets: 1013U, 28U, 1176U, 948U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1013U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 28U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1176U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseASalts = {
    {
        {
            0xA8A5E373DDEEDA7FULL, 0xDC594E3B7BBE6046ULL, 0x8EC5A0C7B972FEE0ULL, 0x0FA20424D9993DABULL, 
            0x6F65AFDCE2FC5E63ULL, 0x8559ADA765A68669ULL, 0x9E2391F73C606FEEULL, 0x396C792B9D3064A4ULL, 
            0x142B83C5A2CFFDE2ULL, 0x8FCE9E33A3AF0945ULL, 0xB0A6B11E7E630C1BULL, 0xC5484BF573A0BE1BULL, 
            0x4AF8B887E3E8817AULL, 0x56B2CABDC8F7D27AULL, 0x640CB85E9BE2A2E2ULL, 0x5419BE62C807E5C0ULL, 
            0xC0DCE19E28A0EB3FULL, 0xB86276B8EF81940BULL, 0xC61D49BCE4771383ULL, 0xF675E473462FD4BEULL, 
            0x8C718FDD0AE6556EULL, 0xA79010BB76450311ULL, 0xF2EA2764FB951E45ULL, 0x315833A6578995EDULL, 
            0x9D09366123809E28ULL, 0x1F2405FFE49DEDACULL, 0xD52AE55C04F57BB8ULL, 0x8CC583226FF70435ULL, 
            0x43CE1EF0135EB4E7ULL, 0x5ACEAF1BC11F2374ULL, 0x60A41F7240EED682ULL, 0xAACF0A1DBB36B97AULL
        },
        {
            0x50FB87DFA7EF7749ULL, 0x33CBF2A4D2BEE397ULL, 0xAF9E1D35FC4F16F1ULL, 0xADF2EF342D851908ULL, 
            0xCC2C65C9C4FB09FCULL, 0x8E36136BD59B7D6BULL, 0x97358C25658CA60EULL, 0x781909171293DA81ULL, 
            0x0F2765588C05116CULL, 0x389C9D99E48D9DFBULL, 0xC4F725CD5EF678C4ULL, 0xF7F8581765BDB905ULL, 
            0x3DFF35B8D4BFD667ULL, 0x44396D7A6A43DEC0ULL, 0x899567A7BD2EFB58ULL, 0xE8D63C280CCB6338ULL, 
            0xCCDD7BD714E83C96ULL, 0x930EC796F08417D5ULL, 0x97D68B2CBC9E5A3FULL, 0x1C1151509DFF577EULL, 
            0x6F1270EF9625C808ULL, 0x0EA272E7328717D5ULL, 0xE3B8CD8D8DA6D12EULL, 0x09291A48364E94A2ULL, 
            0x14A238566ABDD008ULL, 0xCB3C3B4DE7D59F9DULL, 0xB436E2DF76B6B054ULL, 0xC8043975FB1380BDULL, 
            0xD4040EAB5CE7E11BULL, 0xDFA0C8F73B91A5B3ULL, 0x3C4C520F394AE54DULL, 0xE65B9A903663BF89ULL
        },
        {
            0x60623E4CCDD84D0FULL, 0x1F7427949B65B810ULL, 0xA435C115FD102AB7ULL, 0x7B4ED25D32E65D72ULL, 
            0xC711F7B3696A3356ULL, 0x497BEBEC490D38E3ULL, 0x9044B10516E98307ULL, 0x56533338FD322CCFULL, 
            0xEBB1523A91629DF8ULL, 0xCB2DD7F4224D75E8ULL, 0xD4BE6D26EE081F95ULL, 0x0EA5A662E9B8C993ULL, 
            0x895BC07D5BE1FBE5ULL, 0x8F15F1F66DB9C949ULL, 0xCDD4D0DE119FE8DCULL, 0xC1800E1AF0AF9708ULL, 
            0x6A96564E53394CD6ULL, 0xCF1AE47597D88500ULL, 0xE7707D0798EA3967ULL, 0xB5456FBB0D4AC442ULL, 
            0x0D9740DD49BC813EULL, 0xEE5069B06CF7C94AULL, 0xC55562CF316BAEDBULL, 0x9AE6732C72F90316ULL, 
            0xA65C825EF46DA368ULL, 0x715E1C0F6D88B94FULL, 0x8A3268DD4509AC2DULL, 0xD1608E437318DC6AULL, 
            0xAEAD5404B7E51320ULL, 0xFA0FBDFF2F654FD2ULL, 0xA60EB01508E5D010ULL, 0x3CD6EC70EC166DF5ULL
        },
        {
            0x94E40C8913BE9765ULL, 0xEDCF73234A217EBCULL, 0x4975ADB851567316ULL, 0x48A654DF347E2D26ULL, 
            0x1F9BCCC831B1C483ULL, 0xAFB9384807F3D5FBULL, 0x7428255899025BFBULL, 0x69FC667BCF91C845ULL, 
            0x4AA26C3D77930D81ULL, 0x8759C32E03365A68ULL, 0x9B510F580210D593ULL, 0x2DF4D5093F2564CBULL, 
            0x20ED79EE2B7CE6D5ULL, 0x0F449E7E23D853DCULL, 0x20898833D57F3CE9ULL, 0x7FA0C5CC26F5AA80ULL, 
            0xEC1C72A509FE86CDULL, 0x1714022E727829D4ULL, 0x9FA776CB0D0DCFB7ULL, 0x69789AAED9957676ULL, 
            0x4465C882464B2453ULL, 0xCEE3C4C838B04536ULL, 0xA311856C1E4D7A5DULL, 0x7BE6D23A19501DC4ULL, 
            0xF2979EB7B69C168BULL, 0x9F023511CAF36380ULL, 0x293CD03DDBCE99F1ULL, 0x0461F4ACAA6DF62FULL, 
            0x2727EBC861B85525ULL, 0x657165A28717D63AULL, 0x9683986711DB374EULL, 0xAB4AF29CFC9BE6C5ULL
        },
        {
            0xDBC7295EE0C86150ULL, 0x64C2DDF68C504EE2ULL, 0x89C04DF95F2F4860ULL, 0xBD27813319773357ULL, 
            0x5E884667B5BB3639ULL, 0x6EEC667A2804E6B7ULL, 0x65D26A8621E304DAULL, 0xBC9C2C92C096029EULL, 
            0x292976C300F0CE0BULL, 0xA9FA585EB8C1220FULL, 0xC854CAF784AEC9A2ULL, 0xF26F4FAB974D444BULL, 
            0x5EB020F669B25C22ULL, 0xB393873D7AF8F6CAULL, 0xBF4D42A2550C9737ULL, 0x70010E09CFC5123DULL, 
            0x9BE265546C94DFC3ULL, 0xD358FA449E6A64DEULL, 0x854B2BDB0B4B76D2ULL, 0x24337BEF410CC833ULL, 
            0x19BC85CDC45DEEB6ULL, 0x8D4E98030A9F0360ULL, 0x365CBF71F570B58EULL, 0x85AA4436CF69F854ULL, 
            0xFCC5D00A58C34601ULL, 0x347F9B3922FB08CDULL, 0x6BD53AF4F5FD15C4ULL, 0x145D43B9E01190F9ULL, 
            0xCAF91CBE3F7DFE10ULL, 0x002CA51F6D372661ULL, 0x3705EB72FD7E9E24ULL, 0xCC1FCB80676874C2ULL
        },
        {
            0x134E2111BB093109ULL, 0x94F5A76F746E37C4ULL, 0x8E64B22828AC4F1EULL, 0x2D75F7FEDB21CDC2ULL, 
            0x1D2701E89D216595ULL, 0x44DD35E4E64ACFD4ULL, 0xD3B0A7CE8C7396ACULL, 0x80685C6926CD95F1ULL, 
            0x0BD2A739D815D208ULL, 0x5608D75E420976A3ULL, 0x9BF82BD99F4A2BC1ULL, 0xD143A462DE1CE863ULL, 
            0x46FB74E23EB9ECD0ULL, 0xE4EE6606C8FF1F3AULL, 0xF7B164AF4309E35FULL, 0xE9A634F40B04F0B2ULL, 
            0x800BA3C70383F82BULL, 0x6657A2879FECE484ULL, 0x3730F2C2B869AD55ULL, 0xC7409D7473D33B7FULL, 
            0x1C85571EFB46DD7DULL, 0x43EF7679A914B9EDULL, 0x0DE4205BE9BFE7F4ULL, 0xD5AF9B86F861C731ULL, 
            0xE9426A2E77D1E74AULL, 0x1CBC475C8F4BA2C0ULL, 0x7A3C4F071EF25B57ULL, 0x3C481B07AD7613E0ULL, 
            0x24133758F94758D9ULL, 0x5475B5B117A825F2ULL, 0x157FAE4FBA15BD49ULL, 0xD964952A26343A0CULL
        }
    },
    {
        {
            0x41DD32CAFE01E2BDULL, 0xF2EF6BB274D2EB8AULL, 0x1B55C8776C08284DULL, 0xF37FDC1E888F18DEULL, 
            0x43CE3E0DC60A9C78ULL, 0xD4D1C02C79B7EBC8ULL, 0xB73C03AB379EDC9DULL, 0x3C4492146ECA1C9EULL, 
            0x87AEE0D036B79AFCULL, 0x553F26B57366B05AULL, 0xA86E34FBECC9AAF9ULL, 0x6A8D514C6D901E36ULL, 
            0xB36432FA307C45B8ULL, 0xE3ABFC022BB92C34ULL, 0xC35E98B0AFF35C40ULL, 0x26C5020FAAE6173FULL, 
            0x15F8D59FF2623455ULL, 0x32800F9FA5C222BCULL, 0x58D94A7A21794750ULL, 0x217F9283EED9E0A1ULL, 
            0x03F3C4B094AEB8E6ULL, 0xDDC86C5F2FEF72B5ULL, 0xC202F056531CDAEFULL, 0x11F04AAB79EF01CFULL, 
            0xF7589F77F91FDF63ULL, 0x4069B591D2C08377ULL, 0x60F3E05C0345F63CULL, 0xE4F0ADEA2DB0798FULL, 
            0xAC058469C0C256ABULL, 0xEDFD8A19B4A54B3AULL, 0xF8CD36EF54FA1593ULL, 0x2762847896D13714ULL
        },
        {
            0x6287BA8C14493999ULL, 0xA0EE2810C32AC971ULL, 0x2513C96CAE4590B0ULL, 0x126A58585D120550ULL, 
            0x8DE148AC4771D835ULL, 0x52E9C1EBFD50B367ULL, 0x4A01F9D81C166BD5ULL, 0xA75B62C063232182ULL, 
            0x44DDD1E91B97DD43ULL, 0xF04D5AB2914FA6F8ULL, 0x6E981CBC23C7A62CULL, 0x1EC914948C3B40FCULL, 
            0xF0F26196E4281F46ULL, 0x10B0411A9A4F08DCULL, 0xE45B1ED926D62E4DULL, 0x1CB5B77D5B8BD08AULL, 
            0xB577FDE13AB6C3F2ULL, 0xB53C73F65B976A9BULL, 0x3C1EE99060DC925AULL, 0x860942EF978A91C7ULL, 
            0x0581F65B3DBF9B96ULL, 0xA767A05111E8E7ADULL, 0x83EF2F3D90E769EAULL, 0xEA68D83359765EA5ULL, 
            0x9F74B343F6C22037ULL, 0x46477A537F8D2B79ULL, 0x61C77C504F7401C7ULL, 0x4C0EC4BF9667FF1FULL, 
            0x4086BCD3A6D21221ULL, 0xA63345EA0B89821AULL, 0x2D4820C1DA236467ULL, 0x4F5A6AC83D1C6AC4ULL
        },
        {
            0x43B9B8FCB4C68DFEULL, 0xA1DA08D15A577E0FULL, 0xA6D7FE7E168A3B34ULL, 0xB97E3415DF623E50ULL, 
            0x86A52583B48C9EF7ULL, 0xC74C22B3A8E74AAEULL, 0xC248CADCABED3C85ULL, 0x375593B1A58A2DBDULL, 
            0x44AF11DA33BE2CE0ULL, 0xB027C2A3F26B42A2ULL, 0xD3D98219DB0F0F97ULL, 0x138AB5E1517FD7BAULL, 
            0x911F58229C714B6CULL, 0x5D659F2BEF9A2E7DULL, 0x6D3288EBCE41BA22ULL, 0x06DCCABAEC9EA124ULL, 
            0x72389DEA3624C7F4ULL, 0x53C26DD731050F1BULL, 0xA29CBCC91A2EFD62ULL, 0x57E500169E0123C8ULL, 
            0xA489FA8FB12DAE88ULL, 0xA6BC6C8140935366ULL, 0x93675C59EC1FC179ULL, 0xCC5EF32581987EA0ULL, 
            0x4E9F4EAC593EDA90ULL, 0x43865E23BB37AD08ULL, 0x106305F66C9AE8C4ULL, 0x0A66C52556551F6FULL, 
            0x51F91112D14B6695ULL, 0xD8EF3D9D3A1543B4ULL, 0xBA619413327326BEULL, 0x1244BB7AB1470CDBULL
        },
        {
            0xAD7C20F61817FC0DULL, 0x174497FDD556C406ULL, 0x09786609A8167B33ULL, 0x1BD52574DF2C3B3DULL, 
            0xF167D6F19C970B3AULL, 0xBB70A8A40F7E4517ULL, 0xEE4678901B5D7F0AULL, 0x4A1E4F576963801AULL, 
            0xCEEA995C2B17ABFCULL, 0xC30B796AF031A7E8ULL, 0xE86F0FAA6A6828DCULL, 0x5EC0A360787556C7ULL, 
            0x7BBE1CA37629C170ULL, 0xEB64C8C34121405AULL, 0x788996CAC0DEC928ULL, 0x2D830DB694960370ULL, 
            0xA1862AE6525F6025ULL, 0xB992E8FFCDF81A1EULL, 0xAFA44F3EE58D14C5ULL, 0x562C8128F4DC2256ULL, 
            0x1F64AFB0B8C5B1FAULL, 0xA5B9772895E2C35AULL, 0x31D74BBDEA62778FULL, 0xC2396DDBACBA32CFULL, 
            0x840B42636E0E5B7FULL, 0x0613D9EF7AE94B95ULL, 0x03E98433D26E0943ULL, 0x16E546E5EAE6CC93ULL, 
            0x35B1C54B9877D3F7ULL, 0x8239249FD2B1F5B4ULL, 0xEC2EA65DA5FFED99ULL, 0xBBE8F9A9CB3BAEBFULL
        },
        {
            0x4A2F1A1AF0C3BD2CULL, 0x5498863DCC0487DDULL, 0x1AD8C0FBF6B58BF1ULL, 0x0684BF15CB6410C4ULL, 
            0x9F52D27D096EA49DULL, 0x924E668E6A1802E2ULL, 0xCD4A3132BEF9B814ULL, 0xF5EF904DB7522281ULL, 
            0x1A304BAA464A0FE8ULL, 0x6BD3CF07920F095DULL, 0x0B56DD2434E2DA7DULL, 0xDC892FB9A195DB81ULL, 
            0x117BE13FBFD4DE2AULL, 0xE4C64128FE8C637FULL, 0xFB1E8D96170E48A3ULL, 0xD1C1F062AD24EC4BULL, 
            0x75975FB15CAE7F1EULL, 0x3A9A38942DFCE4E2ULL, 0x73B18F312F69F5B0ULL, 0x2D963A0D7AE9581EULL, 
            0xE5CEE931609C1469ULL, 0xCD8C5563B953E922ULL, 0x6EF21708FCE83C8EULL, 0x36B14CF1760BD399ULL, 
            0x15D7E8C2BDE6BBB1ULL, 0x3E1DB0008F595A1BULL, 0x73A91AF9ECF49680ULL, 0xE688041FEA14BB79ULL, 
            0xF3D97C319A2DEA68ULL, 0x228546A3C349A80BULL, 0x2E87B200BA9E4198ULL, 0xB00EBBBDE847F253ULL
        },
        {
            0x5D5FD2A9A35C3311ULL, 0x8EA774F5CF7B9805ULL, 0xAC1C7A07EFF0AC71ULL, 0x232841BB888FF011ULL, 
            0x09BD29ADB9A4BC3BULL, 0xB9E9BF33BD4FBCD5ULL, 0xBFC1054CFD360E26ULL, 0xF02ED9715EB9D023ULL, 
            0xB25944DC5C7F513AULL, 0x21538C810ED7F061ULL, 0x926056F369329960ULL, 0x615748EBAC1D2C76ULL, 
            0x8EEB7AD7422DD0B4ULL, 0x723A217499AFC924ULL, 0x11EE9734BAE489F1ULL, 0x65AD28A9B461E3E3ULL, 
            0x29534778A77E0DAEULL, 0x2FCEF5C926E58977ULL, 0x1BCCCB968B9ED506ULL, 0xB946FAD0C61A63F0ULL, 
            0x6FC1C68913E769CAULL, 0x6825F85F9F6E1720ULL, 0x4F7CF5F81ED25CF5ULL, 0x7602EFAFF17A38CBULL, 
            0xB68D8DB91E860690ULL, 0xEB307F72FD4BD12EULL, 0xF6CA65BF56CE8976ULL, 0x3B7F17275436FA67ULL, 
            0x700B681E18AD210EULL, 0x23004BBA683DC742ULL, 0xF00EEFA1A68D47DBULL, 0x6FE014C7CC0A4913ULL
        }
    },
    {
        {
            0x356E0FDE846DBB4CULL, 0x92F576A6CF449336ULL, 0xEAD09B6FC139BDECULL, 0xB2BE79A6E49B3F14ULL, 
            0x4F7208B0DE50D476ULL, 0x3746CF764F072547ULL, 0x206E6DC11D8C6F22ULL, 0x3C397E60059DB20EULL, 
            0x98CBE23AD8ABBD00ULL, 0xD7002A094147FF61ULL, 0xC1454DA9D0332EE0ULL, 0x06740C8691B4FF6FULL, 
            0x88B2A566AC14CBA3ULL, 0x94191B941A40A005ULL, 0x0A6B4B40F2D456B7ULL, 0x9F0C0397C700D1BBULL, 
            0xFD201AAB11476A1FULL, 0x5C2A6AFE3C912B12ULL, 0x2FFAFFA9EDADC3C0ULL, 0x4A4AF5DB220A456EULL, 
            0xF189CCA4F659FEC5ULL, 0x35815691693A5165ULL, 0xE60CD8ADD82CC5BCULL, 0x8D148C38C2EAA946ULL, 
            0xE077CEF8A54549BDULL, 0x30AEC1794EB3932CULL, 0xD21127B7B6102EB6ULL, 0x51B88CB8CBCACE6DULL, 
            0xEC4853BA644BBE8DULL, 0x5DFE82F68F11B1D9ULL, 0x53BDA9D4D3719139ULL, 0xA40224F5BFE9042DULL
        },
        {
            0x52D439DF2B68C5C9ULL, 0x63EE39D6C887A9C9ULL, 0x424DD4363D86D0ACULL, 0x1092F7F41564BDF3ULL, 
            0x8DCBEF7981C3EC28ULL, 0xF9689044A3D55807ULL, 0x9EE0E3708C1BC5FBULL, 0x886F6608EF9564C4ULL, 
            0x0562588B7E82F649ULL, 0x7DB9587CEE9E0235ULL, 0x6DD248316462AC57ULL, 0x05F9D1541BBE24DBULL, 
            0x90BD1F7611938B59ULL, 0xEB9D9F80DC744784ULL, 0x1CE8E030038811A0ULL, 0x4E59AE125C673EDEULL, 
            0xB3872EFA0107478EULL, 0x2445A8BA49E91C91ULL, 0x69275885A6273EE3ULL, 0x6C14676664549462ULL, 
            0xB4787BBE47585271ULL, 0x858FD2E045F12E2AULL, 0x1E4A7E075BCE2A1CULL, 0x4D8731AA26775A98ULL, 
            0x8629E78F179D7B0EULL, 0xD189BC87BEE80DEBULL, 0x8976A667CD673196ULL, 0xFB490EBC258364AAULL, 
            0xB3ECFDEF39E6F8F2ULL, 0x5C96D3D3FB8BEA4EULL, 0xD7EC0EDD474A8A2EULL, 0xFBF59D92AFE5D196ULL
        },
        {
            0x0C0633FB628EC559ULL, 0xAD74E38376B9174CULL, 0xA55F677CEAA14A6EULL, 0x295D06D35496B063ULL, 
            0x21C0F51B3FF3A05DULL, 0x39EE966343CB68F6ULL, 0xDA5360A00466A4EEULL, 0x30AE8314474E8935ULL, 
            0x067835D5D61D2BA4ULL, 0x7F22F99602E5CBBFULL, 0x2A07614ECB9FF8C7ULL, 0x1A1792C3AD14FDFCULL, 
            0x0B3B8F041EF47209ULL, 0xAF8D11695A037BEEULL, 0xDE4B9AA901E5EDDAULL, 0x909B69F848D25F56ULL, 
            0x365D793ACED630A7ULL, 0x70C6C27E169858B8ULL, 0x844FFFF59859B716ULL, 0x2061EAAB6C28E8DAULL, 
            0x7E09FC9E98B9F876ULL, 0xC2EB56A2498BEE98ULL, 0x6C0298DD70A7EFACULL, 0x388D0A48DB0BB316ULL, 
            0xD67A26E7F496FBE3ULL, 0x6426C9786D34F080ULL, 0x66BB763D5E250D3BULL, 0x8018F1D3A9C8A8BCULL, 
            0xAE5E4CCE874E9C75ULL, 0x83A2B5439B643A57ULL, 0x54F2F743076593B6ULL, 0x2BD7B9EB0C2F36C4ULL
        },
        {
            0xF2086280FA0E3342ULL, 0x03D1C644656FB48BULL, 0x8F1FBF16656EF24CULL, 0x39124E1D0A940E87ULL, 
            0xDBAD7C5179F41ED1ULL, 0x32202565089621FCULL, 0x4D6B03BD4649BBB9ULL, 0x6D816BA77FF0A08EULL, 
            0x97E1C601D3882FE5ULL, 0x4B6B9128CEE0DC78ULL, 0x340438488B7190A8ULL, 0x7EDFA1453188F334ULL, 
            0x9EBE36AFC98720ADULL, 0x5123098FDF22046CULL, 0x8D58B38834C5F542ULL, 0x840A8972C1A37D91ULL, 
            0xE466BC95EE688B1EULL, 0xD3236D4B965D0E73ULL, 0x8A5405B0496F4B02ULL, 0xDFC92B074CDF8D50ULL, 
            0xEF4A99DF5F64F078ULL, 0x178E8A6C0DFF64B1ULL, 0x8A32B5335E8ED7E0ULL, 0xD4733161BC379B3FULL, 
            0x769E4E1445D7B58FULL, 0x15133B6CCD1D6512ULL, 0x8B256FAB86B2B3F2ULL, 0xFD6A657FE1688D29ULL, 
            0x12C6C32C79274890ULL, 0x6C006BD24E0A1BABULL, 0x6588A88920AC538FULL, 0x038165BE9FDA142AULL
        },
        {
            0x9348A27F4997EBB3ULL, 0x8064863CB7189377ULL, 0x02AD0E76D40819C2ULL, 0x95344291EFB6ACB8ULL, 
            0x80847AD35D8731ECULL, 0x484D171919D9359EULL, 0xB88411ACF2CD6D9AULL, 0x00B4CF1BCC058031ULL, 
            0x62298EC6EB2F950DULL, 0x02DDAF35C5CE8813ULL, 0x86847CB1D47EBA12ULL, 0x4604CF27BBD22031ULL, 
            0x8DC7CF8ACF8E9683ULL, 0x71855C8BDFBEFE13ULL, 0x7993FDD619D552EEULL, 0xA6645EE76C27B8A0ULL, 
            0x9CEE3ACE08569E63ULL, 0x4DA0497D84F540E5ULL, 0xDAFC021C47A48505ULL, 0x5DFAE450AB3AD30EULL, 
            0x8E3F4EFAACFBF352ULL, 0x23DE8040845A19C9ULL, 0x8696693D9DF87176ULL, 0x372973EC9E888E4BULL, 
            0x035B8F821A747ECBULL, 0x11C559E49877B956ULL, 0xAED4947E35F0AF26ULL, 0xC41FAAD484B552E3ULL, 
            0xF66F61246A4778F9ULL, 0x7175E8F0820FD894ULL, 0x5217FB6B7B5361BEULL, 0x28AA0C183D86850AULL
        },
        {
            0xA842BEF7DBB4D505ULL, 0xF074F79EFA297444ULL, 0xC1114411A36B32ABULL, 0xBB3A449EB16C0CB8ULL, 
            0x46807A63D3D4FF59ULL, 0x0F159537EE75FC89ULL, 0xB0AFABA34F6848F2ULL, 0xACBFAE6F9F00F925ULL, 
            0x98D9D2F8A45D52E3ULL, 0xB738CAF1B32999C5ULL, 0x9B7ACEBF59E5DD79ULL, 0x38C1C6031916A005ULL, 
            0xBF27CD732267EEC2ULL, 0xF31125065CFAF73BULL, 0x29B5F1CD796B5119ULL, 0xDCD7C6608913652EULL, 
            0x295D386D0C65426CULL, 0xC321C00C4319CB7FULL, 0xA8547F24D365CDABULL, 0x1D88FA4C2DE4ADFFULL, 
            0x3F0A941712E02A5CULL, 0xB4F817ABD1C5BD39ULL, 0xACEABC0E636098CBULL, 0x13626DE881D123CEULL, 
            0x4FD951EDB6227BF4ULL, 0x1CDA8E1EF9268B98ULL, 0x3C886EDAE35BF480ULL, 0x4C603E1D383B701AULL, 
            0x8786DA17FEB76F1BULL, 0x8BF44C8F786726B7ULL, 0xC25609F53FF596C1ULL, 0x75290C0EB02EDBB7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseAConstants = {
    0xCA2A86FCF3DDE01AULL,
    0x2EE443E260E62F07ULL,
    0x499FFBBBD011B4B8ULL,
    0xCA2A86FCF3DDE01AULL,
    0x2EE443E260E62F07ULL,
    0x499FFBBBD011B4B8ULL,
    0x637089FD077CF933ULL,
    0x4DCB519F541C44EAULL,
    0xA1,
    0xA3,
    0x8B,
    0x09,
    0x2B,
    0x68,
    0x4F,
    0x81
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseBSalts = {
    {
        {
            0xE704A2EC85FFBC72ULL, 0x558FB80C6FD56CB4ULL, 0x8BB43E076AFEFECBULL, 0x76A1423599B47B14ULL, 
            0x7E0B5212B9CCFD02ULL, 0xCF6638087AA1386EULL, 0x137A0CEABCC2314DULL, 0xA525CE34FB8F5086ULL, 
            0xADB655D3975EAC63ULL, 0x8ACA9DB37708ECE8ULL, 0xE5CBE73F60F3C68AULL, 0x5F31BE81FDA36FE7ULL, 
            0x65D3AE26BC72FA15ULL, 0x5B95C3DFD5768720ULL, 0xEDB97AF5177C68C0ULL, 0x59BDBCC0D8389E16ULL, 
            0x5CE5E64CC5A2023BULL, 0x822929A3C9B8C0B3ULL, 0xD6CFC9BA10528D6BULL, 0x87DC975708B02F23ULL, 
            0xEA629C58E1C39F26ULL, 0xCE0EB8CCD1D2CDEBULL, 0x1FAF457977EC6F57ULL, 0xE28ECAA2E77CF05AULL, 
            0x8CC9B2F96EB67D07ULL, 0x4892B7AC01438A93ULL, 0x22B654D9BF67C86CULL, 0x19F30DC3C66025D9ULL, 
            0x9E654069F98639DAULL, 0xD092C0968CF71CCFULL, 0x7271341301040D63ULL, 0xCBFCAEB2A282A5CEULL
        },
        {
            0x4CFB66C532F9579BULL, 0xD08C07C6CAFFED1BULL, 0x137BFB4702ECBF95ULL, 0xF3D5A3C4E7F58460ULL, 
            0x98C450D0A7A0877BULL, 0x0D05A6D11DC36DCAULL, 0x64E0D8A817926CDEULL, 0xF0CFBD5AC91FF0C4ULL, 
            0x7362814B1EA5BC4EULL, 0x18CF1983B39A489BULL, 0xA39D60CEE11C828DULL, 0x3EAE721D4EE0A692ULL, 
            0x460EDB50E38C4F4BULL, 0xF70324B1FFACF220ULL, 0xE8D698C3ED09AE66ULL, 0x98CB8C42BA03540FULL, 
            0x24133B35B627B238ULL, 0x2D09B91680044C77ULL, 0x4DE2237FD1712564ULL, 0xC598344A788A3E5BULL, 
            0xB12763B90DCBD4D9ULL, 0x96FED3C10480DC36ULL, 0x7B0A1520A7B160E0ULL, 0x402639DA0B8D6E97ULL, 
            0xBDC45E9B41D9AB54ULL, 0x4CFABE8ACAA9B2BCULL, 0xFC3091CA0EF48FEAULL, 0x1115CD96822D3A12ULL, 
            0xFFD59576BA26082AULL, 0xC0995D374B05CF53ULL, 0xE55CD607153A036BULL, 0x1A4357D57AA54901ULL
        },
        {
            0x6019822845BDDA82ULL, 0x57E63897406FB000ULL, 0x15F66388CB3D0851ULL, 0xDEB2C91A683E9C5BULL, 
            0x92D4470670679D6AULL, 0xB8E5786DA37C442CULL, 0x13FBD7F5E9BD59FFULL, 0xBC93AAE3C52B1308ULL, 
            0x45597B83262C28B1ULL, 0x94142F6CCB918BE8ULL, 0x308434E2B9137762ULL, 0x792438555BCD6A57ULL, 
            0xEA14E78D28A8E442ULL, 0xEA2F3F26F65EE63EULL, 0x47390E9AC4A1EAF3ULL, 0xAEACFB02913DB0C6ULL, 
            0xBC5BD3BDEB6454E9ULL, 0x931F947DBE7AC0D1ULL, 0x0438290B150BB747ULL, 0xDB1CE31314E72804ULL, 
            0xEA267E6C32CCB94DULL, 0xE84E1D80B04710DDULL, 0x3ABC2C8F7CC58AB2ULL, 0xAFD1C192AE023F83ULL, 
            0x8BF318A9E8096B91ULL, 0x7EB515AD53225F78ULL, 0x75EE386BCB91E1EEULL, 0xF308EC3316EE0DF6ULL, 
            0xF7D77962DF5CC40AULL, 0x8E59EC8D76EE3F47ULL, 0x9B838B5ADF4FA012ULL, 0x2BFB8B12D0A15972ULL
        },
        {
            0xE83037B066E267D9ULL, 0xFFA7C81FB25EE8EDULL, 0x0EBD376CA634BB2EULL, 0x7406375681DD29B9ULL, 
            0x5396E806FAA21477ULL, 0x135893700B3CB291ULL, 0xB1F53567B883C166ULL, 0x3218450A7F7F73FDULL, 
            0x0C7C221D24DDEA25ULL, 0x5CEFE9A35BE2BD9BULL, 0x2C9C3407A36314F8ULL, 0x699CCF46A7A9C6F5ULL, 
            0x34760D07F6F4D0CAULL, 0x91F407B574D2D9CBULL, 0x5966E152F0FEED82ULL, 0x4FA7AB9692F1C0A5ULL, 
            0x6513B2774F542F98ULL, 0x130CAC1905715047ULL, 0xC1D9A7243B4020B1ULL, 0x53521CA4341C42A0ULL, 
            0xDC5C428F898D3066ULL, 0xFC9642BC5FF97643ULL, 0x28758B07784E6AA6ULL, 0x1F712B29395EF93EULL, 
            0x2C3F5CE17F0FC5A7ULL, 0xEF1F634C45F5F855ULL, 0x5BD32A5740C921ACULL, 0x2C824E2D19FAF930ULL, 
            0x14E1661AEB54AD0DULL, 0xC946523BA4B1D09AULL, 0x3EA52FDEE09D9E0AULL, 0xA35ED2AE22D03B68ULL
        },
        {
            0x17C4EC64DD4C02B7ULL, 0x9BDDC92902AF54A7ULL, 0x2951F196EF86EA0AULL, 0x1908C1A19E658122ULL, 
            0x9A880BC9126C55A6ULL, 0x8988A37AC5138603ULL, 0x778EE4B232DEAE6DULL, 0x907CA47472DB83ABULL, 
            0x26BFFE822AA73FE9ULL, 0x1CD2F93BA9DA2251ULL, 0x93DF4D20DCF1E5B6ULL, 0xFF0A1568DB42762DULL, 
            0x1490658F791B262FULL, 0xB47DB7EE3D4D52D8ULL, 0xF25171825D6253D9ULL, 0x65743323A0775A4CULL, 
            0x300F38090652FDD9ULL, 0xDB8A2F6F3556ACEBULL, 0x87C25603FB7323F3ULL, 0x575CFD4AF01D903AULL, 
            0x6D2246A748151053ULL, 0xACFEED9ABD2D5ACFULL, 0x773C90F766CDA735ULL, 0x19B7F8A22BCE914AULL, 
            0x55023BA7FF6E70F5ULL, 0xBF83F2CAC90569BFULL, 0x95D48D201A8C54D3ULL, 0x505B063F022CE192ULL, 
            0x3A5C02D908447A28ULL, 0xF8EB6CA908E5B14FULL, 0x357ADC4B1BD17C91ULL, 0xB4F009FCC1A09782ULL
        },
        {
            0x190ED2FD26F7ED8BULL, 0x6EFFEA2A26F82D27ULL, 0xFD6F1E2B15F82E3EULL, 0x5ED677049D5AEB8FULL, 
            0xAAA547CF81B630AEULL, 0x3D46AA8A161D08A4ULL, 0xF7B779C40393BD7AULL, 0x800F451FB200E252ULL, 
            0x02FFC8AA9F507FA9ULL, 0x9123B7C8473BA0AFULL, 0x57F494DB5A195719ULL, 0xE9221B55475AC414ULL, 
            0xBB1E6B1E25347C6CULL, 0x890F5BB6D322B57FULL, 0x06635B527F85CE93ULL, 0x835B57608E63EAB4ULL, 
            0xED236219D59653B7ULL, 0x543CB3F8EBC568C8ULL, 0x7D1D79581E3EFDC6ULL, 0xF35598E8300BE636ULL, 
            0xC6F4C1A7C8DA2D88ULL, 0xC8C4836710F80DADULL, 0x3C6C363B38BA3CEEULL, 0x579359AB0B668894ULL, 
            0xD4C407D2D5D29AC3ULL, 0xF0E57AB213357AFCULL, 0x32A082E845FD9334ULL, 0xEEDD1A0973F7ABD7ULL, 
            0x4D8FD4951F0C6892ULL, 0x5A8166169A664A40ULL, 0x60B6F03FFEB6B903ULL, 0x91A5BDCC8BFFDDB7ULL
        }
    },
    {
        {
            0x0A94A4B3F9D9069FULL, 0x01F3808D9A26C72DULL, 0xA3211E8A03D1342DULL, 0x0784A5170CBA28DCULL, 
            0x86B6DBEFA70C19F2ULL, 0x36C689802BD698E0ULL, 0x347C97F67E84D3CBULL, 0x192DC61C8D73FE96ULL, 
            0x2E1A9707CA81854AULL, 0x94496817360724D2ULL, 0x72B634985DA8906CULL, 0x333779F0A5D3F2C1ULL, 
            0x60D347F05B6C739FULL, 0x6B4311D069F7997CULL, 0x2B2A594ABEE3079EULL, 0x1F299B1E6EC288ECULL, 
            0x295A201A6609421CULL, 0x00F1C1443529AE65ULL, 0x23EE6FA371F00D46ULL, 0x5117CA1AA8F26BA0ULL, 
            0x70B08BCAF3008792ULL, 0x5665A158C392256CULL, 0x1CBE382BCB53B44BULL, 0xF4ADC670FC923937ULL, 
            0xAE192F781321A001ULL, 0x6461DE1FCA950FADULL, 0x7DBCAB28E913E5B5ULL, 0xB968C84F96AAA1DCULL, 
            0x5A80CE9E0958DD4BULL, 0x0A89EFD20B0C0A8EULL, 0xA0380A8353BCA52BULL, 0x2E21F36A1A9E66C7ULL
        },
        {
            0xCEF3B4771876D3B5ULL, 0x723FC70A3914F03AULL, 0x68CED7AFFF809C56ULL, 0x48764D9E21E91014ULL, 
            0x0EEE0B39B0AC3937ULL, 0x3712DCAABDD3C9CBULL, 0x51801C73915CC330ULL, 0xC854B5095F4AB05CULL, 
            0x9849BC9042324486ULL, 0x1CFBAA37A871C007ULL, 0x765EB8A85ECA1BC4ULL, 0x261874C1A9957620ULL, 
            0xC5AFE130C750683CULL, 0xEE386AC963786FE0ULL, 0x6D874ECC6F57CFA7ULL, 0x9BF247938B5DEDA5ULL, 
            0xA2B63747E874CC43ULL, 0xBB966ACE05741E4EULL, 0x8156C4AE1391A223ULL, 0xECAEE28D902688F9ULL, 
            0xC6B258F5763B7C31ULL, 0xC8A10DA7BAD9780DULL, 0x6156E7569D93261DULL, 0x9134BAF564626D6AULL, 
            0x296ADD79B1902FCCULL, 0x539FEA3DE6E58400ULL, 0x7FC5793DFB01BAE7ULL, 0x3B71468100ADBA2FULL, 
            0x54AF5A81D0EA27F2ULL, 0x7574427B692B4171ULL, 0x2833537A21E795A5ULL, 0xD7C5D25CC6EDC075ULL
        },
        {
            0x0E23BA345D4D3C07ULL, 0x2150E1763FA1AAFDULL, 0x6A3FAF5CF2B3C3A0ULL, 0x4605CA2C77EA978FULL, 
            0x2D55BDC608ADE75DULL, 0x7A74E7F311F713F4ULL, 0x520127926B440FB3ULL, 0x7A7F3C00BCAEFDE9ULL, 
            0xFCEEE68DD909C8F8ULL, 0x126ADD4CF561BC2AULL, 0xEA74FEF23FFAECA3ULL, 0x8B833C961D758182ULL, 
            0x336BFC6BC39CC818ULL, 0xE2E3C59693C9EAA0ULL, 0x3144F0920E45C49DULL, 0x9CED70AA749807E7ULL, 
            0xC88D2CE94DF2660FULL, 0xE9C086EFFC1CC249ULL, 0xCF1C61359F733AE7ULL, 0x8F57CB7E6542A2E1ULL, 
            0xEE32A6EB2AD6AF9DULL, 0x74B332D08E142908ULL, 0x29ABEB6D91383B74ULL, 0x6CCF427BD60A405EULL, 
            0xE0493F91FFC114CFULL, 0x4DA04E7F7E92ACB6ULL, 0xFB7A68651F5B5D92ULL, 0x6DA114823081AB9AULL, 
            0xAF062B33F9EA3344ULL, 0xA823DDAE6F82D08AULL, 0xEED7A3DBE479C3F1ULL, 0xC4DC0154207CF48EULL
        },
        {
            0x889029401B8EBC6FULL, 0xE4FE7885C10560E4ULL, 0xBB46109E17FF6BE4ULL, 0xB0F13640EC2F78E0ULL, 
            0x4F692616E75C1511ULL, 0x46F9D21BFDC21AF6ULL, 0xE766254C0F6A57A5ULL, 0xAC8774F27584794BULL, 
            0x530AAC3E2C975249ULL, 0xAC838374E0F2D89FULL, 0x49F999782FF3323EULL, 0x8EBFECD06EBC9BC6ULL, 
            0x27D7F306121A0B96ULL, 0x129C7CF8DFB4BBB5ULL, 0xDDE8FEC088E11B19ULL, 0x7A69E473EEB141D6ULL, 
            0xD07B0F6D18D21935ULL, 0x324E7A0A3C4C0803ULL, 0xBAC92307D9E66B58ULL, 0x76BAD98305FF7479ULL, 
            0x572E21CE758127E0ULL, 0x4723656473495580ULL, 0xC2A35CB713D01827ULL, 0x4CA516D14C7FB498ULL, 
            0xD01E08AE789D771EULL, 0xD36F7C8F238D0462ULL, 0xE1A555ED9AD35CF0ULL, 0xFF3EF4FF20B69819ULL, 
            0xB34A2433AF77A03FULL, 0x1528555F1B577447ULL, 0xDC3AAFFDA9595A50ULL, 0x11D192331C7A3D94ULL
        },
        {
            0xEC118B400A267F11ULL, 0x8FB628ACF1565A84ULL, 0x7648FE099468EF7AULL, 0x3BFE210C142CB621ULL, 
            0xDCB1DB8866C1AE80ULL, 0x8052BF38134CEF12ULL, 0x3CC0914B92F463DFULL, 0x2EAE65C6C8AA502FULL, 
            0x30BE66B7B316FDA9ULL, 0xB9726AAF98810668ULL, 0x69C14B1B73455581ULL, 0x8EE05450A1DF5E6CULL, 
            0x81F25580B552B13BULL, 0x15ACDD20D20C6376ULL, 0x9B997C029B6E7875ULL, 0x8DDBB1259CC4E1D1ULL, 
            0x441BBDAF506F346AULL, 0xCCAAB5E798D5955DULL, 0xDE8F3C2C763CA02AULL, 0x9E6A2FEA143219C9ULL, 
            0xCF3522AEECC72F9BULL, 0x92403C102F836579ULL, 0xD24E3E6AB0F01069ULL, 0xE3BA59B2D1CEDCEAULL, 
            0xCF9265690D43C0FEULL, 0x7AE1547D48CB5073ULL, 0x0DD5D60AFDCDF248ULL, 0xFC3552721EA1D542ULL, 
            0xA1B8992DCE4035DFULL, 0x0D0D800A16FD81FFULL, 0x8D35C7BAA7BC1A92ULL, 0x1A7F1B29BB189691ULL
        },
        {
            0xBCB6F206D4D14C1EULL, 0xFBC26908B163FC9EULL, 0x22F14F0CFFF3D4F4ULL, 0x865923DD2C60C73AULL, 
            0x45D1A627D18BDCB0ULL, 0xC593AB3017D0543FULL, 0x8B57AE2979DAE6D9ULL, 0x698045344D058B1FULL, 
            0x6BEA48849021FDC8ULL, 0xB4C0C1CAA2700418ULL, 0x3AB59EF21F64F9D6ULL, 0xB67585B00ED2EF6BULL, 
            0xC4F980C14CB76B02ULL, 0x679E66B914D9A32EULL, 0xA08233D1CA0C4B4AULL, 0x2D879731C33F321BULL, 
            0x9F6316C7775A3F36ULL, 0xC58B75EAFABE2DCDULL, 0x925DDAA5568B307CULL, 0x0F37698DF91B8412ULL, 
            0x5B214BA8E0ED4B6FULL, 0x35C801B28318A545ULL, 0xD3D34F2191E6B331ULL, 0x3FE61CC3FD8C2621ULL, 
            0xD754C7124C2643CEULL, 0xBBD372D3ECBB7D5BULL, 0xD1289268C87CB26CULL, 0x8D4119E004DD9968ULL, 
            0xB4D2E09F5C64DD74ULL, 0xB5B6E5B3222F7E3AULL, 0x04A3B59EE211BE26ULL, 0xD39181022314E7ABULL
        }
    },
    {
        {
            0xEE1B6165D5CB5EB2ULL, 0x8533C6A22378C52AULL, 0x1B76C748224C07F9ULL, 0x24253884FC337A73ULL, 
            0xA6C5398358A2F883ULL, 0xA7FFFD1CD8D8DF25ULL, 0xFB413D6E559EE470ULL, 0x7B477B3BDF8BAAC7ULL, 
            0x27614C7AB0C9C3B3ULL, 0xB8B11A674E5D3D47ULL, 0x5AC8B7623DA7A1C8ULL, 0x4DA396D8EB96F702ULL, 
            0xAE6823D797B88D03ULL, 0x47B1AD75BD2E7410ULL, 0xBB4055352E1182D5ULL, 0xF7216581DE00917FULL, 
            0x19E85C7B62B7D457ULL, 0x983CF81A27CADB43ULL, 0x0BE2497006947741ULL, 0x391004D82EE67106ULL, 
            0x4BC6569556E114CBULL, 0x0C0A7EFE895EBCD1ULL, 0xF9C3F2CE3FFE3BF1ULL, 0x584FFB030FA3FECBULL, 
            0xF036270BA8F3910FULL, 0x776AE1B36D208938ULL, 0x18F738354C969AEDULL, 0x75FC6E90CD1DFA2CULL, 
            0xC8DD7F282A83D494ULL, 0x8A28ECF681FD8385ULL, 0x515F24DBC49F2EBCULL, 0x04886DB74D2F8C35ULL
        },
        {
            0x0A00F3D0DC43A005ULL, 0x65E4DBE48C41F550ULL, 0xF9FD8E34569B37F6ULL, 0x713BD905B697DAF7ULL, 
            0x12B4A2F8382FF3B5ULL, 0x7C0EDEAEC11FD31DULL, 0xB6CBF0A91FE7ED1AULL, 0x660BD1C93A3AC4C9ULL, 
            0xBD9359016F74E272ULL, 0x8E888C4078A99581ULL, 0x74034E2E14B185FFULL, 0xBD4E3CAEBD1DC50FULL, 
            0x0048C777540A2BACULL, 0xAF8B3162DFB474A5ULL, 0xDE4701FDD9F845E7ULL, 0x1317934EBE5FF499ULL, 
            0xB3E28C99342E3642ULL, 0xA070CA39DA236C6DULL, 0xD3839F8E70093A9FULL, 0x23E7955872F6BB45ULL, 
            0xB3586AE0CD78AF7AULL, 0x5A86520A904E8325ULL, 0x3D1F83AF34CDB4AAULL, 0x766FB03327DF4395ULL, 
            0x48356C4CDA22366CULL, 0xEA4B2BC803B8749AULL, 0xC42BFB309530B8DCULL, 0x37120C8D9FA78D55ULL, 
            0x7D8B2901C3B9B532ULL, 0xC3C7DEC63ECF9641ULL, 0x9502D2F6D5A0750DULL, 0x88C200AB58FC7FDDULL
        },
        {
            0xB755CA8DF787ED98ULL, 0xF313857B6723E492ULL, 0x416BA7D6D5D68AF2ULL, 0x83FB8E3009D0F6CDULL, 
            0x2682DF92F236F3F9ULL, 0xE8DCAB230A16EB22ULL, 0xDA0E682B858BDED4ULL, 0xFA3440B459D8E5D1ULL, 
            0x54461469602952B4ULL, 0xAA67038E72F06879ULL, 0x969268B04B350197ULL, 0xCA84DA30FA92B3ADULL, 
            0xC2FC424D62C04E87ULL, 0xE8CABF614633A56AULL, 0xC0C57410C41D222CULL, 0xC8BA701B2C55F0FFULL, 
            0x89B3187C229BE751ULL, 0x05FD9A0D36541CA6ULL, 0x8D7390F2620A508CULL, 0x8A0445AFBFE85ED6ULL, 
            0x35EFA6797EB9D589ULL, 0x7E3B246504BD84A4ULL, 0xE20B637F48F96088ULL, 0xABA9897ACC99E759ULL, 
            0xA0BF928C651C4AF8ULL, 0x1A67F12774B7C838ULL, 0x7924F60D05F2579AULL, 0x6B6DE0CC90B6452AULL, 
            0x46AF0A5B814755ECULL, 0x8396426798EFD501ULL, 0xB91A1DD36DD93D7EULL, 0x5592FC5C313DF0C0ULL
        },
        {
            0x8B521BF6E6BAD650ULL, 0x467C616FCC3E5C42ULL, 0xDF18C230F55D6108ULL, 0xC3506551CD13B038ULL, 
            0x2DA1557F1BDFD835ULL, 0x09E942D446084AA2ULL, 0xFF9C45D2B3BAFEA5ULL, 0x46FF279AD988ACF2ULL, 
            0xAE37225745AA5C22ULL, 0x0B380C512A11E77CULL, 0x1E95280AC0818583ULL, 0x9D5B35FC457F8005ULL, 
            0xC5DE92027D57C039ULL, 0x0C324EFE2A12453AULL, 0x53763D1BCBC196ABULL, 0x8F796B591265EA6BULL, 
            0xAC53D152DE9EA8B2ULL, 0x8A3372C68F242280ULL, 0x8B9F86D7804385EEULL, 0x07D7B7F44EBEAC6AULL, 
            0x25EAD8EEFCF7BC87ULL, 0x63CA5D89B3A99451ULL, 0xA1ABB928D31508BAULL, 0x7627B6DCF0E14DAFULL, 
            0x91096A5D37B9020EULL, 0xAE871BA1656D5BB5ULL, 0xD825DBBA8C60DE8EULL, 0xC2DAEE4083C38D9EULL, 
            0x0691ED7BE7DDD2D1ULL, 0xEC755B0CD30BF29DULL, 0x3ABE69CF0EF9B729ULL, 0xD19DC595EF07940AULL
        },
        {
            0xCC436F914C40CB92ULL, 0x08161D474055FF24ULL, 0x903F3AA71DA02C7CULL, 0x8ACBE9D9D7B4DE41ULL, 
            0xBE677293110A435FULL, 0x6D59B3EF9C646118ULL, 0x8B92089E989F5BBCULL, 0x17C4FBDE06C58C29ULL, 
            0xD76E97E98D13C389ULL, 0xB3E97C7A5D710D53ULL, 0xD9995A225D0885F8ULL, 0x73B339424464C159ULL, 
            0x1CA66E84BB0D639DULL, 0x86CB657177EF3C11ULL, 0x4236D85BDB441117ULL, 0xBA40A93F2F665522ULL, 
            0xD5BC9BDDF9C6CA53ULL, 0xF6409D768C6A7C50ULL, 0x6D48001520E560EBULL, 0x5C0413E790BD46B3ULL, 
            0x421B0FCFA5625C52ULL, 0xECDA9B513385C1B6ULL, 0x17A3ED862DD7966FULL, 0x579D11BD0EA9C46AULL, 
            0x336D820C1E9A3439ULL, 0x5FB2D58D52F80D18ULL, 0x2C4DDF4EC81B30AEULL, 0x762878AD73248777ULL, 
            0x8963091FB23C187DULL, 0xEAC1952D77F16973ULL, 0x988B7DFC0F4B9ECEULL, 0xAAE7A9EF0D3CF65AULL
        },
        {
            0xF803A29DA6386F52ULL, 0x6D8A3A345B2F7AECULL, 0x8047CDB9175A112EULL, 0x1500E27AF60D12F8ULL, 
            0x7F6149F2260F6279ULL, 0xB9592A9DFDB8EE02ULL, 0x8AFB5513FD69C5C9ULL, 0x3AD88C50F0D64421ULL, 
            0x5DBB0C3B8B1FF627ULL, 0xD7B77BDF9042CE4AULL, 0x1EF730C2DCB915E0ULL, 0x1351342684F5C78CULL, 
            0xF7901C55940B696FULL, 0x8201C8B601C5218CULL, 0x3E2DE2FACB48FC03ULL, 0x9B906B29B552DABCULL, 
            0xA49F2703E63B9466ULL, 0x401A9F95284D2A8CULL, 0x1C9C0EA994D152A9ULL, 0x1B6BC8789020C188ULL, 
            0xB472D063827E8043ULL, 0xF9581D478FFD2252ULL, 0xBA42E1B1A3BE4737ULL, 0x1F0C4D9A31E511ADULL, 
            0x74F7F19CEA8EBF5DULL, 0x5ACFDD963FD058F6ULL, 0x80C929690AF3D82DULL, 0x0940253227F2CEC5ULL, 
            0x82CA055A0937FA86ULL, 0xE78EA23F7B96053DULL, 0x5914D0611194B1CAULL, 0xB3E84F3E89AF8288ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseBConstants = {
    0x717EA93BB7FFBAC2ULL,
    0x2E71D28268431A66ULL,
    0x8B222F5AD437A7DDULL,
    0x717EA93BB7FFBAC2ULL,
    0x2E71D28268431A66ULL,
    0x8B222F5AD437A7DDULL,
    0x1710002066757D63ULL,
    0xCCCE84B487DE62E4ULL,
    0x44,
    0x38,
    0xFE,
    0x10,
    0x0B,
    0xD3,
    0x02,
    0x69
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseCSalts = {
    {
        {
            0xBF1827B8EA98AA82ULL, 0xA6FA2B0D9836E029ULL, 0x43BAAAF0184BB091ULL, 0x39294DAD87358D4DULL, 
            0x345F3F8E67D1CF97ULL, 0x1AC32E2AA755B9CEULL, 0x4FDF26B36D6CD13BULL, 0xF7AB8F0B736BB649ULL, 
            0x38783CDB973DB814ULL, 0x5C3D8E314E93F464ULL, 0xA157B43ADD176425ULL, 0x697364EBF1BB2A44ULL, 
            0x4F81C4068CCB0B52ULL, 0xF1BF89D7C25CC870ULL, 0x807C8CD5CDD8E3B1ULL, 0xAFCA045AA0007518ULL, 
            0x6352EE7B663088EAULL, 0x74432795976CDCA0ULL, 0xF9644E3FB5654052ULL, 0x9666CBB165351675ULL, 
            0xA4D9DBB84F6E5762ULL, 0x74A460BF6D18D6D4ULL, 0xD1CDB9134DBA32B0ULL, 0xDA4C3A35EB88E65AULL, 
            0x3C5A01BA9D0AF0F4ULL, 0xE4C28FF97BC3B661ULL, 0x3EAD8D4E2DCC5349ULL, 0x3CBFB87328892F4EULL, 
            0xB75C631EC00F1A82ULL, 0xA3058B18B272832CULL, 0x16E490F5942AEC96ULL, 0xECB4F860DECB1CE2ULL
        },
        {
            0x2ED4D800770F1270ULL, 0xBA63E0E05AD2185BULL, 0xA3D236D5EF7A3320ULL, 0x056967D97456286DULL, 
            0x8D1B1096EBA801D2ULL, 0x8E96CCCAEC863691ULL, 0x63EB5D5A2A9C33CCULL, 0x9DF6E26BEC01A4C7ULL, 
            0xF2DB1F06AF858BB2ULL, 0x96BA83BF19B3B980ULL, 0x1E290734A50D1ABFULL, 0x1C379091B8FE2D17ULL, 
            0xD17F13B13804A000ULL, 0x229FAD735EEE4CFDULL, 0x80A0A3E2A976B961ULL, 0xB815BF1FAB5DC007ULL, 
            0xDFBDA592C5906598ULL, 0xE00409A3110C3ACFULL, 0x2291EBA6671E111AULL, 0x2C4F4546E0D76083ULL, 
            0x5C8B096F84D8EA17ULL, 0x48C7C62D576DEA76ULL, 0x670BF26D58732B48ULL, 0xEAC13DFADB1E611AULL, 
            0xE8788898C906C0FEULL, 0xC7EDDA2BC94D6009ULL, 0x7F398638A4C5F13EULL, 0x8C117E977F91B7E2ULL, 
            0xD5B8584CE3FAF2FFULL, 0x10B6D87BB0FB4E5BULL, 0x4E0E7BD5D681D90FULL, 0xE94AE39F79A1719CULL
        },
        {
            0x6FB06B881AFB5F32ULL, 0xA056EB2CAD85C16CULL, 0x1A57FA8E7D71AC38ULL, 0xBD6258764C566951ULL, 
            0x4FBB3E4A14B3C68BULL, 0x6657956A7C78CA25ULL, 0x499DF340E292BA90ULL, 0x67C4ED4535013423ULL, 
            0xD3129CEF52B95C44ULL, 0xBF1267C304445D87ULL, 0xACB641D591B76D50ULL, 0xCE54C29B425C50B6ULL, 
            0xCC41FB81174D0A1DULL, 0x1F9CCEE2028050AEULL, 0xC590B83076F61F11ULL, 0xB8D87D4F8CD8B0FCULL, 
            0xBC27AEF9BE44B7D2ULL, 0x4CF813A06C054931ULL, 0x47B035C38A4D7CB0ULL, 0xDB92C7193C642092ULL, 
            0xBE7AF948256E50CBULL, 0x446F6CB5236436EDULL, 0x2E223C5D1887716EULL, 0xA45E877CF49DC6F1ULL, 
            0xF7AEED3087A9CECCULL, 0x07F5DD7C1888D71EULL, 0x70AC02BA50633450ULL, 0x127ADB26BF7DBC7FULL, 
            0xC6C0B7B86FDD8EC2ULL, 0x6AF05097AED89BF3ULL, 0x4B3EBEE7655AB1DAULL, 0xCE95B048570F36F7ULL
        },
        {
            0x9981E2D964A02AA6ULL, 0x46E3C4D7AE9B9B27ULL, 0x87411F5DBA602BBDULL, 0xB555D81E660928D0ULL, 
            0x26F5674392BF6E7EULL, 0x187A51521C8F4C00ULL, 0x8F436A83EDD200BFULL, 0x4C2670F38FA676B8ULL, 
            0x567AA9A5D48B3C81ULL, 0x1C5638EB35EBB108ULL, 0xBE5895847941BEC5ULL, 0xD812572EB2F6F4DFULL, 
            0x6D6CA5183DD926A8ULL, 0x4353376A8495FDC7ULL, 0x26A655A07A9B6D39ULL, 0x8BA88766FC10382BULL, 
            0xD91E7B37CECA8D30ULL, 0x2433B4D55A7B1E90ULL, 0x3ECEB911CBB7AD91ULL, 0x33F7856145AE88CCULL, 
            0xF7C8917366652C86ULL, 0xD7D38BBE9F6DEE84ULL, 0x7C1C333DF03340DCULL, 0xCCC442E7C109DEA6ULL, 
            0x32CC9AEF54B08C2DULL, 0xC3CCEA914D41D6ACULL, 0x2A1120EEED34C146ULL, 0x43B2265540017BFCULL, 
            0x8D953E87AB4377FDULL, 0x5FA4A65B9EBFB9EDULL, 0xD583B300DEFD5ED7ULL, 0xAACAA44BD9B8E375ULL
        },
        {
            0xA69BAD479696E25EULL, 0xD49B1548C0DBB07BULL, 0xEF13B2294D7E4F86ULL, 0xD2C58A1386144FEDULL, 
            0x7FE51C03528E5027ULL, 0x769C8C89D98E9C5FULL, 0x256F7DE03A7EE070ULL, 0x17CC84D244ECB3FDULL, 
            0xEC9B4D963ABA970CULL, 0xBC11CD29F27345C8ULL, 0x567BF3AB2F3B47F9ULL, 0xFCC7BA5B0D525EE3ULL, 
            0x127EB38FE20941C9ULL, 0xD54328F1477715AAULL, 0x48317CC63E88D6EAULL, 0xDCBE62651326D433ULL, 
            0x8A91F3669764EDB0ULL, 0xB54850E5115EEF49ULL, 0xF15BB25EB2DB1B4FULL, 0xBFF03A8EB57BAD76ULL, 
            0x98F842FD50639645ULL, 0x31D50546D5168920ULL, 0x8181134A404392E4ULL, 0x27B71F870DC5E014ULL, 
            0x20D9C1573FD6CC99ULL, 0xABC2F6270E871AC4ULL, 0xDFB55C210451B7AEULL, 0x2DC9F05E3283CF5AULL, 
            0x591263CC0A03B2B7ULL, 0x641E6951E1E5E01CULL, 0x1C82D9B55AA22549ULL, 0x1CD2F0045E30D94DULL
        },
        {
            0x5C32BEDC17DB0377ULL, 0x46B8CCDA06ACD220ULL, 0xD590467A80439996ULL, 0x5A7DB45258F1C685ULL, 
            0x4A8824E3A25D3ECEULL, 0xACC6C13E28B1BC05ULL, 0x05A67CF173F8FB51ULL, 0x75B08FBFE989DEBCULL, 
            0x5C6FB32F00B618BCULL, 0x869FC7126F5B8DD6ULL, 0x484F641B1F68B252ULL, 0x92E4148A835AA3E0ULL, 
            0x52AC7C7FE12459ACULL, 0xD3DB9D722307F2AAULL, 0x9C81F2FD464D1BB7ULL, 0x739CDCE8B7E41C7BULL, 
            0x163D190310981F46ULL, 0xFF1EBEB2C3CEE17CULL, 0xEB069B716AA302B5ULL, 0x77D1EAD695C15855ULL, 
            0xAA5F9B58B21E924FULL, 0xE44727B4A78B173FULL, 0x43C079E150810C64ULL, 0xEF88ED93526940DBULL, 
            0x140174E5E29CCCACULL, 0x1C946D5C5AD4B1ECULL, 0xF1155583A445BDCAULL, 0x0BDED6C481D52C5DULL, 
            0x4382AF6D7C0ABBA9ULL, 0x9590C40360892ADEULL, 0xA15E028FAC8C492AULL, 0x6C5FE38B2C27B6DFULL
        }
    },
    {
        {
            0xAD237AAD90292747ULL, 0xADCE924C73EBE96CULL, 0xE721E2E4CFEED143ULL, 0x08B9757EBAF15D01ULL, 
            0x848330DBAFA93F16ULL, 0xECAB43487E3515E4ULL, 0x46F7BB4E0E747880ULL, 0x56E3667FD3BA6CDDULL, 
            0xD89FBF834340AB17ULL, 0x5FBB7A0BC7AC3174ULL, 0xECFD617526EB8922ULL, 0xD7C695C11215ABEAULL, 
            0x57D3E793B6366B62ULL, 0xE55A92F5D0330381ULL, 0x43CEECA72FA9C01FULL, 0x18AB1DAA2E751ADFULL, 
            0xA39D7402EF6B06DBULL, 0x1753F6651BBBEFFEULL, 0xD4614A40A99319C8ULL, 0xA23F3D6ADDBCFC93ULL, 
            0x1BCB17F2D1DE626FULL, 0x96C55242AFD10C04ULL, 0xB9B5A8DE6A09F6F6ULL, 0x0DB38EC0550B66ACULL, 
            0x4613128D7753EF1CULL, 0x990708EDB76EB7E0ULL, 0x448CB6F8081B95F2ULL, 0xBE711F0F0E42F6B4ULL, 
            0x76231617922BF3A6ULL, 0x3CF1EEE1E146A054ULL, 0x99BAE7DFB6D7E891ULL, 0x6B8056BFC28133C7ULL
        },
        {
            0x8A43385C438F400BULL, 0x9A6565E42E1E8500ULL, 0xEB3118637E5F161DULL, 0xD61C24BF4728573DULL, 
            0x344643D55789B18DULL, 0xB054C975DC430C67ULL, 0x5CA8C5F028AEC056ULL, 0x8D965A5BC01C3EB4ULL, 
            0x96B355C3F03CF521ULL, 0x97AD409CCD15C16EULL, 0x2D8D80E19EF00FE2ULL, 0x1885F9A03A78119FULL, 
            0x95BCC17CFC2F1825ULL, 0x8A0FD9E972DCCE13ULL, 0x8386A6C218EEBCE6ULL, 0xADE1EEA639AC35CDULL, 
            0x8190644F744AE0A9ULL, 0x3603EBEB06575503ULL, 0x052563A54A2269C1ULL, 0x85C97A0CE4D6B531ULL, 
            0x3401AFF793B128E0ULL, 0x2D5FD8D9E65B9246ULL, 0x41A385633E0D44B6ULL, 0x51CEFE09E963C62BULL, 
            0x28152A0F6A3FF4A9ULL, 0x1DDEDC5ADDC245A7ULL, 0xE7A9DF3AFD06BC22ULL, 0x1739E0E29227B2C1ULL, 
            0x1859E7EDB033A979ULL, 0x9ADD68940554C763ULL, 0x19E13B4F993C4A9DULL, 0xA07E6D3776B7377FULL
        },
        {
            0x71AB1B252282E541ULL, 0xD43166CF6B98AD54ULL, 0x0DAC6236CA3BE389ULL, 0x64FD2C00458C4179ULL, 
            0x47B5619F06BD1891ULL, 0x9F44234DEABD0423ULL, 0x52DF0CFB000B462EULL, 0xDC3AD87D126831EDULL, 
            0xC4A1222AE76F6CE0ULL, 0xB70968C567AC1253ULL, 0x68A719C3FDE30225ULL, 0xFC0D43F68B91385DULL, 
            0x5EFB0B284E8CF774ULL, 0x15159806BC8EAA0DULL, 0xAFFB4BB4908BD859ULL, 0x7FF67983BA6DC46DULL, 
            0x6C31D407EB8B2955ULL, 0xED7AD8467C5213D4ULL, 0x2E67F60FFBCFD29DULL, 0x04B36F5B2E1329AEULL, 
            0xD9AB1EAC73C22783ULL, 0x2BF40C49521B1F2CULL, 0xF5C58B10574BA386ULL, 0x7778036E42EC1495ULL, 
            0x20C6014A5807E6AAULL, 0x472B32A7CBD86E5CULL, 0xC37834B82D705CB1ULL, 0xA88BBC45A66F1A33ULL, 
            0x63CB07865F3AF30BULL, 0xA4B5ED3223319DB6ULL, 0x3AB3FA69C2126088ULL, 0x2A2BD4B8F5CBF7E0ULL
        },
        {
            0xB9BAE65A1ED40E4DULL, 0xF741B282D493A7DFULL, 0xAAB433CCFF73079AULL, 0xF8BC8D6CE5F74C9EULL, 
            0xD10E40C54F733348ULL, 0x86501ED3354B4F2EULL, 0xED0DEA720166AFF6ULL, 0x2728390D3910B312ULL, 
            0x2AADB58A044E0C07ULL, 0x37F2E180CBFF5A71ULL, 0x50A63F23231BB9A1ULL, 0x23837D00D10D1225ULL, 
            0xC87F486E624A68DDULL, 0x238C99B0324EEC72ULL, 0x935DA13F8EA6C48DULL, 0x188BA3AB4CAC5D37ULL, 
            0xD2A658608B0C58BFULL, 0xD166A56E849F7159ULL, 0xA3AB2FE31737EE6CULL, 0xA528997A78311B61ULL, 
            0xE898BE871C33D5CDULL, 0x71BE00D9702F7CAFULL, 0xB97F92F2273C0131ULL, 0x584210DBE7BDA9E3ULL, 
            0x6DB9F0B17D1E602BULL, 0x89AD836FE0DD9172ULL, 0x1CEE9EC3F6B417FBULL, 0x34DE471A96B9AD90ULL, 
            0xAEB252F1888AB568ULL, 0x00CAB081B3A0E3F7ULL, 0x7B6098BF91042C45ULL, 0xDC2188E40ECCD8BDULL
        },
        {
            0xAABAEF095710DECDULL, 0x1465914E24946F10ULL, 0x3C621EE250033ABEULL, 0xDDFCCDC15067FAB6ULL, 
            0xB877B383773FC97DULL, 0xD781E28A43DC4E17ULL, 0xA7F8B5A3B3F1E143ULL, 0xFEE055DAB91C5F89ULL, 
            0x24F6CFFBD05C3484ULL, 0xFD7432FB1A35C631ULL, 0xCB93ABA49FF88CFFULL, 0xDC5AE69453FD4390ULL, 
            0x0DF693EA0A0B4675ULL, 0xDA54D7205A138F3BULL, 0xC2D560BD4750B4CCULL, 0x481128A2C8E99420ULL, 
            0x4919602129BCA69AULL, 0xE7DDDB10DC21400BULL, 0xAE3BEC5AF23794B9ULL, 0x9873D4467B9FB5D4ULL, 
            0xCF534604A46672D4ULL, 0x53BC4109B77200A8ULL, 0xE3C86EE40350C6D8ULL, 0xBBC6D3BB2C661EF5ULL, 
            0xA11EA550A9697789ULL, 0xEA574E41CC80EB33ULL, 0xDE160510CE4D7122ULL, 0x1CCAFFFBB27C08DCULL, 
            0xE0FFD1A095FA64BDULL, 0xAF29E5D670CB5111ULL, 0x924A1B23404226B5ULL, 0x6AE1226D4216630DULL
        },
        {
            0xF1A8787E07E70F34ULL, 0x987A070825F3A45CULL, 0x24C7024898363896ULL, 0x0CB97CB9B75BD721ULL, 
            0x36D159C0C1010BD9ULL, 0x4F399E254C2CE12CULL, 0xC829A32ECEFE47B3ULL, 0x75E719ABDA2BC350ULL, 
            0x739B0312E468CC5BULL, 0xA746A5A20F8A58C8ULL, 0x33CCAC487CB2FD6DULL, 0x2787863292CC3C82ULL, 
            0xC671C1168B104CE7ULL, 0x8195BF3FA50F8335ULL, 0xB59B434717FBE54CULL, 0x266100B9E8703DFEULL, 
            0x7B7A59F8DCB296B7ULL, 0x586032992DC09275ULL, 0xD43F81A722A3756AULL, 0xAAAB7348F5935D52ULL, 
            0x039F8CF633B9647FULL, 0x66DE33AEF5F1B874ULL, 0x41329629B3B0C545ULL, 0xA9344B54F7483FBDULL, 
            0x10648F8FA03CDD98ULL, 0x6782CD489B3D83FEULL, 0x19374047D24180ECULL, 0x891179C802B756F0ULL, 
            0xA2748A5870872485ULL, 0xB3ED385A93EBACD7ULL, 0xEEF937505C6A6A0DULL, 0xA1D8D4CAA8C70820ULL
        }
    },
    {
        {
            0xB2032FC843E0CC8CULL, 0xF9DA3D4DC363B809ULL, 0xDD85A5840F0C546CULL, 0xA85D6EB8AF65BB2AULL, 
            0xBA151D0A0E79BEE8ULL, 0x4CD939410820D472ULL, 0x7DCD7D00F299B00EULL, 0xFACD7E1A53ACE570ULL, 
            0xC4B322917B1A92BAULL, 0x69811B7921947EC5ULL, 0xC67DC04C3B803339ULL, 0xA7ACA6407F5C4CDFULL, 
            0x1BA56E005ADE61BEULL, 0xDC3D3373278A93E1ULL, 0xCD174072E50C6EFDULL, 0xE64560A8137B8A2FULL, 
            0x107B844B4B1DF017ULL, 0xCA1871FA56BEFC85ULL, 0x2FF7B02D565CC509ULL, 0x4F46B685ED570D3AULL, 
            0xBF97CD7CCCBFDE54ULL, 0x11082B048282F63BULL, 0x22288599E4CA876AULL, 0x767A6315ACC484E2ULL, 
            0xF453B3749EEBF9F0ULL, 0x44997585A026EB3BULL, 0xDF04E3D8A0F1637FULL, 0xBC57A7BACBEC646AULL, 
            0x501E671BF74D7FBBULL, 0x71BA5EA2C5A0395CULL, 0x3F869CD3E6D41459ULL, 0x4B97134632E55D65ULL
        },
        {
            0x2DC27660C3719296ULL, 0x1BA1307510FE740EULL, 0x924FF9B1571CC872ULL, 0xEF488751440516C4ULL, 
            0x0CCA49F80DA08052ULL, 0x84619F61A7786192ULL, 0x15FC7CDCFF210AF0ULL, 0x144141FEAFC34592ULL, 
            0xE9CBBA5D9DC1B68EULL, 0x6E40EEF7437CF60AULL, 0x8EB2ED8D17B34D6EULL, 0xC18D8938D436F6E9ULL, 
            0xFC8FDFE8DC86B113ULL, 0x8AC879A58C7B4F53ULL, 0x537B0A2FD761305FULL, 0x8D3FAA96182D19E9ULL, 
            0xA639CB2FB47892DFULL, 0x3BFB23BE651C292BULL, 0x39B063EAB2FD99D8ULL, 0x84D2026AE709AEC8ULL, 
            0xB02F8DE998E9472AULL, 0xE5C775994016C519ULL, 0xCC9AFCA9AE0B475FULL, 0x0C3EE3BEA6C67C42ULL, 
            0x8432ADBF30220468ULL, 0xA0C73D89B092480BULL, 0xBF914DB942839B85ULL, 0xFA3574BC08C9FB19ULL, 
            0x04CF8A118A01A1E7ULL, 0xBB4C18EBFE2AB550ULL, 0xED152DD1DCE7FCA1ULL, 0xA2DC96D90ECE3A31ULL
        },
        {
            0x8316EC5288D3C978ULL, 0xF425A9BD1CAC5563ULL, 0xAB03343B9E0D205CULL, 0x4204079A6459553DULL, 
            0x0F5B4ED461055818ULL, 0xDE1BFC2CC8939DE0ULL, 0xA85BA1580C417915ULL, 0xD4AD66D56FFC8303ULL, 
            0xD8155B54372E5997ULL, 0x65D443F70791743BULL, 0xD3BC3BB0E36EA1D5ULL, 0x68BD65C9449181EDULL, 
            0xE5FC2D7195195C33ULL, 0x2E90F490B8364848ULL, 0xB27014809446F2E9ULL, 0x804EC456303A5DFDULL, 
            0x99CB3D5754124582ULL, 0x93987AABE22F5788ULL, 0xC447CE0CEDE6C871ULL, 0xEF47DA622C982B6CULL, 
            0x01088001E8AB9BB8ULL, 0x1456B519CD5D61D4ULL, 0x068DC44DAA30DDC7ULL, 0x267D3A31097A1CF9ULL, 
            0xFE4E6EC4E69CEB22ULL, 0x91554F12602DCE35ULL, 0x12C0E97B8964010AULL, 0xCFA6D64D562296EDULL, 
            0xADF495D50A8DB1C0ULL, 0x2314E804C61E6B99ULL, 0xE0EDBD56D805F2C4ULL, 0xEBA45F8311B5FB9FULL
        },
        {
            0x8C42120A162ECE31ULL, 0x18E1DD4FDD1554BBULL, 0x279F9E1E54841B7AULL, 0xB79A7A0772ACC009ULL, 
            0x5DF4B7361B5C540EULL, 0x19FADF508D64090AULL, 0x8805CAFC379DFEE9ULL, 0x7C254C4EAB103B74ULL, 
            0xD899B201D62DD919ULL, 0xA2DB3835D1D12D59ULL, 0xE7D9DBA1EFDA911BULL, 0x882DAC2FE3D4FA23ULL, 
            0xE00A6AF913427CADULL, 0xF5C11E79D0FF230AULL, 0xA44EED0CB4AED5C5ULL, 0xED416C0669AE5A0DULL, 
            0x23DD286AC95FFC3DULL, 0xDFA84524F3A5B2FDULL, 0x779CD361CFB24FE3ULL, 0x9A7E4F25A9E64E95ULL, 
            0x3EC81018AF25A3E9ULL, 0x7A8F24EF2066FF25ULL, 0xF22801750559AD57ULL, 0xD4659EE8423B1040ULL, 
            0xD721A5C8B2EE1FA2ULL, 0x2FEE7C9CD0FB3F1EULL, 0x97FE4745C280CE6EULL, 0x0719EF181F4F12B1ULL, 
            0x3354F6B0C9DACF8CULL, 0x737774C14C6F7BE2ULL, 0x08CA2642A6D78D24ULL, 0x66E2709EEA870A62ULL
        },
        {
            0xAEA503C3A52CFFC9ULL, 0x0D2ECBCAFBAF9183ULL, 0x9D5D63383A3B0AF0ULL, 0x7D499782005697C7ULL, 
            0x7933BEF78D31128FULL, 0xE708D9E4FDF495E9ULL, 0x08DE1261727E278DULL, 0xA41D4A2F2F455C41ULL, 
            0x8A84A3F92180B4FAULL, 0x5236CC4DB07CC34CULL, 0xEB79F86C92EEF0FBULL, 0xED74A4DE71842CBEULL, 
            0x95B601737F60D15AULL, 0x12F49DAAB2FBE926ULL, 0x20060D03568CFAA5ULL, 0xA95EA6F0C02F3F88ULL, 
            0xDCE5BF5AF4E918DDULL, 0x66D337989FA997B5ULL, 0x59AB9ADB6A7431F8ULL, 0x4BD278476C1E9BDFULL, 
            0x1005BD0CCE470C25ULL, 0x4C64AE866D3079C0ULL, 0xC245D6C0D1E0197CULL, 0x5A3B7CC3EA6FEE32ULL, 
            0x092BB701C7DB8BE2ULL, 0x9EB12375C940949AULL, 0x0A95F40CCED24476ULL, 0x71AFE228D9702E3EULL, 
            0x3C5B3CB8F5B1E332ULL, 0x24975E1DD6271955ULL, 0xF610E6334A43CFABULL, 0x0B3BD77D3C24A6D9ULL
        },
        {
            0xC92938E5ADB5B165ULL, 0x76C30253EAE25740ULL, 0xBAC056A4C1F6A8B0ULL, 0x69B70DC62D509841ULL, 
            0x54EA9303BFC86B7BULL, 0xCF8997EFE0F2DE7EULL, 0xBFDDCF4483C08AD0ULL, 0x89E2B72E4CFD47CBULL, 
            0x8AE9E8294A270E06ULL, 0x9B4AD46A2E24C549ULL, 0x23067D5403F8C544ULL, 0x70D72323450E3094ULL, 
            0x783AECCB4348A611ULL, 0x23986D85FB0A91A6ULL, 0xD4239DEE7F749E08ULL, 0xA04EFAB272B0DA65ULL, 
            0x534BA5651E516AE6ULL, 0xAC942A78733894B5ULL, 0x43A1A91B61CFA5E4ULL, 0x00EA5AFB92F0047DULL, 
            0x3928C5EA1B564148ULL, 0x34ABACEFE1FD8CE8ULL, 0x515223CC0D001378ULL, 0x63C0F60C474F8211ULL, 
            0xC30B00DB557D4ED2ULL, 0xC10BEEDB7899ABF5ULL, 0x5F46262936626AD7ULL, 0x8B6E4E12D0112CA4ULL, 
            0x578DBF22BF824F56ULL, 0x278E41D08AFDAEFCULL, 0x671CBD0731DDB219ULL, 0xB2533772E4DC81DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseCConstants = {
    0x1078DA0E70947021ULL,
    0x5E3438E26CFB9448ULL,
    0x6534FD154398F967ULL,
    0x1078DA0E70947021ULL,
    0x5E3438E26CFB9448ULL,
    0x6534FD154398F967ULL,
    0x056DD0C46F375C15ULL,
    0x23FC2F7D6282961DULL,
    0x53,
    0x71,
    0x10,
    0x2D,
    0xB0,
    0x66,
    0x3A,
    0x10
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseDSalts = {
    {
        {
            0x8765753C4060640EULL, 0xF198054273DA6BF9ULL, 0x76454BF6D91C8BF3ULL, 0x3FECB80EB9057796ULL, 
            0xFE9B6C0C9DD5013DULL, 0x1439BB0072554ADCULL, 0xCCFCBA381BAFAECEULL, 0x3DA224BBFB7FAAEFULL, 
            0x81D08ADEC346B6C0ULL, 0x5DDF201521B4764AULL, 0x6108D02380225032ULL, 0xEBC4906008EF0137ULL, 
            0x5D0E7FC5C2CB5421ULL, 0xE8AFD234779D7E52ULL, 0xFD26843941335D72ULL, 0xE4C76DA636F81E12ULL, 
            0x68C16B37C79C6808ULL, 0xFEBF4666C5D1DF7CULL, 0x9C6838E6023C358DULL, 0xB95D8F3AEA46F13BULL, 
            0xB0C0E773D849F4B7ULL, 0xA066658EADEBF72BULL, 0x77DAD522AD4FEBB9ULL, 0x70B5520C23602CD0ULL, 
            0x22D33D9F2B9204ACULL, 0x9A4B28A3166671FFULL, 0xDEE51FAB7B6C3AB4ULL, 0xAC7BE9335AECFE9DULL, 
            0x2779B8A3D9FE1F8AULL, 0xEB491522D185E02FULL, 0x431CB8D6E813022BULL, 0x010399B30D4DC741ULL
        },
        {
            0x07A99FD4928BEFE9ULL, 0xCCB8E082B88DD4FDULL, 0x024507313519D54AULL, 0x7A4AF5FF7B0530B8ULL, 
            0x753441EEFA81FD34ULL, 0x78B5C4B62585D901ULL, 0x09AA279DBFA90B84ULL, 0x014EE1E5392B5200ULL, 
            0xEE7C422549306BE4ULL, 0x7529CB90D6693EC6ULL, 0x32DA72F187CF284AULL, 0xC12826CB5A60A2DBULL, 
            0x2A82E31223C888BBULL, 0x56FDEF0A7232187CULL, 0xB7B86B1C268267BEULL, 0xB89635BCAB404C9DULL, 
            0xC73D4B070AE636B7ULL, 0x8E1F531095862E41ULL, 0x51102C78160DE4A4ULL, 0xFF03D136C7A3DC4DULL, 
            0x82435BBDCA042A72ULL, 0x30582A917DA1B713ULL, 0x38FC88EF325A34A3ULL, 0xB6A966951FA96ACCULL, 
            0x81076862C532F489ULL, 0xC856F68A575F089CULL, 0x31EFB6F32E19A65BULL, 0x991ED02022B47888ULL, 
            0xC26C42ADD4E5359CULL, 0x8394E25D2AC568F7ULL, 0xBCE1D1C9F1AA4CB3ULL, 0x7B616CE01E036966ULL
        },
        {
            0x0870EBF9902366C8ULL, 0xCC356F896054EF62ULL, 0x584122FE5B36D1C4ULL, 0xE53CAC1A69F12963ULL, 
            0x045A52D5E0771966ULL, 0x1FAFA3B348468E89ULL, 0x325D97E170C72FEAULL, 0xE266AC76BBA04285ULL, 
            0x55DA1A16543C339AULL, 0x18E7C8E3229F1AF3ULL, 0x3CEBF43ACD758ED5ULL, 0x103AC0E368297874ULL, 
            0x46B3709C98AAC0D0ULL, 0xD02A956C04E43270ULL, 0x00DB0B25B457925EULL, 0x7B2115439BEE4C0FULL, 
            0x74DD4C03CA530AB7ULL, 0xF1112D78F1BD357DULL, 0xB3E862B2B2401EAFULL, 0x4ED171DA8469E676ULL, 
            0x9DEF0470C57603EBULL, 0x87015EC3A7DBD900ULL, 0xFBB5B7405854EBE6ULL, 0x7B319A65543A1996ULL, 
            0x84DC23A92D374A85ULL, 0x79AA5D4676A23A31ULL, 0xA2C7C85036F54DA9ULL, 0x92B0FA46824E30FFULL, 
            0xD1D817696606F8B6ULL, 0xBBB65E41507C97AAULL, 0x604380B61A59121BULL, 0x434C87BFCC0F3CD8ULL
        },
        {
            0xE47819C8330DFA53ULL, 0x6762DB6C7ABD9F6BULL, 0xDE4632EC85E9FC8DULL, 0x644DB24EB75F6F0DULL, 
            0x04696B8A7DEB7E82ULL, 0x78A99BE44EA29AD0ULL, 0x7BD7BD5573055152ULL, 0x2C2CEA71EF702F0FULL, 
            0xE17A8D67B08D7FD0ULL, 0x7255738762377367ULL, 0xFC2DA4A4687DF248ULL, 0x18D2C01D1D2DE2A7ULL, 
            0xA92ACDDCBA324091ULL, 0xEB741C56AFF05B38ULL, 0x61FEE7930C6353B6ULL, 0x82568F2656E39516ULL, 
            0xD90CE9C6A164BE86ULL, 0x5E63C8A38ABA9A98ULL, 0xDD56A01D6E3A032EULL, 0x6172D6BAC618E547ULL, 
            0x6C063E88AF0E928AULL, 0xFA1C9FC04D91F227ULL, 0xF1DA37081B01E816ULL, 0x40096D7761A3907DULL, 
            0xD53B7C8BB469BD88ULL, 0xED4D9FAE15DA7988ULL, 0xA502B085050B490DULL, 0xE78088A0647BD716ULL, 
            0xE029BAEF50FF20A4ULL, 0x1399162C50510034ULL, 0xE80571D61277743DULL, 0x10413C3C91A31AD2ULL
        },
        {
            0xC7FD11C4ED189D58ULL, 0x948ECFE3376E59C4ULL, 0xC78CD230D984F0F0ULL, 0xA41DAD995F9F6467ULL, 
            0xF8D8EB870452AA92ULL, 0x0E53036940842B17ULL, 0x1082722EF9930755ULL, 0x1C33B1087EA93C18ULL, 
            0x8DE9DE6E3CAF1367ULL, 0x2698F158EC6BEDD4ULL, 0x9C34726BA1FF9E4CULL, 0xB662D427BEBFDADEULL, 
            0x1BCC7DC251B15E06ULL, 0x060F0C278E57ADA6ULL, 0x5F386CC43775058EULL, 0x6AB3A5CD8372108FULL, 
            0xCDDC537918A9A37EULL, 0x3F1643FAC8A64CFCULL, 0x1404D3683109B0A6ULL, 0xA8CC111740E8C087ULL, 
            0xE72613515B8F2A08ULL, 0xAA88B91D669747CAULL, 0xDE959C3B41C1F9BEULL, 0x71731B1620159BE5ULL, 
            0x27CBBB9DDEA756A6ULL, 0x23513FEBB9C45CE1ULL, 0xED486924A531EDA3ULL, 0x8B39976BA6DB3C9FULL, 
            0x43E86D378E49000EULL, 0x69A68C62CAE01DE6ULL, 0x3095B55DADEC8817ULL, 0xD394D2615626173CULL
        },
        {
            0xE99387ADFF265731ULL, 0xE7989F6207AF1ADFULL, 0x4B1C93E6E611D146ULL, 0xDCC924EEB3DE80DFULL, 
            0xB67B19BA50ADB3EFULL, 0xD8D3ECAE745186F0ULL, 0xCD8EFAFE93E89902ULL, 0x3AB733DDC4A3996BULL, 
            0xD33C5031E4479F1EULL, 0x19AD5B860AF265CFULL, 0x63E62B96095D761DULL, 0xEEE3F11B7F9392E6ULL, 
            0xFA9BFBDFA869A1E8ULL, 0xB97320CB314A2EDCULL, 0x58C3E4E4B315153BULL, 0x05BAF50D7653B257ULL, 
            0x73C17C1274FF896AULL, 0x8F1BB114BCB88025ULL, 0x1646C1F6F7AA39A5ULL, 0x1E3119AEDFC43CFEULL, 
            0x0C7E47AEAFB0B599ULL, 0x83839D5049F20093ULL, 0x7FD9160828A08913ULL, 0x74855740621C39A4ULL, 
            0xC343BE873161EE07ULL, 0xA32BB56FCE3F8113ULL, 0xA27588C242948DC0ULL, 0x81CEAAF8453B85B0ULL, 
            0xED5B4A798E31EE65ULL, 0x96C4373B7841E2EEULL, 0xA2B90808252D3F10ULL, 0x8920806FA22028D4ULL
        }
    },
    {
        {
            0x2AD474C0144C8BEDULL, 0xC18835FE0DCBFFA0ULL, 0x0DED90E1CC42D159ULL, 0x6E06E745D987B91FULL, 
            0x8F9E1C3AA79144EFULL, 0x256354A539AA4BAEULL, 0x9625960CD4C95DBFULL, 0xEB6D6C8F6404DCCCULL, 
            0x7C6FD7F0DA737670ULL, 0xF598E642805F1B86ULL, 0xEEDC13C4AB24020EULL, 0xE4992862487CE724ULL, 
            0xD6E3D5DE01DCB515ULL, 0x85566D00A6FD9B85ULL, 0x5641A094C7821295ULL, 0x09D26A244A42E305ULL, 
            0xB98043495E80DBACULL, 0xD15B4A3131A791F9ULL, 0xAB31F1EC599499AFULL, 0x06256581D0137144ULL, 
            0x3D4840BD1367C19CULL, 0x7B8548B0375A6961ULL, 0x1877B2D12C0CD3D0ULL, 0xED8333E4077972C6ULL, 
            0x147B1DFFB9B8E531ULL, 0x7A68D235E6E80239ULL, 0x0B42E88444497C64ULL, 0x921EAEA563EAC16DULL, 
            0x5456F4086C616718ULL, 0x18893CEFBDFECE0EULL, 0xB420C69238E92060ULL, 0xB0F0775CEAEB20BDULL
        },
        {
            0x19119CA5E438EFE3ULL, 0x17FE36A56AABAC18ULL, 0x4FD0DDDD08553C64ULL, 0x4BDD33854677D80CULL, 
            0xA33C334CB4CD1DF1ULL, 0x12086D2E4D011649ULL, 0xB6F18D516850F68EULL, 0xE2128E92593DE156ULL, 
            0x167C36F72988F2F4ULL, 0x5C2E65B26DE34C12ULL, 0xE2FCD4FB2D09028EULL, 0x588BB2C98B622E1BULL, 
            0x6FEC740697B96468ULL, 0x5D9AD47C614555F1ULL, 0x4BA47EABC6D1096AULL, 0xFA33480E85D476D3ULL, 
            0xC3B6E58495D91A4AULL, 0xEDE6056BB402DC17ULL, 0xC4B9FD085296E0FCULL, 0x40301E0F7B88459BULL, 
            0xFC0AF0C2F840E640ULL, 0xF964B42FD9A016EAULL, 0x52C12261E79A5629ULL, 0x6C54F60B8558133AULL, 
            0xD8EBCFFA44F07334ULL, 0xB8CD56F3F50677B3ULL, 0x0653B0C6652BFF26ULL, 0xC7748F46CDB807CFULL, 
            0x0558318C6FD27429ULL, 0xEF6ACA195290FE37ULL, 0x3934BC3EF3868913ULL, 0x1934194799CC129CULL
        },
        {
            0xE70DC16E0AAC0028ULL, 0x224F656EDE67D0A5ULL, 0xF0118A0C959B0798ULL, 0xEBFD304766BAF857ULL, 
            0x21DC5E4D55EC9067ULL, 0xCCADA4C7B97EDE7DULL, 0x0C0A85C0078B22AEULL, 0x61CF44F1A3E97F9DULL, 
            0x577DBFC2725EAD21ULL, 0x610354A8972BD1BDULL, 0xCC558EBB33C6893CULL, 0x507F4CB7C2B99E91ULL, 
            0xB881E317228E765FULL, 0xD68EDC9E7222972BULL, 0xF42B32950EA20E5FULL, 0x4A7DFDF8E0EB4573ULL, 
            0x115FF23DFC886AC7ULL, 0x3037DC841E9D6DFAULL, 0x2D5DA97A1D0D8648ULL, 0x9DC423567A659395ULL, 
            0x257C1655C7A9243AULL, 0x6F21A4A96ABF49C3ULL, 0x6D08EF3FBD151F62ULL, 0xDD4B0A9D7CF7E71BULL, 
            0xF1767752429CBC24ULL, 0x5F09B76AB6D883CEULL, 0x5F0A82AE677C2565ULL, 0xECE6C67749A4225EULL, 
            0x618186A808354717ULL, 0xD5D4186B08FD3EDFULL, 0x017C0E8756A36198ULL, 0x5B442CAE65CCCC40ULL
        },
        {
            0xEE1F0E5AC3C3FDD9ULL, 0x5D99C506BFF5F35FULL, 0x5AED36130D5B4A2DULL, 0x959F54E80D68A487ULL, 
            0xD6CB949EA0FDD569ULL, 0x3A08FD31C04453C9ULL, 0xD61324788382A739ULL, 0x0F8724961BFCC9C8ULL, 
            0x2E525762AD4D7D0FULL, 0x87F6BF3298C93E65ULL, 0xC16035600CF6DDB3ULL, 0x7C4BF2E0AEA3BF81ULL, 
            0xCDB4EFC6C8F75579ULL, 0xE0328B10AEAD294AULL, 0xF232B305190128EAULL, 0x4EF0180BCD69E7CDULL, 
            0xB08EC1C1142B0A75ULL, 0x9E5D53E746D44A1AULL, 0x887C603202B5EDF9ULL, 0x25D191FB59ADE66CULL, 
            0xCAAA86D21888887EULL, 0x606FC5C2440D4DFAULL, 0xEB0D492C954CD381ULL, 0x6313FE6D603EA5AAULL, 
            0x55A4E92096AC563CULL, 0xD9A93A7DCE74012BULL, 0x721C7F61EDE22448ULL, 0x6A3CDF0E51B415DDULL, 
            0xC348FAB026885BFAULL, 0xAA79754D0F5DC865ULL, 0x82400A20C617ED59ULL, 0xC48FEF175F2773C1ULL
        },
        {
            0xAA0DC0903FC389BDULL, 0xC818B9D334C1FA71ULL, 0x2E0B68302A8B7C5CULL, 0x197768310971F072ULL, 
            0x3C2C2930D0C2E899ULL, 0xDE618FE165AC1A12ULL, 0x7CD6514201E3CB90ULL, 0x805EECB66E85209AULL, 
            0x7C04072F1CFF2238ULL, 0xEFA1448125CC0479ULL, 0x2C2F20D3F8E2F237ULL, 0x08FB335C6A2FDFECULL, 
            0x89FF12F74BC71613ULL, 0xAC7B24D3135C8FD1ULL, 0x0AD614F21A88468DULL, 0xA2E59BB17840BA9CULL, 
            0x276FC387573F8290ULL, 0x27AB058A4DD45398ULL, 0xFC40789F7F69D1ADULL, 0x560DC77CA5E7A9C9ULL, 
            0xA5E18F57D7161869ULL, 0x01A3CD8245386DF0ULL, 0x32BA3F2A021A7AA4ULL, 0x77E5F7E41F52D41AULL, 
            0xD8C2F7D6E6787563ULL, 0xDEF1C06A146D837FULL, 0x223E073F2416FBE2ULL, 0x52A50B1A1F91673EULL, 
            0x9ECB73A6FFC588FBULL, 0x7CC8A351FC053D67ULL, 0x9020C0225ADCA10CULL, 0xCD253044E0998038ULL
        },
        {
            0x6E728963A5DB1992ULL, 0xBEE9EC6CAC7E0937ULL, 0xC6D79D364FEFB65CULL, 0xDF82685FDD727426ULL, 
            0x7E29A85BE21CE777ULL, 0xF8B9D648CD50A12EULL, 0xA82F19840551E716ULL, 0x5429AF57BAA42C71ULL, 
            0x40DC0DA9EB749493ULL, 0xAFD17C73EA770F84ULL, 0x49AB350D0C39C7B7ULL, 0x5C8EBBD5B14061CAULL, 
            0x5D321D09CC8AC99EULL, 0xFC6D3A0772D790F7ULL, 0xB71C810BAAE12B66ULL, 0xDC443AA8AEE78B5EULL, 
            0x1B909191361F150AULL, 0x1D269AB3989C990AULL, 0x197CE9673B1E51F7ULL, 0xFF7738EA5C0F3ACBULL, 
            0x206285A57531C15FULL, 0x31CBEC3542754DB5ULL, 0x1EB3AB5450ABEE94ULL, 0xE6336419EAA34612ULL, 
            0x4BD0CBF026FAB99DULL, 0x78032C08763699FFULL, 0xC99126F1430077FBULL, 0x63D6C0B2C3DDFE3CULL, 
            0x6A533C7ABEC0CAF7ULL, 0x91D4B61FC420977AULL, 0xB3AD65BADC52070CULL, 0xD5DD7BF459A20D6CULL
        }
    },
    {
        {
            0x3B9A8ADCB4594980ULL, 0xB653990D23D48E0CULL, 0xFB2A761ECBB3D748ULL, 0x3B8CA09D49B654E5ULL, 
            0xA2F5DDF3B08F1430ULL, 0x9C8287015E86FE73ULL, 0x197A683AB38936CEULL, 0x76D46427E5E7993EULL, 
            0xAAB8C1AABF8463A5ULL, 0x007CFFC2ED215712ULL, 0x892538EBD172F99BULL, 0x12DDDD6FC4BCA824ULL, 
            0xF44BF8A815907E9BULL, 0xA4B668320247DD41ULL, 0x1B1C7428E79AE542ULL, 0x48BC7B8ACDF64B22ULL, 
            0xF7F614426714287DULL, 0x07001132254EBAC8ULL, 0x3DCF8EA6A75DC4F3ULL, 0x472DE61D8C86CB99ULL, 
            0xC3701B1139A34318ULL, 0x80D9D1CA44BADB87ULL, 0x6017B46D10C58441ULL, 0x9F167BFBDC1F98F0ULL, 
            0x2E4B3A694B862C9BULL, 0x0399C8BF0CC37A4CULL, 0xD70F492DCADAC052ULL, 0x405B915AF76B0065ULL, 
            0x4E8A2D40EDFC111DULL, 0x1A971B4A9C7AB7DCULL, 0x32140E2D73F6CB99ULL, 0xC91976F4E88E9535ULL
        },
        {
            0xE49AAB210805AA8AULL, 0x5E8881A35C1C8180ULL, 0x02491FAD9AF69D39ULL, 0x97208EAC6797BB25ULL, 
            0x9E3775DB71186757ULL, 0x6406C6C82FBA5B43ULL, 0x62CB93BE2FBCB951ULL, 0x00A35830794E6E3FULL, 
            0x454B41BF43BDF4BFULL, 0x36C7243C6C970444ULL, 0x31E0640662582592ULL, 0x021D0B870E7A331CULL, 
            0xB27B670450BAD064ULL, 0xFAFC78F6342EF16AULL, 0x897DB2B3B2D40306ULL, 0x68A5D145DC766658ULL, 
            0x3E4A82374B10B124ULL, 0x7DEC953903916CA5ULL, 0x011F0CF7A5A36CF4ULL, 0x0C550449CD96E6F1ULL, 
            0x45028F3918802CA8ULL, 0x22DD1E758C5DB30CULL, 0xB365CCA5AF795ECDULL, 0xF57BAA46289B8FE8ULL, 
            0x523D446B5112D3E2ULL, 0xAFC6FF119178CB75ULL, 0xCE4E39C9CFB62C01ULL, 0x923C42B1E55050C3ULL, 
            0x73E5A873B6683FE0ULL, 0x9A1E6B1B05F14868ULL, 0x6617E4339FFF1FBDULL, 0x7B0B40518BF76ECEULL
        },
        {
            0x4A5580E9A7A7E4E6ULL, 0x318D0EAE04144EFFULL, 0x85C6528FC6C76E6BULL, 0x6AA62EDAD326B6BFULL, 
            0x8A5837E889981102ULL, 0x59094127A1CA7E9CULL, 0x93AD4FEBF5C5EB5CULL, 0x8D8FE46A07C693BAULL, 
            0x8269F80FCB9FB7C1ULL, 0x6B12C0E982A2A73DULL, 0x1BCA6B4BA1C5ECA2ULL, 0x596A62F990F03DC5ULL, 
            0xB095B4D59516B2FEULL, 0xF6466743CFB458C5ULL, 0xEF3DB7F62E1C2F09ULL, 0x3FC32AE33676EB90ULL, 
            0x111C33CDF255AEB5ULL, 0xE39EB55CB5676691ULL, 0x629221E9F21E9532ULL, 0x8AA8D720E43ED9D4ULL, 
            0x6577F0BB23307707ULL, 0xC9B7F04AFF82A221ULL, 0x5323B4686ED3CBC8ULL, 0x2E8BAA66C63CB3D7ULL, 
            0x54427E65A54A37CCULL, 0x90379ACDF740DA5FULL, 0x577B4CA8C4B46B94ULL, 0x0F2275A0292830BCULL, 
            0xDB772F90B730A59FULL, 0xCD5129F9541F1F5FULL, 0x7E10AD40CC6A750AULL, 0x5F529BC53A5C93D8ULL
        },
        {
            0x5326BDAA2095A566ULL, 0x7315EBCC2FD74D0CULL, 0x2FE6DC33A6402F4EULL, 0xAECF5BED47199386ULL, 
            0xC7534691E98879C4ULL, 0x14D130772B7849CBULL, 0xE8A06CF44509C05CULL, 0xB2A3533448FA9104ULL, 
            0xF9F0836F26118439ULL, 0x286BF0497BB3BB0DULL, 0x1C6D177DB62D3B6CULL, 0x5DD4495F524D7B98ULL, 
            0x7C41536807243CCFULL, 0xD4260D3A2E7DE291ULL, 0x9B2560A66AC4F1C2ULL, 0xA7244B10549327FBULL, 
            0x5331ED31EC1E6A75ULL, 0x07EC9E38243755D7ULL, 0xD61289FEF416E701ULL, 0x4939C736273AAA24ULL, 
            0x2B1ECC838D1F2869ULL, 0xD42C43AA2F90C518ULL, 0xB8E1D696DC78382DULL, 0xB9962DF598C4D50BULL, 
            0x27017ADEEDA31989ULL, 0x6A59EAD6745F29BBULL, 0x96B8D015DFE42CF0ULL, 0x665E2E7603BB1A3BULL, 
            0x2D0318EF3B60BB75ULL, 0xEC1856C62119449CULL, 0x1006F4CE75A8DAFEULL, 0x3C1CEEFF762DE3FBULL
        },
        {
            0x2DE63118B4425E97ULL, 0x800B69951F670B25ULL, 0x7564055D438CC60CULL, 0x0F9C148F3E8B6FDFULL, 
            0xAE90DAA9CB809D7FULL, 0xD123D3D95A47301BULL, 0xA978C0919374A236ULL, 0x0E76EA5CA99C1C3DULL, 
            0x5EB37EC2E02A1E5AULL, 0x53987C62492757E7ULL, 0x278D58DC81D5917AULL, 0x7E59A5E4EB828647ULL, 
            0x80EB86BBAC6F5DCEULL, 0x1D3CA40764BC35FDULL, 0x354B08D9B98A4E14ULL, 0x54BB2F7DD148035FULL, 
            0x51F844F61B1D8707ULL, 0x8B7FDEF2E7C1CDCAULL, 0xE78844B70BC5ED03ULL, 0xABA725BA4E3EACE3ULL, 
            0xFE6B8A6109304D4AULL, 0xCB42B64CE86C7DF6ULL, 0x2308243ACD5534A5ULL, 0x9A5DBF1DE532C5D5ULL, 
            0x35C754E662DC7C63ULL, 0x71B5094D88F3393DULL, 0xB14197CE482B36E5ULL, 0x2484E561299AD56FULL, 
            0x67FC27AB3A3A6FFFULL, 0x2A5E7D40D9332F71ULL, 0x870D7D07E31E7D89ULL, 0x5258E187078BA847ULL
        },
        {
            0x870227B35A6E0110ULL, 0x9721CEF5325DBC4DULL, 0x821865C62BD57546ULL, 0x25F731850B906E4AULL, 
            0x69CA20E99F624408ULL, 0x007D7A28E4FCE70FULL, 0x42E80C7E542C8196ULL, 0x5B6BDF2ADAFE21AFULL, 
            0xC41D4DC797EAEB62ULL, 0x440E3E6FA4EFF5B5ULL, 0x818571548CD69B1AULL, 0x131621C0EB46BFFAULL, 
            0xE93C63FB660A2A8CULL, 0x1CB958628D094452ULL, 0xD36B12B805136314ULL, 0xA0F07AC8D061E062ULL, 
            0x8E085B38B43A41C3ULL, 0xD865198C5B6652F1ULL, 0x50A9BAC50B4C89A1ULL, 0x966B3F80FC484F2BULL, 
            0x119428457E83AAC1ULL, 0xBAE1458BD13A1DD4ULL, 0xD23EDE3BA5105763ULL, 0x1785A019E85A771AULL, 
            0x68B443CD8D7A3B73ULL, 0x9AFF0820BFAC5880ULL, 0x4BE7493C00EBBA24ULL, 0xF48803E7362EAAEAULL, 
            0x53C75EF5BD9E453BULL, 0x2AC73691669FDF82ULL, 0x579F8ECE11A22699ULL, 0xA56370F5D57F16C6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseDConstants = {
    0xF1AF5D416D8B2FC4ULL,
    0x507F73D9E2E89B64ULL,
    0x0F74230227918937ULL,
    0xF1AF5D416D8B2FC4ULL,
    0x507F73D9E2E89B64ULL,
    0x0F74230227918937ULL,
    0x81BD70AECBDA03B9ULL,
    0x66682EE02DF047BAULL,
    0xCE,
    0x14,
    0xF9,
    0x85,
    0xEF,
    0x7E,
    0xC3,
    0x7C
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseESalts = {
    {
        {
            0x36F0724113F99C5EULL, 0x47CA787154203741ULL, 0x63DE6B246AB54193ULL, 0x1CE7D4B8C6EC0FE8ULL, 
            0x6B9B5EA424DF34F9ULL, 0x0FF0A151DFB78F20ULL, 0x463CE266B6C44A7EULL, 0x2B970A191F6C8421ULL, 
            0xE49F79350ADC2017ULL, 0xC1C821F1DBE0EEF5ULL, 0x75EDCEEB08560E0AULL, 0x47EB07C6D499067EULL, 
            0x6DAC001188DED0B5ULL, 0x57F10EF9FB76E1E2ULL, 0x6C679C1BC066B84EULL, 0x34B2E93043B4A865ULL, 
            0xC135E66DA161E36EULL, 0xBC19AEB3AB3B9000ULL, 0x809BE7269E6297B0ULL, 0x53BB5A0241AE31BAULL, 
            0x7EF58B8371976883ULL, 0xF4322545135A3184ULL, 0xB09C7F365DC6F5F3ULL, 0x39F2A933D0295D54ULL, 
            0x48EC897DE6184799ULL, 0xB06C44486B8AA3D1ULL, 0xD3D0DAEB476E198EULL, 0xC65620BE3215F4BFULL, 
            0x2D0336E6CDA01761ULL, 0x86DCB1C18C0F9AEBULL, 0x3DC3612053165203ULL, 0x7FCED30E8A83CC55ULL
        },
        {
            0xFCFC231C234F3347ULL, 0x1B13508E009BB5A0ULL, 0xAE9D37231EA70659ULL, 0xA46C68791D1FB701ULL, 
            0x9B714B46478A6557ULL, 0x569EA95F7276836EULL, 0x41FC3C24AA951C0DULL, 0x726307F69A638342ULL, 
            0x8CD43898F38A4F91ULL, 0x79293862AF0F8D00ULL, 0xD9279AEA75AFD2BFULL, 0x0DE8708DBAA16188ULL, 
            0x09962DE361886B6CULL, 0x61696682C907FF90ULL, 0xB4931E35B921A45AULL, 0xB6B2DF0C7A0AB76CULL, 
            0x9A72233D8C601BA1ULL, 0x45F81FA1A483D7FFULL, 0x3F616FF9DA5D275DULL, 0x7C55ECC2805B7DAAULL, 
            0xE3F9E253F01291B2ULL, 0x981594E284A852A3ULL, 0xE140C225CAE5D69AULL, 0xA26222C155074C64ULL, 
            0x1721093E45D35277ULL, 0xE811E4B1F62CBB17ULL, 0x14553050D244B895ULL, 0x7F339CCAF8EAB5DBULL, 
            0x295F5A60052AF01BULL, 0x916144E0B8F8C38FULL, 0x6F7D9A8ED05234B4ULL, 0xEB5DCD442CC6961EULL
        },
        {
            0xE88D20E654B26DD5ULL, 0xF36DD219BA6CAC18ULL, 0xBD3B63C83143366FULL, 0x15AE8CD8E3D198FFULL, 
            0x59B557040E004C49ULL, 0x726E4C4E908CB407ULL, 0x04970FEC8D639B33ULL, 0xF325646245F01F09ULL, 
            0x1A12F8B584FFD919ULL, 0x0F2B84342A879C3CULL, 0xB3440D13D9DD91E0ULL, 0xF6B4738A2E387AE1ULL, 
            0xDDD09227005AE31EULL, 0x1AD1AE4E527F6BBAULL, 0xC650CBDBDA7DB6F5ULL, 0x9ED5AD6997D751FDULL, 
            0x5E7E84229BA6B1B5ULL, 0xC753160549C9944BULL, 0xA3F4669D212B24BFULL, 0x3D004BD69E26F89AULL, 
            0x64515C7F310E9847ULL, 0xAA8F43C69F311FE1ULL, 0x032EAEB31F2F9A97ULL, 0x8F745E6B6ED093CAULL, 
            0x9C5659BA775CEE41ULL, 0x9DBC0FEF10EB1FAEULL, 0x06ED39B7E8D6342DULL, 0x4D30298F153A11FFULL, 
            0xCDD468F6C731C93AULL, 0xD31A7D4FF6DD139AULL, 0xD42000A27070C292ULL, 0xF7BF0E2DC47705D3ULL
        },
        {
            0xE7A2D7133FAAD5EDULL, 0x2BF04C11C10EC5CBULL, 0x63C3480CC9706F4FULL, 0xDA1944567F39E64BULL, 
            0x7EC88D2D2691BD87ULL, 0xBCD0C7F285C21A93ULL, 0x451FB1207C931CCFULL, 0x8A974BB1A9CCC95DULL, 
            0x594C68EB3FA6C431ULL, 0xB0CF6E935EC24524ULL, 0xA51C7B07FF01961BULL, 0x55D82B3863EF10D8ULL, 
            0x285D8ABDDBEDD406ULL, 0x3B3FD925BFB7C1F6ULL, 0xB6D8F235DCA6FB60ULL, 0xA953DB85A65D051CULL, 
            0x8D0D8890CFDE11C8ULL, 0xE02671F0FB73FB11ULL, 0x228D16FA5089F9FBULL, 0x1358C4BB81E2C245ULL, 
            0x9E2E0D108271AFF4ULL, 0xAF21AEC1FEFB553AULL, 0xA493FFB18FE266CDULL, 0xB5038539D0F97C0BULL, 
            0xD19CC204FFEDA82EULL, 0x2D61791F4F4E24BCULL, 0xA82738BB834D45F3ULL, 0xDF53254D79E0E717ULL, 
            0xA6912EC7A9963030ULL, 0x81E08B55A3A495D5ULL, 0xFD5EEB969C5AC190ULL, 0x4E77CDC49934D525ULL
        },
        {
            0xB53C8D2097101B25ULL, 0xFFC33B66143D2232ULL, 0x18C5DDC0BA0AAB27ULL, 0x5EC07B32E454FB02ULL, 
            0xD7DDC8654AFD0D08ULL, 0x7AC61E2FDB40678CULL, 0xBBF6DD1AD72A2EACULL, 0x3B30A646F38D6A4CULL, 
            0x26EE4AF8C4734959ULL, 0x0431EC1D4C77C57BULL, 0x6EB034DE761CD9E3ULL, 0xDDA2AC628B514F59ULL, 
            0x063EE494623878AFULL, 0xAF8C785EE0E1F67DULL, 0x43E03EEB6B464914ULL, 0xF6B1F5636920911DULL, 
            0x4613C71F18AEC96BULL, 0x5A119815E67F579FULL, 0x62DD9C4F6DACD1F9ULL, 0xA8DFDCA33A0C473AULL, 
            0xB3B512C97AEBCF7CULL, 0xCFE409B6E9209170ULL, 0x972392DD3F658A44ULL, 0xBA848B3E906CC37FULL, 
            0x0F70F4F59134A30CULL, 0x03B3E9A85DB6D015ULL, 0x5423B5AF3596C178ULL, 0xC7AE83ED833D4EEDULL, 
            0xBE1EBD602B1930C1ULL, 0x9A5EA682FD27AE2CULL, 0x5C55A2B96A52C234ULL, 0x8FB88288560E93BEULL
        },
        {
            0xEE44F6A4BDDE12FDULL, 0x8AA11AA57285C7A3ULL, 0x7482B994E72F1A32ULL, 0x2FE86C676E194687ULL, 
            0xFFFBCD5484D31B5CULL, 0xABC45B2447F19D88ULL, 0x64F3FE43FC3F764EULL, 0x1D552D57B4F4FC40ULL, 
            0x9F493B32D8FCFB90ULL, 0x4E057E984658A0DAULL, 0xCAC8FA0A46913D6AULL, 0x422A7D54BB55D2AFULL, 
            0xC4F3650D325762B5ULL, 0x396A5B9031471662ULL, 0xB88AAC0A6B536EC4ULL, 0x6BFFFC04601BF278ULL, 
            0xE0392EAFAC2CE2CCULL, 0x2EB6472D3FE3043EULL, 0x65CDC0A7148C3955ULL, 0x06B8ADFFBC551ABDULL, 
            0x24CDBFF5CCD65153ULL, 0x5533387646C76966ULL, 0x4BEDA773A2587007ULL, 0xCC6DAE8444CC2D64ULL, 
            0xF462A3C288CF834CULL, 0x24FB56E453E14CFFULL, 0x42C7262A198AEC6BULL, 0x19C3DBEBB132F4C2ULL, 
            0xB88AD6BDDE0F33ABULL, 0xAFF282F70756805DULL, 0x9C332134CFC8DC68ULL, 0x4556834A9444DC8BULL
        }
    },
    {
        {
            0x04E7FC77D0D439ADULL, 0xB22E769BAE83862EULL, 0xBC4166A1E5719F58ULL, 0x3C81582F064CEB7CULL, 
            0x885D2EDCD5B9A69BULL, 0x85A39E5A2B78F859ULL, 0x41ABA6C08AABD69FULL, 0xA63798BDB384DF25ULL, 
            0x548376385DB74244ULL, 0x34EA14735448D2D5ULL, 0xC09A74CAA3D0F1ACULL, 0x3F7A855F53E82C12ULL, 
            0x65F8EFF22E8DC250ULL, 0xE4A8523C085642DCULL, 0x423B0AEE9BA1495EULL, 0x27845E5BB7292413ULL, 
            0x379BB45680EA6280ULL, 0xBD7E9CC3D6F1CA6DULL, 0xC68126C2601A7E9DULL, 0x7C00DFEE5BB06944ULL, 
            0xBAF0C4E1DD587E37ULL, 0x35D3213F3275013DULL, 0x984FBBC7BE8473F1ULL, 0x3F91591948C6D0FCULL, 
            0x4434B9CEDEDB27C9ULL, 0x772FEF0DF3CC7A69ULL, 0xA767994D0B8DB1A6ULL, 0xC5DB0D2B27E73D56ULL, 
            0x9CCC3865B92B3AE7ULL, 0xBB6C967BCBC82D3FULL, 0x7DD34AD7F7EA5941ULL, 0xFF390F101E9F89FFULL
        },
        {
            0xE09F36C6F226368EULL, 0xB0F7D1921DF674FDULL, 0xEEE7071CC68B4EF6ULL, 0xA05D408C69A1F003ULL, 
            0x8061331D91DC8112ULL, 0xCE5F5241A4DBDEFCULL, 0x92437D24C2BB500CULL, 0xAE525089F99F98A3ULL, 
            0x17248F4864C8350BULL, 0xA1A1768FC425B15CULL, 0xBC18745C0BDDFD37ULL, 0x236C9AB9D92D2B77ULL, 
            0x13973589975ADC65ULL, 0x1BCD81AB8712BB66ULL, 0xE2C48B808BBDCD64ULL, 0xC1E9A09E9BBAD518ULL, 
            0x41A1BA7BA1F5E238ULL, 0x508BA7DEEC81DEEEULL, 0x779D5D08DB63D0DBULL, 0x71F4897E81DB2E3DULL, 
            0x9FBF01D5A8ECEA8CULL, 0x5EC4232684B9719DULL, 0xF971B1BD668C38B0ULL, 0x29030508F4245704ULL, 
            0x8A9BABB0336206E9ULL, 0xE03EE822E4789167ULL, 0x5B8A3542260F74E1ULL, 0x4967B066DD1C9D6CULL, 
            0xE89D30DF90E2C3C5ULL, 0xF7DF0212698B7BDEULL, 0x6E48C165611E564EULL, 0xEDDE1C990FF96A90ULL
        },
        {
            0xD043C27D02C20089ULL, 0x7F57C0198BB75BCFULL, 0x3895EC9B7E3E69EAULL, 0xC2F28C2A5524F785ULL, 
            0x7892C0616BD347A0ULL, 0x558507C52796450BULL, 0xF2BCFA1228881D82ULL, 0xC2731EDC38D84703ULL, 
            0xBA31B95D7E63088DULL, 0x4B76EF63F1653AC9ULL, 0x3D34729AEAD4575BULL, 0x7C275D5EE39B2519ULL, 
            0x36A5910B27619B7FULL, 0xB6F8CEC52B4FCC8BULL, 0xE329F476C3C2B022ULL, 0xB33B6C1283B9275CULL, 
            0xCD974A1A9D6D3D6CULL, 0x357B891AF69C1916ULL, 0xFCBD08FF9B067277ULL, 0x354241AE694E23C5ULL, 
            0x840CAD64C9F8A4CAULL, 0x368CEEC32700F4E6ULL, 0xD309C01BDBE863EDULL, 0x67876145AA75A8D5ULL, 
            0x44E12DC7060FE71CULL, 0x1D61562045CE54B9ULL, 0x81A88FB6F1CFB15CULL, 0x1C660183057D1E5CULL, 
            0xA7809ECDD611F9DBULL, 0x356EF2CD3F63650AULL, 0x951F49B8B90AB4FAULL, 0x68B80696CA8A1413ULL
        },
        {
            0x87CB34779B49B3E3ULL, 0xB3C38A2F62358524ULL, 0x4462969B4B82E596ULL, 0x43E11D5BAD56108BULL, 
            0x241B2FAE58938A4AULL, 0x5B2C913C749B5C1DULL, 0xEA1C28CA808FF48CULL, 0xE84D7B7117242913ULL, 
            0x413730E02440F771ULL, 0x43192DE9403FE4B3ULL, 0x4149C423FE5C9AF8ULL, 0xD6C664E6C4D21E5CULL, 
            0x969B32B45212B258ULL, 0x9ECDE43AB694BFA0ULL, 0x316337A9F51B51FBULL, 0xFC2C31D2BEFE50D9ULL, 
            0xE2CDF8CF340B7B44ULL, 0xE4B884210723E1A8ULL, 0x82FD88FABC2F5FA6ULL, 0x5EF88D4DAFA66CD6ULL, 
            0x15C7F12FF10CA305ULL, 0x68E6945868D96057ULL, 0xFE2F8BB49A06978EULL, 0x8AF76229CE178C9EULL, 
            0xCCDB8F848CE0FE09ULL, 0x83D6DC71F7410524ULL, 0xFED0F2A9D38F605CULL, 0xC90C59FB15F4A3B8ULL, 
            0x84103A778397463BULL, 0xBF091F5CEBF43BD8ULL, 0xC6A9546E407E2EF5ULL, 0x74688BA867E567A2ULL
        },
        {
            0xD95C012AFD4C9188ULL, 0x5F0D8A3ADF18865CULL, 0x46B91194CE0FA6D6ULL, 0x0727E29AED2E9307ULL, 
            0x8FF392C42C347742ULL, 0x7A885C076362E697ULL, 0xDC7EAD39C9A21507ULL, 0x786C86CC0DE01BB6ULL, 
            0x66B27F172E37B107ULL, 0x71D68652070C8E7DULL, 0x6838D7FB3B31F559ULL, 0x45EBAD8D83DEBE52ULL, 
            0x7A9EA57BF34CECF7ULL, 0xD67B9BB488A9E899ULL, 0x04AB701DED208400ULL, 0xFC8287E4200921E4ULL, 
            0x1ECD48F0042C8CCFULL, 0xDA2F8579DD853FC6ULL, 0xFCE2D129E00F67DEULL, 0xDA4DF41073CA5358ULL, 
            0xE319B95A4798F767ULL, 0x96B192773A48BE22ULL, 0xB4F1E9A64E507330ULL, 0xB50814945D6F3478ULL, 
            0x45B3235419DF8BF2ULL, 0x60FFCD6113A800F6ULL, 0x9F5307A8E717022AULL, 0x3F87D1AD4AA7DC62ULL, 
            0x9E91AA00383619ACULL, 0xF0D8AFD3861F09B0ULL, 0x2195B4228F326BEDULL, 0x95637296A84F3FD5ULL
        },
        {
            0xD3827B38FAF861FCULL, 0x42D13DEF41B9F6EFULL, 0x4E50FBC37AAB5DA8ULL, 0xDAE9CB94966D39EDULL, 
            0x586C722F38E62A15ULL, 0x56E5581843B8BBD7ULL, 0xC57496978E302772ULL, 0x010EDE89B8DDF24EULL, 
            0xED49D52D876736F1ULL, 0xE330643BDF9140B8ULL, 0xC24448F4F0E355FFULL, 0x9521C5C82630F640ULL, 
            0x9CDF0B419FC9334BULL, 0x8A40D644F2EF2F45ULL, 0x45E356D3E2F0E356ULL, 0xF0124C80ECBC212FULL, 
            0xAC66DA16885022C8ULL, 0x8762AE08F2434A00ULL, 0x67249939E170E7F4ULL, 0xBCC73FDE4A905C74ULL, 
            0xC7C74295908EACAEULL, 0x9F9C49A5CC70F152ULL, 0x8E9A9519B7B56276ULL, 0x47868FF505070E5BULL, 
            0xC0546612A6B45E81ULL, 0xC79911B9C832C5BFULL, 0xF8ABF0FB9ED45B72ULL, 0xC9912D18059EBDB1ULL, 
            0xA56CD1F47EAC4798ULL, 0x48C39AFEE86A2B01ULL, 0xA0B97FDF520892DAULL, 0x644F3ADA7C5EBF14ULL
        }
    },
    {
        {
            0xA54EEEB6F00F6A60ULL, 0x2CB43D7B6C6DE313ULL, 0xA7B92700DE754829ULL, 0xC721E5236AD7288BULL, 
            0x0FEDA5171407AD8CULL, 0x86637A00ED07E3C4ULL, 0xC5EF3D45DE369922ULL, 0x44FCD22691B0FEECULL, 
            0xB125B360A13F1416ULL, 0x552C6C66DBC787E3ULL, 0xD46E978637B91A27ULL, 0x50D025279DA0DD78ULL, 
            0x503981C47ADF6CE9ULL, 0x736DFFF02ED1B2CDULL, 0x917B6994235D9F3CULL, 0x5A0AE58ECDAF4995ULL, 
            0x3DAD53F0A4EB6213ULL, 0x729874C1BB5A1BB0ULL, 0x9E136E85ED7EC607ULL, 0x1BBE9474E086F4E0ULL, 
            0x2B3DA2FAEC4B8A16ULL, 0x1935BD912AC931F1ULL, 0xA95D3038E040FC97ULL, 0xC182A60CF7F3B011ULL, 
            0x829A8BF12F47D34EULL, 0x035CEE29BEBDD76BULL, 0x319CE3E3AE524DB0ULL, 0x1E073E2785F1583FULL, 
            0x3F38470497FA49BDULL, 0xF592C8136D581F5DULL, 0x60CF5B2388496DBBULL, 0x408D2A8638A8F8A9ULL
        },
        {
            0xEABD9EED917DCBA3ULL, 0x0E93CB6E5B66E816ULL, 0x355FEBF1C7D52998ULL, 0x7F5A7FFAEEED0001ULL, 
            0x29895C528AC57E33ULL, 0x84470652614ED881ULL, 0x145395B7C6354C26ULL, 0xC85EDFA6ACD18E83ULL, 
            0x23AE94754621D516ULL, 0x625A1B9ECEDC899BULL, 0x349010D501219695ULL, 0x3B4D8DF7F198E238ULL, 
            0x65CA24C69FBED103ULL, 0x2FAF026400CC0E71ULL, 0x242F493C2D945279ULL, 0x7488BB7FF88A55A4ULL, 
            0x18E8956C5E2791B2ULL, 0x1B88B3411A9327AEULL, 0x345D463FCAF96D6EULL, 0x43F1E774548B464AULL, 
            0x9B72A62F414A12A3ULL, 0x43689B97D692820EULL, 0xF0B7B5C8D1891FDDULL, 0xFE48511C7E1AEFD4ULL, 
            0xD0FCE8494DD9A626ULL, 0x541B77EE18BB6506ULL, 0x7302744E8DABE16AULL, 0xAD02353270D82B66ULL, 
            0x1502FCE4890900CCULL, 0xD2E87804DD35C447ULL, 0x47F8E5080D12AD48ULL, 0xE71098BA7A7070EDULL
        },
        {
            0x70655970F44E4004ULL, 0x16F97788CFC4F8E1ULL, 0xA46DFC4846AB5B2BULL, 0x3938502A9F8B5F30ULL, 
            0x6D5F3E8811D20B3AULL, 0xE8D983D71979E46DULL, 0x3898B85F1ED1AC0FULL, 0x491D58591200C893ULL, 
            0x5BB0A02649A18CA6ULL, 0xCF5B6FB36ABC25BAULL, 0x95B5C2CD468B9F13ULL, 0x05F80519757FCB83ULL, 
            0xF9661D04AEA5A33DULL, 0x92EC14A200C067EEULL, 0x18445B3E09B093FDULL, 0x535D412581D32C0AULL, 
            0x108B9281CF3BDC7BULL, 0x0300CF55BD3DAF6BULL, 0x26B86F21593C1852ULL, 0x9EFAE3D6AB3E4BAFULL, 
            0xB9A1052C6015B92BULL, 0x783E532C5A5D7B19ULL, 0xA62D979F72819369ULL, 0x24A1D8A698D88276ULL, 
            0x6CB1FCC62B5892E2ULL, 0xF43EE5C89D266678ULL, 0x8BE01DF0B10B94B8ULL, 0x1A43ABA36663DA8DULL, 
            0x5A007EA548F45372ULL, 0x7AB7011C72D70F23ULL, 0xC4A385AB0A9C2031ULL, 0x3877F50437AEAC05ULL
        },
        {
            0x478CA53D0CE991ACULL, 0x897F3B11A45C6656ULL, 0x6CFEDF40864127C0ULL, 0xF7EDE029DB409E9EULL, 
            0x5498BE08644ED197ULL, 0x8384ADE5DBBC23C9ULL, 0x55F38FC0F07D8542ULL, 0x114985DC1344B8B1ULL, 
            0x42191EE8F767D11AULL, 0x7901AAA4BC33BB0DULL, 0x483AD3A70024CE19ULL, 0xEE0DA271AF3B104BULL, 
            0xA29A079F9396EE7DULL, 0xBFFB77715AD85140ULL, 0x8C6AF8118FDC1228ULL, 0x39B0CC2338CFDEDBULL, 
            0x99B6EA026ACB2BC9ULL, 0xE0659A5697D537F9ULL, 0x6A7C4F04FF8CAA0CULL, 0x5DC94A79E77D6E23ULL, 
            0xB35181A2EA604700ULL, 0x4970D2FC5CEB1F5EULL, 0xE4B180FA3886C868ULL, 0x1BD19AC0907DCF1FULL, 
            0x606B54EA0871B57EULL, 0xCDCDD3D754127B86ULL, 0x49F75A4A9F1FFACAULL, 0xD8F712E5D141E5D2ULL, 
            0x1E02A2BA67DB7BCEULL, 0x0274839323A7624DULL, 0xA439FA52C5162C12ULL, 0xFD99917495F5FA9AULL
        },
        {
            0xE0AAD21C9B0D5A97ULL, 0xAC73DC212F42D034ULL, 0x9D04EEA0A60FA9D5ULL, 0xD48CFF8B1DAB3723ULL, 
            0xDCD81BB695326C5BULL, 0xA5CDA0BB3E884C0EULL, 0x8F51698430B97268ULL, 0x8354D1AC1E3F39EEULL, 
            0x657B8F79D33615DDULL, 0x64AED70C79CA48B8ULL, 0x4E72C253577CD271ULL, 0x170101C4CF60090DULL, 
            0x76BFD824C63662DBULL, 0xF344268CEA31D74FULL, 0xC06C7FE564598A2DULL, 0x8F63129D9EE3100DULL, 
            0xCA7D25424A2734E0ULL, 0x7AA159746B1370D1ULL, 0x8AF2D633677F3A61ULL, 0x9F13A793D16D5457ULL, 
            0xDC0A68AC2A528C9BULL, 0xA9E5A5355AF31927ULL, 0x5B0AB0177536FDB7ULL, 0xADC469277581CC6FULL, 
            0xF2B95BB286A3B5B2ULL, 0x6E08D6C966E82E49ULL, 0xAC1A4E2185C4B59CULL, 0xA21F4E733D619846ULL, 
            0x1F2A8909BFBAB361ULL, 0xA4ABD707033AF32EULL, 0xE1BED850CB99A709ULL, 0xB64F6FB37503A406ULL
        },
        {
            0xA8C4365EF6044231ULL, 0xCFAFC1FC312DD0E8ULL, 0x17B8A214EEA48316ULL, 0x53A4CEEA8D1CC1B6ULL, 
            0x6E6DF1F005F87826ULL, 0x4297A621E2296EF7ULL, 0x0DD39E5EB38003F4ULL, 0x9B7789A0690E8CA1ULL, 
            0x34B5E9CECDA93E81ULL, 0x11BDAE3F6D325AE5ULL, 0x6D399EB36405D56AULL, 0x8BB20C9D8D8B05C6ULL, 
            0x254B8A7C46DC07CFULL, 0x9A0E38BF78DB4756ULL, 0xF4537A0C905F0E09ULL, 0x02C668695D1CEA61ULL, 
            0x9D75FA6158844D76ULL, 0x2170826026CF8395ULL, 0x99F2DB80BC3494C1ULL, 0x7269E148B8353584ULL, 
            0x3D2F485D47554B52ULL, 0x437874C5F53CEBF0ULL, 0xDB04304DACA042F6ULL, 0x81215C6C235ACDD4ULL, 
            0xD8C1684A72EB3AC4ULL, 0xD1B86C07FFB34AFFULL, 0xA3E67010E1AD7959ULL, 0x7564CBFE11B5BC8DULL, 
            0xB12CA9D83B0933BCULL, 0x5CACD68F9486D7E0ULL, 0x22B41C651B1413CDULL, 0x159A1B74D71AD224ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseEConstants = {
    0x0927FCDD1EE05955ULL,
    0x8962B97DE8F97DC4ULL,
    0x0EDDECD056884412ULL,
    0x0927FCDD1EE05955ULL,
    0x8962B97DE8F97DC4ULL,
    0x0EDDECD056884412ULL,
    0xD922D471312B0A02ULL,
    0x1664248D1676414EULL,
    0x28,
    0x87,
    0x03,
    0x71,
    0xD2,
    0x42,
    0x7E,
    0x89
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseFSalts = {
    {
        {
            0xE9BD1354C68E9A11ULL, 0xB63EFC9D9D5B019CULL, 0xD94BAE5886CD89ADULL, 0x55835212C71C1F64ULL, 
            0x42BDFA256EE2A348ULL, 0xBA5849B595CD5E98ULL, 0xECBEB49EB3F09493ULL, 0x12DC39B500A72CF2ULL, 
            0x0E0681F5C4F94838ULL, 0xE22A06A9ABADB7B1ULL, 0xA69EC84185627474ULL, 0x90E41666F047A79CULL, 
            0xD81F653228F775F4ULL, 0x9591B097EAD104E3ULL, 0xEE9FE6BB58D4E32EULL, 0x5B7ACA02E53AA4FAULL, 
            0xC4058529EFBF17EFULL, 0x6D1FDF8A96BCBC35ULL, 0xCE82B613C7198224ULL, 0x29D4BA733C93E750ULL, 
            0x59B6DF97BA099C86ULL, 0xB0885A9F8583DEF5ULL, 0x75BA6F334E4CFAD9ULL, 0x91B3BC0FAF3DF757ULL, 
            0x0F2D6CD6534EBEEBULL, 0x84807CAA4B9CFC54ULL, 0x1382C8CA1757FB39ULL, 0xFAC158B60CFC0B07ULL, 
            0x5B44ACA6E53061BCULL, 0x52A5512883E44514ULL, 0xA8EC9806EEA7375EULL, 0xE012AAB5DEE291E7ULL
        },
        {
            0x9C8D27E164E6CB1AULL, 0xCBEC8B8C265E5D4EULL, 0xBB5A819F6D6C5C0EULL, 0x5B0E78D26954AD83ULL, 
            0x192EE59FDA3A85D1ULL, 0x925A2E60700C2E1DULL, 0x07C6C8AEE5C71C93ULL, 0xF2610D72376CD8CFULL, 
            0x3BACA78A8807004AULL, 0x24E71CB1D98B5525ULL, 0x72F3D6717915C3B9ULL, 0x67DA7F39171B5EABULL, 
            0x5A78B05BAEDEB950ULL, 0x29BB0FF1E9525DCCULL, 0xF876DF722A23C17CULL, 0x4F3650E2D6A22166ULL, 
            0x11D34F04AC83D36DULL, 0xAD8055AD0278E25EULL, 0x424A3ACF13CBE8CDULL, 0x2E938F5E4147B647ULL, 
            0x291EB2404A2A6BC5ULL, 0xE049322D325B0C22ULL, 0xA9A13441BF57E19FULL, 0xB67333D0196D8B7FULL, 
            0xCA6B6C767EDA1008ULL, 0xD75402513B4F7ADFULL, 0xEF04A30069AC98CCULL, 0xCA2047548957F276ULL, 
            0x5FC0105FD69F03CAULL, 0x977DED8923028ED8ULL, 0x6CD2FCC1EBB9FCFBULL, 0xDB3238C5C8DB30AEULL
        },
        {
            0x3772AB080C5203D9ULL, 0x9423FDC59BFC434AULL, 0xAAA7B571F17B102BULL, 0xC07E77FE43D10AACULL, 
            0xA0D27DC7D5405DD8ULL, 0x068DC772FFF95647ULL, 0xBD6984A34AF5E124ULL, 0x88A804D6F54C2AE3ULL, 
            0x8421925C712EA614ULL, 0x23CDA997AD38EA92ULL, 0xA8AB5EEBD861761FULL, 0x1103D1E777530F12ULL, 
            0xF5849F6FC857D993ULL, 0xB77EB559BF019E02ULL, 0xBC23CFDB109052C1ULL, 0x6DD16A117729AC82ULL, 
            0x47790459C74B8E0DULL, 0xB2D914F28C1FF8FCULL, 0x0C02BF56FC7269F8ULL, 0x3824749248D537C9ULL, 
            0xE9A4CF5158466420ULL, 0x4B6F378A384C1429ULL, 0xA2A9A067EB700201ULL, 0x31326F6257BAA797ULL, 
            0x3AED7FFFFD1CFB62ULL, 0x8E3475EF0A11C61CULL, 0x3CB5E25DB01E3F66ULL, 0x706D3183B3CC14AEULL, 
            0x36261A571F1C6C03ULL, 0x481B1351A0A152B3ULL, 0x02E58C40FEAC6CEEULL, 0x54ACC0138144EA90ULL
        },
        {
            0x527CC15FBBC95DB7ULL, 0x807F63F577EB3E52ULL, 0x91235A8F4288817FULL, 0xBC1AACF77B940FFCULL, 
            0x886676F84F25D5D5ULL, 0x3430757EAB7777CAULL, 0xE302D3D8D6107269ULL, 0x85CBB4739D8F9B42ULL, 
            0xE3C3DC218819728EULL, 0xD5211CA78B1C6758ULL, 0x179186242A91FC4AULL, 0x8F6EAC3DAFE6E653ULL, 
            0x146E9FF4C07DAEC4ULL, 0x28CE635194B5E4CDULL, 0xD12ADB329CBCB44DULL, 0x49D07FB2B09C949CULL, 
            0xBEB25097BEE051CCULL, 0x97D276A95DA11FB1ULL, 0xC76A084F72C8BE1FULL, 0xABFEB8F9777913E9ULL, 
            0x23231A0A8767F647ULL, 0xB739C54F2286A194ULL, 0x0E996E64095C8CAFULL, 0x3EE6C6C895A0F6A2ULL, 
            0x1C9BC90B0BD56003ULL, 0x9D594521F1CA234AULL, 0x616024839D73229DULL, 0x83C82B9C2ED14FD3ULL, 
            0x370A4787218E7D78ULL, 0xEC0F20834DBA7838ULL, 0x4A20BCBDADC2C976ULL, 0x25AA1294EF7DBDB3ULL
        },
        {
            0xFF29FF256DA6644AULL, 0x5DAD57F7550BA09EULL, 0x456238D12F6F4019ULL, 0xCCA2CBC9576D7B04ULL, 
            0x696C4AA7648CB4FCULL, 0x8E744AE804F9151EULL, 0xCA50C33EE8E7E8ACULL, 0x8AEE7640BEFEFF03ULL, 
            0x1ED83B6F8A6D76A9ULL, 0x430D31A7A83C1832ULL, 0x1BEE703CA7CFF7F4ULL, 0x49C18CAF26652873ULL, 
            0x19C1E4641D93EECEULL, 0xC5F5E8E4364A1087ULL, 0xDAE3BA786CA5926FULL, 0x9CE06B1ED60F0CD7ULL, 
            0xD90F5CFD2955A1F6ULL, 0xB6F1D4F55A69CC6EULL, 0xB12383D7CB8F9E73ULL, 0xC8BA87558DDFAF85ULL, 
            0x9C5C19BDB80E4023ULL, 0xB0AF547280EE337FULL, 0x924AA4A473E56293ULL, 0xBC73240733E1ACD9ULL, 
            0x8D246F802F8511A9ULL, 0x4E3B66F5C8E17DAEULL, 0xC48F349D2682616AULL, 0x44CF992D278364BBULL, 
            0x0EB90946C08516C3ULL, 0x98FDD1D9C9E84F2FULL, 0x3D6A0EFCB3B8EC6AULL, 0xA2DC62CD31F2B875ULL
        },
        {
            0x875F7F02242E29DBULL, 0x3E433C9D5E789780ULL, 0x27100074E7CB62CBULL, 0x526A4001BFD9742FULL, 
            0x94B57FC3F53FB387ULL, 0x4A6B19469610038BULL, 0xA4B2291E7FC661C4ULL, 0x7846F84DECDE8FC5ULL, 
            0x0971130D7E4463E3ULL, 0x599B9B1C973F7C44ULL, 0x3EC2CF60EE1B9C1AULL, 0xE0B1EB96FF51875FULL, 
            0xD5A8AAC0E90AD5BCULL, 0xF0DCDA6EF33444F0ULL, 0xE364712488ACD91EULL, 0x4CFBC48B1068A53BULL, 
            0x6B8601A23F24A7E7ULL, 0x391BCB66049815D6ULL, 0xF45CAAFE1DA0C0E8ULL, 0x85B1E4805B225DEEULL, 
            0x28616732381176F2ULL, 0x9251AB75AA70C0DAULL, 0x38DF8B5A815EB8C7ULL, 0xC9D74D54525F7D17ULL, 
            0xEBAE24FCBB474EFFULL, 0x17CC59996B956DEAULL, 0xD9626C8373EFA29FULL, 0x0C05642C67896E93ULL, 
            0x64F0434E3FB6667EULL, 0x86AD9FF97C817DA0ULL, 0xA4B8A748C5A4395CULL, 0x9BD498C27258E02CULL
        }
    },
    {
        {
            0xE27B4D9DB3C2FDBEULL, 0xCEEAB62EE0D98C41ULL, 0x9249DE9363E2CBB3ULL, 0x691E32378B4057F2ULL, 
            0x6245418212C1DF05ULL, 0x98B8F74DF81DE190ULL, 0x9D5EE98739AB6A4AULL, 0xE492911A36FBEC63ULL, 
            0x886BC7612783B7CBULL, 0xC8D851190A38C3B8ULL, 0xFBEBD5356FD000A8ULL, 0x00772F0BF0E73C1CULL, 
            0xC022C1053E96B9B3ULL, 0x1F92AB9BAF2B654CULL, 0x8862F64FB01FE9A0ULL, 0xF8EB43C5FD3B4A95ULL, 
            0x81E93AF2927AD8B2ULL, 0xD256A015C31B8373ULL, 0xD634CF6CA41F8C06ULL, 0xDFBECF3D5FBF5900ULL, 
            0xF4CE8849984B316EULL, 0xF5679B0C571CADF5ULL, 0xC148E3140CF70C2DULL, 0x561E3AC0AA64020CULL, 
            0x6AE927FECCA636C4ULL, 0xE00DDB6C427A0608ULL, 0x050DBDDC7C74F543ULL, 0xBB1225CB801C8FC7ULL, 
            0xA08A5972649E2372ULL, 0x945A241CF10E019CULL, 0x0C194B0A04E6AF2CULL, 0x57E3FC0BBC22C901ULL
        },
        {
            0x5452F7DCF744D8DBULL, 0xA944E16514B07DB1ULL, 0x2D753EE7380F3F66ULL, 0x09B369EAC8F9FA4DULL, 
            0x7B5318FB60670927ULL, 0xD9CD366EAA418CC0ULL, 0x5528EA73EF6CFB05ULL, 0x1DBA6F9BFB903539ULL, 
            0xE3FBA30286169CEBULL, 0xE44E427A415B93D9ULL, 0x91BE86C27AFDE932ULL, 0xB620204B190163D0ULL, 
            0xE3C88EC5614BF06FULL, 0x44A8CB1583FDC249ULL, 0x56F0ED0AE47DB41FULL, 0xFCBF81FD490FE767ULL, 
            0x35ECBF1E0D2A2035ULL, 0x6E476C23E6437BD9ULL, 0xA99181E74E6A66EAULL, 0x124F1A374C8BF676ULL, 
            0xC249FCDFBD4B8035ULL, 0x2F72547915A63401ULL, 0x9CA0727DF20BB7E9ULL, 0x248042F4C450EF48ULL, 
            0x4050536485FCAB9FULL, 0xFD7048FFDA284A1DULL, 0x47C4E12F8B92314FULL, 0x968776ED84517490ULL, 
            0x8E6DEB20FB974333ULL, 0xBE77418CDB5CAD56ULL, 0x3362CC6D106A72D7ULL, 0x569352EBC10D5F9DULL
        },
        {
            0x3FF1CA5E0B24385EULL, 0x5CAEE8A079DCAC05ULL, 0xD583DC9490EAEBF3ULL, 0xE9726B020FC95973ULL, 
            0x7197BE9DCC17D879ULL, 0xA83CE4F66D1FC5A5ULL, 0xD210D32E2D3B58D1ULL, 0xF319C05BEFD7728CULL, 
            0x5E026C0D80219F0CULL, 0xB8A116F12D3F7704ULL, 0xA9CE0BAA49A1E9CAULL, 0xE60592968AD554FBULL, 
            0xB910DF3E609C9CB9ULL, 0xC858BAD7E72212FEULL, 0xB7F8C4A8AF82B07CULL, 0x19B645C05E5917D1ULL, 
            0x61770F8AC4D0FFE9ULL, 0x4F06F121BE1F60CDULL, 0xFC5E3B44653E291BULL, 0x26814ABCCAC81F04ULL, 
            0x60D3AF89EC508F51ULL, 0xFC10467B6AB8B4F4ULL, 0xC6C88E0B49C51DC1ULL, 0x788F78F826D5E81EULL, 
            0x77BC4B8A30588046ULL, 0x7B24433C2A3F0DCEULL, 0x3FB3430CA74529BBULL, 0xB8E5AC6E36B420C1ULL, 
            0x5BC4A0812DB93787ULL, 0x5F3391ED769C81D8ULL, 0x0ED607FC1821C806ULL, 0xF37405FE3AC0944BULL
        },
        {
            0xC8CECC4757C4BEA8ULL, 0x9296ED31E62B10A6ULL, 0xC64C73F20122CD07ULL, 0x5C91F97A020B3066ULL, 
            0x5B3EFD457350FAD2ULL, 0xB1A84A16B774A1CBULL, 0xE395D83583E269E8ULL, 0x53316D946394D264ULL, 
            0xA22F21A0262F4106ULL, 0xD5E3576141301A99ULL, 0x0460E3FC985920B7ULL, 0x527ACCC295F1C81CULL, 
            0xF90FC267BE19E872ULL, 0x4B6C1376AA4A91CFULL, 0xFB8E717423B68246ULL, 0x02393B99041926E2ULL, 
            0x1AFD83CE8A507EF6ULL, 0x4AED48BA70EF9A12ULL, 0xC53B6A2002C676F6ULL, 0x6EF4345950F5660EULL, 
            0xD4AD748CA1F9A504ULL, 0xD87754905AEBBE51ULL, 0x460AB5535753820CULL, 0x5EECA06259C3A6D3ULL, 
            0xAC898A458C3E5B40ULL, 0xECAE8F0C2EAF7DC9ULL, 0xA7BC85EF0D879F0BULL, 0xD8A032A3A93979E2ULL, 
            0x256C031202DC501DULL, 0x6FAA9C23F2DADD11ULL, 0x2B79F1A0FBDB4E57ULL, 0xACC940DB53E24DFCULL
        },
        {
            0x0C25A037ED41D1C6ULL, 0x8643C2E4199EF1FEULL, 0x58FB77B655BDB66DULL, 0x6EA873EC789392A1ULL, 
            0xAB80B61006E5C6B8ULL, 0xBEE094351A86AAECULL, 0xEEA63EE81B24E73AULL, 0xB3CA1A59B0F3E955ULL, 
            0xA6CCBE727E975AB1ULL, 0x6182CCA53594B62FULL, 0xE72CB32A57E04428ULL, 0x5B00E887C2A7C506ULL, 
            0x6ABD951A91589F1AULL, 0x94E65103759F93AAULL, 0x4E30DEB09EC4D065ULL, 0xA66864773B6B760FULL, 
            0xB51AF281E745DFADULL, 0xF3885C70DAA76A32ULL, 0x7A7F429225D85398ULL, 0xD6851E88E291AB83ULL, 
            0xAB2306179AD0893FULL, 0x5EE48D9055DACB25ULL, 0x190047C387CECDF3ULL, 0xB419ADCF41CA2E39ULL, 
            0xAE705C4F91031BB3ULL, 0xC1799EB5B186204CULL, 0x8E2269C149CBAAEEULL, 0xE2DA1C2647AB7A3FULL, 
            0xE3D37AA9926BC266ULL, 0xA2178CE58A0F9C90ULL, 0xFE55C2A87AF93951ULL, 0x0EA0614797D24F31ULL
        },
        {
            0x25FDE4368AD09323ULL, 0xD1CCAEBC28380051ULL, 0x88B3E3DAEEC10EACULL, 0x2BEAF0CD1A901FDEULL, 
            0x5B880CFDA615F49DULL, 0xA908EE74CFE049EEULL, 0xE3012B63D775E99CULL, 0x90560C33607E74E4ULL, 
            0x649B6B3EA74DC43FULL, 0x8E2AAD6AEF6E8F6BULL, 0x3C8ECB4D522F227DULL, 0xD2BF91F409781CE3ULL, 
            0x0726F3F807C26F8CULL, 0x32D1D1D526EEFE4FULL, 0xBB9C3157818641C6ULL, 0x966892F119D7EE55ULL, 
            0x95A397AA63A32C62ULL, 0x158EC5D31CB34F1BULL, 0x933C1ACDD53061F2ULL, 0xAD05609B7D3081AAULL, 
            0xA43B6A8A781FD909ULL, 0x668007DA8F2FFA11ULL, 0x86700A5243F0F454ULL, 0x4B49AABDEA2C90F6ULL, 
            0x105DEC199B5DB9E6ULL, 0x2A9F4D69F568C3ABULL, 0xC4E8D337EA6223C3ULL, 0x020821E0F10427EBULL, 
            0xCFAD3CFF15959519ULL, 0x670615D57015E34EULL, 0x8AB4DB93DB912FD8ULL, 0xCC4907676D889ABFULL
        }
    },
    {
        {
            0xF2D6AEAF9FE5C5BAULL, 0xB3380A49FAFEA8DAULL, 0x73B1B656F2CD0457ULL, 0x094FED153DCD991EULL, 
            0x901DE51C2DF8296DULL, 0xC3F82A0538791AD5ULL, 0xE3A188A9511BD49BULL, 0x88F6FAE4CF7209F8ULL, 
            0xDBC7C2BE35791FA4ULL, 0x4CBA51C7A9BED3E9ULL, 0xBECB876A17133796ULL, 0x8C8E21FFD7C9A9A4ULL, 
            0x0139EE2EA13CA45EULL, 0x60ACBC9252A30347ULL, 0x3FD90A1B974F5247ULL, 0x801D6CFEEE2ECE48ULL, 
            0x27436E1EF4F9422CULL, 0xFB398AEB622DAA9FULL, 0x20043BECEAA8B17AULL, 0xF5D3A701EFAF19C6ULL, 
            0x2E326BE2CD08430FULL, 0x80BD64F286FD090CULL, 0x8C0237D3D63528CFULL, 0xBACB5D0B518E9163ULL, 
            0x29AB9DC7617DE763ULL, 0x9C4D84E5E17B60FFULL, 0x9165C27055F684FEULL, 0xA997A5ABF22D2F90ULL, 
            0x8869CCA58A1DA48EULL, 0x699B2598D2A7891DULL, 0xBB2B534D16960D88ULL, 0x79AE965147BFA783ULL
        },
        {
            0x52BBCCD92D2002E3ULL, 0x83C6E19912FF5E19ULL, 0xAE246FBC2975294EULL, 0x5B22DF9E76139FD3ULL, 
            0x210376D4BE9DAC9CULL, 0x7D90BD5FD459BAB2ULL, 0x08D9ED7838DD3B46ULL, 0xC1AE28EADD91A28AULL, 
            0xC8E12F8178D66273ULL, 0xC4549FDA9FF80726ULL, 0x415617BB5D604789ULL, 0x03ABD5007B0C01BFULL, 
            0xA2FD5BAF0882114DULL, 0xB5A0214E9C768D69ULL, 0xA912D048B76F0AC5ULL, 0x2DB023A9E914F494ULL, 
            0x95326281CE3BD448ULL, 0xC61192F798957DEAULL, 0x2D85AC6494B18DB7ULL, 0xAACE56B81EFA874EULL, 
            0x7A19BD984120D903ULL, 0xD71F1FD74783ADFAULL, 0x63A05F4C122871CEULL, 0x4BE1C7D2F316E113ULL, 
            0xD4C848B5490F9B58ULL, 0xBAE8F46792AB7622ULL, 0x6531933AA329C3E0ULL, 0xDE58F92AF959056FULL, 
            0xEC4689BE0F831FDEULL, 0xB5FE2056888CF16FULL, 0x876BE62A5F01F18FULL, 0x5959BF8229404304ULL
        },
        {
            0x384FB3E2986DFC7EULL, 0xF5E883CD143B36ABULL, 0x83BB376757ED5DB2ULL, 0x927334AF31C719D8ULL, 
            0x7F95F5E687F1F986ULL, 0xB01AF2FBA2F4B590ULL, 0x815AA5AABD0BAE02ULL, 0xAFBAEE50ED77AAE4ULL, 
            0xAACB4B04C9201B98ULL, 0xCB3524813DBC9DB7ULL, 0x67CB4E295CDBCCADULL, 0x0C9ED1379C870049ULL, 
            0x8643931FB42426C6ULL, 0x2BA2DB90444D2A92ULL, 0x9721719939E5DC82ULL, 0x451F3EE53E848C6EULL, 
            0x5E55A80FB639D24EULL, 0x6511B9402465800FULL, 0xB380F18C14A45C5EULL, 0x1DD15DC004298E43ULL, 
            0xA262E7727368292CULL, 0xF8FFCB0E41A442BDULL, 0x1EE80B587F5BEB76ULL, 0xD5D064FAB4E00D38ULL, 
            0xF220DB8FBCE0FE5EULL, 0xA7F04063C19618F3ULL, 0xC2912E4A26AD4F27ULL, 0xAB517E8B87EDAA6CULL, 
            0x205EABD5F3D17FB7ULL, 0x3AA01943ACD28FE5ULL, 0xA550AAFE764CB6E6ULL, 0x7FBED3CD88DA8F78ULL
        },
        {
            0xA4EEA8D83FE21B6AULL, 0xEDB37D155E1FDF38ULL, 0x959DB8284238A886ULL, 0x96EFC0E15B428714ULL, 
            0x4B051A35E123F69AULL, 0x6EB380D8DDAE48D0ULL, 0x6B4038DBA85CC597ULL, 0xFB0EEE81F9129845ULL, 
            0xA53D736D791F9169ULL, 0x49E997D1BA5032AAULL, 0x11CBB08880EC9B7EULL, 0x604E7E6F6EA4B938ULL, 
            0xC4CB4A49730393EDULL, 0x76D53DB53CD5CAF4ULL, 0x323A9654A7BB6C03ULL, 0x17CFD6BBD1858858ULL, 
            0x39CA84831D022A60ULL, 0xA5CA274C840C1A1BULL, 0xA5FAD56D9533D161ULL, 0x187E79874C22AAFDULL, 
            0xD97318F191181D16ULL, 0x5423347FF3DF4869ULL, 0x2C30F488A62CEAB7ULL, 0xE8E8A910E970DC96ULL, 
            0x4B97581100699C12ULL, 0xACA1FAFE150B2F72ULL, 0x065EA47097C74F72ULL, 0x187D0F0508872368ULL, 
            0xB2E67F7FA8E4B29FULL, 0xA58B95EEA1328A3EULL, 0x18D541742E233468ULL, 0xDBDDBC90944C3A4EULL
        },
        {
            0x58F7A953B67E600BULL, 0xDEB51BAC02E2B030ULL, 0xD4BCCFCB98934FF1ULL, 0x610B4C1FF07AB937ULL, 
            0x1229C0E7DDF6728AULL, 0x3B8600A0C3B5E513ULL, 0x5EC2140AD471C914ULL, 0xC44DDFFA614D6054ULL, 
            0x71FD8F402CF5FBA6ULL, 0x0CA1F4C00D7264E1ULL, 0x7174A3CE6582B8B7ULL, 0xDE9469DDA6C133FDULL, 
            0xD184940573EB9640ULL, 0x73A10ED89DD7FB05ULL, 0xB18EC99DDB12A17FULL, 0xC19C5ACCAD20DC8CULL, 
            0x4F650AFC6A57F01FULL, 0x1D38F5A86981D3BFULL, 0x0CF3FC27DA5CAB50ULL, 0x57D57D7C100BD810ULL, 
            0xBDF660F9B9430457ULL, 0x904D376890C1C28DULL, 0x77EEAC380EA9BF85ULL, 0xD088C0FD432992DAULL, 
            0xDDD065629E36DFADULL, 0x33066E0B4DDE1EFDULL, 0x4EA05FD9378FE20DULL, 0x9B669594F38EEFF3ULL, 
            0xD46D4424004FA9CAULL, 0x58ABA622F15210C1ULL, 0x750E137AF080A44BULL, 0x1629E7C26AD99628ULL
        },
        {
            0xB3E6728CA8F43C69ULL, 0xEA54A2C8FDDEA29EULL, 0x595795602B0A34B5ULL, 0x862090639AD19BA4ULL, 
            0x93EA977427BBF8FEULL, 0x5B86153C62DEED69ULL, 0x5A154746F7124A14ULL, 0xDB93ADEF5F58AF52ULL, 
            0x0F59296E103869C8ULL, 0xA854C606E8F13810ULL, 0x0487793ED8FC5B96ULL, 0xD4A1FD3F69D3FA91ULL, 
            0x08936AAFD705D2AEULL, 0x3BDFD49728E134FCULL, 0x5D5529F8AAC9BD5FULL, 0x74ECC1632EA9F6FFULL, 
            0x568FFD157A3294E0ULL, 0x4B05AABCD495A0BDULL, 0x588F24D736B3212CULL, 0xB1DCB96467802FAFULL, 
            0x692BB1D255A2CB5BULL, 0xFCBC930CCE5DA6E1ULL, 0x43884AE3365BF191ULL, 0xD06AC2AEC56788CDULL, 
            0xC05A7D326AB4DF49ULL, 0x42E5B226E062F7CAULL, 0xCEF4970E140AB58AULL, 0x02D612A4A0586B7CULL, 
            0xB5CAFBB4BA5B11B7ULL, 0xBFB02051DFE4220CULL, 0x6200E70D5F024FABULL, 0x6215BE844D6F82F7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseFConstants = {
    0x89A10E70BBB2D89CULL,
    0x9257B498E0F547B2ULL,
    0xF291C4CC15740872ULL,
    0x89A10E70BBB2D89CULL,
    0x9257B498E0F547B2ULL,
    0xF291C4CC15740872ULL,
    0xB61102FD0AE75333ULL,
    0x096EDED142D3EEB2ULL,
    0xD2,
    0x6E,
    0x14,
    0x9F,
    0x0E,
    0x8D,
    0x18,
    0x64
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseGSalts = {
    {
        {
            0x3C22725CFF92E558ULL, 0x9F57903B45051720ULL, 0x86DB9BCABE875D62ULL, 0x9801177E4381A39AULL, 
            0x120FAB34F59E7061ULL, 0x097B17C1C2B23962ULL, 0xC0864A056F6BBC1AULL, 0x8004AFEF56634E07ULL, 
            0xB05CE433905E5EECULL, 0x5ABC69A9BCC571CFULL, 0xA44CD61537026858ULL, 0x3A86B625E2B93607ULL, 
            0xD8C8DD978314F62AULL, 0x19BB8999C19392A5ULL, 0x07FE8561DA66468BULL, 0xEEECA87645394C14ULL, 
            0xB44FD78E856796C5ULL, 0x92AE7C3C5D9EBDC9ULL, 0xCB8A43AA7ACBEDA3ULL, 0x7F649E7F3DC90570ULL, 
            0x4E70C1BFD6CBAA2BULL, 0x1F65EF79255A4E13ULL, 0x58235B034BCAB6C7ULL, 0x1A636DE2B9C2A3B2ULL, 
            0xE938179E07D39E76ULL, 0x1A80B800B9AD8355ULL, 0x1A96439C24C92178ULL, 0x70F2B450DE91AA86ULL, 
            0x1D6964FA00CB0D81ULL, 0xCA4BED7033A1340CULL, 0x1ADAA61F83EA1A09ULL, 0x519F431B696BB49DULL
        },
        {
            0x5C4C69864FA6773FULL, 0x2C2146FFB2A569E3ULL, 0x249D7496AD87754DULL, 0x0E4739EB65D79023ULL, 
            0x2A22650660EF2B8DULL, 0xC237DF711E13A931ULL, 0x83DC05B010AFF66BULL, 0x99A7A475522DE7F5ULL, 
            0x2D6EC4FC946211CBULL, 0xF481C0F8C1257342ULL, 0xFA48213B76755D91ULL, 0xBCAA43605BA96AE2ULL, 
            0x89C9E5E210AB3828ULL, 0xEC7464F881E57FB7ULL, 0x4B5BE6E5ABEBC674ULL, 0x97D71E8AE67BCF78ULL, 
            0xD05FB5A6212E0531ULL, 0x9072B947B643AED6ULL, 0x1F2542497CF59704ULL, 0xDFB7C212AA339E5DULL, 
            0x13D354F85A394FC4ULL, 0xCEA6E354FB41D337ULL, 0xE142567F719AA2A3ULL, 0x1BDDED0BFFEE870DULL, 
            0xDBCD442C2758FF05ULL, 0xDB6E823A5D185B3FULL, 0x94E491823BA0027CULL, 0x93B19D22B4214BDCULL, 
            0x5389D9F1B01D1B7CULL, 0xC9DAC4CFD67F7888ULL, 0x8C855A331DE0D44EULL, 0x2B490D4D99165D84ULL
        },
        {
            0xBBBED035CE05EDFAULL, 0xA93D21C8B00E9051ULL, 0xE6C22AB97A0DFE0EULL, 0xAF2C4E127A98191AULL, 
            0x684B736CE81623BFULL, 0x014E77FE2F8438C3ULL, 0xF8B1E6E996A873F9ULL, 0x661325C762D36528ULL, 
            0x6C00EAF068A85FA4ULL, 0x1CFAA3DF45838DB3ULL, 0xED67F9D185F18036ULL, 0x348F8C20F08972BDULL, 
            0x582B1A8A539ECD3EULL, 0xEEE2F86B3AB6D709ULL, 0x1CA8009D8EFE5B7DULL, 0x904FEF0E0481176FULL, 
            0xFDA0A6DC7D68270FULL, 0xB34A06B261C67758ULL, 0x5CF0365E4849FB8DULL, 0xF8032C031B5883CFULL, 
            0x71F01F5942A37449ULL, 0x1ADC62C92317BAC6ULL, 0x0945106B03597467ULL, 0x5E34C5AFF463FE7CULL, 
            0xE3F617AA72A0E763ULL, 0xC00F667F00B1C4DEULL, 0xB815297E312C20C1ULL, 0x1B61F0E55AF1D326ULL, 
            0x587F16BF547C9092ULL, 0xB30A67B352B4A3A4ULL, 0x70CCEBFD490DCDC1ULL, 0xA24D7B3A25F12777ULL
        },
        {
            0xB6DAF266E836A511ULL, 0x68592FEFC4D29C92ULL, 0x573658095291610DULL, 0xD2166F846308BFC7ULL, 
            0xA862346B5B5A5E7BULL, 0xEBB65513DBD8B8A5ULL, 0xF824C0AE6F7FBF18ULL, 0x119926C680174BEEULL, 
            0xF8229A2DD0317683ULL, 0x66B9B892BEABA0A1ULL, 0xF60C22CCAD682414ULL, 0xF1D5EDBC0D20E09CULL, 
            0xCCAE55DEE436B05BULL, 0x1B38D44A95C2CD8DULL, 0x12A78BC98519D078ULL, 0xC8E9FD7BCB0109BAULL, 
            0xCCC78718D199E9E3ULL, 0xC89EAF745DD15DACULL, 0x8442478A24E8B1FFULL, 0x5EA3C7B6E1417D00ULL, 
            0x60BFC5E27A44DB95ULL, 0xDFADD19BE79A95B6ULL, 0x917C0E67EB1898BBULL, 0x6C1567A5C0048DD5ULL, 
            0x4792E6CE41868D61ULL, 0x6F175FE1F0D441DEULL, 0xB074A86BB1F33426ULL, 0x9718029EEEBCF911ULL, 
            0x65E94BA6266F900BULL, 0x036E762E042167C1ULL, 0x630CBA49AF896711ULL, 0xB10A7DC77978ABF7ULL
        },
        {
            0x202EFCAB7BCE9202ULL, 0xDA7F6B989483A730ULL, 0xE10F7397EE96F938ULL, 0x1BC47DB7B534C32AULL, 
            0xEE14D9F62A95592DULL, 0x7766CEE123CDCF0CULL, 0xF1C83530E68A40A3ULL, 0xDE67BEA4C5B26944ULL, 
            0x9A27E77081E9E5D6ULL, 0x5FB649C2D2F2CB42ULL, 0x8E7AAA9C67F4D0FFULL, 0xB9F733E8CB50C67AULL, 
            0x7FC24B801CD3CC3EULL, 0x6F34D324E0ADB8C3ULL, 0x53636C205AC1B810ULL, 0xFAD1F10F6D9ED917ULL, 
            0xDDF51547CDE01E0DULL, 0x252C635C798A4C38ULL, 0xCCAED1D653CC1260ULL, 0x9DEA868A2E88FC91ULL, 
            0x1BBDEEDECFACE5B3ULL, 0x51B71129F895E1DFULL, 0x6F261A2849DA73DEULL, 0xD1747C532020DEF0ULL, 
            0xC0FF198A985FA630ULL, 0x0DD7304180F46721ULL, 0x781FD0DA82CE9568ULL, 0x2080B4E3CF80AEF0ULL, 
            0x36CC0A19011B5588ULL, 0xC3C8AB31DBD549F3ULL, 0x31D76FB841E23D91ULL, 0xA86367C59E035C66ULL
        },
        {
            0xAF9BF5CC54BDA655ULL, 0x0B0FE59B0EC75875ULL, 0xDF056FAF1CDBCAE3ULL, 0x1B9E515C7FAAC0C0ULL, 
            0x6BA03062749D6AFEULL, 0x0350DEEB9C6DE80CULL, 0x3708558975FEEAF2ULL, 0x66634628EC49DF7CULL, 
            0xF9F1395C47501425ULL, 0x50AFB5791DE1C795ULL, 0x9739E2E4FED2074EULL, 0x8ED0EDFCB12B1BF0ULL, 
            0x4EECD0A64DC0BD49ULL, 0xBFEC73A6AC52B120ULL, 0x4E4989B5E037FDBEULL, 0x776A8E136EA31D2DULL, 
            0x2F1B6A7C12F6D873ULL, 0xEB9EA6D1571B1E22ULL, 0xC590EE64F23F93F8ULL, 0x39C6FBD7F660F88BULL, 
            0x8B86DC0D03D45974ULL, 0x86C1909087946748ULL, 0x8F038FC339FCF362ULL, 0x6881B1101D5B7B4FULL, 
            0xD98E1020A00FBB63ULL, 0xA52796CF13B0AA5FULL, 0x8798C610B76CA665ULL, 0x92A6A9D27FFE744FULL, 
            0x83AB6E9D67A4115FULL, 0xB8FC999874A4C9ECULL, 0xC6B0D859BCC3B85BULL, 0x0102CC0373346799ULL
        }
    },
    {
        {
            0x35570F1394D8883BULL, 0xA49059D36B7F7512ULL, 0xC3D33136A67F69D8ULL, 0x60725C6E550F01DEULL, 
            0x6075CD3DE7007602ULL, 0xFEFE463E414CAF08ULL, 0x96C19FE341F24C4CULL, 0xFB971A9B701308A1ULL, 
            0xB55B8438B4738449ULL, 0x89F4435E35AD75D8ULL, 0x9849FC9CDE3F92F8ULL, 0x811E0613D74440FEULL, 
            0x32B2C157450D7AEBULL, 0x3271BF920EA628A1ULL, 0x9DF4A6EDF1118ED6ULL, 0xA0AAE57F6C2FE9F4ULL, 
            0xA9374DCABBD26765ULL, 0x03C7338C72F4B194ULL, 0xF6B00E109FDBE73DULL, 0x07DE7949143C0A4CULL, 
            0xFAAD986FAA0062A0ULL, 0x36DFE765DDC1F8CEULL, 0xEEB1D3CD314E535AULL, 0xC3FEA81FF44465A4ULL, 
            0xD19A37158DB16C4AULL, 0x7ADB7DBAA217BA71ULL, 0x8082C1050B984499ULL, 0xEDD32246E18981A7ULL, 
            0x4594F26E1533BA60ULL, 0x7B3970A3CE653A7CULL, 0x40903D2C97F99A11ULL, 0x14A080D14C8ABF28ULL
        },
        {
            0x85DB6497183BC9A3ULL, 0x78025A98C57D57EDULL, 0xCEA5C4D82B9249C9ULL, 0x6C8F0D7DDC21754CULL, 
            0xE6C6F8126FC93175ULL, 0xFC53D87CB5E8BD2EULL, 0xD9046A78B7F24E50ULL, 0x264026984961DECDULL, 
            0xF4E725A8A8870975ULL, 0xC132898F3559B43CULL, 0x4AF22E3310606C79ULL, 0x8269423C55037257ULL, 
            0x340046D83EACF3F8ULL, 0xF06EE97B1BDCAD1DULL, 0x73EC80FAD85D0B1CULL, 0x01A522CBEEDEE9B0ULL, 
            0xBD7FE10EB3E8E542ULL, 0x922283924D01BC22ULL, 0x8E703BEBF39C42A2ULL, 0x68BB08EE512044F1ULL, 
            0xF075BF0EC68FEC5CULL, 0x2A686E398F1971CAULL, 0xFDE903B9CF5E8386ULL, 0x35334F0F0C885FB3ULL, 
            0x96FAE4FEC2A12C62ULL, 0x682C2E9821E3DE46ULL, 0x93AF8B7FDCDE6CEDULL, 0x8E1370658063999EULL, 
            0x3B555BC39F0E0E5BULL, 0xC0BFCC50F55D452CULL, 0x0B9BF67EEB2C42DDULL, 0xEF97AC5D87A0A9CDULL
        },
        {
            0x1978563CAD625A9CULL, 0x7C8327E0A97DB2EAULL, 0x42069C529E4533FDULL, 0x3C7371E495D9C856ULL, 
            0x09171D8FDF4DEEC5ULL, 0x349BF227825AE959ULL, 0x44F288183480A4E0ULL, 0xF3F300578C23D2C6ULL, 
            0xC2161A969F94E9A4ULL, 0xF17D04FFF4B68039ULL, 0x916710C32E226688ULL, 0x5A60C37C186078B0ULL, 
            0x8171BE18686016E1ULL, 0x59FAFDF02289BA7EULL, 0x2F0F839514B268C3ULL, 0x01150CB1521338FCULL, 
            0xC165A974CDD7CD46ULL, 0x610590DE455AA7C3ULL, 0xA6FDD2A66779FBBEULL, 0x3B5795AF6522DB5AULL, 
            0x7B8EA0046F4BE7F5ULL, 0xCC47AD4A91C83441ULL, 0x3F17A79D192B4706ULL, 0x79487F979F407A8EULL, 
            0xF86BC631E2B6AC01ULL, 0xD72B6355139614C1ULL, 0x7B9AD7273E61D04CULL, 0x8665A0025843F40AULL, 
            0x2C778FF61975EF6BULL, 0x246854A6BD5AAFF3ULL, 0xF8698BB0715F4D75ULL, 0x6C25BC5762727DC4ULL
        },
        {
            0x69C35491739AD98EULL, 0x1A2453D1A6CDD602ULL, 0xD7DDBDDDA745D586ULL, 0x6FA25385E728239CULL, 
            0xE07EC3679A9E0E12ULL, 0x01C9F3798030201BULL, 0xD762CF43CADEE997ULL, 0x36B8A70C4B44B7E2ULL, 
            0x9919B3755AEE75B6ULL, 0x5F94DED60785F259ULL, 0x317791A8903D0584ULL, 0x0E6F5184304970FEULL, 
            0xFFA2B1252E197566ULL, 0x5FC1124FF6312050ULL, 0xC5B793F3D5E7A64CULL, 0xCB28F02F4FE38BA0ULL, 
            0x0AE5306946147394ULL, 0x4908C5A96DCC0A98ULL, 0x9A68C9B3A952C0E6ULL, 0x193A6C249A86B23DULL, 
            0x66F2D458876E0823ULL, 0xCB2B87C2351E64AEULL, 0x2D1B081700CD2220ULL, 0x96A4DB733C7B0481ULL, 
            0xE8C5B1AD0DE8B2D1ULL, 0xF826158555141EA8ULL, 0x59335CCF36F0A358ULL, 0x11300A5E99275E1DULL, 
            0x76D15B96CEF945CAULL, 0x0660306655AAFE10ULL, 0x558A45FABD35F50DULL, 0x22EED42E57F0740DULL
        },
        {
            0x95E3D680E4801392ULL, 0x222BA6E2DABA3A68ULL, 0x3102C8DC7D782422ULL, 0xE08372DE62B80BF4ULL, 
            0x8BD067BC7E29669FULL, 0xBD6F11FD04D87AC2ULL, 0x02C32417E2EAC224ULL, 0x76C1DB51C630DF68ULL, 
            0xC16743028C794139ULL, 0x23E98843AE3EEAB8ULL, 0x9BC195DEB84265CCULL, 0x3E7BFED73AF7DA40ULL, 
            0xC55C78DA1C837F5EULL, 0x7FBA58EB7DC2A0F8ULL, 0xEAB571D77FF8BDA3ULL, 0x89BC31C01CD539E5ULL, 
            0x02600D0A39A2F042ULL, 0x225B18844DC13088ULL, 0x474F2F8B607FB0B1ULL, 0xCABC1ADC5B868D00ULL, 
            0x9B94B5C73B14E9B1ULL, 0x6861CE2A444D586DULL, 0x736E4DEE07944A36ULL, 0x96B23CCA19127845ULL, 
            0x471B0453B35AC8E1ULL, 0xCBF8B3048F13F6EEULL, 0xC3622E4B74C2877BULL, 0x6DD7F8EE093A4C91ULL, 
            0x9089B98EAE433A4BULL, 0x7FD22195BE9BCC83ULL, 0xCA0818FAA932E23FULL, 0x29DAFC29D44609B8ULL
        },
        {
            0x592F8368A60AD1C3ULL, 0xE90F8DFA9524DF90ULL, 0x3550B3D7BC0368CCULL, 0xEC021928F9B3B3E2ULL, 
            0xF128CCCD1D02751CULL, 0x1831D0946DAA0DACULL, 0xC0E3913D9249568CULL, 0x837AC6CB081991CEULL, 
            0x876E7C5EF82536C8ULL, 0x2AB1A44B0BABAC31ULL, 0x213620A4B71D766FULL, 0x10831450F7CF77C3ULL, 
            0x7C94222793086E38ULL, 0x5FC7A3F701624E59ULL, 0xEF20117CA5AB4DC3ULL, 0x15C8B98BDB9B02DEULL, 
            0xB5FF7CA56EB5684BULL, 0x3F186C68A60ABF96ULL, 0x336C3B5085092E10ULL, 0x430E126929252A31ULL, 
            0xC87E4C5A425F8EDEULL, 0x154CF31E6E160665ULL, 0x940B62E8D92E2787ULL, 0x83D84C5AD7E8FA9AULL, 
            0x2A5D11D4BA695DE9ULL, 0xA3191010A3AA20B6ULL, 0xC1C4726886C39FF4ULL, 0x648E9DE646F315CEULL, 
            0xAC6503B80839709EULL, 0x3869C4009A39D547ULL, 0x0B0C9C28E7D1E0F7ULL, 0x13189CA5283FBB2DULL
        }
    },
    {
        {
            0x82B43FFE88CCEB12ULL, 0x207F0337C3D25B31ULL, 0x21E5664406A8A4EFULL, 0x530992B8F3EAE9D1ULL, 
            0x8E950EEAC4203E5EULL, 0x99AC136A9574853DULL, 0x1BFB34C127AD6CD4ULL, 0x4E6DFEF699F7929BULL, 
            0xF88FABEB0DE09999ULL, 0x20191F67A9B756DDULL, 0x463C9DB848B0C22BULL, 0xCB0E3EF44125CF8DULL, 
            0xF8D3D5BFB43EBD2FULL, 0xCE1BC186E220817AULL, 0xBE800C52241181DEULL, 0x0BE0223D7267FA97ULL, 
            0xE2FDE4BF3CCB20C0ULL, 0x129CE5EB93895814ULL, 0x7902F7F6191B4976ULL, 0xF1390AAC4BFB729DULL, 
            0x3BDA404245E53F4DULL, 0xC57057B80AC22613ULL, 0x0088EB044065A233ULL, 0x9686CB6D7CA0D8CEULL, 
            0x7F699E7A6F4E619AULL, 0xA145C4E86F1950B1ULL, 0xC86A68588E11C5FDULL, 0xDC3DC5B1226769BFULL, 
            0x7695BA546C5DD9D8ULL, 0x229133BE40677F10ULL, 0x73B373FEB3E72C64ULL, 0x1E385AA8B52F211AULL
        },
        {
            0x15920C6DC697DAD7ULL, 0x90A5B1CB4E53EE8CULL, 0x90C3BFB14E112612ULL, 0x1C03568C25A8DB8CULL, 
            0xFD915F210137B4ACULL, 0xBD165037BAAC6236ULL, 0x30837E8B8545ADF6ULL, 0xE08101BC932088DCULL, 
            0x05D7B372A3B9C6AAULL, 0xD774FD7B331E16BCULL, 0xEABED806FDEDFE7FULL, 0xEE70BD2FF2C2B314ULL, 
            0xEE6E15F3342C0350ULL, 0x134D4F6EA4FDFF2AULL, 0x41C2D45EF6A713A2ULL, 0xDE6E9263EF7D2664ULL, 
            0x03AE92C51D02C74DULL, 0x69364AB42DFC2B27ULL, 0x283C8BD9C294228BULL, 0x469AD2D75B115FA6ULL, 
            0x79F22A4D3B941374ULL, 0xBC1488EA3913DA23ULL, 0xFE562606413D825AULL, 0x94854EDB755B17D7ULL, 
            0x907FC5AFE888A554ULL, 0x16213CB131C5715BULL, 0xC5CE77CE5041E869ULL, 0x9B3DE1B04D14AD6EULL, 
            0x45FA6ABC7674943BULL, 0xC45954AB1F9342FFULL, 0xC817C97146CDB900ULL, 0x5AE4FC77A9F932CEULL
        },
        {
            0xC00DF048425B58CEULL, 0x1171FCE89624E42AULL, 0xDEF974EA8C46A6AEULL, 0x358A2FAD25EE6BE5ULL, 
            0x2EE776FBDCF10DF2ULL, 0x0ECA11E7ACC11423ULL, 0x8DF7DC9CB5A851C4ULL, 0xFE00B3E9663B5259ULL, 
            0x15A229A43E82E2DBULL, 0x94686902B89DAC21ULL, 0xE64E4DB504CD4617ULL, 0x5E4C1E9A0FFF726DULL, 
            0xD26EC8F4841D9DEAULL, 0x8B48448EC27DA084ULL, 0xBC31040AB2D07643ULL, 0x4FD1604E02C5D3B8ULL, 
            0x01CEEF18E90B6CD3ULL, 0x8F3250690FCC2872ULL, 0x057F2473DFDFF7E3ULL, 0xB6CECB1911FF339FULL, 
            0xC7259AA8CC893A31ULL, 0x30B35EE3E740D036ULL, 0xC5AA562B965AFA4CULL, 0x6F5A15D444640A94ULL, 
            0x269CB30E02B48059ULL, 0x3E44BA078E0D9913ULL, 0x273AE4DD6BA6B72AULL, 0x953371448CA8F6EAULL, 
            0x1A9630873FD8F131ULL, 0xF62CA1D6B36E7388ULL, 0x12C9585C427C679AULL, 0x289E79B989C1CA80ULL
        },
        {
            0xEC21975F8534BD7EULL, 0x19CB7BEE0FF990C1ULL, 0x96DD834CAB740D7DULL, 0xA6886884787D3C4AULL, 
            0x3575ABA437B43BDBULL, 0xCF6926D644B8E759ULL, 0xA1FB947AC4FF77E4ULL, 0x4FE472024B18E74CULL, 
            0x06B21DEFCFD7B803ULL, 0x351C0D3678D773F6ULL, 0xDF362790B348E46FULL, 0xE688FAF4CA9D31C3ULL, 
            0x91184973B56F982BULL, 0xDBAFFB91F26DEC6BULL, 0xAF43F5E4ADA757E1ULL, 0xB4B53A26EA9759BAULL, 
            0xAC67AE5D2CB4CB76ULL, 0x312761CF496F5C30ULL, 0x96888F387444649CULL, 0x3B3E99C8C0E3F49CULL, 
            0x4E16F17B3C5DBA1DULL, 0x774796CD6504F0EFULL, 0x728294DC92D2EB27ULL, 0xECA99F2BFAB08E2FULL, 
            0x92966E715501C8EBULL, 0x081E24150C938672ULL, 0xB70C0BD2CA916B23ULL, 0xBDAB63D13751A4FAULL, 
            0x8EF25F71B526FEA7ULL, 0xD504A9AAC806B03DULL, 0xC37A5CA4275ADA7EULL, 0x705722DBCF806E2AULL
        },
        {
            0x774734F42EBF1869ULL, 0x315D7BCD64F33314ULL, 0x9B0E33969A1087AAULL, 0xFEDD115419BFCCC8ULL, 
            0xFF87FAC02273BB68ULL, 0xA6A3EAEB7FA5431CULL, 0x2622A7368DE2B9E6ULL, 0x721E005BC8464496ULL, 
            0xF93F86FDFCF4B443ULL, 0x6B646476A8F2356AULL, 0x60E0A23A6036BF12ULL, 0x73E07FFFB44372BBULL, 
            0xAED14F32719CF48CULL, 0xE1EA256EA00CF58AULL, 0x482E44AA3E37790AULL, 0x0F87D9B3544BA9E2ULL, 
            0xA6C418A14FB79BBFULL, 0x52C9089F480C76FFULL, 0x662EE1179243BD0FULL, 0x13AE84B8615AEE73ULL, 
            0x06B0A5DD03809260ULL, 0xE141C29CEE5C5819ULL, 0x3E61951AE3403606ULL, 0xB796AFBF1BBFC9D3ULL, 
            0x05449E04666C8FA1ULL, 0xD09A420B797934ECULL, 0x3C1EA83C6BC4AD55ULL, 0x50258E1411DE80DBULL, 
            0x14C9673D54D4BE9BULL, 0xF9CC3EBEC21A1845ULL, 0x89D9402D5470F76BULL, 0x987CB8146726B80DULL
        },
        {
            0x4B666DCDC2352D7AULL, 0x66FF32C84B2B5A18ULL, 0xE0A014354E930DAEULL, 0xE8A0A2C13E5D935BULL, 
            0x0107C720017F5BDCULL, 0x7B526158FA1FCFA0ULL, 0x9438441594C1BFC8ULL, 0xB318512F51AC73DAULL, 
            0x3010981FCC9064B6ULL, 0xDAEE6CDF7321C4B7ULL, 0x073FF79A9A2B7798ULL, 0xF7468D6D5A5F018FULL, 
            0xC27242E34ED6D580ULL, 0x34BFBFAED34339E6ULL, 0x93728DFE6456C5C1ULL, 0xC4AFA108126E67AFULL, 
            0x7C04769A5485302BULL, 0x3AE34E976AA9FF8CULL, 0xD0E81D2BA26E0343ULL, 0xCB519C936D24344EULL, 
            0xB8508935860850B8ULL, 0x7FD7F498E164C878ULL, 0xC92A511718CAEFF1ULL, 0xDCFC6BCB123A8DE5ULL, 
            0xFA7B5B04BA24C8E4ULL, 0x81F0487CD17F6CFAULL, 0x04F02ED4C2204C1DULL, 0xBA7920E37D7C865CULL, 
            0x8FE5CC5B31AD176AULL, 0xB2F933D3E4571AC0ULL, 0x82CBC0E062D7996DULL, 0x7D5E6B3F9FCF36C2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseGConstants = {
    0xC04B1AD8305CC353ULL,
    0xCC8CFD7E457673D5ULL,
    0x8DA7B1F66C72B53EULL,
    0xC04B1AD8305CC353ULL,
    0xCC8CFD7E457673D5ULL,
    0x8DA7B1F66C72B53EULL,
    0xBFA4956E689471A8ULL,
    0xA4BD4A8E6E14A539ULL,
    0x56,
    0x45,
    0x0B,
    0xFE,
    0xE0,
    0x43,
    0x70,
    0x6E
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseHSalts = {
    {
        {
            0x612772FD2F78AD1BULL, 0x019987E93759F338ULL, 0x687571AB0F853B3BULL, 0xBD699D6E1C36B30DULL, 
            0xABBD9C3C278D74B1ULL, 0xFFCBE67696227E11ULL, 0xA75B29DFCC7BE238ULL, 0xEEF25CF623F3119DULL, 
            0xF081654D5BD41DCAULL, 0xB02BDA592E058D5FULL, 0x983F342C1F8877C6ULL, 0x25E554CB3A56DED2ULL, 
            0x6F180FCBF5252E3CULL, 0x616A344E9F5962FCULL, 0x794AEAF26907195EULL, 0x7876C88FF8895F48ULL, 
            0xADFA062CA7A27394ULL, 0xF16AC96E2BAEC5A6ULL, 0x9A0A41D1CF4A49EFULL, 0x29E133015A79D3B1ULL, 
            0x2CD7AB51A04F1437ULL, 0x7E07516DC8CDEE36ULL, 0x75CD5CF078DF5702ULL, 0xC685C116C32A8853ULL, 
            0xD5C2F82928C683EDULL, 0x107638747430AD54ULL, 0x7B2CACA767944427ULL, 0x64D55E5BE0BD0CF9ULL, 
            0x31CB1E0639C6D537ULL, 0x24F1FF9EEA207BE1ULL, 0x95730D8AB5585A9DULL, 0x0F30986AE45F6108ULL
        },
        {
            0xB03A4035BE59E8EFULL, 0x2C0A7B0A4C1CF019ULL, 0x19B77DA5F6A28379ULL, 0xD56239FDD9D48EB3ULL, 
            0xF8C02FFE04C7C1BCULL, 0xF93B811170B5C206ULL, 0x81468DE51CA66FAFULL, 0x22B9D529A1E8CF77ULL, 
            0x084DEA086185CA09ULL, 0x1B18F7B6F3B7A8D0ULL, 0xF5D9D000AE0CAB72ULL, 0xC29FBBEBB95FE198ULL, 
            0xADE275D11B098E29ULL, 0x3897921A3A45FC3DULL, 0x8D0F4FEFA8D42A1FULL, 0x89B51113BFF941BFULL, 
            0xE81A0C19561EE162ULL, 0x004833A473C551CAULL, 0x190D8B9B4F82EDF3ULL, 0xFE2ED3AC244E6EDCULL, 
            0xCE9D3337169F0556ULL, 0xD6BC17DB82FB4A3CULL, 0xC2E2D9738C5D5667ULL, 0xB7593892975ADF45ULL, 
            0x4265593C3F2C8B84ULL, 0xE07218BF3C443C6AULL, 0x42D1B8E7E6C51210ULL, 0x7B97E97E13A4A288ULL, 
            0xAC938A760A652B8BULL, 0xA085F86030BC7106ULL, 0x19F4152CA034E4CFULL, 0x64EFAE76BF664AFAULL
        },
        {
            0xFAB666CC87B325A5ULL, 0x83859133B182D34EULL, 0x09CE2B035A3E5020ULL, 0xDAD719991386D9F2ULL, 
            0x218033A8C537DC44ULL, 0xFCE0F92BB688CC20ULL, 0xA5A8840A4C1FE2D3ULL, 0xE3BA2AFBD00A6617ULL, 
            0x3BB11E151A0B8B03ULL, 0x69E9C29A2F79BADCULL, 0xE5DF3AAB7938B74BULL, 0x36D9B7E0F90110CAULL, 
            0x9B6941C1D7E63316ULL, 0x8BCF3C9BA5EFFD73ULL, 0xB3143DB0C8EC948AULL, 0xFBBC0FF3D52E2E50ULL, 
            0x13F02E2535BA0C52ULL, 0x17E6AB849A189BF9ULL, 0xB83EE3D859E8B1D3ULL, 0x9686A2CC819B9615ULL, 
            0x17972044EAC63C4AULL, 0xC186D89D224CD633ULL, 0x7299E7E769EC7B35ULL, 0x43E3A515291F1A65ULL, 
            0xAF3D86EDDD3FD773ULL, 0x82A2B7CFD4E6C25AULL, 0x948C1A69D7B8EEABULL, 0x8CD4A3FB17A17DBFULL, 
            0x776EA6C35324E929ULL, 0xCCD73FAAD360BE43ULL, 0x1791E47800082081ULL, 0xCCDA312FBF99E43FULL
        },
        {
            0x3B1F6D0EF287A2B3ULL, 0x9855D83F34C1BAD1ULL, 0x922DA7DE6276E42AULL, 0x52E995DD878AB706ULL, 
            0x28DCDA560A4B7229ULL, 0x2E2BF8B96B0A62D6ULL, 0xB393DE96509B0D58ULL, 0x53072900E81EFDE4ULL, 
            0xFC68435E47ECEB48ULL, 0x436676C51538D60FULL, 0xD567848CB137AD17ULL, 0xDB216F84C92A06B8ULL, 
            0x3067AF6C4A99133EULL, 0xBFBCA9EEDE0C2C0EULL, 0x1ED4AE48F3087F71ULL, 0x7EB5D1967E3C12D5ULL, 
            0x0831DD140DC3C590ULL, 0x5D292094F4402D2FULL, 0xA1663C5301A96235ULL, 0x29B2BE649DCBD2E8ULL, 
            0x01D7E819F754C9E8ULL, 0xFED075136725EE87ULL, 0x84449D2589EDD7C6ULL, 0x4228459A15006E47ULL, 
            0xDEA911E927083F10ULL, 0x02A6D8740B6D4610ULL, 0xFF36FB21C1423315ULL, 0xF69A859BFA290080ULL, 
            0x94B71277F9E4DECEULL, 0xBCC50B0B4EDE46D2ULL, 0xFB264C62BABB8DFDULL, 0xAF53AB1C41582B51ULL
        },
        {
            0xF7D3DDB78AD02A27ULL, 0x959B59FBE41E46FEULL, 0x3071914EE1834DC7ULL, 0xFDA7D089E299BF12ULL, 
            0xD7F18E88FD22A7E4ULL, 0xFB71FF442B0785F9ULL, 0x3214D2BF0E52DE9DULL, 0x2D719D7BC5D9AC66ULL, 
            0x599B320136043F8AULL, 0x71575C0D284D47ECULL, 0x216FE803069E76A6ULL, 0x1DF1C000B2B51EB0ULL, 
            0x371013D9F3C4BDE6ULL, 0x1366C2F56BC645E9ULL, 0x29B8BB24742DB72DULL, 0x695B07BA18C7776BULL, 
            0x71EC63F552870025ULL, 0x0D7E3E5BC904C25DULL, 0xE1003643637B4838ULL, 0xCAC7212D56495CD9ULL, 
            0xA6AD585449CEC529ULL, 0xD88C6068017E73E2ULL, 0x235AE0558A8940ACULL, 0xDF027BE60827212DULL, 
            0x099235093BDC1EE6ULL, 0x8086D53A57C8D5C1ULL, 0x87D4F5E54733A7D2ULL, 0x1DCAE90297D42901ULL, 
            0xD9A2C34C6CE9DB4DULL, 0xEF18F31A07942D78ULL, 0x48498AC0D9EA0050ULL, 0x97D4698BCE407D07ULL
        },
        {
            0x1B381CCABFADE665ULL, 0x52ED5804F3AE5B48ULL, 0xA00B00EA8EA65A51ULL, 0xCBA07FCF2C14048AULL, 
            0x1B796485B53516EEULL, 0xC6A4AE1CDE22E137ULL, 0x65D77D40594BBF0EULL, 0x576BBD46C1DAC81EULL, 
            0xB057D8798E99C43BULL, 0x5F7DAC89DCC0C55BULL, 0x302853A2EF551891ULL, 0xF8AA8D3AD2521802ULL, 
            0xE959AC135AB8012CULL, 0xAB8AE3A7EB57AD91ULL, 0x74F2056268DE9692ULL, 0xB4A7B228CA1A6BAFULL, 
            0x3F16114F856369D2ULL, 0x1EC1498B7B352A41ULL, 0xF04AD940E242E634ULL, 0x1B6487A2C1BC2D9DULL, 
            0xB1D8C144BABE50A2ULL, 0xB3EB15B9FB3CAA6AULL, 0x833748DCB46965A7ULL, 0xF19F5DB3A2437C27ULL, 
            0x6E71D798E3626E3AULL, 0x236836D9D316F90FULL, 0x9AF90DEDD07B9760ULL, 0xC0665518B2B6BA64ULL, 
            0x556439CDFDC2340AULL, 0xECEC0BB193B63EE2ULL, 0xB53BDF3078F9A811ULL, 0x438F6FC881D26896ULL
        }
    },
    {
        {
            0xFF78D7F9EE891F4FULL, 0x201C51730E77A300ULL, 0xCDB6DB25540151DAULL, 0xE736786C839AC96DULL, 
            0xA102920466757F3CULL, 0x28E8E043B032E48BULL, 0xEF53C4981A4358B6ULL, 0x727FD0FF7C6168B3ULL, 
            0x30B480EAD31F258BULL, 0x39F695B615AC13CAULL, 0xD644DBD68025EE1DULL, 0x619E430C7D9AAF66ULL, 
            0x0D25EDCB77B55697ULL, 0x143EA5351FFE97F3ULL, 0x3BE1FB19BB4AA14BULL, 0xCE74AA847E5C0D03ULL, 
            0xEF9E038FA9857CB8ULL, 0x781D08AD9EDC2358ULL, 0xCA2B62EAA03011BBULL, 0x883AEC9970A02F53ULL, 
            0x2371F7459982F1EEULL, 0x168B96A9FB32F5D0ULL, 0xA5337ABD41637D9BULL, 0xD4A11E3E1769A55AULL, 
            0xBCAA9C8A7E9DB213ULL, 0x218C32DDE0BFBD6CULL, 0x371E5AC72E7EFF6AULL, 0x61884216D6D96C4BULL, 
            0x74862E34B8F244E5ULL, 0xCBAB0E156504E82EULL, 0xD796F32670A8F97EULL, 0xCB11AACE4C2F4235ULL
        },
        {
            0x01C8C8D9963C7F0AULL, 0x6BD6233BC6A5979CULL, 0xBA7C08BFFF239B59ULL, 0x5A4562A5274750EDULL, 
            0x0CE90A6C3AD6A816ULL, 0x8B5F3EE29A449D61ULL, 0x8C6C6089B2DAE55DULL, 0x95773FBF37BEFE89ULL, 
            0x0572DB396FE381EEULL, 0xA515089F62B409DFULL, 0x22274EB5DA50D948ULL, 0xAE5C5F1C0CC2B38DULL, 
            0x4E19C1AB3816556DULL, 0x8558CE6D780CBE8BULL, 0x379662AAB8E6E971ULL, 0x76D2597DA1FE52CFULL, 
            0x2A1BF0615C0E3030ULL, 0x63D3AB21C82911B7ULL, 0x85D2FAAACC7393A5ULL, 0x907755EF2587FC6BULL, 
            0x13ECE07088900A0BULL, 0x6723560B9F7EE23EULL, 0xD32EF181558438F7ULL, 0xFA2A8E673E604A4FULL, 
            0x5014613C9912697EULL, 0x4CE4DEDC22399D65ULL, 0xF3696F687FC00D1EULL, 0x9A72DED81174D6E6ULL, 
            0x3448EBE91E96730BULL, 0xEBCC5CB33DEFBAF1ULL, 0xFCB7698370DDE06AULL, 0xEF10A9AE0BA1FD94ULL
        },
        {
            0xA60FB5217B610DEEULL, 0x3CB15C504192D013ULL, 0x75EB28252B1D03AAULL, 0x7199184AD52670FBULL, 
            0xDAC3474555145DEAULL, 0x216A92E279FC871DULL, 0xDE0FED3788266417ULL, 0x5A69F36585748F7AULL, 
            0x94D8392224764E66ULL, 0xA4B6F1DB16CDA775ULL, 0x2C3DA2DEAB2E5CC7ULL, 0xD50B085D2CBEB73AULL, 
            0x6FCF293C0ED4B9E6ULL, 0xDEE4236F8E1A1DD8ULL, 0x83307539FB4B4BBBULL, 0xF394778AAD53A677ULL, 
            0xA1060958BA0E1741ULL, 0x357E0CEE67C7E5EEULL, 0x71C8F88F8A918C19ULL, 0x3B2CC1A713FCC712ULL, 
            0x0D4E611A6D9528EBULL, 0x2C5606C910EEE36AULL, 0xA84CD5246FA7A0B4ULL, 0x1C3335DFD77FB962ULL, 
            0x495231CFD1EB402BULL, 0xEA743CC649DAE751ULL, 0xB30171EA064F14BEULL, 0xA30C7B5E86DC8C2EULL, 
            0xB30BC427C4766BF3ULL, 0xC1D900F66F4D94E9ULL, 0x12434409FC4C7F15ULL, 0x6D5E7B49CC3881E2ULL
        },
        {
            0xBE243F3171914256ULL, 0x74A0BCAC8E99CBB5ULL, 0x514C8584F8C5FFB4ULL, 0x2B6586943F9A54FDULL, 
            0x30FAD6BF3BAF3F8AULL, 0x055B34F83D0FE783ULL, 0xD54813AF92763385ULL, 0xC0F6A33633BDE751ULL, 
            0x9BF02D0EAC6724C7ULL, 0x81EEC922827D63ECULL, 0x163FD73D12D0EAA7ULL, 0x370FC1C1BF75E078ULL, 
            0xDCAB6D451C16A7A1ULL, 0x6849171D4104F789ULL, 0x4367B549607620ACULL, 0xDC85265F5ECE0C4CULL, 
            0xBBD4DBFD7A16311FULL, 0xE53DC027287CDD59ULL, 0x526132BF2A43831FULL, 0xA241790B8E6E4CC5ULL, 
            0xC3FD9896D65CC4B7ULL, 0x1964BEC439921889ULL, 0x6A2DE93FB2BEF687ULL, 0x96B078C76C4969E6ULL, 
            0x6A9BC083F35A9274ULL, 0xB6031AE61E826A3AULL, 0xB967C15E87C95DDCULL, 0xA12C0AFA47010631ULL, 
            0x3F44713241D7A221ULL, 0x0C65C5658B671CB2ULL, 0x1D63B5C5D552FEF8ULL, 0xFB38798D781419CDULL
        },
        {
            0x1786EDFF064B4031ULL, 0x385AC40E236594D5ULL, 0xA38C083121A1E9FDULL, 0xD26BD671AF4082E3ULL, 
            0x3109C4126FCA3B25ULL, 0x41F7358DC39E5F71ULL, 0xF8905C8A3024FCD9ULL, 0x860732DDDC4F69DEULL, 
            0xA73860431805DE0CULL, 0xCB5F736032B57A23ULL, 0x4026E04BE23A7CC5ULL, 0x470A9B4758DA74F2ULL, 
            0xA234FAA6798ADA20ULL, 0x60DB8400AC385530ULL, 0xADB10180024FDFF1ULL, 0x1719F50AC3667FF0ULL, 
            0x5633BC100DF46D3CULL, 0x53CB95A713DB52CDULL, 0xA789617894BD97E5ULL, 0xE34AD5C16A235874ULL, 
            0x51F6C584E9BB7A7BULL, 0x3C0D336C33635D8DULL, 0x15699A3E882AF326ULL, 0x4390CC6358BC5D87ULL, 
            0x07C4861BE9E1BD1EULL, 0x9E0797600876A994ULL, 0x961858A9A42BCC2BULL, 0x2D4FAF0E3A5D6292ULL, 
            0x5A75B28C4876F620ULL, 0x04DDBD942B494A04ULL, 0x044E16FFC0D35BF1ULL, 0xAC4FFAC134D978EFULL
        },
        {
            0x3ACD0B07B97BE982ULL, 0x8192C619B37BD1C4ULL, 0x0B8BB6DF920988D9ULL, 0xEBE47881EAE5F233ULL, 
            0x53ED606BFFB0878DULL, 0xA92B04CB5AC83ECDULL, 0x9EFD5E3DADDA99BDULL, 0xE1F893F0BF478D4BULL, 
            0xAF764E1C903CE9D5ULL, 0x4BDA56DB1719495EULL, 0x194A7449E8D67352ULL, 0xCAA3BF1B01FC3CB8ULL, 
            0x2A3FBAA8126F364FULL, 0x247A15569C094973ULL, 0x2464742DC99518D9ULL, 0xD24EB923D6C49F2FULL, 
            0x56AC3C3295F81518ULL, 0x92C7BA16A2570A4FULL, 0x5F73881EFC959A4BULL, 0x69F9FC2E2EDA89D0ULL, 
            0x95EA6F994E354F93ULL, 0x7525251FADA222EFULL, 0x223C032E06884224ULL, 0x6737CCEEAED94C38ULL, 
            0x40EAFC95728ACFB6ULL, 0x872FD751F91AF83AULL, 0xD3D59D3843B9710AULL, 0x90CEB04B0D3DC05BULL, 
            0x2B499F3286F0A003ULL, 0xE9EE94D983E2CBD1ULL, 0x8057765E61650536ULL, 0xBCA9C4DCBEDC4EA7ULL
        }
    },
    {
        {
            0xC8CD931372AD1861ULL, 0xFED4612FEB97CA59ULL, 0xF782C4F1E9748913ULL, 0x134EA061580CC7A4ULL, 
            0xFAA96519765CF2C8ULL, 0xE41AB5DBFA8FC5C0ULL, 0x7121435FD8F1808EULL, 0x57C77BCFDEC7F808ULL, 
            0xD20B833712E2A3A1ULL, 0xE01559858C0E4210ULL, 0x4A8AE2E73B81A58EULL, 0x35F16179E03884A3ULL, 
            0xC5EF8CC0C18A6252ULL, 0x07DE5287B9B61455ULL, 0xB91F775788F87BBDULL, 0x328E9F9B6870BB74ULL, 
            0x63A59C14564BDC85ULL, 0xF3F91C000928D269ULL, 0x761BF07F39CB7828ULL, 0xADCEB4AA40E6391EULL, 
            0x7F0E833AC2BD96CBULL, 0x154CFFE63BF95E54ULL, 0xDB8D16A9FA3334E4ULL, 0x467599D76E0883DBULL, 
            0xB76DA357F9F1E589ULL, 0xA087248E1932B5E9ULL, 0x808D141FA6D3BF77ULL, 0x85ADF3E298EB913CULL, 
            0x1909F468C5953A2BULL, 0x3256E60A61C3DFD8ULL, 0x6F6FF7D70CA2245BULL, 0x9C20B287B703D301ULL
        },
        {
            0xA48BFF5C63B96983ULL, 0xB2E9E81A185FFC2AULL, 0x939AED4F4EF76E60ULL, 0xCB48D08C41E55753ULL, 
            0x9CF02E718D8CE347ULL, 0x0DD135EB303C7907ULL, 0x869EA599525498B5ULL, 0x21D95F04ED33848CULL, 
            0x525DC170A4E556D9ULL, 0x7F529C4EDF3505A3ULL, 0x76F7B0A78E1382C1ULL, 0x8F56E8E82A73B7C1ULL, 
            0x24EA9FDF190D78F4ULL, 0xF6B2B758DB86A371ULL, 0x7FF043846AA06F65ULL, 0x5F6633106623ED0BULL, 
            0x7D5F8B938423FCE0ULL, 0x2E4D1475D3BDC63CULL, 0x1FE5837F9CD3D375ULL, 0x73C560A785347882ULL, 
            0x09800B03F43422EDULL, 0x8D0E2965B653BE93ULL, 0xB0AA5CAB9875872AULL, 0x62B4B31826072744ULL, 
            0x1827EFD4B63FEF17ULL, 0x3F6789B94C73EAA2ULL, 0x5C7F7A68BF905733ULL, 0x0750B141B6CD4177ULL, 
            0x6BB8C7C4C92CD1AEULL, 0x49B47371DAA0897FULL, 0x134ACA87994D019FULL, 0xECE8A4B06F26EF07ULL
        },
        {
            0xFC19F39B1B74D974ULL, 0xF0F9453A6EB96F96ULL, 0xB5F5F925D7790F5FULL, 0x9F08A7852BDF0146ULL, 
            0x1A001BE01F4BC4A5ULL, 0x82E020C093C9B29DULL, 0xB76276908E0AA433ULL, 0xFA6CFA38196A2224ULL, 
            0x36BD5FCB630D0BD8ULL, 0x87E654148D32FF7AULL, 0xF99DB6E3DBD1AE96ULL, 0x16B36643A168C749ULL, 
            0xC98ABA6C631859AFULL, 0xA86DDF29E735B2DFULL, 0x8603A8021A17963BULL, 0x17F51842EF347A54ULL, 
            0x178DD3C3ED23C371ULL, 0xB6D1CBE2965F91F5ULL, 0x71FB7A7E12A39059ULL, 0xDD3EE314AE4FBF65ULL, 
            0xCA5E49A7A282C67CULL, 0xF32966BD0DC3E635ULL, 0x5F8867F44A48A166ULL, 0x8C891345580D404FULL, 
            0xEE6EC88E07E008C3ULL, 0x0998A3914C9786FFULL, 0x30FD9176B03128C8ULL, 0x4B3D0D52233D3719ULL, 
            0x51697856DBB9CF65ULL, 0x93A135CB20733128ULL, 0x74A72995F9B9077AULL, 0x2CB686DB991CEE1DULL
        },
        {
            0xAFCBCA6C4FE0AD03ULL, 0x249BCD97B34B9787ULL, 0x2785A9690D9C0928ULL, 0x1CB169A843C22302ULL, 
            0x966DCFD4AB109D53ULL, 0x22F95AF33A46C12DULL, 0x3762FA9DE93F3AC4ULL, 0xE9B4B700F2E501B0ULL, 
            0x276F86025950CEE3ULL, 0x20BED6E9AEBD0756ULL, 0x7857039070011B3CULL, 0x538987A08041F9C3ULL, 
            0x67EBBD528F4825F5ULL, 0x4951415829900D6BULL, 0xA59B869B06B256FCULL, 0x5CAB3E8AF7ED8F5FULL, 
            0x1A72E40626853E28ULL, 0x4B5FC3FE796A19D4ULL, 0x70B2D68C01BC42F4ULL, 0x037380CD7D6742BFULL, 
            0xA47A7095F387524FULL, 0xAA0F6D649EFD462DULL, 0x82A07683948340F7ULL, 0xCC77AF6F45124AC8ULL, 
            0x4BFACD6115116B4EULL, 0x7577E44689211F51ULL, 0xD192DF735BE75CD6ULL, 0x2AD891502E0B8E89ULL, 
            0x8DCC3E8848698F05ULL, 0x30F2AAB59ED79F12ULL, 0x88916FFE4AECCFF2ULL, 0xB2C4F7DD7BE0416CULL
        },
        {
            0x1F1399A9DC31A5E7ULL, 0x74C0DC2B3899478CULL, 0x7458A44C2C33BBA8ULL, 0x421A9B1804D6F028ULL, 
            0xE7CF8F079BB6F938ULL, 0x21C7A3A93CCF49F4ULL, 0x2EBFDF56B6255FA6ULL, 0x997F007076D9D596ULL, 
            0x4DB514D2523D4614ULL, 0x44E1A4A8B97EEF3FULL, 0x737B325B7887B2ECULL, 0xA2457AAFBEFEC331ULL, 
            0x33E4786AF5514FF6ULL, 0xEF826C7C82D25028ULL, 0xD3F70B77F4D1326CULL, 0x464D97D6CC9C2D17ULL, 
            0x00076FA19D2CC43AULL, 0x189FE7003FE9C56FULL, 0x737E6F67B19D74E5ULL, 0xCF73DECEA98F7590ULL, 
            0x40F4ACE140827B79ULL, 0x87BCE388C63B5B10ULL, 0x627964FA4EADE2D9ULL, 0xE2B73C4E9775D543ULL, 
            0x6AA254860A1B8BB7ULL, 0x49F49CD7BC24FB0EULL, 0x9474D71D6246A02AULL, 0x28FC9AE7995FBDB7ULL, 
            0x97E630DD78F73D92ULL, 0xE7A43C321A8A445FULL, 0x4DAF41846884474DULL, 0xF7B6C779185B9614ULL
        },
        {
            0x928D60BC573AE4A7ULL, 0x33A0426F6A904AD1ULL, 0xD637DA900488F76BULL, 0xA7987D2B8ECEF0A7ULL, 
            0x1BEA361930DBF5F5ULL, 0xF3723D597FAC511DULL, 0x06A95B033BD38483ULL, 0x56E7C55F8F50A3D0ULL, 
            0xEF3D2FD4E59FA220ULL, 0x4AACC9D41E2CBDFFULL, 0x7C6C062EEC146755ULL, 0x33921A209DD91CF8ULL, 
            0xC84B92214E7D09E5ULL, 0xA1B373F3EDD6ABFFULL, 0xCBE31DBEEDA5F9B1ULL, 0x1690DE28CA512641ULL, 
            0x988FF6A9376C5DB4ULL, 0x3167447225C4DF54ULL, 0x0C1EB7232815603FULL, 0x820051BE0E6993DCULL, 
            0x22D8FF3D1D6AF419ULL, 0x98350A6C91200586ULL, 0xD1E5F312208CFD54ULL, 0xC5FFCB157DC0B30DULL, 
            0x9D2369774DAB0C0EULL, 0x8647C50F3A391C7EULL, 0x42793C0F0C2377E4ULL, 0x8697C7804C1E278FULL, 
            0x6D97EFAF565289E7ULL, 0x7A0E0B8F8AFA8152ULL, 0x228584831343A701ULL, 0xF837B96FEC3BA3C4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseHConstants = {
    0xCEF41485D083BC7EULL,
    0x277BD35BB91FD9D6ULL,
    0x27F6E9A2CC26DE4EULL,
    0xCEF41485D083BC7EULL,
    0x277BD35BB91FD9D6ULL,
    0x27F6E9A2CC26DE4EULL,
    0xD6634A1BAD67CFDFULL,
    0x78951F8F5F4ACAAFULL,
    0xB7,
    0x5C,
    0x3F,
    0x3A,
    0xB8,
    0xCB,
    0xEB,
    0xA6
};

