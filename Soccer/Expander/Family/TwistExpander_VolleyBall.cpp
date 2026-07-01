#include "TwistExpander_VolleyBall.hpp"
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

TwistExpander_VolleyBall::TwistExpander_VolleyBall()
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

void TwistExpander_VolleyBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xDBABDDA457462828ULL; std::uint64_t aIngress = 0xC2F00544AA913A67ULL; std::uint64_t aCarry = 0xD7888A0E6B9D2D37ULL;

    std::uint64_t aWandererA = 0xE354C8D8CC47DE1CULL; std::uint64_t aWandererB = 0xF52F005C5A5150F5ULL; std::uint64_t aWandererC = 0xD8B5A5DD883DA91EULL; std::uint64_t aWandererD = 0x86D076A2D10A1ADCULL;
    std::uint64_t aWandererE = 0x912B0CB8E8A18322ULL; std::uint64_t aWandererF = 0x87B5526CFC0F485FULL; std::uint64_t aWandererG = 0xD378452734D59680ULL; std::uint64_t aWandererH = 0xBA63B1449C23862CULL;
    std::uint64_t aWandererI = 0xC39BA8962C1F5528ULL; std::uint64_t aWandererJ = 0xA9B82749BDF99C69ULL; std::uint64_t aWandererK = 0xCA9E88DDD73D8FD1ULL;

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
        aPrevious = 16258916248317821850U;
        aCarry = 10887279543252656842U;
        aWandererA = 14224054447947320293U;
        aWandererB = 11238987108513081744U;
        aWandererC = 14027683350549194434U;
        aWandererD = 16319461245146330145U;
        aWandererE = 11712468922213387714U;
        aWandererF = 14301128386613227425U;
        aWandererG = 16236667077600206841U;
        aWandererH = 12611864060350861840U;
        aWandererI = 11425818954329613593U;
        aWandererJ = 13150352540683019211U;
        aWandererK = 13549986896130341286U;
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
    TwistExpander_VolleyBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_VolleyBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xAB3FA72FACA558D9ULL; std::uint64_t aIngress = 0x853A85C858F50890ULL; std::uint64_t aCarry = 0x8AD901BF49716028ULL;

    std::uint64_t aWandererA = 0xA2D03EE191D25ED4ULL; std::uint64_t aWandererB = 0xD1C6D4032028FCBFULL; std::uint64_t aWandererC = 0xB0C81651ED1311A7ULL; std::uint64_t aWandererD = 0xF1CFA614AE12747BULL;
    std::uint64_t aWandererE = 0x9D4CA39492180139ULL; std::uint64_t aWandererF = 0xB5EB949CC289A114ULL; std::uint64_t aWandererG = 0x828FF2702AAA7FE2ULL; std::uint64_t aWandererH = 0x972C4BD7CD3DF98CULL;
    std::uint64_t aWandererI = 0xB2C8F2FADD0630B3ULL; std::uint64_t aWandererJ = 0xC1ECB16EFC16C56AULL; std::uint64_t aWandererK = 0x8451C10DC3C8AF34ULL;

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
        aPrevious = 9488900751424482628U;
        aCarry = 18422268582876580327U;
        aWandererA = 16432280097669007534U;
        aWandererB = 11989036025463962755U;
        aWandererC = 10685752709117460433U;
        aWandererD = 13369356613018092947U;
        aWandererE = 11138932492591642508U;
        aWandererF = 18256834540951721909U;
        aWandererG = 14894001002297214477U;
        aWandererH = 14760746825616559184U;
        aWandererI = 10102290522118149364U;
        aWandererJ = 9888536919012483180U;
        aWandererK = 17054589392959514451U;
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
    TwistExpander_VolleyBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_VolleyBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBB837BA5848067B4ULL;
    std::uint64_t aIngress = 0x8A957359C08ACAA1ULL;
    std::uint64_t aCarry = 0xAE280377CA5F6354ULL;

    std::uint64_t aWandererA = 0xDC223E700A5E4894ULL;
    std::uint64_t aWandererB = 0x8AB3A366E897BA05ULL;
    std::uint64_t aWandererC = 0x871BC0A814E3DE90ULL;
    std::uint64_t aWandererD = 0xD238B42A02B49F6CULL;
    std::uint64_t aWandererE = 0xA6CB67084D19F1AAULL;
    std::uint64_t aWandererF = 0xC86998B533F252B9ULL;
    std::uint64_t aWandererG = 0xDFD041F67410B3BCULL;
    std::uint64_t aWandererH = 0x97D9B3499D6D882AULL;
    std::uint64_t aWandererI = 0xF3E034D9103AA493ULL;
    std::uint64_t aWandererJ = 0x99C8FE66197BBFE0ULL;
    std::uint64_t aWandererK = 0xFAEA7DC334DC18B0ULL;

    // [seed]
        TwistSnow::Aria256Counter(aSource, aSnowLaneA);
        TwistSnow::Sha256Counter(aSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneC);
        TwistSnow::AES256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    TwistExpander_VolleyBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_I(pWorkSpace,
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

        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
    TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_VolleyBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_VolleyBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBD6CE1C18C4B53B3ULL; std::uint64_t aIngress = 0xCF3CB0AB4E854521ULL; std::uint64_t aCarry = 0xF7346C9FE7EA942AULL;

    std::uint64_t aWandererA = 0xA7F0F1951B5E5F64ULL; std::uint64_t aWandererB = 0xC596EECE18728BA2ULL; std::uint64_t aWandererC = 0xC49D4161A1648E42ULL; std::uint64_t aWandererD = 0xF3422ADB2A859B27ULL;
    std::uint64_t aWandererE = 0xF82310B880BD951BULL; std::uint64_t aWandererF = 0xAC06A9ABD7EB216CULL; std::uint64_t aWandererG = 0xAF6BCA9E902519D6ULL; std::uint64_t aWandererH = 0xF7E7DCDCDD212D5DULL;
    std::uint64_t aWandererI = 0x89E0D3074179C009ULL; std::uint64_t aWandererJ = 0x98844877354A0696ULL; std::uint64_t aWandererK = 0xCD9C532A2C67400BULL;

    // [seed]
    {
        aPrevious = 15441453701450272076U;
        aCarry = 15642553908722471446U;
        aWandererA = 15963045798832695682U;
        aWandererB = 13432602585530571960U;
        aWandererC = 10735337310729282284U;
        aWandererD = 14003680223192982181U;
        aWandererE = 17494261406515812689U;
        aWandererF = 17101837661280697250U;
        aWandererG = 17326524416600544752U;
        aWandererH = 13794673155058987121U;
        aWandererI = 16846605007232729371U;
        aWandererJ = 17014785044990049713U;
        aWandererK = 18281235518947094626U;
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
    TwistExpander_VolleyBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_VolleyBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 3, 1, 0 with offsets 4524U, 835U, 8065U, 1245U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4524U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8065U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1245U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 1, 3, 1 with offsets 3969U, 4785U, 219U, 2425U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4785U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 219U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2425U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 2, 0, 3 with offsets 7966U, 6948U, 6379U, 5833U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7966U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6948U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6379U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5833U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 0, 2, 2 with offsets 4267U, 7436U, 271U, 7931U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4267U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7436U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 271U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7931U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 3, 0, 2 with offsets 830U, 753U, 1854U, 448U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 830U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 753U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1854U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 448U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 2, 3, 1, 0 with offsets 1704U, 189U, 681U, 1558U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1704U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 189U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 681U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1558U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 1, 3, 0, 2 with offsets 399U, 1942U, 1551U, 1022U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1942U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1551U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1022U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 1, 0, 3, 2 with offsets 1951U, 662U, 1131U, 792U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1951U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 662U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1131U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 792U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1998U, 669U, 89U, 1515U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1998U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 669U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 89U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1515U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_VolleyBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 1898U, 1762U, 5208U, 2109U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1898U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1762U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5208U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2109U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 1 with offsets 3706U, 1295U, 3047U, 5386U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3706U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1295U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3047U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5386U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 0 with offsets 1260U, 1102U, 7087U, 2414U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1260U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1102U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7087U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2414U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 3 with offsets 7423U, 5421U, 5003U, 1133U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7423U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5421U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5003U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1133U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 1133U, 700U, 7576U, 5552U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1133U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 700U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 7576U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 5552U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1294U, 1003U, 1646U, 1909U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1294U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1003U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1909U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1105U, 234U, 1237U, 1447U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 234U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1237U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1447U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 967U, 758U, 29U, 1682U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 967U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 758U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 29U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1682U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 151U, 1282U, 1270U, 117U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 151U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1282U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1270U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 117U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 0, 3, 2, 1 [0..<W_KEY]
        // offsets: 784U, 58U, 267U, 1254U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 784U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 58U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 267U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1254U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseASalts = {
    {
        {
            0x2EBE848ED78B88BBULL, 0x6DA8F96C06F5135CULL, 0xE30505D2B12A5CA4ULL, 0x42AFF1B19FBAFEBDULL, 
            0x762AB7D7C2F66135ULL, 0x1A48F05F4794A7B9ULL, 0xB2C438067350D719ULL, 0x95E1CC6AF1F0A588ULL, 
            0xB7CA73617D4A6ACCULL, 0xC2497085F9D58F68ULL, 0x21FEB10508C3DDDDULL, 0x016912EDDE7E2C84ULL, 
            0x95C8DB233C4ECB39ULL, 0x0C809C8E33B746D6ULL, 0xD4C234C565FC2535ULL, 0x8370372A842B3D26ULL, 
            0x74BD53447162E7F3ULL, 0x366729B9CD804120ULL, 0x7046E74DBE3F29CCULL, 0xFDB7A40124B0962DULL, 
            0xD9FB828D321E52B4ULL, 0x6FBAEEA5A04E9887ULL, 0x81A1F1285C2CE61AULL, 0x1189AC0D6684AB88ULL, 
            0x6457668E21FEEDE2ULL, 0x51BAF3568A3A0D10ULL, 0x45FF0DE9DE7BC3B9ULL, 0xF890CFD9C770BBFCULL, 
            0x2553C68CA6DD08F4ULL, 0x46A715274E366075ULL, 0xC694503CF89780F2ULL, 0x7731A0C97FCA8111ULL
        },
        {
            0x0E7E7EA1FDC44F81ULL, 0xF9A39F7E7BBE5EE4ULL, 0xF9592E09EFE7C3BFULL, 0xDDEDB9BC923997E8ULL, 
            0x7C7A2D6F26CFE176ULL, 0x67B0EDE917DC30D6ULL, 0x5C84511EFDC3C90DULL, 0x48DFB83CE1AE228AULL, 
            0x1DF44788BBB8123BULL, 0xBB8FEFE58C448E96ULL, 0x8CB14748F844B382ULL, 0xB243E44E68ABEBE4ULL, 
            0xEA53A15606018E51ULL, 0x64C3EA37A2D72759ULL, 0x6553C37D14D0E080ULL, 0xE3918A7345DEA49CULL, 
            0xA15A85C4D1300F7BULL, 0x98E28FBA4B974EE9ULL, 0x51B05ADD022E8A22ULL, 0x4A0A261D0B5DDF14ULL, 
            0x2576B2105D456FE3ULL, 0xC5CD8DFC983D9581ULL, 0xD0D7A26D54C5B700ULL, 0x6552E7D5B8BEA65AULL, 
            0x724EE59A7866EACBULL, 0x52834C73B1AF9D3DULL, 0xEA41A5B11A0C72EAULL, 0x581D9769CE89A28DULL, 
            0x9CD8AE5F83CF7445ULL, 0xEDE969603F5B350BULL, 0xE81950812AF5AA8AULL, 0xCD85AB394814C8B1ULL
        },
        {
            0xF29C8FDF4CBCCBADULL, 0x43CF3FC08C5EDED5ULL, 0xE7098405052538B1ULL, 0xEBF6284531BC4BC8ULL, 
            0xFB8858DA45FD60BAULL, 0x621B2AF00648118DULL, 0xDBDB6193A33C6A5DULL, 0x597CB6AFE3D80C33ULL, 
            0xDD90CBEDCC2D0F27ULL, 0x0FE77A12C9C9AA8FULL, 0xA36409CF15642BCAULL, 0x04C9FF3B338B9AA4ULL, 
            0x7B230FACFBD1EE00ULL, 0xED54BE2B203EFC9DULL, 0x16FEC91D385F7602ULL, 0xA99575B6FF68A632ULL, 
            0x7560881A579D2D2DULL, 0x3435391C3D3C3520ULL, 0x85F720A13F36BD54ULL, 0xE6AE64BC02B2A1C5ULL, 
            0x2E36561264FF4938ULL, 0xD5EB75D33236BCE9ULL, 0x40D677937CA77CD0ULL, 0xD337543A7A4CAA4EULL, 
            0x5C50A50152C62869ULL, 0x0D274E4E27CEDB44ULL, 0xBA27C5B40595F55CULL, 0xB129E718419B5A4FULL, 
            0x32DC38E5EF91BA1FULL, 0xE09D491951DAE311ULL, 0x9738FDC5DF4E732DULL, 0xAD51AF40A6573C36ULL
        },
        {
            0x6E2F85C65F83A34FULL, 0xC5AC9A03AA2E8DEAULL, 0xB5C70343AEDAA371ULL, 0xC6725A674F787314ULL, 
            0xF8F7423AB7197258ULL, 0x74F7186C9DC2D28AULL, 0x17EE8435C5E69899ULL, 0xC53C566CBAD7C613ULL, 
            0x552F9D8960865053ULL, 0xA186DAB4037447C1ULL, 0xDC637C865638BAB1ULL, 0x1FD76236CCF3E24CULL, 
            0xDF634971D9970FB5ULL, 0x3C86AE2D0DC83872ULL, 0xF2C724E665E0302DULL, 0x7B6DBFE53A958F25ULL, 
            0x567049C312940E3CULL, 0x5DEBAFFA68717A67ULL, 0xCE63BFBC8ED1EA80ULL, 0x968433492C3B9D7DULL, 
            0x2591F04D6949079DULL, 0x100ABED15594E8E2ULL, 0x93CB06980B109DE3ULL, 0x6FD50288F545D6B0ULL, 
            0x8572581DE8A6C550ULL, 0x40F9BE060909243CULL, 0xA73C1B4571C107D7ULL, 0x80BBFE53B6DCE326ULL, 
            0xF0E496DC54B46AEBULL, 0x36EBAF7500782881ULL, 0x503004AADB3077D4ULL, 0xACA9E7B35662F59CULL
        },
        {
            0xB12E5E469CF1A907ULL, 0x6C99FF3434242207ULL, 0x382AF60340812F53ULL, 0x4ECD57F9D13C39BEULL, 
            0x6C5CDFA27C8ADA77ULL, 0x463B9EA88BCAC820ULL, 0x4E520927B578E56DULL, 0x33A87E4D3C192883ULL, 
            0xB260049ABB0C2288ULL, 0xCB8457FB399951B3ULL, 0xD777BBE9397DE5E8ULL, 0xBDE6E392F69BED2AULL, 
            0x07B42D2F4E9722DAULL, 0x1120D04736EBA26DULL, 0x37F812AD55D0AC1EULL, 0x073E51E935263255ULL, 
            0x71E2F7132B5B5083ULL, 0xCDFAB4C58ED9BE8AULL, 0x3D20F3CB10139E32ULL, 0x3F37203F64B70020ULL, 
            0x898ADEB4349D016AULL, 0x7CBEA1DA9CAE367DULL, 0xECD746976C7CEB1AULL, 0x4EE000C15438FE3DULL, 
            0x8970C5C23A5ECB76ULL, 0x1A36219F85C6377FULL, 0x12BF26D826915B76ULL, 0xA6BC3B5E3C5E6106ULL, 
            0xAAD080A02FB510DEULL, 0x6EA54F2BE3240839ULL, 0x16739545B530CC6BULL, 0x2E6DF4217BA08AEDULL
        },
        {
            0x60EDAB92E1F184BEULL, 0xA0D0617C7246BAE6ULL, 0xB733AD79C932CBBAULL, 0xB157CAB1AAF37958ULL, 
            0x357677F8A16843F0ULL, 0x53AE4961C63CEEEAULL, 0x30DC1BA6B78B1B60ULL, 0xF5BA64A077609EF9ULL, 
            0x56876D96BDE1E204ULL, 0xF548412EBAF55190ULL, 0xC92F35FD9CCF214CULL, 0x0975D136F45C5A10ULL, 
            0x0B6825A26BF38DD0ULL, 0x8DB6B7ABE93A92EAULL, 0x8984CB7F1FF7444CULL, 0xA2D60E9BCFEE9F29ULL, 
            0x77AE65DB38E882FEULL, 0x5A1BCDD189CE6DF3ULL, 0xAA64E0866060A529ULL, 0x7BB4C368FDE92A22ULL, 
            0x7D56DDEC59946B43ULL, 0xC0B0C90137806E63ULL, 0x658A463DCDA0C591ULL, 0x56F8D3141CDA9CE6ULL, 
            0x3F6C5FFE040E68DCULL, 0xC412882561A3D1FFULL, 0x5BDD01ACE74093C9ULL, 0x6CE602BEEC2FEEE7ULL, 
            0xF6827CF965227097ULL, 0xA7219E2B79B410D1ULL, 0x85D56D82F56649D7ULL, 0xCC973CC56DBC4C9CULL
        }
    },
    {
        {
            0xF6053292083308A6ULL, 0xCCBE6D9A05F01130ULL, 0x9E79B01AEE278ABBULL, 0x3B500E5DD07ABB1CULL, 
            0x612A1848C4CECA82ULL, 0xD133620998A14524ULL, 0x13DDECEBE743CFA5ULL, 0x53FF72F0DD431FA6ULL, 
            0x4A6025B4D27D0A3CULL, 0x6B5CF4ADFBA103D3ULL, 0x2C0AD476E6FA73B6ULL, 0x3F615FFC7AD76312ULL, 
            0xA3A4450C479F55DEULL, 0xEE932E46C8EF8B09ULL, 0xD553E123F527CAB1ULL, 0xE84A8EE7C2CD2936ULL, 
            0x0275A7CACA3CA3A6ULL, 0xE7E785414ABBFA72ULL, 0xDE68064381F6456CULL, 0xB3EB66FDF45B6B05ULL, 
            0x2BAD14AD9C1399E2ULL, 0xF37CC10652DEC3EBULL, 0xAFE2FAB50B04E06CULL, 0x10282B0A22DE447BULL, 
            0x4785F480916C0BAAULL, 0xB17A0257ECA05154ULL, 0xDC49F16E555C26EEULL, 0x25658C33C13D36C8ULL, 
            0xC8C3122D0BCAD99EULL, 0xE98E8030B360BE5AULL, 0xF5FC436FF55FE866ULL, 0x39F18E6AB1A117A7ULL
        },
        {
            0xD2FE3F936C10FA3FULL, 0x02C0CB2B9BD76B00ULL, 0xB2E90F90BCD47339ULL, 0x648A0C3604174937ULL, 
            0xCD9ED883CE3B795CULL, 0xAE79B474B12C3F05ULL, 0x7BFBD9D312423E89ULL, 0x9793A4EE8EADDC67ULL, 
            0x8CE4F6D5ECEDE469ULL, 0xB261331C69DA4A71ULL, 0xA4E9C2B18A599A55ULL, 0x9398988F01C4A8F0ULL, 
            0x4AA8D3B49107CA7EULL, 0xE51523FA03BC698EULL, 0xC44DC07A2787135DULL, 0xDC132832D428190EULL, 
            0x7CB489142ECD76DFULL, 0x9105B22641D4B701ULL, 0x76EC455D03418ACCULL, 0x6B5557E8389E3DAEULL, 
            0xFEB5A1C66971083EULL, 0x00DF5EE20F862ED2ULL, 0xF809EB6A5D1A9F1AULL, 0xBE3BF5BA2735159BULL, 
            0x3A317150907D3E7CULL, 0xDE81D351F441E693ULL, 0x3D11DC24C32C3739ULL, 0x2DE4815C7DF0FC1CULL, 
            0x91774375625E5F5EULL, 0xD825276FD8B11834ULL, 0xBB4D863A65D86279ULL, 0xA521E195B8AAED31ULL
        },
        {
            0xF65A9833BF13998FULL, 0xD5E896B1C4DD9F8AULL, 0xAB61219F4DF3E002ULL, 0x1EB758BB8D2DC8B8ULL, 
            0x6D918C0527A599A7ULL, 0xF841983331506596ULL, 0xA7C480BCFD3560A7ULL, 0x3DFD1C6C6BAE1C12ULL, 
            0x8053A96FE96C17A5ULL, 0xF8FE0FF628CF43C0ULL, 0xD98097096B693B99ULL, 0xE24A9816092DF70DULL, 
            0x257591E5C35EBD60ULL, 0x30121D3DF62E09D9ULL, 0x13840516C0910601ULL, 0x1BBDB1DDE18920BBULL, 
            0xDC3726AB031A2E8BULL, 0x3DF8EE3E0840A7A1ULL, 0xCFA69395EEF1C603ULL, 0xEC6C6F521BF61EF7ULL, 
            0x830173A06CE6208CULL, 0xAC451441A975FF7EULL, 0xD249170601E59964ULL, 0x8BBED62967BBCBABULL, 
            0xA7CC38179DD2F3DEULL, 0xCF4DF2B711AC9D0BULL, 0x41D713235681C2CDULL, 0xF4DC802E0BAEA633ULL, 
            0xA06AB0A673050055ULL, 0x80663562F5BF892FULL, 0xD5695C021CCC6992ULL, 0x535E978B6A0E67E5ULL
        },
        {
            0x909F79E40F9CD88CULL, 0xFCEFF0EA595BBC0AULL, 0xB0B32BE47CBA1EF7ULL, 0x22BCE35F2C5EDC62ULL, 
            0x6470CFBE57913672ULL, 0xB03E9BE791E90321ULL, 0x21E4F4A258F672C3ULL, 0x1CA8A47A1DDA643EULL, 
            0x209F48C6DACCC704ULL, 0xACBCF6CA99798141ULL, 0x3FCBADAF08F7F85CULL, 0x463D56B4656AA5AFULL, 
            0xA5E2595284862D4DULL, 0x2D56D9625ACBBE56ULL, 0x732DC74C238CA7B1ULL, 0xFAF03B25E33115DFULL, 
            0x591FA13F80D4D22BULL, 0xC55BCB43E16F724AULL, 0x883CD1FE82F8CACAULL, 0x84A2EF93818D5CE0ULL, 
            0xF9C56855DF4F46A5ULL, 0xF34476785EC2DC1DULL, 0xD7503AC7A3557F54ULL, 0x4AA28D61E4C50FEDULL, 
            0xE9849FE3A602D962ULL, 0x199EF22C8C495399ULL, 0xABB65D133EFBAF87ULL, 0x0746FE90B27FD881ULL, 
            0xFDFD907228DBBB33ULL, 0xC05D0EEE7B260973ULL, 0x15D0E342F4BE0C78ULL, 0xC87B652521B7DEB4ULL
        },
        {
            0x6A67579B54DE7618ULL, 0xBC2D2AAD7A0F3481ULL, 0xB64D8254B598B45DULL, 0x2FD1D74526F8962DULL, 
            0xFF72D9AC31569F98ULL, 0x672C7D1A55DB6985ULL, 0xE8AC2FF15EBFE4A3ULL, 0xDD6D1A9E19AADEEBULL, 
            0x21F31D0408AFC3B2ULL, 0x1E8D3E05628482DBULL, 0xBD95FF6258043F30ULL, 0x9FB47DC04D1791BFULL, 
            0x4D8D88CFE7622DD8ULL, 0xE982980E9813B63FULL, 0x2B6197DD8A13131FULL, 0x6D70D0701CD9E16CULL, 
            0x59F4A300F22B1113ULL, 0xD542283D5E30F6BBULL, 0x53D2EDD71BA1E832ULL, 0xC2D5D3BB782800C3ULL, 
            0xC18A6607B3DD5033ULL, 0x86EEAC65B11C637CULL, 0x332FA4578E5E8C68ULL, 0x719E194F080B05ECULL, 
            0x6D77A1E31FC69BB1ULL, 0x871F0E2B7554C5D6ULL, 0x661B6FEC6FDAFF36ULL, 0xA680D087C8C06686ULL, 
            0x74E6C1615E216A6FULL, 0xAD1CFEC3FCBEABCAULL, 0xD22BED641EE53EAEULL, 0xD7868A0DE0F7D85BULL
        },
        {
            0x229552AD6BC5F07EULL, 0x002907ABCE7B31F4ULL, 0x66365308ACCFCB11ULL, 0x72E72D8D117DC861ULL, 
            0xEF6EF97D2B25FD80ULL, 0x0C504A3D129B88BDULL, 0x24685CD34D545E8DULL, 0xAAB2F9ED24B7FE9FULL, 
            0x7ABA35A8C761340EULL, 0xAF9E3B0EF5C6246BULL, 0x3474E662016C1E09ULL, 0xED120E0FE9C336E3ULL, 
            0x2B2DE777ADB8EBBBULL, 0x104A9B85D5B792D8ULL, 0x65501144D6CBFB56ULL, 0xFB69BC30E86ABCE7ULL, 
            0x9D070F1A0E273F49ULL, 0x0C4539E9E082AD26ULL, 0x387D25B8D7AF3BE2ULL, 0x39299C744A59FD0BULL, 
            0x803C4B8D62E90841ULL, 0x5BDEDAB3AC0BACFBULL, 0x68E3F1D3DF719DD3ULL, 0x4CE64A9079BC00C3ULL, 
            0xD6FEC4EA98D1756CULL, 0x9ED4CC40E75F702DULL, 0xBF91D91271393ADEULL, 0xC7E57ED2A8C7CF45ULL, 
            0x80CAD6E29622033DULL, 0xD6BA956073F25ADEULL, 0x165AD33A69E9B3B1ULL, 0xF0E9BA7B2988268EULL
        }
    },
    {
        {
            0x7EC368CD9B9D3558ULL, 0xDFF2E97737D5E59BULL, 0xE867C091BEAF9A7CULL, 0x19FEB13B33DD0F86ULL, 
            0x63456789CF7EFFACULL, 0x23DB0EE5213B1CE2ULL, 0xEC01EF8468302DCAULL, 0xD0F470C4033F84BCULL, 
            0x3619970E994A9753ULL, 0xA32C41713EE01F0CULL, 0x0D2AB4B4F9E467BAULL, 0x769C3214F0FBE65CULL, 
            0x07A55B691EEAE15DULL, 0x512589BCFFA5988AULL, 0xF7A47FC45D80E17BULL, 0xDD8726E0974260AFULL, 
            0xEC328BDF2BA5BBAAULL, 0xE000BBB4756768C9ULL, 0x606262557A157FF0ULL, 0x184942626C1C408EULL, 
            0xD9EFE0F3C45AA70CULL, 0x08A849526C65F7EAULL, 0x6532BE17CC9E9D8BULL, 0xE039865F9C0615B9ULL, 
            0x2373D10761D48884ULL, 0xC1459D325DF1A932ULL, 0x3AA2D305CA8E1993ULL, 0x1EC3250C721B69AEULL, 
            0xE7E13C64DCC8283FULL, 0x6C5894689B056665ULL, 0xC7FE75A416D80C93ULL, 0x2C1E6EA23509A6BEULL
        },
        {
            0x8B002B71732EF079ULL, 0x48104C4FBAE07B78ULL, 0x450072FB407F198BULL, 0x25CB1C663291A347ULL, 
            0x7B016930E5681FD0ULL, 0xC7C90D00B5431795ULL, 0x805F7965826B9E93ULL, 0xCC152B0124CA087EULL, 
            0xCC034485F43C31B2ULL, 0x2246F526871D6F85ULL, 0x481938A991C0E7F2ULL, 0x8F0F0D24D6ACD9FEULL, 
            0x3480B113B294EB96ULL, 0x9155C655B1577579ULL, 0xE05491E90CD7C8C9ULL, 0x6D8C127FE8787918ULL, 
            0x8FA66660F785BF2DULL, 0xF98EC2473D02CC56ULL, 0xA31199C194AADBE2ULL, 0x29714B28CDA2AC24ULL, 
            0xC525E85D77BE5667ULL, 0x078B136F4A64C777ULL, 0x28B513879A207E3AULL, 0x20F7F8AFE2576112ULL, 
            0xB4B7312257853FC9ULL, 0x3C883242753200C1ULL, 0xA1D8F9454B16E1B1ULL, 0xF80753CF29D7158FULL, 
            0xA15B3720F2CC1207ULL, 0x1FBEB7436F2EABB2ULL, 0xD644F773616F8A98ULL, 0x3BA41205AA5E0967ULL
        },
        {
            0x80481AAFABC2D601ULL, 0x71470EABBD953FA1ULL, 0x7BE52CDE4A59CFCFULL, 0x4919DDAAFDADE17EULL, 
            0x74561BF6B7A325B0ULL, 0x6EC272D145EA9497ULL, 0xF529A5AAFFDCB2D5ULL, 0x10B7807B3E9A1EB3ULL, 
            0x14FB8CD83E86AF75ULL, 0x7F2C49467EEF0B90ULL, 0x3265E7495E0F9B37ULL, 0x88628899CB353D1FULL, 
            0x99D36EAB0F74288FULL, 0x6222651EDC6D1F8FULL, 0x3B2F8CF7FF849040ULL, 0xB61F0EB6FCC49D4DULL, 
            0x21902E28155A6CB0ULL, 0xEDA1B0B84E68E1EFULL, 0xAAEF673F67932AE7ULL, 0x20A9FA9D7C37A7B4ULL, 
            0xB900E61524267421ULL, 0xEF8CC8A6D5A481F6ULL, 0x735DFB50E58B4FCCULL, 0xE2EAE28C65D2F21CULL, 
            0x185F9D59A3AFCB6BULL, 0xC40912815D39A606ULL, 0x0CB6A1CAE8FB6DA4ULL, 0x8D714E659F26BBDBULL, 
            0xC5A356272F61CB0BULL, 0x07179525A57226D1ULL, 0x5C0109EFFDB5EBF3ULL, 0x22E1542F11009778ULL
        },
        {
            0x97F4E08ADC669B20ULL, 0x6A7712C3A6FB195FULL, 0x73809C45B4E196D8ULL, 0x0053C142F1DCE285ULL, 
            0x08C669858AADC972ULL, 0xBE0CD02E4ADBA7B3ULL, 0x449EE814C757CF24ULL, 0x443403FF4835BCECULL, 
            0x256610D04EE93FE9ULL, 0xDFEEC4D12624D94EULL, 0xB71C3C421BF31AAFULL, 0xDEC53856E3F81568ULL, 
            0x216A4AEB5A0AF926ULL, 0xF7146592C8485D84ULL, 0xFB33A9D141BD0FABULL, 0xD2A77211699B4B06ULL, 
            0x7766F718A3AF26FDULL, 0x277F0027F4C0E29EULL, 0x8F1AB61CE7128B3CULL, 0x74126169EEA11D25ULL, 
            0xCA7AB228DCD852A7ULL, 0x47A810B6982B9725ULL, 0xBB09D7D01E9C816AULL, 0xD38019A21227DC1BULL, 
            0xB86D96E0C009EA15ULL, 0x2873FF7B3F652CC4ULL, 0x80B1A340746B2129ULL, 0xC5AC9F26BD70ADD9ULL, 
            0x279A400725AA3D73ULL, 0x5A44C364A95DE423ULL, 0x7E853F857D2B64A7ULL, 0xB7ACB4885CD4CE91ULL
        },
        {
            0x24DBF15F2354678EULL, 0x4DFC322CF8319572ULL, 0x59F4518BF301A1BFULL, 0x988E6DC4EDC43F59ULL, 
            0xDDF24E157CF8D3CAULL, 0x3F8C8EBD8C278A13ULL, 0x5C335CB985AA1FE1ULL, 0x377D8116E5967A07ULL, 
            0x65691A1536D404D6ULL, 0x40A97CBF836732DCULL, 0x356EB7551B784376ULL, 0x1D793220D6B55E70ULL, 
            0x0CD69041C256BDA6ULL, 0x7F6C1A9D2B1A9472ULL, 0x90198DC3C2905F28ULL, 0x39CE4C4A29F920E2ULL, 
            0x88DA566B7CB57172ULL, 0x47432709AC38F175ULL, 0x9471700716D5AE7FULL, 0xA3A846F82A209AB8ULL, 
            0x0D8C98A594BE3B84ULL, 0xA51989B34149564BULL, 0x9B77007428FC2264ULL, 0xA52BC26B5F36D74DULL, 
            0xE6DDB37B394699D0ULL, 0x9FC45F9E42BF84C5ULL, 0x26C9F014DA3EA277ULL, 0x2D50F37E412A6F5AULL, 
            0x1C672F21EED11D2DULL, 0x3744996C19270C27ULL, 0xBC74A69199BBEF97ULL, 0x9F89DC26A28A5251ULL
        },
        {
            0xA276B9D03DE116F3ULL, 0x92672A1102194DE4ULL, 0xAF7DB258C77E4D3DULL, 0x869BB8EE33552071ULL, 
            0x1B9496EE0BDF1DDDULL, 0x8487DADE5970C985ULL, 0xDE94B573920B0043ULL, 0x787F44AF05FAE2B1ULL, 
            0x470E8FE8454D46FDULL, 0x29C1D8A58EA99491ULL, 0x64C7B2A558C0C167ULL, 0xA70BAD7FACFF378CULL, 
            0x073A26D6B09A5530ULL, 0xE5B022AC0A47A237ULL, 0xBFB3C59A47B69884ULL, 0x5C68551F687703C3ULL, 
            0xDC103D960DF28FC4ULL, 0xAF312768FFD5456DULL, 0x4D53FD06D302765DULL, 0xA9BFF3B34C135FB9ULL, 
            0x8680BA2AD409CB5FULL, 0xA0415535DC0BE61CULL, 0x5F625BDBEA8EF863ULL, 0x6089E20E39B82663ULL, 
            0x8944D3D76CA4367FULL, 0xC2FA6324AE67324EULL, 0xE139E579C8CF3443ULL, 0x33770BD44E51C360ULL, 
            0x65ABCD7397B28D20ULL, 0xBE194374D837C472ULL, 0x06C49912DDAE3AA7ULL, 0x49B7A3BDAB8C9C23ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseAConstants = {
    0x712C51B5842F94D3ULL,
    0xC930B4CDED70D748ULL,
    0xD54755724A1E1924ULL,
    0x712C51B5842F94D3ULL,
    0xC930B4CDED70D748ULL,
    0xD54755724A1E1924ULL,
    0xB773B2DD4E66B75BULL,
    0xB0D5F526CB64A2D6ULL,
    0x59,
    0xC1,
    0x5C,
    0x7B,
    0x7C,
    0x4A,
    0xA2,
    0xFF
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseBSalts = {
    {
        {
            0x084892F3F922C48FULL, 0x1013E7E7AD67641EULL, 0x41F701C3E093D36EULL, 0xDE5D89820B93B676ULL, 
            0xA1813E256F8A7491ULL, 0xEF1A4FBD4F9DC09BULL, 0x2BFCAD0FC4B83092ULL, 0xDAA2874550E040A0ULL, 
            0xF65DC2C3144B1B74ULL, 0xD9C3193E7F48790EULL, 0xA1CE05ADD5728301ULL, 0x87BCFF909C58D6CAULL, 
            0xC5D50028303ABE42ULL, 0xCAFBE928F3731A06ULL, 0x493437EA2EB60E28ULL, 0xB85E14AF1A52142BULL, 
            0x09AC267F9130B4D9ULL, 0x2B1714BBCC4A6F8DULL, 0x47DD2EB884CDBC9FULL, 0x173B65382873B0C0ULL, 
            0x317E1EB29D2CF9C7ULL, 0x7BEBF3AD2B0DC0ABULL, 0xBD1F1003188F87D9ULL, 0x22EB9589FE226D60ULL, 
            0x312399541BDFF4F0ULL, 0x4FF25A96B1483DD0ULL, 0x2E5D1EC66469FE86ULL, 0x49142E54761B9C8DULL, 
            0x6FDFBF2475BC830EULL, 0x5448E497021C44E5ULL, 0xBD19DC3E0E58D9DBULL, 0xA6CFDF69A782AF3BULL
        },
        {
            0x5392B49BDE537C36ULL, 0xD98D298382245A9DULL, 0xBF2D2FBD40D8F335ULL, 0x9B19543FC441EF18ULL, 
            0xAFB0DD80EF54467CULL, 0x7C1D63773FA72F8FULL, 0x56DF1FFF8A8D8F69ULL, 0x0DCF45966183394DULL, 
            0x095E831066837BC2ULL, 0x52E665E0A5696431ULL, 0xC4EA9AE02B97B664ULL, 0x79456BD5B4FD96B6ULL, 
            0x146F86D416EB3DF7ULL, 0xD79AF5ACACA2775FULL, 0xCD841E0B3FFD33FCULL, 0x48C06645C3025085ULL, 
            0x7A454AB395167C58ULL, 0xAB95C9CD0F18A6D4ULL, 0xB23BDF67382F0FD2ULL, 0x0C6DC586B0AE7BBCULL, 
            0xFA0B5D0804928427ULL, 0xAF23E4244E6BFDBCULL, 0x4437E0C8A4A19279ULL, 0x12123254F4C08202ULL, 
            0x7ED9B957ABAD9300ULL, 0x7C568FAEFB98EAD0ULL, 0xF8D75C3837946C41ULL, 0xEE519F8128B2D2AAULL, 
            0x59F9D3B1C18ED7E1ULL, 0xD563487CF1A2A2EDULL, 0x7691CBA4E9CB99EDULL, 0x3137ED9778333EADULL
        },
        {
            0xD65A5E9957BACCD2ULL, 0xC9BD57E507059AB6ULL, 0xEFCE82D55EC15D75ULL, 0x78BDA5F49907C106ULL, 
            0x32A7755C5E8B3653ULL, 0xD0070B764A416605ULL, 0x0ABBFA41B06394EDULL, 0x66F8F52A3713EB7BULL, 
            0xA4F033BB7758E1A8ULL, 0x6BC56CB48476F9A8ULL, 0x4D95BE76784C93ADULL, 0x7DD90826EAFCBBA7ULL, 
            0x04FC4DE0BD056E6DULL, 0x6251F791589D9168ULL, 0x026C978FC7063CB7ULL, 0xE110908D4B83E2BAULL, 
            0x70DE235539D4EE7CULL, 0x16B22D7FD8C976CCULL, 0x690A88DE73E41346ULL, 0x8E84837D81A62E5FULL, 
            0x9AFB4202112D4705ULL, 0x3E68BF9CBAD8E18EULL, 0xD727DE972779709DULL, 0xFC9985DEE1AC39AAULL, 
            0xADD3D7C59F858BF6ULL, 0x99C4243DF3BEE3ABULL, 0xC2546DDE8F1E37D2ULL, 0xEEAE2B4E63D1DB47ULL, 
            0x04FC26317ABA19EBULL, 0xD14D81E43A622EECULL, 0x790E81788C6148ABULL, 0x9CC1B040067A2A99ULL
        },
        {
            0xF6B3A8BC4385B2E8ULL, 0x91CD6C1861EA2354ULL, 0x411C81F7FCD9B433ULL, 0x5D8D17C8847E7C09ULL, 
            0x1A95A0BC81BB2397ULL, 0x1EDACD3AA01A6773ULL, 0x99A677D362354FE6ULL, 0x0177082FFEEE3697ULL, 
            0x40CEC3379DD54F8BULL, 0x19A060423B4A419CULL, 0x11A85B2012E595D8ULL, 0xCFBC1C4883E45D64ULL, 
            0x86F2EEE7FC19B4F6ULL, 0x0346AF13695426B8ULL, 0x2466E27B265803EBULL, 0xCF409C86F362563DULL, 
            0x58AB50902CFF8127ULL, 0x5835D2F58594E8DFULL, 0xC9999EEE70A090F8ULL, 0xD87CAE54FDB77855ULL, 
            0x01841BF87F195476ULL, 0x24D83A649493FBB8ULL, 0x2D587863619CB813ULL, 0x4BDBAEA57F497015ULL, 
            0x41C820DF29F65E3EULL, 0xB611704D14270C72ULL, 0x18847077BAABFB7AULL, 0xDE591FB2515671E9ULL, 
            0x55BD5C9F6227B090ULL, 0x7CAD1FE057CD5A76ULL, 0xB570D28F0CB9EEEFULL, 0x3530CD898A705E91ULL
        },
        {
            0xC4C1045EBB64C098ULL, 0x7FE8E598A98D90B2ULL, 0xDE35AA2B24263CADULL, 0xD1DABCD7B7480B1DULL, 
            0x35625928F9C8B765ULL, 0xD14C3C8201E4F9D5ULL, 0x212DA397C3005678ULL, 0xFA5C418B8CD7BA3EULL, 
            0x24CFFEF05D5FA85BULL, 0xCB7AEFE552734B21ULL, 0xAFF37DA48F7842AFULL, 0x1DB488BB8032F2EEULL, 
            0xFA79915D94393955ULL, 0x5A7C75E4A40AFC28ULL, 0xB6244A936F681854ULL, 0x0E66E51CE40DA4E9ULL, 
            0x1074D3B5D09AB658ULL, 0x886ABE17636901BAULL, 0x4B009E12A3A01C64ULL, 0xAE193A9B52632223ULL, 
            0x1A19B9C4940E7483ULL, 0x3E0C01AD65CB1864ULL, 0x01A5B979445EAF14ULL, 0x4E898FFC01C02CA9ULL, 
            0x40E2E755E5CEC31AULL, 0x743FEA064447A9E1ULL, 0x162DE2B6E54D9CC2ULL, 0x09EA2C78D3F50F14ULL, 
            0x4A99C7DFEB22ABB7ULL, 0xFD05D5F5B7BC8E97ULL, 0x4F6ADE76B7CB7458ULL, 0xDE6ED51479FA4B42ULL
        },
        {
            0xD6EA1D560EF086AAULL, 0xFE8DBADEA1273471ULL, 0x2C7AA5C9FCD6ACABULL, 0xC9917C36E46226AAULL, 
            0x92F351F68685DB69ULL, 0x8C822FBCC6C6373DULL, 0x51F37650DC282E73ULL, 0x08D0BC8E6804E94CULL, 
            0xB3966B4BE92C591DULL, 0x81EC95DA3583D43DULL, 0x41C6FCD3BF335065ULL, 0xE7E05EC8A06B980BULL, 
            0x2FBD97B1DBF2B541ULL, 0xA6A52EB877138E2DULL, 0xD7B3A048E947C75DULL, 0x9EF2D21AEB979419ULL, 
            0xD955030AF385C4A4ULL, 0x21BD2E2E6640A44DULL, 0x329F2AF8BE8D28DAULL, 0x29CEBD0C85D9F341ULL, 
            0x836F93A36C8BC17EULL, 0xFF631493FF18FE59ULL, 0x8E73F6EC5A196868ULL, 0x829C868EE4A57407ULL, 
            0x39DB468640FDE23FULL, 0x224251F890DB6414ULL, 0xA912CC8AFF96B37FULL, 0x62108D9144344A02ULL, 
            0x7C4D26F758BBA596ULL, 0xE5900C8AF8D1C645ULL, 0x0D886863B5BB9916ULL, 0xFE8BDBA4CBD29256ULL
        }
    },
    {
        {
            0x2B26DA8A4340D11BULL, 0x729D4ADEE3EEE28FULL, 0x4498E6FB0691B8D5ULL, 0x084BA7968618CA6EULL, 
            0x0B97961247785A81ULL, 0x867D178602FF2755ULL, 0xB673FB911EACBE75ULL, 0xE6C4AD0E95AE0CAAULL, 
            0x3AEC5C0AA1091DDFULL, 0x2DCF1397F6904668ULL, 0x0CE29F3BC2FDC855ULL, 0x57F8BEAAA9E92F61ULL, 
            0xC461F9D52255098DULL, 0xF2003BFDBB8A83B7ULL, 0x385A35FD1F1DE2D3ULL, 0x842245EE5DB10CA8ULL, 
            0xA9386C28DC13B523ULL, 0x284F06D9B0A06A3AULL, 0x90F24CBD1E6A736EULL, 0x24F4FF64AE7298BCULL, 
            0x6B16D40087F83496ULL, 0xB8645ED7515F8E1BULL, 0xCBC8EFC2F3F7E096ULL, 0x96F54D15C0294364ULL, 
            0x19E09206AAF9FC0DULL, 0x084C2C41390A8C04ULL, 0xB1BA655C83BD58F6ULL, 0x4FC723C479CA0BEBULL, 
            0x4E87BD9F1ABDABC6ULL, 0x14185BF5BBCFA63BULL, 0xACD77C5B2019F5DDULL, 0x4C07F81A1D1B6DADULL
        },
        {
            0x20B9878B4AF5F745ULL, 0xAB0E59DE678DA8FCULL, 0x8AA8CDD0169B3281ULL, 0x2010165554CEB77FULL, 
            0x3554E1E2FA67B15FULL, 0x67398CABEA0FB7FCULL, 0x9CA14D5A29A87861ULL, 0x8ECA0CF1A96EE021ULL, 
            0x2DE6D2A2388C9CF5ULL, 0xE4D32835D9217B02ULL, 0x4BAC3B7175FA211AULL, 0x79F1934EA499FD93ULL, 
            0x398EC94695A2F32DULL, 0xF8A775C2945AE005ULL, 0xFB4C196EF19DF709ULL, 0xAD4186766404CE05ULL, 
            0x6F2D180B480497BAULL, 0x2B4A6A7E5316F59FULL, 0x3E13AC615A856E28ULL, 0xE35AE4CAEB6FABF5ULL, 
            0x264DA99E480CF9D0ULL, 0x055B9B8F49530812ULL, 0xFAB112CADE2DF2F8ULL, 0xCD8BA41E358C1C35ULL, 
            0x72627086AEFC2CABULL, 0xFA838CCAE96D54CFULL, 0x3F83A12989BFD076ULL, 0x607F7DE2E2732195ULL, 
            0xEE9CF484B22689E1ULL, 0xF6ED70B440ED028EULL, 0x587C292B2DE2AB6BULL, 0x624D9A8464673B25ULL
        },
        {
            0x614D81B7F276FDF5ULL, 0x8AD63AE6C9CD62CCULL, 0x9C739766FC9CF162ULL, 0x2549EE66E63FA86EULL, 
            0x33D89C79F632216EULL, 0xD9F641A6E42CDDA8ULL, 0x12614B0E01D56BF2ULL, 0x4738486BC9312170ULL, 
            0x1AB24D046567B218ULL, 0xE529A2D7CC4EC00FULL, 0xFBF5EB040E0BCADDULL, 0xC7A876217FE5B300ULL, 
            0xA2A2E784FC938EF8ULL, 0x7973EEEC8FC1205AULL, 0x0797921C7145783DULL, 0x3810F933069E2A87ULL, 
            0xB76EC0F2702F19E3ULL, 0x0A5B7F5886DE09D8ULL, 0x73B046D23B770C0AULL, 0x29902AEC4CE1139FULL, 
            0x7AAB08150A6EFF31ULL, 0x5D0D0D40EFB4905EULL, 0xCAA24BFA9E2DA3C0ULL, 0x37F8899522F3A30BULL, 
            0x949A5E528C1A6083ULL, 0xBB7526DEE7020791ULL, 0xFD7E39854FCFD06FULL, 0x462A587A30669FCAULL, 
            0x0D83D45BC8070677ULL, 0xA8C5BA398C196156ULL, 0xDCA668A680FF0EE6ULL, 0x8D50EB7854AFA66CULL
        },
        {
            0x001488EB7BEBBB67ULL, 0x00E838166D561CA1ULL, 0x2F38176CFD1A7A17ULL, 0x9995497D52E7DC44ULL, 
            0xF6DA506821DF26E1ULL, 0xE4FA90880518180FULL, 0xE5D7B3D4E1A92234ULL, 0x04D8DE2EB34ADE6FULL, 
            0x844C3A9A220563B6ULL, 0xA6C07858D8B17F91ULL, 0x8B6DD80CC9321544ULL, 0x06CB33DD5D2AB3D5ULL, 
            0x1E529922980C1226ULL, 0xF2CC518F36A77AC1ULL, 0x4CF64BEFA521672AULL, 0x5E4D1AF0018AEA67ULL, 
            0x20D3AEE6D610BF6FULL, 0x171EF075BF6C0D3BULL, 0xE7C67DA2A808A7D5ULL, 0x16BC3CE89D1E5A69ULL, 
            0x166A1E82825CC546ULL, 0x9FF2E21028C73EB5ULL, 0x43A7B8C3F5F9DB5EULL, 0x917E68B1F2AEE820ULL, 
            0x9408266AD2EF3B37ULL, 0xB6072FA42F339D58ULL, 0x20F3745EA937AB03ULL, 0xCDB7714435F276F4ULL, 
            0xD3750F4FDE69FC1FULL, 0x50983DCC62D8B0F3ULL, 0xA344D99CB67496C9ULL, 0x4E47416FA26FEC78ULL
        },
        {
            0x5508110511566B97ULL, 0xCE43DF7119E9A307ULL, 0xB608DD217D836666ULL, 0x32B77CAED4736115ULL, 
            0x109A90AE40DD79FAULL, 0x67FB705E615F7D0DULL, 0xC872F99C01592FB8ULL, 0x64B077C71D6CEDBEULL, 
            0x4F221D974D6B6572ULL, 0xAB28C23A6A481801ULL, 0xC6963CC886AFE612ULL, 0xA90D1D6AECBDBBF1ULL, 
            0xD379B581E6FBA4F5ULL, 0x201C6B6F01ADFC54ULL, 0x53638BFA9A3F8E58ULL, 0x63C57BE943C0999EULL, 
            0x54E006CB5A2885F3ULL, 0xCC459ED35E7D8206ULL, 0xB170EBB9249A50FFULL, 0xFF27ACEB600F467BULL, 
            0xAC7888BA03ADD2BFULL, 0x00F2CE263FDDCEEEULL, 0xAD6BD83BCD6A3BF7ULL, 0xB65716CA9232228EULL, 
            0x64F8310B8597D64FULL, 0x954D80EA90835C37ULL, 0xBB5AB6632D34545EULL, 0x72AE58315F8F3736ULL, 
            0x9795D91E47A31503ULL, 0xC92E74503446A0BCULL, 0x4345E8D15E9CE7BBULL, 0x77AE3FAC14487C0FULL
        },
        {
            0xBE61691C253B0C15ULL, 0x4E784546F711885CULL, 0x1DFA610CC62B2DD5ULL, 0xFF65BCD99D8260CBULL, 
            0x0D2CCA154E660C44ULL, 0x2D4DE37D6455D53EULL, 0x8FFB41E55887948AULL, 0xE7020204171E1CFAULL, 
            0x783A151E0B073F02ULL, 0xE4CCD6E30D895C3CULL, 0xEEB0C57EA58D8F56ULL, 0xBF5F010C1B4D3240ULL, 
            0xF94B4F1F0F0FDA35ULL, 0x39621CE3F4243F6CULL, 0xAC52268222317BF5ULL, 0x92949BF614EAB204ULL, 
            0xBCE270CE7EA36C1DULL, 0x0075E08A44B78A9BULL, 0x1D1144E559F77FDCULL, 0x29C723C5FC8650FBULL, 
            0x0527C32428758DDAULL, 0xA77F37D27C57D099ULL, 0x2028BAEA591B3D8CULL, 0x8640920DBA42667DULL, 
            0x74524D65823F1D26ULL, 0x9FB89EE236DE41EBULL, 0xADCADF6EA1BC0985ULL, 0xC1A6153EDDDBED06ULL, 
            0xA595575DBD8F135AULL, 0x886630DB1ACF837BULL, 0x1055300CC1A4E4ADULL, 0x9BC7CC370EFAB08BULL
        }
    },
    {
        {
            0x4FE1060B58A5ACF9ULL, 0x2B6E3BD89288A9B8ULL, 0x14DB8713524E91F6ULL, 0xEF188E559942B5AAULL, 
            0x3EF25B2A77B57CCBULL, 0x7C06196DFB7B9700ULL, 0x20BEFE1EEF8C1EA6ULL, 0xDABB0D25A1F1FF7CULL, 
            0x445F436418E18FE8ULL, 0xB66CC35E33D949A8ULL, 0x4A1C08C196679AD9ULL, 0x540FFF72E67FF315ULL, 
            0x751A6ACC274F9BEFULL, 0x98C6F63E5A4F35D5ULL, 0x3B6B04E018EAD410ULL, 0x0A1E84C4CC347FB7ULL, 
            0xBB33FDCCEEC232CFULL, 0x5F4CC3943702963BULL, 0xBD8914AF5CE1A003ULL, 0x50B3E3CF36224961ULL, 
            0xA4AC4D447442AFA0ULL, 0x6FB17EB355595D25ULL, 0x5A96B6873B1183FCULL, 0x99CB279252E5FF49ULL, 
            0x2047233CE3C2CABFULL, 0x1F38ACDADF0F5869ULL, 0x1979CBB6A1B9E648ULL, 0x5EDF4B9FA104D45AULL, 
            0x7F8FD7CE4DB75AFFULL, 0x075D75E038286A7DULL, 0xF85C8F27558E5B2AULL, 0xA4E60E1DBCC17F1EULL
        },
        {
            0x8562E327C361D15FULL, 0x89187EBF87F1D48AULL, 0x4A8BD37480D66DC2ULL, 0x08FF221202133717ULL, 
            0x9F2D4103380AD6F2ULL, 0x8F26576E3F0017C0ULL, 0x567BA5538A911C2AULL, 0x60F57A0AFF206611ULL, 
            0x89A348D233E85F09ULL, 0x328D9352BF062A34ULL, 0xF3A035ED91075CD4ULL, 0xE4A58CEA54BEB117ULL, 
            0x5F304356BA33907EULL, 0x873192522C9DB2CAULL, 0xD7EA441492481552ULL, 0x22C3B1A993172CB1ULL, 
            0xA14DFAF55CA82E0FULL, 0x2139C89D0CBA9CB9ULL, 0xDF2110ED7A4344FCULL, 0x142C796BB5AFEF03ULL, 
            0x4A51E2F88F304D68ULL, 0x04165C19B8C1BFB9ULL, 0xA0AA6A7FF1E1D36AULL, 0x00A4F4A792F26282ULL, 
            0x3DF67AA03180480FULL, 0xDC9960214802FEDDULL, 0x87882CB7CD9F9081ULL, 0x90E583C9906B8718ULL, 
            0xA95F305CC6D90B17ULL, 0x3082EFB520FE5DF5ULL, 0x81609CE7778EEE9AULL, 0x5F34F95D293E532EULL
        },
        {
            0x70D6D1F33FF300CEULL, 0x51D439B867402FC5ULL, 0xDD6D09E246A82DDBULL, 0x770DC9E49251AA7DULL, 
            0xE83EBCE9DF412C4CULL, 0xBD096113D1D1CDB4ULL, 0x9838F2DB0677D1E4ULL, 0xE517AA84F527DA7BULL, 
            0x7BB6175E1AC6C438ULL, 0x826A5934BA7B1A22ULL, 0xBDA2AB1863A3D620ULL, 0x033669565EAC5D98ULL, 
            0x088B3AF461C6637CULL, 0xF89C98066FCB3ED3ULL, 0x020A664CB0CC96ABULL, 0x38B5E2654B5D1CD8ULL, 
            0x2772A17E90D31A21ULL, 0x874DF985E37022FDULL, 0x717DA6DFA8C0CDE6ULL, 0xE3148D6317A7AB9DULL, 
            0x6B2D41EA9D55B270ULL, 0x5D0871B5C907CE10ULL, 0xA0F1BF10B9EBC1C8ULL, 0x0DE808CFB577FAF6ULL, 
            0xEE9DFA96504907A0ULL, 0x04F6A41A6CFDE0F2ULL, 0xEC9C9A14AE7166DEULL, 0xBEE91214913ACF1EULL, 
            0x45239E19C77BADE8ULL, 0xA220658B58698A5DULL, 0xB945F1D70027B18FULL, 0x72E53F0C7753BE3EULL
        },
        {
            0x4545969DB50B6F95ULL, 0x803939FEAADA7C5EULL, 0x1962DFADF5954F57ULL, 0x495305841924FDD0ULL, 
            0x9AF9F9F3B4B0AB18ULL, 0xA709D39C2ADA3D51ULL, 0xA23948D17EC7169BULL, 0x0491910434B2C935ULL, 
            0x9ACA6B8F5951281EULL, 0x414AEF3F059511C2ULL, 0x299AD7AEDE987F77ULL, 0xF12EFEEF8052B874ULL, 
            0xB01F238526323903ULL, 0x40F4CBBA750A961DULL, 0x4130DB626C10E9ADULL, 0x4C04E378A5B3001BULL, 
            0x19623F48CD9DFD85ULL, 0xC464A72CD822DEE3ULL, 0x44EB00B7C170817AULL, 0xDEE5B31727F8B63AULL, 
            0xB23213E0DC3A9615ULL, 0x58A0A694220EB7C5ULL, 0xCFF28F85C3EA1344ULL, 0xA6016F6CDD315AA6ULL, 
            0x61E0896AC27F12BFULL, 0x231FB78704A65CD3ULL, 0x9FBE5CA15D29C6A3ULL, 0xDC43BAA0F766A6D3ULL, 
            0xC13093FE2F9F190FULL, 0x6884823922D1A4C6ULL, 0x3E131D6D53A29D78ULL, 0xCDF274FEE0CC1C52ULL
        },
        {
            0xC3A4B98C54094260ULL, 0x78E1F632408B152BULL, 0x829C7711F2E72FCAULL, 0xA2F3C69BC3EDC8DBULL, 
            0x781EC31EFE1B42B2ULL, 0xDA861CE6D2B6811DULL, 0x8207E697B7490369ULL, 0x47C7C3B1116D0D1EULL, 
            0x4AD210F2D7B72093ULL, 0x172C1CE48A569206ULL, 0xAA0C4765DC09D464ULL, 0x71D823309A7F8092ULL, 
            0xD8FDFD16F1B49B97ULL, 0x71AFD602B02D642CULL, 0xCC0188DE4D37FED2ULL, 0xC551DDA21EF3B93AULL, 
            0x05C70399B750EE3BULL, 0xCF9DB6393A919D85ULL, 0xB6A3C4F76417A3B6ULL, 0x33D6F8D0EB3E03C6ULL, 
            0x465CAB4DE86F2C2FULL, 0x3A1B145B2A01A3F5ULL, 0x86B5C7D467431A99ULL, 0x8E22ACE16A00E375ULL, 
            0xA187FD59802472D7ULL, 0xBE162B6028980EBAULL, 0xCA85E4D6A99FD534ULL, 0x3AC20DF8060A3AC4ULL, 
            0x658C177EA15E1649ULL, 0x2226AA7DA796B4FCULL, 0x1BA796840CB06336ULL, 0x84AFAF1DCC43D4A8ULL
        },
        {
            0x28175BF3B9B2D5F9ULL, 0xB013B6B9E2FE34C4ULL, 0x44F1070D8AB0685BULL, 0xA177705A0974378EULL, 
            0x39BFCB770FCA38C0ULL, 0x0EDDA2C87B275CD7ULL, 0xB1EDFBFD51BC6A44ULL, 0xD815B789D7132358ULL, 
            0x091FB71F20F73C2DULL, 0x2F5BCF1EE7C67574ULL, 0x0F4ACAF27281C4A4ULL, 0x56CD4F32024BBB13ULL, 
            0x94E8B213C9F66CF6ULL, 0xF67C314CBF42AE3DULL, 0xDD769C505ECD8D6FULL, 0xC06441D6D6A42741ULL, 
            0x9D40C299638CB446ULL, 0x10AF485FD03CEEB2ULL, 0x97B228E3F14E967DULL, 0x831DC64BABC96EE1ULL, 
            0xADC6DC3F7C564B07ULL, 0xEE0C0B29540FAD34ULL, 0x976BF6CDE55A2F90ULL, 0xCB5CCFF82B9B62E8ULL, 
            0xCC86E27338D6B9EBULL, 0x920526E20C258885ULL, 0x2A8215F5954B1101ULL, 0x1649482303617E79ULL, 
            0xB96F45F14DDC5404ULL, 0x31C0A3C436B8BFA6ULL, 0xBD4C6CCA04480A5AULL, 0x94078AAE112A5188ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseBConstants = {
    0x123C362CC82A7840ULL,
    0x70129F7108220BE0ULL,
    0xFB22B455248A99D7ULL,
    0x123C362CC82A7840ULL,
    0x70129F7108220BE0ULL,
    0xFB22B455248A99D7ULL,
    0x91E123A16D064F75ULL,
    0x1CF670E972A04D66ULL,
    0x44,
    0xC7,
    0xDA,
    0x25,
    0x45,
    0x72,
    0xA1,
    0xA1
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseCSalts = {
    {
        {
            0x94D92AFBE31A18DBULL, 0xAFAF65645967328DULL, 0xB97FC6049ABF369CULL, 0xA08CE6A4CCBDB814ULL, 
            0x1703D6EF5703281EULL, 0x4BC97D304FA59649ULL, 0xCF5F1AE56106E145ULL, 0x96790F9700AD3B3CULL, 
            0x05EBA93741BCD56BULL, 0x4E12BEE3BF523124ULL, 0xD489DA7E033445C8ULL, 0xEFCF88C885130707ULL, 
            0x5EB1D9B76CFBED34ULL, 0xF6E4C5BE597E34F5ULL, 0x159065A26D8BCC0EULL, 0x1F95713FED1C8FC3ULL, 
            0x4786FBFE95AB8BA5ULL, 0x5FE969A5029E91C5ULL, 0x0D6C438AF0F75C2CULL, 0x4802D0124EE78E69ULL, 
            0x4635AA8056AD5154ULL, 0xA4471602ABCC0D5AULL, 0x0C652BF1A55EC78EULL, 0x9C70DEC8B44599CDULL, 
            0xD86E7CEF466F9F49ULL, 0x05BDB8D977213765ULL, 0x54C4E7A6D69B2D71ULL, 0x37C7E7B149DF8EA0ULL, 
            0x676A2CC854325F20ULL, 0xE6B8CB584487A840ULL, 0x84DDAF836C515BA0ULL, 0xE4113ED0CD064859ULL
        },
        {
            0x1545CC3723501A63ULL, 0x364FA6C2AF6CC70BULL, 0xEF144261324DA22BULL, 0x4D67B9DC71112811ULL, 
            0xF618B7180E70C48BULL, 0xC83FAC0C7CACD276ULL, 0x62A495690486E3F0ULL, 0x2829D83099B2E6E4ULL, 
            0xF23BF29EC0D7845FULL, 0x2D6EE2009ED9D1BDULL, 0x01F8BC527DEAE036ULL, 0x250CE39601C497F7ULL, 
            0xC88C2FEF19215A17ULL, 0x1F40A3959785BD6AULL, 0x2FEFCFF16ABA0E13ULL, 0x3D2D6A4ED6CD3068ULL, 
            0x22A70BFF8B713422ULL, 0x527D92DC5DB11E31ULL, 0x7D06BE609A442365ULL, 0xBC317836B57A5261ULL, 
            0x87F5447C7B1D68BFULL, 0x330A1C66026A8BE2ULL, 0xC6EC7A75011825ECULL, 0x1503A9FAE2CF743CULL, 
            0xC589A1BD999D02DBULL, 0x469CB3B67CE0EF11ULL, 0x0CE18A03A062036BULL, 0x226A73716CF7687BULL, 
            0x9A7867FAC1785BE1ULL, 0x2DEA31911255F14DULL, 0xC89D3DCA7AE5AFC4ULL, 0xB8ABBDF1EC06BA2CULL
        },
        {
            0xE0EFF7B9BA9DCBC3ULL, 0x1E2582B0F08663C0ULL, 0xDE5338605130D846ULL, 0x859FF44FD26868DEULL, 
            0xB42365A0A9CAE624ULL, 0x966B074682D6B1C9ULL, 0xDE440C332EE5A33EULL, 0xB948F0DA207C8D8EULL, 
            0x4F8D1ACECFDA40B8ULL, 0xCE2C8E85E1BBFB66ULL, 0x048EB22BE20FFF3CULL, 0x1A3495123390F525ULL, 
            0x02C44F4A925F402FULL, 0x1B48FDA7254C2ED4ULL, 0x60CE058E6AA61333ULL, 0x0E9E3A2FF221266CULL, 
            0xC70C6831CBE794E9ULL, 0x5FEB17E49B2B7089ULL, 0xC9931EDCCB2187BBULL, 0x043CCA45714F8FA2ULL, 
            0xB5540C503F5332CEULL, 0xF87910711FE915EDULL, 0x2D8C6B38867CB380ULL, 0xD85707A4C3CC601AULL, 
            0xCE71C7341527B1A1ULL, 0x7DC89FE70F587D38ULL, 0x5F2DCF162A0F11F8ULL, 0xAFE0703CF6547E9FULL, 
            0x2F65444C895E4A06ULL, 0x68F6042C924731B0ULL, 0xBDCF93643C8BA059ULL, 0x5CBA1E1CC1371C04ULL
        },
        {
            0x64C05EBAECC01368ULL, 0xA40A4CE75BC705D4ULL, 0xEBE20E94F91CC54AULL, 0xBC257DF15E095706ULL, 
            0x36B11442EEB6F4B2ULL, 0xD06CA8692FFE60D8ULL, 0x9F4A33A2B859FACCULL, 0x2F2C38738509C2D6ULL, 
            0xA1CAF1D171DA0B6CULL, 0xFFA4B2FE64D51937ULL, 0x3A7158B312A9CE8EULL, 0xC55638AAB22150F7ULL, 
            0x4CC92F93EF14D4F3ULL, 0x4EAC3D9EB4694A96ULL, 0x9D6657BBE11C4306ULL, 0x161C3F2B8D0AD159ULL, 
            0xE30B93BCC116F79CULL, 0x6506919910F925C1ULL, 0x670187622861C6D4ULL, 0xDD20E5ECED523201ULL, 
            0xAFE988B72CDEA08EULL, 0x04D7E82C4A0D4ACEULL, 0x549A440024BA7E68ULL, 0x7DFAF152FCB1E102ULL, 
            0x6CC2FC680751401AULL, 0x4ADBF491E635C315ULL, 0xF6B770F612652D97ULL, 0xE8C9CC4F4BF72487ULL, 
            0x158BE81C92E4B223ULL, 0x74DFD0F69D8319CEULL, 0x698661F0E836289BULL, 0x71D7CA8CFB4CE963ULL
        },
        {
            0x19CA3387242541EBULL, 0xD5635A5EB14BA2EBULL, 0x623314DE7E353BCCULL, 0x6CDD95E0D7F2A27EULL, 
            0xDC0D16EAD879FB15ULL, 0x054559464AD6B1B4ULL, 0xED7724ACCFB3BAAEULL, 0x915F71200FD6CB46ULL, 
            0xA09798FE28560299ULL, 0xD520ADCFB1F75D00ULL, 0x53BB781879F6195AULL, 0x27837CB6B8DC989FULL, 
            0x2D335C7F71BDD74CULL, 0xC5984056853CEB7DULL, 0x121A304D5667C377ULL, 0x41AC533D95797C11ULL, 
            0x37B9FB5BCE73DB48ULL, 0x6ED0425F4E039F9EULL, 0xA7126294F331B7BEULL, 0x463A78EFF948215EULL, 
            0xE3ADBED10E08336FULL, 0x8FD223D44241A0B5ULL, 0x5BCAFE4FB850884EULL, 0xD83F003F59C6D486ULL, 
            0x6620111DC24298C5ULL, 0x91E9E4AF925E9C8BULL, 0xFDB5E6C2E36AE04BULL, 0x4C13EB4C1DE6030DULL, 
            0x6E06A2B39D1674EAULL, 0x5E7B8B4F3D5A5BEDULL, 0x2D45CBF687017A8CULL, 0x09131BAD89885859ULL
        },
        {
            0x3C4423B0B02E9EE3ULL, 0xF932839BB96C2888ULL, 0x689FCAC2C7F269E8ULL, 0xACF1A2C0DDE48BD3ULL, 
            0xE2E78C9F07D7B3C9ULL, 0xC59D1DBE08786D3BULL, 0x166EA211149C212EULL, 0xC1B0EAEAF34E528FULL, 
            0x74D0199A1ADB2B50ULL, 0x633377547D9E611AULL, 0xC6FC945A73AF4803ULL, 0xC3BB26A9427763D9ULL, 
            0xBF382F7D01CE133DULL, 0x69A14C435C5FA45CULL, 0x25B8858720250DB3ULL, 0x660146BA3BFD973FULL, 
            0xB9D6C9253FC32DE9ULL, 0xF8CDB5EFC4A9CA1CULL, 0xDF979DDC44FC6DE5ULL, 0xBCFD0618825B5929ULL, 
            0x144624ADCC44FAA0ULL, 0x8E451F0589B92C6DULL, 0x3FE37F96D3BFE28FULL, 0xF66ADFD4525D53CFULL, 
            0xE70598ACEF0241B3ULL, 0x375BF86F0E5C2DFFULL, 0xB91B709D0A8D4C71ULL, 0x1586302B18E252F4ULL, 
            0xCF4EF9328848F734ULL, 0xDF9B7500472CC145ULL, 0x36223E57FDDB579DULL, 0x26822A13E4A658E0ULL
        }
    },
    {
        {
            0xC1C277FF5AF8B14EULL, 0x087AEB7F2D9516A0ULL, 0xD800021F87BA494DULL, 0xB403E8E77392EFE8ULL, 
            0x7B1B8183FBEBABDBULL, 0xD159D376DFFC1927ULL, 0x7FC5B93989FBBF32ULL, 0xDF691EE5EC9B9713ULL, 
            0xA3514FD6B3D8BD04ULL, 0x5CE361C41F648D67ULL, 0x412C8F28B7BE9D1DULL, 0xE8BABBE958CE71DDULL, 
            0xAB83FF34136D84EAULL, 0xF0C7D2F254E95533ULL, 0x99BA6EF43D1C08B3ULL, 0x2A21CDB5FB65E518ULL, 
            0x10F598BEC5C50654ULL, 0x565873478FA53EC4ULL, 0xB4506DC40D8F9C4DULL, 0x7651572C6E3EBCE9ULL, 
            0x1AA9C79D458664CBULL, 0x0678B799CEA5A5DEULL, 0xE5E31349518DCBC1ULL, 0x6D6967BE441DA0D2ULL, 
            0xE70C66D2053A9990ULL, 0xD6E637AE0D1002EFULL, 0x63999259D262B197ULL, 0xB6D1555F97B8CF45ULL, 
            0xB00B9290EDC55BC7ULL, 0x5AD61DCFD0A422BCULL, 0x35302EA541CEB89DULL, 0x0C48CA2BE97563D3ULL
        },
        {
            0x7374E808655B1DF9ULL, 0xD47CA86CB11AA8D8ULL, 0x15E1C5AA742C53C3ULL, 0x6A4A0998A47D95C0ULL, 
            0xB99605A1878E7AEEULL, 0x69207E1FC8F5401EULL, 0x0DED475F3365BD93ULL, 0x90E6B19BBDA8E327ULL, 
            0xA446A7EA3B1607FAULL, 0x93E08D7BE6B0DC54ULL, 0x7E59AD8DFCC24D6BULL, 0x6892A4D7B18E9C48ULL, 
            0xAC3C2983474BD2ADULL, 0x9F279DD7D2B85322ULL, 0x890B911A7C8141FFULL, 0x208965C3C8B7D697ULL, 
            0xED2E9E438D5D9D36ULL, 0x5BA300A81CFF3C33ULL, 0xB9FCE21C0865A13EULL, 0x34372FE170B0550DULL, 
            0x0EFB67C973AD7585ULL, 0x3BAB629FB2E30F7CULL, 0x7D272DF83F87F47EULL, 0x2A076F560240D5B8ULL, 
            0x80BF79041FB39B96ULL, 0x45BD5430AB804E18ULL, 0xF4227FB58B7D9779ULL, 0xC30F8457DF07E7EAULL, 
            0x978EF85CBCEB8BAFULL, 0xD7ECC4B2D6D87C41ULL, 0xB08F8396D587EE8DULL, 0x7FA7A79F10BCDF7FULL
        },
        {
            0xA1990AE5EB97CC8CULL, 0xF2035B7E80382DC8ULL, 0x699E8D38FA10E7FEULL, 0x001DCC143EAD4D3AULL, 
            0xD42848D0F82155D1ULL, 0x1E7A2D4E8DD64790ULL, 0xA9D5F2758741C4A5ULL, 0x91454246D6481E01ULL, 
            0xE0222263A5FB82B0ULL, 0x5B7C391BC7B41EAEULL, 0x3145F80A87131F0DULL, 0xA4C0D4E3907495BDULL, 
            0x8164D000988DF8ECULL, 0x182A213CFC04710AULL, 0x5290AE5EFDD83A4DULL, 0xDF1C8224EA2643E4ULL, 
            0x72F81FB2246E96E3ULL, 0x657592283148295FULL, 0x2FC40D31039DFE7DULL, 0x25EA7FC1757F4FD6ULL, 
            0x6198AD85BC2E7B44ULL, 0xD4DF5194A25C627CULL, 0x9B364C5B1F8C21B2ULL, 0x974F996662CC72A3ULL, 
            0x3BFDCDF6577E5A95ULL, 0x49D32C6784FE5FE9ULL, 0x96B09FB76CE1BC3BULL, 0xB57B9121E252D982ULL, 
            0x92DECE40BC638E8AULL, 0xF78AAC80330813C2ULL, 0xAD21F2B7D3E9B2D9ULL, 0xC631FA2DDC732111ULL
        },
        {
            0x0336E81E5D241745ULL, 0x14C39DD75D047329ULL, 0x722A8EE2F2DDE7B5ULL, 0x0CE82CA9E4A7A1A6ULL, 
            0x204855CF83F8CB46ULL, 0x57D4F93BA92D4D79ULL, 0x76A6403F501AB117ULL, 0x45077AA32ECE4BB9ULL, 
            0x8C0E0EAF37DE9606ULL, 0x9E898760B4822FFEULL, 0x78425844F95DE9ADULL, 0x9D511B0F33FA398FULL, 
            0x23C5BAE0E52E8481ULL, 0x1A529625CBF58AFCULL, 0x0021CC3B6669070AULL, 0x5503DD493F3509BFULL, 
            0x3656E97B091008D9ULL, 0xEC1C35C687C78D98ULL, 0x5BA16858537C808BULL, 0x7F2E231FD212ED6AULL, 
            0xD4B10FAB2B83854BULL, 0xF08C7929D1C5C239ULL, 0x0B1C78D128B0B70CULL, 0x9ADFE0CB699293A5ULL, 
            0xA2B86CBC658C1801ULL, 0x794015D95B03A4A4ULL, 0xE92D8F9F4C983861ULL, 0x51F83407B3E6E432ULL, 
            0x83453256FEA6F9A4ULL, 0x31F02E1C24C12AB4ULL, 0x2572E7AEE8A9843EULL, 0x401D8310F6D11311ULL
        },
        {
            0x5A72229DA20B7BA6ULL, 0x68D476BBC902DE29ULL, 0x7B3142037FDD2CB2ULL, 0x513250B6CF1879E5ULL, 
            0x737C6A882BC35941ULL, 0x1EE820438A7E9FF5ULL, 0x09941C9B1A4893B9ULL, 0x12A42FC7C2C5DF05ULL, 
            0xF940ECBF79A1DE91ULL, 0xA224DCD11FA7E97CULL, 0x5AB172B2EF5A35BDULL, 0xC36FB2BB9D3F44A4ULL, 
            0xD60E3C1DE313ED99ULL, 0xA0AA5FA1FE37F0A7ULL, 0x6F41A42CA9D6B21DULL, 0xEB0EAC98D17F8797ULL, 
            0x64FEDA92D426334CULL, 0xAE91919C8880C541ULL, 0xEA9EA9EF59AD30ACULL, 0x6206C028B7B2BE24ULL, 
            0xEB070A1960C3394BULL, 0x7A51553896A37A34ULL, 0x3AF5B547E592A061ULL, 0x43A3B11B3CA81684ULL, 
            0xAADEF4FB55686C4AULL, 0x839FEBBA3B7112D2ULL, 0x2F200FA907B475DBULL, 0x3337FBC805D99D07ULL, 
            0x54D180347009318AULL, 0x7750EF9DA6ACA459ULL, 0x342B6D8406D599CBULL, 0x0EEB7D5D4B6BA3C5ULL
        },
        {
            0x5C700E52640240A6ULL, 0x9E2399CCB6B85A07ULL, 0xD1473B50247603D7ULL, 0x597D599451EEAE6DULL, 
            0x2DB8BBC5FC0E7A21ULL, 0xD2AE21B44738B703ULL, 0x7DB8623FFBF045F4ULL, 0x9F1BA20878BC0D55ULL, 
            0x05463C8A6C3DA1BEULL, 0xF4368C0A94A9209DULL, 0xD24BD8439A4C201BULL, 0x9F5261EFE716DB38ULL, 
            0xDBB981ABCFEF451BULL, 0x13A8F55C50C4AC69ULL, 0x509EB7A1341FDC6AULL, 0x1692C4D202CE1C2BULL, 
            0xFCF4AC43AF42B94BULL, 0x65133D39C5EFBF43ULL, 0xCE60C0FE3F6C11C1ULL, 0x12F27DDCB50F8B78ULL, 
            0xDE76A5019D0D718BULL, 0x622E82C65F935F75ULL, 0xA31F227378ADD287ULL, 0xC5ED3D1953499A9DULL, 
            0x09CFF0080E63E79AULL, 0xE8A153A2CB6B3BD3ULL, 0xE608428A427CBDA7ULL, 0xF1687F0365E06F99ULL, 
            0x886D5AAB4842E025ULL, 0xAEE0EEFC2F4326BAULL, 0x43BA04024F6F17B5ULL, 0xF35B3366414D40D4ULL
        }
    },
    {
        {
            0x384DDC74B81A281BULL, 0xAB0B48E13D4367EAULL, 0xDB6ADB2DD227218BULL, 0x822C02BAE8E7AEBEULL, 
            0x1DD38FD9DE8F05E4ULL, 0x6318CBC911EE9D67ULL, 0x84C1FDDEEA0D877BULL, 0xF66472F085DCAF71ULL, 
            0x6AD1620A44CB00F6ULL, 0x5AA57DAF2DA023D6ULL, 0x76035C9616060E6FULL, 0x4D7D10676D7D28B9ULL, 
            0xBF471EAC9FB0762BULL, 0xBDC8CCE7AEBE2B34ULL, 0x7C71B7B13941D438ULL, 0xB5A2A13B2362A453ULL, 
            0x1A54750E785AD7C1ULL, 0xE759841408C8F224ULL, 0x2599DC88E52ABEBDULL, 0xF061CC530455A06AULL, 
            0x8FF7051FE20E41C3ULL, 0xCED8BB7927C33B18ULL, 0x2F52D3E4B9C47B83ULL, 0xDD68439D91F5BA69ULL, 
            0x9D989C324F87A19AULL, 0x6FDF0BBB9A332E12ULL, 0x13C1C93507A4C00AULL, 0x25E8DAB103F51A91ULL, 
            0x6C7D9CB3D4EDDBC8ULL, 0x6AC095F4A2DB1DCEULL, 0x04EED628CB192BF8ULL, 0x2DD76BA86D98AE36ULL
        },
        {
            0xC3F1FC8A6FB980C1ULL, 0x56E4FAF6509C1ABBULL, 0xCDE039450A131A24ULL, 0x0E93B8CC4CBC07AEULL, 
            0x86AA1980895485CBULL, 0x9AF98F6F331CB768ULL, 0xF082692298FB8892ULL, 0x23BE609E5060AC92ULL, 
            0xF4D099E274CA5BB5ULL, 0xA08579076ACCAA65ULL, 0x2EC25C06B17F3AB8ULL, 0x9D186E3427F659E2ULL, 
            0x2FB0FD4FC0BF116FULL, 0x967A33F0DBCA7A8BULL, 0xF6A9EC34E0215484ULL, 0xDDC96B548D7714DDULL, 
            0xBCEB9D0F124CEF1CULL, 0x1D1035C915B9F77DULL, 0x4BAD5A59CF564B61ULL, 0xEAD0049FE8E4A1A7ULL, 
            0xFB355BBC311AAA8DULL, 0xAE2491916DE2BBA5ULL, 0x939DA7A51F86D5BFULL, 0xA83557559772DE3BULL, 
            0xCE054F75445BD9F5ULL, 0xABE90C1E2AFF03C0ULL, 0xC439F5DCAC366FC7ULL, 0x753FFC1CAC4F76DFULL, 
            0xB8564B3358350BC6ULL, 0xD1D3814F37CDEBCEULL, 0x24BB113B5E39E1ECULL, 0x452EAFC71F781C1FULL
        },
        {
            0x81BABAE03CA714FAULL, 0xDF137DAB4A7137C9ULL, 0x66FC0FF64BA3A3FDULL, 0xE8FC3EA654F41EE1ULL, 
            0x4E633B59143A4325ULL, 0xDFC09C62986D2E0AULL, 0x27EF81672948085EULL, 0x82A256B315DE8F54ULL, 
            0x3DC7B29ABA7E8F9AULL, 0xBBF2EFAD584B6671ULL, 0x2FBD8F29A7AA2318ULL, 0x8FEE25BC3A51DE58ULL, 
            0x5E2E9894D1A890DAULL, 0x601E15F18F52D6F1ULL, 0x6C9CE0C1E65A6E84ULL, 0x30DBC6F6B276FC50ULL, 
            0xAD14224EF36B3971ULL, 0xCF982B1C1B4378D6ULL, 0x83093F0772AF76FDULL, 0x6C61CA71FA6C2744ULL, 
            0x6B3C5957C0140DE5ULL, 0xA9D8A95A2A4F3E07ULL, 0xC2DC4E70C55B8E51ULL, 0x6454E715778F5EF3ULL, 
            0xEF6CB690C9B53998ULL, 0x08A03280CDDA1E54ULL, 0x936A014B40C4B7FBULL, 0xE5238288311FB992ULL, 
            0xF3BA793A1C39FB76ULL, 0x58369A4302EAFDC2ULL, 0x9ADFA1DBBB433C79ULL, 0x4369EFCC90D5E748ULL
        },
        {
            0xC200989725741185ULL, 0xEAC775538B1A5AFFULL, 0xBE3C3838C7967982ULL, 0xD934791EF76D71C7ULL, 
            0x32E9831764099199ULL, 0x09D603F42E56E3E9ULL, 0x025591A805F029F0ULL, 0x7563CCA3D315C124ULL, 
            0x7B073791DC14AB3CULL, 0x06C08245B3085E2BULL, 0x9B5CD8400D1C1DBCULL, 0xC191C73FE236E50AULL, 
            0x71D2660CE90D0989ULL, 0x9EEBA4ACE38F1EBFULL, 0x87063995D4B37E49ULL, 0xFD616C0B6898077FULL, 
            0xAD0A8D7A72E9C8C5ULL, 0xE896F96422BACC30ULL, 0xA9D0429E08BDE306ULL, 0xB6517383B37821B7ULL, 
            0x70A0277D3254C106ULL, 0x70834B1ED8CD04E8ULL, 0xA9A5919A13A86D52ULL, 0xFE5F2F9DA4600C35ULL, 
            0xC3AD6D50521B3063ULL, 0x71BFBC2B33D69628ULL, 0x7676D0ED9A0D9C42ULL, 0x0EDE2F16767E3A7DULL, 
            0x449D02CACFD3A506ULL, 0x66B7F9B5C69C8528ULL, 0x1E4481F64DBBD43BULL, 0x7C87FFFEF7476DA9ULL
        },
        {
            0x7AFC0C067C997DE2ULL, 0xBC3858BFD0E4FD32ULL, 0x1527BC5418C569CBULL, 0x60470AE8E24E5A65ULL, 
            0x09FBC9C2A50250FCULL, 0x09399B31F3ADB35CULL, 0xCD58B617DC241607ULL, 0x7C49BAA14010780CULL, 
            0x0E9D2A27FD0B723DULL, 0xB923BC605AE56BFAULL, 0x14B1ADFAFBCF3307ULL, 0xEC2690EC072C85C4ULL, 
            0xA9E8AB566C7706E6ULL, 0x9BBF4B982FF0B089ULL, 0x0FE3EAAD4F54AADFULL, 0x07F29673EA7E545CULL, 
            0x9B8D4670C6293D49ULL, 0x87A867554C7AF85EULL, 0xB00F985F2BB635DCULL, 0x062684FC7CA5FB96ULL, 
            0x829E50BF073B7A42ULL, 0xF166B681F876A38FULL, 0xDFD3F9D5303255CDULL, 0x17EBA40A2B8C0B56ULL, 
            0x5D47018D2F9285C9ULL, 0x607801CBD27B3A8DULL, 0xE348F2CF22785E6AULL, 0x8890D0680E26A8A4ULL, 
            0x9E6FAFFBAA4E9202ULL, 0x5E347418036F808FULL, 0x42211E2C65A36EE1ULL, 0x6DC2AF4CFCF01155ULL
        },
        {
            0xAC2837D4F6E77B50ULL, 0x911A0594065F27A5ULL, 0x54C0898814BD6235ULL, 0x8E110F8B6EBFDB9EULL, 
            0x648A7302F3C90DD3ULL, 0xFC18902D2AC88D43ULL, 0xF7F8AA5C17915EB7ULL, 0x5DCB77A0E3EA6F75ULL, 
            0x2556FDC3D54B264AULL, 0xE3CF0B47544845F7ULL, 0x339EC2167A9013A4ULL, 0x05FD8F1ED8EF48F5ULL, 
            0x2591AE0EC66A2AD4ULL, 0xF417018D204F95B3ULL, 0x6CE2508894E31829ULL, 0xEB3821F3D66FF32CULL, 
            0xFDC8E1D66C3B6235ULL, 0x9F9F5E99D7B7FC0FULL, 0x7236CC56E43110B0ULL, 0x5CD2608B3EB74532ULL, 
            0xD501409806F390C7ULL, 0x57638D8D29BA9586ULL, 0x450D054B31A436CFULL, 0x83DC2ECC6DF68D84ULL, 
            0xC66A569D0FE9A0E5ULL, 0x8761DCECE6062DFAULL, 0x6984B5C45E51A284ULL, 0x923F5D2882909081ULL, 
            0x8B2BE5183E6E3193ULL, 0x64E78F68C394E449ULL, 0xBD0E038947BD05F8ULL, 0x11B4B095C8319DF9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseCConstants = {
    0x6D4ACB32F3F2973CULL,
    0xDDEC5898A4195ED1ULL,
    0x5BD331531AB6CBA9ULL,
    0x6D4ACB32F3F2973CULL,
    0xDDEC5898A4195ED1ULL,
    0x5BD331531AB6CBA9ULL,
    0x0C996E6E2E403B3AULL,
    0x87A270595508D44BULL,
    0x18,
    0xFA,
    0xA1,
    0xEC,
    0x85,
    0x8A,
    0xD0,
    0x3F
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseDSalts = {
    {
        {
            0xB7DDEA6CE4FB6039ULL, 0xB7B468F241C8F663ULL, 0xC4468C4B1BC9E667ULL, 0xEEC3E72214A2F573ULL, 
            0x9A5A9874115DB434ULL, 0x03A4084BDF8CD784ULL, 0x8CF1B3B60D001A0CULL, 0x5F8C84C1EDE3269AULL, 
            0x462875EFD7938A5EULL, 0x9BE5EBC60CD863C7ULL, 0xE8A07BFFF26C17F9ULL, 0x442D73B9B1A48105ULL, 
            0x1CA7445F90C0E431ULL, 0x2E73958C98088F8DULL, 0x1A9B8BDB0EEF4113ULL, 0x95F559901CB90220ULL, 
            0xB6BD8DC154F1EB43ULL, 0x1358B8D11C2A86D8ULL, 0x76BEE68138016EFBULL, 0x94A8CA7BB1362110ULL, 
            0x764672ACC79A4BA9ULL, 0x3DF23D4B4A9880FBULL, 0x872A9CEE4029E998ULL, 0x333A8CB7A3426446ULL, 
            0xF6DE20E3696D22AFULL, 0x3CD5E1BCEEFCD351ULL, 0x6695101A5F264BDBULL, 0xCC69E42F020A3113ULL, 
            0xDB71AC3F2EE4BB4CULL, 0xA67B1911B23067DDULL, 0xD41D906A91B88675ULL, 0x320477C17C76E2B8ULL
        },
        {
            0x42E27AD0C5B6117EULL, 0xDDEA201CAFFA7C37ULL, 0xC5FC400A48F4B0CCULL, 0x9EFC0E00E3DE22BBULL, 
            0x3DDD5B49FE0479E0ULL, 0x46EEA1944CCD8578ULL, 0xD624B520EBC55362ULL, 0x91E2897D2B47543CULL, 
            0x96DE12BFCAD3B28FULL, 0x64E68FC75AB71390ULL, 0xCD503F5CEBC486BBULL, 0xE3A3047E3C7310E0ULL, 
            0xE95C1AA9370F079FULL, 0x25A50EC964179F2EULL, 0xDF36A881876FCC20ULL, 0x6FDDC7E9958E1F50ULL, 
            0x50F5250D7A4B7203ULL, 0xC3947D74E040037AULL, 0x847AA616465F5639ULL, 0xE736795F8CCC802BULL, 
            0xC05FF441C57D8B78ULL, 0x1B6C94DD69CE3E67ULL, 0xDD702337C7F43FD4ULL, 0x2E6957425655772BULL, 
            0x1DBD92E021A80FE0ULL, 0x7FEB7297D6BBDD44ULL, 0xE714844984D7053AULL, 0xE056231ABEEE691FULL, 
            0x3F157478DFF47338ULL, 0x8DF2E2FA2A4758A4ULL, 0xBDD1577F550D8EF4ULL, 0xC9151742499BFBECULL
        },
        {
            0x011840EAAB0F8164ULL, 0x9940CCEC8D67B811ULL, 0x1CDB268D5453485CULL, 0x569E2210954512DDULL, 
            0x77B7E8F5D114EA3BULL, 0x24BA2DE3502B27A6ULL, 0x19BEC0394120B7E7ULL, 0x128C71877A8CA072ULL, 
            0x2099FEE0F8DDF958ULL, 0xEFC07D101507339AULL, 0xB734783D835D7977ULL, 0x361F84C72D196765ULL, 
            0xB105181344797F22ULL, 0x6AC7B2DF0D487766ULL, 0x9D7B809A7F24C154ULL, 0x2CFCE63C215F76FEULL, 
            0x8E1B3BFCBEB90A8EULL, 0x26C649C196AE823BULL, 0x78C264A248F41542ULL, 0xB57F3BB5164A523AULL, 
            0x1C5BCDDA78F32DC8ULL, 0xAF151E6E43513C13ULL, 0xA4177E0D290DDEF9ULL, 0x587A4669C29F2607ULL, 
            0xBE153E9A540E801EULL, 0xB062593B4B979A6FULL, 0xA282A8B9F2FF9FA3ULL, 0xA5C3F8927713D699ULL, 
            0xE54D41209902963BULL, 0xC1D6C92B2F7462A5ULL, 0x089D273C937A53D1ULL, 0x4447031681387FEBULL
        },
        {
            0x951B7C46A797A073ULL, 0xE999AB784240A007ULL, 0x6B39FC7826C26A14ULL, 0x54884B848E766EB3ULL, 
            0xDB63A30B1247423EULL, 0x054A5619529165A6ULL, 0xA5E3850670C4D88DULL, 0x915ED8352F52EC30ULL, 
            0x6C56FE2F2278F473ULL, 0x5509E4239D083DE5ULL, 0x0D61E9043B1E0FC0ULL, 0x92F7B2B10C58AD32ULL, 
            0x86D0CF6F746C3C36ULL, 0x5DACBA0E982178C0ULL, 0x5C22FBF8898D2FF6ULL, 0x2E2EB93B185FC5ADULL, 
            0x98ABEF6E2C8562ADULL, 0x76EEAFEAE4369EDBULL, 0xF24B00DBC3E255A7ULL, 0xFFE9402A35BCAF7EULL, 
            0xA0EF066875C9EE00ULL, 0xB9BF6B55D664CDBAULL, 0x6E68E339F5143C88ULL, 0x89C2BC53AFFB66AAULL, 
            0xEFABE1B0335E0C53ULL, 0xF3E2CE7C5B6C3D66ULL, 0xB0CA146C376117E5ULL, 0xF39EFFF93073BA41ULL, 
            0xEDA9E4CD149C179AULL, 0x265A601F10888C44ULL, 0xEA42926C11ED3C2BULL, 0x045638DDCB9AA84BULL
        },
        {
            0x425583DC2703C02CULL, 0x29E8493A13B043EBULL, 0xAEAF5CF049CA9CC8ULL, 0x8CEC1EA4AA02445CULL, 
            0x8D119262FFC06BC0ULL, 0xEFAE30291306A0DBULL, 0x528A90FCAAEDE9AFULL, 0x7C55893993A0394EULL, 
            0xD034B23F409504E4ULL, 0xB6B43A76E0486DC2ULL, 0xD080305A61B55BCBULL, 0xE45BBF4F06F3DA6DULL, 
            0x2C2368D25075EC2AULL, 0x63D57D38FFC3E930ULL, 0xEAB9BC04926180A4ULL, 0x202F66E915E4DE1DULL, 
            0x5BED54CFCBC110D9ULL, 0xFEDB638D44122D76ULL, 0xC51E1A64F2FB8B4CULL, 0x3C36D88749424FC8ULL, 
            0xCEB01911D33C9AE9ULL, 0x2C77884E731DCFDFULL, 0xC1672D5DC83D7777ULL, 0x65016D037A67D5CBULL, 
            0x08F4004BA462620CULL, 0xFD6E710F6A508A8FULL, 0xCF4519B77BAAF525ULL, 0x8A8688B61ABFE440ULL, 
            0xEC56683793DC1945ULL, 0xF23E2C4700740486ULL, 0xA7E00588BDBF54A4ULL, 0x39BE030EC33303D0ULL
        },
        {
            0xC42CC75FA1CB5C9FULL, 0x1CD07710D5D90159ULL, 0xE1828EBA285B9F44ULL, 0xAA6D3CA3DFA1BE3BULL, 
            0x60B3618BDB371490ULL, 0xF96A8B8718E4B15DULL, 0xDDFDC75C7C97585AULL, 0x91078CBF44C9D4E1ULL, 
            0x8DE85176E5C70FA7ULL, 0xAC8CDCD2B497B18BULL, 0xF8C021A1F62082A7ULL, 0x207DAF93C87B0FE1ULL, 
            0x208F366AA1CFDE71ULL, 0x8A907315241E2639ULL, 0xA5141CA32ED0C2D2ULL, 0x70D8E6476888F80AULL, 
            0x70862778DB1F1504ULL, 0x49CB1A4909E5E2C4ULL, 0x2CDCF22170B5EFDBULL, 0x63072ED90C7929ABULL, 
            0xA74BB5B5FA0E15B9ULL, 0xF8D046F39FA38B01ULL, 0x36F8DE9D90931430ULL, 0xD6072693A257A8B8ULL, 
            0xB89F299252BF31CDULL, 0x5C8D6FF912264A22ULL, 0xDFAAC6B51B8DF10FULL, 0xFB27C95BA4B02653ULL, 
            0xA97B0B50407BD7CBULL, 0x9CA418ECE0B15644ULL, 0x0066DBB0EEDD007AULL, 0x26DE4A4FDD395CFAULL
        }
    },
    {
        {
            0x74C4F35EF0486208ULL, 0x282C3079F359940CULL, 0x7E10A805DA6CC942ULL, 0x948283B1E84A4A8CULL, 
            0x0F67D5D8256567A1ULL, 0x4ED6330B996F7BEEULL, 0x3012EF749D2D6695ULL, 0xFEA53932810ED332ULL, 
            0x513FD03470BC440DULL, 0x50CF20DC13BB9F5FULL, 0xD99FF5D32A4A4651ULL, 0x1E5367FD97744E8EULL, 
            0x9C43EF06E922916BULL, 0x3AC8C77489DB719AULL, 0xF6CE476D468FBE36ULL, 0x5C6C52250AA342F4ULL, 
            0x2184793E30DB1ECAULL, 0x9D8E702461C12286ULL, 0xC0C6102921081102ULL, 0xC8702D57D2E63A8CULL, 
            0x76D1BC6C79A5BA93ULL, 0x13E2DE8FB5D2E80CULL, 0xA465305FF9602A37ULL, 0x14C270AAB37AFA09ULL, 
            0xF1EB13B8C767736CULL, 0xBE338FC01972E6D1ULL, 0xBC0492B09E508303ULL, 0x7F50114EB82DC71DULL, 
            0xC6B3441E81DE0C65ULL, 0xCB45FF890820E69BULL, 0x9F913DAA40528B7EULL, 0xB9949DD8AB41D7B8ULL
        },
        {
            0xB6746B2EBA66FFD6ULL, 0x0BAF3370948BA8D1ULL, 0x95385D2141EAAE18ULL, 0x93EBB74480C5C8B0ULL, 
            0xDD9E68C8685DF9C4ULL, 0xC1374987E26165B2ULL, 0xF9268AE6015BC5A9ULL, 0x0292D453D452C6C3ULL, 
            0xFA7C932DFBB059CAULL, 0x9D0FDAD2DA5FFA86ULL, 0xCF20B8B2B028D58AULL, 0xCF44E6C5EBBE5F15ULL, 
            0x2EF893752194A02FULL, 0xD256E1534AAC53A8ULL, 0xF4F43DF2CADC615EULL, 0xDDEB516907B2D119ULL, 
            0xDDECECBBF6C8D3ACULL, 0xD9FC5D2187390CE8ULL, 0x381871C662298817ULL, 0xF14E2955B3D01FF5ULL, 
            0xDB71E3708E8BB948ULL, 0x31A4681633E046E1ULL, 0xDA9FB365939045CFULL, 0x234539F711162C0AULL, 
            0x85478BFA5F5679D8ULL, 0xD817FC613CFC0485ULL, 0x2EE351BAC7ABAA34ULL, 0xBBDC92BC58F39563ULL, 
            0x0ACCE664FDE53D68ULL, 0x06A05F58D7104B65ULL, 0x83F6D786BBBC9411ULL, 0xCEAB93684DB0BD1AULL
        },
        {
            0x20438B49F34101C6ULL, 0xB4454F9178375A60ULL, 0x8190B65A834E8DCEULL, 0x079B378D653DB538ULL, 
            0x5B9860ACF837577AULL, 0xDEC3DE22D9D75085ULL, 0x63002B940BBB7845ULL, 0xB9F837DBAC8D0C82ULL, 
            0x168F8F176BF8EE7BULL, 0xE0F628E3A8B7409CULL, 0x0B4B437299C8DF55ULL, 0x83B4FBE2F714D858ULL, 
            0x51803FE76ED6F3FDULL, 0x05E154145D8944E5ULL, 0x3BEEA342B88247DFULL, 0x66559CA313038045ULL, 
            0xB7F38B619E0C19DCULL, 0xFE4E0A6021FF00E1ULL, 0x56F0E6B4B6AA8727ULL, 0xD44D58F6541F6836ULL, 
            0x7C30427B5E52E486ULL, 0xE4538F3D530B1631ULL, 0x269EF9CFF7904CD7ULL, 0xDEDBBC8387949A96ULL, 
            0x1E26101BA6A12315ULL, 0x6CE90046B9D9EBB7ULL, 0x62315BB423155B67ULL, 0x3D4858DFC6968DAEULL, 
            0xE3752F9A329FA9AFULL, 0xE4A74B633D846021ULL, 0x8B069C956B11E0FAULL, 0x2A62BB5F9D47F540ULL
        },
        {
            0xB8A3F309F8F8F3C9ULL, 0xAE8E25081DF3876BULL, 0x44ADC3999A3AAD3DULL, 0xB6FECD64FC0523CCULL, 
            0x679310C9E731602AULL, 0xAC5233D1630E3B0FULL, 0x870D8994B90CA743ULL, 0x6591F427620F6EDCULL, 
            0xDBA5DA4BFAC664D0ULL, 0x5144A68ED9B3710FULL, 0x652AE3517193DD27ULL, 0xBB6064DBB4F00013ULL, 
            0x1B525005011F65CAULL, 0xA5179B032059834AULL, 0xD9CF9022A697D0F7ULL, 0x5F3F54294C591DFFULL, 
            0x3EC553631CE22192ULL, 0x30CFA16A82450540ULL, 0xC3467DFF240F5D6EULL, 0x12FCCDA8DC6D769FULL, 
            0xCB06548230E872C2ULL, 0x4541D73C70F4193EULL, 0x51445BD39C182EA2ULL, 0xDF8A258F03CC972FULL, 
            0x689559AAFABF3303ULL, 0x744E1A5B5C71189BULL, 0xC9E3E5726CA8B551ULL, 0xECF7F82205C0E5B1ULL, 
            0xEFFCB9107346142CULL, 0x07599913B77C1C30ULL, 0x55C97A6137D2EBC8ULL, 0xD88F1993C8393971ULL
        },
        {
            0x2B976715EE5A8987ULL, 0xD152F239A9818A4EULL, 0x3D054347D847D044ULL, 0x2CA49B7844B136ADULL, 
            0x5E06FB7CFF6C6F6BULL, 0xF61B9E5987CE09A5ULL, 0x48D0F3340FFE58FFULL, 0xCAE93F53B0553B3CULL, 
            0x41CAA51FFDC3D3CBULL, 0x03D4A73AAA20F226ULL, 0x10DC7208C16029DFULL, 0xDB48223EB6C3E964ULL, 
            0x4947B012F5848EA5ULL, 0xD164322A758267EAULL, 0x73DF1649E7B7AA6FULL, 0xEBE3C4FC37981E55ULL, 
            0xD2749E7197EA803BULL, 0xCD15E942EBFD8BE4ULL, 0x7C817A4DC8ACAED9ULL, 0x6B5AF587449EEF83ULL, 
            0x0D58841D49B07D54ULL, 0xEBDA8FAA6E61BD50ULL, 0xAD44DDF3E55A85EBULL, 0x78F48B5F67295DC5ULL, 
            0x50204E9E5811C096ULL, 0x66004623D4AA6A70ULL, 0xF1AD7B285396963FULL, 0xED5BE1DE2909E9EAULL, 
            0xAB60DE72BB2D6447ULL, 0xDF9A27330861488AULL, 0xA801480284321F34ULL, 0x350ACD0E9D8C06FCULL
        },
        {
            0x16CF5345753A498AULL, 0xD29F93CFE0BCCB36ULL, 0x85BFAB8C2441201EULL, 0x25BEFFD1F1402638ULL, 
            0xE1040E246BB6DE92ULL, 0x819178DC3780D68FULL, 0xCFEAC6AF62AA6A14ULL, 0x9F2EF9C27FFEFD56ULL, 
            0x31E28D0FFD21DEFEULL, 0x64D9153F450E69AAULL, 0x2F489E93EA90DA89ULL, 0x000421B4C9757C17ULL, 
            0x5E99F4A8AF26E83FULL, 0x8FFE5E9AD8BCE204ULL, 0x91E7694C0B2A40E5ULL, 0xF36E74EC74F51761ULL, 
            0x8E118298B44DA79CULL, 0x5409B4B932D5544DULL, 0xEC8E66D3D01B977DULL, 0x01960F94757EE79CULL, 
            0x402D30269EC368B7ULL, 0xEE2C1B78A3E80886ULL, 0x056351CBECBDC91CULL, 0x1D22B34402E088E8ULL, 
            0x89AF915B5097141DULL, 0x6E140C942C9A8F7EULL, 0x22FD8A10C159C63FULL, 0xEC44DB7C2E69C43CULL, 
            0x338D6AA70A1BA2A4ULL, 0xF840BC459A78F57AULL, 0x9A759FC1C864EF1EULL, 0xAE8C44DDA0A8FA60ULL
        }
    },
    {
        {
            0x9C094BC886992BE6ULL, 0xF8733AB406EFBA4DULL, 0xFEEDC40A2EFC5F62ULL, 0x56976DA7E96F4659ULL, 
            0x64164A36DAF146AEULL, 0xDC686293EB543ABCULL, 0x1C52CC84A83A91E4ULL, 0xD92E79B87CC7BDDBULL, 
            0x26AED3A0D72AE059ULL, 0xD89C748F88A926B5ULL, 0x27EAD7CE3AF228AAULL, 0xEB82F06C513CF61EULL, 
            0x6F0FA66F325FCE48ULL, 0x88E1E018BDCBE5B2ULL, 0xC5BAD140E38F0DA5ULL, 0xBC71C13D650C9B5CULL, 
            0x2112B5C6CF3333B7ULL, 0xE6FB62C66DCDE774ULL, 0xB2DF3593C403AEFCULL, 0x4903A06F869F9A78ULL, 
            0xA9E649F51E488740ULL, 0x9D5ACAE73A44A558ULL, 0xAC00C7D65E95941DULL, 0x7D9AD68000A3D3A8ULL, 
            0xBFC6B0D9D37D606AULL, 0x956CF81755CA08A0ULL, 0xE3A563277958BC78ULL, 0x32FE4FB4D6C005F0ULL, 
            0xD4324D93D6B32467ULL, 0xB164B3484869881CULL, 0xEDEEB0CD37C656BAULL, 0x598C737095BE6400ULL
        },
        {
            0x71A9154BCCF78A31ULL, 0xDBD4CD51D87CAEB9ULL, 0x260DEB63279A309CULL, 0x19AAB2A95D1649E3ULL, 
            0xA0F4CC74A8C65E70ULL, 0x284504934C161537ULL, 0x998ED5058E7B1339ULL, 0xD86072159ECA0607ULL, 
            0xCFDB71937AE0CB74ULL, 0xCA8EAD2C45E01D34ULL, 0x60F0B4B9784BAEC8ULL, 0xFFD1886EEAFB7854ULL, 
            0x0650FCA46E713853ULL, 0xBEC46F6F8C315365ULL, 0x75716AE9C2B2EB27ULL, 0x8F296A4993643909ULL, 
            0x8635E03FD50D84D5ULL, 0xAE1E0A6A4FD3EEB7ULL, 0x540D0A02F3F2E9FAULL, 0xD979E55E4A808626ULL, 
            0xC890BC107783E24DULL, 0xB2F04A50A7C11C16ULL, 0xE2BA2EE7EBDAB7E2ULL, 0x4145DD8275CACC0FULL, 
            0x37A60A45080498E0ULL, 0xD80901AB138FF227ULL, 0xD69C51B5F00FDC94ULL, 0xEBB506558F11EE66ULL, 
            0xB9D21D28B530F37AULL, 0x45087DE950B24589ULL, 0x5171DAB87B2D3C5FULL, 0x58C898B18FFD8709ULL
        },
        {
            0x899E7E967B15CCABULL, 0xC4C4F39F5C54563FULL, 0xC351560B95906427ULL, 0xA9ADD47035A96A84ULL, 
            0xE018CDA1971172DBULL, 0xE493679A7EB483FAULL, 0xFC2EFAD5B78C1AC7ULL, 0x7F005938BCC6979BULL, 
            0xE30864377F89FD53ULL, 0xB0CF6735CB9600CCULL, 0x8FB6F59914E7CBF8ULL, 0x241A606FB9E44B3DULL, 
            0x3FA10567133F360CULL, 0x319ED11D49B8716EULL, 0xD9606D460F8B73C7ULL, 0xF2BF1D03DBBEAE0DULL, 
            0x65DEDE65C03114F2ULL, 0x8A236CBE02C9CDFEULL, 0x64809AAC644101D0ULL, 0x98E0818707C36ACAULL, 
            0xC230C495A8A8A9B2ULL, 0xEF186CF6B383BCB8ULL, 0x8687EBD121CB10F5ULL, 0xDEC8DF45E3D653AEULL, 
            0x3B9B122CF017BF14ULL, 0x59D51FA33C857A0BULL, 0x621E271B66FF4BDEULL, 0x500976A265B90529ULL, 
            0xBFD7AEA10D5E0058ULL, 0xE7F82C53C47F9A62ULL, 0xBAEC9A1AE2B3AC80ULL, 0x23E3FE841F5F4E08ULL
        },
        {
            0xF18FAB50A41C2E92ULL, 0x3EB125096D3B8271ULL, 0x3649EE2C4E6BF168ULL, 0xFC17714674D2F7B3ULL, 
            0x035ABFF0AFEE6E26ULL, 0x607928C07B82DF5FULL, 0x527FA0432F8DD9BDULL, 0x342113D40F215B0FULL, 
            0x122A401565A22C50ULL, 0x582BF5C31BD52BC1ULL, 0x8A081FB2E3987055ULL, 0xA097584FF3FE86A6ULL, 
            0xD4DEFAD1CB4090FCULL, 0xC59386CC7D81AE25ULL, 0x574F0E7545213DB1ULL, 0xB8CF48D262418354ULL, 
            0x35D95CD32E51E164ULL, 0x27B800538761B2BDULL, 0xC2006D4E320EB1A5ULL, 0xEC5E9EAA392E2F1FULL, 
            0x72D98F8CE44A6508ULL, 0xC292B262B65DD2D2ULL, 0xCFAF4F743711F586ULL, 0xD2120B0E85400FEFULL, 
            0x8AF5AE346F912891ULL, 0x83449BF86B8A0A26ULL, 0x3BC9934113DB6E1EULL, 0x5FD7AB8DFBA6DE78ULL, 
            0xF815041411D5625CULL, 0xF9B73246C918996BULL, 0x293BD68F45D7380DULL, 0xE849661FB44EBB3FULL
        },
        {
            0x20CA2434560D86E4ULL, 0xCEBC00DF36BE7EFBULL, 0x6D8BB3B7BEFF15FEULL, 0x8CB97978D7A841C6ULL, 
            0x3812E0C32014AA26ULL, 0x446B4368A9EAC8FDULL, 0x017D70B45483A476ULL, 0x5AA3EC5295AD7C7BULL, 
            0x8AC552189ED4A401ULL, 0x065C1D551FA8D478ULL, 0x6F9E1629B8E8009CULL, 0xE9DD6B0215634DDCULL, 
            0x7EB56472DD47DBF5ULL, 0x6996DA60CD31A34CULL, 0x686691BE5370091EULL, 0x851780DB010E52AAULL, 
            0x1773636EB405D2EEULL, 0x9378705C36213F92ULL, 0x0858ACD21A6B1A5AULL, 0xA3E6564BF3FD0378ULL, 
            0xE074F4E20A72A039ULL, 0x21BFFBEFC6F1E305ULL, 0x38B3411D841693BDULL, 0xCE512C5841FAE66CULL, 
            0xE5A9EFC520B17EEDULL, 0xDB283F252538274BULL, 0x67E61643598B49C9ULL, 0xB6E3CFBEEAA6B40FULL, 
            0xD0873C2C6A3B05B9ULL, 0x1A2472F8BCBCBC57ULL, 0x830731F84A5B9D76ULL, 0x840967DABF418918ULL
        },
        {
            0x85AC6C0F398A8CADULL, 0x372155E1C0379664ULL, 0x5871E9C6FF1A4F93ULL, 0x37392FCDB30E41CBULL, 
            0xF223D2557DB42808ULL, 0xE43F1145D3C33F98ULL, 0xA419FC1009514698ULL, 0x2A0747C8ACDAE4C5ULL, 
            0xB7E119DD23E114A1ULL, 0x269AEB7B4A0F5A5DULL, 0x80A28C3E400BF66DULL, 0xC9B4132577B1B9F9ULL, 
            0xB4918D9CE221AC47ULL, 0x1C95D849F9F57AEFULL, 0x90EA4DC46F2D507EULL, 0x0D0F67CA7D6716BAULL, 
            0x2DDDCA1D86A7A93EULL, 0x5DE3B0A82485D410ULL, 0x4F958367A834CCF9ULL, 0xE5DFB0CED7364440ULL, 
            0xAECD7811045A842BULL, 0x4C774FACA1D7B1B3ULL, 0x9E3A0D9A7A8D4AB3ULL, 0x9B17C8A77133F64BULL, 
            0xCB7C7D9DF7081D12ULL, 0xCBC68E46A3FD3F4FULL, 0x41BDCF8518E32CA5ULL, 0x7DA2D632FC9C79B0ULL, 
            0x47BF2A2A6C02618AULL, 0xB59AB15A63F696F4ULL, 0xCABC083F46CF3FABULL, 0xC786E5B02D0530F5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseDConstants = {
    0x8D8FA07F71F3880EULL,
    0xA7D9DEEA23AFF625ULL,
    0x50DFF22AE2E7A74FULL,
    0x8D8FA07F71F3880EULL,
    0xA7D9DEEA23AFF625ULL,
    0x50DFF22AE2E7A74FULL,
    0x46BC8266A91A59A4ULL,
    0x11BBE32E07235F71ULL,
    0xEB,
    0x83,
    0x48,
    0xC1,
    0x77,
    0x68,
    0xEC,
    0x90
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseESalts = {
    {
        {
            0x0D40C8A53694A86CULL, 0x8469E3611980FC0BULL, 0xA0E15057F01DCF8AULL, 0x2BE8AFEA4A786E20ULL, 
            0x338566778C63757CULL, 0x31C18EE7AD2C2C31ULL, 0x665CAC4B7AD4DB9BULL, 0x01DEBC42764DD5FDULL, 
            0x7871DC502521CF32ULL, 0x6A0F52D7DDF52AEEULL, 0x9F4425780542782CULL, 0x09CE3ABE8F6AA149ULL, 
            0x0BB125F7364DE80BULL, 0x723E195D5E0C03B5ULL, 0x64CCE5C9790F9819ULL, 0x31FA9A3779FA3E60ULL, 
            0x3AA13D1557392EF2ULL, 0x1F2AC88D0E6E7B7CULL, 0x1F8DB7F3CDBB9D28ULL, 0xC98D6AAD94544030ULL, 
            0x34085888F488E73EULL, 0xD9158B9DEE424ABFULL, 0x6BB059FDF4FF9C04ULL, 0xED32ABE0E33F14F5ULL, 
            0xAC8C7E79E45BE19DULL, 0x1572CAD3B06D9969ULL, 0x8A2153FA361B38D7ULL, 0xAF3BE9FFAF084EE0ULL, 
            0x91AA3B5EAEDF6E8DULL, 0x27BFAB50CB6E3195ULL, 0x79E9AD8A1164F75DULL, 0x83FCB7BDF51282A7ULL
        },
        {
            0xF5DF75BF071B7DD5ULL, 0x09D4590542B66870ULL, 0x58FCC38278BB7138ULL, 0xAC6B98AAD26AC189ULL, 
            0xFEE0C3E1EABBA0A7ULL, 0x1C29EE44048B98EFULL, 0xC4EE07F3845DB67AULL, 0xA5E223558532374CULL, 
            0x97F7359B106557EFULL, 0x52A48F430CDEACD8ULL, 0x47563D634A104A79ULL, 0xC3C13424E66DC04DULL, 
            0x0E7007D9EE832262ULL, 0x819B254C389E95ECULL, 0xB6DBABC8337D2298ULL, 0x8589D26EBE2BF7FAULL, 
            0xA9523721A6B713E7ULL, 0xEC43D9B68863A2C1ULL, 0xCEE8B5B38D146F1CULL, 0xB934CCACC001507AULL, 
            0xAFC0AAF4C6130CE3ULL, 0xF354C3F65C8BE575ULL, 0x800E44D66F165422ULL, 0x1B3A8BE3C6E6BEB7ULL, 
            0x35C7681BE7960E4BULL, 0xD4BF592BB3D76F70ULL, 0xB69DAE44A638354FULL, 0x9F779CC0264363B8ULL, 
            0xAADD2C6B44125F9BULL, 0xE3AE0019CF527441ULL, 0x60E17FFC0F912507ULL, 0xF64A61B6FBD2E5D8ULL
        },
        {
            0x963F83D17F28F09CULL, 0x30C78916D26C6A37ULL, 0xC1F2FCA28B2297F9ULL, 0x5E4901F51B01B5EAULL, 
            0x678F5087CBC388ADULL, 0x4CF9B63CDDD10332ULL, 0xC9A3B3C27FAB3A6EULL, 0x97E0CDE869EC1D42ULL, 
            0x166850EBCA7109D0ULL, 0xE78B0827CACA4DC1ULL, 0xEFA800D5930BC86EULL, 0xFE05FFD5920748FFULL, 
            0x3B140C7C10E9BB56ULL, 0xB52926EDDBB67B54ULL, 0x4B269E57225E1E0EULL, 0x1E1024502A1035EFULL, 
            0xD0EFE1AA42BE3273ULL, 0x178694A09634AC4AULL, 0x6C562A7BDBB2BA11ULL, 0x02C10C0B9871ED2BULL, 
            0x45A19FAE6E1FAC47ULL, 0x4C7AD6FE116A7253ULL, 0xE52A0DCF7E5EC869ULL, 0x8F02BB8F481F1A95ULL, 
            0x5DEDC63887EB3912ULL, 0x37C6CAC4936ECAAAULL, 0x03CD34F10A671641ULL, 0x655370A3F7ED8C1CULL, 
            0xFCB749FF8F64FDB7ULL, 0x0DC24A3A4B6213D6ULL, 0xB77EB592F66068B3ULL, 0xBF5B937CA5125493ULL
        },
        {
            0xE257716F93AB6FC6ULL, 0x2B5A724FC5E45013ULL, 0x9525BCC29417254AULL, 0x3749B51B638163DDULL, 
            0xB76D53887849B979ULL, 0x7FA5276CB59A1D58ULL, 0x6C20594791ABA651ULL, 0x5C6194215B3FE2CAULL, 
            0xD097042CFFC2BE1DULL, 0x772C8C9D737071DFULL, 0xA757FC078D590BAFULL, 0x25DBF8971C8CBB54ULL, 
            0xBF5FB0F7D3BB8E83ULL, 0x89F07F51EE5E5143ULL, 0x45C6630EAAF8AA42ULL, 0x60FCC914FDDC2EBEULL, 
            0xBA87F9F073604E2BULL, 0x289A77D4C255FFB6ULL, 0xEC975BDB3F56FDD2ULL, 0xEFA3C7A9AC6EACD7ULL, 
            0x79832E6C4B1B1A4DULL, 0x13E11408B7088CA0ULL, 0x64DCEE613D7380B3ULL, 0x360FFE42F0B07422ULL, 
            0x98EF078911B4CCA0ULL, 0xFE9D3BA76C1837B2ULL, 0xB3664C7572698AE1ULL, 0x1E335981CBF734EDULL, 
            0x87FC6DACFF5BC39FULL, 0x1B9BB860A9C8C6EDULL, 0xDFDD0077832F3B0AULL, 0x953E5BBD5C16CDF6ULL
        },
        {
            0x4EBE331CAAA5FF52ULL, 0x3AF369DD053DE652ULL, 0x9041FCED9E6793EEULL, 0x85B5F1249942CD66ULL, 
            0xCBCE6EDA021F6EC1ULL, 0xDF15E3DA42081520ULL, 0xD7D6F23482F7AF6AULL, 0x3A1E19A4613695AFULL, 
            0x2869A833E1672E52ULL, 0xD643494CBB3053ECULL, 0x3CAA3D29913FF703ULL, 0x35FB724445ACA72EULL, 
            0xF8AEBF7F7D40377BULL, 0xE32EE7F7A36E9269ULL, 0x0BA32293657FB19FULL, 0x4E9B53A0C730EA1AULL, 
            0x6F9F74C88135BA5AULL, 0x31E1A21370D38B5DULL, 0x8D061444964DA3C6ULL, 0x6117A8B793FA7A8EULL, 
            0x203B4271FA9245DAULL, 0x7128E6F2460601CBULL, 0x313F961E80ED1A08ULL, 0xA028341BFEFC226AULL, 
            0xB9D2E3DE97D65B51ULL, 0x01DD303F86E1341AULL, 0x2A5702EDC040DA2FULL, 0x43EE9224D2720605ULL, 
            0xED2747BAFE395A07ULL, 0x2C52B7AD37EA8EC5ULL, 0x21F4133648A999C3ULL, 0x4E37898D5C0FF640ULL
        },
        {
            0x2E0C82CE57496C64ULL, 0x2C92F3C119A2AA9EULL, 0x568AD54732C1EE1FULL, 0x610154D2DC972776ULL, 
            0x476CB8172814C3E6ULL, 0x2724E24477C6EBBBULL, 0x6ECFE7C15E8B3DD4ULL, 0x896F311E3CAA6ED6ULL, 
            0x2A7006AC70F3A950ULL, 0x54CEC3A2BE0A3A92ULL, 0x581BCD667F581A77ULL, 0x3672FC115AFCFB8BULL, 
            0x41F60DDA23136994ULL, 0x98063482BD7DF6F0ULL, 0xAB7F71DF6C615BBCULL, 0x55498F019ABEB6DAULL, 
            0x7BAF89560C9DD696ULL, 0xA8212DBF0A8C563BULL, 0x8DDC3B871AE3BD67ULL, 0x901D9F1944DC22ABULL, 
            0x1C4DA909B3DD65C7ULL, 0x0C8137E486D4C975ULL, 0x063A1F8B1E3D6017ULL, 0x17B6CAA7CA714BC6ULL, 
            0x2732036CC596069FULL, 0xC1CF95D62B801705ULL, 0x8A5B2ABC73336E5BULL, 0xE123BFCC85FC61ADULL, 
            0x84D18E40F572F25DULL, 0x8A46CAF9CC1EF598ULL, 0xC5C9E3A6687B506FULL, 0x8BAAC86EA754A63EULL
        }
    },
    {
        {
            0x9AD6BFC8650D76E5ULL, 0xDA817BD78E747579ULL, 0x897F3812F2A6A3A2ULL, 0xDE155E3DDB805F7BULL, 
            0xCDAE9D66B0BD7745ULL, 0xF2CE325A705FF9FCULL, 0x70ECE49043AF8A6AULL, 0x3997E531ACC647CCULL, 
            0x6A3C055C78C354CBULL, 0xB09A57407AAC69AEULL, 0x72DC976E11B43106ULL, 0x62D48F6EA6E4C062ULL, 
            0x4F8AE90905DA7502ULL, 0x4E18AC46D0E5F1D7ULL, 0xDA1D9289C8D2C23BULL, 0x45B3A6A9D3434D4FULL, 
            0xF1B4314EFF4F728DULL, 0x0E2D6AA999BF7BA7ULL, 0xBA47FF02970C53F8ULL, 0xBF52D6F58B5F6CCAULL, 
            0x8F0E6EEF14DDAEE2ULL, 0x2394AFBF2FC8D88AULL, 0xF3FBE600B56CC518ULL, 0x088B64AA6AD42AA1ULL, 
            0x9F09AE78FB3FE68BULL, 0xECC7897E7A7FB777ULL, 0xEDC044AE28D8295AULL, 0xC69CA1C96321AE5BULL, 
            0x6AF6E29D1FDA6CE6ULL, 0x6AE388AE175CF562ULL, 0x314BEAE468F9329BULL, 0x6EDA9617DE2990ADULL
        },
        {
            0xDCBE150BEC6F6FB8ULL, 0x5D742A549B19E5C0ULL, 0xE194DEA6A179235EULL, 0xCC30AAF3AF5BC8D7ULL, 
            0xD77A78A127E3E735ULL, 0xE1B14F21B8BA7972ULL, 0xBA4CECA48F2BDF35ULL, 0xC3EA057279B72715ULL, 
            0x8088CA95432A2027ULL, 0x5DEF54F0C4F742E9ULL, 0xB76E7269B5C41E4FULL, 0x034844DCC9B3BBA4ULL, 
            0xFBC6ACC80ED33637ULL, 0x391C195054A58696ULL, 0xBC6238DE6333EFBFULL, 0x4FBF0C74A97A177FULL, 
            0xD2D936F43D982916ULL, 0x5B1600AE08A2C89EULL, 0x013FDE055404F768ULL, 0x3FE33FBB967CBEF5ULL, 
            0x3D13D5A530610D3EULL, 0x19647CDA01E681D6ULL, 0x6D76F5D85994EF34ULL, 0xDF5CCE596BF6A7B3ULL, 
            0x4C7B021025C53D4BULL, 0x1CA316BF958737EBULL, 0x015721B294786CAAULL, 0x50ACDDBAFEE2909AULL, 
            0xBE266C61A5301AB7ULL, 0xD813D42194AFD4F1ULL, 0xE9631F9405C4304DULL, 0x1CCD83FC10D9C6B8ULL
        },
        {
            0xE00356CE5B1A59E7ULL, 0x9914136916A37DF6ULL, 0xC162B5A64FD5198EULL, 0x95A5DCBE0C5BE3C8ULL, 
            0x6FEBAA280DF85C4CULL, 0x35F26AED0B16089AULL, 0x75BAE11AB9C24642ULL, 0x0DA1F16AF4CEA146ULL, 
            0xDB0432B6D5F29DCBULL, 0x3643DD8E08F36DBAULL, 0xC1A058117F018FCCULL, 0xAE2EB133BB8F50E0ULL, 
            0x39A329141E663F53ULL, 0xE2F1E865727ADAD6ULL, 0xB4FFFE91DA25E72DULL, 0x8BCE1A9792FFC367ULL, 
            0x88E99D6D2BEF7915ULL, 0x0096C41A31C0E66EULL, 0x96FEAFF256904C3EULL, 0xFFEFB0A054D3945DULL, 
            0xF383F12C61950C50ULL, 0x93F0EB17BAEE1214ULL, 0xCD99E54B8EEF0F56ULL, 0xD00E6BA36342E26FULL, 
            0x99F57B3FA1E53F87ULL, 0x5F70CDE238D3292AULL, 0xD73DC2012FBE9A7DULL, 0x09F000249CFA711AULL, 
            0x73D510051A9CA518ULL, 0x6D615BD4BFD8385FULL, 0x119736D5C0FC42B5ULL, 0x3F48D5335D007016ULL
        },
        {
            0x832B5E15D0892298ULL, 0x0D4A7A3070C39E1BULL, 0xA20C26918C32C7F7ULL, 0x00C0D000C56A7D78ULL, 
            0xCA23B4A7225E7351ULL, 0x558B03A8993AF96EULL, 0xA4334E05F61D1286ULL, 0x77F62163B850508EULL, 
            0xB0C5196C1B20E58FULL, 0xFFCB2DCC869F4BD0ULL, 0x4ED2AB7E76C146B5ULL, 0x940BF9AEF110D15BULL, 
            0x0491050FFA90CA86ULL, 0x7AD08DAE0A4102B2ULL, 0x63DD5060365BE780ULL, 0x1A7F93DAF03DAF1DULL, 
            0x2895E1171DF2D7F0ULL, 0x80AC347F8296C8F7ULL, 0x4E7F8B00A24827D8ULL, 0x511B57944C129C6BULL, 
            0xB12F6E810171E05FULL, 0x852F834A1969813EULL, 0x6E0B0BDFD0936179ULL, 0xE4C97E5D0F3EAE9AULL, 
            0xA574CF8C2758FEC0ULL, 0x77F667955B597018ULL, 0xB7C404D52218E217ULL, 0x7312464839A407DAULL, 
            0x86AD79A3E1B9657CULL, 0xF57A855A334F61F2ULL, 0x8DA650EDD9DA01F4ULL, 0x5A80F796A461B628ULL
        },
        {
            0x11A850F76F30599AULL, 0x963C58039EE648F1ULL, 0xA036DEC1BF435460ULL, 0x40C4696A1F7DD210ULL, 
            0x20C3EBA7DA1D5349ULL, 0x1576479E846525C4ULL, 0x125505EAA25702E4ULL, 0x39C7799177518D2AULL, 
            0xFEBAE07A5BAC5E64ULL, 0xCFA7678FF7DAF615ULL, 0xC54B0121ADAE4578ULL, 0x063419E9B15BBBA4ULL, 
            0x458BF152CA38DDACULL, 0xFB42AC7E060AF228ULL, 0x737989E7AF76EC71ULL, 0xDBF0B8219A2795DAULL, 
            0xFE77071E00EDFE53ULL, 0x7BCC143C8FD1EF9EULL, 0xFEB549C938ABFD1EULL, 0x885B6ED059257D0DULL, 
            0xEC56E4217CDD79B8ULL, 0x03A8740F57656683ULL, 0x9A2B2F635B387D0EULL, 0x9AFBDED52B194F42ULL, 
            0x9435CA75CA02D050ULL, 0x054E3FA6299280B5ULL, 0xDFBA645F7F2E0D8DULL, 0x099F2E220C121AF1ULL, 
            0x53A766472E7928CAULL, 0xE07B58C6A2F8FF26ULL, 0x8E9937C58422A99EULL, 0xE814A4CFF9B817E1ULL
        },
        {
            0x0CA5C65D12694741ULL, 0xBE15C9C796232192ULL, 0xE776CB024D6D4C8DULL, 0x64EFF283728E8C70ULL, 
            0xC89DCE8477A02AE6ULL, 0x1F96275F0679DD29ULL, 0xDC0D03317991D645ULL, 0xDF2AD29B86E2D943ULL, 
            0x9D3C79408D7806CBULL, 0xA215C889D8C79545ULL, 0x64CE1463993C6AB0ULL, 0xF798721003A4B7C5ULL, 
            0xCC9DC9A6E031496BULL, 0xE90FF735676D72F8ULL, 0x684CB7BE37879B84ULL, 0x9CB1EF7A96671520ULL, 
            0x1E641FEF5F4A6AE0ULL, 0x4FECAC474B8E362DULL, 0x289C5628BFE42949ULL, 0x224CEEE94B1DD6AFULL, 
            0x1AB3C819B9B3CDB6ULL, 0x0CDBCFDB079BF1E5ULL, 0xCB1A80783CC12146ULL, 0xA2AF9476DD6A0933ULL, 
            0x26801C10F28F5ABAULL, 0xDF3C3BC03785D654ULL, 0x828D56AB6CBBC92DULL, 0x06B6D820D7C5FC04ULL, 
            0xE5196D1C5B25C2A6ULL, 0xA1A5FC89C2479060ULL, 0x153B1E9216FD7DD7ULL, 0xA9D993F31279541FULL
        }
    },
    {
        {
            0x49D32E54619328F8ULL, 0x2C6B781BF0B72334ULL, 0xC04B3A7123333FBEULL, 0x1429C90884622509ULL, 
            0xA982D478C46D1B52ULL, 0x1555D7C08C0F3724ULL, 0xF56DEF7C8AB43A31ULL, 0xDFF70C605C5A2FE3ULL, 
            0xC4913ECE55935A2BULL, 0x79BAA8A95183CBFDULL, 0x3062C03C2B4F861BULL, 0x6A9DFDF9A8113984ULL, 
            0xB4D8DC81D0E49369ULL, 0x6CC3081AF24B2EE9ULL, 0x4F09FE4879EE32C2ULL, 0xA559EFF7DCCABBE5ULL, 
            0xB6603DD24C9D8923ULL, 0x23389E23EF2CC0BEULL, 0x0B800B5E7FBF1AD5ULL, 0xD8F8CCDEDCB37233ULL, 
            0xC928BD12CD007684ULL, 0x0FE1A14616E653BAULL, 0xF8575069C58A2320ULL, 0xD7D49A40A0962E74ULL, 
            0xC7DFB0F19B9EA28AULL, 0xF6A670D391B1CEA1ULL, 0x4DB9854AFC6163ECULL, 0xAB37BFD21C09004BULL, 
            0x6375233CF5EA62C2ULL, 0xE4A465993BBD8F7BULL, 0x8FE1F517DBE7F41EULL, 0xB5B379E320A59E76ULL
        },
        {
            0x66998690630C9188ULL, 0xD51CA4CBC9428D57ULL, 0x67B8D6679D9DEB75ULL, 0x2A230DD73F9DCF6DULL, 
            0xC76EC40291CDB2F7ULL, 0x04B95273BA561928ULL, 0xC1B2F30003B20CB4ULL, 0x28DD08853497DAD5ULL, 
            0x6B0ABC98E20B32BEULL, 0x0B10E2F10577B288ULL, 0xD48C1F9D3DA808FCULL, 0x65659FBF1919F2C0ULL, 
            0xEBDAA93356DE7B97ULL, 0x252DE76A9314577FULL, 0xA355B30F1EB864A0ULL, 0x9C7785544568C14AULL, 
            0x5A2AB4B37F53E9D7ULL, 0xE519782B3B680492ULL, 0x1656D159EB3C8D46ULL, 0x1FC27081E5D3EB21ULL, 
            0x5D771F7B8D6701D7ULL, 0xE3704498ABA4AD6DULL, 0x11D6C08A474ACF97ULL, 0x43A72A6A4081F3A0ULL, 
            0x004DBA55E212B1C3ULL, 0x17C543FA9A9CFB03ULL, 0xFEC8D415008CCE60ULL, 0x83493BF6A4E4EA52ULL, 
            0x8FC9F08F5D48CD9CULL, 0x724655348C969D14ULL, 0x9E450D8497BA4F93ULL, 0x93AB99DD5184C2F5ULL
        },
        {
            0x801D5F89C8A0899EULL, 0xCB0460317BE6F11DULL, 0xD809598DDDDDD4A4ULL, 0x3E8F46BA03623A0CULL, 
            0x28C07A1021E6C42CULL, 0xDCB881865D63F27CULL, 0x6C81A72F470F3CB3ULL, 0xFB94500399AFF51DULL, 
            0xEA6D72EFA4F99A8DULL, 0xAFB7454ABEE29D0AULL, 0xA541FFB691595159ULL, 0x3DADF96799065FF0ULL, 
            0xEC3DD07FAB15B1AFULL, 0x01CCA3E4A6FCE428ULL, 0x82B04A8877C51B8EULL, 0x2F05645BEAB2CB92ULL, 
            0x4DE56A29DA75A7EEULL, 0x6E5F9DFC75EE478CULL, 0xECF639542B2D1BDBULL, 0x16EFB97B3E0749A8ULL, 
            0xEFAC48C41FF933E7ULL, 0xC34A054B092055CBULL, 0x838D599FD152E206ULL, 0xDAB662023E00E9DEULL, 
            0x539092D7659BDEE3ULL, 0x53BE3B3638F8F0ADULL, 0x1B6BE07076C91E81ULL, 0x7896F7E142900933ULL, 
            0x8E06F343A6594A71ULL, 0x6CC87D77C767DD95ULL, 0xECC35C4E5D81C956ULL, 0xF11BAFD866179759ULL
        },
        {
            0xDA048E3F1E0ACEB8ULL, 0xDDA5CE50D4579A5EULL, 0x3CFA6A5446765F52ULL, 0xF73E001FED697F6FULL, 
            0x4F8E0B95C9E4B6F5ULL, 0x773F39F5E63B4EB1ULL, 0x5DC253EF005518E7ULL, 0xE3CA99A4E4DED3E2ULL, 
            0x475C9AF17EECA3D3ULL, 0xD686B7DB20C07423ULL, 0xFBC87BC3373D1E38ULL, 0x54FA11DB2FC014F4ULL, 
            0xFA6C332967E18994ULL, 0xA3843DAD070E4C3DULL, 0x85E7C958324740ADULL, 0xA4692B8667924A77ULL, 
            0x7AC7D01E750D225AULL, 0x0167162C9856DD77ULL, 0x0FA41DB80B08CCC8ULL, 0x3A8036B782E4F09DULL, 
            0x0376A13866E337E8ULL, 0x04BEA2E5F659673AULL, 0x7B6687CC5C8A9AF9ULL, 0xB2F032C23FDF3A8DULL, 
            0x3801B5628E45FB3AULL, 0xEE51804179E06523ULL, 0x4C8672FB495268E4ULL, 0xB96AF0AEC7602874ULL, 
            0x01894A2DE1BFC0D1ULL, 0xF0E8845196A36784ULL, 0xD99A6B7550EF3AE8ULL, 0xED788375B43BDA6EULL
        },
        {
            0x40CAEADB53BB6314ULL, 0xC5BE599AD8A560C4ULL, 0xCD1D0DBC84990E2EULL, 0x0D779B4CF6F868F4ULL, 
            0x0521E51120BF5128ULL, 0x2301918FB0844BC7ULL, 0xD7E62387413CEEFDULL, 0xBF69FE56ECEDDD5EULL, 
            0xDD34D663EFE86633ULL, 0x5995BF8477C0575AULL, 0xDA8EBAAF18A95B75ULL, 0xE41EE4FE00ABD426ULL, 
            0xDFEF740A0851BBC0ULL, 0xCED320E3120DD0C9ULL, 0x8DFC965499F1301DULL, 0x6487BA725E2774DAULL, 
            0x807AA6D89123758DULL, 0x3C16BC1E325704FFULL, 0x0F911E554BC933C3ULL, 0x9AA0A1E69E10C7A7ULL, 
            0x9E36C07C5A04B61AULL, 0x628C192F6D9C08BEULL, 0x674D815E0480236BULL, 0x5BBAA1613EB2E26DULL, 
            0x24E2264F7847EA49ULL, 0x5B0A41CF367DDE40ULL, 0x9A150F87CCCBE10DULL, 0x2FEE55CAE5D97B8AULL, 
            0x171F3313FEF34F06ULL, 0x8D1C7E423B24174EULL, 0x78BD5EC56457218AULL, 0xDBDE6F188C7E731EULL
        },
        {
            0x7479BDD6FA2B6F35ULL, 0x785B79FE48F6BD9EULL, 0x94E16CE8046B5415ULL, 0xE6B545FA6EF887AFULL, 
            0x943671E05BCD5FABULL, 0x9B33AF23C82386CDULL, 0xD2BB44C97A8E4647ULL, 0xE8CDBA91CE247509ULL, 
            0xF6C68339B41757DAULL, 0xFD123D98FF84A8E9ULL, 0xAAEFCD83BB10806AULL, 0x0108AC35D705A52DULL, 
            0xA9C94A191F4B0D80ULL, 0xF70EC5F53E9E50E1ULL, 0xCBE723C37536C455ULL, 0xFD6671CCDC5AA591ULL, 
            0x9445ACB7554E6459ULL, 0xABBD215AA1A5BC1FULL, 0xAB1B5A04D8E089ADULL, 0x831B26A130FC3231ULL, 
            0x64F288D3BB04C786ULL, 0xFB3AB67D3BE94137ULL, 0x56E4847D546A9DB0ULL, 0x0B839D712313308BULL, 
            0xEDEFB5F202F9B1F7ULL, 0x8439DE42D92EF507ULL, 0xD4A45D57B6677542ULL, 0x6E4A9C54A1B4245DULL, 
            0x0092DB9B555F99DBULL, 0xA89E0DC751A58797ULL, 0x83E0EFA31EECC288ULL, 0x3F8AB1CD781D9E0FULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseEConstants = {
    0xF384E440AE722DA3ULL,
    0x0B4C47ACF3DA20BAULL,
    0xC8EC760B345EF310ULL,
    0xF384E440AE722DA3ULL,
    0x0B4C47ACF3DA20BAULL,
    0xC8EC760B345EF310ULL,
    0x2C086BEA1326E378ULL,
    0x400CA1C3A3875635ULL,
    0x8B,
    0xFC,
    0x89,
    0x37,
    0x13,
    0x45,
    0x99,
    0x44
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseFSalts = {
    {
        {
            0x3BC35E4B88580C4FULL, 0x835D50EA3FE23204ULL, 0x5AD21A1FB0480240ULL, 0x5F3EE186B44D6788ULL, 
            0x3DE7A8FC917DB8F2ULL, 0x0E28A85D9F51CE05ULL, 0xCDA45DCE92DC7DFAULL, 0xAF6472378ACCF913ULL, 
            0xF9CAE19A3CF4EBD3ULL, 0x99D55EBF66C612BDULL, 0x01B15156DBEB3AC2ULL, 0x37B94330883253DFULL, 
            0x002F4F5CDFCE0371ULL, 0xBBBC4E9B05461C77ULL, 0x33C0496330FFD41EULL, 0x963A02F53AE0BCDFULL, 
            0x5629416AC68CB408ULL, 0xC175F5F4C2B155FAULL, 0xA771FA18F26E42E0ULL, 0x9DA951D9297864A0ULL, 
            0xC1E897C2AB464724ULL, 0x10C0984F45981BF6ULL, 0x636466514865E1ACULL, 0x136DC6B1F13CF2CCULL, 
            0x658D2CC1E8A8D143ULL, 0xED64ECA174C86242ULL, 0xE2FFA531ED0A71DEULL, 0x6B5A315F9DF52BCAULL, 
            0x92DE5596FA2D38D9ULL, 0xDB8FD281CA363366ULL, 0x8CCB22EB8B8DFF13ULL, 0x5A09D3ADE3375996ULL
        },
        {
            0xBE727ED5F7DED2D6ULL, 0xD92344BE717D279BULL, 0xA221ACCBC1797155ULL, 0xCAEF23C533179282ULL, 
            0xEA712DF62ACA2862ULL, 0xAD19A8315C4223C0ULL, 0x5B502AAF6DA84C17ULL, 0xABB1298D0DCBF2B0ULL, 
            0x1BBB2C76FF2B43C8ULL, 0x8E573FA50B18ED29ULL, 0x3088C51E2B061371ULL, 0xD4099D5F5817B9C1ULL, 
            0xAA84EE5A2ECE1306ULL, 0xAD03042F59EDD7FAULL, 0xAE15E7ED37B684A2ULL, 0x4E33B232CA6AD3C7ULL, 
            0xFD79240D657CC435ULL, 0xA18F4874A6C3DBC9ULL, 0x80EE3245FCA9F46DULL, 0xD40728332F8E1B5AULL, 
            0xE54329A25C4E3F6CULL, 0x4CF4610B903252C1ULL, 0x3A481B09AB6C3AB4ULL, 0x3DFF80B77D5045E0ULL, 
            0xDA4ADEA6E3A3CD3BULL, 0x80B761F2AB907D46ULL, 0x212AFE88B3063A78ULL, 0x6337E7152FA22460ULL, 
            0x9592724312C7A681ULL, 0x9B953655325B9B63ULL, 0x65EA40DE16517E1AULL, 0x610100F68B4CE437ULL
        },
        {
            0x46D709CA8D772DC3ULL, 0x716809EF62B9DB46ULL, 0x18A40C4C88E26788ULL, 0x6A4432E8EB0BE653ULL, 
            0x669660B3158DC9D1ULL, 0x679540B2C5F9E2EEULL, 0x8188DB8046D3EC41ULL, 0x6CFF90CA39A7688EULL, 
            0x7129C35FD14824CCULL, 0x28D06012944CAD7FULL, 0x28F8762104692301ULL, 0xF60F12BFEB4D8122ULL, 
            0xBD062040883CC1A3ULL, 0x406E9AA185C4FCD7ULL, 0xD00018C035F9CA24ULL, 0x68ADD41CD5637E31ULL, 
            0x7E69AF32421AA567ULL, 0x6D8991F3BCDFA8CDULL, 0xD00EE753309E311BULL, 0x607F3668BFC1F50CULL, 
            0x2194C8301CC3DE62ULL, 0x8DDA882D58066CB1ULL, 0x0A16CEAFF6074BFEULL, 0xC77047CEA1B041BBULL, 
            0x8F9EE5B6BFFE4411ULL, 0x9DD491232AF81416ULL, 0x18E1F08BF1CD40ADULL, 0xB5089F3C63E3303DULL, 
            0x648272F0AB4E294AULL, 0x6B079092AC32BEAFULL, 0xC7CD1F5304AE2360ULL, 0x3A606722E65BB5B4ULL
        },
        {
            0x7D1E6EB62BBEB96CULL, 0x89678B5A87F0BDBCULL, 0xF5E555634D0E48BDULL, 0x821276DF5BAF4B4FULL, 
            0x49C6A95A4194E792ULL, 0xAB00E71A95F9F4D9ULL, 0x8F24AA901E45F59DULL, 0x418D990EDFE2FC4FULL, 
            0xAEFF50CAD7F157ADULL, 0x2CEDE1C1F1586A9FULL, 0x50AECD06CAD90CCDULL, 0x35D13DE01F33CBB6ULL, 
            0x949C271AE83B16AFULL, 0x90244EDCC8E7D0B5ULL, 0xB25A09D63B6ABE4FULL, 0xCFBFD4664BF55431ULL, 
            0xCE0F7384A5E92F59ULL, 0x04163CC3A03C84E6ULL, 0x69B2BE79B04FFB4FULL, 0x33C31F44AAB06911ULL, 
            0x1852206A3260C55DULL, 0xC4E56D836DFA76DEULL, 0x46C2E404A1034406ULL, 0x046A068C493A5CBDULL, 
            0x64EC4362684E8900ULL, 0x988E1EDD2098EF36ULL, 0x57952BE47214038CULL, 0x2F05084F896F49ADULL, 
            0x50CA2073EC9D0503ULL, 0x60AF6EED8D6D6B01ULL, 0xF3644A92DB4B8E96ULL, 0x7DC88D95D667B02AULL
        },
        {
            0x43A003A258FADDE6ULL, 0x40A33742325588C3ULL, 0x846591E4B706E385ULL, 0xDBA9025A406D93CDULL, 
            0xA36BEA66A2C8B75DULL, 0x063E6E2BAC3E2517ULL, 0x7953199C96ED1F03ULL, 0xB045C342EC9D53CDULL, 
            0xEB6AA97961D5D142ULL, 0x33F6ECE1294A8369ULL, 0xA0C5C0092715E544ULL, 0xF7DAAABD7F536D19ULL, 
            0xE93AF5C35BEF5C3BULL, 0x97EF05CED413E240ULL, 0xDE5F347280EF5997ULL, 0x8BBC6203E13EA71BULL, 
            0x6703D0721F97C2EDULL, 0x0085EFA69CB83387ULL, 0x2C2DAA87A46D010FULL, 0x67E2A37B4084F8C3ULL, 
            0xCF69E9D94C683BB5ULL, 0x1F707E296268C99EULL, 0x5BAC28BBF949AB5FULL, 0xFAA213D5DCE89926ULL, 
            0x9EEBE237B6CBA6C0ULL, 0x55D6D6A0EA6F2742ULL, 0xC588440CD939925BULL, 0x4FCAC5A2B251D40EULL, 
            0xC474682D0CC03173ULL, 0x9716D4300D56D696ULL, 0x4FCB809E4591CEDAULL, 0x0FFD636D6C11A631ULL
        },
        {
            0xA21F4ACCF61260C4ULL, 0xD1AFDF96D9AAC334ULL, 0x5F78D1A30470FEE1ULL, 0x2ABE109369F4AC0BULL, 
            0x335A5DE2847FCC17ULL, 0x6535D9F43D696A55ULL, 0xDC0D56B7820477AEULL, 0xECA7AB5B9F3012B2ULL, 
            0x1D340DA4CF68A844ULL, 0x66F3DD0753493D96ULL, 0x76B971AFE0DC68B4ULL, 0xE843C6E683838AEAULL, 
            0xC5F22F4BD56CDC13ULL, 0xE189BCDCB0E46804ULL, 0x0D62A9F52FF2FA0EULL, 0xF4635C2100816659ULL, 
            0x93E414C5AF309838ULL, 0x798A6A39725B4501ULL, 0x552012633D8C6D57ULL, 0xE38B15724EF85921ULL, 
            0x3F59192703FD5CE2ULL, 0x9B3442B2E0B2CE6DULL, 0x50C8D3D6C933E721ULL, 0x6BE2BFF7EF48827EULL, 
            0xCF8EBA1105128A3BULL, 0x4049506E10BB8AE5ULL, 0xE93220BA96B3FB26ULL, 0xBAE2B64C9F6B1721ULL, 
            0x937D0AB909257656ULL, 0x37A3F90C9914CA39ULL, 0xAD86C7ED12320D42ULL, 0x77587B1332EB414FULL
        }
    },
    {
        {
            0x6622EEDB48949734ULL, 0xDC136FB3BD13592AULL, 0x02B8772A792E3E62ULL, 0x49A7EFFD3347D5FBULL, 
            0xBF77246027177E4FULL, 0x7DD3EB103CE2E368ULL, 0x35D47B492BCBBEF9ULL, 0x301399DEAF51DCBFULL, 
            0x5A960018F9D7663EULL, 0x2AF7B78EC10FC7B2ULL, 0x04CA4B6EFD4DB609ULL, 0xF79ACD97FD6BD347ULL, 
            0x634468AE0D1BB0A2ULL, 0x09C74738005042A7ULL, 0x903BA6E126EF5E99ULL, 0x743E5CAEF61F9421ULL, 
            0x732F45D4B222B86FULL, 0xB9D4CADF0E3E719DULL, 0xE2BBD0A4462BC442ULL, 0x9EBEB338C629F94BULL, 
            0x54CB2C2055D27139ULL, 0xA78EBB940EA8D3DAULL, 0xEC263EAC562FCD26ULL, 0xBE4450CB2F5D1FBFULL, 
            0x853E653880F6DD35ULL, 0x2092A5B1EDD6044AULL, 0x3AB7ECCFB61ADEAAULL, 0xEE6414A17DB38546ULL, 
            0x79EA60F310419744ULL, 0xA561C68E9A80AF2EULL, 0x50DF9049E370BC30ULL, 0xC0CAC43A667A1340ULL
        },
        {
            0x8952486F79FC3B48ULL, 0x31C4FCE89673744BULL, 0x33F1ACA4E5903774ULL, 0xAEF3086A798B5733ULL, 
            0x3D3497700B212B7AULL, 0x8050BA1E0ECB559DULL, 0x501E38D3611E0B77ULL, 0x2CD157E2D5383BD4ULL, 
            0x46CD879F58D248F9ULL, 0xA0CBE24831B1AAC2ULL, 0x6BB5C6DD0E50B589ULL, 0x28C8A8EC434345A2ULL, 
            0x7EAB27DEE9B8F1CCULL, 0xBF19AC0EA733F90AULL, 0x8EF209C4FFD8F183ULL, 0xCCBD3E2695818BC6ULL, 
            0xECB35A7CFB7F9C1FULL, 0xEF2366091DB7E0BEULL, 0x96A6CD8CB788A727ULL, 0x9F7F3CF0DA6C6933ULL, 
            0xCE7B757022805ADEULL, 0x61D2C5F954847FC9ULL, 0xCE62AB2CF363D84AULL, 0x4537AA84E931A1EDULL, 
            0x75D0D9B04AE5DC5FULL, 0x320B636D0B066390ULL, 0x8F17168039AF430DULL, 0x5C7533CDDC2A2518ULL, 
            0xA907469626D0D793ULL, 0x4AB23B20D20E749FULL, 0x69F22A8A005FED9FULL, 0x12C927F4E982B1BDULL
        },
        {
            0x3FD3D8152F92B419ULL, 0x74170A547A6C73E8ULL, 0x6F7E4705A5FF9B53ULL, 0x769EB1AB5C8EF923ULL, 
            0x8F766961B8EADDF4ULL, 0x858400BD9741E5D3ULL, 0x3120AF847B501077ULL, 0xE76BA15D81754AB3ULL, 
            0x192FE6F1D3124321ULL, 0x61D828D6E321BC35ULL, 0x82D21BDBBE772832ULL, 0x9D6B70D385491BD1ULL, 
            0x5CB24F6B502706E2ULL, 0xD1F2186A7FE11D6FULL, 0xC3EDBF10BE17FA67ULL, 0x10DB1FFA09542651ULL, 
            0x9067728F3F653F2DULL, 0xDCCD743355527BF3ULL, 0x87EC29818E0AB9BEULL, 0x3BC1D87099AE7DF0ULL, 
            0x59FA2678B52940DFULL, 0xE5416B8922F92669ULL, 0x36573EE4E8182A26ULL, 0xB3A24A7A76E93EE6ULL, 
            0xE2D699A1DE5D7F54ULL, 0x71071BAB4C84DA13ULL, 0xBB0A6856456038F4ULL, 0x0AF51ECA5459F19EULL, 
            0x5A0F19C1FA6059F2ULL, 0xE853DE465A0A3B50ULL, 0xEDD8ABD72808D9ACULL, 0xC6BDF11218BC319CULL
        },
        {
            0x3014E0A4E3D65FDDULL, 0x08D163FA852F10C8ULL, 0x5679935B64B0A7EBULL, 0xBF559FF80572631FULL, 
            0xD64BB1FE1BE48F39ULL, 0x27EE94FB9FCB01DFULL, 0xA38323906214AB19ULL, 0xED58FED338304A99ULL, 
            0x9A82A656E0EE812AULL, 0x3E1644EBA5749177ULL, 0xD584D55A06F55822ULL, 0xB1AEAF7D13E0B148ULL, 
            0x113FE28835B80F00ULL, 0x8FF42D2057120F48ULL, 0x82FB9F3B48185440ULL, 0x2B5D4525E866AFF4ULL, 
            0xBDF693E8DB8895DCULL, 0xED2DE0531EFD57D6ULL, 0xC041DA9D2F3C930FULL, 0x4AFAA5DA67E8DB0DULL, 
            0xC61846CF7F3C1E16ULL, 0x26BE78E8C0144A3CULL, 0x983A58229F4813D2ULL, 0xE0DA82B1EC2939ABULL, 
            0x2B6A83011C169023ULL, 0xD2421F7A45167F7DULL, 0xC0BCB4F5D54A0F84ULL, 0x12C02F99C22BCE21ULL, 
            0x30027E785BA55FA2ULL, 0xFE847A5AF3B9945AULL, 0xC897E8E033EB7B91ULL, 0xF66F2570B25020D3ULL
        },
        {
            0xEEF04D8787104E0BULL, 0x6419F199AB421DE2ULL, 0x11983F461FF0623CULL, 0xE3D09B60636680C4ULL, 
            0x9821BC7AFBF0F9C5ULL, 0x0640F325A5DBC17EULL, 0x6626859521F13B33ULL, 0xBDE9763DF1FBCE8BULL, 
            0x7D970FC8F530B3D9ULL, 0x35E16D8849C21CDFULL, 0x2283BD4E25EA4F2AULL, 0x686E3D952948D979ULL, 
            0x243C2CE7AD812990ULL, 0xBFD2A1267D4ADD13ULL, 0x817DDE35E161C64BULL, 0x3E0FA8F83827D419ULL, 
            0x321548C645E3B3D5ULL, 0x6D28579C6CF71C75ULL, 0x79168AA475A45CA4ULL, 0xB1FF48BC11E2F9E8ULL, 
            0xB49E3AFD3C7A3C46ULL, 0xD929FB14F15DDA6EULL, 0xF6791EA64F1CE9DAULL, 0x672E5C7ECB4EA5D3ULL, 
            0x8E0F988BCBD6BC26ULL, 0xF5D27A070AD38D97ULL, 0x2C62E7491FE4879DULL, 0x235DA53B5F84CEC4ULL, 
            0x7EF2E53B665B06B5ULL, 0x4DDBF096D88E8C34ULL, 0x24CBAA9A2B5AB5EDULL, 0x1208F56BEE01D910ULL
        },
        {
            0xCFE95F5C7A57EC25ULL, 0x9BD1C907A9343D1AULL, 0xBE36B9B4D43B09E8ULL, 0xD4E396B7AF207CDAULL, 
            0xBE467511F54DE039ULL, 0xB7F907B0CC607857ULL, 0x8631A627F1AF9945ULL, 0xFE78796FB18985B1ULL, 
            0xDC09B88DC3595A48ULL, 0xE7F07DEED23E011CULL, 0xD26CDD99AE6DFF2BULL, 0x8ED02F87356C77D5ULL, 
            0x91F8A91A65E719C1ULL, 0x78A65D2345524F4DULL, 0xA4A93668402ED52EULL, 0x0FEAF202BCB654E6ULL, 
            0x0A6CC2385D57AD63ULL, 0xDEF9F52CDC9EE911ULL, 0x257129222B56C3AEULL, 0xAC17DC3D9306A825ULL, 
            0x0F41104982749F1FULL, 0x5D00488DE2708521ULL, 0xE145AC8189F01633ULL, 0x2F00481FA77E52FBULL, 
            0xD75BF09F9A937CDBULL, 0xF1E0C7D11CC268F8ULL, 0xCA4A79A25265F90BULL, 0x70C9CA88E2EFB79DULL, 
            0x14140DA5006A91E4ULL, 0x44A7564E9662109BULL, 0x8283F5FB92323F1EULL, 0x474D27B943D3E66BULL
        }
    },
    {
        {
            0x2078CE8E3A2878D6ULL, 0x787B552D56BD9357ULL, 0x62908332638DAF6DULL, 0xEAB293EDF9437D61ULL, 
            0xC4E4522B74C360CFULL, 0xD3000E0BA67D3C6EULL, 0xB9A41F4E44927898ULL, 0xD9A37C9AD449FEC6ULL, 
            0x3078A430E77378BEULL, 0x67B6B675C279A5B2ULL, 0xBB65F356D7EBFDD7ULL, 0xF9F5A7BDD7972213ULL, 
            0xF0921934EFBD3167ULL, 0x50A3939C8F80B093ULL, 0x0E5009238F5F3F5DULL, 0x7038BD0FFCCF87B6ULL, 
            0xDB409C3CEFDEBED9ULL, 0xFD189E4DD9E8A7DFULL, 0x9B8CBCC157DF0620ULL, 0x9E99A894D542E609ULL, 
            0x70D844719AAAA112ULL, 0x31D4D6DE2A079A3BULL, 0x60100FABBFFFE443ULL, 0xCA31AEF2C3EA1D30ULL, 
            0x31F683A8CA9ED10FULL, 0xCF1E4B6C9883B09AULL, 0x8AD17F82600B356EULL, 0x7568B454047EB86AULL, 
            0xF392A34D15C09EB8ULL, 0x3B4CC9B953E93B2EULL, 0x9C0AEC49812B8549ULL, 0x1737B2896E64FBA9ULL
        },
        {
            0x033A680DBB9696EAULL, 0xE2427EBC1BA7ECD2ULL, 0xCB0BD180FEA55955ULL, 0x7B9AD066D75E844EULL, 
            0x6F32620D439005FFULL, 0x6735D04CB73CEC2FULL, 0xC2CC37211B1120B7ULL, 0x409B693ED5B3D0D0ULL, 
            0x9E75BF299B3EC9E6ULL, 0x4C2A353A64E27898ULL, 0x4C32E06830757CB9ULL, 0x4373D4F18B86135AULL, 
            0xB5320D9DA94E6C51ULL, 0xEDE047F3D3E7F7DCULL, 0x22FFC91D8F2139BFULL, 0x002A483E56AE0595ULL, 
            0x1D0F51BDBE06DC73ULL, 0xEB6A533ABB3634AEULL, 0xD7EC4F16074840FDULL, 0x92793691650CB6DAULL, 
            0xE44B69717E21D05CULL, 0xC3498294FBE01F99ULL, 0x8E211B4B0A30B436ULL, 0x71C43842D8C104E9ULL, 
            0x2957DE06BE2F6F65ULL, 0x63A43EA01EDB9251ULL, 0x9205DCB19FA967B3ULL, 0x4A9CFC957CC38543ULL, 
            0x9A837D2577F00A8EULL, 0xA6506475E37E8707ULL, 0x9B5E158DFA833063ULL, 0x63720EA7501FE633ULL
        },
        {
            0x1483C26F25DD9C85ULL, 0x1A144ACE8E244D45ULL, 0x428D764F814AA7BFULL, 0xE4B30A53A104540AULL, 
            0xEFD1FB97D4CE5307ULL, 0xA916544B67ACD175ULL, 0x4998C85CA26C5F1EULL, 0x06F6F31B7ECA8D6CULL, 
            0x90E45EA8AE1694A9ULL, 0x73A4EB2E9EC4914DULL, 0xB912286764679D45ULL, 0xA2D7CECAE390EB50ULL, 
            0xCA9D5BCA6648F3ADULL, 0x067C9D0C7614A370ULL, 0xA9E5907B53D6B82EULL, 0x42235D75FC20C94FULL, 
            0xECBF69A0426420EAULL, 0x8640685E3266B342ULL, 0xB754CADF0817B2BCULL, 0x4822F308EBEC5FA6ULL, 
            0x160DCC48D105B27BULL, 0xF51DE07C23AB692DULL, 0x86A928A0DEDB88E3ULL, 0x75F25C84355596E7ULL, 
            0xF5E7A773ACC21A46ULL, 0x8F0E888D9E38B395ULL, 0xA78C6D30310D6413ULL, 0xAF7273FCE0409A41ULL, 
            0xF6ED0551FE0C2931ULL, 0x632CAC987D835A86ULL, 0xA37B73D8F4236A79ULL, 0x4B931357A1118034ULL
        },
        {
            0xCB51770D16EC048BULL, 0x08C2F686EBBFFD8AULL, 0x5D958F5B329C18E8ULL, 0xAADE408740EA895CULL, 
            0x4367C67188898A3DULL, 0x27833094A39AC73BULL, 0xD720AFBFA0F76298ULL, 0x1B76C5E37059BAE4ULL, 
            0x35465367B3E39BF2ULL, 0x16BFAD3A2DD65CE7ULL, 0x86AAA968A32D14F1ULL, 0x9F75D0DB40383245ULL, 
            0x38048B0DD151FCBFULL, 0x1F1AD073EF4EE5F1ULL, 0x4BB2949E2AA98E4BULL, 0xEA23CF2964AF083FULL, 
            0x6C5B32AB062912AAULL, 0x894FF29209DEAA7EULL, 0x750C7523F3FDF183ULL, 0xAA3A51C5B60C1E1FULL, 
            0xFC5221CAB23A80FDULL, 0x0F257367E61A5E91ULL, 0x0D5827BF1080A41EULL, 0xF89B42AEA3982B46ULL, 
            0x8657B9A9EE29D1A9ULL, 0x554299B2BFD4F749ULL, 0x900FA24C674ED987ULL, 0xE9113E24AA86D4A8ULL, 
            0x2640056ECCC240CBULL, 0x793EA6A037996549ULL, 0x45659E5953685783ULL, 0x9B91079C8D792EA6ULL
        },
        {
            0x08276399A4765739ULL, 0x70497E68E67EC04AULL, 0x7BE49CA7144F6F7FULL, 0xE5E0319590C83613ULL, 
            0x7F547F196214A429ULL, 0xD7AB60DDD2BD1166ULL, 0xF1A9C68C50FB150BULL, 0x78DF029D17B15866ULL, 
            0x7D95ECD58612D7EAULL, 0x0A30FEB9223755BFULL, 0x9055D0B49654B469ULL, 0x2852ABB7342DB918ULL, 
            0x21E329E567264B18ULL, 0x7287194B2F71CF7AULL, 0xA718768C563E51D4ULL, 0x9CDF154E1B380274ULL, 
            0x368EC22EE0F62219ULL, 0x96E411D738662C73ULL, 0xA2330F420921D992ULL, 0x2812D14F7D719879ULL, 
            0x8596F8D0D0F5D1C1ULL, 0xE9B7F17EAB0C84D4ULL, 0xAA958BD9ABC13D64ULL, 0xA96CE6617117681FULL, 
            0x3643890CEE12D176ULL, 0x3E3CB8ED8BCBA427ULL, 0xC02C13EFBFEFD198ULL, 0xFA5923C26776899FULL, 
            0xE13004B231EE1BA4ULL, 0xDA191E70C133984EULL, 0x8B217B3E3EE62CF4ULL, 0x5B707E99F4DA4693ULL
        },
        {
            0xFE506B4FA4857409ULL, 0xE47A5614D9CC0E79ULL, 0x207032DFA1555079ULL, 0x3B9A9CD6D9BDA066ULL, 
            0x3C9B2D9C2CF00056ULL, 0xA5ABDD33284E8B8DULL, 0x10C307B8866D508DULL, 0x439373B644343C5AULL, 
            0xB35E648DBE446AC1ULL, 0x92658D7469094164ULL, 0x808D237906785212ULL, 0xD2B2DF36ECE94EB5ULL, 
            0x3CA4B07C5A894D08ULL, 0x359581B84FB6F70CULL, 0x2ACCEEC58B4513FDULL, 0x8951D6701704DFF3ULL, 
            0xEEC7A00090910E0EULL, 0x18B4D0B72A14A170ULL, 0x181E50653D40DF71ULL, 0x31DEFF5510A6F0AEULL, 
            0xBEF8A144A43A9778ULL, 0x1434A7344D5357E8ULL, 0x55A768967C9A4348ULL, 0xF7EA0423BB147241ULL, 
            0x19B68BA45FEE0BA9ULL, 0x7A5FDB2864118686ULL, 0xB0B4EA44694312F4ULL, 0x1C1C61E6DA83730AULL, 
            0xBAA119BC7C2EC7E4ULL, 0x84F8CC9AE253B2A6ULL, 0x3BC9437E789ACD23ULL, 0xB99E1DFECD2B94FFULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseFConstants = {
    0x1994F27F26C5E461ULL,
    0x8F330C4D0A2523E4ULL,
    0x6B4C29D748047DF6ULL,
    0x1994F27F26C5E461ULL,
    0x8F330C4D0A2523E4ULL,
    0x6B4C29D748047DF6ULL,
    0x84DCD9521F7CCA64ULL,
    0xCF1098D81EB3AEA5ULL,
    0x76,
    0xEE,
    0x54,
    0xF5,
    0xCC,
    0x32,
    0xBB,
    0xCC
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseGSalts = {
    {
        {
            0xB0178D6FF088CC0EULL, 0x40C2704A81824808ULL, 0xB29B7BC91BA4A814ULL, 0xF5F2E0E0C2E9C679ULL, 
            0xB04D9E403A5178F8ULL, 0xC63C25A155AB7114ULL, 0x050B39576E1A3795ULL, 0x97874429754BB974ULL, 
            0xF7B1C3982B7BC599ULL, 0xDE83CEE8323142AAULL, 0xE3AB2BEF073595EEULL, 0xC37446B60D663850ULL, 
            0x6EB63397ED2FC974ULL, 0x4B477EB87D95176EULL, 0x7CF276E19BEC1E8DULL, 0x7F3830B6CF74FC72ULL, 
            0xB0C8D222DB046238ULL, 0x1BA222287FCB6CF1ULL, 0xA1B371EC5F0A8029ULL, 0xF35516130A4BA845ULL, 
            0x693254BD6E61AA0AULL, 0x18DBD11CB6497BA7ULL, 0x4DD29C3A22E704BFULL, 0x515429B473E6C526ULL, 
            0x6E09C7EDDE5BD7BAULL, 0xFE0F452DA8F7DB56ULL, 0x7196FBD98B6C0767ULL, 0xBDA159A22C2DB74AULL, 
            0xC22D1CD6C59DBCFFULL, 0xCBBC773A6E485964ULL, 0x958F91FCD6F00B41ULL, 0xAA34B1DE6F15B85FULL
        },
        {
            0xD002BAFC824ECF40ULL, 0x422B8FEBB58505E1ULL, 0xBF05C1E4C7AE1E8DULL, 0xF2DBE3A9E45EE158ULL, 
            0x6EA7EC5143681A71ULL, 0x42175D5AA8603858ULL, 0x9FC4DB42E20AD8FBULL, 0x24F57E9087721A61ULL, 
            0xAE25A754E95D57FAULL, 0x50D359CAB447DBA0ULL, 0x141C97A0AD1311BAULL, 0x03F0C69B7A8E9E4CULL, 
            0xB10F42602DCFF8B1ULL, 0x1BB854982A0D0D37ULL, 0x8F9EC302ABE04ECAULL, 0xC9DA565739D18F06ULL, 
            0xD0E2EA79B7BC24F2ULL, 0x79292D1B3F0C8DFCULL, 0xD8AE4AC75D5B888DULL, 0x16CA0CBFD1DC2CCAULL, 
            0x70D02FC520C815A3ULL, 0x6E931391771FB050ULL, 0x55404CB1AD501348ULL, 0x603955FFC53E3951ULL, 
            0x5EBCC06C7110BF52ULL, 0x43D4DA549B9E1E6AULL, 0x27A930FAA316768AULL, 0x51547B357EF50A05ULL, 
            0x9617877D213349A9ULL, 0x10D52C5B3D184CD9ULL, 0xD18CAB501ED0279DULL, 0x19D7EE0BADA5F62BULL
        },
        {
            0x9CB4E653E26FF510ULL, 0xE947968F33619F90ULL, 0xFBF627893020F3EDULL, 0xA4FB88D360A587E7ULL, 
            0xA6E4CBC582E80159ULL, 0x46C91A286CACD69CULL, 0x209CA0F503DE6100ULL, 0x9C6A17368833C6BBULL, 
            0x187490A931DA4751ULL, 0x834DF7609B177282ULL, 0x541D84A071CBB992ULL, 0xDC3441A30CA3FAFBULL, 
            0xD41310BB0365AB4BULL, 0x592A5B2AD51D5157ULL, 0xBA7A0C16E1E15260ULL, 0x8107B3AC17010337ULL, 
            0x8E70120C1976212BULL, 0x572D7D3137D0CA0AULL, 0x0AB94CC7F77F76B4ULL, 0x40ACA6A4129EEAE0ULL, 
            0x421F1DB775076899ULL, 0x6617AA64A7823C5CULL, 0x8B44D523D25F2A85ULL, 0x20D9008A97C8A244ULL, 
            0x93A1EF8C1765949AULL, 0xD2BB2DE35B31727CULL, 0x738152054E1DCF9BULL, 0xBE786F27A1653AB0ULL, 
            0xE28475AC8AFEEB90ULL, 0xA945F9B722FBD26EULL, 0x982C2932833BA3FDULL, 0x7C6E282C95D09C6DULL
        },
        {
            0x0DBC219C9EB1D564ULL, 0xBD0FFE48168CA26EULL, 0x37CEE4AF8CFAF343ULL, 0xDD4ECFE14CEEF129ULL, 
            0x1CA50D5727D385A2ULL, 0xC9F757C23532356DULL, 0x2FA9F1456C1B263AULL, 0xD0558D2AE903E5A6ULL, 
            0xB2962DB24159058CULL, 0xF893B167A59D7C3AULL, 0x44E41C252973CA73ULL, 0x630A6DD139458F65ULL, 
            0x449BA3701BD71848ULL, 0x0F8DF29A678DF8F9ULL, 0x5C11F1650E9175AFULL, 0xAA87A1239E97C71FULL, 
            0xC2351894134B5DA2ULL, 0x9BF0978869A13E49ULL, 0x00832169077D67E0ULL, 0xC00A5AC86D6296A8ULL, 
            0x9A00BEFE65D2FAA8ULL, 0x89A8F2564EEDDB23ULL, 0xB1B7B8AF975BFC1DULL, 0x267C8E10CA804C97ULL, 
            0x3476ECF6C43FC485ULL, 0x800F8010E9CC5882ULL, 0x114E49BEEEDD9561ULL, 0x50D5628B0A87A17FULL, 
            0x3FB8D36D258F1117ULL, 0x998FD086D784D93CULL, 0x2313C261D5B16D07ULL, 0xEEFDD32D2A4EE9C1ULL
        },
        {
            0x7047B93861814040ULL, 0x1B0394A9C401A18FULL, 0xC75A976C0AA0334FULL, 0xC88D906FA3775358ULL, 
            0xF55489C71870CB9BULL, 0xDB283D688FF226AEULL, 0x37D87081DDF91484ULL, 0x4415430DC9C192C7ULL, 
            0x95172E93BA47804DULL, 0x17587F7F8CB2740CULL, 0xFA3275BC9D04F0E0ULL, 0x77F185055EA7B828ULL, 
            0x8E8AE5DE089DA099ULL, 0xC99457E9F8666FE1ULL, 0xDB2D8633246292E1ULL, 0x9C0E9C4E778AA99FULL, 
            0xFEE366B3D320CE36ULL, 0xE44F320016538C98ULL, 0xF9F3AF85E9585923ULL, 0x545949DB7997F16DULL, 
            0xFAF4F8C225326BAAULL, 0xA3A870A91F8A61DFULL, 0x7843C0B5B930724FULL, 0xE65A6E9351B5BE5EULL, 
            0x1AAFF74A3C8D84A4ULL, 0xFCE934779B445EB8ULL, 0xA8513876A7459A81ULL, 0x9A7BB904417935CFULL, 
            0x597D6860756833D6ULL, 0xE380126FF41C5755ULL, 0xF3488F555AFBF60EULL, 0xA14E4FC325318D88ULL
        },
        {
            0x53AFF3F0BD1B13ABULL, 0xD4C6D75FA6040A42ULL, 0x469E81F8A3141A19ULL, 0x2FDF3631B163133AULL, 
            0xD3D3C1B527311D53ULL, 0xB7F2CB626A903D3CULL, 0xF2FEEE2009144F9FULL, 0x5382B63A8C6FC979ULL, 
            0xC261970D410B3261ULL, 0xEE89F45FA7DA3AD3ULL, 0xF01213D885465DA1ULL, 0xB3993BA604381B96ULL, 
            0x6AEC3EF03232280AULL, 0xFE40D2C04C3A8C4AULL, 0x5483CB6F5C315DA3ULL, 0x37BAD8910529E61DULL, 
            0x3E11A2FE4EFF3519ULL, 0xC16C7F482A363CE6ULL, 0x5FBB89933CC3DF42ULL, 0xF1A09A10A95E1CABULL, 
            0x8A6BD1F6914D81DCULL, 0x9E70DEDC63EE9583ULL, 0x6843BF70B8445117ULL, 0xEB8B56292E7A8FC1ULL, 
            0x483D3B3C1AAD6F0FULL, 0xE2EE558DACF39EDDULL, 0xEB23FF5FECF6F268ULL, 0xFF9FD5D21FDCD29FULL, 
            0x43A1F28B269BCDE1ULL, 0x773AAF66CCDEE4BEULL, 0x31795EEE4E30CDADULL, 0xDEF12B1A30957285ULL
        }
    },
    {
        {
            0xCD121749789E5781ULL, 0x904146976F5041E3ULL, 0x150EB69A01FC7ADEULL, 0xBDE5E0CD218B4216ULL, 
            0xF11B2A9E454CA538ULL, 0xAECB434C2AFBC27AULL, 0x65B3D4E70B1EAC76ULL, 0xAA2108B87A7BFA5DULL, 
            0x0FA27652323CB554ULL, 0xC7A636F214BCC6B0ULL, 0xC6847E7B243020C3ULL, 0x2BCCA52F64C7CB24ULL, 
            0xFBFB16A053C235DBULL, 0x46656C51006A2037ULL, 0x67C817624A879E23ULL, 0x75372F576FB32441ULL, 
            0x47ED7F4D8A4E4075ULL, 0xEA9887A51CE0DF2DULL, 0xACF5CF2C1264ADB1ULL, 0x80A1DB0CCA9F9C8CULL, 
            0x1D457347B15511A3ULL, 0x1E5299BF9CFB90DEULL, 0xF55D3DD5A928240FULL, 0x39D5E6E3177801EFULL, 
            0x7BBBDBD4401D7494ULL, 0xCFC988CEFD75BFB0ULL, 0xFA18DA75CADF5A7BULL, 0x6FC12AC4DFFE0C35ULL, 
            0xCD130DF4E6D175F9ULL, 0xDCB5E262CF21CF5EULL, 0xD688DD44777AA783ULL, 0xD133C72FB820C431ULL
        },
        {
            0xF6AB1DBE0CE8052AULL, 0xCB057DD18955381EULL, 0xD59D731D571D4B43ULL, 0x622040D4132ECAECULL, 
            0xF9BBBAC6DE0E8E8AULL, 0xB391E0E44C49B605ULL, 0xF5D39ACD5D1E05E1ULL, 0xC9DCF268F2E806F4ULL, 
            0xD5E2F6835C8205D6ULL, 0x8EF76A4E052B22A9ULL, 0xD78606E3F8D83A53ULL, 0x340BE73BB0D4545FULL, 
            0x4F71DA95B7FE9724ULL, 0xBCD475C49AC7FDE9ULL, 0xFBAD9BEBBB5F1A94ULL, 0x1537DE09FFE5F877ULL, 
            0x76EADAD5B55EA1B0ULL, 0xE26F10D24FCA64B2ULL, 0x5CDCD695C628C677ULL, 0x7E4628116E8C7920ULL, 
            0x2143B57F03FDA026ULL, 0xE8BF7E7DB8493ED6ULL, 0x803EDF2F23B1B83AULL, 0x5F0C194B49CDCF41ULL, 
            0xDD5CCF14B4111476ULL, 0xF2083DB594B0A5C3ULL, 0x88B39FAE96E1E1B9ULL, 0x48B45DEC4ECF2B00ULL, 
            0x37622D65E57BFDA0ULL, 0x8E125A8C09F43E39ULL, 0x70C6268A8D161C45ULL, 0x343CB4BCC45AB6AFULL
        },
        {
            0x965BCA4FB8FBE805ULL, 0xFA447C04B6163D36ULL, 0x94EBFF89B4031B82ULL, 0xE5A2F73405EB8246ULL, 
            0xE254A72E356A26C6ULL, 0x72D2652F03364E6AULL, 0xE744ADCF6150B2BAULL, 0xEB473C6EE70F6F5EULL, 
            0x0ED8866D4E5457DFULL, 0x74F1EE7FE4B00F3EULL, 0xF7C8D372CD1D04B3ULL, 0xACAA2DAE167D13ACULL, 
            0xDD12B93BF67FEB2DULL, 0x262D162FBD2ED2E3ULL, 0x9A25DBE0B598BA6FULL, 0x4D74EED1A879DE08ULL, 
            0xDA32FDC3A7F0DE60ULL, 0xEF1610676155BC9FULL, 0xA1F91586BD845B86ULL, 0x2138CDE6D71389D7ULL, 
            0x0D098FFB888A2908ULL, 0x628258F08F59C9F2ULL, 0x16550F9A701ACECFULL, 0x65FBB45D8DB18E33ULL, 
            0x7D9D2AE5D22D8FBBULL, 0x6EA5217BB2A0A86AULL, 0x865918F13BE01422ULL, 0xEE7AA4DE51537015ULL, 
            0x5F6E699E78E9CFF1ULL, 0xD079413DA1D30DB0ULL, 0x87EB5A76728A254EULL, 0x9EBD7F9AFD605CB2ULL
        },
        {
            0xAEDFC42CBEB32EA4ULL, 0x22F97088A734283AULL, 0x04A7E28F11A7269EULL, 0xBC71E5696503E977ULL, 
            0xA61D83F21167DB78ULL, 0x88F0E6C8994C22C9ULL, 0x0F1A0AE791FB273CULL, 0x181372A451DAF0BAULL, 
            0x48A6DA4A24A96A5DULL, 0x761FC4B6E990911FULL, 0x9C7E91530AAAD740ULL, 0x6DDF287C4EE21429ULL, 
            0xF2310F88CD97F0D2ULL, 0x0FC120E61A28D4B7ULL, 0x040767D1FBFEC40EULL, 0xBDCBEF48388143AFULL, 
            0xA94A77A9A9FFBD0FULL, 0x5DB9A588004200E7ULL, 0x5C91CE999F0540B6ULL, 0x8F857A906A962A40ULL, 
            0x923EDCCF067BE354ULL, 0xF1C78C95D149378BULL, 0x2EFCA44DF04C071DULL, 0x4980EFDDB460B6AFULL, 
            0x14CABB9F18A8287AULL, 0x4F71DF7F217BF90FULL, 0xA3C7BB7E48E92F5FULL, 0xEF4CCFBE68AD972CULL, 
            0x4353821EC8EBEA3AULL, 0x01553B5A7AC65D63ULL, 0xBB8F1CB734D40ABAULL, 0x1215C0E1F44C589CULL
        },
        {
            0x3442CF192249183FULL, 0xF510840889FB9821ULL, 0x2CD2407BD3A5A1F5ULL, 0x51ADEAC19EAF9C23ULL, 
            0xA8DE74D57EEC7FC5ULL, 0x02BA6E1E7E46ACABULL, 0x33352BB277652CD0ULL, 0x7F2208D4C3A96879ULL, 
            0xA4E88A463B956C74ULL, 0xF295CE5E686A1BB2ULL, 0xBDE20D35DC9F99D1ULL, 0x5A7CB545A3260C22ULL, 
            0x3631FD47C801CA31ULL, 0x64C733700D408366ULL, 0x671A0A7FAEFAA5C8ULL, 0x9FB1B8BFC932E930ULL, 
            0x862FD85CC49FFC05ULL, 0xBD7D6DC00C1D2F46ULL, 0x36CA8D259F30040FULL, 0xE3757DBA85E3B724ULL, 
            0x2E10AB99C45C8818ULL, 0xF9FCBF8B0724C147ULL, 0xA0515C2B72CD0301ULL, 0x879B47363FE50436ULL, 
            0xEAA33DC9F6F7A967ULL, 0x3676700BF209C1B3ULL, 0x2646BFEB155ACC49ULL, 0x9AD9ED02F5620C26ULL, 
            0x8323AEA4B8C2D0F8ULL, 0x175FA7EA90EDD89FULL, 0xB4D729A1338D5542ULL, 0x0B278BFDB4429077ULL
        },
        {
            0x6221F28C9E50A056ULL, 0x0E703AF13611D27EULL, 0x2125EE13C14DFAE2ULL, 0x1779FBDCC09BFA01ULL, 
            0x3B1720DD7D5F9653ULL, 0xA77BB29557C6B3DDULL, 0x25F78E2E3DF271D5ULL, 0xB730AAD9B438186DULL, 
            0xBB1349883DF19EF3ULL, 0x7586C9F10CB54A95ULL, 0xDBDC054C689409D1ULL, 0x6918D53B41B8F871ULL, 
            0x8F998DB203BFD77BULL, 0x0EDD3078B0ED660BULL, 0x17DDE53DEE7839B9ULL, 0xFDD634EB38685166ULL, 
            0x605176654F0A8588ULL, 0xDA33BE565D532C03ULL, 0xCD989AD5F842691AULL, 0x47E187BB4BC395FFULL, 
            0x0BF481FA3CEFB673ULL, 0x38643D2C040BD161ULL, 0xB24F13E2DF7694A8ULL, 0x1958B97E2532421BULL, 
            0x6F1A98434D721A89ULL, 0x0AC46A012D2064B8ULL, 0xC7D290DC189044F0ULL, 0x3ABC9E0E32FA2A54ULL, 
            0x59890A6C7C711343ULL, 0xBAAA07FB437AB119ULL, 0x7338E06A28489F84ULL, 0x47164891C8508EABULL
        }
    },
    {
        {
            0x46D7A91DB892B98EULL, 0x61AE9D8A2BBF43DAULL, 0x784003299C3DBEC3ULL, 0x1BAEF2C2D6070C7FULL, 
            0x1AD3F3F5C8BFD1D7ULL, 0x3DA0858A9136AFCBULL, 0x22DD854DED211880ULL, 0x1D152658D58C4457ULL, 
            0xC2B3441229F58518ULL, 0xB46848E42E5E67E3ULL, 0x80946B772DE7DE3CULL, 0x719B55285B21B479ULL, 
            0x69E5A23B030085A8ULL, 0x2E69E3FEF6BEE07CULL, 0x01F04706538E96AAULL, 0x00C248DE4C98C22EULL, 
            0xDE819916E35FBF91ULL, 0x34BA76C87D4E6E6FULL, 0x6B30B5C5F3C09AA2ULL, 0x2B779C4301FCBF6FULL, 
            0xA7A988908DAEAA10ULL, 0xEA8D8B2EAA77582EULL, 0x8EB67A2391167A53ULL, 0x703159BC2DB6A647ULL, 
            0xF0E5727EEA53DB40ULL, 0xB05E736D733FAA25ULL, 0x4E2EA0D6A0583E51ULL, 0x16103E79E44A90A7ULL, 
            0xA358CDECC6DD89C4ULL, 0x1FBD7AE2D6BFA6C5ULL, 0xD734DCFE4C115401ULL, 0x2DEFDC4ECDE97750ULL
        },
        {
            0x56F912131D8A1858ULL, 0x042F137D0C593B2EULL, 0xE2F3E7E30700A54EULL, 0xC01798F4BF0A51B8ULL, 
            0x53374CA9AF90419BULL, 0x8207C9B2FD2E020AULL, 0x2026F01AFA9D8279ULL, 0x26C46614FF19606EULL, 
            0xA6086B135CE4B063ULL, 0x959080EAF3D6BD2EULL, 0x05C638B4EE75F9EFULL, 0xE7CC1E1F40BB7F1AULL, 
            0x272D9DDB4E44B64EULL, 0xAE03FD9664A1A49BULL, 0x98DF098FA0851FB0ULL, 0xFFD5545656810ED4ULL, 
            0xB294288DF3FB812DULL, 0x3626A1EB43430141ULL, 0xAEE811643DAD729FULL, 0x88871486A4A96C44ULL, 
            0xFB508E45E238EEADULL, 0x8B4190BDD0C30E5AULL, 0x439E1BB333DC2675ULL, 0xD6EC6EC7CDB781E1ULL, 
            0xB2B78D338CBBF3EEULL, 0xAB551E82566F3771ULL, 0x5F07F45219D3C07FULL, 0xEED980188C9D36BDULL, 
            0x8AF695CF76FC35BFULL, 0xDE0DA68D493D77D3ULL, 0x4779819E16FFBFEEULL, 0x56D7B36658BFA766ULL
        },
        {
            0x9EE29754753CDFCBULL, 0x816E0FD458DE5D99ULL, 0xA8DA04CFB5753750ULL, 0x888C3CA1255F7C72ULL, 
            0x1441100D4079926EULL, 0x3B8E7CC5F8BCA6F4ULL, 0x617CAC3629A2EC38ULL, 0x1AE9FD8A180E9468ULL, 
            0x5AE0B2ABEE973EDCULL, 0xB0790CEDBAAB98B6ULL, 0x3F148F6DF7935BA9ULL, 0xF4E6766C4D0B7BEEULL, 
            0xCB9FDD09E32995CAULL, 0x35707110F85C8AD0ULL, 0x09F16DCBC247D51AULL, 0x092F27745C6D2EC3ULL, 
            0xE4DE0831A89D098AULL, 0xC35C0C28EA9B68B4ULL, 0x6249CFFF9A3E9397ULL, 0x8AAAF69F8B809142ULL, 
            0x6A1C24D73FDE9773ULL, 0x1424BEACBCB4520AULL, 0x0AC43B93DA98F1ACULL, 0xCE05A2FA6EC08A1AULL, 
            0x7198E0F248842C34ULL, 0x6AD28A62335825C0ULL, 0x2B6935F2E492A5E3ULL, 0xCAB14A87AA207A90ULL, 
            0x29F9E26D65C23D40ULL, 0x3B2E0F853741DAF3ULL, 0x70C2BC7F002F11A9ULL, 0x21341A21F638D6FEULL
        },
        {
            0xF20B376F25F520C7ULL, 0x3438993CB49170DFULL, 0x1DAD2458E0A4572FULL, 0x5918919A85179FD5ULL, 
            0x1962D7F285727C5CULL, 0x5321FB05958DB79EULL, 0x824EDED50116DD9BULL, 0x5F2B94FC96904A5EULL, 
            0xB005E56F2C94ED44ULL, 0xE878CDDD06018474ULL, 0x2328B95989785C0AULL, 0xC5B6C71167336CABULL, 
            0xC06E2481B54C170DULL, 0xD0DFE4CBE3418890ULL, 0xA5CB49D7558B45BFULL, 0xA33A14148D9D8261ULL, 
            0x6E4F7BC1C77140E8ULL, 0x967C222D4C690EB1ULL, 0xD2D97A16279ED332ULL, 0xEDB16B48354C6AF0ULL, 
            0x9D616F31B084540AULL, 0x93476F30E914E540ULL, 0x45AB027ED1FFA26EULL, 0xDD3E5C48D3DE2992ULL, 
            0x810402F34E5DE3C4ULL, 0xCF477537049DA590ULL, 0xDC4A48FA0D5BBBC6ULL, 0x7FE93C5CC4D61924ULL, 
            0xAC439BCAB537C0BAULL, 0xFD0295CC5CFE4FFFULL, 0xF4F528553A543161ULL, 0xE9229C836C95706AULL
        },
        {
            0xA4ABE4E140A305E4ULL, 0x9829844CE773B5E0ULL, 0xC4708E6B6239CE71ULL, 0xB6C80981CB39EECCULL, 
            0x4A61B721E8B54A2CULL, 0xB4C68AB7A9617611ULL, 0x22601AA732FA4D11ULL, 0x2D129717C4C99D44ULL, 
            0x1ED4068A61C72EAAULL, 0xC828D7C098BA62A5ULL, 0x99E91BB7A1E4728FULL, 0x96BBCB9D053390D3ULL, 
            0x70A76C6675860A35ULL, 0xFF29DDC266E588EAULL, 0xD253F59CD6D3F0BCULL, 0xF5E22D3BC145B0D4ULL, 
            0x995C1F9C1DE1A60BULL, 0xDBB994A158BCD467ULL, 0x250AA7B6D2FC56C2ULL, 0x04F9E5BCFD194521ULL, 
            0x7070A891F7319890ULL, 0x6D0411306A2FE942ULL, 0x9BAC53551B1C6358ULL, 0x18C651D5BE91633CULL, 
            0xBD85CE569657406EULL, 0x26A0BF0BF7ABF9AEULL, 0xE5DABE0037DB1700ULL, 0x5BFAB1892B87A5D3ULL, 
            0xED5B6E842B1845D6ULL, 0xE329A6828BEBDFF5ULL, 0xAE1D7BE7DF52ABE9ULL, 0x98BC79A1E9F9F4AAULL
        },
        {
            0xD58C398AE166372DULL, 0x0CD78A621A7BE01DULL, 0xA9B6B3D01BEAEBFCULL, 0xE1B4AAD6D96A6FBEULL, 
            0x9B71BB87645CE823ULL, 0x9A09957DE37BB96CULL, 0x646C2FD82FD6D993ULL, 0x2A1D50102F2EF989ULL, 
            0x94F12CE08E3C9B41ULL, 0x4211DF626978D9B5ULL, 0x29700C5ED8D9ABA4ULL, 0xEE4B892DCA477E32ULL, 
            0x05D64364CB0A0FFAULL, 0xFE1948DE844EAAC5ULL, 0x612CA404A991E2E3ULL, 0xA7409C42E9CD1CF3ULL, 
            0x14B9E096466E535FULL, 0xB60F80D65847F75DULL, 0xD7FC2053F1C5049EULL, 0x14E4850BCFD7B71EULL, 
            0x36429A1C48215D88ULL, 0xFEB23B368E5044C1ULL, 0x0ABD290B4E2451B9ULL, 0xFACE2036427AD934ULL, 
            0x755A0D7945DF307DULL, 0x6B770CADEB30A7F0ULL, 0x615A6E598F404A3FULL, 0xC32E43009AC464E2ULL, 
            0x59F65CB011CC78F8ULL, 0xB4ED31A469B9E50CULL, 0x7115E45581F50E8CULL, 0x350A62310A2D2C6CULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseGConstants = {
    0x10BB69868771B0BCULL,
    0xD9CA871DA5FBE3EFULL,
    0xF4CD2E05F2AB5FE6ULL,
    0x10BB69868771B0BCULL,
    0xD9CA871DA5FBE3EFULL,
    0xF4CD2E05F2AB5FE6ULL,
    0xBE8E609979C7504FULL,
    0x0BB15074995057EFULL,
    0xED,
    0x9C,
    0x4B,
    0x9C,
    0x69,
    0xA4,
    0xBD,
    0x3F
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseHSalts = {
    {
        {
            0xB7B0626E05C14879ULL, 0xCD32148A31B66288ULL, 0x637A965F84294580ULL, 0xD57F8B9AFDE46A75ULL, 
            0xE564E99EE89DF765ULL, 0x75D1049B6C39B0BFULL, 0x228EE962028E59ABULL, 0xEBED9B3012C2C956ULL, 
            0x03BDF67340CD483FULL, 0x6D60D6F9EAC01002ULL, 0x573BBDCF66079E4AULL, 0xE924210E0B54C9BBULL, 
            0xEDFF5F6C8155DE40ULL, 0x6E26D92DF4FB4D33ULL, 0xE0EA0FF470DF9F7FULL, 0x86E5076085F05812ULL, 
            0x8A29F76C78D6B353ULL, 0x60B3D6D59F70661CULL, 0xD2401C286627EA9BULL, 0xD71E814C00B3A761ULL, 
            0x7D17FAAA3202CA51ULL, 0x498471DB17709657ULL, 0x3100C52B109F918DULL, 0xEF2EE1EDC477A40CULL, 
            0x4C1601314E19D367ULL, 0x5652AF1BF07A62F1ULL, 0xBF700C5CE555D063ULL, 0xCE6DBA4BB9D559A6ULL, 
            0xB6748AC4E04BC1D5ULL, 0x94269AE77F4F3ED6ULL, 0xE3FC79E882298021ULL, 0x88E469CAD8E13F74ULL
        },
        {
            0x8368F0F7F6F42C19ULL, 0xE02A583A741BD1FEULL, 0x69D676F957B94119ULL, 0xF3CB9241693C0CD5ULL, 
            0xB80914182C9291A5ULL, 0xA5AB0EBACC117AF2ULL, 0xF5AD2F67201423C9ULL, 0xA45014DDB55979C5ULL, 
            0xB922F3AE844C17F1ULL, 0x1C1EFF1D4559CEABULL, 0x5940C44800FA89CEULL, 0x67990C15E54F7966ULL, 
            0x915386D477128D58ULL, 0x19466D01E256E554ULL, 0x702E7B7BEE36CC86ULL, 0x26428F845226AC0BULL, 
            0xEC9C9E3076905101ULL, 0xFF88830F2AE223B0ULL, 0x2FAF07410D719957ULL, 0x75ECB6ADE25515A9ULL, 
            0xD84865FEB58EE507ULL, 0xF597719DB785DEF4ULL, 0x33E1DAC9657552D9ULL, 0x701B7BDFE866EC01ULL, 
            0x1DFA8F13AA2CFBD9ULL, 0x8A03F057BA5B4048ULL, 0xFF79703C36F8515DULL, 0x608A451FCE016DCFULL, 
            0xD732C59CBA29E5D2ULL, 0xEA1C1BCE3FA29B74ULL, 0x2481313B38AAF218ULL, 0x2610054F6097A41AULL
        },
        {
            0x30C08D04E609E9DEULL, 0x80661780EC7A22A3ULL, 0x2B13C33CF989F71FULL, 0xC0E42854CC22A030ULL, 
            0xD7B310A87AB28505ULL, 0x2BB6F97824C34B67ULL, 0xD98B3A5E7CCB78B4ULL, 0xA853D7AA551863CFULL, 
            0xA2D088E1ACCFD785ULL, 0x2627D76BB7CC173EULL, 0x01EBD2EB2BE3AACDULL, 0xD8411BD15790EB17ULL, 
            0x4A2937DC88BB7F86ULL, 0x67CC849375ECAAFBULL, 0xDB55C5A5718E5A56ULL, 0x2DA4BD5231228D74ULL, 
            0x757C428598A938ACULL, 0xE1353D2540A4612DULL, 0xD55C92D72595A12FULL, 0x799DB49478099301ULL, 
            0x19DEB2620FE5E928ULL, 0xCA45936CED4FFA8AULL, 0xECC8D2C720657580ULL, 0x6AD6C0D05C5AB632ULL, 
            0x82618EAD44F979A2ULL, 0xBDFC5EC3CF5656A9ULL, 0x67802271DF004DADULL, 0xC03829D3E305DD6BULL, 
            0xA4A0DD3044A04507ULL, 0xC357FB89D9C80F10ULL, 0x92051C789213489CULL, 0xE47FD10AAE3815A6ULL
        },
        {
            0x6F639A0729322428ULL, 0x23DD58DA468530E1ULL, 0x3250BBBB8F022337ULL, 0x09ECDB198B5255EEULL, 
            0x4D9368F549572F5AULL, 0x04BB9B275CF90E7EULL, 0xD165630702ABD3EAULL, 0x6B9A804637B82FBBULL, 
            0x0C03F273F92EE0CEULL, 0x42914D0AD88D18F8ULL, 0x8343FCF2C9A3027AULL, 0x7AAB16766103F9D4ULL, 
            0xB1D9FB0CEEB8504BULL, 0xA9850E0A5A4DD081ULL, 0x5102117BD53A3AB6ULL, 0xFF32F41351A0D25BULL, 
            0xC87E44ECEFA1E289ULL, 0xB9344E8C93347513ULL, 0x15AE16820CCBCE3FULL, 0x3C838E27C92FA3D8ULL, 
            0x5F2916FA48DE152BULL, 0xC09FE636EBA9B72AULL, 0x24ED7B3612469146ULL, 0xAD221CC2535CDEE1ULL, 
            0x01105C173632557EULL, 0x8DEB32772FEBCDAEULL, 0x8D3F65D0F9B085EAULL, 0x6BF95411123EC0E9ULL, 
            0x4D535D7B0816A869ULL, 0x0B5E88F8ED4DE65EULL, 0x962994156052D44BULL, 0x63ADE0B1E860A78AULL
        },
        {
            0x21ABA15F52355B65ULL, 0x8AC3174B4ED0D09BULL, 0x9FD911AF43694667ULL, 0xF6CF0557F4A8359DULL, 
            0x0C723362056A6606ULL, 0xA3B68B7D5880FD97ULL, 0x3841F3EA9DDA70B0ULL, 0x35238AA174C25AF4ULL, 
            0xD74E9426DB81E866ULL, 0x407ED5DC99196A5EULL, 0x8F611BD891B21630ULL, 0x51FF0B94F39D60CAULL, 
            0x0E39E904E2AD41ADULL, 0xFFE1987976D09387ULL, 0xE35F8179B52B9430ULL, 0x22CA527D0EB6B395ULL, 
            0x5772F7E81FA4CE07ULL, 0x708448E65AF20065ULL, 0x37703A3EDDC257B8ULL, 0x925472A4A4BCCF77ULL, 
            0x2F5A704CB2D97791ULL, 0x5766E96EEF9EC0D9ULL, 0x15D41481DC0DCAC4ULL, 0x88739E96F7EFB587ULL, 
            0xA73FB8776F64DE70ULL, 0x9189A7BAD5B55931ULL, 0x9A8D923FD479891EULL, 0x5ED070816FE66539ULL, 
            0x4E88E98131B9D807ULL, 0x028B94EBE2F7583EULL, 0xB4CB7E0E441C407CULL, 0xB7E10B6B6EE5E3CDULL
        },
        {
            0x64DE6286AC3C2F1AULL, 0xCB9BFFA29E288BE9ULL, 0xBF67A7CB8C39BFB3ULL, 0x52335C029C38DA0BULL, 
            0x70DA58370C8CE964ULL, 0xE5E0D07036F65231ULL, 0x3BE4CB46DF0FDAE4ULL, 0xA6C80F565B74F151ULL, 
            0x66A4BC3D842A8BAEULL, 0xC45A7D10C8F99BBCULL, 0xA439AF4255678DB0ULL, 0x92D27075B4B02E7AULL, 
            0x4160BE1A9AC24300ULL, 0x22EB8D1F189F7278ULL, 0xDBFB7173322C1D0CULL, 0x1DFB141D54E9AAB7ULL, 
            0xAA50713503F4AB1DULL, 0x9BA42DAFEBA420CDULL, 0xD7DA2DB57028CBF1ULL, 0xED797BF91D96AE87ULL, 
            0xDB4A3C274A944A94ULL, 0x5B0E2E57D4A20670ULL, 0xC0ABB0E258C50AB1ULL, 0x3EBFD8663112A736ULL, 
            0x3A327778B185F8DCULL, 0x58850463D768ABEDULL, 0x63DDBD96C1EAA6A4ULL, 0xDE1F400315B3EAF9ULL, 
            0x771DC892E2C31227ULL, 0x9067F7E10E3DE584ULL, 0x9C86B5359D49E0FDULL, 0x37C2DE2E6338CD9FULL
        }
    },
    {
        {
            0xF719197DE74A19BEULL, 0x63BB7E18E7434316ULL, 0xD24850C36D745483ULL, 0xE777CA78C4532B5EULL, 
            0x5FEF2E13BE70C9E9ULL, 0x6013638FFE2AF9D1ULL, 0x96D7A4F3A4EE2DADULL, 0x548DCF3007E4CF7AULL, 
            0x64D02FCA8DE20F9FULL, 0x6F69A90D136488EEULL, 0x01CFC7A1A5A2C0B1ULL, 0x8A63EB031781BBDDULL, 
            0x8BEFC615883291FBULL, 0x906C4C9765099616ULL, 0x9734C447CC86FBA4ULL, 0x2C6A097DFAB2780DULL, 
            0xFD5CD9C085E5333FULL, 0x1CFB6AE8234C47D2ULL, 0x713D9927054093F1ULL, 0xB39500371F79CDA3ULL, 
            0x5A094110EE0BEF81ULL, 0xB2DA4E2773C69EB5ULL, 0xB7F574AB3E49E142ULL, 0x223E060F1D3E6332ULL, 
            0xF96756B67484C739ULL, 0x5FD4F81A2FEC6682ULL, 0x640E40B7D36509B4ULL, 0x797418C30A62DDFFULL, 
            0x9B491E52D09EAF45ULL, 0xEE5FCB85E17B0178ULL, 0x49C229E8112A6D68ULL, 0x15078A4FA85C1691ULL
        },
        {
            0xAFEC246A28A0AFC0ULL, 0x4BDD4361B5E3FD24ULL, 0x17023CE3E53AEF2EULL, 0x3FD2E2BB617468CEULL, 
            0x0BAA48377F9F62A9ULL, 0x8FC552520180D19CULL, 0x8D18060DE6499A70ULL, 0xCB77036B7D7E96CFULL, 
            0x76C36C9E04BD9E33ULL, 0x694015CE4A2E07D7ULL, 0xD3414CE88AAAA055ULL, 0x83FE9DD7449BD1B0ULL, 
            0xB40F038B589993E6ULL, 0x386C0912640463D4ULL, 0x27B7791D99D99AC9ULL, 0xF9A7B3575C8F53BFULL, 
            0xFD18FCCD5CBA4BC3ULL, 0x79D2306A86803204ULL, 0x4234FB592EFF0174ULL, 0x24E9067E2EF06160ULL, 
            0xA63D9FEA7B97338CULL, 0xA5307FA243BF8D67ULL, 0x8BD8D904E72ED8BEULL, 0xC4E1641F29BD24EEULL, 
            0xA69EAE5F32B3FD89ULL, 0x977B1ACAD42B86E0ULL, 0x7CCADD515A0C0747ULL, 0x4247FBDEB21605F0ULL, 
            0xC39D360859545FFBULL, 0x409439592DFC6FABULL, 0x162055E03D2C88D6ULL, 0xFF74A352A0D920F3ULL
        },
        {
            0xC3E0578F837EBBA6ULL, 0xED84314699A7BE83ULL, 0x2C454A9BFF5348F6ULL, 0x1888A71519672734ULL, 
            0x620E1B497A374511ULL, 0xE8FB54E9163F6A97ULL, 0x8F228B18ECAB66BDULL, 0x2CAED21D7939BAD4ULL, 
            0x1403224BA56E078EULL, 0x360669477B203E1CULL, 0xBF0D170D2D0F5458ULL, 0x2CB7DEB63490CBBAULL, 
            0xAA27B9630BA36CC9ULL, 0x57AC7A56993419A9ULL, 0x24C55F0A6A41BAE7ULL, 0x6AC4132348ED78D7ULL, 
            0x121DA1F87E494BDEULL, 0x814A88AC91949AA8ULL, 0x91967275AEF2F242ULL, 0xDF25E60852314120ULL, 
            0x56B27A4AAD2E242AULL, 0xABEA7C30A7587DB7ULL, 0x86DA4A60BA99B1FCULL, 0x275A48CDD7E9C7A8ULL, 
            0x5EF1F1E489C336E3ULL, 0xAFE00711903D82BBULL, 0x449438789F2A0882ULL, 0x08D401D07897F9C3ULL, 
            0xE9E1C895734980CEULL, 0xE5DFE6C02F8A9FB0ULL, 0xD5CA3A3D42BB8068ULL, 0xB9802F316DB45547ULL
        },
        {
            0x6C9D6413EF07E773ULL, 0xC4D2AA5D768EAEABULL, 0x876414C6A5EAB8B4ULL, 0xE95C326FBFD0DFB0ULL, 
            0xA26C287F8F52D37CULL, 0x30C1F45E6102FA6CULL, 0x95835AA059E567BCULL, 0x5CA170148B7C0329ULL, 
            0x796A64F777040367ULL, 0x287387A5A6EFB164ULL, 0x0485A62DF70FB91EULL, 0xC1BEB54177E35D64ULL, 
            0x6C5BBE6265A5EA84ULL, 0x778A61640D0EC5D8ULL, 0x27CEF97B6D837D7CULL, 0x66FE4AE665688A50ULL, 
            0x1E195C46B1EFBA9BULL, 0x8D157D7092346418ULL, 0x16D89A2FD0A83AD4ULL, 0xE9A10BFA5F69E749ULL, 
            0x1C16BF6CD2DD51CFULL, 0x91753A3144B65A35ULL, 0xA386B4B92E8277BEULL, 0xB32A6A28F442FF26ULL, 
            0x9A9C00B7AE4D0047ULL, 0x94A862430D1E8985ULL, 0x99A3E23FB473747CULL, 0xD7000DBEC8C66BE8ULL, 
            0x82460DCF41333731ULL, 0x7F375769C1F1B8E0ULL, 0xF09B349F5AE4A057ULL, 0x6BB5187A41100A5AULL
        },
        {
            0x288E00F8501B2DF3ULL, 0x8C8E4C942D93F3F4ULL, 0x79497B7452479798ULL, 0x51E57E52F557F8EEULL, 
            0xC83A792AB5822C68ULL, 0xB6210C5DFAB7E342ULL, 0xDBE32971297670D8ULL, 0xB2673E900AE11001ULL, 
            0xF998759EBF353F80ULL, 0x16A1269259ED206CULL, 0x464C6FF4C60BCEBEULL, 0xDA4643DA2F0E5FF8ULL, 
            0x5F82F14BDF956599ULL, 0x55E7E84BFEB46F0FULL, 0x22DC225956C3F2AAULL, 0xDAACCFBD800FA556ULL, 
            0xF2193251E18B2F84ULL, 0xD58E5AA66DC16A83ULL, 0xDE017F007A6C2959ULL, 0x2C6B53D2EBC1E51AULL, 
            0xA3C3F32D5CD85BEAULL, 0xA82019FE4D144B49ULL, 0x9B1A7F47905FC743ULL, 0x68DB5A11B00FB1E4ULL, 
            0xF4775C72D3DD899CULL, 0x26F6456D3647A382ULL, 0x040669E8A60CF64AULL, 0x95AE8D68AD94C247ULL, 
            0xDD9A4D8B6B33EF33ULL, 0xF29B108AEFF0DBF0ULL, 0x4A9E226F3E816042ULL, 0x0ADC96D78EE7C4ECULL
        },
        {
            0xF0E6E48E242F8BA3ULL, 0xA4F7BDF9B74B9C34ULL, 0x9861B21498CA148DULL, 0x0B5B6F0E6BDD3389ULL, 
            0x277D927C5ED4E170ULL, 0x3C6FF59AFCDB2858ULL, 0x344D4095C891E9BAULL, 0xBF2714AAC1CDE9F0ULL, 
            0x33E9562C8D717C0AULL, 0x19F45AE73E96753AULL, 0x110893522E4A1D5FULL, 0x44822EF83E184A42ULL, 
            0x5A4AD480760653B8ULL, 0x4F14F21BC6DD1CBBULL, 0x6B3B79189C7C5542ULL, 0xDFCF831F605E326FULL, 
            0x0C11B58A1CE26CD4ULL, 0xE27F8EBEF08308C4ULL, 0xFC989E8DD9F6478CULL, 0xC5874DA73375949DULL, 
            0xA68E312A6FEF9C6CULL, 0xEBA3A2ADE139F18AULL, 0xD89B356B20A37841ULL, 0xC2EF5DEAB6B4A065ULL, 
            0x0B6B1B88E5EE4512ULL, 0xB826513BAABEB3A4ULL, 0xE8068828AE44951EULL, 0x322E3754A11F5C22ULL, 
            0x63D45CEB441D32A5ULL, 0xB71141F430C4A330ULL, 0xF315195268EE2949ULL, 0xDAE887A9CBAA3B48ULL
        }
    },
    {
        {
            0x1D89B34F601EBAC9ULL, 0x12AC1C44B68BB7E5ULL, 0x9604D27138504F13ULL, 0x2D72779C247599F3ULL, 
            0x02062453536613F4ULL, 0x51EB297AE1E48958ULL, 0xBE4A470D3C5C8F48ULL, 0xF819BFC4E3CCA91BULL, 
            0x161C4151C3777CC3ULL, 0x564F72B88BF21EE6ULL, 0x36CCD06B352CEFF9ULL, 0x09BA1691BD6895D5ULL, 
            0x5E05F2EFB5B02B2EULL, 0xC4635CBC6045200CULL, 0x379047835F5F90C1ULL, 0x70ADF3C45744A5BDULL, 
            0xCC6AAA2AED128333ULL, 0x91082AAB9AD345CBULL, 0x879EC721DBB7A466ULL, 0xAD01379A0EB06D5FULL, 
            0x1394E94A5FF73963ULL, 0x36162A6430DD2C16ULL, 0x741CE2AE95CBE5F1ULL, 0x1FC0361B0AB9A845ULL, 
            0xE9AD6AC3076018A7ULL, 0xCCEA6858B18D0586ULL, 0x26C06A2E15B61E70ULL, 0x6758E79F24B669D8ULL, 
            0x62BED9A0524BAC11ULL, 0x2040B54000BE1BB0ULL, 0x5CF4E1CC4053FC90ULL, 0x6B07D85CD7D0DEB3ULL
        },
        {
            0x199CD513B34BDFDFULL, 0x6DACD9F5F8F012ECULL, 0x9B126C0638535104ULL, 0xD32D603042E8D50FULL, 
            0x4C29C93FDACF1513ULL, 0xBFA4A3F7114208B8ULL, 0x089FBFEB1B2CDE45ULL, 0x308A76546648A847ULL, 
            0xC12B98042EFE9097ULL, 0xC1BE5481A9EC77F4ULL, 0x2966370D3A61BAC6ULL, 0x10DC5BA914CB1563ULL, 
            0x15BF0C9D64126B77ULL, 0x3A63ABB47DC64651ULL, 0x699953B5240C3963ULL, 0x98B36C5A22DBE01AULL, 
            0x4336DBD01865C92CULL, 0x2D63A30F6D85FA0FULL, 0x6BCF1702BE77AE61ULL, 0xCF9CE142964D54EAULL, 
            0xE6BCFBEFEAACE8E5ULL, 0x8B9BC7E7F3796FA6ULL, 0xFE54B15DBB7081DBULL, 0x56FC687FC8AA1F36ULL, 
            0x9FD556DF002404CFULL, 0x48101EE1DB8C71A4ULL, 0xBFEE5579212FD814ULL, 0xC3E5E904AA591466ULL, 
            0x94687ADB5F2AFD31ULL, 0xF8B4B41B1DF5BEA1ULL, 0x5B3B917D8D8FCA9AULL, 0x8D4F950C4AD676F5ULL
        },
        {
            0xA3317B9EAD59F801ULL, 0x2B3C3B703DCC457DULL, 0x07743198641BFB61ULL, 0x32981E4A288386FEULL, 
            0x67EB5847BD6EDBE5ULL, 0xE4C2E2A764A83B8DULL, 0xF5D67FC22369429CULL, 0xC27A774C140F9A16ULL, 
            0x5C26648A1F2838E0ULL, 0xF611C92220179BB7ULL, 0x30FEE96F4CD4ED55ULL, 0x801808342C5D920DULL, 
            0xA78D0A50AC72AEB8ULL, 0xEAB80EFF8F1F0490ULL, 0x8DC7711927ED75C6ULL, 0x1E058ABFCDD73E88ULL, 
            0x0367927BB3E2A242ULL, 0x8497F1DF5C9DBA93ULL, 0xE520CA30AFB6A748ULL, 0xA933F91663EA07F9ULL, 
            0xB2B368C01BF161B2ULL, 0x5911008412FE21EFULL, 0xAB149F31E22510D8ULL, 0x2F3CC6E667F641F3ULL, 
            0x67117E70859E3B0EULL, 0x938D0B93C908182FULL, 0x05327350CFC01825ULL, 0x5009D22352AB147AULL, 
            0x3BEA1A2D4C868126ULL, 0x9D26D8DDE5DE8C06ULL, 0x528154666223BA45ULL, 0x00A18B277827AA67ULL
        },
        {
            0x3B27357BDA77609EULL, 0xCC6E12A07294F9D2ULL, 0x092BBD24FC1A235EULL, 0x654D9C7CA5A82A98ULL, 
            0xE9FDD68E17543C8BULL, 0x8EADD82C8170D1B6ULL, 0x6E547BDB74F208C7ULL, 0x30EA78DB81BD2BCDULL, 
            0xFF4D313B4BEB528EULL, 0x33B41B7F696802A1ULL, 0x61FA6E1CC6514BFAULL, 0xBF9DBA0E159DB941ULL, 
            0x17F89D4F910A0790ULL, 0x5E91ACA138C3E300ULL, 0xD6AAC24E701F5719ULL, 0x36892CB48961346CULL, 
            0x4125C2D0CAE05718ULL, 0xB942C1BE93174F2FULL, 0xA59D9BC8A5FCED18ULL, 0x8D650921AC409885ULL, 
            0xB69A5926E2082573ULL, 0x1027956EF01D0829ULL, 0xF1B87094CA1D70D4ULL, 0xF09A046A96DAE26AULL, 
            0xCB84B89A2C34096CULL, 0x0B20D537A216FEE6ULL, 0xEEC08F9B1020A883ULL, 0x6539E7A00172EB86ULL, 
            0xACFFA75E67EE393FULL, 0x4B39FB0351B8ABD6ULL, 0x18E10F2518F7FAAAULL, 0x346F1273D1563376ULL
        },
        {
            0x470C5934067D7511ULL, 0xD09B47D07C32310DULL, 0x053D60344D70B7D3ULL, 0xC4000F145E7E6A13ULL, 
            0xFB543C4C00F9B5FCULL, 0x781C4288731C88AFULL, 0x04FAB1519DACD7EBULL, 0xF84242941FCC8DD2ULL, 
            0x23D9FEA8923011D8ULL, 0xAE4721513E722C47ULL, 0x98C787F53C137BF2ULL, 0x77AA8961BEEE7940ULL, 
            0x858306382069AA30ULL, 0xD3A0A2FDE887A7AFULL, 0xB04898424E5BAF95ULL, 0x2F675D71C00FB883ULL, 
            0x7EBE8A63E00576D4ULL, 0x33F6CBC23CC38FE1ULL, 0x96F29BC1998D124DULL, 0xC913C699F28AD75CULL, 
            0x46344C95515DA320ULL, 0x9A33FA4EF243DD74ULL, 0x38B34B13C766E085ULL, 0xD9A225C2AEEF01C8ULL, 
            0x8F8AE2937D5CD8F4ULL, 0x92C9D96F97AF5ED8ULL, 0xD5C167C30604C0EFULL, 0x816B7BC7DC7392FAULL, 
            0x1CDCF8E833DF88E0ULL, 0xB2B4613404AEA91DULL, 0xF1A800F2C2C6443CULL, 0x65677448E9031337ULL
        },
        {
            0xA084ACF0A4072C1CULL, 0x78A0E83AA4BFB01CULL, 0xC00D9193D1D528BEULL, 0xAE8FE34218FAD31CULL, 
            0x9FDE62A6675EBE33ULL, 0x6E1716CD70F395D9ULL, 0xB8AC4856BA216EF7ULL, 0x076C1584221E0C23ULL, 
            0x7657B7AB8ACBBC74ULL, 0x6A6DA0551A108582ULL, 0x6E8B3D59FEEF56F6ULL, 0x008BDB6D0A8DA035ULL, 
            0x4D3B13252B0C6027ULL, 0xE706DC380D04501EULL, 0x743B8AE94D9D44FAULL, 0x3EC3D180A02DB667ULL, 
            0xB9830BF2F86148F6ULL, 0xC71BCC5C94DDA68AULL, 0x837B87551D2CE482ULL, 0x0F07315628A3C3CDULL, 
            0x303D50E7A8E38943ULL, 0x357966C137BDCE17ULL, 0xD22541D6E044B19BULL, 0x4B3ABB5829FA3B6BULL, 
            0x219EBE556979DA92ULL, 0xF794AE4AED6EB5C4ULL, 0x48285D2BF6609B43ULL, 0x96A60B7F44768D76ULL, 
            0x8EF3EF1EF9147D1AULL, 0xF1102A43B562ECE9ULL, 0xEBC95D0BC792A50EULL, 0xED721FA25759D693ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseHConstants = {
    0xCE62E144B25E49D5ULL,
    0xC39ACE7B20397FF4ULL,
    0x82C9BE55ABB7C36BULL,
    0xCE62E144B25E49D5ULL,
    0xC39ACE7B20397FF4ULL,
    0x82C9BE55ABB7C36BULL,
    0x13059EDD473C41ACULL,
    0x276B50D8FD704500ULL,
    0x1E,
    0x9D,
    0x5F,
    0xA9,
    0x22,
    0x6B,
    0xA5,
    0xFD
};

