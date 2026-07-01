#include "TwistExpander_Lacrosse.hpp"
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

TwistExpander_Lacrosse::TwistExpander_Lacrosse()
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

void TwistExpander_Lacrosse::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8594F22F90BD804EULL; std::uint64_t aIngress = 0xD6DF3EA55BF84F87ULL; std::uint64_t aCarry = 0xF249D6201CB3850AULL;

    std::uint64_t aWandererA = 0xBB78B2A9BDBEED94ULL; std::uint64_t aWandererB = 0xB07732712A9E27DCULL; std::uint64_t aWandererC = 0xA4187C7E73CB4A31ULL; std::uint64_t aWandererD = 0xD9627863A3C56426ULL;
    std::uint64_t aWandererE = 0xB841B36EAB86A97CULL; std::uint64_t aWandererF = 0xF064414962BA2140ULL; std::uint64_t aWandererG = 0xCF42D61CF4B5A218ULL; std::uint64_t aWandererH = 0xE9E6A88DDD5EE65FULL;
    std::uint64_t aWandererI = 0x9E245AD6A5D8F0F9ULL; std::uint64_t aWandererJ = 0xD928D223D4AB56B2ULL; std::uint64_t aWandererK = 0xFD00A23A7374D92AULL;

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
        aPrevious = 10580145315017089704U;
        aCarry = 11620333572943444887U;
        aWandererA = 18382880616676762579U;
        aWandererB = 17119842554085244363U;
        aWandererC = 14798806378915683147U;
        aWandererD = 17709575942181755639U;
        aWandererE = 12623152609727290412U;
        aWandererF = 12117201397877867463U;
        aWandererG = 16069866970365263550U;
        aWandererH = 13497839775172670848U;
        aWandererI = 15427410455853200514U;
        aWandererJ = 16562423868967654309U;
        aWandererK = 16083788416967329471U;
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
    TwistExpander_Lacrosse_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Lacrosse::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xBBEDDD236B6EB743ULL; std::uint64_t aIngress = 0x9C01BBB7547DF50DULL; std::uint64_t aCarry = 0xF42D5414583B910DULL;

    std::uint64_t aWandererA = 0xD1949EBBF2ADD43AULL; std::uint64_t aWandererB = 0xC6D3B50A2B8B447AULL; std::uint64_t aWandererC = 0x86798C8D607AD396ULL; std::uint64_t aWandererD = 0xBF28218E6AE981C1ULL;
    std::uint64_t aWandererE = 0xEDA90C9BC7F74B49ULL; std::uint64_t aWandererF = 0xD1D4FF91929AB7D9ULL; std::uint64_t aWandererG = 0xCCAACF21E59CDCECULL; std::uint64_t aWandererH = 0xA74F00A47F781DDAULL;
    std::uint64_t aWandererI = 0xC873511192977F0BULL; std::uint64_t aWandererJ = 0x8E57A31B5315D70BULL; std::uint64_t aWandererK = 0xE10603DA95E8B888ULL;

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
        aPrevious = 13303785113312128309U;
        aCarry = 11066612806805587398U;
        aWandererA = 13930630504351606006U;
        aWandererB = 10527453889391876297U;
        aWandererC = 17072087685525720341U;
        aWandererD = 11280667355064816982U;
        aWandererE = 14130927354738802669U;
        aWandererF = 16287753863603975133U;
        aWandererG = 15951755841797389244U;
        aWandererH = 11563699404307628432U;
        aWandererI = 16464911447535178673U;
        aWandererJ = 18359567092701138364U;
        aWandererK = 17629261536631449350U;
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
    TwistExpander_Lacrosse_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Lacrosse::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB7BEFF75DCDFE4B0ULL;
    std::uint64_t aIngress = 0x874F0772655F49E2ULL;
    std::uint64_t aCarry = 0x86F8DC97F74CC0ACULL;

    std::uint64_t aWandererA = 0x90B6513BB10CA43AULL;
    std::uint64_t aWandererB = 0xC919383CA5F3F8BDULL;
    std::uint64_t aWandererC = 0xED7170D03DE08D19ULL;
    std::uint64_t aWandererD = 0xD799BA7E3DF48018ULL;
    std::uint64_t aWandererE = 0xFCC8A99528F37ECDULL;
    std::uint64_t aWandererF = 0xBCA0797C8907F3E6ULL;
    std::uint64_t aWandererG = 0xCC028A4E66B1ADD6ULL;
    std::uint64_t aWandererH = 0xB545F02CF5F791A5ULL;
    std::uint64_t aWandererI = 0xE989795D78807F47ULL;
    std::uint64_t aWandererJ = 0xBFEF15CB0C8A5D9FULL;
    std::uint64_t aWandererK = 0xA40E9C76041F82B7ULL;

    // [seed]
        TwistSnow::Sha256Counter(aSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneB);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    TwistExpander_Lacrosse_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Lacrosse_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Lacrosse::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Lacrosse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8C7B95501536B95CULL; std::uint64_t aIngress = 0xA8163269087728D6ULL; std::uint64_t aCarry = 0x9977EE49D8C7B4FBULL;

    std::uint64_t aWandererA = 0xD0241D6112F0E490ULL; std::uint64_t aWandererB = 0x9A7910DE3060163BULL; std::uint64_t aWandererC = 0x8906121641D44121ULL; std::uint64_t aWandererD = 0xD062525EE686AA7EULL;
    std::uint64_t aWandererE = 0xA7E8D65B7BCA6295ULL; std::uint64_t aWandererF = 0xABB953B4292E02D8ULL; std::uint64_t aWandererG = 0xB55B47DF347A4221ULL; std::uint64_t aWandererH = 0x8943D5C09BD3FC69ULL;
    std::uint64_t aWandererI = 0xF45EDAC88083B17AULL; std::uint64_t aWandererJ = 0xBC0FB35A76D163FDULL; std::uint64_t aWandererK = 0xBADA3FCD46327203ULL;

    // [seed]
    {
        aPrevious = 11461559087516987338U;
        aCarry = 9681097301523582811U;
        aWandererA = 14330239389489704956U;
        aWandererB = 17551647407498885975U;
        aWandererC = 10491513739833132895U;
        aWandererD = 16840799528935861817U;
        aWandererE = 17146913504504224012U;
        aWandererF = 12134482975664461769U;
        aWandererG = 11111370078364156267U;
        aWandererH = 16578213294796059843U;
        aWandererI = 17633707185113959120U;
        aWandererJ = 13648572398844361730U;
        aWandererK = 17921754671252799652U;
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
    TwistExpander_Lacrosse_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Lacrosse_Arx::Twist_E(pWorkSpace,
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_Lacrosse_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Lacrosse_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Lacrosse::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 1, 2, 2 with offsets 1024U, 4148U, 4709U, 4769U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1024U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4148U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4709U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4769U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 2, 3, 0 with offsets 7860U, 1437U, 3183U, 1189U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7860U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1437U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3183U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1189U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 3, 0, 1 with offsets 755U, 6224U, 7656U, 4493U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 755U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6224U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7656U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4493U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 0, 1, 3 with offsets 2345U, 2820U, 4911U, 1195U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2345U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2820U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4911U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 2, 3, 0 with offsets 1834U, 121U, 1196U, 1867U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1834U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 121U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1867U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 1, 0, 3, 2 with offsets 765U, 1744U, 924U, 85U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 765U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1744U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 924U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 85U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 3, 2, 1, 0 with offsets 957U, 1821U, 484U, 1022U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 957U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1821U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 484U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1022U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 0, 3, 2, 1 with offsets 1213U, 1666U, 1050U, 75U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1213U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1666U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1050U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 75U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1991U, 1929U, 2037U, 740U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1991U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1929U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2037U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 740U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Lacrosse::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 3 with offsets 4111U, 2330U, 126U, 4868U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4111U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2330U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 126U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4868U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 1 with offsets 968U, 324U, 4246U, 25U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 968U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 324U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4246U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 2 with offsets 3234U, 4812U, 7359U, 5159U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3234U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4812U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7359U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 0 with offsets 2728U, 2585U, 7857U, 1527U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2728U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2585U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7857U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1527U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 5501U, 5938U, 1525U, 6707U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5501U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 5938U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 1525U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 6707U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 244U, 1394U, 1982U, 2034U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 244U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1394U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1982U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2034U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 999U, 1732U, 1151U, 321U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 999U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1732U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 321U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 751U, 1882U, 1303U, 725U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 751U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1882U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1303U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 725U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 747U, 231U, 791U, 1811U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 747U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 231U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1811U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 1473U, 823U, 1002U, 1151U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1473U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 823U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1002U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1151U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseASalts = {
    {
        {
            0xBFE491435FA3E027ULL, 0x6AAB9DC2357079DEULL, 0x8CE732DDA1F72DF3ULL, 0x4231F63C8AD2EB0BULL, 
            0xFAB11CE60B45B573ULL, 0xACE78F493504D9C0ULL, 0x55E402DEDD05735BULL, 0xA6786D55E0F73AA3ULL, 
            0x3911ED09073E40B5ULL, 0x6C66585C634B3DFBULL, 0x59ACB46122A8D04BULL, 0x715484C362278DDFULL, 
            0x3309885A12559CC0ULL, 0x63BE73B71341C5C1ULL, 0x876019F8B4627176ULL, 0xDB0F20E5057FFFCFULL, 
            0x017777BBFD4706D0ULL, 0x62181E05E2402314ULL, 0x1E8963134389D06FULL, 0x1B6A33FB29E5A53AULL, 
            0xE838BDDAF2E36EA3ULL, 0x919BA9AA9610E279ULL, 0xB1B36D6B00F79BEBULL, 0x4212C77D18E86D6BULL, 
            0x1AA5FE48D79C21F5ULL, 0x88AD0110FBF89307ULL, 0xF2873B2977385350ULL, 0xD43F22BCDDE403A1ULL, 
            0x2BD85B07DF8C1B97ULL, 0xB7CB484D21F0A82DULL, 0x81535122FAFA9C9FULL, 0x367AADCC416C073EULL
        },
        {
            0x8D27AB5606798407ULL, 0x6B1F104D1ED7E1C2ULL, 0x73E390A4B714C6F0ULL, 0xAAC272E5D642E32FULL, 
            0x04F31B339BE39745ULL, 0x0C7A3000D4D07599ULL, 0xB20DB324E75C74A7ULL, 0xADFD6E6E41D64025ULL, 
            0xF7F34B50855CC91DULL, 0x9E56F49B82D30D89ULL, 0xB6C4873A9DCD0623ULL, 0xF6104ADCDCE84628ULL, 
            0x64519396A089FFDCULL, 0xA091C2CCD249EB5BULL, 0x3B17078612F7F687ULL, 0x49338416F26C8189ULL, 
            0x6A59D085584DDF7BULL, 0xF93E15824FF4114FULL, 0x8EC01FC511A96198ULL, 0xDD4BA3D02B625303ULL, 
            0x829D08A419CD7E04ULL, 0x004BEAA04C78B31CULL, 0x00B4CC5D4BE2EE2FULL, 0x1183F7BBD4B03093ULL, 
            0x61D5F7265ADAF480ULL, 0x1AAEAB97330FBFB1ULL, 0xD0121D210EE8B86FULL, 0x3837A52EB85C67BDULL, 
            0x5AF58440D45F4832ULL, 0x8EFDC72B496ACABCULL, 0x82BD8281EA41B36CULL, 0x726539DD921E2BAFULL
        },
        {
            0x5943CBA14B2405D5ULL, 0xC7139DC8425687B3ULL, 0x703F74D8DC66EA50ULL, 0x72AA5266F3A18EACULL, 
            0x75D614BDC96CF6E6ULL, 0x900CFABABCC1A2F0ULL, 0x3FC0290CD2CA0BDDULL, 0x0A405585EBAA246FULL, 
            0x6A9C9AD60B63A107ULL, 0x18E9D60D8A57D507ULL, 0x2909128EF1704E7CULL, 0x9434231C93EC0D32ULL, 
            0x98D8FF15E2824A62ULL, 0x738D6E136AA04AD5ULL, 0x54C44286F2CBBD7BULL, 0x8D7A4DA67BEA852BULL, 
            0x1B943C22477841CAULL, 0x7C9CA7190897EC3EULL, 0x2A6751F145A868B6ULL, 0xF4D00B18A185D4C5ULL, 
            0xA9543FF315567277ULL, 0x10069BBCD4335061ULL, 0xB15F15014AAFE0A3ULL, 0x878E2FD5EB49C901ULL, 
            0x542336216A62D7ADULL, 0x1F57D6DE9F79741DULL, 0xEB9E0F928DA108B9ULL, 0x806DD42343A2312FULL, 
            0xF7FEDDE1B65C834FULL, 0x5D09A158B76AD4B4ULL, 0x4044555F1C7A02B0ULL, 0xCF693A54327A3AA8ULL
        },
        {
            0x9F084985270B0AF0ULL, 0xD33E075B4FB6B596ULL, 0x491A93F0AC6FC36BULL, 0x6A122781EB2869C7ULL, 
            0x87EAA88A2BB0CDC0ULL, 0x70B382FF926BC786ULL, 0x0BB78ABB00E58A18ULL, 0x170C4724C51A138AULL, 
            0xC27497A2AA16E090ULL, 0xA7C2455048454BECULL, 0x65386DF382891466ULL, 0xEEF503F7575E2485ULL, 
            0x0969F69B2703BFB4ULL, 0xBA2A9D52BDA13D97ULL, 0x0311B3A5ACB0CF90ULL, 0x64EABE9ABF953EC9ULL, 
            0x96E634860137A25BULL, 0x3394AD08EA00C1B6ULL, 0x04A8D72B0FA3482DULL, 0xEDFC9E99DB137A20ULL, 
            0x8F8277C5021C0678ULL, 0x85F601E76044F079ULL, 0x6A33832630472D76ULL, 0xFAA51664D73ACC49ULL, 
            0x9F75D34F5837527FULL, 0xAC09A051DE9877BCULL, 0x314BED604009170AULL, 0xDC70D95891FE0350ULL, 
            0xDAD2036DFE9FA58EULL, 0xBE54E542C4391BAAULL, 0xEBD72BA07B098CC0ULL, 0x242D09D203A0CB51ULL
        },
        {
            0x4EFDAE5E49B0C16DULL, 0xD0054D540A93C1DDULL, 0x594A90B0818D392CULL, 0x1E79A15A0F1D8062ULL, 
            0x180E43D677154AEFULL, 0x968DACFBA4E41374ULL, 0x9E0DBB271A2D0509ULL, 0x11751A0991593344ULL, 
            0x04B6DAE548803DBCULL, 0x40E379816B4949AEULL, 0x6E367DB8DF2DB840ULL, 0x29C3D4A5BEA4536EULL, 
            0x1C3D023F9989E306ULL, 0xD21BABD4F1B02152ULL, 0x4389F514C5A22055ULL, 0x2D07EB22E95DB61AULL, 
            0xCB2654EEB28DD503ULL, 0x828F2972F064D174ULL, 0xD4C51FCD10DDAAC7ULL, 0x9A280E765F5AB1B9ULL, 
            0x6A507F7D4BA30E2BULL, 0x6F2C1139235DBDE2ULL, 0x218669D2F3BBB7AAULL, 0xD6836B005491D624ULL, 
            0x8C5188B63D38BE56ULL, 0x0A8AB2D87581AC2AULL, 0x1A1E2551A218BA0EULL, 0xB1459E9AA98C55A2ULL, 
            0xE47B1AE444D976D1ULL, 0x2536C056FA74EB68ULL, 0x9286F35C8C7D4EA9ULL, 0x56FF052290606B18ULL
        },
        {
            0xED8EDC717E6C2A27ULL, 0xF0D02FCD34BEBBB6ULL, 0x125814A3FA24EB03ULL, 0x411BD5942D6AC960ULL, 
            0x98A4142C9DEA052BULL, 0x434EE3F53090DB54ULL, 0xE87EFE1E3EEC5461ULL, 0xCBE59C9672530F8EULL, 
            0x5ADE9DE44C291604ULL, 0x99E728CE7976F6E3ULL, 0x4DD6A8C38F7FE3E9ULL, 0x1A2508388BB9C784ULL, 
            0x03B597054FF358D3ULL, 0x3061F156E2892E15ULL, 0x865C84F2B60D24FDULL, 0x272AC24796E74AB7ULL, 
            0x9FF5FC93685A802EULL, 0xD5476517B3C19035ULL, 0x34EA5F17A5C04651ULL, 0xF7933394D800E921ULL, 
            0xE552988F07838692ULL, 0xDEE1D0F066E53CF7ULL, 0x96C4463C8B3840D5ULL, 0xDC2DBEF7539161B9ULL, 
            0xD2FC153BAF52360CULL, 0xDCF4AFA7932EC65EULL, 0x7273062446613480ULL, 0x347E5FE8E7568F3BULL, 
            0x46A9ED01E2E793B9ULL, 0xE050A2B886863404ULL, 0x35293BD50AB7E7B3ULL, 0xE33F6E39C7CB6F65ULL
        }
    },
    {
        {
            0xDA937CB5A3E59AA7ULL, 0xE9EEF870DAEADDC3ULL, 0xC564092058D0B42EULL, 0x47D74FE3B1F3AC0BULL, 
            0x21B2BD533F38EE07ULL, 0x71A5CC24BA77DD3CULL, 0x2E1EAEBDB52D4EB2ULL, 0x31EA22643D94711EULL, 
            0xD088C859A2B2953BULL, 0xE39D71C4167B984BULL, 0x39F668866558CB57ULL, 0x07CFD608CE1D3EEFULL, 
            0xAB05CBA8F768D098ULL, 0xD3C1E3F40EE50754ULL, 0x4A5370D41BC8CD30ULL, 0x841FBA7A7E41A1C1ULL, 
            0x04387C203F3B6E59ULL, 0xD0DCB79DC0F7D03BULL, 0xCF25A5D5C771FDB5ULL, 0x9989654C32DE3643ULL, 
            0xF932D973B6E190F1ULL, 0x5623EE968125ED8CULL, 0x67C652A183E5C96CULL, 0x46C3099EC8A997E0ULL, 
            0xAC4533D56B312838ULL, 0x2B2C2C1DC44F6925ULL, 0x970E89749D92DBE0ULL, 0x6C754E69B7C82688ULL, 
            0x3CF85DAF15EA7EF1ULL, 0xE7EA7FF7F1EB7342ULL, 0xD4C4A426A0174CA7ULL, 0xB5C5B62A3000950BULL
        },
        {
            0x24BA8623355C1CE9ULL, 0x3FEDEB7D0008C8AAULL, 0x011D3E7783018808ULL, 0xEE37BAEFB211E1C0ULL, 
            0xBCC65FDA651E8EF1ULL, 0x7477E57534D484ACULL, 0x5EA2DC4FA122D192ULL, 0x44EDBBD0AB0AAF54ULL, 
            0x4C0DD8E816FC6872ULL, 0x641402F527C321C3ULL, 0xA6BBF7375537696DULL, 0x813EADB09358491AULL, 
            0xA185D3E0A9DC4047ULL, 0xBB24389325B07455ULL, 0x1F75F9EAC24DAFB5ULL, 0x891CFA0A42C8AFDAULL, 
            0x01486264B362F74CULL, 0x5FA89B930C36EC8AULL, 0x8C6CC9AA3431874EULL, 0x1FD75965D5A49FFAULL, 
            0x5D6E2B8103832DC4ULL, 0x9481D90040DA895CULL, 0x671E30FD663569EDULL, 0xE5B0EA1498E19F27ULL, 
            0xB8EBB54922BEE567ULL, 0x5B639C1856456704ULL, 0x0ACCD054081F5EC4ULL, 0x0045E249C50F69AAULL, 
            0x99EE5A83A156E27CULL, 0x88D65E0E0BE888A8ULL, 0x2C04D91B8E5130EEULL, 0xC7BC83CF7EF045A5ULL
        },
        {
            0x73D32B47F99287ECULL, 0xFD6F6D61547F86F4ULL, 0x83CD8D278A2BDA95ULL, 0x95F05BD8895BFCD6ULL, 
            0x2D207AB1754FAF2CULL, 0x76193400E36FC888ULL, 0xEB0F878033401CB3ULL, 0x254DA970580E7533ULL, 
            0xB18D84DE53C9723BULL, 0xE5E00CC79BA2C747ULL, 0x03547BA4C6DA55F5ULL, 0x9A74AF7B36516DD4ULL, 
            0x97FF86C214BA50A1ULL, 0xB2726349258DA94AULL, 0x6584DA040D03018EULL, 0x4A61E0F97AEB714EULL, 
            0x2E8D73FFDB7D0B61ULL, 0xC8759AABBAC3A99EULL, 0x5D11D053618D664EULL, 0xF4087279CCBC6993ULL, 
            0x9524456032B198C3ULL, 0x99C916EB9AC7E27FULL, 0x62B8FEBCBF6C7F2BULL, 0xDDEE9A3D8E28C80BULL, 
            0x453C9F91842B59DAULL, 0xF91BEDBABEC3B5BDULL, 0xB29B0131A3AA82DEULL, 0xE2014AB297FDDEE8ULL, 
            0x04CA3055BDAA5326ULL, 0xD5A1B2F76BFE39E6ULL, 0x75D832C02051D65CULL, 0x7C2CBE89BFB91F15ULL
        },
        {
            0x88481BD5FA6F70A1ULL, 0x51B8CB7D4FCE5460ULL, 0xA2F9A3B1EF5361EAULL, 0xE243EDEDD8C862AEULL, 
            0xFDA3A62ECF6180FBULL, 0xBD4419A9AAE6B672ULL, 0x344E857758908385ULL, 0x622A6BDE39B2921CULL, 
            0x476572DBC69ECC53ULL, 0xCDE754E44AD440A3ULL, 0x9084C6E5F0D4D018ULL, 0xA703A464D49FD884ULL, 
            0xADB90AF0250D5AE5ULL, 0xADDD757DB307453FULL, 0xD4A79D06B1CDD517ULL, 0xE19443E8BA189582ULL, 
            0x460C927232089EE2ULL, 0x4922BBC0F56DB382ULL, 0x4C2C07848267CF45ULL, 0x005737D9523FF921ULL, 
            0x72371A152D798197ULL, 0xC9CD707B6D0641A9ULL, 0xBA83939F5EE3026AULL, 0x5AA3FA7830815046ULL, 
            0xF841D651EBC536FCULL, 0x5F81CF2F70819AD2ULL, 0xA2E896E3402B8FC5ULL, 0x21F4E0C94DB51B0AULL, 
            0x76B6BA9823E5E458ULL, 0xCD1CAC9AD5EF3948ULL, 0xD696B3FFDE74F3CDULL, 0xE317917A0DFF3A61ULL
        },
        {
            0x07F5E51D1DAA7418ULL, 0x1014A8BDCDCD853BULL, 0xE87C5A87FF6EA8E9ULL, 0xCA067F3D8C2965CFULL, 
            0xDE1D6BF8F840FF86ULL, 0x7C6D1D14034E3C67ULL, 0x5954B13A3A1BB985ULL, 0x14AA48CE3867B138ULL, 
            0xE4EB69488DCE3E48ULL, 0xF7FE600AD3B51E9CULL, 0x75D588D4A35487BBULL, 0x20AAF12AE3736D1AULL, 
            0xBE680364D1F5E560ULL, 0xFFA8781324257BCBULL, 0x966D58E3298B35CAULL, 0xF73B15C0A503953EULL, 
            0xD96BBE2B6FA0BCCEULL, 0xCE63FABD4D568E2BULL, 0x6D09F09740092FBDULL, 0x946F087D4CE0104BULL, 
            0x2E9499BCD894E456ULL, 0x9ED43A998D3D893FULL, 0x46C29B341F4BAD2FULL, 0xE9D8230B0B96D642ULL, 
            0x8B78241343C1A5CBULL, 0x78AA239B1BFDDDE6ULL, 0x0F336A276B055401ULL, 0x99D570CF35174DD6ULL, 
            0x0131114F4331134BULL, 0x4DA123F9CB99D3ADULL, 0xCE597D2F98206B3FULL, 0xD46C281525BAACDAULL
        },
        {
            0x4B4EE222D41F6910ULL, 0x621DDFE5D0AF3579ULL, 0x8E52A7107180C68DULL, 0x695277F1CE59E27BULL, 
            0xEFCBB5BFD6C8A27FULL, 0xD6F64C431562E8E3ULL, 0xCD883BF1D70E354FULL, 0xD0D758325505DB1DULL, 
            0xFD903E38FFF3668EULL, 0x7547C4332E12E138ULL, 0xD2F0D8DCE3DEFC04ULL, 0xEE3A3982D80C4F85ULL, 
            0xFB00B9E4A7965757ULL, 0x4BB9745A7ADEA117ULL, 0x6F084E202BE32837ULL, 0x50ED150A6FAB51A2ULL, 
            0xB9441A19477DDC3DULL, 0x8442E9146BEA815CULL, 0xFE642A13A778AE44ULL, 0x70E56DD966F9387CULL, 
            0x6EA8E07B4DFF1407ULL, 0x3C9C380A55D9EF70ULL, 0x1AE73E76C5FFA05FULL, 0x12EF86FAFB257CF1ULL, 
            0x465AF0B94C7B2A7DULL, 0xFA44F4897AA54E28ULL, 0xBCCBD22FAE801EF1ULL, 0xF9E4F90045B3B78CULL, 
            0xF1A33EA63F1C504AULL, 0xABCEB6A2C7D22FAEULL, 0x237CFEF24B903603ULL, 0x3EBAEB33F188CBE0ULL
        }
    },
    {
        {
            0xAD05A5027997CF70ULL, 0x5183E243B9A5F233ULL, 0x6D1998B57E4D2F53ULL, 0x2C78B5229659D043ULL, 
            0x3725B12941EF59F3ULL, 0x9D5EAE30C1C376B9ULL, 0x9F4441E5A286A41CULL, 0xA69B65FB2E7D8B5BULL, 
            0xD978317F51F66F71ULL, 0xCCDBD2BAAC927315ULL, 0x6BB0DDDEB95E5793ULL, 0x77D123ACBA6916E4ULL, 
            0x549E83482C380CB2ULL, 0x6520EEFCB8ECD1A5ULL, 0xCE3062EC6A7CFEBBULL, 0x7D1488DBC1C9E92EULL, 
            0xAE3390489E917946ULL, 0x8970DDC27D432260ULL, 0x860323B9D7CBCB0FULL, 0xAD0824B15EAAA0F1ULL, 
            0xD289D67ABF30A5C3ULL, 0xB476F6C3B0E72977ULL, 0xB8DA8FDCE774F2EDULL, 0x654B1E934F579F5EULL, 
            0xCC5DCD0B46013A76ULL, 0x26F6D9D4953DA064ULL, 0x56DC4C3318FC9CEDULL, 0x2D47FA559C8EF375ULL, 
            0x6045F81DC59DBCB9ULL, 0x31F4C89BBB00CE66ULL, 0x0307197AA415D7B9ULL, 0x449AE0F3016FBF8BULL
        },
        {
            0x65FE6CD6866489CEULL, 0x3855AFD0ACF52FC5ULL, 0x7299DEF14BF3469CULL, 0x56C0E1D6952C99EFULL, 
            0x31E80F77149F47D1ULL, 0x6E3B001F7DAE9530ULL, 0xDA838E4D3A0C2C14ULL, 0x97C806C90D2A5D42ULL, 
            0x8BBD5CB2A09B9691ULL, 0xA8204C653DAD3B9DULL, 0xAE5517A551325088ULL, 0x19265FCD5260953EULL, 
            0x2FA949A0E21B64E4ULL, 0x6E33C24B89468687ULL, 0x466EA6CE95D401B3ULL, 0x489C227EFD974632ULL, 
            0xF195B3CEB7AC7597ULL, 0x0819330960363A5DULL, 0x58A4DF32B607C3BAULL, 0xDC5899816CB2D3D5ULL, 
            0xE91CF22F1BC2A3DEULL, 0x6E7C0ABDD12E9BFAULL, 0x0945D3A617A4D86AULL, 0x06A2B4ACC0E13918ULL, 
            0x65A62263A209DCC0ULL, 0x073A51722DA72A4FULL, 0x8AA750057A16C454ULL, 0x2CF59FBE8D14AF18ULL, 
            0xC0268A1C2B3AA60CULL, 0xB0B863AE4694E4A8ULL, 0xE9296A39CB18618EULL, 0x760776C85805B27EULL
        },
        {
            0x30C48C7B0AD3C807ULL, 0x9C9F7A8AEC7461AEULL, 0x8E18B204F0CC1420ULL, 0x05B427477F7807B5ULL, 
            0x7B6BC69739619CB6ULL, 0x4E37AF5D83D2029CULL, 0x9ECBD3E0F1EAA4A0ULL, 0xF708DD6C298CAEE7ULL, 
            0x412D61BBA27863B8ULL, 0x505453F145A296C3ULL, 0xC1EF56329519468BULL, 0xBC79CCF07517C7DCULL, 
            0xF1319142AC1AEA38ULL, 0x0AF1424F0C76AD5AULL, 0x5D9EAE674C5CF8D8ULL, 0x402AD24AA87B41A1ULL, 
            0x43FF202888D8C966ULL, 0x8FA12699C9193709ULL, 0x1098258B212A1FA4ULL, 0x031624A0CC51551DULL, 
            0x872D4BFFFB1B2EC8ULL, 0x64B0A3F69D6F0577ULL, 0x0BC76A1F73BF1728ULL, 0x238B886F73F8FF64ULL, 
            0x700F2E7F6BF58E40ULL, 0xA579AFFE3F0FF639ULL, 0x271C802F390C7FDCULL, 0xBEBEAF24563CE644ULL, 
            0xBC2303647B703D74ULL, 0xD5B609D1568A419CULL, 0x4D0C8084709E9ABDULL, 0x9F3633C37F674D0EULL
        },
        {
            0xA0443AD4E4830A6CULL, 0x6D8A17170DD313BDULL, 0x296FD2829C2AA03EULL, 0xF95DE23E7336B560ULL, 
            0xC79026E32A6F53C6ULL, 0xBB1C995F96BBA1CBULL, 0x3A8FB1C5831FAEB6ULL, 0x5BE627D41C5EA053ULL, 
            0xD9A5ACA4CD4AE8BBULL, 0xA334C67FA81EDDECULL, 0xB69919EA26A7691AULL, 0x8F4820DAC2137FF8ULL, 
            0x701BC3AE2B3E035FULL, 0x9632B2A6161847C4ULL, 0xE75B0F8D07D3B1F9ULL, 0x977BAC5046FBF486ULL, 
            0x2AE630A9EEAE56FBULL, 0xD7C297A7927AAE8FULL, 0xCE8F334A0A069951ULL, 0xDDD1A815FD5F9155ULL, 
            0x7C312D71B87F1683ULL, 0xEEC43605869722D4ULL, 0x0FB88DCEA072B5DAULL, 0xDD8DF32CC5C759E1ULL, 
            0xAEBC4F750D1AC406ULL, 0x82ACAC6122C3BE85ULL, 0xD2C6F37A034F66F6ULL, 0xADE639574211EFECULL, 
            0xE4A730FB31CB901AULL, 0xAD33EF10EBFBBB4AULL, 0xC0F3E001CE020F83ULL, 0x12DF597D1C73D7B4ULL
        },
        {
            0x508CAF904DB53BDCULL, 0xBDCFC0D6EAD97473ULL, 0xE188A68DD89B4866ULL, 0x9FC1F8360E293C24ULL, 
            0xBF442C905FEA83FBULL, 0x0EA0AC6BBDBC9631ULL, 0xD0C2C8BA5B25A4B8ULL, 0xC7541472AC802B1EULL, 
            0xB85CB7110D6D8C73ULL, 0xF5163DB71A7939F0ULL, 0x2281886BDF2DAC2FULL, 0x702D9C6E3E2D33D4ULL, 
            0xEC0D8CF59749332AULL, 0xC80021DC7A788CB2ULL, 0x2D7B8EBA93CBDDE0ULL, 0x2C3A6F52DDA5D856ULL, 
            0xC1AEA05498E11FC9ULL, 0x43EEDD8D07CC5092ULL, 0xA8F563E842C5B29EULL, 0x66FEF63894C1385BULL, 
            0x6286CBCCC0848384ULL, 0x8BB0193249A28B60ULL, 0xD6110173C4403B25ULL, 0x9360BC0668693E85ULL, 
            0x1B19AB84A46EDB7AULL, 0xB3B3224F9DCD2C8CULL, 0x497FC65249B392C9ULL, 0xCFD735A5EEB9CFA6ULL, 
            0x959D8AA41D4A2880ULL, 0xFBC1B54AACFC8CF0ULL, 0xDBADC9FCB9DD5A1EULL, 0xA8C88E71D56480C6ULL
        },
        {
            0x0AD28FBF8086797DULL, 0x8E924C03CA6D4740ULL, 0x1581C4B52B26688EULL, 0x202850DDA436528EULL, 
            0x30F9871177CB2DB5ULL, 0x2A7C4BC19D3BB00FULL, 0x1CF34E025930FB16ULL, 0x9E85B2496C209E02ULL, 
            0x14AF5906054B86FFULL, 0xDB17C2C39BFDF28BULL, 0x2BAF9C82C988E26CULL, 0xF1744385CD6C8F17ULL, 
            0x75371EEF5B8341B5ULL, 0xA16F5F5682A497EBULL, 0x771AC5CB931410B8ULL, 0xD88D919B3ED81312ULL, 
            0x585A7A060EA4FCDAULL, 0xB0DF3257D00196F3ULL, 0x78E8851BEF8F7610ULL, 0x122A6BCAE2092CC0ULL, 
            0x414A417B8C0B58E4ULL, 0x159348B13232B008ULL, 0xADCCF76DB2A3C11BULL, 0x8B76EF438FEC3AB6ULL, 
            0x3795870BBACA14A0ULL, 0x78156E70DF14E9FEULL, 0xEB19BC9D999F73A1ULL, 0x0B307A1C20F8DBE6ULL, 
            0xBD647DE9DD65B637ULL, 0x053C20586E5F9D8EULL, 0x07F59416425592E0ULL, 0x093BAD71B1E95826ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseAConstants = {
    0x4320AD1CDD11299FULL,
    0xEA993713CF08921EULL,
    0xAD43FDB3E3261A57ULL,
    0x4320AD1CDD11299FULL,
    0xEA993713CF08921EULL,
    0xAD43FDB3E3261A57ULL,
    0x917D189AD50890AAULL,
    0xF3A92D73F95E5E4AULL,
    0x84,
    0x2B,
    0xB4,
    0x52,
    0x5A,
    0xCE,
    0x8F,
    0x7E
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseBSalts = {
    {
        {
            0x84D835472CE56C40ULL, 0x0EE053B521C27591ULL, 0xA75F5749B2676237ULL, 0x59E8014EE1A92D8CULL, 
            0xBD05EB1897EE1032ULL, 0x8E10A5F1444A9B7AULL, 0xA7B40E9068156A77ULL, 0xA6B7B72574781790ULL, 
            0x33DA148FB8D7F9E4ULL, 0x524D002A939A6262ULL, 0x96B3F86DE6F54C10ULL, 0x9319C371FED20452ULL, 
            0x4A32ED2CB0C1AE9FULL, 0x7464CFF5B6BF6C74ULL, 0x8DE73A59768C4914ULL, 0x9FF111D21368EBB7ULL, 
            0xE27B41E876206E32ULL, 0xB17138DF88C7F11BULL, 0x6909F14352B550F5ULL, 0xD5ECA7A65A2C85BFULL, 
            0x0F8F9C5A984F675CULL, 0x5912322FC1F5EE10ULL, 0x55E87D0DC9124E56ULL, 0xB097FBE6684FB304ULL, 
            0x162AB997E25F9B12ULL, 0x2A9D7BF9558CFC0AULL, 0xAF449FB93D9E9378ULL, 0x8A2C39BD0B9C1830ULL, 
            0x73FEE2A3B035E665ULL, 0xE63C971B7C7840F6ULL, 0x4B59589BE6340B34ULL, 0x433AA51E4BBF4019ULL
        },
        {
            0xB2A944C32360E57BULL, 0x611D0E0C3F5D8E98ULL, 0xB73BC6540230A63AULL, 0xD3291B9C984E646FULL, 
            0x896FB333B9E5BDDEULL, 0x392D0A34C690BC9DULL, 0x668637CAF6144D03ULL, 0xB65416016E89B791ULL, 
            0xEC72306AB4F894A4ULL, 0xEB7DAE281222B93DULL, 0xBC81403C7C48C0D1ULL, 0xC8876B46C853FD0BULL, 
            0x148AF6CD53AC64CBULL, 0x6345DC47156A49B9ULL, 0x2D82972D06239B03ULL, 0xF7FF55CA9D5BD254ULL, 
            0x7F6C330A50FB60D2ULL, 0x5B40E9B80070F7B5ULL, 0xCCF8356B66E17CEBULL, 0x066EE0F0A9C2EE76ULL, 
            0x3862CE0A59606D93ULL, 0xC1739C8B5EE7D1FFULL, 0x95A5FE99AE15DBFBULL, 0x405F7567482487B0ULL, 
            0x37CD74989215CF14ULL, 0x36B9E15486268EA1ULL, 0x7E9EBDC4643E2BDFULL, 0x6BA0EEB383184224ULL, 
            0xC3BF0F84E020650CULL, 0x9B0BB4FC2660D032ULL, 0xC73CB566E7C1F476ULL, 0x0B483DA8809AD033ULL
        },
        {
            0xD70D3D41351CC7ADULL, 0x56F15AA0C199F734ULL, 0x3F108EBD745E7586ULL, 0x74C90F81350562A3ULL, 
            0x53B17A7CBE7DBD00ULL, 0xB772F4E81AEA6DA0ULL, 0x3202B77283EEA639ULL, 0xB82BAFCC7AC2FBACULL, 
            0x4C76C6F83503E664ULL, 0x2201C73CF4A5B74EULL, 0xD72BF3245F0F050AULL, 0x31205810FBEE64B5ULL, 
            0xB73B9FD42C2F14E4ULL, 0x55842DD0E97394F4ULL, 0xE8059040D095ECB5ULL, 0xB0428009064CFED0ULL, 
            0xCEC56DAFA0688317ULL, 0xECB5C856C5135E8AULL, 0x8FBEB1ECEF5A1148ULL, 0x7ECA67E08023B2EAULL, 
            0xFE722C2CB87B8629ULL, 0x0912400BF2F5A71EULL, 0xB644EEBD9D9612DDULL, 0x42ADB633AAACAEECULL, 
            0xAAD5D1F49C32774FULL, 0x5D74839C6FA55980ULL, 0x7B2C230B395A6C84ULL, 0xE71CB24BAEC61E0FULL, 
            0x4F325CC1E91A0392ULL, 0xCF2B68F9E3CD7BC2ULL, 0x6F4CE1F3E2CC7DBDULL, 0x0FF061714673D431ULL
        },
        {
            0x73956F127DDC69AAULL, 0x55B4BA82B9E72E0BULL, 0x826D13EBF31EEA83ULL, 0x4CB2CD960135E5C8ULL, 
            0x122C643C8E4687D2ULL, 0xAA0E38887BC8345EULL, 0xEC75BD6C512CD579ULL, 0xF47375ABECAF118EULL, 
            0xFC8A6169E0F4FB64ULL, 0x6179337DBEC83CE6ULL, 0x4ADA3BA2567ACFDCULL, 0x56FB7B42B5A9DBB2ULL, 
            0x9E388C03BB025F27ULL, 0x0251426707C057C0ULL, 0xAE57A55DF89A61D8ULL, 0x0DB48EECF357DB0EULL, 
            0xC828B3B4DDA952E9ULL, 0xEC9BDC70BE3F7AD8ULL, 0x7CF182B85530CFB3ULL, 0x7BDD0CCDA03A7434ULL, 
            0x924AFAF2429E9FCEULL, 0xB15A105C85336642ULL, 0x5C0131961F33E801ULL, 0xB22B475BB271D878ULL, 
            0xF370AEDE61F22923ULL, 0xCEBFDB54FEAC6006ULL, 0x9FB8ED017EFBC409ULL, 0x4420AD6D4C7B5C67ULL, 
            0x55CC7AA0F848A616ULL, 0x8A841BA9D673D520ULL, 0xD6030130BD06BB20ULL, 0xF66D8208F473D075ULL
        },
        {
            0x4B6869BD15FA9DB4ULL, 0xBF36D2881AB00F2BULL, 0xDDF9AC2144EB1813ULL, 0x75A4B59CD6ABB0BDULL, 
            0x1405FDE2AB095ED0ULL, 0xA616093546AB3423ULL, 0xA9FD63BEF529D92CULL, 0xC9E1339DD2524E06ULL, 
            0xDF8FA667E8908805ULL, 0xC428EF9BC2A1CFDBULL, 0xB9155ABFDBFDA9A8ULL, 0x04E93FF6BAF862DBULL, 
            0xF5459D040303516DULL, 0x6C64CDA1615AA3F1ULL, 0x4E78635B4F4258D1ULL, 0x7A9C9D242DFDD49EULL, 
            0x9CAAC0039D95775BULL, 0x00620F942483A96AULL, 0x7B8A7CD3E81889BAULL, 0x70817E05909A278CULL, 
            0x94FDD3CC8D30C074ULL, 0x3217DDA9191BAF6FULL, 0x4A107F26F2EC0912ULL, 0xEBDE4F0F4A5452B6ULL, 
            0x0E6B9556C2D358BDULL, 0x8092CB07C8738129ULL, 0xE08CC732C7D3A928ULL, 0x4D4A1CFD4E72BCF8ULL, 
            0x013D659FC228130AULL, 0xE4BB5093F85D3E05ULL, 0x1F381060F68A5B9DULL, 0x4AC5F7C2F951E870ULL
        },
        {
            0xA85182BE5D2830C8ULL, 0x06F68E0248AC95BFULL, 0xA89467CB3366B576ULL, 0xAF69C93F90EF792BULL, 
            0xC802151262863508ULL, 0xA18374478964A989ULL, 0xA4882431A985D911ULL, 0x20826B0B5CF0775CULL, 
            0x527CDA829461239CULL, 0xA150A422E9A5EF9AULL, 0xD20A63057C801EBFULL, 0xB62C1D478DC2129AULL, 
            0xE9D40F981015CB71ULL, 0x0AFC9F0E00BB8EE3ULL, 0x4D6BA07505824E77ULL, 0xCE510EC129AC5E16ULL, 
            0xA9CA11DEECCFCB0EULL, 0x89706AF889C28845ULL, 0x18A156D74436D76EULL, 0xAEF1901BB34575F6ULL, 
            0x44472E9DC557E976ULL, 0xD5AF5CE26C9FC8BAULL, 0x900D1FB6CE0F8F4BULL, 0xC8CEB162B69146F1ULL, 
            0xF27B82E03F3BFC82ULL, 0x03BAA590AD6F05EAULL, 0xE7A9021CEC75ED4DULL, 0x6B3DCEB4B4327684ULL, 
            0x9122530F230D8036ULL, 0x541572FEAE93C192ULL, 0x7648056ED1AA63E4ULL, 0xDA06F9B870830E5BULL
        }
    },
    {
        {
            0x113D06FB3B1F3A67ULL, 0xE7721B18EE0B59B3ULL, 0x6526779B235EA412ULL, 0x0D33EBA9A332A52EULL, 
            0x8B5CEAA8CA48FC82ULL, 0x7747540C6E18F039ULL, 0x2101DAFEC5C2BB46ULL, 0x9FC3E3F2DA78EACAULL, 
            0x425C9007F7EF08EFULL, 0x19C26DB77ED4CB52ULL, 0x44887618EC2BBBAFULL, 0x08A69C802AE32147ULL, 
            0xE6EE4B5EE67D3B9AULL, 0xF6B3AA611BE26CC7ULL, 0x0DCD776AEC4C864BULL, 0x706F40D20AC65B21ULL, 
            0xDAA01488D0EBEEFBULL, 0x7C779CDA1610AF60ULL, 0xF874D13E1E1341E0ULL, 0x8D7C3B5D4F368C37ULL, 
            0x1E7DA5EF431B3381ULL, 0xEB4A27257B80F488ULL, 0x611FA3C0EB4BBA51ULL, 0x21A16D9A007DA129ULL, 
            0xD14E5205410D0D24ULL, 0x393B4897F1904550ULL, 0x484255484E23CEB7ULL, 0xEA829EE47E48DAEDULL, 
            0xB6A7E80EEFAB62BBULL, 0xA759D2AAA32AA0AAULL, 0x21BB82BBCB40B1ECULL, 0xD2E3598E0FB3E25FULL
        },
        {
            0x2CE42BAC47A787CBULL, 0x0D639777C44B4841ULL, 0xECD4000EFAF86FC0ULL, 0x6C69AB3851A9CD7EULL, 
            0xA2B9D1AE5C59E027ULL, 0xB5939BE0C03461ADULL, 0x9BB8B4EBAE72B0BBULL, 0x2178686E5BD9D255ULL, 
            0x4CC341F5728FB054ULL, 0x6D117F11C67E3660ULL, 0xD838E600243323FCULL, 0x1559D8C3371F4F85ULL, 
            0x65CD3B39E685BB9BULL, 0xE4606611ABA4476EULL, 0x732C0BA14FBC6778ULL, 0xB5530581289D98FEULL, 
            0x4A46FB47DED7D2C7ULL, 0xD154518C5919FB9FULL, 0xDA3C9CC06F2965DAULL, 0xC869C739233E53E1ULL, 
            0xC9E6FBB9FC7D507CULL, 0x380FE2BC8C652685ULL, 0x4C47409D78FEA462ULL, 0xC27CA971D34B0B63ULL, 
            0x2A965DBD2A54A56BULL, 0xA2B51FC0FC594CC5ULL, 0x0DE332B37C1965EAULL, 0x5000FCEC01C09A07ULL, 
            0xE9376C56DEA1B563ULL, 0x371350E9942AA505ULL, 0x49E8015C05A8D698ULL, 0x380F96BAB3EF95F1ULL
        },
        {
            0x4DEBEE1DFF31FDD7ULL, 0x1F872E6800C96EE4ULL, 0x32B5CB171C7ED38DULL, 0xAFCB79F7ACEB5CF6ULL, 
            0x1E8C3F7C3611643EULL, 0x0E4CBB43E845AB07ULL, 0x970C089FE6F2D7B7ULL, 0x8319D28F1ECAB83FULL, 
            0xB5998ED94E26AB91ULL, 0x12993EAED4EB99D7ULL, 0x6640CB07439253A4ULL, 0x4BA3AA05AF9324BCULL, 
            0xB4A6789B2864A2B9ULL, 0x57440187035C18BEULL, 0x3E4EDA832C8FAFB9ULL, 0x43574A9169A16239ULL, 
            0xA43F22D1C1CDCA5AULL, 0xB2F50ACDC2A22CD2ULL, 0x4A196BAB82B1817AULL, 0xC3DCD1136CD0E6FDULL, 
            0xD44D693B10052BC4ULL, 0xFB5AB069EF4E78E0ULL, 0x5D94E293344C84BEULL, 0xFAE8761D2354864EULL, 
            0xC2891AD4AC8CE3FEULL, 0xD930F0BC03C8E2D8ULL, 0xF674A8A4ECD3D61BULL, 0x34394E9CD54BF104ULL, 
            0xAD95D4934D536F10ULL, 0x6E177477E375499AULL, 0xA545646BD9B336F7ULL, 0xE79919CFF6E6E5C4ULL
        },
        {
            0x6A177F05990B2099ULL, 0x0022B7C863C300C7ULL, 0x76F2A319ACA46DE5ULL, 0x18782E4D930F5C53ULL, 
            0x8A44396762DE5E4BULL, 0x042D881C83BE3FADULL, 0x3A01C614CFEB5B22ULL, 0x27EE54B0A41A754AULL, 
            0xA2DE436C9F379E27ULL, 0xD935B288A72BF715ULL, 0x6593DF9B944A75D9ULL, 0xF35A16803052ADBDULL, 
            0x3EFB0FA6EDF46440ULL, 0xB800FE6688EF4E73ULL, 0x95570121B09FC88AULL, 0xB7B2824D0445BEE1ULL, 
            0x29A81AC8F137B064ULL, 0xDC97A06FA8403BA3ULL, 0x536875C81ED88A51ULL, 0x50791F1A8D5A2797ULL, 
            0x657D50A2EDE32681ULL, 0x7B382ADF2FA8B8F8ULL, 0x2B60AB5FD5F8C440ULL, 0x9193E8CDF644E97EULL, 
            0x70999144B62E105AULL, 0xA71E9652E231E8B0ULL, 0xD600F1345A1861A2ULL, 0xEE5C73785B6898F5ULL, 
            0x0A004149FDE6442CULL, 0xD09458AF21573BDCULL, 0xC924B15D4EEA6C43ULL, 0xF75A340297433FE9ULL
        },
        {
            0x2B7D589E7DB2C145ULL, 0xEBACE9B160696FBCULL, 0xD0B71662559ABDCEULL, 0x23FD84D8C4449D8BULL, 
            0x402858FBE7400A75ULL, 0x21A25CDF4537A0DCULL, 0x44B7B3E927B25943ULL, 0xA39CA6F50A77BF32ULL, 
            0x35EC09929E9A68CDULL, 0x7017364C61995CD0ULL, 0x2F32DB4362B890B4ULL, 0xF031F9E14969DFF4ULL, 
            0x70B92ABBDA6B440AULL, 0x92E77B963016F32EULL, 0xDB93AF51454E7A76ULL, 0xADAB4656FA781F5BULL, 
            0x978B890BCA39DBAEULL, 0xD435E68D016A2BB5ULL, 0xA5C4BE4EA197223CULL, 0xF4F871C621C6A363ULL, 
            0xD5D1134A7F155969ULL, 0xE45441CC3D89C0CDULL, 0x1AE973EF3B873B51ULL, 0xC9543B257330DD78ULL, 
            0x88024332E84D12F7ULL, 0xD8641F077E735E51ULL, 0x39540BD99B4A3D35ULL, 0xE6F4C9E05697D03CULL, 
            0x62570CB64007E138ULL, 0xD19FB93C606348F9ULL, 0x772DD6D2967AA236ULL, 0x4CC069D019C55228ULL
        },
        {
            0xAC5E43748A973734ULL, 0x14CA5C4A1499A8ABULL, 0x8E1537CCCF2D6BE6ULL, 0x06C40B39FE0EE97BULL, 
            0x39A685E85EC09DABULL, 0x0D5CEF1F6668807DULL, 0x34B3A01E8203248FULL, 0x60923A862B335EA6ULL, 
            0x0B5782612549FD02ULL, 0x61AB3974F021A2F0ULL, 0x7BD9942139345B79ULL, 0x932EDE477AFE2121ULL, 
            0x38DF0F7322664CAFULL, 0xF74D1C56859334D3ULL, 0x28E31711D9E8C186ULL, 0x41BECA45209FEEAEULL, 
            0x60CF0CC3820F3CC3ULL, 0xE0EF5CCE66595185ULL, 0x2F7DB656F97AF94DULL, 0xC96B8932C16B3806ULL, 
            0xB55A58FC20B858C5ULL, 0x909DF802C8B9D6A0ULL, 0xED0FF0B78B4A1B99ULL, 0x29D75D8DD622E7A8ULL, 
            0x3DFF432920B89A56ULL, 0xBEF2266E0304AEABULL, 0xCAFDAAEE1BE58A82ULL, 0xD4FC6259348E25DAULL, 
            0xF72232738BFBA220ULL, 0x9224AFA5EBDB1B8DULL, 0xE8D7C5E7B96642CDULL, 0xED24584B2E2EFCCAULL
        }
    },
    {
        {
            0xB42B591BEF2F2495ULL, 0x8C5DB6FF69DF781EULL, 0x7E65D427E9B7AFB0ULL, 0xA23391CC572A1181ULL, 
            0xC73CD801F9367704ULL, 0xE0805DEDF883A7D4ULL, 0x0F11851B69A08BAEULL, 0xE6470C4F81913F07ULL, 
            0x53F87B5600941EE6ULL, 0x99EDD340C32EE10AULL, 0x16CA24F36F550F1CULL, 0x9BFBCA86A6D640B2ULL, 
            0xB3A4A81613701CCFULL, 0x749FB91732A8EF82ULL, 0xE94BBE1D75358597ULL, 0xE8E380DE809958AAULL, 
            0x1EE7533A04B032A7ULL, 0xA24A3F10F6C54540ULL, 0x94E79D2AC8C3B6BEULL, 0x007D93050D98C03AULL, 
            0x47C4E1E2A4ADF52AULL, 0x97BA1C1C52E808B8ULL, 0x16EEC05C62E0443CULL, 0xA3E35C78635A6104ULL, 
            0xFF53197154EB285AULL, 0x50A3146C67971C0CULL, 0xDB32D467534702AEULL, 0x854BDB05756F5F6CULL, 
            0x62D8760A30D76AEDULL, 0x1805DBB117E792ACULL, 0x131F6826F69520B8ULL, 0x4C5B2ACEA03222E9ULL
        },
        {
            0xA886342BA663542BULL, 0xA4AF894F6B601D7CULL, 0x1AE9DE503E1A37C2ULL, 0x7A407EB74D03E85BULL, 
            0x35765C5937E4EAAFULL, 0xEEE5A6F901A7887BULL, 0xBF21007AF5312A62ULL, 0xC1AE0B8E9375AC4AULL, 
            0x3652E2D545E366F5ULL, 0xC42DD8C43D5D7898ULL, 0xDD8AA75D3268BF98ULL, 0x825BF7B6BB5E1B95ULL, 
            0xEF4063CD3C128EA5ULL, 0x1E1DCB9030586BCCULL, 0x00E983323D9C44DDULL, 0x67008A89626D4DE7ULL, 
            0xAF2A16E29665DE1EULL, 0xD06F7CA3185153D5ULL, 0x9763A35C9DA7FAF7ULL, 0x779462EAE36B06ECULL, 
            0x71FF1D9BC5276134ULL, 0x41A4A9D90057D25AULL, 0xA3E20A6DB19FD4E6ULL, 0xC9EF0477B0F57D3CULL, 
            0x7AE0E7D4D0A005CFULL, 0x6776C928D35E0F4AULL, 0x7306A37C34197C0CULL, 0x05B287CB6ADF6988ULL, 
            0xFCF87AA50E2F65D3ULL, 0x79B3655238EF5157ULL, 0xFD85A644B1AC21F6ULL, 0x3455A08890C43251ULL
        },
        {
            0x12030E224120E278ULL, 0x50103EBB7475D712ULL, 0x2DCBEC6E10656DEEULL, 0xE04D61FC01AF998FULL, 
            0xEFA67F46E2BD189CULL, 0x28146A7965200A5CULL, 0x15B0B583750785E2ULL, 0xE61E65F3BB275E24ULL, 
            0xC969C92F712DAB0BULL, 0x79FD7644DEC5615FULL, 0x6960B389A8EFBE2EULL, 0x3B9CA4B2654482F9ULL, 
            0xC9DEC43AEB5FC9CBULL, 0x4F25C08ECED1C1B8ULL, 0x3B64A7B091A1140DULL, 0x270621A45CC50E4FULL, 
            0x867CBE9917EB4A8AULL, 0xCD402F673C2EEEB7ULL, 0xC71FF0DCC84DF9DCULL, 0x724D470696A67FE0ULL, 
            0x122CAA1602609F5EULL, 0xA9C73CD2915F22B9ULL, 0xAE72E07677434912ULL, 0x8C39F6E4C2540060ULL, 
            0xE06126AD57C3B7F4ULL, 0x4BC33E74823B02B3ULL, 0xA78D381FFB4CBB3FULL, 0xBC10B86B3D96AAC1ULL, 
            0x3AC7ECC0396D2741ULL, 0xCA75350B881DEF14ULL, 0xF7741B73896A93F1ULL, 0x93AEA402A1704307ULL
        },
        {
            0xE5494909BBEC35D2ULL, 0x012CD93FD58774BAULL, 0xD19E47ACA4CB4504ULL, 0x3CACA8BE2B93D655ULL, 
            0xD1D11F36C9A59FEEULL, 0xC744D4881311F571ULL, 0xB874146FD70DC7A0ULL, 0x5C41DE757DD37014ULL, 
            0xB4610CFC028F868BULL, 0x3F74BF8C65C24127ULL, 0x33534CAEB3D187ECULL, 0x6E8B7E9B0480AE58ULL, 
            0x11820789929271F8ULL, 0x1570447C15E0473EULL, 0x9CCC9368ABB6E4ACULL, 0x93689ACAB9D1BA44ULL, 
            0x5F8FE974DD646BEAULL, 0x36129916035AE19DULL, 0x8F927DECE32EFFD1ULL, 0x4C6B6B0190461FB5ULL, 
            0xC273F4A09A80515CULL, 0xE3C2BA9964174DA8ULL, 0x86611D81628FCA09ULL, 0xBB1C6B69DEF2A605ULL, 
            0x8D4F0A99D0198870ULL, 0xC8F240FEBC6C11E1ULL, 0x61D9BC54F3D8F0BFULL, 0x6365B90696C7D4E4ULL, 
            0x0EECBDE86E65F2EBULL, 0x3E7D4B15CF2AB013ULL, 0xF6A971B1BCF53F84ULL, 0x0B71DC77414B23E1ULL
        },
        {
            0xBF4452AF3C5E2F3EULL, 0x5443D727AE0DFBD7ULL, 0xB173B5240F8F798FULL, 0x061E3665B3AA5CD6ULL, 
            0xE0D1F4BF66BF5F34ULL, 0x71CC01B49B2E7E61ULL, 0x62790785DF922A29ULL, 0x81D397668731586AULL, 
            0xC20600323941EFA4ULL, 0x0B87B5C48D4C4922ULL, 0xBBE4462EE56393EEULL, 0x4F19D348405700A1ULL, 
            0x2C83DE367A4BBAA4ULL, 0x2DE74A79994550C2ULL, 0xDFEDE14C3C0EDB0AULL, 0x21BFFE1C379C020CULL, 
            0x6AA6298A7405938FULL, 0x5D00699F67F559E6ULL, 0x5D0370CAA348C58EULL, 0xC35A9175DA6190C2ULL, 
            0x8B6A13C2842381B6ULL, 0x52AC5A3718BAEC6FULL, 0xAF628C5BB5CDE59DULL, 0x98F80DAF3ACCA849ULL, 
            0x32B8B3779CE0C031ULL, 0xFA588BEA47C07DC6ULL, 0x6C91BB5E6238CB55ULL, 0x7236E405E9474490ULL, 
            0x212611B8013E9CC9ULL, 0x893A8F4DD68B3699ULL, 0x1DCB942F5024CECAULL, 0xBB477F5DC4C1D77CULL
        },
        {
            0x643C83FB1CDFE568ULL, 0x48BC99F14422CB5BULL, 0x4A5AA1BC464DB048ULL, 0xCB4305D1982BC039ULL, 
            0x0061A724D6848138ULL, 0x5DAABACABF0A2AACULL, 0x6FAE1BD492500523ULL, 0x5A78661E75242940ULL, 
            0xECA87F80AEDBCF4AULL, 0xD1DAF09B4D5BBF25ULL, 0xF3EA2AA0BC259E26ULL, 0x7F702DDF6BDC59B3ULL, 
            0xEF9A5787721ADC83ULL, 0xABF3C5DCE63A52F0ULL, 0x04C1E071194B7E67ULL, 0xF46B5A4035397067ULL, 
            0x709A7432F4D79A10ULL, 0xDDDABC73A3C16B19ULL, 0x0B9E3153A6DFB19AULL, 0x264865EBF1D3A10FULL, 
            0x28D882106E2F0F81ULL, 0x1146D43463C095ECULL, 0xDEF4F2FE4498D3ADULL, 0x1EEA5A43631F4EFBULL, 
            0xCC107347247D4F91ULL, 0x05B3F1336ED5235DULL, 0x96113975C3FBB857ULL, 0x321B8334EB5094A4ULL, 
            0x8450FB25F1928E91ULL, 0x26008C5D45CDEC7AULL, 0x70A4ECA76D523A0FULL, 0x1AED6B872681E03DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseBConstants = {
    0x637900957A2D2868ULL,
    0x42F9295A0E519276ULL,
    0x6E203B96E19856BAULL,
    0x637900957A2D2868ULL,
    0x42F9295A0E519276ULL,
    0x6E203B96E19856BAULL,
    0x59BABD54FD0058B8ULL,
    0x37D06B5E5CA70AD6ULL,
    0x36,
    0xEC,
    0x22,
    0x9F,
    0x80,
    0xB1,
    0x45,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseCSalts = {
    {
        {
            0x99C0F9429900AC7DULL, 0xAA3E9F41200771A7ULL, 0x56F028F57C845CE7ULL, 0x04910093CAABAC35ULL, 
            0xAF56D373BE8B6612ULL, 0x189320B1157C8B30ULL, 0x1887C4810B50A3CBULL, 0x2FB144DFAC8ABADFULL, 
            0xF616B4E082BB8D89ULL, 0x4FABA138527C5D14ULL, 0xFE3D74E843226F57ULL, 0x88389023A6BA6675ULL, 
            0x6F5F263364009763ULL, 0x4861570B4F30232BULL, 0x426C4A224D1CFDADULL, 0x886B41A59CE4D8D2ULL, 
            0x60822BE247DB3018ULL, 0xC0AE5595D589778AULL, 0x9184BFAFBB5A441CULL, 0x30136E158A8B1EFBULL, 
            0xF6AE2B1969D9F64EULL, 0x2B2ABE9416E788CAULL, 0x1A9A632121E997BBULL, 0x1C0E6E49A924B408ULL, 
            0xAA2CF2561598C362ULL, 0xC6D30FFDBC42CCF1ULL, 0x2CA3545FB7FA9A65ULL, 0xBAED7B95EC6D0223ULL, 
            0x9EF113C5C79DD808ULL, 0x58CDF52D57CB7A27ULL, 0x51052AE7ACCCC6BBULL, 0x030C66981201C20EULL
        },
        {
            0xBBB2F932F40B61C2ULL, 0x68BA0346EDE24E64ULL, 0xF1562273EF64BFFEULL, 0x39CD04CEE467F4FEULL, 
            0xFCDF4F2D52E3463AULL, 0x29907D672EFC6D59ULL, 0x4D908C01AF7F9688ULL, 0xC5111B19A4F49011ULL, 
            0xE3616DE870044036ULL, 0x6036FF95E39C9134ULL, 0x5A4E0A96344A4A69ULL, 0x42164F01398AC437ULL, 
            0xBE4A0F4EC6CF724CULL, 0x664526843A764655ULL, 0x9D8397C7F71A08CAULL, 0xB7A7A72173454E94ULL, 
            0xD9D2C23CFBC00C1EULL, 0x5450023F513E59B6ULL, 0x23726E972DE7495FULL, 0xCC5EDDD177B94873ULL, 
            0xFB982AFFFC8981BDULL, 0x068F6EF7E1EE2E61ULL, 0x86DDEAE5665E3984ULL, 0xED23FFF7D4120BECULL, 
            0x051D177E8886C4FBULL, 0xA4AAA9F74B8A674FULL, 0x24598CDCF9FB4E17ULL, 0xBB9E6CFB6DD812C8ULL, 
            0xAC25A2AD3A6EBA45ULL, 0x3C668D70A1FA39C0ULL, 0x3CCD6C85F009784DULL, 0x2EB6A44F15949EAAULL
        },
        {
            0xCB2FAABCC2C7D9B1ULL, 0x5B303358515BAE43ULL, 0x6832EA39AB29E649ULL, 0x5E744F73E5D74F74ULL, 
            0x85DD97C6F23AA0C9ULL, 0x62A8F6079C70FDBBULL, 0x0CF66A0F3709F7A4ULL, 0xF23AEC0A6EE9D6A1ULL, 
            0x353C806ECE491ED0ULL, 0x529CC37015B37963ULL, 0x090A682B81357BA1ULL, 0x18D1B20BD0728B0CULL, 
            0xE220F729E1E08EFBULL, 0xD353566252DEB26DULL, 0xDE08E7E1D0DDA08CULL, 0xC8BE0074459394C9ULL, 
            0xD5350C9D1CE4DFF2ULL, 0xAEAA9F20AC762B02ULL, 0x5124FFD15C5FD4A5ULL, 0xCB703EDC3BDE81BBULL, 
            0x8FA9A8DC6BD76084ULL, 0x5C6D5814DC672027ULL, 0x0B4557C834F0DAD1ULL, 0xB08E24A91116ACABULL, 
            0xBDAC8A1B451B0FCFULL, 0x4AA9FEAFCED889E2ULL, 0xA263CF17DAD49408ULL, 0x1D5E81F87B6A6054ULL, 
            0xC0BFB396E85C7BCCULL, 0xD09F2A4509E2A8AAULL, 0x720B4BA37842FD51ULL, 0x0E04575A65EE353AULL
        },
        {
            0x70F612034EE90AFBULL, 0x7DD4FBE874D6444FULL, 0x80CBF9CE99F6A29DULL, 0x7714AAC6EF9B8EF5ULL, 
            0x5F54086A62BD8042ULL, 0x2D5EBC1C1F37791BULL, 0x55C38AE0058CE090ULL, 0xD706B205F80D3ADCULL, 
            0x690805EAD77CEBB7ULL, 0x183DF5AE8A7F6B95ULL, 0x0C512359C2D5A536ULL, 0xC496F05E883C8B30ULL, 
            0x69C1B27826C7D258ULL, 0xEF819D7C26154755ULL, 0x8591DF5EFE5A44A0ULL, 0xA0A221CD2DE48ABEULL, 
            0x86C535F4F21F5D41ULL, 0x551956D1B770C7CDULL, 0x7B2AF9583376310DULL, 0xF167B934944DB721ULL, 
            0x6E84FB9D56CE80D1ULL, 0x5FEED8088C9E2BA7ULL, 0xD99CBC05597A4F8BULL, 0x9FC52FE0EF6CAA19ULL, 
            0xC60BF7ADE21672E9ULL, 0xEB577C0DF792ADE5ULL, 0x15146D029AE18048ULL, 0xB6F7BADDF7880369ULL, 
            0x1E5B16979B510D62ULL, 0xC551B5AEA1DADB05ULL, 0xE7D707E4BBFFF0D9ULL, 0x5911B25AC0E8583CULL
        },
        {
            0x7ED80A6B672CD1EAULL, 0x133BB38EB95C9833ULL, 0xB2378B7EB06DBEF6ULL, 0x4DD76E0603E0DEADULL, 
            0x7EC87C11FF0239F9ULL, 0xDE778737F75B2631ULL, 0xB68A4A6D5E410F03ULL, 0x0C41DD3DFC00B054ULL, 
            0xA0306D0B66F5BB7DULL, 0xC5F993FB56A0B602ULL, 0x451B8A16E49DF342ULL, 0xEAE0937EB19DE7B3ULL, 
            0xF4C7E78C02A40D09ULL, 0xA0C16025985EC9E1ULL, 0xED070655B572D852ULL, 0x739CB5BAD86ABD21ULL, 
            0x713417648B4D4DA2ULL, 0x6C84B0FDC73A947EULL, 0x7AA240E91FA2FD7AULL, 0xCC8224158B018FF0ULL, 
            0xFF83C6A2FADAE734ULL, 0xF7B248094413A7EFULL, 0x4903E41A47EC07C7ULL, 0xFC8A412A4E34D03AULL, 
            0xBAC3EB4974CB2261ULL, 0xF7FDBD525BBFAA65ULL, 0xD24E3BE44CE08938ULL, 0x939ED8FC959CE303ULL, 
            0x617945F0A2545A68ULL, 0x618B8EB75ADC3147ULL, 0x801F1DAE5125C54DULL, 0xE20A7A3EF8E7B832ULL
        },
        {
            0x10CE8F82C21AA034ULL, 0x380862556691FBEAULL, 0x714B1AA647B4660BULL, 0x44EC9867C5974350ULL, 
            0x36C3B86676D3A44CULL, 0xBBE805D759B1560AULL, 0x5E0D47F63440C917ULL, 0xDA8B778D19B6D091ULL, 
            0x19E1DA29E28161E6ULL, 0x30E2345955A9B77CULL, 0x146CB3053686CA3EULL, 0x53254E44F0D75AEFULL, 
            0x621346B330C9EA30ULL, 0xC60A9B72D6400185ULL, 0xD59791FCE1AFFE04ULL, 0xF951F5BBDC0E9BAFULL, 
            0x75FD042B87A6732DULL, 0xAAF873C4D40F9992ULL, 0x15C34EEE63444CA6ULL, 0x12BE13A3767A623FULL, 
            0xB1D3E3F7607B5FBEULL, 0x9A352D588399E91EULL, 0xAA281AD33FD6CA55ULL, 0x26BA9CBC41D59B5BULL, 
            0x22A87165A22F0C51ULL, 0x984E8CFA1B584F62ULL, 0x6222682BB621F81AULL, 0x00B884D455FDA7CBULL, 
            0xCD72E2B43A20F222ULL, 0xBBE08D27BC425CA3ULL, 0x764C1CB770EA6D9CULL, 0x4D000670D73CFBD8ULL
        }
    },
    {
        {
            0x3B531A7F3F78076BULL, 0x57C1AB8FB816E6FBULL, 0x67EC6500561F5C0DULL, 0x347521153794E304ULL, 
            0xE34985C0CC2E6293ULL, 0xD5A5DE95EC67FF96ULL, 0x3542DE95F0964BA1ULL, 0x70956D989E2935DDULL, 
            0x718318AD44DC5C8AULL, 0xDD1961A804D86531ULL, 0xDCDFDAD94833556CULL, 0x19DC0F1932056E2FULL, 
            0x226A9166084C7B92ULL, 0xE061F67A1E922995ULL, 0xB74100B3007D1B2BULL, 0x41AAA1EA6E3AEDB8ULL, 
            0xF495643845B23500ULL, 0xC9C945CF5A032660ULL, 0xE4BA905B5E1FCEF8ULL, 0x15BBF36000015389ULL, 
            0xB74D3475A944483DULL, 0x416F04A6D1447968ULL, 0xC7786C1A609F28F3ULL, 0xC47E5F9DB73B2951ULL, 
            0x0E8FD2452BD39C6AULL, 0xF5A199A9FE97AC96ULL, 0xF5E6ECB03AC64634ULL, 0x6FC9CF7F5F51C3F3ULL, 
            0xC37EDF12CD2D65C4ULL, 0xDA14AC51A760E755ULL, 0xE477643A4D8DCB95ULL, 0x33B1889F6DE58A93ULL
        },
        {
            0x767DDF203EE861B8ULL, 0xB803AC0A7B6D4131ULL, 0x0C8FF91F89A9CB06ULL, 0x0AD5496F66CBA83DULL, 
            0xC11E7693143A5079ULL, 0xDB887F76F7F49B2DULL, 0x3F968F436993F502ULL, 0xF054FB878BDF6987ULL, 
            0xF42BCD6556BE053DULL, 0x788C38DF34ED6891ULL, 0x661D92B1DF54AF65ULL, 0x724030F9E2B25460ULL, 
            0x09D325C576E501B8ULL, 0xD64186415E308D20ULL, 0x4DABA0AAF4F587EAULL, 0x44277DFD946CDBCCULL, 
            0x4425C11DB4E3D6E3ULL, 0xD22AACFEEFAD9C8BULL, 0xB68EBBA9BC8F2283ULL, 0x6AC467D1908AD6B7ULL, 
            0xEB874560E365ED75ULL, 0x74F66B52FDAE4B04ULL, 0xAF976D2C2A6A528FULL, 0xC01B891BFDD1AF21ULL, 
            0xB11BB7AEAF8F452FULL, 0x47F3FDCD801CD6ACULL, 0x88E70D44D8CEC20CULL, 0x9C7A0CE5824292A0ULL, 
            0xD8B9A6BA3350FF91ULL, 0xB06FE6B140F219B9ULL, 0x1966429A7EE2B7B6ULL, 0x2B3CBC9365296AB1ULL
        },
        {
            0x0B00B45DDCE1DE86ULL, 0x9C3C3EB5D645BAB5ULL, 0xE086408A0B835DEDULL, 0x1B83F38FF90FEF98ULL, 
            0xA9177B5CA9A0A08CULL, 0x2109C61A9194758DULL, 0xBAF57598AD897FEFULL, 0xC426EB8B65BC8075ULL, 
            0x90694787277A97AFULL, 0x87C9E46BE501DC8BULL, 0x945F593934D67112ULL, 0x399E08C72BED73B6ULL, 
            0xF5424B577D9858C9ULL, 0x9C496ADB9A072750ULL, 0x6C175F40C13DF1F2ULL, 0xBE41F3A2D421C467ULL, 
            0x4E59A98EEFBEABA3ULL, 0xF6873AB1738D0671ULL, 0x59858D952F208890ULL, 0x1832F915F68F1D18ULL, 
            0xAD72D9FB8BBFC9F8ULL, 0x392F8BB38410B548ULL, 0x0A03717E3B59D1D8ULL, 0x10E36502AFDC8B87ULL, 
            0x602D5BEAFD8F801CULL, 0x9E9F31C0AEFB2FA5ULL, 0x3BC31372E9BE1835ULL, 0xC9F56B0D0F13B486ULL, 
            0xCE1AC938A0526D3AULL, 0x5FD8EC8CFA78607CULL, 0xD76B19D871E74F91ULL, 0x1CE2B86A9347F71CULL
        },
        {
            0xA96F0A44754DC4B4ULL, 0xA61A4039459D3AFFULL, 0x27C5A4595560FA9CULL, 0x5A796789AD777022ULL, 
            0x0E4B91F94DCF3BADULL, 0xFC5C5C3272EB87DAULL, 0xC88867D3BF395D5BULL, 0xF8119F91159E256CULL, 
            0x6F00A91A3E71DC8EULL, 0x374ED5732F9DA385ULL, 0x6DD5918FD960E991ULL, 0x6425247A77202A92ULL, 
            0x9E20B76D2C03D7DBULL, 0xF876E015397F18ABULL, 0xC01A93B10ABAB933ULL, 0xD43D4013528A51D9ULL, 
            0xA9DF9B759BC70D80ULL, 0x5B75FC7F8E1E630AULL, 0x3652BCA334458DBCULL, 0xEF2D69930B7E70F5ULL, 
            0x1E01D456A725403CULL, 0x8854C0CE70CF58B2ULL, 0xC80FB68D8C0E104FULL, 0x818D09E687C0C760ULL, 
            0xA738A86B86D61B2BULL, 0x35030CD53EE94862ULL, 0xF3646363F9F0C03DULL, 0x249215FA6F336E40ULL, 
            0x122B278F9D04244DULL, 0x1C2E5F51A2E26EC7ULL, 0x8B393A3034DC970AULL, 0x7D481006FE5A1D32ULL
        },
        {
            0x8387648F5A5E6A37ULL, 0x61B4ABBB7D1F3E97ULL, 0x68244667FC311268ULL, 0x0DB5BC784336BC38ULL, 
            0x82076D86C2B629A1ULL, 0x15FA882F05C28C78ULL, 0xBD1DFCED382175B8ULL, 0x123A8B2A681C7F36ULL, 
            0xF5D4CAE10A706128ULL, 0x0ECD6E70CBCC9DDDULL, 0xD213EB25B11F1502ULL, 0xBF8E4D39949B9717ULL, 
            0x5AC92877362E7935ULL, 0xE6F44A19D61444AEULL, 0x3EF26D5A322D0161ULL, 0xC1F2890B3CA6AED8ULL, 
            0x0F63960960A1FBD8ULL, 0x17D016B6F1E36CE7ULL, 0x73EE01E41BB23AECULL, 0x65D2701F708AFA63ULL, 
            0x4F5F600182EBE557ULL, 0x8B2F199079C7A357ULL, 0xC3D4CF468A8EFDE9ULL, 0xDA9D6C6F67255E7AULL, 
            0x47DE841FD0E616ABULL, 0x8E61DD69A0EE8166ULL, 0x04D06EE2D24D0AD5ULL, 0xB1236346C822E683ULL, 
            0x478A7C5F730FCACEULL, 0xD2A8899C049D9406ULL, 0xF6058C239A1F794EULL, 0xAE981EC87994293AULL
        },
        {
            0xFE1F1B5D6919677DULL, 0x07EC2FFC92F1EDE2ULL, 0x0465E6A2E091FB19ULL, 0xA13D48379C2A1830ULL, 
            0xC57FA14DD47B23BFULL, 0x97E9FF1A77B2A969ULL, 0xE923ECCD408CDAD7ULL, 0xABBE75927601E124ULL, 
            0x5D0D9B98CD44432EULL, 0x7F5EA18257A7324CULL, 0xF6C59A5F27AB924BULL, 0xD47CB4DD87B33B9AULL, 
            0x5A8F2473B8B0F0DFULL, 0x8507BA10CAA2BB4FULL, 0x399FADE7A9C9EDD3ULL, 0xB2CDA1CE8BDCDD8EULL, 
            0x7735E77227817879ULL, 0xC9B894CB33065328ULL, 0x41603FD3D4DE380FULL, 0xBABE6D74B0F4AF26ULL, 
            0xD829307313CA956FULL, 0xA901B91DE49DC03CULL, 0x0DFE8FCFE5B2C739ULL, 0xFA2F1AF205C5EF44ULL, 
            0xCFD612ED5378F4EFULL, 0xE6C9C60933F5D61EULL, 0x22A15C857C4B25A4ULL, 0xEE7C7009581DE10DULL, 
            0x9F1B8A53FC88C90FULL, 0x84F14F5B98C6C799ULL, 0x2D2F144C305C66DCULL, 0xB75482D45CB69E28ULL
        }
    },
    {
        {
            0x1C313A9D4567DACDULL, 0xA9A21B0304D567E2ULL, 0x92CA374324B201E4ULL, 0x3359C44F59B5CC07ULL, 
            0xCFFAB72EE9BED24FULL, 0x818C86FE3D1FC09AULL, 0x834DA90E10970C4CULL, 0x27E93B85A5FEC847ULL, 
            0xC56D94D49859A9F5ULL, 0x8EDE431ED923F316ULL, 0xFEDD34EBC9AB4035ULL, 0x5AC9CAD00FD9A004ULL, 
            0x881B0ACC25479A08ULL, 0x73F6A729B846C1AEULL, 0x71AF4C786E174416ULL, 0xDD27AA23A3C9A087ULL, 
            0x25E9C017C88DA06AULL, 0x83A16557B0990D8BULL, 0x4B2EB68D3031E2BFULL, 0xA9FF4BA0D1FB7EC3ULL, 
            0x5AFB185E5F579AD3ULL, 0x2D8DC42F2BBDF852ULL, 0x58E05E79BD140914ULL, 0x4DA6FB16514F085BULL, 
            0xBEC075B89750CBDFULL, 0x1A3D1CC036DDEBA1ULL, 0xF4EB3B05D8AA87F1ULL, 0x6F8A6BF80FA18E85ULL, 
            0x99BC9E3E9A914319ULL, 0x8BEFD41F39B6D717ULL, 0x2D46D1BAF303B863ULL, 0xA6ABF12786EED96CULL
        },
        {
            0x3C586A3DB55EAF67ULL, 0x29CC03E82AAAF893ULL, 0x391482B114BCB344ULL, 0xF07485E23AD2C719ULL, 
            0x19D7CB72EFF729BDULL, 0xF23B9B8D58862C60ULL, 0xABCC45D75A40ECC5ULL, 0x98A4918C0FFECCB4ULL, 
            0xFA07FD7CA437DB42ULL, 0xA47FFEBCE19E0FADULL, 0x9408EE5E64EB97D3ULL, 0x544222BC18E8C5EBULL, 
            0xA5B4069BE860BF99ULL, 0x20FB4D5E2958B3B5ULL, 0x269DD3CDCDC4B4CAULL, 0x15B4D6D8B8764B9BULL, 
            0xF43B35D173483016ULL, 0x90752785EE3F2D6BULL, 0x1029F93915E93AE9ULL, 0x62DFBF98D7F0494DULL, 
            0x0B1B85E172BBD68FULL, 0x739BFB3014972ECAULL, 0xA08AA9877A489780ULL, 0x73D4A2A02E2F79EEULL, 
            0x5409D4DAB17CD897ULL, 0x71EEDBABAE009E61ULL, 0x0667713EF784E8C4ULL, 0xB8821CA601C40F4AULL, 
            0x78CD89136304F9E4ULL, 0xEF228B41420C55AEULL, 0x2A71EB4B8E273E60ULL, 0xAD695270BABBE47BULL
        },
        {
            0x8FFDC43DCF9E9679ULL, 0xDFBF0DE2946710EBULL, 0x7BD4FC5C0E7D119BULL, 0x0C0E2B4631953EC2ULL, 
            0x727E77EA7AE6E7B3ULL, 0xF5E520EE75D564C8ULL, 0x8F594D3171B8F8B3ULL, 0x3DDD5E51E4F1D7ACULL, 
            0x5CF7FCE1ACD6959AULL, 0x7E8444A5BF619BE2ULL, 0x9486CBA064CC2F5DULL, 0x08CA0D2367C3481DULL, 
            0x5EE6AD20094BCED8ULL, 0x26E624B6FE21EEB0ULL, 0x5D8827536D2BA42CULL, 0x43C395D7549EAB4CULL, 
            0x7ED5BAB23491BD7CULL, 0x9EF1D7DABFA4FACFULL, 0x5A89D002B531EE84ULL, 0xB026E33648F266EFULL, 
            0x4F9CBC14E254D40FULL, 0x61A4C8B5E6716623ULL, 0x33C20D3C1BD55728ULL, 0x697512F27136C31EULL, 
            0x914AFC8E6D285755ULL, 0x5E0B8C94DF10B7F9ULL, 0xF64FD782147FA023ULL, 0x8AF052EE00964739ULL, 
            0xFF4732E7E09E3ECBULL, 0xB03BA20A554EEC4AULL, 0x12620D24F5990C22ULL, 0xB46927206728DA7BULL
        },
        {
            0xCBE400676D73F86EULL, 0x2EA68368B85339CBULL, 0x86199EE35B43C494ULL, 0xDBDA3EFF8325C254ULL, 
            0xC58E8032F59E495FULL, 0x5D7F20CE3131D853ULL, 0x972645FD0385F967ULL, 0x287838CB683DB31BULL, 
            0xAE53BE9EE0AE8A24ULL, 0x93EFE511A2A5B05FULL, 0x3DBCE453E848CB89ULL, 0x10F272E78038796CULL, 
            0x6B782904528A83FFULL, 0x7A298400A718FF6FULL, 0xF02C960816AA5253ULL, 0x0018FEC736BD7A10ULL, 
            0xE2E8673C17247A99ULL, 0x1B30F1AD90B61B55ULL, 0xCBB0E427213C1A09ULL, 0x2C3CC470FE37B71CULL, 
            0xE3AAE35A2594D832ULL, 0x4351220F42737A69ULL, 0x0ECF2E4E9362DF68ULL, 0x15B4035D31262D97ULL, 
            0x7148792BA4941066ULL, 0x29CCF284CA4B8825ULL, 0xACC3BB98CF83AD97ULL, 0x5ECDA8B6D960795AULL, 
            0xCBDAF90FF0954D6AULL, 0xACF88F9D7C0454AAULL, 0xFF83E6448FF38A96ULL, 0x010582FE2411B582ULL
        },
        {
            0x8F13505C0D56F867ULL, 0xEDE2B7F929A595BEULL, 0x9ADA976EE7E58E3CULL, 0xDC7462440608E194ULL, 
            0x6ABC18D79B7A48CCULL, 0x19F17F9FF4618D24ULL, 0x5E14E5B446F388A0ULL, 0xC006ACE6A9BB439AULL, 
            0x9E25B16E4C08C604ULL, 0xC0C10E49332149BAULL, 0x25F4931A0BC15B2CULL, 0x24F1B857C956450EULL, 
            0xE0237AB65C6B9592ULL, 0xDC0BF684C538A8DEULL, 0x99CB3176484A734CULL, 0xE1C95188FC23C20DULL, 
            0xC00E36BF86E6447DULL, 0xA70C02E1B63A7127ULL, 0xAB3405A1A945F0ECULL, 0xDAD162F5111D9361ULL, 
            0x962B68719F91D96BULL, 0xFCBB5D54DF9167BBULL, 0x3C41125477F7057BULL, 0x48CF24D2637676C8ULL, 
            0xF910E0FC66C369EBULL, 0xB515E5D332E9E771ULL, 0xFDB63BD75CC8AA09ULL, 0x0B8E79D93FCB3863ULL, 
            0x15F727FBE976CB68ULL, 0xB30EF09F469798CDULL, 0xFBB60DDE83DD374EULL, 0x532CD026AD5D48CCULL
        },
        {
            0x97E795102CF71FDCULL, 0x215C26BC07914637ULL, 0xFC451DEF1389EEF1ULL, 0x9B775C70A6718067ULL, 
            0x2764F979F1ABE400ULL, 0x9A68C8004B6DECB4ULL, 0x44F73D3C9A8FB0CAULL, 0x54FBDAC48E9A47E8ULL, 
            0xD5485FB646DC60FDULL, 0xAD6941314420E671ULL, 0xFC4784A3A04D9BA5ULL, 0xFDF95332B37E3B18ULL, 
            0xD533C8C07FEAC498ULL, 0x0DC653EEDBD238A2ULL, 0x841D61D837F5514DULL, 0x0463619F0CEDCEDDULL, 
            0x9B7BCC8D15FC9186ULL, 0x1B1656C6C7B3E946ULL, 0xF7D65388D23EE27FULL, 0xEC44F8A67E79B6FEULL, 
            0xFA64AC551EA30CBDULL, 0x0E1FA1E718DB26F2ULL, 0xFC8FECDA15BF9D64ULL, 0xBBC8BF5D7FBFF388ULL, 
            0xBC82C4A24D0363F0ULL, 0xB465CB0B2D5E0642ULL, 0xFC40A21B09A8D737ULL, 0xCBD0529453400B91ULL, 
            0x862DBE1C05B74378ULL, 0xB8046D1ED842F525ULL, 0x2A4FB67C162BB7BCULL, 0xAFB79D35BEB54564ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseCConstants = {
    0x1A28AD2F9F66C1A7ULL,
    0x000B4055CFC8E0D9ULL,
    0x5D2B1DD030D5466CULL,
    0x1A28AD2F9F66C1A7ULL,
    0x000B4055CFC8E0D9ULL,
    0x5D2B1DD030D5466CULL,
    0xA2D4D3B827D22D99ULL,
    0x7250CA40E56B6503ULL,
    0x67,
    0xB2,
    0x6B,
    0x88,
    0x7E,
    0x79,
    0xEB,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseDSalts = {
    {
        {
            0x2B39EAF5F28C2D04ULL, 0x36FFE87859F48917ULL, 0xDA7EC176BDCBCE6FULL, 0x41601DE64D75FBC9ULL, 
            0x2E44851C15DF8785ULL, 0x717FFA6638EB584AULL, 0x171045B898981BC3ULL, 0x9B71B9BACDCFACF3ULL, 
            0x06C31CE8A505A43FULL, 0xD28523D437FBB7E2ULL, 0x49E370D17F5BC86BULL, 0x0C55870DB7A39EBFULL, 
            0x28F543FDD323992EULL, 0x17B236030E8DA8E6ULL, 0xFFBACE0E3388B89AULL, 0xC7F781C609E8EFB8ULL, 
            0x9FC09991F65C996CULL, 0x873D49130EEC933EULL, 0x163B50418ADAC2B6ULL, 0x9C7C7AF19E206C7FULL, 
            0xCDEFCF37974C6491ULL, 0x27AE49801EE19C5DULL, 0xB62DA1A62BB2438EULL, 0xB3B3119544708A1AULL, 
            0x5D8BA1817B5FFCA2ULL, 0xD93C081681D1235AULL, 0xBFAC021C88E98148ULL, 0x50E914331F2D4EADULL, 
            0x180572C2A4918870ULL, 0xB873C5BD75404E49ULL, 0x09121137F5DC88F5ULL, 0xC9A1A937994826EEULL
        },
        {
            0x37EC29C63F24C171ULL, 0xA1540474851FA092ULL, 0x7FDEA17D0ADD4569ULL, 0x0AF209787AAA39ADULL, 
            0x6CD5A6792D4376CFULL, 0x3EE6AD5005523953ULL, 0x0C691B93320C5363ULL, 0x47435F264DE5257FULL, 
            0x6A011843AD3A2E30ULL, 0x7420439FC8B4D59DULL, 0xBA8583A63083A101ULL, 0x0E3CBAC99C749BFBULL, 
            0xB61356B79D12E8EDULL, 0x3DD034E779FFDEE0ULL, 0xA38F77026DA60FFDULL, 0xE7C6941AA9B892FBULL, 
            0x6FAA006607118A87ULL, 0x2FC5CCCC3F03D690ULL, 0xC62D6FD013E6495CULL, 0x9DA3617C576359A1ULL, 
            0xD63FD9BE64CBB275ULL, 0x8D6F26559A424951ULL, 0xF5E823897AA170ABULL, 0xAC83D6D2BA970648ULL, 
            0xEBE09A6C1BFED37FULL, 0x066D9971A872C442ULL, 0xDD0231069BD10CC6ULL, 0x85D1C759A0775C72ULL, 
            0xD020E41DBB2E5A80ULL, 0x022A0AD483B06735ULL, 0x2549C4F904E5003EULL, 0xC8BBDC0F2C77B0FCULL
        },
        {
            0x97C493193B91FE09ULL, 0x2C7D65CB7C62D54BULL, 0x92BD1428D3D7268AULL, 0xA8DB6E9E102A13EEULL, 
            0x07479CDAB7F6895BULL, 0x50B1E7951BB80CDCULL, 0xC4354175CFCA2B5AULL, 0x52E849AE2A056CBCULL, 
            0xD00B5DA797E1B336ULL, 0x9024E102C3D25109ULL, 0x278CE584FED57C41ULL, 0xB9A6C7D9D00C19F3ULL, 
            0xD774A5A69273D426ULL, 0x32A233E1C4C2845DULL, 0xF9EB335FCFF3555DULL, 0xA19AC5274A718125ULL, 
            0x6DB71D13F9FAEE69ULL, 0xF8C817AA1960C4E6ULL, 0x84CF17253310F49BULL, 0x6FD1F6988CFCCF82ULL, 
            0xDE3F037AF0678C1AULL, 0x2CCC48174ECFBD49ULL, 0xC3F74DA9A6E695A2ULL, 0xC167420D107FD3E1ULL, 
            0x0A2C24DAE5B35237ULL, 0xC56BFB91A16D954DULL, 0xCD6FFC99C0CF64C9ULL, 0xF07D86ECBF753919ULL, 
            0x700E5EA22402E2B7ULL, 0x42E4E59FB98DA269ULL, 0xA3BFA48BFE13859FULL, 0x21F254F1F0459AEFULL
        },
        {
            0xCC0D022E861BB9B9ULL, 0x24E35C6C7A79B7AEULL, 0x41E2C3D34FB6297AULL, 0x012BD54A17953609ULL, 
            0x4C018E741578253FULL, 0x06628D8F5AB6542EULL, 0xC0A77B158B6C7AB6ULL, 0x42DB8827F75A4DDCULL, 
            0x0DFE65A9BD1EA064ULL, 0x15CA4F8D5D36306DULL, 0x1221B81F03207B22ULL, 0xC57A196EEF297AE1ULL, 
            0xE4D39D613B8B594DULL, 0x135338FCC11A5AFAULL, 0x2DBBAB65D52D50FEULL, 0xA04D977199223F48ULL, 
            0x897E60CD7615E335ULL, 0x0AC26581C5F75F5BULL, 0x0206DDBDF702E9BAULL, 0x3B9E74C6E8689ADEULL, 
            0xCECB66C07985E235ULL, 0x0BC53B69D97CAA98ULL, 0x6DD7ABD9EF039260ULL, 0x66A03182F8BAB6CCULL, 
            0x33B77F3F3728EB6BULL, 0x9AE9403C5F138096ULL, 0x3656A582AB30DC40ULL, 0x9742165378781F94ULL, 
            0x368677B58DF246BDULL, 0xA0374F3D3E4AF003ULL, 0x3BBD99FDA00A31F1ULL, 0xD39CECCF541C1937ULL
        },
        {
            0x675A6B8DFE9EA61CULL, 0x130FBBBF65726544ULL, 0xC12ABA393F53E0B8ULL, 0x500FC2044C68B39BULL, 
            0xF0756E95A1E46153ULL, 0x3CB86357CC6C04E2ULL, 0x18E8B73BC36B1FF5ULL, 0xEC65535B2E0BC1EFULL, 
            0xFAE640853F161618ULL, 0x25CEF785CD1B59E8ULL, 0xF98D859ABD5D0212ULL, 0x58AC11F582C00793ULL, 
            0x8B855ADEA04F0920ULL, 0x858B55EDD3F34755ULL, 0xC867A3EA0E7B85F0ULL, 0x0EF4B6D17EAC45E3ULL, 
            0xB20690448437C5D9ULL, 0x583E5E63A855D27EULL, 0x4F6EFB922CF3A58BULL, 0xA3EA68219056C768ULL, 
            0x8EF29EB86A5D3BE0ULL, 0x2DBE7760D43F263BULL, 0x0B93B0AFE3AD5A08ULL, 0xCC0CB975BD873E40ULL, 
            0x38EECBFD36E1AA8FULL, 0x39917347AB43E171ULL, 0x7056433A234D628AULL, 0x3AEFCB4519BE4463ULL, 
            0xE3E2489BF1E363EEULL, 0xBE330C316301909FULL, 0xDA42CCC8FD2AAB9AULL, 0x22EB20D1645E112FULL
        },
        {
            0xB6F25FA7F8C1D062ULL, 0x50AEC140F3CA457FULL, 0x17FEFDA2EC051340ULL, 0xF792161BB4616421ULL, 
            0xB206A27A8475DAC3ULL, 0xADAB652E42410CE4ULL, 0x77F6D96872C774A5ULL, 0x384DFB900C887A32ULL, 
            0xBB07AB12C427E958ULL, 0x307C635C1A2669EFULL, 0xD9669A9EACF95DEBULL, 0xE3A295FF7D7668B4ULL, 
            0x92CFF6BDEC2E2874ULL, 0xEF751DD426E0397BULL, 0x5EF7A27AF55DB5BDULL, 0xE63D37E8E0067FF8ULL, 
            0x82C053A9D18BF482ULL, 0x08E1BE33F8C61F33ULL, 0x3EA50881C2A76D10ULL, 0xDCABDBA3C58E0AE8ULL, 
            0x9BEE8934E1DEA3AFULL, 0xE4A9E8F62C7819A3ULL, 0x195A9C86020D24DDULL, 0xAEE27C61B925FE43ULL, 
            0x872AC9D5F96A6219ULL, 0xFC7A671DF07F990DULL, 0x74049EE42D6FAB67ULL, 0x1BB7AF6FBF23DB8AULL, 
            0xA0D470978E97656FULL, 0x6854447C3C09048FULL, 0x82551ABCF5E14BFEULL, 0xB2619239ADA11FFCULL
        }
    },
    {
        {
            0xC4319B97E120C7BEULL, 0xD092C69AB74AE6F0ULL, 0x8F2EF2FAF5B9369DULL, 0x0A4145EB69F78FE8ULL, 
            0xD1B195AD5111465FULL, 0x464C45F2C357F5C3ULL, 0xC8C4E45DF135C713ULL, 0xF8584D915D3CC1B1ULL, 
            0x0C53170D9CEA9FECULL, 0xE1E6827770832B3FULL, 0xE41FFC1152E4100BULL, 0x5A98E2A0512D90E3ULL, 
            0x97326EB49F586FCFULL, 0x05AA47A191FE5D27ULL, 0x59D290B227FD8CE0ULL, 0xC2F38454CC6B8E03ULL, 
            0x24B1D383B261626DULL, 0x6632A9643C8590E3ULL, 0xCC3F843063282773ULL, 0x8BE74FE375351A4DULL, 
            0x9A4410F5F2EA1A22ULL, 0x50E9377A5E82E9EBULL, 0x9F8B682055A45516ULL, 0x3C18AB3F0A7E36D3ULL, 
            0x3D35B8E6FCD116EDULL, 0x3940671A7A77DABDULL, 0x4160E75E7F21BC38ULL, 0xF561F7C805ADF082ULL, 
            0xCDB9B196E09CAD19ULL, 0x61E3746A95DCFBF9ULL, 0x33106590808C3E74ULL, 0xDCD50B2CCB447BDFULL
        },
        {
            0x40B1B05A868E268AULL, 0x48475AFB8CC7CC67ULL, 0x81A0872D6A184B68ULL, 0x23CAC92DDCE68205ULL, 
            0xB32CA635BDD21505ULL, 0x6DBE2CF9DCDF9013ULL, 0xF2F24D6BA27EDCF5ULL, 0xF31407A0725E60F2ULL, 
            0x21C9F5A21BAFBFDDULL, 0xB55BEBEFCB5C2F82ULL, 0xC1EBC849A06EFD0BULL, 0xCD55571E4FAC331CULL, 
            0x8C1FADE4BDD65176ULL, 0x91A2523082093A62ULL, 0xC3AD23F9F6799882ULL, 0x2D5666492FE3CDECULL, 
            0xB338623F5C80DF3BULL, 0x34078F203B9C6082ULL, 0x98105B7E3A060BBEULL, 0xF7EB44E19DBD72F9ULL, 
            0x4A060988BAA1CB79ULL, 0x763F50D8856C2AF1ULL, 0xEC8BB77634CE10ADULL, 0x3BE9711C05876468ULL, 
            0x3675277241641DCEULL, 0x053A78D95BA39262ULL, 0x2BCCF168FC6410F4ULL, 0x4C0A3D722E65D681ULL, 
            0xF3EF4FFDD52EF75CULL, 0xA06F40E5366E1D1CULL, 0xA16D2C1BDAAA2067ULL, 0xD8E44EFD8F58E787ULL
        },
        {
            0x729992577B80F497ULL, 0x864000F30BED4C42ULL, 0x0749AC82683605D6ULL, 0x32E086B62EFD81EBULL, 
            0x1EAFFEF58F4FC3D3ULL, 0x62995F3AE6874E56ULL, 0x5A4D186F21DBB68DULL, 0x35A94D7819110129ULL, 
            0x41D29501A35E3611ULL, 0x51F266EBDB698242ULL, 0xDEFC2FF9128A660CULL, 0x299D1EFCB446E372ULL, 
            0xD0D67F4563919D71ULL, 0x4D925FC683925102ULL, 0x87971B46A8C77D91ULL, 0x59F813A3E8EE3582ULL, 
            0xE47D35AC759D1D2EULL, 0x5179C29406302B4BULL, 0x380D15EE9F032124ULL, 0x6D525CAEDCDF0962ULL, 
            0x88A5DCD7DC6FC05AULL, 0xD54EC890406AA10BULL, 0xBECE3548E3050B37ULL, 0x883D6C931801DD46ULL, 
            0x29BC5DB919DBA338ULL, 0x62A7F2F6955C6EBEULL, 0x602EA332776CD7AAULL, 0xA2AF68C0F8E1947CULL, 
            0x8D08D2BEDC77BFC7ULL, 0x3B9595B5B7F32B73ULL, 0xD1D91E5D6BFDE130ULL, 0x9DD3B067C2407D4DULL
        },
        {
            0x1919396D14434D09ULL, 0xC62DD89E2A31AE3EULL, 0xF29C585B5608F6D6ULL, 0xD96A35BB4E304FF4ULL, 
            0xA0E818512D2EBC3CULL, 0xA625FA962379DDC5ULL, 0x6E62A7FA6F56E457ULL, 0x0E87972267A721FAULL, 
            0x4C621078756A47C6ULL, 0xD205EBB074FC59B3ULL, 0xF9020FDEE4441509ULL, 0xA596AB1AC80FA8A1ULL, 
            0x66AC08F00FBFBFCAULL, 0x6EF7B07622F589F2ULL, 0xFCCAFBF9DD8FB583ULL, 0xFAFD9FA6FB575D5EULL, 
            0x0102213B1604B74BULL, 0xC5DE4B8150A86556ULL, 0x703348C2F7B9D3F4ULL, 0xB019CB77B1272234ULL, 
            0x0D7EDF8687284025ULL, 0x7499811296A7E95BULL, 0x49AF9A3ADE1DBA46ULL, 0x987C6A0A7A3F1D04ULL, 
            0xD342490A31E7516CULL, 0x45C71A189CE166B3ULL, 0x4B552FF9C3B0CB23ULL, 0xBCBCFC1E1B68FD70ULL, 
            0xF24689E8B77C11D7ULL, 0x8264285EF362C1F9ULL, 0x5FE04885891D21D6ULL, 0x59D04EBE780A977DULL
        },
        {
            0xD3286D14C2BC17DBULL, 0xD54C51796D668ABDULL, 0x3DC5E67DB5A7472FULL, 0xADAB969AF8D5CC49ULL, 
            0xD25C8C31FE380B3EULL, 0x6E33585C20AC41E6ULL, 0x142C2C14277FDB8BULL, 0x6E3B8BA33D76A8CDULL, 
            0xE9AAA339EE18F078ULL, 0x5FF39B48B35E5B44ULL, 0x77E2D1FD996E2AB2ULL, 0x0D0D3A898D163C6CULL, 
            0xD32BC9510BD236E4ULL, 0xCE9D765484F5BF8AULL, 0x781428101F3E7443ULL, 0x23AC96ADA740CB20ULL, 
            0x9D8F78B5B85EEF5CULL, 0x86B950A2ADF758FFULL, 0x31B9D471FC9665B2ULL, 0xADB57F98525A052BULL, 
            0x48F6C0A44E41E9D8ULL, 0x426FF079C920DE72ULL, 0xD5226AA2711FD10AULL, 0x203433EEAB38CDC1ULL, 
            0x042A19E2A9C9C584ULL, 0xA034DC63F67AE20CULL, 0x734558DF2B95577EULL, 0xF060CD376DBB83D6ULL, 
            0xD1F8621A90FE7071ULL, 0x9B3BBFF1537304C3ULL, 0x53BA9AA7740F2BD2ULL, 0xBDBD27B89430082EULL
        },
        {
            0xC70634FA181AB856ULL, 0x93FC70DC05AD4EE0ULL, 0x88C0DE65A81D7809ULL, 0x8F632DB8385F5B8CULL, 
            0xB107B7B3B09AA3DDULL, 0x3F6466F5EABE024CULL, 0xF091A1C076068382ULL, 0x2F030662F5493C70ULL, 
            0xD9527AF90846E7D5ULL, 0x3E4F4AA07CB435F9ULL, 0xA3241C140C79CE94ULL, 0xA3B113296D9F66EEULL, 
            0xB363B23B3E2CCA3DULL, 0x8AFA64DCF300D6E6ULL, 0x2AEE4384FA2CC808ULL, 0x13633AC86FF8A533ULL, 
            0xA24EB01545D3C204ULL, 0xD1B12862B3B91B15ULL, 0x495A60F6A5DF90CDULL, 0x074270D964482816ULL, 
            0xFDF670A18A57328FULL, 0xADB7EE3514970150ULL, 0x292ADE4D4F2240ABULL, 0x1D21D8A873C91526ULL, 
            0x96D9134812A7A3A9ULL, 0x498B0B90AB354460ULL, 0x5AA63038053727B2ULL, 0x7920027C13C0B4A0ULL, 
            0xF5B7D1239962AB91ULL, 0x0C01493F7823A288ULL, 0x9E17AF2F43ECA4BFULL, 0xEA6C7283E714A0B0ULL
        }
    },
    {
        {
            0x42C0FAA9536D6CE2ULL, 0xB8D4BD8AC1BE5F87ULL, 0x39F75BAA63ED160BULL, 0x2DE721ABFF6D0313ULL, 
            0x5EA906B6B3FE7B88ULL, 0xB3EC3725258AF516ULL, 0xFF7E9C3085733B98ULL, 0xA06EF39E8F76FCE3ULL, 
            0x5734D690F95A877CULL, 0x9A8CA607C5D44E14ULL, 0xE15E7795368169F5ULL, 0x2AA2EC93BF393480ULL, 
            0x3C993A38E2166460ULL, 0xEEFCBFBFF04BB367ULL, 0x25002AA0F993E372ULL, 0x1F0B6DDF55603A96ULL, 
            0x7A57188AD0F4C82BULL, 0x4793FBAF1C7DB40EULL, 0x49C6C9F1831F8F9BULL, 0x65998B1984F87C6FULL, 
            0x9646FF285FCAC9ACULL, 0xF1D7979F4CA43F66ULL, 0xD52FAF22D83D0D64ULL, 0x76346AEAA2C51D12ULL, 
            0x7C23771D54A90B73ULL, 0x4FBF417ABB7C9C5BULL, 0xC44B9A3EF5FF8DC3ULL, 0x5FB396FCF3D04E83ULL, 
            0xE57E3C5FE3A9F1CBULL, 0x9DA1AD5246FC66E3ULL, 0x395C7450C7A0C4DEULL, 0x5DDD5AA797C316E0ULL
        },
        {
            0x310E9D32E50D4298ULL, 0x372E678BBF4DFD23ULL, 0x01A7FD5652B78267ULL, 0xAF4D40E0FC939AFDULL, 
            0x04FEAF0E9031B975ULL, 0x740126AC319E2681ULL, 0x1C8D5B01FDCACA0EULL, 0xD9F424AA109A8B59ULL, 
            0x1CDB312202F75799ULL, 0x17BDD77B8535358EULL, 0x17C33B2C6E686C2EULL, 0x29669D6BE1BACC90ULL, 
            0x14D384F26C70ED3BULL, 0x00FDA8A2D9A7FF0DULL, 0xFA4B48E4D86561F2ULL, 0x2865C4CE4E05DFC6ULL, 
            0x1A6A2A8155221E5FULL, 0xC3FAD88BA8D5A1F7ULL, 0x9B2D97E78910F28AULL, 0x81509685EEA8E06AULL, 
            0xD8B1802DCE8F5703ULL, 0xE11F0FF3A992BEC1ULL, 0x6D7BCC0A20A7E783ULL, 0x8D52213C0FC8F6C8ULL, 
            0xD24BCDA1A2E96033ULL, 0x45EADA02E27D71B5ULL, 0xDFC9A538883E7033ULL, 0xD5631E2DF6BC177AULL, 
            0x57456C2256096D13ULL, 0xA02919F90DB5899FULL, 0x1CD1C7F5EE43D3FBULL, 0x543146CECD4F3C97ULL
        },
        {
            0xD8DAA61F02735671ULL, 0x14A86A5C87D39538ULL, 0x137EEB53A6692F45ULL, 0x0D333801C930E148ULL, 
            0x54B46371CF3D2D37ULL, 0x8A6C1E5D096BBD38ULL, 0x6E0691D80A246FAEULL, 0x19718E27EBAAD715ULL, 
            0x49A778D1B2CBA7BDULL, 0x7E2D973EA47C1E26ULL, 0x289F0D4D69E2B93CULL, 0xF019ABBD420040BDULL, 
            0x5BB7326E81D8C3BAULL, 0x8A785953F8A498ADULL, 0x0B3773DFB7219DEBULL, 0xC26B4BA9773D4A6BULL, 
            0x6AD834C5ED07F50BULL, 0x9273D0B2ED067EA9ULL, 0x7116709C09F7116CULL, 0x99112BD7F8D821ABULL, 
            0xAE69BB74AE13376BULL, 0x78DDAC7ED5B70D0CULL, 0x15FBBAEC36B0C0FBULL, 0x7D5A9B84EEF83F8DULL, 
            0xBEDB2316436B322EULL, 0xAB8AF5C0CB6B78F2ULL, 0x85A505279FCED7B0ULL, 0xD515B941F08A9C26ULL, 
            0x66578BE7BB9F1EFEULL, 0xDE441AC3140B3541ULL, 0xCA05966D69B4FEF1ULL, 0x1A8C6D443DC405D1ULL
        },
        {
            0x2D7A5D9589E932C2ULL, 0xC622609638454B5FULL, 0xF7D087ED0290ED6CULL, 0xAAC5F31556F0F7FDULL, 
            0xB387843A410CD3FAULL, 0xEDC00E51894464CBULL, 0xACD22735F0887F49ULL, 0x5DE9A00ADA7932AEULL, 
            0x7464F9CE3972113DULL, 0xA5D59E51974B8FE9ULL, 0xA2503AAD6DD3FFE4ULL, 0xEC4E96F3C388BCBAULL, 
            0x4C767A670D096644ULL, 0xF585BBD5F4B2641CULL, 0xFBC2349E6255AA59ULL, 0x15F9B1E9F318363EULL, 
            0x46214289CF53BB79ULL, 0x44A25D9C7AAA55A9ULL, 0x05F16B3051FDBA11ULL, 0x551D41C7DEAFF049ULL, 
            0xCCC590601389400FULL, 0x095DB1CC4BBF202DULL, 0xAE9BC1F3365B4B04ULL, 0x5E887F40202FDC83ULL, 
            0x85F63A9B9E99086CULL, 0xB617A754716CDC5FULL, 0x70A6F794AA176BB1ULL, 0x70B03C4246143D1CULL, 
            0xFFA44EC34F503B4EULL, 0x83EEA2E48EB0DDE2ULL, 0xF0EE4B85FB5D5A02ULL, 0x6F1FA278F77D361DULL
        },
        {
            0x02F6CC952BE47E02ULL, 0xEF007DEF4C66D897ULL, 0xAA09DC3A8B86125DULL, 0x3034A9667F4AC2C3ULL, 
            0x2EB16E547F65BFFAULL, 0xFFD2BC614E880592ULL, 0xDCE5AFA5E0A41FD2ULL, 0x4A23D89195F92E65ULL, 
            0x68E7952313E41C55ULL, 0xA713580C435661BDULL, 0x91E52E75714D847BULL, 0x19AD7341F62A997FULL, 
            0xC9DEB7E6B1BA9DF6ULL, 0x0D25F37EDD3C5BB4ULL, 0xACDB71DF803AF84BULL, 0x6F8B00B5F52E0932ULL, 
            0xBCA605FE0AA96078ULL, 0x1B2B2B6A2F6686FEULL, 0xA6FDE1453370F449ULL, 0x011056A0F8615CC9ULL, 
            0x42E124AB7A3163AAULL, 0x19FE36A92472320AULL, 0x9EA2D6C6C1019B11ULL, 0x10C76749C33FCA77ULL, 
            0x18DD6E8B8143E849ULL, 0x4C8CE22D0E1D8080ULL, 0x09E3C8A356F7FF4FULL, 0xC3F02BC9D56DCF1DULL, 
            0x042CA1A756B59DC3ULL, 0x8691F4C5FA9554BCULL, 0xF2E28ED0AA910167ULL, 0x9EC9D40EA44248CEULL
        },
        {
            0x6CB5AB9E4E8D2B27ULL, 0x0D48AA871B76AE7EULL, 0x990F7F972707CF2EULL, 0x1E8588B01C4A5F59ULL, 
            0xF36E1056A0275E64ULL, 0xB37080FA79B22676ULL, 0x40D850395BD3B775ULL, 0xD4F7BEB32A237F61ULL, 
            0xA35CDCEC2B684D24ULL, 0x4F30243509D6ED3FULL, 0x4A33D03B45C7CF9AULL, 0x08862E5E99867155ULL, 
            0xD8398EB86DCB3221ULL, 0x26922090BABC2987ULL, 0xE52F22EAFDEBE3DEULL, 0x354066F9C1A13ED4ULL, 
            0xF433BD9F44B5B548ULL, 0x57F3D7E2B8017F4FULL, 0x4CF49EAF857D1629ULL, 0xE6AA7AF2AD5D9E88ULL, 
            0x3CC8365C2220B44EULL, 0x2FB715972C885345ULL, 0x01CEADE81926D76BULL, 0x6C6B08614E34E9E0ULL, 
            0x2EB0CBC917536A9EULL, 0xB4D491D612B57B41ULL, 0xAFF7CCF775FEBC47ULL, 0x41281B329E72BCEBULL, 
            0x10CC10D89A07609EULL, 0x281B8314321AD755ULL, 0x0F0BCC62B12C6A9CULL, 0x989E1D4803770C22ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseDConstants = {
    0x8BD4D0E82BA29905ULL,
    0xB853D99C2F02046CULL,
    0x6870CB113F4A127AULL,
    0x8BD4D0E82BA29905ULL,
    0xB853D99C2F02046CULL,
    0x6870CB113F4A127AULL,
    0x3D8FCF00337A2F35ULL,
    0xBA5484FB60DE1DB5ULL,
    0x06,
    0x5E,
    0x11,
    0x42,
    0x19,
    0xA8,
    0x98,
    0x6F
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseESalts = {
    {
        {
            0x2A6E99D4C30A8358ULL, 0xE0C7BB1DF44C2DEDULL, 0x38742503F0625E69ULL, 0x2D8C8C99B4A0D4A5ULL, 
            0xCEF2C7E3E02FED65ULL, 0x0A16935EC9927D2AULL, 0xD68AEA9D3B275B49ULL, 0xAA7B70F76C2345D1ULL, 
            0x093139AA6CDE7ABAULL, 0x7BE6AF4F61D8E91EULL, 0xBA6C74F1F3FC12DFULL, 0xF31588ECAD9F9CD6ULL, 
            0x7DDA171E750E951BULL, 0x4425C5A53AD1AF25ULL, 0x3C553BE5845A49EFULL, 0x8EA7BA8004BEAEF3ULL, 
            0xBAA2FD71C0ED6894ULL, 0x48421D17DE92D301ULL, 0xCB11DC45BD8CC2FEULL, 0xACDD93E9DCD8C61CULL, 
            0x178765E3307E6A63ULL, 0xF80008C9B865C13AULL, 0xD75EAA7CE7CBE5F5ULL, 0xA0306F40C04BAD4AULL, 
            0xD8D3CB27A990728FULL, 0x135E7BBD54B9724AULL, 0x265BE4C68D67D545ULL, 0x440B13C5D68C2562ULL, 
            0x74D06E60CA0FF840ULL, 0x6B124618BBEBE261ULL, 0x85AB423E53F4360EULL, 0xD14F4E9CD6D04F8EULL
        },
        {
            0x2CE97846A3FA2BB7ULL, 0xA75AD63522394B93ULL, 0xDAC2046DBAA1DBA1ULL, 0x8514F5DB92DDD9D4ULL, 
            0x7483A5C8893DE098ULL, 0x162E72E377DE31C7ULL, 0x0AF15743CD6DF401ULL, 0xA46E8E71608DFB15ULL, 
            0xE187D25488B987F5ULL, 0x21F04F12C8D5987EULL, 0x69ECF2F7001AFB16ULL, 0xC088170786EDDD73ULL, 
            0x64CF8EAF31E0BE46ULL, 0x208595E5EFD6D4BEULL, 0x7C6EE5E7EC0D5C77ULL, 0x2EE774FF01B2AD69ULL, 
            0x8AF08E3332E801B4ULL, 0x3411F6D2ADA26298ULL, 0x536A5E04CC82BEB7ULL, 0x7F812BD3227F3DA5ULL, 
            0x169F86D1DBFE4FF5ULL, 0x83B9B408AF667E39ULL, 0x30953D38B47390EAULL, 0x1EC1FD2D47787683ULL, 
            0xB888E5AA8C1A244CULL, 0x9D169AF437AB9691ULL, 0xF670EE4E259D12BFULL, 0x3A75E994F8816F9EULL, 
            0xD5D2F85CCCF19865ULL, 0x2461B7EC8815682FULL, 0x74196133C1907511ULL, 0xEA097234BE6AD180ULL
        },
        {
            0xFDE697EFDB9B0732ULL, 0x85398A05E5AD34E1ULL, 0xB1EE68549C68F104ULL, 0x465744692CC19933ULL, 
            0x58D1566F54924AC4ULL, 0x98A921754220ED3EULL, 0xA02884866F35917EULL, 0x5AED8BD57BA1B90CULL, 
            0x49B83E7BE603093CULL, 0x427C5C67595D5C6EULL, 0x4BE1F0983892B489ULL, 0x40CE617D4D388B1FULL, 
            0xDEE8BCDAD5D83F4FULL, 0x4C7355A4A541524AULL, 0xE2FD658C2318873BULL, 0xC746EAF5E710C049ULL, 
            0x6E577B4C1C12EC80ULL, 0xA59D3DC15DFC9ECAULL, 0x91A55DD41779C468ULL, 0xE522739EE85D3483ULL, 
            0xCD9F657BE0986E71ULL, 0x79FE55D1953388BEULL, 0x76C62D3A27240E43ULL, 0x8F09D4888D834BAFULL, 
            0x1CC904EE2398DFF5ULL, 0x5D11C5768831C98AULL, 0xB61428BB731D146AULL, 0xB0FABB0E19EBC911ULL, 
            0x2F8CEDAC7FF365ACULL, 0xD43D00002EE56C63ULL, 0x3C7D0BFC40840500ULL, 0x040D969A069C8D82ULL
        },
        {
            0x6B4A203F26FF9E75ULL, 0xBA89FA79F4F974FCULL, 0x713B584D0D5E455FULL, 0xA26D6F2C3D929F55ULL, 
            0x00C4F8C604216B5EULL, 0x8DB3FDE6E2D8DBE6ULL, 0x214B93805C01CDDBULL, 0x6EEA1BBA0BF40610ULL, 
            0x7AB9DBC27991660CULL, 0xC2876B3CFA1692BEULL, 0x19F10D3CD8FC114FULL, 0xFD0508B319694B9AULL, 
            0x38A488B94D234D8DULL, 0x42B97C1C151F46DFULL, 0xD965355C6805A33BULL, 0x6168CFEC792E9E3FULL, 
            0x41F5C19E27044C6AULL, 0xC348FFD5A2F6C0D6ULL, 0x547348F9BB825F71ULL, 0x003F70EF8B30010DULL, 
            0x72EA3374E125DBA4ULL, 0x26AFCC4CC21D3A8BULL, 0x9E5D9124A825C64AULL, 0xAB7234691B69D346ULL, 
            0x72BD909ADB210A9FULL, 0xB500C8F395B2C9C9ULL, 0x0A61A26412ECAD3BULL, 0x59D1A9C962974CD2ULL, 
            0x501CE3E24A066327ULL, 0x8A58E26B8301434DULL, 0xE39BEB6AFA79245CULL, 0x170754E7D95DA45DULL
        },
        {
            0x77F384A5D9EEEA96ULL, 0x0FC34E036D07A879ULL, 0x17AA21B6E8D4EDA6ULL, 0x1621C1F90772B415ULL, 
            0xBB5C0A0B258DF83DULL, 0xE4BFB51DF1C48CA0ULL, 0xF9F21E74C622B4AAULL, 0x28863C99E7D35A33ULL, 
            0x017CDA362F78E9BDULL, 0x07C71BC13AE9966CULL, 0xDFF0F70AE0CECD15ULL, 0xC4C679E0AD2F3261ULL, 
            0x9159FD9CC6C4F039ULL, 0x7AC1964E6F44984DULL, 0x6CB3C27EB33AFD30ULL, 0xCD09245F63DC3F9FULL, 
            0xCC3DBCAEB084C195ULL, 0xA8D0581B8C1F1E3FULL, 0x166604828ADD5F3CULL, 0x38C67077737575C8ULL, 
            0xEE9F10688614D063ULL, 0x66DD57B9DA3BFA1FULL, 0x2F8609107591D907ULL, 0xB03DD7F8D78B0FFBULL, 
            0xA9CE4E7A93DE0323ULL, 0xC961A0CE2993BE34ULL, 0x92B706B0A39B649FULL, 0xC3099AAE5154052BULL, 
            0x7DA89BF402C24FC4ULL, 0x70F268C725637068ULL, 0xC521F69CB7C731F0ULL, 0x6398C15B7B2BA3ACULL
        },
        {
            0x611AF02881300657ULL, 0x7A6474371AEE3B6AULL, 0x70B403B4C79055FBULL, 0x98F7C277B853721BULL, 
            0x8CC160672E74E285ULL, 0xB43176F0926F8859ULL, 0x2DFF6F28BA990C24ULL, 0xE5A7DDE078D43EB2ULL, 
            0x78238B91D415895EULL, 0xDE5B64610E1628A1ULL, 0x5C61947029C97AA3ULL, 0xCD0BAE433A66ABC4ULL, 
            0xD160AEC8170FD548ULL, 0x124D7AAF88B06A0FULL, 0xE7C7231841D0B236ULL, 0xB900909CD4388CC8ULL, 
            0x8F61E29DE7EF2FEAULL, 0xEEAA5018957BF8D9ULL, 0xA9F28EC30D89312BULL, 0x2E09A64E0FB755A7ULL, 
            0xB7BA41B131B87586ULL, 0xF3A3943EDD492818ULL, 0x70E080C16A0EBC63ULL, 0x9C42F8F0BFF12660ULL, 
            0xE81AD2AB45A550ADULL, 0x4491818977A9047BULL, 0xBB867BD9A7509B39ULL, 0x7A8C5F8D85BC301DULL, 
            0x356CF6FBE91431D5ULL, 0xA89B8B6D70AEAB3CULL, 0x49C6098BEF359CB3ULL, 0x781709B738F63B4FULL
        }
    },
    {
        {
            0xC37A4E98C3CFBFB8ULL, 0x89D8D5C20EF81253ULL, 0x4DECADB18998BC04ULL, 0x5FF22FBA79F0E389ULL, 
            0x1C91CEABCEA26EA9ULL, 0xF73F1907FB51538DULL, 0xF2ED4827C482C3C7ULL, 0x8C1440D46D2D7C45ULL, 
            0x76ECDBB18FE07171ULL, 0x5837757E09D009A3ULL, 0x4611937A81C1802CULL, 0xB75D22CA097A4B60ULL, 
            0x2CCA0A0442350526ULL, 0xBDA7756F09F0A5E7ULL, 0x4B823497F3C104E3ULL, 0xC5D5FC898720008BULL, 
            0xB6F650FB0E82EBD6ULL, 0xA4CCCA65B2AAB8DCULL, 0xED7EB1C049469D28ULL, 0xEA92DB4CE9B449BDULL, 
            0xD7B71738C4ADE767ULL, 0x89A3D7D93467BEA6ULL, 0x952C4A8422FFCC04ULL, 0xE7C01B7243F67862ULL, 
            0x14BC07BFAE907861ULL, 0xCC0D5F5BC6A65E95ULL, 0xD7A4FE37DD53D723ULL, 0xDFA75122AFFB8222ULL, 
            0x536C172950E28E6FULL, 0xD7B348C36FFCBE0DULL, 0x30A6083A649E388CULL, 0x809C7A66333E07D9ULL
        },
        {
            0xB746D641B0009978ULL, 0x6FFBCD55C5428D70ULL, 0x44DFB1EF25D6B943ULL, 0xA5527CE8C38B9E6BULL, 
            0x8FB016C29DFDFE7DULL, 0x83340B2D9B3B9D39ULL, 0x836F7BD629FB84AFULL, 0xF5A40228EB156D03ULL, 
            0x6741270955E9F09CULL, 0xA21C617305BE8CC6ULL, 0xD8DD6634C96A63EBULL, 0xB640A451EBCE7C71ULL, 
            0xFB810599026A3B73ULL, 0x3F5CC4DE448685BEULL, 0xE12DBDD9E3B0CC58ULL, 0x26BD7387EAC94688ULL, 
            0x83CB7852F6DA4006ULL, 0x9F687BFEAE01B86FULL, 0xB3342D771D0D87DAULL, 0x94E07E970AA27093ULL, 
            0x5D672290C744A6C3ULL, 0xCE1DC934BB5D21C1ULL, 0x858152167CE35124ULL, 0x80144D2AAB0566B3ULL, 
            0xDA091D321C8F065CULL, 0xDA880F5DB669E5B8ULL, 0x21552D011D730F4FULL, 0xFB8E5ACDA42F8831ULL, 
            0x5A6DB20D8968C1A8ULL, 0x44D6F2B07784418FULL, 0xDA57A7A3B6996E0CULL, 0x317CB8B148CD299BULL
        },
        {
            0xC1F618B790FEA657ULL, 0x85F35C0D24D5FF94ULL, 0xE327359CE7258167ULL, 0xBF3E9080B3578099ULL, 
            0x10AD5A4506A822CEULL, 0xFD68AAD0783D4886ULL, 0x41A3916D73655F82ULL, 0x8AB337666E0F2ADAULL, 
            0xBA4F37E69319AD90ULL, 0x94A57D84BBAD1B2AULL, 0xD21BB15E19826B14ULL, 0x76F034BBE1CD334EULL, 
            0x2C5C2918A3A3E110ULL, 0x8D17CD6BEED3993AULL, 0x8BA93021B22A823DULL, 0xE18B1FD5CE5ED014ULL, 
            0xEFC1DCBAADBF2865ULL, 0x21EC4E1AF8627753ULL, 0x632F844417FFF999ULL, 0xE962880F63A9A322ULL, 
            0x7518444A1213B5CCULL, 0x5F839111F351F9C0ULL, 0xA900479081EC3B7EULL, 0x95951F77D7C10611ULL, 
            0x81B3C1304BC010A9ULL, 0x0D67A2A07AB6BF1FULL, 0x598DAA8142CE50D1ULL, 0x71608A5B1D68E304ULL, 
            0x96571F433C4047DBULL, 0x79E67355F95B847CULL, 0x0BBA979C5DB9D372ULL, 0x3FF8CF8576043D70ULL
        },
        {
            0x95E9060F19EAE34FULL, 0x6AA512244D848158ULL, 0x0D923332870AB308ULL, 0x170CC39B1983A496ULL, 
            0x7D3D39BF4B78B251ULL, 0x5C8649110D708630ULL, 0xEC2FE66B0533B06DULL, 0x958552B20A7A4DBCULL, 
            0x078E797CC2FE5F7CULL, 0x263E7B87ACB53B3FULL, 0x03242F78F1978BA3ULL, 0xD6AA7E5C374A53C6ULL, 
            0x41F231DC388E9207ULL, 0xEDE8C334FC2FD13EULL, 0xA89026166D4B5DF0ULL, 0xAD44FC2297570A2CULL, 
            0xAB1AA08FBC7AA32AULL, 0x03AC15CA0A61961AULL, 0x53C64FB5E35EC492ULL, 0x0666DE08AE546CF8ULL, 
            0xF33850996234FFE9ULL, 0xC642159D6FAF0C56ULL, 0x5657CA89AE242C26ULL, 0x0B084230F77A34F1ULL, 
            0xD710D598CBFCA59CULL, 0x900CE5FECDFEF688ULL, 0x26F8AB06A7F55B8FULL, 0xD438524752C59104ULL, 
            0x5E6BB76E4314899AULL, 0x6D9543D46A9622F8ULL, 0xEFA1671901EEC7D3ULL, 0xD22D1F9173843E7BULL
        },
        {
            0x09A2C6F4705D96D0ULL, 0x6D9F8283223A2A68ULL, 0x07448A69A278658BULL, 0xEBFC27F04D1FBC20ULL, 
            0x4A94542ACEF9C350ULL, 0x05E6CA905EE59906ULL, 0xC240692F136DEE64ULL, 0x98172B5AFD36E3BDULL, 
            0x14702FBEFE643178ULL, 0xFFFD575B8AA7021CULL, 0xE4CA38359FE52CDDULL, 0x80023D21AD71BE0BULL, 
            0x00CDF1600086B232ULL, 0x291F14A2BA6FEA3DULL, 0x8795C29EC2E2A38CULL, 0x92A19E8A86018902ULL, 
            0xDEF70E4A939FFFA2ULL, 0x7169CC735A1C055AULL, 0x98A59D7B3EC7D8E9ULL, 0xECFA156412C30554ULL, 
            0x34E0A59FD6446759ULL, 0x5650F80A84673B17ULL, 0x10151DC7AFE69E71ULL, 0x9881F79A5E120764ULL, 
            0xB92978782767094BULL, 0x77AAEF6728443495ULL, 0x2360D690301451B9ULL, 0xDD70755BFA62A825ULL, 
            0xEBFF629464AEA28DULL, 0x34E85C294C625265ULL, 0x5265B72126DA04FAULL, 0x770F654DE1B37202ULL
        },
        {
            0x37EDC0854DA36F2CULL, 0xE522EB360B880569ULL, 0x4E143B9A2DAFA88BULL, 0xED12BB5B1DF02349ULL, 
            0x7E2A5E01471BFD19ULL, 0x7FBA3934E29141D6ULL, 0x88F4BC7823A598D4ULL, 0x22CB4FDA7014B577ULL, 
            0xD9C6CF2503E6EDE5ULL, 0xFD3D6F1608600E77ULL, 0x015A92BFBAF7F048ULL, 0x871BFECDB43FA614ULL, 
            0x2FA0F67BFFDCD5F7ULL, 0x16B8907C46C5B377ULL, 0x4555B10AF5AB7414ULL, 0x03B436C807FC3479ULL, 
            0xB8113B7BE538F68CULL, 0xFA2CF48252F2CDDAULL, 0x8A5E5A2D147EF1A6ULL, 0x85DB5546B72609A2ULL, 
            0xD5DE49628E4A6FF6ULL, 0xFB2BCCCD1AA7B93DULL, 0x59426EF63CE8886AULL, 0x52B443C61C2D94D0ULL, 
            0xBD5C1C76A784EC36ULL, 0x732DA7100266735DULL, 0xCD57F65B15AFDABEULL, 0xCD782DF4EE17D9AAULL, 
            0x443CAD7D91CD6B0AULL, 0x4811AC4AC8C1C38BULL, 0x0DA1F86614FBFF8AULL, 0x06C171BFA1477809ULL
        }
    },
    {
        {
            0xAAE0CDFF57BA48CEULL, 0xF34B1A1A7CAD3012ULL, 0xD8EA73FCFB0547ECULL, 0x95F00688CD6CE54BULL, 
            0xD03D3A94CE48F249ULL, 0xC66DB1EE4B852D54ULL, 0xE410A1608C8278C0ULL, 0x43DC7C7F724F102BULL, 
            0xA0C797926BD36DB9ULL, 0x783312C67E2988ABULL, 0xEE3D4735C798400EULL, 0x39DB9BC35A88F829ULL, 
            0xBFB1B862D5038133ULL, 0x97FD28C2F9B1FB6CULL, 0x1167BB2441BB3346ULL, 0x4D5510E77D0D7467ULL, 
            0x41DF43AF95DD2BCEULL, 0x8F4CDEADE7D7C412ULL, 0xB90E4521F1FC2A43ULL, 0x04809308B4C5C118ULL, 
            0xE56007BAAC2AC014ULL, 0x78CEE16EAA338C83ULL, 0x6D2A97711F81C93EULL, 0xF8499A176D7C9FEEULL, 
            0xCF082D5C8C1A1C20ULL, 0x2F5DFEAC6CA1DE8BULL, 0xF0276FB432E61B8AULL, 0x7E46D3E36C9EB0E9ULL, 
            0x44067B22BA7B3EE8ULL, 0x8ED37975E54B051DULL, 0xADB2FB5670C1F3F2ULL, 0x708577826AD00BFDULL
        },
        {
            0xB00C5F269A4F8C94ULL, 0xEC91F4D81A16A2E7ULL, 0x7DEBAD4449C55A27ULL, 0x3422DBB5C7358ECBULL, 
            0xAD46B5F1F562CCCFULL, 0x1C80E85098289809ULL, 0xDBEEDAAB04CE1A6CULL, 0x332A26A9C0478D03ULL, 
            0x454250CC36A9D915ULL, 0xBB5F56B912016CD7ULL, 0x3DE36B60FF766C63ULL, 0x9B65649812B79104ULL, 
            0x046E2AC63F3075A1ULL, 0x0627759E3EBC21CAULL, 0xB7C6A9D08AD65EF7ULL, 0xAAF67D8476200246ULL, 
            0x18460A91AC13A5D2ULL, 0x2ED0E2378C3940D4ULL, 0x6D40A065B429E1CAULL, 0xFC63CAD003D031DEULL, 
            0xC97261988282ED12ULL, 0x21D600A7259AF505ULL, 0xF7D7C4EA37912DCEULL, 0x2D5BA9B27D2C23EBULL, 
            0xD413E68ACF51EA9AULL, 0x2CE678BB1C2112ECULL, 0x7540E0BB7D22DB9FULL, 0xE30C89DDF1E62160ULL, 
            0x977F5A7994DED4F9ULL, 0xE21A82EF23CB946DULL, 0xD8494631DD4F52F1ULL, 0xF13B7614622AACA2ULL
        },
        {
            0xDAEE7382EA479385ULL, 0xA4D7B622C5D199F6ULL, 0xB3514D433469CC5FULL, 0x6EEB76B9F874A1E0ULL, 
            0x31268CE263004CF3ULL, 0x8A4594231EBF37DDULL, 0x3101B4973CC36E25ULL, 0x0D2B06FAA89B0C3FULL, 
            0x2D665FE9994742F6ULL, 0x4F9FA9920C8538A0ULL, 0x896D7BB12BCCCE58ULL, 0x65B7717E6E1DC900ULL, 
            0x8B9B2BB223E5C17CULL, 0x210C105B7ED66E7FULL, 0xBAE575DD822D9A07ULL, 0xCC37518118441D45ULL, 
            0x0B0EDA5B99ACBF6AULL, 0xE2F3A4190CBD065CULL, 0x6EAF1FD8D367A4D3ULL, 0x9884D5D258BC0A2CULL, 
            0xDC4393D88CB76D21ULL, 0x4FCD51E28DB4967FULL, 0xC853CF3DEAF25B12ULL, 0xDB53D7D9B645604FULL, 
            0xDFC5270ADEC1A426ULL, 0x09EDF46454B12377ULL, 0xE668159E378818D0ULL, 0xF137644E8F999EA6ULL, 
            0x33159C40D2A6E884ULL, 0x18D5C7A0B933E250ULL, 0x33F1FE70A0E83758ULL, 0x2C769377BD5870B5ULL
        },
        {
            0x18B44E0CBFC02F34ULL, 0x39B72F829F787ECEULL, 0xC62778CA418EA451ULL, 0xD3F93D049BE3C106ULL, 
            0x0F0F9970C563F7B4ULL, 0x946DE5EB2C633FBBULL, 0x667B46737C2FE9DCULL, 0x422FABAF9AA7F7D1ULL, 
            0x788E2794D83F68D1ULL, 0xB284B6951C86B2E8ULL, 0x52B5A8D67B0B67FFULL, 0x081CA2EA109029D6ULL, 
            0xA7F8D311397D93C9ULL, 0x1AA961ACC6324448ULL, 0xD534AF5B3DEC2EDEULL, 0x3A893FFA814254C3ULL, 
            0x9DF170B0120020F9ULL, 0x0C31E2B3C45E4141ULL, 0xF110F8E20310B006ULL, 0x82579B48EF373F27ULL, 
            0x8D8FF0A3EDEE5010ULL, 0x085B55F60294BE94ULL, 0xEE32A64F9910D9F5ULL, 0x74FD84985AD3DE0EULL, 
            0x12705ABEB58C76EEULL, 0x5C3CA1CCD1AD5DC5ULL, 0x5F3765272FF04DCFULL, 0x90D91B4BEC53FB81ULL, 
            0xA355BB58FC5DAC9BULL, 0xA73EC0888E6B27DFULL, 0x92F8D3F8757CA0A6ULL, 0x1E39FB7094A0076FULL
        },
        {
            0x01C7462BDFA97F36ULL, 0xE54509AEF67A56C6ULL, 0x38D605EB2E00FBB9ULL, 0xE72E251ECA70F67CULL, 
            0xD6883D83E7A01F29ULL, 0xFDFE783D556A26EBULL, 0xC6D0B7D3F5CCDB45ULL, 0x4D7A90AAB169A945ULL, 
            0x148DDEC282AE67E5ULL, 0x557F6CB4A1691428ULL, 0x0FFFDE25D8C4FE30ULL, 0x9A99222B1D616D45ULL, 
            0xEDE78A10A464570FULL, 0x0CCA81F4CD707708ULL, 0x81058DD85EFB9D65ULL, 0x6E54DBBDB0BEBCADULL, 
            0x4A7C4B46F9BB614CULL, 0x3265C589909CD519ULL, 0x0D1153BB0A402F37ULL, 0x867E25F8CD9CAEADULL, 
            0x9361D6630C43F9D7ULL, 0x4382981381BD7E13ULL, 0x1ED11E209BF09CCEULL, 0x44335A737D39E0A9ULL, 
            0xD334FB9A4CEA57B6ULL, 0x4C10B2A46D12A455ULL, 0x33192561BD0A992DULL, 0xD144305295DEAF37ULL, 
            0x28A7F1DB1D79882EULL, 0xAD705A2183647249ULL, 0x72482E8F9E4476D8ULL, 0x274CC79670F742A7ULL
        },
        {
            0x677428E6C6BF172CULL, 0xE265BE0819739C6FULL, 0x78EDDC50826CF798ULL, 0x723B2FA7623E32E5ULL, 
            0xE3729D5A8534EF79ULL, 0x044C3611C685D335ULL, 0x3E11CC69C81C28FAULL, 0xD51531DD0B9F4C13ULL, 
            0xF6050F7A79D0D4C0ULL, 0x45903C66C891CB1EULL, 0x12AB437576AFD99CULL, 0x7558BC86E57F3DAAULL, 
            0xBCA65A728035ABA8ULL, 0xED9058E48A6F2383ULL, 0x718D4F951E1905B7ULL, 0x782FE5734EB80F9DULL, 
            0xDB4F0456C71A08DBULL, 0x116A664290CBA87DULL, 0x5BC829AA7A7CE32DULL, 0xFEAAD0327711513BULL, 
            0xD1AFDC194B6BCF8EULL, 0x167BF5DA7A876B2EULL, 0xBE83E97B48F117A2ULL, 0xE0C93294FBBDA088ULL, 
            0x2D3394C3A0D85E4EULL, 0xAC0FB04F05EBFEA8ULL, 0x59FD854DFD89A76BULL, 0x9BFC63B935CF4195ULL, 
            0x8D2C3E3F384F6860ULL, 0x193FA07F20CDBC02ULL, 0x460D93E7577907A3ULL, 0x04548BBEAEE5A5B4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseEConstants = {
    0x16658A6D656D218FULL,
    0x41DF5C2BA2647E17ULL,
    0x69658EB7B9E72D89ULL,
    0x16658A6D656D218FULL,
    0x41DF5C2BA2647E17ULL,
    0x69658EB7B9E72D89ULL,
    0x4F16FD2DE15FE6ADULL,
    0x1B2410B70F38D2C0ULL,
    0x50,
    0x9F,
    0x36,
    0x80,
    0xE6,
    0x95,
    0x70,
    0x61
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseFSalts = {
    {
        {
            0x6DE04CA2CB817388ULL, 0x13FB64CBB119387EULL, 0xD23D246D609AF566ULL, 0x0A83A6D3B0C858B5ULL, 
            0x77BD6C5B3C977586ULL, 0xF0E72B2FCA26BB58ULL, 0x0F3FDEF5FC5DEFF6ULL, 0x36E10FBAD57452C6ULL, 
            0x98A6E4D8BDA6D900ULL, 0xB831D0C2D207B292ULL, 0x7E48D3D49A39614DULL, 0xCD3D9C2886EA128BULL, 
            0x03784205F6C23157ULL, 0x18815EB8E627F2A1ULL, 0xCD988F3CCEF46358ULL, 0xFF8CDA45222EBC12ULL, 
            0x05F23ABC30062C56ULL, 0xA36AEBCA850389B4ULL, 0x93AC0E6E88CCCB4BULL, 0x7E30D9BA266A24CFULL, 
            0x322B28D0563863BBULL, 0x17237FF98DDFE4BBULL, 0x1B4D7BAFC2917A08ULL, 0x2D18A3EAD9F38B07ULL, 
            0x4780DC58A9088BC2ULL, 0xBDFC4CB2D6DB28BFULL, 0x5F3F56979044C95DULL, 0x6B0DEA8458B18B5BULL, 
            0xFD0BB1428B88CC3FULL, 0x6D9C9FFE40F29229ULL, 0xC050E310DCED1466ULL, 0xB100740C3F247D8AULL
        },
        {
            0xCD08EFD2563D1451ULL, 0xBDDDD562D3FC4C39ULL, 0xD44A15F6C82223D7ULL, 0x545E13C8BD2C3F09ULL, 
            0x15DB9003ED467FA6ULL, 0x0D170E1F4EE23343ULL, 0xD5A132E340075228ULL, 0xE183AA2F53E16684ULL, 
            0x3EE8284E7D1EBA79ULL, 0x9F886D549B961F32ULL, 0x39F5D1CADC7B00E6ULL, 0x8741F269B9C20F50ULL, 
            0x9D70A23682734633ULL, 0xD9AC97CDB0A5D4C5ULL, 0xD748849D328D083BULL, 0x77E178DA613DB98EULL, 
            0x619E1C6580BE547AULL, 0x55D14A0168A743B3ULL, 0x8C7DC8FD3418354CULL, 0x7C00937EBC8BD95FULL, 
            0xFE8466D94F715896ULL, 0x54562B4B327102FDULL, 0x7B45D7731C95F1FAULL, 0x89C7744FB21F791DULL, 
            0x54F8AE3E62FC4EB8ULL, 0x9436E24E2FB3D856ULL, 0x18E727CADB988985ULL, 0x34B5D1AD5E5F02DCULL, 
            0x85CABD19C55A794CULL, 0xFDD200853A0A7C87ULL, 0x0A83CC07DD7BF2ABULL, 0x2258D8D91A30CB05ULL
        },
        {
            0xC95ABA5D0D5F3BE0ULL, 0xFEEE2CAF762AB273ULL, 0x6AED35659787D4D3ULL, 0x6C5D032D08A5CFFBULL, 
            0x05304991B838D446ULL, 0x615F9B538220471FULL, 0xDB7FE86E1D560B5CULL, 0xDF371F6E73623426ULL, 
            0xEE5566163184152FULL, 0x20546970D617A0B4ULL, 0x3A73762A1FFB19EDULL, 0xB754813F41624F6BULL, 
            0x58B1C4C9F068ED5BULL, 0x5F2B65380285DED1ULL, 0x55D5FF3B2D55DF92ULL, 0xF149F6F9854617FEULL, 
            0xCBEF7E52300FF3A7ULL, 0xE771BFE7B9934E4CULL, 0x14B7251D28A2891BULL, 0xFA5E4EBA0CC63567ULL, 
            0x944798D84533407DULL, 0xCC7AF1448D98E6C9ULL, 0x0ACE3CEE01E142B5ULL, 0x28747B937A5A1DC2ULL, 
            0x28F261CE65627C55ULL, 0x08279A575C6B63F6ULL, 0x2DB94CC43C8CCEBFULL, 0xD84E02BBBDD89F20ULL, 
            0xA97681BDAD4552F4ULL, 0xCF068A4A705DE33DULL, 0x894E0071DE89E497ULL, 0x851201AF75707DE5ULL
        },
        {
            0x525C086AF800C514ULL, 0x62F1C00C9F176891ULL, 0x6A6B0A9C9AD2CF25ULL, 0x96C8BCD91302DCF6ULL, 
            0x91036AC9F0B3B613ULL, 0x993E319481F57C1CULL, 0x1367034952344651ULL, 0x5EDAD978A3CD1B9EULL, 
            0x48515A4BDB974097ULL, 0xA1211B8F0E6D9B62ULL, 0x0B340A916A35504DULL, 0xB4E975C489944540ULL, 
            0x4C33FF52E556084BULL, 0x328B9D9963CDDAF5ULL, 0x15799408885A2118ULL, 0x0EB5888ECFB924C2ULL, 
            0xB2E9464A288EEDE2ULL, 0x2697335BADFC5B4BULL, 0x3E078C1C87AE6D33ULL, 0xD0E86A7301E42FD4ULL, 
            0x5512202F924EC72AULL, 0x397838C6B426B20BULL, 0x3E9581FB9427BD9BULL, 0xB50B17E759F4B8B1ULL, 
            0xA246A749A28E3E80ULL, 0x8AC6A31A0505B482ULL, 0x9ED1F57D7E267228ULL, 0x2F0EBD3080C45ED8ULL, 
            0xAD2F46B17B68325AULL, 0x71B2F9EBEC006D70ULL, 0x6E7C724A4EB68275ULL, 0x9A869CACE51C65E5ULL
        },
        {
            0x78BC930C568A031DULL, 0xE50E38BEF18616FEULL, 0xA84BD0A814AF7030ULL, 0xDC56CD955B7EF1C2ULL, 
            0x54FED2889BAE97B2ULL, 0xE01994F3B50CE3B0ULL, 0x55E4299110953785ULL, 0x2A3C9E82F470D3A2ULL, 
            0x55F38EA7BBA4C011ULL, 0x616EA1F0E1152F2FULL, 0x7272BFE64F7A338DULL, 0x7562E5CE7B464218ULL, 
            0x3665340D4D153FF9ULL, 0x07DA8CA7695CAEAAULL, 0xDABBB18A73218F0AULL, 0x49E27DCB129E4DAEULL, 
            0x1CC82E0E7A4136F3ULL, 0x44AF33818EC0CF89ULL, 0xF42A304AEA5C9DA7ULL, 0xCFFEC96DEEB64965ULL, 
            0x08C5D3296615DF65ULL, 0x59736E1CCE3AE533ULL, 0x7C80F057B4ED0442ULL, 0x8538AA4C26749A33ULL, 
            0xC66AA0B93EA31F76ULL, 0x4A212ABEC89BD91EULL, 0x498EFA6EEA1B5525ULL, 0xBFA6632D630E4D4FULL, 
            0xA8FB4DED688E4091ULL, 0x3CE222C3B5F94D55ULL, 0xDCE5483E666C0BE9ULL, 0x16598C7A54FEA39DULL
        },
        {
            0x91FC1A968385009EULL, 0x3AD9F97BF28C7552ULL, 0x9077A8FF4A0CD97CULL, 0x3B83598218CC00EAULL, 
            0x85FC1FE96874E470ULL, 0xF050FAA2D2E7A625ULL, 0xC618706CA2AE83CFULL, 0xA86A96C74ACC321DULL, 
            0x4FE17CBECF823216ULL, 0xF47833AC18FF236CULL, 0x80B5445B3E5E29A8ULL, 0xDE8D795CB970A57EULL, 
            0x52C4AA7EE606DDBCULL, 0xEB5BD0DDAAB28185ULL, 0x89152C936680A73DULL, 0xDDEA9502342F6694ULL, 
            0x9AA829B36E8C20BFULL, 0x1BFB802DC25B713BULL, 0x9B58833F3608A04CULL, 0xE0E528FB200A56D0ULL, 
            0xE09D4FFBD71140E1ULL, 0xDBAA95BC2AF37C17ULL, 0x589B4BFD0CA2C6BBULL, 0xDD27C14F0C553E33ULL, 
            0x34E81F7210D3EFC0ULL, 0x54E42303CE34BD2FULL, 0x59FE6955C3FA74D7ULL, 0x560D0ACAA6FE6629ULL, 
            0x5EA936AE2B0B849FULL, 0xB61AD3BE2EC04FEEULL, 0xFFEA622EFE624605ULL, 0x5973CD4BFAB9AF16ULL
        }
    },
    {
        {
            0x19792126D7C408C7ULL, 0xB5E924512ACFDAE4ULL, 0xA412A2ACCB115158ULL, 0x4E0722ECA7C8755DULL, 
            0xE0E74F8F8BEE1D28ULL, 0x3877080EEBA7CF5CULL, 0x01F31343D56EEE43ULL, 0x3CA58599A085902DULL, 
            0x50BA5E30A088BA4FULL, 0xDD2E758F70F133DBULL, 0xF76AC3BBD8F0767BULL, 0x19E61D85CBC4A934ULL, 
            0x7CF2EF5503850D7CULL, 0x42314DA1D1185975ULL, 0xC8A4FE371FAF185AULL, 0x2B86DE9503B52B57ULL, 
            0x13D9017EAEC337E2ULL, 0x9EEEB3D0CE60A520ULL, 0x4D030FF91F6C2186ULL, 0xCB823EE09F7D3706ULL, 
            0x3B28ED49731BE15DULL, 0x568F7A062F66B34FULL, 0xBC4EA3821D93852AULL, 0x28A974EB72892B62ULL, 
            0x43318F3DEC31E2AEULL, 0x6831EF8482E3ACE3ULL, 0x5798AA64CDEF8F6DULL, 0xC43211C0B6441133ULL, 
            0x6CE9F59F432F5458ULL, 0x7D31B80C30DFC0DBULL, 0x3A9BCFE71F43AC9CULL, 0xDB90C622BA3BC26BULL
        },
        {
            0x71BA2E0C89240E70ULL, 0xEBF706B234117FACULL, 0x42B632B02FEC92BDULL, 0xBB17AAFC123B9799ULL, 
            0x4859E058802CF136ULL, 0xA13945746840572BULL, 0x12F7E7DE51977178ULL, 0x8EC7436F237C1471ULL, 
            0x6834CC809F527F59ULL, 0x23FB673470F91005ULL, 0x882AC4F192BE1559ULL, 0xD387FA8605F5A6D0ULL, 
            0xCDB95E324398E177ULL, 0x272A36C4AAFCFEEDULL, 0x93A7694CB7B35622ULL, 0x2F00EBC0072BE15FULL, 
            0xB0E22CA361038403ULL, 0x6328EB90B8D5D927ULL, 0xB62E38E0394776EFULL, 0xE61E759CC00AC701ULL, 
            0xC937FE7666153FCDULL, 0xB645CF75E20A8FD0ULL, 0xE22847762B0D666FULL, 0x62A2B44B4A62BA2EULL, 
            0x7F3C28F5EA0D0B35ULL, 0x61D87180C3496DF5ULL, 0x1C0DB82A43D7DC18ULL, 0x92DC43E449E7757FULL, 
            0x165483DF5C09FBE9ULL, 0x88FFEFD4A6FE6203ULL, 0xBB8D391B054CFDC8ULL, 0x892688B6DABD3F72ULL
        },
        {
            0xE4273D1922D3D535ULL, 0xF8332CDF807FCD28ULL, 0x1673BDEA2367A321ULL, 0xDF745D1088CDD462ULL, 
            0x04CA7706E0CD5D67ULL, 0x4CAADFDECC1E25E7ULL, 0x77A102222E37A60EULL, 0x1A6A4F7D1EFDA585ULL, 
            0x238C092CD0E1D3F6ULL, 0xF5BD3D4642261072ULL, 0x087C7890FD82896CULL, 0xDC76EE9A235642D4ULL, 
            0x11FBF6A0CF3DCA18ULL, 0x1EDDB38AB2E4799AULL, 0xD5D0BBE672878EF9ULL, 0x41E1C73401759D9DULL, 
            0x9FDB71E86CFFB209ULL, 0x5AF236EFA6461389ULL, 0x56F1A2B22B9FFE5FULL, 0x92EAE136FE52AF68ULL, 
            0x590493C6D939307FULL, 0xC2B8A88DD1F5450AULL, 0x18F2274DD330566FULL, 0x4055FC9B30D1C64AULL, 
            0xDF463BF254DBE643ULL, 0xACF41B620ADCA96CULL, 0x4E3B1C93DEE23222ULL, 0xE0615E6F595E5917ULL, 
            0x4FD769E5773C275CULL, 0xA73EAE949071DF1EULL, 0xDC545092C1B5855BULL, 0x395D4FFCA427FF56ULL
        },
        {
            0xC629237A2050BC75ULL, 0x51F023D99A625DE3ULL, 0xD49E0E2B08F29049ULL, 0x9F01C914AB0107CCULL, 
            0x315756BD35DD5BA3ULL, 0x388E90CA37804576ULL, 0x1499EF8DF564F4B4ULL, 0x010541EB9B92E33BULL, 
            0x35B31B509D811FDCULL, 0xEB5E576D8BC2960DULL, 0x44D4BABFA6B236E9ULL, 0xC68CB97BE9A68754ULL, 
            0x25E7C57DAF84B4CAULL, 0x7281DC3AC115C00EULL, 0x1A5608EAE9ED93FCULL, 0xEE127CC8520F8EF4ULL, 
            0x67499CD2FA2B1C66ULL, 0xA013A8D00DE1843EULL, 0x03D4C0399195E16DULL, 0x3C5A092F8650C9A0ULL, 
            0xEF6F88DFD4764298ULL, 0xE6601E965B436E40ULL, 0x497A57DAF545D42FULL, 0xEF991FB55D4B22B4ULL, 
            0xECC3F4D4C9E99F1FULL, 0x70A9C380B386CB4DULL, 0x513B3E0157B4BA65ULL, 0xF4BA3E27A1986050ULL, 
            0xC8ADDA49BEA5815AULL, 0x718638666CA76BE9ULL, 0x6707A87E6692939BULL, 0xA600328CD64BFEC9ULL
        },
        {
            0x4A98857BABC545C0ULL, 0x5FB9B607EB62DEC1ULL, 0x774F6E6D648115E7ULL, 0xC963A74FDB0AF20EULL, 
            0x0360076F2A40B736ULL, 0x77DEB297386305B5ULL, 0x7972820FFEFA2064ULL, 0xC81D28BB9755D1FDULL, 
            0xB15247144D8755C2ULL, 0x3380633A990666E4ULL, 0x2CE555BC466E61A7ULL, 0x06B90945A5AE6AD9ULL, 
            0x71AFC336048D7CDEULL, 0x64B5F3F5208E1AC1ULL, 0x706EFCD8DFF05153ULL, 0xD7A5A7DCAC85DCE7ULL, 
            0x5699BAC2B4CBDB28ULL, 0x92C782754087C900ULL, 0xB7C721EEF129160CULL, 0xDCCB211F591C38FFULL, 
            0x201B3BCD8C7B8770ULL, 0x1EFCBA28947A1A32ULL, 0x6359CE683C147D46ULL, 0xA12FC32821A92258ULL, 
            0xA6FB1E2939A7AB82ULL, 0xF76F4859614617FCULL, 0x1222AB7D5DE7C1E3ULL, 0xA6314AE5F6312DA5ULL, 
            0x519091240D2C5256ULL, 0xF44D125C0D81CAF2ULL, 0xF4908DC6FC4066D2ULL, 0xDC56C9C2BB86956EULL
        },
        {
            0x8B194ACC59253B7CULL, 0x0B8C16C6851A2538ULL, 0xAE1BB54838FA0A7DULL, 0x3059BD645015137CULL, 
            0x75BE7DFDC778A0D7ULL, 0x25A12E8E57CD5B4CULL, 0x093DC77CD9553761ULL, 0x9542C71BAFD647E7ULL, 
            0x851F4177D80C35A8ULL, 0x1C479B1E53AC3A39ULL, 0x5FE1C123E7FE393CULL, 0xD9440A36397C09BCULL, 
            0x31F84CBCD925EF46ULL, 0x2F099593C4EF1692ULL, 0x3AA8074411C3D228ULL, 0x108B1ED0EAFE0B10ULL, 
            0x3A152C4F92E69D1FULL, 0xD323850DE5CABC1AULL, 0x972C33F7F1BE6948ULL, 0x429CEB68A7ACF233ULL, 
            0x25A5F6503096FEAAULL, 0xE9C16FD6333063CFULL, 0xB0972E62B730CAA9ULL, 0xCCDEDC09DDF52F77ULL, 
            0x49B655433A2DA3EEULL, 0x34A5B650FD704F0BULL, 0x55BFC697DEBBEDE2ULL, 0xCD9548EB7EAEACD4ULL, 
            0x0373203B96152B36ULL, 0xE28007CB930C0F2FULL, 0x7FC0148E28F15EF9ULL, 0xB4CB3220027C1A40ULL
        }
    },
    {
        {
            0xC4F936668B11212BULL, 0x749E62C102EFA9FCULL, 0x4C1BB172C0627041ULL, 0x7741AB9CED74482DULL, 
            0x2F1D4DDAC351D0D8ULL, 0x96CE64E7D4855030ULL, 0xFAEB7E864D0BAA1AULL, 0xE152C4840E697BB3ULL, 
            0x4CF4B2765EA19BD7ULL, 0x450327FC29D90C29ULL, 0xDF69E089EB8DFC3BULL, 0x84C4B0FA4F617309ULL, 
            0xB719156CE8F2D21AULL, 0x91A517916C9447E3ULL, 0x73FB17C17AA7AECCULL, 0x75755519653334FEULL, 
            0xC969D3721FA4C0C5ULL, 0x7BA402A06A8E11B1ULL, 0x5B22575B65BE0634ULL, 0x367AD9CF10FAA1FAULL, 
            0x2AF564123BBD8FD3ULL, 0x400E2A918E8EC854ULL, 0xD11F45AFF7B7CA28ULL, 0x02B3BF6DA1ED5F96ULL, 
            0x96BD81003FF3C4DDULL, 0x45F6273822BAE4F3ULL, 0x96B3B078B3CBFD8AULL, 0x5AF6A5F1A1ED56E5ULL, 
            0xAED2C7FCA22A19A0ULL, 0x09120FB8C7382C90ULL, 0xA7A40C309A83670CULL, 0xE9189E12982D654AULL
        },
        {
            0x4E2993BABDF87039ULL, 0x1B7256F7DCFA5C03ULL, 0x4E981160B5215748ULL, 0xF778280A88159B3DULL, 
            0x73FF797198B559C9ULL, 0xBFC7B3D788C28E51ULL, 0x516BEC2E0009B644ULL, 0x14944BE75918B477ULL, 
            0x7F949055CBD2ADE9ULL, 0xF06158AAD8D19D08ULL, 0x1C6001612E4F5C50ULL, 0x06F33CE8DAF6C633ULL, 
            0x66EAE05B320D7545ULL, 0x732F6686A2932061ULL, 0xD184A7D63221460BULL, 0xF19C39AAC77DE568ULL, 
            0x317E0A4FB4078276ULL, 0xD7D2398E6DEA4440ULL, 0x47806153DFBA5531ULL, 0x14CA9B7E519956D1ULL, 
            0x59A3E083E2073492ULL, 0xFEDA9EBDBD45ABA7ULL, 0x76FB5104E2848736ULL, 0x06EE887AE6114C1BULL, 
            0x2039C94B31F226DEULL, 0x89A59698C2EEDBCDULL, 0xB0F1951F02ED8C84ULL, 0x663CFAA37EE80205ULL, 
            0x4BFD4CFC85564FE9ULL, 0x60CC5FBD8170A3B4ULL, 0x6996963DD36B3062ULL, 0x790BE53FA394B37CULL
        },
        {
            0x8E71A9D8DE6200D7ULL, 0xC0A9AC1ED210F527ULL, 0x987BCFEEEC272C3FULL, 0x8EB105FF0AD8FFCBULL, 
            0x5E2F1485C63E44A8ULL, 0xF87B0FB29ED433E9ULL, 0x0BED157B114DD6D2ULL, 0x41BE5B00E6447D5AULL, 
            0x5A60FA29E7C1EA01ULL, 0x1734663011D6D0B9ULL, 0x9C4DE11A5C59DD8AULL, 0xEA844D87CB14C800ULL, 
            0x71FA294A81A551A1ULL, 0x6B38B709E20F45BCULL, 0xE08A4B1921BB94CCULL, 0xB5166779116B93C6ULL, 
            0x183F40A3B216218AULL, 0x69153944187BEDAFULL, 0x88BCF2C5B51C2BF6ULL, 0x0A108C1488BE702DULL, 
            0xD42BD90C39B6159EULL, 0xD7B796A833078E95ULL, 0x538B792960E8184AULL, 0x199A4C3D77D52F93ULL, 
            0x431FBAE13B70C652ULL, 0x4A623236A93786E4ULL, 0x9AEC5D87D44A4ABFULL, 0x370165091792202FULL, 
            0x79388677B3B5C49AULL, 0x2745FF5FB709142BULL, 0xD234749FB8F59F07ULL, 0xBDBC3D872F9371DFULL
        },
        {
            0xCD54A978E0F69BC7ULL, 0x1BCE79C6973E3E8AULL, 0xEA672F3E414FE1FFULL, 0x05225C671AB0177DULL, 
            0xC498BD61F3B79086ULL, 0x27F4A5FCC7ABDF5BULL, 0x23834B03951C81A1ULL, 0xF657A9A0CC17637FULL, 
            0x0E07E9D364969D1AULL, 0xDD12EC5B55CD7468ULL, 0x405C0869264D6A62ULL, 0xD79E98A7A8D8993EULL, 
            0x97FAAD055BA6B9F2ULL, 0xBC2D0D9AA6CD83A5ULL, 0xD38302CC365C368BULL, 0xD367F02B682B055CULL, 
            0xF98CEA4B8B7C8984ULL, 0xC1FFF0335B99F4ECULL, 0x51CF7DB37712F71CULL, 0xEA90F119A532B6E6ULL, 
            0x5908DE80C152AF43ULL, 0x5CD3697E2BDD952DULL, 0x884A38D336CDB946ULL, 0x1F66BC46CCCEFE03ULL, 
            0x36F1A418E33AC2F9ULL, 0x44C0CB66CBB0766EULL, 0x2CAA1C060E02888DULL, 0x1D391431C23F0EF5ULL, 
            0x566742E89D1FD7A8ULL, 0xBDBD718C5030A5A9ULL, 0x2E4998FD1BC898D6ULL, 0xF05469FDB68E484CULL
        },
        {
            0xC3B1B3132698D263ULL, 0xD1CABE62E3EC624DULL, 0xF57CFF6DFFDAD438ULL, 0xE2C9EACB6ED2AD1BULL, 
            0x6297F27A2058B8CCULL, 0x042A800C070ABB08ULL, 0x9093A381F6D8E15BULL, 0xA8899E88DE413E8FULL, 
            0x3B5DD1FB813BC7B3ULL, 0x312106A2DCC4E9AEULL, 0x5714F896DA76D825ULL, 0x0C37924FF686C6A4ULL, 
            0x2071EA9727E7F868ULL, 0x9865D759D0F1CBE5ULL, 0xB663A7F060F2C76EULL, 0x28C895734E2525E7ULL, 
            0x44E542E3C75C49DAULL, 0x9B8F446CDB46F5D5ULL, 0x0FF14330EB6136CCULL, 0x70BF5D58E2D9ABD1ULL, 
            0xCB2A3C2CA697D316ULL, 0xC2875C6103D3A933ULL, 0xE68772638BF6DBB4ULL, 0x7339AB5DC8F8307BULL, 
            0xE6F3F4A184603AE4ULL, 0xCD38073CE73675A8ULL, 0x693871D6E4CB26B2ULL, 0x5BB8D217B7FE6038ULL, 
            0x504A4C346560364FULL, 0xA6F5357A5F227386ULL, 0x96C71EE1BC5A0B49ULL, 0xCDBC1FBA6DE72F9AULL
        },
        {
            0xB31C24692008884BULL, 0x2A22D2F227DBC659ULL, 0xA5C459D2F0CEF127ULL, 0x2DCACCB2288A6D19ULL, 
            0x0271E26CEE4E1753ULL, 0x0934D96183F0D5ECULL, 0xDDD435E02F6D9208ULL, 0x14708331F97D299AULL, 
            0x43374713DFC35DEEULL, 0x9C97C99F3A44CEA2ULL, 0xEF61F71B76C12C5AULL, 0x2C2548FB46DCB809ULL, 
            0xC3BA6E99C2A1C172ULL, 0xCA6B8565419C149EULL, 0xF72E3E1F84ADC8E9ULL, 0xDA096ED042A2719EULL, 
            0xD3C8A41952FD59F2ULL, 0x6A0A87BD2C8DBB2DULL, 0xA6033021C114B773ULL, 0x5DAC3CDD047859F4ULL, 
            0xBC49E64CD6184F44ULL, 0xE63FF9B4F0FBDB1CULL, 0x320E846D59A5EADAULL, 0x90278DE12B7AFC4AULL, 
            0xC1C41723CCE93F15ULL, 0x2A5E2CE348C8846CULL, 0xF6D2381E1DC9ECF2ULL, 0xF7D60F1114731CBEULL, 
            0x8226ACF44254D6A3ULL, 0x0C8318EDD9517819ULL, 0xB9566FFF9DE4FAE8ULL, 0x98319BC1F2E026F0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseFConstants = {
    0x7844D13B01D126DBULL,
    0x12007424476E0852ULL,
    0xD14B57080207776FULL,
    0x7844D13B01D126DBULL,
    0x12007424476E0852ULL,
    0xD14B57080207776FULL,
    0xFE6BD32EB3B7E76BULL,
    0x0B30D0F8C7A34255ULL,
    0x07,
    0xF6,
    0x14,
    0xD3,
    0x03,
    0x0C,
    0x48,
    0x59
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseGSalts = {
    {
        {
            0xF110F96C9E93499CULL, 0x6E3F60BFECFDDD89ULL, 0x6E3AC107C8CBBF7FULL, 0x1BCA25F86634ABEDULL, 
            0x577B02913AB49B23ULL, 0x2E67EB44729491E3ULL, 0xE5266815A849D89BULL, 0x488831CDCFE2690AULL, 
            0x3DD65DC03A41F12DULL, 0xF47786A849E8FD8CULL, 0xC6E2B7BA681ECC25ULL, 0x24DBE01006F50675ULL, 
            0xAAE14DEB11639848ULL, 0xADCD559D17C17C3AULL, 0xDE70A9702F0AEF01ULL, 0xB3D1087970282971ULL, 
            0x5FB41B8118EF54C5ULL, 0x569F6E512482D3EBULL, 0x71943B82A07D52CDULL, 0xB7D898B122281E81ULL, 
            0x802381C79B80D89FULL, 0x32126AD53136EB26ULL, 0x0CC185C34BBAB9EAULL, 0x72CB156A1BC5BA0DULL, 
            0xB53BD329CCEC33AAULL, 0x95A8906C72EE511BULL, 0xCEF1BC0BD0149C2EULL, 0x4305F35999380F7AULL, 
            0xAFC80BA44C7B9A08ULL, 0x18BD8B465A9D9AF7ULL, 0x961A8F2988518DA4ULL, 0xFDE1CC28063DDFEDULL
        },
        {
            0x70B91A0E55B2C53BULL, 0xC6E950E53F24DEB9ULL, 0x92660CF118E07C5AULL, 0xFCCD0201F04B011CULL, 
            0x7EBB6E1B600CED5CULL, 0xA60A14F3C723829FULL, 0xFF91368A11AEBE93ULL, 0x185CFB7CE3257AAEULL, 
            0x03A2CF8A7AA8B521ULL, 0x6B7436B82E8DBC0AULL, 0x7C80425C5F0278EBULL, 0xCD9A4CBE0F5FA37CULL, 
            0xDD952858B7C7B59EULL, 0x84DAF7D4741CB108ULL, 0xF48B84A3AF8A22DCULL, 0xD91CF019205FE809ULL, 
            0x1F32EE75078D7D18ULL, 0xCAD3D158644E12A4ULL, 0x1BDA58E667DBAB67ULL, 0x0B956B40B31C6E12ULL, 
            0xC02D5D174F86E8BEULL, 0x9F1342EA2FA69C83ULL, 0x24258A78E9C3D362ULL, 0x3D2501B1986E91F3ULL, 
            0xF986CC94C84A1EFCULL, 0x0389CA82D318CF4BULL, 0x1EB3C7BFBDB91538ULL, 0xF5A3AE0748A56AB0ULL, 
            0x116F9D7EEA764EDBULL, 0x05E99DB563C75301ULL, 0xDB69E21A5513A489ULL, 0xA0D13D63D426995CULL
        },
        {
            0x1024D1576991FA2BULL, 0x22A55C49745AE8EEULL, 0xC23F8CBD30E48DF8ULL, 0xA90C0C3C7A302897ULL, 
            0x56CD725ED7EB63DDULL, 0xA6F1C126B3256766ULL, 0xC6E011BB6F4BE5C3ULL, 0xDA186042ED988D6CULL, 
            0x12568BBD974738AAULL, 0xD708746CA877D918ULL, 0x96308F60AB9070FBULL, 0xD1663A284CE78992ULL, 
            0x98737F531EDF93E0ULL, 0x17944D0C1E46730DULL, 0xBD2927A3C807035CULL, 0x6666462ECC7DAB0AULL, 
            0xEC804AB2EF0BE76EULL, 0x8849B652436D36ACULL, 0x96810649D2F7C82AULL, 0x85B8A28E2EA7ECFFULL, 
            0x98870DB764640876ULL, 0xD4A8CB5B867E7CD4ULL, 0x8D3A82552FD467ABULL, 0xFCA6670C25E08898ULL, 
            0xCCA8B28DE2E90C77ULL, 0xB665DB9027B4AAAAULL, 0x57E2D022EC7D02F6ULL, 0x78143A682C592534ULL, 
            0xBD698BE78FFD4FF7ULL, 0x643DA2633FDB70C1ULL, 0xF9B8CEC0F29B87F2ULL, 0x7F781AAE25DBCB4FULL
        },
        {
            0x0BDE98ED0E758247ULL, 0xD3FB8CF179B66283ULL, 0xDCB3781F8AB4291EULL, 0xED3B2DE9DB6F64F5ULL, 
            0xEFAA55D340751D1BULL, 0x8299E04DFE4E9AD2ULL, 0x69FB5625ACE48E87ULL, 0x1B3F4C35DCFC8C90ULL, 
            0xE2EC4D5D2D6DF11BULL, 0xD0AE189F1F65B88DULL, 0x8CCFE8D7568FE958ULL, 0x678142D6966AEB3EULL, 
            0x2DD138CDDC25835FULL, 0x3D73D9C89EAC9D0EULL, 0xF8EB94FBD5410CEFULL, 0x24E83A901E0FA553ULL, 
            0x4D82884B7F18FCCCULL, 0x617FA9C3D9C1E2C1ULL, 0x7BD8A2BDBB264351ULL, 0xF39257E453C361B6ULL, 
            0x9163F902C4AE04D6ULL, 0x322CB761D1B9AC21ULL, 0xFAE98FA31A1B5510ULL, 0xF4F8EA738AD49845ULL, 
            0x32FA9249FC0BA379ULL, 0x9EC31A430A45423FULL, 0x0AAC467BE7FADDCCULL, 0x951A4AA830912A50ULL, 
            0x20CCCF987DF7D3BFULL, 0xE2BA9DE9C19F709AULL, 0x98E24BEB5680A858ULL, 0x294FCFE2A8CEA142ULL
        },
        {
            0x698E4F3B4D8CC022ULL, 0x504F76E2C2B811E6ULL, 0x33D978C25CBE7C75ULL, 0xF060607C6EE1083AULL, 
            0xE55A8239F63C52A5ULL, 0x8E95DF561FFDAFDCULL, 0x3326034DB27BAFAAULL, 0xF03E62875216AD23ULL, 
            0xD4E52E7BE0EF4287ULL, 0xA0C2DF92CC9D7616ULL, 0x1AEC80D235DCD9AFULL, 0x84C71191B379DB25ULL, 
            0x08E6A241D7C6E8EFULL, 0xD8D2B61390691AAEULL, 0x9AC08D683129E96EULL, 0x8F03D52080EFB1F5ULL, 
            0xF816EA3AEADB4F27ULL, 0x3889FFF164A05CA4ULL, 0xBF95656BD0D48197ULL, 0x3B22D4E327F31974ULL, 
            0x4D12CBD8BED696EEULL, 0x1CF75891BB839302ULL, 0x142104B51DADC3A6ULL, 0xE7942608E815BB39ULL, 
            0x94609442C31F7F44ULL, 0x075A0D489DD2718CULL, 0x40A98972D49C2C94ULL, 0x81BD64CE8C01109CULL, 
            0xA1FD866A8C698986ULL, 0xB8203685262E3297ULL, 0x1076649AC82B99C5ULL, 0x0095968BFB3CFF94ULL
        },
        {
            0xA3CA4A1C10DC4307ULL, 0x495127CDABE6240EULL, 0xAD5B9F39B8FBCCE4ULL, 0x19E398BB77B08EA2ULL, 
            0x89F7B8C310A2D442ULL, 0x86897A0BAD42CA41ULL, 0xB24E49418323EBC1ULL, 0x9E4DD5C61DDD274EULL, 
            0x3F6B09609156594BULL, 0xA4E086CB8E0C53FAULL, 0x9D02588C11B447DAULL, 0x69083B784644259BULL, 
            0xB763D7B56826DBF1ULL, 0xE4A1ED9B56FBC1E5ULL, 0xAB05A07FDEAFB5D0ULL, 0xF1471C211C78C24CULL, 
            0x44881BCF995DA941ULL, 0x34A908320DC07B7EULL, 0x38C1F52B959F52AFULL, 0xE7CE42F0BFEF39D3ULL, 
            0xA3DABB4A299E2A83ULL, 0x3F23D7BF9E129DFFULL, 0x09173B203A0EB09EULL, 0x846E7783DCDFEA0AULL, 
            0x6D350E879FD324D1ULL, 0xD4106885E6D62F56ULL, 0x6FC3AD51D3664D44ULL, 0xBB2A9DACEED49912ULL, 
            0xF8C74CAE3CB49DC7ULL, 0x035BC2F501740574ULL, 0xCC48F05F2B723649ULL, 0x64B67F2EB02E78C7ULL
        }
    },
    {
        {
            0x384211B55780EDAEULL, 0x24712010B0D89CD4ULL, 0x38CF39EE2ECD4EB9ULL, 0xB17565C282FDE333ULL, 
            0x8EB0BAAD9D24F17CULL, 0x20AAC2036C17F226ULL, 0x134E9826338D5713ULL, 0x6766B67FF42AB5FBULL, 
            0x0BD475CF3A4983D2ULL, 0x99E57EC1EE1A24ADULL, 0x76B033B9E192BE7FULL, 0x3BE62DD5713C8D53ULL, 
            0xAB6F7AF6D71453CEULL, 0x22B8026D5CC9D882ULL, 0x14A0D5C93A9BCF24ULL, 0xE12B78ABDD25F96CULL, 
            0x74738A3E5101F347ULL, 0xB30211D301E01BE3ULL, 0x2C9269D6DE95DBD7ULL, 0x5AD98B46AB6BB8AAULL, 
            0x2E8D15B71C7B615FULL, 0xEBBE47A079E1A6B2ULL, 0x0E6D985C8AF80961ULL, 0xCAE0F344792A1448ULL, 
            0x75089D447E0E3442ULL, 0xA8E4DBD7E8F4A8DCULL, 0x3A1AA453CC54A47EULL, 0x18B67ACE50DB3A66ULL, 
            0x073B78F4AB13D844ULL, 0xE04279AFCC217DB2ULL, 0x01D31EA692DD9367ULL, 0x6CB0FD0AAE2F6939ULL
        },
        {
            0xD02078D03A9684F9ULL, 0xC0546ACD0320147EULL, 0xD6F9714C9F859B74ULL, 0x08DB566D7AC511CAULL, 
            0x3F646A738A629D55ULL, 0xBE694D2D47ED7DF5ULL, 0xC9AFD179B749B7D4ULL, 0xA81DBCAE75BC0DA3ULL, 
            0x8B3525857E277DF1ULL, 0xAED3D326711D3FF1ULL, 0xDD7A8C0A70334CA2ULL, 0xABD9CED7F811D5ACULL, 
            0x4692CA777B22D1F0ULL, 0xBA29C00228ED5356ULL, 0xACFE94A3CB91BE11ULL, 0x960F43AFE4CA5B49ULL, 
            0x6FC966D4FB550251ULL, 0x80C7C231C76B7578ULL, 0xEC0E29ED5F5E3CA8ULL, 0x790A31B3404435D7ULL, 
            0x9734CE11AF54A02AULL, 0xFE1BCA57AABDB372ULL, 0x352C58FEA0FE8E73ULL, 0x3C60A40127C77848ULL, 
            0xD18B15896C4666B4ULL, 0x30DED505F3893576ULL, 0xFF4DA912608C9BCCULL, 0x8B979926C9084390ULL, 
            0xB4277556C9E95DAEULL, 0x27957C1870F95D5AULL, 0x83B83DDCF5DE1039ULL, 0x695793CCD856C024ULL
        },
        {
            0xECF223BC19F7A707ULL, 0xF4CE6049A080503FULL, 0x33FF45C0F9244361ULL, 0x509E947341FC5823ULL, 
            0x202DD643B64B4F42ULL, 0xBEC5DE2354F6104CULL, 0x4D11E7AA9FF8EC13ULL, 0xF4469F1CCAE78BA6ULL, 
            0xE71EA60002594486ULL, 0x1F81789CC5FE47C5ULL, 0x883FC88EA1A3E130ULL, 0xBE6FC547D011604CULL, 
            0x1735D6E0F604C5F8ULL, 0xA6C45CE6C6885983ULL, 0xB222B196629F579AULL, 0x35639C0ECA0048A5ULL, 
            0x921A96825F9ED299ULL, 0x54004E24AD670A46ULL, 0xCF9A1A16A66B9CD0ULL, 0x4833E4AEF68C7362ULL, 
            0x9999062F180B572CULL, 0x914C425E0726C24EULL, 0x25BC4E251BE8D9A7ULL, 0x7E34A12ECAC5D56FULL, 
            0xB3067E33B90E19F1ULL, 0xF05EFB891CA8F002ULL, 0xEEA6D1F252C750FCULL, 0x8BA3244557A61E78ULL, 
            0xF3446664C28C2634ULL, 0xCA997EE74131C10FULL, 0x7F4AD5B87D982FA3ULL, 0x6220576F194C1EBBULL
        },
        {
            0x3E6C8AA865FEF563ULL, 0x423E0C54B7C2AB13ULL, 0x9D7D90F39515B45AULL, 0xBC3BD9490C2E3A85ULL, 
            0x85347DE34E504490ULL, 0x87DBDD1796EABB76ULL, 0x51CF42E0BA26A96CULL, 0x80C81BA4B92CC2A4ULL, 
            0xC8F17950E8DCD64AULL, 0xCD873DCA20877A37ULL, 0x0EF4A75D2AB36333ULL, 0x173C5158D858C61EULL, 
            0x7F68488F1AF9FDF6ULL, 0x3B3B2485B8BF0DF0ULL, 0xBEEB98D9695844F7ULL, 0x17F24839885861C2ULL, 
            0x330070F7A9982EE6ULL, 0xFD5E5C2B4D82E60CULL, 0x1A10161FB09A570DULL, 0x5D62EDA07D6EDF7EULL, 
            0xEB1F6C2553DF201BULL, 0x6CE6C39C45E0B98AULL, 0xD7364B676A6D8D29ULL, 0x4EE11C1CD7EA7506ULL, 
            0xD66DFB6C3BB2F7D0ULL, 0xB0C2F4AB63AE2FA0ULL, 0x0D495E553CD36A7EULL, 0x0406D94DEDE59A6FULL, 
            0x9F3BB57C990EF9CFULL, 0xCD5A6919433A749AULL, 0xEB67FCD10B57AA12ULL, 0x717183287C601A06ULL
        },
        {
            0x0A817A4E57386590ULL, 0xB78008BD6B543F4EULL, 0x94A42B46EE09EFD4ULL, 0xC0C6327533920339ULL, 
            0x5AA5A1CCA6B49798ULL, 0xE00FEB6759390D14ULL, 0xE9AB66D8CA4A9F4FULL, 0xF5A425DE5C1585A7ULL, 
            0xD5F4190D13834A0BULL, 0x9E829D468B62A151ULL, 0x0015EDFAAE4CAE94ULL, 0x729219B080C14D90ULL, 
            0xC8C476E4009F7517ULL, 0x2EDEC031ACFE6B05ULL, 0xCA2ABCE203A4AA47ULL, 0x605757FD485E714BULL, 
            0x2B1CCFF81737724BULL, 0xF5DA9F21D70D1408ULL, 0x9FE1712991945527ULL, 0xE9171287F7EED14AULL, 
            0x457B256E1C8C2BDBULL, 0x0DAE1959DA871EBAULL, 0x2A0B6B6E553BAE87ULL, 0xACFB81B586E172ECULL, 
            0xA8F57EEA85712AC6ULL, 0x937F038A084A9F58ULL, 0x573592B496244F70ULL, 0xA5E9FF3E6E18FCFBULL, 
            0xE39032BD66F15DABULL, 0x1FDBBCDC5E516C63ULL, 0xB3744B9CD8797742ULL, 0x0EA655495D194BC7ULL
        },
        {
            0x23B7478BCE8DFAECULL, 0x557634053182E7DDULL, 0x2F9AB4D734791F8BULL, 0xF51D0CA34F860CDDULL, 
            0x5A114BF77699E2D2ULL, 0x62F69E12C94ECF6DULL, 0x562D65B8EE8A2133ULL, 0x7DA2764F2A629D92ULL, 
            0x1238E533C67C4BC0ULL, 0xE79A964A99470691ULL, 0xD44E3A07DCA59200ULL, 0x11F909E57793C6E2ULL, 
            0xCD9EA84D7A12AB9FULL, 0x6D6BD810E97C5033ULL, 0x96925E077D54E37AULL, 0x8C899C03BBE048FDULL, 
            0x8F3312683B2F8448ULL, 0x6363283C127AEBBFULL, 0xCC442FDC2A657D06ULL, 0x76D1715AA90D7F46ULL, 
            0x8B92CC761329DD87ULL, 0xDD82A994895C919BULL, 0x2E500545F99FE1E4ULL, 0x947967C3642501F2ULL, 
            0x0B545108A8A0BD0BULL, 0x9B5F4AB38FD0000DULL, 0xDB1BFB9442B04814ULL, 0x3A393722C21A5EA6ULL, 
            0x21D392AAF477519AULL, 0xFF9E99408A65DDC5ULL, 0x9E69F3ABFD67B2ABULL, 0xA6543455AA6DEF53ULL
        }
    },
    {
        {
            0xBC6A32AAEA1A551AULL, 0x694D54E160C1D548ULL, 0x0B4140F5165CF59AULL, 0xD31E97A8EFC1FC19ULL, 
            0xA265D3C517CE0CCBULL, 0xF633A80C27BE3200ULL, 0xDC884351BDFB6EC1ULL, 0xB4ADE3393DA9F363ULL, 
            0x998284F982EF11B5ULL, 0xDD1765C065FFE5D6ULL, 0x0154BCBFD6B8BF46ULL, 0xC78732D0421D6979ULL, 
            0xAF9C613BDA0A898BULL, 0x920AA3322287D210ULL, 0xC28CAC65938C18ECULL, 0xFC8F9ECE50701A9AULL, 
            0x9227356B0058CE25ULL, 0x68CE68D47DC3C66BULL, 0x70B9FA1F14D14DC9ULL, 0x5F6A4280CBD40403ULL, 
            0x004DAC3753B5D0E3ULL, 0xD340CC3DB45F349FULL, 0xDD699FBAE67AF492ULL, 0xCD8E3F6CB2CCF4BAULL, 
            0xDDA4F0E475BC0DA1ULL, 0xFC53732046E78539ULL, 0xF1AD0C7E68F4DE43ULL, 0x379723A0FA5E3BE7ULL, 
            0xAFE28651346B6E05ULL, 0xE1C95094E9F86F80ULL, 0xA91743DDD3886B52ULL, 0xDF50ED3C32FB75EFULL
        },
        {
            0xEBF8B03FA4B7CA0BULL, 0x5916ACCF7D45ADF7ULL, 0x7DB95F60A91A7F62ULL, 0x7A7364342969C972ULL, 
            0x20DA318EA5BBD2B8ULL, 0x9E8CEB8263AE1506ULL, 0x66855D2CABD39E42ULL, 0xDDF7F622F88975F8ULL, 
            0x3FDC520741A3B2AFULL, 0x35F9511791537007ULL, 0x703ADDD769D549B0ULL, 0xF7AF7A3CB176CD34ULL, 
            0x95B3AE6F42D53611ULL, 0xE57523136F27EAF4ULL, 0xAAF142DF054CD5EAULL, 0x58F8CF09787AE189ULL, 
            0xEFB3640B98152371ULL, 0xDC187FB3946CDC5BULL, 0x4C0F6ECEAB0C6C49ULL, 0xDB7954857E2CE1B9ULL, 
            0x1812C3D096436F27ULL, 0x7FDCE89E5DB8A0B3ULL, 0x3D18E166DBA95D5AULL, 0x7602686D615D8C4AULL, 
            0xB0113BD4B6C65ACDULL, 0x3874EF1A1AF1321DULL, 0xE9AAE40B6DA21ED8ULL, 0x3C55EDAF92CB1178ULL, 
            0x502DAD63481F8CCCULL, 0x1F4156306E1F4EDEULL, 0x95A8412B32D211BEULL, 0x38C2E937C3FE2588ULL
        },
        {
            0xAE5BA041D3901CC8ULL, 0x40E652F3C275B0ADULL, 0xE5904E2AC55FA6BCULL, 0x32860A302EF18CE3ULL, 
            0xF033876579C637EBULL, 0x01835A6B575749DFULL, 0x0675137122C5BBD2ULL, 0xA4DFC5241C52EAB2ULL, 
            0xB087C107EB1855ADULL, 0x125647FC6DF4774BULL, 0x8989D01F331DB72BULL, 0x7FD1CC1E34F0EA2FULL, 
            0x68AB1BF9A4395A2EULL, 0xA11815E67F24A539ULL, 0x0EA43181FA1925EAULL, 0xDF4DF9F26BAD6042ULL, 
            0x62081F985E24CE3EULL, 0x2A2C7746A55616F0ULL, 0x970B70A090490B3AULL, 0x9A44A4F2E8909A76ULL, 
            0x978EAADBA54835F0ULL, 0x95874671CB19CFD7ULL, 0xE11BD0BA341A4B2EULL, 0x23B8C0FBE138B5C1ULL, 
            0xA91D1645CF062B0BULL, 0x9CE5E11DB10CD492ULL, 0x9682C3712AE93253ULL, 0xC2BE4E726563D0D6ULL, 
            0x3A7D36CC08A16C64ULL, 0x51BBD832619F0D66ULL, 0x558595E8D367A3E9ULL, 0x14F1255FFA49F917ULL
        },
        {
            0x158ABCD840D49AE0ULL, 0xC3A79C0849A689B6ULL, 0xFAD3038999E8A83CULL, 0x3445820A5DCAAD95ULL, 
            0xEED542F0D2EC0AD3ULL, 0xB80912E675DBE576ULL, 0xD95E341678F91AC2ULL, 0xAADAD4C16ECE9F75ULL, 
            0x10A3DE44CC998F61ULL, 0x77468F4726C22CA5ULL, 0xF46D597F0AA12076ULL, 0x38895812F96D55B5ULL, 
            0x6E8DE910CF9D19BDULL, 0x7FEE471B0FCFB488ULL, 0x6BFA9A96F9A70E52ULL, 0xA37A815C1CEF747EULL, 
            0x5A1866C75F7D4314ULL, 0x66A11CA3768F28C2ULL, 0xD4ED5A20C1F5D769ULL, 0xC23DCF210E7F0EDFULL, 
            0x8495E652B59C3D10ULL, 0x42D59838C194E5CDULL, 0xC8A474003F0E47A6ULL, 0x610782F57CD1F119ULL, 
            0x9919F1E3C423ED16ULL, 0xCC2A2EEA62A59B3EULL, 0x7C6713AE81B2D8E1ULL, 0xB2AD86D0DF0BC221ULL, 
            0x2DC2364C6D4F67D5ULL, 0x5E36F2D090C962BFULL, 0xB15E0D2452986DB0ULL, 0xED754B89BD13B0A6ULL
        },
        {
            0xC9FDE84938FD68B6ULL, 0x862137940EF8325CULL, 0x3AB3BD999042EC01ULL, 0x58C0E4A4BD180AE2ULL, 
            0xD615E4E4C3121126ULL, 0xA9381FBEE0BB1C73ULL, 0x008FAF4F6261D416ULL, 0x16E1E977249B20D5ULL, 
            0x864C203FCFBBA0FDULL, 0x58E133608FBE8F47ULL, 0x4BFA7422F3852CF1ULL, 0x4DDFF5D295F717C9ULL, 
            0x3C3BCE04E980C194ULL, 0x07D3AD7C2235B892ULL, 0x599998FFEEF3139BULL, 0x6ADBCF5A7314C8CDULL, 
            0x35683C69A1104F28ULL, 0xBEE70503342AC7B9ULL, 0x274FD6DCDD7EE7A3ULL, 0x45537F13B870A4B6ULL, 
            0x8B55CEA689B746EAULL, 0xA4CA87BB7E1F2DD8ULL, 0x122FE37812C30D81ULL, 0xFB666578E66FCAB0ULL, 
            0x40489EE9AD10B1E4ULL, 0x248FD66598E6C0BDULL, 0x1B24CA7F8AA8EDEBULL, 0xE33A19926422CC8DULL, 
            0x3D955BE059532A3BULL, 0xE65B10D71C5910C3ULL, 0x3D11A2EAEA9008BFULL, 0xDC14E2279C6A91EEULL
        },
        {
            0x4E92CFE75BD2FE47ULL, 0x45963C63977C371BULL, 0xB647A294C5F1314EULL, 0x79AB347AF760799CULL, 
            0x6F51273ED74EE4B9ULL, 0xA986FF7D3E3039D3ULL, 0x8B7BD98310FEB4CFULL, 0x54244E1282450A7FULL, 
            0x691C75017386D8EEULL, 0x4569AAD4F89A8B1AULL, 0x365DD464E1A72C7EULL, 0xFC713B198A415C3FULL, 
            0x2F13485CD268EF0DULL, 0x4CC74F4713F1FA7CULL, 0xDBE406977FD5B078ULL, 0xADD78FBF1E7BCC07ULL, 
            0xAD3672A3F3A88A45ULL, 0x09926A07DA661796ULL, 0xF6CE41FE1EA34CEFULL, 0x7EE6B0D404F6D637ULL, 
            0xC9672F99833E48F7ULL, 0x83C207F5F199FD12ULL, 0x79021226F054FAD5ULL, 0x68CA2D9B1DA293FAULL, 
            0x6D92787C24B25713ULL, 0x13CF753BDA05ED60ULL, 0x5010A8C77296E87AULL, 0x54CFD74829C2CE99ULL, 
            0xD036C7CFDF00E003ULL, 0x89CB1630DACCA580ULL, 0x52B4513B5507F666ULL, 0x73FD0E53EEFB7317ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseGConstants = {
    0x05F2FAF3C096111DULL,
    0xC2569AA02CD2ABF8ULL,
    0x88F44CD186FE8899ULL,
    0x05F2FAF3C096111DULL,
    0xC2569AA02CD2ABF8ULL,
    0x88F44CD186FE8899ULL,
    0x00BB41EA13F03AEBULL,
    0xB371A95D90CD81CAULL,
    0xC0,
    0x42,
    0x9C,
    0x59,
    0xF0,
    0x76,
    0x58,
    0x12
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseHSalts = {
    {
        {
            0x2E24119D25B4240BULL, 0xE57F4B004FA21F85ULL, 0x3753C5C7DAE070C3ULL, 0xE3B76A0FA820A4A7ULL, 
            0x9F5CFF7D77548592ULL, 0x15CAD1809B7DC0B1ULL, 0x68E8F959BCE8BFFFULL, 0xF51CB5EB1DEF6211ULL, 
            0x2BB92518DD6DE88AULL, 0x0360CC06AC498528ULL, 0xDCEC562A1A1E0FD5ULL, 0x0AC8D564C615F629ULL, 
            0xB83BCB9C115C71E2ULL, 0xEA180D4AA64C6C07ULL, 0x9453D64D1F94ECF3ULL, 0x257523934861480DULL, 
            0xB8FC8DEF8ED0190DULL, 0x9E72EB2794866935ULL, 0xFBCD94D53CA792F7ULL, 0x035649045E3D2556ULL, 
            0x179568426088D290ULL, 0xBE15B0ED3AE4504BULL, 0x3EC7B80814CEB6FDULL, 0x8B03396BA78BA11DULL, 
            0x9654BAEA7B4C24EDULL, 0x5923BB6E731B62EEULL, 0xD864597018F37CACULL, 0x2880ACDA07A60D68ULL, 
            0xB6F50BE62A72FC06ULL, 0x2D3BC10E360F056CULL, 0x3C33EDD4A9A54DA6ULL, 0xEA1C136BF668B8A9ULL
        },
        {
            0xC2085CA890D7E1B2ULL, 0x119493AA0DD54D01ULL, 0x71F97D368131FA72ULL, 0x3492FFAF8A486752ULL, 
            0x125E1AB543B872D0ULL, 0xB7AF74461B81F6C5ULL, 0xD67ED7CD9C93E219ULL, 0xE60347556A7B197CULL, 
            0xDD2F6E080336BCDAULL, 0x0CDBFC9B30464CFEULL, 0x737461327DA3A436ULL, 0x62794CCC7A6B4E9EULL, 
            0xE0F846E5699CC2B4ULL, 0x9A86D972B0D44322ULL, 0x025E32CEBA5197C6ULL, 0x988B4DD121CEFC6BULL, 
            0x10EF1936FE9C98FAULL, 0x87EB7AAB0F801AC4ULL, 0x14DAF09688F43F7FULL, 0x6B45466F3AAB5EA1ULL, 
            0x8533AC72AEE4F474ULL, 0xC09424935A8E2F83ULL, 0x1364A3B52845BC02ULL, 0x32E388534BDB8B81ULL, 
            0x0FC33B81DE3F31ADULL, 0x5F0C383C071070D4ULL, 0x36398F0965E9F84EULL, 0xD8262F87C46E1553ULL, 
            0xBAFA721E4B5DA079ULL, 0xA2E412FA6B021A0CULL, 0xFD71DF6335929A88ULL, 0x963A875B8F5C60C2ULL
        },
        {
            0x626B60345C241801ULL, 0x79470FBCB7C644DEULL, 0xDEBCAAD7A7E94BF0ULL, 0x28D6530FA39418BFULL, 
            0x644581929DB08E62ULL, 0xF9983FA4CE45B3CBULL, 0x37A4E2CEA9784180ULL, 0xCAD90E32A7BE2700ULL, 
            0xF587CFED75E68D92ULL, 0x6D97CE3C2E4D965DULL, 0x138327AFE8AC8FCCULL, 0x7458518507F2F840ULL, 
            0x939A438FF9AF745AULL, 0x343D19D4169E706DULL, 0x247B50F96FFAD8F0ULL, 0xB5FC5A2FB6D7746DULL, 
            0x37EEB22665495C57ULL, 0x8E5045D953DC9EB9ULL, 0x50989DF5E937C857ULL, 0x680EDA7E05E8DE20ULL, 
            0xBA3721345B2DF7F9ULL, 0x8BA60FE572768993ULL, 0x6C224811BA766AE7ULL, 0x6FD19B42F4A093CFULL, 
            0xFD48E60572688961ULL, 0xFEF56E3DE6A62154ULL, 0x98E0C38BB5A137B3ULL, 0x0B7CD5D13281B191ULL, 
            0x340E05000D491DBAULL, 0x3DB2E05561A0D01FULL, 0x0F24D92E69426936ULL, 0xDC7010A8B1404714ULL
        },
        {
            0xBFC3E77D758FE228ULL, 0xB161FB42501DDDA6ULL, 0xEA139F0339B0D286ULL, 0x5AE4B204A7CD128DULL, 
            0x61DFF7FFA3880F19ULL, 0x0F8FC017982BC268ULL, 0xE9C233FD42E29D43ULL, 0xDD61223B42B26BE7ULL, 
            0xD9D0FD6C42FCA812ULL, 0x16AFF82453DDD657ULL, 0xF91117213957D5AAULL, 0xE6F32066AC7D42C8ULL, 
            0xC12A4B81CC395D58ULL, 0x080F48958D1C4D7EULL, 0x9988866F6A150952ULL, 0xEAFF23BD5BDEE345ULL, 
            0xFCB887CDDB3A5F94ULL, 0xD1D7139196906FC8ULL, 0xBBA3AB3FA6BC5CDBULL, 0x8E538F921D51B668ULL, 
            0x28790AE3B81FE432ULL, 0x0CB210FAA7B25A99ULL, 0xFAE9624060941BC3ULL, 0xD4751495C837EB9BULL, 
            0x7E6B2C4E08ED223EULL, 0x0BED90B0F47BBB05ULL, 0x903A5E48058C13B3ULL, 0xEEE5DFF06D48FD61ULL, 
            0xA1BF4D1DAC414E9BULL, 0x4941A5CB8D47E44FULL, 0x8FC88820672BB38DULL, 0x69502BB67E25FE07ULL
        },
        {
            0x381A71BDC7BB4D96ULL, 0x36C58C314CD1FB93ULL, 0xCD50D2F93D39AE9CULL, 0x1101BC5D2333FAC5ULL, 
            0xC6BA36C7F9BDBB7EULL, 0x64F912AAF857B65AULL, 0x6A0CCE4528806818ULL, 0x7946029EA3FB3C4AULL, 
            0x41B6B549170CEA27ULL, 0x107A8CF7B982DC58ULL, 0xADF0CF41C94BBFD7ULL, 0xDC4DF6F644D6F5F1ULL, 
            0xB3ACBAD41D35EF32ULL, 0x74D859A8E9BAF70FULL, 0x52F3654EFA9014F6ULL, 0x63272FE56D22B09CULL, 
            0xBCEEABB8F024BC69ULL, 0x4B0DFA628178E732ULL, 0x94449EFB3B03A86DULL, 0xF1D127DBB0419D27ULL, 
            0x31BDB331F196F4E3ULL, 0x7D7717BF419F8881ULL, 0x035FC5A8071B633FULL, 0xB98C4B932E7E1A59ULL, 
            0x80D36FDE42EB36C7ULL, 0x21D308C40D7CF45BULL, 0xFFA168B1E6F2201FULL, 0x8CB3216CB817CAEFULL, 
            0xA72AD8252C557A44ULL, 0x7FABCE71E8B78A4CULL, 0xF01A1CAF6E7A928AULL, 0xB249454E0160FADDULL
        },
        {
            0xDBA2BC35787027FBULL, 0x9D3962073B351B6BULL, 0x48F2DE141C522A9AULL, 0x86DCF24904268B4EULL, 
            0xD1719D97DE5600FAULL, 0x64B00EB9D18CC489ULL, 0xC8E3306EEFADE0C3ULL, 0x6A2820D5302230D1ULL, 
            0x5406D0914A171E80ULL, 0xB8FC1A3B08C4F97BULL, 0xF33F7B369154FF7FULL, 0x521C45B2D67CE7E6ULL, 
            0xC38FEEB2CC39C3DEULL, 0x9F8E55BA1F89FE56ULL, 0x8F90EB09DEE16D59ULL, 0xD841B6FE12D5835FULL, 
            0xDBF5F254D1420CCEULL, 0x16C0FD8BEDF04209ULL, 0xB411BF27F2C26CB4ULL, 0x4DA1E8364B386BC2ULL, 
            0xE71BED80FA552751ULL, 0xA7C888D5C8940B58ULL, 0xCBC34AA6FE9B4390ULL, 0xA379C753C8B0EC4BULL, 
            0xDF90F2046050A3F3ULL, 0xB0D86C6F7FA24E15ULL, 0xEEFB6A69D8879207ULL, 0xF3D0721D76586F37ULL, 
            0x5622C7C260A4787EULL, 0xD8292D766CA55BE0ULL, 0xE3EF77D904B38E8FULL, 0x81A4116AA4F942E3ULL
        }
    },
    {
        {
            0x99712B1C098479DFULL, 0xE346A2D5765BA5ADULL, 0xF2A7FF45C0A5E342ULL, 0xC93A6C65E78C519CULL, 
            0xF5F6207CCAB80046ULL, 0x2A6174D6F7245BFBULL, 0x852271F83C56EF37ULL, 0xE61471F6DFDE5B8EULL, 
            0x7C18309E9A102969ULL, 0x1CA4A3BC1D7F8FABULL, 0x4153674CCE9D36E3ULL, 0xEF6C56959FFEF583ULL, 
            0xF54F6BC70F4A62DCULL, 0xB4479408737F0899ULL, 0xD1385E6C5F46590BULL, 0xA19508FC1C05A90EULL, 
            0x5F18F418CFF9C9F0ULL, 0x80D9DD25D2C37BF1ULL, 0x530813B144BFB05CULL, 0x1085675D7346686AULL, 
            0x7F65AEF984E2B104ULL, 0x0D42E2158E077001ULL, 0x02F32539B3896D8CULL, 0x69A5D85409E9350AULL, 
            0x7C09621F99E9122FULL, 0xD0B0E57CB9695AA9ULL, 0x66818A9E9C38688FULL, 0xBFC5D045705A64F2ULL, 
            0x91561B15D1D8197FULL, 0x878170566D7D037BULL, 0x4C8BE58E14630ABAULL, 0x29A985690E5D64A7ULL
        },
        {
            0x9B022F10D82E105DULL, 0x742A560F1BA45B24ULL, 0x532A90D545150730ULL, 0x475B270FEF11C7B1ULL, 
            0x254EDD5817465D61ULL, 0x2138DE1F095741E9ULL, 0x5BBB11432BF48E2CULL, 0x1A3510A1685D6CF2ULL, 
            0x32F707C8A769C571ULL, 0xAED4744B36BFB287ULL, 0xD141DCF6927BF332ULL, 0x51D34667CBA5C764ULL, 
            0x5A14B239F193D467ULL, 0xF237CAD352C6DB66ULL, 0xD48EEFD4EA20F607ULL, 0xDA486E12EED2A1DDULL, 
            0xF724A0DCFCBBD34DULL, 0xF20F9F7CEB6E8A3FULL, 0xBCFEC96D0FA0A45CULL, 0xAEEA02C6335AE752ULL, 
            0x1402B59561513C7EULL, 0x17106F77008E3407ULL, 0x005DD546EB243572ULL, 0x9EDECFE70DAD9499ULL, 
            0xDBF758C8A8C61399ULL, 0xD1223FEA48F6C74EULL, 0xE812AF77A5CF650AULL, 0x58D3E09CB9E65D26ULL, 
            0x493A608C5712AA94ULL, 0xB57ECCF390270FB4ULL, 0x1D8E00E0E710EC8CULL, 0x208563A15E66AA9AULL
        },
        {
            0x240B0CF4EEF8697DULL, 0x086DF3AC946F582DULL, 0x469DC5089463BC80ULL, 0x720D9898CFEA0EA8ULL, 
            0xDA696D73462F88B8ULL, 0xD138BFE8E1AF67A9ULL, 0xE81FC02890AAB7E9ULL, 0xD46A9FB7AD55FB31ULL, 
            0xA1BFDD89A8D4918EULL, 0xBC87951B21C67315ULL, 0xB121A789C014BB57ULL, 0x24E9989698C45C03ULL, 
            0xA9020E20A02BE13CULL, 0x4CCD0FB5E6AB2771ULL, 0x822772FB709D092AULL, 0xE864BCD5BFBFEA44ULL, 
            0xD9071574128D858CULL, 0x32B6C11F1036AA20ULL, 0x36EC2B2CB929FB08ULL, 0xB39C78597A527687ULL, 
            0x571B0AAB83096757ULL, 0x22E08E5B524B8C1BULL, 0xEA52D3A6CDF1623DULL, 0x63A78F4A20DFBDB0ULL, 
            0x2F6D64E2F4B6C20FULL, 0xE9337CBD76A8161CULL, 0xB9501226FA883471ULL, 0x92D3070F60F815A0ULL, 
            0xD446D0D45A3133A3ULL, 0x1B5454E5153B0298ULL, 0x85E05ACC32C9BE0DULL, 0x82D4EC96D0E367A4ULL
        },
        {
            0x7F64258E201BEEFCULL, 0x9E5055415F6A2BF8ULL, 0x8DEF37EF8403E7ABULL, 0x6FA2E42683A5E3E2ULL, 
            0x928B5E3BDD253FFEULL, 0x2283EFF4854E0B9EULL, 0x2A9D7B14243F063CULL, 0xB0953C4EBBD3B4FCULL, 
            0x7954BCDCA790F29AULL, 0x74770CF87CC46DE4ULL, 0x829CEB7C1F8CFF64ULL, 0x4837A791BBC6A065ULL, 
            0x0FD0943B9B0553DEULL, 0xB9159EC2D4BB0A3AULL, 0x98A23B3445A7C9D2ULL, 0x3F5BD18CECF62580ULL, 
            0x00C487D30C893AA3ULL, 0x4A1A53FE4B44A0DDULL, 0x33DCB4CB2D1446C4ULL, 0x5809971EDF01C542ULL, 
            0xB55CD103C83F2092ULL, 0x91657F3E3C9AE3CEULL, 0x1CA311E9DD17462CULL, 0x417EA66CF3DD5C35ULL, 
            0xD3441FA8A8F049C6ULL, 0xA28E589895A10582ULL, 0x5704D823E10F710DULL, 0x1ACD69B70270EE33ULL, 
            0xFE4AF1AB549D5EE2ULL, 0x756CC0C7BB1EA792ULL, 0x4D87BB29D014833CULL, 0xD0F92B8552228CDAULL
        },
        {
            0x6DA671211175829AULL, 0x8709600CA3D2D42FULL, 0xFFB87CC7B53DB3E0ULL, 0x9BD02AA931048558ULL, 
            0xBF955C259A958C27ULL, 0x4D2993AAD3B93E70ULL, 0xE1FF5058C0B0C892ULL, 0xA94F434B741001D1ULL, 
            0x8E6A16C23BF85D37ULL, 0xB7D05F24E10C8E88ULL, 0x36B43F2858A1F53CULL, 0xF7085E78375A6941ULL, 
            0x5A4F85041E4B7F01ULL, 0x8EFBB249627FE72FULL, 0x961061F10D122214ULL, 0x5EBB6DD8940D29F8ULL, 
            0x583D0DAAF113B69AULL, 0x43C404B9C5BCAFB1ULL, 0xE31B33B77164E84DULL, 0x06F308AEB9966841ULL, 
            0xB510A948EB67CA08ULL, 0x1C5C2A0A0154EE95ULL, 0x21EAAA65EC44ACF1ULL, 0x0A0344AC97AC7198ULL, 
            0xCA3EEF787012F78DULL, 0x588B76FE02CD017DULL, 0x6DAF9F940700D4A4ULL, 0xAE3924575D0EE1EFULL, 
            0x6C93E9D4F0ACDFB2ULL, 0xC2EB0AD73E2B8883ULL, 0xB9F355ED12B1C3BCULL, 0x80AF88893C3A63EFULL
        },
        {
            0x84AD4CF235E3C600ULL, 0x42B63BB411EA4737ULL, 0xCFA85CB5A3609604ULL, 0x1ECB5F0723545402ULL, 
            0xC150CA81A3A064E6ULL, 0x225A82703E30477FULL, 0x88531325763EF2C0ULL, 0xABE0AB4FBED01DF6ULL, 
            0xE5B6902549B5E008ULL, 0xD8B68E71D2C42575ULL, 0x08D8DB331EF6C712ULL, 0xF92409A600FD14B5ULL, 
            0x32D8D683DA8A0A8DULL, 0x93DD629DD56B54B6ULL, 0x8CA106DA6BD07E40ULL, 0x0DACD1849CC1DF06ULL, 
            0x45A3493E26D51DCFULL, 0xAC8BEDC9B4758089ULL, 0xCB74B6E8FCF668FEULL, 0x102B61818AB631D8ULL, 
            0xA3D3EEE358E24E98ULL, 0xDEFD925D80F7072DULL, 0xF699D9EDF7A35406ULL, 0x230B7F355DF1DA2BULL, 
            0x01D1246D914661DEULL, 0xEF140ABA86CB168EULL, 0x53CA20FF8629B3E5ULL, 0xD70782586481D3B6ULL, 
            0xCA3FBCECBFF247BDULL, 0x4A71E4C0956E77E4ULL, 0x490886C783D98535ULL, 0xB295451CAAC982F0ULL
        }
    },
    {
        {
            0x002DE238C1638171ULL, 0x9A957EF2182C3B7FULL, 0x896952CE68B4FAA3ULL, 0x775CB4D06AE33198ULL, 
            0x392BC057FB2B241BULL, 0xE62C91E638FD205CULL, 0xF3016A5CA4A24352ULL, 0xF604CEDEE7FCB6B0ULL, 
            0xC7CF0DAC0E593D5DULL, 0x5731CA7565D20E71ULL, 0xBB0B275DF8768A47ULL, 0x4F3CCCA2CC779E35ULL, 
            0x03FD82F4823BB6CAULL, 0xB90E4D69DAF1AE0DULL, 0x675E1102319D9A49ULL, 0x498CA6065E6EA9DDULL, 
            0xEE9FE0C39B9D4D4AULL, 0xD8C9A4F9835D765DULL, 0x230EEA5E9D304528ULL, 0x7D9054EB4E3CC7B8ULL, 
            0xAC6FABF4EE96B4C7ULL, 0xD140CD9133D1FC44ULL, 0x6025B118BE15A72FULL, 0xD0414AA50D5F1575ULL, 
            0xB20E630C47A950FAULL, 0x739046B9652A8D49ULL, 0x3AE2E381BE2B9765ULL, 0x140DB5E91A1C85C0ULL, 
            0x678FDC3839C8E740ULL, 0x2013B7396746523CULL, 0xC93FF80DE2931C5FULL, 0x3EC0EC0B2C4619D3ULL
        },
        {
            0x130FD9703751F9A7ULL, 0x21BCB2F13CE20848ULL, 0x0552F140EC04D758ULL, 0x3FC3D456518D1251ULL, 
            0xBF93E5ADD6EFC976ULL, 0x6DA8E76378C0E5BCULL, 0xF8FF15D979338ABBULL, 0x32780FCDFC738C95ULL, 
            0x5DB81F3C5EFB8788ULL, 0x59403F6E16F1052DULL, 0x8222603651C15582ULL, 0x29A8AB0930E40F9DULL, 
            0x3C2C1D1CFF9AB63DULL, 0xD17820C839BF1E9EULL, 0x9D0A906379D6443AULL, 0x7BBC898E0A5B2F93ULL, 
            0x72A9E0AEFE4FC68BULL, 0x6F6AE4CCB26D3F51ULL, 0xC1885140AA48289EULL, 0x372591AD8DB8378FULL, 
            0xA68AD95ED3C5A284ULL, 0x4967A0C535468FF6ULL, 0x73E7BE5413750715ULL, 0x26CDBF9C5B1F7F84ULL, 
            0x43CA2AAE727A4AF4ULL, 0x2E8AA453F758F8BBULL, 0xC1E28283E994D617ULL, 0x0E3F2543A64A01FBULL, 
            0xEDFE33054195033AULL, 0x6CF7D9D99F53A958ULL, 0xD8944FD16FFBE960ULL, 0x39CDA7F2DBE0E756ULL
        },
        {
            0x4852D401A20E4F0EULL, 0xF605AA86050A7C99ULL, 0x3175F57EFCE57107ULL, 0x98F31BBE46BF7371ULL, 
            0xE3D17A8B1A0FB4A1ULL, 0x372CA3ECA8A0D420ULL, 0xAF64283CA55F2A50ULL, 0x7213B821DC13C2A9ULL, 
            0x7DCD30C0B77E35B3ULL, 0x7DCC7200697FA806ULL, 0x208F75DC2E312402ULL, 0x663168F4B3FC5025ULL, 
            0xCB8B9BC2544210E1ULL, 0x231472CE14544810ULL, 0x36878E82E0F31574ULL, 0xF1151D79E450346EULL, 
            0xC5CEFB8514347407ULL, 0xD5B866F0505FC504ULL, 0x6753E753927BF966ULL, 0xEF0827976DF0EE07ULL, 
            0x46DF89D33C0C7A7AULL, 0x54D642537FD858D2ULL, 0x0B8F5BB84238AEFBULL, 0xBFF21270F9FC2D0BULL, 
            0x8D8277A2C6D9309FULL, 0x894E15EA0E218114ULL, 0xC7E7EA27686DD3D3ULL, 0x7076EE2A26548355ULL, 
            0xB7B2028D8B9241C8ULL, 0xE0B55537875EC62FULL, 0x3356645E6F35DA63ULL, 0x24E79CB8355C476AULL
        },
        {
            0x5B8E3C5C363D77A8ULL, 0xEAC80AB70CEAD2F5ULL, 0x78B2C437AF4A14C6ULL, 0xDED3B983E039B68BULL, 
            0xE5CEA31452C5F537ULL, 0xB9BB2C827F659E1FULL, 0x06BEAE1769E0DDB8ULL, 0xAF1E1B8DF4F44176ULL, 
            0x9E1918638995FD9EULL, 0x0785BB8E43684433ULL, 0xD8328638B8450AB3ULL, 0x1D5CB1B93CAA2FE3ULL, 
            0xB7CA4079D9CDB36FULL, 0xDBD8D369B42F9114ULL, 0x0FDFE86B8EA9E6ABULL, 0xB350A3A62BC55F89ULL, 
            0xF8ECA8A1DE16637CULL, 0x9B8EB7CD9DB9DA91ULL, 0x703C3F83B31769D7ULL, 0x916500DF316B04D5ULL, 
            0xE4B2695758AAD1E0ULL, 0xED371886A5C6DE12ULL, 0x47F3DAE7301B9594ULL, 0x5B4E85644CED4A2CULL, 
            0x560A724973980A57ULL, 0x38628E87A77127BFULL, 0x9A7EB822D4BACBB4ULL, 0xB678D10DFEF267E1ULL, 
            0x84C9439013BC7598ULL, 0xD68FAB21A572DF3FULL, 0x5909796CB7F5DBE1ULL, 0xEF56685C332F0242ULL
        },
        {
            0xF0057E2929969171ULL, 0x42C55CBEA3D8A5D5ULL, 0x8E65E7783778BC52ULL, 0x9A84D262F21E1205ULL, 
            0x94DFB406FFCDA98EULL, 0x1C70B4C6DC913074ULL, 0xF0F8AEFCF4E70050ULL, 0xD6B5C82F4D5ECB95ULL, 
            0xB4DCA3892282A172ULL, 0x43661BF3AF51C0A9ULL, 0x4E5ED9482B5EC16CULL, 0x9043B7F6D4AB5E2AULL, 
            0x2B5278C8F3E22C2EULL, 0xACB6A35F1EFC874EULL, 0x502119469462B92EULL, 0xF706962B5ABD0554ULL, 
            0x5B2D7AFF00D6E231ULL, 0x4A7E5074B75F8FCCULL, 0x889562C4665A6887ULL, 0x802E16F8716E9709ULL, 
            0x3F18F1F6ADFD794CULL, 0xBC0E0BB59E16F3A7ULL, 0x9DD0C66088AB8964ULL, 0xB6C8A014C7C79A1AULL, 
            0x95F69A8E67329E9AULL, 0x2C93A3AFF29B9525ULL, 0x7F43B5B13BEA0649ULL, 0xB81E97E686F955EDULL, 
            0xA910432DEF522371ULL, 0x2A859130A48987EFULL, 0xA108B3B29E592E61ULL, 0x9F6FD1567581C237ULL
        },
        {
            0x0FC37F5F1F1C7AF0ULL, 0x8D0FEFB8D735AD10ULL, 0x8B61870B5F3BC6A7ULL, 0x6B5E4C689DDBA8A9ULL, 
            0x12F600AC4A2F56A8ULL, 0x4253998C0DE59CE1ULL, 0xEF7953F73904B926ULL, 0x3021A52404EBE1B4ULL, 
            0x271DEE99E1217E9AULL, 0x98E8088939B59B5BULL, 0x35D910034E60B575ULL, 0xDE45CB3CC3001662ULL, 
            0xB061D9D72BA427DEULL, 0xF564D821CA2220F5ULL, 0xE12D34A58DFA1366ULL, 0xF5D92D76FF5F0770ULL, 
            0x8367A2F9AEE9A2E9ULL, 0x804720831616C349ULL, 0x11AF2C396D377DB2ULL, 0x90C3CD392C1E980EULL, 
            0x3E86CE940AC72934ULL, 0x9E57CB3626A71671ULL, 0x9DAC0C6476D24487ULL, 0xB72258822B5A9030ULL, 
            0xFB35A20FADD77394ULL, 0x5884D1784DBA05BFULL, 0x1E90B6273C3CA42EULL, 0x17DEC555176C10DFULL, 
            0xB8A8A620149A3B6AULL, 0xC91C83F55C60ACE7ULL, 0xB92C3BF0B1B675F0ULL, 0x558FBCE6129CEF0CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseHConstants = {
    0x66B8E1810D1377CAULL,
    0xA378AEFAC8F02B38ULL,
    0xFC6C20ED2D58FDFEULL,
    0x66B8E1810D1377CAULL,
    0xA378AEFAC8F02B38ULL,
    0xFC6C20ED2D58FDFEULL,
    0x4F4316C317A31EDBULL,
    0xD329C2B751100975ULL,
    0x32,
    0x21,
    0x0B,
    0x14,
    0x7F,
    0xA6,
    0x5B,
    0x66
};

