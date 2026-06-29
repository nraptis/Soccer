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
    std::uint64_t aPrevious = 0xDFFAACEF9C08EF5DULL; std::uint64_t aIngress = 0x8B496E0DF3BD247CULL; std::uint64_t aCarry = 0x8D7F5D451BBCF6DEULL;

    std::uint64_t aWandererA = 0x8182F56B51DEDB5BULL; std::uint64_t aWandererB = 0xF4509A5BCB760900ULL; std::uint64_t aWandererC = 0xB7D98CC330BA2220ULL; std::uint64_t aWandererD = 0xD226FFAC4F5C434AULL;
    std::uint64_t aWandererE = 0xBD98352C950BE03FULL; std::uint64_t aWandererF = 0xAD028337C7891334ULL; std::uint64_t aWandererG = 0xD629018DC63DEC93ULL; std::uint64_t aWandererH = 0xF45A5153CDA68936ULL;
    std::uint64_t aWandererI = 0xA4C5158390C6C038ULL; std::uint64_t aWandererJ = 0xA9DCDC5B409CF83CULL; std::uint64_t aWandererK = 0xEC1F47B14BDF8D3DULL;

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
        aPrevious = 15011072327627800133U;
        aCarry = 14732441387072282568U;
        aWandererA = 15476279559950445680U;
        aWandererB = 11746954116732854134U;
        aWandererC = 16903067038893590639U;
        aWandererD = 16453016148278782153U;
        aWandererE = 13162790222848939529U;
        aWandererF = 16165433643250068415U;
        aWandererG = 18341414972030821675U;
        aWandererH = 14581212429641364446U;
        aWandererI = 12445298312560290093U;
        aWandererJ = 10170600384772095610U;
        aWandererK = 16403849980896834240U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0x8DCE0DB2EE710D75ULL; std::uint64_t aIngress = 0xFF17464D3A6CFDCEULL; std::uint64_t aCarry = 0x9547356E0B32544DULL;

    std::uint64_t aWandererA = 0xAA4B5B771C7A0705ULL; std::uint64_t aWandererB = 0xB046FE14CB04993BULL; std::uint64_t aWandererC = 0xC4F8CBAE5CE5A584ULL; std::uint64_t aWandererD = 0x9FC3D706FE60D08CULL;
    std::uint64_t aWandererE = 0xB61725240063A3DEULL; std::uint64_t aWandererF = 0xF9BAAEF965161DD3ULL; std::uint64_t aWandererG = 0xDC1C53739E2E9896ULL; std::uint64_t aWandererH = 0xF65F56A4BD443AA5ULL;
    std::uint64_t aWandererI = 0x98BFC0C51DE99127ULL; std::uint64_t aWandererJ = 0x959A95B06AE08606ULL; std::uint64_t aWandererK = 0xE0FB4B0BBBD1D32CULL;

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
        aPrevious = 16553449295045877627U;
        aCarry = 11908019838578171884U;
        aWandererA = 14626191642176809013U;
        aWandererB = 9791351249689681964U;
        aWandererC = 12334114290646634490U;
        aWandererD = 9773508730085995675U;
        aWandererE = 9417070361000726328U;
        aWandererF = 17690655325613814180U;
        aWandererG = 15320841710040662446U;
        aWandererH = 12115923157751714911U;
        aWandererI = 12799489335990104977U;
        aWandererJ = 10744862130890591573U;
        aWandererK = 11048089713200005039U;
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
    std::uint64_t aPrevious = 0xD75B87A59F8AAF6DULL;
    std::uint64_t aIngress = 0xE1A881826384D7FEULL;
    std::uint64_t aCarry = 0xE3542A804B590414ULL;

    std::uint64_t aWandererA = 0xC6285BEFEF97CE89ULL;
    std::uint64_t aWandererB = 0xDDFFC632F110DDD3ULL;
    std::uint64_t aWandererC = 0x8389BCA4420E601CULL;
    std::uint64_t aWandererD = 0x9F18E463FE1BE721ULL;
    std::uint64_t aWandererE = 0xAA27AA23F4783CFAULL;
    std::uint64_t aWandererF = 0xDECB68C2396AF5D3ULL;
    std::uint64_t aWandererG = 0x817ACA0BD978C58AULL;
    std::uint64_t aWandererH = 0x85D882BB4470CD4CULL;
    std::uint64_t aWandererI = 0xA58529CB028B0E93ULL;
    std::uint64_t aWandererJ = 0x9349D63A30EE39C9ULL;
    std::uint64_t aWandererK = 0xC32271165ED4216FULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneA);
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
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
    std::uint64_t aPrevious = 0x8DD20EAA21E0DFCCULL; std::uint64_t aIngress = 0xE345E8C803D2D845ULL; std::uint64_t aCarry = 0xD4E4477AF80E4BEBULL;

    std::uint64_t aWandererA = 0xB034DAD198FD0440ULL; std::uint64_t aWandererB = 0xC051CAAAE00CAA53ULL; std::uint64_t aWandererC = 0x9604B985D48ADAC7ULL; std::uint64_t aWandererD = 0x931C4B8E236FE220ULL;
    std::uint64_t aWandererE = 0xE4DDC5384A2F90B4ULL; std::uint64_t aWandererF = 0xEA561F582E23B0DCULL; std::uint64_t aWandererG = 0xB414505971779619ULL; std::uint64_t aWandererH = 0x8B1CBDA1AD0B01D2ULL;
    std::uint64_t aWandererI = 0xE310DB8E4807342AULL; std::uint64_t aWandererJ = 0x87C127DB2E85AF3BULL; std::uint64_t aWandererK = 0x86F20F7ADBF084B6ULL;

    // [seed]
    {
        aPrevious = 16197246777197900116U;
        aCarry = 15728520635931257125U;
        aWandererA = 15043928314641003792U;
        aWandererB = 15646903174991767655U;
        aWandererC = 16241912203019468359U;
        aWandererD = 10016592411751484118U;
        aWandererE = 10523307875458444398U;
        aWandererF = 16701304809199502185U;
        aWandererG = 11519070030748936185U;
        aWandererH = 14967169885332944778U;
        aWandererI = 10217596454806556471U;
        aWandererJ = 9964365498592339190U;
        aWandererK = 14161924381527366350U;
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
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 1 with offsets 1927U, 5852U, 3025U, 5048U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1927U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5852U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3025U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5048U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 1, 0 with offsets 5938U, 8053U, 7607U, 3331U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5938U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8053U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7607U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3331U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 2 with offsets 79U, 4635U, 2495U, 6819U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 79U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4635U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2495U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6819U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 3, 3 with offsets 7444U, 6973U, 6856U, 4520U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7444U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6973U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6856U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4520U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 with offsets 1786U, 705U, 39U, 1080U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1786U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 705U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 39U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1080U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 0, 1 with offsets 852U, 1930U, 108U, 221U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 852U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1930U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 108U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 221U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 3, 2 with offsets 257U, 1797U, 494U, 1787U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 257U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1797U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 494U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1787U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 1, 0 with offsets 40U, 1503U, 31U, 1963U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 40U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1503U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 31U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1963U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1254U, 866U, 2047U, 780U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1254U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 866U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2047U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 780U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 2 with offsets 770U, 452U, 5033U, 2627U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 770U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 452U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5033U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2627U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 0 with offsets 806U, 3792U, 4845U, 6563U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 806U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3792U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4845U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6563U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 3 with offsets 4973U, 287U, 7442U, 7035U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4973U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 287U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7442U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7035U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 0, 1 with offsets 6150U, 5041U, 3420U, 5902U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6150U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5041U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3420U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5902U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1213U, 384U, 1939U, 4695U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1213U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 384U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1939U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4695U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1080U, 1030U, 719U, 473U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1080U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1030U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 719U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 473U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1572U, 1597U, 450U, 19U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1572U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1597U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 450U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 19U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 999U, 112U, 1085U, 1350U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 999U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 112U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1085U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1350U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1554U, 377U, 870U, 1179U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1554U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 377U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 870U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1179U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 [0..<W_KEY]
        // offsets: 239U, 688U, 811U, 1790U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 239U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 688U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 811U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseASalts = {
    {
        {
            0x6A86D73147C1FFA8ULL, 0x0B893F13A363458FULL, 0xBEF7B5B1A8C27BDCULL, 0xE09FF467AA9DA944ULL, 
            0xD80FC7B204502DDEULL, 0x7E205DFC9BBA4865ULL, 0xA7BFBD35FD6AC255ULL, 0x9EF810AFE5971944ULL, 
            0x6BD4B7177AD2BF0BULL, 0x1D4A65AF298F04B0ULL, 0xD60508A243A8BC9DULL, 0x9BF1D6550BE205D5ULL, 
            0x16B3EC586D5FF328ULL, 0x881AC6E7ED953F41ULL, 0x7759698A4F62ED1AULL, 0xEDE9E00EE9C0453CULL, 
            0x53EFC0D2982E6DEDULL, 0x16E3808B89FF25EDULL, 0x0A3895AE0C415D49ULL, 0xC093D091BEF28CD4ULL, 
            0xD8CC56E6C4FD0941ULL, 0x5CBC97608092EB3FULL, 0xE07FC4F4216DD114ULL, 0xAAD087DF580CA8A1ULL, 
            0x73B3D4A40F9478A7ULL, 0xFDB134BA3A917D1BULL, 0xA28B1E3767744B4AULL, 0x34850CE7EA3D4578ULL, 
            0x9604F810784A84B6ULL, 0x434DB8B2C404DB8EULL, 0x754F2C8FFFD03333ULL, 0x701FB486D49F4A1DULL
        },
        {
            0x6CF6CC6E11547D0DULL, 0x686965EEA8DE8001ULL, 0xB5D872D7CBCE32D3ULL, 0x3C904C2AEBFFA955ULL, 
            0xA3F4BA0031362D00ULL, 0xF0A64BD3CA5189F5ULL, 0x0EFA4A03A5A84F64ULL, 0x1BDC7B54440D8713ULL, 
            0xDB1A3A87557950FAULL, 0xADA323684F87C046ULL, 0x84EA99BDFBD6D1FAULL, 0x12D2DA143BAE8ED2ULL, 
            0x8A02DFE3CB267A92ULL, 0x1AA6F396A5ADDB4CULL, 0x11F3EC82B164E30DULL, 0x20DBC4E4A31E0E65ULL, 
            0x3579CB335DB75EFCULL, 0x3A2C6393668D409CULL, 0x224E7D86218B351DULL, 0x5C44AF2D426CC971ULL, 
            0x1CDA52A58D3E5FA2ULL, 0xB5C42336BD8D1485ULL, 0x5422EB110A1F4589ULL, 0xF2BF0FFAA984C2FFULL, 
            0x0087826F595D60B8ULL, 0x57550992543C83B8ULL, 0x85FE7BA60FB4144DULL, 0x03E57E3ED4AADDCAULL, 
            0xC3D4B4EA1C61C2C4ULL, 0x61FEF8635547F15EULL, 0x6DC4EA25DA8D7341ULL, 0xC1C01EB42837A4F0ULL
        },
        {
            0x63985477721B3857ULL, 0x9C5C571A0D2DCB94ULL, 0xC539CA2AF1D53B38ULL, 0xC9164E732DC88311ULL, 
            0xA08CE70D4A00F8FCULL, 0x452B5C84626E7E4EULL, 0x99CE45AEAF4A8A08ULL, 0xEB1442EB8C765978ULL, 
            0xF364F1CA33395364ULL, 0x42C47B68DCFCBC7DULL, 0x76781AFC18C02C52ULL, 0xF8D09C498752E85EULL, 
            0x636904C4A48D0353ULL, 0x5354158FF1FA6FA3ULL, 0xCFA7E3C5E487C736ULL, 0x597E5B5E000002A0ULL, 
            0xA184B6CB76BB8B72ULL, 0x677F0B4E7CA84F18ULL, 0x9E3BA2979101C71DULL, 0xC2DA7583560AC95EULL, 
            0xA8386110B38F82BBULL, 0x6BA30740E7265BA3ULL, 0x8B497106AE3AF335ULL, 0x1F76556303540497ULL, 
            0x6E2D214A7C281A1EULL, 0x9A1A0D2E748311B7ULL, 0xD2F4FB209926A725ULL, 0x612AC8705BC0AD85ULL, 
            0x18806B86529FE029ULL, 0x1C43596B096C058FULL, 0xF65B1637252AF8B4ULL, 0x6DEB3316CFF29234ULL
        },
        {
            0x9021773241495C0EULL, 0x5F6460E6F7976FFDULL, 0xCF83B09BF44F7F16ULL, 0x865498389B9CD54CULL, 
            0xC61BEF7F3AFE5941ULL, 0xEBE3606B384B0546ULL, 0x38128EAED129F8FBULL, 0xFD2261D9954A6539ULL, 
            0xE7015D272D94C2FCULL, 0x0DDD8AF2A478CC39ULL, 0x56F6F9AC81B9A346ULL, 0xCBCC3C4BBBB96E85ULL, 
            0x2F3A3A5E1382EB20ULL, 0x98C2689F36E1A15AULL, 0x142168225D57795EULL, 0x03C833327E373427ULL, 
            0xA6FA98F5C6EC7176ULL, 0xEFA8F6307DC64E9CULL, 0xC8384A8755FD1ABBULL, 0x844C6052990C3B0FULL, 
            0x566CA4F18D3F9F8EULL, 0x3B0FDC63AC1C0819ULL, 0x04048A42A4950D75ULL, 0xC51F8F713F926BF6ULL, 
            0xDE65D0DF412B1EEFULL, 0xEDDAA120C6AAF8DCULL, 0x0AAD1174AE32E4C9ULL, 0xB938F1CBCCAB0207ULL, 
            0xEE17CC840E0AEBB8ULL, 0x259892B711DE55CEULL, 0x10C5A7238BC42BFDULL, 0xE506DFFA6AAD7227ULL
        },
        {
            0x8BD3626EB2586FC9ULL, 0xC02AA9CAA868719CULL, 0xA6602A43D7EA34FEULL, 0x595EBEFEDA5099E4ULL, 
            0x4980E5865899F5DCULL, 0xA38D59FC39980A17ULL, 0x5405C0899CCE00C0ULL, 0x9135BDF8EE901FF5ULL, 
            0xAC006E3A809B03F1ULL, 0xD94B183B8C398B45ULL, 0x5F66A3AB62E3B0B0ULL, 0xA79131C2A23EC0E8ULL, 
            0x07ED7C8AEDBB0C26ULL, 0x7B21C4B75DF4CF7CULL, 0x626B622999E023BBULL, 0x04AE004D635E4421ULL, 
            0xE81E43B150A32642ULL, 0x4C63E36563B6C582ULL, 0x32BD0FE9EF03B1EBULL, 0x2B88F7CD7713B63BULL, 
            0x47497B413CA8B11AULL, 0x2231E19293751817ULL, 0x6F2E6BFCD6E29920ULL, 0x55182A0943BC803AULL, 
            0xF021910C5874A15DULL, 0x8A024423CCE7AF67ULL, 0xC7C0DBF365ED003BULL, 0x2E95EDB1978BA66BULL, 
            0xA75BAF8B626D5F4EULL, 0x2EC54F2F4F16EEF4ULL, 0x3308453EFF7FC00EULL, 0x08D4334142C5CF50ULL
        },
        {
            0x0118E954C0C69D77ULL, 0x9A134C0E61B038FAULL, 0x56386980FCB8402CULL, 0x4FCF192BD6AA244CULL, 
            0xC2CB76CBE3A63F01ULL, 0x40DDBB0EFA600CDCULL, 0x3FD29E6CFA86C576ULL, 0x44A018D145801DBDULL, 
            0x654A0E7B48D8A85DULL, 0x936C26B0329972EEULL, 0x3CC0F4E58544D297ULL, 0x8D36DC57193DCE8CULL, 
            0xE6493541BAFBA2AFULL, 0x0D39AA2B646C6758ULL, 0x20DA14FA85354225ULL, 0xF8A040099B61CE1FULL, 
            0x5E3B86DD0E9100FDULL, 0xF1D95310BC88E5B8ULL, 0x037CDCE706F9C31FULL, 0x0C7592FEB304FA38ULL, 
            0xBD1FB18C95C213F9ULL, 0xDFB2C35A563909D9ULL, 0x5F929801425FC7ADULL, 0xABB28EBC22C740ACULL, 
            0x474C9B74280AEAFCULL, 0xFB0BAB6E32CD6B0DULL, 0x1FEE794231E1BABEULL, 0xD2DD09EDABEA26B8ULL, 
            0x2932B4DF8DCAA1C0ULL, 0x667C98F1B03B163EULL, 0xBC16A9D8BC277721ULL, 0x6B64E87BC5355E8CULL
        }
    },
    {
        {
            0xF740F92727E09943ULL, 0x8D6F24A18CF95498ULL, 0xC7A259A8E64C0D39ULL, 0x86C85D741626B627ULL, 
            0xA022506A48E7E5B3ULL, 0xFB4DC8435DA12219ULL, 0x82316DECCDFD5050ULL, 0x7BEF0386E66E022FULL, 
            0xB86FCF50AA1C767DULL, 0xA1CE951EA7E1DB2FULL, 0x8E54F57D9F9E197CULL, 0x1AF89A05A4CAC60EULL, 
            0x5FB6BB8948E7F6E7ULL, 0x50643511226BECB1ULL, 0x43E1F6FF2320892DULL, 0x24216C96C62133A4ULL, 
            0xEC75DF8FDAB42867ULL, 0xF01100E9BCBEB85FULL, 0x854605BAA21FE669ULL, 0xD8D5EB7E25AE2165ULL, 
            0x8AC1553B641ACFF1ULL, 0x57F7D0877AB5523DULL, 0xF13146AA8BBDF210ULL, 0x5CC4EA884AD329B1ULL, 
            0xE8D79DC4CB064EE0ULL, 0xDBDCEA3F7DB1844CULL, 0x931CDE122D110167ULL, 0xF52492F02BA2A897ULL, 
            0x174A2677C4210E95ULL, 0x9A8C8458F2C9D47EULL, 0xF2CB4E33CAC966FAULL, 0x20BA37509AC74AFAULL
        },
        {
            0x4541F2A21443040EULL, 0x9990C6DA0A11FE16ULL, 0x4CD7AB00F13CDA6BULL, 0x9AA95B762678F0B9ULL, 
            0x7FBDA48C487234C2ULL, 0xBABCACB561136883ULL, 0xD8507AA330652ED5ULL, 0x2F11F21C42453BF8ULL, 
            0xCA6883549190435DULL, 0x19D271E9149FE9E7ULL, 0x6A253852824D9C0BULL, 0x6762D8212761569FULL, 
            0x5BC7ACC443C178CDULL, 0x10752A524743F0DAULL, 0x256435E83C5FF799ULL, 0xE802E640F6559E56ULL, 
            0x3574C3B52C122B74ULL, 0x3891D885072698D5ULL, 0xB852F98FD4CAC6E8ULL, 0xC81513BA23796CAAULL, 
            0x286B6A91E6495320ULL, 0x3B871A0243CD6481ULL, 0xB51290B2AECF5468ULL, 0x8EB2225458D0114FULL, 
            0x951C89CEBD5CEF5CULL, 0xDA65F02EAFD7932AULL, 0x289C96A21083AD5AULL, 0x3E74B0A201209E1FULL, 
            0x9B14662538932C53ULL, 0x35A516FFD6B2463CULL, 0x66F2517966F1FAEEULL, 0x122444F64706C8BEULL
        },
        {
            0xC4F70A157FF95DD9ULL, 0xC6A9B6D11EAE352AULL, 0x6F3E2F392306B68CULL, 0x9C3C20750740DC57ULL, 
            0x7BE5151F4F3A687CULL, 0xCA4E708B41A18874ULL, 0xAFCEFE6D7AF475EDULL, 0x08EBFD17A62E60F4ULL, 
            0x668B3E9EBAF219B1ULL, 0x13A82503CCBC13B9ULL, 0x02964AE504A052FBULL, 0x46F933AC582A5191ULL, 
            0x09C9980728BC062EULL, 0x05294AE7A3F7B164ULL, 0xE3276791952D7160ULL, 0x7AD505636798D1FCULL, 
            0x5098B60BA9E6E10FULL, 0xCA00810469C18E6AULL, 0xD18594BA0F17E989ULL, 0xABF0C5759C5064CCULL, 
            0x3D7233E0430A9FA0ULL, 0x92D392AB2A74F6EFULL, 0x6704A04270298C04ULL, 0x385B832B93772C9EULL, 
            0x60F805197E7878A3ULL, 0xE579DECBA9415A8DULL, 0xF11B105C3C9DD008ULL, 0x63CBD6BD86A721F0ULL, 
            0x38A9827102937F4FULL, 0xE790F56A920849DFULL, 0xB502B9DE7709DDE6ULL, 0x1EC8C9C3887F0D1CULL
        },
        {
            0xAC3AD2F090286FEBULL, 0xD05AE64C91EF5C3DULL, 0x46F0B08937DB0AF7ULL, 0xC64787D22DC83810ULL, 
            0x643D3BB7BAB5FBBBULL, 0xB01D3C2EA1BC8ED7ULL, 0x7371AD6168927A64ULL, 0x6F4F7238207B6A0FULL, 
            0x315AD60E08249680ULL, 0x9EE3F2E46C0C70BBULL, 0x8CC7CEE031BCC230ULL, 0xD953F23BAB75AA6AULL, 
            0xFEAF8CC53E3A2BCEULL, 0xB8149A0E477CD0A5ULL, 0x16DC98110BD3182DULL, 0xEB6EC1A1DD3740BDULL, 
            0x93C4D395A33344BEULL, 0x4636C1E59FF7EBC4ULL, 0x9C6605872AA949F0ULL, 0x8CAF45AAA3CC94F2ULL, 
            0xBC60E5B906BD1099ULL, 0x98BD4A337B07A46CULL, 0x5A7D897B1C966CA5ULL, 0x8466AFC23803C7EBULL, 
            0x9BC5AC5F0E66F99BULL, 0x361A4D5A39EC9302ULL, 0xA44BF9A983001EFEULL, 0x33D22693244BCE87ULL, 
            0xF98D35EE9A234616ULL, 0xE6EC6CDBE01123E3ULL, 0xB0F9B63EF9085BC4ULL, 0xF47ACDC7AA93D8F3ULL
        },
        {
            0xEB9C0A467CFEE977ULL, 0x4BC43626736FCCDFULL, 0x8FFF71FE5552B1F7ULL, 0xBA71F517CD1D96B7ULL, 
            0xD94216FACE49232FULL, 0x9E9C6C8C19C43A54ULL, 0x8BA8AA407E3B781DULL, 0x1D8BE95D2707D2BEULL, 
            0x13F6983B7D002B37ULL, 0xD5936151C1B12635ULL, 0x102DD7829A50E206ULL, 0x2AB3B4A5CE208C2DULL, 
            0x0D6C1D13328F95DDULL, 0x8565F7F74573FD14ULL, 0xA4B103673540D3AAULL, 0xF2B8D3571ABD8114ULL, 
            0x6B439722FBEE1C24ULL, 0x6F42F4D21DE6FC96ULL, 0x67831E918B34DC6FULL, 0x4F688099035B9B93ULL, 
            0xF2846E93C2AD83D8ULL, 0xCE6D335C4D9543B8ULL, 0x1A40B6E1B70BECE2ULL, 0x48902F4E5286A555ULL, 
            0x2623B0187C1A0ACAULL, 0xF75307B6D3C2068EULL, 0xBBBE67282AF22552ULL, 0x95B7282781DE83EEULL, 
            0x9E9D8254CA176B58ULL, 0x6A7AC76727EBC080ULL, 0x062EA253FCC91731ULL, 0xFF0164FB6BE4C688ULL
        },
        {
            0xCB4246333EED6640ULL, 0x880E1F5CC14C6B86ULL, 0xD3A2B0351A9D518DULL, 0xEED56D13D546CD7BULL, 
            0x55F0FC4389EB74BCULL, 0xB1C55313A9B11628ULL, 0x33E30A7DBA9AAD93ULL, 0xBC55C41C80A3DB59ULL, 
            0x89238A655397726DULL, 0x4D4B8B0C12042CC9ULL, 0xBEACC1A9C7AA5C18ULL, 0x2071DA1F7666EE5FULL, 
            0x8699F1C2E764F8E7ULL, 0x2A553A2E89EBCAD8ULL, 0xB14AEDE4F8465076ULL, 0x20C3A8FAC0B1F8D0ULL, 
            0x8B8A2E5151A2A3AFULL, 0xC85D31F485AC493FULL, 0x32BED730A0E99896ULL, 0xE1E27F7ABA98B72BULL, 
            0xA9FBF0AD086A2EEEULL, 0x86939A40EA7845E7ULL, 0xFC62BD0D8D022BCDULL, 0x076134E62496EBDAULL, 
            0x585549B63409CBDCULL, 0xA51B2AF52C628641ULL, 0x7EB949859C3D3D56ULL, 0x48A2A7514E2259C8ULL, 
            0xD35CC7D917336C2FULL, 0x942253118F8AD879ULL, 0xB435B63245118AD1ULL, 0xDC9545883C3E79DFULL
        }
    },
    {
        {
            0xB6EF4D57170EFAE5ULL, 0xAA9BF1C7BEC3737BULL, 0x61E4E0F0E52A8E59ULL, 0xB98BFB07C0A9C490ULL, 
            0x1B6F3A4507F573FCULL, 0x17A988F010B97C54ULL, 0x66E10A5421C722CCULL, 0xD4E18FE09B1341A0ULL, 
            0x6D2F6264E175454DULL, 0x1F50969ED43B22B2ULL, 0xC35923C08EC7E790ULL, 0x538EDDDF983EA8F2ULL, 
            0x4018A6B7504DED8CULL, 0x7E4AFCC95E42BD54ULL, 0xB1A5304B1BE06E5EULL, 0x36751C41002BF956ULL, 
            0x0DC11D5094085D46ULL, 0x088FD2450648142AULL, 0x992BAE0C05FD84B4ULL, 0xDC8C7FF8A9DAB1D0ULL, 
            0x6A8D30071F0EE23EULL, 0x33B3E94BE0B34C02ULL, 0xF7CD5A4AF652A7C7ULL, 0xB2C26115D02219A1ULL, 
            0x12099494083244FBULL, 0x674FA1F40A88CEADULL, 0x92DA98DD4B369E0FULL, 0x2F6CD1F7BA7A7EE3ULL, 
            0x93BA570CC4D0F66AULL, 0x70C30215F86291B7ULL, 0x5250B5C37DB9D56AULL, 0x95E4FC5A47086038ULL
        },
        {
            0xB76DB68B9A707F26ULL, 0xFECFE986D8A7B21EULL, 0x2F66751EF70F74E5ULL, 0xF0364367657A1B8DULL, 
            0xA092E6DA99FC377CULL, 0x63611BEB6161F30CULL, 0x5080316AA9303374ULL, 0xEB73C474101D879BULL, 
            0xD18FDC4C763F3694ULL, 0xA896AB881218B27EULL, 0x02EE41C5D6F38D0FULL, 0x04F711BA5C6303CAULL, 
            0x52C1AA6C0510FF7DULL, 0xE71C01F821CCEDCAULL, 0x2CF166D13665D0C6ULL, 0x3F651BCC26A6A6E8ULL, 
            0xDF2FD05664FB617BULL, 0xE7CA39F8659C653CULL, 0x48B7CDDDD9194DB7ULL, 0x272BF2CD733A3766ULL, 
            0xB16534335E502694ULL, 0x87C85A5FBDC1C0CEULL, 0x8DF068E1717FFE7AULL, 0xCF9A2E9AA414949BULL, 
            0x8CD53D00F5177788ULL, 0x2301785F577170D8ULL, 0x40B0B79868FB41A6ULL, 0x61D1C54B483C38E0ULL, 
            0xD55787483558979AULL, 0xBCE39756AFABD7A8ULL, 0x891D1BD0560700F8ULL, 0x147B4D6EC9A27ED3ULL
        },
        {
            0x5DD6B79CE07567CBULL, 0x1F42EB079DDF9276ULL, 0x5E948EE22BF9EFEBULL, 0xBAC2D32983E78384ULL, 
            0xF3DC07CB0545FF03ULL, 0x2A09ABF2E09E495CULL, 0x6E2B5CDDA3C92225ULL, 0xB23F8DD627F6DCB3ULL, 
            0xD3AAF0852DDCE094ULL, 0xB1B96DE61F2443C2ULL, 0xA1BEF63A81B45DCBULL, 0xB76D3A660DA8D677ULL, 
            0xD545D6FEF5355041ULL, 0xEF54BF6D40289B04ULL, 0x1A1A652820186861ULL, 0xF658663A13C01718ULL, 
            0x3B7AFCC653250504ULL, 0x5A9A1E5D725F2D40ULL, 0x88986A67D538C701ULL, 0xCB9574174E887015ULL, 
            0x4CC9C3C7238447B0ULL, 0x4B189D0BC89B000AULL, 0xAAFF255ACE03BFCAULL, 0xA5F708329001DB3CULL, 
            0x9690411D206B5BA1ULL, 0xFC5A11FEF840CAA9ULL, 0x5E97DBB779B5B8B8ULL, 0x45131B4506B73EFFULL, 
            0x67807C91D4A911AEULL, 0xAA867891DAEF0C7AULL, 0x9BE52962C66822FEULL, 0xEC6753AFCA401C0DULL
        },
        {
            0xD6063D6E4DAD78ECULL, 0x131055848962B693ULL, 0x4FA6D0FD6D79D65CULL, 0x66D47D3D49E0E4D3ULL, 
            0xFD38911227DFB699ULL, 0xDC85ACDCD0AB1C09ULL, 0x6892821BA796AE51ULL, 0xBC2CFEAC93427B72ULL, 
            0x61F9267C42979090ULL, 0x42B36E5F12B89587ULL, 0x3EC798934EC1B4E7ULL, 0x4F30A30C0E1ED8DBULL, 
            0x5262EC621BA40444ULL, 0x3E37ED57DE212BE6ULL, 0x690830C5AA855DAAULL, 0x2EBD82B485FA47EBULL, 
            0x1266AE68CA741301ULL, 0x1803508339FDBEF6ULL, 0xF795759FA2C402F7ULL, 0x112C2A4C397EACC8ULL, 
            0x99EA392C329F2FF9ULL, 0x9FEAE7EE2DF566CFULL, 0x7CEA0392080E9474ULL, 0xE9B44F53666F35CDULL, 
            0x98801D649A212014ULL, 0x3E5A467761FC0C3CULL, 0xA62935BED811AD7CULL, 0xD6948206D73B4178ULL, 
            0x96ABB56356C6BDD3ULL, 0x157C86433E5CBCA3ULL, 0xBAC84CC746B479D3ULL, 0x40F9537151F98CC8ULL
        },
        {
            0x3DAF5525E0C86E0DULL, 0x219C06A7733B0990ULL, 0xBCA849E9AB52396FULL, 0xCB52669F68F51BC6ULL, 
            0xA155852FD642A9E9ULL, 0x3419FB2644C250D0ULL, 0xF8EE8E19534C98CDULL, 0xADD7CD5B8DF79BF3ULL, 
            0xBCD56E94D72034B2ULL, 0xC23EECA486657D4EULL, 0x2E826680E1BCC6F0ULL, 0xCF6CFF04798B7601ULL, 
            0xC946AA221BF2A0E2ULL, 0xF0A22A97CD0DED0EULL, 0x44BB0AA54913EBEBULL, 0xEA7CAA1B94723D0DULL, 
            0xDDE291873C73D1B1ULL, 0xC149BF499EDA75F2ULL, 0xA03CBE871A28E91FULL, 0xE51BAD60755AC111ULL, 
            0x1010B570FB70E14FULL, 0x069DEB95230CE027ULL, 0xE6CB9C776E7F8FD2ULL, 0x6B8568B3A2BD8856ULL, 
            0x7FC4A450209824ADULL, 0x39070C36B84C3749ULL, 0x5F64B9C2BCF6D2E5ULL, 0x090A4B02CC856458ULL, 
            0x9B92D327A35360A3ULL, 0xB43224CF0329C559ULL, 0x172D76FCE89B81E8ULL, 0x7DE2BD776D3A6415ULL
        },
        {
            0xDBCD3EF1853C1446ULL, 0xD6621011C0DEF40CULL, 0xE39233E94FACF04BULL, 0xD20152A3778320A6ULL, 
            0x648ABE490FF93819ULL, 0x8ADFA0993F5938C6ULL, 0x0939B456549CCDC1ULL, 0xD776B1FC28ED7822ULL, 
            0x0E4C8938157C4AFCULL, 0x0A286553E023BD3DULL, 0x43307D2E3D4347EAULL, 0xDBF68C468086BF0BULL, 
            0x82AB45CCF5519338ULL, 0x9DAE3B613730554DULL, 0xF97F87EEE874432BULL, 0xFF3B1C9FCFB1BD08ULL, 
            0x30F83D51E1A32DBCULL, 0xBFF6075F3B8FDB05ULL, 0xEA08DF413B3EC6C7ULL, 0x6A1012289C4C7260ULL, 
            0xA4A1FFC7EB241382ULL, 0x67549024B8467701ULL, 0x1C210DB52D8B6085ULL, 0x194D6AAE59F541C2ULL, 
            0x6BAFD67CAC3C25B6ULL, 0x3814866A237ABADFULL, 0xC66C4C3410C30D6FULL, 0xE28CC14F7C2A27EDULL, 
            0x1FB7A4C6EA28CC8EULL, 0x43C807191D3453FEULL, 0x9A910ECB6E65E12AULL, 0xE000524E7C529784ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseAConstants = {
    0x9E55F3794CFE5BB9ULL,
    0x1648DC7B9361CCE3ULL,
    0xBF38BD0910550F5EULL,
    0x9E55F3794CFE5BB9ULL,
    0x1648DC7B9361CCE3ULL,
    0xBF38BD0910550F5EULL,
    0xBBA4E3CF5FC82D75ULL,
    0x72AB93C445830100ULL,
    0x2E,
    0x40,
    0x75,
    0x01,
    0x3C,
    0xA9,
    0x88,
    0x8D
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseBSalts = {
    {
        {
            0x4EC0072CFD7A3807ULL, 0x86DCE2ED4594E22BULL, 0x1333706721138694ULL, 0x847604204593AB69ULL, 
            0x2F00659F9491C5E3ULL, 0xF602E42C5737526FULL, 0x00106F8904CD6C81ULL, 0x0386DA31E2667167ULL, 
            0xDB85B49DF7359D0EULL, 0xC77E223061643EC5ULL, 0x8916A4CC3D776FF1ULL, 0x9B679DD84A750D43ULL, 
            0x1B8AA85C4A789BC0ULL, 0x7A74A5A96B203F4CULL, 0x8777D159EE78B62FULL, 0xFF6BD2973796C3D5ULL, 
            0xA21C9D85C1506F8CULL, 0x42A9FE1867ECE332ULL, 0xEA4FD030ADF218BAULL, 0xD47CD16F11ADBB64ULL, 
            0xD2193D632D4BD4C1ULL, 0x5A679F5D9A366C98ULL, 0xF898485C72EAC6FFULL, 0x852F4A81B8C971F3ULL, 
            0x1F6364B641FD2006ULL, 0x3D982E228C28504EULL, 0x3409FA5D42C951B4ULL, 0x342DB813258EA2FAULL, 
            0xC5C533E59411145EULL, 0x68CEA18231D8B9E5ULL, 0x1B3E43CEAEB6D36CULL, 0xFA13B32C5233E969ULL
        },
        {
            0x7EDD04127E4E7C47ULL, 0x796B312763291692ULL, 0xF82757EACDE77892ULL, 0xC7BC075FF157D2D8ULL, 
            0xB013F5C994A303B3ULL, 0xDC34A16850B140DDULL, 0xAD15A6A20BEE3B91ULL, 0x439235977A2C3FC2ULL, 
            0x77F409256FF6A7DEULL, 0x26CF78E97B3A3928ULL, 0x522AABFCD1F92D09ULL, 0x0D75AA5A856B964FULL, 
            0xE06F4413CF8D8FE8ULL, 0xD39190F1AA03F18BULL, 0xE0F9CEC3E51863BFULL, 0xD12966414D290408ULL, 
            0x43316E6935B2ADF6ULL, 0xCFFC03598DB66D86ULL, 0x6850897DC7255265ULL, 0x812FFDC3312523A7ULL, 
            0x94336ADD9FA08706ULL, 0x2F89D1FC79DF1448ULL, 0xCF9FD1C4EF55A341ULL, 0x0D49793EC981D02EULL, 
            0xD67A1CA488F5C13DULL, 0x94A97CC3EDC02E66ULL, 0xD53D20CD6C171504ULL, 0xE7DDB9894749EDB1ULL, 
            0xAFED408BA4924251ULL, 0x4A1594E0B4E5E076ULL, 0xF11C53987E516696ULL, 0xDD8B32902FCB9325ULL
        },
        {
            0xD8FFEC8249986C0FULL, 0x6C085256E8538AAEULL, 0x5971FD70DD6C51F9ULL, 0xF516F2403B75BA78ULL, 
            0xB348C9948DBD4BA4ULL, 0xB4F22A66A1CFB8B2ULL, 0x33EB403ABF5A3B5FULL, 0x22E0FB37CB675999ULL, 
            0xDD5F88D4565A1083ULL, 0x3C99FE3FD425AE68ULL, 0x2CAD4C577A1ACDE4ULL, 0xB6A868809BE68F6EULL, 
            0xF633C82220D4BB72ULL, 0x87DBCEDA3D0D2066ULL, 0x0259D889346AAEDCULL, 0xB0E4F857B5B39BB9ULL, 
            0xA6E4195479F05F73ULL, 0x500E8ACDD04AD9CEULL, 0xB9D68437D56BA660ULL, 0xD8817D52EF46E415ULL, 
            0x74C1F8FF7C546534ULL, 0x61301DCEB5534173ULL, 0x58C680D515A5ECCBULL, 0x647825EFEC0210B7ULL, 
            0x20097CB60E9C7EF2ULL, 0x5A881946802A43DFULL, 0x2A9C052E2B041B6DULL, 0x7279FD3A63C8E932ULL, 
            0xAA5B4FDB1F2EF360ULL, 0xB2643FCC6A6346E2ULL, 0x1A5DA18E807BE18DULL, 0xEC624868255D0D67ULL
        },
        {
            0xD1236D0F206943BBULL, 0x6DBDACB2A5178D00ULL, 0xF66D086A2403C6A2ULL, 0xAB27283E423D5D22ULL, 
            0x7187FDFD13BC8BD8ULL, 0x4453240BD0F7D683ULL, 0xBF44CC6FB9614D1CULL, 0x4BC811C7CF5384F0ULL, 
            0x6CB56B0D970BD7EBULL, 0xCE5934C52DB675C5ULL, 0x8C243E52F0073B91ULL, 0x447CA666DD30F04AULL, 
            0x7871D9CE954AE17EULL, 0xC38B1A018F05F7F7ULL, 0xB1D72DF1CDE5708EULL, 0xE88CA36099D52306ULL, 
            0x9D3D95943DAF67D4ULL, 0x750AC13DD6C8B44AULL, 0x054DFDB0123ADBB9ULL, 0x66FAFEDE5B0057D0ULL, 
            0x872F6E189AF55401ULL, 0x13953D85087E0446ULL, 0x95682E9B2CC98359ULL, 0x76EDADE4244C9809ULL, 
            0x0AA853BC45F90F01ULL, 0x7D1ADC59B7F9548DULL, 0x8CDDD7E989A0AC70ULL, 0xCBEA905D52FEC48AULL, 
            0xB482C436F01E61D8ULL, 0x6D37EED69792AE0CULL, 0x9F70B86D07F769A2ULL, 0x32851C3EABF0CB30ULL
        },
        {
            0xB8D5DF0BEAFF0C17ULL, 0x217DDAD26B252F97ULL, 0x05398FB34C865697ULL, 0xF53F3CC20C6621EAULL, 
            0xD3F8C90625164725ULL, 0x9867B6BA5C778045ULL, 0xE8CC37AE9F57EDA0ULL, 0x12AB16A82549F7E0ULL, 
            0x5E6FEE65B85E8D58ULL, 0x844DD1B32CA4DFF6ULL, 0x1A9E4D8456163012ULL, 0x26CB76AB01D20A97ULL, 
            0x1D794DA2810BA4B9ULL, 0x2D8E4103A019ADAAULL, 0x0D91C489284B2A9BULL, 0x2C65B773AA5954B0ULL, 
            0xEE401E967AC1729EULL, 0xEFE1FD2A3EA3CA0CULL, 0x958DB1C8AFBC66E7ULL, 0x30ACBFE625FB1904ULL, 
            0x9DDB3906F68523D5ULL, 0x695C0B8C546A26E3ULL, 0xAA5E102FF11F799FULL, 0x22B274A0316C55D3ULL, 
            0x0967AE1AA8E2BD22ULL, 0x157018D71D54071FULL, 0xC5679E6EA8A385A7ULL, 0x774B3357944734CDULL, 
            0x29E330211EB34689ULL, 0x21722D8F9DFDC75CULL, 0x301E9412AB038FACULL, 0x8A08A60D3A231EFBULL
        },
        {
            0xDA73FF5AE084E7BBULL, 0x132D720D49C3CB7DULL, 0xFC82BCB7DF0624F0ULL, 0x78B9018E093211DEULL, 
            0xAA80310CDC3151C1ULL, 0x44BC5FFE73DFD613ULL, 0xADAE863120A104C2ULL, 0x3E2D92454FB3ECC5ULL, 
            0x3DA66551E95E162AULL, 0xC2C47AC63D40FEEBULL, 0xFD2CC7E4263C7FB0ULL, 0xBEC3D74740A35415ULL, 
            0x56248AE4460B2D61ULL, 0xDDD147E6B59F90C5ULL, 0x99F41CFE5B0D4624ULL, 0xED1E8883275D0631ULL, 
            0x96D1252AB460EED6ULL, 0x3E10F27C2EC6D29AULL, 0xF32A6D6D1326D6D0ULL, 0x31D2DE40F1EB3529ULL, 
            0x254FEBA31957A557ULL, 0x3CF824103AA63DA0ULL, 0x46EF1BE6B7752A11ULL, 0xCCBFAEF59E2B183CULL, 
            0xF081BAA359AFE2ECULL, 0x7DD48F94ABD3B5B2ULL, 0x45BE3BFBF6BFF78FULL, 0x50DFCA615BDDCC59ULL, 
            0x7848641D1EB58330ULL, 0xDFB391CD6F13F34AULL, 0xF45540915319C664ULL, 0x22BA33735F9A7218ULL
        }
    },
    {
        {
            0xE1D22B15D5B60596ULL, 0x5479CD076B7757EAULL, 0xC612A42025E3D28CULL, 0x68630250265D7994ULL, 
            0x776B17F532B3749DULL, 0xA19B3BD37FA3EBBEULL, 0x984132716FA0D508ULL, 0xF26353EC95E7994AULL, 
            0x99C754457CFD0BA9ULL, 0x21340E103F69F484ULL, 0x597F4D180D85C8F7ULL, 0x9DD1231B647FDD60ULL, 
            0x3F38AA0700FC94C4ULL, 0xF48AB69C39CADC20ULL, 0xE87C5803D1467530ULL, 0xFB43EC779ADFC97FULL, 
            0x9DEAF2B0BF5E2A1FULL, 0xBAC89F04ED9AC3CAULL, 0xF46B97AB0964B821ULL, 0x84FA3B684D8DEB68ULL, 
            0xC1083F5C85A37396ULL, 0xEF9553150BEB64F8ULL, 0x904AE9FCC66195CEULL, 0xD5C876837BB4EED2ULL, 
            0xB7444F22892D17CBULL, 0x3FB82BA1B1D5659EULL, 0xC26794BF92611819ULL, 0x7C8FA5462DDA7E47ULL, 
            0xFA556ACCDF0959FAULL, 0x1E1E1867DC184570ULL, 0xF1A1941A225AF6B1ULL, 0x86B776B1D5D6C584ULL
        },
        {
            0xB6F8F51B62FA9840ULL, 0x603C4CBA942E8F76ULL, 0x948CFD86F66CC0DDULL, 0xFE614BABD797F997ULL, 
            0x8E1AA1067DA95CD4ULL, 0xF374304CA24BC19CULL, 0x320CC556BB4D627AULL, 0x54716049C9DC86DFULL, 
            0xC40CF3F38075FB25ULL, 0x20641893001138DEULL, 0xBA07F0CD8B38792BULL, 0x86FDF925C6B67BD4ULL, 
            0x6C3187DCC0D34466ULL, 0xFC2C1EFBE095D9CFULL, 0xCC748021040238B6ULL, 0x2E58CC90D953E106ULL, 
            0xEED623BD74B9A58DULL, 0xD4E331D5CF34E77DULL, 0x2F55C24895B831BBULL, 0x472791F8DBC9C156ULL, 
            0xB4A8FC4AFE44728FULL, 0xF3C4C3EE84DE7926ULL, 0xB54A116B2CAD6718ULL, 0x0CA6BF0B045CBD27ULL, 
            0x93FEA77AA5A3BFC2ULL, 0x2570E7A0D0773731ULL, 0x45E7A99D8AD04C1DULL, 0x806BA94DBD9F9349ULL, 
            0xBF9BB67D4CC58C32ULL, 0x2884A2EA23F3809FULL, 0xC15A9BFDE3B75AF4ULL, 0x846866E4B8112E7FULL
        },
        {
            0x537FAF93079D61B5ULL, 0x6ED6B94E5DB4726FULL, 0xDDAA48C53DBC9C1FULL, 0x8AAA203F6F06100EULL, 
            0xE5243DB3CDA40350ULL, 0x5DC117C3D85501A8ULL, 0x3569F19EE86FA5BFULL, 0xEA901AA3A0017034ULL, 
            0x02F81F152FEC9463ULL, 0x7C60A7B8C0FDBA71ULL, 0x71C5C14EBE82C2DFULL, 0x8EAB856B86F74827ULL, 
            0x6F9078D08BE816EBULL, 0x03EF83EB2690FFE8ULL, 0xCB7F0580454B91FEULL, 0x292ADE7D5534A4BEULL, 
            0xEBD344CEDD18F373ULL, 0x30806029C6B68883ULL, 0xCB9656E40F4D60FFULL, 0xBEA7FF6CD62D2454ULL, 
            0xA1DFBC3B3D4C969DULL, 0x3E089B45F45D45DBULL, 0xBF2C12991681DD1AULL, 0x95E196813A8040DDULL, 
            0x77AAEF7D6423637EULL, 0x3EB0A1407B6BCB4BULL, 0x081BA9E99CCCA10EULL, 0x3F6CE96EAEDF3388ULL, 
            0xA323974D3AAFFAEFULL, 0x67B1B0F76D778179ULL, 0x61C74992A8D7307CULL, 0xF3B84FE59332EDF4ULL
        },
        {
            0x410309A1C2A53F84ULL, 0xC2456BF6727F249CULL, 0x5AB044096550B3C5ULL, 0x3C1D435FCA115B8DULL, 
            0x87D9076C5C7BA926ULL, 0x68F15F2A537D0954ULL, 0x024A0AADD4044275ULL, 0xFCD3B7C6A941D500ULL, 
            0x015D94686993DBADULL, 0xB3F2E6D6C33FC973ULL, 0x31F3B49E4078FB01ULL, 0xE78595DEC1B1FAA3ULL, 
            0x6F1DF526BD272044ULL, 0x233640970C4F2BECULL, 0x23B317AC16174445ULL, 0xD496E2D4DAD5EB4BULL, 
            0xC08E71B77428A274ULL, 0xCBB48975020C8AC9ULL, 0x09B141039954BFE0ULL, 0xB8F26174601827ABULL, 
            0x39AAD74A2FFDC890ULL, 0x2E21E820C8DE2C6FULL, 0xA84DF825068C8A62ULL, 0xE0FA722BB199F5B3ULL, 
            0x91DB6517CB758386ULL, 0x3CCA6045D97008DDULL, 0x3328CBD0E3E3DE12ULL, 0xDF878D9BB939F281ULL, 
            0x3BDA23192280E43DULL, 0xC63BEB1D443BEFDAULL, 0xC7395C5C0065099DULL, 0x7C98011F723ECBCEULL
        },
        {
            0xDAA493DF35F13FB9ULL, 0x333882967304AE82ULL, 0xA8A97335B0A0B052ULL, 0x1283E4A807F045F0ULL, 
            0x2D253E9159467ED0ULL, 0x9D2EC87D71483912ULL, 0xB641A16FA19B97D9ULL, 0x6EE8552C125C2169ULL, 
            0xAD2EA136AECDD938ULL, 0x2312F190A1CC0C6EULL, 0x9C7CA7750E4A8556ULL, 0x7C39EFDBD2883618ULL, 
            0x709279CDF266938BULL, 0xFE0AA95BC322E941ULL, 0x44E497776E0FF7A6ULL, 0xCA69AF6F607B7502ULL, 
            0xD6CA03365D890704ULL, 0xD52405781FE05AA7ULL, 0x24A110D0BBCAEEE3ULL, 0x3F090E6D6DF91141ULL, 
            0xFB9CC2FB958510A2ULL, 0x109E331BC50CE98CULL, 0x72C632704657AEE0ULL, 0x61FB918B1F5EFEB1ULL, 
            0x11E391FBF890B6AAULL, 0x78EC6845D0C9E157ULL, 0x5438119D4B7EB980ULL, 0xE32E5AA7C482173EULL, 
            0x0BBB0318DF1E0160ULL, 0xE2F3B4B2C1DAA232ULL, 0xFBB9469A70DF27FCULL, 0x7427D58F72C87AABULL
        },
        {
            0xA50307C81B096622ULL, 0x8589817F9C7611ABULL, 0x86B3817846C757E0ULL, 0x5695B8AA29AC09B8ULL, 
            0x041817B9453E7F43ULL, 0xC694E3FA781BE218ULL, 0x3A6B302A81F64253ULL, 0xED66FC22529FF6D2ULL, 
            0x98777CE021BF2ED2ULL, 0x7BB87CB3D21EF19DULL, 0x5CFBC56F26F6ECBCULL, 0x352332C2FD97BE6FULL, 
            0xBD7336A25888C7E8ULL, 0x2797DD6AE0B65BF9ULL, 0x8E84A539E64E5167ULL, 0x75D80E6BB6DFE9B2ULL, 
            0x8CEE4C36AAC5969CULL, 0x2807B3F92D5B2E6FULL, 0x7827999056D2BCB0ULL, 0xF3F1F67C0AEC6BD3ULL, 
            0x6B9E1832DF10B208ULL, 0x8FB1CA78E349BF45ULL, 0x23FB371E13B9E169ULL, 0xAAB4BC1E876469AEULL, 
            0x26D5F2741D37C743ULL, 0x580B130BB03FAE2DULL, 0x9B2C372F1DF220ADULL, 0x02A16635856B973DULL, 
            0xDA48948F554E31F6ULL, 0xE4CCA95B19E76A75ULL, 0x309EE67F3B2E73D8ULL, 0xC25A3647D64BF5BFULL
        }
    },
    {
        {
            0x5FE16894758E605FULL, 0xC6CF2F57C2D7B304ULL, 0x8B10392DC7F7FA6FULL, 0xFEE18317CAFA4714ULL, 
            0x5441EBCCBE9D7D13ULL, 0x8FD9AA09993A20D6ULL, 0xA20CCA8BD8672E97ULL, 0xDDC3A6D5077BD49DULL, 
            0xA794D03339933963ULL, 0xBA0550DDA96F8196ULL, 0x06EAD0A917A433C8ULL, 0x15E78EE2E2922498ULL, 
            0x78F94C67BFF5B2DAULL, 0xEF154AA5E754B5D9ULL, 0xABB0EC367F4B733FULL, 0x3EAE2255F6912E48ULL, 
            0xDB25FCFAF9855335ULL, 0x6FDBD644D3DF0937ULL, 0xC7097EB7E4D9CDFFULL, 0x7C294F03CAA8D65EULL, 
            0xCE8973BF0AA21855ULL, 0xD5AB6E527FF766BAULL, 0x30D29D6D365355A0ULL, 0xC8CC31DB2A775DFEULL, 
            0x94505EF1DF931A8DULL, 0x0A438D07E9520103ULL, 0x8B0A67D66D0DA9A5ULL, 0x5674769FAFFAF2C1ULL, 
            0x5FB408643FA67E8AULL, 0x9C51F08378D49C0FULL, 0xBB708FA47795F7F8ULL, 0x4014D657270CD6AAULL
        },
        {
            0x6BC16A149CB5A6E6ULL, 0x8E5B00A2A31BB35DULL, 0xA0EF009B240E7644ULL, 0xD8B4211D8A3B58C8ULL, 
            0x662A069848878D05ULL, 0xEF8A85033337F694ULL, 0x2FC2E1D827B842D4ULL, 0xF3FC493923DD99A3ULL, 
            0xDE265330AF9D561BULL, 0x608DA298FE7A3F57ULL, 0xE6458D93011C4CE9ULL, 0xAC85D24CFC81DB52ULL, 
            0xB63F784AFF788645ULL, 0x9687C009D6510B67ULL, 0x11114910615A3669ULL, 0x8B60801FBB804A40ULL, 
            0x89B02A4ADB52708EULL, 0x3BDE28486B545394ULL, 0x5F2F6EFB188FC32CULL, 0xB9A460DC0974ADAAULL, 
            0x58C5C985FB828156ULL, 0xEDC3B815400A4A3EULL, 0x5B8387F556054DB1ULL, 0xCE6F73F8AD8F41FEULL, 
            0xA5A4218E8E3016C1ULL, 0xBFB1336605D0CD22ULL, 0xD6E95D30B5FF0844ULL, 0x4402F338B7926C70ULL, 
            0x745398455897B65AULL, 0x3D2486F2DD213235ULL, 0xBDFEB97DB5AD4362ULL, 0x80A4C05BAA5E4F36ULL
        },
        {
            0xE3DC5E1592F15173ULL, 0x9B6F431410A95F09ULL, 0xFEF7DDEA06519707ULL, 0xCE5725F8AD5607E9ULL, 
            0xF308BC642D74DAD4ULL, 0x0611A1FA5381D11DULL, 0x16161AB58F603F73ULL, 0x8636F654F7ADA660ULL, 
            0xDFC9C815E066882FULL, 0x7B50A19AEB92AC56ULL, 0x126B2BD266E9EE9AULL, 0xCD6F272D991FCC15ULL, 
            0x47FE21DA35B98BDCULL, 0x24ADE4E9C65245BDULL, 0x2894A8D9A20A7889ULL, 0x64FFED44E8E4AA28ULL, 
            0x30660168E3A34627ULL, 0x267CCEFAB5F71300ULL, 0xA39BB2D344F417D9ULL, 0xDEA4528039068D84ULL, 
            0xED1B71C3379AFCC0ULL, 0x2E4C281297DC955FULL, 0x02B17B7FF2A39E17ULL, 0x481B9B17BEC21036ULL, 
            0xCA7EE0B23AE0C4B9ULL, 0x984284DB21D06C66ULL, 0x7FD23D842B2299CFULL, 0x1BEF56FDBA4EEF0DULL, 
            0xAA39230F6C9BBD7EULL, 0x9B6B5D1B15E6DEA2ULL, 0xE85CA34C433BE0C6ULL, 0x0EA2E43F7548CC94ULL
        },
        {
            0x243448C5A04BEC75ULL, 0x054D350EAEAD1D14ULL, 0xCAAD67860C366C4AULL, 0xABAF605FF4D83E5AULL, 
            0x2FE0BF6FB88EBA65ULL, 0xA69F5B7EF949D4A8ULL, 0xC24D348A9476DD9CULL, 0x95A1578D8C21F77BULL, 
            0xA4ACEAE590A10877ULL, 0x1B635EE5E70856FDULL, 0xD93C9DD34DAABBAEULL, 0x05D7165B7C2A62DEULL, 
            0xC6C26012B7A0A368ULL, 0xA6A6B248BD16F141ULL, 0xBD81FB5C5A4E32C0ULL, 0xE31132C67B6C744EULL, 
            0x5C02B1DC7D971DC0ULL, 0x6B1B3153B4E3A4F7ULL, 0x6A1E61E9B132F40AULL, 0x8110F777E9F5F840ULL, 
            0x87197130D0594E4CULL, 0xF3C794AEBDDD94ECULL, 0x7E58A9E3A0307582ULL, 0x732CA080251071B0ULL, 
            0xD33A78AF8926A6B5ULL, 0x953419ADD17A6250ULL, 0xEFD5A3785973A833ULL, 0x56F6F52558C85666ULL, 
            0xB11A7D07C3B885A2ULL, 0xA2A59AC3F210685EULL, 0xFC2EB840DC4DABC3ULL, 0xCE0737CDF6DB41DFULL
        },
        {
            0x83106B8C53C9B4ABULL, 0x3AA902521A80C218ULL, 0x91D9949C6DA51C4DULL, 0x4005C1F9C0177DC8ULL, 
            0x95D913BE6FAF6972ULL, 0xA415E3A9F865E5A3ULL, 0x050AEA4208A9BDBEULL, 0x28D59E94721BAEEDULL, 
            0x3042A06C0F2EB590ULL, 0x3698EA347AA3C6E4ULL, 0xDC600EE361734B88ULL, 0x23B34582D3468B1AULL, 
            0x67A22B1B2E8283C5ULL, 0x983610F79D9E4F24ULL, 0x0E64206F81325D66ULL, 0xAA715A8B33AE260EULL, 
            0x4DE4CEB455D9DA68ULL, 0x16970629AAD95835ULL, 0xAD9F0DABEB119289ULL, 0x07A7F73E77E18432ULL, 
            0x0C9098E9928647F5ULL, 0x0CC9768AAE194E23ULL, 0x22DAA5B22CFEC406ULL, 0x059AC6F9AC49BBA4ULL, 
            0x0FC695205F223BE2ULL, 0x37481006732883FBULL, 0x8B7C604893C8DB0CULL, 0xE5C9F4569659ED67ULL, 
            0xB8087174C29D13F6ULL, 0xB12032F6565BD770ULL, 0x272FF5F2A67A1F81ULL, 0x945BA7AA6145F63DULL
        },
        {
            0xFED690B450768F2BULL, 0xE5776170D62CAB41ULL, 0x3AEDC211B11A09E4ULL, 0x699217462EB294D4ULL, 
            0xDF44E5C5A91061B7ULL, 0x346340E3CE08D3BEULL, 0xA6876A664FD74798ULL, 0x2651E0E07DC3021AULL, 
            0x5D2FCEF25782C593ULL, 0x37E3253599E6117EULL, 0x3366DCB6CF74EFB4ULL, 0x135B3E6A8FF1F3FCULL, 
            0x1DD3D5B756FC8123ULL, 0x60D1450FF30F1F01ULL, 0xD5517815A375472EULL, 0x8AFC5622ED5979ACULL, 
            0xCEE1C10C0C833560ULL, 0x54CB754E9EAA4E60ULL, 0x63024905B48D8C75ULL, 0x6C1F82D4530ACDF1ULL, 
            0x49D0FE3D0EC83C1EULL, 0x9D1CA289FE370F19ULL, 0xC67F7FFE122DA72EULL, 0x384E6817806C1938ULL, 
            0x5C8F6B73CB13B945ULL, 0xDC57D2A5D8526D54ULL, 0x72117B4CE13EA755ULL, 0xE3637CA37A65ABE1ULL, 
            0x001D80F3ED6AFB58ULL, 0xC4DA168A59FD019BULL, 0x5537DD20ECD091C8ULL, 0x08EBC153EBB818A8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseBConstants = {
    0xE97FF54BC8D00385ULL,
    0xD0A870D732D4E896ULL,
    0xCCC09BE05575D827ULL,
    0xE97FF54BC8D00385ULL,
    0xD0A870D732D4E896ULL,
    0xCCC09BE05575D827ULL,
    0x26F5C3F388FD281EULL,
    0x55B3FB722034641DULL,
    0x98,
    0xDD,
    0x49,
    0x72,
    0xA8,
    0xAD,
    0x90,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseCSalts = {
    {
        {
            0xC6F4AD10FF37A16CULL, 0xBE9EB3B3371A7176ULL, 0x41A7F61E2AE05BF2ULL, 0xC30C03081317C933ULL, 
            0x500E76E774042D04ULL, 0x3F83AA267DF82B1BULL, 0x898E101B99EF477DULL, 0xCF98C71D712DF9F0ULL, 
            0xE04DA0AB56012891ULL, 0x5612E543DD94F738ULL, 0xE8FCCC090622F803ULL, 0x4D1A5FC409A3DB92ULL, 
            0xFB0E7369DE0AE3BDULL, 0x24B3C6CEB5823C13ULL, 0x0FF2259D8D76E443ULL, 0x3742539E4091B05FULL, 
            0x9240F69679B40E74ULL, 0xF910F70F626A7720ULL, 0x94309325AB930B71ULL, 0x87CC30FA7A35A9BFULL, 
            0x00F29734ACF7A8D1ULL, 0x9FC267DE349420C9ULL, 0x023E2490EC6DC962ULL, 0xDE6AA7785DF0DA00ULL, 
            0xF0C67498A4011B15ULL, 0x41C7032DF80D096DULL, 0x08B205DF9DE66236ULL, 0x8E66B54A5CAA652FULL, 
            0xBEA45548E87116B4ULL, 0xDC059E73A2C219D8ULL, 0x101961FF1B0F6B12ULL, 0x62FBFC71AA02F934ULL
        },
        {
            0x31FF46EF88149C36ULL, 0x6347279D0BBD3673ULL, 0xAA1AD2349D101501ULL, 0x78E73DC3E20EED00ULL, 
            0x0662A65F9EA20E5BULL, 0xEAE57E771253CA14ULL, 0xFBC0F4F6417CED17ULL, 0x4D5445FC61F8092DULL, 
            0xDA0E8DBAE5AFB296ULL, 0x0937990FCE53C724ULL, 0xD1A0FB424FFAC90AULL, 0x8A440E30C21766EDULL, 
            0xF73ED8D9A405A523ULL, 0x095F11D89800A9EDULL, 0xDB3A0687EE552E17ULL, 0x0B2C4785211B0D70ULL, 
            0x48960ADE0C63B8E2ULL, 0x36C1007B139E1261ULL, 0x9546512F58A14801ULL, 0xE93ADA60AE651271ULL, 
            0x49DF88D3CA206670ULL, 0x2FBECB02AFFA1776ULL, 0x0B35E71069969550ULL, 0xBF0B07ED2DEE72F1ULL, 
            0xF69AF56F02CA5EC5ULL, 0x77EFC304961EEC1DULL, 0x7C6363F76AC423A7ULL, 0x57A981A7F9BB5750ULL, 
            0x66601029A0420E21ULL, 0xE67814CA561C73B5ULL, 0x85F6EE875873C2E8ULL, 0x6EA52632F13DD12FULL
        },
        {
            0x5048073962C6207EULL, 0x1A38C95350F39818ULL, 0x046FA1A5DEB0CE3FULL, 0x65433EA42B93E039ULL, 
            0x686EB5167A127BA7ULL, 0x3237D349418B6CF9ULL, 0x1BD73EDFB73A78C3ULL, 0x827FCCFBB3C8112AULL, 
            0x9CD4081298A49473ULL, 0xC915738EA9269C5AULL, 0xCB7589FC108CA932ULL, 0xBA68675F4ED2BE0CULL, 
            0x37B361ACD922B0DDULL, 0x3F87A80BA1035ECFULL, 0xA4227387F98A53F6ULL, 0xFE50AED09691979AULL, 
            0x8C1895C9E2457527ULL, 0xB0D1C55E1C37C4C1ULL, 0xB79E6CCC769B66C1ULL, 0x0687AD534838D3D6ULL, 
            0x1149BE99C12D8386ULL, 0x37FA363FCF4ED261ULL, 0xF6165444553FBD3EULL, 0x18AA8F8BFAA8591AULL, 
            0xAA980C4F9FAFB115ULL, 0x078ADA0CA4214942ULL, 0x2EDC7571FFBFB724ULL, 0x44B4E44C87CE2F57ULL, 
            0xF35B3EF884ED75E6ULL, 0xB6387830A0558DF0ULL, 0xEFA67EC9DB18C00EULL, 0x22AA5CA79F24FB45ULL
        },
        {
            0x94D1D372D620382CULL, 0x6F847DBCF1DC79A5ULL, 0x02A313FC2C03B71DULL, 0xEEA658E5B84DBD4FULL, 
            0xC222B1B37EBB62D0ULL, 0xE7231D06295B0F29ULL, 0x84E7107F9218704CULL, 0x9AF6EB6844A46796ULL, 
            0xE8810339F6D2C145ULL, 0x72797863FBE35A92ULL, 0x96CACF4F803293D3ULL, 0x79A03E3EF1631234ULL, 
            0x2C5033E332AFB932ULL, 0x54387BCEA5963674ULL, 0xD8DDA878AC3A1173ULL, 0xFF23CCFF8C3EDFC8ULL, 
            0x24EA6127F45A865AULL, 0xFC71DC3D3B696299ULL, 0x790C2014ADEFC3BEULL, 0x391F2569563E6C55ULL, 
            0x6C81D3E97E547BA9ULL, 0x31FFB2E2D509E20BULL, 0x4937ACF080DCD0CCULL, 0xBA55D7392F630F11ULL, 
            0xF1C791D67C546B6EULL, 0x4F9DCC8627E69024ULL, 0x2EBE170435BCA0DAULL, 0x1CE1EC565CE70754ULL, 
            0x4A6FEFD593B29A6FULL, 0x4B8B262C194439EDULL, 0x50F8A76F80909C8FULL, 0xD27A23064A12BBF6ULL
        },
        {
            0x8CD2DE96AA123D32ULL, 0x7B0F003E984C879FULL, 0xF5FDEF0313198A5CULL, 0x4E408FEC3D66707BULL, 
            0xCDA899DC1468A874ULL, 0x8A792B219FB0928DULL, 0x57DF34184548AF7BULL, 0xF7592D4F85F82467ULL, 
            0x63BB719CD2647D65ULL, 0xB9F71E06D016C105ULL, 0x0FF80E44F0D406F1ULL, 0x89A70A47614F1FD1ULL, 
            0x127B5081F34906DBULL, 0x6E6F14DB308E255AULL, 0x5A6004E40038F8C8ULL, 0x8AC379334007F69AULL, 
            0x91D2A761CCD6A52FULL, 0x7D20D5A74E90A185ULL, 0xC8DA5F20F4A39178ULL, 0x2EA3774DE0E5BF24ULL, 
            0x7BC95B37BA197387ULL, 0xCC0E1E71B2680602ULL, 0xC0409304B8171006ULL, 0xE178570A007B9AEAULL, 
            0x0824451EC6147CAAULL, 0xA1AED7DA142366E4ULL, 0x39761C045B536E2CULL, 0x909680D8C5C87534ULL, 
            0x9935C98B9FD7C95FULL, 0x7F6402B0292BB5B7ULL, 0x3EFE0416DFFF21EDULL, 0x575E0A413A63587FULL
        },
        {
            0x259EA41440F84752ULL, 0xF6C35B4E6CEDEB3CULL, 0x7011552A92BE7F9AULL, 0xC8D8333B4C683182ULL, 
            0xEC4907AF03E1B9E4ULL, 0xA8496A332048AEB4ULL, 0x20A32095779DE420ULL, 0x0E272BCBB5AC5068ULL, 
            0xC951AFBA5DF31829ULL, 0xAA222443F42285B5ULL, 0xB6B6998858E1587EULL, 0x034DB7FDF1F0554BULL, 
            0x8E88C2812C4BB24EULL, 0x53ACD423ABBA3026ULL, 0x729CF5669222B6F2ULL, 0xB2E7E69A7783E60DULL, 
            0xC374A442EB3A48E5ULL, 0x3BBC8E805498B6F8ULL, 0x36A4AC03ABDE15D5ULL, 0x4DF7D1AA1E63FC38ULL, 
            0xBDB27027720B33D1ULL, 0x7EF57BC14693FBE8ULL, 0xF719ACE762E67A8CULL, 0x9C85D8E493934B27ULL, 
            0xB5A3E40EF5695A54ULL, 0x26BD663515AA8221ULL, 0xAD4DABDE0533268EULL, 0xF1DDA7DF7470AE15ULL, 
            0x1B8B59009F87A625ULL, 0xF6464D3C915BBBD4ULL, 0xE335BBA57E3F2152ULL, 0x3BAD817E5D183757ULL
        }
    },
    {
        {
            0x01FA53EB5602453BULL, 0x632ED755D30398D2ULL, 0x208DD1E100A30332ULL, 0x05BA679FF7EC69FDULL, 
            0xFE08815174028896ULL, 0x8E7EF3B73A7E79FFULL, 0x6E610AFCA9FAEA4EULL, 0x2AF0C126D7FA4AE2ULL, 
            0x156837801E4C946EULL, 0xFF4F2189E1CED3BFULL, 0xFD53F5521114A299ULL, 0xD2F935366E2C7390ULL, 
            0xBDC6FDB30B7757BEULL, 0x38F96B1CBB2C98E3ULL, 0x8932124D5FB38CA2ULL, 0xF7DA1CF7F54E9E6EULL, 
            0x9276C9EBF39FBDADULL, 0xB6B061E9A95F1761ULL, 0x003114D5827091A8ULL, 0x3C3831FCFC2DFB3EULL, 
            0x49485A81E6AB8B4AULL, 0xE8A494540EBA9673ULL, 0x2BF839420A86293BULL, 0x678A0A062FF15B81ULL, 
            0xD24B0FA284D2BA72ULL, 0x6A9D898207414A18ULL, 0xF1B8A16BF26E5C5FULL, 0x8C77F558B89D3FB1ULL, 
            0x134EBD9060D59696ULL, 0xEEF1DAD8B4E1C9BAULL, 0x7EC48602B3D9B6B0ULL, 0xE492104D0BDC0916ULL
        },
        {
            0xAE682FA1F0C36290ULL, 0x1D65B4A3D1D40035ULL, 0x174B75E96341923FULL, 0xF8AABEAC59FBAD3DULL, 
            0x5455004B3C59F8BAULL, 0xEA0B60E33464FDBBULL, 0x1804B0A646E46651ULL, 0x65D69130BE4C02F6ULL, 
            0x6C201FA4ABE0444CULL, 0x900FD9A21E0CD3C1ULL, 0x85C21D01F46509A4ULL, 0xDA56F68BEA311D59ULL, 
            0xFBC5818881EC5A74ULL, 0xCB7B99131ADB17E2ULL, 0xBCAD9A13C8B0018EULL, 0x5993C4A6B3A78760ULL, 
            0x3D87CAD9206630AFULL, 0x0A9147F05D6101EDULL, 0xA2933D3450956591ULL, 0xC7E6F2E1271D8142ULL, 
            0xF45F249C5900063BULL, 0x1941DF13A9FDD0BAULL, 0x5D1EF28B3604B8F3ULL, 0xEE2312852C951337ULL, 
            0xFFA76FE3A26A5F32ULL, 0x6021F4686FEE902DULL, 0xC180DDDD29A9CAB2ULL, 0x62653C04886B9BF7ULL, 
            0x0799DC931C535750ULL, 0x5E0253EE9A5671A6ULL, 0x2C6BB2D161B57F7AULL, 0x65C8BE96D20A4557ULL
        },
        {
            0xA583F144A62F3655ULL, 0x10D669AE730063E1ULL, 0xFC1F8B0DCAF41D63ULL, 0x1B7998B0394078BFULL, 
            0xBDBAD26F6D0B1833ULL, 0x6C303B61552E3DBAULL, 0xCBC9623CB29C8B29ULL, 0x3C1923F54F20F025ULL, 
            0x83A19BFBF65FB31BULL, 0x345BB4CC9B29700DULL, 0x14C079F39596ED7FULL, 0x453346C8692B6660ULL, 
            0x4AFA2D0B75A4E0D3ULL, 0x6063EE6600B5C11FULL, 0x1966E212DAEE6CAFULL, 0x4FF12E7461421A14ULL, 
            0x6CA7CC02E68B6DD7ULL, 0x24C4E01092ADE6B9ULL, 0xAC2005F948498E35ULL, 0x6366985D22D115B4ULL, 
            0xF8D0A2EBB0D36B43ULL, 0x7D74A60C9E74EB89ULL, 0x2FEB3E1EAF1FE567ULL, 0x39C01F4CF23E5975ULL, 
            0xF0CB644D70E7D83EULL, 0x2316747A6DD8894AULL, 0xDD93312165EE010BULL, 0x32CC51B7CE71D419ULL, 
            0x9819494350E686B4ULL, 0x5DA153DB92794E49ULL, 0xA4D5F50FB05F7F69ULL, 0x6198224A90A1C4CEULL
        },
        {
            0x1E2F88DD0F283751ULL, 0x183B227449DF5C9EULL, 0x17E251B1127E2747ULL, 0xB5466900232AF50EULL, 
            0x7C8A471F62FF4B3AULL, 0x4519F798BAC2FB5BULL, 0xC9130DE390B031E3ULL, 0x991C39FAFCD71775ULL, 
            0xD07262311AB1CD46ULL, 0x59A831239EBC39B1ULL, 0xD5314B05FD0D63C4ULL, 0x35584B4454EB8004ULL, 
            0x0439BBCFD322460EULL, 0x9368D422B963C017ULL, 0xFF5B6574F77493DFULL, 0x6F1530819141341CULL, 
            0xB207A6BC3FF75220ULL, 0x6AF6B7AE98A21D4DULL, 0xB88CFA5F37717DC6ULL, 0xAD0721EC268D461EULL, 
            0xBAF2BDA74360AA6FULL, 0xEE5096B21768FE6CULL, 0x3994F7626B9D5FE5ULL, 0x54606DAE7C1F497EULL, 
            0x016CCA70BB9E1818ULL, 0x14CA114DEB27E24FULL, 0x5D5F2D9F9C1FF600ULL, 0x22C9D7B954D9A0F1ULL, 
            0xA091579E41A39BC6ULL, 0xD63006CD3EAC0AE2ULL, 0x799F20380768B332ULL, 0xC1685ED86CE69C4AULL
        },
        {
            0xAC1BEC07708F1361ULL, 0x58581E92264912ADULL, 0xA2B505512B0028ECULL, 0x68BCCB9CF5956BDCULL, 
            0xF4F005F2A81EF083ULL, 0xEBF757A6376D7F09ULL, 0xAD4CCD41899E6CD2ULL, 0xC6A44B990F0E57AFULL, 
            0x62E19813BF3E03D0ULL, 0x322CF7DFD88AD829ULL, 0x98FC51DB066DDC00ULL, 0x9ED328F173BA8CCEULL, 
            0x9D06E78560296D72ULL, 0x0D3300B2A902FF05ULL, 0x30AC99E2CC87750EULL, 0x28CFA0E352B7A08BULL, 
            0x4A7DED80732C99A4ULL, 0x517E0DC986348822ULL, 0x29FD6A0FA083F3D1ULL, 0x555D9416278D6142ULL, 
            0xEFAA491D6962401EULL, 0x2CB33D76E13B83FBULL, 0xE6A5D44DA3F2242CULL, 0x3A1451F64960FDB9ULL, 
            0xE709FD2459C38C99ULL, 0x67109147B052B40CULL, 0xB1823FEB30951EB1ULL, 0x83CB03F89F05C99FULL, 
            0x502F8A33A84539CFULL, 0x9AD7A08269DBD412ULL, 0xFF12158C6DDEB8ACULL, 0xF236BDC98FC42E9AULL
        },
        {
            0x85E0F4CE3DB450DFULL, 0x216E4327DEF56A2BULL, 0x5DA865A393C59670ULL, 0xD5C875928868C929ULL, 
            0x2B475B2684C61C19ULL, 0x4009D79955D5BD8BULL, 0xF54B5AD6C120ABA3ULL, 0x3ED707D4C559C73EULL, 
            0x4D4917B94E063D57ULL, 0x659EC7B12A788849ULL, 0x2F6AEDFCFA30ED4AULL, 0x9F64AF91CF979533ULL, 
            0x111D33528CEEF9BEULL, 0xEB08B8B58B9CBC93ULL, 0xFF769896F37FD102ULL, 0xCC50DA1D4EEC89BAULL, 
            0x51C297E260056E8AULL, 0xE70D9D5B4A520C84ULL, 0xE27E9718A8E7A969ULL, 0x2BB30A4D064BE02FULL, 
            0x9BFFF9DD8E3AF796ULL, 0xDAA15D381FF32DE0ULL, 0xC2B015361D4A67A0ULL, 0x28627475841F3B82ULL, 
            0x107B235DAB195D26ULL, 0xBDFD38FC54D18FB6ULL, 0x9F14BEF74A3565B6ULL, 0x03C7F1F6FF8D1257ULL, 
            0xDA23A5D11EB57BB5ULL, 0x03CA2A171657C796ULL, 0x026CD8D8EF49366DULL, 0x3A1817ADBFD32724ULL
        }
    },
    {
        {
            0x4D734A5A7928CA35ULL, 0x8335E39104E52196ULL, 0x1D0915AFB9D6CBFAULL, 0x92ECC11388498D60ULL, 
            0xC4F3A5447881CED4ULL, 0xA1157B678567C0C0ULL, 0x150E799E5447538CULL, 0xF9D8C30106C64875ULL, 
            0x1DE436D2D5661321ULL, 0x1B32271C1DB50AC5ULL, 0x9B106E127DCB49D7ULL, 0x01EBA30060F95270ULL, 
            0xE1CFAF6B73920568ULL, 0x737469311E6F0109ULL, 0x29DA2E7B5F8566A6ULL, 0xCDF131A834FFD5FAULL, 
            0x29AA169910173530ULL, 0x156E6E4F1DCC6E2BULL, 0xF454E7E7811F80E0ULL, 0xE188E97A6AAA55D0ULL, 
            0xB9C3324D3088F96FULL, 0x71EDB3646F6CFA2FULL, 0x088F981CFD10C00FULL, 0xE1629A03E82E2104ULL, 
            0x45E390AF5D94EA9CULL, 0xD01B5AA0E60FB750ULL, 0xE6BF266631A7EC55ULL, 0x891D224B4E07DA62ULL, 
            0xA6ADB1A09D9023D1ULL, 0x096531BEA26A29A1ULL, 0x4F3B654A754E17EAULL, 0x2CE97B7A5405EEF0ULL
        },
        {
            0xE1F13674B9A6E99DULL, 0x45DF7BCC00AB8051ULL, 0x038ED55B81E234D0ULL, 0xCB304F63F9097B57ULL, 
            0x513FE11F8B511336ULL, 0xBF72709BF3A3C479ULL, 0xA8811A3E611428DAULL, 0x2970DE2AD2020F6EULL, 
            0xB03365461B753E23ULL, 0x0B9789A6155866E1ULL, 0x3C9C1FD5DBCD6741ULL, 0x40E984EB24CC19C9ULL, 
            0x52C2A0FA0B07E344ULL, 0xB6813746EE2C7C15ULL, 0xBCA35AC189AE771CULL, 0x5495A87F7D1524C6ULL, 
            0x03D4200606C68049ULL, 0xD87DF8B78B54DD8BULL, 0xD744431EF1A94F16ULL, 0xE2954358826258CFULL, 
            0x4ECFF05EDF7E12C4ULL, 0x597FF72DC047964FULL, 0x426260F60A63A5A5ULL, 0x29E4E99517D485D3ULL, 
            0xEE9478969DD81988ULL, 0x64CB79B156B08E52ULL, 0x491BB21DCA498889ULL, 0x9E0B4B81FD9F0D11ULL, 
            0x37A8A5CF4410E894ULL, 0x2A7E4E88CF43098BULL, 0x6740AD9BB1A02938ULL, 0xBC1EA7785A97D669ULL
        },
        {
            0xC7814BA35D929A2CULL, 0x7F7C14BBBF95AF23ULL, 0x7F7B5354708DB74DULL, 0xE565358363CD26B4ULL, 
            0xAED56743CDD9AD80ULL, 0xE875DFF50F684719ULL, 0xB8EF3B1570B34D8BULL, 0x2F65112A406D0ABCULL, 
            0x789021D92CFD898CULL, 0x2CD3D94A397A366FULL, 0x3592C9E7ADBC3187ULL, 0xC366E395A24A9427ULL, 
            0x7BF89BCFB8ADA9DDULL, 0xD63D3A6D9D5F754CULL, 0xFD10A99C0223A6D3ULL, 0x308E576DE3683ECFULL, 
            0x6F0E2FD9108DC2FEULL, 0x7EEA98FF46E62B5EULL, 0x4FCABEC665A80E04ULL, 0xEE42B90FB7D3EBDAULL, 
            0x41A3C6DB537966DDULL, 0xC98C821BEFBD4A3EULL, 0x420A2A9D0B94951EULL, 0xDA8241E2963EC5D6ULL, 
            0x1D5CB58212127EECULL, 0x0333163010F5621CULL, 0xA48BF9FB54DB72B1ULL, 0xB61B3FE101EE0711ULL, 
            0x05B061021C1C2876ULL, 0x465CDDA58D3E007CULL, 0xF10305A50BB3046EULL, 0x0EE888258EDCB433ULL
        },
        {
            0x995A3ECB2670B4E0ULL, 0x9AFF8F97F2CAA323ULL, 0x9346244C5CA48CE8ULL, 0xCFD5956EF5EEDDD9ULL, 
            0x89BFE2ABEACF93D3ULL, 0x93AE32E92EE7B4A8ULL, 0xC531AFD27B7C0D1DULL, 0xEC90888526AA1292ULL, 
            0xBC6A5D8F6D8111BCULL, 0x4E0406BD786404AAULL, 0x9AC8B243A75D10A2ULL, 0x1631CF7DEC118A8FULL, 
            0x62E8C89F900DE0B7ULL, 0xC1725FB69EE0BB33ULL, 0xC380CA331BFC425BULL, 0x24F78D2842CE0339ULL, 
            0xCDDB2363C7B1B48FULL, 0xD27D9F10AD7E4B84ULL, 0x73ADAD341498B944ULL, 0xA8088A7E35C09D48ULL, 
            0x8326F869D208ECFDULL, 0xCA4CDC1AACD10311ULL, 0x96A0AC7ACD519F4AULL, 0xDF3F4E5B4446FC76ULL, 
            0x13FE38DE3B9DC8A9ULL, 0x2F9A0A930FAAE7D8ULL, 0xE3058908AB52028EULL, 0x46653B47E492F35CULL, 
            0xB20E49BEA6B7F7AFULL, 0xCDCE744B7E8BAC01ULL, 0x9170FF01D2A86C5FULL, 0xEEE4444D8831A290ULL
        },
        {
            0x5DB11D5B03990F34ULL, 0xBDCCEDDFDD1847EEULL, 0xBFF6631AD1E2B9A6ULL, 0xEE320460346FACC5ULL, 
            0xE9F75CD2B66AAC32ULL, 0x89DCBE687DE1C318ULL, 0x597F672644B6B514ULL, 0x9F255944163A8BB9ULL, 
            0x5C5E97CB233C5353ULL, 0xFCEE5986DF398780ULL, 0xF04CCBCCEE727A66ULL, 0xC9C8F783CAF90664ULL, 
            0xDE6411530788CE81ULL, 0xAA55C49D12FC3577ULL, 0x1D3C6ECF6D6755A7ULL, 0x9FC5A84FA146B2CDULL, 
            0xA57C16FEB422B201ULL, 0xFCD4AC2E3EBFE52DULL, 0x3089387D4289AE31ULL, 0x2C04BB28574E0799ULL, 
            0x862EC4E5C3A79FD7ULL, 0x82BA0877971689FEULL, 0x072D0CB6090F1E2FULL, 0xACC0ABDA9560D743ULL, 
            0xD954A29E2CF4E3BAULL, 0x51ACFCCAA064791DULL, 0x6215688831968BC7ULL, 0x2A6F17879AA499C4ULL, 
            0xBA7A6C03AF10E081ULL, 0x167630AD798477C3ULL, 0x7A0497762EA58285ULL, 0x5629E907A37D8C51ULL
        },
        {
            0x341AC4E8CA7D1466ULL, 0x198ECB9479611C6DULL, 0x4833EDF911727ECEULL, 0x0955E5CD4A23A3D5ULL, 
            0x09F8AF1AC1BAA065ULL, 0x6C6ADE56F8ABA0E5ULL, 0x5EF5E2BB76E41C86ULL, 0xCFD1F74F1A67C9A1ULL, 
            0x4284B75ACD7EB336ULL, 0xA0F2EDAD82F5817AULL, 0x38C498FD635DDEE3ULL, 0x2B95C1AE5261C724ULL, 
            0x4F7DF30F1AAD0BA2ULL, 0xBDFDD9F675E53454ULL, 0x787CE88B50C83372ULL, 0xD2570803831D4DD7ULL, 
            0x210B99CCB5CB1110ULL, 0xFBB3A6197A5AE8C6ULL, 0xDA96A94ADB338C59ULL, 0x637A31EA516CF984ULL, 
            0xCA684D2042992187ULL, 0xEC5243A9A7D057B2ULL, 0x4B3B5587ADDADCF4ULL, 0xDC347329E0A0EEC7ULL, 
            0xB55AA2ED13A4B3D5ULL, 0xDA86C6056B609F57ULL, 0x3725E918C73DA1F9ULL, 0x954EF0F0A8F8B69CULL, 
            0xDC01E1B6D2C45A34ULL, 0x9B4CC3E2E85CE3E4ULL, 0xE51F9C66D1B11E43ULL, 0x07513A0DEE051362ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseCConstants = {
    0xBA7F2CA55B6CE17DULL,
    0x708A14FED2D61582ULL,
    0xA8AB9EA2E42F0507ULL,
    0xBA7F2CA55B6CE17DULL,
    0x708A14FED2D61582ULL,
    0xA8AB9EA2E42F0507ULL,
    0xFE68C27484EEBA2FULL,
    0xF5B99A9C8B948D4EULL,
    0x1C,
    0xFB,
    0x68,
    0x04,
    0x37,
    0xAB,
    0x08,
    0xD7
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseDSalts = {
    {
        {
            0xCA4D776B89F79768ULL, 0x3E9FCB1E79F74071ULL, 0x0DE39ED2D6FB1EB3ULL, 0x1CF35368335E389DULL, 
            0x7135D4ADAF1CBA64ULL, 0x084BFADA281C0CF6ULL, 0xCA7ECC705AA211C2ULL, 0x80D097F967C51550ULL, 
            0xF6E97EEC73342D66ULL, 0x10336C7240544867ULL, 0xA873D3F1CB652455ULL, 0x67B02DB34E447020ULL, 
            0x33FB8964B7DA363AULL, 0x283ECB18C10815EAULL, 0xDDD16DEC47B40121ULL, 0x45E19602D78764B3ULL, 
            0x4EC0B1B5ED0BA2EDULL, 0xE4B9FC1B4C0CBA02ULL, 0xD25843CA4AACB50EULL, 0x0729086891597F6CULL, 
            0x5862FC9EDDBC03EAULL, 0x43846A227BDE9511ULL, 0x5808C56438F74A21ULL, 0xED07E4B3C52D2B7DULL, 
            0x1825737EF98888F5ULL, 0x105CB0C6517A5A34ULL, 0x73C73683AEB441F6ULL, 0x2F591863F2F50A81ULL, 
            0xB8DD0D69ADFDED8FULL, 0x9DDCFE9CEED4621EULL, 0xDD04A069CA513030ULL, 0x2EE6D6D5750ADDBBULL
        },
        {
            0x7F2E062232A172EEULL, 0xEA01863139821CDDULL, 0x8FC740CD9109E731ULL, 0x85151BAC75E8B887ULL, 
            0xE078BAC989EA72F3ULL, 0x5D7A4D77E464674FULL, 0xF228C9552BADE2CAULL, 0x2A4AB9CEC18E8DB2ULL, 
            0x2280A3D70ADE2FE8ULL, 0xD25738556C32BD5EULL, 0x811EE93B74856524ULL, 0xB2E1CCD3B55EC4EEULL, 
            0xC931E3D4E437C200ULL, 0x7973FF066CAF5DB1ULL, 0x35FE8B88205F770DULL, 0x1D2904BDBB6D8E50ULL, 
            0xDE52931574393315ULL, 0x490D9A13E010937FULL, 0x99B59EE985B5E6A0ULL, 0xE2CDF13B6923624BULL, 
            0x4281A8FE42057215ULL, 0x9495321A2ADAD920ULL, 0x0CF27D4EEF886138ULL, 0xB3D531C348D81FD6ULL, 
            0x2EFE278393731812ULL, 0xCC509F68A6DC4960ULL, 0xED1D9C9CD640DBA8ULL, 0xA19EA911DD014176ULL, 
            0xD67D0F683F2007BBULL, 0xEAF5C99A18B15CB5ULL, 0x24D5E60F371E46C5ULL, 0x8002D004AF8ADF61ULL
        },
        {
            0x2608F83A3DB6E15BULL, 0xD76236AA2D867E40ULL, 0x06A8A1D6F33B8465ULL, 0x4523CF581FEFF3D9ULL, 
            0xA14B1DA8DC535B5BULL, 0x6CE16F87F0493538ULL, 0x65A6B6931998A30CULL, 0xE93E2D3EF50D3B18ULL, 
            0x9BC63985CA8559ECULL, 0xA2460D9115516D6FULL, 0x0A0EB854C12C6D9AULL, 0x6D6B877B7B34F173ULL, 
            0x38E80B2AE2E4A710ULL, 0xD201E620E7BF5619ULL, 0xF68960454EE47242ULL, 0x82BC3D5FB7116D6BULL, 
            0x073E1DF4674A53AEULL, 0x1DBB86C855A70AB2ULL, 0x18CB8ABED294F075ULL, 0x0431A812848DB2F7ULL, 
            0x1E41A53A7150D241ULL, 0x440623E571AF1D50ULL, 0x7FB695EDF64C780CULL, 0x1C75409834384685ULL, 
            0x6CC05A59C132F16CULL, 0xDC80630EF1EDC399ULL, 0x52B669B4472E68C3ULL, 0x739B3631E5E9370BULL, 
            0x3C016D590BE0A2B8ULL, 0xDDAF17AC1F58FA44ULL, 0xB5A01990E5BB93F2ULL, 0x895F31A281C73D74ULL
        },
        {
            0xA69835D156ADA531ULL, 0x2F6AB6C9111EB2FAULL, 0x613E985CBAE672FCULL, 0xB829129A78C32B21ULL, 
            0x95ACC6E957C3851AULL, 0xCC6CE3D6E62E7A30ULL, 0x27800E2572F110E0ULL, 0x0EE5503719845863ULL, 
            0x2EDB26505F9A9E2CULL, 0x75F5E7BCE67E8E70ULL, 0x708C9ED5D8FA19EFULL, 0x856D0CAB47B401EBULL, 
            0x98DD9FB69F8ACAF2ULL, 0xB4320C0A2A6613B5ULL, 0x62C5B584BBDA5E36ULL, 0x40DF2107C0327D4CULL, 
            0x5484939F459332A4ULL, 0xB8EC91596C906E1CULL, 0x7C729528561851ECULL, 0xE31668FB7814280FULL, 
            0xC6B0F2211F1223F5ULL, 0x242004E725EAE4F2ULL, 0x23F1CCF942A82622ULL, 0x1FFBC1C4507FFB93ULL, 
            0x008AB90D684C3341ULL, 0x88081F53D4175A81ULL, 0x62C435917EF63EACULL, 0xE98A9A0DCD5F76F9ULL, 
            0x9F99960CDD186692ULL, 0xF633394B5C238781ULL, 0x93ED28BD81A47F0BULL, 0x6C296C7DB88E9ED4ULL
        },
        {
            0xF5085A1B616FF044ULL, 0xF4F2C1B458EFD175ULL, 0xC08A26C71F56923CULL, 0xD243A442A9C90F80ULL, 
            0x65F0E3771342C0A1ULL, 0x437CEF143AFF089FULL, 0x1A19B123B8F6C764ULL, 0x02EBF1518A8296C7ULL, 
            0xD37BA82F01AE6F9FULL, 0xE28126357AF1975BULL, 0xA685EECFBD3F0C19ULL, 0xE2784B246EAB7817ULL, 
            0x3EA081389D83F424ULL, 0xFB6C89DA8846DD9AULL, 0x1EE60CB90F40CAA4ULL, 0x03508AB7E0DD09D0ULL, 
            0x0D4E106EA4D020BDULL, 0xC6683510FA1E473AULL, 0xA29AFE555D0D0ADDULL, 0x2AC720376F776E0EULL, 
            0xEDDEC6CA0D6E37A8ULL, 0x85515947FD0507EDULL, 0x0379568C10EF95CCULL, 0xEB249D6458CF40E7ULL, 
            0xE230674B21BB2C42ULL, 0x9186047FF8241F71ULL, 0x69AB3F054C5C5DC2ULL, 0x78F86F2B0251C29EULL, 
            0x0D927C7A5A2EE649ULL, 0x6FFC92B50389CFD2ULL, 0xA1AA9004F9AED915ULL, 0xEA6E3BD028BF19FCULL
        },
        {
            0xF65C5C2A1FD75EA5ULL, 0x20CD9FCADED2A4F9ULL, 0xF758FF3EB482BF97ULL, 0xD7169931D1EF2465ULL, 
            0x534A183DD8DBA99EULL, 0x45409D339518777DULL, 0xCD416DD7763A86C6ULL, 0x75C9F7AB81F7073EULL, 
            0x11E083B608751075ULL, 0x2FC33716548A6EB5ULL, 0x4C1B6DE56A76B8F1ULL, 0xD5E89AA95BAB58D5ULL, 
            0xB62591BAD1B21A42ULL, 0x87D6B78040240301ULL, 0x0C2BC7EED3F77A07ULL, 0x4E1971976463647FULL, 
            0x12789E05613B902AULL, 0xE2C8B640FB63D04BULL, 0x6E8F1AC68A310FF4ULL, 0x6C8B6B6FE11813FFULL, 
            0xA552C050312087C5ULL, 0xD6362C5BBD082293ULL, 0x136301B822DBB865ULL, 0x7FC646570E49BE3FULL, 
            0x3FD13893458DF568ULL, 0xB6E9B7A6AC557FF6ULL, 0x2BE5518EEE75ACFDULL, 0xA9FD3EB0A0A83D58ULL, 
            0xCEDEFFE2FEDFEE22ULL, 0x8A28695CFD0EC808ULL, 0xA3EABD3BE859E0EBULL, 0x3ABC703794CDEE31ULL
        }
    },
    {
        {
            0xE7BB30CA70962225ULL, 0xA1170EA6E22A41A5ULL, 0x8BBBDA8AD828A919ULL, 0x5DB53E9CA44B7A48ULL, 
            0x85884393B9EA66CEULL, 0x86101005189EB02DULL, 0x52E3B70C2932E634ULL, 0x3C62187E661C7285ULL, 
            0xF458D611C3DC625DULL, 0x00479083B9CF99D1ULL, 0x62FDCE94E613800CULL, 0xACDD71AFC7E471F3ULL, 
            0xFFDF5744266F0040ULL, 0xE1F292CA5903A579ULL, 0x25DAE4D603F0555BULL, 0x057E7705E47A970EULL, 
            0x5A745E4A697BA046ULL, 0xB94D83738A079584ULL, 0x611BBB79852FE85AULL, 0xFB601F4C83764510ULL, 
            0xC9061ADFD28045BCULL, 0x2AC9A8D8FE04AD31ULL, 0xDEC5C203396D7CB9ULL, 0x1B72C39CDE8BC0DBULL, 
            0xD3D592D7122FDEEFULL, 0xA2F36F4A4C2F7833ULL, 0x1D109114DF91616DULL, 0x90D69CB8993692FCULL, 
            0x9159603592CAB3DCULL, 0xF51D767199228A56ULL, 0xD6941597889ADC98ULL, 0x1C71FF5C7ED3F02FULL
        },
        {
            0x4B97751AEF952CA9ULL, 0x94D42F484FF3A38BULL, 0xE41E6A0D5C5791D1ULL, 0x597F12C40529AD52ULL, 
            0x5263154A4328A696ULL, 0x84E49776E7519E86ULL, 0xB200EB2FFCB3571AULL, 0xD1DDD473ABA86D5CULL, 
            0xFCA91FFBBC8E7422ULL, 0xF9054771824EB67EULL, 0x38448AC6756B4B26ULL, 0xCBAFBF1AC63180A5ULL, 
            0x46492C73888B5B41ULL, 0xDDEC5CACE64EC688ULL, 0xD23CEC3C1D9C8F1FULL, 0xE9D9CB2D6F44ABA1ULL, 
            0x33EF9C1A31941D6AULL, 0x91D207CFCF4E5434ULL, 0x7B8BECF54D12AF28ULL, 0xB0B3738F0EEE7675ULL, 
            0x4AFB4C3B30F153BEULL, 0x6D0FCF8D3589BC2AULL, 0x64B05B32FBCF6E80ULL, 0x7A19F5B728E48CFDULL, 
            0x41BD000127F5C138ULL, 0xA1E38765EB3948F0ULL, 0x249062D24C767439ULL, 0x363F5CCB72D49770ULL, 
            0x2E7EE8DDB31F6353ULL, 0x56BFF4F46662D62FULL, 0xE1AB2288511793D3ULL, 0x97D3DCE228871546ULL
        },
        {
            0x2267C6E4DFAD4F6FULL, 0x0258E0B4D5869826ULL, 0x1AC989047B9D4F90ULL, 0xB6AA636D8B57BDECULL, 
            0xB85BB87D97A02B6DULL, 0x7BAD2BF902F65580ULL, 0xB197B1FA227D2FE4ULL, 0x2FF8E016B64F553BULL, 
            0xBFB4D58D4E2D06A3ULL, 0x2962055F54C69A5BULL, 0x425742C845DC7581ULL, 0x6A30789D8B1B23BDULL, 
            0x97CDEC39F8B60E38ULL, 0xABD8D410CB309D20ULL, 0xD32C0878144EA0D4ULL, 0x09580AB5B2A1BD58ULL, 
            0x6CB0650BD3247C63ULL, 0x4588CF05A16324ACULL, 0xE6766ED50BB85CDAULL, 0x888D26BD41C5AC1DULL, 
            0x87DC0FF13265820FULL, 0xFCA2FEA7AD825624ULL, 0x5473A66ED390E115ULL, 0x195EDA622FD7F812ULL, 
            0xEB79CDA10B0557DAULL, 0x7CB30F305BEAC70CULL, 0x363A7F4E5CB54DBCULL, 0x1D3FFB961A4F50DDULL, 
            0xEC422D2F2F97DA67ULL, 0x62A94D3CE43C91E3ULL, 0x68A8001EB79E11EEULL, 0x498C6B5E9216B495ULL
        },
        {
            0xD4CD11AC2469599EULL, 0x8488788C8AD461B6ULL, 0xF748FA5E05A548EDULL, 0x9720145ACDD3EC26ULL, 
            0x5877E297B797959CULL, 0x2BC41DE5BE01926BULL, 0xF2F2DFB17ADAACFEULL, 0x4FFB8E7672EDD716ULL, 
            0x4CED6805534536B5ULL, 0xFCB27B631029F999ULL, 0x0746AC9C44849C99ULL, 0xD3BB93BD8849FE93ULL, 
            0x7B507EABFC42FE47ULL, 0xD7ECB20BB93E79FCULL, 0x450CEEF249710AF3ULL, 0xC8358541BF0E1A6AULL, 
            0x887AFB11BE5798CDULL, 0xBA12CE1100FA0998ULL, 0xF10E31B97753AEB2ULL, 0x9E5E69D4DAB1BC3FULL, 
            0x0489FA93EC5DA3D1ULL, 0xCFC26E4C38C427B2ULL, 0x2DC9C794C720568FULL, 0xA48F5D527B18A53FULL, 
            0x0B16963A9B397F58ULL, 0x76F97E2405C99243ULL, 0xC5188DFC5625077FULL, 0xFCD7214B17ADC093ULL, 
            0x61FED59A79A6B892ULL, 0x98137280D93A4E0EULL, 0x3FE9BAA7FF3AF884ULL, 0x48815EF4AB089676ULL
        },
        {
            0xFAAE408B77F75B01ULL, 0xEC13173F2A8EBC88ULL, 0x5C0C3320A36119CFULL, 0x25D0AAFAF9019752ULL, 
            0x76E7CE0AD6A6D911ULL, 0xD7AE0DD917C8FE9AULL, 0xAED5D902858F078EULL, 0xAB00227391F50FE3ULL, 
            0x1CCD0F72C94BFEFDULL, 0xF97D0C4F16E10635ULL, 0xF58BE7E0BE8CB653ULL, 0xE8DB601F6584EBCFULL, 
            0x49E51C23824DD240ULL, 0xD61B618124B52104ULL, 0x6D52EFCBA6ED553BULL, 0x795B02B4BAA26E30ULL, 
            0x322C492223AF979EULL, 0xE763ACCC944A193AULL, 0xAFDBE0CC10B11F1EULL, 0x3BE6B86E476BB14AULL, 
            0xFC5E38D5098D3F7CULL, 0xEEAA8B0F1315D6BDULL, 0xB3B15CC9F912F94DULL, 0xF5622777B4A2DB55ULL, 
            0xB5B868C086885D4AULL, 0x223CA0AA63E80276ULL, 0x11528193A148FBF6ULL, 0x8431F5230B32C62BULL, 
            0x4CBD2FBF98DCB8B3ULL, 0xD5BE299944394797ULL, 0x4D28D61DC84605E0ULL, 0x4A6B1406B6BBB187ULL
        },
        {
            0x30808C2FBFFE633CULL, 0x377589ADA94E0A21ULL, 0xCB0DCF269BE4F30EULL, 0x3352C7DE5D8A62DFULL, 
            0xE889D9F8F7A779EAULL, 0xFB957FF58F9C9A29ULL, 0xA689B71F2A3A0622ULL, 0x0E862FCE0F569492ULL, 
            0x7F5911A640172AD2ULL, 0xC8F379B115F4BE13ULL, 0x1C87213B0A7FB0EEULL, 0x0E792836C27A3728ULL, 
            0xEC1A590421921A3AULL, 0x8F5BBD5E5337B629ULL, 0xC3E0B5EBE94149E7ULL, 0x68CEF92DCA5F1DF4ULL, 
            0x4EF1B134A06741F9ULL, 0x140DEC11F5B59C79ULL, 0x722606CC2A12C432ULL, 0x9B29008A164D31BBULL, 
            0x70EBBF1B8CCB480AULL, 0x24EBC41FA2754EE0ULL, 0xDD134CC58D8AD912ULL, 0xE72617671952355FULL, 
            0x28F22BDEC4F03C61ULL, 0x29EBF9B33052680FULL, 0xE82C2885BCACF5DCULL, 0x18E8D1B0BC583557ULL, 
            0xDFE5051DA56B92B6ULL, 0x635F2CA21BF4C49AULL, 0x394BD37F303FD74FULL, 0x0E65572A3E1C6DBBULL
        }
    },
    {
        {
            0x2CA2CD81FF39EFF6ULL, 0x2ABD84E9FCCDD841ULL, 0x52CFB1EBAAB24929ULL, 0x7D0175B0D0DF5455ULL, 
            0xA1D4F3274EF82ACDULL, 0x1C9E16AFA4648CD2ULL, 0x06DB4B2E84F30BA6ULL, 0x4B75B2C50F9E6C2BULL, 
            0xB82CD25940A03CF2ULL, 0x096A76E563A48CA8ULL, 0x5B8F619BCC1D8401ULL, 0xDEBB9B391035AE8AULL, 
            0x3EB3266179A2BC80ULL, 0x707BC26507857DEEULL, 0xF79814DC4BCF763CULL, 0x3364B1B67E5774B7ULL, 
            0x2C80008C1FEFD25AULL, 0xE5F33004D32457D7ULL, 0xBB141DBAE10E56C2ULL, 0x9775055EE3888402ULL, 
            0xB9D57FFC8FEF457CULL, 0xBC8A5251512607F8ULL, 0xB9EF3E3745BE2C6BULL, 0x2EBAFFEE74C3E7B0ULL, 
            0x6EE5C55B2B4216DDULL, 0x30DCAEE903F6EBE6ULL, 0x66A572681E5DA0D9ULL, 0x851B2D16C741C47FULL, 
            0x6BD720F1E28396E3ULL, 0xF9B5D8AB335597EAULL, 0xBED6E91C2D8C8D1AULL, 0xF051A880BE1DD2BEULL
        },
        {
            0xB43E67E435F18916ULL, 0x0B44372DF50BE5D9ULL, 0x5D519B9B1A91ECC0ULL, 0xC3DB23B0B46D7799ULL, 
            0x6C9AFE6FC3A65202ULL, 0xA4883FD2CC056D38ULL, 0xAF45E734A431D9ABULL, 0x864C7978AC8B0180ULL, 
            0x5B5A3B8FC88985ABULL, 0xE7DD997EE634610AULL, 0x4E639118F2E8DE5EULL, 0x9CF9B314D87F8C69ULL, 
            0x063632F0864C004EULL, 0x0331D33F75091128ULL, 0xFA8B144784DB1327ULL, 0x56E27C6AFC604E63ULL, 
            0x5ED70FCC44DC61AAULL, 0x6EECC4E12E6CE7F5ULL, 0x2F71119ACA4826E3ULL, 0x9E9C0F36210C0969ULL, 
            0xE2F4C251D2BD05C3ULL, 0x5168EAA58DB4E2CCULL, 0x24907C75FCB68189ULL, 0xD18362528BD3318BULL, 
            0xEC92B3AE5EE249B9ULL, 0xF2BE46134F49D433ULL, 0x85ACEF0A28072804ULL, 0x9C9CB0191F8FA588ULL, 
            0x930F094F032A7657ULL, 0x3FAA8DCE0091B924ULL, 0x9CDB004DFA5A76CFULL, 0x91475AC1692CA1CCULL
        },
        {
            0x5ADE05370AE1769BULL, 0x00852CF4C25EA5A6ULL, 0xB1CA6C43C04017C0ULL, 0xC2BD0306A827CED8ULL, 
            0xC4ABCD6CDAE0FD17ULL, 0x47FCEAC2D81F50FBULL, 0x246E231F6E4F6224ULL, 0x020AD5B0DFE33C40ULL, 
            0xBC78874C95C5BFA9ULL, 0x3E8C62070A258744ULL, 0x32A4571041349BCDULL, 0xB8FA3A990848448FULL, 
            0xBB5ABEF4B6DBDDF2ULL, 0x84B81381DE4F19E6ULL, 0x5D83660C81599B54ULL, 0xF93142C21B0EC29BULL, 
            0xB997143E373954ADULL, 0xBE790CCEA6B529E1ULL, 0xA143756F2E9B4573ULL, 0x9C3ADF1EE8DFE1F5ULL, 
            0x0751689DD417C7D8ULL, 0x4F77BF5DAB4E9CD7ULL, 0x8D211B1BCB529274ULL, 0x98AC0404AAB851B0ULL, 
            0x0570A8F0BFA4D880ULL, 0x951EC00348E978CFULL, 0x44C55CB551F1FF04ULL, 0xC404B120C1221212ULL, 
            0x32439CF93A7B1A4CULL, 0x3DE6554E165BB9BBULL, 0xA353428DEA9CCC2DULL, 0xEBFCC617F6D31008ULL
        },
        {
            0x1FF6076EAB8CCA60ULL, 0x5B3934B4B0DE6D72ULL, 0x7013696E843D025DULL, 0xEA8E04644C8C4B96ULL, 
            0xC95A310E11C498C2ULL, 0xB561237E2576BB1BULL, 0xC0AD6D82820B09DFULL, 0xCF60D578F251F142ULL, 
            0x3A742DF17BA3BF9CULL, 0x1B6CB55BC879E8EEULL, 0x0C965A2AC6F0CC7BULL, 0x71E4EC4ABFEC3EA0ULL, 
            0x5EBFA45EE0E13074ULL, 0x080E5399E325D15FULL, 0x722CEFEAFE938D30ULL, 0xC38A2DDC67F5CDAEULL, 
            0x5F4369D3C0E1BBB1ULL, 0x693092EDA9880FDDULL, 0x53F22D0020B979D2ULL, 0xEAAF8658751ED702ULL, 
            0x97458B6642BEEFFDULL, 0x0200E66910EE3BC3ULL, 0xCE27E3BE58DC3BAAULL, 0x8702EA9038BEA79AULL, 
            0xD39A88AB1AB2990EULL, 0x485C4BF9F414893FULL, 0xCCE41F576A37939CULL, 0x3E8823310C33E65CULL, 
            0x1C6F0A659DD2E449ULL, 0x943EF918DBEBA05EULL, 0xFBDCAEF41F5C6103ULL, 0x7D79D939DE312FE0ULL
        },
        {
            0x41FADC1E0F5F8D48ULL, 0x396E970A398D9083ULL, 0xD2812F757A277731ULL, 0xDA39B313F86FFB3AULL, 
            0x0D87AE8AB760DE76ULL, 0x40034C88FEB71471ULL, 0xE629F88F20D17CD6ULL, 0x9428F817636B9F9AULL, 
            0x2F308964FCF29087ULL, 0xA73E729A2683CF96ULL, 0xA0BCF502868C804DULL, 0x121845379C951576ULL, 
            0x4C62363DF14C653EULL, 0xC16DCC6F05019020ULL, 0xDFDD5C48B0AFEFEFULL, 0x83C2457A073AC6A8ULL, 
            0x48411CB09D392B4BULL, 0xBF1DEB22F32DC162ULL, 0x8DDF9907F3F754ECULL, 0x94498598FCABDDD0ULL, 
            0xB2D53347A9D5535BULL, 0x1E4663B1DFE60F70ULL, 0x7A18423179E9AAD4ULL, 0xB6F11A640E04A812ULL, 
            0x23F84D4334009F02ULL, 0xA8284A2544811030ULL, 0x7A274B1CB87BD1D7ULL, 0x6EF19289DC6EF571ULL, 
            0x837A98B69B068377ULL, 0xEFDED19F3D53D950ULL, 0x640C7BAB82CA2F23ULL, 0x9E1A4AEDB4AB4A2CULL
        },
        {
            0x048D5AE7821960CAULL, 0x1E2C8E2E6EA67D51ULL, 0x30915CA75644B0D6ULL, 0xC23B08D5683E4797ULL, 
            0xE5366E5CF8992262ULL, 0xBC7E23B44939DE9AULL, 0xF3E868E115A8BFCDULL, 0xC7C513CB81787652ULL, 
            0xA673B9746DC9A422ULL, 0x7F180DA7446ADCF6ULL, 0x9A94C18B0CE88725ULL, 0xEB08D4865CABFDC4ULL, 
            0x82A620EC5A691BBEULL, 0xF5B494A863F17371ULL, 0x529E6D4145E50235ULL, 0x3B606FB61CDE17FEULL, 
            0xEA391D07E5F17D5EULL, 0xAB38338C3EBB98A1ULL, 0x8C2C49A743905548ULL, 0x25C2CF59DC2CE49DULL, 
            0xE9A848E4850F7D51ULL, 0xA2DF8BE02FD81E14ULL, 0xE89FACBCE0BBA1B1ULL, 0x899347AAA15F523DULL, 
            0x22AFC716DD9CB0EBULL, 0x4EA6DDEAF186D3D3ULL, 0xD45871049EE913F6ULL, 0x17B9D0195DB5D0A3ULL, 
            0xD6B9ECAB39167D46ULL, 0xB698A675F80DA217ULL, 0x9468ECD279A00E7CULL, 0x8E1DC7C148082D84ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseDConstants = {
    0x486868A4F31E5A6CULL,
    0x3CFDAA51B3268F38ULL,
    0xC1B3256546E5C590ULL,
    0x486868A4F31E5A6CULL,
    0x3CFDAA51B3268F38ULL,
    0xC1B3256546E5C590ULL,
    0xBF8E215A8EB034E3ULL,
    0xF5D9D38C42DC0313ULL,
    0xA3,
    0x0A,
    0x5C,
    0xC2,
    0xC6,
    0xAC,
    0xB6,
    0x31
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseESalts = {
    {
        {
            0xC676ADC2DFF9003DULL, 0xD9F43D772E2BF1B8ULL, 0x054C4022B7D2EAF9ULL, 0xEF5E8DCD1061A708ULL, 
            0x42CBD72D94F3E647ULL, 0x2D4D36CB33C8EB8FULL, 0x87C9C3FF44A892F1ULL, 0x9F8A4A8BEABB2B5AULL, 
            0x757C2B8FFE22A62DULL, 0x601B603DF3F276EDULL, 0x5A37ED1D434FA655ULL, 0x408909575BC2FD85ULL, 
            0x4B3C46A60511B2EDULL, 0xB6F325C51CEEB558ULL, 0xA54C1E3AEF76DBCAULL, 0x23F5BB3092C74842ULL, 
            0xF2278A7B2A1613BBULL, 0xDEAB35AA470702F0ULL, 0xE54CB8959EE8F0CEULL, 0xC5869051D9F04888ULL, 
            0xB76F4E727BF4244AULL, 0xAC40147168CCB009ULL, 0x9CB75019BF03C7E9ULL, 0xD1F4185B3DEF7348ULL, 
            0x3907CCF078ED4B61ULL, 0xD08EBDF5963D502FULL, 0x8EF36FDD99DE9237ULL, 0x59502F9C7B4EE4D2ULL, 
            0x55E787E97A42103DULL, 0x675F2EE402FE12DDULL, 0xD154454E314507AAULL, 0x241C00346AD4A1D2ULL
        },
        {
            0x07F8A6ADCDF34D3BULL, 0x20C7D26783DED9F5ULL, 0x2F2D3FDB0EE707F2ULL, 0x336D3DE7A76AEA53ULL, 
            0x6ACF4CD75298F353ULL, 0x10187BD733F418F5ULL, 0xB061290922DC39C4ULL, 0xC802F6957BC490EAULL, 
            0xF13B9ACD6E1EA713ULL, 0x72D874D3C3B3D3A7ULL, 0x7DCA5B1A52D5C3B2ULL, 0x41F1D964AC188925ULL, 
            0xEB6B0F5AB612C144ULL, 0x3C712D05AB30D6DDULL, 0x87BFA9CE0F861C72ULL, 0xD205E958DFF57CC0ULL, 
            0xE4E51E0A1F01BFDDULL, 0x567A6663A694F3E9ULL, 0x1EC2A321FE48491DULL, 0xBB850C23F131B3EEULL, 
            0x1D25C8D59C2BF64FULL, 0x3454D123E63DB7ADULL, 0x47712512F595C47CULL, 0x18478392F650770CULL, 
            0x5D4CE458DD4C4258ULL, 0xA4F667CE06181580ULL, 0x2BEC1D25DB17693DULL, 0x41856996AB4CB2A8ULL, 
            0xFD39E4F5CA53034AULL, 0x66FE39B39643F62EULL, 0xE695C9AD270AE359ULL, 0x6E39BAC8AC2FB353ULL
        },
        {
            0x587DE45EB0B44B40ULL, 0x7CFB1A6F50B33AADULL, 0x18322A8EE3FE1888ULL, 0xA1C454BF6CF51913ULL, 
            0x5B0F104C2AFB537DULL, 0x4E366695B2E180A6ULL, 0x0244FB46B6ACD538ULL, 0x88E0F60DCB03560CULL, 
            0x03FFE12AD7EB77E7ULL, 0xA61B6D1735D201E9ULL, 0xFABD5B65A808AF80ULL, 0xAEF0E25586DAA158ULL, 
            0x268EED8337471F10ULL, 0x2FEEFDB662444675ULL, 0xAE78A85AF155D932ULL, 0xED628B3359630384ULL, 
            0x76B504D780C7E10EULL, 0x9C555B20E737EC72ULL, 0x797CD9800FDF9693ULL, 0xF0B9C7F683947E0FULL, 
            0x6B1BC27FB89B9F47ULL, 0x9CB895E281934B5DULL, 0x4F4A91B36BC13A18ULL, 0x22422FF2BB48E373ULL, 
            0x3D3892AF337456C3ULL, 0x1BF8E0C565F898C1ULL, 0xF4B89CA7FD02DCC8ULL, 0x08218160FEA65358ULL, 
            0xD71A2F9E4FA9CE1FULL, 0x8820D7969077E077ULL, 0x5699214BAABFF094ULL, 0xE39F0D0E7F886372ULL
        },
        {
            0xBD5F3EA6638DCACBULL, 0x1DF10FF4F958FA00ULL, 0xA29BD8C5E7A8E11EULL, 0xC632B09565847C2AULL, 
            0x3D580478BBF2076BULL, 0x148CB00D87C8884AULL, 0xF8857E1D292EAF3FULL, 0x265A6D23687F6366ULL, 
            0x1ADDFF14AD765AD1ULL, 0x0E0926894461E01CULL, 0xB8DE62012BD50135ULL, 0x4F33A029B9EDD47CULL, 
            0xB318D1F41507AD3CULL, 0xEF2147A0F33F0022ULL, 0x26CE43D7EF88912BULL, 0x6B9BEF090FE2715AULL, 
            0xFA9E8F87AD078C28ULL, 0x597E7918280D8153ULL, 0xAB966037A93A2D54ULL, 0xBE677605AFADDD87ULL, 
            0x6C22539A2F0BF457ULL, 0xDE9BD811A7C2319FULL, 0xD9B4B2CAF240C9BBULL, 0x6267867648B34814ULL, 
            0x69E1DA584CBE8E5EULL, 0xB6EF6761562911F1ULL, 0x7CED2826CF427981ULL, 0xC6C9AA08EB97D616ULL, 
            0xBD1499F1CA9416FEULL, 0x57C9E6346618F0A0ULL, 0x0F5D4C5A170518F2ULL, 0x0A981AB643558759ULL
        },
        {
            0x49B2B62DB8D6C7DFULL, 0x3F948BCF0A7C6DE4ULL, 0xF45991FDDF21D99BULL, 0x1828BCDDC9342838ULL, 
            0x6095D75C98450C70ULL, 0xA6B683F82D5E0A75ULL, 0x6D8F736B6BC48D9FULL, 0x79A7579F9F825FB3ULL, 
            0x6AF4245A1CDE33DEULL, 0x4F6B20892BF210E6ULL, 0xC8962E4B3A3843F5ULL, 0xF566CFE6BCF84DC0ULL, 
            0x1AADB2C68DD3ADCFULL, 0x9F9A84B6CA0E181BULL, 0xB74BE2FA1DC1E4CFULL, 0xE9C9D5D3DF24364BULL, 
            0x719BD0E73237C7BEULL, 0xF9E77AA7C877D7B9ULL, 0xF8A6C73081080176ULL, 0xB0235F89B3E2D62EULL, 
            0x2848913762548CDCULL, 0x1397494AFCEBF44CULL, 0xBE57CBE8A80315FAULL, 0x77896F59C20B5C01ULL, 
            0xBBDE7A3B16F4CED1ULL, 0x14676205DE7187F1ULL, 0x8CCFD4A3A3692C37ULL, 0x90E95BF00B367B85ULL, 
            0x482D634C5188A905ULL, 0xBF54D25CDE6BFE48ULL, 0xE5ACE5945CCE9DB2ULL, 0x575082A4A9E6B8E4ULL
        },
        {
            0xACF78641B72CB6BCULL, 0xB333BE2AB68D4656ULL, 0xFA051E9D812A36DEULL, 0x746F65D81944C895ULL, 
            0xDCBB3910C54DAF5DULL, 0xB2A724D624A9685DULL, 0x0ABD6F1EA6A5BF3BULL, 0xDA09FE13D5FBD31DULL, 
            0x3AE81346606A4448ULL, 0x497C74BFB4077351ULL, 0xD9C839B7A8C7A4A1ULL, 0x1711089074D8DE58ULL, 
            0x406CB940D0CEB57CULL, 0xE82CBDC72EEE9E16ULL, 0x97B8838732E7CE8FULL, 0xF394698AB58B0C95ULL, 
            0xAFBF439A22544B7FULL, 0x6F51C6CAD367ABC4ULL, 0x4D6A4047EC76C075ULL, 0x875ACA2E3D837C38ULL, 
            0xB5D1953FBC442955ULL, 0x42591ACE43B6B99EULL, 0x9471AF18B55CF3F6ULL, 0x1DA8909CC1A553D4ULL, 
            0xBC581855BA588DB1ULL, 0x80312B7155D6DC41ULL, 0x45569BEC3AA2A4E5ULL, 0x4DEBA0A7254EED51ULL, 
            0x258AA4D34E015A68ULL, 0xDB36CD8B6FED4301ULL, 0x52F82AF883E33858ULL, 0xD804BA9BCF37B1F8ULL
        }
    },
    {
        {
            0x8E50BBB7C82090A1ULL, 0x74459A7CA20388C2ULL, 0x5192B9183B3D14F9ULL, 0x0B014F18E39B6DEBULL, 
            0x95E50E67D3BD6CFFULL, 0x9C1AD74A5320192DULL, 0x7B31AE738E823BC5ULL, 0x9B0B0CDC8D34847AULL, 
            0x74E56FD12FB9815BULL, 0x4F12EF9FD33AE1DDULL, 0xE4930D4BAF74C6C3ULL, 0x1696B55528FBF6E0ULL, 
            0x8C171DD9B988F1D5ULL, 0xD39076A50885F605ULL, 0xF294B9C3A46CD214ULL, 0x2FF4CE99C5B6D386ULL, 
            0xBA71BB1DEA25652BULL, 0x961E6CF922380A08ULL, 0x6F56F271CA062F4EULL, 0xF67BC04B45E72506ULL, 
            0x7AB49FC3FFB7913EULL, 0xCF97072AEFF3F70CULL, 0x0A90FB70EAE0F37DULL, 0x9AAC34B766411910ULL, 
            0x770782E791F3B6E1ULL, 0x7E4029967E2CC88BULL, 0x9E0F4FE1B2A96794ULL, 0xD93BB778A72B47EDULL, 
            0xA8FA5ACBE9F285A9ULL, 0x8A6D4FF2622C638FULL, 0x5F5694949DCB1CEBULL, 0x883BFEC771A18932ULL
        },
        {
            0xAA495791C6E9C6B4ULL, 0xCAE8D09196FB9A7FULL, 0x520C1AED90ED1C0BULL, 0x19213920554E0B3AULL, 
            0x5E72C102005731ECULL, 0x0B804CB4665C4A3AULL, 0x7BC4577AD8861BA0ULL, 0xB4C9E9AE2FA9C541ULL, 
            0x946161C8C7B76E82ULL, 0xEFF1825357AD46BDULL, 0x0B9E2C852EF61DFFULL, 0x76DD5A5B786CFFB8ULL, 
            0x64E59B89058006AAULL, 0x1010CD06FBE3D7C2ULL, 0x0D66E2923D98FCBBULL, 0xC0D60A3FCE2A197BULL, 
            0xF0D53AEE44EA8BEAULL, 0x9D282496272F5AB0ULL, 0x57B0B11C30536E1EULL, 0x080BA3ED50518208ULL, 
            0xB7F117B1DB043C7CULL, 0xF473C1BD8AA58AD2ULL, 0x9A63A1A48E178FBCULL, 0x5C67380ED3D70951ULL, 
            0x682B744F12D00ACBULL, 0x03FD16CAEAC9B0ECULL, 0xB5F0F029E290DA74ULL, 0xBC8128DFAAE07748ULL, 
            0xFD94139EEC6AB9C3ULL, 0x743FA4A4BD8C099AULL, 0x2FCD835E7E0BF323ULL, 0x4B56456970A92172ULL
        },
        {
            0x52AC6970B85A22BCULL, 0x3C6B1A042B5902C6ULL, 0x701A8D2FD33F2322ULL, 0xC004B2F6C71DAB7AULL, 
            0x5255A86722322F73ULL, 0x2B0EE75E78623FC7ULL, 0x07521D745FB6A335ULL, 0x828D3D40E450A585ULL, 
            0xA3D33D0EF71347A6ULL, 0x8EC2D09E3AD854C2ULL, 0x4045029B23DB32D9ULL, 0xF690F1E650C2D9D9ULL, 
            0xB11027980B8524B1ULL, 0x33D647672F4D4F54ULL, 0x2460B74F12A044F1ULL, 0x846008849A97E2B9ULL, 
            0x5100DBC0D4FC252DULL, 0x947898F1C8FC8589ULL, 0x221233EB37C620D9ULL, 0x964444C0318D0776ULL, 
            0x91FC7DEA3060A23AULL, 0x5D7F28D15DAC5D66ULL, 0x3231E4B3A0BC65EBULL, 0x1FFF4DE4FA8CD9B9ULL, 
            0xD14A63952D7450EAULL, 0xA44C597C3D77EC30ULL, 0x0003B973CAB86BE2ULL, 0x852687339FB8A9B1ULL, 
            0x1F482964F36D1274ULL, 0xB2E1D1AD0290CE49ULL, 0x6D79AD823DA0BBF7ULL, 0x0C948765F507BD1EULL
        },
        {
            0xD2FF114A5909481DULL, 0x0951D41078D4BA6AULL, 0x890282012FD70F90ULL, 0xFD04046BEDE21B77ULL, 
            0xA063CE944CE6CF5AULL, 0x448468ED8636B382ULL, 0x51A1C892C1EAD1E6ULL, 0x84FADACEE7A143F1ULL, 
            0x24B88B86C3B2649CULL, 0xC43FCBD6E80ABB36ULL, 0x6F428BC24DB0AF2DULL, 0xC44940BC996F6E22ULL, 
            0x599C57DFF892EBC9ULL, 0xF23A3B28C59D5D97ULL, 0x343D22737B8215F8ULL, 0xBF90608E39B49921ULL, 
            0x036FF10759C3BB1BULL, 0x75ECB65002336C97ULL, 0xCC713B2935D5F869ULL, 0x260CB9FFC7561615ULL, 
            0xE246032E049C0CE6ULL, 0x43B1E7C895F6301AULL, 0x63658EC6F9DA2496ULL, 0x4934FEE4D30031B6ULL, 
            0xC186C66A53F9056EULL, 0xFD02C1F0E30D0E0CULL, 0x5F083005058DEBB5ULL, 0x73E687BFCE10323AULL, 
            0x48C19AD6C6ACA0C9ULL, 0x1615922E1A303658ULL, 0xCA660C69B657A525ULL, 0x24B3F87FDC3C9DB9ULL
        },
        {
            0x6A3B08A045903AC2ULL, 0xE7DD2CC6FBF94B18ULL, 0x67C769E69C3CE51CULL, 0xF11777AFDED5097FULL, 
            0x1BDEA5F1E2432E45ULL, 0xB3BB8786088B86B5ULL, 0xD3F529A05DE0D1E2ULL, 0xFD6C2E42943D046EULL, 
            0x7E8F6C4793D86FA3ULL, 0xE0E5602D94843036ULL, 0x88BDFCFE30749161ULL, 0xCC83D3E6C8101812ULL, 
            0x6542F27A45AC8D4DULL, 0x0789911032A9C3F5ULL, 0x92549D1CDEA3379AULL, 0xD3F4C0F4DA843E13ULL, 
            0x2C5FB013BE5F72A9ULL, 0xD60A3BE5961418A6ULL, 0x62612CD51304E21AULL, 0xD944766D4AC8A421ULL, 
            0x8418618EF0804AB6ULL, 0xA8B52F42B09BE770ULL, 0x10FA4CD42AC53732ULL, 0xFBCD715AA8BC82EBULL, 
            0xBA069BCB9517B280ULL, 0xE0B6BE0EAAD6C3D9ULL, 0x64CC89F6EB660208ULL, 0x2DFE8FE40D06D2AFULL, 
            0x465EAF782DA75468ULL, 0xE2F1F1B90A590758ULL, 0x54325C30CC759F1DULL, 0x53EC33387488659CULL
        },
        {
            0xE5A603C7180228EEULL, 0x02AE319F16F41444ULL, 0x1DA856FEC9B0C986ULL, 0x660F0BE68CA59128ULL, 
            0x4F1E98190B9062B8ULL, 0xAF859A431D665C5BULL, 0x7938BDD67DACB87BULL, 0xC85DA83E3BAC8A5EULL, 
            0x2E876BFE17A372ECULL, 0x50673020D766C983ULL, 0x5084A1CF5F92E685ULL, 0x90249BE8D5F18C9EULL, 
            0x429332530F263A7CULL, 0xB69D0758EC5567A8ULL, 0xC6F953E8ECB409DBULL, 0x97B58958ED30A058ULL, 
            0xD59136D5701C32F6ULL, 0xC37268CE539E5C0CULL, 0x6915C2355D622328ULL, 0x368A39A84C463C15ULL, 
            0xFB461FA146B29228ULL, 0x7FD8BD24C6435E16ULL, 0x84E079A6C1419B6EULL, 0x1C3CC28ACD7ADB46ULL, 
            0xE50B7EE4B2DFDD9BULL, 0x5A06C355D441F85FULL, 0x82FA7D07CB4B06E9ULL, 0xA651C34C9436CBBDULL, 
            0x0CCBDB8C24128568ULL, 0xC303330D98B676C4ULL, 0x518381A54AC61968ULL, 0xDD8B1649E9A83C29ULL
        }
    },
    {
        {
            0x7C5A596B6ED483A4ULL, 0xCF90CAA46B616D6FULL, 0xC3340FB5D91A9B4FULL, 0xACD9EBC47ED832F0ULL, 
            0x0914568F7B511504ULL, 0xB1881CDBBE1DDF8DULL, 0x6A8A753DB3FBFF2BULL, 0x4154B6A426C719F4ULL, 
            0x6A3E500D0D22762DULL, 0x12EC2F51D8023455ULL, 0x86E1BD07431CBB8BULL, 0x661483007ABF6274ULL, 
            0xB05E7FB68728314FULL, 0x66BFD3F57746D2F9ULL, 0xBEBA5DDCB254C4A6ULL, 0xF8BAAD9E9952E260ULL, 
            0xE9B9A470920BD2B9ULL, 0x563B5F630D82710CULL, 0xC618BB7ABC464092ULL, 0xC1A2D1BF24DB46A4ULL, 
            0x128C5B06BB7FF3DDULL, 0x0E684368C6C879C3ULL, 0x167D22D999BB9467ULL, 0x48ABAD8C57A15CE0ULL, 
            0x575E32D9F4C84016ULL, 0x37AB0CABD3C28094ULL, 0x01ED78D0367ABDB2ULL, 0xB715D93B84890021ULL, 
            0xA19A8776372A7745ULL, 0x0BBDCBE0E368CD4DULL, 0xBEAF5AFC2F504821ULL, 0x0E3D45446AC51106ULL
        },
        {
            0xE25646A9CF36766BULL, 0x4C4443CCE0138FCDULL, 0x2DA9855FCEFC2391ULL, 0xF9F8F3A1DBD9ED7BULL, 
            0x6D8B9D164B90DB1EULL, 0xD9DCB921AF98DA6EULL, 0xD845AAC04B221C3EULL, 0xC141A70C954B78DBULL, 
            0x31E6EDDB056F568BULL, 0x1E8BE5DBDD881CEBULL, 0x7DA058A8454D0CA8ULL, 0x725A77FCA37C8E9DULL, 
            0x2F3AF0D57F08A2F1ULL, 0x172E4ADA85654975ULL, 0x595755CCD96366A7ULL, 0x11231ADA682FB0B7ULL, 
            0x7DFED7F295349CDDULL, 0x35E3AAC2DE218883ULL, 0xD1DE54F74B138F43ULL, 0xD7AE3A47E46B0F3BULL, 
            0x909D22FAA050346DULL, 0x956182DE048FB00AULL, 0x093694541BD2F954ULL, 0x054DB5AFDC8E544CULL, 
            0xD2C727EE9D827C0FULL, 0x56ED5E493D1C0612ULL, 0xC57C7E56A0A06CBCULL, 0x3F31D04264299416ULL, 
            0xF3112FB77F9EBD74ULL, 0x32F86D4CE2C9FBD5ULL, 0xBFB078E80FD3E61FULL, 0x4D938ED251FDE8C9ULL
        },
        {
            0x16C3E97BB82112ACULL, 0x721F365F9674BD73ULL, 0x65F3B39C1CD5B8B3ULL, 0xC4CD0404220474EDULL, 
            0x47F4FAB5F43453F1ULL, 0x3026B518FE53B750ULL, 0x05522964E2D47A89ULL, 0x32CD132634B48B4AULL, 
            0x51858B87544F8C79ULL, 0xD1A1063B1679408DULL, 0x9DFDE241F7B7F106ULL, 0xB3D3A27D6D411DE4ULL, 
            0xF4923CE9E188A3BEULL, 0x53FEFAC311752489ULL, 0x88361620E949AFABULL, 0xD735AF1B23998546ULL, 
            0x46ED570933BC7CE8ULL, 0x68B42B076276556EULL, 0xFC6A602E0FF69323ULL, 0xEAEDE379F3FAA218ULL, 
            0x7C96BD05290DE6D5ULL, 0x23903A725EB92DCAULL, 0x77751F34F2C0950EULL, 0x1E136FF4FA60FA9DULL, 
            0x5DEE1A5059238F2CULL, 0xFEC359CCF846A98EULL, 0x9BB506D267152D42ULL, 0x6A36FC18C67B9543ULL, 
            0x826B84AE682B5C2AULL, 0x354A62B90689740AULL, 0xA07552622C6D6537ULL, 0x0F917EEEAEDD61B6ULL
        },
        {
            0xCCE44ED5E8BC9B63ULL, 0xAA2CBF4DD6BF0CC5ULL, 0x1CE7921D720FFA55ULL, 0x9A63E9ED9F574C41ULL, 
            0xAED46A8402465330ULL, 0x4940D599F962263AULL, 0x866A648E52D3AEA1ULL, 0x9545D4493CDBEE39ULL, 
            0x672B843EFCD745E3ULL, 0x757D619E540D16BEULL, 0xAED2AFE02E2041A6ULL, 0xFB30ECAB5E3546CAULL, 
            0x60AD2AC59116B64DULL, 0x203975BDA912CF0DULL, 0x16B2F2918EF0E624ULL, 0x35BD663588DB9A04ULL, 
            0x0AB177102C943735ULL, 0x3F9D394033878E45ULL, 0x9446F46B42928C3DULL, 0xDEA4D6BFFE862B4FULL, 
            0x0A1D973E94E3A88BULL, 0xF4AD300694B9CA27ULL, 0x220142488D1A1EFDULL, 0x240E1BA172BD8B31ULL, 
            0xADB8AA14CC9D49C3ULL, 0xAB81B3F03975EC38ULL, 0xA97C300037CFCF98ULL, 0xBC5BB8D608D0D269ULL, 
            0x4B2E3CE3F278390AULL, 0xB805F64773D6F9A9ULL, 0xA305A92CD9882C56ULL, 0xE9672246F2D3D174ULL
        },
        {
            0xD049D40066BBBA86ULL, 0x31D9898EE1B2AA18ULL, 0xA060C9B86F1CAE26ULL, 0xAD28A599BE6434BEULL, 
            0x0A8526DC1EB2BDBBULL, 0xDEE401EE81A27ED7ULL, 0x9060169B1FE93E55ULL, 0x39C925A90F40D60DULL, 
            0x808BE63A298D4438ULL, 0x3BF2BC7D632BED90ULL, 0x99EAD78F03662917ULL, 0xA3606C79C1FF7176ULL, 
            0xD41978FD81B900C9ULL, 0x414F2943C7D369F2ULL, 0x4EC4B884DCBDC0F0ULL, 0x73F0AEC43F4BCB39ULL, 
            0xF939502E7ADA93A3ULL, 0x77EC6BB1E0AF076CULL, 0x208DB21A0DED4842ULL, 0xDE8592542F11341FULL, 
            0xAA126A8FD4C0AA4DULL, 0x3C94CF73A5D5DA66ULL, 0x3461DA1E01830CC5ULL, 0xD2DDA96F27B578D7ULL, 
            0x547A7FBD83744158ULL, 0xB5CEEFF63E9079CCULL, 0xD4E9696E5EB14B55ULL, 0xD40CD27A752F4728ULL, 
            0x468C5DEC97414474ULL, 0xCB8A99967417C0A2ULL, 0xBB8DF027D8205167ULL, 0x3E1C6981DA3D440AULL
        },
        {
            0x5E92389BEE4FC5F1ULL, 0x73FE9E9E340866EBULL, 0xC31B6402D734B49AULL, 0xA039E2B7819035E2ULL, 
            0xBC40392E34ACAC92ULL, 0x6B726C8DCFAC1147ULL, 0x1B94F07EC12AB19BULL, 0x38DE6D0DFC4E8DE8ULL, 
            0xF28CCB6E8645316DULL, 0x9AE5755BA06CEBBAULL, 0xFDE53C8E02FFF46BULL, 0xDE2D38A5977EFBF7ULL, 
            0xA7ACD4B23B852316ULL, 0xC3CE58A47807F306ULL, 0x684F8C18BA131EF7ULL, 0x350783BBD01943B6ULL, 
            0x2A5B43D5DA07CC72ULL, 0x12C9B8F1F5D20A9DULL, 0xCDDBDFCEC0F3F3E8ULL, 0x5DC93FECC86E01ECULL, 
            0x797617ED2F666ABBULL, 0xA501D2EA3DD7A15BULL, 0x633CCD92B2094F6FULL, 0x3D9A51E7C0B4EA84ULL, 
            0xE5B7388A547165F2ULL, 0x87C7409C063315E8ULL, 0x989DBE2BF9E8BC7AULL, 0x8A1CAEDE8F5F4157ULL, 
            0xEA23BD34B0F2A3B2ULL, 0xF2E62FCEFADD1A37ULL, 0x6ECCE869D8785949ULL, 0x1689EC0D7E3017E5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseEConstants = {
    0xA62E898913236850ULL,
    0x2237BB0592014662ULL,
    0x9CCA473FB5D9235EULL,
    0xA62E898913236850ULL,
    0x2237BB0592014662ULL,
    0x9CCA473FB5D9235EULL,
    0xA8F659A091D57C9CULL,
    0xB51805BAE2F1061CULL,
    0xF3,
    0x74,
    0x32,
    0xEB,
    0x02,
    0x8F,
    0x15,
    0x05
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseFSalts = {
    {
        {
            0x523CF318BDDAB452ULL, 0x518130A7D2DD1ABCULL, 0xABF7F01D832EBDB1ULL, 0x0201299E82588B00ULL, 
            0x90CE9B67C045D168ULL, 0xE38D214E39A31D15ULL, 0x0A56E263A90114F8ULL, 0xF5D0EEDCD2DB578CULL, 
            0x116520E9681C64DEULL, 0xB72CEF672EF5EC1EULL, 0xA8E4D3A948C9FE9EULL, 0xA192F4F1A847BA9DULL, 
            0x562D9F92883AF3E3ULL, 0x943E95FAF79E2A04ULL, 0x4D2E5C06C61A4D1BULL, 0x3215DB2538EC6ED0ULL, 
            0xF713C8506A90BFAFULL, 0x3F8FC13CD6597B55ULL, 0xE1891A5E0132A9F9ULL, 0xA31E53DAF996EC41ULL, 
            0x871D7698ACA7B522ULL, 0x2317F3B4EED83970ULL, 0xED3BAC385888A879ULL, 0x8F7E1084758F6A6AULL, 
            0x617B87F436166184ULL, 0x785C45BA4C3ADD50ULL, 0x7B90A7D437828859ULL, 0x537BDBD72EA4D089ULL, 
            0x2CA1E3C0B2682964ULL, 0xE2591D4CD4694D86ULL, 0x9772AC3B0BB27315ULL, 0x3A1BDC3543583196ULL
        },
        {
            0xCE29F61A22EE2647ULL, 0xDE5C675159701A83ULL, 0x1B55DB1B2A3866FDULL, 0x167F6E5B17D515F5ULL, 
            0x87EF9F348CC53557ULL, 0xB21046C8B5BC51FAULL, 0xD113F0AE8D01A3B4ULL, 0xAFD4262010DC876AULL, 
            0x02FBF2B9E5EC1A54ULL, 0xA11C95D210542857ULL, 0x4ED571F90F10218AULL, 0x27BCE5EBACBAFEB8ULL, 
            0xD50E364BAF7CAEABULL, 0xBA8BBB49B0420B03ULL, 0xBEC7EEDFEE9B20F9ULL, 0x38DB4FFD037B6123ULL, 
            0x4302347745EA49FFULL, 0x139F322769562365ULL, 0x3A64172C676BB987ULL, 0x934A6940B13C7ED1ULL, 
            0x8680915BEAC67898ULL, 0xF1FD182528D1C01FULL, 0xD90EE53407AACFA4ULL, 0x545E229636265BCCULL, 
            0x2639EF4F26508EABULL, 0x1F66527308DC9794ULL, 0x019E6EC7A7EBDD83ULL, 0xE94FBD182C7C6537ULL, 
            0x0635284DD77B13C9ULL, 0xCB10C536169325BFULL, 0xD9D402BB276DEA8EULL, 0xCDA0D339B31C78DAULL
        },
        {
            0xE07EEBD72D752D57ULL, 0xA834B338EDCBBD5CULL, 0x491DFE7D361FB42EULL, 0x2A9B57EC512E99C0ULL, 
            0x7E423C1EAFEE60FCULL, 0x7B474686FDA8D4B6ULL, 0x190D313D4C3FBF6CULL, 0xEF63DC4CA64867C4ULL, 
            0x4DECA103D6DC4AC5ULL, 0xBFF83C159CF14F63ULL, 0x66279CBB50988DE3ULL, 0xC884C3C0558E02C0ULL, 
            0x8AD442F9C7FB7538ULL, 0x2C761B88E62D83DEULL, 0xE474A472B0CE6956ULL, 0x44C2D34584E7DA64ULL, 
            0xB8CF069BCE2ACFE3ULL, 0x2E38F414132313FDULL, 0x445C18D95C0DD9E9ULL, 0x0D03CC7DECC8E23EULL, 
            0x350AB7E9565A2D74ULL, 0xD16286D7E627A0C9ULL, 0xC4F4CA2F6813C00BULL, 0xA19A420DEECC92FEULL, 
            0x83D44A2BBD759DCEULL, 0x92DAC32B4D3244C1ULL, 0x0C4C837692B86CDFULL, 0xBA98FD0CCC8EAA2EULL, 
            0xD349B3C3F6731D59ULL, 0x2BF7BA8D5CE0F314ULL, 0x9185BE79D410E125ULL, 0x70365C1FDAFBC137ULL
        },
        {
            0xAEEC84183FCF1475ULL, 0x331795614826344CULL, 0x625BD807105297D7ULL, 0x5685D9F0AC93A678ULL, 
            0x2627F8B95233BCCDULL, 0xAFF338FFD2FF7C89ULL, 0x12041A489BF89756ULL, 0x2A76E97FBFDA070EULL, 
            0x5AEAA66B7E994D49ULL, 0xF91317A896D82B4AULL, 0xFCD35A2817E3324AULL, 0x4E258D87F7AACAAFULL, 
            0x94F8B667DAA4FBAAULL, 0x0A6F10A1BC923E8AULL, 0x3DF29FB33D6A0862ULL, 0x1BD49AB69600BF27ULL, 
            0x389BD834551AD3E8ULL, 0xC6465E6032513B25ULL, 0x2631EADBBE6EED45ULL, 0xC32594DB71B1C198ULL, 
            0xEF9F47D7A1B383D9ULL, 0xD82138ED86247088ULL, 0x456CC1FDCBE953E4ULL, 0xF59C6E38347A38D8ULL, 
            0x89E9598107EDEFFDULL, 0xB2D0CC5DD25FA710ULL, 0x85EABE0F614207A4ULL, 0x62A045F718CF1937ULL, 
            0x72F92DFD6196F427ULL, 0x563154BC48DFC936ULL, 0xE257C4918A631B18ULL, 0x1E4DB2F9BB58ED1AULL
        },
        {
            0xEB3BC760E24966B9ULL, 0x70F060C52B72D18FULL, 0x621F01598A799251ULL, 0xD71D843B8123FCB7ULL, 
            0x48266E1B7121E403ULL, 0xC728FCAF6C08BFE7ULL, 0xDABFAD804DBA6275ULL, 0xB7A4818571331E3AULL, 
            0x52F9CC72742EEC6EULL, 0xF463535A0B48DF66ULL, 0xE21D594B1970219CULL, 0xB5A1A30B427C29ABULL, 
            0x7D235CA07F2CE018ULL, 0x9999CC60B56ED506ULL, 0x76C4261FD1C6327EULL, 0x4C50E473EFCFA145ULL, 
            0x7EA0EF598A6ACA3DULL, 0xEF74176F34BCBFE4ULL, 0xA6549DFE86E37012ULL, 0xD1008914F1FB4BB0ULL, 
            0x90A41E74BC2BF8C6ULL, 0xB143A2A6D05D1E87ULL, 0xE14DD688586B823CULL, 0x518C930480370F26ULL, 
            0x07E86019D22E1285ULL, 0xA84373AD3D343C9DULL, 0x2ED7EA5B4F94D232ULL, 0x51071483DFC2DFD8ULL, 
            0xE98419F939308359ULL, 0xA159AE9538B844CCULL, 0x625C47FFFB7EDF4AULL, 0xA2F48A32BDD75119ULL
        },
        {
            0x2CD3688A12B2437CULL, 0x1C2FE4DC0DA4533CULL, 0x3E9FB39603D6FA70ULL, 0x9E7131BB5F7995BAULL, 
            0xC47FB0E808F6B642ULL, 0x3FDCD986A94ADA27ULL, 0xDFD30F3C8F764D66ULL, 0x6D45E46A2103F877ULL, 
            0x7566C630433B41CBULL, 0x71A1F05EF7F9166DULL, 0xAB5FBAADBB0FF698ULL, 0x7ED2132280B26D0EULL, 
            0x80095647C458073BULL, 0xDD5528CB7B209D73ULL, 0x28DEB977E3EB3DFBULL, 0x7DAC3EEB82496E38ULL, 
            0xE56380411D7F7388ULL, 0xFD5AF00EB103D471ULL, 0x083748073C024976ULL, 0x4CF71487B4EC2A63ULL, 
            0x992ECE6426E60D7CULL, 0x642103C27168D382ULL, 0xC2DF834EE57320C2ULL, 0x1BE5FA17EEA61BECULL, 
            0xDFEB476BF94D7D8FULL, 0x960E3DDD4E95CC05ULL, 0x35E289AF1494B88CULL, 0x2AE4F980C74CF572ULL, 
            0x798F48805DA1002DULL, 0x7BE1EA4D747FFD74ULL, 0x4C5A5FA07A01F495ULL, 0x61D62EF8626A6402ULL
        }
    },
    {
        {
            0x874CAAE5FE9B5FF6ULL, 0x17062BC2DEFF9EF7ULL, 0xC196EE15B5D01F58ULL, 0xDF75AF839AA75114ULL, 
            0xB7BC4922A6E1F2DBULL, 0x2C70C59C8948F4C2ULL, 0x145D193A3C20A65FULL, 0xBB97CFE691BE65CDULL, 
            0xBA8BA2F7E16EBE90ULL, 0xE63BDA5903F84F6CULL, 0xF641ED2CA71C93CEULL, 0x29977DBCB239B415ULL, 
            0xDCB5B577A1339175ULL, 0x66BADA703C837C93ULL, 0xD0E892D2B8A913E3ULL, 0x39AC454DCC3B49D4ULL, 
            0x3CBAD7B54A6B4F55ULL, 0x45E6C64D4908A96EULL, 0x0E7B502F74941A26ULL, 0x95A1BA2FA196646CULL, 
            0xFF6274DEB7A61851ULL, 0x21B40BA9EAFE2858ULL, 0x232B1CF50CEB4E3BULL, 0xDC144531D12AEB91ULL, 
            0x0500B3B00872208CULL, 0x07A75088391A0E97ULL, 0x61B49AFDDEECD225ULL, 0xB6CC062DCB310038ULL, 
            0x6208D2B8E8F963C9ULL, 0x7788F245CD417DF5ULL, 0xC61D91AE08742CEDULL, 0xDF71431D835C13C9ULL
        },
        {
            0x223786A039800BE2ULL, 0x1458C81BD0CE1EFEULL, 0x8F9C5DB7DBB24206ULL, 0xCEB1519FEC5B9FD1ULL, 
            0x445D1E63BD5D80EAULL, 0x52FE43E52AA675DAULL, 0x478E79966DB95CFBULL, 0xFB0DF8ABEF1A3F3EULL, 
            0x24D9846C69687CC2ULL, 0x9B289C1FF4A8DE17ULL, 0x4F0F132014FEE3B4ULL, 0x2FC9B01FB856A6A4ULL, 
            0x9C4DF35B24512821ULL, 0x7A33CAE7830B1E39ULL, 0x71C098B1A9DA8CCDULL, 0x5E13DEEC666C7874ULL, 
            0xCB557019C5FF1F76ULL, 0x04944A9EC11EA7A2ULL, 0xEB0F951DA998BE3CULL, 0x1C8926F9ECB413E4ULL, 
            0x0D24FC06964EFD0CULL, 0x611E6DFB9E8A0F95ULL, 0xBB47BD57AC46F151ULL, 0xCA9B84598460BCE4ULL, 
            0x967E0ECF4B2EBEDEULL, 0x43175CED1D207F37ULL, 0xA11596DBA9B9277EULL, 0xCA87656C83EB544EULL, 
            0xDAA5426CDDECC961ULL, 0xCDEC6289FD7D4439ULL, 0x8CC5FE952912EA30ULL, 0x6EF7047E0125590AULL
        },
        {
            0x6B4A8DEA07EFB7E0ULL, 0x3D1FAACDAAA66104ULL, 0xC6A37B14D648F83EULL, 0x6AB8DB47CFCBF04AULL, 
            0x7C08D5F04E628FB4ULL, 0xB5CCC5FA632C207CULL, 0x8ABC236A6FC20C86ULL, 0xFDC413050C122E84ULL, 
            0x8674488105D12CA3ULL, 0xFD2345417BD07BCCULL, 0xDDE827F7D8EFF623ULL, 0xEFA7D872ED7A9A55ULL, 
            0xA6C2CF912CA01881ULL, 0xFBA9F6175957AB04ULL, 0x160BAA5F8A4614CDULL, 0x5C10E288B98876E0ULL, 
            0xA26C8FAAD83F591FULL, 0x97CB72A0FA54EBF1ULL, 0x7C7D7C872F35E40CULL, 0x55F2FC015DB4E785ULL, 
            0x73791AEB35F0F195ULL, 0xF6DC30D06BA6014CULL, 0xA2D90C45D9D2DCDCULL, 0x488CB1385C68E7D9ULL, 
            0x54B823DF6AA5556FULL, 0x8B0AD699DD44CC14ULL, 0x1A2DE93264139BE9ULL, 0xE5FED7D10DD38572ULL, 
            0xB77541C0E37F0E0BULL, 0xF78090ED38653740ULL, 0x89BE4634C1BBD0E0ULL, 0x786E8B7D169F18BDULL
        },
        {
            0xE821F27E32E334A9ULL, 0x1DCABD124230AEB1ULL, 0x9F589D0F24D4D097ULL, 0x9C5C3EA1F84B92D3ULL, 
            0x2C6D511709387FDFULL, 0xCFBDD1ACA56B57F8ULL, 0x5FF792C7CE15DB25ULL, 0x4301AC37BF301EC2ULL, 
            0x17196CCCB8F43818ULL, 0xD67CBB2873D8D6F7ULL, 0x0DF9C8A955CB9607ULL, 0x900FB53308971139ULL, 
            0xE8D6C3D8B0506FBFULL, 0xACBE708F9D696EBDULL, 0xC5ADC31B07AAFE3DULL, 0xC0798CBCD9D9FC84ULL, 
            0x4BF997046DBF48F8ULL, 0xB8432617193AB778ULL, 0x699EBF3FF5D934D8ULL, 0x24D3F28E0E27B4E1ULL, 
            0x5372CDC42693F16BULL, 0xB7B2126911F284DEULL, 0xBF519EB97C6517E4ULL, 0x38C0D32BE21189F4ULL, 
            0xD0BA381A08A09D31ULL, 0x156DE734FF180783ULL, 0xC18BA011C7A78831ULL, 0x127C6729CF0CF3E7ULL, 
            0x64BDF05EE0EFACBFULL, 0x98AFCD16AA87DA8CULL, 0xE43EC1E08E78187EULL, 0xFE9E9A55487C5287ULL
        },
        {
            0x3F1276160F20DB3CULL, 0xE87C0A920F31C06BULL, 0x939A19E629E17EE9ULL, 0x4F9E99015A8290D0ULL, 
            0x02F649E8421917C8ULL, 0xA4C87B4AC72DC1D2ULL, 0xBBE83DFF26B72E3AULL, 0x93E26B5FAA502503ULL, 
            0xC227FEF16557F0CFULL, 0x3092BF1A6187C508ULL, 0x948E171851FA6208ULL, 0x7580A8DD8CA769DBULL, 
            0x9DA2F934C91277F4ULL, 0x7223264287AD0629ULL, 0x5BCD729D1AEB31B3ULL, 0x489766E016D81582ULL, 
            0x251040470CB125E6ULL, 0x304DE6B20BB6D86DULL, 0x15F425C366C55BE6ULL, 0x7636FAEB81F05EF9ULL, 
            0x37683BA23692BC5CULL, 0x7513AEABCBD62872ULL, 0xF7CDCC1A2D7EC15CULL, 0x27B4EBCD37807C19ULL, 
            0x57C03D4B836F44A2ULL, 0x504ACDC3293F7688ULL, 0x26F1C795116B995BULL, 0x14FE7DE2346087C1ULL, 
            0x81E1362850769C01ULL, 0xBE37C379E4E48BB9ULL, 0x389FA80D75C22520ULL, 0x51C35A009914F2CEULL
        },
        {
            0xDDA5A57E0CC7869DULL, 0x0BBEA4B188BA78F9ULL, 0x5AA0E7FE2AA1757CULL, 0xBE941062505DC74EULL, 
            0x481DAC41F76DBCE6ULL, 0xFB8F0674147E702EULL, 0xA21CDDCCDA65439FULL, 0xBA85E9305F52775FULL, 
            0x177C02433B2A0996ULL, 0x146C7588EA28A833ULL, 0x275ADEAC353A2A27ULL, 0x498C7495985AE271ULL, 
            0x86C2C30333A67433ULL, 0x37C7487A2FEE0E34ULL, 0xC5CBB75487203C84ULL, 0x11036BA56294D8CAULL, 
            0xF105D54A139A41FAULL, 0xF915355DCF671E77ULL, 0x9CD54D34FB17445AULL, 0xB9221FBC4224AD6CULL, 
            0x35A9D03A2B4E5712ULL, 0x7682F16ABD325698ULL, 0x773B2A6514872932ULL, 0xD7AFAFA78701EE64ULL, 
            0x6019B4A51F94CDD9ULL, 0x6D723A0A75A55D83ULL, 0xE4B3B31FCA372F10ULL, 0x901C4737872D7F89ULL, 
            0x2C5CB0EF8F547D5FULL, 0xA14709D2909B73FBULL, 0xE32BAB0E17C2EE49ULL, 0x8748293708AC15CFULL
        }
    },
    {
        {
            0x800F955FF990361BULL, 0xCC42C928F4F96A4AULL, 0x645ACA1B2D04CBDDULL, 0x49D9A5AB59388231ULL, 
            0x76BA8AEFC3819947ULL, 0xCA33972C3B02ED40ULL, 0xC6BBC094755EC794ULL, 0x3F4BECC08A4F3822ULL, 
            0x935D8443FDFBAE23ULL, 0x1F66C307A382B6E2ULL, 0xFE2F1E67E52306EFULL, 0x6C75984A8243DC8CULL, 
            0x171EDE4911C1534CULL, 0xFDA55BB9BE3B6030ULL, 0xA01BDB894D7FEAE6ULL, 0xF66EFF856200E007ULL, 
            0xE56828781E92F972ULL, 0x3A68E307D0E11253ULL, 0x78098E343F4F8318ULL, 0x557FAAFA720F16B2ULL, 
            0x4E95288731868F8BULL, 0x3C9DC57CE1533576ULL, 0x8ACA905EA57440C9ULL, 0xCB4C8521BAD5C3B4ULL, 
            0x36115A0EDE4F8FCDULL, 0x39E8C9A93E401F9BULL, 0x2DA887ECBED103E2ULL, 0x273F870CD68DFED2ULL, 
            0x5FDC3D112A589310ULL, 0xB6CDBAC38B189DC9ULL, 0x0900415402F91BD0ULL, 0x1E003BE04577EB33ULL
        },
        {
            0xC2EA3C03256FC256ULL, 0x82D45BB09621FE6FULL, 0x22CF652FD498B443ULL, 0x7C2CCCA7F9029155ULL, 
            0x8BD22C435C90423DULL, 0x025C014283206396ULL, 0x8176DA8FF5459436ULL, 0xCAA71A85D7B219D6ULL, 
            0x55DD666D842D5ACCULL, 0x64A4D19C9EC3C1AEULL, 0x53C51BD87AC76CE7ULL, 0x0F5D28446BE2E265ULL, 
            0x9DA93E9F0EC092EDULL, 0x251EB0BCAD5F467EULL, 0x120404EA818C7220ULL, 0x015B3880E7436517ULL, 
            0xF5556595E9638AAFULL, 0xD32D85F80C8D3DDCULL, 0xB56A386B342FD03FULL, 0x35FF11A8363288AEULL, 
            0x1FE8D93F7282EF91ULL, 0x7BF62BEFC116C71AULL, 0x0221B498C288F3B4ULL, 0xD70178A4C581D461ULL, 
            0x40513C1FA56E0F86ULL, 0x833BC43F67D1AD1AULL, 0x541169549772C1C5ULL, 0x5B23F904B9D5FAA2ULL, 
            0x8A2C9DB748734F00ULL, 0x02D7CBCAA189C694ULL, 0x8B81F0D1D630C367ULL, 0xBD417460C600541BULL
        },
        {
            0x2DD22C58EF75C437ULL, 0x5190F61FBFBFC7BFULL, 0x32699B84E1F1E69AULL, 0x70A8020042EF7E33ULL, 
            0x6DA771B106C67421ULL, 0x53EAE8D4BF91DEB0ULL, 0xEF846335F602F54BULL, 0x1E449A609D0C97D5ULL, 
            0x34A105BA3406AEDBULL, 0x67A8C8CB756DB641ULL, 0x6FA07BDA924A2778ULL, 0x3633AF61B42C78D7ULL, 
            0xA2EF46549711069CULL, 0x6AEEB8B8A782919FULL, 0xF12B22B75B489824ULL, 0xFEC01DFFF98F578FULL, 
            0x181813787589AA8BULL, 0x2ED6956DE5277B12ULL, 0xFF0A87162FA03D83ULL, 0xFA3EF28297C0E785ULL, 
            0x727596D60A4060C6ULL, 0xB47E63C4687C63A1ULL, 0x8375F40C0D418F1DULL, 0x3E30B5EDE7E14DE9ULL, 
            0x1E872FFCFB80F298ULL, 0x26A1ED193472B200ULL, 0xF22FD69C1A9D4279ULL, 0x9311D55D3D497F1DULL, 
            0x18C50CDC660420E8ULL, 0xF0646DADB2A0BEB3ULL, 0xE0134115E3BB4406ULL, 0xBB515D7947E6A664ULL
        },
        {
            0xD9A4CA6AC7EC01BDULL, 0xA1C87959B42D5DDDULL, 0x0741793F06DDF87CULL, 0x97BEA813787D8F9DULL, 
            0x37B45601C44C892EULL, 0x03C1C6DDCDF3865FULL, 0xDF7DFF99AE9A611DULL, 0x6C995BB3E04D3BC4ULL, 
            0x22F9E5B072240E84ULL, 0xFD00B64F358BF4F0ULL, 0xF6CAF59BF47335DDULL, 0x7BB1CD151BE91151ULL, 
            0xD005A4C2484F730FULL, 0xDAF57A9EC2EF0A4CULL, 0xCF6A795EBF4D39A3ULL, 0x448A803DE1854B2DULL, 
            0x3BD052E58A4C68F1ULL, 0xBC325F28F0EB893AULL, 0x9986BA29E3542915ULL, 0x0AAE6F2B1C38400DULL, 
            0xEEF8637ADD21818CULL, 0x668D0E24EFBE1DEFULL, 0xC17D34AA625DAA98ULL, 0x5CCCEB671625B117ULL, 
            0xA8A9846121E9A60DULL, 0x0F5A9D19BF4EF025ULL, 0x25490555826DA908ULL, 0xF0564682341F51CEULL, 
            0x853D3C1115BC62A1ULL, 0x2D6D3F44CEBC1ED5ULL, 0x8E91CDB442AC45FEULL, 0xCEE921EF68EEB27CULL
        },
        {
            0x6D908E5EC6C0E3EFULL, 0xDCBFD8031DF2B9ACULL, 0xDBB457616E28A579ULL, 0x406B9AC03E6820DCULL, 
            0xEC4D8B15DAB28360ULL, 0xB2730B55CEE90D8BULL, 0x96577668112D1F1AULL, 0x907BAECF9EFBC418ULL, 
            0xA4ABEBF4B7AD84CAULL, 0x5EFE397F6AEFC98BULL, 0x86097BA20942F10DULL, 0xD4068A92FF6635EFULL, 
            0x894051A6D51FCD7EULL, 0xD874653B3B8653C2ULL, 0x970A7EBE9C02FA97ULL, 0x8501E868DFD41AF6ULL, 
            0x075ED98422B0C1E8ULL, 0xBFAE1F152F3957D5ULL, 0x03F03B3E50EF99ACULL, 0xF9F5DB777F002DD0ULL, 
            0x80AA7145F8BA7F97ULL, 0xDA43BF131D24129EULL, 0x0801DABAE8FB617CULL, 0xE8E30987F435E25CULL, 
            0xB142A7047241A80AULL, 0x2B16D6025C8368F8ULL, 0x0CBFFA87A0C2CF0BULL, 0x9340EC5BCE60FC0DULL, 
            0xEA02545009196569ULL, 0x125E5869106EF345ULL, 0x9EEB03EA52622DE0ULL, 0xF76B44E6C9A7D74AULL
        },
        {
            0x31C324CF5F3887ABULL, 0xEF5D248B978127F0ULL, 0xDDEE622A89F0F8A5ULL, 0x292A9881FF431605ULL, 
            0x5A97AD79BE03842AULL, 0x2677CF62025E3DB4ULL, 0xBFACE058DCA1601CULL, 0x3C415F36AC30E3EAULL, 
            0xD16B0332453A4526ULL, 0x8F92F3CFF7F6E0DCULL, 0x7B3AFF7A884E736FULL, 0x22A35944DBF20ACDULL, 
            0x19B6543104B43EC4ULL, 0x22C24095C2637D38ULL, 0xD02E08BAFFCAC557ULL, 0x3DCD12CC796A76D2ULL, 
            0x83B6E4402A0A447DULL, 0xE1370E2D62424A3EULL, 0x038F01577DF0918FULL, 0xBC0875D6E96A25C8ULL, 
            0xED744B7DFBBDD137ULL, 0x8F7E06099B2EE5F6ULL, 0x331325A3553C717BULL, 0xCBE9D4CF40FD1740ULL, 
            0xE3B5DA069C668B7DULL, 0x12E52AE48CFA4C60ULL, 0xA408ED11B4467701ULL, 0x90BABDB7BE204E65ULL, 
            0x808147A38DC40D09ULL, 0x8EA10B3ABA6A7BD1ULL, 0x01AAE534F555FC43ULL, 0xB325505225E56C86ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseFConstants = {
    0xEB1F1EEE10E88CD6ULL,
    0x0D866D87179DC5C7ULL,
    0x8541CD1ACB8D66E9ULL,
    0xEB1F1EEE10E88CD6ULL,
    0x0D866D87179DC5C7ULL,
    0x8541CD1ACB8D66E9ULL,
    0x4D449EC91D670409ULL,
    0x8FC763C0963ED229ULL,
    0xE1,
    0x9D,
    0xD4,
    0x8A,
    0x34,
    0x42,
    0xF6,
    0xC5
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseGSalts = {
    {
        {
            0xB0D6990F5CB5A1CFULL, 0x454D1488CDDEFAD3ULL, 0x3F80365755F0CBEDULL, 0x188186ED9017DE46ULL, 
            0x41FA298590E307FFULL, 0x322CF2BCEF653482ULL, 0x4B9AC98E0E24325DULL, 0x8EE36B7485E5B27FULL, 
            0xCEC164D1DBB57D2FULL, 0xB7D98DE604AF417AULL, 0x8D54A796C3AF3D0CULL, 0x20797C44AD398E3AULL, 
            0xD541FFE1858061A8ULL, 0x6AFDDCA1D5BCDC1EULL, 0x2513C9BABD0D5F7EULL, 0xBD0C5829B186C77BULL, 
            0x07CB680F3ADAAED3ULL, 0x207CB16D11DE3B63ULL, 0x210A02B28208D3EDULL, 0x5EB126447753DE1FULL, 
            0x9A7DED0DF4E6B053ULL, 0x11DC63D6993E6800ULL, 0x4270F8FD3584849AULL, 0x1E25453EC95A20D6ULL, 
            0x6F99939A50BDF82FULL, 0x88747D08006803DBULL, 0xBC190F6A1643B908ULL, 0xFF9FC23CE0D6F03BULL, 
            0x4E13C32B7C1BCA40ULL, 0xA9B1453BBD4A734EULL, 0x4EEE280EB8B3E57BULL, 0xB8CB43F0127E919CULL
        },
        {
            0x449F6B2E07D284FAULL, 0xA37615C47A0F46B3ULL, 0x004AF71962F70016ULL, 0xFA2258CB16D39B53ULL, 
            0x78CFD8845D98C043ULL, 0x25CD7120A66BB35EULL, 0x452A235881ED210CULL, 0x8EA6FF2920977C73ULL, 
            0x97274F085802CB71ULL, 0xAEB9191AE937F57DULL, 0x1099D0F79143FEF6ULL, 0x3EF429F91689C0EDULL, 
            0xDB41C35A1165286DULL, 0xE8456C1685D08540ULL, 0xA654BBA3144D15D4ULL, 0xB0D0AE7BA15DD788ULL, 
            0x0BD304D7C090D2D0ULL, 0xCD0647A4F9FBB010ULL, 0x5C5F3AD78A9CC894ULL, 0x325F7085D7129B07ULL, 
            0xE23C8C42238200EDULL, 0xA0EA8D773DBAE449ULL, 0xB8965F638F5B75E6ULL, 0xFCC9B88A2851112CULL, 
            0x0E73C1C27D9C329BULL, 0x1E0A6F5F36A95287ULL, 0x8FCACADD365127B1ULL, 0x200B585FDFF60FB3ULL, 
            0x584436D57EF6C876ULL, 0x0C56BEB74F6EDF08ULL, 0x74E65976113462DAULL, 0x81993B35901D039AULL
        },
        {
            0xF9BA35B31855581BULL, 0x2C62604FBE16FEDDULL, 0x51F6D2CAFBF1E65CULL, 0x3281CDCA1C9E51FCULL, 
            0x23A9FA19B76812FDULL, 0x51865FBE5E963CC2ULL, 0x48138084C9D950B0ULL, 0x88A63FB411CA63F7ULL, 
            0x6F516F2D32EE4FDBULL, 0x0F7B4E951B6C6C20ULL, 0xD7241085121FFE0FULL, 0xC5AFE616DE9267E2ULL, 
            0x4117A0352AAF8290ULL, 0xA9883E5A6C977D85ULL, 0x7702135F0536EA03ULL, 0x5515352C100E8434ULL, 
            0x85597691E19981DEULL, 0xD1F4F4FDA83BCBB1ULL, 0x16929D356A7B6825ULL, 0x988CCA441257B28BULL, 
            0x63A2176655170FD0ULL, 0xA7DC762DF3EFAC9BULL, 0x4519323B5CB5CE10ULL, 0xF202F11541C084DEULL, 
            0x17613763A520A769ULL, 0x4CDE42715C5317FDULL, 0xBB73D00943B75FAAULL, 0x9E5B4B1748E04085ULL, 
            0x38765C6B2601AE16ULL, 0x824589F5E44F856EULL, 0xFB6C99ADACDEFA6BULL, 0xB30698D0FCE4348BULL
        },
        {
            0x443E12F113BE40B5ULL, 0x920B68CC437575E1ULL, 0xFCBD5D153C01E609ULL, 0xDE463B5FE948C9C3ULL, 
            0x0480D47F33B8A8EDULL, 0xB1575E9D34AF05E9ULL, 0xD2A2E775B3EC0839ULL, 0x884E08185DBBA96CULL, 
            0xD07D4DBE15474369ULL, 0x038563C2592C2E37ULL, 0x1F9AAE599032E7DAULL, 0x792A4C7EF4D87138ULL, 
            0x86C1A3223DB061ECULL, 0x1FD058A05E20504AULL, 0xDAA507237114EA3DULL, 0x237861E87DE89F7CULL, 
            0x2E02F3F5BCC35CD3ULL, 0x35A99F0F4BA2139DULL, 0x85B9072357F81295ULL, 0x9D2CF2A89772D3AFULL, 
            0x639AB2AFD2F56366ULL, 0x6EE918CFABE592FDULL, 0xDB5EF05338ED75A3ULL, 0x0663AE6058174460ULL, 
            0x615FFE93EE1959DBULL, 0x21A03E52287B3F62ULL, 0x8954FEDFA7276386ULL, 0xD1ECCCAFAFF4D094ULL, 
            0x53745F7D8A4D1ABAULL, 0x76AB25D98B1B82CAULL, 0xFE591382B76B837FULL, 0x054C97074C78558EULL
        },
        {
            0x6B06427831CCF2FBULL, 0xF907D9E7656F899DULL, 0xFECAAC853ABC0A2BULL, 0xA397B62DC255BFEEULL, 
            0x87714336EC57D953ULL, 0x196DD98E496FB427ULL, 0x6DA521770BC72CB7ULL, 0x11B825597E8D0443ULL, 
            0x7A71A45EB35528C0ULL, 0x24BFAE5713392C6FULL, 0x2FCD4C07D91D85B0ULL, 0x9C878FBBC59E1138ULL, 
            0xD031D7A1689532BAULL, 0x7294C3F0BFEADE87ULL, 0xA091E7EE92B7D95AULL, 0x857F212725A7F7C9ULL, 
            0x2536420CE48C6995ULL, 0x41479BDE1811C8D6ULL, 0x199133D355F247AEULL, 0x9DF6BD8E0779BCF3ULL, 
            0xE12916CCD0BFBAF3ULL, 0xC62670C85536071AULL, 0x08D1F81D494DB6A9ULL, 0x57E87D5F6FB9C178ULL, 
            0x076AC949F7FC0A28ULL, 0x70FB026E376F4F4FULL, 0x9A56CC67456983D6ULL, 0x6E15D0124EA7DFB7ULL, 
            0xE53BA834B6A982A4ULL, 0xFE3550D34507557FULL, 0xEA5AA7FEF35DD1E4ULL, 0x41C535A5913D4E8DULL
        },
        {
            0xEF2AC5A681113620ULL, 0x84050B83F87A1FD5ULL, 0xCF5EA18AEE6491ABULL, 0x240EB4593622F406ULL, 
            0xE6643519FF574927ULL, 0x8EABFB2F31F296B5ULL, 0x3CFA3242D9BEA40BULL, 0x450F9C2E3ACA0991ULL, 
            0x4DC3B15C5235F108ULL, 0xC6ECE7E57326281BULL, 0xB38E25045D727287ULL, 0xA39599BED1BC1C2EULL, 
            0x501A250F17C2CEE5ULL, 0xF9E58B20019FD97CULL, 0x071AD5735FBFB989ULL, 0xDF94B46739696347ULL, 
            0xCD587C6121B61094ULL, 0x90E7E11D05AC2522ULL, 0x4DD1AC406D70FD53ULL, 0xE13445A2DF53C170ULL, 
            0x677210689086A4FBULL, 0x20626356A8793A1BULL, 0xA66B2AFADB0E85F0ULL, 0xA8D9577E6277265CULL, 
            0x1A5279D6DEA586ABULL, 0x718208AA149EF108ULL, 0xBD4387CE9974BA81ULL, 0xC060614A7C78FEA7ULL, 
            0xE3B577E4D5B5E0A2ULL, 0xFB2847B06F86E406ULL, 0x9D90FD45B2F0F990ULL, 0xA83CAE4F9E4BB52AULL
        }
    },
    {
        {
            0x9F46D7D17A62F450ULL, 0x6F40D207B6106F27ULL, 0x141DDF85C571E27AULL, 0xE614C3C0F45203B1ULL, 
            0xB09C19EA76EADA57ULL, 0xAAEFC2ABD41D66EBULL, 0x3DDAB6698E37FE1DULL, 0x16EBB49F0ACFBDA9ULL, 
            0xAA95EE6C270CFF7EULL, 0xA6982EB16C0549B6ULL, 0x0312AD6917C2AB8AULL, 0x1C1AB6788F52DBC0ULL, 
            0xDB7D14CBC64AFA1CULL, 0x5615160F6EC923AAULL, 0xF20765274F9B2331ULL, 0xB5643FF3AA82BD93ULL, 
            0x2A86AC4240442F12ULL, 0xBECB472CE32F13B5ULL, 0xA1E1106164FFE70EULL, 0xF943E08371DB1207ULL, 
            0x44D1F9CCEDFCDE05ULL, 0x68106C7B3FA82E98ULL, 0xBECE48B10F1140A8ULL, 0x1891BCC199E36DEBULL, 
            0x046B0409B5D91180ULL, 0xDA2D3D20A9A74A3FULL, 0xF42B25B143FB0894ULL, 0x232DA06612753026ULL, 
            0xC04788A4707584CAULL, 0x7B58CF59FD1039A5ULL, 0x7DD93B055869CF56ULL, 0xD55285C3D34D51B3ULL
        },
        {
            0xBA00434927245100ULL, 0x91B5271CEB40B645ULL, 0x7851ECA3F4F2B018ULL, 0x9CAAFD8F116DB3FEULL, 
            0xE082C16B825FA689ULL, 0x91B1CA7BB9948E95ULL, 0x148443499CACD95EULL, 0x715274F44F7E40C5ULL, 
            0xFC55024FB0B1D579ULL, 0x2008A7E4005B5DAFULL, 0x3881A27BA9BD29D6ULL, 0xF17FA047518D7F36ULL, 
            0xFFB33613229136F7ULL, 0xAB6892605D11E54AULL, 0x3AF69FE47C8E9BEFULL, 0xB7B4F64F6B35B86AULL, 
            0x25ECC100C9C51460ULL, 0xDBF02B121F1CD03BULL, 0x6E98E6DEAA03EB8EULL, 0x64DD2BDCCCA5A5E9ULL, 
            0x8BA7EFF14C3EE619ULL, 0x7266EB319600D85DULL, 0x2FC3D2F5DD8E02E7ULL, 0xEB70483480919B8CULL, 
            0x1DAA8B9D977ABBC8ULL, 0xCBAF27F51CE0DEE1ULL, 0x2F8FE5F30FAB26C7ULL, 0x34E6C57706598B39ULL, 
            0x88727CB7CE4284A6ULL, 0x18EB5AA0CC322DE5ULL, 0x8B7B5FF2EFFE96E5ULL, 0x3EC450D0A24F6BC9ULL
        },
        {
            0x3A51F1ED183C1933ULL, 0xB4CDEBE7D5C00D96ULL, 0x8A652090C33D7079ULL, 0xF91BFB998AC6CEEFULL, 
            0x319D34771B692107ULL, 0x1AA65D3357E37569ULL, 0x5D4B2E0CEF9D2267ULL, 0x4ED7FCDF0E3AE61DULL, 
            0x455697EE7D31EB2FULL, 0x29B780BC2035A531ULL, 0xDAA2C80A61DF5131ULL, 0x0AB65588A34146A1ULL, 
            0xB896C3FEA1B0C448ULL, 0x3174A2571C75E3B1ULL, 0x519F51D270AD4795ULL, 0x41B5AD0F0231F89CULL, 
            0x8A997271C5F342D1ULL, 0x8CCB9A5DDFCF0A07ULL, 0x450B9DE00AD17937ULL, 0x06FF1E03B8D25161ULL, 
            0x6AF0C7A852FFC585ULL, 0xC377D1383542DBFDULL, 0xBFF3987F855F0C92ULL, 0xA0946AFDE0E70D0BULL, 
            0xE942D552C87A6F33ULL, 0x0F1CD8AD14C73B69ULL, 0xD3CFF39CE65E89E0ULL, 0x011CC97169EC3A7AULL, 
            0x83857E1A69B91133ULL, 0x1927CB4A591DF078ULL, 0x83285097F82F42A5ULL, 0x226CEEAC0ABCA5FFULL
        },
        {
            0x54E298770244E723ULL, 0xE744C180E398A572ULL, 0x1D055A231B533E4FULL, 0x9CEE905976F1ADB7ULL, 
            0xC5DDE4764236616CULL, 0xE1782225E3869CD5ULL, 0x28C3C05F0F63EE87ULL, 0xBBECA0E3E3E68E0CULL, 
            0xDEBA86496764F4AFULL, 0xE7DCDAE3F7A0EC38ULL, 0xE087A422E77855D0ULL, 0x98BDABA0EAA872B4ULL, 
            0x6548E2288D9DB625ULL, 0x6B21F579986A7766ULL, 0x9C07FEA8F14521A2ULL, 0x11F5817432A8ACC2ULL, 
            0x8065B1923906333EULL, 0xD87FA478D86DD24AULL, 0x4DB37BF5A7CDF519ULL, 0xBE04E069427102C3ULL, 
            0x6FE5E63F92C293D2ULL, 0x9CF7A918D169F8EAULL, 0x0652FDEC9426CEA3ULL, 0xF635C30D86D23478ULL, 
            0xCD0388F890F796B8ULL, 0x428C2F61C8F4DDC7ULL, 0x1E79F65EA3F8169DULL, 0x80ABEB3EA62B9DA0ULL, 
            0xCD8EBC1D44C7860FULL, 0x1CD9A72633D3D687ULL, 0x54C8AE3D9B93CFA2ULL, 0x1ECA85E066A38BFBULL
        },
        {
            0xA702911541829B14ULL, 0x193A411D3D16E274ULL, 0x5562BC7D9507DB4BULL, 0xCCC6946E2E7F0E0DULL, 
            0xB35A146F228C95EAULL, 0xC6D95FA55272B602ULL, 0x5C673C0FB4DCF034ULL, 0xC308CFA441119F0EULL, 
            0xBADE23DF65E174CFULL, 0xD8C65169B3264A79ULL, 0x36C3439FB8BA8DC3ULL, 0x85EB269FFCD6C2B5ULL, 
            0x14E50179C9A4B91EULL, 0xA4D2FEFB159B1CA9ULL, 0xB6B93DF76E676057ULL, 0xA104FBD5800EBE66ULL, 
            0xD1D1A3FE0EE433A4ULL, 0x0599FD8558EB0A23ULL, 0x1E25FC31FE38C716ULL, 0xD40D73159C10B691ULL, 
            0x468AD1E4B70E37DDULL, 0xD8B398E8BCE4513AULL, 0xD8FCFC831927FF18ULL, 0x7BA1060C8932715FULL, 
            0x778E3943816C40DAULL, 0xD171A813A5446CABULL, 0xFBAF8DE75256C263ULL, 0xD27933F459939AC7ULL, 
            0x29DB96EBF9DFB3E2ULL, 0xED02B93B14A789A2ULL, 0xD5582AE8D7A3000FULL, 0x54CD612DBD369988ULL
        },
        {
            0x24D3C28A68F83219ULL, 0x746EE3E0123733B8ULL, 0x557C002BD2B83914ULL, 0xE0AEC4364744E05DULL, 
            0x665CE8A103F6B400ULL, 0x344F77E4D25696D8ULL, 0x5610A741EFB66395ULL, 0x5C4600BF40F06CE3ULL, 
            0xDC9110F1203B6053ULL, 0x0BC5B8C1914B834CULL, 0x1892D5F35AEA2911ULL, 0xAA427946B798C7A7ULL, 
            0x46FF0CA85E3A4D6EULL, 0x9C451C533F5245A6ULL, 0xFECFE067880013FCULL, 0x34C62A06C8B5F30FULL, 
            0x5F2205825996EDD7ULL, 0x03E456B724A1A45CULL, 0x6EC23A6BAA18E727ULL, 0x677D1FECDC42DE5AULL, 
            0xD5E72E448D448A16ULL, 0x63D9BF5AB1E70D07ULL, 0x35EEA97ED07CAECEULL, 0xF1E9580E618BE9BDULL, 
            0x80080711CC566F81ULL, 0x10DE79B7C301A9F2ULL, 0x630DF5327DFBF5E1ULL, 0xC5F73E3D0F7EF32CULL, 
            0x011199B655C0FCCCULL, 0xA7DE4B2226BD42D5ULL, 0x93BE3AB4EBC5073FULL, 0x8F23176F2E42058DULL
        }
    },
    {
        {
            0x0271100732C1AD2FULL, 0xDA5413BFF998D088ULL, 0x1E988B7FB1869802ULL, 0x25AC4469DC97D8C0ULL, 
            0x87D8C91C398C34F8ULL, 0x5BC5EFC2DEE3D180ULL, 0x6372159994DE4B67ULL, 0x2AFDC2EA4C429741ULL, 
            0xDB9166B142D3773FULL, 0xF0A3BC8F606230DEULL, 0x97E24F4580E6DE58ULL, 0x3ECFFD81047198F7ULL, 
            0x8F7630950F679BF4ULL, 0x676C68317F5571CDULL, 0x3AC1335AF3173C84ULL, 0x4CD079A38E727C3CULL, 
            0xA0128B972BDE7157ULL, 0x70B73F1EA76FE51DULL, 0x87CBBF699886BF2FULL, 0xE14F777D55C177FCULL, 
            0x047EE0AB78C820BAULL, 0x1A4C494CD7DF23E1ULL, 0xBDE8865A6A025EE2ULL, 0xE107CBCCF26EE198ULL, 
            0x87DD3E0E1F3BF3BCULL, 0x159E8ACD6FDF7856ULL, 0xAB7E73DF05826D9EULL, 0xD177A374E8BCA7D5ULL, 
            0xDD33C4EE79D98538ULL, 0x8591169322421FC1ULL, 0x6C91DF40166FFDB7ULL, 0x4CEFD1478EB6B603ULL
        },
        {
            0x283A283826DE27DAULL, 0x0133BBB9A30FE01CULL, 0x8633CD53C81C3D1FULL, 0xE5564CA4E62C2B11ULL, 
            0x8EE6A5FE6C60C127ULL, 0x52900C22D11E3B9CULL, 0x6318BDE83F62C6D7ULL, 0xC5EEB9D454481917ULL, 
            0xCC7316CC23C32EC6ULL, 0x517558631A146F72ULL, 0x9A33EA678BA96408ULL, 0x68343FCC41F3D675ULL, 
            0x91B03F76966236FFULL, 0x29E23E920F439696ULL, 0xFEB54902F696826FULL, 0xE91594D1D445408AULL, 
            0xFED96E686798AB81ULL, 0xAF69E2ADB30F2A2DULL, 0xB525C4C6E0DE7D08ULL, 0x350273E3EF5C2723ULL, 
            0x33A23CFFFE070B7CULL, 0x119D772398E43616ULL, 0x51A37330E927FA1DULL, 0x5DC70C2505D9A2C6ULL, 
            0x67184736A424B512ULL, 0x8C836BA968A87141ULL, 0x5560C103379B699EULL, 0x69D1FEE3149202EAULL, 
            0x2BF199F21163F1F7ULL, 0x08D60CB0B3B5BE17ULL, 0x73736F8DBD9B9120ULL, 0x528CA3F9A761D763ULL
        },
        {
            0xB43ACE9AF96DE6ECULL, 0x6D7E0AF9D28BC42AULL, 0x05DB6DEE878F6093ULL, 0x49789142F5BA2EBEULL, 
            0x59C83750B1CDE6E7ULL, 0x686C352D7C73BCFBULL, 0xE854ED5B5517F202ULL, 0xD9C848AB5EDD5C39ULL, 
            0x1A32C8233BDA031BULL, 0x003DC572B9510896ULL, 0xD5497D570F188132ULL, 0x7BC54707B5937453ULL, 
            0x3E7AD88545CD8191ULL, 0x38E5314DDB76BCA4ULL, 0xEF1989872D6A6935ULL, 0xE035197D2D9A87C7ULL, 
            0x4313EB449A49A7A6ULL, 0x5D676112128369D1ULL, 0x9A8BB722D09C8666ULL, 0x3CD25C8292FB20D8ULL, 
            0xC8D0906869EC5AA9ULL, 0x54AF3D52B0A9608BULL, 0x8E0CDC5168A777F1ULL, 0xAF5F3BF567758825ULL, 
            0x295176667FCCCC00ULL, 0x64009F529F87AC8BULL, 0x16DF66B12506FED5ULL, 0x059361FF0DBD3162ULL, 
            0xAF9A38B7A99C3C92ULL, 0x94FF7C392050B790ULL, 0x68D7479C0EFA1F67ULL, 0x0834F5EFC9B53280ULL
        },
        {
            0x5C0F457FE56A67A1ULL, 0xCDF8678A98905419ULL, 0x2FCF6BDE5AE07DFEULL, 0x9985579005DC77DEULL, 
            0x5CAD451E90F05837ULL, 0x664B432D57B32EFCULL, 0xBE23DCF4DD590CC6ULL, 0x4CCB30027373F32DULL, 
            0x094A233138C1F0E2ULL, 0x9500D8E4CDA9F9FBULL, 0x9C80B2ACC242C7DFULL, 0xB60DC8E2BF8034EFULL, 
            0xAF2BEDCCAA6E88C2ULL, 0xACFECC198D575197ULL, 0xD71CBC5F2961BD5DULL, 0x168327FA3FEBCFF3ULL, 
            0x27BCF4D3EFCF4CD5ULL, 0xB67652231ADA9243ULL, 0x5763F59F8342478BULL, 0x91CB65C01E64E0F5ULL, 
            0x0C3EB57F30983680ULL, 0x6FD022460F4E200EULL, 0x9C282B21C0466090ULL, 0x9C627A08F403D32CULL, 
            0xC850A1DD23E30745ULL, 0x6966AC74DEE9A04FULL, 0xA916E7DD342B59D7ULL, 0x28D3FF656250D3CBULL, 
            0x0F2E4F3BB5F70463ULL, 0x6B09D6808240FA8CULL, 0x5393F530FE1C8382ULL, 0x375EBCE2E135C9F0ULL
        },
        {
            0x5C82A58A642E80A7ULL, 0x611F3682EE655802ULL, 0xC21813FAC7BFBAD5ULL, 0xADBA969ECEEB7BF8ULL, 
            0x00D3739323292772ULL, 0xC81EE6BD76220874ULL, 0x9D5E3F643512C1B4ULL, 0xF9964833DF20F1C3ULL, 
            0xD10C0D0747225743ULL, 0x785ED4206E48AFC1ULL, 0x3862CD61F55CD0A2ULL, 0xD1E789EF983275DAULL, 
            0xE49D1DD9AFECA933ULL, 0x94CBFC04CB6CC698ULL, 0xADE8809056E86B0CULL, 0x2EB0D9B5ACC5E1D3ULL, 
            0x6CEB5DC7358307D6ULL, 0xD93440ADCD961C73ULL, 0x75B286CA43A65986ULL, 0xAB875853224AFAE5ULL, 
            0x0C36F2245EA6C838ULL, 0x10FF60EB50D0866FULL, 0xF8C2096368EE776CULL, 0x30CFF522554F5E15ULL, 
            0x920D8F25F26EA29EULL, 0x3574BAA9691ED33AULL, 0x82535DDDEE7B6996ULL, 0x8A4C9A8EB326139BULL, 
            0xEE5EEB8AA64C7473ULL, 0x540241064EF8CE5DULL, 0x4E2EF6FBBF034DE4ULL, 0xD5BAA6F368DB0DB6ULL
        },
        {
            0x8A2A8A76BED185E1ULL, 0xE3885E28AB40DACDULL, 0x001307C5AF9C2783ULL, 0x7212AA667B39F17FULL, 
            0x2054BED0758FD333ULL, 0x57E90B88DFA8643EULL, 0x552A172B22942E4BULL, 0xB6C711D21A97CBC7ULL, 
            0x36D465DFC7EF82BAULL, 0xA01D658E15CC84DBULL, 0xB976686A8D020804ULL, 0xBCC78D69C704DCFEULL, 
            0x6B7594FAC3406893ULL, 0xBD9616DE50F5F5A3ULL, 0xC413F86A945C8A90ULL, 0xF771023A6C3BE03EULL, 
            0x39342E4E6CB83504ULL, 0xF9366260C35AAD39ULL, 0x83D1830629CB9276ULL, 0x4D7167717252669EULL, 
            0xF4C0259880C18471ULL, 0x792999F66C2396D5ULL, 0x2F0321D7A8FAC678ULL, 0x07FBF308282A4228ULL, 
            0x62A23125D62CF157ULL, 0xF80E39D0F720DDF8ULL, 0x2D13641C30231F11ULL, 0x4159C43461B3A42AULL, 
            0x52C94434FB5F0703ULL, 0x8C8472BBE8070889ULL, 0x0C0DE4181F5FE772ULL, 0x1AA75250A4015120ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseGConstants = {
    0x9607C14F42A88281ULL,
    0x3CB52607027A26E3ULL,
    0x428DB7F41871C166ULL,
    0x9607C14F42A88281ULL,
    0x3CB52607027A26E3ULL,
    0x428DB7F41871C166ULL,
    0x7532F1BCF9F0E725ULL,
    0xCAF4C0AE989735FFULL,
    0x08,
    0x30,
    0x99,
    0x23,
    0xE8,
    0x61,
    0xDC,
    0x55
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseHSalts = {
    {
        {
            0x954811CC9FC94A56ULL, 0xBD4CC3299623E3B2ULL, 0xA371F6BC6AB3CFB6ULL, 0xAC787451C1A30925ULL, 
            0x129AA255826AA2EDULL, 0x3137DB3554B5DB63ULL, 0x70E79D92C4914A27ULL, 0xCFD4FF8014F7E700ULL, 
            0xA8CF5C8EB6A309A6ULL, 0xD966B1DC6F29E3E3ULL, 0x03CDCF9DC98977F1ULL, 0x7EBB6D279881B24AULL, 
            0x36F545BF2BBC1CB7ULL, 0x4D01FD337A03C57BULL, 0x15D0CACF7CFD5631ULL, 0x3BC466E03237A8A6ULL, 
            0xC24F85397659B144ULL, 0x0936067E87993D20ULL, 0x1F3C853F5383364DULL, 0x4F55EF615754F243ULL, 
            0xC33620A053E689FAULL, 0x144A8E84D6478826ULL, 0x10580AA87826A2E4ULL, 0x7433C9164B4A0A05ULL, 
            0x5382C8522DBCC72BULL, 0x21625BA313A7FDC5ULL, 0xF9BC21EF305067E9ULL, 0x5E656E4E30022864ULL, 
            0x244D7B7157B6A9CDULL, 0x4F1B0E85A3A4A396ULL, 0x5F5C727E6CA6F42DULL, 0x7F246A9FC4E6D073ULL
        },
        {
            0x746E0934F247E146ULL, 0xC8FF3D0AB916DC91ULL, 0x8068C926E3152E10ULL, 0x4A9D94C179C91EE3ULL, 
            0x27235C91190790FDULL, 0x2F2CDC4C6A89CCB6ULL, 0x0A00B6C2926FC8DAULL, 0x1ABF788AE55FFACDULL, 
            0x59A2EC736E3BE7C7ULL, 0xF7DB864F9EAEF09EULL, 0xD27E3D0C1B052EC7ULL, 0x0BF9E118C66C112FULL, 
            0x5A69D6298BC96AC3ULL, 0xF68B209FFE129371ULL, 0xE4E2ED46E53E8A2AULL, 0xAF8A3ED6E90ED9ECULL, 
            0x623F5B81E3222B38ULL, 0xB79DD2BA2DF88734ULL, 0xA2E354514DEEEC92ULL, 0x4B38270A832A5EABULL, 
            0xA95DE2F1DF1ED6EBULL, 0xBCA946745BE62409ULL, 0x93058C5FB66DAABDULL, 0x61E26E69014C5108ULL, 
            0xE71133CFD1C5FA20ULL, 0x8640666CD5333886ULL, 0x4771438B3D59768CULL, 0x9607BB5E5BA55650ULL, 
            0x14BDE7854C931B8AULL, 0x69D639507924DD20ULL, 0x0058BE6EA5D5936AULL, 0x057AC87A799B2E92ULL
        },
        {
            0xD3336DFD0149EF17ULL, 0x6220B5C34A5DDDF5ULL, 0x7A44177DD4D1B583ULL, 0x1A4895758AFD6755ULL, 
            0x9BC5E825B0D58627ULL, 0x00E4DA7D8A69B039ULL, 0x09A4E79FB8263DABULL, 0xAF819FC994E67A99ULL, 
            0x442370B660AFF7DAULL, 0xB800099B083EE6BEULL, 0x753C74B94B4F8936ULL, 0x93FAC1433FACAF71ULL, 
            0x7D9662E56AC7F675ULL, 0x5A339600E97DD3DAULL, 0xC1F3318A21385689ULL, 0x398CB8830A75D73DULL, 
            0xA487B4A31A51B1F3ULL, 0xF0ECB48BF9AECF15ULL, 0x552EB9B53A5E8866ULL, 0x32FBD6581AE85410ULL, 
            0x119ABA550EE6419AULL, 0x6D00861DD8031142ULL, 0xEBCB7932F8D448D1ULL, 0x61F5250FE11FFC1AULL, 
            0x8C8AF3D22C3B40AFULL, 0x36C62B578C636B98ULL, 0xCB8043A6377D6DB6ULL, 0xA9A0EB991851FCFAULL, 
            0xE74FAF35F335A22FULL, 0x62ECB1DB93FCBF12ULL, 0xA481CFB76C3DD928ULL, 0x5672D1253B5C8F48ULL
        },
        {
            0x766D9ED64D648579ULL, 0xE867284292C24845ULL, 0xAD2ED7715D6CB525ULL, 0xDE7F4022B8C80E27ULL, 
            0x29C9861783C2ACE7ULL, 0x162EC996A056ED19ULL, 0x1F012B734A7E6410ULL, 0x202645BA017BEC35ULL, 
            0x77F569C79FB27C3CULL, 0x253BE346AA86558AULL, 0x51081C60A82A7C0EULL, 0x83C120ABAEC2AF3AULL, 
            0xFB4ED570966D4F97ULL, 0x067208D8A0EE3966ULL, 0x75ED31E53DC5656EULL, 0xC15F7E8CEA5173DDULL, 
            0x0F5722221F543C9CULL, 0xF7C3D3C10A7873FCULL, 0x745494CE32D08E5EULL, 0xDD618D7372CA91CEULL, 
            0xC236C09525AC3EB8ULL, 0xB04B1993A5F061A4ULL, 0x4FD2DB97196D4993ULL, 0x2F215116A8BE7235ULL, 
            0x6F68443222247FA8ULL, 0x55DBEBD5F8C1B0CCULL, 0x295507DBA3E3F557ULL, 0x227FBC56D04271C2ULL, 
            0x49A74EB27B7B830BULL, 0x94648773D5F32B7CULL, 0xC0ED764D6F86850CULL, 0x8C0B5E24A62402FAULL
        },
        {
            0xC03574F9600296AAULL, 0xA69DCB05D3687336ULL, 0x7860F85E5527D3D5ULL, 0x4080D6661AC7CB6AULL, 
            0xD5C5638F31365D4CULL, 0x2F875733E49681F7ULL, 0xB55D3BDAB77D051EULL, 0x3C855AE30C4E05B2ULL, 
            0x9FAED04B0C175AF8ULL, 0xF0728294BBDD532EULL, 0x3DF0614AFDB714FDULL, 0xD01B781A469B1EDDULL, 
            0xB7CFEFD093C7D54EULL, 0x3E4FE118C84A98B3ULL, 0x391CACB6125931CBULL, 0xCE648506F2C76407ULL, 
            0x1EC0360CA1D908FCULL, 0xEC4980FD1CD1CF7DULL, 0x4FC3701697BE9024ULL, 0x7F5134A28D7624E5ULL, 
            0xC521FCBC06E65A15ULL, 0xAFEA0293B4987C47ULL, 0xD2FE2AC076A075C8ULL, 0x725FC644BB8B6754ULL, 
            0xAF67B23709869479ULL, 0xE02E348E87C39050ULL, 0x1B8A59AF4C9D2212ULL, 0xD7756959A17CCA47ULL, 
            0x95F32A07ED1F2661ULL, 0xE8956C9090467BFEULL, 0xC7601EAF351EE741ULL, 0x9D4BBE6FDD6DBD8DULL
        },
        {
            0x32B11D2405305D91ULL, 0x11BBFD07BD5E08D8ULL, 0x5EB963304BE0C14DULL, 0xC32E129B6C92FE83ULL, 
            0x36C4AB67804C27FAULL, 0xF749BBC2D0EA7E35ULL, 0x4B7696E641F55501ULL, 0xF0C785C15754D902ULL, 
            0xC5BFED1A948C91CCULL, 0x49B23BB0E7AE28E7ULL, 0xAF0D03BB2988892FULL, 0x2E4866FFD137A0F6ULL, 
            0x4020C73564F0E5CFULL, 0x1F4402CAB4D15C54ULL, 0x5350B36344A916EAULL, 0xBC40CECFF6B56748ULL, 
            0xF13C3E8C7C6AB886ULL, 0xFE88A80EB5990026ULL, 0x831E640FF639F604ULL, 0x9AB0A6CDA5B6128AULL, 
            0x6D4C5B111F27C0D7ULL, 0x1CB36D55989B609BULL, 0xE73D1D98DF8CDD2DULL, 0xEC8A69352B37CCFCULL, 
            0x92855A9DF71EA9D7ULL, 0x9D1F6CB14D8BCC4FULL, 0x57592894929184A1ULL, 0x7F0CE259546CEF90ULL, 
            0x3F2AD909ADEA15B1ULL, 0x9E116785FFD9F174ULL, 0xB9CFF9B2D7B158D4ULL, 0x1FA47DA0A2163271ULL
        }
    },
    {
        {
            0x9D9059C1B453BB81ULL, 0x077E9C70814BD6EBULL, 0x44F681CEC760ADCDULL, 0x42E9C8711A62852EULL, 
            0x6FBF4F493A87D380ULL, 0xE217A48162027B23ULL, 0xF2CE2D6FB38FC66EULL, 0x903391F11188C8DAULL, 
            0xEDC11703444B386EULL, 0x4C56A13B9BA410B1ULL, 0x3F6797E599A342C7ULL, 0x3CEBDD655694F4F4ULL, 
            0xA6752AD053C31279ULL, 0x3A9E80B500730E83ULL, 0xF435C2ACED1E3FC2ULL, 0xF9ED3580EECDABDFULL, 
            0xDC61D7F74B1D4AE5ULL, 0x9160EFE47261B93AULL, 0xFA11E9A536719E6BULL, 0x822670C72B49FF8BULL, 
            0x6D3758505C9DB1D6ULL, 0x1CAD65B3E960F9DBULL, 0x4390DF5581D46D4CULL, 0x922C5777826212ADULL, 
            0xAB5C4DE57DAAF428ULL, 0x9D0974FD2730F146ULL, 0x71CBB58A0BE489C7ULL, 0xA1735F6EFF539EAEULL, 
            0x8F6F65350385E7BCULL, 0x78CFB61135BDFC34ULL, 0xE37B6ED796A7C6FFULL, 0x59AF60F464BDB393ULL
        },
        {
            0x2AD279C85BE46033ULL, 0xDBAC63B75B270C43ULL, 0x8BC77CFAE2E4A879ULL, 0xDF1BFC3985C0E128ULL, 
            0x8EBF5F9E27BAABD7ULL, 0xA958EBEF50D5FA44ULL, 0x947F1F64A62565C4ULL, 0xC1325D434DFC3D16ULL, 
            0x4371D1F6544E776DULL, 0x0950D17E748E1D24ULL, 0xE67D1FCCC9E4FC5AULL, 0x0AD92BA14A6D89EAULL, 
            0xF45621DDB948DCFBULL, 0xF037F819213F54C7ULL, 0xFD867F897E4D8EB7ULL, 0xC7D25A3E64B70866ULL, 
            0x0C50E08FCCE22DDDULL, 0x7F91BD52DEFEE723ULL, 0xEA8DEF725499231BULL, 0xEECD3D7E7B2D5400ULL, 
            0xA56A945EAB7E6B8BULL, 0xD2F17E528FF8C1ADULL, 0xC9B4AA9FD3A56812ULL, 0x6C6FC2DE0E4FEF32ULL, 
            0x461208375161F3BEULL, 0xD95F2357672A709BULL, 0x977EC48271EA3390ULL, 0x135B1B14A344C26EULL, 
            0x3771FF93C906C585ULL, 0x9A45A241E8B64B87ULL, 0x503070AC645DE12EULL, 0xF35B48B240B10111ULL
        },
        {
            0x6B215C5FDC9BDFBAULL, 0x5B1D680A08733525ULL, 0x2F72641FBB813F26ULL, 0x03318623561B4F92ULL, 
            0xB9899D44560AA6C5ULL, 0xB1EF664A48AB374EULL, 0xE22AA62F7635CE8FULL, 0x43ABE2E9C3808238ULL, 
            0x770DA754A903B932ULL, 0x62A15DE5B6C7954AULL, 0x22B65B0A2B029A6DULL, 0x1104C5B81690E409ULL, 
            0x2400FAFE25CA36E2ULL, 0x3C309BF401517BF2ULL, 0x30479B30BFC68254ULL, 0xB1F9A3610C66937FULL, 
            0x263E21E1F983E9BBULL, 0x2E65016A05A01901ULL, 0x9F5E382D3A4E26FDULL, 0x28EDCF7F11E4EAE4ULL, 
            0xC7CCE2DFE9FA82EBULL, 0x6A148816B6AEB311ULL, 0xE3DFED521ED3F5F0ULL, 0x65E2836DA15EFE73ULL, 
            0x2C1F255F420DF851ULL, 0x0BEC56D5B34D33C0ULL, 0x7720335EC6ED0A16ULL, 0xEAA052D9D54111E6ULL, 
            0x846BF74354309EB4ULL, 0x4B551C4D8D6C420BULL, 0x3EE2F0B15F138A37ULL, 0x6D738A1F1A8E0D2BULL
        },
        {
            0x23CFCE46BA4F2035ULL, 0x8896FB45F0314E48ULL, 0xF03F2D9E1E45ABB0ULL, 0x0F1281AFCC94D425ULL, 
            0x100BD8DB7B7694ABULL, 0x45E73627DBAFB0A3ULL, 0xFA924B5A8A9F8CCFULL, 0xFE636DB46931789FULL, 
            0x8AC96D572F4417A6ULL, 0x40370481F23EC169ULL, 0xF14C1302622FC493ULL, 0x9374567176495805ULL, 
            0xF78763CE265E17D3ULL, 0x5C77D8F1FDFB8051ULL, 0x762E7E1B65C90D2AULL, 0x05DFCCA4E6DEEDDBULL, 
            0x9C343F5096D708ABULL, 0x8416B829157783D2ULL, 0x3F9E375852B303D0ULL, 0x38B04396B7B81089ULL, 
            0xF5694D575DFB0174ULL, 0x1A1143BC5C71D8AAULL, 0x48FEC031612B2C2DULL, 0xC4C4B8F6159269CAULL, 
            0x681D054F3B14A11AULL, 0x5FDACA61D02627D6ULL, 0xBE931240E6558692ULL, 0x9F96FC88481B8FD1ULL, 
            0x7B878AA6A831FF55ULL, 0x5D306DF84A164F67ULL, 0x4DAC2C794F169AF6ULL, 0x898A336AC668F8A3ULL
        },
        {
            0x9BBEC0E9524303EFULL, 0xFDDD2D1FE74BB434ULL, 0xC39D4E3A4A76E295ULL, 0xE65A2AF15F780093ULL, 
            0x12EA1EC404EC50A2ULL, 0x2B65BBEDD1DF97A5ULL, 0x0683C42BF7A05A3EULL, 0x47910FF7D776E14AULL, 
            0x64D282C5CE58EC31ULL, 0x9975948F8A203C13ULL, 0x54236570D7076C78ULL, 0x268D72966DF4CA5BULL, 
            0xE4695477570DD88EULL, 0x4F7ACE65AC89B371ULL, 0x2C1CA581022C0295ULL, 0xB3E571977B1300A0ULL, 
            0xA0AE55EBFB8D4DD7ULL, 0xFB626DC85BB6F7AFULL, 0x6D6B6E70AEA376A1ULL, 0x18098AF1D02203B2ULL, 
            0xDDEAA0254F5F5E5BULL, 0x2DA4D3F38A1F50E1ULL, 0x6FF3AD08FE896263ULL, 0x11093BE24346E196ULL, 
            0x6E3B23C7062B256AULL, 0x0F0F5DD2DA213D8BULL, 0xD81B3AE5846110B8ULL, 0x21E58E3DB5C673ECULL, 
            0xE7A0217518DAF832ULL, 0x9C2372BA6EFE4718ULL, 0x99C9506820DE309DULL, 0xE3385063B5B792ACULL
        },
        {
            0xA38BA729D53E541BULL, 0x48041C80F2996FECULL, 0xB2C610034E3E9324ULL, 0x43B7C6481B4C2B79ULL, 
            0x1C5DDF7EA491E3D8ULL, 0x17418F8C47EF8B51ULL, 0x347E3F684D8F640DULL, 0xC292ACB362D461F6ULL, 
            0x6C300205C288328BULL, 0x3364D5A68BC7379AULL, 0x3A52966E62056A80ULL, 0x6BBD54A26364ADC2ULL, 
            0x4200B7F1D27BBC41ULL, 0x6B7F562D9BDD337AULL, 0x7089CAE4450EACB1ULL, 0xFB97283F4C8521F5ULL, 
            0xFE4DDD89C23AA62EULL, 0x860BF0A111C6DBC2ULL, 0x9A692F38B488BD93ULL, 0xADB5B1938D064448ULL, 
            0xE5A7BCE4BB28996CULL, 0xDA631514C675C01FULL, 0xC1CD5B9414D714FCULL, 0x2C13CBCEA46E3A0DULL, 
            0xE8E7D9A9EFE249F4ULL, 0xC781A4456167DF58ULL, 0x31EC9918E26A7542ULL, 0x1F6687F4DC5616D1ULL, 
            0x77F0F70D0CC42273ULL, 0x21A84EB55DC39E81ULL, 0x580A103E94D6E223ULL, 0x3B139759A89F0757ULL
        }
    },
    {
        {
            0xF84CA2EFE71F0569ULL, 0xD6E5E3F4FE635AC9ULL, 0xF76CAE82418F47C0ULL, 0xC7D11A5D2E947CEEULL, 
            0x64F0BB920FBAE3C7ULL, 0xA87A11F2BA910148ULL, 0x89FDFE2A799897B3ULL, 0xC4445A6CB5F3CAAFULL, 
            0x727B22A5A1C22FB2ULL, 0x3E81DEAD8FF0F082ULL, 0xF26C133A10F7E13CULL, 0xA4482FB34E66CD88ULL, 
            0xB2F67243CBBE0925ULL, 0xAD4D17FC22521C70ULL, 0x4908DC991F9CB75AULL, 0xA6557339673444AFULL, 
            0x5D9451439A780036ULL, 0xD38143164DB730BCULL, 0x9140D8E40D6E3A77ULL, 0xE9F61641B49255D8ULL, 
            0x4A4945424E9D2751ULL, 0x47F31F856652CA7FULL, 0x5559797BD4D49D9CULL, 0xE39125C339C7B6B5ULL, 
            0xEE65ED6BBD3986C8ULL, 0xC9E53AD12A0A6830ULL, 0x3B21224CA0FC522BULL, 0xE7585F61C0CFF930ULL, 
            0x458E02D85959CD89ULL, 0xC0A256FAC909C932ULL, 0x317DA5F54E29C8DAULL, 0x234D0970E8F3B44AULL
        },
        {
            0xEF89DAE6579605C4ULL, 0xCA4227A6A7E64711ULL, 0x45A290D6C75AEE0CULL, 0x57FE629A32996CFBULL, 
            0x5FAE5C201F0D7C27ULL, 0xEDCB473C7FFD2FCFULL, 0x3891CA9949F41D6BULL, 0x2402FC61A796C845ULL, 
            0xEA3FC074AE1EFB4CULL, 0xC9A9032599AF78E2ULL, 0x72941A917FF5733EULL, 0x1B035F5C956738F7ULL, 
            0xCA8BA74C9D6C180BULL, 0xAB7462965414DF1DULL, 0xE35F8C5D9C0A71B5ULL, 0x4E08895A5BE2FEE5ULL, 
            0xC36E6D9B2062554BULL, 0x7D2A100C6CF118D2ULL, 0xCD153F6290286479ULL, 0x94AB49E1E851D578ULL, 
            0xCA19847C5DCA578AULL, 0xF4BD958C3E7A261EULL, 0x7C6A37BB87681A50ULL, 0x6558B16CDFDF76BAULL, 
            0x82223A3A2A6AB3F7ULL, 0xA16E5E3CC07FDCE0ULL, 0x2744F3F4C69A7292ULL, 0x7A356D1FC5C84645ULL, 
            0x0C8A10B20F71B1F9ULL, 0xC66F656EB9684755ULL, 0xAFA67C67ABB41939ULL, 0xEA27A79838A9A0A3ULL
        },
        {
            0x875E2048502E824BULL, 0x4B5787E63B72887BULL, 0x98B6FB4761DDF681ULL, 0x6C016784F982FFB5ULL, 
            0xD99F31BE534ED8E6ULL, 0x13C7A74BA949104FULL, 0x04C4A121AF1234E1ULL, 0xFDE4C44F56E5311AULL, 
            0x6D1A6235874F205AULL, 0x9CA14A760A56011CULL, 0xA49CB2FE3D3D3AF7ULL, 0x8CA95909B16379B4ULL, 
            0x430D0211B51DDF05ULL, 0x8EBE4044A2965765ULL, 0x260CA9F5965D0D9AULL, 0x2AB81C89C585C3D8ULL, 
            0xB77DB102B7084ED9ULL, 0xFA4865CC18425E05ULL, 0x27D98825DC200464ULL, 0x7D531BC361A14984ULL, 
            0x746247620035F220ULL, 0x545C1889EFED6278ULL, 0x08FA8B7CE50C7D92ULL, 0x0B23A996183B96C4ULL, 
            0x2C3F14062E6470FBULL, 0x4875407ACE28D481ULL, 0x58D373931C676127ULL, 0x46EA6E8733DC68B3ULL, 
            0x46D6071E1887EC09ULL, 0xDA4C93661C3B035CULL, 0xDC0EF4D3BC7D2665ULL, 0xA9D3091F6625DCB6ULL
        },
        {
            0x93C7E301E5B00638ULL, 0x30D0C7E8456DC525ULL, 0x3FD6D81139DADA1CULL, 0x3C33E048896405C5ULL, 
            0xD6E101F8E23E1C52ULL, 0x17524721CF1058ECULL, 0xCBA0B7A3A1A4BC09ULL, 0x6EF09A108F88C58DULL, 
            0x70D46B69377DC3A6ULL, 0x59009B017C2B1691ULL, 0xA0C97FC960A90A7DULL, 0x830DA5E2366B2BD9ULL, 
            0xE78A186EDD8BEABCULL, 0x42E298A25391CF2AULL, 0xEA8374586FC30F4DULL, 0xB103485C0533FA57ULL, 
            0x33E8A431DC74C547ULL, 0xED86399C2E391642ULL, 0xA0292279F76418F0ULL, 0x314A11157ADAC99CULL, 
            0x0B2F7ABF0DB7F3EFULL, 0x6C3ECC23AC8200DDULL, 0x05ABB3FEA11E16B4ULL, 0x45E0366D036A1D9EULL, 
            0x4207DFC3C5ABB19CULL, 0xDC8E611B69550382ULL, 0x93772AB8CB38E15CULL, 0x56365E40C4B561B5ULL, 
            0xBC2D7683CCBD5C66ULL, 0x4E475B8E9B5848B0ULL, 0x183389DE43B5AAB5ULL, 0x4F59C6157D23A98FULL
        },
        {
            0x7B8AC4ADA9C2B3F7ULL, 0x333D9ED4C0431561ULL, 0xC1478C2E92F79297ULL, 0x7DBC9953F38856C0ULL, 
            0x195E6B50D596BDB8ULL, 0x6500D45BF77706BBULL, 0x5AB1A2FCF0F02327ULL, 0x7D3084D23F86980AULL, 
            0x10143A7B8251C5EBULL, 0xACEE0A55B994CC5CULL, 0xD6AED442ACDDA345ULL, 0x0DE7672EE42CF0F2ULL, 
            0x132B3E2038E24E24ULL, 0xBB18FAFC18F6FB04ULL, 0x8B46B8C163D1A1CAULL, 0x3CB767F4C9681A31ULL, 
            0xC21B07A3D3E5DA67ULL, 0x1607D9875C00F1EAULL, 0x083A937DC1C899B4ULL, 0xB49128420CBC99DFULL, 
            0x64118756ECD4513DULL, 0x0E36D0E9145DD095ULL, 0x03BC2989F0E90656ULL, 0xED0273DC78B4E265ULL, 
            0x00C2F8E61FF9039FULL, 0xA9900A9FE0595512ULL, 0x61A956FAC9DC741BULL, 0x47C38DDDC3F14E68ULL, 
            0xE0E06DBE1651958FULL, 0x8B7494ED1DB43405ULL, 0x5D3AFE19AEF91AF7ULL, 0x472D9C4A5F0B45DFULL
        },
        {
            0x6449581CF7B3CD24ULL, 0x80FFE46996CFD4F5ULL, 0x325E4E813ABDD83DULL, 0x340899E23D687CBEULL, 
            0x76413212A58007E2ULL, 0x2AEC784E8B5197D3ULL, 0x76E92A1D8615E776ULL, 0xD1D6D3B2D3F36838ULL, 
            0x00F9C12623A4D22AULL, 0xDF82CC392523AD75ULL, 0xE19E01E291C25A0EULL, 0x9AFDC1D9F074320AULL, 
            0xF7495989466CB9F9ULL, 0xC031D6527CCE2187ULL, 0x012FF0386AF5D913ULL, 0x6C4158C0302D9F31ULL, 
            0x9DDB72F8EC38E1A2ULL, 0xDB27C9C8837E4F43ULL, 0xA4B2E079A35D9247ULL, 0xB8C18CC70171EAD8ULL, 
            0x598DEF3203A24E50ULL, 0x533C10CEDC0A7435ULL, 0x0945CB3FD2DCCD9CULL, 0xCA83ABFF328A559EULL, 
            0x72BF2A4DF6E3F1B0ULL, 0x8BA216BB8E009E98ULL, 0x16E542199355179EULL, 0x985E12A1ABD9E0D7ULL, 
            0x4ED4487114227242ULL, 0xE4442F43566B3599ULL, 0x69909E8E1C9C4B0FULL, 0xC70E688FD4310DE3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseHConstants = {
    0xBD7F48579842422DULL,
    0x6AAC677A822FB842ULL,
    0x98DEFB92C79502F7ULL,
    0xBD7F48579842422DULL,
    0x6AAC677A822FB842ULL,
    0x98DEFB92C79502F7ULL,
    0xD2D58CF793EB4500ULL,
    0xD078932274BD6710ULL,
    0xAF,
    0xC7,
    0x99,
    0x2F,
    0x21,
    0xE3,
    0x53,
    0x05
};

