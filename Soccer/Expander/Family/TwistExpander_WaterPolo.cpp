#include "TwistExpander_WaterPolo.hpp"
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

TwistExpander_WaterPolo::TwistExpander_WaterPolo()
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

void TwistExpander_WaterPolo::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC9DEBEC512EA44AEULL; std::uint64_t aIngress = 0xF268CFC5C7A8F4CDULL; std::uint64_t aCarry = 0x85164AD9B39FEAB4ULL;

    std::uint64_t aWandererA = 0xA1B7B4F0EBA77849ULL; std::uint64_t aWandererB = 0x9FF6D575CEA565ECULL; std::uint64_t aWandererC = 0xAD210024BF90A0A0ULL; std::uint64_t aWandererD = 0xDD6BF4DC78DB3F3CULL;
    std::uint64_t aWandererE = 0xF193313D2C168BD6ULL; std::uint64_t aWandererF = 0xFD5460236AB74CA2ULL; std::uint64_t aWandererG = 0xBC0A0D9F612B3559ULL; std::uint64_t aWandererH = 0xA8D72EE0F00933C4ULL;
    std::uint64_t aWandererI = 0xA2A2D76B5C39C6D3ULL; std::uint64_t aWandererJ = 0xC3304056FD4EE9AEULL; std::uint64_t aWandererK = 0xC2DE9A4AB2236B28ULL;

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
        aPrevious = 9567875578985972127U;
        aCarry = 13863744759345118355U;
        aWandererA = 16886126896998632348U;
        aWandererB = 9696392960143178099U;
        aWandererC = 9899825222584972919U;
        aWandererD = 13103531373710938444U;
        aWandererE = 15380816885909883545U;
        aWandererF = 18431773747040792065U;
        aWandererG = 11684169999727516776U;
        aWandererH = 18351872868093358004U;
        aWandererI = 13682892117670738137U;
        aWandererJ = 13398773318348548247U;
        aWandererK = 10084137867236186776U;
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
    TwistExpander_WaterPolo_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_WaterPolo::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEE394152C8B9F564ULL; std::uint64_t aIngress = 0x863FCFAD469A0991ULL; std::uint64_t aCarry = 0xA59080F2EFB4581CULL;

    std::uint64_t aWandererA = 0xAA685CE80A28B17FULL; std::uint64_t aWandererB = 0xA55A1FDFF2A5643FULL; std::uint64_t aWandererC = 0xAD74AF3510A4BE5DULL; std::uint64_t aWandererD = 0xE8498E1CBA985C57ULL;
    std::uint64_t aWandererE = 0xD33D070297150ED9ULL; std::uint64_t aWandererF = 0xAE319F094D51B8CAULL; std::uint64_t aWandererG = 0xFEB5D05091DDF63DULL; std::uint64_t aWandererH = 0xA5DD4A52D106F3AAULL;
    std::uint64_t aWandererI = 0xD6B0C8C25E6D370EULL; std::uint64_t aWandererJ = 0xE4A1914ABABB5BFFULL; std::uint64_t aWandererK = 0xCC4178FEBFFCFC4CULL;

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
        aPrevious = 9292313303938778060U;
        aCarry = 15944642100891646441U;
        aWandererA = 11295805910145330996U;
        aWandererB = 13521710863056564494U;
        aWandererC = 15652310178783739321U;
        aWandererD = 9528247873862793191U;
        aWandererE = 9316655645352560080U;
        aWandererF = 9417407314559234226U;
        aWandererG = 16810874246410327902U;
        aWandererH = 13632080844531068825U;
        aWandererI = 16815242004156990700U;
        aWandererJ = 10677679903080969129U;
        aWandererK = 9257473862388060248U;
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
    TwistExpander_WaterPolo_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_WaterPolo::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x82C3845012C0003BULL;
    std::uint64_t aIngress = 0xCA489185DE27A1DEULL;
    std::uint64_t aCarry = 0xF475D2B1831E5170ULL;

    std::uint64_t aWandererA = 0x8F2A23AFF770B938ULL;
    std::uint64_t aWandererB = 0xD2128AFADF4B9D81ULL;
    std::uint64_t aWandererC = 0xD1D7DFB68FF1E1DFULL;
    std::uint64_t aWandererD = 0x804C0C5168A73685ULL;
    std::uint64_t aWandererE = 0xF50F7CDBACCD78BFULL;
    std::uint64_t aWandererF = 0xDA123C1D537184C9ULL;
    std::uint64_t aWandererG = 0x8FDE972D91B9EABCULL;
    std::uint64_t aWandererH = 0xB29141EEC3AE2CCAULL;
    std::uint64_t aWandererI = 0xC0A6FDE25B0342A4ULL;
    std::uint64_t aWandererJ = 0xF5402771FFBBBCBEULL;
    std::uint64_t aWandererK = 0xDA4378553B4D930BULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneB);
        TwistSnow::Sha256Counter(aSource, aSnowLaneC);
        TwistSnow::Aria256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
    TwistExpander_WaterPolo_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_I(pWorkSpace,
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

        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
    TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_WaterPolo::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_WaterPolo::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x861DAEC2F76B654FULL; std::uint64_t aIngress = 0xF5D1EE631412453BULL; std::uint64_t aCarry = 0x9BDA25E8CB0ACB75ULL;

    std::uint64_t aWandererA = 0xD301B0B70A2BD770ULL; std::uint64_t aWandererB = 0xC8E28A4064F20EA3ULL; std::uint64_t aWandererC = 0xF349D53FE1CE5A6DULL; std::uint64_t aWandererD = 0xE419A910254F3D67ULL;
    std::uint64_t aWandererE = 0xA87088176A0675A8ULL; std::uint64_t aWandererF = 0xC34415982980F9BFULL; std::uint64_t aWandererG = 0xECE09E51880FFB61ULL; std::uint64_t aWandererH = 0xD30ED0CF332A5D5EULL;
    std::uint64_t aWandererI = 0xCB73BAC3E82E9F86ULL; std::uint64_t aWandererJ = 0xA2A5D8AB2A83B9F4ULL; std::uint64_t aWandererK = 0x8059C661D80872F3ULL;

    // [seed]
    {
        aPrevious = 15281382227319680634U;
        aCarry = 12175409535247636513U;
        aWandererA = 17710767172190695780U;
        aWandererB = 18372995636161815955U;
        aWandererC = 17268389780813065184U;
        aWandererD = 11664938961757777164U;
        aWandererE = 14896653977587614069U;
        aWandererF = 18226502138978058839U;
        aWandererG = 15266454394996684007U;
        aWandererH = 16997345032114543035U;
        aWandererI = 16882439248536893372U;
        aWandererJ = 16294509669978704479U;
        aWandererK = 18122252351389965764U;
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
    TwistExpander_WaterPolo_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_WaterPolo::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 3, 0, 2 with offsets 6821U, 4021U, 2425U, 7718U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6821U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4021U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2425U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7718U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 2, 1, 0 with offsets 4678U, 1710U, 4090U, 7799U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4678U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1710U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4090U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7799U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 1, 3, 1 with offsets 517U, 5757U, 6148U, 6496U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 517U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5757U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6148U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6496U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 0, 2, 3 with offsets 3119U, 923U, 1341U, 146U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3119U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 923U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1341U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 146U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 0, 1, 2, 3 with offsets 602U, 428U, 908U, 1943U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 602U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 428U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 908U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1943U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 0, 2, 3, 1 with offsets 334U, 1004U, 63U, 958U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 334U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1004U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 63U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 958U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 2, 3, 1, 0 with offsets 445U, 1174U, 272U, 2002U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 445U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 272U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2002U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 3, 0, 2, 1 with offsets 1115U, 1365U, 903U, 2043U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1365U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2043U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 216U, 1900U, 956U, 1682U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 216U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1900U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 956U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1682U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_WaterPolo::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 1 with offsets 4905U, 8018U, 7365U, 4083U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4905U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7365U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4083U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 3 with offsets 3008U, 643U, 4453U, 2871U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 643U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4453U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2871U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 0 with offsets 2538U, 2996U, 277U, 6508U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2538U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2996U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 277U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6508U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 2 with offsets 5064U, 1423U, 5392U, 7955U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5064U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1423U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5392U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7955U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 8109U, 3368U, 6026U, 5867U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 8109U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 3368U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 6026U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 5867U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1095U, 1639U, 288U, 2034U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1095U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1639U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 288U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2034U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 804U, 780U, 1646U, 344U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 804U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 780U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 344U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 649U, 595U, 1964U, 161U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 649U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 595U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1964U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1528U, 951U, 1247U, 806U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1528U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 951U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1247U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 806U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 1, 2, 3, 0 [0..<W_KEY]
        // offsets: 540U, 740U, 269U, 1637U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 540U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 740U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 269U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1637U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseASalts = {
    {
        {
            0x634151DB2ACFBB24ULL, 0x897ADDA741F35AD0ULL, 0xCA25640A002D87B1ULL, 0x68125CFF7CCC0B02ULL, 
            0xD7A2A4E12A6B52F5ULL, 0xA343D32C0B9B51D1ULL, 0x159F255612BEBB15ULL, 0x0A5005FDFF54633FULL, 
            0xA920EE2702B4AC67ULL, 0x9B0631329159029DULL, 0x05D64851E3212E96ULL, 0x76C3B11491334A0DULL, 
            0xEBCA93A2B623F53BULL, 0x9C1B989ADB01A3E1ULL, 0x789276FAB0416DA2ULL, 0x1D1ADC62F85D0E37ULL, 
            0xB76C886B6CFDCFFCULL, 0x8D2AD248580F4DBFULL, 0x22A022315AAD2058ULL, 0x8AA00322FD858B20ULL, 
            0xE34BD36FA4DAA82BULL, 0x7FE20A0638964EADULL, 0xB42F60E2EC2C0EE3ULL, 0x3AC39A6441C8A9E0ULL, 
            0x016DAB4DF95FEBD7ULL, 0x9C47D352FB0D5BE0ULL, 0xD0367903F2823BFBULL, 0xD81192950E63B775ULL, 
            0xB55FF8E82D2D6FC9ULL, 0x11AA7086FDC7CFC2ULL, 0x6F294D2A29E93B18ULL, 0x702DA363F52532B1ULL
        },
        {
            0xDA150504BCD1F022ULL, 0x1DD3A2550B7D80F9ULL, 0x0BE4AFC01E13BF1CULL, 0xF8D078A1AEF3CC90ULL, 
            0x140DB11DAACA5AB7ULL, 0x336DB0AEFEB768F2ULL, 0xE715D8EDE926A457ULL, 0x7C958F4E142C30CDULL, 
            0x7DEEBD9A10BC7942ULL, 0xC8BDCE5C421A8459ULL, 0x7757DE4E21C968F0ULL, 0xC2E9968740BBB960ULL, 
            0x1872463353D3B170ULL, 0xB7D987B9EE676992ULL, 0x5085DD2AC70AC72FULL, 0x84D39B0D5892036CULL, 
            0x873494AA7C439151ULL, 0x20A354EF12E4B42BULL, 0x44FE72BAB5EF0160ULL, 0x4282E82EA4B85F4FULL, 
            0x3DD06DD745D2E788ULL, 0x5177DBD7E6DC4231ULL, 0xC356C0DBBF2E655EULL, 0xED5C079909147EE6ULL, 
            0x49924E3C70B8F8E4ULL, 0x9DCF703D9261DDC1ULL, 0x25D5CF1FAF9A7FECULL, 0x19F6C6D0675C5DBBULL, 
            0x95A21B88DB1D5B0DULL, 0xFD121DDAB4C35C9BULL, 0x569BB75A3884B303ULL, 0x3775B4DD1B68E80EULL
        },
        {
            0x0C84609AFDA6AD62ULL, 0x217DBACC4D4946ABULL, 0xF8E2D1367A6127E3ULL, 0x3C8C2ED2774B2797ULL, 
            0xB5773A1D11555825ULL, 0x8FB11FB5668F3070ULL, 0x6B3317E22DA3A0ACULL, 0x40F4139D29E3BA67ULL, 
            0xFC08C23977699F2AULL, 0xF91432EFCE014983ULL, 0x97B5AAEF7092E5FAULL, 0x14BBB753AD13F05AULL, 
            0xD014E6A2A4C2C4B9ULL, 0x5DC2ED448841FBC6ULL, 0xCF46A51B98368693ULL, 0x0C367C68A11B6D70ULL, 
            0x5C2DA784EFEFAC79ULL, 0xFFAA78302CB3756AULL, 0xFC398BEF60C83B1BULL, 0xD5B312834A9BE7A1ULL, 
            0x3DCC4841742340CEULL, 0xAB184F4EC0757444ULL, 0x47FBE52A594E0BB3ULL, 0x02EC084354C2FF9DULL, 
            0xB302F409BAD14063ULL, 0x6A1467ADA024DDB9ULL, 0xC29D8B56FFA70208ULL, 0xFD56A94FBD2110CFULL, 
            0xDA8C378851C387B5ULL, 0x989C20B22E705A2DULL, 0x4BE7E8CE9DCED1C1ULL, 0xF6839E6CB3959A8CULL
        },
        {
            0x645ED9AD399737B6ULL, 0x0C0C16CF28225E21ULL, 0xAA5864CBACAF565CULL, 0xCC9ABCB638E507BCULL, 
            0xDF5E0A7A2A3941F2ULL, 0x58686C1ED24CB351ULL, 0xC8C6CDE21D4859A7ULL, 0x5080A164AD7E6D13ULL, 
            0x6871E991059E3010ULL, 0x2D295022A7617F34ULL, 0xDD1EC7A5BEE9A6E4ULL, 0xD0365D3E80A13C4BULL, 
            0x5746A89D96C29F7DULL, 0x26081A83FAFB1536ULL, 0x1256D3949AB39E5AULL, 0x69E0BC9ED291E858ULL, 
            0x89BC77CF5A16F60FULL, 0x6E18E1A0D22E5022ULL, 0xA547E889734C60CFULL, 0xAA087DF70DB882D1ULL, 
            0x77CC2CA5A5FBCEAFULL, 0xDC205924B0D34B90ULL, 0x088E39F9F051466FULL, 0x2B2B8B9DFE971D33ULL, 
            0x03C7E9FFDD7782D8ULL, 0x8A8BA31ACA0EF848ULL, 0x52AED91127049508ULL, 0xE647E9723022CB00ULL, 
            0x2A298C6BD3B3AA07ULL, 0xFC50C587F352AB17ULL, 0xB689C91EB5479B9DULL, 0xA074E69077476C76ULL
        },
        {
            0xE20466865E01582FULL, 0x92939DD137A7CBFFULL, 0x5C32B7980BA5AAB3ULL, 0xE43DE71D2A9062BFULL, 
            0xF9D418AF632B6C8AULL, 0x21CBE26A1DFF6B99ULL, 0x29C211CF00EA6E5BULL, 0xC925A3E7B62CC5E9ULL, 
            0x5A8702726DACEEF7ULL, 0x39BC5344D405D316ULL, 0x9243820C188F49A4ULL, 0x55CB05B983FCA53CULL, 
            0xFEAC0F41824886BDULL, 0x5C3B63F138FC1D10ULL, 0x8559A11A8D7785FDULL, 0x5E030CD04D9BD3B3ULL, 
            0x93D4DD043DADDD91ULL, 0x57C4844DEE03D7E7ULL, 0x47A228B888021939ULL, 0xF21EF256F02C7A62ULL, 
            0xBA493618A31D1600ULL, 0x64D57F1E78F679D6ULL, 0xE9AB5AE8BA1C6F13ULL, 0x2685A268C21B2024ULL, 
            0xE4C15B13E1327CF4ULL, 0x9D7D6D69F7602DCCULL, 0x57DE07682EA44D60ULL, 0xC9804B10B96B6722ULL, 
            0xE91E20D5EF10DF49ULL, 0xE3FECF85161D6F58ULL, 0x39999F9B92114D20ULL, 0x429178FA842769EEULL
        },
        {
            0xCE4C3D307F08C9F8ULL, 0x9F8D645161476392ULL, 0x6F0A435D05849894ULL, 0x20BEF5A8D4E8AD09ULL, 
            0x7AD874B3477DA712ULL, 0x8621C8E1577424EAULL, 0x730AEC7EAD3E123AULL, 0x428D3F13559EF64AULL, 
            0x04E88E7FB9CF549FULL, 0x57B3056DE1CBCC39ULL, 0xB785C6126426674AULL, 0xBC06AD4173E71D0FULL, 
            0x06E4069210FF5687ULL, 0xB60A97ACD1A715D4ULL, 0xC652E1F05E9EE562ULL, 0x6B1F0B4FDB3B96BCULL, 
            0xE05A26E3E5ACF9B7ULL, 0xEC85183E70B95372ULL, 0xCDBC75E6A0E82617ULL, 0x8F62994E5ACBC0B8ULL, 
            0x27762EEDC86FBE32ULL, 0x28C4EC88724495B6ULL, 0x02CE1BB0334DB761ULL, 0x455AA5199EAA29C8ULL, 
            0xDDBE847A5C446E39ULL, 0x9F279A3654ED1102ULL, 0x9CC18D246DCE90F0ULL, 0x6C7210C6C50F6D08ULL, 
            0x37383FC373649F37ULL, 0xED60981E66AB79BEULL, 0xCA5C301A2720A085ULL, 0xEDD96C7DA3CCE72CULL
        }
    },
    {
        {
            0xEEA8E5E2783A75A9ULL, 0x38C34C75A95EB7ECULL, 0x72D22D28E280B9E9ULL, 0x0BD8EB9A5D15C45AULL, 
            0xC9A9D5660BCC4BEFULL, 0x32C94C9428FC948EULL, 0x3C4F82B5B8775FD3ULL, 0x49BAAE4A7E358F7BULL, 
            0xC096A196DEC0E513ULL, 0x0EFE1B6F41A2999BULL, 0x1678F93784BBE794ULL, 0x143E373F92F5808DULL, 
            0x60A98860D61F2520ULL, 0xC3394994FAE168CEULL, 0xCE87450AE54D1D66ULL, 0x54E864302D28ABD9ULL, 
            0x7F97A52D56A11338ULL, 0x50E7B3FAEB31E74FULL, 0xC2A6F810A5A240ECULL, 0xDBA3E71326763265ULL, 
            0x302C784CC1153C5BULL, 0x395C7DBB6778AF29ULL, 0xBDD6430CC7F8DC58ULL, 0x05B7DA73BDC15C3EULL, 
            0x7695CBDD453245ADULL, 0x932EA92E47F0514EULL, 0x3FD51A055A28E9EBULL, 0x26443F70211B8158ULL, 
            0x9DCC8030D8F0DD4CULL, 0xEC294943428BA3C0ULL, 0x47FA1E3D13F8D2D0ULL, 0xF05B09F42355EF4FULL
        },
        {
            0xDAF1C26DBC3D27EFULL, 0x374E6B6DC85E801BULL, 0x7F65444558098560ULL, 0x022D1E2F51B81C9FULL, 
            0xA21A501F062AFDA1ULL, 0x39F091247F67D09AULL, 0x772065D688E7E094ULL, 0xC90B5C392929B888ULL, 
            0xBC0B238CBDCD3366ULL, 0x30DCCA2A98386CB3ULL, 0xA5D5E2900DD44430ULL, 0x43CF33366809495BULL, 
            0x3EF76E2D306CDDBEULL, 0xEFBECD0E638B6D4EULL, 0x25CE388558539B5FULL, 0x845B17FF885150FCULL, 
            0x6B9DC7F9A969FA5CULL, 0xBCF5C2FB7EBF09C4ULL, 0x1C19A64454A28A85ULL, 0x4D56D9EA82A68F06ULL, 
            0x7D875A0EBD71E5DEULL, 0xA9B22C215DD2D5C0ULL, 0xB7CEC51F0FD4681AULL, 0xDEDC8FB89357F8ABULL, 
            0x168D7317C942E26BULL, 0x3E2CF6CE3CE68B69ULL, 0x98357E5706B8AD74ULL, 0xBF02C2E1E306C6A5ULL, 
            0x522930F9E1138E69ULL, 0x2D0442C1ACFBC4E3ULL, 0xF8360ABD0D274585ULL, 0xC73A8039A8299EC6ULL
        },
        {
            0x5F621A8F18C16888ULL, 0x4C06DB805DD12B82ULL, 0x09842F0E3C282EFDULL, 0x4DCA5C8F4CC47D0FULL, 
            0x6433DCB5F9AFC781ULL, 0xEDEF08A20EA5CB35ULL, 0x164C757BB142CDADULL, 0xD27621E7B488C780ULL, 
            0x76B1C39BB68B33E1ULL, 0xF843D075A689A9BAULL, 0x3F52214D1C4F6946ULL, 0xC55111B69E07CE32ULL, 
            0x49B5ADD25FD76E12ULL, 0x2D4C84E63480BCD5ULL, 0x274D4988726F0BF5ULL, 0x5F9625C4E81BC578ULL, 
            0x644A5CB3FA48EE8BULL, 0x735005C9215FDF3AULL, 0x0A71C1A825A082CBULL, 0x906F059FFD285E0FULL, 
            0x36939DC16A4AE3CAULL, 0x766EE64E789DD5E6ULL, 0x76EF82601D96A92EULL, 0x21F2A77227F683DBULL, 
            0x271C6DB73A6CD960ULL, 0xE11C393284628F26ULL, 0x22C36EFE9CC3B773ULL, 0xE8627F8A16D7643BULL, 
            0xBB120294338C88C4ULL, 0x9CF3086FBC01DF67ULL, 0x94237924CCE09F36ULL, 0x407DBC6166D54DEDULL
        },
        {
            0x28071687A0F265D8ULL, 0x4F704B47216E067FULL, 0x85991D398049E47AULL, 0x19D977BCF4C4A4DEULL, 
            0xBC715ADB3E9841CEULL, 0x7D7846E8A1F21B72ULL, 0xAB928E1C8F61D4CDULL, 0x07DE0389F62B4589ULL, 
            0xA736F310FC9DB1ACULL, 0x75F0A96D24C5827FULL, 0xDD26B39DE936B8ACULL, 0xC4DB5D32B8DB55ABULL, 
            0x7D83342A93DC2E10ULL, 0x7FD842BA1355C238ULL, 0x864FB7094406A398ULL, 0xE23EA696FD5F88A8ULL, 
            0xAD5CF8BF6A7C0023ULL, 0x704FA3EDBF03C63CULL, 0x863D4471E40B5661ULL, 0xA1C5A26926F794C7ULL, 
            0xCB683D55B779D79CULL, 0x992339238C1EA532ULL, 0xB4D34ECA1FCC876BULL, 0xD0C880B1B044E386ULL, 
            0x010C7228FD9F5A0EULL, 0xE17819E6A95C139FULL, 0x5114AB58E672F9C5ULL, 0xE52934E3EA988E33ULL, 
            0xE31DDE51E0D6A760ULL, 0xCD69EBF62F484F47ULL, 0x92A59F37F0AE87DBULL, 0xBD78EC35E36F009DULL
        },
        {
            0xA75A60C4B2791359ULL, 0xBD738A13D15065F4ULL, 0xEA43DA10F0E71BF1ULL, 0xBFE168DDA8FA94F4ULL, 
            0x7FC3EC144617D839ULL, 0xB0F5856FD2D7EC3EULL, 0x88D23BEE6B343739ULL, 0x87491FED05EA3CBDULL, 
            0x0111CAEC0F3CF0D0ULL, 0x0EB3ED8427AEF0D6ULL, 0x1E686E071214020AULL, 0x087502F630B4CA28ULL, 
            0x5C2EB728EE595BE5ULL, 0x13C3DD3410D82172ULL, 0xCA261FF12742D63BULL, 0x5E1FAE87ABDCA8BEULL, 
            0xC88A1EFB4480667DULL, 0x5BCF38D08AC3F49BULL, 0x448588E98292F23AULL, 0x812DB07C24A6E464ULL, 
            0xD982B158FD98A1F2ULL, 0xCE96BF65030EAE74ULL, 0xD409CFA39F0783BDULL, 0x5491F57A970898F9ULL, 
            0xA1A4C694E8916667ULL, 0x37F2AF21B6FFDCA1ULL, 0xE81FBC9DC91738DAULL, 0x01C4B929D809C53BULL, 
            0x6DBF21023C76F120ULL, 0x70E479D6517033FAULL, 0x0A28AFB13C5429C1ULL, 0x115ADB887CC7C6E0ULL
        },
        {
            0xE5FE645EC8FD492BULL, 0xF083CE6BA778FA1DULL, 0x58A9BF037F37DDC4ULL, 0xEDB5C8288F2FFEDBULL, 
            0x05D2CA7E9BD77B01ULL, 0x79EEDDA74B2DCC69ULL, 0x5710BCFBB2DEDFB9ULL, 0xAEC5CA963C668E30ULL, 
            0xFB8CD7498C4E1FA2ULL, 0xDB1C905C25C233A0ULL, 0x73ABFFDE7C92220FULL, 0xCCA3167864F1B505ULL, 
            0xC74F4A5C0F0D5856ULL, 0x6D6E23A0F421D6C4ULL, 0xCE85377B8AC2E0C2ULL, 0x1139C2AB90065223ULL, 
            0x2EF936E56A597DDCULL, 0x6BC1696339464973ULL, 0x0863E5BC506AA58BULL, 0x69B91884DDA2806AULL, 
            0x75B1FB3AC786FF54ULL, 0x99D5442A8BCCD347ULL, 0xA31DD44281C1A519ULL, 0x4281138BA324DE3CULL, 
            0x78AE9EC884BE42C2ULL, 0xA698C6F15B70E656ULL, 0xDED9C183EBFA9D8FULL, 0xA31C2BB62DF1D096ULL, 
            0x2688D4435C974651ULL, 0x2B54E4D5BBAF8BC7ULL, 0x7771F8FC4C674E2EULL, 0x52D19828D28C98C7ULL
        }
    },
    {
        {
            0x4F9CFDAFFBE7A416ULL, 0x278FB55B433A07A0ULL, 0xFE246FB0E0252363ULL, 0x771DC64E49D19F5BULL, 
            0xDBB68B56134A3EAEULL, 0x81479004CAE54BF1ULL, 0xCAFC321966D7D52CULL, 0x96715657A17D49AFULL, 
            0x4B441665DCBBAD23ULL, 0xEB56EB6B6936D0A2ULL, 0x4DE88694E522CFF3ULL, 0x90FBDA612A3044DFULL, 
            0x0525FC7029AEAE26ULL, 0x18EBFC8828DE44D1ULL, 0x2E6BF3DC16FE06AFULL, 0x729799831BAC1E96ULL, 
            0xFE1A68B59AAE8908ULL, 0x9EA8592D79BBF4C0ULL, 0xADFFF284960200FBULL, 0x0B1404560AA00112ULL, 
            0x9CC3F57C9C8C0BA0ULL, 0x59C3869AAFF36B38ULL, 0x4DC4C32194A0DCE1ULL, 0x11F94F38E1F67A00ULL, 
            0xAFDC8E90CF25621BULL, 0x9785CC0EF52C2B06ULL, 0xFBC4251041488681ULL, 0xA6D4F58DD8E07D15ULL, 
            0xFB4447077CAC7F11ULL, 0x989E62AC37F7EB68ULL, 0xE759F7CAAFCA2068ULL, 0x23B5143AA0348B36ULL
        },
        {
            0x6412C7C561B568E9ULL, 0x624584928C9E2294ULL, 0x824211C7118199CCULL, 0x6F9DF843FB393D4AULL, 
            0xFAC3F9DE161605B0ULL, 0x3E438DEC31FB8A8CULL, 0x0692EB00CFFEEF07ULL, 0xA5F826590AC0BC19ULL, 
            0xEA704E202C0316D4ULL, 0x7257DF94F595C6B7ULL, 0x066F39F168ADF717ULL, 0xF9341144E596FD8FULL, 
            0x0244704DB2932C6DULL, 0x9B6FC206237C12B2ULL, 0x78F0D952E5218198ULL, 0x6AA5575279198BDAULL, 
            0x5C58A386AEC6A384ULL, 0x5608AC38BC5E5214ULL, 0x60687F9D0EE99133ULL, 0x7001AFFB58D0423EULL, 
            0x9654C69F0796A1C9ULL, 0xFB823B490575BFDBULL, 0x8BC9A70BD628009BULL, 0x24B3A9E38EE7EE3AULL, 
            0x1E3AE766846A6D84ULL, 0x792CF96273E14E74ULL, 0xAD8EA5BB29ED4B75ULL, 0xCA8DF807B77FBB8EULL, 
            0xB1B98AFF1936892AULL, 0x5E50FAE706ADCAEDULL, 0x8977923678302592ULL, 0xC7CBE46A1251C815ULL
        },
        {
            0xE34EE47B99FE4A78ULL, 0xDD40C14CF5C3CE64ULL, 0x8E94DED6578915A4ULL, 0x1B8B64DA246F7AAEULL, 
            0x9907155F75BE79AFULL, 0x3A3841281DC7C432ULL, 0xD123F9CE422EB3C4ULL, 0xB184C0F6C5913B29ULL, 
            0x7125916D8AE81257ULL, 0xC68D0F59688F2C14ULL, 0x946C6B538CD87692ULL, 0x2DB083F33187E9E5ULL, 
            0x8EC9B47543309CA7ULL, 0x06554E1310FED13FULL, 0x94E7EDD5EF4D0C54ULL, 0x891B61338136D9D0ULL, 
            0xEC6968D033CA4020ULL, 0x0BE2B3AF05F73EAAULL, 0x5947E73EA43F71ECULL, 0x6D92BAE673F6575FULL, 
            0x4A553311264AF9EFULL, 0xDAC9FEBE77F18316ULL, 0x81F82E2E3939DB37ULL, 0x7C41F60D98BBBF17ULL, 
            0x79397C556F604413ULL, 0x985C837AD94A7C9BULL, 0x25B9F02F5D629346ULL, 0x2C3E5BAB1DB16CFDULL, 
            0x6355038655529000ULL, 0x45A33BD57C86C3A7ULL, 0xB864951354EFACC3ULL, 0x3F32E776DDA43997ULL
        },
        {
            0x1BF3FA7E2234AFFBULL, 0x3BA126CCCCDCF72CULL, 0xBDDC403D6C043FBCULL, 0x9205C1BC8F6B7DC1ULL, 
            0x1459B67A819D547FULL, 0xA815F60571694389ULL, 0xC20310817D80BC8FULL, 0xC5361C2C13D50A63ULL, 
            0x96B2C344076E0A2CULL, 0x572F36516A1255AEULL, 0x348E165F42BC8CACULL, 0x10BF981C08680891ULL, 
            0xB576E71B9360030FULL, 0xC8890B11CBA7A313ULL, 0xEBF2BCB9826095E7ULL, 0xBCE6AFB6E2A57CC2ULL, 
            0x0F60CC7826CD943DULL, 0xB506AEDD61D1DB18ULL, 0xAA08C7A1BE4D8746ULL, 0x9A1B922C337DE552ULL, 
            0x1A364D875D980C8DULL, 0x91F452AF86A85936ULL, 0xAAB2711598C18885ULL, 0x11FFE4D07F08F413ULL, 
            0xC2EA2D6457A10B55ULL, 0x980D3A2A277DB2FAULL, 0x04A98DBB45D114A6ULL, 0xC30AB29659C35FEAULL, 
            0x3BF591D8BEBE896FULL, 0x82C4AC8909DF98B6ULL, 0x74A0B68AB5636C44ULL, 0x4F74B3C62A7E7F58ULL
        },
        {
            0xD776B4654744D1D1ULL, 0xE72A51528DF0483BULL, 0x45B41A70BB949A85ULL, 0x1BD961774B84D690ULL, 
            0xBF03FB216EF5EF7AULL, 0x2EAD2AF348C47DAEULL, 0x3F512FF53778256BULL, 0x10A304EFEDF12E3DULL, 
            0x3DBE51818E2850F3ULL, 0x21DD60EF30750BB6ULL, 0x3DD12E7342802316ULL, 0x81AEBB5695F00F16ULL, 
            0x96F9CBEB407DBD76ULL, 0x044F3A86E603EB64ULL, 0x5D5C422AFDB4DCE9ULL, 0x16C27A359DEDBA7CULL, 
            0x7938783F00D0760BULL, 0x01C513271912F1D4ULL, 0x2B93708C9783A6D1ULL, 0xA9DB59DF8C2EA9B3ULL, 
            0x1A41B777AE633040ULL, 0xCF0237587B31F1F9ULL, 0xD51D33FD10F6FBB1ULL, 0xD639FF4BC651A2E6ULL, 
            0x9D5232FE2D653712ULL, 0x279115DEAC4DA090ULL, 0x46D4D0CD018FC7DEULL, 0x92C1C06779F17C4EULL, 
            0xEF263B13C40E5252ULL, 0xA6A889CEA2A25D98ULL, 0x5A18F8663A77DC5BULL, 0x285EF6E40F6F5514ULL
        },
        {
            0xFE988BD61A8F18F0ULL, 0x9E4649141AD030D9ULL, 0x3C38A45E6F3AF826ULL, 0x110F59D055F68ABDULL, 
            0x501928B6379B9771ULL, 0x2630B0219EA71F28ULL, 0xFF23D333F2CF0861ULL, 0xAF3EBF8B1302B5C0ULL, 
            0x42559F72759760B8ULL, 0x97F4F646EE189B8DULL, 0x3E8E6CB3D2AC25E2ULL, 0x65CB7EFA22361FEEULL, 
            0xC3838A1851A875CEULL, 0xFD1EB1E645A07009ULL, 0x160C0EB9BE55799FULL, 0xAA5F6A621CD06BE6ULL, 
            0x0190AD22F3CBA12AULL, 0x5D17B448A6B6B838ULL, 0x369EDF01AC0BB68EULL, 0xFC9AF788EFE4B078ULL, 
            0x5E3F9E64BCF22578ULL, 0x7F3851BD306A611BULL, 0x6E96080B9A361765ULL, 0x7F571206BB9D6517ULL, 
            0x4BC4E3FBEFF3FE29ULL, 0x197A24F2372E6C7DULL, 0xCD2172E994A5A044ULL, 0x12E3D67CF6FEFC44ULL, 
            0x3F86FBC5995DA825ULL, 0xC3AD477A284C1AFBULL, 0x66E11EB8FC65BF74ULL, 0xC4920F9461C7E16AULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseAConstants = {
    0x13C9655852F98649ULL,
    0x9953967ED09E58F9ULL,
    0x0D41E35D58CEA511ULL,
    0x13C9655852F98649ULL,
    0x9953967ED09E58F9ULL,
    0x0D41E35D58CEA511ULL,
    0x3FE0828E4A8E4EE9ULL,
    0xFF98CFBB529E2489ULL,
    0xE4,
    0x7F,
    0xC9,
    0xC7,
    0x69,
    0x63,
    0x59,
    0x91
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseBSalts = {
    {
        {
            0x8C1B252E9E9F9D0DULL, 0x6B1F4A59ABCD6AF8ULL, 0xF582393141BBACCEULL, 0x2428D2A1DE21C52BULL, 
            0x619775BCB7C5B330ULL, 0x7DBFDF2899E2D03EULL, 0x3035C924516725C7ULL, 0xD0F98D8867A140A0ULL, 
            0xF1AE8C8ADA9D17D6ULL, 0xB72AAA4BDC85AB62ULL, 0xD628CA5780BCFC0AULL, 0xDD1B069769B81B58ULL, 
            0x2D4760613C255409ULL, 0x227119E95EA952C9ULL, 0x413ED5995B8C90C0ULL, 0xC03FFFDD9A8F9FDBULL, 
            0x099E1905124AF6AFULL, 0x5241783AF9E30648ULL, 0xAE99B44308E4B324ULL, 0xBB3BC50DDC05D159ULL, 
            0xF76168559DE0C2A2ULL, 0x8C129CF3DED8CC10ULL, 0x193CCDBB7F18C21AULL, 0x6F956F2CA78F2D21ULL, 
            0x19C17D0921721DE3ULL, 0x885C08A2ED685C23ULL, 0x077CFFFE640B8768ULL, 0xC2E9FE919653C8ABULL, 
            0xA6B7AA94F041FE4FULL, 0xEDFD7F225B760FC2ULL, 0xB2AD05BEA3F7F346ULL, 0x2F7F1EF7B9A7EE48ULL
        },
        {
            0x12C809D5D2B4B63AULL, 0xDF0DFCFF04F4F2AFULL, 0x32BF256244F85B5AULL, 0x11D7D21A9BB7C347ULL, 
            0x47643DDAAB6DBE0DULL, 0xB4E627C10D7B44D3ULL, 0x6D5902B8B6E1B092ULL, 0x9FF26733C3E40208ULL, 
            0x80F39526A1703D0AULL, 0xE4D9A411CC282F62ULL, 0xFC1050E17377BC29ULL, 0xF31726426A27A53FULL, 
            0x4CA6EEBB352A5A3DULL, 0x4492F94CFE78735FULL, 0xC687FC54F15F11C2ULL, 0x5F8134D89033E6A0ULL, 
            0xBC685DACA220EF06ULL, 0x0C4E4B1012415CD4ULL, 0x5BF19201608C34EBULL, 0x475360E46252C95BULL, 
            0xC80A41488AC8B644ULL, 0x60179997F2DE3488ULL, 0x6C1C5A21B7886FB7ULL, 0x0D7C5167C9C4E0F7ULL, 
            0x7DAA40A329D09047ULL, 0xF15B09A98CE158E4ULL, 0x7775E3E01BFC5C12ULL, 0x770B0E389B690F0AULL, 
            0x8110915598F5B85BULL, 0x9223EF4D448DA3A4ULL, 0x42A0C323ED4B649AULL, 0xB5E0011A78EBECAFULL
        },
        {
            0x37F928975E366B66ULL, 0xB3F1606D419574BEULL, 0xD8DDF63AC2A19636ULL, 0x4C8BC1126A662DE0ULL, 
            0xE4ABA3441CF4A1E8ULL, 0x5668DA91A55E3967ULL, 0xC32781DACD6F7608ULL, 0xEBCFF51CBD2AE49BULL, 
            0xA219D35EDCCD99B9ULL, 0xF2300F983C995C31ULL, 0x8DCECD0EF841FEC1ULL, 0xFB049D1134BFACFEULL, 
            0x0A5B696E969ACCC5ULL, 0xA534A291F61EC14AULL, 0x46605E58E60D05A5ULL, 0xD375A53905F89396ULL, 
            0xB6E76ABD18101E61ULL, 0x433B077D8A47C341ULL, 0x8A44AA2FDF189C6AULL, 0xDC7B866DE4F3FA4AULL, 
            0xF41A7A3FFE948E2BULL, 0x52C91FD1246825AAULL, 0x38E0279F34BDDEE9ULL, 0xAE4D6DE9676D510BULL, 
            0x27A6556EAA2A05B2ULL, 0x968BFFD20C38800EULL, 0xDCAD98C41EADAADAULL, 0xB1382B3BED8841C7ULL, 
            0xA484DC3DEBED0C20ULL, 0x3A8DB31512E0566FULL, 0x1EF9B83D24F5EBB6ULL, 0xE5462847AD10FF48ULL
        },
        {
            0x6D2DE89C0E34F4A8ULL, 0x37583643D73CCD01ULL, 0xECD48ADA3044134CULL, 0xCBE85068CC18AC2AULL, 
            0xBB6F5CF5FC37BEE2ULL, 0xC67E2D4CAB661B38ULL, 0x4D13DFCAFC34F847ULL, 0x08C9AFDF75D8C7A7ULL, 
            0x173F13F4D8C6BF58ULL, 0xE32800FC2496911CULL, 0x507B21A6D10A94C5ULL, 0xB5873F94B1B900D5ULL, 
            0xB311EE1811E5A6D1ULL, 0xD81050AF2C33972BULL, 0x9BBB502E98E059D0ULL, 0xFE647381A07CA13AULL, 
            0xEE1D551B47CB9EF4ULL, 0x33D8A1541E33BE3FULL, 0xA349129C8E5E5802ULL, 0xF514CDB16F0D9732ULL, 
            0x6FD8A6C718389D40ULL, 0xA5B57E32C3BC731AULL, 0x5000E4E5FCBBEF80ULL, 0xC1A6B21B53F5505EULL, 
            0x9A4C36C216455E6AULL, 0x8A83DF222D9EF90CULL, 0xDBB3051F79E14EE6ULL, 0x8025CB2E22D8DDFEULL, 
            0xB5759CB644C7AF5AULL, 0xE8537C4632AE5CB8ULL, 0x49703082A1A60D60ULL, 0x403D770BFBB35E56ULL
        },
        {
            0x6490649598D3D4CAULL, 0x635DEC583574E110ULL, 0x26A577FB334ED58BULL, 0x4FEF52C26CAA8554ULL, 
            0x7AE4F4CBC9A1562AULL, 0x425EB505F73E9BD7ULL, 0x224CF9338717C68BULL, 0x8EE4C0383D92D0A1ULL, 
            0x6529C53803254C14ULL, 0xD9B2586AC991B546ULL, 0x32397F4DF3BF00E5ULL, 0x8B3288BD54D40200ULL, 
            0xB49EF32E0031A212ULL, 0x2FC681DED9CA1AA2ULL, 0xD1D12C36FB3E993FULL, 0x35B431FFBE7DFD29ULL, 
            0x1B3B50D278598CA0ULL, 0xA9960674EF1EEF79ULL, 0x1C5333F088D7635FULL, 0xBB350ED62BC39455ULL, 
            0xD5A5AB29480D6975ULL, 0x13F4F88980D1C4F9ULL, 0x641B1B30EA60234CULL, 0x3F45E3001EDE2462ULL, 
            0xE58EAF28DE33B76EULL, 0x99B17C90732505AAULL, 0xF90B98E9F60762C7ULL, 0xB43861E7F0900C79ULL, 
            0x28CA79B7E6433B9EULL, 0x1E5CA1F7C8488920ULL, 0x8DEFE1080A93F1E6ULL, 0x6D5C4E6D8481D1F5ULL
        },
        {
            0x211C2C67D6313988ULL, 0x6F8161D3BB7AE2DAULL, 0xB8A15F35EE4606CCULL, 0xF56C079734EB1C07ULL, 
            0x0759D6F381F24830ULL, 0x975EB830FBC86E6EULL, 0xCBB3763479C2B291ULL, 0x4866ABEFB8E4E24DULL, 
            0x441C077BCE795AFFULL, 0x43B012155CA23450ULL, 0xC7B731300D17CF2BULL, 0xE736B7821E8D0EA7ULL, 
            0x84043527567A3D5EULL, 0x12DC4AFE118210D3ULL, 0x2EABDC6D3AE20472ULL, 0xCAC8D215EDE20758ULL, 
            0xA877AFB7718B5C4FULL, 0xD3FEC54FE13A435FULL, 0x9F371ED605139727ULL, 0x71F232FE6B25A879ULL, 
            0xAE6BCD94B4B4758FULL, 0xAF04F1465EF4F0CEULL, 0xB449E36436933B0FULL, 0x9389569C43B593AEULL, 
            0xA9F016987AF3A11EULL, 0x439EECB620FE12BFULL, 0x6DAC212508A1ECEFULL, 0x2CC445514BFB89B9ULL, 
            0x35D7D52EC8C46689ULL, 0x9B637BB7C6253B57ULL, 0x52DAB7F276064E4BULL, 0x5DA1BDD1664591C0ULL
        }
    },
    {
        {
            0xCA70DD57B00318A9ULL, 0xC97E84EB70B21132ULL, 0xA4031047933BED25ULL, 0x1A8CF9788E3DDD0EULL, 
            0xA608140B9B910AD3ULL, 0x6ADCECDA5F11CA8FULL, 0xE0495862A2401E6FULL, 0x40AA6962597DA421ULL, 
            0x05EB6C018291C816ULL, 0x521C1D914B266A14ULL, 0x63AB3A7ADD60F582ULL, 0x74561E0EBDC823BAULL, 
            0xD44C7BD34465DA01ULL, 0x7CC7EC1E71687054ULL, 0x81D79AF95CCEAD43ULL, 0x570D38EF604CB639ULL, 
            0x10846FF0E90B9709ULL, 0x87DAB15A4910380EULL, 0x53B176A959B20CB2ULL, 0x809267194086A1A9ULL, 
            0x924A80ED01F9D3D5ULL, 0x2CEADC2D36E1E90EULL, 0x6F209A41F2F557EBULL, 0x1FE84BDB1CC2EBBBULL, 
            0x7AACB3F24A434237ULL, 0x5BAF15AE81318651ULL, 0x7F44DF3199D13076ULL, 0x530FD2225B397E4EULL, 
            0xAD5B05742E7AE80FULL, 0x131FF9E5921E50FDULL, 0x196404FFBCDAE8F5ULL, 0x1B378441168D43B7ULL
        },
        {
            0xD9EE303F374301CBULL, 0xEE664D6F8B3064CDULL, 0x6997E2D4C7B0420DULL, 0x42B05551AD714B7AULL, 
            0x4490837D8B3CFDC1ULL, 0x559E38E44C8B82AAULL, 0xD301CB832430CBEFULL, 0x31E71FE569AD791EULL, 
            0xB1AD96AD12AF9B3FULL, 0x966D0B864C9C1FD1ULL, 0x372297B40C709C31ULL, 0x0BB33C4A6F95030BULL, 
            0xECA28F86AE26CB3EULL, 0x35D1518F3FD442B2ULL, 0xED1AB67C2DEB1494ULL, 0x4A7763E270425E0BULL, 
            0x16C93B20CEF49CE7ULL, 0x476669C53C880848ULL, 0xE175DE70DCC3D11BULL, 0xCDB6C1ADEA6389F4ULL, 
            0xEACFD5B19C579F9BULL, 0x5F6CB1DF685C41D6ULL, 0x92CF960B004A10EEULL, 0x9296771931E057C0ULL, 
            0x86BA847022CC9B2AULL, 0x417256F87F102CF9ULL, 0x499E66664B9A69FCULL, 0xE09EA6FE6F3E687CULL, 
            0x83558F5812736517ULL, 0x8C7B88DCF6E2DEE8ULL, 0x627DD15C5D8253ABULL, 0xC2530E7F2B8E00D0ULL
        },
        {
            0xC596C129CCB2E508ULL, 0x5F9843F8F073F298ULL, 0x7D54F0CE84E840A3ULL, 0x20249F89B4800C23ULL, 
            0xCF3DEE687E14BBD8ULL, 0x04CE9F431E601F81ULL, 0x294EE8DB8552C936ULL, 0x45E0E07E633A2CD5ULL, 
            0x5D748783B51DF47AULL, 0x383E9AD3AB142BF5ULL, 0x9F9CA3E6123B0F7CULL, 0x74E4C7B9F3A94BF7ULL, 
            0x83DA2C9207FBDD55ULL, 0x7C570F213A438649ULL, 0x6184E7EAC328FA61ULL, 0x59BF86E981C05C2CULL, 
            0x0475B5279935C25AULL, 0xACC3695BDD8DD754ULL, 0x259803668E5B4A09ULL, 0x12A5F06B287E2FFDULL, 
            0xE8BE1DDDED3ECECFULL, 0x9DD1B26354DCAE84ULL, 0x2E1CC73689017943ULL, 0x260E97C646D5EE56ULL, 
            0x5915EB1700E2E435ULL, 0x6E244D629D3CA6D5ULL, 0xB8D4C9C3D33D09B2ULL, 0x48E124B433910970ULL, 
            0xB3950230E4EDD4D8ULL, 0x883B4608CD8DFFEFULL, 0x8CA3E35FB9AE0391ULL, 0xF71F443FC14AD7A7ULL
        },
        {
            0x6A894356F08D56B0ULL, 0x8ABBF2C5CFE2A341ULL, 0x0A5AABE4BAA88DCDULL, 0x26CEF3DAB575FC41ULL, 
            0x2EDD9E1061582FE5ULL, 0xBC5EB2E3F1954226ULL, 0xE93F94633511D871ULL, 0x69F4772F36EA8E1BULL, 
            0x04A87B41E97797BDULL, 0xAFF37A987AD503DEULL, 0x9E536B153CA052B4ULL, 0x53198AF50DB13CC9ULL, 
            0x2EFE39F887802407ULL, 0x96067862C818A8CAULL, 0x307F641FDA89B194ULL, 0xD8949A6D8B4269F3ULL, 
            0x5AAB21D6B28930D4ULL, 0x28253072A2BD53ABULL, 0x450B3D49B47C8074ULL, 0x05791EF16CF3F74FULL, 
            0x37376EBB9B165B15ULL, 0x3F673ABB1344083FULL, 0x1BC7BFE5858FE3C8ULL, 0xFC12999B4B2404C3ULL, 
            0x2A0A77948393F7D2ULL, 0xA966718F1347A1CBULL, 0xB3085C2A6CD43DEFULL, 0x86961BEBE44A0084ULL, 
            0xB6662E4C7D9B0D0EULL, 0x3A88473F86500127ULL, 0x034CA81F02D67B2FULL, 0xE929C1E569DD8C44ULL
        },
        {
            0xDFF6F98B7D7117CBULL, 0xA1637325F8FFF8A3ULL, 0xE78CD09633C43713ULL, 0x53812C2DC2E56A93ULL, 
            0xB57BF082240A1683ULL, 0xDC8CADB8F5B90F20ULL, 0xE33B8D22BB93E6F3ULL, 0x407DA6CA1F15E7C6ULL, 
            0x253E0C59D727E330ULL, 0xEE82F548FB08EE32ULL, 0xE61B1D006C0F4554ULL, 0x588F6619572B4147ULL, 
            0xEAB90412B5A1DB43ULL, 0x559F5BBA0FB67856ULL, 0x638C8A874A45A4EDULL, 0xF4D378DD8EA12398ULL, 
            0x157C3BCF86D4D37EULL, 0xDB750258CC1074B8ULL, 0x80C4E660A7C8A8E5ULL, 0xB3A16A4971B44F58ULL, 
            0x91E7B6DE2F53DADEULL, 0x038150C8EB179FCCULL, 0xD1DFF49591158C8BULL, 0xB81DAC8E523E8BF5ULL, 
            0xDA89890983EABB2BULL, 0x60890AA78135BA69ULL, 0xE0B0F83FDE96BD9FULL, 0x18E31E66930E9CF4ULL, 
            0x530781452582BA24ULL, 0xE4083875B71C97B5ULL, 0x6DE9021F55F2A2CEULL, 0x83A37B9901B14282ULL
        },
        {
            0x877355C3CDB17D64ULL, 0x842A8188E5C49F4EULL, 0xC6333455EF360A8EULL, 0x268B45C7E10EFA5EULL, 
            0x43250453B1B431ADULL, 0xE54316300B40F8BBULL, 0x400740AE33A13801ULL, 0x88BF29572C690D38ULL, 
            0x4A1A968D809EACD5ULL, 0x93CBCEF5BBC5464BULL, 0x3A2346633416CE87ULL, 0x93CD9BBF787698B1ULL, 
            0x8C3E41F1A5000B75ULL, 0x3B41593EA3F3F1D7ULL, 0xA4719A0AE539537FULL, 0x4AC262E73F1FC442ULL, 
            0xB5BDB5CD0FFE8F79ULL, 0x994A94191D3815C9ULL, 0xF38FBEC24842FA5AULL, 0x1C59DD8DA5375D4EULL, 
            0xDAF514C7E961B3A6ULL, 0xE0C79743B04F0517ULL, 0x38D13A34EC3357D4ULL, 0xE2ABF0BFE4821216ULL, 
            0x28F024AEA5D03DF3ULL, 0xA2FDCAA6D4494BACULL, 0x0ACBD73702FEC6F5ULL, 0xD44AA7F5B5519051ULL, 
            0x1AFB8862046C56EEULL, 0x9888368E82A4EAF4ULL, 0xCB670E7C24DA98F5ULL, 0x0D1275404F82BD6FULL
        }
    },
    {
        {
            0x1061EBCBF015CFBEULL, 0xE3BD64A5271C07B2ULL, 0xBD76544F50A9A794ULL, 0xF03ECACD8E4D4AEFULL, 
            0x75572467DFE08492ULL, 0x10764089705ACC57ULL, 0x6C59B42CACA19528ULL, 0xDC687990207C26F2ULL, 
            0xB1CB1233A75EBB1FULL, 0x5165C6916D12F3C7ULL, 0x469A868114D9BD2BULL, 0x5F2B678C90709F7EULL, 
            0x90FA18AE783F75CBULL, 0x4F1F5ADA141BDD4AULL, 0xFE5A125A3FC121B6ULL, 0xC09DC47CC199EA26ULL, 
            0xB71A9AD51CA0933EULL, 0x1AB3095A6CB65E21ULL, 0x17716B5E28BBA6C0ULL, 0xD8990193CDBC854CULL, 
            0x207830355312C696ULL, 0xFB5308FD045A59F4ULL, 0xB73A2E5F2E96202BULL, 0xB4CFBCB2C7F242E5ULL, 
            0xBB4933D4EC3E8AABULL, 0x867262708388455BULL, 0x7CE15430AF86A594ULL, 0x421CC67DBCD5F68EULL, 
            0x9E2E66E974FE6002ULL, 0x07B2B439DCD963E1ULL, 0x839DC1DE7A7FC8E7ULL, 0x17DF8569EBE9C770ULL
        },
        {
            0xA467543A85328C12ULL, 0xF871DC7F7A553B6DULL, 0x87E487B2A079B965ULL, 0xA272A3090F0AC4ADULL, 
            0xA371C103CFA3E1FEULL, 0x9CC03576301366EAULL, 0xF673216B761895DBULL, 0x8DE259648B0FD5CDULL, 
            0x0A56C0AF7B533A7DULL, 0x21D33F5894BE9AEEULL, 0x56C3F02EC097EA38ULL, 0x6BA601725D5F9D75ULL, 
            0xF0145F48042A5A97ULL, 0xD7BEB160B1C071D5ULL, 0x203D6BC6AED05914ULL, 0x8D52DF0A5C1B9003ULL, 
            0xC2B35576C72A955BULL, 0x08407FD8F3ED25EDULL, 0x10C7FD44A6388F5EULL, 0xFB040233F2334DECULL, 
            0xB53EF8D216356C76ULL, 0x2F7D3FF2FAD23FD9ULL, 0x916F90F2498C8CA9ULL, 0x2FC72C1617492BA6ULL, 
            0x9DD069D38F92CF63ULL, 0x9EAF5DFCC750142CULL, 0xED4167A65166BB81ULL, 0xAA6FBA17990569B4ULL, 
            0xB9207016AF6606E4ULL, 0x2491C157F4149B68ULL, 0x387CED715F5E0EDAULL, 0x082838594FC82C4EULL
        },
        {
            0x3006D45FA212C08FULL, 0xDAB9CD4693C07DA3ULL, 0xAFBBE970907EFBB4ULL, 0xABF7E8DFE9F9597DULL, 
            0xB2780855FFB1633EULL, 0x562997DF4CAEA8DFULL, 0x4D9220DE5A7C9D55ULL, 0x250C8C7132E6C736ULL, 
            0x752616628A288DFFULL, 0xBC198EA65F72DFEDULL, 0xAB87023F550044C8ULL, 0x68218920902349D3ULL, 
            0x244CE38A98A0F01AULL, 0xB3C1CC2AF5203BBBULL, 0x59AB72A67AF624EDULL, 0x6A3C223978331A99ULL, 
            0x77DBE9FE5FD57E5BULL, 0x9819901F7646E28BULL, 0xC41ACD060C4DBE81ULL, 0x68EF3BD38D290EC0ULL, 
            0x877B40887B5AFD94ULL, 0x558F4C14FAA01E08ULL, 0x4ABACD4F677E2F7AULL, 0x333D2F2C9AF3CA8FULL, 
            0x1BC9BF9D8E8FE1FDULL, 0xD157A88CE347BDA9ULL, 0x2701263FAA782E9BULL, 0x05B747F77E9805F4ULL, 
            0xD1F205B33C104FBDULL, 0x87E45AA4C98597ECULL, 0xE43257C67F5317ADULL, 0x90F14F66FBE33F26ULL
        },
        {
            0xC9FA9EC847A97175ULL, 0x9E366C79796B5747ULL, 0xC82AF14180D1522AULL, 0x2BB58ABA784D0EB0ULL, 
            0x9E7B91D49AB07C06ULL, 0xE8459CF005919426ULL, 0x2C10934F2B2F5581ULL, 0xE44724B5B94DA207ULL, 
            0x126C2951F3F040ABULL, 0x3489357CC3D83A75ULL, 0x8BB27B763E7AE231ULL, 0xD7194BB315E63546ULL, 
            0x5C8A8ABE2AD34C06ULL, 0x15606678F7382347ULL, 0x35B46A9BC3C8A149ULL, 0xCD1D747DC7A05CFAULL, 
            0x1D4AD5F42BB7D46DULL, 0xF3E8759D4F2B9EE9ULL, 0x630C9985446F25A1ULL, 0xF16C0C0EE47D9961ULL, 
            0x8DAF4EACA70A5BCFULL, 0xF7BCF22C1D75F69EULL, 0xDA4C2E3DDDB4F60FULL, 0x0DC9741A0AF78E92ULL, 
            0x4496D6F99D3CC060ULL, 0xF5AF99D6BD5AEA42ULL, 0x29653053E2D26284ULL, 0x970878ACA0A3E1FDULL, 
            0x0E3CCD49DBC584CDULL, 0x2AEC4D49ECA14C79ULL, 0xE1402394155F8598ULL, 0x3B99B118BDC5976BULL
        },
        {
            0xD457E1C6F5DCD51FULL, 0x23353079AD520C71ULL, 0x84ACBE75A07C8631ULL, 0x06AA4CD02ED0C2F5ULL, 
            0x996BFF41A745EA68ULL, 0xD7C0A65086A3F4ACULL, 0x243F86A677B13AE4ULL, 0x2744D6F42968EE10ULL, 
            0xF2DCAAD16E535041ULL, 0x07EA3C8DD238A36DULL, 0xA50B6B1DEEF3FF13ULL, 0x12E82BC254A27BA5ULL, 
            0xAE78E8463995A912ULL, 0xF2C4CE40E56ECEA4ULL, 0x9F16B8C3BF3DDA67ULL, 0x6FD3DCB70DA8A7C5ULL, 
            0x3A34AEA37C7BD2B6ULL, 0x2F1FC1F39184E7F5ULL, 0xB0908C227A1CFAB5ULL, 0x45379CEFAE83FC06ULL, 
            0x543635A73E4DD842ULL, 0x6875CA743CAEF81BULL, 0xAE832D7A23BEE3BEULL, 0xA33CE2F459F61ACEULL, 
            0xC1093EFE80D2A005ULL, 0x5F9A1367D59ADA24ULL, 0x4BA971B1A54AE259ULL, 0x2EA657F0B56B824CULL, 
            0x0C2C0B5B322C32ADULL, 0x5F923802B7EA698DULL, 0x8A5C1F71BBF59475ULL, 0xF126BBEE22A5E7F3ULL
        },
        {
            0x18FA33A84E8C1CD7ULL, 0xDD74CC5F1FFEF301ULL, 0x40FCB0461628F1CAULL, 0xC38189A243A63A4EULL, 
            0x4C6C8FBCA5FD48D5ULL, 0x69BE5D6425ACB6F1ULL, 0x1B953832F44264A6ULL, 0xF2F80E62AB07C3CDULL, 
            0xCCEA31F9D4768C86ULL, 0xF230B25975DDE0DFULL, 0x38D53DAC2CCA7D3EULL, 0x12DAAAB1531AE5FBULL, 
            0xAF01BFA441207020ULL, 0x92135A89B8EB9265ULL, 0x2C8D1BD1230D19B7ULL, 0x8089C9B5A8A68890ULL, 
            0xAEFFC34CE6DC022DULL, 0xF5802F196878D1D6ULL, 0xC878CD28476D969EULL, 0xA6B975B1D3064993ULL, 
            0x2E4DFA0CC63EC4D2ULL, 0x056137A7583B1C72ULL, 0xF6B6404F373C82E8ULL, 0x3514223562513E64ULL, 
            0x4AB057BC44027D7DULL, 0xF276CAF97742DE66ULL, 0x643CE4865753F04FULL, 0xFC7D82F81F11BC08ULL, 
            0x96D7F8EE11C1CF2AULL, 0xC472801ACD7C2681ULL, 0x3861E03B6A58D84EULL, 0x16FE1473B4E681D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseBConstants = {
    0x817593C9D308CDF9ULL,
    0xB590ABE8793F336AULL,
    0x35FB94BE1961ED93ULL,
    0x817593C9D308CDF9ULL,
    0xB590ABE8793F336AULL,
    0x35FB94BE1961ED93ULL,
    0xE8889159DCF7FACCULL,
    0x7C25DCDF866CA0D1ULL,
    0xAF,
    0x41,
    0xBE,
    0xAE,
    0x76,
    0xA7,
    0x1B,
    0x5B
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseCSalts = {
    {
        {
            0x1FFC7EE7F20E98CBULL, 0x1FE5A111BCC29F21ULL, 0x6F1E7888FEE74ED7ULL, 0x6FCEDB332C402DE2ULL, 
            0x65168A509449F0B2ULL, 0xEBB5AAAA3470A23AULL, 0xAA07DF53354C7ADEULL, 0x1B475AD302869BE9ULL, 
            0xDF2626D773BA8EE6ULL, 0xF603F8E0240AA109ULL, 0xE0250BF5915272E8ULL, 0xD7DA491354BC9AF5ULL, 
            0xBAB107EFABCB3DDEULL, 0x2BBCB59390C617BAULL, 0xB291735D55B0DF07ULL, 0x4D912972D08F5CADULL, 
            0xC54D9B7E1564ADFEULL, 0xB2550B49F93C2731ULL, 0x2E55F68726687F11ULL, 0x5B67BB525A59474BULL, 
            0xFE70149709F5D3B3ULL, 0x38E204D68FA048F3ULL, 0x134F4E870E13B79EULL, 0x3699D889AED153FBULL, 
            0xEA14980491F05DD2ULL, 0x87B88213A2588F7CULL, 0x4124D6998F0C2EDFULL, 0x27FC1DB428CFD6BDULL, 
            0x68517974A7A9C71AULL, 0x492C585AE08FB4A9ULL, 0xE0033CBD998241E1ULL, 0xFD225036A8B3E4D6ULL
        },
        {
            0xE5FFA3A718A88B21ULL, 0xF3C63B7DEAD7CEC5ULL, 0x21DE9522D1117560ULL, 0xEAACE2729F5C7927ULL, 
            0x9BAAC192C8CEE101ULL, 0xD5C3FD01F8B4F7D3ULL, 0xF8156703FA7B7CE1ULL, 0x114F58F1271CCE39ULL, 
            0x9ABA6C7786DAA3E0ULL, 0xC0F46B53E7AA14DCULL, 0xC5ADB7C12B3020C4ULL, 0x42883054413F7D86ULL, 
            0x38FCE9612CD1E337ULL, 0x9CA0ED2E38EAA570ULL, 0x99A4A851974AAAAFULL, 0x632C77E239D6E8A6ULL, 
            0x8AE36A3748E04787ULL, 0x4DD438358551025FULL, 0xCB138B907C1E4ED7ULL, 0x9B47A125C4DF093CULL, 
            0x30D609F367552ABDULL, 0x900C046093B7712AULL, 0x2CED7368C441E7C7ULL, 0xF5AE9EBDF8E2376AULL, 
            0x704855566CFF0C63ULL, 0x890DDB059849918AULL, 0x94246C65AC323ABEULL, 0x97EA9C3E753C11DFULL, 
            0x1DFB4A7AB65E2102ULL, 0xF3C93C66055E9E44ULL, 0xF649BF58B31A5D5DULL, 0xE27E6DBC1C2CF565ULL
        },
        {
            0x7032B391302DBE33ULL, 0xF2E567D9F92C69BEULL, 0xFF891BAE5BC595CEULL, 0x9E90747E96C6EB21ULL, 
            0x7444BA4DB66C2891ULL, 0x69AE8D6AE3DF0583ULL, 0x8A4274795D318ED0ULL, 0xFDAFBF9E8F49B7A2ULL, 
            0xF786990978A02543ULL, 0x57AA9BDB5C8F944CULL, 0x0FCF0D5544A769D3ULL, 0x87E85C7AC60FB3ECULL, 
            0x81F27A159B30F4CDULL, 0x311915DED52AA897ULL, 0x6FD9FAC2D66ED33AULL, 0x4CA5AAD90DFBF160ULL, 
            0x93107FC2F21FABD9ULL, 0x99E160253C54B226ULL, 0x85E5EC2B09F15A8DULL, 0xA6FE8A4B30CB81FDULL, 
            0xCCC972F9BC71F88BULL, 0x96F11B46EA62296FULL, 0x878BDCA5565CEDECULL, 0x86073AF26DC55352ULL, 
            0x26197B83423A25FDULL, 0x7EE70E7BE3575A1FULL, 0xE94BF5FFB33CA94DULL, 0xBAE5A6ED01B0604FULL, 
            0x3D6B81354273FB8BULL, 0x2450423FF76D62F0ULL, 0xB3066BC3FC10E269ULL, 0xCAE165D541ECCFA0ULL
        },
        {
            0xF55F4E5CF3D2EDC3ULL, 0xEE34B30813988677ULL, 0xA11E7DECEE86D0E6ULL, 0xB31616041DC62BC1ULL, 
            0x0C2AA4FDF552344CULL, 0xB47A4F726935F569ULL, 0xD6FD44A15792D01EULL, 0x8DEAA40CF3BD92B4ULL, 
            0xF01CC33A0A4150DFULL, 0x084C913D642D0066ULL, 0xE98C7C7871B6F673ULL, 0x4CE6E7779E9C97F0ULL, 
            0xCCA29B70E7262328ULL, 0xF7AF80B0EEB7907FULL, 0x66D3765D3A2D7F31ULL, 0xB6E0631287514104ULL, 
            0xCA2A03EA515B9CB1ULL, 0x167354734E780373ULL, 0xFF227A99D36F8638ULL, 0x0A8817CCD04A4020ULL, 
            0x488CD10FBAE8A691ULL, 0xC9D79078A74926E6ULL, 0xA1FF16DAA6370DB6ULL, 0x686F9CC16FA80AC1ULL, 
            0x090E79C8590FFDBFULL, 0x1A36D5AF3543938DULL, 0x75A911AED4B6EDE5ULL, 0x01B5B45C5171056DULL, 
            0xADD2EDFB815C4B21ULL, 0xE139D31B55223F6EULL, 0x5FF86CD2EE906B0FULL, 0x8E3B2135F1F41F29ULL
        },
        {
            0x9BA3375E28C0BD31ULL, 0x874DB887E2C0EE71ULL, 0x7168BE00B3BFA6C7ULL, 0x37DAA510BE2E2CD7ULL, 
            0x5B4CEE3552B15FE3ULL, 0x1D52FD903A16F864ULL, 0x4DFA8BD8103591F3ULL, 0xD97B07278BED18FFULL, 
            0x2E2718C01771C2AFULL, 0x354E8AC2E64CBE49ULL, 0xAF547055CD273C8EULL, 0x60FCD650294ECC56ULL, 
            0xC10C5F38558D3152ULL, 0x86B106B05D0BA6D4ULL, 0x1973383A6B9BF791ULL, 0xE48781F324B58930ULL, 
            0xBBF0393F37FDF26BULL, 0x962A0DA131A4FE74ULL, 0x7B9ECBB1B26F8ABDULL, 0xA746DC42C0F41669ULL, 
            0x405BBACFF03D6645ULL, 0x6DA6B4A7FDBCDA3CULL, 0x2201AC10BF6EDBBCULL, 0x58F6FB60E97E1D34ULL, 
            0x56FA8B96A7C2542CULL, 0xEEDE55292E72E852ULL, 0x528CF8C15BF5A2EEULL, 0x4E3FE665AF50130CULL, 
            0x67AD7D002914E2AEULL, 0x8C0E575FFEE04D82ULL, 0x7A5D2418677EB6B9ULL, 0xF3F99F2310667690ULL
        },
        {
            0xD9CC7CBE4B408041ULL, 0x6D0886368664E576ULL, 0x2F05C75D7DEE5C06ULL, 0x2260D1A880883EB7ULL, 
            0xF631888AB2EC2A08ULL, 0x964566FDE5EFEDF7ULL, 0xA31FE3EA51476E81ULL, 0xAF62CFDC507798F0ULL, 
            0x27F10111B64B1788ULL, 0x1D31EDEE57768287ULL, 0x15652B076BDF5CAAULL, 0x20B473AEB6E4DA68ULL, 
            0x9AB0E6D0F30751B0ULL, 0x91A85A238D5707CFULL, 0x84AA8B8DB957B875ULL, 0xF0C060C2AC6913DFULL, 
            0xC69C8E281E0DA97AULL, 0x5553845D98F2B089ULL, 0x3F22E00D18D0DBEAULL, 0xD763A97E192CD946ULL, 
            0x1064E0726B4098EFULL, 0x2D5BF8B6359EC77EULL, 0x8F095B2598CF31D3ULL, 0x680458A9847F9BF0ULL, 
            0xC2E3B8DBD6DDF9D2ULL, 0x7D2AA874DBABFEBEULL, 0xB7269CE9EA5C6257ULL, 0xAC6790E0BB481DBBULL, 
            0x96B34BCE3BDA8731ULL, 0x8C3D69A63D466A4AULL, 0x7E0D849157E3E941ULL, 0x659C40E6BF9FBE1DULL
        }
    },
    {
        {
            0xB4EA3C96C1EAC099ULL, 0xF0996810D66B86B6ULL, 0xFED182C7F45BE967ULL, 0xCACE0A80DDE4F338ULL, 
            0x2B7E6F7418420A86ULL, 0xC147A150C7059D34ULL, 0xED5F168A7E6F623EULL, 0xCCA513F8DF11FCBDULL, 
            0xC6A79DBFAE2E7FBBULL, 0xAD2FDFBA931A408DULL, 0xFD24DB38FAA5B54DULL, 0x068CD4B64FB36E2BULL, 
            0xD45C6C14F0B0398AULL, 0xA1345E2C616AB5C9ULL, 0x9129510E2912CE32ULL, 0xB71251B975ACCC1FULL, 
            0xDE81D773D25CB161ULL, 0xAE0C777E2942B914ULL, 0x7E6D246FE4F67F86ULL, 0x19D76C596343DC35ULL, 
            0xD3E039625B7B52D8ULL, 0xE375670113ACCE1EULL, 0x9830018FB91F3A58ULL, 0xD57E35F0CF93252AULL, 
            0x9D8B63CA9D04AD49ULL, 0x5158DD67DC325690ULL, 0x29B137CCD531F4D3ULL, 0x51E18288DCE901E9ULL, 
            0x593CD3B4D59F5ED8ULL, 0x4DC6F92E9D133F5DULL, 0x1AB4FF57C699BA9EULL, 0xD897FE714A0211C9ULL
        },
        {
            0x75E3CA917680008EULL, 0x748A4975F6C9485CULL, 0x80E3FEEF195164EDULL, 0x15A3C53B1A87F280ULL, 
            0x2BDD88605F251F49ULL, 0xE9F946437016A50DULL, 0xA7D39313968FEE49ULL, 0x83792981F39DE7E3ULL, 
            0xF8B77DFA87606C35ULL, 0x74E5C85C39013F91ULL, 0x2F3AD14E2C84C689ULL, 0xB40262602C065509ULL, 
            0xFD754A0DDC67ED6AULL, 0xCB79ED88BC52F582ULL, 0xE51F3588EECBF90CULL, 0x6EC2BDA4E5B4F064ULL, 
            0x15788B048F70A9CEULL, 0x7AE81FDF00DF960AULL, 0x0182903EB4F9BB4FULL, 0x3F6AE8A1A607F95AULL, 
            0xF0242E441A641F54ULL, 0xAC109C1B025E6F54ULL, 0x60726F9ECB8740CDULL, 0x68935E033898251CULL, 
            0xAB33CE80D47150CFULL, 0x30B87066BF96639BULL, 0x1DD25CEC27A4E02AULL, 0x5D46EEBA0F9AD3C5ULL, 
            0x196B2A5A7E1CB28AULL, 0x0205C40C833A21B1ULL, 0x1C5BA9C22DDA31D2ULL, 0xB55B9FA43EFF477CULL
        },
        {
            0x3A3AE689EB996B0CULL, 0xF807E857357F6A61ULL, 0x5B5D268BE6BA5E7AULL, 0x4B9CC12244C16CC0ULL, 
            0xDDD92162CAAA37E2ULL, 0x8F7991B5CDC3EB1BULL, 0x8A89992011BF2C49ULL, 0x08BF40A3C663ED03ULL, 
            0x222AB0FC69DE192EULL, 0x7FFAD7541CD2A2F2ULL, 0x69191EA4E159ED68ULL, 0x0275C58535A254BDULL, 
            0x14D6F697A558F3C5ULL, 0x422569362B64287CULL, 0x8D326B76BA946866ULL, 0x716806A6A6F1E67BULL, 
            0xBE25CCF87DA0FF5FULL, 0xBE9C65D23511A5CCULL, 0x3B315391D9A57399ULL, 0xF5A411872B008C9AULL, 
            0x005B84980E02480BULL, 0xA46F7B8D616DAAA5ULL, 0xCFE6D591BCC4A985ULL, 0xB6BF1B179354716FULL, 
            0x149C9E7F44CBAD75ULL, 0x8A352D7D1E541DE8ULL, 0x2FA335966FA3C801ULL, 0x4575F4C2B05CE02FULL, 
            0x74A98D461C815845ULL, 0x5AABEEDFDD26ABB9ULL, 0x05EB787339EF305EULL, 0xFCA68979E5FFB279ULL
        },
        {
            0xF098679747633847ULL, 0x19CEFC08D2497328ULL, 0xF66DF4900FD06D19ULL, 0xB6078E8B806B2C08ULL, 
            0x9167F2EA2F15092BULL, 0x20108D2AB0FCD16FULL, 0x8D0A2749EC5F6CB5ULL, 0x592F93B3D5CE04C1ULL, 
            0x476847CA67F89319ULL, 0xCDAE114EC21E4D33ULL, 0x617BE858ADD3C75CULL, 0x2C700BD925997F76ULL, 
            0x95B91A27CFEC9473ULL, 0x92D61B424B97568EULL, 0xCE0F3685508F3DA3ULL, 0xAD921B85F4C6D440ULL, 
            0x0B3C33C73A204185ULL, 0x9B3E6EAA05F5C886ULL, 0x1A04826B2212C7B2ULL, 0x3B20BF9FFB4D4446ULL, 
            0x097FF6F5A8396A21ULL, 0x172EC74186AD175BULL, 0x76EADECFC3EEB5D5ULL, 0xCA93EBC76B9AB8AAULL, 
            0x78B41CD8118D7687ULL, 0x1A27EDECA859B5A4ULL, 0xDCE9AA0D028816C2ULL, 0xC145B1232739FEA5ULL, 
            0x4E26396DAB9FC86BULL, 0x681DF61FFD7931E6ULL, 0x60E8B00337E57E46ULL, 0xA8D67B3B75611A67ULL
        },
        {
            0xBE1FA088AD392933ULL, 0x8C5E605DBB2643D1ULL, 0xE0A5B13005EFBFC7ULL, 0x3A1083641407E74BULL, 
            0x0A348033658AAE95ULL, 0x7450F17D58E78E5CULL, 0x8F150D80037B0524ULL, 0x837F931178E3555BULL, 
            0x9562EC6257828F7CULL, 0x0608D57416FE176EULL, 0x56136C6463479556ULL, 0x3A69F9DA016A3441ULL, 
            0x6D4821271F3CDBB4ULL, 0x03B7350A1CB03ACFULL, 0x69808B1B45C692D9ULL, 0x675E6E494E495B26ULL, 
            0xBA44D1349CADF47BULL, 0x03DF230F01B9AB9CULL, 0x9481311AEFAB07FDULL, 0x971EBAE3C26ED16BULL, 
            0x308C007E0326A487ULL, 0xA1F4521ED748F3C9ULL, 0x2950BF4E4DF6B744ULL, 0x8584955E48627F80ULL, 
            0x891B5280BCC539A4ULL, 0x0E58CD27784A5C1CULL, 0x5DE604F95A8608E6ULL, 0x68A14C293DCB1E3EULL, 
            0x521FF917F1DBB3FAULL, 0xFA6A4E593BAEA319ULL, 0x8FBB2BE86592730EULL, 0x20E40C1C8745E376ULL
        },
        {
            0x6F7A7FE91BC98D0BULL, 0xD6D0A9C007C49751ULL, 0x8DDBA2A56C71C3BFULL, 0xEB819A3B73A5CCDFULL, 
            0xE166A663079B3EA2ULL, 0x67B975AFCA36F9C9ULL, 0x751635D227FCC709ULL, 0xE5A64B08A59A20F0ULL, 
            0x4E65B3ADC3FBDDFAULL, 0x7D6562515283F4B7ULL, 0x7EB933CF3D32322FULL, 0x7AD31AF462F73E09ULL, 
            0xFF9B49237263C6F8ULL, 0x10995ABE92CE2920ULL, 0x32DE34A0404AC7A3ULL, 0x02670BAA8761132BULL, 
            0x784B08052F9198B0ULL, 0xE59C1796A2148BF5ULL, 0xEC4210CC146B5754ULL, 0xD08A3F9BC52D165BULL, 
            0x63238406359A079EULL, 0x52BC888D73D8137FULL, 0x274FC4C3939184EEULL, 0x8401733848C097F8ULL, 
            0x8C22EA8EFDBEAF8DULL, 0xEF922213580FCE49ULL, 0x107AB0E10F197711ULL, 0xDBA1F2357166A925ULL, 
            0x9C0DA77C3AE670A7ULL, 0x9658ADC2A1419D6EULL, 0x4A5887C551F466FAULL, 0x31613A27BF6E67EEULL
        }
    },
    {
        {
            0x56AA8AE2788E2E38ULL, 0x9C8820EFF06C57A7ULL, 0x78A305E3C85AE33CULL, 0x5ADE1EAF63320A16ULL, 
            0x23146149037F8C6AULL, 0x029C0C2313ACF87AULL, 0x5DCF64A7C55A8DE7ULL, 0x5B0C3F3472B44B4BULL, 
            0x8C78A19D5FB7712FULL, 0xDCD1DD3CABB4C345ULL, 0x2C1EBDF345DCFAC1ULL, 0xE29575DA6540D55AULL, 
            0x8064CF03B3284770ULL, 0x3D7B341DD42EA842ULL, 0x3B69EFD81452F082ULL, 0x7A051E7552900ADBULL, 
            0xDDACACB57749C1E9ULL, 0x9CEFED56C7BCA8A3ULL, 0xE9967A3512CD4D7CULL, 0xC20116873C8EFAA5ULL, 
            0x0E742F442962FB44ULL, 0xEFC3A776C3A63575ULL, 0x3BC368D89A6206CBULL, 0xF3DB4E67DFBD43ECULL, 
            0x019F072507D5B87FULL, 0x788D15D9EBC64C69ULL, 0xA18E29CE29079E8BULL, 0x4B0E9266608791D4ULL, 
            0x91E4773BD3714D5DULL, 0xB5C91FE419ECE1F7ULL, 0x9D27FCCBA43D378AULL, 0xE3E0D72844BDFFACULL
        },
        {
            0xD6043A365ABB49F4ULL, 0x37DB7547DAFAED07ULL, 0x5C137CBEE03EE4D6ULL, 0xF389CBB1399E6FE0ULL, 
            0x699ADE07D28F7219ULL, 0xCDA328420E554A59ULL, 0xA1D66519A42388DCULL, 0xAD84E082E6029643ULL, 
            0x63CA8C54F0BCFF55ULL, 0xEB16E191D804333FULL, 0x58D2675C842F7E6BULL, 0x88D52B1F484F8672ULL, 
            0xAC0A039116D1C9D2ULL, 0x85D534B2C275DF0CULL, 0x3F56533C3616F004ULL, 0xC3189505A80881CEULL, 
            0x29FE11A65F9D7C79ULL, 0x716AD50A9E9C3B91ULL, 0x08408417B314F7C5ULL, 0xE438757CD13CC65FULL, 
            0x0E47F7F61C383837ULL, 0xF790925CD0446574ULL, 0x4EE84F5D8111B52BULL, 0x6C1144D4445FDA8FULL, 
            0x5EDE15B4F47DF1CCULL, 0x5ADFDDCE2A4345BAULL, 0x5E84BDDF29E7531AULL, 0x97657148B2C39A69ULL, 
            0x22BB941F5271C2E6ULL, 0xD30B93FBCEFA9073ULL, 0x6C9449594F0CAA77ULL, 0xACABE1B973A41EB0ULL
        },
        {
            0x31AE35E716038BA5ULL, 0xBA1BC36A3BAE319CULL, 0x6C69C4CE8FC3D521ULL, 0x40E9098A951F58A2ULL, 
            0xA05EC1CBE00DBBD8ULL, 0x54E9DB238E16DF5CULL, 0xB6241CA0EF3D621DULL, 0x598FFF410C446417ULL, 
            0xD303E8CBCC4DB4F1ULL, 0x27EC05158D877F94ULL, 0xC47FB395DF6ACBD2ULL, 0x43B8987E03796365ULL, 
            0xD00F75DF021145B9ULL, 0xCC5BBC26CD8558CFULL, 0xC822E01C4373682FULL, 0x8DDF06FA331FCE9FULL, 
            0x93A0B501061ADE57ULL, 0xFBB39668DB445E08ULL, 0xC4A7848450C928DCULL, 0x7F510325B7E87432ULL, 
            0xCD42AFC6931C643CULL, 0xA1C41C8D61AB00E0ULL, 0x5C0F255D96AB26FAULL, 0x7DA1484C7D52C949ULL, 
            0x4CBBEE2A451097A9ULL, 0x14D35B3C56ED1259ULL, 0xC0F3EF51D449984FULL, 0x478AB6CC6C54907BULL, 
            0x182ED0973A7CB53FULL, 0xD248263CF86442E0ULL, 0xD513DE8AC0D28600ULL, 0x22A2304BB781FCD3ULL
        },
        {
            0x565BD510302864D8ULL, 0x583E5ED3953DD035ULL, 0x8C35B80A712E5356ULL, 0xF72DF7373263D2E6ULL, 
            0x6CC224862C3762B3ULL, 0x43A54FA9DC02DA45ULL, 0x75DFCA3CB8CC6809ULL, 0xEBC4542B983C1E1BULL, 
            0x20CD6049BCD089F8ULL, 0xB52044094CD0D57DULL, 0x4C8536BD32C64F05ULL, 0x33515B4BF44884B2ULL, 
            0xD4DDDB3A15EA14FAULL, 0x12DD8FB9027D3C9DULL, 0x8CDD8EC8A01A3FA5ULL, 0x55F00A2FC8132CDDULL, 
            0x5321560BAF4CC4D5ULL, 0x809BEC9D0C9A644CULL, 0xCD969172E2D788B8ULL, 0xFE9102ADB0EFD9D4ULL, 
            0x3E10B83E920714CFULL, 0x98AC4325D05EA650ULL, 0xA0CF14CB07DBDAFCULL, 0xE69937D524FA3775ULL, 
            0xBB6B504B757A19A7ULL, 0xEDBFEACB5731F535ULL, 0x6A5321C9972E6AD8ULL, 0x05073E239AFADF57ULL, 
            0x95275DEF66B613CCULL, 0x0FFCDA846E2E975FULL, 0x72329DB3B47F27ADULL, 0xCC4F153189DABE20ULL
        },
        {
            0x3C3EB68A470EE12FULL, 0x14C9B0C1683E3628ULL, 0x5E213D66252F5562ULL, 0x325F8DAA8A87235DULL, 
            0x37C4E4EDDDFE9645ULL, 0xDFC5BD0CAAC77361ULL, 0xBFC491A5835CC638ULL, 0x9DBFA8BFFC21F3F9ULL, 
            0x88C23198DA22561FULL, 0x06BD2B5B3A616206ULL, 0xC7D509D18F0D1A11ULL, 0x9483EFDA341EA8E1ULL, 
            0x32327A4690F69F5EULL, 0x05396918A32D081AULL, 0x8C1C69F3158257F2ULL, 0x8DD82123BB06C6F5ULL, 
            0x420CF248ACA2FB74ULL, 0xFE75F810EBC80777ULL, 0xD90EFF3909CDA1BAULL, 0xAFFD43DC420EE01CULL, 
            0x7C4BD0846E4B46C4ULL, 0x0614681EE0D7A19AULL, 0x5C24F354CF2C7C0AULL, 0x2AA6156F81BE2403ULL, 
            0xCBA677E2086F10FAULL, 0x546D13375DE0CCA3ULL, 0x8D116544DA68EB1FULL, 0x68F874BE8BDD723AULL, 
            0x73387EF2D969CCA8ULL, 0x6108A6FA6308974AULL, 0xA37FBA7290CE3051ULL, 0x40F088BF62B4FF1FULL
        },
        {
            0x0D3FFF8FA0462AF4ULL, 0xDCF1C34E1457C0C1ULL, 0x81C245138713F587ULL, 0xA5113134D06D6C89ULL, 
            0xCD4E4B1DE5EAB65BULL, 0x95E9307F74873B1DULL, 0xAD92BB4D5978B99BULL, 0x83D04C50CF5C136FULL, 
            0xD65D5B17F98D88DAULL, 0x2EF7E7006971CC43ULL, 0xDCF9B8FBEAB87B96ULL, 0x96A78D18060584D2ULL, 
            0x7F106BC3671C4957ULL, 0xBAB0C3895F750823ULL, 0x0EC90741C9CE10ACULL, 0x09ADCF624ECCE46CULL, 
            0xD7A7DA7DDA0B48BEULL, 0x3B9E2CF4C7A4359BULL, 0xE216450F0D749D79ULL, 0xA8D8B2A1063D5220ULL, 
            0x221FFE0D91D60AF3ULL, 0xE09D013C7C9A987FULL, 0xC3B3B0119F1D99FCULL, 0xF281E2DEAB558058ULL, 
            0xB18D54720B94323CULL, 0x29D385A012893FF9ULL, 0x5425B7D4358D0034ULL, 0x298BF9696EDB39DCULL, 
            0x5709B8980C372365ULL, 0x9E31A67C1B3AEF89ULL, 0x0505ED330D9525A2ULL, 0x29E6AFD53A5215C9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseCConstants = {
    0xC2D93098C7F1F533ULL,
    0xBE2A980A8B2A0B32ULL,
    0xEF4FA4FAABB8D9A1ULL,
    0xC2D93098C7F1F533ULL,
    0xBE2A980A8B2A0B32ULL,
    0xEF4FA4FAABB8D9A1ULL,
    0x25EC964DB64F6380ULL,
    0xC24F54307D1AFC0BULL,
    0xB9,
    0xAA,
    0xB7,
    0xD5,
    0xEC,
    0x20,
    0x97,
    0x33
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseDSalts = {
    {
        {
            0xAC0870DCDC153459ULL, 0x31B54FCCBE27F6B9ULL, 0x069F1E658D8C7742ULL, 0xFD4840E8E72954FEULL, 
            0x760743708DCAD6A4ULL, 0x0968A7F03A4A7B88ULL, 0xAF004F8568C773F1ULL, 0x8B99EF249432DA66ULL, 
            0xDC5800CAA73EC095ULL, 0xF63B08776B297240ULL, 0x3629FD374C6293A3ULL, 0x4B931D6E5FC27B7BULL, 
            0xE7E5AACEE2494E8BULL, 0xF5FA44B2F1FCAAB2ULL, 0x101DE0E581880929ULL, 0xC2AD61E5B7CF2E82ULL, 
            0xA3EB3FB747DF8810ULL, 0x1C9942B83DF2FC1FULL, 0x65716568AFCCFBB2ULL, 0xA97377BD10D37478ULL, 
            0x1BDE70DD65D488D0ULL, 0x0B2956155EBDDF84ULL, 0xA742E433E98807B6ULL, 0x03B6FC624F979349ULL, 
            0x865C8097D7C5A5B8ULL, 0xFD9BD538D29FA683ULL, 0x7A54C49AD84AAF3AULL, 0x13A0270EDDCF3B42ULL, 
            0x3678713E3BA84C67ULL, 0x6502D1A75B92D384ULL, 0x31486AB0A5A485D3ULL, 0x37923286C0512647ULL
        },
        {
            0x351469F07CC3D860ULL, 0x8AA3DF2C9BA91938ULL, 0x5F45F37997ACFC9FULL, 0x47A3CD27E2F46B11ULL, 
            0xC76A92A7C328FDC1ULL, 0x9616C58CEA0604D9ULL, 0xDE96CDF419B573BAULL, 0x530F14373214070AULL, 
            0xE1CD3004E705B3DCULL, 0xBB0CE14E11705E56ULL, 0xD9BE37C7A8DEBA91ULL, 0xCE0E30C32D7ED32FULL, 
            0xE57534AC8E7106E7ULL, 0x5ACC2B1CC0A66DDCULL, 0x1C6597A6DB3259F3ULL, 0x55C31532BFE5EE5FULL, 
            0x8846303A6BBEA304ULL, 0x90AFE5EAFF7C763BULL, 0x4968291B9F7391CBULL, 0x84120405CBB25AABULL, 
            0xB0090A929CB1F679ULL, 0x587B1920029F83C9ULL, 0x6B4ABC5C451B29AFULL, 0xEEF7F749A878B6FFULL, 
            0x22D6E7FC5ED1E8DBULL, 0xCD22C751BCF83990ULL, 0xBB9E53EAFB096E86ULL, 0x3C11386113AEC60DULL, 
            0x86C3932A226ABA7BULL, 0xD3615E04939B36B3ULL, 0xA7EDEAAE882495C2ULL, 0x1FC4AD909DA64EE9ULL
        },
        {
            0x29722E5B2E8BF156ULL, 0xDF477EB4E73AE1BDULL, 0xA914008F7F61D234ULL, 0xB90E0FB317BC5A0AULL, 
            0x290B576446419326ULL, 0xEBAABADC70718E7DULL, 0x8A8A7F4DC5DCC239ULL, 0x6855AA9127F59759ULL, 
            0x9B9E05D67051AE9CULL, 0x987CB6F6F8601BA6ULL, 0x6E5B29CA62A01133ULL, 0xC71A587A1E21C9B0ULL, 
            0x24D4A9B0DC0338F2ULL, 0x8E57E89A2A542E9CULL, 0xAA2C22FC8EB7418EULL, 0xEE22C077172F7477ULL, 
            0xA9CEE2380126DC17ULL, 0x4625941CFCB9C8F6ULL, 0x27BA9A92DD61F05EULL, 0x36A1373DAAC37691ULL, 
            0x8CD51ECDE2294F5EULL, 0x17BBCE962592C8C7ULL, 0x3951589C05CBF358ULL, 0xB39EF873725F2B20ULL, 
            0x25E58FC5A5E846A2ULL, 0x381F7465056B4AECULL, 0xBECE413AA1A03B8CULL, 0xACF5ADF507554885ULL, 
            0xD5D7923D7BB8F227ULL, 0x5E12EEBE7EF934F9ULL, 0x9C374379B3DA5942ULL, 0x582C8B5791A32E69ULL
        },
        {
            0x67BC3CB96496CF1BULL, 0x2EF9E2C18228CB2DULL, 0x90FC91B68CE1AEC7ULL, 0x5F921223E430BF60ULL, 
            0xCAC5AF7A59939A10ULL, 0xC9CB38301EE7411CULL, 0x32A3F8BB2874DAC6ULL, 0x93220D4C4BA80D69ULL, 
            0xB4E4692024E14ECAULL, 0x22CF9F2B3719FE68ULL, 0xC555C2FBBBBA68B4ULL, 0xE8B61D9F4FC4BCB6ULL, 
            0xA9A2ADBBE7A2D42DULL, 0xC438991934F58D73ULL, 0x92B34F48681B8245ULL, 0x75423C3441F01D27ULL, 
            0x2960D9A15C8C1526ULL, 0xA971A3047B48FBA3ULL, 0x43B06D1952EA4F1FULL, 0x88F69FD05D130475ULL, 
            0xB6C3D9DE694DD28EULL, 0x821933FEFA5BE9ABULL, 0x32B4BFE6F90B7D7DULL, 0xBA29DDC19DDF1B93ULL, 
            0x66FA008C689113A0ULL, 0x3F6D8CA8C643358CULL, 0x8E2A318086F3C442ULL, 0x61B7398839EBCE1EULL, 
            0x0757D247FC0DDEEAULL, 0xED49A0F365BC2CBEULL, 0x222FB0AC82A989C2ULL, 0x2738AFD60FF7705CULL
        },
        {
            0x5E50F5FA3E31AE0DULL, 0x1446656BCD3AFB1CULL, 0x5A082766128811ABULL, 0x95D48CAB1EA8051DULL, 
            0xFA03E51634778AD9ULL, 0x245991E8FE2DEF8DULL, 0xBCF05EFB81921CA6ULL, 0x20E9BCDD74CD5FCFULL, 
            0x13AE383F43DAD9F9ULL, 0x1CC267B34C55EDE7ULL, 0xD8B7B42F33F3A822ULL, 0x3B0427DB7789BBA7ULL, 
            0x4497DAC757F1DA25ULL, 0x817648F7A0F3C1DCULL, 0x3A6DE38983C0DEBDULL, 0x984CB6B9DC9D2510ULL, 
            0x9526D96971737849ULL, 0xED673C51E36B3FA0ULL, 0xF70F787C88799EE1ULL, 0x4D4CED5E16BB64B1ULL, 
            0x452777CDECF07CF8ULL, 0xD017A63FF662B69DULL, 0xAF08B4CEC777E232ULL, 0x13859AF32B2FAAE9ULL, 
            0xA0A1E19E3684E9BEULL, 0xDA996E7702149952ULL, 0x593B8819760A477DULL, 0x75D948A0426219EFULL, 
            0x068D1420CBDBA88FULL, 0x5F41A0D5F35187ACULL, 0xDC252937E8EEB410ULL, 0x5245782082E5A0A8ULL
        },
        {
            0x34D430204573B574ULL, 0x879AF79F06CA871BULL, 0xA690993D680AF3ECULL, 0xBC013F0091570D04ULL, 
            0x7C7F3D84FA3F5792ULL, 0x1662C968A3F89158ULL, 0x63A65B3EAF1719B9ULL, 0x8A96E5C64984CCD2ULL, 
            0x672AC31CC6CEAFECULL, 0xA812C8A67AA81E5DULL, 0x7C23FE932E7EC40CULL, 0x518F2F32B22C94CAULL, 
            0xD1C99A8B5B3A63A9ULL, 0xF7EFC9033787B65BULL, 0xEB7CE6BB316DF263ULL, 0xFBB68F658BE05370ULL, 
            0xBB89719BE0B4AB49ULL, 0xDE7CB1D5DB407709ULL, 0x5AE844C23E251F23ULL, 0x6F3140280373B16FULL, 
            0x92F38D86F183EAC6ULL, 0x08619BDDB341E532ULL, 0x6CC07A37B2771EB0ULL, 0x93A7D43CBF3B4D81ULL, 
            0xD3CD5DA6E4827EDBULL, 0x9F24DA6FB1A4C70BULL, 0x2C4A4C35346CA734ULL, 0x3EEEFBC6E5F3632BULL, 
            0x5C31F6622DDE3797ULL, 0xCA5438E78C92D5A5ULL, 0xCB066FC58D489422ULL, 0x6E67C6AA8476570CULL
        }
    },
    {
        {
            0xE6510FB6CC6985B8ULL, 0x1E42A8DD29F486E4ULL, 0x1217929D417E6364ULL, 0x2ADFB15356BEB30FULL, 
            0x3C059EFD03DEFE56ULL, 0x38708019100072ABULL, 0xD1CF4F42D464BDB3ULL, 0x03238E15F4BC72EFULL, 
            0x4815F8E5253B6D48ULL, 0x38DCC4C3CBB74495ULL, 0xE7A0F4A58C0933C6ULL, 0x909B3384C44B22D5ULL, 
            0x7CDD72820B4ADAABULL, 0xE096758ACAFD4DF5ULL, 0xDAB9766EDA61A960ULL, 0x9B27A0A935390E8AULL, 
            0x768C0181C51C9B3BULL, 0x70427CC07E02C48DULL, 0x419E5EEA0F8614FDULL, 0x7D140AA5E15E4D7BULL, 
            0xDC7CC2598B45001EULL, 0x084B15033C510DF1ULL, 0x6D9F89A2FC4D81D5ULL, 0x521C06D9384B1285ULL, 
            0x41AE9569DE150C45ULL, 0x7C4C9A7AFB0057FCULL, 0x4B12896AFBF2D55CULL, 0x7096DCAA80E841D6ULL, 
            0xF0C60BB3A06DC24FULL, 0x17B088E493954574ULL, 0xEDB4DCC0192EF8E3ULL, 0x65B8180455FB8110ULL
        },
        {
            0xAB5B541CEB7B75CFULL, 0x417C01878D4D2B20ULL, 0x429650A8FC9A8A22ULL, 0xB9C56A4B5B455D6EULL, 
            0xD0E427EAA23D28EBULL, 0x4E8A9BBDB4D98C6FULL, 0xD4C4E4D4D5956E65ULL, 0x61A32358B5BA499AULL, 
            0xDF1B8A9F08753C7FULL, 0xE7EB6611C58E1C04ULL, 0x83635FF598E7DA3EULL, 0x0ECF933B9319630FULL, 
            0x2C7967687230D226ULL, 0xA998BB6AFE0A9913ULL, 0x4E7106F9E782D336ULL, 0xA4F4F33C15A205C7ULL, 
            0xFCA6F632DF671EF8ULL, 0xD91F611F9A4E50C7ULL, 0x4F3412A0D068F3CCULL, 0x637003A7D3B5DF57ULL, 
            0x439DC177AE81C473ULL, 0x7089086AA1979659ULL, 0xB37C99D98CF3FCE4ULL, 0xD2C9941C78E0019EULL, 
            0x3E61C524588A218BULL, 0xB25F06A8366449C4ULL, 0x01BC0BFFEC7973A3ULL, 0xAC850FB7E0F94951ULL, 
            0x476D3F611D15F601ULL, 0xA28B64F6AD3A3FB2ULL, 0x33DEF453A7AA5AD9ULL, 0x45779DFEE52A4739ULL
        },
        {
            0x918B7CC8CE87D48DULL, 0xDF8D1015713E63BCULL, 0x94F98F05C62A02D8ULL, 0xFB71A81A228BB5C2ULL, 
            0xB6BD0DDF8F655D9BULL, 0x2D7774D5B363C106ULL, 0xC6AE47CB3C021C89ULL, 0x2521893D3A7ABF44ULL, 
            0x069D1DD1134EC423ULL, 0x8D57FE102CEC0770ULL, 0xE58B348BA9DE5CF6ULL, 0x960B2E72B9088509ULL, 
            0x29857F925A3EDED6ULL, 0x7113FAA310C84A84ULL, 0x48B52A875188DB96ULL, 0xE33212F99F52D9DEULL, 
            0xA648C5B78D1A638BULL, 0xB43CD7F9A2FDFDAFULL, 0xAAEC190E52FC0D8EULL, 0x8EA0DFF82C46D449ULL, 
            0x0E6CA86612605968ULL, 0x05CF26B6785C6E41ULL, 0x0E116C2B281DD147ULL, 0xAE38879A19CBE9C0ULL, 
            0x53C156AF96925416ULL, 0xDD177DDBD4769A20ULL, 0x6D6B05A97F8C401CULL, 0x8B89EFD33EEF58B0ULL, 
            0x065CD7B3381E2D57ULL, 0x158293F0D4AFEA2FULL, 0x98D3B79CC4119742ULL, 0x93CEDA1DC14FA6D0ULL
        },
        {
            0xCF8A8A1B4CB8EEAEULL, 0xD6CB47785552EAC6ULL, 0xB0D13B942A1AD8D9ULL, 0x90774DA1A287D28CULL, 
            0x5BAA07C098E7EEC6ULL, 0x61776EC4B1647B29ULL, 0x1E391F3857D25572ULL, 0x426BD072953966C3ULL, 
            0xE633B74D0DA130BFULL, 0x0BF4D33A7E772296ULL, 0xDC078BBCA3B002C2ULL, 0x94EAA4E5976B21D6ULL, 
            0x1E9C02063D9FCD8FULL, 0x8CE0C41C60947CAFULL, 0x32E9AF228F3694DEULL, 0xFAA5961C2DD39C87ULL, 
            0xFCCCEC02FED10B77ULL, 0xF3C807CFFD705B56ULL, 0x11156330115A3B4AULL, 0x66867FD4D0FDDFA0ULL, 
            0x95BB70CCE532E0BEULL, 0x5A04DBE4268B9B56ULL, 0xD8182DC809E7C263ULL, 0x87C9EC3AFDCB6117ULL, 
            0x6881D119891C1A90ULL, 0x657C6FF1F64D0035ULL, 0xD0CFBF53BCBD0A89ULL, 0xFA0814883BD6AE86ULL, 
            0xB836ECE4BD110AA8ULL, 0xFB88CCE4F8368FE9ULL, 0x8630DDB1E8D57A72ULL, 0x99D79FA7639B837AULL
        },
        {
            0x5CF44601E2040A5BULL, 0x1AF9CC207F8E834BULL, 0x24AC0695CDDCFE33ULL, 0x8C82BC22CB4E5370ULL, 
            0xDC290B1645432B5CULL, 0x1E2A6F49CE41BBDCULL, 0x18EE25282F282D66ULL, 0x2224B9385F178042ULL, 
            0x0CF655B6584FE35EULL, 0xD801ABD00B1BA9F2ULL, 0xB659057E7F048A3CULL, 0x7C8B134D3269F1DAULL, 
            0x99BB7AA63CF89903ULL, 0xFC6C945E9A144138ULL, 0x1766F5D213C1F711ULL, 0xAE70B9549A0E5A85ULL, 
            0xA7B84AE0B7BFA990ULL, 0x30D73F33A844A1A2ULL, 0x154D3464A44227F7ULL, 0x7EFC31B83A479848ULL, 
            0x8FA07DCB15B25F4EULL, 0xCD4954F763551021ULL, 0xF4A8D87D996A7DC6ULL, 0x9FA58C57373BD491ULL, 
            0xEAB8D070D0E9F558ULL, 0xDDD8FF68CF2488F5ULL, 0xC1BD2051B1BEE7DAULL, 0x2AD85070B837BE72ULL, 
            0x63C337E13AC7947AULL, 0x356ABF25D2BBAD4AULL, 0x4B50B0DA1C68ECF2ULL, 0xC2E5CEC15C425B8FULL
        },
        {
            0x3FF951B2DA92A6BFULL, 0x8E09B0A7F3134E0AULL, 0x1506F12D0A3CC709ULL, 0x7AF0E87D4D110C36ULL, 
            0x9B576A95D289CCA7ULL, 0xFDE11678E7AB2DF9ULL, 0x3523DB098502984FULL, 0xF158581EB3DBB119ULL, 
            0x57364252816752BDULL, 0x8FC45B8B508738F0ULL, 0xD8F42CEF92A097A5ULL, 0xEA1AE2B3247B7A45ULL, 
            0x76A1930E0CE544CDULL, 0x07F03D2154B05529ULL, 0x4D76DD3F09203786ULL, 0x669058D788E60CCCULL, 
            0x54AB5C4A71473585ULL, 0x6FB8C8D5C70DDB72ULL, 0x63C851801F2E6222ULL, 0x30232B115927B3B1ULL, 
            0x22ACEE2C3E5667B5ULL, 0x5B915716B3EA1E5AULL, 0x9DAD9430C6E37208ULL, 0x0B8BD091E1FDCB4FULL, 
            0x1F9867CF4142C21CULL, 0x3653AD894B2CD5B9ULL, 0x2157A8E9FE2C13C3ULL, 0x18DFB3EB98119BB8ULL, 
            0x0CA3CB7FFFE65A83ULL, 0x83A04B5D4B87DB7EULL, 0x866F9D5C7ECC9DB1ULL, 0x2588E3D7B5C6F306ULL
        }
    },
    {
        {
            0x684A93C1C2CB7214ULL, 0x410BB4A84C1B92FCULL, 0x93E85663A642254FULL, 0xBBF6810069B14EA9ULL, 
            0x3418236A647BE4A4ULL, 0xB8F5303B463812C5ULL, 0x65786CE30439C8A5ULL, 0x53FB18F99457F43EULL, 
            0x21E7E2AEE9CF8853ULL, 0x5AD34A4B650162DCULL, 0x5D943EB3671F9C83ULL, 0x9218D7FDC24F7179ULL, 
            0xA70EA6F18E73A9A6ULL, 0xB2C3B54E71C1CB36ULL, 0x67B44E19C3830441ULL, 0xA5D1D67828C720D2ULL, 
            0xA341B1536655DFEBULL, 0xCFFFC8210025DD99ULL, 0xB8494AB767D1932CULL, 0xB1A346675CE98E7AULL, 
            0xF2073568868A4D9AULL, 0xFEC0574FF7E83D82ULL, 0xCC9852C2EA856363ULL, 0x98A27C5DCA22C006ULL, 
            0x13AB61FDBD7ED656ULL, 0xA66ABDD5A0743F18ULL, 0xE35E8A0C5D2B96A2ULL, 0x6478A5E317BA307AULL, 
            0x0E14DD4508C411D0ULL, 0x2D0B09BACADBBA98ULL, 0x880AFCEAB0C67226ULL, 0xED893D6FA2975E1AULL
        },
        {
            0x06FB7764241EF77FULL, 0x6F5DB89FE4866EF3ULL, 0x16300CA672A7466AULL, 0x2A8B404AEFB1E3C8ULL, 
            0xA55A6DDA04159FEAULL, 0x26C9A9B8024D2437ULL, 0xBD9D5AF9AC2A89E6ULL, 0xBDBAF18408BFB0EBULL, 
            0x4A3329597BFE3041ULL, 0xA56C4AE9EDA9AD95ULL, 0x68FE1C7AE409B1E3ULL, 0xF52A0A4B87870847ULL, 
            0x0194B15BE670C450ULL, 0x5CA3E946E2091688ULL, 0xDB82B0737995D380ULL, 0x12BDE321D8B8D18FULL, 
            0x6FA898B7F66D5FDAULL, 0x97FE398D43958590ULL, 0x939935D98B03C404ULL, 0x5FB3676EBA5C64C0ULL, 
            0x3BCAAA5D245AC1B0ULL, 0x66050E85E1880F2FULL, 0x3E0E015B5ECD6C1AULL, 0x9644EFE6CD68579AULL, 
            0xD16EF9B4B068020CULL, 0xAD75DB07C8CDD45BULL, 0x30425B0FB7500E6EULL, 0xC60A324E5A28C53CULL, 
            0xF941BF3D303A1B2BULL, 0x86920E3726BB46ACULL, 0x8AB5B3E9527190AFULL, 0x77DFD5B18DDAC09BULL
        },
        {
            0x7EAFF5264BE69C9CULL, 0x99098B86118ADEA4ULL, 0x51420A3B186A7FC4ULL, 0xEF834C9938BEE577ULL, 
            0xF5F8D054557D33ECULL, 0xC38A1F6BDA8C1106ULL, 0xBA9BAFC46A23CEB1ULL, 0xA3F882D95E53A720ULL, 
            0xE5B75F90D0227074ULL, 0xB3EE3361EC48B24BULL, 0x5B21AF63FA5C7843ULL, 0x4A6032263459C594ULL, 
            0x4803F406E3E31060ULL, 0xBADF4BBD2FF1B9A8ULL, 0xFF0682FD253392C6ULL, 0x146CFB51C7B9659EULL, 
            0xDD37A23BA5A4ABFCULL, 0xD7F6EDD20A2C97DDULL, 0x3549C2EA8EE1D0CEULL, 0xD64DD1BFA35621E0ULL, 
            0x2985099609E2F9BDULL, 0x6EF354AB1106E729ULL, 0x625EF2F322158DE2ULL, 0xEF56145B04FCDCB0ULL, 
            0x0F0ECC86F5222B26ULL, 0xC694F0F272B0226AULL, 0x25120A64ABE26011ULL, 0x51DD4940629563EEULL, 
            0xA53E19FD397E8F22ULL, 0x90D88DB7F60ADBF0ULL, 0x006ECE5B147A6EB2ULL, 0x16E123C326083668ULL
        },
        {
            0xEEB1B476E5B88224ULL, 0xCE5E552830A9F68DULL, 0x8087B5AADAADBCD2ULL, 0x37AD25FA4827049CULL, 
            0xE6E96F5ACB830B01ULL, 0x8AA71A70EE307647ULL, 0x53C47133605EA2ACULL, 0x6BB6D966461F0F68ULL, 
            0x713520A81F77597FULL, 0xD77065AF637E6E27ULL, 0xF2A544DB2235CA97ULL, 0x34BBA0FC13231E7AULL, 
            0x9D0075E948A1C01DULL, 0x09B4427B830123B4ULL, 0xF6F50885CDBF53D2ULL, 0xF077A5D9C6408951ULL, 
            0x843FA2B7ED2672A6ULL, 0x16681A01CF72B899ULL, 0xE2BCFE21ECE946C4ULL, 0x3370659B13699E54ULL, 
            0x5F94CE3EA32F53ADULL, 0xC6F2BC50E7362F83ULL, 0x4C758F47480D1DB6ULL, 0x65C89147C53823E0ULL, 
            0x68E3A563DDE9C49CULL, 0xB4FDFEF8A2704237ULL, 0xAEB546C1548D7B94ULL, 0x3D488FADB8E3D0D2ULL, 
            0x0769FFD94438D596ULL, 0xCDE895805B10C5DCULL, 0x65A645A29D782BC1ULL, 0xA27DA46D7EF364B7ULL
        },
        {
            0x1856E6B4E1876709ULL, 0xC0C8B6D98B8F7EF1ULL, 0xD9E420C90626F74CULL, 0x612D8F76AE467849ULL, 
            0xBCDAC70E733113DDULL, 0xF07F449144C5F16AULL, 0xB738349500579516ULL, 0x891658BF53B19F0FULL, 
            0xB03BF9CFDED467D7ULL, 0x81D95E9921FC23AAULL, 0x2628171BB411A555ULL, 0x11D4DC8A3E169FD8ULL, 
            0x1654655C06A38459ULL, 0xA151956FAF769D28ULL, 0xC8AE57621700BD9AULL, 0x0D78AFBADADB2407ULL, 
            0x4DC89A1E1825EA18ULL, 0xD7A711FFE5B14967ULL, 0x09F0091951CD2ED5ULL, 0xC10433ABD3C237F6ULL, 
            0x2FF159D358931422ULL, 0x9358192710B315FFULL, 0x07B722042A12E40DULL, 0x7F5268699961BC5EULL, 
            0xD51CBE58CD0D802EULL, 0x90D785396FC8245FULL, 0x5A90171353D1854DULL, 0x0A37A64468DA74BAULL, 
            0xE6587780C7DDA80FULL, 0xDE0C45660D98C7E6ULL, 0x51C193274748A4A3ULL, 0xFE2E1204168286CBULL
        },
        {
            0x4C9B7EE84ED8F9BBULL, 0x85C631A66F4561B2ULL, 0x8A91209E206C649BULL, 0xFBA00A9E20241A3EULL, 
            0xDBB981D06AEC4C51ULL, 0xFEACECD659414EEEULL, 0x33846BA75D0A0E9FULL, 0x6421C7C6F52008E8ULL, 
            0xBE142FE0B166B256ULL, 0xBFBF5E021429F494ULL, 0x4BFE5029A89857CFULL, 0x86E4C8CC9F291C5FULL, 
            0x1040B963A8EA265CULL, 0xEA9D969A1922B1B6ULL, 0x8011E8E74AA69654ULL, 0x3910613354592BB8ULL, 
            0xBE095882CD37A8A0ULL, 0xB6F6F3D586FC8DC7ULL, 0x23F48FF9FC64FD00ULL, 0x8F28849D444DF9DFULL, 
            0xDC75AA157BD17829ULL, 0x682AB8C43537F32DULL, 0x51432A1AA4EFA058ULL, 0xEC723D9F5E8CCAD5ULL, 
            0x973D60FC7873236CULL, 0x667B478B55EA0682ULL, 0xB9A4B311ED2633A9ULL, 0x43CA717A9292792DULL, 
            0xF1CFC13D09D9B05AULL, 0xBD748A3F16E6BD24ULL, 0x7A9AF11101E0D52AULL, 0x0C5C64544EA9BEF2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseDConstants = {
    0x43F4CE07DD698ADDULL,
    0x413A47A50D3C15B2ULL,
    0x01EE07D2D1267BB5ULL,
    0x43F4CE07DD698ADDULL,
    0x413A47A50D3C15B2ULL,
    0x01EE07D2D1267BB5ULL,
    0xA267EC4CE9D8E5BBULL,
    0x1939472882376AECULL,
    0x0A,
    0xD2,
    0x18,
    0x6A,
    0x10,
    0x9E,
    0x58,
    0x8D
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseESalts = {
    {
        {
            0xD3C0DA06548C3F30ULL, 0x7F76A548439A6CB3ULL, 0x0D4AEC1B2D82EE7AULL, 0xB6695B7ED113E140ULL, 
            0xA99865245587837CULL, 0x0447E3237BB7F02FULL, 0xDF5745A86C75A8CFULL, 0x26B6153A8C5AA8DDULL, 
            0x23241C65E5394035ULL, 0x549BFBD1C4205EB3ULL, 0x393A1A8F30A3532BULL, 0xD10DC7326AF66D84ULL, 
            0xB7543386D5CC071AULL, 0xACBB42F0F89BB2F9ULL, 0x9D06BD41F5CDDBEBULL, 0xA159F087F5CE6787ULL, 
            0xD9C086F6C15A63D3ULL, 0x57D4D77ED33C6F48ULL, 0x2C40527C90E61667ULL, 0x016C45694268D5FCULL, 
            0x91792CDC677C1E5FULL, 0x460E671AA6273E09ULL, 0xCBDDAB92E2F377EFULL, 0x054BBE9CC46227ABULL, 
            0x6AC3E35CC23C2668ULL, 0x8FB99FB9EA00E272ULL, 0x5DCA6D9AA608092FULL, 0xBA14B52D9947D5FCULL, 
            0x62F6102EC27135F5ULL, 0x2484C0818EDB6186ULL, 0xAEED9951C50C3D8CULL, 0x32FB76D06DA89A50ULL
        },
        {
            0x626FBFCB9A4A6778ULL, 0x566D1555CCBD28B4ULL, 0xE4B71AC55F780364ULL, 0x1BE323372E90CF7AULL, 
            0xBFEEDBF2D87CD69AULL, 0xDB4FAFB494BF40E5ULL, 0x8AE8720073264B05ULL, 0x080D4D3E02434100ULL, 
            0x67CEAE065BC7486AULL, 0xFB7C94562D418A40ULL, 0x8093B0E2D8368DA1ULL, 0x93E7E0B73AD83F1FULL, 
            0x08B702C799E45744ULL, 0xD98DDB283CC166E1ULL, 0x23AA673BD2E51D8DULL, 0xA6FC932A425DD51FULL, 
            0x8406714994570AA0ULL, 0x67E9C2127D4ADC48ULL, 0xF0DE34EB19085A70ULL, 0x0266D7C2800AF07AULL, 
            0x56D0BC95BC0CC604ULL, 0x8009B2D9A42C8BC5ULL, 0x0876EF8D27784359ULL, 0xA93AA073522ECBADULL, 
            0x84E3EF42CF51B143ULL, 0xA0A902E5F970B91AULL, 0x04382D426122B134ULL, 0x38C1BB9DFD03B4C6ULL, 
            0xD3134D132A1B1F3AULL, 0xECB1DD51F456C8E1ULL, 0x89CE75D43A65FB70ULL, 0x5E84FAC0B362C308ULL
        },
        {
            0xDF484C48D5EACF37ULL, 0xD685220A104D09D5ULL, 0x73A336DBFA0775A3ULL, 0xC68E85006F365885ULL, 
            0x3ED08D53FAB7CD89ULL, 0xB9F6102A9D408D90ULL, 0x67209A2337BF4402ULL, 0xA1BEEF3911F31516ULL, 
            0x3673351139739253ULL, 0xAA773A47E18C32BDULL, 0xD8F866DAD9D062C9ULL, 0xCD71AD8DC02FE729ULL, 
            0xA19470A86DB351F7ULL, 0xAE8F651A37B7D528ULL, 0xF768678412A9C338ULL, 0x13984243A1E6073DULL, 
            0x96E76F5E7F460524ULL, 0xC72EFB798C9C0677ULL, 0xDFE437DB2DA56BFAULL, 0x765D3783FDAFF8DEULL, 
            0x94F4DA448DB77BDFULL, 0xB5E85952B34D5801ULL, 0x6BE3C81AB0444976ULL, 0x1959C22B6108DD14ULL, 
            0xB7EC4EDF7475F007ULL, 0xCBCCE112B985F19DULL, 0x7BB7910C14B06D9EULL, 0x0FF39ED2E01AF15DULL, 
            0x2DB7A7DF21E4FE58ULL, 0x060183C82AF4114AULL, 0xC326A145B486800AULL, 0x3602A4F843E25733ULL
        },
        {
            0x7144E9B023B025A1ULL, 0x87CA4E5C073FD4E8ULL, 0x059B52D42C83DEB2ULL, 0x97CE13031518BEABULL, 
            0x282FCE8AA4275DC0ULL, 0xB134391D0F5F9B5FULL, 0xDB9DA680A676CC7EULL, 0xB7E56649DCCA9D2FULL, 
            0xFEFF2B6061C207C7ULL, 0x95E9EC0354EEC61BULL, 0x9A10297B5B671960ULL, 0x98FE816C8553D37DULL, 
            0x4D409284DBDE9F53ULL, 0x72E0BBCA58819129ULL, 0x2FD556240C0C1977ULL, 0xBD0CA083EAADDFA2ULL, 
            0x3FFBB6D5723AB8A6ULL, 0xEF766573FD111EA0ULL, 0xA372A8A8C7A9BDEEULL, 0xE02967DD18447B97ULL, 
            0xC5E14B0CC5D7F7BFULL, 0xC008F0D6EFF6080EULL, 0xFE229A8EDA043BEAULL, 0xAAF200F694953D93ULL, 
            0x693F31CD95332088ULL, 0x1A9346B1FEA6FA1CULL, 0x18A4F045332434B6ULL, 0x9217CDDC85D4BD56ULL, 
            0xA2ED03A14589A193ULL, 0x8C316270DEC9E4FDULL, 0x2E093D3045C0EC72ULL, 0x70EBFB926F82773DULL
        },
        {
            0xB46219A4238D9CEAULL, 0x4989AC2CAD3BAC9EULL, 0x86FC1D6F59B40968ULL, 0x9CB3F78D2A54DF59ULL, 
            0x2F850834A3EA4061ULL, 0x55A196F30A89360DULL, 0x315C69BF1B77E484ULL, 0x6D7A2BB1B0F8204EULL, 
            0x77FC275CEA67F72AULL, 0x4589D8DB303D0A24ULL, 0x170CA9098A3BA08CULL, 0x3E9F1997B63FB591ULL, 
            0xAEF2375DE54C6FECULL, 0xAC3E735095F449D8ULL, 0x6B796B2B11944220ULL, 0x0B657A2F671F4285ULL, 
            0x5C11134B94E2D2B3ULL, 0x6DC7F4150B11D6E0ULL, 0x5B31FA00350BB62DULL, 0xC5CBC4E6CE4963BCULL, 
            0xF421F09AD66469BDULL, 0x5733BFDCCC19C5F8ULL, 0xF27728AB9D9B52E5ULL, 0x0FD30338E35B3AFCULL, 
            0x3A7C2E1584C958ACULL, 0xE96E3A23BB3D32D8ULL, 0x1F3A5BB6E464A616ULL, 0xC131E7F2C6EF7EB5ULL, 
            0x7962011DFA6BB58AULL, 0xCF4AEFF0217407C4ULL, 0x24E0C46557FC1552ULL, 0xA62D43FB9F300BD7ULL
        },
        {
            0xD3BC29E2AAEC2F85ULL, 0x77776894676E60EAULL, 0xCF885438DF959BEDULL, 0xDA4FA42DD5CFB0A5ULL, 
            0x64068BB6310134A7ULL, 0x9E6B43F1FF02C50BULL, 0x6AB866093F44C9B7ULL, 0x7D63042176C5B4B4ULL, 
            0x20D8B762A333DBC5ULL, 0x3F251AE20423A277ULL, 0xA62CDE3B69B2530FULL, 0x9FA932FB2D8E373BULL, 
            0x9A64B1B9C60F70C0ULL, 0x53E86F6A4409449CULL, 0x570DB8E1B572207EULL, 0xCF84FF099A7B3FD9ULL, 
            0xD8FFAA835D3447ECULL, 0xBB430024B498BD22ULL, 0x6436826392D9FADBULL, 0x3513E6A727904D1CULL, 
            0xEA18736A7659303FULL, 0x290ECD96E4A29ACFULL, 0xF20F56CE26A1625DULL, 0xDE68302EC2931EDCULL, 
            0x949BA6194D1678F2ULL, 0x16E4639CC032726DULL, 0x91160E6A8BFB1782ULL, 0x52BD67517C61BE66ULL, 
            0x4E85E8CE25BBA130ULL, 0x7B1A37A7FCA85BA8ULL, 0xECD845AA05CC3DB4ULL, 0x23880E145E552C5AULL
        }
    },
    {
        {
            0x44B8C9916053FFF0ULL, 0x5007C140C13A8621ULL, 0x3A584661B7550B3AULL, 0x8D2240F19A6016C2ULL, 
            0x9F3BCAFD0E19A6CFULL, 0x065DED4A49B0C403ULL, 0xC4E29EF717CCBA4BULL, 0xFC3066094D20AFC6ULL, 
            0x708729DBCD6477B6ULL, 0xEE6D73B650210296ULL, 0xBEFEF216C7C41F5FULL, 0xC573A23B07D2B797ULL, 
            0x86E28CE8EE59A5F4ULL, 0xFD13F9CC49177D21ULL, 0xA1BA68481326D080ULL, 0x0FA9191747D5B16AULL, 
            0xE265C291BBC42C64ULL, 0x005334F7C36B26E7ULL, 0x9257F8600CD37DF2ULL, 0xB4E16BC7C4D47064ULL, 
            0x9D31DA86808D582BULL, 0xE76EFCB253A19D4BULL, 0x7E849F8EE3028FE8ULL, 0x2DC44382DFC4ABF9ULL, 
            0x5FA5736BF19361A1ULL, 0x35D905E42FE0400EULL, 0xE9FDB1BDC845D810ULL, 0x857AFEE29E71F670ULL, 
            0xFB16FA55D1DF159DULL, 0xC924A7E962212592ULL, 0x8316805D814090D1ULL, 0x1098AC1DA4A05F5BULL
        },
        {
            0x437E39A45EEBE9EDULL, 0x6E528E7A25C6F2ABULL, 0xED794BC5B2C283BEULL, 0x340A5EF0EA0A7A28ULL, 
            0x9C854FE270FBE07BULL, 0x6EABFDA775955FAEULL, 0x06CFB5FAAE8584E2ULL, 0xF286F450C4A65A2BULL, 
            0xBCAD972292D9A4DDULL, 0xEED04EC3F3493FC8ULL, 0x22F96DBA08E259C2ULL, 0x9E96A482BC0FBD4AULL, 
            0xCCF3D6F8132350C4ULL, 0x8D5FE1CDC9857A99ULL, 0xD45DA2D99911766EULL, 0xB539C415DC1BF067ULL, 
            0x00E1191FDA51E84FULL, 0x771FF484599341F3ULL, 0x351C81C90EE1A03BULL, 0x867A54C7FD68279FULL, 
            0xFB45B40DBD4C6817ULL, 0x50C5808974BE6F70ULL, 0x5EACFCE436463ADEULL, 0xB5E4C69A6988DADFULL, 
            0x58B97F369CE36A01ULL, 0x880AA0012E11B180ULL, 0x165B2DC566C3F3F2ULL, 0xBB5912C8ADF25320ULL, 
            0x36A878230770CDD4ULL, 0x03917E8B1FD4307FULL, 0xAA046BD059BCD6BEULL, 0xDF40A1F72B3919BBULL
        },
        {
            0x0F0280B0460C0A9BULL, 0x612407306D1DA97BULL, 0xFDC8C800EC406C0DULL, 0x15724DA61FE86464ULL, 
            0x41740B3AFF81145EULL, 0xE93C0DDF4F2F4BBFULL, 0x47200B17043F400EULL, 0xA1113F693E687372ULL, 
            0x3E260807CB179336ULL, 0xD4DED4C03CD06544ULL, 0xC684778CD8DCD0F1ULL, 0x790056F03D02D37FULL, 
            0x12452FD488EC3D96ULL, 0xF93A2AAE2E893BA0ULL, 0x21B4D39D7230CF93ULL, 0x09CE70F80F2B9290ULL, 
            0x25E5A2EEDFD42FBCULL, 0x238089CEF3B02590ULL, 0xB38732ADFEE8E7E2ULL, 0x740E09FE9F709B93ULL, 
            0x6D6E018329408A81ULL, 0xC2DCB1EC020E9ECDULL, 0x53B486A7623F1FE4ULL, 0xB181720D917F7530ULL, 
            0x719265640D1608C3ULL, 0xF491ABC698B7DC19ULL, 0x699B65F20F3DE528ULL, 0xADCAC871672686ABULL, 
            0xC7C458849F3B6CF7ULL, 0x1525F278FF167CBDULL, 0xC7E4732C705852A6ULL, 0x19FC377F9AEA6BE5ULL
        },
        {
            0xF8EF46A7547A110EULL, 0x38C1C5A07FF4D3ECULL, 0x595DADD0C7A5DCD3ULL, 0xADAC1B1B3B0C93C9ULL, 
            0x4A16527D08760C13ULL, 0xB1D7CEA356955A3EULL, 0xA9AAC6BD6DA1ADC5ULL, 0xA54FDEEC8EB21B43ULL, 
            0x2C231B81343DFB22ULL, 0x9015C7949F1B1C7AULL, 0x4F8CDC70660DEEECULL, 0x43C7DA930BE2975CULL, 
            0xE94542BA7E61AD0DULL, 0x1D6AEF3693795A03ULL, 0x0760C54A96F6F71CULL, 0xCAD2E20D2CBA250CULL, 
            0x196CE21DC3089C1EULL, 0x583F7947485EBDD3ULL, 0xE6A46C1C4E38374EULL, 0xE647D15EEBD0EECAULL, 
            0x95822BE592F0233FULL, 0x4188DD63BBE943D6ULL, 0x62179B7175E3379CULL, 0x39C3E7EB581E5A5EULL, 
            0xAFC3C1F373AD30D2ULL, 0x0D835D02BB71E554ULL, 0xD1739C463E569F2FULL, 0x207C3D4826337781ULL, 
            0xC843661667613D75ULL, 0x8F043EB388CF4DA3ULL, 0x6736551DC84D1179ULL, 0x97BB661B93782645ULL
        },
        {
            0xC1715D048CFFE8D3ULL, 0x5DA3460B31522030ULL, 0x3832EDF22DD7E881ULL, 0x3C8E675E955D6647ULL, 
            0xCB0722C647147010ULL, 0xB7A68F0AD267FA13ULL, 0x956F733A94360D03ULL, 0x4BC7F1927250D71FULL, 
            0xA87E51837D6198AAULL, 0x3ECE4A6B0700A03EULL, 0xFAD0468A86C3E99CULL, 0x66D0EA6E234C3FDFULL, 
            0x2F3C7F991BABA791ULL, 0x37DC7A9C0A6A2947ULL, 0x19D369D4847D7CDFULL, 0xCBC3E77079DE301CULL, 
            0xAB2EF50ABBCCA87AULL, 0x56A492305E987020ULL, 0x9B160B159D3C5EB5ULL, 0x5E396EAFAC5CB1D5ULL, 
            0x291B81BB167E8C60ULL, 0xADA8958CCFEF63E1ULL, 0x48B07EA6BE1A4594ULL, 0x2789147893B86236ULL, 
            0xF3ED20A41F609C69ULL, 0xBD9778CFD9186FF4ULL, 0x1CD9C84289DDBCC9ULL, 0x73CEE3631A3BF3C2ULL, 
            0x77DE20D996F3DAEBULL, 0x30C612B83FDF3552ULL, 0xAB0905DC746BD63EULL, 0x227008737239B573ULL
        },
        {
            0x407C18A897555F74ULL, 0x1FC56F92F4EA084FULL, 0x3425915C4C41D2D5ULL, 0x8EDC4B5DBFF27CB2ULL, 
            0x70BF7E6C5D8C1B09ULL, 0x6D0A61AB280A6F75ULL, 0xE21288E46C689C42ULL, 0xC4103DFE144141FFULL, 
            0x62B6CBA257DCD041ULL, 0x6CA5B0DCF0C6BB50ULL, 0xC6EEC212801C01A0ULL, 0x2EE8B2CF93C532A7ULL, 
            0x46364D20A944093AULL, 0x904C8A1CC33677DEULL, 0xCD2849F1D2594F61ULL, 0xE320226CE53C9810ULL, 
            0x192973307C291099ULL, 0x5699D543FB2A2A60ULL, 0xE7F41DBAC822B12AULL, 0x1815CDFB193207F0ULL, 
            0xFC1CA2D83CCC8D34ULL, 0x6B4A97CCF55735CDULL, 0x55115B68694D4491ULL, 0xC746CA1D427E4454ULL, 
            0xE5FF25DE33FB2BC1ULL, 0xBB01E83CDBFF1439ULL, 0x542A9283B6CD1EEEULL, 0xDB19AEF1D56E0B7AULL, 
            0x09AB91529318F340ULL, 0x322085B7E623D0C6ULL, 0xD56A6C3846EF9993ULL, 0xDD931D5EDFA03686ULL
        }
    },
    {
        {
            0x25995C2EBEB02CB5ULL, 0x7215CE5D2293F0C1ULL, 0xBFE1BEB09782FCCAULL, 0x8B747C294AFD6E41ULL, 
            0x6C79A1387FB109EEULL, 0xCAD5A2AB81CD82C6ULL, 0xD68EE43B71050506ULL, 0x36D0C34066883FB1ULL, 
            0x81415DA58F48B00FULL, 0x493C71EFF65299CAULL, 0x9FA70349FDC131B9ULL, 0xCBE6D22267102762ULL, 
            0x579660157056B0BDULL, 0x662D0FA87A67BFECULL, 0x69B2B824815ACD57ULL, 0xBD13BF8D64B80FBBULL, 
            0x11CD76A2D16AB91FULL, 0x00BAE9C9D1B1F59EULL, 0x82DFEEF7F8289F34ULL, 0x8127D545FF981F70ULL, 
            0xA952CEE24CBD61DEULL, 0xEE4D9F06097F3665ULL, 0xA1527E174F9DA6B9ULL, 0x8C7B526F31E252A4ULL, 
            0xAB348E0A22964889ULL, 0x24E078567818A307ULL, 0xDF24019E14D2CC58ULL, 0x273B991BEC12C43DULL, 
            0xAD6994F300F399B0ULL, 0x4D9B0346673782D7ULL, 0x5889DA71B0917B14ULL, 0x883ED1F8A29648BCULL
        },
        {
            0x62963A5961C89BBEULL, 0x2348784485532F98ULL, 0xFADC1AF78F8405FBULL, 0xAE74A373047F15A4ULL, 
            0xEB95E2F9329E7769ULL, 0x2E75B7F072C2EFFEULL, 0xDAF7BB856DD33C43ULL, 0x4DF53E4AF382FFB9ULL, 
            0x627F48FA23C66BBEULL, 0x4DE4F47A89D4DA5DULL, 0xD31C771153BF3998ULL, 0x5C0EF85D935AB667ULL, 
            0xFE23437821209295ULL, 0x5E1A0C8A4CF83D61ULL, 0x4A7383E346D71E61ULL, 0x38DCC01ACE0D7428ULL, 
            0x43C3AE09176C351AULL, 0x1BBA150731907628ULL, 0x7B07784F3837B3C2ULL, 0xF94249D5DA381344ULL, 
            0x1A6AB316B44DEC82ULL, 0x419FE606FB9C81CDULL, 0x2B5CB95562DE6351ULL, 0xE1BF0F957E83B4C3ULL, 
            0xD6DF5449D7A029A6ULL, 0xC5F9C8C2B785AE60ULL, 0x12834BE764526EEBULL, 0x9A03DBDCCE4DBEC0ULL, 
            0x5187AE1C29710A43ULL, 0x2A9BDBC65470D25CULL, 0x7AC6F91019F48E25ULL, 0x256E39A75075AC24ULL
        },
        {
            0xDE63DCACCD0A47CEULL, 0xA41ED75429ADE949ULL, 0x1FADB0FBE7905B41ULL, 0xC8C767AB9DAF0D17ULL, 
            0xEF789761A8D1AAB5ULL, 0x76B9773C91D40C6DULL, 0x4BE1C66BF0E2F896ULL, 0x771E080F798624DBULL, 
            0x6EACEF188450D13AULL, 0x5FD13CD34E44308AULL, 0xEEB33D5E0CF3AF05ULL, 0x9666B13274FCBE75ULL, 
            0x941819DA655E8B16ULL, 0x5606FABD650AC232ULL, 0x6C6FBDCBBE6254F2ULL, 0xAE1B33367FE6EC1FULL, 
            0xFF8BEDB2D8A7AADDULL, 0x543E6746F3162507ULL, 0xD371B5017CAA5760ULL, 0x5481E8682D5408EEULL, 
            0x00F34D3B462CF262ULL, 0xBA541A4424E66DE4ULL, 0xA52BE42AA6F40A43ULL, 0x0BE4DDB0C5AC9E1FULL, 
            0x582ED78F2564B223ULL, 0x72232137A44BF527ULL, 0x62281A314DE8B835ULL, 0x7F9796DF0971ABD2ULL, 
            0x4B02877F58E6BBF9ULL, 0x97646C0B454489FCULL, 0xD6E66236A7AC328EULL, 0x69C1BCA16EC86E0AULL
        },
        {
            0xEE167EBF5C6437A2ULL, 0xCCA06BA985B11A6CULL, 0x23286D8F822975E8ULL, 0x14054141F2EF42C4ULL, 
            0xBE40978E94A0C4DBULL, 0xB9051A9FBB62BDB1ULL, 0xBC0A8BCCA235A029ULL, 0xF6C668AEEA64C14FULL, 
            0x811B2257DF2F14CCULL, 0x9A7D533484C9A972ULL, 0x6AAD4E4C38D77486ULL, 0x323DD9C1D2636F6FULL, 
            0x1C4F7C2F318BFBA5ULL, 0xDF8ED0404497A1E5ULL, 0x4F830D3B0767093EULL, 0x54DB3FA5249668DFULL, 
            0x7732EEDB36020565ULL, 0xCB01CC909F5AC066ULL, 0x0AA77211A6E56B76ULL, 0x4493891DEFFF837DULL, 
            0xAAA5D0637BB5288FULL, 0xAC6141780DC32176ULL, 0xA19CE057B9F1235BULL, 0x262234A07900A1B1ULL, 
            0x4FDFE12A57A9AC6AULL, 0x2008FE15A69881F9ULL, 0x055DBDA32BC73A93ULL, 0x013FC6D9BB7D93A6ULL, 
            0xF0D70E681873423EULL, 0xB38692F49A68C482ULL, 0x0F4715A0BC1E7B44ULL, 0xA84EFFF699389835ULL
        },
        {
            0xF631F744F5663749ULL, 0x438142AECDC45A67ULL, 0x110416E48EB6D041ULL, 0x23985D9A4019000BULL, 
            0x079360DC20393F05ULL, 0x3F1EF140B8C68AEEULL, 0xB45B12F112468D93ULL, 0x8D517B5E09793D9CULL, 
            0x2520BFDC0E20A042ULL, 0xD9D4B116EA968CCBULL, 0x349435DB8520D43CULL, 0x2271D4EF074AC580ULL, 
            0xA6BD0877ACF41BE9ULL, 0xF5FC4C61AA0034A1ULL, 0x8284F0694D4D4230ULL, 0x24E03BB9064F0787ULL, 
            0xFD6A5C2A39920A23ULL, 0x591C4EAFCCC9069EULL, 0x0303ADF11EFB419CULL, 0x0C0E386E176E8D43ULL, 
            0x9FB7E81C71617D2EULL, 0x79AE6B4231F55EF8ULL, 0xCEA805EDE518D182ULL, 0x4B0C2184264C6411ULL, 
            0x2B8C83FF65ABB36DULL, 0x7A6BC7990EBC99FDULL, 0x1C476EEE74265EBAULL, 0x52B21681CF6627F5ULL, 
            0x1BB4FF89ADE3B772ULL, 0x75CBB620183520AAULL, 0xAD478CAD4DEE31FBULL, 0x288F0DEE7771C650ULL
        },
        {
            0x76878F67970EA2B8ULL, 0x425873BA49EEB5DAULL, 0xC720D38481126DA9ULL, 0xDCFEE87EB7E445A2ULL, 
            0xF33DB8BEAE755161ULL, 0x49B1AEF52F2DEE24ULL, 0xEB066F3ED0F3C0D2ULL, 0x88E0EC63AAD8E1DDULL, 
            0x76BE1445E0788673ULL, 0xBBB32DC5D6A835F4ULL, 0xFA1AD2EAC71EA5B5ULL, 0xC9B0C58F8EC69B2AULL, 
            0x071FD8FE2E6E2488ULL, 0xCDC306818386CF74ULL, 0x02E78ADBA599035AULL, 0xFA986D93CF7C0884ULL, 
            0x15B024CE95641A4DULL, 0xFC0908CCFFCF2435ULL, 0x6C1B832A1C49457FULL, 0xA6BDE93F542A94CCULL, 
            0xC2A56C56DE843E18ULL, 0x6D8524BD514E1712ULL, 0x60D3E8D16D8153EAULL, 0x53C77FB07DB202D6ULL, 
            0xA68A7B80606DB688ULL, 0xECB7264C79E9016FULL, 0x7A31A4E314A18B6FULL, 0x6AB880D46ECEE86DULL, 
            0x2F924D11E93FF00FULL, 0x0262BBC45DB5258FULL, 0xF2ECDDAC4A2DBDC5ULL, 0xCCFA5B138B397072ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseEConstants = {
    0xD246E9D21F66E506ULL,
    0x2F145929778D8528ULL,
    0x26CFB3056F1BCFBDULL,
    0xD246E9D21F66E506ULL,
    0x2F145929778D8528ULL,
    0x26CFB3056F1BCFBDULL,
    0xB068C43AABE00BCEULL,
    0x7BE69F9E9E5547DCULL,
    0x4C,
    0xB9,
    0x38,
    0xBE,
    0x53,
    0xE7,
    0x36,
    0xD6
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseFSalts = {
    {
        {
            0x1D9A94BACCFCECEAULL, 0x3F64807E6A2C6CBEULL, 0x666DE0C73F0E8BD2ULL, 0x6DF752F9FC121F52ULL, 
            0x12B2A9A5580E098BULL, 0x59FCA88580458A92ULL, 0x81643B97CF1C7199ULL, 0x802DC0B435313EA1ULL, 
            0x1901BEC59DBD3A46ULL, 0x32DB8D07557A0825ULL, 0xD37C0C1BB191EAEBULL, 0x5DD6D21B35AC1545ULL, 
            0x13A856E3DF08DA36ULL, 0x821C78AE1E8C69F7ULL, 0x20225FE943D257CDULL, 0xF29CB1F33FEF9417ULL, 
            0x620186E29C5E3EB3ULL, 0x6E4BE154F9B3AC24ULL, 0xE1CA8766EFCA85B5ULL, 0x6D4D61A7E8F89F57ULL, 
            0x4DEDC76B2966C14DULL, 0xAD379D312392B65DULL, 0x6A642BC056AFA44FULL, 0x5B2F67AAA8BAF83BULL, 
            0x76DAF2592867FBB8ULL, 0x017FB6F5241011ABULL, 0x85EF612EE5F8B46BULL, 0x498FEBA4229AE653ULL, 
            0x4C5EC7AB9D13A0E0ULL, 0xD827178CFA78BEF9ULL, 0x3AB5F33C7670AE56ULL, 0xD07C0F59BA3C9CD1ULL
        },
        {
            0x69175F29C3D1508DULL, 0xA9D3F7BC6E40498BULL, 0xE237DA7D66868C69ULL, 0xF141D5986187A980ULL, 
            0x2478D8E9A4F7A6C8ULL, 0xB2E5F84A7B0E98FCULL, 0xB3A1BCBEA63F6512ULL, 0x2DFAAB3946ABDD13ULL, 
            0x9D9D6A08D400CC24ULL, 0xFE21793B0A527447ULL, 0x5EEBA11E6AC9B49EULL, 0xC3EA3F8F40C3F8BDULL, 
            0x4D1FDECE6A21CD6EULL, 0x2703248532101A23ULL, 0x738DB04B9D35C8D5ULL, 0x161A819BB48995DFULL, 
            0xAD863CB66E61A010ULL, 0x8C437813BC779EF0ULL, 0xB7741CD13E2CA7CFULL, 0xAC5A7056B8C61883ULL, 
            0x82766FA4830F2C89ULL, 0xA093A789FB3175ADULL, 0x2C7F4055D422919EULL, 0xB76A853519CFB909ULL, 
            0xE027FF50587E2647ULL, 0x4B273F2F19E5AA3AULL, 0xBF9CB8EECB2EE881ULL, 0x1CF6267020B96E3AULL, 
            0xE6D7C52C78085F3DULL, 0xE972ACBBAE89C226ULL, 0x53EC55C667B218BCULL, 0xDFA7857B52F045CDULL
        },
        {
            0xE7300A2B172AB90BULL, 0x397B9E0B2438A515ULL, 0x6D1CCA265EEC5803ULL, 0xDFBB6FB27ECC3F13ULL, 
            0xB891D8033B39C265ULL, 0x02BAB0554BD2F447ULL, 0x951DAB1237CA1CC3ULL, 0xA00A0D845E6483EDULL, 
            0xCE6B7C76433519CFULL, 0x3950227183CCE7DEULL, 0x8C8F00EA903EF99CULL, 0x9E2A27F0E823F002ULL, 
            0x2E4C3AB9BDF0D395ULL, 0x389DB8FDE165DD56ULL, 0x54B4187D3B5A311FULL, 0x473F340A57ED84FFULL, 
            0xA3FA5A2C7EEB9E4AULL, 0x1891EAB40EB45C98ULL, 0x6A24D262A38D333DULL, 0x1CD652C6EEF76828ULL, 
            0x28D2CB2E7F84F543ULL, 0x2FF5A5E55393B241ULL, 0x09960DB6344D9B91ULL, 0xCB0F541A45DFB376ULL, 
            0x6C6CCF67EB4A5A95ULL, 0x274BDAB9639EFA67ULL, 0x12EA4A089BB0039BULL, 0xF066AD95871BFEE4ULL, 
            0xA72117791068B43DULL, 0x6E0B9BE0B84C6951ULL, 0xBE4CF2FC3BBAEB2BULL, 0xE7D74EFA1626D1CAULL
        },
        {
            0x746F59DDCE3B104EULL, 0x419CE1BF7869FDFEULL, 0x6A27759A8F7ECF91ULL, 0xE893CD9EEFF944F6ULL, 
            0x8B311152241BD0BDULL, 0xE69989647AB64419ULL, 0x24A692FA6D79C8E6ULL, 0x4C0E1318AB78E96BULL, 
            0x1BEADF9257CDC7ADULL, 0x8C9CD2AAFDCEB9A1ULL, 0xAD232D262D6B438DULL, 0x2FCC64E75127EA88ULL, 
            0x6B404DA2BCABC3DCULL, 0x839E29220874B886ULL, 0x593DA7482A7F51B4ULL, 0x5AE14D78F0A1CAFDULL, 
            0xB00905F9A3D30B22ULL, 0x6AFB5D533B80F7F0ULL, 0x25B60952BAA6986EULL, 0x3351D8FC54D7CCC2ULL, 
            0xF1BBE19CEB4B6A12ULL, 0x73B42D6A32CBFC3CULL, 0x0B22AE601601DC8EULL, 0xF3498DA389265BA0ULL, 
            0x31F7CEC6379ADCD2ULL, 0x0C6C8099675C2B5DULL, 0x765291A47646CC81ULL, 0x9730F7D3D1F8FBE7ULL, 
            0x03EF20E0E7E16399ULL, 0xE79D5C901945B1AEULL, 0x4D171C66B3830D05ULL, 0x8D814BA7E2E88524ULL
        },
        {
            0x26AD0D321D7309A9ULL, 0x66BB71539E2DDFABULL, 0xEC042D3992A14AC3ULL, 0xD7EC25E47B9F93D1ULL, 
            0x000A74E6A7A793F9ULL, 0x01935B7297F3CFB0ULL, 0x0949076D0129C6DCULL, 0x4F858D18F6A41666ULL, 
            0xEFD4228C9BC18CF0ULL, 0x6FEA125AD5B4A293ULL, 0x003CD95692522EDAULL, 0x2BB6B61264B54F54ULL, 
            0xE1905D2E123C7765ULL, 0x48C32F44AC26636AULL, 0xB6FC19769AC5F67CULL, 0x03A1EE7F76917034ULL, 
            0xE7C514CB7971EAB8ULL, 0x9B2EDCBED644F1C9ULL, 0xBD22C7E7FC84F37BULL, 0x8146298179C97CFBULL, 
            0x3057EAA605C1210AULL, 0x49C065817AE620C7ULL, 0x861992FC6EE0B8BDULL, 0x09B132AAA97854DCULL, 
            0x4C08D9CE318B04AAULL, 0xA5643660AD1F5F32ULL, 0xCF49CE86D8DFF475ULL, 0xBBE27D5599D11DA7ULL, 
            0xB96AB9E3B4A1C716ULL, 0x46A974CCCE0588CAULL, 0xAF67A14117730537ULL, 0x0E735DF43AC0638EULL
        },
        {
            0xE059CFE4CFCE4634ULL, 0x77DC3DE22ED1652AULL, 0x6FA3CEE892239D7BULL, 0xFBEFB867D62106D3ULL, 
            0x9A2CFC5472D2718EULL, 0xB2CC42406E1EA1ABULL, 0x03540DFAC1396FAFULL, 0x057275B297679BCDULL, 
            0xAD9E7D32305C318AULL, 0x96BBF3C6A6699638ULL, 0xD45FC5810E1436DDULL, 0x420E76564A252505ULL, 
            0x03188BEEE3C2A136ULL, 0x729305766B0EC07EULL, 0x4988AE4F03DB1DDBULL, 0x40D9ADB0D8B76FF1ULL, 
            0xE9DF9B51D691D8A4ULL, 0xC43AF55A017A0C4AULL, 0xAA4D2FCD430128A7ULL, 0xB9CCFDD3A69CD6D8ULL, 
            0x15CD711A4495377EULL, 0x889EF27B2A450234ULL, 0x6F69688A1A47D56DULL, 0x13549516515BB617ULL, 
            0xAD1AA2AF51F9EED2ULL, 0x7BEE214A0A1CFF89ULL, 0x4D840F8839C968C7ULL, 0x84FAF64A4540439CULL, 
            0x19B6369694A15152ULL, 0x7C6F49575AAD19A9ULL, 0xD6F08BA9BDC57A8EULL, 0x82A40B61987A0981ULL
        }
    },
    {
        {
            0x1CAE7063AB4A94CDULL, 0x810D8278306B2A0EULL, 0xB485B9EF3780D0F9ULL, 0x7A86EE578141D6AEULL, 
            0x07AAE81284847617ULL, 0xEBC8E884B59BC25CULL, 0x5D3439833D2D4C55ULL, 0xC56B6A4AFCAB183FULL, 
            0x3C3081F869A50E5AULL, 0x13ED8688629DAE24ULL, 0x63B0AB6D89FA6A49ULL, 0x83BF03323F915C7AULL, 
            0x53D2546A40E475D9ULL, 0x472117E4A2BD9CD7ULL, 0x53349C2118C82865ULL, 0x3265D9E09A26821EULL, 
            0xBE5514C9354630D0ULL, 0xA76D5C9B4E8E2EEDULL, 0x4ECFD243FD06326AULL, 0xFF723E5F79DD095BULL, 
            0x58175F91BC226218ULL, 0xAFD4F10227BD7497ULL, 0x5BEBC296ED8C23EBULL, 0x7482A32BEDB388C8ULL, 
            0xCE1CAF01EBFAF148ULL, 0xE7B1736038750440ULL, 0xF5263EEF78FBB560ULL, 0xE0561A7405CFE6CAULL, 
            0x8851D1C8211DA1EBULL, 0xAF2B125664EB2FA3ULL, 0x2D6035F7E92D3E25ULL, 0x4C0D9DAE0731D2CBULL
        },
        {
            0x01E60D0D2F001000ULL, 0xC187A063B456598BULL, 0xB51766D54B091B96ULL, 0x95D50298DC09D06EULL, 
            0x2AB3B6F1FEBCC3E9ULL, 0x727C0E7794EDB678ULL, 0x76D1214F17AF0EFFULL, 0xDECD57BB05E19673ULL, 
            0xC254C683EA2B470CULL, 0x13C562EC21BA7011ULL, 0x7A1340AE784EEA0BULL, 0x2FFCE70E8FD11789ULL, 
            0xCC3EBB29020FD244ULL, 0x609BA0343ED6DB6BULL, 0x2F390BAFF0B21DD1ULL, 0x9A1A71C0DA348D32ULL, 
            0xE7E5347195233AECULL, 0x8759AF7FBE50ED98ULL, 0xDC0133F2C5C68A7BULL, 0x36BA4F9CE44FD8C8ULL, 
            0xF4F65ECDC4741A96ULL, 0x632EF367A9112682ULL, 0xEBF69EBC9A5B3742ULL, 0x1AAB5351605E4B6AULL, 
            0x3AA5846AEC96E25DULL, 0x4E6175854849C54EULL, 0x11A151E06D537259ULL, 0xB9E96DC9C56802F8ULL, 
            0x998870AE94A78087ULL, 0x21537181CF95012EULL, 0xC137C8B8AF4AF10BULL, 0x8940335E8D2896EAULL
        },
        {
            0xA93EBDAF23B8BB92ULL, 0x94128C6A561F8C22ULL, 0x26D1688DBC84D57DULL, 0x0DDF8EDD4E28211DULL, 
            0x27F06CEC5EFFB2D5ULL, 0xB3BAD020D02F822CULL, 0xCED11ECE278E0D88ULL, 0x47FB164CE94D2720ULL, 
            0xFF3C9D5E064F6230ULL, 0xFECB4CAF649CF5E6ULL, 0xF0ADD287AFE78414ULL, 0x76E11D11684B8DB7ULL, 
            0xCB34592997E46729ULL, 0xA5B7ACB38377A382ULL, 0xABF4AF2F272FEFBAULL, 0xE0AE50860215A257ULL, 
            0xC755E8D22524B3D1ULL, 0x3F1B05540D5C4873ULL, 0x9028D5F9B6114494ULL, 0xBAA9B08F1F175265ULL, 
            0xAE27938FE858B45DULL, 0x7659EEC889CA0784ULL, 0xFED058E7A92AD996ULL, 0x63A162DD331FC217ULL, 
            0x9C866DFB8EF84774ULL, 0x0ACB899E0DD510BFULL, 0xC611B3BB9A55956EULL, 0x94EF596693602D5BULL, 
            0x4719566A4826E2DDULL, 0xA5F473FC3FB3825AULL, 0x18AF1E8CD7F90882ULL, 0x386F69878820C216ULL
        },
        {
            0xF9A116F7F1E5A851ULL, 0xEA9B2EF4C51DF1F8ULL, 0x8A101D85CEC72D40ULL, 0x5617B081E402A66EULL, 
            0x0378E91EDF947574ULL, 0x26ACD33E6EC3B88FULL, 0x48E8851B9FFA1B8CULL, 0x4D5CF6272BFE42EAULL, 
            0xE7EA60F59BBBA677ULL, 0x2D26BFC82A06FE37ULL, 0xA9278D0D19955B75ULL, 0x99A18C01320E5C4EULL, 
            0x4BEAA80CA61BAD16ULL, 0x682BE5DA46C92B30ULL, 0x9C30E7CE5865FA39ULL, 0x067397895AFE5A6FULL, 
            0x99A74C843B826FAAULL, 0x101EFA4B852703D7ULL, 0xC6FF51C4ABC4AA0AULL, 0xE6BC376DA1F113BAULL, 
            0xFEA46EAE6DE08FE4ULL, 0x88946335909ADEA7ULL, 0x0E42DCAA357D5517ULL, 0x91E2C2816AE54739ULL, 
            0xADFC28C822F81907ULL, 0xCC2B96E03A949E38ULL, 0x9F4035D75A44041FULL, 0x32A02C9A48E7DB11ULL, 
            0x01A69A680B6B4E8AULL, 0x7C78D051DFD346BEULL, 0xA210601D1582CEE1ULL, 0xCF93E6CAD0AC1D00ULL
        },
        {
            0x9BA2C9B2E2ADF36DULL, 0x72AA9F1BB3DDA3E4ULL, 0xDA515BDC64B06646ULL, 0x9AC3661692488705ULL, 
            0xCDC7E42D5166CBC9ULL, 0xE50F802C089C52FBULL, 0x4AAF9D4C6355AB63ULL, 0x328539B53D1C2A88ULL, 
            0xDF973101BAB5EA87ULL, 0x294C12DDC250F963ULL, 0x7C043FB23774FB25ULL, 0x6CDD2ABEA27FF6F3ULL, 
            0x42F5A8BA379B61DFULL, 0x7C5AB8A4A9300DD7ULL, 0x9C643A0A58EE903CULL, 0xFEC9D2FDA23D6D20ULL, 
            0x08C7DB3C31F4A1C5ULL, 0xAC29B7FF3422F176ULL, 0x23F77653609C6CF7ULL, 0x0C7EDDC367F1F319ULL, 
            0xB2306215BC990184ULL, 0x64096EED19EBD3C1ULL, 0x043339D4E34AEBD3ULL, 0x788C15FAA3DE3719ULL, 
            0xB8AFACC25FDEF634ULL, 0x9B478DF9662E899CULL, 0x7897178E0E4D71F3ULL, 0xDE19D4D16BF16B4DULL, 
            0x1DC2849248851B83ULL, 0x6FEF992CCE4EAE0BULL, 0xC9BA46374302C263ULL, 0x770F815F1F3B386BULL
        },
        {
            0xB9BE289C37BE4F62ULL, 0xACF3F0229F62AB6CULL, 0xE05A27A6C9029B62ULL, 0xD31B4B6A8A375A25ULL, 
            0x21DB2102039A4A35ULL, 0x8C4D447F39B27397ULL, 0xB7E859411CA0CDDAULL, 0x0AF5BE3C0F184E36ULL, 
            0xB9C3BF40DE0DDD2EULL, 0x0A65130870316981ULL, 0x5D6D0A8F6376B6BDULL, 0x6C590B24D95470C3ULL, 
            0xFCC0C290B7FCF6BFULL, 0x9C900A786BDA9536ULL, 0xAA1200332D2963ECULL, 0xDA61AF6E9075B995ULL, 
            0x54F7F31E14442FC1ULL, 0x47AC9851FA1AFF74ULL, 0x56891EBD5444F741ULL, 0x8AAA720864E70BCCULL, 
            0xDDA2C6C09EE47B0FULL, 0x79D3A8A074710C41ULL, 0x7F4085FC45CB4B52ULL, 0x19DE4E10BD54BFE1ULL, 
            0xD1E73F9D948159C6ULL, 0xF14FA23139055AB7ULL, 0xA1928D2610D33CCDULL, 0xEF0D1D3B8BD37FA1ULL, 
            0xC649EA7ECCA0345FULL, 0xF352A9BFB21A9F66ULL, 0x72CD290CFBAB1AD7ULL, 0xC421278EEEAD88CBULL
        }
    },
    {
        {
            0xA3DB95138F415C2DULL, 0xF5DDB08A3CBBFCE3ULL, 0xEF497A4522A07734ULL, 0x291DCAF7EBC2A047ULL, 
            0xAC8B18295E12C8ADULL, 0xA340F54C2032640CULL, 0xB36EA3FE425296F4ULL, 0x47160B70C7E9D296ULL, 
            0x7D3AE02DC4D4DEC1ULL, 0xBADD06B5D6FE572BULL, 0xB49D050E55160FCAULL, 0x51A0A9C004BE9405ULL, 
            0x14F828CA3D5FFC8BULL, 0x3DE585643A2D3F4FULL, 0xA24FB90D8C405ECBULL, 0x9E7927B54F944A29ULL, 
            0x81B6A32BFA4E5167ULL, 0x75D8C09CC71CCFBCULL, 0x2AC079C623A21DFEULL, 0xAB78CC9489217D7AULL, 
            0xF693369C505B40CAULL, 0x0940F4B873FA30F7ULL, 0xBD38B453731E769CULL, 0x5BF840E8594BBF7BULL, 
            0x244A3B545D358551ULL, 0xBE44EEA9749B868BULL, 0xD57D4DDA9FCD9369ULL, 0xB326DAECFDB45CE7ULL, 
            0xC56D2EBA549E92B6ULL, 0x48F75DD2E922B572ULL, 0xFEC435A89EDDB94CULL, 0x50D5E627AD9B0EC3ULL
        },
        {
            0xCDA51B74BF8FDF31ULL, 0x15EFADCD8DFF8135ULL, 0x836982A400DB81EFULL, 0x4FBAC92D6D4C0E84ULL, 
            0x010CD9B4F2B3B0A3ULL, 0x42DE2C5BE17282FFULL, 0x560A22321A7FD9C3ULL, 0x98CE6CB92CF55E2DULL, 
            0x3C2BADCEADF6E70FULL, 0x6EB4FC6B26F0BA2FULL, 0x039B1E9375986B20ULL, 0x344EEA5615B794F2ULL, 
            0x649550A67A9CE86EULL, 0x8ADEB6EF9D9613CAULL, 0xDBDC7DD2816F7C83ULL, 0xA18A1A83E8229E01ULL, 
            0x2F8C5045FE9284CFULL, 0x7C0795E716A5E2D1ULL, 0xB3DE0D3BD2F6E322ULL, 0xD99CAC38D3CBE83BULL, 
            0xD9021AF465FE5CA9ULL, 0xA434335CE807E8EAULL, 0xD7FE5C720AEB35E9ULL, 0x67677FCA6A72B454ULL, 
            0x84A3C7D1D1A216F4ULL, 0x5B97E4F9881BF907ULL, 0xAD50A08A0ED3B2DCULL, 0x948C085C03FCA2DFULL, 
            0xCD2921882DAE3797ULL, 0x1D966EDC6E18032AULL, 0x68D9B3CC9CF6F881ULL, 0x01B094270402C7A3ULL
        },
        {
            0x6723665C04E7A367ULL, 0xACC1BCF8AAC4B7AFULL, 0x72FB6506D99F7CE2ULL, 0xDE70264507CD1189ULL, 
            0x7BD1B28112F28540ULL, 0xE5C234E094842794ULL, 0xBCB88DEC4DEADA55ULL, 0x23832D3C0E648C72ULL, 
            0x2810409D4FE4FBE0ULL, 0xC39F1C6A5E1F5121ULL, 0x5B1C9E7544F85D80ULL, 0x0A6960F5AA0D35E1ULL, 
            0xD854145E463350DBULL, 0xFD0D24A1AF2FDCE3ULL, 0xB08B26BF51DED46BULL, 0x935208D9B7E4D023ULL, 
            0x2DFF0C9D5E86C514ULL, 0xD6DEAA1A2BF4F6E6ULL, 0x1E274037862BED2EULL, 0x9BA3DF9E2574F82BULL, 
            0x2A32E1255EFBFFC3ULL, 0x396A495DF05152F7ULL, 0xAE9D4804A9D74DB7ULL, 0x0DD5F276BEEFC1C7ULL, 
            0xF8823D272093FC8FULL, 0x6D19F41AE5A2BE20ULL, 0x18B480B8525157DEULL, 0x0447081F15094CDBULL, 
            0xFC7D7931E3495E99ULL, 0x3FAB6E9E9E2A75FAULL, 0x7E0F887D5B2D1995ULL, 0x131A0C5E3F0E40E2ULL
        },
        {
            0x5439EFE8A145C0F1ULL, 0x39284D1906A436E6ULL, 0xAF3CDBF9765EA826ULL, 0x6BBDD2E3896A7654ULL, 
            0x2BAD6ECC922F421EULL, 0xED9C90C549997E42ULL, 0x9EA643103AEE352AULL, 0x1B76B08A0F83D038ULL, 
            0xAF3C6A18F3F2DF52ULL, 0x14A4EF1423BBB5A1ULL, 0x377830B6531364A0ULL, 0xA50E5BD71E057E48ULL, 
            0x13C8038FFD0AFBBDULL, 0xE89B22CD09664FB0ULL, 0xDCCBEFD0446B9AE4ULL, 0xE74D1538F2B9C689ULL, 
            0xA5ADFD6ECC5BCC9BULL, 0x37CFC9D2EBE592F3ULL, 0x5E0BDC29E7C4B338ULL, 0xBEDED2FB1D8C2665ULL, 
            0x58EB4F30ACFB7046ULL, 0x98392BB253AB208AULL, 0x47F1DE2C545F8C1FULL, 0x1C09367F347C624AULL, 
            0x906D2696E00178F5ULL, 0x5FD1D96D4705D1A2ULL, 0x7919AF1A8D99AF37ULL, 0xB644DE7103B512FFULL, 
            0x71F3E6CF73D91C97ULL, 0x09A3CEF134CE99BAULL, 0x13FF875B922C6A46ULL, 0x9CC1C5CA332BADB1ULL
        },
        {
            0xB7556630AB6A10F5ULL, 0xB301A003C70BE6D2ULL, 0x6532229CC98C631BULL, 0xA4D2855F8C4F4784ULL, 
            0x119BDC6114741527ULL, 0x1C5A1288B7876FF3ULL, 0xEA9C0DED701906C0ULL, 0x389E87A109B10537ULL, 
            0xCD4A62262128F31DULL, 0xA7EBCA82B6E4FB6CULL, 0x30C1AB6146A2A750ULL, 0x3E2ACB0270E65A3CULL, 
            0xFFB0FF753FC16B96ULL, 0x0019BE51DF554FE5ULL, 0xB1077DB2D42FD96AULL, 0x8FDC051AE73BB426ULL, 
            0x2B07C7F8A22AA2A1ULL, 0x9CE93F187FE26D59ULL, 0x64FB876C0C4F4D9BULL, 0x6110564EDF3BA8A7ULL, 
            0x2DF7CDE7840C3B16ULL, 0xB5B8C2CCD6F99398ULL, 0x74BCA0D9D26AB362ULL, 0x74904421771B7AECULL, 
            0xEE575ADF6D95326AULL, 0x7AB2E2D5975FC84CULL, 0x22E8F50835C740E4ULL, 0xD687D52EABE9B59FULL, 
            0x06F6985BA3C559CCULL, 0x70B7A21123220C2BULL, 0x425B56408DCFB8ADULL, 0xE874F2D421A282BFULL
        },
        {
            0x216E2B91360C2973ULL, 0xC6866495AD5E34CBULL, 0xF3BC3EFCC098F347ULL, 0xAEF327B8D0163500ULL, 
            0xECEA38D44DDC5003ULL, 0x11E2324BA06A9D68ULL, 0xB97976C43588C244ULL, 0x5D48437CCB6C9854ULL, 
            0x513F2BBBBA3349E2ULL, 0xB5F5DF0EA540FC8AULL, 0x8DAB6B5102ADEB23ULL, 0xABB67CB399A3DEE4ULL, 
            0x78FD2C08D7BB98A2ULL, 0xAE417294B37998D9ULL, 0xFED84C72DC020644ULL, 0x9BA3E8BFBBB7E035ULL, 
            0x004ED2B50879F2C9ULL, 0x6EB92913F8413E59ULL, 0xF67A8A11406FBB4BULL, 0xCF6949D7CE6E3F6BULL, 
            0xC7EABCE719E012C5ULL, 0x77DED397DEA80177ULL, 0x576F3DC67F6DFE6EULL, 0xEDC9DA7943F8629BULL, 
            0x51030596DBEF7B9DULL, 0x795616E449D26A6BULL, 0xD723EBC1ECB67845ULL, 0xD9149AE344E2B7B7ULL, 
            0xE7618BF711C0371CULL, 0xFECFE625787D753FULL, 0x473B1406A3AF49F8ULL, 0x5995D190969DB0EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseFConstants = {
    0x95E82430BD6A2A62ULL,
    0x8264527B7A54A88DULL,
    0x8F2C35219C55E190ULL,
    0x95E82430BD6A2A62ULL,
    0x8264527B7A54A88DULL,
    0x8F2C35219C55E190ULL,
    0xCFD7A73465A6500AULL,
    0xA6E397E3E38BA67DULL,
    0xC8,
    0xE2,
    0xAA,
    0xE6,
    0x6C,
    0xD5,
    0xF6,
    0xC9
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseGSalts = {
    {
        {
            0x830A5F25D1B86134ULL, 0x6A6961BB4200543CULL, 0x8AE904DC75A54108ULL, 0x3255097FDA8B7D4DULL, 
            0xD8D84913E87A5769ULL, 0x6BB6FF09AE051A12ULL, 0x162D3B5F218635B3ULL, 0x638523F9CD6EDADEULL, 
            0x90321E5EDDAC6A1FULL, 0xFDF67A88AB2B1E0EULL, 0x0AC1CDC2639C6C16ULL, 0xE697D0D277D696C3ULL, 
            0x3AF1E2C229EC75D1ULL, 0x3B2825DC83CED7DFULL, 0x879EA96B63752556ULL, 0x5D4A4F6320C6E62DULL, 
            0x2750023ABA3A38A7ULL, 0xC5BD85A146C7AFA3ULL, 0xCADEA2B141D891ABULL, 0xA0F2220017C30584ULL, 
            0xA426B6611E600BE1ULL, 0x2F386B49A9D0EB70ULL, 0xCB2AB54CADD021FBULL, 0x148655556DAE60D6ULL, 
            0x0083975DF92F3312ULL, 0xA722A801FB536341ULL, 0xD42D8899893ADF22ULL, 0xDCBB6FDB20F9B753ULL, 
            0x5CECFEED0081D8A2ULL, 0xE9BE50DFE4219DFEULL, 0x152ACBBA5933DC67ULL, 0x771F89206440A6A7ULL
        },
        {
            0x41BA7635D415E0EFULL, 0x1F531E512E767019ULL, 0x5A7E965298C9C759ULL, 0xA35018B694697741ULL, 
            0xD186C42D4CD82F81ULL, 0x2CADC05B7284995CULL, 0x07B6367EF937F60DULL, 0x4C420D5B36DDB1CBULL, 
            0xE06E0EEF2ABA6E91ULL, 0xD2B491155B21D8FBULL, 0xF5C064ECF19B5CB2ULL, 0x10952AFD11D744CDULL, 
            0xE128B3C6C6890DB4ULL, 0x16C9CD85F64B69D7ULL, 0x21AA045467F63579ULL, 0x2D1B7D1A25F0791BULL, 
            0x7DD5B13F0F575D68ULL, 0x4512C2D542408629ULL, 0x03853958C5BE5CC1ULL, 0xB4CAFB91601E1CFDULL, 
            0x511F6A637D5F9531ULL, 0xA960A585AE15D647ULL, 0x63E170086C9C1B3CULL, 0x727E5F2E6D614A6DULL, 
            0x24E405BE9B08C248ULL, 0x3B53A34CDA8AAF0DULL, 0xFD0EEA85EA9C57C8ULL, 0x87E967095EED14F6ULL, 
            0x3341077FFBF593E3ULL, 0x1B4EEC1491C3941CULL, 0x272D096C0AA0E9E3ULL, 0x3BC5BB7A94E2BEA7ULL
        },
        {
            0x2CD56C55F58A7EC2ULL, 0x8FCDF8DFB81EFBD0ULL, 0xAFBD0A93F722F795ULL, 0x1E4D2AE684F67BCAULL, 
            0x157B97038021ABE8ULL, 0xD38F5AA347F37DE5ULL, 0x07FCD161F27F66A1ULL, 0x448C530A09FA82CDULL, 
            0xAA93A84CA7978E77ULL, 0x6025297897BEB42DULL, 0xEED4E357AFC0AF4EULL, 0x015D29D52D130DDDULL, 
            0xD3DD5851F0535139ULL, 0x8BD6F61C19FE16B7ULL, 0x9F3FB4AA676A3564ULL, 0x8079FC5C03F9C0ACULL, 
            0xB683DC657808CEB3ULL, 0xCE3577E5EC78345CULL, 0x27B035A4C2DBE381ULL, 0xAD0D5F9A2DD8229FULL, 
            0xEF866AF2D37C6C38ULL, 0xDF67870FFBDDCC33ULL, 0xFD4C8C0E43E5F4E0ULL, 0x74D4C63EF626DDE6ULL, 
            0x5AD0604584E912ECULL, 0x403A575D213698C5ULL, 0x5AF3ECDDDECA9E90ULL, 0xDEFE68953F848683ULL, 
            0x1DFA675DD76480D7ULL, 0xF25D50D2E67D6EA1ULL, 0xC578975D9347C84AULL, 0x00E9DEAFBB97B0D7ULL
        },
        {
            0xD91EBFA507A541A1ULL, 0xE5DBF54D74AFB97CULL, 0x3E0607DC59F3C1F6ULL, 0xC58A50C252CEFE26ULL, 
            0x3C68C0801AABBE7EULL, 0x2938D3394296A476ULL, 0x9AA98E7876AEBF76ULL, 0x12A8BF9AEDC19ED3ULL, 
            0x30E271CFAE6CFE74ULL, 0x4AEBDAE6D743CDD8ULL, 0xCC49E09326AE3F55ULL, 0xD8493A6A73F61548ULL, 
            0xC60D3D6FA0AE06EAULL, 0x0286213BC87AE6B9ULL, 0x90A6A2DA8D597015ULL, 0xEE124E06B8B7C1FCULL, 
            0x46D57E68FC4AA07AULL, 0xDFD50EF56EB74047ULL, 0xD7A2250CE9DC63CDULL, 0xE5F591AD76926854ULL, 
            0xF23FF3CA5B9447D0ULL, 0x9B38FC56DC8F43E4ULL, 0x51B7019A8AB335F0ULL, 0xE8119072CE40E4A0ULL, 
            0x10471C9A901BD31CULL, 0xF4A64EC290DE4525ULL, 0x131C7A7782596FA1ULL, 0x49CC362E4453636EULL, 
            0x6436ACAF1C751970ULL, 0x1BAC2FBF1A6A920FULL, 0x6781BDB0B1BB257CULL, 0xE195AEED54327EE6ULL
        },
        {
            0x0E89460681FFF7D6ULL, 0xFFAAA7B8F0E6E5BCULL, 0xBD25F992F242CB83ULL, 0xE8FF3E6C9C59B463ULL, 
            0x8507FB4DDFC464BEULL, 0xBE283A38D6AD006DULL, 0xA3D201B20700C058ULL, 0xF2D3E47F5AB25AA1ULL, 
            0x5B2DFAFDB4BEB0BDULL, 0x2E74D50F4FEC96B4ULL, 0xB1210679D647B090ULL, 0xAC46BBBEDAB03676ULL, 
            0xF86002845994277FULL, 0x9B0A5D29862E7209ULL, 0xC6F2F371FC33F421ULL, 0x5F89DBED6E41FBCDULL, 
            0xDCCF99B1FE072886ULL, 0xDDE22DCAAE5C1E4AULL, 0xDE4ECE8410BE04A3ULL, 0x258DD095C2059BA4ULL, 
            0x51F1CBEB5109E3A8ULL, 0x0D8A7DF96C4EBB46ULL, 0x5D7D5925364F241DULL, 0x142650EEE20CF22AULL, 
            0x0B4F8C1D7D348F9EULL, 0x6E6C95ECDD56CFC6ULL, 0x1800298BF56DB09BULL, 0x95B96BD16CAEC8CCULL, 
            0xB8F79BF98187FD58ULL, 0x206EFF23CA68091BULL, 0x2928D5959B7583A4ULL, 0xA4A16F6FC7AC317FULL
        },
        {
            0xEDF5C2A12ED984CDULL, 0xE5FA2FF347ADC398ULL, 0x17E947E64E9D1544ULL, 0x78B5F28C6D978ED8ULL, 
            0xA4941EB9D17B941CULL, 0x73A0ED3C6FE662F5ULL, 0x8E3B051FC75AE006ULL, 0xF4D65AC96F692C3AULL, 
            0x19498602AD992D31ULL, 0x0D8BB7FA4B32D90AULL, 0x0513CFB23724FF13ULL, 0x07733D6EFB666980ULL, 
            0xCEE7B4A4677F45DCULL, 0xC6D32E5A7F9D0430ULL, 0xB4F7B5BD86D9121EULL, 0xEEA9233E9CACB874ULL, 
            0x8D138D27F48D2E89ULL, 0x8AF03FED6F5EDA86ULL, 0xE06A413BF9067773ULL, 0x1D977AD31D15881BULL, 
            0xAD225170DE0E431AULL, 0x7164CB6E2BA00AABULL, 0x318902168E96FF7BULL, 0x39E9739AFA05C83DULL, 
            0x2A012FBD392A3C21ULL, 0x5786E9582C07C21FULL, 0xF14B8515D460836AULL, 0xC8A5E5F2DC18BB45ULL, 
            0x144E7D94ADFB1639ULL, 0x06A01A31F2FC66AAULL, 0x69A8622749F54985ULL, 0xC69C90FF7E9306C8ULL
        }
    },
    {
        {
            0x7909090B4EAE8177ULL, 0x0653092F6B8BB7A3ULL, 0x96CB7263AEC83B4BULL, 0xC8098EF782ADB571ULL, 
            0xC513D126AF526A95ULL, 0xC94A293AB4041B53ULL, 0x3E198578089B2930ULL, 0x085A51B745D96A3FULL, 
            0x3A17D3C2C95B636AULL, 0xD50E9027359A9B8FULL, 0x4452E159C4EE0BC3ULL, 0xFC4485846F4215C0ULL, 
            0x5FD194D8477CE9AFULL, 0x45A222A330D2415DULL, 0x17D539D5DD79310CULL, 0x316CC4AF9E33A465ULL, 
            0x94D52AFD199FB3A5ULL, 0x0E2FD2760BAE0F48ULL, 0x428DD7DCE1F38069ULL, 0xE356A332BB7F8EB7ULL, 
            0x3D86038749695FF9ULL, 0xE239F9DFBFCACEBAULL, 0x70B824428A5F1CA4ULL, 0xE7B5D987936F3A02ULL, 
            0x15D9F41566B0FDF8ULL, 0x4A16696C41277BFFULL, 0xF56ED31A68EBA87DULL, 0x297610B8B3BED102ULL, 
            0x3E73475CE7396B02ULL, 0x2C09E35DB9880601ULL, 0x0D789019D9D2C321ULL, 0x752A2561EA489A19ULL
        },
        {
            0x5FB2230BF5435D45ULL, 0x01B2DC38FAD75A98ULL, 0x5EBC0212074BC415ULL, 0xFCC4216E10217FFFULL, 
            0x2775B8AC62985455ULL, 0x6DE64A566D25C976ULL, 0xEAB27BF1F94AF543ULL, 0xCDC964AC44E98075ULL, 
            0x8620BBF069E35A4AULL, 0x1224351EDBC26E68ULL, 0x7EBD333A4E98A287ULL, 0xDF1E9877524A3053ULL, 
            0x538C07F520AA2351ULL, 0x5713E4E1F64E8511ULL, 0x287DA7E41F2E4CD2ULL, 0x2AF491F86AB0B526ULL, 
            0xC7AEAE685623374FULL, 0x91133F63373A4F7BULL, 0x7E1A5D9AB3FDC899ULL, 0x9E165232A9B3979DULL, 
            0x7AA06F961661C7FDULL, 0xA6778358C65EC566ULL, 0xFFC34FC221BE84A3ULL, 0x160FC40CBAC1F2C5ULL, 
            0xC318ADE9A03EF069ULL, 0xCF1A509359367361ULL, 0x6608657EB2AB8EA7ULL, 0x470810130C66F6FDULL, 
            0x23653A9EE1DCEAE8ULL, 0xE6885A1C2998BE06ULL, 0xCBA936581F107221ULL, 0xD667F5DE97701F11ULL
        },
        {
            0x67544AEEF3EA3E5FULL, 0x6AF226AA0939621AULL, 0x1E5193E8423EB340ULL, 0x0B9CA8524C5A84FBULL, 
            0x92636301A42B900DULL, 0xC2862AF5AF46994FULL, 0xCA321F6879FA3EDFULL, 0xC31A531744DDEFBBULL, 
            0x16889D0767E41F5DULL, 0xF0B5AA15F3A135B0ULL, 0x86660263CA5E77EBULL, 0xA963D8E482E253D1ULL, 
            0x84D1155190C5A812ULL, 0x99D80FF998FBC7A1ULL, 0xBA756C696C951791ULL, 0xF68A4F70E8862A29ULL, 
            0xBDAC8DD86EDD058CULL, 0x8C6E9BE83BC74FDFULL, 0x71C5F8C19888ACFDULL, 0x1D4F93374B8C5287ULL, 
            0x115C6A818C4E94AAULL, 0x577A76FA5FF133CEULL, 0x2DE8C4E12374BC27ULL, 0x54331AD44D0F4A8DULL, 
            0xFA86CF98AA0C4238ULL, 0x40391EAC1092E100ULL, 0x4B8617680AAAB8B6ULL, 0x4F2342FE14D50D18ULL, 
            0xF10F5799A3187BE8ULL, 0x6F979AA39C74602EULL, 0x36A2058B37C90B5BULL, 0x425724B3E4276C8DULL
        },
        {
            0x04274C1941C07353ULL, 0x7D7A5D8106EE0584ULL, 0x1FE92A3ED5A0D706ULL, 0x51760CE584CEB80EULL, 
            0xDA447B208DC0910DULL, 0x8165052EDB2C3909ULL, 0x926880878C57B876ULL, 0xAA00A3FE3CDE1015ULL, 
            0x026A40A875FAF236ULL, 0x7983FF5E4FB53336ULL, 0xAD6F35FA07B3B9F4ULL, 0xCB28F4C9C4034663ULL, 
            0x1682D4F7A5632D09ULL, 0x7765A62A22FA4374ULL, 0xBA19A175510CF47FULL, 0x5FED96AF722107B4ULL, 
            0x3604EE2F0B52CF8FULL, 0x7C840EC1CE3D7656ULL, 0xC9B87E5A3FBBDF56ULL, 0x58EA772717B20DC6ULL, 
            0xA4E39254590DDE5CULL, 0x56A76D00FED78F96ULL, 0x1D34D44AD73152B9ULL, 0xF461962AB73398EEULL, 
            0x457684DABEDFB637ULL, 0x347F3222305D3E25ULL, 0xFEA7FBDFDF3BD3D0ULL, 0xA4AD2ED054FD4FA2ULL, 
            0x4BE0F3B091BD43D8ULL, 0x91D5CAA93E660953ULL, 0x27A9EAF0AF7ECCFEULL, 0xEECEB116EFC0ACECULL
        },
        {
            0x9E1AE2902E7E39CFULL, 0x72A91C1953194458ULL, 0xF4B5E29AB2AF4120ULL, 0x322B419FD37C8A83ULL, 
            0x3397BBA7F822CCF1ULL, 0x7E86E5F0DB75ECBAULL, 0x85D57AA54E9A07BEULL, 0xAFACC9B4F1384E66ULL, 
            0x9FE1553315FAA5EAULL, 0x6773D16173854150ULL, 0x8B7EE7BD4961044DULL, 0xAAF8C9E7B2FB1DF9ULL, 
            0x29E8A0E861244CE5ULL, 0xE6801AB066AAD796ULL, 0xFD7FBBD1990E3926ULL, 0x92EBB0097753F0BDULL, 
            0x805EC9E79474F5DCULL, 0x36F4E0D404675222ULL, 0x25779637867D8FC4ULL, 0xD8B9253932CF64D2ULL, 
            0x28BB3E8962DF55EFULL, 0xA4F483B8BD3445D4ULL, 0x02069BFEF9195591ULL, 0x4477E6C6726882C2ULL, 
            0x73DE13583305E522ULL, 0xC47CBBD45057EEA9ULL, 0x30BB9D7EB465665CULL, 0xE90B8542B0EC14CEULL, 
            0xC7E6595F65CE86DFULL, 0xADBDDC2264445200ULL, 0xDBAEF2A32D90DC9AULL, 0x62A67C293DD37184ULL
        },
        {
            0xBDC3881A9DACB7F2ULL, 0x26BA885153B23852ULL, 0xCF45F548B745088DULL, 0x59A998036027AEDCULL, 
            0x9B7EB81E25E655E6ULL, 0xBA6220AB069C347AULL, 0xFD837F9C4CC068A6ULL, 0xD96878778FD3B4CBULL, 
            0xA652EDD97DFF811EULL, 0x33D8B5D030AA2848ULL, 0xCB687848ABC52541ULL, 0xB38FEBA697887FA3ULL, 
            0x03E8E6CDFFB5BD09ULL, 0xB44DE484BFA647D9ULL, 0x1785CD7A50E8379DULL, 0x63D5F0D11C03867BULL, 
            0x92B6664B5819BD34ULL, 0xE0391FE693FB1D84ULL, 0xF8635C68C297246FULL, 0x3533734707E516ADULL, 
            0x161DC1B66A6BE709ULL, 0xCC9700CA63334E91ULL, 0xAF176172B16E91ABULL, 0x5A54D14E7647DCB7ULL, 
            0x15E6D61D191E6B4BULL, 0xB9016F8A48F5C479ULL, 0x8A4B4A1343D72304ULL, 0x44076DC8E4445D34ULL, 
            0x59EB89C6A2BD7A68ULL, 0x3EBD0B29B24D5072ULL, 0xA4DABB250E9A1AD0ULL, 0x828F00D2EA30A2DDULL
        }
    },
    {
        {
            0x45081E77768EC097ULL, 0x16D09891BED7E43EULL, 0x07B9E9570032B4E3ULL, 0x13FC57B81FF84124ULL, 
            0x2686C65BDA994CF0ULL, 0x88FB3F6BF5A3FFE4ULL, 0x8BDB060452926B78ULL, 0x197B24D5393FB2B7ULL, 
            0x0A15AD327F00143CULL, 0x05F2162D619F39E0ULL, 0xA8581E699714EF39ULL, 0x64AF6788086AE8B7ULL, 
            0xB93F6508562DA0A6ULL, 0x7246D48FD18023FBULL, 0x787263BF7A3284E6ULL, 0xB8FF4A0A453FC211ULL, 
            0x027167782077775EULL, 0x44709454D6C28AF7ULL, 0xC9791A6C340258FAULL, 0x57D01F56C3839ACBULL, 
            0xCA783FB10ED2B335ULL, 0xFE3F6EB695C849ACULL, 0x0833136A497707E5ULL, 0x5EE348A74566F6DEULL, 
            0x61F9838753473C66ULL, 0x29E1041E9F61EBFFULL, 0x450892FB006C68F4ULL, 0x515083B25087A6A8ULL, 
            0xCC5BE8A9244AF603ULL, 0x85B6F7C6912BC4EBULL, 0x652BC5CF12F28008ULL, 0x038C26B699CA85C9ULL
        },
        {
            0x97817912BEFF8356ULL, 0x895626B88240E0E7ULL, 0x42E3F28D7C9524A2ULL, 0xBDA6F7BB29F198DBULL, 
            0x6A6406A658BF19D6ULL, 0x43B2E09679AFA1F2ULL, 0xFA5B28E1BD08A8C1ULL, 0xD5E7788AB393C281ULL, 
            0xD4904D698B231C1DULL, 0xE7FAEA4640C9E271ULL, 0x548F0D2DDE17D713ULL, 0xE0D29598FABB315EULL, 
            0xC270BF9E61055EFFULL, 0x0EA9D43DD0E898CFULL, 0xA39EAAD302380F1FULL, 0x1849A035886F1737ULL, 
            0x5D9704539E531ABBULL, 0x9F1512BF87880CC2ULL, 0xC443C506F24B7F44ULL, 0xA874B9C09B683517ULL, 
            0xCCCD3CB1B13F86FAULL, 0xD0DBDCF04F2F4FEAULL, 0x97B2EB516BB1E10FULL, 0xC09593277DA60AF7ULL, 
            0x301FC3A7CCC39D89ULL, 0xF7CFE55682B47EEFULL, 0x2DC8B588E1571108ULL, 0x236D04C304B81AF0ULL, 
            0x149DDFA37A2529EEULL, 0x9D5CE09995655E32ULL, 0xD27B527840A60657ULL, 0x4E50E3BF97C36F7EULL
        },
        {
            0x9C619651B498FC2FULL, 0x971C833F3BAF0784ULL, 0x6A36EFB439226DD1ULL, 0xE10D349D2F186712ULL, 
            0x784E57E52FD63E05ULL, 0x9C89515B114E12C0ULL, 0x53346F83E11D2039ULL, 0x3AD7BE3B7982E694ULL, 
            0x5952D1E889FE7684ULL, 0xAE157549F7BB70BEULL, 0xB5A57B6043946695ULL, 0xF734A08FD93D6C07ULL, 
            0x911B8F9D593EC964ULL, 0x312BC9A5D0CDE701ULL, 0xC06F93640D2FD316ULL, 0x9F187C12A7473894ULL, 
            0xF303529B61903C30ULL, 0x1DCBDB2464182684ULL, 0xEC1556C8A911D4F5ULL, 0xDB20DD9D3AA7BEDFULL, 
            0xC93024902DA1FC8DULL, 0xDC7CFD3883805837ULL, 0xE2CE39E116F3C604ULL, 0x460E620D5F5FA1D6ULL, 
            0x64B8C50F35C4F732ULL, 0x740F1282E5ABFD5BULL, 0x50314EA4E65CD213ULL, 0xDE00D6476862F1D0ULL, 
            0x30C39DCC5060B1FAULL, 0x0CE35BFFCDCE4C64ULL, 0x9B575F5CAD2F7281ULL, 0x7A75790C150CEEFBULL
        },
        {
            0xA781F53A86843301ULL, 0x46A7797540E9F50AULL, 0x890CAA46E3D53827ULL, 0xFE37CD4E71303AA9ULL, 
            0xFBC99A180374F08EULL, 0x649281A677B0F98BULL, 0x9B1576ABEDAEAFFFULL, 0x385281B1023BB659ULL, 
            0x452A806A50D1D223ULL, 0xA4CA6FD2D24306ECULL, 0xDFCC70C5837CE65FULL, 0xCDBBD58820F1BD55ULL, 
            0x83CCA8E549B7BFF0ULL, 0x9CA615AFC96B6846ULL, 0xEE520EAE72013001ULL, 0x3481A0C82959CF34ULL, 
            0x69CE00674AAAF482ULL, 0x6F3A4C1F5DAFC38DULL, 0x4C93B561C2746605ULL, 0xF0517B9A9986C417ULL, 
            0x75BFDAE30B2F6F96ULL, 0xA676FAFBF6CFFA6EULL, 0xB86C0CE9F412B7A4ULL, 0xE2FA09BF5E8FC180ULL, 
            0xAE5180E8A6ECD54FULL, 0x92804DF6F641F7A9ULL, 0xD911175040320A98ULL, 0x07035AAAF24D178CULL, 
            0x5821A17693F131DBULL, 0x7C92FE7BC385E008ULL, 0x97F744551BDBCAC1ULL, 0x866EA3BD0064B6B7ULL
        },
        {
            0x872EFB65F0086B28ULL, 0xAC3545AAACEDE0B7ULL, 0x1633EFCF82A8321CULL, 0x404C84E373B9812CULL, 
            0xE92107661B1F5956ULL, 0xACF202196CC6EF83ULL, 0xBEA9917E6D8B15C7ULL, 0x51D772F1F1ED4FE4ULL, 
            0xBAD787AF3EB1F36CULL, 0x4F4EC4D2050FBA66ULL, 0x6A98C86F6FC9A001ULL, 0x426072F157A29288ULL, 
            0xDD7C5F711F462667ULL, 0xCEBFE0F7A7B2CD95ULL, 0x24F72E24C11F5F53ULL, 0x3193AAF4FC26D17CULL, 
            0x72CDF271AB603B4EULL, 0xD045CE42CEFDD653ULL, 0x56A193DE4DF0B930ULL, 0x25147608E68436CEULL, 
            0x2B522181E3CA2AECULL, 0x953F99AA0144ACA4ULL, 0x4CCB943A18AD05F0ULL, 0x6327A0AFC0BC8E75ULL, 
            0xEA0F0B427A3B789DULL, 0x4FC646D32D06B99AULL, 0xDC1F18B421100017ULL, 0xA788F018A81E39D5ULL, 
            0x8174959A8281C7B4ULL, 0xA3269D9F887578E7ULL, 0xF4249EBFFADDA78EULL, 0x30C155AC8CFFDF32ULL
        },
        {
            0xE29C416F1630E89CULL, 0x48A34C7C8343D8E1ULL, 0x3264DD2F56DEFBF8ULL, 0xA74216295E98B0A4ULL, 
            0x969AC5DD1D54B34FULL, 0xA42465781F9FAA3AULL, 0x37BF1BF591386144ULL, 0x5D73023C80A8BC0BULL, 
            0xC712290F76B963D1ULL, 0x78F4965A0328FB3BULL, 0x7C1F385B6078B146ULL, 0x1C6998D881AE5075ULL, 
            0x3366AF010D92EC4AULL, 0x7103FCDB7397655DULL, 0x9C24F425AC7F71BAULL, 0x37718E8FC8B59CC4ULL, 
            0x06CAFF7C8CF4DF5DULL, 0x98D471295AE3DD74ULL, 0x0A79AF1AC3A5BDD1ULL, 0xB724B9AD54EDD459ULL, 
            0x3EBF69BA5BA04E5BULL, 0xB1F8F28611AFAFE4ULL, 0xC76BB23415A583ADULL, 0x1307A7C2143387A0ULL, 
            0x49D12E39B2166DD9ULL, 0x8DE65B04B67F38EEULL, 0x01D0F20A91D8B077ULL, 0x230A7F0E542A5F2FULL, 
            0x1A7254B99B5ADFF5ULL, 0x4416FFD7EA5A2D25ULL, 0x0DA04FD2D482D86FULL, 0xAC6A6A07D94E95BEULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseGConstants = {
    0xCFD501B99C7789DFULL,
    0xDC1F33E6CDFD172BULL,
    0x5A13390C400986B1ULL,
    0xCFD501B99C7789DFULL,
    0xDC1F33E6CDFD172BULL,
    0x5A13390C400986B1ULL,
    0xA5678F675B96B854ULL,
    0xBA375553A1793C67ULL,
    0x30,
    0x68,
    0x5F,
    0x0D,
    0x42,
    0xAE,
    0x65,
    0x13
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseHSalts = {
    {
        {
            0x5ED356971B319E1AULL, 0x7A3158EA3E982727ULL, 0x50DECF586D504AFBULL, 0xF6B0F92F511DFC30ULL, 
            0x7E66D103F1FC2172ULL, 0x9F2BDF8A827080B4ULL, 0xB7696012F52EBFBAULL, 0xD1D2D7751FD11CEBULL, 
            0x473F527E4FE99686ULL, 0x99F602EA7F5CA473ULL, 0x8B54ACC19A802722ULL, 0x45D86C5B2E953680ULL, 
            0x2D412979A830A3A5ULL, 0x300676205D57BAEBULL, 0xCD5C9022A9BC9B42ULL, 0x41FDBAAD93BF561EULL, 
            0xDF1ABD65FE767097ULL, 0x3A403FD29A871C2AULL, 0x5CEDF5DADC09C900ULL, 0xFFF8889A18E51F33ULL, 
            0x08BEFD3B816C1C0AULL, 0xAB9447D272D8F093ULL, 0xE023507EC610D57BULL, 0x1FAE7512694CAD1BULL, 
            0x6111C8E16DFC9A31ULL, 0xD111F411585F585FULL, 0x74E9B80A210B6FF9ULL, 0xFEDF6866DBE49AE6ULL, 
            0xDDE97A240350B787ULL, 0xA2138A82581AD1FCULL, 0xBADE16428382CD6BULL, 0x67F08E459EF96F0CULL
        },
        {
            0x97D79A9703DC2250ULL, 0x41CDB37B958DBEF0ULL, 0xD488DF6AD91F62CAULL, 0x2E3889D7ED3D6B32ULL, 
            0xCD1F35FD7A5E80BDULL, 0x9CADAD9FBD433CEBULL, 0x7700AEB77DB72C0FULL, 0x6309D75A30CDFCE2ULL, 
            0x4E4B1EFBACDF9ED7ULL, 0xCD0766559086CBF6ULL, 0xA53716E98B48414BULL, 0x7601816D9C0FD9B0ULL, 
            0x07D08B0DC4DBED5BULL, 0x39F17FE10387158DULL, 0x07C49FB6F1F0136CULL, 0x635414377D25B1C5ULL, 
            0xF57FED03747C0917ULL, 0x26420CEA10C4C315ULL, 0x9E3D176363F25C52ULL, 0x2F29867E1C38F956ULL, 
            0xA90DEA8C824D1A66ULL, 0xF58CD2E0687B9FFFULL, 0xCA46CB7079A0F446ULL, 0x5791D47C8559A80CULL, 
            0x7C22A8A9775E8789ULL, 0x99AF5E357ED6631AULL, 0xC6DDB07860AE9766ULL, 0x562808A08D4C114AULL, 
            0x1D2E6538E5B06E97ULL, 0x0EA9D2BB61D77680ULL, 0x29CED23801D0CDCFULL, 0x8812D261EFC0EDB8ULL
        },
        {
            0x6B2FAA9F5B6D0CEDULL, 0x0C655F4E510954A0ULL, 0x9A1FD88612AF5E08ULL, 0xBB4700CB56908E2EULL, 
            0x5EEAE546A6945DCBULL, 0xC756E1E3D70EE216ULL, 0x2ECF827B11A2C52BULL, 0x682597E630D6AF6BULL, 
            0x532E91CAB130C93EULL, 0xAC24A4DF9E08E718ULL, 0x3C67ED123C493DE9ULL, 0xE51BD1B717453FC4ULL, 
            0x581F7020BF51A98CULL, 0x41719FB8437806F4ULL, 0x35803B293FD8B341ULL, 0x75BE60157ECC720EULL, 
            0x36215E5D4634ADC4ULL, 0x65810FAAA1449431ULL, 0x888A24887D18D180ULL, 0x9DF4A6EF3094536AULL, 
            0x88A0A8ABB9A7B954ULL, 0x871734C1145D6E32ULL, 0x9FD62846F32D6C38ULL, 0x7ECC8C55AB302A1DULL, 
            0xDBDF45D34761E8EAULL, 0x31CB0849FDF14FA9ULL, 0xDB56B383B6FC18E2ULL, 0x2AAEF0459D422D5EULL, 
            0xBA817CD9161F1F12ULL, 0xF8C9B8D4B233A6F5ULL, 0x045F4021E5A8ECB2ULL, 0xC8487114F82D039EULL
        },
        {
            0x95217FDFAEE2F33AULL, 0x65508509A7E17565ULL, 0x57AED6E594E884B7ULL, 0xC2005B198D05AA40ULL, 
            0xC5B1BCE74C82C179ULL, 0xACE50B64F746DA72ULL, 0xF4D286CB790F434EULL, 0x7F0F4FF7DCA651C5ULL, 
            0x6844EF334E8CC8E7ULL, 0x830D89FA46AF483CULL, 0xB91A376BC728F3C6ULL, 0x8CF55EDA0BEE469DULL, 
            0xBE71A1C5D8BACE3EULL, 0xAA6E3593FD2F2927ULL, 0x59D398A130D07097ULL, 0xFC244683BAC5A9FFULL, 
            0xE21616A2AFF9C2E8ULL, 0x9B40F746BFFA74D4ULL, 0x5A8F85A06A481075ULL, 0x0801EF1B1EDAD5B0ULL, 
            0x4564AD488FE55CB8ULL, 0x2493F4B48A4847D6ULL, 0x37BA548746763CAAULL, 0x5F6D04B02D28C44BULL, 
            0xACAB98E5F91C814CULL, 0x0B484B7697DFB0F6ULL, 0x97645214250D59B1ULL, 0x639BEE21F05151C9ULL, 
            0x36CD1C09CD7C2B4EULL, 0x970E7E64CD651983ULL, 0xDF6A756B63432377ULL, 0x2D416D7338A62FF0ULL
        },
        {
            0xF4A490C7EC1654C3ULL, 0xD79EAD31D6B87AB7ULL, 0x31AA1294919E6A8AULL, 0xF081CD2E6411CD6EULL, 
            0x34CBCD59136B1C77ULL, 0xAF2877E3419287DAULL, 0xF448D4E5C2B1D821ULL, 0x863B71C9877AB329ULL, 
            0xAD7825A099B541B9ULL, 0xB5EE2F43AE415AEDULL, 0x35C9BC21F358C656ULL, 0xF9D1512B6DC25E35ULL, 
            0x4733192A6A77FD37ULL, 0x834B8107776C42B7ULL, 0x72140B62D3EE94F5ULL, 0xBF9A11C8E7F5DBA4ULL, 
            0x79A5DD5EC308C640ULL, 0xB50D5A9CE98691ECULL, 0xDAAC8A86663EC349ULL, 0xEAA38A4D7433C265ULL, 
            0x642D65A552641DFEULL, 0xC7CF2CCB7D9F36BCULL, 0x614197D41E2FE954ULL, 0xD2ADFC657BCEE482ULL, 
            0x0879F570C46D00B2ULL, 0x3F364AFBB7B47968ULL, 0xA7648D69032DFE0DULL, 0xC547CC3BC9FF39CCULL, 
            0x468FFB93891CE721ULL, 0x2DDB0A38075FB716ULL, 0x26503E1FD209A1F2ULL, 0xA9E72118BBBB5631ULL
        },
        {
            0x0E63686A7C78F694ULL, 0xC920EBFBAC9F14E7ULL, 0x76A38F0B46D3A1ECULL, 0xC8BAE3073D473694ULL, 
            0xFAEDFC73E10E2A57ULL, 0x1C61D454B73ABB84ULL, 0x3ED591A85D745469ULL, 0x2025138DC4D97EBCULL, 
            0xB2CE7EAFE3FEB12BULL, 0x5B64F4DDAC51E19AULL, 0x7CEB5704F13062DDULL, 0xD1FD7201A45A2FD9ULL, 
            0xE6EBB89FB66D4594ULL, 0xA4E943F4912A50A4ULL, 0xDC86F284FA1F56BDULL, 0x372A262FCF0CD9DCULL, 
            0xAA82D18C1FE34881ULL, 0xF69E58B612911DC6ULL, 0xDABF502B3F2C8723ULL, 0x05B280735D54FD72ULL, 
            0x72C7B5058A189C15ULL, 0x6E4986E012951ACAULL, 0xFE0DA931456AD872ULL, 0xD533BF04EF9821BEULL, 
            0x9E591862DBE84711ULL, 0xD12BBA3E407C6238ULL, 0x7C36A04670582945ULL, 0x860EA66C370CBFD1ULL, 
            0xEDCADBBC75F0BDCDULL, 0x5E52B9396D0C6331ULL, 0xC6A09BEEE864AE76ULL, 0xE9CFF2A87225589AULL
        }
    },
    {
        {
            0xA69E740B5DAF1193ULL, 0x556FA579A7B8248BULL, 0xB32E5BE119C95AF7ULL, 0xC72412CC5AC67F29ULL, 
            0xC218247945EC4D09ULL, 0x12354A364954333DULL, 0x233440C485B4BD33ULL, 0xC22F7DA0976B049AULL, 
            0x78CAE27FC1EA4EE6ULL, 0x81A8217671D7E2EBULL, 0x78CE094F73F246BEULL, 0x427C7ECF9891B37EULL, 
            0x076F464A44923304ULL, 0x1AB224B05047E296ULL, 0xBFEB4D0C6F7CAC66ULL, 0x47293E3CB3E81170ULL, 
            0x22A3722B5D964509ULL, 0xE4AF12F0619EF1DCULL, 0x04A93AB0EB8272FDULL, 0x07965A9D82069ED2ULL, 
            0xF52E618973A70222ULL, 0xD759541BAA0DB9C2ULL, 0x55A7DB95CC368C3FULL, 0x80974276DF99BA7AULL, 
            0x20C7AA79AB1856AAULL, 0xBE1F130337C33B24ULL, 0xADEEF6589F7ECDA2ULL, 0x730E027CA410DBC3ULL, 
            0xC21F286D2E6B68FEULL, 0xBCA611AAAA6CD729ULL, 0x0999CFC901AD9AA5ULL, 0xF10F164E3F295424ULL
        },
        {
            0xE7AEFA13C3541855ULL, 0x8FAAB5D6C52A2F95ULL, 0xA875C3B34BE3F066ULL, 0x1E4352417BA3EC72ULL, 
            0x6EF21C206A84E770ULL, 0x3B8D36623256DBBBULL, 0xF906A297DD723DE3ULL, 0x706AC2B21444585FULL, 
            0x5D3FA07538A29678ULL, 0x1E40D96F193538AFULL, 0xD78895F777DB333DULL, 0xB0127EDD061E826DULL, 
            0x1A71C9C7CD02F3BAULL, 0x5D9D85DFFC556AD1ULL, 0x50BE9942C7EEC455ULL, 0xF9D800D9B9D4DB7AULL, 
            0x94D8E78618787348ULL, 0x52E9F1A8692A198BULL, 0xBAB71EA6415C2F8BULL, 0x68F9AAD2CB88A17DULL, 
            0xC89B4D94BFE19E42ULL, 0xFB0F271911EBE613ULL, 0x44818F7446213EC7ULL, 0xD266F54206978977ULL, 
            0x62D574D92D9A2163ULL, 0x14DC2FB336BA9CB2ULL, 0x067385C20C16C974ULL, 0xFC93187D4A4F2F94ULL, 
            0xE8CA5059D80174ACULL, 0x8101A59B20D1037DULL, 0xC24AD3A304A84DD3ULL, 0xE15B35D2C962E4F5ULL
        },
        {
            0x7961C9C6EBFF737BULL, 0xF1DB7FC9DA246EB9ULL, 0xA2695890441F2F5BULL, 0x0F70EC44562A16FFULL, 
            0x2FED64618CAC5686ULL, 0xD2B86E3DC3CD8228ULL, 0x206077167C0B877AULL, 0x8214D7C078B2485AULL, 
            0x38530087DCB7D22AULL, 0x89E3EB20C2C143C0ULL, 0x02BB1A5612893ED2ULL, 0x647F1ADE1989058EULL, 
            0xF9FBEF472AA23D49ULL, 0xBCF5291AA6AB91D8ULL, 0x8A614611EAC070C0ULL, 0x0FBF7315EE9CA98BULL, 
            0x5B68644060060C59ULL, 0xE6D4A90795906258ULL, 0x836C04668F979C83ULL, 0x9BD1CAE2464B6954ULL, 
            0xAAF745996034D596ULL, 0x90C1FCE70662DE8FULL, 0x7B7EF60B828D8FFFULL, 0xC291806A72C97D7AULL, 
            0xD0929725FA0536B6ULL, 0xED7D74C3DE5D2022ULL, 0x7992E37F966A4F8AULL, 0xE7B97020514823B2ULL, 
            0x614F94D307245732ULL, 0xC194ED7B36658099ULL, 0x322770CDAC7C860AULL, 0x0C30B242DFCAE77BULL
        },
        {
            0x392F4F42CCAD482EULL, 0xAF628F740DCF4E95ULL, 0xA59C0B3C44424EE7ULL, 0x52CAA2A7C9CE09D3ULL, 
            0xC7E6D7AB2C87DBBFULL, 0xAD0C5FBB610C13FCULL, 0x284BD352D0F77C82ULL, 0x42C1110ED289BA10ULL, 
            0xD3DBE0A6E220899BULL, 0xB87D28CF55FD68B5ULL, 0xB3DB104D62406059ULL, 0x2636BA31685B1E62ULL, 
            0x9B3CF6EEBAE25822ULL, 0xFFFE057015F4A3F0ULL, 0xE7B06240EB8A88CCULL, 0xD05E785EC460CD5EULL, 
            0x921794E55D8C2D00ULL, 0xE9EE58913E7539DAULL, 0x17DC8DFD58A7175EULL, 0xEAB0090F7E7CA478ULL, 
            0xAEDB139EE8A9910DULL, 0x81C49B74C37913FBULL, 0x8FE8A5813796FBFDULL, 0x1215AB19FFA1FEEBULL, 
            0xA3AE8D5BBE5008C6ULL, 0x29B30FF5E2039BF8ULL, 0x557D6F9434E77892ULL, 0xECCBD9D82A4E4A6BULL, 
            0x80F01A0E2334A0F1ULL, 0xCC900EA905D7B89EULL, 0xFBDD9925139FAA0CULL, 0x2A380E0DC0091AB9ULL
        },
        {
            0x2BED4F0E718C918BULL, 0x1FAE842096A70784ULL, 0x312748B45F834326ULL, 0xCF3F5F828EC323C8ULL, 
            0x754EC6E77D9172B8ULL, 0x6290EC9A012FD283ULL, 0xEC22EABA02E0D7D6ULL, 0x9FFAF4FCE38E7C8DULL, 
            0xAE5E7F326A385385ULL, 0x1B9269B7A4B17D4BULL, 0x6529DF59A2C86407ULL, 0x08E1CBF841CB4B4FULL, 
            0x477CCCD05100F645ULL, 0x76A546F38C2E1FB8ULL, 0xF8BEFC097BB3474BULL, 0xB8B50502ABFAAFFBULL, 
            0xC732D6A69734DF73ULL, 0x9324702B3AD8C7B7ULL, 0x916B0FD7355924C4ULL, 0x3B6D140A08E82CDAULL, 
            0x8E6995B3A8FF767DULL, 0x1F4A209D8FB2D442ULL, 0x779AB55A21636AAEULL, 0xED71A1F9D84E6980ULL, 
            0xB17FCEDAE278B85CULL, 0x3ED1415F907A9397ULL, 0x54D45D570436E88CULL, 0xA49211CD83B820C8ULL, 
            0xD09148091EA20799ULL, 0x5DB73910442F5B72ULL, 0x01C653B9DCD77779ULL, 0x4F7BB6C0794F37A0ULL
        },
        {
            0xE29ADD50101742F1ULL, 0x9F79A2ABB4BC01CEULL, 0xAC36D4C089186CA0ULL, 0x688E87AA4A5BDF28ULL, 
            0xE95CC29D0AE645CEULL, 0xDC7F150A25CCDDDCULL, 0x32F0B760CC2B8A96ULL, 0x7C5C1C1F1865474BULL, 
            0x8479B2AAD8433854ULL, 0xCACBAB6697FB4374ULL, 0x30CFBFF4EC02C5A5ULL, 0xF73025036D4C2292ULL, 
            0xB68A83EDFABB7314ULL, 0x55ADE99B47F311F9ULL, 0x1FE3869D40EE8FA3ULL, 0xFE28294C6C78618BULL, 
            0xC643EA3EAD7FE49DULL, 0x38B349410220D251ULL, 0x5D8743A962735D8BULL, 0x76D28F8F88CC3247ULL, 
            0xC1D314AE33D35EE0ULL, 0x51C9A43DFE8BD03BULL, 0x579FD4C8B386262DULL, 0xF18114EB065CA3F6ULL, 
            0x14635FD0F11E380AULL, 0xCCB77D2B4D86AF2AULL, 0x02A5CA2CFDA8F5E7ULL, 0xE1C200B8B3B8FD4CULL, 
            0x82B163F0A0F5A56DULL, 0x27D5CEDF7919C8E7ULL, 0x6D269CA13E33AF76ULL, 0xE77807EA1B8198D5ULL
        }
    },
    {
        {
            0x2C0D516E71F465A6ULL, 0xBF7B817959A4149AULL, 0x0969C393C16A71E6ULL, 0x8B0CF954EA59A02EULL, 
            0x68E2773AC19C2C6CULL, 0x56EEA6D3BA44FF44ULL, 0x1AB8155236889F22ULL, 0x0E5E934EAC8542AAULL, 
            0x8D33F38E86F918E0ULL, 0x0D4F94CEFEE94FDDULL, 0x1EBF1B10AFFCC51AULL, 0xB10F31D3BB5EEC69ULL, 
            0x244B73165FC4E0D9ULL, 0x80A0DAD9B1077DFBULL, 0xA6CFA7D6A673BD10ULL, 0x9BE2364709BA66ABULL, 
            0x0441F938398C63DDULL, 0xDD1876C81CD5A823ULL, 0x5DA0D6BF37199605ULL, 0xAFD51A084BB9A6F8ULL, 
            0xBC5E7C31705497F8ULL, 0x1772F8B0E2067874ULL, 0x3B604CFF85A1F03CULL, 0xF4BC381A053D5A86ULL, 
            0xBDC6F83717030F4EULL, 0x1A5B2D62E2EDD4D3ULL, 0xF08FBEDFF4A428BFULL, 0x5730487684E14171ULL, 
            0x54873323653559F3ULL, 0xE87812CDCB0C27C0ULL, 0x11BDFD463C3BB14EULL, 0x0B5D1480AFDAF77CULL
        },
        {
            0x345BFFDF059CADC2ULL, 0x0572CA57A83DD671ULL, 0xC404161B47A12318ULL, 0x2063DAC76DC20964ULL, 
            0xC0533AE8F64B3D67ULL, 0x17264D816A1AB431ULL, 0x06E600592892A4A0ULL, 0x6CACD0E680795F35ULL, 
            0xD83C4740A585ED23ULL, 0x6630996726A1B445ULL, 0xBAEF3DA9679BF8CEULL, 0x5E9540EC5194AE6CULL, 
            0x81736B31304BF604ULL, 0x92BFA43AE2666AF9ULL, 0x26A9614A9F9F2D84ULL, 0x3A3BAA3599723B23ULL, 
            0xB69C10C9300707B6ULL, 0xDBFE46517DA3C89FULL, 0xBB33D3EDB4AA4327ULL, 0x78441EC87AD2D13EULL, 
            0xEB7A0F4E41B63F5CULL, 0xCFDD3BC96F78CF64ULL, 0xB08FF3EFDC126DBCULL, 0x7AC8393950CD9945ULL, 
            0x564047C81BD0B7B6ULL, 0x41DF7747079971B6ULL, 0x3692EB1FE8F69819ULL, 0x90BD8DBC401901A9ULL, 
            0x8259B8B1514465CCULL, 0x509DA2CA4F498257ULL, 0x15B60749F3CE0E35ULL, 0x113619AE0CC133BFULL
        },
        {
            0xFC38DB0717AFE92EULL, 0xDCAED6E64280D111ULL, 0x92691F17E28ABDB0ULL, 0x4A53FC9AEB87C6C1ULL, 
            0x118C8FD0CADFF0E4ULL, 0x69701A85B5EA40BAULL, 0xD111B2F11B4A9183ULL, 0x06E7F01CB2EA8185ULL, 
            0x6B89F628014D9B0FULL, 0x6D9FC37F0263251AULL, 0x6537C447F2E31572ULL, 0x4E585C5B668BB810ULL, 
            0x6D0295F106E9CF64ULL, 0x353EA8E40583CC0FULL, 0x8A6B00536EDF7DD4ULL, 0x02915F40CE6945A5ULL, 
            0xE676E86B79207EB8ULL, 0xB20B9DA55E5E4114ULL, 0x4BFDD7C349EDDBD6ULL, 0xC0B1A34FB91C0210ULL, 
            0x4FE580DE916CB544ULL, 0xBC6A374CC678DC4BULL, 0xCCE55A4AEF51FD1DULL, 0xFEA086A1DB3AADFAULL, 
            0xDD9BA9072298F1E9ULL, 0x9F1605208268BFA6ULL, 0x164F7BA5E8F4CA83ULL, 0xEEE94471C3B964A6ULL, 
            0xE2DBD908F258149FULL, 0x80F6433CF32F7DFEULL, 0x9B4BC6FDDC5CBE76ULL, 0xE42B471BBE26F8CFULL
        },
        {
            0xEE8E4C424607FDE3ULL, 0xB8152DFD73EFC89EULL, 0xCBDB0F99D1C26171ULL, 0xBEAD26456E2EDD98ULL, 
            0xA24044C02AAC65A8ULL, 0xBF66543E5E8B5A3EULL, 0x24236334E13CCEF5ULL, 0xF5E941A9EF26087BULL, 
            0xF5271B6D0851E9ECULL, 0x8418E11E25D20977ULL, 0xE14907C66F570E7DULL, 0xC2D4367A0D466AEAULL, 
            0xC9FCA6FEF8B6D313ULL, 0x0822B3C4C72F0A29ULL, 0x35B004DA9AA1312FULL, 0xBE9C87F1FAC16F3BULL, 
            0x277F42B2613A5ECEULL, 0x4E1C9A68FC3E3262ULL, 0x0F1DE68B73E51326ULL, 0x30F308B9A8913808ULL, 
            0xDBBA025888891EA6ULL, 0x4FE635AF4BBFE76AULL, 0x5469DDA3FA32E290ULL, 0x35046DEF881D9B0DULL, 
            0xCCF9D8B1569BC546ULL, 0x881FEAE802E17C96ULL, 0x770ECF0ABCC5118BULL, 0xE41DFEF7047BC67EULL, 
            0x99F796B234A53D53ULL, 0xB89788D54548DD48ULL, 0x3E803532232E7672ULL, 0xA34B806F758BB935ULL
        },
        {
            0x754FB50E38F35D21ULL, 0x2755C812B8AA18D9ULL, 0xC4279B3F5302FF86ULL, 0x492CCADA7B8EF1C8ULL, 
            0x4A7F2BD3520C88B2ULL, 0x22C8FD62924D9AEEULL, 0x00DBB313BD95B919ULL, 0xDA0951849FF3EECFULL, 
            0xCEEFAB15DDF47492ULL, 0x525A53FD4A5D191EULL, 0x3834DC1C13BCEE9EULL, 0x85DFFE65A3D15914ULL, 
            0x293FA7BEA10D6979ULL, 0x873B4A9E49DE8FCFULL, 0x13B94175CADA6C61ULL, 0xD4A9DA12EAF24E41ULL, 
            0x07137E9B32A470B0ULL, 0xA2C912E1B27FAA50ULL, 0xD79B7B736D4A70D2ULL, 0x3BD858F314AA4AFCULL, 
            0xA677B59CC4D38166ULL, 0xBFE478B497D8A97FULL, 0xA2374A00AC6B1277ULL, 0xE2D979FCE95044F5ULL, 
            0x93FFE52AE46EB66EULL, 0x43750F3E96FC23B9ULL, 0xEC257688C35F5A8FULL, 0x24DAC954CD7D8668ULL, 
            0x66D0E1BE44B07FABULL, 0xBDC36D281E0926DEULL, 0xA949014DDA4C5586ULL, 0x79C0B051EB24B80DULL
        },
        {
            0x45E1FC2D4E00F48EULL, 0x4E3848185854FC1BULL, 0x54360045D41BD4C3ULL, 0xE45469EE0546E9BBULL, 
            0x400BF86389C255E1ULL, 0xCF3FED2C76A03526ULL, 0x181184112CE14DBCULL, 0xC88B3421E1C43270ULL, 
            0x540DA72B83D99CF6ULL, 0x97A65FFBDF23DDB3ULL, 0xDADF24E3BA8014ABULL, 0x6E268C0A6233DD46ULL, 
            0x7FCBC7D6C363BF50ULL, 0xA260F06A656FE6F0ULL, 0x256E3A818E7F7DFAULL, 0x950F725D006FA38CULL, 
            0xBBFE34682A9C6AE7ULL, 0x00D9ECBC6FCDA63CULL, 0xAC0E78DC841AF8F8ULL, 0xD6429C9C334C7BC6ULL, 
            0xDC60146A145EEBB5ULL, 0x172BE0379468B997ULL, 0xA2CF34B1C65F9A71ULL, 0xBFD9B560ED9A0C87ULL, 
            0xE4DA49C167075281ULL, 0xAA5A8F2A481B3040ULL, 0x83C0452D06F0E205ULL, 0x6C7AE0866F09B23DULL, 
            0x04FE9136473479A2ULL, 0xFB097E1F0CC88B52ULL, 0x82532B3616A6F551ULL, 0x95A086A92DD8EA78ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseHConstants = {
    0x04510F59FF6333D4ULL,
    0x047667351ABE64E9ULL,
    0xE1850CDA1959AF2CULL,
    0x04510F59FF6333D4ULL,
    0x047667351ABE64E9ULL,
    0xE1850CDA1959AF2CULL,
    0x71CF1939E8EBD19EULL,
    0x437A6E234ECE680AULL,
    0x8E,
    0x78,
    0x27,
    0x4F,
    0xE6,
    0xB9,
    0x2B,
    0x8F
};

