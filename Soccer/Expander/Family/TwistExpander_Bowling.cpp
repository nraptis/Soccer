#include "TwistExpander_Bowling.hpp"
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

TwistExpander_Bowling::TwistExpander_Bowling()
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

void TwistExpander_Bowling::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x82EE2C8C8469051AULL; std::uint64_t aIngress = 0x8AFA60A4AF91BE56ULL; std::uint64_t aCarry = 0xDDEBEE0CAA9AB8E4ULL;

    std::uint64_t aWandererA = 0xA94D37707B5663E6ULL; std::uint64_t aWandererB = 0xBEE0296778FE6F60ULL; std::uint64_t aWandererC = 0xA4437D2CACC2A7ACULL; std::uint64_t aWandererD = 0xB12726B9581E6AF1ULL;
    std::uint64_t aWandererE = 0xB9B413F0F74C6D3AULL; std::uint64_t aWandererF = 0x88C56A1891D8010AULL; std::uint64_t aWandererG = 0xB18AC70F95224E8CULL; std::uint64_t aWandererH = 0xDFF88AF50EE25466ULL;
    std::uint64_t aWandererI = 0x850441D93C1A468BULL; std::uint64_t aWandererJ = 0x8B1FAEE7C7DFD977ULL; std::uint64_t aWandererK = 0x917C1B2D7A8EEC00ULL;

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
        aPrevious = 10531257594964384728U;
        aCarry = 15737494910507693885U;
        aWandererA = 9961236065692614354U;
        aWandererB = 16969856295296961766U;
        aWandererC = 17475496391357039540U;
        aWandererD = 17454808174498604721U;
        aWandererE = 10530486879627523462U;
        aWandererF = 12254998567733982244U;
        aWandererG = 11361011964443308828U;
        aWandererH = 11043305005799042831U;
        aWandererI = 17939400245192317300U;
        aWandererJ = 14904003524757133807U;
        aWandererK = 11198445370122842257U;
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
    TwistExpander_Bowling_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Bowling::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEA164A94BA60EA4EULL; std::uint64_t aIngress = 0x83F9E35FFF299168ULL; std::uint64_t aCarry = 0x9B1EB89D5C4D4377ULL;

    std::uint64_t aWandererA = 0x8AE00FEF7FA7A94EULL; std::uint64_t aWandererB = 0xC0152608B5697B17ULL; std::uint64_t aWandererC = 0x8A41C4436E87DADCULL; std::uint64_t aWandererD = 0xE8144FCD770A6869ULL;
    std::uint64_t aWandererE = 0xDF6084C4766EC2FCULL; std::uint64_t aWandererF = 0xB3B89DD2A3C88657ULL; std::uint64_t aWandererG = 0xCDF0AE38E592CD2EULL; std::uint64_t aWandererH = 0xE37D8B5FAF039567ULL;
    std::uint64_t aWandererI = 0xFB1DE42FC1B7433DULL; std::uint64_t aWandererJ = 0xE30D86EFCFE8336BULL; std::uint64_t aWandererK = 0xF04B0DE1EE057A24ULL;

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
        aPrevious = 16001828865441666073U;
        aCarry = 9791456047972246667U;
        aWandererA = 16548849323313134233U;
        aWandererB = 14937985718313913242U;
        aWandererC = 17729975278936554175U;
        aWandererD = 12277593542855357749U;
        aWandererE = 9856147705381397059U;
        aWandererF = 16028950971731216290U;
        aWandererG = 14510945572827523135U;
        aWandererH = 14807347915628866450U;
        aWandererI = 11174442653756285199U;
        aWandererJ = 14807187886376320508U;
        aWandererK = 12989758225136571291U;
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
    TwistExpander_Bowling_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Bowling::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD7358C0FB5B87868ULL;
    std::uint64_t aIngress = 0xC9C16A2A700B6069ULL;
    std::uint64_t aCarry = 0xACEFB065D817C836ULL;

    std::uint64_t aWandererA = 0xD8AF25E1CE34F618ULL;
    std::uint64_t aWandererB = 0xC7242ACDD89CD3C2ULL;
    std::uint64_t aWandererC = 0xD202917316B39D40ULL;
    std::uint64_t aWandererD = 0xC3C007FD4443C002ULL;
    std::uint64_t aWandererE = 0xEEF4D89B30A68D9CULL;
    std::uint64_t aWandererF = 0x9300AB96B91947FDULL;
    std::uint64_t aWandererG = 0xC54146CD0C4CE538ULL;
    std::uint64_t aWandererH = 0x859C055F7C906F6DULL;
    std::uint64_t aWandererI = 0xA479BF7B22C0DD3CULL;
    std::uint64_t aWandererJ = 0xE6F3EBAFF1A6CABDULL;
    std::uint64_t aWandererK = 0x800C0700C565D981ULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::Aria256Counter(aSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneC);
        TwistSnow::Sha256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
    TwistExpander_Bowling_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Bowling_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Bowling::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Bowling::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB3B0D1FA88EBAA59ULL; std::uint64_t aIngress = 0x91B2B70F76C6E045ULL; std::uint64_t aCarry = 0xEF8763634C532292ULL;

    std::uint64_t aWandererA = 0xF04468C3F93CB433ULL; std::uint64_t aWandererB = 0xEDF5E0EAAA6FDF3EULL; std::uint64_t aWandererC = 0x8DE921F69C246FBAULL; std::uint64_t aWandererD = 0x9F5BF53E06057029ULL;
    std::uint64_t aWandererE = 0xF9E5B0A8F463E914ULL; std::uint64_t aWandererF = 0xAC3CF42F54967C5CULL; std::uint64_t aWandererG = 0x961AAC34F55AB245ULL; std::uint64_t aWandererH = 0x8DB2B373181185C2ULL;
    std::uint64_t aWandererI = 0xB0D7E6616CD33707ULL; std::uint64_t aWandererJ = 0x88754966C6D800BFULL; std::uint64_t aWandererK = 0x8ACDE4940423A1D9ULL;

    // [seed]
    {
        aPrevious = 11798324394629500299U;
        aCarry = 17220676677892831000U;
        aWandererA = 10694932655135923046U;
        aWandererB = 12579520701983371077U;
        aWandererC = 16893926320072413944U;
        aWandererD = 11531931229033678672U;
        aWandererE = 11736247993901122170U;
        aWandererF = 11007992551837442780U;
        aWandererG = 13657063926484354870U;
        aWandererH = 9420648888048261218U;
        aWandererI = 17306971714793680417U;
        aWandererJ = 10984975033235248486U;
        aWandererK = 11482520684082955151U;
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
    TwistExpander_Bowling_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Bowling_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Bowling_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Bowling::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 1, 2, 2 with offsets 7137U, 4717U, 6533U, 4861U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4717U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6533U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4861U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 3, 0, 3 with offsets 5654U, 730U, 3260U, 5211U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5654U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 730U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3260U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5211U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 2, 3, 0 with offsets 3737U, 4353U, 6808U, 7214U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3737U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4353U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6808U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7214U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 0, 1, 1 with offsets 660U, 5479U, 6429U, 3802U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 660U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5479U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3802U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 3, 1, 0, 2 with offsets 905U, 1101U, 577U, 1023U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 905U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1101U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 577U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1023U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 3, 1, 0, 2 with offsets 1266U, 1983U, 763U, 73U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1266U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 763U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 73U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 2, 3, 0, 1 with offsets 520U, 1694U, 856U, 369U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1694U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 856U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 369U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 2, 3, 0, 1 with offsets 563U, 260U, 949U, 995U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 563U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 260U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 995U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1103U, 966U, 843U, 936U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1103U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 966U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 843U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 936U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Bowling::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 991U, 7771U, 5453U, 1995U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 991U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7771U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5453U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1995U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 0 with offsets 3195U, 7146U, 3997U, 2420U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3195U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7146U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3997U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2420U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 1 with offsets 5196U, 2719U, 7260U, 7430U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5196U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2719U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7260U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7430U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 3 with offsets 8025U, 3990U, 4035U, 4140U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8025U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3990U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4035U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4140U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 7829U, 468U, 4537U, 5645U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7829U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 468U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 4537U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 5645U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1091U, 1375U, 353U, 1185U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1091U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 353U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1185U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 331U, 1675U, 751U, 1676U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 331U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1675U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 751U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1676U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1313U, 73U, 877U, 1108U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1313U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 73U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 877U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1108U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1186U, 16U, 957U, 1212U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1186U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 16U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 957U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1212U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 2, 0, 3, 1 [0..<W_KEY]
        // offsets: 468U, 855U, 1921U, 1997U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 468U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 855U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1921U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1997U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseASalts = {
    {
        {
            0x96CFE1DF929D6971ULL, 0xAD7B5955BAD6380DULL, 0x0AB39D42AD263614ULL, 0x3E3B7034EBB55D0DULL, 
            0xDBA5774E1F7A7712ULL, 0xB18D8936B7AEAA71ULL, 0xF6A5278887F92E3DULL, 0x338EBD4268029DA0ULL, 
            0xCC450BEA58F408ADULL, 0xDF7D1B0AF79D47FEULL, 0x1F4BC89154A7813EULL, 0x81568566C5D32085ULL, 
            0x080D67FA2739BE26ULL, 0x86BA252BDD25819BULL, 0x85E9EEBF078A78CDULL, 0x53DFAFA685408089ULL, 
            0xBC8BC833FD28DC63ULL, 0x391C71113E4FDFBBULL, 0xD8F9861142C8B57EULL, 0x2EAF58E469230C1FULL, 
            0x5AA6C8B3F9BF8401ULL, 0xBB314D7C3821C495ULL, 0x6C61C39B3C65C822ULL, 0x9C3D2AAD2323316BULL, 
            0xA1BD33EBC9582685ULL, 0x93A4D079545BD7D4ULL, 0xDAB471950584737EULL, 0xC3D8FDDDC3A978D8ULL, 
            0x1C41A9961FFF1F29ULL, 0x1C6369250A952FF1ULL, 0x8C983707009A69ACULL, 0x7F1A6B79C734A8DBULL
        },
        {
            0xE4715B3B62BEDB2DULL, 0x5E6F7EBD52B98314ULL, 0x19437643412C639AULL, 0xAFA4F71655CEB4AFULL, 
            0xA735ADD81587682BULL, 0x28D17AA33D7AA5ACULL, 0x0EB11E7DD5787F7CULL, 0xC6A9AEA3C7B88CE0ULL, 
            0x1075821E37933BB3ULL, 0xE5E650B1FDB171D1ULL, 0x0EAB7B9430CC776CULL, 0xE5FDA5E17413B8A8ULL, 
            0x0DC3E6DFF7B192F4ULL, 0xBD17D68F83EF3EFEULL, 0x8D0D05954C958EB8ULL, 0x9B55C0CDF99E609CULL, 
            0xE7BDDFAA27BD4B39ULL, 0x8A177772A694396FULL, 0xD7BBDB6B19B1A3E0ULL, 0xF150C3F7CBCDB1AFULL, 
            0x88A901B3E878666EULL, 0xE6650E2D8BE3B8A0ULL, 0x14177ECB5AFC0238ULL, 0xAFE3E0F8301C006BULL, 
            0xFD815F4DC50CD5FDULL, 0x98169BA4BE3A314CULL, 0x294E262E5146B304ULL, 0x9C1E68D7D0FE0D0DULL, 
            0xDC86E6AFB92C2854ULL, 0xE69AB619D39D5DC0ULL, 0x4DF92E74436109BDULL, 0x9760238D693AC978ULL
        },
        {
            0x5ACC3A83E6811D05ULL, 0xE3616D33DC8D1D8AULL, 0xB82BE617A6F0AF25ULL, 0xB8C95DC8F4D819EAULL, 
            0x3D4ADFE3383D7F9EULL, 0x4951A702F7124C2CULL, 0xFFC79F6D637267C4ULL, 0x0A485C27DC6B6DC5ULL, 
            0x5DE467E04697501FULL, 0x9AD8F21428FA93BFULL, 0x6D248E289A4E15C8ULL, 0x60633D9892908F9EULL, 
            0xB692975439BE809AULL, 0xD26E56AC428C8247ULL, 0x36A76C5A83A4B24CULL, 0x53E31936B60AFD5EULL, 
            0x32F559856A667DBDULL, 0xAA3A8AD4DBA92201ULL, 0x805348AC7B2DEA04ULL, 0x76C963081D042789ULL, 
            0x6882133BE2AC4506ULL, 0x4A5B0292836CDB84ULL, 0x365EE8A8CD903CE7ULL, 0x95759897DB5AEA81ULL, 
            0x1F0682E7E214E01FULL, 0x0A89FA75E7C61046ULL, 0xDFE62557DB506AB2ULL, 0xBD6FB12F65D950AFULL, 
            0x3E7C4D245309B06BULL, 0xB06A9B49876089AAULL, 0x06CFEAF8A52A1BF7ULL, 0xDF4E06DB657204D4ULL
        },
        {
            0x310743CF4E2603A7ULL, 0x8B9665299F7DCFFFULL, 0xD288C6184CA4FC96ULL, 0x171FE4CBC2578508ULL, 
            0x325D5B4FF347CEE9ULL, 0xDBC8C7CB764360CDULL, 0x386BABF528B64295ULL, 0xF4D0902C6EFBB6EDULL, 
            0xAB810B8DD67DE992ULL, 0x19C4675D6D12899BULL, 0x618A3F283B4AF847ULL, 0xDB329AB1883B2419ULL, 
            0x2D4836F1D0C85B85ULL, 0xDAF7FECBF01D9564ULL, 0x3B32C25BCEC50373ULL, 0xBDC6DAE09EEF3A33ULL, 
            0x56C0B1802F7DF3BAULL, 0x4CDCF631A1B20909ULL, 0xA45D9F61904EAE3AULL, 0xE49688E2501E5E5AULL, 
            0x71DBC355C6153559ULL, 0xFFE24CD787A52927ULL, 0xF7ABB0F3982E7389ULL, 0x6BC8189E34A01465ULL, 
            0x142D7747216E40E2ULL, 0xBFAA5876E22418B7ULL, 0x32F84792D4C1C1DAULL, 0x18554636E138B8E0ULL, 
            0xD9A496A1B52827A8ULL, 0x318B694EC408522FULL, 0xBD8E256DBE540789ULL, 0x2E87636AE8EE5EFBULL
        },
        {
            0xD44E4DA00FAC0294ULL, 0x7D3B3A9998E471B9ULL, 0x12DFE6343DBBB706ULL, 0x99051AE1E041B0A6ULL, 
            0x2CD4B32A57C385BAULL, 0x237FD0E15AE1BCCEULL, 0x56B3FF2549E1F7C2ULL, 0x12E703998099301EULL, 
            0x7908DBD040880DA5ULL, 0x7ABFCFB4C82ADA6EULL, 0x6DF7F30FC7AF0488ULL, 0x42F91816A5DB94BFULL, 
            0xCA6B69A61E284021ULL, 0x697D7BA0ADDAC839ULL, 0x6717540998CEB298ULL, 0xCC202CFEAC2A0FC2ULL, 
            0xFF573E19A546379EULL, 0x93C2E3AB230C2CF2ULL, 0xBD860C36F70DBE56ULL, 0xE5EEAF573B91DD98ULL, 
            0xE302C0EC5D365A92ULL, 0x14F76BC66DF1B10BULL, 0x1E2D3B70DAE27A8DULL, 0x08857590CDBBDA76ULL, 
            0x1BF73A43CBE7117CULL, 0x8E2271FF0A7BF0C9ULL, 0x414BB00E235A9BADULL, 0x87E6296771B93567ULL, 
            0x4DC305A78E968DAEULL, 0x1F112DA8AA6C19BAULL, 0xE177666C1DA5DFEFULL, 0x2C3B18757968C955ULL
        },
        {
            0x75EEB7FF6EDFE8D4ULL, 0x9936CC6EBB88589CULL, 0x27814EE5AF17827EULL, 0x0DE33BB5540A9EE4ULL, 
            0x51E8BB86F07CCFDAULL, 0x585C8F4D937C708EULL, 0xE23778B5C2E7B0EDULL, 0x253880514790CA7AULL, 
            0x964B63D38741C656ULL, 0x2EF8649DB8E0C2B7ULL, 0xE4FA84DB8843CF81ULL, 0x9AAD0CF8FF5EF747ULL, 
            0x04466E81DAF3353AULL, 0xDA0BBC912083FC72ULL, 0x37976571E084DC48ULL, 0xD978EDE623CAB4C0ULL, 
            0x5178C31B96B56B21ULL, 0x68857D75E6CE3BB1ULL, 0x071ACBF6CC937250ULL, 0x9E0814EBDB7B0BE1ULL, 
            0x31A46F2781744ECEULL, 0x563757DE84FAC913ULL, 0x78D5C0FFC0215A23ULL, 0xE149E7FBFCFBC9E6ULL, 
            0xD943AF7240AED19BULL, 0xC78A190AB6112B40ULL, 0x2CF61AE3B94D7464ULL, 0xCDD4401D15068AC6ULL, 
            0xD6BED9F618DDC064ULL, 0x040765257DC9AD4CULL, 0x21716BAC68BA84D3ULL, 0xCBA4D22FA3954817ULL
        }
    },
    {
        {
            0xCD009A5E8861064AULL, 0x7292982DF67F3820ULL, 0x35C37767FCC6B911ULL, 0x27CF7C3CA77F689BULL, 
            0x157381DF7397F194ULL, 0x5A547FEF5507D6CDULL, 0x3A60CD03D35E2CA6ULL, 0xED7943F9505483F7ULL, 
            0x0D62C2BC6B50CE25ULL, 0x857F355D9FBD945AULL, 0xF345555096CF25FEULL, 0xA7C24D34A3EB2156ULL, 
            0x68640B62ED4E73F7ULL, 0x045AB340D6844B88ULL, 0x3203BBA1F2FFB24FULL, 0xA3BEDF670355DEC5ULL, 
            0x7E982DCBF13BCEC3ULL, 0x6954CF5D934C2C77ULL, 0xDECBEE54256A9037ULL, 0x42CB5B4E92ACD87FULL, 
            0x6734628CD34A7F38ULL, 0x6B4013CF1E49BB02ULL, 0x44FC9F44837229FBULL, 0x32C3BB2A57B1799CULL, 
            0xE752F5767D2ED0A2ULL, 0x1D44405D96A9DAA0ULL, 0xABA501DFE0B070C0ULL, 0xA8AC50FBB2C24A0BULL, 
            0x1808C061E588C92EULL, 0xF773136584A2C75AULL, 0x74EB696B6A672AADULL, 0x95F0C410443A39CAULL
        },
        {
            0x05E0036D09FE8C8CULL, 0xF19C8AAC22F7516EULL, 0x12BC3825F23CAB7CULL, 0xE03D85CB1C38BEFCULL, 
            0x982FA4605EBBABAFULL, 0xCD6CB837088A2F5EULL, 0xA39F50087F4B09E2ULL, 0x0C198F9BE3816173ULL, 
            0x31A69D6A408804D5ULL, 0xD108D7090B09151FULL, 0x3CFF700DC0936F8EULL, 0x123BBAFF7AB3640DULL, 
            0xA6B4C241F9357283ULL, 0x3323E8E42EFBF7FCULL, 0x1DA1576F169E7E72ULL, 0x8B4C55523F0ABFC4ULL, 
            0xB6A8F48DAAC4918BULL, 0x6F21A9438C24D6DDULL, 0xE56B592850A39E29ULL, 0xCBA1045C8151890AULL, 
            0xCFB8A63B18527861ULL, 0x5B20764C7C73D3E1ULL, 0xC9B894DD75F358FFULL, 0xEFAD0E74BED1E95CULL, 
            0x901CD4239FBE5C2AULL, 0xB4453B4577A0CCF0ULL, 0x2F3C9B8451C65C30ULL, 0x5AA6DEDD52E161EBULL, 
            0x4E6519258EA76D5DULL, 0xF37E0EC9B37187CAULL, 0x8FD1022A815CF72DULL, 0x468E33A3FA8ECD1DULL
        },
        {
            0xAD89A1D42F3B5FEBULL, 0x1907C19E5FDCD2A0ULL, 0x9078E610808EC2A2ULL, 0x429A586083B3B0A7ULL, 
            0x3C54940539A07CEAULL, 0x56E7F4B0731BAEADULL, 0x536FA73AD6474D09ULL, 0x07A8A88ED95FF921ULL, 
            0x9D2E570C153ECBABULL, 0xBDE5693B67CB49C1ULL, 0x208863C4EFED9A61ULL, 0xD50A59B83322D15FULL, 
            0x5226AF8798012C35ULL, 0xC590BB6533777621ULL, 0x452E458131609025ULL, 0xEBEE7E49F1F81984ULL, 
            0x37DBB720DF03D2BFULL, 0xD3D966C30124347CULL, 0x6D830080332AF621ULL, 0x771FC1C3E342656FULL, 
            0xE8DD1B6FE1FE511EULL, 0x2AAA5C19B1E4945FULL, 0xF8166DA622492435ULL, 0xD7230D57F4A666EFULL, 
            0x8B2C7F8DCFAC90C5ULL, 0x8688772178AC1E40ULL, 0xC9BC8E63F1417924ULL, 0x5C137709C80E2CC4ULL, 
            0x251006D48DF28A2EULL, 0xD9910674B7892508ULL, 0x8B3FF4A258974196ULL, 0xDA90C6BB1E19D50CULL
        },
        {
            0xC0B0A1B1C7BBC08DULL, 0xDBE94ABC90552CC1ULL, 0x91182FB95468C1B6ULL, 0xDCC909FD9426AC4EULL, 
            0xA963ED25B6AA15CEULL, 0x44571481CFF9B222ULL, 0x4E4A3639794DC831ULL, 0xBE19CC87AEADB52AULL, 
            0xB7D09AB2BB1859DBULL, 0x4F2CF02BA281565BULL, 0x07055D686D7980B0ULL, 0xEB4A6F8E96DE290CULL, 
            0xC19524734A6E3A09ULL, 0x61DB34951355583EULL, 0x919531166EC976F7ULL, 0x8128897F5C858AEDULL, 
            0xB773DA277A6CBB5EULL, 0x51D5F7FA8EFB1927ULL, 0xF53DC2486D6A0E2CULL, 0xB6E77DC398DB8676ULL, 
            0x8AF892525F2DFB20ULL, 0xAB427681EBF91FAEULL, 0x6F4558790EB37DB8ULL, 0xF035D3E4A04B46BEULL, 
            0x1019898A55E6C548ULL, 0x91A82BC5E22C3294ULL, 0x7FE5C95527A4C94DULL, 0x6DBC338421A1854EULL, 
            0x32CE8DFD612AB287ULL, 0x0F2CA357A49B58E6ULL, 0x2ACA98F69800EA9BULL, 0x0109126E07F2047CULL
        },
        {
            0xDDE84309D08D23C4ULL, 0x696F25E8657EF23AULL, 0x4C0B4945ECB6B87AULL, 0xE71D46363479E137ULL, 
            0xB0A07839668F40A5ULL, 0x097D029403D5DF50ULL, 0xE03F0B9D4D9A0AC2ULL, 0x043C79867CFD1E48ULL, 
            0x031E3402DC2C0C10ULL, 0xEAA19D8F3F5B0065ULL, 0x6B599D6EB6BD7A44ULL, 0x0589E8A2A5DCBDD1ULL, 
            0x7941656ABF27EF0DULL, 0xCCD1C8F81F83B7FDULL, 0xE55A20A47B1CC9D9ULL, 0xE957F44A761D0782ULL, 
            0x41457E516A76D7BFULL, 0xC6977FDC0CD25913ULL, 0xCDE367F734F73870ULL, 0x010DCEA7D220F8F0ULL, 
            0x76637252EDB3DA03ULL, 0xEBCD23EA5C52A174ULL, 0xBEAB9CDCA4DED407ULL, 0x8CC4186250EA775AULL, 
            0x1AAC3E1857E9D558ULL, 0x09D55A36C204619BULL, 0x4EB5E28B04C260C7ULL, 0x2AAE62F71E083C8DULL, 
            0x1BC04CBC8517DDDEULL, 0xFF6881BBA28DE023ULL, 0xCE819EE027637DBEULL, 0xD10E1BE184759932ULL
        },
        {
            0x2DB0CC27B84069EDULL, 0xE4EC7CFCAD01797CULL, 0x17AE8B4604490D4EULL, 0x095137F02F719941ULL, 
            0x1E47D00FD98B1C7DULL, 0x8AB06C0A4DB1C9C0ULL, 0x556AA7346A1F4458ULL, 0xE45829FB80586A86ULL, 
            0x395909010BADC58EULL, 0x781953E02C055CD4ULL, 0xCFB114D40F80CC82ULL, 0x2BCD89054C346EC1ULL, 
            0x26B434F1A4A6AA9AULL, 0x82D19ABF08E18FEEULL, 0xBA4CFD1670A66BFAULL, 0x9A37B453C225D37FULL, 
            0x0DFFECCC151B3E40ULL, 0x891A13DE40B300F2ULL, 0xC71B6A9E373848B9ULL, 0x4BF93AA10D0858EBULL, 
            0xE14983A42A45E52BULL, 0x92BD57ABFAA99FC1ULL, 0x5523091547494BBBULL, 0x3E3F4D3FF134D034ULL, 
            0xE69964474DFBB519ULL, 0x1D66CDFFFFC07C80ULL, 0x447541E61B6F4213ULL, 0x7D98019387B54C6FULL, 
            0xBDCEBD55DF5D34A7ULL, 0x35D333B630257ACBULL, 0x5CCFE2EF28BD9A33ULL, 0xB3E2F72F08EAD399ULL
        }
    },
    {
        {
            0x7418E95E15F47B1EULL, 0x43186F895988B90EULL, 0x8AF5BC52E9350629ULL, 0x89812CE574F096D0ULL, 
            0xF3BC36A00BD82AF7ULL, 0xD25CFCF7A3313A25ULL, 0x33DC9400AA845886ULL, 0x588763E3FA2BAD5FULL, 
            0x6C2F8D76B1EDDD78ULL, 0x8FFF882F323392E3ULL, 0x5EF3EB594DF7F943ULL, 0x0A8FC5F862B0AB58ULL, 
            0x9F59C7E6D48AC040ULL, 0x87742DA86FD00B55ULL, 0x5B2D8170C74F6388ULL, 0xDAAAD07C49E1DFA8ULL, 
            0xCC03721C8C69A8E5ULL, 0xA613D0B039DD78CEULL, 0xA7BAA9F1F3702710ULL, 0x149941038E956854ULL, 
            0xAC40061BDE4AA902ULL, 0xB8AFE5D0F120B48BULL, 0x44CB5AFF98BA471BULL, 0xCDD58ADF8665BE66ULL, 
            0x774F2DC4C4548759ULL, 0xE990FD66D1673D46ULL, 0x3C2595E7761549F2ULL, 0xC3997C340899B191ULL, 
            0x45B07C2E882EA960ULL, 0x60C9A7CB51945D71ULL, 0xDA8CF6428AC1A2B5ULL, 0x414A0338CE78DAE7ULL
        },
        {
            0x6C902725900857F0ULL, 0xD4DAA711BD061FA6ULL, 0x43CAB58AE94913BCULL, 0xA2A65E1C45DB4420ULL, 
            0x7284C949F50B060AULL, 0x057D40EA2CEDC173ULL, 0x684E28E22065E76DULL, 0xAAF7D2C57D9D3ED8ULL, 
            0xC1E543D398D9F6E1ULL, 0xF6380CA2F443AE36ULL, 0x0011424C2852B68BULL, 0x7314C9F52AF5F857ULL, 
            0xCBB570ED8965C0C2ULL, 0x5F988421767F5F64ULL, 0x83A2DDFAD58A3091ULL, 0x6C68A2F2653F2BF2ULL, 
            0xB717379BE8CDF3B4ULL, 0xBDFCB6C85C3E3F71ULL, 0xC34D721801F99AADULL, 0xE9666DA5B7784B44ULL, 
            0x04F3FE09D1661D9BULL, 0x4BFBDF43B23BB26CULL, 0x88F647B4DCD6240BULL, 0xD579F3743E5EB770ULL, 
            0x70455FC9E785A435ULL, 0xCE50B605ABE400C9ULL, 0x7162A000B3964FEFULL, 0x677AFC354E3B1CE5ULL, 
            0xA1E9D9D78FD3C369ULL, 0xFFCF387ED62749FEULL, 0x5C097042E97353E3ULL, 0xAA35E2C51B62C163ULL
        },
        {
            0xB257C504EC771C54ULL, 0xB25E5CD7DD4DFF7EULL, 0x79306B7B43815F84ULL, 0x7EF9A2E691B2CC36ULL, 
            0x3D50929AB6503263ULL, 0xEE721E4D0B03D69BULL, 0xCC3CB0A327E11F3FULL, 0xA533250AF2D93474ULL, 
            0x41EA8A2F8ED6D2AFULL, 0x91C1BE3530CDEE48ULL, 0x95B30651C584F54AULL, 0xA36027FE8E8A0360ULL, 
            0x0D5F54BDA1C148C8ULL, 0xA397BC830E5C93BEULL, 0x7BE53CC1580ADFD9ULL, 0x1C96423635E66320ULL, 
            0x1CA820330C07F684ULL, 0x7C0A801526497681ULL, 0x0FFACB9F480D79ECULL, 0xF3C90C796501533FULL, 
            0xF8495A5CD875B10CULL, 0x0DAF05BC01FC7E2AULL, 0x537323F960FA2914ULL, 0x7886FDE520771CABULL, 
            0x8E20F26FF9A21C98ULL, 0x1717EECE7DF121DDULL, 0x43ADB3D23F1FE67CULL, 0xE9EFFFCE68EC9D33ULL, 
            0xF01446A1870FCD0AULL, 0x75D7A28D4D74C3B1ULL, 0xC20391377302ED5FULL, 0x42D6B7DB0649A525ULL
        },
        {
            0x8A945DC5ACC14FFFULL, 0xAF53C75340B97743ULL, 0xBF71167312F4A891ULL, 0xDBDBB2279E8FCB26ULL, 
            0x7D96E56F2C1CB4DBULL, 0x510EBAA1E96ED705ULL, 0xAE1628E23BA5082BULL, 0xFFAABB6CD01564D6ULL, 
            0xF866632DEB9ED2B0ULL, 0x19871ABFEDC1FDE9ULL, 0xFA6C91D4498247A5ULL, 0xD55592C47A54D37BULL, 
            0x9B4A3CD0E97A2336ULL, 0x4146C15B57E44F1CULL, 0xC03B0BC6630D4F83ULL, 0x4255D22F081674F9ULL, 
            0xE3EA39A89FD61B6AULL, 0x80BEBD8251CFE14DULL, 0xF9EE94E81B0BFDDCULL, 0xF0B073333216319DULL, 
            0xDB2250B8F6E97B54ULL, 0xC74EB9B911D3BF63ULL, 0x779249050377C1DBULL, 0x35893CD0DA0CD1C2ULL, 
            0x8EFB2A9A3D68CF70ULL, 0x3D91985672C00DCEULL, 0x10532B50D803EC8CULL, 0x90D7AFABA41470FEULL, 
            0xD3A7E4BACAEF990FULL, 0x1A3BE9155B950D2CULL, 0xA8970D7DFCAC6308ULL, 0xBE81D71D669EDCDDULL
        },
        {
            0x77870E12C3A9C9F9ULL, 0x026E3F7A42709DE1ULL, 0x2861BD9706516374ULL, 0xD76F1DBC5E27A0F8ULL, 
            0xBD6C45C13DB36A0FULL, 0x07F0ACBB7AB965B1ULL, 0x7FE032E1108623B8ULL, 0x8149712AAFACA7BCULL, 
            0x55A4617474831BE3ULL, 0xD8BA8BE486488728ULL, 0xE3AEC8E73E76BAB5ULL, 0xF03CC661DF236BA1ULL, 
            0x0714E81BF3BD16CCULL, 0x7BF25AD00586DA0DULL, 0x86DFDDE2606E0B62ULL, 0x2FF1FDBB750EC7EAULL, 
            0x15D8BEEB7FD495C7ULL, 0x3C2A582B10583B2BULL, 0x480DADA449EDD984ULL, 0x9D20880BE7204D8DULL, 
            0x89A127B3FDC123C8ULL, 0x8CE83292B9BD1458ULL, 0x1998DC7FE51F030EULL, 0x81C012FFAC578C2FULL, 
            0xAC519F5550DA0793ULL, 0xD34136A3399F621FULL, 0x8A0A1BFADDC45AAFULL, 0xBE97D162794CB323ULL, 
            0x6BD827E398618AACULL, 0x42885770BA9202E8ULL, 0xD6BCC71287D3F1B6ULL, 0xEC5653EBF666EA9DULL
        },
        {
            0xFC094A79B89D810BULL, 0xB9787AD4134DE287ULL, 0x88C98865094C1A64ULL, 0x3E88EE6ADC22ED2CULL, 
            0x473CF5560A7DE54DULL, 0x9E5ABB9705D1B5ECULL, 0x1200EEC9395B5130ULL, 0xBE957398E7DC7671ULL, 
            0xF2ED0FEE2335131CULL, 0x6B5BDEF244D54D44ULL, 0xD266A8B0A0410121ULL, 0x7DE92F14E2FCD9FCULL, 
            0x3721330E2E59431FULL, 0x67DFD65DF599D15FULL, 0x4CF0D9CA844529BBULL, 0xDF0385D4F6989F58ULL, 
            0x22ACDBD3C2FA3FC6ULL, 0x5A8EA9ACDAD7336CULL, 0x879080C0328D252EULL, 0x34F3F9D5D752D7D0ULL, 
            0x92B9AF8363B34FEEULL, 0x86D7555F38FDBBE4ULL, 0xAE5FB3CE1CA39701ULL, 0x1EAE4226BDEA489FULL, 
            0xF94076B84B5052AFULL, 0x7351BB820D2DCAC8ULL, 0x56FED678A403E9A3ULL, 0x6D5B4CD8D71B9113ULL, 
            0xA4F5C4D71CD16035ULL, 0x2F19BC8DE10EE8C3ULL, 0xF22ECFD45316BA51ULL, 0x16534C5E5B125D2FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseAConstants = {
    0xDB4FBD76D6852599ULL,
    0x38B18E14DDA37726ULL,
    0xEA606B33F1EBA55BULL,
    0xDB4FBD76D6852599ULL,
    0x38B18E14DDA37726ULL,
    0xEA606B33F1EBA55BULL,
    0xA973FC9491FFB859ULL,
    0x5362610C4D32FFE0ULL,
    0xFC,
    0xE5,
    0xF2,
    0xA9,
    0xF1,
    0x8B,
    0xFE,
    0x61
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseBSalts = {
    {
        {
            0xEA717F1896BD2DA8ULL, 0x3F8EC67CA5F09F82ULL, 0x0A3AE47E1B24723DULL, 0x726FBD7121EF9C29ULL, 
            0x22F50EF8F6FDEF12ULL, 0x1684DBCD22AC7FDBULL, 0x0724BFCDD46019FAULL, 0x9DF3F899495F4375ULL, 
            0x925FCB8A37454E46ULL, 0xF31CF1A88200E952ULL, 0x305CB57E611CC9D8ULL, 0xEEF42933C380919BULL, 
            0x769E896C8D129805ULL, 0x8C75369A7E4F293EULL, 0x7CDCD04A6481118BULL, 0x7FB3396136659BFFULL, 
            0x2BB9D95E113CE283ULL, 0x3B73269CC3861C10ULL, 0xA9642E9F86E2B012ULL, 0x366D4592C6F9B98BULL, 
            0x5EC1C462C64E4C2DULL, 0x2262E636DC627AE9ULL, 0x0ACF67BD0F491D31ULL, 0x4AA4E2B8488956D8ULL, 
            0xCE3DEC3136D2C803ULL, 0x47FEA375571D14C7ULL, 0xFC931039B453E3FFULL, 0x5A341F92AB980112ULL, 
            0xE9C9A571F4675056ULL, 0xD3F8AA97F95E1BDFULL, 0xD49D04788F0F6481ULL, 0xFFD245F966F6A87CULL
        },
        {
            0x8C459BD1265D25C2ULL, 0x38E50BCE8A515193ULL, 0x34664664B4F7724EULL, 0x3E789C0B4ACAB4BCULL, 
            0x145DF232DA288789ULL, 0x69EA19298F779EF0ULL, 0xFD36B18B2CFAD280ULL, 0x24B5350063671DC2ULL, 
            0x9EBD69F69FBAE334ULL, 0x7420B315D650F804ULL, 0x920B853B8BF1E727ULL, 0x0483D3403FE48374ULL, 
            0xF456A5AC47CB7DA6ULL, 0xD81E9047772B178FULL, 0xA03BF046D5DD9859ULL, 0x0A70BE3A0FB7A959ULL, 
            0x03BC0503EA9F0AC8ULL, 0x4465EC321D29E7A1ULL, 0x15F0EF7575035695ULL, 0x18DC42D5D9F8B4E8ULL, 
            0x1036934080CA1899ULL, 0x4CE04091167B8DACULL, 0x95764FA6607A0132ULL, 0x534408AFF68C5C7BULL, 
            0xB5B38ACD21809E58ULL, 0x8DF2E69647D69CFAULL, 0xA922B36D0BA4402FULL, 0x4E781BB68A20A8AFULL, 
            0xAB5136DD30BE64B4ULL, 0x12B3097632A67933ULL, 0x31847C3CF02513B7ULL, 0xE3B3FA108DBA836AULL
        },
        {
            0xFE26E12D9E7A513EULL, 0x68BE1E38268CEDCCULL, 0x0D030676489F333CULL, 0x2F5B59E1718D76BEULL, 
            0x058F41D68B882E5AULL, 0x06FFA304FA35330AULL, 0x4A4E3DF187DD4507ULL, 0x990F89F0BE4C8188ULL, 
            0x2A33B4743C2ADDE4ULL, 0x14F5319F103B1EEFULL, 0x6973A6CDD8C0224EULL, 0x70D56C2B0249FB56ULL, 
            0x4C892909321B7A79ULL, 0xDF7FC1DA72675E33ULL, 0xB3E8949D75401DF1ULL, 0x12CB7E55BE93E92FULL, 
            0x98A578D5AF0D6FA0ULL, 0x264ACB2B07DEBD73ULL, 0x8EC3305DABB5E995ULL, 0x427C6679E5618E34ULL, 
            0x05D815E7700978D9ULL, 0x7D1885E2578F3E49ULL, 0x352D2EF973BEA22CULL, 0x23468652B5CDE478ULL, 
            0x403BA8C13F44AF66ULL, 0xF4BA53F6693C4309ULL, 0x47EA5CCDB9636986ULL, 0x2780E30F7DA43664ULL, 
            0x6D47B93F41B2B32DULL, 0x61FD09C50223525FULL, 0x940AF178B899117CULL, 0x081AC8ED019DC5A5ULL
        },
        {
            0x322081B9DA2F8008ULL, 0x340520EE0C20EE31ULL, 0xBD5C1FC2930249F1ULL, 0x38AE3D7D66226A2CULL, 
            0x85DFE74308C88ACDULL, 0x2E84647584D4397BULL, 0xEC2B6604E432E141ULL, 0xE218A3F1D502CD93ULL, 
            0x40B43272AD8A69DFULL, 0xD595D05E23596A2BULL, 0xC6628E2BBB08D8ADULL, 0x2F9DB46A7ABFE518ULL, 
            0x04B64E0007C15C7CULL, 0x8962C5349EE81B42ULL, 0x99B961C8227858C4ULL, 0x09AD92FABD5BB25FULL, 
            0xE7E9C9D7AF81DEDFULL, 0xFC7B8EA18E5B6509ULL, 0x346DDB24E037F463ULL, 0xEA1B4E30F3B5F9BDULL, 
            0x5861130A408DA664ULL, 0x0CD24447B8B8910DULL, 0x99D43FD8F69F555DULL, 0x04BA6DD00B97E5DCULL, 
            0x47102311BCF18B38ULL, 0xE72180193F67A13FULL, 0x894D1292D0F91BD6ULL, 0x14D24FFE5870DAC5ULL, 
            0x1F6B2D007529D61CULL, 0x9BD2F173A12FD5C6ULL, 0xF4F6F7DA4849DB11ULL, 0x25949D2CA7C17CB5ULL
        },
        {
            0x8FE6BB4CAC819F47ULL, 0x64AAFA48026F544AULL, 0x8F75A289F54CB730ULL, 0xF27489E7BBE4E5C7ULL, 
            0xC52CCAE643E212B2ULL, 0x7D7124DC60FFA923ULL, 0xC6BA153A5FEF0A13ULL, 0x685159E6CBA15C9DULL, 
            0x477D3B433AB9C243ULL, 0x4B9C5DC6C497CEF8ULL, 0xD5A8C272DE4C1B4AULL, 0x839A35C0166DD0E9ULL, 
            0x7D14856B11F2BEB2ULL, 0x748A6E389E0EC6D7ULL, 0xA13E3370B059216DULL, 0x2B06C143AE8B99AFULL, 
            0x3E95BB88A5E090ECULL, 0x5705D15D19CEB57BULL, 0x3E4242839A0C1790ULL, 0x5493723F31D85976ULL, 
            0x1C0449761DC4D570ULL, 0x82F1C1FAF27B8CB6ULL, 0x532B93776FAAE292ULL, 0xD8188B8188AC9FCEULL, 
            0x7025B19FDF4F3803ULL, 0xD5CAC06BB3E28241ULL, 0x336E98123CEC064AULL, 0x7790BE4D66CA86EBULL, 
            0x6F069E86BD60A623ULL, 0xE305BC6D814DF3A2ULL, 0xADB934CBA87DDC1BULL, 0xE7BAF59E43550BE8ULL
        },
        {
            0x342903B3E8C1B6B7ULL, 0x55A25CD5CA2DF780ULL, 0x313D27A7BCD94FFDULL, 0x025AE720E5B0A8C8ULL, 
            0x7D6AA859627D8F65ULL, 0x115B0B6396472480ULL, 0x3779714F341C3A04ULL, 0x09F1EBBC7E12A3EEULL, 
            0x8612F168F6A5B921ULL, 0xA7549C3BBC2DD8E2ULL, 0x210573ABAA98EE36ULL, 0xBFE2BC89D2FD6368ULL, 
            0x1B80A3DCFAF16561ULL, 0xF62AD57C162C11A1ULL, 0xECAE5663776CE1A5ULL, 0x72238E6A49AD0F9BULL, 
            0x8D6CD9996026700DULL, 0x8F852E99A5A6155FULL, 0xD1C21CDE32B3E41FULL, 0xA5782ADFB8C29AA7ULL, 
            0xD9B12EF739BF0DECULL, 0x1C61770F6C882D86ULL, 0x5B8AB9EE99400EE4ULL, 0xC679BBC309051011ULL, 
            0x36C252BE6E71C5B1ULL, 0x188AF2842713B54FULL, 0xE38CB2C0D716C404ULL, 0x0D3332D463C45C3EULL, 
            0xCBF2348B29881D84ULL, 0x7972FE4A2C47293EULL, 0x18AC57A6499C1202ULL, 0x455792CDBB95601AULL
        }
    },
    {
        {
            0x3C627B8D0049CD3FULL, 0x41C37509C56403F4ULL, 0x694437889E42D689ULL, 0xF98F672174645A22ULL, 
            0xB815B07BCCBE7AFDULL, 0x625F2F22CD4809C2ULL, 0xB0E77810C5AF0126ULL, 0xB5032D4A5B8FAC20ULL, 
            0x07B5CBD2B5455115ULL, 0x0930AAA04648FBFCULL, 0xA86C49DADDABB516ULL, 0x18504F6FDA369308ULL, 
            0x67AFB7EAB9362D55ULL, 0xF0DA713E789D8AC6ULL, 0x5FF17BA720DC25B0ULL, 0xE4EB730031BE6A4EULL, 
            0x99E60E9A1E438AB8ULL, 0x2BF632FB6D6A8C5FULL, 0xE23B0FCA0DB0CE2EULL, 0x12199D8DF85B89AAULL, 
            0x048BFBA36B1FD21CULL, 0x6DA240B9D79CE9F2ULL, 0x78A971FEF76B15C5ULL, 0x91457FF4B8BB8C54ULL, 
            0x6BC20FAF40E9729FULL, 0xEFB1F4361158A0D7ULL, 0x7B2FCFD993203370ULL, 0xF2E96D34FCC8D796ULL, 
            0x418B78B0848E4F8CULL, 0x43C9C509E4D114C3ULL, 0x7DF778AE1A47D886ULL, 0x1759A646C576FA16ULL
        },
        {
            0xAA686E58199C7282ULL, 0x0521D698ED6B11F4ULL, 0x3F5781F2CEB19309ULL, 0xBC5D50F4DD7F7B44ULL, 
            0xDFF06097A6C5F849ULL, 0xB4BEAD2271D8458BULL, 0x1477869FC60AFA15ULL, 0x80A49A0ACFEF3A87ULL, 
            0xEA6CB3E6EDF4891AULL, 0xD679BC073E394FE3ULL, 0xD01D25F76465E9E1ULL, 0x406B8EBA9672E235ULL, 
            0xC98945BE876575D3ULL, 0x19F801BA7DF05CD4ULL, 0x0059A490B07CE659ULL, 0x8C533EDCCC9093F3ULL, 
            0xC3FA910C669D7C71ULL, 0xCD0AF45487C0BCC3ULL, 0xCE238150D34A594AULL, 0x3486BF021D71BCF7ULL, 
            0xAC9BCF6AF4698D45ULL, 0xD1893797C34E5DA0ULL, 0xFE5FD63D3A5E869AULL, 0xEDC8E7C783D4E363ULL, 
            0xD74F7EEF51060DC7ULL, 0xE5FDD6F7632E808CULL, 0x17A2C65208AAB1ADULL, 0x39536984F36C1C0EULL, 
            0x72424481A0026847ULL, 0x8226FC4BFC5DA16CULL, 0x5E71042A2036028EULL, 0x70CDF4820974B5FCULL
        },
        {
            0x5A00662ED0FE0E6EULL, 0x58B529F67ADA81E4ULL, 0x6CC9C1A56BE97AA8ULL, 0x4115C0CDEC0E74A0ULL, 
            0x14F2EA77B3C7271CULL, 0x6E2C436932AEA2FEULL, 0x88470D06EC0B61E3ULL, 0xAD751FE822734C32ULL, 
            0x68B4938E53534049ULL, 0xC528318BFB613AE2ULL, 0xA844FE48B90C77BBULL, 0x647B3A0C09224C29ULL, 
            0xA0AE6C8C57A5BC65ULL, 0x91B69B92ABB2AF79ULL, 0x2B10934275F223E2ULL, 0xE0942AFD0093323AULL, 
            0xBD4E2BDCACB5F4FAULL, 0x7D771FE38F99C4E9ULL, 0x629AFAA61822E0E9ULL, 0xBA09C6F83C80449CULL, 
            0xAB73710A7CC71493ULL, 0x66B1E9D576DAD832ULL, 0x4C20232C88A2BF83ULL, 0xD105AEBE2354C84AULL, 
            0x57BE1DFC3C10F8E3ULL, 0xDE54081C676BDFBBULL, 0xA0E3DE17D0213163ULL, 0xC728A0348F3ECF2FULL, 
            0xDC349ACCB926048AULL, 0xFED5BDE6C5C09ACAULL, 0xA2590C17CCF0A73CULL, 0xD1D7D19780A141E3ULL
        },
        {
            0xC78898286E1EB4BCULL, 0xD5AC3B50AA9E8967ULL, 0xFE6B569EC9F3F0B5ULL, 0xDA5363793271A36FULL, 
            0x4EEF71D1E90DA356ULL, 0x849AD391CD0D110AULL, 0xBAB58B807E01B0FDULL, 0xAFB5ED34CFAC1B89ULL, 
            0x694DF8625FD335A5ULL, 0xE5EEE601A05C5AE7ULL, 0x92DD4BF1EBBF38A5ULL, 0x98441E7FD427C184ULL, 
            0x3A8ED3DE989B7E12ULL, 0x567C67FB22B10CBDULL, 0x809D4747A52F28F4ULL, 0x6544DEDDCB091D14ULL, 
            0x717AD8FADA763633ULL, 0xA3970E7D334A005FULL, 0x42F955761FDC646DULL, 0x611FD9EB39F60643ULL, 
            0x592ECE4F98B854BEULL, 0x2E9DCB7CAF1B0A54ULL, 0x612EA8C1DAACB26DULL, 0x68FF1486F8D59968ULL, 
            0x21337F792469433CULL, 0x8E569A7F7C6FEF90ULL, 0xC0AACDEB7F8C4BB6ULL, 0xBE54179B18B4B991ULL, 
            0xA58F5C8EC66CBCC4ULL, 0xFAFD7C04A2F848FBULL, 0x3F9BB5F0A439B522ULL, 0x0442F583AE163369ULL
        },
        {
            0xB79604D740CF4548ULL, 0x1EADA6FD0D2EC5D8ULL, 0xF6191151C39E4721ULL, 0x8C9FD65EE7ECA3EFULL, 
            0x37BC7A1166C9CBC2ULL, 0x5FF16B05B545E95DULL, 0x93BAA1FD4F3DDF48ULL, 0xFD05ACA58B6D1AEEULL, 
            0x2A0A92AE87F0182FULL, 0x69D2BDC92F766829ULL, 0x2252EF2A45CF38B3ULL, 0xFB066D10ED0D3AC3ULL, 
            0x41F7CC0794D5A2CEULL, 0x2606793EA037B158ULL, 0x3C479827E40BF08FULL, 0xC9F6A5564E7E5C40ULL, 
            0xBA64B41DC02A3364ULL, 0x21F127BB15189F43ULL, 0x292D987199AC5951ULL, 0xDB290C3547FC4C9EULL, 
            0xFA6E8702D98F62C1ULL, 0x6673C6FB5E807974ULL, 0xB123E24B17331047ULL, 0x419F4C59959B9E9EULL, 
            0x113EA0D20A1541B5ULL, 0x323B67F7C0C1B064ULL, 0x5C241ABC7D7BDCFFULL, 0x8AB52CD4E45912F9ULL, 
            0xBB50DE09A9DC75EBULL, 0x1A51713EA8EDEAF2ULL, 0x481F697451B2AE08ULL, 0x04718E3C45B7EEB2ULL
        },
        {
            0xF347267974EA3645ULL, 0x3CE82C634DA9FAB0ULL, 0xAF22065655C0024FULL, 0x93B2644C1350854BULL, 
            0xE32639950902ABCDULL, 0xE6E7B7E5AFAEFD93ULL, 0x407BAC4702C105C0ULL, 0xF5D45BF773765CC4ULL, 
            0xAEEE376D34661932ULL, 0x0FFB282F661004BDULL, 0x987C620CA0A97C02ULL, 0x7B27947D7E7BC92AULL, 
            0xD9EEFAA5418350B9ULL, 0xB2AC98AC49588363ULL, 0x0A56D19E20E6FFEAULL, 0x0474302CFBFF04CEULL, 
            0x15E1139883B9536CULL, 0xA8E81132E036BDF4ULL, 0xE6B13F4DF5AFCC52ULL, 0x94E9540EB37355ACULL, 
            0xE8268E7417766F4BULL, 0x5F83E3A1FFE16117ULL, 0x02D7F9A027891B13ULL, 0x970FAF447E4ED8A7ULL, 
            0x041E15498CE7AE2DULL, 0x1B7381CFB58D8AE0ULL, 0x7CDB33A2A9184732ULL, 0xF2D10C06EBF53D6CULL, 
            0x5DE74DFD507EB5FDULL, 0x0EF75A49533E7531ULL, 0x1B2E0A1DF80CC853ULL, 0xCB0479731CBBFB03ULL
        }
    },
    {
        {
            0xFBE890097D4D5709ULL, 0x99E1EAB1416CBCCCULL, 0x38D4CF3E7BB72727ULL, 0x49BFB5D57CFB5FCDULL, 
            0x09FE81228D46E171ULL, 0x0F6BA45AC1F782A5ULL, 0x8A4BA59762E59606ULL, 0x6BF338874B1AF466ULL, 
            0xB8D612CB829EACF0ULL, 0x192FA7CAD24BBA6CULL, 0xA768ABDDC991F36FULL, 0xBF94D3BEA92F910FULL, 
            0xD30A084045520F1AULL, 0xFD2A56A09901E9E5ULL, 0x75B764592E78A2D9ULL, 0x92C629F21D4E9A97ULL, 
            0x63361FC0726419F8ULL, 0xBF27576D2FA04F5DULL, 0x10809CBDE3F97943ULL, 0x3A5479E8AF72B74AULL, 
            0xF4B36FF93B879C3BULL, 0xBA066A9C3BA53B61ULL, 0x471981E32CA95682ULL, 0xD6695F8CF001A53BULL, 
            0x8FFFDDAC465AFD59ULL, 0x55C205B0AF7F5C6FULL, 0x87366922E93AF452ULL, 0xD0B7D2435A6809A9ULL, 
            0x8A7408C660C62CEFULL, 0xD7A9E8CD0C523A11ULL, 0xB0BBEC705C9101BDULL, 0x67CC057BE46C4FB1ULL
        },
        {
            0x4AE1037941D62BCEULL, 0xA15318ABAF81173EULL, 0x26282155E6935A1AULL, 0xE84704667790C6D6ULL, 
            0xF56CCFB5BE53ADF7ULL, 0x895E3801B365D361ULL, 0xFFB7F54444D1A2FBULL, 0xA5C4A6D0AFFD9F8AULL, 
            0x5CB18D098BE55505ULL, 0xDE4418C1EC0917E9ULL, 0xAA16778520EBF177ULL, 0xEADC540F96EEF25AULL, 
            0xEF5C526890388ECBULL, 0x86E575C32E6B1CA7ULL, 0x8CA1C0361DE414A4ULL, 0xBA7B2D314D7AD2F8ULL, 
            0x2124F5C217C3ECE1ULL, 0x44233DA06461E928ULL, 0x7BAD95D0B15FBA10ULL, 0x104F577B83D8A2D1ULL, 
            0x602A3BA39F751F10ULL, 0x3722E19AA6FF265EULL, 0x6E8CAB1867B05D43ULL, 0x59E08983DE95B13CULL, 
            0x744E3FFBD2F47B0BULL, 0x9070A80CB5F63124ULL, 0x118FEFD1D51A8D48ULL, 0x57DA4CFE65566DA5ULL, 
            0xAECEB560EFC47477ULL, 0xB1AF4AE5CEF58901ULL, 0x452C4A62B2AD5BC3ULL, 0x15C81C228CAF5302ULL
        },
        {
            0xEEB918FC9FB8770FULL, 0x6092B02F4E41B925ULL, 0x2A45F403A8177A0FULL, 0x6171C00280EBE6F6ULL, 
            0x39E9B0BBDBFE5C09ULL, 0x89E65C0A1DDC6DD8ULL, 0xA1F74E835911A401ULL, 0xA2C72BA772F9B907ULL, 
            0xB04D9BC0DC2B86D2ULL, 0xB349F2FA4F2A1D0EULL, 0x0E30FD5C15D17538ULL, 0x7FF54C576E505B63ULL, 
            0xC6B4D4D6D6BF6607ULL, 0x591498BF25771CB2ULL, 0xF751A7BE51C05B53ULL, 0x6280EDB5E40C5309ULL, 
            0x2D9483701738C2C0ULL, 0xCD795E3D6DBDDB97ULL, 0x89144989A45C4EB4ULL, 0xF57A6CE25788B76AULL, 
            0xE99A0C0776BE92FEULL, 0x9AD34CF654A7D625ULL, 0x0151A81EDA9263D6ULL, 0xF26C734878D18AD0ULL, 
            0x127385B8742CD604ULL, 0x6C736862D24C0A1CULL, 0x8DE3049481146156ULL, 0x24D1FF3C30C3632FULL, 
            0xFB6F752E5AE92608ULL, 0x816414BD13A1B414ULL, 0xA43EC08B9C8BFFA7ULL, 0x5EBE659A12B7CAC4ULL
        },
        {
            0x6EFF45942E0F3AF7ULL, 0x93E0DEC32ACB3092ULL, 0x8E01003EE299BECAULL, 0x388CECF4D50A0FC6ULL, 
            0xD5CE2BBDBCDBFD1AULL, 0x1874F3018BD97779ULL, 0x411430B9DF39BEB2ULL, 0x10F0AC779E32C2B7ULL, 
            0x29B85EB7FD82EBBBULL, 0x11B02962370F2579ULL, 0x9B2DE715EFE4FCA4ULL, 0x433F9B19C25CA2E8ULL, 
            0x80DA81C68366BCD2ULL, 0x4A50275BAB0C88ADULL, 0x32059951D24F7D63ULL, 0x23443883B5FE58E6ULL, 
            0xE0D50B7C5E74B4FCULL, 0x9CBCC8F0B22BDFA4ULL, 0x5AA1747314B8F260ULL, 0x7C8150CCD7755299ULL, 
            0x7E0B2C45EFC9E73DULL, 0x6D681E1E72AC8627ULL, 0x50FF0D525D1070B0ULL, 0xBBCCF6195F040087ULL, 
            0xBD1782A3A711C56FULL, 0xFA04A4D38B58CE59ULL, 0x9D87A150C25A4D29ULL, 0x2223E17127ED7219ULL, 
            0x577D3455E9DB7A91ULL, 0x5C0E51C58B9A26AAULL, 0xC379552C579FCEB8ULL, 0xB7D18CCFBFC01FAFULL
        },
        {
            0xCE3FF834BFA0B86EULL, 0x4FD0688330C227B3ULL, 0x96FA0EC0248D05FBULL, 0xD5C38AF48DC727C4ULL, 
            0x26EA98FAA3E0EC57ULL, 0x241921AEE9F29FFBULL, 0xF10C97C156FC9460ULL, 0x218153080B7A4124ULL, 
            0x872233EB926C7289ULL, 0x3F367739E4AFFA5DULL, 0x9C0270B7EEA03363ULL, 0x0C11845C186F66E3ULL, 
            0xE5C601D2A31EBB49ULL, 0x9A59F51A637EBE2AULL, 0xA9523E5CDD5BDC9EULL, 0x5FD56F53720C01DBULL, 
            0x54C6F1E7C290512AULL, 0xEFED348DFF7B0F3CULL, 0xDA9D5C8E95476DA5ULL, 0xDDD3337082799EACULL, 
            0x7EB24A4087A3AE80ULL, 0xBD8226A7E2CC0F15ULL, 0xA7262EA64E069DB5ULL, 0x93FBBDB72E34E943ULL, 
            0x68CF78C78D8B7C64ULL, 0x465BB23F13014946ULL, 0x3E21A6B089127690ULL, 0x48213D3484D46BF8ULL, 
            0x92C2705D704912B5ULL, 0xDB9BDF7ED6850CD6ULL, 0xE1DB5B61348E0DBCULL, 0x14097B3FD50D5CDDULL
        },
        {
            0xD8FC1FBBD2D40AE7ULL, 0x88F58CFAB9865C9CULL, 0xF2AF48FD26761F1CULL, 0x1BBB42735E3BB8D1ULL, 
            0x16B58A04CE444EFAULL, 0xB5B23060F5A76FB7ULL, 0x6F24235C7B1F2CBEULL, 0x3A397CF6408A588DULL, 
            0xBB9084D3EB50A817ULL, 0xFA7BB815FB628E02ULL, 0xCF972EA524E8B71BULL, 0x9156860B00E14BDCULL, 
            0xFE63A2013A1E7CE6ULL, 0x6F6922A2FDEBDD35ULL, 0xFCC84575536E336FULL, 0x2235C75F4EFEEB15ULL, 
            0xD5E401F602C9CB4AULL, 0x4A1FB557E05000E5ULL, 0x665614163AD2875AULL, 0x38C4E2C845A893B0ULL, 
            0xB0C66A9EEED6684BULL, 0xCBDEA74F6825EF36ULL, 0x1FD43B767F32D9EBULL, 0x6EE4A3EF01632C71ULL, 
            0xC1729097D857E5B1ULL, 0xA117E19B34F6A9A3ULL, 0x8B2DA6B1D79CA37DULL, 0x27521B6764CB0550ULL, 
            0x416A39F68DD6BE43ULL, 0x5F328C47384A0FA7ULL, 0xD585E7A5220E61F9ULL, 0x428CC26C50BAE813ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseBConstants = {
    0x0CD6BF2D1BEE3C38ULL,
    0x4F68A90A8099A530ULL,
    0xE2C1B4210E019997ULL,
    0x0CD6BF2D1BEE3C38ULL,
    0x4F68A90A8099A530ULL,
    0xE2C1B4210E019997ULL,
    0xA42C2EF9973F7CDFULL,
    0xE52E1178AE2C5CA9ULL,
    0xC9,
    0xC6,
    0x0A,
    0x06,
    0xCC,
    0x3E,
    0x70,
    0x77
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseCSalts = {
    {
        {
            0xC08ECD2D2000A25AULL, 0x20E3E8600A7113EEULL, 0x69518CE7DC8D1CBDULL, 0x389AA66C7289994BULL, 
            0x5AF44AD39BE03AB4ULL, 0x0982699411A663FBULL, 0x45E39093C7C53F55ULL, 0x699226B13C1FCA84ULL, 
            0x763878C170725648ULL, 0xD984BF14B975B45EULL, 0xF95392AE870A33AFULL, 0x79F6370C3FE7E9A2ULL, 
            0x531CE261CF5CFC09ULL, 0x399FFFB8B30C4669ULL, 0x788D713BB2786606ULL, 0x9EC56EE0D271223BULL, 
            0x17AADD37DF69D738ULL, 0x192BED4D7D1A430CULL, 0xE872764E0F67AA01ULL, 0xB708205048EE3DBFULL, 
            0xD91A3BF6E7AA37D7ULL, 0xEA90C6CD5A561768ULL, 0x694CB2F1FDA9A16EULL, 0xDDD98E29481B6A4EULL, 
            0xE26DB0FECEC246E5ULL, 0x8FD5F192072F63A4ULL, 0x3F386BA72432041BULL, 0xDAF2080AB49A5747ULL, 
            0x064DC8932EA0CF94ULL, 0x6BEAC9335D0DBCEEULL, 0x3317D76DC37D611BULL, 0x0CB4893D1366502EULL
        },
        {
            0x76C44EB8867A7758ULL, 0xDB5D9AF27089A007ULL, 0x4C31D1CDBB698917ULL, 0x9EBE6BB0B775A2C9ULL, 
            0x68033E869756D2F7ULL, 0x18DE79C7F6CF8632ULL, 0x716CF901B538DB16ULL, 0x55D352D762D9DFADULL, 
            0x8D6F21072DD6902FULL, 0x7A3364F64DF671E3ULL, 0x538E43312E5B8398ULL, 0x3E02756B6627493EULL, 
            0x11F56E874458B7FEULL, 0xFD2E06CE4FB196DDULL, 0x6761DD2BFCB03A23ULL, 0x4EB64D86466E3029ULL, 
            0x3B11B5A89F721346ULL, 0x57A71595AAD506ECULL, 0x618BE2608FB91CE3ULL, 0x2EF11910C24B64A5ULL, 
            0xF044899C88D69D9DULL, 0xD09F579DE9ACB4ECULL, 0x697318384398E1E4ULL, 0x794197B3F0F85D7CULL, 
            0x132802F04AE9F97DULL, 0x022D1D49F9F7F0B0ULL, 0x98E9CBCE2AD1A1B0ULL, 0x4B4A86B7A441349BULL, 
            0x3A4F5A17F93BB4E5ULL, 0x69073D74985696B0ULL, 0x0BC93FA15D559CA1ULL, 0xC381F3D2F5357D8DULL
        },
        {
            0x8108D6DC7195F6E8ULL, 0x4C62966B6ED24735ULL, 0xEE3E91F3FB6D5B01ULL, 0x694C7F035E067097ULL, 
            0x714ABDF7F1D682B5ULL, 0x6454336065E9AE97ULL, 0x38689F6AE435DC57ULL, 0xAC9F33F06E506236ULL, 
            0x06A933375A060E96ULL, 0x5457FFD14A9A62C4ULL, 0x4A7E261864A1BA4CULL, 0x27EF1B7EA7D5ADFEULL, 
            0x712A4E4B9BCE9E19ULL, 0xDA7C62CDE514C374ULL, 0xE5F4EC4961CB671CULL, 0x80957CB75C06AB3BULL, 
            0x6C7577102CA57628ULL, 0x5D47D1B00F1A1E94ULL, 0xF2876FAE49D16B5FULL, 0x9F8BABBD00D8851CULL, 
            0x0ACA9D4753BF1DE4ULL, 0x6708B7892D2DD6A1ULL, 0xCFDAA965C35192ACULL, 0xDB6C64D16E97E008ULL, 
            0x0BA7DDE381F5742BULL, 0x9861ED8EE0E3C1D4ULL, 0x2FBBCD483C560DACULL, 0xC2CEBE7A88E84476ULL, 
            0x64AE327F5F9C2AF1ULL, 0x93455CC4FD6DAA1EULL, 0x40FAB884E0BD0E84ULL, 0x254978F6B7D70E25ULL
        },
        {
            0xF1C94D4F3D2BEEE5ULL, 0x6B85ED4166F3A332ULL, 0xCEDC638EC7A4BFFDULL, 0x8590182D39B464CBULL, 
            0x5AA4ABEC2C51042EULL, 0xC710A357B0CE60D7ULL, 0x2B883076D9C884E0ULL, 0xE89E81CCB7074112ULL, 
            0x15A419D8AD45CA0AULL, 0x1E2A54097B9BC725ULL, 0xE8205995AA98A760ULL, 0x51BA2A4C78700AE2ULL, 
            0xE2F38A327F80DD35ULL, 0x1B6A0081B123828BULL, 0x892A838378378D20ULL, 0x5AAA3BEB67F40E66ULL, 
            0xFA04565FEE23F1C0ULL, 0x188DCF5B8E071717ULL, 0x38C8DB7F0C18ACDFULL, 0x0B9CF75073600551ULL, 
            0x6794D1B0D79B76B8ULL, 0x5DAEB754CFA1A393ULL, 0x126A994A425D79CBULL, 0xACC7BFDCE580C2E9ULL, 
            0x0E9F03FA7B053723ULL, 0x43795FB4C74CA8D3ULL, 0xCED72830A09619D8ULL, 0x2E92A06F50BED8A2ULL, 
            0x45BE3D530ED084A6ULL, 0x5464E9ACEBB259A9ULL, 0x2DDE1AC9F50D9241ULL, 0xE9BBB75BFA604CEAULL
        },
        {
            0xE0F8E4DDC24E4428ULL, 0x61BDA2A1B48D31DCULL, 0xC1984EC8B8EB6CBDULL, 0x54DFC7A7773BEE01ULL, 
            0x4556F7C507667630ULL, 0x5058D8D4A4293659ULL, 0x9FE17A79AB55B328ULL, 0xD7A3A2372664C88FULL, 
            0x64CBBA2B1ED6E6DEULL, 0xDCAC9905B0BE17ABULL, 0x3FAB1AB3A4E2194DULL, 0xD0538A2AEC13D728ULL, 
            0xD52CF750545D9201ULL, 0xAB00F1DE41EA1ED1ULL, 0x44D6623562F4734AULL, 0x6B616B8D3339C13FULL, 
            0xFEEA6C7AF2D10A7BULL, 0x48D033D480B73AAFULL, 0xA3B12EAD0EE69719ULL, 0xAE8549E626C6A02CULL, 
            0xF785BE417C8D66B4ULL, 0x3735687399E304F5ULL, 0x153D638FC247931AULL, 0xA60C915E7E70B333ULL, 
            0x238EFF89B839ECDFULL, 0x74656042C560259FULL, 0x2B7A7AE8A1E0B582ULL, 0xA2BC082C1921134EULL, 
            0xB4EB5A63B2BE0570ULL, 0xCDFA603EB6FDF3B4ULL, 0x0F209FA3EEA202DEULL, 0xDDC1112D7D221015ULL
        },
        {
            0x8C12600F2F1445ECULL, 0xE350C622BCCADB8FULL, 0x323423FF285BCBEDULL, 0x694E1316AF8F2E2BULL, 
            0x4BC34BC67696E795ULL, 0xB552A55274570A45ULL, 0xAFE4E2766D3ECC5BULL, 0xFC9AFB94496D8C11ULL, 
            0x6B92785BD905531EULL, 0x7CDD17677BF5C3D8ULL, 0xD4BAD308F11D1008ULL, 0x336955554641C3EAULL, 
            0xDB646F97B7F80AA0ULL, 0x739A86C1806BCC7FULL, 0x303A5FB7FD27BF0FULL, 0xB86F9FA69AB27DE4ULL, 
            0x560B3A083F9528BAULL, 0x4E7083F19D64F5E4ULL, 0xE7BC452A5FAC1F71ULL, 0xD23FEA90BF53767BULL, 
            0x276626AC3A1C3396ULL, 0x29DE44E66D6293ECULL, 0x6565BC6F5F5A5B49ULL, 0x546F389B124F9D26ULL, 
            0xC5D9D89D613A0903ULL, 0x50E4AC4C7F2B577BULL, 0xB397437559DDBC90ULL, 0x69DC1BA0DA78F6B9ULL, 
            0x2742DE62D42836A4ULL, 0xB3616B3B49587F52ULL, 0x5C055F8BE5B61673ULL, 0xDF4D4FE0D2268979ULL
        }
    },
    {
        {
            0x156F589E41FE013AULL, 0x16C0B21ADF641F0FULL, 0x426025E0257D99FDULL, 0x8006E2D8175321DDULL, 
            0xF6AA99A45C27F7BAULL, 0xEB87F097C8899578ULL, 0xE8D8BDE62275FBBEULL, 0xD6F840FD5DA8B4A6ULL, 
            0x17CD8FC041C7FB0CULL, 0x5590E365DC00201AULL, 0x148DE2A08D3573EDULL, 0x7B6E9AA962AE1A23ULL, 
            0x46C2F051E73D751EULL, 0xD7188BCA43466E94ULL, 0xC3A8E5B3A8C94219ULL, 0x187F20EBCDB89A67ULL, 
            0xD3B59C61C8C28C62ULL, 0xC6C7547BB961F8C1ULL, 0x277DAFC8FF674BC1ULL, 0x3306B76469A59BCEULL, 
            0xE8F045A7B0C022BBULL, 0x94B6FA3DD6F03C13ULL, 0x5E396A4A71EFA725ULL, 0x9AE8C0BBB1005386ULL, 
            0x8F336B970B6E7F46ULL, 0xE743333656DD84CCULL, 0x4C23F4758239B4ADULL, 0x074324DEC93DA506ULL, 
            0x076C186B0A2D4B91ULL, 0xB5B7197A864FA467ULL, 0x2FA0E62EB3365A2DULL, 0x672D079F4C252A22ULL
        },
        {
            0x73F6508F8B7E1DF8ULL, 0x925AA3EE8FE1BB01ULL, 0xDA8C38CB6F656FE6ULL, 0xD7C37BA4A9F978C0ULL, 
            0xBD83B8E6FEB26886ULL, 0xAFF1B6BE33803EC6ULL, 0x1CC7B6BB0C6C4EDBULL, 0xA9D34B67C332D2C0ULL, 
            0x193B650A40088D91ULL, 0x5B424FCA4D677DB7ULL, 0x62BE0ED22AE5046FULL, 0xFB12743F302E5B43ULL, 
            0xF195617D6217B5B1ULL, 0x2758716992219458ULL, 0xEB4624644E3D2874ULL, 0xF652009B660CCE7CULL, 
            0xE5916F357663A020ULL, 0x3A80F64A4C5B5988ULL, 0x8E7BE1B58AA9AF4CULL, 0x37A7707D031A103DULL, 
            0x752D6E6E3D2B1E35ULL, 0xD8303497F02832B9ULL, 0x29D89D3BC3E507BAULL, 0xC7500D0EC334CFDAULL, 
            0x490632D7F7B0C623ULL, 0x8CD2FC188C05C52AULL, 0x7D14EB1B10601C14ULL, 0xFA317ADA94367DFEULL, 
            0xEB3FF6EDA75BE7DAULL, 0xEF0F18CF9C4AFF94ULL, 0xFD7C1FB356217A8EULL, 0x7C5C911581B56CA8ULL
        },
        {
            0x7CC10B3B74884348ULL, 0x2C755B8F99D4891DULL, 0x54E6B12E1227BB8DULL, 0x68B9000ECCB1A868ULL, 
            0x109D15910B4F5D83ULL, 0xCDA05DD2B22513FCULL, 0x27EAD5BC4388639EULL, 0x941B12F185E14163ULL, 
            0x5F3CD228BD8D1538ULL, 0xC3A7C1E23DA5DC6BULL, 0x9A99C834737127D3ULL, 0xB5E8EF0F823CBAADULL, 
            0x3E217A083CAD1F10ULL, 0xB954D281B7F2D767ULL, 0x44A4952BF4C2B12AULL, 0xA813942A9316EF33ULL, 
            0x30FA59316B9EF069ULL, 0x058CDA8DD6489B86ULL, 0xC1CBED435DFC2CC2ULL, 0x30A13C21AFE1A177ULL, 
            0xF05B90B44D0CE31CULL, 0x82D00BE4F0F381BBULL, 0xDAB4BE9F7C1A3C9EULL, 0xBDA897C11FA0CB64ULL, 
            0x897F5BCC291D5CD3ULL, 0x6CCB814D8EE9B51AULL, 0x24BE7E65EC0430FAULL, 0x2DBDD464BAF12E84ULL, 
            0xA44F87FD5E45DA6BULL, 0x7B51834BD05167D7ULL, 0x7414B90F5E5EAA48ULL, 0x7690CD49690C9BD4ULL
        },
        {
            0x5F385510B47CA1B4ULL, 0x01F4AB13A54027DCULL, 0x01BFA0A7AC1080E4ULL, 0xD8086B6840AD35D5ULL, 
            0xFBEA1DFB63097216ULL, 0xDF435679A7FF5905ULL, 0xBFE77675A01F2E6AULL, 0xD5CA11B9B25FA41CULL, 
            0x284000933CB70375ULL, 0x6A8D8F577FDF0D09ULL, 0x56160AB8FCDB2750ULL, 0x50EA3A0BD782EDCDULL, 
            0x9FBF542B999302AAULL, 0x8132DF10DA010A4CULL, 0x92C8CC62DA92B694ULL, 0xCF28C1841442FDB7ULL, 
            0xA628EABDA4E326AEULL, 0xD66677E82A67D499ULL, 0xBDA6011BB280EBF1ULL, 0xD11D6F352257C1ECULL, 
            0xA042BD4FC7B3E0B1ULL, 0x4C13205A64D1CE4BULL, 0x7364E11C3F72210BULL, 0x112448D42C8A018DULL, 
            0xA2334F2CEEDFA4FBULL, 0x5B2A156831F82101ULL, 0x53A924FCEC8A15D3ULL, 0x19CE90810AC9C59FULL, 
            0x0725635947E0C28AULL, 0x18D017688AE5DDA0ULL, 0x5565D5742660E336ULL, 0xB7CC56CF528A88EEULL
        },
        {
            0xF826F5C997699A1AULL, 0x42B38F61086AD93FULL, 0x669849B9D4351436ULL, 0x28EF9B5FEA98CCE2ULL, 
            0x8904E4D519632AF4ULL, 0x4B4C248563ACF495ULL, 0x9843FD50284E8FABULL, 0x44A2A6AEBBEFF6D2ULL, 
            0xB76ECCD164A4578EULL, 0x0545323D010AB13DULL, 0x9B45CE26E96648A9ULL, 0xA832B0B5DCC03397ULL, 
            0xCF8270B9A30B1407ULL, 0x082ADA7AB1818AF5ULL, 0x6AF1396B53FCC196ULL, 0x39E8B102A534BEB2ULL, 
            0xD591931DB464B36CULL, 0x3391EA42FA237BB4ULL, 0x09F0B2BAEAE562C9ULL, 0x48D5CB76E471A217ULL, 
            0x4D6F450B118E757CULL, 0x91B5A0E78B26477AULL, 0x69B89E010443B3F6ULL, 0xC2CD2693B9B9F7E0ULL, 
            0x0220F648B8D092ACULL, 0xD5FCEC544F2DF01FULL, 0x3636B015F3E60063ULL, 0x66B9EFD63E795A79ULL, 
            0x0E8D6840B9F9583DULL, 0x2CBE65347FFA0AFBULL, 0x794DB6323A1C258FULL, 0x44DD1A644258AE65ULL
        },
        {
            0xE631C84BF8E42336ULL, 0x8DE9C87819EB92C5ULL, 0x2BD50661F80A79BFULL, 0x3930783AF53F9CFEULL, 
            0xDFECE7D2B1143195ULL, 0xFFDBFD00133350F1ULL, 0xED45B07CB5CF57B8ULL, 0xC08E099A235F3393ULL, 
            0x4A70D6C118940B5EULL, 0x564BED0685A494D5ULL, 0x86074BDE6021E9D6ULL, 0x7368486257EF1156ULL, 
            0xAF7BE19CF112C153ULL, 0x3329E73708E8661CULL, 0x7BF512B09B59E8E0ULL, 0x270273BC83ECA10AULL, 
            0x480A742E556724C2ULL, 0x3FC2D274B810DFF6ULL, 0x4509F9D63C4ADBBBULL, 0x0BC1893D3547ABF7ULL, 
            0x299EEA42500167DCULL, 0x3ED427A39BD3179FULL, 0x3C8A315BEEA004E6ULL, 0xE07B1D5D10A270A2ULL, 
            0xB9DE3067520FBE33ULL, 0x7E21DD6B8C7317EEULL, 0x2EC6110ABEFF9488ULL, 0x205687F9180FA85CULL, 
            0x1E44A11110725E8EULL, 0x9623846D2E63EB95ULL, 0xE430D41C4696305DULL, 0xE84B38C53863DF8CULL
        }
    },
    {
        {
            0xD4031BBD989BA442ULL, 0x4459CC17E485141BULL, 0x53326851FF1930F1ULL, 0x5FC8199588AF994DULL, 
            0x04C4A29F56648AF7ULL, 0x71785632AB0DE84CULL, 0x74A4B64C7C48B0B4ULL, 0xAE202335D6376EB4ULL, 
            0x84A3B6D7EA5FAD5CULL, 0x7995CC892680817EULL, 0xBE3C16ECFB6849EDULL, 0xC67AD8F79D828945ULL, 
            0xC0375A392FE9EDA1ULL, 0xFE45DB65B041D922ULL, 0xF8D78AC4308BF094ULL, 0xB67FB4224FBC203FULL, 
            0xA8A180C5909C31D6ULL, 0x896427000D44ED70ULL, 0x9904A3671190E774ULL, 0x2A62864C197D5BC3ULL, 
            0xF437D2C1FF8DE0ACULL, 0x191EC249619CCAA9ULL, 0x55306C7163C3B001ULL, 0x3A0C387A1D39D3EEULL, 
            0x6F30BBF4845CCDA6ULL, 0xC1BA6C586E60B5B5ULL, 0x24D36C0F655A3A3FULL, 0x9D40D7A3AA6FBB59ULL, 
            0xE1287ABEBCA1B346ULL, 0x1F67E0F37CDE0283ULL, 0x25A66C0218C7F5E4ULL, 0x1A998D10E10E1ED2ULL
        },
        {
            0x1012EBD800F8C0F9ULL, 0xDF904B8986ADA57DULL, 0x14E39B32FD6922D1ULL, 0x7D007E717D663A1CULL, 
            0xA0C36D8740CD7F68ULL, 0x87BF18D564EB2DEEULL, 0x4CD43E700E87664BULL, 0x7830E456E89D4EC4ULL, 
            0x18285A2B876941C8ULL, 0x2F581F30C5167508ULL, 0x7949662D92DC6D00ULL, 0xCB4251B2672C1269ULL, 
            0xBCA9A5CB0F2913D4ULL, 0x5F3EB3435166F351ULL, 0x53CDC39EF4BDA837ULL, 0xB0FB19A00D0CA67DULL, 
            0xF61CC2BDF22342A3ULL, 0x8BD1310598798F11ULL, 0x50A4403CE07554A6ULL, 0x16A25CF7DCABEE65ULL, 
            0x6A49CFD47AEF5381ULL, 0x1DE06AA83F63B409ULL, 0xD20D38EF01F42082ULL, 0xFE5D36EB345D35A1ULL, 
            0xEAD59C6D313C3139ULL, 0x7C80DC0A223B5112ULL, 0x67AFAB5A84A063F6ULL, 0x57F5A715E0629FFCULL, 
            0xF5A8F7DE787EBE18ULL, 0x233D49633D9186C0ULL, 0xB7167636E9A5A41FULL, 0xC7C064CBF52095F8ULL
        },
        {
            0xBE3011E35CA2234CULL, 0xE4708F10C1AB76CCULL, 0x4C8330A708EA4ACFULL, 0xE9E8C21221B8D766ULL, 
            0xEC76B791C9DE3AA2ULL, 0xEF4773B2671F3DCAULL, 0x11EE6439474DE1ADULL, 0x908E18E7DE3F3214ULL, 
            0x52D70937D0EC3083ULL, 0x66575FB1D91F3D69ULL, 0x5FD554058CF2F622ULL, 0x6646BC37E0260345ULL, 
            0xA794879B0B94BDEDULL, 0x49D1949625C88DE7ULL, 0x8A1592E99C93D1E2ULL, 0x94C8C602F5851D91ULL, 
            0xC2747483754726F9ULL, 0x31E1D4D18378D4F4ULL, 0xBAB50AB0769FD842ULL, 0xB7CF9C33522A56A3ULL, 
            0x3779234DADC7C17DULL, 0xB50B81EEBDD6A78EULL, 0xC7033CDD328B2091ULL, 0x996903759E4A4733ULL, 
            0x68B1A91BCD2DDFFAULL, 0xDBEAD47C38F577CBULL, 0x7E5A46C9659B2BD3ULL, 0x3CD9D59CFA09E73DULL, 
            0xE7E8FD9FDFB53A60ULL, 0xE1BC87357333A9EAULL, 0xA313C432A5AB1697ULL, 0x6D76EDCA43845B2AULL
        },
        {
            0xABF8AFDBC1B1C579ULL, 0x75732235EF558E11ULL, 0x8B9D5ED01D3D8158ULL, 0x09FC483780E14403ULL, 
            0xDCBC6369D0B11656ULL, 0xB7E8AAF652D0C5AEULL, 0x13FB4B14F18D33BBULL, 0xC3313532DFBC65BDULL, 
            0x54664F6221742A64ULL, 0x5B79FB2953B15FBEULL, 0x79F4B945C71D78DFULL, 0xE7ED1A6E535FF31FULL, 
            0xC453F4534B4F896AULL, 0xCCFE92861A05DCF1ULL, 0x3D9025357EEE24A0ULL, 0x5AFDB432D02CCA21ULL, 
            0xA4EE1738A1634827ULL, 0x2846E584CF4DEBF6ULL, 0x3BAE03EDB9242441ULL, 0x7076FAC0D3A19DD4ULL, 
            0xB83DA86C624AAC16ULL, 0xE0DAD1DD253C4D67ULL, 0x1C40380E25DB48FFULL, 0xFE56D6D54B90F262ULL, 
            0xA4495D84EBA804B1ULL, 0x9AB3169EA873D367ULL, 0xAAC922A3E5824163ULL, 0xD1AFE0B4D3D56C8BULL, 
            0x494BA3658B183778ULL, 0xEFF71AD68D59A642ULL, 0xED8E8C7D34FAB2F0ULL, 0x762D0D60557523FFULL
        },
        {
            0xD5ED351892832C52ULL, 0xFD471EB005846197ULL, 0x5146857F279C8CF0ULL, 0x0D2B941FB95D0CF3ULL, 
            0x5B8A0933F2F8F878ULL, 0xFFD08FC835EBBFB8ULL, 0x19592D715905DE1EULL, 0xB4626FA9DF18D526ULL, 
            0xD49DC8B83C35D34BULL, 0x6CED6531FD39916BULL, 0x5515449C4EBDAA06ULL, 0xA6DD0ACBBE5F7717ULL, 
            0xB73715AF47F00DE6ULL, 0xDB082B3106CC3442ULL, 0x679FA7A6D2062624ULL, 0x0D2914CC3112CF18ULL, 
            0x5D8096066A41D751ULL, 0x8DEF6E3552EAE603ULL, 0x99E7ECAD431B4CADULL, 0x67914812143405F0ULL, 
            0x008B1EBE7D9D0A81ULL, 0xE01E8EBE28EF4085ULL, 0x4F7365D55B85115BULL, 0x1B7E21701721F569ULL, 
            0xBD9EBC65A63D65EDULL, 0xE6A65FE1D478C6A3ULL, 0x9107102FE4D4FF72ULL, 0xA59B599F7742E538ULL, 
            0xC9E520423DCC872AULL, 0x4336EBB83B773940ULL, 0x4469E5827C643A96ULL, 0x55E25B41DB3A7513ULL
        },
        {
            0x34947ECA85833B0AULL, 0xAA930F2A3E745E15ULL, 0x97A78A895C7F3B57ULL, 0x29C83554F2B642B5ULL, 
            0xB2CB5A3975879E78ULL, 0xEB73DCA2A23653E0ULL, 0x5C42379EB07609E7ULL, 0x7055B2F5DE298A2FULL, 
            0x9E93FDB681B05AD0ULL, 0x6DEE565F96C858E4ULL, 0xED25328B225C0397ULL, 0x02FDB2E2C7BF7700ULL, 
            0x1160826F2DD4C1E5ULL, 0xAC2F2AC00BED61C9ULL, 0xE88988A361AEE775ULL, 0x890238265BAF6624ULL, 
            0xBFFF94D875D945E9ULL, 0x94F52B8DCF762E88ULL, 0x5129791D99DD3C11ULL, 0xC16D196E91A8305DULL, 
            0x927E84487432428BULL, 0x9AF4D6507C7AFF4AULL, 0x5A86205D6F4F5E1BULL, 0xDDF1D858FA303B8DULL, 
            0x76BB9EE10A609ECAULL, 0x3247D9E91688D78AULL, 0x94BB02C93CB6C78BULL, 0x7B1CCD15090C93E6ULL, 
            0x4F0EBC588E5FD50DULL, 0xB9F27B8C0C87E427ULL, 0x2559F69F51488FD6ULL, 0xEAE448E75C5AB979ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseCConstants = {
    0x4DEE8C4384705C96ULL,
    0x59CF39321057A573ULL,
    0x0A5AF725EED505E6ULL,
    0x4DEE8C4384705C96ULL,
    0x59CF39321057A573ULL,
    0x0A5AF725EED505E6ULL,
    0x0F4A90967FCCD9C6ULL,
    0x12EA62FAAF2008F2ULL,
    0xE3,
    0x4A,
    0x30,
    0x95,
    0x01,
    0x50,
    0x04,
    0xD5
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseDSalts = {
    {
        {
            0xA36CB7EE28AE3BA0ULL, 0xE861661B78682E7AULL, 0x2E73EEBB29AAB0F2ULL, 0xF26D45AAF8B6EC75ULL, 
            0x3500810CDA405E8AULL, 0x2940D1B5B77890A9ULL, 0x06979CA2211258BFULL, 0xA4CFD3ADEB9098EEULL, 
            0xA7FAF9969C37CE78ULL, 0x6929B758E9834082ULL, 0x227872F12DF09768ULL, 0xF68B98EC17F2F679ULL, 
            0x59D71DA08BFE9744ULL, 0x12026ACEF0D886F5ULL, 0x6750744A60B78888ULL, 0x120FF07CFD1B19BCULL, 
            0xE628157E9F200311ULL, 0xE8F4AD4D5BE8D414ULL, 0xD509E6033623E236ULL, 0x4CDB5C2B5238FFEEULL, 
            0xBC994DC36C4EA559ULL, 0xAD519F363C07E482ULL, 0xE673CBA6EF96B0FFULL, 0xBC8045F2305D6DE6ULL, 
            0x4CBCF6C095373FE7ULL, 0x15FB2C327D1DD3F7ULL, 0x09F890B7839E6746ULL, 0xBEF65F37D09C08CAULL, 
            0x7D6B21242B3B0B57ULL, 0x9B2FE62A4254D33CULL, 0x19E3CFCF39998CB4ULL, 0x8E5839D54DA62A82ULL
        },
        {
            0xA27990CD24413B50ULL, 0x586282B0398F8D66ULL, 0x067177216C9DAE1EULL, 0x96CFEC59F03B5DDCULL, 
            0xBA11881C13700006ULL, 0x0D2BE54BC4ACE7CCULL, 0xFA83158B714D2F79ULL, 0x846D7FA275A2277BULL, 
            0x5D347A345AB8CAECULL, 0x655BE5BCFD379DB9ULL, 0x93C9738768604340ULL, 0x0BE823C97AD78787ULL, 
            0xF54C890B08B8EB47ULL, 0x3CDC51F7F041549CULL, 0xC65B10F0F386BE81ULL, 0xA9C85D890BD7C8EBULL, 
            0x3E1E10769FE80B57ULL, 0x61D310B4AF0ACE2BULL, 0xF34F071AE4E1F932ULL, 0x4869A818C343E331ULL, 
            0x0808CAE6B2CF1748ULL, 0xBEE751167C18B3D4ULL, 0x295AAAAB4F513790ULL, 0x060E42914A473AAFULL, 
            0x29D9D4827A629BA7ULL, 0x9E53C6F7BAD93ED3ULL, 0x6C6D917112927885ULL, 0x055C011E99543A53ULL, 
            0x8B7B0D3D1BAE085BULL, 0x081BA35533F9B881ULL, 0xDEFC4BF939013835ULL, 0x9C746D1745D67FD8ULL
        },
        {
            0xDA4C7CBE9784F2C8ULL, 0x2EC0BF552EB6833EULL, 0xF81AC186D3E562D3ULL, 0xC30DACD3FF397643ULL, 
            0xF3A38D10AAA2E60AULL, 0x23D6AA6EAB3671FEULL, 0x95238B45855385E5ULL, 0x93D96C1D84AEEB2CULL, 
            0x65F0E98E956BB2C3ULL, 0xB244F29F9E3C8DA9ULL, 0xF15DBEA27C32ACDBULL, 0x06224E06ED709588ULL, 
            0xC3B023E10D9E7251ULL, 0x95A85BF597814010ULL, 0x858503D3F2762038ULL, 0x5DEDE25E60F5645CULL, 
            0xC860D3423B1C47ACULL, 0x7D97A882E7D9028CULL, 0x3FC3264784719C76ULL, 0x5D9432F28CF65DABULL, 
            0x704C6D9DEA75D23DULL, 0xCAD70178CB3EAD78ULL, 0x7DBF6A53AFB99F3FULL, 0xD05CCBDC7499CA9CULL, 
            0x4460BE9955F505BAULL, 0xBB9F636A82A1FEEDULL, 0xFFB0BABE093DACCDULL, 0x1FC56FE39DB34552ULL, 
            0xF5F5F0FF677A3655ULL, 0x7189D545B55CC801ULL, 0x191EE103F7E4A4A0ULL, 0xAD0FADC3AB2949F1ULL
        },
        {
            0x724A1BADCFDFF989ULL, 0x71EA5D6667FB820AULL, 0xC2200D04BA8D1CE6ULL, 0xC42167922A6FF868ULL, 
            0x3BDB1D471C13CCA8ULL, 0x6A55AD427E5C2EE5ULL, 0xD1A88C2F9BF3CDF6ULL, 0xA572347A6B03556BULL, 
            0x9DFC18A248ED80D3ULL, 0x83D3DCE250E2866CULL, 0x3A143D6590B7F71FULL, 0x51877307178E6638ULL, 
            0x597AFDC3D2452A2CULL, 0x8F71F3986985DF28ULL, 0x0B47C23A645ACACEULL, 0xD404D59F71B93D62ULL, 
            0xF150EA8B9CCE4216ULL, 0xE7A9AE30619635B3ULL, 0x7C1DD3469BBFC4A3ULL, 0x07E54AABCF10E713ULL, 
            0x097499CBF7B6A7B2ULL, 0xA28572BDD7BE14CEULL, 0xEA6DA1B8C550DF64ULL, 0x0D2C6C3773679942ULL, 
            0x7A7D26FAB33B9A11ULL, 0x1C8D461F9433E1FEULL, 0xB23FD102D3A3756BULL, 0x327211C5E238978DULL, 
            0x20CC8F494C6F0516ULL, 0xB33CC6D4B096398AULL, 0xBD2AF7236C9F74AEULL, 0x1D5C5DF70E42E8D0ULL
        },
        {
            0x49FEBFA06B154E3AULL, 0xD4F82444F7165909ULL, 0x0787EA70B8AB1E10ULL, 0x7A62C6467A7FD330ULL, 
            0x6A7AAAEFD3887882ULL, 0x7C991B9EF8ABEE0CULL, 0x09EA144902250BA4ULL, 0xB64CBD08B669CD78ULL, 
            0x5BD3620B4B1C9B1EULL, 0x5A409D07F1C9F805ULL, 0x28CA793E49FEB849ULL, 0x55E2E70C0B2B2599ULL, 
            0x909E4F2C07F11632ULL, 0xAD72D1D5C80D9503ULL, 0xFEDBEC1B8E9FE0E9ULL, 0x45B209C2F8381087ULL, 
            0xA5C04F4E6EBE5631ULL, 0xF2F179BC85428A2CULL, 0x5EF09E61B50AD4E1ULL, 0xE2A2B84CC2DB7079ULL, 
            0x57F522CD0E65D834ULL, 0xBA89F2E7768F5753ULL, 0x2B24FA441F3B5CBCULL, 0x82D23DEBC18035A7ULL, 
            0x63CBED4722E96877ULL, 0x68BE4A23E83C8C5AULL, 0x83792CEA59C62C66ULL, 0x9EAB3643E21E495FULL, 
            0xF45811D75E92FADBULL, 0xBCBB56346EA112B4ULL, 0xFC5CF728936E3196ULL, 0x5B30649E7CFC2455ULL
        },
        {
            0xD464400DFDE53D2CULL, 0x65C504D0FB7F85DCULL, 0xDBDBB737C4AB6FDBULL, 0x4F60EEBEB6D6280FULL, 
            0xAC56BE12E43D2DF1ULL, 0xE394C9E30950F3DAULL, 0xCCF1188619050AF8ULL, 0x16B2D0289758FB55ULL, 
            0x251CFF00BAEEEF00ULL, 0x1AD11B2F9207981DULL, 0xD477C661D1985E01ULL, 0xEB06F17959A80D9CULL, 
            0xFAF7B279AED8EADFULL, 0x383B3BD6DA4F122FULL, 0xD936B80B2DF90DFCULL, 0xB6E85E192BAF55D1ULL, 
            0xFA01E846CDD8ECBCULL, 0x98AF767DB262CF6AULL, 0x845E3CB8D4E74A81ULL, 0x73FA575C8CCF475BULL, 
            0x9F229428838B78B4ULL, 0xF68B82A8EEC396F4ULL, 0xCDF5A7F3346F53BEULL, 0x9CF2F7C2EDCAD111ULL, 
            0x66A243ABFD9C1B71ULL, 0x36AC185632AEC964ULL, 0x5D5F976462ECD7CBULL, 0x62FF3421F348D3BCULL, 
            0x8F1FE39716F195C0ULL, 0x94BEFDF5BA4CAA9FULL, 0x83976F2A3F1C874EULL, 0x99E72B3157EDF311ULL
        }
    },
    {
        {
            0x2A6CFAEEDEB7FB81ULL, 0x3A9C490EE8919EDDULL, 0x003AA3C17962D1C0ULL, 0x343F434545B15C0FULL, 
            0xF503A8E7133BE77AULL, 0x65AAF6C2DA172716ULL, 0x06D91D0E7C0B76A6ULL, 0xEA9269F0413041B2ULL, 
            0x0ECAE8C2335123B8ULL, 0xFDF623E234F639DEULL, 0x0E03AF82F165105CULL, 0xE5745B298953DF9CULL, 
            0x12AC6F816320AB2AULL, 0xBC78049C8FF7A52FULL, 0x97B5CC00BACFB8C6ULL, 0xB7308AC967C4EDA1ULL, 
            0xC6C1C24401108217ULL, 0x2A954E0191987A31ULL, 0xFDB00069BF4D0D87ULL, 0xBF8EA4BF14F4B381ULL, 
            0xC964BFC19FF86921ULL, 0x84F3B1CA3D2AC032ULL, 0xC3BAA43AC240C06CULL, 0x8F7F9F9E6001D42EULL, 
            0xA0440ECAAC64B9FFULL, 0xE204C94BD3EA5BF9ULL, 0xFB1BB7D2CD30ED53ULL, 0x7D9A0EFF829D4F6AULL, 
            0xFEED5EA3A1D116D1ULL, 0xD454A7FB13C806C2ULL, 0x1BB1AF484B083109ULL, 0x875F6725205EF14CULL
        },
        {
            0x717D751F6D790C93ULL, 0x6ADECE0E0CF98B2EULL, 0xCB833EB6F0D65CF8ULL, 0x944204DE98A2DB84ULL, 
            0xCAB528CB042C60E1ULL, 0x01D6F4C3F34ADA70ULL, 0x77E18439F80D73DBULL, 0xDC42EC4AD0EC97EFULL, 
            0x93A52EF8E7F9D59EULL, 0x1DB58F8E8177C570ULL, 0x00C86437E10CCC5FULL, 0xE8E2F0E9D034CD36ULL, 
            0xEA7843923FC7F481ULL, 0x2F4C7FF42B8B26C7ULL, 0x7ED401A896902703ULL, 0xDA14943B96A1BF25ULL, 
            0x9BD7BD97158A63C6ULL, 0x63A81D2112AF31F7ULL, 0x5E7CF6E0F9084A1EULL, 0x30552FC4B9F3EF50ULL, 
            0x5877429D6FA6D07EULL, 0xE8044A9A64D0B7D3ULL, 0x566BA10F5BCAD1C6ULL, 0xE107E5D9A3143704ULL, 
            0x77CD6E664A94A366ULL, 0x52653B2209C5E7A4ULL, 0x24B9740BC789B072ULL, 0x197525F14CFC446DULL, 
            0xDC70E03079F044ECULL, 0x4446CB0C2C0B8909ULL, 0x22268598D4F403E5ULL, 0x04705AFD284926CBULL
        },
        {
            0x597C454F834CE024ULL, 0x11976E3A97E425A4ULL, 0xE6A91A833DFAFEC6ULL, 0x13D75139B8789D59ULL, 
            0x583A0E77C476A1BAULL, 0x4A01CF19A0D164B3ULL, 0xAEF1955F16AFD1D6ULL, 0xDC173B19472EFAACULL, 
            0x7D883704A7718F04ULL, 0xA2C835940CA84D74ULL, 0x21ED5E150E08F706ULL, 0xDB750E11FA63FBFAULL, 
            0xB2C262D697F84E25ULL, 0x0A371CA54D1B42E7ULL, 0xE5CA89AA61999315ULL, 0x1DEE4693818B909EULL, 
            0xA21167002FA3345EULL, 0x0EAD4B6D44A08127ULL, 0x0E855A930D01653AULL, 0x4FE63E3CB9E09AA1ULL, 
            0x41A4BF4538817792ULL, 0x9FA901A959581C49ULL, 0x4105B80C07DCAE50ULL, 0x89BAB684AF8EE650ULL, 
            0xB0C51975EEF347CAULL, 0x860B9EE18862951BULL, 0xDFBFF777BDBA69ECULL, 0xB755EC49859D17FCULL, 
            0x967836828F9CABC5ULL, 0x6AEEB1026815ABEFULL, 0x69C020FD6894FC91ULL, 0xAC19CA7801B5A8A3ULL
        },
        {
            0x02B00803E791405AULL, 0xAC4E86F922ECBD1AULL, 0x42B2B45E31EEFB7BULL, 0x4D648DAD0960181BULL, 
            0x5BB11C56DAAD7ECAULL, 0xBCCAABAAE0722972ULL, 0x498EF8BA80095176ULL, 0xF5F768CC8928F373ULL, 
            0x5D90285DCE445405ULL, 0x0883013D5817DD0EULL, 0x60E8427EE337BDB3ULL, 0xCD36F6F5EB0AC695ULL, 
            0x29ACEFD3D5DC9857ULL, 0xD26A456F4C51F538ULL, 0xC2518C83AF3404B9ULL, 0x9493112289983899ULL, 
            0x3B0E3CC89A963F20ULL, 0x04CA3B37F46365ACULL, 0x8FF7189B91A6BABEULL, 0x8428EE3387E510C0ULL, 
            0xA1A974194822FA18ULL, 0x8CE5B3370DA34FCBULL, 0x2931ACC07556A208ULL, 0xA88E631A4BEEED2FULL, 
            0x060824356AB15784ULL, 0xD33411F11297A10DULL, 0x54146913EBD91723ULL, 0x2A70960872D961B9ULL, 
            0x951EFCF19CD8FE90ULL, 0x8F231E198E824852ULL, 0xB54DF27F01708582ULL, 0xA7274808FBE4C306ULL
        },
        {
            0x94A1FEBB42751A69ULL, 0x94BD4E6EB17CAA1FULL, 0x42F9F692DAB9201FULL, 0xDBE20C6DF702DBE7ULL, 
            0xCE965BA5EFB512FBULL, 0xF005232FF4F6F827ULL, 0x91DD4AA835678710ULL, 0xC3E738E9AD32FBD1ULL, 
            0x2915EC882D122796ULL, 0xB8060A9F839E2BA1ULL, 0xEFD28B0A2F52E4D1ULL, 0x73B50340C27402F5ULL, 
            0x596FB64FE002F687ULL, 0x1AE11022E59FEDEAULL, 0xFFB38878AF731835ULL, 0xE2AB1F3057237F6BULL, 
            0xB735C7FA5B6E0392ULL, 0x9AF146AAB7ACEAFDULL, 0x86A424F044B38E3AULL, 0x98B13007A0391E2FULL, 
            0x90B07603CC21B6BBULL, 0x1BA1DB426C0DEEE3ULL, 0xD438471473A8A5F9ULL, 0x712F4E52A81457ECULL, 
            0xE602D85CB38E35E3ULL, 0x32AF36C6A14C8C99ULL, 0x51BE39545AA3E4DBULL, 0x975BD3E1C8505CB9ULL, 
            0xB97019718284365DULL, 0x872A5F8AEE88FA8AULL, 0xAEB01B96C0503E3CULL, 0x0CEBFCE478AE4F72ULL
        },
        {
            0xCC40D05C8B8C993AULL, 0x4E60B94F233F2F94ULL, 0xD271A710A3E61F63ULL, 0x37032F8AC4F23826ULL, 
            0xEA65379850978F41ULL, 0xC11C7889F112E79CULL, 0xC852FFB7A94139FAULL, 0x99D32641C830D3CBULL, 
            0xCD0A476C618A36D5ULL, 0xAE0CF25E7340E673ULL, 0xD407150180E53E02ULL, 0xB150BDC9D79C5FD3ULL, 
            0xE0172FE7A57D3A38ULL, 0xF7E242CC5DBD04D3ULL, 0x47F210201747EC76ULL, 0x00039BDF89878FBCULL, 
            0x75663428C8D9B2B0ULL, 0xE6A388BCB822658DULL, 0x8C1AFDACDFFB150DULL, 0xEFB68182C727A0EDULL, 
            0xF9EE5AED150A10B0ULL, 0x6B2C61247D1FDD3BULL, 0x94D29895B29A7E50ULL, 0x8286A849472D04EAULL, 
            0x5B16676F7DBB8EABULL, 0xE09F4054F3F7C7FBULL, 0x40E775DC2D16DFB8ULL, 0x21C15C23A374BDABULL, 
            0x4A7BEC0CE1BC62EAULL, 0x79E014F8CDD71810ULL, 0xE6958E3C0D80AA19ULL, 0x55E25819DC9CBC18ULL
        }
    },
    {
        {
            0x7A3DFFC46D12CE95ULL, 0xCAB381D523993886ULL, 0xAF85439FFDBC7E02ULL, 0x78CA57206DFED5FAULL, 
            0xE562C1F1547F5F10ULL, 0x29D0FCE0A4FC4FC7ULL, 0x757D06C8A63ACAABULL, 0xE7D48B7CCA8673E2ULL, 
            0xED66C317C2D8656FULL, 0x9BFFC3EAD97A178CULL, 0xF1D758480F618BA0ULL, 0x955286C1F60EB9A5ULL, 
            0x89CE014B01FB7F04ULL, 0x4DC389F0CF138822ULL, 0x4485B2C1A3847A8FULL, 0x3BE9DF80122DD1AFULL, 
            0xFA5B56BA2CDB538DULL, 0xEDB4783E891C7307ULL, 0x433B1DBEA49DF102ULL, 0x266DA5AABCE6EE61ULL, 
            0x5204D53FF34FB061ULL, 0xFCAE89978D3EF8E7ULL, 0x5117B3134445DC53ULL, 0x6326FE7E1B9B7695ULL, 
            0x7C4ED9EC794ACA7AULL, 0x20F1E8C0D9B3792FULL, 0x7E75332D9AB63FC8ULL, 0x32B1860DE1971A77ULL, 
            0x87473472651076A1ULL, 0xE3C7103E0E0EFE61ULL, 0xB1F103563C887969ULL, 0x4FEB9A1B25F9E5C6ULL
        },
        {
            0x700016279D7A2EA1ULL, 0xD0134011D6BE5861ULL, 0xBEF9373D710B5AAFULL, 0x77CAF36B998DBC7DULL, 
            0x8D53E1564B7B4B9FULL, 0xF82689A26D3CA786ULL, 0xDF158B3E99B00D01ULL, 0x082C7F48375308B3ULL, 
            0x86E699B63B12C3FEULL, 0x95E637BF109FD3E6ULL, 0xDF7AC173E720072DULL, 0x2C00EB75CC0E2568ULL, 
            0xB80DE68EDE7B91B5ULL, 0xE5CA66B52FA2C78AULL, 0xCD8929989C895105ULL, 0xA065320ABFE302F7ULL, 
            0xBEE641D25DDF760BULL, 0x5E288FA75274EAC9ULL, 0x06FAFBB379079D0DULL, 0x9B39286F391DA90BULL, 
            0xA131AFAAD789785FULL, 0x88FF5B1D75754104ULL, 0xB07B879D4148C34BULL, 0x9FBAC63FD831CF9AULL, 
            0xE8EC004AB0111148ULL, 0x1BA5E080F0659D1FULL, 0x0405BA54A2FC3812ULL, 0x4771D6525619ECF9ULL, 
            0xA3F40FC10F69747EULL, 0xE456F1AE018642F4ULL, 0x68EB941FE466963AULL, 0xA92805E0ADACDE55ULL
        },
        {
            0x55EDDA0186E2BF8EULL, 0xA68BEED94A221CD3ULL, 0x6C8B65F44DD41953ULL, 0xEA70C9FE0C9DB84BULL, 
            0x3CC447E8D7A5C9F4ULL, 0xCFCD300D5D92AF49ULL, 0x15699BF663DCA043ULL, 0xCA993316D30029EFULL, 
            0xEAE5D895D883FD0FULL, 0xAB0329CD3E1B8567ULL, 0x42F099D2CD5BBCC6ULL, 0x27DC2E7F56D82DC1ULL, 
            0x9FDC87749E34AD77ULL, 0x6906B883216FF3EEULL, 0x2DF6A730BC409A00ULL, 0x7DFD9A65F37130C3ULL, 
            0xC85BA4DCCB73724DULL, 0x65F560312515345BULL, 0xDE787A9299BFD776ULL, 0x0A5F3AF78B60DB33ULL, 
            0xFB9409B0C7050B62ULL, 0xE4A1366193E6DC02ULL, 0xFE778831B665567BULL, 0x6AC7A126F15874A3ULL, 
            0x509559E9FECF5517ULL, 0xF951A94686B02874ULL, 0x60AAF1500D0697C0ULL, 0xAAD4B64BD7A14CA0ULL, 
            0xC992FF92AC9C64EBULL, 0x9F13D6B754C2E4E6ULL, 0xBA8282263FF8871BULL, 0xD490372F48DEA01AULL
        },
        {
            0x074F9CF89977E406ULL, 0xC504A3912A03892BULL, 0x666F980E0EE8FEBCULL, 0xC647622099597BAEULL, 
            0x00FB1BC54094F99BULL, 0x1A177D175DC61E6DULL, 0x9BDC973DBD98873AULL, 0x141C6FB9DD44240EULL, 
            0x99C3D61C7CAEED7BULL, 0xD8DCF560B00DAA70ULL, 0x824AFC8A56AA83BEULL, 0x6E87EADA419BBBF8ULL, 
            0x39913A6EB8CD62B5ULL, 0x73F54CD35A077EC5ULL, 0x91F457800E70A98DULL, 0x6FBD91759A67D420ULL, 
            0x68B620017A70CD5AULL, 0x58AD5599655BE00DULL, 0xD09385077C902C7EULL, 0x9FB2EE53018016DEULL, 
            0x71AD9EAA48B24F4AULL, 0x7166B24EBF412763ULL, 0x39D070D0B80A19BFULL, 0xE00ACAD4062A78B8ULL, 
            0x213D21F283C0BFE8ULL, 0x6604DA279CAB2048ULL, 0x5ECD21854AA9DA58ULL, 0xB675732DC79BDB9CULL, 
            0xCF71DF6EDB66B086ULL, 0xF4AA7BBD283632CFULL, 0x3E9DBF1DC0D43B3EULL, 0x2A137F6FD257DF20ULL
        },
        {
            0xE370C36083FF6A6EULL, 0xFD189AAC7A4FFDCEULL, 0x25ED846BCF1AFAFDULL, 0x79375FB790269005ULL, 
            0xD657F1C38E36CAC0ULL, 0x7457CEE9DBEDE00BULL, 0x97543B85F134D3BFULL, 0x20145A89DD7A9EAEULL, 
            0xCEE4F4517D01913DULL, 0x2DC930A24B9AD628ULL, 0x2B22E9F261A4F586ULL, 0xEB32044A07B1FD4BULL, 
            0xF6D489968C9F148BULL, 0x1E0FB5B2CC750D90ULL, 0xA9B1570169345DEDULL, 0x671FBDD2CCB58A06ULL, 
            0x9F834C45B9729FB5ULL, 0xEAC240121346F76DULL, 0x29F3302D1E576F9BULL, 0xBA5945CA43D57AD9ULL, 
            0xABC7B60C97874AFCULL, 0x680B66AA9CAC41A0ULL, 0xC4AAB5E8B534B52CULL, 0x591FA9D53E33F247ULL, 
            0xF23C4593399F1059ULL, 0x10F3778FC99A5E8EULL, 0xFC78952AE783FAA9ULL, 0xFD6C7E67D63C3B87ULL, 
            0xBBCD00D3EDFEA19CULL, 0xC93BE9D6F59F1031ULL, 0x0B174527E10BA6AAULL, 0x34FA596EB219796DULL
        },
        {
            0x31C694DF09F6BBF5ULL, 0x56CB4BC2978C7D0DULL, 0x303FA422DD18C987ULL, 0xE6921D79A6442965ULL, 
            0xD616744F4EDBD976ULL, 0x04B4A8234BB9484FULL, 0x31A8ECA6A9AD5F19ULL, 0x82C8C5203121B109ULL, 
            0x3FF8E985FE37CE93ULL, 0xE1C55BBFF1D2695BULL, 0x208C4A277CC75237ULL, 0x43DB9EF0C471EA7EULL, 
            0x2E49A20A924B99DEULL, 0x8D0627BFDE332A95ULL, 0x4700A4B6A8C6C44FULL, 0x58631279DFB343C0ULL, 
            0xF48B5E8DC1191750ULL, 0x188FF6E291C6DE1EULL, 0x8B238AE4BCBFAE74ULL, 0xE4B67908F8155B63ULL, 
            0xDF535F397CC49957ULL, 0x7F1E561B6B500CAEULL, 0x0CE2668DFE4EDCDEULL, 0xFCB3916DDAD91746ULL, 
            0x58CFABA6D7C33301ULL, 0x8046A941DE33D79CULL, 0x3CCC77D4A0D4BD39ULL, 0x3DC8D5BC57E8B9D4ULL, 
            0xC2167A37D84C1FC5ULL, 0x583330D342213D81ULL, 0x20CC11DD092E056CULL, 0x6A21B0D1A831C43AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseDConstants = {
    0xCD062B256C5655FDULL,
    0x66983E7685A959F2ULL,
    0x3045D490B41DF124ULL,
    0xCD062B256C5655FDULL,
    0x66983E7685A959F2ULL,
    0x3045D490B41DF124ULL,
    0x20FBE3A17125F0E2ULL,
    0xAD22E4CCA5487427ULL,
    0xFB,
    0x75,
    0xA8,
    0x88,
    0x6A,
    0x1A,
    0x4C,
    0x99
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseESalts = {
    {
        {
            0xB6DB67E0EE4E6D50ULL, 0xBF36A5BD24EF38B5ULL, 0x504CF4C33B23FE2AULL, 0xC5EA4B55900B412DULL, 
            0x3F2A2A7789C86ED8ULL, 0xE3867EE89FD80A86ULL, 0x757FBBEE9265DD4AULL, 0x1DE973D9DD35553FULL, 
            0x7F24B10A5FEE6F09ULL, 0x141516FED94C30D3ULL, 0x85DA1968E4BBB22EULL, 0x01D06F20895A4FBCULL, 
            0xFEC2B834B1B5D29CULL, 0x7E159AF98AA79498ULL, 0xD0913CDBF4B7BD4EULL, 0xAE41A0225E2B71BBULL, 
            0xC29C9B1E5BCB03F6ULL, 0xF822542652C7CDD6ULL, 0xC5669A8FFB217C24ULL, 0x7FFFD99199D8EEE5ULL, 
            0xD0D6CEDD23036BDFULL, 0xE3486936CA2B4F8DULL, 0x8254F6FD951ED88AULL, 0xE0CBFC2EEDBB3EFFULL, 
            0xB3CD549FDF2E9B33ULL, 0x75A65F297F8983E4ULL, 0xFC687B3DCCEBDB5AULL, 0x5C4ECE42AE73A75DULL, 
            0xE107C97F85785445ULL, 0xEE9C59829E4A5301ULL, 0xD822C3CDD87ABC72ULL, 0x55A3A0F5A111CABDULL
        },
        {
            0x14B4985F0FAF6B19ULL, 0x8512766D7E364AD1ULL, 0xB4C82951F9A496F6ULL, 0x7B7B48C22006554BULL, 
            0x4A7E122695DF375EULL, 0xCD8E7E25654BB9CCULL, 0x5E655E380013E451ULL, 0xB746FA3C5829A9E4ULL, 
            0xC7A302F526F96011ULL, 0xDD5DC7ED503A07F0ULL, 0xF369A6FC41A2D379ULL, 0x7E318D1952717E0AULL, 
            0x97655FAA3FCC593DULL, 0x17A1B0C72256AA6EULL, 0x1C2E426BFE9D3EA1ULL, 0xE4F655436BF5C4ABULL, 
            0x0B8CBDC57FC59C9CULL, 0x4F35C36DE1AA2F3AULL, 0x570076BF7371C922ULL, 0xD5EB5AA0D533023EULL, 
            0xC3ADA35A893D9D29ULL, 0x55FAD0E78B53A9DFULL, 0x42B00A8C8C5C817CULL, 0x52CCEA0E501A7CDBULL, 
            0x81C570BF936FB84AULL, 0x2E0160B5ABA9C544ULL, 0x86B14CE73ED3D13CULL, 0xBF3B735D1AAD7F04ULL, 
            0x09C42BACDF898952ULL, 0x38F7CA9759ABD7DFULL, 0x0E9CD7831FD778C5ULL, 0x2FFB11AC701F6231ULL
        },
        {
            0x3C4F3ED5B2C68A84ULL, 0x77D34FD97D186BD0ULL, 0xBE318C29BA8854CAULL, 0xCCD3CB52B485224EULL, 
            0xF90E9D18714B9FBFULL, 0x4F35073CF006BA78ULL, 0x29E907C2BAB39064ULL, 0x1925DC0F8C76716DULL, 
            0x575DDE5314AA9CE1ULL, 0xC83DD757CAF95569ULL, 0x9E3E1553D28498DAULL, 0x3B1FE17AD8F0C504ULL, 
            0x68E528BAABAE1F87ULL, 0x595F71E3AEE6DEB3ULL, 0xFC5A32DDA16C4F52ULL, 0x3DE478F244B0599CULL, 
            0x9CC943FB55650BCDULL, 0xA1E9FA1006B4E382ULL, 0xA38AEA9C1C887EACULL, 0xADEF81F12734C593ULL, 
            0xD5B4E7E90363EF83ULL, 0x0F452FE6A03346AFULL, 0xB054236F9F87991DULL, 0x8F5C8AFBC89E7E67ULL, 
            0x52FD1146429A7DFAULL, 0x295385AB079DB7BFULL, 0x76428060D305E1AFULL, 0x9B4093F4416A78D1ULL, 
            0x330F80C61CE3A233ULL, 0x721EB73016D02657ULL, 0x41492980D8E72ACBULL, 0xE79CD2A96D12FB1AULL
        },
        {
            0x63EFE8F073399508ULL, 0xFB5B9D03976E10A5ULL, 0x5B0724931E164167ULL, 0xB46D89E6046F3357ULL, 
            0x9BEF5F78DA63D8F1ULL, 0x0D6B8E640CCDCA89ULL, 0x1B2D7B01880650A7ULL, 0xBA69E183F0086B0DULL, 
            0x987340987FACEBA9ULL, 0xBBD092AB2D601187ULL, 0xE5FDF7A818999FDAULL, 0xCB9CC82ECD4A69FEULL, 
            0x71F7A9C6AA31D6C3ULL, 0x23B7A5038DA9454CULL, 0x08291267051BB580ULL, 0x7AD0E1F7AF9CB859ULL, 
            0x7281463262EFCD11ULL, 0x20545208EBABF890ULL, 0x2ECD6A66BD2FCC68ULL, 0x93B002DEF7FB4B98ULL, 
            0x6872FE5BF292B81CULL, 0x29ACB5921C3BE533ULL, 0x72F7BF5207D61A22ULL, 0x46A4CD8AECE3E85FULL, 
            0x2F92713ED63AE647ULL, 0xE63548DAFBDD0651ULL, 0x1BA47CA60EB4B24AULL, 0xAA874C0FE54AE407ULL, 
            0x77AB198947844A87ULL, 0x344AB6F349461E46ULL, 0xEF22A813C2CDCE24ULL, 0xFFA82D16FA3928EDULL
        },
        {
            0x45D3C8477626A8E2ULL, 0x58AE7EF54474EAC4ULL, 0xC8816B364873BABEULL, 0x0D382569FB3FF303ULL, 
            0xE921CF3DC76958C5ULL, 0x896A6BE0D4FE7442ULL, 0x470FB9920972F485ULL, 0x73BED17DA3DDC737ULL, 
            0x4C4DC556DE49F88BULL, 0xA8676AB6D7AAE2ABULL, 0x08220E2E6376635FULL, 0xD278F1216DBAF48AULL, 
            0xBBDCE6D9AE4AD22DULL, 0x9FC3B0BBCC950990ULL, 0xAAE205EDE49CA9BBULL, 0x2832CA41101AAF4DULL, 
            0x2199E4F70A67E925ULL, 0xE6E903438E40B82AULL, 0xF6F94F6092B4B6ECULL, 0x057A50FA424B7ADDULL, 
            0xA4F3C6E8331DE2D8ULL, 0x8197D2D242DD6939ULL, 0xAF9C1813DAAE04B7ULL, 0x330EC468EF9C5D03ULL, 
            0xF3B5DF299FD1B47BULL, 0xB3027FB256F3D669ULL, 0xEF50A0E9D9EEA4CAULL, 0xD0789FB28413FF67ULL, 
            0xC6C9EC3EB852AB45ULL, 0x009A2411869B38ABULL, 0x909E2F4917C81A5BULL, 0xC71BEACB262C3009ULL
        },
        {
            0x2EE9BC7D667E0EE5ULL, 0x4C043E71911A3509ULL, 0x7C7BE1F31ADD71ABULL, 0x8D6753D4D9EBC5EAULL, 
            0xAA4F082C2E95D5CDULL, 0xA48AF77E32750ABDULL, 0xECFAB7CBC2637629ULL, 0x24C0A8B48D4E4B48ULL, 
            0x2A87639D222D22B1ULL, 0xDB404398AD5E070CULL, 0xE6AC88695176969BULL, 0xA82973256E11E425ULL, 
            0x84AE6A0A0FFC4053ULL, 0xA19E5BCDFF57B719ULL, 0xBC13CAF1393371FDULL, 0x154FD8646EE93197ULL, 
            0x3AF058B88E45EC95ULL, 0x8AAE16C547CA40C4ULL, 0x93EFB2253001C393ULL, 0x2F26C4D2624AF3C8ULL, 
            0x93D5251EBBF25AF8ULL, 0x572154ECEA2EF426ULL, 0x5350C8A1098D1144ULL, 0x3DC05060C13E07B2ULL, 
            0xD654EE8BA6834742ULL, 0x2B1BB670BE4C5CEEULL, 0x90C1BE67D24C5A4EULL, 0x3C6E4102950555B7ULL, 
            0x6F561DB8266317B0ULL, 0x56BF0C21F09DDE51ULL, 0xEE147E3E2F7CB780ULL, 0x0C2326B155342F8BULL
        }
    },
    {
        {
            0x0D235C9A5C432038ULL, 0xC630BD6FBB583CEDULL, 0x7F23DB6364AEBF0EULL, 0x82CC78EC01AD420EULL, 
            0x24B1094DA342409FULL, 0xDFBFBB2A01502394ULL, 0x4C8F8C9BB9C2B5F5ULL, 0x07D9F0ADE4082EAFULL, 
            0x238CD054873A46F3ULL, 0x3A70F268E44C6075ULL, 0xC13B0B58AD928191ULL, 0x7BA6A9B925E9729FULL, 
            0xFBE39C9B16A21DDEULL, 0x6E7D7ECB63304D54ULL, 0x285FE0E2013E82F5ULL, 0xC8BA5372415A2156ULL, 
            0x9AEE774ADF88AC09ULL, 0x63D9E31E4B17E8E0ULL, 0x771D23345125F3FFULL, 0x76DC3F6796A7C9C6ULL, 
            0xCCA24CE04275F2AFULL, 0xD0D23CA01B1CE8A6ULL, 0x9AB5E4FC65DD8E5CULL, 0xED98A875EF3921E4ULL, 
            0xAEFE6B604E7484C9ULL, 0xF6FAFA60A5F9405EULL, 0xA467B38E5E15B2F3ULL, 0x992EB2DC56AC259FULL, 
            0x900F8917EAF62E4EULL, 0x79E5A5C5503A7315ULL, 0x373FCBE97CF5FBABULL, 0x8276BD0D66695FABULL
        },
        {
            0xB1F43CD11E066F81ULL, 0x00A238F9A48ABCFBULL, 0x48B1461FF401305AULL, 0x4F34AECD56EFBD80ULL, 
            0x4EB41FEDBF08EF8CULL, 0x63312ADBE1E44F71ULL, 0xBA592C50A6BD1FB6ULL, 0xD73B21E178B17433ULL, 
            0xC8F2FC2FA42BAF59ULL, 0x91420E6C5D228F88ULL, 0x54EB1CCED97645A1ULL, 0xB703334B2C804F6EULL, 
            0xA93B06700FFC8FFBULL, 0x4A38B9955403633AULL, 0x413DE66269B26E6EULL, 0x70C1D9151D7AC141ULL, 
            0xB95B8276C4E3580CULL, 0x4CCD250B88A5BD9DULL, 0x2C9D76A922A4892BULL, 0x0ABB910CE9154B4FULL, 
            0x83978795E5D172F5ULL, 0x12ECDD6B37D1D789ULL, 0x63B0770E15C39C65ULL, 0xF0D73F676A7DFBE2ULL, 
            0x94FC456A16780D94ULL, 0xF50E69F6243EF7A5ULL, 0x36A294094C27BC20ULL, 0x251912D827B59EC3ULL, 
            0xA959224EEA216E4AULL, 0xE030CA52C9D4A19AULL, 0x8A3C5ACA44CCD38CULL, 0xF3FD9EE18F0BA104ULL
        },
        {
            0x9E64896D7D140942ULL, 0xFE844D78616145EAULL, 0x4A49EE3896728A5EULL, 0x6135E4467FBF3F88ULL, 
            0xCA1EC17D1674DD2EULL, 0x3736EAF2539313ADULL, 0x6ECBF63513AA8AF9ULL, 0x9C859A771B565F9CULL, 
            0xB29BC98D2AE7D0EEULL, 0xBB4324D98A3792E9ULL, 0x0A1493DE8D36DF94ULL, 0xD1A2116035F67BDFULL, 
            0xB8274849C328C798ULL, 0x68FE408947B170C6ULL, 0x4B57B1F830BF8478ULL, 0x536FFDECD91FF470ULL, 
            0x4C7D870E308093A0ULL, 0x6F5DD8AFF856CB8EULL, 0xFF9D4AEA13DA62E1ULL, 0xD2448A6339C3DA92ULL, 
            0xA73F4E2DF1C64910ULL, 0xB713101E4F2D9F34ULL, 0xA2F0202DBD66A079ULL, 0xCF36CCC46D436D0FULL, 
            0xF1C61D3EC7F5A79EULL, 0x07AE3528305CAB10ULL, 0xFB02E02463074DBBULL, 0x85B513984AEE5C1CULL, 
            0x15AD0EA75043F75AULL, 0xDFEFD5B03DDD075CULL, 0x1EF62ADECCD5FE05ULL, 0x09BBD5D9899FD4B1ULL
        },
        {
            0xFACF258E7956C0B1ULL, 0xE7EF9CB282DEF4A8ULL, 0x0B364B8D0364E8C0ULL, 0x31D1FA4BBF5BBDD3ULL, 
            0x6A91076E8DF1A846ULL, 0x93E811ECE080E018ULL, 0x4B54F1EAA6A2B607ULL, 0xC624A3FCF6B41160ULL, 
            0xEF6C7ACD13B1ACAFULL, 0x72D64F829E55062BULL, 0x7B4CEA75FFD3D34EULL, 0x81678536F41E603DULL, 
            0xFDCC969E545AEECEULL, 0xD0BB7338F27C4915ULL, 0xB755B83C1C1F534FULL, 0x78270966A0A4A93EULL, 
            0x81A035D81394BBDDULL, 0x43231A6E7698A1F1ULL, 0x69627192887011DEULL, 0x4BE110D659540E17ULL, 
            0x2423A527AD70DDF2ULL, 0x6F0143A97ACCD10DULL, 0x5C3C9E8766F004CFULL, 0x85D6E3AB49924E36ULL, 
            0xB944779FF2E114B6ULL, 0xFF2A2A1860E6E492ULL, 0x3E37D60C20330CECULL, 0x3BFC0575A3223844ULL, 
            0x82E9AA289697D0E1ULL, 0xC238F9213E08952FULL, 0xCE99F26C10A00080ULL, 0x4202DBE650034DE2ULL
        },
        {
            0xFF8FDE5EB0BB338EULL, 0x0E777E32C0E8FF32ULL, 0x3F2A2652C54BA84AULL, 0xE23775DC18936C38ULL, 
            0xBFA42722A6CF0B4DULL, 0x9940375B5BD5565EULL, 0xA25C1C5BF3BBF0CCULL, 0x9316C20A54D2C8A4ULL, 
            0x1535235132F5E0FBULL, 0xCB1DA2FAA874A6A9ULL, 0xF8A76914079A5431ULL, 0x006076A8DB8B0EE5ULL, 
            0x8103E25956A932EDULL, 0x30905E68CD51ACA0ULL, 0x8686D96F613CF988ULL, 0xF3318789AA76C8DEULL, 
            0xB27970D283B8F9A2ULL, 0xC4E3AE08851420E3ULL, 0x5A5154E86C4C8645ULL, 0x010D41B3342EF44AULL, 
            0x83BC625D4FC0FDD0ULL, 0x4C1D8D85EF26D56FULL, 0x982090D332F30569ULL, 0xC01C992B585B2ABAULL, 
            0x09CC4A5E8A2254E3ULL, 0xDDF518DDB8964A28ULL, 0x6C8D209B171B56B9ULL, 0x50129A10B8B63D43ULL, 
            0xF5445516507D83CDULL, 0x93DEA5035487275DULL, 0x4CD947B7BA431985ULL, 0x98988D4AF825DD9BULL
        },
        {
            0x832D44556951DDB0ULL, 0x5AACB29D38A71D4CULL, 0xB448787AF7AB6E07ULL, 0xCDE2D4725ECA3B7BULL, 
            0x8B9837C2B64724C0ULL, 0x39707CAA39C97FDBULL, 0xE30BF1EE633F5B23ULL, 0x6053C4D5FC493AB7ULL, 
            0xA2FA7CF7518F3BC3ULL, 0xF8A5C64B1AF8764BULL, 0xEF0E115895FE3ED4ULL, 0xEB5CB0999198BEABULL, 
            0xDAA1667FD934DDDCULL, 0x0C2F86C44E8C9551ULL, 0x25F7394BE3045563ULL, 0xE1C59BB5B636E3A4ULL, 
            0x81FE452B66FA64CBULL, 0xB8C7EF1E7A8CB530ULL, 0xAE443A55AC583D48ULL, 0x9F1A4AD4D8F034CAULL, 
            0xF5A6C605E119A7E1ULL, 0xD6B832C4BD5AF4CDULL, 0xD3343C5378D76870ULL, 0xF9F2E8BC53B9EC62ULL, 
            0xB9C662ADB383D6FEULL, 0x55C2620419AB900FULL, 0xED81D964FF667B47ULL, 0x9EED76EBBD954E9DULL, 
            0x31ADA538107B9B79ULL, 0xF57E832B6EC80E4AULL, 0x77209A6611EEF19EULL, 0x2B840E2DC1EADBF1ULL
        }
    },
    {
        {
            0x18C49418701E1916ULL, 0x42A5B7823DDF9C71ULL, 0x47F84AB914F6CBC0ULL, 0xF47C80320185B031ULL, 
            0xB4D0B64B68630E30ULL, 0x63B0865D1931EDE4ULL, 0x4EEF706E9E259502ULL, 0xF9454C6F26A5B8ABULL, 
            0x11FC3B48DAAD4989ULL, 0x5AC317FA423ABEF4ULL, 0xCAF3D7BFD178FCAAULL, 0x923AA745B23B58CCULL, 
            0x6D31CA1EE23ED0D7ULL, 0x4ABE38FCC126CC3EULL, 0x897E3BA3CE5C1DCCULL, 0xD139590ED3A8751DULL, 
            0xA0552BE3454EED69ULL, 0xB8CC660C853CD446ULL, 0x242956D828274843ULL, 0x6BEBFFBB0A8EF8C2ULL, 
            0xC56252F2E1A118A4ULL, 0x2A2A54E2986E5743ULL, 0x656D04C9C85E2B89ULL, 0x253309852CA2206DULL, 
            0xB68CEC5B5C0787B8ULL, 0x6172FE68DE58221BULL, 0x4C85A59D03AF5C8AULL, 0x7BFF6AB12B22D021ULL, 
            0x12FA07E21476AF9BULL, 0xD782DC9EE7A996AFULL, 0x26D2E42D6512B69AULL, 0x66E618D5524381BFULL
        },
        {
            0x59A1C7B717BFDD16ULL, 0x0CE2270D32189C70ULL, 0xDE877666C8AB6191ULL, 0x78AE1BA9CE43B221ULL, 
            0x4879D46A528A7585ULL, 0x474DCBC451855BB8ULL, 0x0BE310E0D57D45CDULL, 0x1EA7F85F75298DC8ULL, 
            0xDEF25D41B2AEAAFEULL, 0x5A76EC726196A7B1ULL, 0x8B2F7E5EA1E78B0AULL, 0x7081F96961F95133ULL, 
            0x583B77A60BD3F4B2ULL, 0x82517469BDBD2CAFULL, 0x268E05EA1ABEFB28ULL, 0x2DF760FD4DA78943ULL, 
            0x6046BCA6C7019716ULL, 0xFDD55BA2D4126E25ULL, 0x127D356C18A95E56ULL, 0x76200C9983134E47ULL, 
            0x3AEB038589F65614ULL, 0x32C4B52495A9061FULL, 0x3897E8AF47820874ULL, 0x2FE6F4513766A382ULL, 
            0x73724ED46294715AULL, 0x47001B64511CC5F6ULL, 0x3C61BA09CD1B7CB7ULL, 0x92C9CFA0BE4E4E28ULL, 
            0x009A52E09BECCC44ULL, 0x2E9A8F1CC230D584ULL, 0xD2C3FF6C67A1E3EBULL, 0xD630EB4B51741FFDULL
        },
        {
            0x35DF3682ECB2545AULL, 0x7F1B14F247F81294ULL, 0x6EB4FA5C55685EDBULL, 0x20C6ACDFB7D98BA2ULL, 
            0x459673888AB5672EULL, 0x93B41BBDCA2DAA0DULL, 0x0F264F9F5FA8FAA2ULL, 0xAF8BDC3F64C75264ULL, 
            0x908E070084C48791ULL, 0xF7FDFE89D616888CULL, 0xFFF640A431AD6B85ULL, 0xACACB2A8238F2F81ULL, 
            0x7C98226C4EA640BAULL, 0xFC3340ED2D041768ULL, 0x5DDEDEB050FACC99ULL, 0x0281EE17694B1AEBULL, 
            0x314CCACE77B39E95ULL, 0x088674578D391EAFULL, 0x2405D89275BB3956ULL, 0x204DFB393A0BA21EULL, 
            0xA6003794763E427CULL, 0x94076D55CF4407C7ULL, 0xFD5CF19426D5D3E9ULL, 0x664D427D1D410955ULL, 
            0xECB61284A9410815ULL, 0x97F46EA3B86D7A47ULL, 0x6CC7303077EF22E2ULL, 0xA0EA51486E61E0DBULL, 
            0xDB0ABB093B6EC840ULL, 0xD9DCE48C334F45A1ULL, 0x7136E8198E9441BCULL, 0xAE30BD08D9BDD15FULL
        },
        {
            0x05327FE990FADB5BULL, 0xCF7816935C1051C2ULL, 0x1AF4B9F0C93587CEULL, 0xEF7328F272A3D2F5ULL, 
            0x801B3E62C6D0B9E9ULL, 0x0F1F5908FF86C3D6ULL, 0x3180ABF5B91510C3ULL, 0xDB964E41B9F46BC7ULL, 
            0x883617C64F869117ULL, 0xD198B8B778B7AC84ULL, 0x752C3A24DD7482ABULL, 0x679C6A3176CDD989ULL, 
            0x03A10990E073FE64ULL, 0xABABB013D12B343DULL, 0x22BB92A99E7DC55CULL, 0x17326730F21BA6A4ULL, 
            0xAFDAC7E91B93BF5FULL, 0x2C0638327FA98101ULL, 0x7FB38C41F885FE40ULL, 0x3D1262C7DAFFD4DFULL, 
            0x290754C50D46170BULL, 0xE0985BDA60B8E609ULL, 0x5E62E86C3FBA4A10ULL, 0x6CF6ECDA81E70192ULL, 
            0x4BC9888536E6B6A7ULL, 0x60976E16B77CE7D7ULL, 0x69D6279D6A08C90AULL, 0xE623CE50FF3AE2E6ULL, 
            0xB6266B2C8EFB9958ULL, 0x54883E235746475BULL, 0x52DC31EE4F84086EULL, 0x44BD7C48A4812CCBULL
        },
        {
            0xB623587C6F43A6E9ULL, 0x04BD13A77DCB22C8ULL, 0xBF7D539740EE1DACULL, 0xBCB5F2D414490F1EULL, 
            0x9EA6EFEC8BE604BAULL, 0xC45A00D86FF1D2A6ULL, 0x606F72AFEC77E42DULL, 0x59036926007A93C0ULL, 
            0xC8EAEAC5A7430962ULL, 0x23FC3301B3412261ULL, 0xFB4E0CA741F80E93ULL, 0xBA26E455CFC76F5EULL, 
            0x42596F7CC5EAD737ULL, 0xF76BAC794A537526ULL, 0x0962ADF44BA025E1ULL, 0x2C4124BB7E0C2D07ULL, 
            0xB4805C1C5A6AFCF7ULL, 0xA760756118A15029ULL, 0x049B6EAC51A6BAC9ULL, 0xFFCBFD0C3F78D663ULL, 
            0x8C96A1EBF335A951ULL, 0xB08C462AB47B4D80ULL, 0xC22537F20F011A25ULL, 0x0FD07A00C66851FAULL, 
            0x6EEDD3BC75B74B97ULL, 0xB1DDE2300320B7A5ULL, 0x38A9B916D88A44B3ULL, 0x139D35F05D152F53ULL, 
            0x692F96E8458A5E56ULL, 0x61354A10E541C994ULL, 0x0AC7D0B55D73B5D1ULL, 0x023A76B130A0CA21ULL
        },
        {
            0x97AE517637A516ACULL, 0x14DE162044ED68A3ULL, 0x9EE731354F7B3D8BULL, 0x8CF82684F127DC5CULL, 
            0x81FC81BB379BC285ULL, 0x168B602E3B10A1BFULL, 0xB4FD9FCB251B835CULL, 0x38C923F5A8CDB727ULL, 
            0xFFB134370FA958DBULL, 0xD9B878A2E1B0AEFDULL, 0xA0F2748C0B8D1A0AULL, 0xDD97F16C90264AEBULL, 
            0x879F3032A4DD32ACULL, 0x4BEC00B9C15F5D17ULL, 0x4E1DD29B058BCDD9ULL, 0x40D33149E7037695ULL, 
            0xAA63AA5428E6742CULL, 0xBCF272BE31F80500ULL, 0xA3807EDAEBD54FDCULL, 0x4E216CD4B4ECAE93ULL, 
            0xDB8E6EB3E9FC381AULL, 0xDB5FFD4B0BB8567CULL, 0xAA68C9DC481B3F93ULL, 0x4B078AC42526E934ULL, 
            0xD35FC13785C5B67AULL, 0x0A42FA26D7574E34ULL, 0x4867F8C97D4DC26EULL, 0x439490CEB3CBDEC8ULL, 
            0xE07699FDED63A135ULL, 0xC81AFCF09196E155ULL, 0x97FAE4914AC25313ULL, 0x1CEA6E196E0719D3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseEConstants = {
    0x7F0EF6F97EBAC601ULL,
    0xF091149941318214ULL,
    0x965C444CE307FD89ULL,
    0x7F0EF6F97EBAC601ULL,
    0xF091149941318214ULL,
    0x965C444CE307FD89ULL,
    0xE91C34E64C33D6AAULL,
    0x5D5773E28AED7468ULL,
    0x6E,
    0x5D,
    0x17,
    0x67,
    0xE9,
    0x17,
    0xBD,
    0xDD
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseFSalts = {
    {
        {
            0x0E82444C011E3FACULL, 0x0B3F4A373F1A2898ULL, 0xE1BB50794AC5B7CCULL, 0x7F6BA897DB79EDF9ULL, 
            0x625AF94F7424C111ULL, 0x611B7692DA210DD1ULL, 0xE65CECC8CB2399E1ULL, 0x04A8D28D3492E8C8ULL, 
            0x53481EDF6F01F284ULL, 0xB728F8F317127A42ULL, 0x204536387B56D7C6ULL, 0x2D10FE1295B9A91FULL, 
            0xC948F361A8298EF4ULL, 0x582406A4BBB125FBULL, 0xBD7CE65CCD4B4D84ULL, 0x139145D64ECE94CAULL, 
            0x18460AF7A6B1816EULL, 0xD898D593B682D3DBULL, 0x0BA55F0427335724ULL, 0x034A6FB23D556630ULL, 
            0x564BA8A3E4ED6AECULL, 0x04B21ED658432052ULL, 0x8CD33EEC88843DF7ULL, 0x5232DA5EB380CCDCULL, 
            0xD2106CF96ED85846ULL, 0x4155E7BF660CC4AAULL, 0x145C035A1DA9F9ABULL, 0x877F3F0E49288615ULL, 
            0xF7916F02E5719329ULL, 0xF9E3B36A8928CD8FULL, 0x5D9F90013D34BF53ULL, 0xEA95D2F9D1A0C448ULL
        },
        {
            0xEC22FDA60AF1D619ULL, 0xD8BE86F0933EF64BULL, 0xBD2321ECBF0D66A7ULL, 0x7475F04B2AB4E923ULL, 
            0x53F1A195A458D947ULL, 0xF340E3D42A4F42B8ULL, 0xDE7F2EE1E6FD92AAULL, 0x69648E572D366DBCULL, 
            0x2E93D673C02E716CULL, 0x7E6874A00A44F964ULL, 0x69F6D7738C4DF8F3ULL, 0x6E02B9DC8865834EULL, 
            0xD0160DE4AA6D251FULL, 0xC09A09689F5E3066ULL, 0xDBBC275B7D59E6C1ULL, 0x37A3077A14A3432AULL, 
            0x4D13A803C64CCC7AULL, 0x620BCCBD49DB1204ULL, 0x2FBEA4A980D65FA5ULL, 0xA716CDD2CC8251BAULL, 
            0xDF04A90013731183ULL, 0xD994ED99DEB10F8EULL, 0x92993C47A936108CULL, 0xDB66CFD3C8ABE981ULL, 
            0x13A1CC1643F00F83ULL, 0x94ADDDF21F96DDC6ULL, 0xBECEE33D47328B45ULL, 0xC003659466398187ULL, 
            0x4FD3C94E883E360EULL, 0x9D378D308BF4CB17ULL, 0x699B2C12EA59604BULL, 0x3F53A2AA34079310ULL
        },
        {
            0xD041FE880B6F7242ULL, 0x2ADFD16DF03447CEULL, 0xCA2D010A64104A7DULL, 0xD2B66380C55BB6FDULL, 
            0x80384776821FDB17ULL, 0x1282DA21AEA2CFE0ULL, 0x30BF03341AAC955EULL, 0x9C96FB7217113CB7ULL, 
            0x7664EEE900780EACULL, 0x778CD2D207377CA1ULL, 0x95101B93D53CC27BULL, 0xCC49666189E5FFA9ULL, 
            0x43CEB1077A379139ULL, 0x0DF09D45A1D17453ULL, 0x7F9B5F4288B3789BULL, 0xB17EA85D3C79D0C0ULL, 
            0x0D34690902CA4FF4ULL, 0x461CD9E36C16981EULL, 0x3E10238C0547ED11ULL, 0xB002A317CCA9F42DULL, 
            0xB5E6C8E32AA0D8AFULL, 0xA1BC8FE2576398CBULL, 0x06531B8E2DCF4B3DULL, 0x5B856C2FF006F585ULL, 
            0x0194C2E2E84A9E99ULL, 0x92C4AD6BF98414C8ULL, 0xECE71D6536B32ACBULL, 0xC6F1B357022C67C6ULL, 
            0x73DBF1DFCCDA33E1ULL, 0x4BA14C104D110893ULL, 0x4E94DD6CF5D83512ULL, 0x82111AA1B5B115C1ULL
        },
        {
            0x067D929FF358140AULL, 0x27F7B8B0EEC323A5ULL, 0x0C41457B7198DAB3ULL, 0x88DB0E1B452189B5ULL, 
            0x76605EF932942756ULL, 0xAB6C3CC27BB4D623ULL, 0x8BA31C3C53829B6DULL, 0x975B8390C699D288ULL, 
            0xA94112091DF46766ULL, 0x2391BFB3D21E8775ULL, 0xCBBCCB275EC9B9DFULL, 0x4B97A60C32447360ULL, 
            0x8BE65C84DEC7EB12ULL, 0x814A06467E192C03ULL, 0xA36259473B13E4BDULL, 0xF8DD49FD0934B256ULL, 
            0x01416A08F073ADA2ULL, 0x0CBADAD31F0DAB4AULL, 0x7D4C07BECA879EDFULL, 0x51FDCE4A3BB8AFC5ULL, 
            0x582A0394772144F0ULL, 0xD16B8E112790108FULL, 0x72B873C030CC02F6ULL, 0x0E399098468A3A7EULL, 
            0x2F3CCD9883A06784ULL, 0xC480C52A6BEB254AULL, 0xB80A4418A9EA1078ULL, 0x7B3D081E6799F920ULL, 
            0x848C34612E928D83ULL, 0xC87AFBD9A7117D79ULL, 0x6F6829B71BCE23E1ULL, 0x60418C5C7F680506ULL
        },
        {
            0x80FDD7EA49388688ULL, 0x9D7EC82B105F2E7CULL, 0xF4EF21A65B86B5EEULL, 0x04A568CF2CC28278ULL, 
            0x22207AB389039ECFULL, 0x54A69B538D5BC020ULL, 0x60B7E8A9617146EDULL, 0x3E1D6009385A307DULL, 
            0x8AECC292BD438ACCULL, 0x3C3EAA3951823090ULL, 0xC63B365A2A1A562BULL, 0xA4604B682963CFB3ULL, 
            0xB77ED0C5DF94B2CEULL, 0x211D955ECC1034D2ULL, 0xAF5EB106FCD55B4CULL, 0x407D4AEB78F62CFCULL, 
            0x8513CF7DC68EFD6DULL, 0x6B8941630FD21BDAULL, 0xF8358700F4739860ULL, 0x3960D5A292DAB519ULL, 
            0xEB1080E44AB6198DULL, 0xA493143F1B90C1D6ULL, 0xEEF9B1523ACC1E25ULL, 0x3FEA8507D5154566ULL, 
            0x2D4790F59D1B8EA1ULL, 0x4D6E59D2751554A8ULL, 0xA1768FDFA98B537EULL, 0x79A87BE8091B5AE7ULL, 
            0xC2837777D295587CULL, 0xB193B39C8CB00114ULL, 0xF7262CE829BA0F95ULL, 0x68093FE2947C17A7ULL
        },
        {
            0xEAEEFC5A04AC18DDULL, 0x074DEFBB843D712CULL, 0xE39ACA4121011918ULL, 0x2439C3AD1759502CULL, 
            0xE663A3465D712924ULL, 0x9C9806F2BABA3055ULL, 0x9789D474C4488160ULL, 0x85E221D168DE3943ULL, 
            0xD0EC2D3EB353E91CULL, 0xCE5B070BB92CE36AULL, 0x9A062055533457C4ULL, 0x754AE2DA5D8BCA15ULL, 
            0xAB2CDEB03F4572CDULL, 0x8E6D3E90FFD98B41ULL, 0xC5D403FD32A6CCC4ULL, 0x6445816908C3DA5CULL, 
            0x9873CD493DA690CDULL, 0xE2BFE9E5EB7278E5ULL, 0x6D4C33AB05A04CCCULL, 0x93FFC2D11A0CE160ULL, 
            0x6BB1D251975B76C2ULL, 0x4C6B499CDA0A315DULL, 0x7662535F53269338ULL, 0x70B197E887C3EA52ULL, 
            0xBC88ED6E70120588ULL, 0x2EC042FB4CAE1FDFULL, 0x736F82629A2EA64FULL, 0xD96E96F339EFA86DULL, 
            0x884DEB40DB5B6B45ULL, 0x9A49A74F6A39296DULL, 0xD5FD9600DB36B8FDULL, 0x1DF4235B7A5FC69BULL
        }
    },
    {
        {
            0x93B2194EBEAF56E8ULL, 0x65A0243068ED1D73ULL, 0x53983B7E99C589BFULL, 0x0E98FE6224EB08DFULL, 
            0xC7E7657F5917CBA1ULL, 0x043CE2F930C374A2ULL, 0x173AB09AEB2D7FECULL, 0x5A87639A5CCBED93ULL, 
            0x409B0D38579E816DULL, 0xA67DA396100972B7ULL, 0xD2042A5383143152ULL, 0xF5FA7FEE9D209A61ULL, 
            0xA7B1BFC5A77A2061ULL, 0x7CD230081B657AA1ULL, 0x500B35C762DDE3AAULL, 0xB12305E7F6605A51ULL, 
            0xBBB1518985B178F5ULL, 0x1D0DEEFA1641E0A3ULL, 0xE98EDBE60C6BC1EAULL, 0xC1133C1232369122ULL, 
            0xF562902534089262ULL, 0xA360B95C1689B7F8ULL, 0xA952E10E3FCF97FBULL, 0x9D2CCA44AF6E1668ULL, 
            0x59C9EB9FDCBC158BULL, 0xD068EECDE8329723ULL, 0xE79FFC5156A0284EULL, 0x1146376C14CC8386ULL, 
            0x3E6C5F3F1E66859AULL, 0x36717BAE3A765C0DULL, 0xE68D39166F722562ULL, 0x653B7A46890E4B9BULL
        },
        {
            0xA3D69C5E714A4C93ULL, 0x364BD895600EA5A3ULL, 0xDBA3C5F1F55A9398ULL, 0x9E26A78EDA4CBA7BULL, 
            0x35CCE6CC58FB80C0ULL, 0x86C484AE740FACDCULL, 0xA54D2EA2936CA192ULL, 0x635F4050D9769299ULL, 
            0x92A15E66600EE477ULL, 0x66722B3718363A0AULL, 0x913A2FD532608236ULL, 0x668BFFAD7692AA19ULL, 
            0x4E065F3B79414674ULL, 0x604E23354BCAD97EULL, 0xE6D66A2FA9734C2CULL, 0xF312B6B392458B20ULL, 
            0xC87937093251918CULL, 0x33CFC6B742BF506FULL, 0xAD927C773CCAED95ULL, 0xCC45A0EAD2D3A1D4ULL, 
            0xB438F9EE7FD1C810ULL, 0x005C2C4C5368A561ULL, 0x1AF3516C025EA1CBULL, 0x205B138B8DF50887ULL, 
            0xB1499D22C675DFAEULL, 0x203E34BC1AD139ADULL, 0x1D983C87F4220D4DULL, 0x84AA9612F47077BEULL, 
            0xFB71A038FA81BA93ULL, 0x85BD4AFB4D2BFF5AULL, 0xF51B673DDF9166EEULL, 0x0125B211E6C6825BULL
        },
        {
            0x34B080F995F42380ULL, 0x3559E16377A57023ULL, 0xF49BC73440974262ULL, 0x6A53DD116306B4FFULL, 
            0x2094E04476A3871EULL, 0xBF3B5E82BD78B9DDULL, 0xA860BA222A77C983ULL, 0xEEDF3F63C0E72B61ULL, 
            0x84F47BB2407EDD73ULL, 0xF7B03BE5093C09CBULL, 0x2F6206AB5DD6C404ULL, 0xAF0B813A96F420C6ULL, 
            0x27193EDD211E5796ULL, 0x31F8CC62344864EAULL, 0x2EC77176E5934C44ULL, 0x48D24F98D1DFD565ULL, 
            0xEBB8A4FDB67D01FCULL, 0x77A429E1D754FBCBULL, 0x3219A6D98563D9CBULL, 0x023A966DD3EDC79EULL, 
            0x8A92AC34AA6AC8BEULL, 0xAEB207F8439FED98ULL, 0xE5B10157C8C5B912ULL, 0x20F04946D675044CULL, 
            0x80DA5A3F345C3F75ULL, 0x15522E7EF1888CCCULL, 0x20F076EE4530BB83ULL, 0x4626A0D506C820B4ULL, 
            0xE30AD591B02F9A00ULL, 0x12F9AEBF97823C8CULL, 0xADE7AA432CAB7AA2ULL, 0xA344223F739B70F9ULL
        },
        {
            0x402DBBD11BC228D4ULL, 0x78D30D3030E0AC1BULL, 0x692749CB8B260B90ULL, 0xAA17A44ADAA8CB56ULL, 
            0x4F80EB92354CCF8DULL, 0x3E0B75D0BA3BF855ULL, 0x29828FABFA109496ULL, 0xCAA23DCBBB893498ULL, 
            0x37299334717F9730ULL, 0xEDFCB78939DD0038ULL, 0xD113CA9EC0B19069ULL, 0x1FB15F1B256B72C9ULL, 
            0xF472C96931DE6A2CULL, 0x9EF560D6638C37BCULL, 0x71312836169F4512ULL, 0x6B6098D08678C4EFULL, 
            0x5F15C239966B9E40ULL, 0xF177DD8F578D8511ULL, 0xA33619DD6C4A9426ULL, 0x0CC09D1C32943E56ULL, 
            0x78215533F8C0AA62ULL, 0x6B860C1E461146C1ULL, 0x6568E98AD5D232F1ULL, 0xBFB94A545B51C43CULL, 
            0x588F7BC56FE80C0AULL, 0x32D4D219841E7617ULL, 0xA3686171006000D5ULL, 0x0EF97240A5B563E9ULL, 
            0x12E65BC4DC1CA97FULL, 0x67EAEAD99CA8707EULL, 0xACEF12309B21EDD7ULL, 0x2DD5DF3C330F7ED2ULL
        },
        {
            0x685911D7C597C003ULL, 0xC0FBC2881F7E0830ULL, 0x652EDC47D33788CCULL, 0x5CF2768D6061AE49ULL, 
            0x620E52C39CE7CC84ULL, 0x04D9864F95B60438ULL, 0x63C852C2ECD6EB08ULL, 0x8FD85DDC1A4BAB42ULL, 
            0xC45D909DFD25ED4AULL, 0x4B663DA9CEBD8C3DULL, 0x50FD11B93BDC7C20ULL, 0x8F8EC44A91B10565ULL, 
            0xDE7CD4D9E60658C6ULL, 0x98C1F33383129BE8ULL, 0xD4355F7C3FC13BF9ULL, 0x4E08674212F54BEFULL, 
            0xB4A44FC28E0518D0ULL, 0xC514DB3ED73B3986ULL, 0xA63D8B35C7074CC3ULL, 0x59A623BFE4FC8FDDULL, 
            0x11C1E248E91C1704ULL, 0xF20D61C562104692ULL, 0x9E92BE18B03E69E5ULL, 0x0F0210D550A49C54ULL, 
            0xFA80BDE9774B28D3ULL, 0xEE3EE6DF77FA7077ULL, 0xCA3A08F826461D4BULL, 0x7AE56708DD85AEE5ULL, 
            0x8DED0A6D004AE264ULL, 0x8D2E29F282A846A2ULL, 0x126AA6C478A7EDE6ULL, 0x83DA8E253C0916EAULL
        },
        {
            0x7ECFFABB2D4708CAULL, 0x86FA8B076B90F305ULL, 0x2FF9A18EAF4F104DULL, 0x0B04F6325EAAC394ULL, 
            0x82EA79F2CC32A499ULL, 0x6C5C1C5186C4A406ULL, 0xC7C967A15CE8F8D4ULL, 0x6AA76E2456D0BCA2ULL, 
            0x465681367E0889ACULL, 0x921FFF397E82675EULL, 0xC0673FE1CC30D186ULL, 0x69960A0FE25207B4ULL, 
            0x0B9115B653BB6AE3ULL, 0xE9354DBADB4F3117ULL, 0xE770E6BFFA9701C7ULL, 0x82AE20784F280D14ULL, 
            0x347816991A1C1296ULL, 0xAA7674F6B72200A5ULL, 0x9CB18F6A781DF161ULL, 0x4DE79C44B2DFBD0AULL, 
            0x690A680F09DAC61DULL, 0xD09B6F87C2A5A593ULL, 0xC0C47730F4A6844DULL, 0x20C5F2459B459FF4ULL, 
            0x5A088BCA3A4BD0DAULL, 0x74AC2014C80D98A4ULL, 0x40B5DF0CF40057A9ULL, 0x120D25470E9CCD5BULL, 
            0xD599D815FFBD1518ULL, 0x18D447486AC142D8ULL, 0x19BD45EB5578E401ULL, 0xC7D4E356D519934EULL
        }
    },
    {
        {
            0xC64736BE667446C4ULL, 0xF94CC04BB9CCD72FULL, 0x1C36879CE8C0B2FFULL, 0xC90896B890898254ULL, 
            0x0D9DC6C63CB42B1EULL, 0x6B00F134091415A4ULL, 0x4C3C297CFE9BAA87ULL, 0x4D8019B4B8A1E0C4ULL, 
            0x39BDA24B6A3AC1C9ULL, 0xA379E4B784750DFAULL, 0x7E3DF5A9FDB0BEFAULL, 0xED5BBC3198D60A6EULL, 
            0xA383579661B09D00ULL, 0x0AB1C3A397DE16B8ULL, 0xA9A46C1AAC6C9EB6ULL, 0xA6B4CD920E69F7E5ULL, 
            0xDFAF1E1A7573095DULL, 0x3629B86555E311FFULL, 0x3FE837C58ED8F28CULL, 0xE65AB500BAB5DD8BULL, 
            0xABFD4FA5877348DAULL, 0xFB1538B833D64A86ULL, 0x3A4939D7DE1E253CULL, 0xE880D95D40D39D76ULL, 
            0x5C79FABD55C88554ULL, 0x3D68E09F3AF722F6ULL, 0x0693F781A84156E9ULL, 0x5F63596B69D41FE9ULL, 
            0xF0819A788D88684FULL, 0x8ED5AD1953466685ULL, 0xC310D9ECFB5A2625ULL, 0x825DCCA424D26BBAULL
        },
        {
            0x52AB1D633BD19A1CULL, 0x74FBCAE0B635D5DAULL, 0x1FDB9FD5866D1C9FULL, 0x11121AEA909D9B63ULL, 
            0x052DFB7DEA84316DULL, 0x0A73AF7DB5FC5C1FULL, 0x7FE6C549B12D35B4ULL, 0x33D146234023C917ULL, 
            0x6DEDD64DD515B950ULL, 0x17526C92C7CA80B9ULL, 0x53600F923008317BULL, 0x420DB5B9FAA8477BULL, 
            0x238D9D3AB6892BFFULL, 0x4C733ECC3DB4BA9AULL, 0xA17482DBC5CE31BAULL, 0x25A9FC94E17AFD12ULL, 
            0x6EB9699F19E49B67ULL, 0xEAD1FE352088C97AULL, 0x1487F9EEB1E4B0B2ULL, 0xDD81CFC60FB42A7DULL, 
            0x71A3F1B39A502B7AULL, 0x1ABEDFE2C7757ECDULL, 0x247DE1DA894AA7D0ULL, 0xBB30154E1688E04CULL, 
            0x73E459511E00341BULL, 0xE2FAB9F2C1B3E6E2ULL, 0xFE7D7B2E38008613ULL, 0xB12E60494B9FC77FULL, 
            0xC43309C53C0CDAFDULL, 0x4DCCE9C749A64031ULL, 0x15403F21B8F7E5E7ULL, 0xE2E22ABD1C13319BULL
        },
        {
            0xA49FD8C8816E4F0FULL, 0x8E71C0F9E1FD5AF3ULL, 0x9140C52EE11C4120ULL, 0x9B3EC7C87E0AD7BAULL, 
            0x09156A2D49349C56ULL, 0xAA310C46BD25C6D6ULL, 0x0D46E7229CCDE68CULL, 0x57394010E29662F6ULL, 
            0xB17D4AC81217D26FULL, 0xBB530BC108C9834BULL, 0x7C4F8A375E952455ULL, 0x47CC9C07C612CBAFULL, 
            0x3E0E7B3BCA60BE6CULL, 0xE49D24EBCAB16D02ULL, 0xED58A658BD3138D9ULL, 0x582868D089B730EFULL, 
            0xC51C750EFFD220D6ULL, 0x0744F9D8F3DCD269ULL, 0x126A4F6497DEF0E7ULL, 0xC8A1A4FED8B958E5ULL, 
            0xA9E34C15575DFFDDULL, 0x79AEB52E64C357E6ULL, 0xBD768A67F9234616ULL, 0x1828A3AB13D65AEEULL, 
            0xE54E5B5981A241FCULL, 0xD77FE13A751806FEULL, 0x454082D7488EE753ULL, 0x61DC38B265052B5EULL, 
            0x2AE2733B434AF35DULL, 0x5CAA12630BDEF33CULL, 0x5650E86F5C75E5C5ULL, 0xD8D53839BAA0DA2CULL
        },
        {
            0x32AE125E2640181FULL, 0x11B2265E63DEB80FULL, 0x045A3FE0E4BAD614ULL, 0x69449EA8E3A86D2EULL, 
            0x202B650084ACEA28ULL, 0x622AD559AA82E168ULL, 0x67FFB3B3C06AAA4FULL, 0x28ABDB8368B31F78ULL, 
            0xBAD1FBC838DAA5CEULL, 0x498F1F16AB37B59FULL, 0xBF1E82C13B23F4D4ULL, 0x9EDB11F4457BA1D5ULL, 
            0x8ADAA025D1AB69F7ULL, 0x08884DD41E566260ULL, 0xCA10ADA3E00C1AECULL, 0x4AA597A800E16B29ULL, 
            0x6F46F36EAD71853FULL, 0x473DFE9A3C0E04B0ULL, 0x5D8ED9DAB806057EULL, 0x1C32466F036FFDD3ULL, 
            0x373FB4C4F8365660ULL, 0xB913F66123D25087ULL, 0xD100B1881A41A20CULL, 0xDBBEF9D377813492ULL, 
            0x4218CAA5944BBB4FULL, 0x7AA45890AB2A659DULL, 0x9CA753BE2F2ABAF7ULL, 0x1E369E49AE943DD2ULL, 
            0xC84C821F96FAB9E7ULL, 0x64E91EBA5BF2EB71ULL, 0x5D6D95D83591D35FULL, 0xC45AABD726CF2405ULL
        },
        {
            0x5041C4C27E0D6A96ULL, 0x8F4696ACC723271AULL, 0x59E0EAC360A0C5DDULL, 0x28FEEFB5DD0BE014ULL, 
            0xD227F4E04B804257ULL, 0xD1C944FDE4119A3BULL, 0x0AA803DBEA79514CULL, 0x0E829128C69BC160ULL, 
            0x609E45BA72C04CEBULL, 0x915ACEF422321AC4ULL, 0x1BF818CFDDD3B4BEULL, 0x748E4551409D4302ULL, 
            0xF6BA75B256CF3C81ULL, 0xD9941697008FE0A7ULL, 0xDF1C70882D1FAEB0ULL, 0x2EDBE7360462BA54ULL, 
            0x4DD202BFE057E6F3ULL, 0xCEA1BA31F90E362BULL, 0x76C392745F322585ULL, 0xB181DC93D5954108ULL, 
            0x7467421E28D3FC13ULL, 0x76AD75110EE6403CULL, 0x10F823774835B070ULL, 0xC0D51E6C4299E9AEULL, 
            0xF79D27AD35F3326CULL, 0x65BEC5F750A730CDULL, 0x725200C89A9E3930ULL, 0x22B8E93CF29F7BF2ULL, 
            0xFB597FA12F5CD400ULL, 0x2EC154E33CDDD5B0ULL, 0x92043C95CA0CB36AULL, 0xDBA45E65C30E63D2ULL
        },
        {
            0xFAD566A3A2AB19DFULL, 0x9A069D3CC350293FULL, 0xE533B4267CDFF9AAULL, 0x81758F497AC458A6ULL, 
            0x94B52C2EEE68B90EULL, 0xD41C494E4631B380ULL, 0x8207CC87364495E6ULL, 0x75CDA5B66A15E7FEULL, 
            0xAB1A8D3761791505ULL, 0x52B2D4401E28D2B2ULL, 0xF33451078FAB7DFEULL, 0xACF4E897741E0828ULL, 
            0x0D762FFD3E85ABD1ULL, 0xE7EB8B245BE47FE3ULL, 0xD06928270D935C53ULL, 0x41B5AD31B921EE62ULL, 
            0xFA7D95A21FD350C8ULL, 0xD3E3F58E57E2A8F4ULL, 0x832F95B78E0FCCA0ULL, 0x218814DDCA38CCE5ULL, 
            0xA267ADD37C16F042ULL, 0xE61FF348BB916023ULL, 0x81A39867CE404199ULL, 0xBDBD152DA929D2DDULL, 
            0xBAE8025799155508ULL, 0x7810B86E172A825BULL, 0xB33A1E4CADCDB73BULL, 0xE654EE244F5DF2D4ULL, 
            0x2216C31D2462862BULL, 0xBCD7083656F50DE9ULL, 0x178D46DC5A97A1FAULL, 0x55869267ED758BAFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseFConstants = {
    0x0C0563400E2AFA55ULL,
    0x163BD32D0C0F9A1EULL,
    0xA44E327B468C90C1ULL,
    0x0C0563400E2AFA55ULL,
    0x163BD32D0C0F9A1EULL,
    0xA44E327B468C90C1ULL,
    0x103D6C449F573892ULL,
    0x7B805F831338CEDAULL,
    0xDA,
    0x83,
    0x48,
    0x93,
    0x44,
    0x8D,
    0x30,
    0x31
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseGSalts = {
    {
        {
            0x3C13BB3D566F669FULL, 0xBA7EA21CDC90C63EULL, 0x475B892AF963855FULL, 0xD5748EC67A8E82D3ULL, 
            0xD9D2A33AC1AD0F2EULL, 0xE02FD1E29018593AULL, 0x986C194C5F57BA99ULL, 0x3ECA3C1094199B9AULL, 
            0x0E6A26CD5758A888ULL, 0x3A145715DA30C6E2ULL, 0xAACAF6D412F42A44ULL, 0x54230EABDC85E38BULL, 
            0x72791807954291FEULL, 0x71495DB1B7D74254ULL, 0x0CB53D4BFC59D0ADULL, 0xA02CC4749F768B3BULL, 
            0xADCF9C20DA8BEAEFULL, 0x9067D155B523C744ULL, 0xEEE531EAA2A12024ULL, 0x3FA0F54CED680568ULL, 
            0x9D5C96132109C25CULL, 0x0CC9F54E023A6491ULL, 0x38E3A14BC940914EULL, 0x523CC493579C9F01ULL, 
            0x66CD4DDABE566931ULL, 0xE614D9949B65F5D3ULL, 0xEFFE1FD3AD2291EDULL, 0x5CF19B0029038999ULL, 
            0xDE3FC321B7E70A5EULL, 0x093B9BEB276884C6ULL, 0xC3D65E0CE9C39C53ULL, 0x0576D51721404E36ULL
        },
        {
            0x4387533C96CFB9FBULL, 0xEBD8B7729AF2AC3DULL, 0xB9F4850636142283ULL, 0x966AF097FBCC96F1ULL, 
            0xC8E205237B03932AULL, 0xB860BBD39751051FULL, 0xAD9F8FA871346F86ULL, 0xB31581BB5926E32DULL, 
            0x5DAE40E9ED9DB745ULL, 0x52F1920ED553C8D8ULL, 0x60CAC655F3CF0B0CULL, 0x3E42C42E5E83A899ULL, 
            0xEA05211797C3092EULL, 0xE7917C52C8E74F18ULL, 0x568A2182965044F6ULL, 0xAD662EBB1A8BD668ULL, 
            0xA182FAED2B0CB5F7ULL, 0xE2D7A6C101D42212ULL, 0x92A500EFF526649BULL, 0x04B02F03EE8D78B9ULL, 
            0x9BE4ACE88D49532FULL, 0x6175B2B10E18082CULL, 0xA1296AC1A249C5E4ULL, 0xD9B584F7EF985533ULL, 
            0x327A2E4A5E2FC4D8ULL, 0x80C4590B57C0FBB8ULL, 0xCFAB2DFACE6A4EA5ULL, 0xB8A07910C0CC47CEULL, 
            0x5691E05975398004ULL, 0xC4B8DD213E50E758ULL, 0x6789F0627BCBE6E0ULL, 0xF12304BACB41BEAAULL
        },
        {
            0x2DB821989757C1ECULL, 0x8CFD1B17BCFBDA74ULL, 0x51B5FAC25CC36661ULL, 0x143B1D0051F7E6F8ULL, 
            0x8544532236AF1B1BULL, 0x76C6F1D3B0234D67ULL, 0xB1C69BD1C0B96B0BULL, 0xFB2BD61B98745A68ULL, 
            0xE39C73372713411CULL, 0x508B367326EEA71BULL, 0x4AED14E8FC193B9FULL, 0x941D5D679C5C998CULL, 
            0xDFA131304E538385ULL, 0x46DD967EE1D61268ULL, 0x3116B302D4BA5A55ULL, 0x35B4B9232D1DB94FULL, 
            0x6052BDC2F1A48B52ULL, 0x9DBCE5A0E61D2C1FULL, 0xFFAC2280EB65EB29ULL, 0x6E6DD1AD5BAB7AF1ULL, 
            0x8EFAEBA8182FBC6DULL, 0x6912BB5F77EEB17CULL, 0x768A6FBA284EB0D0ULL, 0xAE1659A196D1AAAAULL, 
            0x1AD740DFF7A2DEC6ULL, 0x46C523A26FD863D6ULL, 0x2F205CE6DAF7BA88ULL, 0xA5F3DFA45FEAE11CULL, 
            0xB364C9C21A407A17ULL, 0x91A3DC208460E383ULL, 0x4491833B256FB8A2ULL, 0x70F171DB6AF77D0EULL
        },
        {
            0x546A4329A9A24297ULL, 0x3DA263F85C495C71ULL, 0x7F19405CE1213094ULL, 0xAE5B65228A26DB16ULL, 
            0x9945A3EF074DA58CULL, 0xBD8229A1F53DE686ULL, 0x127C1EA1291C0D58ULL, 0xB378A21BBB10F5ACULL, 
            0x834E0ECD7F81AC34ULL, 0xC753C54461498AB2ULL, 0xDAFF5D2BEBAF57CDULL, 0x3CBC6FCA7D8DD0ACULL, 
            0x412A6BBB66C0159CULL, 0xEFF4AD079FDE62E8ULL, 0x94EC3F8FE0E63058ULL, 0x4BF27A1E7AD11707ULL, 
            0x86E0FCD8E7606E6DULL, 0x5DB9070B51D94ACEULL, 0x94A234D76343F365ULL, 0xF97730287D033E95ULL, 
            0xD5A417ADFB44FFDAULL, 0x02C453DE80A7952AULL, 0xBB30F91B99767289ULL, 0x884D105649999390ULL, 
            0x0191825BB6A7471BULL, 0x6D6EEA0845D8FAC1ULL, 0xC0E82CCC001F7B79ULL, 0xE1CD12A08435D360ULL, 
            0xBD064E7D65EE1919ULL, 0xFFFA9109C2901CF8ULL, 0x60E64A1C22DF5E89ULL, 0xA0E12950DD822D09ULL
        },
        {
            0x912B2B90FA49B434ULL, 0xFEC69A728C3C9F5BULL, 0x643ECD8F5EB21933ULL, 0x22E68BF6988BFEA9ULL, 
            0x772E8B6CA6CE89ADULL, 0x922F5ADA44321E21ULL, 0x620C292228C55526ULL, 0x96DFD3DA30F6ABE4ULL, 
            0x341D4BFAF8568F97ULL, 0x4C718BCD2FDD449AULL, 0x5FE7D76AC38B6BEDULL, 0x8EED3E7288AB5F89ULL, 
            0xDEA2D3701E9CEED1ULL, 0xCD9A80581F975267ULL, 0x44221FE69592FF6DULL, 0x351AC29806F3524BULL, 
            0xD58102BFBCC99740ULL, 0x2CAEA5BD96FBA6F1ULL, 0x1C5E0BBF8EA30A75ULL, 0x9699BAADB4E5EB05ULL, 
            0x46B9B182F149381EULL, 0xF09860BEB74A2EDDULL, 0x9145CF154C621B70ULL, 0xB2F9D33C131F2599ULL, 
            0x27801F2F8473FD46ULL, 0x5CF47A5D4700EE86ULL, 0xFBA18FE045A627CDULL, 0x6C1059DA1843236DULL, 
            0xBC5429836CCED906ULL, 0xD7ECBBF596C43C7DULL, 0xB7D3F1A2790410ABULL, 0x440E2F9770795DB9ULL
        },
        {
            0xDF491898D46A57E5ULL, 0x3411D80C4F5A7F6DULL, 0x5C7768D3FF456752ULL, 0xBEA8AE489FDBA8F7ULL, 
            0xE69BC760D7CED6FCULL, 0x964BA7676C01F8D1ULL, 0x39B6F9082F75B970ULL, 0x463496CD0D13E8F6ULL, 
            0x92B39010C5D2B9FCULL, 0x7CD5ADB87048BBDAULL, 0x00591CC36EB1FCAAULL, 0x6F9CD91D9EA6CA17ULL, 
            0x31061C6417FDC658ULL, 0x87610480019633B6ULL, 0x5A4D4BB8A3B9A93DULL, 0x7C2F303967E12B5CULL, 
            0x91F3DD45DA99332BULL, 0x757F3DB57BA9D563ULL, 0xD7EC6921D9AAF1CAULL, 0x57F6ED82FE6290FBULL, 
            0x63EC70CCDEDC12D5ULL, 0x3944E7C8D4E91566ULL, 0x06300324FCBF3DA5ULL, 0x007EB8BB25881D3DULL, 
            0xDDF6119598862CA9ULL, 0xD21E8FBC90062828ULL, 0x98FC1F94AC6D0818ULL, 0xAF4E4DEE264548C3ULL, 
            0x22400C49FEA59FD4ULL, 0x9B78AE3E22DF5E71ULL, 0xD18A4337E45273C5ULL, 0xF65EDA2F0A97934CULL
        }
    },
    {
        {
            0x29104EAA101240E7ULL, 0xBE58853F036956FEULL, 0xA8420E0F42C1BB94ULL, 0x8F543D0DAF60E77EULL, 
            0x5E7943914E43F1BAULL, 0x44511B44EBF844E9ULL, 0x46B43D6BDDE1CAC2ULL, 0xF66FAD5D7FAD4928ULL, 
            0xB9E389E567D23418ULL, 0x8FEF25C1A2CAE267ULL, 0x91DFE95ADD72B5BEULL, 0x6C376F54F6B69B13ULL, 
            0xC4F301FDE77165ECULL, 0xDF25A27652DDBCDAULL, 0xE760B022C9364DAFULL, 0x68120DDB68C0EB9AULL, 
            0xB845F983AAEA184AULL, 0xE133C602104611FBULL, 0x13E49AF25F11DB18ULL, 0xC175E3355B775992ULL, 
            0x6FF5A53983265816ULL, 0x1430D1A407620849ULL, 0x9F523144F693FC49ULL, 0x0EC3591FB4FC8F4EULL, 
            0xEBD3A84FBF9AD3D1ULL, 0xB2F1BD8598C1730CULL, 0xBB809674B6B63A8EULL, 0x81702B34CA393EE1ULL, 
            0x27820A32BE419353ULL, 0xC3E6B869C6D94BE2ULL, 0x27CD1D1745BB48A2ULL, 0xDEE512B3DDDAE7CCULL
        },
        {
            0xB2B7F4A414AA3DD4ULL, 0x42A1C0490D518EA9ULL, 0x303F453AC3B3F7ACULL, 0x5150DDCF48673193ULL, 
            0xB63851BE739D577FULL, 0x661BD9A60C35D2AEULL, 0x7D46FAC3698BCF77ULL, 0xF8F78F4954B6D2E0ULL, 
            0xED1BACFA208B64B4ULL, 0xC4F4C79B87D92F96ULL, 0x98BCF2E4048AC765ULL, 0x6E96A01599FA49EAULL, 
            0xDB6D0FD2F875677CULL, 0x69D31DAB598B34CAULL, 0x7A7D67F917684FB8ULL, 0x70FFCFD2639FE195ULL, 
            0x7E16B1128E8D376EULL, 0x303FF03D6EAC7865ULL, 0x3D49ABFBBA0B4420ULL, 0x1A858A4FC78E0AACULL, 
            0x389FC22B30073111ULL, 0x6259C3987A2FBD1EULL, 0x3B37CF5E032795BEULL, 0xBF8C3204358DBE29ULL, 
            0xAF429AC661FB71EEULL, 0x61181AD130680A6CULL, 0x100D303FE8C4BAE6ULL, 0x699420DD1CCE1E69ULL, 
            0x6BDF46DB4779D15BULL, 0xD944F453320AED89ULL, 0xAD2E392D0C1CA75DULL, 0x08EDAAB79EE95A9FULL
        },
        {
            0x6859C2F4C11FBB2AULL, 0x44B2909A57398A53ULL, 0x61F628A7585A66EBULL, 0x5E1E0221D0DCB187ULL, 
            0xC0482869CAB6F348ULL, 0xE4D37021DF3F1B3CULL, 0xF92A3508850CD2B8ULL, 0x7E9DEC553E019FC2ULL, 
            0xD350A1852162C513ULL, 0x80D2FB36527C7400ULL, 0xE83BA245E7D5BC82ULL, 0x5D7B85C58E69C5D5ULL, 
            0x525011FF0632CB79ULL, 0x991BCEE1BAFE1473ULL, 0x6A968DB2078320CAULL, 0x294923157AB81E5FULL, 
            0xFCEE19C23A680A51ULL, 0xB01A2A7CA0B0E5B5ULL, 0x1527072F6D16AD3FULL, 0xC0DCE86D50A776E1ULL, 
            0xF4264111CBD5A8C5ULL, 0xFE3AF72E8575EF3FULL, 0x7CCB277FD73BCA03ULL, 0x51F6B4EE1159995AULL, 
            0xD9CA207A7E5DBC61ULL, 0x1E78DFF3C925FE5BULL, 0x57EA9B3B64F670AEULL, 0x06444C52FE303392ULL, 
            0x1104855534E04C69ULL, 0xCC5AC1BBD551D112ULL, 0xE3ED4603AB6FA55CULL, 0x4D673567CA3BF7B6ULL
        },
        {
            0xEB9EA51D2309DFE9ULL, 0xE14AF3C78F9EA8D7ULL, 0x1282F8D10C390C26ULL, 0x97E268FF63AF04FFULL, 
            0x3D7059FDAB42E72AULL, 0xEA3A11B8541C52E8ULL, 0x1D9BCBC1DB2B9BF9ULL, 0xE8A7CD8E664432D8ULL, 
            0xF4BEBD9B0410ABBBULL, 0xA8650696874293BCULL, 0xC2A93A3FDF243321ULL, 0x0562BF147F47765EULL, 
            0x7D6FCE57491A5C56ULL, 0x88827A0A522B5732ULL, 0xF24857A44DBEF9F4ULL, 0xBA921F510D471FA8ULL, 
            0xEE8FC0612344D26DULL, 0x13F6C6943545EC35ULL, 0x561088628B3BB46BULL, 0x715C0E734D550843ULL, 
            0xC240B3E927C9B053ULL, 0x07486D95061F12ECULL, 0xF878F86640AD7304ULL, 0xA74BA48146E8768AULL, 
            0x8470ED49A22B2663ULL, 0xCEF08F596B1EED1BULL, 0x629B7D8F131F28D8ULL, 0x0830CA20901EBC47ULL, 
            0x90561F23F9452C4FULL, 0xBE11D6834870F065ULL, 0xF594D0D91E6F5A6AULL, 0xE32C02366BD41E03ULL
        },
        {
            0x6D4822715D2F3D7BULL, 0x9755ADE6C80BCF34ULL, 0x1CD36BB8A85935CEULL, 0xAD3E18F25D3BA1C9ULL, 
            0x64DAC23FB769498FULL, 0x9285761AA0A415D6ULL, 0xE9CADA849CC7F2A6ULL, 0xFB22A5E4BEC63366ULL, 
            0xA1447CCCAC4A4FCEULL, 0x7CBD83CA3F6055F6ULL, 0x739DFADB9CE1EA52ULL, 0xB8B97E46963DDCFCULL, 
            0x796719B1E54EE91DULL, 0x50F7292346F3AE95ULL, 0x4B1F0D2D3CC6A3C0ULL, 0x45BDCE14B019A0EAULL, 
            0x237E53AF5746313FULL, 0x38EF8842C240A2A8ULL, 0xF26FD3D46D0684A5ULL, 0x991E484B654FA54BULL, 
            0x6F83E50D586ED823ULL, 0xBCFA4D4FD91DFE14ULL, 0xE6E6C48678B008C1ULL, 0xAF3DD496E60DA396ULL, 
            0x3AD5E8C63FE321EAULL, 0x81EAEE4AFC521AB8ULL, 0x1184C5137A59E836ULL, 0xC051AF95C94FD271ULL, 
            0x5A2DE5AF294E35A0ULL, 0xD00BB77B4E88E840ULL, 0xC28B7780C17FA866ULL, 0x0EA371D090A42F78ULL
        },
        {
            0xD7AFCB6DDB0D5DA2ULL, 0x39BC42FF44BA6C83ULL, 0x7AA2D3900B13C7C7ULL, 0x6CEAAC40A09736CCULL, 
            0x525A1D78B116E237ULL, 0xCF13CDF7AD95958CULL, 0xD351375637C8E853ULL, 0x86953C24297916F8ULL, 
            0x74660DA4C02E8290ULL, 0x2DE293124839BCDDULL, 0x84FB4D7F432C53AEULL, 0xF979515F3F62B225ULL, 
            0x7B1E549CD435052EULL, 0x721ACA9962E41E51ULL, 0x1F31D8E60A347A22ULL, 0x1295D44C85499658ULL, 
            0x78E49B26015D76B6ULL, 0x61A0B3E91C21B542ULL, 0x92A8E79761B0F854ULL, 0x37845D45066695A1ULL, 
            0x33B24ACE1AA02FC7ULL, 0xD624B09D17D46B30ULL, 0x8316115ECC41B7D3ULL, 0xBFBF883FC7957A9AULL, 
            0x0100A597BF1E58DBULL, 0x12E8B0C058D0AB3DULL, 0x6B09257452FEC179ULL, 0x25C4B7545249325BULL, 
            0x6D313CB76FC6B621ULL, 0x46C3D1CC0CABBC4BULL, 0xEE28EE55DC6F957CULL, 0xE61DC07B70EE54CCULL
        }
    },
    {
        {
            0x83C65BF2A255C6F9ULL, 0x650F8B07F210188DULL, 0xFCA49A9A1E4FEB72ULL, 0x32FC770D2B41704CULL, 
            0xDE86CF71594965C8ULL, 0x10C1DB4F63A487E0ULL, 0x2618F80D025DEE8DULL, 0x908B49D811F785BCULL, 
            0x8325A25D98AA220DULL, 0x5A00A17AA447336BULL, 0x100F91869B96AC50ULL, 0x6D45842836FB2CE8ULL, 
            0x4A3AEFAD3D29AA48ULL, 0x6C45AB16349D7DC8ULL, 0x7FC4852C242C2734ULL, 0x35D216E8B783CDFAULL, 
            0x46409109CF7EAA24ULL, 0x32074B2BAA9F42F7ULL, 0xC9C33F9F5D45F6CBULL, 0x2B57513DE880CCDAULL, 
            0x384A5B63F2045B1BULL, 0xF5F66E6E15B822BBULL, 0x354A1F9EF807D9CAULL, 0x305EAFC209A732E7ULL, 
            0xD5A0EB8D007BC5B2ULL, 0x2BCFFAB453BF0BFDULL, 0x270974658BEE5F9CULL, 0x95A1432315F65465ULL, 
            0x327CE96437D1813AULL, 0x7310103C3DDBDCCAULL, 0xA77882BD4D49BDD4ULL, 0x618748EB43FA8C63ULL
        },
        {
            0xFFD8EC989B30EABEULL, 0x3A740DE2E3411260ULL, 0xBE9C5819E074A971ULL, 0x25BB85B9CCB7A9CBULL, 
            0xA03EBBAF0602099EULL, 0x40412E6E72D77308ULL, 0x81EEFCD21B7795CAULL, 0x245B169A1289D3D4ULL, 
            0x021D3C29D14D6E77ULL, 0x85FC297616663C1FULL, 0xCAF2AE40B3FD8BCFULL, 0xE4F52A3C199DAE4FULL, 
            0x543BA9492A0D0CC4ULL, 0x04359A984D2D15BAULL, 0x7F8A37F586419C44ULL, 0xEEFDFF23F90193A4ULL, 
            0x1D8EFDB3EB3FDD54ULL, 0x0903AC71F090B598ULL, 0x077D2160984B55CFULL, 0x699C09ED42EF7731ULL, 
            0x9A5A152AEBDC079CULL, 0x27830C3CB303A17FULL, 0xEE5E697A9DD67889ULL, 0x1D34DBF4C765991EULL, 
            0xA150C8061091066FULL, 0xB2EB49A7D1BC711CULL, 0x1C1A2FA8BD93B033ULL, 0x2A2A9493C76DA81BULL, 
            0xE6A03DD43E83AA42ULL, 0xA2C0640B8E72BB9EULL, 0x0C5CD250B0A8D29CULL, 0xC0F08A42BA652625ULL
        },
        {
            0x7915B33EFD00B456ULL, 0xED150935C629EA49ULL, 0xE53EFCCBC2DFA3E7ULL, 0xEAC3B578B979E214ULL, 
            0xDE4569B1E24B07FDULL, 0x1C79106676F2AF38ULL, 0xCFBD3D545D4B6CE7ULL, 0x8655D0221CC039BEULL, 
            0xF7D10A1C6DBB59A8ULL, 0x8EC0B61DC0A45981ULL, 0xD6835D6672837C5AULL, 0xA81DBA480CB6BC1AULL, 
            0xB90D51D7E3182E65ULL, 0xD61950E7FFC3CBF8ULL, 0xF66D371EF1B1C0D5ULL, 0x69D8EBD68B6104A9ULL, 
            0xCC834C18B100D49AULL, 0x5BF6FBB7E8BB6168ULL, 0x34E1247D4A413190ULL, 0x0EBF60CDA7AC96D1ULL, 
            0xBDF909DBC9EAF5CDULL, 0x21DBEFFDBC0F1BB4ULL, 0xCB7A7FA7EC159184ULL, 0xAC5418041431A93CULL, 
            0x68545003B2BAA1E5ULL, 0x560CD72F8AED69F8ULL, 0x103FBD70C75DE523ULL, 0xDB87B9B430109043ULL, 
            0x0774ABE006E46096ULL, 0x7386D9BFE93CBEF1ULL, 0xC35843E615FE3056ULL, 0xEA7168282EF7EE4DULL
        },
        {
            0xA6EBF7A35516D2D5ULL, 0x39CD1566F3068999ULL, 0x92B548E2083CC83DULL, 0x067E91C10108BCA2ULL, 
            0x2A30B32FC6011FDDULL, 0xCE21C03737E01A51ULL, 0xCADB1FF4B78CBF64ULL, 0x14E26FBDB3A8583AULL, 
            0xFC885E7ACD0A3B28ULL, 0xBD2D0746CC3F9377ULL, 0x0ABD04FC60BACE88ULL, 0x27BA8B1A32ED841CULL, 
            0x2953ABBC3256FD5FULL, 0x776AC5517D746A8CULL, 0x0AE0D04DFBA586F2ULL, 0xE2B124657579E3FEULL, 
            0x0AAE52FFD875287BULL, 0xF071623DBCD2DD2CULL, 0x1C36E1883D4C9F3EULL, 0x68AA3EC013EAD513ULL, 
            0x35E3FA6771850F1EULL, 0x80C50DFA8E19E5CAULL, 0x276CCC854C09667DULL, 0x089EA609CE4D0B6DULL, 
            0xD5B941E3BE087501ULL, 0x85D0B3361E15ABB4ULL, 0x310CC4C18986CAB5ULL, 0xC66D7FAEFC31CEFBULL, 
            0x5CDD689D77C58F46ULL, 0x67F8FFA8A933867BULL, 0x03A7117B939CA1DAULL, 0x164D69C864D96533ULL
        },
        {
            0xAB29851A5BFF149CULL, 0xD203DAE4683E53BCULL, 0xE6B3A2469F296392ULL, 0xC652339314304099ULL, 
            0x15CBE1319C6B564AULL, 0x324618BE48DBAFBDULL, 0x72F5DAC45074EC63ULL, 0x0E285E8B76F3CCA1ULL, 
            0x55300EAA6B982F2DULL, 0xC36515BAD64F24D4ULL, 0x1CDE1BC78566AD85ULL, 0x445ED2FA93411AC5ULL, 
            0xF42A9B40E177120EULL, 0x476F60A4D91D4A10ULL, 0x928686371A26E4B1ULL, 0xAC752B6F4CF9DC44ULL, 
            0x7012DC6C6E40AC9CULL, 0xC500F6FF2E46E02BULL, 0x400C7C77E5A5B733ULL, 0xB212B6A31525E1C7ULL, 
            0x7F778D231712F229ULL, 0xE1CDC4867ECBE7F4ULL, 0x22E26DE44BF00729ULL, 0x617B30F65722DF40ULL, 
            0xE2DBB2FB46D88A10ULL, 0x1120021469BAC3BEULL, 0xA743DA6E506B92D2ULL, 0x253F98E6882D29B2ULL, 
            0x750F86468ECFCE2CULL, 0x32189533BF4D8DCFULL, 0xD7D3276B5E07E9B7ULL, 0x1204D092C1CCA96FULL
        },
        {
            0xAFC2321EC54FAE64ULL, 0xA3D4958EE73BC43CULL, 0xC2E3A6BED2F14177ULL, 0xCDEBEDA31C7625B4ULL, 
            0xFEA43320C4B1CDB8ULL, 0x53496D786AE43FA9ULL, 0x6CC0C3060ACEC087ULL, 0xA3CFA9CDA25D4D94ULL, 
            0x58B67A708FA894A6ULL, 0x9E5A39C244F03B91ULL, 0xB50960ADCCF31CC7ULL, 0x810D90A00B2AA43CULL, 
            0xA0157F102D1D450AULL, 0x8CF02BF60896010BULL, 0x71CE6AEFC52965DAULL, 0xD4EE5AE36E3D8ABEULL, 
            0xE0935B6C74C5A111ULL, 0xDDFAED3E7FF365CDULL, 0x76E23D6046E6E198ULL, 0xFC05E2ACB5762714ULL, 
            0xC7704AB00DDED477ULL, 0xDF0842A0ABDF4DD9ULL, 0x16036B3A38EFF20BULL, 0x4C0E25E9FFE55253ULL, 
            0x32503895907A471BULL, 0x090C0CF469CD48C6ULL, 0x8BE672F05A0EE69BULL, 0xB985637CBC49ECDDULL, 
            0x99A64B0DEBEEDCA2ULL, 0xE704C8D0287B12EFULL, 0xA4204B8E1350CFBEULL, 0xF1CE0F57C254C493ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseGConstants = {
    0x13866EC3E5848030ULL,
    0xEB35792910FDF507ULL,
    0x672CAB12CFF85D17ULL,
    0x13866EC3E5848030ULL,
    0xEB35792910FDF507ULL,
    0x672CAB12CFF85D17ULL,
    0x570071C17F118C2EULL,
    0x414848CCACADA932ULL,
    0x05,
    0x8A,
    0x7C,
    0xA2,
    0xFD,
    0x98,
    0x50,
    0x4C
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseHSalts = {
    {
        {
            0x85C658141399BD80ULL, 0x4608105539A84C6CULL, 0x1B4C8BCE55F0B515ULL, 0xD561148AFA8A28A1ULL, 
            0xFD0D4D38BEC3FD0EULL, 0x362B63EAC271D115ULL, 0x1F5FE2B85F5F23C2ULL, 0xBA8E88879DA1FFD8ULL, 
            0xF0C7397AE35E5EEEULL, 0xE45087F57EEEB777ULL, 0xE3A1B1B8F925E0F3ULL, 0xD0791D9DB36C05E4ULL, 
            0x7780B7F5404CF58CULL, 0x444F236636C30445ULL, 0x48D4886B5B7425E4ULL, 0xEE6364B2339D4B29ULL, 
            0x5E56BF7247B7B9E6ULL, 0xCE123CF30DB719F4ULL, 0x2726DC9CC833F96BULL, 0xD2E11B6DC0B1B57CULL, 
            0x9EA0A1CF9E8A096FULL, 0xA845BB12FEC80042ULL, 0xB3D0BAD130A7EBB5ULL, 0x40287BDBEBA8652AULL, 
            0x0D12DC08FE427FC8ULL, 0xF15F2AF72A678B12ULL, 0x3A3096385FB51702ULL, 0x62117A48D20BD10DULL, 
            0xF18DD90118BD5B29ULL, 0x6F4135AED23DB322ULL, 0x6A04E2349EDF46BEULL, 0x59953CF0CB7C4DDAULL
        },
        {
            0x19D02048CCBB952CULL, 0x64B423DD5CD5B4D9ULL, 0x713E7C591C4DC6D7ULL, 0x5AF7B701F06BA3D7ULL, 
            0x2BDA1FC6FCB8BA9FULL, 0xE0D8E3EA54CC64AEULL, 0x5EF709A4D1F5F82CULL, 0xFE93BC3ED51CF51BULL, 
            0xCE8EC92B6C3077DEULL, 0x321E8865F7F4F9B5ULL, 0xC58537DC8360B222ULL, 0x75FCC9B16F7A7FE4ULL, 
            0xBE149B9B5CA15F2EULL, 0xADFC96315DD40F6EULL, 0xD33F0DA2AE7680BBULL, 0x77F40F75936B48DCULL, 
            0x800F0F0684A25759ULL, 0xE0596DE59E0353CCULL, 0x7C3F6B928313634FULL, 0xFF60C3CB36302106ULL, 
            0x6ADFCCA7243B0F41ULL, 0x5686137F01DED492ULL, 0x056213B5FFD480A8ULL, 0x6EA4F3853B46AC39ULL, 
            0xF1907A6031C34ABDULL, 0x4B867DF75241A4D4ULL, 0x2FC221B1EB7FAA31ULL, 0x835417F761FCA8B1ULL, 
            0x408804F6D94E159FULL, 0x5D0E276E765585AFULL, 0x22F867CAADE72359ULL, 0xBB18016CCD4A52C1ULL
        },
        {
            0x542A86E3E7864DBBULL, 0xD738573F6008C038ULL, 0xC0FB45964FF23BF2ULL, 0x830B782CF82E0C7FULL, 
            0xE3562448C6F7306BULL, 0x3B3D7FE3D291E703ULL, 0x604382D973361A20ULL, 0x96D045755DC4C7E3ULL, 
            0xB5C8504C2BE6EB7FULL, 0x9A48D245AA1ECB5FULL, 0x3988BF5AA36C649BULL, 0x2ED2CF47F167BA58ULL, 
            0xB17D2F1A68237A2CULL, 0xF9CD9150CD0D47C5ULL, 0x5740CC33B8122624ULL, 0x2F6990560BE8ACD8ULL, 
            0xA5CC2D3EB9BE9E87ULL, 0x5B97AD4DCA32E818ULL, 0x5E9D34FF6F5C77F2ULL, 0x3FF8AE3073431B88ULL, 
            0x419226B907BA84E1ULL, 0x64B4117A75CFF567ULL, 0xC279BEFA7C77C26DULL, 0xE9D8C20BEB05D4A0ULL, 
            0x2EF8FB78586E19F3ULL, 0xD3AAF0A52CE09C81ULL, 0xC6AEEEECAD7B89DDULL, 0x0D1AD699B2B823B2ULL, 
            0x8CD910A6A0F1C25EULL, 0x0E835701C05F7CC1ULL, 0xE128A9E8A7040BEAULL, 0x324A1B3F5373949DULL
        },
        {
            0x1F53D9163F1C23F5ULL, 0xF746D3627E059B36ULL, 0x4C043DDDB1D82D93ULL, 0x8687C37F1F9C5586ULL, 
            0x32024E6EF2AC27E9ULL, 0x5A2106344D5BBDE5ULL, 0x8597E8EE7788F282ULL, 0x937D7E22998836EEULL, 
            0x63F38452BE12562EULL, 0xC2B173411144F490ULL, 0x4C1D857A60E4669CULL, 0x9841285DF89D9376ULL, 
            0x961795E42FFB204CULL, 0x7F8C90102835F309ULL, 0xA7917204973675CAULL, 0x4F23390D521C31E6ULL, 
            0xD2AF2868671CC3F6ULL, 0x6E024ABB5FF18F97ULL, 0xF4B60E871E334DFCULL, 0x97EF33F75232E7A2ULL, 
            0x40B4B9184C4630DDULL, 0xF135569E9CE69492ULL, 0x83D8B7990A41AF2BULL, 0x785F51C1A8112299ULL, 
            0x786C9DD438CB6F1DULL, 0x0008182B5A135CD9ULL, 0xEBBA370FBC93F6AEULL, 0x5570C8B5D24B906EULL, 
            0xA0397B7DF97A8BE8ULL, 0x4543F179ED48BCE9ULL, 0x9B56DC3CD24F0275ULL, 0x3E6B7C851930F4FAULL
        },
        {
            0x65F44049D5928FC6ULL, 0xBD124AEF5EE806CBULL, 0xDC85BA664757235AULL, 0xE6CED45450269ED1ULL, 
            0xB717ABD672B3F47FULL, 0xDD976C5BF21A019FULL, 0x2934D3CFF14D4DF7ULL, 0x770BC4ACC5895637ULL, 
            0x45F2C9B5A1AC4022ULL, 0x2C42DF3270FE37BBULL, 0xB85C32D1CEB273D0ULL, 0xC214C16EACD4BFADULL, 
            0xC2A55ECAB4FA2B49ULL, 0x003E0618FF841A6CULL, 0x82B5407E50EFB421ULL, 0xD7A92D8209774B19ULL, 
            0x5031E0347B9D1E0AULL, 0xA59AFC5DA5405360ULL, 0xB6AD249299135320ULL, 0xFE7763FC3AE512CBULL, 
            0x4D0E946651D56571ULL, 0x0A3354043EC9495EULL, 0xBA6BDCFF57F0CA11ULL, 0x6987F537F0B22DD6ULL, 
            0xD063128ED45065C5ULL, 0x6DA6FD4A818E700FULL, 0xBE11E86CC66EA139ULL, 0x98C7C3064E9311F2ULL, 
            0x419B5D971CC365A8ULL, 0x0CBE866F24437331ULL, 0x5AF35F1E8765681DULL, 0xE938BEB99BA28D98ULL
        },
        {
            0x8B6AF0495126A6B0ULL, 0xE1F8620470E6A931ULL, 0x840D99C2580EC885ULL, 0x2CA1BFFD05F6570FULL, 
            0x90CFC51B86948F12ULL, 0xC6E634379F55E70CULL, 0xEC27238B02358826ULL, 0xF8C6BCF4D0E83A28ULL, 
            0x8E1C615394D65CE3ULL, 0xB8500B502D23D9E4ULL, 0xB8D21E78B6BD7B15ULL, 0x6AAB27A8F257350AULL, 
            0x775901484AC112D5ULL, 0xFD1DB817391BA245ULL, 0x37F0852CAC0684BEULL, 0xFB883CE74DCCC607ULL, 
            0xFB6F5FA7324678A3ULL, 0x0BB5D35D342EDB9DULL, 0x7F5B83C681AEAE02ULL, 0x0E4047ED865315ACULL, 
            0xCA5278F93356CD3FULL, 0x1E55F06D8EC4E093ULL, 0xE8E8115CF3E1247BULL, 0x5AC2220894DF36B8ULL, 
            0x144D1169C37CF0DBULL, 0x3898ABD0249B055AULL, 0xCB1D6E863C03A255ULL, 0x3879B44B520205A6ULL, 
            0xB1F2B8222814A724ULL, 0xECB3AEEF3E2BA03EULL, 0x684C053623C86097ULL, 0x622880DC729DCD97ULL
        }
    },
    {
        {
            0x83287A21B10EA85FULL, 0xEF5539C559BE2E95ULL, 0xCB51F08151842D18ULL, 0x37DEF905951230FFULL, 
            0xF7D23F90AB29122FULL, 0xA03230BFFD3E0BF9ULL, 0x1C8BF103956890AFULL, 0x6919EBFE7EC49788ULL, 
            0x0FF9D7E1F2263FB9ULL, 0x0A0AD3F6EC27C801ULL, 0xAF06D863B5695AD7ULL, 0x5349B6F2D81E8024ULL, 
            0xDF57AE276AA3ACEBULL, 0x5BA8E605B6EFF20EULL, 0xA964723F52453642ULL, 0x86A804B1207BE60BULL, 
            0x3C2552B0CCB84A86ULL, 0x6D7B922CE1C5465AULL, 0x387AE8FE8A288408ULL, 0xFDB3653F7D85FD6AULL, 
            0xEFFF41FDF4179B09ULL, 0xC9838BF2579960E3ULL, 0x48084EB638726DE3ULL, 0xE1B4CE856CAFA4BEULL, 
            0x6EEF71BD5026C64FULL, 0x72722FAA6A6BCF96ULL, 0x473A398CA4CB811EULL, 0xE115FAB65550631BULL, 
            0x6F183B217501A0E7ULL, 0x722325A6968CA611ULL, 0xB6403D29881C3F2AULL, 0x31E3CFD29C853F7BULL
        },
        {
            0x9F9DBD6E67F5BC6FULL, 0x13B0166734FA376DULL, 0x7C03D193B85E652EULL, 0x2E21B601B89EFCDBULL, 
            0x435DE8BFBEAAC5C1ULL, 0x61C076BB7E3300E6ULL, 0x67B229417F592BEEULL, 0xD9F4153AC3B0109BULL, 
            0x08ED6FE09AE031B2ULL, 0x85325F9331D75C42ULL, 0xDE1F2544E1D4B635ULL, 0x18B3E7E8051DA79FULL, 
            0xA6DE0AF8CCD4809DULL, 0x8714443DE86B570CULL, 0xE98290C617662959ULL, 0x6D9C5EFDBF4AD051ULL, 
            0xEF378BDA1202D279ULL, 0x3CFEEEEDE1A0CF35ULL, 0x864387D43E275ED3ULL, 0x7DA408B309FC92C2ULL, 
            0xACBFBA8DD219D005ULL, 0x429178EBC6D9E0F8ULL, 0x5ABEFFE60021A269ULL, 0x34DE4BE193BCDF60ULL, 
            0x15C6AA77AF80E8B3ULL, 0xD3C648336C8A909FULL, 0xE76F7C4F98A692C5ULL, 0x3F849ABF0BAC730CULL, 
            0x3C41C57A00C1D8DAULL, 0x96682DAAD14290A3ULL, 0xE95BF3430B82456FULL, 0x996A4075B8348AFCULL
        },
        {
            0x8576D78AD0CF0581ULL, 0xE861D2116583F670ULL, 0x3E711B9E5E997CACULL, 0x3F3768311C90161DULL, 
            0xF8669FF45E0160DEULL, 0x51F6CF4B9E7252FCULL, 0xF16E007BCC8EDE11ULL, 0x3202B12CD818459DULL, 
            0x2AFFBCC0783326C6ULL, 0x49238B730707F06BULL, 0x0C4B3A69346EB359ULL, 0x61483D5CCF901775ULL, 
            0x2852A6CDDAC9ED1DULL, 0x5447E1D9D29099B1ULL, 0xEE03C0B866431531ULL, 0xB2AC777BF73230ADULL, 
            0x73531AE2A8C9CDCDULL, 0x0268496406CD8040ULL, 0x6EEF234A45C874B2ULL, 0xD299E3379678DB28ULL, 
            0x22BBE8DF9359D0E8ULL, 0xD2661484D39B6946ULL, 0xDFCAC77207328CBAULL, 0xD3F4DB7B37988B15ULL, 
            0x51E0499FB77E661DULL, 0x4A5E8650D479F434ULL, 0x45EEC7BCF0CDB5FCULL, 0x8E8CA8948B00F5C7ULL, 
            0x6BA6E34509B33F46ULL, 0xD56FC9B11B7CED8CULL, 0xE29E52211714B1A1ULL, 0x06985D3D32253D17ULL
        },
        {
            0x387F8535C54E0C5CULL, 0x8C91422288298A57ULL, 0x78F85EA96B1FB67EULL, 0x35B0FD0854825E83ULL, 
            0x93A8E65A4E00153CULL, 0x12440F2A8492A3D6ULL, 0x8C877250D263F949ULL, 0xE068A34E8874AE47ULL, 
            0x46ECA6DF11450087ULL, 0x388C4BA4A2B8DB87ULL, 0x8B4E0A2194EF9857ULL, 0x51F9D48F06F50EC4ULL, 
            0xB41CB7B2DAF153E8ULL, 0xDB508EDFA2197A01ULL, 0xF575C4360335A79DULL, 0xA2E2E004BCD2AE73ULL, 
            0xA056C54F89F7214CULL, 0x06DE53BCA46AFFF4ULL, 0x05CBF53EA426689EULL, 0x1C5F1EAA9F8FC790ULL, 
            0x9F51F8EE29C19652ULL, 0xD3681BED4C04140AULL, 0x2E5FF0CF1E0DC3FDULL, 0xB9C34180D40F3F25ULL, 
            0xB6867B07A9C9B7B3ULL, 0xE537841583521845ULL, 0x320587F911A19558ULL, 0x2B53A07BE27867F5ULL, 
            0xC79520973AB7931FULL, 0x13ABB130FE335E45ULL, 0x8FBEBB5EF0B16114ULL, 0xC3F9FCC5E8ED82D2ULL
        },
        {
            0x6477E47D852544F0ULL, 0x634063AE4748005AULL, 0x5A288ADE86D71063ULL, 0x87E2481227E4526DULL, 
            0x25BB1F5674FB5AE6ULL, 0x0F9108C3913B5C5AULL, 0xBAB9581CCB04A602ULL, 0xE76697551859C938ULL, 
            0xD6AA7526C4929F02ULL, 0xA64D77E23CF89DE7ULL, 0x54BAF397EE8F30C3ULL, 0x1742DBFF1D5D5874ULL, 
            0x6E7AF817086434C9ULL, 0xA21F03DCC1E61673ULL, 0x2546C5080BD55329ULL, 0xE7B782D3897F7883ULL, 
            0x1D0A1732240AB368ULL, 0x96FFF679BE4F5F69ULL, 0xEF615743750BE376ULL, 0x5CB9C687CB9E8300ULL, 
            0x406CBA774E5E576BULL, 0xF882FEE702CFFF9EULL, 0xB853EE34116DFF1CULL, 0x81FFF0A18E33CD78ULL, 
            0xF4CC842BEA9727AAULL, 0x7AB1D2A646D69203ULL, 0xE2EEE385597A1C17ULL, 0x43F2CAAC7997C4A2ULL, 
            0xD0C8477209EA89B2ULL, 0x3E285447D22015FFULL, 0xF7565670797CB9A3ULL, 0x21E9BB2E50D9E6E9ULL
        },
        {
            0x34CED2413632763EULL, 0x58D8BC3356AB06CCULL, 0x1E3C04CF02A0E404ULL, 0x1BE4EF41F89932DDULL, 
            0x52272432ED4558C1ULL, 0x052A912D9E14A40EULL, 0x2195DC6366518826ULL, 0x2F37926CA0BD5283ULL, 
            0xE7B57D87BB4A6686ULL, 0x87328B9D3359CAA7ULL, 0x78F965E2FE6DCFE7ULL, 0xCA87E5CABC8ED0DEULL, 
            0x0D5E30EDF6D09F2EULL, 0xD8DB72DC6E91C387ULL, 0x99950D6FFD63FD71ULL, 0xB02E9F0C69EC1056ULL, 
            0x59042CBB9CD18569ULL, 0x0CC70EC6F18A1078ULL, 0x78C94C963E109EDFULL, 0xF8274BCB21806CA9ULL, 
            0x2FF49905389715F6ULL, 0x796351C8D83428B3ULL, 0x11EE9B59012A9C33ULL, 0x446E5B8AD4C6B9E4ULL, 
            0xB73E27AD1F23F7DAULL, 0x9C3809C8766CED53ULL, 0x5CFC103E2455A691ULL, 0x8F733B8B91868BEEULL, 
            0xD30D4A9E75AC6104ULL, 0xF7BFDC3ABD23FE78ULL, 0xDCD5CD522EEBCA54ULL, 0xEA26C8A441C7C6F4ULL
        }
    },
    {
        {
            0x8FFF3205832C6E6EULL, 0x572C6BEE0B4A7894ULL, 0xD42ABB07327BD597ULL, 0xA0430C94972D1A52ULL, 
            0x00FB0B4454FBF464ULL, 0xDFE83EC0DF5BEF64ULL, 0xF215478E5E873316ULL, 0x8B643B948207A100ULL, 
            0x665B55AD747401DCULL, 0xCDEA6F5840F56047ULL, 0x7C81C528DDF65D11ULL, 0xF1AA6149DAF84C1FULL, 
            0x3B326AFE7A40B58AULL, 0xD254CCB657A091C6ULL, 0xCD93E6B64E428939ULL, 0x790DB0489649E415ULL, 
            0x2FABDC6DFF32C459ULL, 0xEF17D977669CC668ULL, 0x97808347A0B549DBULL, 0xC99A86A0EC853A91ULL, 
            0x9F585B827E8C1B69ULL, 0x31F0D1858F02FC5AULL, 0x6D0488A2BDBA3074ULL, 0x9AAD3D5B6DE998E9ULL, 
            0x9A5D81B46E552A1CULL, 0x00486C9581FC22C3ULL, 0xFDE464763AFB8C9CULL, 0xE49141C585ECD946ULL, 
            0x0D4B3D921BF1F9EDULL, 0x0B8A80FA24CA2D00ULL, 0xA028F64639C3F989ULL, 0x8F1F6918CE7AFFD6ULL
        },
        {
            0x23D5D2AC1B0F3F4BULL, 0xC7EF0F4381E019F0ULL, 0xD35B1E5A282593AFULL, 0xF1206EBDD3FD1259ULL, 
            0xC8519FE117EB7192ULL, 0x854393181AC41F34ULL, 0xE8BC897D415E3FB3ULL, 0x18FBB027A1D26DFCULL, 
            0xA8F20E3481AED5EBULL, 0x703AA5C5714C7428ULL, 0x97E3620C6D814CD9ULL, 0x53316A50C7A0F2EAULL, 
            0xA8D42328F48FFE8CULL, 0x7060E8B874C2AD83ULL, 0x4C61575BF9420352ULL, 0xE8204224AC45CFDDULL, 
            0x4BEA6F491833AC1AULL, 0x95A486E0AC0C7825ULL, 0x8DAAC0769739224EULL, 0x388196A2FDBA2CC4ULL, 
            0x3650BAA5CF8EBC11ULL, 0x939790DFD2D742CBULL, 0xC1D8FDE7ADD1539FULL, 0x4F2B075E083F71DBULL, 
            0x6A65EA0D778AB6C6ULL, 0x1023A5F567B41795ULL, 0xB1DA1DD66278FC9DULL, 0x56D6812D46793FF5ULL, 
            0x88428396257F9121ULL, 0x78E96CC142237730ULL, 0xC882366E098E7E68ULL, 0x2D66890367FAB2B2ULL
        },
        {
            0xC0519BEE430DFEDCULL, 0xFB3FDB7FCC33F9A7ULL, 0x30BCFBAB5C103D81ULL, 0xE03CF24BE0D8E4EDULL, 
            0xB6235AFE71644511ULL, 0x0CEECBB243C4D0FEULL, 0xF5FA3E352C451F4EULL, 0xFF7EF25E3EE5CA27ULL, 
            0x3B9220D76DC83FC2ULL, 0x76766D3BB37542B1ULL, 0x1300C7F2A0481600ULL, 0x58D333FA8A1EA77DULL, 
            0xB4A0A459B8EE0525ULL, 0xEC253D0785B7FBE9ULL, 0x0E044949FF152D10ULL, 0xBFF7FC43575B732DULL, 
            0xED9D4F2BB3B61172ULL, 0x6E999178B059419EULL, 0xE9C0E11BC3510D8EULL, 0x991542D27820620AULL, 
            0xCBAB8E5642EA9794ULL, 0x2705176938A2B145ULL, 0xEAF2A9DBF5C15AE5ULL, 0xA7628260160D136AULL, 
            0xCF4C2E1DCB1E77CEULL, 0x8D95D734CEEF0F39ULL, 0xE29727AAF8F4BF81ULL, 0x57451EC0ACCF8C20ULL, 
            0x6B77CC386B12AC9CULL, 0x40FDECBDC9272AC5ULL, 0xC463106D6B39A080ULL, 0x5BCEF7EFA0138AD7ULL
        },
        {
            0x12CAECA8170F4175ULL, 0xDA84C9C5169480F8ULL, 0x3F3B85867D2E9742ULL, 0x21DD51ED59898BAFULL, 
            0x0F83862DFB0AE517ULL, 0x6CBFA05E2E93645DULL, 0x5A409DC07311DEC5ULL, 0x91CD1655F382B52AULL, 
            0x1F4F6D88C04F855BULL, 0x259C83736C59A005ULL, 0x0929AB48EF91E58FULL, 0xD8F9E1C582A6E95CULL, 
            0x91F9E0D3224334B9ULL, 0x7309F880128AAD66ULL, 0x91108EA7EA3DF19CULL, 0x4CC299BA047A9161ULL, 
            0x71C9DB2A027F7253ULL, 0xEE7DE6251FA04EE6ULL, 0xD3BEDC1A39845723ULL, 0xC79D12590380403EULL, 
            0xCCFC09E353A2CB35ULL, 0x42985507EC830054ULL, 0x73851E7F939B2CA4ULL, 0xF4004177CCEC9BC7ULL, 
            0x3100A3D392ECAC3CULL, 0x4E84A2AB381A5961ULL, 0x31DE7684C2C26499ULL, 0x00A3120F13D6C437ULL, 
            0xECD847E2AD0B06ADULL, 0x209395457C252A63ULL, 0x57C4B6763F62FD84ULL, 0x733875791D2A03DAULL
        },
        {
            0x3F92CC54A8F2CF8EULL, 0xC37EC29A38B60FCAULL, 0x700116C21FEFDD51ULL, 0x169A5E48DE75FD7EULL, 
            0xC66E3250CF83CCE7ULL, 0xBE376F5D9DAA3FA4ULL, 0x9D202F1C99B1D9DAULL, 0x0121FFB301D5CCD1ULL, 
            0x9E28F5A2EFF138AAULL, 0x56546780FB04B025ULL, 0x5AC984E23CA35458ULL, 0xDCAB45BF5A291452ULL, 
            0x9BA41B55C5E45CE3ULL, 0xF7D84F0D5167146AULL, 0x552C99AFB46D9A16ULL, 0x34FAD0C49D08A654ULL, 
            0x4FA5C6BCAEAD3BC5ULL, 0x0820F10C254D5255ULL, 0xC33C8F9AAE4F97D4ULL, 0x6FC831C87139581EULL, 
            0x87BACCE252A3E633ULL, 0x8762B78B987B4C12ULL, 0xE4B5E21BD43EBA9CULL, 0xF0D88F8731A8607DULL, 
            0x309698D755D8ED63ULL, 0xF7DBB7A3396F6D57ULL, 0x916E2B4E73BD38E3ULL, 0xF09BF781FFDF25B7ULL, 
            0x18F4AF1331BFE98EULL, 0x0435F41C74AAAEF3ULL, 0x1CC508F5DBA7B7BCULL, 0x8A135FED2C1CF1C0ULL
        },
        {
            0x0ABCD80D5E94DBDAULL, 0x24FABA193142804CULL, 0x7C041BCB9C213C58ULL, 0xB95D30CAA62B3231ULL, 
            0xC0A2EF6682AFADD1ULL, 0x54BEC2DAFA66EC00ULL, 0x638E216F0F0D2B44ULL, 0x79FA165F7FF69578ULL, 
            0xB49F322320A5DBB1ULL, 0xF8D6202DB7AA598EULL, 0x66DDA0CBA4FEF692ULL, 0x49414AC1E54EEA51ULL, 
            0x7DC3A82287FC19EFULL, 0xECD7D00EBA1E1143ULL, 0x3AF6F7281447AF32ULL, 0xDB8561CA3AB5FE08ULL, 
            0xDE0BF12D05174194ULL, 0xC7CF69B52EDC6422ULL, 0x967FDD48BF5B3B38ULL, 0x27277167D271A922ULL, 
            0x4B0B4A8B0C8819DCULL, 0x6E6A51EB50E0D030ULL, 0x0E4F0E4A25A550F7ULL, 0x93B59F01C9A4BF77ULL, 
            0xE951F52B9FE8270EULL, 0x76FFD6FE152AD372ULL, 0x0C6ED9FDC83B9A30ULL, 0x5F3B8AA90A8C8E61ULL, 
            0x7E2A7C1BC9D7AE91ULL, 0x429DF0756091C6C4ULL, 0xA182464F609A142BULL, 0x95D975635CDF2101ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseHConstants = {
    0xCA67DC0CAECEF5C4ULL,
    0xBBBCF434BE4288A7ULL,
    0x795CF0AC12F1B965ULL,
    0xCA67DC0CAECEF5C4ULL,
    0xBBBCF434BE4288A7ULL,
    0x795CF0AC12F1B965ULL,
    0xDE44AE3577B9B467ULL,
    0x2F006672607138A6ULL,
    0x8F,
    0x7C,
    0x88,
    0x53,
    0x73,
    0x57,
    0x86,
    0xC7
};

