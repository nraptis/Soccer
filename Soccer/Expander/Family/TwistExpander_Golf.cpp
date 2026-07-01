#include "TwistExpander_Golf.hpp"
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

TwistExpander_Golf::TwistExpander_Golf()
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

void TwistExpander_Golf::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC717FED9DFE65A7FULL; std::uint64_t aIngress = 0xEA5C4CD7DC214E78ULL; std::uint64_t aCarry = 0xF5D052DF498EB0D2ULL;

    std::uint64_t aWandererA = 0xB76172F21BE13C55ULL; std::uint64_t aWandererB = 0x87D4E74BF19DF7F1ULL; std::uint64_t aWandererC = 0x82F4AEB055287B32ULL; std::uint64_t aWandererD = 0xA2719EAF49580206ULL;
    std::uint64_t aWandererE = 0x9849C9EE991A9998ULL; std::uint64_t aWandererF = 0xEF6886DBF8F8AEFAULL; std::uint64_t aWandererG = 0xACEEA89D36FDBA8BULL; std::uint64_t aWandererH = 0xCD8CE318BB57E45CULL;
    std::uint64_t aWandererI = 0x9CFC0BDF1FAC5432ULL; std::uint64_t aWandererJ = 0xF730AD9C0506C401ULL; std::uint64_t aWandererK = 0x943E1D35BDD429F2ULL;

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
        aPrevious = 12125008960127698302U;
        aCarry = 12704469321421548052U;
        aWandererA = 16090193064159847061U;
        aWandererB = 14395090415454917684U;
        aWandererC = 13001912485748688389U;
        aWandererD = 10554448144998615059U;
        aWandererE = 14591152572256361414U;
        aWandererF = 17731114426589956656U;
        aWandererG = 12210477507059842244U;
        aWandererH = 13614038921110445577U;
        aWandererI = 17386632453916332095U;
        aWandererJ = 12147936544403401149U;
        aWandererK = 9265890172689850671U;
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
    TwistExpander_Golf_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Golf::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC855B318344793F4ULL; std::uint64_t aIngress = 0xB947152697987708ULL; std::uint64_t aCarry = 0xCD3C794A01B77073ULL;

    std::uint64_t aWandererA = 0x8FE78EE6B0644F82ULL; std::uint64_t aWandererB = 0x9CC2FA4A7A00C406ULL; std::uint64_t aWandererC = 0x9D027813B6A4E2E5ULL; std::uint64_t aWandererD = 0x8C4A3BECBFDD2801ULL;
    std::uint64_t aWandererE = 0xCC61181681E1950BULL; std::uint64_t aWandererF = 0xE80D836D7C2298A9ULL; std::uint64_t aWandererG = 0xDB2CA14EA8AC547EULL; std::uint64_t aWandererH = 0xD09270835A609340ULL;
    std::uint64_t aWandererI = 0xD1740B778130CB17ULL; std::uint64_t aWandererJ = 0xD84816D449638DE7ULL; std::uint64_t aWandererK = 0x8E0ECC21BC575A35ULL;

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
        aPrevious = 13096599160670110745U;
        aCarry = 9948749354292996897U;
        aWandererA = 11134794303295407429U;
        aWandererB = 12612939032053723321U;
        aWandererC = 17632381054203723929U;
        aWandererD = 15495728131865440059U;
        aWandererE = 13795354491253406162U;
        aWandererF = 18133072853094851293U;
        aWandererG = 18359519151534112380U;
        aWandererH = 16522466223239015192U;
        aWandererI = 11351663050425627202U;
        aWandererJ = 17801181635329008108U;
        aWandererK = 16814371842782379033U;
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
    TwistExpander_Golf_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Golf_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Golf::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8B4DD42DD5C18250ULL;
    std::uint64_t aIngress = 0xF8F8D02B7742C01FULL;
    std::uint64_t aCarry = 0xA9012BD3688534E3ULL;

    std::uint64_t aWandererA = 0xC1B4124B1335BCCCULL;
    std::uint64_t aWandererB = 0x9F750B0916C3D6F8ULL;
    std::uint64_t aWandererC = 0xB2D8B722F2F0FBE3ULL;
    std::uint64_t aWandererD = 0xB39D40612D489A6BULL;
    std::uint64_t aWandererE = 0xCA202A248CF097D3ULL;
    std::uint64_t aWandererF = 0x9FE84907AA5FE0A1ULL;
    std::uint64_t aWandererG = 0xADFA6EF19D4965D0ULL;
    std::uint64_t aWandererH = 0xF41F3E18A92CECDDULL;
    std::uint64_t aWandererI = 0xB586D1AB3B640BFDULL;
    std::uint64_t aWandererJ = 0xB9B6A02D56A35012ULL;
    std::uint64_t aWandererK = 0xCEAFE453F1A43EEBULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneB);
        TwistSnow::Aria256Counter(aSource, aSnowLaneC);
        TwistSnow::Sha256Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    TwistExpander_Golf_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Golf_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Golf_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Golf::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Golf::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA6C665751FBA0835ULL; std::uint64_t aIngress = 0x97822A8429E98A6BULL; std::uint64_t aCarry = 0x89EF85D4958850BDULL;

    std::uint64_t aWandererA = 0xE25F4BCFD53036A0ULL; std::uint64_t aWandererB = 0xD817871E605C221CULL; std::uint64_t aWandererC = 0x964D5376B84EF89AULL; std::uint64_t aWandererD = 0xBC9DE21FDE6D5F3DULL;
    std::uint64_t aWandererE = 0xA31257DAEC361536ULL; std::uint64_t aWandererF = 0xB721700CEEB1A175ULL; std::uint64_t aWandererG = 0x8239AE4781E1B961ULL; std::uint64_t aWandererH = 0x951E6081D09FD831ULL;
    std::uint64_t aWandererI = 0xC3CA11C205F58ACDULL; std::uint64_t aWandererJ = 0x8BE0AF8160EAAEC2ULL; std::uint64_t aWandererK = 0xF55BA6E369F9244FULL;

    // [seed]
    {
        aPrevious = 12310694958541563341U;
        aCarry = 18098205315194918061U;
        aWandererA = 9529483146612889317U;
        aWandererB = 9776372918273936147U;
        aWandererC = 17407215651439145467U;
        aWandererD = 16847741199473623396U;
        aWandererE = 10203974997458463395U;
        aWandererF = 16633565233352861372U;
        aWandererG = 10122974169889101196U;
        aWandererH = 13520477494485507543U;
        aWandererI = 13750986441772610021U;
        aWandererJ = 13910114048162000644U;
        aWandererK = 12693694065060994472U;
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
    TwistExpander_Golf_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Golf_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Golf_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Golf_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Golf_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Golf_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Golf_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Golf::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 2, 3 with offsets 4577U, 5692U, 6220U, 5793U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4577U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5692U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6220U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5793U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 1, 3, 2 with offsets 832U, 7554U, 7831U, 5592U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 832U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7554U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7831U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5592U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 2, 1, 0 with offsets 1317U, 8182U, 1567U, 5990U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1317U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8182U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1567U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5990U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 3, 0, 1 with offsets 7110U, 7725U, 6974U, 204U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7110U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7725U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6974U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 204U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 0, 1, 2, 3 with offsets 1545U, 417U, 120U, 1180U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1545U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 417U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 120U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1180U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 0, 2, 3, 1 with offsets 1225U, 1061U, 362U, 740U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1225U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 362U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 740U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 0, 1, 2, 3 with offsets 536U, 1716U, 994U, 1227U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 536U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1716U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1227U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 2, 0, 3, 1 with offsets 318U, 1822U, 943U, 759U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1822U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1192U, 1127U, 117U, 472U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1192U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1127U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 117U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 472U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Golf::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 3 with offsets 3021U, 4737U, 93U, 4782U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3021U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4737U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4782U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 1, 2 with offsets 5202U, 233U, 5791U, 1598U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5202U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 233U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5791U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1598U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 2, 1 with offsets 7070U, 8167U, 6248U, 6197U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7070U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8167U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6248U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6197U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 0 with offsets 4518U, 2402U, 4862U, 199U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4518U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2402U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4862U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 199U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 1374U, 3178U, 2610U, 1957U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1374U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 3178U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 2610U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 1957U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1450U, 610U, 1190U, 558U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1450U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1190U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 558U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1408U, 1639U, 406U, 180U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1408U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1639U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 406U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 180U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1250U, 1090U, 1154U, 1277U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1250U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1090U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1154U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1277U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1455U, 1775U, 1598U, 572U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1455U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1775U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1598U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 572U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 3, 1, 2, 0 [0..<W_KEY]
        // offsets: 849U, 326U, 326U, 1532U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 326U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 326U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1532U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Golf::kPhaseASalts = {
    {
        {
            0xD8965FEFDC126767ULL, 0xBD8F60A973B5B17FULL, 0xCE8E3CECDBC219FFULL, 0xD0E4A6A3B81E4BFBULL, 
            0x4E823903E8EF684AULL, 0xBEA33CF70F1290A6ULL, 0x83FD0DFBD442E11FULL, 0x02E08B9A3D911DB5ULL, 
            0xB65CB1A04649D71FULL, 0xEF52BB16B20C61C8ULL, 0x9897CF34A4399E35ULL, 0x0ACCE866EEEC2396ULL, 
            0xB38DFF3454D7B138ULL, 0x49DF7A6CE4E81787ULL, 0x59BDF414F351C8B2ULL, 0xFD0EEDCB4F34D0BEULL, 
            0xE682A39E41191D13ULL, 0x001A994E7195CC98ULL, 0x78CDE566E59B39A8ULL, 0xD543CF59A5727A7EULL, 
            0x29D097C6B6DB2352ULL, 0xC437921A50D93A1EULL, 0xB338DE6AD284F09CULL, 0xB4A73574F3CD4095ULL, 
            0x75D683B741C8C19BULL, 0xA74AE129749379F0ULL, 0x371144F79D5C1BA4ULL, 0xCCCECF7BFAD66688ULL, 
            0xCBBC947DB0559CEEULL, 0x00212AB3F0F771BFULL, 0x6AFC4AB6D9FADCD5ULL, 0xB564F7134B2C0E86ULL
        },
        {
            0x44FAEBA360083863ULL, 0x915B43617B0F58E4ULL, 0xC02808799F463477ULL, 0x4BA6D9D0FA23B2CDULL, 
            0xB0D04984623E6A10ULL, 0xB5C36666573B0204ULL, 0x3241869AB2D05370ULL, 0xF89A751F1B79B232ULL, 
            0xFEAF589A0A8A92A0ULL, 0x15842E70F19E2D33ULL, 0x273A911F4C9A8000ULL, 0x5AB2EEC706CEA6F6ULL, 
            0x1897AE5D8DCB2D09ULL, 0x8D3670798C52273FULL, 0x0DF08608B11CCDC8ULL, 0x8950216102DA970BULL, 
            0xFF86FD494E348057ULL, 0x88B1B757428E7EDAULL, 0x7D269AED36B07E58ULL, 0xF41545FE901E0A57ULL, 
            0x08996C9A32962430ULL, 0xA4DE8DF72EF37F84ULL, 0x18EB15229F0588B1ULL, 0xA059B1A552513AE1ULL, 
            0x05E2A5F6543E28DAULL, 0x83AD7AC8759EFE0FULL, 0x7863CF02CD6149CDULL, 0x59D3C2A457D876DBULL, 
            0x1F20B97E0EAA3403ULL, 0x555710360EA4B788ULL, 0x9D9120312EA70AE2ULL, 0xCAF9DBA450F956E0ULL
        },
        {
            0x165DFCA185C2FD80ULL, 0x3C6C8AAE5349DBDEULL, 0xE3F2D7D0F46AE4F7ULL, 0x4138A3C1C07B24B1ULL, 
            0xE892052C1DDFE629ULL, 0xCAE7BF14B17B594AULL, 0x8D6C8E1E45804563ULL, 0xD9F3123EB49341BDULL, 
            0x0709A9974B0A2C66ULL, 0x82B63BEF7EB61863ULL, 0x3492F492A2E18BFBULL, 0xA856C9E98A44C732ULL, 
            0x5DA782D752F46476ULL, 0x344B1C6AD1254F14ULL, 0xEE17361CE79B0CBBULL, 0xDCC9D5C1C7E7DBDAULL, 
            0x5CB37884401DD410ULL, 0x6195918CF987F1BAULL, 0x1F24DE5CC709D046ULL, 0xD1413B1A4D8FC4B2ULL, 
            0xB1B226DC5E3E4FB2ULL, 0x2B7162DD33890EBEULL, 0x2A32ED303EA1D0C2ULL, 0x35C4B7DDD92D7CAFULL, 
            0xA9ED380CE7A3E15DULL, 0x09C5FBE596AE50E8ULL, 0x0469A170D27CAFF4ULL, 0x2CC2D08EBABEF8ACULL, 
            0x283A69535F37CA86ULL, 0x768DA12F81591075ULL, 0x274107A1E63AD393ULL, 0x12880E82352FDEBEULL
        },
        {
            0xE0D72670A37D8DA6ULL, 0x2A5F4A66BAAC0E2BULL, 0x25ABCA3C73EEDB64ULL, 0xC4B8310392308D76ULL, 
            0x68A241F823DFE88EULL, 0x402083D579189091ULL, 0xA69404AF91E3D1C5ULL, 0x8730CCEC6F5EEA17ULL, 
            0x3A204FC5615B4945ULL, 0x93B2403C20DAAC8EULL, 0x28D0EC9ED3C63F9AULL, 0x943A938FBA027D7DULL, 
            0x20B9D98ABA59DDBDULL, 0xD49D18ED9E8AF433ULL, 0xA02CC44FAE39B6E9ULL, 0x9E269359F3156D32ULL, 
            0x27C7FD1C9D0CA575ULL, 0x92E8955F7380F0D3ULL, 0xCE0D3D66C3DC6C67ULL, 0xD3192B40B1406D2DULL, 
            0xD9B573B83ADBC931ULL, 0x91388B1780A83C33ULL, 0x40E9466F97139D12ULL, 0x7260D6A2268B7E15ULL, 
            0x6235ABA61C61D55AULL, 0x1C87D9C60184179EULL, 0x0ED30E6E613E0B16ULL, 0xEBD6906DA4573031ULL, 
            0xDFEC7219B99F7665ULL, 0x9A655B81961647FEULL, 0x173C267329C72BF7ULL, 0x19F9C2B22E69C668ULL
        },
        {
            0xF23B10C5F8CA817CULL, 0xB1FB514838272E0CULL, 0xFC512A0E1735F7C5ULL, 0xEB59C5BC23C4D76AULL, 
            0x9541DA18CE72C4C4ULL, 0xCDD5D5DB50574295ULL, 0xC381AE344776B6E6ULL, 0xAE85FD21324817ADULL, 
            0x219C79FF69B9ACD0ULL, 0x194DB5E7715E72A3ULL, 0xF21DAE2EE64D6F89ULL, 0xCB6B7CD190034B03ULL, 
            0xC891715C8375BB8DULL, 0xD40416C2250224B3ULL, 0x5659BEA043226948ULL, 0x17CF2F8940A8211EULL, 
            0x3BF2B21B00D6BA4FULL, 0x643570627745AD36ULL, 0x16426B90FD4E1598ULL, 0xBB30476E52F87E2FULL, 
            0xB03C5277AA0A6AF4ULL, 0xB3A63CB91041239BULL, 0xAFC0E58426757E87ULL, 0xE8D995AB34BD3C79ULL, 
            0x9C2D95293E1238CEULL, 0x62FF2058373C0B62ULL, 0x9A5C000CED34575BULL, 0x1E3AC4A17B05BF00ULL, 
            0x4310B735176AFC12ULL, 0xE83BEA898B0F35E8ULL, 0x041066F3C2698A4FULL, 0xB8AB48EBA5217813ULL
        },
        {
            0xBDA229CBB9EFCA66ULL, 0x241F6D328E453768ULL, 0xA48A27FC54E3520FULL, 0xEC52875EFBB20446ULL, 
            0xD3E6AC321C01C25FULL, 0xDAFBD799E829DA92ULL, 0x210C2BE5A494D7E1ULL, 0x0ED1DDFE7542E35CULL, 
            0x2F6FB08E71311048ULL, 0x391AC16DE947CC60ULL, 0x6417CD7247515969ULL, 0xBAFD48F4379B8A87ULL, 
            0x61C9E8CF6CCDBA8AULL, 0x1DC7506F4C1882B0ULL, 0xFA49A6D1463AAAC7ULL, 0x786763CD75A8F3A5ULL, 
            0x4307DDBCB9199D2CULL, 0xB2F2F889865D324EULL, 0x2C24D48AF98EFF2DULL, 0x1628463FEB2B196EULL, 
            0xD3135A1DDE17E991ULL, 0x99AD7F7101D62FB5ULL, 0x72CF77A029A74E21ULL, 0x7F23437D0142C90CULL, 
            0xF7C78BCBE55C2A10ULL, 0x9BB204D1B60F5FDEULL, 0x4B3BB36CA8FA23B2ULL, 0x6A061206CBDCB8A0ULL, 
            0x1941C6C64CB54FE9ULL, 0x37DC4B9C0DFE64D4ULL, 0x130632D4F741E370ULL, 0xCF2285C193079A1BULL
        }
    },
    {
        {
            0x97B8548B654A2AC0ULL, 0x33F21A8B5FA34BE8ULL, 0xE64AA9F81521AB45ULL, 0xABB1BC612766C381ULL, 
            0x96429C8B983287DDULL, 0x9AA0E4D3612993F9ULL, 0x015520FA27850CEDULL, 0x251DCA19E10BC809ULL, 
            0xB041F8501AA13FA4ULL, 0x6C7C5E814F5DBC01ULL, 0x39B88007F562F1FFULL, 0x8BCEEE66ECFC804FULL, 
            0x895D70CE52CB90A7ULL, 0xBFDECE6E91223C9BULL, 0x53B14BA0A00C8C07ULL, 0xDC47B118615708E9ULL, 
            0x17757789A06E3FE2ULL, 0xB4F111DBB0696538ULL, 0xEC52E9F3DD1480A4ULL, 0x819CEB9BF24FD1FCULL, 
            0x88F6C487EF099542ULL, 0xD2FDAF1610F725D0ULL, 0xE98D6B72464D13A0ULL, 0x7CDF55FC3A8FAF14ULL, 
            0xCA1FB715DE7DFF5FULL, 0x655086941318636DULL, 0xBBEE2CE6304D6818ULL, 0x92FC5C9FEBC4E5C2ULL, 
            0x39A4DDE0BEEB1D7EULL, 0x35FDE5ADC1A27010ULL, 0x93BEFF312FB0B665ULL, 0x4DC61D1795FA3136ULL
        },
        {
            0xF5A56EEDB89516C6ULL, 0x8BDC0DC310A81B3EULL, 0xBE33874FE8672954ULL, 0xE808668887524606ULL, 
            0x90C2B55718DFB528ULL, 0x38F6D5E8DB898862ULL, 0xA9D45778294D3CCBULL, 0xAD1A64DAF2B26DD4ULL, 
            0x11A53F84293EBE8DULL, 0xCAFD1F44695EB93FULL, 0x05B5E4927C2BA520ULL, 0xAB127EC2E7F8E3AFULL, 
            0xFCE0F802C1799DD4ULL, 0x5E21C071FE460626ULL, 0xE8CD0F7E99555E80ULL, 0x03B2CFFDD17BB6D4ULL, 
            0xE30422D800BD082EULL, 0x2D4C8B661219FBF1ULL, 0xDAD4196D3D621177ULL, 0x64FC76950BE2C057ULL, 
            0x3F363339E7772F62ULL, 0x91C8A6220D593647ULL, 0xABB1D2FD8F016732ULL, 0x110FA3D7A1779489ULL, 
            0x130ADCDAA5E7967DULL, 0x94813319891B7738ULL, 0x45948768DDBC1566ULL, 0x3E80D60A439EE33DULL, 
            0x72DBB0F54786894DULL, 0xC31F7F40FEFCC39DULL, 0xA5E4256E48D6457FULL, 0x8BFA36D1BD1BAED5ULL
        },
        {
            0x280E3DA4AE833ADCULL, 0xE471F3C6B2D02DC8ULL, 0xF8D877E7EDF75458ULL, 0x6C5C2958097156ECULL, 
            0x0B1E4A4597815414ULL, 0x64D904A5215998B4ULL, 0x34644E3B85BE1B19ULL, 0xF435205E34F8A0E8ULL, 
            0x799D4D47C727A5E3ULL, 0x635EA4773EF99356ULL, 0x62C508B992B05494ULL, 0xB4B5292C31246207ULL, 
            0xCFB0FDE80FBB35D4ULL, 0x49D8E03B4BB6C81FULL, 0xA4AB8039013E18E6ULL, 0xEB4ED06FE0D01184ULL, 
            0xA34D78C91D3EBFF4ULL, 0x479F19148FBB7434ULL, 0x414CF84A52D82941ULL, 0xA0468065504FB19DULL, 
            0x67D699A92AD8142FULL, 0x9902AAAA096A1296ULL, 0x14619D16FE742721ULL, 0xE7FEB7E95A1540C3ULL, 
            0xBB28014A403EC972ULL, 0x213D317D67B08BDEULL, 0xE5CFE2A16EAB39E0ULL, 0x6AC71560FB1569C9ULL, 
            0xAC0B0181F7F9AB68ULL, 0xC4BA9D31E6E96A2FULL, 0x6C7F69092747C778ULL, 0x98EF336BFFEC9B54ULL
        },
        {
            0x37CEFC6102B0170BULL, 0x11D04C924C007749ULL, 0x76D11476BFFBA31EULL, 0xDF8DA6EEFFF1349FULL, 
            0xA3D0263C621D3B4EULL, 0x9B5F79569025AF00ULL, 0xA341C7FAD95DA7E2ULL, 0xE0504901A431FC3CULL, 
            0xBAC59721FFCB0F25ULL, 0x37CEF632D917DA62ULL, 0x6AEDC9532B31342DULL, 0x8CE013F09745059AULL, 
            0x9FA3A04FFB2A054FULL, 0x77E10E73D864C9FAULL, 0x6175C55DF9B7C42DULL, 0x14C327687C4132DFULL, 
            0x61590B0A3F2434A5ULL, 0x5500C17C0AB84031ULL, 0xE444D641FA6C8CD2ULL, 0xD553F59473CF2A76ULL, 
            0x999DF626C1A3CDE6ULL, 0x285FE82CBF968E70ULL, 0xB1325E153AA7B9D7ULL, 0xECE8D062282AD484ULL, 
            0x1ADADDD0DFB9B16AULL, 0x741A08EDD749106CULL, 0x4FB093C0DADBE232ULL, 0x12D4BF5F50A41148ULL, 
            0xAE1D6FB94A8E7E26ULL, 0x73502150535B83A3ULL, 0xF30541EBD99A4563ULL, 0x0C3B93BD27D725C0ULL
        },
        {
            0x1AA09048F12AD50DULL, 0x290934A737170CF9ULL, 0xD8F9BD29C2C00DB6ULL, 0x3FD6C8B34B712E3EULL, 
            0xD29DF821C7BA0118ULL, 0x9A5933056FA740ECULL, 0x82943BFC9EC47EA9ULL, 0xC5DB698C2CA8C986ULL, 
            0xF9C7F7652C85BB91ULL, 0xBF9190ABE006E011ULL, 0x8CFD47B8C64B8C4BULL, 0xD58217EB1945D54DULL, 
            0xACF50FE3893A1023ULL, 0xCD63AB46EF6B8346ULL, 0xEE77F8461C072128ULL, 0x1FA1382EE4C4A864ULL, 
            0xEF83A4F1D37758CCULL, 0x8485E06A3E23A4A9ULL, 0x3ADE32022D021808ULL, 0x94F4EBAD1384079DULL, 
            0x3F6E22B4DBDC7901ULL, 0xA47F12593E825FA5ULL, 0x49C4AA7199E5EFD7ULL, 0x187B5520A5774872ULL, 
            0xA12CD7DFC8CB2365ULL, 0x47F6D3A22B1026DDULL, 0x3FCA8A992930799DULL, 0x35227289F49DF47AULL, 
            0x3212386BECD99832ULL, 0xFC045E9B3EDA4E13ULL, 0x60D11825C2B6562AULL, 0x846BBD709A299096ULL
        },
        {
            0x7E29452F5EC66E48ULL, 0x6EECF9DD53717F3AULL, 0x1576F668B3BFC2DFULL, 0x118138B58DEB8E95ULL, 
            0x8D9068DA60711D68ULL, 0xB3556393DE3DEB8FULL, 0xD743EEB69207078CULL, 0xF2A08B882797F742ULL, 
            0x9C22A5B78A483A63ULL, 0xE57D3501751F9133ULL, 0x865EC1C214B2A6FCULL, 0x5153F6DF2145388EULL, 
            0xB837DF61F01420C4ULL, 0x0B49270E05A1CE13ULL, 0x60D01433E305EF40ULL, 0x79F73838FE176EECULL, 
            0x9632BE053E25791EULL, 0x964D85A53E1ABC42ULL, 0x5AF65ACBE1E13972ULL, 0xD92921AC87D396AAULL, 
            0x4903336770E2962FULL, 0xE7056984FB85689CULL, 0x7EEF2C9A94C16B8EULL, 0xDE610B5922974696ULL, 
            0xFECA02BE35764D25ULL, 0xE7F6E4E0E835330FULL, 0xA0BDEBFC0515513CULL, 0x4481C0FD69818C1BULL, 
            0x25BF17B6765B5E99ULL, 0xFF2BA325E4B03ABBULL, 0x11D4436446E9597CULL, 0x5712A415EB23F346ULL
        }
    },
    {
        {
            0x723C2F910E7159A8ULL, 0xF479623403523ED3ULL, 0x2DB9F56B5B25E844ULL, 0xC8F51F60C02B3B30ULL, 
            0x312D02DC1D1F64A7ULL, 0x9317C68061106C17ULL, 0xB0BCA4A41B4FED72ULL, 0x3915E215EC35A3F8ULL, 
            0xFB08B3E0FAEE3AD0ULL, 0x4C755CA86A95BCEAULL, 0x9449512CCD80E04DULL, 0xC656873A42F3F4DFULL, 
            0x9987BBE01916DC09ULL, 0xD28ADC1A7FE7F084ULL, 0xFC234382A3F08DE1ULL, 0x90F602FE4C94B2D4ULL, 
            0x64181E1866DFE6BDULL, 0x3BCEFD44951FC438ULL, 0x50062498B6BCF17DULL, 0x3BB6F012FB334EB2ULL, 
            0x94E808C9775C0EF6ULL, 0x9796792974F5CA39ULL, 0x8384C5BB9F588082ULL, 0x4FAA85A6617E0294ULL, 
            0xA2B5A350A507C481ULL, 0x7CDEF0E397281C81ULL, 0xBA00132F375168F3ULL, 0xDC296395DC2BBCE3ULL, 
            0x21D9E9B707BE256BULL, 0xFEED95FB048DEBA6ULL, 0x127C6FEBEE6CD9CBULL, 0xFA7D04B248C8068EULL
        },
        {
            0x560D102C02FB6688ULL, 0xF2A81BC375A5999CULL, 0x63AA946D29A34536ULL, 0xC56D8DF33E49A67EULL, 
            0x91AC5F3491E36C78ULL, 0x8C0918D3132A7494ULL, 0x3ABB800BDBD5B6DFULL, 0xF1D7638E346589DEULL, 
            0x96220053F20DE5C7ULL, 0x5D63E35795D331C2ULL, 0x7DB7254BF865B1C1ULL, 0x045A4B9C6C682EB0ULL, 
            0x2D0E0A8694BC5337ULL, 0x2350064CB89A1818ULL, 0x116B99F79497D6FAULL, 0x59E0669CFAFE8F98ULL, 
            0xCA4860BADA3003BEULL, 0xB98833FE704D7398ULL, 0x3D216FAE28B74ADCULL, 0xBE7C17937B75BE0DULL, 
            0x5076149485D0E8B1ULL, 0x82350B5EB4C448A1ULL, 0x2B00A89393F8C3C4ULL, 0xD126A0EB106B8AA7ULL, 
            0xE037935311E7E3ABULL, 0xA2991083F6D6B7DFULL, 0x1092DE38CF6BAF03ULL, 0x2FE71252C5CDF97FULL, 
            0x52B8FD67A9260D38ULL, 0x7EB622F89CFF1811ULL, 0xB2E04EA0C5DC1C04ULL, 0x6874C77A8792F1D2ULL
        },
        {
            0x2EFE6A91C0CF0DFDULL, 0xA342952FE19BFCD0ULL, 0xC8E28C09FC88C86CULL, 0x7C03EF14CE5160F0ULL, 
            0x36F22B71E270D2EBULL, 0xA1C977AEA56AEEFFULL, 0x37B47DECD2A2DABCULL, 0x3B8F3E7A8980D19BULL, 
            0x8EA51B3FCA77C839ULL, 0x44504CD767C3C368ULL, 0xDE2FA286123E9FE0ULL, 0x2EB86DEE2545E1AAULL, 
            0x9708B4EF312E0151ULL, 0x12708618ADAE364FULL, 0xB866C167607DFA34ULL, 0xC8D4528DC3F6C724ULL, 
            0x7862CFB50120599CULL, 0x65F5EA050E5847E7ULL, 0x47815410CF6494EDULL, 0x699DEACAAB7F4B8BULL, 
            0x6E7B18D79549C276ULL, 0xF143A4E5513F578EULL, 0xD1C252D3FECECD43ULL, 0x9C8C129A575B06EFULL, 
            0x305C97A2ECEB60C7ULL, 0xD88CC8DF0B8F6473ULL, 0x24A27E25807E1428ULL, 0x3A0F1A8BDCBEB91FULL, 
            0xBC056AD2C6C3E34AULL, 0xA891BF217BCFB4AAULL, 0xC488F846E0AA68BAULL, 0xD05B77CB488C2EEDULL
        },
        {
            0x49DA455BD33187E4ULL, 0xA712BA1C4C1A1C42ULL, 0x4CF6211B3291929EULL, 0xA44857E26D2024EFULL, 
            0x4C5130D4A875DCA0ULL, 0xB6F1C9BB5CB13B1FULL, 0x19BBCF0676A85DF6ULL, 0x625B8FB0771C3513ULL, 
            0x90E7F75BCFDD2204ULL, 0x896E057969F84D81ULL, 0xE4A5553588A2DE61ULL, 0xD4E25FD0CB43C384ULL, 
            0x16C13253A958B4D7ULL, 0x9C8BADB0913CE56BULL, 0x247DA2D3DB9389AEULL, 0x8FED749E61C523CCULL, 
            0x3624464AE5E29CC3ULL, 0x141204E6E06B6C09ULL, 0xCCD324532E6804DCULL, 0x9743BE32F1116B66ULL, 
            0x1C11C0D59D310AE1ULL, 0x4303520C3CC1E171ULL, 0x7B0FBF82393938BAULL, 0xF68293048CD98045ULL, 
            0x2107C6AB9D667DF9ULL, 0x6310E9D833D9C96EULL, 0x6532F0EF23205349ULL, 0x64851556DAA72315ULL, 
            0xD915B3290B5E5FC9ULL, 0x89AB99AD510B7B44ULL, 0x4A4D9CD7805AAB26ULL, 0xF2C7D5EAE4496E2FULL
        },
        {
            0x63F7C431D082B8D9ULL, 0x84EC7656475663F7ULL, 0x54B2BC0DCD847185ULL, 0x30DB0252D5F7FB15ULL, 
            0xA87FE05954C37F12ULL, 0x4E09F15888949BA3ULL, 0x721197C56B73038DULL, 0x743ECD190EEACCACULL, 
            0xFD865C50C0F731FAULL, 0xC41B1151FE27BF61ULL, 0xE877B777C34BDA61ULL, 0x8929F9A0D2BF29FCULL, 
            0xC02E5B942F519C97ULL, 0x8FBE44F5A09C9CB3ULL, 0x18FA5B93CFCFE8C2ULL, 0x4DACCA1B380F68BBULL, 
            0xC00EEAF0FB4FEF04ULL, 0x2DDDBEFE4E074165ULL, 0xEC3DB44C2670BFF0ULL, 0x13660CC016B73BC5ULL, 
            0x39355556999134EDULL, 0x42551D941EE617B9ULL, 0x1E7A7179685240EBULL, 0xEDDA6AF54FD12E3FULL, 
            0xDACF76EFAFB98AC8ULL, 0x9DD7B0B40CBB723CULL, 0xEE8749B9F9D7A53BULL, 0x1BD60B94534D1CD5ULL, 
            0x652BFFA91C81DF17ULL, 0x685CA75041AA170BULL, 0x15AE6DAE4A6DE8FBULL, 0x1A04C3BA9BDE568CULL
        },
        {
            0xBCB25AA099DC012AULL, 0x009E5C3CA59DFE7BULL, 0x9BC87B31EA3BA11DULL, 0x5A029AD3843D3D42ULL, 
            0x891193808A466A8CULL, 0x7148271DB2C5E7B8ULL, 0xB91EA5C61DC08660ULL, 0xDFEAA5FDDC5D13A8ULL, 
            0x5E7E35728F824B8EULL, 0x98A5FDB4E0951353ULL, 0xF39B07204C082B40ULL, 0x18BFA20C19F9E0B8ULL, 
            0xD0987700F46349EBULL, 0xCAA9D7A1C9C48A04ULL, 0x915E40B3543D3EC7ULL, 0xEDC168BA9E936D56ULL, 
            0xC81EC66E038AB699ULL, 0x8B535AA6498BA67CULL, 0xBEB261FB1A68E8B3ULL, 0x48E03DB62F425BD5ULL, 
            0xB55971AC94C2DE25ULL, 0x8A484467D5B403F7ULL, 0xDFBDB49B2A9A0EA0ULL, 0xBF8114755CF2EEFDULL, 
            0x73FEDFC8DCFC0695ULL, 0xB935C547DF76E702ULL, 0x260B59EF2186DAB7ULL, 0x953868B5E5AE2CC7ULL, 
            0x8836829C83FB8891ULL, 0x565BA034A972843FULL, 0x2A3284AD1672369BULL, 0x03C95AB9C9297925ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseAConstants = {
    0x724C7B212829D59CULL,
    0xF61791E75EBF036EULL,
    0x9656169D571491AFULL,
    0x724C7B212829D59CULL,
    0xF61791E75EBF036EULL,
    0x9656169D571491AFULL,
    0x1AC21A4CCE571A9AULL,
    0x1F0907FACC88E16AULL,
    0x2E,
    0xA8,
    0x8E,
    0x03,
    0x01,
    0x69,
    0xDD,
    0x26
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseBSalts = {
    {
        {
            0xAB7885C48A446D5EULL, 0x2F3C1293BCB5CAC5ULL, 0x131D4F6A0F52031BULL, 0x6CEEA7A1EF7AD1A7ULL, 
            0x727B69409B9A2E0AULL, 0x29250D60AF50D2DCULL, 0x3B0EAC602261B499ULL, 0xFC2092E83C25EAFEULL, 
            0x4FDE2E52EC78C25CULL, 0x81007A21EF45EFD2ULL, 0x131E0FBDE44162B5ULL, 0xB3E6CE213DF7A5AAULL, 
            0x7F80B52C503F741EULL, 0x93676C3F2C6E6F1CULL, 0xB3DB0BC34567ADB8ULL, 0x07EACE6A2B10AB86ULL, 
            0xB98100FA27C294BFULL, 0xEE89339FB9ECE246ULL, 0xF9A562767ADEEF80ULL, 0x402D564E2F186BC5ULL, 
            0x025D108EBB60C3FDULL, 0x17990AB03EABEAD3ULL, 0xB87D71CADFB2611CULL, 0x96F939366E2B5D6EULL, 
            0xBD6B98412EDBD7B1ULL, 0x779D1540E2C1007EULL, 0x1695F4B23A4A5309ULL, 0xD8EC0E184CA630D9ULL, 
            0x21115DCAC35F48D5ULL, 0x1667B0A6A49E89ACULL, 0x6EBAF938EB6232F9ULL, 0x6767B3FC5B675321ULL
        },
        {
            0x64F70D0527F05B66ULL, 0x4864E12068738D1AULL, 0x0AC7716DB6C50B05ULL, 0xBBB059CDA582AC05ULL, 
            0xE56DF06477613F15ULL, 0x0549A95658B78C7DULL, 0x7E182497A3EF6FA2ULL, 0x9EADB7CD7FAA2A65ULL, 
            0x1CD1FD9EAAC51886ULL, 0x22A32FF1565CDB16ULL, 0x7EB17D5E30B1A695ULL, 0x4C086B7575A38EF8ULL, 
            0x6987AD6284B94D46ULL, 0x257AED80BD2F7B9EULL, 0xA6449D784E5D3E69ULL, 0xC4C93FAB39CADA97ULL, 
            0x4236F68D42A9A090ULL, 0x8A3E0DA0B59ED3C7ULL, 0x221B8D610AA5F162ULL, 0xDE45F804B8BDB204ULL, 
            0x0BF8924B45157DB1ULL, 0x5F6365ED4A42A073ULL, 0x65B3CD2A3FA4F0F3ULL, 0x2C063AD3BE18D4ABULL, 
            0xFD4C2B5920DC252AULL, 0xB3FD5087C4813D1DULL, 0x252239508E3A4554ULL, 0xEFC188F1CB110865ULL, 
            0xF3996BF29817F4AAULL, 0x7CCC045F64BCAF8AULL, 0xD43A0BE91118CA6CULL, 0x12D55063144F7B5EULL
        },
        {
            0xCB090BD5189776F1ULL, 0x697D646610138241ULL, 0xF9B93283D7548C69ULL, 0x3E38BAE986A47E59ULL, 
            0x140DD25FDD0584F9ULL, 0xAABA1E8BF394B30CULL, 0x09B9B522D017AACFULL, 0x69852DDA3F2293DCULL, 
            0xC698B32993176F11ULL, 0x2F64BF88E726D337ULL, 0x59553311C1646102ULL, 0xDD13507DA76BBCAAULL, 
            0x5367785A9856EE4EULL, 0x083DFD7472B782AEULL, 0x80D76B6FAE0FC6D5ULL, 0x89ADA3D5DA8DA7CAULL, 
            0xFED4327088D72907ULL, 0x38C177572AFBD94DULL, 0x7EFEF2FE34B8AF34ULL, 0x3B73DB3B8FDC7377ULL, 
            0x7CA16AD647EF6817ULL, 0x40356956BE7F28B5ULL, 0x83F93691BA94357EULL, 0xE7D2A075B58730F5ULL, 
            0x6E8CCA8E13D25547ULL, 0x9DFF1380436356CBULL, 0x9F7B3A40C3B3F4A2ULL, 0xAA369031EB88F445ULL, 
            0x0894C7442E8FC67FULL, 0x24F070C727C5650DULL, 0x31802257E5CF1EDEULL, 0x4A9905DA646D4925ULL
        },
        {
            0x5665DD9ECF626C4EULL, 0x4EDD311174205F1BULL, 0x75321CEDCD96D912ULL, 0x6AD07F84A725BC03ULL, 
            0x0C4384D9DA6F9D2DULL, 0x2FF55F9C96EAC523ULL, 0x18B6E5B2475C2C63ULL, 0x8657C09068AD35FAULL, 
            0x9F35C5CE354AADCDULL, 0xEDA96DA8F2ADA899ULL, 0xD7CE6C2D7B0EBC5AULL, 0x2A8A7899C7B08AFAULL, 
            0xF7BAC102776FE0C9ULL, 0xC48EF7F44EB5FF7AULL, 0xA17E3C2AEC01C5F8ULL, 0x7644928BC768CDD5ULL, 
            0xF16F555F6A47CA83ULL, 0x318A2DA97CA9D20FULL, 0x4C91EDEEBE9A721AULL, 0xCD8FB089AA720A18ULL, 
            0x986823C3204E43EFULL, 0x80BC19938DF17F35ULL, 0x9FF206AA94347C6FULL, 0x427737DDE172698FULL, 
            0xF7F4CCA3A281832DULL, 0x256B6BEA6E031237ULL, 0x63589ACBFD17F320ULL, 0x372DFE49E1C09FBCULL, 
            0xDD6E97027C422EF4ULL, 0x9715E3F21ADE9ABDULL, 0x79BB8B3F15CE529EULL, 0xD72E0F4626709D6CULL
        },
        {
            0x503617491CF881FDULL, 0x75D9CC715828C2CCULL, 0xA53D8CE22C84250FULL, 0x38F8866EA10BB2FEULL, 
            0x8752AA0360AD1754ULL, 0x37CBA13FE765809AULL, 0x72D4F3D4833DEB04ULL, 0x9D33B52E991CEF11ULL, 
            0x0079B1ECD2F8FE5BULL, 0xD5F4A87F3936A390ULL, 0x7C075F6AEB719213ULL, 0xBD5FD00B597A0D2EULL, 
            0xCD8AB3CC07D41410ULL, 0xAF01F64B15E4E9E9ULL, 0x23EA3F9170864B85ULL, 0x86B1DE7E6AEBF94FULL, 
            0xC1B80011CD8F1BA0ULL, 0x9D445F4D97D256E4ULL, 0x62D5593F707BCBF7ULL, 0xEDFBEF59944C7806ULL, 
            0xCDB811FB8AA4A408ULL, 0x3F737398E1E66CB6ULL, 0x699F7703983E151DULL, 0x386EBE486A5C6222ULL, 
            0xCE3CCDE75626C7BFULL, 0x4455685359A5564FULL, 0x4760B6CF2763656DULL, 0x02FE38BE69E2F121ULL, 
            0x128D072F50AB27FFULL, 0xCFE82BFD9745035FULL, 0xACBB2D3E4DE44EDFULL, 0x6A64DF47779CE3BAULL
        },
        {
            0x343FA4000E928D07ULL, 0x7E8E53D0CD993DFAULL, 0xC8ABF2CF10BB2166ULL, 0x24CD9E922169E18AULL, 
            0xAE3461ACEAB9CE86ULL, 0x1CFA3BED59F3FB2DULL, 0xD4201424FC8DA165ULL, 0xBE5F2358EB0DC78CULL, 
            0x441863379FE3C84CULL, 0xD2D90ED3B4A37696ULL, 0x2B2AD42451DF1CDBULL, 0xAFB4E3CAFB5891CEULL, 
            0x66D46FE18A113FA7ULL, 0x885E726D8558577EULL, 0x568A7C7201EE4B79ULL, 0xDEA64C5730617D96ULL, 
            0x4F88D682D5696AD5ULL, 0xC36AA49F128BB4E6ULL, 0x29074AA479314CC2ULL, 0x8EADF56BEAA66638ULL, 
            0xC64B62532DEA409DULL, 0xF7C488EBB7414113ULL, 0xA46B356C26EA3B7CULL, 0x6615A155EA9C5D48ULL, 
            0x7F45A690BFE5AFE7ULL, 0x90E04886161DE35CULL, 0xA8D036E63A480070ULL, 0x652870E26ACEA982ULL, 
            0x44E878BBC4F3FCFBULL, 0xE29970C1732BF3C8ULL, 0xDC4FE2817AD0899FULL, 0xC5A45B2F9A4E39E3ULL
        }
    },
    {
        {
            0xB04D9D91489188C3ULL, 0xEB0F709EE7E93946ULL, 0x950BC36BD04BC6B6ULL, 0xDB52064661A62EDEULL, 
            0xFC7D3CF8BC7A8A4CULL, 0x95F2DCAE53CDD17CULL, 0x1BB0E7ACEFCB4D74ULL, 0xDC7DA4EE1C831E20ULL, 
            0x5ADE6410CA5E929EULL, 0x446EFA27025227A4ULL, 0x9B63EC27EB4295E8ULL, 0x2BE7834B721EBE3FULL, 
            0x4556128362B22A5AULL, 0xAD06782B2B115F0EULL, 0x95E2E6D40A618169ULL, 0xBCEDBCD81E62A676ULL, 
            0xFD609081157B96E9ULL, 0x0E34FB3305F49D6BULL, 0xC1470F0BBDE4145BULL, 0x7D8ACA7C15D8B784ULL, 
            0x53683945DDF5E5A0ULL, 0xE5F0E0B73F82EC5DULL, 0xBC22A7308FCF06AAULL, 0x96EFE2C7BFF725FFULL, 
            0x5426EFB844BE76CFULL, 0x76AC88E332DD577BULL, 0x45BD5D78EAE23CFFULL, 0x96ED90BA6C94E756ULL, 
            0xCFAC25293E6E7191ULL, 0xF00CC7787F2BA46DULL, 0x96222CAD8DAF9A65ULL, 0xDE0E28BBC9187435ULL
        },
        {
            0xEFD97A81F6C05965ULL, 0xC4D3745CDEACCBE0ULL, 0x03A1306414771382ULL, 0x49E6956AE2428A0AULL, 
            0x446E5DB29D65FDFCULL, 0xDE48E056719C4F50ULL, 0x77E024A6B5B7DEFFULL, 0x51F6E9836F1842F7ULL, 
            0x9BB4102ED7E88905ULL, 0x0DE04E8A3FB8E27CULL, 0x7DA14FAE4EFD210FULL, 0x92E2492A54C62AAFULL, 
            0xF06161060A328D3AULL, 0xBD21D6FC5B9CFE83ULL, 0x8C1CA5DF983C10BAULL, 0x687A0EFAE5D8816DULL, 
            0xF48250A9B55F4085ULL, 0x35375DC444662052ULL, 0x2F2DC0E6F9897CC5ULL, 0x21F5D1AC7345A53EULL, 
            0x2362FCE4E1D7BAA6ULL, 0xFA353A8D2A6BF266ULL, 0x331ED650D2EB635DULL, 0x46F8C8D0E4D5E3FBULL, 
            0x8B700C0508DAB5B0ULL, 0xF53BBB319A219A1AULL, 0x212B60DB52E393E4ULL, 0x468DC2504E733DFAULL, 
            0x6C0B5C25AF9AF634ULL, 0xF91467FC362F2C80ULL, 0x68DCA011B352E02BULL, 0x409FF9EBC31585D6ULL
        },
        {
            0xF395DD7827F80297ULL, 0x18BDED737F0DFFC1ULL, 0x07D4B5688E7115C1ULL, 0xC61B8CA5D74BC82BULL, 
            0xF3195ECDD6A751CBULL, 0x0FD02643BE750E78ULL, 0x05FC919F107961B2ULL, 0x930CB137372FD6ADULL, 
            0xEFEEAEDFD45187E9ULL, 0xA5F38C0B215C5BE3ULL, 0xB97051B2CB9395EBULL, 0x92954736F218E391ULL, 
            0x9D8E73A4245CDF3EULL, 0x5AE8C5C91B22F8A4ULL, 0x876E3AC558AD0816ULL, 0xE6D84FE1F98307D4ULL, 
            0xDFCB58C25D1033FFULL, 0x8536DC14414E3468ULL, 0xE4FF5F49D83CD97EULL, 0x9706A486C95C47B8ULL, 
            0x125B942F3706AF20ULL, 0x37BA87DDB4C5E765ULL, 0xD09CE04B155A0D84ULL, 0x026F020FF2447FCDULL, 
            0xD42F140C2786DE08ULL, 0xA7F41751C83BD9D0ULL, 0xBCD95E45C492AB1BULL, 0xE1DF45F78012195BULL, 
            0xDC2303D28739F055ULL, 0x92E208615FFCCA44ULL, 0xD7276FAB31E03D4AULL, 0x4A27254D23BF8A22ULL
        },
        {
            0xACA6BBB83715AD28ULL, 0xB368F0BAA0B5E691ULL, 0xA93BB8AFEE0BDFCBULL, 0xE593823722CA495CULL, 
            0x2247394A2EC6C6D9ULL, 0xED1990F4EB0DB214ULL, 0x1C0784A7EA5A6B3AULL, 0x0A609F655E8A74ADULL, 
            0x348727FE1CE9A4E6ULL, 0xC1BB61A62A3C25F9ULL, 0x4BC2D7E9E66F10DDULL, 0x7525E8413B006168ULL, 
            0x1137F4E6CCA0F0F0ULL, 0x46A9B1EC9015574DULL, 0xDF7052C9261A7BD4ULL, 0x4B22C4D4D662D62FULL, 
            0x43DDE3906B2BE67DULL, 0x8C0AA4A5B8E36717ULL, 0xA2CE92A73A2F3DF3ULL, 0x6C47EBFFBFAEA09FULL, 
            0x385B63BBC637EB15ULL, 0x3B73D339791C718DULL, 0x24E838252DB134FDULL, 0xDA879AE45BBBF517ULL, 
            0x0BC51800F43CEE44ULL, 0xA80B180093AAB4B2ULL, 0x5D4FB0BE17D9D50BULL, 0xCCA857E13763E29AULL, 
            0x641BEB0912ACF741ULL, 0x99CB44B32015805CULL, 0x36FA0F920AE01587ULL, 0x5EBBB4CA9C6A2652ULL
        },
        {
            0x10B129BC5709A0CFULL, 0xB951DD3D1A30CB2EULL, 0x957A6A15562FD5A2ULL, 0xC6519E18F52EE478ULL, 
            0x4A9EB792A8AA366EULL, 0x0BA0DC93B20A8131ULL, 0xDBF35659F7438AA4ULL, 0x723E238325CFAF65ULL, 
            0x488A7DA33035D9E8ULL, 0x0D424FE598C812D3ULL, 0x2DD916273540B637ULL, 0xFB50C0B7B9259F84ULL, 
            0x418D74AF6CE7EE88ULL, 0xEF040017E72C8263ULL, 0x0EF72C111D96433EULL, 0x1707451E551CA149ULL, 
            0xB2415D2DB24960D7ULL, 0xF5514828E02CDC0AULL, 0xD4B974A053F3093CULL, 0x4007E45713C8E2C2ULL, 
            0xB57908E3260DC8FBULL, 0xC47D6D56111AC915ULL, 0x352591EAE28CD712ULL, 0x08F308FC753E0BD0ULL, 
            0x24D536EB58C589C8ULL, 0xB2E14636841A4A81ULL, 0x17A8D816A623F0FFULL, 0x997660860235DEA0ULL, 
            0x8B6DD47156B1B153ULL, 0x8F696C99A2DE7B94ULL, 0xBD97583396585595ULL, 0x3421E4A26F97A3DDULL
        },
        {
            0x4B12FEFB6663A019ULL, 0x6038C212E050A8F1ULL, 0x937A0EB4C992E697ULL, 0x5118D0B6012C8E7AULL, 
            0x357CC48AF91F2870ULL, 0x19162824BCCDF1A1ULL, 0xB7B2E071C2A48119ULL, 0xC0470C9110EB149AULL, 
            0xDBE4A6D9C6230404ULL, 0x8FF6285AF051AC1FULL, 0x2DE2353415B1DE94ULL, 0x0A3C21464711A6B3ULL, 
            0x0F5BAB54C0F03813ULL, 0x29E4F6E949F55D75ULL, 0xFF815EB9FEEE8BB3ULL, 0x83ABD7CACCB1FBB7ULL, 
            0xFD3371E8FE42007BULL, 0x52F24268C2FEF174ULL, 0xE78091E269B68B20ULL, 0x6C502879653A26ABULL, 
            0x7535BBC714046549ULL, 0x1FCE345B1B45DB08ULL, 0x317C656A316B252CULL, 0xF4F9C74C66E836C9ULL, 
            0x4EC1E7DC4E561C06ULL, 0xA5E51ECB8ED73954ULL, 0x064C6033897051B0ULL, 0x5DBB683E16561532ULL, 
            0x5E568E2B0CA38690ULL, 0x84BF977BB13B47DDULL, 0x73782D0BAD9E9BC9ULL, 0x9C6C6F531DC0DBF6ULL
        }
    },
    {
        {
            0x3D5B171785BAACC4ULL, 0xD67D6A49D8E05861ULL, 0x6D3ACE9498A6DF85ULL, 0xCC1DDC6E30626ED2ULL, 
            0xD524DEB9A45AE03FULL, 0x38CC456679DD19F2ULL, 0x1EA8B9656F0C44DFULL, 0x2B2FCDA7496B814AULL, 
            0x67695C0F93D8A0F1ULL, 0xD1C6048C5830DC3FULL, 0xD9B42AC1C2AA7105ULL, 0x698A666E05185354ULL, 
            0x9D00DAC23C76829CULL, 0x00A17F1F3C2092B4ULL, 0x50A4523032E343B0ULL, 0xE1581697F5EB12B5ULL, 
            0x66E864E67C07F62BULL, 0x62C5AD5899E153E9ULL, 0x77BF06635A1FB0CBULL, 0x49F88EC64E48FF8EULL, 
            0xCC10A3D5F43739CEULL, 0xD5D361D973A39F4AULL, 0xEE3BF404B12D1BD2ULL, 0x8223BFBC29A808D4ULL, 
            0xCE4F91C6158E9410ULL, 0x1C95082655CB7B12ULL, 0x6C8291BD3201B31CULL, 0x0D1DB8EAAFD1C237ULL, 
            0xFF2E231CA4DCC606ULL, 0x41C3A177DA1A73DCULL, 0x2213A96C442AAC26ULL, 0xB4D070977D1A411DULL
        },
        {
            0x02D77327F97C51FDULL, 0x0A67E65F43BF39C4ULL, 0x9A549D7AA5BDA151ULL, 0x72CD6EF78B6608E3ULL, 
            0x662B3BB56BCB89E9ULL, 0x841682F93165CBFAULL, 0x18743BD1AAA17223ULL, 0x67D61B18291A1F3DULL, 
            0x0F88D98DD0C9006DULL, 0xA9C6B864BF66100DULL, 0xF48546B5AD128A91ULL, 0x0617E72D230AE445ULL, 
            0xBDD4AAB3411CA93FULL, 0xE21F020A2D5A9D64ULL, 0x93D9594D5086ED14ULL, 0x1776ABDD57256446ULL, 
            0x54A9BCEBE02D1469ULL, 0x88A78340D627C513ULL, 0x31DC3C2B81F3043CULL, 0x4089B2DFE1943D65ULL, 
            0x13053F7716960216ULL, 0x8ABBDC6ABE0C9DC5ULL, 0x810BA02EC13F78F4ULL, 0x5281AB8476CAB909ULL, 
            0xBBB995F76599C37FULL, 0x27E87FD1241FE6FCULL, 0xDF79F0482437EEC2ULL, 0xD5EB81A5BA79F609ULL, 
            0x9769C6637BDBF35AULL, 0x7BE55E3EACB2A695ULL, 0xDFE45FFE41944D3CULL, 0x6DABA6734A17A098ULL
        },
        {
            0xC5917F53DBF1427EULL, 0xB88D17F0AC17510DULL, 0x2F42DE47D83556F3ULL, 0x5964BFC1A2F5CDAAULL, 
            0xD52F5A54C547D246ULL, 0xA4516C0C662CBB6CULL, 0x508EBA4E220EE449ULL, 0xA255EF4287820800ULL, 
            0x919F3F602F460952ULL, 0x5618C4992E0DB094ULL, 0xB02F3E0964ED7C55ULL, 0x8153DD3BDA2C61EDULL, 
            0xF39CE8363D7DC612ULL, 0x10DDA315CE1779D1ULL, 0x37316CDDC4B53F28ULL, 0xEF183AA9254A2C72ULL, 
            0x6E47028127112C78ULL, 0xDE4D54DEC00562EFULL, 0x27FBE79E124A121EULL, 0x6D479BFB274D3DABULL, 
            0xA3F5FF51CA26B696ULL, 0x6BBAC1EA60A9E148ULL, 0xE30B59CABE8E82AAULL, 0x2F2991F0FA9DBDE9ULL, 
            0xAC52A22C8894AB34ULL, 0x4CFE947F4D705A4FULL, 0xAB6B0309A1E57778ULL, 0xADC4C3CC650BAE31ULL, 
            0x0695B668E60341CBULL, 0x5161CCC64EF36692ULL, 0xD49295168B525FA2ULL, 0xF42063AE5705080BULL
        },
        {
            0xEF100F7B1F91F28BULL, 0x1FCD42CB823F53D0ULL, 0x0A5D85456E7DD4E6ULL, 0x404050A7A2071B57ULL, 
            0xACEFFE5C64BDCBDBULL, 0xB2C33EAF5EAC27F9ULL, 0x495A8E5A6FE1ABF7ULL, 0x33B5AA798AB0A96CULL, 
            0x770CA378494B548EULL, 0xEE8F798DC1810C9FULL, 0x586C7978A84F71CBULL, 0xEFCE395F73CB44EAULL, 
            0xC98D08FEEC7C1CC5ULL, 0x73FF47EC3A4655E0ULL, 0xCD5F3118226F2F46ULL, 0xE56672BB89F4BC8EULL, 
            0xF269F5543F72BA93ULL, 0xD810B6D1C4136C62ULL, 0x8379788E74794EF7ULL, 0x9C7F6D7BA3217621ULL, 
            0x7D2F551745EB4AF4ULL, 0x71AEE4101E3FA8D9ULL, 0xF82FBE978B2F98C6ULL, 0x24EF816463B342ECULL, 
            0x27B722BDD52EDAECULL, 0xF1927EE60C4F9197ULL, 0x7C8519E812BF3B0EULL, 0x780CE9977BD584A1ULL, 
            0x8DFF0B578C5FE267ULL, 0xACD04980C8F523E4ULL, 0x846B0B3BC62EA7A8ULL, 0x25C98D87BE6F66D9ULL
        },
        {
            0x63192F9FEDC5081DULL, 0xDF2EFA199852309DULL, 0x917514B5837F0265ULL, 0x7BB491D92CC456A7ULL, 
            0x6C392F5D9CF9CD7CULL, 0x979807D7893C34C9ULL, 0x39982BD42BD304C5ULL, 0x38549158B47FD707ULL, 
            0x62DFE6FCEE3FB234ULL, 0xC532F1B4F9F61A11ULL, 0xB09E12561EF2FAF8ULL, 0x91CAD0FDC4B7D18BULL, 
            0x9C0E0E513420FE19ULL, 0x9D98BFD3CD7392B3ULL, 0xC6033D546900204FULL, 0x35C575F84F351DC6ULL, 
            0x9579A4A7481754E3ULL, 0x7F84ABDB4E9A7637ULL, 0x3B34FA166A962F67ULL, 0x2C53D05C9CA351D7ULL, 
            0x19A2A4DE2F31EBDAULL, 0x36A948EA61C31F1EULL, 0xCAFCD8ABB1EB02B4ULL, 0xA350819FF365B34EULL, 
            0xA23156E47765BC30ULL, 0xD5CF0E5DB6C00D6BULL, 0x7ECF1B700CD6F748ULL, 0x4202C0DC3268D930ULL, 
            0xCE0CA9C35F3DD1B3ULL, 0xFA308E626556CF49ULL, 0xA5EDA6A9F7C01A40ULL, 0x1B58397A2CC8574AULL
        },
        {
            0xCF0113DA19A4AC05ULL, 0xB219C8D7B424037BULL, 0x9F5CAE71770868D4ULL, 0x27A1DBBAB4A75F90ULL, 
            0x1327A7B266AFC0A6ULL, 0xF5222333985469CBULL, 0x7E80C459E654608DULL, 0x1FF6859D50ECFDD3ULL, 
            0x19DE48D8B436537AULL, 0x5A2F6556E6BF5980ULL, 0x2885309019F05CF5ULL, 0x35B31CE8077D6155ULL, 
            0x41838E202756CB91ULL, 0xCD617D7C9BF832DBULL, 0x15C89E844BB9AE78ULL, 0xE785B9E8661BCF65ULL, 
            0x0749AEF53FA3C24BULL, 0x554A68D2DF4FC205ULL, 0x1BFBAE834E19630FULL, 0x67F0C02E3D12CB4DULL, 
            0xE6429285CCEE5A29ULL, 0x59B68EE82233207AULL, 0x38377EF4C13A3491ULL, 0x6317FAB63E72363EULL, 
            0x3B7DE25405A35C72ULL, 0xF4F0B4294672CBB9ULL, 0x8750B1F3A067B161ULL, 0x87DF672C4CDB70B8ULL, 
            0xE00367356DE994D2ULL, 0x64C166E97F7D14AEULL, 0x609412DD25880165ULL, 0xE25F56E05CF7E4D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseBConstants = {
    0xF9D0F5ACEC0051CEULL,
    0x9D21370CA2F5F4C1ULL,
    0xDF646A0103FE6407ULL,
    0xF9D0F5ACEC0051CEULL,
    0x9D21370CA2F5F4C1ULL,
    0xDF646A0103FE6407ULL,
    0xED0130A68185C255ULL,
    0x04A86D33DD89741CULL,
    0xF3,
    0x79,
    0xA6,
    0xA8,
    0x87,
    0xE1,
    0xDF,
    0x40
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseCSalts = {
    {
        {
            0x768A70202D253932ULL, 0x122F679D60ACD2C5ULL, 0x31B1523E6641B269ULL, 0x51A0B51E7155B314ULL, 
            0x1B9ACE59C5E268A2ULL, 0x5AE82452F9E1F967ULL, 0x35AE59A162FFDB2DULL, 0xB0FDB5D7CCCB1542ULL, 
            0x5D255CFF0358FBDCULL, 0x09FD6303D842E4CDULL, 0x415BEFB222A53C56ULL, 0xAD199DB3CB40B680ULL, 
            0x20FC798E960C360BULL, 0xC70FED23509E1569ULL, 0x5D8745EE30265E73ULL, 0x4300858887193F8AULL, 
            0xC4F4A509A786A106ULL, 0xB58EC392DAB147CCULL, 0x26577DFDBC3BFB8FULL, 0xDFC543D848782D45ULL, 
            0x04C3BB077F467791ULL, 0x279DBAEABAA794ABULL, 0x6EC5727F6086BC04ULL, 0xA97F8C1A4ACB8A21ULL, 
            0xC6EB7C922C44F82AULL, 0x47D0C99727F2E6D2ULL, 0x024CB8270414E8DCULL, 0x45B060DE41F55CF0ULL, 
            0xA68A5ADB68AA0C4DULL, 0x23B2F994CF20936CULL, 0xA67D62725C15A3A6ULL, 0xA736CD19FC60E238ULL
        },
        {
            0x25BECEF57C1C7C31ULL, 0x363CF5C89F6DF105ULL, 0xF1A0FAB2D1993879ULL, 0x86D7CC204610FED0ULL, 
            0xAC07860639107EDDULL, 0x971B0CC8E6B9EE0BULL, 0xD2D0E22676AE9F25ULL, 0xF0F070952984C5DDULL, 
            0xDD0D3F088422FADBULL, 0xE7D7FD852F42BC21ULL, 0x220BD3ECF39D3C8BULL, 0x288856B2BF9BC55AULL, 
            0x3E77F621BD4C1D14ULL, 0x4A4B585DB6FB2B8EULL, 0xAC9172089AED8E83ULL, 0xBBC3D5E36651A208ULL, 
            0xE8D535F2FCCA0B13ULL, 0xBC24EDE5EF593AAEULL, 0xC972DF977FAB0C22ULL, 0x7163B25EE257677EULL, 
            0xD051E029A2686593ULL, 0x308B77E4AD8A80EDULL, 0xD65421B5117DF67BULL, 0x2ECE7FEE84F3E8F1ULL, 
            0x59CF80688819238AULL, 0x17AEAA534C16537BULL, 0x40B5860C93619766ULL, 0xA03F43AA92F56659ULL, 
            0x76BF055608A12533ULL, 0x015E44C1451851FFULL, 0x9DFFDFFD844B78E7ULL, 0x2938D0FBD79238E9ULL
        },
        {
            0x1E53D6018BDEFB18ULL, 0xBBABCE9EDFBDA980ULL, 0x6486EDE6234DE429ULL, 0x020FA328B04C7C52ULL, 
            0xB77FED3F4DCEAF8AULL, 0xCE3AACD5B6858BD2ULL, 0x88A770242D681063ULL, 0xA49715D12F202EC7ULL, 
            0x7F40081996635189ULL, 0xD99115EC289D37BEULL, 0x677E683FD540ED41ULL, 0x43F9E7088D816AF0ULL, 
            0xA9EA5DF69F7F9C21ULL, 0x70ADC82B61A72445ULL, 0x57F9DC53DC8BBA91ULL, 0x50751DF605BAB677ULL, 
            0x0FA5CEB8467617AFULL, 0x15BCCD741DB3BA46ULL, 0x42C869D053B6FA31ULL, 0x0AFF2EF1E892E489ULL, 
            0x139499A2FBB43C1AULL, 0x4E81E754552E266CULL, 0xA991BEE7EC1E665EULL, 0xC562378931DF1AABULL, 
            0xC69BC7330F104E30ULL, 0xBBC9046BC13E570CULL, 0x48817D9223D9BAF8ULL, 0x5B98B8FC3F5FA4EBULL, 
            0x2BC536E5C5A0EC79ULL, 0xF69B1C3219FA3DC6ULL, 0xFECA57660B77C606ULL, 0xE16FADCE5298D3D1ULL
        },
        {
            0x488DD49BC3F44498ULL, 0x154331AE48FE4CB0ULL, 0xF3C98F1275947DA3ULL, 0x95984AB9A2B89E52ULL, 
            0xCC124C9AAFE0E2BAULL, 0x5F0E88641ABFD1BDULL, 0x7D1A845343145A03ULL, 0x46EB6E0096F120D5ULL, 
            0x1993F7291940B77BULL, 0x17BB26C81E08EDF6ULL, 0x853D6E2E1EED602DULL, 0xEC90DEDDB007C7BDULL, 
            0x58C84D51466E8306ULL, 0xC551129A83F0C657ULL, 0x881DA909ADB72EF2ULL, 0x7F1FE7881B77E7FCULL, 
            0xD29DCD70D98F90CEULL, 0x7DB53B7C462518CAULL, 0x395113E438603A5CULL, 0xA06F2BA814E30074ULL, 
            0xBC7926C954BC35C9ULL, 0x0BB3F5134BAAA0E3ULL, 0xEFA998B49A90FE3DULL, 0x2BF20981A700FA9BULL, 
            0xF8A5FEEC3932CA2CULL, 0xF28F6788BBB6E59FULL, 0xF070FC6C8545ABA0ULL, 0xD595DB412B43F6D0ULL, 
            0x813117C4729301A5ULL, 0x8DAC4D325033DD7DULL, 0x181FFA70A90C6178ULL, 0xA40637A2E3DEF832ULL
        },
        {
            0xE42665BD0721A8ADULL, 0x39BEFFD618569F30ULL, 0xCC1BE859225991F9ULL, 0x3E90E288F1FAC15FULL, 
            0x72D53F1EED7CD8B9ULL, 0x1C63307B12FEBC62ULL, 0xFE3185EB3476C997ULL, 0x679BD32A1BB3469FULL, 
            0xC58C1448CF9E50DFULL, 0x536A486EF1DE0B93ULL, 0x2774C6B90B051EBDULL, 0x708EDF6B1FFC0EF1ULL, 
            0x2C937F78A308248DULL, 0x62A83CD42F4988CEULL, 0x68F95BD58DCF2B74ULL, 0x3C20EF045463ABB4ULL, 
            0x162C6AD75D998C4BULL, 0xAFDFACDDD91CBAA1ULL, 0x9C39EBC4DFA30EEAULL, 0x248755C898B98EC5ULL, 
            0x2312B7853A666043ULL, 0x9E383E59D7116E9BULL, 0x6FCACF8AE1CD9158ULL, 0x009C296EAE11A0D1ULL, 
            0x8E9F161004A0D40CULL, 0xC48B4FAE845CF689ULL, 0x4EBBF51E9D9E1B53ULL, 0x878B441FCBB2038DULL, 
            0xF614DE7E65DE991BULL, 0xD12D346D6B9B074EULL, 0x87F8725DCA0C3398ULL, 0x8D2897D74FE67CF4ULL
        },
        {
            0x36C08432D18CF9D0ULL, 0xCE8B575E8745A05DULL, 0x337926E0706E2C8DULL, 0xCD9CB979DD997DA1ULL, 
            0xF8E251919E1C985FULL, 0x3F470102B780C269ULL, 0xBE641D40FC0AC4ABULL, 0x9503B71C7BDADF77ULL, 
            0x14FC10674BE0A6C0ULL, 0x2F0007E7295AEAD2ULL, 0x4688FD70259DC18AULL, 0x7D82F8FD49CAFBFBULL, 
            0xEE9B94972ECD1A43ULL, 0x7F50F58DB81BE643ULL, 0x6DE07B2179C24441ULL, 0x04D39F85A0E04C5AULL, 
            0x07CB64F40ECDB2CFULL, 0xDD85C7C457CA5832ULL, 0x507BBDFE745D7657ULL, 0x357CB4DD1A44C8A2ULL, 
            0x59CEDE02DE9E220AULL, 0x98B43AA92F1908DDULL, 0x82B596072396A149ULL, 0x035161B7A91CFBE2ULL, 
            0xF7C237B583442017ULL, 0x5DB933F2118079EAULL, 0xBB8BE3FCCD0D7D91ULL, 0xBCBE32EB7AE0E9DDULL, 
            0x9CEC98575FB22767ULL, 0x6B9439D4EBB34A79ULL, 0xED46E794460424B6ULL, 0x1719D09273575B4CULL
        }
    },
    {
        {
            0x0DF71688F084A65BULL, 0xA13E765275B170FAULL, 0x85A2C7FCF17B117EULL, 0x5187474FFFBC11CEULL, 
            0xB8BDFDA701538EACULL, 0x259332E24689823BULL, 0x0A950B9C2478D63EULL, 0xFB74CD187EB84543ULL, 
            0x188FBCE61E0265ADULL, 0x485F6D91A349B57CULL, 0xCF5632FA527D065DULL, 0x4611B13FF3D837ADULL, 
            0x5AE3471060FE1A8AULL, 0x203B64AEDAA65C97ULL, 0x6BEB69A06E328718ULL, 0x605BD1659F8FE143ULL, 
            0x3B030F9694DE05A0ULL, 0x39DDF4E31A27F49AULL, 0xE83B77B172E541B4ULL, 0x9AB1C1C20BAD4F6EULL, 
            0x42F8D59A12C13368ULL, 0x31A7A14F6F41EEFBULL, 0xBBFEB03566C1D641ULL, 0x634406D0B1DC3ECAULL, 
            0x1407418C14E0B2AEULL, 0x3AAF6920E46E6693ULL, 0x904A2D497D260328ULL, 0xF2EF6AC87531BF68ULL, 
            0xC10AACF528ABCE9EULL, 0x522F4EC97F5A55F7ULL, 0x4ACCEAB63332AF43ULL, 0x5921E3CFC63E8429ULL
        },
        {
            0xD50C6FB2985C168AULL, 0x6B293115D225DA2FULL, 0x59DEE28C95B4A9BFULL, 0x6176C45B0232A54CULL, 
            0x5B5A6A1C5C8D1D07ULL, 0x30EDDE5ECBC7D264ULL, 0x29273D98A29D30D8ULL, 0x20327E1C8F8B4369ULL, 
            0xC6322B96E1D3F270ULL, 0x2486D9C09A6DCC53ULL, 0x174C8086270EA68AULL, 0xA605B8FFE48E9B29ULL, 
            0x910D1322710FF7BDULL, 0x186E748786FDBE64ULL, 0x348063526ED6708BULL, 0xF752B4676D8C2C0FULL, 
            0x859B7511C705EBBFULL, 0x3D8E12CE5A55AD4EULL, 0x8E2BD122D3709B10ULL, 0xC5F9CAA501FCD125ULL, 
            0xB79C56F31B9E7F3DULL, 0x9CDF28A4E62B14BCULL, 0xC8D7910B98AF034CULL, 0x257F6198F9226DB6ULL, 
            0x04A3D35B6700D559ULL, 0xD7ECD08BA4ABA3C2ULL, 0x272E7EE786F3F27DULL, 0xEE5D017DD38E4C0EULL, 
            0xA51506815812000AULL, 0x01911E33F8340B06ULL, 0x4369BDCB4C1F7EC2ULL, 0x7FAF4C9B0E0A6AB5ULL
        },
        {
            0x38E518E83ACAB6A9ULL, 0x004A4D31B6FFFB66ULL, 0x7419A6C1E297DDBCULL, 0xDE07BB8BED046B8EULL, 
            0x267477ADEDFD9A1FULL, 0x5422156FCA84F62FULL, 0xD432E4F79CB11020ULL, 0x389C44080CAD5BC9ULL, 
            0x46E8A6B80AB63480ULL, 0x2D55C249D7567F25ULL, 0xA2BBF0FA1AEC9635ULL, 0x12262B66CAA45DA0ULL, 
            0x5EDEF08EC1B1B6C1ULL, 0x8EB5FE1931212CE3ULL, 0xBB27CCFD62D1305AULL, 0x8250BC7B018B50EAULL, 
            0x5EBE32CBF6DAF464ULL, 0xE6517F3E2BC2BB25ULL, 0x9659D56EC20DE328ULL, 0x8D253B2D453D9B75ULL, 
            0x973CED5AE2157579ULL, 0xBD19E48A59DD4C7AULL, 0xCF72A72F3FE7D044ULL, 0xD0C36A5BD958D762ULL, 
            0xA895D9988F4FC673ULL, 0xC22F9CBA426FCB25ULL, 0xCA519EC423717389ULL, 0x033727C66DB5B643ULL, 
            0x04AFF91BFBFC264DULL, 0x330F2AC8C6594F35ULL, 0x36BD443FB1D877A6ULL, 0xF2C6C18E8E17657BULL
        },
        {
            0x72CFA45AD4D326D5ULL, 0xE832D01D9E061DAFULL, 0xEE8C18610C141F69ULL, 0xB7635A179F31A82CULL, 
            0xB3F80C95C17D1C20ULL, 0x1BAA796BD181AF09ULL, 0x76333244C70657B5ULL, 0xABAC93AE460D5FD6ULL, 
            0x17F6B11F790C05C5ULL, 0xD94954B78064D960ULL, 0xBA3BAFF79009761FULL, 0x5BB9882C8E0977D0ULL, 
            0x9CA2169A5988FC41ULL, 0x14560B1666CB368CULL, 0x91BBCF9E418B698DULL, 0xAD81ED4A9B643E36ULL, 
            0x2FAB58F36970C8E5ULL, 0xBC25989296D991D3ULL, 0xEAE2A775B4474901ULL, 0x91FC30FA0B3ED5CBULL, 
            0x69D2781FAFDCDE8FULL, 0xEB3BF7E2AF03BF28ULL, 0xF9CE6A4D6D2827CCULL, 0xB07FBB7501F262BAULL, 
            0xC2AE9CC425919D7AULL, 0xC6DBA51D94F42CF9ULL, 0xD7C65ABDF5776E1FULL, 0x0E0A72F765372B0FULL, 
            0x684D3F8BC1ED1D3DULL, 0x9588C51D104B1AE6ULL, 0xE8AC171865B3C234ULL, 0x73CB542218DA0BB9ULL
        },
        {
            0xAD4466566421C99EULL, 0x0F8BDE00CBD1F1ABULL, 0x048651F6569FF2ACULL, 0x836F6BC2345C1A00ULL, 
            0x9D1F6ACA67364E37ULL, 0xA3EC37EBAE8EB3BDULL, 0xA07E74A4BF3303C1ULL, 0x762B2E2E86BA3B34ULL, 
            0xE109823D44ACDAE6ULL, 0xBE65588BB29E9B78ULL, 0x8BEB851687E6B714ULL, 0x56CC8E06B8A4B2EFULL, 
            0x72B88419170FED75ULL, 0x7F106F68702344ABULL, 0xFD16B7F660FC73ABULL, 0xB406252F2630D17EULL, 
            0x41BCCE9108758F9BULL, 0xBFB16C5979C408CEULL, 0x8FDB3F0CE8D47F2DULL, 0x86DA7F1EF8BB501CULL, 
            0xCB38E799ABAA1886ULL, 0x3476ADDF482684A4ULL, 0x2386B39039B4A5F4ULL, 0x7C7A27CE776B6697ULL, 
            0x717A3E0976E8B889ULL, 0x4B8414C93BDA8812ULL, 0xB33E1B2C98C61E1EULL, 0x864245C7530E2A55ULL, 
            0xE0ABC8876E3175AFULL, 0xC4824DEA0A86BC47ULL, 0xC6AA0A884630E83BULL, 0x415CB0404CF5BBBAULL
        },
        {
            0x52D9D7A486E4B105ULL, 0x2D2C4C7184855A09ULL, 0xA6F56E7BB5C99BD6ULL, 0xC0E5E529BE5B4051ULL, 
            0x7BBAEFAFB4F35496ULL, 0x2A7822B6E4587DD8ULL, 0xBA39F026C6D68C12ULL, 0x254A1B1BD76DCC43ULL, 
            0x4A63ABA2053004E4ULL, 0xFD46F1724FAFB849ULL, 0xAF877357D9A87BE1ULL, 0x84C8D39C557A3893ULL, 
            0xB902B8553300FB2BULL, 0xD7FD51205C7188C0ULL, 0x0A82772E0FA8854BULL, 0xA4AC97E30D73F800ULL, 
            0x91590CF4337E4137ULL, 0xC2CFA1FBA602F400ULL, 0x0874D83ADBCAAC75ULL, 0xA0D290CE7B9E64A3ULL, 
            0xB6F6A9B102007286ULL, 0xBE884B29C29B4306ULL, 0x0CDC422F60FEE232ULL, 0xAE6F1BD22579CD0CULL, 
            0xD3053B46B25F71F7ULL, 0x26F370A95ED136C9ULL, 0xBF616C046EFFFD84ULL, 0xEA7B32F50E482F59ULL, 
            0xB8382DE3DD8BC86AULL, 0x8F62B54ABA966E7CULL, 0x3FA702C5205C1991ULL, 0x18E018A5D6CBE5F3ULL
        }
    },
    {
        {
            0x007DE6A3E5B2927FULL, 0x44FC1B4195199BA5ULL, 0xC742F571201CBB04ULL, 0x4DE6F632EADA873FULL, 
            0x46DC0D0FD15187A2ULL, 0xB4C38932CCD48D1FULL, 0x7A0C82B5B2A02AD3ULL, 0xFD8D79A1D9E801BFULL, 
            0xFE2277FB48C5496EULL, 0x5E347A9346D45A66ULL, 0x5275C1211A577ED4ULL, 0x3D0EAC4C195E41D5ULL, 
            0xD6BC05CD36371109ULL, 0xEA8AF2D140BBAB9AULL, 0x103D375D1FB11ADBULL, 0x048C81F07473A556ULL, 
            0x54C0DFBCDB564A43ULL, 0x1500E3595DF39A02ULL, 0x91298C84B8AC7E4BULL, 0xEE360AA806867588ULL, 
            0x9A8524DC0701380DULL, 0x1A6E83E1C9D0F5ADULL, 0x0C3FAECDF52AA725ULL, 0x9156E2EC10241C44ULL, 
            0xD726B94570D0AD86ULL, 0xBDFEA15A2AA94FF7ULL, 0x563771CD4E76B395ULL, 0x21E0F34E3705E407ULL, 
            0x925DE4D4540FB945ULL, 0x968E5A3F40D448B5ULL, 0xC105EA923E7CE2B5ULL, 0xCC5ECC466AC70D5AULL
        },
        {
            0x9DFAC3500CD3853EULL, 0xF2D00E0D7C017445ULL, 0x1DFEA7BB6D540898ULL, 0xD2B5D8998FECF65FULL, 
            0x808AA122F4660876ULL, 0x5CFB752F345AC5B0ULL, 0xB87208473926685DULL, 0x7C51296FF72D6DD2ULL, 
            0x88F7A5ECD183B853ULL, 0x8E89BEC37EF21049ULL, 0xC46A419ACA3EBD63ULL, 0x966F1B11CF6A1D12ULL, 
            0x514563D5896E0736ULL, 0xFDB4BE418B1C1276ULL, 0xE24D75F87ED5D1ADULL, 0x97E30CB03C8B8882ULL, 
            0x048D1C7B3D43D189ULL, 0x26F2960FBA5481A0ULL, 0xD3313BBB372FDFE2ULL, 0xE67971FCECB65D0FULL, 
            0x085C4D412AD4C189ULL, 0xD5F17711F118AB3CULL, 0x04EE227A51579B8BULL, 0xC012DBEF62BA4B81ULL, 
            0x41C665CEFB3FFBB8ULL, 0x39DE2820DB9AF5A8ULL, 0x9A8917F36A03F862ULL, 0x1A0FEF11D40393DBULL, 
            0x786F54467B636516ULL, 0x676E84CCB5A8F59DULL, 0x6889FD6B71DD366DULL, 0x508A13384CAFB76FULL
        },
        {
            0x841C63AB64AD999EULL, 0x2566A77B871856D5ULL, 0xCDCD6C03376088C1ULL, 0xE846F185390563D9ULL, 
            0xF760256F46097D1EULL, 0xB12C12655889A91EULL, 0xA0D4C6A26F1F8A64ULL, 0x6DFB789897CB097AULL, 
            0xA43312CF848FB9D3ULL, 0xD823762676397716ULL, 0xFEE241844D36C623ULL, 0x37DBC8CA573E59DAULL, 
            0x3FFCE7691CBB41C0ULL, 0xC616F138EACD53B6ULL, 0x4C0D3D8858BB28C6ULL, 0x64338D8CFAE97B78ULL, 
            0xB0FFE65E1F7BBBBEULL, 0x84BFC5239AAEBFB5ULL, 0x648C582B699B62F6ULL, 0xCBC13F453E1EF1BBULL, 
            0x8C0B107C752E3228ULL, 0x3941E825022CF9A3ULL, 0x5D818FB094CEDB83ULL, 0x4194BF99DC4A3934ULL, 
            0xD99D0CE6C31FB67DULL, 0xB17CE8B56B1888EBULL, 0x0BC793AC7DE8922DULL, 0x4CF951B1DC6A8B3DULL, 
            0x55C2A85179D931D6ULL, 0xB3DFDBC87E6BD50FULL, 0xD9DA010779F77FDAULL, 0xFBEFC671397D87D4ULL
        },
        {
            0xAEE571CC7C3C03E6ULL, 0xE903A019C8963C35ULL, 0xC589E8750F67EF7EULL, 0x44C3275E49962B2BULL, 
            0xDA60A85DC2C02DE1ULL, 0x3BEDB69058AA8D1DULL, 0xFE64B00BF29DDF8FULL, 0x251B5D59E009ED31ULL, 
            0x91CC4D0C2C723EDEULL, 0x43F8631DD5E0BC0DULL, 0xD314A37B72DCEF14ULL, 0x8142D1E512953E7EULL, 
            0x10EDAE84E3A077F2ULL, 0xD2CB21115189DB18ULL, 0x559A47CA5849B781ULL, 0x9D2ACE91697F4B5FULL, 
            0xEE9A388A6E3F5E8AULL, 0x5D1C89CA0DAA39B0ULL, 0x4362E4DEA1CDE490ULL, 0x7EA5D23E6BE724F3ULL, 
            0x6EC4E982BC5EA5D8ULL, 0x5E065FE0C7C15E09ULL, 0xB82D37B2CAC653DAULL, 0xD095E31BECAAF5E4ULL, 
            0x781EC1C2B0315346ULL, 0x5902B25CA4CAC8B2ULL, 0x59AFBF0C99D23EFBULL, 0x5369D93FDE36D49CULL, 
            0x62C1AD9D0DBEDAB4ULL, 0xA9714747A56C74DDULL, 0xA2338E0B0F82435AULL, 0x5FA64BAF1F20F9BCULL
        },
        {
            0x84A6899EDB320A92ULL, 0x72123C049891B2A4ULL, 0x05700A3729C8FFA5ULL, 0xA69ABA8AA138FE93ULL, 
            0x8C0CAA8A1DA9A1E0ULL, 0xDAC9F2C4135F4755ULL, 0xDC57600A6F9A542DULL, 0x1C913541E47A94F5ULL, 
            0xF9DC67C8E0B1A9BEULL, 0xEEC001FE337AD59DULL, 0x4E7B07BA405FB5F3ULL, 0xF630CA85F36E8D34ULL, 
            0x53A301BEDF56832AULL, 0x5F17D63776D4B0E5ULL, 0x7DEAA58D764A7FAFULL, 0xF76740F1A52CE71FULL, 
            0xB517CB666C80724EULL, 0x3F8BC3800FDFAE25ULL, 0x72AD194ACE9056E3ULL, 0xCD5056712614F657ULL, 
            0x0859EB17A214B5EBULL, 0xA3154D1F9B690465ULL, 0xA9A53A16DFC8C390ULL, 0x8A428783D0841EA4ULL, 
            0xF0E6100603A1E6B3ULL, 0x99343B7BDF05A6DCULL, 0x93804F718C306B51ULL, 0x9A77DF424F08B26EULL, 
            0xFB747ED20C29AC48ULL, 0x8F1AF0F35326FBF6ULL, 0x6858EBD79A9222D8ULL, 0x75EE43586AB207E9ULL
        },
        {
            0x65976EFF906DB86CULL, 0x75F47A826607F3C3ULL, 0xC459E49F9FE61C85ULL, 0x6B204D28237F2487ULL, 
            0xA48DABE9ACD9A267ULL, 0x66BF8BD105EEE8DDULL, 0x86EEDD5108B2234AULL, 0x1835929222F8BA59ULL, 
            0xEC89F735D7BA8AFBULL, 0xFD2464F3422CCBBFULL, 0xC5F8AFCD2D75381BULL, 0x3EB752535F3AAE01ULL, 
            0x8B23F266664DA349ULL, 0x9CC7EA023BA050FEULL, 0xF5F3E548FFECF893ULL, 0x8AEF3D7D77FCCD6BULL, 
            0x32EC7434264C177FULL, 0x61AF28D0E74B1088ULL, 0x3F0A956D7E05C479ULL, 0x53467D7E8ADD5B52ULL, 
            0xF3BE68DA9E099049ULL, 0x65C617F1BC99B8A2ULL, 0x5CF87A30BFA9083DULL, 0x0C3FE50906560F1FULL, 
            0x00B8EADE9473DF52ULL, 0xC720772196699B6BULL, 0x2BC78DA62C24E37BULL, 0x408BFD9798CFDB94ULL, 
            0x3C7C4F525BBC9F06ULL, 0x04911B26BF66474AULL, 0x2C8A9F5E284A09FAULL, 0x735C80295CB38ABEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseCConstants = {
    0x2CE02EBADF643D9AULL,
    0x3ED3924336D00946ULL,
    0x9E17E5CFC0E2F17AULL,
    0x2CE02EBADF643D9AULL,
    0x3ED3924336D00946ULL,
    0x9E17E5CFC0E2F17AULL,
    0xC7869F592D90AF1CULL,
    0xE1E09E72A25EA00DULL,
    0xA7,
    0x37,
    0x31,
    0xAF,
    0x99,
    0x70,
    0x42,
    0x68
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseDSalts = {
    {
        {
            0xBFE814334F23EA5BULL, 0xE7124F8726661781ULL, 0x0E6F55C9B3708FECULL, 0x2AD73A09CAA18C8BULL, 
            0xFEDBEB560EEC808FULL, 0x6ADC27791C6EE811ULL, 0x2399469D4EB8628DULL, 0xC23DE24C8A770C96ULL, 
            0x6C2E2EE83380B845ULL, 0x7524D99469D74873ULL, 0xC790B641EB09B923ULL, 0xA8931CA6FFC5C544ULL, 
            0x1A902A99EAC939BAULL, 0x34B8AA82A23AF871ULL, 0x09429F336B1C952AULL, 0x387BBC887483C207ULL, 
            0x5DF42F9492B31C62ULL, 0xC4E577971479D2A0ULL, 0xE734ECBC576FA16BULL, 0x2ED7256513E22BB0ULL, 
            0xF32C833FBF407C38ULL, 0xE712F51C71FF4B09ULL, 0x9688953B969D12ECULL, 0xDE8F6CA84C46BF55ULL, 
            0x4557E78AE01B04F8ULL, 0xC229727F889DE32FULL, 0x3AE99668828CEA6DULL, 0x6E00809B32A6A502ULL, 
            0x6671266F39D78BE1ULL, 0x630E7077EBA3319EULL, 0x645E3A8DEA910166ULL, 0x0EFD7817EF3E4EB3ULL
        },
        {
            0x8FCE52B61D3ACA41ULL, 0x668D67D180226A34ULL, 0x33169F8C7DBCEA15ULL, 0xBF0A532F3018B26BULL, 
            0x5D7ED458A8C11ABFULL, 0x1641F58387073EECULL, 0x0636B032B081A73AULL, 0x423FAD841E78FBEBULL, 
            0x61F6CE996CD14FD1ULL, 0x6F00084D40B8D7B2ULL, 0x84944C2CE57D237BULL, 0xD8BD874746559B1FULL, 
            0xFF9430E1C17C6710ULL, 0x6B951603C47563BEULL, 0x3BF5CDF483A26C8EULL, 0x4189B02BB3463551ULL, 
            0x4D93FC3C5ACFB286ULL, 0x6B2BBB3DA2554027ULL, 0x6E7072581870D50CULL, 0xCD17FDC8E2B2622AULL, 
            0xE066746FA1A30F78ULL, 0x1FF2929F436CAE21ULL, 0x2584B16650D4AD08ULL, 0x88A05C7DB9AA7340ULL, 
            0x507ABF4A3E11FD14ULL, 0x9242867ABF205A9EULL, 0xEEE8153CF9D37CA4ULL, 0xAAC57C2E830CAD45ULL, 
            0x5D18AB8736CC31C6ULL, 0xB3EC37D2FBA24449ULL, 0xF970E8C6BC5C3810ULL, 0x93E18AF61A05EE18ULL
        },
        {
            0xE3C0D0961E036895ULL, 0x3F74E3AB9EE21D0AULL, 0x51FE2C9C10CAFFE3ULL, 0x009C289DCBA38DACULL, 
            0xF9E6BD213E468F93ULL, 0x2A17E1CC2EBB16A6ULL, 0xB6AC1E41B587BCF9ULL, 0xA5A973438CA5F967ULL, 
            0xE29D73056AC62ECBULL, 0xE2B49A523637889BULL, 0x6F629A3E89ED7734ULL, 0xDE53C3996CE45A41ULL, 
            0xDA9140D7A929D730ULL, 0xDF3E1F5EE54ABC8DULL, 0xA0C1B02EA696BE87ULL, 0x4B390646BED657FFULL, 
            0x06026BA2A7A0F880ULL, 0x49AB7D5996B9FD3EULL, 0xF0E396E84439FEF0ULL, 0xBBEC2A01C6220C19ULL, 
            0x5DD6852FD8C4283DULL, 0x303D17A0EBD45E62ULL, 0xE7C1109326CDB9AEULL, 0x7A679D5E363E500EULL, 
            0x6153EDA69AFBA718ULL, 0x076B6299371A737CULL, 0xA6D6E58C6FD2CDDEULL, 0xF5DB31A008DE52A7ULL, 
            0x5CD397F4E80ED136ULL, 0xFC4ED64872804CACULL, 0x06D59B6017C5DFA6ULL, 0x8EE89B7134629E0DULL
        },
        {
            0xE4998907A2509F99ULL, 0xB7D150D854F6DBDCULL, 0xD13A7D3DEA4C4CC6ULL, 0xC9D8D94ADD4DC3C9ULL, 
            0x3DF01CCAE4E65717ULL, 0x10A0735162E24108ULL, 0x1B892E9F23B22552ULL, 0x2B8973F24B483221ULL, 
            0x45E5EB73284EACCAULL, 0x7114B993AD9C6C79ULL, 0xECEDFEC285C7BC1AULL, 0x5FAF982466B9F0E1ULL, 
            0xF39FA6A74AE541E2ULL, 0xDBF0218DBBC57547ULL, 0x9FDCB0367B4B7EB8ULL, 0xEC57B9F4F998F39BULL, 
            0xB59A5241E0C784EEULL, 0x2D2F2721EE2BED7EULL, 0x5748FD61CC6E15BBULL, 0xCC24E8CE0CE3DA24ULL, 
            0xB8AE6809D830128EULL, 0x42F6C5559D7D1676ULL, 0xDA694DB37537E1E5ULL, 0x8296545A7DD69711ULL, 
            0xA3CD772A5B9BCD3DULL, 0x42E05603D9DB8E6AULL, 0x18A3AC350C356814ULL, 0x128193D92EFD496FULL, 
            0xDDE96503916DD61BULL, 0xB6172495ED4E2310ULL, 0x345F62C8EFB93F1DULL, 0x110C88623F4DF6E6ULL
        },
        {
            0x6C808BC2615BE799ULL, 0x2FE71F9DDA180FAEULL, 0x8F04340785DDC72BULL, 0x87B6B6D4A8735336ULL, 
            0x9D269861C0B6DBF4ULL, 0xAB514FE927555F3AULL, 0xA346D5F626884836ULL, 0xDAD2D7E6AC4FB1E7ULL, 
            0xE347379D42E1E29DULL, 0x11CB7C21AAB4ABEEULL, 0xBA425AFBC6161465ULL, 0xE87BEF5517C702D3ULL, 
            0x57EF7B4D365D677DULL, 0xAB6B04B1592F8531ULL, 0xD83D4FCDC378D60BULL, 0x492AB05FD74504DDULL, 
            0x086E243FB43D9084ULL, 0xC7FC460F5785B64FULL, 0x709DABA4205AF0B0ULL, 0x79D259075A5DB1ACULL, 
            0x51B5985340B1E3F7ULL, 0xFF8274A8C7100476ULL, 0x5FD41B2AAA1316F3ULL, 0x1F10AFC06A398151ULL, 
            0x75F104A1A13AE515ULL, 0xC3A7F21F5B425C24ULL, 0xE080A653CA4090F6ULL, 0xAC5D714B492EA571ULL, 
            0x2923E543CEC2C022ULL, 0x2FEA48D3AD2CC2CEULL, 0xE9C1521987B38794ULL, 0x8A8BF222F607B7A3ULL
        },
        {
            0x45AA1365DB8192D4ULL, 0xE397DDA933F171F3ULL, 0x6B26215CA7555738ULL, 0x9B531D4EF030D4ABULL, 
            0xB994799357517470ULL, 0x43F958085F13A56AULL, 0x3CF514160A4D8D98ULL, 0x4607708E2F4C7DB7ULL, 
            0x541FC703DC7F5014ULL, 0x0B2349AA01297B70ULL, 0x8EC01AE2D1571C27ULL, 0x85EEB97AF1E2BCD8ULL, 
            0xC2961C5A13EC8D86ULL, 0x65AD48054750E960ULL, 0x72D560BF512E49DAULL, 0x1222CD11B83071E5ULL, 
            0x7254875A0D3E8889ULL, 0xA5B1C06963E8AC66ULL, 0x8252AEF1FCC9D0EBULL, 0xA7FE3D89599889A3ULL, 
            0xAC68F4B60137B606ULL, 0x15F2B13864DDBDADULL, 0xE991ED09C13F05B8ULL, 0xB3814E9D2DD507A0ULL, 
            0xDEA097A1761547B5ULL, 0x8B6958571864E7EAULL, 0xA9EFD6535978C8ECULL, 0xEFAE1C4F3B2D04EEULL, 
            0xF9D475095BCA14ACULL, 0x485FA1F49D779E3CULL, 0xA8954B520042C5D6ULL, 0x59C5B1812424569DULL
        }
    },
    {
        {
            0x0782A0E4124666C1ULL, 0x84458008A7A8C315ULL, 0xAF39C6A7EC345122ULL, 0x8A30EF72548824F5ULL, 
            0xB1458F30CDC1B5D2ULL, 0xCE748418CD81D18AULL, 0xDBD0E2BA0A79E35AULL, 0xC8E846353E1F5DFFULL, 
            0xAE9943DF5A2FAF6CULL, 0xC6CA2B6B12BCFAF4ULL, 0x3F076630ED1F009BULL, 0x463162BA57846997ULL, 
            0x71FDB68219F021E2ULL, 0x07C741D7E2453801ULL, 0x9A3A11F962F0B4B1ULL, 0x99F902397E3D68FCULL, 
            0x6A43A75C6BA1BB63ULL, 0xB950935AE90CD353ULL, 0x55CCC14627891C9DULL, 0x0C719FB997E8E772ULL, 
            0xDB202791340D405FULL, 0x3AB5F50FDC539EE4ULL, 0xA306B569900967F8ULL, 0x6F79303A96411774ULL, 
            0x697C370CCA27A33DULL, 0x31FDE688D942E8DCULL, 0xF81624B725D9C0BAULL, 0xA6ED61E35BB23479ULL, 
            0x236495A5F943F92BULL, 0x2CFF1C953CE5C8E1ULL, 0xF2EBA35160320A23ULL, 0x15AA3C1D6C1F5D17ULL
        },
        {
            0x7A093844BD84E0BFULL, 0x150DBEB299C8C996ULL, 0xBCB0D133632A3A57ULL, 0xBED1E04F5C93064EULL, 
            0x5102A0808A380657ULL, 0xF70E610666922E07ULL, 0x293ACAF1C897033DULL, 0x960040A90D2A2FFEULL, 
            0x466F89F5060C1689ULL, 0xC8276071A2E6C66BULL, 0x7EEBBB1ECB192658ULL, 0x49B87AC6071EC3F6ULL, 
            0xE11132F1EF4AE2E0ULL, 0x8F00E50CA5D95957ULL, 0xE53ABB5711861A2EULL, 0x789F66BEACC16F0DULL, 
            0x5C23F5DE566B43C5ULL, 0x2F36733A16B3F5CCULL, 0x6BB7437589B0089EULL, 0x16FE1B02D9B5944FULL, 
            0xE8D445DD18186F23ULL, 0x7604BD74C56719D5ULL, 0x158AC8B50E2F9687ULL, 0x9CE025A22E93275CULL, 
            0x126A6FB954EC092FULL, 0xEBCDC53243EA7CB4ULL, 0xBBBA87B08BB7CBDCULL, 0x2F0B444C1B4E7DA2ULL, 
            0x635BC034C08F109AULL, 0x3DDF169C872A0905ULL, 0xF4D261DBCCEB1C82ULL, 0x7A9425544577F715ULL
        },
        {
            0xDCED783728C90E6CULL, 0x7D3CA5DE30461C4BULL, 0x7D46327758F50D25ULL, 0xCA8337F8E858CC49ULL, 
            0xAC4BF3E2E553B5C8ULL, 0x00ADB75302A252F3ULL, 0x4EE60ED5FC692FD2ULL, 0x449E3F446B064597ULL, 
            0x572E0F4989915BEBULL, 0x2A53B843EF848C54ULL, 0xF9ED09FFB00BC0ADULL, 0x5FA8841F8FC52437ULL, 
            0x8F7EA79E7EB2F247ULL, 0x9381126FC39EFE19ULL, 0xC044B5CADF4AA482ULL, 0xC73E8AA17BF2209DULL, 
            0xE727C8B7412B4DFCULL, 0xC1C4696208915F56ULL, 0x5B4D6DC0893D54CFULL, 0x96CE59B170C6FAD2ULL, 
            0xF651C6C6F39299F0ULL, 0xD44AF90D9C8FA3B3ULL, 0xA94E334D939DE104ULL, 0x4725684471F9D02BULL, 
            0x399C1A9C60223A71ULL, 0x627F2E57B119DC4CULL, 0xF8BCB6BF85AD865BULL, 0x1240BEFDE37D1B1FULL, 
            0x10DCD5D27CE085C9ULL, 0x6CAC47F89508F184ULL, 0x427322099509EC41ULL, 0xF07A60FBCADC780CULL
        },
        {
            0x32D31C3B82022683ULL, 0x339AB366EA49EBAAULL, 0x1BCC6F937CF395C4ULL, 0x64DD397B2BC7BF3BULL, 
            0x797904A48D109994ULL, 0x7DFA2A42B3127BD1ULL, 0xB3AB43AC5FE55753ULL, 0x20C5FAC4414C59C4ULL, 
            0x7D67F7BA11747461ULL, 0x2A244E131B352AD6ULL, 0x2DD41E0E6260A7E4ULL, 0xB121DA23131E5A19ULL, 
            0x8B2FD6EAE15F8E20ULL, 0x932D0E45E5C09EB3ULL, 0xE4CF8372E9EB63ADULL, 0xFDDCCD1C73FCEBBAULL, 
            0xB8008274DE224B3CULL, 0x909A8AD80D5D1A5FULL, 0x9BAEC9DFA8F394CFULL, 0x65C10F280552D927ULL, 
            0x5A03461222A49684ULL, 0x400F07352766DB91ULL, 0xF4DCD2643031DEAFULL, 0x85ACCFC417852754ULL, 
            0xCAE9BCDA89F36645ULL, 0x1F42380E79C9B591ULL, 0xF67E0A9E87AF661AULL, 0x982E840F92D3A845ULL, 
            0xFDD580F74784BC08ULL, 0x4D129B349760E9CBULL, 0xB911418AB696E477ULL, 0xCADB8DCCAFEC9EBDULL
        },
        {
            0x02F15684FA05D48AULL, 0x4BBA67E0C5C719C0ULL, 0x1CAC32D1D5483FBBULL, 0xBD7DB41D2D5CAEA1ULL, 
            0x5AB9EF2F667D4348ULL, 0xE4CAC7A68BD3F7F9ULL, 0xE7E7EE19EF2A74FCULL, 0xAACAB511B637278EULL, 
            0x84A93E46D943AE99ULL, 0xB79CA8CD8ED19A05ULL, 0x3DEA95390D474A9DULL, 0x3C4089E87E3CD6BFULL, 
            0x6B470F454323B3D2ULL, 0xD83DF8CD650FD0B9ULL, 0x57242AE09C314149ULL, 0xFCAF7487C94753BFULL, 
            0xCF12179AACB82531ULL, 0x6E6266D2B15CA956ULL, 0x50DB7C0499B2323CULL, 0x1468508313F781E6ULL, 
            0xB82CEFA45396A56CULL, 0x3554A45D1FAA9486ULL, 0xA18F4A92FD90337EULL, 0xC14D968049457EBCULL, 
            0x036E88755CF18B6CULL, 0xFA6F0F6C932904A4ULL, 0x1DE45C30311E36A5ULL, 0xC83D6CEDCADD0592ULL, 
            0x7DA9864807C53AE5ULL, 0xE3851B4CEE1211E8ULL, 0x251180212E571999ULL, 0x01FA19844EABB425ULL
        },
        {
            0x3D18BD526D36D61EULL, 0x2920C2519903D9F0ULL, 0x50C4CC75BF0A4D9EULL, 0xFB052A4534301648ULL, 
            0x3255AA4EA55ED4F1ULL, 0xC5CB554F96BDF128ULL, 0xC106813FFC62F206ULL, 0x4447FFD792415795ULL, 
            0xEC21FC00F2190992ULL, 0x4AB781AABD8CC52EULL, 0xB8B3F1806D181CCDULL, 0x615A05D8E2C9C1DAULL, 
            0x9B58BA4A4ED8E408ULL, 0x2F691855340E87ACULL, 0xBD2F11A33DE6B812ULL, 0x2173AD670D22D2F8ULL, 
            0x92D50D0312E99ADCULL, 0x8F17AA1109DB7E84ULL, 0xF480842041E99D48ULL, 0xE610DD0152675E00ULL, 
            0xF39B87D3C1D93DD9ULL, 0x53BF1B771BE1D633ULL, 0xC1F199709D171A42ULL, 0x04E8E4365AAFEBBEULL, 
            0x670C8D5661A4DDAAULL, 0x82B6352FA6930467ULL, 0xFEEAAB04174DE527ULL, 0x2B6C350AF4B96417ULL, 
            0xD6C6A102E99FACA9ULL, 0x4E8F11BCC048A22CULL, 0x80DD10307477A22CULL, 0x609ECC148BD3FAD4ULL
        }
    },
    {
        {
            0x4C2914053536AC94ULL, 0x15B9F7AFCD23D5D1ULL, 0xC09D2FA5AC23D896ULL, 0x6FAB015F37B31C31ULL, 
            0xBD6FD08025EDA3D8ULL, 0x2A1733DBCE4A732BULL, 0xBB58B04E4678B7BFULL, 0x0DE03F3ABEF59B33ULL, 
            0x4A3C848F610126E8ULL, 0x635804AEA63D7501ULL, 0x922318682BA64D84ULL, 0xA0433A7B83B52BBBULL, 
            0xBB124003E4AAD903ULL, 0xAD757AE357D5561BULL, 0x9A6489C68FCA6979ULL, 0xFF581299E5C6AACAULL, 
            0x0ACCA35197E5D431ULL, 0x66A2675DAFCF709DULL, 0x0984BF2AAA369581ULL, 0x7D829F7C7045B3A7ULL, 
            0x94F79FC762AB90BEULL, 0x4B0C06435E69D2ADULL, 0x6E6F4DDB95EBD655ULL, 0xB679367A913734E2ULL, 
            0xA6A4462966F7683BULL, 0x54884B7C654AEBF2ULL, 0x9349476B50742AB0ULL, 0x0D0D1E2E17DACDC7ULL, 
            0x229C5FEF0AB83E77ULL, 0x4697993B05FD1D19ULL, 0x1FFF4DFBCD05B06AULL, 0x58842CDA32452831ULL
        },
        {
            0x5834C4F5F6CF7654ULL, 0x8B42C6D584CFDEC2ULL, 0x5D3CD6EEF9D3A4E4ULL, 0xDA5B9DBB311056F6ULL, 
            0xD4EBBE451DE92B12ULL, 0x42F9175C7079E6C4ULL, 0x1597217A661FD847ULL, 0xA23DEAE71DA33B2FULL, 
            0x7F6CB39B99768DA9ULL, 0x4768E1BB578C4F37ULL, 0x4DFCC200D72F7B56ULL, 0x415572FA9B5A6720ULL, 
            0x3E84912CD60CEBD0ULL, 0x3DDB26A85E717314ULL, 0x5E2766CA1B5FD5DDULL, 0xE2A4022EC22781BDULL, 
            0xFC685ACCBA846514ULL, 0xD0C75F3BEF52EFF7ULL, 0xABA47F9B83677E08ULL, 0x60420D6C4FE7BAF1ULL, 
            0x618C55E8E5FB965AULL, 0xC0B70519EB4A99C3ULL, 0x12E70419191B5275ULL, 0x6739E6C1DE7B9C2BULL, 
            0xFFAA61CD1F1B26FBULL, 0x695FCA11FC38E8B3ULL, 0xF8E969176C3B058AULL, 0x5780EC205D20FFBDULL, 
            0x21F7878757A7EDEBULL, 0x63B357BFE95F23F7ULL, 0x22A7A86D5246EB5DULL, 0x241133BED55EB998ULL
        },
        {
            0x54C6E31C6C220286ULL, 0x4D2F8EE4F753CA25ULL, 0xF12BC2E1FBCC1566ULL, 0xB8C1EDEFBE49FB00ULL, 
            0xAC175F9F9B20AA40ULL, 0x0592F2F17EF0962CULL, 0x8EBC55F77204A381ULL, 0x155EC7A25A34E605ULL, 
            0x4764E46F81200707ULL, 0x360EB77146CD59FDULL, 0x7E1C426D7A7EBCE6ULL, 0xC3ED8E67E0A4374FULL, 
            0x8822DA85F142077AULL, 0x8E25DD02842A7394ULL, 0x79B7D029A8985118ULL, 0xC439980B911505F5ULL, 
            0x1EF8248A6E19C786ULL, 0x4C102DF489144150ULL, 0x28470356293EB0FCULL, 0xFD9E7D115BEE6536ULL, 
            0xB182035E19C33ED7ULL, 0xF24E0181D951E546ULL, 0x1C4F3CC62DFD6B7AULL, 0x70D93E5482B7BF40ULL, 
            0xE4D27592D03A450BULL, 0x69CF3D899D04A498ULL, 0xB5A2F5BFD4A8B27CULL, 0x4ADD2A2B59FDF7CAULL, 
            0x2AA3C6E328603490ULL, 0x3E51AE7A9FB7297DULL, 0x21722AC232320506ULL, 0xCD6EF85C17691AB0ULL
        },
        {
            0x97754DFA5839C146ULL, 0x4B5AEE15D1DC0B2CULL, 0xC55E76DD97E29257ULL, 0xEEE35EEE1E9F6D26ULL, 
            0x31614FD166903902ULL, 0xC64BD1C61A966F59ULL, 0xAB0C06F77675BE6FULL, 0x96F65DBAB3754C11ULL, 
            0x4EBBFE83BD3F5114ULL, 0x9A962670ABA1B13FULL, 0xDC06B54D4E902EB2ULL, 0x9E093A4662D31F6AULL, 
            0xA505D950F151795DULL, 0xBDF6DBCBD5C3AF0CULL, 0x70BBCBB0ADC8505DULL, 0xD716D62B631876EBULL, 
            0x1B5F8DE7A4CCF066ULL, 0x68795A36FE9C1F74ULL, 0xD95C11143D808CFDULL, 0x73D78835B41BA80BULL, 
            0x7266C957155F004DULL, 0x84B74A308C744ACFULL, 0xB2EF58562CCFA288ULL, 0x36462DA65CD85DB5ULL, 
            0xA2B10C810F8C5F1FULL, 0x305FD480E717BA8EULL, 0x3061D267FB628C2CULL, 0xD1E1670733BE776CULL, 
            0x896F5230A19BB390ULL, 0x01F8FCA7B468F69FULL, 0x2A70D3785B135030ULL, 0x902A228DA698962CULL
        },
        {
            0x8C27BE9535B6C15FULL, 0xDB837386674E5BBAULL, 0xDE73C395E62D613BULL, 0x95BB34B3689A1477ULL, 
            0xF95F531AA4D4D6E6ULL, 0x406244DA3D27FC15ULL, 0xBAAC810B0AEB0EF4ULL, 0x54566031221E6864ULL, 
            0xAE2739B5AEA65454ULL, 0xCDB9127087CB509CULL, 0xF001F7BCFBE19567ULL, 0xAF23EFF2CCCD505EULL, 
            0x35AFE11D27C66EFFULL, 0x18AC831D7397C6C8ULL, 0x9B3998CA2F729E44ULL, 0x6D129B9C04D593CBULL, 
            0xA556A9B49DC13E21ULL, 0x4CB7B38732D6AD09ULL, 0x1D2FDE8359A9A0CCULL, 0x1CFED64491C7BA5FULL, 
            0x203662C021B904CBULL, 0x55958F8A0F7556A8ULL, 0x0DBA47B383D3396FULL, 0x8FE7E14950DFAD33ULL, 
            0x31958EE2F68BE29DULL, 0xBCFCFD760710FB6EULL, 0x2ADEF28026E03500ULL, 0xEFEECC67AD9DE254ULL, 
            0x636FFD12DFBB32F1ULL, 0xC5564D250422C1E9ULL, 0x14281A9741DEA123ULL, 0x1C7AE73573ACF52BULL
        },
        {
            0x20A8646281534390ULL, 0x30A9FCC396A34A0FULL, 0x0232221E5AF66D13ULL, 0x0E51A66797F85A8BULL, 
            0x8DD3FFAC5CA6C2A2ULL, 0x2FC377BD39E2A912ULL, 0x77490D49587E5EE1ULL, 0x05F0444E55461C0BULL, 
            0x3500F2D394BE89B0ULL, 0x8748A253DC393B09ULL, 0x8AA2F4AF255E4CFBULL, 0x94DEF754C104491AULL, 
            0xA8274E163EE7FD79ULL, 0xA8FCE175179F7B5DULL, 0x9A019A7EEEA2BA09ULL, 0x5F5B6511DC888BACULL, 
            0xC8D4B8DA29E11CC0ULL, 0xA53AFCA6FDA7649AULL, 0xA7A60ADBF82E4A35ULL, 0xF4F679E4B6502061ULL, 
            0x7662A0001D481198ULL, 0x1B29D056685E19F9ULL, 0x4C535DBDC2C8EB00ULL, 0xE64ED64136E2B731ULL, 
            0x8C975DB23CFD604FULL, 0x5E79B68055FB879BULL, 0xC796670E8611A9D8ULL, 0xFA4E0C92D74F58E2ULL, 
            0x7D38212AA2F1D598ULL, 0x5FA7AEBDF26CDDE9ULL, 0x315FA8525BD44629ULL, 0x63B3204CF4F45E49ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseDConstants = {
    0x5990F50E6A241069ULL,
    0x25659C13397F4C77ULL,
    0x14FEA421F6969CBBULL,
    0x5990F50E6A241069ULL,
    0x25659C13397F4C77ULL,
    0x14FEA421F6969CBBULL,
    0x72C29C0ADA6EDF60ULL,
    0xDD918ACF4C282C04ULL,
    0x7F,
    0x22,
    0xD5,
    0xCF,
    0xD9,
    0xDC,
    0xE2,
    0xEF
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseESalts = {
    {
        {
            0xDF426FC86128403AULL, 0xA3D59EB283A45D04ULL, 0xB160F5BE554D709BULL, 0x8F531C3198984F87ULL, 
            0xB5BF842F3C86B1EDULL, 0x8A43390A545FCB15ULL, 0xBC27024CBBEA54F1ULL, 0x6D016BAC13675494ULL, 
            0x21A6DEAB882AAE82ULL, 0xBF76C57D591D0E83ULL, 0xE99F2C42A5F8B69AULL, 0x6B34B172CC5D67A9ULL, 
            0xE8C33AFCE39ADB19ULL, 0x4C92D19FBB0F9514ULL, 0xFF43414325F7035DULL, 0x7AADE0195D1CEFB8ULL, 
            0x6D8443FB35391159ULL, 0xCDDC19C6003D37A8ULL, 0xE92A5AA74A0AF87CULL, 0x2603DA1541550D00ULL, 
            0x6956095AD4DC96CEULL, 0x655343C6985BC838ULL, 0x1BEE9D8FB28AA5E5ULL, 0x2CFA8DD19900FEC0ULL, 
            0xD5B66547B500AF91ULL, 0xFC358275666275B4ULL, 0xFAD0ADE7FE75931AULL, 0x4ABB0E672122153CULL, 
            0xC6AAB13659A7B7AEULL, 0x7CB67E5AE2537F01ULL, 0x4B03E0F046733766ULL, 0x669EFF8AEFB9281AULL
        },
        {
            0x38F104B4F43E7AD2ULL, 0x3C2909CE201709F9ULL, 0x3F337E58B1FD4B3EULL, 0x2EC1C9A394483790ULL, 
            0xDA26FE8195A59895ULL, 0x64107E2F9AFE9CC9ULL, 0x165898B1839867E6ULL, 0x101E18951A85B225ULL, 
            0x9AEA958D91299289ULL, 0xDA65493C2EEDDAC6ULL, 0x3BB2B414E0907D1CULL, 0x9C41A0DF85866296ULL, 
            0x0C63344F7F1C0499ULL, 0x0D5F8880E7930A27ULL, 0x6B474BA7E8BC781EULL, 0xDC34B7C9DAEA0610ULL, 
            0xBDC0B5BD09B28616ULL, 0xE0522210D786252CULL, 0x1FEF8BA7E6E107CFULL, 0xC9ED264B80281770ULL, 
            0xD515DDD75ACE6EC2ULL, 0xFBD96E582315CAA3ULL, 0xAE317A7F9BE05B28ULL, 0x11E9F0D1265E352BULL, 
            0x2CB0AD4EE7796280ULL, 0x4C069DEC387AE635ULL, 0x652E6152C606F7DDULL, 0xAACE8385E739E9CDULL, 
            0x4F61B44F6364C988ULL, 0x1F787781FE85E03DULL, 0x9E072671AB2417F4ULL, 0xE5A8C3C3E8DBCEFAULL
        },
        {
            0xAA7B2078641AF287ULL, 0xB78C48F26F9CD91CULL, 0x5BD817B794D75E01ULL, 0x0082C72636C14142ULL, 
            0x9602DE67EE8EE84AULL, 0x52BC16CE533A6A72ULL, 0x68FA75632A57DDFAULL, 0xE617B9905E312DA6ULL, 
            0x3C4DC5B6328DAE8BULL, 0x98C66898F1458393ULL, 0xEA5614334218C1E4ULL, 0xBC5C6504889261C3ULL, 
            0x37487768E75C733FULL, 0x01817C89EB55B7DAULL, 0x325FE7C532637876ULL, 0x60D7EB7DDF6FCF1EULL, 
            0xC9FBA6E79B020A35ULL, 0xC8B7BB7BCBA0D080ULL, 0xB936450D2A00468AULL, 0x49C3B05CFF0D970AULL, 
            0x3AC8DF302FD3012AULL, 0xC9B40D5325D629CDULL, 0xDA5C672C2A84D34BULL, 0x6E19B474E3E34A97ULL, 
            0x8FAA56422682D426ULL, 0xE5F8F2EAD1D7952FULL, 0xE3A1B11A90240214ULL, 0x3C89592FC680DBA2ULL, 
            0xFAAE24352E31352BULL, 0xC5A7044C7B59BBECULL, 0x1DD71472833512A1ULL, 0x124E68C86FEE0142ULL
        },
        {
            0x8D60D337B67A0205ULL, 0x44DB546FF72B7079ULL, 0x9D4A052835335198ULL, 0xAA3F8A59948D72B8ULL, 
            0x2606471939B84E6AULL, 0x49AB9EA6C336BC27ULL, 0x06A944E69E150AACULL, 0xE733346C7F37D59EULL, 
            0xF5D9E7D4DBB4FD2CULL, 0x9710E6653A65668FULL, 0x603BBFBF1E193749ULL, 0xED9C0B772561449CULL, 
            0x7D22633BE76F8570ULL, 0x3841E15FCBF27985ULL, 0x201790563D216346ULL, 0xC6926B1F557C7B4CULL, 
            0x5B1BD77CF6D76CC1ULL, 0x893A69A71BAA1E63ULL, 0x9B8DF344A8232DA7ULL, 0xC9F68EE6FE492A2EULL, 
            0xCFB346C761E3CF99ULL, 0x09186641BBEEE849ULL, 0x4F8F31096EB993ADULL, 0xB67E873D83129F4FULL, 
            0xE9E223C37A87DE83ULL, 0x7BECDF5B21BDABC2ULL, 0x35B0C260EF0C8DBDULL, 0x9CD6338C844BAE18ULL, 
            0xA6538472EF181FAFULL, 0x11976C95CBA8E29DULL, 0x574BE0A5A7C5ABE0ULL, 0x8D7CD7C91B3EB1EAULL
        },
        {
            0x2A4DD7D3110001AEULL, 0xEED7B8A3FC1C9504ULL, 0x32346642F41E529FULL, 0xCD9D4C2EC4505A1DULL, 
            0xDAF444870C4C5AD6ULL, 0xE5AFB38896622C63ULL, 0x842FB364BD179234ULL, 0x1F2AB37689C3EF66ULL, 
            0x8EB582260402A6E9ULL, 0xD8AA5B671EEDE80EULL, 0x08A1353F60702C80ULL, 0xF741780A0BA02366ULL, 
            0x432CE181D2CBE986ULL, 0x2C3E848E85D53533ULL, 0x6FB7B5B8B578CADFULL, 0x5269141799FCC2A6ULL, 
            0xFBB37CB0E6ABDF06ULL, 0x743D9432CDD9DBB1ULL, 0x7103863EB6EB0615ULL, 0x194033BB6333208FULL, 
            0xA02C9E60139AA3BAULL, 0xA6CDA075D99A7B22ULL, 0x800F368CBD62CBDFULL, 0x0A9A58A1E4ECD561ULL, 
            0x53DAD172EEFB1285ULL, 0xCFE5969BED1EFE13ULL, 0x678ABF0E2353985CULL, 0x96A3C03E0BDBC039ULL, 
            0xD0A537C8CD57CC85ULL, 0xEFAA3B9083DF51C3ULL, 0xD83E4F68E224F453ULL, 0x36D36FF977C2F7F4ULL
        },
        {
            0x02253921C19E07D9ULL, 0x2CC98FB5E703CAFAULL, 0xD35C9108A5ABAE21ULL, 0xBE44D9F373D0F6DDULL, 
            0xB7ED17D20CB3F4FCULL, 0x37A85301326187AEULL, 0x46E9BFD3A4835B03ULL, 0x915822C129AF0C4DULL, 
            0xE39D5D40AC75C190ULL, 0x7B7B14A9C37240D6ULL, 0x92051AC230A81E84ULL, 0x6AE95918174AFC40ULL, 
            0x5B2F44D40C4944CCULL, 0xD08AB0D5ADEF3BE4ULL, 0x6442FEBEFDD60563ULL, 0x5BD84831D4EFB449ULL, 
            0x24E8EE170E5AD51FULL, 0x98E12BD97BD1E52FULL, 0x711A2131EBF0CD89ULL, 0xB949588BD71D92E2ULL, 
            0xA9B75D26CB326156ULL, 0xD6DF880E3462A713ULL, 0x2297822D79C00492ULL, 0xEAA38A91906EBD31ULL, 
            0x68EE848D04F26E6AULL, 0x06BEA10013D733D9ULL, 0xA2E17CF6476A47A0ULL, 0x711ADF9B531BF28EULL, 
            0xB68B64FEC471E8C6ULL, 0x43D013BA2999E03EULL, 0xE4CA5D4EFE37C78AULL, 0x2631987366E66D75ULL
        }
    },
    {
        {
            0x82AFF9F43D13912EULL, 0x5C039AD1441EB772ULL, 0x8BE403514D3E81F6ULL, 0x13565FA7879E5BFBULL, 
            0x31C700E4AFE4512FULL, 0x92218E719268F34CULL, 0xFCC7A9DE830DACD7ULL, 0x031D3AC655842005ULL, 
            0xB20067640DC504E9ULL, 0x154633388FEF1AA2ULL, 0xEAF1B4A4C266FB2CULL, 0xAC90706E1B7347B3ULL, 
            0x7D14437651A26088ULL, 0x0FD4BF580797FCC0ULL, 0xA193666775ABEECCULL, 0x4300CD2A4CE762A3ULL, 
            0xF9875D0690DC987EULL, 0xA4BAF0C33A2CC993ULL, 0xC5A2EF6E8DAFC4F9ULL, 0xCB1AC913DAA3EF0EULL, 
            0xEDC0E1458C3D853EULL, 0x70D214D006BAD4F1ULL, 0x8CC2B6039BA1FE01ULL, 0x1D336C2314A7C617ULL, 
            0x7134A5F45C19C4BDULL, 0xCA20860C6CA52EE1ULL, 0x42AEFE9BB5CDDA4EULL, 0x1623B2AB7369AA5EULL, 
            0x2F4E5E8860F11783ULL, 0x90BE4EA704C19C88ULL, 0x0A5CE8FDBF666398ULL, 0x47E43DAD8B6E7F9DULL
        },
        {
            0xBE336D7B1F0FCD88ULL, 0x581DA1AE6D7442EFULL, 0xB9715E05A3B49D89ULL, 0xB2F8835C7CC5BFACULL, 
            0xDCB1B37814A737F6ULL, 0xEE75B05438ED6755ULL, 0x7C9B1BE27506E517ULL, 0x79BB778877F9EE81ULL, 
            0xF6FE8E58AA55133DULL, 0x52F5F91385138714ULL, 0x58262CD189206DFDULL, 0xE970BD6986E913CCULL, 
            0x9756734CDE8E0D73ULL, 0x9B33453C876A5DD3ULL, 0x4F6707239D2D7DD7ULL, 0x2932608EFB8E5AAAULL, 
            0x4DE449234CEFC290ULL, 0x36F493FBD08E74FEULL, 0x076C007F5F9DB663ULL, 0xF77AD0FE8D1BDE2BULL, 
            0xB23E045D11CBD6DBULL, 0x5B9A9D0D4CFB4750ULL, 0x55EE41AAEBC52F31ULL, 0x0A65A82D46E5D11FULL, 
            0x279A33246F696825ULL, 0xEF6B54ABE90AB738ULL, 0x254C4F321E343B40ULL, 0x4B24B6C51D2095B9ULL, 
            0x7A44BD3F4910B632ULL, 0x310A2A05112591AAULL, 0xF83EBE216C826C13ULL, 0xF217B1815D6EB3C4ULL
        },
        {
            0x31191E3A11B5128EULL, 0x0B75644F4BBE4675ULL, 0x0ED16C746D3D47F1ULL, 0xAD80204EC6E33695ULL, 
            0x87E4577E11AE46CBULL, 0xC5285C066C59925FULL, 0x25973756580F4DDBULL, 0x9AC1D493B1CEF820ULL, 
            0xE7764009365BA8DBULL, 0x91C3B6104FD10627ULL, 0x8FD8023106642BA4ULL, 0x0361CA22B5B20BADULL, 
            0xC4E0D1465B036E11ULL, 0xC8AFF4F002DC4720ULL, 0x305A98B1E736CECDULL, 0x08262A0F19524F82ULL, 
            0x97BAA6575C2FEEA3ULL, 0x06949E1A6693DC8AULL, 0xED714FF6ABF3C1E6ULL, 0x714CCC8D5A1C9BA6ULL, 
            0xC220703428CE0706ULL, 0xEFBF8B6A1AD3B1DDULL, 0x4BDE6C99F723659DULL, 0xC007657032881BABULL, 
            0xFDED0908D6265765ULL, 0x3BC4F74911D6058EULL, 0x08C8C3887E2FFA5AULL, 0x14ED7757AECDE332ULL, 
            0x0F064F6083320A27ULL, 0x4A5D3EAF040764C8ULL, 0xDAD5B975F0CA2997ULL, 0x81B8C819D9093854ULL
        },
        {
            0xD9B38FE3053D41EAULL, 0xB84EF7BC879CCBA0ULL, 0x2E87BD608D70D0DEULL, 0x61755DE4A950B4D4ULL, 
            0x6F1AD4D40BF8DB1FULL, 0x6B1B173174D5925DULL, 0xD28188CEB10CB155ULL, 0x274901B7BD2965C7ULL, 
            0xF0DD8FC0A459DF91ULL, 0xC7DFBFC3EB4EC94AULL, 0x39F5B8FED09DA8CCULL, 0x681182CDFC69EF8DULL, 
            0x56A009609D5F3F1DULL, 0x5BB48E3E5949D784ULL, 0x7B47AD20A4014D65ULL, 0xE4D9C5190B7435D9ULL, 
            0xEFC09A0DE5380C54ULL, 0x117B3CAFCF4CC17AULL, 0xA19158DF09BD8527ULL, 0x44216EB68B152C0BULL, 
            0x2ED75FB44B9C97E0ULL, 0x40654764ED1D2FE5ULL, 0x3D021232A0F13A86ULL, 0xF27B21CDD6F9DFC5ULL, 
            0xE997709409102E1DULL, 0xB643BEA821BF4797ULL, 0x3B0FF60ED60BF84EULL, 0x245944E1601844DBULL, 
            0x151CE4EA9A079E72ULL, 0x280957F3EBC2B5E0ULL, 0x3B61EA3447150D0EULL, 0x271EC8C757E7B471ULL
        },
        {
            0x9CEFE3B64110D0C6ULL, 0x9451047105162D8DULL, 0x0D94A62C53722F53ULL, 0xFD605DC462776AE9ULL, 
            0x1E760066C6834D15ULL, 0x4E3EBAFBD7E629C4ULL, 0xB0C56946ECE2AECBULL, 0xD72BCBDC82B6B42AULL, 
            0xF001AC468DA8E012ULL, 0xFF5C708BADC5F169ULL, 0x32511CD34321E4FBULL, 0x1E127E90FBB57739ULL, 
            0x3795CD02FE2783BFULL, 0x558AF33B52156BFDULL, 0x880238374CE05345ULL, 0x1CD3022BD6BE401AULL, 
            0x76A59699AB52569FULL, 0xB0CDE007A977631EULL, 0x91B2BC86EA83C5C2ULL, 0x225E119485B34A95ULL, 
            0xF6018529A9D91B3AULL, 0x556B2A36AF0CFCACULL, 0x8D827D20D61830E0ULL, 0xE3A38847F16B9D69ULL, 
            0xD9D4B6DBA6E6D6E7ULL, 0x2C9D306D60446DABULL, 0xF3A5B32EE1886B9DULL, 0x35EFFC90766AFA90ULL, 
            0x78FA15589970F906ULL, 0x6889673DBA1051E2ULL, 0xA4C4F735DD4B3229ULL, 0xD4F6C83857A713E6ULL
        },
        {
            0x2189969293156089ULL, 0x6757075C6F189A88ULL, 0x32594B750153C3D0ULL, 0x48D61D978C4092F4ULL, 
            0xBE41FE51E1FB95ABULL, 0x71C71731101417CBULL, 0x3F6758009FED5749ULL, 0x317328C578EE1140ULL, 
            0x2A486A6196AC14CDULL, 0x32F693F74AB2DDF5ULL, 0x8A36777E162D3ED7ULL, 0x01234D602E86D0ADULL, 
            0x9DB0515D851C70D8ULL, 0x94500CAF5E2B4689ULL, 0x154439AB703E284BULL, 0xF76DE9487D5BEA00ULL, 
            0x046306991FD487D2ULL, 0x5D75C0957489A50FULL, 0x2106A976CEB03970ULL, 0x90A032F66D35CDFBULL, 
            0xFA2BC75ACA770F17ULL, 0x77E9C76A6E259BCEULL, 0x2A33CF804A1A2009ULL, 0xBCD79DD8D3643266ULL, 
            0xF279EFE2FB83C005ULL, 0x7E3706B46D9A0A57ULL, 0x10DFB3F97F0BFB8DULL, 0xCB4A0A26C29E9A64ULL, 
            0xAABC0C8A8793D4DCULL, 0x18C5B36F471912ADULL, 0x074287CD3CCC5BC4ULL, 0x457021AE22039632ULL
        }
    },
    {
        {
            0x52216D57045AA43EULL, 0x7644431447196B72ULL, 0xA37FA67CEFBC281EULL, 0xEE67B88054E59C0BULL, 
            0xB50E15DD900FE566ULL, 0xE735550F22A0EDFCULL, 0x0AC69AD06C74679BULL, 0x632C5A08932518D6ULL, 
            0x4D113FD6D904D9DDULL, 0x91981753DC5B3251ULL, 0x252120FB16EB5C4FULL, 0xB97C80EF8AA8BB5AULL, 
            0xFA4CEF3C7FA61797ULL, 0x6CBA9CF9854D2ED3ULL, 0xAA8EE01395A2C642ULL, 0x4DF4C79471305DBCULL, 
            0x260CAD4D4AB56CE4ULL, 0x64D629AEC5751959ULL, 0xFB2202A63ABB59ECULL, 0x947015C8CB86494CULL, 
            0xEBBB52D3851E9517ULL, 0xCB20BEB235EF80D9ULL, 0x28792EEF1320BA18ULL, 0x9A4272BCB33B21ECULL, 
            0x73A415BB08EE0CCDULL, 0x9EE98581843E90F0ULL, 0xD3C9887DF042BAF1ULL, 0x3E3A09F6CAB340ABULL, 
            0x91FD55DB8EF315DBULL, 0x7D9D55D830853EA5ULL, 0xA378B2AFBE94059FULL, 0xDAF61EC36C16B1ABULL
        },
        {
            0xA45CB90CDD3B2FB7ULL, 0x8F8A5359A56F000CULL, 0xAFBEEAB4FD3B0934ULL, 0xEE6DE5BB655B6F72ULL, 
            0x88D81DD7175B2BD0ULL, 0xFA699307B5A70A75ULL, 0x980A2125686DC243ULL, 0x1BE19012F7FB3550ULL, 
            0x8339009A3EAD28E6ULL, 0x00B54774FE48AD26ULL, 0x2EF21F47656C293DULL, 0x90D1B1CA7D939632ULL, 
            0x7321AA6A2C208616ULL, 0xB0AA19B015D84483ULL, 0x9B584E027D11CA64ULL, 0x8E3C99478988E665ULL, 
            0x45FAC82907EECE7CULL, 0x645207C47FC62869ULL, 0x90EE26D78645F080ULL, 0x3B876395541F2EE9ULL, 
            0x9F1A58B915010F10ULL, 0x19638F19E098A363ULL, 0xB6A3D85498CE4308ULL, 0x6B6B01D5702BE7F4ULL, 
            0x7603B2B48AE53C56ULL, 0x8418F1EC4D0D7EC3ULL, 0x71AC71B16C774BF4ULL, 0xC50D839B96022C1EULL, 
            0x5C01F81B0108FEC7ULL, 0xCCFAC57544188BABULL, 0x6D1FF04224385926ULL, 0x8B5E4575748ECFB4ULL
        },
        {
            0x3C769F2E2A62964DULL, 0x2F171075B84D9270ULL, 0xAD8953B5878D28A5ULL, 0x59D9C1019CD13278ULL, 
            0x6D9F70BCFCD9FDE8ULL, 0x7989F0C0E4B8E94BULL, 0x194924C0DC872236ULL, 0x54C5215D10C1D371ULL, 
            0xB2C8DAA559682158ULL, 0x3E53B0A954576C35ULL, 0x5187765D28CCC2C0ULL, 0x1E3CFAB6106D0825ULL, 
            0x588CDD1DC11C1E97ULL, 0xD4C0F201B29C9114ULL, 0x3F5444DF6A24DA11ULL, 0x0C5905DFEEF3B4ABULL, 
            0xF7B50360B3892523ULL, 0x913AC28C838FA1B6ULL, 0x6C924612F25E532AULL, 0xE174240D721ABEEFULL, 
            0xD0BC94B9E10C8D69ULL, 0xAD8F2C1389AC9610ULL, 0x9CF85F7C48FB7261ULL, 0x64F05F0CF3E915C6ULL, 
            0x2BC77779C991DFF3ULL, 0xDA61441595A64B38ULL, 0x56B27B5092695188ULL, 0xD62781C9BAEA0BD8ULL, 
            0xAD3B12E4A021CF54ULL, 0xBE9E299D83999024ULL, 0x2D565C6AF33E8216ULL, 0x0FA1E29F737DD4DBULL
        },
        {
            0x46818FF67E5C90A4ULL, 0x5233DF7402F88657ULL, 0xF48E9DA435289CAAULL, 0xDFA098A2A0A8D471ULL, 
            0xFA836D3990E1B238ULL, 0x6087CC8F571FEF3EULL, 0x2E4360E21876D3B9ULL, 0x51C8AFEDFE5D7245ULL, 
            0x898DA8AAD6F75E75ULL, 0x9AE7D9D0BD7B9169ULL, 0x00EA640B9F53D32EULL, 0x8C61FE1669E2123DULL, 
            0x2BD0B7A5243D4EE3ULL, 0x28AD7DEDC46E31B7ULL, 0x5FBDB763E1483192ULL, 0xB216DBA84BCB14F3ULL, 
            0xBFF4E5AEBA2AB373ULL, 0xE95633DC82A48823ULL, 0xFD86D7389378BDD4ULL, 0xD957048B139C9B61ULL, 
            0xCB75E1D17FBC3814ULL, 0x561FEE0EC7CD6195ULL, 0x17ECE2A8F7A719B3ULL, 0xF6FD81998E7839DDULL, 
            0xB4F21A816AE8CA62ULL, 0xA4E91207311E0947ULL, 0x460A7ED5FE9ACE5CULL, 0x7778B189AF2CBF73ULL, 
            0xC55E95625E301F98ULL, 0x246ADCB6C3E98A80ULL, 0x7E7655DFB48A5A6AULL, 0x3ECF4E243405B379ULL
        },
        {
            0x67C58FC730855749ULL, 0x4B857DDDAFDD1D3FULL, 0x249F8332E6F156C4ULL, 0x4098BCA79B6DB277ULL, 
            0xE0C5EA706DA6A207ULL, 0xB086C53CD75E23FBULL, 0x4F83A7050BAB9ED1ULL, 0xF7D57C505763E8DBULL, 
            0x1417861F06535D48ULL, 0xD6686B8F71EF8EB9ULL, 0x4627CAC30FB3BEC5ULL, 0x239BCF0945D556C0ULL, 
            0x6B3351E109DE2667ULL, 0x45FF83782BFBC5ADULL, 0x350A38D7D19BFAC8ULL, 0xA6309D93A9B38E1CULL, 
            0xC81A322F86FE66A0ULL, 0x79FF2B33D65AFFD9ULL, 0x04E811003ADB815DULL, 0x1C1BF72C71175EF5ULL, 
            0x62A06E6866C3820BULL, 0x1D74B860B5073ED3ULL, 0xA6BC9D256EB4F4DBULL, 0x85AD2392D778A8A2ULL, 
            0x293E0F47E230BF78ULL, 0xF46A4F01B251B3A8ULL, 0x41ACD47E52CD7206ULL, 0xDDF8BCA36DB1E3E4ULL, 
            0x3B49FD5F838514D8ULL, 0x5BDA80DC6D3B15F7ULL, 0x6462D02C2FE3AA2CULL, 0x484EDE26C4B113D1ULL
        },
        {
            0x52163B3AFE762B87ULL, 0x4BF697DBD01B45CBULL, 0xAF4A2CEC3F6ADDB4ULL, 0x3DE6A9B3B8A07385ULL, 
            0xEB684B9D94136CE1ULL, 0x9DBA5CA18C5B09D4ULL, 0x380829287544397AULL, 0xDB89184F62DB4382ULL, 
            0xA780497DDE7E130EULL, 0xA45E6ED2B8939D7FULL, 0xCFD6D56DBB9D5E23ULL, 0x51F9AF2135DF3EAFULL, 
            0x8645F0370C3FC8F5ULL, 0xC82758BB5BF7C995ULL, 0x95144EC9A47B9CF4ULL, 0xC25B7F793F788026ULL, 
            0x560CB18F03F93889ULL, 0x9A9ACF8C4024B0D1ULL, 0x9B697D118FC1F6F5ULL, 0x65C51A0201063BFFULL, 
            0xEB81E6C76FDCB8C3ULL, 0x275F24357779C747ULL, 0xA9D4E15ABCF62D07ULL, 0x5389ECC21E4E2C03ULL, 
            0xAB919EA44A2277F4ULL, 0x503BF553EA0F2E1DULL, 0xA4B33B3CB5C1865DULL, 0x179D0488B0644E99ULL, 
            0x569734EAE3B076ECULL, 0x2AB474F08E862ECFULL, 0x16EE8FF2215BDBB6ULL, 0x0C81B867431C1DDFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseEConstants = {
    0x2CC70EBD92E4E46FULL,
    0xE898708567777AB0ULL,
    0xF3AB3912E2A2606EULL,
    0x2CC70EBD92E4E46FULL,
    0xE898708567777AB0ULL,
    0xF3AB3912E2A2606EULL,
    0xB505A116E1BDC30AULL,
    0x599CD981482FD43BULL,
    0x45,
    0x0F,
    0xF7,
    0xBB,
    0x25,
    0xC9,
    0xD1,
    0x47
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseFSalts = {
    {
        {
            0x8BD13D5F8561CC6BULL, 0x4227D73BD56F1364ULL, 0x6A60C8BBAAC97083ULL, 0x1467E8DCC0E6C224ULL, 
            0xA030AF81D53C6FB4ULL, 0xB0CF994F1AB54092ULL, 0xEDCB6DE009FA7B92ULL, 0x74028472A24273B4ULL, 
            0x7EF4BC142BEF923DULL, 0x186B912550DF991DULL, 0xC4D49297BE4B38DEULL, 0x85A5BC1FC2490315ULL, 
            0x76CE9463988A9BC6ULL, 0xDB2B9EDD417A49ADULL, 0x135B1FD70F7E5552ULL, 0x15DA5EAE912BC2FEULL, 
            0xA1EDB4448DA32367ULL, 0x07068032183D8C58ULL, 0xD8687C1345F28D21ULL, 0x9162C9ABABD9A20BULL, 
            0x641A35F4860D6A4DULL, 0x575F9E3878A9AFAFULL, 0xC6E02219663A78AFULL, 0xC5EAD8C6AEA87930ULL, 
            0xDFCB360F307E4001ULL, 0xCA20B494B7CF5CD1ULL, 0x8F2A34734DE2D625ULL, 0xBCD2CA929C9590FDULL, 
            0x4CAAE225643D0D2FULL, 0x62C6339DB1EF2C93ULL, 0x91C8F73467AA8EE4ULL, 0xB86213FF85602F49ULL
        },
        {
            0x0308BBA7D87611DEULL, 0x7785C31C695F9366ULL, 0x15212829340B92ADULL, 0xFCFA0DB7310D212CULL, 
            0x93678F9F3A0F3457ULL, 0x10FAA52D270D40BDULL, 0x9425D902915D64C6ULL, 0x32DEE11999F23B6BULL, 
            0x72650401F99A114CULL, 0x3514C6C26F5B724AULL, 0x77BB361174D044A6ULL, 0x821D40C238104D74ULL, 
            0xE5F633F0DEBC0263ULL, 0x9ACDA4BFEC6BCAFCULL, 0x5511C30CF055BF89ULL, 0xD0284C0CC5C345ECULL, 
            0xEBBA2C6B6264F171ULL, 0xCDD5ABF090CF86DEULL, 0x05F659DA2A22D6CAULL, 0x74CDC6031136F31DULL, 
            0xD043D1EAA2D072EAULL, 0x06DAE18AD6FC76E0ULL, 0x8C9465DBB9C2D232ULL, 0xF0CFB626AD1F519EULL, 
            0x3C023336492EC898ULL, 0x9963E97B72F15DF3ULL, 0x8D311E812F88E222ULL, 0x86A79E7727EF2EA7ULL, 
            0xA79B1A2E20E027F2ULL, 0x840AAC0FC5764A7EULL, 0x126CC69C800F0256ULL, 0x1BD19084CE1AF560ULL
        },
        {
            0x410EEFA44C20E32DULL, 0x89D6520FBB05F860ULL, 0x67E585530B2A9C8EULL, 0xEDC4154A03C834CFULL, 
            0xBB84E698D491A90EULL, 0x2D38477A183347A5ULL, 0xFB880DE15B2AECEDULL, 0x6A341B3F31AB31E8ULL, 
            0x1A00E759034ACCC4ULL, 0x247C597E1C1283ABULL, 0x98987CAF5C67FC6BULL, 0x10B1163D1D561F78ULL, 
            0xA8E85F76098BB1BDULL, 0x2BFEA303872A50F7ULL, 0xEB5693EB3BE19B6CULL, 0xB64400E3658484BCULL, 
            0x6FB0FE056D530B74ULL, 0xA18359B8B43E1CB1ULL, 0xE9C58748616994CFULL, 0xDFE3070A15CC5927ULL, 
            0x1D36FC736CD99DEEULL, 0x040144DE0C52D91FULL, 0x5B81ECA0AA2440FAULL, 0x95BD7BFFDA68471AULL, 
            0xA4A36115EC2BB5B6ULL, 0xA1FED91C4D9BFE33ULL, 0x47387612D3AAA324ULL, 0x5E240F2C47E80C17ULL, 
            0x7C523CA499C7D518ULL, 0x4BC419D25348CD66ULL, 0x8A850D5B31B349ADULL, 0x48F7BA225657926FULL
        },
        {
            0x50613F6DDC677733ULL, 0x2997EDD4B3DB610DULL, 0x80FDB9EFF22E06C2ULL, 0x3793236F82A67EFCULL, 
            0xCE27E5DC3ED4B716ULL, 0xCAF7345009EDB85FULL, 0xD2B600D6CCD7D67EULL, 0xB8385C587B12EFA6ULL, 
            0xE0B5CC6C093E503EULL, 0x8B628A63448E3186ULL, 0x8958D59A73E88EEBULL, 0xF3A652CDE1692359ULL, 
            0x216472403FC234CBULL, 0xCEDD9A250B494F68ULL, 0x796A963217473B2EULL, 0xC6898B288AA8CE56ULL, 
            0x33023D937F3625B5ULL, 0x08611B790BE945EEULL, 0x85974F02E42F315DULL, 0xF748C5D0D07797A1ULL, 
            0xF1CFC35FE2B87326ULL, 0xE587C0AFC267CC7BULL, 0x9FDD68B487ECB7C9ULL, 0xBF7A80DEB6E71514ULL, 
            0x420760A6411397A0ULL, 0xBC84E6E4D8934941ULL, 0x19BC5AAE00606A7BULL, 0x5FCCF8CF949217A5ULL, 
            0x96B3D10435B65337ULL, 0xD349FEC72E042115ULL, 0xB40B59D492F6B0AEULL, 0xC16628EF28A2CA24ULL
        },
        {
            0x268200DFDF84939FULL, 0x95E72C87F1B2BEB4ULL, 0x446CAEF88719491CULL, 0x468B7360505075C2ULL, 
            0x22599D1C56505424ULL, 0x48829F9697433DCCULL, 0xE53D876C89E2CD56ULL, 0x10AA7700EDEB0AB6ULL, 
            0x652BD8CD23740961ULL, 0x2F2F67DCD56B3844ULL, 0x94F74ED2E8F95295ULL, 0xAE169ABBC9E8DEE6ULL, 
            0x9DC3417D43E911C2ULL, 0xB14B1983D3D05512ULL, 0x14E8E65754CD654EULL, 0x8C07ADC109F8B559ULL, 
            0xDE92877354B38292ULL, 0xF2C0FCEECD70CC16ULL, 0x1AD38A93527FE7E6ULL, 0x85012B701A5501DEULL, 
            0x58ADFA854972C579ULL, 0x8CC6570C8E32693DULL, 0x4B0B592656DB592BULL, 0x26B812F11E8512E8ULL, 
            0x5C1F28978717FFD0ULL, 0x654323752EEED654ULL, 0x541725EFDFE23A02ULL, 0x6A5667F6BF09C4A7ULL, 
            0x8059EC9EB3AB959AULL, 0xEB94B4AD87AB6F3DULL, 0x508F76FD64919E41ULL, 0x35525FCDB456C529ULL
        },
        {
            0x98BC58D63758C0CEULL, 0x5186A84AAD280798ULL, 0x0D5A12658C5664EDULL, 0xD8DE7AC871F551F2ULL, 
            0x763D400AF40D5F6AULL, 0xB5489548A15BBF7DULL, 0x0BBBE1D12C2FF83FULL, 0xE1853DEE1FA5E1CFULL, 
            0xFD7483640CAA4A81ULL, 0xE7B2CE25617566FBULL, 0x1428C86761FA9740ULL, 0x0785F8F61B791EF4ULL, 
            0xCEE0C87B4C8632D5ULL, 0x8C0686F0657A96F2ULL, 0xC568FA7989E2D5F3ULL, 0xBAC8CA476D15D93BULL, 
            0x021F62BE9C947D82ULL, 0x18792871974C7D4DULL, 0x9136C15F9EC7D1F9ULL, 0x53C3AC21580131BDULL, 
            0x8A708D47CC1BC818ULL, 0xD3F5595D1F4AB19DULL, 0x2E383FCD27AB928CULL, 0x9A253BA81E030CA7ULL, 
            0xDECB4A0BBD34FD2FULL, 0x70B7EF99234F2AA0ULL, 0x56E027B9B8EE1ED6ULL, 0xDDF625AE5F909222ULL, 
            0xC91B03A2D7BFB9FAULL, 0x0A2BFDD1232E5CF0ULL, 0x2F2F3AD69AB6F1AEULL, 0xB861B45776A0097DULL
        }
    },
    {
        {
            0xC5DFF76918CFF525ULL, 0xF91E0DD1365FFC2CULL, 0x05281DBF612D91C4ULL, 0x7ADAFC11B55D73C0ULL, 
            0xFD69035A6FB5D952ULL, 0xB3BDEAFBF45C6981ULL, 0xE5EFBB8BB745410AULL, 0x93C47EA0FF440428ULL, 
            0x9830D6F0A00F075CULL, 0xE4F68174B8BB05F5ULL, 0x98C42B1E2E82B190ULL, 0x29C1B2973160FF8EULL, 
            0xB80ABE3751D203EDULL, 0xB8A53848EABA3BA1ULL, 0x4AE5DD684EFE61CCULL, 0x8726EBBD3BD82B81ULL, 
            0x40B31E12B4436A0DULL, 0x95CAA62038D35A4EULL, 0x8CA3C80FB57A7A64ULL, 0x07AFC9CF8B2B65A0ULL, 
            0x2D5B35CDFBAACDC1ULL, 0x53DE86A45D773316ULL, 0x21B67A1C128486ACULL, 0xE7DF2BE5A38A424EULL, 
            0x12A6257AE5DE341DULL, 0x6ACC7CDD54281B8FULL, 0xCEB76A6E1E412E5DULL, 0x918418441E7BCE69ULL, 
            0x6F14719BDBB800BDULL, 0x60E9C60135F6F2C3ULL, 0x98C0D74E91436299ULL, 0x0C3DB9E0DBAE729CULL
        },
        {
            0x9889C7EB35099F82ULL, 0x605896F66D5E0971ULL, 0xA1B2BDAB0B2CABB1ULL, 0x475DEFC9120C3301ULL, 
            0xB7407BB99DCA9BD8ULL, 0xCC7E65C88B63E52BULL, 0xBABB32E0DB886EC4ULL, 0xCB43150C6515C020ULL, 
            0x59478438B527DE9FULL, 0xAA8961A48051E696ULL, 0x3DA3791D91430165ULL, 0x90CD3A6468305C9BULL, 
            0x89DD0FD40F776B6FULL, 0x813EB58293915C31ULL, 0xD0B284DD423B7499ULL, 0x000CC7157BF5F0D9ULL, 
            0x9778DF8F05D0D347ULL, 0x205E396FE0C0586AULL, 0x7D329295892F3DB6ULL, 0xA367F6C01D470F02ULL, 
            0xC77680E47931EE28ULL, 0x4D82ACF249668DBDULL, 0x7374B1F3CCFF134DULL, 0x5E1A8958265BD0CEULL, 
            0x478A07AC7766E22CULL, 0x72D0107B93A997FDULL, 0xDE5BF05A477872E4ULL, 0x1023AE276809E11DULL, 
            0x1DE3562A0E5E3054ULL, 0x78363B43156345D7ULL, 0x5404001BDA5B0541ULL, 0x4DBCF0617B4898CBULL
        },
        {
            0x43D48F0F280FB607ULL, 0x06A60177789F06DAULL, 0xA9F4CD72CA03E68EULL, 0x0445DF8D6DBEC0D7ULL, 
            0xC0E5EB576F8B4814ULL, 0x5D6B504CC3F92DA3ULL, 0xCBAEB990D1158B33ULL, 0x4A751525DB0AD815ULL, 
            0x7B427F9D21721BBDULL, 0xE293ECD40C63277EULL, 0x892FF1A80522B3E9ULL, 0x868403B852DD585EULL, 
            0x3305D3675E3EE766ULL, 0xF6C37AEC596C91F0ULL, 0xB5328EAD0E8E3286ULL, 0xEE5CF764B91EC54BULL, 
            0x6E07117A619B96ABULL, 0xE2B6705B16B08AEAULL, 0x88C298C31EA74953ULL, 0x393FEDF12B40DD86ULL, 
            0x4840DE5F8FCEFBD5ULL, 0xA52AB13B9E904ED9ULL, 0x6AB87ED8700F0428ULL, 0xA80959E93D1D4729ULL, 
            0x0C5F22A2C6C7D87AULL, 0x1C6F18846AC5C03DULL, 0x53F49F79B63A3640ULL, 0x8A8196F64BD1324DULL, 
            0x1F99499ACB09FED2ULL, 0x58D017BB5F265837ULL, 0x6CCA6A7F3B86DC3AULL, 0x2ED029BF817A6964ULL
        },
        {
            0x8A85E5341CCD4C39ULL, 0xD2C8BFED2CCE96B2ULL, 0x87B173AC104194A0ULL, 0xE37C76B8121C6317ULL, 
            0x33FBC3E95D6AE609ULL, 0x1894EED8DC4F6C97ULL, 0xB5A4DC13E9548D5AULL, 0x7A9BC136276ED650ULL, 
            0x2777C398889D7676ULL, 0x5910C20FCDC64699ULL, 0xA016FA4D5CF287F7ULL, 0x4D65095545314CA3ULL, 
            0xBA5F5526EFAFC200ULL, 0x413055656AF989E9ULL, 0x559B1BED5852B189ULL, 0x9216847E960173F5ULL, 
            0xB8566EEA19F469FBULL, 0x057074C52D48C6D8ULL, 0x7B49359457752639ULL, 0x7F3BB97A9C79560AULL, 
            0xC44ABFAF42D197DFULL, 0x557C06FBE95C2C8FULL, 0xC48D532A38D35CE7ULL, 0x5096695AFBE21914ULL, 
            0x32206F6F60B76B81ULL, 0xF6117B642655D907ULL, 0xF74F8BC269889218ULL, 0xF8612F318F98E934ULL, 
            0x031C2A420F1076B0ULL, 0xBE7CC9D141E6762CULL, 0x5B6DD3341C429E16ULL, 0xFD6A6B05F33FE5C3ULL
        },
        {
            0x202147378C341919ULL, 0xA9D5188748E4A54DULL, 0xA3C17B650D8B4AC8ULL, 0x8FE26953BB426724ULL, 
            0xE4CE374D6D8A32E5ULL, 0x13A294999701F352ULL, 0xF92296DDF041DC9CULL, 0x807DD44E9523C874ULL, 
            0x634F1F0D2B7C14E6ULL, 0x9B0B8F3CB03D6049ULL, 0x9E0F2FE7BC9B5182ULL, 0x1078782FCD6730B5ULL, 
            0xE3E853DBC4DB0B55ULL, 0x4E312DEE5A7DDFF0ULL, 0xFDDEDDA325CAF70EULL, 0xBC54DE62B6D675F4ULL, 
            0xA314A511DBDAC2F9ULL, 0x461A18B6185CB51BULL, 0xEA89A04E49F8A04AULL, 0x869473A56F8EA9F3ULL, 
            0x52E442CD89395920ULL, 0xFF3596930B3316CBULL, 0x84465981600C75EEULL, 0xABCAF3206BEF004FULL, 
            0x6F29F43CE98BBA5EULL, 0x265AE90E0C3833DAULL, 0xC3962EA2AE2106A3ULL, 0xCD42FC7E02505C4EULL, 
            0x8D012EBE72E66538ULL, 0x99F57A78DD4F264FULL, 0xB1265E22758D2252ULL, 0xC81BC3B537D5D5A8ULL
        },
        {
            0x6112BE5D3921ACFEULL, 0x53CE7BACCF754489ULL, 0x003A7FE5FEDDE4AFULL, 0x2E138D77A179E709ULL, 
            0x8076898D04ACD946ULL, 0x6B5C5705E27E069BULL, 0x806D08E81DCD0961ULL, 0x319C068A9201A705ULL, 
            0x123705A083E387ADULL, 0x379B85129B3F2BF5ULL, 0x4C65FB5B71E87AD2ULL, 0xB1DC73CA74B60701ULL, 
            0x6F8ED5526539B43CULL, 0x3BA90D896AC8E597ULL, 0xCE4A89C4DC40C943ULL, 0x0D0731D4A91011BEULL, 
            0x0F1384046C2E48D2ULL, 0xE8203E9B21005E25ULL, 0xCFC2532696002C58ULL, 0xE5F34A1AFFF8243EULL, 
            0x537DB6F4B965E131ULL, 0x6C76FFA0C223D6D2ULL, 0x33D6F4AF2DB62384ULL, 0xE46C510C93905386ULL, 
            0x1D33F0C535A0B1B5ULL, 0x708B4E377F2F7277ULL, 0xFDC6277A0484C079ULL, 0xC80FB1716BC4611FULL, 
            0xB93927DC3A33DD18ULL, 0x4A662B1621C372B7ULL, 0x8F4953D1EA8DCB62ULL, 0xF4A716FE625B4199ULL
        }
    },
    {
        {
            0x71BB3D244CA4680EULL, 0x9E104DD7ED8FBA45ULL, 0x925A0FE2699908A4ULL, 0x7753537F2DB82059ULL, 
            0x4A4AE94018944229ULL, 0xB0615ADB3DDBF1BAULL, 0x7226FF9FA15DF337ULL, 0x0880D96DEEA5F77EULL, 
            0xF928FB3885D4932EULL, 0x37FE9F09D74C6F12ULL, 0xAE6DE2952C6710A2ULL, 0xC9E0DD5026582882ULL, 
            0xFF9256ABB9741BFBULL, 0x9AB4123B5A857180ULL, 0xCC2CC347305BDFC3ULL, 0x0A795F656DA6A60FULL, 
            0x38904DDD98B0C00BULL, 0x8159EF80695EE5D1ULL, 0x114C97B41A051850ULL, 0x7020B226173D587BULL, 
            0x028A1EF5655F21F6ULL, 0x6430A0B4EA05AEDEULL, 0x8DAC33761ABE6050ULL, 0x53DE24EB0051000DULL, 
            0xF418F2C399C52E26ULL, 0xC0CDEBA8D0BC9E58ULL, 0x2608B7881227E656ULL, 0xEFA95DDCA0AC398DULL, 
            0xB42C329DD1A6DAD6ULL, 0x5E0E90C503760E5BULL, 0xDABDDA674AB082F3ULL, 0xCF46DEF35083F0D2ULL
        },
        {
            0x6F2569F6DEFD11FFULL, 0x5ADC753AA115AF99ULL, 0x352DBB8DBB6E870BULL, 0xC7A285555D291278ULL, 
            0xEF16ED21BFCA74CEULL, 0xA08216F12670CE40ULL, 0xDFCA4C3D8799F5BDULL, 0x956C6A428D4D9560ULL, 
            0xE75953EB5BD69BBCULL, 0x6CCFB8B0BACE46D3ULL, 0x27AEB4F05C615F75ULL, 0x103504CEE1A2C211ULL, 
            0x14349D1BEB7EC55EULL, 0xB41C631AA1358EBAULL, 0x612CCADC3E4088E7ULL, 0x63976FAC0BB8AD5BULL, 
            0xAE9B826215A9F00EULL, 0x130486C61E86ADE1ULL, 0xBA49743EDEAB6CB9ULL, 0xC2CD5C4410B23573ULL, 
            0x7DBC9B89D0520352ULL, 0x8FE34876690F9C7AULL, 0x868F14C45E981E51ULL, 0xB1F77C46B2685E52ULL, 
            0x14D4980907F5BE1BULL, 0x0E1C23FA1396D3AAULL, 0x8D7F1B64E8DBFB9FULL, 0x5D349F800099E7A0ULL, 
            0x66AB52E7509814D0ULL, 0x528C7D81DAA02534ULL, 0x8ADB1FEFD39E6C9EULL, 0x92FB15DC944FD8A1ULL
        },
        {
            0x9DF8A4E5C795F9F5ULL, 0x0B6F31D4E078E9C6ULL, 0x27F6528F83D23D28ULL, 0x8197464C25ECC8A9ULL, 
            0xBD50E890408CC3B6ULL, 0xDF3D0CA45C9ADD60ULL, 0x41D986423DD9CE44ULL, 0x180F1612D32F7CCCULL, 
            0xE09C8BB3D8A4BC5FULL, 0x7BE1B79CDBDDFE2EULL, 0x15D747476D4D0C87ULL, 0x271F3F9CE563B0F0ULL, 
            0x4E8CBE99017422A6ULL, 0x733539DAF8428BD7ULL, 0xB25A9DAFAC403CDDULL, 0x8CDFC0BB860854FEULL, 
            0x407C72D8284A1F10ULL, 0x7F18008F2DC4C5F3ULL, 0xEDE62493DD8A1DD4ULL, 0x6AC2E93ABBA17DB3ULL, 
            0x04138A54DF0F5E0AULL, 0x8A19EE74BE9704B9ULL, 0x4D0C3ED5A7CC70F4ULL, 0xA474ADF638914942ULL, 
            0xB9B605701C43D1A2ULL, 0xCB0EA9C103800ABDULL, 0x12F1C3FEC253148CULL, 0x6FE25BC0FCEA96B9ULL, 
            0x735A84628A21021CULL, 0x7E79FB9771F4DCF8ULL, 0x8D56A5CBE55D4851ULL, 0x1E7AF53029247DCAULL
        },
        {
            0x586D50BFDAFD9EA3ULL, 0x43E82716F3EF4D26ULL, 0xD2188366E30C11D9ULL, 0x9142ADC3B8576F73ULL, 
            0xFD125470E2FD27FCULL, 0x3AB114E4E868DEFAULL, 0x2C4C5987F0C3EA97ULL, 0x32DAB4906298F7A8ULL, 
            0x0CF27FC0B45C2FBDULL, 0x6701F1C5C268B749ULL, 0x5F5464E3E693EF32ULL, 0x6136F32122738B51ULL, 
            0x56F3582B04BD9CCFULL, 0xC1133A18B4E77005ULL, 0xE2374417C7ABB58FULL, 0xA6077255143CC395ULL, 
            0x07D6C900E8C681DCULL, 0x3496DC556C1B7939ULL, 0x66834C7A70BB4BDBULL, 0x729FCF89F86437FEULL, 
            0x85CD7E5E92A6C023ULL, 0x35AE549A252BD5B1ULL, 0x0FEEB8DE8D041036ULL, 0x65119FCECEC62413ULL, 
            0x6C7729FC1C630BEDULL, 0xC1B1BAF18ED91C8BULL, 0xBEB3D452CE402F8DULL, 0x315765909BA28569ULL, 
            0x022307F9018824DFULL, 0x24501BB3FEEAA452ULL, 0x496948453E6503A9ULL, 0xC4E2C6B9C74F2645ULL
        },
        {
            0xE23E5CADB40DD527ULL, 0x51EF571513C711A3ULL, 0x5DB443E42DA2FA99ULL, 0xDC5C9B044055F949ULL, 
            0x84E24B782D702CA9ULL, 0xC00503059F2436E6ULL, 0x6F4816F9B1CDC7F4ULL, 0x76D7CC5CE928E221ULL, 
            0x688C0AB9C96E5086ULL, 0x37006CDD45DC8752ULL, 0x644F5BD5D1FA4C91ULL, 0x563E1FD181736494ULL, 
            0xDDD86A9284F437CCULL, 0x70BC25A7FC822D3DULL, 0x3B94357A675E551EULL, 0x33412E093059DB77ULL, 
            0xC1BEA2B5907BA07DULL, 0xF260983E0651D0D7ULL, 0xD12FC328DDAACF3FULL, 0x4E01F1C8514664BDULL, 
            0x5CC821C19D93A356ULL, 0x62EB714D4D0AAC61ULL, 0xCD6904784FD772C9ULL, 0xD789A7789211FE84ULL, 
            0x012354F7BC6F0840ULL, 0x3F9760DB9E500EFFULL, 0x5CF18CCB248B3C09ULL, 0x2851AE126454072DULL, 
            0x06DD37C2E66F8364ULL, 0x3C7C9064492B3C6BULL, 0xF01B47221FDB055AULL, 0xB6A46213A34B9AB6ULL
        },
        {
            0x03B75249AA86176DULL, 0x54EC150B9BED2BDFULL, 0x774E6CCB9183C4DDULL, 0x6B22C5D520249731ULL, 
            0xB6F15843B904BF02ULL, 0xE0EA2D99D7862A6EULL, 0x7530C0720EE83244ULL, 0x0E1A035B4215435FULL, 
            0xFABE7D98282794FAULL, 0x0CA0A29D632EAF9DULL, 0xEA9FBAD72C003A57ULL, 0xF7B3A9C376170E1CULL, 
            0x2106287CE0781AEFULL, 0xD55575C8CEE61F07ULL, 0xCB0F3116B3269CD4ULL, 0x89DFEDDD9EA56EEEULL, 
            0x986310172523C303ULL, 0xA1210782D6D7BACAULL, 0x5F450B665DF4ED43ULL, 0x93FE3AE648C50BB7ULL, 
            0xA8CEF24646F74E47ULL, 0x38C18D3A5DB8FC41ULL, 0xC041897918B1AECAULL, 0x938AFF68E581D663ULL, 
            0xC6C5C7D1B65C1014ULL, 0x578FC3CFEC54303CULL, 0x15E1A9644362051DULL, 0x8BA01C648C53D145ULL, 
            0xEED201EC970AB6FCULL, 0xDA7A2E67C0270189ULL, 0xD310777F73EA1B2DULL, 0x281A90029B87FD1DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseFConstants = {
    0x87BBAF5D8427CD58ULL,
    0x5EF86EF2E3750CBDULL,
    0x1604B7B70C7640E8ULL,
    0x87BBAF5D8427CD58ULL,
    0x5EF86EF2E3750CBDULL,
    0x1604B7B70C7640E8ULL,
    0xA6425338CAAA9866ULL,
    0xC6EB0D9ED0863CB6ULL,
    0x1D,
    0x07,
    0xE0,
    0x7F,
    0x7A,
    0x39,
    0x96,
    0xBE
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseGSalts = {
    {
        {
            0x5F6CE83B3F1FC7D5ULL, 0x1B40D11E34D6F948ULL, 0x03FB42482D08081DULL, 0x4A0117B9734EEF17ULL, 
            0x37167FE09D117712ULL, 0xB925DBAE58ED1C29ULL, 0x8D211740EFECC804ULL, 0xBC984466856215DFULL, 
            0x36D8417C29E5956CULL, 0x1116FD4C96C521FAULL, 0x7AC0C71580D3D265ULL, 0xAB30BFCC8769997BULL, 
            0xFF0E4850CC2F4725ULL, 0x3BCDC43D25FC323CULL, 0xA511F0D0DB984506ULL, 0x9F71A0EB825F5D0CULL, 
            0xC201F6693C1A51F1ULL, 0x20D9ACF2B096D431ULL, 0x5534A1DB8A1EA8A9ULL, 0xF05A0BF8C88D8D31ULL, 
            0x6149DBF62FE442BBULL, 0x3FE08606000590C6ULL, 0xC935598B8297D62CULL, 0x3E59D99A1666A637ULL, 
            0x3FC5CF5429903DA5ULL, 0xE4FF03C4A77062CAULL, 0xB064A8A6A254CE19ULL, 0x7BF3B16E49B18314ULL, 
            0x406AB003FC536C0CULL, 0xE695490200113E95ULL, 0x646CBD28D589115BULL, 0x746CAD1D4091B001ULL
        },
        {
            0x6C2EA4BF4CCD6D90ULL, 0x8C141A682DF5A210ULL, 0x1E7CEAC08181C565ULL, 0xB52213FE8BEFC686ULL, 
            0xF9F88710A71740EFULL, 0xDB28B28E3F758063ULL, 0x2292466F73611A14ULL, 0x17C3E55A35AA16F7ULL, 
            0x7A227294D2C2FB18ULL, 0x3D84B598EB800B01ULL, 0xDD1BC60D3934DFA1ULL, 0xC781886CAD2E73B3ULL, 
            0x33DCFEC466473D73ULL, 0xF68C6333AAFF5C7CULL, 0xF7BAB70937F93A99ULL, 0x0062F388BB3636ACULL, 
            0xDBA5DFE6D7C9E96DULL, 0xB695996904E75D63ULL, 0xD194063ED1B2883BULL, 0x8FD44706208A4512ULL, 
            0xF00C679E6723B7C8ULL, 0x47955C1F2D4F39D1ULL, 0x2868708F4F7E6199ULL, 0x17DF3573EFC6A168ULL, 
            0x7360194683E950F0ULL, 0x1BF87C2CC7C21576ULL, 0xECCD7031E07AF90CULL, 0x5C443D7E92FB019CULL, 
            0x1B7F32575CABA025ULL, 0x452F30CEC93B3E5EULL, 0x169CA9722517D0B0ULL, 0x1F6BD092FEE0AA3DULL
        },
        {
            0x2667B60533724AF8ULL, 0x120F1711D9120716ULL, 0xB5F8E0BBB6CF9742ULL, 0x05145BC103BF1C54ULL, 
            0xEDC44C710000AE10ULL, 0x13C09B2857132540ULL, 0xA3DF2C0AFD081284ULL, 0x7AC255DCEAF4DF39ULL, 
            0x1F8ED7006C1E76ECULL, 0x7BEE150670CF7956ULL, 0x7179168965E0C49BULL, 0xE320EA883414B25EULL, 
            0x57CB077033B673EFULL, 0x03B3BCC8040B8068ULL, 0xF115BFD0069FF5E8ULL, 0x8A379A4BD6F3BDF9ULL, 
            0x6EFB398B114BA5BFULL, 0x00D9E175133F6E8BULL, 0x310EAFB893B4EEA2ULL, 0x0EDECCFC41C6158CULL, 
            0x55DA798988AFD889ULL, 0xC718C1A65342314AULL, 0xEBD6F9792AA1D22EULL, 0xCF42DF6605AF6523ULL, 
            0x72990D29A60837EEULL, 0xB15FB15A54B7DA2DULL, 0xC1A6230B90A8BED8ULL, 0x1549C4041AE90604ULL, 
            0x79C43D5675E157DCULL, 0x276C1375F5FD16A0ULL, 0x16FCDAEEC6F3A3C7ULL, 0xB1971278C6865C83ULL
        },
        {
            0x5A303B8FEAEC3B42ULL, 0xC66103EED88CA2F1ULL, 0x49BBCFC66AA6079AULL, 0x2D45011BC0744C10ULL, 
            0xB5035C75ED87EFB1ULL, 0xF0DFF1A758270F43ULL, 0xDA874A35A9B2ADF4ULL, 0x98A55C4366F6CFF6ULL, 
            0xCAE1D9ED427158FDULL, 0xA41C23EBACFC10E8ULL, 0x66E110B22934348AULL, 0x1408B9B56460E530ULL, 
            0x7776630C0393ACB2ULL, 0x3F8505682EC48D8FULL, 0x2C158F375BC736BBULL, 0x6EF6553B6F016B32ULL, 
            0x9C284C8805032AB8ULL, 0x9FE6B8A801D23281ULL, 0xF413BB544F598E6AULL, 0x78EBA21D6AA4A505ULL, 
            0xD27D321E1C270DA6ULL, 0x6267F93BF6424B6AULL, 0xFBB7E4EA26D33777ULL, 0x0F0DE4F6F4BEAC8EULL, 
            0x3A53CB8FD4EE8050ULL, 0x315F4CE5F06B64A5ULL, 0x1B0BBAAA37CC0973ULL, 0x77DBA30DF2E7767BULL, 
            0x64A5DD16AE7C99DFULL, 0xDE3722AFB976C19EULL, 0x60ED801C932F7FFFULL, 0x528FF3779F06D633ULL
        },
        {
            0xB00BC2497063F98CULL, 0x934C0CA33643701CULL, 0x5F509F3A96A6470EULL, 0x8EFAA9EAAFE2A350ULL, 
            0x851B996C929E0BBDULL, 0xCFBD60EC89D4B8F8ULL, 0x8CB052EF171ED6ACULL, 0xD44DD7943A4F564DULL, 
            0xEAABBA0137E4350AULL, 0x4114358E63266C57ULL, 0xB1962DCDF30BC792ULL, 0x7AF0C642CF7BE380ULL, 
            0xF5E6E2794BB4AB61ULL, 0x3FB5D83273A6B709ULL, 0xFAB38B9DA3314075ULL, 0x66ED3FF33A8E8264ULL, 
            0xE1C2B5F56A25B950ULL, 0x2F1C1C2A20C31D8AULL, 0x48B3368242DA3599ULL, 0xF412441DA49E4E26ULL, 
            0x8E5D472485B99A59ULL, 0xA7254BC74E499B58ULL, 0xF20A5199C72D10F6ULL, 0xE2EC33C9C5D8E256ULL, 
            0x43FDB9BC5242EF1BULL, 0x42322FE61D2773C1ULL, 0x2B48168025C547ACULL, 0x83B100A2A77EA4A3ULL, 
            0x0577687BBD6B6E5BULL, 0xE824E319B304351FULL, 0x2EFD65373EFFA4F2ULL, 0x9152F7F768DB72EDULL
        },
        {
            0x898936D400CDF6D5ULL, 0x7E98F41C49681DD9ULL, 0xC6F92A6AE06AFB1AULL, 0x6A1665008A5866D8ULL, 
            0xDBF87E455E01F014ULL, 0x18EC317784A210F9ULL, 0x261129EC205FA254ULL, 0x6A0E8E7DAB19AB28ULL, 
            0xC35BA2B3EA47B900ULL, 0xBDB700CB607686A1ULL, 0x7C879C3CD27D2DD7ULL, 0x2673AC8D0C8DC8FCULL, 
            0x2AD85164EDE3D88CULL, 0xFBB94F7FA546374AULL, 0x9B5840FDEBA7CCD9ULL, 0x94241E15CA455D65ULL, 
            0xC585A7AA5141FEEAULL, 0x45A064F4E30355DFULL, 0x65446D0096892007ULL, 0xB06D650A5F92BC5FULL, 
            0xBA3AEEA754A2CCB9ULL, 0xD396B685D4FC4304ULL, 0x4FF71F70E20BC56CULL, 0x70E05B62EAC0C042ULL, 
            0x0B43FACE02DD28A9ULL, 0xC0BAD671E3340C0DULL, 0x667A625F37928EB0ULL, 0xEF85DC4F741971C9ULL, 
            0x42F5F207AA2797F8ULL, 0xB962859B0E4C247FULL, 0x6C8AC5140CCC43BBULL, 0x9FEE4F52CE422152ULL
        }
    },
    {
        {
            0x62EDFC2848401592ULL, 0x7143BF56BB0911A2ULL, 0x6D6F2DDACD327592ULL, 0xE5CF9DAFCC2419A5ULL, 
            0xB86BB8EAD18E9270ULL, 0xF28D9C1B2F3D929CULL, 0x65A132DFEA61A7E1ULL, 0xC81029DC86223275ULL, 
            0xCAEBF46458D7C806ULL, 0x92D7F0BEB669021EULL, 0xE12D9F82689E700CULL, 0x82F0E3A69B025B0CULL, 
            0x868C33B6FECD5160ULL, 0x1BC5A56B0C7FEDC3ULL, 0xB114F820429FA2E8ULL, 0xBD58120E89C2BD15ULL, 
            0x08D269AC9BA73A22ULL, 0x3762AA2140E981D9ULL, 0x2B02C91D9E5C38CBULL, 0x27D91FC1FD6BA2BBULL, 
            0xADC72A2201022DAFULL, 0xBF123C6FD86A08DFULL, 0x4DB6B90270B294C4ULL, 0xF37D11816302CF48ULL, 
            0x8804E5FC109816D5ULL, 0x847CE16F79B70725ULL, 0xE00F92363D459714ULL, 0x72D2697D1DD09AE2ULL, 
            0xA02AADD0D3237BACULL, 0x2AC5FC5FB68E8E24ULL, 0x8B959E9B98D14138ULL, 0x15043D3D391A587DULL
        },
        {
            0x28C81160E7D5CB54ULL, 0x2E5C1A255C082BB7ULL, 0x1077010DBF61991DULL, 0xE692C5C0E88389B8ULL, 
            0xCDCE463548DC440AULL, 0xAF77B6637743EB6CULL, 0x1B4C2AADA14C24CFULL, 0x5FDF590453B72EEEULL, 
            0xD5F208C66637CBBFULL, 0xA98F002F95ED1790ULL, 0x11D7760E1A863EEEULL, 0xC8A818F282B5ED8EULL, 
            0x419C52D52E968DD5ULL, 0x7D25D60C3F36F06AULL, 0x6D2EDEFE37E57ED5ULL, 0xAA0F43351FE0110BULL, 
            0x0ED209381960DB84ULL, 0xC80CD494B5D012C2ULL, 0xEE79491222B1B45FULL, 0x9EC88AA67DD1EF10ULL, 
            0xC8BFD6D6E4ACC971ULL, 0x18637A0B9C3C3F6AULL, 0xD3B1E8BC9F9A13CDULL, 0x5799C566EA8C945FULL, 
            0xCFE9C6C9ECDEAD19ULL, 0x1E9958A2FBCD9798ULL, 0xDF8DE0555CA4DF2BULL, 0xE86CD9088517305FULL, 
            0xCD1CDABBE60D8BC0ULL, 0xAD4A550ABB970195ULL, 0x7A4F50B8765D2F17ULL, 0xC79C8BCB4542766AULL
        },
        {
            0xDDF43F594BE7CDDBULL, 0x5F21BAF3F7218E5BULL, 0xBA480BE518EC27BAULL, 0x2625F5F53ACFCF83ULL, 
            0x2FD0CE00CA5C063BULL, 0x00492F5F9503F2AEULL, 0x4C433571669F0B4FULL, 0xCE5D95295A18898EULL, 
            0x4BD648DFF9F68DF6ULL, 0xE8ADFCB731E8D2B0ULL, 0x4FC31056E9E82CF6ULL, 0x581DE96D067F1441ULL, 
            0x6BE66E703DFAF1DBULL, 0x3CD6734A081C2159ULL, 0x8DE252EF9BB5F476ULL, 0x2FC54DA04FE95330ULL, 
            0x67EF2C615985676BULL, 0x347B11D4C5F540D3ULL, 0x49740A287C638E23ULL, 0x25683AAB5A90CE05ULL, 
            0x28BC1BD664410D85ULL, 0xD983770193E6E03FULL, 0xC35EACE7095BA024ULL, 0xF55F2926CC3BBC07ULL, 
            0xEAB7699E2AA7D1DAULL, 0x7AC26FD852B6663EULL, 0xB8FD9E95464FC846ULL, 0x2E57573D38507886ULL, 
            0xCFB516B1DFFA6A74ULL, 0x68BB8E733432E0B3ULL, 0xD5833E08C473A1CBULL, 0x0428D5B2BFF71825ULL
        },
        {
            0xD455C52A32EEB94BULL, 0x1BC5A20CBFA43464ULL, 0x07993F49E5A68364ULL, 0x60D6D7745D25BB07ULL, 
            0xFB15E21BD08EF1ACULL, 0x9277323772131870ULL, 0x901696F662622F9AULL, 0x1B0AECAFCD3A69C9ULL, 
            0xA64014584EAC2064ULL, 0x0306FA500B6EAE59ULL, 0xE6A3B47CE05A8DECULL, 0x71AFEA0B0EBEBB7BULL, 
            0x139C904BD25E6592ULL, 0xD9851ABAC4C444C0ULL, 0x411A105F2AB521FDULL, 0xF32EDB86019898D8ULL, 
            0x82E55AB0A07B5468ULL, 0xEC5A64EC7468C7CDULL, 0xAFA4953B3C4E4FD8ULL, 0x27C910EA3C6F0417ULL, 
            0xB49F811DF98A7DC0ULL, 0x56D16BC53DB3E22CULL, 0x2074A763C05B3142ULL, 0x2E0CAA023974045BULL, 
            0x5457B58FF5A21401ULL, 0xA462243A53E3D4B7ULL, 0x9C0E2B3A2F21A09BULL, 0x923EE00F44A1DC50ULL, 
            0xEE2AC687476B898BULL, 0x05C216F82552DBC5ULL, 0x55D00ADD4A62DF03ULL, 0x7995D44CA1A9A58EULL
        },
        {
            0xA485988025B99DF8ULL, 0xBD4CE7D7E6B1E370ULL, 0x8366B3DFC678F57CULL, 0xC4D98A33BFFA23F0ULL, 
            0x8A25F68607D48377ULL, 0x321AACD5FCFE9735ULL, 0x1064A23B84883628ULL, 0xD384C37C20D68AC9ULL, 
            0xD98F29B8BDAAD707ULL, 0xDCFC311C903C9D62ULL, 0x79654F4203A650C6ULL, 0x53049B7A4BD10C33ULL, 
            0x925BF15BCEB27DFBULL, 0x352D8392A40BF2E2ULL, 0xE82270F2D4DE3BEFULL, 0x8D6AD63568797EFAULL, 
            0x42B99C2D766EC3FAULL, 0x415C85A391441644ULL, 0x2C2A51407632F475ULL, 0x6211FBF4678E4F43ULL, 
            0x17BE4B3FF7065B01ULL, 0x64EB7021A419EE7CULL, 0xD344BCD34F0C489CULL, 0x168801268F1DD429ULL, 
            0x3994AA7871B6C489ULL, 0x887365490D5D770EULL, 0x531CC63B08E2A0CFULL, 0xE16D8B31ADCA212DULL, 
            0x55E7596776C4A162ULL, 0x6C2F0AA728ADE1FDULL, 0x4BEBC2046FE7E10CULL, 0x4CACD653506CA9CFULL
        },
        {
            0x82DF136CFE1C48CAULL, 0x90670ED686CACC3DULL, 0x34A05D5BBDD79575ULL, 0x4C2EA3C474BC2CBFULL, 
            0x0F8D39F0F133E2C3ULL, 0x125FC97C40B2EA80ULL, 0x8A38DE8E83FA36C9ULL, 0x038307266D2C339DULL, 
            0xD58A43CCC0F1F6ABULL, 0x6051A86E34830F21ULL, 0xE00DB05DA6414373ULL, 0xA8330E2EA9DC1A1FULL, 
            0x8679106C134E409FULL, 0x1013DD67EAB6A6AAULL, 0x36C08C3FF53D0C21ULL, 0xE80F001E5CE5AF9FULL, 
            0x304D6D87221C3D06ULL, 0x5A405B85C3FA8C2DULL, 0xA0EA354EF9AF6B6CULL, 0xAAC553E73267D713ULL, 
            0xE6C683C5A6C4B8F9ULL, 0x13282418CDFD9D3DULL, 0xA1010E380A4F588BULL, 0xD81DE055E01DC8D3ULL, 
            0xED63DB9E7C68038DULL, 0x467F79ECE40A5AF5ULL, 0xEAEC51DF0363C557ULL, 0x9A03A0DEC6FBA28FULL, 
            0x2CA50BE3CE78081DULL, 0x85B1B630518302C6ULL, 0x3120FE538E7880D4ULL, 0x643B60B6ABD32342ULL
        }
    },
    {
        {
            0xB297348D1948CED9ULL, 0x9B0DA29B1705EF23ULL, 0xFBFCBA19EEEFB721ULL, 0x451D5F38B023641FULL, 
            0x18D72A672B274742ULL, 0xF8DF82BAE257B84BULL, 0xB26475A52D9C1E2FULL, 0xBB34C9CC427CCB8DULL, 
            0x0B4449A64C88B0F5ULL, 0xE295E65433B9D719ULL, 0x06844133DBCFA80EULL, 0x6E08322ABEA0C0C6ULL, 
            0x92C980008F78AA43ULL, 0x78DCD8F9265CB0F3ULL, 0x3BE7E5D5C11AF8DCULL, 0x90158A963380A49AULL, 
            0x0EC6592624AE55E7ULL, 0xFD4EA04EA8899813ULL, 0xA30E640E10D20751ULL, 0x6F829E8A506D1BF8ULL, 
            0xEB0A4B062691CAAFULL, 0x8B496B6C0969914FULL, 0x6F92B29945E16720ULL, 0x779D3A9390DAE239ULL, 
            0x1E7A8F0852E05BF5ULL, 0xE2D70CEA916B1A56ULL, 0x43AC6A19C4374A3BULL, 0xF43AB7ADDCAC20C5ULL, 
            0x4CE05F3F96925C84ULL, 0x09190E04A75EE725ULL, 0x1D2A8ABF8AC53C96ULL, 0xE9ED7B17FAD52801ULL
        },
        {
            0x33283778C26B16ABULL, 0xA5543B9766228D73ULL, 0x7DFF70D34E67D6BEULL, 0x502F2043E31CBF7EULL, 
            0x7FF65C8DAD283173ULL, 0x25B32540B1BA6A57ULL, 0x477A4DA123E6CACBULL, 0x9748A748967420A6ULL, 
            0x4C62EF65CE28F69DULL, 0x20148C5D2442B4C7ULL, 0x41344ED75B81E1A3ULL, 0x7CCCA19866CF4A08ULL, 
            0x023E2535C5D7F542ULL, 0x8EC4E5E30BF53566ULL, 0xEF86A2471680CAB4ULL, 0xD7BEED5590E594F9ULL, 
            0x1A29B90C0C6E6969ULL, 0x6AC583D45C3D665AULL, 0xF9C6404355A73A81ULL, 0x611249B9A57456E0ULL, 
            0xB5E76767E40F0CC8ULL, 0x6A957F7968C782FBULL, 0x0F0F268C8DC83B92ULL, 0x2210D1E5B795B62CULL, 
            0x872AC43E682B2E42ULL, 0xD1572FC242864D08ULL, 0xC0BCAE617EEC8554ULL, 0xDE1F18B5975B96E0ULL, 
            0xF3987EC14D2AC601ULL, 0xC07504911F831470ULL, 0xA6AF2835927B4A44ULL, 0x9C24DD1CD2CAD935ULL
        },
        {
            0xD1BB2557CA74F55EULL, 0xAF8670C70157D789ULL, 0x83CF03EDEBA4AC8DULL, 0x34DB2843369CF4C1ULL, 
            0x8793A808382116B9ULL, 0x86BA78F461DDA8BBULL, 0x945A19930AEDB53CULL, 0x55C5DDF6E9CD4A37ULL, 
            0x5BD97E7FAB662211ULL, 0xC9F50EE98BD0CD77ULL, 0x0A49D920F124783CULL, 0xC9ED030A28E64710ULL, 
            0xB199332D01940FB7ULL, 0xD154F07A4FE74639ULL, 0xD60B0DFCC164C600ULL, 0x6192BC6EA801B746ULL, 
            0x732E6F457D99F459ULL, 0x6C1E5FCD605E0AF0ULL, 0x5ED39938A9559BEEULL, 0x07A96397CA45C14CULL, 
            0x958726847F950DEAULL, 0x86FAA1DF5A84B26BULL, 0x1C804B2D325E8F97ULL, 0x49E1EA485ED84AA6ULL, 
            0x37B32FB40D467873ULL, 0xF979DF7AE7C3325EULL, 0xE9D947FEAAA4F8C2ULL, 0xB27AAD06B1AA8B74ULL, 
            0xCA4DEB553CB70277ULL, 0xDAE66A1B11E6231BULL, 0xC5E54419CDE776D5ULL, 0xCD831C84EA7461DCULL
        },
        {
            0x3087DF2932413ED8ULL, 0x6632944BE727F4CCULL, 0x2007B03A8DA1F0BEULL, 0xA705F4643D0D80D2ULL, 
            0x76A1885A4682CC1DULL, 0xFAC4AB7AC45A5998ULL, 0x00D58999CD8A10BEULL, 0x90466A7F124BEF50ULL, 
            0x66912209729D68EEULL, 0x81CDC5EA0643EB9EULL, 0x4461FF3F44D09D92ULL, 0x0FA8FB2661EEE3A6ULL, 
            0x48CFADAFE3C0DBA7ULL, 0x8F892D32178C5695ULL, 0x3159ACD3FE02D192ULL, 0x8C53B400C4A1899CULL, 
            0x1F0552F760D3DED2ULL, 0xA30388C48674DD59ULL, 0xDF8252B0B639BE74ULL, 0x5AB7E74FDD5FD29FULL, 
            0x2E91BAECB3CD4A95ULL, 0xDF01DF1E5D683808ULL, 0xD7A8B6357FDF54F1ULL, 0xD2B63F87A7C45BE6ULL, 
            0x2F4ABCE845206C45ULL, 0x8534047E4E61F395ULL, 0x0413A71BCDDEE752ULL, 0xA63EA3188AF3BAD3ULL, 
            0xA6B59A1440C86FBAULL, 0x2DA769F8835A8891ULL, 0x95D052384C04018CULL, 0x4B5CB652C1B23509ULL
        },
        {
            0x35CA8DADC779D38BULL, 0x1DAC9323568604E9ULL, 0x7BD219535A8225A3ULL, 0x7D098575A552977DULL, 
            0xEE3A685633C9B262ULL, 0xF2137345921DE10BULL, 0xA17C3DCC0366F3BDULL, 0x1383066A5D0C9EF7ULL, 
            0xC7D2773C3A439707ULL, 0xAD094C321DD1BA10ULL, 0x0DCE780FEAE038A7ULL, 0x131D0783EA7E0B46ULL, 
            0x69DBED26D89AD7BEULL, 0xF4437A12AB127245ULL, 0x847721335A1B3C06ULL, 0x3DF4E8F85C9533CAULL, 
            0x597BAE40766A1DACULL, 0x79B1E07AA6B543CFULL, 0x1A793F8650802DBBULL, 0x750832A4825F64BDULL, 
            0x798208E8CBD49BF0ULL, 0x7ED12D368DBC509AULL, 0xD20E68E82E64DCC9ULL, 0xA85054A22AB2D426ULL, 
            0x2B7825C2A0813616ULL, 0x76B1356D7BA585D8ULL, 0x8192C9F81514C9FFULL, 0x889998E5F75B1414ULL, 
            0xA7E5713A12973AF4ULL, 0x225A2030D8549641ULL, 0xEC811E23E60B6D73ULL, 0x33AE6E842B52E431ULL
        },
        {
            0xF9E3E5F70C2037A0ULL, 0x51B844C8C63FBF27ULL, 0xFFB4017A21AC5520ULL, 0xB65C4EB843DDF127ULL, 
            0xF9D3117A57E76E07ULL, 0xBECB0470100600BDULL, 0x1FFFC4D4D399F7FAULL, 0xA7920F974BB92622ULL, 
            0xFACF02B398D587E9ULL, 0xDB31F11EE81FD739ULL, 0xB8FC6D8106B12186ULL, 0x2402B4FDF838DC3EULL, 
            0xCBF12CC93847F7C3ULL, 0x75981B938609C702ULL, 0x7E1F19E09285E2FCULL, 0xB8B862CA52162CDEULL, 
            0x5FA9CDAA88A06825ULL, 0x30B170144AE15172ULL, 0x024AEF6D99067CD7ULL, 0x7F28ECA456599F30ULL, 
            0x933269463F7D24D6ULL, 0x00AFFC064DA84145ULL, 0x93BE5C2282ADB48AULL, 0xEEA11E344256D0E9ULL, 
            0xC3790E8CD8032176ULL, 0xF2A8BE2CD358467BULL, 0x7B7FD1824C656D33ULL, 0x3E13E5C2C60FFC20ULL, 
            0x7C0E0FB70B9F9A1DULL, 0xA3699A6FA3AD4FEFULL, 0x814A88E9AB8BD326ULL, 0x8D2AC20335B8FB0BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseGConstants = {
    0x44780E9396C32E8BULL,
    0x2DAF51B9B897BB16ULL,
    0x22F533B12990C864ULL,
    0x44780E9396C32E8BULL,
    0x2DAF51B9B897BB16ULL,
    0x22F533B12990C864ULL,
    0x3C6AC435EAE5939DULL,
    0xF9698C26F009754BULL,
    0x95,
    0x2A,
    0x69,
    0xA0,
    0xE9,
    0xC8,
    0x0F,
    0xDC
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseHSalts = {
    {
        {
            0x3A5543BC076DDC2EULL, 0x4B44801FCD0459B4ULL, 0xF4EEB66B67C96C71ULL, 0x6FD2067DCB6E8F00ULL, 
            0xDA23084C429CEE10ULL, 0x38E498FDF90FBBC4ULL, 0xE710E39330C7A44CULL, 0xEBFE95C12635BF56ULL, 
            0x1269A12BA6F4DB85ULL, 0x01F55C3862CB318AULL, 0x88A63A9424360E78ULL, 0x2BBF0A71FC6DF555ULL, 
            0x673DD4FD9703F203ULL, 0xEEB2ECC2DFCB89D2ULL, 0x575D132BE1F892BDULL, 0x321AC1238EF691E9ULL, 
            0x40A524133D78316FULL, 0x26789DDD87FC3331ULL, 0xE3A7E929313EF059ULL, 0xEDA32AC54FBBBDCBULL, 
            0x333919CF4BD8A105ULL, 0xF676120ACEA001CFULL, 0x61A802466DA70E77ULL, 0xD94C986CADCBE495ULL, 
            0xBC3A4E0F58B45CC2ULL, 0x9B444EA3E505E5AEULL, 0xD727A2D65B959FD4ULL, 0xA60D905D067ACA85ULL, 
            0xB3B4A30D4C529014ULL, 0xC8A0D40A056D34BDULL, 0xF9F9361048785347ULL, 0xD1995F848B66478FULL
        },
        {
            0x9652EFC6D129FD95ULL, 0x4D30C91C886208BCULL, 0x1D284A9C399F0D03ULL, 0x1CA8EBB54B10B0A0ULL, 
            0x2A5A4C0FB63583E1ULL, 0xED461D45B8605C73ULL, 0x6BF18B4D2CCB73C0ULL, 0x5E639A04F7AF2F3BULL, 
            0x26CC5611B842CB0CULL, 0x08F912E1720EEDB4ULL, 0x2EFBC89ABAACA85CULL, 0x199855696684C70BULL, 
            0xD7FE0214E1E9D5A6ULL, 0xF0FE0A9980ED528CULL, 0x8685D47C98511152ULL, 0x2496CB67C756468AULL, 
            0x25FBCD156DB68AE0ULL, 0x60884016B7432B0EULL, 0x9FC9F668B4BC479DULL, 0x15EACA488FF158BEULL, 
            0x7D6B49DFAB0A5CDAULL, 0x3BF036D6D02687D4ULL, 0x92D2CEFF3DE66330ULL, 0xF4B7A0F2355D41E6ULL, 
            0x1189F7957D406E73ULL, 0x93867C9F4BEB3D65ULL, 0xD9F1930A37463CCBULL, 0x6840DADBD33D6CBDULL, 
            0x07EF21361536DB7EULL, 0xC37B37F9D5D7CDD0ULL, 0x857A2ABC8232F8B4ULL, 0x15068DF54D77D0E8ULL
        },
        {
            0xF422FE77CB8BF019ULL, 0x481DD41B7D6F4283ULL, 0x581F85E18022E566ULL, 0x26CC6F3C82A9CD6FULL, 
            0x8CA64B85E1C7ACB1ULL, 0x01AE4DC0D896A560ULL, 0x0A7F3922C4DDB56CULL, 0x63F5F3DBB49AE751ULL, 
            0xB233D614E6B522B9ULL, 0x8E864D8AF56A2921ULL, 0xA9FD5BBBE63DF3A6ULL, 0x1323439A33B3CAB4ULL, 
            0x93C98524B0149FAEULL, 0xD0C90592960F3CADULL, 0x1A9CDCE9615CD15FULL, 0xF7B80B697B1F5FCFULL, 
            0xCC6CB32651832AFEULL, 0x0780C1036E90AD28ULL, 0xD99E07657548898FULL, 0x98B425EC2C5808F8ULL, 
            0xD50DDEFF0284C0E9ULL, 0x90B3BA9743DE139EULL, 0xAEDC5A79B294853AULL, 0x594292DA02BD955EULL, 
            0xF62FE29E77673768ULL, 0x16BEA70927769E49ULL, 0x0221B7D0B8E78614ULL, 0xE59D8005F1A28199ULL, 
            0xF8637DBAFA91419AULL, 0x011B9573AA9782D7ULL, 0xC5BE8CC3EDDEBC40ULL, 0xDC9A82232318CDE8ULL
        },
        {
            0x1BC1BE13D209FB68ULL, 0xAFF7BA97A675E89DULL, 0x6C9FE33FA02BBB54ULL, 0x7BB55462634260B9ULL, 
            0x9E2225F3D7FBBEF3ULL, 0xD31B0D2007BC1A13ULL, 0xF52A75F618617C28ULL, 0x4A037AEBCA311103ULL, 
            0x24FDA09D6673E949ULL, 0x0B9334BE28FF1ED8ULL, 0x67E297F53955ABE3ULL, 0xC7DD0AD8CC165DF7ULL, 
            0xBF65F4F20661847FULL, 0x1145BA1003D611CCULL, 0x0DAD9C3ED84AB3C2ULL, 0x88840FDE14981E29ULL, 
            0x3012F28E3428836AULL, 0x158CE0C922843899ULL, 0x322A30E222B30A77ULL, 0x3645C471EC516A30ULL, 
            0x61D64B12C8FA5EF4ULL, 0xA965C36305E3AA0DULL, 0x57E0E0F414DF8116ULL, 0xCA5F42C1368E9A2BULL, 
            0x26283D35A20A8A00ULL, 0x957DCB3911E5FC32ULL, 0x58D270310C08FDCBULL, 0x568E639DD1DFEF8EULL, 
            0x8173A254FA10152EULL, 0xFF54F9876C658949ULL, 0x8D8DAA056C5C6714ULL, 0x7C68B7CEF1D544BAULL
        },
        {
            0xEA2013882A946C35ULL, 0xBB9FC421824836B3ULL, 0x3308BAC5E017C824ULL, 0x135D559FA7CD6849ULL, 
            0x646D4FF35A27BC39ULL, 0x4619A19B0964D4B6ULL, 0x7A75F1BB1B1899D6ULL, 0x0BB5D14C1DB4E58BULL, 
            0xD2F98CD0D7278D44ULL, 0xC46B7E227E96143DULL, 0x8E923FC96DFDFF0DULL, 0x64C750AA02CF946BULL, 
            0x3D00052DFE69A9CDULL, 0x67FC6FAD6E3D7049ULL, 0x7D7E6B665F1992DFULL, 0x00BD14071EFA8542ULL, 
            0x02221FEFE3CB32C3ULL, 0x9347B8BBCE6E57B7ULL, 0x63BD7A38D1C3DD0BULL, 0x4E7C155A2A875F6BULL, 
            0x0F0645A4499D4072ULL, 0x3E213F7C72450941ULL, 0x27FC5AA62A7B0E92ULL, 0x5CE76277C182B18BULL, 
            0x7136A4BF11647EBEULL, 0xA2E06408D1903911ULL, 0x4A9CCB10C4E86ED3ULL, 0x40D3E807737100EDULL, 
            0x97994A5B20C1F972ULL, 0x6865B83065B86547ULL, 0x1333A59064DBAFF8ULL, 0x006BF4119FDC9C4DULL
        },
        {
            0xBD5C56C79494CE35ULL, 0x8C1596F8A210E76DULL, 0xB35A74416AC5A3D7ULL, 0x294599C1315A109DULL, 
            0xEFC891B19D12EB8FULL, 0x1EC17B78BDB1EAF8ULL, 0x83C72A79D536FE70ULL, 0x6C61D9B7D9EB86A5ULL, 
            0x2FD4D87B23E3DC3FULL, 0x6BAAA99143135710ULL, 0xEA1A74EEDA7BBCC6ULL, 0x4AB06430A4E4E5F5ULL, 
            0xC7CECFC4443BFC91ULL, 0x6ECD34DE63074A06ULL, 0xC84C87D9F73A48CDULL, 0xDF68599CBB7B3096ULL, 
            0xC6BB2F45E7AF7419ULL, 0x023A31B6D225C1A7ULL, 0x07BE9089EDB4AE0AULL, 0x5A9387ECCFA614E8ULL, 
            0x0A7BD87A7BFFBC0AULL, 0xF4D2B66043BA273EULL, 0x61D4DFF8B2851453ULL, 0x36F40590112F07FEULL, 
            0x2B78CAA9E5D555B4ULL, 0x909C83AC04D25D55ULL, 0x9C34F91673FDBF19ULL, 0xC1DC66B6719C9F17ULL, 
            0xE131C2B9265CF3D3ULL, 0x93F494C2B5BD8AB1ULL, 0xDF502B46324A79C0ULL, 0x6B3FFD3A17CF1A7DULL
        }
    },
    {
        {
            0xF3CCBDB0B887D4F1ULL, 0x0987658A057E234EULL, 0x3BB5C0977E657AF2ULL, 0xDB51AB17CC3B4203ULL, 
            0x20D915A2BFF3B252ULL, 0xA4AB66A3D1AA968DULL, 0xB00CC3EE98759E93ULL, 0x03E9695B134B7A6AULL, 
            0x86C36392DB071341ULL, 0x87A41083279228F7ULL, 0x75F22AD75A9C0F5AULL, 0xE5F56D690DEC4F29ULL, 
            0x033F8EEA79938326ULL, 0xFE97B4DB544D83D2ULL, 0x032CE87B0BD45CC4ULL, 0xD3796DB584F880D8ULL, 
            0x9DB54AEBA1850E97ULL, 0xE2C01BA9D2C59259ULL, 0xBBE400C5DF6BEB32ULL, 0xCA164666AD64A66FULL, 
            0xD3DF18C7CA683AEDULL, 0xB424076EF61CAAE0ULL, 0xAA61F1F1A04EBC4FULL, 0x3CF33F9794CBC4A8ULL, 
            0x8F41E5FF359EE6A9ULL, 0xA3BFE8DF65680158ULL, 0xC94EF8ECB75AF05DULL, 0x42F50741267FC2FEULL, 
            0xAEB74389861325ADULL, 0x37F5A0CF49AA23BFULL, 0x15C5A7FDF5B101E6ULL, 0x7D0C5CAF571C09E6ULL
        },
        {
            0xCB234D7BA6678555ULL, 0x3B8D2B13BF5B8383ULL, 0x7292C690E09EE439ULL, 0x873ABD95DB0188BBULL, 
            0xFC41B3106AEAF532ULL, 0x6D3A7B3B5BFDDF87ULL, 0xD1FE679EB48557E1ULL, 0x81C1375B186F2DBDULL, 
            0x135BAD00903CCC54ULL, 0xF022C6E9CA339011ULL, 0x4459064E738DEE5CULL, 0x40517EFF3053978AULL, 
            0x000D57E7FFFD8BCEULL, 0xB7593B7ED50075A9ULL, 0x15BB70189BED73BEULL, 0x0C3C1CC38D140F26ULL, 
            0x887E7AFA361BFF6AULL, 0xF78B9F04A7D7F3B6ULL, 0xA2DA59766DFE00FBULL, 0x08E4CB38EACB2929ULL, 
            0x798D6E50BA6DE588ULL, 0x7563BB16273CAE4DULL, 0x14F08B088A13D5B2ULL, 0xD4F25F41E60CD29EULL, 
            0x9C4E3C57304F6D6FULL, 0x0D1F73443603BB1BULL, 0x8AC639C3A6911F24ULL, 0xE4EFECD751DEADE7ULL, 
            0x07FC3D86B078A58FULL, 0x6DEAC16CCE246AC4ULL, 0x0EBC1EA1DED554EDULL, 0xA0096B9644CA00FFULL
        },
        {
            0xCCC0BD6D54FEE952ULL, 0x552AD87FDA811FDBULL, 0x0C66AF0690F7014CULL, 0xF4B0F50D1AAF3721ULL, 
            0x3BFD6C133CC33C36ULL, 0x44C5F01A9CB2256FULL, 0x1876E62517D7BACCULL, 0x031ACF1CCC5EC4E2ULL, 
            0x04DC276DDFB306D3ULL, 0x4A5BEB2DCE4F9729ULL, 0x838F07CB3D995808ULL, 0xC1157DF5548C0B3CULL, 
            0x643354FA2D543C8CULL, 0x90A962E6241AD5C8ULL, 0x6703492CED239AD1ULL, 0x08CA6F16FD224B6EULL, 
            0x390B12FB3FAA0922ULL, 0x374690AE9C8009EDULL, 0xA819AF88EC88AE37ULL, 0x80330924866B0B84ULL, 
            0xBAC51FA513EA04E6ULL, 0x76388095E2FE8702ULL, 0xFB8836286DB2765DULL, 0x4FB5F8EB27F8CCD3ULL, 
            0x9AD0D0A4948E3350ULL, 0xEA96332E5FBAD3D3ULL, 0x94ED17884A1F5B7AULL, 0x9A58A8A209BC8D21ULL, 
            0x938103B0ACA77829ULL, 0xE15BCD79F3619350ULL, 0x528923296849EF8DULL, 0x17232FFD15CEBA38ULL
        },
        {
            0x63C1C459D7B1799AULL, 0x1D7F74EA420E7484ULL, 0xBAF8D5FF4AB2C4FDULL, 0xD517D7F5DBB4710AULL, 
            0xAE7976F4C452700FULL, 0xBFEE1187AD716B53ULL, 0xA116231ACCD89412ULL, 0x0C878FAD46AB35A5ULL, 
            0xC98242718DFAA2C4ULL, 0xA428D2091837083CULL, 0xF000193B0755B494ULL, 0x4DCCBD930CFCC3ADULL, 
            0x3BF72C4127D17967ULL, 0x242D6EC931C5CF9BULL, 0xDB8217E8FF0F87BFULL, 0x7B6C8F4AA88FE438ULL, 
            0x13B23DE16BAA98FFULL, 0x62D27E7F8E78E57CULL, 0xB0B535ACE6BF5456ULL, 0x7A94D692FE8C06E5ULL, 
            0xC76E06B320529045ULL, 0xE210FE09A9DF3787ULL, 0xAE694959F7530C0DULL, 0xD9485216B14C4B3FULL, 
            0x7E1BF29B5FB687AFULL, 0x1AA674F0FC325F09ULL, 0x074124E69A9E35B8ULL, 0x916F34F975739F71ULL, 
            0xE13C40EE67A05A27ULL, 0x7DF4A6BA3149AF82ULL, 0x09E2A366713DA690ULL, 0xED9C9C9DD10B211CULL
        },
        {
            0xCB437444DCD23071ULL, 0x41054F1EF3DA3942ULL, 0x76D9A10871EA7C4AULL, 0x2345B21E6F2E5914ULL, 
            0x2C5FEC67BA3A820BULL, 0x105889DBBE65C7C5ULL, 0x06BA8361B86F54C9ULL, 0xD43D6A3F89A22BA0ULL, 
            0x703A50451B5B8BFFULL, 0xDC04870CC0B956ADULL, 0x4717EC37352DEC0BULL, 0x8B9FB9066934D950ULL, 
            0x08A15F5EE846C54AULL, 0x9145145988F91BA1ULL, 0x876C64046CEF50AAULL, 0xC303E7AA4ABC38BBULL, 
            0x08CFFEBC6402A138ULL, 0x30405FCA1A1407FEULL, 0x47E51DC1D8D0C046ULL, 0x919E6699D19FB7F8ULL, 
            0x6BBF8610F0BA745DULL, 0x366B5A27405A5097ULL, 0x8A3C868EEC970927ULL, 0x0E94E6C0E956BADEULL, 
            0x9E0306FA023F66E5ULL, 0xA55CAEFED5D71D30ULL, 0x63AF8C0660F7A67DULL, 0x903E807B1D225A08ULL, 
            0x30A33CB628D0B833ULL, 0xF005737B75702E10ULL, 0xA6B1AC72360EB31DULL, 0xA9C206EE3E7B6046ULL
        },
        {
            0x788A20CD2B65C63DULL, 0xF3B8A4878AF36633ULL, 0x2B202F74EBCBCFBDULL, 0x1333A79BDA1F9D07ULL, 
            0x8324C2395C90CF58ULL, 0x20228FE3C83701B2ULL, 0x3E03A221797E5C16ULL, 0x10EBAFFAEE7C25D5ULL, 
            0x09029186EFD87321ULL, 0x28F543C25811CE7FULL, 0x85199013977AAC40ULL, 0x9D90102F3BC0B6DDULL, 
            0xB642844969EBF341ULL, 0x9D319F2888CE5A9AULL, 0x7279981B21C123C4ULL, 0xEC8756F674C49794ULL, 
            0x47621D47032EF0F9ULL, 0x9C049DEF2C769182ULL, 0x6595C2729AD01C21ULL, 0xFFB50536BB188DBEULL, 
            0xE936E1243A3B1CF7ULL, 0x78929C5B7B825861ULL, 0xDE1FD286FE0D0B01ULL, 0x99993B07D2FA4AD0ULL, 
            0x148AE2AF043F4B62ULL, 0x04B4550D8B1DD01DULL, 0xEECA755DFCE5365DULL, 0x8091959D59AE48C9ULL, 
            0xB6A48CE30D1B3FF7ULL, 0xBFBC5D9049E365B2ULL, 0x607F114FC92CABE1ULL, 0x817B6EE6E8E1C9A3ULL
        }
    },
    {
        {
            0x83278AC2A1474CFBULL, 0x03F7514EDE87C215ULL, 0xA883B96491AF11C3ULL, 0xE377E769CC71E5DEULL, 
            0x128ECF035D337E9DULL, 0xFBAD63D64144094AULL, 0xD89A6ACA75AB6571ULL, 0x1DA7AFB514C60D4AULL, 
            0x9889800912EF6130ULL, 0x8EEF188FEB0FC82EULL, 0xA2BBD5A53DCE58ABULL, 0x507F93EDEDB4CF8DULL, 
            0xF42234BC3D79C2BBULL, 0x687ACADBC3EA2505ULL, 0xF959490695ABD659ULL, 0xBC9F84C42EF0A115ULL, 
            0x702C6F5F9420F242ULL, 0x33C0FE2D69D0CDD8ULL, 0xF830015CF95DA07CULL, 0xA6F4435C6896E92DULL, 
            0x771042713CB6549AULL, 0xC4DFE66384CC8F8FULL, 0xA6773709372E62FCULL, 0x2B4DADFFEE42A049ULL, 
            0x2A4EF7BC065FE6C2ULL, 0x1DFD95AFBFF51C5BULL, 0x716C71C3EA483073ULL, 0x81EBDD5B527AD376ULL, 
            0xF0428117223CECC8ULL, 0x4717BBB4AE99A816ULL, 0x07E66CDA0F720BA0ULL, 0x1BBBE5868A368DEDULL
        },
        {
            0xBFF92AE6462D0916ULL, 0x34263992D9D9E9CFULL, 0x30B7588B898FA2F9ULL, 0xE9FD7AEDC9DC302FULL, 
            0x5634C28D08A99D01ULL, 0x2E9CD8FDEE2DA3CFULL, 0xF19D294AE80F2C8EULL, 0x927E0285FB587908ULL, 
            0x8179C8F505685F07ULL, 0x57A59878006730B5ULL, 0x849947F0C4E0DB72ULL, 0xD4A4A0F72EBF9D0BULL, 
            0xC3135E0BDBD05AC9ULL, 0x230E4E35B1F1412AULL, 0xBD287050C1857274ULL, 0x534852C2C35765D0ULL, 
            0xF65631A2FB9D1523ULL, 0x5004F900DA7CE17CULL, 0x46F879BF523FF70AULL, 0xD476A6730B6EFEC7ULL, 
            0xD99A12CAB041D57FULL, 0x614CEC805C12EE24ULL, 0x4419479FBFA547C1ULL, 0xB0AA3715D5A23794ULL, 
            0x83AF0A03D4A56047ULL, 0xE4568A971E1379B4ULL, 0x529E7E7E5D622298ULL, 0x37B37E32FA266C3BULL, 
            0x83F8C5A5783A6D2BULL, 0x1487EC5E1209176CULL, 0xF6D6A1DAEDF8A5DDULL, 0x7CA1A4D4FCAEFE21ULL
        },
        {
            0xF1B584CE84EA2D1BULL, 0xEFCA253A3EE0DC99ULL, 0x32F04321B5C09485ULL, 0xB03B71DD43088D29ULL, 
            0x62F6BFE27ED2158EULL, 0xE94DA2870C09A04BULL, 0x6BEB6FE9B41CA2CEULL, 0x398FCA89492A0250ULL, 
            0xCE59BCAA9EBED2CCULL, 0xBE7129D39F552191ULL, 0x17ED24F29E7C0F23ULL, 0x4D2E4E22D1F393C9ULL, 
            0x1ADC4C4D3427D0BDULL, 0x06BB0C6AE4849797ULL, 0xFE01C655CBC23DACULL, 0xAAEF3AC3A5E39607ULL, 
            0xC495A84C8DCB9C3CULL, 0x6AEA78452B35FBFCULL, 0x6A6FB1F532FDC322ULL, 0x75146C7E326FC6B0ULL, 
            0xC0364B4710E53176ULL, 0xA187E5534109D256ULL, 0xD1369FF9734B1016ULL, 0xF0D2096F99D34C6EULL, 
            0x8186F7F55A5CFAC6ULL, 0x3344412AA4B67DBCULL, 0x2271E74108DC24A6ULL, 0xFBB27A938020CFB2ULL, 
            0x3800B99762575BFFULL, 0xAC965643A3E9493BULL, 0x4C84C4DA74ED8896ULL, 0x8E02013307C0FA66ULL
        },
        {
            0x69CF03001EEE7188ULL, 0xB0F7691D008A04F1ULL, 0xE9BB07CCCAD3776EULL, 0x8CF571085F9E091CULL, 
            0xCAEF26D622156914ULL, 0x465707F4DDF861D2ULL, 0xCA65C312E3235895ULL, 0xF6E8F9FDDD106D6BULL, 
            0xE230E524FD02732EULL, 0x6A091FA11296E67BULL, 0x2C97077C362E5E37ULL, 0x59951F431F06A890ULL, 
            0xBE55BD09F6EDFF0AULL, 0x3FB769E3B2ACA250ULL, 0x259176982AB6E503ULL, 0x2C700810BCC52F3DULL, 
            0x13A2E73E7EBFCA75ULL, 0x51C48153C24322F4ULL, 0xF6FF4A183418FD86ULL, 0x0FD16DB2C0345FB7ULL, 
            0x143E36463360C385ULL, 0xED910A30E9A5C94EULL, 0x5039A83134BEADFEULL, 0x17A998CC9FD0A534ULL, 
            0xF615C73B10F373EDULL, 0x8CED7FE1847620ADULL, 0x3B64CBE3F03141F0ULL, 0xEAC29E92E542C7ACULL, 
            0x6FBDDB942BDF11D4ULL, 0x0769A352956E2B56ULL, 0x0C9D8AB1F4AE4D1AULL, 0xCF8FF9E4AA6FB3D8ULL
        },
        {
            0x2C7206AC28E0F6F1ULL, 0xAA2A06EFA73F297EULL, 0x42F337101108EA80ULL, 0xC86F5CCA8D046EAEULL, 
            0x5D121B3DE6A8990EULL, 0x30FA7806CC1753B4ULL, 0xB77B48065C5062F3ULL, 0xDEAB3F06371373DBULL, 
            0xBB89AA9D1B53CD9CULL, 0xD64B50A4C5F64233ULL, 0x07A735BBC39CF74DULL, 0xC99750239F1645A1ULL, 
            0x132201392385630FULL, 0x7DA69F71BD1817D7ULL, 0xFC958C6FBC5FFB63ULL, 0x73A20DD0E8C907D7ULL, 
            0x86708CF62B792A1EULL, 0xEF5C3C9BBEB0D49FULL, 0x6728F0F416D62E00ULL, 0x2B9F3FE6CF4D6DE4ULL, 
            0x26A8837D12B1FBBBULL, 0x36E5394337109884ULL, 0xF4F6137E86058727ULL, 0xC27E6ACE72AF9073ULL, 
            0x470C4AB29A2A9293ULL, 0x5DFBA81E66CC8EF6ULL, 0xE6ED67E6EF14A97DULL, 0x3EA96A82BF763F2AULL, 
            0xAB0AD3FB18123F43ULL, 0xC2EB508F0C462A59ULL, 0x8B898A210C970956ULL, 0x44D231B4CE8909AFULL
        },
        {
            0xECC95E7951F5C853ULL, 0x0D7C1E018DA88973ULL, 0x31F2C0291D2B6C95ULL, 0x4C0C0EBC1ABACDF9ULL, 
            0x299B00DCE244E8F9ULL, 0x5DCBF7CE6D54F48AULL, 0x7212A29B0411F2F6ULL, 0x39729F5F044BF47CULL, 
            0xA0D3EAE57EC74856ULL, 0xC403276CC042C9E9ULL, 0x5641F1CD492581E1ULL, 0xFD0C74A34ED3DE02ULL, 
            0xF2EFCE5B7716E0D3ULL, 0xD1EF98E28011DE7CULL, 0xCD8E3F8C7B8DE65FULL, 0xD31C597CDB85517EULL, 
            0x9CE46E23F2F2794DULL, 0xE1A564CDB92CF4B6ULL, 0x3F3AF1A0836BF90EULL, 0x45AF25B3C85298ABULL, 
            0xC61F9C6E64235CFAULL, 0x3ABE22C64FDBAD8DULL, 0xC1C08903578FA53DULL, 0x5696A62398B57151ULL, 
            0x2E3CF1A17F3B353DULL, 0xED18F6DF0F6FBE39ULL, 0x8F749F327E7DD909ULL, 0x1A5A6846A0F77D03ULL, 
            0x96978DCC5EB351A8ULL, 0xB1BFEC120385BD9DULL, 0xCA0F6EB2B9DB6D5DULL, 0x8C4436CFE76AB2E3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseHConstants = {
    0x3ACFF87FAEBC4779ULL,
    0xBD42E29CF402E98CULL,
    0x136A363FC2E1883DULL,
    0x3ACFF87FAEBC4779ULL,
    0xBD42E29CF402E98CULL,
    0x136A363FC2E1883DULL,
    0xDBF49D85B9BC6F2DULL,
    0x63E934B64E63A298ULL,
    0xB4,
    0x7E,
    0xBF,
    0x04,
    0xE6,
    0xDA,
    0x43,
    0xBD
};

