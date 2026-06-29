#include "TwistExpander_Fencing.hpp"
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

TwistExpander_Fencing::TwistExpander_Fencing()
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

void TwistExpander_Fencing::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB3CAE133F05B9DF4ULL; std::uint64_t aIngress = 0xAF635F419C7EB8C9ULL; std::uint64_t aCarry = 0xC88EC2CE4D0A476DULL;

    std::uint64_t aWandererA = 0xA6F77F61C6EDA4FCULL; std::uint64_t aWandererB = 0xD079305C9787CB1DULL; std::uint64_t aWandererC = 0xFC086C9EA7351C49ULL; std::uint64_t aWandererD = 0xD8F9EA36D2096AE7ULL;
    std::uint64_t aWandererE = 0xD0253050D06815DDULL; std::uint64_t aWandererF = 0xAD28027D25951D3BULL; std::uint64_t aWandererG = 0x92F0018713ECAF1FULL; std::uint64_t aWandererH = 0xB786A7BC84776649ULL;
    std::uint64_t aWandererI = 0xCEF055AD0732DD46ULL; std::uint64_t aWandererJ = 0xA0A2B6A2A20F2E27ULL; std::uint64_t aWandererK = 0xF1EA2D1494AE4F26ULL;

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
        aPrevious = 10167572547996186674U;
        aCarry = 15288953482555498593U;
        aWandererA = 9525003352719811556U;
        aWandererB = 14216861806780970088U;
        aWandererC = 12534783035787920770U;
        aWandererD = 16850453376476340520U;
        aWandererE = 16392335915672178458U;
        aWandererF = 9829262874237900029U;
        aWandererG = 12168398691052703634U;
        aWandererH = 17869024030255586738U;
        aWandererI = 9807295468870151201U;
        aWandererJ = 15408868608255057999U;
        aWandererK = 17759744719116713931U;
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
    TwistExpander_Fencing_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Fencing::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEEE78630DFC280A8ULL; std::uint64_t aIngress = 0x98200858DA0490DDULL; std::uint64_t aCarry = 0x81C03D528FA135F1ULL;

    std::uint64_t aWandererA = 0xDD55044E9812BCD6ULL; std::uint64_t aWandererB = 0xE3866EB6ABE58CCEULL; std::uint64_t aWandererC = 0xE6500E35A08577E9ULL; std::uint64_t aWandererD = 0xF9FA02BB283FAC0EULL;
    std::uint64_t aWandererE = 0x967D12C91908D22DULL; std::uint64_t aWandererF = 0xB47583547B3029C1ULL; std::uint64_t aWandererG = 0xF86E4969F72DC574ULL; std::uint64_t aWandererH = 0xA4D2B3A1069F77F9ULL;
    std::uint64_t aWandererI = 0xA77D9454F802F3AFULL; std::uint64_t aWandererJ = 0xA157445B70A5F5BDULL; std::uint64_t aWandererK = 0x9D60815BD68A7AB2ULL;

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
        aPrevious = 13673670090971290620U;
        aCarry = 13775767600212736519U;
        aWandererA = 12381104563606722651U;
        aWandererB = 13659619746106915631U;
        aWandererC = 13552161701076090264U;
        aWandererD = 11222440807309347538U;
        aWandererE = 17452959622526475634U;
        aWandererF = 14334074154762739680U;
        aWandererG = 13639099491972700440U;
        aWandererH = 13795869129232464806U;
        aWandererI = 17519993188625272711U;
        aWandererJ = 16443954403484654268U;
        aWandererK = 13988813109399552013U;
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
    TwistExpander_Fencing_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Fencing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8F989A2FAB87EC78ULL;
    std::uint64_t aIngress = 0xDE612156245E7A24ULL;
    std::uint64_t aCarry = 0xD759E1FC3C062E0FULL;

    std::uint64_t aWandererA = 0xD840EEAC9253AA19ULL;
    std::uint64_t aWandererB = 0xBB42CBDF876FED01ULL;
    std::uint64_t aWandererC = 0xE8FFB6F904B16B9EULL;
    std::uint64_t aWandererD = 0xC13F0AAE651B33E4ULL;
    std::uint64_t aWandererE = 0xE789A18F7313A7BFULL;
    std::uint64_t aWandererF = 0xE64FA083BD992EA1ULL;
    std::uint64_t aWandererG = 0xAF3AC94BD0C3BA95ULL;
    std::uint64_t aWandererH = 0xEF55B77208D43EEEULL;
    std::uint64_t aWandererI = 0xA609A2F789B42AF2ULL;
    std::uint64_t aWandererJ = 0xEF795A9593077061ULL;
    std::uint64_t aWandererK = 0xB57BCB01634CA58BULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneE);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneD);
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Fencing_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Fencing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFEA90D6C0B9BAAC0ULL; std::uint64_t aIngress = 0x929EB9153BF54B47ULL; std::uint64_t aCarry = 0x81EDD42900BB9E30ULL;

    std::uint64_t aWandererA = 0x9B6DDE674040C2B3ULL; std::uint64_t aWandererB = 0x9693B62FE348F431ULL; std::uint64_t aWandererC = 0xF63D03E58DEF2BCBULL; std::uint64_t aWandererD = 0xB4B0D49918DD7A72ULL;
    std::uint64_t aWandererE = 0xC5AC32B5145763ACULL; std::uint64_t aWandererF = 0xFC962692D32F8979ULL; std::uint64_t aWandererG = 0xCDC74797AC422401ULL; std::uint64_t aWandererH = 0xE880357D589B1650ULL;
    std::uint64_t aWandererI = 0x8124CC68C68D979BULL; std::uint64_t aWandererJ = 0xB61771D92A34DF30ULL; std::uint64_t aWandererK = 0xB12D33478ADFB3EBULL;

    // [seed]
    {
        aPrevious = 10605534037056968229U;
        aCarry = 14454235225858769539U;
        aWandererA = 13101502947202054834U;
        aWandererB = 16111023291871764075U;
        aWandererC = 12520400539421306182U;
        aWandererD = 17985051344700467096U;
        aWandererE = 13999281815128905704U;
        aWandererF = 10953774367453027573U;
        aWandererG = 16220294606873612946U;
        aWandererH = 16190711172432821806U;
        aWandererI = 15866840584817299290U;
        aWandererJ = 13986074289708585976U;
        aWandererK = 11994666142332860862U;
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
    TwistExpander_Fencing_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 1 with offsets 2836U, 6675U, 7462U, 3398U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2836U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6675U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7462U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3398U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 2 with offsets 6324U, 5399U, 2234U, 4242U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6324U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5399U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2234U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4242U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 3 with offsets 6117U, 5613U, 3954U, 2056U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6117U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5613U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3954U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2056U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 0 with offsets 6791U, 6828U, 3279U, 777U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6791U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6828U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3279U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 777U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 with offsets 1412U, 766U, 829U, 541U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1412U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 766U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 829U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 541U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 0, 3, 1 with offsets 735U, 1786U, 479U, 553U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1786U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 479U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 553U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 2, 0, 1 with offsets 1078U, 1961U, 1729U, 428U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1078U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1729U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 428U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 2, 1 with offsets 1868U, 1609U, 1359U, 1972U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1868U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1609U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1359U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1972U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1845U, 1441U, 552U, 1990U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1845U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1441U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 552U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1990U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Fencing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 1, 2 with offsets 3237U, 3546U, 8070U, 4109U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3237U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3546U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8070U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4109U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 1 with offsets 309U, 4385U, 259U, 6935U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 309U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4385U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 259U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6935U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 3, 0 with offsets 3049U, 3754U, 1064U, 4568U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3049U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3754U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1064U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4568U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 3 with offsets 6428U, 686U, 2339U, 7080U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6428U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 686U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2339U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7080U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 233U, 6949U, 4033U, 2736U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 233U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6949U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4033U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2736U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 548U, 1774U, 1104U, 1021U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 548U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1774U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1104U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1021U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 45U, 1436U, 68U, 1288U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 45U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1436U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 68U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1288U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 43U, 1503U, 935U, 326U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 43U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1503U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 935U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 326U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1379U, 1714U, 603U, 1332U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1379U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 603U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1332U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 834U, 1051U, 1177U, 1451U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 834U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1051U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1177U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1451U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseASalts = {
    {
        {
            0x7D7F6DF22892DB69ULL, 0x56CEAB1B189F016AULL, 0x7DE4EEE98E1DA64DULL, 0xD906EF4E95BA5ECCULL, 
            0x9481CE421993920AULL, 0x3501748B3875C079ULL, 0xA5AAAB162125BF96ULL, 0x7C5A558B013D1812ULL, 
            0x08ACBD8B8A037F82ULL, 0x08957B170C70D5C6ULL, 0xA76CFF612D6947B5ULL, 0x323361F076740D08ULL, 
            0x3E0C6A8F6644C3BDULL, 0x9D92E52E7737259BULL, 0xB219A93AA9861CC3ULL, 0xA1AC414CFB551CDDULL, 
            0x534855C40BE93E0DULL, 0xA7E9DA941E15805CULL, 0xCB2E6D0871E861F3ULL, 0x5F653114564A7B86ULL, 
            0x62ADD6BB8A8BDD51ULL, 0x00CFAB79CDE2E4FFULL, 0x0DFD6315295D0121ULL, 0x71861F3D7272E7C9ULL, 
            0x78BF9DB3737C52C3ULL, 0x8D95BA9BE6B2C16BULL, 0xD7CF0584EC270B66ULL, 0x2519D5AB3A54F2D8ULL, 
            0x7435E6D346002CF1ULL, 0x9916B851F43B8B09ULL, 0x57CDF6C45F480061ULL, 0x83F0E268BE2E7943ULL
        },
        {
            0x879B184D5783A8DAULL, 0xACACBBE04A04797AULL, 0x18B4F907E126CD97ULL, 0xA2CFCBD61685A1BFULL, 
            0xE9DA07664A3B63BFULL, 0x6145594A45681503ULL, 0x7C4CCC3C7E08DD54ULL, 0x8ED58E16D21E8872ULL, 
            0x0A59D9EC6E0EAF36ULL, 0x906F7C458914D49DULL, 0xFD84E53E161454C0ULL, 0x6D011FB13EB60CCCULL, 
            0x3D48B216E9F7651DULL, 0x8114E994CEBAA2E1ULL, 0x1441FF45AD33A864ULL, 0xCD4A7BE76F26BA9DULL, 
            0xF7BE4134A78E810CULL, 0x4E74D1DEC5C27ADDULL, 0x980C693413D12543ULL, 0x489205BDAF0B3A23ULL, 
            0x08A79AE8DC766C00ULL, 0x9F132EB87BD7BE65ULL, 0xFBF0E1CB0F85F44BULL, 0x3751DD397F89F08AULL, 
            0xE526C47E8F507DC8ULL, 0xC49EFE65BA2D0324ULL, 0x0C647D260FD47C57ULL, 0xD4F669B79F97B923ULL, 
            0x51EED818EC6CE49FULL, 0xEBEA09FCF3EDA29BULL, 0x0FCA2D28467C3E52ULL, 0x9C7EBD8CD3A4CCDFULL
        },
        {
            0x15373421A7D8E67EULL, 0x052A855A035377EAULL, 0x2626AB236ACE1893ULL, 0xBC5A1994142B15C1ULL, 
            0xC10617BC8E1D06FBULL, 0xD03A590C06C22103ULL, 0xAC28686D5BC03643ULL, 0xCD6DB46CB464FBA2ULL, 
            0xA4FF18956ED7FC76ULL, 0x635EB3B3A44956F3ULL, 0xE87C9650A0437029ULL, 0x40D2ACF560E4E10CULL, 
            0xC088507C822A7AD1ULL, 0x0F532DB0867C8BB1ULL, 0x831419E2A3AEB3D9ULL, 0x661010B8CD2BC0E1ULL, 
            0x0B105415DE08D5FAULL, 0x65D549409AA1982BULL, 0xC7D9447A7E75FC9AULL, 0xCE33740F3427E503ULL, 
            0x02A5C793D3666A17ULL, 0x474A5CBFDF163007ULL, 0x5484032EC7C456EBULL, 0x16BE717BE9D3F14BULL, 
            0x9ED332EC36926165ULL, 0xE98F0CE1FBF2697DULL, 0xBAD44BD791CF0F59ULL, 0xF6B7D4E50ECF2740ULL, 
            0xD120F675900EA44EULL, 0x8657137C3D0B0F54ULL, 0x7DCC56E158D99E0DULL, 0x7D981825EBD75EFDULL
        },
        {
            0xDD01600AE4A4364EULL, 0x7914D2B6EB682364ULL, 0xD0097EC3129D3405ULL, 0x1ADED1BB6A76857FULL, 
            0xC00F0BFD0FD525BFULL, 0x5A87931AB942E72EULL, 0x5B619C06B50859E6ULL, 0x43E4C5E65EBED837ULL, 
            0xCEFD70CA193DA39AULL, 0xBFACBE93F554A982ULL, 0x19849771013FE66BULL, 0xEA8EECCAA9FF656DULL, 
            0x3ED0DFC36D0E58ABULL, 0xDE481D8F9010A543ULL, 0xAB7A44BCE01E5F66ULL, 0xB0C7F4EF3948FA4EULL, 
            0x03D7D17586454CF1ULL, 0xEDD63CD24296C369ULL, 0x727CC623C48FBBCAULL, 0x831463A3F6523F1EULL, 
            0xABEB4221CA9E21F2ULL, 0x4A694D6A42E90F08ULL, 0x3C2EDAB9C7F8C403ULL, 0xF6DB30A244476546ULL, 
            0x4C5A852E1FA4FDA9ULL, 0x4C8E504AE33E4A90ULL, 0x0EE6E82B979A0F1EULL, 0x320C0BB320AD4C99ULL, 
            0x5E78D823D77F6488ULL, 0x4A2CF36E16B63692ULL, 0x9C5F62EBDD301CE8ULL, 0x8D24B50A18BE025BULL
        },
        {
            0x9C14EDD4AA9AE0DCULL, 0x7C83EABB8C32802BULL, 0x68825B4C7C3E1AA4ULL, 0xB24EA7A7AE55E901ULL, 
            0x3A82A258B4F7B13AULL, 0x7144F09C407A3E95ULL, 0x8C0CBFE5A5107153ULL, 0xBBB2C76E3482B6D1ULL, 
            0x1BFCF85E64741846ULL, 0x42DE8B05F157D08CULL, 0x3194F8DADB8A0DD8ULL, 0xFCBB26794B2D6DC1ULL, 
            0xE9131571CE615951ULL, 0x3B86BAEF91412AEBULL, 0xAAC1AD705990706DULL, 0xB594937B212D6474ULL, 
            0x5D9C7BE8B8F88A97ULL, 0x342053E50FC31E44ULL, 0x002D5D756638C970ULL, 0xCA6F7584F030646EULL, 
            0xF5BACEFDBB875975ULL, 0x8914D2BA2919132BULL, 0x73E52D24B935AA3AULL, 0x90202CADDA4B35ADULL, 
            0x49EE2FE4E370689BULL, 0xEA3BB7B09A1ABDEAULL, 0x8E1E5FA62FDB81CAULL, 0xAC313C5BCB98D876ULL, 
            0xB5449EBFAEAAE3BEULL, 0x4ECDC083F0D9945CULL, 0xFBEE51F732C6AC6DULL, 0xD31B3D26D27947AFULL
        },
        {
            0x7FB865061F7B3F0CULL, 0xC434026BDB6BCAFEULL, 0xA2E970216F0C7682ULL, 0x7DF74D2E3A53D31CULL, 
            0xFC8D4D8BDE7FD78FULL, 0x57898E709E9EE351ULL, 0x430B76DA735AF32FULL, 0x0028CB1EB244D2CCULL, 
            0x0085D4D5AC4AB6C3ULL, 0xC88975F289240389ULL, 0x20680FD696DC8946ULL, 0x64C3DBDF1337B48EULL, 
            0x05B4B5FC8B547415ULL, 0x9317975AFEE5CC59ULL, 0x3BB4A1325247EFE2ULL, 0xA954F517D142B2A9ULL, 
            0xCCF4BFFC12915D26ULL, 0x58EAF3B50D8696FCULL, 0xB98EFC370FCE0C35ULL, 0xBE948BDFEAFAB9CDULL, 
            0xEB47271DF0CC2F2EULL, 0x1423DDD2FDE7513DULL, 0x54EA9EBAF8571B5AULL, 0xB635F266C2F40DBCULL, 
            0xCA6EBBBC9EFC5878ULL, 0xF2700118F3648A4EULL, 0x4786FEBAFE4CAD86ULL, 0xA7AD99F3F3D3C64DULL, 
            0xCBAA79458F131F75ULL, 0xF26AD01DB4A67482ULL, 0xB8CD0DE62650120CULL, 0xE6FBFBCBB1E2F0A6ULL
        }
    },
    {
        {
            0x44E06D7E4106C596ULL, 0x219914DE1DD1A8C9ULL, 0x6A86FA5E79AD0B04ULL, 0xC3FEBAB5461CCA77ULL, 
            0xCC5BA03722F80A9AULL, 0x0B9D44B8E967EA3CULL, 0x7076574A4C656938ULL, 0xE496F739A749A9EBULL, 
            0x870F319CAFB1393BULL, 0x86A1E578BFDDAC7FULL, 0xDC30D8AB941F6B8CULL, 0x25A4C12A594A4481ULL, 
            0xDCE814B1C79F9BE6ULL, 0x0734CBAEC597B85CULL, 0x7CE93BCA3F79868DULL, 0x2E204650A80F9A2CULL, 
            0x4214944D33967430ULL, 0x121856DD54DB7817ULL, 0xA23B830277AD0673ULL, 0x229A898461595F9FULL, 
            0x6F38D4ABC7212213ULL, 0x8A0FAC7F23508144ULL, 0x9F07F2D1F2289C7FULL, 0xEC54BB7D236FCF3EULL, 
            0x64267194586D6322ULL, 0x0370426956B7E6C4ULL, 0x2936DB8CA5877284ULL, 0x05879EF94F09129BULL, 
            0x223C5F628151773AULL, 0xC6B9CCA1472C8ABEULL, 0xBB4456CEDCBD757AULL, 0xE091D6490E350125ULL
        },
        {
            0x078CECD868B64156ULL, 0x52FEC49FF65400BBULL, 0xBD3C70DD5D3C7625ULL, 0x9F7CEF88D1CC6FD2ULL, 
            0xCFD46908364B2C72ULL, 0xF56E1CFB51824AD9ULL, 0xE13CB5EFAAE6C58EULL, 0x51DC5623E3952A11ULL, 
            0x5CA9C8AFC947B409ULL, 0xBEC3EE001C05741FULL, 0xF18C8FA0F8C7E7DDULL, 0xBA97584BA08CB2CBULL, 
            0xAA8E0A2D6C3B4F39ULL, 0xC55CFA5927B52896ULL, 0x0C2540BE16E4507CULL, 0x4141445564E6AF3FULL, 
            0x1830E4CEA4C7A548ULL, 0x55F76B81C30E2082ULL, 0x3CB27EA0FC9EBF77ULL, 0x27500A4B1AA96613ULL, 
            0xFB016F26DC56466FULL, 0xE1F42F182776E52AULL, 0x7ECC0BC59345B33DULL, 0x11558A00AECC140AULL, 
            0xFED650D9EC2BC229ULL, 0x53C8709920CFF94CULL, 0x3281178BF851A845ULL, 0x05519EF6D86EF65EULL, 
            0x5B082CD0A525560BULL, 0x1579D5DB79710D4CULL, 0x9A1742E0B4832574ULL, 0x4F00C4E0C7EAF147ULL
        },
        {
            0x78B2EC433AC2A2B6ULL, 0x00EF541EC232CC77ULL, 0xDF997FDC9408CD28ULL, 0xFDDD9AF6EF002B16ULL, 
            0xAFD25F59651AF8D8ULL, 0xF60CB746A36F1142ULL, 0x2784D2043239C28AULL, 0xB94851406528DDF6ULL, 
            0x8E8E799F40216AB1ULL, 0x94F153D06FF749AEULL, 0x89C351E22332E4C4ULL, 0xB65385C008AFB6BCULL, 
            0x3A054F39C13E610CULL, 0x9EA4DA04233F9DE4ULL, 0x9EC81C20285716DDULL, 0xBAC116BEEFBB0CBBULL, 
            0xBA0CF3F62A5E850FULL, 0x5FA78783AFDE5C4BULL, 0x41002758F14882A0ULL, 0xDFF8E4BCF7999FF4ULL, 
            0xC7F26984ABDD759BULL, 0xC351CCF0719C77D3ULL, 0x64A1A84611585960ULL, 0xCEAFEBA566D4D58CULL, 
            0xD7DA013A873C789BULL, 0xA83DE31C47F6E735ULL, 0xB5C4DF5FB5BAE237ULL, 0xE91089E8727C4C69ULL, 
            0x4ACF608BA5EFBEB6ULL, 0x8267D55EC1295DE8ULL, 0xA813C589D90DC9B3ULL, 0xCEB18EC42F929704ULL
        },
        {
            0x0BAD1C821196437CULL, 0x5E3F257DCBDAAA6EULL, 0x7EE776022485A9EDULL, 0x84E5C84F6BF0BDC1ULL, 
            0x063457BE5BEA967AULL, 0xA55474AD3ABC8AD7ULL, 0x2205F9AE16B0E3AFULL, 0x31A5BD12C4870B98ULL, 
            0x8E1AEFB8EF836C9EULL, 0x308306038AA43180ULL, 0x0A8AC1FC385CD4E1ULL, 0x22E01EAF9E88721BULL, 
            0x50E041C4C1C54403ULL, 0x0D74227DA8C88479ULL, 0x2C530C912CD16009ULL, 0xBE00461D428D93C6ULL, 
            0xF31FD663536118D8ULL, 0xE984EDAB2D1B0F70ULL, 0xF3E49738ED0587C1ULL, 0xFDFB685955956110ULL, 
            0xC66EE45FCBC300EAULL, 0xD04C28ED77B66BF4ULL, 0x8B247D11EFD8DA5CULL, 0xD3553519DD507B2DULL, 
            0xB7FA3551EE887546ULL, 0xFBB8C1BA1ED50252ULL, 0xD5399358ECBAE3D7ULL, 0x3F68BD5AECF0EEFDULL, 
            0xF484DAC28C89485DULL, 0x2EB52DF943382C63ULL, 0xC0889AC22F54E5FFULL, 0x134FD6A7FAC16058ULL
        },
        {
            0x328378F8D01C1229ULL, 0x4F60D33B7B6CAE71ULL, 0xB9607B79B125008FULL, 0xFCB16D17B74F9BE8ULL, 
            0x63A4545200C10ADAULL, 0x5E5B34A263CAF2A7ULL, 0x23F0236C96A6E0FAULL, 0x0F68889DC34D8CD9ULL, 
            0x4584AA6962ECB6B7ULL, 0xB2CFB3356B51EBCAULL, 0xB130E9107E99B465ULL, 0x8CB5168AF855568DULL, 
            0x690EE44C87C013F2ULL, 0xDB4D8A19450C8867ULL, 0xC5BEE3F077832588ULL, 0x1F8B75F388A02F08ULL, 
            0x8B5552999A535462ULL, 0xE191A1F47420FDC1ULL, 0xE9CF1FA4AD09BD04ULL, 0xBCB4FA71BF382548ULL, 
            0x1E8B0561A49EDC32ULL, 0x42CC79A1248EA593ULL, 0xCF1F7F9EB75C88E9ULL, 0xE5C9F18D961FD652ULL, 
            0xF83812B90ABE5B84ULL, 0xFC28954358344A0DULL, 0xBA98DB23E94214BCULL, 0x31A4EB07E16FBFA9ULL, 
            0xDF60462783A4D28CULL, 0x5F2E30046B5D14E5ULL, 0xFA98FA356D342806ULL, 0xFC37294E7D473186ULL
        },
        {
            0x24E7E3AB2F9E5015ULL, 0x34B2420F0A3A4FCAULL, 0xC3A0286AABFF99B8ULL, 0xC2A59547214551FBULL, 
            0x992F42FBE211FE84ULL, 0xB2CD67300823EFF9ULL, 0x81EA2D8880CCD739ULL, 0xC0437969841F1766ULL, 
            0xBA2166FD684A6F56ULL, 0x402BC0CA2A414D31ULL, 0xD1D94BF3AA5EA91AULL, 0xD8BB922873FAA28DULL, 
            0x03D655990A3A7095ULL, 0xAD41779E491A1ED5ULL, 0xFDC569E28B5CDE1CULL, 0x1CE00F7EBACDDC6CULL, 
            0x0E08E493067183A8ULL, 0xA6B12AB40AC830DCULL, 0xEC75172C2CA33FA6ULL, 0x7BE15D9262D0482BULL, 
            0x36556CE342A6D9EBULL, 0x0AD6B7647235FC38ULL, 0x03E3B31A1FEDE69FULL, 0x79E5619F4480EC12ULL, 
            0x66013E40E26CD080ULL, 0x246970D94927EA16ULL, 0xC7D835CA46302016ULL, 0xCFD2E7D4C4D50A66ULL, 
            0x39AF237272E22252ULL, 0x793EAC016631B1DCULL, 0x08C54746899EBF97ULL, 0xCC12DD3287A8F942ULL
        }
    },
    {
        {
            0x2CBF412DC1277FEDULL, 0x1B45150217C50F8EULL, 0x93E4409F96779A8BULL, 0xC4B7AFAC8EC5B617ULL, 
            0x26A7D5E41B6EB618ULL, 0x3C4180272C8FCA87ULL, 0xC2F326948595498CULL, 0xE3AA4C46A2A84036ULL, 
            0x6D7FF6D29B09BA70ULL, 0xC08D29BE5449F0AAULL, 0x75B39C7DA8D224C5ULL, 0xA80C65ABABE75F65ULL, 
            0x7100C66F96D6B962ULL, 0xBA208B81FF499382ULL, 0x71BB412ABF834CB5ULL, 0xAB70090EA638151FULL, 
            0xD8F5D0F2947D4A5DULL, 0x30E5BAC91692198BULL, 0xE6C3D4FB37D0F370ULL, 0x655B432522333DE1ULL, 
            0x93537B53C50D5596ULL, 0xC13F9CE8705AB6C2ULL, 0x3F030F4CBEE254D5ULL, 0xA8196AC6C6085C58ULL, 
            0x53C85552D58931AAULL, 0x6022BC11692EF3C7ULL, 0x92DA2C714314FAC3ULL, 0xCA8B962091D405E9ULL, 
            0x5C54A257EC2D4FDCULL, 0xB6B7A40C68360933ULL, 0x9434EB979C439406ULL, 0x2E0C5EC02EB82CBCULL
        },
        {
            0x3493463F4172AC72ULL, 0xF68E273CE74F4BFDULL, 0x95BC2269D6E17551ULL, 0x428348E17CFDB64CULL, 
            0x1EF967AB9CEF3CF0ULL, 0xB956D5A3FAFD6E20ULL, 0x5C6EDDDDC1328F46ULL, 0x22CC14E6E8358CE3ULL, 
            0xA1D5C1D29EB0C604ULL, 0xDDB976EC3B59A7C1ULL, 0xD1A21482AE1E03CFULL, 0x6698FD555AF5682BULL, 
            0x72D0723B36975270ULL, 0xC3B833E1DA96D601ULL, 0x4883B9ABF97BA7E7ULL, 0xF1F2F5D025E57AF2ULL, 
            0x54CA21DBDCF368EDULL, 0x06039DF355483F3CULL, 0xF5E87176AD289760ULL, 0xEEEA003A1A27576EULL, 
            0x69D3ECB812244C2BULL, 0x200EA7B9386EDEA3ULL, 0xF0591446492E21D4ULL, 0x062ED8CC6B4B63CCULL, 
            0x6AE70C711BD78437ULL, 0xF6331501438CD005ULL, 0x242CDD7455F1D895ULL, 0xFFB54B827AFF8B68ULL, 
            0x6415EEF958CEED12ULL, 0xE1DB074E201C6198ULL, 0xF26813FF8C221349ULL, 0xD1797518E2C7614CULL
        },
        {
            0x1DC9E4F41FC48984ULL, 0xBE973EB36E705E36ULL, 0x4A5487D5105D6048ULL, 0xE350E56613CD1C1CULL, 
            0xBD061568DCB831BEULL, 0x817CA2C725B3E47DULL, 0xAFC5D7EE38FFE746ULL, 0xB04910F674AAE0DAULL, 
            0x6A039FEA731759B6ULL, 0x98C2898106CF9F6AULL, 0x64E089B66DA97F70ULL, 0x0C80D84F7CFB9AB7ULL, 
            0x8E04F62C1E007476ULL, 0xB430402E4E1855CAULL, 0xA3B27CCEABF1CB72ULL, 0xF1CA35E18E6B3A3FULL, 
            0xA779F212C39E6B9DULL, 0x6B60060D5850CAD7ULL, 0x5AFD2E409814230FULL, 0x84E84B074F4BFE13ULL, 
            0x0864DD4E728BD3C9ULL, 0x83EA281B8E8E6BC7ULL, 0x93FDD63BFB52938BULL, 0x2C2C5A2E520C6569ULL, 
            0xEB25BB93F1EC032DULL, 0x8CCBF19A626AFD1CULL, 0x078C117FF4CB35A8ULL, 0x9EDAD38DF514E6BEULL, 
            0x970C09EA65EF0A6FULL, 0xD4500B736B6B06B8ULL, 0x04326FEA28B376AFULL, 0x3BFDBB2461B0498AULL
        },
        {
            0xAD82A552BEFD0A0EULL, 0x5B051DC1BD35FB2DULL, 0x42283E6420AC4F11ULL, 0x90F0D29AC9304E89ULL, 
            0x867BAF741238521DULL, 0x3D45D83B36F3A1AEULL, 0x8617C878BA223C32ULL, 0xBFBFEE1D4F0E516AULL, 
            0xA0F0F5F97B5365E4ULL, 0xEDBE5580A15684DAULL, 0x9CD4EDF4C2B580F3ULL, 0xBA5240D8CCAFFF2BULL, 
            0x9C7AF34CD8F8F61DULL, 0xF4510FEFF4E923C4ULL, 0x3310DF41DC04B64DULL, 0x007389845A8F1D32ULL, 
            0xD088D0DB5BB2FFB9ULL, 0xF7E3DDACFF965CF1ULL, 0xACCE7BEBB8214049ULL, 0x294A86A736136462ULL, 
            0x77CE1FCBA91280AFULL, 0xBAF89E77AA5BC08CULL, 0xA23928479A38F53FULL, 0xF0C434FE0911A925ULL, 
            0x4A3D98E9A15FD806ULL, 0x1F5F0313E153CB14ULL, 0xD876C2EFD9AA009EULL, 0xD0BCC461A8DDD1E9ULL, 
            0x6966012547185F66ULL, 0x5C70AF21E40B6AB0ULL, 0x87BBFDFF75253921ULL, 0xD0B3A7D7AB23D014ULL
        },
        {
            0x1956B2444627A963ULL, 0x0F54668515462D56ULL, 0x12038C17E5BBB42BULL, 0x699DD01F0616FCD4ULL, 
            0x3A42E62587709765ULL, 0x2C675FC37DA71D75ULL, 0xBAA33ED13BC1B3ADULL, 0x1EDB6EB6356554FAULL, 
            0x6CC17B0109EF6556ULL, 0xD09419DAC940934AULL, 0xD5F91D4119BF7E42ULL, 0x49D0836E4407792EULL, 
            0x71AECAE58AF28185ULL, 0xD72D90194A4ACB14ULL, 0x197E642C0C9BA03FULL, 0x6C2FC3E3397DE43BULL, 
            0xFFBC52AF82917108ULL, 0x2E4115A61C62088DULL, 0x8FE51941B9161F81ULL, 0xAC804885DBE65E1EULL, 
            0x261E247600393B8AULL, 0xB9BACEAAB4F90366ULL, 0x51068A1EB9165EA7ULL, 0x67346ACB8AAC0DABULL, 
            0xD88F9F10F6FB8960ULL, 0x21A325B6D3C246DCULL, 0x644215DA85CD7FBBULL, 0xC982C3BF3344552DULL, 
            0x1C70DADB5DB71827ULL, 0x045B991AB478F9BEULL, 0x5F127F8EF7B3B5E9ULL, 0x6980BDE6E1AE7196ULL
        },
        {
            0xEBD1F4CFFEF4A6CDULL, 0xD9E9304295CADE7FULL, 0xCF0A83349F889730ULL, 0x5DE1E58F0FB97E48ULL, 
            0x1FCAFF748E21E08FULL, 0xAC261A69D5EAAD84ULL, 0x726154748BBD9A1CULL, 0x7F2569759ABC811BULL, 
            0x0DDBA4855C511BB7ULL, 0xD2307471D31A8B77ULL, 0xAC0248621E5A5B72ULL, 0x10EAEAA4CEDE6695ULL, 
            0xAB7490BDCA7216BBULL, 0x9BF3243AD1F08026ULL, 0x318A74623B2BE625ULL, 0xDA3FAA39ED1C1B94ULL, 
            0x23A103DE522A428AULL, 0x07988E9A429A4A8DULL, 0x9AA64B904E7F490FULL, 0x03901FE10BF7EA41ULL, 
            0xF6DCB0F1E54A5E51ULL, 0x399EFCB0F3BAFCBFULL, 0x0B8B033988EA19F2ULL, 0xFE51F0019EE2AD1FULL, 
            0xCDC256D7A65E89B6ULL, 0x347AB75EB8F7F88EULL, 0xFC1A0E2CC03F5D5CULL, 0x1482ABF6781132CCULL, 
            0xC1820836DB6F404BULL, 0x805A15D9536F708AULL, 0xAF40A47BDFDD4F2FULL, 0x4056BB5F0EF44C91ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseAConstants = {
    0x4C562D49C4FF73ADULL,
    0xBA8498FFEE9F2D11ULL,
    0xCA4D665FA9F2554EULL,
    0x4C562D49C4FF73ADULL,
    0xBA8498FFEE9F2D11ULL,
    0xCA4D665FA9F2554EULL,
    0xA0ED97398C8CDE9CULL,
    0xD6B73424D4E325D8ULL,
    0xDB,
    0x9F,
    0x49,
    0xE2,
    0x34,
    0x6E,
    0xC4,
    0x78
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseBSalts = {
    {
        {
            0x31E33F512B0FFA77ULL, 0xD80791FE3E2863C6ULL, 0x624C83484E106DB4ULL, 0x5B106326CE6F1E4BULL, 
            0x2DFA7419FF132916ULL, 0xAF4322B37D46DE84ULL, 0xC214D40378A76263ULL, 0x7D28503A8238D526ULL, 
            0x7A0328A21FDA4B9FULL, 0x04DE4B17223869ADULL, 0xE4C82F6AF2C500DDULL, 0xDCA58F0B87545C23ULL, 
            0x185E88865A18A64DULL, 0x1F6946997135D531ULL, 0xC49D16780DB2932CULL, 0xF1A58A052DC4D85BULL, 
            0x99E644F64B3F4DFEULL, 0x1AC36CCEE081D97AULL, 0x1695A2CB046E4602ULL, 0xC795044242F469C2ULL, 
            0x6BC699AA1AA40E4CULL, 0x6FDA6D523FE9B315ULL, 0xB4D86A6671C74D1EULL, 0x5B7494411B86A0AEULL, 
            0xAC583FC28E14D4FAULL, 0x19B56D5DB1C1A4B4ULL, 0xC5B0D52043FBD8CDULL, 0xD979F9C61B2BEBD3ULL, 
            0xCC360C084F708D23ULL, 0xE2D8E0FE1FCDD442ULL, 0xC9FA8DA8F7A8FA67ULL, 0xA54CDF4F57E6F24AULL
        },
        {
            0x6C4FE83DBCD72DA4ULL, 0xC4E970D25A7498C2ULL, 0x69E595F97F5B89E0ULL, 0xB1FF18549A77EF93ULL, 
            0xFDEBB6523D27F6FAULL, 0x2F1D0D87AE5FE08CULL, 0xFFCA6469167549B9ULL, 0xF4E39918227A9308ULL, 
            0x92E2DF1A1C0B5591ULL, 0x57C055D2FAD3D837ULL, 0xEE1C7F2BE0A41F55ULL, 0x28B6ED25387C132DULL, 
            0xB073A756B4300150ULL, 0x103E1A89B91DDC17ULL, 0x7D3C784B99A74EC8ULL, 0x63D6FA744B59879FULL, 
            0x6DA1CE740D60BFD5ULL, 0x5441C8E528033FC2ULL, 0x517C05F23D441E72ULL, 0xD13006CA724BFA49ULL, 
            0x8EB711176FDA3D20ULL, 0x8EB805E777FA9C9AULL, 0x1FA19EB3A37EC083ULL, 0xC36DB2CF3F154E7EULL, 
            0x50604C3019ABB32AULL, 0xE5067D99F3D9299BULL, 0xBB5E06D472E93BF3ULL, 0xFDA25D7E7ACA6428ULL, 
            0x764629F9B36EA219ULL, 0x2A6CFF0A1D4A15DCULL, 0xF8F8B7681CDA10BCULL, 0x3C0736077E8950EDULL
        },
        {
            0x44EC95FEDF31E7E8ULL, 0x78B0E7067C90BCFBULL, 0x5975DA541DA674DEULL, 0x2BA5CC32B846BE45ULL, 
            0xAF5DF87146F31EC6ULL, 0x958495D64466B32BULL, 0x1F244C97CB2F824EULL, 0xB544C4DE9DB23C52ULL, 
            0xB674BF96C348E408ULL, 0xD5412A4694D5B084ULL, 0xD1D07F669A27E68DULL, 0x7760F1A7F3A2063EULL, 
            0xFE34115DD05A2288ULL, 0xAA34F6E9A4D9B5CAULL, 0xE827748CF32CE564ULL, 0xA14CF7D7CFBAB4F4ULL, 
            0x08DAEB2C47B730EDULL, 0x45FDB525325FC69BULL, 0x8985FEAD9331C60CULL, 0x2C48D124AEF9AFF1ULL, 
            0x18CE9F5892BEDFBCULL, 0x260BF3E89C6CA5B8ULL, 0x14F7C5A93A3EE17BULL, 0x3D3E77E0C7FCF83FULL, 
            0x71AB5AE28D9BA8D8ULL, 0x49B80C4EB1D25C87ULL, 0xAF8B0FB9F039B15FULL, 0x36E569B0A7715AA1ULL, 
            0xF8A73E7E574B7055ULL, 0xB3F9803B66729BEDULL, 0x33E6CBB49460A88BULL, 0xC6A02131FF5CF7A3ULL
        },
        {
            0x1A45B9825C52B8D2ULL, 0xE629176BAFAB269EULL, 0x97F9D4845D0B64BCULL, 0xD3C16C01C89C9547ULL, 
            0x3C0DB30E51E46142ULL, 0x4EACE9E117BEDD00ULL, 0xC3986027BB1DF9DBULL, 0x05B0728404C66330ULL, 
            0x7AA9CEDD65661B73ULL, 0x72FE77403FF2008BULL, 0xD875C700E2DD9D43ULL, 0xE8459AC92EA564AAULL, 
            0xA9B8C36B75D08375ULL, 0x0FF2986C036EB5BCULL, 0xFD21A123DA32E036ULL, 0x2869558E1361EF59ULL, 
            0xDA8A5AC72FDA3BA5ULL, 0xF59706575E1C5633ULL, 0x4BCC97444203BB8FULL, 0x484D19519E6FCF67ULL, 
            0x18853D83A515A745ULL, 0x6F9FEF006D6DAAECULL, 0x25074A7CD15A60B4ULL, 0xC5C00F901DE1114DULL, 
            0xDDD5C56323B43085ULL, 0x59937D06F299A09EULL, 0x45DF94B67AE59330ULL, 0x840C167C23D3D44FULL, 
            0xD364539ECC2B3147ULL, 0xA9BC65D45D232086ULL, 0xCD828D3EA994E456ULL, 0x02488EDB80D76285ULL
        },
        {
            0x75BED9128D4F7254ULL, 0x2AA41A45A55A2417ULL, 0x582BBBBCDA36472AULL, 0xCC22EC580D2B6C51ULL, 
            0x4DEAE3D6CA225589ULL, 0x734DF676AF5FE7FCULL, 0x8A13409EA3437CDCULL, 0xFFB83EC4C0A01A12ULL, 
            0x159FBEEEB2DC91BDULL, 0x908FB2083B1195F3ULL, 0x176BF896742C4607ULL, 0xA30ABD44311C148DULL, 
            0xFEF382872669267BULL, 0x37A037663889C9BCULL, 0xF1FA22BF4B713E79ULL, 0x8FFDA706B6124770ULL, 
            0x68A6FBBC57F4B033ULL, 0x4DE655D3FC561205ULL, 0x8C2B038D6E51A430ULL, 0xFE634A01C86F9953ULL, 
            0xE1E1F122AC3ABE76ULL, 0xB2562663E5F346C0ULL, 0x1A5C32CB53EA4D39ULL, 0x9BF885EAFE22B32CULL, 
            0x499B18DD38802974ULL, 0xFA9B1AF2E923AC6EULL, 0x9CDBDAF4CBAA57AFULL, 0x4894659154F3A300ULL, 
            0xC8963512906A70E3ULL, 0x98EC43A0C49A2B8CULL, 0x21A2BD12BE4981DEULL, 0x37C94CD0172E041BULL
        },
        {
            0xD01E1E168345279BULL, 0x61CF0FFF1E160BB0ULL, 0x64F3553E1FC1AAC7ULL, 0x2A4AF8310D8A83E0ULL, 
            0xB24FC73B5E4F2EF4ULL, 0xDD5826035637FD05ULL, 0xA00625AD93144B25ULL, 0x28914E22965F226FULL, 
            0x449E86EA329A4003ULL, 0xFEEF98B3F9C3374AULL, 0xF4168419A8C56CFBULL, 0x97CF0988A051FFE4ULL, 
            0xE59B0CF874E7440BULL, 0x7FFAB24B0E1B7ACAULL, 0xBE803E7940478078ULL, 0x2B9304D3C4644535ULL, 
            0x2E41164FE0352BFCULL, 0xEA9A07A9951AC1FBULL, 0xC2ED74331A4DD554ULL, 0x34E92AB55C8D9E37ULL, 
            0xAA2EE6ED6964881FULL, 0xD4D5AA202D7E94DFULL, 0x462C8AEE15E8A5B1ULL, 0x6C44F72279CEF915ULL, 
            0x5A245815629831DDULL, 0xA834F06F29C3385DULL, 0x390CBCC2B91A6A0CULL, 0xC8DD02BBBA5B9515ULL, 
            0x88FF459B6CD87D48ULL, 0xBB1759778F93CAC1ULL, 0x28A2E346A3C44229ULL, 0xF962FAF4C5CC8899ULL
        }
    },
    {
        {
            0xE991288F94F03FF7ULL, 0x6F8B7C2A375D6A44ULL, 0x32C8F7CB6D38C53FULL, 0x29222CACA673C43AULL, 
            0x14E1B1A1D8AEFC17ULL, 0x6C6BFC0EA0E55F65ULL, 0xB3C5606702E1911DULL, 0x4AF6BB716BFFB789ULL, 
            0xAE1210376116A340ULL, 0x866441905870D7FAULL, 0xA00AD285A3159D54ULL, 0xF0030483575EA8D6ULL, 
            0x7ACDE9F33AC307C8ULL, 0x284F600DC9D80135ULL, 0x873F6F2B0520A93FULL, 0x82E409A770E78BDDULL, 
            0x8D0A1FCB732D6A94ULL, 0xBF538CB0DDF34859ULL, 0xEA12A71261286ECCULL, 0xBDE96B2DD5D78080ULL, 
            0x02E80EFFCC810F02ULL, 0x3E7C24DFA97F9E38ULL, 0xFCA78EB12F742A92ULL, 0xE9CC212237BB5A94ULL, 
            0x2ABFD88E24B103BEULL, 0xA0DB02E960E1A36FULL, 0xFB820E397615090EULL, 0xF1D79AD47AF999C1ULL, 
            0x3635920A039880B9ULL, 0xF6C84B7021EA591DULL, 0xCC03225DD8B47663ULL, 0xACAA436A5B42DE70ULL
        },
        {
            0xA92428533371C1FEULL, 0xB9B21E995729893CULL, 0x4FEDF0F905D542FCULL, 0x182FD1ACE55C2E43ULL, 
            0xEF56A75A61F6A9FBULL, 0xAFDF04C0107EB2C2ULL, 0x8619027BB1EBB230ULL, 0x5D0BFAE51D7FC49EULL, 
            0x558CD7A7430F92B5ULL, 0xB064A05268EC0FDCULL, 0x20ED85C9999992C9ULL, 0xE74F7564A06C8FC0ULL, 
            0x400386366E5CF3ECULL, 0x9055709915349187ULL, 0x9282D185CB5E693EULL, 0xD00CCD2BA8D009D5ULL, 
            0x6D6E82C5EAA1B8FEULL, 0xEFBF004B06BB188EULL, 0x3C1AD47DFA120B01ULL, 0x1A08DBCADE6FDAC5ULL, 
            0x8EC24CF7BFC723A7ULL, 0x1E23BF4AEB5948E6ULL, 0x53D0B05C6D3BE124ULL, 0x6756A5AF895D15B8ULL, 
            0xA35F45B984DC8EEBULL, 0xAA5B865F3A5E27F8ULL, 0x8C5D06ADB224EC37ULL, 0x5BED07BEDE317278ULL, 
            0xBEA3EC66433441E7ULL, 0x9E895599F8500831ULL, 0x15EE050079CB0F2FULL, 0x2DF074AC09ECE596ULL
        },
        {
            0x29405E9E502640A0ULL, 0xC58AD7A2BC0D5443ULL, 0x2C0E05503A9A7FFCULL, 0xE47FABEC04E37C9FULL, 
            0x8E7D5740A27D4643ULL, 0x695456C123759097ULL, 0xE842460A6FA179E0ULL, 0x53517BAC14990ECEULL, 
            0xB6E66C554AFE23BBULL, 0x43464D743A0BE6EEULL, 0x20E3A058FF03BDC4ULL, 0xEC9054A7F84FD188ULL, 
            0x3C2EAF696F111959ULL, 0x52F0562C809A00B4ULL, 0x0105C059452CD497ULL, 0x4DDC9D2CD3AFC343ULL, 
            0x9BB7A5D2D5F9870CULL, 0xA714D65997550DE0ULL, 0xBA7207B01F294BC3ULL, 0x5F385970F3493D36ULL, 
            0xA16D47C2AEFEF9D4ULL, 0x43325C1CE2958EF4ULL, 0x7D6262C828239D21ULL, 0xE4A50C3293CF5AA6ULL, 
            0xB62F8D921B8D626EULL, 0xA69398182D77FAE7ULL, 0x24A725A8D58E3C4FULL, 0x33D2D92C5976108AULL, 
            0x8EAB9E8D9579C97FULL, 0x2A739B5F0790AEECULL, 0x29120EF4271714E8ULL, 0x03E1216133D908E8ULL
        },
        {
            0x8FDE13D98A4EB5DFULL, 0xD4EF7FD39BBEF0D2ULL, 0x6E55FAF81C4AFF95ULL, 0x9EAEB2AC6EC5BFD7ULL, 
            0xF10640139A21938CULL, 0xD98F72D0224144D6ULL, 0x658066DCB062B585ULL, 0xA30DA2AF2F7CDA14ULL, 
            0xEA42AE1E92BE3D6DULL, 0x02C49BEE1FEFD077ULL, 0x2B6D99D1E4DFB64FULL, 0x67732BD41B5232B5ULL, 
            0xB6158A35486CF8C7ULL, 0x5D65A95C9840E527ULL, 0x580A06A16C608FC7ULL, 0x97AED45F8328AFE9ULL, 
            0x4FE8C522B026D889ULL, 0x6297E323CD740336ULL, 0x191688A2789E2F8BULL, 0x04613515CD28C1C5ULL, 
            0xDFF1798CCD71FE8CULL, 0x66408815926D498FULL, 0x0F00CC33B77093B9ULL, 0x0E334F3CB98AA07DULL, 
            0xAC7DB8423439EBB0ULL, 0xECDD6729A1219C67ULL, 0xA9C5127F4821F4D0ULL, 0x26AC25067F651703ULL, 
            0x7833641B19EF2FFAULL, 0x38646DCAB1034778ULL, 0x41C13E12206D373AULL, 0xFA718A05A1ECC4DEULL
        },
        {
            0x5C641D22A0CF02F5ULL, 0xFF4FF6A07BEDA943ULL, 0x881036283E6BC0EBULL, 0x8F01A331FA3E6FF7ULL, 
            0xB8C114BF7C97386DULL, 0xC7781146AFE5B8DAULL, 0x3D7EC6C37A5B39A2ULL, 0x386A0C9B6EED2B2BULL, 
            0x72D5FF30FA1AF22AULL, 0x66CED350532446FAULL, 0x075BBA41AFF84EEEULL, 0xAFAC15474B83DCBDULL, 
            0x5288A40F4633505CULL, 0x949D02A2463A3774ULL, 0x0682D2ADF79937E3ULL, 0x722157D3D0C8A489ULL, 
            0x552621606C5F1FF4ULL, 0x384B364145E21FEEULL, 0xD07D1534A416231DULL, 0xC72776A9384D52E0ULL, 
            0x4A60ECFA90E83DE0ULL, 0x53C2EE4BB53ED7C2ULL, 0x00C6B0E642E1C2BEULL, 0x227DB4948EFEF428ULL, 
            0x99DA85BAD665BD21ULL, 0xA7292D862FFA382BULL, 0xA809E8337DA31BC8ULL, 0x90A8AD5FB0B77E3EULL, 
            0xCD40FC5764501D5AULL, 0x30A900326AF079C6ULL, 0x41C7592CF9BDA6B1ULL, 0xFAB5DBEFB2A6CE36ULL
        },
        {
            0xA317EE44DEAAA979ULL, 0xD41AC971D3F69A2DULL, 0x8321E77D92511A91ULL, 0xBE630A8A3A50DFCEULL, 
            0xEFE908B7676D6F45ULL, 0xDF7BFEE2FAC3B8F7ULL, 0x2960CD4E6DE61E75ULL, 0x0766801D4A423AEFULL, 
            0xFA10323525401D5CULL, 0x1D753A68AD9F0165ULL, 0x7A406AC8CA38652EULL, 0x8876628607224C2AULL, 
            0x92BDC1A434F695FDULL, 0x7B716E5581EFD3A6ULL, 0x1537B8DD6E38F218ULL, 0xAAE028C06D2EA59CULL, 
            0xD9DBDC562566136FULL, 0x329168A4C3B1B2EEULL, 0x637C1CFC8FE9390EULL, 0x445CE21D9BEB813EULL, 
            0xB7BECD28FE5ADC7FULL, 0x574BDE6B01FF5718ULL, 0x64A02A0BCF530B30ULL, 0x75EDF01FD3591595ULL, 
            0x9D04197DFEB98BE6ULL, 0x4B01381A14F9092EULL, 0x68A70B71BD912551ULL, 0xB0001AD1953DF2BAULL, 
            0x626C20910BDF929DULL, 0xC5ABC38F94940539ULL, 0x7F6D7FF0CBA814A5ULL, 0xCA98AF793E813D91ULL
        }
    },
    {
        {
            0xBA01792DE348FC37ULL, 0xB9FE4FB3377879D6ULL, 0x4F94A38D6D483A44ULL, 0x65CE694670D20300ULL, 
            0x63AF631E8189CE4FULL, 0x1C0DF164AB864EDFULL, 0xA0E6945FA8F3295AULL, 0xA843D9B3DD58D71EULL, 
            0xE936E34F6883E1DEULL, 0xD3A6ED706D9DD2B8ULL, 0x4E7BA7B26F8DA76FULL, 0xA3227340690AE938ULL, 
            0x19ED4F05899A3490ULL, 0xE6171C1C81B694E7ULL, 0x48A8826972FF2A73ULL, 0xCDFB03F5CC22167FULL, 
            0x7D123FB01EC8D5C5ULL, 0xF55CE68C3B3C66ACULL, 0x65DA4BB2E1F5EA5BULL, 0x2DFA211E4809AC8BULL, 
            0x6376C598E51A9CF2ULL, 0xA8752BB5B666661CULL, 0x584A324863CE68F2ULL, 0x61523DC867C9C692ULL, 
            0x3A2BA8C01AB89795ULL, 0x62A81C2A576329EEULL, 0x846CA58B5AA92321ULL, 0x7514FB0C8717D388ULL, 
            0xAD1916CB37F9A7A1ULL, 0x9DE50A3183B9429FULL, 0xE00E15ADE4F372F7ULL, 0x22E33786E63509F5ULL
        },
        {
            0xBC9EC31B7867B266ULL, 0x4314F5AD3A35207CULL, 0x3E7B23645F77012BULL, 0x9EB97BF2FB3599CFULL, 
            0x683668C627EE4D58ULL, 0x0A33DD67724D79A3ULL, 0x378D3B0996A820D9ULL, 0xC4EA09816058AAEFULL, 
            0xF51B2C5D2E9EBA0BULL, 0xC8CEE5F2CBD1FD11ULL, 0x4F15FB612035ADD2ULL, 0xC313F252C60BAD70ULL, 
            0x8EF2451BE368C3E4ULL, 0x1849807830D99854ULL, 0x686B1D57025D393BULL, 0x999A534C0C0A93DFULL, 
            0xC97C2F7661A1E524ULL, 0xBD594A01012C4286ULL, 0x701990A41C7DA54EULL, 0x1A603B6688831725ULL, 
            0xF49B54166F0CC4DFULL, 0x7B21FA0BE6309598ULL, 0x888589B1EA0389DEULL, 0xA6F8968FD55EEB23ULL, 
            0xB63AE9A40CB8A3FAULL, 0x9864FB526D6AA6D8ULL, 0x1BA15486ABDC2CCDULL, 0xA5A3FD90D3FAC817ULL, 
            0x486637430F92DB18ULL, 0xE1E10775C23277CBULL, 0x353DB6A91BB06CF4ULL, 0xCC34C2D2D8BF2D6FULL
        },
        {
            0x700FD3DE16B097FCULL, 0xCA553B65A46F55B6ULL, 0xABA52E7ECB99ABAAULL, 0x873752E4BD52D6EAULL, 
            0xEDFA247FADB00A92ULL, 0x8023420498CB568BULL, 0xBD04EBF9AF8F2862ULL, 0x2E2EB991CAE18ACDULL, 
            0xA81ADB1AAAF98EDDULL, 0x124434AB74B2A009ULL, 0x37E9BB4385B211D7ULL, 0xBA9ED9B32882F856ULL, 
            0x6D741A4D7F036891ULL, 0x23B8F3BC5EE14F4AULL, 0x92EF5A5593AB75DEULL, 0xB9D5DB3711E395C4ULL, 
            0x0EAC463631A972C6ULL, 0x6184977F23A4B7DDULL, 0x98FFCFEBD64D76F2ULL, 0x8748DB3B1A9A7F9CULL, 
            0xFBCAEB6FA6F98D4DULL, 0x45845873D2411F5CULL, 0x80FC0E29B46869A9ULL, 0xA037D1EBF2A2A187ULL, 
            0xD494A4532FE085A5ULL, 0x797E1D05E47BD5A5ULL, 0xA60033041296941AULL, 0x046FB282A9834EF7ULL, 
            0x910C1902CAACBCD3ULL, 0xD1653B7E9FAA2672ULL, 0x45373B34B269A3EEULL, 0xF3BBB0BA72B4483EULL
        },
        {
            0x48E25657BF2D7A8DULL, 0x872A3084D00DBF45ULL, 0x78A0069899765D0BULL, 0x3E35D419152BF58CULL, 
            0x6DB8888196F9C953ULL, 0x160DA0F06B145378ULL, 0xEB7B55AAE283A3E4ULL, 0x507654DC5B53436DULL, 
            0xCCAC09F44FF3154AULL, 0x5DAE1FAAE208EBDAULL, 0x7D97FED78F3C1BC5ULL, 0xDDC517CF4C17C359ULL, 
            0x15CB6594AD989BFAULL, 0xCE76E5B579CE5882ULL, 0xED30B432170398DCULL, 0x60003742B6CD36AFULL, 
            0x853A40F3C691BFEFULL, 0x911024C9C20E936BULL, 0xC92FD42B87E227B7ULL, 0xCAE13D362B3FCCC8ULL, 
            0xB7C5069BE94F21E1ULL, 0xD139338A236E386CULL, 0x2E744EA3798ED333ULL, 0x0443EA232E3089CDULL, 
            0xBD7A31D5674E9C6FULL, 0xF7955AE6B9CB1765ULL, 0xB50E20125DF9D839ULL, 0xFA78C2EE3C6B4591ULL, 
            0xA569192B3DE01388ULL, 0xAACDEA923F7786F8ULL, 0xEC3D78CFE0B706E6ULL, 0xFDDEAC3B1C1A5EEBULL
        },
        {
            0xCA4021C9E6F7E6FAULL, 0xCBCEFE0DD1EC3325ULL, 0x6CBB1DCD9163037AULL, 0x498BA9091B70EBB3ULL, 
            0xA19035DF6D20E32EULL, 0x3554CC9D0C6730F0ULL, 0x3AC1CF3018347A78ULL, 0xE06C522788FAFD0FULL, 
            0xA8A9021AAD420371ULL, 0x7CAB7EA425566A43ULL, 0xBFD6A5F1A8DC5FC0ULL, 0xF67372F0FA55B398ULL, 
            0x861642757584AD4EULL, 0x91B4D348E371228CULL, 0x690E85B7BA9608A6ULL, 0x982CF4F0F0D26F20ULL, 
            0x0984E01A45D38C4AULL, 0xD84E9C81274001E8ULL, 0x59381FD4CDA36B1FULL, 0xC689534D8E51842CULL, 
            0x1E6108D24E745211ULL, 0x963C52A66A2F30FAULL, 0xC2B21CD9EAA42E98ULL, 0x562506914D76E99FULL, 
            0xBD36DFABFE4C0DCEULL, 0x27C59018C61880B3ULL, 0x9D05256D0B5D25E9ULL, 0x918F0D833630739FULL, 
            0x03E362DEDC853750ULL, 0x80CBBFB0EED6FA7FULL, 0xB6FD4656BE32E104ULL, 0xD34A89BEA4802144ULL
        },
        {
            0xF261B1265E7CB4BBULL, 0x2EC6D6D3F02776C0ULL, 0xC6691A2D335180CBULL, 0x08D0B871CEF486CEULL, 
            0x8748155F112EC860ULL, 0x2D74D8F1E803B560ULL, 0x2CC9147F049FACDCULL, 0xFC59C8877B6FB05AULL, 
            0xB143CB3400A439B0ULL, 0x8D88B88BD309A8E7ULL, 0x471798EB0E3BC331ULL, 0x833477E9F09CA1D5ULL, 
            0x5E9B38085488DB73ULL, 0xBADF56151E3315C0ULL, 0xD1BB11F50D9B25F4ULL, 0x62CB46CF42A90887ULL, 
            0x598929C75A700818ULL, 0xA2D1D75C1DF1E13CULL, 0x63284C73910DFAB3ULL, 0x83C18E20BBF47169ULL, 
            0xDDE80281C80B43B9ULL, 0x41B78C399F007926ULL, 0x33875E4BEE86B1ECULL, 0xF5E134CB3635CCC9ULL, 
            0x8FD0BC315928F98BULL, 0xC114C1B5648BA0F4ULL, 0x7DDC439277565C94ULL, 0x31A2A456268E67E2ULL, 
            0x7472678550650B5AULL, 0x8CB2C40F72E7891BULL, 0x27F608E9198A315AULL, 0xD13401872900645AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseBConstants = {
    0xE5B51E4F8447D89CULL,
    0x4FCF006F26CADC0EULL,
    0xEBB4A7A9C05B51E0ULL,
    0xE5B51E4F8447D89CULL,
    0x4FCF006F26CADC0EULL,
    0xEBB4A7A9C05B51E0ULL,
    0xEF54048370390D41ULL,
    0x65E0EC6944A64279ULL,
    0xFA,
    0xFE,
    0xC1,
    0xBF,
    0x1F,
    0xFF,
    0x65,
    0x84
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseCSalts = {
    {
        {
            0x8FA8521F6E879E5CULL, 0x5F655EECB16ADC96ULL, 0xFE3503D65ED7A663ULL, 0x5E3D9D8076016826ULL, 
            0x2A9339C7BCA9531DULL, 0x2CB58CB84402BC01ULL, 0xCBF47EE1913D2E65ULL, 0xE52446E4E1385A23ULL, 
            0x2A7B4F7334FCA8EDULL, 0xDA5D91F2541E79CBULL, 0xEF74381399B97E8EULL, 0x2E96D77FAE597D0FULL, 
            0x8DDA5B8F55CB2DE4ULL, 0x270D89D2116DC764ULL, 0xA337E3F7E7FB9484ULL, 0x7DBFF477FFA16B47ULL, 
            0x9C2DDFCB77EA22BAULL, 0x9F88F5FE1D6DD2C7ULL, 0x51C0B9778F89335DULL, 0xD840D0AB468C9007ULL, 
            0xBF17F5C1A44EDA53ULL, 0xFD1678A4AFD7CB92ULL, 0x69758752A4D6EEB3ULL, 0xF441A924632F0135ULL, 
            0x02265C16FEFA5B15ULL, 0x7BD78111E692FAD6ULL, 0x57B493980986A02CULL, 0x7CDF702ECD714F63ULL, 
            0xD7EB70FCEDF65A7DULL, 0x54EE88E615B7BE8AULL, 0x647A311195CD3641ULL, 0x8CDE0925189C650EULL
        },
        {
            0x67B2712A08B8B8A4ULL, 0x86A984ABDE1FD5B4ULL, 0x5C5ADCC6AA9D21E7ULL, 0x23FBCE6F53744811ULL, 
            0x2496B3481725860CULL, 0xF9CBBD285C623C30ULL, 0x5E281788E9E627FDULL, 0x8E6EFE6E4D902E83ULL, 
            0xCDA6F5A609BCC551ULL, 0xD84A8E8D2F6556FAULL, 0x5AB17F0E5678C244ULL, 0x7D65AAE8D66699E5ULL, 
            0x4131D3273C0922E4ULL, 0xD6F31B9E4AD65684ULL, 0xF514568DAB88C89FULL, 0x6E051F944696B9C2ULL, 
            0x7E4427F8D0D44464ULL, 0xA1A7167618BB1017ULL, 0x04D52E7FB19C35CCULL, 0xC714F401929B9434ULL, 
            0x4BDCA0E4CF3E3037ULL, 0x1628B79531A6BAD0ULL, 0xB05EE71D08D3FCA9ULL, 0x5A86F5D9A72C78CEULL, 
            0x4C6C4FCBE33D7711ULL, 0x95FC95F3246D06DBULL, 0xA33E55352E56CEAEULL, 0xFF82D25596ABD7D2ULL, 
            0x6BE7C7C31CE9E6B2ULL, 0x608E0D5AE75C638FULL, 0x730B54141275AA6DULL, 0x9388BD6FBD7ECF47ULL
        },
        {
            0x3563DC9E0329971BULL, 0xBA0AA7FF061A18F1ULL, 0xCC41BEED18DA95A6ULL, 0x9011CEDCE53BDA75ULL, 
            0x83814A3B0943AC0CULL, 0x7046DB5AFFA2ADDAULL, 0xCCAE2A2240C3EB1EULL, 0x73D1903DC88546F3ULL, 
            0xDCE875986BB543F1ULL, 0x54A37867942C3516ULL, 0x53414CB94F3328A4ULL, 0x28828732A5B2EB5DULL, 
            0x148EB4F06BECCF6EULL, 0x7504FB80150A8B7CULL, 0xB8A1A0EF549EC4AEULL, 0x62A27CE957A5185FULL, 
            0xCFB835F240F28104ULL, 0x4253B8AFD68DB53AULL, 0xD7635615B5611789ULL, 0xFB6D6C5459EAD898ULL, 
            0xFDD1C0F1FB2E9349ULL, 0x97E445E8AED27713ULL, 0xB83B135AF5E006FEULL, 0xD6C471295341DA46ULL, 
            0x53B01AA13C4323A8ULL, 0x4F81240715DC5591ULL, 0x897DDDD7C758A58DULL, 0x129BF68EE3975F8BULL, 
            0x52297F1FF3B13991ULL, 0xB612472F74A02C27ULL, 0xDE59737398B4D6B5ULL, 0xCCD35314440F3954ULL
        },
        {
            0x093797B0937B10E9ULL, 0x6C928EB5AA5E802AULL, 0x8B63F9C1887947E6ULL, 0xE50C4AE752196739ULL, 
            0x8E416E0B93000564ULL, 0x4E92FA5329B017FEULL, 0xF02AFE7B1F9FEAFAULL, 0x4640C657DB4CE988ULL, 
            0x4CD53B94A696A475ULL, 0x7C28FC8047A376ACULL, 0xA2253B3B10A66473ULL, 0xFCB7B8371FC9B0D4ULL, 
            0x23FA6D044A12BAD2ULL, 0x3192477D292B9FBCULL, 0xDDB9529A02B139AFULL, 0xA13989C3144A53B4ULL, 
            0x3EE607508DEBA2A6ULL, 0x05A4DAE9D06E78DCULL, 0x195F2EEB00291495ULL, 0x25D7C78A0E36672EULL, 
            0x6BF90B2FDF3EF627ULL, 0xD202E251E14975EBULL, 0xE6BA581C57F0D5A2ULL, 0xBC4370FA9F0CF06EULL, 
            0x4245DBD47E335E67ULL, 0xBC90C17AAF680690ULL, 0xFD379D76D91764DEULL, 0x3952271BCEBAF365ULL, 
            0xB274388588E21D28ULL, 0x2692989C7BEF9C6AULL, 0x5AED8F196E59A5C1ULL, 0xFC0902B5F8012456ULL
        },
        {
            0xC676B85313BE75DEULL, 0x093C7FF645B5E682ULL, 0x5848ED02AC6FC884ULL, 0x24A13B9A42C8FC47ULL, 
            0x86A6575C14036122ULL, 0x0F4BE745008E4B1CULL, 0xDA9838CD6DD3481EULL, 0x8B242EB648A487C2ULL, 
            0x9070CD6229B1C649ULL, 0x04B66467A554E51DULL, 0xF71CBC6E0EAE775FULL, 0xCBD718727EF4D819ULL, 
            0xDF07D24C6AB438D5ULL, 0xC6F1B129A7F8FF3EULL, 0xD7EBC874AC9C00B8ULL, 0xEBC1727D32994E94ULL, 
            0xCE3940338096D586ULL, 0x9D77297B29D98EE9ULL, 0x7111964B7ADBF3C4ULL, 0x1210FE367EEF13FBULL, 
            0x8414DDF1C779F1B1ULL, 0x48D7D0AACADD0F4EULL, 0xB272E0AB30208EAEULL, 0x04798E4289A32986ULL, 
            0x4BA97CEBD540EF97ULL, 0x2C23CDDEF4FD186FULL, 0x0D28DC54A880F287ULL, 0x4C2753ABD588B3ECULL, 
            0xE6C03F759E6123AFULL, 0xE26066DC004CCC10ULL, 0x7A5F5849EF9FD3EDULL, 0xC05F28C342A9E483ULL
        },
        {
            0xDD24C030B406F2FCULL, 0x607AD845E1D6ECCBULL, 0x32D6719EBE3D32B3ULL, 0x434A3939C01F17FCULL, 
            0xC1DAFEA43D2A07AFULL, 0x7B98B214F4837BC0ULL, 0x1707E09F7B60A699ULL, 0x266E25C65F5CFF25ULL, 
            0x3A61D3B7662C714AULL, 0x61785DFCC13AE334ULL, 0xD4EBB7AAA172834BULL, 0xEC0C9E31E795AB95ULL, 
            0x2D412B3C764038B1ULL, 0x87074DB38F6826DBULL, 0x3AFC41D0DB381446ULL, 0xD8F6235A06C7589DULL, 
            0x214B95C70806188DULL, 0x77496D29BC8E37A5ULL, 0x0858AEF22A458741ULL, 0x337C8B8765360685ULL, 
            0x0D6B7CE5E7A26D70ULL, 0xEB507FAD4E960BB3ULL, 0xD558B9F3C7CF5608ULL, 0x9BEB124B97DA5BB7ULL, 
            0x58ABBABA1D60A29FULL, 0x7BBE80BF7E080171ULL, 0x50A1D47B516F93CFULL, 0xC7B510EE499D120EULL, 
            0x6DEB46ED36393646ULL, 0x8307AB826995296AULL, 0xF2FB6C6D637E55B8ULL, 0x7274250408163122ULL
        }
    },
    {
        {
            0x1141FDC98E20AA41ULL, 0x727A083A3A1F3EB0ULL, 0x6D61DE79A6173070ULL, 0x61C1D437E22964D7ULL, 
            0x39F6A83BC48347AEULL, 0x737D01EF6DF8FB85ULL, 0x195DFA7908E707FBULL, 0x6DD6BAF0E0A18A02ULL, 
            0x77D4E2D525A0EFB3ULL, 0x31378DE1098A65C2ULL, 0x0BD14BFB46D3D14DULL, 0x68FCD99A08659D7AULL, 
            0xDC07683AD0F26B75ULL, 0xD7DBE2E56F1B4A97ULL, 0x5EC9DF1F0FED82FAULL, 0xBB48B6557EB42E86ULL, 
            0x55A7536F7413712DULL, 0x324E99AE3F1D4A38ULL, 0x946FC3186C69C988ULL, 0x67ECC093E9F3B7D3ULL, 
            0x9CDA003A83742AF7ULL, 0xA91EBB8105389280ULL, 0xE19A1CFD9355D523ULL, 0x80F69F6572A987EAULL, 
            0x962DC127A850D884ULL, 0x883254E222B4C2DAULL, 0x50F5AD898E176F2DULL, 0x97F3FC961CECA39AULL, 
            0x260DCCE871A4870EULL, 0xB7CD6B53C2C541DCULL, 0x80422B3086DD76A2ULL, 0x87F7626FEDD2A61FULL
        },
        {
            0x3FDA77260DE2B1C2ULL, 0x71A00B7C063E21FDULL, 0x6DFDE6B13DD7E729ULL, 0x6ED4CDE2A24A1839ULL, 
            0x57D23A65EF4CD88DULL, 0xCD9EF7A91CB6ADD0ULL, 0x4923F45E29A33FD7ULL, 0xC90A9B46D902732AULL, 
            0x29827C744744DD5BULL, 0x5709B4CDBC73EC77ULL, 0x6606C984ADFD09ECULL, 0x709445BF823826EFULL, 
            0xFF8A9BC9B5AEEEEFULL, 0xB42E6DEFAB8EFF06ULL, 0x8CB519D837039C83ULL, 0xA75BE52FDBA505B8ULL, 
            0xAE7108DAC7C81BA5ULL, 0x1E1046224468E3B0ULL, 0x1B00DD2E7CE81249ULL, 0x3FC703B2DA7CB76AULL, 
            0x87862CABF5DFD8CDULL, 0xAFD6A7C886A2DB5EULL, 0xB4115CB6B9959E95ULL, 0xE54B6DC09318FAFFULL, 
            0x1BCA1002406BEDEDULL, 0x335F8987DE7922B8ULL, 0x81B9DBD85EE4A619ULL, 0x980AA59528447AB9ULL, 
            0xB5448EF47A85DFECULL, 0xF1EBB293213873A7ULL, 0x737A3BE3B1DBDFD3ULL, 0x3D2B0E7E5C55C3A9ULL
        },
        {
            0x73C1E877B6B6CEFBULL, 0x1101252A1FBD77A6ULL, 0x4EF95D94C104FEA7ULL, 0x4FC9BAD838B6F31AULL, 
            0x04E2AF4FD60E4B23ULL, 0x337A272CB72548B8ULL, 0x22758D9BD6EB35DAULL, 0xA5BCB299A8459BDFULL, 
            0xCEE87413AEFC988DULL, 0x26B41B246E7918E1ULL, 0xE15A4E6F98A477F9ULL, 0x89C43CD650CDEE42ULL, 
            0xDD79E24FB3A48476ULL, 0x08326362CA80F595ULL, 0xE7721B31DE3ED8C1ULL, 0x28B149DF65A5CE52ULL, 
            0xE8913D8BA3DF0435ULL, 0x272348D18679BE3DULL, 0xC93197F618B480F7ULL, 0xCF887B0D3263F326ULL, 
            0x31D7AB04F8DFE474ULL, 0x67007423BF6C7880ULL, 0x710F333752E33AD5ULL, 0xE6958EFC2015EEAAULL, 
            0xE7836DA4C9830AD2ULL, 0x271B1CA6151236B5ULL, 0x7C3DCD552D6A6895ULL, 0x75991387F447DF9BULL, 
            0x832BDEC24DC3E3F8ULL, 0x6182F81A846F3C97ULL, 0xCB9165D0FA69A09BULL, 0x0E65AF354F7C8DC1ULL
        },
        {
            0xEAC1B7DE716F4F5FULL, 0x357CA48CE40E2043ULL, 0x50F4D7081C44CC89ULL, 0xF81097A05BF2BC4EULL, 
            0x841184A1A3C3ED51ULL, 0x0D5DCECE20170F55ULL, 0x16C20749065E6EE0ULL, 0x47C00137B1C58748ULL, 
            0x15042A3C32EC44D1ULL, 0x851FFA7E15D42387ULL, 0x02DBE122785EFFCDULL, 0x08CF51A998A2ABC5ULL, 
            0x68CD6FAD43BACFBBULL, 0x8A5CF129E44D3433ULL, 0x579DFDE0BECC1399ULL, 0xD3E3A413044090CDULL, 
            0x67147EC3DDDF0900ULL, 0x51E85B4B1C95D419ULL, 0xA4CC37767F4E022CULL, 0x2E96CCA060ECD035ULL, 
            0xABF7D8F5F2EF4366ULL, 0x94F4A02E1D1829EDULL, 0x9B0AA739B2139B4AULL, 0xD5C8772ABB61A3B4ULL, 
            0xEA94072CA9BDB38CULL, 0x23290B911B8355D1ULL, 0x5FB5D741E799ACD7ULL, 0x508A8103734629FFULL, 
            0xEAA9768154426FF1ULL, 0x5060C1B4AEEB511BULL, 0xA32A3C653BB81C77ULL, 0x6FB3BA3C26A4BB7AULL
        },
        {
            0x2E8D58AD019E392FULL, 0x347A15A576862B37ULL, 0xD18649A19144CB71ULL, 0xE280EF3C64F78E3EULL, 
            0xB746943091F5D9F9ULL, 0x8FCB315636805CBAULL, 0x3E5F6554D4A6ECE1ULL, 0xF5C93CD2C300A1D5ULL, 
            0x1740F2D0BAB95F2FULL, 0x013834745768B680ULL, 0x9F26B455B29419F9ULL, 0x79FADF9965E09532ULL, 
            0x26E29D79C1DB7CDDULL, 0x8EE4C02741AE702FULL, 0xDA6A4D8890A3C9D1ULL, 0x51C07DB0C408B3F3ULL, 
            0x6E9A422B945E5ECDULL, 0x8C6931F633064552ULL, 0x8F5F7ADF328596FDULL, 0x8588A47EE1EBEC2AULL, 
            0xE595BFAB9FE611AAULL, 0x14A0C8F0E6E78584ULL, 0x719C0924F3A504BCULL, 0xB55E6C7248491CB8ULL, 
            0x5C73D6103B72203FULL, 0x205385A634E8437AULL, 0xA65ADC979E6D6D8BULL, 0x6E64A7428EC2905FULL, 
            0x171365442092B8EEULL, 0xD9DFF2E588C89D5AULL, 0xDF394A29FFBF225CULL, 0x3E4C318426010CC7ULL
        },
        {
            0x012ACE9231118D44ULL, 0x1718E563CB239BD0ULL, 0xBE32873EA08F4097ULL, 0x88C6247327119C06ULL, 
            0x3A4D67FE0D1DE256ULL, 0x79A27E7235FB54F0ULL, 0x2ED16DEA65E2B035ULL, 0x4815F7184A108FBBULL, 
            0x113A8AA8BF8072C2ULL, 0x01DA2E16B04706B0ULL, 0x55EBF92A48F2477BULL, 0xA77BB759BEC51A34ULL, 
            0x877D216B3CE3F3A8ULL, 0x1AAB11CD38C7C992ULL, 0xF73F7394B0C83F07ULL, 0xF4695246A8061D10ULL, 
            0x5E69691CC203F9DDULL, 0x3369EDE97B85D386ULL, 0x957F6E08401E0CA4ULL, 0x336DAB803EE0299CULL, 
            0xF24E359251C03157ULL, 0x78606EA92609387DULL, 0xAF484D32AD5D4DEDULL, 0x4D335701F7B15C83ULL, 
            0x4F6FB1A3BD7A61C5ULL, 0x1EDD0D0938E76BF5ULL, 0x4E7C9173CE3DACA5ULL, 0xAE7194DEA214264AULL, 
            0x76C59CE8FB65ADE7ULL, 0x5547E6E542A6A84EULL, 0xAD32B26F7D4C45F4ULL, 0x02764107B19668A0ULL
        }
    },
    {
        {
            0x7588E01F160DA557ULL, 0x7A823C222D58D276ULL, 0x3BE5FF27AB89FB62ULL, 0xA41D2DFD92543A16ULL, 
            0x88B13042D6E72989ULL, 0x8CC9EC8C3CEC84ECULL, 0x8C0FCD0716FCCD46ULL, 0x8FCB29730994562FULL, 
            0x7559BF497E9BE52DULL, 0xE45F2316AEB26E8EULL, 0xBA18665FBC884345ULL, 0x68FFDDC4AF991B3BULL, 
            0xD7A942BCC7BEFDE1ULL, 0x07064C1CA71571C3ULL, 0x34C95788BF3DA497ULL, 0x924A1D35EDA2FE9BULL, 
            0xB2E14D7A26A9E90AULL, 0x9CF5A058AC926E8DULL, 0x46D199B56A197757ULL, 0xA21A219A882C924CULL, 
            0x58E9DDCB5ED7DFD0ULL, 0xC8CE36E28FD85516ULL, 0x70D643FC970FD6A7ULL, 0x2DD997A33DC78564ULL, 
            0x7BC13D46BA05A9E1ULL, 0xB59A63CC1520CB35ULL, 0xE0306748318C29D0ULL, 0xE96CF6433AFFCB3DULL, 
            0xA44B82D5733896B3ULL, 0xD236521839435754ULL, 0x3F447E128B779037ULL, 0x93910041EBA9C1B8ULL
        },
        {
            0x64952654218DD8B7ULL, 0x0323A65D00DD2646ULL, 0x15F6A23000B636E7ULL, 0xB86180CDAFEBB884ULL, 
            0xB2A9FC8BB8DDEA19ULL, 0xB050581E2A5F1B1EULL, 0x765C78D851E2847EULL, 0xEEC2306919388766ULL, 
            0x7E965C3F62B8F9F0ULL, 0x20EFD9ED87AEA668ULL, 0x7D079A04F86C2D0BULL, 0x89A6D870A6363263ULL, 
            0x4B9598E2F158BF91ULL, 0x30900F0E2CBAD54CULL, 0xE1BB00677B0363DEULL, 0x4583EF6E54BDCAD2ULL, 
            0x6E016ADBEC676FD0ULL, 0x46A0F8223793B756ULL, 0x003739C9E6043D77ULL, 0x96C60C439D6C5657ULL, 
            0x69412B63B76DE513ULL, 0x07963A2F531E3C64ULL, 0x34C917146519F9D8ULL, 0xFD4EE488ABD65901ULL, 
            0x6255BC7D4710E115ULL, 0xC3EF51FCFFD0AA34ULL, 0x1922D4B120F5564CULL, 0x2263F3DE06C2897EULL, 
            0xA05FAA12E0E800C4ULL, 0x1A74F938FC2353A6ULL, 0x76428BBBC8EDB78AULL, 0xB32AD39EE0CA5975ULL
        },
        {
            0x8DE7AD78A6579D12ULL, 0xE7C6AFAF91222DE6ULL, 0xDB0A6F0876EA9221ULL, 0x73BC998CD55C6FE3ULL, 
            0x5F3D936E449133AEULL, 0xF6206EA024F565B6ULL, 0x6A844BA682740EF7ULL, 0x5E276A2DDD6B5DFFULL, 
            0xFC41BAC51038709EULL, 0x9411A251ACBDDE66ULL, 0xB9AA430549173A57ULL, 0xD65C16B0B865983FULL, 
            0x6A29B3EA11C70108ULL, 0x0F20BE7B4A9CFDBBULL, 0x59536A76B5CC214FULL, 0xA8C979844A98F5D9ULL, 
            0x67E9F5ADB6634524ULL, 0x17BFA32C0EF0CB44ULL, 0x546140DC204EB940ULL, 0xF909C0730EC1A633ULL, 
            0x686870E32D03E20CULL, 0xEA2BC4F650F0C632ULL, 0x6329B5656C5C7095ULL, 0x89E9909D259FE485ULL, 
            0xA92C5199203D157AULL, 0x4F50A23A4E49E153ULL, 0x5ABFD584C80BFD5DULL, 0x3BC2B913FF329A04ULL, 
            0x3DEDF589C8077A6EULL, 0x5356D7449B3BE719ULL, 0x5ED4BA91DE0C1041ULL, 0xE700D6B5889C288EULL
        },
        {
            0x5CD2D3622EEBA617ULL, 0x721A2FFC1DC70CB1ULL, 0xBDA9C7E5F4C576A3ULL, 0xE6557BEABF469063ULL, 
            0x864B9DAAF664FC2DULL, 0x254ABA709FBD8EBCULL, 0x037C5EC4680C5574ULL, 0xFC7391A0EF512E87ULL, 
            0x05D993C60BCBB28AULL, 0xC98DF250A418D8BEULL, 0x7AF1F3B96080CC59ULL, 0x78577A17E138FCD8ULL, 
            0xB9A1137F3592D490ULL, 0x0069AFBC6F0491F5ULL, 0xCFC2667D58D58AA9ULL, 0x1BB038443D9FA2EEULL, 
            0x00A8CDC170280812ULL, 0x110C1090A53E283AULL, 0xA6D7FB5FED79D599ULL, 0xDBC1D56B3951F35FULL, 
            0x0708167020AAFB25ULL, 0x17215FB2077E410EULL, 0x184A2356BA74F60CULL, 0xA7E38486024E5ECEULL, 
            0x78E4BB0ACF6E5592ULL, 0x7991160E2448FCA5ULL, 0x660ED4539B26F90FULL, 0xC658447525D95A6BULL, 
            0x53F939F521A87C70ULL, 0x884C2DBC2E8B6881ULL, 0x997423039736B9D8ULL, 0xF588AF6610AC4FE1ULL
        },
        {
            0x91A8EED0C6C4E10AULL, 0xF91327C5012A783EULL, 0x8B01F340655A9B52ULL, 0x924D407535686DBAULL, 
            0xDA880293D65BADD4ULL, 0x0FEAC033D61F67A1ULL, 0xEC194F236EDEC359ULL, 0x622D85F8418108A3ULL, 
            0x59D65314DCAEBC2BULL, 0x132C4C9D06F82145ULL, 0xC4FC49013B9B70FFULL, 0x2B1B338762B2CA3AULL, 
            0x0BD6FD115F2C6B8FULL, 0x007FADC0800650E4ULL, 0x1020D5718712D05EULL, 0x0233B2C02754CAA7ULL, 
            0x5381F640F3F3B5C8ULL, 0x54CB36E8D3D2B7B2ULL, 0x8EABBA074A19FDE5ULL, 0x3F307D8171C8851BULL, 
            0xBD31DF8E8E6A93C4ULL, 0x1497722FE6CE069CULL, 0xD8F82FF29004C21CULL, 0x27F0F7C2CA613633ULL, 
            0x6102B61264E84B0DULL, 0x49F120D65D222EF7ULL, 0xF579288369095B6AULL, 0xAA9078D555E9ABC3ULL, 
            0x231F521D5987F9C8ULL, 0xD1B680F4070303C7ULL, 0x280693E281A2C40BULL, 0x761322272FCDF18BULL
        },
        {
            0x3FCEA441244A2CC3ULL, 0xC9493883719BDD9AULL, 0xA78F5C0327AFC923ULL, 0xD7846A97BB7ED644ULL, 
            0x6DF4980A538A9DF1ULL, 0x5D549DD884FEC4B7ULL, 0xA0CC5C395D1291C5ULL, 0x77376AB4C53B4FC3ULL, 
            0x09565D22BA67B396ULL, 0x80427A0B77641EE6ULL, 0x684091B897D84FFFULL, 0xF03C3586012D582FULL, 
            0x75556008E6D33AD1ULL, 0x6E26225B7C81F0BEULL, 0xD376D8C867875A2BULL, 0x7BB135772F0793ADULL, 
            0x754FC7D1F38844AAULL, 0xA1C7DBE58F355A82ULL, 0x5F27DAB3A8C84DFCULL, 0xA40DF06701DA48CEULL, 
            0xE62F5586D8002C4BULL, 0xEBC8F30C1752E31BULL, 0x685F3002734DC9FBULL, 0x01036E668315D9BDULL, 
            0x7EE02BD13F444D2CULL, 0x116AD695745D277FULL, 0xEF532E1372810D79ULL, 0x5D10ABFD0752D367ULL, 
            0x19F3FA5D7D5F6468ULL, 0x61C67E4C4D450680ULL, 0x24C975224654BFCFULL, 0x6FFED6710E76C43EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseCConstants = {
    0x2739923CB83B385FULL,
    0x3E2DE070BE7F3B92ULL,
    0x0952A6742927BEC9ULL,
    0x2739923CB83B385FULL,
    0x3E2DE070BE7F3B92ULL,
    0x0952A6742927BEC9ULL,
    0x39004BB60531E466ULL,
    0xFEEF601BD11A7E1CULL,
    0x4A,
    0xDC,
    0x0A,
    0x4A,
    0xB4,
    0x62,
    0x62,
    0x1B
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseDSalts = {
    {
        {
            0xF01C4A354DCC9D8DULL, 0x29B71C0503D1980CULL, 0xCCE88F7F0B077BA4ULL, 0xF272CE9DF633FA42ULL, 
            0x3439E68461B05CE8ULL, 0xFE814A5DA69BC066ULL, 0xF7A005807FBABE4AULL, 0xFCD6ABFEFB57F450ULL, 
            0x3431B3B00526A30EULL, 0xB99CB8F7E2EA1C99ULL, 0x9BB95E9AEA9FB5B7ULL, 0x9FF4EC49F7FA97C3ULL, 
            0x69A97CEE1F0399C4ULL, 0xF00753D029F12549ULL, 0x47E1F4C628301055ULL, 0x5382B5CFE95F25E4ULL, 
            0x45857A62E8293FBFULL, 0x30767D4ADA989645ULL, 0x76B6E9C5131D6198ULL, 0xFFC3F72481305D50ULL, 
            0x7D19460C5FF9CB4CULL, 0xF6750DB788C7795BULL, 0x8401235528BBF7F4ULL, 0xC6FADC298BB129F0ULL, 
            0x5F6D95D58D98F390ULL, 0x6A789C7C5E9DBF27ULL, 0xA803F66B81B09C63ULL, 0xF61389A0E03FA573ULL, 
            0x8A45B31754EB6D6EULL, 0x9314770EA15090BFULL, 0x2C81362A361477F2ULL, 0x380E518AB06F72D5ULL
        },
        {
            0xAF1A413DB9B7A125ULL, 0x202456A3FD2BA3A3ULL, 0x3A0E1CDBD1A94B22ULL, 0x8DDD5132520EDEC1ULL, 
            0xCFAAF3417DFD2536ULL, 0x6AEF66D3F3C3C599ULL, 0xB3F5198B275C68F8ULL, 0x6C8E1C939F5C2F19ULL, 
            0xAFD864A350BEF473ULL, 0x284744355F4364DBULL, 0xD0F30F22635BC4AAULL, 0xF6BE9FE9E2FDC465ULL, 
            0x2D6C3F2CF23FD41AULL, 0x5B26B0576BD4540BULL, 0xA881801AE4129C3AULL, 0x174C40426B14C19FULL, 
            0xA898527F8782F9DFULL, 0x78B9BFFBFA60CE99ULL, 0x10271D1DE57AD815ULL, 0x1D86DA2952F98589ULL, 
            0x6BFFA0C6DC38D142ULL, 0xD8B070542E49F9D9ULL, 0x1C6B5F1EC66F6348ULL, 0xE30759CE3AD4B95CULL, 
            0x64315526BE37DFA7ULL, 0x6E6E1ACE02D82E05ULL, 0x64588B1DA985D6B9ULL, 0x8D77C4B033AAE7AAULL, 
            0x34A178D417D7B590ULL, 0x3FB70FEBA934DFF3ULL, 0xDD841A9B4E420D59ULL, 0x2C4DDC2E5BA13B35ULL
        },
        {
            0x2114EBB641708DC2ULL, 0x3A104F324B2095BCULL, 0xA08ADA11E3F861A2ULL, 0xD9F505710DEB6DB0ULL, 
            0xB0622F04D4193F67ULL, 0xBCA6EE07D93149DEULL, 0x697FBB1E5422D765ULL, 0xEABE3258B6EC23E6ULL, 
            0x1AFC1CA8EA342A46ULL, 0xB4DB074A357E2138ULL, 0x474597EEFCE71219ULL, 0xF5EECFD7A7B1B947ULL, 
            0x6132D947C08D5535ULL, 0x535BEE86DDA6331DULL, 0xF039463519515FDBULL, 0x7B25DB532A99EA75ULL, 
            0x3824A0D80465F8DCULL, 0xB099CEA659E79081ULL, 0x36D912D67DACC421ULL, 0x2E6180742C8A3BA4ULL, 
            0xC4D0353EA0800893ULL, 0x6EC7175E07C91744ULL, 0x41D4B2C7946D1A46ULL, 0x19364E79DA199D07ULL, 
            0x324F4CEABCFD1DF4ULL, 0xBB9CE0924C8047B6ULL, 0x4A22F01AEBE49CF6ULL, 0xADA1D154DBA9374DULL, 
            0x7E82A148B19C2696ULL, 0x8B283C88EE770AB6ULL, 0x6DB852EF5EF257B1ULL, 0x1F7F3842E7F8C411ULL
        },
        {
            0x646CE58366022827ULL, 0x7612333C8ABF50F3ULL, 0x7369C1B8919BD106ULL, 0xDBFB6E977DD291C5ULL, 
            0xEB6158700F6F4A9DULL, 0x08BBE94DFC74EF6DULL, 0x47A47E82CF5FC204ULL, 0xA466A5898CBA7181ULL, 
            0x425E0173A5B3866DULL, 0x437591494298C108ULL, 0x341D73B559B404E2ULL, 0x48E0E7B40AB381C8ULL, 
            0xFB90846B93B3AC05ULL, 0xAE270DC6E4D1C66AULL, 0xB41C1911D93DC723ULL, 0xB8DE7ACC4ADFBB8CULL, 
            0x315606AD4DE57BC9ULL, 0x0D511030BC315EDAULL, 0x3D8347F400270CB5ULL, 0xC52FC6513130ED8DULL, 
            0xF1E39B5044F01A03ULL, 0x9B7CFC46C588EC74ULL, 0x76814A6FC2A81BFAULL, 0x5C75DF95920598ADULL, 
            0x0CBD5E10BE12B270ULL, 0x9CF24FAD1D6F648AULL, 0x3D4F34FD9FB6551BULL, 0x397B9CBD59809970ULL, 
            0x187FDC7BD01BB9B9ULL, 0x011A59F905C51657ULL, 0xD5AB65F236CD66C3ULL, 0xE69B99FAF444F88CULL
        },
        {
            0xA3C79A0EC305C818ULL, 0x41E04A0750E33DAAULL, 0xD0BF1DE25118DE6FULL, 0x4ABFB9B423F45E8DULL, 
            0xCD43FDCEF125986EULL, 0xFB47C8EFCEEC8D14ULL, 0xDE7B6778B5582CF4ULL, 0xF32F10864D51A7E0ULL, 
            0x378CF41673DE99D3ULL, 0x50F88500539B2C0DULL, 0x1F34D093A6071974ULL, 0x9DB96368E3136571ULL, 
            0x20735D2D00715023ULL, 0x45B92D0CC82DB560ULL, 0x52E3BEEE70B25101ULL, 0x2D1B90D12368DF26ULL, 
            0x165B3C6DBECC8CE6ULL, 0xDDE847733074B8A6ULL, 0xDDCA3B63D4D980A5ULL, 0x4ED7876CAC5A6F5BULL, 
            0xD6AA3378C6D45A5BULL, 0xAE9BA36A8D1A43C5ULL, 0x457B03173822C7BAULL, 0xB98E29AC35D69637ULL, 
            0x5FEB02879BF9AD8AULL, 0x85AD536E1CBDA640ULL, 0x79360590F2FDE6C3ULL, 0xC0B85EC97D6E4F83ULL, 
            0x1D05D58868EA35EDULL, 0x41D2AC10A9514BDCULL, 0x4FA2A1345C34E90EULL, 0x4F1E1D7A032ED63FULL
        },
        {
            0x0F366738B3DAAA60ULL, 0x8D89846A72CCC9E4ULL, 0xCBFF7BDE61C338A2ULL, 0xD787450393D18FFEULL, 
            0xB0607019FA54DF6FULL, 0x36D45E5E826DE2F7ULL, 0x5BDC2D94F0D82D0FULL, 0x8117E2255C574918ULL, 
            0xF838FA469E10D42AULL, 0x2CF2C1639093F64BULL, 0x9BBFE04D16D0A64EULL, 0xF34E75878B4CA008ULL, 
            0x6A4294BDAD1EB3F3ULL, 0x9B5F8AFDFCF7DC36ULL, 0x7A7FA88CDF459E0AULL, 0x848321A625EE257BULL, 
            0xA6954CB8C0BE4176ULL, 0x385E59700A20DF35ULL, 0x5A75CEF484C379E4ULL, 0x43137F9958651BC8ULL, 
            0x6971E58756F954B7ULL, 0x2892B14557FFB2D4ULL, 0xD86C878A5E08A845ULL, 0x0814F40EAEAAC79FULL, 
            0x480B74428754C30CULL, 0x7FDB85BAF696C74DULL, 0x6DF554F03D504BF9ULL, 0xFCC5A5E1A50E7950ULL, 
            0x111872A81E9DBA1EULL, 0x845A7760FAD5FCCCULL, 0x28FAFBC7C346E002ULL, 0xDBA58A666C0BE6B9ULL
        }
    },
    {
        {
            0x8DE15605D72AB466ULL, 0x3A9454449A3AD148ULL, 0xB104E1F7C5A17F8BULL, 0x0A69187170C8AD2FULL, 
            0xF6739C03E3F9BF6CULL, 0x4E51543157101873ULL, 0x8E82A495968BF682ULL, 0x5BEDB5DA468B64A8ULL, 
            0xBE0E758EDBF01360ULL, 0x48FF666CA09108B0ULL, 0x1DA30641127E022CULL, 0xCFEA4FC25F36E2F5ULL, 
            0xCC615D0C465AF636ULL, 0xA6A98DFB89A265C7ULL, 0xB0158003BA1FAD88ULL, 0x0B78D7BECA7BFB10ULL, 
            0x93146D247A4BA087ULL, 0xBA6B5CD00895659AULL, 0xAA9346AC9F460FB4ULL, 0x591C520A96B87BBEULL, 
            0x12F5404BED428647ULL, 0xFD89AE9738CEE831ULL, 0x6BB5C0CB74CC71ABULL, 0x84966BA1B2B2FFB6ULL, 
            0x3E726A4A2BACB6C1ULL, 0x7CFCA54CF2CD0AE3ULL, 0xC6005D3354FDE219ULL, 0xEDA9D3079F0E2D2BULL, 
            0x190EB687F5632A75ULL, 0x81EE8F2A6E5763BDULL, 0x49968C89F97192DDULL, 0xF0661077D93B6C05ULL
        },
        {
            0xC021AD8DE0CCCE60ULL, 0x3860C672D7EB5E6FULL, 0x233423F3209B41DCULL, 0x0B2F15F8B89E4C2EULL, 
            0x54F734443C2E24F2ULL, 0xB8B0876F9298D048ULL, 0xACD56227457E0F0FULL, 0x24B918440B86B9FAULL, 
            0x8C1626DAB8A234ABULL, 0xFAAC9B06648A05BEULL, 0x549975B832469EC8ULL, 0xDCDC956C7E91ABA0ULL, 
            0x4BDA6AE7017FF027ULL, 0x765DC16B4673C5D0ULL, 0x729AB9E7B67A8C03ULL, 0x760EAA6068B4AE34ULL, 
            0xD928623B023B2E63ULL, 0x4777C70E5D5A2C75ULL, 0x9A409C64A24C6ECFULL, 0xC23948F27245B856ULL, 
            0xD56A472A481F36C1ULL, 0x20800CDE1473185DULL, 0xFBCA2EB896692322ULL, 0x37682C1BEF11FCEAULL, 
            0x3FB51F7EB6548D4AULL, 0x03FC7FEEFE708C46ULL, 0x01CB66005B3D1922ULL, 0x78555A08C2DAC64AULL, 
            0x53FC2854114F101FULL, 0x8225306769864A04ULL, 0x7F129FA7813CD253ULL, 0x1BFF286821F7399EULL
        },
        {
            0x0B926C510A0FB852ULL, 0x2A36E0038D5BED8CULL, 0x10257B80960844BCULL, 0x3829BB3037375456ULL, 
            0xF785C218E7C5FD15ULL, 0x9ABF5EA6DD553BF6ULL, 0x40DF3217BF8DBA3EULL, 0x5E1C6D95C094C365ULL, 
            0xF987E516E9BB4EF0ULL, 0xFDD3EDF638545874ULL, 0x0B687B8F42A66BD3ULL, 0x4F911CDA93B6E3DDULL, 
            0x4D45660552096E5BULL, 0x78EA4D1D42648ACBULL, 0x7C3BE3A6F8D912AFULL, 0xE3C9EFBB0E143DE0ULL, 
            0x2B71C15C07645742ULL, 0x7BE488B67C903950ULL, 0xA5C091718023AFCEULL, 0x96E6132162640363ULL, 
            0x3151A5EBDF6EFE9AULL, 0x56424DCF516CA1E4ULL, 0x71F15C17332788D8ULL, 0xBA7848146A488D34ULL, 
            0x157A84E7ACBCE1EBULL, 0xA690F9BD34329C49ULL, 0x79657FDB239D1FECULL, 0xF9080FD77B9C21E1ULL, 
            0x6072E06C0889B339ULL, 0x58D1D1C5F7C8F59FULL, 0x07145CB66D0C2871ULL, 0x1936433253249BA7ULL
        },
        {
            0xDC883C7B910C3558ULL, 0xEA98DAD064D9963FULL, 0x95A9C3E88C0CACF7ULL, 0xAD3E61EF7EA83836ULL, 
            0x5B070BA01F788E6DULL, 0xBC1232299834C874ULL, 0x4F9BA8377065C6DDULL, 0xAB7E1272706E65A7ULL, 
            0xEA2D3ADCEA710360ULL, 0x5D23C5C00FA9602DULL, 0x6028168A90DD7492ULL, 0xE30176AA94ADA854ULL, 
            0x3103CF9410BF8BCDULL, 0x4FC495C61EAD3548ULL, 0x72335649AD27FDE0ULL, 0xCE03BFFC9F592D3FULL, 
            0xB0CB8F4D7B8A9B89ULL, 0x574971ED7ACF6471ULL, 0xFA7431E9710A1D37ULL, 0x448E700688FAC5B0ULL, 
            0x15798EEDC3A2448DULL, 0xFBE941FF62266A81ULL, 0xE49646BF132CE496ULL, 0xDFEBDA24C6AFE04CULL, 
            0x93B24B1B3FD423AFULL, 0x4AAAE3C1392E6CE9ULL, 0x21BECB40A8593112ULL, 0x9C08C7B8241F876EULL, 
            0x53C363535492EE53ULL, 0x94A4CD6898226C10ULL, 0x9A27AE7FBD1E6E78ULL, 0x5CB6322D63D22E75ULL
        },
        {
            0x767C3EE00A6B4B32ULL, 0x66B3F1EC147DF3B4ULL, 0x6D0C1F98BDDB8E41ULL, 0xAF5A0A0C8EDBDCD5ULL, 
            0xFCF3D59F7C4DC205ULL, 0x8C2A459EFA1EB8A5ULL, 0xC6A4D80B9A40B9C9ULL, 0x70BFF7A1357E29DBULL, 
            0x05E7E376EF4D2C9DULL, 0x1EEB3BD35242835CULL, 0x3A4895215D651591ULL, 0x7082B0E5B87C0F87ULL, 
            0x4E6CCA0FB3DD6C7EULL, 0xE9E15B00A0F9C5B9ULL, 0xF1C487A7530AAE36ULL, 0xBD2D4F7B67CB14E3ULL, 
            0xBA84B326A85F3D50ULL, 0x7D69A5065B558BD4ULL, 0x5480DB1B20B41642ULL, 0xBD1DCB0D5A446000ULL, 
            0xD8B3745C61475F53ULL, 0xA56786731501A995ULL, 0x3609D3FB30BE281CULL, 0x67261FDDB712EE4CULL, 
            0xA6AAC689550CF58EULL, 0xA9C394634DACDE9BULL, 0xC75613F6F8351F7BULL, 0x1D2E5FDBC9DAF5AEULL, 
            0x92EED21C5179D5D6ULL, 0x932424943D57AB4AULL, 0x0850A333112A5F71ULL, 0x75EE6DD806D223F8ULL
        },
        {
            0x4B17B39882FC6543ULL, 0x4C71BF11F9FF696AULL, 0xB6F04BFC34A8421EULL, 0xF82FD3559DBB1909ULL, 
            0x9742D282364F49B7ULL, 0x59E63A92C165DEDBULL, 0xC49447CDC9C9AA0AULL, 0x8481F6FBE62E76EFULL, 
            0xBA13D148BCBC4E23ULL, 0xCF833D0649361834ULL, 0x88628139EB788E46ULL, 0xE556105DE79967EBULL, 
            0xFCEC4168E4B602EFULL, 0x841173F2554335BEULL, 0x9F1F2941C76B1315ULL, 0x7C77DA387542D16AULL, 
            0xE26ADD1DE93205CDULL, 0x953A5B784F2D0EC4ULL, 0x5C1EDD06A508813BULL, 0x12E1B9A1CC24DBC5ULL, 
            0xF377870D883C613EULL, 0x43F8C6A56048BB9AULL, 0xFA942E1D54341068ULL, 0x0C56D82E592C649BULL, 
            0x17E137EA39013090ULL, 0x9C0FA8298C3B2565ULL, 0x90122EE1D6ACBA18ULL, 0x4480C0C126B0835CULL, 
            0xA5F892B13C4D51A8ULL, 0xA59A6A07EDDB8202ULL, 0x0014A092EA9670C2ULL, 0x496F3C0AC351B346ULL
        }
    },
    {
        {
            0x05882B1C7A7D9871ULL, 0x58B85ABC616EBE50ULL, 0x086292CD6AB07BF9ULL, 0xAA2D0EEB4845AA5CULL, 
            0x44C6DC85AB185347ULL, 0x6104A35086ECBBAFULL, 0x67884910127ECB4CULL, 0x2DC740EA4C04619FULL, 
            0x3B4D14562FAA8E87ULL, 0xD726FAA1CF3CE065ULL, 0x00007E091AC8B384ULL, 0x5C9A105B67063606ULL, 
            0x61307186CC649707ULL, 0x920590277C704760ULL, 0x06C90666A84E57C8ULL, 0x9C17907546B3F923ULL, 
            0x54D36664E0A9ABFFULL, 0x89702676503E2B37ULL, 0xAD78304F93A32005ULL, 0xC0D5628B9F33C339ULL, 
            0x9C15D31394DAD433ULL, 0x03BF5E874D9F5B72ULL, 0x8677DFC6803B6B3DULL, 0x28C0AB6E633B8F55ULL, 
            0xB516DF3E082F8D9DULL, 0x483F0ACA2D3D6402ULL, 0x2F1C3BF8A4FB0CD4ULL, 0x1B56218575C39DEFULL, 
            0x37E4C58F433920E8ULL, 0x525953E542B8C067ULL, 0x1288DCE60434881AULL, 0x87437F6AD240C58EULL
        },
        {
            0xA2809EF25DF5A6E8ULL, 0x6F795834E64298A6ULL, 0xE7D94823A5980F0EULL, 0x5AA8AEBF19C3A49CULL, 
            0xDC2041C55527F4F7ULL, 0x24481ACDBD69BF30ULL, 0x1581CF0D98754991ULL, 0x3B28CA78B4FCF517ULL, 
            0xF04DC7678B72E542ULL, 0x147B4F04165BC102ULL, 0xF95404C00C0281ADULL, 0x3419BE80FC04B603ULL, 
            0x561F3B4C8426D9C2ULL, 0x415BCD402A95C56EULL, 0x54FB89B34EED56D2ULL, 0xC39D209D3FF7E1B1ULL, 
            0xF91D26870CC90837ULL, 0x9B6CF8A41C6AFEABULL, 0xE82590997C58F9CAULL, 0xA96BA6BCF4F5E67DULL, 
            0xAA81801FB1C54706ULL, 0xDEA1BA9766566B89ULL, 0x6DD007619D85644AULL, 0x74AD379F9FC589D2ULL, 
            0x97FE2A54BF6B8A20ULL, 0xC4F556E03F38B646ULL, 0x6DFE824E69E36EEDULL, 0x2AA4E8C47DAA8996ULL, 
            0xC04266214643BAD3ULL, 0xD5041CA884932EF3ULL, 0x0A04411836D75710ULL, 0xC869AD24D1C6A6FCULL
        },
        {
            0x09C28E45B6318A5BULL, 0xAEC0FC96BB27ED66ULL, 0x9F1497DE0DA759C0ULL, 0xB6721DB02A14D742ULL, 
            0x93721C658CAA7118ULL, 0xF7CA1DFC4DDFC346ULL, 0x84DA7C49342420F5ULL, 0x9F686F92D69CB47DULL, 
            0x761A303EA28A031DULL, 0x58B0BC240EABC5C6ULL, 0xE033EA3FA7225B0EULL, 0x7F9F97ACA5E5812EULL, 
            0xC79BAB9BB41A570AULL, 0x44EAC2D1BE6771CDULL, 0xC1FD010CE799AD7CULL, 0xFE42F8A6ACAA69F3ULL, 
            0x5A01A10D2F54DEF0ULL, 0xA510D94D34C1CF04ULL, 0x93CD10E5012D743EULL, 0x59F4E50D379EC40FULL, 
            0x4C0A00495CB73D17ULL, 0x951D4D3E8E2410E5ULL, 0xD97088CA8D7C42CCULL, 0xC52F41F706740666ULL, 
            0xF39FD8C2491E8311ULL, 0xAE99AB6709DF077FULL, 0x7239E440F0C110F4ULL, 0xF215896E06E684BDULL, 
            0x0A1842DA9088779AULL, 0xFBD0F8F923DD569FULL, 0xE36005869AC3E46BULL, 0xEE62DD4676291312ULL
        },
        {
            0x48882F75B276553DULL, 0xD5E3B1FEFD81152FULL, 0x05F3971891CDE193ULL, 0x0429E11A277417D8ULL, 
            0x4478D61478401CE2ULL, 0xB382D8EA99140961ULL, 0x1A57E7ABE8069E4DULL, 0xC1463CFD6BC7DEADULL, 
            0x39F29E4A24428E3CULL, 0x3D8A69A0854AEF71ULL, 0xFA67FD96D4A76501ULL, 0x9C617B7CFEB7CFC3ULL, 
            0x2FE3BA340F0F003CULL, 0x760BCAE977B7E3FDULL, 0x074B82A8CEE6A56AULL, 0x99D85E8F1A5A1FC9ULL, 
            0xECD1DDEB09A7891CULL, 0x767A79A6D9CE871FULL, 0x784FEF541E899E5EULL, 0xEA1FA34A92E5D5E7ULL, 
            0x46E0752D509FE5FEULL, 0x1293B248A197C89DULL, 0x13EF9EEBCA892E38ULL, 0x0BE6FB4E5C671DF8ULL, 
            0x62B601507D832CE4ULL, 0xF7141A0F6516A94DULL, 0x55BB706A8424FB42ULL, 0x49CED0FDD40F4C16ULL, 
            0xDE692B0CD6B3E32BULL, 0x995E40FB463598E2ULL, 0x9BAF82B85587CD6FULL, 0x7715CC1977F8B851ULL
        },
        {
            0x90B6C4D30B9FE478ULL, 0x89EC5E9E65399ECFULL, 0x9AC323D9512AAAE7ULL, 0xA3EF376C76344ECFULL, 
            0x652CE2713843D77CULL, 0xCE1EE1FB11DAA671ULL, 0x256BCAF8B9486E19ULL, 0xB51AB42C5A0C6163ULL, 
            0xEBFF0F743932E17FULL, 0xF4F751B7AEFD6FA3ULL, 0x6E1920A26DCC8B4BULL, 0x4C88EE4D78151225ULL, 
            0xA3D99F9A8ECAFEB4ULL, 0xC23F8DA4E40350F0ULL, 0xE6FDB22A986090D7ULL, 0xC0AB04821C4FDF47ULL, 
            0x30E8AFCF6B5FB508ULL, 0x18C31FB443B68472ULL, 0xEC0DADA146F21004ULL, 0xB89F4D2E65CED476ULL, 
            0xD77DB536126B4E6EULL, 0x0EEB4CF085D6D312ULL, 0xD634A97DF81BBC6FULL, 0xC6ED7AA0B9D176ECULL, 
            0xBF3FA043FDDAF5E8ULL, 0x57A5129DE829254EULL, 0xE4826715E6F1348FULL, 0xAEF3701AAF92019DULL, 
            0xD5BE60A17A978BEEULL, 0xC7B8D0D78E2D93CAULL, 0x2D1E29D6E5E30338ULL, 0x8EEFA3FD1BAAEC95ULL
        },
        {
            0x415D0C1909802025ULL, 0x7E4C94A266790E05ULL, 0x141589AFA35B2796ULL, 0x3772859E5B3EA9F5ULL, 
            0x958DD3FA272EF4E8ULL, 0x032578EE375EABE0ULL, 0x6B3BB8B52FD8686EULL, 0xB65959474FFB4695ULL, 
            0xABB0539574DB4FEBULL, 0xFF121ED292686D50ULL, 0x1B2E6A228883C828ULL, 0x260936E50283CEB0ULL, 
            0xF4963FD267505C59ULL, 0xCB59B06C59A43584ULL, 0xF537C5CD1AA74BDCULL, 0xDA758A25BEB7B6ECULL, 
            0xBFAE5D65BB80C2F2ULL, 0xE675B64A3CADA2E1ULL, 0xFCA3B796E3D1B598ULL, 0x4AE700CEED27914FULL, 
            0x4531DC0DB0654E36ULL, 0xD7044D5B88F66EE3ULL, 0xE0D671B9D904999BULL, 0x978D7C58A5EAB331ULL, 
            0x885754F965D6F209ULL, 0x80CF5C9F1E1915B5ULL, 0x6057508C0D970B42ULL, 0x169D7F38F2F925A4ULL, 
            0x4A75F9C00D7BED70ULL, 0xF9F72A03A4A2BD57ULL, 0x0F77397B1C9A4CEDULL, 0x16FDB822B83D3FA6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseDConstants = {
    0x4A088888EDA7AF44ULL,
    0x5E4A4A113E743F86ULL,
    0x179AE163B47B291EULL,
    0x4A088888EDA7AF44ULL,
    0x5E4A4A113E743F86ULL,
    0x179AE163B47B291EULL,
    0x44F6C24B1058E8BEULL,
    0x37C7AC4D36A24105ULL,
    0x33,
    0x29,
    0x04,
    0x38,
    0xD2,
    0xC7,
    0x29,
    0x60
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseESalts = {
    {
        {
            0xAECADBBD02846049ULL, 0x316ABE391E784F3DULL, 0xB647050F1045D483ULL, 0x9F276B5710E193A2ULL, 
            0x33407608A8BF43A0ULL, 0x27E49A5D59D882AEULL, 0x82995ED805E29B9FULL, 0x25CD2ADC3BC2A89DULL, 
            0x9B63B4C1EA263032ULL, 0xBDE9ADB4648A7C82ULL, 0x89F91D4B5C67422AULL, 0x29071AD040054054ULL, 
            0x75DDAB8FAE3B03D8ULL, 0xEA84EA33525880DFULL, 0x20D1E2E173806FBFULL, 0x1D7AE34AD69CC967ULL, 
            0xB37CA4F2B92DC03FULL, 0x80A607CD50BADA33ULL, 0x51557932F119A468ULL, 0x0A906D7E4A9BB9B2ULL, 
            0x9199FCEA18DD7917ULL, 0xC719789A2D648FD6ULL, 0x89FC04FC97E15A86ULL, 0x58814CCF04E3A57EULL, 
            0xE0258D7382BCE8E1ULL, 0x283956425C26DC79ULL, 0xE4380852932DE79DULL, 0x96B64D909FA14B1EULL, 
            0x5FE9491694557552ULL, 0x3F4E64BBC4B04AD4ULL, 0x51784039A62B336BULL, 0xCB9488FB36FA2A08ULL
        },
        {
            0x6E845B0A8805B5B4ULL, 0xE2B2FCF8E2C49FDAULL, 0x70EE8EF060564E30ULL, 0xB8CC3A96B6E40BFAULL, 
            0x63057662AA1C8B09ULL, 0x56E59258779DECC0ULL, 0x0FBFC909E8D9A0E0ULL, 0x85F92C5ECA1565A7ULL, 
            0xBCF03620C6A27A23ULL, 0x0261DDED480D4328ULL, 0xF1719EA68520DF59ULL, 0xFADECCA48B4D64CBULL, 
            0x330E28D53B0E3E7FULL, 0x849B6CB6B5DEFEA6ULL, 0x2FF8F0A587609FAFULL, 0x5C5E4AB4B48A6EDEULL, 
            0x9AA2BDF0E68D739DULL, 0xC7F948930AE06C4AULL, 0xB8CF08FF017719B2ULL, 0x2F2EDA237A142F68ULL, 
            0x06DA9E365D797093ULL, 0x0C9DA3304BF44078ULL, 0xCA4CCA726FF51D55ULL, 0x1ED9B350FB2733B5ULL, 
            0xAAE89A97B4302E13ULL, 0xF42699781C4F517BULL, 0x9254017DFC426929ULL, 0x2C375F89036FCC6EULL, 
            0x5F9A6B96B7822D9BULL, 0x0FECC2585614274EULL, 0xDE0048FCC503CCD7ULL, 0xBF5C05FF783559C8ULL
        },
        {
            0x8BDCA540AE9CD903ULL, 0xD47414427B8DAF61ULL, 0x000F8379F882218DULL, 0x97588BC6C4D22AA2ULL, 
            0x14F3357CA0861089ULL, 0x02FE08F9122A9D62ULL, 0x728FD5DBA9182CEEULL, 0x8D81D0CC9C28D807ULL, 
            0x7BBD2AC6919DDC60ULL, 0xFCAA9B0FF6CE0BEBULL, 0x515E3E3785712BD0ULL, 0x3ADC35EA595D9CE2ULL, 
            0x81B840554CC0502CULL, 0xBA10503392EFC341ULL, 0x6E3D62DD73051511ULL, 0x2436740AC6CC504CULL, 
            0xDF3D36A1EF5DEA37ULL, 0x8AF777A2FF903AE8ULL, 0x3C20CDD736619C52ULL, 0x381B401071E4E143ULL, 
            0xFFC3A722EBA61208ULL, 0xFF91506599572BD3ULL, 0x264C75CC43C5275CULL, 0x38CD311A6A517EFCULL, 
            0x492C476831600A82ULL, 0x41E1549EE614BFB0ULL, 0x383B90B930B930B7ULL, 0x869CE07E81DBC2FBULL, 
            0xBAB5B5AD9BC7CBBBULL, 0x64AAB4392DAE1199ULL, 0xA098EE57057DD281ULL, 0xCD9E0AFD2FB6511CULL
        },
        {
            0xBA741684D9C6F91EULL, 0x04AE8FD9F07B157AULL, 0xBD4A7D84B877AF73ULL, 0x4B788FFF8CDA219EULL, 
            0x5D015D80DB646085ULL, 0x48F66FC48805D681ULL, 0x4E767238FCCD7D3FULL, 0x7850BCC0CED8680EULL, 
            0x2521EA8EE9C39C36ULL, 0xE92C3B6B8342D00CULL, 0xEC638AAF7C648076ULL, 0x67F2B0383AF7B225ULL, 
            0x320D588553E29D8AULL, 0xA181F728E027650EULL, 0xBF27BD2D727423E3ULL, 0x8CAD31F1D5E95270ULL, 
            0x6DDBAE25C47387EFULL, 0x78B45897FC7E0F1FULL, 0xBE506BD0E152462AULL, 0x2596FB0FE639FDC2ULL, 
            0x1F33847BD2481873ULL, 0x1B89F62B60D830A4ULL, 0x7435AA633C69E03BULL, 0x24772CFE5DBCD6DEULL, 
            0xC944318E927A9F51ULL, 0x69286B3704CE9995ULL, 0x87DC0D14A347A0FFULL, 0xBD672663CCBE4305ULL, 
            0xDC1151DB392193FEULL, 0x126823DFB66B4D32ULL, 0xCF7DC6D343754B1FULL, 0x5CDD0C88223B6882ULL
        },
        {
            0x96CC8E85D19E3236ULL, 0x462905F48AF22B5BULL, 0x40FDDE3D550F1474ULL, 0xD07E6D9FF3F1789DULL, 
            0x3FBA114ECFD1CBACULL, 0x8270865F1BD1C720ULL, 0xF46A04C5DC4477CCULL, 0x7532A66C1A013FE0ULL, 
            0x6C1A1B5AC18FD9F8ULL, 0xD307C7640BCAF630ULL, 0x55006356DA586E43ULL, 0xF94BAE39404BA6BEULL, 
            0x2C644608FD9F4112ULL, 0x902FC79A59A7AF61ULL, 0x87246556A1035EFCULL, 0x823EB9424261BE97ULL, 
            0xE243EF8F53DD4F13ULL, 0xC400FD7D08462D5AULL, 0x7B27F56F97AF8F03ULL, 0xD0A571AB34F053EFULL, 
            0xE3CCF32FCBC0A6E9ULL, 0x25BEA64D030860A6ULL, 0xF1262FBAD107A400ULL, 0x67E857F6C3F09A59ULL, 
            0x9CFEF2597526F517ULL, 0x6AC1303EEAC8048DULL, 0x31B1793589D6E78CULL, 0x01973C5CA3D191A3ULL, 
            0x9707BB7A727786CCULL, 0xC74815D1293548FBULL, 0xF1F9CA4FAF0613ABULL, 0x48C3492A91AECF03ULL
        },
        {
            0xDE06C2E520EFDA98ULL, 0x20DB3C0402D74E26ULL, 0x39A78BACEA7D9AB2ULL, 0x90307C617B75F82BULL, 
            0x5E3470FB5BF42996ULL, 0xD92FD422FAFB74B3ULL, 0x948C74A37911D28EULL, 0x12E8E282CC127F1CULL, 
            0x1FC64D58F6DC0700ULL, 0x4E8D75E722A07525ULL, 0xB08AB087BBC04731ULL, 0xF9054B5F9335E651ULL, 
            0x70C494846D6A3D77ULL, 0xE97B24A4963910A0ULL, 0x9CCD355986701BFFULL, 0x99BA5159ACACE908ULL, 
            0x7CE1540B651C0662ULL, 0xF178BF6FA908B93EULL, 0x37D6608E2CFD9FD9ULL, 0x36A480B194F21911ULL, 
            0x1FAC636E33920D52ULL, 0x8648F2A9B2D2A6A3ULL, 0x4D944920B85BAAFEULL, 0xB324587F961DC192ULL, 
            0x49CED3D83D8D546DULL, 0x78CF44A1FC017DF4ULL, 0xC06A60775B8547BDULL, 0x190667A6C7CC7748ULL, 
            0xCDB56529DE6DB997ULL, 0x227398A8EA6BE382ULL, 0x8714A37697BF7B34ULL, 0xE6F98DCEC2FCD47CULL
        }
    },
    {
        {
            0xCDB7D2E4B1F2F745ULL, 0x17569D3260E1CF74ULL, 0xD5A337851875E28DULL, 0x87C79012A880EC89ULL, 
            0x7D1324466162BD52ULL, 0x720162F983E14085ULL, 0x95CCE76C2B130925ULL, 0x39D93ABA8D85504CULL, 
            0x78E6EBDA2091FCADULL, 0x0A7C738A92B47039ULL, 0xAA8110102404E21EULL, 0xD5D0A17E55804439ULL, 
            0x752C5EB8F762B849ULL, 0x5001240E30B1D268ULL, 0xA5293C84676917F2ULL, 0x00FA3E40E5C1B0C5ULL, 
            0xBF45D0303E8BF2B9ULL, 0x9092832439CC989BULL, 0x78B8C5CED45B21F4ULL, 0xCE104EC78AF615BFULL, 
            0xA94C4CB4075E8044ULL, 0x3A5E8EC54851CA47ULL, 0xD854CADC028F2601ULL, 0x9CB7809CBE6B52A0ULL, 
            0x86A38F3CB3D2953BULL, 0xB940E9AB142E059FULL, 0xD4440EFDE420DFE9ULL, 0x6DDE8E60AFC0BE53ULL, 
            0xE8987CF70145D8C4ULL, 0xCA2BB2E483532F46ULL, 0x39BC2F60084AC858ULL, 0x53B82AC6170D7E14ULL
        },
        {
            0xB5F4FB20683A51F5ULL, 0x9B102B9AE2CEED04ULL, 0x8C4A0836325F2469ULL, 0x2C20E0F84347D772ULL, 
            0x9483AEC4079D09A1ULL, 0x68E7231BE196C878ULL, 0x2C43A0C41D70D535ULL, 0x673E173941001BC5ULL, 
            0x012DA2853E4D27AFULL, 0x10392CC9854128A0ULL, 0xEF01CD60C913C4B1ULL, 0x3981EF8BC66D6266ULL, 
            0x5862EC0ECB698067ULL, 0xF8702FBDFA8CB1BDULL, 0x79AAADD19FA09927ULL, 0xD9E2C5170B78B4C8ULL, 
            0x065938EB8C084507ULL, 0xFED4B1381A9F3CE2ULL, 0x5B505054DC3F6AD4ULL, 0x82D890696BF160F4ULL, 
            0xC6524C846BB6926FULL, 0x0E8DA949526D2DF0ULL, 0xEC9EE0D9623AD13EULL, 0x5D064FA1E1C7703FULL, 
            0x53A64E31A7123602ULL, 0x89C2B4F0AD82132BULL, 0x067A66558CE3B358ULL, 0x5512031BCB38150BULL, 
            0xE5451EE62F379D75ULL, 0xD9947C0BDB4F72A2ULL, 0x5D5DF70685680C7EULL, 0x110643111B53A070ULL
        },
        {
            0x8EEFF30F2AA50A12ULL, 0x2BB12D852D66678CULL, 0xEB510BE1A770F4A9ULL, 0xA35527A1740F4160ULL, 
            0xBAF7052487B95B77ULL, 0x1A2CCE3AAE94B583ULL, 0xB45BD5D2B9C37EA8ULL, 0x7096FC094920B5DBULL, 
            0x91FD600507BC3007ULL, 0xEF7C742ED97B59DDULL, 0xEA83D32A084A8AE3ULL, 0xB17DFF427DA4D615ULL, 
            0x59A268BB7CBF31A2ULL, 0x92A89E6CEE6CFAF4ULL, 0xB5B051FAE344D9F1ULL, 0xCBA12207E63320DAULL, 
            0x2CEEB531B696ED55ULL, 0x96A6F7434AD67900ULL, 0x2A51DB87A88E9D11ULL, 0xF9510D2E98A9421FULL, 
            0x89B887478CCE3029ULL, 0x5120B6290D1AAA09ULL, 0x7136BE6D5D88B671ULL, 0x16DEE7BCC37D7AA9ULL, 
            0xAA7551F21E318F20ULL, 0x1DFE160613821C3EULL, 0xDC38DD299458FBE9ULL, 0x370E1F9407419609ULL, 
            0x6A89D6127D52CC14ULL, 0x1D5BEB463CACAABFULL, 0x425355BC82C5EF8BULL, 0x9849CE2CC6AA95DBULL
        },
        {
            0x838E87596589147DULL, 0xDB6FD33090886295ULL, 0xEA579B9C9551505FULL, 0xCAA40C9E447D72DAULL, 
            0x0A731F73FBBA1614ULL, 0xF6DDF30F287DDC18ULL, 0x05DB2F588C705DCBULL, 0x0CE72CFE4A0C7685ULL, 
            0x9EAAFDC01D0D942AULL, 0xD5D4C5E0E2E84A29ULL, 0xD39603A16612B748ULL, 0xE90BED7A00DE0232ULL, 
            0x5181209E10E59B51ULL, 0xDF69D993BBFF3037ULL, 0x19FE7EB9A2890DD8ULL, 0x4ABB42E1F0E85BCCULL, 
            0x3FF72A962128C2E2ULL, 0xE3E92D78A945D418ULL, 0xF1BDBDD4A6807EB0ULL, 0xA0FCFF524019F3F9ULL, 
            0xF76229392939EA40ULL, 0x4106475861771524ULL, 0x1092DF2AAD7D9DB4ULL, 0xF1450774A3AB45B7ULL, 
            0xFFD86FD4033342A8ULL, 0x4187EA5F15072654ULL, 0xF4F6B4CFBB803E90ULL, 0x00B4DB706EB9425BULL, 
            0xABF79F65FDE80B49ULL, 0x4A768CF64AC75D99ULL, 0x85DE7997D514F016ULL, 0x49124698CABB34F1ULL
        },
        {
            0xB83D2964DD8F50DFULL, 0x2D3DDFA01B9871D1ULL, 0x3004BDAECB4F043FULL, 0xCFFF3DDA0AE444A6ULL, 
            0x69ECCB7BBFF57F89ULL, 0x4B934251926916CDULL, 0x309703EE11A5003BULL, 0x65C7090DD3F58456ULL, 
            0x33ED5EEBB5835233ULL, 0xDC77E03EAC0D21AAULL, 0xD0CD31B4095EEEACULL, 0x413183B0DBD89C27ULL, 
            0xD865F92C102E16A6ULL, 0xC247942245FFFAB3ULL, 0x0654647F7A2744F4ULL, 0x0CF409A1402336E5ULL, 
            0x659FCAAE2C85A3F3ULL, 0x67D8901A4DAFF0DFULL, 0x38F7DB12B1BD5E4CULL, 0xDA7C701A90D2CBADULL, 
            0x792AE2E2B4B0BE8FULL, 0x36F7448FA8F61D37ULL, 0x1FCE442F75194086ULL, 0xD0AB9CF23A3A07ACULL, 
            0x7E64F1393C5671F2ULL, 0x16BF19E3D73D369AULL, 0x6CF14A12243238C9ULL, 0xB481EB64F1FE6996ULL, 
            0x69B2D8D62DAFE1C1ULL, 0x41DFE9A97BF6E996ULL, 0xDCDF53439EA5E4C8ULL, 0x8323E7CAF381A46AULL
        },
        {
            0xD65B0EC8DF881C38ULL, 0xF72C7A1299708082ULL, 0x75A559AE76A2924CULL, 0x5F7BEB2DFA047151ULL, 
            0x75BBC835ACACEE54ULL, 0xD4D8E28577651D26ULL, 0xCBE6152900BD86FBULL, 0x08C41FE63E18984EULL, 
            0xCFF622E232256541ULL, 0x3E88C90AE3F38735ULL, 0x522CB599814EEFC8ULL, 0x3A7CFB5E3D953E34ULL, 
            0xEDF27344DE785D80ULL, 0x8DB29D24D317D907ULL, 0x37548BDD1A388235ULL, 0x7F6CCFEB0AFB40D1ULL, 
            0x18DF96A4FEF94921ULL, 0xFB52A46498AB6BD1ULL, 0xB43116DE7D2804B7ULL, 0x8830C380283E7DF8ULL, 
            0x0805088810645113ULL, 0xCB39866D7B031D7EULL, 0x8A99EC0918963D89ULL, 0x6BD4740BB2B8467FULL, 
            0x594E73627F5150C6ULL, 0xAE9C7BEE9967FA6AULL, 0xB63F94F32920A81AULL, 0x575D7A5533608048ULL, 
            0x388EDFDB8188FD7DULL, 0x355A6005BBE46223ULL, 0xE8BA2F4D3652B4C6ULL, 0xD759E663F32A95F7ULL
        }
    },
    {
        {
            0x73A3C8DF5B21A992ULL, 0x4E2FD71E8CDC3BD6ULL, 0xFDD112FDFA096BD1ULL, 0xA16F6D81919D97CCULL, 
            0xD162E72E6D917634ULL, 0x4861360465C764F8ULL, 0xE075384BFF928CB3ULL, 0xC20B5E5DE8B838DAULL, 
            0x747FEFEA2A45A5DAULL, 0x37DD5679DDC4DABDULL, 0x0D74FEDEEA7E2B15ULL, 0x514E4330C890F1BFULL, 
            0x61CC6F374AA74DF6ULL, 0x1A8EEB1D8D6C466CULL, 0x7836C85028A678FAULL, 0x67D00612E2EEDD2FULL, 
            0x35A33EDE5B23F890ULL, 0xB323546244C235EBULL, 0x2C14EFF10B855DDFULL, 0x0E33B6AEB040D822ULL, 
            0x64EE328A4022534DULL, 0xB3BB0D4BCCEE9BDDULL, 0x2C1ADE61282AC410ULL, 0x118B803E465FB428ULL, 
            0x405D8BD84725D01AULL, 0x787321E0102FB3E1ULL, 0x1861628E0601A7A7ULL, 0x6D49F41FDFD598D0ULL, 
            0xC30D9A9CB8834C24ULL, 0x4A7E98B7A93296F2ULL, 0xDDBAACD6B1A78768ULL, 0x9AF4559F9451DBBFULL
        },
        {
            0xD897D7EF2B53A172ULL, 0x85922D942352F130ULL, 0x3125037A8F591D0DULL, 0xA9DF41822CCAE47EULL, 
            0x8004935682C236FEULL, 0x4C1E744CE4DB2027ULL, 0x4D5C6E0B4EFF66F7ULL, 0x2B9BBD0887BC205EULL, 
            0xC93AA465FCF442B2ULL, 0xAC44A173FC67B342ULL, 0x532D0065EF9CEA05ULL, 0xFD67300FC60D69EDULL, 
            0xFE8D7DB42CF5A8FCULL, 0x893B37837C82A5C8ULL, 0xA9E0C32634017950ULL, 0x81071D8CEFB806F0ULL, 
            0x0D11004EBF718FCDULL, 0x811A7DE7088F66B4ULL, 0x4DEE5282D8A28231ULL, 0x3DD26ACC4CEDDF5CULL, 
            0xE92E68207517B887ULL, 0xCFA71FF73B92AC18ULL, 0x9CCB209189F924E0ULL, 0x0CF58FD24C29EA66ULL, 
            0xE1294EFA41CC19EEULL, 0x260E6029BCDC779CULL, 0x791533F232E19537ULL, 0x96F7B01D921E8FE4ULL, 
            0xFE3B50B92B91A09FULL, 0xB889F8F26C8EF122ULL, 0xF470783C3C897B64ULL, 0xB69F53AA48EFB00CULL
        },
        {
            0x1FC605D760C25C44ULL, 0x2D4D4053CA60DA1EULL, 0xB10F673A9D572BD7ULL, 0x68C894DCFA871AA3ULL, 
            0x787BFB8684A7DDA0ULL, 0x64DDE912FDD5CD98ULL, 0x0F365E5814D50650ULL, 0x2454BCA82117F992ULL, 
            0x980D76D5D6F1BF98ULL, 0x762928CD81A571C8ULL, 0x43193C61D70842FCULL, 0xD44F3C0743711C9AULL, 
            0xB1EA6FF9B267DF56ULL, 0xBE3020402D73A04EULL, 0x58BC38F5B80CED9EULL, 0x90B529946D2F2A92ULL, 
            0x9084F531988D884DULL, 0x7C18F846341FB105ULL, 0xB664EF979529746FULL, 0x218512EA75B557C3ULL, 
            0xB3D7452EAA9709D9ULL, 0x4304403B906BA084ULL, 0x52986673CF6AEC7EULL, 0x4B6BAC218CB6B337ULL, 
            0xAD38F525BE8694FBULL, 0x7AAFDF7A03079FE0ULL, 0x8351A3CBCDA9000DULL, 0xA53EEB02729A9E6FULL, 
            0x35D67A4E7068B244ULL, 0x3AAA756EDB2F27A5ULL, 0xB7BA71005D40D62AULL, 0xC5E5E86A6C87F975ULL
        },
        {
            0x57CAD3EFFC2D647AULL, 0x48834DAA3B88178DULL, 0x85DABC76F95D8AE8ULL, 0xB594FC72DEEBD4BDULL, 
            0x18236A8FA956103BULL, 0xE6C5245DF3B53FEDULL, 0x7EFCEF94AA598959ULL, 0x95E097C590EDDD71ULL, 
            0x0B1C7A4D418E779DULL, 0x326F5312F02F44D5ULL, 0xF1F24B41ED7E1356ULL, 0xD9363825CC4C0BA7ULL, 
            0xD600211070CB69AFULL, 0xA250EC20B947DBBEULL, 0xEF5718DD6A88982EULL, 0xB3E7EA541C179C7AULL, 
            0xCF196FF6E7F12A1DULL, 0x64F02D88A89D1474ULL, 0xEA0C0F9E4284E22BULL, 0x3559C84231DF8448ULL, 
            0x663190A06579B020ULL, 0x9668DDC70398D984ULL, 0x0E6876448E35F81BULL, 0x8A17DF7D72034661ULL, 
            0x6A310DE2A6820D8BULL, 0x11BA99029E576263ULL, 0xFBB23D22A7BE5136ULL, 0x18408C760C39CD3CULL, 
            0xA808124030CB3FC0ULL, 0x0EB8D43992796D31ULL, 0xD3E30F9BD8B3839BULL, 0x3F206E1BDD75C1F5ULL
        },
        {
            0xB541A9F5854240CCULL, 0x8622E4E66E4055EEULL, 0xDBC79FBAB12D27A2ULL, 0x1F2E724CE6F98C16ULL, 
            0xEF35D49BBA6E4C7FULL, 0x0A8BD85374B97733ULL, 0x435F9C02B6AF415BULL, 0x93958E866F7F03CBULL, 
            0x842A4E98F645BF33ULL, 0x40C212123531E23CULL, 0x6CA13DF8E59190C2ULL, 0x97E46C02B6E8120CULL, 
            0x4AE0976ABB8796C0ULL, 0xBDD6CACA3F423CD3ULL, 0x8E05986D49115BFAULL, 0x1F3139D17231ED06ULL, 
            0xE47568DBED661DA3ULL, 0xBAB9252951A2FCB9ULL, 0x73D3C27966A2EF7EULL, 0xD770C6CC422AD294ULL, 
            0x87AB9A8A589F4D0AULL, 0x761EDCEFBA16B329ULL, 0xD2A83AF58C9E78E9ULL, 0x6092ED61694811DFULL, 
            0x1C63A1EA75AF1454ULL, 0xA1AA9F40EB4959F1ULL, 0x816D88E84D9CE4F6ULL, 0x2C15AE41663BCB3EULL, 
            0x1C8DAED490526A03ULL, 0x286C0DD1A484FA15ULL, 0x0567D694964C85D1ULL, 0xB1F9FAA617C5E0A1ULL
        },
        {
            0x54E996418EDEB9DAULL, 0xA8767EF7A4726810ULL, 0xFF654585D01F8CEAULL, 0x31C49022147F46B0ULL, 
            0x1A37F39AB76B1EC7ULL, 0x0C7997ACD3E94F3EULL, 0xF36064A32E397C6FULL, 0x9F3E71599AC08127ULL, 
            0x4131CF99C4F84376ULL, 0xD2A88B62D7B91BA2ULL, 0xE8777607E76CBF05ULL, 0xC45DFFAC1623F8FCULL, 
            0x6A2B762564A12423ULL, 0x9D347694BD06A82AULL, 0xF603D2FF4AC1413FULL, 0x0EC9554CC183CEB4ULL, 
            0xA9EB81752CFB0871ULL, 0xDA70F784A620AE52ULL, 0x168382611F841263ULL, 0x8586986385A54547ULL, 
            0xAC5593AD4858A6B4ULL, 0x9AE8A2D58399DEF3ULL, 0x669EDA01B9C0B5BEULL, 0x293EC07B7D88E5DFULL, 
            0x898A2DD75B573A94ULL, 0xE06E3AE0C4CF9890ULL, 0x91F7C98080950BF0ULL, 0x7E29558A2BC501C7ULL, 
            0x2CA6AA725472A3DCULL, 0x22AADCE6137830BCULL, 0x4443D69D9F969D95ULL, 0x85A64283810CE477ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseEConstants = {
    0x53DFD159811A9A18ULL,
    0xCC21D2B8635247E3ULL,
    0xEED1B85B41E6B810ULL,
    0x53DFD159811A9A18ULL,
    0xCC21D2B8635247E3ULL,
    0xEED1B85B41E6B810ULL,
    0xBDC61B54FEDF5CFBULL,
    0x7A5E2AF028261699ULL,
    0x35,
    0x75,
    0xD1,
    0x57,
    0x73,
    0x3C,
    0x46,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseFSalts = {
    {
        {
            0xCCC2DCD069BA90A8ULL, 0xC344568107D73530ULL, 0xBBCB93E975713671ULL, 0x123DBC916374253FULL, 
            0x4163EA5F846096A3ULL, 0xF53D01CF817498CCULL, 0xAE2DC73BB0692347ULL, 0x8CDD606717093DD4ULL, 
            0x29EEB17580CE30E4ULL, 0xAD112713285354A4ULL, 0x75D15A76D21167E0ULL, 0x854D89A71ACEA63AULL, 
            0x4FEC776CE27BBC3BULL, 0xB52E85D4BDB9F7D1ULL, 0x1E1315089476ABF2ULL, 0x34356D84FCFA3270ULL, 
            0x3EACED3A8C78CCCFULL, 0x08BEDC0E11E71F61ULL, 0x6C36FAF53A6BCB81ULL, 0xFBD17DB309687CF4ULL, 
            0x91AEC144AFDAA4CDULL, 0x98D4C717BEA28DAEULL, 0xA0E6D3ADFE8D6CD3ULL, 0x9231BC4D32E6890DULL, 
            0x5F3DB123733826ADULL, 0x4FA2B5AC2322FE68ULL, 0x10BE7577AC69F35BULL, 0x5AB11512ED51BBD4ULL, 
            0xFA076A63EA80A1D7ULL, 0x18FA17BCC4BD87B5ULL, 0x8BA3B2487BA88CD9ULL, 0xCE489A4A62E39576ULL
        },
        {
            0x7CD915FEBF3B821BULL, 0x897192A3E2E06F6AULL, 0xE9E66639A6A18E3DULL, 0xE53A9FC8AADCAF29ULL, 
            0xAA5BA046979DC321ULL, 0x224EAB912BFD7DA2ULL, 0x965B7ABD17A9EF58ULL, 0xE58030CA99113599ULL, 
            0x75070263F01C05E0ULL, 0x3B677440053B3FEAULL, 0x95228F6B532FF67EULL, 0x86402D994DD22533ULL, 
            0xF7ECAD494BBF28C3ULL, 0xC1C241A81B3BC0AEULL, 0x0B2F2E01C6C958D0ULL, 0x4534AA92DD0D1034ULL, 
            0x7E22A118DB16D522ULL, 0xFCC1A6C98E95112BULL, 0xE885E4AD07E9FEB8ULL, 0xA4E3AE8750352648ULL, 
            0x0830E12B902D4494ULL, 0x5190551BF9A02FF2ULL, 0x14C43625A6B00FC9ULL, 0x366EBDF253002324ULL, 
            0x7C0A12459FDD5D1BULL, 0x2189F150BF45B1ACULL, 0x222CB36C5421D7AEULL, 0x9A11D4CB84D42276ULL, 
            0xA30CB6A6224DBA13ULL, 0x2D73942611257736ULL, 0xB9C0B4E07FC39C0AULL, 0xFACA2BA23DD2E451ULL
        },
        {
            0xBF5E47BE3C2AF728ULL, 0x5BDA0087758D02D0ULL, 0x8FF651ADC3E8ED68ULL, 0x9664F485D7CA5BDDULL, 
            0x9435BD9D51D61913ULL, 0x92CFD0B60E9A92AEULL, 0x972862F045C1E8A4ULL, 0x00EF86105FB5DEEAULL, 
            0x616D79EB9BA6FAABULL, 0x72A208D8335A61B0ULL, 0x113E5493BB7E552DULL, 0x7454C0DAC7025E72ULL, 
            0x8481B9E57C90DE0AULL, 0x652774FC6CCF466EULL, 0xE572610CD1B238BEULL, 0x7855BDC9DF0CBA3EULL, 
            0x7C24DC5EDB6EB7AAULL, 0x3C8CCAAAEACF88B2ULL, 0xD4F7D1B84484B357ULL, 0x10F81701BBEF4E95ULL, 
            0x0A3945BEC54B1A41ULL, 0xF2608ECDDDB49556ULL, 0x9F20B4E73C8A9070ULL, 0x3CD2C5545E86BF1FULL, 
            0xB9DF52E16808EFF0ULL, 0xF3B0BE74F44162BBULL, 0x404A79DF2B4E52F7ULL, 0xE844F56BCD45EC90ULL, 
            0x4F48C1B2D1FC325FULL, 0x078DA48708BC77ECULL, 0xC48BEE5F81C6ACF7ULL, 0x088F818C3D93DEB5ULL
        },
        {
            0x16B8A64E339BD93AULL, 0x3F44D250AA297EB6ULL, 0x85F0B65EBDA1551CULL, 0x4F9ABB5BBDBC30DAULL, 
            0x8D735D3807A3E2AEULL, 0x9DB2F4590C350C4FULL, 0xA5072DAF34CD775EULL, 0xB6E50EB358E08246ULL, 
            0xC8A32E445136D74DULL, 0x793E77AEC8801C06ULL, 0x6F35271064B8B4B8ULL, 0xFDCCA61A42FD3860ULL, 
            0xE0C778B06267AFB6ULL, 0xA71D5207ADD8EE41ULL, 0xF38CC6C1DD9029AFULL, 0x854674D451BA7AEDULL, 
            0x4EE84B493AB8FFFDULL, 0x417C5505D5267FADULL, 0x2624131B4C58B87CULL, 0xAF67E08C0511B227ULL, 
            0xEA887FAC8D2E2E0DULL, 0x93137D9CD66F99CAULL, 0xBB695FD79ED237DDULL, 0xC74A4DECCB0F12B0ULL, 
            0x36A48071FBC2CCA8ULL, 0x669FDC55F244AFE1ULL, 0xE1438BB0C71C19D7ULL, 0xC0DA3C340A80F24AULL, 
            0x6792ED28442E968FULL, 0x7BB51512EC169961ULL, 0x8F1382BBB7EB5516ULL, 0x37B0CB6388D2662FULL
        },
        {
            0x248EC0EAAA9E9DCCULL, 0x62C2AD736EFFC7C7ULL, 0x893FA58334704192ULL, 0xB2E82C85A0D4628BULL, 
            0x0DE2629547E421E0ULL, 0xF3C8CB94B21C967DULL, 0xA7E2C8A67565271DULL, 0xF6E51684769E0322ULL, 
            0x9B2968E5380E207AULL, 0xA2A83183C549F5ADULL, 0x455CC6CD499C8496ULL, 0x7FD12107BF27EC2AULL, 
            0xFFDE88FDA1A978D6ULL, 0x6DE1B4E11F221D4DULL, 0x3128C0AD5DF00F5DULL, 0xDDA55D5F4D36FF7BULL, 
            0xC58C2899CD1CA07AULL, 0x03C1DAB2CDA741E3ULL, 0x114D17B440AF715DULL, 0xFDCB782C42B6EAF2ULL, 
            0x4A891BE1BB644E15ULL, 0x6864EB088540FC2AULL, 0x9AF376D6C5DE1F63ULL, 0xE98891FBC9A844B7ULL, 
            0x4BC51C70211468A2ULL, 0x6DC826F6E1383738ULL, 0x35590E3116016810ULL, 0x7D26CFB2F3FB6B64ULL, 
            0x57DD0F3E59F878C7ULL, 0xD64E8723953B0ECCULL, 0xAFD2855CD955A09AULL, 0x217A16E369F42D2AULL
        },
        {
            0x2AB3CB8DC30C40D2ULL, 0x72B9280C05C33ADDULL, 0x4E03EB9C69768F2CULL, 0xA3A8194FDC4DF0E8ULL, 
            0x18426E025FC183E7ULL, 0x1D4B4310CF823C5AULL, 0x113D1D32927B9F1FULL, 0x383155B011CE9F69ULL, 
            0xB687136F3B75DE7AULL, 0xF11C267F298ED04AULL, 0xE3F1DEFB1A8B811DULL, 0xAEF828705D7F15A5ULL, 
            0x78C648DE12476BF9ULL, 0x11D4BB1B0933020EULL, 0xACC90F82616C09CAULL, 0x3CBC2C8119B4C344ULL, 
            0x62E495B83FD5F753ULL, 0xA740B0B8143A60E5ULL, 0xC98E141C9FCB2BE7ULL, 0x39528BAA599DBFE3ULL, 
            0xE6F30828DF63C4AEULL, 0xCB89DC4FF08E96CEULL, 0x34983214AD606174ULL, 0x3F049E66ED4A6457ULL, 
            0xF944E8B1DC68DC52ULL, 0x9BF994EA066D6FB5ULL, 0x661B1EFF02FA67ACULL, 0xDD1F872A15A88636ULL, 
            0x61B9B180A9EB7D86ULL, 0x09E9139120452543ULL, 0xD3C60249D8C4F5C7ULL, 0x08A4445B05336FD1ULL
        }
    },
    {
        {
            0xA7DAFD60B447DC4FULL, 0xB6229753B04A4878ULL, 0xAD05C3E3AC7E9968ULL, 0x98B5F9AF514DA1D1ULL, 
            0x1DDD230FCFB6C5A0ULL, 0xF2DA111022A386A2ULL, 0x7E585D5A2F7E4A8EULL, 0x7FA1027B19CF478DULL, 
            0xED6036FD27A5A44EULL, 0x046A09A6C870BEA8ULL, 0xCDD01D9900DD5512ULL, 0x569EBCC9F930D63FULL, 
            0x60664F5A2CF4E526ULL, 0x5E7267C3A15CBDE7ULL, 0xAC2A26D740C405A2ULL, 0x6F69D81C2613BC5DULL, 
            0xBD42FB3989490D56ULL, 0x14AB67E5A61FF2C2ULL, 0x691A4233F06DD282ULL, 0x3DAA4F8CAA23E519ULL, 
            0x62BA416909CF6F05ULL, 0xB89232CCAE3C50CDULL, 0xE660846C998C0C18ULL, 0x900A6B65A0173E08ULL, 
            0x74B70C149C2DBA89ULL, 0xF14E8D66B12CA5D9ULL, 0x70D80A3006EF8578ULL, 0x9DAA6D4503F2C053ULL, 
            0x7B50AA1588A21C44ULL, 0x0AC08F82FA159F85ULL, 0xFEE0E79AB5547491ULL, 0x3E16C267B6DD82E3ULL
        },
        {
            0x3EFC30793EA2F495ULL, 0x6E847981E3438208ULL, 0x66589830F4440B84ULL, 0x61DF5D5464DB28B2ULL, 
            0x03532A7656E04737ULL, 0x87CC83C0C847EA85ULL, 0x6ED28EC40822941AULL, 0x9FA3FD44CA148DA8ULL, 
            0xFFE49EC89C324D4DULL, 0xA8099823E5D81636ULL, 0xC3AAD883E80776E2ULL, 0x7FD4EA59C120CFBCULL, 
            0x7FE8D9F1E6AAA0E9ULL, 0x44983B632B8D7A14ULL, 0x022415DBB897F81DULL, 0xD007CF867D8012DEULL, 
            0x9D9C9D1BF03AA78EULL, 0x0F8E308D1A20779EULL, 0xD8EC1652D2D40DCEULL, 0xB37A36F3E3ADB1D7ULL, 
            0x2CEA1A0CAB7B6C94ULL, 0x31FF7C4BAAD5AA90ULL, 0x71BF5B15A508E7B7ULL, 0x3412814A27E1AD58ULL, 
            0x0E584691CE504E2AULL, 0x148A5B7DE565E072ULL, 0x42A5B7B345793FB4ULL, 0x9092F85AB654B4F8ULL, 
            0x6E71627DFB9FF771ULL, 0x4BDB201E86377C49ULL, 0x6D3C8227CF3D5179ULL, 0xB17665F86858D60FULL
        },
        {
            0x6817278F0BBD805DULL, 0x322526443655C335ULL, 0xD1DB4EB4B79060EEULL, 0xC64F3C4306DD491BULL, 
            0x2C4630FADCF9802BULL, 0x3686114E0CABC8B1ULL, 0xDC0059736C5AE341ULL, 0x478350730EF82414ULL, 
            0xE726F0E7C24E9C37ULL, 0x35CE53129A8305C2ULL, 0xC16982ED5F8A9F75ULL, 0x1B524CB335CC8047ULL, 
            0x535B6481F362E10CULL, 0x36EC98C96936C9CAULL, 0xF520CD373996CDA6ULL, 0x616653B7ADBA3A5AULL, 
            0x12FD85D969E6C497ULL, 0x16DBF98B941E3C24ULL, 0x195F170859867447ULL, 0x39C149E6DA90E424ULL, 
            0x5D7530DD3CE03510ULL, 0xB6C68B16276F789EULL, 0x6FF2D8504CA5DB3BULL, 0x3AE84F3BC6FAB61CULL, 
            0x520755EEC12F50BDULL, 0x47931DD40A43DAC0ULL, 0x17DF435E309CCA0BULL, 0xF917754D61DE590BULL, 
            0x426FF7F14D1462BBULL, 0xA5B921E0C70BF76BULL, 0x0C7EE41BCE609463ULL, 0x0CDD99B368CCDA6DULL
        },
        {
            0xF67726B7ACF5FE12ULL, 0xEE3292DD9478F966ULL, 0xCE643DC4E41340B6ULL, 0xC6F7FDC3F06024EEULL, 
            0x8A20C98D0FBCA08FULL, 0x69964B3E85ABD2B9ULL, 0x69A5A39F919CAF04ULL, 0x5E7B9282B49F3FAAULL, 
            0xA94EE2A972136E61ULL, 0x64B81FA5B85E9E85ULL, 0x7EC14DC8FEEEE024ULL, 0xA720629B172DCB7EULL, 
            0x9450EDCC859CD462ULL, 0xCB4AB977EC45F3BEULL, 0xA41C80959E99FDC7ULL, 0xD202F5F12C69F7C8ULL, 
            0xDF68AF0CFE63540FULL, 0xAC59FD36F5901CD3ULL, 0xE5992EDB486E6BBAULL, 0xCD1FFB93E53080EDULL, 
            0xCB0F029E7E30A0A4ULL, 0x6FB29F6040021B71ULL, 0x761615AC7AD8A8D6ULL, 0xD3356842059BFEB7ULL, 
            0x45BA6B5B5F7A22BFULL, 0xDD493163E89BA669ULL, 0x55687905A211F052ULL, 0x1F7126BEC1B88BFEULL, 
            0x3FF594AAD6D42433ULL, 0xC40C7B47D71B30DFULL, 0xB641F1C17FEA3433ULL, 0x1EE1F2BEE0A72DD5ULL
        },
        {
            0x4F8BADC28C61588BULL, 0x1E1B466A238E80DAULL, 0x1C189D07F3404938ULL, 0x28DA33693FAB7842ULL, 
            0x18CD317003B8476AULL, 0xAC7B71CD20632C63ULL, 0xF1706361DCADAA31ULL, 0xDAAC4749B7D566A7ULL, 
            0x6D82E1DDFB714068ULL, 0x08F271EEE8B859BEULL, 0xAF6CB2ED1D49DA35ULL, 0x4C86C7FAF140D87AULL, 
            0x739F3A0DF173D8B8ULL, 0xD42DB10A95FEC7B4ULL, 0x746CD85FE096EADEULL, 0xACBF7B6A29DCF374ULL, 
            0x8083B09733FBFF9CULL, 0x879D4D09A8E51A92ULL, 0x6D21CAC922CA6F6AULL, 0xD78D3341A17CEB64ULL, 
            0x72C0B3BB6FCFA934ULL, 0x7D077256DFBC1BDDULL, 0x4FFD2F5378C9A29FULL, 0x3D98973D37596CC3ULL, 
            0x1434FBD408753BF4ULL, 0x4C070184A1A64058ULL, 0xC31E3E4E72053BD7ULL, 0xB50014DDEF618160ULL, 
            0xB8BAD19867B7F88EULL, 0x12EBE5C02C9F5CE0ULL, 0xD93C6D9A3BA603CEULL, 0x63F3BA87A4159CDFULL
        },
        {
            0x249C9407B3F1CE0CULL, 0xD36A3BC11DA11A52ULL, 0x622510EAD05CA2B7ULL, 0x48BB6BFDF0F9141DULL, 
            0x7DFE715C5DA2ED7CULL, 0xF91F836753748817ULL, 0xC9868F2C5EAE84A8ULL, 0xE6DA4B9AC93EA9B7ULL, 
            0xD8A48EBDA5C51CB0ULL, 0xC524055D1A11E375ULL, 0x8B599C25FF171841ULL, 0x3571D286295F010DULL, 
            0x75B65DFFF57EEBB1ULL, 0x00129945A565C56AULL, 0xBBEBD7B4239FBE60ULL, 0xD98775E3351F5562ULL, 
            0x296EB5C1583BBDD9ULL, 0x234ACEFF6E03D312ULL, 0x3746B7634B9A2F9FULL, 0x85D116CA1A123417ULL, 
            0x2EF5790664B4945BULL, 0xDE18F4AF4D074E95ULL, 0x19D7E6417E3AFEDAULL, 0xE1BD4A8FA71BC001ULL, 
            0xA168914681FB3301ULL, 0xEFCA3E1BBC55037EULL, 0x1D35FBFEC1455AE6ULL, 0x4A5E10B8B56FB264ULL, 
            0x30DE6233BC34F7EDULL, 0x591C5B928C7CA447ULL, 0x36743DF7981F4943ULL, 0x28B738B192D0795EULL
        }
    },
    {
        {
            0x0465D0C12E5CAD61ULL, 0x142373CB1E1C2766ULL, 0xACB476DE95676A66ULL, 0x17CC8801F8DFD9F3ULL, 
            0xD8FE5A17BCB9E361ULL, 0x2FEDE68110CA8BE0ULL, 0x753EDD99EABDA6DBULL, 0x81E8D0DF22CE18F6ULL, 
            0xB0E6970550656212ULL, 0x75A379D7687A9DEBULL, 0x1398D945DB0E55CAULL, 0x29C04EC53FE243CDULL, 
            0xC4C97C67FAE17E67ULL, 0x2656417E638D8507ULL, 0x5BC2CB8927015CA8ULL, 0xC255E6DC371337C5ULL, 
            0xD584C39CE1EA9829ULL, 0x801FBA214BA4CF75ULL, 0xBFA4AC076E834C84ULL, 0xB0BEF8781082DCE1ULL, 
            0xE5DD2E26D8D62B21ULL, 0x12EF3C9AD3F4A8D4ULL, 0x9CB27D3E7A97B410ULL, 0x2E3E1018FEA2BAADULL, 
            0x095D24FC8DBF406FULL, 0x50C86F99DBF9A93EULL, 0x59EE3661000C29A5ULL, 0xCD6C7FEADD122355ULL, 
            0x6A30CFC96A8B5973ULL, 0xA34921EB2EC4870CULL, 0xA422228F46779FABULL, 0xF414390734D93B9CULL
        },
        {
            0x3C7D5D96F46A8E12ULL, 0xF3DA500805CCA357ULL, 0xB590CB049EF2F8A7ULL, 0x0166605398ECE539ULL, 
            0x3A1F52547DAAE818ULL, 0x0791F4342D4B4227ULL, 0xCE8F3F3EEA38B03FULL, 0x54AA1FBFD78BC99BULL, 
            0x7695E1B239113A05ULL, 0x14A23244B7B94BBBULL, 0xFD8F09CCAC01325BULL, 0x10A9045461BFFF21ULL, 
            0x23B977971215ECC3ULL, 0x4B4422E51D4C5513ULL, 0xB59A2DCE598A121DULL, 0x6DDA753E53E87666ULL, 
            0x38C9EAA627D96675ULL, 0x717549264E2E11F3ULL, 0xF4419388FA255CCAULL, 0x8F734AFE9D90B65FULL, 
            0x506057A732F30C3DULL, 0x1B8DFA5588A46209ULL, 0x3734645975FD40A6ULL, 0x43CEC2FA7D3996F3ULL, 
            0xAD86C7B8C6F600C6ULL, 0x74C667EECF77E38EULL, 0x6C597BADF5AB560DULL, 0x33C67DB9A533035CULL, 
            0x7C89879380591BE7ULL, 0x008FCCD9D0988B98ULL, 0x16A2069976671971ULL, 0x98EB51E54D41DFD0ULL
        },
        {
            0xDDFCAA4ACCE1A3AFULL, 0xF718725B869BA5C4ULL, 0x403DF68D518639F1ULL, 0x19981C9001A56A55ULL, 
            0x592B6D15B6910448ULL, 0xAB7450147199FFE8ULL, 0xEEECEA733B3F9806ULL, 0xC3A607BACD426DF8ULL, 
            0xEBC6538D0084EAA1ULL, 0x3E50EE646B58A250ULL, 0x652D253BDC2AB7EAULL, 0x7C9626D8237D1EB4ULL, 
            0x40BD3F14A7035F35ULL, 0x31A622DC1324FB0AULL, 0x9AECB9524BE6EA6AULL, 0xA8D249B9C61652E1ULL, 
            0x6644C3F670311A91ULL, 0x6D8A0812A7F72353ULL, 0x7F4EEB31F1D43487ULL, 0x500177F13ED05962ULL, 
            0x5DA22CDFAA2C7581ULL, 0x7C152E32AB7E67F5ULL, 0xD6C606481A9E45CCULL, 0x1B8847235F58937CULL, 
            0x958594200F0CF96CULL, 0x195BA13B6985A7D9ULL, 0x37CD863AF932F0A1ULL, 0x64A322AA690290FBULL, 
            0x9B12ADEA1AFCD937ULL, 0x872708171087D2F1ULL, 0x4EA222AF6BAFF026ULL, 0x93D2DDD6CA89C18BULL
        },
        {
            0xB5D1EA5023012AEEULL, 0x65FF6759C98EA65DULL, 0x8C8A5147065DB5CFULL, 0x8B6D7DB714660849ULL, 
            0x8EF6CB0F039E307BULL, 0x4AB102818F4176DEULL, 0xA0AF1CE14AB6A7E9ULL, 0xFAED31D022400DC9ULL, 
            0xAA019E6C6ACE091DULL, 0xFAD75CCF57F01CA2ULL, 0x56F5120F3CE0D9DEULL, 0xE942B0AF1B6C4D40ULL, 
            0x78696F3C607196BEULL, 0xCEE1CDA43A777729ULL, 0xC1577C9D4C9D4D08ULL, 0x7409B04B142B9172ULL, 
            0xDEE7C51CFFB8F6DCULL, 0xA5E67050A344EC54ULL, 0xB8405DA11472A5BDULL, 0xCFA8BAD87C41F116ULL, 
            0x2F31FCBBE673353CULL, 0x97099CF8083B2BAAULL, 0x4291A459DC348BEBULL, 0x9902C6C094268BF9ULL, 
            0x8E51CDABE8DB7358ULL, 0xBB3EAE68744245B2ULL, 0x056C0E16F0E0A73DULL, 0xB5C76DA6EEB24ED3ULL, 
            0x8B167808E991E277ULL, 0x03265B57B402CEA9ULL, 0x180D49C38539F245ULL, 0x23D2651F6B7AED86ULL
        },
        {
            0x12DC1CC09707D66CULL, 0x19E9EA517833F849ULL, 0x2598CC0B22D6CFB7ULL, 0x43EF851943A5738CULL, 
            0x9AEA1930B97745CEULL, 0x33DF6B33FABB775BULL, 0xA8F5F03CE27E34F7ULL, 0x12269B77863BBD67ULL, 
            0x18AE0C408CEE1D61ULL, 0x6FB057EB6FA38494ULL, 0x1B0D303FA50E30BFULL, 0xEC636708CA974E51ULL, 
            0x9AE87A1954ED2A8BULL, 0x3F04FBE8DAFA804CULL, 0xABBF41F54E84EF57ULL, 0x3284DAA1CE570FDBULL, 
            0x4C94238A7C1882E7ULL, 0xF1DA09EEA414623CULL, 0xB930572EC101ABC0ULL, 0x54493BAAD338C3CCULL, 
            0x77F7EEC5C6FDD6FFULL, 0x39E8D41895EEF0F3ULL, 0x08E687BE0215CBBFULL, 0xE4400AA22B33C373ULL, 
            0xE4F256939D4B70F9ULL, 0x7CD030013985CE77ULL, 0x1F50B308192F2570ULL, 0x729EA398D30C95BBULL, 
            0xAE1D83C1DAB16795ULL, 0xE5FD511A879C5829ULL, 0x1A83FA0CE224840FULL, 0x9C8400D4618E54F4ULL
        },
        {
            0x3258586E7DD9C8ABULL, 0x51B1A34A16176BA7ULL, 0xA6B9AD578D5B58C3ULL, 0x5B1EC47F7153362FULL, 
            0x181D9C0068C5A06CULL, 0xA8B5E564675D5DCCULL, 0x9A6156ED1EAE7569ULL, 0x78A404116AD50824ULL, 
            0x41F20D03BE0D59C1ULL, 0xB5716CA4C32D6CCBULL, 0x8F36A5164497228AULL, 0xDE60E768DA7AE30CULL, 
            0x1C95F5E07D3BA55EULL, 0x03A0172A9879C78BULL, 0xF40A82ABF3082D0EULL, 0xF3259F7E84762D9FULL, 
            0xE5A4D58F25856C3CULL, 0xD2EAC48A3BA06602ULL, 0x402755BB270E2DEFULL, 0x6D87638AA3D1B2E3ULL, 
            0xD1F34E0CC9D89E94ULL, 0x09227912639F7939ULL, 0x3EBC01132D632D59ULL, 0x5BC8E39648899B01ULL, 
            0x5F8074E068A79899ULL, 0x6B0A04BF5AB27D05ULL, 0x0D2F57CE6690A988ULL, 0xF51254FCFBE74F02ULL, 
            0x49833056ECDC8ABBULL, 0xFF3595004609FE47ULL, 0x7A8C0E65D69CD7DCULL, 0x050AB1F35B4334A7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseFConstants = {
    0x1DC7EDF5E834B574ULL,
    0x425943A831124499ULL,
    0x28E4BE9A924FD10BULL,
    0x1DC7EDF5E834B574ULL,
    0x425943A831124499ULL,
    0x28E4BE9A924FD10BULL,
    0x2861156598FF4E1CULL,
    0x65037A6F3CF37B96ULL,
    0xB5,
    0xB2,
    0x0B,
    0x74,
    0x31,
    0x03,
    0xD9,
    0xF7
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseGSalts = {
    {
        {
            0x9ABB2B9F728F3B5FULL, 0x55A4585C1400E44FULL, 0xD182D63838E4A0F9ULL, 0xE5D0595C4FAB554AULL, 
            0x5631D9A63BAF5884ULL, 0xD1F9FD4D0D945CEAULL, 0x49A79CE1E562522CULL, 0xF3EE314A5A0D521FULL, 
            0x002AECC3D1E72683ULL, 0x38096811B4FE1F91ULL, 0xFA55D9016B172794ULL, 0x63B2F8C732502CE1ULL, 
            0xD1E78B0A23DB8436ULL, 0x02822FBC4B417D00ULL, 0xB7F4BB0F54EB1958ULL, 0x968F67D053535633ULL, 
            0x0B0639673D32C523ULL, 0xDE57D975F646EDBAULL, 0x85D2C7B610B2B3EEULL, 0xF21A9DF49967C19DULL, 
            0xAAC0A34BECE1F032ULL, 0x1D22602E1598DFB7ULL, 0x114B81004F408618ULL, 0xA66D9FD0B5724CD5ULL, 
            0xE6813F647DDCED53ULL, 0xCA10B31A5163210CULL, 0xF022F62118A956DFULL, 0xEE13FED73458F33EULL, 
            0x249B7AD34FF14A93ULL, 0xF47802C5137EE478ULL, 0x482BA807A987BED5ULL, 0x08B6E7971C1AFD6BULL
        },
        {
            0x8D4BE905E9F096F0ULL, 0x03FE45BB17854600ULL, 0x11BFCFAA7514D952ULL, 0x81058738ED305ECAULL, 
            0x42B9C5ED3F422B93ULL, 0xE340395C6E4FFA7EULL, 0xB04156930791CCA0ULL, 0x55E779866B0E225DULL, 
            0x74BA3AF1E1A7078CULL, 0x72CC851E8AABDB98ULL, 0x193231F27E519AB2ULL, 0xE63CE09A29F3C154ULL, 
            0x62C2D4A13EFAA008ULL, 0x797FCB5FCBD910B3ULL, 0xB90D8D33A3B99986ULL, 0x7C090100C4A87F1EULL, 
            0x4FD37B26227D1945ULL, 0x598D89039A93981BULL, 0x4F3F85CA12E4DACAULL, 0x0716E090A10CD47CULL, 
            0x1C229580AAC54A74ULL, 0x3CEB19AA4B336E0BULL, 0x47479BB315791D70ULL, 0x0E81BAF6C0ED600EULL, 
            0x01A3845382A59619ULL, 0x0520C5F373866E4BULL, 0xC2FF790403CEE26DULL, 0x0030311A6032E3BAULL, 
            0x1F1C2B058E898E13ULL, 0xF978973FC1F85CEAULL, 0x97635342F05FF9FFULL, 0xF622795C25E4CC67ULL
        },
        {
            0x687EBCC52A657137ULL, 0x7BD4684D82627FF0ULL, 0x16DC4CB5B2E6C048ULL, 0x170D0A2B6CDBBFBCULL, 
            0xD6F608541EDB2480ULL, 0x2F6A82D97EFED5A5ULL, 0xA0788F75AE58D60AULL, 0x8D3C02BFCEF44074ULL, 
            0x212F5AAD5A05AD93ULL, 0x399BA2B2D2BD9CEFULL, 0xC05A5949735B25A1ULL, 0xFB13720FCA93F504ULL, 
            0x25F1445A29440671ULL, 0xDDD638D8786EE6EBULL, 0x65134CEB71106750ULL, 0x7F0692373561C7D2ULL, 
            0x9390503B2DDF0F82ULL, 0xF7D15FF2F6B3DD4BULL, 0x167C4B5CCB78E751ULL, 0x5D1EDA9BCCCE9907ULL, 
            0xF6B62E141A1D8672ULL, 0x8134963AF4C288A4ULL, 0xFABE3607C5B7EA9FULL, 0x9D2FA71E642B48BAULL, 
            0x31422FC4AE61D561ULL, 0x09B0742EF462E338ULL, 0xFA87DB0794848E48ULL, 0xC09443C8BAA9E823ULL, 
            0xA6C1094481B7C8E9ULL, 0x62FED5F8395D6EBAULL, 0x5A4E9B0956B3738BULL, 0x74A7106BEFD28B4EULL
        },
        {
            0xEDA1B3120CA0A44DULL, 0xE044A3E0375F7DCBULL, 0x8CEDA77F05D7F594ULL, 0xFD6ECEC9D781EB24ULL, 
            0xD5EF27AB099D61CAULL, 0xA0A37602812EDAF1ULL, 0x8E5EBDFE1B0935AAULL, 0x9C76315920D743C8ULL, 
            0xEBEA9BF456223435ULL, 0x0DD29120ED12E4C4ULL, 0x788DBEFEFED83965ULL, 0xCAF0ABA56F1A9108ULL, 
            0x7535D7E89960124AULL, 0xDA4310B811E35E3DULL, 0xC18D45449AC4B196ULL, 0xE630E888F14042AAULL, 
            0x3C3C57E805993296ULL, 0x82226F5567429BD9ULL, 0x25DB1AD8AF3C6C00ULL, 0x62A26D87B46D30BEULL, 
            0x816A4593BD2C04C9ULL, 0x6785F49A06D9F074ULL, 0x1DC17476DE4C5B92ULL, 0x0684422255FEF5F7ULL, 
            0xE7A17A45C749254AULL, 0x200A139ABE9BDEC4ULL, 0xF7138A822D6BCA81ULL, 0x651A1A7F212C5C63ULL, 
            0x5A318DA1438C9849ULL, 0x8A7B5AC4B7B3DEE4ULL, 0x144E53C62C6FA0A4ULL, 0xF4AC794348F8AE36ULL
        },
        {
            0x378D623CFAD81F2EULL, 0x61FFE3EC494760F3ULL, 0xB52AC708DD3BA68FULL, 0x86BDBDBC11DDC398ULL, 
            0xE91246451141A53CULL, 0x57774E2A86277E9CULL, 0x29F5290C6A061706ULL, 0x06AD4BA80FC6A9C6ULL, 
            0x2685F32591A82623ULL, 0xE0C43D36AA1958D2ULL, 0x4BFE5F9E5D115878ULL, 0x6734EF968FE9385AULL, 
            0x662A3E93ECC6C14BULL, 0x5959FBC33D9CEBC6ULL, 0xBB072DFDD16AC5F3ULL, 0xC9E52F0932361B49ULL, 
            0x53DD72B26597881BULL, 0x64CD83CF90E69DB7ULL, 0x882A7AC0AD747631ULL, 0xD87E9B1AD6A097DBULL, 
            0x9D8BF9E9BCDC589AULL, 0x475BF452DED8E0B8ULL, 0xA99A147DDFF8FAB5ULL, 0x912079C30AE9BB62ULL, 
            0x37A276183F168B5AULL, 0xCDC2DFAB01DA949BULL, 0xAAF9C030B73C1B83ULL, 0x171A98264D62FA4FULL, 
            0x63A2F1FDB78D557AULL, 0xD42BACC2D370A09EULL, 0x6ECAE81D67A5D1A4ULL, 0x343E3C90C287CEEDULL
        },
        {
            0x6E0CFC55A7723808ULL, 0x241F08246DACF8E7ULL, 0x7E4BDB00C2061747ULL, 0x4A1967E3319E6FB2ULL, 
            0x7539FCAB3B2CEFBDULL, 0xA4970A53161DD256ULL, 0xA43BA21D75680E2DULL, 0xCE8179D358642E78ULL, 
            0x0DF74A5220C05114ULL, 0xFDB8F03D99CA5141ULL, 0x2A489799AFCBE1C1ULL, 0xCD4195C7C0ECA7B2ULL, 
            0xB91906A42E221687ULL, 0x75C6B324CFF14CD9ULL, 0x24EB21E112C45814ULL, 0xFF495D39550162A0ULL, 
            0xB6A7BFDB0581B026ULL, 0x7B1D28252741846BULL, 0xA3B51FA00B941A76ULL, 0xB1B36CB930E503C3ULL, 
            0xD1E594EF0495FA13ULL, 0xC49E74A2AEC38C9FULL, 0x6764544F14D60B5FULL, 0x20F481052D41E59FULL, 
            0x673A5955F5F2BF72ULL, 0x51266ECA4B174D44ULL, 0xFA065AED33D9168BULL, 0x207E5120A91EDF95ULL, 
            0x03EAE34AF414CCD3ULL, 0x0301B726660DB93EULL, 0x08062CCE8018EBCFULL, 0xC0DB79393870EA7EULL
        }
    },
    {
        {
            0x115ABEC9470DB879ULL, 0x9EDFA724BD01B5C9ULL, 0x9AEFADDA77AEBFE8ULL, 0xA8214E6E8222CB66ULL, 
            0x0666ACC7ED2DB3AFULL, 0xA3987C51EE9D8F76ULL, 0xEB83B486711A8BEDULL, 0xF4CECDF3F9EF5C88ULL, 
            0x851F0C8EF4929552ULL, 0x20E87CF00E9B2E3FULL, 0x974D654BDA4048F4ULL, 0xF0A5C1013C516FB3ULL, 
            0x79939C3FA59DBF8FULL, 0x4FEDA75DB45A9FB7ULL, 0xD9C34685EC33AE5BULL, 0x3B50ED1C0B74455CULL, 
            0x1BC20C9AC6EB04B5ULL, 0xDDB0C593BBAD1EBCULL, 0x4B89CE7CC4A65047ULL, 0x17C4594E52DD7AA0ULL, 
            0x8B7B212A816F4EC0ULL, 0x0E14877C60D75225ULL, 0x53E1CB99DE8D7F44ULL, 0xA381B882940A20F1ULL, 
            0xAB5562B8CB424961ULL, 0x19EDBF23E89B80B1ULL, 0x6B20711D63D40317ULL, 0x7CD31CEA482376DAULL, 
            0x882DDC1ED023A34CULL, 0x592716D461A0A593ULL, 0xC4E6F8D2EC55F112ULL, 0x35408AE92401BFE8ULL
        },
        {
            0x5C2DDFAF3AAC9AE3ULL, 0xBFBFA2DE1A7B6658ULL, 0x0953DEA5B9C6C158ULL, 0xFC09ABB6A804EB9BULL, 
            0xF0F017EC40AAC042ULL, 0x9AB23B019DAA5DFBULL, 0x120E0233A5E5475FULL, 0xD61D8715B2CF99A0ULL, 
            0x98BD38A5CA65512BULL, 0x4CB16C08EDD29EA3ULL, 0xFF7EE1F2EF39B469ULL, 0x9A47873881C17EF2ULL, 
            0x77D13BF5732EB9A6ULL, 0x7B8DE344A83926B1ULL, 0xD87EEBAFFA07E0C7ULL, 0x9B0DED67504A736CULL, 
            0xF09BCC5DC678E779ULL, 0x8E6949133BBCD5D3ULL, 0x8B4AA6DD22016003ULL, 0x7272F4C226F43B5FULL, 
            0x6FEE4332BB031BCCULL, 0x01AFE496FAE621E4ULL, 0x72F52BCA1BF7955BULL, 0xF2E992BB7E84AD72ULL, 
            0x45DA4F4FA41BA03EULL, 0xD8E7BD919A912C02ULL, 0x3172D9E092F4B6C7ULL, 0xF90351850067E20CULL, 
            0x76D77189E77B8623ULL, 0x7D4E92E7F57312B1ULL, 0x42F41263EB56C56EULL, 0x56F561E105C36ED5ULL
        },
        {
            0xCFCDDE34F6BE293BULL, 0x6BC03C54C1A74DD6ULL, 0x7A68D489B2BADA64ULL, 0xB371B0B661EBE881ULL, 
            0x486FA1F0F8C6619EULL, 0x9F7C2346E24D713BULL, 0x6D629581CE512D61ULL, 0x86579D3051976981ULL, 
            0x44DAFDAC4403F20EULL, 0x649250506CF32F89ULL, 0x566DC909897364DEULL, 0xF5D5B169612B994CULL, 
            0x547708658CDEC750ULL, 0x180FF378B7F6FFB6ULL, 0x1F41C2CF36D5A1CDULL, 0xBD79C480BAC7FC5AULL, 
            0x5C2CE4062D4B6A40ULL, 0x2050010E7E01574BULL, 0xEDCE9C544C5823DAULL, 0xEFC00B26B37E7963ULL, 
            0xDE0E6DD927595435ULL, 0xF39F5F826EB27BEEULL, 0x900594E6E7A343DDULL, 0xA3D23A4772E6C819ULL, 
            0xB8E03393DD13100BULL, 0x74D5F7FB02BFA99FULL, 0x60061372AA974003ULL, 0x3B175F07091553C9ULL, 
            0x80D9CB8C2E0B6AFAULL, 0x0134D52B543D305AULL, 0x777E1C12FCF57930ULL, 0xEFD4814EE71231CBULL
        },
        {
            0x3F07D8ADBCF39D0DULL, 0x5F69AC6AA9677CF0ULL, 0x08345FC1E79E81D1ULL, 0x461653FFFEF53971ULL, 
            0x67457D06BB6291A1ULL, 0x5A6EC6F13E3FB672ULL, 0x7A39E5818D3D9368ULL, 0x6BF55B3E2513A9E9ULL, 
            0x907216148765C0FAULL, 0xFE122B882217C22AULL, 0x32BBED4BF6D2F666ULL, 0x126D55F022F26191ULL, 
            0x7E350ACF129CB477ULL, 0x2AA26CC9FFB0DDDAULL, 0xB5762217887809AEULL, 0xE30216363A1F9612ULL, 
            0x6182A353A9B249B5ULL, 0xBFC0CE2109A78F62ULL, 0x2EB91CA450C709A2ULL, 0xC5535124F536BCCCULL, 
            0xD6CC392A120E944EULL, 0xAB3FDBB421B39772ULL, 0xCF44C6EA6E7863B9ULL, 0x87D32FE29C870962ULL, 
            0x6121E8F69B7AACD4ULL, 0x4D05FD78CE84A363ULL, 0x895CE5AD6928DDB7ULL, 0x07AE16D64AFAED3CULL, 
            0xD5651A76CEFE1EA8ULL, 0xE73D98969278780CULL, 0x8A9716B1D7B68484ULL, 0x96C22FE63F9F5D88ULL
        },
        {
            0x75FF528E4803B4BEULL, 0xFC20F7FC3DAF083AULL, 0x82C657E643F6151CULL, 0xE817335BDCD7694BULL, 
            0x16EA51DD4A59FEA1ULL, 0x7162F90F647A3880ULL, 0x2008BC341ECCFEDFULL, 0xEB002BC4DFF6F734ULL, 
            0x28AC54C99AEF768EULL, 0xEFB78194244D27E1ULL, 0xEF07D3132A26C079ULL, 0xD326839394D66879ULL, 
            0xE71841EA0BC31E37ULL, 0x161756803F5C32DFULL, 0xA4F173B23E897384ULL, 0x05EE3933B36F046FULL, 
            0x137EC588F32B394DULL, 0xA6B6AC20DC2BACE6ULL, 0x06640947D62BF71AULL, 0x14ED14C9439A5AF1ULL, 
            0x937A335530040129ULL, 0x19176C0BC41C49FEULL, 0x1DA99FEB977BBC75ULL, 0x9AAB3EB4E8D1B205ULL, 
            0xB804C174D238A401ULL, 0x6713D964533A7EC0ULL, 0xC38D460916977A72ULL, 0x58F0CBB6DF519D97ULL, 
            0x51E7EABF313DF3E8ULL, 0xEC4F9A51366B9E74ULL, 0x928651B5F3E7ADDDULL, 0xB18325DD8E914A42ULL
        },
        {
            0x2E968DB760FE85DCULL, 0x3416BEF89BB47E8AULL, 0x816D053F704A0DFDULL, 0x19F2C69F1AF4B1E3ULL, 
            0x6B4F00880B81A71CULL, 0xF9B73B475AE0C878ULL, 0x382040B5036280BFULL, 0x00525CE7F8F9B169ULL, 
            0x7342BD937235FD77ULL, 0xE50746B2AF723BEEULL, 0x6832A36B8297A785ULL, 0x366C10DC0123AEEAULL, 
            0x95DDFBC6F8A5608AULL, 0x25E2FD254DAA0D53ULL, 0xED1DBFD80F30C3DFULL, 0xE4097194300A5FB3ULL, 
            0x9D20EC2C9766521DULL, 0x83088FC82A5ACE3DULL, 0x3CE396ACC2D63CD4ULL, 0x5628A95AD4476AA4ULL, 
            0xF8F902ABDF9D059EULL, 0xFE26FD8BCA6EC5E2ULL, 0x9B1AD426D35596C1ULL, 0xF64497EE17DF85A3ULL, 
            0x2755BC28D35DD4B6ULL, 0xD5D2235F47DF4EB4ULL, 0xF140EA046ACFB8B3ULL, 0xF1C573DDE028C033ULL, 
            0x0CD21C4FF7DE9349ULL, 0xB2669311A22E4230ULL, 0x9D2EBCD36FB7E9C8ULL, 0x01CC3CF3B1456532ULL
        }
    },
    {
        {
            0xD0646B56EF1F75FAULL, 0x8FE65115B133D05DULL, 0x9C869608EAEA7CE3ULL, 0x6F5A5661B80301BEULL, 
            0xE270B1C3E0EE0D0BULL, 0xCD85EDCAF8E756F9ULL, 0x442F72DD69EF5668ULL, 0x3E3099E65B73023CULL, 
            0x508FE1AE9CFF227EULL, 0xBAF36490ADCE8A7EULL, 0xDAA9B40CD154E63FULL, 0xFC9B5C18E4333527ULL, 
            0xF330F9232F214819ULL, 0xD59C2E48ACE53F7FULL, 0xA81E4D2F054839F3ULL, 0x1BD0AE28F1114B6DULL, 
            0xE255FDEB551A0062ULL, 0x6B869CB590BDFA06ULL, 0x29593286CBCF0439ULL, 0x9299B8A0164AE053ULL, 
            0x0CB0E47F8582713CULL, 0xDE0F1C5AA627D0A3ULL, 0x388F257A46140E86ULL, 0x175EFFB154AC19B4ULL, 
            0x7F5AD7468287FEE7ULL, 0x959096672DF5C4F0ULL, 0x37B5ECEB7CFCA333ULL, 0x4EF08633B577DA30ULL, 
            0x341D516D5A52B321ULL, 0x09A2C321A9C8903DULL, 0xC4C6DAC23F8D4865ULL, 0x8F33816CCA4E381BULL
        },
        {
            0xB068B58CF05F5EDAULL, 0x295C09C0A469D63AULL, 0xA6095845826B904AULL, 0x5566B48544407411ULL, 
            0xD53170F1E6379B8FULL, 0xC88300C76BA9DDE9ULL, 0xDD807D2E3D95EE98ULL, 0x972C9C5D31FBC626ULL, 
            0xD61D0001D51A29AFULL, 0xDC9AE7994F854839ULL, 0x99A2A8C4CAAE2984ULL, 0x0AFFB185A9ED4E35ULL, 
            0x2967E73729D69501ULL, 0x348CDB48656782D1ULL, 0x0BA5FCFD8EF27F04ULL, 0x14F59DF8EE6EC1BAULL, 
            0x8BC585E7F8CF68A9ULL, 0xE6DE589B31CBAF4AULL, 0xACF3A9559DC1C6F9ULL, 0x456498B8AAEA36B4ULL, 
            0x3E338CB8358D2EF0ULL, 0x4CDBB4C0DBBD6D0FULL, 0xB323D71B067FDAC9ULL, 0x4D7A6EE5EF8883FFULL, 
            0x1D8526C2F87567F2ULL, 0x109B9411D7C78CCAULL, 0xC31456656508FF4EULL, 0xF017B1924184BD8DULL, 
            0x57E1DD0919F018EFULL, 0x97144DA9CDE8FF9FULL, 0x40108A7CA732ED8BULL, 0x96322CE76CD43E5FULL
        },
        {
            0x4F682B2AA5CF2BE9ULL, 0xEABD4E5544EB306FULL, 0xE23621E25F22FE16ULL, 0x7F29EF2C706A62D1ULL, 
            0x59ABBAF91A8BFAE2ULL, 0x95D202EF424B2CFDULL, 0x444928375A7C51F0ULL, 0x3B68E86D5262F10AULL, 
            0x50ED411252A940C5ULL, 0x280F3CB692DE5C7BULL, 0x598549A3EDD09185ULL, 0x56B40BBEB0BED2C6ULL, 
            0x3E26A6013997D466ULL, 0xDA0669F7DE98A911ULL, 0x4BADBF2EC81CE288ULL, 0x31FA5A5E88F34C60ULL, 
            0x4939DAA19ED557D6ULL, 0x2A0C175C2BADF5FCULL, 0xB65FAA12729F0298ULL, 0x652418A2A5C03B6FULL, 
            0xD2C067413595BE9BULL, 0x2565962B49077091ULL, 0x7AD38E8B284FEAE6ULL, 0x5D5DE73B85FE4F37ULL, 
            0xEFC8E78EA6117D32ULL, 0x19F32E7033245FA8ULL, 0x38CED687579E8416ULL, 0x30316D02CDDB2EE6ULL, 
            0xC6711CE2F1F7B445ULL, 0x37ED1C5120171D20ULL, 0xF7277E502ED24899ULL, 0x5741F1B6535587EAULL
        },
        {
            0x05D7AEFD7309730DULL, 0xC589B895F2FDD764ULL, 0x300F66F1DF940049ULL, 0x583300A825AB4686ULL, 
            0x4CC5DF01FB28FF76ULL, 0xBC219EA95B5F0BAEULL, 0xDB5A6F213561C4A9ULL, 0xA745AA984F46A1BBULL, 
            0x70BDE835F2137F96ULL, 0x1041BF2009AAFF6DULL, 0x46428C1601A71FB3ULL, 0xFBBE46CFD7C0D169ULL, 
            0x7BD22233BED787FFULL, 0xD2A0B892666356BAULL, 0x35CF2A98E54D1FECULL, 0x9DD984DA5915C72DULL, 
            0x574CF8A2F26BF505ULL, 0x0C87482E883AB2CEULL, 0xB9AA301BA6CD61BFULL, 0xEAF236F8A3D6A7B1ULL, 
            0x51AC2DB881922BA4ULL, 0x4C13A7D0EEFB2396ULL, 0xDEBFCB79E6110DBFULL, 0x165791F19A300A30ULL, 
            0x16CFB9AA6124B476ULL, 0x911E6E5FE0CE0EB8ULL, 0x5385FA4F0543539CULL, 0xDDA5004CDED6CF82ULL, 
            0x2799E996384ECD6CULL, 0xF72882D75CED9E4CULL, 0x9E365ECC8B6C59F3ULL, 0xA8639BEE143EABFAULL
        },
        {
            0xC708A4FC830E8039ULL, 0x840B22CC1B584187ULL, 0xD16F6C518A10DBBEULL, 0x95C366005330CBFAULL, 
            0xA92BAA9A9ED7A7ABULL, 0x2D242C513B22384EULL, 0xEF4C9D3A2D6CB4DAULL, 0x90C0D37F6BFD5586ULL, 
            0x5AE0998043A1620DULL, 0x65941E8B67C94EA1ULL, 0x6C0F9D84EC6B4FBAULL, 0x90E139CA0C1FFFAAULL, 
            0xF71FF4AD71450D51ULL, 0x3FB8D9BCE5750A71ULL, 0x2B842E6D4047C6DEULL, 0x6507B1ED64E0F5DAULL, 
            0xD99648876BF9BF52ULL, 0x41D20BE4BBC13389ULL, 0x46B37C9131D29AACULL, 0xD1CDB8BC1B86BC16ULL, 
            0x01F13C37255BCB02ULL, 0x753F93714232FA2CULL, 0x635CED910A3D432EULL, 0xC12C7DF982B718A0ULL, 
            0xF26E0E17277B8C4EULL, 0xE236ECE25D90A987ULL, 0x3A16C1CFC8C18A9FULL, 0x5D16C6D7EDEBA02CULL, 
            0x992D0DE17C6802A3ULL, 0x56B5273592D1793DULL, 0x599FA7760B0BFA8AULL, 0x197D512AFEB4BDDDULL
        },
        {
            0xD7DB8E289C045186ULL, 0x6197E36BB5CAF657ULL, 0x2237F6AFAFF6EAF9ULL, 0xD75D6FB2F939EDF4ULL, 
            0x1F6A252D2A380B81ULL, 0x8107D8036818E859ULL, 0xDA684CCDFE82510BULL, 0x2F8CE641114A456BULL, 
            0x5AA7DF4C8908DF93ULL, 0xFBCE4E7794725791ULL, 0x6BAF45585103725BULL, 0x7409983765FD6EFFULL, 
            0x4DA64505439DBEB8ULL, 0x4C5E608D15387F7DULL, 0xD75C7412678E3B9EULL, 0x0DA466FA661B01F3ULL, 
            0xA39FE981BFA3CF90ULL, 0x99009C99640B1275ULL, 0xE44F68AED5820234ULL, 0x8DD2ACD3C191A6BFULL, 
            0xCF775BA4FC8A4D3DULL, 0x29D53087554C2289ULL, 0x629598D6A9DEC718ULL, 0xC612855D63ECA9BFULL, 
            0xB86073D7497A6F45ULL, 0x5E1F3C61B89CFB01ULL, 0x78B5DB649C262E2AULL, 0x3CFE2FA0583DE593ULL, 
            0xB702B24A9C59458BULL, 0x22887B35ED1E381CULL, 0x20E2A472411C5165ULL, 0xD0902A2892CB73A5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseGConstants = {
    0xAA32DAB55F6ACB81ULL,
    0xF638CFC58B7193F5ULL,
    0xE488B3EDCFC45D9BULL,
    0xAA32DAB55F6ACB81ULL,
    0xF638CFC58B7193F5ULL,
    0xE488B3EDCFC45D9BULL,
    0x15663EA46AF852EFULL,
    0xD6B7C770FB94C939ULL,
    0x8F,
    0x77,
    0x59,
    0xE8,
    0x23,
    0x98,
    0x69,
    0x02
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseHSalts = {
    {
        {
            0xDABE30EBD7B41C6CULL, 0xA2B4EFF74B91179CULL, 0xF26AFC9D07A0E712ULL, 0x6F74701F02E6D1A4ULL, 
            0x742682602C6B237BULL, 0x7B8AC1F1F15065FAULL, 0x7543B2ADA3207F50ULL, 0xF79642C35F5CAAB1ULL, 
            0x3AA145ADA9F1F968ULL, 0xCEE4E0C188FEB292ULL, 0x5EF78CFA6D94F1C7ULL, 0x8CB4133D81CA556FULL, 
            0xF484F5E3AC5D4383ULL, 0x2F602173B42E856AULL, 0x53CB852AF640B8B7ULL, 0xCBDF13D9D82C2DEAULL, 
            0xB5537D0C9B042D30ULL, 0xC98E6B4F4200E654ULL, 0x602A72C3ED5D3A63ULL, 0x7EEFB43088FB0416ULL, 
            0x1E76E779F3DF65B2ULL, 0x4EC6133004CC219FULL, 0x7CF14D2E968F1837ULL, 0xF499F78B67463471ULL, 
            0x88FD6E367CF3EE36ULL, 0x954685CBFBB3C213ULL, 0x6BA907D227282D8AULL, 0xC5281FE57779E0B1ULL, 
            0x5DAD1C55033BA1EAULL, 0x64398F78642CBA35ULL, 0x027496BEA4ECFB0FULL, 0x15412C6444BD65DEULL
        },
        {
            0x1A98AD613A2932C9ULL, 0x8007B7A12AD85AAAULL, 0xD035F02A05EF5839ULL, 0xF87649C58DBB70C3ULL, 
            0x9B33FF3BDEBAF182ULL, 0x151F17ED5EC98178ULL, 0x182BD8EB36989F96ULL, 0x4C77B1AEA5135C55ULL, 
            0xE287A4115E0243EBULL, 0x651DF54AA466E32AULL, 0xBED8EB7040C34C89ULL, 0xA9FA593F5C9D4509ULL, 
            0x664E84F9230D75B0ULL, 0x37CF9D3932323A22ULL, 0xD8E2AA8551B43469ULL, 0xD5A618FC2EE34760ULL, 
            0x4B128BD99DC89B41ULL, 0x6EA93B9CCEC555C8ULL, 0xBAEB94E376EABF58ULL, 0xC2EB7AEBF093BFA0ULL, 
            0x82CAAC770D2C6D34ULL, 0xA6EBB03E9F4B2B57ULL, 0x781759A0E2EC7A05ULL, 0x2F3C33796E72B388ULL, 
            0xE729DAE140A15F2DULL, 0xE4EA12BC643A9D25ULL, 0xF39FEF98835DC998ULL, 0x95CD742F503E7AAEULL, 
            0x1CDDA24CE36E4BECULL, 0x947CF03A9B353032ULL, 0x2F15287CD5F73284ULL, 0x73749033128ECA99ULL
        },
        {
            0x915356653877CCCAULL, 0x934B5FB6283645E1ULL, 0x65F475266B40DD58ULL, 0x20D14D2629BE2183ULL, 
            0xA78FE08052D7848FULL, 0x380EE30CAC145327ULL, 0x4808FA01FE978537ULL, 0xBBDAC482651CC448ULL, 
            0x0E566866FB2E7577ULL, 0x97AD2E72F677216EULL, 0xBD686F7A471C4781ULL, 0x37266395BE058734ULL, 
            0x5A5B6C745641C97BULL, 0xB363F67ADA96A949ULL, 0x01CA9122F5A02906ULL, 0xA5958FE264D56DB8ULL, 
            0x6774776DBE12F231ULL, 0x6A8F73F357E58B64ULL, 0x81B69A6BAAD46A44ULL, 0x2E96C116242EAA42ULL, 
            0xB6FFD06D861F3A14ULL, 0x0A97573B7342AE21ULL, 0xECA3026CD1521F52ULL, 0xE06BA55F84AB386FULL, 
            0xD4B34DC33886A612ULL, 0x870BB9A88ACC0EF1ULL, 0xA67BDE48996B37A5ULL, 0x02BB3BCFD56A38BFULL, 
            0x2762571314FF67BEULL, 0x48F8E8969ECFE154ULL, 0xBA73C9BC87FDCD84ULL, 0x6CC591E3D74B2307ULL
        },
        {
            0x35EAE97E0C5C61D2ULL, 0x56F8DABD882218A1ULL, 0xD1E699CFD98B4493ULL, 0x82F47C3C22D088EAULL, 
            0xF647C2E4CD284BB7ULL, 0x2F487DE423CB0F17ULL, 0xEE0405DF2D0A3F1EULL, 0x38100EBE6723C53AULL, 
            0x89D2633DDC611C21ULL, 0xF49E3A2424CC8714ULL, 0x7F305C0512A091E0ULL, 0x71D309431FE52739ULL, 
            0xF1161D5E19BF0D4BULL, 0x100DE4DB60E4D7AAULL, 0xF06897C8D67E6DA2ULL, 0xD2DD611097D065B9ULL, 
            0x182B9942D7F8C354ULL, 0x92F5BA3DC8267A96ULL, 0x980DA39E7FFA8FAEULL, 0x9A94AC7356B812B8ULL, 
            0x54F8C8F565FD0255ULL, 0x36508553C546E08BULL, 0x3FB221DBB07725DBULL, 0x4313E77AE4158A99ULL, 
            0x4F6846A85A4ACBCEULL, 0x992252511AEB7AE2ULL, 0x5733DFDDDCC387EFULL, 0xA164873DEAD6C00CULL, 
            0x32314D2F7EA8CD4AULL, 0xBB48845D65F934D9ULL, 0x16D5AFC947FA89A0ULL, 0xF74C15301381FB04ULL
        },
        {
            0xD5741BAC2FAE79A4ULL, 0xCE34CD5019BEABDAULL, 0xC3B4DC1A8C3611BEULL, 0x86385F78E0229BFFULL, 
            0x118CD191D24702D7ULL, 0xD1422C89AAA37005ULL, 0xB40B6CBE6ADE19E7ULL, 0x736B80832677CB95ULL, 
            0xE129D62315B72583ULL, 0x4A200936827B556BULL, 0x4DA8DD2D74AD3C47ULL, 0x7BCF89D55803977AULL, 
            0x3244FFA3E88E8D9AULL, 0x64882904F600D91FULL, 0x71433C9414354000ULL, 0x3FB48FA02333630EULL, 
            0x1FCF5BC954B61888ULL, 0x92A13816C3048134ULL, 0xDE8F0FD25BA4FEB9ULL, 0xA44692C33968FD0BULL, 
            0x31B518EBE7A1959CULL, 0x53C8BDFA6754A75CULL, 0xFBC5833F16AF07E3ULL, 0x5540900A70B85A09ULL, 
            0xEA8CA0ED98353C6CULL, 0x8BF5AB6B0A050F5BULL, 0x32365FC1F848811EULL, 0xE7DA9541C8B1FC84ULL, 
            0xD72CB4D728F042C9ULL, 0x9053F4CD49FB5F37ULL, 0xBE1E3CF8A9BC3F8BULL, 0x0B53486810CD8137ULL
        },
        {
            0x8D52DC9924BA7646ULL, 0x137563EBB21AB902ULL, 0x7F48E8E212BBBA6FULL, 0x10E3165685922673ULL, 
            0x01A84E4F4524D12CULL, 0x8889454B91ECE34AULL, 0x53CD213087B76298ULL, 0xF78D1040ACFFFB03ULL, 
            0xCDD9065C7D56F84AULL, 0x3011B6A023EF1269ULL, 0x599665CDC71E9675ULL, 0x3865DA6370BC2640ULL, 
            0x6E8E9A9AADA83D8AULL, 0x1DCEBD5B2EC89436ULL, 0x745BCF94D1EA5B18ULL, 0x889E0B9445D03697ULL, 
            0x33F574CAEA5D8226ULL, 0xE54026499E5428BEULL, 0xC4C2117D5138DCA7ULL, 0xB86049352090510BULL, 
            0x774508057C0E63E5ULL, 0x49312FC3B57A0BCBULL, 0xB686B9DA06178400ULL, 0xE58B2015F912DC9AULL, 
            0xC6C14BB6875EE4D4ULL, 0x449431ADE6E4FEBDULL, 0xFBA1767AEC4C092FULL, 0xF60B3D9296674B24ULL, 
            0xB7C3D6FAE264E820ULL, 0xB4831BF538A20BCBULL, 0x42CC98ECFD26F832ULL, 0x6884256523C66C39ULL
        }
    },
    {
        {
            0x83C042EC9F5BB5CEULL, 0x4D4E2B5B3103420DULL, 0x530EE98FBF3FFECEULL, 0xDB77E79625FEB003ULL, 
            0x43CEA33279AEC844ULL, 0x5DF882A87D5EE3E3ULL, 0x15A2D1EEF112D011ULL, 0xE17B6585155A98ABULL, 
            0x29AD66AF5CFDE54FULL, 0x5C567BC9E7314AA4ULL, 0x186DFCFCCA0B76ECULL, 0x2118C19D3EC2015CULL, 
            0xAD14CA5519570D81ULL, 0xA2D95B86F7C89EEFULL, 0x8BC81C7344C58031ULL, 0x1069198DB84B71CDULL, 
            0x2CDB3715B5C86A86ULL, 0xD0FDFA72916A092FULL, 0x9BFC4AFE4303545EULL, 0x4423AF25A2E7F1B8ULL, 
            0xC77B79870E955977ULL, 0x39BDED61C4A660AEULL, 0xB463EB330FFC279DULL, 0xF6774979F0E129F4ULL, 
            0x95801BE895EA7A25ULL, 0x4368D8D54740F31DULL, 0x66EF397622C01043ULL, 0x91D3781BD7DB412EULL, 
            0xC33736772B3A2943ULL, 0x990B18FDCEEE53A7ULL, 0x1A1B1CE8168A79F1ULL, 0xB213F960D5814756ULL
        },
        {
            0x08012B93D563C6B1ULL, 0x53C31FB862DE1FCAULL, 0x81D451F4EAA622B6ULL, 0x4F4BFF4C53DFB905ULL, 
            0x0241A3C980CECFCFULL, 0x497FA636EB330F05ULL, 0xA2C92E8E92B70A65ULL, 0xD8CBB200636BAFFBULL, 
            0xA9C21B86E5D177A7ULL, 0x83CA391E58D261E0ULL, 0xF1F46E0D9A8F7A30ULL, 0xFFA3BEFDFAA57ED7ULL, 
            0x666A577B6A827766ULL, 0x648EB1F476671693ULL, 0x586D42FAAD9A890EULL, 0x7A87962832774B51ULL, 
            0x7F0532E13A0C4D06ULL, 0x067B69213604D52AULL, 0x6FD5D81B16448AE9ULL, 0xAD7F5C4609241291ULL, 
            0x0CDB380249901EA9ULL, 0xBA4CDB5EA6B88815ULL, 0xAE586C5BFE2F5286ULL, 0x29488E42BAF9F784ULL, 
            0x45AF5779A49195F8ULL, 0x96A226EACA84A5F0ULL, 0xFCA909FE11748A6BULL, 0x3CAC5A3281879F9CULL, 
            0x89DB1E8E0B7C9FCEULL, 0x5FE9CA6AEC524FB5ULL, 0xBFE3B0F4CF7DF5A5ULL, 0x47A357EBE2827158ULL
        },
        {
            0x32020639182F934AULL, 0x9EF88160CA048BEDULL, 0xDDE8FD18E3B0A3F6ULL, 0xF9D20235844A3A44ULL, 
            0x587C9DE8D6025C05ULL, 0x0AD2A90627C4472EULL, 0x5D66874ED288A1D8ULL, 0x9D9D42772C3395E7ULL, 
            0x95CD7F733C46C95FULL, 0x19F1F5339AE668CBULL, 0x3E2D2FC73C9AB31FULL, 0xC096725877C2CA74ULL, 
            0x30DF18D327D12D9DULL, 0x86FD74EDB1282278ULL, 0xC187F61CE5DE40B3ULL, 0x3A1A2FD5A4DAA734ULL, 
            0x64424844EC641D87ULL, 0xB7011E4DDC947069ULL, 0x92D8B940BD1E4A32ULL, 0xD117CE80B5096688ULL, 
            0xDBE50034819DC59EULL, 0x1E596D1F02637FABULL, 0x27D6C67426E56C8BULL, 0xC953C1690784A571ULL, 
            0xF6A47DAF8282241CULL, 0x83F676414D248E61ULL, 0x8984D124BBAD9FBAULL, 0x2A8554486359EC46ULL, 
            0x027CA21DE3AF1927ULL, 0x372848457B4CBD82ULL, 0x25D8F9CE95692FABULL, 0x2FE9EF1DCED265E6ULL
        },
        {
            0x6BE9E72620BF445BULL, 0x8E5345A580CF60F8ULL, 0xC0753805A1985563ULL, 0x724FAE78A1E0D0EFULL, 
            0x9FCD911975EACE1AULL, 0x364331B9E308257EULL, 0xC6867A5B11C46044ULL, 0x526091D4E812B91AULL, 
            0x764CA61E25AB454FULL, 0xEC8D774AACD1903CULL, 0xF6AF4FE3CFBF773EULL, 0xE46B29D4E5C2CD2DULL, 
            0x79B7F38F488C5533ULL, 0x311DFA4D07460BECULL, 0x387FDA5233BD468CULL, 0xE2F2C763E30E4BBCULL, 
            0x864F573D8806ABB5ULL, 0xBB2CE21FC2A659B7ULL, 0x0AD2FBDAAE1BCD02ULL, 0xFB478317D3C28C95ULL, 
            0xB46BB15772DD0A19ULL, 0x05C49838679EF3ACULL, 0xE8D30F1BB4BE3184ULL, 0x3BD4052D1054EC24ULL, 
            0xC6D4CADF6DEE5795ULL, 0x94C508F94A160AFEULL, 0x0DFF166A6A977F9FULL, 0x5F6C5FCA65B425EEULL, 
            0xEFE170C2BA01389AULL, 0x2DF2A50F5C2284B8ULL, 0x8A1565DE16ACDB72ULL, 0x9B5E5EC6FA1A0339ULL
        },
        {
            0xC2A040FEDFF67AEAULL, 0xB71456620D423C52ULL, 0x90D20245CA35CDC7ULL, 0x824ADCA618009769ULL, 
            0xFBB4EA091E63990BULL, 0xA7E0BFF3EC4AAA97ULL, 0x58EFD30A1587D83BULL, 0x7F4339D596AC4C18ULL, 
            0x74DE8CE19B264ED4ULL, 0x5AAF98EB11FA270EULL, 0x3BC8EF6F65D633A3ULL, 0xB7BBD4CDBD84E7C7ULL, 
            0x11D29343C5051558ULL, 0x5871D897CBF65CE3ULL, 0x3DEA16BFAFE1270AULL, 0xE478B0210BD25EF7ULL, 
            0x74846569023CC54FULL, 0xF541937C93168241ULL, 0x275B1D9E2F143F81ULL, 0x318581B333DCE6F2ULL, 
            0xB2FE597B646229F4ULL, 0x9A16F47071CCBB80ULL, 0x6438CF58CE97BB0EULL, 0x8FDB2CF3EE201AC4ULL, 
            0x8AA935280666416DULL, 0x46B3CAFE432170C8ULL, 0x31F572388679330BULL, 0x90D40549F0B8A078ULL, 
            0x7B511E0CEF5AD86AULL, 0x6B2B02DFEB6B08E3ULL, 0x7B66506B6C2CD679ULL, 0x3BFBA7AEAA6033DFULL
        },
        {
            0x1204F6395F1A6F2FULL, 0x50B0586D172A8E26ULL, 0x837742C80D5AFE4BULL, 0x8A233273E1BE6F2FULL, 
            0x1D90EFAA2D8BF4A0ULL, 0xC432A4D35535C0A5ULL, 0xA5CD15DEC90D47EFULL, 0xA420F74388C36520ULL, 
            0x3A07846D611DCE90ULL, 0xB081CE4AE0BD714BULL, 0x9985AAF59E238AC8ULL, 0x4E6BC17A3923539FULL, 
            0x1D3D135D31D1DF7EULL, 0x1BFAF1460EE43E89ULL, 0x9D25D02C41D7F0DCULL, 0xDF8F85201EC6C5DDULL, 
            0x1719E20F57916A9BULL, 0x1A30CD5B25EF3FEBULL, 0xD7BA0A4D9D36FB88ULL, 0xA35368322FFD113AULL, 
            0xEAD522FA5EFEFE7EULL, 0xA213ED765955928DULL, 0x6DD9B6AA74244ACEULL, 0xE407FF50ECCB4BF9ULL, 
            0x456F42F5AE5795BFULL, 0x370E9255D37A44F1ULL, 0x0FC8D8D0321E4EDEULL, 0x6194C08313D771DCULL, 
            0x298A9862DBF8D8A1ULL, 0x42077DE65CFB3A9DULL, 0x844A07B295927D58ULL, 0x91E9A56F865929FDULL
        }
    },
    {
        {
            0x2F0398824AC1DD9DULL, 0x69AA67E83CCCAFF1ULL, 0x4B5290A47ABEB844ULL, 0xC8A2FF4420336CC8ULL, 
            0xE5744300DBA721A6ULL, 0x7B5473D7F9BFDC31ULL, 0x81059AF55268D77DULL, 0xDEDA25F4D40DD897ULL, 
            0xE5148FB653C2690AULL, 0xD12604AED6DB03B3ULL, 0x8F0273B706B1986EULL, 0x102634C85A8E17B6ULL, 
            0xC4CFD647B588F04DULL, 0x74BCB52205DE933BULL, 0x6AB88C6E0F20A7A4ULL, 0xCD012A48CF86C36DULL, 
            0xB49CE69A9A265BE6ULL, 0xFD7A9EFED7904C86ULL, 0xB58B919236FD8E3DULL, 0x43B52E22BC01F10AULL, 
            0xB9A7B030EBF08125ULL, 0xC26FB48C8B689C7BULL, 0x82507F7BA49F1400ULL, 0x59262ABC0738815DULL, 
            0x55D2B71CA6979656ULL, 0x806459E0E3927D82ULL, 0x1930F8836FDEB2ECULL, 0x2E3FCFCBC1A08F5BULL, 
            0x7C40CD0D4034BE0DULL, 0xF12DABBD3BCB697AULL, 0xF79649E4AD118ADEULL, 0x64A17D52D3338341ULL
        },
        {
            0xA390A6DF5FF90A5BULL, 0x907D87AA0AB811E3ULL, 0xB90082866AD7A4ACULL, 0xFC10119FA498BC97ULL, 
            0x6B281F37CE6FDD8CULL, 0x12E79846654D4F78ULL, 0x183B046FD54F0E4DULL, 0xC75E1E15AF0706A7ULL, 
            0xE3920CF18A4FE140ULL, 0x9DAC0EAEFF5EBC41ULL, 0x1CF12103EB905C52ULL, 0x1E5FF29954518BC4ULL, 
            0xB91D611290C18E47ULL, 0xB4905565D26531E9ULL, 0xA9724C6366139675ULL, 0xA98062DB7D5EDC1FULL, 
            0xCBED7E2D16E69BCEULL, 0xD3270F4699320C96ULL, 0xA4D6FBD67F9E4FA4ULL, 0x5F7FD593E84D15E2ULL, 
            0x61B4DE96AD786756ULL, 0xBF983FC940F9CD0EULL, 0xC49FB47A7BF816B7ULL, 0x0D3EF63871DFFF52ULL, 
            0x0CBE7EF3CDE501BCULL, 0xE0D5C18FCE8E8575ULL, 0xCBFAB77D275D34F0ULL, 0x8EAF9B17B7F87F5DULL, 
            0x2D3C304C2D8CED21ULL, 0xBF5964DCEB89549EULL, 0xFEE4391732ADDAB7ULL, 0x6FF9C28987EBDC0AULL
        },
        {
            0x859EC26B541020D0ULL, 0x99F769E80941E5ABULL, 0xDD07B762B4AD472CULL, 0x8FFD075931CA81ABULL, 
            0xD75F74F14A4F1123ULL, 0xEFC538223427EA10ULL, 0xDAE7F9E540834D94ULL, 0x5980C82453C529ACULL, 
            0x67D9F242625A2249ULL, 0x0147CE1997F1757EULL, 0xFCE902B93E5E74ABULL, 0x329B1BE5F9320CAAULL, 
            0x84719C5F9FB078E5ULL, 0x7A7C350C463F45C7ULL, 0x839ED8BFC9C9A074ULL, 0x0A67DCB239E182F0ULL, 
            0xD906CCAB2669F37BULL, 0x00A42BC4A23AED7AULL, 0x1D4F29E2C8F6AFC2ULL, 0xD4B5978413A3571EULL, 
            0x472DE5654AB41767ULL, 0xD11DA554FBC26467ULL, 0x2D9148896194D5C1ULL, 0xC8B7B01F63793D0EULL, 
            0xEA5CC0AE0ECED5A3ULL, 0x660CFA6CB02AAE74ULL, 0xB63B0A3F0F7A3827ULL, 0x89AFDC71318F05C2ULL, 
            0xB6C299F8666B84ECULL, 0xE0589C7D0F01BA12ULL, 0x86C20044D949A23AULL, 0xDE2197FB7D23F8D0ULL
        },
        {
            0x7883C80F54DF536DULL, 0x7590A2244954C29CULL, 0x8DF8C8FF16746469ULL, 0x0429A894A68DE969ULL, 
            0x1EDE29B9BD4923B2ULL, 0xD17351D13D79FF3FULL, 0x4DC6025A8E0F4924ULL, 0x278DD1A4DC15BF32ULL, 
            0x8DA6AE25BB9F2CDAULL, 0x20A97FA33CA19A8CULL, 0x492C46A664D4816AULL, 0x323F9821D855C616ULL, 
            0x75A70E80F05779E4ULL, 0x065D0942B83167E2ULL, 0x946528092311128EULL, 0xE15252336247E684ULL, 
            0xB3BEFA818D8DA787ULL, 0xA1BF32C50D4753A3ULL, 0xE5209FDF26E72715ULL, 0x83B91A553A039A8EULL, 
            0xAA89FCA973887DC8ULL, 0x43890853472DA248ULL, 0xBD040DB5AE825B1EULL, 0xDC861BFD4BEDBED0ULL, 
            0xE8D76F967A152372ULL, 0x416B216990D595ECULL, 0xFDF73F208F136E05ULL, 0x6A798799C0EFBCF3ULL, 
            0xF2A0EFD1A7B8974CULL, 0xC40CABF93A999EA2ULL, 0x10A9922D072885FAULL, 0xE9135EEF1B7DFC98ULL
        },
        {
            0xD4AD03DC6CCC89ACULL, 0x561F2119ED66B7BEULL, 0xBFFA5C6D5887FE7DULL, 0x25C2CC6EC3EE0F66ULL, 
            0xABE38FFCAF893580ULL, 0xE7F973CBB27A9168ULL, 0xBDE62F4DBA15466BULL, 0x82EF6722F690B72AULL, 
            0x5E8406B5CF6D016EULL, 0xA973E9206EEF75CCULL, 0x7CDCC8E629B2CD8EULL, 0xF250F306F84E4719ULL, 
            0xCCB0E4933E4B4C21ULL, 0xCFA5CE7B62C913BEULL, 0x329E55FA8F64A8BAULL, 0x8D4C6801B3B674D3ULL, 
            0x3565A81BEB6A198EULL, 0x30E8E7B42D75C304ULL, 0x72906A965D35A5F7ULL, 0x18DE99AB20650EB9ULL, 
            0x10980879F3D58DB0ULL, 0xF65B32979BFFB819ULL, 0x0DFBCF4DB3041145ULL, 0x643A133097833AE4ULL, 
            0x35FF7A4EEE347E8EULL, 0xEDDB8A5AE7C1C172ULL, 0x66710F4F3C9C3A7EULL, 0x4E87FF5400493807ULL, 
            0x75253FD353464DF0ULL, 0xD9D29DBC97089B7EULL, 0xB57F148223496075ULL, 0x93A4B87C3AD2406EULL
        },
        {
            0xF3F27A49356CEE6FULL, 0xC9AEADAD49C6FE9FULL, 0x69D7EA722B064263ULL, 0xBAF90A03830A96ECULL, 
            0xB2BE121C123D8B8BULL, 0xD9E0A1368206ED74ULL, 0xAD065F74F806597DULL, 0xAD2D4AD409E775EEULL, 
            0x238BEF045BC83B3EULL, 0x19B8CDD01F7B6FBAULL, 0x10A6CFC86E085178ULL, 0x0090CFC09371B501ULL, 
            0x247009B08097DB32ULL, 0x228286F168665073ULL, 0x8C926C20B923761BULL, 0x62FC3C8D62A7CE6EULL, 
            0x43D60ACFC9361223ULL, 0x441074A9581997B9ULL, 0xEB0B16A1EF6CE754ULL, 0xCA2FE138C52366A8ULL, 
            0xF53F887047E3DECDULL, 0x3B8136E4E40C518AULL, 0xF03EFE11D7369C7FULL, 0x9666342F9842DE85ULL, 
            0x76A23568672F4CFFULL, 0x3B457CCAF670CA60ULL, 0x08EE1536C0B49AF5ULL, 0x0D8308F29289FB06ULL, 
            0x665B26A379B64122ULL, 0xFF1B82AC452F255BULL, 0xD2A7926C98A2C9F1ULL, 0x7D0F35BFBF743F4BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseHConstants = {
    0x4FDFDA62A9856A9CULL,
    0xFF7EE5F8EA3C341FULL,
    0xB0D5E51D1D0848E7ULL,
    0x4FDFDA62A9856A9CULL,
    0xFF7EE5F8EA3C341FULL,
    0xB0D5E51D1D0848E7ULL,
    0xBE41311A0E91C4A0ULL,
    0x18A5718A7D55E0CBULL,
    0xF6,
    0x57,
    0x0A,
    0xE1,
    0xAA,
    0x1E,
    0x71,
    0x02
};

