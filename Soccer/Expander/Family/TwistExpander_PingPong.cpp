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
    std::uint64_t aPrevious = 0xC8E73C307A13DAF2ULL; std::uint64_t aIngress = 0xF450E9D3E4F10B07ULL; std::uint64_t aCarry = 0xF4B37FF7CDE434D0ULL;

    std::uint64_t aWandererA = 0x9AD79A5042830754ULL; std::uint64_t aWandererB = 0xAF698753DCFB2F8FULL; std::uint64_t aWandererC = 0x9FA3E5BF3CACD4EBULL; std::uint64_t aWandererD = 0xE6F6990DB595C40DULL;
    std::uint64_t aWandererE = 0xFCBDBD80E2A214F9ULL; std::uint64_t aWandererF = 0xD70115BC39E09EC8ULL; std::uint64_t aWandererG = 0xB30F6E7D7146D3CCULL; std::uint64_t aWandererH = 0xE99E4D182370BBFFULL;
    std::uint64_t aWandererI = 0xA32FF450D7611D90ULL; std::uint64_t aWandererJ = 0xFA4B9314D9B3F61AULL; std::uint64_t aWandererK = 0x91B7EAED045BA8BFULL;

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
        aPrevious = 11066947172682757032U;
        aCarry = 11170300344266999193U;
        aWandererA = 11709019375532962838U;
        aWandererB = 16839291096157431838U;
        aWandererC = 9766964347275723137U;
        aWandererD = 15463019329458441468U;
        aWandererE = 11002743183688215418U;
        aWandererF = 15296348553016655530U;
        aWandererG = 12111607563899706982U;
        aWandererH = 11704526267897837876U;
        aWandererI = 11385847656946763883U;
        aWandererJ = 17866497206430690542U;
        aWandererK = 15939836288658355666U;
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_c, fire_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0xE09D6A4AF73762BCULL; std::uint64_t aIngress = 0xE94ABD87594C3CF3ULL; std::uint64_t aCarry = 0xF71F66D2BA2923B6ULL;

    std::uint64_t aWandererA = 0xB815EA6B6A406B6FULL; std::uint64_t aWandererB = 0xFA5F694540ED7FE8ULL; std::uint64_t aWandererC = 0xB2BA8D26A8F2B095ULL; std::uint64_t aWandererD = 0xEE5D09DBAA0F4126ULL;
    std::uint64_t aWandererE = 0xE840141CA624CB77ULL; std::uint64_t aWandererF = 0xAA8F1374184EDCD9ULL; std::uint64_t aWandererG = 0xDD2AA00E39FE2097ULL; std::uint64_t aWandererH = 0x8107F6D876D6057EULL;
    std::uint64_t aWandererI = 0xAC6AD8A37019593DULL; std::uint64_t aWandererJ = 0xE49ACBD6C749C809ULL; std::uint64_t aWandererK = 0xF794953F70263F5AULL;

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
        aPrevious = 12237612706070870229U;
        aCarry = 16844508172520212568U;
        aWandererA = 15161923733523875979U;
        aWandererB = 11284215219010048522U;
        aWandererC = 9811584979695952279U;
        aWandererD = 17827988467604027220U;
        aWandererE = 17764503699869089122U;
        aWandererF = 16985872939147079697U;
        aWandererG = 11503619663788720263U;
        aWandererH = 15024596842444153898U;
        aWandererI = 17342069645606609654U;
        aWandererJ = 16650553163318756780U;
        aWandererK = 16237174208948057114U;
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
    std::uint64_t aPrevious = 0xDEB683B28557CFA5ULL;
    std::uint64_t aIngress = 0xDC7178FEA3BD9AFBULL;
    std::uint64_t aCarry = 0xD0AF74B3028C68F7ULL;

    std::uint64_t aWandererA = 0xD485A6F7A921E809ULL;
    std::uint64_t aWandererB = 0x8E9578EC2D25073EULL;
    std::uint64_t aWandererC = 0xE457069462DC7C0AULL;
    std::uint64_t aWandererD = 0xA6CB5272D2528077ULL;
    std::uint64_t aWandererE = 0xC42753B99D8001C4ULL;
    std::uint64_t aWandererF = 0xFC8D2DA6DC36AC96ULL;
    std::uint64_t aWandererG = 0xBA68B0A7F10C9479ULL;
    std::uint64_t aWandererH = 0xA4A4AE53714C07EAULL;
    std::uint64_t aWandererI = 0x98A1F47C45581020ULL;
    std::uint64_t aWandererJ = 0xF8138429EACA84E1ULL;
    std::uint64_t aWandererK = 0x87B81B3B3C928EA4ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
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
    // write to: work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: snow_a, snow_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
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
    std::uint64_t aPrevious = 0xAC7C1EDE17C3DCDCULL; std::uint64_t aIngress = 0xBAE068685C03F81BULL; std::uint64_t aCarry = 0xA2F1394C5F748415ULL;

    std::uint64_t aWandererA = 0x8841932A52AC59C9ULL; std::uint64_t aWandererB = 0x80AD5E4A8E8E98DDULL; std::uint64_t aWandererC = 0xC0433EE0E3D6AFF1ULL; std::uint64_t aWandererD = 0xB5944A949001A6D7ULL;
    std::uint64_t aWandererE = 0xAEBF9C7BAC7D042DULL; std::uint64_t aWandererF = 0xC6551C2B69D03489ULL; std::uint64_t aWandererG = 0xFB2ADDB8FA34ABC1ULL; std::uint64_t aWandererH = 0xEDB1621C99502EABULL;
    std::uint64_t aWandererI = 0x9B7B4B392CDDF2CCULL; std::uint64_t aWandererJ = 0xE2E82411AB42CE92ULL; std::uint64_t aWandererK = 0x91A968AAF658A99AULL;

    // [seed]
    {
        aPrevious = 16340234832179523009U;
        aCarry = 16095033658896189147U;
        aWandererA = 14005939394170996148U;
        aWandererB = 15991527429849792665U;
        aWandererC = 15019667404586291449U;
        aWandererD = 9880239775161061104U;
        aWandererE = 13421322089248044027U;
        aWandererF = 16324143750143842648U;
        aWandererG = 16554844164516674836U;
        aWandererH = 9674240446931674598U;
        aWandererI = 11076580759537232422U;
        aWandererJ = 18115826510716643765U;
        aWandererK = 18087171240074490649U;
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
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 1 with offsets 2468U, 3172U, 6683U, 6871U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2468U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3172U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6871U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 1, 3 with offsets 3394U, 2997U, 1003U, 4398U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3394U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2997U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1003U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4398U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 3, 0 with offsets 2460U, 2801U, 1269U, 3901U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2460U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2801U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1269U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3901U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 0, 2 with offsets 7158U, 7857U, 2770U, 7538U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7158U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7857U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2770U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7538U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 0, 2 with offsets 1158U, 1558U, 310U, 785U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1158U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1558U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 310U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 785U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 0, 2 with offsets 1439U, 1003U, 1185U, 891U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1439U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1003U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1185U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 891U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 1683U, 1672U, 1943U, 565U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1683U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1672U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1943U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 2, 1 with offsets 1476U, 1573U, 1373U, 612U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1476U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1573U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1373U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 612U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1555U, 1442U, 437U, 847U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1442U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 437U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 847U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 1 with offsets 6520U, 272U, 4608U, 5363U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6520U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 272U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4608U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5363U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 3 with offsets 5108U, 2459U, 7937U, 6030U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5108U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2459U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7937U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6030U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 2 with offsets 7722U, 7372U, 7342U, 5700U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7722U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7372U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7342U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5700U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 0 with offsets 3555U, 5534U, 1962U, 7994U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3555U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5534U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1962U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7994U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3815U, 3636U, 5733U, 6227U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3815U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3636U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5733U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6227U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1842U, 1622U, 1650U, 1717U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1842U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1622U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1650U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1717U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1623U, 1629U, 2005U, 667U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1629U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 667U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 219U, 387U, 850U, 1770U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 219U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 387U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 850U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1770U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 368U, 481U, 1984U, 48U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 368U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 481U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 48U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 [0..<W_KEY]
        // offsets: 316U, 1388U, 1939U, 412U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 316U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1388U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 412U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseASalts = {
    {
        {
            0x419A9B9FDF1ECF8CULL, 0x11019EEA461E4BBDULL, 0x5F775121A49D9D5DULL, 0x4B3AF4DC327B69E3ULL, 
            0x087828E09F50F272ULL, 0x85F97CF5D6B8B473ULL, 0x1E67EDE7F3A896F6ULL, 0x1011EED6961DC6D6ULL, 
            0x55D4A009EECD90C7ULL, 0xAE1C2D6567F069FAULL, 0x20CD2A21FF6C15A4ULL, 0xA4691AADD780A4ECULL, 
            0x078B98404787072EULL, 0x29D73EE771C37A92ULL, 0x11640425A0F41184ULL, 0xD72C7D13703796E7ULL, 
            0x1EE8540665946C6CULL, 0x1E339DC694488BAAULL, 0xEECB0030E464DF3DULL, 0x158DC6D1C42AE2A0ULL, 
            0xD5B1B8A5FB4C9B1FULL, 0x9A6ACB828F2255F8ULL, 0xA33A0CE4AC1D7773ULL, 0xBF6E85A3CDA36BDEULL, 
            0x64E3793DFBA8FD10ULL, 0x598347D0E2FD1B97ULL, 0x3ACE14DDF4742845ULL, 0x337E070E24BA457BULL, 
            0x2D6D88735EC77F8AULL, 0xB479827591A0829EULL, 0x9643C0493DDA586CULL, 0x535C69B9EDEB1B91ULL
        },
        {
            0x599800598696CD00ULL, 0x99A9559DEF8D1C06ULL, 0xEBA83CA4772B1AB8ULL, 0x0992AFEE6D00555FULL, 
            0xB0EE5BCEC81A6F00ULL, 0xCD682CB5FEB61566ULL, 0x3360EBD321D8407CULL, 0x045724FC32B3D30FULL, 
            0x86F059C4DD8D2ADCULL, 0xD95D6D6794A8DBD0ULL, 0x5BBFC3AC1B7E4C96ULL, 0x73E0FF5A7DCFDA76ULL, 
            0xC5ECC1084380EE5EULL, 0xDFFF94E00AF65C98ULL, 0x445571210EDAB503ULL, 0x72DB0A83E98590F1ULL, 
            0x8B497702ED49E8A5ULL, 0xB072A4908ED6419DULL, 0x01DCA53D96A6B28DULL, 0x6969E5E8E3652FDFULL, 
            0x1CC815C828198053ULL, 0xDB2BE7F50C0EC25BULL, 0x24DDAB512CDB0C33ULL, 0x2DAFF00C814381A9ULL, 
            0x40495E0CFD021660ULL, 0x3538C36AFF8E3342ULL, 0x5DC97ADA4F0CF210ULL, 0xC4FAAF8092D76079ULL, 
            0x8DB53F8D41DC7A1AULL, 0x030DD9EA5052ECD9ULL, 0x8D1E064EE3AF06F6ULL, 0x8524D34B4AA9DA9BULL
        },
        {
            0x1017C925FDB34B03ULL, 0xA81B1D4BD5641AE4ULL, 0x5969E762019A16F9ULL, 0x03398CD698BA1EDAULL, 
            0xA502C0C76DA6D169ULL, 0x7D30B9498E740DF7ULL, 0xFFC0CC32427869CCULL, 0xB27F47991A69F960ULL, 
            0xA0C413D322C24F81ULL, 0x2042538D91D0C2EBULL, 0x70488A213269F251ULL, 0x2E84A4DFDB73ACA0ULL, 
            0x422D335D6E852866ULL, 0x3368F4EE69C33D1FULL, 0xB320B91EC12E3744ULL, 0xF7800AD1C32E01F9ULL, 
            0x9A3338E80F5CAF32ULL, 0xE754D31FE5C78B90ULL, 0x197EA4155FBE4AB8ULL, 0x6E4C8497C03500E9ULL, 
            0xDAF76F632BB4884DULL, 0x672207EFC708F27FULL, 0x710EAD552ACCBAF1ULL, 0xAAE398B7809CA87FULL, 
            0x4A234EBA6D0598A1ULL, 0x5107391F378E6E6AULL, 0x5D63AF4618C40B12ULL, 0x67619D1C3A0D6736ULL, 
            0x6CF9B15BBEC68CE5ULL, 0xF9C7CC2140B8DFADULL, 0x8B3E45D4DFAE280CULL, 0x007D0B4224BD537FULL
        },
        {
            0x58F6413F15B42A74ULL, 0x50E287BAB16E4A9AULL, 0x173FE20F72E04D77ULL, 0x25B4731114B8A670ULL, 
            0x0124423733B6A9EAULL, 0x6CF7532A7A047E1CULL, 0x0247BEA7D15C6816ULL, 0x98C03604D3B21AA2ULL, 
            0xEE40C64E8DBFB5B1ULL, 0x338BDAEC629E9AA1ULL, 0xE44EDDCD90401BDCULL, 0x2FB130CA3361DB53ULL, 
            0x1F64584370613D27ULL, 0x8D36495AED05BA19ULL, 0x2C1DC7482EBA06A8ULL, 0x611A590F2843FDDBULL, 
            0x5FE3654D3FCD011CULL, 0x8B81AB9AA58B0EBDULL, 0x101279C70028F3B8ULL, 0x7FDA3B46BF32F51CULL, 
            0x2797C92B00CA405CULL, 0x787B752ED6394929ULL, 0xF2D30F9C8AC828E5ULL, 0x4411008E81FEEA24ULL, 
            0x488F3F82F3A08ECEULL, 0x589AA54EE6AC8625ULL, 0x8F54069DDF625C67ULL, 0xD8924D673C5D3E74ULL, 
            0xDCABDB7ECFEEA33EULL, 0x72A1BA313341E62BULL, 0xB566DAACB0229D10ULL, 0xECB8C461CDD8FD31ULL
        },
        {
            0x54954BCF02ECFBAEULL, 0x3C7A69B21ABAD310ULL, 0x6066E5139FA88D35ULL, 0x6D707E30396DAB2DULL, 
            0x6B392C0BFD039877ULL, 0xA8A82F37838A66EDULL, 0x19B6079CFBEB87E4ULL, 0x0E04E59204A35BF9ULL, 
            0xF58322CE2DBB2FDAULL, 0xBF310859C00D124EULL, 0xC663AF6008E74EE3ULL, 0x92E967171C8FEBE5ULL, 
            0x74D57D3848F16569ULL, 0x1BC1DF5C185ED16CULL, 0x1D30B1DA7D6C7BFFULL, 0x1FA962F8FAC15A46ULL, 
            0xE844A83B50564F35ULL, 0xB7EBC46D8C937B5CULL, 0xC39D3AC59D081F05ULL, 0x29405D1EA9D6F4A3ULL, 
            0x71F01CFCC7D3AF60ULL, 0x571F28AAEEE40EF6ULL, 0xE14DAAB1ABB65F08ULL, 0x94314394AB0EC286ULL, 
            0xE30CE2803E53B379ULL, 0x31D0A530676DB27DULL, 0x71E989F3AF1DD3DCULL, 0x3528572A20465E18ULL, 
            0x8C86ABC6E4135A2FULL, 0xBDBE3346753C39C8ULL, 0xB60350C9034E9D45ULL, 0x77F3E636F316B8AFULL
        },
        {
            0xD7ABD1AE485EB112ULL, 0x7E14B03D0F8A1A2EULL, 0x81364C8707C9B9E3ULL, 0xE01FCA4DA6FD5BC7ULL, 
            0xA19A6D519266B181ULL, 0x4E038D8F392E7AE3ULL, 0xB0097E0E18E35C83ULL, 0x35470C49AD182F9AULL, 
            0x762A38BD2B9A4B7DULL, 0x961C3FA74615EAFBULL, 0x9B40129C27AAD90FULL, 0x036F946D89B884B1ULL, 
            0xFF76AF1667BA08ADULL, 0x031666E3ECA59C55ULL, 0xC58AE0E253DB8C34ULL, 0xCB8DC6458C3B6CF9ULL, 
            0x80D9F991A3990A2BULL, 0x53302A9226EE06F0ULL, 0x9FE4FC0769245495ULL, 0x6F308C2D2F1BDAC1ULL, 
            0xE4DA07B90B81B421ULL, 0xF310509126C77702ULL, 0xAB3272BE553E2F9EULL, 0x48600C3C9198E6CBULL, 
            0xAFC767A33D385B6AULL, 0x37DE6B30A804FE27ULL, 0x1D3200131E238240ULL, 0x7C6EFA2905EA57EAULL, 
            0x5A738E93EC6571E3ULL, 0xCDB53F37583A5BB9ULL, 0x466E0E5DE0400E44ULL, 0x69F5231E1FD56684ULL
        }
    },
    {
        {
            0x28A8DACB50FC143BULL, 0x354CF2DA219F78D1ULL, 0x14252DE02A036C30ULL, 0x6668ABD8A89A97F8ULL, 
            0xCE1199A9D954A21CULL, 0x854E0F4B57F5732AULL, 0xB957A5C5AC83FC8EULL, 0xF1C28A0311FC13B6ULL, 
            0x86703F92680650C0ULL, 0xC5167C4C7C98BF1DULL, 0x79A565BE6BF4BB9AULL, 0x4CCFC10DFA69CA09ULL, 
            0xBE329894E607AB9EULL, 0xC7A7357D4B8D4D0AULL, 0xEFF95ADBFBE2FD13ULL, 0x598D0CF9EDE8E348ULL, 
            0xD7A008D8E3A81796ULL, 0x869FA0D109D581B9ULL, 0x295670E2EDB10F16ULL, 0x03BF335671B43281ULL, 
            0xF66F6106DA694AD5ULL, 0x21A6575EC09DF248ULL, 0x954B14ADFE63E6B8ULL, 0x57F6CF6273E819EBULL, 
            0x9B3EEB33CC8237F6ULL, 0x81C9B059B5922C5FULL, 0x040B4E4D6596565EULL, 0x50F8CF54A790F440ULL, 
            0xA4C3E26267DCB26EULL, 0x062C3882C5213673ULL, 0x15AE48AD05540454ULL, 0xB95F65E4769BDD5CULL
        },
        {
            0x60B2874C41890C32ULL, 0xA8FD53085EF7CCF8ULL, 0x2678F5A93F9B0B98ULL, 0x5ABE0CD502D59792ULL, 
            0x8EF74F14D3538399ULL, 0xE91F1F49A5CD808AULL, 0x796B21AD133259B1ULL, 0xA48464B3F3D33F4EULL, 
            0x90CDC1771E38BADDULL, 0x99BE2393AFEC7B1AULL, 0x64982552CF7B21AFULL, 0xA764477633147E85ULL, 
            0xDEEEF2EEAE358505ULL, 0x68A57B536EE08D7CULL, 0xDD078AFEDB132A8CULL, 0x97B450AAA9C62A09ULL, 
            0x280BB55C8690F148ULL, 0xF35BDD82978DD3B1ULL, 0x5B403185659617C6ULL, 0x0499CDD66C8B04F8ULL, 
            0x74C10ACE3F9EBA8CULL, 0x05D78291A394B62DULL, 0x8BBB35A05D5B96D7ULL, 0x0DC5C0DDD77F4680ULL, 
            0xD25FABBDF2D59F8DULL, 0x84FEAA335B35A41EULL, 0x28646F7B9A7718A4ULL, 0x6F7B4BCB477F57A1ULL, 
            0x7132E3042D7354FDULL, 0x1E812ACDAC0A479AULL, 0x3B39E2D17A455A34ULL, 0xC352E2CAC87369F0ULL
        },
        {
            0x78F943BFD07D6FC8ULL, 0x434CFF02E1781B59ULL, 0x35E817F84C162501ULL, 0x2AF71F87E18142A0ULL, 
            0x478FCCEB061CE491ULL, 0x23FC156886C145F0ULL, 0x66169C24ACF12D33ULL, 0x10A227226C3DA4CFULL, 
            0xA4099F9C81F32D68ULL, 0x485BA918779C4AC1ULL, 0xAA151B90899D41DEULL, 0xE0BE120A67B09456ULL, 
            0xFFBB21D5700E7F38ULL, 0x9E23C7A060AD0B97ULL, 0xFFB8291EF4102E0FULL, 0x48AB6B88D6FB33C4ULL, 
            0x0084DEA10C786E92ULL, 0xFE3DCB1273092C68ULL, 0x8B7640E33C4E458CULL, 0xBC0F9AEAE3B5AD4EULL, 
            0x75CD9F820DD914BDULL, 0x1E3F80A262B7F79DULL, 0xF9D5C3E5BC8DE1B9ULL, 0x7322181864698621ULL, 
            0xF2BC57ECE9790A4CULL, 0xC12055B8E4C5B907ULL, 0x8847E2E41650D3FCULL, 0x2473F4A97DC07E51ULL, 
            0xAEE23D99B43A0648ULL, 0x7864993DB2788E32ULL, 0xCB8D06BC63D7DF35ULL, 0x5F128ADDD0AB0A8DULL
        },
        {
            0x864B4138021690DFULL, 0x011874A87C69D815ULL, 0x28E466CE6777438AULL, 0x646C9A823104CCF1ULL, 
            0x9F7F6B5A39BC785DULL, 0xDCCEE67351EA7879ULL, 0xDF0E574224B7B4B1ULL, 0xD5FF1A18D7AE553BULL, 
            0x72C22B01478DA566ULL, 0x2A93A2E25C427115ULL, 0x90F68D1500146673ULL, 0x618169278C508610ULL, 
            0x2EA8C886D8EA53CAULL, 0xF18A5FD7F19FAD7FULL, 0xEE058C8E361920E9ULL, 0xED9C26ED03E7082AULL, 
            0x0939D30CB506A51DULL, 0xD95EE388BD0C85DCULL, 0xE9CE6491ABD0A7C9ULL, 0xAC6C080520E216E9ULL, 
            0x25AC85DFD76D1387ULL, 0x3865BB105823C1D5ULL, 0xE9B2FDFC7AD67EAEULL, 0xE47743E2EFA464CAULL, 
            0x4C2A9192EAC14520ULL, 0x1BA387E57FED67DFULL, 0x50F024388DE24C6BULL, 0xB3E8A7135FEC53BCULL, 
            0x8B4C8C9ED16FABA2ULL, 0x3D19468C57AA7226ULL, 0xC69128D160A35276ULL, 0x2689A7C022049D3FULL
        },
        {
            0xBD9FB23F3312556DULL, 0x6B70E2393290B01BULL, 0xCC0E1E86FD2A08C1ULL, 0x1263867C095364CAULL, 
            0x898C7DDE901CA2F4ULL, 0x242A9BA32E0E1420ULL, 0x3C56B97FCC71D01DULL, 0x314AC76A09066897ULL, 
            0xCEC4B10F2DFB0BC8ULL, 0x9DC41E0BDF310DADULL, 0x056709834E83D8C9ULL, 0x886BB82AE72CBD1EULL, 
            0x8C2D31B7F1C06E2CULL, 0xFAF5486E9C35702DULL, 0x56D601DF995569ACULL, 0x306244559F2F0DB0ULL, 
            0xAF2274814D0F5992ULL, 0x6FA1009D32741FAEULL, 0x4391FE9631D950CEULL, 0x9B034D52686B6DBBULL, 
            0xBCD9478B585A2F10ULL, 0x552E0CFEF0D96F82ULL, 0x9A9829B62D277FB4ULL, 0xAFD7FCD3F02381CDULL, 
            0xE9079EEA43308CF7ULL, 0xC9B6A1E40C3BDA51ULL, 0xEAB33A57A45A5F93ULL, 0xDD74DD510DA8748EULL, 
            0x17DE8E7673AC87E0ULL, 0x968C60FD0AE2A30BULL, 0x99290D3EE8ACB700ULL, 0x67E1287CC45304C6ULL
        },
        {
            0x0BD1668F3ED79DEEULL, 0x7F15BF4801A8CD28ULL, 0x0D68D72FD9C9E59BULL, 0x516F1981AB70D6BDULL, 
            0xB7D32D0FF02415D8ULL, 0xF006003932136944ULL, 0xEDAABF5D4C02D061ULL, 0x21BE456EF3AF81FBULL, 
            0xEC7BED66E362C1C2ULL, 0xF93B9E6413026BC2ULL, 0x3B92A9050DA9E667ULL, 0x94BF988C6E80BF8FULL, 
            0xACC729D6088585DAULL, 0x4B687F72FCCD5CCFULL, 0xC953C93EF6DBC539ULL, 0xAB534C6102687D85ULL, 
            0xF02B9EC3AF7F17CEULL, 0x61A2D62586EEE861ULL, 0xB31BA5D4416A63E8ULL, 0x567A9137F7DD0F05ULL, 
            0x697A23B55173B8E0ULL, 0x497873A3D670F7AAULL, 0xE73FF31A70C474B7ULL, 0xAE9C9449262895CBULL, 
            0x5D72ED5055923943ULL, 0x33E4EBC8A3D1B5B4ULL, 0xA8F63BA4E6E652EBULL, 0x6BC76C650AD8D147ULL, 
            0x9411B8926B86B302ULL, 0xE5982411D8A5A9D3ULL, 0x55B91BA52D28EBFFULL, 0xEA26AFEE6B5489F5ULL
        }
    },
    {
        {
            0xAC88C22CAF88A51DULL, 0x352A4FD5D30029CBULL, 0xF677F341D388BBF2ULL, 0x123051585F2447DDULL, 
            0x4F4EA6C91236E42BULL, 0xBE819F0CB2EF096AULL, 0x17EA6C8E6E57F2EFULL, 0xFB094BEA289A7735ULL, 
            0x95D2EF2605AE3946ULL, 0xEEC11F599945F126ULL, 0x2BDF448539E09B4EULL, 0x87BCF1CD02DFED26ULL, 
            0x9A18C51FDE858F16ULL, 0x414CC52FA42C4D4CULL, 0xC7AB27E9DA6E89AAULL, 0x66C13683730B8CA4ULL, 
            0xD478384D95ADD389ULL, 0x6E2BB3A224041B00ULL, 0xEA099088CA30EA3EULL, 0x90DB4E7CDA52A4B8ULL, 
            0x436170F048F4B2DCULL, 0x5E26A52F6E273948ULL, 0xB3EF925CDAADD9DDULL, 0x531A9F0745B93DCDULL, 
            0x182109094CF9D060ULL, 0x8E34CE4D325E2A59ULL, 0x9E795D488DFE8445ULL, 0xF027309AC492F11DULL, 
            0x095AE401FB1C09D8ULL, 0x1183A19CC04F48FAULL, 0x977DDB7420AD8BA8ULL, 0x818C5E9EB229FCABULL
        },
        {
            0x79A0676CD45D318BULL, 0x4FD4C4F8BFAF8191ULL, 0x5198A744BF8A31CEULL, 0xC2AFCCC9FF02C3A7ULL, 
            0x6FED9A3DB8DFA6A0ULL, 0x7E6C4D2E5D7A61D1ULL, 0x1C4FE5E561DF53EDULL, 0x9DA66C8239D418A8ULL, 
            0x97CB18A6D008D0B9ULL, 0x36B0D12F14A6A472ULL, 0x5CED3CE31CB9546BULL, 0x9AB9587C0FFEF371ULL, 
            0x852FC9360259F9F3ULL, 0xED5555DFE09EF6A1ULL, 0x037CEB1223980E07ULL, 0x9C3655F011F76A36ULL, 
            0xA32E7B442D055F07ULL, 0xD667317579F328DCULL, 0x5DAF65AB2D4164FAULL, 0xDBEE71D40E897014ULL, 
            0x790F2C8854938332ULL, 0xE765F5FD234CC7B3ULL, 0xB161ADF4908C6E8CULL, 0x40C2749EBA94A736ULL, 
            0x2B72B95FEC4FB572ULL, 0x93F993D388504B2FULL, 0xA781329C62AF6A57ULL, 0x19F0ABFF4E420160ULL, 
            0x3F2276948F44A7AAULL, 0x402ADD287F678448ULL, 0x017B60011E1D782AULL, 0x3E09CA20BA57D757ULL
        },
        {
            0xE10387C203CAA541ULL, 0xDC4B3411EC592E14ULL, 0xC808F3CF6823F671ULL, 0xE2717D2C0881BB94ULL, 
            0x2C80B77D9515600FULL, 0x5097C0FEA52713BFULL, 0xB7FA84AEFF0E59BCULL, 0x251DC53A5726157EULL, 
            0x1B4CEDAAE3817EC1ULL, 0x802F5859D8CB5F55ULL, 0x4B37157313D6C989ULL, 0xF0D13F1A52277F02ULL, 
            0x3302631228073D1AULL, 0xF3CFE1F4EA82796EULL, 0xD995F00B37BF6DCDULL, 0xF688B0052270CCB2ULL, 
            0x4AA820992264FCA6ULL, 0x8CEC7D6964E06F88ULL, 0x782656F39827CF57ULL, 0xA249D234E4ED95CEULL, 
            0x86BDDB92C4F2DB42ULL, 0xF845D57E745EA057ULL, 0xF2EA40DA232E2DD8ULL, 0x896F02FD9543347CULL, 
            0x14FC1711A392D428ULL, 0xD87438CDC127FC37ULL, 0xBA7CF37150105077ULL, 0xA7CA48E31CEE44B7ULL, 
            0xA09DF18D6AD9DA13ULL, 0x9FD88B2DCA7A65A8ULL, 0x5F1C5AFEFEC081C9ULL, 0x995521FE15AC4A9EULL
        },
        {
            0xD300B9C8A0F7B337ULL, 0x107E653090C48C97ULL, 0xB58265B832A9A766ULL, 0x58C88706740AAE8AULL, 
            0x92B1EEF3258A6E5BULL, 0xFCAD00234321A27CULL, 0x8ABADC9129C23137ULL, 0xE8604E96C165D517ULL, 
            0xA397760CFFF0E06FULL, 0x5B6219219C98D2FEULL, 0x857776FF4DEBFFCEULL, 0x0385D1CEBA125F3DULL, 
            0xBCFA759FCC538781ULL, 0x08515E85A6AC298BULL, 0xB099CB152945C580ULL, 0x20F47ED08031EE25ULL, 
            0xECD8F20183A8B363ULL, 0x12B7ED2D7F97F534ULL, 0x3D08CC234E6E58A8ULL, 0xEAB588B69A0EAE13ULL, 
            0xB5278CD949FE3583ULL, 0xEF9A7DCF385600BBULL, 0x4FF712676B6C049BULL, 0x3125EDEA9145348EULL, 
            0x287E090173D1DA8CULL, 0x49E9DB39F269DA3FULL, 0x72F8787FF6CE621CULL, 0xBDA07F929B5A4CADULL, 
            0xBBA4206054E899EEULL, 0x665934D99F94D0DBULL, 0xE3FE3626A136A3A7ULL, 0xB0DBB60309475360ULL
        },
        {
            0x33D7835C72E9B348ULL, 0x12A6C3A1074131FEULL, 0xBA67E6524B16020CULL, 0x8C22F7878C5962FCULL, 
            0x2C34E3985ACFBDE8ULL, 0x8A86541222D28D6EULL, 0x884F8E11F76134C4ULL, 0xF4D62B1E8924448FULL, 
            0x3B2723F2EEC16922ULL, 0xC70A5EFD820B1FE3ULL, 0x810F476E37DE4D0CULL, 0x220C78E35D63966FULL, 
            0xC525CB944051E7B9ULL, 0x3FDD167C3CDE2BA8ULL, 0xF3D4A25F6F905258ULL, 0xEE7A0E6D73540A59ULL, 
            0x5F32ECE07B9F067AULL, 0x3C92FCD2183554BBULL, 0xD5D388EDF47F8BC0ULL, 0x5CC5EF5AB848A24EULL, 
            0x2FFFC6CE0DF0F5F8ULL, 0x1924CE9571B9CFF4ULL, 0x709FCC181933578FULL, 0x43E6596963FF05D8ULL, 
            0xB9E37433EF73CA58ULL, 0x8DEF60AA047612B5ULL, 0xD1451DC2F0D78AF4ULL, 0xA8C8AC7FBFD1AD9DULL, 
            0x3A8878B4F5E037B8ULL, 0xAE203466ED360ED7ULL, 0x9F75C2B95C1C02F5ULL, 0xA1FFDDAA2345CFDDULL
        },
        {
            0xE002FFD2A4251BDAULL, 0x2F7F6F07D2336D17ULL, 0x99DB77CC3CDB6FD6ULL, 0x7971DF66066E1EA7ULL, 
            0xF927E117ECCCD457ULL, 0x53973FB648F3D85CULL, 0x60971DFB5BBAA51FULL, 0xE1B95654470CF432ULL, 
            0x0CC857E71F32EC34ULL, 0x91B4DC955AD78D75ULL, 0x459B42CBA2C63FD4ULL, 0xA4980C7E9379A44BULL, 
            0x2E9179E796A2E5CEULL, 0xBC957652015C5CDBULL, 0xE7FB1C2FD85AABAAULL, 0x344E9E1E95EF53F7ULL, 
            0x3462BBF01C0F280CULL, 0x388BA170AF2549BBULL, 0xFB3F53A365F85FD6ULL, 0xFCEF95B65311A444ULL, 
            0xD5835F1FFF797A36ULL, 0xCE51303B08706AFEULL, 0xBC1E20C514E69060ULL, 0x3482E38356480C72ULL, 
            0xE5CFD179D6C68C8BULL, 0x7536DD7485FE486CULL, 0xB3F522EF8EC7544BULL, 0x3E1B7D50C10D38B5ULL, 
            0xD0EFAEBDD3D7148AULL, 0xF4C5A0BAFE8D4A3FULL, 0xCF54FA3820101650ULL, 0x455DD29A38D1AEB3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseAConstants = {
    0xB321207A70F16F1FULL,
    0x2E40F6CBB2B0497FULL,
    0x6144DA1291BD2078ULL,
    0xB321207A70F16F1FULL,
    0x2E40F6CBB2B0497FULL,
    0x6144DA1291BD2078ULL,
    0x31B411B1A5101A6BULL,
    0x78621025D0C60928ULL,
    0x9E,
    0x50,
    0x94,
    0x8C,
    0x7F,
    0x13,
    0xC9,
    0x39
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseBSalts = {
    {
        {
            0xEA264D0E900F3221ULL, 0x4D3A83656F9C0890ULL, 0x033967152C0DF365ULL, 0x5DFBD9247DADA832ULL, 
            0xB37B075D6A421B80ULL, 0xF9157B8EFA239945ULL, 0x7781C57DBF0B973FULL, 0x1B765207C003FB8FULL, 
            0x55C85F180D958B9DULL, 0x1E2F951D932D9619ULL, 0x0C9A8C5ADD492B0EULL, 0x7D119741A13C6623ULL, 
            0xE535AA5C895961A0ULL, 0xF9581DAF428C14EAULL, 0xDC911F6294E4F8E4ULL, 0x5336DDA15126D63EULL, 
            0x6C15B8B55F9B1EF6ULL, 0xAB4A85F8AC2F8509ULL, 0x6D9F3C70AD3F4983ULL, 0x1C1B21F8E49FE621ULL, 
            0x97053C5F6ADA824DULL, 0x300A79C7F44F71D1ULL, 0xFF5643F2577A08F6ULL, 0xD91FF5EE3158211FULL, 
            0xC3AAD35B52E0416AULL, 0x8461A14C294776F5ULL, 0x454B2FA3F70C075AULL, 0x47986A408F34FD9FULL, 
            0xDC3E300DA6534235ULL, 0xA593E247C86CE8FBULL, 0x225838F1F0769826ULL, 0x798E81479E665404ULL
        },
        {
            0xA6BDDF2BCE6AC279ULL, 0xD2EFF38C81002D23ULL, 0x29C997E6968E53FEULL, 0x6CBA6519271BEC10ULL, 
            0x262C46A21744ADB7ULL, 0x0EDF5873E63F8AB1ULL, 0x7D25CE835A79C110ULL, 0x94F6CF2D6774933CULL, 
            0x0F9FC22B5FAF1B08ULL, 0x00477E1EF08A3BD1ULL, 0xF2324E4883E56534ULL, 0xA3120E2F9865D1E3ULL, 
            0xA0E104DDC36755DCULL, 0x06427BB176663A84ULL, 0xDFD4322A96E91986ULL, 0x4B682DB950725EC4ULL, 
            0x2AF4932EEDBF843CULL, 0x26C5039D86CADFA7ULL, 0x47B3140330200995ULL, 0x6390E21040468237ULL, 
            0xC6A7C18BBFD1F685ULL, 0x9D1B1BE18D3FD366ULL, 0x34D6D4D7585BAC2CULL, 0x5F4E9B05A0474AA2ULL, 
            0x6C12C9112D51A010ULL, 0x34BA5AE4841DA137ULL, 0xC92C526773C4766EULL, 0x335B51AB894D7AD2ULL, 
            0x59131BF903BE19A1ULL, 0xB863CD1040EC2848ULL, 0x5FE9EB6842D1BB80ULL, 0x20BE4BABC5B4D49FULL
        },
        {
            0x80D44B0E58E065A2ULL, 0xB126926B7E866851ULL, 0xC624FAC0C168DEECULL, 0xC1361E19D9C007A3ULL, 
            0xEAEFCB1656E0A7CDULL, 0xF1060EC579957366ULL, 0x246720CB88654A53ULL, 0xCF6728EE698D273FULL, 
            0x3C81CEE89E3B7207ULL, 0x71B2AC50A5A763ECULL, 0x1B6FE4EABBCF0115ULL, 0x880A5ED4F47F1D06ULL, 
            0x37FE1B2F1ED8CEEFULL, 0xB79E6446F8EB352EULL, 0x57A87F79F9CECD2CULL, 0x14CA6E35F0D3B5FCULL, 
            0xC53E2E99A31EEF7CULL, 0xC3B1F31D5E375581ULL, 0xEFE808BB5C5F970FULL, 0x1F4A792F8110FA8EULL, 
            0x3C3CCC8DC4714672ULL, 0x34881AE5A06547A3ULL, 0x6E5EB6BB992EB10BULL, 0x1C038608D0E490FCULL, 
            0xA889A08AA3E7809AULL, 0x473C3C667660E99EULL, 0x1D5C6A3E3B099668ULL, 0x8DF8C49EAFCCF6B7ULL, 
            0xED2EED8D0267143CULL, 0xB50B1B84C2F81DBFULL, 0x2B570A9FC57556A8ULL, 0x8A1453431A11CB3AULL
        },
        {
            0xBA6B7635D9E5EA16ULL, 0x65B57FB0FD328780ULL, 0x5CCA131AE94853CAULL, 0x2FD83FB656D6F6F3ULL, 
            0x2CE83CA56362790DULL, 0xB4C893AA7C0C89D2ULL, 0xFF50A3BF25018167ULL, 0x44805D3537E9888EULL, 
            0x5EA897C6E8582E1AULL, 0x87000150B029048DULL, 0x728B18F283B389C8ULL, 0x33A71F0A0191C59CULL, 
            0x650612AD414E27C3ULL, 0xB17AE63DCEDDC6F2ULL, 0xBD831D58AEB7871CULL, 0xB38F48E6418576D2ULL, 
            0xBA0A2210777BABA7ULL, 0x574FFC3C9CACCF06ULL, 0x5B13880095C86CDDULL, 0x20AB930ABB6EE436ULL, 
            0xA8557A6CA2C5366BULL, 0x3252D69DD3A0C6CEULL, 0xBDAD100597C915ECULL, 0x21ED1B4AEF5525CCULL, 
            0x6AA2D62AEE1635ACULL, 0xA956085188D6BE07ULL, 0xB30C8C446F28694CULL, 0xBEB1D7BF4EA732B2ULL, 
            0x62138CA528B7D853ULL, 0x012D72148E3BB1B8ULL, 0x1BBA957D36C1220CULL, 0xE250B75868D98F9EULL
        },
        {
            0xD881F980322A39EEULL, 0x14AE2CFA4A3990BCULL, 0x3BCA42C3BA670E94ULL, 0xDB9451503AAD6986ULL, 
            0x87F5AEB52D0439C8ULL, 0x290F26FCE8BAE851ULL, 0xBD0FC6405ED743E6ULL, 0xB51B8E95F704196CULL, 
            0xDD01971CADC3810EULL, 0x6DECAF236CDCD5B9ULL, 0x09A8ABA2085D816EULL, 0x9DC90D35D9A04349ULL, 
            0x226386F23E943839ULL, 0xA9CF3FD89B11734AULL, 0xB83326C6D30BB8F7ULL, 0x64EC1E8C9E27B133ULL, 
            0x4331B7FC7BB1C5DAULL, 0xCC7AAED2C8726CC5ULL, 0xD776A7949FD2E22EULL, 0x75CEBCF147CAAFA5ULL, 
            0x435FC22EE25E50A8ULL, 0xCED14B1139AC630AULL, 0xB79B03F1C95DD310ULL, 0x68C664CB1BC1272AULL, 
            0xDFAAD6F02393A33BULL, 0x29943C837DBD6F45ULL, 0x749824B90D784150ULL, 0xCCDEAE61D846A5ACULL, 
            0x8D23101300ECA1ABULL, 0x6A0842D2E8AF73B5ULL, 0xCEE8659DFEEEAB52ULL, 0x80B2C50D6266E9CCULL
        },
        {
            0x70715B19D485C465ULL, 0xF5E9724A41AF5802ULL, 0x2663D359DDAECB6CULL, 0xFFC49EB1341DCF3AULL, 
            0xF50BB21EC3AEF0F5ULL, 0x310C1D8059CD1EB9ULL, 0xB4827928FF0912C4ULL, 0x6C3B5BE651F65960ULL, 
            0x41EF2BC697D78F45ULL, 0xEE7C98EC483CDB37ULL, 0x75A88109EF971051ULL, 0x8DCF423B31BB51CDULL, 
            0x8626C8ED488B97CDULL, 0xC9CC5109964781F4ULL, 0x643A1E335DC6B242ULL, 0x23E4A4E6BAD80710ULL, 
            0x78E79E90F70E518DULL, 0x0305F3424E167565ULL, 0x80DB6AF61BB7A52EULL, 0x92628F69497596DDULL, 
            0xC53D84DBD824A227ULL, 0xF1847CA5B9A36EBDULL, 0xA3C52A0119F573C9ULL, 0x7D5A5367FD36BD4BULL, 
            0x8284FB0BE88A1987ULL, 0xE857847DCC352854ULL, 0xE43FD9D9C8C86E03ULL, 0x78E9A0FCC67721FBULL, 
            0x244D6BEC50D3052CULL, 0xF7214720F6AF5273ULL, 0xB80D7369CC170E34ULL, 0x64AAA474AD54DD87ULL
        }
    },
    {
        {
            0x138323194B75620FULL, 0x8455D6F04ED627A8ULL, 0x1BCFDFC8150A878FULL, 0x0A19471EDA7A7467ULL, 
            0x750DCEAEC602972CULL, 0xA63B5BE853266EF4ULL, 0xD3BA7987BC87B457ULL, 0x213DFB5D40D9D76CULL, 
            0x84F9359F0696E248ULL, 0x6D007013448FAE50ULL, 0xC9B5979F2B0B60B4ULL, 0x61DE866C0445162BULL, 
            0x7AA861CE3B0A039FULL, 0xC7193B3227FE8F07ULL, 0x45E795C844E50F42ULL, 0xE9D30B2243032F6DULL, 
            0xD27B53BFD0A1E36FULL, 0x59948E45B9036817ULL, 0xF888392365AA7558ULL, 0x21F63D7AC434ABD5ULL, 
            0xED27D2037DC1BACDULL, 0x0F3FFC1EEF746C09ULL, 0x61AD44146F946E89ULL, 0x39A4060498E549ADULL, 
            0xF099F60215C9F5F9ULL, 0x9896DBFDC723E7CBULL, 0x71F1D8BE5D5DE484ULL, 0xF332D8394F157100ULL, 
            0x2B5616AB11D9A6E9ULL, 0xE6802F6ACD029D7AULL, 0x02E40878203902B5ULL, 0xA12A1E7651C0A392ULL
        },
        {
            0x16E2F5FA59FEC094ULL, 0x54326E7016F6C7BBULL, 0xE487BFBA0BD98EADULL, 0xFA3566B320A4C677ULL, 
            0x8E7B42A464F3C88FULL, 0x2260304EA0798038ULL, 0xEDC5E78D21DC051FULL, 0xEA1E4D9671ACF5CFULL, 
            0x2AC014DD99498D53ULL, 0xCE5DAAB013AF37BBULL, 0x9B375CEB44393DBDULL, 0x43193E946913AF3DULL, 
            0x1382DC6DAF06D6C7ULL, 0x596C29D4474E5BB9ULL, 0x3653A2E055C97358ULL, 0x036951DBC16C11ABULL, 
            0x322F9B9B4D6FDB76ULL, 0xA13C132B40B21FA2ULL, 0xE2F10FC1D90B6CABULL, 0x75B5FFD43E62A4ACULL, 
            0x9512BDC788ACCBDFULL, 0xEA6092A8AA70E130ULL, 0xD0CE903E41EC65A3ULL, 0x690C7D0B0965C306ULL, 
            0x8A3851BA0DC79536ULL, 0xCE88B95E151C2BFDULL, 0x724B6C6FC6111913ULL, 0xBB67C709C7A63CB3ULL, 
            0x11E86E7354B124B1ULL, 0xC6AA665B564E15E6ULL, 0x30677503305917C9ULL, 0x3E3A6C08A4EF77C7ULL
        },
        {
            0xDA8D6327FC3448F8ULL, 0x7D5B7179D156E664ULL, 0xB150BC20B8EB1CD4ULL, 0xE6D7396CBC395ACCULL, 
            0x66C0791D60A0E4E9ULL, 0xD252352FF8E0F62FULL, 0x0E8C97C085CE3A27ULL, 0x88493F69E79F296BULL, 
            0xD43EA379BB626D60ULL, 0x658E64D3C56A87DAULL, 0xF4CE7F670DC63487ULL, 0x941E6D628A111A1EULL, 
            0xEA5518B505F3F321ULL, 0xF0CA2FF66A99E228ULL, 0x07F9DE3B73066B57ULL, 0x316EB65553D22FB6ULL, 
            0xD521E86161E75B9CULL, 0x1D4D7F8E7FE5A58BULL, 0xE5510C17A5489593ULL, 0x37A313FD3F93A931ULL, 
            0xB372F5D1725FF0A8ULL, 0x5A79BEFD0D3971FCULL, 0xD14B9971B7C9C6F3ULL, 0x5ECB7AB977419A5FULL, 
            0xF4B67AD2484602EEULL, 0x2E562171BD513FC3ULL, 0xB3D40CB45E018A72ULL, 0x602C922069A73F7CULL, 
            0xFFA8F601D1C1ECA9ULL, 0xB22FF7F112214D15ULL, 0x0BB584D927602817ULL, 0xB98759CABA5A7408ULL
        },
        {
            0x2B48A7ED985E918FULL, 0x5774AC49EA3747D3ULL, 0x09557AE649C8565AULL, 0xB946CA0E8E4194A0ULL, 
            0x203D18484ED677CCULL, 0xBD128B70A249BF77ULL, 0xFC3AA4E699B8C5EBULL, 0x638EB5DFE465173AULL, 
            0x00A27CDE5EA8CDE6ULL, 0x7A3C655D188123C8ULL, 0x656B6739B3A95E7DULL, 0xCD4DF997D7661CC4ULL, 
            0xA3314E5BA32D5988ULL, 0x7EDC9588783CF568ULL, 0xB47590AD8AE936FAULL, 0xF67B298F5B99170FULL, 
            0x23376B96018A2F54ULL, 0x1ACD119442199EFCULL, 0x71B77567B3AD62F1ULL, 0xB6DD8DD58394D427ULL, 
            0xD8799B9400628E6CULL, 0x9FB3ABA41F8C4411ULL, 0xA0245E64AF67ECE6ULL, 0x721D4DC1B5B40397ULL, 
            0xC217230C94AC9196ULL, 0x68862C044141AD94ULL, 0xFEAB5910C4673624ULL, 0x43EB59AC7A64AFAEULL, 
            0x038EE65E349C94B2ULL, 0x55FDABF4FAA49E06ULL, 0x4EE9B5064E94051AULL, 0xFD5B8A38C65C1E5FULL
        },
        {
            0x4BCB919684C94202ULL, 0xB6C2F3B2C31900C8ULL, 0x1D7612E2E01B3FE1ULL, 0xF0D50B9D422DE146ULL, 
            0x6F29C18894520DEEULL, 0x24822581412A075BULL, 0x8C293B7F51E27A96ULL, 0xCE0C24C6BAE566FBULL, 
            0xF89E5072B64A2CFAULL, 0xB5B77E4EB71CA070ULL, 0x8BD2D135BF6ACBFFULL, 0x0BC640723E151B81ULL, 
            0x884983657089025CULL, 0x0D0375D8DB3B70B2ULL, 0x467BA9B2830465F6ULL, 0xB0539D29911D76BFULL, 
            0xAF81453D60678018ULL, 0xD80D762806CE3019ULL, 0x30495106AF7AB47EULL, 0xFA241A0A8DB5D61AULL, 
            0xE39A2B61BD0E7D4FULL, 0x560EFBE65EB47A9AULL, 0x48F9CAEB8DD54143ULL, 0xD9B0BC0F0F504FF1ULL, 
            0xB784D235BFFE5373ULL, 0xBB7EC7A801283F39ULL, 0x2504656D436F0EEAULL, 0x88597BB66A22ED3AULL, 
            0xCC8DF2A9C9AF4C76ULL, 0x3E51B239AA512924ULL, 0x5A767E21CB7A44C0ULL, 0x6C0A3EBC4437F677ULL
        },
        {
            0x603E8038F590B2DDULL, 0x44DB9B20D83C0204ULL, 0xD400AACEA1D6C078ULL, 0x4E94ECF81C90A7E2ULL, 
            0x83AE79BCB6D0CFF1ULL, 0xEB03479A42DB9C0DULL, 0xA9EAACB25F633093ULL, 0x43BAA6BD42793EEFULL, 
            0x0B4C462FD8DDF03AULL, 0xBA18635029A10B3DULL, 0x74525535DD14AEC9ULL, 0xF770B0CD84BC30B3ULL, 
            0x7457032DEA73E1D4ULL, 0x27294CBE0158AD4FULL, 0xB6A222C928FB78BFULL, 0x099C19B68C668CDFULL, 
            0x6215B865CC43229DULL, 0x2A69D3B9A21EE9A4ULL, 0xCAE6A19A872A392EULL, 0x7E8C7E5A77E02B9FULL, 
            0x4EFBF9E18AE5C2CDULL, 0x4315FFCB32AF5C22ULL, 0x1A237AEC9B8F46CFULL, 0x70B1BDA22EE1E2C2ULL, 
            0xFD43CB8A105B8673ULL, 0x0D08C0D2E3EC37A1ULL, 0xA20DF36452184E3AULL, 0x4B262984AE477559ULL, 
            0x9F434E7E3AD852EEULL, 0x2C541F5BE4D802D1ULL, 0x3439BD27166BC545ULL, 0x719DBF216E1F83D2ULL
        }
    },
    {
        {
            0xE46D9FB05A3FAE24ULL, 0xF6E3BEDC0A726D91ULL, 0x85ACBFAA631959C5ULL, 0x0BFF26BBDAFC6313ULL, 
            0xE60A2613E2563468ULL, 0x7E4D2A6C1DC1F4ECULL, 0xCD97C4DC298F9293ULL, 0xDDD63C321AD061D4ULL, 
            0x1C45C55440403DA2ULL, 0x452C0CB833C49BD0ULL, 0x6B5EFE672E5FE3AEULL, 0x54D53380D77F50F5ULL, 
            0x4B1E536553D56D33ULL, 0xFC1073B7C1674F3DULL, 0xCA3A74CE8BA44AE2ULL, 0xB73A50FA4B6218A7ULL, 
            0x135B58653B6889E6ULL, 0x9715A8C986CA0C5EULL, 0xB037758E13FD7292ULL, 0xCA38B02B3DAC308FULL, 
            0xCA04BCB3F2CAEC9EULL, 0x2FB46F6D950CB930ULL, 0xEA27739272F12B0DULL, 0xE4DD717FFCE054F0ULL, 
            0xDB1C636B94D04A67ULL, 0x0BC07435BAB4F745ULL, 0x39876B49ED71BBD7ULL, 0xD7ABB1CFA3D3015FULL, 
            0x960E3DDD7C944488ULL, 0x625D286767758F8CULL, 0x378B7B1729118C84ULL, 0xA00B248922244B2DULL
        },
        {
            0x4B6EA900F3DAC276ULL, 0x2B21B67473C89E34ULL, 0x5D45EB30CB5C3AEEULL, 0x3F02369F2E8C7E52ULL, 
            0x9E642416F93F97E4ULL, 0x1257AEE3F96BD9FFULL, 0x3CFFAA860E50B0C8ULL, 0xAA9687F976FA2993ULL, 
            0xC5ADF330FE25E01FULL, 0x27A3A61EA0D4FE6DULL, 0xF367F6B57A489171ULL, 0x612C7C7D177ACEB1ULL, 
            0x63BE74238E0578B8ULL, 0x303A38921DE88C3BULL, 0x5FB36B2805C2178EULL, 0x11512F3CB09667CDULL, 
            0x5F34DB0239F470FCULL, 0x661F3D9BA7A8D353ULL, 0xAD2B1D30010C5008ULL, 0xD49C1EFEEE019106ULL, 
            0xE988B4E3F8C355BDULL, 0x630FDFD9AA3F54FDULL, 0x913CAEA74EA3972AULL, 0x497ECE1158B1908FULL, 
            0xF38A6973FEC5543BULL, 0xACCC59F4EAE9E9D2ULL, 0x7929A131D651F975ULL, 0x6E4FC7822EA0263DULL, 
            0xC7F4EB1A3737D4D2ULL, 0xB896206082A1C3F1ULL, 0x8B03F8439704B7C0ULL, 0x958A77C07C0FB399ULL
        },
        {
            0x522C51B450B15D9CULL, 0x3B62634204DC2D1CULL, 0x42612C185F519A1CULL, 0xF0FE50898ACC0C44ULL, 
            0xFF08DA790562DF1EULL, 0x34FC02B03898E1D5ULL, 0x53A4FD87A7C1F09FULL, 0xB016F0F9F63ADEDEULL, 
            0xD392B7C8BBCB3F4EULL, 0x66A037571227589CULL, 0x03DC95BDD5BAECFBULL, 0x359CF04782FEB407ULL, 
            0x4D1DD121F8F183B5ULL, 0xA8B4659A7E5FA98EULL, 0x15DA004E88FA3E6CULL, 0x207B9B4A83F79D33ULL, 
            0xB326E10B7B0A8EC5ULL, 0xF25C1053F8E9599EULL, 0xED4698F567733BB0ULL, 0xEC0E8B260485CF93ULL, 
            0x3CAA61DB691AEC17ULL, 0xC6BE9078A67C06F3ULL, 0x96DFC8DD048C4EF6ULL, 0x57C23D0391CE9DAEULL, 
            0x80C61FF669230513ULL, 0x125FD28E5FD96F47ULL, 0x34D88A43EFF99F0FULL, 0xBCB5EFFB481877F8ULL, 
            0x2C106B7EBCFE04C9ULL, 0x24D124F462124C92ULL, 0x0EE59983D3A49F45ULL, 0xF0C6D7C5D8A6B016ULL
        },
        {
            0x244DD6AAB70B876BULL, 0x5ACC16450CA3DB54ULL, 0x3F051E72FD38786EULL, 0x7BC58439E56F4B88ULL, 
            0x740F77C915297D2AULL, 0x162D0ECEC4DC094AULL, 0xD4C233B22FE855D9ULL, 0x051C31E0C3AAD4E6ULL, 
            0x63B3A9C8BB789A64ULL, 0x5586856D145D3F39ULL, 0xA8586A1204DAE728ULL, 0xAE4C195AB536EBC1ULL, 
            0x4126FD28DBD79EBAULL, 0x6C11C6B0D9F590D8ULL, 0xCD2A4A8D2B4C82EAULL, 0x6B344DE5BA8698C4ULL, 
            0xC5B08784E6AF6143ULL, 0xA7B048268D7F6CB7ULL, 0x9B4672B4385E4D33ULL, 0x5DE25B651898C339ULL, 
            0x608F8F8E000A7CE3ULL, 0xDEE4639A971920CEULL, 0x94581BDAFB5637E8ULL, 0x881F8DDA9EFB608AULL, 
            0xAE054747D8687B75ULL, 0xB163F483347DDA55ULL, 0x6913ECA19D1664FAULL, 0xB255504621594D02ULL, 
            0x4BD0DCB18DB37848ULL, 0x7A12D361A5FF28F6ULL, 0x8823EB02380E45BBULL, 0x6851244578C58776ULL
        },
        {
            0x96491AED426A19B5ULL, 0x19A423404079639FULL, 0x5158BC9A96613D23ULL, 0xFCAA9503A59ADBD7ULL, 
            0x7D26B6E44771D8DBULL, 0xB05CF3999853F821ULL, 0x7C75D33A57ECA06DULL, 0x639D1E531E069883ULL, 
            0xD1F2BF06D89236D7ULL, 0xB0D584683F0302DCULL, 0x75D7B928F4893834ULL, 0x0A53D724F6A22146ULL, 
            0xE795854E2FEE16B4ULL, 0xBEAE017DF305CE84ULL, 0xC5672E402A6E76D9ULL, 0x800CF079FE78EDC6ULL, 
            0x53F24B318885BE14ULL, 0xE1EA71390E512B89ULL, 0x8534A791A85E6203ULL, 0x7FA413D60D7373CFULL, 
            0x94A9CE9922A85E49ULL, 0xD9894FE80833EFE0ULL, 0xC9578D511991783CULL, 0x25DFB72F03DDDD0BULL, 
            0x4FE50E0C6F315C6DULL, 0x514407D303D34F08ULL, 0xB3FC71346B7A5FB8ULL, 0xC9C9E789098272FFULL, 
            0xCAB710AAE4B416A0ULL, 0xA3843BBA490A50C5ULL, 0x78EBF3753A5CF26CULL, 0xC57D461EC271F2B5ULL
        },
        {
            0xD4E8FB98709EBAFBULL, 0x30B62873FC71A79BULL, 0xC849CB33CFE0403FULL, 0x6A0FD0B78D701C68ULL, 
            0x67AE441A7F927847ULL, 0x5C500771896AB642ULL, 0xC2D5A810A63C66C4ULL, 0xABB4D6D48C6F7648ULL, 
            0xA86F93DDE0C211ADULL, 0x36C43135AD10B8F7ULL, 0xE08F3E80B761180CULL, 0x6BFD23A99608AC4FULL, 
            0xCFE0E6533150E144ULL, 0x4AD581FBB1BB995CULL, 0xE0C70FBACC513831ULL, 0x18A2F3DF5845265AULL, 
            0xB2EB4EF988235AF5ULL, 0xB7A214C82EA5EA05ULL, 0xF5F20172D8591A78ULL, 0xE6FCAA616F4155A3ULL, 
            0x95854173F6C43AFCULL, 0x70B3132283C2F240ULL, 0x1C494D5D6F7FB0FFULL, 0x1FCDFE19BFEF415FULL, 
            0x4C03F18F8E9A1101ULL, 0xD9B75B41B8DE6638ULL, 0xDC98A5D07CE7BFCFULL, 0x626E46BFB16F0DB8ULL, 
            0x7828503AC34A7FCDULL, 0x562BB482B32E192DULL, 0xA53C4233830FBB08ULL, 0xE34F97A14A33897DULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseBConstants = {
    0x9E579F5C0AE1B648ULL,
    0x2B1114AB4671CB50ULL,
    0xA1579C1AA953743BULL,
    0x9E579F5C0AE1B648ULL,
    0x2B1114AB4671CB50ULL,
    0xA1579C1AA953743BULL,
    0xEB26BEC3EAE1C9D3ULL,
    0x9C0F21330E118F61ULL,
    0x95,
    0xF6,
    0x57,
    0xD0,
    0x4F,
    0xED,
    0x8C,
    0xDD
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseCSalts = {
    {
        {
            0x2D51FBB2C92CA66FULL, 0x235BB2C15C8639E0ULL, 0x5D78A2E88EB3A388ULL, 0x2FEC44E5E53119B6ULL, 
            0x474209A54B3E6427ULL, 0x5ACBA3E1CEC74700ULL, 0x8873609CBEE55B9CULL, 0x744A35D738FC1366ULL, 
            0xB6763DA19B7787E2ULL, 0x806EFD7828233C07ULL, 0x97EC28DB035E3F97ULL, 0x61C13C8A9B1E5E1AULL, 
            0xE6D1E95EB9B3E5F9ULL, 0x2AF945BE1DC2D8F2ULL, 0xA59CBA06375CC8F2ULL, 0xE1E881227818BBADULL, 
            0x164760028D0D47E7ULL, 0xC630F74977FC4E71ULL, 0x32C06A39B0280DA6ULL, 0x81A5206BEE0155ABULL, 
            0x3CF9B8D0DB20DE6EULL, 0x36CA0B5299801601ULL, 0x39014AB86745B1B7ULL, 0xB633F3471CC7ADA6ULL, 
            0x27B7F717F1923A98ULL, 0x589EF6607D524ADEULL, 0xFD36D73394C31D58ULL, 0x60EF67E29F369ECFULL, 
            0xDA55D441D3AAAC4AULL, 0x657EB59729D99702ULL, 0x917C66EEDC26FDBDULL, 0x71DBB9808EC7CDEEULL
        },
        {
            0xD0823E4D1C9A017BULL, 0x5F4CD166A5CAF35CULL, 0x2C70D12B7EE94AD1ULL, 0x885E5A579D81906DULL, 
            0xE6D6D60FD479BABFULL, 0xBFE28607AA350380ULL, 0xEF629FE33029B1D8ULL, 0x41555743233FD5E7ULL, 
            0x8FA1816346841C1EULL, 0xDFD03A6125068527ULL, 0xA24D1153DF2D44A1ULL, 0x2227E6D6F1A2505DULL, 
            0x0AEAF95BCEA18DC3ULL, 0x168E4FE0DA184DA7ULL, 0x7C91475DB6EBB861ULL, 0x7EDD1ED30B927E9EULL, 
            0xB81986E9E89F02BAULL, 0x2741E9F69AECF2BFULL, 0xBFFE186CD38A792BULL, 0xBADA30E69A170119ULL, 
            0x149CBABE95C7A24CULL, 0x2607BB0DAB3A3284ULL, 0xF49C428DFC9F5D9AULL, 0x0BCF4859F2087D88ULL, 
            0xD4C04EAA52649B1AULL, 0x1A3DD50BBE297D85ULL, 0xB2080D08783669D3ULL, 0xD31B7347E721FD10ULL, 
            0xB034DA0BA82FB8DCULL, 0x65CC95881F2BA3E1ULL, 0xD68593A908E48A61ULL, 0x3C8A940DF315C167ULL
        },
        {
            0xC7966DF6FD095DDBULL, 0xC8E59FBE0C3B89CAULL, 0x974DAEA88AA93A01ULL, 0xDCD6868513711F01ULL, 
            0x5F259287C486CB27ULL, 0x9ECBB89CD8E1E3DDULL, 0xC9FFAEE432E371D6ULL, 0x3893BE5C4BC3C1B4ULL, 
            0xDEB72F944D76EF6BULL, 0xA853924831450460ULL, 0x01C94E180963D9EFULL, 0xB649460BC7A3E5FFULL, 
            0xE04E380A260D94E1ULL, 0x61B3D9B75F2C2500ULL, 0xB8E93384526E1394ULL, 0x21A6BE10695B1025ULL, 
            0x7331B476BD02384EULL, 0x62D2E33EC4E32E94ULL, 0xCF7501BACA936348ULL, 0x820FCEC817815B69ULL, 
            0x73D385F6C6444C0DULL, 0xF204DB8017604A8CULL, 0x7A7AB97D49C9A065ULL, 0x9D63F486A273411BULL, 
            0x1D4BDCA644EDC24DULL, 0x9E7156660154F251ULL, 0x5001D5EE1195A445ULL, 0x786F8D0DFBE88005ULL, 
            0x3461FE22B28D9077ULL, 0x22559E01107AED47ULL, 0x3D974332DFBD2A61ULL, 0x1F4A8AD2945FE92EULL
        },
        {
            0x827157FDFAACEF9DULL, 0x6D485E72FF0B4744ULL, 0xD618ED3D4741CCCFULL, 0x41F3FCCAE0F5CCCCULL, 
            0xEB8F4F5AA711063CULL, 0xF7A5515AC5D0E9DCULL, 0x5D0A1BEA457B167BULL, 0x6F9D0D3313E33A23ULL, 
            0x7272BBEE53AC1559ULL, 0xF75773111D1ABE73ULL, 0x14FC5A2B960113A0ULL, 0xABB80CF9C72855F6ULL, 
            0x31BFC1A498F33E65ULL, 0xA79FB9F739C457FCULL, 0x32BE16050090C0E7ULL, 0x4DE8EDB6FFAC6DD1ULL, 
            0xE7748A2B915E3308ULL, 0x4C96F9DC2CB599F3ULL, 0x03F0191933FAD1FBULL, 0xCCCAB9AAEB5BA3BFULL, 
            0xBD4A0FBAF5B55AF2ULL, 0x789CC269C7B9A16AULL, 0x753BA70C32125669ULL, 0x43E367D600424EE5ULL, 
            0x1D9908D69CCBC201ULL, 0x88CBC23FCF4820A4ULL, 0xEA590DBCBE60FC12ULL, 0xDAF1E6313B2398C2ULL, 
            0xD0B9757330172FE8ULL, 0x712B2F5E45419685ULL, 0x9540E12DE690F436ULL, 0x5E12AB5F022C0232ULL
        },
        {
            0x4517505B3BE318D3ULL, 0x68BCA1D35FDBFC56ULL, 0x5F261F8C371B65F0ULL, 0xD7C7610138EAC68DULL, 
            0x54B0AA42563C1939ULL, 0x3BE88C002CEA8791ULL, 0xDA04DC04305D2037ULL, 0x0844F37A31F7F22EULL, 
            0xB47F8C15024C519DULL, 0x54BD635F2C488FF0ULL, 0x1BE3E4C4347B8895ULL, 0x45CD3466673452ACULL, 
            0xB165A00F1EF5D36BULL, 0x02B45398EFC2C177ULL, 0xEFE726D487A3D58AULL, 0xC9E2D74C824FAD0FULL, 
            0xED2084112E879A69ULL, 0xF31E4AE2F9C00828ULL, 0x4F4514D7DF0AF6B1ULL, 0xB2F1DFE5086195EDULL, 
            0x271D71351F5C4A6DULL, 0x4034DB7297730BBFULL, 0xB1ABB9809F6887C1ULL, 0x4AFC43CB10283932ULL, 
            0xEDAB5AA8C4B4B0C3ULL, 0x28D6E14BF98C6EC2ULL, 0x37EF42DDE0B11EB5ULL, 0xB09BE8B3173CE80AULL, 
            0x4EFDC922EF5AF337ULL, 0x9BA4A4C240BFA34FULL, 0x37133FAA6D3EB604ULL, 0xE8806822C1D105F2ULL
        },
        {
            0xF04A9ED52A2C3F1BULL, 0x0BA477016315B34EULL, 0xCB3E643EFF2BBBA4ULL, 0xAA94DF0C37FFC2BBULL, 
            0xB51E683A11882121ULL, 0xF64B98257469FB78ULL, 0x68F2302DF92AA0B9ULL, 0x6C7546CA97238CCFULL, 
            0xC1E0F4D2ADAB9684ULL, 0xC4A2D68FA8F3C7F5ULL, 0x189706A40AC7A58AULL, 0x0F684B11D53F59A0ULL, 
            0xB3015A79A64454C9ULL, 0xBD5A2E9B959C19DAULL, 0x537C0A282FB0DF85ULL, 0xC743FBFA7300BD12ULL, 
            0x552A2B5F75D79602ULL, 0x3094FA1B375E34FFULL, 0xDBF2BF01A2430B8EULL, 0x5DE7031BF3B4D6E7ULL, 
            0xA88715378681C363ULL, 0xF608AF02FEF0E0A0ULL, 0xB42EBB084D8669C2ULL, 0x830798E107B0F9D9ULL, 
            0xB55E6513FD9630CDULL, 0x8E066689E6EB089EULL, 0xA4999EB1B4C81368ULL, 0x0C3AA8B503D5343FULL, 
            0xCD7564FB962252D8ULL, 0x7D8A0614F3EA1955ULL, 0x36F328015B797D0FULL, 0x57B179EC190236D4ULL
        }
    },
    {
        {
            0x8DCDB518EC2DA0FEULL, 0xA2C57C39CD36D416ULL, 0x8F348CC84B8F21A0ULL, 0xCB29E8783D029674ULL, 
            0x130F00DD34296F5FULL, 0x21A02F28C86DDFDDULL, 0xDFAE2BE5E702B4A7ULL, 0xD0A0C2B3BC86BDDBULL, 
            0xFEFA24415D1C62DEULL, 0xDE11397A853359FEULL, 0x72622F52202A6F88ULL, 0xF31AA7252E4013CAULL, 
            0x275A1B12842FE1BEULL, 0xFBFEEA15073849CDULL, 0x70D3CF0EDE433025ULL, 0xE078DCD3F57280BDULL, 
            0x148F348EF1D4D32DULL, 0x580AE7B09C476CCCULL, 0x539FA8D9704F65F7ULL, 0x3D5C2D299D499113ULL, 
            0x3D98BDF777458451ULL, 0xF340F4E9B5E0D26AULL, 0xF19B2FA297A95443ULL, 0x24E81A59BEB8EFBFULL, 
            0x72AE57B0C125B2B6ULL, 0x90CF6E1F94FA3410ULL, 0x04597C19A2A906B7ULL, 0x63DB2BEC5AC204BFULL, 
            0x2C7DCE37426BA30AULL, 0x3290C59F7094622BULL, 0x7FB4E1CF0C4679D6ULL, 0x686DDFF0FC4C0DACULL
        },
        {
            0x236AD3143EB0732DULL, 0x1C154D3B858701AFULL, 0x73979D84C295E5F1ULL, 0x75C483A3AF3A74FEULL, 
            0x1879AE78A19B2D23ULL, 0x2A60A55F15364F58ULL, 0xFD740B2413DDAA7BULL, 0x176178546EFE2F6BULL, 
            0xAD2D74BF6CAA363DULL, 0xC9440D1F6A6C1970ULL, 0xA143326F93DCB1EAULL, 0x8092CB434F066ADEULL, 
            0x5CA128D2B2544124ULL, 0xEDAC494445BFC5EBULL, 0xA8D64AB686D30CA7ULL, 0x2B8F8E24B918F02DULL, 
            0xE59D4DF58B1171E0ULL, 0xCAA5D305864735A1ULL, 0xF3D638C943344AE4ULL, 0x2F991B1BB3B65B9DULL, 
            0x57077D92B591D9E4ULL, 0xB5B3DC2D50B6C178ULL, 0x931FA1A0AD746B4DULL, 0x44118C038C878186ULL, 
            0xE035FC7CAF671777ULL, 0x852A639320ABF9DAULL, 0x77DDEC6A5C11525FULL, 0x6589EAD9FAF526EBULL, 
            0x9C192A868216D915ULL, 0x5D257A836AD6B5D4ULL, 0x5380423B1E3267BEULL, 0xC08A983BA43E4ABCULL
        },
        {
            0x97FF3EFB53C4F332ULL, 0x94CA849364D78D5AULL, 0x3380D672BB7F898AULL, 0xA3D83C497F97856BULL, 
            0xBD4E314BDC79A3EDULL, 0x7153B8EB1DC7FF47ULL, 0x9918DDD98DFEDF70ULL, 0x1896CB25B665A3D7ULL, 
            0xC501455B953EACD0ULL, 0x7F6E55FFBAF460A6ULL, 0x5A451AF6B962BA53ULL, 0x650F6F3A8E13FC7DULL, 
            0x93C4DEFE05282654ULL, 0xBB741DBE7F1F2D0BULL, 0xDA9CC6DC609DE115ULL, 0x4A098AFF0C8FCBC6ULL, 
            0xB64E1D59E9BDEA21ULL, 0xCCACC9E02808E317ULL, 0x2770546760DB6A74ULL, 0x3841DC4005A7AEC7ULL, 
            0x1B56C37FF5E1EA36ULL, 0xDA69D9F69BF2C45FULL, 0xDEF64963F3120F0FULL, 0x10CC066B1B617092ULL, 
            0x58D5FAE191BB393FULL, 0x0C61007AD78D4579ULL, 0x357951F85B9CAF15ULL, 0x225BAA2BD07AFA97ULL, 
            0x601A07A98149ADADULL, 0xF09754144A7023F8ULL, 0x5F99E651B36E15B7ULL, 0x0FFC727D8295096CULL
        },
        {
            0x2FA935BEA706659EULL, 0x6330CCD1E1B96C08ULL, 0xCCDABE3F3AFCEA61ULL, 0xE54B1BDE46A3BC5DULL, 
            0x8BB50BDD52146B57ULL, 0x6F41D08CA2118060ULL, 0xA8F7CA4B2DA5BF05ULL, 0x77E7B6FBBB99C8C2ULL, 
            0xFED8A38A60ED2CF2ULL, 0x89407341DB184D59ULL, 0x8E1170AFCF123EBEULL, 0xD886268C1873DB45ULL, 
            0x49A12AAD0A54030FULL, 0xA43DB845D4DC4486ULL, 0xE1CF99E17CF071E9ULL, 0xF298E6B4892BE321ULL, 
            0x030A389F639737E7ULL, 0xBFCF9B91C3BAB6A5ULL, 0xE4949A8FE6174C4DULL, 0x3D2805F6891B5301ULL, 
            0x9FE8E138568E64D6ULL, 0x9E1BCA26A8F426A0ULL, 0x3E13C700D53AD33DULL, 0xB6DE1CA4D444CDFDULL, 
            0xF1AB664853C6002FULL, 0xD08881B8DE7E2726ULL, 0x3749971BD3D07B17ULL, 0x823AD1D0748F1704ULL, 
            0x2352CAC3B3C7342AULL, 0x0EB53C4D0CE5BB48ULL, 0xDC60EDA4BCB011DAULL, 0xB2E2148B27709E19ULL
        },
        {
            0xC8B5F779A797E526ULL, 0x3B07179452623BE8ULL, 0x20A7C0A2BA0AB459ULL, 0x47850DD4851F3878ULL, 
            0x48A0F17CD271EC98ULL, 0xE52213DFE5E82F6DULL, 0xE035967BE608C4E6ULL, 0x2BC5C3FA20F26F00ULL, 
            0x087555C29CE911EBULL, 0x1BBC1723B5D1A882ULL, 0x51A5D7217D4EBF4CULL, 0x6C9DCBC12400D275ULL, 
            0x6FBCBB37D1418197ULL, 0x5C3BAA4EC3C59C96ULL, 0xA16FFA642FBE82B1ULL, 0x571B74E6BF6AEBFCULL, 
            0x90BB938924A3F8B4ULL, 0x61B10E38C3883E9EULL, 0xEF0D6B5863E04DBEULL, 0xD7FD331EC5622E92ULL, 
            0x67902A23DEAFB8E3ULL, 0xADBABDAE91E8A4EEULL, 0x072C234352932527ULL, 0xFB20F0058CF35CA8ULL, 
            0xA61EB4006BCCBC1AULL, 0x8FEA83121AE205F8ULL, 0xA9FFEA5898234388ULL, 0x02B632681412E97BULL, 
            0xFE029673CF90947DULL, 0x4F5F1A5D46286FB1ULL, 0x88F1E1CE3546364DULL, 0x4DE30E54A3CCA326ULL
        },
        {
            0x7BD0D50AA00F863AULL, 0x5A6D308187CAC6DEULL, 0x9831CF6913D4D6DDULL, 0x856A76A5781C3A1FULL, 
            0x0BAF3ABF79BA4A5EULL, 0xACEC704332727BACULL, 0xDF0578D62ED5A792ULL, 0x710658CE129D27F2ULL, 
            0x7E58D20E63DE9458ULL, 0x2EB925C5A281E71DULL, 0xBF4BF5A78DD04ED5ULL, 0x11AF40B26C82F8CEULL, 
            0xB938EF64AF41DB56ULL, 0x1D13CA9A545AAA57ULL, 0x2DAD0FADA6A4CC50ULL, 0x24BD670E8B8F7727ULL, 
            0x7519E94857CA98C9ULL, 0xCCCE6B80C3DD87B5ULL, 0x8C2DC55DDE53EDB5ULL, 0xA69BFC0405F82614ULL, 
            0x823FD831403E2BBAULL, 0xF7104C5C130DEEFFULL, 0x377385F398293E0DULL, 0x374A113F4D68C393ULL, 
            0x9FABB3B960F64DADULL, 0x51A67F34BB2F421BULL, 0xD57F306E159B0C4BULL, 0x72DC9F371A1037C9ULL, 
            0x1A8F76F09227304CULL, 0x83839142EF826DDAULL, 0x75B087EDC1595A5DULL, 0xF7EA9B2E22BF545BULL
        }
    },
    {
        {
            0x5465AB7D5394EBD5ULL, 0xC0988E4E1D89C338ULL, 0x839406A818175AD0ULL, 0x9894A98121B69AE2ULL, 
            0x31140623D4154418ULL, 0xC32D806BA18F12C9ULL, 0xCCD688CE8D1715C3ULL, 0xF5E91A536E6789CAULL, 
            0xEB6989E24171E99CULL, 0x69EDFB89ED154B75ULL, 0xB864AF9DCE86456EULL, 0x572B8B2AFCF1148BULL, 
            0x71E47A5275188202ULL, 0x7E198DAF2D4E7AAFULL, 0x19EEF6901B0AA2E5ULL, 0xB39E3E53D0B62961ULL, 
            0xA1C84D9D28ECBC80ULL, 0x6A130EAAFA5929AFULL, 0x46CBD105A354CFE1ULL, 0xBCDCD9F1517F70DEULL, 
            0x78ADF2C7740D3F68ULL, 0x808845D1138DF084ULL, 0x330960787B2AF1C7ULL, 0x50811FE757F770CCULL, 
            0x052D727709AF47BDULL, 0x34ADD5C54BEFC2F9ULL, 0x5A9BB1A6555BCFD9ULL, 0xC5E471CB23DC8ABDULL, 
            0x7EF9FE6BE273E557ULL, 0xAA09092AEAA68AB1ULL, 0xD824F6880253CE72ULL, 0x3B79C025F4B6BA2CULL
        },
        {
            0x0AA1EF03BC78E22BULL, 0x8F18C34961021F68ULL, 0xD0F4EEB065E63A41ULL, 0x52914A31874038C5ULL, 
            0x6A1D5CB0D9A72EB7ULL, 0xFF159FEDF33C91C5ULL, 0xF40D63448D432D47ULL, 0x3696F32A97B002A0ULL, 
            0xBF6DCD581E2F193AULL, 0x5C86170B2F1098B1ULL, 0xF957D6E69FB0B2D0ULL, 0x6F6F7A835BE17B95ULL, 
            0x07B557D7846F4A5FULL, 0x20229BE8EAF76989ULL, 0x0D6BF50E7E6F2BF5ULL, 0x7DA2EEB58CAED8FBULL, 
            0x92FB54EAD46F438FULL, 0x48F07CCE30C425EFULL, 0x819DAB14ADFB478DULL, 0x39D2F78787BAFC23ULL, 
            0xD087E91AF4E26725ULL, 0x4E5BD1DDA13FCD24ULL, 0xD543B190EAC12060ULL, 0x49A94118A95760DAULL, 
            0xCC9A55FB75BF23D8ULL, 0x2115A16802D2FB66ULL, 0x09A459B842940B4EULL, 0x9D7F06559542FF0BULL, 
            0x3D84F5FBCAB152C3ULL, 0xF0605B175C5B4C4EULL, 0x0E4CF607E74D3E84ULL, 0xBF8B61215056D8D9ULL
        },
        {
            0xF025C2F736813217ULL, 0xD9857FF782BEFA2BULL, 0x9D3E73D36461E7C2ULL, 0x4AB903E881284F25ULL, 
            0x099D16A3C01B637CULL, 0xCABC2D68FCF3DF2EULL, 0x09FC0CCC5B785C14ULL, 0x0683613DA074A944ULL, 
            0xDB311A70486F4AF8ULL, 0x3FB1C21CB130604FULL, 0x937ECA53F924B6F7ULL, 0x5F3456B0E2FF73EEULL, 
            0x0FC0F477A8D8C97EULL, 0xEB07EC09A6B7A0D3ULL, 0xF7BDD1E2931BF8C0ULL, 0x43FA1EBD56919E20ULL, 
            0xEC7662F0F3F9756EULL, 0xCADAFCB4C8732098ULL, 0x26D1055DF8D7D290ULL, 0x8EF38BB38C141087ULL, 
            0xDFEE400C53C02320ULL, 0xCE695373DB7EBFCCULL, 0xCAF6C90774CB53D4ULL, 0xFE2536B4E1D12D01ULL, 
            0x7FC5E2DFB4D8BBA7ULL, 0x4259B2222C2BDE55ULL, 0x18DBB8DD7BDD1D5BULL, 0xA16B1F0A4AFFE018ULL, 
            0x9A9131029A5AF312ULL, 0xEA26F84C4157E483ULL, 0x8CA05EF54F36BFB7ULL, 0x05678C54B3A1C76CULL
        },
        {
            0xF0879804C44CD001ULL, 0x8DC35E326D264D31ULL, 0x7D94FC1B1A140FE5ULL, 0x7348C5A774EA0BF5ULL, 
            0x227E5933BD154D55ULL, 0x426073992A7F26FAULL, 0x67DCC4861A437CC4ULL, 0x3897A2CB3E762BF1ULL, 
            0x6300D7E1C46D02ACULL, 0x8E0EBA23470342DBULL, 0xE9DFF1C4A2970127ULL, 0x7008166AC56DBC2AULL, 
            0x3F6A7ECC58B20F7FULL, 0xB0186EADE9E68FD4ULL, 0x1640383457E07CAFULL, 0x28636B87F7A8F8D9ULL, 
            0xFD9395FA632FD8D9ULL, 0xE27F0A7284082A7FULL, 0x83F71BEB532CCF28ULL, 0xCA068B9D56C33925ULL, 
            0x9F77AE6210E6E6A0ULL, 0xC5A335A5675EB699ULL, 0x5172367F6454C19BULL, 0x82696065D24F3053ULL, 
            0x1D4E8A6E64095CE9ULL, 0x808F1E367161A19FULL, 0x770D1F2D97475578ULL, 0xB667A3374838E5AEULL, 
            0x313CCBE9F62F24E8ULL, 0xA05AB402AB8CD0B5ULL, 0xEF00962B35A4802CULL, 0x1E5EE61AEC6A93DCULL
        },
        {
            0x3A5C9C4B1138B50DULL, 0x21787D36B4B1B6E4ULL, 0x0CB244125F017BF1ULL, 0xA0AEB3016200344EULL, 
            0x69E381C831B072C1ULL, 0xF858B1D5A76AD07AULL, 0x972864573356CE7CULL, 0x58D3C8E2A467EED7ULL, 
            0xCD491C7C20B3A638ULL, 0x3A7D79BEA1ADABB7ULL, 0xE3FDCB91815B6088ULL, 0xAAF0DDDF522386D2ULL, 
            0x477C7DCD6C54CA59ULL, 0x01AD8FACEBA04AC5ULL, 0xEED5BCFBF921DC24ULL, 0x3FD712FEAEA109D3ULL, 
            0x53584632CE5DAC98ULL, 0x897676B2AA8CC906ULL, 0xA3753477FA57EC60ULL, 0xBF89527CA81F905DULL, 
            0x0E946977AA4BD702ULL, 0x708111B0CA297760ULL, 0x94D3444F89DDD222ULL, 0x49C9DED78CACDE91ULL, 
            0xD757C9A80261A973ULL, 0x94ADD4BBF16093B3ULL, 0x0CA34056DFB524C2ULL, 0xFD18A85805D2A85DULL, 
            0x47CF5DA3D20C83F8ULL, 0xDA1DCD048FEBB4DAULL, 0x22DB838AAD528FCFULL, 0xF5089C7F4A6E05F8ULL
        },
        {
            0x55C3B8B4FA9A52D5ULL, 0x22B18A7FFA061464ULL, 0x8214C5C85A71B42FULL, 0xA9B37695AFF11C7EULL, 
            0x095B61FD093232F4ULL, 0x1BD8D30F6605486FULL, 0xFD966418AF93850FULL, 0x2594655924EE2A21ULL, 
            0x4DB0CFD81FC1E644ULL, 0x092E1A8C59DB6F09ULL, 0x10B91C1358C40BEEULL, 0x8C936A652F591DE6ULL, 
            0x39DEED5B4AA5A55CULL, 0x76F0D8C7600F15BAULL, 0x0970A2213E783BC1ULL, 0xA6791F4A571829FDULL, 
            0x86FBA6E69B2EF552ULL, 0x909C9B6B1A69EB9AULL, 0xCD10F42D08F66BE9ULL, 0x12A7C332321361ECULL, 
            0xB6E4D64CE4254D36ULL, 0xF851A7A5F688E4D1ULL, 0x0FE64BFD719B1926ULL, 0x43FD470EAED57AE2ULL, 
            0x31DD48C0F92F87DDULL, 0x0FF9CFCE90498C4DULL, 0x212D1A528E4876D4ULL, 0x4E5FCB4DDEE41D41ULL, 
            0x2C64A14B08AD6281ULL, 0x0E09C5032F346EF0ULL, 0x7B6C3DF7F5FDBBE4ULL, 0x145711ED6CA855B4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseCConstants = {
    0x43B2850A76AFE9D5ULL,
    0x994EF8D22DEF2753ULL,
    0x4633E15D0FFE3E19ULL,
    0x43B2850A76AFE9D5ULL,
    0x994EF8D22DEF2753ULL,
    0x4633E15D0FFE3E19ULL,
    0xEC4FC3B8D04CDF7CULL,
    0x3A0B4F955D5F19B4ULL,
    0x5A,
    0x0E,
    0x3C,
    0xEE,
    0xFA,
    0x78,
    0x29,
    0x73
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseDSalts = {
    {
        {
            0x7E0CBE9565CD0D8FULL, 0x98B78408396C8727ULL, 0x18C28377C20C7E43ULL, 0x38A682D1705C70F1ULL, 
            0x53DFF370318F9921ULL, 0x589D7495AF66121DULL, 0x16EA3E46DA1C0015ULL, 0xF51CF19E784D93F8ULL, 
            0xB7930E6FDD1CAC76ULL, 0x0B5F1BBF6B5C3752ULL, 0xC8BD0880D943B232ULL, 0xBD377F80A94C6AA0ULL, 
            0xB6F5F2EB6376BFF4ULL, 0x6EE32E512C3FF613ULL, 0x8DBE2705274A51B3ULL, 0xE8509AB8970D3D9BULL, 
            0x81146865F54E1F77ULL, 0xC890697D9AEBB461ULL, 0x4E55B04A6614B13AULL, 0x7DAE2FD16ACD019EULL, 
            0x840ACC943C886960ULL, 0x5433184BEBD5CC7FULL, 0x9C702518BE6292FAULL, 0x36EA66BD4692F602ULL, 
            0x805AFE78332F5CE4ULL, 0x65C6A3D14FF7099BULL, 0xAFD7A9955D52748DULL, 0x6CFEAA52B8C04C61ULL, 
            0xEE2D1684B7650C87ULL, 0x47AFDDCBE080F889ULL, 0xC4F9FB2EE8B7D081ULL, 0x0DB5A937540B6BEEULL
        },
        {
            0xEA4B831216DE6252ULL, 0x71D7E6D05ED39899ULL, 0xA5E1FF8415AC627EULL, 0xB6454C5303D33E0BULL, 
            0xABE073EC44789184ULL, 0x14250383BD0D417DULL, 0x86375A723CC32C0EULL, 0xF7B5BF17C081AE6DULL, 
            0x35BE6970C262AAD8ULL, 0x16B5B3E6F2D5D748ULL, 0x89FA209731A1346FULL, 0xEEB64C64C8BC0F96ULL, 
            0xC28B18A5FBD55BB1ULL, 0xF86AC6D948B4E500ULL, 0x63794F541E780BCAULL, 0xF31B7CAF5E00C583ULL, 
            0xB3BF089AAE658EE8ULL, 0x3664C044A2E6F469ULL, 0xD36614180B23D059ULL, 0x30C52AAF375C88D4ULL, 
            0x595585B24549DB57ULL, 0xD9B30BD1A3D7ECB3ULL, 0x152697C28FDBE7DFULL, 0x8908916EC0EF4E20ULL, 
            0xD9E21699B8C01AF2ULL, 0x195CFD03248E6AADULL, 0xE048F82C376E310FULL, 0x54B130B0AB69CFCAULL, 
            0xDA85F325B5AE9EBAULL, 0x019D1DEF546A37BAULL, 0x6043F1368ACFE5F3ULL, 0x4670B473ED460AB1ULL
        },
        {
            0x8650E4B3837F7F46ULL, 0x2ADE16E5B15FB1C9ULL, 0x09B66B8BBA7EEE38ULL, 0xF9143DAE6C18A48BULL, 
            0xD88EBFC581A9151FULL, 0xC4DFD461A3EE2D5EULL, 0x9D283B28093AAA92ULL, 0x54CA6AC95F7F92B1ULL, 
            0xAEB2076AAB932597ULL, 0x1A60538024692250ULL, 0x260258681E0F080AULL, 0xC8BBF6ED421B764DULL, 
            0x238666387B60EA93ULL, 0xC80029BE721A4893ULL, 0x18430B74619AD454ULL, 0x999D490D90B3F747ULL, 
            0x171E0EFD23D6F4D1ULL, 0xE3A5E6AB8277CAF0ULL, 0xC36EFAF63F6C9C7BULL, 0x4FB9EFC38D21E027ULL, 
            0xE92A0C9E03AA569BULL, 0x0B81609E7D86B377ULL, 0x70E7C4DF6CB292ADULL, 0xA4DA5931365BC0B2ULL, 
            0x63CA6E1F7FD17C13ULL, 0x1490F61D5C61E393ULL, 0x12DB7A40B4F7E713ULL, 0xCEF7EFE853A634B2ULL, 
            0x7AEB74DCE9E56F07ULL, 0x27F1FE433FA871EDULL, 0xD33B88EA67F5A528ULL, 0x432B226F0481B024ULL
        },
        {
            0xEFE7B030892ABEC7ULL, 0x87CAC24601FAAA05ULL, 0x177106309A03FAD8ULL, 0xAAC9C1FE3C237CD1ULL, 
            0x07D4B1A735650901ULL, 0xBCBE74AC6201622AULL, 0x239F81A9603BD16AULL, 0xA6B1FD60E59A4C82ULL, 
            0xA166123F7B5FC71AULL, 0x366989ECBA3D7501ULL, 0x06A2737A37806E28ULL, 0x698F07FCC2FA0C55ULL, 
            0x7D01E2EC78C89865ULL, 0x90A8C94814722DE7ULL, 0xFB3A6A5CDA83E142ULL, 0x882D2B9BF69553C3ULL, 
            0x9B7093CE4B7410B8ULL, 0x75D70E1856340985ULL, 0x2062284BCE86C56AULL, 0x9CD4DDBF25C33663ULL, 
            0x85D049A2D74601F4ULL, 0x8E3C17450F7E262BULL, 0x9620F70A70A77D91ULL, 0xF22AEDD560492561ULL, 
            0x3DD0713731D5E684ULL, 0x9A6CFD9D478267BDULL, 0x079FD3A223F8E8E6ULL, 0x5208E1CB52DD6366ULL, 
            0xC82EE528F9B2D0A3ULL, 0x98C7FD7CC6C5463EULL, 0xA3B677C238551385ULL, 0x27CCCB0F934EA138ULL
        },
        {
            0x8324B8C311DEA296ULL, 0xA357D54545392F73ULL, 0xBC4C876FD6859CE1ULL, 0xA7320B5AE1EED21BULL, 
            0xC5A922C371DD1C21ULL, 0xA2DC58B774E21633ULL, 0xE432690BAEA4321BULL, 0xAF268AD30D0A32BEULL, 
            0x24E426537FFDE6EDULL, 0xFA485E2214FAFDEFULL, 0xEFFD319C0BFCAE51ULL, 0x2144922D851BD685ULL, 
            0x2F7A0DEDC02C8E44ULL, 0xC11A87CBD6F200B7ULL, 0x273F0F247388C5B5ULL, 0x65D49057C9BB3DB5ULL, 
            0xE20FD81BA1D2ECCEULL, 0x14BCEE139A3FBD0FULL, 0x193BA6FA28D6890EULL, 0x739E519D1F0B291BULL, 
            0x07D83B4529290045ULL, 0xF445D531B9F30228ULL, 0x21D6AAD0ADB82470ULL, 0xA7DE938D7268E174ULL, 
            0x383144286003F1FFULL, 0xA09BE41766657065ULL, 0x3D3B3149819D6462ULL, 0x5EB6A8C06C4C394EULL, 
            0xF849D4ED63F8C578ULL, 0x545CF214E9E1519AULL, 0x343E0F7B7B2ADFF0ULL, 0x5E78716B7C65CCB1ULL
        },
        {
            0x9196A71774604769ULL, 0xEFB8FF75E107BC4AULL, 0x150A88D270CF0E19ULL, 0xA8DD4CAF8F37625EULL, 
            0xD1D1DE81936DD498ULL, 0xD21CEC307F7B4C90ULL, 0x7E08027809318236ULL, 0xE648161FE8F795BFULL, 
            0x7ECAC7F77AF1492FULL, 0x54DA5268F29406A6ULL, 0xDCB01AC49AEF1956ULL, 0x57CAE5FD304FA0EAULL, 
            0x3028B743594D9EEDULL, 0x2223EF07F02F5BF3ULL, 0xF37100B545A44868ULL, 0x70D61E55C48E71AAULL, 
            0xF327269C92714039ULL, 0x147751CE3046F7E6ULL, 0xBCE95445EC9FDC69ULL, 0xD2B2B955DB66AC07ULL, 
            0x7EF89EBC0186C4FAULL, 0xE6B4D5ACD978008BULL, 0x67B630E732EB4E87ULL, 0xBE08B0662F9B7076ULL, 
            0x38991224F3676E69ULL, 0x12FBDBE44FE6475DULL, 0x8193FEDF57FCD81BULL, 0x7CA717DB7D114E40ULL, 
            0xDAC3642C469024F4ULL, 0x73659F7D5AF99CD1ULL, 0x874D70A30B6D5AC0ULL, 0x1CE20ACDA1B46BF1ULL
        }
    },
    {
        {
            0x3FAA885F947ABF8DULL, 0xDF211BA0745BACA7ULL, 0xECDC7E7695B826AFULL, 0xA4237A28EEC68892ULL, 
            0xF703102FB1BCEC7CULL, 0x86941369DA8A0A94ULL, 0xAFAE0D3AB5D72650ULL, 0x8513C5E107273053ULL, 
            0xF1D13B5555F102F7ULL, 0xE2AF0A06EE0219F5ULL, 0xFBFDCD0D12F81453ULL, 0x4666A846923EFFE8ULL, 
            0x2642C6F2821A258BULL, 0xF62AFE295B30BF54ULL, 0xE1551F8C4C34B763ULL, 0x9EB221FBF9CF1517ULL, 
            0x3C0B2F9BB3455656ULL, 0x16F81831323473FEULL, 0xE762D7372DF8AA46ULL, 0x586181A8492B08EDULL, 
            0x69E69274D5147E7FULL, 0xAA592B2772AF1BBFULL, 0xBAED363B30076638ULL, 0x651C124868465F73ULL, 
            0x5218DFF90558E7C7ULL, 0x1F9017D043FCBF61ULL, 0x35F41EC69460ED46ULL, 0xD70B49060FF1C79DULL, 
            0x7D18EA441C3F3C2DULL, 0xD0F2DA46D6CB247BULL, 0xDF8748ED7A60BECAULL, 0x9E7213FE1C713407ULL
        },
        {
            0x6ED8EB3916C596F8ULL, 0x0E420AACBDE7CDA1ULL, 0x137B21A28CECD839ULL, 0xB115A48BB104C499ULL, 
            0x3E16DABCD5C66164ULL, 0x5C48CB085CCC98D7ULL, 0xDB0F32DE579CA407ULL, 0xB7D6E69F8ED20501ULL, 
            0xAD68CD2C195B5841ULL, 0xB2BEAADC62FAFC60ULL, 0x4604ABFBC7CA9C59ULL, 0x9CE958C713F9B790ULL, 
            0x8C581852E42C3C81ULL, 0x3D334DDA3661B6DFULL, 0xC6D83F040E88A1CBULL, 0xA2E58B13E5F70A41ULL, 
            0x56D1E1E0C3F9F63DULL, 0x27A9939071D4325AULL, 0x4BB4CED1A0A6B4CDULL, 0x592C56AC31C5B8C3ULL, 
            0x565D521D842AEAA1ULL, 0xA6DE789E86AC06E0ULL, 0xF55133AE9035661EULL, 0x920086957E241ABBULL, 
            0x00BDBA41470BCA7DULL, 0xBC97CD2D2746E75AULL, 0xB58F85043050C45DULL, 0xEFB9BCF4AD3BCD4AULL, 
            0x26D7EA0081D51765ULL, 0x178135F12E5A0C50ULL, 0x4C9BAC9ECF569940ULL, 0xB75F5A7DAEE7F3BEULL
        },
        {
            0x99D8C52CA77CDE5EULL, 0x13440DD07B82D205ULL, 0x433C761A9DBBB828ULL, 0xEB0FA74BF6F51A38ULL, 
            0x91DE16ECDB9E02FCULL, 0xC465EB6BE98CB065ULL, 0x64E592B7A80A6198ULL, 0x3E8FA0B7FC6CBB00ULL, 
            0xC530E465A27E100EULL, 0xFD292FD64B937627ULL, 0x1D7EEA4499401DA8ULL, 0xADB7BF6EA2B93006ULL, 
            0x1E77031E194CB6FBULL, 0xEBA69B071CEE9306ULL, 0x7CA05A356787C556ULL, 0x71D6AC5834A5F936ULL, 
            0xB521935BE3576A65ULL, 0xB7B159B973A7C878ULL, 0x7C4DC8DAC250047BULL, 0x2B59F2A716AC7C65ULL, 
            0x51600497FF7C67C5ULL, 0xB4C732697B7E9F67ULL, 0x4AE5459ED2AD7AA6ULL, 0x46236AA70F437E7BULL, 
            0x3D6CAD7BB1C389A5ULL, 0x3383B43428FA4F65ULL, 0x4AAED2A6DDA41A5CULL, 0x94BBD017A2B48CF4ULL, 
            0xA9A2DF514598836DULL, 0x26003B44378B3BE6ULL, 0x117B50D837109A05ULL, 0x0C5D6E963F519E25ULL
        },
        {
            0x7FF0A8353C74E9F0ULL, 0xE232C392CAAB1E91ULL, 0x47093C15CCE14DE5ULL, 0x031D6A2A8E134CC9ULL, 
            0x98824582539A0EB1ULL, 0x0F4D65EA04095B4BULL, 0xACB5B25E94280F31ULL, 0x377E1A0A36E26CE6ULL, 
            0x77EC6EC131912097ULL, 0x07240392D356239AULL, 0xA26B89A4E7DEA289ULL, 0xFFD3E8348C848453ULL, 
            0xBA2E56A21EDCF039ULL, 0x6CB67F235EDEA95DULL, 0x949402B02D5DAC8DULL, 0x017D0A8E77112D58ULL, 
            0x0050038ABD0A44D0ULL, 0x10CC490637B589ABULL, 0x03DF262B6C72F9A8ULL, 0x65C265F779707C5BULL, 
            0x175D84C5A9AAD0A0ULL, 0x05277D866D443CFFULL, 0xCC37F19CBDB79181ULL, 0x86282FACCB25CE38ULL, 
            0x737F23E006C34569ULL, 0x263FD0C134A762F5ULL, 0xFE29AA86A91B0076ULL, 0x792EC41E099221E0ULL, 
            0x369F39F55A12B260ULL, 0xC3556F69BF321425ULL, 0x7E3D853642FFF4C8ULL, 0x3C567981719A1821ULL
        },
        {
            0xE06D8E858D4FAC74ULL, 0xB8F093107E42FEB2ULL, 0x41AD2EEB90F49306ULL, 0x863B5150FCE2BFDBULL, 
            0xFE4CD64334502820ULL, 0xA5F724EA425BBC7CULL, 0xDE5A87C92DF9858CULL, 0x4BCC03056EC523CFULL, 
            0xCCD78DCA604FD2C5ULL, 0x6A7094C49C0740CFULL, 0x90BD121770A6F4F1ULL, 0x8024400FCE53250CULL, 
            0x1D29AD32C92BCC20ULL, 0x436EA7D6B6465C04ULL, 0x5D71AF71394E9DB2ULL, 0x165721E4293652F8ULL, 
            0x6718EEAFD838E224ULL, 0xAC32EDF709175C19ULL, 0x373E47C30B137203ULL, 0xA2D5ABC5955B98D1ULL, 
            0xFCC125F93E734897ULL, 0x04870592848458ECULL, 0x7939251A36C8AE51ULL, 0xDB0985D55EE7CD59ULL, 
            0xCFEB027F316DF2D1ULL, 0x07DB17801D68B014ULL, 0x35099FDEF0AC3EB6ULL, 0xA3F70284FB7DCC2AULL, 
            0xBDF75D7F515B36B6ULL, 0xEDF2E27C127C78BEULL, 0x341BF56CEBEA4348ULL, 0x97CD8B49680CFFE8ULL
        },
        {
            0x7024C4A139FDBA59ULL, 0x28CB9F94150DFE92ULL, 0x56263DCC05EBBCCAULL, 0xB382E748A972896DULL, 
            0x4E3BBCC0C937BB81ULL, 0xB0A5BC0CD637DC89ULL, 0x5D74D96F1B7013BDULL, 0x62737A80B057E286ULL, 
            0x41BD1D2CBCEFB701ULL, 0x5E50A3E74158BDE8ULL, 0x67FF846C57D315F3ULL, 0x837242314FB05A4CULL, 
            0x145F08F858609453ULL, 0xDC693CDF3749BCEBULL, 0xA605850052C78B77ULL, 0xD96E09379722EC67ULL, 
            0x3D4FC650A255631EULL, 0x670BB104078CA5F0ULL, 0xBA683196BFFC4AF9ULL, 0x0828C771EFC2843AULL, 
            0xBEF5798AEDE29C3AULL, 0x56948EF28E15287CULL, 0x021D874D0E39D0A4ULL, 0x4CF45C62118F5EE3ULL, 
            0x6F7AB146D0E9D398ULL, 0x2EDDA12D7CC1CC13ULL, 0x3C3A10573042D943ULL, 0x5AC92F4D21C74AFCULL, 
            0x100BAD099DC747B0ULL, 0xB187D772DFBA1510ULL, 0x78F2D219B8F4E60EULL, 0xB6E090024531E2D9ULL
        }
    },
    {
        {
            0xAD1206C7B907351CULL, 0x2C4D5274E01EE931ULL, 0xFCF63675EA85DD84ULL, 0x71EF09C1CDDA41C8ULL, 
            0x10B43043C52BC069ULL, 0x77C4D085DB6E1FBFULL, 0xC6E7D1F1523AB4CFULL, 0xFF3728C31060CFE6ULL, 
            0xCE8FF2713E4A097BULL, 0x311F1C0B7828C3EBULL, 0x01414B4EC7B1E283ULL, 0x24569C3206E38E74ULL, 
            0x235EFDC3A6451A80ULL, 0xF24B7A2F85950226ULL, 0xF3AA8C159DB3F91BULL, 0x714BBD82439E452CULL, 
            0xD97E3B2CF2F4D7E2ULL, 0x379C376D72C0E197ULL, 0x750D9F24A7570D24ULL, 0x6F5C930A3DDDA900ULL, 
            0x79920F3419B7967DULL, 0x380B960A0370B1DCULL, 0x9045B2F85BE0E3C9ULL, 0x57C52344493C2D1DULL, 
            0x405789399FD73D0BULL, 0xEFE5D948EB09A409ULL, 0xCECA28C8F9C586FEULL, 0x3978FFBD28CEB29CULL, 
            0x4EE5E8F1FF21BC86ULL, 0xFA0BB21F24D37134ULL, 0x2A29AF2D4ED93DFCULL, 0xB4959A638EBA5B6DULL
        },
        {
            0xA13873D648F7188AULL, 0x620B4D39F355F8B9ULL, 0xEA256EA06C358BE3ULL, 0x625D496AD070A329ULL, 
            0x186CD2E2122BC831ULL, 0x23CA5567AAE514A3ULL, 0xBBB775843B7FC53AULL, 0x03501168F47285BAULL, 
            0x5F78D7D5240A87B8ULL, 0x16C3CC39E6C39430ULL, 0x10480CF10B3F4777ULL, 0xBDD8CEB280549D4DULL, 
            0xE67787E42D7A8023ULL, 0x0777A0F3DD4A2758ULL, 0x828A1C986A920BD6ULL, 0x00A8DB515CCF5CF0ULL, 
            0x8C2033C7A8C54EE5ULL, 0x6449FA518961167EULL, 0xBF52A5869EFEBB9EULL, 0x7061F32BA83CA331ULL, 
            0x48A90593015DFF5AULL, 0x55FE600F81E0E3F6ULL, 0x40A993A5650D9A74ULL, 0x6F7069E7334A6481ULL, 
            0xE7E73FFC0724878CULL, 0x40640779946D6A33ULL, 0xD6978CBE21F2E5ABULL, 0x2BD458059095636CULL, 
            0x912A4F9D492E1E37ULL, 0xCB6489D33DAB3370ULL, 0xD663BE6BF095CA18ULL, 0x23F88DE171D46486ULL
        },
        {
            0x506C316B1476FC6EULL, 0xA597CA5E1147B4A0ULL, 0x6EFA4BBF5051F45BULL, 0xE02B96221ECD15D6ULL, 
            0x3E6E029E1691B44FULL, 0xEF0C7D8399F27579ULL, 0x51259E24B00763D7ULL, 0x87F3926B1582CA3FULL, 
            0xB4589FB2FBCB8C8AULL, 0x77C8E8CB56B4EFDAULL, 0x025E4AA669A68A15ULL, 0xE49E24B6674F41E8ULL, 
            0x1A3BC168373AB5CAULL, 0x81644FA8F5333668ULL, 0x48F0318CB53DAB74ULL, 0xC469D7BA4D187D06ULL, 
            0x45867C21066E8B06ULL, 0xB496AFE9572B89B6ULL, 0x793962A66C457AA2ULL, 0x9FE666FEE7C73237ULL, 
            0xBFCAE52433480DB5ULL, 0x04A6907190984E6EULL, 0x4982619F5412D374ULL, 0x46569A06EA1A203EULL, 
            0xC3A5571BF5A7C07AULL, 0x3923EA2D40D8DAE2ULL, 0x38DF8FCA1C0615BAULL, 0x48DA494D25E6C3A3ULL, 
            0xFE842128BDF94693ULL, 0x5D7AE94A5792DEBFULL, 0xE517B424CA9C188FULL, 0x64531F8240EE31F0ULL
        },
        {
            0xE8EC1F52F6349DB9ULL, 0xEBC5636D2452F355ULL, 0x9F490C929AC92430ULL, 0xD94DAE7119AB8711ULL, 
            0xCE86BC37E9527A78ULL, 0x8C6A2D256830531BULL, 0x70956FD6DFE02034ULL, 0xC981F56979BA2740ULL, 
            0x347810390D54B888ULL, 0x554A5C9E6CC922BCULL, 0x622D261AA93A876EULL, 0x6D45EA9075149579ULL, 
            0x627BDF50CF81139BULL, 0x2D3F76B1775F7A35ULL, 0xDDD7FEB8C0E1F817ULL, 0x469F55B60AB08215ULL, 
            0xB8A99AABB886B35BULL, 0x2357C4218309074BULL, 0x407078D5F382C9B9ULL, 0x07C7470D3B3D8607ULL, 
            0x05D12107C56FBCF8ULL, 0xD36E289CD984B20CULL, 0xDF0F87FAD7F86A87ULL, 0xFFA6C7EDFE73092EULL, 
            0xCA4EBE92481FD291ULL, 0x732FB3854229F454ULL, 0x6A75E7AEFA15272CULL, 0x9328F81BEB1CDBA7ULL, 
            0x314B5745DEF3AE98ULL, 0x47FBA75ECFE27F7FULL, 0x3C12A36FA8186A0BULL, 0x7FBBA093CC33B884ULL
        },
        {
            0x7095D2161CE77425ULL, 0xE621CBB4D4921155ULL, 0xAEF4D99B9CB0E44DULL, 0x4DAA4CE58AC6237DULL, 
            0x206F336A1915DDC6ULL, 0x9C0755992095858BULL, 0x19B3DE9CF6A1C527ULL, 0x8A9F64B90C2CDF17ULL, 
            0x6D9B12949D4A1426ULL, 0xAFBCF7F961C523B4ULL, 0xAF7A5FB8794E2B57ULL, 0x99A1F73BE76F49D4ULL, 
            0xF87C022D23F94624ULL, 0xF56685250FA55BC0ULL, 0xAEEBC914BFAE096EULL, 0x70F6A5DBA9B604CAULL, 
            0xE31F899C1FF6931CULL, 0x3B377EC11ACAC3B3ULL, 0x214A256A505D14C7ULL, 0x2C008A1F8B739D37ULL, 
            0x61146A4BEAAAD3DAULL, 0xDAC85A761906AAD3ULL, 0x300A26A41C3E562FULL, 0x6BDF62B267EE5A35ULL, 
            0x874275C30E7A5481ULL, 0x06D939472A1817B2ULL, 0xD8168A2086605064ULL, 0xBDC3203DDE3BE7AEULL, 
            0x064103A9A53A8250ULL, 0x643168E148479758ULL, 0x111E34082088F24CULL, 0x720A9C829EFA2053ULL
        },
        {
            0x43D9CF7AC040F2B4ULL, 0xA18181F606B47673ULL, 0xF428DC6C249FBF5CULL, 0x4B4709E5748A74C9ULL, 
            0x0B753A960265382DULL, 0x56A61B8D2FEA2615ULL, 0x5AA2F495E997A493ULL, 0x50C2745394B8FF50ULL, 
            0x2294871DDFADF9B9ULL, 0x9BF3EC2C19A720CBULL, 0x8B105BE5758547FAULL, 0x539F04923852AC52ULL, 
            0x11074F626663CBEFULL, 0x0BB89A7B5D79ABEEULL, 0x6095D56DAD466815ULL, 0x51F9FFB1732CB599ULL, 
            0xD483DF06492E9E59ULL, 0x0BB768BFBBCEB1DEULL, 0x5C087687B93F41EFULL, 0x77DA21DD8F89EB8CULL, 
            0xEA5FD3F5D085B4DFULL, 0x9894BE2EAEA9127DULL, 0xB8A616DF372A408AULL, 0x8B7ADF27B0ACE635ULL, 
            0x5739BCACD5E9B58DULL, 0xB008D3B49BA64ED4ULL, 0x4732872D6DFF77C3ULL, 0x5F6AF6D6D5057ADBULL, 
            0xA091FF9DBE64F037ULL, 0xB625CA7D06894A7CULL, 0x83ACDDDBD4FEE817ULL, 0xE5BB2ED9ADFDB2E4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseDConstants = {
    0x6666A4F7CD7D8CA7ULL,
    0x0EB13CDE38A56893ULL,
    0xC61A98901FC9A122ULL,
    0x6666A4F7CD7D8CA7ULL,
    0x0EB13CDE38A56893ULL,
    0xC61A98901FC9A122ULL,
    0x5906FC10B8B7A69FULL,
    0x751BCD5CFA7649E3ULL,
    0xC1,
    0x68,
    0x8D,
    0x44,
    0x77,
    0x54,
    0x47,
    0xC9
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseESalts = {
    {
        {
            0xB441C3252FE6FA8FULL, 0x704E913A86491EF0ULL, 0xA64009A69CD121F8ULL, 0xEABA44D40E0E3433ULL, 
            0x3052F9972309CCCCULL, 0x39DDE7C31E48BD15ULL, 0xEA90C97A8BFFEDE0ULL, 0x0637F16990C4A17DULL, 
            0xF01D8C132318D482ULL, 0x42DA70F5FD77BC26ULL, 0xEC31986924A4BC0DULL, 0x952A52C5339C008FULL, 
            0xBF4832C4EE439E68ULL, 0x5211C1ADE65BE841ULL, 0x1785F22BC717A637ULL, 0xCE13746778F97F65ULL, 
            0x394EAB38B1A8FD1DULL, 0xC67AF5371CE4F752ULL, 0xE7A71BC814DB7F84ULL, 0xBA1BE7420A0DA23EULL, 
            0xD5FB2F3F51C02713ULL, 0xD054C55E4900B3B1ULL, 0x545DA794237264E1ULL, 0x555C380B66231549ULL, 
            0x626E2852D8DF9B23ULL, 0x2004C65429273F4DULL, 0x15FA933355D1F45AULL, 0xCFE2B2BBE6227FC5ULL, 
            0xEB2C71F456AD099FULL, 0x468568AB8A8BC1DEULL, 0x851B0FA847DBE092ULL, 0x87165BAC186C418FULL
        },
        {
            0x09AE7F8C5F7F03F1ULL, 0x55149352C32C3E87ULL, 0x23E4C29B2F8DEB97ULL, 0xC391785B4DCE6100ULL, 
            0xECFAA98576EE56C4ULL, 0xBEA196B63B3CCCCDULL, 0xCEB0C2FC76920181ULL, 0xE676A12FCE22A25BULL, 
            0x293981BB54F7666AULL, 0xE8FD7333FCE938A0ULL, 0x1881BA096F0E4AC6ULL, 0x6ECB79EBF58DA03BULL, 
            0x1CC06FBC25FCA5B1ULL, 0xB1A966C872B274ABULL, 0x76D6DB596416E477ULL, 0xBF3FBA4CC118C183ULL, 
            0xFE5196140EA28ED6ULL, 0xADA7C135AC0CC6B3ULL, 0x4776925374D6336AULL, 0x2F29D62BB6E678C5ULL, 
            0x956E8BFA59D19702ULL, 0x5F4D7C4BAE1212AAULL, 0x424D69E00281D431ULL, 0xE4E3DC1A23B2CFBEULL, 
            0x74B18FB4B69E3317ULL, 0x63098A9E9A547EFEULL, 0x75DD4F6CB764E9E7ULL, 0xC2E3E92C2A07895CULL, 
            0x7684708F759E031CULL, 0xB5C6F8826F8796B4ULL, 0x9ABCFC325237186AULL, 0x4E8154CDB58BFED9ULL
        },
        {
            0xD3B6AD4918A2F596ULL, 0x10D25742F1EE0689ULL, 0x4BB132E359B39BB0ULL, 0x53388B751B8406B1ULL, 
            0x106B5728B1C4CB52ULL, 0xBD84EAEE2C8AE044ULL, 0x71224E3EFF9D2A73ULL, 0xE5570EAB0FC8E98DULL, 
            0x2AA9C2B87B61317AULL, 0x5861F1669DEF6C9CULL, 0x51946825D1120B94ULL, 0x79D5A8721895E80FULL, 
            0x86B6A141C304D883ULL, 0x7406984E087F8A68ULL, 0x3D0E4CCEF3F2014EULL, 0x3E509554F7D81DD2ULL, 
            0xDBA639D8D60B59D5ULL, 0x1317CCC9587E8442ULL, 0x15A9F46ECCE1B7B2ULL, 0x4ED6288C3CC6181DULL, 
            0x866814137BEBB02BULL, 0x36CC254EEF41C89DULL, 0x0EA19F8C24B5D359ULL, 0xDEA48071782673EDULL, 
            0x05C1BBCCE2F827E3ULL, 0x9CFE2EAC3BAC7FA8ULL, 0x689BA6D1EC2A6E4CULL, 0x1333D88E6C64054EULL, 
            0xE2924753305BF270ULL, 0x59843CCB9CBBF8A9ULL, 0x70B6C8AD2808F117ULL, 0xAE2CA6FB09B52998ULL
        },
        {
            0x1994C328E2AEE4A6ULL, 0x149F5312CE6BC254ULL, 0xB70D31A8068C3EBBULL, 0xA42C279095893827ULL, 
            0xDD7F0428CA0B3ECAULL, 0x1419D57159D8089EULL, 0x8C80B7DB8E1AAE71ULL, 0x38A21D22838B51F7ULL, 
            0xD8CD7503F598C207ULL, 0xD06227A83168F0D2ULL, 0xD65DD6CC94F21096ULL, 0x4F87F0E50D7F8A1CULL, 
            0xB1321A1AD0B4B91EULL, 0x194FF8F444060DB2ULL, 0xC2A2F341B3A8B14EULL, 0xEFA630CA21FDE71CULL, 
            0x3AF638EA6461BA77ULL, 0xD6F122F87A45E7A2ULL, 0xE68F41A9227C5BC1ULL, 0x362A1926067FDBBEULL, 
            0x9A535769CE5413D9ULL, 0x6E3BB56F85E9B575ULL, 0xB5E93A85E863D3E2ULL, 0x28F1598CB81017A9ULL, 
            0x826349423837BD74ULL, 0xAC3C9D4ADDB32422ULL, 0x19BF3712B568E434ULL, 0x882DBAF84AE6B0DDULL, 
            0x3B379EAAD88FBDC4ULL, 0x14B8246773AA46E7ULL, 0x8C25D917A28841ABULL, 0xD2D11E456EE9773FULL
        },
        {
            0x92DAB5CE2DB4DE87ULL, 0xA58E41AB3529F9D1ULL, 0x7BEA292A7458903AULL, 0x5A4FB70BA0020ECCULL, 
            0x532B9DB70DFC6067ULL, 0x4124EF1968A5F273ULL, 0x2DCB2CB1AE118124ULL, 0x451A6921A0C986E7ULL, 
            0xAA2902DA707AB976ULL, 0x31B5F0C17D04BB9DULL, 0x3A64DED9C5DF57CEULL, 0x6319087F363B8F9DULL, 
            0xFE009371CC56E6B1ULL, 0x3B37ECAA91537443ULL, 0xEA461F9A2995F08AULL, 0x413A93E2B5175F82ULL, 
            0xE534AA9971698D1BULL, 0xC7B660AB5F04F428ULL, 0x64B1ECDFC33B9BEAULL, 0x5CE258742FD69FE8ULL, 
            0x7E588D8284B67C06ULL, 0x3109DF719F4FEA5BULL, 0x9339F8DFE0820CA0ULL, 0xD0687ADB68EE139DULL, 
            0x96B9544B5789633AULL, 0x7A8555DC2D6C1F52ULL, 0x2DC47838BDBA1504ULL, 0x0B1447A75EBF6956ULL, 
            0x00ECE689B678BDF7ULL, 0x564F20E1C760E0F9ULL, 0xA2E5806D66E18B1CULL, 0xABC45A98160E4AA3ULL
        },
        {
            0x5F9FC21B6A522002ULL, 0xBA420E1AF9815CE5ULL, 0xC4FBF7F60498F6C9ULL, 0xC43F07C21954F735ULL, 
            0xCE93C3A1803F1116ULL, 0xCC0D7973E68B64ECULL, 0xC71574252345D937ULL, 0x0AF67FBF0839E146ULL, 
            0x5006CFB3A0CC8133ULL, 0x8791819F7465DFA5ULL, 0xA31BC5FBC53DA47DULL, 0xD992046FCD05AB9AULL, 
            0xBB80E5B464576522ULL, 0x27324542BAF08FE6ULL, 0x0BB8CC7B156561B2ULL, 0x1E0963DAF687CEEFULL, 
            0xFE0B27A9F9BE3BA1ULL, 0x74910A30048583EDULL, 0x46DC15840E254A58ULL, 0x7DD05A0AAF28549AULL, 
            0x0244DB40E46DC632ULL, 0x026DB46DD13A1A8EULL, 0xE8488D887FCF0D15ULL, 0x579B2226F0BC2D9AULL, 
            0xF003C89B65192F47ULL, 0xE786BF481CBB55BDULL, 0xF1988C2EF96E37F1ULL, 0xC5E89F96E5FA6B1BULL, 
            0x484E35AEE4A6E450ULL, 0xBBC1D77E58160776ULL, 0xCEFA938BFF5A5A14ULL, 0xA174F3F722F805D2ULL
        }
    },
    {
        {
            0x25ED80ADFC4BFCEDULL, 0x6E37BFFEF0F505ADULL, 0x40B480A48D28B0AFULL, 0x4E2541F6A279F429ULL, 
            0x732F1AA844A19FDCULL, 0x8B13859F67877B64ULL, 0x08F28F9E093F5131ULL, 0x6F457E1E66A614B9ULL, 
            0x8A5C305F8F30B992ULL, 0x5E4AB58135B7CAF2ULL, 0x2F353FA5E23755EBULL, 0x2EB169F05DFF43D0ULL, 
            0x515795E5969128D6ULL, 0x52CCCA574274B057ULL, 0x706F67E20F117CE5ULL, 0x0E8409DC7F911048ULL, 
            0xE4140883C9B7B855ULL, 0xDC12FFFC45041BEEULL, 0x008168AE7215153DULL, 0xD66D0A3768E87D9BULL, 
            0x6DDB043CA8AC651BULL, 0xE28682A7F1F9E2A3ULL, 0xE6D583664C77EF08ULL, 0xCC046CE28133ECE8ULL, 
            0x3BAB052D4F9E280EULL, 0x721E2AE906D42366ULL, 0x99E7796E9F5D97ABULL, 0x70BD442490384B9BULL, 
            0x8708D99F12799D95ULL, 0x89AA59F0F200EE50ULL, 0x4259DDD750D41219ULL, 0x2F5323F758C071F8ULL
        },
        {
            0x897B0A7A39D6FD43ULL, 0x8F278B1811B53371ULL, 0x1A3525F368498FFDULL, 0x0E5E43AD2EE22EA8ULL, 
            0x792460A2592BC037ULL, 0x26866DE48B09F963ULL, 0xF1A140516F8E693FULL, 0x6C8F0F0F5010D504ULL, 
            0x239B6646D69EB810ULL, 0xB48F607F0EE26661ULL, 0x286222F7408C0F2CULL, 0xBDE17A76199A7478ULL, 
            0xAACA8506BCED7732ULL, 0xEC68FDF36C694FDEULL, 0x811A064D35774B86ULL, 0x720FD33D486A08E8ULL, 
            0xBEA93080FE7459F4ULL, 0x840FB54AC0E386D2ULL, 0xC2D984A56FC66D63ULL, 0x80F544244E7586BAULL, 
            0xC09F61BB35C3A68AULL, 0x8AB450B61612E00DULL, 0xC7B7C694A7FFAE84ULL, 0x606F4EC8C7DB9FE3ULL, 
            0xA1EEE80DBD3F14A0ULL, 0x51E479A3E30766F9ULL, 0x5063160635ABA90AULL, 0xFD77B3DA65F0A00BULL, 
            0x5CA3A2E856753A38ULL, 0x843B9DDD69865202ULL, 0xC36D28E38A497A82ULL, 0xE60967B99927B741ULL
        },
        {
            0x800B6C208CBF39EBULL, 0xBAB16826EA880B59ULL, 0xE1D0995EF342AF96ULL, 0x7CD6604C0B041A4FULL, 
            0x081161DBDE0A11D2ULL, 0xD57284E34875B04AULL, 0x8759D8A0709BFCA8ULL, 0xCBD80D56CAD9929CULL, 
            0x8885C1D501ACE14EULL, 0xB70586B3E9A5ABA1ULL, 0xE237EBD383DB1FA2ULL, 0xC77AB7D361AC5DC9ULL, 
            0x82EFCFA5AE029D1AULL, 0xCB36EA8508DDEBE8ULL, 0x97FA028178B7627DULL, 0xA835F7F5B3C5509BULL, 
            0xD6CE2BAD93D69F52ULL, 0x90A4D9B761D9EA29ULL, 0xCF66B28EDAFF7F52ULL, 0xC0682EB8A4439EB3ULL, 
            0x646F73E8A1F98A4BULL, 0xF2C4C5A3D9C5F193ULL, 0xE888A0A6B5593A9CULL, 0x3C580291A8CE03DFULL, 
            0x8CCC9A22B3B05CCAULL, 0x76D4CA587F2769BCULL, 0x59D7AE9BE616397DULL, 0xDF97ECEED0852536ULL, 
            0xC2AE9DCD4C7D559DULL, 0xB23ED1535BE37F1BULL, 0x2564820EC7D81F8BULL, 0xE37042B73048D5B4ULL
        },
        {
            0x19664685807BD606ULL, 0x97BB5B46011A61CCULL, 0xBDE31F62C4AC5A03ULL, 0xE3853EFB93B2FF1BULL, 
            0x11243A04BE64D374ULL, 0x4E44672478DF17AAULL, 0x745AE40455D758FBULL, 0xF1BE3EB2867746BBULL, 
            0xC63DE4946089F551ULL, 0x91F079A5406F6F12ULL, 0xA4BD8CBFF2B37283ULL, 0x90DCDC082A77F891ULL, 
            0xD662E1EBB95635B8ULL, 0x2AFC96DE359C1E0DULL, 0x825C6AE75667EE51ULL, 0xF6DFF74F10476573ULL, 
            0x75B357C2CCE67A8DULL, 0x00CFCE10E295DCE9ULL, 0xB3FD7F2FFB035789ULL, 0x49BDCF5D1D7D50B4ULL, 
            0xE8859307EA773BC2ULL, 0x36DD82486AC6EC06ULL, 0x24CAFFD7695AB34EULL, 0x669AB6123AD71E12ULL, 
            0xEFD989D45B59895CULL, 0x029AB229165152EFULL, 0xCFD50B2B69D88762ULL, 0xEB46142505DF8559ULL, 
            0x7D13ECA919E30243ULL, 0x03861F727789743BULL, 0x0379F2B7CF85DE7AULL, 0x021126446D927A15ULL
        },
        {
            0x0E1BDB8CBE2AA8E9ULL, 0x4336325459B26597ULL, 0x17E6AAEBB6EFC7EBULL, 0x482518D460709794ULL, 
            0xBBFC2A8F122DEFFFULL, 0xF4D9E2A6918F0E18ULL, 0xA41DAF262E84B764ULL, 0x00E9C15691A99F69ULL, 
            0x43551901939E6F4AULL, 0x5A8376A8819CF824ULL, 0xE9114EF886082156ULL, 0x8AF4929D6571E483ULL, 
            0xBD7E35F97F45E494ULL, 0x144B1B6686A80BB7ULL, 0x094D51AC8C143909ULL, 0x60E340C27A309C96ULL, 
            0xA9F2439AD0CBAA92ULL, 0x0A846F4369BC0E7CULL, 0x998E950FCBF790F3ULL, 0x4AF5495ED7E015ACULL, 
            0xC1A4717F1B255522ULL, 0xD9DC0F00B7C8E9E0ULL, 0x5EB93FA88EF09C23ULL, 0x9C3E07CDFD36B420ULL, 
            0xF436E97563BABD15ULL, 0x688C69C53B091F77ULL, 0xB9E84B572B796BBCULL, 0x2764F95D8E034786ULL, 
            0xF963B77C06EF123FULL, 0xA49A215D8EC09D0AULL, 0xE3F450A52F3222F8ULL, 0xE0CA631C7D95C73DULL
        },
        {
            0x14CB82839A0FA4E8ULL, 0x3A9B60F57433EB12ULL, 0x41EF157B08C6BF29ULL, 0xB31E1C74C4CC31E1ULL, 
            0xEC3C61E2BFE224ABULL, 0x9126248454CB5ECBULL, 0x70E72F1DCF9F1352ULL, 0x5C80003BCDA3F705ULL, 
            0xC1CF8522E4C643DCULL, 0x928D3EBED5B24B48ULL, 0xBA2CEB688BB7232CULL, 0x033CF08CDF0B794AULL, 
            0x2A9DE7B677D70478ULL, 0xCA2DEF304FB3815FULL, 0x81148B3FD65E6C34ULL, 0x3E5A6174D409A444ULL, 
            0xCAA3E159F0C110F4ULL, 0x92321EEE1DC21554ULL, 0xDD2B148C64BC9A74ULL, 0x8B4D7AF16130083AULL, 
            0x2961E190C56C33FCULL, 0x84797762318BA0BAULL, 0x31D38EED2800ECCDULL, 0x172EE7ADB6B30098ULL, 
            0x0B0CE7245ECFF590ULL, 0xE22A22B3CC225A48ULL, 0x36975C2163F3C4CFULL, 0x9699BFAC2214B2B9ULL, 
            0xC669F2BD73A6C1AEULL, 0xD016B18B425C7AAEULL, 0x81CCF6E672F36638ULL, 0x793A37CE361948BEULL
        }
    },
    {
        {
            0xFEF83FA6C2A749B0ULL, 0x1BB7E43A745D7240ULL, 0x4D43F857B75C25D2ULL, 0x6B42B8B162D5DAC0ULL, 
            0x8E913FA1E4872F17ULL, 0xF8AB9063331B52DDULL, 0xF30B14D6C3A1243AULL, 0x63EBE91BAD07545AULL, 
            0x5DA624CCDE88187CULL, 0xA398E5E1A3881822ULL, 0x8F240EF55434DBDDULL, 0x53D35A307E671452ULL, 
            0x306D877C03FE97E0ULL, 0x5A85B9FB9D3C8CC0ULL, 0x2955B124324D7BB8ULL, 0xEA310D713A5E92EDULL, 
            0x2804CB90B7BD890BULL, 0xB9AC30BDF25979B3ULL, 0x66587A472D7EF614ULL, 0x9FDD2980689C29E3ULL, 
            0x88E62F8BFF3CCF1EULL, 0xD4F16F3696CE1DB5ULL, 0x5C11C7ABC05A2F98ULL, 0xFEF1F4DC39D84505ULL, 
            0x5B4F621BDA974394ULL, 0xC5C5C76E102B2396ULL, 0x1739A442F4CDC4FDULL, 0x28E588297E483C9AULL, 
            0x03847A8B91F65DCDULL, 0xEDA077D63DF1D388ULL, 0x2B50B62363C3B0D8ULL, 0x86FE685DBCBD68BDULL
        },
        {
            0x0D093B9C1E43B8ACULL, 0x00F8D90940DB30E1ULL, 0x24CA2CC98503F7B5ULL, 0x69A5550384A5D40AULL, 
            0x10EF001AA7A1969EULL, 0xD516F05C2FC6E0A0ULL, 0x543FF49F501413CCULL, 0xF9AEF743BDB3C959ULL, 
            0xAF8DD38E47EAB4D8ULL, 0xD59FD98F660AC81EULL, 0xB8E296C6B9668DBBULL, 0x24D8AAD5988B8224ULL, 
            0x0EB496BB49ECFEE5ULL, 0x045EDA3CAFFB4525ULL, 0x85EB2972F6B8CB8FULL, 0xC6F185D5BF1F3578ULL, 
            0x0A736326DC8E1801ULL, 0xCCE90ED480606876ULL, 0x5134DED0E5746458ULL, 0xD15C2CF016546F85ULL, 
            0xFA722A576DAECBC0ULL, 0x2BA62744A627A150ULL, 0xD55D8DA9F7E4B872ULL, 0x11B78159EE99CCEEULL, 
            0x0733DD3E4159F956ULL, 0x445947312F86E379ULL, 0x08387DC4089F4BCEULL, 0x390BAE481C6BF017ULL, 
            0xB36FA313F49943AAULL, 0x343B650FF733C023ULL, 0x853C3510C4B3A0D1ULL, 0x13C9FA692118EC4DULL
        },
        {
            0xA22497769756B7D9ULL, 0x5DB6C2ECBB57E666ULL, 0xD68DF22D8B5B5DB6ULL, 0xCDC85D81141B8F5CULL, 
            0x316212A7DCD04A62ULL, 0xE618A4256BFB5FC7ULL, 0x9A4C697435917F78ULL, 0x1DEF056C522F49F2ULL, 
            0x9CFF593F22A7FAE7ULL, 0x9079A7B282E44CF7ULL, 0x14AE0E51FFDCD5F9ULL, 0x6FA4DBABD53416BDULL, 
            0xFAB6CB8D25A6FBF1ULL, 0xCD4AD5D4438082C3ULL, 0x29E0EAC3958F5B99ULL, 0x042C66D24D1C5EBEULL, 
            0x5131AF4BE6CEF641ULL, 0xEEFBA199F6596FF6ULL, 0x0642620C413E156CULL, 0x13147FCE87AFD523ULL, 
            0xBBEFB105564C8E3DULL, 0x80409F1E991A0D58ULL, 0x647813B58A782560ULL, 0x300A62869C4BBCF6ULL, 
            0x5E95C252F0335EBEULL, 0x947975CFDD27CFB9ULL, 0x01A97C9AC3DC9A3BULL, 0x356C88C756362046ULL, 
            0x02ACF0E1FDF53BD5ULL, 0x18EF2EE88EBBF6E6ULL, 0xE2E515B7F475F578ULL, 0x43AC1EC65189BF80ULL
        },
        {
            0x8A9A99404E81CEB0ULL, 0xF86EE0CF76A044AAULL, 0xEF07CC3D5E4A6B6DULL, 0xFF958DD2C6913532ULL, 
            0x96614ECAAD1CD5BAULL, 0x01DE41A597F84CBDULL, 0xC0B56C61CD5B6165ULL, 0x82BEC355B0FBCA82ULL, 
            0xC79B653DD7A4FE0EULL, 0x0121140F1A5B2D50ULL, 0xB476A1CA6EA6384FULL, 0x1F657C70D74D9A90ULL, 
            0x1D2B088B6CACC2D1ULL, 0xC99636B59010B657ULL, 0x5B94F84C8B4BF21BULL, 0xDC6BF3580A16D5EAULL, 
            0xB08DCF0F166A826CULL, 0x1A26B2DFBF3DE1C9ULL, 0xA74762C7F91C8378ULL, 0xCDCEBD8E7896539BULL, 
            0xA4F25658C420E1ACULL, 0xF598CDB1F32DA9C3ULL, 0xCCA20338C1B72407ULL, 0xF0635D14BD22AD39ULL, 
            0x75F5F79E09976AC9ULL, 0x4B8E441A31B1F1EBULL, 0xFED24C8C142B6F76ULL, 0xA4AFB73F395506C9ULL, 
            0x6CB8FDF5CBA36CFFULL, 0x3053201B1ED23062ULL, 0xCF07F3A508DEBF12ULL, 0x060C42184027AE7AULL
        },
        {
            0x2BFE69DF62FB2DB5ULL, 0x198477847AC37A85ULL, 0x8AFFE74338893F6BULL, 0x9ABD55DB60853A1AULL, 
            0x294225C3313D3BA6ULL, 0x4AE0C46CEB7FC62EULL, 0x4B8D1637D7FCED1CULL, 0x57B34BF113CACADBULL, 
            0x4C2C04512518F21FULL, 0x7A1F87CB3F2E6209ULL, 0xF12669ED4A5C36DFULL, 0x4441E7CC399D5573ULL, 
            0xDFE1B4089D105184ULL, 0xD8AB91F9628F36D5ULL, 0xBE11C9819A2E6637ULL, 0xE59FA10B81956362ULL, 
            0x8558B9E07D5907CDULL, 0x96CDA97830624CC7ULL, 0x3948D94370908A9DULL, 0x11D839C5AE7014F0ULL, 
            0x850FB7CCAC104B5EULL, 0xCF3F56F3534DBCE7ULL, 0xB0FBC05A35BF19F6ULL, 0x4CE97327C262BEA9ULL, 
            0x3B94D517DF293B41ULL, 0x2E12AA0CE4D2D0FAULL, 0x1D19EABB4AC39EAFULL, 0xC9645E11F7A5BF46ULL, 
            0x1CDAD52BADE8BAC3ULL, 0x7163CCC0364581FAULL, 0xEB9D0E01459B517DULL, 0x378B22C6246FAF24ULL
        },
        {
            0x7A6599613E0E4C85ULL, 0xDA6B915F8E3A5E08ULL, 0x2FBBA75D399B8432ULL, 0x20D308997CB4F06CULL, 
            0x1D06DF49673E7FF0ULL, 0xACCC04363FFBC91AULL, 0x258338BC09FC4534ULL, 0x0909A116DE2D9663ULL, 
            0x4FDF4AF1185F6B2CULL, 0x85A26B139906C578ULL, 0x12F04ED68240376FULL, 0xEB1937EC97D5AD12ULL, 
            0x9875795A7F62C497ULL, 0xD97D674DBAFD3987ULL, 0x49AF0E4B1FBEB19FULL, 0xEFC8734B52EC0B4BULL, 
            0x4750E49010DC9CF1ULL, 0x4A772366AF583289ULL, 0xBEFC2780D8AB77F4ULL, 0x6ED80A7C6F5BFC87ULL, 
            0x62ACCCC983860A36ULL, 0xE38B914BB69E8ED1ULL, 0xCB4053C30FC9FA2AULL, 0xC0D45CDF53D4D33AULL, 
            0x7907739C47CBB67BULL, 0xB7CA98E0FD398885ULL, 0x5D6F9F924C0442D0ULL, 0xC184FA26F4E73DE3ULL, 
            0x0F5B1542B15624E7ULL, 0x4190B7F3B5FAA1FBULL, 0x7E3A3E468451D2C9ULL, 0xB903D94023A19607ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseEConstants = {
    0x5C2B09A886C96B68ULL,
    0x024895C186AFE46AULL,
    0xCE0E0200DF7D43E2ULL,
    0x5C2B09A886C96B68ULL,
    0x024895C186AFE46AULL,
    0xCE0E0200DF7D43E2ULL,
    0x97D39753A98A8BD2ULL,
    0xB2DBC0175E66629CULL,
    0x45,
    0x2D,
    0xCF,
    0xA4,
    0x0B,
    0x7A,
    0xDB,
    0xAE
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseFSalts = {
    {
        {
            0x2093DE0EF8253655ULL, 0x0782B4E331B0C0B2ULL, 0x9C07B51E6D445A61ULL, 0x168738541AD2C59EULL, 
            0x51A429774A7A54E0ULL, 0x3771726A03A5F8AFULL, 0xD936F74AC68192EEULL, 0x81C62B3B6F8C581FULL, 
            0x4B8B3F0CA905F845ULL, 0x3A142E371ED3D6EAULL, 0x06E3EB66FCDD2EB7ULL, 0xE4F3C50A519924C6ULL, 
            0x9A8E2391E4A9044CULL, 0x0B3640463E189B6BULL, 0xF535A724C2AFFC43ULL, 0xE44409918EBAD73DULL, 
            0x563CFF180851E360ULL, 0x3AA1FE66AC41DF00ULL, 0x5FD40410A989C7C7ULL, 0x5C20E5E4CAA0632BULL, 
            0xF2189C3086DB2525ULL, 0x2AA2ECEF9FF15798ULL, 0x608A70B0D1A4EBC0ULL, 0x9499973EC4F7A14DULL, 
            0xD5FD11B36526326CULL, 0x3ED4CEC45EA3E606ULL, 0x80279FBFE1D73A32ULL, 0x6B0C1AEFE5316794ULL, 
            0xADF9DDC45746A120ULL, 0x98988B7D3CEEC395ULL, 0x0C5B616F42AF44A3ULL, 0xEE28FE828BFE5E24ULL
        },
        {
            0x0CE99B7EE928A7F9ULL, 0xA13A3467E0E3318EULL, 0x2966959982A60A49ULL, 0x08BF1BA0111B32EAULL, 
            0xB7EBABBDED8C0386ULL, 0xD6A6EA1ED5D921CAULL, 0xC7D5C247C3ED6703ULL, 0x32CA81E95945AF5FULL, 
            0x2E7B7F7B37B69A10ULL, 0x8E3D8898E27EBF94ULL, 0xE074A021A4404D62ULL, 0xF9E0E19C3B9ACC08ULL, 
            0x79A7A0DF773F3FDFULL, 0x0BD27710C4876FF1ULL, 0x305A760652B2BE95ULL, 0x410FA5B567D8A83EULL, 
            0x2BD80EA01CBB141BULL, 0x20530168F83C373CULL, 0x6C12BF76C12C07ACULL, 0x6DC61A9DAF6DCB83ULL, 
            0xFDC0F3308C707CFBULL, 0xA3F40C0339AD3A0DULL, 0xD8EF19C086465EAFULL, 0x14F79D9FBEFB1A0DULL, 
            0xBE9624452F157C61ULL, 0x3BB94CCB2AAE28D1ULL, 0xB8CB3C3F608D9AD9ULL, 0x1D89BEA4E267C7D4ULL, 
            0x7B48B5E16D3FBA43ULL, 0x04696B7FA689BF8CULL, 0xB3BC3B9E2E59A67AULL, 0x5FCC9B9238038A1DULL
        },
        {
            0xC27060324B6C7930ULL, 0x9F6247F0A00A0E97ULL, 0xF649AD29C7011D41ULL, 0xE8B1FB0E62347E16ULL, 
            0x23DAA585088C7B19ULL, 0xDDAD6040DE2FD2CDULL, 0x98D6386115E15304ULL, 0xB940443A19ACBD14ULL, 
            0x612E956000AA719EULL, 0x3EAA58537CCB470BULL, 0x1D9F8097BAB3A67EULL, 0xB84E389AF84DF58EULL, 
            0x3EAF698583B61E35ULL, 0x606175426E981190ULL, 0x011070778A550A62ULL, 0x1DE3B81B0030676CULL, 
            0x1562A2082D79C4CEULL, 0x8B39772CA519BE3DULL, 0x5BA4435377876DE6ULL, 0x1CB8EACC816928CBULL, 
            0x01E9029388866B86ULL, 0x5DD6D1FA7E38EBACULL, 0x3CBA7318D96BBE95ULL, 0xA19C09C91D904D15ULL, 
            0x2E2D1BBB50758630ULL, 0x1E2699740D0454DAULL, 0xBE760F78EE8C6D08ULL, 0x3DC67E0D2BD0520BULL, 
            0x6200E8C42939F61DULL, 0x3448F85D5D209D09ULL, 0x8E8E8CC537EB74A6ULL, 0x3C7ACD5E183C4331ULL
        },
        {
            0x6DA099189F29C740ULL, 0x22196CAB47FB266DULL, 0x0390175BEB925F7BULL, 0xA1F9B0FF48FC060FULL, 
            0x08D6CF0A3A0F2318ULL, 0xED235A4C29DFD52BULL, 0x04FB69627E11C09EULL, 0x5834EE0B234D796BULL, 
            0xA34005CE9B7547D8ULL, 0x29EBF08EF17111D3ULL, 0x4A007DCCB5B2B383ULL, 0x21AAB1D3EDF746EAULL, 
            0x1435EA2A4606D835ULL, 0x5B79D42CF8369085ULL, 0x972EFC01A69A5347ULL, 0xC629D3207991349EULL, 
            0x4B5C392DCB822901ULL, 0x86A330C3E4BA7901ULL, 0x3BD4ADF01766BE2AULL, 0xD6A22EB47BD7B483ULL, 
            0x6F02127B0D4078F7ULL, 0xA3077BA9DB9849D4ULL, 0x11369F579F5A7512ULL, 0x94EE90705DE822D5ULL, 
            0xB333B85A27531A12ULL, 0xEB491956F4E76AECULL, 0x6ACF7921FF497E15ULL, 0x6D12DE796C3420F1ULL, 
            0x00C6139E06EFF15FULL, 0xE2E2570B9B8A7C5AULL, 0x99D83D08656BB60AULL, 0xC16E472827D26975ULL
        },
        {
            0x56D154EAD1C6E212ULL, 0xE588B30F01A54F0AULL, 0x23D523575961578DULL, 0x4151D9B01BEA5CA4ULL, 
            0x729B86619BAA45A0ULL, 0x792EBA62CF57D707ULL, 0x44BB64C0AA9DB58DULL, 0x771B68E582DAC201ULL, 
            0x89AE12E5BA0751C9ULL, 0xAFB10247F992AA3DULL, 0xBF22A0B32EB4783DULL, 0x63A4E6A2CE66824AULL, 
            0xA50EE1899B8EDF71ULL, 0x3C0CC30FB0B8075FULL, 0xEE8CBB85AC48FE87ULL, 0x1CC2D40908424EACULL, 
            0x8E14E44038E9172AULL, 0xF8E2FBFDCAFBB5E6ULL, 0x9069638AF9936926ULL, 0xC5359B2A13398DE4ULL, 
            0x9C944DE21208F443ULL, 0x3D216CFF22AF599FULL, 0x614FB754A1BDCD99ULL, 0x49950BDAA047265FULL, 
            0xDDE0C8B7C54FC159ULL, 0xB27535B942DBA8DEULL, 0x58BABE10563288ABULL, 0x3ED3B4232429E57DULL, 
            0x9457CEA564A124A0ULL, 0x125F25C4EAF905DAULL, 0x09F68874E04AA849ULL, 0x17DA2AEC75F0D7BBULL
        },
        {
            0x11FCBEB9E317244AULL, 0xF99A93AE3EF3082CULL, 0xC81CCAA9C74B3B99ULL, 0xFF1DE9D495DF0FA6ULL, 
            0x3DE5A48DC6FF7B1FULL, 0x46A7B63B7A5F7EAFULL, 0xC379E4AC50712E88ULL, 0xEEBAE1A6D052764DULL, 
            0xC65F974643E9921FULL, 0x15E7915046A6FEEEULL, 0x6800A36049B6A069ULL, 0xC8A423A3136FEBCFULL, 
            0xF51BE93FF65FD654ULL, 0xC7ED5BE610BBEBB5ULL, 0x428CE2DA6D543777ULL, 0xF8F225ED70BD162EULL, 
            0xFD8D3A56E7209341ULL, 0x174A616F84F897A1ULL, 0xD907F57F139264D7ULL, 0x3849B633450379C3ULL, 
            0xB558E5A84F679015ULL, 0x50E5A056B0F80C82ULL, 0x7E57131046F65BEAULL, 0x2C3E2F5F5251F5CEULL, 
            0x41DB435BC7D33A77ULL, 0x10A4C14A867CC3DEULL, 0xBE89374960150DE8ULL, 0x2AE71C1D54D81599ULL, 
            0x33E5505CEC797F75ULL, 0x04662B803AF4E5B3ULL, 0x2DDBDCC490F9CF17ULL, 0x99C9331AC564D638ULL
        }
    },
    {
        {
            0xA365D29EB85E3331ULL, 0xBA3C5050B373A5F2ULL, 0x1119683F3E69FA47ULL, 0xB29BBB0EC0B47B7EULL, 
            0xD7AFD91A39BA1F2EULL, 0x499BF2187559ADD3ULL, 0xA4AE407E02C2749AULL, 0xF310BA9E7C7C5B86ULL, 
            0xFA4FE75A0C4A89BEULL, 0x780B4D5220558539ULL, 0x6EA7A032421D5126ULL, 0xE8F429E862196231ULL, 
            0xEEC7C25F49079705ULL, 0x88B03863A7DCA38CULL, 0x9FC5E506AFADA322ULL, 0x6F9D0272F1663B6AULL, 
            0x57F697B17B227441ULL, 0x8C238A29E75D14CCULL, 0xF7516547FF2D9832ULL, 0x334D9D7B69B46F9DULL, 
            0xF9CF8B5A67E82045ULL, 0xA9595B436217B0AAULL, 0xAE9B761F8A6DE596ULL, 0x255006D13B75EF3DULL, 
            0xE5C586D108BD3722ULL, 0xEAC70EE86D354E80ULL, 0x45EEA53440A44D15ULL, 0x3A689DEB1C20BA35ULL, 
            0x82C90A477124891AULL, 0x11ED525F59672902ULL, 0x7F9F2943C4C975C9ULL, 0xA43E707A262BA942ULL
        },
        {
            0x8874794C930B97B6ULL, 0x48D2CE0F20464E7EULL, 0x68B523F1E943C7F2ULL, 0x79EB5E6453B7FCF6ULL, 
            0x2842085C5538FF44ULL, 0x11B8360745D8C69CULL, 0x514A1BC57FC50274ULL, 0x819A55A05873DDCFULL, 
            0x957A71840726951CULL, 0x7507FE4C22731386ULL, 0x30B834ADF091DB31ULL, 0xF5ADAFD0DCBBF52FULL, 
            0x9A1C6DF1421FCDFDULL, 0xAF75AE73910135C3ULL, 0x9250AF5AABA06EFEULL, 0xC46575468FCA8699ULL, 
            0xBA57413FDB33DCC9ULL, 0xD04D2D74DE8532FFULL, 0x1B5A2164579DE37BULL, 0xFD277D3874B609A0ULL, 
            0xFAC5ED5CC8A87EDCULL, 0x0B3FABBD8B230B1AULL, 0x13E6686EB999076CULL, 0x2D56DD0428B29456ULL, 
            0x5A2778253940549FULL, 0xBC5D8325BD57A985ULL, 0xF729696F6546C145ULL, 0x29C5DA3DA95CAE94ULL, 
            0xC860D00E7264AA0BULL, 0x8B108C801B93A757ULL, 0x574AC3F38AB82CB7ULL, 0x154D997FBE310417ULL
        },
        {
            0x0A426E2F8B62FE5AULL, 0x05542EDB29A79F4EULL, 0x975A6176AE2D3805ULL, 0x2313EEE1D4CE81E0ULL, 
            0xD85EDD6840D54445ULL, 0x03759E5CCBBF12E4ULL, 0x29385C4A3CACB5EAULL, 0x2EA5677F871853E1ULL, 
            0xFBBDFFCBD2C87C08ULL, 0x8808B0B1B9D02443ULL, 0x2A1FB1D289172814ULL, 0x491D344808B33D40ULL, 
            0x90A0B7AD3D24EF5AULL, 0x7E2AB9AD9FF3D9BEULL, 0x7B60235DEA05886EULL, 0xDE55369F7745D700ULL, 
            0xEB1BF320EA1F3692ULL, 0x8FB2CA21FD9D77D7ULL, 0x4DC3C1FB293A1455ULL, 0xA7886A15705D3698ULL, 
            0xB8A12755AD943DC8ULL, 0x045A55A9289732F0ULL, 0x37195E1F4E4DF0FBULL, 0xE800A36CCD5DD82EULL, 
            0x0CCBEA98F075DD07ULL, 0xE26C44724226E4E3ULL, 0xD0CD2D0386AB1FC4ULL, 0x5BD999715466BC4EULL, 
            0xD3CAA40879B78C4CULL, 0x8F6C455B46EC54E3ULL, 0xDE3DB0F094EDF69EULL, 0xC302311400E4990FULL
        },
        {
            0x106D6C51F8E4936AULL, 0x77F06736036B3A1AULL, 0x95B697CC2629A96EULL, 0x97E7A250E5D6D6C4ULL, 
            0x1285924750F5CC5EULL, 0x7604CFE427BDB1D5ULL, 0xA4699B6E8703043CULL, 0x8BC83930D7BA1D2AULL, 
            0x5764610A78045143ULL, 0xF6073E85DF209761ULL, 0x9FCADC9BEFFB20E1ULL, 0x886BE14A1FBBE2CAULL, 
            0x6ADF0A77639484A3ULL, 0x2071606D4014E4DCULL, 0x24BC97A249580B93ULL, 0xB585046AFE878DF1ULL, 
            0xC6D79B10A5B86DE9ULL, 0x11E93C85C0CABAEAULL, 0x039444D989260AC2ULL, 0xEE3877F1B044D45EULL, 
            0x34807EB7F425A310ULL, 0x5E0F1F3F5DFC471EULL, 0x17DB70BE323DD6A1ULL, 0xDA4D7F148BCD77B2ULL, 
            0xC3ABA347065A186AULL, 0x21DFE3D8B7F0C99CULL, 0x37A99191D67D650BULL, 0xCDB4C1E085D3D7EBULL, 
            0x3223F0D287EE4D38ULL, 0x1F60B2E86FA51145ULL, 0x7169C27719F92FB2ULL, 0xC436BAEDE2799FE5ULL
        },
        {
            0x57D70853A056FB36ULL, 0xD09C976F8A5080F4ULL, 0xCE71D653990E678DULL, 0x828088B36A2B4258ULL, 
            0xD174EB0900F12EA4ULL, 0xC810BA39BDEC83D0ULL, 0xAAC01E21E94D8B5FULL, 0x30733AC3ACD95FC3ULL, 
            0xFCF18E7CEE1CC30CULL, 0xB8DB77BA4A6F1DEFULL, 0x8CF1A2E38F5C1203ULL, 0xDE5DAC7F473E00F9ULL, 
            0xC54031A0ABA8AC8FULL, 0x62BBEB1A0348D751ULL, 0xBECA3A14D1193608ULL, 0x177F2BF3938D7377ULL, 
            0x0130E9D78582AB4AULL, 0x1248810E2A1D1C5EULL, 0x1A912595801B1431ULL, 0x8C8EB5B99B221A32ULL, 
            0x346068D843BA06AAULL, 0x4011B9552FEB1B40ULL, 0x30EFE1458D643924ULL, 0x44454085E35DD376ULL, 
            0xBFFBF8B0BDE00253ULL, 0x7797A99563399A68ULL, 0x96C097044585CD04ULL, 0x3D4618144276396BULL, 
            0xF149A6C6678203CAULL, 0xCFAD7DCAB5088194ULL, 0xE3D7AB411E10FF4CULL, 0xFEF608EABE3057D9ULL
        },
        {
            0x20B24BCA545B5F09ULL, 0xAD765A4A543752C1ULL, 0xB520CE6BE9EFFAD2ULL, 0x58EB92B5CE337778ULL, 
            0xF741A6887FD3CC7FULL, 0x7979204ABB121DC3ULL, 0x1DE8AB33B916D787ULL, 0xA3EC03DAE8E7C024ULL, 
            0x2940B20FFE8B111BULL, 0x149BF86B1CB217ADULL, 0xC82D17994B47BA11ULL, 0x37367F5AE1ABC3BFULL, 
            0x14F6D43AD926CED9ULL, 0x2F1E2F19B7A7C2D5ULL, 0xCE015FACFE09186EULL, 0xE508E68C56C06371ULL, 
            0x5AE26E78894F10FBULL, 0xA6E6CF7D22CF12BAULL, 0x89DCC50359D27DA9ULL, 0x4061044D64556400ULL, 
            0xE65AAF4541064D53ULL, 0xED849C5D59682530ULL, 0xD4E10D883BEAD2D2ULL, 0x66327038B02D7C26ULL, 
            0x7921AAE215EA22EEULL, 0x9041AB96A67CBF6BULL, 0x83CE513FCAB75692ULL, 0xB441EB811C394323ULL, 
            0x5C5F954702E32FDDULL, 0xF6005F7526B7B394ULL, 0x0CD3E2F40A1FC8BAULL, 0x1627DBA2F5FC5E73ULL
        }
    },
    {
        {
            0x3565B03A2920A38BULL, 0x06710C003AAADE4AULL, 0x07FF452B94FF63F6ULL, 0x43F37F6A6C6B2AB5ULL, 
            0x36B4CB6287E76D6BULL, 0x79476D9A775AEB8FULL, 0x50E702746814EE38ULL, 0x25AF012FA8E4508EULL, 
            0xB6D400A567C876E2ULL, 0x43619943AACA79A4ULL, 0xF284957CFFFBA966ULL, 0x593415E6BE2808F9ULL, 
            0x581F7E8484893D56ULL, 0xAF47A686541F3D7DULL, 0xB61F07F7BF8C6456ULL, 0x1461D37E5A084334ULL, 
            0xA48BE8C2581B63D1ULL, 0xDB3855293522C5DDULL, 0xC559D4BCA7C03CB4ULL, 0x53F5CF452D5C0E07ULL, 
            0x3518D279659D617BULL, 0x12B33F588B6B9D1EULL, 0xA7F8253994751C3BULL, 0xF332C0E9B37A9A17ULL, 
            0xA0A889D90F19688EULL, 0x288411B475C68609ULL, 0x8A27B90FF14CF25AULL, 0x0AAB2C27AC3A2F13ULL, 
            0xD3705E05AD6DC71CULL, 0x364A83F819E977E4ULL, 0x007F81003CDA1AB2ULL, 0x010185BE4CC061B2ULL
        },
        {
            0x407988E4BF0647E0ULL, 0xE3FBAB6E30244A80ULL, 0x3738DD4DB563013FULL, 0xA6A22107BB2EBD65ULL, 
            0x439001FAEB7E387EULL, 0xE4842D955ED6DE89ULL, 0xFE170763ECDDF01FULL, 0xBB52DA3B25DDA322ULL, 
            0xF5EA2CCAA4D83723ULL, 0x99AEBD33CEAE6EAEULL, 0x58F36E3307A76826ULL, 0x4C313D5E8E46A0C9ULL, 
            0x4F1C26B7B747A841ULL, 0xF3BAEB49370BF788ULL, 0x30788A3EFA1044EAULL, 0x3CE08BBEBA34A593ULL, 
            0x53C0FB9201D5C787ULL, 0x9DEA6A1758F56E29ULL, 0x48FD840AB3D16674ULL, 0x10A46172B970893AULL, 
            0x3F460D5EF0399767ULL, 0x846A96D09E91704CULL, 0x0F0FCC89790FDA47ULL, 0xD7AEE72CB2B93DE4ULL, 
            0x1A984A30DDE7B2F4ULL, 0x0CF4CDB5B0B2C458ULL, 0x38EC32CDC436BAF0ULL, 0x548EF87FD6070B8BULL, 
            0xBC502DC0985252ECULL, 0x1BDA70EB8F2D01F9ULL, 0x36A1ACCCC421F156ULL, 0x27A724A949FE08ABULL
        },
        {
            0x7649D58401E483E0ULL, 0x41078711963B5EFFULL, 0xFFB07B79AD21817BULL, 0x1A8A149504646054ULL, 
            0xE329B0CB00C1EDF5ULL, 0x118B61CBC59B41C1ULL, 0xDC790DE2B94A3ED8ULL, 0x5F748366C567A2E4ULL, 
            0x6D04965832399380ULL, 0x4F947B311CEFB17EULL, 0x179C7F8D91C82600ULL, 0x599336571E5E48FEULL, 
            0x6FB9F4D45B9B038DULL, 0xBD23FB7D1FFF8DD8ULL, 0x47341005CAA03BB2ULL, 0x94268ED04E1E596CULL, 
            0x576397B0B49C0E74ULL, 0xE2682528CC36348FULL, 0xDFBD945E958CE406ULL, 0x64D90D959453575FULL, 
            0x61151B4D75DB73A7ULL, 0xD21E493E53A1E95DULL, 0x76429712E93730A0ULL, 0xBC5FFF1A13A9EA8AULL, 
            0xDBDF77B44D6EDD2DULL, 0x058CE0342B550AA9ULL, 0x8E7683107CA1E214ULL, 0x449FAA11DCE1C4B3ULL, 
            0x52BE8809E168856CULL, 0x437C161E26FB1F9EULL, 0x085F0C792DBD7552ULL, 0x436E8F1A0587569CULL
        },
        {
            0xEE01190D63E67DCCULL, 0xD0AB5C12C40C03EAULL, 0xDBE9ACCEC7BC565CULL, 0xF377D03060FFC86AULL, 
            0x19F80AB75046850BULL, 0x3C619900656167EBULL, 0x58A190176D3E6E4BULL, 0x274AE44C036F3B17ULL, 
            0x87B6D90CB853F15DULL, 0xA8F887D7DB6515DDULL, 0xEB807F52E77E21C8ULL, 0x2412A179A200F7E0ULL, 
            0xB4F4250D84EF3913ULL, 0x668D70AE9D12472BULL, 0x4202A550431A5C93ULL, 0x6BE45A3985B47F80ULL, 
            0x528FCDC90CE0717BULL, 0xE332B1E2B9EA19AFULL, 0xAF0A53993F34BF4CULL, 0x71453519F01B0084ULL, 
            0xCFE620A1E5F709E0ULL, 0xC72E11B86B8C06C1ULL, 0x414DE9107E600A7DULL, 0x1AA7317563DEB921ULL, 
            0x201817CC8EB6C14FULL, 0x0065A15627E93824ULL, 0x36DEF5105696D847ULL, 0x9F90C1436A7E410EULL, 
            0x14A38ED7D2252385ULL, 0x2FFF313409D6D4A6ULL, 0x02322FE5CD4891AFULL, 0x834045A9FF52F57FULL
        },
        {
            0x643D17E4B7520819ULL, 0x923F693F29F5101EULL, 0x4FA33657DF89FB58ULL, 0xAF5C116D7037D3EEULL, 
            0x80CCE967BA04E468ULL, 0xBFD0AB06949DD7F1ULL, 0x9AD9D8B9FC8319A0ULL, 0x4791DC4AB512334DULL, 
            0x8E9A1A4250EF8FF0ULL, 0x71B7A84D48F2BE28ULL, 0x3259E4226E37D658ULL, 0x4391D6E80B336B15ULL, 
            0xF25DF28D90340CA8ULL, 0x01A1A73AFCC53DA9ULL, 0x774EDDE743F1C233ULL, 0x0CF7085C4432B0C3ULL, 
            0xCE9EE70AC1C9C3E1ULL, 0xC7CBDBFF97F2631DULL, 0x561755A1F9A78949ULL, 0x4750F1BE4FCDBC2BULL, 
            0x7A807B303AE7A6B9ULL, 0x7EF33AE52939D2BBULL, 0xFDDB740F95B7C876ULL, 0xFEA27CB9CDF6D29DULL, 
            0xE6D993BB00E0AC77ULL, 0xE97A73A7EF6C7A2DULL, 0x5B3DA840606EF2E0ULL, 0xCA559E970EE9D27DULL, 
            0xDC8C86E520CB519AULL, 0xECF9BFFF51BEEB14ULL, 0x7D430FE3D8BB65C2ULL, 0x09E2483759D13707ULL
        },
        {
            0x718F89CFB84A5A62ULL, 0x503700F4D8A22B46ULL, 0x5D5259AE0233AB94ULL, 0x6CA30528868EBC3BULL, 
            0xC76D3CBCBA306351ULL, 0x17A19D5FB43BA106ULL, 0x7E6BDA05ABDE7F47ULL, 0x0414542324AD02E6ULL, 
            0x3D33D8166FE2091CULL, 0xD69ABEE131CD7600ULL, 0x4C88738B70227E5FULL, 0x08556B009A797DFDULL, 
            0x8E44CAE5C296FDEDULL, 0x8E4D5F8584E8E7D9ULL, 0x9BB74F5C569DC331ULL, 0x19EAFC822763F546ULL, 
            0xB857A253E7283ABEULL, 0x42DCDDE04CC09A58ULL, 0x7598D3C9C00B316CULL, 0x0BC7343B405E84DDULL, 
            0xA0E01F1A7ABC7E81ULL, 0xD5DCE0CDF85AEE4EULL, 0x70A0F9F548580924ULL, 0x75024906422FBCA6ULL, 
            0x0D1DB449453E1F98ULL, 0x9EA307908EE0B5FAULL, 0xE811EFF34AD34C7CULL, 0xC406668618583A67ULL, 
            0xC168834960DA021CULL, 0x19910DFFFE7585BAULL, 0xDB009B13A4FCFDFEULL, 0x5FD732FEAA8F0AD2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseFConstants = {
    0xF2C91B1EF9E092DDULL,
    0x7B8B63E367082A10ULL,
    0xEC77217F381E292FULL,
    0xF2C91B1EF9E092DDULL,
    0x7B8B63E367082A10ULL,
    0xEC77217F381E292FULL,
    0x3D7A6DB0A9D3EF33ULL,
    0x2B4608C6B710AAF2ULL,
    0xB7,
    0x37,
    0xE7,
    0x01,
    0xE3,
    0x33,
    0xB6,
    0xB5
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseGSalts = {
    {
        {
            0x3EABBF3E93CEBC6BULL, 0xB89E23362E1A0476ULL, 0x3088878BE51C0A05ULL, 0xC0F0A353A61D0967ULL, 
            0x22A7A51CF88779D3ULL, 0x57732697C5EDCFDFULL, 0x1885F67CDE5E34E5ULL, 0x96EC95182203F1D7ULL, 
            0x49F62C92D0159B41ULL, 0x23173105F2D8D14BULL, 0x99A89D547792798EULL, 0x34D4F56FFCF9AE11ULL, 
            0x046D954601F06746ULL, 0xDCDCDB347887223FULL, 0xA3795EC37D54B83AULL, 0x3BAF0A63484FE5B1ULL, 
            0x4674B99F6BD15AFCULL, 0x13A3A0A43C4C7649ULL, 0x7EAFE1481050FA08ULL, 0x23EFD4035733E0F0ULL, 
            0xC38EEF83252B632CULL, 0xF46590856D4C03E8ULL, 0x4AD75A96411D12A8ULL, 0xDFD21DC18E19E098ULL, 
            0x3A3EE7B59804C8EAULL, 0xAFA152DD4AB34031ULL, 0xBB507A42B573D89FULL, 0xE312E513A2D14265ULL, 
            0x25C2F442FC29EE1CULL, 0x1D65B1A8068F6C1EULL, 0x7F544EDE964D3B9FULL, 0x82F7B3CA98BA1382ULL
        },
        {
            0x727AA253FD432F7EULL, 0x36985728C12A7FE9ULL, 0x1B8A021CEB184629ULL, 0xE57131EDBA9CCCE5ULL, 
            0xF6AEAE6FE4E12ECAULL, 0x79F8673917B095A2ULL, 0xD162F8278C59401CULL, 0x6E9C4B74D552EA67ULL, 
            0xA3E2741D52B955C1ULL, 0x8C5A6F8BF4BB58CDULL, 0x32331DDB77545A1DULL, 0xDA9F4F8DC88C1650ULL, 
            0x88BD49A537A20FC9ULL, 0xA6C6150F5F1622A0ULL, 0x16FFF90FF5AEA584ULL, 0xB5225DD02EA92211ULL, 
            0x16716039448969D1ULL, 0x78E2AE1F36FED476ULL, 0x60C3271371BB4DA1ULL, 0xF34F4D1F4E12F39FULL, 
            0xEAA31FB74782E2CCULL, 0xA2EEDB505D1BF567ULL, 0x0A8C0C5A14827CD1ULL, 0x72D4B43590627B9FULL, 
            0xD12409722BCEB5F2ULL, 0x4CBFEF1A2CB823FEULL, 0x2617A27C46A04FB2ULL, 0xB6680E32D79202FEULL, 
            0xE57D5A5937F89D0FULL, 0x4E20576730F04A3EULL, 0x6921DDAA5C6F1FEBULL, 0x400F2E3C642B0573ULL
        },
        {
            0x42ADBBDBE8ACD290ULL, 0x18549867FA0750E4ULL, 0x1FFC4DB178D56B46ULL, 0xD6DE45C302E88BF6ULL, 
            0x7B80ABA6AEB43ED2ULL, 0x2514723ED0050C20ULL, 0xD2071838FAC38BBEULL, 0x3AB77BCF6DAEA8C5ULL, 
            0x8A7F3701FC1F24FEULL, 0x9A685A4EE3E466DEULL, 0xDCFD13FC9C1EEC62ULL, 0x38F9DB7D13BCAD7AULL, 
            0x38D31E417B51408AULL, 0xB2AB984A9D0EF3CAULL, 0x0292D9C3608C4DE9ULL, 0xDAF563579D501FBCULL, 
            0xD3173109D631CE6DULL, 0xEBF896B30DDBD91BULL, 0xE5DE8DAA711AC018ULL, 0xD89ED3D41D5246F4ULL, 
            0x7ECB320CECD38A4DULL, 0xC4DC9E4D62730314ULL, 0x840F6C61995B7306ULL, 0x35001C793F003155ULL, 
            0x5574885B429EB87CULL, 0xE4ED5974B9323905ULL, 0x5281A1346CDE4C25ULL, 0x283043EB1A957707ULL, 
            0x5D5E23CC3A30B345ULL, 0x1242E37B6056B607ULL, 0xB0C5EC36EF32A790ULL, 0x3F0AF934325D74D3ULL
        },
        {
            0xEDC105EEB940C298ULL, 0xEA0EC75A2DA784A3ULL, 0x8300EFB7A01B2B71ULL, 0x7CD2664F3484CCA9ULL, 
            0x527163881DF071B1ULL, 0x42CEC126356C1724ULL, 0xC0EAC85734CD3DA2ULL, 0xACBB0D445A628A2EULL, 
            0xA339F95F7DE25BD8ULL, 0xA4BDDC0B88572005ULL, 0x15C2987A815EA821ULL, 0xEACB3C8BFD5D5DDCULL, 
            0x05582C68D13B4B4BULL, 0xD75ECA906FD710A3ULL, 0x5C9C54E2BD686DEAULL, 0x5511755DC867D53AULL, 
            0xE834228F6984A382ULL, 0xB5F80CCA19F7B9EAULL, 0xA88533298B3833ABULL, 0xF275C94D7C1211D6ULL, 
            0x884526233359EC56ULL, 0x417089A04DB60582ULL, 0x61161D5EE171C455ULL, 0x20DB6F2B5081BF7EULL, 
            0x8B794AACD427CA5CULL, 0x047C7C6416482844ULL, 0x3534773CE6115F15ULL, 0xB46F563EA491C980ULL, 
            0xF85E859CFC830573ULL, 0xFE628327851E4397ULL, 0xDF444C2EEF5E5059ULL, 0x9EA0DABF9DCB2C6EULL
        },
        {
            0xA0A0135449C3C563ULL, 0xF6AB3CE584B37859ULL, 0xF2328D598FE73BA5ULL, 0xAAA2D7B6FC597032ULL, 
            0x154429F571D6B5B1ULL, 0xB7903AA9EB0A1633ULL, 0xB59C036D9ACC0CE8ULL, 0x94F2B44733B141C9ULL, 
            0x88533E145905BDDCULL, 0x22D7CC349F600B33ULL, 0x53709C5E5CE0372EULL, 0x580B800843123F85ULL, 
            0xE7CD46CB605CCDDDULL, 0xA89956B96DA9E097ULL, 0xD6DC380FDFB370FAULL, 0x775EC5139B24523CULL, 
            0x336E011DB529F9FEULL, 0x336635E3BA94F05DULL, 0xDDA3F8117F2B8EB1ULL, 0xCC6ABB95311250DDULL, 
            0xCC7E3EEF9C1D52ECULL, 0x029410923C726BA2ULL, 0x1FE77C7CCCE08CF0ULL, 0x086DD17B1C8E2A08ULL, 
            0xC91CCABEB30D5F91ULL, 0x758A8B201B91CA2BULL, 0x3E48027967877552ULL, 0x226CFB3DBEA24548ULL, 
            0x7B74A0932DD3AC1EULL, 0xFD121E3DBC85C0E5ULL, 0xAA330BB64A9C2D2AULL, 0x9F01AF0615A5EBD3ULL
        },
        {
            0xF0757B5EB51A9C68ULL, 0x0DD16F594C8A336FULL, 0xA9DC5A873CE4A606ULL, 0xE4487297C48911A8ULL, 
            0x6268711E80F6704FULL, 0xAD207F25A0B60C8FULL, 0x2720616A5E3F6B3FULL, 0x87CD34D5022ECE68ULL, 
            0x279B2AD8864E35BCULL, 0x8B6F167653A19664ULL, 0xF7D883095E8E7059ULL, 0x597AF40D276A0F5DULL, 
            0xBCD58570B8EF2A08ULL, 0x073099AAE86E47E1ULL, 0xFDF82DAD8EF374EFULL, 0x5478F43FE51E8B42ULL, 
            0xA8C41401907FFD06ULL, 0xEC3250CDDD2BFDD4ULL, 0x61CB23FF6D594689ULL, 0x1DF033D53A14FE8BULL, 
            0xE2F974E2286B04E4ULL, 0x3488D11A694B33DAULL, 0xD32B6A609D546D8DULL, 0x53F547B6C7D607C7ULL, 
            0xDEE2E771597A34B1ULL, 0xDC8C12124443A842ULL, 0x2E6EB90D82E6B5DCULL, 0x5A996EE5298DC0A3ULL, 
            0xCD3B30B932908DBCULL, 0xA826089114564947ULL, 0x4254BAE362CCEE13ULL, 0x725CC51574428339ULL
        }
    },
    {
        {
            0x2CC99D0590787561ULL, 0xB24432955AA55510ULL, 0xC76F244643E924B1ULL, 0xA0662F1C584C0249ULL, 
            0xB72F866626FE38A9ULL, 0xC3D660943088D62AULL, 0xA15A74F7D483C0D2ULL, 0x99AC9E894E26C808ULL, 
            0xB495655CB6973FA5ULL, 0xBA2F5A6081D86967ULL, 0xED43114B60C68944ULL, 0x27CCD36A6BECC9FBULL, 
            0xAFDDFB3448ED77ECULL, 0x38C1B1ED3F08A041ULL, 0x428012B7B20AE6AEULL, 0x19881F36C6E23071ULL, 
            0xCC6092A3709C957AULL, 0x2CC928120A89E168ULL, 0xCC980473A96E032EULL, 0x6025591C892A1311ULL, 
            0x2DF8D2692ECB6DA2ULL, 0xA901D575AABCE1F9ULL, 0x31D209E1904A59F5ULL, 0x5409FC686B894DDDULL, 
            0x9E06B2900B0CD1B0ULL, 0x020454A9F691E21AULL, 0x5282DDDC0F2AB5EBULL, 0xB9BA9CF25870DC21ULL, 
            0xB252366354F0E849ULL, 0xDE37DF35B29DDC13ULL, 0x3029C94B8B954A1FULL, 0x339E2C13A145EABCULL
        },
        {
            0xBDF439B3C2469C1DULL, 0x6AC247DB2110A0C1ULL, 0xF2C59E4D3A06D280ULL, 0x80EFBABE144FFEA3ULL, 
            0xE8D6775990BDB9F3ULL, 0x198FE7709E380F10ULL, 0x68A149E30CBAFCDBULL, 0xF4F30774660625D3ULL, 
            0x1665F5C634868F3FULL, 0x7E5D665DAE260E8CULL, 0xC4F23276B052D880ULL, 0xDB5F7E5A4BB913A4ULL, 
            0xB48057DC8217A8E2ULL, 0x22DD070BEA0B6761ULL, 0xE071ED0516E28175ULL, 0x0746F86CB456FC02ULL, 
            0x8E44892CA22FF247ULL, 0xC4A526492B816327ULL, 0x8680969917C45D9CULL, 0xA94899CD3F864B0BULL, 
            0x57EB5C1DC1FC0C90ULL, 0xBF974CCCB07DCF5CULL, 0x053DEA6C10471A9AULL, 0xB4BBC49DA544FF6FULL, 
            0x3F9D9A54612FD26CULL, 0xD36FBEDB82D1C60EULL, 0x869E3EAC1AA1FF34ULL, 0x6962D4AE50BB8164ULL, 
            0xB27CDF5ED8C86295ULL, 0xD0F7E260D2339CFCULL, 0xF57AABE391E4012EULL, 0xF9028084F6CDDFE9ULL
        },
        {
            0x532C4F6FA8376B32ULL, 0x7C50A0A107740C0BULL, 0x6FECE7AFE6E251D3ULL, 0xF256774B0339F586ULL, 
            0xE383F5CF0D05001AULL, 0x2A2D4556FACFFE54ULL, 0xF97D02870C0D0D93ULL, 0xC4BC6D3D90D1CE6BULL, 
            0x914C1552B38B51DCULL, 0x86208A3E124F35D9ULL, 0xC9EBA6E8D0FB268BULL, 0x0F7019B21D9626FBULL, 
            0x492395BF2616A026ULL, 0x97F1956BEB75DFEAULL, 0x0612AAF1CB4CC6E8ULL, 0x71CCAB45A0DC90FDULL, 
            0xE579F4798F4DD853ULL, 0xF18FAC067254FE0DULL, 0x1F475B4A4FFB424EULL, 0xC8439B66D8C929B7ULL, 
            0x90682051195AF119ULL, 0xBA4A2CDEBC78F253ULL, 0xA2CBFAD95B0DA255ULL, 0x532D875A05126106ULL, 
            0xDCD8DDB2C85917AFULL, 0x2CBC9E284030B6CFULL, 0x94E0ECA4DCC5EFCCULL, 0x0439CCE68C036B4DULL, 
            0xB4F153572DCB56AEULL, 0x5BECD59292D14A48ULL, 0x09ED34F01D445596ULL, 0xE6CFB1450ECDB810ULL
        },
        {
            0x80D9C25EFBC96E84ULL, 0x1F9C4641E563A6D5ULL, 0x14F2736137E1BEAAULL, 0xBBC786A054D7491CULL, 
            0xFCDC18602832DB41ULL, 0x19CD1B798B45557FULL, 0xC90BD6BDBD88A6BEULL, 0xA3104924A5E834DEULL, 
            0xD3CCC2EC4B0028E9ULL, 0x0A7E14FD8ADCE586ULL, 0x8582033FA9CD99ABULL, 0xA3CF5C1E78D146ABULL, 
            0xE3C54B29903CEA43ULL, 0x06A91F458434C7CFULL, 0xFCF8C54111CE0261ULL, 0x179AFF06945E31FBULL, 
            0x893339735E598A1BULL, 0x4AFB25166F664397ULL, 0x1F52410E49D9E78AULL, 0xB14CDFD58E39A653ULL, 
            0x76836C91E896BDF6ULL, 0x9A36E0ECE52A2A76ULL, 0xBD4FC477F7E0EDD9ULL, 0xB5CD4FDCB4B17F4CULL, 
            0x040C65524894F1A8ULL, 0x95F8F4218B6D3EA8ULL, 0x04197F9AA6C72B4DULL, 0x3BB1719CAC75E18AULL, 
            0x835FDAE6101412B2ULL, 0x2C87D2E38A50A138ULL, 0xF25878C678B92043ULL, 0x0AA8BDA7D15B4A2BULL
        },
        {
            0x5797E60E12C626BAULL, 0x388973481741573EULL, 0x53ABDB56790C2948ULL, 0x5915354C92947538ULL, 
            0xB6AB2A370DDEAF74ULL, 0xD2C535FCAC7CF81CULL, 0xF301134437E0E1FBULL, 0xEE1BEFC0FE6AE854ULL, 
            0x313EB136B313E646ULL, 0x47532A18439F5C99ULL, 0x3C47EADB09EB1CABULL, 0xBBFB4C5135EA693EULL, 
            0xAB1A48ABE33ACDDBULL, 0xEFD14BF1BEBB1D0DULL, 0x8CD452C54F346D8CULL, 0x75BF96D46287F3F0ULL, 
            0x5B977E59F0203F34ULL, 0xAEB9C0525ECBA0FFULL, 0xC4C0D192848484A1ULL, 0x2F19B51FC8EBFDFEULL, 
            0x4BB9500C27D1B7A0ULL, 0xF0AA060A00968391ULL, 0x80B9E39FB1603864ULL, 0xB8FB6FD485590C81ULL, 
            0x4E635CE8798BC08AULL, 0xE8C1C529B164B6C6ULL, 0xADFCABEF28321F30ULL, 0xB3F6286E8B28C526ULL, 
            0xF84EC457686F3553ULL, 0x474FB376A0E7AF0AULL, 0x5770D225275F496FULL, 0x6CDCCB816676A6B8ULL
        },
        {
            0x0BF1684D2A32C3F1ULL, 0x5F62828F831F07C0ULL, 0xB54F18A70F1C1CCEULL, 0x1536CE6AEE384D6EULL, 
            0xDF36604E2C80C51CULL, 0xE729AE6E17553867ULL, 0x956F4A43F0E601B3ULL, 0xB2BD7A553267A199ULL, 
            0x71A52633BF294A21ULL, 0x3823DC90E6DBBEDDULL, 0x54F629FDB56DED41ULL, 0x38B06FB386E694BDULL, 
            0xF7610A25C85C1AAAULL, 0x5B1B997CDB88367DULL, 0xBBFDA33770D9FB05ULL, 0x0EB1DE776BCAD8AAULL, 
            0x6B6C1E16F3E955BAULL, 0x6D09D9F900B83DD9ULL, 0xC252C20F7F46BA83ULL, 0xC439612B1CF15578ULL, 
            0xEDA00C1864A7D86DULL, 0x4331B9270FFC51AFULL, 0xD032B3B07374526AULL, 0xBC892E27D9220FA6ULL, 
            0x033027B2ED4E815EULL, 0x76478ACCAE1D59DEULL, 0xCF3890728A7A06B3ULL, 0xF56BFE481B3A05A7ULL, 
            0x6FE19DA1B6780670ULL, 0x4BF83313B1D46222ULL, 0x5014E80772998E3FULL, 0xCE9F28755044F86FULL
        }
    },
    {
        {
            0xF78B505042F549C3ULL, 0xA799F8CA06B57677ULL, 0x7ADA3262F248EACCULL, 0x10441606E952AC89ULL, 
            0x49C1819F79518F7CULL, 0x009DE878D673DD39ULL, 0x605D45BE506B7397ULL, 0x2F1B67AB6132DABFULL, 
            0x18840BEC69CD1A87ULL, 0x50F8D2AF9519086FULL, 0xAAE8C5B83D11F5A9ULL, 0xB234FA580B46AA77ULL, 
            0xEA4F442EEA51CDF0ULL, 0xA6EA75C354865BDCULL, 0xB40647A56E0471ADULL, 0x068AB38D2264A280ULL, 
            0x558F124A13714AD1ULL, 0x4477E1D9ED5CEEBFULL, 0x27A7702CF6E34DCFULL, 0x28807E8B8FB008A0ULL, 
            0x9E88F77E660A2A53ULL, 0x2188C249CC219FE2ULL, 0x4DAE7CE0760D22F8ULL, 0xE51C5A9AF738EC43ULL, 
            0x1A9C9E5756B347E7ULL, 0x455160D06D957DACULL, 0xC7719746BEFAACB4ULL, 0xC7D12B6714945FB8ULL, 
            0x350A2C843456B8CCULL, 0x90189DFC19A11829ULL, 0x2E56939FC86D4820ULL, 0x14BDFB748FCC03D6ULL
        },
        {
            0x96202EEFC0FF0E65ULL, 0x6E80476A69C6F9C9ULL, 0x1ADD0E2CFF003B4AULL, 0x36BD2CF60DD0DBA5ULL, 
            0x0FB24314820026CCULL, 0xCBBA0E3B15EA5CE2ULL, 0xA00CF8CEB7AEFF71ULL, 0x1EBB937742A3B267ULL, 
            0x1D06158FABE45573ULL, 0xA7DF751C6E869C80ULL, 0xF81A583AC42CCAC2ULL, 0x83A2E4FE784B2565ULL, 
            0xC8C2D7E8F4993C81ULL, 0xC3FD2EF864662485ULL, 0x13040E4563AB6FD3ULL, 0x644ED0C4B2293BC4ULL, 
            0xDF4A71CD3A29DE7CULL, 0xF2B6BF5DC2BC2C68ULL, 0x8D1FBF0A784E2C1AULL, 0x20280C572B76974CULL, 
            0xD2A2DF061E3FF4A0ULL, 0x9268B3D7228230E5ULL, 0xF899927433D6B899ULL, 0x57DB80CE878E686CULL, 
            0xAC098F31971C552FULL, 0x1EB0583A053AE5D2ULL, 0x794B5CED68555AFFULL, 0x0971B5F9152757EEULL, 
            0x86B91808113C3788ULL, 0xE9DF745440547592ULL, 0x2748C5F4649A950DULL, 0xEC74CD8DF9532D93ULL
        },
        {
            0x55ADDEF40C362499ULL, 0x1BAB0CE8E17B45B2ULL, 0xFDBCD5142F979F71ULL, 0x8BB04F4A61EC5AC0ULL, 
            0xBB248D791ED0912AULL, 0xB8E4F77BE196906EULL, 0xF95F32E177B44456ULL, 0xF983AC4238C0AC7BULL, 
            0xC3AEB2DF7533704BULL, 0x4C31B2E6960837BCULL, 0x3CCD3D2D4F421271ULL, 0xFA965A0F543DD5E0ULL, 
            0x313A220A22CDCF4FULL, 0x7581117468AC3DCCULL, 0x1BABB259309325BCULL, 0x0722F2995ABF95A5ULL, 
            0xB587C99AE3C98991ULL, 0xB5C215F7E60C2668ULL, 0x3965C5E9AFD93BC8ULL, 0x95DA8817AE8F43FAULL, 
            0x11AC7216F82A060AULL, 0x368DE122BA467E24ULL, 0x709D422166ACFD29ULL, 0x003507E255925B5FULL, 
            0x9CD662104A584E6FULL, 0xC7D5E41C8BCCEEF2ULL, 0x0344AA7F5F66040FULL, 0xBDDD244CBB65C210ULL, 
            0x97F101177B87AC02ULL, 0xA49597CEA31F9B32ULL, 0xA788DB8881AF7D2DULL, 0xE39EE708924A56B9ULL
        },
        {
            0x1F71A18BA1A46A11ULL, 0x4DC9287755EEDD2DULL, 0xC6DE6634BC145B53ULL, 0xC978DDEC3FDBD1F9ULL, 
            0x7AA9C2CD5C1D90ACULL, 0x9A02CAC6A9AE5242ULL, 0xEE2A25F3EE20A459ULL, 0x94DEF0E7085A4C06ULL, 
            0xE9113761A3FD5E07ULL, 0xC7D88DD8309A69A3ULL, 0x211A23B45F4351E9ULL, 0x8B1A5B7AFAA9CF17ULL, 
            0xAE808C45D42DAA5CULL, 0x81016AFD4E79A7A4ULL, 0x0320ED81CC9978BBULL, 0xECED74C8A239C589ULL, 
            0x5449BCE2D901D2E2ULL, 0xE4C9D02327285B7DULL, 0x1C8059A883263D20ULL, 0x3FD9BD4773CE81B3ULL, 
            0xEBD060288B7ED51BULL, 0xCE22CFC13A80610BULL, 0xA22D526E6AACE4EBULL, 0x940A92C5242EB605ULL, 
            0x63F72B2FA9D09E3DULL, 0xEC0F9127E9BA4ECFULL, 0x7EA6474071E2FB0FULL, 0x0338C5CEDBE2C220ULL, 
            0x4FB2120BCCE74C13ULL, 0x2D2976C7E31E5040ULL, 0xB63757463D11F737ULL, 0xCFB93E0182D523E9ULL
        },
        {
            0x003C0D168025DD7FULL, 0x2D1FA6804791EBF7ULL, 0xC6808A6B8C9BE583ULL, 0xD6E9D984ECB89981ULL, 
            0x4E6C63D2537FB731ULL, 0x9355BC13BB3A6EDFULL, 0x4451A33B0B0E26C2ULL, 0x276482406B2C05F0ULL, 
            0x624D20DE3894A2CAULL, 0xEF94D31ABE0FABC9ULL, 0x0DCF4049C21A1A31ULL, 0x7770A9C312861BE8ULL, 
            0x85FDBAAD8B246E31ULL, 0x65CCFAB68C37A156ULL, 0x5AA5CF47E9671C6FULL, 0xA135FAA5E0075678ULL, 
            0xDF00E21CFDC79F49ULL, 0xDE19C96A52817AF5ULL, 0x3B3C88F5A5A3AEF5ULL, 0x57FCDF1077660E19ULL, 
            0xC4C1316FD25FD339ULL, 0x36CA332F525D8EF1ULL, 0xE58DD75C559CBBFBULL, 0xEF09B2BC92EA2B48ULL, 
            0x2DD54D289F3B128EULL, 0x16ADF3002D1C5A93ULL, 0x0B8CED883D966C95ULL, 0x8E571CF672AF866FULL, 
            0xA7E9C2B4C33E3E6AULL, 0xEB5DD57E54FAF4C3ULL, 0x10FD0146A81F8189ULL, 0xE888A4128BD0F6CDULL
        },
        {
            0x34ABF267BDE76262ULL, 0x358BF262B7F602BAULL, 0x2D520FF242B5F49CULL, 0xDB49876E0F7BB616ULL, 
            0xB2C2A36F41C987DBULL, 0xB2D6753C291A7AB3ULL, 0xBB90395B0CF96F77ULL, 0x6D1A9A4054AB66B0ULL, 
            0xD045FD61A8471D39ULL, 0x7BBF451AF1BB6803ULL, 0xD29FA153DC4CEC32ULL, 0xE58745F4415DAD3FULL, 
            0x47A0DE86984E09E2ULL, 0xF0AEC31E365E0A26ULL, 0xD8BB9ED0F791EF06ULL, 0x074FF79B9EE1C912ULL, 
            0x34A5AC09C52267E8ULL, 0x7B8C0314BD788FCAULL, 0x128C68D3014E6F8CULL, 0x9A39E8BA89BE3D78ULL, 
            0x8753855DD668BD76ULL, 0xD2D518A324AC9B7AULL, 0xEE7309C1143F8E0BULL, 0x695DE075BFE58147ULL, 
            0x064E8FCFC91B657FULL, 0x63D667EFE5EAFB8CULL, 0x82624B2F6D6586EFULL, 0x822C07330F6B506FULL, 
            0xB868AFD615F38ACAULL, 0xB11D01AC4E0F3566ULL, 0xB900A789D6C995BAULL, 0xCB91513B7289CA40ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseGConstants = {
    0xABD15C1663C58E8EULL,
    0x9CA846EC805E7415ULL,
    0xCF60F16FD02651FFULL,
    0xABD15C1663C58E8EULL,
    0x9CA846EC805E7415ULL,
    0xCF60F16FD02651FFULL,
    0x5CC520C26EB996E8ULL,
    0xB754C08D61A0EEBFULL,
    0x42,
    0xD0,
    0xE9,
    0x7E,
    0xD8,
    0xB7,
    0xD4,
    0xD5
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseHSalts = {
    {
        {
            0x00A20108060C1BFFULL, 0x33E5ABC04BE8BFB3ULL, 0x9F107DF091C1D91CULL, 0xA35E7CCB87E91EDFULL, 
            0x4294F60EBBEF707AULL, 0x935D59D047221D01ULL, 0x17A2C78D5CE2568AULL, 0xC66E3B4A782BCFC4ULL, 
            0xA6DC1A6E8A2BD833ULL, 0x88F61C691C338B43ULL, 0xBC170E4832D1AA54ULL, 0xB44AEEE697755AB5ULL, 
            0x1A951DE6F84B26CCULL, 0x2124D4D2000853F6ULL, 0x47927C5BFD3BEE16ULL, 0x49869F267EFB1FB0ULL, 
            0x367177E8FFD6F606ULL, 0x3F36BE04A97ADAE2ULL, 0x6D4C454EBAF9B94EULL, 0x92E3F4A35DD46B03ULL, 
            0x2DD63D3F3756D6B0ULL, 0xCF55940C097B0B01ULL, 0xEB7F39DC4CF0C85CULL, 0xDEB53578D751CE64ULL, 
            0xE39E517EC4B03C0FULL, 0xFB3B5F77029DE3CCULL, 0xBE1CC1151954EE0AULL, 0xE3C2C9388597C102ULL, 
            0xC3C1EB6126DF6CB8ULL, 0x51AD4EF68C9161BCULL, 0x204354E991A8992CULL, 0xC929F6936AA3B2E8ULL
        },
        {
            0x2DF3DDA23CF3146EULL, 0x46AF7DA9908837FDULL, 0xCAA4509D83794582ULL, 0x8776106AE376D4EBULL, 
            0xC6913C80A9D08B6CULL, 0x8DA8E22F2A05E964ULL, 0x8340AA9C88CDC61BULL, 0xEBCF2FE3E254A618ULL, 
            0x81D4F24DE8A7B9ECULL, 0x02C4C47CA047420FULL, 0xF1D59389CF4F90FAULL, 0x154179A41691225FULL, 
            0x4D88E125D2CD3B92ULL, 0x3AE3C0EFE3C8C62DULL, 0xEDCD5A01549B6FB1ULL, 0x6835E7BC3A433D41ULL, 
            0x0DFC87CF4B94874BULL, 0xCDEE8356819E6367ULL, 0x25FA6821AA8DD798ULL, 0x7A88C9A68A6FAF44ULL, 
            0xDF2974AAD4BDC82AULL, 0x529F12A7490F4A1BULL, 0x89AFEC480C728595ULL, 0xDD0802D26DEF95F2ULL, 
            0x774FF511B422A804ULL, 0xBF510A14CFA12400ULL, 0x8014935D31E3D359ULL, 0x8FB99725855ADB55ULL, 
            0xAB3D02969C06AFB4ULL, 0x54B6AA85CA3DBDD6ULL, 0x05ECA0E34746B7DEULL, 0xF2DFCA320E32D5D0ULL
        },
        {
            0x356BE183D7128B88ULL, 0xE73DD7675895619BULL, 0xF8A599AC37F021B2ULL, 0x0446F396767A7B13ULL, 
            0xBE6F732AA7411C7CULL, 0x493CDCE2D76DDA74ULL, 0x384771EA188576AEULL, 0x726858C45849C314ULL, 
            0xC937529010EAC12AULL, 0x694471BB05A73EE4ULL, 0x2302951AE76A54DCULL, 0x55741EF8D4A67FE4ULL, 
            0x0093CDB983FE29B9ULL, 0xC47A07E23466B384ULL, 0x1D864CA645662892ULL, 0xF73EB60DE06BE1D0ULL, 
            0xD0323EDE729B7ED8ULL, 0x815BCAA648E54562ULL, 0xD031E7A3AF719D03ULL, 0x388FB03E6BAEB6A5ULL, 
            0xC241CACAC0A29E9AULL, 0x56121CE8326B47EDULL, 0x8CFB84B2C999E0ADULL, 0xAE3B5144AD2FB8AEULL, 
            0xD9EF6C161AFD6335ULL, 0x0021D8B97B3B27E6ULL, 0xD9E0153B3CB78746ULL, 0xF681C4CAE03C168EULL, 
            0x4CEC3A217BC7E922ULL, 0x69AF9CF33D5B1C4DULL, 0x2AEE92C3AE95B761ULL, 0xBA1D58651FBFE493ULL
        },
        {
            0xD80E7864DA2B35EFULL, 0x44C9D47EAF3A1EC1ULL, 0x4847183E1437D124ULL, 0xE02E656DA6B61434ULL, 
            0xFA0AE7D33E12662FULL, 0x5818FD9AE3256F5AULL, 0xB296AEAFD32C1F0EULL, 0x7E621AE046B77AC4ULL, 
            0xBFF9B5BB72C29606ULL, 0xAE8E3C0CDFBB2D2EULL, 0xA2CDA37E28693F9CULL, 0xFD8E63A5F8971F69ULL, 
            0xCD0DD9ECB2FECA13ULL, 0x8B304357369822E0ULL, 0x9342AEC86B043272ULL, 0x9493C50548B86061ULL, 
            0x2B76799B99B16A57ULL, 0x404D2B491AC1CDADULL, 0x09C75F54F59C7DFBULL, 0x10D54AAF94AA7CBAULL, 
            0x5D731227ADA6B5A2ULL, 0x0D6E9A24895D64EBULL, 0x897495020025608AULL, 0x18FE68B8BD275DB0ULL, 
            0xBFEC42D17BFB475CULL, 0x379E993D1CE9074EULL, 0xA5956B57763E2C71ULL, 0x1FE2EFC584A67D62ULL, 
            0xDD2D432CDEF1EC97ULL, 0xC51A462A89A027FEULL, 0xECFF8C9C9DB4949BULL, 0xC83ADF515A3ED69FULL
        },
        {
            0x07ACFA125BE7EF53ULL, 0x0CEFDFFB7DB199B5ULL, 0xBDD4EB6CFF38D520ULL, 0x29622D56F6760E4FULL, 
            0xE21FCD5CB80E8D26ULL, 0xA786B1054BDDA391ULL, 0xD84665CD1D293AD6ULL, 0xE8DF5D1C540D9AEDULL, 
            0x24BE97CC3914C747ULL, 0x3F421ADAE4F641CFULL, 0x327E7CE8A1758CCAULL, 0x0802E68E595DD35BULL, 
            0xA707C423875FC160ULL, 0xEF199355EFE017EDULL, 0xAEA88861C3B48CF5ULL, 0x965FAB8C7B7CCB31ULL, 
            0x3708AE7ED8745E95ULL, 0xBF8E1A51F0599089ULL, 0x1D6DFBA740E56BB7ULL, 0x5A54D40428E31014ULL, 
            0x9176749FAE3FC793ULL, 0x7527F2A21B076382ULL, 0xF26C3012CFEED8A6ULL, 0xC4CC5177224DF904ULL, 
            0x63DB9C5C7385EFFEULL, 0x06BCB1F6EEEB01A8ULL, 0xD526DBFB3E574C22ULL, 0x74F7B1AF91A7B464ULL, 
            0x6413787ED70E8E50ULL, 0x363F34CE7C5AA0BCULL, 0x4C976EC438FA5862ULL, 0x51BFE91E0EF5B710ULL
        },
        {
            0x9D366F2DCD82E86EULL, 0xFA7524BA22121CE8ULL, 0x02A42CFFF2A62F43ULL, 0x43DF21948323C926ULL, 
            0x2BD5C2DF46E5D829ULL, 0x83C46B9335344598ULL, 0xF4BD6C3EE4A7E1A1ULL, 0x01072B42AEBB9B3FULL, 
            0x513269B580B6A18EULL, 0x15FDCBDCB2512DE5ULL, 0xF241FC1195BA4AFBULL, 0xB3F0C7597EC87845ULL, 
            0x7CD27A98CBE2BA7FULL, 0xD3E17CAD2A7BF0ADULL, 0xDCB1D96BB7589D77ULL, 0x27D530856E6F7BBAULL, 
            0x89D14398E2D9240EULL, 0x7B3125F5943CD47EULL, 0xA85BCA9EA5677121ULL, 0xF9E0B3822C689939ULL, 
            0xE3446527D09E7BCAULL, 0x3F9BAB7A901B2F0DULL, 0x34A925F85F4C000CULL, 0x44BDDE2A1B4368C6ULL, 
            0x00697C9BFE4E0A7AULL, 0x60283416CC387737ULL, 0x996116882246C3BEULL, 0x29A0B67604C792C1ULL, 
            0x22EB116A3F6610B3ULL, 0xC7965D28D2DF9000ULL, 0x2BB3E6C806B7DE42ULL, 0xB8E18BC65790182EULL
        }
    },
    {
        {
            0xC6CA0C802334A43CULL, 0xC4AC3FFCD047A18BULL, 0xF29CB2F53136AEF3ULL, 0xAEF2596199103B73ULL, 
            0x80057D5D07BD1B67ULL, 0xCF5722A597B4F90DULL, 0xB11F0E629E2803EBULL, 0x44041903C049A892ULL, 
            0xF521D734CC25AE1FULL, 0xEB65042BED8B6774ULL, 0x29CC1C7F7EB12655ULL, 0xE292B3BDC6A4D042ULL, 
            0x930C72899B75C76DULL, 0xAA1492D986CBF778ULL, 0xAF360671D3E00A8CULL, 0x01F0FD0CD4A4F335ULL, 
            0xBB7A55CF04EF722BULL, 0x38BC46F9F85FCB80ULL, 0x7871171D82FCD1B9ULL, 0x30F87347EC47C7A2ULL, 
            0x5F7DD9FB80D64A9EULL, 0xC9B46E472C8D87D9ULL, 0x1A9BF99DDBC1F2F4ULL, 0x9452FB50CD8F745CULL, 
            0x6322941167F5619EULL, 0x13E285C2CF4A4465ULL, 0x5B83134E046368A7ULL, 0xE5A168F813F74977ULL, 
            0xFB2E2C9078C96A70ULL, 0x7B197EABDFFD7446ULL, 0xE6DB481F07A0E897ULL, 0x9B6FC73AFFAF4F70ULL
        },
        {
            0xB9ACF6BA1A5C2FCAULL, 0xD3F3494E7C1AA2BDULL, 0x43A11B713B33A277ULL, 0x36379725091D8605ULL, 
            0xBBE3CBA55865B0DEULL, 0x6CD63936A31B7112ULL, 0xD169BBA6A4F2D821ULL, 0xC5EDD6F7A45F0A1BULL, 
            0x642A141A492D2D9EULL, 0xA0D30A0633EFF2C1ULL, 0x03A96FD14686CD0EULL, 0xEDC7010BCD906A24ULL, 
            0x369B51C210A032D3ULL, 0x4DDA7416CDE06378ULL, 0xBEA426399BD2C12CULL, 0x1D44FF846C06D42BULL, 
            0xA0D1FAEEB71D7E1AULL, 0x0CE7E348FF1C9A27ULL, 0xC74647521742EFE1ULL, 0x56173903D4D5EE5BULL, 
            0xC5F478CAA556CB15ULL, 0xF03CFEBFA10DA968ULL, 0x62DF7EB97297E504ULL, 0x662D83AD8D9ECC15ULL, 
            0x00ED3F6799DBC5E1ULL, 0x09F74CAD312CF44FULL, 0x4F55F7C49B7259B7ULL, 0xB783E73C177CCFA8ULL, 
            0x154880832424F5D5ULL, 0xF30A19FC366B3BBAULL, 0x9CA7EF2BDDBFDE26ULL, 0xEBB5F0EB9BEFD41AULL
        },
        {
            0x4F0DB4BB4195B3A5ULL, 0xD71DDA13AC976F15ULL, 0x06CAF654891F535DULL, 0x674B2B63311E7E3CULL, 
            0xBBE3DF1CF19E17A9ULL, 0x649D5A99264CCC8AULL, 0xB081D44A8139911BULL, 0x782967C337D2429AULL, 
            0x639307ABFD9B6859ULL, 0x55A925DF905F905AULL, 0x1485E4D332599D6CULL, 0x5F9162EC781E2A97ULL, 
            0xB6A20140571CFB9EULL, 0xE0ACEA6B75D3AC10ULL, 0x1FCA773B6743C1D6ULL, 0x11251BEE8C750443ULL, 
            0xE45229CD3D134E81ULL, 0x94C68A0FC30D4D2EULL, 0x45BE3ECAE6EA0E9DULL, 0x9CE13C5A8BE5B448ULL, 
            0x8984F2F29FD750CCULL, 0xF8F89BB320EF8A5CULL, 0xF12E0BA106B0F342ULL, 0x93631FF90FCC90A8ULL, 
            0xCFDA08C5352B96AFULL, 0x031A044680658411ULL, 0x62BA2A2FEF02542FULL, 0x7FBD48E04A27BDA0ULL, 
            0x09BE3D1DD65478BCULL, 0x672546BC220ABC1FULL, 0xBC28209EBD19BE7FULL, 0x95076543E9A2C143ULL
        },
        {
            0x912B6C77E2690256ULL, 0x143CDED9F86F59AAULL, 0xE4365EA8148ED336ULL, 0x9DF5F1D6353B24B1ULL, 
            0x1E034B40220C50B7ULL, 0xA2419852EBD8491DULL, 0xBC5FF7E87517B424ULL, 0x63A282EB75CEBA60ULL, 
            0x2E76AAE821C9E7E6ULL, 0xAC532F0E5A93DD61ULL, 0xCF479E5712A0F8DDULL, 0x30CA3C21C862ADC7ULL, 
            0xACCE2F08F37BF72EULL, 0xDBA3A39D140FB6ACULL, 0x002F0A7051CE7420ULL, 0xA8D62D07EBECCFCCULL, 
            0x4CEBF323B6947107ULL, 0x9C9DF06042965EB6ULL, 0x0DD3110D7AB2AD5AULL, 0xB8ACE6EBBF3905A2ULL, 
            0xAA6BEF0C07ED8EDBULL, 0x5D42EDD92B271EE6ULL, 0xA004CB972C092752ULL, 0x2E5157F604971FA8ULL, 
            0x73F8B5E17BB51324ULL, 0x3A422F524D6FE94FULL, 0x92ABA6FC1FC1408FULL, 0xDC698F3BD08FF1A4ULL, 
            0xFA98D0A30A128DB7ULL, 0x23DD02119D92D799ULL, 0x5EDCF564C043B1ABULL, 0x1C767869D12F6686ULL
        },
        {
            0x183A58C7EF28FF06ULL, 0xA301E6914ED904A0ULL, 0x569A2339BB92FF1CULL, 0xE6A304F78A13976EULL, 
            0x7D29ED60B4D92770ULL, 0xC0B22ACE3A026C11ULL, 0x16513F7FE0B191A8ULL, 0xEB9BD72F43D89955ULL, 
            0x0E5ADB97DC097212ULL, 0xA01F1A166E3B63C1ULL, 0xEE4CBDDDA2F04064ULL, 0x75408FC90498F104ULL, 
            0x71A250C3146B9411ULL, 0x9708E22DD86CDA0CULL, 0x74A780AAA06F62A1ULL, 0xCC13BA3EC0D664F6ULL, 
            0x229610C8E7D49C36ULL, 0x23CDB731AB1C4681ULL, 0x400F688ED6354EC5ULL, 0x15D477D80A47B552ULL, 
            0x150874E33C7207B2ULL, 0x4A37940DDBA55C4DULL, 0xF73698B445F37645ULL, 0xFF65DA0011975CEDULL, 
            0xF2F2BEB651977228ULL, 0xC601F5423937D389ULL, 0xE78096B48E2BB3D3ULL, 0x817C6B78953E25DDULL, 
            0xCE5801987E6C1BEDULL, 0xB29B8E62D03BA1D7ULL, 0x486964C16AA978F0ULL, 0x35D458AF159BB0C0ULL
        },
        {
            0xD47177996D9FC22BULL, 0xA8CFF38501A6F9AFULL, 0x217070C8D1CB1D8AULL, 0x3BCCA15626B6B680ULL, 
            0xCA714BAB0CAF146EULL, 0xC0722EE86830B2F4ULL, 0xEDA13F609967E71AULL, 0x138EC4749B19F85CULL, 
            0xB7595BB120299FD3ULL, 0xF52EA7130B097C7AULL, 0xDC6B4DB8F13FB018ULL, 0xF342F710045B00C0ULL, 
            0x6C35F7DC5C393449ULL, 0xCB8C5E1E80935085ULL, 0xF447C9A5041AAFBCULL, 0xE5D8A24FDD13E7E5ULL, 
            0x5BA5A8FF11158197ULL, 0x6A414BCC5B3149A2ULL, 0x0DB12F3FC51D3A8DULL, 0xA1A67AF60D2A2B2AULL, 
            0x1859001F1A369633ULL, 0x6431D637E1303653ULL, 0x9CBEDCAF3206BC3FULL, 0x86296F5FAED9A72FULL, 
            0x6972C40988E91BC4ULL, 0x140DC1367F035694ULL, 0x9B517AF2EB95159AULL, 0x0C7D60401EED6FE0ULL, 
            0xF68D9B57F37D915DULL, 0x0ACC26158B90DDD6ULL, 0x305596B7F8B71DF4ULL, 0x266C557BC5DD39F4ULL
        }
    },
    {
        {
            0x8943481C3D781C5AULL, 0x256C0EB62D7E4CC1ULL, 0x470A32517F0B2CE6ULL, 0x7C06F42341F7109EULL, 
            0xD6BC080E780087EDULL, 0x2090AA906494CCDDULL, 0x278F13FBD3C60A5FULL, 0xEEB80BBD911E9CE3ULL, 
            0x1A3EABE8E7B2CF55ULL, 0x7E72C3F3F0D7DEDDULL, 0xD340C4737FCAEC35ULL, 0xF7DF78027F825795ULL, 
            0x10638F9B1167316BULL, 0x47F93ED1C8D4A8D5ULL, 0x89267C36034C75B6ULL, 0x5182EC9EFA4CEBE7ULL, 
            0xE89D938D9A46B0B4ULL, 0x0494EBF927E6F486ULL, 0x7A14BD90889671DAULL, 0xAFCC2907D2EEC154ULL, 
            0x613BC8F7FAA702AEULL, 0xCBE0807D6CAD2BF4ULL, 0x064EB656DA6C4946ULL, 0x93F429D45524DE12ULL, 
            0xABCFB88C0B7D98ABULL, 0xBB755BA559557339ULL, 0x27585DC52E26CFBCULL, 0xA0997D96808B4981ULL, 
            0x98080AB0D08CE177ULL, 0x0CDB16CC47FF71A0ULL, 0x37A214030240D298ULL, 0xB07676C95F06E8EAULL
        },
        {
            0x4851D36F1942D12DULL, 0x70C8D67541C9A76FULL, 0x16E56716A4F07064ULL, 0x1994BFEA8EE00015ULL, 
            0x31CA60B1E696176BULL, 0x4FC82BBEEA937E03ULL, 0x4FC51C9AB8C275C5ULL, 0x56DC8142872F9BF6ULL, 
            0xD004FE943D5A8A1BULL, 0xAF2E2DC9BA373E9CULL, 0xBA8B11D50EAEBBC4ULL, 0xAD8A45341E756ED7ULL, 
            0xD858E68F0D7AD95EULL, 0x47E7420721BB7303ULL, 0xC822DDB5EE47261CULL, 0x8F3813AEAD5D7946ULL, 
            0x0C5D6C133A274D9DULL, 0x0C28AF227D64A029ULL, 0xF37560BF0AD78D42ULL, 0x22A127F6E9EA8C39ULL, 
            0x95BF228F1B37F1E0ULL, 0x977F2DF86856B091ULL, 0x4352CD5AE11C9EDEULL, 0x1E2CDA50E9DB06B3ULL, 
            0x82B629D3BA3A13CBULL, 0x49EC141927B284D0ULL, 0x223EB94C33A5B787ULL, 0x22DBF70051AD9AA5ULL, 
            0x3407611C0E2EF076ULL, 0x5581B7BBBED6A311ULL, 0xB01C2C07A58CA711ULL, 0xF6D2E4CFFC362492ULL
        },
        {
            0xC3F413295C6A7A8AULL, 0x039C8AC4A685B487ULL, 0xB508AF0EE9CB0C9EULL, 0xBB5921FC1F9B6C61ULL, 
            0xE85DADDA883D22F5ULL, 0xC088209C94629500ULL, 0x38A181B0AD74CBABULL, 0x9AE419BE2492779DULL, 
            0xF8111F91DECC07E2ULL, 0x519EA8271F4BB252ULL, 0x3ECA43ED8C665883ULL, 0x8A0F780FD31CBC10ULL, 
            0x28219C9F3DDFC736ULL, 0x30664C8B0BE648ADULL, 0x385698D18C3B7231ULL, 0x644EAEF0FF9CC9A9ULL, 
            0x5FB64BC53A220E11ULL, 0x79E6A7915C825C8AULL, 0xBD04DF94AA15F52FULL, 0xF78DD75676185BEBULL, 
            0x916468D22AE084CDULL, 0x3A36CFCE269E06F4ULL, 0xD73571B4CB6720F9ULL, 0x3EC6D13C3A7FBEBFULL, 
            0x6CB28D79AD19002AULL, 0x12F2E8467368018EULL, 0xAE155983A8C7157FULL, 0x33D7EC8545D38837ULL, 
            0x4AC5DD485F43AE86ULL, 0x273748F3AA04D2FFULL, 0x31E86CD661F16E09ULL, 0xDCB6D7E5F3702072ULL
        },
        {
            0x3ED2820BC46937CAULL, 0x76033114C4F981CAULL, 0x7F220989CC31785FULL, 0xE617DA23DF28B802ULL, 
            0x9D1485B73356E948ULL, 0xEEC128BC98F79E89ULL, 0x02CA1E367CFB88CCULL, 0x61089E2523D2333DULL, 
            0xA5CC68ABBF7C554EULL, 0x4BF0A08152988C39ULL, 0x7D1440E70BF804C8ULL, 0x2058E3569276A443ULL, 
            0xCB6AFE1D0BC48A37ULL, 0xC9F3B74E16829A54ULL, 0x607C69D4D3FF69DBULL, 0x40FD5E93FEAF4387ULL, 
            0x78A1AF11B1412928ULL, 0x9D222BCC1EEEE909ULL, 0xD0471542A3E382D3ULL, 0x9352795A4B1EDDE6ULL, 
            0x6BCF8A2FE7D6A70AULL, 0x610168EA2A80A51CULL, 0x9158582FC4B30377ULL, 0xCCD0B7948905ABE8ULL, 
            0x76F7D9DA7885E276ULL, 0xB8AE9D3713AD872EULL, 0x520DF9FDB10E1A62ULL, 0x0E3087AFDCBC7205ULL, 
            0x6878982D34098498ULL, 0x84CED987C226BB08ULL, 0x37AB30586146EEA9ULL, 0x6093514ED3D85C3BULL
        },
        {
            0x4E29C0ED03326B71ULL, 0x55F2CCEAD1B0859DULL, 0xBD93B3FAAC4A5C83ULL, 0x5186E2E0FDDF7C40ULL, 
            0xDE10E4C6CB341370ULL, 0x3907D6C59DBC9569ULL, 0xB656B252D971B60CULL, 0x015056F66C20D6A4ULL, 
            0x70B62D277C942E5EULL, 0x020D239D598058D9ULL, 0x0365C051344A2C71ULL, 0x046A60BB2084CF51ULL, 
            0x2D877BC7BCEE49AAULL, 0x99E30757A64BFE8BULL, 0x0E870D7D01EF8FD1ULL, 0xABF2C9E065070C28ULL, 
            0xC537D97068C66A4FULL, 0xF3E68CA3EE425954ULL, 0x1C618D517C86F7EFULL, 0x298FB7A8B463DE52ULL, 
            0x21F61C0C1046E2C7ULL, 0x3C21DEF5562EEDAAULL, 0xB49F601AAC0B44A8ULL, 0xC6DBC7DA290A3BEEULL, 
            0xB1C4CF1C95327513ULL, 0x71A1886631467E34ULL, 0x515DB5641D483FF0ULL, 0x768E4BD0F3285D9AULL, 
            0xFA454F2D8A4AB2D1ULL, 0x2F6E897BB4013809ULL, 0x810126FCE5825F15ULL, 0x6741121E291A712CULL
        },
        {
            0x413AFD150ACA279CULL, 0xFF861C24E9717F46ULL, 0xDA65E772214816FAULL, 0xC47EB796B585D8B0ULL, 
            0xD8E50505879D09F6ULL, 0x3D9AC824DD9B7998ULL, 0xBE31FA3635051ED4ULL, 0x8A66FEC1B3101DA4ULL, 
            0x78EBD92EBDD3149EULL, 0x60FAE380005999A7ULL, 0xC0FA445B53B772D4ULL, 0x842B511E85485F21ULL, 
            0x202C531F4C973756ULL, 0x44B4FC48E7AA1BC7ULL, 0x9391C2683C40627AULL, 0xEE4F1009A4671D83ULL, 
            0xB3EF7FEC264BF54CULL, 0x2F466B678D78D83CULL, 0xC2E686A8509F5A30ULL, 0xD706E0C54708900EULL, 
            0xED67AE835FCA2CB6ULL, 0x9E31A8BF9B161C73ULL, 0x400FC401F6D8409AULL, 0x539CAFC24212E5EAULL, 
            0x497A684C721DB783ULL, 0x69975393FFF40960ULL, 0x727485FB681FA5EEULL, 0x18CE61554F084D17ULL, 
            0x17352225C38385C3ULL, 0xC24C3500B9DD63C5ULL, 0x5F38388D012947B6ULL, 0x73387A52C9AA9E6DULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseHConstants = {
    0xC695917E5835726EULL,
    0xAD3AB8CD5C9961AFULL,
    0xE7B8DCE372BB5DD1ULL,
    0xC695917E5835726EULL,
    0xAD3AB8CD5C9961AFULL,
    0xE7B8DCE372BB5DD1ULL,
    0x5CDC786C48FEB50BULL,
    0x8C68E76C8D136867ULL,
    0xAB,
    0x1A,
    0x33,
    0xF0,
    0x0C,
    0xEC,
    0x1F,
    0x49
};

