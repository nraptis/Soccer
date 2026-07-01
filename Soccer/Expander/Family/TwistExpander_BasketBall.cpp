#include "TwistExpander_BasketBall.hpp"
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

TwistExpander_BasketBall::TwistExpander_BasketBall()
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

void TwistExpander_BasketBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xE3A39A70E64EA572ULL; std::uint64_t aIngress = 0xF19F2D2416B19EB3ULL; std::uint64_t aCarry = 0xD39AA9CB34909F7FULL;

    std::uint64_t aWandererA = 0x8FC443329C0D8BC5ULL; std::uint64_t aWandererB = 0xF66F0DAC1DCEC235ULL; std::uint64_t aWandererC = 0x8AC26742BBC9A001ULL; std::uint64_t aWandererD = 0xBFFB4D043D286741ULL;
    std::uint64_t aWandererE = 0xD9C6F3DF2EC71939ULL; std::uint64_t aWandererF = 0xF96E12A4F309CDE7ULL; std::uint64_t aWandererG = 0x8BE29E2BE8D20419ULL; std::uint64_t aWandererH = 0x8C1E63627C797CE5ULL;
    std::uint64_t aWandererI = 0xBD10127E6DB3C1E1ULL; std::uint64_t aWandererJ = 0xAD80DACEA4E4CCDFULL; std::uint64_t aWandererK = 0xF4D4B4E9C4FF96EBULL;

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
        aPrevious = 12785534270196632692U;
        aCarry = 11068265706704373605U;
        aWandererA = 14253754674326948639U;
        aWandererB = 14976341554526461721U;
        aWandererC = 10272808748012442203U;
        aWandererD = 18118825956268400717U;
        aWandererE = 16356894523194485743U;
        aWandererF = 12531747137975784263U;
        aWandererG = 15598953335030541388U;
        aWandererH = 13111860244689095289U;
        aWandererI = 16694531178629454680U;
        aWandererJ = 16408643245326558938U;
        aWandererK = 17558821904622149818U;
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
    TwistExpander_BasketBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_BasketBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC46A442AF49D71B6ULL; std::uint64_t aIngress = 0xEE0FCC036A31E6FBULL; std::uint64_t aCarry = 0xE299662EBC303A9AULL;

    std::uint64_t aWandererA = 0x8BB34A76A397C104ULL; std::uint64_t aWandererB = 0xDCA1F05B1EA1DB4AULL; std::uint64_t aWandererC = 0xF16305D0438158B0ULL; std::uint64_t aWandererD = 0xCA6C55D1E9C61EA4ULL;
    std::uint64_t aWandererE = 0xD34DC814F66C09BBULL; std::uint64_t aWandererF = 0xB5BFBEEC3AB95ABDULL; std::uint64_t aWandererG = 0xD8BEFAAC2643FDC2ULL; std::uint64_t aWandererH = 0xB0BAB343AB8FA111ULL;
    std::uint64_t aWandererI = 0xF57EA2E307591F7BULL; std::uint64_t aWandererJ = 0xCBF2A3857FF4AC67ULL; std::uint64_t aWandererK = 0xBA3DF854F30EAFB7ULL;

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
        aPrevious = 18236073412094353430U;
        aCarry = 12710841520682203680U;
        aWandererA = 13738496119645868960U;
        aWandererB = 13038254799052268236U;
        aWandererC = 14236832366283496714U;
        aWandererD = 14325547026681619455U;
        aWandererE = 16385717200708428822U;
        aWandererF = 10389880651420143276U;
        aWandererG = 17101874853710151078U;
        aWandererH = 11837678911291219996U;
        aWandererI = 16914442466438745941U;
        aWandererJ = 13900790193719558464U;
        aWandererK = 16678690764774441625U;
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
    TwistExpander_BasketBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_BasketBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE76D9E92B79B40FAULL;
    std::uint64_t aIngress = 0xBF586B37D87E136FULL;
    std::uint64_t aCarry = 0xF6EF97F773A5B750ULL;

    std::uint64_t aWandererA = 0x91630B74DC529C5BULL;
    std::uint64_t aWandererB = 0x9F0E8DF4F43762D6ULL;
    std::uint64_t aWandererC = 0x8789D134A483C480ULL;
    std::uint64_t aWandererD = 0xB02FEBB3DA2866DFULL;
    std::uint64_t aWandererE = 0x909CFBAABD6B04B7ULL;
    std::uint64_t aWandererF = 0xE5565678B9B0675BULL;
    std::uint64_t aWandererG = 0xA471A6931EFBAAC7ULL;
    std::uint64_t aWandererH = 0xAC0FFB72F9F24216ULL;
    std::uint64_t aWandererI = 0x8B1E1E28959B0308ULL;
    std::uint64_t aWandererJ = 0x9FEBC1B8D9E0F21EULL;
    std::uint64_t aWandererK = 0xCFB32A9B5B4BB31FULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::Sha256Counter(aSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneC);
        TwistSnow::Aria256Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
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
    TwistExpander_BasketBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BasketBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_BasketBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA4D395B4F7A4AB27ULL; std::uint64_t aIngress = 0xB349596B5EB8C440ULL; std::uint64_t aCarry = 0xA0A4384F644B96A4ULL;

    std::uint64_t aWandererA = 0x994AA564BC020E13ULL; std::uint64_t aWandererB = 0xB4FB1A3B9DA87207ULL; std::uint64_t aWandererC = 0xB3D052550010FFC0ULL; std::uint64_t aWandererD = 0xF3FE705057199602ULL;
    std::uint64_t aWandererE = 0xADAFD0A344C96F0BULL; std::uint64_t aWandererF = 0xB071DAA3665786C6ULL; std::uint64_t aWandererG = 0x818FE4C9C7AB9613ULL; std::uint64_t aWandererH = 0xFC81DC9D5093F0ACULL;
    std::uint64_t aWandererI = 0xDEE1F2C67ADE8D31ULL; std::uint64_t aWandererJ = 0xBC9BEB8867769A78ULL; std::uint64_t aWandererK = 0xECAEF0577BB73FABULL;

    // [seed]
    {
        aPrevious = 14893089886153355773U;
        aCarry = 11619961569713835902U;
        aWandererA = 17160858780493102245U;
        aWandererB = 17731881842827560481U;
        aWandererC = 12630121014554670841U;
        aWandererD = 12049733054803124954U;
        aWandererE = 14769281321820296839U;
        aWandererF = 17432688361193035739U;
        aWandererG = 13079727726155587077U;
        aWandererH = 16799538861824106390U;
        aWandererI = 16473028044007124053U;
        aWandererJ = 17178947496730018969U;
        aWandererK = 11879565959566033694U;
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
    TwistExpander_BasketBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_E(pWorkSpace,
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
        // temp storage: scrap_a, scrap_b, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_a, scrap_b, expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_BasketBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_BasketBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BasketBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 3, 0, 1 with offsets 5228U, 6939U, 6045U, 3314U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5228U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6939U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6045U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3314U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 1, 2, 2 with offsets 1170U, 3852U, 72U, 3053U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1170U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3852U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 72U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3053U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 2, 3, 3 with offsets 4342U, 6335U, 447U, 853U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4342U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6335U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 447U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 853U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 0, 1, 0 with offsets 39U, 7721U, 4868U, 3127U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 39U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7721U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4868U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3127U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 3, 0, 2 with offsets 36U, 953U, 60U, 1512U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 36U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 953U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 60U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1512U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 3, 0, 1, 2 with offsets 2022U, 1088U, 293U, 91U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2022U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1088U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 293U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 91U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 1, 2, 0, 3 with offsets 1470U, 220U, 381U, 1011U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1470U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 220U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 381U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1011U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 3, 2, 0, 1 with offsets 900U, 958U, 373U, 1452U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 900U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 958U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 373U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1452U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 789U, 540U, 1788U, 1206U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 789U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 540U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1788U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1206U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BasketBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 1 with offsets 1890U, 1008U, 689U, 2255U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1890U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 689U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2255U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 2 with offsets 5112U, 1728U, 235U, 7351U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5112U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1728U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 235U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7351U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 1, 0 with offsets 5093U, 1960U, 997U, 3628U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5093U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 997U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3628U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 3 with offsets 3955U, 2777U, 5389U, 1105U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3955U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2777U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5389U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 7216U, 3137U, 6569U, 1309U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7216U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 3137U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 6569U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 1309U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1479U, 549U, 1096U, 836U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1479U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 549U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1096U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 387U, 520U, 294U, 1091U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 387U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 294U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1091U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 208U, 871U, 1127U, 710U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 208U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 871U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1127U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 710U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 713U, 398U, 853U, 982U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 713U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 398U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 853U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 982U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 0, 3, 2, 1 [0..<W_KEY]
        // offsets: 1648U, 528U, 1961U, 1443U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1648U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 528U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseASalts = {
    {
        {
            0x8E35471E2CE23EC6ULL, 0x2902AE7E045EFC88ULL, 0x2B993BB2FE3E6971ULL, 0x45A2FC3D97B1A564ULL, 
            0x1FB1CF1DBBEA980EULL, 0x59F300CF4C9232C7ULL, 0x99B02C81E60D9250ULL, 0x49FFB7EE25DA3022ULL, 
            0x3F534B31C6B8AD0EULL, 0x6A4B316AFB863690ULL, 0x4AFFCBF2BE4D8976ULL, 0x8FD9F3A6FA5FA7CBULL, 
            0x7540E6E40A26250EULL, 0xFFDD4C4F56487605ULL, 0x7E0D06C83B872A2DULL, 0x126A7F22D34A0B0FULL, 
            0xF8B0CA94E7FCADA1ULL, 0x7399CD6779DBD4A6ULL, 0x5F542BDBA8FCE7C8ULL, 0x33EE2F700FDF1707ULL, 
            0xD0AC26D3CFF46415ULL, 0x38EBCE7D9FD26D87ULL, 0xB53694A38F7FBD00ULL, 0xF1D8D3AC35F367F1ULL, 
            0xC64A4BBD512704C9ULL, 0x4B04B86F01456323ULL, 0xD06E415C13954F72ULL, 0x6A2EE0A6B9BF2EEEULL, 
            0x204920A9AD8CFAC2ULL, 0x9FBC7F4249D801A4ULL, 0xFA82B4176B16BE36ULL, 0x0F39E112AD67A160ULL
        },
        {
            0xF7089F6D41085E17ULL, 0xDED11FE6715E5057ULL, 0xF503332481534D1AULL, 0x38E0F96B6B1997A9ULL, 
            0xA5CBC518A3147B09ULL, 0x1FA5F3F8258EA6E2ULL, 0x84023D35E0601BA9ULL, 0x74955578C76E1E87ULL, 
            0x4C78C9220D08A341ULL, 0xB8269E28CCB81240ULL, 0xF3D9EDACD49B1DF6ULL, 0x1FC0208993B98472ULL, 
            0x336626B6075D66DAULL, 0x95DFB30C2DF82F2EULL, 0x587E48F107F9BBB2ULL, 0x0F21DE41301B3DB2ULL, 
            0x0BE05B99EDE30909ULL, 0x1CAFFF208C46E75DULL, 0xDA5E33DD6C7CC1F1ULL, 0x12B39ACEF931FC68ULL, 
            0x4FED84E1FFDB3276ULL, 0xDC17B272D5E55230ULL, 0xD3820008FE720BF6ULL, 0xDDA7402EF2813C3AULL, 
            0x9E2B66453F06F874ULL, 0xE44D6EBBEEC3C6EBULL, 0xDC04D70DE1833194ULL, 0x836A1D5C5FAA6A43ULL, 
            0x7284A2B0C7922A08ULL, 0x9ED42AEAC0004958ULL, 0xAC52DF8971EDB7ACULL, 0xAD1DE777B70CFA9FULL
        },
        {
            0x9D3264D3A5AFE6DFULL, 0x063F623E5E238807ULL, 0x54B8295A8E05FECBULL, 0xE473E60A12528D8BULL, 
            0x3A41BA9C96AE2F7EULL, 0xE98DAC2753EA9C9BULL, 0x490866D8B16B3E76ULL, 0xA3A4D8F3C8D09248ULL, 
            0x6B1D8BF0306DE0DAULL, 0xE044787915148E41ULL, 0x0E43AE357A65E157ULL, 0x097026C8A80AA2D6ULL, 
            0x8FBE12688CBAF417ULL, 0x18208E8A5795D9EDULL, 0x44F0693378077147ULL, 0x27ED58FC6F1AABB5ULL, 
            0x86AC68B50BD8585FULL, 0x84D78D2C0D87E0C7ULL, 0xC3BCA4C0A2F54357ULL, 0xDE3359BD1716CA58ULL, 
            0x660CAF0F790A2BD9ULL, 0x93E5198CE3134DB5ULL, 0x716B2395E52490F1ULL, 0x88BE7073931AEBDFULL, 
            0x30DAEA9A54972927ULL, 0xEE426FAB3FF30BDEULL, 0x49ACFB77C4CE3655ULL, 0xD8B4C299DABFCBF7ULL, 
            0xF96685E2F1311604ULL, 0x85E355281280C871ULL, 0x7A8E7082D51724D1ULL, 0x8ED7D2837782EDBEULL
        },
        {
            0x6D97C559F9058DC8ULL, 0xE683A688813C3FF7ULL, 0xF015CC262119E396ULL, 0xE93BB8C0891185A5ULL, 
            0x261358FB24E8F3F0ULL, 0x0D398192AB915602ULL, 0x57682B966F016EFDULL, 0xDC2AF8D9833C2AF1ULL, 
            0xE546C6E2AE1B69DDULL, 0x63C8F50EDE9F962CULL, 0xB7DFF5CD7959D833ULL, 0x4F989B07297098D2ULL, 
            0x8D8F5BA5DAEB75C0ULL, 0x3EFFB80251F0BD80ULL, 0x2D29FDC00C651465ULL, 0xD9F34A954B60702CULL, 
            0x6837379E36756F37ULL, 0x4EA9BC7B015764E6ULL, 0x5211E1CAABAB1B9CULL, 0x65670A1A96ACB80DULL, 
            0xC2A11B0CA42388B0ULL, 0x3FE72596D396625DULL, 0xA3D94CACCB1FCAC9ULL, 0x50BE22B1B3BAED30ULL, 
            0x92F4E7D0911C6AB2ULL, 0x05ECBE3A3BB87614ULL, 0x84E021AF07038833ULL, 0xCA2BD5872C38A222ULL, 
            0x615FEE10F6220B81ULL, 0x82A924293D98D634ULL, 0xBD1FBEC128689D7EULL, 0x06E3F03262B50674ULL
        },
        {
            0xD2A8EBB78F7FDECDULL, 0xA718CC4D2A759928ULL, 0xB98771B22ABCF49CULL, 0xC6A6DE411F4CCC63ULL, 
            0x051C07686DDFB772ULL, 0x5BC0B38A1C79491FULL, 0x69EED2F68A92133BULL, 0x590D8E0E145722F7ULL, 
            0x3D3F068DFD5150D9ULL, 0x8C554F5146FA6B60ULL, 0x4415F722B533B46BULL, 0xF12F2983CC40BE82ULL, 
            0xF081BA04B736FC2CULL, 0x6F9732B5E0AC6ED0ULL, 0xA0CE3160836017FEULL, 0x4299E00FCDF110EDULL, 
            0x9A549DE9EA3B2560ULL, 0x016190CA6DCD488AULL, 0x73F3AFECA37668A0ULL, 0x73E89EEFFFD7374BULL, 
            0x0446DF0DE20D1A5DULL, 0xEEF7ACA346181CF0ULL, 0xEDD131E3AFF74B55ULL, 0x6C8F63F26BAA2608ULL, 
            0x9308EA5A34ADF277ULL, 0x27D8AB1BEB217C89ULL, 0x94BA0FCDA37867E8ULL, 0x284E048AE27B365FULL, 
            0x98181142DFA0696DULL, 0x8413BF3A6F03FDEAULL, 0xB1C3C4E825A1C2E0ULL, 0x93F4B5644305FD38ULL
        },
        {
            0x8DE092ED59637435ULL, 0x7049DD3E64BB1456ULL, 0xE7A40F19F6BD128DULL, 0x4E3479FEF2119F79ULL, 
            0xA6ADFD417CCEF906ULL, 0xCD5C4F9742959708ULL, 0x0E0E7A4CFAF3AB97ULL, 0x19A84C0F599F794AULL, 
            0xE36B0BFEA4D26B65ULL, 0xEE26ED340AFEFB88ULL, 0x49CF829A9751650BULL, 0xA85A9A455AB5EACEULL, 
            0x2EB3923D494E816DULL, 0x0ACFE6F27A052EB8ULL, 0xB20B1808B45EFB26ULL, 0x56CA47FF9DF66EB3ULL, 
            0x804AD01861BE6E1EULL, 0xBD1AC73E72483D6EULL, 0xA188A9E21B4DD024ULL, 0x7A75BF3B61D446C1ULL, 
            0x41E01356BD9A6DE1ULL, 0x49613184DE9A2B7BULL, 0xE911D6E664F024BFULL, 0x41E42C27D9130A80ULL, 
            0x3787DEE5F9678E11ULL, 0xFAA3CD3DD7C63C33ULL, 0x86E295204D5F46F9ULL, 0xB89021BF9596C4DCULL, 
            0xDED674094DE65D1DULL, 0x0CEB44B1D24CF741ULL, 0xA594E4F90D64A46FULL, 0x9C01CD610057B8F7ULL
        }
    },
    {
        {
            0xF1C8436245D4FDA4ULL, 0xCBF84E98C69F04CCULL, 0x4CC128E5865F1D2BULL, 0x7A36F02D95FE3086ULL, 
            0x626CF7C897495797ULL, 0x12A3C9DDF5A9912FULL, 0x3C1FAEDDA011B172ULL, 0x18AE44016202B971ULL, 
            0xECDE3BFCBB975508ULL, 0x9E8A96E9E4C40397ULL, 0x3FB9ED8A3B209D6BULL, 0xB19243F31712C04BULL, 
            0xE85F80EC53F00015ULL, 0x54186276DD707DD1ULL, 0x481A14A90DA24ED6ULL, 0xF4060AD34545A673ULL, 
            0x670B5537354F99AAULL, 0x05A3B14EB77C407DULL, 0xD14499560CB9BF31ULL, 0x6D22F03266AF6F7DULL, 
            0xFD4DA441752B8114ULL, 0x1E2245B2972D1A0CULL, 0xCA34B3FF1F09E525ULL, 0xFA37C3AB0C9805A8ULL, 
            0x6D1F1705690A6D93ULL, 0xD34EDE80BB7BF02AULL, 0x635E6F95D89775B2ULL, 0x6EC1216EA45EA3A7ULL, 
            0x7AD306EFA75AC348ULL, 0xD6E7012D7D84C4D8ULL, 0x79737ECE7676550FULL, 0x3B21963EB07C2E50ULL
        },
        {
            0x7968DB061581CE90ULL, 0x7FF28CA51B49731DULL, 0xA0BEFF9184D244A9ULL, 0x974E02B0DDE5375EULL, 
            0xB2F60886DDAB0FB9ULL, 0x670F4C59CB48AE5AULL, 0x7612CE1FB64FDD5CULL, 0x0496060480D9F8DAULL, 
            0x681E578A33AEA9E3ULL, 0x98F53B940DF7DCD4ULL, 0xED98C772F06A5938ULL, 0xC603CCFE2D1811A3ULL, 
            0xA0FE0AB9C86C71D1ULL, 0x8C793A3E7AFBA7F6ULL, 0xB0880CDEF95980DDULL, 0x42DE6A85892F36C5ULL, 
            0xAB00BD721E2C0F14ULL, 0x953A77696034BE34ULL, 0xE6639BB81FB15B01ULL, 0xC485394F303580CEULL, 
            0x1955D49A74954884ULL, 0x9CC45597AEE0190AULL, 0xE4FA6D0C436E6A5EULL, 0x026FFB94D1777B2EULL, 
            0xD96325F3711F8371ULL, 0xFC8B121C1A6EA1EDULL, 0x2BF39980E6CE4F69ULL, 0x3535C36461EA5F53ULL, 
            0xEC1B2D240170F41EULL, 0xF015F2E4A926D2BCULL, 0xF397649880BFD759ULL, 0x01E9E0DC3A110693ULL
        },
        {
            0x19D14514C58AFBD9ULL, 0x2702FCFC59527E5CULL, 0xD1903A6DA34DC72AULL, 0x99871A496D2A79CBULL, 
            0x061FE07279E48A71ULL, 0x55DB3F71793AB124ULL, 0x504979A0BC71AC62ULL, 0x68CFFAEC1618F75EULL, 
            0xFC5EE7D672B77E5FULL, 0x530C929F9D53715EULL, 0xFEB10EF0B0794CBBULL, 0x4043A0E9CF64A52DULL, 
            0xFBD35AE0DA1E5E18ULL, 0x74F7403E872D0FDDULL, 0x2BD038D2DFAB5D37ULL, 0xED5F1360CB0099F7ULL, 
            0x9771F83AA6D3A511ULL, 0xED30EE86C489C88EULL, 0x7C5C9A8F1B1B7690ULL, 0xB02B7AB236AE07A5ULL, 
            0x01F318C5B84C8F16ULL, 0x649A818007465630ULL, 0xA4A0143099D396F6ULL, 0x21579EE0E0D03433ULL, 
            0x67286044A220919DULL, 0x09DE1B567C62482DULL, 0xDE56EB9409448CC8ULL, 0xA331022DBCF626F5ULL, 
            0x330E23120C3E0B57ULL, 0xD73EDB593B5B90E0ULL, 0x2BB090621D1F0857ULL, 0xE07D8FCFF6D654E7ULL
        },
        {
            0x44D8612AF75F6EB8ULL, 0xFBCDF14BD1B984EDULL, 0x830FD9F5AE662FB2ULL, 0xD56895FC23D0BF81ULL, 
            0x04E801FFAD3B716BULL, 0x7948C127BB4DB18EULL, 0x5A22E8DBA68B0B5FULL, 0xDAED14F149D91630ULL, 
            0xDFB826CFA37059ACULL, 0x7CDBE5CB0D890BC1ULL, 0x5EC27831B76E638EULL, 0x2111340C1FE1AAD2ULL, 
            0x16F043B441045ECFULL, 0xC048988F717F6137ULL, 0x2D8709B4384F9D75ULL, 0xFA51EA558C5BD728ULL, 
            0x8CA0797EDF2B355EULL, 0xC49AE4CF1411B25BULL, 0x54CAA338852BAB15ULL, 0x991929849BD91F4AULL, 
            0xEC6202C68BFE8048ULL, 0x1E0041D5EEF80344ULL, 0x77C2D4C22539B747ULL, 0x7577497E49A6B8FBULL, 
            0xED38EA9D8B9B447FULL, 0x3BDF1D9EE9208FCAULL, 0x547E42C1B69E7ECCULL, 0xA719CC6565C6857DULL, 
            0x4BF6E4B3E748AE93ULL, 0x8979139D58904906ULL, 0xB0C2E6B300E95596ULL, 0x8EB99D4CDCB8FA4FULL
        },
        {
            0x394245C57E83C159ULL, 0x4D973599D0082334ULL, 0x98B787836CF7FE39ULL, 0x43B159D0232CDEE4ULL, 
            0xDAD2F9065D8159A3ULL, 0x5BA46878A2CA6418ULL, 0x2E510861DD1D39AEULL, 0xDA7E41D0865625B8ULL, 
            0xAB589CF1C23F9A6CULL, 0xC180FA0DB68B67FAULL, 0x1ADC066630983364ULL, 0x103FB4C0D6AAC1B0ULL, 
            0x226ECA11D9E60C84ULL, 0x562C9EE646113007ULL, 0xDC1FE56962DC7713ULL, 0xBC35AA62A4FAEACCULL, 
            0x9D54A23849943E36ULL, 0x3B1CFA168153376CULL, 0x39105AB3A54A774BULL, 0x909FBFEE35CB7A0AULL, 
            0xDAB20898C19C97E5ULL, 0xE77427585814237BULL, 0xA91A19717A50B321ULL, 0xA3150FD91FC70267ULL, 
            0xC3D50A1B67580955ULL, 0x4108339D85E71B8CULL, 0x9827CAE056AB6D8FULL, 0xAF46C4EC6E2E156DULL, 
            0x443A04073F3E9487ULL, 0x3A4491CCD5617EE6ULL, 0x6737CDEB209016B7ULL, 0x51071BFDE6086462ULL
        },
        {
            0x266142408C383D49ULL, 0x2D7DB510156C6DC0ULL, 0x523B3B09F9F167F8ULL, 0x0AA4A50CDC672B21ULL, 
            0x496079C26EB8F6E3ULL, 0x83A41FACAD35C680ULL, 0x0F0A9BC3C5693DF0ULL, 0xC50C7C5A58927EE6ULL, 
            0xFE082AB6ED6BB9B8ULL, 0x6443FEBA6714E344ULL, 0x3A32C2E3823C6A47ULL, 0xE79C9D380EB26C14ULL, 
            0xEDDDE3F6F40B940BULL, 0x487F5ADAC1248AC9ULL, 0x6741FDCAC04B54A9ULL, 0x25B336E0EBB19F3FULL, 
            0x44CA86DEFBD84366ULL, 0xF095E859AFEA7977ULL, 0xDA745168C95B7B5FULL, 0xDFBC13C702EC0A02ULL, 
            0xAB71F06925522816ULL, 0x7211696D050B80F3ULL, 0x77D8A9B8C37FBCB6ULL, 0xAF8C3641A489BFDAULL, 
            0x9D1A8D286EAE9CCFULL, 0x8540F375D7AF0293ULL, 0x4C0E239BC8CF8C1CULL, 0x1EFB7441B6E69C15ULL, 
            0x40B56E77D46F6976ULL, 0x09C531AD640BA5BFULL, 0xF9FC447ACC572C9EULL, 0xD1B7FDAB4AD3509BULL
        }
    },
    {
        {
            0x08CEE9A0B1D563F0ULL, 0x9EFE19A6ECC96385ULL, 0xB2DBD1C2B85D23AFULL, 0xA18E734ED71AF017ULL, 
            0x07C3E1B09C49D31DULL, 0x9C5EE73EF8D80F3CULL, 0xE181CB9A8A6581CAULL, 0x2B69E316EF95344BULL, 
            0x7DC20AFB0064819BULL, 0xCB362BB4A17C248DULL, 0xCF8877F9E3EAE2DCULL, 0xABDF112ADC60FD4EULL, 
            0x5CD98D07C57446D6ULL, 0x43DE98FDECEE6E30ULL, 0xCB2E5E699B2B5F75ULL, 0x02E21D6391B389BEULL, 
            0x3DAC1C46BE6BA609ULL, 0x5EF579D743228960ULL, 0xB730D3CFC9F1B6EDULL, 0xFA7721D8C847DD2FULL, 
            0x93E9C26ADCFEEED7ULL, 0xFC41A452740D2C33ULL, 0xBE129C7955216128ULL, 0xCDAE282A6C1CEEB8ULL, 
            0x82369467AC6843BCULL, 0xD8F9B5FDBE535CB6ULL, 0xE7053FDFCA78D200ULL, 0xA7127AEB3FC34A25ULL, 
            0x7557912FDBC4B91DULL, 0x04282B365AE72447ULL, 0x806CC5D16740E14DULL, 0xB462383A7A4FFC30ULL
        },
        {
            0xFDA0C2D734F2F10FULL, 0x8AE12647017F0F1CULL, 0x7C68AC4537607CAEULL, 0xABDA2075402712F2ULL, 
            0xA886C446157AA4B5ULL, 0x397A873BF1D9F94AULL, 0x5A183F7455650DF9ULL, 0x55C335CD9E43BB46ULL, 
            0xF418FECA110768C2ULL, 0x1DC555D0154196F8ULL, 0x9426322D30933C07ULL, 0x8FB1B2D0101F2602ULL, 
            0x22FCD04B8B39C959ULL, 0x028C80618D7EEECFULL, 0x5A2E74F695AD94ACULL, 0x317BC1F702525F08ULL, 
            0xAA58F5A758B46DD6ULL, 0xCA3FDFDEBA5E1270ULL, 0x9E0D3C87853FAD64ULL, 0x83870E31302F1744ULL, 
            0x7F9F99170D629A04ULL, 0x141ED8028B72E994ULL, 0x638BF1D75E00356DULL, 0x54838A7EF6731FACULL, 
            0xB6FC22BF16523A71ULL, 0xE5B0CC2D67CF8E99ULL, 0xC874FDBC512D673BULL, 0xE7FEEE0CFC8C2F21ULL, 
            0x0FCB1C3EBBEB0D2BULL, 0x2538D412F58D7FD9ULL, 0x6D9043901F2E7FA6ULL, 0x71A619F6E5698921ULL
        },
        {
            0xAE9826A8226655C4ULL, 0x76CAAD94ED644178ULL, 0x62003A51C528B162ULL, 0x6C8D2A1D5FD4EBB1ULL, 
            0xAE2FD31EEB28B9AEULL, 0xB344642B1C366135ULL, 0x8ADE6688854DEB15ULL, 0x62D64D761F31C8EFULL, 
            0xF492148662100371ULL, 0x9378058555FBA605ULL, 0x3D0379D8EDEABDA0ULL, 0x3FD85A9771A4586BULL, 
            0x05E3036C8E3652A7ULL, 0x823938A910254404ULL, 0x48176FDD57C876F3ULL, 0x25922E6F7D530E50ULL, 
            0x932C2AAC5B208B78ULL, 0x32EFCD11F4FCA55FULL, 0xA1DDA6ED2C76F791ULL, 0xCCD805C10799EF2DULL, 
            0x3D255571674FF73EULL, 0x791318389015B0EDULL, 0x21E374F72A0232FFULL, 0xE53AFEB4E843E505ULL, 
            0x30565610E21401EBULL, 0x09974D5FC51E2308ULL, 0xF61A856546007315ULL, 0xF6FBF80E9B2EF19CULL, 
            0xF869F8C9C93C5FC1ULL, 0x3317BCF22D0FB0C6ULL, 0xA32E7F7C4FF2F222ULL, 0x27EA539956894645ULL
        },
        {
            0xCB3B4AC70231EBABULL, 0x2B9177F7FA831FAEULL, 0x1F3D50E55CADDC88ULL, 0x9268EE7509F44F7DULL, 
            0xA893413C8B72E5CAULL, 0xABF62C51F9823D76ULL, 0x336A5ADF29C6580CULL, 0xBAA6674CCA14F0B5ULL, 
            0x6EECFB6AAE64F116ULL, 0xAA1DB0BF3126E601ULL, 0x6DF58C08AF21C156ULL, 0x15D1BF3D012BFCF8ULL, 
            0x76B9DD0AF230F1B8ULL, 0x12814C2AC80B0BFCULL, 0xE4FD8B20C33F0F3FULL, 0x28324E8DDF34F688ULL, 
            0xC0A2F5229DAAC15AULL, 0xB85E97F32D1EA244ULL, 0x0603F251FD58747EULL, 0x0271D26F8DD85F72ULL, 
            0x31C9C9D9EE83265AULL, 0x4CBD22667D666D88ULL, 0xA390EFD8F7D60693ULL, 0xBF0AC019F6BDF510ULL, 
            0xFD976D9291F5E1A1ULL, 0xD4EADCE40BD88A6AULL, 0xEF0A4331A520C8C0ULL, 0x62A6B70B1AA8FB20ULL, 
            0x5F5C6E25F13FB383ULL, 0x8E463F98BB240ED3ULL, 0xC56FA036E6955179ULL, 0xE8E9DF6AD7D92AFEULL
        },
        {
            0xB57CF416DCB01579ULL, 0x8FCD0FC3669DB566ULL, 0x87A739EF3F6E7D74ULL, 0x070E36FBA0E9DF9EULL, 
            0x1FAC7DB319B50F43ULL, 0x146FBD501C2BA266ULL, 0x9BADFE39879499AEULL, 0x4195B9FB7BD44E4FULL, 
            0xCE61D95FEC97F603ULL, 0x0223949FF16B4220ULL, 0x3AEF473306D11E1FULL, 0x56E66FBAD921C063ULL, 
            0xA8821D4F32D3B4A4ULL, 0xA989E989BD629EC3ULL, 0x87924910472A9C78ULL, 0x6F190081350A74AFULL, 
            0x3AEE898320A4EDA1ULL, 0x7806D768B52C0DB6ULL, 0x311C349DE8AB35FEULL, 0x3BAAA5D90E92EDCCULL, 
            0x17EF4C7287FFDF0AULL, 0x9839BB4D4218952BULL, 0xC709FAEEBCFB3C50ULL, 0xA9EDC10667F6318BULL, 
            0x1FE9B9112BC62B9DULL, 0x465EE67AFF36C64AULL, 0xCF3C308EF61E3445ULL, 0xA77D1A4209C2A6F2ULL, 
            0x17A17B5467CC260DULL, 0xA0197FC7AE3212C9ULL, 0x81476B7E8530A9BFULL, 0x1606949D9B964043ULL
        },
        {
            0xE79874A9B6103526ULL, 0xB4696AB81B1A2B4CULL, 0x5021B8F03254CFAFULL, 0x669606F2D5CE29E8ULL, 
            0x9D7AF1767958BB9CULL, 0x67292EDDC9A86CF8ULL, 0x4B86B90E1F964357ULL, 0xD1684F1332970CA7ULL, 
            0x11DFBDADA7338936ULL, 0xB6E9AC848063B963ULL, 0x387FCA4D930D9942ULL, 0x3EFB133D9BF88B19ULL, 
            0xB7EEC190ABC3D79CULL, 0x1FBDD7F3EEA03905ULL, 0x9019048656FCB8C8ULL, 0x099CD09A5FCFB6F7ULL, 
            0x56D8B3E46AA7D534ULL, 0x2EAE26AE826ED3B3ULL, 0x2E4916CA0F3B87FBULL, 0x64544D15171513FBULL, 
            0xB741B54A84E8A2F0ULL, 0x3DFE6482EE1D62E2ULL, 0xDD7C0AE4BB18481AULL, 0xB6221E96B691B948ULL, 
            0x0D1472E95411BA0BULL, 0x77E092A256993F24ULL, 0xF8CBF6ECF37DDE84ULL, 0x6270C62126E098C0ULL, 
            0x6198BEDE21118110ULL, 0x74DFD980CCDC15C5ULL, 0xC18088EB0F303CE9ULL, 0x1493A98A25225391ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseAConstants = {
    0xD5259E642058514BULL,
    0x823A4FC1C4B87513ULL,
    0x75AF2BA4B835C3C6ULL,
    0xD5259E642058514BULL,
    0x823A4FC1C4B87513ULL,
    0x75AF2BA4B835C3C6ULL,
    0x0542593147C89836ULL,
    0x251E7311397B948FULL,
    0x60,
    0xAB,
    0xE7,
    0x4E,
    0x0F,
    0x15,
    0x59,
    0x62
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseBSalts = {
    {
        {
            0x273647D1699D61CAULL, 0x1508AA492254FB83ULL, 0x2C13929B2112AACBULL, 0xD2CE67D1BBF3D6CDULL, 
            0x46A7514F4C430BC8ULL, 0xEE037C76EDDE37ACULL, 0x28FC1BCB88AED645ULL, 0x194F5062FD3CFE79ULL, 
            0x0D7872D575694B86ULL, 0x99FFF476FA6B3892ULL, 0x3C83405E53F8210BULL, 0xC2229BA05387EC37ULL, 
            0x64A925482D87B494ULL, 0xCC4300D8E5B0AC2CULL, 0xB032CCA46D39D4F2ULL, 0x0A6F7E111172DCD0ULL, 
            0xA0AAEEE8637B0A5CULL, 0xF1EE6E968D0EB14CULL, 0x51A9B5ACE7DE8990ULL, 0xC339A7C64A7B8A9EULL, 
            0x8279818EB07771FEULL, 0x69C481E29E458D3FULL, 0x6DCA98024F677425ULL, 0x7E9B70EEAD6AC972ULL, 
            0x1877A72840EC9AA7ULL, 0xEF56BCC7D2B0DE00ULL, 0xBE8509E7FC6FF5CEULL, 0xCE205F390E77DBC8ULL, 
            0xECF63B66453ABF13ULL, 0xC26917B41E99DA76ULL, 0xD0EE498EFEF7AA8EULL, 0xCB206F415895A8E5ULL
        },
        {
            0x7B74065DDCA47B16ULL, 0xCBDDA2C2239BE591ULL, 0xE3AAE7759BFAC63EULL, 0x13F58E8EA23F58B6ULL, 
            0xD3667A2A3F1AF538ULL, 0x23BB2D4783BFDF10ULL, 0xAF084F45A543FD5FULL, 0x5F43FF1ADF3C2595ULL, 
            0x134FDADF4C8C833BULL, 0x27EB492E574D1DA9ULL, 0x504BA88FDA121B35ULL, 0x6A318FB11EC9EFF5ULL, 
            0x0FD37B7FEB878B68ULL, 0x5F6820826BDFAC4AULL, 0x5139B8E24FCB497EULL, 0x316D79873C466C02ULL, 
            0xD1C2B93FFECB94C6ULL, 0x6FD181622C7F5705ULL, 0xECDD586B5C04E55EULL, 0x449B9D4B3D2D0F94ULL, 
            0xFD788DA907779DACULL, 0x77F7FF29BF9B691DULL, 0x7B85DA2F9D804A8EULL, 0xA24B48307C13A2C7ULL, 
            0x390FECFF055DF2EBULL, 0x26FE79469BABCD1CULL, 0xEEC194595A0FDB1BULL, 0xEED85A1A6F875597ULL, 
            0xEBA082DB15A662E7ULL, 0x8C92D565F35D1B82ULL, 0x8EF6E5239B22A57AULL, 0x2A04966610FCFDA4ULL
        },
        {
            0x109E0DE06EB539E8ULL, 0xE55A1286772B524BULL, 0x7B4DBCE497A8664AULL, 0xB7D96786A5985AA9ULL, 
            0xC00441C57D13FB08ULL, 0xB656C6D8D9C9F3F1ULL, 0x009740554EA27A75ULL, 0x3DB4FB5901C7144BULL, 
            0x61349D3B196CA9B4ULL, 0xD4E29C9FA7C69F76ULL, 0x0A0EC68A9011AECAULL, 0x0B02597C0363BCCBULL, 
            0xBF1D071956308C74ULL, 0x47143C650F1A4441ULL, 0x5074C9608B523C7FULL, 0x3B4F79FE68323554ULL, 
            0xD218A86C916D0B69ULL, 0x6A1F642E0D528205ULL, 0x7A106ABD71C47C96ULL, 0x8D6F9FE577E9C7B6ULL, 
            0xDDFEB48A7404AE15ULL, 0xD9A0E0DDCA443E12ULL, 0x7050D944B4F23261ULL, 0x9E521E8A11F0BA70ULL, 
            0x9C390042F797F86AULL, 0x32742E174050FD6FULL, 0x32BFBB8104BC05A6ULL, 0x8F0CB5FA021D3514ULL, 
            0x76CA9A712FBA87F3ULL, 0x7D215D2C53AB829EULL, 0x4B19CA6124222D26ULL, 0xB13A08BCC9C1CE1CULL
        },
        {
            0x8E325EB285020E3AULL, 0x2CD70212BAEDC5C5ULL, 0xD0BF751C90D7CA4CULL, 0x5BCE6AD461FFE253ULL, 
            0xA2CAA2496651CC93ULL, 0xED9891C7586B1C0BULL, 0x04541D713C875271ULL, 0xF4BED4AAC01D9A64ULL, 
            0x16756BC84EB23CB6ULL, 0x165148F11BE9FB14ULL, 0xA6EF72E776E8178AULL, 0x80C9009FAB5DE52EULL, 
            0xC074082121F49C30ULL, 0x0932119A992084B9ULL, 0xCAC3DD6E5133B5C4ULL, 0x7CEB8AB8F71EB370ULL, 
            0x94CC14198AC5E2DDULL, 0x5899EA33BA1F787EULL, 0xBFB6FAB5037BD76EULL, 0x8786F4D540D8D2E6ULL, 
            0xE12B4C6A17BF3629ULL, 0x4C2FA6D90D8AC3A5ULL, 0xEE4EDE1662D6A428ULL, 0xDB0BE78BB0809A4CULL, 
            0xB7EAB550A21EDAD4ULL, 0x486CFF85A4107A0BULL, 0x532B63936F6E1C49ULL, 0xE847AB5744E26B4FULL, 
            0x8EE2B76EFA458907ULL, 0xCCF8D1CD78D71DDAULL, 0x02D47B0ACEB294EDULL, 0x0A59DC7BDAD9FF4BULL
        },
        {
            0x8792038DCBFD52E7ULL, 0x05B514D8B61BE5D2ULL, 0x4631E1F532F7D697ULL, 0x925A724A15B03A3CULL, 
            0x7DD2D0A7F7B2A0AAULL, 0x991ECA963DB85066ULL, 0x0A4AE015BCF609DAULL, 0x44A7A6470EE72E4AULL, 
            0xB9D2A5922FE6DE9DULL, 0xB70895AD88E97DFDULL, 0x2AB6C81DD1202950ULL, 0x6A7A794606A23D7FULL, 
            0xBC5D1BEE860713B5ULL, 0xAD0F7F94CA33721CULL, 0x024A36F0BCFE2921ULL, 0x40BD0F1D49EF5376ULL, 
            0xE8F8962D2E0E14BCULL, 0x749069406D226157ULL, 0x5710B7401B1BB951ULL, 0x7E48945DA939BAF4ULL, 
            0x264B610C9D07F803ULL, 0x08C45DDC6469F9D0ULL, 0x101AEA8B7DD86B46ULL, 0xA145ED3751D2D611ULL, 
            0x364C1E624E4387C1ULL, 0xD44235FA51A9C08AULL, 0xA6B37B2B6B73A450ULL, 0x79E4BDAEF2D3CFA6ULL, 
            0x787462ED5D1FB851ULL, 0xF1B78E897BCB1C07ULL, 0xC8196C6E47C6C023ULL, 0x40B91A4FB693D5C1ULL
        },
        {
            0x91714B7FFF4B2DFDULL, 0xEDF83179D6759523ULL, 0x0DCC803461F569F4ULL, 0x770CA4A8426EC1E3ULL, 
            0x749A3F7B48DACBBAULL, 0xA5C1E4C0FBFFB5CEULL, 0x59003F9061987F8AULL, 0x0D8F0683287DD0DCULL, 
            0xEBE4E1C735D39A96ULL, 0x1842459ADD8FF3EAULL, 0xD8284F9F2132C1F7ULL, 0xC723E037957EDD82ULL, 
            0x1CAED541507617C5ULL, 0x9E91C719E021454CULL, 0xE981EF3E8BF27408ULL, 0xE25D14AC66BFCB56ULL, 
            0x82811B03A16392BBULL, 0xA1E2473F131FE355ULL, 0xDA200207E43D734DULL, 0x7398704CF2F230DBULL, 
            0x7A3E3F34B38D3354ULL, 0x3B8AEDA1848CE6E4ULL, 0xF19B3E6C6B975ACCULL, 0x028DF054439ED7A9ULL, 
            0x01FC10FD52AE9E02ULL, 0x0FBF34A82731ED29ULL, 0xEF3D3664938BE639ULL, 0x50590D1A26C3F1C7ULL, 
            0x95899B50B921C7F7ULL, 0x00C6E2C46A9C374BULL, 0x6BE530CCE43EB422ULL, 0xFFA715D934C51F5FULL
        }
    },
    {
        {
            0x1CEA1932CE984284ULL, 0xF652E38A4568BD0DULL, 0xAB1B595EB7203A79ULL, 0x68C1BDDC4320B693ULL, 
            0x09F70963F2A052B3ULL, 0x9808581B752F0E3AULL, 0x085A05C9B8AB8707ULL, 0xCF7CDF95ED430936ULL, 
            0x144ED6D9EEDEC497ULL, 0xA566A4D2CCC7C6CAULL, 0x283E5B86CCC404C4ULL, 0x209060CC5C69DE37ULL, 
            0x0F0B4C14B5B4991DULL, 0xF1161B710A1FE2B8ULL, 0x73BD91D3B72E1578ULL, 0x1DD51C1B391ECB12ULL, 
            0x893E8AE5EC5F50D1ULL, 0x5D3584F0758504EBULL, 0xBC72652AE52AFF77ULL, 0x419BF26652DF4CE5ULL, 
            0x355773F879D5B7A2ULL, 0xAD44EC97C777F99CULL, 0x2C98070BBDF4AB04ULL, 0x3A6FC987A3454756ULL, 
            0x8D4D328717049960ULL, 0x9D8C83CDBD6DE389ULL, 0xA343223891E991F2ULL, 0xCA0302ECB8A0C37BULL, 
            0xEDD4A21B5149A460ULL, 0xFB168399588ADBCFULL, 0xE4CC66996DAB7E03ULL, 0x08A5E338803986DCULL
        },
        {
            0x6A412C63CF28F0E2ULL, 0x5A654EEEC42F0C63ULL, 0xBB7C8A00E2AD56C3ULL, 0x1AEC1BD46B1AD366ULL, 
            0xFDB4371A0FFC6E6AULL, 0x8257AA0EA5831D55ULL, 0xC90C4D44983FCD43ULL, 0xB8A19FA55440037DULL, 
            0x5CC57C0C31B6055BULL, 0x5ACA48E41A1BC677ULL, 0xF85163261B6CF660ULL, 0x8B0D026304290A2FULL, 
            0xA8078572E7A44C6DULL, 0x59F5E97505742CB7ULL, 0x152876B45059A6BCULL, 0x25EC0F6638196D1DULL, 
            0x54F5137B8F7AC08CULL, 0x86DCA4A9FF3D6380ULL, 0xD4AD571DFCAA6473ULL, 0xB955B93E346B498FULL, 
            0x7A881D9F66671492ULL, 0xFCA02240D30EB4C0ULL, 0x10C7B09F95FB9526ULL, 0xDC33F1B78A3CEF80ULL, 
            0x871B2D58BC7C0B4DULL, 0x9CEBF6905CA1AB36ULL, 0xAAB8C02AAEB33F32ULL, 0x6FF1BA120799CCB6ULL, 
            0x547931B5D559EE6BULL, 0xF332C60B185727CCULL, 0x24E73A754FCCD910ULL, 0x3363347EFF03DF41ULL
        },
        {
            0xF2E2003A4740DAE9ULL, 0x5164E371FD39FEB5ULL, 0xB6BC8A1F034A3C13ULL, 0x78F02B9FF0DFB9EFULL, 
            0x765BF6D7DF64FC5AULL, 0x75198139D7472A81ULL, 0x8EB7478C48280AC2ULL, 0x129AFA5E5B4E8880ULL, 
            0xC473E9BE991DFA4FULL, 0x65420E653926BCE4ULL, 0x3061F35572BCF9FAULL, 0xE05378F7728E6C40ULL, 
            0x4FD23F4C9F86F69FULL, 0x0C35045DDE52A62DULL, 0xA3FAFFA26A72E026ULL, 0x10C1C9B1242D47F8ULL, 
            0x54ABDCF10BC2D30BULL, 0x293935DD7A3E87AEULL, 0x90645E1E7EFC3D6CULL, 0x8A1DD27F68218BD9ULL, 
            0xD94D205051FEDF00ULL, 0x9A7B3607C29802B5ULL, 0x97D3E8EF4B6B8E15ULL, 0xC0CB7BF203C96DB9ULL, 
            0xDBE0D457B8BC4F14ULL, 0x6C2EE2BDBB0B6D61ULL, 0x4A1431F5064EEB60ULL, 0xF09D26F0CACD4D97ULL, 
            0xF5DCD0BBE99283E5ULL, 0xCEC0C2863106E13DULL, 0xF3050D43CBCC03CEULL, 0x3F853FCA419254E6ULL
        },
        {
            0x3A71261E87D1B2B8ULL, 0x5B89D08DEE701B01ULL, 0x4237E6F2ADB5DCAEULL, 0xA2012F8AB698BD46ULL, 
            0x71C376F663592939ULL, 0xD3F7DEFC04BA04FAULL, 0xF0935A9CCC9F8E83ULL, 0x97E57356E824ABFFULL, 
            0x351CC0E712365692ULL, 0xEAFAD20F8A69F3DEULL, 0x7217F8C7C2153A55ULL, 0xCF49A9A90C4B50BEULL, 
            0xA9FC208B12F5D65EULL, 0x7F52A7136ED168D5ULL, 0x7CA04ED72EEA42F9ULL, 0xAF59B4C1470D5ED8ULL, 
            0x45B9C00577C66179ULL, 0x35CE48C91F697708ULL, 0x798418FD480E4DE8ULL, 0x034BEFE16BE01276ULL, 
            0x6BFB207BE04607D8ULL, 0xF2030BB703FC1A04ULL, 0x71C88D353377B65BULL, 0xC74BE1587A5873B2ULL, 
            0x063056CD1686B105ULL, 0x0C22078B9804E6A2ULL, 0x770E0100F0E2412BULL, 0x3D006CF62BC4739BULL, 
            0xEFECACAC4A79CB59ULL, 0xFBB5F4439CC9BD67ULL, 0x8F119566B7E335B4ULL, 0xB79889C53326418BULL
        },
        {
            0xBDD7D2C915337CAEULL, 0x673928F318E317D2ULL, 0xA2766509095CB985ULL, 0xDC3D22298E27CA3EULL, 
            0xAF8B3EE446AAE4B1ULL, 0x345AD8C44CB6D7EDULL, 0x36E1E11E8CFB8F78ULL, 0x9E1CF01BCFACDEDAULL, 
            0xC61E666F4E9895EEULL, 0x96730DB4A8AF5277ULL, 0xCAC1246B3D98B85AULL, 0x3A19B920DA34C834ULL, 
            0xD9D9C6E5432DE7CFULL, 0xE51B67E3FF5B50C7ULL, 0x86FDB2D3283C66B6ULL, 0x59EFB2DAE7A4DE56ULL, 
            0x6B9279CA027D0E5CULL, 0x6758C064ED71CC2DULL, 0x7654E7DF9935A73BULL, 0x9D45C9688DC35B05ULL, 
            0xDA3DCCD7F4B14F15ULL, 0x5D879DA4D34DC049ULL, 0x434D00D9EF17B123ULL, 0x4ED14C4DB2D138F4ULL, 
            0xD1CE4E2A2F2BB131ULL, 0xCEA670369A3AFEE5ULL, 0xC3C0DB5429DF4C5DULL, 0x7789CD52041F83BAULL, 
            0x44050256C02D23ADULL, 0xA1028462FDF17785ULL, 0x57F4F60E877CAE88ULL, 0xF199A07914E2BF8FULL
        },
        {
            0x6918998E19D2E81EULL, 0x35E62ABCFFF9F4A4ULL, 0x6C96821C351C5C5BULL, 0xF11629542B8FBA24ULL, 
            0xF213F6B5A660D5D9ULL, 0xEF7853FA5CB20A2BULL, 0x5F3C3E0C1E8CAC96ULL, 0x95545D564199F56DULL, 
            0xD3A849DBE9F15081ULL, 0x85B18C7894ABD7CAULL, 0x03BF566F85A80B13ULL, 0xAA5C9D3D8DF03AC8ULL, 
            0x2FC90B7DED60B089ULL, 0x9E1DA71D0A913F60ULL, 0x2648F4AC18842008ULL, 0x70FA6FB602D2EAA0ULL, 
            0x25455F80A20D32DCULL, 0xFEE77D936E073C60ULL, 0xC6553A94640D276EULL, 0xFB18A9F579898D57ULL, 
            0x0BBD1405946CFDC7ULL, 0xDACB0D876191FF68ULL, 0x08010CE196122F37ULL, 0xC4AC714BFD027BB4ULL, 
            0x86DD8CEA7B98AF7BULL, 0x28F0B7B1D0F326B0ULL, 0xE3588C20C68FE755ULL, 0x3496115F9A0B1827ULL, 
            0x59D18E2D57F36A77ULL, 0x649671F723D3C774ULL, 0x9EAFF80A11854C81ULL, 0x613D2740A4366E34ULL
        }
    },
    {
        {
            0x936D07B662A182A1ULL, 0xC06D35CC1D389AE7ULL, 0x3535226F99FB5A12ULL, 0xEC137D91EC2A4C5CULL, 
            0xEEA36BD68F07C2CEULL, 0x9791D6C9F9594382ULL, 0x5F3775AAF98B0E24ULL, 0x9DBDD4025C4662E8ULL, 
            0xFD03B4D2F9289CECULL, 0xF8B223179F4437D4ULL, 0x94CE8766DDF0BF85ULL, 0xF4496D72D95D187AULL, 
            0xED1C07CCD092054AULL, 0x7012C98B9DFB0711ULL, 0xBF39150F8FE5A3BCULL, 0x9B0266B1857C01BBULL, 
            0x71A0192C40200692ULL, 0x4017A7B129131771ULL, 0x9CB2F80D365B7413ULL, 0x4B57D9E0C7AD012BULL, 
            0xCBA89AE825DBB5E8ULL, 0xCEB15436606EC92DULL, 0x3C34D5434134F778ULL, 0x251103B248EC1169ULL, 
            0x05AD96787F0B3D27ULL, 0x23A07968D9B4F370ULL, 0x363E6570C4E71B5CULL, 0x09A1D5F2560888F3ULL, 
            0x4BAA4631141A3A71ULL, 0x03593189812A2822ULL, 0x8FA5551E68846C05ULL, 0x11EBB9D2D758DD39ULL
        },
        {
            0x700A0BFB5499FB2BULL, 0xF610A6D31B337A7BULL, 0x431D98C5AC1B4F05ULL, 0x7A5B8A13099BA092ULL, 
            0xE39BF730971CE7BFULL, 0x6E13508194FDFEA9ULL, 0x6AD51E40B833A06EULL, 0xC427D1DBDE13B3DCULL, 
            0x30DACD29C1927328ULL, 0xF97F3B2C08CEE51FULL, 0x71C06FBA853AA3E9ULL, 0x41CECF776BA8E496ULL, 
            0x6838025F6BD1A69CULL, 0x2A72946730A20D0CULL, 0x6D8714E67E8BB33EULL, 0x5882785BBB88E8DCULL, 
            0xBF9B99DC149FE192ULL, 0x19C6816231C914FBULL, 0xEB1634EB8A38C610ULL, 0x3C2B05B591BEAFAAULL, 
            0x1E105B957D6F8911ULL, 0x5338C28EC07BA018ULL, 0xFEBCAC9131CE054CULL, 0xCC257501B3AB4F76ULL, 
            0xACDB6C284F9E98B1ULL, 0x1020D5C882F8C28EULL, 0xD1163409C7A8EA20ULL, 0x8AAE9F134B62BFAEULL, 
            0x662D21F508FDC6AEULL, 0x3F07DD32E127A079ULL, 0xAB431E93C36B9AC5ULL, 0xE2FBC08E68E5CBCDULL
        },
        {
            0x90ABB41A7588AC13ULL, 0xDDEE0545AE896519ULL, 0x53EAF222724B1FD7ULL, 0x2032716A9928424DULL, 
            0xCE36B92E1852AF44ULL, 0xE40BAEB0FE8742FFULL, 0x8331108D152A03EDULL, 0xFBB997F70E890889ULL, 
            0x4175D65CE784B675ULL, 0xA9F9B080142AC4F6ULL, 0xAA0B33109272481DULL, 0x781F639F0AB9CD27ULL, 
            0xD4EF19419410C01AULL, 0x65711847FF212C2FULL, 0x421D9EDB6A66FA63ULL, 0xD9B023444EAB06F2ULL, 
            0x0068002FD054AA67ULL, 0x2CD24F764C7BBF4BULL, 0xEEDCC9A733B20BBCULL, 0x1D8E26238FBE3E3EULL, 
            0x16C87DEDDE57953BULL, 0x1BC1FAD9C3DAD6D9ULL, 0x86F162771BFBBE99ULL, 0x4DC747078FC4675DULL, 
            0xDE868F49F7BD08F4ULL, 0xF04F4E11C45B27ABULL, 0x5E701611EAFE4D43ULL, 0xC0CBA3DC4561E36BULL, 
            0xF5CB74AEB9D8066BULL, 0x230DECE8045BBFBCULL, 0x4AED677FC27DC512ULL, 0x687BA22AA7B04087ULL
        },
        {
            0x916F46393B5FA916ULL, 0x7E812EF25443824CULL, 0x45102839A5FAC0B8ULL, 0x5103C56647F8C1C7ULL, 
            0x2AD300E292133A57ULL, 0xB3426C030CC9319CULL, 0xA67AF1E32047454BULL, 0xD0585F9A89ACC2E4ULL, 
            0x358B1750383FA6C1ULL, 0x99AD7F7F2C7DB25CULL, 0xE5D03B14971D3E0CULL, 0xB14563E118DB8671ULL, 
            0x80554F427AA3A948ULL, 0x551D6EC3D1FF4A06ULL, 0x78B1A3215F49E7ABULL, 0x749B7839F535C826ULL, 
            0x60ED3CEA916A6FCCULL, 0xEE4F6F38A5015B6BULL, 0x28352C1F970ACDA1ULL, 0x4CB6EBCC2F40979FULL, 
            0xBA3590D80D5FF9F8ULL, 0xAF98B51F0238EDDEULL, 0x600B4740B9BCB532ULL, 0x13952EC9DDE324B5ULL, 
            0xB9F7B3E97567F1F1ULL, 0x8D8D4B70B9A95BBEULL, 0x267443219DA7BFAEULL, 0x31684FBA843A9B90ULL, 
            0xA708E389480B0774ULL, 0x24B5DF5EC7914CACULL, 0xF0A1AA4F2B5FFEB7ULL, 0xEF40382CD6D538EEULL
        },
        {
            0x4EFF18C41E2ECE61ULL, 0x1DCA7D00B5AE3ECFULL, 0x95F29DE027C71D90ULL, 0xB22204DB18EE95DDULL, 
            0x364AD96BE1E4A39EULL, 0x6FB171FBB62DBAE4ULL, 0xA0C91F6A86EB061BULL, 0xC2C641AEEB2EB993ULL, 
            0xB2E0468F7B708E96ULL, 0x33B074FF1AF1769BULL, 0x217EF7E0823FEE2BULL, 0xFFFE43FA56699BA3ULL, 
            0xA7F29947C945C10FULL, 0xE58340B99E5AC179ULL, 0xD2AE216CC1F74737ULL, 0xE94760BFF1749C49ULL, 
            0x535F78A4FF2A5267ULL, 0xED50624EDD78616AULL, 0xAF41CF114091C11CULL, 0x7CF38DD6A68A0304ULL, 
            0x6E8513F30D7BF1E1ULL, 0x86EB5B295DD7E69CULL, 0xFD8DEBC748A9C49CULL, 0xDC5D171CDBF0ADA9ULL, 
            0xC2B4AB833208A058ULL, 0x96B9772AB075CF8BULL, 0x540E25090A56A59FULL, 0xD287E5A587C7D170ULL, 
            0xBEAE768BE3830C63ULL, 0x2C13095C51EAD1A4ULL, 0x4A3D2BA182BA5739ULL, 0xADC13691692862A2ULL
        },
        {
            0x2DF7F60407D8815CULL, 0xC5260C3E4D3BE561ULL, 0xF91D437B11E66847ULL, 0xF60EEFD387274310ULL, 
            0x3E3BE385CA2E31FCULL, 0xD448EEB2434908F1ULL, 0x175EDFBE29636BB8ULL, 0xD1C6E0762B647395ULL, 
            0xD9866C72CA395519ULL, 0xE3B728CE32484316ULL, 0x0F964657139A2453ULL, 0xAD4CAF8E4FA0F776ULL, 
            0x5CBAB78E34A0D6ECULL, 0xE590FCEC328A5310ULL, 0x321CBB5EEA1CD62AULL, 0xA44CB2B8E5ADD82FULL, 
            0x3BAAE6475D40EB9FULL, 0xC6D185685B006B52ULL, 0xA9A7F3BB547393DCULL, 0x1E2DF957C0041400ULL, 
            0x0A5F7D245F6A75E4ULL, 0x5691CDF21CBE3E4AULL, 0x06BE43AFC139DC1FULL, 0x62FB33B2F606C1E2ULL, 
            0xBAAAA45AA580B2CDULL, 0x841BBF461F125BDEULL, 0xA4F3C879CF245EB3ULL, 0x491DDE8F2A1D317DULL, 
            0x29DE1D8D7D1B6723ULL, 0x8F024D8F04A14ED6ULL, 0x409AFA953307D24AULL, 0x0D04625F1420638CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseBConstants = {
    0x411B190ED4F5D8A4ULL,
    0xBBE7509A60D115A3ULL,
    0x4AFEBCBBFB84C1E7ULL,
    0x411B190ED4F5D8A4ULL,
    0xBBE7509A60D115A3ULL,
    0x4AFEBCBBFB84C1E7ULL,
    0x7C18DCBE899DE894ULL,
    0xD415751897CB088CULL,
    0xAD,
    0xF2,
    0x2C,
    0xE5,
    0x87,
    0x08,
    0x26,
    0xD8
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseCSalts = {
    {
        {
            0x0B8D58DE72B5C52FULL, 0x01E83756D660ADEBULL, 0xF3F5F656195D6CD3ULL, 0xDCABE27326EAA1AEULL, 
            0xDD4B349E52E44D2FULL, 0xAF679BD4C2CB9F12ULL, 0xA2DDBCC3BD2EA447ULL, 0xAF83DAB5481E3EDDULL, 
            0x0C581E32DD7AD92AULL, 0xCF69272DEF1CF3C5ULL, 0xF567D598A52EE2E8ULL, 0xD348C593887ED1F6ULL, 
            0x680ACCED1F394BE4ULL, 0x2C941AB5267EE619ULL, 0xEE918F2D35CF25D7ULL, 0x3483421C45082E9AULL, 
            0x1BFCB8E0AC65748EULL, 0xF404B2B25E937C2FULL, 0x146D07B86FE84E1DULL, 0x08970C550C987430ULL, 
            0x3A2849CCC47B966FULL, 0x9CB91D82A63E5D30ULL, 0xB2C77D32AEE0DC7BULL, 0x87E716592DF9565EULL, 
            0xC22743337B6E1C0AULL, 0xE11C0130A1030CCCULL, 0x98055F0955918B66ULL, 0x4E022BFBAC69B8DDULL, 
            0xE3CDDC623D560404ULL, 0x4F08A6A393DCF313ULL, 0xF534291A6A114EDFULL, 0x9DC758D0D6B2A7F1ULL
        },
        {
            0x5CA3B676EF874E6FULL, 0xB922D24396008CDBULL, 0x466514BC6B4D2BDEULL, 0xAFCC81D47E557221ULL, 
            0xFC31565224CA3A06ULL, 0xE6A4A5BB18A1D575ULL, 0xD93A7541FC82054AULL, 0xA3B2F612C0E7D6A8ULL, 
            0xD410CCDFAE06A7DBULL, 0xC799D56D255918BDULL, 0xF72B1BE3F696CBA4ULL, 0x90CA15A68403F648ULL, 
            0x9FA0312A58D9D463ULL, 0x7B1136FF8976572FULL, 0xDE91A258A4C43639ULL, 0x680E99BA07D5B62BULL, 
            0x69C22C9A3E095408ULL, 0x4977075017F54F83ULL, 0xBEE859335DE062DEULL, 0xE4C6969824F8097EULL, 
            0x8B9FD679013B159BULL, 0x164D8844B2424314ULL, 0xD7A5B9C8CEB3F38BULL, 0x811F7590F5B85BD3ULL, 
            0xB7B23A457CC96822ULL, 0x99A6949A788AE6ADULL, 0xF3C4E7532A99DBE2ULL, 0xFBB7F81956322380ULL, 
            0xE6970DF80F2F2F6FULL, 0x7FA1DA25A44F01B4ULL, 0x3606430510C42CFDULL, 0x72702750DC63F73BULL
        },
        {
            0x1BBE129A532ACD41ULL, 0x6792D0D5A03963D5ULL, 0x3FA757FAFA6B908DULL, 0xF17D1935797753FDULL, 
            0x05E2EF86E256FDA4ULL, 0x3EEE304C7EC76FADULL, 0xEFBC913A01FE18AFULL, 0xC419CA1AF3F14BECULL, 
            0xE9ED8E24CF55F073ULL, 0xEA582898F91F6ACFULL, 0xB4F2AD0A3CFAD2A5ULL, 0x109A0872AC037E78ULL, 
            0xB5C5986B7B061664ULL, 0xFE94726BD1D79B09ULL, 0x9989E24393F96B53ULL, 0xA6B1772BE0ACD314ULL, 
            0x58DEDD4EFD95FBEFULL, 0xD009CA3D647C69B5ULL, 0xA9909C6C3F1D4FC0ULL, 0xECA64DD8041CFAD8ULL, 
            0xA248C70B41424A96ULL, 0x1033F0B905A75D42ULL, 0x7B3F56B554858223ULL, 0x570116D4BD63084CULL, 
            0xF920073367146CA7ULL, 0xC36FAE1D21408174ULL, 0xD1A1293D3024FFFBULL, 0x4AC6DB9C81A7A830ULL, 
            0x3A46AAE878C4382FULL, 0x83C1C5119B73BFA7ULL, 0x5BBA60CB0930EF88ULL, 0xB927E4E385D9A25CULL
        },
        {
            0x60FC970D2A32E01FULL, 0x1F22CA70414E198BULL, 0x75AF04043D201C09ULL, 0x2C5914CC53388522ULL, 
            0x16C74036B89B6E63ULL, 0x5BA9EF8C89996539ULL, 0xC557822E7191EDC2ULL, 0x8EC39537F1778730ULL, 
            0x4E6163CDB335610CULL, 0x299B870063001B34ULL, 0xFD5815EDCBC842D2ULL, 0xF32B9172CE55A082ULL, 
            0xA362919596ED9077ULL, 0x0FEC6E260551A80EULL, 0xB2815CA0EE2E3598ULL, 0x99A71EDCFE3B59C3ULL, 
            0xE81F75BD0AFC22CDULL, 0x76E496AC7C727F4AULL, 0xA58251EC0D4EC15FULL, 0x8CE00D23B43FBDE5ULL, 
            0x7DD806B1E2C35771ULL, 0xD423CFEDA9625EC0ULL, 0x68819BDAE04B3E20ULL, 0x52019FAEB961DA6DULL, 
            0x4588BC28C0E0D6A7ULL, 0xF0348ECF948BAEA3ULL, 0xD6C0B4DF18954169ULL, 0xEA063AF9E3504247ULL, 
            0xE1DDEA98B8339E7AULL, 0xF232D504756F0230ULL, 0xC7592743A1BFA18DULL, 0x5E891831DD93ACADULL
        },
        {
            0x660E5AF17D2578FDULL, 0x3E1B2091381A2B4CULL, 0xF396FC6561260235ULL, 0x0CDAB8C02D0EFD5BULL, 
            0xE5A7B48962DB31D8ULL, 0xDC818F9E46E4E479ULL, 0x6452AA267FA358BAULL, 0xC65CD4C06EA81C01ULL, 
            0x91281520DC5BABD2ULL, 0xE1DBD0C0F648DBADULL, 0x77E019C9BEC3F001ULL, 0x2E0918B2E287954AULL, 
            0x7F3ED68DAE4E6298ULL, 0x972176114DF4FB37ULL, 0xF3E526D052380B12ULL, 0x3663B10E32D4EB6FULL, 
            0x469412C3BD1ADB34ULL, 0x93E8A8993C32F98BULL, 0x977E1991AADC4ADBULL, 0x798876C0668BCA1BULL, 
            0xC4FB43E3106D15BEULL, 0x2D9EEF693349E460ULL, 0xBA2A13EA9CC3D4CFULL, 0x55EFD9D5AE032CB6ULL, 
            0xCC09C14D68A067BEULL, 0x0883C75308D18B08ULL, 0xD54AA69618B89849ULL, 0xD68378B3DC784B64ULL, 
            0xE4D5484B43CAA7B5ULL, 0x5751EE108BEC729DULL, 0x09DA7C969BB5799BULL, 0xE5FEFC1E4962FA20ULL
        },
        {
            0x279CDD5CF5B314B9ULL, 0xF4F98FE7FEA71C12ULL, 0xD9313819F437F1E4ULL, 0x5631AA0C474B7846ULL, 
            0x53335C479EDA86A1ULL, 0x9E3092D409BE40C8ULL, 0xA4089597589CAC21ULL, 0xF3ED1A2EB1A380F6ULL, 
            0x8F628149E3F33F92ULL, 0x2A14E9B284F7B311ULL, 0x184855853F31DF37ULL, 0x8F7FE6FD0819194AULL, 
            0x7119AF3EE353BB83ULL, 0xE0FEBD8CCA492C89ULL, 0x24F60DB72C63BE54ULL, 0xD424D88CB2834018ULL, 
            0x05C787513339A152ULL, 0x62F100BF3BAD5E72ULL, 0x2E7A660B726CEA7AULL, 0xA403BE7151ADB7DEULL, 
            0xBD4DF9EDD6E13D48ULL, 0x57036719AC593EF2ULL, 0x1FB340A4A5ABA384ULL, 0x0688850B13880AF7ULL, 
            0x78B8EC3B789EE1FAULL, 0xF1973740FA6A932AULL, 0xC779B7F2D55E2E6EULL, 0x6E0E340BE47A836FULL, 
            0x0A11F1788E8865B2ULL, 0x6FBE98F8D416F3E2ULL, 0xD6281BAD9FA49CC9ULL, 0xC58162A862EDFE1FULL
        }
    },
    {
        {
            0xF58EB0955798B4F5ULL, 0x449F9E3DA9217920ULL, 0x8C0591EA04A91298ULL, 0xCDB7E0FC7D9B88D5ULL, 
            0x0FEC866261C1D0B1ULL, 0xE4A1D3814865013AULL, 0x9849CE530AF4CDA0ULL, 0x1D1DBD331DFC2828ULL, 
            0x693EC719C26F6017ULL, 0x63B5CA36129A40CDULL, 0x7B69F3A6F4A9504DULL, 0x915B6FEB0F683D26ULL, 
            0x438FBE953E9E9026ULL, 0x976583151066C5EBULL, 0x2B7368F87E3A4E24ULL, 0xBBFF030FC0D6EF2CULL, 
            0xB9ED697DA7CA40C4ULL, 0xC15BC11B6893FEC3ULL, 0xBBB4451F9FFB14B8ULL, 0xE08F8BB5B8E22C2BULL, 
            0xE0D39D19B80DC9DAULL, 0x07A4828912F31AE3ULL, 0x4D377CBC2E2EC2BCULL, 0x94E8C579196F5422ULL, 
            0xBDF098BBD7EC5E61ULL, 0x4A7FA7AF4982B136ULL, 0xAB16DAD5800770ECULL, 0x67205EAFBA882CA9ULL, 
            0x529BEBE54BD526D7ULL, 0xCADBB2F1DB6A2D31ULL, 0x9375F80E203E313AULL, 0xC87673C2A402E733ULL
        },
        {
            0x9AD887A26FE094D8ULL, 0x02C615A8F346C80EULL, 0xCA9C0763034D0D7AULL, 0x7BB2B28B0081F373ULL, 
            0x0A3D22460C82C6CAULL, 0x219BE47E6B1CD1E4ULL, 0x8F6C1C5042A58937ULL, 0x6D02710D13E1275BULL, 
            0xDA0EB4A3487C9D1EULL, 0xC0C926C788F549A3ULL, 0x5781BF4AEC73353CULL, 0x3E41168AD05C5D78ULL, 
            0xCC5F0E64F52EBE14ULL, 0x57E6777B4A0A0EFFULL, 0xAEE6DBAFB773F4C1ULL, 0xE0A27C234FC05AA7ULL, 
            0x9898425F44D206DFULL, 0x6D5A6927BFE9F881ULL, 0x9F03D9E5FDE6B886ULL, 0x2314741436E1B1F8ULL, 
            0x0795C2C3900EAA80ULL, 0xEE22C2BD4C2FC182ULL, 0xF6EF7A6AB167E1FDULL, 0xB13E69C632FC2392ULL, 
            0x1C8F4932C595B9C8ULL, 0x515813F0842774DAULL, 0xA4E0723DB96C1856ULL, 0xD5D463520E0EFB7FULL, 
            0x1A0E97176CF15471ULL, 0x3288C990D86157BCULL, 0xD956ACD91C7659DFULL, 0xA87060F6865672F9ULL
        },
        {
            0x215A631E18A71264ULL, 0x2256047DE7A0AA33ULL, 0x624D559662433FFFULL, 0xA2861A686D31D986ULL, 
            0x6CBE9BA269A889FCULL, 0xF5D2BAEBAC228771ULL, 0x1FE1AE9D06814890ULL, 0xAD50F771CA8F1BC1ULL, 
            0x87DA187247FC17A3ULL, 0x2554245ADA21B0DEULL, 0x8E686B033FBC18B8ULL, 0xA79E7D84F11EF6B1ULL, 
            0x73946D97D2415CEEULL, 0x5C1062D000BA32E0ULL, 0x514DD6E6ECAD886CULL, 0x5F071E2D94EAE00DULL, 
            0x47E264A6124A0C47ULL, 0x6275429155EF1B88ULL, 0x25D4CE772F5236E9ULL, 0x697F656171A52ECBULL, 
            0x2AB69070132CB0C4ULL, 0xE2366A03D74F4143ULL, 0xE5CC0982522603CDULL, 0x0E0FA6D7A0D68593ULL, 
            0xAB2FC555420B0F3DULL, 0x693B8102ABDC7CD4ULL, 0xD4E5470B17F4E007ULL, 0xDC753615B6DFBFBFULL, 
            0x9390318B4F538E42ULL, 0xA52630DEF722E6EBULL, 0x9413E73A8753D208ULL, 0xBE3E68160B2395C0ULL
        },
        {
            0x4F1D48EB3A7D0BE9ULL, 0x356384AF704AB4BFULL, 0xA5B020731A5245FAULL, 0x07F28BBCE3A429C2ULL, 
            0x8B81B4545D62742FULL, 0x49298D522F3A71EAULL, 0x863B138D03D27E77ULL, 0xE75B5609214589F7ULL, 
            0xABD88199768F1B96ULL, 0x057828E71B2AA398ULL, 0x76FCEB761C869CDDULL, 0xB53B66A09D19EEEEULL, 
            0xBF35944E22D3E8A7ULL, 0x227EE6542F916578ULL, 0x3416CB233A34601DULL, 0x0C7E0BE954AD6B2DULL, 
            0x250AFE6C532B8CB8ULL, 0x6EF66FC947CC113CULL, 0x9D2C1ADE06F49239ULL, 0x41D1EB9ECD70D937ULL, 
            0x97AECD05770CF4F0ULL, 0xFD63EA1472D12148ULL, 0x27483852B5FC1D10ULL, 0x8C8379BBD9C84653ULL, 
            0x52907090651E382FULL, 0xBFDDC93749E7EAEDULL, 0x5566FB2131E4EF6BULL, 0xC7847144D50443C4ULL, 
            0x3814AAD07939C7EAULL, 0x36724CFDEFDC99C7ULL, 0xA7D307526BFB4C8FULL, 0xA257DFC6B6A7DD73ULL
        },
        {
            0x435D75F364FB344AULL, 0xCA1C52B511A273D7ULL, 0xBBFA14899761D2F6ULL, 0xCE9DC1E8269E2CDBULL, 
            0x5768A3E777C0F136ULL, 0x8A127BB1A72D1572ULL, 0xAAD268228EB325CBULL, 0xC3D2FE930A0B179FULL, 
            0xCC1D58ED224625AFULL, 0x0192893308020649ULL, 0x5A9AB80A1327C3A9ULL, 0x5763810893CD2BF5ULL, 
            0xB89670B503E7276CULL, 0x9B41E8E87EC22A97ULL, 0xF443DC86CED8DC73ULL, 0xCCBE5D2C4CA2DB8BULL, 
            0xEA6DF33899E5FC97ULL, 0x58F2A484246DBE34ULL, 0x872B9E6415241BDAULL, 0x0B11B7B889F01B69ULL, 
            0xD4FC4066C14BC66AULL, 0x559CA15603A1341DULL, 0xAD1FF90128D8E7DCULL, 0xB24824E301BA87ADULL, 
            0x7137AFC6D0EF9BEBULL, 0xEAD2A2BAF7081CF2ULL, 0xD4347019CF742863ULL, 0x51AD18BACAB4AF7DULL, 
            0x2E929749833D87CAULL, 0x18746DC2B9A71DE0ULL, 0xF3CE979DE8DB02BAULL, 0x6F174CA9ECC69BFDULL
        },
        {
            0x86669A0685FC4CA4ULL, 0x8B83A26B7E997922ULL, 0xAD04946A40035D28ULL, 0x45A50F2C3424FCF8ULL, 
            0x958579475232EEA3ULL, 0x68F5F9EDDC393859ULL, 0xA21F1EEB51DE49D8ULL, 0x7C5BABEE862150D6ULL, 
            0x8D3FFA43695C80B7ULL, 0x58B4184E8DD01432ULL, 0xF63F3D9720AEE880ULL, 0x1050C9A5463CA521ULL, 
            0x59B14280AEEBF927ULL, 0x5382440DCA4813C8ULL, 0x4A851E7B13B9BEEAULL, 0xDDB71D5B8F24D07DULL, 
            0x340A76796D67EB29ULL, 0x7D2423B4ABADEB0BULL, 0x20B6B47DE795B8FAULL, 0xB8E14F892FB0C404ULL, 
            0x99DD1A61F16696DDULL, 0x70ED5AAE538EEE5AULL, 0xF5DB5CB1D6E48761ULL, 0xB1BA91AF539C61D7ULL, 
            0x1FE27AA38EF5E6A8ULL, 0x44AD46D64F4836F1ULL, 0x2A28CAF281E61C6CULL, 0x5F0680AAE869495CULL, 
            0xDA9C9E59A9403AEEULL, 0xA0803EB6E2F9309FULL, 0x53DAA8DE26DF595DULL, 0x70AE346A3AAC30E3ULL
        }
    },
    {
        {
            0xD43E400F86DFD36CULL, 0xFF340C9C775785C6ULL, 0xE02C34583FF6B209ULL, 0x37E4CF1237CF13E6ULL, 
            0xC8508F2B766F1155ULL, 0x99756CC0DBB56A09ULL, 0xBEBB546A59A6A10BULL, 0xB9464B70743C3F67ULL, 
            0x320722670E5C6EC2ULL, 0x7F839E3550277537ULL, 0x8C8CC9EFDD9C566AULL, 0xF13D4589D08E19ADULL, 
            0x864C468DFA3AE0A3ULL, 0x6E588415FE37493AULL, 0x8AFBA64153FEEC86ULL, 0x16F0E37C9B54163BULL, 
            0xD7D2FD4A62DF2C29ULL, 0x08866007B55EB8F1ULL, 0x6832BDC2FB17DC23ULL, 0x8CB0E7D390E20EBFULL, 
            0x7456F2B58F2488D0ULL, 0xE550C90CBC1DD3D3ULL, 0xD1E804C54BA22C69ULL, 0xBA605263DCA37F4AULL, 
            0x2BEC8431E051120BULL, 0xFA073991142B6B82ULL, 0x0713889CD37FA4CAULL, 0x168D20BAD6784AD9ULL, 
            0xE7B6314D30738BDCULL, 0x87D40EBC52FBE82DULL, 0xF0EF5081167F4EC1ULL, 0x1AF6F67716F6B471ULL
        },
        {
            0xFE94774B627A5E4AULL, 0x46B638157D14C12CULL, 0xE767646F89C1BCEAULL, 0x3B5E6562A54F6B4EULL, 
            0xA0BC4590F02A8D4EULL, 0x58675D4D1C59FF76ULL, 0xE2EE8ABAAA31CDF1ULL, 0x82346F58C105278AULL, 
            0xC28AC924F3954FBEULL, 0x0D4D61EDD82FD080ULL, 0xE6A7030020BB74BAULL, 0xEC3AF26D0D228B2EULL, 
            0xE7E535EFC862712CULL, 0x1026A45383735147ULL, 0x0D6EA4E9387027EBULL, 0x5E21411A38AF647AULL, 
            0x40D3B464097E4AB4ULL, 0xD82E1B9CFADBB1B8ULL, 0xEA241BBD697D20FFULL, 0x3334705122390BE7ULL, 
            0x59F9696923E4FD8AULL, 0x866AEB3346200B60ULL, 0xE048496C49070540ULL, 0x4871B60C51AE2E68ULL, 
            0x277CC33B73F1435CULL, 0x77C4213F8138C137ULL, 0x80B2DC36414099E6ULL, 0x419C44136179D477ULL, 
            0x989706F53FD6A52BULL, 0x4E48B8576101819EULL, 0x42A0B9A5A60298EFULL, 0x7E1AE05870DC7032ULL
        },
        {
            0xA2C95EE475D07B36ULL, 0x8E415483404EB1FEULL, 0x5C86CDA6D9AE94F5ULL, 0xDF29ED56CD23ADA4ULL, 
            0xAD9876EBFD7C88F8ULL, 0x3E5677F038B35C8BULL, 0x1EC1AC846E13687EULL, 0xF5C87FA1E0740482ULL, 
            0x4C585684D8890931ULL, 0x0F5887E5EED33D60ULL, 0xD10A943EF6673051ULL, 0x90715CE6526EC6BDULL, 
            0x37496AFDC295BD81ULL, 0x8DC15B21C62CAB4EULL, 0x907484CEA3CBED0EULL, 0x34300AD3DF15A368ULL, 
            0x1638FC160C4F9219ULL, 0x1343FF41D52079E4ULL, 0x8555912BA20091A2ULL, 0x5F04AFAA8C6049CCULL, 
            0xDC00C8C6533CE236ULL, 0x512CEF5C920CFE1FULL, 0x80B5FC6128FAB7F7ULL, 0x4A5C97ADBCFBFE8DULL, 
            0x42AEA969E893B948ULL, 0x8D92D61B26B8FC12ULL, 0x7996B7BA6923E64DULL, 0x1319BD2055E1B543ULL, 
            0x227787A166F61FECULL, 0xAA1984244F063D23ULL, 0x31E77B52FB424214ULL, 0x40E22B55D3055D48ULL
        },
        {
            0x02B7A6534A4687CEULL, 0x12A9576E28F671ADULL, 0x6AA9D5119CE84728ULL, 0xEDF5EA139469C1C8ULL, 
            0xD0C55A9ECD444269ULL, 0xB16D69867678CD08ULL, 0x0345AED003162C5DULL, 0xF8BE28BC8AC4BCBDULL, 
            0x099711D9EA07A118ULL, 0x73CA2399C824BF79ULL, 0x282F0461498FD04EULL, 0xB2CABEEA751C3914ULL, 
            0xE9B0996DB163C7CAULL, 0x611510CCB00B6052ULL, 0x365A30F0B0C9804EULL, 0xE2AE4F532DC5523BULL, 
            0xC57C9A6AE11ED8A6ULL, 0x39F115468413E707ULL, 0x6609A4C60B76E7B4ULL, 0xE40553B0548359F7ULL, 
            0x476B07C59EED8DF3ULL, 0xE204D99ACF1CAB55ULL, 0x34EFF14388F9C978ULL, 0x9DA4069D7CACAD8CULL, 
            0xD900DC4EA7BF89D1ULL, 0xD4CE66A0DBE5A3EBULL, 0x141A9858B391B606ULL, 0x1B3320B9EDCDA3EAULL, 
            0x1D2AB719E392AA18ULL, 0xB0AAB1EF541BF168ULL, 0xBB98ADF515E3D6B1ULL, 0x260CBDFDDE7A9E64ULL
        },
        {
            0x6F9FC70750940430ULL, 0xC567C8C064206585ULL, 0x57E73B14FA32DA36ULL, 0x6029349B554447EBULL, 
            0xEB5967B7CD915455ULL, 0xB65FE8D5939E312EULL, 0x92411B44D397746DULL, 0xD8BB17680C4E7B86ULL, 
            0xED209EA31A075C49ULL, 0x63B83C9707455BC0ULL, 0x13F190F83B12DA92ULL, 0x542982BAB7875416ULL, 
            0xF2268DE4F00E2CD1ULL, 0x73588350EE56E791ULL, 0xCB9D0323F6AB882CULL, 0xED22B29FEC6A8100ULL, 
            0x93354971E785E87DULL, 0xEA8638DAA40C9390ULL, 0xCBA3100F9F9C3FB6ULL, 0x266136C0BA90B580ULL, 
            0x6FD01FE0E935255BULL, 0xE4D68124F7D599C4ULL, 0x26DDCE60493AF082ULL, 0xA841BCAEB8C38D89ULL, 
            0x816C26DA12CFB0A7ULL, 0x2DD407983B38B24FULL, 0xD9C603E7F4D033B8ULL, 0x655714C55DB872FAULL, 
            0x23C2296D284F77D4ULL, 0x6C5F64092DDC6C04ULL, 0x9DBE67AEB3B70E8CULL, 0x09413D30E6D07624ULL
        },
        {
            0x179A343A182BC7EAULL, 0x57A1DF6E1C681FCFULL, 0xBA10871E3B668564ULL, 0xCF0E803A30FA0B54ULL, 
            0xEEAAD779DB6F7213ULL, 0x8E2D01ADA2CA0F47ULL, 0xAA1384685AD2BB9BULL, 0x9A19794ACDBB31CFULL, 
            0x2B1F328518B9A779ULL, 0xECC6A3DCB7612F2AULL, 0xC10A731CCE5E05FBULL, 0xDDDCB7C7AA835FF4ULL, 
            0x12D29B32A7A6A515ULL, 0x91EEBC6BD43C3D94ULL, 0xE735BE615AF60D56ULL, 0x278D41FC64059182ULL, 
            0xDC4699BD66695354ULL, 0x8C504AD9399894DBULL, 0xCC4A4B28EB482C46ULL, 0x245C447E1E5BC734ULL, 
            0x6C20E55065FD77F4ULL, 0x306B0FD94D96AD5AULL, 0xE4A21128726A913EULL, 0xE48A4F7FEA371086ULL, 
            0x32FECD2104C8B8C1ULL, 0xCED8A49F9C2BB9F3ULL, 0x000F7458025685EEULL, 0x981C9469CB5C2D85ULL, 
            0x25116FC4BE757616ULL, 0x8DDD1F65F754BE22ULL, 0x98D7ACBF84085B37ULL, 0xCDEC446FB6DE4373ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseCConstants = {
    0x0E25D340CFC9135CULL,
    0xC70EE8D27D22498EULL,
    0x5DD66AF0A9424D14ULL,
    0x0E25D340CFC9135CULL,
    0xC70EE8D27D22498EULL,
    0x5DD66AF0A9424D14ULL,
    0x85D0F568FCA039BCULL,
    0x6D10B41B4F1AD7D7ULL,
    0x87,
    0x86,
    0x3F,
    0x10,
    0x34,
    0x60,
    0x71,
    0x1C
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseDSalts = {
    {
        {
            0xF89C62C74161C6E0ULL, 0xCA26F02E4E9FEDADULL, 0x7029264AA051CCD6ULL, 0x92B821D3EBF90AC2ULL, 
            0x063AC9974897C0D3ULL, 0x8C0B6709BF544A9CULL, 0xD07A7C2958B53BFDULL, 0x93AB4C3F5374CF6AULL, 
            0xACE60291185A5D33ULL, 0x8111B0DB681673D8ULL, 0x9881DFF482F20954ULL, 0x79C8E1AE05F3B361ULL, 
            0x09BC7647F4886C68ULL, 0xFE12B26186241D1BULL, 0x8CB99643EDFD682AULL, 0xE7578650EEA7C00FULL, 
            0x8DEF914DD752E7EBULL, 0xD51729229265345DULL, 0xA4994F046BC81E03ULL, 0xFB34FCDBBE4B29B6ULL, 
            0x5046C52CFF1A6FA3ULL, 0x8B9B8B6224A79C3CULL, 0x77E04463AE009A44ULL, 0x106C03C7862F29FFULL, 
            0xC0EFF3495EE11FC2ULL, 0xA469D6AAF20CC44BULL, 0x23F62C974DF2C98DULL, 0xA9A340624634BE9DULL, 
            0x9DCE70F78BDAEEADULL, 0x374D5FF298B66D58ULL, 0x40018E6BD9C7E613ULL, 0x16DEB1F2D81639C5ULL
        },
        {
            0x5A12CDB34045F31BULL, 0xA6D282C2A5711FB2ULL, 0x60A0FE9F14E81174ULL, 0x83E05BB97E12EC10ULL, 
            0x518DBF17DE1FC88CULL, 0xDBEA13EB1368B5ADULL, 0x50B09E67481B5FEBULL, 0x20F6C831ABD054E5ULL, 
            0x98459489ACDE5BC1ULL, 0xAE922081004BE9C2ULL, 0xCA9A20BAB53996A8ULL, 0xC3DDA7DF63452A92ULL, 
            0xDD227E5CE375E45CULL, 0xC69536A6D85BE476ULL, 0xF7DA77B05E26DE45ULL, 0x2C00D57BC7169B6DULL, 
            0xC3B46B44F092D24CULL, 0x6EC3B51BEA188D8DULL, 0xC99AEBA512432E1DULL, 0x8BF0E15AD9E2B7B1ULL, 
            0xA6517E4EB07FA497ULL, 0xF392B0B868A2098DULL, 0x21DF062BFBF79395ULL, 0x8B4599BC5D77413EULL, 
            0x70D8022626729B60ULL, 0x8257C8793BC8419DULL, 0x9437996589114B42ULL, 0x6C033D1C91976053ULL, 
            0x614590F1189208E9ULL, 0xD453747713E49E5CULL, 0x4F40A27E5A9CFF7FULL, 0xC8A92D57CF6F5C8FULL
        },
        {
            0xD24D32011A91461EULL, 0xAE17F6DC9B944CACULL, 0xD412C29915E4A983ULL, 0xFDA4369CE59B51A8ULL, 
            0x27275962E17167DBULL, 0xE63A5359D09575FFULL, 0x53055DEA18198964ULL, 0x46BF288EA74B34AEULL, 
            0x8A5022C03DF76D28ULL, 0x6D3F03B962104A57ULL, 0x71E4906C628759FAULL, 0x238294F62E3DD248ULL, 
            0x88268FC5B1F0B873ULL, 0x7B973115E8C23784ULL, 0x7DEEDE741FA53697ULL, 0xCA43AA990248E9BAULL, 
            0xD0F99FBB2279ECDBULL, 0x2E3C7E6FA79D15F1ULL, 0xA60E5317253F4295ULL, 0xCB2E16F6B3A756C7ULL, 
            0xE0156F9C3A498780ULL, 0xB96EBEE036A89C73ULL, 0x90E765CD76EBD14AULL, 0x8CD0EFAE44059F52ULL, 
            0xAF363AAFF789A019ULL, 0xD5C48A1A17206034ULL, 0x4AE0A7CE5FEAE054ULL, 0x42240CA9FD8B4E74ULL, 
            0x0FF91286D9A2E9CFULL, 0xB0834D9466B4DE89ULL, 0xD5DB3130C3DB9C31ULL, 0x27BCC44DF8574973ULL
        },
        {
            0xBE5DE30953F80C95ULL, 0xD81BDB110CF734F6ULL, 0x119D9F901EB663A4ULL, 0x4A5B2B1884C158B0ULL, 
            0xEB79960B0211FF66ULL, 0x4FC4A30FC97440D2ULL, 0x2E40C1F384F15EB1ULL, 0xD4CFF911AF3624C5ULL, 
            0xD72B8ED0B9711A15ULL, 0x196040AE802B5C5DULL, 0x2868FC8BE127D806ULL, 0x7995AFCDD0D91F37ULL, 
            0x6423769A14CFF1E8ULL, 0x90C865E4E271BEDEULL, 0x756F8732B177A724ULL, 0x1DCD1F9A2A6A7E08ULL, 
            0x8F74893A99A34EEAULL, 0x14785B954DD8A715ULL, 0x4DDC83C3AA1D7A86ULL, 0x7C2EDF2041E74465ULL, 
            0x307269A75822424DULL, 0xBDE7FCFAB364E55AULL, 0x920C111546A549EAULL, 0xBAC9E86E1CCB559EULL, 
            0x6B23F79D955FDFB0ULL, 0xB93E41434431384BULL, 0x6C2C41BDF86271BBULL, 0xBEFC5E39E187B723ULL, 
            0x3A6A75B6970C3E55ULL, 0xD13021A84DF5A355ULL, 0x2D157FEF31DEE694ULL, 0x82B8123FACFEF377ULL
        },
        {
            0x5E6DF919A920917FULL, 0x5FCE073474C312CEULL, 0x463C6861433098AFULL, 0x1A32E0F12539C406ULL, 
            0xCA4269C88F2E5011ULL, 0x63EA098607322AD0ULL, 0x4C0A419159EB5A5CULL, 0xEA01360D5CA4C61CULL, 
            0x8122994950C386ECULL, 0xFC3FBBAB75755891ULL, 0x0651F0DED84BEAF4ULL, 0x9E71719A8DD9891AULL, 
            0x4816573E6CE586C8ULL, 0xEB4D46CDD4D0ECDBULL, 0x1D1E68071EDF5F7BULL, 0x695FE6065DB0F7A6ULL, 
            0xB96EDC566D4B112FULL, 0xED8E859B6866A314ULL, 0x4CEAC8FA92CDB76AULL, 0xC981713ED03EA041ULL, 
            0x0DADEE843490EA32ULL, 0xEFEE740F8008B7EBULL, 0x26EFD4C3CE4AAC1FULL, 0xAE8CA746432881F6ULL, 
            0xCC8685000CB31865ULL, 0x423D3210F59CC191ULL, 0xA0FC9CF52BA39F35ULL, 0xCA7EBDBE88941EF3ULL, 
            0x06FF58BA30B1E843ULL, 0xCD1899EF063E0FADULL, 0x81D3B81EC5FE3FFEULL, 0xCA16A309307160D7ULL
        },
        {
            0xACC4E13878C84791ULL, 0xC2C6B29DC67299BAULL, 0xBFE9A585168AE45EULL, 0x98A2766B47CEA7A3ULL, 
            0x1E9BB33F10BAC7ABULL, 0x8992D24A82D987BAULL, 0x4DF42B4367FE1408ULL, 0x893D2D6584275AE0ULL, 
            0xB10619B956372F0FULL, 0x6DCC67CC62D69692ULL, 0x86C197096D337ABDULL, 0x0FC7FD144D35F156ULL, 
            0x3C45BD2A61ECBE00ULL, 0xBB9D6CCBCA364EF9ULL, 0xCF7E89F6E742D848ULL, 0xC03BB41119841D80ULL, 
            0x9ABD8E03C1A566A9ULL, 0x13422594884B9746ULL, 0xA916E2B13A29EBCCULL, 0x8C3C3E3F2B5B6E66ULL, 
            0xDD1CD6BFFAD27625ULL, 0xE8B26A7D9FC533B3ULL, 0x109E19FFB32E5F7EULL, 0xC10D344787C32AB0ULL, 
            0xC730F58B526C2955ULL, 0x49130266DE0603DBULL, 0xFCF6FC1E551F4D6DULL, 0xBCC33CB41CC65179ULL, 
            0xCBE8C566941291B4ULL, 0x99A9DF86D90EE0D1ULL, 0xCF7C9001A0D5FE27ULL, 0x9BF048566245077DULL
        }
    },
    {
        {
            0x0F8D8170831B37A7ULL, 0x9B05FA5995B1D9EDULL, 0x359494642908E90DULL, 0x5B07C29C0023DEC8ULL, 
            0x44560518240F1DD8ULL, 0x015FB77492EA9F94ULL, 0xA0300B72288A0EB0ULL, 0xE2F82E3D08AF4ABAULL, 
            0x0F8F35ADA95E9B33ULL, 0x4DC471784DFFDE6DULL, 0xC625D332D78A528EULL, 0xE39AA735D95A9825ULL, 
            0x01527885555CE910ULL, 0xC6F283DAE1A8AFDCULL, 0xA855BD7CC90A5B87ULL, 0xA5042FADF4F47FECULL, 
            0xEA307801A3314AEEULL, 0x06D9172C54CDCCA6ULL, 0x4EE743005F5B8B73ULL, 0x0C57B1C3E6B49D20ULL, 
            0xC4E82F07CF8F2D0FULL, 0x11D6BFA321F407E2ULL, 0x491FB01ED6E11ADFULL, 0xDCB9596B9231586BULL, 
            0x4D312EFA67DCCD04ULL, 0xC9C89202D6423125ULL, 0xB35B14BF099EFBAFULL, 0x6ACED0DDCE33BF9CULL, 
            0x3C518522C8E0C280ULL, 0x4659D438E44BFC66ULL, 0xAB0F6F46D663BEFCULL, 0xCB2F004D26A48B83ULL
        },
        {
            0xBC715E5FAE6105C9ULL, 0x63CDD0B12CC32A91ULL, 0xB8B96F68B34DBB3CULL, 0x6D03452BACEA9A38ULL, 
            0x781BDE2461A10111ULL, 0x89DF626A2A7EE282ULL, 0x83ACE9FFCF77F846ULL, 0xE738F9FD31B9BAB9ULL, 
            0x8BB78AAC784FFD14ULL, 0x46921F590501ACC2ULL, 0xF2864055DD847A1BULL, 0xCFD3906105733CBAULL, 
            0xDBAA096634719F6AULL, 0x5DA1C60E91E1E5C9ULL, 0xB901369364015DB3ULL, 0x89B0EFED63578584ULL, 
            0x75453F8BD853CF87ULL, 0x0CD314843DDA830DULL, 0xC3B25E2C4747E3ADULL, 0xBEACB72C6527BBE4ULL, 
            0x14D12C211502CAA9ULL, 0xEF599007E86B7CF1ULL, 0xA639758C1BB5A797ULL, 0xC1B2E7C81A2A76E3ULL, 
            0x4464A5551EF6B59AULL, 0x34F78381E6B4E410ULL, 0x10A304E157721C65ULL, 0x239D07337D3B6B43ULL, 
            0x3E2DC5A3E601BB3CULL, 0x8D93B721DA5DCB3FULL, 0x647B51D034EBC3ACULL, 0x048747ADFEE8A2AEULL
        },
        {
            0x1080533DC86979C3ULL, 0x85C34DAFED479BBFULL, 0x3BA8DC4FFE5C19D0ULL, 0xD9452C476024936FULL, 
            0xFA19F6C5B09AA9CEULL, 0x82656870F2278AEFULL, 0xDEFFD3D6DB869245ULL, 0xB447C75509383594ULL, 
            0xF34696CC81BCDA5DULL, 0x17F06275C4E837C8ULL, 0x12F0F1E718C93857ULL, 0xCA0813D8B3D32BA9ULL, 
            0x546D773761E3FF18ULL, 0x32487871E15E79D8ULL, 0x2D015B9873C14CF7ULL, 0x7C320F097DD0C609ULL, 
            0x2296FB4F194883D9ULL, 0xC2C7D6A092A56632ULL, 0xD966D5FE41F74253ULL, 0xCFF020D73FA720B2ULL, 
            0x34EDD5AF76B24212ULL, 0xD995C4ED9F8CD46FULL, 0x2D055F7697CE092FULL, 0x1CA7D230B9F7039DULL, 
            0x10B4F5A0CD2A65B7ULL, 0xFA0A54052BF0F3FCULL, 0x21FC0C6456702195ULL, 0xAF3DF7A6A2E4326CULL, 
            0x5EB0FD005CE8F8ABULL, 0x1CA607BA71643F6BULL, 0x114D678FBD8EE80DULL, 0x641988A5D59F3A35ULL
        },
        {
            0xAFDF16C5AEBF6B5EULL, 0x0D2CB2A3D2B8CAC4ULL, 0xA1ADF28351BD6590ULL, 0x14B7AB75B24E95E5ULL, 
            0xD70E68EF169C451CULL, 0x14216156D5E44311ULL, 0xA069CF4B751896D6ULL, 0x7A675FD259BE7E43ULL, 
            0x765B338E9970A6BBULL, 0x1DB36EE323302C93ULL, 0xFD1A94877E6B920BULL, 0x5D1708CA28925583ULL, 
            0xC45C04DE47DA856BULL, 0x3AE17385C028DAB9ULL, 0xF6781F84E631143AULL, 0xB49B2FF6DF676437ULL, 
            0xE227E63084E594DBULL, 0x3FFB6D0EA765E442ULL, 0xA24CFE8C3ADF27EFULL, 0xA530948C2D48E685ULL, 
            0x182CE48456843CA2ULL, 0xD39D63EDB7F93A8BULL, 0xF68581F86D94EC52ULL, 0x842B4B9F0F8334FCULL, 
            0xB416896A6C234330ULL, 0xCAF495F7CC50BE55ULL, 0x78BEA679EA00F0DDULL, 0x85D8915765701CF8ULL, 
            0x38A286A9A5A9A3C9ULL, 0x521AA36C4AB28F24ULL, 0xCC1781370E5822B4ULL, 0xC5AD3C6F2DEA1AC1ULL
        },
        {
            0xFD598C465F7641C0ULL, 0x7B6351ABE5DC493AULL, 0x22674726C42E010DULL, 0x2FC427DBEFFAF578ULL, 
            0x8C98B43F4A289359ULL, 0x11E3DD2AAB1183B2ULL, 0x5EEC718DA92F6FABULL, 0x1BD92E0200D4839DULL, 
            0xB75C88F1A81AED6CULL, 0x8C78F8CF6A50CF90ULL, 0x0E7E27EE94D1C3F0ULL, 0xA3DC6ED8A1FA5F4DULL, 
            0xADCEDEEBA6111030ULL, 0x93A8046F63546E8EULL, 0xFCB8466188DB9DFFULL, 0xC27683B3ED6D906DULL, 
            0x14F6391233BB03D2ULL, 0x23C0E76348508A94ULL, 0xD592AC13EE4CA5CAULL, 0xF25DD1785D828BFFULL, 
            0x11F6E5C67420D173ULL, 0xA66A561D65E63222ULL, 0x24A4ABF3BE7F8397ULL, 0xCD9B227654A6E33CULL, 
            0xEC67F54A7C0DDDCFULL, 0x4D8B17307BAFFB71ULL, 0x13A6BE68FAA29063ULL, 0xE2EAC5408D04CA6AULL, 
            0x0D49D4484D960892ULL, 0x3BB66BD521FBAFAFULL, 0x0BB14750C7F99E21ULL, 0x8A7F39DE3B24604AULL
        },
        {
            0xA4DD521E5EFC690BULL, 0x03F4180F48B09AE5ULL, 0x496F4C66B7E83EFAULL, 0xE41EB017270C5AB7ULL, 
            0x9760C47EB053E33EULL, 0x995F012A82C32618ULL, 0x854820DB971787A0ULL, 0x0DB5103B840B75F4ULL, 
            0x48E23470468A7057ULL, 0x3856B056A7DA3357ULL, 0xAE823280467903CFULL, 0x9B9E22C0B889032AULL, 
            0x4D8B42109CBBA011ULL, 0xC9BABB00C178C6D6ULL, 0xFF3F7CABB9D30E2BULL, 0x402A3C3DABE82057ULL, 
            0xE4A1913D6074BD22ULL, 0xCDBC62920FD7F4EBULL, 0x562D369B1F20D9F1ULL, 0x78E8A099997824BDULL, 
            0xE404C377ABD023C2ULL, 0x8E72BAD78C768DF9ULL, 0x79EF0824D7B0005CULL, 0x66EE71A068953FBCULL, 
            0x224BBDE2C5F296EBULL, 0x096292DCB6E08D89ULL, 0x3A40B821FF6D2906ULL, 0x532E443A68FC4486ULL, 
            0xFB604AD0957D01BAULL, 0x6705BCB8B2177F7DULL, 0x4163E08BE86BB515ULL, 0x22600C095739D5E2ULL
        }
    },
    {
        {
            0x4C94E46EA8D33B17ULL, 0x387E77779C92B334ULL, 0x96C45D67309669C9ULL, 0xA6A8424EC8C1FF7FULL, 
            0x6631CA95009107A7ULL, 0x0DC614B90F97214BULL, 0xD36B36B923CC4C89ULL, 0x12DD5537DB011486ULL, 
            0x116925C709A8ED40ULL, 0x33A41B238B5D2C56ULL, 0x5F0FCD917C647740ULL, 0x1CDB847AD00C0153ULL, 
            0xBD0278D45674FB08ULL, 0x5EE0A7DEBAF1698EULL, 0x85AFE51095A8D8B3ULL, 0x46E83BBBAABC67A0ULL, 
            0x51E227E8F2543E23ULL, 0xA3252F845EB1F456ULL, 0x3E545E0A14B8C0DDULL, 0x780D5374894D33C8ULL, 
            0xD230EBEC3A2C5905ULL, 0x74EC1F50E8539F30ULL, 0xBADAAD24730E0CCAULL, 0x9F151AADD2245429ULL, 
            0xFD1483DDC139FE78ULL, 0xAA99C8F9E93822DEULL, 0x7DA6224CAE0A57E5ULL, 0xF1067677886886C1ULL, 
            0xECBD778036445EB7ULL, 0x18C76AD9DD456622ULL, 0x89C045763B06581CULL, 0xE0DBCB9EFED01A8BULL
        },
        {
            0x45D7DE3190D8A2CAULL, 0xD354711BB682EF5AULL, 0x62A63900FC9C085DULL, 0x40818959FF889EBFULL, 
            0x75A5F1914669D08CULL, 0xC30D61ECA9E9D063ULL, 0xDE8E6CC02252B918ULL, 0x608EE97809959C7CULL, 
            0x1B506DC19DB99AB5ULL, 0x69CF5B83031917E2ULL, 0xA9B7116D7EB4822EULL, 0xB986952A4A73C812ULL, 
            0x9F65448AB8FA0C05ULL, 0x8394A0E29EF9F90AULL, 0xC2C3E899755CFE4BULL, 0xC122EBA21821AEC4ULL, 
            0x2A7560B3CB6A3338ULL, 0x15F3D51CECF397F5ULL, 0x167541B900D4D269ULL, 0xEFCCFA1C3F4F382BULL, 
            0x8721BE2923AB434EULL, 0xA49BA80C84C5DA80ULL, 0xB01E25F745A1DA76ULL, 0xF55884169FEAEBBFULL, 
            0xA6FB430EF13E8223ULL, 0x9FA6DE9EA09E062CULL, 0x34E2E8F275D90F96ULL, 0x762AD5F086DA05D5ULL, 
            0x827BDF5F4792A613ULL, 0x480D41A048081938ULL, 0xBAFE5FFAA5DB5DE6ULL, 0x7EC3714F750905E0ULL
        },
        {
            0xC3745E6EBE2D1C8BULL, 0x2905E880159E2817ULL, 0x133308F9AFEE984EULL, 0x034F1ADBA1BC0B89ULL, 
            0xFCF60489B91240DBULL, 0x29A41A063AE6C50AULL, 0x0BD94E9ED375EC3BULL, 0x4216AAF719D50AE1ULL, 
            0x90A0D0D06319361AULL, 0x00C1395C0A4D692EULL, 0x135BA2AA7836D6FBULL, 0xCB6D8AD010DD1B47ULL, 
            0x362BC465DF993369ULL, 0xE4DF114D79E9C61DULL, 0xC9A955E08D7BBEDFULL, 0x7EBD88FDC6F8C558ULL, 
            0x99993474696907ADULL, 0xCAA51DFD84384493ULL, 0x93759918E1885C4EULL, 0x6D6B2E925C93691BULL, 
            0xF81CDED08710BD94ULL, 0x5B1817A566ACF92FULL, 0x7F50BBE65FA6FE29ULL, 0xE217B5918A6B6B06ULL, 
            0xA2A788DAE448701FULL, 0x5E71F3F315D87AFEULL, 0xD958523E0609D427ULL, 0xCC9330D97BD423EAULL, 
            0x19A399D85363ADB1ULL, 0xBD289BCDC564ABE3ULL, 0x294CEB97A4E79C2DULL, 0xCE4B1542B3030535ULL
        },
        {
            0xD6C43A9D4C6BBD69ULL, 0xF080CB44F949B7BBULL, 0xE31EF90E442A2A74ULL, 0x9F0661218E8F349CULL, 
            0x0484312B6895F349ULL, 0x7080EA96A6EFD948ULL, 0xB3854E93A30F79E8ULL, 0x1FC070E9E2913A9CULL, 
            0xAEC49D6C1EB71EBBULL, 0xA681E09197307B6FULL, 0x762E887D48F67556ULL, 0x23A746F212B435EEULL, 
            0x04DF21EEA04B8290ULL, 0x4802CC3F935F166DULL, 0x3F4B2D9349901235ULL, 0xAEE795A34BBE5020ULL, 
            0x67B7195C57BD311DULL, 0xEBF111322948E23DULL, 0xE849984D5ED527F1ULL, 0x9090296F9B2916A5ULL, 
            0x69B9ED0F3664D40CULL, 0x944263CF487CEF33ULL, 0x772881745B7AD270ULL, 0xA0418AC2BA988BB7ULL, 
            0xBD95C79B72B85306ULL, 0xB0A41CE16FA13568ULL, 0x0CC775FF5E4C1A4BULL, 0xA6A2E3513E65010AULL, 
            0x6463F431D1070C87ULL, 0x10795979157AF3C0ULL, 0x155DB139E50E537AULL, 0xABFAB9F12EDE7C7DULL
        },
        {
            0xA114D4F9688955F0ULL, 0x4AD1FEE20CCF60B0ULL, 0x29ACD57D3B4029E9ULL, 0x73E1E04649F281C7ULL, 
            0x98FCAD717EFC91B6ULL, 0x16ED6A48A183D6D5ULL, 0x6A8414B8974D5F94ULL, 0x724AAD6AAB048B2CULL, 
            0x30F2623C8E0C3FB3ULL, 0x6F9043E01F41A51FULL, 0xAE41BF406C1B779FULL, 0xB0A74E91712DBE65ULL, 
            0x881BE47A54E122AFULL, 0x33C076DD30177DACULL, 0x2032E21A40CCA43CULL, 0x5A41EC886A2741BCULL, 
            0xF37771011D119B61ULL, 0x338143C306BF31C8ULL, 0x7EA61B22E2F1C4A2ULL, 0x190930077F0264F8ULL, 
            0xE98D94E886F4AB33ULL, 0xF11A7225EBF54263ULL, 0xFF6F168B22CEDF96ULL, 0xF173E9DCBF270D0CULL, 
            0xD0CD3B184A5669EEULL, 0xC6CA288AAB8F0A90ULL, 0x195C40F57775A544ULL, 0x2B9A752FB344C9F9ULL, 
            0x8BD0901E3340A784ULL, 0x25CD7B9CF679F144ULL, 0x418D796745EE2AC7ULL, 0x7E01B72883EBE8B8ULL
        },
        {
            0xABE2550D321994C5ULL, 0xB200ECAD641E0BCDULL, 0xED92F6E077B710C7ULL, 0x11741D6C03CF73A3ULL, 
            0x3AF345343AE50FC5ULL, 0xB4A6CC49664F3FC3ULL, 0xA12CEFF2EF6CF9DAULL, 0x2D4259DAE3DAF654ULL, 
            0x6EDFB6EFDB33154BULL, 0xBA758D66D1BE2AD7ULL, 0x25BE4F494903EABBULL, 0x5867BC2D9A783DBBULL, 
            0x727DB6D0D69D12FCULL, 0x8CAE31EA4D6CCF24ULL, 0x1CCAF53F0C24624EULL, 0x1122E05CA2AF34CFULL, 
            0xF9CF42C6E80C02A9ULL, 0xC80B049D2A8CF9BAULL, 0xB5E4DEC423F2756CULL, 0xB2CE9D8FF66F20BAULL, 
            0xA3A3431EF14BFF84ULL, 0xE63E0AE5965DBB94ULL, 0xBF91212BDA4EE55EULL, 0x0A69BA90090FC2B0ULL, 
            0xCD63EF959274446FULL, 0xA2CF80052DF224E5ULL, 0x0F84934B65C02C92ULL, 0x81A07C08AE572F97ULL, 
            0xB549C23AC78E017EULL, 0x911AF0E4D201613EULL, 0x34266CA98B4CA373ULL, 0x816B55F00A671F29ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseDConstants = {
    0x2CD4677B7730409DULL,
    0xE6A2FA783AA5FAB8ULL,
    0x26D33DC0A22849EBULL,
    0x2CD4677B7730409DULL,
    0xE6A2FA783AA5FAB8ULL,
    0x26D33DC0A22849EBULL,
    0x21D62144A455020EULL,
    0x48C196C63025E864ULL,
    0xEE,
    0x32,
    0x74,
    0x41,
    0xD2,
    0x9B,
    0xD0,
    0xAA
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseESalts = {
    {
        {
            0x789F6BE8425C14BAULL, 0xB0AF08B079990B2FULL, 0xBB83DD745D14E6BDULL, 0x70B0834801553258ULL, 
            0x2EF08A73BE2A9826ULL, 0xD8FE3CF58FC5F311ULL, 0x2A797E354AFD140EULL, 0xBDF3BEF1148A8E84ULL, 
            0x34771C963A358CD1ULL, 0x4447881ABE516893ULL, 0x62B7EC8DA59EF402ULL, 0x275600CEDC901195ULL, 
            0xC39A2F7A2AE5F722ULL, 0x5B0AB6284226EB84ULL, 0x80950ABDA2874469ULL, 0x8522B722CED1B0F8ULL, 
            0x05C822EBF00167CEULL, 0x49E8F4B7F56981E8ULL, 0x9662C3CAAAE46EC8ULL, 0x83797D249DF64F8EULL, 
            0x67FD396E473DD960ULL, 0x6CBA159ADA924A61ULL, 0x36BC3BF22422BF8FULL, 0x002CFECE9EA075FAULL, 
            0x2C914238CF21215BULL, 0x4A7EEF7510C5F9D6ULL, 0xB032130024BE0017ULL, 0x1B3CC88C4293B7E4ULL, 
            0xBFCEDA5401294A86ULL, 0x7BEDC5D1F0F3B5F0ULL, 0xD9ADFE7EEB8F7277ULL, 0x179942D78DA70FC9ULL
        },
        {
            0xEE81884AC9EFC63AULL, 0x1700C972E389A1FAULL, 0x5EB5CE400823BE2CULL, 0xB0B5BC930E6724D7ULL, 
            0x0D075DE8904495A1ULL, 0x2B41B8B2ED61A79CULL, 0xD6432A1E21C511A3ULL, 0xDFEE75D1FB69B1C4ULL, 
            0x8EF0B1F8924C1BB3ULL, 0xC1C6DFF301341CADULL, 0x537EC70FEBB1AEDAULL, 0x869789BA9F2A3D0EULL, 
            0x687D41CAF74238BCULL, 0x69FF499C040D9CEAULL, 0xBBD9942E1C0D032EULL, 0xBD79271FFE93FA0EULL, 
            0xA0EDD8E2164D5C53ULL, 0x25121BC707F4BF20ULL, 0x3F44524334BA6390ULL, 0xE555F11EEAC85037ULL, 
            0x7E63B98D74562BDAULL, 0xE693706B2A4FA042ULL, 0xCF24A03F97930154ULL, 0x67E10FDE3AD49BE3ULL, 
            0xDC42768B566EB39BULL, 0x22A64102D68530C1ULL, 0x678E02C8C96BABA5ULL, 0xAA729C314F978A71ULL, 
            0xC46FB7DE557D4A5BULL, 0x225FD6062BD8DA15ULL, 0x1FBB2435AF59D375ULL, 0xC640D71CDF51494FULL
        },
        {
            0x71052C858A76C48DULL, 0xC7F2E29E55F38AEBULL, 0x3D3C3CF3D76724ADULL, 0x0D46284A1F502B50ULL, 
            0x5EF0F28F8624C778ULL, 0xB3996AC422DC7702ULL, 0xBCD6E9DD284FE5C2ULL, 0x556B0792D864D9ECULL, 
            0x69DBF948D666B132ULL, 0x71CA69A66FF95717ULL, 0x2EA2E404B71C982DULL, 0x41A6CE849DF032A6ULL, 
            0x48F86E5659B46E06ULL, 0xD55D39DD3E0AF99FULL, 0x371A9FB97936EFCCULL, 0xA01E063F8C79F93BULL, 
            0xD03B3D0B97380216ULL, 0x7FAD72D98E7231F7ULL, 0x810246231EB50FF2ULL, 0x21E8C8F9E00B95CFULL, 
            0xB9CCDA1ACB43E8A8ULL, 0xC49C677FDBC453F4ULL, 0x322452543AF102EEULL, 0xD06F61D257329D38ULL, 
            0x4E58D6BA75283DE8ULL, 0x5721E3AF9DF68E20ULL, 0x9F45DD6FD285B9A6ULL, 0xFBE3E956A06D0558ULL, 
            0xB7D06D9830A44831ULL, 0x0DD470553E8A7F32ULL, 0xBF3E5D2A2FAA6510ULL, 0x5C9E8AE2D46B2BAEULL
        },
        {
            0x59D12D483147836FULL, 0x8ADBD07A836A0419ULL, 0x35C2CD36FD57C725ULL, 0xEAB77DD3641E5B57ULL, 
            0xD73E8C3C4484D2C2ULL, 0x40699F557A900A27ULL, 0x6808C3F56E276C66ULL, 0x65B1591E5D663B96ULL, 
            0xBF89097D64994D40ULL, 0xF88F3C0501008A0CULL, 0x27D8B993A3A5D34DULL, 0x5D7E86B589F2F05FULL, 
            0x2BB5FFC908584234ULL, 0x2951919281F2AA77ULL, 0xD849788E8345A177ULL, 0x09F41BE23E7FBBB5ULL, 
            0x77CED30270A09D50ULL, 0x7B948F95C7F6F97FULL, 0x1C8E8A7EC8780963ULL, 0x60CA6F33B6B63D8EULL, 
            0x8F2C13C6860C1ACBULL, 0xECBD1D423DAA4DD5ULL, 0x7C2398681FB81C6BULL, 0x85370B607F8057E7ULL, 
            0x6AFE2AB5ED72AD92ULL, 0x130CE43B53D0D535ULL, 0xDEC6BDCA5974331CULL, 0xCDF614C6EB3F4A49ULL, 
            0x207327C4AB12470AULL, 0x6CA1868606853D8FULL, 0xEB2C9B5A2E5AA593ULL, 0x9F63AE218A2CFEDDULL
        },
        {
            0xF28C8A71CA8B4BDEULL, 0xA220F967F0ED277EULL, 0x1C814D5A51FAC988ULL, 0xC237FCBFF0721BD8ULL, 
            0x7EBA3F4D52DD9165ULL, 0x4BFBB047E510B4B2ULL, 0xDE105CB7B4F710F9ULL, 0x8D6356BE4DC74DCFULL, 
            0x8C3325A28DF89F92ULL, 0x70ADD74F5BC4B3C7ULL, 0x7F91EF18132F30BBULL, 0xD062937D538B22E0ULL, 
            0x68F8AD9498134F4BULL, 0x393131D2F877A55DULL, 0x0C43A1D20DE44441ULL, 0xD6BF22603DC09E21ULL, 
            0x42C62F9083D307E5ULL, 0x4E888AF4FA3933C9ULL, 0xDA2F02AAC4E42063ULL, 0x9086DCA6C2FD4097ULL, 
            0x29697F08E4F70066ULL, 0xC4F5587F66280565ULL, 0x2B9E7768F6F34720ULL, 0x8CD6F74F00DC87A7ULL, 
            0x8C1EF4A0C6E0A21CULL, 0xD8CB5271564DE055ULL, 0x8A3BF7B8D249613CULL, 0x2470CA090C956221ULL, 
            0xD44632B7A29F5E2DULL, 0xFA6EE3D4D9AD9C5FULL, 0x26C0A045EED09CEFULL, 0x4E372761F13C4C5DULL
        },
        {
            0x8D4085E798081E94ULL, 0x8961DC81EE6CE4D7ULL, 0xAA5A47CF0AEF81C1ULL, 0xF2DBD762586F3D00ULL, 
            0x81A7C67623DE28FBULL, 0xB68E78007C8713D7ULL, 0x35D21F241CAB334AULL, 0xCDA30A8794DB4976ULL, 
            0x24AB2086238F7B15ULL, 0xBC0605A1F3075F98ULL, 0x1DE36FBCB0C4AADAULL, 0x697D802506C86BEAULL, 
            0x5B6DF7C9A8E0269CULL, 0xFFF01CC259AB862EULL, 0x598F20C26275A662ULL, 0xE32E3B1CB600C705ULL, 
            0xD439F32F361D82E8ULL, 0x5B9972F932A52135ULL, 0xBEBCD75D5E9F1B01ULL, 0x1352FA8AABB7C8A8ULL, 
            0x5EC2EB837E135B70ULL, 0xCC3294B3954306ADULL, 0x940D7EE1DF57629BULL, 0x5233041F38B656AEULL, 
            0x8646298158AD6204ULL, 0x8264C2A65CDC7678ULL, 0x1DF0FCFDDCEC6D44ULL, 0x3ED2078724FCEE55ULL, 
            0xE116CC8F3CC24CA8ULL, 0x6B71BBE5813F1633ULL, 0x83ABD223E0A54D70ULL, 0x86264C1F503AF6A6ULL
        }
    },
    {
        {
            0x97837F7D9A0D4056ULL, 0x2DAED01E570C1F35ULL, 0x05F00CB945CD15F3ULL, 0xFE5A52A7EFAE6396ULL, 
            0x55592112A721EB06ULL, 0x66CFBF91142DE4A6ULL, 0xDC99A950BDAD5092ULL, 0x084E8F6090583B06ULL, 
            0x50B6FE6B8777A901ULL, 0x54D215C06C80C31DULL, 0x2B46767B5A72A56FULL, 0xC527E1BEEAA1C9C3ULL, 
            0xC5329AC861853652ULL, 0x89E690EA81BA4CD4ULL, 0x0B7561DDFC398495ULL, 0x87FBFB0FE5BAA29CULL, 
            0x0ABA3CDC8AAE2050ULL, 0x14FD5F35B0922E64ULL, 0x67F12A99309AB5EFULL, 0x2F13C424C8DB8F36ULL, 
            0x52B621B77880011BULL, 0x236FB83C2894F87AULL, 0x9537E8F82DF37985ULL, 0x7B4FE9630563BAA0ULL, 
            0x5640F6B0225DD66FULL, 0xED280170ECCF0D46ULL, 0x4B40E3476F6D33FAULL, 0x47DE1357867D460BULL, 
            0x1B2369B9E2DD5D2BULL, 0x5C97B2C7AA84B475ULL, 0xCB32B37AD961EEC2ULL, 0x2E495E08B0BC6895ULL
        },
        {
            0x9783242A4B8691CEULL, 0xEF828A0B436F7F70ULL, 0x51105BD6C225AD1BULL, 0x00E59187BBCE61D4ULL, 
            0xC4042918DF2DF12BULL, 0xF5EF04F12E32240BULL, 0x31B5E64623CD8E7FULL, 0x9D05423A41577273ULL, 
            0x48B1C53F19FA6F62ULL, 0xA082CDBE68D32510ULL, 0x5C93060AAF2B6ED5ULL, 0x18FD4A52F667F71AULL, 
            0x71DA180A63A7892EULL, 0x566192193850AA65ULL, 0xA904D12A647A2D76ULL, 0xB5B6858AD852FA26ULL, 
            0x75A3DD223319E274ULL, 0x9C7BC0CC878E9C45ULL, 0x94DA887E09967C05ULL, 0x8B7652852067FA13ULL, 
            0xDAD856DE3EA0CFA4ULL, 0x8B8FCB053B796564ULL, 0x9DAA5BA7EDB0CB8EULL, 0x18A921E8AA68E814ULL, 
            0x82F11162EC49D0D7ULL, 0x7B96F2A6F83837E4ULL, 0x8B03867F6A140AD7ULL, 0xCEA19A29336556D8ULL, 
            0x75D7FB0646905B91ULL, 0xBCD93A5F89702708ULL, 0xBFD94A6F967486F7ULL, 0xB997E89FC518393BULL
        },
        {
            0xD63BC97B50D97657ULL, 0x4C339D438367A5F5ULL, 0x89481F6860FAF0B1ULL, 0x8E94CDCF312C51A2ULL, 
            0x1D2FCEAD07605312ULL, 0xAFA342CBE54162CBULL, 0xB072B21FE4376592ULL, 0xB3931C9C93E760F3ULL, 
            0x8673D5A08B85E1ADULL, 0xCD31A3EB750827CBULL, 0x941D9AC08B2A5321ULL, 0x91C847694D4F5B64ULL, 
            0xCF9DD53AAC4CA2A5ULL, 0x6708CF67EA2BBFFFULL, 0xAB6AFE27516E1C6CULL, 0xE4B9F162DF70FBBEULL, 
            0xEF0897FDBC1107BCULL, 0x43297EF03576796DULL, 0xE5332FEA250E6962ULL, 0xDDCAA4A6C9FF9DABULL, 
            0xDD9CF9CBF3C72347ULL, 0x041244BE1E6FC307ULL, 0xD012F3EA49C5EBA5ULL, 0xC3E2461E9233D2D5ULL, 
            0x2F126A3583EAEBDBULL, 0x1551E462ED73EBB2ULL, 0xEBF88CD9C1D9ACEBULL, 0x1E543590C27765EFULL, 
            0xC92FCF7973B5DD83ULL, 0xB04DF797A00B1D77ULL, 0x923E01C679776BFDULL, 0x9AFEDD58E71C18FDULL
        },
        {
            0x9CF0F4D37A9884D1ULL, 0xE0770E44D0449043ULL, 0x919409B4D7795E14ULL, 0x9EE6757B47525886ULL, 
            0x7252B6081D0FBD44ULL, 0x77187A2D78D2FCB4ULL, 0x5C415009C3FDFFC7ULL, 0x8090A2A13B6CF7AAULL, 
            0xAABC7000BB73BE8CULL, 0x25B43BD478B33B17ULL, 0xF0C472E4138382C9ULL, 0x753F82E9AD3EA0B6ULL, 
            0x79CA73FEBA8D50A8ULL, 0xD1737C16EC9455DFULL, 0x2E291B9F1073F15CULL, 0xF06790000BDB70FDULL, 
            0x1376A7FA9695C5F1ULL, 0x12B64CC232A10256ULL, 0xB663F226FD0A9355ULL, 0x2FFC6479FE7D6598ULL, 
            0x5BCE0486AD65565FULL, 0x65789DCE3F41C808ULL, 0x49D9963E6D27DEC3ULL, 0x88B4A4AB870300DCULL, 
            0xCBFEA6CAD04FE622ULL, 0xD7E5BA4A6505B470ULL, 0xD9C0311DFCD12B54ULL, 0x428056F4051F5162ULL, 
            0x04FA595753D31240ULL, 0xB94E2C9DBC2C8C2AULL, 0x5AA18E1FBAAA3670ULL, 0xFCBE2100C2889669ULL
        },
        {
            0xFCD34F65752B69BCULL, 0x6CE77BBE246967E5ULL, 0xE6C4AEF19D266F47ULL, 0xAD7E493AE186BF74ULL, 
            0x791E0EBEFB1BA4D5ULL, 0x2D81079262CA5FF4ULL, 0x6A7428D551574A3BULL, 0x284AA5AD9AEB8AD0ULL, 
            0x2538249636068AB2ULL, 0x831CFEC97CE78FE5ULL, 0x0D882FC843353865ULL, 0x858FD8B8F288C3DFULL, 
            0x4FA697AC7E64872EULL, 0x6727972A4D20B90EULL, 0xE7D023A20E8B2A1BULL, 0xEB9161D66448CF9AULL, 
            0x0867DE6F4BF8C5A1ULL, 0x306EA4E132214A95ULL, 0x98E5031FD43188E5ULL, 0xC45B1D7A852DF5DDULL, 
            0x895F8520B8C18432ULL, 0x34BD56D6B72919CDULL, 0x4EDEB47AA3F59EA4ULL, 0xBA8F021DC6D94C32ULL, 
            0xD63F1917B4BED463ULL, 0x92655FA768483DFEULL, 0x4E8BCC930DA57074ULL, 0x8965F1C257A5F8B2ULL, 
            0x2AADD4BAC79767C0ULL, 0x59EB8A1795BF2174ULL, 0xC2DF48AAB7B6444EULL, 0x73775FF282BBA6BFULL
        },
        {
            0x2D9A7FC66B917C05ULL, 0xD48389D45661A0CAULL, 0xEA4C79D147CC8810ULL, 0xD7AC98E119C16C69ULL, 
            0x47149C188550315DULL, 0xE72E20B7A04EBD42ULL, 0xBD4DB0EB5E3D5E0AULL, 0x1939182C9E0EE0B1ULL, 
            0x96A3B6B799F4A6D7ULL, 0xC435CA9E35CF7DEFULL, 0x334A7775923E9D2AULL, 0x69364FD2F826F2CCULL, 
            0xF10E4EC8EADEDEBDULL, 0x926673DD49EE9980ULL, 0x241EA6E1BA5A2AABULL, 0x438A9386CFAB4338ULL, 
            0x87E81EADBF2EDE65ULL, 0x7D63C3876F25DDE3ULL, 0xFBBF6422E68DEBFBULL, 0x6FC16822A70A5E5BULL, 
            0x08AC66059409252AULL, 0x3F5F00970A6B97F2ULL, 0x1A85363131CCACE2ULL, 0x6EFA60A446BB6431ULL, 
            0xDC99B8062F0A9041ULL, 0xA8CBF20E18600619ULL, 0xC9CAC3537B85F99CULL, 0x1D5ACA28F6ACF609ULL, 
            0xB853E43DE832BC36ULL, 0xAD845FA63EF625DDULL, 0x3302E244EE7BB974ULL, 0x74BCDEB88A91CE7FULL
        }
    },
    {
        {
            0xB9E7CE6674356F05ULL, 0x46D950D7FCA967A8ULL, 0x3039C7956E3E4F66ULL, 0xC3B78E985C03C353ULL, 
            0xAB171E23FB8F42C2ULL, 0x8FA5E4AC7AC533FCULL, 0x3AB12C9E7033DF50ULL, 0xAFFB033409F136C8ULL, 
            0x2505CF80B68B58D2ULL, 0x71049E5355C6C1D2ULL, 0x37E5E8E46A8D9EACULL, 0xF0B1FE4018A2F5A6ULL, 
            0x5364F20658A1F066ULL, 0x7A4E8C3FB35E0F5FULL, 0x5FE0D88C94FD4CCAULL, 0xE5B4F8C0F583E858ULL, 
            0x92BA87C12381E141ULL, 0xF0B5E998177C12EBULL, 0x5908AFAD822625CBULL, 0x86884092C4A6D81DULL, 
            0x7450BD88DB565D63ULL, 0xACFD64762A27FC55ULL, 0xDD1254C8483C5807ULL, 0x6422F19850AF7204ULL, 
            0x19F1AC47CD6ABD88ULL, 0x976DFEF0C1368A2EULL, 0xD26A2CDEAE8F28CAULL, 0xCDA883C4446EA763ULL, 
            0xA35161C3130933C6ULL, 0x7964DC60F2804DBCULL, 0xA776C3618FE13950ULL, 0xAB09A059DCACF874ULL
        },
        {
            0xB64A1B333C04F22FULL, 0x21EF01C5ADEFC274ULL, 0xCE04C210955FDB46ULL, 0x932A9B70B7F2FC18ULL, 
            0x40A43F9EFA608784ULL, 0x1341E1AD2194804FULL, 0xFFCA4375115AEC55ULL, 0xCF95458EAF0AA06DULL, 
            0x52C80BE0377AAD2CULL, 0x1A2208BE73F40679ULL, 0x4E255BDD5A9EE03CULL, 0x7281139A0A772AF3ULL, 
            0x5DAD1D8BF813AFD0ULL, 0x101992F95AFF804FULL, 0x68AA73D17EE41C94ULL, 0x8C237991ED8D8710ULL, 
            0xF0B440B1ADBB9C8EULL, 0xAAFC01B1ED865168ULL, 0x77048AAC6C6B8803ULL, 0xCB1F5C6E1E5DA436ULL, 
            0x097FE556CAE8CB6BULL, 0xCF7FE648EC1E56FCULL, 0x075D0A3C2FF9C4BCULL, 0x8D801C5904B3A008ULL, 
            0x65ACD2F50786035EULL, 0x44AE1C82D5C7AEEFULL, 0x2F9044C032550226ULL, 0x63360D35509E22BCULL, 
            0x5E3B7EFC1B2972E9ULL, 0xC02EB1A919125570ULL, 0x563AF2604D436040ULL, 0x33200A828B5443A1ULL
        },
        {
            0x9B836CC50F1EE71CULL, 0x5D624281CF447369ULL, 0x56F9C6E9D3173F50ULL, 0xE470FA9E88323F8BULL, 
            0xFA00F73AFCD0450FULL, 0xA70AF69F6FDA6AD4ULL, 0x949A2D393EF7ACFAULL, 0x5D2633D217C24914ULL, 
            0x8926A2CADB00858BULL, 0x7ECCE9709A8436E6ULL, 0xC45BA78486485775ULL, 0x941DB98C704C7BCEULL, 
            0x4CB043BE70F9B050ULL, 0x84794A79947A10EEULL, 0x2E1E6951239DC978ULL, 0x13E3CF6A10467003ULL, 
            0xEF4AE3122868C7EAULL, 0xB8FE9365B3AA0C96ULL, 0xAB6B1F8658EDD91AULL, 0x4F7AFBBBF4F5660BULL, 
            0x18D365E549BC1386ULL, 0xF8692485737C5CC9ULL, 0x0EEFA85C1392E562ULL, 0x5C62E13F8BF4E979ULL, 
            0xBD3350CB2E338DA3ULL, 0x0B01C13652BF4F36ULL, 0x473E4B2F2F28B6C4ULL, 0xDE20A2D3A966C24EULL, 
            0xAEA8D1D168A729D4ULL, 0x3CB91F1656DB2F56ULL, 0x548D39B9E61BCAFFULL, 0xFC538CA42E20F70EULL
        },
        {
            0x3061407FF22431FBULL, 0x8ABE3BF1A67E7F04ULL, 0x39A17D8A77517691ULL, 0x8AE9D7135FCB19A7ULL, 
            0xC1A63BB9C500E28CULL, 0xC6570F0B6D447C9EULL, 0xDFE3D12F8D68C51EULL, 0x646CACD35F2212B4ULL, 
            0x0E840CF0F5FE386DULL, 0x9DEE7870E77EF9FBULL, 0x266D85B9AE17BFE8ULL, 0xE41496C67A16873AULL, 
            0xD4D4F8CA208F06AAULL, 0x16E249FA84E9828DULL, 0xF5CF9C9CD44C518CULL, 0x7B8A47A7A7BE9092ULL, 
            0x8D413B6EB0BCA7FDULL, 0xCE204D8F3B6E2D23ULL, 0x8388A86A96A8E22AULL, 0xFC6438EC3786D0B0ULL, 
            0x2AD25C21B7F2221AULL, 0xF086EAD414A69269ULL, 0x08CA7B81198EDDD6ULL, 0xD0055BE70854397BULL, 
            0x35EAB5942FF8FAABULL, 0x15BBEB3A03533903ULL, 0x8CA2FB7DD0BA8D6BULL, 0xAF9FFBA97D3DD18EULL, 
            0x44E09F3E5DA41DFDULL, 0x6BE1A649E2BB2FE2ULL, 0xDDD82D0B850F8D23ULL, 0xEA3354A3EA69AEF8ULL
        },
        {
            0x2BB6F467317AFED8ULL, 0x41979A17CE491B3DULL, 0x25BBA126591330CBULL, 0xDFD70261AE400469ULL, 
            0x51610DA7A84F184CULL, 0x200C8D4ADCD47319ULL, 0x72F1AB0602119E09ULL, 0x3D025366D1BEE1B0ULL, 
            0x7285CF5D6129E01AULL, 0x4BE607CFFF470D7DULL, 0x23DCA8C2EAA88197ULL, 0x6B56351F49194CAAULL, 
            0x72C9574FBE16D19FULL, 0x969C2E7C0805F826ULL, 0x0B7CFB8142916DE0ULL, 0x8625CDCD115BCA97ULL, 
            0x68C91A3BF09A165AULL, 0xC6F5B3FC45C15EE2ULL, 0xAB46C75A92CBE395ULL, 0x439E4D3F5D208266ULL, 
            0xFAE53BC0A0FCB677ULL, 0xD2956811B2308E5BULL, 0x73ACE446BE760019ULL, 0x191B9FE4A62E82A1ULL, 
            0xC1D3C932CD225807ULL, 0x4C59789D152F55F8ULL, 0xA44BC4E98D5A8468ULL, 0xCF0AE4F27ECD50F3ULL, 
            0x2DF90B00EAFC2F1CULL, 0xF14EFB529AE5B4B4ULL, 0x401E783C05D049B0ULL, 0x208158C7B44C0AA4ULL
        },
        {
            0x0226E172B56C164AULL, 0x77B00DED733B64FDULL, 0x9646726FC3079FCCULL, 0x30C2E91408D4B47CULL, 
            0x22BEBFD846D90F28ULL, 0xEEEA131D0D9843F5ULL, 0xB7E1548C7930B4D8ULL, 0xE8E374790297714DULL, 
            0x9B818C046FD6EF1CULL, 0xF57A53EEC91C6C4BULL, 0x0E218D952B024E76ULL, 0xB53070108B2B5122ULL, 
            0xDBEF4A4709ACAE8EULL, 0x13109E787608B3C9ULL, 0x10685A1C196E92AEULL, 0x018B5F517883C638ULL, 
            0xAC3157406D9B4101ULL, 0xCF796325BDFEBBB0ULL, 0x032ED9F3206FDE03ULL, 0xD5845285D5898AF6ULL, 
            0x20087C33C8214088ULL, 0xCEA6E64D8E547046ULL, 0xF66579CB7D00E411ULL, 0x16F82703F801C2CDULL, 
            0xFAA6C63E8E5322A2ULL, 0xAEAFB7BA65B0582EULL, 0x48FE994162BFC149ULL, 0xF653D888731D5DD6ULL, 
            0x1F8EDBC9B017F2C7ULL, 0xE693EAB7DF5486C7ULL, 0xAF68BCDA7925A7F6ULL, 0xB774A7C799BB055DULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseEConstants = {
    0x15361B630CC04C6EULL,
    0x0025AE47327FA46AULL,
    0xFB62146687A12B6AULL,
    0x15361B630CC04C6EULL,
    0x0025AE47327FA46AULL,
    0xFB62146687A12B6AULL,
    0x1D9BCE3F6A5940AEULL,
    0xAE8981769096BB95ULL,
    0xBA,
    0xF1,
    0xBC,
    0x08,
    0x45,
    0x19,
    0x22,
    0x1A
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseFSalts = {
    {
        {
            0xEFDFB9D22B1A7C79ULL, 0xA76F00C36A363025ULL, 0x8A389882EEC62D4CULL, 0x546CC665DF8AB2D2ULL, 
            0x744B23F9DF970FAAULL, 0x839E54BCA6462D60ULL, 0xEA18C00D4FF87229ULL, 0x24D962F5B21E0E09ULL, 
            0xC2A6CA80174FF46EULL, 0x3E72122C8B93C225ULL, 0x41061164F2A4A07AULL, 0xE82ACCCAC736C22EULL, 
            0x347B7FC831C9EDA4ULL, 0x2CEF526002831A1EULL, 0x9CF81929582F767FULL, 0x01C27729697E7859ULL, 
            0x6879952FA8B26E7CULL, 0xDA27E69C1CCFD95AULL, 0xC2C67BACD87A9A62ULL, 0xC7D4CDAE85189AC6ULL, 
            0x255B77308C2A819FULL, 0x8BC2A0294F19F440ULL, 0xE77C41242CCBFA0CULL, 0x850909A056885050ULL, 
            0xAD2FF6E0F2E1FA0BULL, 0x9E41A8993E2AEF3EULL, 0x6E3821BA191B4356ULL, 0xD697F0A74AB71F7EULL, 
            0x9D51F114BC1EB13FULL, 0xC31A5770252162E0ULL, 0x6EBF48C9B7A6C5ACULL, 0x0BB1290A16810888ULL
        },
        {
            0x782384243CCA223EULL, 0x5E3EDDBC5F40115CULL, 0xB2EF9A499A1F18D4ULL, 0x112929B69F1F69DCULL, 
            0xC8B7947B2F1FFC7AULL, 0x24561A1647593902ULL, 0xF00B69D36D9FA094ULL, 0x2925F1FB10E3EF9CULL, 
            0xF8A93BED4EB9848CULL, 0x86B5A7C2C5301354ULL, 0x1057939E7EE46CE1ULL, 0x937F3875BA076E7CULL, 
            0x74764F8813BEAD39ULL, 0xC0C15FA5ABB2BDBAULL, 0x44F53092A4E17F3AULL, 0x80A8CFDDC09DC034ULL, 
            0xEEA0B829D3AD896DULL, 0x582DCB39918ABDF5ULL, 0x12839F82B7B7CD35ULL, 0xE416146D688BC526ULL, 
            0xB417414FFE2BB17BULL, 0x3D06E588F184E5BBULL, 0x62F9DA8EA0A33C4CULL, 0xBD640992ACFD061FULL, 
            0xF26AF93C7260F426ULL, 0x6F0175E700F5E87EULL, 0x4BC9F5C3F90E78A2ULL, 0x5C96B0A4312948CDULL, 
            0xA7007D947279A2BBULL, 0x224CDDB6935A3C44ULL, 0x3C541D9C24DEBDF5ULL, 0x8F1D1AB0AD00F9C7ULL
        },
        {
            0xE06AA897ACD9FF48ULL, 0xFF11D12EDF448AA9ULL, 0xD33D907B718DADBEULL, 0xD0C2274A575A98B4ULL, 
            0xBC959C6E4CA6DEB6ULL, 0x7FCBF9F85AA20A88ULL, 0xEEF8F2CBACC92FCCULL, 0x7C664573C35E9FC9ULL, 
            0xBCCFB2AA6FA2C3B6ULL, 0xD2E9A4E0A3F1B8CBULL, 0x74D9C1AE592C5AB5ULL, 0x8AAB4EFBE30FBEC2ULL, 
            0x831DF67E1A94EA3EULL, 0x49ACE5E4B3D942E7ULL, 0x2F1E08C74364D748ULL, 0x27CFFF329AA333DFULL, 
            0x47539682F95F6FEFULL, 0xCC5C57A0C369F8F6ULL, 0x9D53CB4D1A2C9BECULL, 0xF174FD2DB5BF844CULL, 
            0x911855339B2E4424ULL, 0xA439681E5D9BC2A3ULL, 0xC4834ABFEF4D5C2CULL, 0xB836A5411A186690ULL, 
            0x9010F08EF17EF629ULL, 0xD23D831722B146C5ULL, 0xC2EE404478C7DF2AULL, 0xFA1D2230DB4CEE91ULL, 
            0x865C922DFD49E5EFULL, 0x10DA05DD1420CE99ULL, 0x2DB052FFE7D2FD96ULL, 0x6299B4CC56458BE9ULL
        },
        {
            0x935B989ABFCFDF2BULL, 0x8FA8335AA0A01A33ULL, 0xCD8B592C14EABBA4ULL, 0x3C3D072BD2ED2816ULL, 
            0x5F54BECC11A8FBCFULL, 0x63ABE7A7CC48D102ULL, 0xC2CECA2BDFD27562ULL, 0xAE688AFC51AA0ABAULL, 
            0xC03CCBF59184A961ULL, 0x7C352C541B1EAEC6ULL, 0xE06AA6223D007731ULL, 0xFB35DE36D9BA7757ULL, 
            0xCB2D646EB337D72EULL, 0x1F970C1B260E324CULL, 0x1ED637D5B540E5FEULL, 0xE001F8595300A289ULL, 
            0xF454462EC04820CDULL, 0x25FEAF53E29F7C4CULL, 0x2C6F0674531F69F4ULL, 0x5FA2633195BE4305ULL, 
            0xD40D625ECB3CE868ULL, 0x858146F9A01E8FC9ULL, 0x0541AA779512AFADULL, 0xA779C2028F0922FAULL, 
            0x773637BCD4109CAAULL, 0x1E392D69CAF0FFA5ULL, 0x9A253021E03D2A32ULL, 0x61E27F884D6A4A3DULL, 
            0x59CEFF7E45E9F4A7ULL, 0x1D3BEF4C3FB62218ULL, 0xE45ED49235E020CAULL, 0xC53E5F3B3A0CA954ULL
        },
        {
            0x15EC080112688B4FULL, 0xEC9DED379F7A7797ULL, 0x77A2C9FFA811544BULL, 0x846C3054B40939D5ULL, 
            0x84C5130084A4AA04ULL, 0x863E8F127A33BE5DULL, 0x31C216FED5D4217FULL, 0x6EDD7A2D9E6D9429ULL, 
            0xE7189B248C665E2BULL, 0x652CFDD758A27F6DULL, 0xE3E98266C7877BD3ULL, 0x60004BCD6A499914ULL, 
            0x9345A2365ED9F024ULL, 0x05467D366C57D584ULL, 0xAB9BD89E9878C8D0ULL, 0xD9C78D1FCC200138ULL, 
            0x475A6D3F1A430D83ULL, 0x057F270F5C8941E3ULL, 0xD38374B128560B3FULL, 0x5E19A4FFFD0E1E6BULL, 
            0xEB9F967CAA255543ULL, 0xD472BBD7C468923CULL, 0x75267200BFB0141CULL, 0x46D3DF82D8234A4EULL, 
            0x962AD4A8B4ED2DB8ULL, 0xD8386759E580BBE8ULL, 0xECF7C970364FE9F1ULL, 0xBAA67C16F9AF75E3ULL, 
            0xC1F1CF7FFF165385ULL, 0xEB8DE0B20D858DBAULL, 0x882D411F6299DB8AULL, 0xF971E8F781218A36ULL
        },
        {
            0x760CB7B648EBDBD5ULL, 0xB70CF58E77D5A88BULL, 0x339B691B8819F3EAULL, 0xF0E1F1B8959D0A44ULL, 
            0x90CAD90E29D783E0ULL, 0x2880BDC98C59AF27ULL, 0xAFBBCE8802F20E74ULL, 0xA2DC1BF04B73BBD2ULL, 
            0x220F010D4D21A8E8ULL, 0xD87BC0B4337D8FEDULL, 0x4D460845BC03554FULL, 0x0A73F60C1ECAB858ULL, 
            0xDB2BAB1D131C9687ULL, 0x2F01D222B0308F5EULL, 0x67212CDDEFEB5E96ULL, 0x6BCF9C4FB11F3D91ULL, 
            0xC77B0E7DB4A5B1F1ULL, 0x79DF84C1982C0DF6ULL, 0xE1C2B52FF725B5F3ULL, 0x57A488A51D16FF49ULL, 
            0x82FB71B08B537012ULL, 0xBB0D2866267FA873ULL, 0x958FE5CD62BF87C9ULL, 0x286DFEB4D910C712ULL, 
            0x7AFCDA18791E20D7ULL, 0x8644B7DFEFDB0846ULL, 0x872D08D17D9A3EB6ULL, 0xAAC40B62A6E23217ULL, 
            0xAEF7101C2EFA9FC9ULL, 0x21B0415DA80C4438ULL, 0xECBD0EA22A5BE1B1ULL, 0x3BA59FA57E448812ULL
        }
    },
    {
        {
            0x4358EAF504D75A9AULL, 0xA9734130F8287A45ULL, 0xE175511BFA0FA374ULL, 0x14CC6D6A39CACEF8ULL, 
            0x99A2E2D6733A63F6ULL, 0x4BBE51979E57078FULL, 0xD252975A1C2E6636ULL, 0x49664CD29E129BB1ULL, 
            0xAC9DC0C888DA5D42ULL, 0x5CCCE948E6CCEB76ULL, 0x28C3F2B11C2FE136ULL, 0x9FE400E3A4A514EEULL, 
            0xCA45BA5FE979AE24ULL, 0xBB5322D479BAAED5ULL, 0x93B9C1EF4924A7BCULL, 0xAF304668400B2885ULL, 
            0xFB9942A430DC16EAULL, 0x07E59A9A594E1C88ULL, 0x9898603A23E72458ULL, 0x18F72851C3128B6EULL, 
            0x8ACB9A451019D428ULL, 0x5B829B73DFF36716ULL, 0x4B4DB441E206C452ULL, 0x240EAE9051736652ULL, 
            0xDD91158D57BF53F2ULL, 0x15DFE3BA2885137CULL, 0x0AD7D0BD754C9A48ULL, 0xDA61E77159192224ULL, 
            0x071D0ABB59941867ULL, 0xA8178BABEE54877EULL, 0xD01B2EF51BB17F6EULL, 0xA3AFBC933EC3FEC3ULL
        },
        {
            0x5573F55CE50FD0D4ULL, 0xC0E7ACBF09DE618EULL, 0xD3D5166555D0FD9FULL, 0xF891F70E115EF28EULL, 
            0xD1CE4FA8F310083DULL, 0x5E8EF92DB3B86C6FULL, 0x49CDA805546370E2ULL, 0xAA155A2840EA56BBULL, 
            0x56153CD61D59F011ULL, 0x886A577B074169DAULL, 0x8268954EBEFA326CULL, 0xC5D7FDB9905078FEULL, 
            0xC3323B7AAC2BF3B4ULL, 0xC3373046B4131C3CULL, 0xD008F58F56286B7CULL, 0x5679D0DA63C0C3D4ULL, 
            0x0D2E56444DA867A5ULL, 0x8DB9985A7565AD10ULL, 0xA587666B4396E176ULL, 0x0A500E0F006639CCULL, 
            0xB9D8FA7B1A578248ULL, 0x7D1C6275800D40A0ULL, 0x06EDB1EC7CF42B1CULL, 0x6C9F23B89EC797F5ULL, 
            0xDE7EB64A996380EAULL, 0x27A4AA57D5158390ULL, 0xAB7547971F244DB8ULL, 0x1D8686408E80EF43ULL, 
            0x921E92560D28E817ULL, 0x7B50E4F80BDA1234ULL, 0xBF66B6A6A75C6015ULL, 0x1ABA837458F92FADULL
        },
        {
            0xB524FCDF6C7F6C77ULL, 0x9A2EB30548C65E21ULL, 0xCCB88171DD2B4CC5ULL, 0xF081F1514A53CA51ULL, 
            0x12D5755BE7BB1E4EULL, 0x18268EF54A35135BULL, 0xBDAA745C84C71DD9ULL, 0x4A117962EF95A3D7ULL, 
            0x8E16C520E145EE53ULL, 0xFD4A18B45A3B2555ULL, 0x070E8F2E8CD025A7ULL, 0xB4FAE036CB300B0FULL, 
            0x051AEDA43EB9C792ULL, 0x51F20A7CB536EBBCULL, 0x259FB768425141C0ULL, 0xC560F6B54FEA97FBULL, 
            0xF43F64216421AD18ULL, 0x1EF860093CEFFA56ULL, 0x09756E5D05586A92ULL, 0x13FF12883E07F3C3ULL, 
            0x3BF08EB0A92B1FC5ULL, 0x9045A68C88AD819EULL, 0x0B204D375074061BULL, 0xD0ADC342C542D03AULL, 
            0xC68213999AEF1B3BULL, 0xEEEE3CCCC38648DFULL, 0xFD72467FF4D8B126ULL, 0xD74668E65599AB7FULL, 
            0x9F4429806A7D0B5EULL, 0x2E445D499596F7FFULL, 0x1793DA208BF544DEULL, 0x603EC26E159E21A1ULL
        },
        {
            0x42C82E9F6AB9FE29ULL, 0x4A3F8667D30CE6DFULL, 0x699B184A1F05CB53ULL, 0xBB8089079917436EULL, 
            0x91C9E8E90ABBD1E8ULL, 0xA976E6B54C626506ULL, 0x0A4E5F20C4BD2F4BULL, 0xE65D80D81334E62DULL, 
            0xFF81A9A0A54CEDB7ULL, 0x37E94FCDCBE15FAAULL, 0x5F41B944770BB2C1ULL, 0xFEC5835792024AD7ULL, 
            0x8E0B5E990130B1D9ULL, 0xDDA8E0C36EE0EC2DULL, 0x2DB71B23D996B038ULL, 0xBD88EF5F050B274EULL, 
            0xA313E83EEB691265ULL, 0xA1677864BFBD86A0ULL, 0x7C8BC81140B6AC9AULL, 0x64AE8894878F814DULL, 
            0xB7AD5B7EE8EDEFE3ULL, 0xB1A1991F7D7131E5ULL, 0xF0CED245292A5FEDULL, 0xCADB5DEA0CF8CADCULL, 
            0x971D4A9BE0D74E30ULL, 0x2355B88253369BE1ULL, 0x19AECE938275BA15ULL, 0x1D6EC76F71617859ULL, 
            0x90FF1B160CA6D2BBULL, 0x98DCA3FB518E7862ULL, 0x08968DFACAC6AE9DULL, 0x9BA1B7ABD224548BULL
        },
        {
            0xCD90D6E3DF776E60ULL, 0x4CE0013C9DA745F6ULL, 0xF6B64D65A8206236ULL, 0x49B6B4265EEBB6E1ULL, 
            0x0F10E00606DEBC71ULL, 0xA05D6313B65001E5ULL, 0x306C998D3804A9E1ULL, 0xDB5754CD592CC3DFULL, 
            0xD5B296F095297D37ULL, 0x1E17AAC338CDC0DBULL, 0x4CA502258C304A25ULL, 0x4FEB6A53026C47C3ULL, 
            0x1532D8CBEF2EE16BULL, 0x7B71293F960D7052ULL, 0x67C9BB41A04D4056ULL, 0x65FDB172984361B4ULL, 
            0x3FCEDBA494DB4F81ULL, 0x9B350F2459949A5DULL, 0x23956B32F22116DAULL, 0x29EAEC2FE4007487ULL, 
            0xCEBCDF78089B820AULL, 0x3653EE81EEA1E658ULL, 0xC2D345BE796E8EF0ULL, 0x0A8C2058C49C63BBULL, 
            0x424E16D2FA89E4B1ULL, 0xE3282532FBCDA1F7ULL, 0xFBABD7BA683D9343ULL, 0xA851FAF84DA8B0C8ULL, 
            0x1E2D918313AC803CULL, 0x0D2D6F1A80139585ULL, 0x6BA4AA75297027B1ULL, 0x0192604B718455B8ULL
        },
        {
            0x83057B189B2EA5B1ULL, 0xA399FAF07110191EULL, 0x3BF7A92AA987E85DULL, 0xCE284CA4FF05003BULL, 
            0x6C006B99BDA71CE5ULL, 0x39BC5CE1E4DE5497ULL, 0x14395599FAAD09ADULL, 0x1C9B9B6F408448DDULL, 
            0xD3EA89B35F3FE2D1ULL, 0x24C77071656CDB3FULL, 0x693767B54560D9BBULL, 0xA7032566FE82A146ULL, 
            0x3986682C7A1312F5ULL, 0x60A6B8915F018D9FULL, 0xE4212D26EBDD3753ULL, 0xD413B83282EB29BDULL, 
            0x3735FD045E39C4E3ULL, 0x6CF7962654978EC3ULL, 0xAF176384E8CFB834ULL, 0xCF7EBBDB78A1E156ULL, 
            0x865E19CD256A6E59ULL, 0x16A238B415A07E97ULL, 0xC4B1C7FF37A4FB17ULL, 0x5CECC6EE082765DFULL, 
            0x45CF2749BF0C3689ULL, 0x1DF2925132C105E2ULL, 0x72465CFC6D9637C8ULL, 0xC634FAA0AE1573E3ULL, 
            0x985E90D63396A647ULL, 0xDD6BFF8AA1ECD2DAULL, 0xCDEBE92B1C5FD27BULL, 0xF71F2EB76573B581ULL
        }
    },
    {
        {
            0x73773A6048922E99ULL, 0x94CF06AEB4B9EFD4ULL, 0xB58E20AF84DC72DDULL, 0xCDD1AD6A0C2B9056ULL, 
            0x482D306CA0CC5A77ULL, 0xB709FAEDBA2B56F5ULL, 0x0D3E2B330D9F84C2ULL, 0x57F8B0CA94252E1BULL, 
            0x74C7AE8A33BE0837ULL, 0xD88899EC9D4706ADULL, 0x90B10F5FE59F7ACEULL, 0x9D012F4FC601C13DULL, 
            0xE269905A3E6A00B3ULL, 0x93F0F9E89B8E40C2ULL, 0x810832CD687139D5ULL, 0x69A36FD3DA78A3A6ULL, 
            0xD5FCEEAFB4178E3AULL, 0x08EBBCEE83850DC8ULL, 0xA582F8C6218BACE3ULL, 0x2EB686C200D28C89ULL, 
            0xE9831CF31BE57071ULL, 0x0617741E25C7B60BULL, 0x05730D7BF41BDF65ULL, 0x3CC5E5DC2F5FB88EULL, 
            0x9C5847BC2FC67FFBULL, 0x25175D89F30EF697ULL, 0x2189080A8DEFCE91ULL, 0xF5409B8FA99AB9D0ULL, 
            0x626AD595A1A7224AULL, 0xC9A222A863BB04AFULL, 0xB3DEC5CCE789C321ULL, 0xE4E44E56C8228F61ULL
        },
        {
            0xE5CB0016748EBA91ULL, 0x1E290F793D3FB69FULL, 0xCF85FCCA5B358236ULL, 0x3D51DCE30A21A9DBULL, 
            0xB8FB47716483630BULL, 0xAE73AC1E11A3423EULL, 0xB87720F5487192D0ULL, 0xBCB77EE850CB0821ULL, 
            0xD39293302DD4F03EULL, 0x7AB199612ECE5E06ULL, 0x7C1EEA4224A82A4EULL, 0x4F36AEF4D58ED8F3ULL, 
            0xA53A51BB0E46B829ULL, 0x85B9E076AC61D908ULL, 0xD34CCA6313635C53ULL, 0xAD901E718CF53211ULL, 
            0x0E0D571D3E6A43B9ULL, 0xC02ED9059A829AB4ULL, 0x25032F26D54E9BAAULL, 0x293E2359B96013C3ULL, 
            0xCB939EB3A36098F1ULL, 0x4C6A0F962B2420A7ULL, 0x45C2D612C58852E8ULL, 0x83D7EC3B18D0EE51ULL, 
            0x6019DF6AC8DA01E8ULL, 0x30DC06007CC86C77ULL, 0x92956BCF3F072242ULL, 0xEC4D396BF7ABA62FULL, 
            0x8C821484313BB711ULL, 0xF3C89203DC01BF7DULL, 0x1E880B4B4241E1E4ULL, 0xD7BD49743D37A40BULL
        },
        {
            0xD161A4EE68550F92ULL, 0x79C3257051A45CFAULL, 0xA32FC3EEFCF7F5AFULL, 0xD0212C729415BFB2ULL, 
            0x9D0523AFE6DDCFE0ULL, 0x250787BACEEFA964ULL, 0x30F7906D77A1A1F6ULL, 0x7CD2B216626A4FEFULL, 
            0xFF78D9E1D89FEF41ULL, 0x5E0214EBB4ADB7D2ULL, 0xEE25965ECF3805C7ULL, 0x6BE0C38B1368B250ULL, 
            0x6144F71BEF0413FFULL, 0x200A3A5F963BB0EDULL, 0xAB42A4BD4FC61286ULL, 0x6754398F98023607ULL, 
            0xEEDD94473F85BA26ULL, 0xABD614FDA5E8838CULL, 0xAEC8FDFF049169DFULL, 0x032042F0E769DE89ULL, 
            0x9009B82E2CDB6D61ULL, 0x95805476D3621616ULL, 0xA8DB23B7B36BF791ULL, 0x2F37263AA434C301ULL, 
            0x82AADBC1FC91A26DULL, 0xE343D50754CE1011ULL, 0xBCABE45F1E3A39B4ULL, 0xD798655F2743A11EULL, 
            0xC7F6E247787780DAULL, 0xD7A97A894CC574DDULL, 0x794787E08F8E668CULL, 0x1CF77DCACF5AABB8ULL
        },
        {
            0xECCA48B5E9448F9CULL, 0x5F063FAA2B408953ULL, 0x4F1611228C263719ULL, 0x5305493AEF0F1CBEULL, 
            0xC566F84E8DCEE46BULL, 0x50B58BC7E7DF087EULL, 0xF8F498EBDA978512ULL, 0xAE866D483061E424ULL, 
            0xF641BB82CEEE778AULL, 0x38A76D015B841121ULL, 0x935AFB7530012036ULL, 0x399E53815714D231ULL, 
            0xA6FB296676D7EE93ULL, 0xDDF7CF1E472F9637ULL, 0x7F9810FB7FBF8B9AULL, 0xA8A06FE3D93E1C02ULL, 
            0x518D5FB91B054365ULL, 0xD3691B9DFF1B3EFDULL, 0x569FC66C1694E7C2ULL, 0x4FFBEC35D3A77D18ULL, 
            0x7070C33856806999ULL, 0x2E16A29CA12A8FDCULL, 0x43E8E29FD4B74FADULL, 0xE534D0B9CB8F2762ULL, 
            0xD861485589E9B1C1ULL, 0x8FA40AA8362A05A8ULL, 0x73E30B46D623BC29ULL, 0xBCD5BAD18B3C8B01ULL, 
            0x127D69CE92935BF2ULL, 0x9F3C87C7D43D630CULL, 0x163844271D32D453ULL, 0xC8F78C28F44837EBULL
        },
        {
            0x64C434974D4DA701ULL, 0x46D8968027E4981EULL, 0xC03322601AC78B7CULL, 0x206E2E3384AA74DEULL, 
            0x093E1583E9E27FC8ULL, 0xF1A03B279AE61F8CULL, 0xD80FDE9EF7365649ULL, 0xD3BA0377F940EB9DULL, 
            0x6CDD2E3B50D45474ULL, 0xAB10BC55ED835146ULL, 0xA91B2DFCBDC8FDC7ULL, 0x917BAF1BDA627546ULL, 
            0x3B4969CB5938FE2EULL, 0x541632B12D717E70ULL, 0xE01A917068C4AB63ULL, 0x1D2B20D41279EBECULL, 
            0x91F06A669CAD6450ULL, 0x8C510521CC2E50EBULL, 0xF81E3C4FF78FCB3BULL, 0x8B9E96C1ADB8E8CEULL, 
            0x27C4F7BE919ABC7DULL, 0x53A2B2EF705E1662ULL, 0x673F3C1D9B7B4ACCULL, 0x70C75FEDCD93110AULL, 
            0x67952B2B4DDF76AEULL, 0x5322A8986E92C7A2ULL, 0xDF4BECE1EDA9CB92ULL, 0xCC370C6255105ADAULL, 
            0xE25F9CC8953DE0B0ULL, 0x08F6A296344D2B13ULL, 0x1F708ABDA232A5D3ULL, 0x12AEA5D78B95CC50ULL
        },
        {
            0x41E9B7BE36EF3F1AULL, 0x2B0B7B5850D42CF3ULL, 0xBC9DFC6CAB81CF9FULL, 0xC10FE9EB3D0E329DULL, 
            0x6587E71535B673F4ULL, 0xCD93602BDB562591ULL, 0x04EE76508B627DB0ULL, 0x98D7B6CD0A63604BULL, 
            0x11855A6447F06F8AULL, 0xA5466B693559BE1CULL, 0xF9B1F68B1552161AULL, 0x27ABB2F6FDE4E476ULL, 
            0x92A085D0A447D45AULL, 0xED3115D9C7E216F3ULL, 0x220235B12812790EULL, 0x4E2110586C008CADULL, 
            0x4F7CAC1D248C1C48ULL, 0x280C73A3CD3DB2A8ULL, 0xF362AE598792D74EULL, 0x325B894E4025E96CULL, 
            0x67CCBF9862E02806ULL, 0xA79D51679C04BD19ULL, 0x3EEC15D921DEBC15ULL, 0xDF8C868EBCB6C939ULL, 
            0x4D614517ED41225CULL, 0x3F77C4D8C17804BFULL, 0x4658BF2ACED47BE2ULL, 0xC25B92018E8B8528ULL, 
            0xB3232B7760CA0BAFULL, 0xCD040F76A21AC807ULL, 0x83AE5398B36B5F95ULL, 0x2C9B041FF563218FULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseFConstants = {
    0x1EE06FECDB43849AULL,
    0x86710DD6EE96EFB9ULL,
    0x42EDBBE1A287BDA3ULL,
    0x1EE06FECDB43849AULL,
    0x86710DD6EE96EFB9ULL,
    0x42EDBBE1A287BDA3ULL,
    0x52A768864984EA7FULL,
    0x7CF3EB8BC1BC32FAULL,
    0xAD,
    0x76,
    0xE1,
    0x7D,
    0x6F,
    0xB7,
    0x65,
    0x46
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseGSalts = {
    {
        {
            0xC2FF67D1FC77ADF0ULL, 0x1554443E7F6FC046ULL, 0x6E1489AF2688FE0CULL, 0xBC5B3DF207F598D7ULL, 
            0x70F14730C7494894ULL, 0xA86C94BDE90720CAULL, 0x2369F075EAC1749AULL, 0xFAA8B44047BEE94CULL, 
            0x4A5AA8F3184D5F5FULL, 0x586B930A38567367ULL, 0x95C0E2D250B9E7B9ULL, 0x02E8FE5A2806873FULL, 
            0xA3DBA205C6C52765ULL, 0x198F5AA552FBB85AULL, 0xDECCFE4B17830251ULL, 0x6263E4D15ADF3FA8ULL, 
            0x25A3D4EC8933A059ULL, 0x00104351EABF147CULL, 0xF3FA5DA55449923FULL, 0x38AB875F5DBFDDB1ULL, 
            0x80D5052E9FACB29FULL, 0x5EAEB5FD8D3AF1EFULL, 0x2495CD37EB00D85AULL, 0x6CDEB337F7848E7CULL, 
            0xD9319C262E1E3B0CULL, 0x4A0495D8C90F8C7BULL, 0x99FDA3CD8EEEC9E8ULL, 0x8D57760B45D44D92ULL, 
            0x9078481618DC1663ULL, 0xDF14D507FE5CFA4EULL, 0x076626F689ACE995ULL, 0xF25F365810754257ULL
        },
        {
            0x41A72F0735CD5EE4ULL, 0xD09C18DC58BA4653ULL, 0xCBA770010B3121E7ULL, 0xBE067B5AC130F9C2ULL, 
            0x49FB15B6B605BB49ULL, 0x1F044260CC4901C9ULL, 0x5EFC224B93A026E5ULL, 0x189DAEF2A3FA9803ULL, 
            0x86DBF0A17B3329C4ULL, 0xB58BE6841AE1E0AFULL, 0x3A3D4C2B6634E019ULL, 0x14411AC814063844ULL, 
            0x86F1B788CE77CB19ULL, 0x132AC8779D9479C7ULL, 0xC61855F536293EC3ULL, 0xDC1A4203C87458D4ULL, 
            0xBD8B4C707034DBCAULL, 0x04ACB85775ECD203ULL, 0xF65B5A113CE13905ULL, 0x268AF1703F4CA8EBULL, 
            0xD73B3AB51F146E10ULL, 0x432968471017A50DULL, 0x937D87148DCC76D3ULL, 0xE95820D043F98D29ULL, 
            0x9E5CC79A5FAF3066ULL, 0x9480EF0DA1570C67ULL, 0x4F48022EF9C11D6CULL, 0x71AC1C62C7AECFB6ULL, 
            0xDF5356F508FDF08DULL, 0xB5BB36461738D9E3ULL, 0xA7640C0124DDC5DDULL, 0xC1C22FDD8C3B1E80ULL
        },
        {
            0xE15A98A9A34BE6FBULL, 0x40B3072E5BFE33D3ULL, 0x625F8BF2F418685FULL, 0xC04B7ADD013016DAULL, 
            0xD4C05394C982CE7BULL, 0xC6B6A2F4EAE0D5FAULL, 0x08BB9D5A5719EFB5ULL, 0x10DA9EC9005F45B2ULL, 
            0x1E57F8CBEF343F98ULL, 0xB25F8A4042B7B7A3ULL, 0x0AC070CF61814C36ULL, 0x3E25455575BAF51EULL, 
            0xFB7515F8A57C596BULL, 0x465098F2DD63FABBULL, 0xC1FCED62F1ECC0A5ULL, 0xAC56F988B1991DBFULL, 
            0xB83DEC2ED793FCBEULL, 0x730F630454808476ULL, 0x8CCB43D3EA62CEE5ULL, 0x7AB7220A085841F9ULL, 
            0x5037676D10164CDEULL, 0xB8D81AE725D7039BULL, 0xE7CE1EB022BC49CCULL, 0xA1F0949ACABE3BCAULL, 
            0xE59CEDA445DDD209ULL, 0x7C752F3DFB5FECB6ULL, 0x0207A5260D8516BCULL, 0x5F94837A5AF95615ULL, 
            0xF40DC1DFD80ED562ULL, 0x6FFFDA522A8A72B3ULL, 0x17E0564D1409760CULL, 0xF8B8B8B73182CD46ULL
        },
        {
            0x5AB1295DFB67DE70ULL, 0x95B3B5385895BDF6ULL, 0xE1D505269F87C7E0ULL, 0x6F7FF81F27649A60ULL, 
            0xDE9D3A962BB12BF3ULL, 0x8B8B91AAC7EEABAAULL, 0x51259EB03C5DFAA1ULL, 0x1374E650C1304861ULL, 
            0xEFEB46A773E98894ULL, 0x9BCAEE54F99F3D61ULL, 0xD9DF787BE5A8BBA8ULL, 0x7D29CD0F3C3B5903ULL, 
            0x8918E4A42D6AB24DULL, 0xE6EC77A4098DBC91ULL, 0xD5AC9F33E24CB7F3ULL, 0xA17F83303F2E1C11ULL, 
            0xD1712430F4F838F9ULL, 0x30922FCEEBADBD28ULL, 0xFC25BBCB6C5E46DEULL, 0xC18F3D4A42A4EAECULL, 
            0x6858C55E07415472ULL, 0x3DDF471D0778C5FBULL, 0x95EB6329AFDC378CULL, 0x7C93351949A4A7EEULL, 
            0x554570D92D3C8376ULL, 0xCD153D4EC66153B6ULL, 0x27637FBF0AAF0FD7ULL, 0x1DFE71A448E90483ULL, 
            0x5979E4F193D8686AULL, 0x5B8A250941CF59F6ULL, 0x57C24D7BE5A718B2ULL, 0x39AF92156C2891C9ULL
        },
        {
            0xCAC1C1535B28E63CULL, 0x6F1C2F57AB15A76AULL, 0x3CE5F33D9BD0BC24ULL, 0x6C33E71252D960B9ULL, 
            0xE75F220F23DFF4F2ULL, 0xBF0060DBD975134FULL, 0xE71501D91FBFE358ULL, 0xE50C9736E3783AB6ULL, 
            0x64F436E8A2D2619FULL, 0x00687A465970EA17ULL, 0xFAF6A5F390FE47B7ULL, 0x19D62DA498558241ULL, 
            0x739C1D063CEEEC1AULL, 0x09D94141040D8DC6ULL, 0xC147B77959D172C7ULL, 0x2008C385D3AC619AULL, 
            0xA68D227A1B9756D1ULL, 0x2630711232B06CA3ULL, 0x6EF16F9F885496B1ULL, 0x44EA575DD5702174ULL, 
            0xEB9EBDE90DF228B0ULL, 0x2593647486041966ULL, 0x7AA1453C872B5E82ULL, 0x1154FE66E36CD4DCULL, 
            0x2DFD15B8CC401AECULL, 0xF8178441C5AABB1FULL, 0xBDD6D83B8223374CULL, 0x0D3476BC100C4C34ULL, 
            0xD05BDB9417A2E0E2ULL, 0x4B768F038D3A87FFULL, 0x60CE5BCEE3A99B04ULL, 0xE98567D343DE20CFULL
        },
        {
            0x7B74DDC31BDE7E81ULL, 0x33BF1642B393255CULL, 0xFD63EF8FAE224888ULL, 0x40C08E5B0CC03377ULL, 
            0x89D94DD254EB7939ULL, 0xCA349881AB226E64ULL, 0xEA82FBFCD2524362ULL, 0x59BA83767762DF76ULL, 
            0xC59E9479E99FD465ULL, 0xEED11E7D0FF6427BULL, 0xD1FFC187CA71B438ULL, 0x11EDA768390EEF19ULL, 
            0x923214D62EB4CF4DULL, 0xCA3D94835B61894CULL, 0xE14472A1F961449CULL, 0xF7EC06BE164DFDB0ULL, 
            0x02E1CAE7D8573D92ULL, 0xEEE03EA1458B51D7ULL, 0x11411B0D2268FCB0ULL, 0x12E8167FD49DAA7AULL, 
            0x539E3D60B1F2702EULL, 0xB306BA767FCD5672ULL, 0x43B4F583821EC4DDULL, 0x9D401716A80CC02CULL, 
            0x9FF19487965A2B98ULL, 0xE8EE41196F63E31CULL, 0x8200F251DA2AA5A4ULL, 0xF0B41F54C9A59CEDULL, 
            0xFCE3CE07DD0AEE1FULL, 0xBB0A894051C7C623ULL, 0x11DB2DAEA6BE182CULL, 0xF9E96EE6B5B2E00DULL
        }
    },
    {
        {
            0x1B0F64D0C26E780AULL, 0x82B633479153046BULL, 0x25EEB63F1CCF77F8ULL, 0xED39A7BF855F57FAULL, 
            0x78586939361F8089ULL, 0x40D9F429BEA1CEBDULL, 0x7BE4F2D3B35630E6ULL, 0x718EAA6054A6CD3CULL, 
            0x3C70B8F462BA888CULL, 0xBCD4F09DF779D38EULL, 0x09A62C2DE9B15F81ULL, 0x5F48E75D782BD11FULL, 
            0xFFB62F0BDAE8986BULL, 0x15DDC0DB36B10CA9ULL, 0xD60A5D2349BB1813ULL, 0x0E2516ED5B68CE54ULL, 
            0x216EE5E715F1DB34ULL, 0xB0AB10A629F9093BULL, 0x64E1B9F429984065ULL, 0x115C5F2C2D631580ULL, 
            0x2B6329F76AF59BD0ULL, 0x3DB95B56CF15F6A0ULL, 0xB7B8BEA4B0B06C05ULL, 0xBB2CA2E8F70BB811ULL, 
            0x012403A0FBA795C1ULL, 0xE233D5DACF17ED9BULL, 0xC4F2CBB435D75765ULL, 0x6A74E570AB0E35F2ULL, 
            0xD1700FF1F5F22009ULL, 0xCE963A0C79300F77ULL, 0x01CA7D8773DB0963ULL, 0xE081A01CFFCB41AAULL
        },
        {
            0x6533DB1DFB7B6767ULL, 0x9FF483BC3EA54D42ULL, 0x444CA9BFC47FF5D9ULL, 0x49FCC0914BAE57D2ULL, 
            0xEA86C3704E127E6EULL, 0x486A43AD777418CEULL, 0xB5E33105BF880508ULL, 0x47EAD838B0315E31ULL, 
            0x6FE29896DEA8A55EULL, 0xA32CE2E8BE523E3BULL, 0x08AF8EDDD7B19171ULL, 0x1B71233DE4E6DDF7ULL, 
            0xD0EE9BEEFDE79CF3ULL, 0x1C99025A068DC270ULL, 0x4CA94DAD6E1CD982ULL, 0xE24748A0B6B83672ULL, 
            0xFC6B1AA974B463ABULL, 0xB70F03F21552A585ULL, 0x95455D188BE2E6F5ULL, 0xA21DFCDDBF9DF0F9ULL, 
            0x40C76C81247C8EF0ULL, 0xAB293DB2F8EA5A01ULL, 0xB02D4740117FE3BEULL, 0xBE814B1D6F5751EAULL, 
            0x6E12565B9B9CBC02ULL, 0x5378F19374C54007ULL, 0xDED1DD8E0953D5C6ULL, 0x48E425A48B6555DEULL, 
            0x52488CDC89AAC92AULL, 0x75705A9D77604041ULL, 0xDCEC0DC867CA1824ULL, 0xA70D30FE48169E9CULL
        },
        {
            0x38CAF912D317ABCCULL, 0xFE7F2EC412DFC20DULL, 0x34C178EC3BEEFF7BULL, 0x51872EC61042602DULL, 
            0x39E76145B51719C7ULL, 0x304582A4E488841FULL, 0xE39D1CBDF7E03E89ULL, 0x6EBE110A0D14A77EULL, 
            0x45B6621EB448BC67ULL, 0x9BF7C880D96EEDD7ULL, 0x65E581CEEDC1964DULL, 0x9B0BF3FECB218E10ULL, 
            0x7931DB2445AFB9ADULL, 0x08C6F68325764ED3ULL, 0x57104B9CC4449349ULL, 0x40BCB103DC3D2C95ULL, 
            0xE46FB5041C61F3F9ULL, 0xE03C5AD9F6423261ULL, 0x03CE9A1FF88E438CULL, 0x2B7333A309D44DD2ULL, 
            0x5645F31790190AA8ULL, 0x470AD9CCA7126189ULL, 0xFA358D603C0C0357ULL, 0xAA1D5BF927720755ULL, 
            0xC0F62C1823FC35F1ULL, 0x42EA1C36E8A7EAADULL, 0xE80D105C16BE8036ULL, 0xDB51E621EEED1701ULL, 
            0xCE567A34824CC747ULL, 0x56FB2B9F127C0360ULL, 0x616C8EDC4C4666D5ULL, 0x35644D26E7C5BA45ULL
        },
        {
            0x6A10FCA9EFDE9475ULL, 0x452C602B84A4BA7CULL, 0x85374A81BA768A20ULL, 0xEF9864D52F6D43A4ULL, 
            0x73C2F47F670CA364ULL, 0x3037B473BE50598EULL, 0x428A4D9EDCB42740ULL, 0xBB2EF9B601C1D75FULL, 
            0xB4C8C94B59C67E01ULL, 0xF07F1E416F27CF68ULL, 0xFFD1CD8845C60493ULL, 0x5ADF7A735F421900ULL, 
            0xA05EC505F25F7F1CULL, 0x9D16157B74358EF8ULL, 0x15E95861280EC41EULL, 0x9950C8B92DF4BD81ULL, 
            0x16E0000031CC0FF4ULL, 0x8791C69AAE07B2F5ULL, 0x412C8BC56CA60220ULL, 0x6FEB4BED20F2E8BAULL, 
            0x0AF9E0D4CCF61E0AULL, 0x31396FA7EF8C201AULL, 0x8D4C602CB961FE1CULL, 0x1022DE661560FDE6ULL, 
            0x2E5A1E87A6520A63ULL, 0x06E45EE05717DC45ULL, 0x2D5D68CD45EAA942ULL, 0x9FFFE27740BEE219ULL, 
            0x4A40BB9F0B4B2FD9ULL, 0x86A3D24B8B876D0CULL, 0xA36A02DBC33D02DAULL, 0x591E44E4E8DB8C1EULL
        },
        {
            0xF0144F883004A917ULL, 0xEDA947AF306AD90BULL, 0x6A8239ED9891B816ULL, 0xAC900C9E93B62280ULL, 
            0xD57025DCB0769B47ULL, 0x9B0A78E610693EE2ULL, 0x23543FBF210281C2ULL, 0x59B332A65455D975ULL, 
            0xD676036756D3D07AULL, 0x523ACD7B7A4FE693ULL, 0x393150E1AF032C80ULL, 0xD3ADEACA96AEA5BBULL, 
            0x98753EDEB16990B6ULL, 0x544B02319806D4D6ULL, 0xAE59CB9839A7DF17ULL, 0x1BCA024CB59E5DE8ULL, 
            0x1F0B9C491E022F16ULL, 0xC5C90CF8A37C18AEULL, 0x632CB8288FF73440ULL, 0x002E4F7EC805D560ULL, 
            0x802FDB10E2738D3DULL, 0xCAA4571BF70F2A85ULL, 0x0CDBCAB77E902EF2ULL, 0x22B6069B1563F709ULL, 
            0xF839A95F87894338ULL, 0x26F7821253CAA6CAULL, 0xFC0741E1D1E47A94ULL, 0xEA26B96D2DD0F13CULL, 
            0xDB67A44EAC960604ULL, 0x72A9C39AABA415DBULL, 0x24748D0DA18443EDULL, 0x9D3D47CAA8BCF8FBULL
        },
        {
            0x9CE3C7A1E8F37843ULL, 0x7E67BA0BD1DB3E5AULL, 0x8B987788467E547BULL, 0x3200E09720CC6556ULL, 
            0x3DF1A1C00E762A24ULL, 0xD9FD46C554C4FA11ULL, 0xDA9FA8C374851E21ULL, 0xA1073BFCDAD09147ULL, 
            0x61825DB4288F6A76ULL, 0x5A3414F3C632BEF2ULL, 0x929FAD52C2510239ULL, 0xF35BE333AC95C23FULL, 
            0x955C1812E5EDE69EULL, 0xC1739D916D1CDC3AULL, 0x1E379A9022A684D0ULL, 0x1371F45A2321F139ULL, 
            0x70C0328F2767FB15ULL, 0xC4A6601398B08AC0ULL, 0x6CE2F38B10876898ULL, 0xE24ED6E5A82BBB50ULL, 
            0x3FB44F6BB3DECC74ULL, 0xB6393E5695E1CAC9ULL, 0xB909317FE751CAD7ULL, 0xC0132DE8F9F88904ULL, 
            0x33E12BD15EE5A270ULL, 0x996B07600A651565ULL, 0x06E802B3BC2B03FCULL, 0xF360D4C8A01F30C5ULL, 
            0x85674B0969770EE3ULL, 0xEF8BCDA1C389F518ULL, 0xBD7BDBFCEBF9EAFFULL, 0x90FA125B95AC375CULL
        }
    },
    {
        {
            0xD5DFA2D2140D86ACULL, 0xF76FAE017C6DF3D3ULL, 0x8E15134B35044F0EULL, 0xFD67EC7732FEFD54ULL, 
            0x0B7E6B640A1B67E5ULL, 0xEDE14BC08F5F2FB5ULL, 0xC34BF5F1F1F7D07CULL, 0xF61CCD90D68A0B4DULL, 
            0x603779DB7DCC0385ULL, 0xE2D271A741EE8E83ULL, 0xD468C6A67FC2FC29ULL, 0x5E06C4514865948FULL, 
            0x6765C938F4861EBCULL, 0xC7E68A53F1F796CEULL, 0x081F626D1958E575ULL, 0x61C6595CFB1E3FB5ULL, 
            0x60C4602ABAC010D8ULL, 0x77BD824D7B969EA9ULL, 0x06AE61596AA16E10ULL, 0xC39AF019CEAC6CEAULL, 
            0x96943FB5A12EED31ULL, 0x239A362460CC7190ULL, 0xBE2FB12463C969B6ULL, 0xBADD0D7753AD8D97ULL, 
            0xBA4001BA758CFC72ULL, 0xAAD04C1830B7195CULL, 0x4DCC84434F5D5ABEULL, 0x520727F36A7F20FCULL, 
            0x3CBB70D615A70AA3ULL, 0xF3933680707272F4ULL, 0x491D0CBDAD40F2FAULL, 0x938198D00B705C16ULL
        },
        {
            0x44A514770282CDB9ULL, 0x0A38A5462D80F74FULL, 0x1267119368331D3EULL, 0x6AB0BA966A25EF75ULL, 
            0x3D2EDB18010A6071ULL, 0x92807D48124F4EEBULL, 0x4F3A722EAD0596DEULL, 0x46E7C37E2180FF99ULL, 
            0x9AD0929790B9AC36ULL, 0x80EC00AADDF7E0C2ULL, 0x18FDD33270FC95ACULL, 0xAB7AC1B74F55ADA3ULL, 
            0xE635DAD0BDFD4590ULL, 0x31C98DB94DF083D9ULL, 0x9DA4006A142A1C6DULL, 0xB184040642B99EBCULL, 
            0x7F0A84CFDA69DF33ULL, 0x362FB02375FF8213ULL, 0xE424E5AB66E36056ULL, 0x1012CB2839500D80ULL, 
            0x5C139CDBF6C1585AULL, 0xC572797C7CF7518EULL, 0x00884640515FEE84ULL, 0xD468993EC2B8ACFCULL, 
            0x55839504CE12DE25ULL, 0x2A2C1B8B51177C5AULL, 0x48D0664A970DD033ULL, 0x1EB2CE2FD7227D8DULL, 
            0x36511FAA474F9088ULL, 0x96B1FA39ACB2AE3BULL, 0x760304D2DFA48D43ULL, 0x4A03ABDCDEDC0976ULL
        },
        {
            0xD65D0DF0FFE1807DULL, 0x1C43506D409EBE3FULL, 0x82C81C9FEB02DAC0ULL, 0x8127DA9EE195547CULL, 
            0x3338EFF0D4BD4D86ULL, 0xE3549B6649954EA6ULL, 0xC33D1A19C05F28A7ULL, 0xC31A1292216C5773ULL, 
            0x66A8C019BFBE0910ULL, 0xB222FDCA45563E23ULL, 0x6D7DB15A55E340CCULL, 0x423DE0B7731CDB4DULL, 
            0x5112A383AC1A9769ULL, 0x9045E41720DAE770ULL, 0xC31447D89346B665ULL, 0x808450BA1964E8D1ULL, 
            0x0E2C603FA848B686ULL, 0x65D850F1A4F0C9E7ULL, 0x2AFF64ACB4C6DBD6ULL, 0x2C62A2D8DDD375AFULL, 
            0xE47D939065B7FE68ULL, 0xAD3E450630520A0BULL, 0x34A6DA60A7377EABULL, 0x3B6D1C1E374C8778ULL, 
            0xD34F86C518AB3CC5ULL, 0xEC065A3DA587249CULL, 0x00CD1D82D518BDCAULL, 0x509E19AC6F33A600ULL, 
            0x83809601667EE4E7ULL, 0x4CAC3EAB2A789385ULL, 0x03A43D64537E97BDULL, 0xC5080281CFC9BC55ULL
        },
        {
            0xF6B73B2F0C0B206AULL, 0xDD7A37FAE8389D0FULL, 0x4706C9F245696804ULL, 0x5DF3D4B629C7CF11ULL, 
            0xE21E6970DAB6DB10ULL, 0x690380024BF5DC45ULL, 0x7C155BC01D454690ULL, 0x9F9B22EACA801C10ULL, 
            0x4D5CCC3FB0F12AF5ULL, 0x5DA0C125821B8529ULL, 0x9A08C6A91D44C21EULL, 0x946DDAB871BEF28CULL, 
            0x60315F2F5D45B878ULL, 0x44566DCF6AAFA89CULL, 0xBC5D97E85FB732B3ULL, 0x085AB8EF629B601AULL, 
            0xB93AEEDB1B2FB900ULL, 0xAF90CD6862E262A4ULL, 0xFF73359619DAC07BULL, 0xF4B576F63CD80977ULL, 
            0x2E9C1C1E24B0DF8CULL, 0x3135669C5BDF238AULL, 0x591ED6E8B033F9C5ULL, 0x051D18F44D6E0E6FULL, 
            0xCB3DF9CBE3CA1F12ULL, 0xF1F0A7B6485847BDULL, 0xFFD1B5A4A4E99BE7ULL, 0x5F5D9C50A7890005ULL, 
            0xB389C8C5235C14AFULL, 0x96DE0D6857FC8C18ULL, 0xDF3A1F513632BE89ULL, 0x7806173E3E8568C6ULL
        },
        {
            0x0971EFEBA9AE1858ULL, 0xED3EFE80A272E749ULL, 0xC3D16D28BD532C4DULL, 0x9C58C8ABB69648BAULL, 
            0xA81886CCFCF71D75ULL, 0xB186CCACCBDF3A12ULL, 0x3E93C53AFFE9526CULL, 0x976B597CE1249ED8ULL, 
            0x5DAD3C8EEA4CA097ULL, 0x34DBA05BEE0E314AULL, 0xD9158BB970750321ULL, 0xB622188EF975B383ULL, 
            0xC3F17FDCF64FD024ULL, 0x5F7146226B3F21B0ULL, 0xCA6C7E8F12B0798DULL, 0x27FBD50BDC16803EULL, 
            0xC7EFC8EC20D95580ULL, 0x0F3EBA607D75646CULL, 0x74EF6D83DB4D2892ULL, 0x23DE03D8D5444D17ULL, 
            0x716E69ED09993A65ULL, 0x7CA58176CD180D1AULL, 0xCD1A66EBEF4D0344ULL, 0x01720155A02EDAEEULL, 
            0xEF128BFECF7A9CC1ULL, 0x386FFAE3CB5D4D54ULL, 0xC163206042419C9FULL, 0xC9108129C34A09C5ULL, 
            0x0C79014A966A1353ULL, 0x33F16F83EBF333D0ULL, 0xCB8BBB9FE73B9DC0ULL, 0xB12DA86DC2CC6E79ULL
        },
        {
            0x02289B21EC980DA9ULL, 0xD315D0A150819B42ULL, 0xB433C12D82FC6525ULL, 0x8A2BB037691AE0FBULL, 
            0x5C9AB1AA6B6A0D4AULL, 0xFE1B5B356DCFD808ULL, 0x0BA3A1C257A12B84ULL, 0xE6059B767ECCC3A9ULL, 
            0x4FDF42B86F4AFB0FULL, 0x5787C22DDC7194A9ULL, 0x66820506D2360887ULL, 0x2C26CB73D90F5C6AULL, 
            0x5B0F1CB45D74C281ULL, 0x5F2D0D65EC695738ULL, 0xD48ED7D9BFEED759ULL, 0x1AB1392F4BBE6373ULL, 
            0x91AEBA48CD9E5D69ULL, 0x93BF5E28275B833BULL, 0x53901B9E324C2923ULL, 0xFC763E71F36FBFE7ULL, 
            0xC587CEB34D64D2A7ULL, 0xE5B1EC506005D27FULL, 0xD39277EABD05A038ULL, 0x0CA9A36F03B594CEULL, 
            0x468DFA00271A9D60ULL, 0x55E7B520352FFAD2ULL, 0x6D231588557F66ECULL, 0x5A1DF0CD8A193952ULL, 
            0x4B736438B264FF74ULL, 0xBFCC438064702064ULL, 0xE1681D0E5F9B93C7ULL, 0x392D4978A0646334ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseGConstants = {
    0x44E2D3399D18F043ULL,
    0x70D35A1E576F80D0ULL,
    0x9B3453CAD96D31DEULL,
    0x44E2D3399D18F043ULL,
    0x70D35A1E576F80D0ULL,
    0x9B3453CAD96D31DEULL,
    0x9B36A6A5F6B0F9A0ULL,
    0x01922C223F38E825ULL,
    0xBF,
    0x79,
    0x85,
    0x32,
    0xCA,
    0x70,
    0x9C,
    0xA6
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseHSalts = {
    {
        {
            0x304EC265A2DC4806ULL, 0x23D0B5C498F6A39BULL, 0x7469C46F235F14CFULL, 0x6C6305CD27411D68ULL, 
            0xA5BE392C84CD1DA8ULL, 0x34AC9DF41DFC8986ULL, 0xB556485A2C449C62ULL, 0xE70121C7D69F5665ULL, 
            0xEA442C9C36282683ULL, 0x907543D91F6D999CULL, 0xEDAF9E06C3E5E8FDULL, 0x03B5B2C22582DD84ULL, 
            0x06D7B0BA58EC7152ULL, 0x02A6DAC241DE171EULL, 0x73EDE2ED74717028ULL, 0xAADCE7A612725C54ULL, 
            0x76167D061E551146ULL, 0x27CF68E4861C3919ULL, 0x53B93A3212298073ULL, 0x86886954B1EED146ULL, 
            0xBC02E0E8FEC9A4E2ULL, 0x5CEF392EBB5DC924ULL, 0x3638F4FBD5BE4938ULL, 0x782A15C93F8E50D0ULL, 
            0x031FEB48CD58D030ULL, 0x3A17C0F63F4E1DE6ULL, 0x2A804280BFB9F682ULL, 0xDCD3DDF91B51B981ULL, 
            0x9780C35540D0E09EULL, 0x831EE608F18FF524ULL, 0x9279E2E32149EC09ULL, 0x9E508F7367FE940FULL
        },
        {
            0x749C2C226D5618CEULL, 0xB26849CFD89347A4ULL, 0x36D803125BC23A8AULL, 0x37065FEE83FDB901ULL, 
            0x879D20F1272DD898ULL, 0x82B2FED7EA60C975ULL, 0x7BBA7CB741313EC5ULL, 0xEF6E87B1A17C7655ULL, 
            0x3982E2B4F0D1676DULL, 0xDA8A5B67B7250CE7ULL, 0x0556C0A3879AD9F6ULL, 0x3473E64EA0E79AD6ULL, 
            0x338BE1AA9435BE53ULL, 0x33A4F38919A21147ULL, 0x85C751EE0F1190A1ULL, 0xEC037A15E6B547FDULL, 
            0x26310E4DFE9B574DULL, 0x2153A541E9EB502FULL, 0x929D199D7AE0DED6ULL, 0x6E2BB773BD0927BEULL, 
            0x8B0B4C3EA3704853ULL, 0x4F771758191B118BULL, 0x38DE79ED85A2C5FEULL, 0x6D67BBC3CE652D80ULL, 
            0xFE5607E80939F7DBULL, 0x8FCFF6E8AD969460ULL, 0x02E7E047129B8643ULL, 0x52198BAF1D65E8E8ULL, 
            0x36EF7C6BFCE8A8CCULL, 0x265B2FE77F754A90ULL, 0x0A628491B9E4DA05ULL, 0x4F0C85ADC0E54D8FULL
        },
        {
            0x5A799DB63B6D3688ULL, 0x367608AE4685650BULL, 0x40D1BB6A313A7DD0ULL, 0xD5DE7F046D10476BULL, 
            0xC5FBD0AF5DCB0ADCULL, 0x7F14A6AAB621D40FULL, 0x62D38F030DF1756DULL, 0x342316C0C23AF9A5ULL, 
            0xE591A3A4B1B5577DULL, 0xF3B4C4B070213A78ULL, 0xD0B8FCBA2208869DULL, 0x036FFE09E0B377F7ULL, 
            0x06573460DC2131C0ULL, 0xEB575C64B4F0D834ULL, 0xA243A80C45136B84ULL, 0xC6AEF1FF360B4AE6ULL, 
            0x82E9D3408274709AULL, 0x4D41BEF9A0F586DBULL, 0x54EEBDE64A6BCF56ULL, 0x613E59B8341A3E4DULL, 
            0x9B5F39CB9E93B621ULL, 0xA66BD9E7F93C98A5ULL, 0xF6E16C06B4CD13B1ULL, 0xD9D2B80A1D5AFCCEULL, 
            0x310A58D558B607E7ULL, 0xEECCDFCEA8DE645AULL, 0x6B0110C35D9E484FULL, 0x5912F15F885C9FDCULL, 
            0x3AB475397CE589FDULL, 0xCA5D2E6CCB907B97ULL, 0x03831431937264C0ULL, 0x02AC743276302B40ULL
        },
        {
            0x6584E3F0A2F94A8AULL, 0x0CBC0E5EDC945132ULL, 0xEB97B8D98C9883BDULL, 0xDA4ABEBEEC4C934BULL, 
            0xEBFAD138FB564E94ULL, 0x3190F32D4739062CULL, 0x873A34E67BC93A92ULL, 0x1AE664C42324AD83ULL, 
            0x002163174C08D068ULL, 0x0FC204C7F73C43C5ULL, 0x69C2CB09C3C97446ULL, 0x515442E80E3260C8ULL, 
            0x583F067FC23FFE68ULL, 0x57CBD0BE9D402B58ULL, 0xEDA98027F5BCFF9FULL, 0xDCE0EB73AC10E7C1ULL, 
            0x66151A4791509529ULL, 0x9CADCF7E4E453937ULL, 0x5FE177C010843563ULL, 0x5E53C002876596B3ULL, 
            0x1CD31CB01CC3AF6BULL, 0x234091E1A8BA1560ULL, 0x197D2EE4E0E4DC70ULL, 0xDEACCBFF3ED4681EULL, 
            0x69225F97EEE40BAFULL, 0x19439CA2642A0996ULL, 0xC3FBD54334B82C07ULL, 0x9556C8E9552C85E9ULL, 
            0x3FEFD04AB53B1948ULL, 0x294EFA93E686A892ULL, 0x1A4093602198ED8EULL, 0x1ABCC7BE7B75D89DULL
        },
        {
            0xF6192EEF25C01FD5ULL, 0xBADE19475C4085C1ULL, 0x924883B2B6E583E5ULL, 0x905B1F6953B44348ULL, 
            0x9A8DACCFAD087791ULL, 0xE95B919C0067CB37ULL, 0x2B58BA6C7CD370E5ULL, 0xAC00987DFAC7BF85ULL, 
            0x71A34DFECF95988EULL, 0x61590D3C59AE23A4ULL, 0xF33B35AC27A6C4FDULL, 0x834F3112EBDD172FULL, 
            0x5BE2742BFF6D7B69ULL, 0x2DCB2F5317FD2EF5ULL, 0xD6A0EDEF99D7880CULL, 0x96BA2E54EF92C975ULL, 
            0x1E29BCAA347B3756ULL, 0x01BD100776E28BBBULL, 0xABE9562B38188102ULL, 0x6EFA1547F8F22202ULL, 
            0x4E8928730A18DAEAULL, 0xB7485AE829B35736ULL, 0x8912F51566343E9FULL, 0xD5BF5FB1132C83D6ULL, 
            0x5E2897E31151419BULL, 0x3CE9BC214E5AF421ULL, 0x50459FD1C75F092EULL, 0x35F98FC318D73FBDULL, 
            0x00AF1C19B13E19EFULL, 0x14553ED85970715DULL, 0xD4CDCE5CC3E1994BULL, 0x5C28101218F9738EULL
        },
        {
            0x6245BF3AD4B08F52ULL, 0x447EA13F9C90705EULL, 0xCCFDA2635C28D5E7ULL, 0x918A33364BA438F5ULL, 
            0xFDDE649EEDE1D578ULL, 0x0E1C29258BF4EC5DULL, 0x1AACC37DA7132E4FULL, 0xD44BAAEEAC7545F8ULL, 
            0x44E26261DDA178D8ULL, 0x27BFC99F579177AAULL, 0x5D854C5677F6176CULL, 0x0995AC90E5ED3F08ULL, 
            0x161E184C6215107BULL, 0x328C11E2A120A491ULL, 0x608C06483DEA109AULL, 0xC4C980A8C8EE030EULL, 
            0xB01106562CB7CCEDULL, 0xB97839682D2CD0FCULL, 0x65C6A1FBD6A29669ULL, 0x555B2AF4894105F9ULL, 
            0x3ACC44BE74FF0BB5ULL, 0xE5545801ECC692D0ULL, 0x100F2DF77133A551ULL, 0x6C51CC1B9CC034F0ULL, 
            0x7857902D309350F7ULL, 0x126C1E54C78F914FULL, 0xCAE4D07A8659508CULL, 0xF500ED5AD7F31599ULL, 
            0xBA0A12C7260DBFCBULL, 0xC5BBA3B00BDAAFAEULL, 0x470029F8A3803ABEULL, 0xA4030FF93021FAEDULL
        }
    },
    {
        {
            0xC0FF16300E52E747ULL, 0xBE8B4F8EC0F31EB7ULL, 0x811C216E030820BCULL, 0x1CFA33EE4050FB7CULL, 
            0x65937C7EBF06ED75ULL, 0x149E21CFB9DF1C7EULL, 0xF774D1A0A934103AULL, 0x785551F7C6A20839ULL, 
            0xE6CA6443DEF6123AULL, 0xEEE0DA28149FF43AULL, 0x5EB01EA080B23E4BULL, 0x42593B8DDC945AA4ULL, 
            0x70D15EC8B57CB112ULL, 0xAA25EDFBB0D6C032ULL, 0x1A846F973641A523ULL, 0x242DD904EE60D870ULL, 
            0x76EEC4A1ED8B76BBULL, 0x958750735AC48C8BULL, 0x47F8DE144FDAE4E6ULL, 0x2B77A9503AB8FE07ULL, 
            0x5A0032343019BFB4ULL, 0x5A380110DFA83156ULL, 0xAE9CF372E839D8FCULL, 0x51B4FE8B8FF940FCULL, 
            0x94671CC98D8CBE17ULL, 0x9E8C7DC91107AE00ULL, 0x708510FB40DCCAF6ULL, 0x10B5AC98A3E5FED8ULL, 
            0x36E08F33E6E73E8CULL, 0xEA53E117AA4DF252ULL, 0x9B28347403946A36ULL, 0x769467B620E43FECULL
        },
        {
            0x99B21AB16BB39D6AULL, 0x01E9365C8E76126EULL, 0x9300492A3B8D7F3FULL, 0xF2761B456B994640ULL, 
            0x9401F908A0E1BCAAULL, 0x04681B30FA657C2AULL, 0xC48C05D6B167F664ULL, 0x04FE426E67FED90AULL, 
            0xA8D5BD40213DE6DFULL, 0x4AEB5E6D1AA867B5ULL, 0x08820975B432F488ULL, 0xAD929637AF8BE927ULL, 
            0x6D8C627D2466BD6FULL, 0xE5A90583D7954362ULL, 0x99D4039E2A84E873ULL, 0x77D18CCD0DE32529ULL, 
            0x50B7BC77F8FF9E77ULL, 0xFCD9F196866288B2ULL, 0x5C3E1B47C77CB980ULL, 0x3C1DCD2EB3DB090FULL, 
            0x302F72AE51D4964AULL, 0x24FBA5222480BD08ULL, 0x494ED78310B9C0E9ULL, 0xB520EF8007CE3FC0ULL, 
            0xB5A2EAF08EAA9A6BULL, 0x9C5759C5FFDC8494ULL, 0x288042788EBEADD9ULL, 0x0546D8A8B1B158F1ULL, 
            0x938F29D14414B19BULL, 0x8087BA9F80F6B021ULL, 0x9BE7B61FC493481EULL, 0x90195054441EE31AULL
        },
        {
            0x730CEF2DF6501C24ULL, 0xCBA5C807EA1D6385ULL, 0xC78E8B24446CE98FULL, 0x1444323EDF729710ULL, 
            0x1047A42F57249472ULL, 0xC7E8DB75353930E9ULL, 0xBE17B28551B31C56ULL, 0xACAC3959AEB89462ULL, 
            0x3BAAA59969913028ULL, 0x3A6B04F63A82495CULL, 0x9BCBE86426E47348ULL, 0x063B96B53E3E1A59ULL, 
            0xBD3A8CD6F855023CULL, 0x3B51D89185D4A0BDULL, 0x33360C9C279ADC6BULL, 0x34F812631317B955ULL, 
            0x3317E3FCDC81535BULL, 0x5B10BCEBB6A20701ULL, 0x504DD3C4695D26F6ULL, 0x0E84228424019869ULL, 
            0x0C63A0C018DA9CFCULL, 0x959E5AB284A550B0ULL, 0x12BD6C24F81E9F94ULL, 0x65D58EDEEBD6C762ULL, 
            0xBEB9FF4DFBAF5156ULL, 0xE4EE1D9B657FC009ULL, 0xC581D71FFCF62512ULL, 0x156B449940C0571AULL, 
            0x99241023E3BA6AE7ULL, 0x018BAAE517B38588ULL, 0x4EAA3B9F7C534FA9ULL, 0xF2546D68FAB3A754ULL
        },
        {
            0x208C0328E4B7ABB8ULL, 0x4648CCE258750C06ULL, 0xE94FCD440C669B02ULL, 0xE06D292ADA5B4C94ULL, 
            0x5F579670F24BB7FFULL, 0xFD25910095382CD0ULL, 0xD10D71749FA9EE4FULL, 0xAF57F20F8CC708F8ULL, 
            0x461AF3EFD55EEA92ULL, 0x6F0E0A42B18F7E15ULL, 0xED4BE44C59DAD059ULL, 0xF2F856B035415FC5ULL, 
            0x3F0083E92A8517B8ULL, 0x6F9B7F5DF3C413F5ULL, 0xC246A5EFFF9F2A5DULL, 0xCAF24E62426F95EFULL, 
            0xCE377DB6F259EC52ULL, 0x31A01EEE0CC140E6ULL, 0xBFA224D3C7DEB7E3ULL, 0xA00812BF4259F2B5ULL, 
            0x1AED4A493F611524ULL, 0xB83786E56116DB17ULL, 0xD61DDD853FF7BD4AULL, 0xD14EFE3B4553A1A3ULL, 
            0xC3125D2CE368DDCFULL, 0x0FB0B6A30F9B7CE0ULL, 0x2EEE251A9C93E69DULL, 0x1E67E4D3BE5E576FULL, 
            0xD8B553D416028890ULL, 0xF65970A626DD95BEULL, 0xFA7F7B88C31365BEULL, 0x17BEE30646F1EC1AULL
        },
        {
            0xA779B369E7A1EEEBULL, 0x9ACF28FB4DFCD932ULL, 0xDCCCB6683FEE62DEULL, 0x5D7901D0399DFD44ULL, 
            0xD0EB3F5D3BB6FF00ULL, 0xF9968340A46FF560ULL, 0xBCD18A9411A98DADULL, 0x91CB5B8A1356F230ULL, 
            0x2744AADDD7975591ULL, 0x35592BA64A2507ACULL, 0x357311887622E056ULL, 0xBA34CDC3C3407801ULL, 
            0x5F5CDB64C3E69A59ULL, 0xCC18F98F917D1030ULL, 0xAB5CA33B62141DA6ULL, 0xE403B6FB86A9C0DCULL, 
            0x59AC1A65C96E03A2ULL, 0x82ECC0645CB35EDCULL, 0x6E561400D8362F27ULL, 0xCEBB853D04400036ULL, 
            0xBAF282B05C2B21C0ULL, 0x7BC42E15D317D853ULL, 0xC47FC1B2FA5357B1ULL, 0x073BC348DF58F979ULL, 
            0x99561DD49EF87AD3ULL, 0xCF3643C941D455C4ULL, 0x10AC6F2F8ED0EC3AULL, 0xB461653A12A1AA68ULL, 
            0x3A4FCAEBCE8A41B9ULL, 0x58BCE26596CF5CE5ULL, 0x625D039581DF278AULL, 0x98C34C6EFFDB12ACULL
        },
        {
            0x9F036B8BDCF44A5AULL, 0xF366DA0A8D5530B3ULL, 0xC434084FA2C9B3F4ULL, 0xC1EE41DF6AA0BA19ULL, 
            0x2598E9EC9E1188FCULL, 0xA1E3986BBC3C99D2ULL, 0x1AB483F3059AF5FCULL, 0xBA7CE0744A0C897AULL, 
            0x6F8F2774B94304F6ULL, 0x95F4DACC1CD74A5FULL, 0x9095399F04BC188AULL, 0x99A9BF9B0BED3331ULL, 
            0x9BE7AAD5E5FAE54AULL, 0x0B060492D06BC95DULL, 0x513D9E5122CD2693ULL, 0xA9CFF4C489CF14D4ULL, 
            0xC0B1D4BFB9A5C24AULL, 0x2BD4878768E8D491ULL, 0x639EB5802785BA9EULL, 0xE9E3A060E4202BBAULL, 
            0x0E8D3D939CC9CABDULL, 0x635FAAE952CA1565ULL, 0x0B0CCAC3FFA32383ULL, 0x2D0287329AFFA251ULL, 
            0xB3B8CDEB2A04735EULL, 0xDD68AEAEBC1D4563ULL, 0x1D09F9431E698CF8ULL, 0xE001CAA47979E78CULL, 
            0xFE224BCDD4F51F19ULL, 0xEC862432344F2565ULL, 0xE5B51B3BFA3D81ABULL, 0x7C8D90F32D74143DULL
        }
    },
    {
        {
            0x8212CB55DF3B2466ULL, 0xD10F4AE7E08EE252ULL, 0x641AEEBEC45D1EB4ULL, 0x42A993162DB53750ULL, 
            0x8C68EC31CF157DF5ULL, 0x0F7F3DA2B2CA4962ULL, 0x31E823F0CF7E7D9CULL, 0x2E3C0F515D18446DULL, 
            0xCF5558287B8E72C8ULL, 0xF6EA7532DFF84FE0ULL, 0xA05732076EE24B52ULL, 0x33264D8665E9E64AULL, 
            0xC34C6A54ECD0BE38ULL, 0xE646D2347222293EULL, 0xA42496FB397967B9ULL, 0x178C14D5C468E6A6ULL, 
            0x78182F4E2EEB2D59ULL, 0x166A49E94034E976ULL, 0xFD02171CC242812CULL, 0x06CFEC5F01A9F9A9ULL, 
            0xF19AA4F500458271ULL, 0xBC6C7CC039CB730AULL, 0xFF8CB1C69989ED4EULL, 0x3DD2C6C4D6583E97ULL, 
            0x50F2A256A0D537AFULL, 0x9633D87DE5260828ULL, 0xEC7FF2FE8F5DB2DDULL, 0x9297E2BBEB8656A1ULL, 
            0x9E09893F59666991ULL, 0xF58346316D50CDFBULL, 0x0CB6199CDCE6F120ULL, 0x647EF04D1198C695ULL
        },
        {
            0x19CC31E02C65F32BULL, 0x39B311DCBB6DF1D3ULL, 0xF630DCD7BAE01AFDULL, 0x744B242ED23D7021ULL, 
            0xBD5D3B778C8D362CULL, 0x2B92859C7DF63E81ULL, 0x16F06576721D5D24ULL, 0x2D09271108627CE1ULL, 
            0xE1DD89BA94DFDACEULL, 0x45ACA2513766824DULL, 0xC9580031B6B1D904ULL, 0xDCB835878F66DDF3ULL, 
            0xABDA550A3B80970AULL, 0x83B139F89E7FDBDFULL, 0x7DE68596C286090DULL, 0x87252C324C7F0A6DULL, 
            0x0006327542B914C8ULL, 0xDD8C1901282BD1E5ULL, 0x504BB5820F6D374FULL, 0x7FD5AAAA67A11696ULL, 
            0x27FE45648D8971ABULL, 0xE3A65037D0D96F24ULL, 0x25CEE26DCD00EDA7ULL, 0xBB7DCF16FAE54E83ULL, 
            0x7BE10B6011AB1645ULL, 0x88BC1FBE66168CD8ULL, 0xDA5B0F24CFCEB89CULL, 0xA1E47DAA12601CB8ULL, 
            0x6398718555AB4A5AULL, 0xDED14A0A3A83F458ULL, 0xB750A62E60807CE8ULL, 0xA660CDBAA7526D3FULL
        },
        {
            0x25A956C7C89202C2ULL, 0x5DCA237D3469AD6FULL, 0xFBB7AFC3876E3650ULL, 0xB63365888190E9BEULL, 
            0x80A5264583A32194ULL, 0xE347DD5E0651A354ULL, 0xF24CF7DD73C75FBDULL, 0xC665DCDE14E89C38ULL, 
            0xC94F4B29404CCD6CULL, 0xA3A5383B5BEB6E6FULL, 0x62C5751DBA4DC717ULL, 0x9ABBE8699BC645A7ULL, 
            0xCF175BB99267B896ULL, 0x0A29A470FC9DB159ULL, 0x5B8BD669B5EDE34DULL, 0x3BF35A95F2FF79E4ULL, 
            0xAB0C24BC34158A61ULL, 0x91580D1049D1D12DULL, 0x0AE1A5DA0AE690C2ULL, 0x80C7FD4CBF052E72ULL, 
            0x83F6B66C36654369ULL, 0xA2FD17FFA785DDA7ULL, 0x62B151DC398EF4D3ULL, 0x11231747DA9A2629ULL, 
            0xC3D1990B9CAA1A03ULL, 0x66F37275C79C8942ULL, 0x6F819188995C0310ULL, 0x9666D4EC0C01BD4FULL, 
            0x533918D8A69619C4ULL, 0x0F16332AE0B82198ULL, 0x1732380882D1F4CDULL, 0xFD6EB3D529E92B0FULL
        },
        {
            0xC2C60AA35B260377ULL, 0x7DD338A68F3DC449ULL, 0x19018B60A87AE0EFULL, 0xB3EC6383A3730F62ULL, 
            0xCB104CDCBBA571A5ULL, 0xC9AC7633DB6C6668ULL, 0x9E8060321CB6E5AEULL, 0x0B26278E26BD4C41ULL, 
            0x122F6E972906C3E5ULL, 0x2556B9EA0DB72C46ULL, 0xF26FF02FC9A05E4CULL, 0x10427B307456AAABULL, 
            0x67F9422392A05F70ULL, 0x7C24BA2E7E30720EULL, 0xC433E20CC7E1F514ULL, 0xA71F849E077FD859ULL, 
            0xD5AB660C8C115FE8ULL, 0x01C889609F13F7F4ULL, 0xD3829BC673DFF7D5ULL, 0x7A9B512BAF701A9DULL, 
            0xBF4D538EAFA5360AULL, 0x37B28EC96FF71761ULL, 0xF1A02B6D802537E4ULL, 0xA941C463C1C38600ULL, 
            0x27F709B597C5F726ULL, 0x8B24470615024AD2ULL, 0x275B329B6CBA0246ULL, 0x71D256D846570734ULL, 
            0xFD98B1D8AC1D5C55ULL, 0x381D8F125AB9552DULL, 0x380356DED8A3982BULL, 0x32184D53AA2A1D03ULL
        },
        {
            0x8A44DA6C16B97EF3ULL, 0x39B900EB01F47060ULL, 0xE41B10D54B417D4AULL, 0x6B774B03C09CA59CULL, 
            0x930E76D083562BF9ULL, 0xFD254F48CE1EC0AEULL, 0x37398A311D5C32BDULL, 0xE2D81C809CDB6AFBULL, 
            0xDF445E0A63668971ULL, 0x18F6D1BD2D49A64DULL, 0x723E93F19C62427AULL, 0xB8B5611E85119570ULL, 
            0x890D85E9DD2300DDULL, 0xF508130D865A9612ULL, 0x8EDC7CC066F3D3D8ULL, 0x99E4FA92E7B8EF53ULL, 
            0x6A4217FD55BB14F3ULL, 0x0A15F0687EEBDC61ULL, 0x72F97C6BC80267DBULL, 0xC635E7661BD000C1ULL, 
            0x86B41F8AE9D15FAAULL, 0xD3F69C3A94CFFE29ULL, 0x4FF6FF954C7E5685ULL, 0x823CD102989EAEEDULL, 
            0x2EC67CE8C87635E2ULL, 0x76388FC0BFD4A978ULL, 0x52F538D7F9FB10BEULL, 0x113B0C642F73565CULL, 
            0x6395CC46C4388D3AULL, 0x7B2787D84462924FULL, 0x8B2BC679FAB440B0ULL, 0x1F398A2638F0C542ULL
        },
        {
            0x73C847E9884BEE44ULL, 0xC48500077E02A436ULL, 0x91D7E1D2240D0081ULL, 0x11FB2C9082D5F134ULL, 
            0x9324130724796C0CULL, 0x50F06DFD47B8C58FULL, 0xE726F28CFC6D675DULL, 0x74850FAE320769D3ULL, 
            0x087D5A6B289C5594ULL, 0xDEC4374F32C07B34ULL, 0x9EB9C816CB722EBDULL, 0xBCA5661F15BC1D6DULL, 
            0x8299643A05366C23ULL, 0xE96B3A064C0E8771ULL, 0x25041AB46D3711D0ULL, 0xC95F50B779105545ULL, 
            0x8E6CDFCE065E6CCAULL, 0xCD1AFFF403651974ULL, 0xE4EB24ED64AD0B63ULL, 0xF2074A715617F5ECULL, 
            0xAECCA4659529B485ULL, 0x46FF095E38172E9DULL, 0x08185FA119EA5944ULL, 0x293E62F0AEF3E320ULL, 
            0x4593956886EA2FBFULL, 0x30838DAE95DBD14FULL, 0xF4DC99A80E0B1349ULL, 0xC6966B971F930B5BULL, 
            0x2F8227BAB98A4405ULL, 0x3B54AFFC978C51EBULL, 0x11711BD7027CA39BULL, 0xCA54E460E7FD3F18ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseHConstants = {
    0xD80E1C626C2B3DECULL,
    0x1CD4A30D48245463ULL,
    0x13B8D0A150F09865ULL,
    0xD80E1C626C2B3DECULL,
    0x1CD4A30D48245463ULL,
    0x13B8D0A150F09865ULL,
    0x3EC8E929C32B28F5ULL,
    0x80BC198487023F15ULL,
    0xFD,
    0xCD,
    0x85,
    0xF6,
    0xFF,
    0xF8,
    0x1C,
    0xD3
};

