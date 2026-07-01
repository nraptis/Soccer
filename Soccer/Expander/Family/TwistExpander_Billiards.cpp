#include "TwistExpander_Billiards.hpp"
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

TwistExpander_Billiards::TwistExpander_Billiards()
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

void TwistExpander_Billiards::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x86CE39F9B472C97EULL; std::uint64_t aIngress = 0xDAACC248ED7F749AULL; std::uint64_t aCarry = 0xC563323EAE83154AULL;

    std::uint64_t aWandererA = 0xFE17ACC7846BE146ULL; std::uint64_t aWandererB = 0x9E143A1030899220ULL; std::uint64_t aWandererC = 0xE6D3E0C61D6BC364ULL; std::uint64_t aWandererD = 0xB765AC393B75CBE7ULL;
    std::uint64_t aWandererE = 0x8B1AA774CA63A3D1ULL; std::uint64_t aWandererF = 0xDF5ACDEF836271BAULL; std::uint64_t aWandererG = 0x8B544D78A464C235ULL; std::uint64_t aWandererH = 0x9029570083F5F76FULL;
    std::uint64_t aWandererI = 0xC6508CF8982F88E0ULL; std::uint64_t aWandererJ = 0x99D49C102E402880ULL; std::uint64_t aWandererK = 0xC063B25EEAFC6331ULL;

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
        aPrevious = 14045093183626799814U;
        aCarry = 12502215923058513820U;
        aWandererA = 16573354779388482771U;
        aWandererB = 11435816036197140675U;
        aWandererC = 16376711485654329390U;
        aWandererD = 11043394675185131069U;
        aWandererE = 9516468038356600963U;
        aWandererF = 16306696857090369632U;
        aWandererG = 15892969768357443671U;
        aWandererH = 15461546357221141153U;
        aWandererI = 13277656593218150621U;
        aWandererJ = 15634112196388876530U;
        aWandererK = 16877761427556485726U;
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
    TwistExpander_Billiards_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Billiards::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x878C6157041C8B7FULL; std::uint64_t aIngress = 0xB12E2A3543BF3DDAULL; std::uint64_t aCarry = 0x9E36B2C7E7B2499EULL;

    std::uint64_t aWandererA = 0xBEC352B1D32026C8ULL; std::uint64_t aWandererB = 0x8C75B5B71662882EULL; std::uint64_t aWandererC = 0xB6CB28BA517AA09FULL; std::uint64_t aWandererD = 0xCCEAA022EAB00261ULL;
    std::uint64_t aWandererE = 0xA35F038867628632ULL; std::uint64_t aWandererF = 0xACFA96AC6C6B4C47ULL; std::uint64_t aWandererG = 0xAFF7F5C0B2105961ULL; std::uint64_t aWandererH = 0x8D5064A3D48FB645ULL;
    std::uint64_t aWandererI = 0xD7B432EAC982D3BFULL; std::uint64_t aWandererJ = 0xB19272571AAC4056ULL; std::uint64_t aWandererK = 0x92907618CBCD611FULL;

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
        aPrevious = 12702924693490141483U;
        aCarry = 11159599790189213554U;
        aWandererA = 12357778079147257386U;
        aWandererB = 12847485544321179950U;
        aWandererC = 17592428685170525663U;
        aWandererD = 13059277343336776555U;
        aWandererE = 16713434555087706217U;
        aWandererF = 14754582837367204731U;
        aWandererG = 10219261470924894783U;
        aWandererH = 12159817074617124417U;
        aWandererI = 17732180417801352747U;
        aWandererJ = 11640924387078302529U;
        aWandererK = 12399894414533538763U;
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
    TwistExpander_Billiards_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Billiards::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD6B2C503D01EE0D7ULL;
    std::uint64_t aIngress = 0xF72AEF2908F913CDULL;
    std::uint64_t aCarry = 0x981AD767ACD45230ULL;

    std::uint64_t aWandererA = 0xDBD18E871733D3F9ULL;
    std::uint64_t aWandererB = 0xFAC141642B23ADDEULL;
    std::uint64_t aWandererC = 0x9C305BB2094529C7ULL;
    std::uint64_t aWandererD = 0xDCB94C2F63804D3AULL;
    std::uint64_t aWandererE = 0x8B61424A9931A889ULL;
    std::uint64_t aWandererF = 0xC285CE28E8986B45ULL;
    std::uint64_t aWandererG = 0xC95D49294A55F3C1ULL;
    std::uint64_t aWandererH = 0xDE7B859379349D00ULL;
    std::uint64_t aWandererI = 0xE557C629BBEA5F25ULL;
    std::uint64_t aWandererJ = 0x86888672F2ACE94BULL;
    std::uint64_t aWandererK = 0xE2F60B4CCCDDC29DULL;

    // [seed]
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneA);
        TwistSnow::Sha256Counter(aSource, aSnowLaneB);
        TwistSnow::Aria256Counter(aSource, aSnowLaneC);
        TwistSnow::AES256Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    TwistExpander_Billiards_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Billiards_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Billiards_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Billiards::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Billiards::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF2D3DDF30238E4F4ULL; std::uint64_t aIngress = 0xA5D4BB9D81FACCBFULL; std::uint64_t aCarry = 0x9703D7F1B167D330ULL;

    std::uint64_t aWandererA = 0xF212B4755C7D22D6ULL; std::uint64_t aWandererB = 0x88DC94803B76DA34ULL; std::uint64_t aWandererC = 0xD69BBBD16CD915C5ULL; std::uint64_t aWandererD = 0xF4BCA014ECBE6CC6ULL;
    std::uint64_t aWandererE = 0x994AA37BA4FB36A3ULL; std::uint64_t aWandererF = 0xDFEA67384FA4D449ULL; std::uint64_t aWandererG = 0xD6795A3AAB86259AULL; std::uint64_t aWandererH = 0xE873B710D7AEFB9DULL;
    std::uint64_t aWandererI = 0xC0646B29A4FD5DC3ULL; std::uint64_t aWandererJ = 0x8AA521294061EFC8ULL; std::uint64_t aWandererK = 0xA299D2FD282E5A11ULL;

    // [seed]
    {
        aPrevious = 9881771127745462647U;
        aCarry = 10837189216472714955U;
        aWandererA = 16215845432476724136U;
        aWandererB = 15705856480148722103U;
        aWandererC = 15162627928354671392U;
        aWandererD = 11571984190213687027U;
        aWandererE = 12940813661478730176U;
        aWandererF = 9900544141522390115U;
        aWandererG = 14497936197877387486U;
        aWandererH = 13722393259032252077U;
        aWandererI = 16735118547468251795U;
        aWandererJ = 12447216675399873404U;
        aWandererK = 14816630977448436536U;
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
    TwistExpander_Billiards_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Billiards_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Billiards_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Billiards::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 1, 0, 0 with offsets 5645U, 1521U, 7646U, 3422U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5645U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1521U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7646U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3422U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 1, 3 with offsets 2021U, 5304U, 5964U, 2060U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2021U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5304U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5964U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2060U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 2, 3, 1 with offsets 3598U, 3794U, 2157U, 7789U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3598U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3794U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2157U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 3, 2, 2 with offsets 7963U, 7594U, 2361U, 1740U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7963U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7594U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2361U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1740U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 0, 2, 3 with offsets 707U, 1639U, 1011U, 1740U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 707U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1639U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1011U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1740U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 1, 3, 2, 0 with offsets 1337U, 389U, 1785U, 725U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1337U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 389U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1785U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 725U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 0, 2, 3, 1 with offsets 1665U, 978U, 2011U, 1928U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1665U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 978U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2011U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1928U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 3, 2, 1, 0 with offsets 827U, 457U, 1316U, 1810U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 827U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 457U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1316U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1810U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 382U, 226U, 1234U, 722U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 382U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 226U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1234U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 722U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Billiards::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 1 with offsets 4358U, 3190U, 6689U, 7474U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4358U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3190U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6689U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7474U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 2 with offsets 4484U, 2603U, 6058U, 7478U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4484U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2603U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6058U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7478U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 3 with offsets 331U, 1333U, 610U, 7443U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 331U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1333U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7443U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 0 with offsets 3342U, 6171U, 4350U, 3350U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3342U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6171U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4350U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3350U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 3624U, 1973U, 4955U, 2321U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3624U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 1973U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 4955U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 2321U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1067U, 1012U, 355U, 993U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1067U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1012U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 355U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1053U, 1089U, 1647U, 223U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1053U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1089U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1647U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 223U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1747U, 545U, 487U, 1451U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1747U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 545U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 487U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1451U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1933U, 1124U, 1485U, 1144U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1933U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1124U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1485U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1144U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 2, 3, 0, 1 [0..<W_KEY]
        // offsets: 1142U, 1354U, 1072U, 1506U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1142U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1072U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1506U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseASalts = {
    {
        {
            0xCAEACC05F165090EULL, 0x56C2DD967392C814ULL, 0xFC513D7FD9473657ULL, 0x2C9281CA47B776FCULL, 
            0x32C48525F6BC76B7ULL, 0xCCF360BA43707FB7ULL, 0xBEB9A35E4441DAE3ULL, 0x2F94D3D3AE34E5F7ULL, 
            0x58F63D638CB0D7C4ULL, 0x89264D22CE3A3574ULL, 0x68F88486484D3E0CULL, 0x2F5FD30CDCEB4C23ULL, 
            0xB299DABD36219DA1ULL, 0x54AEADC60D449BB5ULL, 0x93A03C4E7A69ECE7ULL, 0x689FE2A9316389ECULL, 
            0x2EFB825E1F5752DDULL, 0xB202200DF73B050BULL, 0x555A9E4F666DFFEBULL, 0x093D146AF3D1DB61ULL, 
            0xE6676F40172F616FULL, 0xCDEA529C507ABF6EULL, 0x68B8625AFE3ED434ULL, 0x9FF46E735E6C6F15ULL, 
            0x51DCD2B9CF618687ULL, 0xC162074BC4AB3884ULL, 0x1B5FF2B844AFC332ULL, 0xBAD55F784B65A70AULL, 
            0xF1AD914EFC8AC250ULL, 0x4745D2E97B3A31B0ULL, 0xB06ED4933E96388DULL, 0xEABA7A5F2723CD7EULL
        },
        {
            0x836D85E1C00ED201ULL, 0xB533D694ECE832FBULL, 0x366EDF681208C242ULL, 0xC1D360D7F2BEA930ULL, 
            0x95D3912A60901E15ULL, 0xE209759C6B9E14CFULL, 0xF66697390758E530ULL, 0x05B5ACDA4A542BB2ULL, 
            0x824ECCB85346EF0DULL, 0x5D42350BA5F2EBB7ULL, 0xC42112E731558CBEULL, 0xC6A3B25C909B4649ULL, 
            0x1C4DF6C651BC679AULL, 0xF72D42A5F02AE601ULL, 0xA05AE4716748BA1DULL, 0xD817548D02F8D89FULL, 
            0x9CA7217FE82D3D55ULL, 0x77A00A46C3355A52ULL, 0x32881A6077F75C33ULL, 0x7DB82342F9E7FBF4ULL, 
            0x6542FAC2EF961719ULL, 0xB1DAD2126673840EULL, 0xDAB35A94DD0D52F6ULL, 0x8E0CFC5436E893DBULL, 
            0x3BC2E852008ACE3CULL, 0x5DEFA99F0E56B79AULL, 0x9C491AED5B087F41ULL, 0x9D9948FA3BB25B8BULL, 
            0xFB97D00161682EEAULL, 0xC2168FAEA8FFC7D0ULL, 0x68B2F7BC145FC143ULL, 0xDD0AC34ED18DF4DAULL
        },
        {
            0x7ADFD27CEF2F00C2ULL, 0xCB97B852C48E587DULL, 0xDA070E1D8BE64112ULL, 0x1BACBFAF9C866329ULL, 
            0x93F4841827102D3AULL, 0x23F3FE6650780225ULL, 0x9C6890864D8291FFULL, 0xADEF23134EA4D310ULL, 
            0x7A436DBB35F3E528ULL, 0x1BD80DF3D2627B09ULL, 0x7CDE42B7F65B90C4ULL, 0x7667D8E488BEE6C6ULL, 
            0x751AEA8D828EEF14ULL, 0x15B890384B87859DULL, 0x2DBCE8DC0696719AULL, 0xE8D57AAEE4A19E82ULL, 
            0xFE9CF2353B7C995DULL, 0x6EACD77AFE2CDCD8ULL, 0x0213D42536336A1CULL, 0xF37210365D59B42AULL, 
            0x41460565CD41132FULL, 0x7199455D3656D8E2ULL, 0x8AFEFF6526AF2223ULL, 0x59A1E020986EE104ULL, 
            0xF336130B47242D1FULL, 0xFBFC13A754AFCD73ULL, 0xCBC33913778E1237ULL, 0x808AE0C73468B784ULL, 
            0x27C41448BB51E47FULL, 0x1AA7DA1B60BFF08FULL, 0x0812194A94AE4E5AULL, 0x897B3E1519244521ULL
        },
        {
            0x6BEDD259B2994B14ULL, 0x37E3AC36EFA1ECD4ULL, 0x22B02754BF3C6408ULL, 0x1FCC44152C35158BULL, 
            0x5B2610264D0E34A5ULL, 0x697FC7B460708CE5ULL, 0xE03DB16C037E008DULL, 0x04CB30581108B1FAULL, 
            0x294BD7BDD6A5327CULL, 0xCA37D7316BC88413ULL, 0xED70E4C7C94D00FCULL, 0xFC725A421ED59A11ULL, 
            0x4C13B6B5DDB00DABULL, 0xCE9FC71B163A075FULL, 0x0C4946C322754910ULL, 0xD329E013C63D0FF8ULL, 
            0xF7BAAEC90224781EULL, 0x661C4EF2AA804143ULL, 0xACF7462194A5F5F4ULL, 0xBBD90ADAD911FA53ULL, 
            0x6E10DBE135D7E714ULL, 0x8FF6BF3963FADBFDULL, 0x4A00EE11C9D496B0ULL, 0xC4388166115CC7BDULL, 
            0x2E15A41B90DAE336ULL, 0x650C7A3B59155FD6ULL, 0x8A8E1386182277E1ULL, 0x117F9577CC9839B4ULL, 
            0x1C6A351DE9C63851ULL, 0x690C340452D9D1B3ULL, 0xC660DA2B1A113FEEULL, 0xF84CBBE42404CDCAULL
        },
        {
            0x1D45BB707DC743FEULL, 0x297BB34A588C1B18ULL, 0xC775320DC50F0E45ULL, 0xB01A86CD0A942C22ULL, 
            0xB7AB9CDDDE48035CULL, 0xBCF0BE66D440551FULL, 0x1A262C37FFE14B70ULL, 0xCC59AE0385EBB573ULL, 
            0xA3CB56158C67A0CAULL, 0x4CD329BB77E379F3ULL, 0xAD6446CE43B91AFCULL, 0xC7EA5C85EF06CB62ULL, 
            0x407A1DD1655F508EULL, 0x9FD068D6C5E9BA7DULL, 0x75B7FC5F0B5C5A03ULL, 0xFD7683014051B213ULL, 
            0x6629F343D3E1AA09ULL, 0x0D20FD9F0C16B8DAULL, 0xA0ED232386B41CA0ULL, 0x9D55796F44F2CA60ULL, 
            0x9FE6B20572DAD72AULL, 0x85C4CE3C4E11445EULL, 0xC3AFA936147C4EA7ULL, 0xB25DD284140C98D4ULL, 
            0x6580D022B16A6256ULL, 0x44CAF2140A1AB185ULL, 0xC73075CA62203894ULL, 0xB18575A808E8B413ULL, 
            0x7A2E1DF2A1926C37ULL, 0x3213C4AFF7DC02EBULL, 0x3A5E44F3AFDA96CEULL, 0x124DD59513B4E702ULL
        },
        {
            0xE9B3B0FA5387DDB0ULL, 0x3E9C6AAA1260C2F9ULL, 0xD4B4B7B965ED55A1ULL, 0xE80EF43456FF3A4FULL, 
            0x8179CB5FAD745F29ULL, 0xEC025CDCC0F110A6ULL, 0x09256F7DA07E0B68ULL, 0x5F7E16B8B1656AA8ULL, 
            0xB5FD677E910233DCULL, 0x6532ECBE9E132A8BULL, 0x1E2BBE0CCD608D42ULL, 0x448053259342F86EULL, 
            0x2983B059DF821B35ULL, 0x831D80BDE5A5990DULL, 0x17538ECFDD629F1AULL, 0xE5584D870661D8B4ULL, 
            0x15C06184F2F48033ULL, 0xC0C055DA91E80662ULL, 0x7E6FAFAA9D9D7978ULL, 0x20F9C0809CFD8587ULL, 
            0xB5ADDF2FB5BC2FD7ULL, 0x042AEE743018EDFAULL, 0xFB29D3147F5CE5BAULL, 0x63198D56918ACA66ULL, 
            0x74BB038F1E16A84BULL, 0x0F104B471E6EAE4AULL, 0x1F9AA29BAE2BF29DULL, 0x0F67E9BD479FF88CULL, 
            0x005E334C2B2D206EULL, 0xF67C4E957495B353ULL, 0xB584A9834F47AE94ULL, 0x927ED922B0039190ULL
        }
    },
    {
        {
            0xAC9B0F9D9990C5ECULL, 0xF58E697E7E5B6A2DULL, 0x8D2F3D75FE4F993CULL, 0x8664271421FD1B3FULL, 
            0x82AEA054EF1A9B5AULL, 0xC7341F079EBB41F7ULL, 0xF5D78F3962D66BC4ULL, 0xC46D4F7B6D8516B5ULL, 
            0x9200657BDB7E5B92ULL, 0x221E6DD0161C80E5ULL, 0x1992B552981BDB81ULL, 0x48EB8BD658586D53ULL, 
            0xC43434FD06BA84DCULL, 0x3835EFAB7D9AB7B1ULL, 0x8473BF401530FEC7ULL, 0x9BCD962038AAFFF4ULL, 
            0x62202648274729F3ULL, 0x6D862E1260EF7B91ULL, 0x453BE1BDEB77CE8CULL, 0xB749A7A0A6BE3C09ULL, 
            0x24892488CE214F47ULL, 0x5BC44B46FF3516E5ULL, 0x4FD4A8271433A77BULL, 0x745F0AB341B26AE2ULL, 
            0x1238DEC1726295A7ULL, 0x455BA16E281A8544ULL, 0x94F64E16A82CF193ULL, 0xA3553AE6533653FEULL, 
            0x28F9DC7E36ECCFE4ULL, 0x70FC34B83F7A0B69ULL, 0x9EF226628FCDBAC1ULL, 0xF10A82132F836A27ULL
        },
        {
            0x2FBF6BD06B0C35E9ULL, 0xF33DF96FAE640B97ULL, 0xBEDBDC029000B571ULL, 0xFB1165C89CDF766FULL, 
            0x87D83A507ECF4CA4ULL, 0x4E81F0746883E574ULL, 0x90F2713AF8E7E449ULL, 0x4A55397CDB439923ULL, 
            0xD4DB66DA1FBDC4BDULL, 0x4E26E8A245346658ULL, 0xF17B3F4DD3DC1753ULL, 0x30FC88FAC77A9487ULL, 
            0x0D5F12800361BB40ULL, 0x3F65919B61002DDFULL, 0xC592E0D74E6C1286ULL, 0x0290FE4F07A1082AULL, 
            0xC22640CEC33DEBAAULL, 0xE17FD562F83633E1ULL, 0x35359EE9EB78BF17ULL, 0xE9850BD63E65E21EULL, 
            0x8FAEA1042A315037ULL, 0x4BA6C6993597520EULL, 0x858EAA916C6AB521ULL, 0x05F7F9BB42F86FF0ULL, 
            0x04B6794445530B0CULL, 0xABC069518A32E183ULL, 0xD521485ED49CE14DULL, 0xD16B293D780F3988ULL, 
            0x83CF70AA082097A2ULL, 0x6D5909713B4CB556ULL, 0xB33CF40E478E27D7ULL, 0x5C2BAE6D685847FBULL
        },
        {
            0x481D700E3246902CULL, 0xD4003D4CE2F3B6C9ULL, 0x94D6BB83E04B940CULL, 0x4A8E4FD1C2F6BA84ULL, 
            0xED3E298E87ADE3F0ULL, 0x53544D6D06441955ULL, 0x846DB2D124054DA2ULL, 0xE366C526C48538D7ULL, 
            0x2967F948B85DC461ULL, 0xF56C3F7DB7C42D2EULL, 0x366841D4671EA6CAULL, 0x36B86301767A7133ULL, 
            0x0E82AAF07931951FULL, 0xD65E360BD5AB08BFULL, 0x28FC314262DA7165ULL, 0xDD8BF542C6304BA4ULL, 
            0x8DA936D6079AE39AULL, 0xFBC19A5446AC0D0EULL, 0x4B389947E612FAD8ULL, 0x94D278DE31A0CF6CULL, 
            0xABF42301D974DD97ULL, 0x3191AE04032C6F10ULL, 0x42782B1D4DD3BAFEULL, 0xCD113FA1B2539024ULL, 
            0xBF7F300A7A7C21A2ULL, 0x2F8850B98FF2550CULL, 0x560BE97D9DB8E6CCULL, 0xC42E25988FD0568DULL, 
            0x67AC9B1285C3532DULL, 0xED2EAA89820583EFULL, 0x281E9BDFE77B02C1ULL, 0x66FA2E202C683A56ULL
        },
        {
            0x5F30143C466B29FEULL, 0x8961FC1BA9A4B7ECULL, 0x80D61BCAC7BD03DFULL, 0xEC4D61D90917158FULL, 
            0x3E44B169767EFC0FULL, 0x517083872A2CFB60ULL, 0xFF107331F85E4037ULL, 0xCFCA952C2CFD5E06ULL, 
            0x777C370AF9936CB6ULL, 0x7F01C9F62EF588BDULL, 0x3F1943AA1D9EC059ULL, 0x73AEC7757704D59CULL, 
            0xD0C1223AC9D9F61CULL, 0x2FF906F3EB931E2CULL, 0x780F6A5D701A899BULL, 0x52245A3328BB04A5ULL, 
            0x6D460400124C91BEULL, 0x0BBE28E8534B41C4ULL, 0x6EC3DDEAD226BB1CULL, 0xD3409B8B36AF1439ULL, 
            0xC22BA4F23D6A25C1ULL, 0x16CAEC7FE1D117EEULL, 0xE46A1A946C1460D0ULL, 0x214FE27F0C74AB90ULL, 
            0xA4BC7A203F6B845DULL, 0xA82C38D33578A258ULL, 0x2FDCD745B0CEA600ULL, 0xD8B65A6D378F4F6AULL, 
            0x0C3BE5636DC23E85ULL, 0xF68C5890AED80567ULL, 0x9F4B880B8BF14C14ULL, 0x27ACFA5F151E587EULL
        },
        {
            0x6323358FCB8DD0FCULL, 0xB843CB1868402725ULL, 0x69447EB0A54C0E99ULL, 0x6E618AFD291FEB63ULL, 
            0xB6807ECA3B7C41F9ULL, 0x38BFB95329733D82ULL, 0xC246AB39943E07E9ULL, 0x3F4BF13040FEA391ULL, 
            0x25EF6E36D0645AC2ULL, 0x3A61A42E35E39A0DULL, 0xB40546302AAB65DFULL, 0x74BCA794D107D122ULL, 
            0x871FC22464D48E26ULL, 0x106A4C88AC27BB94ULL, 0x4C5603BD962D0865ULL, 0xA1789A08F31AFCD8ULL, 
            0x7E9B52480D5A9EA0ULL, 0x6A50AC841CFC6A0FULL, 0x08235ACC648337E8ULL, 0xB00541DE15BC0FA2ULL, 
            0x28EA2AB225CA6359ULL, 0x64E10E3079196E9DULL, 0x0C3264F8A8B32B2BULL, 0xA9B18FBD1283186BULL, 
            0xABA167D789A33EB9ULL, 0xA7F34EFC0D7125DAULL, 0xF1EE0CD848B50766ULL, 0x04700EDD2A3DC408ULL, 
            0x8EDC3447D76FB0B8ULL, 0x677E44D51A5B67D8ULL, 0xBEF81F1F6F7BDDFDULL, 0x922F36E2CE86FD58ULL
        },
        {
            0x24FB7CCA9B8BF001ULL, 0x706A5135265DAC7EULL, 0xCD4459F0A710D43EULL, 0x55871747E758023AULL, 
            0x0DD3A636738B6986ULL, 0x4A35A409AE9A6A79ULL, 0x746FFF527DF72274ULL, 0x3ADA13FE641C7B45ULL, 
            0xABE7D4BE6430C1C1ULL, 0x84B5DAF49E3F8D4FULL, 0xA297620402F27655ULL, 0xF9810854F1F3382DULL, 
            0xC2D0102D0511EE35ULL, 0x4B21FAF167C9AD37ULL, 0xBDA2C4F51B6E6A6FULL, 0x655F4386B08E39A4ULL, 
            0x4762933F20498809ULL, 0xA27309134E4EABC3ULL, 0xFDDACF90B34B9C5DULL, 0xEBC6AB3096B25171ULL, 
            0xB7A0007DB9FFBD55ULL, 0xA46D1236173E5B0FULL, 0x3CAE5F2E87007021ULL, 0x6DC2B4A596519E2EULL, 
            0xD9C195FC46E5FB60ULL, 0xF894644580068E14ULL, 0xE122CAEA9518698EULL, 0x5422800D2B43A4DBULL, 
            0xF14CF62C0253C5CFULL, 0xF7684DDBFD33B760ULL, 0xAC757CED7DB9AB0CULL, 0xDB556D9C576D53C8ULL
        }
    },
    {
        {
            0xC9C0F1049E92360BULL, 0x976F9265DBD80A8FULL, 0x19E77558F38A2348ULL, 0x9B48338F3D0A3FF9ULL, 
            0x6B17B1FF393FEB5AULL, 0x33D8FBC9312EA633ULL, 0x7C7663D2306B8295ULL, 0xA443E56ECCABFD1BULL, 
            0x2F26BB7ADB4BC252ULL, 0xDFDCB973C3E74F92ULL, 0xFC5ED05E3966A4F6ULL, 0xB0C32525F7A870F0ULL, 
            0x6BBA5448B49547D9ULL, 0xDA9C935A1D1CBAA7ULL, 0x90E9981D7058310BULL, 0xF5556D85F6A39C2DULL, 
            0xACB882E0C97AD458ULL, 0xA3CFFE1778AA1A6AULL, 0x7091F41966B6B5A2ULL, 0xC37193B0E2224523ULL, 
            0xD5EFC212BD46C655ULL, 0x1F4F92DA63E08612ULL, 0xA469023398CE867BULL, 0x8E5218F9E6B1ECE8ULL, 
            0x3111F311BA7D387DULL, 0xAFD74F5E30EAF594ULL, 0x1125025A739908B8ULL, 0x098C1EB514D688A8ULL, 
            0xD8EAF30FF8C5BB4DULL, 0x7B6B7DCEC65BEE3EULL, 0x051B8B9A62F5440EULL, 0xF6067F770D911966ULL
        },
        {
            0x77E8A9C2A2A4AF9AULL, 0x4DEB909C6EC0E64BULL, 0x96483C91E8C38087ULL, 0xDD04C6F0026D410AULL, 
            0x3A9525B9B77AF607ULL, 0xD352B5EC1683A46BULL, 0xE536D74F8DA2F174ULL, 0xCFF6407671C243C8ULL, 
            0xBF5556551452E18BULL, 0x643AEDD71922D1B1ULL, 0x6FBF39754D1BE3A0ULL, 0x90E175AD241D14CDULL, 
            0x70DF399F690C4278ULL, 0xF025C61D12D7C91EULL, 0xE64E71F48BC9FC85ULL, 0x9526FB47242DAE5BULL, 
            0x22B282591CB75F0AULL, 0xD2CE10FC4D1ED722ULL, 0x96BEEAC7B6AAA898ULL, 0x6E15FB2AAB19EC2FULL, 
            0xCD680C3D2EA92E50ULL, 0xA186C4271D43BAC4ULL, 0x13EA04B13E5D52A9ULL, 0x8593A9A26C9BE5F6ULL, 
            0x3250991809CCCFBCULL, 0x37AF1EE68D202B71ULL, 0x8A9F08B137E7C47DULL, 0x6AF8D85454C4A64DULL, 
            0x90DC38B6142B333EULL, 0xD5CA2C9587E07695ULL, 0x1B3575ED6D843034ULL, 0xD707333A6AE2ECFBULL
        },
        {
            0x005F314F1F0D23DBULL, 0x6C9B97073270D5B6ULL, 0x99B23AF105A8263AULL, 0x73525C658C4FCE01ULL, 
            0x0B29AC3395F0FD4DULL, 0xEDC3D47DFDE42081ULL, 0x820ADB3990991D16ULL, 0xD53B39783260C3F3ULL, 
            0xE568FDA877387AD6ULL, 0x7124C09B1552DC98ULL, 0x2AA3AFAAAE8A9C18ULL, 0xF6A7D7523AC5AF01ULL, 
            0x0A9347A2A94076C8ULL, 0x00966F486E8EFF9CULL, 0x49F04E6858911D1FULL, 0xD2F05F2269220F21ULL, 
            0xC5F932F464D98452ULL, 0x2BEF769C69E1C8D4ULL, 0xC432C5AF1FAFA77EULL, 0x6AA6AE592D58AF91ULL, 
            0x005C332B2C918636ULL, 0x2BD6CB100630CFE3ULL, 0xB6542D8A99ACF298ULL, 0x73477E3D7DCDE946ULL, 
            0x4CD7AD276EEE6B75ULL, 0x2930241CF054A74EULL, 0x1EAE1D8CC3928301ULL, 0xECA0D330BD78F395ULL, 
            0x326A4D02446692B0ULL, 0x3D74BDDD7FBBF255ULL, 0x00731ACA1711505CULL, 0xD74827899D9E4A83ULL
        },
        {
            0x8916FEA0910A6D30ULL, 0x6E70B4ACD3519348ULL, 0xC2348A85E1DACA87ULL, 0xE986C2BE63E157C9ULL, 
            0x5058FAE971510A10ULL, 0x8C207D5A7A2CA993ULL, 0xEE04A13475D6BBBEULL, 0x8D17A40BBC7E7233ULL, 
            0x54920E4FD06F356AULL, 0x8FF10E92B740AF45ULL, 0xBF8B26F81A1B3750ULL, 0x5CDD9240256881DAULL, 
            0x8CBB2BF911599CBAULL, 0x10CB6C458A6C29C5ULL, 0x6529D0B9D54AAD07ULL, 0xF3B93E49227B787AULL, 
            0x063E7705BB009472ULL, 0xA069E7423A14B49BULL, 0x4C6EA0CEB24C86E1ULL, 0xD6329A8570A1F448ULL, 
            0xE5367AF8CBBF4247ULL, 0xC4BEA1994A653BBEULL, 0xBE87D127D123C41AULL, 0x62F979886D90F336ULL, 
            0x9E9B5E7E33EDCE8AULL, 0xD373F797C887C2A8ULL, 0x568946250718DAC4ULL, 0x61F9F1EC27245EADULL, 
            0xFE18830A9C55DCA5ULL, 0xA19281B6DA413F86ULL, 0xE03CE9D59FEF7228ULL, 0x1F8BCE4D94D61C76ULL
        },
        {
            0x57F2A367F49DE1EAULL, 0x211989A0D0431528ULL, 0x6EF96019921629D8ULL, 0x5371F087F3F1FE78ULL, 
            0xD17C03EF22FA7164ULL, 0xB2F1B9D7E2BA3F96ULL, 0x1484A286B02DC7D0ULL, 0xD130A16B60FFE805ULL, 
            0x5E4A02635BC8ADD9ULL, 0xCE0BE7177B51423AULL, 0xFB75DE498B321045ULL, 0x1CA1819578BB846EULL, 
            0xB332D832486B9AD1ULL, 0x50B089810FEFB9CDULL, 0xF24E436DCDEC8762ULL, 0x5990D47431C1C0EAULL, 
            0x2A96ADD17E1155F1ULL, 0x73C1E408A9E9886AULL, 0xA3E3C126AA07ADD0ULL, 0xF831C4C5DFD150A0ULL, 
            0x07D8F077BF94C05FULL, 0x0358DF240434774FULL, 0x91E1294CCE52C3F9ULL, 0x6D07F063659DDC92ULL, 
            0xA2B848AEF13C839EULL, 0xCA4420126D781EC6ULL, 0x4E9C7F7B79DD52EDULL, 0x15EE237153B41857ULL, 
            0x0FE0541C27FF37EEULL, 0x042BA8BCC54A4AC6ULL, 0x6D27489ECAB10FFBULL, 0x244509AA0EA9A50DULL
        },
        {
            0xA22F5914501061D3ULL, 0xB4EB6BE4825ECD3AULL, 0x7FEC1672E2175451ULL, 0x12F2912D11EF7762ULL, 
            0xC20856F169BAA245ULL, 0xFFFE56F560DB1CACULL, 0x1BCD43BCB87D45A0ULL, 0x7B73664416AF9E27ULL, 
            0x2348B92B070B1173ULL, 0xFED4FD0339B16A77ULL, 0x9F1B93256FE3DD9EULL, 0xD2CADFE655302B4EULL, 
            0xCD01047277D9CDABULL, 0x0771C9F8B636035FULL, 0xD6AA51F9C1D30CF7ULL, 0x6CC10BD6517D7C5CULL, 
            0xE02EABB74F86AB35ULL, 0xDA29D76CA5CEAD8BULL, 0x3337D12A87AF5F5AULL, 0x1DF19EAD782F6AF7ULL, 
            0x09093E74EBDC7E59ULL, 0xC6371E5027B2B9AFULL, 0xEA435DAE80DEA82DULL, 0xAE0A5032586B97CEULL, 
            0x1C8404AD58E322CBULL, 0xCF099C8A4ABA2217ULL, 0x4EA9F96650526A81ULL, 0x004B6515601F6B32ULL, 
            0x0C483B95FAC36B01ULL, 0xD3F1901E6948467AULL, 0x41E39E760E955430ULL, 0xE9D59CC606DFF286ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseAConstants = {
    0x006567DD41FCB4CAULL,
    0x31FB62CD321F3F2AULL,
    0x29D42F6D99F253B9ULL,
    0x006567DD41FCB4CAULL,
    0x31FB62CD321F3F2AULL,
    0x29D42F6D99F253B9ULL,
    0x1C0FE9BCF5A72241ULL,
    0xD18C8B96C6AE92FAULL,
    0x1C,
    0xFE,
    0xA3,
    0xE5,
    0x9D,
    0x1D,
    0x6D,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseBSalts = {
    {
        {
            0x72C92F05B1F16F19ULL, 0x33A9039C5D559CC5ULL, 0x90756F6ABAAB2069ULL, 0x1DBFC4B6076A0279ULL, 
            0xE995D40A6C1BCDAFULL, 0x1AAD391980607FA7ULL, 0x83A585BD356D6690ULL, 0xD9A9F1F48F43EF94ULL, 
            0x4FDBA5033B65DAEAULL, 0x1D8D87B4477800B5ULL, 0x94F02488DBEA3683ULL, 0x1C1C59ADD1F67D1BULL, 
            0x27A942AD5492075AULL, 0x07754387DA3F0E3CULL, 0x78AB23CE9058A1D0ULL, 0x7BDF6A94977AD023ULL, 
            0x3BC108D116C0600EULL, 0x48E69C1571CD4C58ULL, 0xF55EC6172C744015ULL, 0x80FF3F51046B69C7ULL, 
            0xF5E5740DA8BAE02EULL, 0xAFA18A415DF6D37DULL, 0x577C6091F0F7067DULL, 0x96C8D12FE880D44EULL, 
            0x88CDE383DA376F15ULL, 0x1E91CCCD1109C3FFULL, 0x4E5A36F6A8D591E8ULL, 0xAA9F7910DB6BE08CULL, 
            0x1AD73810DA3AEC18ULL, 0x85BE2510D7C26086ULL, 0xE04A063815A6A83EULL, 0x71530DCDA17832E0ULL
        },
        {
            0x62CB1B8F2037CD1DULL, 0xD83DBF0E6BD5768BULL, 0x7A59795075BE35C0ULL, 0x19405DB3EF12171CULL, 
            0xFD9567DA207A3F1DULL, 0xBBC4BABB739AEEA2ULL, 0x6A5CD5332F4C55E5ULL, 0x8A3EC634AB29AF76ULL, 
            0xD597581BF88FA91CULL, 0xB9E1145D804FDEAFULL, 0x05CD57850EA654FDULL, 0x255C000D71FB9BADULL, 
            0xEFB5C591C3BC3915ULL, 0xFAD70DF962139CC6ULL, 0xE0F4683126A18415ULL, 0x5245616A6DF010BCULL, 
            0x496C183B4E790853ULL, 0x2960EE5C47E2AA15ULL, 0xEACAE0A109470F34ULL, 0x6BA8BFAB022FF362ULL, 
            0x1D3E060A148EBDD1ULL, 0x3716848F772D6925ULL, 0x81262D76189D0B0DULL, 0xA512581CD90F5FAAULL, 
            0x0E145C7ACA1E3792ULL, 0xC9484F2B1C0DDAB7ULL, 0x925116A5F580F0AAULL, 0xE6512145C2A29879ULL, 
            0x996B26678CE7A1BBULL, 0xA2612430D3DA796BULL, 0x7D1F80AE6A2ACEBBULL, 0x34CCC2C16CDA2D39ULL
        },
        {
            0x655FDC0A5F165C12ULL, 0x99756D7769ECFAC0ULL, 0x1E558042DFF2ED1DULL, 0x5BECE3395E973E59ULL, 
            0x7EA7AEBC4B0D2E8CULL, 0x974A772B32878561ULL, 0x715DC730BD3CBBB4ULL, 0x5278F7F029BBBF2BULL, 
            0x959BA5F71DC6415AULL, 0xA7234DD432B67297ULL, 0xF49077D5AF2BC46CULL, 0x04BDD656D0D4567BULL, 
            0xAA7798963DEA5861ULL, 0xA2169A0581522EDAULL, 0x5CDE9B1F53A6276AULL, 0x65808589249C28A1ULL, 
            0x90D88FC48F503A1DULL, 0xC8B13E71AD0F8503ULL, 0x3F70EE730C38BCB7ULL, 0x2ECCB576432C5EADULL, 
            0xEDE1A621559D0B09ULL, 0x0F264B9E12C2B310ULL, 0x6FAE7B4B118DF589ULL, 0x1F38BE973D8935C7ULL, 
            0xA30786B81A374C34ULL, 0x75A6A32675FDE968ULL, 0xD39EA2A5B0783FB3ULL, 0xBF5860B4710AD419ULL, 
            0xD0D6D6F53C7C0698ULL, 0x44D3776601357F12ULL, 0xB6EF38511AE644E0ULL, 0xADEA62CB1E0A2A97ULL
        },
        {
            0xE0EEBC6DA13CE5ABULL, 0x8FD586BD625FBDFCULL, 0xCE9C48AEA05F8818ULL, 0xB85204616D1ED223ULL, 
            0xA65C5A18BA187D70ULL, 0x5BA4F48D1E26B922ULL, 0x26F0BD1A22073F70ULL, 0xA0928DA9AA616010ULL, 
            0x4FF2D7B23DAD374CULL, 0xCA99B0CCBB98DDC6ULL, 0xDC0A1058B7C4A268ULL, 0xAB288A337374D37EULL, 
            0xFFA0BC7B5CE53D57ULL, 0x3C66327E094DB777ULL, 0x04C787940131715CULL, 0x406F980E58F300A3ULL, 
            0xBC440FABAAF2A690ULL, 0xE79EB45ED397B12FULL, 0x7330AD65385B436BULL, 0x2E39C2E3894B717CULL, 
            0x425276FA5E0CD5BBULL, 0xD77C66059CE4701DULL, 0xF116671CB4F2CC42ULL, 0x818705AA1FA30BCAULL, 
            0xFCCDB2765F5BE332ULL, 0xECDC893C018DCFA7ULL, 0x415F093E4D85A5A0ULL, 0xC58E8DCD81BE52F2ULL, 
            0x4A81F387029493FFULL, 0x37E90BCE5785C9B7ULL, 0x219EC9C6F896BD59ULL, 0xB764966EBA916362ULL
        },
        {
            0xDD5F17148EF18B12ULL, 0x3FA9C7E4E05210CFULL, 0x228C7F80D277EF8FULL, 0x983C36A7B99ED75FULL, 
            0x157C6EDAB7D5AB90ULL, 0x4D071747CE5B821FULL, 0x591A35C1D6166A1AULL, 0xA8372604A8B270B6ULL, 
            0xE453D064ABA4B5C7ULL, 0x24F48C8DB560BD9CULL, 0xA397AB1E09A9582DULL, 0xED485642F0A9860EULL, 
            0x1FB361848ED79C44ULL, 0x441B59D3E251C515ULL, 0x2E2EB5673407C5C0ULL, 0x69B30F2248C2C099ULL, 
            0x7F3F1DB379F31A40ULL, 0x4950C91C809E69C3ULL, 0x2CE1E3C660BA40C2ULL, 0xCB14297C41F80E1CULL, 
            0x034A0991FCA239DCULL, 0x614A07A05E9EF4C1ULL, 0x81DB8CC345B6A4D3ULL, 0x7AA5E5A3DF643776ULL, 
            0x0DF043E377969614ULL, 0x3FAFF142DEB247F1ULL, 0xEC0CCAC1A32408B1ULL, 0xE31F7945CE0EC2F6ULL, 
            0x5297307B216ED884ULL, 0xDF1D6FB241BC572BULL, 0x31716D0C00CBDB3AULL, 0xD8405A58A4DB35ADULL
        },
        {
            0xAB07D420FD9D5D88ULL, 0xE8DC213945DF3135ULL, 0x7B083953F2CDD7AEULL, 0xBF1D5564554F8114ULL, 
            0x69A3BAE9DD788030ULL, 0x6A8F50804F4B6766ULL, 0x1340E86E0CD56526ULL, 0x2E3A65DE12A21D20ULL, 
            0x6CC6AEA84D2A330FULL, 0xE12E74C8215B1EE2ULL, 0x5DA181F12930A5C6ULL, 0x08E4E21AD08D841AULL, 
            0x27B9EE0217A98D47ULL, 0xF725027376759BE8ULL, 0x7A91E70E549BB7C0ULL, 0x68581B3C70A865E4ULL, 
            0x5D460230289E3282ULL, 0x63D56BD035647210ULL, 0x70AEF59DBE441806ULL, 0xC30C6EDC0CA4621CULL, 
            0xDEAE08220288BE1CULL, 0xD1D9D910E777AF1FULL, 0xCF7DC4C8FA765FD2ULL, 0xA32A426EFB825FCAULL, 
            0xB0B1A3404D0DE250ULL, 0x4CEE23DD5149BC6FULL, 0x3694AF81EF34B7AFULL, 0x283FCE8BA28B6037ULL, 
            0x66BFAF67C7C1FCBEULL, 0xAB131706BE267125ULL, 0xA8D0B8CB412AC8D0ULL, 0x179DC05DA9781CBCULL
        }
    },
    {
        {
            0xB219C37CEE24B55BULL, 0x38A4469FE1B987EEULL, 0xC93EFD41FA1BB23CULL, 0x8978E22829B7AB65ULL, 
            0xA65DFF95FF6615EDULL, 0xF59EC1AE0FAF2315ULL, 0x19E8C4C07D4A39C6ULL, 0xC03FC61D2BEC69A8ULL, 
            0xCCDC6452E37A9ED7ULL, 0x3E3FAC8419C522E9ULL, 0xAE329DA5CBDEBBF5ULL, 0x6962FCDC286C8B33ULL, 
            0x086991DC0DC67691ULL, 0xA771248296C774BCULL, 0x776173207244DE01ULL, 0x7453DCF288EC11B6ULL, 
            0x89E0AF5A19C51BC7ULL, 0x4DC17D1C934E1CE3ULL, 0x966902D9E213D07BULL, 0xC1458AC2C812E2FDULL, 
            0xFB0A0C534205FD68ULL, 0xCD6AB175642B9715ULL, 0xA06D781FBB0EA0CEULL, 0xD2FA75B98728A4C8ULL, 
            0xF2ADA497FFD9C740ULL, 0xDECF1E811AE34D08ULL, 0x5AD5CD410155FE67ULL, 0x7F50767A9691932AULL, 
            0xD0538A95438503D3ULL, 0xBA640E785314AE22ULL, 0x17563D08201E9BD9ULL, 0x28F974D4D4083266ULL
        },
        {
            0x07B0E2B38638BF26ULL, 0xCCD916BB94A7CACCULL, 0x970423C12B2073A7ULL, 0x6C9F1833D0CE4A60ULL, 
            0x88DA221B04E497A3ULL, 0x988EEEAC48337DC2ULL, 0x7CA359EADB0C0125ULL, 0x165F9E5DA626270EULL, 
            0x552B3C7C1093EF13ULL, 0x83D080277E31D035ULL, 0x97F88BFE7FF03BE0ULL, 0xBCAEC06F054B249DULL, 
            0x3E452B54E063780EULL, 0x84BF4EC55DF1B007ULL, 0x5326BD2D6BE18888ULL, 0x48D9D89119180F57ULL, 
            0xD35351208C93213EULL, 0xA2DF5D790B7C1103ULL, 0xF95F74C192B76447ULL, 0xEE11C0AF0E69B473ULL, 
            0x98ACBDCBF3858E59ULL, 0xB79393E8DB673887ULL, 0x3E350C9D4184C3FCULL, 0xC33C4278C5B38FE0ULL, 
            0xE40B1F925F5B6EEAULL, 0xB8B6AB8A9DBAF0AEULL, 0xB9A2B18B7C788BD1ULL, 0xA3990928AF4967C5ULL, 
            0x3D9DE86BF9077366ULL, 0xB26239B38B130B03ULL, 0x3B3DACDDA9914122ULL, 0x4CC06E0F3B42B075ULL
        },
        {
            0x07CB9CDD69115C62ULL, 0x0FF874D74340E2F9ULL, 0x84B096831E77179DULL, 0x6272E12076C91CCAULL, 
            0x92626610DEBAE54CULL, 0x48DD1ABA46F80901ULL, 0xF9E508B025DB37E5ULL, 0x7F072896F2A0FA3DULL, 
            0x233AD0E88333689BULL, 0xB46FF9B7B2483769ULL, 0xE73BE1E513292C75ULL, 0x5B6F616CCF665C2BULL, 
            0x8C8617887D0478F6ULL, 0xC37702BE16D4D415ULL, 0x3DDAFD42F0E9E973ULL, 0x6CF9A4D1EDAA6FEEULL, 
            0x61E0EE24E421E3CAULL, 0xF9D4B30D2C3E53BDULL, 0x398CF271C76B564BULL, 0xC60FFB16302D471BULL, 
            0xF105551B3BA647BDULL, 0x4EFCB8A439EBCE3EULL, 0x42E6269AA1EE8034ULL, 0x226401D2FE209880ULL, 
            0x860E2C91B7548B14ULL, 0x7D7F4AB2190D782FULL, 0x741A9C4063945A58ULL, 0xDD1400D9B59B5860ULL, 
            0x7DBB40CB1FF877C4ULL, 0xD839220D43374F56ULL, 0xF02D3EF214158E7CULL, 0xC96B764BFA995E1CULL
        },
        {
            0x7E1BD3E2EFE0E1BBULL, 0x6480486A6436217FULL, 0x14BDACF6AF20E698ULL, 0x8D5CD49A967F3546ULL, 
            0x48B62D7984684168ULL, 0x2BF87AB495772657ULL, 0xC9AE6A0DD8234A75ULL, 0x13D4026FBD2B35AAULL, 
            0xEFB6FF435D9D43FDULL, 0x50FE5107D9205640ULL, 0xAB1F79E626DC4DC8ULL, 0xD3B1FAF05D4E6399ULL, 
            0x11E0E33F9BA150B8ULL, 0xB2EF17897BFE33DEULL, 0x25B75515441EFA02ULL, 0x4274584D33CA65FCULL, 
            0x7100B8CE8B7EB118ULL, 0x20B702A509E9D7A6ULL, 0x338BE8A1B7A274AFULL, 0x86A18F8B04637B4EULL, 
            0xEA3197E326747910ULL, 0x0894BF9E8A1E7A4CULL, 0x9A1DEF264EF29F6EULL, 0x7179A978F3BBAFA1ULL, 
            0x27CD58FFC87BE8E3ULL, 0x8775967AA659423CULL, 0xD3B187C19C8DED4CULL, 0x31BE806C9A1CF01CULL, 
            0x4399A845384EC2F3ULL, 0xE223CC2D31545B61ULL, 0xB9272A945B03332BULL, 0x62249F21D8584658ULL
        },
        {
            0xC898903C9090270BULL, 0x1CA228D3562C84E5ULL, 0xD96BECF850F00AFEULL, 0xD4CECA277475E5A1ULL, 
            0x270E402601DD2E6EULL, 0x8FC02EADDE14BAACULL, 0xB6778BEB0B3D9F1FULL, 0xA8DE87272B594152ULL, 
            0xE4318D67C4E7A1F2ULL, 0x5D3FED71559DABEFULL, 0x09D4885CBA0D6FAAULL, 0xB38E643201FB4548ULL, 
            0x1786F7F3163D062BULL, 0x5898F7A08512B37CULL, 0x306068024F8F1A54ULL, 0xD5B63C4F78C283B6ULL, 
            0x1A0D69F33F0C2260ULL, 0x724C5C37A873657EULL, 0xE86F19DC618E065EULL, 0x0E23F9D34956C627ULL, 
            0xBC8A03FB9BFBDF7DULL, 0xC6C5B9EF5D132439ULL, 0xCDE53A716D782776ULL, 0x4E6F8546880A5CA7ULL, 
            0x4C735399D7F10227ULL, 0xB9D3BCA65B8B6C06ULL, 0xFD5E5DEA2791DC33ULL, 0xF698353ABAA95D15ULL, 
            0xF38CAD4217CCED20ULL, 0x72064FD8224002A8ULL, 0xF123903BE6E30E0AULL, 0x6274083D8B24252AULL
        },
        {
            0x9B86EC70B58C79BEULL, 0x178A286A1C2AD0E2ULL, 0x9E8E8EF0CBC515C9ULL, 0x8B8DAC251A2B3D91ULL, 
            0x39AE09CB26A3FE8FULL, 0xE169FB86121603BEULL, 0xF0033739E6394E8DULL, 0x395FF7C3669570DDULL, 
            0x0E4031ADCF156798ULL, 0x1F89AD24B4E04966ULL, 0x8BE336056E94770EULL, 0xA0772BBD95177691ULL, 
            0x025CDC1D64AD591EULL, 0xF5733BC151E32579ULL, 0xCA19E4236ED0D157ULL, 0x9242AB4A106AA6CEULL, 
            0x45A116F588D3FA8BULL, 0x8B2E56A0A2A45DE3ULL, 0x57A204C093C7936DULL, 0x5709CD3F356AD4C0ULL, 
            0xECAE9A078F553005ULL, 0xB14AB4EF0AF8EA33ULL, 0x9B64637853D3ED7EULL, 0xCB0443AF96DC3D0AULL, 
            0x36924A0D1CD9006EULL, 0xBB1ADC746DDC1658ULL, 0x9AFDADDAF994C46EULL, 0x8C2E85BFD49A2703ULL, 
            0x8D9B169987A35A14ULL, 0x82026C814AB9D19AULL, 0xBD9AB7098AA446BDULL, 0x7323C610C4E4814DULL
        }
    },
    {
        {
            0x49B5BF3D5C1621E5ULL, 0x4B7F3FA4EBF36EEAULL, 0xB0CF379C9AE0CBBDULL, 0x45B94FB26FAB3CBEULL, 
            0x4E53E58CBAE03A21ULL, 0xE131BEF15F3AA887ULL, 0xF4E44661D8A5EA08ULL, 0xB401DFED65016E10ULL, 
            0x0F91D999D1F1F31BULL, 0x845E55282DF1BD3DULL, 0x042128301720E72EULL, 0x6E2880D78877D81CULL, 
            0x12E4BB3D20FF885BULL, 0x388717B5BB5CA668ULL, 0x96A9CD790AE4C7E1ULL, 0x237D6C10C5D8B14CULL, 
            0x86EC23077966099AULL, 0x10F0D9740B7CAB4FULL, 0x44CBD7C59F9CD8A1ULL, 0xD45710E6516D81C2ULL, 
            0x8AD582D10AB52717ULL, 0x1E56B2CC718F004EULL, 0xA484D96865F5BDB4ULL, 0xBE53B395183DA436ULL, 
            0x4218028D5CD3E48BULL, 0x94F66BA14BD61676ULL, 0x6F21172A6F2DD7A0ULL, 0x28D65FE56E7636B9ULL, 
            0x51E862B78AFBA480ULL, 0xB8BBB51311F61F53ULL, 0xD41E120E98241FF2ULL, 0x401D35362197A17BULL
        },
        {
            0xFD82527C706EC010ULL, 0x99B115B67C9EAAD2ULL, 0x7FAA76C4AC740814ULL, 0xA6A81A21425DF48FULL, 
            0xFA63B1E33D48678AULL, 0xA8FD238C6164E6C0ULL, 0x79A93D04C3B99975ULL, 0xD26A4DD821C4EE43ULL, 
            0x2D3A557205D36396ULL, 0x97AB5013E630459FULL, 0x83C878DD15DC83E5ULL, 0x77A591AA19418E0AULL, 
            0x44BAB2B8623BDA6CULL, 0x420227B4118BE4A4ULL, 0x71D6D883F3F6F274ULL, 0x548C36CB3D24DA71ULL, 
            0x626172EFBAD3121BULL, 0x274B27588B3A7BCDULL, 0xBAECAB875638A7C2ULL, 0x4EE11E4B1B06D2FFULL, 
            0x4E9CE1636A315A5AULL, 0xD80F491740E5DF12ULL, 0x9C743679F998E5DEULL, 0x636EE8F4E36AB3B6ULL, 
            0x9F320D4D50E2A024ULL, 0x48B5B07EA26E231CULL, 0xC614A1978FF372DDULL, 0xF7DAAD5DE729D0E3ULL, 
            0x6369DA6AD4553FCCULL, 0xD3F82E83E771CCAEULL, 0x92BB3357A1377DC9ULL, 0x52F349804BDD7D07ULL
        },
        {
            0x5E8CAE3A935EE4A5ULL, 0x3DF21AE69671FD4AULL, 0xD7D43CE79B22FABEULL, 0x35C26874EA9336B6ULL, 
            0xEEB031BAE684D6EAULL, 0xA6ED8186C35B48D4ULL, 0xB91C57A31B2A7130ULL, 0x9420822F94B05910ULL, 
            0x065BFB52EB73E197ULL, 0x9BA7AC2C48B3E33AULL, 0x801125C17F4F7C95ULL, 0xDD76DF7C1640D224ULL, 
            0x58798AD718206F3EULL, 0x9FD9CB3F386C21B5ULL, 0x2396365DFA44E27EULL, 0x49FA794197A89EA7ULL, 
            0xB265E2EAF0636122ULL, 0x8BB7D9BF1BB93902ULL, 0xFE2C589992F83E63ULL, 0x2F08F59488E643E7ULL, 
            0xABFF46D13EED4FA7ULL, 0x0CBE88A98F0A16D9ULL, 0xA23E1D1F76524010ULL, 0x821D7B6DC82EB5DFULL, 
            0x197387590408C2FEULL, 0x61EE7F963B5F4D26ULL, 0x44CCE89221CD40C8ULL, 0x6DEA993FFC268E75ULL, 
            0x7F5DE9C25194AADEULL, 0xB688BD4C779FAB9CULL, 0x49E5E7D192DCCB7AULL, 0x731AE6A611450F8CULL
        },
        {
            0xECB955813EDF60C5ULL, 0x60100F90BD4B97F1ULL, 0xB8B536148C43EE3AULL, 0x9554A41FC2B8B834ULL, 
            0x42916A932B067599ULL, 0xC71B4DAB2C5DA329ULL, 0xB9F4C1C21C425C95ULL, 0xADE291D3D6A25471ULL, 
            0x2AFF308057D77135ULL, 0x51F0945A5A5334CCULL, 0x31417DDCD90AC964ULL, 0xC75704D7706FB202ULL, 
            0xD0F0D7DC30A64186ULL, 0x84DF63652F09E445ULL, 0xFBA8D65DB56C6CA6ULL, 0x9C3BCDCF8149CF92ULL, 
            0xF09AB86F18F55DB3ULL, 0x102B04C904627997ULL, 0x5C132EDA983278C4ULL, 0x34254999A2D30DA2ULL, 
            0x7FB18ECCE30CB272ULL, 0xCE6C5FE5C24FB19DULL, 0x1AF505B1922E5161ULL, 0xF7C015DD0AC860A7ULL, 
            0x73A895C697F8823DULL, 0x4E94776F0BBF2EBBULL, 0xDBBE5782140513EDULL, 0xD2103B113FB587DDULL, 
            0x8440B63930662DC6ULL, 0xA5DD8526E85B7637ULL, 0x4F4EC1A79643F798ULL, 0xB5B238A7AE4EE2EBULL
        },
        {
            0x3BFCB96F5A9300D3ULL, 0x972ECB92DC55C1B9ULL, 0xE3C98F0B3B19010DULL, 0x01CD115CA76FCF43ULL, 
            0xAAB28F6A0207FD45ULL, 0x70BC9E774BC7A658ULL, 0xF5A3C95A474DCE7AULL, 0xB33A823DC64F6560ULL, 
            0x457AAC8934425BA6ULL, 0xD6C43CB8B942FB80ULL, 0x9B872658FBB3AF17ULL, 0x0FD5C6C3F49FC376ULL, 
            0xE128594498628F6CULL, 0x141E5FE99D028255ULL, 0xA23796B49BFE562BULL, 0xFB66506DA4FCC7B5ULL, 
            0x9AA57E8EF3403CF8ULL, 0xE741D08497140611ULL, 0x2337A2E07AC64CCFULL, 0x7DD105D44AE4FED6ULL, 
            0xBADF4547BCD9E6D2ULL, 0x5F456BC575E7854FULL, 0xCA7D889A66CD5E47ULL, 0x968F6F3705873C59ULL, 
            0xF9F61514A19FE5DFULL, 0x5B229547623985FFULL, 0x7C1611BF8FB7821AULL, 0xF47AC404530B05F1ULL, 
            0x92A4EA6F5F18B35CULL, 0xAE8707E53B7A86B7ULL, 0x4E07FAED3877F9F9ULL, 0xDFC2564D5FF68176ULL
        },
        {
            0x7AA1D2F3AFA613FFULL, 0xF881D1C2F53AAD5EULL, 0xDA026D9742C5B349ULL, 0xE20E61629659861EULL, 
            0x74885CE9962C8B3DULL, 0x6339E926C4E1472AULL, 0x7993B7F9AD8F3301ULL, 0xFE75E19A910B5BC9ULL, 
            0xE22D9A822F8C5937ULL, 0x52459705FB190DC5ULL, 0xF09B6A7022D03FFEULL, 0xE9E2E4111730421BULL, 
            0x7DA4063E70D0295CULL, 0x7A0B746436EFF98FULL, 0x8C168621B177B403ULL, 0xC94DB18739D94639ULL, 
            0x16519DD97EEB0632ULL, 0x9FB0FFBB33C47882ULL, 0x70FBCD1EB9BAF80EULL, 0x02EEDEF84F4D4FCCULL, 
            0x4FB3448C95E0ED5FULL, 0x4EF356CF45DF0B90ULL, 0x2CC2659EEAF1F1CAULL, 0xD118A6061CC763F2ULL, 
            0x8DEAEFC72E51482BULL, 0x2338AB3F21085099ULL, 0x10163459AF6721EFULL, 0xBAFAB3E5CAAC4CF7ULL, 
            0x6900D5353C77A2E1ULL, 0x9D572AAA035DB954ULL, 0x5516561EDF3002B7ULL, 0xD9F3A3439009AA22ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseBConstants = {
    0x839607E31F69837AULL,
    0xCA94C4036F234615ULL,
    0x706F0D09F559328FULL,
    0x839607E31F69837AULL,
    0xCA94C4036F234615ULL,
    0x706F0D09F559328FULL,
    0xDA84E5BD3D41495CULL,
    0x759D2F9FDA8FF9AAULL,
    0x95,
    0xEE,
    0xC8,
    0xDE,
    0xE7,
    0x0C,
    0x44,
    0xEB
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseCSalts = {
    {
        {
            0x892708D420E3316DULL, 0xBA4732BBD108DEA9ULL, 0x2C22167FE075BF01ULL, 0x77744DD7BF3CBF6BULL, 
            0xAE55FCB443D0963CULL, 0x8CFA6837D67E2FBBULL, 0x6EDFA0D3AB7EBFCAULL, 0x66F64D5D7EC9690FULL, 
            0xD40438DB054D022EULL, 0x8E8BEC1CCF14D5DAULL, 0x8A009174FA94B530ULL, 0xA6079DC1201C8594ULL, 
            0x06CCBB91031089C1ULL, 0x597ADB57620D8ACEULL, 0xE0D0D91624112646ULL, 0x6F6DC40744A842E5ULL, 
            0xF8C20A6FDE6A64C8ULL, 0x420BBE7A73A02D93ULL, 0x918A52E4DBE820DFULL, 0xF2EB634BC3B047D1ULL, 
            0xFA9CDFB4A0978F4FULL, 0x1DC89C27EDE95326ULL, 0x158C23D19DFEF4D0ULL, 0x2273A3A3CAAE4D3DULL, 
            0x0EE4F89B47B45927ULL, 0xDA56F71AB1E0F12AULL, 0xAC48FC5CD56291DDULL, 0x1E48118321248EE0ULL, 
            0xCF9D27403A5D8111ULL, 0xF577E19A4E1105A1ULL, 0xC79272F4A997AA17ULL, 0x6CDA426E74648C9EULL
        },
        {
            0x78090FB44254B6C1ULL, 0xBBA34F6DB2E2736FULL, 0x19B0736B341E01BBULL, 0xB6881D2406F7E8D7ULL, 
            0x1751C723345CCA53ULL, 0xDCA2FD4590BA3174ULL, 0x2C90A9DC6FAFEA12ULL, 0x6CCB542A5E8C82B1ULL, 
            0x4A43363068FF9936ULL, 0xA675FB1CF6483568ULL, 0xB2588B4EF4029599ULL, 0x295B02D23697AC12ULL, 
            0xBC27B57E646ABD68ULL, 0xEB3A857B1ED83DE0ULL, 0x3A46ADA160BA4781ULL, 0xF2F4902E672A8F05ULL, 
            0x2317785C61406519ULL, 0x41A90A45480C164FULL, 0xBD84CB4C0A59B4FBULL, 0x1ED02588F3F66670ULL, 
            0x45304DD550BE807EULL, 0x2E93DB157B45509CULL, 0x92F25A864A8D4242ULL, 0xAFF302DE2D52A162ULL, 
            0x27F40B6A45091746ULL, 0x990B8930BE8D8E27ULL, 0xF7D87DBD7EF76E12ULL, 0xF4334680755AE3ECULL, 
            0x5253FF925AC353CBULL, 0xF38069F1F4BB62BDULL, 0xBF067554098200D3ULL, 0x771D3E45A0776228ULL
        },
        {
            0x37B2E38A2B242FECULL, 0x54FC96AF4DA9DBAFULL, 0x9DE10288235309AFULL, 0x9DAC7A5105B88CFBULL, 
            0x31BDE97DF532C10AULL, 0xCFBD5CFCBC9F433CULL, 0x374ABDC09695A423ULL, 0xBB7761C9F4AD847FULL, 
            0xAB5D0D943437AFCDULL, 0x3964DF873BA56981ULL, 0x0957B47066936E6BULL, 0x805B8CEC15148F64ULL, 
            0x9BF1E6DB9F9711E6ULL, 0x47CDFDA9D5DFBE71ULL, 0x967914FCBF914A06ULL, 0x5F42A72082F5C61FULL, 
            0x2FE199FFA209EB80ULL, 0x1E22E14427BD9DFEULL, 0x81ED54E2B9CA1D5AULL, 0x0F9E455DF6F63B62ULL, 
            0xB01BAA63ED8C7196ULL, 0x5CD82641F121F5F5ULL, 0x3393F6B19E4E3B2FULL, 0xEEC0853EFD20AFB3ULL, 
            0x8ED923F72A19DB64ULL, 0xDA7ED852AFC1FB5BULL, 0xC66BF4D6FEB39B37ULL, 0x9A79E454670B3229ULL, 
            0x27B8F4ECA57AA21BULL, 0xBD52E0112BD5CA67ULL, 0x0DBE561186BB095FULL, 0xC5CA7905D65E0C1FULL
        },
        {
            0x70DD270F954C4A8EULL, 0x2173B0220A2EEAE4ULL, 0x460EA630FFAACEC8ULL, 0x28E900452A0E97E4ULL, 
            0x17F50A5A30D2F901ULL, 0xDA6A76D1D594671AULL, 0xEDCA89E83FE2EB9AULL, 0x21F66704FE30FDA3ULL, 
            0xADDDBAE454EAB8BEULL, 0xDE1E923CEADB3439ULL, 0x4088292DDD5BD925ULL, 0x3DE0A2151FEBC7A6ULL, 
            0xA857CDA1F985F574ULL, 0x8B5BEF5BF50C148FULL, 0xCCBDBC0AC32D9216ULL, 0xD0CCCB68A9B32904ULL, 
            0x8B03A26CCCFAED0AULL, 0x6A553CD9201E2C4CULL, 0xE432F2FADC9EE39AULL, 0x63DE2ED05F286237ULL, 
            0xF62A5AF1D2CC5A0CULL, 0xDC249C3F016BF547ULL, 0x931688FBB0C3F771ULL, 0xBD104D9E05D79EE1ULL, 
            0xABB5BE67A1000B53ULL, 0x9285EDED1BFFDA61ULL, 0xA65090EE6FE6E145ULL, 0x3F0C2A9A97514351ULL, 
            0x1146759674DFD9E3ULL, 0xFDD4A0C2CAC05C0CULL, 0xD5F1FF72DF763C94ULL, 0x2DEEBEF0C4BDB31BULL
        },
        {
            0x01E6AEEF2DB0DD4AULL, 0x95D927932281AFCAULL, 0xD411DB47932B5690ULL, 0x867B6866ECF34427ULL, 
            0x3C7BD24E1F4646B7ULL, 0x3658042B2531CD85ULL, 0x961825CEE5015A81ULL, 0xEA03F7FB115A72B6ULL, 
            0x7EE39BAD7945EB47ULL, 0x1E72E3DF3C853C01ULL, 0xBF2FE6E9838462AAULL, 0x39E097BC18514E34ULL, 
            0xA67B8320C9FB3B65ULL, 0x7A459E0A083757F2ULL, 0xBBE6302FD51AB150ULL, 0x727E4F6F7E7E4C78ULL, 
            0xBB9C2ACDE9A0EFDDULL, 0x964EECB02DBA92B0ULL, 0x84726F3D01F91EC5ULL, 0xA7A89ED4B67B8972ULL, 
            0xC160ADBC0AC5A989ULL, 0x191EAA095DA54D13ULL, 0x69A8F2A6EDDDC43DULL, 0x77E20322DE4528F6ULL, 
            0x9D804C3EDC3A3B68ULL, 0x7580DBC8E9CD721BULL, 0x620E0783EADA06CBULL, 0x50B6E9E852283945ULL, 
            0x1923B67DF4681514ULL, 0x49BBA0D3433C710CULL, 0x709135584057F002ULL, 0xAF870700882E6AD9ULL
        },
        {
            0xAA601307946399DCULL, 0x6F4F79D836863B0CULL, 0x32B03BE2CCED1C7CULL, 0x20E9EF95FCE30A44ULL, 
            0xDB58A6674ED5AA28ULL, 0xE1E13F7AB11B2D54ULL, 0x0FB0320921B518D4ULL, 0x4A25B846DF7F814CULL, 
            0x8FDC4298C004CAEEULL, 0x8D5E028D2B5D085BULL, 0x945C0939821E7436ULL, 0x14EEEC441E9687AFULL, 
            0xE83214D8E6A0A45CULL, 0xBC7F5C9A8BE1571DULL, 0x297649050F5063A4ULL, 0xD11CC5DE66457A9CULL, 
            0xC0FA6E74DA2F9CFFULL, 0x271302C3CEBFAC2AULL, 0x7779355F83837853ULL, 0x2F1E479D36A99340ULL, 
            0x8EC7AE6CA22204DDULL, 0xCD65553296517202ULL, 0x2A63926F9C4FB44EULL, 0x2BBA9622836AEBC3ULL, 
            0xDDCC42F02CD96C35ULL, 0xCAD91C5B82C57CB5ULL, 0x5E0A723FE50D2DC2ULL, 0x38EFABB335238E2DULL, 
            0xAC695818AF430035ULL, 0x599F63D3EF72A3B4ULL, 0x99632E08EF0F20F5ULL, 0xFD1163936E885327ULL
        }
    },
    {
        {
            0x49C4BD61A2F3752CULL, 0x122F3B9824614B9EULL, 0x9667F09D4BCFA3F9ULL, 0x49A6CBBCD4145087ULL, 
            0x23A1A8F2E6438DE6ULL, 0xDEAD03BC1FE1DDC6ULL, 0xA8FC6E09CB747D57ULL, 0x5D1EC00EFA6CD38AULL, 
            0xF7748B3802957E48ULL, 0x6A440F14FD7743DBULL, 0xD54FE3A0C7789540ULL, 0x5EDAAE65BB442FBBULL, 
            0xB1DC7A50E84C6A5BULL, 0x1B2605D0B85F05DAULL, 0x1BBA4BB55A7DAD2BULL, 0xD6BE88444857594AULL, 
            0x6B7D1982DCBD2734ULL, 0x50E079D624FCBC79ULL, 0xBAB02D5AD116C06AULL, 0x0F9EBF77CCE3BCF2ULL, 
            0xCCF4223628771E60ULL, 0xBC7465CDDE6CA071ULL, 0x4092A418685AC715ULL, 0x1E74A1CA59A1DA84ULL, 
            0xDD0B43DB4D1B7390ULL, 0x559C29EFB4C86020ULL, 0xDF6A97BD265A7024ULL, 0x7253437CBB2E598CULL, 
            0xD4890170C596F4F7ULL, 0x63A511E36340C340ULL, 0x0A7D06DD3606E487ULL, 0x3B9D62CEA2AB14A2ULL
        },
        {
            0x2652CA58DC076647ULL, 0x5BA79FC6ADD77718ULL, 0x02BED88331697CD9ULL, 0x5072BE90FEB603ABULL, 
            0x6CD7310A03FF1878ULL, 0x6A9B857FFB444F2DULL, 0xD3ED168E0E529B0BULL, 0x2136CC078CB809F2ULL, 
            0x06D3F803E1A8C28AULL, 0xEA48D8C6CEA60633ULL, 0x904EEE7F24692E9BULL, 0xDC06C1BBCC37D62EULL, 
            0x63927B64A3B0125DULL, 0xD2FFFE65243BFC1AULL, 0xA9F80975F4EF2536ULL, 0xB2A3C56F83E72501ULL, 
            0x18B68D01E985A0B1ULL, 0x73727E526AA78429ULL, 0xCCB1B2526AF9E685ULL, 0xDCB77E6BB9ED6A46ULL, 
            0xD05BCF9C574C0CECULL, 0x152C8DF5F0366F95ULL, 0x9D8348A40B9444E2ULL, 0xC461C622C0CABCE9ULL, 
            0x420794A0405B487EULL, 0x83ED3080BFA4682FULL, 0x50B6BDA311A29FE1ULL, 0x4B45B5C52F40FF57ULL, 
            0xECE689071D00160CULL, 0x66BCD4278E58E846ULL, 0x02E35B2EA2BB87DDULL, 0xACBB02AA98FBB06FULL
        },
        {
            0x23A2AD976E82121EULL, 0x1047D11B73C4C494ULL, 0xB45414BF22E152D5ULL, 0x61945CDB005C1D41ULL, 
            0xBF5CB8A3B14B69E8ULL, 0xAADA28715869BEA0ULL, 0xE10517C21B6658B1ULL, 0xACBC5D7094CEC536ULL, 
            0x825AC4B19497A7E9ULL, 0xFD3D7F8DC98FC6A1ULL, 0x6A197D12D8802724ULL, 0xF0610AF236F98657ULL, 
            0xC48B479EF695FC68ULL, 0x81A2A3164A4967E4ULL, 0xCC048C1CD8EA1FE9ULL, 0x186F8C6F41663361ULL, 
            0x4DE57918BAA7A91DULL, 0xDD6993C6C623B66FULL, 0x121C888424D636C9ULL, 0xE2766C6C7B7EDDF8ULL, 
            0xC45D048634EA0C17ULL, 0x2D0FC55E2F36D4CFULL, 0xDD4D72F3FC86D33BULL, 0x77592EEF6AF03785ULL, 
            0x7509D1014FE3A159ULL, 0xAB62615B58DA7F09ULL, 0x56822F45DF903F90ULL, 0x9AB844F4CEB5713FULL, 
            0x6A4364B0105300D8ULL, 0x074B47E15C53D56EULL, 0x2C586B5AC441FD2FULL, 0x6E0013A4BD4E550EULL
        },
        {
            0x4863F350E2CDBE75ULL, 0x18B3233DFF2431E2ULL, 0x6BA9244F03870F93ULL, 0xC5BEAFB680435B75ULL, 
            0x1B328EE728BA7932ULL, 0x8CC355AC9E10A854ULL, 0x4922BBD0975C28D1ULL, 0xCA3967AFE1CCD982ULL, 
            0x98C352E901163B78ULL, 0xA1BE4349C95390A0ULL, 0x0D769CAADA04C106ULL, 0xF99E60CDE0978746ULL, 
            0x744B3521DCBA097EULL, 0xF348E27DF7AE7DD1ULL, 0x3AC23BF06656E812ULL, 0xA6829F7C292E5323ULL, 
            0x09EFA4E648BE1042ULL, 0xE1B6A8EA156F56B9ULL, 0xE5637F59F508A89EULL, 0x839124695574C49CULL, 
            0xC1508DB2A296A2C4ULL, 0x9BA8D7FD2D7721C6ULL, 0x8F9869A415C0D78AULL, 0x379B654C99A09722ULL, 
            0xCC6E1701381DD595ULL, 0xE7377E86525AC95FULL, 0xE4527F4C73F6801FULL, 0xFD89F628CC0F4527ULL, 
            0x98EAD9E86C392767ULL, 0x3C8FC0C3EE1FFCF0ULL, 0x4B8CB2C645CBD026ULL, 0x2688BE7964F5C63DULL
        },
        {
            0xC2E778CEE9B7A7F8ULL, 0x93727A5DCDA0E7BBULL, 0x7CF206AB17811641ULL, 0x0DC3169E119791B9ULL, 
            0x5F3A1A25F2B8D4DDULL, 0x7B66FB4BF7A04F84ULL, 0xBC2C9826B2F40E1FULL, 0xD4B8CEFD2B472F25ULL, 
            0xB927420E9276E606ULL, 0xF089A7D95D1784E7ULL, 0xAD9560E764892B68ULL, 0x572485F164F5CEBEULL, 
            0xBB1711CCD0BB1303ULL, 0x7BF7C1327F645586ULL, 0xCC58CD51A910753BULL, 0x44E382F11E242DFDULL, 
            0x3D99086421917442ULL, 0x24BDDC09E4045AD0ULL, 0x824A6F896B9740B4ULL, 0xD586C4BEA17E7E2DULL, 
            0xF83126C291164E49ULL, 0x718C6024DA2177A8ULL, 0x0282BF2008D37218ULL, 0x7FAACC6F2395651AULL, 
            0x16343FFBA04A6680ULL, 0x015B93C3A8CD1018ULL, 0x12675ECEF8C4F3A2ULL, 0xA35EEED4D94E09D8ULL, 
            0x28EDEF897E1F2D14ULL, 0x81A05BBFD71E466EULL, 0x16F7E1B2DBA75042ULL, 0xD3DCDB7413431219ULL
        },
        {
            0x682585A5D6E3E90AULL, 0x490CACD7E466780DULL, 0x175B0CB4E9D8451EULL, 0xAA2B8ACE501E9121ULL, 
            0x5CA2CF6F9F2AA30EULL, 0xEE4F652E3BE25424ULL, 0x91BA6E2AEE5F768BULL, 0xC7EDB294E984D4CEULL, 
            0xB405DCC554937AAAULL, 0x0ECD144C8F2B9082ULL, 0x642609E33A9AF06CULL, 0x14B2BBDD494B4DADULL, 
            0xD5E4C66564CD1653ULL, 0x348D751C66C1ECC8ULL, 0x77BEB6604E7D2BC2ULL, 0x08AD60FFBD86F61AULL, 
            0x1350D62264CA2B3CULL, 0x1A910C42FF6581C5ULL, 0xAF924DA903D140A2ULL, 0xFB68ECAE0E0C657FULL, 
            0x9B3D384B927FAC42ULL, 0x3C36C4825F68DC5FULL, 0x7F578A4130DFC617ULL, 0x8D721897301B6791ULL, 
            0x4006BE2C1C1AE022ULL, 0x0F0D20F53F21A2E6ULL, 0xB0B2415E79E679B1ULL, 0x3AED47F534310A69ULL, 
            0x6B07DAA11641EB86ULL, 0x13CB9C8BAE0E5130ULL, 0xE467FCE339B62FB6ULL, 0x8FE8C4AE854FD883ULL
        }
    },
    {
        {
            0x1D116DFF21178EACULL, 0x0A13B67E5F8F9782ULL, 0xEEB85EC3BBDB3AFDULL, 0xFC3A2CF147048EF8ULL, 
            0xC30CE8C2854CCB61ULL, 0xD65FBDD901E431A2ULL, 0x85B4DD8A9F8C05F2ULL, 0x55B9ED6DAEAD1B9BULL, 
            0xD4D311A20CA434F9ULL, 0x414140C2616AA5C3ULL, 0x12C3E0D51FA553A5ULL, 0x52437CB993458B8DULL, 
            0x660643864CA5023FULL, 0x18509210EBE997B2ULL, 0xC17438DAB9C0735DULL, 0x40570D7200A8AD1CULL, 
            0x1D3D81E5A9E38290ULL, 0x20B485710C1FFD48ULL, 0x6F9049602C2FD519ULL, 0x5BE3B0912FCAA634ULL, 
            0xDF96923806E79686ULL, 0x56E97DAEBAEAA652ULL, 0x9A9D834CEB2320D7ULL, 0x4B2EAD53CB70905DULL, 
            0x95031FB5A1C1BB57ULL, 0x6B458668A6CB3A4BULL, 0x14B81513FEB39CE2ULL, 0x8529B8532DF723C7ULL, 
            0x89B0EA4820E3A2D2ULL, 0x93DBED17A3BB326CULL, 0xE1C64841656D74A6ULL, 0x7CE16B1A59E2C10AULL
        },
        {
            0xC0F430FB7E1A0263ULL, 0x5AB460991F4203BFULL, 0xDA2788E092F906C5ULL, 0xA9AE5E81400E7290ULL, 
            0x7EA79370C0A897F7ULL, 0x0DE49963F1EB25FFULL, 0xD086EB921482935BULL, 0x84552C2B82E62E8FULL, 
            0x1FE52E4E74ED6BA6ULL, 0xF99572A3301BC0C0ULL, 0x5C8DDB361EA3CC62ULL, 0x31E99F02884FE475ULL, 
            0x0B0531B4481F89A3ULL, 0x2097FFF28FCF13FDULL, 0x71BD32D778D18821ULL, 0x8584226823D43816ULL, 
            0x84BE09E0D10C9000ULL, 0x8FD83BF33AA92E98ULL, 0x145A6E566B5DF5E2ULL, 0xF78296ECFB7648E6ULL, 
            0xBD6FCC02D3D62FA5ULL, 0x6B720C4C8B963122ULL, 0x2E2E874B72E162A3ULL, 0x34136143454EB7C4ULL, 
            0x985F13139EA5BF99ULL, 0x2D22D92D1470355DULL, 0xFF71E25D113AFB26ULL, 0x4CBF7EC916BDB90BULL, 
            0xF64C2138A585D754ULL, 0x070B236E29389B71ULL, 0x7A1F24197BF32078ULL, 0x1AD60A71F4FFEE15ULL
        },
        {
            0x0E21579A68A67193ULL, 0x8DB2FE657C296F71ULL, 0x58DD3860800E2935ULL, 0xCA5FF79C69ED1283ULL, 
            0x27C05F6E2B4A4A3BULL, 0xB1890594564D4BFDULL, 0x9B1F464AB01E35AEULL, 0x03D3DCF1CC77AC41ULL, 
            0x292367CC58E79F92ULL, 0xC7A1E98245DD73D2ULL, 0x30B2AB78FE314B08ULL, 0x13EF992BAACDE990ULL, 
            0x5085AC6EB71DABE0ULL, 0x7EF8D77E6E97EBF1ULL, 0xC8AE3C193235E507ULL, 0x46F2DBD8DDB9D6AAULL, 
            0xD601C21BFD9210BBULL, 0x3973E79D4774003EULL, 0xC633641246E20A0CULL, 0x75D11483FA89E05EULL, 
            0xC0EF4FC602A06F03ULL, 0x7372697C1205966BULL, 0xFA1714401ACD508EULL, 0x849068B61D02CD60ULL, 
            0xEF8F414EE47D5077ULL, 0xA5750E467D3255E3ULL, 0xD86FCA1144983469ULL, 0x7F0D068D7B0B1D85ULL, 
            0xA895DC1CE106679EULL, 0x66E8E51066FB678CULL, 0xAACE2186EB5B6F34ULL, 0xADA36C4DA9DBA1FCULL
        },
        {
            0x6E4B6778D59649A4ULL, 0x5E566432B0A53670ULL, 0x9B67F4563705B8BEULL, 0x3ACEABD03C7A3A8AULL, 
            0x71A5BB3178BAE333ULL, 0xC933C8042C450777ULL, 0x8FC08261A60BA1B3ULL, 0x52791E0988A41F89ULL, 
            0xE5223A30C940C009ULL, 0xD70718DAE084EF79ULL, 0x54D18D1CEE4B009FULL, 0x87ED9DCE4EE21F24ULL, 
            0xF7BEE1BCF56D5A5FULL, 0x64D81F4DFA0294EFULL, 0xA050B4048F7FC5F6ULL, 0x06F49246A1B18050ULL, 
            0x068A70384FB50851ULL, 0x4716996865B2B37FULL, 0x60618C9BA6E06F1BULL, 0x60B870FA04FF65EEULL, 
            0x132B3BFDCADDD198ULL, 0x5C9F2C5B5C90BA19ULL, 0x11EE22F34C16EEA7ULL, 0xF0B47347744ED1A5ULL, 
            0x9DDC876D7BE59AB4ULL, 0x141D387A70487E1AULL, 0x19A74F1EC27D9F3CULL, 0xCFA66F17A82D3AB1ULL, 
            0x24692B940042946FULL, 0xC24CBA268C97260EULL, 0x1F373BBA6A541915ULL, 0x458307BD60FF8267ULL
        },
        {
            0x83BB79553EC86A9AULL, 0xE9E43D365F55218BULL, 0x6EDFE009EE768D60ULL, 0x28FF5FC00E536388ULL, 
            0x0A08F8D62738BB5CULL, 0x38A613D615A45811ULL, 0xBAA988932B01F204ULL, 0xD7F6344BA41865DBULL, 
            0x279A3F77AF2459C5ULL, 0xAE82FD30C4552F2FULL, 0xB351C501B8F32B09ULL, 0x147E3E7D4AC9F7CBULL, 
            0xA72AC6A773CC572AULL, 0x518D59FBD5532BA9ULL, 0x2159BE2E8CD41E96ULL, 0xDA2B83E785DD9713ULL, 
            0x9F72B026DD179CA0ULL, 0x3D30F16CB8E7CADDULL, 0xBCA0B5A82038F9C6ULL, 0x208299864829E5E0ULL, 
            0x91D1F37478781662ULL, 0x18ADB34316D092CBULL, 0x256B86FBBC7CA96EULL, 0xCA565EAA29835B1CULL, 
            0x85FE425B01C67266ULL, 0x7A644ED771D06089ULL, 0x9655E2052A932DA7ULL, 0xAB0B91A592A79699ULL, 
            0x1B96DBAB236FB18FULL, 0xEB99FED34624D01FULL, 0x6768F7629A59A135ULL, 0x7287F140C47DAFC4ULL
        },
        {
            0x14706BF8049FDBC0ULL, 0x1C8ABC2B138E02B4ULL, 0xD29305081459538CULL, 0xD131866810F3B0ADULL, 
            0x6C4AEF6A13D8E98BULL, 0xC5390A61FE0EB9E2ULL, 0xEBBE2801127FDDC4ULL, 0x6667F621796E7F7DULL, 
            0x4315475D066FED7DULL, 0x279FF63A4AAE42A1ULL, 0x95EBDC552DA7A927ULL, 0xA0FD56040531262DULL, 
            0xEA245049B3BE025DULL, 0x90CF23AEADE741B7ULL, 0xE09FB28E25487354ULL, 0x8E01F8325F96A19DULL, 
            0x4B702825E0B5532CULL, 0xA5B15F49B6ABDDA3ULL, 0x6917817891608B7EULL, 0x59C2762559B13D21ULL, 
            0x82B4D1C38CDE4060ULL, 0x75A3CF89D53B55B6ULL, 0x332C37434D0A5EF6ULL, 0x75809A7411E0407DULL, 
            0xA645EB7F669E486BULL, 0x3EB6A6BCF01FF08EULL, 0x224BC4E6CEBD6F44ULL, 0x9CBFF9298A61E1A6ULL, 
            0x68BACDFCE04E03AFULL, 0x2AC3917602F74718ULL, 0x0F36725FBBF686E6ULL, 0xD26AEC0B2189158CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseCConstants = {
    0xFBA69A40FA5646CBULL,
    0x7A532DFB65C2FBC2ULL,
    0x6AFDAD9418FB01FCULL,
    0xFBA69A40FA5646CBULL,
    0x7A532DFB65C2FBC2ULL,
    0x6AFDAD9418FB01FCULL,
    0x6E8F355FFA22C1A4ULL,
    0x172B2D802927A834ULL,
    0x5E,
    0x35,
    0x52,
    0x1F,
    0x6D,
    0x6C,
    0x6C,
    0x1F
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseDSalts = {
    {
        {
            0x2C81C5D0BCF299DAULL, 0xF547BAACFDB89B77ULL, 0x2B7E4A9FC6346075ULL, 0xC369C81BE0E1BBF5ULL, 
            0x61315D81FFFDE586ULL, 0xEC6E7C4BC7E5C458ULL, 0xED40B689639443B6ULL, 0x7B322768CF5663E3ULL, 
            0xA53CB92A0EA91CE2ULL, 0xE39E15394FA7E27AULL, 0x580F37E7353891F3ULL, 0x73EF8A291457875AULL, 
            0xBC41E6BCA29EFF73ULL, 0xFA3FF799272FC603ULL, 0x1B54CDB394227B52ULL, 0x5F3388F77B05FCADULL, 
            0xD9333F62C706BFFEULL, 0x10A72CD83DE36927ULL, 0xC2FE79E40192D45CULL, 0x389A947545A3608DULL, 
            0x9E5802E261DBBDECULL, 0x98670F256C885929ULL, 0x224C47390467ADD4ULL, 0xA08F8846146BD28AULL, 
            0x98E5530DA15F05A3ULL, 0x815E14B30DAB380FULL, 0x2194B059F7BB1EA5ULL, 0x1A40B53C2DAD1C8AULL, 
            0x334E85499A293ECAULL, 0xB37F3F418B12227BULL, 0xDD8746DFD2799FB4ULL, 0xC056D3A95BB5CE25ULL
        },
        {
            0x2A60E8B1D6D2E4EAULL, 0x82CB422563DACFDBULL, 0x836CA7BE8DB0CB7DULL, 0x0E4FBBFB667D7AD3ULL, 
            0x7968FBBE0F253FFEULL, 0x39AC35EBE536DC68ULL, 0x0DF062C928163767ULL, 0xC46419B5D293E88CULL, 
            0x5AE863E7717731D9ULL, 0xA99350AF93D07B87ULL, 0x272F3494D2B283F6ULL, 0x84E4D6A6D1863013ULL, 
            0x996C9C7C893FF9B0ULL, 0x45754D30D462B6FEULL, 0x50838F108FA0A6D2ULL, 0x0B71B763A77ACA32ULL, 
            0x0442FE69D28AAD72ULL, 0x64920F907F8CCF37ULL, 0x0C35F6CCF9009E55ULL, 0xAAF1D9F0D0EA3BEFULL, 
            0x8371EE8623C35F12ULL, 0x0C300BD1C5A1818BULL, 0xDE0F0AAD813EDC7FULL, 0x53AA71EF507B71E5ULL, 
            0xE25D3069CC22FD9DULL, 0xB356B7613071010FULL, 0x3C5949FDB63101A6ULL, 0x21FD28D9246A78BDULL, 
            0x1706AD3386BA157AULL, 0xC8E6E80B89FDE869ULL, 0x143074FECB1E3817ULL, 0x17547561A2CB26DCULL
        },
        {
            0x9C1E28788D743E16ULL, 0x51BCBFC2B2A54674ULL, 0xAAB185D4926A6A58ULL, 0x58945171D023F367ULL, 
            0xC9F1131479908D4FULL, 0xF0717DA497590F03ULL, 0x82EF074CDA07A195ULL, 0x057520E34F76BB35ULL, 
            0x8DC1424091A38A4EULL, 0x6BEAF1405BF8E13FULL, 0x0735CEEF5EF45EF5ULL, 0x6E44FEC5D93348E3ULL, 
            0x848368A4E1F2EE14ULL, 0x8995E1A6D06A8B0DULL, 0xEBE5CB1539276FCEULL, 0x9F0F574366C3BA93ULL, 
            0x8FFD2D5558949B3CULL, 0x59D5323A64C4C995ULL, 0xB22AC9AD4B683CF2ULL, 0xA41ECC07A24705A3ULL, 
            0x93DF3724D9BF392BULL, 0x05D33C87031F495CULL, 0xA786BEB89055F13EULL, 0x1990F89A2F799804ULL, 
            0x0C69014E1AB9A0EDULL, 0xDF9AABD0C21FDD24ULL, 0x2E1FFF95AE082DDFULL, 0xF3001814B34A7FC6ULL, 
            0x955AA9968A99867AULL, 0xB909A49DA5541E05ULL, 0x5415CE03A793EBC4ULL, 0x3F8394AC7BB24291ULL
        },
        {
            0x3FC69FC20CFEB309ULL, 0x62C51FCCE9B5AC95ULL, 0x8A1AC7884862DDA3ULL, 0xB92C0023DD882CA7ULL, 
            0x3B61257512B9789CULL, 0xFB5D644626E603ABULL, 0xDF4606D3AD4B5ECCULL, 0x0968B4384A1183BCULL, 
            0x78E0E38E7BB52B8BULL, 0xA71C12B61591F158ULL, 0x6D1BF9E09A761B6DULL, 0x35E7F7C1A8E64FABULL, 
            0xF6CE37E06A43EB5BULL, 0x0C31FF11A740E435ULL, 0xFE3DFF6F19294F30ULL, 0x61F8CBF16F009973ULL, 
            0xB45AD48804EFE059ULL, 0xEFE2640E4E55BC45ULL, 0x746896EFF51F612DULL, 0x8407CDBBC5A87A52ULL, 
            0x318F9D2BFB10DE45ULL, 0xEEBDEF736E0306CFULL, 0x7B71329EF1A1056AULL, 0xFB213A38D111E99CULL, 
            0x31968F310A5D190FULL, 0x6A1ACF81653D3445ULL, 0x0541EAE3E828BF8BULL, 0x6B577B990DA5E3B8ULL, 
            0xC9D5A31AD0C875F0ULL, 0xCB002C65FD9B4C88ULL, 0xDC129B1DAF819863ULL, 0xCB7C4F7D95F651BFULL
        },
        {
            0xC60B9D84C85FB1EAULL, 0x6D712A4B6E4BF7F7ULL, 0xB74A89966D9F09D8ULL, 0x31B1EE6E1E8B8068ULL, 
            0xF5A4A2768CE36E0BULL, 0x23AD2AE040C28589ULL, 0xC2E8B8B74283EC3AULL, 0xE9D3A78058714608ULL, 
            0xB19F581A53C0E45FULL, 0x5EC5845E06684298ULL, 0x507530DE2187B83EULL, 0x21A1DDF73CF7615BULL, 
            0xF0718D0295F10633ULL, 0xA2D6C16C03EB6C26ULL, 0x23F08E076D2C0395ULL, 0xB152D5BEF3EF5CCEULL, 
            0x0A9A846B95A50F89ULL, 0xB000F289DE2EACC0ULL, 0x8C8834B254D08203ULL, 0x5E1DE2EB7FD628BBULL, 
            0x6CD4976A2EBA9524ULL, 0x0ED0DAE4FBCF789FULL, 0x7A8E092EE87817B3ULL, 0xFAE38CED994E98F0ULL, 
            0x9B33B33715071872ULL, 0x06821909E20119ACULL, 0xA016C15EA844D1ECULL, 0x473DDD5C79ABF526ULL, 
            0x540FF67C7067F134ULL, 0x19C791159868A6C9ULL, 0x75248922F9AA36A9ULL, 0x461C6266AAB1BA74ULL
        },
        {
            0x52FBAB31FCC2BB22ULL, 0xB482FE097470354DULL, 0x01D319ADA79649ADULL, 0x8EB734039428A38CULL, 
            0xA8C0692A066FAA6BULL, 0x04AA95976C9A878CULL, 0x700417F75A8F1E92ULL, 0x46B42F3636087616ULL, 
            0xC4EEBF95D75C244DULL, 0xCC407A98629149B0ULL, 0x396827EA2F2AF6AFULL, 0x472E08E59375186BULL, 
            0xA2BA0ABAA022DFA2ULL, 0x5F2BFC12932A54A4ULL, 0x2D6D7330EB3A1B4EULL, 0x059530B6E279A130ULL, 
            0x32C399CA940F059BULL, 0xADADBBDD110A7E3CULL, 0x3086A9466B15595EULL, 0x77A7198A6D9A7E83ULL, 
            0x153FB8671CC792D6ULL, 0x3F7603AEF338E6EAULL, 0x6EDFA4BCA94D13A9ULL, 0x1358E598FB57FBC9ULL, 
            0xD4530FC912DFC1E6ULL, 0xCA43BA997555F131ULL, 0x10FB66BD05EC8D9DULL, 0x92BC567BF95E7EF0ULL, 
            0xAA043B2B1FCA0ABDULL, 0x792A793488570BECULL, 0x0625960FD0364D45ULL, 0xF4F21025F0A15000ULL
        }
    },
    {
        {
            0x0CE91757DD1D5DDEULL, 0x7CA16CDE2FABC3F8ULL, 0x6C8840509C08C9B3ULL, 0x7350C4DF338D7ACEULL, 
            0x07B2D0CB7CA07DBBULL, 0x76EA30918854BB49ULL, 0x71F171B74100869FULL, 0x3D0F62C6F1B53E84ULL, 
            0xC61A211E21254256ULL, 0x5E5598D7ED8E7BC7ULL, 0xDEFAE8693A0D5E0BULL, 0xAC9D361CEEBB3E92ULL, 
            0x424D214DC3188468ULL, 0xA6D68D2D5B99C88AULL, 0xD308E5E82AFC6BAAULL, 0x55C10056E19DCDE9ULL, 
            0x0A1088E3AECCDA8AULL, 0x4E34A3BB7BFD7C2CULL, 0xAE18CB0CDAA6E8B1ULL, 0x93F68675974CB8ABULL, 
            0x3419146F90E66C1DULL, 0x3B0B7EA59A279556ULL, 0x0012D303F773E751ULL, 0x4295A149866103A2ULL, 
            0x8F0EF6199E2B5067ULL, 0x8E3E0406F7713D48ULL, 0xC6208BC744E03C2BULL, 0xC9D1A44BCFD3C284ULL, 
            0xAEE813FAF1A677C0ULL, 0x0A650034CD19F130ULL, 0x4D61DE2F2EDD3321ULL, 0x50539AB7BB983710ULL
        },
        {
            0xD96AFA45FA663D31ULL, 0xC752FB0574067E3EULL, 0xD526A7C43B08E825ULL, 0x6900E3BB799AF874ULL, 
            0x46C8C058CCDA7399ULL, 0xE32C39E2E6E1CE6EULL, 0x5D606326FC57EB5EULL, 0x980CFB3B3A117658ULL, 
            0xBE5F40ABAFBC3198ULL, 0xB6FE7003637FA7D8ULL, 0xA16C2317E3C2C0F8ULL, 0xFE9131B806B20F2EULL, 
            0xD6DA89F7A938EA05ULL, 0x589FB070190627F5ULL, 0xB1B657BC228E5DB7ULL, 0xDFE71CB52D8CD1ACULL, 
            0x8BB4EE2111F242E0ULL, 0x792BC8A0FD64DA58ULL, 0x7B656CF7CB0AA471ULL, 0x4C12A6D81DFD20C7ULL, 
            0x60BBBFDB78A7DF07ULL, 0xFBB2B149FE4EADC2ULL, 0x186AD8F9B81AB4E5ULL, 0x4912929C4914D525ULL, 
            0xD1CD54BACFDC0D4EULL, 0xEE85F24451461DF1ULL, 0x8181ADBC4EFB1498ULL, 0x2DCFAEEE90CDA00FULL, 
            0xA8B5AFD6578DD6EEULL, 0x5F15E4BCAA5ECF9FULL, 0xD8CAF389FB812A87ULL, 0x45DB3C3D458E47F2ULL
        },
        {
            0xFB03EB40D284BDF2ULL, 0xF3F0369A7280B325ULL, 0x4A2BF44D7612DEE4ULL, 0xE58B8655004ED99CULL, 
            0x9FFE3D86CF9AC6BEULL, 0x25136BC6A3C4822CULL, 0x52E1C6B1B5A361ABULL, 0xF6EF67F122AE0041ULL, 
            0x51C158E82D98EF58ULL, 0xFC231AB6D0D37F87ULL, 0x78BFEDA3B5AC1E0AULL, 0xCF11AA169A43F44EULL, 
            0xA721B460338D8A58ULL, 0x5D69FE372393770AULL, 0x780645D5BC212E1EULL, 0xA509DBB15559BF25ULL, 
            0xD99413DB3EE1431AULL, 0x79D300B7563DC64DULL, 0x0FD421703DE54C7DULL, 0x9BDC319B052CC506ULL, 
            0x53CD0FF0F4DD880AULL, 0xE1AF33FCBF51BE81ULL, 0xA43AA83F002ED649ULL, 0xA6BF5D6D9A1D732CULL, 
            0x27F043F1CF67EC0CULL, 0x8FBC42D0D0B01DEEULL, 0xCF7563CB0002F005ULL, 0xB57FF891CDFCD639ULL, 
            0x6B6F0FCFBB318E45ULL, 0xD434C80FCE2139B4ULL, 0xD7A97B4CE2972407ULL, 0xC0E1845A98148B61ULL
        },
        {
            0x654A906FA6585E63ULL, 0x516940AC892E59DAULL, 0x864C3036E8DFF800ULL, 0xD4404E242F1CAAB4ULL, 
            0x365746EE6B543A8FULL, 0x1FA81047FE7F1460ULL, 0xD34D52E58A85CFB2ULL, 0x620B2AF7663B4A07ULL, 
            0x7BE26DF8B11F6CA2ULL, 0xF0160185B772B228ULL, 0xEAD132FF00C0D8AAULL, 0x3372AF01B1647D29ULL, 
            0x3609CD123E983C1FULL, 0x83D5ECF57AB5ACE4ULL, 0x5375CC4C9412CA88ULL, 0x57CA778635EEA9CBULL, 
            0x40A84433A3346AB4ULL, 0x759E9B343FA28C8DULL, 0xFE02D8C29CB3A8AFULL, 0x6078B26D508FF768ULL, 
            0x75D368F04D92ABD6ULL, 0x47AC5041590B8CF7ULL, 0xB99C0D293BCD51B0ULL, 0xDE5D73DA846409D7ULL, 
            0x027A938FF05E1175ULL, 0x6A86FC24BEE9E1D0ULL, 0x2732284A3EE161D2ULL, 0x76ED20690A0731E2ULL, 
            0x238FFE1633B74393ULL, 0xDE025A73B7B56503ULL, 0xC3F96CE22F9EAE24ULL, 0x0328F60FAD7206C7ULL
        },
        {
            0x360DCA8C9897EF40ULL, 0x3F795A5AE78A009DULL, 0x0AAE2975B97B3DE2ULL, 0xD5E80317630825C4ULL, 
            0x59087E74135FC92CULL, 0xCAF3113578899EA1ULL, 0x2B94A62BAFBBB6F9ULL, 0xF30C706ADE82EF37ULL, 
            0xFAC455279DBCD324ULL, 0x6FFD0860347B31E8ULL, 0x7128069D15901C34ULL, 0x77F4E50704682229ULL, 
            0xE80EA450FAA694E3ULL, 0xFF67E8A50B796FA3ULL, 0x7467086810DE6D54ULL, 0x3B38459AC2FBA8E2ULL, 
            0x45A00CC694179811ULL, 0xA732EAD1B0AEFE62ULL, 0x15E540D5CED8C594ULL, 0xAD78A8EC07FAD003ULL, 
            0x4CCF7B6B3A49D85CULL, 0x5274C671F8B0A758ULL, 0x5D6AA7DE80CE58DAULL, 0x8883FBB1B1D973A7ULL, 
            0xDCB5459219D12037ULL, 0xEBF57AE7811217FDULL, 0xACFB20B6BAA91DD5ULL, 0xF76D7E9E11D9DBE6ULL, 
            0x679CE0179C168BA9ULL, 0xDCE285846E856D35ULL, 0xA158CEED224B354AULL, 0x8CF0E4225E6259E7ULL
        },
        {
            0x163F8C150A1D3F90ULL, 0x00D48FBED710FB86ULL, 0x917AFC3E80F6DB8DULL, 0x3F456C071A44616AULL, 
            0x54141521444AB7A5ULL, 0xCF95D6CC090CF7B9ULL, 0x28776299CE63409AULL, 0x2B00280B53EDD436ULL, 
            0x0E82C1731F5CD87EULL, 0xDA77E3CEA02D884FULL, 0xDB880F6E591EABA4ULL, 0xD6AA938C2B12970BULL, 
            0x0FAF4B812D4F6850ULL, 0x81EBC9335B32219EULL, 0xA4B65576D7323B10ULL, 0x0F9775EDD8CE5AC6ULL, 
            0x20BC18D7B10D5DECULL, 0xBD8D7DE4A354538EULL, 0x5EC63B9199D89A76ULL, 0x5D06B52759802075ULL, 
            0xD2912C53C276C9A0ULL, 0x81089BD101BC6D78ULL, 0xEFDB89B8CA04C546ULL, 0xB7CAE34EE6F60939ULL, 
            0x9F5980CCF676F2E8ULL, 0x927A3E05172CE9C6ULL, 0xACAB0BEA5B8209E8ULL, 0x34316E881AFE381FULL, 
            0x862A7C891ECB070EULL, 0x53E754540D3E7C7BULL, 0xC91A071C09111B36ULL, 0xCF9BC5D7DDA9148DULL
        }
    },
    {
        {
            0x48C2D674A00687EFULL, 0xF7F70B8FBC5B7BDFULL, 0xA16054CB4E7BE3C9ULL, 0xA4E934F1648E5413ULL, 
            0xCD9F76E75A0BBCA2ULL, 0x9C508BD60D427FECULL, 0x0239110EBCC2F45CULL, 0x918410C7C13F019CULL, 
            0xD43056603ADB3ED7ULL, 0x531352FA2D0724B2ULL, 0x8B7CF2195A1ABDB2ULL, 0xA184C861458571FFULL, 
            0x07FBC75035E6925CULL, 0x5516DF1FBDCE6902ULL, 0x4A329A1CC681D35DULL, 0x1F435E1AB9700DCDULL, 
            0x8D83062DC9243514ULL, 0x3452B174BAD6FED5ULL, 0x72005550AA517A23ULL, 0x8BDC3F4EA3E215B9ULL, 
            0x23B85F6EB3CDD859ULL, 0xDC854A37269686A4ULL, 0x3B5A222C13DC48BCULL, 0x1B295D10BCEFF95AULL, 
            0x3F7B6C18B0688CF9ULL, 0x7287A01996823CF0ULL, 0xBD66CE405447B728ULL, 0x9383944A5EDB1D49ULL, 
            0xB708678019F3DF05ULL, 0xCC69EB784C45FC82ULL, 0x086F3671D19215CBULL, 0x40F65CFF63F6D3C2ULL
        },
        {
            0xAC0D5A790B5C2856ULL, 0x35309124626C2BD1ULL, 0x921BA10419C3A416ULL, 0xEE868F8DD73FE667ULL, 
            0x88AE988B03706122ULL, 0xB532EEA8134F9AB7ULL, 0xBA5819E0435F01D3ULL, 0x88ADAF427EDE52BAULL, 
            0x661422406F1639EDULL, 0xDF36ED5A21788201ULL, 0x2DD0C88D3BE7AAE8ULL, 0xF7963CD24E256EF0ULL, 
            0x69A97E91F0A2CB43ULL, 0x5B98A77F9378EB4DULL, 0x718DAD065E2934B2ULL, 0x00985EC7A595994EULL, 
            0xE3B0584981686DF6ULL, 0x81F80CB0750F99ADULL, 0x1733DFB92ED96EA8ULL, 0x21613F4B1641EF0EULL, 
            0xF8A3D4AA8C1F5480ULL, 0x9A1CC54F22ED55BCULL, 0x9379ADD7EDB76276ULL, 0xB480AB6F92BAE2C7ULL, 
            0x9B04FAAB9BC93C2DULL, 0xA8DE50D654C7C48FULL, 0x1BB7D0AACEBB4580ULL, 0xD11917440CFE2767ULL, 
            0x63DB1B8ADE3B8B1AULL, 0x7E817EE9A528D5ACULL, 0x69C4E1FF82553CA6ULL, 0x2EE75B49040E9970ULL
        },
        {
            0x2EB27B80B00648E6ULL, 0x3ABDF2A732EC3714ULL, 0x486C63827A8B2DD7ULL, 0x29036C27D0D4D345ULL, 
            0xA953BA7D9A874EBCULL, 0xC7BD8F327322FC1BULL, 0x6AF7BA8EC07F03DAULL, 0x3B47EB0401398DF0ULL, 
            0x710BCE255D6886C0ULL, 0x89743D8CFBF6DF6CULL, 0xF7A666A602C13610ULL, 0x5005B8CD6E4DFF8FULL, 
            0xA336CC2B1E13828CULL, 0x9266DF78AC9F9F7EULL, 0xC0DCD2545BFD90C0ULL, 0x2E44722C968F3F23ULL, 
            0xDD185823469F3276ULL, 0xEB71AA04FEDF7C4FULL, 0x80B4966EC553B881ULL, 0x88F965B000922D30ULL, 
            0xEB449E01ABC17DFFULL, 0x547E7E21AE85B44BULL, 0xF6F95175A1481341ULL, 0x37B8E16180826BAEULL, 
            0x669A7C09C35BF160ULL, 0xACAB6BE48F853185ULL, 0xB40B8D9E8DC21BECULL, 0x36FA633E9AA8CB3FULL, 
            0xF60173BE23AE1083ULL, 0xF24E1B7987CEB169ULL, 0x59668FD02986C02FULL, 0xEAF6FFD4C057A7A9ULL
        },
        {
            0x722CAAAA46A35A2BULL, 0x19BD763077658F04ULL, 0x5F78FC894235278FULL, 0x6303BEA42A93842BULL, 
            0x983E30D5B08571B0ULL, 0xFE5719D649B1C4CDULL, 0x50F5A1D5BDEC637FULL, 0x58CE94E1AA5CB02EULL, 
            0x389365FB9B5FB2F4ULL, 0xA337B7BD4448492CULL, 0xAD47EDD0369E6E6AULL, 0x597C1D93D6A55607ULL, 
            0x8B3643FB1525995CULL, 0x845A4C0BDC1A24CFULL, 0x9FF9A5CA6734227BULL, 0x6C2D990190D932FBULL, 
            0x4D1CEC352C017C62ULL, 0x15DA944373275737ULL, 0x10CCD4100D92154CULL, 0x1D122329E24825E3ULL, 
            0xFF20C5AE191A8637ULL, 0x20FFA80C24E063B3ULL, 0x21CAB3EC726FDA06ULL, 0x6C82D964C1E1C920ULL, 
            0x93E8A313710C4F1FULL, 0x6A78FF69A32424ACULL, 0xCCC1E4651C587809ULL, 0x855D3ED0D8732326ULL, 
            0x2240C738A4B5A972ULL, 0xF7A7F44522D1511FULL, 0xB42514E8D343416DULL, 0x59BB70B1D170FB0EULL
        },
        {
            0xAF2328904212C971ULL, 0x6471BC8C74FDE205ULL, 0x73A69DDF7B66CFBCULL, 0x6AFB4AC53A97B242ULL, 
            0x6A9EEEE34FA97F6FULL, 0x859A52307342D60CULL, 0x1ECFC24C6B913768ULL, 0x59FDA23FFE3CCC16ULL, 
            0x5D1DD8C006DBE3DBULL, 0xE4E09B392BDA488BULL, 0x1329CF62DD432BBAULL, 0xDC8C7D7370A3EE3DULL, 
            0xE278DDBAA184092DULL, 0x21130A0028A4EAF6ULL, 0xB31ADCA5BB5D986DULL, 0xFF4A2E9E5B7B0C68ULL, 
            0x1C9E9A7ADCF452CAULL, 0x0A823F91EEDD8E93ULL, 0x8F5030BE473A50B1ULL, 0x6F60071A90FABE5EULL, 
            0xB22C2864A3507FF5ULL, 0x11E592BAF00AC7CEULL, 0x50D7FA84EA0EC3D3ULL, 0x9D6180D55F5EBD5FULL, 
            0x73ED38C2AE326F4FULL, 0xCA23C6299D04E8AEULL, 0xB93A93A39C8A66E8ULL, 0x88468B1D371BF536ULL, 
            0x815700AB53430E23ULL, 0x68114907B18302AFULL, 0xDCC428A692D077A3ULL, 0xFB52D9F0D9340E4EULL
        },
        {
            0xB6BF2C6265C21F96ULL, 0x1BC0A47DEB874A37ULL, 0x38C7531AAC36F07CULL, 0xE2BDF8D25E0A3F1BULL, 
            0xD811E86C29B72477ULL, 0x54EC3F06055C8112ULL, 0xF8F182C7D7EE8C20ULL, 0x53AD3CE6734DD642ULL, 
            0xA7BFB1D58B4B3AA6ULL, 0x70C86CABF09EBE83ULL, 0x775F5479ADC0F863ULL, 0x93346984081F8D0CULL, 
            0x84CF79D7AA2C6B12ULL, 0x8682B2D837A797ECULL, 0x4C3C39D5387EC752ULL, 0x5134C632775EE18AULL, 
            0xA4121A15DFEAF23AULL, 0xD52913D6F7921674ULL, 0x5E288A9045741AE3ULL, 0x7823DCF7554DF8E6ULL, 
            0xE7F14C8E71F681E4ULL, 0x85D333F8B2B20E6FULL, 0x2D7FA1423C483FD4ULL, 0xD4EC86F4F72504ACULL, 
            0x2DFC2FDF75E42DB7ULL, 0xF097F3ECA8E24822ULL, 0x765A45434A0DAA85ULL, 0x113658C992EE916AULL, 
            0x1C6A4AE711DA354FULL, 0x67C1E164B00319BBULL, 0x13EBD65B2B138F6BULL, 0xEC2E470135496773ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseDConstants = {
    0x6CF897067E67F87DULL,
    0x6F6D10794A2E09B6ULL,
    0x8FC82B2CAB99626AULL,
    0x6CF897067E67F87DULL,
    0x6F6D10794A2E09B6ULL,
    0x8FC82B2CAB99626AULL,
    0x2A5A522E8C9E4091ULL,
    0xD2C19955E8C51BD5ULL,
    0x2E,
    0xEA,
    0xF5,
    0xB2,
    0x8C,
    0x75,
    0xC1,
    0xF9
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseESalts = {
    {
        {
            0x8F2BE03E914F5943ULL, 0x205A915CC15B797EULL, 0xD53855EEDAD09A64ULL, 0xE0F50F92BCB83BC0ULL, 
            0x8DDC290F731C8C80ULL, 0xD19863CADC69B886ULL, 0xF5518E7609B75B4AULL, 0x8532D56FFF182942ULL, 
            0xB531F1DFA7EC8790ULL, 0x78FEDF30D5826C7FULL, 0x8325E9113CF9654AULL, 0xB2274A8664B6948BULL, 
            0x6F4AC935819917E1ULL, 0xC80801D6B562078AULL, 0x9BCBC48160A6B145ULL, 0x8D038D701F1BE4D7ULL, 
            0x36D46FC3D2761B65ULL, 0xEB20CEC2A2B8E23CULL, 0x089E5A1DB74A11BDULL, 0x388355EB91C52AF2ULL, 
            0xE7C3C4ECC2ED4243ULL, 0x0076A00EE42F6ADAULL, 0x4E27F0C4A1A37DE1ULL, 0x1E5DDBCA6EA293A1ULL, 
            0x9AAA1B04E0A0FF98ULL, 0xA3867DB7F99FCD88ULL, 0x23EC5B42367E487BULL, 0x4C1F2679DAE80DEAULL, 
            0x15D8F1696A5D4EC3ULL, 0xB5B126F94BD7E940ULL, 0x1C82D5DC55E88B72ULL, 0x2B9A8E689ADEB7F3ULL
        },
        {
            0x3E0F7F2CE21D749AULL, 0x401970A5FD555538ULL, 0x4DBEAA2EB50CB1C7ULL, 0x083760B4041CFFA2ULL, 
            0x0CDB79BF33E0E030ULL, 0xA2375C821361ADCBULL, 0xF78AA435D99BAD57ULL, 0x22904BCA6479F906ULL, 
            0x4E1D770B906FDB9DULL, 0xC28EE81AD3F1C2D7ULL, 0x70B1C1DAE444F8DFULL, 0xED825A4AB8A51B9BULL, 
            0x7CDD044D92046F8FULL, 0x1043DC297C5A8149ULL, 0xD98F31DFF73A2694ULL, 0x6663FB1D6AEE07D8ULL, 
            0x03CB50206017807EULL, 0x672818E0C143D68DULL, 0x8BD471DC0B8DC7CFULL, 0x20145DCDFCBC900AULL, 
            0x2573FCEB2EB98950ULL, 0x1FED3EA911C04A94ULL, 0x3DD3FE23EE0B9748ULL, 0x9C7651E08FA5B1ECULL, 
            0xC7EF640C2AD98961ULL, 0x4822BB5531EA29BEULL, 0xBA8B2D880D108B0EULL, 0x58284568E76F2787ULL, 
            0xB9FCD8A940829C06ULL, 0x4E81AE09FBC27781ULL, 0xB7FA5CA1D5D5355CULL, 0xCAD867D8E2FF6912ULL
        },
        {
            0x535D657DBB229174ULL, 0x2EB436502208A9EAULL, 0xC6207CF9F24A0352ULL, 0xD6CF182DA29A75DCULL, 
            0xBAD901657AA17D46ULL, 0xEE24BDDDBACE3BD5ULL, 0xFE65A2850875B2E6ULL, 0x02ADFC6468579C37ULL, 
            0x0281E38D7E988A9CULL, 0x8A7E38483016B2A7ULL, 0x1BEE4C0283E8A40BULL, 0x4C23BCB8630BF9D5ULL, 
            0x656035D91B8819C2ULL, 0x05722174AF96DBE0ULL, 0xA487063B63E9F39BULL, 0xE81E27EA4D5C5664ULL, 
            0xD11AEFE1292DD1EFULL, 0x538449ED8F0A6648ULL, 0xE3F1C8CBB4E8CCB2ULL, 0x3DE39C5BEEF7AC76ULL, 
            0x6DF642037FD006E7ULL, 0x5BBA5DBDCBA21920ULL, 0xE64A5F1F21FE9545ULL, 0xA28D1EDDD23C1BF4ULL, 
            0x7020AAFB3C426F8CULL, 0x995A4E03D485578DULL, 0x21280873941FF25CULL, 0x314EF2CE36D6F5A4ULL, 
            0x2BCB355D6B30B5E0ULL, 0x9DEEF3F760B85205ULL, 0x50CC87303AF1A6BDULL, 0x9EDC7D944BC12BB8ULL
        },
        {
            0xD8BF5F240E12A1FAULL, 0x7A1B82554B3ED6EFULL, 0xEEC54221F237A068ULL, 0x21C7254BBCBE8AD3ULL, 
            0x3D5C1E615FED97DDULL, 0x0B829FC2FC679852ULL, 0x64F40D874EECDDF8ULL, 0xCCF91FB232532A4AULL, 
            0xC1762103F585F2DCULL, 0x29915EF62BD71244ULL, 0x18217C0E6AD55D45ULL, 0x028B0D78EFC3E5A7ULL, 
            0x6202050F69E2B32BULL, 0xDDC4E2F4BCA94BEBULL, 0x38348295C7D11735ULL, 0xB637CFABD181E6B4ULL, 
            0x8B8E9653C82D69BEULL, 0xA49E65F90D54B8F1ULL, 0x9016DAD354EA5F92ULL, 0xF0EDEA156BAC0AB6ULL, 
            0x979E89587019ACF4ULL, 0x0F244E8238CF516AULL, 0x14CBB4AE8A840DA3ULL, 0xAA6F993AF1F32BD4ULL, 
            0xC719E6E231AEB685ULL, 0x41BCAAD8E22AB2C7ULL, 0xDC23386C2D81F94EULL, 0x6FACBF54AD9213E9ULL, 
            0x450268A6975E72EFULL, 0x35EAD0CD4DCDC386ULL, 0xC4F835E0A2C95118ULL, 0x246B0277F887C384ULL
        },
        {
            0xB528C83A85653CC6ULL, 0x49BBAD97BCB060CBULL, 0x1A65C10CBA0ECE90ULL, 0xB53A811E69A92532ULL, 
            0x6D133B0F0CD76F5DULL, 0x86998F36D3C83EEBULL, 0xB27640793F26E386ULL, 0x486968F3152AF64EULL, 
            0xA0489EF7A340FC7FULL, 0x41AA69FF60C667D4ULL, 0x6E7A080B54F5DAC3ULL, 0xF540CAA68E1F3125ULL, 
            0xF9122FEBCCDDDD9AULL, 0xB07B85EAB01286BEULL, 0xB9CC36417FCC556FULL, 0x064BBCC414CA3020ULL, 
            0xF9EAED152AFC6D8BULL, 0x208E01E5AC0508F9ULL, 0xA54444568C9F9BCEULL, 0x768E5685441B2FB9ULL, 
            0xD2BE759A16451761ULL, 0x2EA20F6373055143ULL, 0xFA26CD1E3335CAA0ULL, 0x4F39C63BA8820C02ULL, 
            0xD4E2A9508C45E502ULL, 0x3D25D6E78C035EE8ULL, 0x8AA4F067290B0537ULL, 0xDC037907B255B9BBULL, 
            0x71D312B0355BF8D7ULL, 0xEF406DE8DD4A2352ULL, 0xEDFE1C90E0CCAAC6ULL, 0x49A00BAF4E8993A5ULL
        },
        {
            0xD5543BC8AD75A426ULL, 0x4D21A4FD4CD5A514ULL, 0x0E9CF287784E9425ULL, 0x6967487428921739ULL, 
            0xF12822B2180FC21AULL, 0x8F827086DF270BDEULL, 0x72EEEF59F5065149ULL, 0x6721C3FAD49CB28BULL, 
            0x67F13E03D791A487ULL, 0xB77C1C64A1EE5B78ULL, 0xE216A8E465035883ULL, 0x67BCB9C78C85CFD1ULL, 
            0x8BC3D903F06B551AULL, 0x55B05F3622438EBFULL, 0xA3796BEFD24A96ADULL, 0x8F86EF56DB64D24FULL, 
            0xF67B8B4B993F4206ULL, 0xD5BF2D55A82810BEULL, 0x88B04A17E7A5DDFEULL, 0x41DBAF53CBF7DE08ULL, 
            0xCFBCE294FFD0F194ULL, 0x64942270C5667A60ULL, 0x9A8D7EB0250861C0ULL, 0x8ECC15AEE9F9C4DDULL, 
            0x879C22EEC429E0ABULL, 0x42258E224A6E706BULL, 0x78B4899E36462555ULL, 0xD769F8A764F281AFULL, 
            0xDC50B70208623207ULL, 0x1D75D86A7093A4A9ULL, 0xCC6AB0DB3994B1B9ULL, 0x296BB156B7286E55ULL
        }
    },
    {
        {
            0x99A38BFF49A2F2ABULL, 0xD62C3F14ABD1C6C7ULL, 0x095A6060F11111A7ULL, 0x8D848471CE1E757AULL, 
            0x7F1916E31120E069ULL, 0xE739D0E5E639AEA8ULL, 0x8390C658B76B2644ULL, 0x8A85011EDA364E78ULL, 
            0xAE0944CE7665364AULL, 0xA71552CE8BBD7307ULL, 0xD40F905903FC0838ULL, 0xE495F0B2C730AFB7ULL, 
            0xE487C5E6B14C3B28ULL, 0xF3FFDA2930A3A609ULL, 0xE445CCF3652F3991ULL, 0x35ED784FAD3F3FA0ULL, 
            0xB51990C916FA6D9FULL, 0xACE6B80A8962475EULL, 0x7F7C865441CFBCAEULL, 0x4C32EA2A0E10B9A4ULL, 
            0xEDB36BE0EC56FDBAULL, 0x6D468D22FF664ADCULL, 0xA305170585781129ULL, 0x26712F365CB4DE16ULL, 
            0x113E43D1CDCF6203ULL, 0x6E1BFC3F0F26826EULL, 0x47137C3ECE447057ULL, 0x0105B54624F70B2CULL, 
            0x22C2F4BA7F32D6C9ULL, 0x03834060CDD60233ULL, 0xE75C0BD7D68AD0EAULL, 0x41F16A4CF961B255ULL
        },
        {
            0x626BF7C617790E78ULL, 0xBFFD9A03F19DA055ULL, 0xA3158CEC57597EB3ULL, 0xB4C04EE191B99FD8ULL, 
            0xCB65FF23F67A11CDULL, 0xCAC85B502CE9A5D9ULL, 0x5E9392481B232CFEULL, 0xF6BEF7FB61981A54ULL, 
            0x25C778DB3551C1ECULL, 0x1AAA31BA94F03251ULL, 0x2F0C59E054319B0EULL, 0x2C795175E305A5D8ULL, 
            0x746197887F32BFDEULL, 0x14987FC6E2FA9FDFULL, 0x394FC19D00D887BDULL, 0x7144FD5841EA4A70ULL, 
            0x8DF5A783F01212FFULL, 0xE2E8C5DF67B2D8E3ULL, 0x99CCC4A7BD042492ULL, 0xA856F0DF635EF96DULL, 
            0x07D886CF8A758027ULL, 0x2C6DECC7FE0AE23FULL, 0x12CA082B47BE2BF7ULL, 0x33F96030E38EAB9EULL, 
            0x543F52B03E1444E0ULL, 0x6A36EFE747A2C576ULL, 0x3B190229FBEF6B8CULL, 0x0CF0724ECC16C3C3ULL, 
            0x41FC17576FAF77BCULL, 0x544B9553DA6D3329ULL, 0xE348A47F4854BEAFULL, 0x70609CC86336DCEAULL
        },
        {
            0x10E4B808EADCFD9DULL, 0x91AF56139C99E159ULL, 0x70691F416F66D279ULL, 0x4539DBCD3B932850ULL, 
            0xC8D35E952AFAB133ULL, 0x5A4E4C7F2DAA2179ULL, 0xE3D3C38B5220B5AFULL, 0x022F772E29351BF1ULL, 
            0x4DAFDB346CE72E4FULL, 0x90DCBC5D0153CA94ULL, 0x66592FD80A597EECULL, 0x8B0AD7B8A5787C11ULL, 
            0x375FA713863A33D0ULL, 0x4A528DDA928EABB7ULL, 0x60C4314ACBB18F24ULL, 0xF4B24E37C294D722ULL, 
            0xD0DD36B38827FD9AULL, 0xF08B33147CA6DC3FULL, 0x9C428D7D17881222ULL, 0x2973337B279402EAULL, 
            0x87288A2238670122ULL, 0x4DED5D6375322154ULL, 0xCEC4E28D97E4C4E9ULL, 0xE0ABB60DAC470256ULL, 
            0x09DA4B42EC6C34F3ULL, 0x15FBD2324BDEB4AEULL, 0xAAC091A82BC9E6D5ULL, 0x83CAEACA4BC9129AULL, 
            0xC67793E9A75A3183ULL, 0x1E34DC739C645B02ULL, 0x9EABA2CBBDCE30F0ULL, 0x32FF892FFE9CEFD8ULL
        },
        {
            0x9A83D83F4CD95CCCULL, 0x5FBE29BEC2F779A0ULL, 0xA11A5F2D455805C1ULL, 0xE3E2D857863BC6C0ULL, 
            0x2CE1DD54ACED2C4EULL, 0xBBE94E55E3D10474ULL, 0x0F679FECE580A8EEULL, 0xF25F9D19A1DC0D85ULL, 
            0x104345413669908BULL, 0xC9E9CCF0155A1066ULL, 0xE9759639CC85C207ULL, 0x7EFE3B7B22BC5B14ULL, 
            0xA53B698065734A32ULL, 0x015A2542560D39CAULL, 0xA15ED48B1D173027ULL, 0xDC2FFD4C896164A3ULL, 
            0x8E1D51D133619636ULL, 0x4C0C05B6D73B3EA6ULL, 0x9593D8D5C47C40DAULL, 0xA48ACB2054370134ULL, 
            0xC74341AF7C2C05F5ULL, 0x23B23D3C3A8A1C7CULL, 0x7915488B9BC77B85ULL, 0x252CF3B6937E1725ULL, 
            0xCBCE304BE9A276C2ULL, 0x158455A6F180FCBDULL, 0xCBF63DC848173546ULL, 0xAAF9E119A65C9138ULL, 
            0xE6013FC68C413A43ULL, 0xF82B45C46198D54AULL, 0x1274D879CF2F1E97ULL, 0xAAD4AAB4C71884F4ULL
        },
        {
            0x296C5CCCD36D80DCULL, 0x8BE9DC9309A66EECULL, 0xB95E64DC1E8491C6ULL, 0xF9B3E54CFAE11AD8ULL, 
            0xDDE88D5C9DCB3977ULL, 0x2B1B0CF73880AC6BULL, 0x434B89E58BA73464ULL, 0xF5DC12F69E89704EULL, 
            0x1053DF599DA93C36ULL, 0x720C212CD0D499CAULL, 0xF5B9D1050BC8D860ULL, 0x94A0D1798096A069ULL, 
            0xDC7A39184CC9C255ULL, 0x3F9AFBE1D35CCEFEULL, 0x62D9798C80D93A8BULL, 0xD4A9107BC13BC9CEULL, 
            0x25954D706FA5F0ECULL, 0x1397148C32E1FC2BULL, 0xBD08E17A0B5D322EULL, 0xDA6B6DEC65922AD5ULL, 
            0xC523CA2FEAEB214AULL, 0x2A07B402B4D044A4ULL, 0x00912656D2F073B8ULL, 0x1D820C557F7BB751ULL, 
            0xDC838A70B0600838ULL, 0xF66DBB1EA9B3A5B3ULL, 0xBB79CEE7B190945CULL, 0xF23FFEE372E43AB8ULL, 
            0xDCC6F67B79C1B88BULL, 0x460ECA8F2091BCD3ULL, 0xAA5AD1F7DD2BBD99ULL, 0x33D18EA57E010D64ULL
        },
        {
            0x1ACB999E6741C823ULL, 0x8516A6D457D6F10AULL, 0x89B5946611CC9E91ULL, 0xD30324E9BF358873ULL, 
            0x3FC8696E444CA59FULL, 0x5CFDCB7FB81F6C24ULL, 0xBC02B25D5752CA4AULL, 0x549E8C6195FD0AA6ULL, 
            0x77D5B1A5F2BFA50EULL, 0x879C63C514622F6FULL, 0x1EEADB50EEEE9565ULL, 0x04B5FCCF6220BF0FULL, 
            0x11763E5BA75DE887ULL, 0x5D04B450B7CC5947ULL, 0x828E9E4962BF4CE7ULL, 0x3C3FBA440B898905ULL, 
            0x5B96B0DA61D9B506ULL, 0xABC4C3530D40FA8CULL, 0xE006E90305CA32DCULL, 0xEBC82DCD6420F360ULL, 
            0x8987AF7C99DC1784ULL, 0x048A00F0F5A14B9CULL, 0x71E49B1CADBB2C57ULL, 0x4BF9B2485DCF169BULL, 
            0xBAD64D5C2DD25C00ULL, 0x3EAAF894761D300BULL, 0x17CC0BCC595F3237ULL, 0x49296A40AE889C82ULL, 
            0x107B0247DB519251ULL, 0xAB6356C613E72685ULL, 0x8F6F9741EB9FB55BULL, 0x7F8703CFC07EF4E8ULL
        }
    },
    {
        {
            0xE55B8E00B1991134ULL, 0x826AB363CB7C891BULL, 0xBA92322D2CC09AF1ULL, 0xAD612433BE81C549ULL, 
            0x6614B3BFE8234786ULL, 0x6CF8A2AFF69B6C0FULL, 0xDBD4903D036606B7ULL, 0x04763A2C8BD9D486ULL, 
            0xFC5857F74644AD82ULL, 0x5701DE04532A5EC6ULL, 0x3373AE92C8025B79ULL, 0x1CE2AD355FA09AC2ULL, 
            0xCC7545A553462534ULL, 0xBF78AD2DD07568C9ULL, 0x9373EA42B5DE6C27ULL, 0x82131B6838E7DA2EULL, 
            0x95532F88F5443618ULL, 0x00349341AFF4DF47ULL, 0xFC53C6DD79BFEC0AULL, 0xBA70B56D62B279A0ULL, 
            0xBEB08BE31BDEC787ULL, 0x55E4F67BF4238DB5ULL, 0x4D29C60ED924467BULL, 0xD17FE5D3B7EA394BULL, 
            0x323F0357CA5F31B1ULL, 0x5DBB2E73B7ACDD42ULL, 0xC0205D125CB3BA4EULL, 0x78C5A06884781C52ULL, 
            0xC7D2DA83E1938D3FULL, 0x2A23798BB79B5436ULL, 0x3626DC57C2DCA0B6ULL, 0x91A10DFE47B819DCULL
        },
        {
            0x9836F4A06054376DULL, 0x0275B59D002E158CULL, 0xEEF3F79679F379A4ULL, 0xC0F67AC9A2B89E7BULL, 
            0xE1021E6EE25426EEULL, 0x9E5A0E56C88D6B4BULL, 0x8CB546F654F72EBDULL, 0x816A9782E9DB1771ULL, 
            0x9C35439A97BEAFD8ULL, 0x441B41D2030FCE52ULL, 0x820A98F9EE284B20ULL, 0x1FC8896819715769ULL, 
            0x5931BF9758E1EF96ULL, 0x2F335CA7E2E642DDULL, 0xF2B2B194E6932C28ULL, 0x2F05100892AF2AC7ULL, 
            0x0CE2F7A598D0FEF6ULL, 0xD3796C80C36D6C8CULL, 0x7E09773DA14C2947ULL, 0xD9D12BC74529895FULL, 
            0x18EBC3BB21B7637AULL, 0xD45581A1ADE423E9ULL, 0x162C27C14C7945F0ULL, 0x060BFF0BB6FA9989ULL, 
            0xB18384C8CF0F45A3ULL, 0x93930518D8D793B2ULL, 0x4CF8227EDFAB08A7ULL, 0x80DBD3279E20267AULL, 
            0x2B70247A8B2C210AULL, 0xF3043E7BC54B27F0ULL, 0xD8F50EC695BEA981ULL, 0xDF1A6A00C855BC16ULL
        },
        {
            0x33F99F846821DAECULL, 0xB32436D0D8C0AE97ULL, 0x8923FB2DC1F74339ULL, 0x8E5AC98A9D18BBFAULL, 
            0x74D0BC6B408F2F74ULL, 0x4735B67A69A8A1A2ULL, 0x462419C4372A5D9EULL, 0x006CBB8AFF3B2E59ULL, 
            0x86C31D21942AF63FULL, 0x37E6FA75CDE34259ULL, 0xA577E050818DAD80ULL, 0xDD0B7355C7089B09ULL, 
            0x8AA3AE43E4AD5928ULL, 0x3178F5F7046575B8ULL, 0x1AA1B8AA760CF117ULL, 0x6CA0EA1C8AB4206BULL, 
            0x94C64FC7BF881641ULL, 0xC126BC68C3B77BEBULL, 0xEAF86CEC48DA4AD8ULL, 0x620A6B73C0D92E93ULL, 
            0xFB6B83CE783D49A0ULL, 0xE22C348050EBB720ULL, 0x2D730DBEC8D08982ULL, 0x28E4826846C4E196ULL, 
            0x2115848B5506FF96ULL, 0xD2DB83E124679F91ULL, 0xFFBABA3906EF22F1ULL, 0x023118F2A7D34FF5ULL, 
            0x87D4C3BBFAD2E6ECULL, 0xFA171CFB20FE44B7ULL, 0x9F94D0A3FCEA1AAFULL, 0xED8C8B96B1C8F7F1ULL
        },
        {
            0x5FE6D893EF3AF97CULL, 0xD12555E632CCC80FULL, 0x301DAE592F83DA66ULL, 0x2905351714CD5496ULL, 
            0x68BBC934C93FB12EULL, 0x229214BEE83331B3ULL, 0xA23E450D881CE2F1ULL, 0xD2DD152EE124D549ULL, 
            0xBB4607E3B8C8DB08ULL, 0x44C4E1B406D9A8D1ULL, 0xF6EF63AC9C72C29FULL, 0x7250EE7D6816E9C4ULL, 
            0x40C996D2DF937DAAULL, 0x5EDE0B1E9B767501ULL, 0x03BFBD1C361F302EULL, 0xAD860574E6B8DD82ULL, 
            0xCC18EB3A9749F72AULL, 0xFCE59A0C8CE7628BULL, 0x8959F0AD89855761ULL, 0x2BBDCA46720B7271ULL, 
            0x878199D90FEBF430ULL, 0x0FA8B4E08FCFF47AULL, 0x72C6779C512C2681ULL, 0xFEB0574727C4D0DFULL, 
            0x79DC60D281E3C76EULL, 0xB7BA7F88579ED796ULL, 0x5E035A3328A30FB6ULL, 0x9600BC61E33C0CDFULL, 
            0x500372EF4C937E26ULL, 0x19EA7C6FCC85C248ULL, 0xFE4A4AAB1CF1A38EULL, 0x176D68E131AD3C19ULL
        },
        {
            0xDC09BF536C515AF3ULL, 0x9990E32CC9B46340ULL, 0x937695236BF6248BULL, 0x18F9C1F402D5E835ULL, 
            0x5DC74EE6716177A0ULL, 0xFF548AA8B2D1BFCEULL, 0x7BEF72024E4CBB77ULL, 0xCB159442EB156D23ULL, 
            0x4455BF25C399DD95ULL, 0x697CADC5290C04B1ULL, 0x5026A5E1AB52C990ULL, 0xAE935EC8B00DBCF0ULL, 
            0xC355F9576B61754EULL, 0xF6ECC193C2B30CA4ULL, 0xE9A28AA4E2199F6FULL, 0xE429347D42F7A0FCULL, 
            0x1B4475C9364ED9C0ULL, 0x56525ABA92532E95ULL, 0x72C7C1ED6C2A92D9ULL, 0x57B5CA7658943866ULL, 
            0xD10DE8B2736B3F26ULL, 0x227FFBFD1C7A22E5ULL, 0x24F2BC38174CABFCULL, 0x421AFB1CF65D3CFAULL, 
            0xC8497DBE4B11E916ULL, 0xE9B8C404EFC3A6B0ULL, 0x892010CEB70FCD13ULL, 0x950AA202088A14B6ULL, 
            0xEB0E58BCDCF8286AULL, 0x4547E13A210E7CA1ULL, 0x685A87AEE6178616ULL, 0x4D8952BA7BB8940AULL
        },
        {
            0x6DB8FCF8D8AD5D0EULL, 0x025909A4331C01B0ULL, 0x7194F63B8C47B8E3ULL, 0x6C3FB66B8F661D7FULL, 
            0x5C533E8956146572ULL, 0x31B30A9C1892A053ULL, 0x9349FABE94E177C6ULL, 0x3B0DEA10F6BD9F1FULL, 
            0xD2A9AE1351932E60ULL, 0xC0793A5095FC6D3BULL, 0x063BA7736CD2B2F4ULL, 0xE7DF50F14BEFE59CULL, 
            0x525472E7B0C83C7FULL, 0x28E74BFC3A403BC5ULL, 0xC99EE58D7C19C7F2ULL, 0x0C1FB2628D74B25EULL, 
            0x9268D4EA6202170AULL, 0x499BC3144F4BBD4AULL, 0x3605B7D98D5C3738ULL, 0x8E68DAE2641A2739ULL, 
            0xCC5983F6BD2D989FULL, 0xD9082C29BC984B66ULL, 0xA8A91E293E435C7FULL, 0x99DD67A51310F1BBULL, 
            0xBDA382B8A6087FF6ULL, 0x702844A5D91CCF67ULL, 0xE2A0322A3E03256BULL, 0x20D8D027C62EF91FULL, 
            0x6507A34BEE53E609ULL, 0xC24F40B28C37C9F8ULL, 0x56C45080EB809D57ULL, 0xF0563E50879E9E12ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseEConstants = {
    0x77566EFA2DF51C49ULL,
    0x7F8F1FAF4900B842ULL,
    0x476698C2C5DBCAFCULL,
    0x77566EFA2DF51C49ULL,
    0x7F8F1FAF4900B842ULL,
    0x476698C2C5DBCAFCULL,
    0x5F051D0820315108ULL,
    0xBDA448A0363B5E24ULL,
    0x77,
    0x68,
    0xA4,
    0x36,
    0x47,
    0xD5,
    0xD0,
    0x92
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseFSalts = {
    {
        {
            0x993AFD3FCF17AE82ULL, 0xF7C96105684676C6ULL, 0x4F73CC1B4DD63AE0ULL, 0x96D0CC9394A56DE7ULL, 
            0x786A746D0F85D51BULL, 0xB9F3717988B1F0F1ULL, 0xFB3BB661E9722272ULL, 0x650478A79EE78F37ULL, 
            0x40627CA0D25C91AAULL, 0x146B23332C717B06ULL, 0x837FF5CE5E0FB5FAULL, 0xC82BF6456A292877ULL, 
            0x166F23AD9A96F7A2ULL, 0x02817BFDCCCA021CULL, 0x39511E59DA5FFAC6ULL, 0x09F1FD0FA83F2001ULL, 
            0xEF1D6833FD896931ULL, 0x73F57B67D4B16A3CULL, 0xAA303A9F11FF69EFULL, 0xF4328100F843B5BBULL, 
            0xDC07C3F960660286ULL, 0x781D81CDBC348273ULL, 0x0CF261ACF3800297ULL, 0x1361CB97F034B05BULL, 
            0xC101BD1CF379CF0DULL, 0xB41638DB162CA272ULL, 0xA60D37AAA2B8A6C6ULL, 0xBD0A63028F5EB98BULL, 
            0x79BFEE26F3C2C602ULL, 0xCE49AC2F0B0239F4ULL, 0x799B7A3E3B7B6B65ULL, 0x7098EA0E9487063DULL
        },
        {
            0x2B2D1BA7C1F1E520ULL, 0xC9666577F7706991ULL, 0x65FF45D0ABF6AC2FULL, 0x2B6BA0CF083D0DA4ULL, 
            0x27F742D242844201ULL, 0xEEC5BD7443C447F0ULL, 0x3FF9F5FC2ED064EDULL, 0x546DB83B352746D5ULL, 
            0xAD24F868E8EB4548ULL, 0x8FBDAF41BA9B0421ULL, 0xCD2ADD3AFA41EDA0ULL, 0x8C3CF762DB06C807ULL, 
            0xEDB975198D0A8B03ULL, 0xE26F2B329BA61E05ULL, 0x83DB089E511C7515ULL, 0xB8436580D9E6E90CULL, 
            0xC42AF6F75A5DAE26ULL, 0x878474EB851FAE14ULL, 0x11D29BEA952F7DC1ULL, 0x823B8757DC0C6AA1ULL, 
            0xFF3CC277F20F353CULL, 0x96EC5DBCAE25385CULL, 0xC41DC7CE67635218ULL, 0x89257598F8E1CF23ULL, 
            0x5A25993F513BD731ULL, 0xC6E34562D0F7C524ULL, 0x5C234A7DA4ADBC60ULL, 0x148B0BCF8C5E48FEULL, 
            0x4CA38E763B8CAD2DULL, 0xDEE4DDD61D975F2FULL, 0xEC9F60944685C057ULL, 0x4915FFA5137103CAULL
        },
        {
            0x2FF2F9371C3EEC41ULL, 0xCDB36CF616AC8C29ULL, 0x22A5958D409A0960ULL, 0x1E913B13DA5F314BULL, 
            0xE9CE2F1758D2203BULL, 0x7C8A1D8865254AC7ULL, 0xBF9C33F6A7F39703ULL, 0xE9705FE65E9783D2ULL, 
            0x5783314350D6E768ULL, 0xB4BEE127B1A5F13EULL, 0x269BE563CD360BF1ULL, 0xD9B4E68FD6F083D8ULL, 
            0x4CCC316F3EB2B3CBULL, 0xFD0B5DB7021FCEE4ULL, 0x57C375AF0F446805ULL, 0x4D990836E4842215ULL, 
            0x9B2F0D8DA8557828ULL, 0x850C238758C51FFEULL, 0x26BC350CC33CD470ULL, 0x2FF5FEE8B021335DULL, 
            0x2C26A06D5020A616ULL, 0xD79D534D91168A54ULL, 0xB0FF1950C06398BAULL, 0xC5619C932E77D3A0ULL, 
            0x7CC22E55A289D3B2ULL, 0xD86D0E032FD4F351ULL, 0xBB7A6F2332655983ULL, 0xA11BF97AEBE23337ULL, 
            0xA62770EB30534ADBULL, 0xAD546FDD55BA4A0EULL, 0x2900867E7D414656ULL, 0xA4C0B6B944B7DF02ULL
        },
        {
            0x694F5E949939013BULL, 0x51DDFDFA3BF15CB4ULL, 0x6A8AD55EC311F5B2ULL, 0x38F514160D1FA872ULL, 
            0x6864F00AE2F61D3FULL, 0xF0CFC5B4DB7D59ADULL, 0x6A075DFE38C9B60EULL, 0x6EB396EB31E57E4BULL, 
            0x0D13711EABDE5044ULL, 0xF6992FD83F77E72BULL, 0x8C6B02D13D44F61FULL, 0xBA13DAEBC769C415ULL, 
            0xC055B2ABC3AD88EBULL, 0x426A9F3F881C63B9ULL, 0x26A0664229AC74DBULL, 0x58F075620E7146BEULL, 
            0xE64D373D06EAE238ULL, 0x674500519D1AE280ULL, 0x4FBEA54AD591521CULL, 0x29F7E401BC51BC64ULL, 
            0x1C61D4FA57B5B6F0ULL, 0xEF9FCBB0707D67D6ULL, 0xB16AB4155FF778ABULL, 0xB7D19ACF03672BCDULL, 
            0xB1C1C044ACFFDF5AULL, 0x4FD862C82D8B985CULL, 0xFF380C510F7C6E3AULL, 0xB8537B2F996B5887ULL, 
            0xE9BC73AB624683C3ULL, 0x26B148FBFED2C8FCULL, 0x8324A5327806BE78ULL, 0x93FE904CB942D022ULL
        },
        {
            0xACA6754F497FBE6DULL, 0x20D736EE43DB9B7DULL, 0x0A58DB3D8B88FC41ULL, 0x021C9C198B4AA9C8ULL, 
            0xD988BA98D5140FB8ULL, 0xE4BADDF28BB6BED5ULL, 0xC3284AAF670FDFE2ULL, 0xC2DD9D6B883A5409ULL, 
            0xADC2701F0986D247ULL, 0x0BB52207F1CE6012ULL, 0x869FB606B4F7532EULL, 0xBF2800DD9069CDE4ULL, 
            0x28CF1E8FAF860856ULL, 0x8DF2AE053CAD0E65ULL, 0x4FC6948E13BBF7C6ULL, 0x29805F5A222ACFC0ULL, 
            0x5EDF9F0BB558F084ULL, 0xE770F92FB3DE30F6ULL, 0xA88C24E94825FA2EULL, 0x3B83074D05D9A236ULL, 
            0x91F089F057361E39ULL, 0x060BB29413F68EE5ULL, 0x512FAAE298078396ULL, 0x07111DB36EA1D3A2ULL, 
            0x3EB8B04D51490251ULL, 0xC2321C449FAEE3ADULL, 0xB1016D7727A13DD6ULL, 0xF9B5247B9CD6AADDULL, 
            0xD74B9581E9C4C84EULL, 0x47EB8F716CD45C4BULL, 0x863F3ADA4D6EBB6CULL, 0x4AF856C934C5331BULL
        },
        {
            0xB4B28DC3D834E306ULL, 0x2DC7D9272C12C8C0ULL, 0xB3B08594EA977DD2ULL, 0x6C25CFBEE2249C78ULL, 
            0xD7FB041E4A6A20BAULL, 0xD9B0BFAA3A4A0176ULL, 0xA9B35139A8623182ULL, 0xAC98930E8C52A2D8ULL, 
            0x19D002A21DFA1824ULL, 0x8369A73A2FF7633AULL, 0x87EB68BB234FDAB2ULL, 0xBF7854DFFA334469ULL, 
            0x1870A433BC64B06BULL, 0x5D73B62DFD9FAEECULL, 0xADB68C7676F484B7ULL, 0xF5C3712588FB2035ULL, 
            0x5521241E5342D1AFULL, 0x1048DCDB5D5EF87CULL, 0x8B1D8EB80DC5A985ULL, 0xEB73DD3C45EF371BULL, 
            0xEE4F607F09F8739DULL, 0x45641D16CE6EA06FULL, 0xC59D69514D30AD84ULL, 0x69139A8D2974CAA8ULL, 
            0xFAB8596217064C17ULL, 0x020B5A7ED9F216AEULL, 0x2793FAF2DE849FB0ULL, 0x09C21ECE9A2749EEULL, 
            0x366B056E1E03FD26ULL, 0x1DAAFF75F982A1FCULL, 0x4DD363A0868CF128ULL, 0x020C3952FA9B581EULL
        }
    },
    {
        {
            0xB253924E348B8B0CULL, 0x0275005216B03B3FULL, 0xEF2585F2341F32B8ULL, 0xB552C755FAB302B6ULL, 
            0x7181F34A1856D12AULL, 0x552140F509627AD4ULL, 0x542715CB36C660D0ULL, 0x164F64181A4ACCFEULL, 
            0x3D72E1D2395B20DFULL, 0xA3981E8DE0D7D87EULL, 0x8138CFE95CC38A4AULL, 0xE5701813A9AE2E3AULL, 
            0x4B37F45E2E127604ULL, 0xC1C73333341DC42BULL, 0x04F9BABF8EEE8300ULL, 0x22F1C8FEBCB3C8FFULL, 
            0x31B4DDAAA037BDCFULL, 0xA6475ACC8C3553E8ULL, 0xA16917CA3A7DD012ULL, 0x8D9C9D84548129EBULL, 
            0x07C7FFF59856ADDDULL, 0x3186DCD27D319787ULL, 0x9D0F33FEDDF45C5CULL, 0xA194F4B0A85AEC3AULL, 
            0xC37BB01892BCC6DCULL, 0x16F29A90283F9014ULL, 0xDCFEB28C62929DA0ULL, 0x9254E369C682B8F8ULL, 
            0xBACB88A4D5096E0CULL, 0xA42E5D3ABB250006ULL, 0xB60822C303C3A39BULL, 0xF5497EF5FF401D0BULL
        },
        {
            0x2CA7D54F3DBC9947ULL, 0x30488E6025262994ULL, 0x178439F937CAB583ULL, 0x5BBB75725CEF4661ULL, 
            0xFE7BB3D55DE85110ULL, 0xD2113BC2D543338FULL, 0xE2E31908AD165042ULL, 0xC53AF125652AE3A5ULL, 
            0xFFF297B6D5A801C3ULL, 0xD1A3F42E531B9925ULL, 0xA82DC5F3F36E82F8ULL, 0x06961D570F53009DULL, 
            0xD2FB0241B4AF09F6ULL, 0xBCF93CA9FA4F4845ULL, 0x7E6B9FC29C1D7D22ULL, 0x3591FAF527397ADCULL, 
            0x0D73A988EFB9533BULL, 0x50908135C49A49F6ULL, 0xDB1FBB05FD2D7169ULL, 0xB7EB8402F8DC3FBFULL, 
            0x8839DEDD50F8003FULL, 0x5F3B00319D1C7EDEULL, 0xB88AE50C662BB941ULL, 0xB27D75A072FC59A0ULL, 
            0x8E89BC9E17615E27ULL, 0x6858F9059424A2AEULL, 0x71AF2E3C6DDB9FD6ULL, 0x5D9E048B13A78C76ULL, 
            0xC942AC46AD576A68ULL, 0x4F1AFABBC3589C2AULL, 0xB57D3E8632185A84ULL, 0x296718DACB7DC69AULL
        },
        {
            0xD49BBB096C9CE821ULL, 0x416CDD17E6EA860FULL, 0x798ACB3625330117ULL, 0xB74A6350B8A6E5F5ULL, 
            0xFEA5217CEC2E0400ULL, 0xF001DDA5A276E7FFULL, 0x0A1CE8E5CBF70E49ULL, 0x20837B71E6F2EF42ULL, 
            0xEA9909A5AD5668C7ULL, 0x310046C333FF7027ULL, 0x06A18ACDC2A43119ULL, 0xE326DEB36D71A8CDULL, 
            0x7AF88B45FF7580FBULL, 0xA20218DCBB7BC557ULL, 0x3DC44D31F5076298ULL, 0x72ED0F49C7A7964CULL, 
            0x4F0F49DCFF43B459ULL, 0x970FA5D871E07136ULL, 0xB8414CC83C571D67ULL, 0x8AA217419ED8E340ULL, 
            0x7593BF44458F24ACULL, 0x021B91F63B6B9413ULL, 0x63BFAD759C68B5A2ULL, 0x133F11D5F673A0ECULL, 
            0x4E4660AC654A505CULL, 0x5A3F48BE88F14A65ULL, 0x43756A1439F324B5ULL, 0xFECCF178DF357AE6ULL, 
            0xBD68B05A126F1B73ULL, 0x85796E6121E6CF3CULL, 0x90AD2F7817E8BE30ULL, 0x9BAB894212531421ULL
        },
        {
            0x17A9DB951B73BA52ULL, 0x075940859353C66BULL, 0x53EEC1920922734FULL, 0x0BAFC48A95B4E4EBULL, 
            0x312053BCBC13D5C6ULL, 0xA5170B494B6A8EFEULL, 0xBAEE6CA0ACB77694ULL, 0xBCC302BE938398F7ULL, 
            0xADCB4456C27D5453ULL, 0x38B516936B1D8730ULL, 0x337069D593CB0591ULL, 0x822D1ECAA9CFC665ULL, 
            0xB4B75E4A51D4846CULL, 0x576793469F2C87E4ULL, 0xD1DE7EE301FC833CULL, 0xB9B66A1D0BCD5746ULL, 
            0x809D1F8BBA540F79ULL, 0x1CB9D80FB2075784ULL, 0xC046610856F5BCB8ULL, 0x11EEE8BDA4415939ULL, 
            0xEF79EF7F60726C2EULL, 0x9436DFCF285911DEULL, 0x74125FB317F72A2BULL, 0x7A123B0FB19C7EBDULL, 
            0x0CDE66EE5CE8B06EULL, 0x8BEAA6B24C6DB35CULL, 0xFF89458E80E52317ULL, 0x2A13A7EFD90C68A9ULL, 
            0x89640F7528AC5199ULL, 0x74878D917588BDCBULL, 0xB8E3F52F69E622CEULL, 0x5A1FE05FA30E312FULL
        },
        {
            0xD611876CE61A577DULL, 0x1BA3735881EBEB7DULL, 0x9020ACC3A4F59CA4ULL, 0xCF76150622838D7EULL, 
            0xFF787E2AD3627BAAULL, 0xA567C4D4AD06A812ULL, 0xA232FED8901AA1D6ULL, 0x76DA794D5B2C9898ULL, 
            0xAD6867A8AE41A58EULL, 0x07AE40BF8808927DULL, 0x4714338FE669E69FULL, 0x0E647F4F6F2A7F6DULL, 
            0xDEFED749B1B40E93ULL, 0x8750EC41B37CCB60ULL, 0x34B4FE9AF3B5DABBULL, 0x6BC1D5F9B0106ACCULL, 
            0x7A2446DA811BE604ULL, 0x8A6D8D56DA87C9DCULL, 0x871E52FB956D06ACULL, 0xFBBB737ACCEB506FULL, 
            0x481D7CDDFE75F409ULL, 0xD5D5A4FCE4BA5745ULL, 0x1C96AA83037BB8E0ULL, 0x6B1019622956628DULL, 
            0x462CB783A5213D8CULL, 0xA31C9D2F41FD6657ULL, 0x93A3DFDCDA852FBFULL, 0x048A098696E7E710ULL, 
            0x0DA74565A5EF25D6ULL, 0x4B2F175506D73A34ULL, 0x00BE94EE8C84CF2DULL, 0xAC5FB6C0A2527076ULL
        },
        {
            0xABEBAB41338638D4ULL, 0xC9505D50B17483B7ULL, 0xE3A83C0D2159D2F4ULL, 0xA5CCFC7D5A1B4FAFULL, 
            0x298B51DE73FF12F5ULL, 0x60324D23CE290485ULL, 0xE78D2A73B90BB62EULL, 0xFC8FBC4AD0E84FD1ULL, 
            0x5B226E27765CA41AULL, 0xA9D76F8655B30D08ULL, 0xE31A4C953E8A08B8ULL, 0x5E4D762F665034C6ULL, 
            0x2C0A12F8DC1981E8ULL, 0xA97A6CB05E9B02F6ULL, 0x5EDFE1BA9E917F2CULL, 0x087B751E14D00800ULL, 
            0x08FDEBDDA991F2B4ULL, 0xA0D9ADCC36BBE38FULL, 0x45712FB409C2A6CBULL, 0xCDE373A4280B0D38ULL, 
            0xDC1641B56C8BDD2BULL, 0x6BB426A4276C59B2ULL, 0xB9B7CEE95BBD7C00ULL, 0x7F9070CB06997AFEULL, 
            0x2193D8667DBAB2E2ULL, 0x61F3AB3DA7307133ULL, 0xFB73937C4F29ED5FULL, 0x9D451CE083E7931FULL, 
            0xBF07FEC23CFA3EA9ULL, 0x839F10C61DEC09A3ULL, 0xCFF923F815F79703ULL, 0xDBB5AFBE4186E10EULL
        }
    },
    {
        {
            0xBFBEF4CAD01BB4C0ULL, 0x45CA00A16E22E3AFULL, 0x7F33A1F0EADF9B9AULL, 0x246738C102AF34D6ULL, 
            0xFB2D52E1BE477FDCULL, 0x001F02A3C6912646ULL, 0x22B8AF315D5DFFC1ULL, 0x380AB80C33C125BFULL, 
            0x38B4D0F07A99EA0BULL, 0x97BD83A0CFF1A4E9ULL, 0xFC0B848BDA68B411ULL, 0xE8C957D6C3AA1727ULL, 
            0x2301413BAEF73168ULL, 0x90C4AE34CCBF4811ULL, 0x51EE1B63AA6A9ABCULL, 0xD9F6130B2ACDA7F0ULL, 
            0xB4E8C8B5B0DF5D40ULL, 0x77AC1A31CE511847ULL, 0x6DA7A76A3C8EDCCCULL, 0x9917CA184A1CD134ULL, 
            0x2533097BAD667E5FULL, 0x4F6D49CE7303D7C4ULL, 0xF509EB0AF66B76EFULL, 0x4498884C84809617ULL, 
            0x338DD8E2DC5D65D8ULL, 0xE4BE0760B1523526ULL, 0x0709ED27052D72FDULL, 0x9D7D520FBF6B50C3ULL, 
            0x3EBAA98798975CBBULL, 0xD048FA733738F42FULL, 0xA33E8EA08490EEE5ULL, 0xEA09D500643C3FD5ULL
        },
        {
            0x9593F329976BFE6AULL, 0xA6186FF964064E90ULL, 0xBB01764A2D9E7411ULL, 0x946D6701E188C27AULL, 
            0xADC91904CBCC0545ULL, 0x38EBD4A61721B09FULL, 0x638FD87A55BCA435ULL, 0xE25C47223E90009CULL, 
            0xAEEEFAD5147CF8A1ULL, 0xAE062CC85540D32DULL, 0x4C9039D7E135A77FULL, 0x80F1C34585FC5295ULL, 
            0x94C73988D2DB7803ULL, 0x472A11F35AB47B77ULL, 0xB3078DA72EE4067AULL, 0xDE294EA34ACE7847ULL, 
            0x662CC5AEA9CEB2BAULL, 0xB17EBF3F85C411C5ULL, 0xE8922FA95EE4C7DDULL, 0x80D4E5BCDE70D2CFULL, 
            0x4812AC10AB654AFEULL, 0xF0720373E54B7C66ULL, 0x11B738D78DF6708EULL, 0xBFE3423D585F4144ULL, 
            0x099D1C4F2863F72FULL, 0x324063EFF973C153ULL, 0x2592918455B83F1CULL, 0x85B4819BFBD63F54ULL, 
            0x6EF96C94CADC9C9AULL, 0xC46E54570EB1AB1CULL, 0x4DE0D5E3E3F9CB84ULL, 0x70643470F2C12130ULL
        },
        {
            0x1F6D8973A131AE8AULL, 0x8A2AC1FBFE6DB4EBULL, 0xD06E7E07B3FCE9BDULL, 0x7348A28163FB1A7CULL, 
            0x9D9F7ABADD345B5DULL, 0xCDCFC7576DD77685ULL, 0xF8911ED65904A4F6ULL, 0x63E532845C1AE1D7ULL, 
            0x23F391A5C38541DCULL, 0x90A625CF1FDBC25EULL, 0x83DEC49A9A826B0DULL, 0xF447E0BBF4CBC10FULL, 
            0xBEAF185D9882DFB0ULL, 0xF9BA7C4731E01897ULL, 0x9830AA0F6F6418B6ULL, 0x689F4CBA9287CF90ULL, 
            0xCEF6B3EFDC264422ULL, 0x2B6223B280D5D69EULL, 0x4B34339CD85D1E46ULL, 0xC8F0818F401A2DE0ULL, 
            0xFFF9441CC6EA1D63ULL, 0xC134808319ADB846ULL, 0x007BC99A5CD86787ULL, 0x1A8F308C43AD7DCAULL, 
            0x98B82AEBADB50E64ULL, 0xD9095680E8576199ULL, 0xF8C1032804DAAAEAULL, 0x5783D7C291FECF1CULL, 
            0xF9CB89F7439FEEECULL, 0x938360E5348F6E62ULL, 0x23CBF57D798F77F7ULL, 0xAE660A765AFED69BULL
        },
        {
            0xF25FC531D3C022FAULL, 0x4D1C908AB9C0B12FULL, 0xFDC2F43482C05962ULL, 0xF0D5A5BE29DA3295ULL, 
            0x5F45B4F691329689ULL, 0x92B55DC6B06FA859ULL, 0x56DB9351A552BD13ULL, 0x0B3783B4B8418B97ULL, 
            0x028447DFDB9429D8ULL, 0x03F5DD47EAC21584ULL, 0xC708E0877C19062EULL, 0x220767E04405A1ECULL, 
            0x065D78151099697AULL, 0x9EBA348D5BC4EA1AULL, 0x4D68CDF676A9439AULL, 0x53B930981286929EULL, 
            0xC07B87DE9B4CA346ULL, 0xEECED440A43AAD45ULL, 0xD6E4C6737155BA62ULL, 0x8FB3D5CC48FE0DA7ULL, 
            0x1070C8E4BE1DCC4FULL, 0x47723FCADB9AA416ULL, 0xD7E6156E088B5C2DULL, 0xB173998DC9EE3EA9ULL, 
            0xFA3C7ACDFDBDD3D6ULL, 0x54C2FC006E30D330ULL, 0x25BECE72FA37BB6CULL, 0x7A28FBF4392CB098ULL, 
            0x441F9F50F4D202C2ULL, 0x3D3FE71D4669B99FULL, 0xCDB030E55F376B31ULL, 0x288F24B8D09891F3ULL
        },
        {
            0xA408570EB3E1BC62ULL, 0x4D1802691E4E4E73ULL, 0x4511B631BA8E567FULL, 0xC8ACBC5349E290D8ULL, 
            0x078C3B29B54B7218ULL, 0x74B162955380D167ULL, 0xF5DDF8C6B7D2C922ULL, 0x318410D3D67A2498ULL, 
            0x3EB016008BF9971AULL, 0xEBC9632E71813637ULL, 0xE7710D758DC02F13ULL, 0x5EB27968C30F1D8EULL, 
            0xCC25E3BD3B020A8BULL, 0xF4DEF4D5E1A7094BULL, 0x7AC76043DFA38A9AULL, 0x9AE1E5C74839D706ULL, 
            0x1231DC411F44438FULL, 0x4D06E88815072BEAULL, 0xF1FF91092818108DULL, 0xC9B7E53EB034C125ULL, 
            0x2B7A596878AE30D6ULL, 0x90E8660B830A8EFBULL, 0xDA01602F3A16D95EULL, 0xE7662D7FED472E01ULL, 
            0xA30994AED830E866ULL, 0xA97DED06ACD20D9FULL, 0x1044F1959CC57F57ULL, 0x59E78C0567807235ULL, 
            0x6DAABB1F46824496ULL, 0xE11A2E6EA34CF0A7ULL, 0x1A78E49A2F3CF7E3ULL, 0xB6F3CDA5E75FC885ULL
        },
        {
            0x525849737748C662ULL, 0x981F878BF8C4E1AEULL, 0xEDA0304CC115124CULL, 0x948D7DF5AD63ED78ULL, 
            0x87C8B3F71637DBFFULL, 0xCDF8CF6D11551B4CULL, 0x12C2707928FAD9EAULL, 0x1D74C3E3578381E0ULL, 
            0xD30584673A6F74ECULL, 0x53B3FC1AA9B419C8ULL, 0x05EEF153127CDF96ULL, 0x53182C1EA22E869DULL, 
            0x361831F4F9E15AD6ULL, 0xC0E60A304FCB78BAULL, 0xA2BFADDCA7FBC355ULL, 0x9239C113BF527F42ULL, 
            0xEF7C2A2826384F96ULL, 0xF7F6BFCE061225C9ULL, 0x7028FABCA36AEE6BULL, 0xF351E3CFD29BA80BULL, 
            0xA9B1753265785970ULL, 0x2D4CD4359D6831B8ULL, 0xD33B619F2BB5C5AFULL, 0xE863FF6E111FF95FULL, 
            0x817E348B46DF60FDULL, 0x3E0055F5A5F738EFULL, 0x71610783E05BC048ULL, 0x53BFF0C58739E542ULL, 
            0x297E3469225BE227ULL, 0x7EA3C2A3964CD6E0ULL, 0x43F73CA0F5782A11ULL, 0xBF07CFE39C6AB971ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseFConstants = {
    0x49B2DDEFEEBA5A4DULL,
    0xCB255F9D2FE81893ULL,
    0x7B9868A92DFB762AULL,
    0x49B2DDEFEEBA5A4DULL,
    0xCB255F9D2FE81893ULL,
    0x7B9868A92DFB762AULL,
    0x210248CDEA6443B9ULL,
    0xA99FF4877BB09F2EULL,
    0x41,
    0x2A,
    0xB4,
    0x1D,
    0x29,
    0x09,
    0x11,
    0x06
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseGSalts = {
    {
        {
            0x3BE4703676526369ULL, 0xD4705E4F990EC9D2ULL, 0x31ACD736DFD0537FULL, 0x2C88DFE7CAFED94EULL, 
            0x1D67C337CBE13849ULL, 0x5BF9EC768110CE09ULL, 0x5C3B2549A088B714ULL, 0x9A263EC964282907ULL, 
            0xA7AE1D51D2E6B114ULL, 0x47327FAEAF90C426ULL, 0x3B74346C2FB0450DULL, 0xA003E2124A02B6ADULL, 
            0xA01267681135325EULL, 0xF015643C29C82ED9ULL, 0x58B9B1F615DDCB43ULL, 0x1F3D099F282FBC0DULL, 
            0x5984466F10F492C4ULL, 0xC9BDE6C90CC8720BULL, 0x485085AECC69B36FULL, 0x2F9124FEBE80D30CULL, 
            0xD6A1BDC5392C53B9ULL, 0xC9FEFFE8AD5D0910ULL, 0x7C892BD57192917CULL, 0xEF2074DC0629F851ULL, 
            0xC2F97F138EED7B92ULL, 0xA40DB44E83E93425ULL, 0x52D544572DCF88FDULL, 0xD98E00EF4A968458ULL, 
            0xC8418DBD1ED434EBULL, 0xFBBAB3797DBD699FULL, 0x0325BEBFED693AD6ULL, 0xF2A097A335211A6FULL
        },
        {
            0xAAB7C0D8AC6030DFULL, 0x883302350566319EULL, 0x923ADCEF6A3D55D0ULL, 0xC2A25E316E9887ABULL, 
            0x4336EE2FDE03893CULL, 0x2EE805849A6F0778ULL, 0x36E56E37B3006E71ULL, 0x7560EE5273B0E562ULL, 
            0x574CF840EA067F2BULL, 0xAE84A046A4783925ULL, 0x3FB7BCDCF87CB3EDULL, 0x9A5FCD4668F2F524ULL, 
            0x955819696C35212EULL, 0x2D1AB7B2E6DD12F0ULL, 0xC82F14EE7A6D614BULL, 0x5740925D00D23E5CULL, 
            0x7228BE27AE9B82B0ULL, 0xD01636F2824BAD87ULL, 0x40E3A9DAD9096DACULL, 0x7F1504FC4A80A7A8ULL, 
            0x5CCDAA05956467BEULL, 0x94D496A7A7387AD0ULL, 0x523A238C955628BDULL, 0x75C9691854D44918ULL, 
            0x611647B47A3429B0ULL, 0xA2940049E2CC52B0ULL, 0x9F6C295AC26F18FCULL, 0x9D6A2432C697FED7ULL, 
            0x5C3C0EE816B2A378ULL, 0x1BB33814A76C82E4ULL, 0x05367FB741D07A18ULL, 0x8D4932D851D20B5AULL
        },
        {
            0x1ADBB842C4AAF37BULL, 0x6C1172684EEC986DULL, 0x8CB65353CE51347DULL, 0x8936196F47330984ULL, 
            0x1140D7D6BE537D86ULL, 0x00994049A763103CULL, 0xAD5C65A0506D2568ULL, 0x8D235482D79D6A67ULL, 
            0x3D88649591F6352AULL, 0x0C20A0E5AA86E75BULL, 0x8C58EEADA1633219ULL, 0x5670A5F4A2F0DA3BULL, 
            0xB48F2750C907569FULL, 0x4F5856C4530ACDE4ULL, 0x286D24BB7EE505F4ULL, 0x25236B6EAE8CE74FULL, 
            0x4BD250CA7D555F35ULL, 0x12AD007AA65D32A4ULL, 0xBB6AD1839D4F97B3ULL, 0xDB8037EEC7A622C9ULL, 
            0x0F233FC19A685F5BULL, 0xD51E03CADEC00089ULL, 0xA4550B2BE91AC72DULL, 0x5FE0F2B46B5F86DEULL, 
            0x86C9659094798038ULL, 0xC04708C626E9F19FULL, 0x10B5FE899B93AF2DULL, 0xE864CA8E916B87EEULL, 
            0x28F7E1202AE9E678ULL, 0x36D64F6873938C90ULL, 0x17F69D910DC17C92ULL, 0x99749091D6939E55ULL
        },
        {
            0x8BC4A76BBE66C5F7ULL, 0x37037210EABA4F45ULL, 0xD0A954003682A93FULL, 0x8A405454D5D1F2D2ULL, 
            0x1A594633BF35F0D3ULL, 0xA6F437E05CEE714BULL, 0x240D1CE259A2F77CULL, 0xA666E54C1CD302E3ULL, 
            0xE2009F6175346F5EULL, 0x50409EECBC267D28ULL, 0x8A8F4B7DC54F1ECAULL, 0xB9136A4F8EC9121FULL, 
            0x2AB9E09C5C6E2593ULL, 0x58046DCA6C796B44ULL, 0xA5C7B584D97F9676ULL, 0xB1D003161A6A5179ULL, 
            0xD60F1AC0EE8A27D5ULL, 0xC87ED530CADB0020ULL, 0x4B73F51BEAFF4B1FULL, 0xD5C0B3C820519AF0ULL, 
            0xE0634D02D5D3323EULL, 0xF39949F62F226C79ULL, 0xA2C698DF0342F868ULL, 0xB0374DD2872264A4ULL, 
            0xB57D02D566E28FB8ULL, 0xF9BA6D0E3474FC22ULL, 0xD19BD5DD25F11287ULL, 0x40562FDD043D1649ULL, 
            0xBD6F442EB2999110ULL, 0x1980220F57BDB799ULL, 0xC97E99E59E740632ULL, 0x7A68EFD5548C32E6ULL
        },
        {
            0x35EFB12180DCF7C4ULL, 0x99B570DF38C7CD3EULL, 0x48C2FD136C647AB6ULL, 0x1327FF95E03150DAULL, 
            0x0D18E3C8E69FCBACULL, 0x406F032AAC5A86A3ULL, 0xD418B4089DF14CC1ULL, 0xC7681BABC5D34186ULL, 
            0xBB0861B32764500DULL, 0xD41E326A3B45F4F2ULL, 0x38039E87DE111936ULL, 0xCA3E8883273AACF8ULL, 
            0x7F4096F6166968FBULL, 0xBFF910AA2F15935BULL, 0x3FD3F7700C24CBABULL, 0xA52935B444266FEDULL, 
            0xC0B17E371F275967ULL, 0x550AED36FC4D3032ULL, 0x55390E1E039255C6ULL, 0x7750B307738FC104ULL, 
            0xFDCE177E23F3EFC8ULL, 0xB9CDDCA9F0E10AC5ULL, 0x3B48688F637ABF4DULL, 0x18D7F4286149A87AULL, 
            0xD917855399E17CD0ULL, 0x2FCACD4DC912DAA0ULL, 0x2F32A3A11172D7DEULL, 0x7D07DFF898DB5680ULL, 
            0x50DA4D6F0DF28105ULL, 0x9EB519A3C3A9C7E7ULL, 0x432DA9366542E05AULL, 0x446377B132E0587BULL
        },
        {
            0x3B96A8D71A0F50CEULL, 0x13BB63F314F75CAFULL, 0xA7BA494C31CFFA46ULL, 0xFAFB7C8D6066C76EULL, 
            0x1C675E1B7C862A1DULL, 0xA9169774D8315D83ULL, 0xCC59AD822805C1D7ULL, 0xB98D2665541FA3C9ULL, 
            0xB2B0959B88179ADDULL, 0xB73F255C91D2705DULL, 0x40992470CFEE4EF4ULL, 0xB73CB727FB99C39BULL, 
            0x46C9E14560C37B7FULL, 0x75F0C58251906439ULL, 0xBE5DE6568EC15869ULL, 0x3D2CFFA97EDB7FEEULL, 
            0x8DFF01F643FE9FDCULL, 0x7C7195ABFE7A78E6ULL, 0xE65F272EB758C8DDULL, 0xEFD153CD70481275ULL, 
            0xFC1B7538D9D4A94AULL, 0xA66402722F18189AULL, 0x51C0F4F438B80C97ULL, 0xB30C0F716C5D1C90ULL, 
            0x5D522103726882D5ULL, 0x8B0174D55410DB9FULL, 0x9DCF7AFD124F2354ULL, 0x92993DAEA283F454ULL, 
            0x6246A4DBF7C89F40ULL, 0x302D46E635A1AA95ULL, 0x6420525435D654AFULL, 0xA416484A8D7CF1E7ULL
        }
    },
    {
        {
            0x026066F28CF60057ULL, 0xABD1AC8C78CCA632ULL, 0x53F07472C493841EULL, 0x2B9C15A707679654ULL, 
            0xEAB73E3DC3BEB47BULL, 0xB1B29A3C44EB1B9EULL, 0xFE2D0909D34743A2ULL, 0x2448C625281196ABULL, 
            0x3E5A8A7CACECFACBULL, 0x5B30C61C5389D5C2ULL, 0xD36C6EE69E1899AFULL, 0x76FBE93E802F6C76ULL, 
            0xF3520A04654B02EBULL, 0xE9B0D1D447357CECULL, 0x056E964C17B2A861ULL, 0x34C79B02D55CF399ULL, 
            0x57482ACB36B82BBCULL, 0xDF3682664630C9E4ULL, 0xD55CE1156BB78055ULL, 0x5979DCBA1DA21DB0ULL, 
            0x50752A53E78B81ECULL, 0x9F6F744F9C7526D8ULL, 0xADBB70B59DB867B9ULL, 0x3BFEFD1EAAD68D62ULL, 
            0x0A8D4CEF3CA3A2E0ULL, 0x58CE23D09E4D48C7ULL, 0xABB27C56AB8F80E6ULL, 0x9A4043B2BEF40FDCULL, 
            0xF44B881651AAF62FULL, 0x13688567F966DCBDULL, 0xD8497ED7D3BAE326ULL, 0xAA54383E7484E5FEULL
        },
        {
            0x814B516AF9499930ULL, 0xB2FA1E0A04606918ULL, 0x380BAC6315D9E72CULL, 0x2A7D2DFCE46344A7ULL, 
            0xEB9552CC1B9E5EE8ULL, 0x9DCD13F8856007B9ULL, 0xF8FD31F40CA7ABFCULL, 0x0E12907AF9515DC3ULL, 
            0x3A693168D50842D3ULL, 0x0E66CA4CEF40DE62ULL, 0xE3FA3ABB41354C8BULL, 0xF3CED053DE53D919ULL, 
            0x355B5460AB643859ULL, 0x9FAAE994A4222050ULL, 0x24C01343BBAB034EULL, 0x8965378209B09FB7ULL, 
            0x01F66129E9F72076ULL, 0x3B8C99D97C3C14FCULL, 0x6FB4DFBD435AB979ULL, 0x85856D54128CCC74ULL, 
            0x8D072360AC927D89ULL, 0xEE9741E324D88743ULL, 0xF844A4B0C86232CCULL, 0x390360B3582B7551ULL, 
            0xB400EE89AC79592DULL, 0x99FACDCC8E72F2A6ULL, 0xDE9BAE11D2E1746EULL, 0x503BB8E9B4C9CE70ULL, 
            0x3FEFF85102657AA1ULL, 0x1AE79B80E1044FD1ULL, 0x1F9AC2C9CCFEB291ULL, 0x5D6B19B1414662CFULL
        },
        {
            0x585CE04D5A696300ULL, 0x93C7BBE0BD238393ULL, 0x077D6FA48060802CULL, 0x9DDB0F39BA547134ULL, 
            0x6F2FE43ED2AFE13EULL, 0x90E7290DD1A93A2CULL, 0xFBD8D06049BE1D0CULL, 0x3CE5719F7B57B7CCULL, 
            0x493A46A6609C1475ULL, 0xD33B1EC7310ACFC8ULL, 0xAF6803343E4E58F4ULL, 0xF9361331D8530C7AULL, 
            0x34AF6D5D681EBBCBULL, 0x8A121DDEC9AB73E9ULL, 0xC453ACF2E9599500ULL, 0xF271FB242107E983ULL, 
            0xC3DDB3AF4484F61CULL, 0xA85CF62E42EBE4C5ULL, 0x5524A0914EB8BD34ULL, 0xEC5FD7FB50B9C462ULL, 
            0xBD987BA944BE6820ULL, 0xD477AE8CCD247A6CULL, 0xA2E7BEE0E605E977ULL, 0x3C11226AB1E7937DULL, 
            0x23526D6BDFBA2432ULL, 0xBCC36FFBD0C02ECEULL, 0x625D2CEF3AB06BDDULL, 0x5F3E8A7112C88FE0ULL, 
            0x3CBC00C9208CD398ULL, 0xC4E6D760A1B3F829ULL, 0xD0D03B71EBD6C96EULL, 0x70DCED776710EF41ULL
        },
        {
            0x2EF0286548C3BB04ULL, 0x99DB2314A7325990ULL, 0x40CA8B5B41E18A41ULL, 0xB1987FB65006A115ULL, 
            0x339780AE1E8A6796ULL, 0x92BA2F50A9778ADAULL, 0x0ADBF621EE10F9B8ULL, 0xD6D5658AD2D40EF8ULL, 
            0x59BB28824E66FDC5ULL, 0x3B51A32E27AF5B35ULL, 0x71AED51EF6105CE6ULL, 0x2C3033F3033E615AULL, 
            0x31753F46991952F0ULL, 0xE2825914F56A6BEFULL, 0x64FB7A8FAED80F04ULL, 0x8F56612E69A98B9CULL, 
            0x00B66841095C474BULL, 0x53DF0C7F19F5A788ULL, 0xB50214A5CDEB99B0ULL, 0x358E7F58EECFB513ULL, 
            0x8D16EA800CB706C7ULL, 0x3FD299402648509FULL, 0xAF344178B5C43836ULL, 0xD17308B6C260CDC3ULL, 
            0x05CA37C5B1D10EBDULL, 0xFF8459AE522440CCULL, 0x826EB4E042F92B73ULL, 0x73A229CC2A35481AULL, 
            0x5FCE3F95085B0595ULL, 0xE4065E2B962DB3ADULL, 0xAAEFB4D87B565B4FULL, 0x5FD3FEBE57DD6A3AULL
        },
        {
            0x9A689F12F5CAFEB4ULL, 0x8234823274D123FAULL, 0xFDD505BD3ADE10ABULL, 0xA9661D67A89F590DULL, 
            0x52FEF400C4D677A5ULL, 0xFED599751F861EE5ULL, 0x4CA66DFD949EED35ULL, 0xED09B7E4D70E9542ULL, 
            0x9C472AA5DE97132CULL, 0xF62EB8356EC465E4ULL, 0xAC43AECF3542F565ULL, 0xA6C7C8C018244FADULL, 
            0x2A0771227188D83CULL, 0x4AD8ED7739FCB63DULL, 0xBED703576EA89946ULL, 0x2144F361EBDFB838ULL, 
            0xAFD8B24631BDA54BULL, 0x22E4F6D80CDD9646ULL, 0x8A0E5721AACB3FF9ULL, 0xA7A5AE60BC2B91B2ULL, 
            0x0522619224A044E7ULL, 0xCADAF2624303C596ULL, 0x57D4AC53AB4B204AULL, 0x7B8CAE0497B4B860ULL, 
            0xA4E165EB7294DED0ULL, 0x027CF7417B4E92DCULL, 0x9DEACF283392AC6DULL, 0xAFFADD29E845CEE1ULL, 
            0xB427D96851014D04ULL, 0x76988B8DECD531A7ULL, 0xC94DAB1BE48A185FULL, 0x98316FFBB1DD0840ULL
        },
        {
            0xF9E86FA876983A10ULL, 0x260DA32D0B573560ULL, 0xE924C328620CBB15ULL, 0x6336873ADD098872ULL, 
            0x677ECCD85DF883D7ULL, 0x54EF8E4C7C63E401ULL, 0x0F01B9F44DDE0D42ULL, 0x5BA027E84917F3EEULL, 
            0xB9769D083A930BB2ULL, 0x39074A9BDA9C6F59ULL, 0x10274E40E4846921ULL, 0xFE546E7911872AF4ULL, 
            0x0C5598035286BB5AULL, 0xF3B3EA0F079C84D1ULL, 0xB882024554FF53AEULL, 0xDAA3A3D9B39B7D8CULL, 
            0x4411B3EF31F7EB42ULL, 0xC0F9237AD6AF2799ULL, 0x553E2EFCC8C51B51ULL, 0xEC40EEC2060C10F2ULL, 
            0xDDB693EB05D3B456ULL, 0x0A02AC6D84654491ULL, 0xD2DCF8879700C88DULL, 0x04BA93C4E2371CD4ULL, 
            0xD7A44341F1C8D4F0ULL, 0x0E6F5D88323EB80BULL, 0xD92748EB4FBAF4DDULL, 0x4CE92C9D6F3F3CEEULL, 
            0x725FD14B90C98050ULL, 0x54AFBD7F9F382F5FULL, 0xB36704CA24C80FCDULL, 0x6298DE1952F07C5DULL
        }
    },
    {
        {
            0x8342218420511230ULL, 0xAA805D6D8579ECE0ULL, 0xFEF4DDBE811B90C4ULL, 0x2A08F568A1B98BF7ULL, 
            0x8A2C3F18984F4ABEULL, 0x0404A51BB6A5A68DULL, 0x93FEC89A0A9F4606ULL, 0x859072DBAD68AA78ULL, 
            0xF62C5D9F2BD56FC5ULL, 0xE9D68EE4DB26C057ULL, 0x493A3E70450995F7ULL, 0x9BB458CBB01B108EULL, 
            0xB93A046F6AFAA4D0ULL, 0xFD5830E5728E5B15ULL, 0xE0F2A5A29AE739C3ULL, 0x5F294B7237841D24ULL, 
            0x05E90CA271082EC2ULL, 0x0FA8C93051BAF273ULL, 0x3E435E9A89F12351ULL, 0x486DFD5954DAE23CULL, 
            0x42708114EB233011ULL, 0xC0E515C6CD6D875FULL, 0x3EA6CCAC8C310791ULL, 0xE3F90E5CB2FF3A96ULL, 
            0xA45642429CD507A2ULL, 0x232BA3C060EF3851ULL, 0x08E9E0B2D0C53FFEULL, 0x94832E42E9439830ULL, 
            0x32869CB1EC781163ULL, 0xEC7977CB81B9E45DULL, 0xA168AE4C82D9FA7EULL, 0xF9018F2340D4A7C0ULL
        },
        {
            0x27516A66CEC3AA73ULL, 0x57E6C1E29C0B9047ULL, 0x23F9DE0D52D691A2ULL, 0xD54D2CA325FB36C2ULL, 
            0xB32366FEA9E86A29ULL, 0x1B18A1390FD8239EULL, 0x26356EF0FC656687ULL, 0xCD360A55049F885EULL, 
            0x4C5F583C97387076ULL, 0x93C5D5063E7F8071ULL, 0xB8787450A61D5A6DULL, 0x93DF8A92CDE0D350ULL, 
            0x2E0F47BFECA9F24AULL, 0xDF637ECCA2D9BD0EULL, 0xC59EBA1633737452ULL, 0xBFE0EA591BE0E5E6ULL, 
            0x184F316F98AF8CA3ULL, 0xB0F93849BE590F9DULL, 0xBB5BFD0BD1CA696CULL, 0xCA4C736ABECEE799ULL, 
            0x7FB5B92A07346898ULL, 0x5634182DC85E63AAULL, 0xA32C9300ED447BF7ULL, 0xFA1B63477E311C44ULL, 
            0xF4CA99FC0556CE7AULL, 0xCF069985E990CB73ULL, 0x401A3AFC25C734E3ULL, 0xDA15816C2B348BC5ULL, 
            0xED4B9A24D322F79BULL, 0x26C28E8F17A548CCULL, 0x76805EB9E4BC7CB8ULL, 0x6BA1FAB0A857F969ULL
        },
        {
            0x70FF97EF3EFF808EULL, 0xB0A32ADBBC0AFB08ULL, 0x45BD6C224AB97A38ULL, 0x1F19912C9F3B489DULL, 
            0x5CF9CF4864DADD1CULL, 0x5B0630A5B55C9D70ULL, 0xE50D2EA211861857ULL, 0xE07C67ADCBF062EAULL, 
            0x86A2137A981E4D35ULL, 0x6C853F39271CA672ULL, 0xFF7AAA50F83D8B48ULL, 0xDA1BE907BCA31F2AULL, 
            0x6B1B071F6B27AC4EULL, 0x650B8AEAA3B4D99BULL, 0xCBC9F3E2AC5330A3ULL, 0xAB3B5CF458610971ULL, 
            0xE33F74FAF8F131DAULL, 0xA9C5D2E51E308A08ULL, 0x2D220E5C6CD2ECEAULL, 0x3BCACA1401F414E9ULL, 
            0x7AC942902D7D148AULL, 0x43CA3E8C946058F8ULL, 0x37D2260B39BF1914ULL, 0xECF83D34B837F058ULL, 
            0x41A49BF23F4864CFULL, 0x0C7982FAE47C22D8ULL, 0x3306B950250A5824ULL, 0x9880F592DC3FCEF0ULL, 
            0x53A30E4AEE259585ULL, 0x25B88AEC6A12D0C5ULL, 0x07A463662C21CD52ULL, 0x18CB9989F92501DEULL
        },
        {
            0x84CCE480B65E3F4FULL, 0x51C21031240AF1B6ULL, 0x3439D5426FCE2916ULL, 0xFE595FDA01B9EC7FULL, 
            0x9025C4042130090CULL, 0x622B50BD1826200DULL, 0x9493FD4078652983ULL, 0x28AD77B7F2063C58ULL, 
            0x98D78F1408370FF2ULL, 0x02BE9B065F7D9C0BULL, 0x4A52F5AA2FE9185AULL, 0xAA61242EB6116A76ULL, 
            0x78BC8879EE2E5E17ULL, 0x2212831D7680E08AULL, 0x07573D3C552A9B73ULL, 0x090638F943174F39ULL, 
            0x57E61A1DBA20ADC7ULL, 0x42D7F11AE966A513ULL, 0x0468A9806E544777ULL, 0x7494C8C847AEAA9EULL, 
            0x64138211EE72DC50ULL, 0x28A7C527470C85CAULL, 0xBC47BD25FD9C230EULL, 0x57BAF472F6962791ULL, 
            0x553ECE0E7505C851ULL, 0x9565420A580F4E40ULL, 0xD646F2CFCFE643B5ULL, 0x821968F1FC52822DULL, 
            0x0A4E4E953C7707BDULL, 0x35C40509B5A79748ULL, 0x9EDB414C027F2526ULL, 0x403B1846D481E4ACULL
        },
        {
            0xFE5AC09D2E8BC405ULL, 0x4CE0109C4665A7EBULL, 0x17EE335710B9AFEDULL, 0xF95DCABBB83EA6AAULL, 
            0x5B8839C3E9470861ULL, 0x495AB3F71AAC1AFEULL, 0x97F60081D6654729ULL, 0x20FC697C69705BE0ULL, 
            0xC41E8A59F9C43CBBULL, 0xF08263E6F297AE80ULL, 0x6E4727CF70CBC68EULL, 0x1CC6FE51B8188BC6ULL, 
            0xCC62C0D34D7F21DEULL, 0xC4FDFF8B6DD61452ULL, 0x6E5089330BFA5F17ULL, 0x445B763C99005D2CULL, 
            0xBA6A4604513122A9ULL, 0x40E6BC6A3FC9BE52ULL, 0x159F342CC0BAFF2EULL, 0x9E1F879836E16DBDULL, 
            0x8D8ABAA1097F69ACULL, 0xC140CB9C39A34414ULL, 0x90B9D2BA944127F6ULL, 0xD24F6AFCE9B9D40FULL, 
            0xFE8A17755EF6ED9EULL, 0x234CD2175A9F5ECBULL, 0x0F7A110CC9581012ULL, 0xC1D4E71CD3908F83ULL, 
            0xD0382A4BA200C27AULL, 0x62E2B4B49B28A0DDULL, 0x9158C9453A41A6C1ULL, 0xF3F8C99DBF2964FBULL
        },
        {
            0x7A126DB258F7A1A8ULL, 0x11AC738F5206AFA9ULL, 0x29A925235B114557ULL, 0xD0AE68B0D109A20AULL, 
            0x7647FA608C3450B4ULL, 0x493ACFC130FDBD35ULL, 0x15227AC0D7ABE5C2ULL, 0x068A4652C8FEEDF3ULL, 
            0x2BA552A1D6A72102ULL, 0xF97010791285B26DULL, 0x44F1258D1DC11CC5ULL, 0x01619CBB94A68480ULL, 
            0xB30EC4629B2048F0ULL, 0x4A3A08C1850692A0ULL, 0xFD63F074EE7B6363ULL, 0xBF7EB5A2DD3A6CD7ULL, 
            0x3103DCC5D63DBD91ULL, 0x7176B0F1E7A3E791ULL, 0xA3EB27DEB58FECACULL, 0x70ADD0F4304BD198ULL, 
            0xD43C3ABFB12CE755ULL, 0x3B58A3877050DC02ULL, 0xBB9DA29DA40643CBULL, 0x5E5C4882E9CF0EB2ULL, 
            0x5D3083133C70642EULL, 0x6CF8F2E6430364E7ULL, 0x68AD693D4E8AC3B0ULL, 0xFB220F55A39F7C27ULL, 
            0x6779B8D84DAAB5A6ULL, 0xBD62764B1778DEFCULL, 0xED93F85C699B2633ULL, 0xB78E8142FB0F18DEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseGConstants = {
    0x9DEB1C58EA6C1A8EULL,
    0x775DB82031A18EFEULL,
    0x9D20650C5AB4C57CULL,
    0x9DEB1C58EA6C1A8EULL,
    0x775DB82031A18EFEULL,
    0x9D20650C5AB4C57CULL,
    0x9577A0855D3F855BULL,
    0xA586F047E2B874C5ULL,
    0x8B,
    0x28,
    0x48,
    0x76,
    0x20,
    0x04,
    0x0F,
    0xAC
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseHSalts = {
    {
        {
            0x155B20EFF92F6968ULL, 0x80599783F9D8A93AULL, 0xFD42A38302EC2E1EULL, 0xA47A6B9F06C381EBULL, 
            0xD0902765A76021A6ULL, 0x7FBD05AF190F3414ULL, 0xF6D5DD064902AFE3ULL, 0x23EDF8305DF7D959ULL, 
            0x05BFC52A12D48FC0ULL, 0xEB47FA55B92B911CULL, 0x0D65F2BCB32DD244ULL, 0x8BA64010DC45B304ULL, 
            0x86B29287213254FCULL, 0x000260E0AA87B552ULL, 0x147ACD61318D4508ULL, 0x9E27D1802EF77992ULL, 
            0x6953486581456CC5ULL, 0x15A56266A6DD2039ULL, 0xCC1E0B92C8F45E7BULL, 0xB5711D4D956DA9D3ULL, 
            0x13BAA27E281F4567ULL, 0xF532735A67199A44ULL, 0x7BB9A2E3DAC85A05ULL, 0xFC95AB28E35E4B4BULL, 
            0x47B59C5AF53B81A5ULL, 0x6EBB86C2F087319DULL, 0xEFE855079918640CULL, 0x129B380D4214227CULL, 
            0x3C7E5248BACB455BULL, 0x57B3E8B790D5E466ULL, 0x0CA3BCB6A51E3A27ULL, 0x4AE4C45D48D9B49AULL
        },
        {
            0x9C03F7A4161277A6ULL, 0xFA8A91F43445E9BDULL, 0x7050C78E2AA34EE9ULL, 0xEB06B986007DBD6DULL, 
            0xE07D3275BBE0300DULL, 0x56B123EFD1CDE230ULL, 0xFE6B68D0B28BA9D2ULL, 0xF6492D9F0769C3E3ULL, 
            0x578B85162CAF635EULL, 0xDE408646598C0342ULL, 0x2B4E912D5178B321ULL, 0x2C7DF716087276AAULL, 
            0xB3C4B25D3A811094ULL, 0x12372DA3BF91A9C0ULL, 0x27E8CCCED3766700ULL, 0x87C2DC29CA195BBDULL, 
            0x1559A5B3EBA81B4AULL, 0x39E5ABE3E9522B9CULL, 0x724B332B59685CCFULL, 0x21233DBB16BB821AULL, 
            0xBF0A01ECD68CC8D6ULL, 0xB0A8343802C59734ULL, 0x93E9A13A17D57D0EULL, 0x0A6D4F345D0F54ECULL, 
            0xC01E11370B7AB5A8ULL, 0x98D72FBEED53084BULL, 0x6EF756CF3A709E58ULL, 0x9EB82B6765C04279ULL, 
            0x1DA850F18B19FD35ULL, 0x0C2EE82DB6B98F4AULL, 0x97827F563DED2837ULL, 0x76142AC86656AA3DULL
        },
        {
            0x47C1C398410F6A6CULL, 0xDC77D85BE19B4CA3ULL, 0x316693C778C236DBULL, 0xCA2504A432833A36ULL, 
            0x8EAB9CCD0519D61AULL, 0x3D95E3A9DC689DE8ULL, 0x5F1C06E505EC6EE6ULL, 0x5DE7A46F064D467DULL, 
            0xB54FC1F8121661DFULL, 0xE6591C580D362B54ULL, 0xCDD2DA31B20F0A21ULL, 0x5442836DE693F280ULL, 
            0x048C702C54A56EBCULL, 0x9E581AA38234A641ULL, 0xA757BE2A23040760ULL, 0xD7D908F73A723BC9ULL, 
            0x1C744752642479BBULL, 0x7BD97FD816DFBE06ULL, 0x63F3B7A56C56FB07ULL, 0x46ABD4752895D2D4ULL, 
            0x81154A17ABF9F40CULL, 0xEABBE354370EF8C7ULL, 0x3159B75E559B088EULL, 0x679A6FCD396E3FACULL, 
            0x3615A0E4488AF1BAULL, 0x7E520AAD4D346525ULL, 0x26D6F88B791993A7ULL, 0x0A54C932FBEA2BB9ULL, 
            0x142432FFE1F2348AULL, 0xE5436B3DB82668BBULL, 0x5B399225F2D9B937ULL, 0x06D1EC5B88EC3011ULL
        },
        {
            0x17BC24749445FD25ULL, 0x20A257C84EE4B177ULL, 0x2A857F8763F5F4F1ULL, 0xBE92F467F1FBD021ULL, 
            0xDF8D84BA70F69C63ULL, 0x7AB46493091F6D5EULL, 0x49BAA4045FFFB30CULL, 0xD7855B3D249C3BF3ULL, 
            0xA303EC5C4C37C9E5ULL, 0xCAF14B06192DDBD7ULL, 0x68FE48CAF6FDF86AULL, 0x00A764B06C72B9A0ULL, 
            0xA76E1B450D2B7BBCULL, 0x56370F9A799A067CULL, 0x14293B263DB48890ULL, 0x14A1B1404180E530ULL, 
            0x8E584F747BC48821ULL, 0xB76D6D6E76ED3BF6ULL, 0xF3347C836FC79E42ULL, 0x01580D32E0CDBF00ULL, 
            0x1E33EDBC1A98107CULL, 0xAFC6CCB94428D51CULL, 0x572BC7A338AC1E8AULL, 0x7E8FAD4971791D1AULL, 
            0x85874A15B03A930DULL, 0x6E361FB6656DCB64ULL, 0x6DBEC3BFBFD271ABULL, 0x6820F6DC4DDA1033ULL, 
            0xE9D87CB4F59B39F1ULL, 0x4CF9DFC125A72849ULL, 0x1EF91C946AA60664ULL, 0x80259171D64160A3ULL
        },
        {
            0xA8483CAF5E4488C0ULL, 0xBE438E0AFB96A86FULL, 0x23B317CB8E1EA711ULL, 0xDDEFB479D3E4EB35ULL, 
            0x28786AA494717FEBULL, 0x94795B655A8FB483ULL, 0x941C826936CB3D2BULL, 0x6FEA6CC61E80D5FDULL, 
            0xE6D5A48DF06C8D2EULL, 0x2BD40641DCFBDEA0ULL, 0xF380AFCB22534FB6ULL, 0x09DFEFC7F82FC20BULL, 
            0xC3B5B6429B4D7365ULL, 0x4EC39E41A17E684FULL, 0x4B5C19C53EC577CAULL, 0x91238BBCF1C63259ULL, 
            0x945B83D2E1CC6CA4ULL, 0xE72E87C1082C4D83ULL, 0x502D40AB3426A54FULL, 0x91308C09DDF90650ULL, 
            0x6B069E89FF785566ULL, 0xE28B08396C56283DULL, 0xC71B9D30CA0CF552ULL, 0x2B9B5DC22A6CC418ULL, 
            0x72380368E33C2565ULL, 0x80D09243483AB1DBULL, 0x0F96CEE15F70DC62ULL, 0x2AE935D97C77A043ULL, 
            0x92AB298F2B8820CAULL, 0x6AC0DC4A8CB3213CULL, 0xBFA1FD5CB1536746ULL, 0x107B13E718DC8D82ULL
        },
        {
            0xBC45B5DAD7770D4EULL, 0xA9A174055F42A27BULL, 0xBA17C9D4E310FAADULL, 0x47AA9F8307CFC176ULL, 
            0x7CC39C563A3CD50FULL, 0xE32D3BE45C8E59F0ULL, 0x728B39778A44EB44ULL, 0x92EE3A0E1E357100ULL, 
            0xC29A2114BB3A7410ULL, 0xD3055EE150942E2FULL, 0x2AAC114A4BF7537DULL, 0x7DDCA354635E600FULL, 
            0x95295B4859F90399ULL, 0xC5BD0B71D059FAB2ULL, 0x857BB61B0853754EULL, 0xA8D2903A1D6768F2ULL, 
            0xF828A11EA4BCE3F7ULL, 0xDB58EA7E0C4F119DULL, 0x78FA94B87AEEB301ULL, 0xE372EA2371659006ULL, 
            0xE5E255EAFB1379B6ULL, 0xC82B3FF705DF76ADULL, 0xF14A4758E9FA7DFCULL, 0x4049855748F30C1BULL, 
            0x2C49A3D2BF24188FULL, 0xB3CB0358C02796CDULL, 0x7E9369A1033F7AAFULL, 0x0B2D9C07E798E9C5ULL, 
            0xECDFC745C6566925ULL, 0xC82A03DD10FA7B6EULL, 0x5813403C58933803ULL, 0x9D8A7150657F995CULL
        }
    },
    {
        {
            0x6849FDBFCE9A1BB1ULL, 0xFEB519A1746E3D7BULL, 0x38A27DA950C15E97ULL, 0xB986B454F905E6F5ULL, 
            0x8096B0207DA94D9FULL, 0x38A850A5DD79C173ULL, 0xA24DA7ED5441C5ECULL, 0xD9C5EDBB3E68B63DULL, 
            0xEAB346DA8A434865ULL, 0x4A12E93BE448E627ULL, 0xCB9475F3BE7AE760ULL, 0x90D94616FCB190A5ULL, 
            0xD105739D40830989ULL, 0x0179C540622BB23FULL, 0x655D955BBFC4CB8FULL, 0x001DC2FDEA5052F4ULL, 
            0xD1E185326255331CULL, 0x749E4A360CEB9D23ULL, 0xA06277D726815BA3ULL, 0xA3199D9E2A616484ULL, 
            0x47AF9ABF3EA0D13EULL, 0xE464402C71C10FCDULL, 0xFBA5A5903C9F65E2ULL, 0xA780B91F0EC78452ULL, 
            0xBD0D552DB505FD5DULL, 0xC0DC21E15247E863ULL, 0x988EEBDBB34F95B2ULL, 0x8289D64955FE031FULL, 
            0x56AE72AFB0F5DEA0ULL, 0x408CD3FCB52ABD68ULL, 0xCB59AA11C042FA00ULL, 0x72393097E399BC3CULL
        },
        {
            0x5E05F18EB74C6ACCULL, 0x632AF3F38C3DFC28ULL, 0x35D9277998FEEFBEULL, 0xE35F564555501907ULL, 
            0x622EAEE06686FF61ULL, 0x27E807E3D25DCE93ULL, 0x6A827F961150A615ULL, 0x8FA254D78DC91A0AULL, 
            0xD11CBD57929D9193ULL, 0x8ADA1555DF4F34D5ULL, 0xFF20F539CF37E002ULL, 0xAC11DF1E35360D1DULL, 
            0xC8434526EDBB71C6ULL, 0x346FF00E6A391082ULL, 0x80B2EFE6FD3D083AULL, 0x054F53B93767338BULL, 
            0x1BD04BFEDD860E5BULL, 0xD8CE688D58620862ULL, 0x261D16F3CA47F6EBULL, 0x86321F4178FF19D7ULL, 
            0xA4AA059010123605ULL, 0x2A883331DAFDBC7CULL, 0xB030B81100359F79ULL, 0xEE535BDF3025D28CULL, 
            0x44968A082A27F477ULL, 0xB31E6A010D5CB9ECULL, 0x0374262C01370A30ULL, 0xB1B9E2B45E623627ULL, 
            0xD2D6EF0551EE07D9ULL, 0xEAED981CD2512D8BULL, 0x8B3E3E747B49F94FULL, 0xE927E98EF8B91AF0ULL
        },
        {
            0x12B034B632706832ULL, 0x047AC3751CB8EBE1ULL, 0x7E7126B047F4E346ULL, 0x9AAAEB45B7146D40ULL, 
            0xFEDF1FB010C76386ULL, 0x826372636B794869ULL, 0xCF9F56758A55B8B4ULL, 0x193A84B79506DA0FULL, 
            0x01392900A091D500ULL, 0xDD1C4C78F55A55FCULL, 0x497960E58423E9A9ULL, 0xF935450E9C2A651EULL, 
            0x2E0E623808AEC58BULL, 0x81E74848D35EEF31ULL, 0x1A60A24D93F7E9BFULL, 0x6BFF6E60939F1FE1ULL, 
            0xF1B093B39EBA27BBULL, 0x97AFA52B4688EA81ULL, 0x912C59950C2C0593ULL, 0xC5EE398A505CBE14ULL, 
            0x6AC0079F5AC1487BULL, 0x4D6319AE3845F98CULL, 0x57D2F3BE3778F5DAULL, 0x67B269FC39E259C7ULL, 
            0x6E869F106D37EB9EULL, 0x23FDB90D79845D83ULL, 0xBAF05B51D9F4FF14ULL, 0x6BF376A4C6308237ULL, 
            0xB279A5C154801CDAULL, 0x938777A8CFC8441CULL, 0xF50301DB52199776ULL, 0xBF52CCBC7167C3FBULL
        },
        {
            0x6857833F77E8D802ULL, 0x38F4C3889A9FABEEULL, 0x63DA38D1EB08F425ULL, 0xCCB9F8B0ACA240BFULL, 
            0xF2989715525CE551ULL, 0xC66DE028CABB3C40ULL, 0x7721F4054E139CBCULL, 0xC5D6999F7FFC00C4ULL, 
            0x0796BC64E36E3124ULL, 0x0B2C63185915F745ULL, 0x240495F93EE91B91ULL, 0x34B7C94E77143646ULL, 
            0x5C6A2500BE50ED37ULL, 0x5526C074F90934CAULL, 0x618BA4D240D7A0F4ULL, 0xB14E827C6D154A5FULL, 
            0x3CB942C33745A8AFULL, 0x38C263DEFB6677C0ULL, 0x787CAB3A17CF2D85ULL, 0xD01BC352E9CB959FULL, 
            0x1C3D0A8724335461ULL, 0x22F4581046A533D1ULL, 0xC0747C4AEABA72B8ULL, 0x162704031078F72FULL, 
            0xE300978D785AE71CULL, 0xA44CC4021B9F39D6ULL, 0x774AEDACB52752D5ULL, 0x4028C14BC1A357B2ULL, 
            0x9F7D475CB2F5CD1DULL, 0xB4D2A4ADB6605CE0ULL, 0xFFA702EBC06DFD52ULL, 0x3340EA4A3EE4C377ULL
        },
        {
            0xAD6AB99F3865377CULL, 0xF28DE5431F28D5BEULL, 0xDDF954AA298F2572ULL, 0x2401EFB1E1919568ULL, 
            0x911583C0C7E98485ULL, 0xB8343B143136DEDFULL, 0xDDEA4357A584858FULL, 0x9F079130B58D2455ULL, 
            0xF557FF42C87AD049ULL, 0x6F56F69953CD0AD7ULL, 0x82F70EE2EA5DA7DBULL, 0xEA140318A74B0B89ULL, 
            0x6F76FAF00088900CULL, 0xCD50021383D5D9ECULL, 0x489B34881B4A7AE2ULL, 0x6E8125C0B2935EF3ULL, 
            0xB19E25576C254119ULL, 0xB618732FBC745BB9ULL, 0xBF1AC82943311739ULL, 0xC0F58FD5DBA27F3CULL, 
            0xF5A7F13244385F24ULL, 0x41927C83982F55CAULL, 0x4984181312C52C4CULL, 0x45BEA91536095C51ULL, 
            0xA6FA5F137907A078ULL, 0xD37D2EBC1216FDC6ULL, 0x85D36786AB966A33ULL, 0x204D16BED58DE626ULL, 
            0xBC8BDEDDA7D6FD37ULL, 0xBCB0571003F70424ULL, 0xBEB104830315B7ABULL, 0x58FE36D27B4BE94CULL
        },
        {
            0x7318EBAA79B7F782ULL, 0x8CACDC30597E9331ULL, 0xB6D8EE1940E59375ULL, 0x90CA313C16500E66ULL, 
            0xA25B320AAC1FFC28ULL, 0x3489A833A88906A0ULL, 0x419A8CB6ED22ED8CULL, 0x2B490937E73B2211ULL, 
            0x46620823CC66FB97ULL, 0x9719840CBD43A7EBULL, 0x98D6F9F961177941ULL, 0xA5FF1BB6E5201259ULL, 
            0xCB04F2E192698687ULL, 0x7BDA52DF49F64A17ULL, 0xB3EF7940BE359FF3ULL, 0x51A417EA8FF86306ULL, 
            0xDAD52C645BAEA524ULL, 0x3BCF2172C27D5161ULL, 0xBD775365368DCF7AULL, 0x7116558D82625242ULL, 
            0x4E234E01AB00DD2EULL, 0xDDA1A9D82FF802DBULL, 0x854127133D98C46CULL, 0x986723FB70DB0A65ULL, 
            0x8720D33EC01A7C6BULL, 0x22C0AB8D210D2314ULL, 0xDED35B682087A35EULL, 0x7E3C1712449202F6ULL, 
            0x4DE7F1E6B76F4587ULL, 0x997257120D9824C2ULL, 0xC7BC64705EEE3BC3ULL, 0x56A0E233C455BD06ULL
        }
    },
    {
        {
            0x01CF283D5FEFC5BAULL, 0x151CD5800C43D328ULL, 0x17DA88CF8361AA57ULL, 0x8B2A3EED547A9E42ULL, 
            0x58F05FF3F85C4C23ULL, 0xDD3965F40266DC76ULL, 0x4274A83C8D8E27B6ULL, 0x0535CD7C5E5084F8ULL, 
            0xB8C93C8C4C34AADDULL, 0x55D8B6CDAC5C77D0ULL, 0x29436760FD356B40ULL, 0xA7DC231DA8E50611ULL, 
            0x4206CEBAF7312C7BULL, 0xDFCB07CBE7E5C9A2ULL, 0x5F0EBFAB4071CAA2ULL, 0x916F0FF78AE5CDE3ULL, 
            0x9235499BAE310476ULL, 0x5E43F1877B4D7788ULL, 0xCFFAAFCFFE740084ULL, 0x3C85CF6BF5D2C4B6ULL, 
            0x9D523CECC90AC1CAULL, 0x20E5C5EEFD1FEFD3ULL, 0xAA707EAAB25067E6ULL, 0xA1FB43F4D11EC895ULL, 
            0xB4B293E9642A6249ULL, 0x99890DFE89E8C871ULL, 0xBE0660E9572DF934ULL, 0xDB39B377A5E1F87EULL, 
            0x70A06BF7B35420E2ULL, 0x40FD1F600190DD14ULL, 0xA1D201F6AD9EAF2AULL, 0xC755E2B6EEAB720AULL
        },
        {
            0x717E59806A8E3CF1ULL, 0xAD0045BD202FCF39ULL, 0xF05D583C43DB5D7FULL, 0xED3DC6FD4FEA2F82ULL, 
            0x55DF921A2F683FC9ULL, 0x62F4DDC75608D16FULL, 0xE759D2DF111C1AF2ULL, 0xBF23750E8F416803ULL, 
            0x7710A34C383A92BDULL, 0x275A7D6B21F983ABULL, 0x738D91FA5CD53ABDULL, 0xCD3199FABE08B781ULL, 
            0x52EECDF96022CA09ULL, 0x493655C8AE65831AULL, 0xB98ABB4599EF6A78ULL, 0xED3822DE11DB4FC9ULL, 
            0x87F19D5E36DAB7A8ULL, 0xB4F1A96D7797BDD4ULL, 0x1E3CB5E7F169F970ULL, 0x9118BA7721D8A578ULL, 
            0x4AF8F40F4AB025DBULL, 0x9265B78CC52F507AULL, 0x09A5B0AF1D9C6511ULL, 0x1A01B84C25174785ULL, 
            0x7C3E5A20A03FCDB0ULL, 0x9386268229098AC4ULL, 0x80DA2E57C9F16EE5ULL, 0x8C2AE36973C46F44ULL, 
            0x2D20D36921A751FCULL, 0x1E28E57041E8A276ULL, 0x01A3287CC8FCC5ECULL, 0x4B91E6E6D3B3A72FULL
        },
        {
            0xBAA0C0E0D51E1B78ULL, 0x8AF69316B5871CBEULL, 0xD7A345A2DBA9AA69ULL, 0x7BCED922BAC551ADULL, 
            0x002A9C9B11F2875EULL, 0xD7C1F92BF0B5E8B7ULL, 0x1E2862270516A00AULL, 0xEFDB15194CC303BBULL, 
            0x0559EECB1A81AC03ULL, 0xF35F338972A9704FULL, 0x10AD9EC5B9DDF314ULL, 0x78A4E7891ADF6411ULL, 
            0x23D94EDFC52E8E7DULL, 0x5F4533380AD45785ULL, 0xEE6B2B576E930267ULL, 0x8CF86194CCB7D005ULL, 
            0x1D0F2A950B0E43FEULL, 0x499C333AB62D06C2ULL, 0xD6D9C155140615E1ULL, 0x1B756CC35F6F379CULL, 
            0xB0D21E7025B07AACULL, 0xEB92BE8E5C6E43E8ULL, 0xC8779D8DB4722069ULL, 0x2F669F20A0AD641EULL, 
            0x799120D00B3E99DBULL, 0x792138984E3FF50BULL, 0xCE0ECEADA4099421ULL, 0x636FA9CD5CA078FFULL, 
            0xD0048B7423BBA76CULL, 0xE3F18B78F0C8C448ULL, 0x2EE0AB8F15FBBBA1ULL, 0xB3140D59FCA26847ULL
        },
        {
            0x35AE4A920DDF691BULL, 0x8C55059AB3F29E63ULL, 0xD7814BDE31617E55ULL, 0x11E83DD2F4E94A56ULL, 
            0xC62FC0EA8501610AULL, 0x877F8E59522D29C6ULL, 0x0D9AC320EA49C0EDULL, 0xB0D83BE72B1C68E8ULL, 
            0x713D1D405F0F78D6ULL, 0xD9CDEF9F4E7BFF9BULL, 0x818B19ECA191D6C7ULL, 0x96A358C330D15CCBULL, 
            0xAD6AE088DC9B2BB5ULL, 0xFC34907C6ED6BF87ULL, 0xBB45AE64107B1C56ULL, 0x77E050DEF7DF802FULL, 
            0x0A25E996DB149937ULL, 0x5D0C7E2935D7742DULL, 0x2BC030ACBBE3985AULL, 0xD0D2F69576388A3DULL, 
            0xD2E6B935595F255DULL, 0x3251AA4D28A4735AULL, 0x989596D03410FD56ULL, 0xFD284CC291A12FF1ULL, 
            0xF3FDB12833994A7EULL, 0x7B4B81AF4DE3FA08ULL, 0xB740E744E73980BFULL, 0x29B9EC59834CCF9DULL, 
            0xEA7F0817FFF39E10ULL, 0x2CBBAEA266846826ULL, 0xDCC1694D97570D55ULL, 0x1F6E3E2329747F7EULL
        },
        {
            0x6A42D8BC32565251ULL, 0xAE80AA7CB99D189EULL, 0x38255FF459E15815ULL, 0x4489F9795BE17A67ULL, 
            0xD8DA4B670E22BDDAULL, 0x09FEC81F63062E0AULL, 0xD912883F010A1937ULL, 0x11C65B860E708086ULL, 
            0x391701AB8CC686D8ULL, 0x67A2DED9CBB7C0DBULL, 0x79491962C20566A6ULL, 0x53E77298DDFFEB57ULL, 
            0xB8ED8887516F94E0ULL, 0xCEE9E75A992AB285ULL, 0xC08CD481F6113FD8ULL, 0x012FB69C440F8F6DULL, 
            0x5FF7DFFAFD09C5ADULL, 0xBD6E931AD6EB8A43ULL, 0x26AC99ABA8189489ULL, 0xDA550A1A0A37B3D8ULL, 
            0x51E9E6B7A2EF8AD5ULL, 0x00A0916114069862ULL, 0xEE5B5DE89A49A585ULL, 0xB7D71DB388CF63FDULL, 
            0x68C6C04E63E0DE75ULL, 0x0534CF7D926ED090ULL, 0xA38E7258B10702C2ULL, 0x4B6B18AF1973978FULL, 
            0x255248BA7BC0547DULL, 0xF4C06F726A3C68C9ULL, 0x3B785232A882070BULL, 0x7998924C5626DA84ULL
        },
        {
            0xCDD87ECCD5F57E0DULL, 0x0C6828AC9FB7328AULL, 0xD05BC8425A331336ULL, 0xD172517EA34757C2ULL, 
            0x9312988629511294ULL, 0x35B52EC56F779D79ULL, 0x6DCA3D74C97ABAEFULL, 0x5915FC561273BC37ULL, 
            0x1B9D2DEAE20FCA34ULL, 0xDCA9144C1808D6AEULL, 0x35DFE6C60015CB96ULL, 0x228B34B24A2538C8ULL, 
            0x95318DC8B9955F47ULL, 0xF3F1B8FC3D39C5D5ULL, 0x6CE9CE960A978FD5ULL, 0x8D3DFAE47380B7FAULL, 
            0x3135D01133175298ULL, 0xBF5DA7A8D029F2F0ULL, 0xA23EBC22CC388A20ULL, 0x085E59540A8FEE6FULL, 
            0x0B1F930084FC0D31ULL, 0x9706324074FB9CB7ULL, 0x04EAC3541D6CD71BULL, 0x6BB0D843C18C9748ULL, 
            0x61775C40CE5A9600ULL, 0x438AC298DF4DBABBULL, 0x1794566969B26D09ULL, 0xA8CAC65A72BDDEBAULL, 
            0x059A1AE378E98863ULL, 0xC80DCD0F94757D8CULL, 0xE91D8710EF160539ULL, 0xD17D8E3636967506ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseHConstants = {
    0x8A9B5436A2D21813ULL,
    0x317AD69A8E7EAE1AULL,
    0x5528AB7EFCC6A414ULL,
    0x8A9B5436A2D21813ULL,
    0x317AD69A8E7EAE1AULL,
    0x5528AB7EFCC6A414ULL,
    0xFB1F1A9A360C8D71ULL,
    0x2E52A464EA2BC1DBULL,
    0x1E,
    0xBD,
    0x18,
    0x44,
    0x67,
    0xB8,
    0xD9,
    0x55
};

