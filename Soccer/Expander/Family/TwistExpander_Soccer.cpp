#include "TwistExpander_Soccer.hpp"
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

TwistExpander_Soccer::TwistExpander_Soccer()
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
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Soccer::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    [[maybe_unused]] std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    [[maybe_unused]] std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    [[maybe_unused]] std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xC0945BB251E94F0EULL; std::uint64_t aIngress = 0xB69E49256BFE8F92ULL; std::uint64_t aCarry = 0xCC569105B91414B0ULL;

    std::uint64_t aWandererA = 0xC6E40F0515CD0459ULL; std::uint64_t aWandererB = 0xC8E26DE9DE3C8194ULL; std::uint64_t aWandererC = 0xE521913B6037E73CULL; std::uint64_t aWandererD = 0x9C39BE9897ADC8A6ULL;
    std::uint64_t aWandererE = 0x9E52380CB034481EULL; std::uint64_t aWandererF = 0x86F36615E5DB28FDULL; std::uint64_t aWandererG = 0xDC4B37C0645B86DCULL; std::uint64_t aWandererH = 0xD7EC0E8BAD9DFCDEULL;
    std::uint64_t aWandererI = 0xBEF6553C05FC77B9ULL; std::uint64_t aWandererJ = 0xC3BEF564E4B702A1ULL; std::uint64_t aWandererK = 0xE8989253FA3444CEULL;

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
        aPrevious = 11081601240381266092U;
        aCarry = 10368957605204679289U;
        aWandererA = 10790193840613110273U;
        aWandererB = 18063102519385098124U;
        aWandererC = 14246843234793186373U;
        aWandererD = 10120569328728580658U;
        aWandererE = 17294326134466854661U;
        aWandererF = 11055646513474402694U;
        aWandererG = 16794506964978048856U;
        aWandererH = 15523114498844392670U;
        aWandererI = 15811906695177956965U;
        aWandererJ = 14815184638456403418U;
        aWandererK = 11727432903076346030U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_A(pWorkSpace,
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
    // read from: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_B(pWorkSpace,
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // temp storage: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_C(pWorkSpace,
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
    // KDF_A_D kdf_a_loop_d:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: earth_b, earth_c, earth_d, source, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_D(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
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
    // KDF_A_E kdf_a_loop_e:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: earth_a, earth_b, earth_c, earth_d, source, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: water_a, water_b, water_c, water_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Soccer::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x9D559C2A278E69DFULL; std::uint64_t aIngress = 0xB182CBFC05FA4D32ULL; std::uint64_t aCarry = 0xB55C379C953AB165ULL;

    std::uint64_t aWandererA = 0x97F43F392DADA14BULL; std::uint64_t aWandererB = 0xBA63C2F3991F3139ULL; std::uint64_t aWandererC = 0xA252D770F1CC174BULL; std::uint64_t aWandererD = 0xB9BB1087E4791346ULL;
    std::uint64_t aWandererE = 0xDBAE9124C5D0AD0AULL; std::uint64_t aWandererF = 0xE9F69510B1ABC6F2ULL; std::uint64_t aWandererG = 0xD2256CA1B29D2699ULL; std::uint64_t aWandererH = 0xD5541F269B3F972CULL;
    std::uint64_t aWandererI = 0xA9045EFE05566E90ULL; std::uint64_t aWandererJ = 0xCDA52806FC34C421ULL; std::uint64_t aWandererK = 0xAB6059A1025D1628ULL;

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
        aPrevious = 10260841776088068179U;
        aCarry = 11731784822080691400U;
        aWandererA = 14569955389731959102U;
        aWandererB = 11492955061769280589U;
        aWandererC = 12595307377180528987U;
        aWandererD = 11883602144669990988U;
        aWandererE = 14266561890381095511U;
        aWandererF = 13021411228608046623U;
        aWandererG = 15194159236986463847U;
        aWandererH = 11981508966648026830U;
        aWandererI = 15410779904846368258U;
        aWandererJ = 11731539285847275866U;
        aWandererK = 9752055537877649647U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: water_a, water_b, water_c, water_d
    // temp storage: wind_a, wind_b, wind_c, wind_d, fire_a, fire_b, fire_c, source
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_A(pWorkSpace,
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
    // temp storage: water_a, water_b, water_c, water_d, source, wind_a, wind_b, wind_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_B(pWorkSpace,
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
    // temp storage: expand_a, expand_b, expand_c, expand_d, earth_d, fire_d, water_d, source
    // ---------------------------------------------------
    // write to: fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_C(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
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
    // temp storage: water_a, water_b, water_c, water_d, fire_a, fire_b, fire_c, wind_c
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Soccer::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr)) { return; }
    std::uint8_t *aSource = pWorkSpace->mSource;
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    [[maybe_unused]] std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    [[maybe_unused]] std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    [[maybe_unused]] std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    [[maybe_unused]] std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    [[maybe_unused]] std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    [[maybe_unused]] std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    [[maybe_unused]] std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
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
    std::uint64_t aPrevious = 0x9F67C047A2D7712CULL;
    std::uint64_t aIngress = 0xEE292B73A9AB40A3ULL;
    std::uint64_t aCarry = 0x9E0946BD12A99055ULL;

    std::uint64_t aWandererA = 0xC116E4715107CDA3ULL;
    std::uint64_t aWandererB = 0xD2F41A54CE5D8CFBULL;
    std::uint64_t aWandererC = 0x8810741861E3CE2DULL;
    std::uint64_t aWandererD = 0x9E5EEDB07CDCFA51ULL;
    std::uint64_t aWandererE = 0x85BEFB7CFEB3321DULL;
    std::uint64_t aWandererF = 0x8448EDA9370C3B21ULL;
    std::uint64_t aWandererG = 0xE97A2F45DF7325B9ULL;
    std::uint64_t aWandererH = 0xFC34D9AE3634AB0EULL;
    std::uint64_t aWandererI = 0xE88F6275390C0C05ULL;
    std::uint64_t aWandererJ = 0xB088909BB17758FBULL;
    std::uint64_t aWandererK = 0xE649B65D9F876D01ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneA);
        TwistSnow::Sha256Counter(aSource, aSnowLaneB);
        TwistSnow::AES256Counter(aSource, aSnowLaneC);
        TwistSnow::Aria256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    // temp storage: water_a, water_b
    // ---------------------------------------------------
    // write to: water_a, water_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_A(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, earth_a, earth_b
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_B(pWorkSpace,
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
    // read from: work_c, work_d, earth_a, earth_b
    // temp storage: work_a, work_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: earth_c, earth_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_C(pWorkSpace,
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
    // GSeedRunSeed_D seed_loop_b:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: work_a, work_b, work_c, work_d, earth_a, earth_b, expand_a, expand_b
    // ---------------------------------------------------
    // write to: snow_a, snow_b, fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_D(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aFireLaneA, aFireLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aFireLaneC, aFireLaneD, // output lanes
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
    // GSeedRunSeed_E seed_loop_c:
    // ---------------------------------------------------
    // read from: fire_a, fire_b, fire_c, fire_d
    // temp storage: key_row_read_a, key_row_read_b, snow_a, snow_b, expand_a, expand_b, expand_c, expand_d, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: water_c, water_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_E(pWorkSpace,
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
    // GSeedRunSeed_F seed_loop_c:
    // ---------------------------------------------------
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: snow_a, snow_b, water_c, water_d, earth_a, earth_b, earth_c, earth_d, fire_a, fire_b, source, key_row_read_a
    // ---------------------------------------------------
    // write to: snow_c, snow_d, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_F(pWorkSpace,
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
    // GSeedRunSeed_G seed_loop_d:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: snow_c, snow_d, source, key_row_read_b, invest_a, invest_b, invest_c, invest_d, snow_a, snow_b, water_c, water_d
    // ---------------------------------------------------
    // write to: water_a, water_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_G(pWorkSpace,
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
    // GSeedRunSeed_H seed_loop_e:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_c, fire_d, source, key_row_read_a, snow_c, snow_d, expand_c, expand_d, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_H(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aInvestLaneE, aInvestLaneF, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aInvestLaneG, aInvestLaneH, // output lanes
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
    // GSeedRunSeed_I seed_loop_f:
    // ---------------------------------------------------
    // read from: invest_e, invest_f, invest_g, invest_h
    // temp storage: key_row_read_a, key_row_read_b, fire_a, fire_b, expand_a, expand_b, snow_a, snow_b, water_a, water_b, water_c, water_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_I(pWorkSpace,
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

        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: scrap_a, scrap_b, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::GROW_A(pWorkSpace,
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
    // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Soccer::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Soccer::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8A3993D477CA1A31ULL; std::uint64_t aIngress = 0xDB066CE4F15D08CAULL; std::uint64_t aCarry = 0xFC6659FE33EDEFFBULL;

    std::uint64_t aWandererA = 0xD978254E08DCC6E5ULL; std::uint64_t aWandererB = 0xD969ED1A34DCB507ULL; std::uint64_t aWandererC = 0xE16F34A5102645D7ULL; std::uint64_t aWandererD = 0xA9E562F33B9584BAULL;
    std::uint64_t aWandererE = 0xAAF501353807A7AEULL; std::uint64_t aWandererF = 0xCA2A548399C41F59ULL; std::uint64_t aWandererG = 0xC30425203DADC201ULL; std::uint64_t aWandererH = 0xBB33F6A6C4D8B48EULL;
    std::uint64_t aWandererI = 0xA744D9B64C42A3D8ULL; std::uint64_t aWandererJ = 0xD71EDBD256559B87ULL; std::uint64_t aWandererK = 0x846438D095874FCEULL;

    // [seed]
    {
        aPrevious = 15144022452362164742U;
        aCarry = 11749818090004025286U;
        aWandererA = 17034441002869515610U;
        aWandererB = 13109883294278948460U;
        aWandererC = 12564290517747661163U;
        aWandererD = 11638702383766443333U;
        aWandererE = 17552311712842214731U;
        aWandererF = 15229233405812259413U;
        aWandererG = 9734133388324370225U;
        aWandererH = 12693122703684990345U;
        aWandererI = 12726461317197288407U;
        aWandererJ = 14379005940095814359U;
        aWandererK = 17691231375868599595U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_A(pWorkSpace,
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
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: water_c, water_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_B(pWorkSpace,
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
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    // write to: water_a, water_b, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_C(pWorkSpace,
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
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: water_a, water_b, water_c, water_d
    // temp storage: wind_a, wind_b, wind_c, wind_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, invest_c, invest_d, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_D(pWorkSpace,
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
    // GTwistRunTwist_E twist_loop_e:
    // ---------------------------------------------------
    // read from: earth_a, earth_b, earth_c, earth_d
    // temp storage: invest_a, invest_b, invest_c, invest_d, water_a, water_b, water_c, water_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    // write to: invest_e, invest_f, invest_g, invest_h, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_E(pWorkSpace,
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
        // temp storage: scrap_a, scrap_b, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_a, scrap_b, expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_Soccer_Arx::GROW_A(pWorkSpace,
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
        // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        //
        TwistExpander_Soccer_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Soccer::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyA(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aScrapLaneA = pWorkSpace->mScrapLaneA;
    [[maybe_unused]] std::uint8_t *aScrapLaneB = pWorkSpace->mScrapLaneB;
    [[maybe_unused]] std::uint8_t *aScrapLaneC = pWorkSpace->mScrapLaneC;
    [[maybe_unused]] std::uint8_t *aScrapLaneD = pWorkSpace->mScrapLaneD;
    [[maybe_unused]] std::uint8_t *aMergeLaneA = pWorkSpace->mMergeLaneA;
    [[maybe_unused]] std::uint8_t *aMergeLaneB = pWorkSpace->mMergeLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneC = pWorkSpace->mMergeLaneC;
    [[maybe_unused]] std::uint8_t *aMergeLaneD = pWorkSpace->mMergeLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);

    // [grow key a]
    // GKeyFoldA grow_key_a_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldA expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 2, 1, 0 with offsets 1748U, 2828U, 6059U, 2068U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1748U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2068U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 3, 0, 3 with offsets 4289U, 6242U, 3093U, 2915U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4289U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6242U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3093U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2915U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 1, 3, 1 with offsets 772U, 6693U, 3217U, 1230U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 772U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6693U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3217U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1230U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 0, 2, 2 with offsets 2283U, 4656U, 2298U, 7889U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2283U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4656U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2298U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7889U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 0, 1, 2, 3 with offsets 1612U, 360U, 1393U, 335U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1612U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 360U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1393U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 335U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 0, 2, 1, 3 with offsets 2026U, 847U, 1920U, 443U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2026U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 847U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1920U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 1, 2, 0, 3 with offsets 1087U, 233U, 1720U, 1135U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1087U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 233U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1720U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1135U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 1, 3, 0, 2 with offsets 1549U, 1159U, 1190U, 1750U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1549U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1159U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1190U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1750U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 849U, 19U, 551U, 2009U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 849U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 19U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 551U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2009U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Soccer::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aScrapLaneA = pWorkSpace->mScrapLaneA;
    [[maybe_unused]] std::uint8_t *aScrapLaneB = pWorkSpace->mScrapLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneA = pWorkSpace->mMergeLaneA;
    [[maybe_unused]] std::uint8_t *aMergeLaneB = pWorkSpace->mMergeLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneC = pWorkSpace->mMergeLaneC;
    [[maybe_unused]] std::uint8_t *aMergeLaneD = pWorkSpace->mMergeLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);

    // [grow key b]
    // GKeyFoldB grow_key_b_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldB expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 0 with offsets 3102U, 5606U, 3504U, 5789U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3102U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5606U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3504U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 1 with offsets 5140U, 4249U, 6334U, 3507U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5140U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6334U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3507U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 3 with offsets 2302U, 73U, 5174U, 3127U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2302U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 73U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5174U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3127U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 2 with offsets 3381U, 5125U, 1129U, 6411U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3381U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5125U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1129U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6411U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 8077U, 7995U, 7680U, 5055U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 8077U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 7995U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 7680U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 5055U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 201U, 1295U, 695U, 1058U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 201U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1295U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 695U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1058U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 8U, 376U, 341U, 800U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 8U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 376U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 800U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1260U, 699U, 491U, 1727U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1260U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 699U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 491U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1727U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1650U, 909U, 88U, 129U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1650U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 909U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 88U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 1, 3, 0, 2 [0..<W_KEY]
        // offsets: 1051U, 1685U, 405U, 218U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1051U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1685U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 405U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseASalts = {
    {
        {
            0x441C5777B196D477ULL, 0xD36B0C12BA5A794BULL, 0x8627D9BE5BDD2222ULL, 0xED13D0B3AE2F6F3EULL, 
            0x222F99DE7D3C6190ULL, 0x259669E28DD23A93ULL, 0xCC3881AA63663FEFULL, 0xED0D45C627ECE26CULL, 
            0xA679061C65A58FCEULL, 0x271B3281DF645DA5ULL, 0x2E0026F279B85888ULL, 0xF37D80E600BAB18FULL, 
            0x2A50A6D03A715F47ULL, 0x47D246F2F8372C64ULL, 0x1E0D2769CBE96DB4ULL, 0xB81F2267F60C17C9ULL, 
            0xEAEF30FEF7D38FF2ULL, 0x1B67774CE7E9716CULL, 0xD7BDD3A092776C94ULL, 0x1B28E54680717751ULL, 
            0xC2A10CB67511005AULL, 0x37F4F4C1D2229EC6ULL, 0x3C3212F137043854ULL, 0x73312E0529084994ULL, 
            0x32FFE1A23A9206D7ULL, 0xCFD7482F5E0AB7E2ULL, 0x6C7C780B664ECACBULL, 0x88A1AB70C025E02DULL, 
            0xC013C8AC17A6E179ULL, 0x887440987A9109AFULL, 0x969AE3B51EEC92B3ULL, 0xE937CAAA7F70591DULL
        },
        {
            0xC800940D7472720EULL, 0xC8F9BB8A108856DFULL, 0x86A811739AA68C0FULL, 0x9CAB2ACEE1A2F574ULL, 
            0xDAF2A815B7EC08BBULL, 0x69E773386BC73C56ULL, 0x5019DA60151F4366ULL, 0xF0E0E1ACEDF41522ULL, 
            0xD8DE7D10778C24AFULL, 0xADD131C49AB42051ULL, 0x6F8ADFDA0B1EB933ULL, 0xDF2AA97BAB7AA429ULL, 
            0x171AFC93AE4829B8ULL, 0x459F0B7EB319386AULL, 0x021553791ECE7023ULL, 0xC10ECB86059AF7E3ULL, 
            0xA1D3D123546763B7ULL, 0x77A012D9F72A518AULL, 0x363445B9AB58A5B1ULL, 0x1410D1716833585AULL, 
            0x1688349EA8129689ULL, 0x1A49138601BEEEB2ULL, 0xA14B8EB70052D027ULL, 0xC43BC5BA5F9BAF3AULL, 
            0x03E0A731776E78DBULL, 0xCA57448898C17782ULL, 0x2267605F56E18F8EULL, 0xE00724A566567000ULL, 
            0x990E2D6D2803B94FULL, 0x73ADC00FC9711E3BULL, 0x5F51BBF52CF4E688ULL, 0x4BA0A7522D3A40A7ULL
        },
        {
            0x2455AE48C56E5503ULL, 0x1F6C9EB220822751ULL, 0x096B54156941E09BULL, 0x36E3D433BD6F812AULL, 
            0xDCE2609A9FD63927ULL, 0x8833C49CD4E03393ULL, 0xE23F7EDC3DF70839ULL, 0x4747BE46D68E9188ULL, 
            0x8E5BE23C4ECD3D0EULL, 0x68825AF00D8D76DCULL, 0x955E4FC5D5F2E151ULL, 0x19C57E0B6E93E669ULL, 
            0xEEC06B7F370AD695ULL, 0xB8F12CDE790CE48EULL, 0xCCBC000EB439B13DULL, 0xB62E5319FAE9246CULL, 
            0xE7DB9AD95837F2EFULL, 0xE5A11E983C1B879EULL, 0x56B60675F27960C4ULL, 0x61A4248BE91F146AULL, 
            0x9F22C20177C8F64EULL, 0xF3CD793AC6902D9FULL, 0x2A4F7D3AF3B3706AULL, 0xE742212BF79B2B14ULL, 
            0x59C057AC604FB22AULL, 0x852E84095634C5B2ULL, 0xA45172F2BD0BA4C2ULL, 0x614E5D82EA40BA02ULL, 
            0x269F9F0E8029D975ULL, 0x091208F535EB3417ULL, 0x2D906719F9824B35ULL, 0x9E85F99FC6E61C05ULL
        },
        {
            0x394B634C2E998671ULL, 0xF53E1E11C839159FULL, 0x226B2305259DFEFEULL, 0xDD064B27B6AC5581ULL, 
            0x2790E690328CEEECULL, 0x5F23DCDA300BE700ULL, 0x5E48FBAF9DD0372FULL, 0xF768CAAA0C8F53B3ULL, 
            0xEE0043DAAA6E042FULL, 0xBF4BB595F366705EULL, 0xC6A7BA06E829A859ULL, 0x45E13041B3CCAE59ULL, 
            0x0169FDC3EB8257E0ULL, 0xBA225BD000ED8765ULL, 0xFB881C3189264428ULL, 0x256F01F349F69D25ULL, 
            0x078DFFB117511EBCULL, 0x70CAF267271143E2ULL, 0xC7CAD1F6F6997465ULL, 0xCA00B1C14CBBBB2EULL, 
            0xFAC65C9D0519457BULL, 0x36EDA84B313D21E2ULL, 0x92CF8FA7FBF589B8ULL, 0xC44A22835D0C5823ULL, 
            0x8CEAE24F1A13E260ULL, 0x0E5B92D0704D36F5ULL, 0x9D8068148D3124F3ULL, 0x7B2E5A0ECF7EA9B5ULL, 
            0x06AC921D1E16CC8DULL, 0x8997F52CCCDF31E9ULL, 0x70B576E87A3D9E6AULL, 0xC303392396B98BC6ULL
        },
        {
            0xF76DDC363F3E765AULL, 0x06D63FAC210F1E72ULL, 0x10EA08A18CF059ACULL, 0x2B081767C3793816ULL, 
            0x83D67028F1A27892ULL, 0x29E5A641950C6A33ULL, 0x65F6E106E298B6A2ULL, 0x6FB94699F4E6F283ULL, 
            0x498936A065DF3E1EULL, 0xD22B48A4662818FBULL, 0xD8C42CD955DA3522ULL, 0x19A9D76A3BD8F3DCULL, 
            0xFB27467EAF0F5B94ULL, 0x280F0F756F797D80ULL, 0x012AF7393793C01AULL, 0xAA52F81664696EE2ULL, 
            0x1E9C96D1B91EE3EDULL, 0x8AA3101CD05DD61AULL, 0x46E11794F8F12DECULL, 0x4DA9CB6D322D21AAULL, 
            0x14B94DC5F064D74FULL, 0xA726215A0C328EDDULL, 0xC954AAAF3D244D11ULL, 0x71E65DCFAA999F38ULL, 
            0x63EBFEED20E42B20ULL, 0x55AACC272F13E715ULL, 0xFF61F8EC8E41218BULL, 0xD842804F66FAE4E4ULL, 
            0x24284364A5C32522ULL, 0x3BB89DD0F05EEECBULL, 0x97D8B5FBBEB16E71ULL, 0x6CA5E2BD68CDFFDCULL
        },
        {
            0x93EB879CC462CCBFULL, 0xD3E95CE1DFD61C22ULL, 0xC2CDA93E8FCB9085ULL, 0x5860D0817A2330B3ULL, 
            0x9DA253B0CDAB4067ULL, 0x2BCF637A7489AE19ULL, 0xEC3B44B0D4D510ABULL, 0xF58B011B8B5254D2ULL, 
            0xE637AB2BECBA9B42ULL, 0x8EADF42AE432CB38ULL, 0x0687FEC468C9D112ULL, 0x7C78385D740BCEC0ULL, 
            0x5DC539FA1F957A52ULL, 0x4C43507C3AC385BAULL, 0xCBC6474A34AB252BULL, 0xF2F1516C6C89E3CAULL, 
            0xEAC2022BF29AB23BULL, 0x2ED923F60EF486AAULL, 0x5363A2012BD75DF1ULL, 0xAF6F615FA23343D2ULL, 
            0x3C913D82AFF91F88ULL, 0x95C8FF30ECB25094ULL, 0xF25D55B7FF334079ULL, 0x5BCD50A06C2D6101ULL, 
            0x6860C9A238FA817DULL, 0xD9261C38F9F82078ULL, 0xFA90166B40A5BEE6ULL, 0xC30C8B107769585BULL, 
            0x10F750A89B5B155FULL, 0x2170FE845DFEA415ULL, 0x086C164B9F20509FULL, 0xA8E5ED4713AA5B68ULL
        }
    },
    {
        {
            0x877AD6A318450AE6ULL, 0x117A1118CE34F774ULL, 0x0E4342665566BE9EULL, 0xE50FABA8822F72A6ULL, 
            0x631B8B54D21B207EULL, 0xB17412232740288EULL, 0x4274D43305AE581BULL, 0x351B317ED444D427ULL, 
            0x416EB576B9C8C342ULL, 0xD072B739B5903F42ULL, 0x0A62447E9E9E18CDULL, 0x8BD6E03C90B7D4F4ULL, 
            0x515B9554782C37CCULL, 0x45E1FF8C9857DE19ULL, 0x0D9C2989CA4B8945ULL, 0x297F9A3058FF4556ULL, 
            0xA6B38BB625BD2EC7ULL, 0xCBDF34BCB8B22DF9ULL, 0xDA287E0A4298C43EULL, 0x3EEE859D36A44083ULL, 
            0x5920C04A2757B22CULL, 0xC641E7425C1AB758ULL, 0x7B2B848C84948FFFULL, 0xF646015D5853FBF0ULL, 
            0xE5FABD26152CA304ULL, 0xE0AD6855940DADD2ULL, 0x321B8C1FE1E225D0ULL, 0xA24F3C3500AB4AB0ULL, 
            0x4F3768254D1F6719ULL, 0x67B42C437654B9F5ULL, 0xC9F95D3C52540CD9ULL, 0x3DAB7455160B5C17ULL
        },
        {
            0x11067B3C81CD9080ULL, 0xDB1CD28408C6D0B3ULL, 0xAA1AA540D3536D69ULL, 0xAD90705109F01D77ULL, 
            0x9843A2218E6F291DULL, 0xD46E6B190D26B583ULL, 0x7EFAE217A074AACDULL, 0xB35DD2C62FCD4D92ULL, 
            0x865D662DEAE9D56FULL, 0x7BC4DF1A7F8653C0ULL, 0x0C85F81C0DA8FD17ULL, 0xC4DC32B0803F0AD2ULL, 
            0xD2E3DD805B6B7ADDULL, 0x0030A32F8EEAE0C8ULL, 0x239247CC0824E897ULL, 0xA4F060AF59746353ULL, 
            0x9505B85953066B8EULL, 0x79B718D4E5D31865ULL, 0x63770E21F4F3E4C3ULL, 0x46B6E03DA0C238DAULL, 
            0x0044B22D6B05FC41ULL, 0x67B4643F0E67A4F5ULL, 0x4F377F66A43A8727ULL, 0xAF1662F0791810E7ULL, 
            0xE959D251ECA227C7ULL, 0x0E20E8F07EA0E6E4ULL, 0x6B0761576AE3E9DDULL, 0xEF370F15D8519BCFULL, 
            0x3D8057A4A1461614ULL, 0xCD56630BF7784E4CULL, 0x864DF7F6D6D7FA08ULL, 0x652FE8D0E02EA317ULL
        },
        {
            0x045A899FE861337DULL, 0x55A5B11B11BB4CACULL, 0x0ADDA8A726056D13ULL, 0xA3D437F0F767278CULL, 
            0xC32FF72DF50F8051ULL, 0x3A531AF5D7589692ULL, 0xF6431AE95DEF2585ULL, 0x2E3FE0922BF5541AULL, 
            0x95C997DAFD8EC138ULL, 0x4A1789736481559CULL, 0x29EC5396340A1BF2ULL, 0xC93196AF33411F8CULL, 
            0x3CBE2943F2361B47ULL, 0x15DFBAE2728EC2A0ULL, 0x60B0BDFCD9D70CAEULL, 0x504FF36DCC168C8FULL, 
            0xE4FCC8C60978C615ULL, 0x69B1111B42E7D225ULL, 0x32D0F0F476D7CC45ULL, 0x51D34D7EF908EC4AULL, 
            0x515070A63385707BULL, 0x6515BADFFC0D0FE7ULL, 0x386BCB1F6880A614ULL, 0xA77E7F6D3592A1A5ULL, 
            0x69713CD48CAB4473ULL, 0x00ED5A0DB406B250ULL, 0x0025843AC7CD2666ULL, 0x077BDEF9BAD661D1ULL, 
            0xEAB7F72A96777F0BULL, 0xA7C1AAFB5635CFB9ULL, 0xA28EFD6438119F6BULL, 0x53DE41F468569060ULL
        },
        {
            0xF7C036F32D65A48DULL, 0x453533827FABE101ULL, 0x3BDE60F842AE3B16ULL, 0x603652D0F1654B08ULL, 
            0x90D3BE5E20FBF249ULL, 0x1057299678D47A12ULL, 0x9D8AF71790241FE2ULL, 0xF5CBC08E8524CAECULL, 
            0xEF4D0FF9A63F2F97ULL, 0xACF0920C2570AFBEULL, 0x7B6C810736113EC8ULL, 0x6B0DB239566276B1ULL, 
            0x7BFDC20A338E44C6ULL, 0x45689154FC2D7B63ULL, 0xD2E572635751045FULL, 0x9CBBBC0503B92852ULL, 
            0x4B8342FB7D49C5CAULL, 0x487839BA4C51C836ULL, 0x225866B2F660B5DCULL, 0xD6487B848A4BFE46ULL, 
            0x5C6F02308849F8F6ULL, 0x61BBE839E31B11DFULL, 0x2F62913E5E0854CCULL, 0x0176C04526EB4B52ULL, 
            0x696A2AC73C00C3DCULL, 0x6864B5408453CCADULL, 0x823B92AE24CE94B3ULL, 0x60EFED3305C65967ULL, 
            0x5F5E51E290EB5A5CULL, 0x9CFA3CC4B328BAA9ULL, 0xDCAC4A00C5315720ULL, 0x51D8CC0CEE410386ULL
        },
        {
            0x1B58E91E37EC6B03ULL, 0xB58F0FC4575E3285ULL, 0x2DD83F8D2EE6C293ULL, 0x46B571761A00E635ULL, 
            0x9A4475103EE8E6DCULL, 0x6E8AA13CDBCFA440ULL, 0x1EBEFA89192D4BF3ULL, 0x6168623D8A50C342ULL, 
            0x8DA18EE2371350DEULL, 0xB4DF5D37CA47F70DULL, 0x26C1DD4CAF225874ULL, 0x4DD63F08158D2BDBULL, 
            0x948D3359D6959AA8ULL, 0xC1A93DB6BBF83400ULL, 0x7B8A238EB15CCE3DULL, 0x897576D6E9756DA3ULL, 
            0xDD7A3D53E591FF59ULL, 0x6044160BDE5755D3ULL, 0x88754E7866F90FB8ULL, 0x44A752F00DD7FF39ULL, 
            0xE9DBAE819D3BACCFULL, 0x01769054E884E99AULL, 0xCEB50BDEDFE5BB25ULL, 0xB3B93DF63C86DC29ULL, 
            0x1A899C9D4710BCB0ULL, 0xD70B80EC60980CE0ULL, 0xC2E6EE5C94CE7801ULL, 0xB4A034352FAB6B70ULL, 
            0xAD02B74B0FC886FAULL, 0x655F69029B0EC41EULL, 0x86081277EC96D53EULL, 0x1B59C19DAC9A3DEBULL
        },
        {
            0x2E37D9710A040F2DULL, 0x4F4211B833232AC5ULL, 0x529F373A15D599C9ULL, 0xC29023F3287B18A7ULL, 
            0x982DF1D3BC7127A8ULL, 0xB1439ECA009D2EA7ULL, 0x4407D6CFA5EE8E1DULL, 0x0ACC5F1B96A73BC7ULL, 
            0xA42DEA076B303F47ULL, 0x258F29DD914B5F0FULL, 0x5B952761D3C29460ULL, 0x450E976DE590188BULL, 
            0xFB677342DBD09CE5ULL, 0xF26E50C8BF8C5F7EULL, 0xFC92073816894043ULL, 0xCFDA4909C2DB3DACULL, 
            0x0ACEEEF331145D98ULL, 0x37104572ED8DBD47ULL, 0x894B1C76B37F6129ULL, 0x098378F3C08AA059ULL, 
            0x6F1557CCF611AA34ULL, 0xEDE7DEF762221D75ULL, 0x5B2A17A8BFC86803ULL, 0x767F1268BA60247FULL, 
            0xFE6FC83CEB55487FULL, 0xEA10A5B2B217A6A4ULL, 0xB40D9559D4C97BBAULL, 0x7194034039C8BCACULL, 
            0x94250AD01C1FCA41ULL, 0x0CC8B9ADC77B4BD3ULL, 0x11B2EE09FFA33676ULL, 0xC4D3C300C0BC6120ULL
        }
    },
    {
        {
            0xC7DDEA0D16F53E7BULL, 0x91B7F46F933760C7ULL, 0xBC0B5ED64F52ED6EULL, 0x995BB50EB64BEAE8ULL, 
            0x010F11E2F2A38FF2ULL, 0x7814BD9D3B7C12D7ULL, 0xB2FF708D84F0F4E4ULL, 0x726407F6CDF6548DULL, 
            0x7E041EC852AD5C88ULL, 0xC924B2232A50AAEFULL, 0xF47CA638FD8DD208ULL, 0x003A619DDF4DBB76ULL, 
            0x97342B19045C0B9BULL, 0x66145F60DC89E683ULL, 0xF8DC9DD062FD48BDULL, 0x209B0033B48E06BAULL, 
            0xEEE807F32F1E44C5ULL, 0xCAC154B44EAD5D33ULL, 0x93897A7FD20A7EBBULL, 0xD3EDF8B0BC60E942ULL, 
            0xCBB8518DA08DC11BULL, 0x3346E768CA518A19ULL, 0x5C876BA55DFD1D6BULL, 0x287F3C40CBAC21B7ULL, 
            0x7D6CD8B8D92D1ADAULL, 0xDDE03069E2941F64ULL, 0xEEB0FEB9A8365284ULL, 0x09B46789FC09B768ULL, 
            0x133334C349E47246ULL, 0xB8AD116764689DC2ULL, 0xF0577FB78784CDBCULL, 0xFE2E379A2AA47AD4ULL
        },
        {
            0x563C6249767F91FCULL, 0x31D88E08DCB5252FULL, 0xAF10453C5EE3C3D6ULL, 0x5767F56FD41A2B00ULL, 
            0xCC684FE08647FA37ULL, 0x31521BC2C9820725ULL, 0xBB1742E031D8E7B3ULL, 0x9D6C32843DEA94E7ULL, 
            0xB0C8F91E295A8392ULL, 0xD220BCACD7D0B19FULL, 0x8E99F280F562615AULL, 0x9EAEBB53F7A3E5F2ULL, 
            0x17E487747A46D60FULL, 0x7F130741B4C81554ULL, 0x1DA27C6D3A561A52ULL, 0xAABABDC39DF56842ULL, 
            0x0615274BD7FAD0D9ULL, 0x5514CF2F225C386FULL, 0x6C3939B992A2A6EDULL, 0x7FB5F27ECABA5AF2ULL, 
            0x6D2B46361191A75BULL, 0x6C24625C743956BFULL, 0xA55F4E594BEF6D30ULL, 0x4658FB08E51DD08BULL, 
            0x1CBFE9AF2D1D545FULL, 0xD2138E0DA0FB125CULL, 0x7386E8CEF5DEBEA1ULL, 0x8985F79C379676D4ULL, 
            0x32ED07AD0E2E666CULL, 0x93616A5F046E77EFULL, 0x2335F4161FCC7B53ULL, 0xF47323C34FDF704BULL
        },
        {
            0x1E565B59DEADA0A3ULL, 0x98E0FA237D608255ULL, 0xC33BE3F32C5A2193ULL, 0x493DE1700667D3C8ULL, 
            0x88132E08DD3E9101ULL, 0x7F1FA67FD42BBEBBULL, 0x566EC603ADDD70B5ULL, 0x852D924177BD76B5ULL, 
            0x25539E978C6F0004ULL, 0xC35EFE56777E6538ULL, 0x383DCCAD7F26D44EULL, 0x2EAE207790D64644ULL, 
            0xD96A8118926C0F7BULL, 0x48DD8DA00E31FA95ULL, 0xAC7D81ED3D8555D0ULL, 0x24E6FEF245F1B73FULL, 
            0xFF50C728CA654C7CULL, 0x20B36C03ADA44743ULL, 0x5F01A69317C4879EULL, 0xA5E14486DC707D48ULL, 
            0x3E780D2176BD936EULL, 0x3378B78FAAE582DFULL, 0x0688961E0A1A10E7ULL, 0x9615627DD658BAA1ULL, 
            0x8B78B78A2611E238ULL, 0xB0FD1205A7E2A618ULL, 0x97518DBFB45E6279ULL, 0xA9BF24C3A00C603BULL, 
            0x0667BB6872574465ULL, 0x9A0740C67506E131ULL, 0xCF80FD4BDE12B5A1ULL, 0xB1220E137F0DC630ULL
        },
        {
            0xE4411CE399FBC23EULL, 0x541C2CF36FE03531ULL, 0x44C00BE56C71B33CULL, 0xB342445DDD5CB107ULL, 
            0xBA2A2CE1ADD78FBBULL, 0x17D0E41CE525404BULL, 0x28E86257F138C060ULL, 0x58995C3B81D21449ULL, 
            0x725EB51874B82EB0ULL, 0x984403168B16F59FULL, 0x1CD9BDB263A93E09ULL, 0xA29F69528B170E68ULL, 
            0x62F5D28F4CA0E0A6ULL, 0xE8AC9F53B29CE3A1ULL, 0x739CBC71FF0EA939ULL, 0xF1AA69A0FAF272F7ULL, 
            0xD23E65D158E5D3ADULL, 0xC748CCDB211757F2ULL, 0x74800EB2DF27A1D8ULL, 0xFB833F733C4F8794ULL, 
            0x8DF6F502B0135558ULL, 0x689D94E240AB681DULL, 0x0C7F722A281DB05BULL, 0x61ABF74FFB0904DDULL, 
            0xF847D13CB5E4B7DCULL, 0x1FAD64E6AB5EE447ULL, 0x1F12A765C71E8484ULL, 0xCBDD6244A1DAE261ULL, 
            0x846277B9F2297834ULL, 0x4CBDE92F4FDC8414ULL, 0xDFF1D1DF86C39991ULL, 0xFE60FAA167F8FA4DULL
        },
        {
            0x21838659200DC53DULL, 0xDF41EBFEDE46B510ULL, 0xB0585183BF2C6B47ULL, 0xDD655BC5B044FBC8ULL, 
            0x987F8B9558144968ULL, 0xB69B2B76FD289868ULL, 0x360DD0104DA61B32ULL, 0x8FBAB814BC2EC212ULL, 
            0xFE6B640F9B677DA8ULL, 0xE34AECFC3E08D74FULL, 0xFC62602A7BBC0124ULL, 0x87DBBA5F2BF2E938ULL, 
            0xCAEA3D79A1168B9BULL, 0x994A32F6C80C16C7ULL, 0x4331CD7693C5BB70ULL, 0xEB82F1341D43C33AULL, 
            0x5B2F270A5876DE34ULL, 0x3C30F041BF03F12FULL, 0xEB10210D93417A44ULL, 0xEEAB3B966FDAB9FAULL, 
            0xB5A80E42D1D44358ULL, 0x5EEA86EAB3D22F80ULL, 0x62A5ED116E0CA721ULL, 0x365839968558EDA4ULL, 
            0x27791865F7CC2742ULL, 0xD3A0BE7E809E2227ULL, 0x2B36B8FFC08DE209ULL, 0xD89C1A5029CF459EULL, 
            0xCF70235EA60A62BFULL, 0x1F1592013E932CB1ULL, 0x2B5CB3E25C73CF14ULL, 0xEF7B0417832B6AE1ULL
        },
        {
            0x8543EB416AA26BB2ULL, 0x8C691F526243E1DDULL, 0x5E8D4630709DAC9BULL, 0x1186714E3C4B28F9ULL, 
            0xBFA6900590D6EC38ULL, 0xFBBF67EA9FCC26BAULL, 0x01C7955B10704541ULL, 0x2CA749F2D6DD36EFULL, 
            0xED6C4D31E30458B1ULL, 0x3913D470FD197F17ULL, 0x0BA21EE868374EF6ULL, 0xB533E0D59C2900C7ULL, 
            0xCF63640CF056545BULL, 0x56F3466E46375A09ULL, 0xA316856A3E54B89EULL, 0x4551CFBDE9428F2CULL, 
            0x6A2B79557000631BULL, 0xB97ED5F080A04BFDULL, 0xB3CA2789F19D6AECULL, 0x9E353F59B55DCA07ULL, 
            0xAE25D28696B553BFULL, 0xBF240146501235FAULL, 0xBD343C2705776B92ULL, 0xDA6633215B6775C8ULL, 
            0x70134EDC400F04ECULL, 0xFF29F38DECBD4954ULL, 0x1AEB37A92F27B838ULL, 0xBD519CA9AB3D7821ULL, 
            0xCF506150218DDC0CULL, 0x5903339DF34FC27CULL, 0xFCD7E7AC0530BF8CULL, 0xF07107EB1CB6DB65ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseAConstants = {
    0xD2345D57B7034F7CULL,
    0x9B5FA86613FD1F8EULL,
    0x5635BFA149FD0939ULL,
    0xD2345D57B7034F7CULL,
    0x9B5FA86613FD1F8EULL,
    0x5635BFA149FD0939ULL,
    0xE3FCDF682C4A7C7FULL,
    0x9DC15DB81F1D719DULL,
    0xB8,
    0xD9,
    0xBF,
    0xA6,
    0x64,
    0xBA,
    0x47,
    0x8C
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseBSalts = {
    {
        {
            0xE54D6EAE8FBA17ECULL, 0x4562218A00DAFC47ULL, 0x23C16E31FB82E01BULL, 0x085044189FB90EF2ULL, 
            0xEDCA807C3DB60975ULL, 0x90F4149E759A8FEDULL, 0xF3EF74DAB9CA298BULL, 0xEDA3C0894C30EFD0ULL, 
            0xF3F86E398D72AE11ULL, 0x1C29565038F47589ULL, 0x82BA1FAA8DD85027ULL, 0x8AEA74C764F56281ULL, 
            0xFBD2BF24BF7E114CULL, 0x2045C51D04C08939ULL, 0x30CC3218E15864DCULL, 0x195D340EFA45EA1FULL, 
            0x62C4C32BA0E94477ULL, 0xBD6FB6575F0F5553ULL, 0x72A3A209617A14F8ULL, 0x502AA078C437C65BULL, 
            0xEBA52CFC26A3DDBEULL, 0x25E5F6785B1F3E18ULL, 0x9CF61344EBEEFE59ULL, 0x0472C0CA44E7ADAFULL, 
            0x9ADA9B3449AA90E6ULL, 0x083ED5F19D0F6563ULL, 0x5B72694114305AE5ULL, 0xD02CF824C8457A9BULL, 
            0xCE74F083EB0FF17BULL, 0x0E3587C32F12D66CULL, 0xE324FBAC55F88DBDULL, 0x1DA108A758E03941ULL
        },
        {
            0xE31B0DF24BF51289ULL, 0xA73BB6B94816A812ULL, 0x5715886D2C0BDF62ULL, 0xCF46059334648462ULL, 
            0x91F6CB950D2CCA03ULL, 0xCDDDEDD69970DC76ULL, 0x0263584442EF5281ULL, 0xFE09E475295D6705ULL, 
            0xBA9014FAC40438A6ULL, 0x0C1C108F5E7B7918ULL, 0x4C067B78D0F578C0ULL, 0x80324229E45A2BC9ULL, 
            0x818F9E45E009181FULL, 0x6BFC040AC629CC23ULL, 0x3377B26792CD3E8AULL, 0xFD1B674FAD86FD13ULL, 
            0xA8C41F492833E21AULL, 0xADC6678C2FA945BDULL, 0xDBACEAC5D1F48B62ULL, 0x2BA1FC9DFB8CBB9CULL, 
            0x96F8A869F4DCCFD0ULL, 0x236A7BBB25589321ULL, 0x5267599B04A6E151ULL, 0x4F2EBD304A0204CEULL, 
            0x45E62CC47888B406ULL, 0x88C233F58916AC5DULL, 0x23F0A1DBD3FBCFD8ULL, 0x24A37E9FD0DA84F2ULL, 
            0xB5F78EF78DF3FD18ULL, 0xD872DD20A3A25D99ULL, 0xF1152846EB5A270AULL, 0x7A43E977305B58E7ULL
        },
        {
            0x4315AE4B9B520B71ULL, 0x290104639F60EB9EULL, 0x1FB462FCF12FEE22ULL, 0x95257C1F89CB971AULL, 
            0x4571896913164831ULL, 0x01095FAB4573FAFEULL, 0x5A353F3FD99F6347ULL, 0xBE32C16793F80C33ULL, 
            0xA46DFDF9980B35B0ULL, 0xE3D83BA44B877334ULL, 0x19B6693C06456373ULL, 0x554898FA7787BE02ULL, 
            0xD00B291D050E64AEULL, 0xB0CC35BFEB12659BULL, 0x3AC8890A2EDB28D6ULL, 0x7875605BCE2C3659ULL, 
            0xE57E51D7F0A90647ULL, 0xEF583E5CE9B343FAULL, 0xC5EE046CE67242E5ULL, 0x0F7D979D32E3A88AULL, 
            0x5ADCD29F88D0BF77ULL, 0x64A39A4DD9FF6D82ULL, 0x58F5B1B03F2C3169ULL, 0x82E52152BC0CBCADULL, 
            0xB584B46AB60F53BFULL, 0x979A9114202857D9ULL, 0xE14A045D6D335A4CULL, 0x30D9B15A522BDA8FULL, 
            0x27F21E317BEB0ACAULL, 0xD1E17BAD67820EE0ULL, 0xF9C007F061107425ULL, 0xD60DA383FB902617ULL
        },
        {
            0x3B92A6AC7DFC4B73ULL, 0x8237D3E94F39B93AULL, 0x7AF82A3E6965A16FULL, 0x6AAC26C941B4E7BEULL, 
            0x8DB5B711B6BCAE9CULL, 0xF69C72BCFB24C31BULL, 0xB3E3C2DFDEB95DBCULL, 0x06216EE323421C54ULL, 
            0x5D7C98918A6A2808ULL, 0x03CF0D86D202599BULL, 0xD404A016EDB6E12AULL, 0xB79E4449A4980BC0ULL, 
            0xACD8E265F11CDC93ULL, 0x0F10B62E432F8818ULL, 0x57C7D92A1F02AB2FULL, 0x278C71DDDD3E881BULL, 
            0x8A91894377AB3B7DULL, 0xF3F1767D290918D9ULL, 0x92C9C07B1703D902ULL, 0x63D10DC23D3EE19FULL, 
            0x55E1A45B3BB387C1ULL, 0xBE081F531FE79C27ULL, 0xF97D05974A7DF404ULL, 0x2D2206FB1D110A5AULL, 
            0xAF638518AB453C3AULL, 0xEF08762808659C02ULL, 0x6102670AB81BEFABULL, 0xBA44766534014C1FULL, 
            0xAFE6397D3C986245ULL, 0xE4D06AE4E6C7D3D9ULL, 0x6139E02D0633E50DULL, 0x6729826372B10637ULL
        },
        {
            0x2754F7FF3AABF8C3ULL, 0xAE7C274EB31941ADULL, 0x78F4D4FC5CF015F7ULL, 0x5EE12C311FECF7B8ULL, 
            0x8008946B354B8498ULL, 0x74DF00FF23338227ULL, 0x889DB9BE2417094AULL, 0xBAA147474AC9D510ULL, 
            0x01AA4F52E9A31D13ULL, 0xA66496B74FD077BDULL, 0xB6E40741D0D3C018ULL, 0xCC6EFFD4A6360A2CULL, 
            0xD3B79D4F20570CA7ULL, 0xAA218E52E3DF3158ULL, 0x1DF8C06025C0CB89ULL, 0x41AB18DFAB50B17FULL, 
            0xB56A2C267EC0FA72ULL, 0x9EF76477E39CAE93ULL, 0x738FB9A0A5656BDCULL, 0xDA60FDB4628FDBD4ULL, 
            0x85BC0CCD72DCD53CULL, 0xF00F55CCFDEF91FDULL, 0xEFCA6234DF9EE99EULL, 0xD73CFB6C0A9A6B24ULL, 
            0x27FCC6558ADBB394ULL, 0xAD63079EB7239887ULL, 0xCB2FA0D4F578F559ULL, 0x7A45591227AFC0E6ULL, 
            0xAA1547AAD263D856ULL, 0x8C9520698934763DULL, 0x6236492A64A3910CULL, 0x142E9AD14B0A8304ULL
        },
        {
            0x71FA56E45E6C480DULL, 0xFB33C3E8E35C86C5ULL, 0x185AE3B461C78F70ULL, 0xF17218B63DA98E6DULL, 
            0x609A5C191B627C03ULL, 0xEF2F1D97ED208405ULL, 0x51A0EAA36221243BULL, 0x7A25C352DCBADBF9ULL, 
            0x30FCBD4798DF96DDULL, 0x4293BF5278F01921ULL, 0xB234AC987795D119ULL, 0x45172CBD674AC969ULL, 
            0xF8FB51F2A5C3CC52ULL, 0x2CD20CE1C32F0DA3ULL, 0x84F9BB4A2CD0D436ULL, 0xEDEEE0DCBE8FE013ULL, 
            0xBB2E0F189FBE7B58ULL, 0x6ACB49D5F4FCEB0AULL, 0xA64843985307A860ULL, 0x1E251EB325AD607AULL, 
            0x06773385DBDE0B85ULL, 0xC7DD7E4609AD265DULL, 0x40DCCB3AFA49D419ULL, 0xDFE8F38D7D9612BEULL, 
            0xAFCCD66CF7B024E2ULL, 0xEBCDE38CCFF0F719ULL, 0x18E909B9A8D9C146ULL, 0x1A269E30EA51F025ULL, 
            0xF87DFB8209591370ULL, 0x4FEAFF4EA160C15EULL, 0x52E8851210BDA2F2ULL, 0xA9B6AAC86E63F62EULL
        }
    },
    {
        {
            0xEE25C04DBDA64366ULL, 0x053081B2E4937310ULL, 0x09226030E2706633ULL, 0xF384C3E7E61BF9CDULL, 
            0xAFAB73209F69F692ULL, 0xCEA50B35827B357FULL, 0xAD4972A3AA2D16DFULL, 0x936726E37CFF7376ULL, 
            0xC6EDD4B9C1637C39ULL, 0xD4E9A85EA0BD72CAULL, 0xDBBDBEDBDDE6B795ULL, 0x26CE0B88CBD287A1ULL, 
            0xECD307EE563E2930ULL, 0x68D30456D5816E50ULL, 0x8115EA9861E34F2EULL, 0x73A14E30226C20BAULL, 
            0x73ECDD6482E05FD9ULL, 0x378080F784EDC586ULL, 0x011CC5A025784817ULL, 0x2D0122B374E2E5C2ULL, 
            0x03198F2FBD22A8E6ULL, 0x93222E8CB96F0F75ULL, 0x569CBCCBCDBB128CULL, 0xD52D43C3AF6C591BULL, 
            0x238B5F0AAD6CDC94ULL, 0xD598811DC14FF08AULL, 0xD888D6025A829AEAULL, 0xE496C12E0301AF5CULL, 
            0x7B07B968177D4B4BULL, 0x63C0CDF3396B7B55ULL, 0x95E9EE0E44A1F7A4ULL, 0x045CF474EE911414ULL
        },
        {
            0x5358E061795869DAULL, 0x5E8A6DF3844D7C6EULL, 0x0C8B64D628506CF0ULL, 0x10A0EF180E81E24AULL, 
            0xA1E0375AEC033F47ULL, 0x70151A7526D9CA6EULL, 0x7D67433D34CADC28ULL, 0x61D665276D2455CAULL, 
            0xFC9924498786247EULL, 0xCC05DC69D07D2627ULL, 0xE620C8BD37F5FC13ULL, 0x5947492E809DB1FDULL, 
            0x18460820181ED500ULL, 0x31D15DCDE453BC9FULL, 0x73871F153E0DD261ULL, 0x8AE1A2CFA77E4BFEULL, 
            0x09C0746B9A27E191ULL, 0x20DA224C923E76E6ULL, 0x05F2EA4797D10578ULL, 0x4BF7AB597897AA82ULL, 
            0x776E2384F125A097ULL, 0xC75D8284EA9CB361ULL, 0xE4939D545EAB56A9ULL, 0xAE2B6815CB664276ULL, 
            0x06628EFEB665FBFEULL, 0xDCF09AD3B8F668E5ULL, 0xEA98931A0BD5EBB7ULL, 0x1BCB6FDE9319CB43ULL, 
            0xF49A5450406F3D06ULL, 0x0E3998E5305F02ACULL, 0xC653533F8B867B0FULL, 0x3E7D7FD5B4569567ULL
        },
        {
            0x8848DA1517EDC0F6ULL, 0x60075B231A373BEAULL, 0x48F8AA4B85F4BC1DULL, 0xCD080ADE5AC299F3ULL, 
            0x2CFE12C7B586B282ULL, 0x2B5AFFCEF17BA9CDULL, 0xE555F0D9DAC85DDCULL, 0x8E8A0D0D57C76A6EULL, 
            0x7034D40ADA742EE5ULL, 0xABC5C5BE24742375ULL, 0x4AD88B2ACC7698E6ULL, 0xEDD57DFB252F62DBULL, 
            0x9322745E2FF8C3DAULL, 0x28D7023650AFD295ULL, 0x72F5CAB91B54BD7DULL, 0xF91E30BE88385E11ULL, 
            0xF5B8B3F93BE0BB5CULL, 0x10B0573F331292C8ULL, 0x16B6135FE8180AC2ULL, 0x9F40904272C3FAEBULL, 
            0x3EEC445B1C7B1BA4ULL, 0xFC9D81A8F9362595ULL, 0x75641FE33C5A6986ULL, 0xD37FBF79FCB85CC8ULL, 
            0x7F81C7FDF50390D3ULL, 0x0F6407BE18A2DCD6ULL, 0xDE71C237CD72D175ULL, 0x879D7B02BB6AE0E7ULL, 
            0xA3DACEF1151BDE09ULL, 0x2F6FADC12FC91EA5ULL, 0x5FBAF5293A86C2D8ULL, 0x9B72EBB79003DADBULL
        },
        {
            0xE2357445146036FDULL, 0x595DE3F4367BCE30ULL, 0x53EAF5CABAD29025ULL, 0xBF44CCB81B50CBC4ULL, 
            0xD629E9812DA4585EULL, 0xADC845A5912626AFULL, 0xFDA1A80C076C85B0ULL, 0x956E9015504D50CAULL, 
            0xEFE326AA2073C9BEULL, 0x8492D0D9EE76763CULL, 0xABBB2E1507F983D7ULL, 0x9F86FFFE722A96E5ULL, 
            0x002FD43B1A4F8D0DULL, 0x78E1D01B419E8DBDULL, 0x4071A9B700AEA64AULL, 0xC0E150A23B4C8A1AULL, 
            0x88DBDCBE913410FAULL, 0x953F641C67AF7DEFULL, 0x891B0F798BD3C993ULL, 0x302E9BBC9FA478DBULL, 
            0x79D2350C70C3AEE8ULL, 0xBC8196E8C8B2043EULL, 0x597AEB0430BDDD80ULL, 0xB65A3FA78E68041DULL, 
            0xEAA86EC9F9219EABULL, 0x6ABAEFEEB3F9D13CULL, 0x0515DFF94C1984D2ULL, 0xA275EF0844FEA9B0ULL, 
            0xD4B47AA9EC56D006ULL, 0xABC205D13638AE56ULL, 0x2967BC67165816FCULL, 0xC96CEE1D6732AA00ULL
        },
        {
            0xDFBC0F167167B1AAULL, 0x8254FBC78D4FA05EULL, 0x44C60E5E1613FE31ULL, 0xA3563E19520FACC7ULL, 
            0xD21E1D3813CE930FULL, 0xE601A01A3B3E38A2ULL, 0x05A055174F8050D9ULL, 0x9B67FF106C30F457ULL, 
            0x2C93C0BA66FE78B0ULL, 0x7AC4D3EE8FD7D12DULL, 0xECA47C6EDEDF5417ULL, 0x4E14D35BABE79A66ULL, 
            0xA693CEE257F00A15ULL, 0x9DFF69EACAC3817EULL, 0x1D59D01973571515ULL, 0x154F4AC17BC999C7ULL, 
            0x786E399E72451D4BULL, 0x841EFE9434398E90ULL, 0x384BCD737C3453ADULL, 0x609C3D2B5C53E5D0ULL, 
            0x0B14F26533C40F31ULL, 0x84FDCEB1D088F9D8ULL, 0x4A55A712294AE1FCULL, 0xDEF8AB693DEC1178ULL, 
            0x40E1FA1AE2B196BDULL, 0x60A6296F2618A0D5ULL, 0xB1F3DECAA1038950ULL, 0x8F26EB00C17BBE47ULL, 
            0x771BE56A0C071705ULL, 0x8DB3084D12316837ULL, 0x02FFE147E17862A4ULL, 0xCAA5F48588D629F3ULL
        },
        {
            0xD76D09498351E79FULL, 0x580B86B0372EBCCDULL, 0xC1B5852FD9ECFF5DULL, 0xE76BAD15D305EE13ULL, 
            0xFA1186204EE4F28CULL, 0xC1C08FFFC9ACE554ULL, 0x9D6E76BD3BD2773CULL, 0x6DC0C5F504E7BE9AULL, 
            0x270B29EC2457BACDULL, 0x43435B8279ED94FCULL, 0x79CDA47C7B7575F5ULL, 0x94425A63D4D05D35ULL, 
            0x3538F661A6C68231ULL, 0x75666B7631A647EDULL, 0x09FB1B2946CA2C64ULL, 0xFE58FEAAB49126F1ULL, 
            0x10B2A37CBFBD5A41ULL, 0x2A94E59D9DB6C75FULL, 0xC522CB7EE52A5FD1ULL, 0x7A415CB66F8EA58CULL, 
            0x44A8BB332E38A585ULL, 0x17FB273D053C0DF1ULL, 0xEE3E2FEA81CAC186ULL, 0x847761E406B54E1FULL, 
            0x53B131EB064F25FDULL, 0x44121B7671A77BC4ULL, 0x669653DA96A01EBBULL, 0x142077B30E730143ULL, 
            0x087E091E8C4B4B70ULL, 0x253883381CAEAAACULL, 0xB7AC19E76B532343ULL, 0xBCCC8BFC5254744BULL
        }
    },
    {
        {
            0xB0917EE436A0A6FEULL, 0xDD745B7ECEE4C689ULL, 0x666BA0D35D2F8FBFULL, 0xD6DF1F973812B3BBULL, 
            0x2033C704B1369DD8ULL, 0xF2BE125AB833C34FULL, 0x904A2EFA026739F1ULL, 0x938A0D69B4C9B51FULL, 
            0x7A2B0D53F8613191ULL, 0x72C9CA1D7E26BB3FULL, 0xB09EF14138227FB7ULL, 0xBF9FBBA8BF03DED4ULL, 
            0x9AD58775320A18E0ULL, 0x5F674F9918B4F9AEULL, 0x227E89E07B110626ULL, 0x388068D1892CF477ULL, 
            0x19D16A0C4F6D4078ULL, 0x196D12AE659065F4ULL, 0xA8875E971A5B8E10ULL, 0xEC623670DD09076EULL, 
            0xF60E2CD92144F543ULL, 0x9FADD647604D50BCULL, 0x15055D04354F82A1ULL, 0x23A5B3E42C3EC55DULL, 
            0xAAD01F61E9E9AE68ULL, 0xDED75E5EB988024FULL, 0x32AA53E28798670BULL, 0xD37BE5A547C74143ULL, 
            0xABF1B886BC173E3EULL, 0x62E4441ABDB6DC6DULL, 0x9F5743665D1F94DEULL, 0xA2B905733F264CF7ULL
        },
        {
            0x50C4C1918CA76E93ULL, 0xAC89CC41134ABA61ULL, 0x2CC45B3D8E30D2F2ULL, 0xAEC42FF1789046C9ULL, 
            0x5A5FFA2BCB6F4D89ULL, 0x691A5E87ADD33609ULL, 0x07E32A6296D32542ULL, 0x2A8600BAC55FC692ULL, 
            0x37BFB4403EC05588ULL, 0x06009330244728C7ULL, 0xC9062CEAC2919535ULL, 0xB0E300B87F522377ULL, 
            0xE84755B33DE8E365ULL, 0xF82889CA8FF35D90ULL, 0xB85CFE4BB1371380ULL, 0xC869E73B638B7C83ULL, 
            0xD96220A2831D929FULL, 0x7802D3D1DB2B94A8ULL, 0x761CAC4E14CA4D88ULL, 0x74C1825D73A63551ULL, 
            0x44597D597DDA24F6ULL, 0x90545DA2F4E6D889ULL, 0xCDC7FDBDE2C1A1F8ULL, 0xE4524854CBCBDF56ULL, 
            0x209EA6A7C5473F9CULL, 0x8C734925ABFD7FF9ULL, 0x26B0FB0BDD1D1C46ULL, 0xB48E23D49E1DBAAEULL, 
            0xB3A6399A4DEDFF5CULL, 0xAE8D0CCFD4C1A50FULL, 0x827E63195C6420E5ULL, 0x016223054D35E97AULL
        },
        {
            0x77B286923A2B5CA1ULL, 0xF4932E852601480AULL, 0x6F51C18A55F3FEFDULL, 0xF45B79353B9E1C1CULL, 
            0x33E77A8BD41D4197ULL, 0xAECB562F8B7308B4ULL, 0x380452C04F7738A6ULL, 0x8FF53675C305E449ULL, 
            0x7BB6D8985E27BB8AULL, 0xCDAAF9030BFAA08EULL, 0x27B77B7C1BD467B6ULL, 0x50AF804028CE1639ULL, 
            0x43EE753EB13463C3ULL, 0x3BA07418087E5D1EULL, 0x0CB52239AAAA14C1ULL, 0x56FC217F99F2CF32ULL, 
            0x9837ACEAC28832DDULL, 0xB50BC5C1A72CE64FULL, 0x5703B7AD9A5FD723ULL, 0x007BB4F6B1F0522AULL, 
            0x1A718F6B3D96E3EEULL, 0x6821F416543D77ABULL, 0xA5CD57D1A6D481E4ULL, 0x438ECEC4056700B2ULL, 
            0xC9A26E929997E748ULL, 0x5620227426F2684FULL, 0x36BFAD1B7B20ABB4ULL, 0x589C7FBAD2D871A6ULL, 
            0xDA9AC9902B95C50DULL, 0xFB21474E6FF48BEEULL, 0xE0AB5824D3AE4DD8ULL, 0x0DF159C706D773A4ULL
        },
        {
            0xE52DC9DEE086247FULL, 0xAA72948289E880BFULL, 0x2F392FBC85EA2B69ULL, 0x658B0283E42E3B3DULL, 
            0x523F52E6A6575224ULL, 0x49E318A8FE57F5DFULL, 0x37652E63D8ECA5ABULL, 0xA70C2E7F9F5D7A23ULL, 
            0x16641501F6045F1BULL, 0xE7F56A37000D1E37ULL, 0x96B122DDDE9DDC97ULL, 0x8E57BD76E0479092ULL, 
            0x4357A36C4C7C9F6DULL, 0x8953DC0D1DE2EF65ULL, 0x0CB2A606B14F0A49ULL, 0xCE39EE14EC9F8693ULL, 
            0x34A7232A73BD0F74ULL, 0x4D74620C7C16C5BCULL, 0xA0CD5FE79DBB97D5ULL, 0xA5F944029C10C7EFULL, 
            0x8A1861193315D7B3ULL, 0x0C15E5BA0DA82E03ULL, 0xF293123E9FB35939ULL, 0x303EA48208FD3EF9ULL, 
            0x43DF39D536006AC1ULL, 0xEBC5270E1FB4C373ULL, 0x14A8F563D8EA75FEULL, 0xD6C6B5C14F218AA7ULL, 
            0x9B0B455F603D78A3ULL, 0x08A5ED00411EDBC3ULL, 0x672115D3B694B27EULL, 0x2CCE3D230E151E4BULL
        },
        {
            0xFF3FD08068723D44ULL, 0x708AC8B76CE6D908ULL, 0x751EC6AFC3A35E4BULL, 0x74044430959F2482ULL, 
            0x1ADFCF416277EBF2ULL, 0x75DBB74770DC1DD3ULL, 0x22F93AA9F053A6E7ULL, 0x515DB0D6FF55E3FAULL, 
            0x61BF35E9141D653FULL, 0xE4DD721D2F88C7BBULL, 0xEF0A59A6F3815E60ULL, 0x600EB2C4CE9A7730ULL, 
            0xBCC37DB8B6A7FCB2ULL, 0xDC456044A29FD350ULL, 0x28181FB8FD434846ULL, 0x16CBC52C3F42FB31ULL, 
            0x0BE6E003B4C29D20ULL, 0x5F55865518847979ULL, 0x04A733E4B30D8FC0ULL, 0xA4C73AAA02CD9176ULL, 
            0xFE336E24D8AF4C38ULL, 0xD3766D8D0CA67557ULL, 0x01390B19C17526F6ULL, 0xC2C3923E1128EC33ULL, 
            0x5E13D456A1AA4C4FULL, 0x1C615FE6DFCB291FULL, 0x80230820E18D075FULL, 0x91B0109379A84CFCULL, 
            0x0FA90F8FA2B730BDULL, 0xB41F749EE75B4FDDULL, 0x17D4F73E0B8787ECULL, 0xE88DD5506E684A35ULL
        },
        {
            0x5F6F53DA453E695CULL, 0x8EA2FAE5E8BB1FA5ULL, 0xA072A1A8A2FA8489ULL, 0xC0A29B890B3E1EE4ULL, 
            0x149887E8D956AC1AULL, 0x7282B91F36759A10ULL, 0x505735780C381DC8ULL, 0xA920E9E6E6819EDCULL, 
            0xB0489F79D5402644ULL, 0x7B77A3EE04EA1820ULL, 0x88FCCA6643DDA866ULL, 0xB53CFA452F024D48ULL, 
            0x6AB7E3067AD27EB1ULL, 0x4ACD4A9D9531F8C7ULL, 0xA5E9FB92EE81386CULL, 0x574BBC0F4B347166ULL, 
            0xE9301D96B88982B4ULL, 0x2EC8F3E1C5C41ACBULL, 0x1FD44C39271408FCULL, 0x5CA6BDBF37B00601ULL, 
            0x47F553437FD838C7ULL, 0x72809B831694522DULL, 0xFDF55371C6035684ULL, 0x2A00BD288F32620EULL, 
            0x3B33C3DB28C3470AULL, 0xEF3F2C683832843BULL, 0x1C937BC0D3ECCD12ULL, 0xE2D552FA9608F268ULL, 
            0x1FEE75BC3A4E1F9FULL, 0x249FD73FB8D96FD7ULL, 0x68B706A9AF32E578ULL, 0xE069380DC81D7846ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseBConstants = {
    0xFDE0BDE3E5161186ULL,
    0x558E1599EBFC44FEULL,
    0x9D32EA0B80E8F426ULL,
    0xFDE0BDE3E5161186ULL,
    0x558E1599EBFC44FEULL,
    0x9D32EA0B80E8F426ULL,
    0xF33024E21E8411A5ULL,
    0xB664060E86991144ULL,
    0x61,
    0x0B,
    0xC0,
    0x19,
    0x49,
    0x7C,
    0x1B,
    0xB5
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseCSalts = {
    {
        {
            0x00F5DB3FD878EA69ULL, 0x08FB77EDC47C2FDAULL, 0x6F6457477245EEDDULL, 0x3A54591CF91C2D47ULL, 
            0x133CB3ECAB4CFB8AULL, 0xEDF7A03BC32B3F0CULL, 0x31940B2A859A1402ULL, 0x83E1A5C012936AF6ULL, 
            0x653B9C772A9028B4ULL, 0xA3314ACF40155537ULL, 0x87E27B5D949BDCD1ULL, 0xCCE9390BB34B6829ULL, 
            0x610FACA64D3AC23CULL, 0x6736AB4488B340C1ULL, 0xDCCB33E074FCC478ULL, 0xE69C657344E199DDULL, 
            0x918D89BAB912264DULL, 0xDD03328B9C4903A4ULL, 0xE8C0E3A61A88447FULL, 0x6990D463A669B7DBULL, 
            0xF996DEDBB9580D15ULL, 0xDF8584B76B5B1F2BULL, 0xBA0A7A2A0E67A25BULL, 0x28C0EF1D59B68D85ULL, 
            0x2B009693A23BCE8EULL, 0xA204865313C7E030ULL, 0xC80478D9065158DDULL, 0x357DB7D236482F77ULL, 
            0x13FB5EFB86B2BFD2ULL, 0x941BFF515F182244ULL, 0x344EC173CB984F31ULL, 0x546A3232DDB27614ULL
        },
        {
            0xE5C3C650C9370BCDULL, 0x814BC6A07212DBD7ULL, 0x025FB57686FFC27CULL, 0x98F2ADB53EFBAC77ULL, 
            0xDCEB698421F65F2FULL, 0xD319206B9D4B6E6BULL, 0x0A7EE63B5943DDD8ULL, 0x0FD5F871AE078F4FULL, 
            0x77611EFB1F9873FBULL, 0x2CC0705281C65D41ULL, 0xC2A9A7158681F6A2ULL, 0xD9DC8B8C37632AC8ULL, 
            0xF815CE984D4163CBULL, 0xFA6A938CA0E7DC0CULL, 0x61A85B910F567027ULL, 0x83FF721A2C857727ULL, 
            0x389E6FB17BBFF2EEULL, 0x9AEBABF25CFC16EBULL, 0x93121C1D666E51ECULL, 0x8BA32485D0759919ULL, 
            0x24DD05EEA8ED4323ULL, 0xB01C60769C8A23C2ULL, 0xBA9BE5BE9ECF6C98ULL, 0xBAD83125113F6CAAULL, 
            0x8D451AB273F7BB76ULL, 0x1423C47DD2097A70ULL, 0x9B5793468B56610AULL, 0xD12FA682B9619C64ULL, 
            0x200EF0CDF8A163DEULL, 0xAAEBFC267A4B347FULL, 0x0E3193517D1419DBULL, 0x91CCF92A324E0746ULL
        },
        {
            0xAACE3F32F2465C33ULL, 0xBC04D70620E5FD04ULL, 0x74DAC62AE52D0615ULL, 0xC50D4C6D987267C1ULL, 
            0x384EFA96D943402FULL, 0x284A298C4CCFF699ULL, 0xAA1C932A2849D9B5ULL, 0xF9D1C096B54353F4ULL, 
            0x1D712F3287A27435ULL, 0x2DA7F9555DA8F0B2ULL, 0x5B76F09E687AD582ULL, 0x638300107C027F64ULL, 
            0xEE99C04E26AD4E00ULL, 0xAD4206AD6A00A04DULL, 0xCE2463A505F0E5F8ULL, 0x10FAD8EE96DCE3DEULL, 
            0xF512FC986D2BE74FULL, 0x6F7DFC9EADED1544ULL, 0xD9F09B47A5D8BCD5ULL, 0xB340EF57F42A544FULL, 
            0x49EA556EED348BBDULL, 0x33B2AC637F9AE4ACULL, 0x307F4745F5AA9C9EULL, 0x47989852587D3EE8ULL, 
            0xB4C9C5FD15262A74ULL, 0x831CE14B5390B253ULL, 0xCDD26F4BA3B4ABB8ULL, 0x807EA5D328CDC09EULL, 
            0x40B52EF9D55D0251ULL, 0x89191323D6C6DACCULL, 0x6CB1222DC10A3EFAULL, 0x8B8248825E6DCE26ULL
        },
        {
            0x6878D2DF73589311ULL, 0xA9BA368A4073496EULL, 0x91CC7EB396DD4096ULL, 0x5C11E549BB50AEC2ULL, 
            0xEEE22C75C9920E6CULL, 0xEB6878DB172493A0ULL, 0xC77B62EFC4938EA9ULL, 0x872C4E0931829EC8ULL, 
            0x1076C8EFD6A37163ULL, 0xB43EFB143974A4D0ULL, 0x7ED709848B7C6548ULL, 0x5061C72BD0B2F802ULL, 
            0x19280CBD8E4C138AULL, 0xCF08DFE8CA5F3D19ULL, 0x96AB81A9C1FF4617ULL, 0xB72327CA4B089776ULL, 
            0x2B87167BFD29C4CBULL, 0x1D17830109E74450ULL, 0x43AF71565C48DCBEULL, 0xFA9499599A5518A0ULL, 
            0x516B0009A450C5B2ULL, 0xB247D39A477E4E06ULL, 0xE26B4BEFCBB7507CULL, 0xE69A2BA5DA9E36BEULL, 
            0xD236138494979BCDULL, 0x997F949732D5676EULL, 0x17699BB03C208206ULL, 0xB977A763E6A564BEULL, 
            0x78BC21F1BB5ACFC4ULL, 0x618E5534CEFD475FULL, 0x1712BEF933A8A6EFULL, 0xDF0626DA61AD26E9ULL
        },
        {
            0xEBE41E248D869462ULL, 0x08BC2B6A41FFB41FULL, 0x61277B6AB37C5FC4ULL, 0xD2912C53314CDD2AULL, 
            0x92A20A748A679FA4ULL, 0xC55D5AF905937491ULL, 0x535FFB6854DBCDE1ULL, 0x6923F8017CAA015BULL, 
            0x9C1D199414F87642ULL, 0xBB25446AFA25130FULL, 0x9D02D4E758A93480ULL, 0x3AFB8CAF04299B61ULL, 
            0xCB21CCF0F1255FBBULL, 0xEB48232AF07E68BFULL, 0x82EC039BE98D465AULL, 0x875D79743BF7743DULL, 
            0x0D88AA6209EDDF81ULL, 0xD5AC88AD11B1D8C7ULL, 0x3973435CAE97F7D5ULL, 0xF0B9EE6C656CBE0BULL, 
            0x0328C2B8A63FE984ULL, 0xB7C1A010228D16B4ULL, 0x6C8809824043A778ULL, 0xBE8190DAD88514AAULL, 
            0x8BDDC3407512CB73ULL, 0xC35A11BC0C9D51F0ULL, 0x6F49409856C7B1C1ULL, 0x0EE695C83D75962CULL, 
            0xDD9AFE9FC02E707CULL, 0xE80A31FBCCAC7A1FULL, 0xA40A5B7D3813645AULL, 0x78D6D0A5E274057BULL
        },
        {
            0xD89519A615015AA1ULL, 0xA70E1D50F53ACEC6ULL, 0xB1EE851A0993E09DULL, 0xFC9346717414B6DEULL, 
            0xA10A296A6942C756ULL, 0x4A34389A8534D3A7ULL, 0xDF23129B8142DB4FULL, 0x0A3B752F603A6BC4ULL, 
            0xD3A9D4FCE8AFFCCCULL, 0x549D3699EC9E784DULL, 0x055CE7E0E7EE8B3BULL, 0x47D2DE06510C9ADCULL, 
            0x030B1302CCE61001ULL, 0x4186D64738FF3DABULL, 0x025DEFA88F96979AULL, 0x3CA3CFD04F191110ULL, 
            0x796E40B8F5CD8F13ULL, 0x063F614C6D66BBE7ULL, 0x2706C6A893B19ADAULL, 0xAFFE043017ECA986ULL, 
            0xF6842FD683E27D35ULL, 0xE1A1C8615D22C8A9ULL, 0xE37FBC06701528C2ULL, 0x69940CFABC080CC8ULL, 
            0xFE1439F2B33433BDULL, 0x16FED3B847D10913ULL, 0x5DC26A515CDC8400ULL, 0xEB573B72769FDA53ULL, 
            0x4ED03416066EF31AULL, 0x576FD9DDD1788FD4ULL, 0x7FEF521A834052A6ULL, 0x5BAE22613955834CULL
        }
    },
    {
        {
            0x85DE949EFAF8FCB4ULL, 0x3BDD3996CB2D945EULL, 0x1414711E267796B6ULL, 0x89113012E831599BULL, 
            0x1017B5234AA113CBULL, 0x6A9D16B4404FE989ULL, 0x82A2D36209EECD46ULL, 0xE99B2D5960DC1B73ULL, 
            0x610A2BC1F37C76C7ULL, 0x5B6E4E880E483255ULL, 0xD7E761C896DFBD68ULL, 0xD251B3E30BF5A4FCULL, 
            0x0A4072218DC80654ULL, 0x80880E4F43C11FDCULL, 0xBFE2D08C641935B5ULL, 0x7CA6E8C9B416AEFDULL, 
            0x5AC42AA852B12865ULL, 0xEEEE127D46EEE657ULL, 0x17BCA11ACE8DA1DEULL, 0x9E2B689A1554FCDCULL, 
            0x1E0A707641313F2BULL, 0xCF3A9EE4AAFD6B3AULL, 0x59334CB1EEA43723ULL, 0xB160518A3A81685BULL, 
            0x3FE3640385C8DFBEULL, 0x257A1AF10E15D38CULL, 0x918E11885B8B8B32ULL, 0xE0BE425DC17CB713ULL, 
            0x636C0AC27585ADE1ULL, 0x36F316FB85EEAA96ULL, 0x178573C3759FCE58ULL, 0x9B20D3116D4E5E99ULL
        },
        {
            0x1BCED2B1C1337FE1ULL, 0x27F6AE300E4115EFULL, 0xCF18A9D511F25FA3ULL, 0x45918DAB5FBD17CFULL, 
            0xD157E002D75ADB1EULL, 0xF9607FAE4A7C8FF9ULL, 0x65D1AE17945B38F1ULL, 0x247B4EC2912DA715ULL, 
            0x1A2EC5CABDEE4F47ULL, 0x9AA9F19A2FC7DA8AULL, 0x69AE9720C26C3165ULL, 0x405D6EFE29271549ULL, 
            0xE8926745BD33F537ULL, 0x108D902CFDE9C951ULL, 0xC1AF72630F3039B4ULL, 0x5229EA7C68518C17ULL, 
            0xA7AFC74B538E6BB6ULL, 0x64048D0E0CB02A45ULL, 0xD61FD08AA16C6A5FULL, 0xBADA98F82F6EA32BULL, 
            0x19E916D52D6370A6ULL, 0x9F4D45BE9C0B1BF4ULL, 0x79A9F8597EB4B9EFULL, 0x25F4E5AF5880B2AFULL, 
            0x733CE5BAF6D660F5ULL, 0x63C765C3D2493F5FULL, 0x564E316C29DA5185ULL, 0x5509404CA734DE5AULL, 
            0x080BE8DA57DDC3E2ULL, 0x329BD3B2016B3E72ULL, 0x96068D4179E4F5D0ULL, 0xF6AD4038010E4E37ULL
        },
        {
            0x49009D7D004B41CFULL, 0x3325BAC32C754491ULL, 0xA2D6F70CF88E7EECULL, 0x486889FFA8F0DFB7ULL, 
            0xD390D22DD65BF22EULL, 0x2C8333C0E6EF3F10ULL, 0xE8C67AFF2DA24066ULL, 0xBCD8AEB159DCE200ULL, 
            0x436A9A4C3C6C4CA4ULL, 0x3D74E58E3F889634ULL, 0x5A6A49F12DC66F3CULL, 0x21937F0B3BB10AF1ULL, 
            0x15A8C965D2CBDDDFULL, 0x7C7C8507A1FB5B07ULL, 0x2E40F4F5BE417A6BULL, 0x2D30982BA8C240ECULL, 
            0x10A21D3EE80AE3A2ULL, 0x5ACDC7306D196837ULL, 0xB061F3F30456049CULL, 0x4200C2F8A3014265ULL, 
            0x6B6121FC98C09CB1ULL, 0x24E0EA0CA96BA00CULL, 0x7FED3C00B1DBD15BULL, 0xC54048662EE7EA61ULL, 
            0x4F3F346693DCF1A5ULL, 0x9137BFB4358BE904ULL, 0xC4DBA04000999475ULL, 0x1F67F72F0CEF8449ULL, 
            0x28F69BEB9CB59674ULL, 0xDC2AE94F8595767FULL, 0xFF01E0466DD69567ULL, 0x1FBB75CCCBF393A3ULL
        },
        {
            0x33E9220359B57B85ULL, 0x5CD828221ECFD056ULL, 0xFDE15E945190661EULL, 0x1095959D436C1C09ULL, 
            0x54202BDB1F2862D5ULL, 0x32C28A04EEEB149BULL, 0xFE8E10AE75A89A28ULL, 0x18EC0B7DE37DFA32ULL, 
            0x713FD361211B05B5ULL, 0x1E72A0E71C3883A3ULL, 0xFDD88B7166B46DEBULL, 0x70C401CE96C8B30DULL, 
            0x526DD6899AAD254AULL, 0xD5C08BA4ADB65698ULL, 0xDB27E32DD0CE5F2DULL, 0xD9403A2CDFCB1E79ULL, 
            0xE978F6BB07821914ULL, 0x6C195C9C3D8D9B2EULL, 0x16477CA17AE9F92BULL, 0x88B6E65C93EAFCC2ULL, 
            0xCACAC41147D87ED2ULL, 0x30258BB6D8EBFEF4ULL, 0xA71FD77156631A3AULL, 0x3BC338CE2EED29DCULL, 
            0xB44D178591ED4983ULL, 0x58C063BC754AB377ULL, 0x24030867196DB00FULL, 0x0AC150F513EE7996ULL, 
            0x4EC67591CB618D48ULL, 0xF0BECBEE1176A751ULL, 0x7CACE35D87770A88ULL, 0xC6F7ECD8E401CAEBULL
        },
        {
            0xD1AF1CA78C6AEF87ULL, 0x7380B3B795F6751BULL, 0x8FE4F83812088AFAULL, 0xAF4CC40987A45980ULL, 
            0xAF3BF9FBA1C14CC8ULL, 0x3B0609CE5AAA0097ULL, 0xF60685747DF64974ULL, 0x8824E695065491A5ULL, 
            0x42D6C27C1CC6B12FULL, 0x5F4E22F8BE342398ULL, 0xCC0C09F2011FEC22ULL, 0xC5AF79461E1463E2ULL, 
            0xEE2EE9D5413E7B7CULL, 0xC300FFB1B39B1D6FULL, 0x52A5AF46C28D3147ULL, 0x2972057B5863808DULL, 
            0xC856D5C4D4AAE212ULL, 0xF34A9C5D2FB1EC8FULL, 0x55E25330D7EEDE89ULL, 0x4707C93D6FC18A2CULL, 
            0x2CCA19AA88A23C88ULL, 0x5ADE6859BD7F3B90ULL, 0xE1E554C1450A30B3ULL, 0xF7ACE08CDCF74581ULL, 
            0xD02CD9B47E2EF1C0ULL, 0x990838B0F80CFFE8ULL, 0xA6C173D6D1D451F9ULL, 0xEFC246213C3293F5ULL, 
            0x57F9615279AC1221ULL, 0x99A21DFB3CD180B6ULL, 0x54851AB4B38F16BAULL, 0x83331B6A4B584B8AULL
        },
        {
            0x1D335CCAC9A7A4A8ULL, 0xD7B87187756A24D2ULL, 0xDE96FAEE7515B1C9ULL, 0xEBA3ADF0021E8A09ULL, 
            0x490A9621BCAA417CULL, 0xB8B0B68CA22B44F3ULL, 0xEC8984E805DD91C9ULL, 0x86E7275C432B3284ULL, 
            0x44957EDB232AB309ULL, 0x18A92CF92CAE90BAULL, 0x9F35917E0B57969DULL, 0xA1B420CF11253CA6ULL, 
            0xE671B09BD953D6FDULL, 0x4CDCF91D7FF8844DULL, 0x4CEC9C0C84747C0AULL, 0x4021F90B679C0E51ULL, 
            0x4B242BBF037D36D5ULL, 0x28E467C0C75313CDULL, 0xD640E0F3842D987EULL, 0xE627EE9F2A018D9CULL, 
            0xCEAA0ECB7C346E96ULL, 0x6AD6EDA877FA88C7ULL, 0xF826B6CD91EE680AULL, 0x52ED99CF998588AEULL, 
            0xFA1F3ADAF6FC0633ULL, 0x28587A826DD4725CULL, 0x2FD5A6314FE2E5F6ULL, 0x8397E763E487259EULL, 
            0xDC7D220675F90F80ULL, 0xB3BA151AF1D22E09ULL, 0x5E9AB5CAFD6C60AAULL, 0xA8BC1880CE0B9199ULL
        }
    },
    {
        {
            0x197866C279EA007DULL, 0x2FF973A4259B7A1CULL, 0xB8B5E936E899A874ULL, 0x681F0061FBCD5DDFULL, 
            0x5FFC75D5C11A1E05ULL, 0xEE7457298C46FA93ULL, 0x3AC3A075E9FF9C3BULL, 0x96B05AAC52E7F942ULL, 
            0xE27144E484D9935CULL, 0xBFCC295C5B1141A6ULL, 0x921874355C685ECBULL, 0xD2400CC39A8A2A84ULL, 
            0x2A4F4183B585C881ULL, 0xEBC1E7BA80125224ULL, 0x4EB3642881BE774FULL, 0x53C10F006DC2D6D9ULL, 
            0x9AF75A631C9FA6AFULL, 0x0531A6D2A18A3970ULL, 0xA53F57EC427C2C78ULL, 0xA2E313DFE8E01AE5ULL, 
            0xB146AB4F79021ACDULL, 0x627FCEA43ED49E2BULL, 0xB37B6CF5CD784805ULL, 0xE37020CD2FDDB307ULL, 
            0x3F2B99AED12F6B92ULL, 0x9ED2952E5A7B4B07ULL, 0x7C8165EE12CC5702ULL, 0x3ABF78EB3C5EB76BULL, 
            0x6F73ECF322F612A5ULL, 0xD78FB9D304DDF181ULL, 0x566B0E83D1D2FD53ULL, 0xBA3441BCD40DE7DFULL
        },
        {
            0xA6E2DD0738842F00ULL, 0x1272960FB4A8FE48ULL, 0xCCE9B396406534ADULL, 0xED2A837C678689E4ULL, 
            0x52D23AC8FFB82DEEULL, 0xE1162564D891E5A8ULL, 0xD247E01D73FA59A2ULL, 0x69ACBADC9DBD0C80ULL, 
            0xDE890F1B53A40B93ULL, 0x07315F209C0A5F88ULL, 0x0BFDF0767F389DE5ULL, 0x893ADE06DC1AC239ULL, 
            0x06995D4DB7112818ULL, 0x3A9A4EEB7EF3FA89ULL, 0x2CB40212E6357ABEULL, 0xB0594112CDD1EDACULL, 
            0x7F81685C4C7733BFULL, 0x7A50805EFEF156EBULL, 0xF3FCF0C55486A9F4ULL, 0x9676F19C7E0573CCULL, 
            0x0556D01081897A4BULL, 0x6B55BEA8FE6869BBULL, 0x18BD5376D98E14F4ULL, 0x89685FC9500B7A9BULL, 
            0xC884DA62A3AFFC5CULL, 0x01BD5E23BD3129DAULL, 0x15FA95366A475BAAULL, 0x237B05B1D12BD49EULL, 
            0xDCA7669702DDA9B5ULL, 0x1BD40B3A1DBB78E7ULL, 0xBB18A8BB4F33AFB6ULL, 0x484BA95AAEFA561EULL
        },
        {
            0x78B503A395626BC7ULL, 0xBF21A02244021F68ULL, 0x1E98A6E2FFE446FAULL, 0x773861ED6B4ED2B9ULL, 
            0x31C26B4848B40559ULL, 0xB20E95CA03E1541DULL, 0x0B99B1520D5EBF21ULL, 0xEAB6BA07B61AF617ULL, 
            0xC8C86FCFA1038098ULL, 0x245633F0B8F964E5ULL, 0xD62AF99B641D81DDULL, 0x6BAC89222FA37BBEULL, 
            0x119632BE78FB1E07ULL, 0xE8E8F27ACE5870F6ULL, 0x0799CA05DB4CB2B4ULL, 0xA4F71E673DDAE7C0ULL, 
            0xB23FE9BFA12E9BF2ULL, 0x09371AC5CCB36DB7ULL, 0xB676829E40D24A5BULL, 0x1C924FDD7A300E30ULL, 
            0xA213197B27C24258ULL, 0xEEBAF035648AA228ULL, 0x449AF112676ECB14ULL, 0xECEC60C1E2AD3367ULL, 
            0xAA36EB6A6F785696ULL, 0xF6CD4D6C6873ADCAULL, 0x349FD5B2EB8AE871ULL, 0x9EB7DDEB893BCB7FULL, 
            0x7E0554E6BEA258AEULL, 0x9955C0BCA5D608A0ULL, 0x04B8E54B4DE6D276ULL, 0x1B5EF461BFF92197ULL
        },
        {
            0xEF9D6E7F49094750ULL, 0x27AD0C1A9F9C9363ULL, 0x3580A2EA0767DA09ULL, 0x7FE16CE1E293F269ULL, 
            0x7205A6EA8390753DULL, 0xD66C835267FF1B7BULL, 0x9A2B9052EA00E025ULL, 0x3F057EA101675A5FULL, 
            0xD0D249652C2B8579ULL, 0xFF7212F5A43F9310ULL, 0xC6C881471B2C8013ULL, 0x6C716FF6DB0E6248ULL, 
            0xD3D45B5741A66AE1ULL, 0x7DB38C9F7D97052DULL, 0x9E22808F4DFB6F2DULL, 0x1A8CBF3E278AEBBCULL, 
            0x11598AEBCB75A3C2ULL, 0x367CE9ADE3B3BA30ULL, 0x315ECC7A24F72892ULL, 0xA1669C6F5295D8ABULL, 
            0xC561F9963E586045ULL, 0x4F98E0696266D55EULL, 0xAC548D84DCCC1F73ULL, 0x658B7CF077CACAD6ULL, 
            0xD82D78471DA33091ULL, 0xD95F9CACB3F62F3CULL, 0xFB334585A0469665ULL, 0xF3B61A10C6D03AFCULL, 
            0x0A05FEE56F9646FBULL, 0xBB0718F9DA0AFBB1ULL, 0xE4139DF6345CEAF9ULL, 0x896E272D838FDB62ULL
        },
        {
            0xC4F445313D1505CBULL, 0xA50BB5E54E8154CBULL, 0x6746078DF86F61E5ULL, 0x29A4C5C298729875ULL, 
            0x6921278420FBA98FULL, 0xBAC85A4EF7029F06ULL, 0xB75234E325394172ULL, 0xC908B1D977B84049ULL, 
            0x8D8F558188375CF8ULL, 0xA42987DD1CC6AC51ULL, 0x9097F571BA50ADB6ULL, 0xD5A216802EC6D6BAULL, 
            0x80B36B83AC7805F8ULL, 0xFD66C5C2AFEA416CULL, 0x011CE65874437F2AULL, 0xB09A41986A9EE0C9ULL, 
            0x0B1C985456F28E4FULL, 0xA84FC7DFA4E750F9ULL, 0x0E4C65EF3E157B5DULL, 0xA44760FA930F4AA4ULL, 
            0xFCC716AAF0EE0698ULL, 0x1ED31417B72D8741ULL, 0x270930393CA64157ULL, 0x7D65A5CA1A0662B4ULL, 
            0xEA6679439E4C82E7ULL, 0x78CE2EF67AE0C329ULL, 0xFFF2DDCFFD194D74ULL, 0x3505866EEEE72730ULL, 
            0x1781025FFB43CF40ULL, 0x0D64564E06C23F90ULL, 0x884BE0A833FF0537ULL, 0x49523A598789C3A3ULL
        },
        {
            0xB8EF9816FFBD98BFULL, 0x410C8E797B242C15ULL, 0x5A8C281AF78C447DULL, 0xA844CE9DDF4D2129ULL, 
            0x53581FB639069646ULL, 0xE649B8CF97737A67ULL, 0x1F54213F18F9E2C9ULL, 0x6D7EC3F7F1791AFFULL, 
            0xC51821D50ED8AF24ULL, 0xE983E161269C8F3DULL, 0x14663469E6F4615BULL, 0x0BF14394BE16B98AULL, 
            0x68821C1125167971ULL, 0x7E43FA4DB975F01AULL, 0x5B6463E396761C75ULL, 0x59464326A316EA85ULL, 
            0x87201ECA1F95DAECULL, 0xCE9F7AA0F95B145FULL, 0x415FBBE4EAF60AAFULL, 0xF63D3A28B5EEC5D3ULL, 
            0x38648780746435A9ULL, 0xD7C277ED4B827A3AULL, 0x64C9A9AC508B538FULL, 0xBAB4D2B449D6E000ULL, 
            0xA8FD09E140F07B03ULL, 0x3EAF069D491963C2ULL, 0x20C8AF11D030DFB0ULL, 0x37ACF849739BB00EULL, 
            0x030DF31D0552FA7DULL, 0x231BC953A3CD55BEULL, 0x756F467095874AFAULL, 0x5A7310CC2A843653ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseCConstants = {
    0x6229F8568D4CCDF1ULL,
    0xF50DC0A8CCC8FCBCULL,
    0x6222E7D6BFB38BF3ULL,
    0x6229F8568D4CCDF1ULL,
    0xF50DC0A8CCC8FCBCULL,
    0x6222E7D6BFB38BF3ULL,
    0x3B360D54A491C78BULL,
    0x6CD227A977A209F8ULL,
    0xA9,
    0xC0,
    0xE2,
    0x97,
    0x56,
    0xA6,
    0xE6,
    0x32
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseDSalts = {
    {
        {
            0x573F07B171AECD41ULL, 0x0CEDD4A8C0D2DFE6ULL, 0x9F9A9A1E18B34082ULL, 0xC2E3EB458CA506D8ULL, 
            0xE01D047B82441041ULL, 0xAA10385C2542CCEAULL, 0x688E082245D4C6D5ULL, 0xFEF28DBEFBB3ED22ULL, 
            0xAF7E7CFE1FA94229ULL, 0xD4A5C3248935E0F2ULL, 0x52A769DBA6668C0CULL, 0xE51E14069E3FB955ULL, 
            0xF53637B2FFAE2876ULL, 0xD4B51753890F4FB8ULL, 0x38148ABA0A5EEBACULL, 0x407AAF57930ABF0DULL, 
            0x3E19D93895CE5524ULL, 0xA0E59691C8F94C61ULL, 0xD736472E173A3385ULL, 0x3EA7DA67EBEEBBA4ULL, 
            0x712441F593BE7566ULL, 0xC4B24D13CA42F4BEULL, 0xD8DAA8EEE2BB6F71ULL, 0x6EFBB0381D9B4B9DULL, 
            0x9835B3A8D452A282ULL, 0x797D21BFF69704C1ULL, 0x8DE58AB6C0C94E21ULL, 0xA188CEAAC17E30F2ULL, 
            0xEE7BE008D5F6938DULL, 0x078729B8DD7F4285ULL, 0x9FA5EA548DA8580CULL, 0x04C810A579BAFE39ULL
        },
        {
            0xB63DA91481EDC379ULL, 0xFCD3171378AEFD76ULL, 0xDB440C63885F5CE9ULL, 0xD7F76C209F473E53ULL, 
            0x8BB066C3D9FCB745ULL, 0x7B3F6558C58D82FFULL, 0x0D7432526DD5A857ULL, 0x15FA20DBA0DD7AEAULL, 
            0x6AC9E90D3D89BFB4ULL, 0xAF3A179C6907C8E9ULL, 0x0A9D3F3FDB348646ULL, 0x78E6B08179EC0617ULL, 
            0xDB99186D4F7612CDULL, 0x143FED278C86DB9BULL, 0xAB6F2F4EF52D4968ULL, 0xFF8A37172449AF64ULL, 
            0x2ECF6445D9C6F761ULL, 0x67D00EB8890F66CBULL, 0xE8E92687A7275B99ULL, 0xFB1074C9FFE6191DULL, 
            0x21B2061A3EAFEC9FULL, 0x80D18E21C5C38860ULL, 0x1F6265821C908738ULL, 0x53941258033D1D0BULL, 
            0x3ADFBCE3835EEFBFULL, 0xB1DDE8E19ABEFA74ULL, 0xAC1F3A745D90F682ULL, 0xC1510DD7708C2B22ULL, 
            0xAE7838E1802B5714ULL, 0xAEEF8C3FFA736086ULL, 0x89831EB131893C1BULL, 0xB6875403DE313DAFULL
        },
        {
            0xEE2B6157CB2D2CB7ULL, 0x0C517FBDC59E5272ULL, 0x0C6BEED5CCCB2594ULL, 0xB30F61677C5B0A63ULL, 
            0xC7ADE2F7DA7E062EULL, 0x36FE770136CD9AA5ULL, 0x2E3DF1D2EEFCD736ULL, 0x094448F50B0D6B89ULL, 
            0xE0A81355FE298323ULL, 0xEACEFF55261BE516ULL, 0xCF0534E2F6A54BF0ULL, 0x709BD2199B9D1E06ULL, 
            0xC0F084A923C73C94ULL, 0x09604B1375D33E17ULL, 0x0190E6B229DBFB5EULL, 0xF1C73601CDE64757ULL, 
            0x5F276B7F8EDFD9FFULL, 0xCF05AA7022CFBF55ULL, 0x423E93E9E1944B89ULL, 0xB75417D0E2EE425FULL, 
            0x4E3FA0B25880A838ULL, 0x4D691EA2FAB1D560ULL, 0x46B44F78C14F3062ULL, 0x72CE4A86B4FAB393ULL, 
            0x9E2D30DECA654B79ULL, 0x926A41D38B720BE6ULL, 0xA79BCFEF54565F8AULL, 0xBCD3AA73825DA6ACULL, 
            0xFD84DEEFA78C80E6ULL, 0x16091361B14E99EAULL, 0x7E65E6F5D6D8A835ULL, 0x29F96C23A16A15E6ULL
        },
        {
            0x4F6973F29FF4ECE1ULL, 0x6B30AA1DC2266271ULL, 0x3ECB1CCAA270FBD3ULL, 0x5CEB2FC68A4685AEULL, 
            0x503617D44DFF784EULL, 0x1A9993B4F35D9D3FULL, 0x3D4CEC0E6931295DULL, 0xDE5CB8B6E9F35E33ULL, 
            0x003C2C3E110032CDULL, 0xED57E1246854EABBULL, 0xB4F4F9E5C025CCF4ULL, 0x296C86F9472B2219ULL, 
            0xB5D211678028DF17ULL, 0x545B1B2D4B524E22ULL, 0xE3F711A5190F8169ULL, 0x858C92F1520496AEULL, 
            0x8FEFEC7E272C9871ULL, 0xB2650B2C95FCCC82ULL, 0x9520D22E57FE385FULL, 0x1DBEE0D5A82400D2ULL, 
            0xBB5D989790A6486DULL, 0x0FDEEB24581A0913ULL, 0x8AE265F6D4EF1954ULL, 0x3F74D93C66B042F2ULL, 
            0x65C25AC8BE60F2AEULL, 0xA7513F8A4CFD132EULL, 0x218FECE929898FCBULL, 0x17EE3C888F26097CULL, 
            0xCEBDE44B6CC8AA3AULL, 0x65864D828D80A48EULL, 0xB100D9068554F370ULL, 0xDE0FD910A72DFE32ULL
        },
        {
            0x22102C93EDBE0C78ULL, 0x34ED0A8218FA2AD3ULL, 0x4B18B4573D548A05ULL, 0x15C70179C4614F29ULL, 
            0x4593A8CB3A27F85DULL, 0x43EE8250C65775FEULL, 0x7DD5B256B8A961CAULL, 0xC198E285578C95EFULL, 
            0x5AE75E7E5767D5F1ULL, 0x10835638629FF2FAULL, 0x8803ABE990169410ULL, 0xBABCF27BC100B414ULL, 
            0x48EE1E7AD8831E4EULL, 0x1A7BEB7E4ED5DD38ULL, 0xF7408C52604D5990ULL, 0x5A96B784CF5C027CULL, 
            0xB54F77BB98321C82ULL, 0x44E0ED94C8B3E8B8ULL, 0x6FC04868B689EFB4ULL, 0xFB83885D634D5C63ULL, 
            0x4E0BD1E9C0BD7465ULL, 0x4AE10956C6EFDC3BULL, 0x00FED442898FC851ULL, 0x8F59FA95A947561EULL, 
            0x9BEAD9979801B6A3ULL, 0x6C16C0E59680C119ULL, 0xF3EAFD74C85F85F5ULL, 0xC6C47ABC866C658BULL, 
            0x5320D19DBFCA1EB9ULL, 0x38E99BA4B89B73D3ULL, 0xD0FA280130338760ULL, 0x407EB8EBB416B538ULL
        },
        {
            0xA7B28DF0E65404C6ULL, 0xCE7BBF7265841880ULL, 0x7DEE72B5E22FC08AULL, 0x37B5397189A6EB88ULL, 
            0x0328A0106B5C3A3DULL, 0x7DC2C72DCBF7B7FDULL, 0x6B47CFD3FA1423EAULL, 0x94CCCC15AFA1B3E0ULL, 
            0x8444CC1BB141CC1AULL, 0xBA9221E0FDE043EAULL, 0xA5D0F81504F03365ULL, 0x37782EB63764A1E9ULL, 
            0x6949A6791843FE14ULL, 0x995596AA07667C03ULL, 0x7F83BDD68AC0357DULL, 0xE31B348804DE119AULL, 
            0x016F55BCBD6C1272ULL, 0xF765B4FAF3C5CCDBULL, 0xCBEAA21B5BC0C91EULL, 0xDDAC2CD1292EF335ULL, 
            0x609D9AA3D83AD783ULL, 0x547D0E1A34877310ULL, 0x8D6C86681DC0FB2BULL, 0x0CF87C451A90B10CULL, 
            0xD22AC49A06DEED81ULL, 0x5456E3AB3210032AULL, 0xA1555B1CFA700082ULL, 0x32AC1BF10730A7D5ULL, 
            0xC19AC95EA26AC989ULL, 0x2898927B3158CD8DULL, 0x6A6FDF6338176369ULL, 0xE091E3C2B56053C7ULL
        }
    },
    {
        {
            0xD9CD8B1819C9F02FULL, 0xD9394E19EBD07AE0ULL, 0x7610908FDCC0EEAEULL, 0x8FA946B766075125ULL, 
            0x59E83A7701CA55E9ULL, 0x791C59F7EE241C34ULL, 0x32280889C5037242ULL, 0x4690B875026028A7ULL, 
            0x152B5F54AD7F1FB4ULL, 0x6B5948FC09E594B9ULL, 0x2271F1EB7E8D1B27ULL, 0x1F41836D05B07EA7ULL, 
            0x3DD152383F40141BULL, 0xD5FCC06980D8B481ULL, 0x5C20E3C636210F3AULL, 0xAAC4B76099D29020ULL, 
            0x4C49DE3183D64EBFULL, 0x0FA8A3D1F2A4490BULL, 0xE8D5C8D3BEF9E046ULL, 0x600757C8157E8F7DULL, 
            0xE35B81A51BEF48F5ULL, 0x4E1E60012E990F05ULL, 0x068ADA3137E8385AULL, 0xFD2C509A1D8DFACDULL, 
            0x5205BEB5050D2266ULL, 0xF682B26CBD9DE09EULL, 0xFE959E952012A1BCULL, 0x54F7D617681B3ED3ULL, 
            0x3DE2EC8D8494B987ULL, 0x4F60805A0098AE0DULL, 0xB40A93867E6C3179ULL, 0x1E857CE463D94CD2ULL
        },
        {
            0x5E6C6FED66824EF9ULL, 0x112CC12B87CA2A6CULL, 0x7D29E352802D2B5AULL, 0x39886FD2CC9E3562ULL, 
            0x96A881333D51B0FBULL, 0x0B9AD224FCCE664FULL, 0x8E5D38D1BC4F5427ULL, 0x33EFCD588F35A6DCULL, 
            0x694DC7B6BEAFDA7BULL, 0xFCD5CE3A4FB15A23ULL, 0x2388B6ADD0B510E3ULL, 0xB900FAD6DFD937D5ULL, 
            0x56D30C1419894B45ULL, 0xA615E67A5AA6B8E5ULL, 0xC0E24C2ED369EF51ULL, 0xCED3AE32FA1ED2A6ULL, 
            0x17E2DC59495A6EA0ULL, 0x464C97A547CB8E63ULL, 0xD4DACEC9E692D5BFULL, 0x8EDC844822828AF5ULL, 
            0x69704455DFFDB2EDULL, 0x79A703FE515451F7ULL, 0xD09E2175482328ABULL, 0x1421A6037FE927E6ULL, 
            0x68F5C123F76ACD58ULL, 0x9345A427460F8E57ULL, 0xCB6E9A98CB01466EULL, 0xC428F9183719CB2CULL, 
            0xBC2FE8F85348A380ULL, 0xFD47AA259ECEED82ULL, 0x0DF4F4892BDAFCC0ULL, 0x643032219F7010C6ULL
        },
        {
            0x3AC6344D9C7231DBULL, 0x45E04CBA7DA3FACBULL, 0x8E398F60B923F387ULL, 0xC4BF7A1A62801249ULL, 
            0x595AAB93303F0540ULL, 0xF0D4785F660B5A2AULL, 0x91104D0A62BC55C7ULL, 0xF0DEB3BB3C23AC12ULL, 
            0x50FEBFCAA7374DA6ULL, 0xDE350FA891B38A52ULL, 0xFADC0779DE88A598ULL, 0xBC08B99B4C8D0EC8ULL, 
            0x27D0770B0A0E9E79ULL, 0xF00FF85B7FF7CED4ULL, 0x469D1C52FB8A8C7FULL, 0xC52F4C6C56CF8B3DULL, 
            0x744B70D8F0E58C8FULL, 0x37AE1F2ECE876081ULL, 0x1585DDC05CDAA1A6ULL, 0x32CC385EDCB0D08EULL, 
            0xDCEB14AAF375AA6AULL, 0x8E4B088A6BF27BA4ULL, 0x4B9561905E5245F7ULL, 0x1A16B464962E19F6ULL, 
            0x030E4C758815D3C9ULL, 0x661D777D67FDD185ULL, 0xDCE1C9540A0BBC0AULL, 0xC02569C7E0CD2FB2ULL, 
            0xDD56A290D7E82B65ULL, 0xB397923D44177DB6ULL, 0xE4E9745DB47A5B14ULL, 0x0DB364F6F1F68DB1ULL
        },
        {
            0xF447B10DB9BA3BE2ULL, 0x2AC947D5B0C57B5EULL, 0xA354DADD2C89C477ULL, 0xFEE84E1F88442BD7ULL, 
            0xBA9DCFC6642EAC1BULL, 0x24673EF8BB1397E9ULL, 0x27A616B9EF7EAB98ULL, 0xD853805E7B462D32ULL, 
            0x1B8D0EFE2176817DULL, 0xB0F14015BE3B58A2ULL, 0xF1D957CBCB2A056DULL, 0x4F66140E1C8F4A83ULL, 
            0x02B236A20AD3DD87ULL, 0x2AD1C89439C1E34BULL, 0xC47C291E6992AB29ULL, 0x9835B308D8F88B5DULL, 
            0xFEBB8EBEA722D42BULL, 0xE2B76A29B7451DE1ULL, 0x6E5D004E36914814ULL, 0x4B1808F8C16437B5ULL, 
            0xF2A14DC656B18BB8ULL, 0xB0F5D57A54D5AD84ULL, 0xD7AD07E799E93545ULL, 0xAC7F33E6AE1D0D07ULL, 
            0x997D2E199C7FE843ULL, 0x39E3734FEC1C1781ULL, 0x23236C843737AA86ULL, 0xF23D5D50757CFFA9ULL, 
            0xFBF3BE701F3707BEULL, 0x3BBAA596C32CADC7ULL, 0x744A9FC7C5306E68ULL, 0x49E27DBAD43BF3D8ULL
        },
        {
            0x527DC2AB615D1270ULL, 0x84AF423A49312D64ULL, 0xF6E040D38CABF196ULL, 0x223F8A92F851DC08ULL, 
            0x47AD2AECD4D7DA89ULL, 0x75E556D2487B8F0EULL, 0x67D09C5E51328D7BULL, 0xDFAC0513A8196D86ULL, 
            0x6211277F91BA2229ULL, 0xF9A8F80EDD3CF2E4ULL, 0x344534122BF7AA37ULL, 0x8DC15157AA33EF84ULL, 
            0xEC6C030C48C2347AULL, 0xD4DB006E6F06493FULL, 0x4C71AC8F40F59C95ULL, 0xE864A88BAE716439ULL, 
            0xF45FA22EA051254DULL, 0x11AFFC920C0D60AFULL, 0x6C12EF5C8EB91588ULL, 0x4600128081571A22ULL, 
            0x5B897E5E4601889FULL, 0x1B26603B7ADCD48CULL, 0x37C0CF5CE4742634ULL, 0x748234E68A43D7DCULL, 
            0xE0E5E35622D337C0ULL, 0xAE7BF119A4A9ED7BULL, 0x9F7081AE32058346ULL, 0xEE375580AC2A98A8ULL, 
            0xA2627BC87840561BULL, 0x7EDF88A4F00F3CB0ULL, 0x36D6B7088E0CD859ULL, 0x322E45F82ECFE069ULL
        },
        {
            0xA05307596F2DAD6CULL, 0x36BAD7E8035753BFULL, 0x6D27E250EFB6A7E7ULL, 0x09D3D23188E9CC58ULL, 
            0xC969850958A972A8ULL, 0x30B74E1E700410D2ULL, 0xBAC67A06F84992CDULL, 0x61181BC8E9631625ULL, 
            0xA669970A0EBC7CEBULL, 0x82042A051207A759ULL, 0x17C1B7A2CB2B81F3ULL, 0x14CE79F79FD3BDAAULL, 
            0xB6F796F5E740B335ULL, 0x8792A163B5A51596ULL, 0x01D398A65BC9A376ULL, 0x90E7E904E228B1D9ULL, 
            0xC889FDA4BA66C7AEULL, 0xB8AEF690B9FD65C3ULL, 0x043D17D792477E2EULL, 0x0A116B4298E534BAULL, 
            0x32DEA0F095DAE305ULL, 0x6EF4A939E783FD2CULL, 0x50AE595BD2DC61CFULL, 0xC23434573E4A310AULL, 
            0x073D2D15B06E3CE4ULL, 0x7140AB727E656E73ULL, 0x5B013E8D9FAD47EBULL, 0x66D5327E83ADAF8EULL, 
            0xC9CE02F7959496DAULL, 0xEE2C100FF8AC2DD6ULL, 0xD32B1D4CA9F035B6ULL, 0xED0B33500039C848ULL
        }
    },
    {
        {
            0xDA4886B5334D37C2ULL, 0xAE00FEE942B12A42ULL, 0x99FE40BA31671CD7ULL, 0xDCB009240969BB8BULL, 
            0xA55B5ADE208AE767ULL, 0x6A48722BEB2523D9ULL, 0xE9655FE4B9B0085CULL, 0xE7D5E11CF58B3849ULL, 
            0x2278D485996DDE9EULL, 0x7BA60B3348177A0AULL, 0x8D0CEB0438E74873ULL, 0xF9D4B2012346AC54ULL, 
            0x5959BF2238F649A0ULL, 0x800FF15C7F90DAEFULL, 0x06FF0CB9BA2066F7ULL, 0xE29AFEF675A782FBULL, 
            0x7069D46199D0B2ECULL, 0x50E1D72DE56F4EDCULL, 0x1036F40141962BE0ULL, 0x42E76C02E14B6F22ULL, 
            0x91C1F75116263CE2ULL, 0x291F4653B62F997DULL, 0x547FD1DDFA4FEACBULL, 0xE6D08871E30022F0ULL, 
            0xCDD6975FF2D04EA7ULL, 0x283883F8DD0F6B72ULL, 0xB38B3956FF4690BDULL, 0x166F0F1C523D2ADBULL, 
            0x2B94D2730886C2FDULL, 0xC6FF4EBC34492E72ULL, 0x1B3494FDBF8D428EULL, 0x199A93D731FCA1FCULL
        },
        {
            0x49778FC96C299A2EULL, 0x57317BEE67FFEC21ULL, 0x47229AA34F0AF27AULL, 0xF1B08F025C629521ULL, 
            0x740CF59758696A97ULL, 0xFE382071B09687E7ULL, 0xCD7FBC1130A018CCULL, 0xC6AF0AB6E192EB3AULL, 
            0x7C2B4552AB3B82D0ULL, 0xAA6E2D2FF44C311AULL, 0xD5B0EA35A30D9308ULL, 0x7F0501526D2C14A5ULL, 
            0x93C463A060A4CEDFULL, 0xFBF9EB2791CA917AULL, 0xEB40CBB4D5FCD90DULL, 0x2DF172991516067EULL, 
            0x8AF1CEBEC0926F96ULL, 0x138D0834FD4C50EEULL, 0x065D51D2030F23AEULL, 0x2A86ABD25976B8AEULL, 
            0x57B4B686F205954EULL, 0xB20155A0A0C01F65ULL, 0x7070089DB37EC78DULL, 0xC646213D72C4A655ULL, 
            0xED32C04A5A32C993ULL, 0x95A3A9578089804EULL, 0xEE77DAD950A77321ULL, 0xC046BF860F1BD77AULL, 
            0x90109AE5D7CC3705ULL, 0x9A6EE257AB607024ULL, 0x970B2BDB46305995ULL, 0x85595D0CCC62584BULL
        },
        {
            0xEEFB1BC5FAC0D636ULL, 0x8C4F63BE7BEC3733ULL, 0x89A5FFDE848C7FA5ULL, 0x8EDE025C5DD7C451ULL, 
            0x1DF1F2DAE260ECA7ULL, 0x1412263A1C85E71DULL, 0x43F66D29AE24B577ULL, 0x4102807B2101CD1CULL, 
            0x0DC8A634436D45DBULL, 0xAC7668D575AB7D69ULL, 0x9D02719BD4F42390ULL, 0x9F6E69ADF24C2D82ULL, 
            0xA39341742ABFFBF2ULL, 0x91410AC4DF9FC5F4ULL, 0xBA3330FED10C7CACULL, 0x97B1A9C9D9A4B14FULL, 
            0xD9867B6F325FE1E9ULL, 0xA43FF1EE8EB0163FULL, 0x3ED403E7B05F686DULL, 0x87AD62E422AA9EB4ULL, 
            0x5C4D2D67111CE050ULL, 0x872736D73470E3C8ULL, 0xCCDFF490D45FC81EULL, 0x4678D878E2640B2AULL, 
            0x945BB3693F9FE024ULL, 0x2250C7286098D992ULL, 0x80D0016B6A2F060CULL, 0xE7A27D6F37308F92ULL, 
            0x549A6D7F8F6FEFA1ULL, 0xB4F21A3423E81FAAULL, 0xAF8554F018006269ULL, 0xC90FFDAF58F13A4CULL
        },
        {
            0xFFBED48717A481BBULL, 0x4EEF77437BB31798ULL, 0x1DDA221023EED56DULL, 0x87300D46F9C5353CULL, 
            0xB103D2EC5D6F43C6ULL, 0x3DF5DAE58ACE9DFCULL, 0x4E611ABE7DF96D7EULL, 0xF15EEF7FFA3852EDULL, 
            0x4C85BDFABDF153A6ULL, 0x6B63BCE7E60AD2D9ULL, 0xC709D3160CCD182AULL, 0x444401A0895A5766ULL, 
            0xC25EAC13BDF43F20ULL, 0x2ED56046301ACAFFULL, 0x75D01663006FDCBCULL, 0xBAA2083B40E83C6FULL, 
            0x96EB6B5B11A4BF00ULL, 0xB82D846B34629CF8ULL, 0x11C84744839F6372ULL, 0x255B541432C480EDULL, 
            0xCBC75F0E6081404EULL, 0xC6DA2B2A7E0857AAULL, 0x53636FE8B4E28821ULL, 0xA5520449B83EDC11ULL, 
            0xDBA089A5108697A1ULL, 0x9534DB3333900797ULL, 0x42CD1FB7B0EAE21CULL, 0xFFC318043993BF00ULL, 
            0x8F7F8DBFEC4512B6ULL, 0x6AB8A25EB6F8FD3FULL, 0xFB6AA67FCBE59DFCULL, 0xD51D66277204FC91ULL
        },
        {
            0xC0F85DBBB0F09A84ULL, 0x60F6AAD883A7FE2CULL, 0x183B37479E1C5903ULL, 0x8A05EF7999871BAFULL, 
            0xC773BA4AC5E8694DULL, 0xFA04701106B760C5ULL, 0x4D90AB0037277701ULL, 0xDAE7CDF1E9BBA8D1ULL, 
            0x2A99D81DA8BFD669ULL, 0x53DA49C120EF7DBBULL, 0x411F1B5AB8A30E7EULL, 0xEED743F12B636594ULL, 
            0xEBC38A0F7DD6B4E5ULL, 0x67538256EC321339ULL, 0xEFBF014B8E8C428EULL, 0x7797969D26677EE6ULL, 
            0xDE5555313691E92AULL, 0x366850192AC7D255ULL, 0x277CE203442B9EC6ULL, 0x2C23838170289175ULL, 
            0x9CA9A03393BF3DBEULL, 0x6B1EE8A704DEFD20ULL, 0xB931B23F5ABB90E5ULL, 0x916C367C1ECA1F09ULL, 
            0x62BDE71089F220A9ULL, 0x48BA0DA7E4B47D40ULL, 0x4271C1D5C26A4A1CULL, 0x9F1B4127B35C16EAULL, 
            0xF2EF5F66FCAD3B35ULL, 0xD3789A877853F9E6ULL, 0xA75762B99C1D28ACULL, 0x44ABA256521AFE9FULL
        },
        {
            0x394CB1CFAE74CA81ULL, 0xFA648673C075062BULL, 0x98F01965CE7B9065ULL, 0xEF5A726546F3D70BULL, 
            0xE0F75F748AF4F370ULL, 0x4988133B6CA65FF9ULL, 0x8598D7A31EF5C9B3ULL, 0x2FEC70BF3EF33969ULL, 
            0x14C05DA17B612ECCULL, 0xDEA670A1D286C911ULL, 0x7F82B36358EF734BULL, 0x6C6E07E5C52BA2BCULL, 
            0xF16FABC8249F778BULL, 0xC30A5B708E52416EULL, 0x050DF705CC7F8F45ULL, 0x09B022BA384C4921ULL, 
            0x3208B0808B00E343ULL, 0x889A7EF0FC5ED71AULL, 0xBF882AB77ED7F0D7ULL, 0xC2CBF13671272ED3ULL, 
            0x37D9FDFBAF2D419AULL, 0x7FAF09B43228C2C6ULL, 0xAC837F9DC84BBC19ULL, 0xC579D8A651A17297ULL, 
            0xBE0E6CE24B6FACC6ULL, 0x473BE078D20FD212ULL, 0xB32A6F5B7549E5DEULL, 0x191F87450EC69AA1ULL, 
            0x07B5D659B43579F4ULL, 0xE453BB8BFAF4733FULL, 0x274DE063D713FB2AULL, 0xDAD2E4BB94B4FF6DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseDConstants = {
    0x40CF1FDE62DCEC6DULL,
    0xAD5410CBD13086D6ULL,
    0x6F378A2AB276C8A4ULL,
    0x40CF1FDE62DCEC6DULL,
    0xAD5410CBD13086D6ULL,
    0x6F378A2AB276C8A4ULL,
    0x2D6691F186FA21E6ULL,
    0x86256DB517543C28ULL,
    0xB8,
    0x85,
    0xC4,
    0x0D,
    0x30,
    0x6F,
    0xF3,
    0xA6
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseESalts = {
    {
        {
            0x66A99BA5C8C63B66ULL, 0x05AB5A5065C27357ULL, 0xC93D2FF6C32BA403ULL, 0xE1259DA0B9A0EE69ULL, 
            0x9CB36B836712FB5BULL, 0x3EE07A0AD910388DULL, 0xACD063F8EDE04BE7ULL, 0x49C64C0DBD2889F7ULL, 
            0xF0A786F365EE7EE2ULL, 0xD52BD17A98D8BA41ULL, 0xC699A89AFED719B1ULL, 0x7AF724076CB0AC89ULL, 
            0x80436011524164B1ULL, 0x3973FEC0EEB693AAULL, 0x8EA03C3F2625D1F1ULL, 0xD5DF62CA15F03B6FULL, 
            0x42F0A2425054D77EULL, 0x2F2C81513438EAB4ULL, 0xCCA421FB83AC2100ULL, 0xBF54F7C3C893C8B4ULL, 
            0x2868F1158E276930ULL, 0x33A9BC28D6263B22ULL, 0xD657D9F60DF34BFEULL, 0x111ACD2DF42CC09EULL, 
            0xA65AD9B4D9F65BA2ULL, 0x7A7C4C28045EA9DDULL, 0x36A41A89255D2763ULL, 0x3D326EC2B4608695ULL, 
            0xB69EEFBA4B87C5C0ULL, 0xCB78244F2EAAA40EULL, 0x2ADB03CADF5CEA94ULL, 0x594281BFE552CF91ULL
        },
        {
            0xA7BEFDD66A8F2859ULL, 0x2B2CE97265D47787ULL, 0xA92FC5353C1CBDFEULL, 0x6526C42F6994E759ULL, 
            0x49ABB8D7ECEF52AAULL, 0x301D24AC6CA51B45ULL, 0xFCFCB70176348CEEULL, 0xC72091EA4B020136ULL, 
            0xE4668D5390B62526ULL, 0xDDCF0200786AB8B9ULL, 0x4AB22BB1B537C304ULL, 0x9CADAD96CEE91699ULL, 
            0xDF8BEEBC53966927ULL, 0xC6DA19001049B752ULL, 0x52683C00383D78ECULL, 0xA142E8790AD1D777ULL, 
            0x20835193EBCC6C0DULL, 0x6ECF18DEB926A886ULL, 0xE44216E6F7453FB6ULL, 0xC4D0F177F086E5F2ULL, 
            0x21122401DAD3BD1BULL, 0x851C250EAFE5D9A0ULL, 0xC95F73E8B7DA7475ULL, 0xACCCFFA1EB13AE4DULL, 
            0xDC9FB117700148C5ULL, 0xF3EBC2FA24018309ULL, 0x6F21EA4AC8A58B03ULL, 0x3446FB66D96CB353ULL, 
            0x75D20D8D66F93778ULL, 0xB8DF4D7F1E10EBDAULL, 0xEEA297B77FE09EF8ULL, 0x9DB359E3A2CFC1B0ULL
        },
        {
            0x0FE044B53C9B6F73ULL, 0xBAD17CE0D06C976CULL, 0x80E1F7CBAE0D9EF8ULL, 0xEF69BBA23AB1C3C3ULL, 
            0xBBBAD2E596D0ED43ULL, 0xBA2032008E56E5A2ULL, 0xB2C7369C56216C33ULL, 0xA6930EA4740D297DULL, 
            0x2E81FB55E3904B64ULL, 0x6569A5AFE30A60BBULL, 0x0BCA61BBA47BC33EULL, 0x09FF3B8564A6CC76ULL, 
            0x5BBBA4D71A176DF9ULL, 0x5AEEF8027B997611ULL, 0xBC515B19A15068D9ULL, 0x3816127F6FB3C1BFULL, 
            0x3D5DD73AC71ACFA3ULL, 0x20666EF061701C9DULL, 0xFC866214B2C8EF70ULL, 0xD63545BD71EA31D4ULL, 
            0xC73EAD9C792A6AA5ULL, 0x04975610B5D9CD56ULL, 0xB4E94FC7777CEDF2ULL, 0x9DDE038193F4A450ULL, 
            0x7FB10BAC6DFCD207ULL, 0x694574B2D68788F1ULL, 0x196D85033088A637ULL, 0x574EEEDB3B416B28ULL, 
            0xF5D1ADB724BBC19DULL, 0xAE6464369EB90FAAULL, 0xC64DB1C752624250ULL, 0x51056423EDC67D92ULL
        },
        {
            0x37CF0320ABB1CCC3ULL, 0x2ABEAAEB2C77C995ULL, 0xB95954418B1E0464ULL, 0x98BA22CD835376C5ULL, 
            0x736C441F8FCABD06ULL, 0xEC61CE927B97C669ULL, 0x896A81144A0CCB61ULL, 0x674F23A0788D1F6BULL, 
            0x5900CD6831B071BBULL, 0xACA8602A060D0E90ULL, 0x2F9A48EBF2C2E336ULL, 0x6DAFAF9410E8A235ULL, 
            0x478732A35AFAC9C4ULL, 0xD22CFDFBAE158307ULL, 0x0AB0B69D4553A773ULL, 0xD07D6E8DDB988E37ULL, 
            0x9BEF96185DD57CEBULL, 0x584FC5FE5DA8559DULL, 0x7BD203BA312DB922ULL, 0x49EE61D7FDBE8B9DULL, 
            0xCD764FDA1BBA59E7ULL, 0xDE10E7A0C3380542ULL, 0x7086433355D33B91ULL, 0x576FB0DE5D10DE0DULL, 
            0x04301A60ABB8215AULL, 0x9F2AAD9823EDC3ABULL, 0xA5FC6E3A3EFAACCFULL, 0xD8A892DB06BD0003ULL, 
            0x2EAB93C7B45B4D64ULL, 0x2104EA1B7699B804ULL, 0x9A699718063AB203ULL, 0x63CD42A57E64A88BULL
        },
        {
            0x81BAD43C7B40F45CULL, 0xC90C49E7D297CE32ULL, 0xEDB5C671C4DC5E57ULL, 0xF9DD5B48B2FC34CBULL, 
            0xC7983F6708774405ULL, 0x8EF12E8B2C5D31E3ULL, 0x8EA0AAE02A5A17BFULL, 0x9B378F48CDFC3AD8ULL, 
            0xDE94A2E93943A54AULL, 0xD77C0673F08B06BFULL, 0x6A7E009F2142E04BULL, 0x9F2312DEC1F634C7ULL, 
            0x7B87FD21B87D33EAULL, 0x3F3317A1BDD451DDULL, 0x7F72A2C8C788B848ULL, 0x8FBC0367B06E6959ULL, 
            0xC4F9345625B0B78CULL, 0x3C1078993D0D0D6FULL, 0xC550F640ECF7E0E8ULL, 0xF0BA0EE54680E645ULL, 
            0xA6BF731B4F47A62CULL, 0x1EC000E8A17ABF9EULL, 0x2AE5BA3FD229F13EULL, 0x788BF7B297E71B33ULL, 
            0x9A454D11A9A7F68AULL, 0x8D357911E65D145FULL, 0x389772F8FEBA2193ULL, 0x488BEFAD19E1ACF9ULL, 
            0xC3445264E574EE56ULL, 0x4DF8112B4F4392FFULL, 0xBECAC06BDB78DD1CULL, 0x1ABFF281282B378AULL
        },
        {
            0x0FFAD6C519E6FF74ULL, 0x44C1784026F99E70ULL, 0x1493AE646E0D8B0FULL, 0x20EFBAAD802E1CCBULL, 
            0xCA88551F43A76E62ULL, 0xD0D6A06D44C1E07EULL, 0x9E5A63B8675D754FULL, 0x1CCB22626F53378CULL, 
            0x9BF334EEA106B654ULL, 0xDF21CB703003CE58ULL, 0x6A5EA55466C32C14ULL, 0xC2A17BBB5AE3235CULL, 
            0x0E6BB35043F2B75AULL, 0x8C6040B803B63DBCULL, 0x469AC17DA1226AB6ULL, 0xDA690ED33A4B4C5BULL, 
            0x2681E4F19C718F42ULL, 0xABC7A828D3E2A2D7ULL, 0xEF30F9F5B3F2E744ULL, 0x0170D442F807896CULL, 
            0x99BA31154B32FA15ULL, 0x8B4B6DF5C070F919ULL, 0x48DD270B9A0BA7C0ULL, 0x5DFE2B9EAAE96882ULL, 
            0x12AC7BEE0B1BFE6FULL, 0xA96245A18D83B08DULL, 0x0C6332D56893008CULL, 0x0D64E7227E73D7A6ULL, 
            0xA3FA018F3E43748AULL, 0xF3A54435BC0B6A46ULL, 0x5C41D07708105848ULL, 0x5C4565B58B8A1B89ULL
        }
    },
    {
        {
            0x521E3ECC1F61E33BULL, 0xC648FCC3E0421D7CULL, 0xA4B5B9813D39E4CFULL, 0x775A2741EF542130ULL, 
            0xF26F69F038D429C6ULL, 0x20BD31AE1DF156E9ULL, 0x1C81FA9C7EE2B92BULL, 0xDAA74E6EC1F10021ULL, 
            0x793DC5B355A35134ULL, 0xB73ECF5A68B68F09ULL, 0xBC1D9229F66CE51BULL, 0xA345C760B4D80CC8ULL, 
            0xC288140FAC2182A8ULL, 0x144602D111EC9B40ULL, 0x5FAB9DEC4014C49CULL, 0x9225AB28D7DB8F95ULL, 
            0x652070A7BB46C0EFULL, 0x854175D144BE9695ULL, 0xD005389A5A556650ULL, 0x05973A5DD12FA011ULL, 
            0x2C83693166831126ULL, 0x6797BF47B52533B7ULL, 0xB08CF229E326F5A6ULL, 0xDA3707D8D03C81DFULL, 
            0x8E69EA28180C184DULL, 0xD683474331E4ECB3ULL, 0x1FC310BC9621DE19ULL, 0x7E9AC645D5D115CCULL, 
            0x30AC881380B1D9E2ULL, 0xCAA22DF2FDF0E0A8ULL, 0xEBCA5916FD49DB77ULL, 0xFBD4384D435013A1ULL
        },
        {
            0x7987C1C83A9FA358ULL, 0x551FA7EC72A295A4ULL, 0x529BBCD55C06DB7AULL, 0x622AF49F9E571BF6ULL, 
            0x988642EBC7685306ULL, 0xDC8904F6EB4A6C5EULL, 0x5B0CF6075FD884DEULL, 0xE9C7C48404EF0543ULL, 
            0xF6D76FD6118350B7ULL, 0x2177CAF610728E65ULL, 0x0BBA7F61C385C6A8ULL, 0xD944B5DCD0834ECDULL, 
            0x61271F1571E6186DULL, 0x5C89C22D9E056EA1ULL, 0xC651E806C345F8D4ULL, 0x6F4F8344D64B1FFCULL, 
            0xA48F3513F0AE3680ULL, 0xC4C24AEADB08453EULL, 0xD2CDA6161A222270ULL, 0xAAFF69A148404FCAULL, 
            0x3E4B2862746159CDULL, 0x044305054B92714AULL, 0xBAF65DC0EB4CA9AAULL, 0x6E868B90757EAD20ULL, 
            0x2E02772DA9E8FEDAULL, 0xEAEA0D654BBCCB3CULL, 0x8D4BA04612C54FACULL, 0x41FE9051B190A57DULL, 
            0xDBAE583AB5128DE2ULL, 0xF85A1F685BA438F0ULL, 0x0E1CCC20D464459EULL, 0x9CA7B744B3F2FDE9ULL
        },
        {
            0xA47FAD34BECB1B14ULL, 0x21F2DE356164B52DULL, 0x414EC730986340EEULL, 0x69D7C3DF246430DDULL, 
            0x6E6F88C1DC564DF8ULL, 0xF97284475BDE6731ULL, 0x1FC526306C188BEFULL, 0xA51A26DFE0853BA9ULL, 
            0x0626736137BC2B5EULL, 0x78B5861F7FEEC804ULL, 0x40E16C23F1D0305CULL, 0x2EE5F19D2B747946ULL, 
            0x43CB70ACF19B347FULL, 0x6073682F1DCFFA64ULL, 0x9305E2E9861B4BC7ULL, 0x8981576C4C336916ULL, 
            0xE8B8706EFB2D2F20ULL, 0x65D1EE3251F9732FULL, 0x36990E18757538DBULL, 0xE1379D2BDCF9FBA9ULL, 
            0xD5E0E44FF1258725ULL, 0xFACDD109E89EFD5AULL, 0xA35ECBDD9230BD51ULL, 0xBF9FD70174F9073AULL, 
            0x1C727A23DB0BB8E6ULL, 0x48733B792828E9B8ULL, 0xB272640EFC1AEE19ULL, 0x9F3755CB14BA12EDULL, 
            0x2B0836E36208CC12ULL, 0x723B3C8F6DD7575FULL, 0xD0480D41669034CBULL, 0xAF56066385E8F1B3ULL
        },
        {
            0x572B2B7E77B34C5EULL, 0x61D7233688BCD871ULL, 0x8052A9E160F41557ULL, 0xEA57BB61BD71767FULL, 
            0x5CD3B883055A90C2ULL, 0x50DBA03AA64928E3ULL, 0xD2A8B32672A7C7AFULL, 0x1452D734B77E8450ULL, 
            0x25B07EE690346BD8ULL, 0x8E532BC907224E8AULL, 0xF4155DE36678024CULL, 0xFB7FDFD3D5F3920BULL, 
            0x1D39A1DFDAB4ACDFULL, 0x2542B58A7CAD1A02ULL, 0x7243B14BD15D4C51ULL, 0x869AFA51B8851C58ULL, 
            0x50547F914CFA6687ULL, 0xF7E43150D128B537ULL, 0xA49DD2329CF89DCDULL, 0x573DC401B9917B95ULL, 
            0x2CDCB496ADA0D310ULL, 0x0DF10BDEBC21E696ULL, 0x66BE5F01A0B887B6ULL, 0xAE90BBAC4117674AULL, 
            0x307F5E284C6D2C97ULL, 0x902A0EB62CF0E3FBULL, 0x2980FB2B30AD7983ULL, 0x2879A9DEC5BBD4EDULL, 
            0x8C37B83C10E91DD2ULL, 0xCE85B43709D34F76ULL, 0xBE65A42F6A0EE7D3ULL, 0x6D935802AC1E13AFULL
        },
        {
            0xA386ABD621AA33A2ULL, 0xF7B501F0ED77B5C8ULL, 0xA7355CAE9012C1D1ULL, 0xDC2CE773321C8623ULL, 
            0x982BFAECE9C30D80ULL, 0xE3445BA46214BFDDULL, 0x678E5986F1A63FEFULL, 0xF33649C9F61B9F66ULL, 
            0xC8F719E8A7784ED2ULL, 0x4AE75FD9A3F67B20ULL, 0x7D69A6234B4348A7ULL, 0xAF905AB7723EF276ULL, 
            0xFB3BE12778D94E33ULL, 0x56A7E6D81F124969ULL, 0xAEA787A6E456E784ULL, 0xC74D8DA148D03804ULL, 
            0xB860861873A8FB4BULL, 0x323256FAD426950EULL, 0x7AD92D724A2BE0BFULL, 0xD2D840C283CC2A73ULL, 
            0xD944EDF0F134F5F2ULL, 0xC1A8A952071BF539ULL, 0x043C96B80E8A62CAULL, 0xA2E632EB05618FE2ULL, 
            0xB425DDADD009E3BCULL, 0x3E9E45D8C484C1B0ULL, 0xBB9B459CC099C3E8ULL, 0x4DE1E1996F91EB1AULL, 
            0x831D72BFC0A0A02CULL, 0x6CE5A2AE5F168BA4ULL, 0x90E25CF4BEC44749ULL, 0x700EAB843CDBF373ULL
        },
        {
            0xCCF88EFF1FAC1470ULL, 0xE7A4AA4003C16060ULL, 0x02632582D2967036ULL, 0x92E1D1A5EB26A3CDULL, 
            0x3506663D5A8CE59BULL, 0x8852F56EA687E007ULL, 0x57641B90736FC31CULL, 0x6E59CB382F83C77DULL, 
            0x57A887F8C7B7F5F3ULL, 0xFB1E0DFBA0F2D1CDULL, 0xB77604279ACCB9ABULL, 0x640F7E153664BECAULL, 
            0x7845C564DA9186F8ULL, 0xFCCA6BA2300F4D38ULL, 0xF3DD2B1218F479CFULL, 0x3DE0ABAE1A7F18C4ULL, 
            0x69169B3706F5CBF4ULL, 0xB98CB68E902E3CE8ULL, 0x4964312C4B99FC1AULL, 0x9F8F17C7CF8EC28EULL, 
            0x1C34A437678132CCULL, 0xD490DA992510ABE8ULL, 0x821BF7B27D1DCF2CULL, 0xC150202C22758BADULL, 
            0xDC0B256661A7D47FULL, 0xE12D807F61804129ULL, 0xB2E8B01C38FB986AULL, 0xF837A679A1BAD7BAULL, 
            0x32921EE1D4763CD1ULL, 0xBE3F563F0FED91C6ULL, 0x16A4B2A173BCF3D7ULL, 0x570EF95592C76C79ULL
        }
    },
    {
        {
            0x9870120127ABF781ULL, 0xBF46E66EC48C957AULL, 0xA4C2B82833512886ULL, 0x33157E18C432AA27ULL, 
            0xB4C6BDCAB3CD4935ULL, 0x696A32B503CB10EDULL, 0x4B911669D2FF9FDAULL, 0x65078892CD9A7868ULL, 
            0xACEC39CD9524C75CULL, 0xE8F8B31A26FFD7D4ULL, 0xF894FC452EED90CDULL, 0xBE5E9BE612009E14ULL, 
            0x184A486AA4F5DE44ULL, 0xC24398DF61AAF996ULL, 0xBA4FD101430E4BCDULL, 0x48E643145067C601ULL, 
            0xC3A8934ADB9EEBD5ULL, 0xF02A58ECA0A473CCULL, 0xE2937C30F2E93FC1ULL, 0x660506E5E7993AE7ULL, 
            0x991271D126B79053ULL, 0x40FEE7A4D33C952EULL, 0x0201E40020DC5432ULL, 0xBA3AB1CE39FF9B70ULL, 
            0xFF8B8F3D28FA9704ULL, 0x5C101CD2D7D987CFULL, 0xD2B5B4683CD821D0ULL, 0xCFC3326070376554ULL, 
            0x99E13327CA114C93ULL, 0x02AB596EFDF9EBA1ULL, 0x1EBFE82CEDB22B10ULL, 0x28E59D79D5C4974AULL
        },
        {
            0x23766FA5D1D99C5DULL, 0xDEB9F158B330AA65ULL, 0xCFEC9C5B01692B45ULL, 0xB4CE95E3648E47DBULL, 
            0xC558C969EB195463ULL, 0xB50283867CB7DFBBULL, 0x498CFBF5B6FF88FBULL, 0x070F15D47CA291EEULL, 
            0x3F1F5067047F3899ULL, 0xD151CEB08458A71AULL, 0xCEDF0E9E9D40F370ULL, 0x29205F09095B3529ULL, 
            0xE765B4C3F8F91A57ULL, 0xC130AE290D92110DULL, 0xE1FF4DAAD3A619CEULL, 0x640B1DF9731CC5F2ULL, 
            0x02D28DDB56AD48E5ULL, 0x0383B5EB59BD8117ULL, 0x7839E2402D8C3A1BULL, 0xB521F05181D102B9ULL, 
            0xB6782AE446D0E44BULL, 0xE3F00D4B63FA9A10ULL, 0x7292CEFB32D9C78AULL, 0x428F484ACBF577F3ULL, 
            0xBF7A8595968CC76CULL, 0xF1FD453EE5E9F16DULL, 0x5916AF76A2140C0FULL, 0x76ED12A4987A00D7ULL, 
            0xD11AFD134B3DCC8DULL, 0xC91B6D65D28D6079ULL, 0x795920521B8E9A14ULL, 0xBE1EE6A294E5B193ULL
        },
        {
            0x02ED9A02EE2D350BULL, 0x6A052307C235D0D3ULL, 0xEF601400C9DBF1BEULL, 0x883285E4A606B175ULL, 
            0x2A35F7A661164CE1ULL, 0xE3AF09EFE2E9E9DDULL, 0xDE2F0F2D3C39F27EULL, 0x07F0EF737F607160ULL, 
            0x36B3C67510800B9EULL, 0x4A46E7D9D733261EULL, 0x036474624F2D3BA9ULL, 0xCF460171A16A42B1ULL, 
            0x25261EFAD805BD49ULL, 0xDE697136B6785AA8ULL, 0xD367429E0798CDF7ULL, 0xFE5885FC1ACB2669ULL, 
            0xCAC0388C5842026EULL, 0x38AB569F98E09558ULL, 0x3C9EE4D0B4D11559ULL, 0xA751EE2E00700341ULL, 
            0x002F1F1375E9B915ULL, 0x867DAF7C75D614EBULL, 0x9BFD4916FF519FA3ULL, 0xC0C14E7B527E5F8EULL, 
            0xE5C95A4300E177F2ULL, 0x9452D3C779B6ED7EULL, 0x3E5917955243E815ULL, 0xA7203F91EBD3B43FULL, 
            0x4305DA8DF251AAFAULL, 0x8AA42C9D9AF5E4F0ULL, 0x3B08E61EEF52014AULL, 0x15323876B0C935B5ULL
        },
        {
            0x3BF742CE96729AC5ULL, 0x29544D8E62D40425ULL, 0x811B8E0CAE316E40ULL, 0x85FF101E5F4CF13FULL, 
            0xC652443B87BFDECDULL, 0x27E5DC9BDEB40C7FULL, 0xF5E91AE80A778C6EULL, 0x732940C968312428ULL, 
            0xB497096F0916ABC5ULL, 0x7136EFBE00831E7AULL, 0xA03EC8B826424CF5ULL, 0x78BCE2A55B5E2465ULL, 
            0x50A5C5AE88F0B709ULL, 0x863D6C1524AA9905ULL, 0xD792897AA08325C1ULL, 0x15C73FEC880719F2ULL, 
            0x4C26C626CB036E85ULL, 0xB5C1B26C58EE17FDULL, 0x43D1C6B24EC8AE02ULL, 0x8B14725BFED4ECC3ULL, 
            0x3E70D37228EECE7DULL, 0x22467485C69B0FF5ULL, 0x25E605593F3ED93AULL, 0xCD05E2ACC43BC5B9ULL, 
            0x8A56D58672451364ULL, 0xB865DABE0E992815ULL, 0x5FFD1B67E1C9BFCCULL, 0x083334DC429720FFULL, 
            0x823749E0C9BC5F44ULL, 0x73ECD63B302A8F16ULL, 0xD1D4C83C8598D28CULL, 0x23E50DC32018D3CDULL
        },
        {
            0xC4CAE0865A0B4E53ULL, 0xBBC4343D37E2F7A6ULL, 0x8B94D9A4D2BDAAB9ULL, 0x4FE53FB0B41A207FULL, 
            0xD45A2ACBE8E5E242ULL, 0x7D1BF63F50B23BA0ULL, 0x7DE025D2F7C5182AULL, 0x411E49ACB987EEB9ULL, 
            0x28172F5FC371BFBFULL, 0x911185E693B8D963ULL, 0x296768D87DB36CE3ULL, 0xF12631831A7EE9B6ULL, 
            0xA2A716AC4BFCF217ULL, 0x2E52C63C2E3115BCULL, 0x450FA7E8A3D5707CULL, 0x9D12FE5287C7F6E7ULL, 
            0xDA2EABF4C223F735ULL, 0x520804A0F02CBD18ULL, 0xFF59D03B58B5821CULL, 0xF5C3DE6AE1C2B7B6ULL, 
            0x3AF4D357C28AD762ULL, 0xC954346FD774E9B2ULL, 0x523D66D62F225FE3ULL, 0x647CE8A3ABB94DDEULL, 
            0xCD915EB414CF658EULL, 0x920382042E5A7A8EULL, 0xD9651CD9BC40E2C0ULL, 0xB12CFFD6280F885FULL, 
            0x8F02C74B04767332ULL, 0x1874B19985E50885ULL, 0xFD62369E288E94E8ULL, 0x1ECF90F48C901496ULL
        },
        {
            0xE321FDFE9CD66195ULL, 0x8C8CA0596FCBC1F1ULL, 0x4FC82B7887182D29ULL, 0xB2F65F6EF957D35FULL, 
            0x8E5E0052B7410826ULL, 0x718675C5881853D0ULL, 0x02B89D9A5B5A5FF6ULL, 0x254A63719D1EA8DBULL, 
            0x7DA53332F4B77295ULL, 0xF53708AA989BF399ULL, 0x95A61D8B06EE85AAULL, 0xFDAA18ECA5BBA8DFULL, 
            0x02810183FE42DB81ULL, 0xE67B57FBDD7090ADULL, 0x70FA8C778DA8020EULL, 0x2C5D53F639F61389ULL, 
            0x86C2DD4571EA5656ULL, 0xF05CE9BFECF2073CULL, 0x3A431CC93B1DFED4ULL, 0x0AAA754CAFDBBC95ULL, 
            0xD88E122B35633025ULL, 0x3BD8ACBFCA590A22ULL, 0x791BBECD133FB12BULL, 0x6F5B943CABE070B6ULL, 
            0xEE5DA122F35289EBULL, 0xFE9E9828AC215EDBULL, 0x415DED6668294EA4ULL, 0xE33AE4666AA7D6B0ULL, 
            0xD5063F40538A23BEULL, 0x322357C790ECA6ABULL, 0x23CFD2C1D86756B5ULL, 0x3298E01B7E096283ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseEConstants = {
    0x9FE570F828AD9DE8ULL,
    0xA439AA6B29916B25ULL,
    0x4F6CC6B59EF7134AULL,
    0x9FE570F828AD9DE8ULL,
    0xA439AA6B29916B25ULL,
    0x4F6CC6B59EF7134AULL,
    0x1D7A76B4C9856EC6ULL,
    0x0D47AE9407A4D89FULL,
    0x5C,
    0x6D,
    0x63,
    0x14,
    0x12,
    0x77,
    0x48,
    0xAF
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseFSalts = {
    {
        {
            0xC2BD905149F126E3ULL, 0xB2CE72C33DD8C6A9ULL, 0xE21D079639B07743ULL, 0xE19795F03D4A7BBEULL, 
            0x19B556447463CD8EULL, 0x0ABA140EC28DCB5DULL, 0xAB847D9C68636A39ULL, 0xA1C01ABF0405F9A7ULL, 
            0xC4186370B84DF8EAULL, 0xFFF18F468D4870CDULL, 0xC3860D080B0C9FD3ULL, 0x5C53499F6611EC23ULL, 
            0xDDAFC240B7C67276ULL, 0xDD9D22743585B38BULL, 0xF13B017EAE9B9BBFULL, 0xFDFCD853884AEB5CULL, 
            0xB86577A69699CB99ULL, 0x9FBF5C3E9AF4677CULL, 0x97BC9973450AB5BAULL, 0x252816FA0D305A22ULL, 
            0xCAA5F697B7FC7B20ULL, 0xCE9F47E607B11795ULL, 0xE3EED1FCDFAA4071ULL, 0xC66AADF5CF870499ULL, 
            0x3969BE40B0FA5A70ULL, 0xADD34526DA2731B6ULL, 0x81F42AADBF40BB3BULL, 0xEADA037C773DBB9CULL, 
            0x3DB208AFDBB2BFD8ULL, 0x153110B08845BC9BULL, 0xDD550049D80C2D53ULL, 0xCD398D2380C01275ULL
        },
        {
            0x488ECBE3D3F558ACULL, 0x85D76D0E5A8919F7ULL, 0xA2EB1578989D1E66ULL, 0x04F91301A160B324ULL, 
            0x15C485D57D2BEF69ULL, 0xDA550D8A4E93585CULL, 0x8BDB3EC5ED9D7028ULL, 0x84733C471A58AF63ULL, 
            0x8B7F2D34CC286738ULL, 0x6A5B23E5B2FB7202ULL, 0x0C04010D9C40DCF9ULL, 0x153EB932F9DBA25BULL, 
            0x345BEA175FBC1385ULL, 0xFD6A18CAF59610F3ULL, 0x26B4BB5D8E446322ULL, 0x072CDD1B64BF6F79ULL, 
            0x9CA0B6CC8DBF4024ULL, 0x19289151B0C8A504ULL, 0x165A9FF64E6D3A20ULL, 0xB1E0FE841D70C345ULL, 
            0x948A055F967D5C88ULL, 0x2CD3E7D820E14FEAULL, 0x5C633AC31087F70DULL, 0xF2E1C34871C79B26ULL, 
            0xDC5A74877EE28FCBULL, 0x64AA38499251D8A5ULL, 0x35862349A3B6198AULL, 0x6AD1F24BC74DBF82ULL, 
            0x0B370875BB37AA67ULL, 0xE22195D2E9FC425BULL, 0x4951A265D1A566A7ULL, 0x60C0BBBEFBD08C47ULL
        },
        {
            0xC59E1E280352B83AULL, 0x7A556EF5918E1B39ULL, 0x9973D516B5C1F9C4ULL, 0x2B9E15B135271BC0ULL, 
            0x0BA92E40B00E7EC5ULL, 0xA2F1ADF4D563A2EFULL, 0x7CA781887BF36591ULL, 0xB31DDD68551D0F37ULL, 
            0x976056530C49FEAFULL, 0xA4D33522753F45DBULL, 0x451357AAACC15EA9ULL, 0x438002E0E7DC0CF7ULL, 
            0x9D7F912DD9DF5881ULL, 0xFB2207A90A097FB9ULL, 0x5CB05A5830638176ULL, 0xFA829DE93C725B3AULL, 
            0x3857C43F74CE48ADULL, 0xA9791D61D14CF94EULL, 0x4A0ACB5143CB0399ULL, 0xDE0D7FD15B4CD8A2ULL, 
            0xBE6ADAA74D4DBDCCULL, 0xBF9CCCEBB99F250FULL, 0xED2BAEEE45CC9ECFULL, 0xC073D10AAC1D5230ULL, 
            0xE9E7FDEEFC932861ULL, 0x129E7F3F26FCF8C6ULL, 0x4562401F941C60D6ULL, 0xE0347159E9A430C5ULL, 
            0x140478D6232FAA9AULL, 0x2CEB0FE85F085CFEULL, 0xA1C5CFEF19C561D5ULL, 0xD9D572E1BE6F49AEULL
        },
        {
            0x9B2092624371C0F6ULL, 0x7435F76C345C8EDEULL, 0x86C673DAFCAF55CBULL, 0x11E601134B6D8E56ULL, 
            0xAB91E435FBC91167ULL, 0x48A794AE943C1F6AULL, 0x934650D8542DAB68ULL, 0x9B5F1F4D0BCF7411ULL, 
            0x03FD6B1F1FCD9DB4ULL, 0x107474E4165E8F3AULL, 0x8EF73C02F1DA41F4ULL, 0xF4BD3CBE3CD951FEULL, 
            0x0E3D0D717870BC45ULL, 0x447BE732DEF92693ULL, 0x62D1421B91F8682DULL, 0xC8D771AC91DA17D5ULL, 
            0x544C7C3B703E2AFCULL, 0xDFE8E41BA6809E10ULL, 0xD20A5C189E82F6D4ULL, 0x6AFF927DA5C6EF8FULL, 
            0xC837642049A38EA7ULL, 0xC754EDA84BF958F2ULL, 0x6F1644AA01A0FDB2ULL, 0xF098B4AC6F5846CBULL, 
            0x829E94E45BB400ABULL, 0x6D431F68DA64A6A8ULL, 0xCB164183CD11763DULL, 0x1CB6ACEE797B7692ULL, 
            0x1D4FCA1A929723A5ULL, 0xFB2D832CC031A3F9ULL, 0x401D5C047C4AE9E8ULL, 0xF61C81D266ECED88ULL
        },
        {
            0x70D5229C8C4742B3ULL, 0x54ECEDD3EE9417FDULL, 0x69CC289EB95EF272ULL, 0x6E0BD0534957C514ULL, 
            0x50B84F7891638101ULL, 0xE034B237DFA34798ULL, 0x2CBE77668BE3C83DULL, 0xA892A39A70F7A437ULL, 
            0x09E93391836C3A26ULL, 0x9406C474D96CF7B5ULL, 0x0FCB70CC9A66045BULL, 0x77D026C6D692A0F0ULL, 
            0x211A8685DB0EB65CULL, 0x69BA3B1A01D20771ULL, 0xAAB3E1FD6BCB379AULL, 0xADC4F6F039492783ULL, 
            0xDC64620CF54EEB78ULL, 0x5C8118A619A263A9ULL, 0xAF13F78EEE666E66ULL, 0xCAFFE9A8ECA2DF02ULL, 
            0x37C63E2D230AD09BULL, 0x3FF3A56B5F9952C7ULL, 0xAF2086CB11ACA3E2ULL, 0x4A44AF71333DF6C4ULL, 
            0x99062D1E68F2BFB2ULL, 0x9E2ADE9154192407ULL, 0xD025633590E9EB46ULL, 0x886DD9E6C39D054DULL, 
            0x4F2CCBA109C0D7E4ULL, 0x4ACC477B67AA39C4ULL, 0xD7253C7D23FED668ULL, 0x6B2DBED7CF6A4090ULL
        },
        {
            0x157169B6DC0854FDULL, 0x9A73E354649925C0ULL, 0xB366AE2267172507ULL, 0xB61AA4719A8F95FAULL, 
            0x31347BA94313110EULL, 0xB7C6D6EC77DB9B8FULL, 0xEE501A321B7B21E1ULL, 0xE1D34FF7D5874A57ULL, 
            0x819FBA8FFFB0CC9FULL, 0x7C7E5F46C773AF5BULL, 0x358815D76340510BULL, 0xB5F93CAB504D7672ULL, 
            0xD055744ECD2E137CULL, 0x93DF10C2CECF11A8ULL, 0x2ECF3C28902F54A7ULL, 0x1F8670EED12BDFACULL, 
            0xB375F4D15B234354ULL, 0x6655A0CC4FC762FBULL, 0x2CF623C5E2EDEE0BULL, 0x402209BFB59A0AB5ULL, 
            0xB31FF66A02C5CAFFULL, 0xEB4A3C23C0F40267ULL, 0xB45A9D568984EF1EULL, 0xBC88C89E9899487DULL, 
            0xD2E39FCFE214F324ULL, 0x2013BB8412C4272BULL, 0xD981DBD13F6B6D83ULL, 0x4C1FADD2F453D913ULL, 
            0xA813E23122F33C12ULL, 0x1DF788E1D7452B47ULL, 0x619A5733F5205428ULL, 0x4B8CB8F0968C1B49ULL
        }
    },
    {
        {
            0x6DA69DEB00CBDDADULL, 0x8734008D159D0774ULL, 0xF7F5F26397C06D16ULL, 0x8781727F9731791EULL, 
            0x3E3EA64214A93AD6ULL, 0xC71A0BDCFFF8D9F2ULL, 0x3BA678BBC56BA23EULL, 0x71A62F22BFA33667ULL, 
            0x92FAA854C0083B2DULL, 0xB4DF8C7DB372F81BULL, 0xB810E4E103AA191CULL, 0xBF67326A4C59BFE0ULL, 
            0x6EE5DCDE59C07956ULL, 0x09CDFE302B56FA19ULL, 0xCDD43D94A00AD826ULL, 0x951678197F77AFAAULL, 
            0xBAF731DD1D579F68ULL, 0x250433953BD000C1ULL, 0x0B02ED3E47C81C9BULL, 0xEBC82C72C016B7C6ULL, 
            0xFB16A1D0D7EC8045ULL, 0xF639F3915C074F8AULL, 0x5353CA01E3E09E89ULL, 0x285EA03A228FBC1DULL, 
            0x14C1B24E00AA35C0ULL, 0x348DDA38650E966EULL, 0xC58B4F03AB9ED148ULL, 0xCBD4EBE06723DBAFULL, 
            0xBE5416D66E5C1925ULL, 0xF07DA9F0725DAF1AULL, 0xFE5EC736E4164E30ULL, 0xFA380ED627CBECBCULL
        },
        {
            0x4F1087F79AE3E6FDULL, 0xC692F5F08D81BB7FULL, 0x2B027C7B88AC492AULL, 0xC05FEA0EECC7C6CDULL, 
            0x40AE2552503A86BAULL, 0xCBC2B56025D8318AULL, 0x176C80D4D2D5611AULL, 0x87AEA9FF41A24B90ULL, 
            0x40A4273DF2D6FF02ULL, 0x075251FB96BD040EULL, 0xC1CB01B66C9A2097ULL, 0x4386916E14C6C46EULL, 
            0x58D6529093D30045ULL, 0x702B0A102AD000A6ULL, 0xB099AB1AEB60001FULL, 0x28C87AD14673FF46ULL, 
            0x95E47FFA7615FB9FULL, 0x7D6F9449CA5D073BULL, 0x92CC473E2DD289FFULL, 0xF9FEFF56E8AE245EULL, 
            0xD73EFCA8B9D361C2ULL, 0xFBACE585E67A0C29ULL, 0xD729DDCF5E4BC34FULL, 0x54C9F0B7C2101CF1ULL, 
            0x52B8412A95EF0A97ULL, 0xF3E7AABA6CEF9756ULL, 0xE2B773FF70B50AA6ULL, 0x515C17DE7D3C07C1ULL, 
            0x55C53D7936CEEA88ULL, 0x7B8B6555CDE106A2ULL, 0xEFAECFF996A690E7ULL, 0x4C4F379BCE97CA60ULL
        },
        {
            0x77B98A9AABF8D0C2ULL, 0x5321B62EF86508DDULL, 0x36926DF5D7095F5AULL, 0xC192C858B0B16EE9ULL, 
            0x29F4817723080333ULL, 0x889B6BE5ECC34CB3ULL, 0xF3D303543C9F8120ULL, 0x78BF64172B89851FULL, 
            0x0D4A29E7ABE671F1ULL, 0x939ABBB00F3E8B8EULL, 0x38770E3F2546BE58ULL, 0xDCCEA76C5951F7B1ULL, 
            0xCDB7920D99022112ULL, 0xAE8F9D958EA51E9FULL, 0xA58D8B28677DDC3EULL, 0x113EDE49159EBABDULL, 
            0xED9883B2600C7CA2ULL, 0x90D52A4AE9750970ULL, 0xEEFBB6ABB998DFA5ULL, 0x6CFCC1F1E3FED80EULL, 
            0xA9F4B2A3D02D0245ULL, 0x0F4C85E37FB858B3ULL, 0x828F8FCEA8FFEC23ULL, 0xE5DA98F162F62AB4ULL, 
            0xB6A3610DC71DCDA5ULL, 0x1D74E7DDBB0CE7A0ULL, 0xC3E0B939063974A4ULL, 0xE6E3E7658CF31821ULL, 
            0xEB631840FF6C5C07ULL, 0x7DA9CADC22D739ADULL, 0x320D2DA87AB0014CULL, 0x33D255125F5F38D2ULL
        },
        {
            0x45E0C082CD69BDE6ULL, 0x514BB36F22F41B61ULL, 0x1AF2E023075CFB3CULL, 0x191749584B73DE5EULL, 
            0xA8DA4CB258483931ULL, 0xC446A982DE0507FFULL, 0x7E6D20EFBA132FFFULL, 0x656F9F0263C52742ULL, 
            0xA138C65B0D3A22C6ULL, 0x97B70961D24AE42AULL, 0xEFAF5393224EE50EULL, 0x09042FBC47CA5A1FULL, 
            0x204B2D03D92A00F8ULL, 0x7C1E9321A775ACC4ULL, 0x7878A47C1DE0533FULL, 0x5C85553004DD40B2ULL, 
            0x8ACA2C6409A79807ULL, 0xD61107F95C602347ULL, 0x525DD1181FAB96BAULL, 0x6C711FE984267B12ULL, 
            0x9D9CC1AF8CFB3017ULL, 0x3DD186101E4BB130ULL, 0xAFE5928AB5478087ULL, 0x3AD720FC80FB3C93ULL, 
            0x45493674861381F9ULL, 0xA297D59D9D6C674BULL, 0x4561136C796BB821ULL, 0x4E13D390C6245C43ULL, 
            0xC46DF499A337A1BDULL, 0xD48972B883AE7B8FULL, 0x50DADB4929CD696DULL, 0x279929E0C13A0411ULL
        },
        {
            0xE3D01A07ED890D94ULL, 0x5496815B3448FDE9ULL, 0xDEDF2CCA61EA236FULL, 0xC3CA572AE9C7FD7AULL, 
            0x08D503C1079C9141ULL, 0xB59CDD79AC01E3B9ULL, 0xB75972DA63899674ULL, 0x44F98DE78F347266ULL, 
            0xD69EAE1F5FE86BDDULL, 0x28092E774F00166BULL, 0xA6EBB6590BB6F325ULL, 0x72D4864CEC684390ULL, 
            0xB2AFF1E15A89F7C1ULL, 0x0C58827B1EA19A7AULL, 0x92033E0918B95684ULL, 0xC198AA532F17DDE0ULL, 
            0x096BC5A4617007D0ULL, 0x2A8F952E1EB20E56ULL, 0xE24E16BB36F291B3ULL, 0xEA7365D843D710D9ULL, 
            0xB5A5667FDBBC2257ULL, 0x64BE2E5F56A7BB0EULL, 0x37009F1E678157BAULL, 0xBE9CFA1C38038245ULL, 
            0xF0A18EBFC454DAD6ULL, 0x1EDB24B87ED9E51FULL, 0x2EB5B85D355180AFULL, 0x393E42312A05870AULL, 
            0xE1E823880AF21481ULL, 0xE49D61DC73F744F3ULL, 0xC8EDA08363F86BB6ULL, 0xAF4CBF7C03BB41F3ULL
        },
        {
            0x3FC29545D5C3D1EBULL, 0xB0417430F1FFFF4EULL, 0xB6F0C032FB981CBCULL, 0x6F385111FA3B879BULL, 
            0x4CD2937E0C78FCF6ULL, 0xCC7DDDD4B8D297D3ULL, 0x0440CDA0D0298F16ULL, 0xF00083AFECC982B8ULL, 
            0xAC0FCFB514ED79E6ULL, 0xD6819CC98728916AULL, 0x37866BC4045139A3ULL, 0x4870F55FB2C948E2ULL, 
            0x476CCE6D9C91200EULL, 0xD227024AE7F5DE87ULL, 0x416B1164FDC17C8EULL, 0xCF30F670036123B7ULL, 
            0x6A4880DB20FD6069ULL, 0x9CAFCEFC0F8B32D5ULL, 0xAD9473D5C9EE5AF5ULL, 0x13C5B04B5BE22169ULL, 
            0xFAF79545797437F9ULL, 0x4DBCB0F7CDE8A15CULL, 0x18EDEA9850F56B5FULL, 0x9F6B248F8C112DE6ULL, 
            0xCE62F79CF2FF8336ULL, 0x2845D109521E500CULL, 0x3F0E70AEBEC25838ULL, 0x48C5C8CD63830686ULL, 
            0xA03767F81BD7BCB4ULL, 0x37BE7AAF359D4A7DULL, 0x288DEFF8218AC0DEULL, 0x33A9EA0DC640AB68ULL
        }
    },
    {
        {
            0xC11154D83442EF93ULL, 0x8D8599A957F14DBCULL, 0x0274816C6C66144AULL, 0x97AC133B350C3DB1ULL, 
            0x1BFD597A9158709EULL, 0x017033D8F6AAC89DULL, 0x8111451799F86A1AULL, 0xEB27FBF18B7D8D0DULL, 
            0x3AF3854DDC7F9544ULL, 0x6E7C8A87EB544AF2ULL, 0x28E6500A3893A931ULL, 0xE2C5394075DD8B64ULL, 
            0xEE82EC06C75002D5ULL, 0x86568D284018F823ULL, 0x20424809AA7ECA28ULL, 0x93BBBFF1D5EF947FULL, 
            0x9175BCB10BB9B624ULL, 0xB3027B555EFD93C6ULL, 0xD53886765F689628ULL, 0x0A5F6C51F90583E6ULL, 
            0xA2E8A7AA6C656427ULL, 0x61689E12BA9BA1C2ULL, 0x8A481AB08B896118ULL, 0xD8166902AA75B8DBULL, 
            0x6444CF15A2A5DD4EULL, 0xBE9DFB3411928002ULL, 0x6E64C69E03E45391ULL, 0xB226A286F04135BBULL, 
            0x3F3396DD55AE37DBULL, 0xC7C965DCF5D22EA2ULL, 0x19852C9CFA5143A0ULL, 0x9FA9BECBE355B6B6ULL
        },
        {
            0xFA97AB771395EDEBULL, 0x5BC2D280052D7011ULL, 0x7C14209BFE2F1C43ULL, 0xC5AB90C20A2F7291ULL, 
            0x4981CAB6CEA48E68ULL, 0xB12CBE9FD0B398B0ULL, 0xD85AAED01BE708A6ULL, 0x8DE02E7DDEEE1825ULL, 
            0x257110AC509649F3ULL, 0x1D7D6832A55FEA97ULL, 0xCC482B455AB4F93BULL, 0xDA263B71C1B896A7ULL, 
            0x6DA6406D553CBA8AULL, 0xF8DA35C4FF5772CDULL, 0x1F367742A3582874ULL, 0x42D22DD12201F54AULL, 
            0x0F208277CDB9E26CULL, 0xF265232975FC477AULL, 0x32B6710235499350ULL, 0x9512B49F927222EFULL, 
            0xC9F4938380BB2698ULL, 0x4464EFC0483B9404ULL, 0xC4108B21BECE8D85ULL, 0x4FB7877B539A7A1AULL, 
            0x8F36437361E82E1AULL, 0x0A273BB46816844CULL, 0x692AD2F3EE20A905ULL, 0x4ECFE353153A18CBULL, 
            0x724D27ED56C3BDB5ULL, 0xC6C528396866376EULL, 0x63E8FBCBC9725955ULL, 0xE8FEBBFAC06CE55BULL
        },
        {
            0xBE531B90D1B4B701ULL, 0x549B6C7E06613C8FULL, 0x1DC324BFD810074FULL, 0x7F7FC98A505F22D4ULL, 
            0x9D937C6CFC9E9190ULL, 0xB167F45D57973E12ULL, 0x2E780ED03C0A5CABULL, 0xCB5BF957A66C0CF3ULL, 
            0x63E87F782D846675ULL, 0xE9FCF646C08FD96DULL, 0xE6B86FAB66453D34ULL, 0xC48B3BAC06E37556ULL, 
            0xD8CE08267D16A3D7ULL, 0x92AF635960A98BA9ULL, 0x65548BC6DAEA1A0EULL, 0xBBEC0E721233D903ULL, 
            0xB03424C5B156FC38ULL, 0x51571A7342A394C7ULL, 0xC04973911BFE80D3ULL, 0xA06760860BF12A65ULL, 
            0xE803906D99FFF24DULL, 0x11F7592CB53C1E78ULL, 0x6EA6840FF780EFD5ULL, 0x7E9F748ED4B51E1CULL, 
            0xC07BCC94BCF6CE4DULL, 0xDDB6C43C1387E022ULL, 0xA7CC0C4AFCD81733ULL, 0x8DB9F7DAD58BE4DEULL, 
            0x5C42942CC70534A0ULL, 0x714C675A881D323AULL, 0xF7387031E8881F2EULL, 0x7EE2332D6B4B87F0ULL
        },
        {
            0xE7D078C7C41A888AULL, 0xD465534ACDD0AFDDULL, 0x5DECFA515D2E9532ULL, 0x407E357049688924ULL, 
            0x6C042AF17146A1FCULL, 0x943270BF0776F363ULL, 0x70058F5C67EA5F43ULL, 0x8506FADE3121482CULL, 
            0x7F563FE4D55D076FULL, 0x19A9A5324E0F98C0ULL, 0x11911BB529C7D2C6ULL, 0xE655A3EA1931DF8AULL, 
            0xFD40105E2AE3184EULL, 0x6F4CC9797AC26E33ULL, 0x9F421BD77A73620BULL, 0x3BCABBA44DBA938AULL, 
            0xA9371DF7E2DB2F27ULL, 0x7FB88416470B45C4ULL, 0xF60DD2F433703A13ULL, 0xE3659AEFB505D33BULL, 
            0xE9E8982CD8FE34D2ULL, 0x18C854532A80A60DULL, 0xF5E6D9F84C375575ULL, 0xA8D122D3090DD732ULL, 
            0x656BEDD1DF404996ULL, 0x00FDC2889078044FULL, 0xACFA6407FB085239ULL, 0x99590B8193FE23B4ULL, 
            0xD7DE1D3EA6612DE8ULL, 0xEBAB1BC59A0B76A4ULL, 0x30D59EC13C506D66ULL, 0x770BF0A4449EA6C1ULL
        },
        {
            0x5D7E529655C5E80AULL, 0xB56C3F0C29C114FEULL, 0x0843A0D84A638C80ULL, 0xCE3DF9A5F6BD3BD2ULL, 
            0x5427CE454B8FA1C2ULL, 0x22CD7D543BB5C190ULL, 0xD354804D67243208ULL, 0x8FDF299C2CDBD845ULL, 
            0x3A788EFA0C17DB2FULL, 0x6BB783CBB03BFE55ULL, 0x689061266EC76A06ULL, 0xE08A63D9D6A9D6A3ULL, 
            0xFCBF82C61E11A852ULL, 0x45AC6E6E29BA9AF0ULL, 0x9F7E0C2CECA1BBB2ULL, 0x31FE4A80A7054889ULL, 
            0x086888F7BF8CD847ULL, 0x6ECECEE2EFBD7838ULL, 0x020743219058BCE6ULL, 0x27A6BD69151DA094ULL, 
            0xF621103FA896E5F7ULL, 0x22B252A503D787CFULL, 0x2D979303F4E4831EULL, 0xA72638FD44ABEB75ULL, 
            0x1D8B0DB7F6AAF9AFULL, 0x6ADAA2A0D367D815ULL, 0x3D250A92A101BF59ULL, 0xE57B02733FE29483ULL, 
            0x7970386C02E14551ULL, 0x53C3F54DA12D40ECULL, 0xD862A27CEE178AB6ULL, 0x18C1B0B7E7FD5D07ULL
        },
        {
            0x82A7D049CFA91367ULL, 0x498B4CC41472F23BULL, 0x2F7C08FA41456F17ULL, 0x94332CBE9A1C4A2DULL, 
            0x17EE935F3F3E7329ULL, 0xFE3D7F38EB93EB93ULL, 0xCA89E27E175A7735ULL, 0xE104F0AE0F4C7514ULL, 
            0x1550993F05138AC5ULL, 0x1B26063FBCB5D8D7ULL, 0x908335BC21D97E42ULL, 0x514DE66E07672CD4ULL, 
            0xC1AD81BC9BD97B08ULL, 0x47B48523B726E335ULL, 0x75955405BFD86818ULL, 0xE9F4AEF965627D9FULL, 
            0x3790392BACEB9948ULL, 0x69F44468444ED141ULL, 0x3BD081D5ECCB09ABULL, 0xC6B552A0E3BB423FULL, 
            0xF68E6254D97BE972ULL, 0xFC441897DEF3691FULL, 0xD7869D8F03E9875CULL, 0x8B5D901377AB3A1AULL, 
            0x68F2931D4A7B49ABULL, 0x629B718B8FCAC67EULL, 0xEB48FBBF6FA58048ULL, 0x22087D6FF765B015ULL, 
            0x545CD1BEDA465D39ULL, 0xE1F2083FA391E8C8ULL, 0xF6DDBBA9FEE62904ULL, 0x7330632BAA4D32BDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseFConstants = {
    0xE978569BCA5DDB81ULL,
    0xDD4E6EC3B410A926ULL,
    0xAF9F91A7FF358337ULL,
    0xE978569BCA5DDB81ULL,
    0xDD4E6EC3B410A926ULL,
    0xAF9F91A7FF358337ULL,
    0x3CE71294E99BA244ULL,
    0xD5199D272441ECE8ULL,
    0x83,
    0xA7,
    0xC2,
    0x90,
    0x1B,
    0xD9,
    0xD0,
    0x22
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseGSalts = {
    {
        {
            0xDE2CA1C716249F7EULL, 0xB338C7116E2788E2ULL, 0x60DF31F4CE8EB517ULL, 0xABFFD71D8EC46C57ULL, 
            0xFB8FEF63F780795EULL, 0xD1F7BEA77D8F36A3ULL, 0x6D4FF86165EA9E61ULL, 0x06A3123A911DA351ULL, 
            0xA3DE13BAFEB6BA8BULL, 0x7A9CCBBB1369F28BULL, 0xA0F62B4EC2DFFCE4ULL, 0xF03EB55B2F4A2147ULL, 
            0x868B38D31DD92F59ULL, 0xB7096B9B68D86648ULL, 0x9597D46DE5DFE38CULL, 0x0CBB02EBB5731A76ULL, 
            0xF0C45DB4F8DEAA0DULL, 0x71189F3535A258B8ULL, 0x6A565B1B53A0BC94ULL, 0xDB2DEF4BF6F88A13ULL, 
            0x3C95E3EF628311C4ULL, 0xBB5D314B266C47F6ULL, 0xD7B4BE1E4C594131ULL, 0xF845AF2995663889ULL, 
            0xFE17EC702131D888ULL, 0x70EC3205BD04D648ULL, 0xD46D06CD1E62455FULL, 0xB2A8F9F552DD5DE3ULL, 
            0xFB657C0512C03CA6ULL, 0x0002A1F2034E48C7ULL, 0xD16BB91096C8E4F7ULL, 0x566059265750D8B8ULL
        },
        {
            0xDDAB964C0EAEDC76ULL, 0x904904CD84DF48A6ULL, 0xCEA0288786D17BDBULL, 0x45ABA0E826A93A50ULL, 
            0xE82E12230727C3CBULL, 0x9A3391CF9BA2CA86ULL, 0x701D38E7A73C3F34ULL, 0xCDE55BAD411FAFF2ULL, 
            0xE6891E02029BB52CULL, 0xE6BFFA55374797EFULL, 0x9FF309CEF3898777ULL, 0xB1C883068EFD1CCFULL, 
            0xAF56CC2451CA2BA5ULL, 0x7D68712C63546478ULL, 0x572AE43EAC52B8DDULL, 0x3AC394C6CB144996ULL, 
            0xF6B37A2232633B62ULL, 0xFC6C286BB7920A8BULL, 0x90655753BB44434BULL, 0x42C12670A8807C51ULL, 
            0x5F3EA7413F1F6C2BULL, 0x906CE5737D34DCF6ULL, 0x4346E7FD1C019030ULL, 0xD9CE93C68994B3D2ULL, 
            0x1FF6441126FE1574ULL, 0x6FEB4F6FBE8C041EULL, 0x154C545F77D5934DULL, 0xCF7FA341BEE2CB21ULL, 
            0x2BB11898E37F96E6ULL, 0x5F01045EC58875D6ULL, 0xC600EEB199E72351ULL, 0x0935F61BFC9941F3ULL
        },
        {
            0xAF428BB8944A28E7ULL, 0x21A4DCE1B4824837ULL, 0xAC49A420761F6C95ULL, 0x35A2F5E4B467442EULL, 
            0x9C515701340949D0ULL, 0xFF72DF2356E68F2DULL, 0xDA4494D4CE76F058ULL, 0xB1497EBCAA36EC2AULL, 
            0x459CC4BF51B9B354ULL, 0x3533F18C144065EBULL, 0x3190A2AD1BBF57C2ULL, 0xA4422CFD4BF257DEULL, 
            0x65BF4949C41264B2ULL, 0x2F096B38B7ED4F8CULL, 0xEBA1C4CD4A591A1FULL, 0x264C7E0D287A939DULL, 
            0xC611654A0577095DULL, 0x128C867D6CE2183BULL, 0xFE84FE78F3D44505ULL, 0x8C0277A8258579FEULL, 
            0x7F5DFD9E164B2594ULL, 0x2F2F8A820EF2A11CULL, 0x3F5A2DCCC6975387ULL, 0xEEF3CBCBA93345E2ULL, 
            0xCF5F065315BEA0ABULL, 0x23E45BA9BBF83294ULL, 0x3DAD08F1E0CBBBE7ULL, 0xAF58C811AC3DE5C4ULL, 
            0x001376AF36B86946ULL, 0x198DA62832F2E01DULL, 0xF2849DE6F5441438ULL, 0xF991819959890771ULL
        },
        {
            0x14EE2051CE756C37ULL, 0x7A04A6A44E31B9F2ULL, 0x31D54E36DEFD8E3FULL, 0x08E2627EBED017DDULL, 
            0x1CB365876E88CBA4ULL, 0x8226633164C09973ULL, 0xCEACF46E036306F8ULL, 0xF2C71E7041A5A2F9ULL, 
            0x664AAA8E10C0EDEFULL, 0xCB587CD4FB4747BBULL, 0xF8AEEF3E2C8FD511ULL, 0x8B905798BBDD78C4ULL, 
            0xCEB8BEB8A59F7793ULL, 0xC497A48322723EADULL, 0xD6258A4B0224F46FULL, 0x80E63D2DB319E552ULL, 
            0xBF175A370BDC7A40ULL, 0xE95964180BABD24EULL, 0x7E8ED5116348D26AULL, 0xBC761078CD073DAAULL, 
            0x9858E7B302E843BCULL, 0x8679A951E333E436ULL, 0x121B93989305814DULL, 0xF383E11B376AC769ULL, 
            0x11FF7C71D12DBBCBULL, 0x228B70DED80B575BULL, 0xB4054048D9AA9FCDULL, 0x83D63578C6E3C818ULL, 
            0x6F8E22AC00A21503ULL, 0x29BDD3E723394CADULL, 0xCAF4DCBA1D55F31DULL, 0x9D546CD0A869F604ULL
        },
        {
            0x41678A8559B1D30BULL, 0xCD76C3F5F9E54131ULL, 0x8629AE8E2A5C5B87ULL, 0xF7606E395DA94202ULL, 
            0xD9B5F724E639EC5BULL, 0x9F2318A3B7DC89C6ULL, 0x4CFFA42E0FCA60CBULL, 0x23393CDAB16B21F1ULL, 
            0x2D9BC300A2FB0A2DULL, 0xC2DDA7B60AF1EB9DULL, 0x7DE5B6B06514324CULL, 0x0CC3C5C5EDDCDCDEULL, 
            0x40C13503FF52CBCDULL, 0x8817957715BC2803ULL, 0x8EC15277359969E5ULL, 0x11F7487B7E9BC325ULL, 
            0x959F2ABB4E67DD0EULL, 0xA73585E972C9E03AULL, 0x8D73527EB9B03ADFULL, 0xA6ED1E0BAF24973AULL, 
            0x86FE5D43BCB58155ULL, 0xAA41D1362D4C666EULL, 0xF8F486F4570303B9ULL, 0x32DEC5F61FCEBC1AULL, 
            0x39AE29AF49FF30A5ULL, 0xD909C93E2A695A2FULL, 0xB9968EBF5E0AE34DULL, 0x2D74A09A9510E78BULL, 
            0x9EF1267A5125CED5ULL, 0xCAC499C07A6E0EFCULL, 0xBA919497F1653AF7ULL, 0xBA46F4ECB9B8745EULL
        },
        {
            0x51D6036255A3227BULL, 0xA4EBA5DAE490CFF4ULL, 0x3C0E358FD574FA3DULL, 0x5E9E8E1006B426FEULL, 
            0xD69E730DD07E87D6ULL, 0x2196BC3A195A9AFDULL, 0x3370EDE081A8FAB3ULL, 0x943799D91A74F55CULL, 
            0x54D4E8E0CC3E0A63ULL, 0x2A8DD7DE5C9C79ADULL, 0x9734FDF5E33AC341ULL, 0x4A3027ACB61C6301ULL, 
            0xE17B4923DA6C35B8ULL, 0xF6A57E38EE705283ULL, 0xD2774A19B8B22042ULL, 0x188AFDF2C47D4184ULL, 
            0xF3E37728D1B01675ULL, 0x06F4DEBDA51EC725ULL, 0x2C88AF3C5CD7F8A1ULL, 0x725CD0ECDC182444ULL, 
            0x0D4E1FBF4757BB12ULL, 0x686C136E462B82D2ULL, 0xA1E834A5C5BF62A6ULL, 0x4E6F796AFF688663ULL, 
            0xEDFB1536591C41AEULL, 0x9F0D7047DE58A128ULL, 0xAA111ACCD6870D72ULL, 0xF42A3F9204C5BC53ULL, 
            0x40212BFBC44EBB04ULL, 0x61C5CAF6BC3BCACFULL, 0x64641D0899BA3646ULL, 0xB394FF86BB98F6C9ULL
        }
    },
    {
        {
            0x0FE212C25ECC52A8ULL, 0x6DB8C9D5C79FCA96ULL, 0x22CF23B15430E164ULL, 0x1D29ACE65BFDD42DULL, 
            0xDC14DF74FB0FA875ULL, 0x20BE9EE53742C5AEULL, 0xEB4E16269860318AULL, 0x76E1B3E97233762AULL, 
            0xDED6655AB0BB55BFULL, 0x186ACCD8A3A035A7ULL, 0xC535372F35C9D42BULL, 0x8DD5B5248C7D718BULL, 
            0x7DBB69DCC95561A7ULL, 0xEBFB0CD3B4F197EAULL, 0x0ABF6D80A8EF7585ULL, 0xD66E42B3070612DAULL, 
            0x79FAA70DB3548ED9ULL, 0x2EBE4E26D8B26A9BULL, 0x8D07D3871BF649D3ULL, 0x8FEFE0AE144D212FULL, 
            0x9269D2D73C4C6402ULL, 0x6E11544FBAF1084DULL, 0xE220B7471A3D8371ULL, 0x5D2FE7CADA481DCFULL, 
            0xB55393672AEE5979ULL, 0x0A7C6BBF8D6C4CF6ULL, 0xF6AA5423648DFEBCULL, 0x5B4C175136E893D9ULL, 
            0xCBA02F86CFD7C9D2ULL, 0x91AC40F730F30043ULL, 0xF472DB21577EB2AAULL, 0x7FB56FC0392A1259ULL
        },
        {
            0x0B5BF2D8936307AFULL, 0x9AEDA513B0A2DA1EULL, 0x19478D5A45140AE2ULL, 0x7316615AD7C58D3CULL, 
            0x2995CBD2A4AA39A0ULL, 0x96317272563DABB8ULL, 0xA35EC377E6A0A732ULL, 0xAC2AF8905A0A9777ULL, 
            0x11B9EA5FFE89AA4DULL, 0x04A3E1BF871BA56DULL, 0xC9158C010E954A24ULL, 0xD2EE2AC3F36FC015ULL, 
            0x5444F4A7ED48019AULL, 0x0EA9853756E59C65ULL, 0xA1D971D5526136DBULL, 0x6D2DA009C64D8F41ULL, 
            0x80C2EA7804C9E759ULL, 0xFF2189321402FF74ULL, 0xBF137F7122781F8EULL, 0x88BC0DD9A6150FC8ULL, 
            0xD7940B131F45203CULL, 0x25A3CBCBD46B6446ULL, 0x2C2AFFC70B29B2EBULL, 0xC09C3FB8A49DFD00ULL, 
            0xC8E24DD85872C629ULL, 0xEF9E120DEB894D34ULL, 0x8912521DAFA96B2CULL, 0x111F4243FEE01D89ULL, 
            0xB646B205E3F6FAFEULL, 0x97E4FA45B4BED8A7ULL, 0x4430ED6C821F0BF7ULL, 0x993504E7479D0CF5ULL
        },
        {
            0x23987432D0294724ULL, 0x6E32F788C4C4E36DULL, 0x6811C1B5845B7D64ULL, 0x4479467B16033B47ULL, 
            0x97039831DA475F13ULL, 0x1A2E56B895DA6FAEULL, 0xD8DF393541E6BF54ULL, 0x25413685FE8DF101ULL, 
            0xF906DF241E8F8CA2ULL, 0x6BD62218599E284BULL, 0xB08683D1D742BD86ULL, 0xD4B4A7D74607BD4EULL, 
            0xC1E69CE271E3B45FULL, 0x08DC6DEB7D7DAC75ULL, 0xC85D242EBE5E0645ULL, 0xDB183D2833B4D128ULL, 
            0xC391F05DA7E15235ULL, 0x4530EA498CC5539CULL, 0x539341696001C505ULL, 0x799C2CF4834B28BDULL, 
            0x5A4F8038C83FA840ULL, 0x164617AEAD7143B2ULL, 0xAF583464A2804C1EULL, 0x357ED5B91E4CF87AULL, 
            0x26DB73A4D6D835B2ULL, 0x510EB836BC24887EULL, 0xE8BBD3701B68BEBBULL, 0x81EA185F44FF1EABULL, 
            0xAD56020B3D16FEA2ULL, 0xFF8591757463F3B0ULL, 0x1B4CBAFC1B1E070AULL, 0x08E5017FD8D67B75ULL
        },
        {
            0xFCEFAE75D95E209CULL, 0x3E1410CFD9ED98BAULL, 0xD28A18BA1F6D99B1ULL, 0x35C76B465C4BD391ULL, 
            0x5AC9C2EA28EDC53CULL, 0x81C0631DD6DDF3E5ULL, 0x86E04BDB588EBE38ULL, 0x7BF2CA8DA1793AFDULL, 
            0xF1F77817986B75B4ULL, 0x3878ED3367744098ULL, 0xBE00F174FE1C45CBULL, 0xA3D9C483DA5D50B2ULL, 
            0x4F5AFA5BF9320B17ULL, 0xD6C52208F5934EDBULL, 0x00EF30BB2A33BB0EULL, 0x3C2DE590CD8CE555ULL, 
            0xE452534618CAC63FULL, 0x6691A98B14D4FFDFULL, 0x44FCB31B1687FC42ULL, 0x0D132CE8676BB1B6ULL, 
            0xDFAA9F221CE1774FULL, 0x26D1C25D7BC6CFF1ULL, 0xA8317E0670E282DEULL, 0xF27A4A4C101DE307ULL, 
            0x3922F0A81BD87091ULL, 0x301F0BEE6C51A37FULL, 0x0EFD45FC0F0E434EULL, 0x736DC8800068EDA7ULL, 
            0xD71747CD93C7F496ULL, 0xBD09B482DCD847EFULL, 0xC8FED7816B239754ULL, 0x12D13DF44D545553ULL
        },
        {
            0x017964EBC299CD7EULL, 0x1119519B9E27B35AULL, 0x1FA397D264E3F367ULL, 0x56F3728D1D3A2C42ULL, 
            0x72CE273F2F95C49BULL, 0xF7474661F67CC75FULL, 0x7912BEA2DACE260DULL, 0x11020D298F4DD16BULL, 
            0xB3BDB198009E349EULL, 0x65854DD8625CCD57ULL, 0xCE342DC0301F577BULL, 0x4449F0A1D8D51E28ULL, 
            0x8A5AFD65455BD70AULL, 0x33BED00E7FBB7AA8ULL, 0x3E0C0A9F51D3E4C8ULL, 0x1914E0B381D9E201ULL, 
            0x48F5C4D5A1DE5D2AULL, 0x22F73933F61F1881ULL, 0x6DD830FBB1EF0AADULL, 0x073756C5C71C7AADULL, 
            0xEA60E94C9DD85315ULL, 0x0B5C027E16D21DA4ULL, 0xDDE56216FBCF80DBULL, 0xE4FF7F8168BBE2BFULL, 
            0x8ED15DF8EE1FB931ULL, 0xB847D53F79575D7FULL, 0x22D47B656DAE3F6EULL, 0x7BE0D97907AB2FD7ULL, 
            0x65CE97009877F0B7ULL, 0x818B230BAF6149D9ULL, 0xBB6628453FE2E7B1ULL, 0x923E37A7E53A128CULL
        },
        {
            0x73DE3FA9A84E62EFULL, 0xD3EB95AF4E92B622ULL, 0xE8B6A0F735F6206FULL, 0xC26E80320C616B62ULL, 
            0x00B01A00E98111AEULL, 0xC9B53F6D0E686183ULL, 0x195683B6F6D5EDA9ULL, 0xB3CF2F5FA6EDE3B7ULL, 
            0xD1859276AB94941DULL, 0xF81F6E9A5B0E52CCULL, 0x57DA86E5ADEDF7E2ULL, 0x43DB3EB9F3B9BD2FULL, 
            0xB8C078107FD9FD3AULL, 0x1D56F5456426D891ULL, 0x12E42FB43A5E020EULL, 0x4BCE06531C71DD48ULL, 
            0x799D890C52448E32ULL, 0xF0BF516A4B7B8F32ULL, 0x333FD773D339FF96ULL, 0x20D6878BB6396751ULL, 
            0x045288574FBBE966ULL, 0xE337F479251018D9ULL, 0x5EA593362D8D6C3BULL, 0xED792C2FEEE3B2EAULL, 
            0x7014AAF49C900320ULL, 0x86E4D2B5E8065A97ULL, 0xAD3212FBF517E70EULL, 0xD1E2AD3F1C95EFBBULL, 
            0x88ECE464DF645794ULL, 0x0B8165A44EC81CA2ULL, 0xE68610639C2C0F7DULL, 0x3E513B54C6196D94ULL
        }
    },
    {
        {
            0xED8DCC0E1BB89177ULL, 0x1B8D4D909D98CEC4ULL, 0xA2503880A5B582F8ULL, 0x5A6BAEF6A483CE84ULL, 
            0xF15A0A285A37D52FULL, 0x67E356FC81F46BF7ULL, 0xADE38541209E848AULL, 0xF40D556A39E5B27DULL, 
            0x5F79BD88C1709836ULL, 0x09C2526CA8B6059BULL, 0x88174028CB27E530ULL, 0x940868AAE42B1A29ULL, 
            0x05AE264094790D59ULL, 0xCF28B503D38C4946ULL, 0xE05EF2C00F77D1B7ULL, 0xF02FFCB083044E53ULL, 
            0x26C85D2A152DAA86ULL, 0x7422329C447EB41CULL, 0x54B732B399B5D1D4ULL, 0x0C35CB2C92207E78ULL, 
            0x80FD36439519018AULL, 0xC26C59787A60531FULL, 0xA28F5386ED44EE68ULL, 0xC8348193A16BE5BAULL, 
            0xCF3BCDBEF729694DULL, 0xB095D32CF719A99DULL, 0x74DB511CAFEFB1D3ULL, 0xFC77B40EA080921BULL, 
            0x82FCF3359EDCEFB7ULL, 0xABD4A98FDED9912BULL, 0x68BB305B2974772AULL, 0xE0270CA09CDC0323ULL
        },
        {
            0x57C5F7338BD44EFAULL, 0x2CC4BA077D540CDAULL, 0x0449F110AF5D4184ULL, 0x8AAE5F1DD5CC7DEEULL, 
            0x1F265802FB538794ULL, 0xC4BDD20EB4BA7CE9ULL, 0x7ABB8DF7749A4450ULL, 0xFBE48522AEA17ADDULL, 
            0x91363BDEB1D5AE71ULL, 0x8851DDE917CC8BC0ULL, 0xB506CE0A0A0F4FC5ULL, 0x1C88FFFE88193225ULL, 
            0x7FCB62BE19329DFFULL, 0x0923E451F931AD88ULL, 0x9AD7F56ABBB58024ULL, 0xC6BEC357732D2242ULL, 
            0x88DF9E2E555FB63FULL, 0x0313896E2727BF0EULL, 0x918B0B572EA5157EULL, 0x7F85C6E7C7748834ULL, 
            0x8C6605AB87F8E271ULL, 0x4D445E79BFCFFD7FULL, 0xEE073F65E138F4ECULL, 0xC69BF6380B95A08FULL, 
            0xF956205EC3B0FCDDULL, 0xBF5918A7737B2B87ULL, 0x25F113A736801773ULL, 0x1DE5A927F6979E30ULL, 
            0x7B70C437FAB92F16ULL, 0xA78E39DFBA34B551ULL, 0x5D091A45D7192F79ULL, 0x870031A268E7547FULL
        },
        {
            0x68BCE5263604E4DCULL, 0x80AE952D9CD019D3ULL, 0x76709FF3DD7FEFA3ULL, 0x6F101FDF076812F7ULL, 
            0xC375F2A7C81FB501ULL, 0xD2D4C0EA8DF0534AULL, 0x16C33B5B9173A95BULL, 0xD9FEFB85C8CD7DADULL, 
            0x2351468EE5BDA97FULL, 0xFD79C5EE64F2DFEEULL, 0xFD4AFA503DE46076ULL, 0x8BA2C8B306E19DA7ULL, 
            0x5F33F1D5898540D2ULL, 0x3C2A7EB43B1B389BULL, 0x5B8446A13D15E3E4ULL, 0xDF699A19ACA04C84ULL, 
            0x0979FDBA8C52EF66ULL, 0xA722301C817A72B8ULL, 0x2F72087D23F3706EULL, 0xF5D508BF1A2A9B73ULL, 
            0x965D6C410CF73884ULL, 0x396ED0860DFE6EE5ULL, 0xBA67756721BC1C32ULL, 0xB42A492A39D91081ULL, 
            0x6E5E9AE33FD70CEFULL, 0x992A90EC03F1FB97ULL, 0x987D48F89C2CD0C9ULL, 0xFDE08BD08CECA168ULL, 
            0x4A187DFAFD4AE00FULL, 0xD9BF1FBB982C5882ULL, 0x2245E02143B36464ULL, 0x9A3AB99359CA253CULL
        },
        {
            0xAC90A480C8DE5916ULL, 0xA923E8B6785B89D3ULL, 0x7553FEE76403FC5FULL, 0xEFF71BAE94AD98D8ULL, 
            0x6CBF9B714A6BD317ULL, 0x3520B17483D31A2CULL, 0x4660B75049279AA6ULL, 0xD0ABEE53EBCA4E63ULL, 
            0x300BB4A8CBEE69A9ULL, 0xB7F166FC77C53D55ULL, 0x9C2A2C22280AD28BULL, 0x0755B83F43CBB91CULL, 
            0xE6AB5EC155A1D0A0ULL, 0x0B4C7658312AA68BULL, 0xD8D3EC40EBE29CCEULL, 0x5AF65C6859764F69ULL, 
            0x2839A1A556F98B6BULL, 0xB6CDCE873681EC08ULL, 0xBBB8CB90634A8266ULL, 0xAC47FE6DE4615EE0ULL, 
            0x070F7293E46EF89BULL, 0xC84CFD66675F63EFULL, 0xC13602D5CDD1BB7EULL, 0x95875FA5CF8127A2ULL, 
            0x5D5FAC2C538D64DAULL, 0x6564405D46C608F5ULL, 0x2C64BC23F5DBDEA6ULL, 0xC47E0439626E7B99ULL, 
            0xB9EF01DCF82A5714ULL, 0x2946FD3E02F0243EULL, 0x49BD5ABF619629D5ULL, 0x30BDBF5792CB1679ULL
        },
        {
            0x703489B2E8D0DD78ULL, 0x993D5C754089138BULL, 0xB223C82822AE7CD4ULL, 0xD582858F5359C36EULL, 
            0x75908CF87DD54B09ULL, 0xB953CF6AFD3EBB2CULL, 0x82DDA742CD94E3AAULL, 0xD41E277E91CC9B02ULL, 
            0x37908684D09542F8ULL, 0xF0FC313A063DC593ULL, 0xB1D475904B4EA956ULL, 0x43EB55C6784EA6AFULL, 
            0x6C39D90F93D3C0A2ULL, 0x977B2F7C07622799ULL, 0x5E308B151E7AB0EFULL, 0x4EED42DE30C1AFB1ULL, 
            0x161A622172D9F598ULL, 0x4D850238572EB027ULL, 0x515C84DCA27E62E2ULL, 0xFFC95BE92D527D40ULL, 
            0xD21A63DC248BE2E2ULL, 0xDAA3019E9E6F0690ULL, 0xB29AE7769DDDF2A7ULL, 0x7B35B6455AC235CCULL, 
            0xD8AB6B1F634C8865ULL, 0xD816BD64487EB46AULL, 0x3144C511798072C1ULL, 0x3D7FB48B68988C9BULL, 
            0x5BB92A9F7AECD67FULL, 0x29FD2DC708322D83ULL, 0x9790665B112517C6ULL, 0xD9FEF2A420FDC711ULL
        },
        {
            0xF336F6A8C84DB8EFULL, 0x99F48C047B1201FFULL, 0xE97751B686E51349ULL, 0x20F61434C191D12BULL, 
            0xFD1563680DF2E838ULL, 0x014FFFF430987B15ULL, 0xE55CF46A2710DA68ULL, 0x9FD04D521F0CE24EULL, 
            0x71A213AFD55DA52AULL, 0x49BF1A6112B313A6ULL, 0x82B42B80C0B3A2ACULL, 0xC37E946FA051E89BULL, 
            0x4CE46C45F7E8AB14ULL, 0x14FFF47450D499ECULL, 0x336D15E1AE1DEDA6ULL, 0x82E164B837B131CDULL, 
            0xF1FA246FD43177EEULL, 0x748E5B3FE8EE3FBFULL, 0x6947E355CC5D8284ULL, 0xA23068B6C92F339EULL, 
            0x695CA30B948E4E02ULL, 0x506E7032F77525D8ULL, 0x9AC39A13825C0356ULL, 0xBF10E921C9D3AA42ULL, 
            0xCEE4D45ACEC08DA3ULL, 0x9CFF9C89DE9620D3ULL, 0x4F0C9D1DE6E0DCD8ULL, 0xD692FC8AD0B2D798ULL, 
            0xA9A104BB1E0FDE03ULL, 0x41569C51EE56C8D7ULL, 0x3D9426D6E8909B1BULL, 0x48FF74305E6E2837ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseGConstants = {
    0x07E456377EA80F40ULL,
    0xAC99337E6741ACB7ULL,
    0xC52879F223A57656ULL,
    0x07E456377EA80F40ULL,
    0xAC99337E6741ACB7ULL,
    0xC52879F223A57656ULL,
    0x52FC7345FFF98F44ULL,
    0xF99B22F2ED1C3F2FULL,
    0xFD,
    0xD7,
    0x4C,
    0x84,
    0x2C,
    0xB9,
    0x5A,
    0x71
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseHSalts = {
    {
        {
            0x9D444FBC0DE50608ULL, 0xBCC5A054420000AFULL, 0xEA69FFF73EB123DFULL, 0x5ED0876D7C524EBEULL, 
            0xBCF1784CFBB64CCAULL, 0x9C20F117B61667B7ULL, 0x7D8D93CDE50A1047ULL, 0xFA55741868D07609ULL, 
            0xCA374EAC319E9827ULL, 0xF04ECE14CFF2A92DULL, 0x24D8D67042FF935AULL, 0x7C3CDC6A46A4A39EULL, 
            0xBEE2369944FED9E7ULL, 0x49567FFDD5264216ULL, 0x717246B7F8958A59ULL, 0xE66DD98CA458FC82ULL, 
            0x0F994DFF79103E4DULL, 0xC1C9A347603C7B32ULL, 0x8E5118828CFAD466ULL, 0x107799E66A47F1A0ULL, 
            0x985829B58F24318CULL, 0x5078B994DB72E01DULL, 0xECCB90ECF13FD62FULL, 0x6F1880105C0CA067ULL, 
            0xDF031408046E4C27ULL, 0x39F120F4CCEBF731ULL, 0xDE72EBE5F324FEF2ULL, 0xC8844B4173790319ULL, 
            0x3FFFBC4A88BE2631ULL, 0x5766064D9A7FDBCCULL, 0xB278CB9615CFD4EDULL, 0x9435D2F1DD78FC05ULL
        },
        {
            0xB70F3A5E4E923F1EULL, 0x54F9C8AB7A752A59ULL, 0x443DD93F1944C752ULL, 0xB459BC8263D70432ULL, 
            0x7CD545B3AC970E98ULL, 0x71E363279B301F7BULL, 0x028D91EA1A6E9254ULL, 0xC5625666428875B3ULL, 
            0xD6042E58FE45DE6EULL, 0x068D5B447BA2EA02ULL, 0xCD2F53AF9CD3028FULL, 0xDB0B5723F76FD2BDULL, 
            0x0E1782836F54880DULL, 0x90CFCBECBB1E1073ULL, 0x454D91268177D5F8ULL, 0x0E50EC26DC1C1ABBULL, 
            0xC828BC22695CBDA8ULL, 0x581482FED757D12FULL, 0x3FD04654EE0CCFB7ULL, 0x7F90492DA73ADA7BULL, 
            0xB81EEF8195FEB840ULL, 0xE7271DC2984C428FULL, 0xB03792848C3AAE63ULL, 0x0EF6DAF7BDA91E5CULL, 
            0x86E39538EC0EE10DULL, 0xC0DE384C31579293ULL, 0x45F5F196CEF19004ULL, 0x1B8512FC5D101109ULL, 
            0xBEA86581BB087776ULL, 0x3ED9BB3451217214ULL, 0xEE9D434AF91B01BDULL, 0xAB9E3FF3F61BBA74ULL
        },
        {
            0x4FF756D1B73AF10DULL, 0x89D67D3FA139ED46ULL, 0xDA39EB1A15715858ULL, 0x1A0663066E34C9DAULL, 
            0xC77F39216BF850D2ULL, 0x438FCC27B79C3893ULL, 0x672845BAEAE3CDDAULL, 0x5D4DF679869C9D29ULL, 
            0x307AF5678F3805BFULL, 0x4355305E35F3BBB5ULL, 0x57CFEAAA7999A0F7ULL, 0x5A6632151C8FB06AULL, 
            0x99FDBA8B3F690681ULL, 0xD86C68987A6A3149ULL, 0x649F277D8D582322ULL, 0x8ACAC68379C6127AULL, 
            0x52103FCDCD743502ULL, 0x7B0981FE0347E088ULL, 0xF5D82FEB91B95EA5ULL, 0xDA5625CF17B53B18ULL, 
            0x93A7315BFC4A215EULL, 0xF93D8E32BF4918E0ULL, 0xA95A856D30066860ULL, 0xC8522F40F2E8281FULL, 
            0xA1C17DC87021FD76ULL, 0xC039292CF32EE744ULL, 0xAA48066CF004F796ULL, 0xB5F7530D39DEABA5ULL, 
            0xBA02AEBB42A20885ULL, 0xD2716A7D8962A455ULL, 0xD950D1455BD4ABAFULL, 0xC881D24C2488E91EULL
        },
        {
            0xFC84C8670AECAACFULL, 0x18B38BF9DDB2D467ULL, 0x663FEA6FA736B41EULL, 0xE3EDFAB5CD185D21ULL, 
            0x2143C86E8455B4DCULL, 0x8F1E770E1742F670ULL, 0xF421B46A78086DA1ULL, 0x994977764F7670A3ULL, 
            0xEF2E1218B9A7027EULL, 0xEC21F998AEACA529ULL, 0x2D03E3D4B41F51B9ULL, 0x68FCCCC5903944B8ULL, 
            0x1BADBED5D110B5CDULL, 0x03E46EA8017D059CULL, 0xA9485501B28F544BULL, 0x211F92752D120CF9ULL, 
            0x2D71AF869E98365BULL, 0x4A2C8DDAD60F5E99ULL, 0xDD03BE4EA92D5F31ULL, 0xF94FC841B2D7FD79ULL, 
            0x56A468CC74F199F1ULL, 0x3ED30BCB767DF7F3ULL, 0x2A76F61FB07EAFECULL, 0xD5161D5CC440D094ULL, 
            0xC5165B32DB7C88FAULL, 0x8879801AD4AA34D7ULL, 0x3D5AD013A34511A3ULL, 0x6174AA2256F0D573ULL, 
            0x53D0D4E289248FB3ULL, 0x5649A217D4A9CCB9ULL, 0x2A293FC870F89817ULL, 0xC43D9D15855619EEULL
        },
        {
            0x1AA633A2E0A69DC7ULL, 0x5F90605E854184E2ULL, 0x87649A0CC7C862CCULL, 0x171FF575131EB12EULL, 
            0x2A3DF62B73DF784AULL, 0xFC8AFFE01686944CULL, 0xF31114EEA1B58D51ULL, 0xB20066DC318C63E7ULL, 
            0x60E7359B630A0302ULL, 0x097CE74E2A61FE3BULL, 0xBA6D99EE6BA3D20BULL, 0xD7B3979C2C556353ULL, 
            0x8AA128B1E95646DAULL, 0x7C6791B6A6DAFCBBULL, 0x07C9E9B2CC1EEF15ULL, 0xB041980391DB2BE1ULL, 
            0x67D365D069CDBDD6ULL, 0x8F496A2D40F62ADDULL, 0x290F604180176D67ULL, 0x41F9B7E0DB742A68ULL, 
            0xBB96EEB7558A8622ULL, 0x0917B405551B111BULL, 0xD98A1057B93C5D67ULL, 0x718605DB50EBA07EULL, 
            0x5A1FCE60F5C4104FULL, 0x3861C7F154FE59C4ULL, 0xF63A302759C2F01EULL, 0xDFADD8BA8BD33F96ULL, 
            0x5110A4B890933411ULL, 0x3E5A9563544D7500ULL, 0x14FB0E64C4E40BD8ULL, 0xF52AFAD540A76BCDULL
        },
        {
            0x39C105A4051D1309ULL, 0x93D00CCBF6C5A8D9ULL, 0x47C12BDF471C66F6ULL, 0x2BE1177D50C1F378ULL, 
            0xACC015504222A29FULL, 0x0EF8FA7EAB7300F8ULL, 0x6243C78521814B7AULL, 0x0DE0B6EC99E1F38FULL, 
            0x3EE0DBE19A3A428BULL, 0xD84BEEA4F50DC3EDULL, 0x515864CD21FABAEAULL, 0xAD71B79DD05B694AULL, 
            0xD286142DCAC91F54ULL, 0x23E619F535A93FA3ULL, 0xAA4A1A60F2A90103ULL, 0x58F57BDF7386AF42ULL, 
            0x5F18ED8D6728E757ULL, 0xAECF53AE79730661ULL, 0x1DB6C3D67F54F3E9ULL, 0xDA3B4A7533ABBD42ULL, 
            0xBBF7AFF6E63190CAULL, 0x70905562B9BC9233ULL, 0x93AED303A4C7C32AULL, 0x42C3E1F0E87824A3ULL, 
            0x317B9E70DF0E4F7FULL, 0xA4FEC7AA4DA0D49BULL, 0x6A8B16E00AD9A037ULL, 0x3C32676DC62B4724ULL, 
            0xDE43A29ECED07EF9ULL, 0x7C67C5473A365958ULL, 0xB5C8FED3A5A5DE97ULL, 0x94B3B399C8FE119DULL
        }
    },
    {
        {
            0x32CE5C6F4D04D328ULL, 0x9C07788D75C04749ULL, 0x0BF2F66378F7C53EULL, 0xD2B3216D11B2E449ULL, 
            0x1AB87D288687667FULL, 0x3A98C19E17FF9637ULL, 0x857AEC110FFF0B92ULL, 0x640446098D0482A5ULL, 
            0x677C98856FED5D75ULL, 0x2D40213F3DD34333ULL, 0x3994FE6CDFE92F59ULL, 0xA3BD6AEB0AC7A3F7ULL, 
            0x1468A9CFB5B4AEF2ULL, 0x6ED21F5380CB0DA5ULL, 0x109E3F60C4CD614EULL, 0x29AA6A769C302DADULL, 
            0x59E7D85C5AF6B76BULL, 0xF9A3309B479A4548ULL, 0x058C7E4549293E0AULL, 0x9B7BFF25CD346671ULL, 
            0x0100C9C4F480B186ULL, 0x9CD1E2EB09B6E357ULL, 0x732A3DA7A78E72E8ULL, 0xF5A671AF5F42E3B0ULL, 
            0xC961F6F3818E47F8ULL, 0xBC2736F207834E3CULL, 0x378C7E5C715FDA6DULL, 0x170B9B44D144202AULL, 
            0x336C2349B9564454ULL, 0xF972C2BE905DBFDCULL, 0x6CD7B0CECF2A695BULL, 0x10D1370E85E07204ULL
        },
        {
            0x757C1D3E514FA815ULL, 0x7B49C312007AC46AULL, 0xF5D85E845BF33DA9ULL, 0x7B2E9DE79E69FC6EULL, 
            0xC065C25105A4F14AULL, 0xB66ABB790CF0A9BEULL, 0x37FAC3E027EE5683ULL, 0x4990BC3C69530322ULL, 
            0x27DC5AE28C1746DEULL, 0xF02D4CE57C70E83BULL, 0x07AE8DEFD14071BFULL, 0x6C86CDBE4C8AF6E1ULL, 
            0x45966EF156D85180ULL, 0xA17881BDB60C1E1BULL, 0x971F8ED5B8685407ULL, 0x9C69339DBA65DB99ULL, 
            0xB49B0870C364D849ULL, 0x2410401DC8651EC2ULL, 0xBD0731B1957E8FD1ULL, 0x5AC205D5FE09AD60ULL, 
            0xBDC0AF138C3C6258ULL, 0x6BF05E99E6EC20AEULL, 0x78F15930427E4F10ULL, 0x5A00D0C011F40B9EULL, 
            0xF4641FB30AEA5998ULL, 0x5A4879F832C683CEULL, 0x1419596CC58902B5ULL, 0x776E21187981BD5AULL, 
            0x4E2F5DE3F2FF3C89ULL, 0xDEC36C740D05686DULL, 0x39C93F278318670BULL, 0x4214884DA279F846ULL
        },
        {
            0xE49E20C566B89CECULL, 0x7C7601A4D52634EDULL, 0xA564170E35519408ULL, 0x5279FE1ECB953301ULL, 
            0xFD90A9C62C66618DULL, 0x196EF8864F0A876FULL, 0xB4E065FEE4EFE2C9ULL, 0x260AEA8A1A50A362ULL, 
            0x6ADA6E9C7DEF3B54ULL, 0xB2AB4633063432F2ULL, 0x7A94C01382C961CAULL, 0x6D4465FD6F67125DULL, 
            0xD943D4F4224BBE89ULL, 0x031CE5541FF57FD3ULL, 0x7201ECE03DFAA795ULL, 0x1E9CA6EDDE44D612ULL, 
            0xDFDA54942FDB5310ULL, 0xA8A8A512A50EDCF8ULL, 0x0FC91F101A8B45ECULL, 0xD28AD6D2BE6C7F2BULL, 
            0x44FC1047B2905E35ULL, 0x00D84106CD5D3D05ULL, 0x4276491E6DF0BC7CULL, 0xDC7BCA88DCE5D732ULL, 
            0xF6F2F8A2BEFAE3B3ULL, 0x57C2CEA3D4763B6AULL, 0xEC2726F4C67C49E1ULL, 0xE3BB21F3D043315DULL, 
            0x5376D3DE74D3B4E3ULL, 0x17A62062E1DB5137ULL, 0x6E01D57EE81AD337ULL, 0xD999E1DA5BF75F9EULL
        },
        {
            0x52D1F5CB0D2A6F03ULL, 0x8574CBA84B6E660BULL, 0x8562B9997095A43BULL, 0xA756A42F25141929ULL, 
            0xF43C210DB113C473ULL, 0x48BF1C046EA84E59ULL, 0x87784A79A107B4B4ULL, 0x0C037FB5EE7FFAC7ULL, 
            0x7F26849B543E1DB5ULL, 0xFA1C6E2D634E20F8ULL, 0xE8A185C33B61DE3AULL, 0x8A8A81E59AC36BA7ULL, 
            0xC7A5D90293FAE041ULL, 0x46968859E848A663ULL, 0x4BADC827E3E12112ULL, 0x14B13A9579DF43A3ULL, 
            0x59C4C4B462BCADC6ULL, 0x508A6145CFF705B3ULL, 0x33D856F1A8582F54ULL, 0xEB1A19AF57569A0CULL, 
            0x9986383A210542E7ULL, 0xD6B8D11A47E0990CULL, 0x487A9B4F91F787C5ULL, 0x13C45810F4E13A0AULL, 
            0xBF263841AF592DF9ULL, 0xABC06DE8285916E2ULL, 0x477B87559783D7A1ULL, 0x39F158F648E2462AULL, 
            0x8DC51013CB8B7531ULL, 0xBBE167CFDC90F88CULL, 0xEAB33D921747B3E6ULL, 0xFEFEFD75B756D804ULL
        },
        {
            0x85F817DE262FFF21ULL, 0x1D2753DEE3AB84E1ULL, 0xD7F1FF30FD83D394ULL, 0x00FBF49B831C792FULL, 
            0x1E6814E3D87778AAULL, 0x8F35715236C7EAABULL, 0x99F5D50FC480B767ULL, 0x7BB1FA3168AB1FECULL, 
            0xBDCEB59C2580D117ULL, 0x61FDA572F176C53BULL, 0xFE9D8011802249DBULL, 0xA7A2B7F75DE3A3B9ULL, 
            0x17F651D7431B809DULL, 0x5E6098FB90E71C7DULL, 0xBAAD8104AB21756DULL, 0x7960F22FFD400A2BULL, 
            0xE44CBD55DD9C895CULL, 0xD39632EAF76DCC93ULL, 0x8A3A478CD834CD35ULL, 0x270C32CF4210269AULL, 
            0x2E6812D9DD4095E5ULL, 0x6C3D63D73FCDB85CULL, 0x2DB5B8038695EA85ULL, 0x96857F05A2C39E35ULL, 
            0xC3434E5BB21F6EDAULL, 0x512C09D82F75E685ULL, 0xB8CBBAED15194279ULL, 0x6AEA006923C15A1CULL, 
            0x1A36A40997DDD3CEULL, 0x198A16B1285CB374ULL, 0xEFEA249202EE2738ULL, 0xCAC267F8CC28646FULL
        },
        {
            0xC476B1513D6B0706ULL, 0xF47F2A66DA3CEA25ULL, 0xEEBB175A20C35B49ULL, 0xF17C8E51524143B9ULL, 
            0xD7A0A1D30534B1F1ULL, 0x1C2999241CCA035AULL, 0x769C1E4367DEFC10ULL, 0x6136F4351125DAE4ULL, 
            0x6B7625E8034DC0E0ULL, 0x29148F1A6E485C9CULL, 0x682A3D75D0A8D646ULL, 0xF5C0BC2FA76F167DULL, 
            0xCA9B5A70B2AC64D6ULL, 0x132848C36A638382ULL, 0x1A21016E7F536749ULL, 0x6081CC846578FE29ULL, 
            0x9C451AB04E85B88BULL, 0x3166F37B3CC060BBULL, 0x4DA185A611AF0B1BULL, 0xF2B2E0E5B4F1A4A6ULL, 
            0xA82CE54FAEAE13E6ULL, 0x99C183F4B1BFA7DDULL, 0xBD7FED836B31D724ULL, 0xF7766E115F609BC7ULL, 
            0xD2DEDE0B4A26A391ULL, 0x1B409D549B7467F3ULL, 0x64414019D76B87BCULL, 0xB77D6DA4337384C4ULL, 
            0xCBAD56C995222EE7ULL, 0x575F5642E0E3D06FULL, 0xAB96225AE2215A70ULL, 0xA87FB9FA86D989DCULL
        }
    },
    {
        {
            0x858765411B28ACF3ULL, 0x159216826E06DE40ULL, 0xADB7B73515B25E45ULL, 0x5856A8EE7AF7E7E0ULL, 
            0xC294959D1EB42AAFULL, 0x61EC76DAF934F7E2ULL, 0xF9CD0AB03DAC9587ULL, 0xD8B50D8C9EF64334ULL, 
            0x289C71F133E92FE6ULL, 0x907200BC4A438791ULL, 0x1C9A1160B09DFF73ULL, 0x3043CD652686F704ULL, 
            0xC73D0EE074A5E95FULL, 0x44C4E1A605ECA575ULL, 0x3FE2D3DDC806AC52ULL, 0xBB00D7A12BC93510ULL, 
            0x85C916E72669DCBBULL, 0x5DC26161156463E0ULL, 0xF770C5BDCA19129BULL, 0x55460AB84FE8AC51ULL, 
            0xA839D9A8D1733AC5ULL, 0x66ED882F6E00991BULL, 0x9078AF19D2DE632FULL, 0x2F48509204B2A1DDULL, 
            0x0BB415AB36E97CC2ULL, 0x433F607A6BE78C1CULL, 0xF94572ADD6064FE3ULL, 0x99646AF581B6BAF3ULL, 
            0xA95BFBC45804E512ULL, 0x4707D5EBC896DE26ULL, 0x1C333F1A640A5D85ULL, 0xAEB66841CFAB24BCULL
        },
        {
            0xA8A1B913228AADAAULL, 0xB69D64AE26C8A21CULL, 0x5DCC571F8902AAF3ULL, 0x27453BE3DE0410FEULL, 
            0x2247C11996A740E4ULL, 0xD17A275103CF30EDULL, 0x5B89D2D79627387DULL, 0x8CE2629B7DA62975ULL, 
            0x105BB13D81C49E5AULL, 0xCD2BC7B0FAA3C41EULL, 0x127F539B39E2E551ULL, 0x0124DD5B58F0E10AULL, 
            0x028DE3F9775534E9ULL, 0x72DB621F63DEEA02ULL, 0x0FE9667AA3CF12A1ULL, 0x55D42119B1F92841ULL, 
            0xE6774F9E5F5F39FBULL, 0xE2D127D7CC504229ULL, 0x73355B466FD7E464ULL, 0x0587F28853F49E80ULL, 
            0x59DA993356850348ULL, 0x8C615EE4A4925999ULL, 0x93A5B21298BAA5BCULL, 0x00101463F1D14C72ULL, 
            0x3F38666C1E4A3D94ULL, 0x8E3FAA905C3416B7ULL, 0xF6ADB86183731BC6ULL, 0xA9F3827735990714ULL, 
            0x8D104106C5F935C4ULL, 0x56B2A8E0547D2BCAULL, 0xDB1D068E740DA20DULL, 0xB31588979FB23E6EULL
        },
        {
            0xCCC4F580389C4A29ULL, 0x2197A5D72278F3D1ULL, 0xA78E46C0933332C7ULL, 0x6771BD2EC5E190BEULL, 
            0xF5450DF8A7960D88ULL, 0x7528BEBA841111B0ULL, 0x40CB4CC61D1B6637ULL, 0xDAA8648AC60A8E84ULL, 
            0xD65B1B784A5BF52AULL, 0x18D16C51AE5D5100ULL, 0x0FABD63D61919393ULL, 0x1DF5F5C362403114ULL, 
            0x432434D64978D476ULL, 0xCF18EE58AB55FC6EULL, 0x8DC71CB3863B6369ULL, 0xDACA7DF90D059CD3ULL, 
            0x77150C05F3B8EFC7ULL, 0x92014AF47EF5F41BULL, 0xC80F34B078589779ULL, 0xF9F4D4AAED8D6FD6ULL, 
            0x493B918F9630D7B7ULL, 0x397A10CA3BFFCA76ULL, 0x6FF29CE2BB12C3E2ULL, 0x3C52FC5AC956127CULL, 
            0x2E72AC9B729F2C9EULL, 0x96D3EF326F055E74ULL, 0xED87D3F861291D52ULL, 0xC56A67FBA2DEEB6FULL, 
            0x39979809A7060476ULL, 0x36B312E3D677D3A4ULL, 0xC10102F10A4CAAE2ULL, 0xF62A527F3C229E01ULL
        },
        {
            0xA602706443940993ULL, 0x29438015B94FBD88ULL, 0xC4D50346A7D9B560ULL, 0xFA400BAF715BB863ULL, 
            0x1BAB5306265AF3BFULL, 0x2A8F615A411AB334ULL, 0xD990DDE1ADAAF8E6ULL, 0xE6E0024186BF186CULL, 
            0xABFC4E40197FA82DULL, 0xBBA03B9E62BE4BF0ULL, 0x324CC874A43F50D1ULL, 0x413FE617A6D50228ULL, 
            0xE498B246D9D891D8ULL, 0xE022BB541C7CC86DULL, 0x2F127EDAC221B7BFULL, 0x085B06426510D50AULL, 
            0x80B413B1D7E6D296ULL, 0xFEB74A9B4722DD7BULL, 0xB82E27913D629429ULL, 0xC69F616E5D02AF9FULL, 
            0xCADA4C782CD9F466ULL, 0x9CDFA679ECCA3B56ULL, 0xD199A3FCC50FC891ULL, 0x12B433B1E9C1757AULL, 
            0xF68B906EF3C99643ULL, 0x6C5B932F16829075ULL, 0x3061343D6A253A0DULL, 0xC02E6D4F27A446D7ULL, 
            0x6A4E4050E455A3E3ULL, 0x61AA0F7A4EFBAF91ULL, 0xE57B31C612FC7608ULL, 0x2271EC43156754A2ULL
        },
        {
            0x904498CD03F031C1ULL, 0x822E9FFF2E3397CEULL, 0x5E27EFD38D5DFE5EULL, 0x7E831C598F60321FULL, 
            0xC131E405FBDCDB73ULL, 0x1D4BBE214639EEFFULL, 0x545810149A75D3E9ULL, 0x1850D8896D9A9F81ULL, 
            0x02CA6CCEC71E765AULL, 0x0982E5A74FAC624CULL, 0xE66596B13904AFE8ULL, 0xB5C5F786600BD934ULL, 
            0x057200E9B006F38AULL, 0x4A26DE5DA2E2D1C5ULL, 0xF3346804625127EFULL, 0xA3F72516360EED73ULL, 
            0x707371F2BB4B3632ULL, 0x2756A1AAC3A07686ULL, 0x5FC305B262347A54ULL, 0xD30F32DD459ACFF3ULL, 
            0xEC42591A6C6754DCULL, 0x5E26DF2306C19AB7ULL, 0x69B92F0570C732C7ULL, 0x526B38370FB797E3ULL, 
            0xCC260917FF354169ULL, 0x250F08BE636CCF11ULL, 0x9978BD8556C80F2CULL, 0x5DA2E44ABBF07529ULL, 
            0x7630E4A143B23BB7ULL, 0x60082AFF87307063ULL, 0xED01C1CA127FDCDBULL, 0xA186F48989EF9351ULL
        },
        {
            0x1455562848EFCF66ULL, 0x93E6F5B28CBD18F9ULL, 0xA405CD6BB9E99F97ULL, 0x8F0961854DC4F979ULL, 
            0x3D8BB80C0A5B6B83ULL, 0x3AD16CC609F31F88ULL, 0x82D38F0989B47340ULL, 0x4C92EC046BE50EA0ULL, 
            0xDAFF0F3572816BC0ULL, 0xEEA96F35A0F838C8ULL, 0x5440879BC3235959ULL, 0xD1EDC3CA38F817E0ULL, 
            0x0607D9DBDAF0C62BULL, 0xC0262428EEE8E8F2ULL, 0x65876573DBDE32A6ULL, 0x4C3E73EBBA82CE72ULL, 
            0xC4C5AB733A9BBE4BULL, 0xF9896EFC529B794AULL, 0x248EA8BC17F238F0ULL, 0x6DCA9B189B1C8694ULL, 
            0xF39D2140FE366EAAULL, 0x2857E1F429F49E37ULL, 0xF5D0943112700469ULL, 0xB47F7DBB5C98247DULL, 
            0xD94806BFF4E1A5FAULL, 0x2D7C5FF4E2886CFDULL, 0xBEE0A24A2BDE38BFULL, 0xF283B3FACDC47D34ULL, 
            0xE27B4BD227F2C79BULL, 0x7149CDEB1607F0AAULL, 0x20AA5D2379CA2482ULL, 0xBF038D14D6212EA6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseHConstants = {
    0x7BD14BFA7868BDCBULL,
    0xF9F663B22A136310ULL,
    0x05DA36AEEDCABAE0ULL,
    0x7BD14BFA7868BDCBULL,
    0xF9F663B22A136310ULL,
    0x05DA36AEEDCABAE0ULL,
    0x2031D26A85272B26ULL,
    0xD70E22936DD462BBULL,
    0x5E,
    0xB8,
    0x10,
    0x53,
    0x02,
    0x34,
    0x04,
    0x52
};

