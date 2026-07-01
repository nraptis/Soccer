#include "TwistExpander_Boxing.hpp"
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

TwistExpander_Boxing::TwistExpander_Boxing()
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

void TwistExpander_Boxing::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xF3E12FA9370994F8ULL; std::uint64_t aIngress = 0xB6E5D0CEFFE53BCCULL; std::uint64_t aCarry = 0xBC200744A248D4D4ULL;

    std::uint64_t aWandererA = 0xA07703057222CD8DULL; std::uint64_t aWandererB = 0xA8C4D481DF1C9812ULL; std::uint64_t aWandererC = 0x807685AF630026F1ULL; std::uint64_t aWandererD = 0x9764548D891C8F00ULL;
    std::uint64_t aWandererE = 0xDD1D0648D1F52340ULL; std::uint64_t aWandererF = 0xD5315CBEB92AFC00ULL; std::uint64_t aWandererG = 0x881ED933CF260BCCULL; std::uint64_t aWandererH = 0xA9DD9790E7AF1432ULL;
    std::uint64_t aWandererI = 0x8E2F55CD128D41AFULL; std::uint64_t aWandererJ = 0xAACC8AD531D671E9ULL; std::uint64_t aWandererK = 0xE4C58F1159ADF261ULL;

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
        aPrevious = 15452394885928940426U;
        aCarry = 17256828124404519181U;
        aWandererA = 14172826104035902331U;
        aWandererB = 16505676177886673995U;
        aWandererC = 16957603588995514738U;
        aWandererD = 14972533310642937388U;
        aWandererE = 13726363088111007266U;
        aWandererF = 15190915398854970557U;
        aWandererG = 15657055388814756204U;
        aWandererH = 11896180337307069250U;
        aWandererI = 16847322679201185129U;
        aWandererJ = 14739439130010330679U;
        aWandererK = 17728753356033629038U;
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
    TwistExpander_Boxing_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Boxing::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB045E8B00A5739DFULL; std::uint64_t aIngress = 0xA2D7267648721ADAULL; std::uint64_t aCarry = 0xD7CFF1FF41D732ABULL;

    std::uint64_t aWandererA = 0x875C81833A53E562ULL; std::uint64_t aWandererB = 0xE04B73D8FA09E30EULL; std::uint64_t aWandererC = 0xE43BE7C92A5AD304ULL; std::uint64_t aWandererD = 0x9B11FEB2CCC87A64ULL;
    std::uint64_t aWandererE = 0x8A03784ED35A8549ULL; std::uint64_t aWandererF = 0xCCC4266711DC761CULL; std::uint64_t aWandererG = 0xBE95DC1AFA32ADB7ULL; std::uint64_t aWandererH = 0xCD765D1ADA663306ULL;
    std::uint64_t aWandererI = 0x85F11A0DB4FE40DFULL; std::uint64_t aWandererJ = 0xC057F33742573398ULL; std::uint64_t aWandererK = 0xAF149FB4D337BCE4ULL;

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
        aPrevious = 16098298097787220202U;
        aCarry = 13835381116047446872U;
        aWandererA = 14084209425785786169U;
        aWandererB = 13849815346271779124U;
        aWandererC = 9879597754329015743U;
        aWandererD = 16465284462766503190U;
        aWandererE = 16745913926258461009U;
        aWandererF = 9311031225596147246U;
        aWandererG = 17531705200289591366U;
        aWandererH = 14190556666556809618U;
        aWandererI = 14341829537676789149U;
        aWandererJ = 16287431203124466017U;
        aWandererK = 10308253103976108593U;
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
    TwistExpander_Boxing_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Boxing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF6816C052BC2C690ULL;
    std::uint64_t aIngress = 0xCCBE92199215F729ULL;
    std::uint64_t aCarry = 0xC74DE0A734AE9C0CULL;

    std::uint64_t aWandererA = 0x874D175ADFF91FAFULL;
    std::uint64_t aWandererB = 0xCAE03544F62A5048ULL;
    std::uint64_t aWandererC = 0xA77D2C69122755DBULL;
    std::uint64_t aWandererD = 0x945A42F8DA2CB91CULL;
    std::uint64_t aWandererE = 0xAE013910EC1D760FULL;
    std::uint64_t aWandererF = 0x8CB464ABCC65F849ULL;
    std::uint64_t aWandererG = 0x82FE0BF3B92DB435ULL;
    std::uint64_t aWandererH = 0xDDEFD3A38BFE1CBEULL;
    std::uint64_t aWandererI = 0xBDC6210CF5BD6201ULL;
    std::uint64_t aWandererJ = 0xBB5F2F05FD236323ULL;
    std::uint64_t aWandererK = 0xA73ED28CC9DF50A6ULL;

    // [seed]
        TwistSnow::Sha256Counter(aSource, aSnowLaneA);
        TwistSnow::AES256Counter(aSource, aSnowLaneB);
        TwistSnow::Aria256Counter(aSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    TwistExpander_Boxing_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Boxing_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Boxing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Boxing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBAEC454FF4A11B29ULL; std::uint64_t aIngress = 0x8D9D2707E1F46719ULL; std::uint64_t aCarry = 0x9822529D00848B28ULL;

    std::uint64_t aWandererA = 0xF1711CCD8D127915ULL; std::uint64_t aWandererB = 0x92E3FC197F5D34B6ULL; std::uint64_t aWandererC = 0xBF6A65C135251BF7ULL; std::uint64_t aWandererD = 0x826EAD85640B4C23ULL;
    std::uint64_t aWandererE = 0xC95B42051273815DULL; std::uint64_t aWandererF = 0x991FAAE31EF9F900ULL; std::uint64_t aWandererG = 0xB98FB4C29100C420ULL; std::uint64_t aWandererH = 0xD50DCDC0EA8EAB40ULL;
    std::uint64_t aWandererI = 0xC923EA15612D694AULL; std::uint64_t aWandererJ = 0x8C4D9FECD7E2BFB1ULL; std::uint64_t aWandererK = 0xE13C39114FB7CB98ULL;

    // [seed]
    {
        aPrevious = 16043517883018668773U;
        aCarry = 13517748281585581098U;
        aWandererA = 13715202494413629602U;
        aWandererB = 12392763735499172531U;
        aWandererC = 13207465720822481637U;
        aWandererD = 13761798697062873220U;
        aWandererE = 17708553348439504158U;
        aWandererF = 9953347782130959887U;
        aWandererG = 16448951567204585812U;
        aWandererH = 14397961827492945711U;
        aWandererI = 15926450662472875190U;
        aWandererJ = 11007986163253567578U;
        aWandererK = 13180229316301207718U;
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
    TwistExpander_Boxing_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Boxing_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Boxing_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Boxing_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Boxing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 3, 1 with offsets 1602U, 2427U, 2272U, 2508U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1602U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2427U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2272U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2508U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 3, 1, 3 with offsets 6410U, 3852U, 1023U, 6301U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6410U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3852U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1023U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6301U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 1, 2, 0 with offsets 2433U, 594U, 4402U, 2794U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2433U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 594U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4402U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2794U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 2, 0, 2 with offsets 295U, 7384U, 6156U, 3336U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7384U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6156U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3336U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 2, 0, 3 with offsets 1518U, 43U, 1877U, 1337U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1518U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 43U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1877U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1337U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 2, 1, 3, 0 with offsets 630U, 576U, 532U, 1823U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 630U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 576U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 532U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1823U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 1, 3, 0, 2 with offsets 260U, 285U, 1242U, 52U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 260U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1242U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 52U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 2, 0, 1, 3 with offsets 242U, 484U, 1321U, 142U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 242U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 484U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1321U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 142U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1690U, 788U, 1580U, 1908U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 788U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1580U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1908U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Boxing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 0 with offsets 1560U, 5476U, 5232U, 489U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1560U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5476U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5232U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 489U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 2 with offsets 4187U, 160U, 7254U, 5406U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4187U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7254U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5406U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 0, 1 with offsets 7368U, 1912U, 7528U, 2864U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7368U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1912U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7528U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2864U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 3 with offsets 5510U, 1144U, 4876U, 7009U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5510U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1144U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4876U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7009U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 801U, 618U, 461U, 2283U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 801U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 618U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 461U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 2283U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1100U, 1850U, 454U, 602U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1100U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1850U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 454U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 602U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 774U, 1534U, 526U, 767U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 774U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 526U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 767U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 174U, 1778U, 768U, 1955U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 174U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1778U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1955U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1705U, 1456U, 1493U, 1250U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1705U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1456U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1493U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 2, 0, 3, 1 [0..<W_KEY]
        // offsets: 99U, 1557U, 1042U, 150U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 99U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1557U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1042U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseASalts = {
    {
        {
            0x07E14678675589DEULL, 0x37AC65043A889275ULL, 0xC0AA0FAC5F391C47ULL, 0x153B3A758241FA5BULL, 
            0x74915E82072DE395ULL, 0xB5A2435EDA1473A2ULL, 0xBD7EFE4FC7CF2ECAULL, 0x414E811595B2F5C3ULL, 
            0x26325AAE7C15618CULL, 0x6CAFD5568D06BF32ULL, 0x251E3D7298FB0524ULL, 0x75B397BF1113B7AEULL, 
            0xE7CA6C469F1FC6A1ULL, 0x021E07888DB6CF53ULL, 0xFA2359978BCB0B90ULL, 0x8B24CB0FF1DFAD9CULL, 
            0x6E5C85277ACA3F77ULL, 0xBE1055332A1CD307ULL, 0x5C8143BF365CF29DULL, 0x08B37FCA6501A9A3ULL, 
            0xB9D63F6BCDC4F9C4ULL, 0xFA00E187FB31E8C3ULL, 0x1C646E4F120998EBULL, 0x3FD1464152877487ULL, 
            0x5360D6B9C8836801ULL, 0x19324D948F0F485AULL, 0x315F99E96DF3BB2FULL, 0xFE779421F2009D06ULL, 
            0x8D553B73B41E5A55ULL, 0x91E27A7E78D38AF6ULL, 0x03D89C9578FCC75DULL, 0xC496717000076C2CULL
        },
        {
            0xBFFDC7DB87AF68F1ULL, 0xBB92D299DFB334A2ULL, 0xD0427EF6210810A8ULL, 0x9043187302098080ULL, 
            0xC280F5BE967DAFBFULL, 0x4902EEF0360417E9ULL, 0x4F8E921A0BFCDC2EULL, 0xAB817FD2EB5E2D2AULL, 
            0x10915261DD24DFF5ULL, 0x1893D4F4B32B40EEULL, 0x08E5AB06992D45EEULL, 0xC6BEFF86A69D1C49ULL, 
            0x8495171FBA5B45B0ULL, 0x8A9CACA2C2263DC0ULL, 0x076BD32573081B92ULL, 0x0D207BF996E6DDEDULL, 
            0xCE3A2588DB0C5C36ULL, 0x5A9E74924CF3675EULL, 0x342FE4E76D9E18E4ULL, 0x48E242A0F1501609ULL, 
            0xF8B2F59F3B0B24AEULL, 0x88F9CDA26D6BC248ULL, 0xD0724D6628679DD7ULL, 0xCC2985FC2D6E9D66ULL, 
            0x20E941FDBF5F4033ULL, 0x9FB0B50F1D66976EULL, 0xE1DE7C7CDAEDEA1BULL, 0xC9868AB2F1A434E4ULL, 
            0xBFA8407CD5E932A9ULL, 0x23B5DC653DD04917ULL, 0x96F0673653110D8CULL, 0x938D6AAE85914044ULL
        },
        {
            0x23D9AD8A8C039650ULL, 0x4857B6DB4832B997ULL, 0xEB8414BEE67C3AC3ULL, 0xEEDFBFB75C8B4175ULL, 
            0xA65065938BD7906DULL, 0xEF815575AD515C57ULL, 0x882A9598F481334AULL, 0xA504B03BF1C96F79ULL, 
            0xE75F4F91375D2EA5ULL, 0xB557AC71C76D7B85ULL, 0xB5377E4C1AD3DDE1ULL, 0x7BA7AD9D17180AF7ULL, 
            0x69645EC982332ED9ULL, 0xEAF30F94E2BA5CF5ULL, 0x474EF815FA85B14BULL, 0xBE14DF2D3861DB24ULL, 
            0x22CACACB27D9D9EDULL, 0xD8BD3D8559A0DEBEULL, 0x04EC41D538D94BC0ULL, 0x81FA6028DA487D61ULL, 
            0x8976558DB5B612D8ULL, 0xDCC2C69D27C943ECULL, 0xDF8D24DB96887B17ULL, 0x907EE34C0BBA58AEULL, 
            0x1A27CA0A393D40B8ULL, 0x2C4BE91AAC84FE0BULL, 0x36DCAE0B301F4582ULL, 0xBC3CE18823EF1EDBULL, 
            0xF8C08503842FA626ULL, 0x39E8DF35630DB2B4ULL, 0x7C2BDCC869A281A4ULL, 0x27A0F1BF9BD1777EULL
        },
        {
            0xBBD8AF3CB5646E92ULL, 0xFD71BC4CF6C4A300ULL, 0x223005C5AC139BAFULL, 0x208C1A8786AB2A36ULL, 
            0xD01CBA6D407598F3ULL, 0x8AEA81A3FB980A63ULL, 0x2C0AE7C2116519FBULL, 0x894E4242AA4984CEULL, 
            0x7A0D68E1E2301A21ULL, 0x90616E368F02165AULL, 0x3BDB5B2031A13200ULL, 0xDF1E2BD55AA03088ULL, 
            0xDB2F9BE197B42F2FULL, 0xAF4CB7CF2C0566A6ULL, 0xABD2414EE834B781ULL, 0x8CB2CC6A6C8EC631ULL, 
            0x049BFB8ADF0A1B6AULL, 0x0B53EF81E1E3E5A8ULL, 0xF97B9B4E26848F27ULL, 0x572B9F60A75A1430ULL, 
            0x338D9793F0D23B6FULL, 0x63D0A5D7F1F0C314ULL, 0xD559B85ED2E8E7DEULL, 0x625913A55D109304ULL, 
            0x12ABB2691811C1F2ULL, 0x489A991F0E96B72EULL, 0x19C6C46CB0BDC3F5ULL, 0xE48D5C860F73CD29ULL, 
            0x3CD2970C7C30F72FULL, 0xCA909CDD1B5133FBULL, 0xF95D75AF109013F3ULL, 0x3A744973E81F4852ULL
        },
        {
            0x620CFBB37287D42BULL, 0xC594207AC0903284ULL, 0x07CA393B1208518DULL, 0x66360AD607506304ULL, 
            0x46479375088F0669ULL, 0xC9098D35119C2C1DULL, 0x2FA3D610912A0904ULL, 0xC20EA4EBBF1ACE25ULL, 
            0x101B0840DB64B4B4ULL, 0xB3B392FFEE5BB826ULL, 0xABEF2D5281209097ULL, 0x09C5222CC8D3A828ULL, 
            0x446AD69B7139683DULL, 0xAED334B05F55CE47ULL, 0x179C5ABB7D863B77ULL, 0x866CE0173C9E4EE3ULL, 
            0xE7C2DF806980EA02ULL, 0x47873B8EC055F043ULL, 0x375AB1301C72011BULL, 0xD97AD618991B6E10ULL, 
            0x6CED33117E5060F8ULL, 0x1EAC19904C2E3ABDULL, 0x96AA2F5C4CE254B0ULL, 0x68FCE7D676BDE2E8ULL, 
            0x48EBAA83C3F1E4FEULL, 0x59FFCE4BFD1559D6ULL, 0x91A82A5355E9409CULL, 0xC5364129448318F5ULL, 
            0x89E3C07DED8D9080ULL, 0x8773158ADB1D4B5FULL, 0xE002D8A935F3C027ULL, 0x013C5435FFB85897ULL
        },
        {
            0x12DF72E564001DDCULL, 0x35DC550FBB03628CULL, 0x9854D06307DBE283ULL, 0x082A66D513F30738ULL, 
            0x6B68292D5AF22CD7ULL, 0x5421CD99FC4B1E29ULL, 0x5345C409B6880E53ULL, 0x7A63B20F022E43CAULL, 
            0xB3F2F72BF93B9406ULL, 0xCED10406F54A4CD3ULL, 0xB334286D3468DAE9ULL, 0xF4A99DAB064025E9ULL, 
            0x31748AEA743227FBULL, 0xD27DFE547FC8D6FAULL, 0x0D4E59998C0DD4F7ULL, 0x6289444DDF6223ABULL, 
            0xE1F0877AD53C8B3BULL, 0x188257CB86CBE40AULL, 0x123BA4D5B915DFE3ULL, 0x7D8569FA35C8459CULL, 
            0x13BCCE0EB78E4BB6ULL, 0xABC5DA4C3FDE2209ULL, 0x21275C8FE58477F7ULL, 0x7BF104E2C9651697ULL, 
            0x52E4CB3A2078738DULL, 0xDACAD952CC70806EULL, 0x68C7210F7B7F6AF3ULL, 0xE14F93E3B3C502DEULL, 
            0x0B676C68EE2B9B52ULL, 0x5D2C779827DD2215ULL, 0x687601D432DA4AEAULL, 0xA36EB8FAF9F69ADAULL
        }
    },
    {
        {
            0x1D56D5B2F81E8843ULL, 0x8D9BCCE3B9668DA6ULL, 0xBF5858D180CB152DULL, 0xA42FB6F4DBA75351ULL, 
            0xD5DD0A58EBE05A64ULL, 0x773494457F018590ULL, 0x803497E7E40312E1ULL, 0xD03ED303A833FC45ULL, 
            0x79F08EE8D90BC4D0ULL, 0xF3B59929F427B6B5ULL, 0x9BD5047FE15335ACULL, 0x13CED47AF6EB21AAULL, 
            0x476E01D4BA328F2EULL, 0xD1D05FE4E52C4370ULL, 0x79FCAC52FF26000AULL, 0xBE62FD9CA52B747FULL, 
            0x5D0C5212A6427C55ULL, 0x6E82C6BA13AB70C2ULL, 0xCE56A5F8D9A00A45ULL, 0x6F658976CFA28AD7ULL, 
            0xAB6C5863F3AC9B51ULL, 0xE41A757F48E14FA9ULL, 0x70F1E728643FC92AULL, 0xCDEDB1CFA5AD3AB4ULL, 
            0x16467CE66B953BE0ULL, 0xE87CBE50A40FCE6CULL, 0x06EFE07661454712ULL, 0x2E38A84209DAE28DULL, 
            0x5C46A6EC06EFDA01ULL, 0x535BD91793C21570ULL, 0xE3FB3096A57E19A0ULL, 0x960088B68D6FF84CULL
        },
        {
            0x1DC75795E528EE83ULL, 0x4FB49563688DC795ULL, 0x5E12A1FF9CA7A15EULL, 0x608AFAF0DC2E110CULL, 
            0x5A6F10D817F94F40ULL, 0x38FEE838553BBC38ULL, 0x06E20E6399582EECULL, 0xFB0DD6746862948AULL, 
            0xC96CE0ACE536AD1EULL, 0x9AB5313643199EE0ULL, 0xE568B89B8836BE93ULL, 0x93ED11CCA4729237ULL, 
            0x8BA7F4F2789D790AULL, 0xA0BD619DDECDA4FEULL, 0x8FD9DE59881AA9A7ULL, 0x4ADCBF5E4FE5BFCDULL, 
            0x9CFB64607A4313FBULL, 0x7FA48ED7EB00DAE5ULL, 0xC3BE6F7B40101033ULL, 0xE4BA70C1028B20AAULL, 
            0x084495E8F3535B42ULL, 0x6CB25B2002CB2C74ULL, 0xEB5652DAC9E7E648ULL, 0x2C73928325B1D08FULL, 
            0x6255B45D8E538918ULL, 0x7C22D77C0F853BA8ULL, 0x85E744C5B0A356BAULL, 0xD7160360A5963411ULL, 
            0xED7EEBDB03CA3ACFULL, 0x37A51CCC98E93B01ULL, 0xC08BFD32471B44E9ULL, 0x95DA072C9042A146ULL
        },
        {
            0x5E3EB166D24AE1A8ULL, 0x8D2761370451AE11ULL, 0xBCF177D3540C28D7ULL, 0x8135FC6748607EF2ULL, 
            0x41036216E2EC9EE2ULL, 0xA294574D10CF2A9EULL, 0xDC8251232BCDDF2AULL, 0xEDC2DCB92A742707ULL, 
            0x0241FCAE4C03256AULL, 0x63DD52BF54EFD211ULL, 0x3C5E461DA5527466ULL, 0x7CA30E308FD7BE02ULL, 
            0x831B7828D1A7264BULL, 0x7CAF6F73F855BED7ULL, 0x012EA54C2C256553ULL, 0x4C6F3B1CB5427B0FULL, 
            0x73EAFF6D23DBCF98ULL, 0x7F853FFA702AFCE9ULL, 0xD93DAF976BD267F0ULL, 0x4A427E2A40402CE5ULL, 
            0x4F7A862917069C65ULL, 0x8A47C7DE9E13F733ULL, 0xD8500F3FDD5533EFULL, 0x5B220DBBAAD2EE7AULL, 
            0xB6A5514AA602E7E3ULL, 0x8E5A58DE2A86B2ABULL, 0x0576C6942CE64708ULL, 0x5834D76A527BA91CULL, 
            0x9E26BB815266CF7DULL, 0x3C988EB73A487333ULL, 0x86967F81CA203D00ULL, 0xFCE681CD5A1C7A8AULL
        },
        {
            0x99536FC2C7BC6A53ULL, 0x6813854C81D7F488ULL, 0x30A4BAF295A4B09DULL, 0xC3E39859C4A14D89ULL, 
            0xF24BF2A30D9A2250ULL, 0xCB08BFBEDF6CDAB1ULL, 0xF46205D8F17A1FC4ULL, 0x84066AA0EB0A5E96ULL, 
            0x2A23543CBCE2AAD4ULL, 0xA075B26DDA55D8D9ULL, 0x61D1F9B39ACDC292ULL, 0x6B92F1CBE7E52C1DULL, 
            0x80D8618886AE9A66ULL, 0x3B64EC8EBDA2EA96ULL, 0x316A406CE8A44C5BULL, 0x9F818AD2B8C84F36ULL, 
            0x867431B763994DC1ULL, 0x501E1D05C80AA7C7ULL, 0x4C949D1E051E0AECULL, 0x6079FCF343F3578CULL, 
            0x8B10EA5988FC5901ULL, 0x611DF2F47B91BF34ULL, 0xE547A6EEBD83AFDCULL, 0xC7B5DC79EC00CF85ULL, 
            0x4BAD2165CF77C54CULL, 0x75014B1334BB7D05ULL, 0xA917C3B58D88FE00ULL, 0x98CC1440E67C799DULL, 
            0x11B7706600CCC854ULL, 0xF3B935137027F783ULL, 0x1F41CACBA69D4E51ULL, 0x6D125DE87A62581AULL
        },
        {
            0x2EA9BE04CA47CEFCULL, 0x395C470740F5746BULL, 0x9D4FD180D23446DBULL, 0x3437008893B97519ULL, 
            0x539F5578E0F3A0F0ULL, 0x12C26647E3F83F56ULL, 0xA25215D60E994665ULL, 0x4E6FFF06D64875DEULL, 
            0xEFA00479C6B5942DULL, 0x0DD5F2F5F1F18876ULL, 0xFD4DA175A8FDD918ULL, 0x1F3737005070053AULL, 
            0xA3384272AA588736ULL, 0x048D06A67FFD805DULL, 0x70364D4AA7365C5BULL, 0x6AC15202D662A296ULL, 
            0xD5C45F0C09241D48ULL, 0x558B86F5EF415FCDULL, 0xB890422FA573264EULL, 0x7AB3E292AC055D4DULL, 
            0x3415858281A45D86ULL, 0x184A7BE242B54B19ULL, 0x2C5123B1C5198D9CULL, 0x5F477024A34ACE0DULL, 
            0xC9BAA1E9AC87DFDCULL, 0xBF2E94BA25771D8BULL, 0x0060E3EEA95AFDA6ULL, 0x9C5C9BA7B3E9A807ULL, 
            0xF67CB187DB9313C0ULL, 0x8A806D24E9777FFEULL, 0xAF536D6BBBD6B8F9ULL, 0x928DE19137C73A3AULL
        },
        {
            0xDC5428F83F24DDB8ULL, 0x503CC52C3AA840B6ULL, 0x601102C3B04A846BULL, 0xFD9370FEA0472A4DULL, 
            0x32AE1447EC6960A9ULL, 0x9F8339646AAE53F7ULL, 0x1E40B0B860BEB14BULL, 0xADC45B6F3BD1F9BCULL, 
            0x983391BACD98DC7EULL, 0x388A8B7D4A59724FULL, 0x323DF0075EB480DEULL, 0x249B3D9356BD1B4AULL, 
            0xE8EB4E100DF4E710ULL, 0xAFBE009A304C468FULL, 0xE538FD0CDD69F21BULL, 0x2A709BF8EA674174ULL, 
            0x322B9BF3EC2ABE3EULL, 0x923D87F6B10E04E3ULL, 0x8B58461CEFEB1C10ULL, 0x16B6F5DB6F452F12ULL, 
            0x9CB9ACA601D90D88ULL, 0xC1B551C77600DC6DULL, 0x6975118A0FF95B77ULL, 0xF2C4FD21AC453BA2ULL, 
            0x12F03979BA3D3406ULL, 0x26F295E60E6FF978ULL, 0x214DB9F7B17D2C41ULL, 0xC9E72FDBE7996C9BULL, 
            0x9BD8238D40BF1C7AULL, 0xF3D0B168F5F785A7ULL, 0xA0C8D6236B613FB7ULL, 0x8E41B3981A1FE148ULL
        }
    },
    {
        {
            0x2C8D3BF7DA95083FULL, 0xFE4F190A1754AAE8ULL, 0xF32384CFBD32B18DULL, 0x32FB09176624E6E7ULL, 
            0x70723EF1B87AF411ULL, 0x441A7E43402C2263ULL, 0x6A725D088E8084AFULL, 0xDC39AA0CA6B7D57EULL, 
            0x0A984D5D9D1433D7ULL, 0x3EE2518A7A93D712ULL, 0xA7F9FD69E3F50DE3ULL, 0x5E6A8BAA3D513A1EULL, 
            0x88A77A4567AC0C58ULL, 0x5E3D7C34A12ED6D5ULL, 0x0EB3BDFBCEFDCF45ULL, 0xE90D4BFA484EB16AULL, 
            0x019A74F928FD9DE9ULL, 0xCA7144FDFC813621ULL, 0xADADAC9E86151A4CULL, 0x34FD86D1263348DAULL, 
            0x2C0F4361FE96F050ULL, 0xB61717224C36FA1BULL, 0x37E2213A6915A550ULL, 0xD18CD7C44A233BA2ULL, 
            0x49FB840608C5EC21ULL, 0x3A624FB1FC266396ULL, 0xECB6178E38943733ULL, 0xF6AD77FC8CEC8398ULL, 
            0x1297C307C07BC4ABULL, 0x0F13A1BAC07BD6D8ULL, 0x935DD409E28BF8ACULL, 0x6F8B135CAE5C2D35ULL
        },
        {
            0x8926CD310C84BDA7ULL, 0x720AF2335E229178ULL, 0x1BB448B865746CDBULL, 0x7AEFA79A0A0BF1C9ULL, 
            0x5DA7AFF2109410F0ULL, 0x52FC4A2AB0472018ULL, 0x72CAB91BC75FB761ULL, 0xF2D3FDA19D38FE88ULL, 
            0x06CEEC5824C12737ULL, 0xA9271ED2C51481F7ULL, 0x3BD8FE2826FEFFEAULL, 0xF8414C09486D645FULL, 
            0x8CC22475B48A6FB4ULL, 0x4CDBB51DE289259BULL, 0xE599AB4A2F06A3E9ULL, 0x1D97D68DDBBB0A44ULL, 
            0x2896B3F8D886B715ULL, 0xA9248D38935C5F3BULL, 0xE125945FBAE469ECULL, 0xA5138A4C66E469F3ULL, 
            0xD9AA55695D5D267EULL, 0x94E76F7177DA79D1ULL, 0x2821B1DB37E96107ULL, 0xC0303F0122186528ULL, 
            0x870112CB6F9F22CEULL, 0x2AE0793C5C41BC68ULL, 0xD89366DFCC64B2C1ULL, 0xE212795D9CBF8194ULL, 
            0x85F830C4B8FA3B4BULL, 0xF970B2FD250342FEULL, 0xD9C1ECBB211EBF34ULL, 0xB02B265B3667DEFDULL
        },
        {
            0x6DC4C4D3E35E22CCULL, 0xDADBDE66D90A6DB5ULL, 0x31B2563800D3AC87ULL, 0xC76E8566787C0FEAULL, 
            0x274ECB8481E75464ULL, 0x41664704555957CDULL, 0xE013B65810739054ULL, 0x03B61D014F457DB2ULL, 
            0xB541094275338D35ULL, 0x42DEE0DA888A7816ULL, 0xBD23F14FA8B986F9ULL, 0xF1A1631573B1720AULL, 
            0x2669E1E8D56A81B4ULL, 0x3122211CCE532E73ULL, 0xEB370E968C6BEA33ULL, 0xD3674661D56A3E55ULL, 
            0x85CC4FBAC58D0B89ULL, 0x6838170D464A02F7ULL, 0x130EA4B5BA5408ADULL, 0x1F74E16231B8174AULL, 
            0xFECC6F3AC0228234ULL, 0xE397F8B550EF618AULL, 0xE6686A9FA783C9A1ULL, 0x94D682027FD2FF20ULL, 
            0x195D614FD60F71BAULL, 0x0AAD494729C42A3BULL, 0x8A468E32FED892C4ULL, 0x299E9E2633696007ULL, 
            0x85E83E6B45327B85ULL, 0xFB96B937340F9B31ULL, 0x297E10DA4E0F5B49ULL, 0xD1A154058CE59803ULL
        },
        {
            0xF8FC0F6BC842A843ULL, 0x4938E58609BA5BA8ULL, 0x7A1EB9231E9A9F5BULL, 0xFA3B7DA1179E44DAULL, 
            0x580B2C1BACA1468CULL, 0xFEB79FB5A216486BULL, 0x0FFFA1A28456840FULL, 0x88D7DC3C8C1EA5CDULL, 
            0x59F06C731EA53FFFULL, 0x33D23BED455669C0ULL, 0x1F84A27F518C9EB9ULL, 0x28B011F35C0F3C87ULL, 
            0x48B70049959AEEBCULL, 0xBBB9A4468E55895FULL, 0xD94B39839DC2F241ULL, 0x4227CABDF38CD327ULL, 
            0xF851DE1AEDBA7899ULL, 0xD51CEA0EE24B750AULL, 0xDEA048C234F52DAFULL, 0xDDF554DDDEC968EEULL, 
            0xC99D25424A3BF28AULL, 0xE326BAC8D2E98A18ULL, 0x0994721D1B7A2AE3ULL, 0xD79B462617E62DB7ULL, 
            0xD11F49B9F75726A0ULL, 0x22C2B880C944037CULL, 0x886C8A8F67EFA9CBULL, 0xEEB10F00D6DEAA82ULL, 
            0x4E60241DECD9F91AULL, 0x0783A5184C6A2379ULL, 0x99081C415D15CE48ULL, 0x265C4EBF917B854AULL
        },
        {
            0x7EE56877469A46C3ULL, 0x5B93AD5C705ACEE2ULL, 0xCD9B464A60F7CE96ULL, 0x46E1C0DF660DA86CULL, 
            0x7F346CD1E9D12BE9ULL, 0xAA44BE292FE55297ULL, 0x6AC1BBBF9860B78BULL, 0x1C112A60EC862A45ULL, 
            0x25C2593B0D7894BCULL, 0x326969D9F8F70A91ULL, 0x5616C6199C8BDA33ULL, 0x3F5BFF24B937406CULL, 
            0xC4134CBE54D56B95ULL, 0x4C49731A2F9BD131ULL, 0x4F393186F0FCA90EULL, 0x6550B4584CC20943ULL, 
            0x61AF490759D4ECC6ULL, 0x52FB6709AB9D928FULL, 0x42645DF07BB09856ULL, 0x43FF7DCC360B44A4ULL, 
            0xC97A506B2B169857ULL, 0xB0407ADC908490C3ULL, 0xBCA93DFCF967770FULL, 0x058950CD72787BF3ULL, 
            0x6FC4FF344D3CF3BCULL, 0x72736EE98A7BD0E8ULL, 0x085886B375CC0DB3ULL, 0x4CCCAFFC3342D3FBULL, 
            0x5EA669FF4F313618ULL, 0xEA08E993D118EC92ULL, 0x972D7E80ADF831F5ULL, 0x1863061DDF43608BULL
        },
        {
            0x3D40A9EFD2B3B9CEULL, 0x362530E47EF3F70EULL, 0xD42711BADA6E323DULL, 0xA7B9DA9883D5FC6BULL, 
            0x99DEBA9C00B5D585ULL, 0xF39D9E769B7A3BC4ULL, 0x50968C2F3D1EBD3AULL, 0xC8DC0EFF69CBDE4DULL, 
            0x1E7AAFFBBC9E43EDULL, 0x157EC791AFBF3A90ULL, 0x26D13ECCA213CDF3ULL, 0x3E4525A8D3C59BD8ULL, 
            0xA5EEA9EDFE50E19EULL, 0xDDAB34F2AFEAA935ULL, 0xC8DF4B047D42AB02ULL, 0x45583465D8BEDA46ULL, 
            0xE1A79A0DA445E7ADULL, 0x44D455B7870B196FULL, 0xD4B5DA5390EA9F96ULL, 0x50353835061B3B21ULL, 
            0x6365C0DA7D108FC8ULL, 0x3AB87EDA03314F8EULL, 0x982026F1C33E41C9ULL, 0xA61FE26B5EDCB3D0ULL, 
            0x921D33AD72D92017ULL, 0xC868B3E1B72FFB80ULL, 0x31C5FD8F1DA7219DULL, 0xA68AE1E4FFB08448ULL, 
            0xD5AFEEF060AF6014ULL, 0xBE7534BAB3AC4BEDULL, 0x2DCA0CC49A0491BCULL, 0x9632DA438C1A595DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseAConstants = {
    0xBA5B00F556407AF4ULL,
    0x1DFB70E279331CCCULL,
    0x860AE6B635FAFE25ULL,
    0xBA5B00F556407AF4ULL,
    0x1DFB70E279331CCCULL,
    0x860AE6B635FAFE25ULL,
    0x22F7186806339172ULL,
    0xB1C10E70601A0AF4ULL,
    0xF2,
    0x51,
    0x1A,
    0x48,
    0x3F,
    0xBD,
    0x31,
    0x03
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseBSalts = {
    {
        {
            0xFA29BC305727D834ULL, 0xF942B636D88293AFULL, 0xFECA1E3B5961509AULL, 0xCB5C5F4F74166610ULL, 
            0xDD6CD5A60CEE7A35ULL, 0xE66F282A0246C052ULL, 0x71E8D3079185F094ULL, 0x0261FC1BF544C83EULL, 
            0x3D4B866CCA9C38B3ULL, 0xB6CC023D0BC77797ULL, 0x3D29F9B12822F32DULL, 0xC0F77F79EACDC2B1ULL, 
            0xEE1D94503C13213FULL, 0x85DC9AE5FE1DC3E6ULL, 0xD36C4A657F12FFD2ULL, 0x063E4C953EDE7593ULL, 
            0x97A5334638319C56ULL, 0x3678E9413BCFDE3CULL, 0xFB25D77CED411861ULL, 0x1036E5E9D2A22025ULL, 
            0x9A91826E9F8CEF88ULL, 0x94C9EDA2A45E4F55ULL, 0xC543A9992C8E4233ULL, 0xAF7C8F65C1A14722ULL, 
            0x3A405A42F7EB537BULL, 0xC3F4145CD5ACD2A0ULL, 0x93D88517DDC15004ULL, 0x325FF96A30B41992ULL, 
            0x233F39ABC0526078ULL, 0xB9BFC6556DDA4F25ULL, 0x40D9D1020BFD86D9ULL, 0xE887BF9FAE88C676ULL
        },
        {
            0x760BBDB3781709B1ULL, 0xB9458F788AF0EB2CULL, 0xE894CFE14AB5A83DULL, 0x5B77F09C6545D047ULL, 
            0xB7D8B9F1039B76DAULL, 0x1D312C13B064E05DULL, 0x06EE7DD96AF9908DULL, 0x16326579D61C2344ULL, 
            0xAA60205C5C5B80A2ULL, 0x8ED2FBA42306F4A6ULL, 0xFB74EE9E29D34544ULL, 0xE521948D231AC0A4ULL, 
            0x3A01CEA8707786A1ULL, 0xB9CE1B66D3D90E9AULL, 0x3711AC1F0A8385EFULL, 0x170358CCF19ECB7DULL, 
            0x26FD13E349A07E34ULL, 0x4A053664CEFDB710ULL, 0x75D01D7412979395ULL, 0xEFAEF2557932484BULL, 
            0x6029E4C0470FC850ULL, 0xC1ACE210B420D571ULL, 0xCD5D89972BC0AEFFULL, 0x6581025DFAAA3489ULL, 
            0xC23A9EB3AC6A2D0BULL, 0xECF58DBA11E5F46CULL, 0x56E4809B44C2D94FULL, 0xFC7ECF6A886BD8F4ULL, 
            0x5D65EC0968FBD48DULL, 0x9E0566D87C5F7107ULL, 0x3A669BBB857E75C2ULL, 0x4A52857147E87708ULL
        },
        {
            0x900BEF39679A841DULL, 0xCC49378552A052AFULL, 0xE5E588C338AC03A7ULL, 0x08BD5EC3C87844F2ULL, 
            0xE044D21D60AD57C0ULL, 0x01CE74FC5BFD9078ULL, 0x67FC90C98AD19F7DULL, 0x6E922A27F5FCF413ULL, 
            0x536A4586655BC9A7ULL, 0xF764791877D0A5F9ULL, 0xA131E19D2B02F673ULL, 0x259A5AD736BEE64DULL, 
            0x9B8C09855DE0EF7AULL, 0xD364A9585704BB7BULL, 0x5A4D9E4BAD6D066AULL, 0x7EE42839629F197DULL, 
            0xB2C11DEEE398810DULL, 0x683DD7DBA1B1E71AULL, 0xE35BC80A519D7511ULL, 0xB98EE3E7C4C30F84ULL, 
            0x16B73E0D3314AFC2ULL, 0x35D77DC4C6844CF5ULL, 0x1867EE14A4604B53ULL, 0xB56DFE7A3642695AULL, 
            0xDCC35F646A5CC78BULL, 0x8DC158964B33A402ULL, 0x264453B56AE29D7CULL, 0x451475BBC0FF3627ULL, 
            0x350AB98BA00B6196ULL, 0x67181F48AF3D154CULL, 0xFD9C9FEB16216852ULL, 0x630E90ECA0F623E7ULL
        },
        {
            0xA6032F87C945CA01ULL, 0x1C3ED6E9E7A38CA0ULL, 0x3F81BBB02A1E6370ULL, 0x633708AFE46B8804ULL, 
            0x3C8F124307B0E71CULL, 0xFF084546750D8FCCULL, 0x795D885E5B2FB39EULL, 0x56D04608EB63BC42ULL, 
            0xBBC9085B371B4679ULL, 0xBC23E121C368D901ULL, 0x27CFE7A57C9DE20FULL, 0x45277A4EBC004C8FULL, 
            0x1F27C9D209228986ULL, 0x02C52E9897055E0AULL, 0xCD6110E9806CDAB3ULL, 0xAE4CA9D2DD5A3DF5ULL, 
            0x0B796B0CAC0F8B44ULL, 0x60FDBDECBA0C9D39ULL, 0xA8983E93E4D893B0ULL, 0x5A554C146BFD6CB8ULL, 
            0xC24EEA00A9EEE317ULL, 0x4A1298E7D4EC1BEBULL, 0x59E7F4CF1CBC8245ULL, 0xEC6E9CBD9E2497DAULL, 
            0xF87C3FF2ACB00C77ULL, 0xAC259D7BCF3F09FEULL, 0x213CC197376B9A0AULL, 0x76CE75CA92F151F1ULL, 
            0x2F4ED729F8A5A884ULL, 0x2A7DFFD1191341F2ULL, 0x7AAF1A986DA4D7D4ULL, 0x52588E80525F3C71ULL
        },
        {
            0x029E76F9EC3C0449ULL, 0x8A86C93BC9CAE338ULL, 0x62E0B740DFE9CD5BULL, 0x89FBCC139278EAFBULL, 
            0x277C6E0CFBB7B9DAULL, 0xA12A6C8C8C66ABF9ULL, 0x979435606FCBBCC1ULL, 0x73EFC55D8149B09EULL, 
            0x482660E53D853910ULL, 0x320DA74E1F630FFAULL, 0xC0E9913DBB5C548CULL, 0x221257B4AF6B606BULL, 
            0xBEEC743CE9DF8D6EULL, 0x654CCD143BE9845BULL, 0x4A713C88DC4CA6A9ULL, 0xD42F127560A47B5DULL, 
            0x1A2CE37EF1DB9F3DULL, 0x0C857F1C98A45DE9ULL, 0xA5256AE440B636D2ULL, 0xFB154E66083D1045ULL, 
            0x6D184FFBA743F0C1ULL, 0xE1BD6AD38DBB1A8EULL, 0xFCB3468FDE7F78B5ULL, 0x693F5F4BEEC294CBULL, 
            0xB63A342B24D28837ULL, 0xA1B5B14197B5A669ULL, 0x7D129D6A4CD4A26FULL, 0x3005AD77ABB14B8BULL, 
            0xF990EC92D8A36126ULL, 0xAC7A531F8A5FEA80ULL, 0xE7E3CBEB586E8228ULL, 0xE0A8F10F7BDDE34AULL
        },
        {
            0x621E96A6A75769E8ULL, 0xC5C7A4FE3CBB8A6BULL, 0xAEDED6D09ABED423ULL, 0xE39AFA1460B5DA4BULL, 
            0x25E13CE7D76EA2E5ULL, 0x82D390FDCED97991ULL, 0xDB788F611A662DF1ULL, 0x138EA37638C05DBFULL, 
            0x827D9725F7CF5218ULL, 0x2C41C1B6E714C967ULL, 0xB1FD1CBDB80C7BA4ULL, 0x382944FCCC74A09BULL, 
            0xF13282842D9B63B8ULL, 0xA077DB8540BB35E8ULL, 0x2B0E2575C99C1A89ULL, 0x5D6C47A92424DE71ULL, 
            0x64D12F230FD4D13BULL, 0xBD860D16951696B8ULL, 0x747181EABC9761A5ULL, 0x6E876A17F311D16CULL, 
            0xBD6BEA467649F4BFULL, 0x045C662F134F51C6ULL, 0x92E29E19312A2757ULL, 0xCD0C580C5A655F09ULL, 
            0x4B558C8258E38B9FULL, 0x8F23DC5CD97B47E1ULL, 0xC6DD604498C9E257ULL, 0x4FCB1FB3CF384047ULL, 
            0x15850FA57FF0F5CBULL, 0xC7735B80EF7DC71DULL, 0x3B1A291247FD048CULL, 0x5E4632CD9A690F62ULL
        }
    },
    {
        {
            0x51D898BB770D66F0ULL, 0x3733D75757D2B5F3ULL, 0x03AB4F9C2B7EE5A8ULL, 0xAECB465A937D1847ULL, 
            0x15861C680386DD6EULL, 0x978C771B7BD1038DULL, 0xA77A1AA319BE768DULL, 0x3014B79CAC99A04BULL, 
            0x56DED9097864853FULL, 0x2028303F39FA69B8ULL, 0x6F5F6D7CCE69BC66ULL, 0x61E21C3260C72E7EULL, 
            0x5183E7E8F141120BULL, 0xA89122548EC43025ULL, 0xF1C5011C87B8098CULL, 0x3ABC9634720A7690ULL, 
            0x916570C90E8BA5EEULL, 0x5A44AFF9784D4960ULL, 0x2D84E0A07ADCB637ULL, 0xF86BA0920AA6EDC1ULL, 
            0x2602119910F751C3ULL, 0x56F9A083838AE6B1ULL, 0x2061293FB5CD0B03ULL, 0x43276038D4427743ULL, 
            0x9BA866FC16742E2FULL, 0xF18EF7EF5C4C8AD1ULL, 0xA0065F55B9039E0DULL, 0x23C4CB6E7BC65389ULL, 
            0x4114E56918275341ULL, 0x6EE376E4AB24267EULL, 0xC21EA0823460C16CULL, 0xDB78138160818235ULL
        },
        {
            0x443C46834B08B2DDULL, 0x89007608CEF52440ULL, 0x27C25C6630ADA9AAULL, 0xCAEB45372740A9B6ULL, 
            0x57174B2C557E2373ULL, 0x68CF53E3502CD862ULL, 0xAC045F89C9720983ULL, 0xCA309D30EAFCFCF5ULL, 
            0xA26B3A8618721E1FULL, 0xF6B8225B2F1A8E18ULL, 0xD29114EF4919FC5FULL, 0x02E4A2C348CBBA4EULL, 
            0xD9A641AF88034C6FULL, 0x475ECE30BBD39F9CULL, 0xDD4EF65B08303E9BULL, 0xD3AB493EC536723BULL, 
            0x6E2E76A4593A8B88ULL, 0xE89EE378A7DF65CFULL, 0x664CEEE15DC945C4ULL, 0x5B197F4ECCB0FF4FULL, 
            0x1D16A90C8190237CULL, 0xD9192D1736216BF3ULL, 0x5584E033DD0C4168ULL, 0xC74295DE5B7ACBD1ULL, 
            0x07B1689CE2990241ULL, 0x925C08F1DA4EC3DCULL, 0x92C8F975F713F730ULL, 0x7A08BA8F8C6E7197ULL, 
            0x613E9EBD4B4B4892ULL, 0x795173D724FBC016ULL, 0x5C5C4436324D33F8ULL, 0xD49558EF0D03AC48ULL
        },
        {
            0xEFFF1249EFD9479CULL, 0x7E7C7D7ED4946561ULL, 0x132932E206BF7B28ULL, 0x8FB74C243F88EEB1ULL, 
            0xF5AFC0FFD9F7655AULL, 0x6647F76AE4E8AA94ULL, 0xFE0EE464FFF9BA5EULL, 0xD9C36C2452536197ULL, 
            0x010E6B9E7B97149FULL, 0x96A46A5F6A17756AULL, 0x10AF27935511571EULL, 0xD976C1920AB1A08AULL, 
            0x6A2DF0A722AC3C64ULL, 0xD7A0B0AC84127A6BULL, 0x83A961F827681B8AULL, 0x3BBE1FB2D9896803ULL, 
            0xA2282D4FDF33EFDCULL, 0xE6349A1B1F3A6DB4ULL, 0xC131F6A121A62098ULL, 0x3D95F7964FB6B2F1ULL, 
            0xCDCA76D462E2998FULL, 0xA2B8CEC1953F9DC7ULL, 0x380990CB48A1736BULL, 0x2F493D5DB960805FULL, 
            0xA76939EF7FA479FFULL, 0x859492D85F0BD9DCULL, 0x59E0931D5A066379ULL, 0x2F6C948AB535F7A7ULL, 
            0x72F33B5FF62E36C6ULL, 0x5DAA50C8C7C6BF5DULL, 0x8835E53FD77D5E05ULL, 0x694DFC267F60C457ULL
        },
        {
            0x6CA03676583A524EULL, 0x9D97A0E9D8FB64C6ULL, 0xECAC4370DCAAFC2DULL, 0xAEE74EA4C31765E2ULL, 
            0x12124CED2E540510ULL, 0x476365A66AEB443AULL, 0x9C2ADAF882C83DBEULL, 0x0FFF2482CA71B22EULL, 
            0x28E8792CF8694710ULL, 0xE02580A22375BE45ULL, 0xBF8C0656632C9C92ULL, 0x3D310C49298A3F0FULL, 
            0x6C4C662B1516B80AULL, 0xB57438F4F2BA87AAULL, 0xB8C4AEA2A1D1ABCAULL, 0x90A8C3B672E501B2ULL, 
            0x36AC2B188D0944DEULL, 0xED658A08E5561056ULL, 0x5597B9C0BD70A74BULL, 0x9F76CCE56CD87320ULL, 
            0x98C07E2A66434700ULL, 0xBC8B3574BD3840F7ULL, 0xFBBFA7DC64279BE8ULL, 0xF59804E6CD84F745ULL, 
            0xF8DB22EA090547B3ULL, 0x8B7122A3256EC30DULL, 0x40137419F4B47DE8ULL, 0xFBB6CB473DC3E1EFULL, 
            0x5135F2562F705B39ULL, 0xF0D56AD6E4CC9399ULL, 0xFFA8D931B52286E3ULL, 0x69BCE70AAFDCB3D9ULL
        },
        {
            0x9BA4AC7E0FA201CDULL, 0xB52EB9CE2F9A0854ULL, 0xFF23A9FF80104258ULL, 0x1F283B37A1B51CB6ULL, 
            0xD48D5EC7E9A60FA9ULL, 0x5A2FF9E169EBDD5CULL, 0x31B63EE0D3E66CAAULL, 0x96773CA52F8B5FC3ULL, 
            0x215960141203B870ULL, 0x482F1FBCB9FABA3EULL, 0xC719A9243263A95DULL, 0x8482911BCCECEED4ULL, 
            0xC1A1EF6B0FDC0877ULL, 0xD12552AADF3B1926ULL, 0xC1BD1A5760F00C3DULL, 0x06CDA52CFB05F327ULL, 
            0x1248D39F339D2B86ULL, 0x377529B123D24F0BULL, 0xF2FCDA6D02ED2C4CULL, 0x99400211D7C424B5ULL, 
            0x4ED379FBD8354F03ULL, 0x04B1F33100AEB56CULL, 0xB0E1D57810F4B1BAULL, 0x6C3FB8B136071ABBULL, 
            0x0E4D2B31339E434BULL, 0x4BA9BA98D38C6E97ULL, 0xEBF2A6F5D89D4FC5ULL, 0xE614D7A2117C30B8ULL, 
            0xD0E4FA5AC05414F7ULL, 0x034BBA8A37A28620ULL, 0x27922A2D9D150C46ULL, 0x9E12395063220A08ULL
        },
        {
            0x1738C45EFC3EDB2CULL, 0x5779FB49AB2BA124ULL, 0x2353B9ED8364CCF0ULL, 0xA31C0EFBB3CB6A84ULL, 
            0x5B7C50E5D964C6F0ULL, 0x037F07F220BCDC16ULL, 0x2E37681F46BBC203ULL, 0xFE5E5D41D08904BEULL, 
            0x4C5384E6BF759810ULL, 0x7AC822E7D7475B8AULL, 0xC92D2114D3DAD4BEULL, 0xAA9B498F2B15CF9BULL, 
            0xAD41381371188469ULL, 0xAE8AE888BE6D4E0AULL, 0xFD4B8D9EF5194539ULL, 0xDB5C72D2F0E251CEULL, 
            0x08DE4E35B58DA095ULL, 0xA3204CDD4C3BD3CAULL, 0x1431A68EE63773BEULL, 0x75654ED2AB1B081BULL, 
            0xBC290FCCB35CC399ULL, 0x6A73E13B06AA365FULL, 0x973DFC1BD8A407F1ULL, 0xB588A529E8E00818ULL, 
            0x595DF8DDEC819922ULL, 0x0C4FB682B696880BULL, 0x383DE58A9A0C3B1BULL, 0xF90C13860A473721ULL, 
            0x82B13CC92A00250DULL, 0x665EDB52F7467250ULL, 0xE111AE4694FCA709ULL, 0x8DAF0F5AF36377EFULL
        }
    },
    {
        {
            0xE728059840B6DC68ULL, 0x9FEF3A88DDF131F9ULL, 0x31C1119412A5FB80ULL, 0x393F0D30F0C464ACULL, 
            0x2638CCB91423FBC1ULL, 0x1D506E5B90D3AD5EULL, 0xB48113406373D31AULL, 0x11AAEDC30944D718ULL, 
            0x5F26A0B241012E41ULL, 0x1F439B20C960E0CEULL, 0x5949ADDE84A10A08ULL, 0x6A9A2400273A7BC6ULL, 
            0x626BD8AEA123B844ULL, 0x2852B52540AA426BULL, 0x542110DFC2EE1526ULL, 0xBD9B779B1B5E76C0ULL, 
            0x841DEF2706ECCFE7ULL, 0x2507AA5848C50594ULL, 0x0948927A0B9853E8ULL, 0x35FC467C12B18864ULL, 
            0x1C802E0BE5A5F3BEULL, 0x53F17EB5FE9B886CULL, 0x561D93C1A11E6533ULL, 0xAD300E5FB751E88AULL, 
            0x92DD9E86F820BC16ULL, 0xA157DBD28F2FA6C0ULL, 0xE6721368080C5D49ULL, 0x831B216169C1017CULL, 
            0xC3516CBF7591F3F4ULL, 0x29EBA270F9BBDC70ULL, 0xE508CD6371605E72ULL, 0x19D7FAF246AEB853ULL
        },
        {
            0x85168D370E2377EBULL, 0x9584CBA067AEC932ULL, 0xBB5B93FC1D45AD52ULL, 0xF62C09DE95A07B53ULL, 
            0xA26426E7096DC310ULL, 0xB155C9D7638FEFC7ULL, 0x8E58229EE290260AULL, 0xDA83A5C0990C79CCULL, 
            0x40674E0685BEBBB5ULL, 0xE7C72B26169C6FCDULL, 0x560D293147668B1BULL, 0x9C43467AEA2AD9EBULL, 
            0x290EFB9028A7A872ULL, 0x060AFE56A9797D3CULL, 0xC4A6A23880DDBA3AULL, 0x01AE83B0D27D5325ULL, 
            0xDC7FC7DEF222EB19ULL, 0xD2A1CC960D220794ULL, 0xFCF29028ECAC4606ULL, 0x476FFD76AB8181A3ULL, 
            0x482D33CFC2F57AA5ULL, 0xEFF75A71C6618966ULL, 0x784866D5C947EC24ULL, 0xDCF9708AABED5AB9ULL, 
            0x546286A5C0EB517DULL, 0xAFB263EA51752378ULL, 0x126A11D06FBF6F83ULL, 0x791DD76F2525B482ULL, 
            0x7D2EF7427B4B5735ULL, 0xFAE985EFEB8BA258ULL, 0xEF2F0E46A6142D87ULL, 0x7E5BE221061E6A4BULL
        },
        {
            0x39E4EFE63BB0C48BULL, 0xFD9BB04A472D0B39ULL, 0xFC867C599322190FULL, 0x46F3CA019E4D9085ULL, 
            0xB3D71336382347EBULL, 0x2853E9341D740638ULL, 0x53D967B40FB1E1EEULL, 0x36D75D34B8CD983EULL, 
            0x3066F0A78683F735ULL, 0xDFF0531C5DCB5C62ULL, 0x3C46ECC88429D6DBULL, 0x80F19CD08415C0BBULL, 
            0xBC335F6454FA730FULL, 0x8CCC011F48E6B7F8ULL, 0xF21097CBCFCA2C10ULL, 0x498193FD9F665752ULL, 
            0x5F8B83E27CD03D54ULL, 0x6CD610E8A447D292ULL, 0x9883D7BE5FCFCF5BULL, 0xEC374D4825342EB0ULL, 
            0xEF036DDEAF72A056ULL, 0x221480ACDE4D365FULL, 0x76CB4D8EE3FC825DULL, 0x6E3E1E394772A036ULL, 
            0x3CE476B27C949701ULL, 0xEAABF1C34EC5143FULL, 0xC638936A8EF2CBEEULL, 0xABE7E2D0649C0A71ULL, 
            0x6B2CAAD474A0F281ULL, 0x667D803B6C0F4371ULL, 0xFB2819FC577B9CE0ULL, 0x897F0D170FDB9817ULL
        },
        {
            0x01F35543A857FDA1ULL, 0x068DE39C5169E3C8ULL, 0xFE3C86122A80456CULL, 0x10A6CFA82A180144ULL, 
            0x175E30338DEC5E74ULL, 0xD9E9DE48C617B0A9ULL, 0xB445D9F12683F927ULL, 0x300F740D5A3CD23BULL, 
            0xBB4ED9293EAEE095ULL, 0xE99D91053B608621ULL, 0x1F19C1CCE6DFDAE4ULL, 0x7EF3690C141EF90CULL, 
            0xFF959406DD66DF0FULL, 0x84E3BA8EBCB02039ULL, 0x9A26536A968274D6ULL, 0xBF4D95DC7FDC3B76ULL, 
            0x81A023C8100E8F3BULL, 0xD0D6AB6DC72FB827ULL, 0xD6B3D72FB904D466ULL, 0x27FB90749A66AA03ULL, 
            0xAA5093B9887476B7ULL, 0x8E8D118140A9591DULL, 0xE4EA86F80B4C8D6BULL, 0x7D709E877EFA465AULL, 
            0x3047EC7504699B75ULL, 0x523544A524C995FFULL, 0x4021BE3817854CEEULL, 0x959DAABC983BC863ULL, 
            0xBF06AEDE1254C7DAULL, 0x253F6122A9B8022BULL, 0x53AE71A1AE8F2D51ULL, 0x03E58DC3227B6752ULL
        },
        {
            0x0AABF82043081150ULL, 0x2A72E02D6B55C2E3ULL, 0x1717DECDC93A3782ULL, 0xF50F04734D752299ULL, 
            0x18BAF4D823E4D757ULL, 0x207777C2820D96F3ULL, 0xD494D9E0F8A6E9A1ULL, 0x5353EDA8C22CA638ULL, 
            0xA97CD69FCB7AE0C8ULL, 0xD3B022EFABB359B2ULL, 0x7C7543A6A639D287ULL, 0xDA32B4A2B7A6AAB7ULL, 
            0x3868D44895D94942ULL, 0x3F8A690168784A4AULL, 0xC812DAC3DADB1882ULL, 0xEE39745400CF1235ULL, 
            0x920E390003552EE7ULL, 0x5BBF77E32E749D33ULL, 0x161CDAD348B58D0AULL, 0xF240083EF6A93E60ULL, 
            0x63A3C03515580B9FULL, 0xF906E41D00902A32ULL, 0x69EF6EEA92183871ULL, 0xEA1F15E3BFE0A5B7ULL, 
            0x8AAEBD5D6FEE50C5ULL, 0x5EE2F581492BC1F1ULL, 0xEEB3313F2C839637ULL, 0x62EB665CB95B6362ULL, 
            0x59E2662A960A55C0ULL, 0xD00C703D7B9C1719ULL, 0x172F986E1901CB3CULL, 0x54FE87CD4671DAD2ULL
        },
        {
            0x6B09BB4720435B15ULL, 0x9EBB57C4095A3D12ULL, 0x4D8D2129EC891876ULL, 0x4A5C0AD5A01B0697ULL, 
            0x83DBB85369A9E549ULL, 0x103F8D95C4C00342ULL, 0x909320A5B88789B9ULL, 0x03DF84DBE7ECCBD8ULL, 
            0x14840D3C2ADD482EULL, 0xB2542967916B3B66ULL, 0x523F9DFE3F183B22ULL, 0x1CB86A184BDABA13ULL, 
            0x2F0A11982D288CBFULL, 0x05AF7029819303CBULL, 0x9C3766B215CE6B05ULL, 0x3AB5E92C543AE63EULL, 
            0xEB836B7B0AD75DC5ULL, 0x33F6E66C4335797DULL, 0x65F7BB2FA9ACA811ULL, 0xA5DDD2A915F4E138ULL, 
            0x2581FE833CA7E80CULL, 0x992455E68A704678ULL, 0x2CF568FF06C0B5F7ULL, 0x90257E29B444EC0AULL, 
            0x1EED1458815AFA5CULL, 0xAC29B9BC1C444921ULL, 0xCEAF189B7349CE10ULL, 0x6151A2F77CC03E15ULL, 
            0xC2C915C9A097C33CULL, 0x709E41C5EBD2B080ULL, 0xADCCE0872CB5F454ULL, 0xA954ED10B9D67BA8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseBConstants = {
    0xF74F6899355378DDULL,
    0x7EC2D7FD83BCD96DULL,
    0xCBAF9C0FFBB595D8ULL,
    0xF74F6899355378DDULL,
    0x7EC2D7FD83BCD96DULL,
    0xCBAF9C0FFBB595D8ULL,
    0xEF2B09EF05D9E3B0ULL,
    0xA6647A7FA5A8196FULL,
    0xFF,
    0x6A,
    0x2D,
    0x66,
    0x16,
    0xEE,
    0x5C,
    0x8D
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseCSalts = {
    {
        {
            0xCC5984046EC392E2ULL, 0x7240602F7346D009ULL, 0x0B03A87FAED59A92ULL, 0x0B18A1663389453CULL, 
            0xE02C996F60287FC6ULL, 0x9CC79C430EA13D2DULL, 0x7D43E4AC4FD0F717ULL, 0xF49C113553489EB0ULL, 
            0xA9C831D7A94D12DCULL, 0x58F2BA6883E6E3FDULL, 0x74341B36DD026B9AULL, 0x4D4870862311AA89ULL, 
            0xEFEB22818F222A49ULL, 0xED0891E16831A118ULL, 0xE448617020266B81ULL, 0x29ACC8B84986AC14ULL, 
            0x1B96B0FA121C4636ULL, 0xE8ECDE22424AC997ULL, 0x9988646DF89E2A0EULL, 0x598AFAAE5E66ACF2ULL, 
            0xB77F37D001CB62A3ULL, 0x963A9AD1AD5107D7ULL, 0x750B178B0691E641ULL, 0x1C3C8FF1758450A2ULL, 
            0xD09DBF4AD1971258ULL, 0x676DC35F3792DE3AULL, 0x9F75724347636FA1ULL, 0x5CE8B28733CF021BULL, 
            0x5F4F5BC440F57937ULL, 0x9923049D7D27C39FULL, 0xAD38DBDF5D51B72DULL, 0x3B9EE0D92DC74E63ULL
        },
        {
            0x1CBBD8F6E20848B1ULL, 0x6628488E61164329ULL, 0x34808BA86BC9CDADULL, 0x4C60235CC593CE0CULL, 
            0xDD6B163DFBED0349ULL, 0xE634A3AC24A6E5B6ULL, 0x57485ACC351FBBC8ULL, 0x12502CCE22F8E0C3ULL, 
            0x8F68550D49E0F7D7ULL, 0x4E9BFBD508140B61ULL, 0x15F1B130FE2900DDULL, 0x297F9EDD2B7B9F03ULL, 
            0xB7596FAE4EE87FB9ULL, 0x181608ED2B98D4C5ULL, 0xD7CAD2E3871ABD82ULL, 0xC9A74668B286757CULL, 
            0xB46611FA11C22521ULL, 0x53AC5FDF2D6D82DEULL, 0x86323F9164A5353BULL, 0x77612AD6E70B35E6ULL, 
            0xC63725530FD19AD1ULL, 0x35F282EA127EBFBFULL, 0xBB6E2BD834BA7C1FULL, 0xA28FB49403DB520DULL, 
            0xCBE5E6A1A63BACF8ULL, 0xB01459BA696740A2ULL, 0xF5A306733260380FULL, 0x3CCB7C0DD6CDE718ULL, 
            0x7864252FB1316F04ULL, 0x8835A28A834C331CULL, 0xC8893CDA8E8C82A9ULL, 0x46FBBB05142D6ECBULL
        },
        {
            0xB214BF87D6738251ULL, 0xFF57B0933BBEA754ULL, 0x8604AF2A764BD745ULL, 0xDF613BCE734252A3ULL, 
            0x9D97E817B5D2BF2DULL, 0x231CB9CAE48C9035ULL, 0xA3EA613FB30755BEULL, 0x0D1D776D5A39CFE1ULL, 
            0xC13EF4CE49B0130AULL, 0x866534AF54664C3DULL, 0x3C0CC72F2D21B918ULL, 0x7BF2833E81F0AFEEULL, 
            0xBCD16DEDC5768D9CULL, 0xEA3FC426A50C914EULL, 0x570A69177890A06AULL, 0x3D2969C00595D635ULL, 
            0xDD05D676C9B25ACDULL, 0xC8674C8D9AE1BE9CULL, 0x2936A61705E51945ULL, 0x9E8A42E49E1352F0ULL, 
            0x82EAFCC277DA67AFULL, 0xF0974249A59EF60EULL, 0x52D1CB011609516DULL, 0xF23E5EDDA6FBCC9DULL, 
            0x74D8D876ECECCCDBULL, 0x108AD1771C05A758ULL, 0xE666F5C8D577425BULL, 0x0A7559BA0979326DULL, 
            0x266A7228216D2D40ULL, 0xBB60220AC99E8E78ULL, 0x27A53B0D8926D6ECULL, 0x142CEA5244672313ULL
        },
        {
            0xFACBD27AF2275EE2ULL, 0xC9C992196F677911ULL, 0x35EFD1456099F90EULL, 0xA92DEA194151E288ULL, 
            0xD2301C74EFFE5482ULL, 0x36D528DC0A8315A8ULL, 0x6DDC9B92C35E9178ULL, 0x58DA6C003B1A61C0ULL, 
            0xD578D92E395209F0ULL, 0xFA1115CA62281D84ULL, 0x2C80300ECA48218EULL, 0x348F19DC4DFDF33CULL, 
            0x5E4278558933059BULL, 0x75DCB1C261A66629ULL, 0x965F00AC98CF48C6ULL, 0x1A8A4F54BE17E535ULL, 
            0x3428AFCBFF08A9F0ULL, 0x9691C0156F08F27DULL, 0xDEBCA1C97E8A6D10ULL, 0x264E49AD615B501BULL, 
            0x5E4D2775E3B32A87ULL, 0x43C367FBD44937D5ULL, 0x35B892281FBD65DBULL, 0x985C23A1C304D1FAULL, 
            0x668F2DD76AB061D0ULL, 0x8AE45FBAE4F58D90ULL, 0x4122094B2E101E65ULL, 0x0CDCFB9EF1A2E4DAULL, 
            0x18B2DC014D924BBAULL, 0xA2363A44169C1D40ULL, 0x9470DCCEC398124CULL, 0xCACD1A872E6881DCULL
        },
        {
            0xFA54FDDC89BDEB0CULL, 0x443262CF03115446ULL, 0xC2C50C201CB2003DULL, 0xC2FA2780E345FD17ULL, 
            0xD56708FEF1E9B51CULL, 0x5D983A5CD1435C3DULL, 0x9AF3FBCF2B0C449EULL, 0x9B6953A4D59C3595ULL, 
            0x02EDC48DBE89B107ULL, 0xC236649D92D96B00ULL, 0xFA422F69A2AECAF4ULL, 0x82746B8CF3CEB215ULL, 
            0xB7F1669358AF16E7ULL, 0x398E506397197835ULL, 0x8D2D57C09DB5A1E7ULL, 0xEC071BC8449C88AEULL, 
            0xEDFC8837C3F27155ULL, 0x136A744D2DB11203ULL, 0xBA08D19CF512976EULL, 0xBC383B539325C683ULL, 
            0x2AE6D723619FDFA9ULL, 0x40830102478F5DC5ULL, 0x37183391AC672B44ULL, 0x1D9D59CB1CD0197EULL, 
            0xB78528CA25466F83ULL, 0x9A817040C2F7EEE9ULL, 0xA367D9C01E82A2C6ULL, 0xB21194C315107686ULL, 
            0xA958123D69AC4088ULL, 0xE708839BC0A442EDULL, 0xA1BA4E10AAD005BAULL, 0xACB527D905E8ADB8ULL
        },
        {
            0x0EB22A74825D6A0CULL, 0xD23883D35BC543B5ULL, 0xB915EABB47B3815AULL, 0x90DFA54C32D3E689ULL, 
            0x38406C7704FDDCBDULL, 0x327CC928DC57ED15ULL, 0xEFB69E07AD344757ULL, 0xA86596792177973FULL, 
            0x0C855E4B68C95A48ULL, 0xAEDA41D39464C663ULL, 0xFB5A5FBD77EAB7A8ULL, 0xCFEE3EED2080BB22ULL, 
            0xF4179E02B653F916ULL, 0xBD1A818333C1DA64ULL, 0xE5FB29987629EF2BULL, 0x99969679414EBC18ULL, 
            0xDCA06C9FB14083D2ULL, 0x961D29EE537075B4ULL, 0x840CC36A8C03ACB4ULL, 0x8165F7BDF850FF16ULL, 
            0x1BF9F817B4B7F071ULL, 0x8F25A4CC08EADE5FULL, 0xC5A40A1A258BE59CULL, 0xAF4CB7622ACA0EF3ULL, 
            0x2A8806C9CE5DA9CBULL, 0x99AE35370BE915F9ULL, 0xC6763D9914434F5BULL, 0xE11447C85EE65495ULL, 
            0xC8DECE1A309E7AAAULL, 0x9E3625B5AE61BB59ULL, 0xB65720E463047995ULL, 0xFDEF0A76798A8FC4ULL
        }
    },
    {
        {
            0x3EC203E8E76CEB97ULL, 0xAECEFB505C6F3340ULL, 0x8BD6F7DE02169A4DULL, 0x0270DB85EF326AB6ULL, 
            0x1222EC2F46FC86C7ULL, 0x7C40B3E57DA074C6ULL, 0x6A5CA9E7E0D6791CULL, 0xBDB99C69575C3D70ULL, 
            0xDA91E5A84EA4F0B0ULL, 0xC90C821B6A73D1B3ULL, 0xD64FBFD3BCCFE6AFULL, 0x70C6F260E7361B4BULL, 
            0x5D2F1D01589C8B20ULL, 0x790BF093B7589BE8ULL, 0xEE4B4D24EDAA5035ULL, 0x319ACDB51F5A61E7ULL, 
            0x05B4283C30307339ULL, 0x6C5336F3CB6BD31FULL, 0xFFDE9E0F2A68C5FDULL, 0xEEA4AD93C34BD0AFULL, 
            0x94C5C90843B2BA49ULL, 0x9F6BE5B5996965E6ULL, 0x249DA4A662033FCDULL, 0xA57F35F3D020CFC2ULL, 
            0xB351356F10C49DFFULL, 0x581D7C0F399B01F5ULL, 0xEA2B8ADBFF9D5361ULL, 0x6B8569EF943FFDFDULL, 
            0x1812BD3108D9E5F0ULL, 0x84CE84EDA098B7E4ULL, 0xCB1A2BDBC4DE57C7ULL, 0x20C4CA91E7EE148DULL
        },
        {
            0x699AF54901EEA162ULL, 0xC2A15F2EE53CFF04ULL, 0x1F202137558397CFULL, 0x3903EF1E0A1B019AULL, 
            0xDADD76AFDA332688ULL, 0xB743BEB1D0137402ULL, 0x03D7A88918F2A1E8ULL, 0x382159975BBC4661ULL, 
            0xC15FE63685BBF543ULL, 0xA96786471F2464B5ULL, 0x41CCDDDE592E78A0ULL, 0xA0DF03713A32B973ULL, 
            0x1076C16F06D459CCULL, 0xD6B4D8C5897CD37DULL, 0xB9421263CD22A9D4ULL, 0x6689EB23D5F4225CULL, 
            0xDBDB4690D3FACC3BULL, 0x766E0E21E91EF36DULL, 0x6953CCF9678610EAULL, 0xE01A849AC8B61E48ULL, 
            0x6C0D04CCDFBB3C2EULL, 0x427DD3D92BD60025ULL, 0xC312A822E1B05AC0ULL, 0x149430591C086A54ULL, 
            0x160A7D113E7795A3ULL, 0xCEC9E0F718AA3E02ULL, 0x193F9B751686B296ULL, 0x8A3152FBC893716FULL, 
            0x119B6268371EBF90ULL, 0x8BC390A5200FC65CULL, 0x24E045C477A78F44ULL, 0xFD731D91205616DAULL
        },
        {
            0xEE4E9ADF0DCEC5E1ULL, 0x84B891176E2F6770ULL, 0x48AE123838365AE0ULL, 0x9F6F67BA32845E26ULL, 
            0x5D6365A469D9E1C1ULL, 0x2D92B90CFD8C3D0BULL, 0xD5C5A3C6708C9B5EULL, 0x0D30BDAA4B23B965ULL, 
            0x1A7908F34219EA58ULL, 0xE68B2E6D91B2FFAAULL, 0x47018FCF6919AA8DULL, 0xB3C331ECBEBE2955ULL, 
            0xE97C58A49859E6E4ULL, 0x4DD49B3B823EA505ULL, 0xF5CF7DF2C74861ABULL, 0xD9163C70F3D904D3ULL, 
            0xD7E172DA8D53C92FULL, 0x9A5FC2F529D40E64ULL, 0x5E2FA8807A2C4EB7ULL, 0xC5D723A8935EF049ULL, 
            0x06C028DD6A7446C4ULL, 0x2EFAA08C360F7367ULL, 0x8A414935AAE01658ULL, 0xA6CEEE9F78CB49A7ULL, 
            0x3699B4287A1DF956ULL, 0x78AE7A08E211CC75ULL, 0x1794109FB23800AAULL, 0x3B9B8B7B927EAAA8ULL, 
            0xDD84F2E58FCC53E1ULL, 0x7B64F7827A31F09EULL, 0xF3AE6B8F4A19F32CULL, 0xABE0F3CBF6B87E40ULL
        },
        {
            0x4314BFDA2F5EFB26ULL, 0xAB5063D1751A8A0AULL, 0x9895C53EB25E23B4ULL, 0x8F26D3148842CD48ULL, 
            0x6945C5F48E777E20ULL, 0x045825F51752C041ULL, 0x6B4E6C0B9E8B9068ULL, 0x46323294B4E5AA1BULL, 
            0x980EA1C09B1C31E2ULL, 0xA9EDA0D2D7DE91D3ULL, 0x2E60028A62F51903ULL, 0xE3A9F2377AD84DD4ULL, 
            0x6376C411976007EDULL, 0xE0F18BCE07E8AB42ULL, 0x0B51C23F6CFC1119ULL, 0x4957805E70CA5408ULL, 
            0x6FF6D74FF27DED60ULL, 0xD13873CB4A735193ULL, 0x2155AE0957F121B9ULL, 0x1A333BF45347C86EULL, 
            0x896A779D865EEABAULL, 0x43747D447BD0B136ULL, 0x8D2D84D59B306284ULL, 0xA42B046DF90758C6ULL, 
            0xBADE10D7AB22BBB4ULL, 0x951F2F0A0FF2C049ULL, 0x6A60E59F2E338C95ULL, 0x7DEF3ECEF322C9A7ULL, 
            0xC9C1811AF0D1915DULL, 0xB5D2CA85755CA797ULL, 0x08F8E0E261B540B7ULL, 0x590445744E2A349DULL
        },
        {
            0x24C7852730E07D2CULL, 0xE7AD5D1A8562D0DAULL, 0x544B77E4E8CB022CULL, 0xF58199454D1CA26FULL, 
            0x9B5D481CFCADCFD3ULL, 0x19D4CC8B6B24AA75ULL, 0x68D79D372C7DF1D2ULL, 0xAAD082CC594D7A84ULL, 
            0x84E7846B08FBBCFCULL, 0xFAC297113DA260C7ULL, 0x49DA3DAC9A29484EULL, 0x9E7C95038C55CCEEULL, 
            0xA8AD602DD6FCE400ULL, 0xE6C45B52C93D88E9ULL, 0xF5E733620BDA0EE8ULL, 0xC91D1E24160F9317ULL, 
            0x0B3A054C7F500EF8ULL, 0xBCC884344E66C260ULL, 0x64DBA8D8386EF0EBULL, 0x1FB44A79AA6401D8ULL, 
            0xD9D3164B4879F96AULL, 0x7D0E8B29A83BEF0AULL, 0xC667BE98D3D2993EULL, 0x8BC5081042293702ULL, 
            0x9938E7D82EAB0D33ULL, 0xA85BCD3493298375ULL, 0xEEA4F134D8F0B29EULL, 0x181E1C6FD7213085ULL, 
            0xF2AE1CBAA35EB990ULL, 0x453525A12ECB4C0BULL, 0x332B8DD1EDA4D126ULL, 0x0624E1EEC83D860EULL
        },
        {
            0x4E59686A08AE0E74ULL, 0xA29F1F61835A9D2DULL, 0x12660BA672DC9504ULL, 0x23172DFE5F6A4B80ULL, 
            0x9C2321DFDEDB307DULL, 0x7BBAD77DAD8ED23EULL, 0xCADF5E70283AC6C1ULL, 0xC10481DAC382BB2BULL, 
            0x101BA6536A5C0D1DULL, 0x5F69B58FEC035707ULL, 0xE43E55081E9BD2E3ULL, 0x12C9C02A7BE668F3ULL, 
            0xF017A81F9D5B272BULL, 0x9641914E074CBAD5ULL, 0x5BB3575013C7AFBDULL, 0x2ADEC20518A1AAF8ULL, 
            0x87550CD6758ACAE3ULL, 0xBD9AB022F068B549ULL, 0xB88B52B31E7E5997ULL, 0xCB5ED227A772DF3BULL, 
            0xDDFF41335E2667C0ULL, 0x3263E79731257BD3ULL, 0x1B6ADEFA589EC41BULL, 0xC6D14FA8C9125498ULL, 
            0x79D4419C49B3485AULL, 0x9E84A7AEF656DDE0ULL, 0xE064CC14353F1197ULL, 0xA4873606A31252B3ULL, 
            0xE1245A1641BABD40ULL, 0x50A814E501255A2FULL, 0x3A893773947EEB70ULL, 0x7E0B98BF6962A94FULL
        }
    },
    {
        {
            0x713A422D14276C46ULL, 0xE45CADEF2F1FD373ULL, 0x5AF60FFC545CA303ULL, 0xCBA9E78804F72AF9ULL, 
            0x597BC072377D6CE6ULL, 0x2430A850AA157B16ULL, 0xD21772564403680AULL, 0x86A3A85A6065C74BULL, 
            0x62CB092469A38A19ULL, 0x4ADF4A302EF4D3DEULL, 0xA4322D4A822796A0ULL, 0x146AA50E9A057640ULL, 
            0x8EC5D955BDB1E11AULL, 0xB6101B8D7ED67E93ULL, 0x8D544677E7D61F7EULL, 0xB724C0994B9D610CULL, 
            0xE252A23EBB6D0B63ULL, 0x3C2D236839430885ULL, 0x3CA490446708ECDAULL, 0x28A70997D6733B53ULL, 
            0x528A1CDBE2287003ULL, 0x9B70E1D10BA88B4CULL, 0x4842068A157B5301ULL, 0x6703C2C744C5BD36ULL, 
            0x059AA2C1FC9987FBULL, 0xB9B1324377979B74ULL, 0xE172E04FB8117A1AULL, 0x77645EE2644D48D3ULL, 
            0x4B227B828FF28425ULL, 0xB525D5F73FEB29DAULL, 0x8EF08C95E60C3AD7ULL, 0x3E06EDC1B37FE160ULL
        },
        {
            0x0F1402846EF8B570ULL, 0x8D56E2F8E9D2E337ULL, 0x441560C2C460CD8BULL, 0x8316FF6E1865FD8AULL, 
            0xF897C26B9B53E7FEULL, 0xEEF52D8BDD4EA534ULL, 0xC98849C609D43CFFULL, 0x8C3D86668B43E446ULL, 
            0xAF7490E6D30664EBULL, 0x9776D520F86A3D79ULL, 0x126CDFE28E97DC5FULL, 0x828C6EF19A8EF153ULL, 
            0x59046B343E0946B2ULL, 0x8EFBECA2942BFC9BULL, 0x249DA7A2E2DB5B48ULL, 0x40CCD395C639CA79ULL, 
            0x0F5F9FF09F2831C0ULL, 0xA8337870FE0F0225ULL, 0xA7584C55F91A274AULL, 0x837EB15CFB006206ULL, 
            0x1544EE35362066E3ULL, 0x5CBD6F186A91EBD7ULL, 0x0F07AC5AE194BF39ULL, 0x820700074E6FF257ULL, 
            0x9C61013FDE67B8FAULL, 0x8C7DDDD1B5D7715CULL, 0x3045A708733281D1ULL, 0x33E295AECB5EE452ULL, 
            0xCFFC5F751F1B37FCULL, 0x12DD48E72F1C369BULL, 0x1734AD4DDD3EA910ULL, 0x4B4C87225170FF31ULL
        },
        {
            0xC55DE8F6FA3060E2ULL, 0x6AE2DAD5EA3C1187ULL, 0xEB1380AA43D44E08ULL, 0x875D9FD7717EB2A4ULL, 
            0x432B3B4AEA214C6EULL, 0x5705C419ACAEEC13ULL, 0x542C811AC2B823B6ULL, 0x071E5E043B8A1B8EULL, 
            0x33E136C8E9B68F73ULL, 0x30C8499418186D9FULL, 0x7B6F10AE43D9F36AULL, 0x742FA48057C6F80AULL, 
            0xE2C3A63A215781BEULL, 0x1BD5A61FBDDE5692ULL, 0x0245845FF0BCBC64ULL, 0xD547B5E261992021ULL, 
            0x25207A8E2AAFD9B8ULL, 0x13CD60A79EE558B8ULL, 0x49D4A09FF1728A35ULL, 0x80993205F8505617ULL, 
            0xB4EF4C40E692A98CULL, 0x515164CE29DE5870ULL, 0xB58D8C853DE49EABULL, 0xB20EBCD4715A77EEULL, 
            0xFBD502F1F7BD707CULL, 0xA2BAB076987F266CULL, 0x555FCACDE7FBBF9FULL, 0x6A552E9F7B04A9D9ULL, 
            0x74493D1AFB5A4F37ULL, 0xC7B34A0A5A6FACF1ULL, 0xB2CE6ECF43056004ULL, 0xE8EE61D309525BD4ULL
        },
        {
            0xA8A537174A1D1166ULL, 0x58D61F4CF59685D2ULL, 0xA071601C9CA1003BULL, 0xF628D1C535DB8FAFULL, 
            0x7EDCF2A00697E4A3ULL, 0x7CF53BC50C993C55ULL, 0x36522EFB19725204ULL, 0x4787DEF0613D77FFULL, 
            0x0C5A7BCA91955FDBULL, 0x1EBA7451EE696DDBULL, 0xB08F86EC5CA6BFF2ULL, 0xF14B9238E6AE45ADULL, 
            0x90F05DB4E046E137ULL, 0x449EC3556FEE848CULL, 0xF234E8E8058CA0BBULL, 0x74CB4841965799F7ULL, 
            0x0DD87F9ECE2FE08FULL, 0xA5DF53B326A2862BULL, 0x5E3DABE0D34CB702ULL, 0x4F2775D9E372EF63ULL, 
            0xE1C9079A14693099ULL, 0x0D358E4D9E585CDDULL, 0x560375E10B8D3041ULL, 0x05D8D9860554B368ULL, 
            0xB6760B60BE212AE7ULL, 0x94015C059716FF97ULL, 0x2558F76F52DD35DDULL, 0xA5CFC80246AEF44CULL, 
            0x49D2438115196C07ULL, 0x8AA06388BB755F40ULL, 0x785008B7F82B8C80ULL, 0x96AE372CECC30FEBULL
        },
        {
            0x45927CD57A117585ULL, 0xA16C1B052D1F20AFULL, 0x006D6E8B3AD714FBULL, 0x5A00DF7A03F33D3BULL, 
            0xFAE682A7D5ED2BF4ULL, 0xAEB198143641AA28ULL, 0x430993F06885151BULL, 0x67FDE51014A0FCE2ULL, 
            0x78BDD6EC3115F213ULL, 0x400851F654C4E5C4ULL, 0xD1C8053A07E54636ULL, 0xE9A1FCA7AB450C81ULL, 
            0x5F252F872655FD5CULL, 0x4B45FC9C4129A0F9ULL, 0x78FD7EC7727F924EULL, 0x39079074A322B065ULL, 
            0x3864949B829A9F9DULL, 0x0B4FA66E1AA865A4ULL, 0x8884457D58850C2EULL, 0xA1DF5EEACF987842ULL, 
            0xB21F986965C87294ULL, 0xB453298D92E49CFEULL, 0xFBA168A79CB7D2EBULL, 0x6DA38D10A9229FB9ULL, 
            0x6CFD0BD8E7D1BE66ULL, 0xAC3989248EE9C704ULL, 0xBB9039A8374D5266ULL, 0xDB277CDCC46FD241ULL, 
            0xC9AF18CF9405A8C7ULL, 0x974DE109E519F389ULL, 0x7100A6FB220925F3ULL, 0xC04E7EDA1FFB9892ULL
        },
        {
            0x4D6CEEE5A624A024ULL, 0x4C281C6A78263B73ULL, 0xD8786749DC27023FULL, 0x9CEE787291070EB0ULL, 
            0x8894E62A3C526138ULL, 0xE599742CA63D1ADAULL, 0x61F050865B017B62ULL, 0xA48CA7B7D04341F2ULL, 
            0x2A3C3622E0ABE779ULL, 0x376B19FFFDC8B0B5ULL, 0x9C51836A2E39DD3BULL, 0x47A8714C1BF447D0ULL, 
            0x8F80D4A4784E13FEULL, 0x3DF48E6E5351834AULL, 0xDCFEFDA34A23311CULL, 0xBCB1D76EDE360908ULL, 
            0xD691EFE53EA28D7DULL, 0x2B872FDA71846C15ULL, 0x8A815A52DB6D77AEULL, 0xF499DA8F58ACBDADULL, 
            0xF64CD4E1B88045ACULL, 0x020FABBF5DE94CEBULL, 0x11205CBD6FEF104FULL, 0x81FB713F86E6D026ULL, 
            0xE0F4C81B96E1CC8FULL, 0x5F854680DF91F805ULL, 0xA19E2B5C0280BF2EULL, 0x135AA9A1106A0BF2ULL, 
            0xA7AAFBBE15672986ULL, 0xA327D94DAD72ED74ULL, 0x40D8ADFAA9930F40ULL, 0x85AFACBBBB71A589ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseCConstants = {
    0xACAB9C011AB763E4ULL,
    0x089290EE777DCBD6ULL,
    0xC66559FB7CA3C1F4ULL,
    0xACAB9C011AB763E4ULL,
    0x089290EE777DCBD6ULL,
    0xC66559FB7CA3C1F4ULL,
    0x865C0B020F3E7170ULL,
    0xA553C650FA7423DBULL,
    0x39,
    0x20,
    0x2A,
    0xF2,
    0x5E,
    0x56,
    0x9F,
    0x77
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseDSalts = {
    {
        {
            0x40A10D6366C3ED06ULL, 0x3A213E66C9F5BFFDULL, 0x711A9C397FCA5702ULL, 0x27FE6DE141563044ULL, 
            0x97F18837603F294EULL, 0x5984A8843D035085ULL, 0x4F141536A53A7EB0ULL, 0x458795235EFC1174ULL, 
            0x59BE4B5727C7C7E5ULL, 0xE8389BC49EE9D4F7ULL, 0xBAFCE8AD09F3D172ULL, 0xA80FC9F1E1E1FD22ULL, 
            0xF955EFC78FA1981BULL, 0x6441D95BDE606A90ULL, 0xA1904C7DFCFC7419ULL, 0x2EAF5DE5A7536927ULL, 
            0x563F92A6CCBC558AULL, 0xDC4A5566ED9CB0D9ULL, 0xBA91D543809B2D76ULL, 0x246515A214388562ULL, 
            0x595CF0C29D1FDA17ULL, 0xF94F9E41EE11AFA3ULL, 0x30852B4BD7D52D01ULL, 0x538DDF15D255D340ULL, 
            0x9672860D5449AE7EULL, 0x5553E862759BB9EEULL, 0x4FCD0AA79BF52F32ULL, 0xA8DEC700FC17469BULL, 
            0x3734AD5BDA648D71ULL, 0xBFB998697088499FULL, 0xA3EEED59014513EFULL, 0xDB60BE6654E97307ULL
        },
        {
            0x4046B3634A74B32CULL, 0xD610595DB17A6171ULL, 0x5ED7CF0D27A50BD3ULL, 0x213244FFB45BE86DULL, 
            0xE7EC4FF856075CD1ULL, 0x8743DE0EEEC30CA3ULL, 0x8B953B5FD60BDE84ULL, 0x647CD05659601A5CULL, 
            0x867F441BC8153EA8ULL, 0x7E7121AF3FA87D85ULL, 0x51B7495EF42C5A77ULL, 0x25C4B494FB64F211ULL, 
            0x8874E40ABB75DEF1ULL, 0x6447888BC666821BULL, 0xC4EA3070145730E1ULL, 0x024035A02B4D0723ULL, 
            0x5B928E9600952653ULL, 0x94362EBB57A02925ULL, 0x0ABA1C3E8E6735B6ULL, 0x167FBB84C0A79392ULL, 
            0x08C435BF3B2707DDULL, 0x8F075497914DAF6AULL, 0x20415D6EE9FA2990ULL, 0x297D1CE175547B24ULL, 
            0x571F28714F2BEA87ULL, 0x5D3DC26C12869ED6ULL, 0x7D3EBAE34ABF6858ULL, 0xCF1C690ABF71403AULL, 
            0x9C649ABC147A288AULL, 0xF8D384271C4D185BULL, 0xBA130A9050E41BD4ULL, 0xDE88B9C1A2DCD428ULL
        },
        {
            0x4FDD82A1DF180A78ULL, 0x2ED46931312A9FA9ULL, 0xD8BC578EEB150F46ULL, 0x40B7EA4CDB9BA373ULL, 
            0x7BB5358B1D9D3D43ULL, 0x875690F1CDCF42C0ULL, 0x067F252D2994F4DAULL, 0xF9C37DA8893F1161ULL, 
            0x3F53B28AC40FC8C4ULL, 0xA520E7B38A2F0040ULL, 0xAB64304B5CE5A9EAULL, 0x199A2CCC9BFA6436ULL, 
            0x44DF70498DF14373ULL, 0x461C4F90E9DE5B89ULL, 0x0B251EB34FC9228BULL, 0x8ADD959167C29ED6ULL, 
            0xED0C000E3C9CAD87ULL, 0x9C111292780199C4ULL, 0x47FD6CAA84994ED6ULL, 0xD7FD615479A65717ULL, 
            0xCA450EE28D7DCEBBULL, 0xF552A5770358E8ADULL, 0x58D51697F58CEA4BULL, 0x79111A89F13C1E8AULL, 
            0xE6F68AEECD81F458ULL, 0x52D1BAA57089A1A1ULL, 0x52D2C6041043C630ULL, 0xBE1DEC38C1412F9FULL, 
            0xCDD6CAFF9FDE6BB9ULL, 0x56CB42D30EC6570AULL, 0xCB4539141CB1C583ULL, 0xE0BE4F33ADDCFFD5ULL
        },
        {
            0x6301C70CC2986A91ULL, 0xC0CDEBFC3BD68F7DULL, 0x38A52305A6BC5A2FULL, 0x112C296BFC4946C3ULL, 
            0x76A95F8EABF3E77FULL, 0xEA9CF4C49EC1C45DULL, 0x26AF3E02CB9FFAA5ULL, 0x528349EA8C22E346ULL, 
            0xD9D1DDED864BAB4AULL, 0xE666969A0C4C2674ULL, 0xEE745BC5AA4B0CF9ULL, 0x5FEBDBE347FCC515ULL, 
            0x0BE2F7254A263DE4ULL, 0x9FBAC4110B393E09ULL, 0xEE79D1465701FAFCULL, 0xD456D2BA7FB9868AULL, 
            0xEB84E167AE4F2B10ULL, 0x848F61A55FE433B4ULL, 0x2F4D0798EB53BF71ULL, 0x8375C21E58B68966ULL, 
            0x4921C6F04923867DULL, 0x423843E2F8EF4157ULL, 0x09BEE797D650F960ULL, 0xBA93AF9A510511B7ULL, 
            0xE149D7E85F5465D7ULL, 0x3D5FD680549D9E79ULL, 0x07A4C21976DA3A05ULL, 0x55A761D5E65BB55AULL, 
            0x89149867CC4116F6ULL, 0x63B034AAFB24C86EULL, 0xD2965C624DC0BBCDULL, 0x7BC4FDFF9C8A86D8ULL
        },
        {
            0x67A5110E7852ACBCULL, 0x6017205AB793FF72ULL, 0x5B210FD567CF5639ULL, 0xEED299CA74C5B83FULL, 
            0x684A14FF5D18684AULL, 0x1F2FE946E5AABB97ULL, 0x406518742C8C15D8ULL, 0xD39FA93688560D2FULL, 
            0xEE39E70ACA8754ACULL, 0xAFA92530373C8890ULL, 0xF8C9D31277FBDB80ULL, 0xF6FE5B49CC0EADC7ULL, 
            0x69E8D6328EA78ACBULL, 0x814D7853702B5103ULL, 0xE5C45527F2A75F8AULL, 0x141291C8BEC02EADULL, 
            0x0B45B94355194703ULL, 0x8CC346CDAC5E863EULL, 0xCBF754B9F7BDA2F9ULL, 0x0943F6B6F3DD740FULL, 
            0x382D829C8FC09555ULL, 0x824A627BF6BD52DEULL, 0x7EC60610800B719EULL, 0xE7E541F196039487ULL, 
            0x74549B70E17B1F7AULL, 0x405EF82C3C7C3E12ULL, 0x5D36668D1FB4F737ULL, 0x4F06750E4D6D1EB7ULL, 
            0x06C95C383B69AC90ULL, 0x80E2A4ECBA4E835DULL, 0x8D56C86C635B8DFFULL, 0x3925EF93B5C5B431ULL
        },
        {
            0xAAA362E474DFFA41ULL, 0xF463FA43501FF1ACULL, 0xD1A17C61DB648CF4ULL, 0x3FF7959127CFF578ULL, 
            0xAC6BDCB47D72E40FULL, 0x06D41BB21A383F1FULL, 0x5C8975C7D9E18D07ULL, 0x46B4CEE443B077FDULL, 
            0x0EC463C20B873B69ULL, 0x0560CF57C0FB12ECULL, 0xEEFA916FFE10D6AEULL, 0xC8AD98F1827D910FULL, 
            0x2E66564405468A88ULL, 0x3C84CE8DECC10678ULL, 0x8C8F04A0F0717C20ULL, 0xB8CEDD2846975313ULL, 
            0xA58750B710933AC6ULL, 0xC49D75E760F1630CULL, 0x454BC932BADD0AB9ULL, 0x8B873960B629D960ULL, 
            0x6C7A15884DB1B64DULL, 0xE5E61EE80B5B1D19ULL, 0x7CAB853EB690E43CULL, 0xDB47DFB5C5ADCDA5ULL, 
            0x5F2DE4A95520058FULL, 0x7FFAAE8956B8D85FULL, 0xCAEA804FC6C6C870ULL, 0x0E62729AA369911DULL, 
            0x72C8E17146873093ULL, 0xE44EEB77106DBC0DULL, 0x5C9C0593D7B37D34ULL, 0xB3084D2434CF42D2ULL
        }
    },
    {
        {
            0x24BDC31622C722B7ULL, 0x76BF0A9657601B93ULL, 0x95812EE364678490ULL, 0x50C402411EA85DC2ULL, 
            0xCABCE1023618B76AULL, 0xF58A413B55D2179FULL, 0xE47AC99F807B40CFULL, 0x744101048A77DCCFULL, 
            0xD8CEC658776291C0ULL, 0x19548AA98DB5BB29ULL, 0xCD282F9E2811AE7FULL, 0x77F511B3AAB7116CULL, 
            0xC996F8EE550DE110ULL, 0xCA8AFC44971B86D9ULL, 0x2D1B200977DE15DAULL, 0x247072D8D7131417ULL, 
            0xD21CAD5E762F55B0ULL, 0x8C87498A5CC70F93ULL, 0x90B4BF21BB6A3F2CULL, 0x93DB4E88ED069A59ULL, 
            0xCA47971E17BC18E8ULL, 0xA1C1AA4D9B4E1A5FULL, 0x672E6D8D7B9E2D64ULL, 0x6D65398D00893982ULL, 
            0xAB3FE124667C19AAULL, 0xDC076CDC263281FDULL, 0xB71AE0D0E0F2FEF7ULL, 0xA4E52937880458F2ULL, 
            0xED396B924E90CE6AULL, 0x876F2DC4770A9F8EULL, 0x543D2E303445D59CULL, 0x6BEB49948F3C79B8ULL
        },
        {
            0x18C7AB8F9FA18821ULL, 0xF12937E1759AE8A5ULL, 0xED4584B98CC01BACULL, 0xD74CD22473333117ULL, 
            0x0EAE86CF19709AABULL, 0xDAA28CE365866973ULL, 0xA3DF1105B96829FAULL, 0xF63DE1984739884FULL, 
            0x13C01689BDCB50B9ULL, 0x11C66429E57530FEULL, 0xEAAC0CEDB4FD9760ULL, 0x5C16F68555B3541CULL, 
            0x82FF51ED6F43A115ULL, 0xEF3D325767E8FF2EULL, 0x082E8B0C0D352D0EULL, 0x76ABD0F97F1EE173ULL, 
            0xDA684C5F5BDB70A6ULL, 0xFFBEE91E1C2DE5EBULL, 0xAB1E22770D5291CEULL, 0x45534C700F59BFBBULL, 
            0x966E433D75FD85EEULL, 0x3CA00D3661C1B384ULL, 0x281CB209760CC588ULL, 0xDB07DECF0E28C055ULL, 
            0xD2F061C2D8AE72F9ULL, 0xA859134A523CE1EEULL, 0x6823E7B421439065ULL, 0xC02611FE2599AF14ULL, 
            0x33360B290C879719ULL, 0x74CEF65385FFC8A6ULL, 0xBCFD35190A6298A6ULL, 0xC33CD3EDF28ADB6DULL
        },
        {
            0xE6070169D4A82531ULL, 0x1993AFB850477C40ULL, 0x10DCDDA8751085EFULL, 0x65C88F62BA01082CULL, 
            0x0CDB6C14EF3F6099ULL, 0x3A0AE1385492EF5CULL, 0x56A6D482759BC5F3ULL, 0xB11B2EB74F1546EFULL, 
            0x189E7772B5FA48CDULL, 0x90389FAB0F158540ULL, 0xF573381A78C9977CULL, 0xEC6D9300706173AAULL, 
            0x0C6434A43C1D8309ULL, 0x2B6575E7538FA253ULL, 0x0FEC3EFF4D35901DULL, 0xC16AD1ADA6527880ULL, 
            0x1B47FC37CA006BDAULL, 0xB3FD47A7E1021376ULL, 0xC59966EC6271C203ULL, 0x2BD4F098AA67E1F3ULL, 
            0x782F2058EBC2B14CULL, 0x5B43979A2847B76EULL, 0xFA4246D3A2739E1EULL, 0xBA2A71B1021FFC8EULL, 
            0xB37638FBCA53764EULL, 0x223A38714F7FA9E3ULL, 0xDC6CC7816E51F7B5ULL, 0xAF221F3EEC7B0FCAULL, 
            0x6511C7CE6A01547BULL, 0x5D003351C0239DF7ULL, 0x48518EDCCBE76B6BULL, 0x1B27A08D6A847B72ULL
        },
        {
            0x821D9B8903B27E0BULL, 0x234FC2DB213949BAULL, 0xE4573407A472A1CFULL, 0x493658BC1F2A5FE7ULL, 
            0x653944B3413864FDULL, 0x513BA52A917520D6ULL, 0xEFE300333574C372ULL, 0x01E642A1471EAB24ULL, 
            0xB8C78477D14B8E8BULL, 0x7AF9A00EE447B3E1ULL, 0x23BB14F5255C875CULL, 0xE52B762F2AA85A36ULL, 
            0x3BBE6EF299BE11BEULL, 0x008A7112F0F06860ULL, 0x54E609F5DFE12AE8ULL, 0x8E6419A7A2CFB8F5ULL, 
            0xD764E468A326232AULL, 0x619279595002FB93ULL, 0xFE0A757E273B4309ULL, 0xBE550D89C01BEC3DULL, 
            0x6437DCA72F762438ULL, 0xBDB556F5E26C4297ULL, 0x4B85423730C07421ULL, 0x5DF1392670A3360DULL, 
            0xC87A80EA95793486ULL, 0x4051EA3B965974BEULL, 0x89CA033CD7F86BCBULL, 0x5B9688B6C540B2BAULL, 
            0xEEA03D19B5DD44F1ULL, 0xAD89C7FDC0C60341ULL, 0x6A0D553D630F0EB8ULL, 0xCE67E64306E83EABULL
        },
        {
            0x05FF443313ADDF03ULL, 0x11007EDD85A32F1BULL, 0x2E323F850F76289FULL, 0x0E7A631A002CD694ULL, 
            0x8F617574AADAE906ULL, 0x29ED85C836F36BC9ULL, 0xCA84EFCC1521F350ULL, 0x7471C3521620729FULL, 
            0xF08D5B4F298BE251ULL, 0x789661C0C62DF585ULL, 0x92FFE2BDAC9CCE93ULL, 0x0B69C922084135E7ULL, 
            0x279982D34615C2ECULL, 0xB8852D2A260EC3A1ULL, 0xAED22DD28CC4DFC4ULL, 0xBDECF71B68265A2CULL, 
            0x8974F3DE77C2D3E4ULL, 0x529BE960BA52F510ULL, 0xED655FA27FEB4958ULL, 0x889BC153230F1999ULL, 
            0x7B31A349B3E43A60ULL, 0xAC0EF76D3D8DD6FEULL, 0x0921118D40AE2D9BULL, 0x409D4B23FB0747ADULL, 
            0x034A3BBA0C78C4D5ULL, 0xA27AF3DC76E3CD0AULL, 0xF71198832F7BC770ULL, 0x355EA3FF83447F2FULL, 
            0x6444CF9719760EBDULL, 0xB5691FB504964A0AULL, 0xBCA90568A86CB820ULL, 0xF549B8BEDC850B92ULL
        },
        {
            0xD2B23DACFC97E366ULL, 0xA5BFF56BACED4284ULL, 0x0DA3B4FBD50F926FULL, 0x0B649010F0BD18C9ULL, 
            0xB505C452FAB0E0C1ULL, 0x009DC2FC97A0FE86ULL, 0x61857743BAAABAF8ULL, 0xE15B626E5D777FFAULL, 
            0x6F035AEE9BBD50E5ULL, 0x595D66D27F66094CULL, 0x17EACE6F4192A45BULL, 0xF177437594A9A09CULL, 
            0x59DB59185DD4B8EEULL, 0x226EA36B8C2235E0ULL, 0xD7B3D94DE17F027DULL, 0x4327DF3299A06EA5ULL, 
            0x62A046C819D0EBAAULL, 0xC7B33DB412ABE895ULL, 0x3D205C2FDAFF0A84ULL, 0x4A73A289AF05C86EULL, 
            0x1E293EE76F4E36AAULL, 0xEC34F3501EC4A835ULL, 0x078820FCC9DBEE52ULL, 0xCE118AA92E6FA281ULL, 
            0xD03EB479F30C1F6CULL, 0x15A42AFEAF5FDFADULL, 0x22D2395DEFF4421AULL, 0xF3407058DBA8FFB0ULL, 
            0x55C0F54ED5CE419BULL, 0x50B9EFB18B0B0A88ULL, 0xCF2CB7DD7CBD06B1ULL, 0x26EB4D0B9B7F265DULL
        }
    },
    {
        {
            0xD889BA63B462DC36ULL, 0x8E2D205C67BE5688ULL, 0x8BE45D1CA24613DEULL, 0x5ADD33B6065CBB09ULL, 
            0x85F1192A8619A377ULL, 0x8751D4FF1CD2DCBEULL, 0x3422BB2973A335BBULL, 0xD3075B59D65CCA2DULL, 
            0x986C4D49E6CD24E0ULL, 0xF8E1C4E2B8C8BBD9ULL, 0xB019D1468C493AC0ULL, 0x96C3A82C18EC4289ULL, 
            0x86933E95C476CDC3ULL, 0x91ED77BC2236A5E4ULL, 0xB002BE8BADD0F138ULL, 0x948271BADC578D9EULL, 
            0x460749D792CD1567ULL, 0xDAA396EBC9FDAE23ULL, 0xA27B2F0FE96CC94EULL, 0x82F06CCF9543EC97ULL, 
            0x57888712A6CBA911ULL, 0xAF68DAA71005506AULL, 0x49983474BC0A9BC5ULL, 0x0760B740A8196DDDULL, 
            0x2E24E33A8D82E827ULL, 0x6BD3831A2DA5EFEEULL, 0xD26A6BD1D35937D9ULL, 0x6DC2CBC9206FCDE2ULL, 
            0x2ED6477DBA5F1970ULL, 0xE9EB08999AE6A203ULL, 0x40D99800E10321FCULL, 0xCBC303F0EA3090E8ULL
        },
        {
            0xBF77E85271259BEAULL, 0xF62216F94D25208AULL, 0xA7B3FF9209DBA95AULL, 0xEDF467C996F94069ULL, 
            0x940D85D6F78209B9ULL, 0x0C5472FDC87D43A6ULL, 0x1F532690E9FC4D73ULL, 0x1F94272FEB2C2426ULL, 
            0xDE0738CB7172D309ULL, 0xB2853215AE900A5DULL, 0x1E9E5E1A09EBADF8ULL, 0xC1D3F822EA427E92ULL, 
            0x42753DCA0D1893F3ULL, 0x0926698F8F5E4D97ULL, 0xAF19937C7652288BULL, 0x3ECBB97814E1BCAFULL, 
            0xD09EA692F35FD7CCULL, 0xD03671D23563EA4EULL, 0x87CD55DF7D9250E7ULL, 0x6129E6278035D295ULL, 
            0xB3032133292CF9F7ULL, 0x32B739E81CF253FFULL, 0x07AAC1D90F783EACULL, 0x64E72ABAD22F130EULL, 
            0xDFA5EC6D1365C869ULL, 0xAA4DF2FBE47CC47DULL, 0xA2FCF33EED2D7ABBULL, 0x9441942AE89CBBECULL, 
            0x0E75CE0F18179347ULL, 0x209ACD350C2BFE15ULL, 0x6931CF95935CDCBAULL, 0x775271A9A9363E36ULL
        },
        {
            0x952A8A760AEBF39EULL, 0x0FFD0A31D488C4DFULL, 0x2A17988C9AB6FD6BULL, 0xEDE7787DFBEC4ADAULL, 
            0xA2F1A4EF3C4F3FF0ULL, 0x5376E7E8C1E7C25AULL, 0xF43CA11E85970D65ULL, 0x8E095424F383FD1DULL, 
            0x01996A19E6085A0BULL, 0x969B6CF3F57D30F7ULL, 0x6F50F3D3D55E9D79ULL, 0x3B64694B1EBA403BULL, 
            0x01A551BE741A0E98ULL, 0xE98DD47AA866F7EFULL, 0x9CD35AFDF775FAEDULL, 0x5183C415AA54042EULL, 
            0xD165DA0952EDCE36ULL, 0x93733193B566E7BBULL, 0x42D226E9BD81D026ULL, 0x468F16588B21C0A4ULL, 
            0x28EA65C12352FDAAULL, 0xD1859162B7576A76ULL, 0xCFDF19668417BDEAULL, 0x315B00C67BC59A04ULL, 
            0xE51E238881A7F254ULL, 0x1C8E10776DAC06ADULL, 0x96706EEBFDCB7A34ULL, 0x128AD05EE621AA4CULL, 
            0x2440AA76ACB549BEULL, 0xD3F1060101328E7AULL, 0xA7B6CA0559BDD582ULL, 0xB2C7BB21E45B93EBULL
        },
        {
            0xFAD5301D98B896E4ULL, 0x5B8E373EE4AC9F07ULL, 0x5AD6594BCC790C5AULL, 0x8E0022B040DD6C3CULL, 
            0x9A42C24FB338B6C2ULL, 0x911711B703E469DBULL, 0x3D450F521900CCCEULL, 0x69B7255065BC11CEULL, 
            0x662199DA7FB03FB2ULL, 0xA25BC615FE598776ULL, 0x38CB845E602A1621ULL, 0xDD19CDF03CF3EA9AULL, 
            0xFCAC4BE7558E4E21ULL, 0xD735B442B18D5916ULL, 0x28494EDBD490C461ULL, 0xA12B02B44DBB171DULL, 
            0xB59AF53FBDCF8B76ULL, 0x807855175D9E121BULL, 0x81D1D3EAF182E1B9ULL, 0xEC27AF42DFFF9AB6ULL, 
            0x1130D68F3F3B262AULL, 0x0BA9F763739C2D44ULL, 0x4A371E9559ED2FA5ULL, 0x26CE2DAD846B741EULL, 
            0x40007DDCA0653EC3ULL, 0x005FAD4A20112B0AULL, 0x345263EED6A242FDULL, 0x73E50F45F11B2990ULL, 
            0x7821883900D64608ULL, 0x6081EB2DCEA0DECAULL, 0x4F2FC56D37D87995ULL, 0x6256AD41735549CBULL
        },
        {
            0x12CCA17139E7468FULL, 0x6B9C48E327A68B61ULL, 0xB962927EB4713E2EULL, 0x51F3898F98C56012ULL, 
            0xF66ADFA06522F0E0ULL, 0x2FCE0B98EC6B1B11ULL, 0x21795450B80F4DD7ULL, 0x7F868A03BCCF3F54ULL, 
            0x248B76B1B59A970BULL, 0x3C18B776B6CED0BFULL, 0x4BE3DE159946903AULL, 0x867C9EAE5EFEBA35ULL, 
            0x1919B1A817572E1FULL, 0x60C40F3D7E861F73ULL, 0x48BDCFF40D8987E0ULL, 0x647BBA90784B090CULL, 
            0x82F567189B715FB3ULL, 0xBB6E58264E3C04B2ULL, 0x5148732134B3307EULL, 0x755E21FB2152F443ULL, 
            0x7E758654E87EB3BBULL, 0x7E2450B9751C8062ULL, 0xE3787DC38832DFEFULL, 0xCD48C30AD08B1AD4ULL, 
            0x8D4B7676CEB77A86ULL, 0x695A76497E9B9EF8ULL, 0xC5040C3720C077FAULL, 0xCEA79897A70A9436ULL, 
            0x8CD018480B92F7A5ULL, 0xC0DC0F1601121461ULL, 0xEE082107F7EDA53EULL, 0x108B480E4E3B80BCULL
        },
        {
            0x8F0AD2437321E85BULL, 0xDEFEF2C84085F4B4ULL, 0xE8F7D232659B1774ULL, 0xCEC6F82FEAF2F6D0ULL, 
            0x131FAB7C74C040A7ULL, 0x249BCD0D8F205237ULL, 0x8FFF655B401DC226ULL, 0x06817DF255F96AF6ULL, 
            0x32843D8E13E70568ULL, 0x5206B43D3C857062ULL, 0xF0010EEEF7A32D13ULL, 0x77827991C61EC966ULL, 
            0xE97ECFB9875E5609ULL, 0xB5FEFC94D6C7C275ULL, 0xD9E508355ED853D9ULL, 0x1C2C4620DBEC5E28ULL, 
            0x96DA27F1F3008018ULL, 0x78C84E49FC0C74EDULL, 0x5A86B46026B1FA8AULL, 0x72E7B372D8BD649CULL, 
            0xBE16D94C106FA6E0ULL, 0x9A5B294FDCCE386EULL, 0x3BB3A65F381AFB36ULL, 0x25728C90ED3B0E04ULL, 
            0x3AF64CC7CF534918ULL, 0x9C0D09344BA77C5FULL, 0xEDDDEBC1BAAA57E9ULL, 0x5E07DBEEED33AF55ULL, 
            0x34000034D90F6F16ULL, 0x38CAAF80B658A149ULL, 0xFBA271929CD183CCULL, 0x176A07E5B2560F6CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseDConstants = {
    0x1B1B7BFC151C9880ULL,
    0x4DEA6E33C1CA995AULL,
    0x89E735888EC8EA14ULL,
    0x1B1B7BFC151C9880ULL,
    0x4DEA6E33C1CA995AULL,
    0x89E735888EC8EA14ULL,
    0x687DDCDB4CDA3C68ULL,
    0xEDCB590E3A29BE0EULL,
    0xFE,
    0xF9,
    0xAB,
    0x37,
    0x82,
    0x15,
    0x02,
    0xF6
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseESalts = {
    {
        {
            0x8E9B96DDF33C8B87ULL, 0x5BD6BE9FAF9BBB53ULL, 0x8E9EC7AE7E37EE2EULL, 0x2929F21F70F52B31ULL, 
            0xACBAE695601F9A66ULL, 0x87796D73C0F69683ULL, 0xE88D481651C23A14ULL, 0xADF00C4080161290ULL, 
            0xFD77A18E068904BEULL, 0xE6B1FC311DD1E6B3ULL, 0x1EDBEE7B1472C2B4ULL, 0x943697F425D16D19ULL, 
            0x994A9F33024551C9ULL, 0xA6123CCE35749DA7ULL, 0xF19062125D1333A2ULL, 0x424BD63CBD7E0ADFULL, 
            0xF806F9042B3ADE45ULL, 0xD3E807E7EDF44877ULL, 0xCB459EF565DB2AD1ULL, 0xF4011B7448BDDBE4ULL, 
            0x7C8D2FA7448DAF46ULL, 0x7D5455816134AA2EULL, 0xABDD0C07F7D6F9C6ULL, 0x225A9F4229146654ULL, 
            0x08BEF98B665F8446ULL, 0x2E8E3B17B12526BDULL, 0xCEAC73B7183691D3ULL, 0xACDF4078AF718511ULL, 
            0x010A42FB88E4B960ULL, 0x4E936B24F8869906ULL, 0xBCADB231F60655FCULL, 0x27110F542D57A724ULL
        },
        {
            0xACAD897B19735717ULL, 0x248291B613B507C5ULL, 0xC03E6313EDC0EBD4ULL, 0xE8210385296FCF51ULL, 
            0x45A00D48BCBA7380ULL, 0x3259B43296580E88ULL, 0x866063E2B14810AEULL, 0xDF951EEB5D972A1CULL, 
            0x4484963AF79795E7ULL, 0xB21ECB96E1AC16C9ULL, 0xD65D5C18A8D66920ULL, 0x097D8294B156C73CULL, 
            0xA825CF600808E661ULL, 0x45743B50DC0A1850ULL, 0xC798DEEBC885B58AULL, 0xB1E9123FB4FF2A32ULL, 
            0x772162BF02D646CFULL, 0x160BD206C82BE05EULL, 0xD5BE99E43988DB9BULL, 0xCBE0FD23F8891AF9ULL, 
            0x3C1A1C9D3472BB09ULL, 0x80C6802273356F81ULL, 0x5BE890FF436441B6ULL, 0x2627AE05962DE419ULL, 
            0xC2FD67E084BAAB9AULL, 0x70476646952E3BFDULL, 0x3E32EEDB24AA568AULL, 0x05AA7AD2FAA9DE2EULL, 
            0x7E577F9A88EE3579ULL, 0xF5A707C75B726BAEULL, 0x1277AA45CDB84D8DULL, 0xF6C62039549A69E0ULL
        },
        {
            0xEFF7FC1382A3AC17ULL, 0x7E987180AF1D4D4FULL, 0x515EB6561D670CD9ULL, 0x434A32137A2A85A8ULL, 
            0x07F5E3E0F74A9869ULL, 0x9D5B52FE8F6E7573ULL, 0xBDA6A959138E3C1BULL, 0x14CA53E253F6462DULL, 
            0x8CC0A8A25EF3E7F7ULL, 0x8F41E9AB30D9C031ULL, 0x7F19E142CF9E4B70ULL, 0x00B5B9549F6FD6F9ULL, 
            0x522F18AF60C1F2FCULL, 0x8A8ECABACD7B01DCULL, 0xA266FB6732DD39EFULL, 0x901815421AF40B2DULL, 
            0x94A2E3A594C81A2BULL, 0x798A0FBE6E3F1E11ULL, 0x38E10E06D8DFAC76ULL, 0x2E91D9F01B245A4DULL, 
            0x524CC429AB3B77D1ULL, 0x86E23AF3A93E44A5ULL, 0x67582D13DEA11CFDULL, 0x4AF9821895DEE403ULL, 
            0x4A0341EC5E6C3964ULL, 0xEA27A127E9D4373FULL, 0x68B14E8CBADC6493ULL, 0x76C6315B6FD8ADDDULL, 
            0x234C1669CDFDE3B9ULL, 0xFE721827DAFF509AULL, 0x14CB291E64284F5FULL, 0x6FFF3499B20B73E2ULL
        },
        {
            0x2E0E550FA7DE9DA3ULL, 0xFCCF732527C4B073ULL, 0x17BD60719F02DFD4ULL, 0xC1E0925A025CF815ULL, 
            0xE518BCBD366C3CF3ULL, 0x41EC9C97051F753DULL, 0x95A4B90F3BEB24E0ULL, 0x021D5C8E323CF1BCULL, 
            0xB3131889FB322013ULL, 0x2DBF144D0B3B8ABEULL, 0x64594703DC5BF1B4ULL, 0xB8120BF3A9617817ULL, 
            0x02435D3892E8741FULL, 0x7781FF057DA29125ULL, 0xB6A67EB9C43B3EF3ULL, 0x02D25A4DD0DE24ECULL, 
            0xE5D9B2C5C39E9391ULL, 0xC963163B0B39DA87ULL, 0x8FFC1AE21D5AAC53ULL, 0x4A5BFE4F970EDB33ULL, 
            0xBFE9DE6C1C6DECC8ULL, 0xBE551AD61AE16008ULL, 0xC1086973CA29007BULL, 0x22F28F10734E60CEULL, 
            0x57C45643E0277DB2ULL, 0x825E46DB90DC0607ULL, 0x402376D3FB716B78ULL, 0xFBE12F8A4010C039ULL, 
            0x3331BFE67706B13FULL, 0xC143F5FEE1704138ULL, 0x525C087FC6387BBDULL, 0x08094FEB165DE988ULL
        },
        {
            0xE4B27D3DA8203B82ULL, 0x6D91DEEB90E4B6ABULL, 0x27C22CB2EA3B14F9ULL, 0xBE464352B4845A27ULL, 
            0x028CD30C66798A1EULL, 0x03386F5294A18742ULL, 0x76E084137FB72532ULL, 0x32310E5BF7250E85ULL, 
            0x6ADFC69EEC7D5081ULL, 0x5F800E02227B8E25ULL, 0x90E72C456434C248ULL, 0xF313C2A8F4A1F792ULL, 
            0xBD72379AF7D92C67ULL, 0x3F960E74C55E8BC4ULL, 0x59FD1A1B13B9346AULL, 0x96D1183A7E576DF1ULL, 
            0xCDDDBE0C29999D06ULL, 0xA719C71275E06502ULL, 0x657BD8134B9B82EFULL, 0x21AC413FCB16BB68ULL, 
            0x8B1F81AC5F1FF5BDULL, 0xED752706A513A3C9ULL, 0x87FF2F0A7BB18D18ULL, 0x9595420CD98DD1A9ULL, 
            0xC4165537F8D77850ULL, 0xA3676B6628C109FFULL, 0x54EFA3381020D79FULL, 0xEEEF8A8251407822ULL, 
            0xE75098445613E715ULL, 0x9747B197D82E14D7ULL, 0x4098FDDDEABB3EF8ULL, 0xD5B0EE1FA690D37FULL
        },
        {
            0x197CF8B61D7CC4C2ULL, 0xC74191F827D34083ULL, 0x44DC4E6B37501A75ULL, 0xEB433E94C4D5DEEEULL, 
            0xA2F22A67E0B969F1ULL, 0xC31A8C1AAA76C2A0ULL, 0xFF6073AD838BAC01ULL, 0x0EA8F6607F8B9F15ULL, 
            0x118020FF0917968EULL, 0xF70FDA96C8B7A1CDULL, 0x65BD78AA9C45186EULL, 0x57B0BFAEA34A8D4DULL, 
            0x642EB874262EB46CULL, 0x5EA5DC7079F237FEULL, 0x283A0CEBEEBE758FULL, 0x7E05E7728D54EE4FULL, 
            0x29376B71C517D3A1ULL, 0xE5619210FC19B254ULL, 0xFCA2BF38771738ECULL, 0x6B765576594EBD5EULL, 
            0x8C005AE45385D695ULL, 0x2224CBE315849CE2ULL, 0x037E281F08FA2643ULL, 0x9B282D109A3E07F8ULL, 
            0x7B53D53A9A31AECFULL, 0x3A1BF8AEED61A530ULL, 0xDF9091CB4C574B3DULL, 0xF0A170ACD91FAC45ULL, 
            0x05867A02B5CFEB56ULL, 0xC2D797713D26299EULL, 0x22AD64C75D44A59CULL, 0x952BBF45E138E255ULL
        }
    },
    {
        {
            0x10C6DC00F0CEEB82ULL, 0x9E9EF3C62B41C10EULL, 0x0B461624A2BAEB60ULL, 0xB5022A97E01B8E49ULL, 
            0x082524BF86066AE5ULL, 0x97865D0C641C5EAFULL, 0xE62C6CF8779BC415ULL, 0x4AD3795C87B70378ULL, 
            0xA32170459B66D3C3ULL, 0x46DF9DFE4493DDB6ULL, 0x3E4649C62368BF22ULL, 0x4D3F31E272F5BC81ULL, 
            0x24A9E1FDAF4F8428ULL, 0xD6A843C59C1EE05DULL, 0x3D34779551D8E141ULL, 0xEA0D3DDD604442FEULL, 
            0x2B66C4B49A3CAFEFULL, 0x38962C44E5A94B88ULL, 0x81F05398414EB0FEULL, 0xA5A1DB2B51333024ULL, 
            0x8BE67B14286AFD88ULL, 0x9D98946D29E8FF6EULL, 0xFD538909C321A577ULL, 0xF5BD9A5D05F7D23FULL, 
            0x475F8E699FE1A7F4ULL, 0xAEDE8233F536AA9FULL, 0xC6FFC0CFD95DEE2BULL, 0x47D4F9E5F4AE2F9DULL, 
            0xAEEB12ED257E95B2ULL, 0x67BD7D213987A6ECULL, 0x84EA9920A3DEB777ULL, 0xB8AD49D43F5C1E7BULL
        },
        {
            0x9DAEC7CF17A3033AULL, 0xE4AE0840C04661E5ULL, 0xFA0ECA294CF5E54DULL, 0xD4D6391802C7B7F4ULL, 
            0x6D1080653C798D63ULL, 0xEC0559569DEFAA43ULL, 0xF3B138C04079D8FDULL, 0xBC108BF0B1CC1030ULL, 
            0x7E22389BE6B9DDC4ULL, 0x2114043D93C1C5BFULL, 0xB69CF399A989D5ECULL, 0xA0E9679694EDA074ULL, 
            0x131FE47EAE172B82ULL, 0x88F0A97F5B3C8F7AULL, 0x0902FD81DE537EC4ULL, 0x24E7BB7582F9FB3AULL, 
            0x94B77EA2CFB15715ULL, 0xF5E972439B4AF900ULL, 0x49AA8514742691AFULL, 0x4A3B5EF16684142AULL, 
            0x13FE34B3B1BC9E78ULL, 0x802D0DBD6514ABFDULL, 0xF7ACA48D729AD4E2ULL, 0xA945376DED1FC8C4ULL, 
            0x60B4553947ED37CFULL, 0x6E63B8DE9122DA0EULL, 0x4EAD847B6783ACAFULL, 0xF932361FA5D2347AULL, 
            0x7B294F4134D04C0BULL, 0x94909B4B3337C54EULL, 0x233DAD70C5FD9378ULL, 0xD668FE6A7091D305ULL
        },
        {
            0x4748E188110DDE2DULL, 0xE8302AC06A5AC969ULL, 0xBCB695A27F3CC918ULL, 0xED70AE1290C99530ULL, 
            0xB91EAD4C5E5A7197ULL, 0x65A9169137ED8CABULL, 0x3E94A74BB5A59E30ULL, 0x2C99854032C19A5EULL, 
            0x7B72984A68B3D6D3ULL, 0xA3367E4CB56EB1ECULL, 0xCADFB5053E46E928ULL, 0xEBDB005530D726C8ULL, 
            0x413302D2914F722DULL, 0x786D3242C4A14FFAULL, 0x06855A99BFB1E69AULL, 0x5248CD3726A69539ULL, 
            0x9C437B8F6D68483CULL, 0xC6CB60B36FEA9A4CULL, 0xA717C2B095AF387BULL, 0x9836748A6E6DD027ULL, 
            0x8BDD53F9E872014BULL, 0x3520A8EE8DA4F002ULL, 0x0A664F1ECE308A81ULL, 0x9242F621F4B7E6F9ULL, 
            0x27EC741B98237C0EULL, 0x75023284A2CA7734ULL, 0x0D1FE25699CD9447ULL, 0x0900FAC1A0C17A87ULL, 
            0xE50E5CEC8E2631E7ULL, 0x216E94057E9D2A0AULL, 0x5096DF8C67428969ULL, 0x3A1C34EFDF8A9053ULL
        },
        {
            0x8E21FB82224AF9A3ULL, 0xB520D114642F4D75ULL, 0xB0B49AC6550DE294ULL, 0xB888653857FADF91ULL, 
            0xFE8CB357637FF5C3ULL, 0x7D6558A40E786744ULL, 0x8EAAC0D4D01584FAULL, 0x359DFCE76083C794ULL, 
            0x83DB04099C22AFC0ULL, 0x0B30DA4769503E58ULL, 0x1998A9A3D0265C01ULL, 0x46AFBB41043A176FULL, 
            0x6DBC0A047ED8F771ULL, 0x4197BCB1634F1776ULL, 0xD862203C96B65841ULL, 0x733C83BDEDFE06AFULL, 
            0xE524A7C2A4B377DDULL, 0x9431DF64CF1506C6ULL, 0xB3AB350003CEFB4FULL, 0xBB91E166F53FD25DULL, 
            0x5D172FC89FFEBC95ULL, 0x3F540D0EA9A30FC1ULL, 0x9BC305F482EDDA40ULL, 0x9E23617376D26F03ULL, 
            0x04A611AB80D31A21ULL, 0xF724E6CE3CFAE456ULL, 0xA478EF9351619973ULL, 0x004B8D7D515434C1ULL, 
            0x84E0B80DD9C137CBULL, 0xECD4B98C736792FEULL, 0x01B409D1A1DA2F97ULL, 0xA69131A963CE1A5DULL
        },
        {
            0x1C12DD8397A823BEULL, 0xB654D4B0FC27CF37ULL, 0xC64991E4438B04C7ULL, 0x6C322309C9DC25EFULL, 
            0xC3E70F07682694C3ULL, 0xB857C156844934F8ULL, 0xEF6123C01097EEB0ULL, 0xCB91EBD09281B6E9ULL, 
            0x0F26422A2A4F9A14ULL, 0xDE32BB35C003B9EBULL, 0x3A6D4A6D718CEB50ULL, 0xC6E2D68D217D4B6BULL, 
            0x150357F18F88000BULL, 0x3CC15215DFDEF440ULL, 0x6D1626E276A930F7ULL, 0xF338790074B22C0DULL, 
            0xD2E314B87AD93237ULL, 0x168DD8DDE1E219D5ULL, 0xEA8C7F35A52701BDULL, 0xE36D5A3F53DDBA6FULL, 
            0x69DEA435CE1B3245ULL, 0x920D65F6194C37F5ULL, 0x0A2A114D0C3C010AULL, 0xEB0E8D7160D3E013ULL, 
            0x0544CC195E0D6B99ULL, 0xDD7D482F31A30FD5ULL, 0x2A122A8E41A05417ULL, 0xC61440166F02F9EFULL, 
            0x03D8AE692B7CD8E7ULL, 0x349C767883D13EC4ULL, 0xDF8D88DBECAB9540ULL, 0xF8EFCC02BC36240FULL
        },
        {
            0xF98464D37EF13F5FULL, 0xD3108008B68B9F63ULL, 0xC473D67C3B46E810ULL, 0xFC3D7EB397D1F4B9ULL, 
            0xBFEC75B51A119CCEULL, 0x8A8882C4F9365275ULL, 0xB7CDC892F36CB272ULL, 0x28FEC6337FB8540BULL, 
            0xBFB49CC02AC43A98ULL, 0x429BEAE6580D20B4ULL, 0x0EB087344D4D1114ULL, 0xDADCE6DAEE01AB0DULL, 
            0x902C8447C87C8220ULL, 0x060122CAE1B1108AULL, 0xAD99AC3D65A044FFULL, 0x4A51FFD12899F3D8ULL, 
            0xE2BF5BD3AE4AF7E4ULL, 0xB31C0E40BE6D22EDULL, 0x590C08EBFE5BEA0AULL, 0x096A204260D45E70ULL, 
            0x5F62D6B8EA2E54E9ULL, 0x0C397CC9C0635913ULL, 0xF7486686DFE0693DULL, 0xD606EA91496715E7ULL, 
            0x89A1155F4049FC01ULL, 0x27775D415F70AC0BULL, 0x89F626CD771B5702ULL, 0xC564DA337D9B7C89ULL, 
            0x9062110103A296EBULL, 0xE6E5424B224A1EBCULL, 0x77A01EBD1A3B541CULL, 0xC16D4266080593DAULL
        }
    },
    {
        {
            0xC7DA1D236DE72550ULL, 0x9A3D517DFAF394F3ULL, 0x4B6FC791E4BAFEB0ULL, 0x3A80CD8413437335ULL, 
            0x10BD2ECF77DEFD5DULL, 0x5C2A46F9989FFA10ULL, 0x8926CE57E0766D1FULL, 0xCBAD03DDBE7F04A9ULL, 
            0x4B472D38F1E92459ULL, 0x509DABAF00C5B9A5ULL, 0xC73AAE801D2B2E77ULL, 0x91499EED64DE707DULL, 
            0x67531B44E71F7268ULL, 0xAEE95E8ED9B2D21CULL, 0x92984CA595258EFFULL, 0x9003833EB0E58148ULL, 
            0xA5C688A50705A577ULL, 0xA6C030209CE4FF11ULL, 0xB16BD42D281CC602ULL, 0x0CEC62F2749A5C91ULL, 
            0x5C0969A9769ADF78ULL, 0x1108D0F4BB2BF1AFULL, 0xA2B4F23984BB0D91ULL, 0x8F49DE4B5F05B63DULL, 
            0x4BBC1C31EFDBD6AFULL, 0x43EA6FD2CF39CEC2ULL, 0xF53E12073D151D3AULL, 0x3503C60D03AF6621ULL, 
            0x3B650F11080D9BD4ULL, 0xA803D29360047157ULL, 0x9CB3E33E7C333FC8ULL, 0x8FEE7F9990564B0CULL
        },
        {
            0x75FBC62D9D701889ULL, 0x61CA68B1C79082D3ULL, 0x7376C10BDF6AE828ULL, 0x7A71EE2D826C3A2DULL, 
            0xF0700F2E637DEF76ULL, 0xD26109B4E1A92BECULL, 0x848826FBC223B931ULL, 0xE9C2E7EE41D898C5ULL, 
            0x4E281782447B2A03ULL, 0xB77BF59B2A704A08ULL, 0xA04C45F989B22800ULL, 0xAD1AF28D02D4ABA9ULL, 
            0x6D7E0A0A1175A169ULL, 0xC445DA473F57C84AULL, 0x7C2044038DE7A729ULL, 0x396D6DC2933AB2E1ULL, 
            0x0B02225E158615C4ULL, 0xE9B4319A440403D7ULL, 0x49710C19A0FCF96AULL, 0x29B126A0D682B6BEULL, 
            0x0F80F0C210CFDD78ULL, 0xCD0E5FEBFA094FCBULL, 0xD938F42411D3FBE6ULL, 0x0201B3C45F4EC0E7ULL, 
            0x1DA61A9B2A54946DULL, 0xB00574D141F02307ULL, 0xC62B659877DEB29DULL, 0x263E9CCF0CD19CBAULL, 
            0xA88613E8F4BE2212ULL, 0x8AB7FA524958FB44ULL, 0x4F23EFAD996815DCULL, 0xBCEF29BCB441AE55ULL
        },
        {
            0xFD68482F225CC156ULL, 0x7DFAFBE48E5526DFULL, 0x1BEB8EA9967BC51CULL, 0xA0A2AB5676471651ULL, 
            0x7987FB941E60EC54ULL, 0xDF29313227FD1F63ULL, 0x636D00124E623C0EULL, 0x0C402E37BB9E85C8ULL, 
            0xC8410A43E5D689EAULL, 0x968CF2E06BE84BD5ULL, 0x0A05304074FEC0DEULL, 0xC796109FC67D5CE6ULL, 
            0x2F67345E4079E05BULL, 0x8D4105CEFF9DB91EULL, 0x293E8AD5DD4F488EULL, 0x62282492A621890DULL, 
            0x21546E2E1898F599ULL, 0x9196BA4FB904CD15ULL, 0xEC36215464CACFB3ULL, 0xC216E5A2C8E6EFEEULL, 
            0x75A39704979BF268ULL, 0x35DB7B733B9D68BAULL, 0x5DEBA0FA0EF0DF54ULL, 0x94365AB632C4AC84ULL, 
            0x1369A63D16FDA1DFULL, 0xB32EFCA47E8B7651ULL, 0x30EB8036476234BDULL, 0xD370C30E0FC02B11ULL, 
            0x3CF96D0AB95D53E0ULL, 0xEA04D9D17C4ADC43ULL, 0x7EB6F1A28134B3EFULL, 0xD95AE6155E8080C9ULL
        },
        {
            0x41AA66CE788AEFB7ULL, 0xB2EEC94100450565ULL, 0xF90C307B72092C4CULL, 0xC21124C938B84425ULL, 
            0x056D8C4F956B4454ULL, 0x25060E979D9A6E35ULL, 0x458B53372A64A689ULL, 0x8DFA8D50F293AE4CULL, 
            0x4A5871243D9BF9BAULL, 0x0A32C5AB0A985ADAULL, 0x1630E7BF86EA3D3DULL, 0x396F6EDB09D62EE6ULL, 
            0x5ED66797584E0E9FULL, 0x0068FFFE13B7345CULL, 0xB8E4C5E5F3FD3139ULL, 0x7B83112D6009F238ULL, 
            0x17C3AC0DE2CE51D9ULL, 0xBFE46A924934BA0DULL, 0xB13612C735CF3146ULL, 0xEB650CA2A0A35FC2ULL, 
            0xC02E4FFF4E77FF67ULL, 0xF8E94BDD42EC4603ULL, 0xE36F3B4E74A2B1B6ULL, 0x42B3091BCCC73238ULL, 
            0x2C3DB75DCF6A3D8AULL, 0x4F8A75DEA965E884ULL, 0x6DB6362B5FA9B9BBULL, 0x95D5D634E8653568ULL, 
            0xFBB360ECBF381D13ULL, 0xBF6E3E925030E29EULL, 0x851175527FC0076AULL, 0xC19C1967E7960F65ULL
        },
        {
            0x7ABF9F1158AFF5E0ULL, 0x7637A31F6DA4E111ULL, 0x1B3B37A6AF6C4FE7ULL, 0x461647F6F3D03FD0ULL, 
            0xCF23F90BA20E4089ULL, 0x322C90BEDC253185ULL, 0xB1B6D9A41863C62DULL, 0x1FABD2050C37DC93ULL, 
            0xD27163F738235758ULL, 0xBEF22AD4B4909CC0ULL, 0xF9BF6763007BD48DULL, 0xBDBBC1622D9B5F98ULL, 
            0x3D91368A230E1301ULL, 0xE54530ECDC089D51ULL, 0xE20D67C127CA9DAAULL, 0x658B3164834E2C4FULL, 
            0x12CCEF4E6B8C9EC7ULL, 0x434FB1004139929AULL, 0xF335B3B66C7C4306ULL, 0x495996696312793CULL, 
            0x39ABBE1A3BDCB29AULL, 0xF52F99066285F219ULL, 0xE907E351092FB0DEULL, 0x717CC3E847BE2AC1ULL, 
            0x1DD896B6B36DC7F2ULL, 0x837E9F21D318F6CEULL, 0xC392B1078BCC0AD2ULL, 0xB0064FC79483749DULL, 
            0x48B8D28BDE13AAE5ULL, 0x547C9A238FE07388ULL, 0x26AFE708D9E21B92ULL, 0x25494D181F903C71ULL
        },
        {
            0xE17BD59EF38C5F99ULL, 0xE5F5C3A5F3FE8F4FULL, 0xE3928F6F17861E65ULL, 0x806B2B372264631EULL, 
            0x4EFC981175FEF2E3ULL, 0xB1CFF2FFD23AB918ULL, 0x0300EB67C18AD969ULL, 0x957E14E906C46508ULL, 
            0xB80936A30B3082C0ULL, 0x35F420C2BD1AEEDFULL, 0x45496C2EBD8FA257ULL, 0x50C96D99F6C50B00ULL, 
            0x8925F04DD4FE1953ULL, 0x31794821E834CD4DULL, 0xC265BCCEADB83ADBULL, 0x29F872E5981B5DF5ULL, 
            0x67149408D88F1E75ULL, 0x76410BD7A7FC5F24ULL, 0x9C64C427743838BBULL, 0xAF187AF20BE4344EULL, 
            0x95364EE74F83B6C2ULL, 0x8EB915F7564A0F44ULL, 0xE608DD862B4163FAULL, 0xBE98D60B27C96612ULL, 
            0x604C1C1D71485534ULL, 0x85B1661C8994FCBEULL, 0x49994EA09AE0B9ACULL, 0xE20DAFEAC65A52CCULL, 
            0xD58D3A9F7E14D143ULL, 0xC4A60AF483EFBDEEULL, 0xC6B5320452935790ULL, 0xDF30763333009196ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseEConstants = {
    0xA9661553EC242158ULL,
    0xB3EC5BD79043B76BULL,
    0x8E88C1E06B044BB9ULL,
    0xA9661553EC242158ULL,
    0xB3EC5BD79043B76BULL,
    0x8E88C1E06B044BB9ULL,
    0x6DF4743F38A6D90CULL,
    0xABA8517F9BEAB7FDULL,
    0x6E,
    0x27,
    0x43,
    0xC5,
    0x41,
    0xEA,
    0x03,
    0xCB
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseFSalts = {
    {
        {
            0x6D81766D7F238454ULL, 0x6083C92148FD955EULL, 0x2721958EF43F2928ULL, 0x7C5AD00B77F4A3FAULL, 
            0xEB63932224296E2DULL, 0x3961EDDFA9ACA0BFULL, 0x165E409C386D223FULL, 0x6A169F04B6BE602CULL, 
            0x0166FA329A9D538CULL, 0xEF965B1B78884FBAULL, 0x011CE3437B5B7C6DULL, 0xD46C093CD59A8AA1ULL, 
            0x5E99A57A26DC2C30ULL, 0x848EC0652AA2B444ULL, 0x1CAB6159B61594A4ULL, 0x73A2227D5ED330F1ULL, 
            0x6D0286968813CAC8ULL, 0x9BD5A78929B938ACULL, 0x8AAF96DDDA6CE485ULL, 0x17A07A79F8831DEEULL, 
            0xE31D954C31EA8F6BULL, 0xB22BD3B3E70079E4ULL, 0x15FDAECE138F20AFULL, 0x05A857150FB3134DULL, 
            0xEB3F7149576A47F1ULL, 0xD3C64E39515FDE51ULL, 0x46A536F094275EEBULL, 0x5EE942995140184BULL, 
            0xB0805F9A52E5CE6BULL, 0xF0E9DFB83C8F3462ULL, 0xAA884BF378CF9673ULL, 0xBB235BD5E7CEDD61ULL
        },
        {
            0x7FE6B26D5254C3D6ULL, 0x1F9DAA7262813A40ULL, 0xE44B8F402D24BA62ULL, 0x9813B1FFAFEE1796ULL, 
            0x8FAFCEA5C4714778ULL, 0x85BA9757B48B67FEULL, 0x9CF41C65831C893FULL, 0xB0FC5D6DB75E7E18ULL, 
            0xEADB0C12CF8A9BD4ULL, 0x87395D8E9F5A7516ULL, 0xBBEDEA67ED565A83ULL, 0x10E4CC179E12B1B0ULL, 
            0x9045F0DDC50E4F40ULL, 0x05D03BFA94CC9DC9ULL, 0xC1D9098612EC9D2EULL, 0x20E3DF33A227581FULL, 
            0x3E9C8556C2666485ULL, 0x7D47A1423AC693C2ULL, 0xD06F749418096D14ULL, 0xEDC18753A11DB728ULL, 
            0xB8FCECEE36CB9A2BULL, 0x25E898125B254203ULL, 0xE6BB27E30F974E4DULL, 0x71D75D2C7489F207ULL, 
            0x6CFF668B7D2FD78FULL, 0x431E2C67F86411E2ULL, 0x831C0541B2039DFFULL, 0x927D0CA37033AFBEULL, 
            0x70D2C65403735822ULL, 0x6457F802AA3D32ACULL, 0xA3CC50296BD8675BULL, 0x8AE36A49D5927C42ULL
        },
        {
            0xD81DBFF2EEA4B70AULL, 0xA592BE9E525F1166ULL, 0x04A9CA4D566456FDULL, 0x8C3FC30F450E0936ULL, 
            0x2CE63BAAD2198B20ULL, 0x3641E1FEF2744F4DULL, 0x99B392D3A39D6C3CULL, 0x507BBF072C696329ULL, 
            0xB2CEED06C5976F41ULL, 0xB685D5A17B6E5AA9ULL, 0x175F5A2453A58938ULL, 0x984C12A248848AA6ULL, 
            0xD93663E06EFE2111ULL, 0xB65B7F13B5F6759EULL, 0x289EC2CEB8DFA639ULL, 0x32CE446C613496A3ULL, 
            0x2D7222A6B0CA8E03ULL, 0x7D4AC93522D3AE9FULL, 0xA7729B2F0398B595ULL, 0xF9BC29F7992387A1ULL, 
            0xE112BB0FF33B79E3ULL, 0x30C3D0923652686EULL, 0x889BE30C541493C9ULL, 0x22E1C419093A3C7AULL, 
            0x83C54BF48B5822C3ULL, 0x84B6F29221845C56ULL, 0x8F5212B5F3874190ULL, 0x19C14FF830A6B2F6ULL, 
            0xDA5690B2210221EBULL, 0xA28205EBD4188F2CULL, 0xDE22B918F3E8FEDEULL, 0xF587D4592E00EDF9ULL
        },
        {
            0x530B325581FC4943ULL, 0x82950084632AE5DFULL, 0xBDF095011ED166F7ULL, 0x5A85482F36999A98ULL, 
            0x462FCD08623413FDULL, 0xD4815418A0BEB835ULL, 0xD239F6EB4559D353ULL, 0x606390A62C9EBAAEULL, 
            0x86799265E5BB2739ULL, 0x96365A516579AD2EULL, 0x6C051E0E2DACEABDULL, 0xB12D8CC240A4A738ULL, 
            0x9977897E748FC1F4ULL, 0xEC848B7F6027C923ULL, 0x0AA21DE2841828F0ULL, 0x58897E46E45E1905ULL, 
            0xC549B173A52B6741ULL, 0x8C978E016511D4DCULL, 0x0182DE9AD64BBCC3ULL, 0xA53AD400C795DDD5ULL, 
            0x9FECCC4B4B0C29E5ULL, 0x07D91D63CD3F6923ULL, 0xF492EC283DFEAF09ULL, 0x9931AA3A82B3A6E9ULL, 
            0x4C740095C030DD7AULL, 0xB1675870D6C84584ULL, 0x1C4B26241BF36A48ULL, 0xB921DAEBFDADABD3ULL, 
            0xDE96A9CB3B6A6B07ULL, 0x681E896E650980BBULL, 0xB734A4894B34CD81ULL, 0x073D92516D3253FAULL
        },
        {
            0x1B91D79A0362B3AFULL, 0x12CA7B5177E874C6ULL, 0x0617F23A768E0AC9ULL, 0x34C0A215BB211470ULL, 
            0xA238089CB43276B9ULL, 0xE342DA67E24F482DULL, 0x93F16BE0DEAD10E4ULL, 0x87A166EE41C109FAULL, 
            0x56130F70E148E931ULL, 0x17174B58022CD40FULL, 0x17F624D025DC5D8EULL, 0x374AFB60B4418620ULL, 
            0xD5D6030BD484E479ULL, 0x2B45B22B953BBFBDULL, 0x1B1401A6142122AAULL, 0x6CC8F0D50AC3205EULL, 
            0xBFD9B84AE822EF44ULL, 0x3D33850AF14E9069ULL, 0xAB047CF00A1C3C62ULL, 0xA29DE50BBFFFF8CAULL, 
            0xABDFD25A131F65A8ULL, 0x2951A221F2EE296EULL, 0xE17175BFCCA5507FULL, 0x3286E8D94DB7A8AFULL, 
            0x675ED3A02E902C6FULL, 0x10C7F1374E76B5ECULL, 0x075CB95356643EF3ULL, 0xD7F76CF7EBE86958ULL, 
            0xCE0B469BD355860DULL, 0x18625B19238663E4ULL, 0xD129596E0C308A6AULL, 0x51C7C7F575F13D65ULL
        },
        {
            0xE9ED4F948F19033BULL, 0x91BD32612C1469C2ULL, 0xA6E2C34DC400B010ULL, 0x0C27F21DFD16DECEULL, 
            0xEE23AA65D082B355ULL, 0x5D901080A9052A79ULL, 0x604E1DA74C8A1804ULL, 0x4F50E41B4F3FFFAAULL, 
            0x686E22C0AFFCABBAULL, 0x71E49371BF6A51B9ULL, 0x85275791962985E7ULL, 0xCA1486D3BBA71D0DULL, 
            0x2E34A4340E9E5D6DULL, 0x68F8E9673DC3A756ULL, 0xB5A529B69C6DDB52ULL, 0xDAA8D3D0936E6B54ULL, 
            0xCDD5804717F534ACULL, 0x9EAE9C09B3EA5C80ULL, 0xB0AE7AC6FFCB46BDULL, 0xF7CCB3AC5469BBEBULL, 
            0xB9368CF5ED18A1E6ULL, 0xA84428DB7A415C40ULL, 0x3EB26AC733279061ULL, 0x4B5103C676B704EEULL, 
            0xF39DEA4C9737EB1FULL, 0x00D6E1091ABAC069ULL, 0x3E904383A9C96A03ULL, 0xA4CD7E10A945FA78ULL, 
            0xEC104E3727FD1667ULL, 0x2EAA9BC3AC17C4A2ULL, 0x003C2FA686C47C83ULL, 0xE955C9ABE6C93F74ULL
        }
    },
    {
        {
            0x1C43F87C9CEE14A2ULL, 0x1C84430A14FFEA2EULL, 0xB35AB3B01B5149FEULL, 0x8C786D1425913FD8ULL, 
            0xFBA7DA40131CD2E0ULL, 0xBA779C4C5621DB07ULL, 0xB252E7E2090E031FULL, 0x26F93E0FC3CD81C0ULL, 
            0x9E16A2D2E0B2764FULL, 0xC58CD83F7B13CB9AULL, 0x6F756A9D6D47C733ULL, 0xA3D92391AA74BEA2ULL, 
            0xDB01DF62CEAB8718ULL, 0x4498003D53201601ULL, 0x666826ACD22DF963ULL, 0xBE631C7DFBAFF512ULL, 
            0xB0335A6A548D9AD2ULL, 0x1145F16E209DCC61ULL, 0xE1A9BD9B56BE9F5CULL, 0xDC0F282170D32724ULL, 
            0x46AC94DD7269651BULL, 0x3A906785B246C6EDULL, 0xE419551629FE4C65ULL, 0x610C65A1A6B78D97ULL, 
            0xE141533F120B6DCCULL, 0x8BDF71E00D11D2F8ULL, 0xFDB3986F888A5D33ULL, 0x263ECF81E513406AULL, 
            0x1326928384CFDC68ULL, 0x479E99290DCCAADAULL, 0x53CA6F3A56ABFA52ULL, 0xCB9E6F0DE4DADE17ULL
        },
        {
            0xFCB2A96F375344B9ULL, 0x4788C925A005D0A4ULL, 0x19425C064792B572ULL, 0xE54BEE1A94962276ULL, 
            0xD6B1EA93369980A7ULL, 0x4A3DB564AEF61200ULL, 0x3750AFC9EAE01577ULL, 0xBEA4885499A6A090ULL, 
            0x3B7A9A8C43BE0A87ULL, 0x9EEBCF0DB27A3192ULL, 0x47B6984972A9A7FFULL, 0x44971CF509913C4EULL, 
            0x23CAA8B738BBE56AULL, 0xB85040C5023F6928ULL, 0x9EE68D83F3DDE7C9ULL, 0x319ACB05D8C27BBEULL, 
            0x228B9C2F12EDB28AULL, 0xA22448D428DAEEAAULL, 0xAC5CB3522BD2A700ULL, 0xF2CBEC8135A79614ULL, 
            0xF150B8936F2E4847ULL, 0x95B6CF3444A662D1ULL, 0xE08634ACF614AC12ULL, 0x1F98FBD85245770AULL, 
            0xB1509F117E9EB1CEULL, 0xB514BB9824D7928EULL, 0xAE45D82CC81262BCULL, 0xC32FF6EC5980560FULL, 
            0x51868A60878FEBD1ULL, 0x8166A510FFF071A1ULL, 0xA0829EE6769FE7B1ULL, 0x28D11FFD37F98D66ULL
        },
        {
            0x80ABE67A13973C84ULL, 0x32FD6DC7DA91CA23ULL, 0x489D44414C7955FDULL, 0x869E8315DA04A5F2ULL, 
            0x5F349D19B996DFCCULL, 0x13C40AA33F60245BULL, 0x4A1C0C1146669B98ULL, 0xA0CA5AE143327073ULL, 
            0xC65D00236E06291FULL, 0x5D20CD69A427D748ULL, 0x7C390DC032FE8F8BULL, 0xDCF531DAF62838AAULL, 
            0xC730B28C113FE6E2ULL, 0x6D4AE73CF23B904AULL, 0x02853EFB41F564BDULL, 0x350558E42A6F9FBFULL, 
            0x65741E2334C82EF8ULL, 0x4FE5607000323DBCULL, 0xBD965FE1EC9B5822ULL, 0xF9DD53328E89BB7FULL, 
            0xA84D42A062C52687ULL, 0x9E59819F85C64CE6ULL, 0x8A6337E954B1CAA2ULL, 0x070D92656209210FULL, 
            0xD854808CABA131A6ULL, 0xC5F31058AFBF7A17ULL, 0xC27AA20AC25DEC29ULL, 0xFAE369961FFEAA6FULL, 
            0x5B53A7D43B7211ECULL, 0x939BC068CA0DBB72ULL, 0xBE4E0DCEFB08CE95ULL, 0x6FB2607F57073DD5ULL
        },
        {
            0xF0F1FCEECCC2DEDAULL, 0x29D22A642E02D5ACULL, 0xD174F97597FE47F0ULL, 0x91C47E79BB0C3A0DULL, 
            0xD2DCCB5921664909ULL, 0x396B158CDC359D21ULL, 0xCE9317A4CD08019DULL, 0x5791D76287D70D95ULL, 
            0xDDFE8FB8314A664CULL, 0x6F037D9AF24D131AULL, 0x26249B01F2CACA60ULL, 0x8854618039953BA9ULL, 
            0xEA35D89C8D3AEBCBULL, 0xAADA315317CD7744ULL, 0x2E707B1F345A74DFULL, 0x1D5688FF2024960CULL, 
            0xF747D0F7D44F6647ULL, 0x6F6DA8256C999919ULL, 0x23EBB21434EA6E48ULL, 0xF4D925F1BE9BBE35ULL, 
            0x8EB56DED575792DDULL, 0xC7E5070BBAE90A45ULL, 0xAE780823E23D5EDCULL, 0xE8134A326A82C024ULL, 
            0x911539A95A836513ULL, 0xB1565206D64ACAE1ULL, 0xC7D8D3E7868BCE87ULL, 0xCD2CF59C7DCD7E98ULL, 
            0x0DFBC839CFB263FBULL, 0x12DB7B6D91CB8767ULL, 0xBE5C660AFFEC91B5ULL, 0x34575449A5103897ULL
        },
        {
            0x474145BDD8FD9F02ULL, 0x2B7D9D34328DF8D1ULL, 0x49DCAD24D40D7FFCULL, 0x9C851B79B47744F4ULL, 
            0x4A32BBEA6B2EE73EULL, 0x228A95209111185EULL, 0xDA007ADE52963E61ULL, 0x7AE3646107D9E2D3ULL, 
            0x7A159AD7CE33E696ULL, 0x9603DAC1206DE471ULL, 0xCF4E0DFE229C9164ULL, 0x71D27D0D449238B1ULL, 
            0x35AAD478F79C6F55ULL, 0x597DF936A05E6F2BULL, 0x5D9B38C95E77CDADULL, 0xD04DE27E9B7E1BFBULL, 
            0x7853185790BA8CB3ULL, 0xB2F01A5312C6C58EULL, 0xA5FC5F1E2543018FULL, 0x1EA3E0E093A158BDULL, 
            0x2664ABEF347F08ECULL, 0xED49B7C5BCF3156AULL, 0xE35B1C5DBB0E843CULL, 0x731AA261B7A62342ULL, 
            0x7725CE6486D92963ULL, 0xB2A6B0D1D7129BE8ULL, 0xA31B1DD9A6953F8EULL, 0x9298920F053B9201ULL, 
            0xE54E1DC389EC02EEULL, 0xDFCC41329666B0E3ULL, 0x089F752BE33ABF7EULL, 0xEAE7D8332514796DULL
        },
        {
            0x299D1934AB02F14EULL, 0xB653C0A1CECBA603ULL, 0x25B53EC2F7BA0799ULL, 0x9A71CD115873FC5BULL, 
            0x368BB7FE07B1B7DBULL, 0xBD3E607C56F55D15ULL, 0x055ED637F85785A0ULL, 0xF3E06B7E372278BBULL, 
            0x8C06A98CFA34869AULL, 0x9B2F7BDC9D71ECB7ULL, 0x582C4624407B0887ULL, 0x681F318908B122A0ULL, 
            0xA7907085F2A490F3ULL, 0xAB1F5F11F288BDADULL, 0x0D13F8FDF15BFAB4ULL, 0xCE9E8AF6CE77D4C9ULL, 
            0x83997E78DA736E2EULL, 0x2714D9F0FE0CE7EAULL, 0x106F213770928CA9ULL, 0x55C41EAD4DB2AD0DULL, 
            0xA41DB13AC4AD30F1ULL, 0xA4B8813A9AF83304ULL, 0xFB05DDFE49F47AC7ULL, 0x0B7248DDE77E5204ULL, 
            0xC59725FDF358EB7BULL, 0xCC3468456E1233C8ULL, 0x08D35D433C38C961ULL, 0x2DE0088AD97CE765ULL, 
            0x9698C0F38F28B956ULL, 0xE791F4EC3FA08F0EULL, 0xA5FE8865AD0FE0C4ULL, 0x08206E3C783F1BDDULL
        }
    },
    {
        {
            0x3F570AA3EF36BD1BULL, 0xC60A02505604D486ULL, 0x1D37D5D9742F733CULL, 0xB28BFD3EA569F8B2ULL, 
            0xE04D07486B49DB8CULL, 0x06DFB6CCF65EE840ULL, 0x1E98C3CA769457E8ULL, 0xA981B2120FD40B4BULL, 
            0x2DE2D4BB2D7F51B0ULL, 0x794179646BD53842ULL, 0x302000630574358CULL, 0xFA5B9B10DF01D9E8ULL, 
            0x53AED097AD138B24ULL, 0x3E0ABA67A5C6DCCFULL, 0xAD3C21BCDE47A101ULL, 0xEE03A5FCE4BE4246ULL, 
            0x571AA1FA822DBA8EULL, 0x93BFD4109937C524ULL, 0xE79013E6100C9F29ULL, 0xA11F45D7F55C44B9ULL, 
            0x875C64F786CB3F27ULL, 0x6546A40EFBA3A77DULL, 0x54B3C4ADE8C6707EULL, 0x71509698D4EF31E7ULL, 
            0x231DC9942532E841ULL, 0xB1786F8467663F9DULL, 0x5DB025B55C1E0A5FULL, 0xA7E343855105CEA9ULL, 
            0xB9C875F08080C0ABULL, 0xD8984A5BA03958FEULL, 0x8C1D33F83F0B0627ULL, 0x6B96F101995BEE73ULL
        },
        {
            0x1F080E8007D69673ULL, 0xEE16BD9F9E2D89D6ULL, 0x5ED33515D977CF94ULL, 0x6256C07B4453B110ULL, 
            0x9FC417A04A20C099ULL, 0x105C6B254AB85862ULL, 0x7583C927801F7DF6ULL, 0xED43905F831EE852ULL, 
            0xA2C3A504A9EDB1A6ULL, 0xA414C6A78AB47004ULL, 0x1C835A5191244268ULL, 0x3C0413B22207BEBFULL, 
            0x82E1A0C297BDDE7FULL, 0xCE12C6009E9C7808ULL, 0xB63911A9ABCA76ECULL, 0x3E1BDA833911AA06ULL, 
            0xD3F9A78386790CC3ULL, 0x52D77EADA495A471ULL, 0xAC8AD2FE5BFFBA67ULL, 0x832F0FB465B7DD13ULL, 
            0xAD60761A4A614042ULL, 0x4915A9B2BFD164E9ULL, 0x56976A4793F98A40ULL, 0x2E302034A83B6F8AULL, 
            0xAD656E1833627A65ULL, 0xD995EFBD05791F96ULL, 0xAF7F613463B09B7BULL, 0x95068F78B62E68A0ULL, 
            0xD4046B694E0926DAULL, 0xDE87E1E055A457B7ULL, 0x04C5147DD863AA04ULL, 0x95A550EB4F0CB8F9ULL
        },
        {
            0xE3049C38A7105CE0ULL, 0x995BC79167FBC569ULL, 0x079732FCD8F4EB16ULL, 0xE70D44C8B6B46AC4ULL, 
            0x3925018454100CE7ULL, 0x506908823B525747ULL, 0x6EB2A9122F0F3552ULL, 0x9604A21928CE3F4CULL, 
            0x63C330B0AE69D09BULL, 0xD0E1651B08EA0FFCULL, 0x118161658C2CEB02ULL, 0x73E725AEC80382E0ULL, 
            0x889CE41F80156F86ULL, 0x824F981A253EBB3AULL, 0x129A1D46286F3A7AULL, 0xB0F1E04DF56A7A37ULL, 
            0xC45BD2C076D6E124ULL, 0xB25AA8D7062E6DFAULL, 0xF86A9547C3104294ULL, 0x4D02DB5E0D72A09EULL, 
            0x44ADC1B5E5F7B040ULL, 0xAC820BD6C7594AC3ULL, 0x93BE08FAD3A8FAE5ULL, 0x93113D495D519C76ULL, 
            0x6E9297E6377FA30AULL, 0xCC3E286912EF7F48ULL, 0x01DD716EB1D2A079ULL, 0xA8ED22E4DCE6918BULL, 
            0xF209E7A9E0C51883ULL, 0x755D1158597CAD5AULL, 0x5528CB64AD9F6AA3ULL, 0xFF6AF808033B9555ULL
        },
        {
            0x5FABB76F723D8F1CULL, 0x7ED89800FEA96225ULL, 0x22DBD85B3E857F2FULL, 0x398B759BA27B00AFULL, 
            0x3CFF31F8FD48094CULL, 0x8982066DC405954FULL, 0xEEC6E63A5CDDE24EULL, 0xD3B8AC7EB660454EULL, 
            0x8DA1580A6EC9D1C5ULL, 0x1C6D80E865A67300ULL, 0x0B7BE590B957BE27ULL, 0x7B4B73C629B6FECFULL, 
            0xFFC26E39F502490EULL, 0x13784C243429C561ULL, 0xB33E8FD6FF11203DULL, 0xC91D330B5897DD3AULL, 
            0x4BA2C14855EE8E3EULL, 0xFD79B356E4C36D7BULL, 0xBDBB648CA02A0F23ULL, 0xD38A1F2B87674A59ULL, 
            0xBD7EA408E0FC3646ULL, 0xF20CCE8A2EDB2F59ULL, 0x0BCD1C0064EEF650ULL, 0x4268A9B27FA17562ULL, 
            0x88412705324369A0ULL, 0x4B67F348F6C53EF0ULL, 0xE99423F5B8FEB11DULL, 0xA53DC484641A5BFFULL, 
            0x93E3FE33E9D8F3DDULL, 0x14C057787CF23980ULL, 0xF1388815745941B6ULL, 0xE296348C95A53BECULL
        },
        {
            0x9CA0787569FE4E0EULL, 0xA5314DFDBAD1A66DULL, 0xCB02B8535086101CULL, 0x7A6DFBD7D535D74CULL, 
            0xB468A74B56AECF88ULL, 0x069A3A31C61D1AC8ULL, 0x68F5BBDF18757C78ULL, 0x125A0A2B596AF03AULL, 
            0x44E615A229171AE7ULL, 0x69A4BAC0C2965DA9ULL, 0x261F78A8113734A1ULL, 0xBD492E1742832B08ULL, 
            0x8A0C922891B77D02ULL, 0x7EC3626D4BBCA66EULL, 0xB77C584E67183B0BULL, 0xD6145A60B31E385FULL, 
            0x39B1D79564994486ULL, 0xED4C8B1E9376661CULL, 0xF0BB5163BBC8980CULL, 0x08F96D8309964AD2ULL, 
            0x3637AA643390FA51ULL, 0xF3C8C49A83B8C094ULL, 0xA4E35A9024734A45ULL, 0xBCA96F3A886F5E0EULL, 
            0x64F44CEF2D0901C9ULL, 0xC652E99110882346ULL, 0x9FF00D4E0EFCD4F8ULL, 0xDD1E66B05A9ECA6DULL, 
            0xE49A4532015D7BDAULL, 0x52C273A1E9B2CB6BULL, 0xC6AD1275748D3E3FULL, 0x2A72147CB0C0A458ULL
        },
        {
            0x895F3C379E0503F4ULL, 0xB8EBA7B4EFD77967ULL, 0x29AEE4299B474257ULL, 0xBA125BBC4777457FULL, 
            0xA3CB88CFFD8E83D5ULL, 0x6F46CC1D97DA5929ULL, 0xCBAB5A3A0C3474E1ULL, 0xC9386F7B58D39542ULL, 
            0x06FD138BC9EEAABCULL, 0xC219715DF11179B2ULL, 0xF4123D5E0E5F646DULL, 0xF9A18B8FEB2A4723ULL, 
            0x24DE746C0722A970ULL, 0xC4F55DE4CE93BDADULL, 0x0903DB53C74DA0D5ULL, 0x1C888355F00C24E5ULL, 
            0x788AD151A0C74FCDULL, 0x0DE0C5A8ABA0E2DEULL, 0xF217ED964A4B4CD5ULL, 0x8E7816DB98F17A98ULL, 
            0x948A44E079B4447BULL, 0x332A1E8EA2CA11D6ULL, 0x39176A279AD901ADULL, 0x5F0B9128A2818C95ULL, 
            0x2E76A1ACF3A9BB66ULL, 0xE8DEA0EA4A52BC28ULL, 0x4790436CBDA8B7E8ULL, 0x9F85990BAEA04F30ULL, 
            0x32A978B135BD9DE4ULL, 0xE8182A440E49977CULL, 0x6F732B33864E708FULL, 0x53D8BDAB43EB7DADULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseFConstants = {
    0x29602A78098BA628ULL,
    0x097CD565802EDDB8ULL,
    0x6DE5B2F86F90180DULL,
    0x29602A78098BA628ULL,
    0x097CD565802EDDB8ULL,
    0x6DE5B2F86F90180DULL,
    0x229A361834F81D58ULL,
    0x3D3EFE7427DE9503ULL,
    0x76,
    0xDC,
    0xC6,
    0xDC,
    0x3A,
    0x0C,
    0x37,
    0x3A
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseGSalts = {
    {
        {
            0xDECCD749B505C8AFULL, 0xA7A9F651D03C9A36ULL, 0xE3B4F3BF9385BF9CULL, 0xDA8784BC0C2C10A1ULL, 
            0xBF762AAAF1ACCA6EULL, 0xDA55C50363569E8EULL, 0x2D0E1DDF0AB5C648ULL, 0x75ABD5CB5D0A8AA8ULL, 
            0xB75DAF2A481D18C6ULL, 0x7D2266054F330B5CULL, 0xA68BAE68553A8885ULL, 0x8D364CBF0BA0EA95ULL, 
            0x3E4EE2B7439CC3B6ULL, 0xEA1078AE5B227128ULL, 0xD020817AFF4AC91DULL, 0xE5DEF74716BD6BFBULL, 
            0x2225514472CAD2C4ULL, 0xC42040AC82C5C1C6ULL, 0xA8BD4A8F59706EFEULL, 0x58070D30A185643DULL, 
            0xEC1D82A88CB9748DULL, 0xD1CEA53DF4CE570CULL, 0x97DB7D5FA1FBDDA7ULL, 0x90A482994DD643F9ULL, 
            0x1FB4EB7B3AA8D550ULL, 0x10F4B77095AA7486ULL, 0x381AE796FED144C2ULL, 0xF459EE07F3F3FF90ULL, 
            0x5321EB5CACE53984ULL, 0x9BDEB22B794C5540ULL, 0x29775D3ED2F6DAF6ULL, 0xB41EFB122A7C3395ULL
        },
        {
            0x86DFCA2A6A46A690ULL, 0x5410B682AEAE7CD0ULL, 0xD25FE3D3481AD9B6ULL, 0xF0F9A366829A0D9BULL, 
            0xE98EC8368B908955ULL, 0x82AE10793018C793ULL, 0x4C8E566C190EB6F7ULL, 0x8F1DCD47FDB89596ULL, 
            0x3FF137741ED01B9DULL, 0x6BC4C0F29A6F852FULL, 0xBE336D3AD67388C8ULL, 0x5DB9ECB0C356A7C2ULL, 
            0x78A59458ECA2B1A9ULL, 0x95693CD2BE937830ULL, 0xF73005C1CD3513B2ULL, 0x6A274D7C10CA5139ULL, 
            0x2080BCA3723916FEULL, 0xC62D6296ADE28E73ULL, 0x81B7657292C288FBULL, 0x9BF26E19A922AEEBULL, 
            0x2B1F421A45937817ULL, 0xBF345FA8282FFA0AULL, 0x0F68E4F134CAE49BULL, 0x03A5CC456F78F68CULL, 
            0xFE37B9CC653B1A1DULL, 0x041E3232BB609F06ULL, 0xD3EA4659723D69B3ULL, 0xEEBC9AF86CF3659FULL, 
            0xCE5B7B68C4030DFCULL, 0x5B0C55022525D5F7ULL, 0x94354C985E06AB3BULL, 0xA72857F7942FBE4BULL
        },
        {
            0x4B5B755AB66598DEULL, 0xC21EBAE8180ABB52ULL, 0xF1B92148CA66DF9EULL, 0xAF76E772416A22FEULL, 
            0xC5E343B9F0F143B2ULL, 0x42C47F6E88458EF3ULL, 0x53B202C2A459D04DULL, 0xEFDF99F7F1BE4D75ULL, 
            0x8A552DEEEA8839F8ULL, 0x866ECC0A8AF32073ULL, 0x9C1A7EFF90328730ULL, 0xFBF965EF33C675B5ULL, 
            0x77656046E7EBC720ULL, 0x2AE0E85EC9D75FE5ULL, 0x9CA141362EDE12FAULL, 0x88701C2B891B7A7BULL, 
            0xF7594FCD91B03244ULL, 0x9375F72E01271F42ULL, 0xBD968EC28CACB90BULL, 0xAC1D3066A8B2DF18ULL, 
            0x5A91AFFCD8B1ADA2ULL, 0x6B7FE0FE3B6B6C3DULL, 0x7B866FF3E38BBFE8ULL, 0x1971CE815D60E4FFULL, 
            0xF4F58F4FCFBEA54CULL, 0xA43A7AF785B2B6CAULL, 0xA507A91AEF25D09AULL, 0xCC18D8B6ACBBC40FULL, 
            0xDCDBCC22B20B6162ULL, 0x4C196EC339A4B60BULL, 0x903A3CE2EE8D5896ULL, 0x324C3D8704107334ULL
        },
        {
            0x56C739F8471C58C3ULL, 0x2E8686C945BBAB50ULL, 0x73A9D79DF0E1C8A8ULL, 0x412AFA3E9910D5E4ULL, 
            0xD4426A32E5D0F58AULL, 0xEF2DA8DC69AE99A5ULL, 0xFED74343AD75E563ULL, 0x26687619BE9E0067ULL, 
            0xFF5A2809E545CABCULL, 0x996536E3F07C1A6CULL, 0x89B390858D31AEADULL, 0x3941F4F25C3C18B4ULL, 
            0x96A431EB9F4A7167ULL, 0x312B96AC158D89ECULL, 0x5C9E85BAD278272AULL, 0x1943A461BF529894ULL, 
            0x94756425FE23DCCAULL, 0xE7217F46C916ADBDULL, 0x03AD553BF435F073ULL, 0xAEBCB9CFDB986FCAULL, 
            0x62B77862709BD17DULL, 0x58479AE17291CE1EULL, 0x54E751337EF0B6EBULL, 0xD5D0F8870831567CULL, 
            0x397DD62A3CF63864ULL, 0x4EA9E518885D2882ULL, 0x7F069E3C8305A882ULL, 0x835C07D1FCC4115CULL, 
            0x409C75B4050C7ECCULL, 0x982DDFCAA3296A3EULL, 0x0C36848949B5731DULL, 0x7B23F0C2FBEC7AA6ULL
        },
        {
            0xAA37FCA62C325A89ULL, 0x0D4E932C448B2243ULL, 0xAA4D2B6CC99C8C20ULL, 0x4FA7C82FD840AF3AULL, 
            0xE0FC5C4DD3DBCBC6ULL, 0xF890DCB1F6B0CCC9ULL, 0x9BC196F3B3532D89ULL, 0xE064B7CFB2C6ED6DULL, 
            0x0D15EDA9C12F7A92ULL, 0xA1C2C1C2C9E05729ULL, 0xE820D35233D64269ULL, 0x5D9350D6A2554EABULL, 
            0x16F9431889FAF9C8ULL, 0x5D0DD737D144B1E8ULL, 0x8172B4950873E3C3ULL, 0x1912A055AC7FA634ULL, 
            0x73EFEBB7A78A8E2BULL, 0xBB411BB38BA419F4ULL, 0xBF1E28FD1D16B186ULL, 0xE7B06F5CE74FE1FCULL, 
            0xFEDD548A6EA44473ULL, 0xAA36BF3F390F0935ULL, 0x5D71CFD4EBD39A1FULL, 0x67570F4B749391A3ULL, 
            0x1547F0D475C43945ULL, 0xAA2FAA866CC170D9ULL, 0xC65AB3F68F983280ULL, 0x65BD548A5F8F3CC7ULL, 
            0x34A8378E2CAB6A2AULL, 0xEFF5E98CEC5D570FULL, 0xDE234F9FEC01C89CULL, 0xDBEEFCC832DE00F6ULL
        },
        {
            0x83D52C5A1674B360ULL, 0x98DBF140D830675DULL, 0x958CAD7B2043009BULL, 0x52A4A8619B259A50ULL, 
            0x1FCC518C86671CC6ULL, 0x1411C4F4D5D92E25ULL, 0x2D2766518BF75BDDULL, 0xCAF4B1360C2DC321ULL, 
            0xDB3A9391DEB5519DULL, 0xDB4FBC215F96D8B8ULL, 0x0CE2C8F751E79A55ULL, 0xE1764E6EB2C551BEULL, 
            0x0AF3B6906438D395ULL, 0x9441D693A4C2D5CFULL, 0x9A235B88D1472861ULL, 0x17CC4EF67DA95C4DULL, 
            0x203EA57EE1961AF8ULL, 0xDBDFE0D95D014363ULL, 0xAAB3568CE07244ABULL, 0x8C6A83354D243AF6ULL, 
            0x34ECF2DFA09BD32CULL, 0x05656EC99C5E8FC5ULL, 0x376B17CEBB1BA140ULL, 0x7DBD690D2784F3CAULL, 
            0x561380FEFF570C60ULL, 0x333088A0D5539341ULL, 0x96CE475F815F33EEULL, 0x2369A71B1ED5BB02ULL, 
            0x2187A8E3D65555D2ULL, 0x05907645CC5A6A8EULL, 0xC21B661C957B808FULL, 0x9F6C8699D7191037ULL
        }
    },
    {
        {
            0x347DB63C1530FECFULL, 0x45C0A1DB368B8793ULL, 0x69289E67EC2A4E27ULL, 0x7EA587DC2813C2CEULL, 
            0x3E4BD389BD4885D5ULL, 0x155A251C2F6BBFE4ULL, 0x7C29C6E4D3D3E70CULL, 0x2FE77BF17F25976DULL, 
            0x0605606712031FCFULL, 0xE554285D96BF84A6ULL, 0xF9BA186DF2D56116ULL, 0xA12F05F81CF338F1ULL, 
            0xD25811384A5B5665ULL, 0x44D74263FEEBC842ULL, 0xF95F92F1E12F20FBULL, 0x4F3CAC1BAB79BBF7ULL, 
            0x463084DEFCF6DA7DULL, 0xD2D280635C1BD950ULL, 0x93C94D673E69BDAAULL, 0x28F98226081ABF8AULL, 
            0x67E59249F5CAB72EULL, 0x8A50073188FA21F7ULL, 0xE07B0F824CEF6CB1ULL, 0x411D2EFB1F6D59A6ULL, 
            0xFCAE6CB1A06CE5B3ULL, 0x2DEE4355DF74CD91ULL, 0x0A4BE36CC2245111ULL, 0x63C996C80D9A1E8CULL, 
            0xCE4F76D98D8E60CEULL, 0x02515D61499FADC3ULL, 0x2A896CEBFFEBAD4BULL, 0x325266FC4B5A2A28ULL
        },
        {
            0x6758668AB1015ED0ULL, 0x5D760A0C7420EF0AULL, 0x46CDB1659435270DULL, 0xA1D1EA89DFCC42E2ULL, 
            0xE407868EE588675EULL, 0xC16E4D98FB3D481EULL, 0xE5262F8C4F10829CULL, 0x205F8B5E5AB48E2DULL, 
            0x9C08E72BAF724146ULL, 0xAB4A7032CB914E09ULL, 0x338E9D4724B4CA91ULL, 0xC8A2A2BE0F6857A9ULL, 
            0x00F2C383A3EFF5B4ULL, 0x9FDCDB2E15A332BFULL, 0x97CA1165BCF34565ULL, 0xBB31CC8D7B690B14ULL, 
            0x4AF6DCBDE9084D82ULL, 0x08D3E782DF838B53ULL, 0xBAB1663A33F00B22ULL, 0xCF27F2C1231049A1ULL, 
            0xD750ADE9C5A2864EULL, 0x3F88812E7DABE66DULL, 0x71E64BAD52CE0747ULL, 0x0A30540988856245ULL, 
            0xA92B558318664A37ULL, 0xD7E7D288ECFB9FB6ULL, 0x935142DFAC8F854EULL, 0x35E4A2B4B144B809ULL, 
            0xCEBD69CA44B6789DULL, 0xB03D3E6EB95FED17ULL, 0x6A110073A3BFAD37ULL, 0xF094ED3CF49699B0ULL
        },
        {
            0x619731BF2315B74CULL, 0x452E621AF9014361ULL, 0xF0DEFD8BDA141BD4ULL, 0x22BEBB6A346A217FULL, 
            0x991198922F49CC99ULL, 0x61E7D877F8609C62ULL, 0x877D2D5615F2282BULL, 0x37CFFE2880B6D342ULL, 
            0x1FE3300C83472ACCULL, 0x92B824482111A0FBULL, 0xC89167D10DB33F26ULL, 0xA80CB627A1982BA0ULL, 
            0x7017045C848C8683ULL, 0x1F0CDCCAFE03B6D2ULL, 0x18F019DC1DCF8F53ULL, 0xB7356CB515DC2BCBULL, 
            0x31AA2DC290150583ULL, 0x8597BE3BFC857182ULL, 0x9A995CC4588830BFULL, 0x02D3DE02A98A6B9AULL, 
            0xEFF4AA0BB2C0F511ULL, 0x947E846B5390FFB2ULL, 0x15DD7652605D7DD3ULL, 0x1C7CCEA666163B60ULL, 
            0x400ED6CC369165B5ULL, 0x240AFB991661DC63ULL, 0x30F622D823CF12A8ULL, 0x553DD3CD91ED7F98ULL, 
            0x698286AC37ED4BBEULL, 0x2A51D979FD1588A7ULL, 0x38B4D8BC38B42060ULL, 0x14676ACAAB78FFECULL
        },
        {
            0xE4FE40FE225611E7ULL, 0xB8C212CC02B794EDULL, 0x9A2637D06D4DD58DULL, 0x3407A0E1A1EF33E8ULL, 
            0xA34166EDAD693F0CULL, 0x61E9627B0C4DF929ULL, 0x1FE86423ECDA6AF2ULL, 0xEB14CCA83321A113ULL, 
            0xBE82B251FFE05CFDULL, 0x75D1D47CF0903747ULL, 0x1F3280E9B8938137ULL, 0x7EFE68392F6FF61FULL, 
            0xF7B0F470822E6923ULL, 0xD37089D36355E908ULL, 0x03B70D87F4343499ULL, 0xCF8E7DB4889D1639ULL, 
            0x593EA527A66751A0ULL, 0x79E263E4D2F41A5FULL, 0xD849639A8C9082EEULL, 0xF1EB440EABA0EC2FULL, 
            0x5321E56CAC63F657ULL, 0x0EFF1544F8B562F0ULL, 0x0CFF45190AEF2430ULL, 0x2E9658173AB243ADULL, 
            0x377127AF6038F164ULL, 0x6F45D4FB3317B1F3ULL, 0xFC7EF6BC794E2F04ULL, 0x895FA596C805F279ULL, 
            0x9282957FA17782C4ULL, 0xED485C8C9D9D5EFDULL, 0xDB782F00D03FB6F4ULL, 0x119B19191E502FCBULL
        },
        {
            0xA8E5951435C053C8ULL, 0x44761D1C5681DBC6ULL, 0x4F327E06C29F8A5BULL, 0x3D5F04671BED8F19ULL, 
            0xD16CFBA49F582C6EULL, 0x784B6D08D2CF9CABULL, 0xE1F554DE5CF8E22EULL, 0x738297BF980A2571ULL, 
            0xFBB1CC9BD8E55BCCULL, 0xE6A71D217D2C1D3DULL, 0x19AEE4834C73B558ULL, 0xD2C455D02AC36C07ULL, 
            0xE3AB92AD2111DA7FULL, 0x49678D09289EDAEBULL, 0x51EED0A351DDBF4FULL, 0x54FCF74DB88CE32DULL, 
            0xA68F2CE870C472EAULL, 0xA4DD999ACC5ED4DCULL, 0xBE21EDBB3E952337ULL, 0x1996339061AA7D27ULL, 
            0x026048091B771F29ULL, 0x6AF358F9EE41CC3BULL, 0xD96D1827076EFE29ULL, 0x95ACE629428AFDABULL, 
            0x57DCF5616D8E738DULL, 0xE85552215618CF3EULL, 0xE8DA276B93595F68ULL, 0x9F6A553F63DED5B6ULL, 
            0x25D083963B33CCD8ULL, 0xE79DD2A008C58DE9ULL, 0xB366BBD0BB06AC5DULL, 0x2236442AA1FA6D86ULL
        },
        {
            0x1E8173D0478A0635ULL, 0xBA0F0E85E043A496ULL, 0x9D640254DF833C40ULL, 0xB609F318135F277AULL, 
            0xAC2DA4DB466D3336ULL, 0xFCB227BD72FC7D1AULL, 0x2CDB7FCF17D2791EULL, 0x2009E5B448BDA173ULL, 
            0xE0B28DCDF9E5D348ULL, 0x97FF413126CA83FEULL, 0x576AC780A6F4E0A9ULL, 0x9AFF3A241B19BF9DULL, 
            0xE91CC7946310A58FULL, 0xBF041B03EC8AD3C1ULL, 0x66E9902CFC90746AULL, 0x2B887C9D7C1A2E94ULL, 
            0xEC9AE75C318A61F6ULL, 0xB1A19AFAE0CC4722ULL, 0x4BCD47122A576698ULL, 0x1338BCA615B988A3ULL, 
            0xADE04DF725460783ULL, 0xFE4B5BCDB469EFDAULL, 0x0E2225EED7127C26ULL, 0xD02782E3303D974AULL, 
            0x543352BAE1F818F3ULL, 0x115A440E3E9DE400ULL, 0xB80115FBB5B73C64ULL, 0xC4405AF47C5F8C70ULL, 
            0x6329E03D5B68335AULL, 0xEAD07B4AE6FB6E29ULL, 0x400B2C8B971928B1ULL, 0xF084C26C434F767DULL
        }
    },
    {
        {
            0xE15463F62B9F3A99ULL, 0xF5BFCCCE83A2434FULL, 0x8DFFE5F35DC31D38ULL, 0xF22806985ADE4052ULL, 
            0xF994E9B19994D3CFULL, 0xA7D23BD9344BFBAFULL, 0xF44D88FE95DC1871ULL, 0x239141034A6B4040ULL, 
            0x2AA87F915B35AEC4ULL, 0x2708E7DF22E8B1BDULL, 0x203A26580489C40AULL, 0x6213399AB88CBF54ULL, 
            0xB9A7EACB26FD826CULL, 0x96261DF2DFCA87F9ULL, 0xF5BC34D1B88F5FA2ULL, 0xC3BE1ABF178AB746ULL, 
            0x30034A45A6F2FDFEULL, 0x1896CD5ACF2DBDF2ULL, 0x802130EE8A1AAFE2ULL, 0xABCF3C5B0546CA2CULL, 
            0x26B9B2E0505C9230ULL, 0x3D61D2EC5C30301DULL, 0xFD50CD603795258CULL, 0x91582EF1F2062F6CULL, 
            0xD479E0CD8C745F16ULL, 0xB46F692DD9C73F14ULL, 0x1A205CD1839F54CBULL, 0x626F8E375BB68DBDULL, 
            0x28C001845A6176E9ULL, 0x03FD84E9FA549A36ULL, 0xEE1689A38684E08EULL, 0xA4B7EB32E243C6E9ULL
        },
        {
            0xC1BD9CDE857C6A36ULL, 0x21E288B71AA7281DULL, 0x717EEABB154BB897ULL, 0x2275CAC6E1D94784ULL, 
            0x60400AD8DA567D79ULL, 0x23544AA65B3D37FDULL, 0xED6C5783F0A3BBBFULL, 0x867CD2CC1731A864ULL, 
            0x76023ED4B8711A8EULL, 0x2B04BBBF43E02598ULL, 0xD52CB91033017819ULL, 0x5ED1E9E28DDEEFFEULL, 
            0xCC2403C73940984EULL, 0x345CAC13DD53A522ULL, 0xEE11D2E0117D2EC6ULL, 0x6C6A96671CD8ABD0ULL, 
            0x3694ABDB60D55C5EULL, 0x75280F1CB99CD7F9ULL, 0x61571E207157C340ULL, 0x92791FC7B64DA184ULL, 
            0x317409E670BDC63BULL, 0x44F26B7E83E500B2ULL, 0x0E444EC74FEC920BULL, 0x3BD4E18685F2B460ULL, 
            0x3D5D1665B2A021A4ULL, 0x52DB554B54B74204ULL, 0xB4DFC3F7424C227EULL, 0xE12F71583D57F459ULL, 
            0xAD9DA1EDEE99BEDBULL, 0xD258EB3CB3309BD2ULL, 0xD13CF8B9C388AD6DULL, 0x875110A257C6C416ULL
        },
        {
            0x9A8C3A9A81544326ULL, 0xAD964CC4B35E3AC7ULL, 0x83B3FD7F95A9CA2EULL, 0x0C6ABB3DD9CB6869ULL, 
            0x8DE191E0233F3713ULL, 0x7E3A9046267B1D06ULL, 0xF6FCA60140489219ULL, 0x10F039A419E24E79ULL, 
            0xCE277ADF29CEA167ULL, 0xA1A418E484D8B0D3ULL, 0x29FC6958B9317388ULL, 0x92A2384587F55482ULL, 
            0xC98FDE4112FB7AFCULL, 0xF0EF6AABBCA2063BULL, 0x0F01CF72370457DCULL, 0xB8F4A123EE14B7E6ULL, 
            0xDDBECD6679A59A42ULL, 0x637A765410444D96ULL, 0xFF486CB34187FFDFULL, 0xE788102D63CDCAD6ULL, 
            0xF052A71552321891ULL, 0x0DA4E815DE56EF9AULL, 0x351B711CB0EC93F6ULL, 0x78B6B5721078364AULL, 
            0xCF4F3E4BF55C9045ULL, 0x252146D2571824CCULL, 0x420EEC3B94F0F6D2ULL, 0xD379E65B2CBDA921ULL, 
            0x86AACED87EBD3EBAULL, 0x88B33973F4135041ULL, 0xBE69A54C235E1643ULL, 0xF7276B3FD9880F9AULL
        },
        {
            0xC0FA5948E4A78C0BULL, 0xED9145BFC2960F7FULL, 0x8BC256F7976D9E89ULL, 0x2D396F1A0FAD0275ULL, 
            0x4FC74766993C901CULL, 0x3D227E02935FF4F3ULL, 0xBB3EE1657365CCD6ULL, 0xE63AA170D5BB1A11ULL, 
            0xAFBF9FDEB5D2BAE7ULL, 0x6EEB39F8C8D83365ULL, 0x393853833C6E5860ULL, 0x6BFB86BFB94C69F7ULL, 
            0xFA920123BCB9235AULL, 0x38175AC1A45AD9AAULL, 0x7BABCD422D019776ULL, 0x72C1086B20099448ULL, 
            0x8EBD6716C0498F30ULL, 0x4854911C8F8A0648ULL, 0xF3E371C3B20E8361ULL, 0xC636D6B6F897A280ULL, 
            0x479160DE7B69220EULL, 0x460215F194D41765ULL, 0x4B100E7A46D220CCULL, 0x37CA8105476230DAULL, 
            0x282B158CD10D0BDFULL, 0xCCDA68BDCF1FB068ULL, 0x66C6A915CA0C4E2FULL, 0xE633B6027741762EULL, 
            0x4DCA4097924274EAULL, 0x64BED95FEEA7AFC3ULL, 0xB9A6837CAB1605D3ULL, 0x771C59AC45D54F09ULL
        },
        {
            0xCD095BC7C91FDB6BULL, 0x73C2EC81E74459A8ULL, 0xD7522F63E8235FE1ULL, 0xF74CA7096E446B43ULL, 
            0x6E06C91210E25711ULL, 0x8562C11BBD455A7FULL, 0x1E95EEC55D971482ULL, 0x79EB18B5C27843D9ULL, 
            0xA2BB3AA7482F26ADULL, 0x650D99E5B046286DULL, 0x7B738E4544457C09ULL, 0x424BAA373E5D0861ULL, 
            0x4683D140E82E7960ULL, 0xEC7ADCCFD9C9DEAFULL, 0x1270597B0EF108A5ULL, 0x08D6A8E2B7401986ULL, 
            0x549DC7075FE72912ULL, 0x221E7BB43C04620AULL, 0x22FD41DDA91A7E76ULL, 0x35CC42E434E27AC9ULL, 
            0xB0664762C3903BD1ULL, 0x684D3885EEF384CAULL, 0xEC2DD8C9975E1892ULL, 0xB6EF2B6C485C3341ULL, 
            0xB47765C9EEE4FB3BULL, 0x158DD45B0088047BULL, 0x930D762B8E7CC6B7ULL, 0x7558FBA06DC8C773ULL, 
            0xC4BEC6A8CDA85C77ULL, 0x9ECF26D830A04A6EULL, 0xFC4EEEB89E0A2506ULL, 0xEB4AF45A65E9CD8CULL
        },
        {
            0xBE280590BA548ECBULL, 0xC205D4AC2B25B6B7ULL, 0x4E7E876B89B6460CULL, 0xFE65E354210F7672ULL, 
            0x982F76281C99CBA7ULL, 0x1F2DC22A83EC3748ULL, 0x2DF3232076ADA6A9ULL, 0xF289EC1F7668919EULL, 
            0xDA9938391F55BE05ULL, 0x3C4F9CB64EEC8CDDULL, 0x77BB8FC2578735E5ULL, 0xC433AC2D000ED701ULL, 
            0x80D455A88D47B1CBULL, 0x4D4CF2B5594F91ADULL, 0xBA965F6673380BFCULL, 0x42756D157F8877A5ULL, 
            0xD6EA975D4F23BCD6ULL, 0x094B9942477982EAULL, 0xFB3DE6B50DAAEE78ULL, 0xF741D442607F2C6EULL, 
            0xEFE5B747F83118D0ULL, 0x2F657F68ADEEB5DDULL, 0xBDD2C96153EA7DE6ULL, 0x2A21587D3E4BED7CULL, 
            0xD7E3F4DDD992B1C4ULL, 0x46C199197770B10BULL, 0x0AF3A0EDD287AAFBULL, 0xE9FB2B82FEA95F18ULL, 
            0x9D1A9AE435797EA5ULL, 0x11E7631080E79B2CULL, 0x65B2DDEDCFF3BF09ULL, 0xFFE993296CB23164ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseGConstants = {
    0x13B88451DB298539ULL,
    0xF28AFBB96D51DA0EULL,
    0x64D45F32056990DDULL,
    0x13B88451DB298539ULL,
    0xF28AFBB96D51DA0EULL,
    0x64D45F32056990DDULL,
    0xD317B136E9A69E99ULL,
    0x042D1A2EF3F53D93ULL,
    0x15,
    0xBB,
    0xCA,
    0xF7,
    0x01,
    0x9F,
    0xE9,
    0x64
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseHSalts = {
    {
        {
            0xEED11C7194C02610ULL, 0x635488EB7D87527BULL, 0xD87960AC78810109ULL, 0xA66098C527B0CBF3ULL, 
            0x3FE6F42B8C3D0060ULL, 0xA62885953591AC59ULL, 0xF2F6635198428678ULL, 0x3EFA72CACFFBE8AEULL, 
            0xE5A62F0ECAAADF05ULL, 0xFB12C71987E94A9BULL, 0xD834CD83735E43E2ULL, 0xC9B3ECAC4299B89BULL, 
            0x40FFE36EADB84916ULL, 0x233B508CC2534E3FULL, 0x9E455B34E51D1DFEULL, 0xB0EACC3B148FA09DULL, 
            0x5D95D5D25EC01A17ULL, 0xB44A471B798510B0ULL, 0x152279808EFC0CBEULL, 0x0AB6CEE137D1FDE1ULL, 
            0xFB19A0A416B45C78ULL, 0x5B58448302CA6E2AULL, 0x6EA3E870714DD90BULL, 0x1B863A08FCF9478DULL, 
            0xE54F10517856D799ULL, 0x037A06660EE412C2ULL, 0x85BFED41F24C36AFULL, 0x2ECCF0AB2B03FB4CULL, 
            0x07511306F60CBFB3ULL, 0x945C7D1AC3EBB4FEULL, 0x20F0BEABE023F5AFULL, 0xA8912F79D03E1C90ULL
        },
        {
            0xAC33FE7ED9A3117CULL, 0x59A5D5FC770499B6ULL, 0xE0309803A067E5E0ULL, 0x9EE50D56AE8C6DF5ULL, 
            0x6B1720DAD0382B27ULL, 0xBACFD5035A1851B7ULL, 0x2914AAE49D59FA94ULL, 0x4227BBC644DB40D8ULL, 
            0x622CBA00BA527D1EULL, 0xA423000685120ABFULL, 0x871E4611B666AD3CULL, 0xE238846F34292800ULL, 
            0x73E7579C8D0EE532ULL, 0x87F6C004B253698CULL, 0xD5F494873FEF8DF8ULL, 0xD42CFC11A09C6212ULL, 
            0x005B3DCCD19EFF38ULL, 0xA3EA07AE0879AE18ULL, 0x47E3B96F8F5BA76AULL, 0x26FD70411CC24B2DULL, 
            0x63B9F70F6C7A04AFULL, 0x42DE9FDE39CFF282ULL, 0x9158EDB809039AD1ULL, 0xF533D0FFECAD53ECULL, 
            0xC7B82D9BF9EE197CULL, 0xC28400D11166E3C4ULL, 0xA71FD765F92C0663ULL, 0x63C5FF54F1DE18D8ULL, 
            0x37A4FA9D77460535ULL, 0xCE0C55292230255DULL, 0xFAA2761FA7FB66AEULL, 0xC5FC8E89DB77C02CULL
        },
        {
            0x1CF5ECF90EF4D320ULL, 0x6A7DCBD4E6B8C941ULL, 0xAC2AF733D76E7A57ULL, 0xA2FC721EA764CDB8ULL, 
            0xD54D10E4CBD32AD1ULL, 0x9073C1908F77A513ULL, 0x0A034EAE0977B9CAULL, 0x7D9B8A26AB9D6B0BULL, 
            0x32FC11CEF9B5B314ULL, 0xFC82C777C7E24FCFULL, 0xF6C85717385E9AABULL, 0x598AC759EC0EBB8CULL, 
            0xF1FD8F2AF797958AULL, 0xAA9514D98F1EF430ULL, 0x6A52E68073247F97ULL, 0x4EEB55348498DF56ULL, 
            0x2280291B9A3F0FD1ULL, 0xB867C2BEACB4480AULL, 0x99C5C9618EFE3ECAULL, 0x7DE85913673F718CULL, 
            0xCB36C16DA3A6A6EEULL, 0x6862A3846A94ABE0ULL, 0xE783AACBA7B0C7F1ULL, 0xFD1A42BDA303BF11ULL, 
            0x73A774677A8A0A75ULL, 0xFBAA82A4DCC34665ULL, 0x3A163B1CCBFBCC12ULL, 0x8E4E6B37DE37445AULL, 
            0x489016F4A4500F8AULL, 0x938D868E6A771B3DULL, 0xB4862CB00992D594ULL, 0xC5F51AA85B1D159DULL
        },
        {
            0x3E8ADFEED7D4D740ULL, 0x75B9D1DCEFABCFA9ULL, 0x3FCC0258280D06D4ULL, 0x6BF34B4FDBADD1B7ULL, 
            0x453BA816EAF1EA11ULL, 0x3DD8571DE7745433ULL, 0x99A3FA02F2F2A8DFULL, 0x751E5C739C4A1157ULL, 
            0x8F2AEAF50AA5C93EULL, 0x567135483938861AULL, 0x95A3EBB0439CC6A2ULL, 0x906630A3CE410589ULL, 
            0x219CC882075998E2ULL, 0x709B94F2B57A294BULL, 0x1746F0F3050914EEULL, 0x73BCE05047A52C08ULL, 
            0x1340E362C6F51C62ULL, 0xEBD6D26F0E194A47ULL, 0x41EF57DDEF10562BULL, 0x3ACF3F1470C25EC5ULL, 
            0x62B6BB28791A1D0DULL, 0x22CC3EEED8E60D72ULL, 0x14D84672C36977AEULL, 0x2F5DB0D319948870ULL, 
            0x514327AE0E8DD33AULL, 0x10F8DC345A29808AULL, 0xB49C16C4D959E264ULL, 0xA049BC4DB0B90FF4ULL, 
            0x670F2E3C1392386EULL, 0xACB0A5686009516BULL, 0xCDE2BD0EF272D816ULL, 0x97032DDC0FDF4649ULL
        },
        {
            0xBFE42647F4A3232AULL, 0x91AEB3CB616A45EFULL, 0xE81D455A3F3ACA1CULL, 0x8BCA64EC6B177D23ULL, 
            0xEED232220F0E7846ULL, 0x1BC83F27114BC5D7ULL, 0x288C062196014F92ULL, 0xFDF822C6CEC55EB7ULL, 
            0xD3FC4826C11C36C0ULL, 0x182FD94FD2C19D22ULL, 0x5D137F3F093A7B2EULL, 0x6454BEFCE21AF429ULL, 
            0x089E8F3BF3A16B39ULL, 0x491BF06F6E39C7EBULL, 0x6CD7D25D8C6A7E56ULL, 0xFD50DE5AD38CEB16ULL, 
            0xE0B8AEB6F94FA8E5ULL, 0x4A38BF058D2AC1B9ULL, 0x9B9F47AE959CFEF5ULL, 0xC4BB46BE1C02E455ULL, 
            0x4D092DCA5A88D421ULL, 0xAB3BFC1D629FA16DULL, 0xB8EA38579342FC1BULL, 0x07B40A61B6F63610ULL, 
            0xEF3DE9A34E5374FFULL, 0xDC2FBBCDEBE32165ULL, 0xEC5FA5062F661377ULL, 0x08A97FF2E104CEE5ULL, 
            0x201C52FAA7332057ULL, 0xE0917EAEF3CAF6CBULL, 0x86F8E1CB30F59B01ULL, 0x6E1DB441DDDDDE83ULL
        },
        {
            0x59033BD3A7E4064DULL, 0xE7D22150DBD38720ULL, 0x7471A2C386872C2DULL, 0x8D5E4407B1B16C4DULL, 
            0xE3A19EE88E5FAC15ULL, 0xFB5E3DB3AA87C61EULL, 0x1C6B62CBE65009D4ULL, 0xD43EA2713F62530EULL, 
            0x022D1C989C7341E7ULL, 0xEA0928E7D68C5B79ULL, 0xE4632E8E2B00B8BEULL, 0xD37C445098988FC2ULL, 
            0x3A3FB30ABAD0661CULL, 0xBF46B16F2B9F0B55ULL, 0x43AB40922453FCD3ULL, 0xA2D30F8E92C080A2ULL, 
            0xA097F864A3F731B3ULL, 0x3D59458800D5356DULL, 0xD8FE77199E5BFAA1ULL, 0xC261B992C55C1B24ULL, 
            0x0A9289CE14F4F2FCULL, 0x46E7F8A5BD6A6738ULL, 0x88C1C42FA2501F73ULL, 0xF7DEFD435FA2B2E6ULL, 
            0x87F7B6A1AAA5DF45ULL, 0x281229E85EDD08BCULL, 0x265715DE259DC2A4ULL, 0x51E701CDEF7927CBULL, 
            0x48455C7661063956ULL, 0x1218C6A8C7CAF2E6ULL, 0x278A89FF298995B1ULL, 0xAB59FC0070F97731ULL
        }
    },
    {
        {
            0xB174F24508B6A60DULL, 0x5CC894594CA7BA38ULL, 0x4E10EFE58C9E0B23ULL, 0xF9700B95DA7E3750ULL, 
            0x6199ED42940D0BF8ULL, 0x90E808BDDB6024BAULL, 0xA5A6527E10006914ULL, 0x003CB85D397D4B6BULL, 
            0xBBE96D829D958B09ULL, 0x664DFC10CD2465BEULL, 0x6F62D617E238795BULL, 0xF496588EEB95F785ULL, 
            0x5EE88C0C2684F17EULL, 0x4DB647CA8C8E2087ULL, 0xBAFBB818AE659135ULL, 0x35BED8A0B77E4102ULL, 
            0xF78DC4F755F95EE4ULL, 0xC372901743FEA23AULL, 0x0D77BFC3AC3C86EBULL, 0x3C906AF39356984AULL, 
            0x0990F7CE75677C54ULL, 0xEF4508700E7A1CA4ULL, 0xA4D6983C0A0F4808ULL, 0x7AE0D4493634B137ULL, 
            0xBB2F0262C240FE4AULL, 0xC818BEBD9C3473E1ULL, 0x8F05EE746209A276ULL, 0x4FDBD424C3243E61ULL, 
            0xDFAA2AD88819E6FCULL, 0x89E1FEA129BE8A4DULL, 0x72892B595291363CULL, 0xB3392CCFF4F32B75ULL
        },
        {
            0x6B8FC2776B5D8D7EULL, 0x82E73F0D43D1E441ULL, 0x26BC8399023AF682ULL, 0x56CF87D8D5B1ADD8ULL, 
            0x6D6A9BE438237127ULL, 0x3D0DA5904E41AAA4ULL, 0x4A734B72E6F6F6EAULL, 0x164D1CA25B88B20BULL, 
            0x9D558BADA9ECEB8CULL, 0x6352AD58CD9D232EULL, 0xA6B6EB5B019F7291ULL, 0xCBE88601ED4D3823ULL, 
            0xDAA4019C6E4C2B31ULL, 0xAB2A4462BBEFF690ULL, 0x3F2FFB915D0E027AULL, 0xAFBC58B1A9A00406ULL, 
            0x8B77E0C33D878928ULL, 0x4B61FB597F6DE27FULL, 0x281DEE929E87C297ULL, 0xD4E59FA440ADE72FULL, 
            0x07ED0F6D1C725094ULL, 0xEA854B9B4254BFA2ULL, 0x0E0330CA05803099ULL, 0x6918521E238FA773ULL, 
            0x1A66BD986D4216DAULL, 0x23B5F6B83EFBCC2DULL, 0x9B4D57C61EE4886FULL, 0x0AFC91FA430CCC1DULL, 
            0xD4DE6639D1242884ULL, 0x606E3EB487D6AF5FULL, 0x31DC55574938F9F5ULL, 0x984A97881FA617CFULL
        },
        {
            0x0A063D3999DC630EULL, 0x9C2EBA3BEF97FE34ULL, 0x7F2962E208FD9B81ULL, 0x7A07CC4AB80EEA77ULL, 
            0x5CC058A5B23E1AC1ULL, 0x1F9DD6C0BCA159A5ULL, 0x989D2CD60C34B8BBULL, 0xB60D854471400D7DULL, 
            0x39E90AC24662C184ULL, 0x1C3F6DDBD74C3F00ULL, 0x52E63E9FF9EE5F69ULL, 0x37B244F35E4D2EB6ULL, 
            0xBE729C9102C17D94ULL, 0x8A34EBB14845967EULL, 0x754BA976CA9B90E7ULL, 0xD05B78A5AB19D59BULL, 
            0xA8CFC81FD1C38D25ULL, 0x64A08E71D862C19FULL, 0x95138A4328A99A29ULL, 0xCB2D1F38FE18B894ULL, 
            0x4C27BD78C3A94E0CULL, 0xBA40EDF7DF589039ULL, 0x152792DBB66EC238ULL, 0xB91A3134DE2B83B2ULL, 
            0xE77D1E1F336E2DA1ULL, 0xFCA9F83BC1E9CA2AULL, 0xF462454D59A2FF3EULL, 0x02B5AE9B8EE827FEULL, 
            0x4C70D8F467FBD788ULL, 0x1937C5EDED2FD46CULL, 0xE4C07A61865B4FBDULL, 0x745021E9A9A16EAEULL
        },
        {
            0x5009B37F348EBC18ULL, 0x8481F778F456FEF0ULL, 0xBD6781BBC9CA8A46ULL, 0x5CF9D5268E87378EULL, 
            0xF31263659BEC27BDULL, 0x9CC8E2C5162B25A6ULL, 0x607F4D22E7260D52ULL, 0xA6ADD51FC89D89E4ULL, 
            0x5FF1E62CE8FFAA66ULL, 0x6CDA073F5A5D48CDULL, 0x421832F9C82969CDULL, 0x61D82A6386E8DE27ULL, 
            0x3D02823143AE022DULL, 0x9DD874D69CE525D1ULL, 0x1A0159F96B866F84ULL, 0x3631776C03752B13ULL, 
            0xCA09BD13B7BF022BULL, 0xE7B4B0F038120729ULL, 0x0F9BD0498770FB88ULL, 0x2F8E8C5206F781DAULL, 
            0x92E3435E0CE459E3ULL, 0x3CB8E035234081EBULL, 0x60A4FA8B5094C233ULL, 0xCB8AE4BFFEFA3244ULL, 
            0x436D129D07B0C08CULL, 0xF71484609893207FULL, 0xE6BC32B4CB8309F3ULL, 0xA66A3AF15252E883ULL, 
            0x5E9856325EA89899ULL, 0x67B6742C0B9B55C5ULL, 0xFABF8238364A8941ULL, 0xEE14A62914EE553BULL
        },
        {
            0x0699DF886F0A260CULL, 0xFFFC9F0D477F39DBULL, 0x7D900EF3DD14DAF8ULL, 0xC0E0ADCABD6441DBULL, 
            0x2CA26758434965F4ULL, 0xB5F186EAE211CC80ULL, 0x8563AE53EA0EFE45ULL, 0x573E3B8C2FD00217ULL, 
            0x520D42B92A17ECDDULL, 0x85F93F42218D2C53ULL, 0xDF7F5234FB3C3B01ULL, 0x16143309C49C4257ULL, 
            0x02455EC3FC3B95B7ULL, 0x89EAA7BB3C1B0DF6ULL, 0xF4BCE9866BC64CE5ULL, 0xA28DF46D24B4835FULL, 
            0xF9E45D528AEA0424ULL, 0x8C88030621AEB438ULL, 0x0F962A8969532EE5ULL, 0x108D093F1CC5B21FULL, 
            0xE122DBB198C67A21ULL, 0x28EFD8A33039FE56ULL, 0x48996A84089F2E65ULL, 0x6EBF1195C52C6AB5ULL, 
            0x1CFA769D5E2C5E8AULL, 0xFD86717A6CCD425AULL, 0x6C76303F22C03502ULL, 0xCF721A8982456349ULL, 
            0x3A4409F8A0D27B4FULL, 0x38B2BD91DD66C739ULL, 0xDFA9AB575AA25A48ULL, 0x7652A485D998F115ULL
        },
        {
            0xCD464AF045CEB2C1ULL, 0xBC58F0AC86AB04DDULL, 0xE010AE1791A0D909ULL, 0x4FA60F7C01D2E7E4ULL, 
            0x09292D17199178D2ULL, 0x188E3DE33D46F296ULL, 0x3C37506A80953FEDULL, 0x2E1B4BD4E6C46AAFULL, 
            0x2B13C70D2A511DF3ULL, 0x0470B07C3CB0253FULL, 0x219C03902E61D81BULL, 0xB1C2600F1070A5D8ULL, 
            0xD3908DEA6E975210ULL, 0x7F530199C21EC054ULL, 0x1DEC97D03DCA0BC4ULL, 0x0A84F6F1CDCA3038ULL, 
            0x40C42FDE98C92819ULL, 0xB6E9B476F8CBC202ULL, 0x3FEB2508FD983C61ULL, 0x3EE50CB74DED28C7ULL, 
            0xEFE5A9ACADC6DE57ULL, 0x417D69B5B50D0014ULL, 0x5302478310099590ULL, 0xCE59A39E6BC1DCA7ULL, 
            0x64184EE013D069D0ULL, 0xB349C67811173652ULL, 0xF35173D1954EDCB2ULL, 0x90C5FE7F0E7B3BE8ULL, 
            0x9842043A3EFFA2B3ULL, 0x44999E39DA0A7681ULL, 0x5DD3AFC4EB08ECEAULL, 0xF600AA87DEBCF31AULL
        }
    },
    {
        {
            0xB0D06C3CD692371AULL, 0x0200162610F59986ULL, 0x58A8DB482544EF2DULL, 0x0FFA5F535D058735ULL, 
            0xAE3A1D150684665CULL, 0x755A13CE44AB6B9CULL, 0x8E2D679B196CB940ULL, 0x918EC43242C6A60AULL, 
            0xA4BB0654FA35CC03ULL, 0x3DC25F4614A42D8BULL, 0xD245194C8454F4DDULL, 0x5C8052A1E0D8AFA8ULL, 
            0x10792AFAFAC1FF4DULL, 0x32EE6BF6861A82E3ULL, 0x749CCF2D658B0F24ULL, 0x15A4878101826493ULL, 
            0x91F1056E2E0F31C3ULL, 0xC0E9083D671E2D52ULL, 0xFDA773A826425438ULL, 0x7C16CC8C5D19053DULL, 
            0x119ED902C873CE99ULL, 0xCFB0D48D1352E937ULL, 0x47A7A2A1EE303E77ULL, 0x3BCDDAFAEE3BF62AULL, 
            0x1DC8C5D87B8C1454ULL, 0x4CB768E6B198DDE3ULL, 0x924EE67EA326B6D5ULL, 0xE521302179E2C061ULL, 
            0x74E264106F4481EAULL, 0x88593DC92D99A6E6ULL, 0xA37AE05655A1816CULL, 0x56C8228437AA4E67ULL
        },
        {
            0x1D11AB1D39159AB1ULL, 0x74F1BDDAEE20204FULL, 0xFFB52F9EAECB3729ULL, 0x12C487864A12DD5BULL, 
            0x2577B8FA4CA34673ULL, 0xC47DF39518E1F86BULL, 0xD3F6709EE6D892E3ULL, 0x9AEBFFE98F78EDFCULL, 
            0x5DBBF823A3C592B4ULL, 0x5BBA078B19620CAFULL, 0x87CBAB05DB637F49ULL, 0x017913A5F798D4FBULL, 
            0x15F864B3E8698713ULL, 0x832208E05021CF35ULL, 0x1F85E71CDDE08AA2ULL, 0x64D333FE29D80C24ULL, 
            0xF2CC27DEF5F4C33CULL, 0x8A3640F0AA9AB221ULL, 0x6D603BA0DACFCB34ULL, 0x0F6881B814AA7B24ULL, 
            0xDB6C2D88D9340E8DULL, 0x491137A75C0635EBULL, 0x7C226F84B83A0E1BULL, 0x35097ABF545421DCULL, 
            0xD7DD1755F5111B30ULL, 0x5FB6553EE502C54DULL, 0xCD3993949895C274ULL, 0x08BF35DA565D69BFULL, 
            0xED4F4F448C804FF7ULL, 0x5E237A02A05BFE99ULL, 0x5AE910F9577C9568ULL, 0x1C075ED2122C4CF1ULL
        },
        {
            0xBD51481ACA800CCEULL, 0x3174301F8DB9E1E5ULL, 0xDEA277E68529D7ECULL, 0x8D266784D3ACA2E8ULL, 
            0x1E142B4737B52341ULL, 0x36CD63FA78F7FADBULL, 0x4B20B499E7D7DFA1ULL, 0x55AECFD4B444DE2BULL, 
            0xEB4C9D1DAD372491ULL, 0xA48D38158F7C0DD1ULL, 0x0EB989FCB484B201ULL, 0x52B45C18ECF4EF01ULL, 
            0x54B8682E5D61DB12ULL, 0x96EAF99649809749ULL, 0x6CE9A0DECA1EE414ULL, 0x66D416EECBB5A9AEULL, 
            0xDEC320B55E7D72ACULL, 0xA2488EB19F086A6EULL, 0x28AC435CAE1E2F3AULL, 0x261A8C1459BD3023ULL, 
            0x807C57450F9CDD01ULL, 0x6AF101DFF3791551ULL, 0xFD8EB36793E2F5CBULL, 0x419DFF3E2AD14C99ULL, 
            0xF7DDE41D287BC253ULL, 0x21EC4D9F37C87452ULL, 0xE64F22F9541D77EDULL, 0x55C1F40B6BCEA902ULL, 
            0xF4948046F7774019ULL, 0x20BFE8B6E2148084ULL, 0xFDD390F895BF1F09ULL, 0x9611FA2730A1DE36ULL
        },
        {
            0x8D842A1800641798ULL, 0x9925395217A1B5C8ULL, 0xC61F2B14307CC171ULL, 0x1606F1CFA92E1BA5ULL, 
            0x15C3FCFCAF82402FULL, 0xFB89AF145742D84CULL, 0x34DD6BD5C6AE8A13ULL, 0x81AE4E84247C68E9ULL, 
            0xDD52758E5DAFAB91ULL, 0x26B1CD35C0D1F2DBULL, 0x64262D58BEDA9A69ULL, 0xA9F0B83833BD597EULL, 
            0xD99FFC9C9F055ED7ULL, 0xD2CE99CFCEF90D18ULL, 0x85B32E2AA4020973ULL, 0x96BD257FDCC8472DULL, 
            0x5044BD8176AC80E2ULL, 0x8CD5FD341434FEF9ULL, 0x9070A4EED20B5417ULL, 0x129E3CAE869CFB9AULL, 
            0x6608B1A2C941A82CULL, 0xBF2CC84021CA01F5ULL, 0x143325223FCF4B7AULL, 0x37FC1901F1D93F17ULL, 
            0xB408AA5A93E97085ULL, 0xBA6B173BC2F0D37DULL, 0x5E9E3DFD1E82178AULL, 0x2B11C61EEBFC5902ULL, 
            0xC4EFC755D32209A5ULL, 0xA777F2407F98AE4AULL, 0x8EEEB7D4A8F9DAA6ULL, 0xA7DD5253474E85D2ULL
        },
        {
            0x69F1ECE6AD82D652ULL, 0x6D4E0410125A2E8AULL, 0xC937E627B8B8D880ULL, 0x6A9D24ED19D5F6CAULL, 
            0xC56B48ECBD8B0F3EULL, 0x416FFA68E576FF64ULL, 0xC8370FFCA1EE88DBULL, 0x3CE2CF9AA99B791CULL, 
            0x7BA769B7332A7385ULL, 0x912682A69B0A394CULL, 0x49AFBA9CE8232525ULL, 0xB29AFE5678210F20ULL, 
            0x302935A69275AD00ULL, 0xD38D8FE0FA5696B7ULL, 0x9C67576D733A8B30ULL, 0x45977F732549C679ULL, 
            0x8B6518A30714D7F0ULL, 0x7B824F386149294BULL, 0xD9455EF7453C869AULL, 0xEC9C69117850377EULL, 
            0x58FDFF3012B2800BULL, 0x59C5335292C0C9EDULL, 0x0812472822A17213ULL, 0x38A18741B7A5D33EULL, 
            0xC021426970A16657ULL, 0x7F2A5D8F808CAD36ULL, 0x95E2FFE7ED01DF09ULL, 0x51631DC999B13373ULL, 
            0xDC15554218C66568ULL, 0x5834AAC8D84C4853ULL, 0x62870F295CB5C99EULL, 0xB3C7248DD9C5C2FBULL
        },
        {
            0x3AB58CE001AFA3C6ULL, 0xFA866D2FED7BCB92ULL, 0xB6EF438BF56BF135ULL, 0x234553B9EF700565ULL, 
            0x39FFA079E741581DULL, 0x1B4B2DE5D2C6CF33ULL, 0x1B5BD8A65D05E945ULL, 0xF25AECE6C7ACFDADULL, 
            0xC017430CBF4BD1F4ULL, 0xA3BB51A7F1D861CDULL, 0x0F78568A658A4AD5ULL, 0x834660C374BA5FB3ULL, 
            0x746BF3093CA23A4DULL, 0xF29036628032CBBCULL, 0x47CD9CF267EC9967ULL, 0xEC33D191AE9BFF83ULL, 
            0xE8B916046DCC79B8ULL, 0x8409B8C79D41FD8AULL, 0x0FA15A180DD97368ULL, 0xD1A540F34FD75DF1ULL, 
            0xA94F93F5FA5D622FULL, 0xF61541F8A9E0E5A8ULL, 0x1BA759484C7F59C9ULL, 0x488F23B433B6E309ULL, 
            0x16FD8A14CC2C7E6DULL, 0x78A59F5082B066D9ULL, 0x82E984F86B07D605ULL, 0xC26FC5690D7A0A5FULL, 
            0xD5E228120C5B2898ULL, 0x723B967EE293F19FULL, 0x9F2A0DC91C724720ULL, 0xA5F9B48F6BCD8105ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseHConstants = {
    0xCE9A244A692C6B37ULL,
    0xA7FFC92FA63314B2ULL,
    0x9F1E540675F6FA1AULL,
    0xCE9A244A692C6B37ULL,
    0xA7FFC92FA63314B2ULL,
    0x9F1E540675F6FA1AULL,
    0x798120A1B85EB1F1ULL,
    0x6576C679448B564FULL,
    0xCA,
    0x85,
    0x14,
    0x8F,
    0x91,
    0xE8,
    0x3A,
    0xD4
};

