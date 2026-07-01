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
    mDomainBundleEphemeral.Zero();
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
    std::uint64_t aPrevious = 0xA4842F3A303BD6B9ULL; std::uint64_t aIngress = 0xBAF04D996ADBDABAULL; std::uint64_t aCarry = 0xB360D7B7D19AA49EULL;

    std::uint64_t aWandererA = 0xFE6D58B782158F11ULL; std::uint64_t aWandererB = 0xCC50C001D17DD300ULL; std::uint64_t aWandererC = 0xE66F632DBCDFA7AEULL; std::uint64_t aWandererD = 0xD5204A4ACE70F67BULL;
    std::uint64_t aWandererE = 0x82CEC0446876207AULL; std::uint64_t aWandererF = 0x974B355D46CD9829ULL; std::uint64_t aWandererG = 0xBCDA30B5C761A26AULL; std::uint64_t aWandererH = 0xFD8451774703F093ULL;
    std::uint64_t aWandererI = 0xDAA69B60DA5DACCEULL; std::uint64_t aWandererJ = 0x8E1DB227C9584188ULL; std::uint64_t aWandererK = 0x82FD8DF965A57C9EULL;

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
        aPrevious = 18117041157846311415U;
        aCarry = 10196890525737461244U;
        aWandererA = 15219403738058714784U;
        aWandererB = 16187142539342162556U;
        aWandererC = 14029125282239309395U;
        aWandererD = 10110885014845953724U;
        aWandererE = 16353249322594400325U;
        aWandererF = 12417541265751167395U;
        aWandererG = 16725389181143365925U;
        aWandererH = 15478351417420527081U;
        aWandererI = 14279036063600460447U;
        aWandererJ = 14241713940497024631U;
        aWandererK = 14914921651357977065U;
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
    // read from: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // temp storage: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    TwistExpander_PingPong_Arx::KDF_A_E(pWorkSpace,
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
    std::uint64_t aPrevious = 0xEB4BB443D85E23E7ULL; std::uint64_t aIngress = 0xED19FF44AB3DA1DFULL; std::uint64_t aCarry = 0xF9F79BBDF87352F0ULL;

    std::uint64_t aWandererA = 0xE3B3602C1A6EC3CDULL; std::uint64_t aWandererB = 0x8CB04C1BD9E2ADDFULL; std::uint64_t aWandererC = 0xB82455BA80CD800BULL; std::uint64_t aWandererD = 0xE7AE20269AB1D1E3ULL;
    std::uint64_t aWandererE = 0xE3BD6DEB76E1DB51ULL; std::uint64_t aWandererF = 0x96118C2C47020077ULL; std::uint64_t aWandererG = 0x961431F875494E70ULL; std::uint64_t aWandererH = 0xB36DD65042584DD3ULL;
    std::uint64_t aWandererI = 0x91DD45451FEFE035ULL; std::uint64_t aWandererJ = 0xA4E7E3677F6BF7F1ULL; std::uint64_t aWandererK = 0xF58EC1CB69A3938BULL;

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
        aPrevious = 9441295038737172222U;
        aCarry = 12142012604063736844U;
        aWandererA = 11403857674020659201U;
        aWandererB = 16271327604738654845U;
        aWandererC = 15530752036933670728U;
        aWandererD = 12898642294699907722U;
        aWandererE = 10267842038332342778U;
        aWandererF = 10845691706730141407U;
        aWandererG = 12510827581474102175U;
        aWandererH = 17953004365189281575U;
        aWandererI = 17664511493774825774U;
        aWandererJ = 13125154839868183338U;
        aWandererK = 10908584303026672788U;
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
    // temp storage: water_a, water_b, water_c, water_d, source, wind_a, wind_b, wind_d
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
    // temp storage: expand_a, expand_b, expand_c, expand_d, earth_d, fire_d, water_d, source
    // ---------------------------------------------------
    // write to: fuse_a, fuse_b, fuse_c, fuse_d
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
    std::uint64_t aPrevious = 0xC2C28747EB24F286ULL;
    std::uint64_t aIngress = 0xD48DF75ADC78E928ULL;
    std::uint64_t aCarry = 0xAB2563D12B5E782FULL;

    std::uint64_t aWandererA = 0xCA452FEA88785868ULL;
    std::uint64_t aWandererB = 0xEE75B1C6EB937B24ULL;
    std::uint64_t aWandererC = 0xBFA190457142AF66ULL;
    std::uint64_t aWandererD = 0xC34FE741296C840BULL;
    std::uint64_t aWandererE = 0xB84C74DF1A1B8F27ULL;
    std::uint64_t aWandererF = 0x8E6D479F848682CAULL;
    std::uint64_t aWandererG = 0xF602C1EF04617B7BULL;
    std::uint64_t aWandererH = 0xE3F0B1810FD0AE64ULL;
    std::uint64_t aWandererI = 0xA409BA197D63FAEEULL;
    std::uint64_t aWandererJ = 0xB7FE90F511C6F986ULL;
    std::uint64_t aWandererK = 0xA2E1F4526F1BF2AFULL;

    // [seed]
        TwistSnow::Sha256Counter(aSource, aSnowLaneA);
        TwistSnow::Aria256Counter(aSource, aSnowLaneB);
        TwistSnow::AES256Counter(aSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, earth_a, earth_b
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
    // read from: work_c, work_d, earth_a, earth_b
    // temp storage: work_a, work_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: earth_c, earth_d, operation_a, operation_b, operation_c, operation_d
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
    // GSeedRunSeed_F seed_loop_c:
    // ---------------------------------------------------
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: snow_a, snow_b, water_c, water_d, earth_a, earth_b, earth_c, earth_d, fire_a, fire_b, source, key_row_read_a
    // ---------------------------------------------------
    // write to: snow_c, snow_d, wind_a, wind_b, wind_c, wind_d
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
    TwistExpander_PingPong_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Seed_I(pWorkSpace,
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
    // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
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
    std::uint64_t aPrevious = 0xABF236B63E14EA58ULL; std::uint64_t aIngress = 0xD799E1535AA75E93ULL; std::uint64_t aCarry = 0xB6D64DBD02CB7DC3ULL;

    std::uint64_t aWandererA = 0xA2011EE9244FE5A9ULL; std::uint64_t aWandererB = 0xFEAF6F03C4E571B6ULL; std::uint64_t aWandererC = 0xA9C0082A35D59AA5ULL; std::uint64_t aWandererD = 0xB1992D06EA4C694BULL;
    std::uint64_t aWandererE = 0xFDE870F7A90EF3DFULL; std::uint64_t aWandererF = 0x8023A6D93BCC89EEULL; std::uint64_t aWandererG = 0xA9F99B3AB3B63995ULL; std::uint64_t aWandererH = 0xE027B8F768801336ULL;
    std::uint64_t aWandererI = 0xC0E17AEB641161ECULL; std::uint64_t aWandererJ = 0xACF377FB20AB38FFULL; std::uint64_t aWandererK = 0xDBCDB8D0FF552A4CULL;

    // [seed]
    {
        aPrevious = 11968035951727394853U;
        aCarry = 15326479046003662781U;
        aWandererA = 16421610492958733438U;
        aWandererB = 16128392830693118567U;
        aWandererC = 13438918363288284227U;
        aWandererD = 9455838731008297993U;
        aWandererE = 12372746798965577180U;
        aWandererF = 12832556219843524439U;
        aWandererG = 17597247818591481298U;
        aWandererH = 9682085592995103506U;
        aWandererI = 15263710091358750433U;
        aWandererJ = 9921187575268734296U;
        aWandererK = 13914807474497700604U;
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
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: water_c, water_d, snow_a, snow_b, snow_c, snow_d
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
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    // write to: water_a, water_b, earth_a, earth_b, earth_c, earth_d
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
    // ---------------------------------------------------
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: water_a, water_b, water_c, water_d
    // temp storage: wind_a, wind_b, wind_c, wind_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, invest_c, invest_d, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_PingPong_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_PingPong_Arx::Twist_E(pWorkSpace,
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
        // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
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
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 2, 3 with offsets 6820U, 716U, 6888U, 4956U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6820U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 716U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6888U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4956U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 3, 3, 1 with offsets 5727U, 7518U, 859U, 2414U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5727U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7518U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2414U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 1, 1, 0 with offsets 598U, 2341U, 4944U, 6376U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 598U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2341U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4944U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6376U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 2, 0, 2 with offsets 1876U, 5872U, 6891U, 523U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1876U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5872U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6891U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 523U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 3, 2, 0 with offsets 857U, 1715U, 563U, 2007U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 857U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1715U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 563U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2007U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 0, 3, 1, 2 with offsets 1023U, 200U, 668U, 540U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1023U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 200U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 540U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 0, 3, 1, 2 with offsets 2033U, 164U, 455U, 1695U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2033U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 164U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 455U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1695U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 0, 3, 1, 2 with offsets 85U, 705U, 1959U, 724U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 85U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 705U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1959U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 724U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 484U, 842U, 1371U, 1664U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 484U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 842U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1371U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1664U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PingPong::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 531U, 4139U, 3378U, 6117U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 531U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4139U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6117U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 3 with offsets 2891U, 293U, 7096U, 2914U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2891U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 293U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7096U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2914U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 1 with offsets 4867U, 5118U, 3471U, 1781U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4867U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5118U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3471U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 1, 0 with offsets 3039U, 5733U, 1204U, 2945U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3039U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5733U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1204U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2945U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 5104U, 3297U, 7945U, 4653U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5104U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 3297U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 7945U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 4653U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 217U, 153U, 827U, 945U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 217U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 153U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 827U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 945U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1026U, 1964U, 935U, 1794U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1026U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1964U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 935U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1794U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1252U, 1536U, 338U, 839U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1252U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1536U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 338U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 839U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 45U, 751U, 173U, 977U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 45U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 751U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 173U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 977U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 3, 0, 1, 2 [0..<W_KEY]
        // offsets: 1437U, 1811U, 901U, 1499U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1437U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1811U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 901U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1499U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseASalts = {
    {
        {
            0x2E877F934B0A7555ULL, 0xE0C38C041092A2C0ULL, 0x9473383B39CB10CEULL, 0x9B847B77E1A21D7BULL, 
            0x7B0F75EE79F17658ULL, 0xD5FE25677AB85363ULL, 0x922540B288B8980EULL, 0x4D376CDC0FFB156CULL, 
            0xDF254FA3AC173CC6ULL, 0x62DD844EB3215462ULL, 0x208C0B612F1CA106ULL, 0x92F5445A1C02FB0EULL, 
            0x147BBAC4B4E9F5FFULL, 0x9B0366F0327B9A64ULL, 0x58F960DAF6EFBFDCULL, 0x66562FF85B9F97B0ULL, 
            0xB5E833622FE49EEDULL, 0x38F3291FB0117014ULL, 0x64475716916ABB07ULL, 0x221E4C06F6333777ULL, 
            0x53FA950DBCE18142ULL, 0xEDBBB9A3F83E6824ULL, 0x3E28725FA57893CFULL, 0x8631810B7B26BEC0ULL, 
            0xE735D64F7A73A58BULL, 0x0E02B9AEB2101448ULL, 0x315D8DAF9B42AD89ULL, 0x33E1736CA7331D94ULL, 
            0xFAAAF13BE8E28BBEULL, 0x1C2278333E8A6F82ULL, 0xE51E174E9391872AULL, 0x78E830CBF833F758ULL
        },
        {
            0x7C3744415BB07D25ULL, 0xD82BE0D78352A9C7ULL, 0x1A003D50F43D8AA9ULL, 0x4738534235CF861BULL, 
            0x2841827B7CDEBE0AULL, 0xB55FC4001B2221C5ULL, 0xA38B773BAE735428ULL, 0x07A3D6BE80AA71D2ULL, 
            0xF77D9F693D84BFABULL, 0xF8C18A6B9DD2DB3DULL, 0x4DDC85991A205139ULL, 0x6F28EEC9D4408BD8ULL, 
            0x3B5B3B7097D2EA6FULL, 0xB650DD202344D40CULL, 0x65A10D37E2209FE3ULL, 0x626677C1B88B08D3ULL, 
            0x175EE10251BF2499ULL, 0x2338A30C6C6F7ADFULL, 0xAEB519A952137435ULL, 0x72437651BF21A945ULL, 
            0x5D61C429008211ECULL, 0x4FEA4B49EC1D0DF2ULL, 0x85BAF98550529346ULL, 0xC65299A6605E21DFULL, 
            0xD0C9404006DC73ADULL, 0x8D358C7A89240605ULL, 0x0E1436792970FF4EULL, 0x85F19D2AB34E427BULL, 
            0x7620171F52CF4D0EULL, 0x4217453FE0455375ULL, 0xD3333A8D7D9ABFD1ULL, 0x0C07653332A626D5ULL
        },
        {
            0xAEF07DA8EF4DE2E4ULL, 0x952532EB5EF8D3A9ULL, 0x6527BEE3CD8ACF87ULL, 0x06F32CCDB6AA2265ULL, 
            0xF442C2D11284EB73ULL, 0x3C366540DF93F262ULL, 0x69CDF48E738317A4ULL, 0x9BA39DC1E9D8E24AULL, 
            0x5DBE671DB5DE1697ULL, 0xF93DB721DF0BB142ULL, 0x8852BDAD859DA980ULL, 0x0B211C3B6351BB82ULL, 
            0x5C59919BACEF4709ULL, 0x08D01906CDF51DCFULL, 0x3BFFA179677631E2ULL, 0xCAE3C553BEB424A6ULL, 
            0x68451DE0BEFC19F3ULL, 0x416D9D096EE6D3BCULL, 0xD4BFF47E0045C2AEULL, 0xA5D191DC9C3541A9ULL, 
            0xD9F56459B210A185ULL, 0xBF19F55EB6C7D03FULL, 0x4FB262A24BCDEAF3ULL, 0xD760566F677F7CB2ULL, 
            0x89FD318C75471B81ULL, 0x72EEC79E9B7C5598ULL, 0xA0CFD0842BB81C30ULL, 0xC84AE0B62E5ED1C1ULL, 
            0xCBA9033A6E02B947ULL, 0x85273EEA1AC69F57ULL, 0xF475B737954EAAB9ULL, 0xCFC4B00361F99543ULL
        },
        {
            0x6012AD87257FA698ULL, 0xFE580118BA43DE76ULL, 0x781764C8B5784E6BULL, 0x6B21313D18622D5BULL, 
            0xAF2FDB4522A5FEBEULL, 0xD345BA0D113736A1ULL, 0xD5CE6CCA38903E51ULL, 0xA437E8A09EE896CAULL, 
            0x0758082E2F4376BFULL, 0x87FB61645F652F7DULL, 0x2BE47619F0E72A09ULL, 0xEC549B7FF99CFFF4ULL, 
            0x47249B0D0552C77AULL, 0x3B0DA54202F6A2FCULL, 0xAF74F419D91DBEB9ULL, 0xB75F3CF1C0FC64CAULL, 
            0xC39E088A797A88A3ULL, 0x84A626F7FCC7D6C0ULL, 0xEDEF37BE5CE1C1F7ULL, 0xE8354DFCCB9D4032ULL, 
            0xA49786DC2A9CD7BAULL, 0xBCC069BE6B0E19FCULL, 0x4480B96D3F6EA47CULL, 0x32035527131A1287ULL, 
            0x6B24390B5922CDD9ULL, 0x8E0D3E87E536A4F2ULL, 0xA472FBC42055EE94ULL, 0x3473C98B80CCE80FULL, 
            0x2823E793DD50D214ULL, 0xA4490B0CE4EAAD52ULL, 0x7BEE7F86918F4D2DULL, 0x5662EC66546D1895ULL
        },
        {
            0xDB2236479A7A8D69ULL, 0xF1DC1D93E5F0045DULL, 0x6CAACD8C164656E0ULL, 0x563145BE449A44EAULL, 
            0xE0AB4FB51BDDE564ULL, 0x68B89C0AAE301234ULL, 0xB1CB44F2166DC295ULL, 0xC28D88D52385276FULL, 
            0x204C686ECA1DB6CBULL, 0x7094F64806FB85D4ULL, 0x408D94D81AC8FB80ULL, 0xF1EFB6D0D2F5DBEEULL, 
            0x917FB534B8E04A65ULL, 0xE88A60CC1C8B659CULL, 0x58E00420CE44894FULL, 0x671D1A5E3AD97533ULL, 
            0x3CC5547A913CCEC7ULL, 0xC7A62E1F5114E03EULL, 0xFA24E4BFA13C8A81ULL, 0x8F0170F83B6E4124ULL, 
            0x696909DD1A710496ULL, 0x35C619DBB4AA0A68ULL, 0xF73C07C6AD80EF9AULL, 0xE1CD1213BFF39A4FULL, 
            0x20FE2D3EA547FC04ULL, 0xEA28ADB6541E374EULL, 0xA6A7792AA5F7671DULL, 0x9917C0C9A28C494AULL, 
            0x532030FE0DFC92BFULL, 0xEAC5225600A96AEAULL, 0x6BDC54CA22B6CFC9ULL, 0x7356FFB458A56C1FULL
        },
        {
            0x58F69AC7A1E5D139ULL, 0xA0E496361F2B0DB8ULL, 0x33EB48D2FFDBF23AULL, 0x885F193CBB87C82EULL, 
            0x3D4B70D064092BE0ULL, 0x59CF3788B081DC4DULL, 0xFDFE3FDD2590746EULL, 0x2DEBCB1440413E48ULL, 
            0x96CC0CD37E507D91ULL, 0x9901E65229CBBF26ULL, 0xACC1C97949AFFCA8ULL, 0xC534BBE469D64B74ULL, 
            0x9986580A2C72ED3AULL, 0x613DAF409335CC22ULL, 0x47D3E1F52BD84666ULL, 0xD3E02B7C1504F036ULL, 
            0x915DDBD15CE75BB3ULL, 0x53275EC6EBCA39CDULL, 0x74914E60C2A2D021ULL, 0x5290B0EBC6EA28B5ULL, 
            0xE65203A3EF88FE18ULL, 0xC709055E18DCEA2AULL, 0x740AFB6E1E541FBDULL, 0x92711E5186D432D8ULL, 
            0xA3B5011D36DFE246ULL, 0x0B665B9F24DF34F1ULL, 0xAE29BC09455ABB90ULL, 0xB3BCADBF0872F2BFULL, 
            0x6B44594CC50C3DE5ULL, 0xBEF33D5F0E0EDC4CULL, 0x1838CF1FA7B2488BULL, 0x3F9BF7E24216B382ULL
        }
    },
    {
        {
            0x7E1BEFD519C3A882ULL, 0x2027966CA2AD34DCULL, 0x74F72692C3D38CB8ULL, 0x747DFB22C4B559E8ULL, 
            0x00F3516A15F8F9B1ULL, 0x423A61B7C584D0E9ULL, 0x4ED2F41F62D44A5DULL, 0x47B5DCA04517E47EULL, 
            0xAAFB4BE3AE45920DULL, 0xA5F5A7DF76502C24ULL, 0x71370DD14639D04AULL, 0xCF65D481A027F1F7ULL, 
            0x66D197C57EDFCCA2ULL, 0x030E1A529628C900ULL, 0x02F2B2D705E48E6BULL, 0x6C277E9D9B7EDED3ULL, 
            0xB5D50A83DED8F22AULL, 0x718AF5178B1E247BULL, 0xA68916A08670849AULL, 0x0EAD1ADF42D791FAULL, 
            0x34EAFA7DF68F9EFCULL, 0x34E44B9410056120ULL, 0x4D98321025165479ULL, 0xF69BFD53E332ED12ULL, 
            0xDEA9FB977B89B477ULL, 0x59271687D75306C6ULL, 0x2B70331695C9683DULL, 0xCEDEFA85421132F2ULL, 
            0x0FC306FB17957A15ULL, 0xA4D323A84C89DD04ULL, 0x29E917D79F19981AULL, 0xC086F9AA8ECAD41AULL
        },
        {
            0xFE23715699DFE253ULL, 0x61E2E6F72F68B114ULL, 0x1DDAA2EAD8B86942ULL, 0xDEBCECEC2193F242ULL, 
            0x161E9C04A235C78DULL, 0x54FCCF228B5EB647ULL, 0xA63DF7816B40ACC7ULL, 0x171EDF63A70BA5F9ULL, 
            0x33A1F68F136EE95CULL, 0xBE4A855F9DE170BAULL, 0x4844F538678B5261ULL, 0x709D4865C120A676ULL, 
            0x5885551C4F3C3F77ULL, 0xFDD69BE2940A09D2ULL, 0x8D594D7DE11F0C38ULL, 0xB66BEB79B7F5DB3BULL, 
            0xE924D6AD86C131D1ULL, 0x81C594123AD89940ULL, 0xAB97AC0CF880F287ULL, 0x98F9ADB7B06A74C8ULL, 
            0x41A011A4F1ED9812ULL, 0xCB423CCAF8234366ULL, 0x779CD7EF37005C3BULL, 0x8EFA961DF775F8C5ULL, 
            0xE8B2C192F81D3A5FULL, 0x529AB826EB9BDE66ULL, 0xE5330FA6694CFD07ULL, 0x2415FDA124FB8A59ULL, 
            0xA985F2C6D0CD6F4FULL, 0x6FABA1DEF4CAC1BEULL, 0x27C03ADA63DA641BULL, 0x21AC0940BF1F0E60ULL
        },
        {
            0x030542A23C68126AULL, 0x565217F36F390F18ULL, 0x2D594FB08D8DD937ULL, 0x0BD5CA0272EB1085ULL, 
            0x57639B1B37B90B60ULL, 0x75AA36193008BA93ULL, 0xC4AED3CAC4C37409ULL, 0x18B12530FC8F1E40ULL, 
            0x1B564D574DEA356FULL, 0x6C3EC884C083E9BDULL, 0x54B184D00265A660ULL, 0xFB699CB157F5D9ADULL, 
            0xCD61132FEA2DDFBCULL, 0x86A794E80ED9CDAAULL, 0xCB1CC6C4550C63B9ULL, 0x23F337127E271D76ULL, 
            0x8DBF64E67EED47D9ULL, 0xBF6096DF437EF76FULL, 0xAB5E80C83BE25119ULL, 0x6D0144ED97BF453CULL, 
            0x310E826C89FAE4D5ULL, 0xCF16F4489F0E088AULL, 0x19D975B0465A2473ULL, 0xACEDF98D30592AF8ULL, 
            0xF8340105CDE6F28BULL, 0xC193A3EDDB689AB3ULL, 0x8029EF68C52FF9C3ULL, 0x93DA0DCDF7F2854CULL, 
            0x5AAB515892351138ULL, 0x516B67A286BE20E6ULL, 0xBEAB72A54EED7A59ULL, 0x8613C2E58120D07BULL
        },
        {
            0x4B5126BFC867324BULL, 0x77B0A240E57456C2ULL, 0x803C507E34B88236ULL, 0xF7AC1A4EC263DBF0ULL, 
            0x3CE6A02D9502599FULL, 0xAA1A1948048629CBULL, 0x9F1388C5270E950DULL, 0x8361BC3AB1DDC6E9ULL, 
            0x6A1EE3797EE31437ULL, 0x28A15CBD3ECA590EULL, 0x02279120BCDCB21AULL, 0xE4E948179026F847ULL, 
            0xA65A1DF38DAD268AULL, 0xD2F2F69795FFBA37ULL, 0xC3EC73C041D2769AULL, 0x066E5EEC2308BFDDULL, 
            0x8C30783A92D579E5ULL, 0x84A916C35D885F7AULL, 0xB5CBEE8AEC589B88ULL, 0x326BFDA139FCC7CBULL, 
            0x13FDE6D38A31705CULL, 0x85CD8252DD695FFBULL, 0x87C5AA6B660351CDULL, 0xAD56CD475924BB6BULL, 
            0x3B6F26703DEE1BB4ULL, 0x5F81E6B08E919475ULL, 0x19F5F0518DB630A5ULL, 0x929D708FCA4948A1ULL, 
            0xC0D956DA0FBD8195ULL, 0x4EDB16B303B13B71ULL, 0x73B2178EC4FBD147ULL, 0x2CD9695D582562D2ULL
        },
        {
            0xF005241764790D1BULL, 0xF09862ECF8C66B8FULL, 0x00058D9FF8B3620BULL, 0x3168A7697FCC39E6ULL, 
            0xECDBCE35D349D0DFULL, 0x7AD2219017D763DEULL, 0xAB7EC5844BFE36B2ULL, 0xC663C1DDEBC98084ULL, 
            0x1A10C9A921FA2045ULL, 0x292C718E63CB5986ULL, 0x7EED07CC60DD5571ULL, 0x4EB45A0425776F2FULL, 
            0x736CAA8CE4D413D5ULL, 0x3A37029245EB0C3BULL, 0xDFA3E7E958E5CDFFULL, 0xC46367D48B911C94ULL, 
            0x0AAF8690D3139E4CULL, 0x28A48FB70338CAF7ULL, 0x815E7BF2373C19CBULL, 0x65E6451C04891B8AULL, 
            0x6F79D3D89B869F47ULL, 0x7DC1D24AD30ACAEFULL, 0x69A2B8F8FF934499ULL, 0x35294F71CE3AB121ULL, 
            0xC06A63DD645F5067ULL, 0x6067F040E522D52CULL, 0x5C5ADBE0A475292EULL, 0x8848D71DD34E1738ULL, 
            0xD22CC53BEED1F55AULL, 0x8751BF7E7AE8500DULL, 0x412D3C0900E1A330ULL, 0x727E8E3C38B655FBULL
        },
        {
            0x4A89F3088BF185ACULL, 0xFD0CBDB3A916DBA0ULL, 0x7E6ABA7F1F3C1E2AULL, 0x2296C61366ACCD80ULL, 
            0x6ED728A635A59D02ULL, 0x7575D113B5BF14BFULL, 0x0642594BF85A408EULL, 0x0043A475B57639D1ULL, 
            0x2909EBF4E91A6248ULL, 0x7D117942EB04EE57ULL, 0x06AACD0AEE40024DULL, 0xA07AF87C5469567EULL, 
            0xB407430E821E1C2DULL, 0xCDFC5973E41C433EULL, 0x17788AEDADC7F029ULL, 0x4B8A8D8DB02114F3ULL, 
            0x45146F65E01722B2ULL, 0xED20FC85266E294DULL, 0x7036717642C853C5ULL, 0x8CA26E10356D568DULL, 
            0x712013E81B3D1CBAULL, 0xB7EF7B8DF0500E8EULL, 0x029255F98251D780ULL, 0x7E1D903CCF4DFDFBULL, 
            0xCCC760977B713B5DULL, 0xCCE88EAC425AA477ULL, 0xB424854F0D05DFD2ULL, 0x19D088573CD2CF64ULL, 
            0x445C49DAF63A3707ULL, 0xC8D7CB546C77A52CULL, 0x1BA5FC76C590837CULL, 0xA120A49FDE3B5EAAULL
        }
    },
    {
        {
            0x71C62AE93BF00B13ULL, 0x5B04692EA9FA172EULL, 0xF3A5C7284FF4D042ULL, 0xA2BA1C0A90169BAAULL, 
            0xEE8CDA03FFE42365ULL, 0x9D9C2E0E552414EBULL, 0x82BB16E4D9390FACULL, 0x42910BD843A56311ULL, 
            0xAE421538B1892340ULL, 0x1A19E65D605097F3ULL, 0x9505E3624A6E9D5BULL, 0x6D22AD00690A7A87ULL, 
            0xF568096C35A76BC1ULL, 0xF2218B82ACB802ABULL, 0xBF7444BF7D613A59ULL, 0x83C5D55A44B04AAAULL, 
            0x8F396B085BB95EE6ULL, 0x314D443F412607ACULL, 0xED9AA7C053B0B1E4ULL, 0xF9F84779C803A7A6ULL, 
            0x1BE5456C5EB25D8BULL, 0x7CB1A25E11319F21ULL, 0x7CB941DB93780A5FULL, 0x59D86949C945441DULL, 
            0x541979FD466C1B2DULL, 0x522784CA3CFE629BULL, 0x2DA3B5EC6137A8A5ULL, 0x43B268FCA17C591EULL, 
            0x27D9DA720EF76B27ULL, 0x1C92B0ED28572A5EULL, 0x06229B2ED15597F9ULL, 0x22DC88437C803E54ULL
        },
        {
            0xEA15C56DD7F83BA1ULL, 0xA1852542E0CB50ABULL, 0xD91210CEB0965255ULL, 0x5B4A5F5533862727ULL, 
            0x9CFD4B6D21C1C2D8ULL, 0x8DB44BF41C178A9CULL, 0xA4561C0DF8F4B518ULL, 0x3B513F2BA5AA38BCULL, 
            0x53683FDC2EFA2AD9ULL, 0x4DA1AE79000F8D0FULL, 0x2CC46129FE80E85FULL, 0x4A6178A7C11CA463ULL, 
            0xC0C3C61A4893EE8CULL, 0xB5AA9A0DEFF55345ULL, 0xB30DFA9B7B78AC71ULL, 0xF0CB00E1DDE9B404ULL, 
            0xD7370FCAE55A9415ULL, 0xDF5A40FEE20AC03DULL, 0xE56B4931D569FF67ULL, 0xAAFF7D79845E91BDULL, 
            0xCC5E75A77CA263C0ULL, 0x6EE84B0C238C8182ULL, 0xED3A1430E3E209ADULL, 0xBA38320537453F30ULL, 
            0xCF47CC9D4058CCEAULL, 0xE2F32B8148DE8EA9ULL, 0x72631877F4C92361ULL, 0xF30C7C01A2ECE9C1ULL, 
            0x7C051F469441DA91ULL, 0x9464FCFC72586ADAULL, 0xC7B71DCC3A99C32BULL, 0x7A9ED1C3D2B2933CULL
        },
        {
            0x534DE9887BF2D69FULL, 0xEFC8C33863DDA933ULL, 0xF5D0A8107875A3FCULL, 0xC8F805623DB9B55CULL, 
            0x55754428717084B9ULL, 0xE70D54CE0EF8C7CCULL, 0xCBF0C40717707A26ULL, 0x5B9787ECA9FC8A15ULL, 
            0xEAEAF4FF22847C85ULL, 0x1A307A4E270ED2F9ULL, 0x33CECDDD1A524B72ULL, 0xC2BCAA58AF56C454ULL, 
            0x3A6174DEA213521DULL, 0xC23A5DAD62E637D1ULL, 0x0C2D87717EC9E7D3ULL, 0xD6B097AB8FDB6578ULL, 
            0x8518C3DA82566CC0ULL, 0x946317F257A38C6CULL, 0xADCA63972A69AF98ULL, 0x2D88B3AD086B8B64ULL, 
            0x36EB73FFF969998AULL, 0x6985D53A8A896EC0ULL, 0x800C2A81E3A4F816ULL, 0x496654183DFA5AC8ULL, 
            0x2C21F5DB1A9AB852ULL, 0x717BC2783E6981D5ULL, 0x0378143356E3D42AULL, 0xE69B47E6CC01D759ULL, 
            0xF5110E3551C868A6ULL, 0x4134456D593EC36FULL, 0xDD92871FAB8CA925ULL, 0x78713B588447104EULL
        },
        {
            0x0CED3F54E201CAC4ULL, 0xD1BFB349C8E1EDCAULL, 0xABE558ED51F4CCC8ULL, 0x1BA1B23F9570E57DULL, 
            0x71EE9B4C05869E47ULL, 0x6E1D249F438F8E45ULL, 0x61C111056032BA10ULL, 0x918C6DF4D13485F5ULL, 
            0x2709BAA1559BAB20ULL, 0x8B720106A7E68C17ULL, 0xAC4B52DB790F373BULL, 0xB3248B629EBA72DBULL, 
            0xBA426ABC5AA23399ULL, 0x6B190A68C4379285ULL, 0xC810A08D72D4F4F5ULL, 0xDC18CABBB1E0B8D2ULL, 
            0x616FC696536B3E97ULL, 0xD260CDE2E2962DD4ULL, 0x60B32681903E2030ULL, 0x0F947D8C86F1E678ULL, 
            0x4C3CAB529A870EC2ULL, 0xB6D2BF6B8B440D2AULL, 0x2373E2729C587204ULL, 0x795AE6857509D9F4ULL, 
            0xA13C68C579E86DEDULL, 0xDC525E3B9621DC63ULL, 0x1AE576E4C2C5ECD1ULL, 0xB9F2E38137580DC8ULL, 
            0xEAB3601062922827ULL, 0x0D4B886A6F483175ULL, 0x595E1595F277F70DULL, 0xB0812402E86E8F7CULL
        },
        {
            0x56AACE8A6D0A396FULL, 0x26687FDF28067D11ULL, 0x1BAB319B97A97FF4ULL, 0xEEF6811AF03F9AE6ULL, 
            0xFDAAF77BC3EE940EULL, 0x43DA2E1CEF7CDDBCULL, 0xCCC8937789C227BAULL, 0x1601936ADCC84C3BULL, 
            0x3FDD77C801562F01ULL, 0x0A2EEB64D86B98FEULL, 0x06459F06BC5AB095ULL, 0x70CEEF4DD8C938C3ULL, 
            0x4CFFD2BE3974E60CULL, 0x94E237BB3075301DULL, 0x762F1444DE21DC4BULL, 0xA1CE2DD7A93F2F1EULL, 
            0x90B5611ABE9FDB30ULL, 0x42796344392A0BBBULL, 0x45FC6E024993B90EULL, 0xF8BBF039C29CFCE2ULL, 
            0xF2D1A7254CBBC13DULL, 0x0F517CEE0B58AF3DULL, 0x51CD7938D92E576CULL, 0xA1FF784DA0559A45ULL, 
            0xFECC071BFAAE374BULL, 0x0BD610CAF702FA5DULL, 0x6068CC9F3C800B47ULL, 0x95E68F88F276C5E6ULL, 
            0x9D854903BCB17C59ULL, 0xE9FC813F09CE626EULL, 0x5482A9C926CEA4B4ULL, 0xA97D8099A3BDD50DULL
        },
        {
            0x5C2B5AD1C412AB96ULL, 0x7CD6EB1600CF46C6ULL, 0x548C07DCA905C94AULL, 0x44042F07CD64F98AULL, 
            0x1DCE3AC1BFE75441ULL, 0x376B3A295EF4FE4AULL, 0x168D023C50247DB5ULL, 0x4B03DA3E42FEB7B2ULL, 
            0x92E90ACD40C419D8ULL, 0x0D648F275492BBA5ULL, 0xAC3FC0FDE1E594ECULL, 0x228A830DC0840E77ULL, 
            0x3DEC5FFD50CC2BC7ULL, 0x3AE6D985E6A7DAACULL, 0x26D665B16E84AD71ULL, 0x508C4351187963D5ULL, 
            0xDA0C7735BC65A59BULL, 0x9A6A88AD0F5912F6ULL, 0x89970BDADF44D569ULL, 0xD0ABA3C91D2626F4ULL, 
            0xD764EA830D6B5B2CULL, 0xB7316747A00AE463ULL, 0x08B6BB2CAF56C486ULL, 0xA3FC1E1AF30E730AULL, 
            0x981077C95BD6FA8EULL, 0x2835B1C8BF2EF6D2ULL, 0xC600014E269F8461ULL, 0x8947E487602292EFULL, 
            0xC057E71E61CD88C5ULL, 0x93EE32A851D593B7ULL, 0xAA9F30489B3FA986ULL, 0xC131F0AB032C21B4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseAConstants = {
    0xC849F21B30BD1841ULL,
    0xADA92441E315FED1ULL,
    0x1E86C91B1EA1BB6AULL,
    0xC849F21B30BD1841ULL,
    0xADA92441E315FED1ULL,
    0x1E86C91B1EA1BB6AULL,
    0x2C2DABF2009F9FC8ULL,
    0x3D337FF996CABF35ULL,
    0x0F,
    0xCD,
    0xFE,
    0x1B,
    0x17,
    0x20,
    0x0D,
    0xA5
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseBSalts = {
    {
        {
            0xF07E97F923E1AFCEULL, 0xC8D0F4A3D5E1EEAEULL, 0x0B44054CF9DF5E18ULL, 0xD424ED4CE6AC60AEULL, 
            0x2DEF9F3DD6CD6B5CULL, 0x265AE5D4A5E7D770ULL, 0x3FE2C2CEDBF8A3DCULL, 0x11971584EC1A10A1ULL, 
            0xB23E04D0A80C8114ULL, 0x337F3695532D05B7ULL, 0xCC6EF4D8AA585D7DULL, 0xA31E2AB3256FEA30ULL, 
            0xA6ADD4A0589285C7ULL, 0x1D828D4F5BC6F3A5ULL, 0x519E5B35ED71EBB2ULL, 0xB9C4DBB0AFEF0AB5ULL, 
            0xA72419E3194B4899ULL, 0x77741F319B7DA3BEULL, 0x28624FF115CA70E4ULL, 0xDB564637012B5D09ULL, 
            0x74062EAAAD6EDED7ULL, 0xA647B44D9F94586BULL, 0xBE3A163A856436FFULL, 0x8E92A3AFE03F82B3ULL, 
            0xE08E8B03D8F51826ULL, 0x751021D81CDFAE32ULL, 0x8C1C0098484F2671ULL, 0x8DF41045964D0468ULL, 
            0x9D739FC59C9C240BULL, 0xF704C12F85D098F8ULL, 0x6857B1CE885FDB3AULL, 0x4DCDA49196ADB476ULL
        },
        {
            0xBD037F4B85466ACCULL, 0x42B1D5FB3F32FFC9ULL, 0x90F8FE386059BEA5ULL, 0xAF65A950CD4C3364ULL, 
            0x65B6C491AF2535E4ULL, 0x220643BFB540A63BULL, 0x6B6AFB9CEB33A150ULL, 0xC4CAC2397C018574ULL, 
            0x4336F35475B940BEULL, 0x549AEA2380DD4C5EULL, 0x8F30B21BA13C474DULL, 0x737B14E76B1F3DB5ULL, 
            0xD1C8801BD29882A9ULL, 0x22B42F0AB72EA8E1ULL, 0xA31841C49856ECA1ULL, 0x2EF2A418F86FFC29ULL, 
            0x83AD602D17DC47AEULL, 0x7DFB40CE1EA58D3EULL, 0x13BDE028394D77F7ULL, 0x0C96669EAB163689ULL, 
            0x7DAB55B583983622ULL, 0x2AD598EBF8FC744DULL, 0x5959FDAAC4F5C1A4ULL, 0x3F3EEF04BDDFE8D1ULL, 
            0xEC1C9086A9D70435ULL, 0xC3865BC8DC58CC9EULL, 0xFF0F31426572235CULL, 0x0A58F328BFEFF441ULL, 
            0x49C303F63B5DA439ULL, 0x16AEF69BADD12FECULL, 0xB380396F706EAF22ULL, 0x97654B5EB6A76680ULL
        },
        {
            0xB0E0B2B001A55ECFULL, 0x7C355C5C52FD3B97ULL, 0x62B9793EA135E9B0ULL, 0x2678CB33A2DE79D8ULL, 
            0xC4EED1C32B7C7B5DULL, 0x5D53884DC12016FFULL, 0xE5CFC0A235DD506BULL, 0xD7473E58212B6764ULL, 
            0xCBB50D51191F9F97ULL, 0x57B15A141FBB1FE0ULL, 0x4BE2045D32D78313ULL, 0x2F338782278E9937ULL, 
            0x8E5F45617F1B5463ULL, 0x298E60F4C53A25C7ULL, 0xC0ED7F1EF567F3ECULL, 0x33532CD6FFCDAEFCULL, 
            0x660BC8AAC5AAA129ULL, 0x9C7F765B17AC5783ULL, 0x6819D7B7048788D5ULL, 0x62DEACFB32CAE858ULL, 
            0x22027215142EB67FULL, 0xEAA4D13894ACCA76ULL, 0x8613538CEE7AB5A8ULL, 0x7973A65E1B527FD2ULL, 
            0x9A8AE7DB57F2A887ULL, 0x88D09B4FC0B704FDULL, 0xD34225150DCA8532ULL, 0x60C1B7B2F9BF72F1ULL, 
            0xE50C1947C4E9AFE1ULL, 0xEC88AAD6C94D9BABULL, 0x3A75BE79956B277CULL, 0xBC2F85534B802759ULL
        },
        {
            0x5A4683198DAB4262ULL, 0x00FACA621322C42FULL, 0xBE28BD0C0B905F7BULL, 0x5F01753DCE1574E6ULL, 
            0xC0E820BA38EE8621ULL, 0x9E0973DE7B27F737ULL, 0xB4672A3B2261AC43ULL, 0xCBFF08E84B416341ULL, 
            0x55432C116A0C1BCAULL, 0x5550426424F55B3DULL, 0x3CDD4D6521BC0355ULL, 0x1C48A37E0ECABA8DULL, 
            0x58350D4D46DD566BULL, 0x5978D928842D60F7ULL, 0xB9DB8A8D2B34E8A7ULL, 0x15D8EB1C57F9645DULL, 
            0x3751910F062A4845ULL, 0x94D43F5C11049F36ULL, 0x13E2662B76FAC6E3ULL, 0xEB00419D007AE729ULL, 
            0xE24F1807B79910DFULL, 0xF191D89C67260420ULL, 0xF27DAF55FF923B71ULL, 0xDDB345AF304A8D82ULL, 
            0x47A03C0716005352ULL, 0xC16104AB7F7C6022ULL, 0xB7660C34DE50479BULL, 0xF3E835580E3F47E2ULL, 
            0x7A6A7971380D698CULL, 0x161F17977234D542ULL, 0x14C45E8AD8116125ULL, 0x3E3A073DCB037E5FULL
        },
        {
            0x2E05CB209CE1B1A8ULL, 0x3E3410B4478F24D1ULL, 0x81A3C93FDCCF5A9EULL, 0x8CD60B8A48FA3BDFULL, 
            0xACB96EACFA6C3840ULL, 0x4049E32BD42F9B76ULL, 0xC66A3964721A7CF7ULL, 0x5A3172FEF2CE4325ULL, 
            0x1667BAC38EBF6D1CULL, 0xCA3F6F5CA312DA18ULL, 0x3CBFFBED76C06417ULL, 0xDB4683E000DED4F6ULL, 
            0x3B09220261B85B0DULL, 0x0865F24A40CA9598ULL, 0xBED9BED69C07441CULL, 0x13A3F93F92538768ULL, 
            0x89A852C8033626CCULL, 0x7BED3EB06F7B64B3ULL, 0x7AD1CF5D214576C8ULL, 0xDB63DCC207035BCEULL, 
            0x6260FAB15B10DAF3ULL, 0x53CA5A91F9CF6336ULL, 0xEB429B5BF4F6B9FBULL, 0x306496396D0D9B02ULL, 
            0x31F6F5BD0E2F5F2CULL, 0xB0767F3AEE4149B2ULL, 0xDEA108015A0D55EFULL, 0x3260772F5D98EAF2ULL, 
            0x29661C98B0B0B160ULL, 0xB7886E5B1E8ED451ULL, 0x72813B0D02CB054BULL, 0x321C96EA57589269ULL
        },
        {
            0xC6ECEC2BC2AB9CD9ULL, 0x021618C316A7095CULL, 0xDDE067980C20F4C2ULL, 0x44E59A900773F67FULL, 
            0xCE507EC553C1E174ULL, 0xF74BF3A49F9448A3ULL, 0x544DF542EE5B4AC8ULL, 0x06AA13220F497571ULL, 
            0xE810F38FCFD17371ULL, 0xE96DBAB71882603CULL, 0x0D82AF7E4526597EULL, 0x74C01E62E367F4CEULL, 
            0x8B1CEB632D161469ULL, 0xFCA817F893342A9EULL, 0x9D0B3C4C00573672ULL, 0x52A0569FF22A9110ULL, 
            0x2302AF28CC6EF543ULL, 0x437A18AD7F62B3B2ULL, 0xA5C917D428D75B8DULL, 0xD5645649EA0B592FULL, 
            0xDADC50B3AA51C6E4ULL, 0x381E1B5F9A6CE026ULL, 0xC854D208310E9C55ULL, 0x439406F9A828DBA2ULL, 
            0x4B284297FC02F443ULL, 0x44E4CA9CFB335D6DULL, 0x72C58F42B28408A8ULL, 0xF1BD8BFE09874923ULL, 
            0x1243272E452BDF77ULL, 0x9EB33040A19BF780ULL, 0x6DDA9FFF0A140764ULL, 0x8DD11CB6A5198687ULL
        }
    },
    {
        {
            0x2F894C78C5888B03ULL, 0x9E818C9B3A1E8143ULL, 0x810843045556669EULL, 0xD998E8D080A4D174ULL, 
            0x2E4693B43923D57AULL, 0x84F7D8FBA4185EC1ULL, 0x03298EF29ABBFB82ULL, 0x68BF5D1DCBAC673BULL, 
            0x74AEF5E1876233AEULL, 0xDD3FCAAAA4397986ULL, 0x8887EBF6E6039698ULL, 0xDB4237BB6D766E1BULL, 
            0x45D2E86FF9B93A0AULL, 0x097D7B1144215C8DULL, 0x5A2B59DBD3B1EC8BULL, 0x9400220D386BB486ULL, 
            0xD1EC1E21770F2548ULL, 0x4ADC29A858660F2AULL, 0x4865CCC236514637ULL, 0x5E905589928B3EABULL, 
            0xECFA93D2BFBC7830ULL, 0x18A8C0B7D23A93BCULL, 0x24DB617D04D70043ULL, 0x8519262C0FB08208ULL, 
            0xE652B72FFAA2C876ULL, 0x952014062D3A4323ULL, 0xD0F99DC075E13FFFULL, 0x59F9874BE38918F7ULL, 
            0xA0C6D5735EAB6054ULL, 0xE31A6CE71FEC6EC0ULL, 0x4AE736E207B3B8E2ULL, 0xA6EC0CECB7E601FAULL
        },
        {
            0xB74C825E637AC0EDULL, 0xEC5D877D68C2945CULL, 0x2CE44F0A009CD716ULL, 0x605CB1839A33B4D3ULL, 
            0xC276FCECFA9F64BAULL, 0x344103142967D63DULL, 0x0E9CEEB0ECF3182AULL, 0x35B2F2F04ED021DBULL, 
            0xAC2E48BBDC9D2D30ULL, 0xFAAADF7CC66288A0ULL, 0x338E34F54814AC8FULL, 0x3740117065728FE7ULL, 
            0x7BDD4C007B968FD9ULL, 0x3D288F98803FCFE7ULL, 0x0A9EBCD12592B4F4ULL, 0xB9227664C7092177ULL, 
            0xB98527EF1CECE1ADULL, 0x5CA4C0E6FFA2FD3DULL, 0x1C958B89A16E2C54ULL, 0xD849FC1BDB6A7D38ULL, 
            0x52AF6955E64AE2E9ULL, 0xB8220DCBAF9E1C8FULL, 0x8DA5ADAED8984FA8ULL, 0xF0C8FB0B3F373DA6ULL, 
            0x483D5F817CECFE4EULL, 0x6C5B31006FB0ADC8ULL, 0xE72459E46E18CA0FULL, 0x8AA083B177E51DF4ULL, 
            0x49DB0ADF5D91B194ULL, 0x46E8BBA5C75F34AEULL, 0x48E70CDF06A36FBDULL, 0x8523B87D59E845F8ULL
        },
        {
            0xB7F6703D1D6184FDULL, 0x9B4C110B3E8732B4ULL, 0xC79AFDFBDA43D536ULL, 0x402F978D18753EBDULL, 
            0x68897438303CBCA0ULL, 0x77E2D767F10E8767ULL, 0xF35259AA4C770483ULL, 0x7A741194EFA9843BULL, 
            0xFFB89941378C4ACEULL, 0xFE771FC573E84448ULL, 0x244D1FC95D928977ULL, 0x5CCEAF68439A0DBFULL, 
            0xF2022227036E34A7ULL, 0xE47B283D430D0B9DULL, 0xB6AB491A4B2E382CULL, 0xD45F276001A9D813ULL, 
            0xAEEFC3A1FEA9A137ULL, 0xA24758700BF3E51AULL, 0xF127D5DCEB3FDEF1ULL, 0xD2CCF9E8AFFA81CAULL, 
            0x5118726CBC85AB56ULL, 0xADE5E5823B75A8AEULL, 0x9F49FC111B908ADCULL, 0xAA52C1EA6A718049ULL, 
            0x4C872D02440D8B1EULL, 0x37641F9823484AEEULL, 0x0F8D3164C6E513DBULL, 0x982D76503CC82DFAULL, 
            0x1E4D10C6757EFAC7ULL, 0xFF867D3AE4C2DD92ULL, 0xC252D9202DAFB680ULL, 0x7B4AE8339620FCBEULL
        },
        {
            0x21CCA8F9C9BD12F0ULL, 0x200CA6032B871584ULL, 0xB0D8A37FBD6C32C3ULL, 0x2EA47C548BFDFF18ULL, 
            0xBB7A8F5DAD0E2BB7ULL, 0x76BD18DE708ABC7EULL, 0x911C0EA7A4E52248ULL, 0x4C6D500B56A3149BULL, 
            0xA4B1CA45DED5D9BFULL, 0x08DC2B8643B6C4A2ULL, 0x979695B575C88736ULL, 0x5A5A73C1ACB92D64ULL, 
            0x24C2AF78D2F384A5ULL, 0xAC69D2CD134043C0ULL, 0x3BF5603202E1EFBEULL, 0x4B5556FA5170B561ULL, 
            0x3379B80B121366E0ULL, 0x4372876630CCA2D0ULL, 0x0E904F6365C9F8BEULL, 0x90BAFD7E768E105EULL, 
            0xA01BCDF5D0F5B4EEULL, 0xCD9E120771872650ULL, 0x97F457FCD1561BD3ULL, 0x72396807076E6FDBULL, 
            0x680BF7354F66E75CULL, 0x9EFA5F9470948721ULL, 0x3753B791F797DB3EULL, 0x9CF12426B5683394ULL, 
            0xF04FE02EFCEF8FE8ULL, 0x3A4A5E8E6A6E2A2EULL, 0xFA7392F348C46429ULL, 0x239453F2B51BF028ULL
        },
        {
            0x816C69591FF2FFC3ULL, 0x9CF92BF735E932F6ULL, 0x5E4CCC36F0415D63ULL, 0x4C440DF873696FF2ULL, 
            0xE83454BB69B2E22EULL, 0x7D7865BFF4EBF651ULL, 0xC7BECBD5C231F118ULL, 0xEE0D2D14FD0276FFULL, 
            0x2F7AE3B93CDEA45CULL, 0xCFCBD2961275DBF6ULL, 0xED87021582CE0718ULL, 0x50F1BE5A8D6E78CEULL, 
            0x4852BA6816D9F62AULL, 0x9CA55574A8613AD9ULL, 0x3467D7C0EFBBB158ULL, 0x80ACB49BD4C88AB4ULL, 
            0x01F7658CDED5FEE1ULL, 0x412E2CA40761BE3AULL, 0x143D86F916FA740FULL, 0x2E65B07EB142203CULL, 
            0xB52B7AA30C18F4F6ULL, 0x65DA7BE90F61E935ULL, 0x6DC42245FCEA084EULL, 0xA2EEA6ABEDE92366ULL, 
            0x2DCFE78937C21D28ULL, 0x49350A3418EA9FB1ULL, 0x5F1F6B40091EC78FULL, 0xA32342A48FFB9034ULL, 
            0xA70B4221B5B82F8EULL, 0xFCC59A9DC254F1CFULL, 0x3BD366D39D4623ABULL, 0x6B663A5018312C18ULL
        },
        {
            0x1AEE05896BBB1C87ULL, 0x5B316886830F945EULL, 0x76A55B3DD924F7E7ULL, 0x619C09E9D6AC13D7ULL, 
            0x7397F2AB0B42F960ULL, 0x63957BCD12821E65ULL, 0xEFA14C61E53549A0ULL, 0xE14E7DDAC7A956BFULL, 
            0x9252CF63C8C90809ULL, 0x7BE3AEA93B91E6ABULL, 0xDCAA6D4F06D6A41AULL, 0x5E1EFDA316F5C2C2ULL, 
            0x0ECD1370A097A29FULL, 0x594889CA44EAC605ULL, 0xD7FEB77FCD7126DDULL, 0x7761CBF59BFB9BEBULL, 
            0x7DFC02B6C1341EF4ULL, 0xA724B2B6B8E197CFULL, 0x1083C0EBECC98B0BULL, 0x10BF5BE0C8632926ULL, 
            0xC17EBD89558042AEULL, 0x1BBF413951E81681ULL, 0xE08618A60446A81CULL, 0x7A8C3FEA2C26AED5ULL, 
            0x60687A2F7E52B9B6ULL, 0x5EA8AB037372BD0BULL, 0xB949F3C603185784ULL, 0xDFE8C1A307FAA899ULL, 
            0xC4E7B30B4A223047ULL, 0xEE885E6DF0D9875EULL, 0x2B8413AF3AE285C9ULL, 0x63BC69F94EB2FA80ULL
        }
    },
    {
        {
            0x324A961D45CD184EULL, 0x2149B36B0A4C4D35ULL, 0x2E08CE8C64A0B3E0ULL, 0xF9272DDFEA63269EULL, 
            0x9ED23CFE466C2DA4ULL, 0xDE0DF95E55544BBDULL, 0x17ED1751002644D1ULL, 0x14A4A7BB2722BA15ULL, 
            0x9FE83C55F8C8DBD2ULL, 0xEEC195B4D4B68F70ULL, 0xC952D3F9CE6C7118ULL, 0xE75A143D34B2240EULL, 
            0x98F4D231666169E4ULL, 0xD186857800CB66F5ULL, 0x439644D2B6E0B9CAULL, 0x555B16B5AC442502ULL, 
            0x6B6B9DD8802F42E4ULL, 0x60B1615740A8BC0BULL, 0x63166B5A05FB18C8ULL, 0x54E13E5BBC4166F7ULL, 
            0xA533416C23E8C4BEULL, 0x9550B705B7B6FB47ULL, 0xD8037DE2E63DEBC6ULL, 0x94B474E387DDDC71ULL, 
            0xE2DD29E5A32383B5ULL, 0xDD77C098F50E276DULL, 0x00A18D78D93B8BC6ULL, 0x6F30546806BB7AADULL, 
            0xBB2F1D8880FE4CC9ULL, 0xAFF2385771A3F4E0ULL, 0xA5EBC0B42F8B2218ULL, 0xEE44007D1A8155C3ULL
        },
        {
            0x6709D447D4BDC35AULL, 0xC62A884E3A41AAE3ULL, 0x0BADCF72531A5C21ULL, 0x478B8AB737DE0FC8ULL, 
            0x4D02EA1E6B4B3E5DULL, 0x3E156D4F2CA639ABULL, 0x803575542D4064A7ULL, 0xEDA74E4A3BAB0CB3ULL, 
            0xFBB9625FAB4D2B39ULL, 0xCDFD6BE5B296AEB7ULL, 0x274B2E5C91B271E4ULL, 0x2C0832AC7FE93212ULL, 
            0x2A1C585123DEB554ULL, 0xD36E05332B3F545BULL, 0xA8BD93567EF94E5AULL, 0x1E8ED5A5504B71D0ULL, 
            0xA2D33E83EE5B70ACULL, 0xABFC7EF5F88E74DFULL, 0x398CAA614EC2117BULL, 0xD50975B3375CD8ECULL, 
            0xA65A32F3F04575EAULL, 0x51913D635384492BULL, 0xEEBF0D961D9AC466ULL, 0x66F2267FB08533A7ULL, 
            0x82C4AA6A199E2B8AULL, 0xBD20E52EC9323341ULL, 0x053F11507EC34363ULL, 0x035DDBF266D2E929ULL, 
            0xB5FBB9F7546A9E72ULL, 0x59977D580312CD79ULL, 0x934589C0EC268281ULL, 0xD6A3EE97F33ED113ULL
        },
        {
            0x5ABB80CC3FF07612ULL, 0xD744E1DA1CEF095FULL, 0x32EC1A640429DAD2ULL, 0xD0A059804412D563ULL, 
            0x1987B705969D9FF6ULL, 0x78A22A3F144E871CULL, 0x816E6E981607763EULL, 0x208AF7D311613683ULL, 
            0x141382238308A99AULL, 0x5A79E3F0631107D8ULL, 0x5662DE8E1EB5D5C5ULL, 0x5FBE6B56622A91A6ULL, 
            0x465DC28571EBE139ULL, 0x205CBE3F9358FFBCULL, 0x2C0B49883DE01A31ULL, 0x216F971C8A81D4C0ULL, 
            0x23C8D5DE9B168116ULL, 0x4907BA12883F74BAULL, 0x3E069E22A73CFE23ULL, 0xA9D0188F921CC404ULL, 
            0x49E8CA3EE5863338ULL, 0x9E9D8D375DCFEE57ULL, 0xE8CEA52C7BBA1E38ULL, 0x237E3FFB76912976ULL, 
            0x014B7C924E2B1B0EULL, 0x8943C5DB38BCB098ULL, 0x299B08AB830CA7AFULL, 0x7E763710EA37B16EULL, 
            0x85FB05F124736985ULL, 0xC2AB66ADC3992ECFULL, 0x39A7F960FDA7F8C7ULL, 0xCCF7C83F0C21E1AEULL
        },
        {
            0x3C9ACBC1C9F3CFB0ULL, 0x47F654F1FBD280F6ULL, 0x837B4E58B1C15B45ULL, 0xC9F017954CB6FE91ULL, 
            0x6590183600D84A70ULL, 0x033D668774789E18ULL, 0x80B93831B821DC97ULL, 0x1A139ED555811FBAULL, 
            0x5DD9BC68765C44E3ULL, 0x9BBBAA24DE9331B1ULL, 0x71DF7BA5A3DB3ADDULL, 0x0D755726712EDA0FULL, 
            0xFD1087B1B87C4A3EULL, 0xDFCB17AF8AF2355CULL, 0x406DDB6CB35ECA97ULL, 0xB4291E5880ADC0E9ULL, 
            0x798973B841D4BA99ULL, 0x91275DBF74868532ULL, 0x4CA22AFF53514EFBULL, 0xA071A29AD2A76D5AULL, 
            0xAB9F23206EAD4739ULL, 0x005ECE7D0D28703DULL, 0xC68FFF83235C7175ULL, 0x8A2F2623BE3D7B4DULL, 
            0xF66EA0871CB2CCCCULL, 0x7C69A8327691536CULL, 0xB86F67DFDC204906ULL, 0xE0774EA4784287B1ULL, 
            0x37D5DDB6321B416DULL, 0xC2AE90577E624E51ULL, 0xCF77EB72CD4E2CE4ULL, 0xF2FE0F357EFC9347ULL
        },
        {
            0x952F50912DE06C24ULL, 0x5F7414F7555586ACULL, 0xAAAA60D68EBEDE1BULL, 0xDA5C3B40300ED9FAULL, 
            0x327A30B079AEB59BULL, 0x22E4B7BE79C04128ULL, 0xA6D761558E74AB16ULL, 0x0649B248A11A0849ULL, 
            0x40181202C8D52465ULL, 0xA42DEC7B9CEAE1BFULL, 0x9B333B494ABE54E4ULL, 0xB2BACC6F71A033E5ULL, 
            0x0A4B83F683EB739DULL, 0xC52FA5DE1A4458CCULL, 0x7087E3B22A8276B3ULL, 0x2DD852F794FDFF29ULL, 
            0xE6008AAC0DFAB2B3ULL, 0x42B64F1DAD95BCCEULL, 0xEE18C3A24AE9C535ULL, 0xC57E2872D7452223ULL, 
            0x081794AD4D7690D2ULL, 0x2E3C18DF267C8F12ULL, 0x39E13558424EDA9BULL, 0xE76ADAF21A315905ULL, 
            0x91D86BAC6083B707ULL, 0x19393E01B9791AA7ULL, 0xDC50063C601A4349ULL, 0xC717525BC48050E3ULL, 
            0x5FF89A0151B57221ULL, 0x59BA32FE14920410ULL, 0x0C9A4AD53F107850ULL, 0x02F24CE04BB94C01ULL
        },
        {
            0xB34E6B3D53418B97ULL, 0x8AADB866B1E102B2ULL, 0xA28BA1DC3276AADFULL, 0xFDBA0C918EE40266ULL, 
            0x42F53E872F3FAD92ULL, 0x936A944027A9452EULL, 0xEAD2172802EE809AULL, 0xBCB81CF2BEFFAB89ULL, 
            0x3A997AF0CEB511CEULL, 0xA10616D06A25CD07ULL, 0xECCCC573ADC4DD76ULL, 0x303F0DB4FFBE77DBULL, 
            0x0B4E1960143FC7DAULL, 0x16AC5B1917A3E4DFULL, 0xCC4290DD9B62CF25ULL, 0x2D7880C2619447F0ULL, 
            0x2B288C67059ECE5DULL, 0xD7A273179B08538AULL, 0x2125B19053A89AC9ULL, 0x9B7A40480BCCE4C5ULL, 
            0xCBE712258BC4FE0EULL, 0xB928462B8F642B28ULL, 0x02FD9BFDB38FF253ULL, 0x71E3439283F1EFA3ULL, 
            0xD2741DE06957CB41ULL, 0x35C5BC20D4F2602BULL, 0xCE689F787764F7C4ULL, 0x231448DB05F53169ULL, 
            0xB3E23C9891095861ULL, 0xBC905A9B9C1F6A88ULL, 0xA8E2202DC29D0576ULL, 0xAFD95F1AECCE7A8BULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseBConstants = {
    0x67CAA139348AF72CULL,
    0x9B5DC0C9986D3961ULL,
    0xF9F1CCE680EBD773ULL,
    0x67CAA139348AF72CULL,
    0x9B5DC0C9986D3961ULL,
    0xF9F1CCE680EBD773ULL,
    0xE8888654418D6D5CULL,
    0x2B977EBDE349FC2DULL,
    0x5E,
    0x94,
    0x23,
    0xC4,
    0x10,
    0xB7,
    0x4C,
    0x62
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseCSalts = {
    {
        {
            0xF72EE03C0C70D4C2ULL, 0x312689C1C25FCCBFULL, 0xC020DC3A751EDF87ULL, 0x8A6D0AB64F94E786ULL, 
            0xF46FFD466993410CULL, 0xFD61513FD9007E82ULL, 0x6E4683791C438405ULL, 0xA8E21691EF8800BDULL, 
            0x849D8EB442EA9B22ULL, 0x99AF8E6D68AAE78AULL, 0xA7DE38DA424BD36FULL, 0xC230068D8651722AULL, 
            0x9863EF494245442DULL, 0x467F4AA438159FB2ULL, 0xF3723F46787E02C8ULL, 0x303D722B6A240F49ULL, 
            0x7B4805DD340ACCDAULL, 0x80F46CC1366C557CULL, 0xC01F834AF2D16708ULL, 0x3CF5A8CEEA546C07ULL, 
            0x8BBF715DF66F9C02ULL, 0xCC60544BFFA62663ULL, 0xF502771538AE7103ULL, 0x7355C21859E9EF30ULL, 
            0x564834C2ED84984AULL, 0x38270F329FF3733EULL, 0x423059B756BB96E9ULL, 0xD312AA53765ADBD3ULL, 
            0xE8E8D6868B0F6F18ULL, 0x6560B785714DBBD7ULL, 0xC29D39531C80DE47ULL, 0x3C814270C92E127BULL
        },
        {
            0x71BA9C84C9485EADULL, 0x5EC5496C00E5AC89ULL, 0xAFE1E237F10F5421ULL, 0x464F440A15334CA7ULL, 
            0x1CDD85196A213674ULL, 0x527211F7619E6E46ULL, 0x6044A9DAA2AEDE36ULL, 0x8E4A8CD948BF28D9ULL, 
            0xE6C6F4938DE0422DULL, 0x7CB370C218200E4DULL, 0xE2A80D54544CEB80ULL, 0x9CBC6B3FA078B600ULL, 
            0x8B59C1C540321D2FULL, 0x071A3FB40DDE4EE4ULL, 0x59DF429FE0262E48ULL, 0x4BB412BAF183AD2CULL, 
            0x9D770F3CD3EDBFD2ULL, 0xB79E1C42DBB2DD7DULL, 0x81308E0D0B67DBF7ULL, 0xB9E791FF8D4C4942ULL, 
            0x0A03161D9EAF4EC3ULL, 0xF192745DAF2EC67BULL, 0x63C5FF8A5DA36498ULL, 0x110E53EC88CFB4A9ULL, 
            0x92060CD857BA0A0BULL, 0x7F8E615048030BC0ULL, 0xA7A2B5D9022297ECULL, 0xD1CC5256A8A34919ULL, 
            0xB9D83B224480664FULL, 0x3B8F5A19C48A29F2ULL, 0x4EFC2A2EBCCE55BBULL, 0xA366AFF9BBEFE80CULL
        },
        {
            0x1D9FD58D91ED3C8FULL, 0x90EAFF3F9D542A20ULL, 0x9473A639E945ECDDULL, 0x653CF85FD66F9C7BULL, 
            0x2C941E3192994C28ULL, 0xEE289D009425FE07ULL, 0xC354D48304C9314CULL, 0x9917EBD2754B265FULL, 
            0x7C02886630DD6EAAULL, 0xFF0E648FC95BD72DULL, 0xFBAB5E67A1A661C6ULL, 0x91756184875B5062ULL, 
            0x82FE07AAC3FF36E8ULL, 0xFB63F1181D3F9379ULL, 0xDD3945E48A4912D8ULL, 0x924D0C4FA6727643ULL, 
            0xDF27DCBAAF74C32BULL, 0xAA213C1E7C7A8B92ULL, 0x14B488C01891CF3CULL, 0x726C5ED39315D024ULL, 
            0x9FFC978827D96228ULL, 0x5AF7C2365FD0A73FULL, 0xE74F038513C92C76ULL, 0x13BA8D7DFDFF4538ULL, 
            0xD387F212C5489785ULL, 0x127AADEE60240160ULL, 0xD2BC26ECC7ED6C4AULL, 0x3D184E841E20A526ULL, 
            0x8A24DA537D20587AULL, 0x40D00DD090010B5CULL, 0xBB59AB7BE122F530ULL, 0x51425D861987CC14ULL
        },
        {
            0x7240AB94390E23DCULL, 0x049F181F674CE8F3ULL, 0xC4B4155C03B10F91ULL, 0x0B4FDA327B9BE5A4ULL, 
            0xDCE4C955905619CFULL, 0x163D1F068824B75CULL, 0x19375E0D55390A07ULL, 0x579468F9AAD82D02ULL, 
            0x56AF0DC3C4150910ULL, 0x8C72554D932ADDA0ULL, 0x5AB3F96260E06F73ULL, 0xE410824AA4F85DDDULL, 
            0x8213E299E52460B3ULL, 0x90854BB423974D21ULL, 0x2129229F5AF8A69AULL, 0xD8576ABBC1257156ULL, 
            0xDBC575A93CA6C744ULL, 0xD2806F44E491AE6DULL, 0xF970420D08AE382AULL, 0xA19C9A501E00D34DULL, 
            0x3EC6F9CD1FBD0374ULL, 0xE272A6BD8B3F6E4BULL, 0x885F007FC8D6A5B5ULL, 0x4D2B270D5E95CDA8ULL, 
            0xAE5AB41265A88B6DULL, 0x5134BD121032071CULL, 0x5BE1A6EF4C99CA94ULL, 0x9247850ABFAE5BE8ULL, 
            0x394B9F2A564A8595ULL, 0x304DA811FC20C1FDULL, 0xF63009315AA8E488ULL, 0x0474DFC170618BEBULL
        },
        {
            0x4F54BCFA500DEC45ULL, 0x9748CB967AC59C48ULL, 0x4055A433E49A9617ULL, 0x4F3FB50B2C5EC4B5ULL, 
            0x9CC5432365D3869DULL, 0x336FD5F5F82B4FC2ULL, 0x36D3364DE4095359ULL, 0x306EDBD9FCD10BF4ULL, 
            0x9B96391082436B8FULL, 0x8CB78ACEB6BC5A96ULL, 0x8781A7ECA2F9F0C3ULL, 0x0238563F5273381DULL, 
            0x205137DEEBBEA272ULL, 0xA4C0A650873F678DULL, 0x2DC9FD4C72700773ULL, 0x0092F15612E042CEULL, 
            0x3773444ACBB5E56DULL, 0xB9C2B29F0BE959DEULL, 0xAE8A37FD0CA23139ULL, 0x54077CA4BD5BB6A2ULL, 
            0x8DABE7BB9F813C8BULL, 0x4AF916F766AD2D15ULL, 0x894AC9E154F41E4EULL, 0x472FD380BFDD543DULL, 
            0x2876D6541434FC08ULL, 0x93F7086A329FE404ULL, 0x0CC6D92E8F5E3BBAULL, 0x74098656088E3343ULL, 
            0x76946650E8DA5321ULL, 0xA3204F208912CCE9ULL, 0xB098BEB1E0D56D66ULL, 0xFFB30A323C2BA2BBULL
        },
        {
            0xF3FB0AC4EFF651DEULL, 0xFD3776D22C4D8931ULL, 0xC8252AA870C7ADFDULL, 0x69A1740B877FC51CULL, 
            0x296465CC0A83B5E4ULL, 0x9F4B6CF6F1C51B01ULL, 0xC1DB223D3EBF99EDULL, 0xE564F40F7FF0258BULL, 
            0x794FD1102962673BULL, 0x44EE1CF3F8FE0F9DULL, 0x74CE5E0853F2848BULL, 0x494A365E9D5911FAULL, 
            0x6B6FF7461033B42EULL, 0x375ECAF70502BAF4ULL, 0xAE25AA9FE2443282ULL, 0x08129EF779827C6BULL, 
            0x915F5D9F6E5195D3ULL, 0x38B6A43D01CAD078ULL, 0x448C2CD3229125B6ULL, 0x5FAE772F91178FE0ULL, 
            0xFF85E3EC77CE878EULL, 0x0E0E35345F05AC9CULL, 0xF1748A0C7885DC54ULL, 0xF0D3B5F41DE19511ULL, 
            0x4C4180E39170C63BULL, 0x27C98FFECE5EA4C1ULL, 0x20B79C152C8EBF53ULL, 0xAE6A2CA0A6D41AC3ULL, 
            0x504C4A04D6B0CE2CULL, 0x95D4EA7B6678182CULL, 0xB669FFB3FB8E6FB3ULL, 0x90D994A561EE09F9ULL
        }
    },
    {
        {
            0x6F0B4ECFA5F06BF9ULL, 0x83C1C2F7F1619524ULL, 0x1823D5DA201B64BCULL, 0x38880C9A4EE444DDULL, 
            0x9D5B68628CD1AEADULL, 0x49BD26E0422ADB38ULL, 0xC21C7800FC102C80ULL, 0x1B01D1F63B6770BEULL, 
            0x0A167D29C0432A6FULL, 0xC8C7079AC09A19AAULL, 0x476F897D8AC39F99ULL, 0x4DC7358E64CE03C9ULL, 
            0xA3BA8C51B36F9526ULL, 0x6EF15481E51E0A82ULL, 0x53DEA74515FC8937ULL, 0x6055A2641DDDDA25ULL, 
            0x3A1EB2DE7B76A9ABULL, 0x39D0A4655A9AF0DDULL, 0x04A2CD5F94DD6C02ULL, 0x49EDFAB061CE3DF9ULL, 
            0xD1280E11EB1FE2D1ULL, 0x260F4440E450DB16ULL, 0xFC8ED49FB32F904BULL, 0xC826D7232237B420ULL, 
            0xE7122BE77D94575DULL, 0x49046B4761D11B5CULL, 0xFE88666F27687A46ULL, 0x043A5045CA860EFFULL, 
            0xB515F559D7B867D9ULL, 0x186FD8784170F848ULL, 0x2BFCCB307C77EB11ULL, 0xA225FDF5ABE78181ULL
        },
        {
            0xEDA0A6459B6FFE23ULL, 0x3FEECE13594BA082ULL, 0x7C604C00F2FBDA8AULL, 0x9FDB28B539EFC1B5ULL, 
            0x2BDC0F153FADC22CULL, 0xC57C072A71084976ULL, 0xC83F526AC10E0467ULL, 0x2F343B51B291877FULL, 
            0xB66E1B83296E82A5ULL, 0xAA1D6A28F53CAFE6ULL, 0xAD5EB6BC9EBAADFCULL, 0xDC9DFF82259E6E3EULL, 
            0xBC5025D8BC35C9F7ULL, 0x34A50418DAC48EAAULL, 0x7EA94F7B7873BEFCULL, 0xD9A94379918DCE5CULL, 
            0x5C45EAE2EA1654EDULL, 0xEA20E668DE2B2FD7ULL, 0xB49A785193BF769BULL, 0x55BE928C38542994ULL, 
            0xB1FD8AB66A267AEAULL, 0x07EAEADECC54AB61ULL, 0x6E60E15D342B782AULL, 0xEE6D36F18966DDA2ULL, 
            0x42485ECB25EB2E09ULL, 0xBC62E297F0F56CCCULL, 0xE5070D53A3720D49ULL, 0x752D27CADC09B358ULL, 
            0xCAA039995C842E99ULL, 0x42DC43CC83833E1AULL, 0xBE611A1317A8AD51ULL, 0xBB270E679586A1A4ULL
        },
        {
            0x7249A7F1BF74BE84ULL, 0xC82ABFA3FC635862ULL, 0x5984910D32771568ULL, 0x0DECFCE0467A8933ULL, 
            0xE7AAA7E61B65D9E0ULL, 0xC40A8E537E539296ULL, 0xC152E8344B15D6C6ULL, 0x1E31325354A8766FULL, 
            0x9BEE2C175EEAD972ULL, 0x4EC1B0234BC559F5ULL, 0x18860E687622C423ULL, 0xDDBEA9D80DC7B848ULL, 
            0x4C50190D9008E6D7ULL, 0xC6F27D96E0155FA4ULL, 0x7BE161D702A57B33ULL, 0xB97EDF2EA3C105BEULL, 
            0xCCB09D2507BB591FULL, 0x5AC08F40F896C9A2ULL, 0x273BA0B27A6C711FULL, 0x2FA1D7473BA7D980ULL, 
            0x15CE85B9B449BE7EULL, 0x306A14BB4C0DDA74ULL, 0x0C13E295A4A6AB8EULL, 0xCA57EE03A7B9AA52ULL, 
            0xF1F13F5282409825ULL, 0xF5A34F83D0D1A57CULL, 0x801900D1B9F93B05ULL, 0x7FCA8EC78838E140ULL, 
            0xF92576ADDC46434FULL, 0xD9DE52B7FBB94470ULL, 0xEF5EBD769F01B75AULL, 0x2A468AEC6B9202EDULL
        },
        {
            0xAE62C3A9CAA91909ULL, 0xAE29E68AB9511B4DULL, 0x268E5E299E5051A1ULL, 0x5D1BC05310C17441ULL, 
            0x2E1EBDB35730F662ULL, 0xDF591619CFFE82A6ULL, 0x4CF2D99E6F62EEADULL, 0x04D49105726BA27DULL, 
            0x71D9E470D3B7C5E8ULL, 0xCB29FF882B153E24ULL, 0xEE851C9B80427A55ULL, 0xE37691F92AEFE3CAULL, 
            0xBEE5FFE4D7652C35ULL, 0x762B78F60ECAE3B9ULL, 0x5CC712DF1D52CC0DULL, 0x6304AB531C55F247ULL, 
            0xD589E314AB676C96ULL, 0x6D090B9346A2D15AULL, 0xBCDB3721DA11F6B1ULL, 0x0E788A30C0C4B322ULL, 
            0xB6B092BA9894BF13ULL, 0x6583BD681465F360ULL, 0x30342084892F4B9FULL, 0x1F712807603176A9ULL, 
            0x809831B9D0D941FFULL, 0xF7ACD5D69DA15A0DULL, 0xB8E0A495B8DD152FULL, 0x29FBCB14FFAB8156ULL, 
            0x8AD91671353B2EFFULL, 0x99648A5C2DB57BA9ULL, 0x7745ECF8B3A81ADEULL, 0x7AFCEBB272DA98B2ULL
        },
        {
            0x9D3C1450ABD68E32ULL, 0x0906538E9E79B773ULL, 0xB3FAE3F4A365C193ULL, 0x622B4E2FD263B7A9ULL, 
            0x23E6E55CB522E1D9ULL, 0xC676E2BD9AA34957ULL, 0x585AA8A3B919C16BULL, 0x8F1CD4877AB79673ULL, 
            0x995622BCD557F461ULL, 0x78E785D352EDA348ULL, 0xB765C55D2A05EA88ULL, 0x412AEAECC00A2168ULL, 
            0x74289C9D3E52556FULL, 0xA41AD329AF36231DULL, 0xEE2B5F3327CD8606ULL, 0x0A7F299FD9705216ULL, 
            0x2F974D38FC158B75ULL, 0xD8B21265837C1CFCULL, 0xA6A69A823F1CDB6AULL, 0x16300D0FF4251319ULL, 
            0x6C5083879777EB19ULL, 0xAAAB9C344DA9FB34ULL, 0x12CF1228AA773C37ULL, 0x561C7161ADDD200CULL, 
            0xBA336980D3B1EB60ULL, 0xF715107315BEA820ULL, 0xE16E0EBCC9DEAB9BULL, 0xFE86145A64A0CC3EULL, 
            0xBF7CCCACF5B81CB2ULL, 0xB3BAF355726B1AF1ULL, 0x195EEEFA1C71066DULL, 0xA40B93648DEECE39ULL
        },
        {
            0xB42D0CB496D88327ULL, 0x7210B7B68AC79542ULL, 0x73E6999B14BDD5D5ULL, 0xB12F079E10F228E1ULL, 
            0xACC446C11D8722F0ULL, 0x442D28927FA05155ULL, 0xF1D3EEB22800C692ULL, 0xC1F32CC70F7EF409ULL, 
            0x485EA2F174738CB2ULL, 0x97D76AB3342DDB5DULL, 0xA1E83B325FD2F6B3ULL, 0x7980BFDAC61114B8ULL, 
            0x28B794606DE71766ULL, 0xC69B07D04CA879A1ULL, 0x3879A89CFD8C42D1ULL, 0xAEA8B8F292C1E47AULL, 
            0xB79341AB97B53DE7ULL, 0x90623CDF2EAF858BULL, 0x9775ED98BE4A2EE0ULL, 0x2AA7E299046C3318ULL, 
            0x30A85EE9090526D7ULL, 0xFF7EC91F9041B13CULL, 0x095FE7249379FBD8ULL, 0xAE5FAAE1F838CA1FULL, 
            0xF4140CF53C5BFAC1ULL, 0x745D633D7990BDECULL, 0xDB54C098E7CCDCA3ULL, 0xBCF615385E584217ULL, 
            0xA8AB0C5BE167762FULL, 0x651E46CBFBDBCD49ULL, 0x67F1CA97B2FA49E6ULL, 0x4DA8F8D2A8BD39B8ULL
        }
    },
    {
        {
            0x0351B1D6C8E989A5ULL, 0x812D5E2E389ABB9CULL, 0x1A73BC0E1018DEF4ULL, 0x1BD646E5DB226379ULL, 
            0x6F9C8BFB3F5CBCCAULL, 0xE957B24135B983E7ULL, 0xBD6BFA6D35D31132ULL, 0x95F7A4A6BC901F13ULL, 
            0x01F28824BC20BEC1ULL, 0x98AD4BC428CD064EULL, 0x62D1BB6477C80751ULL, 0x22320619B731249CULL, 
            0xE4E0F4DA5F2747D5ULL, 0xB4233C06A4BD3C5AULL, 0xDEDF023823461E44ULL, 0x6C454CA59EB2FC9CULL, 
            0x9BB2C7C75B20E8B4ULL, 0x65F534D7341834BDULL, 0x6E7489F5A7F983BDULL, 0xF9D75522E2BA023FULL, 
            0x5414A05E2DA1559AULL, 0x7C8514CFA426C757ULL, 0x63DF5D63793E28CCULL, 0x71E67558476794F5ULL, 
            0xC207775D0463CF4CULL, 0x05AFD32538FBB071ULL, 0x8C5EB9ED9DB579B5ULL, 0x53C189572C1F0B0BULL, 
            0x5D20986107DE204DULL, 0x4FA8ED18A7DFBCFAULL, 0x7C6D4784CF992213ULL, 0xCF1E79E13966AD96ULL
        },
        {
            0x144B9BCEA79FD517ULL, 0x07FF14D27E18FF0FULL, 0x52BD89DC71B3214BULL, 0x5C4C57D2940CE367ULL, 
            0x75B645E9B43801B5ULL, 0x454822EF064FE097ULL, 0x6C925D3D7A60C992ULL, 0x65EB370743842244ULL, 
            0x2BA2A24AEEA2AAE9ULL, 0x355D84DA77A82C55ULL, 0x46DBD13E6FFEB287ULL, 0x0B1E7A9FF9A63AD6ULL, 
            0x8A6947E5A1DDF0ECULL, 0x104399ED5C379FCFULL, 0xA8340C0E08C69395ULL, 0x9A55474C545B054FULL, 
            0xEA5C76BDEE16EFC9ULL, 0xF36E8915D19CD06BULL, 0xB0EB387492643E33ULL, 0x7C96907AE551E32FULL, 
            0xBFDED963777EB4C2ULL, 0x140E5C1ED9C11C9BULL, 0xBD337EC0A9B2A729ULL, 0x3D34CFC531C9633EULL, 
            0x7233F68445DE27E4ULL, 0x0F85D0D0561A605CULL, 0xB34017681B120ECFULL, 0x60FF1C0A7DB1DC02ULL, 
            0x9C9A0D21333EB9FEULL, 0xEF72AF6F748E321BULL, 0xEF30B9346A718601ULL, 0xE3EBA970A60CE2BAULL
        },
        {
            0x4FC91C6F2DB66F8EULL, 0xB907B46798110F9EULL, 0xCA6E8DDBD78FAA02ULL, 0xA0C517594760B6E5ULL, 
            0x813316B7B5FC1AD6ULL, 0x9F069B887C9D00ACULL, 0xA46D74F69E4B8456ULL, 0xDA0411F21356DB2DULL, 
            0xB296F6AE9BFAED3CULL, 0x2B2E467B3DF07857ULL, 0xA5EB70E732FD8769ULL, 0x27A264ECF51F4631ULL, 
            0x2D52BBDD50E27AE6ULL, 0x1DFE401975EA446AULL, 0xF99E2F010A16AB20ULL, 0x532EB956FAFC7FB3ULL, 
            0x1B4EDECF98787093ULL, 0xDF1A455AFD1C519FULL, 0x07A3C92E62D4F0C7ULL, 0xB734EAFE705CCC5EULL, 
            0xC94CF82B7DD23C5CULL, 0x31CAEAEA03F77C19ULL, 0xE2B44A3606B24335ULL, 0x529E698CEAA8C213ULL, 
            0x232DC23F44CD5BE7ULL, 0x821027DAD0CDEEAEULL, 0xC256AFAEDE848461ULL, 0x11C14E7386A59252ULL, 
            0x62FFA3F0B5079F6BULL, 0x1D67B877178EC74FULL, 0xBCCE21804CA56F27ULL, 0x05CEC242994362FAULL
        },
        {
            0x11697AB3F869F43DULL, 0x61E27D8289AD5F2AULL, 0x61BEF7C548AE6CC1ULL, 0x761C1E16A1EDE2D8ULL, 
            0x86DBB147F8ED26F4ULL, 0xAE48C5BFA9D0E84CULL, 0x921BACCE9EC78EE8ULL, 0xB6FC3D5D5562395FULL, 
            0x5B04868FBC648C5BULL, 0xA8142EB7BAA48F72ULL, 0x0B846B08819298F5ULL, 0x548AF6E2876BB63AULL, 
            0x314554C3D33B9454ULL, 0xDE03E86DC6BA077BULL, 0x43379EE964B410B7ULL, 0x1D45757ADEEC5671ULL, 
            0x807472F25204EB5BULL, 0x24C73C8735C77D44ULL, 0x34109388AE5144B6ULL, 0x3A5DF8221D888393ULL, 
            0xB58E2247F70D71F8ULL, 0x98F12C6EA3245603ULL, 0xC029544055133572ULL, 0x08A761C82EDF1A25ULL, 
            0x9A5A26D0B2FE1F33ULL, 0x748A8B333A060794ULL, 0xF47A701960D06604ULL, 0x707F3571183F96FAULL, 
            0xB1E53943B2DAC955ULL, 0x5441DFB5DF70D55FULL, 0xB91AAEDE27F37D17ULL, 0x00A8A7899C92ED8AULL
        },
        {
            0x6231BF475B6BD135ULL, 0x8B9BB15DC6F8A3AEULL, 0x4929AEF6154E5130ULL, 0x98E4F4A4D64404B2ULL, 
            0xEFE7CEA7211B0265ULL, 0xA5DA206CC0AD3118ULL, 0x34A19D06B7848499ULL, 0x280D68BC0373165AULL, 
            0xD9DB78B6F0F681E4ULL, 0x3409244C95E19A79ULL, 0xF27F6CC4FC612DF0ULL, 0x93263ADA7E9F5353ULL, 
            0x34AA20C032D65FA2ULL, 0xFC84D07DF3AFF39DULL, 0xFA377B74D7F66392ULL, 0xF0F250B69D8A5B80ULL, 
            0xEB2B4626C7D0D264ULL, 0x45B503728D8B9750ULL, 0x498504AF6AE07960ULL, 0x5177CCAE2A4CD16CULL, 
            0x40C3B6B3FF91C1DBULL, 0x12D02D0833A3A38DULL, 0xF8E52711B681814EULL, 0xBFE8F0BBC021F66AULL, 
            0x9B7C4FB3DB81F340ULL, 0x007080AF078AF2FAULL, 0xC79B61BE6AB54AB4ULL, 0x3F59C2B32B5FEE81ULL, 
            0x9C378E3FE04AAADEULL, 0x19F86A2D3F2C40ACULL, 0xBAB9C7C715D2D911ULL, 0x6A3C6431E3A84F27ULL
        },
        {
            0x1D2BF49ECBDE10CEULL, 0xCFB1867F70C51018ULL, 0x1C20B1806DF0CFA3ULL, 0xCD121A7A3DF6CFCFULL, 
            0x3EF612928D496E15ULL, 0x2C924E16CA9EE0ADULL, 0x3827A124D01113D5ULL, 0xA4F744865690AC53ULL, 
            0xAAC10F59BBB66E65ULL, 0xD58EA03674EBAF79ULL, 0x597BB74E7164CA45ULL, 0x826DAF77E444642EULL, 
            0x18B9899AACB8A9C5ULL, 0xE1C5BF17F9F068A8ULL, 0xB6C6A5A4241B3D1BULL, 0xA76A59D510D7E329ULL, 
            0x2B9CF17B776414F1ULL, 0x6A721CD64CAC9602ULL, 0x911EBD5836768667ULL, 0x452D32CEE009811AULL, 
            0x8C2F2E6288C00FC5ULL, 0xA39BF43D680AD085ULL, 0xC554E2C069CCCA4BULL, 0x9F5C95B6DA9F3F83ULL, 
            0x87B02CA19085AF77ULL, 0xA0A1E8E7C3C71658ULL, 0x9B320C329F815A3DULL, 0x75657685C92E9D78ULL, 
            0x1A85979ED13A8828ULL, 0x1A54A970821ADAD4ULL, 0xB27F58937B86C612ULL, 0x62A3D44FF3882BC0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseCConstants = {
    0x65CA54C6BD8D70B9ULL,
    0x11814675651B63FCULL,
    0x6ABC89A3A9F05550ULL,
    0x65CA54C6BD8D70B9ULL,
    0x11814675651B63FCULL,
    0x6ABC89A3A9F05550ULL,
    0xA787057261A2C640ULL,
    0x1841351AA05F27FBULL,
    0xD0,
    0x8D,
    0x08,
    0x6F,
    0xCC,
    0xE6,
    0x8E,
    0x42
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseDSalts = {
    {
        {
            0x691A93164E740426ULL, 0xB62A518080282D8AULL, 0xD4BEF93A733F3329ULL, 0x462B035C9283949CULL, 
            0x8786920F57407427ULL, 0x78CA56793D8360ADULL, 0xD78938DD8DFEE862ULL, 0x7F649851844D52F4ULL, 
            0x1EC0ACCBA0111706ULL, 0xF5C5F8A4D0E40A00ULL, 0xD3F8B407D95EAC93ULL, 0x79E31BEC1D918C96ULL, 
            0x79525087AF46A287ULL, 0x9109FCCA13F68814ULL, 0xCA5C3825F21F2F50ULL, 0x7EFD5CE344250D8BULL, 
            0x775D170ABBB64CCFULL, 0x37F3EA5BB2C52DEEULL, 0xD5AC0886EAB0F1FDULL, 0x51647E2EA3439DD2ULL, 
            0xB72AE5E247922B53ULL, 0xB48DD0F39ADD056EULL, 0xCE871C70C3DF2CD5ULL, 0x3024534F523DF725ULL, 
            0x902DF91270D65222ULL, 0x5577930F68C01C0BULL, 0xB9D1487E67FF312AULL, 0x823A8C6DB06D34B3ULL, 
            0x50F3D6E9ABD4B30FULL, 0xB638EF83D75D2F29ULL, 0xC61FF04EA7491067ULL, 0x9D544D04F29D6E04ULL
        },
        {
            0x44C95A19A73188B5ULL, 0x8BA58655F6CF0E0AULL, 0xCB669EB3C7310422ULL, 0xC7B3DCDA17C55A80ULL, 
            0xA48BAD754AD0FD57ULL, 0x786AFF460894D9B6ULL, 0x7ED87B82600372B7ULL, 0x85004CC960F245BBULL, 
            0xFCAFD42B169EA86DULL, 0x36731792E680B081ULL, 0xD1A91775663CC7AEULL, 0x8EBDE23C34A83511ULL, 
            0xCEA13360DFCDED17ULL, 0xB6C585A62C51BC6AULL, 0xD1289081AC4C78ACULL, 0x5AFDAAF15F016573ULL, 
            0x1BBCD2FA62495F8FULL, 0x377EE37518414013ULL, 0x840122365F24195CULL, 0x955A6D324E815BE4ULL, 
            0xA9EB4B3BF9AAE143ULL, 0x5E68508B25DA90D4ULL, 0x2D54E21D2B83EE90ULL, 0x5015DEB84AAF34AAULL, 
            0x6CC0954E3EF480F8ULL, 0x7537461A53F2DE5CULL, 0x9D1EED1ADE259EA0ULL, 0x1FAEAB055C1533ADULL, 
            0x6CE10CDDD9AA8B72ULL, 0x2497929781812D34ULL, 0x6FD061F08B1A4C3DULL, 0x755093AF262AF259ULL
        },
        {
            0xCD8CB89D3533178DULL, 0x27D69CBF50B5791FULL, 0x9D5B5C7F3F86223AULL, 0x1C1B93E9D037535EULL, 
            0xD8FE6D503573E669ULL, 0xF9D017532B5BD7DEULL, 0x2318034542F87572ULL, 0xDDACB06A59DDFADAULL, 
            0x22B934D2FBAB2DADULL, 0x8DC5C53E08AA8EB1ULL, 0xF3E6B0B1AAC5180AULL, 0x197044E443610A31ULL, 
            0xF30CFC8D341770EAULL, 0x40A9BDA37F6BA428ULL, 0x71388DE51C8CCAAFULL, 0x77D992E018A5CD5BULL, 
            0xD354133CCFCD3184ULL, 0xE9335C2A88CBDBF4ULL, 0xE43AA20727EC6E0AULL, 0x8B8B6A6EB912ED3EULL, 
            0xFC0E460F1F0A073BULL, 0x6AA349E26B08FAB4ULL, 0xCA378ABDA9EA5009ULL, 0xD08F5247D67CCB3FULL, 
            0x7B8A8257B32349AEULL, 0xACEDCC014EE986E1ULL, 0xF0FF204FDBDE56DCULL, 0xF62D5A81B1559BA0ULL, 
            0x58B37472A306BF74ULL, 0x996361B9BEDD8B36ULL, 0x82C97FE72A18FFEEULL, 0x0BECF6EFCB3D2D19ULL
        },
        {
            0xB9DFA83B249B2D96ULL, 0x06A0A909ADA570F0ULL, 0x62DAE404DF50B180ULL, 0x2F0BCE555A560036ULL, 
            0xB2FCFBCC2C525A2DULL, 0x99F300642D305FEFULL, 0x734CF9678B7BEC90ULL, 0xC3A0EDFD2DE1C8A9ULL, 
            0x9845340B9A247D5EULL, 0xC0BAA1DBA9A45F6DULL, 0x608C76242E2E69DEULL, 0x841ED563F1AEB95FULL, 
            0x6A9B67A7CF05F03DULL, 0x6B9672FCF1557A7BULL, 0xA5825DD7728B540BULL, 0xAAD91A3A131E10DCULL, 
            0x11D988D0B24CA4C7ULL, 0xB11B9813C5ED9D4EULL, 0xC34D29B11F0FBAD5ULL, 0x7296EC314C7F7492ULL, 
            0x357BA1A65678373EULL, 0x99AB492FE0A7C200ULL, 0xB0D693F5A651ADB3ULL, 0xDA2B0988B2DD189CULL, 
            0xC6562C604FA15AADULL, 0xF4609D7E6ED9E08EULL, 0x44AAE1DC60B87CE5ULL, 0x08F94ED3418B209AULL, 
            0x1644B17F1E038CA9ULL, 0x66D578E1BC6A39EAULL, 0x57C7DD0A870AB78CULL, 0x9CB799329CDE2F71ULL
        },
        {
            0xC4EB07A8148E60D9ULL, 0x81F456E41B2FE505ULL, 0x4E0F177D7D38A2AEULL, 0x8AB969081DB5386AULL, 
            0x27F392B51D80BFA3ULL, 0xCD40E1FF3455E246ULL, 0x3CB2B4813A0FEFF0ULL, 0x9C6322A860F3BCAFULL, 
            0xCB8377F3EF56AEF3ULL, 0xECAA09705E0F8432ULL, 0x2BB9B7B022CF8809ULL, 0x0AA4D0CE59937CF6ULL, 
            0xF4DFB501938A439CULL, 0xC684C2721AA012C0ULL, 0xD420E7D686AC9E55ULL, 0xBA6CB25D34602034ULL, 
            0x6798DFCA4D17A8A9ULL, 0x38B0E6D3D0E12270ULL, 0x53BC6B3329BC5823ULL, 0xEB318BC6F4ED50EAULL, 
            0xBA835CD34725A9AEULL, 0xCE63B5BCAA7BD517ULL, 0xF227D94147B9AB5EULL, 0x957734D30A49600EULL, 
            0xE347EC167132F171ULL, 0xF9FA0B63A140B44EULL, 0xEF94B7CFE505ED19ULL, 0x7FC6D7621511C6EBULL, 
            0x6E4104A3393FA79FULL, 0x32322994528BC383ULL, 0xF5F13EF102948350ULL, 0xCAB5F80CF5FC40D5ULL
        },
        {
            0x17150C44F84FC044ULL, 0x4C26AF825B14418EULL, 0x5D40CB607B5983F2ULL, 0x313C5782198F90C7ULL, 
            0x642F04D4A2B62322ULL, 0x911D0AA1A6F37C5CULL, 0xB591B65E1FBD1994ULL, 0x3E589E78E50F25CBULL, 
            0x2F86B9F9EB50CE69ULL, 0x352687DE6611B7C6ULL, 0xE184C45E592A4FFEULL, 0x6DDAF04E91C22CCCULL, 
            0x170884298BE1EF09ULL, 0x4EA1EB483F4AC0BCULL, 0x2EA5539168BD3474ULL, 0x142D995EA216D1A6ULL, 
            0x0F7196641AD1A9DAULL, 0xCD9CA792E86CC521ULL, 0x8FCAFF947A64B036ULL, 0x60B771A14E21E9C0ULL, 
            0x86EAA4945492830FULL, 0x3296C66671CCF970ULL, 0x3DB9E439242950FCULL, 0x561870FF23E894EBULL, 
            0x2F53AB16C8E49440ULL, 0x0B19D04B4B806EB1ULL, 0x2B5F511029B33793ULL, 0xC53D2EB2E4D4319DULL, 
            0x7DDB26DB5333941AULL, 0xB2F6E29B6760AACBULL, 0x8CF72C80FA62DC18ULL, 0x85534FF784F3105FULL
        }
    },
    {
        {
            0xD1CA83C9EB4AD862ULL, 0xD43A3A510BE72F02ULL, 0x2FE331C2A2906A3FULL, 0x2CC16A22AECE2B9FULL, 
            0xF25B1898163899C7ULL, 0xF29ACCB7E0648C50ULL, 0x3A1EED628E616514ULL, 0x7F58E4BC4ADAF864ULL, 
            0x59FA9C6D77CE887AULL, 0x6E1AFB8CBE83E67CULL, 0x475944C43D23B121ULL, 0xBC55531537709858ULL, 
            0x0B5B7C9AF5F9CF7DULL, 0x1C0D98D0EBA9362FULL, 0xF850820F568797CBULL, 0xF13A81EEBBD076D1ULL, 
            0xB69B60824044716DULL, 0x61B8840FCED15008ULL, 0xDA99A5DD45752D29ULL, 0x7675EF606153BB89ULL, 
            0x038E96C2AC6541F0ULL, 0x6E3B013F7B8B91AAULL, 0x5ACA45410E7061EDULL, 0x68278BCA7B2E11C6ULL, 
            0xEBDE8E50E8083509ULL, 0xA32F9CD08C01F166ULL, 0xC28931D1FBCA423DULL, 0x5BC9AB1BFDB33A5AULL, 
            0x3CD0CD264FF54A3FULL, 0xCBB00ECF23836D6AULL, 0xC0D6E930C381027DULL, 0x43AC38573BAEBB16ULL
        },
        {
            0x7B91D922F83366E3ULL, 0x294EFB8E62F595A8ULL, 0x6CA5874B3BD0E21CULL, 0xDC36CEA69006F8E3ULL, 
            0x4D3329483AB38D9DULL, 0xEDFDDF24EE40B6FEULL, 0x5B935E5D2614976BULL, 0x771D1784E6B9112CULL, 
            0x9E5AD34DD6446800ULL, 0x2E9F23EECA6B357AULL, 0x0691035C201C0A75ULL, 0xCAD17775D99D34D0ULL, 
            0x52E97C196653387AULL, 0x018BE60D91121BADULL, 0xD6649578FE0B874BULL, 0xCC8263E5D55612CDULL, 
            0xF9AEFED018A1FCF4ULL, 0xBACB168A92DDA893ULL, 0x3CB7443E925EF677ULL, 0x24CB277C07472151ULL, 
            0x75869C1FEE3D75C8ULL, 0xE373D641DA13CDCBULL, 0xAB900B4E70C128A4ULL, 0xDF7D4F4241CC59A8ULL, 
            0x205FEB354845B5D2ULL, 0x41DC2683B78633F7ULL, 0x459BF280052AC641ULL, 0x6E999B91FFBAFBFFULL, 
            0xF78952F25A903347ULL, 0x743523EFF5010D06ULL, 0x6216399ACCBD01F3ULL, 0x9BD944CC53CF0ACAULL
        },
        {
            0xE1E81A079108842BULL, 0x73D8A0DEB643457DULL, 0xDF9EB5D6E2549939ULL, 0x95565D7C95E1DE9DULL, 
            0x324EF7DB35A340DFULL, 0x2A3DCE19B8B05E37ULL, 0x25BD84D9F5778ABBULL, 0x9AA27F04715965AAULL, 
            0xA63703A37378A6DDULL, 0x838B8CC7C902F569ULL, 0x6F7091D5599BA630ULL, 0xFB961669914B6982ULL, 
            0x18E69F00D50D80D5ULL, 0x3D29F97A3CABEA7AULL, 0x8690AB4FCE733A24ULL, 0xB41D50C9EFC71546ULL, 
            0xD5190B30D13EFB0DULL, 0x51B352F2A9813D84ULL, 0xA31D9AA0DA30ADC8ULL, 0x635D7D5CD6B594F2ULL, 
            0xF9B854ECA34A258EULL, 0xEE80682E4F913F94ULL, 0xCF42B5247C65278CULL, 0x04F342D59E598DE1ULL, 
            0x54BF7344BCF4B478ULL, 0xA41D1A27E3969D11ULL, 0xC9EED0451F556083ULL, 0x7FE772592E2197BEULL, 
            0x11D381DF039B0685ULL, 0x1EE0E29C687D108DULL, 0xED0A4F3B9B0D4FE6ULL, 0xE91A41ED15648074ULL
        },
        {
            0x23B2DF99837253B0ULL, 0x2B7AC076F76AC675ULL, 0x5F6DD2EF40BFDCF8ULL, 0x4FD94C7EF8FB8D44ULL, 
            0xE212519453FFC578ULL, 0x07844FBE891FC8FFULL, 0xF659BAD81EE401F1ULL, 0x166821671D342F98ULL, 
            0xE96D7C570BE5481FULL, 0x3EE16576CF5B053AULL, 0xA45253962F140E48ULL, 0xD8F1C5E9F04042CAULL, 
            0xB082E37B5F9EC21CULL, 0x010CAF02834FFBDCULL, 0x5440CAEDA0DE83E9ULL, 0x2A8201924D0C43CEULL, 
            0x1EAA91768A60CB9FULL, 0xC80CFB45D30D0F21ULL, 0x2266A630E84DE31AULL, 0x822407CC400B4B05ULL, 
            0xB65BD47A9E978666ULL, 0x2CA02BE621AB74DAULL, 0x893EA5C158FE1B7BULL, 0x181702E602429CD9ULL, 
            0x84B4E67D4FDC388DULL, 0xC8E4E7AD27FFBE33ULL, 0x9EF4417293E106C8ULL, 0x4B38E73B77D71D88ULL, 
            0x4A0300CF18DE962CULL, 0xC9668A8A95737C64ULL, 0xA7B7FA2FFFE0380BULL, 0xAE095B52366CCB56ULL
        },
        {
            0x466BE1810A261B24ULL, 0x9BA59024FBAF11CBULL, 0x576568DE750B9EA5ULL, 0x300AFF2D156BF783ULL, 
            0x79D03D61FC2C0028ULL, 0x8B13AE0F4250BF55ULL, 0xD7CEDD63550BAD63ULL, 0xB211C5E84F444AD6ULL, 
            0x1EE399CCAF843933ULL, 0x9AB04FE7AC923D28ULL, 0x9B8D258BA843954EULL, 0x78A835A1D7757ED2ULL, 
            0x78736241444A1D62ULL, 0x51ADDF2E3CB47F12ULL, 0x790CDD47CE6B9EE4ULL, 0x5723725707774F94ULL, 
            0xCE90002350D45D87ULL, 0x2057C4136B20AFADULL, 0x1F67FA860A854C49ULL, 0xC058B4C41D19008EULL, 
            0x6A532A27405E16CFULL, 0xE5A39DC8890C2DE0ULL, 0x061DE064C23A3642ULL, 0x08CC869CC1C4CF11ULL, 
            0x45E6EB53BB7C0472ULL, 0x6C248FFF0438E1AEULL, 0x6AC16338CE161B86ULL, 0xC7BA1540BFEAE562ULL, 
            0xB7146131C98B4451ULL, 0x98EEF7AEC3364477ULL, 0x89BCB3C2A843224EULL, 0xB11619388DA875A7ULL
        },
        {
            0xCED0152DAC9F7E8FULL, 0x7F279B3BDA0D2FF9ULL, 0xABF15E17E359F99EULL, 0xF0BA3024B6872203ULL, 
            0xFEC2FBDA0018F39DULL, 0xB743DB359F0F8E8BULL, 0xE0991AB6AE959751ULL, 0x1E19876D2CB40656ULL, 
            0x8092B13C6875BC78ULL, 0x82BF2D6D63A925AEULL, 0x834111B584B23F14ULL, 0xE535CD3E79F1D44CULL, 
            0xF7C6873EB700705EULL, 0x08FC8033DDA8477CULL, 0x9020EB6B69FE3DA2ULL, 0x029B624A3DCCDFCDULL, 
            0x4929662204EA04C8ULL, 0xE4E38B66746CCB7AULL, 0x7891422249B547C9ULL, 0x677E896A2780BE8BULL, 
            0x051AD619B0E47EC4ULL, 0x13F6EB201FDC885EULL, 0x76EBD7F465E8B700ULL, 0x3A87A40E53C68792ULL, 
            0xFDE5AEFF4F018489ULL, 0x3310ACF78B1AC060ULL, 0xCC7CBCA9EEACE4ECULL, 0xE09A81495CF8A6D4ULL, 
            0x5F4697ED7482A573ULL, 0xBFCECD2CE4A4FD78ULL, 0xA10E4EB63A6EB462ULL, 0x57287CCF0E236ECBULL
        }
    },
    {
        {
            0xAC97B1883600110DULL, 0x2111CCF943880670ULL, 0xFFF43266FEC202F8ULL, 0xF68400488DA503B5ULL, 
            0x2CE79843E76DE0EFULL, 0x27CB098DE25F90EFULL, 0x420F3333C5B9D2E4ULL, 0x63FB2278E4887C35ULL, 
            0x3CD9D80D52B0BAD0ULL, 0x0F37A16A40112F9EULL, 0xEA0BE35DBEB3AE27ULL, 0x8B966EF0BEDEBF04ULL, 
            0x344794F94115473CULL, 0x3966F3BF364242D7ULL, 0x8DDE2BD9FC717A59ULL, 0x3377422B98E2F09DULL, 
            0x01C0B151EB3E4026ULL, 0x2BB1BF81D5CFB3CEULL, 0x678493E3F5EDB76FULL, 0x48E500B33A8D4D26ULL, 
            0x04F19F0F51997BA8ULL, 0x39671C74FC294E94ULL, 0x934AEB9219F422FCULL, 0xE2E49F21F0B63672ULL, 
            0x9707E3AF750AB550ULL, 0x8355031DF4ECD628ULL, 0x45DFEEF5E5F458D4ULL, 0x2F3D180AAAE1E308ULL, 
            0xE80B22C2CCA271E0ULL, 0x890A9D5686CF72ACULL, 0xAB71341B819377DCULL, 0x1E0DF58160ADDCCCULL
        },
        {
            0xC77855A5B8BCB95CULL, 0x3ABBBB37646E6B0CULL, 0xF5682742FF7859DAULL, 0xB1C20A5346991304ULL, 
            0xD96C4BFD021747C7ULL, 0x620C65CC67F917A2ULL, 0xDC86788FE1FFE2DFULL, 0xE16B9F009A4A6A47ULL, 
            0xADBA654C6EFFF0C2ULL, 0xE4F92EF6189826D3ULL, 0x0DCBC53D45F2ADA2ULL, 0x9C7AC3F1C1B77CC0ULL, 
            0xC77287E0295408B0ULL, 0xDA7722EB19AB87F9ULL, 0x0035165301B9890DULL, 0x7E37824C4C22FBF0ULL, 
            0x4BDE61E7CB08D4D6ULL, 0x594EBBC0F20CEDDEULL, 0xB549C2E76C112467ULL, 0x3988925E9EAA554FULL, 
            0xDCDA283002C2AAA4ULL, 0x016C0CA04DA7FEABULL, 0x9FEDC7D45D67DBC5ULL, 0x5100EA0AC441A0A8ULL, 
            0x27FDCA116FD4636EULL, 0x4DC5C1C6CF58D3AEULL, 0xA3D019FE200B677EULL, 0xF23CACED4D8CD42CULL, 
            0x0244A8AF1D3F9C76ULL, 0xE043C817B5688249ULL, 0x2CA92361B26FF86FULL, 0x8C2E94BD20D92779ULL
        },
        {
            0xADC3D87085B8D869ULL, 0x864D032023B903DFULL, 0x7CBF05191E7C5E2BULL, 0x94291E2330500BF7ULL, 
            0x61A884AA94360904ULL, 0x58CEC0494A2862F3ULL, 0x42A6E3D332C4A1D5ULL, 0xF95BFE1DBA1F7953ULL, 
            0xFF3228B2BFE5CFD0ULL, 0x68A962EAC71B9CA3ULL, 0xE834AC96CB524145ULL, 0x1CF205E09088BFD6ULL, 
            0xC4E0F00BBCB2C23FULL, 0xB122229794FC9DA4ULL, 0xCFC5E39200EB3FC7ULL, 0x3E8DC07DDA8E514DULL, 
            0x28BC17247AFC80C9ULL, 0x49A8D2DE27C8C9E8ULL, 0x1E9A6F340CEB4697ULL, 0x7792AB91FE5E4DE5ULL, 
            0xE332D57461E2C1BBULL, 0x3AD2B4D9D825F818ULL, 0x21A7CD548B609160ULL, 0x9E9F8A88C709FA8CULL, 
            0xD884F06415C51A92ULL, 0x02DF3490D3547CBBULL, 0x94B04BE8B1D85093ULL, 0x8F24209FCB42A249ULL, 
            0xA11EE571C642C390ULL, 0x58637A6CDC7D3D0AULL, 0xF673406346690F00ULL, 0xF0F59E2916B30CDBULL
        },
        {
            0x7328C0DF946B16C8ULL, 0x646EE33C29C0D475ULL, 0xE20C141226B48DC3ULL, 0xD9354D7901A96B23ULL, 
            0x931083E12943CD3FULL, 0x4BB533CD8023ED3FULL, 0x8BC24992D0385D17ULL, 0x0C6B23CBF9498917ULL, 
            0xEC4C94982BAE47A0ULL, 0x322AA18D67DAB7BAULL, 0x6A84D4D27256890AULL, 0x1057DD7A683930F2ULL, 
            0xE35B1D37C62E9659ULL, 0xD67A48229F27A6E6ULL, 0x683EE2DDAEBBE0BBULL, 0xDE243910E5A15EE6ULL, 
            0xEDFEC10F60D4EFC5ULL, 0x3AA34A2E4DA54CE0ULL, 0x014D4B09AD3866E9ULL, 0x96738CD39CC84A4AULL, 
            0x177F63B1E4FA6CE5ULL, 0x4874CD2FACCBFE1AULL, 0xD46D4FE57F88C43FULL, 0x11F28A1C2692AC71ULL, 
            0xB019DC4AC999AE4BULL, 0x16E8276B7ED2040BULL, 0x5924D0CF0F8F15C5ULL, 0x558938597577808FULL, 
            0x9C735D90D43CDF4FULL, 0x60C6C8A8F57812ECULL, 0xC1FDEB542B1298D5ULL, 0x2177F1A70BF38941ULL
        },
        {
            0x3FBFB228538CF9B4ULL, 0xC3E02C3A01A22020ULL, 0xBAADADDBC20168F2ULL, 0x449445BB342DABCEULL, 
            0x2448DB6245E88D13ULL, 0x5546FCBEEA66F42EULL, 0x4287C90AAD243583ULL, 0x4E3B1A62985BFE9EULL, 
            0xF82A0EDDC75D2B81ULL, 0x211C2CE10935010BULL, 0x0256EE880EA0916BULL, 0x4D02831974BB15D9ULL, 
            0x3BC1517E9E27AF3BULL, 0xF2E8C45BE67EADC4ULL, 0x9BCB5CC34B4903C2ULL, 0x0B09F3D7DC1DEE2BULL, 
            0x84483F520FA3D795ULL, 0x9E53C98A70EF6F98ULL, 0xCA70E4839CDD4DA2ULL, 0xE38E5E46D2601702ULL, 
            0x7B47497633D92E1BULL, 0x064EC89C3BC1EFC1ULL, 0x7D1A75561C636DA2ULL, 0x7AD37E592F2DAC1CULL, 
            0xC8388FB8042D8AFBULL, 0x529B887D08040239ULL, 0x266F12282B739233ULL, 0x79CF11F3BA6BC551ULL, 
            0xA55CD80144F23DE4ULL, 0x9217CACE93D1A7F6ULL, 0xD8B285ACC478E60FULL, 0xA4673AE67F32F7DCULL
        },
        {
            0x5120B1A6886B200CULL, 0x7A50B671B96B8378ULL, 0xDA0CB700D17FFE5DULL, 0xA4D81DD8AFE58795ULL, 
            0x4A46E8D34A987566ULL, 0x36C3B3F8769294FAULL, 0xC9D178B1118F71C4ULL, 0xD30688F46C60DD5AULL, 
            0x3D625B85637FB817ULL, 0x7AE1C916F5065AC6ULL, 0x19FEED02A88461E0ULL, 0x21B0F600E3B05D3AULL, 
            0x32F5EFA6B5197BE6ULL, 0x0D1AF8FEB7687BFAULL, 0x8FED73B8CAA898FDULL, 0x6893DF67D359D2EEULL, 
            0xB1C2920D08B610C0ULL, 0x56F2D8A59F99AB3AULL, 0x35EFA8EFF4E3A921ULL, 0x156A8D090CA73280ULL, 
            0x52D668A26E1B140CULL, 0x23CC019AE4686ADFULL, 0xE0C93C81F5CD3688ULL, 0xB93494D49CE6A036ULL, 
            0x4653D29C380FDAB5ULL, 0xC464FF418C2BD21FULL, 0xE898BDE1B27E18D2ULL, 0x0B8FDA14BBFA6D60ULL, 
            0x47689FA72C540DECULL, 0x5AFD4D28BDD719ADULL, 0x97D3781BC2F6BCBAULL, 0xEFF49B3B5037EEABULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseDConstants = {
    0xEAEE48013D36EAE0ULL,
    0xB9E89A62B69BF1E3ULL,
    0xADC190CB4130AA67ULL,
    0xEAEE48013D36EAE0ULL,
    0xB9E89A62B69BF1E3ULL,
    0xADC190CB4130AA67ULL,
    0x36D3B311C81D1516ULL,
    0x711D7BF88755916EULL,
    0xE6,
    0x39,
    0x84,
    0xC4,
    0x45,
    0xB4,
    0x67,
    0xC6
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseESalts = {
    {
        {
            0x024F3CEC64B9F0A6ULL, 0xF67402F31F2046CBULL, 0x43928B53EC815299ULL, 0x5570C57619742FAFULL, 
            0x71DCD54C29461679ULL, 0x6D60A3A48CCC70B4ULL, 0x83F524EED286A8BAULL, 0xBEAD52A9A12F06B0ULL, 
            0x057191DE47562BC3ULL, 0x3342857363B4D7E2ULL, 0x548AD0B9265DD7D4ULL, 0x76520B127871CF48ULL, 
            0xADFEF93F03846988ULL, 0xAB89019907EF716FULL, 0x615CA382644B75BAULL, 0x417B580F13E7CFE7ULL, 
            0xC19FB1D5B5E9E1EBULL, 0x321A4B6F625A05D7ULL, 0x8C7860FA6D995199ULL, 0x34E852D66F0A7FD5ULL, 
            0x379B09625525876FULL, 0x6CD69DD718E1EF1FULL, 0x2F8441F450FD889FULL, 0xA610D430EA12FC4BULL, 
            0x6F87DEB671C24A4BULL, 0xCEC916E7E00F4B67ULL, 0xA1B5A6523E3B4F88ULL, 0xF356A43FE96CABC1ULL, 
            0xD256FFC1D0352469ULL, 0x550D728E70DC8800ULL, 0xEB281C20F51B09B0ULL, 0x474DB59EDC444501ULL
        },
        {
            0x9834BBBE6C1AD307ULL, 0xCE3FA9F4587AA571ULL, 0xB327CA479CA7AF4BULL, 0xFD7324189234F15FULL, 
            0x6AE706216C110C02ULL, 0x29CA9524F2979F74ULL, 0x45828947DF9C6F32ULL, 0x404A82564BB9D7A0ULL, 
            0xD34B48CFC2792251ULL, 0x11A15DD22E20D659ULL, 0x01C98BBD0B82D5D2ULL, 0xE6E978970BEBE641ULL, 
            0xB6FDE0CA0AD93989ULL, 0x8862F87E08340DB5ULL, 0x0811016CFF7A4580ULL, 0xFD07C3030125C801ULL, 
            0x7B4F125E5E874D9AULL, 0x28CA37A34407E8ABULL, 0xC49C5AB739D97842ULL, 0xD1BD2255E4951DECULL, 
            0x52EDA5087DDB85AFULL, 0x49143CD670F368FFULL, 0xC38DD5DA21304169ULL, 0xF333EC3AAB3D85A8ULL, 
            0x5033CE6B44C13A2AULL, 0xDCC4DFFB7C9A354FULL, 0x8557063F8D40C503ULL, 0xC57E4AFF025B48A1ULL, 
            0x414ADD35CA40F02EULL, 0xA4769BF2BBB70C81ULL, 0x45CF9924AC3AE435ULL, 0x184F2B313E9B75A0ULL
        },
        {
            0x8F6E4CE31B278E3EULL, 0xC4825C0EAACD7865ULL, 0x1AA41BC21757546BULL, 0xA88954A0D4875C5DULL, 
            0x6E3CC3ED00D6DD71ULL, 0x0AFC6BC785A618EBULL, 0xD35AE4ECA47D3031ULL, 0x9F65F7FA1B33C463ULL, 
            0x880EB85905EA62EBULL, 0xAEC46D7A0BA34C0FULL, 0xC188C08B7950AD4EULL, 0xF776A7C68B7C4238ULL, 
            0x43689E3A6248831EULL, 0x5CDB39359B30B0DDULL, 0x7231C6BEFE6A2F8FULL, 0x08F92C775615D6BFULL, 
            0x95318EBACEDBFDBCULL, 0x001E59990B83933DULL, 0x3906209716A00A64ULL, 0x63C91019F3489165ULL, 
            0xE293B59A1DA0DB05ULL, 0xE11B247E445EA4A7ULL, 0x5A8EED9795822319ULL, 0xE58F8E64778D7627ULL, 
            0x40DE73DF081AD6B3ULL, 0xCA5685375468D129ULL, 0xDA2D5BB3F4A37977ULL, 0xEB47B2530AF094FFULL, 
            0x2047256AA4F7156AULL, 0x86289488F9CF6F5EULL, 0xC0C405907FADD547ULL, 0xF13F895A7255CF2AULL
        },
        {
            0x915991C895CBEC31ULL, 0x23478DDD6866DED3ULL, 0xDB387B345A588934ULL, 0x4B99861C61D93FD8ULL, 
            0x0449C2A955C793CEULL, 0xA3982BF4F9D1FF55ULL, 0x3ED9D7DC1BE61BF6ULL, 0x6940C1BCB554B60BULL, 
            0xAE90FF1A498443D9ULL, 0x9A23313A106420C3ULL, 0x280039184C90F5ECULL, 0xDFF4AD8EB5D03FEBULL, 
            0xF08408936D578EA3ULL, 0x82124D4B83772303ULL, 0x4776FCF40F347A94ULL, 0x4D61A1D82C1F681EULL, 
            0xA0A85E4A621E1AEAULL, 0x1C9A8073EE2CD56CULL, 0xF86A9DC056904DA9ULL, 0x05359BB885F60DFBULL, 
            0x11D9104B31F5DFB0ULL, 0xB24107B84D2F3FE1ULL, 0x0582DBDF74F19962ULL, 0x3905515599126EA9ULL, 
            0xEBE4BBF053EE5DC3ULL, 0x8D847BA2A8529D51ULL, 0x052F55737B4D0379ULL, 0x028007AD21EDEB5DULL, 
            0x1F6289A8ED9915FEULL, 0xF1A3B58E22F18550ULL, 0x00ECD7AFF17A2231ULL, 0x0A08F4E6BF7DC4D6ULL
        },
        {
            0xB7AC9D46EDD21301ULL, 0xE3DE547E0F29295CULL, 0xB142A36A8A076456ULL, 0x212E8A1BC3441AB6ULL, 
            0x0264DE126E409244ULL, 0x94D3BE6484665CE6ULL, 0xB31E1DCCF3FDC885ULL, 0x64593EC2189B0CADULL, 
            0x17BDC65FE13B1431ULL, 0xF02D52EE56012510ULL, 0xCCFDA3CA0048C251ULL, 0x12079302323B971DULL, 
            0x254BEB353BC98FE7ULL, 0xED7017E66CFCB41EULL, 0x1BF4B6D817BF504DULL, 0xB1FE04F9C758941CULL, 
            0xDA4132AEDF40D30EULL, 0x5DD0F00BF045A82CULL, 0x0A7B4DF41D1856E0ULL, 0x96F044BEB0A6DD1AULL, 
            0x05A7FF59D35E961BULL, 0xFA9E98357E11ED3AULL, 0xF992B814298212F8ULL, 0x7381A53F7B208EEAULL, 
            0x94D96997285E97CCULL, 0xFA0F7EE535458965ULL, 0x1AB3094102CF487BULL, 0x9D601A2A9F654D63ULL, 
            0xEB4A76E382D2A7C6ULL, 0x7BF1BA40D4A2DFF5ULL, 0xDD63A5CCB7C670DCULL, 0x8E16DAC5490562B2ULL
        },
        {
            0xDA5D2FC580A74834ULL, 0x2A94969BA65D13B9ULL, 0xA5454DF377A353DCULL, 0xBFBBAA1D435D1BA7ULL, 
            0xB764C1EE9B3BD0ACULL, 0x7EAEC77633BDE5F6ULL, 0xD6D5A829953C39CBULL, 0x1F80D3593B8F79A6ULL, 
            0xD0F95E2B364F2DEFULL, 0x7689371EE2D1F29CULL, 0x3CE2EDFEBF7723BBULL, 0xC58A15B044122E85ULL, 
            0x183B70960611F565ULL, 0x11AF0C15BCA24152ULL, 0x5305DB259C9FA2FCULL, 0x1DD74909297B913EULL, 
            0x7D05DD5F6BAECE2EULL, 0x10E3418A096042ABULL, 0x05092A4C012266D5ULL, 0xFFB93C5AEA3977F9ULL, 
            0xC0E54EDA21B14030ULL, 0x9FD0E321915383AAULL, 0xFAC3C884E152D52BULL, 0x12ADA3E5152681D0ULL, 
            0x78446626E5792E18ULL, 0xA2CD8E30D1581488ULL, 0xBB4B2598E7C8296CULL, 0xE18AFED5B92FB58FULL, 
            0x97855C23D4E267B7ULL, 0x28FEF061B8FF3114ULL, 0x0420B51F5F6BF867ULL, 0x847665BB17427C5AULL
        }
    },
    {
        {
            0x8E9435397446C720ULL, 0x48B095CA75207C0CULL, 0x157C7792EC383F2BULL, 0x68F81DA5A33E9372ULL, 
            0xD9EFA350CC576AF0ULL, 0xEB8D73B19E246282ULL, 0xEE539B163D470DF5ULL, 0xC334CABBB4C14498ULL, 
            0xBFC0FC88905475CCULL, 0x0B88D907A0402D83ULL, 0x749CC68566715AF2ULL, 0x452AD7CD1F3A3CC9ULL, 
            0x6831545C75C62A08ULL, 0x5DBF2A278C0BCC2DULL, 0xD229D1D58B1C1094ULL, 0x163F49C7D833DD6DULL, 
            0xCE77510DD98B756CULL, 0x986A4FB60EB39862ULL, 0xAFB3C3F34804B924ULL, 0xCF1E3DC55E514E52ULL, 
            0x23A5B29E8F38872AULL, 0x7F56FD82B6CF41E6ULL, 0x17066501ABBBD302ULL, 0x391D6A92A67D19C3ULL, 
            0xC51CF132FCBA93B5ULL, 0xF8D13E1AF97DB54BULL, 0x93F6A3E3FD14A382ULL, 0x573323B3EB4F86BFULL, 
            0x675A974A3D12186BULL, 0xC212AEF307BF301EULL, 0xBC87DC1C3D9659E5ULL, 0xFA94C70467CA7376ULL
        },
        {
            0x45A194068A8C32E5ULL, 0x35D6B5B826F24343ULL, 0x1D20F4DDD566BBB5ULL, 0x4DDB967BC33C8216ULL, 
            0x4F7B5953165E9AFBULL, 0x17B92520BEEAE801ULL, 0x92B0D984E0E5FB66ULL, 0x4CDF54FA565CF027ULL, 
            0x461F2EEE9869100EULL, 0x5658D096F8E0D651ULL, 0x303E097EC3AD00DEULL, 0x8BE55C0A96AEF961ULL, 
            0xAEEC6B448B8F049EULL, 0xAAA591CE47626168ULL, 0x2BD30B5934B5CF55ULL, 0x5042355F86C315DEULL, 
            0x7DAB9DC884E8924EULL, 0xB381F25496534EC6ULL, 0xDCCD14A878C320CBULL, 0xD451BADE666C7E68ULL, 
            0xBF8E1BD717369D0CULL, 0xDA384EC042BD53B6ULL, 0x67FADE75F196BDF6ULL, 0x6B60201F7AC518E9ULL, 
            0xE8186A07199F228AULL, 0x5EC745DFCF6871BEULL, 0x584ED05DE8FC1047ULL, 0x7144A7AD4A048B3AULL, 
            0xB191DD178F0171F9ULL, 0x84DC12B5AA184F7AULL, 0xF0D4F9E81C4E2F31ULL, 0x72692F02D736B84DULL
        },
        {
            0x4FA01877464D6121ULL, 0x4CC1525786F4D1C6ULL, 0x5B5B740FBFB949FCULL, 0x3AA8B8C187C99C14ULL, 
            0xB80AC5CC710AF9C2ULL, 0x92AA74F0FCB7E28FULL, 0x1F682DE08275453AULL, 0x3784D21B60C3341EULL, 
            0xC49CC49166CB9E86ULL, 0x822E9E09C4607777ULL, 0xA1DEF078D8F7BE3FULL, 0xB395DE142F61D757ULL, 
            0xDCC2924FC76D6E52ULL, 0x4991741B33D1DAA3ULL, 0xEBBC14BAC266E233ULL, 0x577A7D7B884AB8B2ULL, 
            0x74F49228E85499ADULL, 0x50B755ED22533236ULL, 0x24C750B6110FC4AEULL, 0x14FDA2F0C9773A3AULL, 
            0x2C4DC9F33DF60168ULL, 0x01B2F7CCAA2B27B6ULL, 0xCB23323334F9E7FFULL, 0xCB058AA21BE168DCULL, 
            0x3E419DB2D5037C74ULL, 0x963034C573338147ULL, 0xE550C8F4A612BE24ULL, 0x4F8B3191407169B6ULL, 
            0x16B80E99CAB56A68ULL, 0x2E6C2DE86C7127A5ULL, 0x548630146A12086DULL, 0x527729B462F202A6ULL
        },
        {
            0x9BD475912836B019ULL, 0x7470A88A8DC24696ULL, 0x07DEA0BC85F40B35ULL, 0xE0184F89385F5B46ULL, 
            0x79BABD48BACD287BULL, 0x78E418C6412048BAULL, 0x468B29E6657B9755ULL, 0x8AD81BE74BB1457EULL, 
            0xDEB1A9D6A7C5206FULL, 0x8A739074F2B43436ULL, 0x2E4BC65938EAD2F8ULL, 0x5A52E87A6DC8D140ULL, 
            0x70C5BB04CF82021FULL, 0xBA9195860B419AB1ULL, 0xAB339266E84AF0D7ULL, 0x9AD3AD53ECB07894ULL, 
            0xEDA8D0501A423F16ULL, 0xEEE43BEAB69D529CULL, 0x646A0D280BB3F232ULL, 0x86A53A05EC3A47D0ULL, 
            0xF844CF44F8E9DAE3ULL, 0x98246D565DD798EEULL, 0x31FCB0842DDEEE87ULL, 0x19F2D1F4F2E56E51ULL, 
            0x7D8637CF37C04D1BULL, 0xC2F22DAF1928A60EULL, 0x3BE4551FAE9AFD45ULL, 0xBF3A9ED2F8869623ULL, 
            0x88E483628F1EEFA8ULL, 0x1966CD045086B9C3ULL, 0x02B3499658B894FBULL, 0x1CE331A635BB9DCBULL
        },
        {
            0xB079EF4A5D458B40ULL, 0x6B7C476115A7D104ULL, 0x57AF9D8351205236ULL, 0xAEF8AC1809D8A23CULL, 
            0xB549C8AAC88053F2ULL, 0xF81570314F8BE71BULL, 0x0981B0AB956F9564ULL, 0xB1BE2818B245A1C1ULL, 
            0x02193C25768C2F56ULL, 0x80C19EAB348A3DD2ULL, 0x9ABFA741C3C3183AULL, 0x0E32C0CDECC02B2DULL, 
            0xD42DF481F409A9F4ULL, 0x167BF732B2E61D1AULL, 0x8056ED2E3AF4F787ULL, 0x827A18863EEB243FULL, 
            0xF9EF6C6010FC8831ULL, 0xA85B4EB7F7E3CEC1ULL, 0xFC344278D1320339ULL, 0x08EDEFFEA758F8D5ULL, 
            0xE8E14FA9C96258DBULL, 0xB410E1DEDAA8351DULL, 0xE219E4713A74DBC2ULL, 0xAD66E9100417038AULL, 
            0x523584A19A777155ULL, 0x598ECB68008F6A7BULL, 0x5414945C40DAF4F2ULL, 0xD88C95C13C1B96D6ULL, 
            0x3DE362DE0D07756FULL, 0x7744B0188B8AA68CULL, 0xF901520464E0FDF9ULL, 0x806FCFAC54998243ULL
        },
        {
            0xFDA2EBD8F262D32CULL, 0xD3150E0AFE5253D3ULL, 0xF87117BE19EA5DF0ULL, 0x5F1373201F76742AULL, 
            0xFB26F39EA92F095CULL, 0xFEE158EBA8C6A870ULL, 0x05E1D3F762DE9EC5ULL, 0x7B63FBC18A06034CULL, 
            0xC2FFD39CE548A98DULL, 0x25193281DF357ED2ULL, 0x91A16FEF13526E83ULL, 0xB7C35446281A983EULL, 
            0x444EE90E9F0854CBULL, 0xB222688DDC0005BAULL, 0xC10F02CC20D23F9EULL, 0x383B457DE4E8CA5FULL, 
            0xD1FD0BF56D2A4560ULL, 0x72753DBF7414A22FULL, 0x1564A3AA67DA6C29ULL, 0xE8078A482303994CULL, 
            0x625C200D4E5B5A4CULL, 0x68F59FAEFF1C0526ULL, 0xABA9C104E6D7F9D2ULL, 0x21D410C6AF7571E1ULL, 
            0x904EC11F5710CFA8ULL, 0xF5D42712E2122335ULL, 0x567A92EDE19C5523ULL, 0x46A3CB0FEE83DF83ULL, 
            0x787B22786B1D8676ULL, 0x91542870F3D02ADDULL, 0xB6B89C79E56192E5ULL, 0x0A9FA114A07E60B1ULL
        }
    },
    {
        {
            0x03D85C984750010CULL, 0x4964ACA617F96A66ULL, 0x8117E394C9CC8F10ULL, 0x1F6D7E9C7004F0E0ULL, 
            0x59CC3ED26A07601CULL, 0x7F7CA32A1075B9F8ULL, 0x4632762BF3CE54D4ULL, 0x3411063D057BE390ULL, 
            0x8095C627E524259AULL, 0x11D9573995C943EDULL, 0x690704932211DCF0ULL, 0xF9E977998F8FC5F0ULL, 
            0xAEBBA3B3DA08D265ULL, 0xFFD1281F841C84EDULL, 0xCABE3F24A41FE27FULL, 0x9FDACEAB8F34D160ULL, 
            0xDA486EBB806E55C8ULL, 0x2D4A0BF62A62E78AULL, 0x99B91FC6897D47FFULL, 0x6B72092769D794B9ULL, 
            0xD3517230C183C82CULL, 0x9A6DC1BE1A712B94ULL, 0xAA8E7F07EE3E495BULL, 0x0AC1F24D61169020ULL, 
            0x33936ECEF9E794F6ULL, 0x86485E67CAC32F66ULL, 0xAFF9C15EECE5F8E0ULL, 0xB25AF1B5F1D65394ULL, 
            0xAB44ACDECA6B1969ULL, 0x9DB98F3362E36C33ULL, 0xC5210DCD9F0B91D2ULL, 0xF03043EF716D1ED3ULL
        },
        {
            0x3BABAEC8767DC461ULL, 0xE9467F0213CA12A0ULL, 0x6CE160495902EB59ULL, 0xCA1322B8A671972EULL, 
            0x794D137F59B93097ULL, 0x2E6B8F23C8D9D7B1ULL, 0x335D3092DA4C6679ULL, 0xB1D47766DAE724BDULL, 
            0xEE32151BFCDCB461ULL, 0x3E83A3BFD9DC25F7ULL, 0x64D76AF5560A684EULL, 0xC810D2F9AB41489CULL, 
            0x5FB504FA65CBA1D2ULL, 0x648D20823406672CULL, 0x07D3010877694B30ULL, 0x37070FF21FC6D29BULL, 
            0x63A13B6AC1719CDEULL, 0x725D7D1AF867970BULL, 0x2F7D5D6BACB8A6A1ULL, 0x687249E9421BC444ULL, 
            0x40CE09E2E72A24ABULL, 0x71A293A2F9E66F2DULL, 0xA936194D5715DEADULL, 0x417F036F5DBCDD4CULL, 
            0x50B9AF71174AF0D2ULL, 0xD94D74AFCCA1F024ULL, 0xBF248A3A5A8E19B3ULL, 0x221080426F0842C3ULL, 
            0x9FFDD8F59AAEEAFCULL, 0xCB9023ECA562360CULL, 0x14C67CC2502E8E74ULL, 0xBE006927AC006FAAULL
        },
        {
            0x0F276DAA3F1BBC0DULL, 0xE9DB6B90F637D23DULL, 0x1C5F17A4AF55AFEEULL, 0x0429D12B0A33FBE6ULL, 
            0x0AC2B45AF96AC049ULL, 0x4487BA113B6455D2ULL, 0xA9EA829C3E0EA93CULL, 0xC213B9F54AE72E96ULL, 
            0xA9CB3FFC2EB321E5ULL, 0x253D10A9C392C853ULL, 0x03FEA4F6A80BD69FULL, 0xF0127FFD20339714ULL, 
            0x13E761AFA8D4D910ULL, 0x1A0D96BEA7447EACULL, 0xA6CF986658D4CCB4ULL, 0xF8BE258B555FC049ULL, 
            0x972EC405D61D80CDULL, 0x35A7A508013EBA0EULL, 0x7DAFB6759A805F0CULL, 0x9398F227E474B961ULL, 
            0xD9283831D6EB580EULL, 0x3C41E30A515A875BULL, 0xBE21BB88A76FA0C8ULL, 0xDAE69840F1A6EA04ULL, 
            0x12EBD37D19C3B128ULL, 0x82697C4C1394EDC8ULL, 0x0712F9A358640832ULL, 0x0CFA4F5615DA7DC3ULL, 
            0x52666596D2BF4CCAULL, 0x7C77519C8D089025ULL, 0x005E09F182AD889FULL, 0x2CB9F7F14DEDD817ULL
        },
        {
            0x950C02FB0187EB8CULL, 0x0BEC47E7DA4A8C5EULL, 0x033D8B69D139E3D3ULL, 0xD38B631FD055BD21ULL, 
            0x94775DA4705C45C3ULL, 0xF363DF2295E222B9ULL, 0x2770ABFA65F66D45ULL, 0x01021A3003D10501ULL, 
            0x9F2D9D721C7AA38BULL, 0x1FC68B206B97FA88ULL, 0x7C2778E938F88154ULL, 0x91EE5D9AFF25C4F0ULL, 
            0x62BFF301E090D903ULL, 0x439AD6CCE1579838ULL, 0x98C622D84DCECD2AULL, 0x047A9C59E3BCFE8FULL, 
            0xDD3A0CA5AF2E34B9ULL, 0xC54CACE9ED6FE2E7ULL, 0x26E2827CF7C47DA0ULL, 0x7C184B4B61EB5381ULL, 
            0x1B43CDEF2F84DE51ULL, 0x13C4E70FBB0881FDULL, 0x624AE58C3114DDBBULL, 0x5505BD0B03CE4405ULL, 
            0x1D9DBD3EBE598B19ULL, 0xFB32C26264F0105BULL, 0xEF7CB7913C5AED76ULL, 0xB252CF652D25668EULL, 
            0x43337976F64AB5A1ULL, 0x9EA8A84AE15EFBB7ULL, 0x485E2DFC86BEA9B5ULL, 0x43608B643A1C7088ULL
        },
        {
            0x6360347FEA430DA5ULL, 0xB046980D9CFB436CULL, 0x91E58BF7382B4B34ULL, 0x8B5A89DA35551811ULL, 
            0x5A5B2D520C963DE0ULL, 0x0628650F1D6B19BCULL, 0xC45237450A0D7A36ULL, 0x4C7BA5D3A6DABA08ULL, 
            0x65741676B6703E20ULL, 0xF444D2C2D8A1159DULL, 0xAFA8D4E8A6390E1CULL, 0x5944344682C7344FULL, 
            0x45A1B7FCE5088990ULL, 0x382D590948B2EF94ULL, 0x8FD9879894101D96ULL, 0xDE5C830FA0B5B425ULL, 
            0xF09D0148F6D3D11CULL, 0x0D45F5A6022132BCULL, 0x57EA01274CBD884DULL, 0x6F43D43383C58D71ULL, 
            0x98A8FA8A988FD314ULL, 0x9791E831F7A775EDULL, 0x056D39E050FAE501ULL, 0x9329FD2270D66EB2ULL, 
            0x1D4AEF0877B6F86FULL, 0xA7EAEDF38A6CA1C7ULL, 0xCDC502EE61AF28C1ULL, 0xA270D4619298AD75ULL, 
            0x4428B26C0DE64184ULL, 0x39BD5C831AB58842ULL, 0x8B6195890070834DULL, 0x4D335C80761894F1ULL
        },
        {
            0xF90E202467C270CAULL, 0x566D3C8CD68C2500ULL, 0x81355651CF61C8FEULL, 0x6BDC4C7CA08B3AB9ULL, 
            0x6195E1D325761777ULL, 0xE2498D74BCD92E4AULL, 0xE044ACDF382D156AULL, 0x55B5A5DC3161F223ULL, 
            0x3D8FCA7EA3B7A919ULL, 0x50A9B3A8980B966DULL, 0x0DF69E345D66C2ADULL, 0xE965CABFE0138C08ULL, 
            0xAA99C4B9D6F51614ULL, 0x2E0780E3BDA28E5FULL, 0xFB3CF95E3C5C5DFEULL, 0x500511877868D6A4ULL, 
            0x9A2988C33453143BULL, 0x7920B0861FFB8B04ULL, 0x7D29BEB06C6EB60FULL, 0xBE3E3AA3E78BB3B6ULL, 
            0x3E066A41E7293D11ULL, 0x1C52EE0362CB7F43ULL, 0xB848A4D455199921ULL, 0xD7972526371FB80CULL, 
            0xC1787969AB3569FBULL, 0xF003F7D0288A7F10ULL, 0x95394B97A57D92D4ULL, 0x9BD77D9ACAF8951DULL, 
            0xD0E2EBCCEC6FF740ULL, 0x4963794CEF756EA8ULL, 0xE126F769B7C1C596ULL, 0x21CAB4E186D52003ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseEConstants = {
    0x06ADFD1A32D0D9D4ULL,
    0x755CF8E8305CE253ULL,
    0x0B0D95A2E8ECCAA7ULL,
    0x06ADFD1A32D0D9D4ULL,
    0x755CF8E8305CE253ULL,
    0x0B0D95A2E8ECCAA7ULL,
    0xDB9690167D7E4EF3ULL,
    0x9651C5A994C12576ULL,
    0x14,
    0xD7,
    0xA2,
    0x6F,
    0x7E,
    0x70,
    0xF8,
    0xBC
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseFSalts = {
    {
        {
            0xE13971E04E3B6C79ULL, 0x86B3F0E4615ADA78ULL, 0xBF81BE0001441F8CULL, 0x8E5AF4C397769E00ULL, 
            0x05200710DD0007BFULL, 0x3013EF994B474E1EULL, 0xD91E835B502DFADBULL, 0xC523EB8FBDD8B88DULL, 
            0x01128432325063EFULL, 0x0838290BDB692A09ULL, 0x349DA4DBD1722881ULL, 0x485BB13BA1F3AADBULL, 
            0x0CA50C9DE57D4B6EULL, 0x170E4B1A504EB5F2ULL, 0x02CEC7B4A329A1F2ULL, 0x4CF5519335D68B0EULL, 
            0xC22A01F01404BD3EULL, 0x3C43A52B1CAAB671ULL, 0xBA5193E5933AAFD5ULL, 0xDB57B2A2C8F4D838ULL, 
            0x7F2D5DE944CC7C1FULL, 0xBE158FB639798102ULL, 0x22D0A45599D34D9FULL, 0x3C17FAE294AF88BCULL, 
            0x4AF370A283B2787AULL, 0xDD292892F22BB8DBULL, 0xAF57C4824652EA2BULL, 0xF00B8710930EE1AAULL, 
            0x49EE66D5267F70DEULL, 0x4FA87D78A7ADE0A7ULL, 0xF5E5C08D0881E1A8ULL, 0xCFC106873D54D0FCULL
        },
        {
            0xC62BFE5E6BCD5896ULL, 0x69B3D0DE1753EBCEULL, 0xA5D26012C485BADCULL, 0xF4C07B418CA29B3CULL, 
            0x7C34FAF89585C3E9ULL, 0x17D7B41D4C407CE0ULL, 0x927745320E79FF50ULL, 0x33A845E5A880557BULL, 
            0x1C41BA4EFBCD203BULL, 0x5EB77ED6C7D4B588ULL, 0x5E77C6695969A905ULL, 0x368154E5E4D981A5ULL, 
            0xAF2EA60B8722853AULL, 0x2B9CB8DFC4319123ULL, 0x7F4C92149026889FULL, 0x2B5461700999AB65ULL, 
            0x5EE2A2CF9212D2C4ULL, 0x1BFFDC4F1B85FED3ULL, 0xD2AE9CAB0B26DB32ULL, 0xF1C5DA69498599E0ULL, 
            0x45C213D9CCB2CF8CULL, 0x6704E42A14EA4663ULL, 0xDC781A277E007992ULL, 0x4D5E3A8322D9249DULL, 
            0x79ED0D2E29FBF5A5ULL, 0x3076F69A2F7BA368ULL, 0x8E05ABBCFC94DBD5ULL, 0x3461697D4BCC767AULL, 
            0x4AAC9A12BEAF2CF7ULL, 0x8BF0176CEA251C84ULL, 0x867A1D16535F39F7ULL, 0x22BE9F3497798F19ULL
        },
        {
            0x33F937059A25F128ULL, 0xAF1870D38170F841ULL, 0x6875FFAD1AE1A922ULL, 0x4333A71229AAC040ULL, 
            0x0F4E1120247B27A6ULL, 0x152DB2C9E9FF05BBULL, 0xE626A797290E786BULL, 0x2A33B539252FD818ULL, 
            0xD348EE7603D61453ULL, 0x64783A422C36EAF7ULL, 0x9181C70AABD8BD2EULL, 0x935B9A05EA280F5CULL, 
            0xDCF151704A6FD5A6ULL, 0xF7D5B0963EE8F4CCULL, 0xF479E4ECF7D06ED0ULL, 0xC992AB43BE363C0FULL, 
            0x85285BEA157AD572ULL, 0xDC7E0102CB129DBFULL, 0x8DFFF6CA8FD0F85CULL, 0x903A8ADF9565F699ULL, 
            0x0AF07B8C42FE5055ULL, 0x1D512904AB9B255FULL, 0x3BFF850A9E102728ULL, 0x19AAC3785279487FULL, 
            0x335935FB4CD7C361ULL, 0x3DE506E44282E5B1ULL, 0xDE61272F584D6FCEULL, 0x6B57CF0553074540ULL, 
            0xBBE5AD6D65F77813ULL, 0xB957320991DACC39ULL, 0x8110A7A698E1409CULL, 0xA4F840AC0FC70851ULL
        },
        {
            0xB1C6B5AFC53F56DBULL, 0xA9993D644FD4B110ULL, 0x59B919666C76F919ULL, 0xD1B9F518F037E4A9ULL, 
            0x91A45B15F517161DULL, 0x315BBEDBB747A443ULL, 0x8D6D411560E353CBULL, 0x6CF199934D3B16DAULL, 
            0xBE66315749E0DEBBULL, 0xB03C4A873EC49B77ULL, 0xE24B34F0F4001BBBULL, 0xDD62EBB9DCFEF508ULL, 
            0xAD7A8F7FF1096A27ULL, 0xD417F0475EAA31EBULL, 0x5B568B8CB71348AFULL, 0xD1528FDFEC155D3FULL, 
            0x40EE16FB00CB14D7ULL, 0xA43DC62A99ED016BULL, 0x70EF5CB42545EC1EULL, 0x243AB493553EDAD1ULL, 
            0x5DDA6F8835563959ULL, 0xC218701C55280978ULL, 0x14E63811E25FB986ULL, 0xB082736EEDA8E137ULL, 
            0x8E00DDA7E685C9ADULL, 0x3E01F0F8B7CB69BAULL, 0xE83BA8F9736646ECULL, 0x68614AA001D243A5ULL, 
            0x7C41687994336D58ULL, 0x0708861DC49AF42EULL, 0xCAD1A50C9638F008ULL, 0xB9E656E269CCDBACULL
        },
        {
            0x7B0FD99FDC245341ULL, 0xC3C1C700C4206080ULL, 0xC6F4AA5B070A10F8ULL, 0x99A323FA5955D80EULL, 
            0x87322FB43B98CF36ULL, 0x8FB92BC35AE74C11ULL, 0xB223E5038D04FDF6ULL, 0x58AE317A30C5F6D0ULL, 
            0x62DD51AE04986F10ULL, 0x98F7953A49A426B4ULL, 0xBBEEC5059B0E88A9ULL, 0x0B95159DB7927F33ULL, 
            0xDE3B133DD6764453ULL, 0x7F142CCFC5ABA074ULL, 0xA7B2267FA5891100ULL, 0x58DD19F45F0D7C5BULL, 
            0x8BA0FBE382334E23ULL, 0x44210F3207B14071ULL, 0x03F894C69A100003ULL, 0xD392A07A7B403572ULL, 
            0xE20989B5B190FD6FULL, 0x761FCABD48C1D0A1ULL, 0x3A40FBB439327392ULL, 0x89A7D95C2D0322ADULL, 
            0x0D76FF5F2C2752B3ULL, 0x64AEA5C5B712592AULL, 0xC0E999ECAB2B4293ULL, 0x97227FD9398605B2ULL, 
            0x55DD038A50E33506ULL, 0x95AFF128434E294CULL, 0x73F8DB2385CE7B4EULL, 0xF0FA7C6BE57B1700ULL
        },
        {
            0xFD8896150405F82EULL, 0x24E253A84FEC58DCULL, 0xA21FF68D203C112BULL, 0x4521AF8657A1ED7DULL, 
            0xBE6AB81067D89E93ULL, 0x574A6A9054C94AD2ULL, 0xC8FC4EE485F62136ULL, 0x8DD9437BF7179DE0ULL, 
            0x43351F4E8797562FULL, 0x861E86FA514B4F0FULL, 0x2252576FA52D2ADFULL, 0x41B62EE6E36CFEF7ULL, 
            0xEF86FFC7B5FF66FCULL, 0x0A3CF6A4EC8BA2CAULL, 0xED527284F2B8E0A0ULL, 0xA0DA1BE6F31A9F8AULL, 
            0xAF2674B19C9398BBULL, 0x7959C40280C8CA55ULL, 0xE374EA5255E1E7FFULL, 0x2BFA33335BD47DDAULL, 
            0xD5F439895F1CF903ULL, 0xD9F64E49589E1D9EULL, 0x02F5DBF14171ECEAULL, 0x14D4AE3E9EB6E282ULL, 
            0x244EEB6FBF4711C6ULL, 0x2F164BBC99C54E74ULL, 0x32982A11A7746FFBULL, 0x5BCB58B6B451C07AULL, 
            0x3976F2F281AD78DEULL, 0x84325EC6E0C0E5B6ULL, 0x7879BD8265E2D43CULL, 0x54CD35AEDD9F2950ULL
        }
    },
    {
        {
            0xA6D1C86F0457CB48ULL, 0x79FA938E0F009A8EULL, 0x971015F2F9EC80BDULL, 0x41B13168C910F65DULL, 
            0x66328C65C90DE2CEULL, 0x7C51360F6C4A8865ULL, 0x68BFB0E11B02373FULL, 0x3CFAEE85F49DE407ULL, 
            0x7AA02417F5A955B2ULL, 0xF550DF5A041AD841ULL, 0x77E2F1B1C839E4B1ULL, 0x816ADC616C80464CULL, 
            0x98FE5F9F526BAD13ULL, 0x1CA0AA554452D365ULL, 0x5680BAA6A99FC5AAULL, 0xFD9B3791DF091F51ULL, 
            0xC2A0CBFB958F08D1ULL, 0xEC36EBB7E201AA9DULL, 0x3D1B7569BB950859ULL, 0x057B0E7A503E28B6ULL, 
            0x977B288657D2451AULL, 0xB76FCF82C0ADD88DULL, 0x26231A09FE847850ULL, 0x711BDBE34A65FB76ULL, 
            0x5C48CD9B4DB85845ULL, 0xC9E3D471814FB961ULL, 0x8BFAEE1AA35861A9ULL, 0xB9B5D99F471D5054ULL, 
            0xA73184262953B6ACULL, 0xDD30A88F06BF7627ULL, 0xDD3CC576C9A9964DULL, 0x8182842A7B90BF64ULL
        },
        {
            0xB0322C840F96ACBDULL, 0xC68E65E92D282EEDULL, 0x5E37BADF8EFBCA23ULL, 0xF0089A2F0942A854ULL, 
            0x83778103980B8749ULL, 0xDE8D765472A6F922ULL, 0x019BADEC07781314ULL, 0xF7ECFA0CED406B1FULL, 
            0x411CFD08C0E53DE5ULL, 0x32723C2C8AA68050ULL, 0x9E5DA2FECDE0BC3BULL, 0xA59783A8408A62B8ULL, 
            0x07A6DF86FB7770B3ULL, 0xCAEB6A4A22EDF1EBULL, 0xB94078CA7216D041ULL, 0x5BFB82BB0783CA40ULL, 
            0x6F19D5A8C7214EFFULL, 0x7C267DE0D2251D4DULL, 0xD0C00A7CE30CD0A6ULL, 0x2A21497F0C784197ULL, 
            0x8C3C44FC052DA052ULL, 0x1A6FE7B4309C892AULL, 0x2372C5608324C28CULL, 0xDDA65442B8DAC66AULL, 
            0xB7ACDA2F05457E79ULL, 0xCC16492A431AB278ULL, 0x5F4349D248F7C162ULL, 0x9B0BCB09CB603DD6ULL, 
            0xB85890177C614564ULL, 0xCC6524F40464102CULL, 0x163CC3F4FCF4237AULL, 0x0C3EC59AB61BC2F8ULL
        },
        {
            0x87249400E85C4359ULL, 0x9C2CC2787D54EDF8ULL, 0x2F6D7FAF6087ADBCULL, 0xA9F73E3B8267E10AULL, 
            0xF2E70D34DBA2B39EULL, 0x3709340231B272BFULL, 0x2EC595F015C47EE7ULL, 0xF0ED40A069E95318ULL, 
            0xC7DCB0CA4271BC82ULL, 0xF55E43001171D733ULL, 0x1DC7C8B2A7D49266ULL, 0x737B93AE68B9ED1DULL, 
            0xB998EB1CCD192007ULL, 0x9B44D4241D4D6F57ULL, 0x217CAEBF19F7F4FFULL, 0xED4C69E2838348F1ULL, 
            0x50904984B477CB2CULL, 0x5A8682D80C25C0BDULL, 0x6BB7A15864426FF0ULL, 0x6DE45E34219F81EDULL, 
            0xF7298B48F5BD4241ULL, 0x2E7FDAE689417C33ULL, 0x7A7170F6063827F0ULL, 0xE1EB81DF88EC0061ULL, 
            0x70678E2A00B3C983ULL, 0x3DFC8689E8567770ULL, 0x3D857DF6D339FA3BULL, 0x46F3C11C716DD7ECULL, 
            0xF1F80EFE2D092024ULL, 0x2BE3642153A1CA9AULL, 0xF85668BA5D9213F5ULL, 0xA401993636879FE9ULL
        },
        {
            0x35CBB2E70A998C26ULL, 0xA09815C03926162DULL, 0xBD970917C06E68FBULL, 0xC3C01217A733D336ULL, 
            0x865F641AD9D77852ULL, 0x4A4E0356ACDCEF60ULL, 0x6ADEDE8E3B46C425ULL, 0xA277A02BD0195077ULL, 
            0x8E0E8E5B23B40881ULL, 0x5693B697C26A4A3DULL, 0x049BA9F6558AF2B0ULL, 0xA466E15C2B654FB7ULL, 
            0x03476D0BCF12D333ULL, 0x244FE4885CAA9AF0ULL, 0xD4B8CFEDBE471A08ULL, 0x3A9205107C52746BULL, 
            0xC544FF46710C24FEULL, 0x4A89D219637B7116ULL, 0x0ADAE4F9EE9E43CEULL, 0xCA76EECCBB60DA7DULL, 
            0x3604439FE73CB2F4ULL, 0x6D33AE441A4E3B48ULL, 0xBD66E675FC7BE9FFULL, 0x6F2BFFBC722662F0ULL, 
            0x9AC8A563C36DBC9FULL, 0xAEF8A0756CCD0207ULL, 0x0888B65186DD86AEULL, 0x9A408BFCAC774845ULL, 
            0xE70085A50BBDB554ULL, 0x231496414B6C5BE0ULL, 0x9C09583580C9ED7AULL, 0xA52ED155446199ABULL
        },
        {
            0xD0C9A8BBBBCA98E9ULL, 0xA239DBEF62B75F22ULL, 0x22C6F0DFC75D599EULL, 0x9636D000A13A9CEFULL, 
            0x6122E5DB41CCD6E7ULL, 0xB5B843F15A967E62ULL, 0x36F74E75ED3CAFF7ULL, 0x092192B652FEA185ULL, 
            0xA051CA4EE0F8CAFEULL, 0x340C21F797E42103ULL, 0x03A6EC29DC417A2DULL, 0x16395F2FA777EA2BULL, 
            0xF09C93AA39215EA5ULL, 0xAF7D25351587FE6CULL, 0xB0297A838AB1194EULL, 0x46A488EF9CA3C152ULL, 
            0xE2EBF89B9218257FULL, 0x22ACEBD28F69FE8AULL, 0x82082CAB9125FB0CULL, 0x2833C9947E56C3FAULL, 
            0xC642D400BFB62985ULL, 0x55F0312C9E688693ULL, 0xE1AD96CDD5DAD517ULL, 0x68639EC7BAEC8090ULL, 
            0x1C58311DE10CFE87ULL, 0x31233F80870AF76BULL, 0xC5C4FB60CE43A232ULL, 0x08FC0A612341B733ULL, 
            0x51841851B98C20A5ULL, 0xBA36E913BFFE3753ULL, 0x6D7979BAFA4028C6ULL, 0x240E56A52841E433ULL
        },
        {
            0xF6A7D29702935D09ULL, 0x267984702696C678ULL, 0xB736C6DCA650C204ULL, 0x800450F5A0C6C4FCULL, 
            0x90011AD291F55490ULL, 0x382176779C58BA40ULL, 0x69163B5ED3CCC47EULL, 0x8FC0D1E2BB630E5BULL, 
            0x1AC188BC3ED34777ULL, 0x5BD455833721483CULL, 0xE81E81255536B10CULL, 0x33BE53F2F4A00CADULL, 
            0x6E3AD0EE0048AE1AULL, 0x3347C8BD2417557AULL, 0x2B65252D5B75BD82ULL, 0xCC3BC2CAEB4705DFULL, 
            0x03C325ED9BD03E8AULL, 0x5D0F7454021FEF94ULL, 0x6B8070DE4EF393CFULL, 0x9D5979551FC8C819ULL, 
            0xCE53BF13FB12B798ULL, 0xEB2B16A2104D9DCEULL, 0x4F45D3044A2BA0C8ULL, 0x857543A889C89468ULL, 
            0x40742314721DE0C0ULL, 0xA76951DC5633BDFDULL, 0xEDCB129F130F1545ULL, 0xA46575B7C5047848ULL, 
            0x44EBCF049236F857ULL, 0x12D7194C95BD5087ULL, 0x665AA7C7304AA91BULL, 0xF0FF49ED783AD659ULL
        }
    },
    {
        {
            0x275B6A3BB3C7C9EFULL, 0x51D15DBFA83BCF63ULL, 0xD7470F5F78BDBBF3ULL, 0xB4C52B2AAF282E04ULL, 
            0xACF58E3986CD019AULL, 0x15A84B5E4542E275ULL, 0x3B7B713B3369297EULL, 0x8E76FBFC1544BA1CULL, 
            0x4B9376E6AC5A9D54ULL, 0x21DD29EDE236FFACULL, 0xAE9C87E66C03787AULL, 0xF6F05F8406143F97ULL, 
            0xDCFD32653BCF5EFFULL, 0xB83AD8D25BB133B3ULL, 0x4411E95A7EC400B1ULL, 0xA239C684DC009818ULL, 
            0xE351246ABED3555EULL, 0x136B7D2BB43A8147ULL, 0x2946359B8759EAB1ULL, 0x30527874445F40A6ULL, 
            0x3A7C166669122D5BULL, 0xDF3424F0FF6A91BFULL, 0xE13E77BBB97C63F4ULL, 0xE3E1E6029D954EE9ULL, 
            0xBF935D7AE0DBCF69ULL, 0xF58A8C8F3EA353B3ULL, 0x09766CD93794A0CDULL, 0x837D58D578FCAFE7ULL, 
            0x568177719E8D98F2ULL, 0x11F5E477C633D1A2ULL, 0x3AB47557DB126604ULL, 0x40F71DC95C2BF3A4ULL
        },
        {
            0xD09020E7E3AAD6F1ULL, 0x8B292EFE61541415ULL, 0x02DB6F63E689262DULL, 0xF0239D919C76547BULL, 
            0x54E1AD97CAA8A8C8ULL, 0xD82C926A21E14A5AULL, 0xDB3372235E3F6F4FULL, 0x3C45BCF24AEF4193ULL, 
            0x672D1D522E90C827ULL, 0x104297CE910A4DA7ULL, 0x2970A09CADD1BEC6ULL, 0x20D5A93C1F9C1FA2ULL, 
            0x6A6C6FD9084D829BULL, 0x15B1C86A2EDEB869ULL, 0x8660E246DF2EE812ULL, 0x8460272894E2A38CULL, 
            0x32C8459862B0133FULL, 0x1AE181F833DAC763ULL, 0x2554EAAEB384FCFAULL, 0xF5EA1A601BD26412ULL, 
            0x4FAB6A1C6FA24F17ULL, 0x6B7B9ABF80FC9F72ULL, 0x96AB2CF7D686432FULL, 0x937E227A0BDFE82CULL, 
            0x7C06BF02DCCEB5CFULL, 0x0182826DAD42E1D8ULL, 0x5AB1E65FD2164C4DULL, 0x0E2474160ED50C4AULL, 
            0x03D3ABBA4B086C31ULL, 0x87782BDD64E190D9ULL, 0x0A54B251F5B89954ULL, 0x1DB6FAA931D0CC27ULL
        },
        {
            0x65C9DEAFA34638ADULL, 0xFFF60FD7DDA54862ULL, 0xDF1E171D7A8B5BABULL, 0xB55D108D4990C8B9ULL, 
            0x4658DB340BCBD95BULL, 0x8870B203B1522B36ULL, 0xB0F084121E23CAD1ULL, 0xE31EC3F4714CB46AULL, 
            0x1383CB67FCD3327CULL, 0x3670DA7804FDDBA5ULL, 0x429EEE91C53CE493ULL, 0x84FD514D0068DDACULL, 
            0x5269B484564A68A7ULL, 0x7E4C2DB508A086A4ULL, 0xBA95FF4DEA7CA398ULL, 0xF3AC8E4DF25C5812ULL, 
            0xC3AE263773FAA92EULL, 0xA52FACFE6420E78BULL, 0xC394836E97F669B7ULL, 0x597158DF8C2154F4ULL, 
            0xF0EA588F26BABA62ULL, 0x468C936C475E40A8ULL, 0x2A85AD50620993E1ULL, 0xABB6AC1BE0D6A209ULL, 
            0x7D726AB4BF612E45ULL, 0xE2B2D19AACA36232ULL, 0xF5553B0C5EFA353BULL, 0x46204CC8D4849BDCULL, 
            0x95CD43366F41AC87ULL, 0x78D14BD4B0CDACB1ULL, 0xAD2ADD325BE95471ULL, 0x112B0BF7DE4AE908ULL
        },
        {
            0x47A54E7508DBA98DULL, 0xCD53574CF0DDD574ULL, 0x75545580B554460FULL, 0x33D52C232B7D6BE2ULL, 
            0x693A1BB11C1FDE3AULL, 0xBD74826317E4FF45ULL, 0x3554F3FFA13ED4E0ULL, 0x7106EC246CB8E554ULL, 
            0xCD2503FF10158E8FULL, 0xC7DDE4F3E796CBD4ULL, 0xE788ECB6FC1F2C7AULL, 0x10F433E53864D053ULL, 
            0x6465148FE3128B9DULL, 0xD0D495E6CF6A5A68ULL, 0x9707BF975F54A261ULL, 0x800C32C094792601ULL, 
            0x7D74629C2967C361ULL, 0xE39AB0ED1F09AFE0ULL, 0x5C3CEC7267B0C426ULL, 0x70C1EBA0C52D86E4ULL, 
            0xB57E70498708B5AFULL, 0x959F2D677B1FBC40ULL, 0xD1E19F75E4A66CE0ULL, 0x5B6BB278FDB2B6D5ULL, 
            0x8D95987BAAC0FA5AULL, 0xFC751D735C67C4DEULL, 0x91237D22D6EEAFBEULL, 0x6197CA4D0D9D3CA0ULL, 
            0x543AE7D66C950576ULL, 0x70731C35284843BCULL, 0x234DBF6AE6C3329AULL, 0x67230BE18B2DBB51ULL
        },
        {
            0x2498F28B6C43C101ULL, 0x0AA8B700E370ABD5ULL, 0x96E91458FBF3DDF4ULL, 0x146B4E06F5F178BAULL, 
            0xBCF8F96CEA157581ULL, 0x4617863111312733ULL, 0x4836D19FC291B870ULL, 0x9A1600ABFD6DE010ULL, 
            0x6387869B2534BF3FULL, 0x5139E509C984E18FULL, 0xA3FA4CE3E7AB07EEULL, 0xD9C87F42A12ACCD0ULL, 
            0x71ECD3DBE1A05AE1ULL, 0xF0AC444D2C5D8C43ULL, 0xEF8D203377AFD347ULL, 0x2658946CD0B9F17EULL, 
            0x690D2DAC52FBBCABULL, 0x46A0FBD9F0F740C3ULL, 0xF91DE17C7D38F8B1ULL, 0x9E2A9B726CACFF7EULL, 
            0x640D39ED56F516BAULL, 0xF1591D87A36C86FDULL, 0xA12BF6FA8BB27193ULL, 0x35BB998645EB168DULL, 
            0xCBB646244D2C7884ULL, 0x0995F0DEF457DC9AULL, 0x261877690AE9BB1CULL, 0xE0D443B6B9EA7EB4ULL, 
            0x5C86C99E1A63801AULL, 0x33787D679BBF96DBULL, 0xC3A1C76F14304E4CULL, 0x4016A806E4C74D65ULL
        },
        {
            0x87D6E21361D5F327ULL, 0xBCF75B3399500726ULL, 0x317C4194C2BCCF05ULL, 0x8BA2C937962F75CAULL, 
            0xC3459A79C69DB7E0ULL, 0x2F71233337F5DF0FULL, 0x1705666E3EE0C072ULL, 0x706FF305D5EF42F8ULL, 
            0xE8FDFA1A0B165208ULL, 0x6D5DDD36B1FFF1C9ULL, 0x8BD4F801D4D6100FULL, 0xB10C34D1DF2E6125ULL, 
            0xE76F9216F14F858DULL, 0x7EF22797F3ADC524ULL, 0xA45678033510D39CULL, 0x7797CC302FDBAE7CULL, 
            0x527168F4F5746656ULL, 0x0BA47A4BB5EB4B92ULL, 0xE38E99883D44720EULL, 0x4BDFAB7579EC3FBAULL, 
            0x5F71FA52944B7C58ULL, 0xE29207E8D0089BF7ULL, 0x3559880A5233D35DULL, 0xFEE1699DF2E10697ULL, 
            0xAAAC0656019F53C5ULL, 0x9D9B11EF17CB9376ULL, 0xBA2A4B82A394713AULL, 0x6DE13E514D19109CULL, 
            0x9427706B5C5313DBULL, 0x772D090F385BB4BFULL, 0x281329D2EC4E2E87ULL, 0x74B205867A240627ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseFConstants = {
    0x0AA21CC2A7374A0BULL,
    0xF935A98959668CB7ULL,
    0xEDB8A07C5F189283ULL,
    0x0AA21CC2A7374A0BULL,
    0xF935A98959668CB7ULL,
    0xEDB8A07C5F189283ULL,
    0xFA7F4265A74B5061ULL,
    0x85D5AAF75143717CULL,
    0xC8,
    0xDC,
    0x3C,
    0xEC,
    0x10,
    0x7B,
    0x4A,
    0xF6
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseGSalts = {
    {
        {
            0x409DDDE46A0EA5C3ULL, 0x482D46D4128D9C74ULL, 0xCD39057195E47986ULL, 0xEC2FA1C93C2CC211ULL, 
            0x3F6A532012D6BC5CULL, 0x7331EF10B7184410ULL, 0x462FDC40E7CE947DULL, 0x1070DF952ED85A9BULL, 
            0x525664038CAA0132ULL, 0x3E68723DCC94A070ULL, 0x463BAADFE637C1E9ULL, 0xC9E7BC7046EC919CULL, 
            0x2CECC78ABE2CACB0ULL, 0x742D42DE507650EBULL, 0x5ECB6EE186E926F4ULL, 0xC9CEBEEC925156E2ULL, 
            0x4AA87CE226954CAEULL, 0x2AC810CF116D0612ULL, 0x154BCF1DA64EBFAFULL, 0xBEA76FA5D1F2A449ULL, 
            0xD178C38D2DFF988EULL, 0x3D1FE630C4BBE80AULL, 0x337887D932673A2EULL, 0x94A26D8BD3BF8177ULL, 
            0xCDCC565511B04D19ULL, 0xC424A6E242B59CF2ULL, 0x68D63527208B557EULL, 0xD43A6E3F1C879413ULL, 
            0xD77E2C67D759ECB2ULL, 0x24D604A76B736C6AULL, 0x95D6F170AD72CBFFULL, 0xBC5FF6D9ADD4A5ACULL
        },
        {
            0x5F5D294E5218C655ULL, 0x7BACA44835617046ULL, 0x96A471D5EE2CFCF9ULL, 0xC5E40639476F2EC5ULL, 
            0x582A5DC43AB9BDD9ULL, 0x4212575274943DC7ULL, 0xDB2A651465DE49E8ULL, 0xAD4D21A9CED36DF4ULL, 
            0xD6214ECAA7983A2DULL, 0x2FA43B27C6489F6CULL, 0x65DF7080E9055F46ULL, 0x474C252350D19CEAULL, 
            0xBDE05120A9D4B387ULL, 0xC2A488159CF6B4D1ULL, 0xD2FD456F816B6C7AULL, 0x7A85526491D648ACULL, 
            0x1397C478AAED30F0ULL, 0x2351BD4DE8A19BBCULL, 0xC0541760B59DA592ULL, 0xED91171203BE5252ULL, 
            0x6CD61C9090B390CAULL, 0x12F0CD98698FC2A8ULL, 0x25CBCD18B2635DDFULL, 0x11A27A423D2572CBULL, 
            0x2FFF4D17305D4FE3ULL, 0xC63385CC41675683ULL, 0x9FF86D75309B369EULL, 0x87661901E1D73332ULL, 
            0x3E7EF7D23C27139DULL, 0x60EBCB8B03CE5639ULL, 0x4B4EB4752B7ED338ULL, 0x03A524A3B073C5C0ULL
        },
        {
            0x07CA8F75B9BB3EFDULL, 0xAFEBAE58967A925FULL, 0x272F5FE5A58B8F7BULL, 0x1B86CC17D4FB8263ULL, 
            0x6AC400A11426C398ULL, 0x54A804E85BAA98A9ULL, 0x26C7F2829747AC7EULL, 0x5E54A5416477941AULL, 
            0x492A31D4362DE6F9ULL, 0xD0AC89670300094FULL, 0x78C0E029B51F727CULL, 0x8DCBF302B644F7A1ULL, 
            0x392A7B7F866A0DDCULL, 0x04F1C59EDAAC79A0ULL, 0x15CC825FA7767CD7ULL, 0x4920F5B6DFD7A136ULL, 
            0x6147BC7D917A711DULL, 0x7558199D3C3AB55BULL, 0xDD6BFF5551B5B3B0ULL, 0x4E69BE1A081BD9EFULL, 
            0xBBB6B5749E065F14ULL, 0xAA0AD82F33BC0E30ULL, 0x913460163498EBA8ULL, 0xC623F54804BE31A3ULL, 
            0xC60AF2BDB6B532D8ULL, 0x18524E37A92DA615ULL, 0x89AE83E12E0E4C31ULL, 0xFD80BA31CD7F9F44ULL, 
            0xB8C5DBCCBCB8444CULL, 0x84A77909FF652357ULL, 0x6DEFACF836827FB3ULL, 0x58DE8E8C6A694F4AULL
        },
        {
            0x117D8AF59B894E0AULL, 0x0475560E0C390C6AULL, 0x6AD6F6C437703AA9ULL, 0x71F222CB76942689ULL, 
            0x5DE0C8FDDECB56F5ULL, 0x01FEF64CAA4A1C41ULL, 0x1A18B4FF73754438ULL, 0xA6D7C8032CB3A190ULL, 
            0x7209DB3A7C4CE44BULL, 0xC3499246603B9B8BULL, 0x85967D54D51B3F87ULL, 0x7A83FE7C139963A0ULL, 
            0x4DD6B3D04FE1628AULL, 0xBABFBFCBF446E312ULL, 0xB5A788BD84CFF6DEULL, 0x07A2709F1D7006C1ULL, 
            0x45B20859FE9FF03AULL, 0x0016CC20903F3488ULL, 0xD00FEDE747C5ADF9ULL, 0x590B51371F0A660DULL, 
            0xCF77AE5632D0D2B6ULL, 0x1AFB343E668C8A8BULL, 0x4A9F27AECD7CF4EDULL, 0xB6D7A8651EA736FDULL, 
            0x37A86489A1266A70ULL, 0x35C650F73937995AULL, 0x36C0599FB8EDBF8FULL, 0x49472F19F26ADE52ULL, 
            0xD2185FB7F91820D7ULL, 0xD7591F8AE440763BULL, 0xD457D638237DBDAFULL, 0x12BDFB088E1AEF45ULL
        },
        {
            0x8895BBC751C700EFULL, 0x132AC309E74BF1B1ULL, 0x06AAAEEE9EBB04B1ULL, 0xA8B1BD1F8CFA1CE9ULL, 
            0xFEF885D9405F6159ULL, 0xFD34F77063B908A5ULL, 0xDB634B8CD0901C60ULL, 0xE290A45C66A156D5ULL, 
            0xD2C6371CB9A57029ULL, 0x7BF971DDC87A2225ULL, 0x026237FC4630E121ULL, 0x32F9CD153C20B48CULL, 
            0xCD7E3B8FA1DF8E09ULL, 0x8E4DF9F1CF0B9710ULL, 0x0A6441594A5F4B2BULL, 0x684673ACE4E74FFEULL, 
            0xE54801C8313A2C04ULL, 0x58EB367FD82C22EFULL, 0x18B6C0011E524F51ULL, 0x63853464C1059230ULL, 
            0xE9145B6642D0E5A6ULL, 0xD522BB45F7558AF4ULL, 0x57F06603561A567CULL, 0xF0F5FDDB7DE07E62ULL, 
            0x0D2FC07F7EB8BE01ULL, 0x370D1407212F8E55ULL, 0xA5B4AE33AF5B1CFDULL, 0xEF51467B0562C9F7ULL, 
            0xC0280D625E18BBC8ULL, 0xAF840941D60CF9A6ULL, 0x3F2FB5D497FAD1A2ULL, 0xF5B2E1218B240175ULL
        },
        {
            0x4ADEE75317DA9C10ULL, 0xCCD5227ABFACE364ULL, 0xE8F6BBFCAC207550ULL, 0x3DCB90FE6B4DDA1FULL, 
            0x5F272D9EE546372CULL, 0x45562D7320002AD6ULL, 0x90B1082081278A28ULL, 0xF7BDD970C0FFE58EULL, 
            0xB24813DABF43D774ULL, 0x5B9B0187408FC3F8ULL, 0x3172B3460C06405AULL, 0x8755D817308D90ACULL, 
            0x573D90FC010877AAULL, 0x8DCC7B14CC6FAF1AULL, 0x36E923F4F18689AEULL, 0xF84972C5E658878DULL, 
            0x5F99E3252A00793DULL, 0xC3E88F0710F9AA9CULL, 0x8E46A427A22EDDBEULL, 0x06A0073E15B83B6BULL, 
            0x03994E203FB9144FULL, 0xEAE4C9DEBC9FBE01ULL, 0x2223BF364DC741B0ULL, 0x184C652045692595ULL, 
            0x883DF2E114B466A9ULL, 0x0984B6ECAEF983AAULL, 0xB3550FCCB9010976ULL, 0xD299ED6E4CA77BDBULL, 
            0x4D454198349F1894ULL, 0x27AC134B50244A06ULL, 0x193016F814E60F1FULL, 0x27D43CFAE450C6D1ULL
        }
    },
    {
        {
            0xAE742BF258021875ULL, 0xB7A17BDE59EEBDFCULL, 0xAED36B063D053003ULL, 0x43708B9097E83D80ULL, 
            0x0675CA9039359B97ULL, 0xE65F9A730E684B83ULL, 0x35BD6C0B3274C30AULL, 0x081D02317179B15DULL, 
            0x8A80BE6E03D1E445ULL, 0x8BD90BAD51252EC1ULL, 0xE5DDAC55D082D315ULL, 0xA78D0E0A43B3639EULL, 
            0x800C5DA249A265C0ULL, 0x4299614E3E268EEEULL, 0x7FEB297FD078A01CULL, 0xBAE34B45ABE6E75EULL, 
            0x1DD46F80EE30A38BULL, 0xEC74F0635D780687ULL, 0xB34233D250AFC4D6ULL, 0xDA92C0EA66D457EDULL, 
            0x938A4B259DAE574BULL, 0x8E9FD3DAD7A953B5ULL, 0xDF45B24D61E2AE5FULL, 0x0C01910F26F895A8ULL, 
            0x47A8DDB540896E83ULL, 0x277189474EE4AE69ULL, 0xC725AB38CB546684ULL, 0xCF72182F7B31D29DULL, 
            0xE970A852B89246ADULL, 0x7573097FC9A4C72EULL, 0x47E914C60955EBBCULL, 0x72085EB316664D87ULL
        },
        {
            0xC30BC19B0EFC6BF8ULL, 0x4592B7BF78B83078ULL, 0x59608E778811166FULL, 0x38D02C2586A93019ULL, 
            0x9B8272CF756F12B1ULL, 0xD95F90A811425CFBULL, 0xB43A2865416EBF1FULL, 0xA5CD3433D073C976ULL, 
            0xFF40BF38127A3C58ULL, 0x19BAAFC831CE7FCEULL, 0x2C3CD0DC66618E78ULL, 0x856D780E98F92935ULL, 
            0x9DAA4A667B8A444CULL, 0xFB3B8E8F66FF69D1ULL, 0x1FB3CE146E315456ULL, 0x7372C976BE48C770ULL, 
            0x93A1637C27E7D1F0ULL, 0x497689FC81616C54ULL, 0xB74C56FD83ADD54CULL, 0x55BCD80A0A25BB0DULL, 
            0x905CC2A9ECBB6816ULL, 0xBFA266239474C6CBULL, 0x6D2C33928B59C77DULL, 0x5B9D347EA6ACA97BULL, 
            0x1FE4500978BF3328ULL, 0x80E5A52FDCA95570ULL, 0xC9DB4E4B1B1904E5ULL, 0x62E215F5C4FEC7FCULL, 
            0x300EDED1BAB326ACULL, 0x3EFBC46370793758ULL, 0x8EC50B20ADA77FF8ULL, 0x505F60C559466423ULL
        },
        {
            0x9F5DA2F3BF655153ULL, 0x145E4A761BC62CFEULL, 0xDD6D51710FC8DB34ULL, 0x87BAC0E99ECC439DULL, 
            0xD4E957B5212DF757ULL, 0x68C3018A66E765A9ULL, 0x5865A819C135F4DEULL, 0x8D76086F60E07D02ULL, 
            0x0E8A289D94CA2BCBULL, 0x40EDC5D8BE661E72ULL, 0xCE87B9C6F05486C3ULL, 0xCC6CF44BB01B7535ULL, 
            0xA570FB7F74104628ULL, 0xC32805B686374268ULL, 0xDD2F6CACEB309A0EULL, 0xC8BEF456864808AAULL, 
            0x08D142CDCF20A0D9ULL, 0xDEA48C63A841B063ULL, 0xD551E1935516823BULL, 0xCAED394A5E7FD6E4ULL, 
            0xC34BD064AA302285ULL, 0xD439BAB11EAAE093ULL, 0x5D54E3EA25F2FBEEULL, 0xD5273019712B05DEULL, 
            0x3CBEEC1E3925AD23ULL, 0xA82AAB5157ABBE59ULL, 0x62AB5887F126ECA2ULL, 0x4FD1E2888224125AULL, 
            0x39F040534EA8E96AULL, 0xF2C4EA0DC7A562A7ULL, 0xF78C0E6658E91ED6ULL, 0xD9C11D20810C1CA3ULL
        },
        {
            0x744841DB1D4B37AAULL, 0x902DE0D395F0135FULL, 0xEBF7E5AB7B3E09AAULL, 0x66EE66F7AD9B5B48ULL, 
            0xC07C43D8440614BEULL, 0x96880714B7E58915ULL, 0x6013D64794263B56ULL, 0xCF4323F9FAD47D3AULL, 
            0x977E845C37A13451ULL, 0x873F8590182082D9ULL, 0x37807A9B645F2941ULL, 0xA4A869C07EF0AE56ULL, 
            0x3AFA60DEBBCE6C58ULL, 0xD80305816A9C1B9DULL, 0x3BA719DBB2236ADCULL, 0x5E4FAEB2A972C8BBULL, 
            0x109759C3485EC8DFULL, 0xB38B9A55E1146790ULL, 0xE9A852CA0E890AC8ULL, 0xD7622D10FEAA7CE9ULL, 
            0x7579CB69ED744DFBULL, 0x022517B856C9D246ULL, 0x8ACCE1D624E7291BULL, 0x3B50FEABD0537DADULL, 
            0x827FA0253EE7FBB8ULL, 0xFE64900E8D736CC2ULL, 0x68265CD28D796849ULL, 0x2A6AEE3C0671AEC2ULL, 
            0x2CA2D63FD4B0048FULL, 0xDD0FB693F4A663FAULL, 0x7A55C8C66C68E562ULL, 0xB9C8A7F476BFB1D0ULL
        },
        {
            0x905ADB3E36CE27D1ULL, 0xD5CEFBEC5E043C3CULL, 0x12BB9BB41B3C9F05ULL, 0xF5E4F2510C1136E9ULL, 
            0xD91F9994008035B3ULL, 0xD4223D03B8F60E6DULL, 0xBFD7F41C641271EBULL, 0x2D7831EA20727776ULL, 
            0x6F904DE99DE23C4DULL, 0x38E2A3F595512896ULL, 0x0D46EAD5FAEF1770ULL, 0xA21A226E615768F6ULL, 
            0xC3EBBCF285B70221ULL, 0x2BD1F25D08A322E6ULL, 0xB8589759193C4108ULL, 0xC934008D7315087DULL, 
            0x082462369C661655ULL, 0x2CC2A9A8C041543EULL, 0x5FCFB8AC3FD09AD8ULL, 0x2FB82B153E9C3AAAULL, 
            0x5DB6DD338B67186FULL, 0xE5FF85FD6F9D1A4CULL, 0x433F6B4624E577D9ULL, 0x839467CF7B71F706ULL, 
            0x98349A1F4D4AF028ULL, 0xB1F6766E8B4D15E7ULL, 0x6660EE28699AF445ULL, 0x18EE7B883104A53EULL, 
            0xFCFAD857665A838DULL, 0xF7F503216D331E7DULL, 0x6606B48CF0979C13ULL, 0x70B900B50A2CD436ULL
        },
        {
            0xF0BADCF1BD8FE61BULL, 0xB3E2F85BF3FC066AULL, 0xEF66BABF9E637AC9ULL, 0x500C8DEE9416EB65ULL, 
            0x18F5D8A39C6C946DULL, 0x76BD4F29B57E437CULL, 0x50A57DE917D8C815ULL, 0xD5685275133D7675ULL, 
            0xEBF24818C3EDD20EULL, 0xB689446394DED36DULL, 0x4D9A3DB8DB4F067CULL, 0xDB72C65DF238752AULL, 
            0xF85EEFA73321CA33ULL, 0xED594F1BC8B76AA6ULL, 0x0B6ABB398BBF7D4FULL, 0x7B91395D7FF55E3CULL, 
            0x441A5C0CC80C287CULL, 0x76195924052030A2ULL, 0xC54CBE5215D5F7F1ULL, 0x0CF55D695210D719ULL, 
            0xA212A6F0C5C2CF1BULL, 0x65C0F2016D90FBA7ULL, 0x0A3B9145B14BE38AULL, 0x3601F93D8F77BA0EULL, 
            0xD7F78A216774FE08ULL, 0xFBC194044B01D246ULL, 0xE91A79A29B1C5FB2ULL, 0xE938F17F6212B62CULL, 
            0x587A7B60A4D75CDCULL, 0x48D5C36453B4AC63ULL, 0x5520337EC704E63DULL, 0x182FAD0591F38F8EULL
        }
    },
    {
        {
            0xD31EB7062685787AULL, 0x0BAADEBC89C6F1CBULL, 0x26303EBB38856AD4ULL, 0x67D0F67D85A569DDULL, 
            0xAB07FF9CA63AFB53ULL, 0x71BB2C8DD9851294ULL, 0x9EA99A01672AE848ULL, 0x46A9E52F2F3609D3ULL, 
            0x1D7E174BAF61AD83ULL, 0x6010B9732E171944ULL, 0x847E5310D4D205F4ULL, 0xCF4791CC81A2ADB5ULL, 
            0xC92145167BCAD362ULL, 0xA35180865756CC49ULL, 0xD2DE53D9C2CA9676ULL, 0xC0D1B29735815475ULL, 
            0x593CD88DBD003196ULL, 0xC8AA52473EE13B64ULL, 0x7DE69530DA84B162ULL, 0xD55F806F1C0FBF2DULL, 
            0x1154F44A6E7F68C4ULL, 0xE0EF29EFFEB92D41ULL, 0xE37D152F8139C4C6ULL, 0xC13509CC61375FCCULL, 
            0x32E8C46AFA9B2830ULL, 0x838E6609589AC6BFULL, 0x168BAB871C34325BULL, 0x1F706E5BD4B68EBAULL, 
            0x641809ACCF8B6993ULL, 0xA1FB8DD5E8ED7BC5ULL, 0xB71F3BB8C31936B8ULL, 0xEDA124C85D448D2DULL
        },
        {
            0x78D6560A8F4B46E5ULL, 0x6BC9B72E3D5E7050ULL, 0x8569510F638F2CC5ULL, 0xDCE8EED23B34BDC4ULL, 
            0x5B08D4CF7EAD4038ULL, 0xA19B4DED5BD5F131ULL, 0x7D0A53E544F5C9F4ULL, 0x296850159693ECA9ULL, 
            0x9A91C76BEC2E6CE8ULL, 0x928CA847790BF05DULL, 0xD41A0A4001D60210ULL, 0x92A09BB864D1CA8FULL, 
            0x3D5C1DE4E9C9616CULL, 0x942E76D4773086ECULL, 0x0076BE98E7226ECDULL, 0x9139FAD5515407FAULL, 
            0x9439B4EFA15FC017ULL, 0x7386460B510665D7ULL, 0xD5C734B71078C47BULL, 0xD46E92841358B442ULL, 
            0xC4B556AE26591E91ULL, 0x465BE0DC9C432C1FULL, 0x47FAA2D8E5D008BBULL, 0x8CB30B85CCB4BE86ULL, 
            0x4CD6673D9B3A2487ULL, 0xB337E425A8316962ULL, 0x045DED0D77FA9656ULL, 0x84D2304FE9C3FD89ULL, 
            0x45EB43A695A91682ULL, 0x77D7D58F908736DAULL, 0x87B46BB92070BB54ULL, 0x31A8450450CBC071ULL
        },
        {
            0x2E3576E9DDC3C2F6ULL, 0xECD4D4A717C1202CULL, 0xA3DC607C14A1EFFFULL, 0xF06477F3D40A3DE6ULL, 
            0x6CCC8BEDB97F1A8BULL, 0xDE00584C2B33F862ULL, 0xC8CFA39DD68C0BA5ULL, 0x897A7DDFA133F0BCULL, 
            0x2C36AE41008B698AULL, 0x71AF089D8208A52EULL, 0xDADCE2A82AC22BD7ULL, 0x5E0FE96583B85C29ULL, 
            0xC2410846DF6E5509ULL, 0xD9851D9029046855ULL, 0x4F3FC08928504D88ULL, 0xE2063F65D70486A4ULL, 
            0xD216D293D825B0D5ULL, 0xD866F80A2B97C29FULL, 0x98A439E2CA889278ULL, 0x26DEB2A0D6A9B85CULL, 
            0x23131C14F961A696ULL, 0x7B42B52D49EA0D95ULL, 0xE4309863A008D7FEULL, 0x05B970CB6A491AF4ULL, 
            0x207E419B1423A045ULL, 0x5B6B3FCE0711E980ULL, 0x61F64CCDE7C84E9BULL, 0x9B15A6B1F7F42501ULL, 
            0x6DAAC27A1B5718E2ULL, 0xFBF5DA2C5EAA1BEAULL, 0x5BCF869A67DA2A68ULL, 0xFEA5E6E35140A96CULL
        },
        {
            0x2FBA58860607DEB4ULL, 0xE7EE425F58D5A055ULL, 0xF28080734244AB8AULL, 0x27C303ED126AEFE5ULL, 
            0xEBDB26FC340772F4ULL, 0xECD9358D57AE32B1ULL, 0x1C216C76A9F89106ULL, 0x3EDC173F7A371B2AULL, 
            0x5F6924A5A8E18FC6ULL, 0x6E81909A368CC121ULL, 0x72361218FB11AE08ULL, 0xE784905BC25FF0DDULL, 
            0x84FC030DA680FC61ULL, 0x0430526B14075A66ULL, 0x3EE6DDA12ABC0BEFULL, 0xBEBE6F8EE93A22F5ULL, 
            0xE3F0DDB96F973011ULL, 0x4F28D517326D36D5ULL, 0x7120DF6FDBD7A9A1ULL, 0x55BD4F426C021403ULL, 
            0x11BC90000E72235BULL, 0x66E78FE411413339ULL, 0xEC32F2D1AEC3E5EFULL, 0xD6FE6051D06323ECULL, 
            0x1BAB96C2292FB08AULL, 0x3B639F5C2709A834ULL, 0x3672142B00E5661DULL, 0x33B34DDF4BFEB627ULL, 
            0x9DF29695C65355D8ULL, 0xF40E9B1B57F88EEDULL, 0x0387848A7B24D5A3ULL, 0x0DE0C62993F9E03BULL
        },
        {
            0x3D0B518F5A331E48ULL, 0x1698AC17B248D59AULL, 0x72979DC3F144366CULL, 0x8534B3544A937877ULL, 
            0x148EAECBCE523F77ULL, 0x89D551C4F60FF2B3ULL, 0xD5BE2EF1D6949C02ULL, 0xF7B23E3B00B88824ULL, 
            0x792BD4E3DD90E7A8ULL, 0x3DBE5FE2CE05400DULL, 0x3DFFE7A98F914AD8ULL, 0x6A080F65F2E578B2ULL, 
            0xDA732FC6F86272F0ULL, 0xF11A8D95A4D8D9A4ULL, 0x9E8A2A04985F0C42ULL, 0xC2689F1AA29E52F8ULL, 
            0xD85822898595B946ULL, 0x2BD48B6379B0284AULL, 0x1E7D95D90DE714E0ULL, 0x67431812525D4ADDULL, 
            0x8C93AF7B2B786779ULL, 0x9EA3EB7E4A3B83B2ULL, 0x1164A4DA49603AC0ULL, 0x26CACC2ABDAC995DULL, 
            0x73E1183D8D83E5C6ULL, 0xC79115543839497FULL, 0x5DBB0EF5DAF14DA2ULL, 0xA83AF6A0AC3A842CULL, 
            0x3386BE97FBDEE181ULL, 0xF9F4F93AEFE46D70ULL, 0xC0B07DED128B11A8ULL, 0x9F7E2142CA6F8AD4ULL
        },
        {
            0x7A95C3EC22C836B5ULL, 0xE04214BDA3E00652ULL, 0x0EC7C14026046F24ULL, 0xA0F047721DE4EDF0ULL, 
            0x1A6C050D1FFC0440ULL, 0x8A3BB799AD29BA16ULL, 0x37C9097AB9F29714ULL, 0x9DE35413B3EB93B5ULL, 
            0x55C06C0630B95F7BULL, 0xBCC87D6205588C33ULL, 0x748A774641737292ULL, 0x324E9516B3F0CFA7ULL, 
            0x18BA5D9B1A7A5433ULL, 0x13C5904A9BAE81B6ULL, 0x7ED2E6B6FF3AB39AULL, 0x977657381B8494D3ULL, 
            0x7D3778455156CCFDULL, 0x216CA830CA94D272ULL, 0x0949B35CC0835D96ULL, 0xBB3533515A203E1EULL, 
            0x751B3D5D60AEDDBAULL, 0x10A2CB770A8722D6ULL, 0xBCA60CB340C466CDULL, 0x2866619871E079B2ULL, 
            0x6D3042F32E1FFA10ULL, 0x4B19639C2DB88ACEULL, 0xF11A7535019CE630ULL, 0x2A23FFC297AC3527ULL, 
            0xB5F01A2CA8B032B6ULL, 0x928B44D56E0A8D75ULL, 0xF9F20E8338B6C844ULL, 0x2C60E6E56F3D8FACULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseGConstants = {
    0x925F7F4D52BE8B08ULL,
    0x72D73E482AA67392ULL,
    0xC26AEB936C092943ULL,
    0x925F7F4D52BE8B08ULL,
    0x72D73E482AA67392ULL,
    0xC26AEB936C092943ULL,
    0xEB35D050EE0ABF4DULL,
    0x88495953CFAFF576ULL,
    0xDC,
    0xC0,
    0x4C,
    0x65,
    0x56,
    0xA1,
    0xB8,
    0xD7
};

const TwistDomainSaltSet TwistExpander_PingPong::kPhaseHSalts = {
    {
        {
            0x72177F20E6B9C78FULL, 0x9D26379BCF979C0EULL, 0x94A54F3E9D441DAFULL, 0x6B8FB9DC677EE849ULL, 
            0xD72E193BA7B461EBULL, 0x9CB56D18DC543B5EULL, 0x3245ACB95EDBCD1FULL, 0xD68B2505EC8D5A0AULL, 
            0x1C02B14D72DE335BULL, 0xB4765009E8BB7394ULL, 0x04F8CCD157D6C3D2ULL, 0x9D3A0DB3CE92702BULL, 
            0xFBA8ED9F2AB33BF1ULL, 0x0791176DBD486FBAULL, 0x9F95924487B2EFAFULL, 0xCEB917B319C415F2ULL, 
            0xDD9993487E42B97CULL, 0x61E83E88FA100351ULL, 0xBC98EEFD25559C56ULL, 0xAE7D20B2E547EBBAULL, 
            0x8C90D31130D0CA5BULL, 0x6360936D9AE53B1AULL, 0xFD66F588B7D3956DULL, 0xB09787E952E93569ULL, 
            0xAC4DE0F5AE64BD21ULL, 0x9AC29FF2CFBB8813ULL, 0xBA4256B143C576A6ULL, 0x97D7F9695676A439ULL, 
            0xB3C49E379633502FULL, 0x6C8E49B2C79B5F2AULL, 0x7386316C78873CCBULL, 0xD311BC2F87D41B55ULL
        },
        {
            0xF55AF83DB6EC9894ULL, 0x0DDEBEADC4D6716BULL, 0xC59F60A7EC8FB953ULL, 0x89DFF8C5099E4E3BULL, 
            0x70A12A4045334AC4ULL, 0xFB5AF2C69562F6FBULL, 0x41E99B421C4BE26BULL, 0x459A530C59BB205FULL, 
            0xFBF31D95898063B7ULL, 0x4A06C02FC51C2E43ULL, 0x870BDB7CF1B917AEULL, 0xF28F68ED043E58A6ULL, 
            0xD366DF77354FB11EULL, 0xDF49A2BEB1819F1CULL, 0xEB7C21AD1AA24B52ULL, 0x427A64D8BBB09EE6ULL, 
            0x7B31B0FF46E67672ULL, 0x245F3C4411CEC83DULL, 0xB259BACF50C382C4ULL, 0x8CDD800715A114EAULL, 
            0xCACDFAE2F62BDCBBULL, 0x1ACAF7F16262831DULL, 0x72BDE91D8A41380EULL, 0xA831EDD4EE10B2C7ULL, 
            0x9718C63ADB072CF1ULL, 0xF116AB9160C0DEBFULL, 0xD6FDEABDA17FDB3BULL, 0xA546448455C13A89ULL, 
            0x9EABDB9CF47BFBECULL, 0xE0D878B105C32135ULL, 0x50D08145970DB532ULL, 0x88CDE3BD9F4C4881ULL
        },
        {
            0x21862C2C98A10B2CULL, 0x0277268AD8362B12ULL, 0x638602DB009F812FULL, 0xE4A6273AD067988BULL, 
            0x13085338154C481BULL, 0x6FA4A03F3B991928ULL, 0x12F7CCC5B783AC7BULL, 0x5B32786F35FE76C8ULL, 
            0x3F6BA43B786EDF4DULL, 0xA9D396AE3D71D991ULL, 0xD3FF9429866E4045ULL, 0xE7AB68BF392F541BULL, 
            0x42F3B6EBEE674264ULL, 0x59CD52BBF4376DD1ULL, 0x3F62698E761BBA11ULL, 0xC086000328123AAFULL, 
            0x85026EBFE2D89468ULL, 0x369E0F481FB7C25EULL, 0x561726A5A6654096ULL, 0x6AB38162535F3516ULL, 
            0x3388801CB737A335ULL, 0xF6BEE1933C47E658ULL, 0x0A5F373D3A6B5F64ULL, 0xEBF2AEF2F3AEBFF4ULL, 
            0x76E86813E959D6C1ULL, 0x4F337423D528C8B7ULL, 0x793C09489DCD4509ULL, 0x7C6813D7113D9A8EULL, 
            0xA9B936732D882B26ULL, 0x4DECF7C2B5DF138CULL, 0x99C91981677A7CCBULL, 0xF7186F05CEFAFFABULL
        },
        {
            0xAF2E507EF7782581ULL, 0x310F2E33CC52BAD0ULL, 0x61800EE4AE807629ULL, 0x8C06AC8817B5768CULL, 
            0x5E7A7BC439BC7843ULL, 0xF83278C6C96663B3ULL, 0xF0196120D4F0A572ULL, 0x664CD47745C01921ULL, 
            0x4CC7E4211ABC84F9ULL, 0x5E32A6811728B5B4ULL, 0x4C97D3D17021F859ULL, 0x24104283095E3F65ULL, 
            0xE4EE61FF0BC9DEE7ULL, 0x94F863A9B62C2203ULL, 0xE05E4F775408C851ULL, 0x38EE5B9B3143A65CULL, 
            0x2530C83C0B52236BULL, 0x4F105AEAC45050E2ULL, 0x45BFF24BBD8B933DULL, 0xB59F55545FC6F7FDULL, 
            0x4085D86E39C0CE83ULL, 0xFBEA6C8C8A9B1135ULL, 0x54BDC10DEDC18357ULL, 0x8060FD8EB2269080ULL, 
            0xB6C2601D71482912ULL, 0xDB6D89C2CC534991ULL, 0x2EEC691F8F1C4659ULL, 0x4E702E037732BDE2ULL, 
            0x7934356CF47920C8ULL, 0x371AE155AEF30FECULL, 0xFC3AED92C02E316CULL, 0xAFDA4AE3469805A4ULL
        },
        {
            0xA159E957B8138659ULL, 0xC9A8C74E22E1F585ULL, 0x415C067CEBEE5186ULL, 0x539F723D7C891180ULL, 
            0x7583435F854846C7ULL, 0x3F16A918111C5690ULL, 0xDF2D6F4AEC944293ULL, 0xAD647CC725F756B1ULL, 
            0x62470FAFC731F903ULL, 0xE335799D8EC1936CULL, 0xA42F9A6170BBD96DULL, 0xFE5CE4FC455AC569ULL, 
            0xC6228955F2650EFDULL, 0xC048EF4FCCEF89EDULL, 0x9E56CCCD98BAAF99ULL, 0xE7C4361112722697ULL, 
            0xF8F654FBEEE0AFB9ULL, 0x82B21D15F0E7FD1DULL, 0xF7CFFDDE296AFCC2ULL, 0xF54F734B33DE0BE0ULL, 
            0x60478D8381B36F5FULL, 0xBF046A7AC7420B35ULL, 0x16CB7ED3E006F3B6ULL, 0x9F9E904DF731F0FCULL, 
            0x2E5054F61D4857C8ULL, 0xCDB79DB71593ACFBULL, 0x88F60C6FE151B0F9ULL, 0x6F6B3F68DE2AEA29ULL, 
            0x3349700C35755E74ULL, 0x36D3E5D929E51692ULL, 0x96E067E723C93785ULL, 0xCD8698E6C5351675ULL
        },
        {
            0x9400299CD106AC44ULL, 0x5D585EE1CDB83055ULL, 0x8783482F934192FBULL, 0x495BC4BE56DA20BDULL, 
            0xDEDE37D6965E1353ULL, 0x50B79D4A25759A51ULL, 0x081B7144CAB33028ULL, 0x5CA0785F58F21379ULL, 
            0xBF4FEF86E9CAB01BULL, 0xBCDD477FE3557954ULL, 0xB6A32D78B7EE363FULL, 0x21952235C47C514CULL, 
            0xB52D2787D0372111ULL, 0x94B0DB27645F771AULL, 0xA62131408ED81124ULL, 0x67DC00882A623788ULL, 
            0x6BCBA1DD7DFB6377ULL, 0xF8BC4EEF2D3C6975ULL, 0x815725089D0F7453ULL, 0xD1DB0FCE69EB8755ULL, 
            0x748FA70C0CC1D5D3ULL, 0x9BC1D94F5AF10EC1ULL, 0x53D772EC432D5B8DULL, 0x08B04A03DB44356BULL, 
            0x7A3F13672AD6C3D5ULL, 0x31063DB51BC1DF5DULL, 0x56CAC9FEC50F4A3BULL, 0x81392A99872C2116ULL, 
            0x5DF6E8E35436A438ULL, 0x6B127E14D83C3065ULL, 0x1B2BDECFD47FC55EULL, 0x3A65E8CE689C7C51ULL
        }
    },
    {
        {
            0x91DEF7466D15C280ULL, 0xCC5D2FE728942107ULL, 0xB474EBB963223D45ULL, 0x01AF6D4DFC786452ULL, 
            0x6019675603A1637EULL, 0x473A60F39B3E3E20ULL, 0xCDD581AF495C499CULL, 0xD695EB650A7D2BACULL, 
            0xF19609E6286CDD87ULL, 0xBEB1CE01A9FA22FAULL, 0xB4B70FE1D5A15404ULL, 0x193487C0222D0649ULL, 
            0x08BED1D3DD0E23B0ULL, 0x1EBC94F7F251E25EULL, 0x876757480E3A1BD2ULL, 0x7E2E03281082D713ULL, 
            0x1E4E99C4CDAAF490ULL, 0x0AA5B6369532D100ULL, 0x27B378F8F208E35BULL, 0x1E6B3388A4FFA84BULL, 
            0x7944152AA586F632ULL, 0x6B3DDC3DB82C79EEULL, 0x8BB4ED317B5BB91FULL, 0xFF8D49AD6446604FULL, 
            0x0F00F373A60ECC3AULL, 0x4D1C50EC085D14D1ULL, 0x802D7FBEFF43EFC3ULL, 0x2B0F246F72475F82ULL, 
            0xF5D03EB7E44C50E4ULL, 0x6C6440EE2C9785EEULL, 0xECB074215D764637ULL, 0x3AE6AFEA165AC0F6ULL
        },
        {
            0x51266C192F55636FULL, 0x906CB2D0A80F45ACULL, 0x157145E0DAB020DDULL, 0xBA7D6BF0A12F07F4ULL, 
            0xBA6F7EE519B3A7C2ULL, 0xF01DD679EC822AA9ULL, 0x877AE33050F3407FULL, 0xCD0D5D5D2A1B5AE2ULL, 
            0x7F20E661AF893E4EULL, 0x86FEDCF7E95E3F16ULL, 0x0B484E58BE6A6137ULL, 0xD1C034885F91F752ULL, 
            0x00325C8C47F20A1BULL, 0xC6F580E411D1CC78ULL, 0xE7694BD1CFB5C944ULL, 0x82462DCD0D202F76ULL, 
            0x28842F8BFBFF9F09ULL, 0x6FA869E26E382883ULL, 0xDFA28E9DD6B761FBULL, 0x776D0C0A6C56FA6FULL, 
            0x5979F26EBE19F22AULL, 0x6715D3261DA6002FULL, 0x7630084AE7DAF5A6ULL, 0x52D814BF466AE5AEULL, 
            0x00A3EF127FD5F812ULL, 0xBE1B00BAC6A2C433ULL, 0xBCDAE5424E4CE334ULL, 0x4198A95932BE8ED0ULL, 
            0x05B4D4F2A0B603E6ULL, 0x1F4334F957003075ULL, 0x3FD99F4632D9234AULL, 0x6B2056F4EA571632ULL
        },
        {
            0x9A0140BF57638B1FULL, 0x9D737A9E4A3D7D73ULL, 0xE156ADC4B9454B20ULL, 0x9514685A45EB8DC0ULL, 
            0xD8E8714C5652E848ULL, 0xED105323AD422250ULL, 0xFB8EEA0B174F09EEULL, 0x10847418DA10BF8DULL, 
            0x81CFB0E8F4E096B3ULL, 0x866362B223B1736BULL, 0xE32A58034D4F4D4FULL, 0x7B28424A3F169D75ULL, 
            0x8637D0AD04B34A4AULL, 0x8D4DECCB589532DDULL, 0x2E1F921C36D6E577ULL, 0x03C24A77E9640915ULL, 
            0x45362FB85A157140ULL, 0x27526993207DA422ULL, 0xE2F504C8BDD4DBDEULL, 0x64BE87AD0B8311DDULL, 
            0x614F1BE8A5B24BDEULL, 0xAF7293341B6575FEULL, 0xECD643EEC91B2D60ULL, 0xDB46D659601E0E7BULL, 
            0x0AB0C71940268F2DULL, 0xB1A1CE3A6FD365ABULL, 0x83289D7B90BF98B4ULL, 0x8FEF1634614E5ECEULL, 
            0x754652701A034887ULL, 0x76F98C5660963320ULL, 0x76029A435EDD5927ULL, 0x8AADF4B75B75453BULL
        },
        {
            0x35EDAAA894DC73BEULL, 0xB7B288C84597D365ULL, 0x578B0CDB95287267ULL, 0x85F0DF1106FA2DB0ULL, 
            0x90825AB3CEB689F3ULL, 0x5DA7127356952D96ULL, 0x02BA0BF02F391945ULL, 0x78EB28AD4CF75BC1ULL, 
            0x8199144C5D0167CDULL, 0x3E43ACF4225164ADULL, 0xE895D5F747F1F31BULL, 0x8852D2BAD4A03312ULL, 
            0x7A0F736E89FF92BFULL, 0x354966F65DDBFFBBULL, 0xC706C09B326234B9ULL, 0x28D3301C798261D4ULL, 
            0x7CC9FD8CBCD3AEADULL, 0x937A6B13476035A7ULL, 0x91F4B0D88D694443ULL, 0xA0FA9819BA63317DULL, 
            0x8C4B94CF8CAC6587ULL, 0xDC7598F038FC43C9ULL, 0xFB26824A525CBA69ULL, 0xBB87F7839AEB6E7FULL, 
            0x59CFCA2E86B1CC86ULL, 0x2077FA8F72756BF0ULL, 0xFF06FCA995E26FB3ULL, 0x9C97C478605EFE2FULL, 
            0xCF40B7E8DEB630B6ULL, 0xB2CF20E9A4DEC77FULL, 0xDAAA3D7A2706701EULL, 0x4E146FD9DA66593AULL
        },
        {
            0x09579849DEA74BC2ULL, 0xDAEDD1ECF239EC38ULL, 0x7A83378C3E2948BDULL, 0x3F731CB78BB7C760ULL, 
            0x81BC0F75824D0AC5ULL, 0xC4012017C5A9244AULL, 0x3F2C0F86A420D803ULL, 0xF4F6F6DC2E2BE51DULL, 
            0x49E0A63FA0E1F715ULL, 0x79C0836F58FC93EBULL, 0x6B2BFCD769D7B824ULL, 0x85C25A1B27B8BBE5ULL, 
            0x9FD0C92332529268ULL, 0x4377C918BB165A33ULL, 0x52C20B72A940B1AAULL, 0xA69701CBFB40F39CULL, 
            0xAD72FB2EC03B0A01ULL, 0x86825365316F4E96ULL, 0x56957666478B121EULL, 0xE206717B034D35A5ULL, 
            0x1520C657A2757192ULL, 0x2034E4AB5C5D9CF1ULL, 0x9720F60CEADA15F0ULL, 0x56153BAC2F2BEF5FULL, 
            0x971FCEC01D5BB475ULL, 0xC4169DAAEBE95346ULL, 0x0AF8F01C8794B315ULL, 0x982C121914C097DAULL, 
            0x34D97399B7C40383ULL, 0xDD896FC7B260D48FULL, 0x49C95F60AFD08145ULL, 0x31F920AA1A56120AULL
        },
        {
            0x627AC1D43035F21DULL, 0x10DC6711F0EE04EEULL, 0x13D743C986024B60ULL, 0x62E314A0061E9D8FULL, 
            0x2E232F7E9BF06491ULL, 0x7C25D4E203A3A643ULL, 0x615C9F0AD0BC8C59ULL, 0x3951049EF4564355ULL, 
            0xF152C5A95EB1A8D5ULL, 0x0222E8A91B86CCB2ULL, 0x1C40D3350DAF30A3ULL, 0xD53B6CB87FC14DE1ULL, 
            0x852D2D8A6FF18A69ULL, 0x495FEEF109E6D42CULL, 0xA9B74079C44070AEULL, 0x158E16A4520EA627ULL, 
            0x681363CB17A4A0A0ULL, 0x30A9EB1BA292978DULL, 0x6F83FADA4CE245ACULL, 0x69FDF20E34ED7E23ULL, 
            0x72E42A90126D2A70ULL, 0x0CD5A5B6E7896D6EULL, 0x1F166D2705081FA7ULL, 0x3EAE08C587265E36ULL, 
            0xBA915445B911B8E5ULL, 0x9CB9DA926051CF7BULL, 0xA526B1961C9AE568ULL, 0xE96AEB6B9E38D34FULL, 
            0x3B38982E8685E781ULL, 0x7253BEC46B8F3818ULL, 0x471F74D187CD65F8ULL, 0x99C3377E265ED307ULL
        }
    },
    {
        {
            0x497E2E45D95C60CFULL, 0x984CA11462DCA4CBULL, 0xF9A5DB805FF256F4ULL, 0x329D195A356B3C93ULL, 
            0x66D708A7DB3F2CDEULL, 0x1A0E29AC08506461ULL, 0x2E1AE1B8455AEF4FULL, 0x93F30A1411159BFBULL, 
            0x888D0C30F98ABB95ULL, 0xF6A8D72DAABB21A3ULL, 0x13C1B8E1255B252FULL, 0x429686BCD856E266ULL, 
            0x478B95498F17AA46ULL, 0x0B12C3175DF686E3ULL, 0x84A32C1A9EFDC7FCULL, 0x449E97228CEFAE32ULL, 
            0x5F8E96D5ADAC87B7ULL, 0xAE8709CDCBB483C6ULL, 0x629C24FD11910BDDULL, 0x628AF661FF0E8BC4ULL, 
            0xBC822A5F2816A18DULL, 0xE838591A378F28DEULL, 0x7E1CC4DCD6124CE6ULL, 0x4DADBA077B37FF6AULL, 
            0xEDC0ABC6A4FCAAB0ULL, 0xA4DAEB6DB5AEBA07ULL, 0x29A938EC7CB46B49ULL, 0x9B586FF816E1E120ULL, 
            0x6567501C098906FBULL, 0x4FF39192C0EDB10AULL, 0xD835E0DF1CF1A86CULL, 0x4E60C0CAFA169195ULL
        },
        {
            0x246F3DC9EA7EDB7BULL, 0xDFABF1F6543D5AF0ULL, 0x7A0948EE639A6BFAULL, 0x75EF30C85F42A78AULL, 
            0x71E5186FA1144261ULL, 0x339E5F682417CCD5ULL, 0x9A6EC2E32D34392EULL, 0x9F093E6073E4A1C9ULL, 
            0x06E96F7C73046C87ULL, 0x9BD39AA98B6EDE6AULL, 0x3688D285286E40CDULL, 0xD180EBC2BC80AB07ULL, 
            0x49C29F576CC4AA10ULL, 0x30DA4CA697535FD3ULL, 0xD08CCCBDB4FBEFDBULL, 0x1397CE8F0CF86D68ULL, 
            0xE1D9B2BEAE28B95BULL, 0x124A00E2FEBFEBBAULL, 0x2ECF79681CA9B255ULL, 0x1502CE647E020AFEULL, 
            0x3BD8EF2084456D98ULL, 0x0AB83338F6200AFBULL, 0x57CFD8B156B460C5ULL, 0x07CB5209F96644A6ULL, 
            0x786AA3963F584AE5ULL, 0xB512AE773561F694ULL, 0xF839AD68CD928516ULL, 0x59D8B5C25CE51355ULL, 
            0xA55B246D38BFA296ULL, 0x2F9A4D956954F86EULL, 0x7780E560D756B066ULL, 0x13398E4165F9636CULL
        },
        {
            0xA98E0BFFA3F05F26ULL, 0xD3B6F31FEF62D9CCULL, 0x7688E3F13BF2CF81ULL, 0x87333034C1907F00ULL, 
            0x858A23702FFF0422ULL, 0x0FBED7F03A9BF6F8ULL, 0xA3C7B17375C4F938ULL, 0x7977099BFEA73177ULL, 
            0x058D6D34D58AD684ULL, 0x7C9AA1874CC71DA7ULL, 0xAE06091E3D731C9FULL, 0x99A6C5218D9047E9ULL, 
            0x70BCCC30C4AF37BCULL, 0xADFF5A2CA7042345ULL, 0x3A5D14B1A0188C3EULL, 0x56A56A0411517D78ULL, 
            0xD6FE8EAEAB04EEFFULL, 0xE26356805B92FB49ULL, 0x2708D32518F66DB6ULL, 0x5AE45F8A6A737364ULL, 
            0xE66FA81069DD4090ULL, 0x7962F6AB374E784AULL, 0xED10F485AA7D55BEULL, 0x55D978F7C0F618F1ULL, 
            0xBBB90350079769F7ULL, 0xF18BDA9B715114B9ULL, 0xB55B7B329F7357E9ULL, 0x1FC954BC26FF919BULL, 
            0x57EC15EE6BD9AFAAULL, 0xBEEF85388D4CD9B5ULL, 0xA7E9F830C9955D83ULL, 0x2054E06C10D8543FULL
        },
        {
            0xC5B646789ACC1BDCULL, 0xC43AD08E69D97D48ULL, 0x0C768A864CAAA1E4ULL, 0xDB689B20880B9A74ULL, 
            0x53185664C1C9EEF8ULL, 0x5E1BC7A2E524234DULL, 0xF347FE9C82EF8D07ULL, 0x13241995CED2E09FULL, 
            0x7BC4CBE03367807CULL, 0x491D1D5CC2FBD5FAULL, 0x83CE8EC0113F0204ULL, 0x755820ED4EB6F1BBULL, 
            0xA682641B51DA384AULL, 0x0A4285490FA106D1ULL, 0xCDB5CCFB10BD58CCULL, 0x10A63723B54061DBULL, 
            0x50619F70907366F4ULL, 0x277780F169C4ACB8ULL, 0x120FE9D0E4A3411BULL, 0x4DB9988943B8BFA8ULL, 
            0x3F2AAA28B3CA2871ULL, 0xBF85F998A1F4E216ULL, 0x20AFB81A03F67C06ULL, 0x239CE00E12790EEBULL, 
            0xE1FB1602A8D63990ULL, 0x971B881B36D1C712ULL, 0x250982769607FDD4ULL, 0xE74E044EFE946F4BULL, 
            0xE0C7BD0DC07840CDULL, 0x891040942C0C943CULL, 0x1DCCFECC0D582123ULL, 0x058F40B22058C7C3ULL
        },
        {
            0x709813C078A7F214ULL, 0x46D9DC461042F80CULL, 0xCDA49A6ABD2E59E1ULL, 0xFA96DD02439B31D3ULL, 
            0xEEB12FC968625FDBULL, 0x0BC4F9A75BD21B78ULL, 0x7AD7059F1ADE2850ULL, 0x11071F49222B0E05ULL, 
            0x1E054A8823F67CE7ULL, 0x3C49CFA2CECEB7C7ULL, 0x46F4713AE36733D7ULL, 0xE634882CE3C6B79BULL, 
            0x8D8C32F612D2AE79ULL, 0xE11830023C105B5AULL, 0xBD5468147E45AAACULL, 0x63CA8BFA817E385EULL, 
            0x8EFEEC5A665CA7ADULL, 0x65313517126F5668ULL, 0x68EF294D79D02040ULL, 0x368277C4A804DD98ULL, 
            0x1CF86E7C7144421EULL, 0x4AFA6E1A6B2692C9ULL, 0xD65A3BE90162572BULL, 0x3831F8959C80E29BULL, 
            0x5EF743B7F58F47B8ULL, 0x5A26C2EB6EFB6D2CULL, 0x45A45D4A95B30A51ULL, 0x2A2D5D9611BC4B89ULL, 
            0x6062ED709494749BULL, 0x8F9EAF219B087AD4ULL, 0x79E724A2F56678E6ULL, 0x455738DDF04B7402ULL
        },
        {
            0x0A5B4BC3A048C30FULL, 0x55D854F174E3671CULL, 0x66648F9FFB385866ULL, 0xE1CD2C92C8024C6EULL, 
            0x2B04B1EECC478D24ULL, 0x6CEDECCA0D3CE0B8ULL, 0xAD027F1746D6BDFDULL, 0x65E570589FA70BB0ULL, 
            0x5970162C2620575DULL, 0xBBD3C9AB86C86A46ULL, 0x44E7953FC71C4FA1ULL, 0x84D295620B3CD32EULL, 
            0x2B036AA16761EFF1ULL, 0xA29ED5A213BDC7EEULL, 0xE76C491A1D09C020ULL, 0xCB2675CE75166145ULL, 
            0x613F473A2606714AULL, 0x2D8E4D90E4060070ULL, 0xAD012B2470491F63ULL, 0xD08A99B9B11EB941ULL, 
            0xC4CAB325025BE3F5ULL, 0xD7EBDDC317D1F49AULL, 0x40BD834F36B2A9E6ULL, 0x9452D5CF883A18CFULL, 
            0x1E36D3EBD335860FULL, 0x4B955E8872B05ED4ULL, 0x5C6E7268A16E101AULL, 0xC59B6A6B3D47310DULL, 
            0x035857F8D096F763ULL, 0x705AF82238857F1AULL, 0x345F24E021B7984BULL, 0x472616C1FD06D5BFULL
        }
    }
};

const TwistDomainConstants TwistExpander_PingPong::kPhaseHConstants = {
    0xAD3E4826A4F3D9E8ULL,
    0x71C3B9B6E0AF0541ULL,
    0x9BB4CFCE45308686ULL,
    0xAD3E4826A4F3D9E8ULL,
    0x71C3B9B6E0AF0541ULL,
    0x9BB4CFCE45308686ULL,
    0xFF525BE2F5491FA7ULL,
    0x1883A1E486D35F09ULL,
    0x02,
    0xF8,
    0x10,
    0xE5,
    0xAC,
    0x60,
    0x64,
    0xF4
};

