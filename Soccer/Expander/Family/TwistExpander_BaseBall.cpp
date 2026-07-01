#include "TwistExpander_BaseBall.hpp"
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

TwistExpander_BaseBall::TwistExpander_BaseBall()
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

void TwistExpander_BaseBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD9738120F049F8DEULL; std::uint64_t aIngress = 0xF3A13063ECA62B30ULL; std::uint64_t aCarry = 0x8D54BB4B8911495DULL;

    std::uint64_t aWandererA = 0xA5C734C0C9A49A43ULL; std::uint64_t aWandererB = 0xE7B78A6348EB8E49ULL; std::uint64_t aWandererC = 0xB3A64C68015C4846ULL; std::uint64_t aWandererD = 0x9C72A0BDF95C57D2ULL;
    std::uint64_t aWandererE = 0xF08AAE85A8C58B83ULL; std::uint64_t aWandererF = 0x847D576A3281ADB8ULL; std::uint64_t aWandererG = 0x8013D1AAF19634E2ULL; std::uint64_t aWandererH = 0xB29C9C802F6FA735ULL;
    std::uint64_t aWandererI = 0xEC731AA70AD31232ULL; std::uint64_t aWandererJ = 0x9C85462A8F7FF1EAULL; std::uint64_t aWandererK = 0x995DC82B2FF8C2F1ULL;

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
        aPrevious = 12792248109541286354U;
        aCarry = 14407493509911825742U;
        aWandererA = 15922237030783324906U;
        aWandererB = 13645334156174251502U;
        aWandererC = 9567818708300420562U;
        aWandererD = 10396222741689256622U;
        aWandererE = 13995983984468574148U;
        aWandererF = 9285251819848267417U;
        aWandererG = 13893915138035933517U;
        aWandererH = 12269361553640317945U;
        aWandererI = 18337777354200610263U;
        aWandererJ = 13508047642611210292U;
        aWandererK = 11990499202934333190U;
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
    TwistExpander_BaseBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_BaseBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB2EBE614D0F0BBB1ULL; std::uint64_t aIngress = 0xD2A9F8667B8F5522ULL; std::uint64_t aCarry = 0x81CE7B3D4C77ACDFULL;

    std::uint64_t aWandererA = 0xBC12D1C7E73C377DULL; std::uint64_t aWandererB = 0xBC15943AF6A8737DULL; std::uint64_t aWandererC = 0xB6F7A406C7C29DE2ULL; std::uint64_t aWandererD = 0xD01972294DC21D01ULL;
    std::uint64_t aWandererE = 0xDC15EAA22BC835A5ULL; std::uint64_t aWandererF = 0xF38BEFA1CDE71F01ULL; std::uint64_t aWandererG = 0xBB822D1836BFE8F0ULL; std::uint64_t aWandererH = 0xD9DC0DA6D97508B4ULL;
    std::uint64_t aWandererI = 0xF3C9ADEFA76D4E1EULL; std::uint64_t aWandererJ = 0xE91969C600EED960ULL; std::uint64_t aWandererK = 0xCB95C3B868C0EBD4ULL;

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
        aPrevious = 12809264553336687722U;
        aCarry = 15937175675781283816U;
        aWandererA = 13253500696869817643U;
        aWandererB = 12419141645507030021U;
        aWandererC = 9242264720637402159U;
        aWandererD = 11911595599721418970U;
        aWandererE = 18316190035723771138U;
        aWandererF = 14871717730491997443U;
        aWandererG = 15515658944347199645U;
        aWandererH = 17635362368326293440U;
        aWandererI = 18436225010301795788U;
        aWandererJ = 18383150680225060984U;
        aWandererK = 14800423995231534732U;
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
    TwistExpander_BaseBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_BaseBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9256976C77043470ULL;
    std::uint64_t aIngress = 0x8760AB6F12AB45BAULL;
    std::uint64_t aCarry = 0xE545077A9296F445ULL;

    std::uint64_t aWandererA = 0x943951817D74D3D6ULL;
    std::uint64_t aWandererB = 0xAA4D77CE2454E4DAULL;
    std::uint64_t aWandererC = 0xDD9E8E49FD9AF1A7ULL;
    std::uint64_t aWandererD = 0xF4E6D29B2F788ECFULL;
    std::uint64_t aWandererE = 0xD6CA026145235A1EULL;
    std::uint64_t aWandererF = 0xF8D30C324B8F4A67ULL;
    std::uint64_t aWandererG = 0x95E703E1A5544569ULL;
    std::uint64_t aWandererH = 0xAA664CE347C9DCB6ULL;
    std::uint64_t aWandererI = 0xE1D3FE8AF0B2D2B1ULL;
    std::uint64_t aWandererJ = 0xAF0E8480B274E66AULL;
    std::uint64_t aWandererK = 0x92306A571D03A320ULL;

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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    TwistExpander_BaseBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_BaseBall_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_BaseBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_BaseBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD782D2FDE9AED1ADULL; std::uint64_t aIngress = 0xF5BF0CB92B05506AULL; std::uint64_t aCarry = 0x9FDBBE3E5BA4B974ULL;

    std::uint64_t aWandererA = 0xAE55432016A26FD2ULL; std::uint64_t aWandererB = 0xDEEEBA0E95FF6AD8ULL; std::uint64_t aWandererC = 0xBA5F94D35573CC95ULL; std::uint64_t aWandererD = 0x936148FF5B69D03EULL;
    std::uint64_t aWandererE = 0xA783654F2AA979C1ULL; std::uint64_t aWandererF = 0xB5E7E405E40576CEULL; std::uint64_t aWandererG = 0xABF9D9BB29E77300ULL; std::uint64_t aWandererH = 0xD820F10A38024642ULL;
    std::uint64_t aWandererI = 0xE607BA7C6A06538FULL; std::uint64_t aWandererJ = 0xD894C3AA8C9CA494ULL; std::uint64_t aWandererK = 0xAE424242FB2242F1ULL;

    // [seed]
    {
        aPrevious = 9418407071694055147U;
        aCarry = 13520829274155274595U;
        aWandererA = 17276704607580617630U;
        aWandererB = 18210571503710217572U;
        aWandererC = 10652029855919779658U;
        aWandererD = 16498258774455221298U;
        aWandererE = 14400673922496142360U;
        aWandererF = 18322243744823264476U;
        aWandererG = 10235295067565048703U;
        aWandererH = 9599191372974115066U;
        aWandererI = 11041266877865156095U;
        aWandererJ = 11099796875660457783U;
        aWandererK = 13900247318191012833U;
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
    TwistExpander_BaseBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_BaseBall_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_BaseBall_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_BaseBall_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_BaseBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 0, 3, 3 with offsets 396U, 4354U, 3486U, 1810U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 396U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4354U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3486U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1810U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 1, 2, 2 with offsets 6037U, 6412U, 6827U, 4110U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6037U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6412U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6827U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4110U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 3, 1, 0 with offsets 3203U, 1885U, 1106U, 189U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3203U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1885U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 189U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 2, 0, 1 with offsets 1261U, 3520U, 3275U, 2528U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1261U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3520U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3275U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2528U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 3, 2, 0 with offsets 129U, 834U, 227U, 1560U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 834U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 227U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1560U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 0, 2, 3, 1 with offsets 1271U, 330U, 319U, 1337U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1271U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 319U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1337U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 0, 1, 3, 2 with offsets 1377U, 334U, 1031U, 1651U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1377U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 334U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1031U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1651U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 2, 0, 1, 3 with offsets 161U, 406U, 1812U, 1829U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 406U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1812U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1829U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1059U, 1791U, 925U, 671U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1059U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1791U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 671U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BaseBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 1 with offsets 2990U, 6985U, 463U, 4989U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2990U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6985U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 463U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4989U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 3 with offsets 6880U, 2066U, 1561U, 176U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6880U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2066U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1561U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 176U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 0 with offsets 1764U, 92U, 384U, 735U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1764U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 384U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 735U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 2 with offsets 4648U, 5592U, 1193U, 3186U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5592U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1193U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3186U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 8105U, 2516U, 4325U, 1792U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 8105U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 2516U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 4325U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 1792U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 2036U, 106U, 1437U, 962U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2036U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 106U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1437U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 962U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 937U, 427U, 1255U, 12U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 937U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 427U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1255U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 12U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 123U, 1685U, 1386U, 276U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 123U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1685U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1386U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 276U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1794U, 780U, 846U, 1268U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1794U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 780U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 846U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1268U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 321U, 1075U, 996U, 1998U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 321U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1075U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 996U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1998U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseASalts = {
    {
        {
            0x3EB6043CC8769F77ULL, 0x7F718C41395F6BAAULL, 0x63C10F582FDFEB1BULL, 0x8F212F0AC30041E7ULL, 
            0x9931D4F81EC530D9ULL, 0x4BF3941CA6459547ULL, 0x4604EFB8C0D86BACULL, 0xE1EDB508EBD36CACULL, 
            0x8B74847A71BC368FULL, 0xB464FDE0DB472010ULL, 0xDE974395063CEE70ULL, 0x218B8ED39E19CB49ULL, 
            0x5632395D89BCD207ULL, 0x832A359528C9DE6AULL, 0x69EAABC431F78C07ULL, 0x326F1200D5E37A4DULL, 
            0xCE463404341F85C3ULL, 0x5DA75EDDE4790821ULL, 0xF909DFAAEBE24F96ULL, 0xA09D8178042D40E6ULL, 
            0xF7C331927E0BEFAEULL, 0x51B284EEB7BED7D3ULL, 0x07D4C9AB2DC2C85DULL, 0xE182BB9967C34D76ULL, 
            0x9B4A1EEE83BDFB04ULL, 0x1887E02ACD9057BFULL, 0x0E0955B27E43F227ULL, 0x095D4E0F9D9978F1ULL, 
            0xDC1DFF297F33DB9DULL, 0x2B01A94D3A8C2128ULL, 0xC8D937FFFCB2A1E0ULL, 0xDEB21C987544BA64ULL
        },
        {
            0xAA233B758597FC9CULL, 0x6E291B903AABE4CCULL, 0x5B2B7A53774F7E35ULL, 0x95909968498BB9B8ULL, 
            0x7BAE1F729A193AC2ULL, 0xCFF66F6ED85F4930ULL, 0x513FD6C1B8356504ULL, 0xCA078942E34CD6B7ULL, 
            0xBED589146D4C523AULL, 0x5E1605610604EA42ULL, 0x7BBD6CD9F83ADAABULL, 0x0E876E0D3F5E92CAULL, 
            0x39DE7D69C4F81F31ULL, 0x308D0E8920F64613ULL, 0xC564E4F24333F56FULL, 0x89D77486EB68F223ULL, 
            0x7AC11930B2E1B166ULL, 0xBF8A611D0045B2D5ULL, 0x62B76BC8B3FA7CA0ULL, 0xA701569CCC304643ULL, 
            0xB1C0785A4C7F504CULL, 0x4ECF63BA3C61BC85ULL, 0xFAA1530143FAA6CAULL, 0x8D649E580E201449ULL, 
            0x623FB72D2AF254E2ULL, 0x59E877324FC00D33ULL, 0x6BF5747C813DF062ULL, 0xB87F30B78CE42B83ULL, 
            0x81931A3BA815CE66ULL, 0x4BD9324EB275B280ULL, 0x49FF880B2D2040BEULL, 0x82FAB18BA53245F9ULL
        },
        {
            0xA654007492B4E093ULL, 0x2425398C4C52DB65ULL, 0xFC6614464E13A3C4ULL, 0x21214592EEC15F48ULL, 
            0xFC107CC52DA55819ULL, 0xB6C7806AD3C1DDD3ULL, 0x191E5E1AE03BFA7CULL, 0x0542B6E4F6ABBA2BULL, 
            0x8213083B5028D24DULL, 0x01226AF90A89C3B4ULL, 0xD4C36D1257C28B7EULL, 0x5B8334A60BE26116ULL, 
            0x1FC63FD37D571AFAULL, 0x50E353B906E5A2D0ULL, 0x244E597986592650ULL, 0x451EEA2EDFF31FCDULL, 
            0x0B05683EA0B97A52ULL, 0xBEDC3FF3A5B1BBF8ULL, 0x30AE79E66CE732C3ULL, 0x625088E378F4C0C8ULL, 
            0x54EC0E6C04237C2EULL, 0x98B2174C1F194A26ULL, 0x45BE1EADE43C6F13ULL, 0xE9A3A1326F341CD9ULL, 
            0x0C9F15B3558B6887ULL, 0x652AC7399CF58F61ULL, 0xB0B7BDE5AA8233BDULL, 0x7631417AD731BACCULL, 
            0xFDAEA746B4DF04DFULL, 0xD22B32E4AAB7C63EULL, 0x2A8E5F6F721A1F20ULL, 0xA23B8002EF469CA7ULL
        },
        {
            0x96E27E9A22E8FA15ULL, 0xA5E64B2FEC8AE4B2ULL, 0x178A293AF0FFD865ULL, 0xD2F1C28B3103750BULL, 
            0x3B0F3C53A2698EE1ULL, 0xEFB6434CE574781EULL, 0xF9640A726AEFD5EDULL, 0x39B8EBB544A749E2ULL, 
            0x2F95CED81D09F1B2ULL, 0xDDB6DADF18F97EE2ULL, 0x94DF3E144DDB312FULL, 0x5DEAEE4923F9BDD2ULL, 
            0x776797C0276F1284ULL, 0xB19C0B60DCC5C8F2ULL, 0xC975CFF7CB3AA905ULL, 0x7202CB5353EA61B0ULL, 
            0xF4E05E26A11AB24BULL, 0x86A26BAA29BCD1C0ULL, 0xF1A03F9A86D7A79CULL, 0x87E516113E0861E3ULL, 
            0xF76F9E2FE4DCF950ULL, 0xBC1B219587874D31ULL, 0xD018C84EE42B7D18ULL, 0x2EA974B764962D95ULL, 
            0x0852024A8260E079ULL, 0x08DF524C979A9C84ULL, 0x3CB9BA52BE5B0FF5ULL, 0x7114952135DBD709ULL, 
            0x74620BDD91E8E2FCULL, 0xF555E00296FAD183ULL, 0x38C839849F468DE1ULL, 0x7606AA3ACFA61E41ULL
        },
        {
            0x5F938D2A8F08D86DULL, 0x9FAF9BAB06512422ULL, 0x2825658E28B7CB64ULL, 0x361CFD65937CC552ULL, 
            0xC4A59917A3EF8FE2ULL, 0xFDE8B22C655AFA99ULL, 0x65930C41ECE8AC33ULL, 0x6114BBBB4C3191F9ULL, 
            0x9A9FDF3D8C9A5CC8ULL, 0xB1A1218337CA8CD7ULL, 0x3FC1AD04589564C1ULL, 0x631ACE6D74FD67F3ULL, 
            0x8FEB20E212D617D1ULL, 0xAADAB5A17E076582ULL, 0x6B2AD2A10E0A71A8ULL, 0xB4D45B8B721246A8ULL, 
            0x81483C436931125DULL, 0x7CA2A25C51B5DCA2ULL, 0x3908647DDB14929EULL, 0xD988E12DC13F4E59ULL, 
            0x82C064103C43417BULL, 0xBCA72B1648302D40ULL, 0xEBF3807A13F8CBB5ULL, 0xDAE513BC13442497ULL, 
            0xCE94A9FADFED9908ULL, 0x3DB3DC61F1772164ULL, 0x833A3EA8D5D69B4BULL, 0x16FBE415A7DD4162ULL, 
            0xC00CC7286A5F6637ULL, 0xC05B50C423861C2BULL, 0x64396AFD22FE9805ULL, 0xBFB723DB4FD64E60ULL
        },
        {
            0xE0B4FFEA521200DFULL, 0xDC5E44EB8D9E5CFBULL, 0x11097EA2445023FEULL, 0x79D557CA0F96AF31ULL, 
            0xC4E87A631EE69137ULL, 0x2DC3A12191D7D473ULL, 0xB9B54BA0ACF02BA0ULL, 0x95E0C0E8DD7A5C01ULL, 
            0xBC7FE921BB668113ULL, 0x6446F8431BBE402AULL, 0x9A3098F3114F2338ULL, 0x0A8F7F4DBED3B800ULL, 
            0xD5CEE7D755F7A2F7ULL, 0x355E1F712ED528A6ULL, 0x7A0FA9A1081FBE4FULL, 0x1BEC863E595FC52BULL, 
            0xD23FF2599EFEAC96ULL, 0x427667B411DF0A3FULL, 0x66ACB9E45C66BD58ULL, 0x6E7019D5A6D0FF9EULL, 
            0xE4CEA9E9DC0A3B87ULL, 0x75CFC33E3AF660E5ULL, 0x866772BF064EE508ULL, 0x13116F1684FDC425ULL, 
            0x316556CA43D13D73ULL, 0x6530E8D02520789BULL, 0x007BB2B713064416ULL, 0xD5D816D255FED435ULL, 
            0xCF78B2A56A8481F6ULL, 0x5115B941E27460CDULL, 0xA535EA0D78D81A33ULL, 0x338AA98829111159ULL
        }
    },
    {
        {
            0x9EE78A728EFE1A88ULL, 0xED59270D28AAF4FEULL, 0x220F5B5A5F5CEB71ULL, 0xF8DA0D88727FA2E9ULL, 
            0xDECE7B5230DC24EAULL, 0x2726B4B4B1AB97EBULL, 0xA572DA52FC0129B5ULL, 0x7B620EFE0A59A7D1ULL, 
            0x84F613885AA43640ULL, 0x1B990D47602C998FULL, 0x279D770973FC5575ULL, 0x882ABF987526CAE2ULL, 
            0x92CCA6BED4C11815ULL, 0x6F80E330FED022A6ULL, 0x1426FB40895B7E35ULL, 0xD5D20BAFA0622E8CULL, 
            0x11FB50ECAAAC0AB6ULL, 0xA1832EE6961462D9ULL, 0x623384CC27B5BEE8ULL, 0x8CBD727B7A151059ULL, 
            0xA9C08E809712A7F6ULL, 0xBAD82743CBD7A366ULL, 0x58105B418D974B15ULL, 0x30656F05F11F11ECULL, 
            0x07DFF98410DEEBCBULL, 0x41A0F87E7557A278ULL, 0x5E05611265087AD7ULL, 0x30073E85FD3358A3ULL, 
            0x4020830A4409CAB8ULL, 0x529C1CA00C1966A3ULL, 0xBDB67E2A780E436AULL, 0xEB1743BC555E4B4AULL
        },
        {
            0x605725CB6BAF6CD7ULL, 0xAE262A02AC0ADA26ULL, 0x27BA7614E93B8D0FULL, 0xE4AB593F6D554563ULL, 
            0x4AD5AE908A8E1D59ULL, 0x3E3669B14CE0C018ULL, 0xF8B72C7A2E31099BULL, 0xE8764C3BA2FA1250ULL, 
            0x7729297B6C81B2E2ULL, 0x412F74097BF183B5ULL, 0x09BA330B88CF892BULL, 0xAE57278CC23B78A1ULL, 
            0xE13534B81AB1AF40ULL, 0x238E71C5B6DACB81ULL, 0x08C6F8FDE6071D11ULL, 0x5B6EDF039F9F7255ULL, 
            0x0F0FFD57F31820D0ULL, 0x88A4BA7EDFD259D7ULL, 0xC682F28EABBB138FULL, 0xDFEFD3B591136B1FULL, 
            0x35766A8F2DB204DBULL, 0x49A58557A8ED69DAULL, 0xBEA096AEDF05E3EAULL, 0xB68ECF1435D908DDULL, 
            0xC95180BB841B7654ULL, 0xC12DDC89589ADD01ULL, 0x4AC817A33BF3A394ULL, 0xF5985E82DDA2C9EAULL, 
            0x20E7DC3939B66B0AULL, 0xEEB9BE1086F70FE0ULL, 0x6CEC22808F6A3AFAULL, 0x7BD1CF65571DBDF9ULL
        },
        {
            0x696754995FB739D0ULL, 0xBD0ECD6FE86AB9FDULL, 0xC223CFD59CE436D3ULL, 0x652FBC792127E2E7ULL, 
            0x8CAA88D274342808ULL, 0xCCF0C67C5C80DA01ULL, 0x6FDA4F24F1BE6ED4ULL, 0xE64EDB7B64B5CD81ULL, 
            0x6E7CBB16D0350F2FULL, 0x70F392EE3F88D2FEULL, 0x2ECE439A95BB78C2ULL, 0x2A30B163749A9B6AULL, 
            0x2C0906AEEA4C9D56ULL, 0x1F97C8719DD43AA8ULL, 0xE822441BA4BB3B18ULL, 0x622FE20125CC5B09ULL, 
            0xADCBC2AA7664B6D1ULL, 0x3D27489D72079018ULL, 0xDA87089D36165436ULL, 0xB8CEC91775603776ULL, 
            0x8A67A009C1358EF8ULL, 0x46C02BCAADD7800DULL, 0x93C61D154BAA900AULL, 0x0B89A61075EC6FA4ULL, 
            0xCD58F00B974043DFULL, 0x98011B95370BB171ULL, 0x7B7DDBD2F7C05AA2ULL, 0x7935B9B03341FFA8ULL, 
            0x810195FCDB08CE2EULL, 0x6A947F364C6E68C0ULL, 0x6C799AA11EE18D81ULL, 0x0AAA20BA35CDF9F3ULL
        },
        {
            0x5BAF237F3A0A3624ULL, 0xA661848EDEE9A4EBULL, 0x92BB6424B087477AULL, 0x47BC40DA28140D20ULL, 
            0x873C5730C1B6EBD6ULL, 0xEEB6486FD7D5ABF4ULL, 0x2BAACD9656EF94A2ULL, 0x140E74E3431AE7DBULL, 
            0xD96559D97DD8D645ULL, 0x8A5086047469009FULL, 0x2B76F45670433D6AULL, 0xC22245C599787106ULL, 
            0x0A6A531AB20C4E08ULL, 0x3DDABCB319933031ULL, 0xFAEF4CA09255F604ULL, 0xB76568018B1728D0ULL, 
            0xF3186D6A4B0BE87AULL, 0x1FFF0AC22913E1F6ULL, 0x927DE8254696905AULL, 0x08C46B56DBE9347BULL, 
            0xFAB9134FFBCD59D0ULL, 0xF78FD2826B134AA3ULL, 0xDB68FC139E5E35D0ULL, 0xAF7AE3BF14F8B069ULL, 
            0x51A549FCA08702A8ULL, 0xB2949EA7B2468591ULL, 0x90680BAA085C53BAULL, 0x506DB7F2D185A027ULL, 
            0x9E5A84E87970A26EULL, 0x897B52735507EDDBULL, 0xADC684913BA3526FULL, 0xA20D3316A2A6BDB2ULL
        },
        {
            0x77DB01494DD1C680ULL, 0xD806BDBC1096268FULL, 0x12622D7486492164ULL, 0x4585B771C02B5EBFULL, 
            0x033296CB22462E5EULL, 0x6C47FFAD7B37B5F9ULL, 0x21BB4B18E2916F8AULL, 0x5537D8C44BED97E1ULL, 
            0x3391E3AFE11E39DFULL, 0xE9778DBA8E1A3A52ULL, 0x75C6A16CA1615719ULL, 0xD0FE7BC057E5F54EULL, 
            0x142EEAA029D86314ULL, 0xBE5A459BB465F52BULL, 0x566FEBA7A5221A72ULL, 0xEDF860A0F948433CULL, 
            0xD74F94D1168A5A8EULL, 0x3CBC9D29C610617CULL, 0x76A1D166D3CFEE56ULL, 0xC18DB31350BFD584ULL, 
            0x0A6486C0F2BDD5ECULL, 0x0192C86C2BD9C302ULL, 0x523C696DCDB58B65ULL, 0xE85B331D17E559B3ULL, 
            0xD286480567D5822DULL, 0x62E88990A4B3312FULL, 0xAB3F9549295017EDULL, 0x6BE4ECC2C33AA767ULL, 
            0x0A22E26F828F0191ULL, 0xA47F3CA6CD71CCE5ULL, 0xFDCC37D6116D46F7ULL, 0x152106A9815CC7D4ULL
        },
        {
            0xEBB9F10B78AF7194ULL, 0xAE025A8C7CABB979ULL, 0x67D23A99D072ACA2ULL, 0x68C2549C11209677ULL, 
            0x3582FFB85074773AULL, 0xB79F82788BD8B4D4ULL, 0x567311B70021BB13ULL, 0x7D9A9352842551CFULL, 
            0x8358ACD861EF0D0AULL, 0xF39D65C3FD528869ULL, 0xB3BA693882BB24E2ULL, 0xE225402C14DF4C66ULL, 
            0x4EA747FB65836CFAULL, 0x92CA7D3D7A067867ULL, 0x716CEA7DCE8F4EE8ULL, 0x7BF972ADD1269A89ULL, 
            0x17A6794B1E4A42ACULL, 0x2E75972888148D75ULL, 0xFB9425B23296F7A7ULL, 0xF6D5DC4396651361ULL, 
            0xA576055363DDB500ULL, 0xEAEA4AB068F98646ULL, 0x00FB1531D4DA1194ULL, 0x7A07A1A28C534B43ULL, 
            0x959CF96B409A3A71ULL, 0xFE201C33DCA6D4F1ULL, 0xB8A466FECCC824F0ULL, 0xDF274BE8F8F2FAB5ULL, 
            0x9539304BA63C9886ULL, 0xA38BDF14A3F1B46BULL, 0x735D36FCAB5EED82ULL, 0x25192BCA51A3F890ULL
        }
    },
    {
        {
            0x90552DD5A13B5398ULL, 0xF2AD01CBB1C1C458ULL, 0xE48EE28C8A99FC09ULL, 0xB4A8952EDD9E0A36ULL, 
            0xEEDE2C4C18C5FA12ULL, 0x15C706E6B81BA1AAULL, 0x4B5F5FD3BC406D07ULL, 0xF29D1249546CDED2ULL, 
            0x808ABEF45E4C87F3ULL, 0x3AC3F910074FD665ULL, 0x37794B211AE9DBFBULL, 0x0FAC419C4633E46CULL, 
            0x4D056E56AE695D4CULL, 0xBF3EE3C062A351E2ULL, 0x769BCB9618F3A2BAULL, 0x694D5B8E8582A6C2ULL, 
            0xFDE28C9D0ACDA03EULL, 0xF891F5C49C410175ULL, 0x0DD4A09959792757ULL, 0x01AD75EDB0560433ULL, 
            0x13CF62A9CFB5A135ULL, 0x0BBEC61121E473C1ULL, 0xCE54ADA3533D0CE2ULL, 0xC4DA877E35F28A38ULL, 
            0x958358DE45442D20ULL, 0x9F5FA0FC063EAEDBULL, 0xFFB28C5128219F4AULL, 0x3DE614C1053C439CULL, 
            0xC5AEF48C692D8B8FULL, 0xE09FABA76478E22FULL, 0xB7FE9E17E5DEF77FULL, 0xFFAFE51AFA0E1356ULL
        },
        {
            0x9297872A2CA691C3ULL, 0xD9319F2DC287D479ULL, 0x842F9FAB571C3C2EULL, 0xEA52F161F60786BCULL, 
            0x64537D04F39F675BULL, 0x0C79E5EA5505B850ULL, 0x14994BF3617DDEA4ULL, 0x9504FC87B6D85D02ULL, 
            0x8A65AD80BD8CF724ULL, 0xC0A9062E332932DDULL, 0xE72F8E41D25E940AULL, 0x877947EE1DD59751ULL, 
            0xE4761342FFECEE60ULL, 0x48294F2DEE274265ULL, 0x99E3D79E88BAFF0AULL, 0x08E7619BFCB4019DULL, 
            0x25B4B253C51DC721ULL, 0x602FB22FAD777651ULL, 0x3F5B38C3F3C4B33FULL, 0x1BE48C8FF874921BULL, 
            0x50627C0DFA290CFFULL, 0xAD16EA538652C1E3ULL, 0x5A99A705AEB6A6D8ULL, 0xF3AAC997A6B2DD97ULL, 
            0xEBB93CBF1286DDBDULL, 0x69E7771433134CBBULL, 0x949600C0A6533DF8ULL, 0x8DE10FF68F79A0CCULL, 
            0x87713E5A1F39261AULL, 0xE2DC5B244E0F207AULL, 0x476E73958EB81ADAULL, 0x7864AAAE936889B0ULL
        },
        {
            0xBB759A9C4EC83D2CULL, 0xE4245288A22D99A5ULL, 0x96184104A510E4D7ULL, 0x3FB3F0708015F57BULL, 
            0x533030816064EE70ULL, 0x6574AABDB76E8007ULL, 0x14294018F81AA4C4ULL, 0xF48BF2215B5F86DBULL, 
            0x854ED34EE433DE7DULL, 0x66F3A17993150C94ULL, 0x1C7A314EBFCE164DULL, 0x3E874197BDA2760EULL, 
            0x345A5B66335A6CAFULL, 0x051AB3A2E650D242ULL, 0x6F9F2491E31505F0ULL, 0x2491829451D84EF3ULL, 
            0x12EEA40D330A3E5CULL, 0x77B07D22CFBE4437ULL, 0x459382C8B10CC03AULL, 0xAC4D68BEB5F409E9ULL, 
            0x431F40CAF7AE1BE4ULL, 0x26B4C439C78A8085ULL, 0xD671F77CE0C10E0CULL, 0xF44831CE9D0A78A7ULL, 
            0x4DDCD61C33DC1C34ULL, 0x246692F66662A02FULL, 0x99621EA380EE6298ULL, 0xF546A1621D951AB3ULL, 
            0x3783C5A78ED85EEFULL, 0x0EF2AB9AC998D895ULL, 0x60CAD05676A3941CULL, 0x4076E671010E692AULL
        },
        {
            0x7D87A2D514AB1A5DULL, 0x614C19F33E95D8B5ULL, 0x93F41A4AC71D4412ULL, 0x4A8DB40698FE0040ULL, 
            0x9618A7DD3C31972DULL, 0x4EBDD7CC266301CAULL, 0xEA5076D289BEC114ULL, 0xF13D46B372629F84ULL, 
            0x430278E9B28C2DB4ULL, 0x3829E4B021B7CCECULL, 0x0F3196FA90F29D38ULL, 0x5E1307B170DFD4B6ULL, 
            0xB51B7828BF10A322ULL, 0xC86549AC5E6918CAULL, 0xC908ACB1E8C18D8CULL, 0xFE8196ECD787EA73ULL, 
            0x05479BD68345381AULL, 0x7E036068DBD2AACAULL, 0xBE796B29F158CC2BULL, 0x2C7BE3B02380CB92ULL, 
            0xA392FD453F580CD8ULL, 0x04AF06EE86CC1376ULL, 0xB8C5187E3DB40908ULL, 0x43B0F942721F1799ULL, 
            0x01817E434986D31AULL, 0x1A25D6DEE8EF88E7ULL, 0x23526E24C6DB83BFULL, 0x173AAE27732DE075ULL, 
            0x68859B5A32667E9DULL, 0x0894E1E1D419D455ULL, 0xD305B65C550056CFULL, 0x4D4D3E4AF66902B0ULL
        },
        {
            0x977D09888CA12C12ULL, 0xD08E1A3F3980AD13ULL, 0xC5E877B7819C711EULL, 0xDA6365D04311E8D3ULL, 
            0x1A8B260A6445BB34ULL, 0x6D951726326326E2ULL, 0x15E5812392796B5AULL, 0x6ECB797DF8D29C74ULL, 
            0xD8BD9F7E24ED2225ULL, 0x98A22083983ED288ULL, 0x16450EE0419114DBULL, 0x71148FDF61856214ULL, 
            0xD85A4180491941EBULL, 0xD6AB6CDC1C320414ULL, 0xD067F519D0B56D2FULL, 0xCB67DF1F934AC0A6ULL, 
            0x595B3149512E81B3ULL, 0xB4D2F97131A78F88ULL, 0x3ECB7937CC3FBC93ULL, 0xAA0F0D6FEB1C4328ULL, 
            0x18D39320E4A2C368ULL, 0x1248F39AA57C2C7EULL, 0x57933A1EF5191D11ULL, 0x3732DFC74EF47ED6ULL, 
            0x67443BF10C5AFCA0ULL, 0x6D22AAF3BC48C6C9ULL, 0xF713E5F365064133ULL, 0xA4CC1EC6F614F1BCULL, 
            0xB4C441DDCE16A8EDULL, 0xB15EE44B1B84D4E8ULL, 0xBAFBF2F0FE7580CAULL, 0xFDE5A9F9C4239623ULL
        },
        {
            0x9BA7D12FA35BF0C6ULL, 0x257BC2120F5715AEULL, 0x7E1D21CFF70EC089ULL, 0x046C66C970821BA9ULL, 
            0x2D77DD0516C9C364ULL, 0x61CC12F3F9C2285FULL, 0x1BC56FC922613886ULL, 0x0BFE2D5382412625ULL, 
            0xF6982DC8D4C07849ULL, 0x746E3F52A8614B44ULL, 0x44D23A11D31A2DB3ULL, 0xDE2CAF9762265B28ULL, 
            0xF94DF898EBFA530AULL, 0x1DAB36873B8CF536ULL, 0x058D7E5524C339A9ULL, 0xC96203C1A4691767ULL, 
            0x36FA0F18383A8104ULL, 0x690E5419F3DC5F31ULL, 0x2AC793799B97EB66ULL, 0x7F6936F2B4311862ULL, 
            0xFE17B1F46DEC3CC5ULL, 0xC80654A0FC091FCBULL, 0x481AAE3AA7C09458ULL, 0xA28395C9328420E8ULL, 
            0xE7C0B98247FCF404ULL, 0xE383088BB2B7E2DFULL, 0xA811B05E69E59765ULL, 0x0C8CDFC7E0988DBCULL, 
            0xB55D3B9BCB2F9650ULL, 0xF9AB04B08E94075DULL, 0x57386A776DE3287BULL, 0x35E1B2115C141B8BULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseAConstants = {
    0xA9CEC4CA2A5E4B72ULL,
    0x1B1C3C6DFFAAB73EULL,
    0x02EFB73A927E5C25ULL,
    0xA9CEC4CA2A5E4B72ULL,
    0x1B1C3C6DFFAAB73EULL,
    0x02EFB73A927E5C25ULL,
    0x679251DAC1ADA5C7ULL,
    0x930B33A174157763ULL,
    0x34,
    0x03,
    0xE4,
    0xF3,
    0x24,
    0x57,
    0xCB,
    0x43
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseBSalts = {
    {
        {
            0x74152BBDF9CFE4D5ULL, 0x335ABBEBC56A64FDULL, 0x74EC1F1F67D049B6ULL, 0x624258C43335FF46ULL, 
            0xBBCA4445F38857A6ULL, 0xDCEACB9443730B1EULL, 0xC27AD158BE515CABULL, 0xFA02A82BB6FAD994ULL, 
            0x1F894A8BF95DA3AFULL, 0xBE1ABF11A455A5D1ULL, 0x17319AA9345EB4D0ULL, 0xD33D09570E5A2800ULL, 
            0x8FC7A726ED010E50ULL, 0xB8440EBF028ECCF2ULL, 0xD742641F2F7B835AULL, 0xFD9711961B1F6BA6ULL, 
            0xCB07086768FF3E14ULL, 0x23285751C19E307EULL, 0x2B5140781A6DCCE9ULL, 0xDD83AEB749ACFD46ULL, 
            0xE5261F713DFDD77FULL, 0xFA6604CFDC1B7743ULL, 0x5ED774589C17751AULL, 0x473A85B4B08C20C9ULL, 
            0xFAC60E6F6228FF62ULL, 0x38452148E4EA586EULL, 0x822E8DADA175C1ADULL, 0xC61FBFE3252033E2ULL, 
            0xFF1168F4DC5A4FADULL, 0x673A06C935CA56C7ULL, 0xFCE156CDB8F33F9BULL, 0x8E0530AF37110EDBULL
        },
        {
            0x0FE17897DD60315EULL, 0xB6BC2B010113254CULL, 0x67EDF8E90CF85029ULL, 0x48EF808E7B6B6122ULL, 
            0x85BB6FC33E0321CEULL, 0x2FBEEB4FCC026A3CULL, 0xB4452FB9F54AD93EULL, 0x62757D5C0B6CCDE9ULL, 
            0x93ECB59744676FB1ULL, 0x61368C53195025D6ULL, 0x9AD17F01E3A571D7ULL, 0xCC3214B4AC4A1454ULL, 
            0xB0EBE0B02305D396ULL, 0x7CC5EB2919874C5BULL, 0x8194F931165E9CE8ULL, 0x8A51C674C4167C0CULL, 
            0xEF31B485F76759FCULL, 0xA76F5677C8D8E98DULL, 0x651B1269891F8DCFULL, 0x74CBA3D3B22AF09DULL, 
            0x25F7211A68159346ULL, 0x24BE26D876731E68ULL, 0x695E792B69657D1DULL, 0x6757F943E7A1C9DDULL, 
            0xEE7F7867D671F426ULL, 0xC4B7C87417DEEF53ULL, 0x77B47445A3859FADULL, 0x742BA94BB28D4BDBULL, 
            0x8BC522B9EBBD331FULL, 0x1CE56A0CFAD989C9ULL, 0x40292A346131473BULL, 0x001E5B6700DE308CULL
        },
        {
            0xDEA1AC213D54FA4BULL, 0xC02BB1810ADC0531ULL, 0x776E222E7F874382ULL, 0xD67541A6A547E8B1ULL, 
            0x5131FC911A5FBBD2ULL, 0x2C9BCDCF1FE16D7FULL, 0xD37B105ACED079E0ULL, 0x72B8F858AC2FE14BULL, 
            0x2F0979166866E4C4ULL, 0x5C74E36600B48DC4ULL, 0xD9D8E832674F8F19ULL, 0x73C37C80CE55A656ULL, 
            0x8620BA2432348A80ULL, 0xE3CEE4A6AAD5CEB0ULL, 0x4AB04C645F638907ULL, 0x41CF4090243BF123ULL, 
            0x1204768999E57256ULL, 0xD4A0EADC6C2A4497ULL, 0x6E56A1A992AF64F6ULL, 0xBD4410D15424D155ULL, 
            0x5893453CC61A13F8ULL, 0xEC3D7641D26A01ADULL, 0x8F78FF650645DC12ULL, 0x9E0FB709B9537570ULL, 
            0xE41EE67CC0641ECCULL, 0x01E8371AF1178846ULL, 0xA31F447A26EFD941ULL, 0xC7A91DFB70CCCDC8ULL, 
            0xAA94CAA4ABE40CEAULL, 0x33DAAF9D02B87DF8ULL, 0xA67EC18F6357702CULL, 0xC0D266CD1CDD055DULL
        },
        {
            0xF19C865D2F6D0C2DULL, 0x5318049099FECD57ULL, 0xD3869D3F6A9CFDD3ULL, 0x12A01D3124F95991ULL, 
            0x54F9CB1506BC2CC6ULL, 0xF476F3EC317AF8A1ULL, 0xFC8809C52E401CA4ULL, 0x741CB60AEA91ADFBULL, 
            0x84E436E5DB263036ULL, 0x21677CA316268341ULL, 0xADC0230FCB46F95BULL, 0x548A7EC5AE0CBE45ULL, 
            0xD59B09DFE867CBFEULL, 0x3BB50814A1FD9C07ULL, 0x13367CC3E53AF210ULL, 0x6E92F33E4BC68EE0ULL, 
            0xD13BEE57E5EBFDDCULL, 0x6A08126982BBF3F6ULL, 0x0394ED498B05B47CULL, 0x63B6E28BEB4A6289ULL, 
            0xD0D418E47563A70FULL, 0xF0AAC03054C8D647ULL, 0xBDF27B50454C010CULL, 0x8766344F0E25285FULL, 
            0xBBAD81E7BF46F46BULL, 0x86E9A10511AA1D8CULL, 0xCBC1A6DDF68C040BULL, 0x62637AB94BCC6A30ULL, 
            0x9909955EE6429CF9ULL, 0x752F9C20EC518454ULL, 0xB8C76FAF3C4F5D94ULL, 0xC0E8A61C14332956ULL
        },
        {
            0xCD5C79DA05963884ULL, 0xD83315B1CE49D302ULL, 0xA04AAA6E1885B51DULL, 0x30089C6BD5441101ULL, 
            0xEF1FA2E87BB2E020ULL, 0x7B183025F49A53B8ULL, 0x321BE947F14EBF70ULL, 0xD7D0DE0E975D875EULL, 
            0xCBA0C4B62643B45FULL, 0x71B1CD76ACE568C8ULL, 0x7F4C4A554317C4CEULL, 0xDB2C09D5518BFAC4ULL, 
            0x187B193AC7B49FC6ULL, 0x305FC4CCCEF87AB0ULL, 0x70016C15C9FCAD79ULL, 0x4F95B3BCA2975DAEULL, 
            0x1663BBD1C5FE9506ULL, 0x81143C964F78298DULL, 0x2F7748754C29EF32ULL, 0x851CFA2AA5A22958ULL, 
            0xBCF73B3627D0D26CULL, 0x3271A8E141F85EA8ULL, 0xDE669BCBB4C292EEULL, 0x79A2284455CEF363ULL, 
            0x538CF400D8F64022ULL, 0xE52ADBC7A8C5AF2AULL, 0x4824409D8DC92443ULL, 0x9F936022CA4B1861ULL, 
            0xF2E3266F684AFB6BULL, 0x98C881AC3C88C7FBULL, 0x57FCCC3361B211B1ULL, 0x69C7698973490677ULL
        },
        {
            0xFCD93C6554BB53F3ULL, 0xEAB5227649C0E110ULL, 0x6B74C75BCBFF36AEULL, 0x9BD5FB1AD57813D2ULL, 
            0x6B235E6E2671DC92ULL, 0xCAC603DFD63F181AULL, 0xBBC5EF75C1780DE2ULL, 0x7988794C95219E1DULL, 
            0x0621B66892E0F665ULL, 0x382572CAFAF1E732ULL, 0x706102529C8E2947ULL, 0xEFD6902182C0F0F3ULL, 
            0xDE609D46E8E2C9B5ULL, 0xAA7DC434106FECC1ULL, 0x9A5C9342E559143EULL, 0x872B4743511A39DDULL, 
            0x39B416B4BE8FCD5AULL, 0xACD38001CC819B59ULL, 0xF0FA7FCD50F4A1B3ULL, 0x8BB714956B91BF72ULL, 
            0x85C3952389358A21ULL, 0x576F3C1D42E2B8B0ULL, 0xABD227D953AB2E52ULL, 0x30C6E7A298E7A9E1ULL, 
            0x2D2EA33F6C67F963ULL, 0x8DDA027A1E469E01ULL, 0x510C06FD3FDD10D3ULL, 0x8C19A31631E99041ULL, 
            0xFCA3A60A92EDC7CCULL, 0xE5E26582F6AC9B5DULL, 0x2FD0330A6B52FCDCULL, 0x4434E2A20203F867ULL
        }
    },
    {
        {
            0xF3F46F10401DF8DCULL, 0xC0F2D86583275957ULL, 0x2AA5BC453043A4A0ULL, 0xB9F1E97A76C07C72ULL, 
            0xC4345B09AD367515ULL, 0xFDB1E81B22936773ULL, 0x1FF40A3FA49946AEULL, 0xEE72777E431B0577ULL, 
            0xAA05097DEF96FEB8ULL, 0x39E13956A3B275ECULL, 0xFCED41B2145F6566ULL, 0x79C44AAEFE85357DULL, 
            0x37608B4AB06ED4DCULL, 0x8DA4BE0155CB5F65ULL, 0x252BDDE565586D7DULL, 0xB721AEDE24350FAFULL, 
            0x2A0FD471442D0F2BULL, 0x212DC8C9D54E6805ULL, 0x1E28819333736D90ULL, 0x872B33618155444CULL, 
            0xF0DBA04B4E9C72C2ULL, 0x47536F90836B8DAEULL, 0x085175D06B8706EAULL, 0xC8F0AF6D2D7DC494ULL, 
            0xE2ECD4DEFCC24894ULL, 0x6BB0F534C52492C2ULL, 0x3E89B7EC59ED4599ULL, 0xC832EF102F3586B0ULL, 
            0x41FAF8AFA9552DF6ULL, 0xC21055F75808F136ULL, 0x7160341F729DD80AULL, 0x6663DEF70AB8D76BULL
        },
        {
            0x9FE55B10F1D43FB8ULL, 0x4BC005AE714165ACULL, 0x0C09899157E8B794ULL, 0xC808038937626548ULL, 
            0xACCD5A52A3709C6DULL, 0xB13893FCCEB30D53ULL, 0xDAA67192EA5BC08EULL, 0x4F727B67DB263560ULL, 
            0x150290911B25B88AULL, 0xFE007F2DA148FB1CULL, 0x98F2DC8421CBC9A1ULL, 0x715A6F8F05EEC78BULL, 
            0xAD097517A7DD7C25ULL, 0x6DA86116645D51BAULL, 0xF03DD70735BC78D3ULL, 0x9F1BAAC69537521DULL, 
            0x85DDF0209C983E90ULL, 0x99E0B4988E019786ULL, 0x9796365179E26611ULL, 0x402D6CC0BBE6E2E0ULL, 
            0xF255273737697D4DULL, 0x21A51B623D3B3126ULL, 0x2F7FDA07C90676B6ULL, 0xE8BD9415EFCFD8D6ULL, 
            0xB829121A801CDB98ULL, 0x4922AB87A7068E79ULL, 0x8AFB9763AAE66D3FULL, 0x25C510AC2306C5C7ULL, 
            0x07C74A5756FB68B1ULL, 0x7A99B5907BDEFBD3ULL, 0xF0DD9FC7579B2BB2ULL, 0xE75ED2A41E5DF331ULL
        },
        {
            0x0442419AF9BF0683ULL, 0x40E8D5F34223F3F3ULL, 0x0FE4496FEA4BDD8DULL, 0xE856E9279B883D1BULL, 
            0x01E5F905779E5537ULL, 0x0CF16EEC3E76DD0CULL, 0xC0F83C9A71FAACD2ULL, 0xA266576E47E1BB16ULL, 
            0x18834129934DC0D5ULL, 0x966DE3E4B3333177ULL, 0x80D422471BEFDC98ULL, 0xE65B4FC6DA03DBE7ULL, 
            0xE3FEAD6CB902DCE2ULL, 0x7E971D88678A5F9DULL, 0xB8859FDC95C4B6F6ULL, 0x7C74D711BB0E4F2EULL, 
            0x52401BB02CEF9042ULL, 0x9DB35F915A94DA9DULL, 0x583E04FE5002414BULL, 0x9595C503C9C37714ULL, 
            0xEEBDA7C750F9B3FAULL, 0xE1F858398E1DE810ULL, 0xEEB5D00DC4FCE4BDULL, 0x36CF7790B09AE71EULL, 
            0xC91DEDD8B372BAB6ULL, 0x17522FE8438F6A6DULL, 0x79AE544BAD59F563ULL, 0x9DD8E8BB6FA2AEA5ULL, 
            0x0138A108EAC710E9ULL, 0x6BF9E531CFDB459EULL, 0xF6C7C5B9F4246F75ULL, 0xBF8C7A6776154C65ULL
        },
        {
            0xF89A02A3E30BD4D8ULL, 0x5711F4059A300AD9ULL, 0xF6B883830CC24FDEULL, 0xCE22582A50D243F8ULL, 
            0xB47437B7103E3F58ULL, 0x5CB0605E829F7F30ULL, 0x520E2442DF4F05B3ULL, 0x05C5101FB0A55282ULL, 
            0x8055FA04A1A0B071ULL, 0x3AD994D23360F90EULL, 0x473FD31C834A8A6EULL, 0xD22F44E16A5D10F5ULL, 
            0x238AA81F5E3340E1ULL, 0x6790C6EB46AE0E73ULL, 0xA480B72A065CC6E3ULL, 0x4BD63EB2B70E80E2ULL, 
            0x7825F246DD10AC04ULL, 0xB64CC0BBBBE4C3FDULL, 0x2273F8405C546650ULL, 0x2F84F6A69F85D430ULL, 
            0x716D7B8874D50E78ULL, 0x671D4462EB0C34D7ULL, 0x7648085591410B63ULL, 0xA7FA77F122934A43ULL, 
            0xA786B0FB7CF845B1ULL, 0x3D2E181332AF6B3FULL, 0xABF034F7F0140131ULL, 0xD258297FAF1CFDB9ULL, 
            0x7DB8E18168D3AD93ULL, 0xD458ED310FEF74F7ULL, 0x75C28CBFDE7899A2ULL, 0xA3BCA2811B5F0356ULL
        },
        {
            0x10B95EB4753D9240ULL, 0xEC3206CB823C788DULL, 0xB06D67B944537705ULL, 0xC8B856358AE446EFULL, 
            0xC5958E8EF89A3C60ULL, 0xBF4DFA34365FF179ULL, 0xB9EB775D49B905D7ULL, 0x81B16D5062CF20E8ULL, 
            0x15B9013956A2DB35ULL, 0xBD826A50F6724D56ULL, 0x4BA54E4EEB4C3225ULL, 0xDEAEE4783C4B5583ULL, 
            0x1D9AE57A80E606C3ULL, 0xF81ED3EA21089FF5ULL, 0xD1BFEC8C85D07886ULL, 0xFF8A6B12E7215AD6ULL, 
            0x80AE0D9D07306F10ULL, 0x7C0307A4C927AFA0ULL, 0x8133B622BB2E4792ULL, 0xF20D40C6BD86A8BDULL, 
            0xFB60EC16996097D9ULL, 0xE1253D67EEF90397ULL, 0xAFDEACAC08B98C1DULL, 0xABA7EB00749CE9A6ULL, 
            0xC47180F745F4C90EULL, 0xD99555871245694BULL, 0x14739DBC4AD6EE34ULL, 0xA5E980D486E69C54ULL, 
            0xCEDDCCF4E9767D8DULL, 0xB45193A0EF27E293ULL, 0x2FBB206597BD16F4ULL, 0x07990E0AC84AA8DEULL
        },
        {
            0xF420B02343B1C48FULL, 0x7E5EE84274A43F11ULL, 0x8F1D228E79AAC610ULL, 0x0264FE2C8AD7F8E6ULL, 
            0xC1F18FC2650906CAULL, 0xEFF9308542034AFAULL, 0xE1641916048B6852ULL, 0xE8E93647531BFA77ULL, 
            0x08A6906741F9D54DULL, 0xB9D79E47A0B54C62ULL, 0x4BD82A2AB562BD74ULL, 0xC2165C5259DEFDE6ULL, 
            0x44853BBF01A9C1A0ULL, 0x177287C51426738EULL, 0x061428C4A46A8311ULL, 0xE44A147EEDA70E03ULL, 
            0x509BF2BE401D73A6ULL, 0x1305972981BE1DDCULL, 0x2F1AD157665D30F2ULL, 0x0C7387CF446E3B6BULL, 
            0xD10BAAE7AE272725ULL, 0x27E4FE5220383CD8ULL, 0x6499014D30BB3437ULL, 0xE50767CE2E421451ULL, 
            0xA97A767785042185ULL, 0x52BC63DB5EE2252EULL, 0x705C92729FA90CE7ULL, 0x55EB1BBCA468249EULL, 
            0x46181A458F58962DULL, 0x2680C8207896C7EBULL, 0xF5D56691DE1A7B46ULL, 0x3261E5BCF5E82BDBULL
        }
    },
    {
        {
            0xDEC3279EF2F3531DULL, 0x58E57D4E5E7A50CBULL, 0xAB1E0DA2888FA48DULL, 0x09371B861CC0571FULL, 
            0x554E2CD7E4E70391ULL, 0xD551B16BEC7CFBCBULL, 0x6A73DD738C707445ULL, 0xC3B4F5948FEA0F6FULL, 
            0x97AEEFB238D94077ULL, 0x8B4C7D757E22016BULL, 0x5E7DB3FEC82556F4ULL, 0x5AE11E6B14C5D1DCULL, 
            0xB1C1EABCF4B95F06ULL, 0x4DDFA79027308782ULL, 0xB61E13CFE087CAB6ULL, 0x4EAE65925E72E79AULL, 
            0xC41A32C7FCA19421ULL, 0x1F4B12BCA7ABC37EULL, 0x8C19041AC0F780C3ULL, 0x632DCAE19DEC317BULL, 
            0x02CDE8556F436F27ULL, 0xC60642BE005ECB6FULL, 0xFEC348128EF068CCULL, 0x2234916A5A2F9495ULL, 
            0x9FE56D58F6983E7AULL, 0xF74BD5859FE12C69ULL, 0xF0317D0FAEF39345ULL, 0x7B82CA73CDB2D455ULL, 
            0x9E2F07D01F39058DULL, 0x3E183B83F5DADD00ULL, 0xF45DF21D35C92AD1ULL, 0x740E40A4019A6A6BULL
        },
        {
            0x2E9877C6FFF23F76ULL, 0xB7A2EF25561AE9ACULL, 0xAE46320C06B88CF7ULL, 0x111C1834FCA08578ULL, 
            0xA482307F4BEF94A8ULL, 0x6C3EBC43EF89AE2CULL, 0x772EB63D1CD2CA05ULL, 0x99D199A2575A1011ULL, 
            0x0943718B620732D3ULL, 0x1886B65870E47517ULL, 0x258A18203D5D6D23ULL, 0xC929745D54B0CEF3ULL, 
            0xA634711E98DBECB2ULL, 0x90CD0F30A7A56139ULL, 0xD20070D21A66AF79ULL, 0xAC8567C695E7B60CULL, 
            0xA84B955AA6E2A475ULL, 0x901A798265730B88ULL, 0x9659BF62187E6108ULL, 0x527C313E1BF04DBAULL, 
            0x91206D48B5F27A42ULL, 0x18159A24B2CBA6BEULL, 0xAF77BE8B4C227364ULL, 0x29BDAC67B87ACA1EULL, 
            0x4657E1A9414C5728ULL, 0x8A779E562A02C742ULL, 0x35F2B9148B97FCCBULL, 0x202B172596B78BBBULL, 
            0x70A17E698DB0F588ULL, 0xC631199584F64B0CULL, 0xCA5366C78D8706D7ULL, 0xE5D978495BF8C13DULL
        },
        {
            0xD30D2874C39B4AEBULL, 0x47582259D0496416ULL, 0x8BC6B5A4AA4CEC48ULL, 0x7AC54FAF15B7F976ULL, 
            0x01582DFF8B38FE39ULL, 0x0F78B9304D5C3418ULL, 0xB086C270C038E5A6ULL, 0xF747AB902D389A72ULL, 
            0xB36218CEF45A8521ULL, 0x07584FEF74CC4ED3ULL, 0x6715FD4857F81F5BULL, 0x9BB3DD5D9631E70EULL, 
            0x0FC1B2B724964EA2ULL, 0xC76E0075F6BF4F84ULL, 0x13FF3D2561A4FBB9ULL, 0x80F7A57E3F3C4861ULL, 
            0xB11F87A499844412ULL, 0x36C87235922B73D2ULL, 0x2ECF08896BB541F4ULL, 0x47F02BA9137B74E7ULL, 
            0xD26DC74FC479DF1BULL, 0x0D3D06C4BF87230CULL, 0x5DE5C4D4A40AA3CCULL, 0xE6F141A3E955B776ULL, 
            0xBD7AF9B5FEBE9CE0ULL, 0x7D6E04944F3D1B94ULL, 0x34E53211D62C0C0BULL, 0x8D6EDD8DC5E38862ULL, 
            0x5FB5846E6D4B0B23ULL, 0xE0DD6C4143793A7FULL, 0x5FD17C13F76A4C08ULL, 0xFDD01C4612EBFBA8ULL
        },
        {
            0x5FA592B553D69FDFULL, 0xDB637EA4E3F1F9EFULL, 0xF8C451245F4025D1ULL, 0x97FDE4F0B911D1B0ULL, 
            0x065E23F3EF780064ULL, 0xADB7823F882CE1D6ULL, 0x8435E9587A32D26CULL, 0x8B75E7532E98F844ULL, 
            0xEB0165D9D38212DEULL, 0xDC4A6B5EC750A5FCULL, 0x235F98F1923D9123ULL, 0xFE9209ADBBCB6C8DULL, 
            0x8DBC8059632DEEC8ULL, 0xB30236A450272607ULL, 0xDC2BD302CECC3222ULL, 0xD0469B81162CEF03ULL, 
            0xFC07ACDBF4ECDCE2ULL, 0xA1CC7C93DFE50C8AULL, 0xA815C8338E5D756FULL, 0xE8D4CA8AB86BDCC1ULL, 
            0x215C94B353B5CFD2ULL, 0xD2016AF05C1E2359ULL, 0x6A8D68BBF17F71FAULL, 0x677F96BADA0ECBB2ULL, 
            0x900AF09FE2CE6830ULL, 0x7152738CC1D0A6D8ULL, 0x9E9FC2C76045B206ULL, 0x2D141E3540DA8BD1ULL, 
            0x0D438FC833C6BFFEULL, 0x50CEC1F2CB6A5186ULL, 0x7B600DAFB6692DC8ULL, 0x37C13D6548A281B8ULL
        },
        {
            0x13A28FC9623D945BULL, 0x5AED631A04B850D7ULL, 0xE2D90F1B52544B57ULL, 0x1AE71ED42F7B9C19ULL, 
            0xD5686CA89898A827ULL, 0x677A89D04B0DBCEDULL, 0xA849C0C9D07F6E4DULL, 0x90E1FD97C8858677ULL, 
            0x66933DFBF6303923ULL, 0x32ECFF0DD82975E9ULL, 0x4F4BF1833EE08F80ULL, 0x7738418DA53FB125ULL, 
            0x8A7033E35C66E86EULL, 0x6D1232BBE0F7A7A7ULL, 0x7BFEB5E6762FE000ULL, 0x8E7F3431B141BE56ULL, 
            0x423EA52B706EAAD9ULL, 0xA98EBF3DA5D5280FULL, 0x22F2AF6605227628ULL, 0x6BE38D3D6F6222A7ULL, 
            0x322D4E1CA4B923F9ULL, 0x50B23112EA405372ULL, 0x0CEAF30E574D87A5ULL, 0x94AB77FFE593ED2AULL, 
            0x0B13F77A4C9EA3DDULL, 0x00024E0FB293C7BFULL, 0x06555E5D68CC1811ULL, 0x5720EF4FCB78AFC1ULL, 
            0x2EACA2BA4FF4E627ULL, 0x3C655E786DD9EBC0ULL, 0x7E29DC5270390117ULL, 0x74CE6632053157FDULL
        },
        {
            0xD6D96C9089C4D2F4ULL, 0x8BFDD72D8CC7C24EULL, 0x646C789AE6DA9DA4ULL, 0xB0E02EAFCC9E4381ULL, 
            0xAD8D473544223828ULL, 0x19044B91A34C9094ULL, 0x6BE418CF1BAEB4E2ULL, 0x66A5243E6F469B2CULL, 
            0x53D44A8AD2FD9AC0ULL, 0x01CA7021FE8C16C5ULL, 0xDE20FD0CB6C5F2EEULL, 0x95D0F572B41F2775ULL, 
            0xB405228A59774FB8ULL, 0x4EFD2AD793842604ULL, 0xE4B3C97EEBB69C08ULL, 0x6586172C22D20528ULL, 
            0x11916CEF82302769ULL, 0x576914758C6D0F70ULL, 0x199122FD99916487ULL, 0x7E22DFA6FC62D577ULL, 
            0xA8825E2C66CBD0A6ULL, 0x9E55F821C6D5605CULL, 0x6DE20022E27A1157ULL, 0x1BCC55B5748878FAULL, 
            0xAE3E8B2769C6C194ULL, 0xE1570671D2C688DEULL, 0xA686015A628BC202ULL, 0x05F82D16793BAB59ULL, 
            0x7B68868CB1D78999ULL, 0xFD9D54B091F42D5FULL, 0x04FF00D7432A9BCEULL, 0x6DE4CE70C11EC342ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseBConstants = {
    0xCAE2A5811EE61923ULL,
    0xC257CCD10925C938ULL,
    0xD83D7A6ADDC34209ULL,
    0xCAE2A5811EE61923ULL,
    0xC257CCD10925C938ULL,
    0xD83D7A6ADDC34209ULL,
    0xA7D191C35BDD97C3ULL,
    0x7F5DF0535BEB10E4ULL,
    0x79,
    0x30,
    0x6D,
    0x8B,
    0x55,
    0x48,
    0x14,
    0x56
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseCSalts = {
    {
        {
            0xDC3BDC2C2283A892ULL, 0xFDC5342BDBDA4651ULL, 0xD96C02CEB66D8460ULL, 0x579F6C9A5393FAA9ULL, 
            0x48985C6918004A2CULL, 0x8ECC2C30DBBD0EEAULL, 0x53BB05CAD9625E7FULL, 0x338D2DC6222801B5ULL, 
            0xC2B3CE294262CEEEULL, 0xF27DE0BA618BC9CFULL, 0x38016F856EF7F36AULL, 0xBA2848D46657F321ULL, 
            0xA7E07FED50AB6736ULL, 0xF680872B0A33F142ULL, 0x1BBFD9528312F6CDULL, 0xD7AD8B8922AF4319ULL, 
            0x5D851286C0D36DA5ULL, 0xBFE2488DAB72FE06ULL, 0xAD68CEE64B594E95ULL, 0xDD295F94C33341A0ULL, 
            0x499F6E274131D376ULL, 0x21F3FD8CDF042209ULL, 0x792F768D1A75FCA1ULL, 0xB9F4A0FE2E56CE84ULL, 
            0x6E1393064DC52324ULL, 0x83EE2194CCC465B9ULL, 0xE338BE5BFD2B79E4ULL, 0x59EBFD599BA120D6ULL, 
            0x946CB684CF0AF1EAULL, 0xB8BF27513DF28C92ULL, 0x5BF363A44F130F12ULL, 0x0EECF715672D32C2ULL
        },
        {
            0xDD3C3DB2B75C2EA7ULL, 0x739CA3DC707723F1ULL, 0x25421871EA619E19ULL, 0x4A8EFAE0D3C12285ULL, 
            0xC1DF5993303393A8ULL, 0x45CF629ABBF879D4ULL, 0xD7369145E2859129ULL, 0xF49AA2D7A9E38CECULL, 
            0xF865D85548C59735ULL, 0x32D8BCA2F0D2BC66ULL, 0x1CAEB727490F2224ULL, 0xEF600C3709EC3340ULL, 
            0x7D625FFB8B34BF3CULL, 0x3BBD423A7153BE93ULL, 0x9B04A36E9C21C4C4ULL, 0x79FFFEBB7D0BDBC7ULL, 
            0x6492F309EF562B4EULL, 0x15A3B3E215B2FEFDULL, 0xEA6102FA41E0E418ULL, 0xFEFF3F93208A7E37ULL, 
            0x86502DCBB0B1A9E8ULL, 0x527DAA3C5BA955D8ULL, 0x3303573310B80DD4ULL, 0x62D674622000D1A0ULL, 
            0xF3E8E53A262E5875ULL, 0x860FBB56ED7545C8ULL, 0xC0A7F21B3E9353DDULL, 0x4D549AA193A02FE5ULL, 
            0x41D863F1BB8DAFEDULL, 0xC102EB8B9E06BC83ULL, 0x23D4A0D74E1AC9FBULL, 0x57F2C32C1397BAB9ULL
        },
        {
            0xA0EB1CA7D9EE4622ULL, 0x0E6416F548D60948ULL, 0x0D6C40D6494B673FULL, 0x3BC4CECF33B056CEULL, 
            0xF908030C8149172EULL, 0xDA3F49C874018661ULL, 0x0A7288F04A14E697ULL, 0xA1FB94DAE906B9BCULL, 
            0x62A8ABBD72C620A0ULL, 0x1A8B0CFED83B6AC8ULL, 0xFBD7E59159101C24ULL, 0x028BF586F1C07E45ULL, 
            0xD54AD4893B4215CBULL, 0xD394FB351DC0B9B1ULL, 0xB036843A50AE3094ULL, 0xEF87CD5DAF710BA1ULL, 
            0xB5A804164A02AF8DULL, 0xAA53DBF9BA2FD395ULL, 0x76AA775825F19CE8ULL, 0x424530E71FA2EBE9ULL, 
            0xCD26A7FA0A347E26ULL, 0xFB76DC599D2A7D09ULL, 0x39CCA7365D300CBBULL, 0xBD217F1F88D862A9ULL, 
            0x8DD0B94E558BDFDAULL, 0x0BB31D3437418382ULL, 0x6D58E9C52983183EULL, 0xC8FC4BEDCE865093ULL, 
            0x890EB0AD3C1EB49DULL, 0x965115557AD47386ULL, 0xF926C7827A0FC8FDULL, 0x1118203C81BC0DB7ULL
        },
        {
            0x6375E6E5EF0894A8ULL, 0x6E3EA9B7AA3C88E9ULL, 0x0F570BE70AA38736ULL, 0x9121FAC171EBB1C2ULL, 
            0xF356B69529C4043CULL, 0x7AD9973C64E6FA74ULL, 0x7EB564A784F495C9ULL, 0x4D5B603374DAC976ULL, 
            0x77155EEE50E0900DULL, 0x4D9C6260EC0A894EULL, 0xC866E4076A6C2206ULL, 0x20B7CB9D067CA0D4ULL, 
            0xE3C8FA4A5562EE2BULL, 0x1F6039ED07C2FFDDULL, 0xC11983DC7CC356ABULL, 0x132489EAB6B4BA8FULL, 
            0xC0BCFE409C39AF99ULL, 0xA02D1A8EC0B38B19ULL, 0x8549EAD226D1FF31ULL, 0x511E06C8DA74673FULL, 
            0x1488C328C687DDC6ULL, 0xE4C64BA05B6D73F0ULL, 0x0B3C59FEBB2B74B1ULL, 0x86876BD09C7E5541ULL, 
            0x3413920C81A9EAA7ULL, 0x2605FE4699118850ULL, 0x87AD9F9F7D6150DFULL, 0x834D3864F020D43CULL, 
            0xBD26B7A1CBC74375ULL, 0xE0E9F36C58D1BDD9ULL, 0xD9F38C48DBF2C5E4ULL, 0x4002C6D0D7DABE4CULL
        },
        {
            0xC498A5FB5EBC5B7BULL, 0xDD47260F3933AAE3ULL, 0xF3546400BCED939BULL, 0x061337058A6BE505ULL, 
            0x58BA5E3CB6EA2EB8ULL, 0x01F0A5E795A3B8F3ULL, 0x39EAFC1BAFF892E8ULL, 0xA5BD306DEEB4FCB5ULL, 
            0x9DE0BE5C23CE273CULL, 0x22B760C8FFA1C367ULL, 0xFDCA15C83C30B4B1ULL, 0xC37F403ED4B96AB5ULL, 
            0x580B3351AA259F47ULL, 0x806FEB76B978DA1FULL, 0x8231823AFA29F4B8ULL, 0x5C1EF2AB9F6C440EULL, 
            0x5ED4881076E81C00ULL, 0x6A2F69600F41CDCDULL, 0x1F7BE5131518E8C5ULL, 0x30C7B470630D9865ULL, 
            0x9C4AA619AB384928ULL, 0xE5C404143AD1180FULL, 0x2E7DA4DC5AE1F101ULL, 0xD70CD71E1C51E1D6ULL, 
            0x27E8BA5119A834F4ULL, 0x049CFBE2F0EB3750ULL, 0xBAB603B20447A986ULL, 0x6A8530F9697B4739ULL, 
            0xFDCFBF10FFF7D1B2ULL, 0xC2A0A9CCD0A5B469ULL, 0x23BDDDC841EF79BDULL, 0x15069EA01FA568A3ULL
        },
        {
            0xFA2A0797DA3703B5ULL, 0x09AE24E556994295ULL, 0x5BDA79F9B8B8E17CULL, 0x49EB9869C2D57999ULL, 
            0x652585863A282E67ULL, 0xC261171CCB21356AULL, 0x0FF63B294DCEB8C8ULL, 0x7CA95D578754C8E3ULL, 
            0x7569CFBA80871873ULL, 0xBB3DEA7CA0917C31ULL, 0xFA0D186804CB8196ULL, 0x8819417F9FCB7047ULL, 
            0x46ACE034DE69F098ULL, 0x23817A8AC259AABCULL, 0xCE8178148BD61002ULL, 0xFCAC7166A0B4A102ULL, 
            0x7056DD8AB0265AC2ULL, 0xB3F865948885DD2AULL, 0x817772D1891C44ABULL, 0x668938ECB26221A4ULL, 
            0x66B71AB615FB1EB1ULL, 0x20C1BD9FED5E7F10ULL, 0x924D1219467D0847ULL, 0xD15808DE8ED57382ULL, 
            0xF28C1206A4782AE7ULL, 0xE17BAC2FF70EC3E8ULL, 0x2BD63879AFC929C4ULL, 0xC91013A603DA4C72ULL, 
            0xF1065DFDE02F9270ULL, 0xAAF251D3E2811D04ULL, 0xBCB8E50D394A672BULL, 0x25793AB114A4CEE9ULL
        }
    },
    {
        {
            0x2607A25CE76FC843ULL, 0xB2F3D5D181C45166ULL, 0x6CDCF74BA74B7FC5ULL, 0x0010918956300BEEULL, 
            0xEB0209AAD6960929ULL, 0x9781F27CB47EBE9AULL, 0x2186A1E6D0DA4695ULL, 0x325A056EBE98F4C0ULL, 
            0x53320FAC38D76568ULL, 0x3C90995E4A6BF86BULL, 0xF1C0066D974027D1ULL, 0x05DDE57EA97B88D4ULL, 
            0x17334C1F0C0B64E7ULL, 0xE0271D92A44FC2A5ULL, 0x2B69C00CACB02164ULL, 0x1F2454122342F6FFULL, 
            0x76F0AB785598834FULL, 0x4936CCABD62D4199ULL, 0xC36419C30622B3EDULL, 0x01824D7A70495837ULL, 
            0x07EA655C1652CFD2ULL, 0xF9675593172302ACULL, 0x9BE628BCCB42DE15ULL, 0x128ACDD64A6781CDULL, 
            0xBC7FFAEB9F66C35EULL, 0x9593EFC5BD9F66A2ULL, 0xD67679BE7FB7CC39ULL, 0x8B56BCDEBC4D7128ULL, 
            0xA134FC8E1C9464B7ULL, 0xAE33A3C5B178DA9FULL, 0xA1D12C80541AB6E4ULL, 0x1A007ADE61E8A425ULL
        },
        {
            0x8212B1080F0BF4A2ULL, 0xC440CE51545D20D1ULL, 0x3CF5CCDAD0CD1FFAULL, 0xEB77BC90993747D4ULL, 
            0x30DEC04DD344EFA5ULL, 0x9B0BC3674219AC26ULL, 0x3F744D3CC9FAF01FULL, 0xF4DC67FDDD360944ULL, 
            0xFEACB843D13365BFULL, 0x7F9094CCAAB1A6ECULL, 0x2A79DAB8F081D359ULL, 0x680E4B4D4D19527AULL, 
            0x1E7B03BA094E92CCULL, 0xEB5FF8E35F133FCEULL, 0x1B2C46B36EE26FE6ULL, 0x941CBF7BF39A44A1ULL, 
            0x14692CE760073394ULL, 0x609987F3F15AD878ULL, 0x92B184EE2799BEE1ULL, 0xBEB0EB304F856AB2ULL, 
            0x6C9DE809A7BC7D64ULL, 0x82E90F822DD7561DULL, 0xE5809679106E90C5ULL, 0xEF90D1A5CCBF8501ULL, 
            0x7CE7641D4B5D8885ULL, 0x1C158E376D7CD4EAULL, 0x0CFEDD83E39B29CFULL, 0x2B858533EB6466CCULL, 
            0x83329D26B5D0E201ULL, 0xC865050EDE171F4CULL, 0x4DC97DC496E4DAF3ULL, 0x5F9BF47B7FC44778ULL
        },
        {
            0xBBC99A346E516311ULL, 0xDA52B775B7EA3E72ULL, 0xF8DAB949F894C44CULL, 0xBB7EA8F3BDD3E0B1ULL, 
            0xB7FA0C1EA7772179ULL, 0x2F3D9DD2B8A0B9D7ULL, 0xC08A59A843F60A91ULL, 0xE4AE752951D92CD9ULL, 
            0x7673211176F94AFFULL, 0x994810985255B825ULL, 0xD58DE0D86D99E263ULL, 0xE977A882A8132C65ULL, 
            0x62DB51B1651998E7ULL, 0x8537C7EFC23A18F8ULL, 0x693D668E63A697AFULL, 0x0D37643A26E9A72FULL, 
            0x619E56476CC12DEEULL, 0xD1CA734AE591FDC7ULL, 0x050C4456F4D49DB7ULL, 0xBE534E8DB1801CB6ULL, 
            0x694774A09D38295AULL, 0x95B7E3CD633E34D2ULL, 0x7BB70CA71E3C5F18ULL, 0xBE23216ABB722BD3ULL, 
            0x4D2FFB1CD79021E1ULL, 0x056E31C6A8D4B832ULL, 0x57BF32038DFA1D83ULL, 0xC73FCA267AC89AC3ULL, 
            0x07FA7F2C08D5FA56ULL, 0x063B01FB176D1234ULL, 0x429BB90FA587ACACULL, 0x1EC668A5727FCA9FULL
        },
        {
            0x210DBF6F72122507ULL, 0xC5F0E363F3A465E5ULL, 0xC3E2E5C38D526D19ULL, 0xD1729070DA4A4409ULL, 
            0xA18698F7C458D096ULL, 0x161CF17AB535D2CFULL, 0x8D9E5F69E8B7CBFDULL, 0x37D24D807ACA8208ULL, 
            0xED00C25C5D7E9E05ULL, 0xB47CE6AE730C446EULL, 0x4AEAB56E072A1E2CULL, 0x4282762704C265FEULL, 
            0x2CE0B0CDF87369C3ULL, 0x2387431D7025ED93ULL, 0x5382F6614ADC2539ULL, 0xC9B39427694F2BFFULL, 
            0x35675212DC255832ULL, 0xEE62E503935D4090ULL, 0xCF41EA2F141BF04AULL, 0x53F2BC812C4EDCD4ULL, 
            0xC1B8277A00DE9E76ULL, 0x69EB00DB1AEBBE56ULL, 0x6488C9C9249E9308ULL, 0xD061CD851E81ACBAULL, 
            0xD764B9453D3ACDCDULL, 0x7D108AE789476E5AULL, 0x92D52704F5D83462ULL, 0x1D2BD782999C0646ULL, 
            0x0A68BCC3C6B62803ULL, 0x6D28D3C0A81F8244ULL, 0xA2505733C922E4CCULL, 0xC8ABBC19ECC069BFULL
        },
        {
            0x7395130A959B5709ULL, 0xE86A1A75AD30DFD5ULL, 0x90A360E6CE8F5181ULL, 0x2456E0D37F5A3394ULL, 
            0x0F626E8C7F6ADE33ULL, 0x8122F45F74485A9AULL, 0x1681FEF82AECC5BEULL, 0x49064214423946AEULL, 
            0xE3176C11EB671054ULL, 0xB540B8ADD6DCF512ULL, 0x2D214667F8267850ULL, 0x63EF0830348943EEULL, 
            0xF78FF835F9DC17FEULL, 0xCD58E88C3FEDAE2BULL, 0x166D79D244A172AFULL, 0xDCE46E68C1B52A62ULL, 
            0x8AF88445E4C9D85EULL, 0x6C4413D59B3221ECULL, 0x6CAA0AB0F10461EEULL, 0x5326D64232400E19ULL, 
            0x858E7D33337241B0ULL, 0x047D2600665F1952ULL, 0x6B0DFACC616EC335ULL, 0xC28B1B583E286B3CULL, 
            0x6B060F56CEA69667ULL, 0x58D2A72EC35E19C9ULL, 0x119DCD77BE249914ULL, 0xFD9CE8FFF1427E43ULL, 
            0x6F374449111CEC6AULL, 0xA97415792A219FCFULL, 0xD2CC982791AE4988ULL, 0xC4DA59B78C352CADULL
        },
        {
            0xED73287EDCA1A1E4ULL, 0x32CFCC30A70A2C84ULL, 0x7E4784202668E287ULL, 0x0F23B5D6483EA5F8ULL, 
            0xE6F18AB992CEEF53ULL, 0x24AD7B5692AF53B8ULL, 0x3C48740CA478D2A1ULL, 0xED681D1992DDB716ULL, 
            0x81DF2B6E6D704672ULL, 0xE530BDF694602BA6ULL, 0x6EA54FDD0E01F3E9ULL, 0x9B0B78250A560F19ULL, 
            0xC7368192146E59CCULL, 0x70B6DB6C790C7D05ULL, 0x4E1B7C666E07A142ULL, 0x6AD6F568EE315BF7ULL, 
            0x509A9A6D6C4A68B6ULL, 0xB7F8A57A36264755ULL, 0xABE662A15E2FF97BULL, 0x619EB7CDF16D7A98ULL, 
            0x56401D19E73853FAULL, 0xD0E2ED42AE9DE663ULL, 0xBB8D0BC1CEFC7D4CULL, 0x06338B9050E1B2B9ULL, 
            0xC1D07E7EAAA8D134ULL, 0x7B9BF4447DE79BB1ULL, 0x3536028996714AE1ULL, 0x4DF142A6FDBFB2D0ULL, 
            0x0D13EE20691DD1F0ULL, 0x7C4848F99EE3F520ULL, 0x26A1CDF605A3B844ULL, 0x65E3FBEC6A706F90ULL
        }
    },
    {
        {
            0xBF4478618C6EF04BULL, 0x252E3A2B60F39054ULL, 0x319B34A0F8C504D3ULL, 0x3A6FE5751139EF4DULL, 
            0x55E41420A8873B0DULL, 0xE334C335C319815CULL, 0xB020DFEBC37ACA34ULL, 0x03BBCD1572D5C157ULL, 
            0x28B6964C29D5091AULL, 0xEA6AAF8DFF711B0DULL, 0xFF0CD9D449579AA1ULL, 0x0D68E30B72237148ULL, 
            0x88B3BF536C651CD9ULL, 0xD60715170F6AAABEULL, 0x000D8E8BE818AA3BULL, 0x6430E759F062AF6DULL, 
            0x5FE526C676C604ADULL, 0x63E8053CF1E0FDB8ULL, 0x33F8960D518C84C6ULL, 0x60168207BE80BDE6ULL, 
            0x383A4549E8B502F2ULL, 0xC3F2E14517853E3EULL, 0xA006076D8C781AF0ULL, 0x045B76906947219CULL, 
            0xC130605A8D4F431CULL, 0x0D324F8A1DCF1057ULL, 0x366DD574EB36A3C3ULL, 0xC76B9D26FF1C2C5AULL, 
            0x635725852CE9A17AULL, 0x507F95785F167EA1ULL, 0x1A8E06227D8D65F5ULL, 0x112F7EEF8E1FB615ULL
        },
        {
            0xD2D8B4AFCB930B5FULL, 0x192819FF121D8A31ULL, 0x1EA601A08521D5F5ULL, 0xDCD199A7D5B7A278ULL, 
            0xC23101499FE57955ULL, 0x41F32B187E051DE1ULL, 0x384A5E4C00F9BD8EULL, 0x95D614C1EFBECA84ULL, 
            0x0430918B38A621BFULL, 0xD99786397F0BC2D5ULL, 0x2D01673C50B90004ULL, 0xE3FFC59C7F38BE33ULL, 
            0xDD74DE67EFA34AD3ULL, 0x74854ADC4F879AE2ULL, 0xFF91FC12BB06849DULL, 0x53254E9DC6D16776ULL, 
            0xFCA82A3467DB64FDULL, 0xBEBBE469C43FC050ULL, 0xCA7C7A73C01761EFULL, 0x58B3901FC820C3E0ULL, 
            0x6E510BB2F78DEEF3ULL, 0x2957D53E200A3DFEULL, 0xD89CDED865AE15C0ULL, 0xBE1D33691F9C798FULL, 
            0xD72248BC555FE330ULL, 0x0B370B4054982704ULL, 0xFFA568D7C169924AULL, 0x1E8EB98CE17CF866ULL, 
            0xCA22536579080E19ULL, 0x1C9776C1E1F1E481ULL, 0x5B838C69813486D7ULL, 0x048B9FD93DA45DAFULL
        },
        {
            0xB997D3EFDFF1C332ULL, 0x8310380E303CDBA5ULL, 0x8973E062684135A0ULL, 0x245D2DDC5F2D67A6ULL, 
            0xCA334FF51D387702ULL, 0x9D5B1FC08EABFDB4ULL, 0xC55063FCA4ABFF9CULL, 0x61EC1E2CB2E0330FULL, 
            0x47B2999609DC0F25ULL, 0x10E1FBD10BE095E6ULL, 0xD15879EE0AE59962ULL, 0xC46C8D786D9663F8ULL, 
            0x6DD3AFE80C76242EULL, 0xC848F615327BA89FULL, 0x39CEAEB8099FF72DULL, 0x6C81FBC5A4A1DCB9ULL, 
            0xD9815E6A2DAD1FFAULL, 0x94994861A7397714ULL, 0xD5B268CB0DDF25B1ULL, 0xF5B5465CA46AB54AULL, 
            0xA4084B3ADBEC8A97ULL, 0x48944537835D59E0ULL, 0xA8357E5FEDD89E0DULL, 0xAFEFDE97AEA1B482ULL, 
            0xF52652CD988BE7D2ULL, 0x7E7FBD061352AD73ULL, 0x8BAF5145BFB13C7FULL, 0x372A6D720FABC0E5ULL, 
            0x00C13680A421C0FBULL, 0x774E3FD32D99FE20ULL, 0xECA867946CA72610ULL, 0x40776BD6BF8356A0ULL
        },
        {
            0x103D5D636D1F5E6DULL, 0xFB36266E1BA575A0ULL, 0xCCC1B562E45DDAF7ULL, 0xB3C716F421C828B5ULL, 
            0x15EB67623C24116DULL, 0x850F921E589D8972ULL, 0xE90F725108A52A15ULL, 0x978EEAF506A2E0F2ULL, 
            0x85FB92D371943443ULL, 0x9D9682CA4180285DULL, 0x300AE34CD6973D91ULL, 0x781A0F765DF022CFULL, 
            0x506DF3004693BF59ULL, 0x535F4FEE05CFE50DULL, 0x482D689429F7CD96ULL, 0xB8E0755882012BF4ULL, 
            0x17EEAC416844A1ADULL, 0xCDD5CD4C659C0280ULL, 0x886C6B388F216AAFULL, 0xA72ED7905909A963ULL, 
            0x03DB9AF37E489169ULL, 0x1513FDA29446C8C0ULL, 0xC7032E67C0CDA474ULL, 0xAC4CB60F71FC55D4ULL, 
            0x14FF3F8D98A67DF1ULL, 0xA04D9ECF1DF6D5EDULL, 0xC68349E9B6329763ULL, 0x4385265F1CAA49A1ULL, 
            0xEDF1D75C9B52D965ULL, 0x9683EEC4EABF76FAULL, 0x1F8633CBB85EB9B7ULL, 0xB27FB582357CE892ULL
        },
        {
            0xE7785A805B08C69DULL, 0xEF8C51960B7AA322ULL, 0x2885574751B858D8ULL, 0x64BA0FDDD001F55BULL, 
            0x0A34CE1F1A09EF59ULL, 0xE1B6633439BDF8C4ULL, 0x58A0A17D56C807A5ULL, 0x849F3E89E0F80B19ULL, 
            0xC975561C2917F58CULL, 0x8EA7BE8D5DB79A47ULL, 0x19E1CCC1037649FBULL, 0xF87A70673679B6CEULL, 
            0xFF76AEED7CBDFE14ULL, 0x795D8D3D27CADB49ULL, 0xC743938B17862A8CULL, 0xC2D9C0ADEC85B8E8ULL, 
            0xB05403ACEB2C7269ULL, 0xEFBCA31466268E9CULL, 0x06E8E2E102EA0377ULL, 0xDA448FE5E727FA22ULL, 
            0x64E7474FD711F35FULL, 0x13E8556DBC2568DAULL, 0x5EE4FE3EC126CBAAULL, 0xB63CE55B675D2B64ULL, 
            0x88B939E9ACB4D477ULL, 0x07E28AE8B794E683ULL, 0x1241D238D1DEEFAFULL, 0x3996A90BF1D854D9ULL, 
            0x9FFE4381A879EAF6ULL, 0x39098C26B8EA12C7ULL, 0x1A25AE6A74A757D7ULL, 0x446C842549D8165FULL
        },
        {
            0x48B7A570324C21A9ULL, 0x840396556F0EAC6DULL, 0xCCF18733A4EB7863ULL, 0x0531A46153535802ULL, 
            0xBF1D95FF2786961FULL, 0xA3BD0E6E6FEE4F41ULL, 0xB50FCABD73A5793BULL, 0x2CE34087A3E8A238ULL, 
            0xA27633EFF5DF9305ULL, 0xAF07DCB072003E8EULL, 0xC4699B2E812D6D39ULL, 0xF0D16167F5AB4738ULL, 
            0xDFB1BF36DB143548ULL, 0x3D15355547783545ULL, 0xD448963170606EC6ULL, 0x639F78476C8BEBAEULL, 
            0x792475387C7A19FBULL, 0xCD858C62C1AFE089ULL, 0x25AB082891772364ULL, 0x13D5B383677E6B7CULL, 
            0x854E60A72D05857CULL, 0xF3F1ECCC844A3ACDULL, 0xBEC2F8C7FF58E4AAULL, 0x2EB368B665FCB7A9ULL, 
            0x553C98077650AE83ULL, 0x66F7DBFBC662B7D6ULL, 0x7752244708462AE9ULL, 0x6E0F0D44B99A525CULL, 
            0x981E0C24B9706D87ULL, 0x3F52CA0AFA6A8164ULL, 0xEA92475DA75A28BBULL, 0x1067D9A6A6A0908BULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseCConstants = {
    0x9CC8379042BFF705ULL,
    0x78255AF9CD9E3DCDULL,
    0xDCC0F3EF2F155A58ULL,
    0x9CC8379042BFF705ULL,
    0x78255AF9CD9E3DCDULL,
    0xDCC0F3EF2F155A58ULL,
    0x4B8CA650F0567C7DULL,
    0xF3F6F4D0C6ED63E0ULL,
    0xF3,
    0x1A,
    0x32,
    0x52,
    0xD8,
    0x5D,
    0xB0,
    0xF1
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseDSalts = {
    {
        {
            0xBB95FA932DBBE923ULL, 0xBA3694D03657A5DDULL, 0xCF6B829D0A9D9454ULL, 0x964B3A68F8F19FE6ULL, 
            0xE8EED95223141F00ULL, 0xB6B9C548BB2DA17FULL, 0x8375629134C44166ULL, 0x848FBA08A111DBFFULL, 
            0xEEF9C19D2E607409ULL, 0x63B9CEDC43ADF3D5ULL, 0xFD2D3B2E76904AF9ULL, 0xF726B4F5F95C87BCULL, 
            0x6569AA5AB99FB397ULL, 0x218DCE3A74F038C1ULL, 0x2C7E9BD764FE9E1BULL, 0xB97B9F221AF0631BULL, 
            0x29381C4D1489CE18ULL, 0xD28D166276BCE047ULL, 0xDC1BBA6CD32361AFULL, 0xBBD238BC9ECC643AULL, 
            0x1891420EF88B195EULL, 0x3D84F5CDE0CD2BCFULL, 0xC78F6F107EDCE86DULL, 0x60B6E0715A306CCFULL, 
            0xD1998DC74EEE5B18ULL, 0xD2B665A897B679FEULL, 0x0FF3BEBB41061364ULL, 0xAC165F02763B12F5ULL, 
            0x22061DB2BBD57D29ULL, 0x802A8FB0D72D9B23ULL, 0x2A058E0D3303B840ULL, 0x390D493BD10EBEC1ULL
        },
        {
            0xAB1AF85AD70C12BDULL, 0xE6C6B8E7CBC7E9DCULL, 0x4AC8167ADF496A68ULL, 0x9427A43450346D02ULL, 
            0x3E1C4E1113D82B6CULL, 0x8A7176E94361F46AULL, 0xEA770C0870F30CC4ULL, 0xDBB8FC5AF0945B26ULL, 
            0x0CA4E83F82258551ULL, 0x91F50F6EAB095287ULL, 0x83098D785135876BULL, 0x97C42C31A6BDBD8CULL, 
            0x142757F0DE73B48EULL, 0xE4EDA0165BB334F7ULL, 0x9B347E90F779667BULL, 0x129B0A8A7A8EE3CFULL, 
            0x1AF7AA4FE18B02B6ULL, 0x957AE4D2D94B42D7ULL, 0x2B9DD0104400E8F1ULL, 0xD9A13CF0F335B63AULL, 
            0x654C1FA322487ACFULL, 0xD233FE0DD04D0DA5ULL, 0xF1B4DE3D80666599ULL, 0x152AADF91508CB9BULL, 
            0xC08D2D1458963A9EULL, 0x093F9E28D0FD1B18ULL, 0xCCB470BCE2EA15E0ULL, 0x382E474A16BC23D7ULL, 
            0xF7A1C305DA0532A4ULL, 0xA7E3A6CF6C25C89FULL, 0x4469A0ED14EF11C7ULL, 0xBFDB4C8B5D9D14E1ULL
        },
        {
            0x5B64D1EE14D7C925ULL, 0x8D8AFA5BC0D9F1DDULL, 0x134786F84A61DF89ULL, 0xB31F218FE71AF2ADULL, 
            0x4E5C769A6FA5E961ULL, 0x0E2760D2420417EAULL, 0x8EA28F4FB4257B3AULL, 0xFDC0F2F263AFBCE6ULL, 
            0x5DE4BEC49C1C03D1ULL, 0x9171D0724D9F0995ULL, 0xC2412F971DA4DC99ULL, 0xD6A05F3FB21B7001ULL, 
            0x254B81F0D3A7D6DDULL, 0x0E31CFE1463BB4F9ULL, 0x0F1485AA395215BBULL, 0x47BF6C49DDB9D7DBULL, 
            0x3E306006AA672439ULL, 0x72FF454C39BDB9E6ULL, 0xA04BA2FED2B44979ULL, 0xFC21709D2A8D1A75ULL, 
            0xEE68DC7592FB1359ULL, 0x47307D4826B0FDC5ULL, 0x77357ACE9C8EB48AULL, 0x61EFC8EDA0EEAD04ULL, 
            0xC39CF19D33985AD3ULL, 0x6F7B56F0B2001E45ULL, 0xE56EE06D69042F8EULL, 0x59711E73B2E262E6ULL, 
            0x0582D9E13E472D5FULL, 0xC7A9CF27AE1EEFD1ULL, 0x776DB95F408ED28FULL, 0x483A8DD369D951E9ULL
        },
        {
            0xB781B99BB1A8752BULL, 0x60C227EA338694AAULL, 0x7BA9B190B65F87B8ULL, 0x393EA64EDB91549BULL, 
            0x3213CDBBDABAB251ULL, 0x87B05F98C874CFC1ULL, 0x74EEF51A6EEBED50ULL, 0x5E3D71FBEB47FCB6ULL, 
            0x7A6DBC33CA9A564BULL, 0xAB8AB95AA9DD32C5ULL, 0x719C19986C2CDFD7ULL, 0x4CD3B8E4CAC4ACCAULL, 
            0x5B1321FE085A35BBULL, 0x022A90CA1F912C10ULL, 0xBC12851826ABAAE6ULL, 0xB37352E0E1F1908CULL, 
            0x0B42D8CE3FAB067FULL, 0xA4B546C2802526FFULL, 0x257BA6F57A02EEF5ULL, 0x2759F24AB39520E2ULL, 
            0x9480054FB4F04EE3ULL, 0xED7B25508F321D18ULL, 0xA0357BA674E38B9AULL, 0x4BB46E1473A459A8ULL, 
            0xD053D6F5D8B03F4AULL, 0xC22F797E554BA291ULL, 0x88B2171C0C04C922ULL, 0xD145899CCD49A0C4ULL, 
            0x9B5507404804004AULL, 0x47C9BAA3CDD45E52ULL, 0x2F80B5693546BC7CULL, 0xE0C532AE45C11556ULL
        },
        {
            0x35F03B720C153BF6ULL, 0x0EC3B6F4EDC86FC0ULL, 0x65B7AEE92A7325E4ULL, 0xEC2A94826CBEA7C6ULL, 
            0x92CA9F9537B15A29ULL, 0x7E1B01A9DBB49046ULL, 0x2777FE0E2B581FB2ULL, 0x797940C9816CD2D0ULL, 
            0x5DC03EC26DBF1DC2ULL, 0xEF2B68E0F5AA0E35ULL, 0xC88C8B0AE0BD236EULL, 0x6E3D663C4B32B726ULL, 
            0x5281E2E1E43E9B3FULL, 0x23045D26F87903EAULL, 0xCFA108ADC4018003ULL, 0x738FF6EC9023383EULL, 
            0xCA266CD081CBB1F4ULL, 0xFC2CC69A54F3B587ULL, 0x61A858301C0F2298ULL, 0x2DC25A91DAAC24BFULL, 
            0x70415A9847DE3E8BULL, 0x9635F43CB9960F1FULL, 0xABBC7BFD7ABE7CB8ULL, 0x25F63FF2B6927631ULL, 
            0x71C346F6D351E1E4ULL, 0xACF316CBEC79DD63ULL, 0x20E6C6FEF6E4541DULL, 0x7E4316533C333E90ULL, 
            0x2168295E13ABF688ULL, 0x0A2C26A8C0F18E59ULL, 0x0F1EF383A903EDC1ULL, 0x2B06CDB5261F81A4ULL
        },
        {
            0x13697EEE8E9743BAULL, 0x366519334904C8CDULL, 0xFBD85E2C3FD5AF6DULL, 0x0BCA12CB487680D7ULL, 
            0x8AD512713A470B04ULL, 0x5FA36D7D2CF085D5ULL, 0x4D5A53D898B9F8B8ULL, 0xEE2EB4A515512706ULL, 
            0xBFE905B1D00CC354ULL, 0xDCA76D154FB8FC08ULL, 0x99F6C75510BC3F8EULL, 0x6EF087C815C83849ULL, 
            0x2F2C8201DE2617E9ULL, 0x2AAB03E4E52E1264ULL, 0x567482A33588D56AULL, 0xA363B8D361059D22ULL, 
            0xA57E9C6535A0B399ULL, 0x360A68B81ADCDC3EULL, 0xBABFEE76AE6661B2ULL, 0x5814ED829991F439ULL, 
            0x29C7A5CFBC2A077AULL, 0xF5C9B15D51D7196EULL, 0xE8C80EFA8F0F2519ULL, 0x91B3C90A39A749C8ULL, 
            0x6D2BA3BE89E2ED70ULL, 0x99D851A3CEC1A1C3ULL, 0xC77479BC9F469C4AULL, 0x6727A52EB5911AEAULL, 
            0x9D35737B24E4DDB4ULL, 0xBB234AFC65C555D9ULL, 0x06204F47557BFF91ULL, 0x095AA617AAE58528ULL
        }
    },
    {
        {
            0x2827EC1FB5F4B3A9ULL, 0xC6F7421600CB8A64ULL, 0x9868D20B7657CC27ULL, 0x34C6CC59505F37A3ULL, 
            0xCC9DB92B52AD1738ULL, 0x5A7153B56AF9088AULL, 0x2418DDC073F2938BULL, 0x2E4757852F723FAFULL, 
            0xB8DE80F4C2CBE755ULL, 0xD016DC24424EFECBULL, 0x7597EF98A30E4AE8ULL, 0x0CC0C09ABF5BCF76ULL, 
            0xE1FD996F313C8E09ULL, 0xD5EF6D38701DE575ULL, 0xD7F5DD4EDC598A21ULL, 0xD6C24B3768BF13F4ULL, 
            0xFE8876065847A96EULL, 0x7502C34C985EA006ULL, 0xB50682D202513116ULL, 0xE3CF3005AC86175AULL, 
            0x715FBB1B506088AEULL, 0x13C3672AFD27F642ULL, 0xA9E0469E9F12BD63ULL, 0xCBE1C11543856246ULL, 
            0xFCB9CBC48221C7ADULL, 0x5D46C3E543EF922CULL, 0xBBF3FA950FEB8761ULL, 0x455A14181E42733FULL, 
            0xE9CD8485DCF3036AULL, 0x028C57EBCEE29047ULL, 0xD673FB8581D1533DULL, 0x89839540C5D060D0ULL
        },
        {
            0x6F9B53C08327DCD0ULL, 0x42121DB913B91E31ULL, 0xB99E6A570E7A631EULL, 0x29BF533608D0C82CULL, 
            0x76C7A390AB81B53FULL, 0x31AE727542EF67D4ULL, 0x389DA6E3A0E1E9ACULL, 0xA197412FAD59525DULL, 
            0x3E61BE2F26237BCAULL, 0xE948FF2624EF1D17ULL, 0xED94B12B53670FC6ULL, 0x8CB2D1F841BEA57EULL, 
            0x5135A3225F239BD9ULL, 0x6B644D2BD5162661ULL, 0x11F863EB4D5E5117ULL, 0xDCFF6C91DF8D68B4ULL, 
            0x9A4EB2ABFA062B32ULL, 0x3A818CC2F14A7CFAULL, 0xF5DF0898B9D9D934ULL, 0x2734013493A14B53ULL, 
            0x538A24F408F80F1AULL, 0x4A03244A4A629785ULL, 0xAAFADD365809765EULL, 0xF2D56DC21A22CD78ULL, 
            0xD554E3BF7E442F0AULL, 0xA6CB66971C1B06B5ULL, 0x3500E724CE84C4BCULL, 0xCB5D19215B7FD1D9ULL, 
            0x3788EE0A968C4446ULL, 0x32F2C400592BCBDDULL, 0xF65A22A7B803EDF6ULL, 0x39D63B308E8BE730ULL
        },
        {
            0xEC7C2CC841A6640DULL, 0x616B4057956D94F4ULL, 0xDD0247F68852F2A1ULL, 0xBC44267995AB49BCULL, 
            0x6E767604B6C38869ULL, 0x9761094B98413097ULL, 0x33960394DA50588FULL, 0x2602F377A664CAA9ULL, 
            0x1AB16342F1C0F230ULL, 0xEB59AFB64F937A83ULL, 0x763102E6E27E08F1ULL, 0xF38C4F80C6D9D481ULL, 
            0x6287AF6F0897202CULL, 0xBD2C98A8D7FB6782ULL, 0x29C76C8D9F690975ULL, 0x9FB9BB1634B8509AULL, 
            0xE098565E62AE88E5ULL, 0x41B028CB7C17477CULL, 0x12F510E0E8657563ULL, 0x84895215DCA40D6CULL, 
            0x983BD292261D30B4ULL, 0xD35C2188A32C3622ULL, 0x4BDF1656A9CFE405ULL, 0x1B22409349954AB5ULL, 
            0xDBB874EFD389ECF2ULL, 0x6D27228F6F3F7888ULL, 0xECFC5D41B87C4A69ULL, 0x7DA33D3AB7D9B933ULL, 
            0x5FA005F0D31DD00DULL, 0x9BD49EAE9F08FA4DULL, 0x92EA8B10FE03FB30ULL, 0x9CF459D4A2D80268ULL
        },
        {
            0x2894BB3A09EBD5A8ULL, 0xC2A79A892A855AABULL, 0xECC2AFB563A24EC2ULL, 0x39C2913CAA123F39ULL, 
            0x6928A723B8F27FF1ULL, 0xB59B8FE0D3323345ULL, 0xDF994C7C5179E40FULL, 0x57F0464B2425852BULL, 
            0x4C110C6A97771A5BULL, 0x19BBBFD8A4EA9C13ULL, 0x0F7217014E8D7689ULL, 0xCA534403DABB94C6ULL, 
            0xC3B7CA71C82E0F8FULL, 0xBBD70EADF4F78989ULL, 0x79F5F6E75FA6C5CDULL, 0x7D6922169A53081FULL, 
            0x37D50EB8EA9C08A9ULL, 0x561CE6C0B804AC32ULL, 0x6552E6F066DA3299ULL, 0x46F08D177A6412FAULL, 
            0xC2F5CEB8A7323841ULL, 0xBF9FFF6CCF23320BULL, 0x911F6B5377201270ULL, 0xAE528E6E46B6D49FULL, 
            0xA3CE6C508C014802ULL, 0x20948F25616549A9ULL, 0xEC270DA4394F19E2ULL, 0xC9A755AA91CFB785ULL, 
            0x974002F23273EEEDULL, 0x0CF0892B0DAF2DBAULL, 0x5495663C7B7EA03DULL, 0x50C7087B7D7687CCULL
        },
        {
            0x617CB36824F20B51ULL, 0xA56D99C619BAF4C3ULL, 0x4D40A2E814FF38BEULL, 0x2086FDB541B66FAAULL, 
            0x0A9BAA5F47793491ULL, 0x1EF94835D4E6219CULL, 0x8171CFC8E6722740ULL, 0x3A1B997004592D51ULL, 
            0x833B6DF1F59F2BA7ULL, 0x6013BDFFD096E5DFULL, 0x9BEA19F1CA1DC1B3ULL, 0xF0285A3014AC8D3DULL, 
            0xB1927965293050BAULL, 0x78D2909037F19268ULL, 0x504DAD63302C6871ULL, 0x9C04FD4BEE4D71BAULL, 
            0x776E152B2D92997EULL, 0x1D3ACF255D4DEC79ULL, 0x411FE66836C250D6ULL, 0x1AD282C85F48CA96ULL, 
            0x6F9B15F446451F6CULL, 0x4FE086AEB812279FULL, 0x19C40D6C0120E1CAULL, 0xBDCA27A1B1436EF5ULL, 
            0xAD3B29046975B41FULL, 0x68136D51C0395D5CULL, 0x7C1382084D1BA409ULL, 0xD90CCF26D2E6588DULL, 
            0x2CCB779534A02867ULL, 0x4E90E6EEFE207E15ULL, 0x2C93BE0C7348C4AFULL, 0x16BE6307C9DA254CULL
        },
        {
            0x03998A344090F38EULL, 0xDA67FF893D8313B2ULL, 0xE360395ABF7FBD00ULL, 0x5EBCBE01F15C67E3ULL, 
            0xC78B846C8C6A3425ULL, 0xA2591468A4656804ULL, 0xB83635F0E0C9D6D3ULL, 0xF424613E0094C06AULL, 
            0xE50E7DE199699240ULL, 0x624B7B374214E7B1ULL, 0x9357F34B50DAA2D1ULL, 0x870E7F00A3C1B002ULL, 
            0xE8B4011C3235989FULL, 0xE561E8FAEDEBCCA7ULL, 0xAC0417EC46B14B43ULL, 0xC0F3A7D605562AD0ULL, 
            0xAC8A581BD3C81015ULL, 0x0D29814A6B43B411ULL, 0x83B2A55BEDCAD960ULL, 0x74056225D2BBA6A1ULL, 
            0xD9661A4423407B0EULL, 0xD1AB2DD502519D07ULL, 0x6C8F0D9879FBD954ULL, 0xCB23A17EAB7D962DULL, 
            0x12A5069C5FD7AC03ULL, 0xDFFC9EC59F87CB41ULL, 0x12ACBCEA8F5E66ACULL, 0xE1BE86812B166716ULL, 
            0x1CBF3FFD9677A236ULL, 0xD1D3009CC507F2E5ULL, 0x0348BF5A0190F5E9ULL, 0x716BB424A8563583ULL
        }
    },
    {
        {
            0x7BAE2F58D1D40893ULL, 0x09EDA233AB00E464ULL, 0xD81FCC3DA6AAFBF4ULL, 0x7B2914154144E1A0ULL, 
            0x77C736830A7376D6ULL, 0x273571B4ABF9D6E6ULL, 0xA84AD1CB3A18086BULL, 0xEB411155982188B2ULL, 
            0xF1A43D4C7173C20FULL, 0x42AA287773F0330AULL, 0x9583C7709BA9C0DDULL, 0x42D23002468978E1ULL, 
            0x47B9490FB817E319ULL, 0x763D11AFD7C641B0ULL, 0xE32C9021EFC71482ULL, 0x2D983FF66078D2E9ULL, 
            0xAB4264875268C7F3ULL, 0x693820B18CA35E8FULL, 0x1DDBF075AAC41723ULL, 0x1F933231A8BEF1CAULL, 
            0x15035969C02C7797ULL, 0xB1F72744716EF5D5ULL, 0x40836BC52C5973EFULL, 0x59594EB5A3A06E16ULL, 
            0xF54D892E0A62104DULL, 0x1DB172BA17921C87ULL, 0xEBD97C4BCF5AA40EULL, 0xD08B6B5B6F6C9261ULL, 
            0x925325DBE3506646ULL, 0x021BF99AFC890242ULL, 0x97866B61A38A65ABULL, 0x7F6C86D73FDB82A1ULL
        },
        {
            0x91A46A862D55BA5DULL, 0x4FEACF8FFDF9B16FULL, 0xB3178DF7FB941EA3ULL, 0x12ED187DA49EE4ADULL, 
            0x51EA23BFB91185D5ULL, 0x03CA8190FBCB42D3ULL, 0x4409CC7EF56D00F8ULL, 0xBCBA9C3469943416ULL, 
            0xA04D40F5A5D88C32ULL, 0xA32D50A5A777B93AULL, 0x574551B66ED8E35AULL, 0x8928F4470922993FULL, 
            0x2EBF62CDB07DB4E3ULL, 0xD5C156C8225008FBULL, 0x46029CD1874675F1ULL, 0xFB9C4E6CCE64C20EULL, 
            0x5A9309C63C5DAED1ULL, 0x91744CACC3BD8778ULL, 0x7B6E41DA94050B1AULL, 0xD213BFB07E123164ULL, 
            0x25683E1DA6E6C189ULL, 0x6AB0C2E8A118C86DULL, 0xD651B366722009DFULL, 0x51FB1150EB33E012ULL, 
            0xCD7DC71401B06C3DULL, 0x191C01EBA0973692ULL, 0x27E17A678A559DCDULL, 0xDC8F6C0FA564EAB1ULL, 
            0x0C2B7B0F2791B128ULL, 0xAD9F05D233DCB181ULL, 0x33754D2534B8B115ULL, 0xF54AF811001D7FC5ULL
        },
        {
            0xA4791FEC8D04F48FULL, 0x2F11D95063280A16ULL, 0xEB5291E2EEF7C992ULL, 0x3414CC358483606AULL, 
            0xC5373E27A29146F0ULL, 0xCB778B26A03159B1ULL, 0x3C6CD596802196FAULL, 0x39D2D8AEB00BAD31ULL, 
            0x6E52ABDEE5CA2B77ULL, 0x5B0E4A10E1D72EF6ULL, 0x6C2E0B0258378837ULL, 0x101CC048F77E4BE2ULL, 
            0xAB1EB7358AAEA358ULL, 0x8DA97A702CAC3EEFULL, 0x91E04950A1C6FB80ULL, 0xEAE4ED4E02CF8D16ULL, 
            0xB2AE785E8831A3A2ULL, 0x8C990AA348E4549EULL, 0xAE36789B127DDBD5ULL, 0x4CD32D221BEE9CDFULL, 
            0x86A6654EB8E4509BULL, 0x90D5A3B428CFAA52ULL, 0xADE32DCD79EDA498ULL, 0x5B43A5E1AD3727E1ULL, 
            0xC66EA7F6EF18F0ABULL, 0xCE25AE0360017311ULL, 0xE7412756FAE70F8CULL, 0x39A1D00815DCD73AULL, 
            0xA32EB397A005B529ULL, 0x6360998E4BF02F3EULL, 0x0A90C5F1CAA01112ULL, 0x3665A64117C6C6BEULL
        },
        {
            0xB412B83D5803E6A6ULL, 0x679E17BCB8E31936ULL, 0x25311C8B4A50059FULL, 0x9AD64436A36E42F9ULL, 
            0x2D4A845D72BC49E9ULL, 0x5BF6F9CE54C544AFULL, 0xE789D8E52054F656ULL, 0x47E5BB854EC2A9B1ULL, 
            0x91ABF230C0003433ULL, 0x04620B2D8BF77999ULL, 0x268153BB5BD3EC85ULL, 0x4853CEED2C217713ULL, 
            0x63C0D8833E25B3D0ULL, 0x6343DB44CAA848E3ULL, 0xDD72117D46ED3E46ULL, 0xE8CF58606F108A7AULL, 
            0xE14C8EA964D1A03EULL, 0x87F81025594FA7B4ULL, 0x97C2D91221EC1736ULL, 0x42602FD1CFDCF4ABULL, 
            0xD3A5F374ECE1AE20ULL, 0x8A0EE1A2F95249E7ULL, 0xB9966BFD6C8D4D06ULL, 0x6A1F9A345D03FE87ULL, 
            0x93730DA57DF65E5EULL, 0x41664B36F95DE9D2ULL, 0x2F9BB0DC63D2EFB2ULL, 0xD0233931923D87E0ULL, 
            0x747C0BDDDA1214DAULL, 0x3F4EAC2B2D8D1160ULL, 0xBC884E2FC01130E6ULL, 0x9963A877BC890A56ULL
        },
        {
            0xB37F770D6F54CEC8ULL, 0xC43856F736DD66BCULL, 0xE7F3C20E4CA86DF8ULL, 0x2BFBDACEBE64BE9EULL, 
            0x59F7C91945EDD719ULL, 0x97464325B42B10B4ULL, 0x5AB708F07D3BBDA4ULL, 0xAA90D3759FCC22AAULL, 
            0x4EF0EF7AC7F010FDULL, 0xC0C5EE8B5365E8ECULL, 0xC4DFAFA45DCA1EA2ULL, 0xF1C11024DF982EEFULL, 
            0x29E9D8F3110C19C0ULL, 0x1386B30AE63ED9DBULL, 0x9D0E6EC307ED7F81ULL, 0x3F7310B05FDA414EULL, 
            0xE0EA56CE70AA78E3ULL, 0x7C8595099B6E3028ULL, 0x4875F6DFEA63FB70ULL, 0xAB1304ECE16B6112ULL, 
            0x47A939FC30ADB3E6ULL, 0xC361886B0DA1C8DBULL, 0x8BFB1774C35D29FFULL, 0xCB1665B3466C69D2ULL, 
            0x82F447D36A4C50BAULL, 0x839B2E7301357FBDULL, 0xE04AA248BAEB175AULL, 0xC5567006CDDE11DEULL, 
            0x4AA00CA750631779ULL, 0x995C3ED8635CB0A0ULL, 0x81D45F4CA0D41A72ULL, 0x4E0B5EE66479A634ULL
        },
        {
            0x6F93822C2B6EBC5AULL, 0xB68E02E8977235AAULL, 0xF7410A8CC9E0C9B9ULL, 0x84C8602F26E6D77FULL, 
            0x065A247019D4E465ULL, 0x1505112E0C730CDAULL, 0x2753C0384641A584ULL, 0xF9A3C00224A6307BULL, 
            0x71441D2141A5BFE9ULL, 0x7E1C218C88AAAA57ULL, 0xA3BE42F422C419E4ULL, 0x0A3FC1583C735C81ULL, 
            0x104C6B4FD6EB16FDULL, 0x40C04111F6C37BEDULL, 0xBFDDD5789ECBE664ULL, 0x5BA8A8B46AFC056AULL, 
            0x959BDB59502F1059ULL, 0xB4242FE7E7E3E73BULL, 0x386CB73FFB54644FULL, 0x0102C8787DFF06A8ULL, 
            0xE10307D2C623405DULL, 0x4B23C75F125B50D3ULL, 0x3ADB053B7622400CULL, 0xA2684F4F413C0E39ULL, 
            0x8FCB1637F4C2E624ULL, 0x3812078A420342E5ULL, 0xCF30EF7735CA8DA0ULL, 0x76941E1448D12178ULL, 
            0x4C69CB067A58120AULL, 0x1174C8999AACF850ULL, 0x93CCD06EDCF2E3BDULL, 0x216FD1C2F07F054AULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseDConstants = {
    0x60B0D1309F8ECF9AULL,
    0x60135FD811C8D862ULL,
    0xF81D9F14F5096DE1ULL,
    0x60B0D1309F8ECF9AULL,
    0x60135FD811C8D862ULL,
    0xF81D9F14F5096DE1ULL,
    0xA87F70428CC7B28BULL,
    0xC7CC3CD542977FA3ULL,
    0xC5,
    0x37,
    0x07,
    0x55,
    0x56,
    0x9B,
    0xE1,
    0xBE
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseESalts = {
    {
        {
            0x97F16DB07E1D8113ULL, 0x49E4F31A98374124ULL, 0x0C1F2F63FCEF65BFULL, 0x383FE7D6E2446B22ULL, 
            0xE1DDEF3FE4DDD465ULL, 0xE0254A57E18EC2B7ULL, 0x96C09FE6845159EBULL, 0xC8561D81BF832509ULL, 
            0xA9E87D0102BD8C0BULL, 0x764233A257471C1CULL, 0xAFB992CB01FE6415ULL, 0xCE4AA62D1E729AD3ULL, 
            0xC05DEAA312871B2AULL, 0x3D960C79C9D4D4AFULL, 0xF694903AB9110018ULL, 0x189BD7315336194CULL, 
            0xA65A486912ED181FULL, 0x85994970618AF1B4ULL, 0x2B891570D37ACD00ULL, 0xA941F2DF0FA0B8D8ULL, 
            0x0486ED0C2AF62D50ULL, 0x3112EC26C20BC0BEULL, 0x3AF9ED6F997B61E7ULL, 0xA409E920E8746D79ULL, 
            0x4E410462ADE2A1B6ULL, 0x1E35442D435F697BULL, 0x8E540744881668F2ULL, 0x016FB7D105EDE272ULL, 
            0x66B8DE59C27DC76CULL, 0x03D996996DC85CA9ULL, 0xAA3529171EB778BBULL, 0x6F7B3D8BAEF7D49EULL
        },
        {
            0x6CD4852B9E62DA06ULL, 0x3790D79B5FCD239DULL, 0xF0BB3413675548B9ULL, 0xE66B4801789F4BACULL, 
            0xBE8DEBFA9F7D6031ULL, 0xDB3F981D182AF8C7ULL, 0x30FA78B415DEF369ULL, 0xECDA44AD78D1585CULL, 
            0x616CEEEB005D5F10ULL, 0x0FBD639A2F4B39D1ULL, 0xC0E3BD3463972B45ULL, 0xC2790897EA4F92A8ULL, 
            0x7034F8824FF15F6BULL, 0x125BE168DA14C2D9ULL, 0x11F5187553A07807ULL, 0x9293C1208C7BBDA0ULL, 
            0x2E77625F739C17CEULL, 0x8BB9E7C5CE766DA3ULL, 0x0EC0B4799ABCDB52ULL, 0xE6F90E930B9E1B47ULL, 
            0x8D0A8644E48F8083ULL, 0x4C1DEECA456E522BULL, 0xA43EC99DE55628CEULL, 0x59574B891AF6C55DULL, 
            0xC4086DD79AC3704FULL, 0xA44A02D8BBC1A0F7ULL, 0x77F046969B21DBD7ULL, 0x6E90AD824DC27446ULL, 
            0xD9FE9517D8E1DE8EULL, 0xEA8EFEDD8B9A6A1DULL, 0x23424B117CDDD6A5ULL, 0x55AA50229EACCCB5ULL
        },
        {
            0x18B2846F8192A6E2ULL, 0x600707D03CE5FC74ULL, 0x43ACB0C987F104F4ULL, 0x754FD71A9446CCA6ULL, 
            0xB2B6E73785B7A00CULL, 0xDD636DCA0D701C17ULL, 0xAFEE8ACB2CFFBF96ULL, 0xBC748C6530216D98ULL, 
            0x549E0C8BA8860FE2ULL, 0x2C35BBDA76F28BE3ULL, 0x22004234E9768FADULL, 0x613B19423870D12EULL, 
            0x2740479BFA928A51ULL, 0x5B3887391D0B2B2EULL, 0x81191C1674F29983ULL, 0x3F8970A61597B79DULL, 
            0xB96D11737CEADC9DULL, 0x5F70BDB8610C58CAULL, 0xA79788756E3BADE7ULL, 0xB6314E98342DD71AULL, 
            0xE941597E706CBBFCULL, 0xAA31AEF57CD408A5ULL, 0x2EBF225EC009D768ULL, 0x7E9723239A205420ULL, 
            0xE6D22EA01CD03A93ULL, 0xDC1B57AFD9EC0727ULL, 0xC6171F5ADB58AC21ULL, 0xA8A91F4EB865E0E7ULL, 
            0x71888856E21FF309ULL, 0x5A7116861CCD3498ULL, 0xB46A18F585CD0CA2ULL, 0x2E4F737505CBFFB6ULL
        },
        {
            0xDB160BCDE1EAF331ULL, 0x18628B8367092FFAULL, 0xFE2C4B1C01878A68ULL, 0x9A95671753525C74ULL, 
            0x68D6B83DD1482449ULL, 0x09A8CF6085DB2E86ULL, 0x709CFBF7097E1466ULL, 0x35836367D643FBB7ULL, 
            0x92F54F8D5316AF51ULL, 0x608C5A6819BBDEEDULL, 0xC40EBC6D79C59B72ULL, 0xCECEDF1F28F47530ULL, 
            0xC06AC6C0A11492EDULL, 0x0EFD98C049D8C5B7ULL, 0x3003141D565387A5ULL, 0x55A4385088F0A1EDULL, 
            0xE6604E2A2CEBC1F4ULL, 0x737F35D80C15C537ULL, 0x5738A9B7401D8149ULL, 0x9CDBBB75B2EB7155ULL, 
            0xE4CE534A9172E834ULL, 0x3DF823D186CBC667ULL, 0x715354E2D3DFECF7ULL, 0x75CAE9617C0A6F1EULL, 
            0x24D47A55FC1063FAULL, 0xEDF2CDA7FDDC4827ULL, 0x228C91B4362A9ACBULL, 0xDAB18C14210F4E36ULL, 
            0xB563DE332CB52FCEULL, 0xCC868AE32FCE11F7ULL, 0x869558F6BA979B28ULL, 0x7729A099DD9ED13CULL
        },
        {
            0xAE873A04CF3D9E82ULL, 0xAE06EC0A4B6CCB41ULL, 0x7523525C11AE2E1BULL, 0xCB311036C233E91BULL, 
            0xEB18E50855AF1E90ULL, 0x133249BE8CAA3F47ULL, 0x9A3DDE1A64174CBAULL, 0x1DA555BBC1449156ULL, 
            0x23D057A009302592ULL, 0x4D20D848A153C163ULL, 0xFEDFA661F25595EDULL, 0x461F68E4C5B9B358ULL, 
            0x9FED4E990416C822ULL, 0xEB4DFB7F57C835DAULL, 0x0291BBE5CAD2E9CBULL, 0xC9200F7AF950F608ULL, 
            0x28C53D850AB1493EULL, 0xDD716EEB924579FAULL, 0xB3A7EE8D1AC2D628ULL, 0xF7D38277C985B2FEULL, 
            0x62342505767C0E12ULL, 0x558632886FBFB06DULL, 0x3468F342D14EAE0BULL, 0xA707D5204291655EULL, 
            0xF38FD767BCDD1A66ULL, 0x8DE113D43298F44AULL, 0x09AA295414F4DA60ULL, 0x3587F2A8A7157505ULL, 
            0x8B1D1CB3B69D0B8DULL, 0xAE3F53ADF32AD684ULL, 0xDF9E3383A05F1CA3ULL, 0x1A0F1AC826148931ULL
        },
        {
            0x94E4A3A2275DF8BEULL, 0xA4AFF26DEE6BE4EBULL, 0xF604B4DABE880B94ULL, 0xC533A90D854791EBULL, 
            0x2437F29F794C9207ULL, 0x79D4B152C8F242A8ULL, 0x8D8D8CC1AE684B00ULL, 0xD33CF160B434CF66ULL, 
            0x58C63635814D1C68ULL, 0x749865B272603EDEULL, 0xF30F1A7752B1D2B3ULL, 0xF5E88BC0D481B543ULL, 
            0xAEC317502B5F91E8ULL, 0x095DD775DD731334ULL, 0x580283B67EB02D26ULL, 0x0BA14C3C82AFDA7FULL, 
            0x726EE49B7C98AEFAULL, 0xE66549A5721A759FULL, 0x272F9178EBBD2E34ULL, 0x086B4C57CEA0F80DULL, 
            0x2B7443DE36C888DBULL, 0x3E93709705845E03ULL, 0x035414D1B2096427ULL, 0x8E64F7210E2B6D03ULL, 
            0x0DD15789912FEE3CULL, 0x17574B6C2A77CB45ULL, 0x02F23228ADC4B92BULL, 0x9C4488D3EFE26EE7ULL, 
            0x4B3FE9E81FF5375BULL, 0x2CCB40411742708CULL, 0x10A1B619E25DDD92ULL, 0xB3A77B6708E88487ULL
        }
    },
    {
        {
            0x75697076A89C7307ULL, 0xA2A7F591100D11A8ULL, 0xF77AB004F29F98AAULL, 0x195BCDAAADAA7ABBULL, 
            0xB24DD8260ED97A07ULL, 0x0D26C61E1F2E291CULL, 0x94E5389555D99462ULL, 0x4EE189B4ECD5191DULL, 
            0x05A5932641EBD393ULL, 0xED97A836A33F8032ULL, 0x3637273E432FC960ULL, 0x1ED04C8728190141ULL, 
            0x720D880D29841F10ULL, 0x2EA1AD4F03C8B9AEULL, 0x28B20C797A44AE02ULL, 0x42F1C95AC81ED605ULL, 
            0x16F4B9937EB1ADB6ULL, 0x2DFE8C3F9E802B97ULL, 0x7DBFA592A81C33BCULL, 0x5B24CD53655F2219ULL, 
            0x7C9D978BBBAECEE3ULL, 0xF953C8A5400141D4ULL, 0x4DA03580E3DB8F86ULL, 0x067BA17B636BBBA2ULL, 
            0xD870AED195CC095BULL, 0x9E4278BC73916F67ULL, 0x7E434EC7E0D886BBULL, 0xF3BDEC82AB749733ULL, 
            0xBEAC8A49E659AF92ULL, 0x8D8AB12C94D36B5FULL, 0xE81ED5331CA45286ULL, 0x2D30CA3AA29EE4EEULL
        },
        {
            0x1B91BD4A893E743AULL, 0xA64CD320E69F1B7FULL, 0xBA76015346716E50ULL, 0xFCD7665A7ED5C0A1ULL, 
            0xF609436A958B97D9ULL, 0xDB145F9B9D81B88DULL, 0xE044EA650836575EULL, 0xBFE5D34704615C76ULL, 
            0xD77FC01A8AA1A989ULL, 0x46163CBE25A2BB8AULL, 0x6E934D3BEC50600FULL, 0x01839D416F76CB9DULL, 
            0x1F65E480C7165D68ULL, 0x97CBD749D0E93C4AULL, 0x70DF76560F9AB40BULL, 0x48A1A079D19DD0CAULL, 
            0x194EDB4ED0220F21ULL, 0x3A2A592065A472E2ULL, 0x551C1F74E468464AULL, 0x0885A46EAA9DE0E8ULL, 
            0x5A58AC7A6A8BAC89ULL, 0x916428E48DEFCC78ULL, 0xE000E67D76DE52D9ULL, 0x6CFA383FB23DD88AULL, 
            0x7776C2FF62919598ULL, 0xB58E6C7B0298B20CULL, 0xD1586523FB80A423ULL, 0x60A5428C91A42148ULL, 
            0xDED163C826952E17ULL, 0x60FFC37A81EAB35AULL, 0x11B59D0677E69318ULL, 0x04EA52DD901A4212ULL
        },
        {
            0x56F461934094034CULL, 0xFE9C1B7BB2A155A7ULL, 0xB735D6821A0065BEULL, 0x4915CF45474B1AA9ULL, 
            0xCE099C0520E51465ULL, 0xEBB5684C3A0BDDDAULL, 0x5A82F5301EC396D4ULL, 0xF645AA3A9F2E9701ULL, 
            0x0C566B38581B7228ULL, 0xF08641C48164C102ULL, 0xF8E943CFA0FE00BEULL, 0x78945792B3EB1FBFULL, 
            0x0D6D810742CCD71FULL, 0x33C2D28B492A5D09ULL, 0xB0C83EE7DCA62745ULL, 0x58378D5A20905FCFULL, 
            0x1EB2DE17CAB078C9ULL, 0xA014E7F195B5DA2DULL, 0xD06555F366F2579CULL, 0xBB6859F17D026E8CULL, 
            0x8D92246B9D750244ULL, 0xDE541C6794D24C4CULL, 0xCF845EC1A35E8469ULL, 0x7BC911DBF0E6E61DULL, 
            0xAFAD955D7012A71FULL, 0x14B74F0635B44602ULL, 0xFCE7BEE76927BA7BULL, 0x558D045CD1B55F51ULL, 
            0x68152BF0A74A48C3ULL, 0xD9ACCA8967CE0C82ULL, 0x81D51BF742A62576ULL, 0xD5CB5AEF9ADA36A5ULL
        },
        {
            0x659CF73C381CF101ULL, 0x4FAABAEF8DA6A518ULL, 0x3BA053737CABDD12ULL, 0x686B6C5DDE63348EULL, 
            0x1D2FC0D08A36EEB7ULL, 0x644E00A4C716F7FDULL, 0x4B136B7A759FA63CULL, 0x2767C94D4C34C77EULL, 
            0x64A234A565974865ULL, 0x9E4F547416D0B6C5ULL, 0xB04DBAB0FB0F38B8ULL, 0x530D4DBE862BEA21ULL, 
            0x8DACD4687EAEE9A7ULL, 0x46F49C187D12C7D9ULL, 0xA81CF56F049EA015ULL, 0x1E9C8D8C812AF260ULL, 
            0x0FF694F9208F1EA1ULL, 0xE4545482215CDAC1ULL, 0xE5F4C0DECE36FCE2ULL, 0x6EB3BF20AE49313BULL, 
            0x62BE32A6D16C61ABULL, 0x29D37B81E885496AULL, 0xC8AB87E7D45F2A8BULL, 0x96ACD26631B06348ULL, 
            0xFF155FC9DFDCD3C3ULL, 0x347A89210CFEA0F3ULL, 0x68E0F9C390C4248BULL, 0x18CD2F52A247DFAAULL, 
            0xFD39861857694009ULL, 0x16258718E31CE640ULL, 0xA53478506CA7C03FULL, 0xF034DA34FB4E857DULL
        },
        {
            0xDA9C614CD39AD3A4ULL, 0x6F87A6627F4DCC60ULL, 0xB208137AE201EE9EULL, 0x02710F99606EC8B4ULL, 
            0x6DDD3FBE95E57546ULL, 0x42122DE879327676ULL, 0x33BC337BDEBE6434ULL, 0x9BBFEDE52CACBE5CULL, 
            0xF7961572CC8924A3ULL, 0xC9430D3C4889DC15ULL, 0x0F3AD4FF14E16CCFULL, 0x66B38C180F8FFC02ULL, 
            0xED77EDAB1E29166DULL, 0xADB2DB6DB48D1E6EULL, 0xB0AC739D24E79B07ULL, 0xD9ADE3E0A0B9D6D6ULL, 
            0x85DA745B561E224BULL, 0x4E0B6296B92FDE91ULL, 0x6658F1272C0D9F90ULL, 0xC6C3487797CBF716ULL, 
            0xC604F91D1536B117ULL, 0x89EAC33F0641B84DULL, 0xDCC93CBB2D32D130ULL, 0x9AE57E05F3EF08E4ULL, 
            0x53ED9F9D757B91EAULL, 0x8BE8D8F108F34286ULL, 0x1B5276398492A658ULL, 0x623A9C1CFE14FB7EULL, 
            0x5188AD02CF6AC36FULL, 0x3732EA0B30EA2E00ULL, 0xA01F19129B8C59A1ULL, 0x2DE8D00D1FF8D6EBULL
        },
        {
            0xCBDDC28678BA1E9AULL, 0x7DE2F372AAC1BF9BULL, 0x47D11C172E710793ULL, 0x26676601ED23D2A5ULL, 
            0xC90D09120EA1AC14ULL, 0xD03579C9F68ED393ULL, 0x0A6EB3F384E72F07ULL, 0xA1240B20188ED70EULL, 
            0x45FDBD7BD76064BBULL, 0x3D1CFF065023F177ULL, 0x5C8988BE1BC10228ULL, 0x2AF129935B48A504ULL, 
            0x3ABD3E6D5EF20E2EULL, 0xBF40463226577AFAULL, 0x2935E1848453337DULL, 0x60AC363781ABD70EULL, 
            0xA6355F1701E177B7ULL, 0x5286CF04A7994A26ULL, 0xE3A818CAA0D250A2ULL, 0x77DCA6568FC9BDA7ULL, 
            0x663F2C5E633925F1ULL, 0xEFD8F176195B66A1ULL, 0xDE5475CEE5B61638ULL, 0xACCFEB226F4C3529ULL, 
            0x25915C1EE619C98FULL, 0x99C4DB88788E404BULL, 0x1C15346CA7856352ULL, 0xED639C79F6CBF016ULL, 
            0xD10582DADF425D7AULL, 0x721E0D5C120A06D3ULL, 0xE23E2E0FFCC4202EULL, 0xADF340444EDDC249ULL
        }
    },
    {
        {
            0xA4188B775A7ED10DULL, 0xBACF877788C42317ULL, 0x78A0C9FABC9F3676ULL, 0xC35CB313EFCD289FULL, 
            0xD35D2866943D1DB5ULL, 0xEC53C5DCC6388E32ULL, 0x79A2A50F89273B1FULL, 0x7610355E52F81ECBULL, 
            0x9DDA25B86D3974BAULL, 0x6D5EBF4815B5FEABULL, 0x8E89D090B17A4C26ULL, 0x424AF15D8C4847B2ULL, 
            0xA293FD311DF3102BULL, 0xCAACCD1687F41167ULL, 0x9EABF289CBFF67DCULL, 0x303B99875BA54D00ULL, 
            0xE5AE0224E7BE5D83ULL, 0x3CE54CBC61CA67C9ULL, 0x488E38B31CC909C9ULL, 0x1F6FFF3396DE9F22ULL, 
            0xC0366481F948D79BULL, 0x7F76E3732CDE7253ULL, 0x159BD48234432536ULL, 0x601388B613B00D97ULL, 
            0x89E56040024D4C69ULL, 0x24C7CD5ED46ACFE8ULL, 0x26470C6EBDCB233EULL, 0x19AB02641B2C11ACULL, 
            0x634EBB3E097D4C32ULL, 0x2FA823CE9FA55A2FULL, 0x134D1449FCFB121DULL, 0x930E100A63C80080ULL
        },
        {
            0x140C1FDE5986FFFAULL, 0x330D6C61B3FB1BF3ULL, 0xB2D895A729BDFE56ULL, 0xF0CA8EA980DD9B25ULL, 
            0x78E02A1D5550D172ULL, 0x6BA02C1B908D9712ULL, 0xC38FE876D3B86EC4ULL, 0xE4761CF1D5958D88ULL, 
            0xA8CC48D748975EEFULL, 0x6F5CC46517E54D88ULL, 0x9C476CD551A47846ULL, 0x9ADD426FBD8FFDEEULL, 
            0xD6651F6FCC6E7F80ULL, 0x7EA61C061D25FC6BULL, 0xCE758EB2CBCB6523ULL, 0x73B1B1F556755545ULL, 
            0x57C3BCE4CDC9E173ULL, 0x0A961E1358C4CE74ULL, 0x823447A4DEC05AAAULL, 0x56030B154AF4E9BFULL, 
            0x096BDC748558AB9AULL, 0x2D233865A4E08B99ULL, 0x249D8F7833B0C823ULL, 0x129A5061BFCA7BE1ULL, 
            0xE72B89322E9607D3ULL, 0x2B01D1D8085C50D3ULL, 0xEE9DD2757B304662ULL, 0x08ABD25B32E0F9F0ULL, 
            0x7B0C64A4B24C6581ULL, 0xC33FDD52F7206DEFULL, 0x6E076C4D98A50A89ULL, 0x25B56B7DFD0D9567ULL
        },
        {
            0x22D84E60C8010C0CULL, 0x5DFB685DE7425BDBULL, 0x2CF3353CBEB9EA39ULL, 0x40F5654AAFE4B5EEULL, 
            0xFE240E65DF5756ABULL, 0x33F3767EA8D6197DULL, 0x19B35C5E14FDFFAAULL, 0x294A2506029FFF17ULL, 
            0x1D98E82E36894AD6ULL, 0x5763D71236E38636ULL, 0x86AECC5C713E4983ULL, 0xB0BCEDD2F8C9D854ULL, 
            0x8168107231C8E1C0ULL, 0x57027B165EF74781ULL, 0xB3F72C4FEBF521DFULL, 0xB020F104C4AA2DAAULL, 
            0x059CE4F88C631C57ULL, 0x287BAD410475F64CULL, 0x273FECB7C94CB848ULL, 0x1C9328323CEBF0E1ULL, 
            0xD7EF8209C8098B3EULL, 0x60246A1B42B32590ULL, 0xD7963F55D2CA57AEULL, 0x43986DB4371363C0ULL, 
            0x912D850EEA6335CEULL, 0xAA41DF9DA09A0B48ULL, 0xCBC555340C442B05ULL, 0xEF04EEB1E36F17E3ULL, 
            0x8D900E81C04F0A12ULL, 0x49931092C8B349E8ULL, 0xB7A1E0596AC42FDFULL, 0x5150D6579703EFBEULL
        },
        {
            0x7EF878AC763887AAULL, 0xB8051E3C42BAFA6AULL, 0xBCB6E2E9DCAA551DULL, 0x78B1C196C4D118F5ULL, 
            0x86D80B133E19E84EULL, 0x5AFF26DC9514E144ULL, 0xBDEDAC65F7A965D5ULL, 0x706E634DCE6CC1D1ULL, 
            0x7425945FFFF65338ULL, 0x2F5EFFA20B4933A0ULL, 0xFDD4AD4D2064F8EDULL, 0x4AF647A2CCB0DEBAULL, 
            0x6841BD20B3002920ULL, 0x0B7C31D7E7986ACBULL, 0x693DCC2C89BD11E6ULL, 0x447DDCFA393BFD8FULL, 
            0xC8892F808721EA5BULL, 0xBE1D69217C8F892DULL, 0x95FABF8B632F5699ULL, 0x4236681F80249A5EULL, 
            0x19485C322ED2B1DFULL, 0xDE5C33D55A0DC5BFULL, 0x6F4900FA8D25FA26ULL, 0x01BF9D7F9022827AULL, 
            0x705DBA5A3BBF0CA5ULL, 0x57D2170E44D2EAA2ULL, 0xB53C9A6251635ED2ULL, 0x9CB40B2BA4FBEFCCULL, 
            0x00B48EE8F14634F2ULL, 0x7900F0AEC795F9F8ULL, 0x1F827028C64509A1ULL, 0xC2393BA5EB7ED0A7ULL
        },
        {
            0x3A16AFE1084DBFC6ULL, 0x9CC4C8C4C2B447ECULL, 0xEC7A2C6F44E2BCBCULL, 0x837D65F853D731F4ULL, 
            0x64A8AFBCB81DD458ULL, 0x4691F9F6C81B9D1CULL, 0x28AE01446A191286ULL, 0xB56B3FD433F55F61ULL, 
            0x954C84380EED02C9ULL, 0x0B280620246B16C9ULL, 0x0931593BB7E2FC93ULL, 0x6D86DC365A9207A8ULL, 
            0x0121BE9E4DB9F44BULL, 0x7A3FDBB975D48DFFULL, 0x63434C7B0550D155ULL, 0xAFF7E42E75C3A5FAULL, 
            0xC592B8E176594B34ULL, 0x67E4ED8ED0A922FEULL, 0x9F6780C211A0D535ULL, 0xBD6B1ADD5990A837ULL, 
            0xE6750B02ECC50105ULL, 0xAD5F30C086A36991ULL, 0x0904B096B48C9DE6ULL, 0x45A6E7F1BB49C948ULL, 
            0xFC8939C3FA8634CEULL, 0x326B56A18DEF2E3CULL, 0x46E3DF1EB2F013C2ULL, 0xAA7D01569C6459CEULL, 
            0x62638D02FA1BF575ULL, 0x62B2132E7A9884E6ULL, 0xCBA90D4D04A5DDAFULL, 0x2E922088F2313095ULL
        },
        {
            0x56B1A6A56EB63581ULL, 0xF9DC9BDBFE98A5EEULL, 0x09F7473D6846CD57ULL, 0x770D22785ACB8073ULL, 
            0xCA9F7584BFCF0CB1ULL, 0x33A1A0A4D85C30FDULL, 0x373CADC513F86E6CULL, 0x43B69136D0EDCBBBULL, 
            0x00C0577093F84B43ULL, 0x27C8ADC0B2B227D7ULL, 0x0B197480D7CEEEF9ULL, 0x93A29F1FC672CB81ULL, 
            0xB5C72028DFA26A59ULL, 0x8B88352AF5F4AA37ULL, 0x14BD912EB3AF3FB5ULL, 0x9513F5C64063158AULL, 
            0xD9CA7D175C004FE8ULL, 0x603E806197DB8FBBULL, 0xFB41C586C2ADA720ULL, 0x2C2B84325B799B5EULL, 
            0x6B7281E6264DBEFEULL, 0x9B2562BB360A69D7ULL, 0x7905F5518E43C62AULL, 0x14A7CE803E7657B5ULL, 
            0xB3B8B7D70EEE9DC7ULL, 0xBCE43B7DFF56E5A1ULL, 0xB68FA28E1E4FF335ULL, 0x5E74FDFB60E110D8ULL, 
            0x9F5D2523BE6DE0E3ULL, 0xA971B7DA9887D972ULL, 0x9E3EFBDF70ABC373ULL, 0x8F68F2C3A6DF4EC6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseEConstants = {
    0xE42FB356209548DBULL,
    0xADF6B354E5BAC30EULL,
    0x78076BAEFDFE4179ULL,
    0xE42FB356209548DBULL,
    0xADF6B354E5BAC30EULL,
    0x78076BAEFDFE4179ULL,
    0x6696646E41A4914EULL,
    0xE06731CA9890FE6AULL,
    0x22,
    0xC7,
    0xD6,
    0xDE,
    0x06,
    0x06,
    0xB0,
    0x14
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseFSalts = {
    {
        {
            0x4BABE6F3B867A402ULL, 0x307E93F509A8BB74ULL, 0x3FEA148AB95A3325ULL, 0x7E00880EF2C2415FULL, 
            0x2599F077FBA8E468ULL, 0x8B85944B4B5545E6ULL, 0xC7AC8DAC09CA7E95ULL, 0x3E318AA7C1DEC9ECULL, 
            0x84A3D981C2843FE4ULL, 0x83A9168A1D1FCA49ULL, 0x830089EA9C64CD52ULL, 0xE6CB947A5BEAE2A2ULL, 
            0x943111F5085C3798ULL, 0x3454E3C105FF9F6AULL, 0xA289281996A5DA25ULL, 0x223C86FD5D74828EULL, 
            0x5EA845E250E8C3DBULL, 0xF42FB714841BF173ULL, 0x6EA6A2D7E17A0177ULL, 0x106EBEC01E07CE68ULL, 
            0xBEA41663B8F97C58ULL, 0x777159B7B80AA1A2ULL, 0x099F18BDE3980EAFULL, 0xFB2EFD8A1F26AF08ULL, 
            0x76215DA2CDE3CB46ULL, 0xB040AF56770F3C93ULL, 0xC05F8D0B9FB5379AULL, 0x498A5C3DA6D5BD7AULL, 
            0x325EBA81A50A1FDCULL, 0xBA0E6050765C3B88ULL, 0xB713F0AD7855D584ULL, 0xC49CA5C1918AE205ULL
        },
        {
            0x6D6CB1CDB36EB6D0ULL, 0xC811D4D7E147609AULL, 0xD603255FA12F3EE6ULL, 0x947193153B99AF30ULL, 
            0xC7D39961122DCBDEULL, 0xF566E97641157599ULL, 0x2349D4371FE4C451ULL, 0xD72E30AD403464BAULL, 
            0xB8085D1C0AD96A00ULL, 0x98DDE4640118BB2FULL, 0x543D535A9F4896A0ULL, 0x08B94F43D8633F8CULL, 
            0xE3BDD83E7578DD91ULL, 0xC983BFF6A9EF625EULL, 0xF89627B5F4AFFF78ULL, 0x9AE37231CC7A93D0ULL, 
            0x9F77D71ABEC4D7E0ULL, 0x7F17C3707A87A298ULL, 0x4060B24B7020AB9DULL, 0x072D12F5742CBE54ULL, 
            0x146654EBAD020049ULL, 0xC50266A0032587C6ULL, 0x1104527A3C781CF2ULL, 0x104443BB66BB3046ULL, 
            0x376F981DB4FE21C9ULL, 0xEC1A94B0607AFAA7ULL, 0xD598CAFBA1564EA1ULL, 0xF2F63D25F79B47E9ULL, 
            0xEF0A868910F9A974ULL, 0x431FD261463A4B36ULL, 0x9B73CBB6B1719F4FULL, 0xC97F364429DD7325ULL
        },
        {
            0xAA800AC8FBA99DE8ULL, 0xF6C7EBCC7F199AD4ULL, 0x8BE8C6063590AAE5ULL, 0x892BB19EC1561D69ULL, 
            0x839B33AEEF78C243ULL, 0x0DC6C264A5575FD2ULL, 0xD7F531B2477068CCULL, 0x0155FC829171B279ULL, 
            0x9A07DBD654294AA0ULL, 0x936E980EADFE65BAULL, 0x80DD8C09356FB034ULL, 0xFB44981185B6EAB7ULL, 
            0x1616ED20F18846BCULL, 0x19F2610B94A9A171ULL, 0x7A5B3F38098F4F4DULL, 0xA0F95A79ADE1B1B2ULL, 
            0xAD89F877474BFED7ULL, 0x473A28936620272AULL, 0x1A52A0774F21588FULL, 0x9004F39DA6A7293AULL, 
            0x35C62E11B3EC4B90ULL, 0x17D366C3F2D53382ULL, 0xC97719A23BF3F6A4ULL, 0x907628B97A61734CULL, 
            0xC98182F92F0AEE1CULL, 0xB1D0456C73308E2CULL, 0xC2D535A0991DCAECULL, 0x520F2BE667B74FA5ULL, 
            0x74F6B3FA1B4FDD42ULL, 0x3F3D0E33D8BC2483ULL, 0xDDC35B70C74A09B9ULL, 0xE8F9103CC1DB6F96ULL
        },
        {
            0xA6E9DA2210BF2174ULL, 0x866A60D88C796BF8ULL, 0x5651335F80E692D0ULL, 0x8A615CBA2482F621ULL, 
            0xDF53DFB7F633BDB7ULL, 0x2C61E59C7B6F1B70ULL, 0x67B2595E353FCD92ULL, 0xD1D585435897FE90ULL, 
            0x120B0BE5E531ED63ULL, 0x95E18A24706BC949ULL, 0xADE5FCBDA4BDE776ULL, 0xD885493DA86F3E3EULL, 
            0x8BF5D1D91B0A1E60ULL, 0x1A31B223AF80BBB4ULL, 0x92151931285C7A27ULL, 0xE99FB0BC39D24749ULL, 
            0xC9472748904B4DB5ULL, 0xBC054290C01ED0A2ULL, 0x3D617D791224B59DULL, 0x2E91681408B8B816ULL, 
            0x327058241C35F21DULL, 0x74402CBE7C20CE12ULL, 0x5946D8BFFEE93C68ULL, 0xC9CAE14309E9D283ULL, 
            0x8D9AF63E0164BBCDULL, 0xED09235B6310AE11ULL, 0xF0E5F718C2C4DF0FULL, 0x6A97BCAF3F311F1FULL, 
            0x97C977493D4DF9E6ULL, 0x2CACD9ED5452335EULL, 0x2D9C7C42396C0E5DULL, 0x91526919422F06A8ULL
        },
        {
            0x5A14BBD683A50B7BULL, 0xBB91470605D5C267ULL, 0x3D4FA09CA8AEBFC5ULL, 0x9E048ECFEAB94494ULL, 
            0xDC94E9EB6F28E925ULL, 0xB2FD1A4E8F57A673ULL, 0x6B985E21388AF570ULL, 0xD5BFB2AB3F0FADA7ULL, 
            0x9E72C89F57DF2B72ULL, 0x6477D918E6CA8B02ULL, 0xAFF7005CCF617F4EULL, 0x4C5247703217149EULL, 
            0xFCADB11C92BCBBFEULL, 0x99CD4E4444C76544ULL, 0xD862DF806B3C5D1CULL, 0xDB2CF1A8B9F5ECA8ULL, 
            0xE29ECACF547504E0ULL, 0x36B4D353701147DDULL, 0x5238C4F07675761AULL, 0x0E524FBDE99C253BULL, 
            0xD26E4C739657B05BULL, 0xD101F7D739AA1762ULL, 0x3D25A084BC084DC3ULL, 0xB6ECA953CDA8208DULL, 
            0xE9DAFE07A209A569ULL, 0x1798BEEF03C77C22ULL, 0x85532E7E7AB3DD9EULL, 0x74AFE65C7A64EDBEULL, 
            0x674582D9650ECF78ULL, 0x50B868C0581A5C74ULL, 0x9E46E4B3A48AFBC8ULL, 0x67E30470F44CF315ULL
        },
        {
            0x4D880B8570A4B76EULL, 0xB5F1D170AA9AAA09ULL, 0xD97037BD2FD0DCDCULL, 0x8257B92153681917ULL, 
            0x6F161503C3FD74D1ULL, 0x907D1B04A59731DCULL, 0xFB347FA7BF10A431ULL, 0xEBE6514500FC7B4DULL, 
            0x6D3847918E9ED0F9ULL, 0x12809137905BE68BULL, 0x319180239BE774A3ULL, 0xE563C3DC2CB41996ULL, 
            0xDA78AC1EBB433618ULL, 0x191943FD8A03C3A9ULL, 0x1471279A52F73482ULL, 0x2452CE040DA078BFULL, 
            0x2F206B46EEF00385ULL, 0x50EBA37ECD275998ULL, 0xD2F3A97851838649ULL, 0x5F69790B3ACD86DFULL, 
            0x50F209308466DF87ULL, 0x59A7181F3E9CD7D9ULL, 0x4DEC08A306D5638DULL, 0x5A849D888DC3DC09ULL, 
            0x5D7481A752E97894ULL, 0x43E7A62C5992A490ULL, 0x7DBE7BFF951EEA6AULL, 0x6322382A43A8E11AULL, 
            0x5EA6A64E630899F2ULL, 0x20684D2BEE7CF397ULL, 0x0A851DE1A45626CFULL, 0xDA74B9F61D6FAF2AULL
        }
    },
    {
        {
            0x8C783F6F3216F87EULL, 0xB0CEA20013C0428DULL, 0x75F437C5BED1BD1EULL, 0x2AD96CF00DB3C307ULL, 
            0x1FDA49ADBBA40E61ULL, 0x0B4E0A3AA285CF1FULL, 0x0201DE4B8271F2F6ULL, 0x15C5795060288C36ULL, 
            0x925B361B1AE0463AULL, 0xCC41AB06326E4A5AULL, 0x1CA889EC72DF2724ULL, 0xFD3638C8FAA84ED1ULL, 
            0xAC04B8CD1955663BULL, 0x04C910F46A006C0BULL, 0x1D5972F00F74A5E4ULL, 0xF9F3C9ACE6021E37ULL, 
            0x67FD78AF2772DFD0ULL, 0xF490E5958C25812AULL, 0xDFAE0959FFF8152FULL, 0x97712D2F50821232ULL, 
            0x07A7EFFE19D7A3B8ULL, 0xA0D349DDDE0CEFEAULL, 0x36AFA6036966BA5DULL, 0xA6D88096130D149FULL, 
            0x91CBABE122D4D310ULL, 0x906C9E0D5B8C3666ULL, 0x5D2E4A95ABC23597ULL, 0x8CD6790B8B529DBFULL, 
            0x2F335BC2A24BB94CULL, 0x170171443B18D88BULL, 0x47981FE589687C8BULL, 0xC70F763256A176F3ULL
        },
        {
            0xC05FF15ED6637F0DULL, 0xE51BEAFA708DF74CULL, 0xE4BF03A01A6193C0ULL, 0x8A1E6A8BA91F82D1ULL, 
            0xBF78F8BEC1F20AA1ULL, 0xDC73B0A61E1B85DBULL, 0x47F1C2FC68CEB674ULL, 0xA31303579242D1DCULL, 
            0x3DEEDE643F4CE068ULL, 0x6341771F392195C1ULL, 0x2F637BAE8D922786ULL, 0xC57949DAA4511EBBULL, 
            0xE7818156FDFE9AA9ULL, 0xF17DB24F18EA9585ULL, 0x6C6953370AE3802BULL, 0x38E6368E76031DD2ULL, 
            0xC1E1063A6AF8F7D3ULL, 0x14078E1CB4C45CC3ULL, 0x395B64BE66CE3AF0ULL, 0x5DE894D6FEF5C41EULL, 
            0xE1ECE52956B126E1ULL, 0x3B1EA644CA0DA769ULL, 0x1D1616EFCAFF7E13ULL, 0x50D43998AACE462EULL, 
            0x63D003D170C8C1B6ULL, 0x203FCAC4840A664EULL, 0x87E70BE5B28C4153ULL, 0xC1DBBA7ED44329FEULL, 
            0x3BF62A7B51D95EF4ULL, 0x3D1758677B7366B9ULL, 0x2E27572CE854234FULL, 0xE1D8B1967FBF3BEFULL
        },
        {
            0xB4B797624E8EBD6DULL, 0x270BDBC822A3648CULL, 0x790E1818FB4FE4E1ULL, 0x05B7D4B974E3F2C8ULL, 
            0x30598995F9113D69ULL, 0x1CABBEC8F0020AD8ULL, 0x0F06867FEBF5ECA1ULL, 0xC13DC97848A4A755ULL, 
            0x155362F63D46070CULL, 0x943BA812362B66C0ULL, 0x0193744D8FF32CF5ULL, 0xEFCB6F9B2E998F47ULL, 
            0xFC6A8CF7F174B06BULL, 0x00345572873DF78AULL, 0x74BABB37ACF1E5F2ULL, 0x1B53EE6E0504E3E6ULL, 
            0x7D3181CA0B2B04ADULL, 0x8B30D54C8BEB3C24ULL, 0x5537B1FFB42B3B32ULL, 0xF03EF086743BD30DULL, 
            0x1BAD6EDDB5050EBCULL, 0xD35E5D66C06BECC8ULL, 0xCB90879AACCD23AAULL, 0x150FFE43A149E99EULL, 
            0xE27B745E7FEE1073ULL, 0x64EAFD1978D816EDULL, 0x3D2A422AE4854473ULL, 0xE068A04D1F2EC9B3ULL, 
            0xAB5722ED99D871EDULL, 0x3FA34C11A588540AULL, 0x20B77D58110486A1ULL, 0xB692115A857816B3ULL
        },
        {
            0x7577CF5CF2A4C6BDULL, 0xE306A341176FA186ULL, 0xF952A3A4AABDF7A1ULL, 0x041CA97033998BF7ULL, 
            0x833382CA17A45F89ULL, 0x053E057D49A8F842ULL, 0x999D4AFA0B1BC222ULL, 0x97363B2306D543B9ULL, 
            0x5B9623AD924FDD70ULL, 0x142AED037F4D9241ULL, 0x7D170946700C3686ULL, 0x64962DDE8E64ADCCULL, 
            0x3AC5DC0F9C13096AULL, 0xF6832FCB2BFB551FULL, 0x1193C4C0171E5443ULL, 0xC393692B4B0C4FB1ULL, 
            0x4B0C2107A6C5968CULL, 0xA020235E064D1327ULL, 0x139FBB5AE58DB2D9ULL, 0xC29D16C05B94BFBAULL, 
            0x47F759A6F38400B9ULL, 0xC553D3D531E7D259ULL, 0xE386BEF41525AD56ULL, 0x642D8418AF576488ULL, 
            0xAAA81995D53977A8ULL, 0xF3318EB7F06AE26AULL, 0xD69653FB06DC0CAFULL, 0xFB242F3C14D7F065ULL, 
            0x8372F91DE2421FF5ULL, 0x4FD9959846F583E4ULL, 0x87DA660AEC8A2288ULL, 0x12A67746346D05D2ULL
        },
        {
            0x0D0756BB7F29D3E0ULL, 0x8D156419822BED2DULL, 0xC47F154CA3DCC881ULL, 0x0091E1A4080AD145ULL, 
            0x0B1F3919422B7745ULL, 0x91D8BDE0FBD76DC4ULL, 0x505D20955C5BE353ULL, 0x7C2402D7EC6A1DD6ULL, 
            0x83BAC08ECC6D3DBFULL, 0x1E16EE4D6E40A794ULL, 0x22A005643EF202C3ULL, 0xD2DE2CACCAA47508ULL, 
            0xA2E30E69766FBC86ULL, 0x206262F217385D33ULL, 0xD0C55F2A1188574BULL, 0x183A0440E69107A0ULL, 
            0x243E286F9C37511CULL, 0x7A3BCC22260DCB69ULL, 0x1E0ABE36FE56073DULL, 0xC9F054600426CCEDULL, 
            0xBCB77C5CC054F761ULL, 0xFC0F7A8D2B5A2995ULL, 0x75C46F3E3F9DB3D0ULL, 0xE606C05F3C153205ULL, 
            0x80AC3A1330B95BB3ULL, 0xD8298E38A13C0355ULL, 0xB4B0FF7A3032F6F8ULL, 0x9256B1B21FBFD16BULL, 
            0x12A8902D2D86B51BULL, 0x99B1991FB0C45735ULL, 0x4F8D17930CE7C6E6ULL, 0xE1760292BF61EACBULL
        },
        {
            0x918F50DBE6FE3139ULL, 0x9009957A56575F46ULL, 0x032DBCD4CCECBE7EULL, 0xFF8C4245A235FAF7ULL, 
            0x58C34CDE9F18D2A4ULL, 0xF9D5A79E0FD50814ULL, 0x4B9ECEADC96C3A2BULL, 0xA23D542A4796A6E9ULL, 
            0xC355C7CFA22911B7ULL, 0x37F86D4A7FC020E7ULL, 0x4BE05B6CE054107FULL, 0x59CE70D706324072ULL, 
            0xA0D758A305C740F6ULL, 0x582472C8F38909E3ULL, 0xC1A0DCDE625667F2ULL, 0x3FD9DF6148380E93ULL, 
            0x40EF7E4FDD609174ULL, 0xEB9C2F2E981C0916ULL, 0xECF45CEA5932F3D4ULL, 0x9994CE9A1FDEA1C4ULL, 
            0x901B140F2946420EULL, 0x73F90DD5180C6095ULL, 0x5AA1CEFF8AD1BF16ULL, 0xCB359066EF3514BCULL, 
            0xC855B7B1B92C5064ULL, 0x52E5736DC60B8417ULL, 0x7E8F7DD807943D21ULL, 0xCEA14B590648646AULL, 
            0xA77765040C0CD875ULL, 0x95800B032035E319ULL, 0x0D9C51CEF3DC371EULL, 0xC01EF4D7618A4D53ULL
        }
    },
    {
        {
            0xBD24D4D921208AA9ULL, 0x9A18EB3989EBDC61ULL, 0x7C7C6E9FC914F975ULL, 0x4AE31AEF19FE2279ULL, 
            0x691A542D9F79DA19ULL, 0xA4B12C2AF9E7BEF7ULL, 0xF422DEE8A8479554ULL, 0x026E0E9FA82DB34EULL, 
            0x9182B0F74AF2E93EULL, 0x0CDB188BB8216077ULL, 0xEF3CE9AFB6B8F440ULL, 0xDD7ABE4825FA6B13ULL, 
            0x52749DD09DFBF9F3ULL, 0x2618178C5AE44FD6ULL, 0xBB8697E5E3850247ULL, 0xAF84076A7035B5EBULL, 
            0xF4459A056E3D89A5ULL, 0xAD50458FBAB2D002ULL, 0xF68AE7D00B0EC11BULL, 0x5FFCFF82186A1068ULL, 
            0x9F6ED3AD18D5AF70ULL, 0xB8FC764E3C1EB268ULL, 0x4B98DBCF16978148ULL, 0x6C4AC5371D91CEB4ULL, 
            0xB6E2382296727EB6ULL, 0x292C3277596E64ECULL, 0x1CD499E050884524ULL, 0xC00A8C5F3455BF4DULL, 
            0xC110375AC0B522B6ULL, 0x0FAB79B3ABA5C3D7ULL, 0x37DBE141EF05DC3EULL, 0x2992F2199C4D19F8ULL
        },
        {
            0xF30B7F2DCF278585ULL, 0x9E7C8A0E21F02086ULL, 0x21790C6622FD8FF1ULL, 0x39853295736C9A33ULL, 
            0xF220A1A960A61FDDULL, 0xEB2CBCB26DF3AA30ULL, 0x60EFE397836FCFC5ULL, 0x5B453258CB8117D3ULL, 
            0x93A98F368A6E82D9ULL, 0x3E1D8F33C3D2CE5AULL, 0x91B8252E1FD829D2ULL, 0x7B0B8DA0B7E417C3ULL, 
            0x55237964FB61D50BULL, 0x18FA1EEBE267CE4FULL, 0xEE815BF909061C29ULL, 0x53A7C041DE81BF99ULL, 
            0x241C2305491F46B1ULL, 0x62B71F410FA7BDC7ULL, 0xAC91F098B229F81DULL, 0x5224804E14549690ULL, 
            0x0410DF4E26BF713BULL, 0xF2B920E3859FC581ULL, 0x85BABF8E9F01D316ULL, 0x190FAB0DD161718AULL, 
            0x457FAEFEDCA0D529ULL, 0x0A0A2D7EE0E6374BULL, 0xACDF172FAB0F2645ULL, 0x5385C7753C5FC886ULL, 
            0xCB9AB3BB8A6ABEA3ULL, 0x03FA513F96057375ULL, 0x7A4E874BE69259FDULL, 0xBCE8B489EF9EE265ULL
        },
        {
            0x4C984ED91C68526AULL, 0xB1D31D58DCD8B1F9ULL, 0x640BBC30DE5C71F0ULL, 0x9BE8A15327AB76DBULL, 
            0x5726FD46D4B08DA6ULL, 0xA59F1AFE6C93FF75ULL, 0x7EA3C08928CFDF21ULL, 0xC5CBB9CA022CF51BULL, 
            0x36E991901B66DDCDULL, 0xBEAF1FFD1DCB3075ULL, 0xE0AD54A676BAE718ULL, 0xAB03739FA7548EC5ULL, 
            0x9F3BAECA741F2456ULL, 0x7A498BA1000D72FEULL, 0xCA9D50750791778AULL, 0x3A77F048904AFE20ULL, 
            0x7F493BDA77957681ULL, 0xB1126A9095455A01ULL, 0x476E5A30A26BF05EULL, 0x0AE444016A581E57ULL, 
            0x9938453F8B3725CAULL, 0x657C3AFB971CF1AEULL, 0x9CCE5068C6AC029FULL, 0xF2E7B4E5B7187BB2ULL, 
            0x05BB12ED2250A641ULL, 0xDE5C424D7F4408BBULL, 0x503AD6ED5DDEFE22ULL, 0xD119B03C161C2670ULL, 
            0x1FBE9F64F1986E15ULL, 0x7380878329237984ULL, 0x87AE1E73434AA9F7ULL, 0xC0A7530C95233C62ULL
        },
        {
            0x031ED1634A6304A7ULL, 0x84DABC5B1C2AB2AFULL, 0xF5D0EE5C88A9FAEAULL, 0xAF084BB02418C515ULL, 
            0xA761F981184242EEULL, 0x84B421A3BFEE6238ULL, 0x65C06290BCB23834ULL, 0xD27CF701704AC491ULL, 
            0x0E38DBAD0B9626A4ULL, 0xDCE8DFE62617122BULL, 0xA56AC0FC668DD123ULL, 0x6628E107B14CB602ULL, 
            0x9A961CB1D6EA5AE7ULL, 0xFEBF8014ECC183EBULL, 0xCE8DE0AEA374D90FULL, 0x15B2C4C20167B906ULL, 
            0x4E18431D2B7691C4ULL, 0xCE4FDA8EF8F495B3ULL, 0xBBC2E69E824E09C6ULL, 0x04235EE1B5F1B99CULL, 
            0xDB0B9C1C67DEE0D2ULL, 0xC9F597D22DAF48CFULL, 0x76244FD0132A90FDULL, 0x8F988AEA6A14B135ULL, 
            0x6129EDEB81477077ULL, 0x5724BDF72A7B77A0ULL, 0x096845454508E280ULL, 0x034BB4093077A89FULL, 
            0x9695CA87D79F746FULL, 0x754156A0DE097463ULL, 0xA2DB932B0C7A7D92ULL, 0x905F8CBE6C8EC7DBULL
        },
        {
            0x9E18D6CBE256D303ULL, 0x5DEA6558F10E96D9ULL, 0x9F630B128FE98399ULL, 0xFD212AEDDD869939ULL, 
            0x8AD8997AB42E2294ULL, 0x036815441B31EA3DULL, 0xC7BD59E69F166E4DULL, 0x7A51909DE1A9FD1DULL, 
            0xD68308C4AD48AB06ULL, 0x6E77C92C24A6966EULL, 0x2A2688366EC3C425ULL, 0x502E01F2EE5D78A9ULL, 
            0xD935F131F77018BFULL, 0xAECAE1D61EAF025BULL, 0xDFFE7AAD628288BFULL, 0x6267C5AACBF633D1ULL, 
            0xDB8F5A13CAF02B2FULL, 0xD1F5FE5619A0F7E1ULL, 0x24AB6A19E20C8144ULL, 0xAD42E7F91CF29BA1ULL, 
            0xC2661B7FE8B294F9ULL, 0xBD10C1530EF996D0ULL, 0x132F9523C6E7F4C0ULL, 0x3F9B53E005883464ULL, 
            0xD71F73D8D3C00165ULL, 0x0FD97C758E158CD7ULL, 0x3EC1893BE462950CULL, 0x1CAB51BB7312B9DAULL, 
            0x183CBD9230950B4CULL, 0x0EBF3912E05A78C1ULL, 0x6FAA89619BBF5B8CULL, 0xBCF552E57A954B72ULL
        },
        {
            0x3D7FF5EC489D032EULL, 0x8AD2FAEBC55E054FULL, 0xDE8058A62348FF8CULL, 0xB17CF982883ADACAULL, 
            0x39ED9702CB03DF2BULL, 0xDA11F241265A16C5ULL, 0xDCEAC4F775DC0B58ULL, 0xB3551760F10C9361ULL, 
            0x2F31A0D1BB0B7B39ULL, 0xC5B25CE0DFFDAE92ULL, 0xFBF84A85879A2064ULL, 0xF26D92B73AA5CFEDULL, 
            0xAA36725CE8178416ULL, 0x1BE79F2190B0D931ULL, 0xA570F9A86F69F9D4ULL, 0xE397432C7C6A2075ULL, 
            0x49AFBD5A08A8021FULL, 0x61449EE3AD67FBDFULL, 0x8A8769FD7AC5FAB1ULL, 0x56570508D2884340ULL, 
            0xB98649727FE45CFEULL, 0x8327FA3BD72A1C0CULL, 0x0699406169210958ULL, 0x9C838D1721F0449FULL, 
            0xADB234C2E8725CCEULL, 0xC60DD632A3B8DA5CULL, 0xA5220969D13874EFULL, 0xA8B105C1EE19C205ULL, 
            0x182BBED69499C3EDULL, 0x051809F3F1150F68ULL, 0x1804AB60074C8307ULL, 0xC7635A438DC75665ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseFConstants = {
    0x7A2849F33D565143ULL,
    0xE74188075DCE2A71ULL,
    0x5C632DDFA661EC6AULL,
    0x7A2849F33D565143ULL,
    0xE74188075DCE2A71ULL,
    0x5C632DDFA661EC6AULL,
    0xB28ACEEA1D9E5940ULL,
    0x0127184C035BBB10ULL,
    0x6B,
    0x2A,
    0x0D,
    0x37,
    0x2F,
    0x7E,
    0x22,
    0xAB
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseGSalts = {
    {
        {
            0xFC57E72FBB6B7A46ULL, 0xBCD18DEB71806FE3ULL, 0xB64F4CB9E31703EBULL, 0x40ED64016453173EULL, 
            0xBB523294C9EA7854ULL, 0xA2E82E1617417D38ULL, 0xC66A13372DE24DB4ULL, 0xB1AC5552468D17DDULL, 
            0x46E19ADAAE73AE38ULL, 0x409684E332E44886ULL, 0x24F34F7BF3701DEFULL, 0xDC4B2256206B58DEULL, 
            0x7632DBA413494256ULL, 0xCF3C6C3675FA192DULL, 0xFAA41B89E471E141ULL, 0x1A38D2263EBDBB90ULL, 
            0x9AFF89CB8CA202CAULL, 0x377F6BFC048C5715ULL, 0xADBBDA4B93694534ULL, 0x585619688ACB3E27ULL, 
            0xB121C9EBCC1F400AULL, 0x372562947AD050BFULL, 0x568B9F46FBC36E36ULL, 0x871529A732371386ULL, 
            0xEF8D5062F9DE4BB8ULL, 0x618279CDBAD7A765ULL, 0x89752AAA7A92E937ULL, 0xD051B0D72AC4A2E7ULL, 
            0x5455BA15050868C9ULL, 0xC2B14A99A908A5DEULL, 0x55C08AB18DF479B3ULL, 0xCA42CD2B6FF44684ULL
        },
        {
            0x2CDD5C6A7C986BE6ULL, 0x8BA7EABF0615CC07ULL, 0xC09CEDA12342C9A4ULL, 0x4E32491F7EEE97C8ULL, 
            0x99656378AC023783ULL, 0xAFEE17DA352B0B57ULL, 0xF5620BFB38FCF106ULL, 0x8AC3F8D91CC91A10ULL, 
            0xCAA21E5BA4C18BDDULL, 0x6FB6F6DD707BF63BULL, 0x495C34FB80354F26ULL, 0x4EDE83F2F6D99EDEULL, 
            0x4859D151237E6322ULL, 0x977D1C50AC98D9F6ULL, 0xC05037E36C4106E2ULL, 0xE91EE8EF6DD8C3E4ULL, 
            0xB08FCA19FFA8A255ULL, 0x37B7FF13C0D9D5EEULL, 0x8888671E40B52D2DULL, 0x0A74E3E9C0A78DC2ULL, 
            0xA75BBC28A5E1E957ULL, 0x1BD391FC82190F64ULL, 0x34A0E44618D793B0ULL, 0x53D9FA6044828565ULL, 
            0xB5442B0F4249014BULL, 0x409F2AB57561BC93ULL, 0x9703B54755921399ULL, 0x84836FD08B6F35C4ULL, 
            0xB0FFC306CE7A3C58ULL, 0xAAAD9C67C15E82FFULL, 0xF4CA657CC11D91FCULL, 0xD26C44212A4C9E83ULL
        },
        {
            0xF1DD7D7049D770B2ULL, 0xF8CEAC3CE812A3CEULL, 0x3CCB399BE08BB979ULL, 0x62D1E14B8C514780ULL, 
            0x867C3B6B6708B07DULL, 0x15D8C2D149C6244CULL, 0x9B251DF53849EF33ULL, 0xA2F98E6F6D76A474ULL, 
            0xB48CA82DA1CEAB2CULL, 0x13A7E1ECBC397C78ULL, 0xEAE4DDCD7DE33F55ULL, 0xC0DE829CFB335D65ULL, 
            0x395A27E4ADFBC750ULL, 0xA69F3FDD2D1046D8ULL, 0x3E0A44E3BF8402DEULL, 0x90F303C4E7E3DA4FULL, 
            0x68BEAAC6A707DA33ULL, 0x81F14C802AFF9D2DULL, 0x8C2557D81F58F76AULL, 0x85DDA32437A8B4C8ULL, 
            0x39E5DAADBABA67D4ULL, 0x3F79C8063F1B2AE4ULL, 0xCAE78FEDE2D2E720ULL, 0x952A2B0A0784A10DULL, 
            0x8226FD18F962C092ULL, 0xC2BF36672538A0B1ULL, 0x9C903737FF1D3F93ULL, 0xFF3452DD2090A28BULL, 
            0xF5839B8841A87DE2ULL, 0x942F08DF43F0CCCCULL, 0x59F4F1AB0DA4C0F9ULL, 0x719E262D6A2301F0ULL
        },
        {
            0xA38F4CB0CE02DD97ULL, 0x5524017851A0C7A0ULL, 0xA43E26832CC1DA00ULL, 0xB06A7DD2F4344110ULL, 
            0xF1F4FAA774261802ULL, 0x2ADBC4CC881FB991ULL, 0x82ECDD39A8B48003ULL, 0x1CA5FB828B664DA6ULL, 
            0x5E3791E73A8B8B91ULL, 0x54B0A2F3654B39BEULL, 0xB8D019EE2CAFDB47ULL, 0xD6FCDD9BBF53067CULL, 
            0x9D9B4041BCCC7DFFULL, 0x3F22AF53E40B7C57ULL, 0xC6467070E472CB34ULL, 0x8FC972AD9D7CF550ULL, 
            0x6DB9984697BC2E8FULL, 0xB3757AB6CB7D67AEULL, 0x46CEDCE2ECB6BB4EULL, 0xAAF5949D03ECD09EULL, 
            0x841A433DC9AAF2F0ULL, 0x6B62D95480D77C27ULL, 0x478D482D17E63DF6ULL, 0xB075BFB91980CA04ULL, 
            0x114EAD0659F070B3ULL, 0xDFEECB38C3106B22ULL, 0xCF4E67D0663C1438ULL, 0x3352808DF9575220ULL, 
            0x83428A4CD52AE3E7ULL, 0xC56EA0F3D40B0FA0ULL, 0x1B1983D3772AEB80ULL, 0x5CFC41A182774494ULL
        },
        {
            0x642CEEE4845BEB58ULL, 0x013B2FAF60F2C7E1ULL, 0x67C67F71E222CF25ULL, 0xC70BF57CAEC35D6AULL, 
            0x3DE9D0FCD02C22EFULL, 0x5243D0034613EF55ULL, 0x0CA4B91BA88C87FCULL, 0x189FADFBBCFC0303ULL, 
            0x4390900B0A523211ULL, 0x23BDD7DA21C885D4ULL, 0xD1BA469DF472C980ULL, 0x7C0BE017DA827E4CULL, 
            0x0F6D76D585CFFF82ULL, 0xF5FC036BA366DDFEULL, 0xB0D26F212285C6B6ULL, 0x11C2E60E41957CAFULL, 
            0xE4EF33036A7396F9ULL, 0xCD66A3C3F3161538ULL, 0xDC6AA319C638513AULL, 0x900ADF8F2165320FULL, 
            0xC9D4B6A15FDD4C53ULL, 0xE7F01C802A797DBDULL, 0x1CBF61E7C18B6690ULL, 0xDF823E0646FF506EULL, 
            0x760783B11FCA3AC6ULL, 0xC3FECEE33B33CFDFULL, 0x149A495D5206E07BULL, 0x725AA3DC969EC828ULL, 
            0x5D5FAAB523AC1557ULL, 0x4C37D71E77D3E389ULL, 0x91A60B191532B7A6ULL, 0xBEE7A6BBAFC3033AULL
        },
        {
            0x61983A84791177E5ULL, 0x27835C9B1AE2EC64ULL, 0x733E4485AA0D9B22ULL, 0xAA0A02F8F1706069ULL, 
            0xEDFEC28D122E3E96ULL, 0x879A760351A615E6ULL, 0x9A5D0CEA35DA8AEBULL, 0x386A8FD7F4EC86B1ULL, 
            0x4E178CF0FF111341ULL, 0xFF94C5BE69170E73ULL, 0xE7D00327B18E4C88ULL, 0xDCD9AD4C99A084F0ULL, 
            0x4C5B06A725152E2EULL, 0x74A9AF033FC92741ULL, 0x951258EDE85B7418ULL, 0x916B25FB61D42A1BULL, 
            0x4EA9F24270E32988ULL, 0x3A6C293CF480D00FULL, 0xF17987F17A1438C9ULL, 0xA08F0E0B44B6874EULL, 
            0x5E656F1F5FC20D40ULL, 0x7DFE1A6BBFCBFD3BULL, 0x7824741CEE675E3FULL, 0x9A8C9DF048D30DA5ULL, 
            0xAD7905D358777714ULL, 0xEE7F774DCF58DBBCULL, 0x33B8D17AA25FE636ULL, 0xDA10409536E91328ULL, 
            0x424E17EB40D70CFDULL, 0xA8465874EE9CEB2FULL, 0xB4E3416BCBF2441CULL, 0x0AFA9FFBF91C8D56ULL
        }
    },
    {
        {
            0x7C93D23A4C958E3FULL, 0xB6BEF4C6F08A249DULL, 0xC4890A111D8A3386ULL, 0x4FC350D49000696DULL, 
            0x270A4C48CB3454B4ULL, 0x96AB98C0CB6922A5ULL, 0x653B235F64C5A350ULL, 0x7F13FD2BAE7B9220ULL, 
            0xFE66866ADEA0262FULL, 0x5E93CDA61B74D7EAULL, 0x95890AB3FDA5DAB1ULL, 0xD3F0F2EE64483E90ULL, 
            0xBDA4D422D8959471ULL, 0x114BE290A3B8F8A9ULL, 0x64C55E4C2759A7A0ULL, 0x52C91CA2308297D2ULL, 
            0x5DA1322494C98F5DULL, 0x89187E9E3AA4BF6FULL, 0x27BD14A41FDE5BE4ULL, 0x613BC2D3C38446CDULL, 
            0xD1DAA24B9E59535BULL, 0x0D09AF467092DE00ULL, 0x07B297027D8B8A68ULL, 0x97C707356489263FULL, 
            0x5D9E33225F4864CEULL, 0xC090AF639DAB5B47ULL, 0xF5F117093C3368E3ULL, 0x9D231B6BA82F24F5ULL, 
            0xA15E83153DED006EULL, 0x0BE622EE84BB8B24ULL, 0xAD23AC0D2ED0E24BULL, 0xC8248BF2DA3199DCULL
        },
        {
            0x88F8226A0BB12DFDULL, 0x1327C99F7CC8CA58ULL, 0x16ABE1C2A601FFF6ULL, 0xA8BCE69738170E83ULL, 
            0x36E11162909A8906ULL, 0x1077F96341033EF5ULL, 0x330C35DBFC313B34ULL, 0x5279F53882C21C68ULL, 
            0x3982C482356868DCULL, 0x45563D922368E007ULL, 0xB9D2D0BAD9F313FEULL, 0x8A5E22D26AC37FB4ULL, 
            0x2F048507B9156E66ULL, 0xA89B0E4AF8973887ULL, 0xCBA399750C39CBCBULL, 0x38130A714B487E35ULL, 
            0x7605244F5BD1290BULL, 0xE5F1BC07F758204DULL, 0x1EE9F3667F0A1FE4ULL, 0xA88B0594F63A5098ULL, 
            0xEC740D92D90BF0F2ULL, 0xFA9BE9574DC66047ULL, 0xF01A4F5AA449EDC8ULL, 0x1AC49B41AF86D531ULL, 
            0xCAD8008526B25D3DULL, 0xBED4C1DE4CBB8A57ULL, 0x97FBC2A8725B6A19ULL, 0xFDF0CFDE59370481ULL, 
            0xAEA2612B6CF3DEDAULL, 0x060F2D306A28AF29ULL, 0xFEC012A028CD4FF3ULL, 0x43958865D929418CULL
        },
        {
            0x5225C88E47921FD0ULL, 0x41E93465420E1A84ULL, 0xBD460ABFFB286062ULL, 0xAE4C02F3EE7A3175ULL, 
            0x65710B229E86E154ULL, 0xA04B7C546F9135FDULL, 0xBEDA09A79BD43A3CULL, 0x7463649A9932A042ULL, 
            0xAFE62B6137D9F1ABULL, 0xA00E80DDBFF20C27ULL, 0x61F1C088A7A217ECULL, 0xF691248EAAC1E9B9ULL, 
            0x9023894374D93DABULL, 0x364B008289458A22ULL, 0xD6D0852F56DE23EBULL, 0xD54F04B1CD5A2F2FULL, 
            0xA04B062E32401083ULL, 0xE3A9DA2F91CC2D4CULL, 0x94CBFBD819DB7877ULL, 0xE7CCA098922F53E9ULL, 
            0x5B13D6B1A20C07E8ULL, 0x84B728BB96A677F3ULL, 0xCDF1D481DD5275B2ULL, 0xCA081F6EA63FB025ULL, 
            0x70670F4C90AEF9C7ULL, 0x0E32FC1A794285E5ULL, 0xA2CC607596FCA244ULL, 0xD21637EBCFCF3D57ULL, 
            0x716B05681CC9A43AULL, 0xC8FDE6118117FA4CULL, 0x9CBBC64C3FB94E9AULL, 0x6500C318E1F80EA3ULL
        },
        {
            0x59EC723A071E8C46ULL, 0x03097C7386A1E384ULL, 0x934BFE2DBB7DFE7CULL, 0x7409108E48349DB3ULL, 
            0x5A62A9D9BA92CE97ULL, 0x89D408ACC11882DEULL, 0xE128FB451CC7B2BFULL, 0x3730A83176734204ULL, 
            0x8F2B949304B54ABDULL, 0x2D45EB32B1B9CFDDULL, 0x3D82F01DC9E78F9FULL, 0x94EF270E9039FAB8ULL, 
            0x17C323828167578CULL, 0x3C38D6355237BE6CULL, 0x16A02920DA805018ULL, 0x042582C2FC7D55FAULL, 
            0x2A7BD975973E2248ULL, 0x7B464760078CB7EAULL, 0x15192CEAE3EC6752ULL, 0x9729BA8EBBB1E2B7ULL, 
            0x060AA3650C570722ULL, 0xCC62F5B5DCDBEE0BULL, 0xBEF37B9C569CA6A4ULL, 0x271433F31D723204ULL, 
            0x66D58471D8451FCAULL, 0x1B58AFB59EBEFF80ULL, 0xDCE4BEE254C39C1FULL, 0x48B92290C70B803CULL, 
            0x216D3618E0BA3B72ULL, 0x2367FF518C60E974ULL, 0xD55AEE8E74B4AB46ULL, 0xE1A6FDE191B6480BULL
        },
        {
            0x7C965F464DFF4F6AULL, 0x2019C6EA28421DE4ULL, 0x361CC1AA22EFBDD8ULL, 0x44F93267794A36CFULL, 
            0xE70C73349BE53DE5ULL, 0x6879689641817D0BULL, 0x1A38D92CFB6CE9A3ULL, 0x9A28CC3FC87A9B85ULL, 
            0x2D779505E0E5CC99ULL, 0x48DEE97DCC5D29CCULL, 0x5ECD661281BAAC51ULL, 0xD84257B9B5778856ULL, 
            0xF99578FBC0CCB283ULL, 0x380FAFEC42996C76ULL, 0x92D1FBD3C457845FULL, 0xC0DF068399FD3965ULL, 
            0x4F4E799BA99781FFULL, 0x7DE224A0588BBA05ULL, 0x821F6333FBE3102EULL, 0x3C6B6EB8B1222F41ULL, 
            0x1A467BE33F57FDACULL, 0x1C437331B5C4188BULL, 0xBEFF44C10BE582AFULL, 0x2C240AA2A5BD7F7EULL, 
            0x43505C236CB5AB5CULL, 0x23CE425F7B1DC6C0ULL, 0xDFBE5734DC1C9B30ULL, 0xAC9A265948B201B7ULL, 
            0x438CB52EA98AB872ULL, 0xD35B8761F710ACD6ULL, 0xA6042258335495A1ULL, 0x2B8D85340A48127AULL
        },
        {
            0x1CF69F452C99739BULL, 0x5AE781A45CFB0583ULL, 0xEAE806193E483C10ULL, 0xCBD6FEDDEE139691ULL, 
            0x73040EA23BA99816ULL, 0xE128175BD4426AB9ULL, 0xB10E62F74E9DDB20ULL, 0x1C693DCB819E3DDDULL, 
            0x214E00861091D2A7ULL, 0x4282EC99F828AC8DULL, 0x95413422C4245E91ULL, 0x4D24136D4868ECF7ULL, 
            0x850E33139F38BEC1ULL, 0x087A5BA7AA729E24ULL, 0x043C93A6033BC05AULL, 0xD3DF814AA7E45F82ULL, 
            0xCDBDFAE120144425ULL, 0x88DDEAB9D60EAEBBULL, 0x5CE02A186B15AD48ULL, 0x0AC8F810C75CB73EULL, 
            0xB930DDDC40916801ULL, 0xB3EF953448BB8247ULL, 0xEC83EEB008A03E1CULL, 0xB0CC77994E6DBC65ULL, 
            0xC37021C31ACB5A3BULL, 0x91494A57C750F5ABULL, 0x48D3CF3382149FA9ULL, 0x9A55778BD86E9F10ULL, 
            0xDA71A9F6DA1A22A1ULL, 0x52A1735A5D1747D8ULL, 0x0B3E8BB111BEC482ULL, 0xEDED7CBB5D0E6D1DULL
        }
    },
    {
        {
            0xD0FAB1903277F215ULL, 0xB2975AF631380649ULL, 0xCFAA266C51C2CE1FULL, 0x10C3210AA7DE4024ULL, 
            0x564CA77D55E7386DULL, 0xE83B8C72E7900FC2ULL, 0x8B166EF7E73EBD16ULL, 0x4C639167A35F8858ULL, 
            0x2A0CFF1352F65552ULL, 0xF00770F9F292D08DULL, 0x9698C9271694FDE4ULL, 0x4DE2A2468945937DULL, 
            0xD2F1B244C24C1724ULL, 0xF5C749418782609BULL, 0x88FB342ED042B757ULL, 0x18AC42AC7E712F7DULL, 
            0x5D4756CEE76DF4FFULL, 0x5B3388926D93DD1BULL, 0xD292132FC84A1277ULL, 0xBAD85826A53214F9ULL, 
            0xF854FFB33242AB88ULL, 0x58CF503F6F056D89ULL, 0x9869E72E3988DAADULL, 0x75B818D9C832715BULL, 
            0x4961CFAE2B2EBEF7ULL, 0x9A732FD353F72F00ULL, 0x5DEA35E5F6FFBCD2ULL, 0xF38DCD612380E112ULL, 
            0xCA48887F3ACE0447ULL, 0x70540CEBC5DBECA0ULL, 0x4C1E1A7C1B0D81C7ULL, 0xF1CA2D9C3B14E56FULL
        },
        {
            0xD3063490EDA94036ULL, 0xA07F3AE1AA44BFC1ULL, 0x7F9063BA5C15C902ULL, 0x75ECEDA894317A0CULL, 
            0x4342B2D2059A0C24ULL, 0x98D084E24851D70DULL, 0xD545606CCC0B6790ULL, 0x6CF2F78FA60A6C2AULL, 
            0xA43927ADA5A69A43ULL, 0x310F8850DCDD37E6ULL, 0x205EB826075AC360ULL, 0x90A9FABE04B3AE87ULL, 
            0x084EF51B84CDD881ULL, 0x4C447666057383C7ULL, 0xB60276C8CCE94B52ULL, 0x3A86168C8817F20DULL, 
            0x1231C5159667BA75ULL, 0x3E5D6BF11687A540ULL, 0xAACC29A3B871C858ULL, 0x066FBAD5C4A47664ULL, 
            0x62026D752E21F450ULL, 0x84C8C38BCB7431FAULL, 0xB4C30AAA87E48944ULL, 0xB58FF1F1ADB76C49ULL, 
            0x02D3E72430AB12C6ULL, 0x5FFCEBA09620B326ULL, 0x47D6ACDBEA5B6A10ULL, 0x77D3896D34DEE76FULL, 
            0xA40E9C1BBA918BEDULL, 0xFBC29734B5DA26FEULL, 0x38EB529D108E7983ULL, 0x86C0395D3518C415ULL
        },
        {
            0x44DE2DDD8D9F6961ULL, 0xC4FFB1465EF634D7ULL, 0x40ADECDA7CE3EEA9ULL, 0x25E8D6265E5F6974ULL, 
            0x576EA79B08504CEDULL, 0xCEBA65E478720024ULL, 0x2187B2B162F4181AULL, 0x8572C7ECE2ACA2C5ULL, 
            0xA8290F754BB412D0ULL, 0x986188BC6E013963ULL, 0xACFDEC29B16E4831ULL, 0x9CA7CAA75344EECDULL, 
            0x373A520827F6244FULL, 0x966E79B1A5982B73ULL, 0x81454B9862DD0BA8ULL, 0x51EA13A495218289ULL, 
            0x1C4B1E6E8B67E7D2ULL, 0xE6AD2DF2CE87F31CULL, 0xBAB445C580A3ED17ULL, 0xF1955BC84C30C9D4ULL, 
            0x5B8DC6FDAC8BB132ULL, 0x5328E048BA7AEF97ULL, 0x333ACC82BCCE6DA1ULL, 0x78019E0EFF723261ULL, 
            0xD9E7295192F9D1A1ULL, 0xE521CE064406EF89ULL, 0x1B8B73D79884D07FULL, 0x4511B95E53CE690EULL, 
            0x43C6341412F496E6ULL, 0x4DAB3A1E02A70EB7ULL, 0x7337B6FAB7414F6EULL, 0x1F8A5A840ED765D6ULL
        },
        {
            0x08BC28683B8C509FULL, 0xAAE17691CE539338ULL, 0xAC73365854D77212ULL, 0xE112B5E2FCAB3852ULL, 
            0x7BA1E46DAEE8EE1CULL, 0x67A936A28D604F66ULL, 0x8A1007C96CBE27A6ULL, 0x067221FD623C4D27ULL, 
            0x4E1B97A466ABE59FULL, 0x724333717563E407ULL, 0x52E841571D2A336CULL, 0x7493B26714FBAEA6ULL, 
            0x8E701B32D5B4D1C4ULL, 0x090C675B38BC60D0ULL, 0x8A22F35B7A33FB8FULL, 0x3383D488FFEE93FFULL, 
            0xDA2B72DEF07700B2ULL, 0x7EFDA95E0074160BULL, 0xA3E1B2F8697C5C2DULL, 0x33190ED108D506B3ULL, 
            0x2FD8AF3642644E55ULL, 0x0F96F5A7F4502AAFULL, 0x5FB1DF38F3EEFFF6ULL, 0xEFB84F7027F90641ULL, 
            0xE3C320614BB32E95ULL, 0x5E82ED04E370BFDFULL, 0xAD89FF2D2B4C516DULL, 0xC2A28CB74CAB4843ULL, 
            0xD618624B28C7493DULL, 0xBD40B5D9AAB66059ULL, 0x8EF032D5AA3684FFULL, 0xD8AE50C76AB74B53ULL
        },
        {
            0x62D97B3269D56DD7ULL, 0x9A8250776B7EF3CBULL, 0x79286E800917D89EULL, 0x81986AEB8D5605B7ULL, 
            0xF30A89168A14C569ULL, 0x2D7361862B602185ULL, 0x3D0525C559DFB595ULL, 0xD5FAFBBF114E39CEULL, 
            0x54AD775D182743B3ULL, 0x4A7A5CB53F552915ULL, 0x6058B1EE51DEF47CULL, 0x6D63D58948AA0A07ULL, 
            0x8DFF5616D61C2101ULL, 0xDCBAA6C8894755B7ULL, 0x74E4A1EECC5D86AEULL, 0xDF2C364B479C9D4DULL, 
            0xB073A1856B7990B8ULL, 0x1271BA8513067BA1ULL, 0x9DC006DB893A4D75ULL, 0x7EF4F40080ED4171ULL, 
            0xF262F6D39017366CULL, 0x4DCA3668FFEC07C8ULL, 0xF9FA895B9B0A1604ULL, 0xD4B98DD39113C269ULL, 
            0x1ED4271F3122EEC8ULL, 0x1DBEB30A926E668FULL, 0x83D21F9BB350797DULL, 0xE593D81252E9D1C8ULL, 
            0x2E3F7B1FC1C951ADULL, 0x855DAFFB5656A8B6ULL, 0xC3ED55FEF786802FULL, 0x00BA4606673FC602ULL
        },
        {
            0x47B31B267B4549BCULL, 0x71576D8B0EAD45ABULL, 0x1B9B89B5CA0B9F23ULL, 0x59A47F6229A37888ULL, 
            0xEB3C985B13912A97ULL, 0x429AAC5C2CBE936AULL, 0xDEBDA8B727ABA562ULL, 0xF80903E23D4F616DULL, 
            0xB8C3C8973D7D4496ULL, 0x7218F9BB4534E213ULL, 0xC031168E7F24A3CFULL, 0xC7D25F9996B9C032ULL, 
            0x3779072936AB424DULL, 0x9675181325F7782CULL, 0x708016E602F9327DULL, 0x9815246A1A9A4084ULL, 
            0x0986BEBE4EB861C9ULL, 0xAC0843B3F37F4645ULL, 0xE341AA175944D76DULL, 0x6B31BF889901B2D1ULL, 
            0x7E929988210ACFB4ULL, 0x69EB7AE237FC7C01ULL, 0xB38D724AEB5CE8B0ULL, 0x3A99D87D55EDE39EULL, 
            0x39DFAF82CF25CE3EULL, 0xAAB1443AA5ECF289ULL, 0x15116B6AE99E97DAULL, 0x663D87F32D900D98ULL, 
            0x3EC410BCB369CBE9ULL, 0x5CBB234ADC6897ECULL, 0x3F6C2395AFC61EB8ULL, 0x2005DC9EC6F06105ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseGConstants = {
    0x92CFACCB9B4565DEULL,
    0x572662D8625012D8ULL,
    0x80FF4202167D72EFULL,
    0x92CFACCB9B4565DEULL,
    0x572662D8625012D8ULL,
    0x80FF4202167D72EFULL,
    0x16C9D42CC3CBF06EULL,
    0xAF50E27BC1D8F67EULL,
    0x57,
    0xB8,
    0xB8,
    0xBE,
    0xB2,
    0x21,
    0x8E,
    0xF9
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseHSalts = {
    {
        {
            0xC221C44359392719ULL, 0x7501A523B69817A6ULL, 0xD5DD2FB116E3DB3FULL, 0xAC1E3B9DE56C5FB2ULL, 
            0x4923602091658401ULL, 0x60F3EFC8ADA69759ULL, 0x7339F718592E478CULL, 0xCEB2D2AE579F321FULL, 
            0x12DB3560DCF2E5ECULL, 0x4B7CBABEF3D7DD74ULL, 0xE8A40BBBD2288B84ULL, 0x5F88BC93501BF9CEULL, 
            0xFCB804B16CAE60C0ULL, 0x1C4F3AEECF2250FEULL, 0xED99B83417B8F1ACULL, 0xBE7A9BAE34D95A62ULL, 
            0x9F2EA1F0BC2519A1ULL, 0x70A227F1E0E04E56ULL, 0x03B96AE8FCADFE3EULL, 0x0AF6A2A9248322DBULL, 
            0x0CC94406FDA403A4ULL, 0xED46A66BE3AC4A1CULL, 0x374B4F99BB9C15D2ULL, 0x82339C38D3540D05ULL, 
            0x53BC83F1C71011E3ULL, 0x915484586C735F71ULL, 0x831766A826A9FC8BULL, 0x86B402235E76EED5ULL, 
            0x506837ADAC42A2C1ULL, 0x136D3B6F81F0DA6DULL, 0x4F29FB1F93F5E741ULL, 0x82AD836A22249E47ULL
        },
        {
            0x4BF98BE955CB0DC2ULL, 0x5472A6E6F13234B8ULL, 0x5CDB2AF5278A38BBULL, 0xB3CD348BE99007EBULL, 
            0x15CD720438DD0AD4ULL, 0xC586A7775F33C982ULL, 0x75A490EA4B734444ULL, 0xA0B3C298DC6BDAE4ULL, 
            0x12ACF6A72B35B087ULL, 0x64821A558EF232D5ULL, 0x6454FF5B196D66F3ULL, 0xFEF4769262D264FEULL, 
            0xFEDAEB462F7EE543ULL, 0x038A1187A1B09AF7ULL, 0x5ED5135DF0A0A194ULL, 0xB7C799D211028B22ULL, 
            0xE588717D44ABFB66ULL, 0xDC1A7D2C5C3ACA5AULL, 0x1B0B68F60BC40FD4ULL, 0x49679506305CF01BULL, 
            0xA198FC17D5D29C9EULL, 0xC8CAF4B34C85F837ULL, 0xF1A623BD26496902ULL, 0xE8D3F3A424FD2D53ULL, 
            0x50E8FBFCB9B1852EULL, 0x621DE1516557779DULL, 0x8A96922E5398600FULL, 0xD16F0ECFBDCC7670ULL, 
            0xB74E78B265C9C153ULL, 0x1FF44F6330EEDBA0ULL, 0xF78DDD400896B178ULL, 0x499C6A55C2438D60ULL
        },
        {
            0x19E3701D50CC3E21ULL, 0xF69FC35674F22DC6ULL, 0x76A37D00F1D0BB3AULL, 0x69863DCED931AD99ULL, 
            0x590C0A3D5E31BDC4ULL, 0xB90CA5AE05D8D966ULL, 0xE700DA472389CF24ULL, 0xB444B2C774B9FC4AULL, 
            0xA50DF3B4FD44EC6DULL, 0x8B6DE2E68CCD5B30ULL, 0x2C22E6CD03B93F56ULL, 0x64B3E4F3A0B6FB6FULL, 
            0x983D31B340BF22C2ULL, 0x6D6A8E8343C96A4AULL, 0x93FD49C1A303D3B1ULL, 0x4D1A7E9617D0304FULL, 
            0xDAAEDC2DE44A10ADULL, 0x167327D9B70B6DE6ULL, 0x073C16A1F670AA4CULL, 0x2FFB73FA92BC89E6ULL, 
            0x6473E34281817E73ULL, 0xDB7261F4C7E79127ULL, 0x9E6D36DF81ADC73EULL, 0x22299A5FE96C57FAULL, 
            0x472D0CD6D2D5464CULL, 0x74669D04426C2AFDULL, 0x9F80759ED652D936ULL, 0xFC84F8CD7CF40CE8ULL, 
            0xDD0D5C486AA8AF82ULL, 0xD3D0FE36D917756EULL, 0xA0C0B2B7482313D3ULL, 0x12601D14F03050ACULL
        },
        {
            0xFE8B57CEC365E520ULL, 0xE39DB25E05F4A40DULL, 0x4F0CB0FDA2D81A03ULL, 0x4B2FE15FE39590B5ULL, 
            0x229849DF1B9FC99DULL, 0xB9D764860B98B130ULL, 0xB9914FAB0B7E4F30ULL, 0xA944EAB015041AD6ULL, 
            0x8D8613142B6E3291ULL, 0x76F78152BD8A2DECULL, 0xBDABEA22A69C1164ULL, 0x6D4DA520B8CE5373ULL, 
            0xF1CBE0DC34F9A829ULL, 0xC46666BD4F4A5BC8ULL, 0x23F2ABD33019F699ULL, 0x79B74F1E898E3681ULL, 
            0x7958DB0112CFFBEBULL, 0x272491B4325940A5ULL, 0xFC865A10EC4ED0CBULL, 0x1C80DCAA35C75311ULL, 
            0x90F776FCC246D4C8ULL, 0x1B30427B76F7602CULL, 0x0E01205AEF2E5E0CULL, 0x51CFBDECC905BC48ULL, 
            0xB6D4CD76C57C596CULL, 0xF379C074A7F1C842ULL, 0x20F36FE7C91ACB7DULL, 0xC9E2E90D653B3160ULL, 
            0xDD6111F72319DC73ULL, 0xB208408D99D41FC9ULL, 0xB131D46475492372ULL, 0x8912DBFE27BC536DULL
        },
        {
            0x3D6D9B2BDE4C871AULL, 0xBA952B3812D19EEAULL, 0x62F15C9E5F1F1C1EULL, 0x8CFA3D177D53F010ULL, 
            0xEB285F4DC7322AA9ULL, 0x23FBB4F0E27726C4ULL, 0xA4F50A29F9928BA9ULL, 0x53B7DC40C55665A5ULL, 
            0x99364446E6F412C1ULL, 0x1A5A741DB2E62CFCULL, 0x447F56745D8BB294ULL, 0x44309F927726BD47ULL, 
            0x9264740C8BA06B5AULL, 0xA0B5821A59DA0764ULL, 0x8EDB33EBB9EB4BDDULL, 0x8045B7FBCE924DBAULL, 
            0x60300CB9ABF0E14FULL, 0x8A096B4995929E22ULL, 0x41AC3FD451E26C52ULL, 0x152AC31FA8F973EDULL, 
            0xDC202F47F03905F4ULL, 0xDB06F5E9DB198A7BULL, 0x942C56F9DE675E46ULL, 0x1C7858EEDCACD28BULL, 
            0xABF82D948597E8AAULL, 0x992FA7FEB6B7A049ULL, 0xD7EB7FE4EB7284CAULL, 0xE839F143B1EF0B9FULL, 
            0x25B8089C3128DDA5ULL, 0xE1B8E416615670A8ULL, 0x7B1534DC09D62F82ULL, 0x365A8AD38CFB3350ULL
        },
        {
            0x434208F50A13EB85ULL, 0x7A20C8BBCD6AFC54ULL, 0xA452242581075459ULL, 0x65BE0DE73983C1BEULL, 
            0x0FA74A3978B8517DULL, 0x1925EF136D01D4D8ULL, 0xB7F96C385BF38500ULL, 0xD582554BE192CB2EULL, 
            0x2E5B6DDF14AEDC0FULL, 0x03A3201E2BEDDEADULL, 0x909AA87F7A5ADE25ULL, 0xE8934C8A1C580239ULL, 
            0x0621BCB5CE8AB977ULL, 0x85F8F4ACA2F624C8ULL, 0x4DF9810563FBB156ULL, 0x33C156D8A3898EE1ULL, 
            0x0153EA9CEA679F3CULL, 0x3CA1558222E5F3D4ULL, 0x927EB1A2C0086381ULL, 0x7F4904FCA19030B5ULL, 
            0x630F635A5781CA77ULL, 0xC479315610F5105FULL, 0xE27351AD293960D8ULL, 0xBE144D091869340FULL, 
            0x19C8B3AE6A421EFEULL, 0x714B6726C136F6F0ULL, 0x68BD7E2672B8A02FULL, 0x9B4BA110593AC8AFULL, 
            0x581D184A78402A5BULL, 0x32F5D3D90B48D64FULL, 0x93B668446ED82EACULL, 0x26259E0F99979E06ULL
        }
    },
    {
        {
            0xF131A179A3309712ULL, 0xF7A260B0E9078F24ULL, 0x4A39FB039D7CF692ULL, 0x28F4CDED2AB8FB54ULL, 
            0x05771B9834627715ULL, 0x09A3618556798A9EULL, 0x0840794C447A7C50ULL, 0x96B39B572826CBEBULL, 
            0xC3DE74CCF46509CDULL, 0xA88637062AE90CEAULL, 0x23722E8AC7B15614ULL, 0xC65060B65CFD057FULL, 
            0x36BEF53FBCDF4941ULL, 0xD957C844FC3D4B09ULL, 0xFE97A4084371B9D7ULL, 0x9C5084C9A5AB1238ULL, 
            0x1EE7FE12B0F44C0CULL, 0xEC6F2574A58008EBULL, 0x593CDB8E10A00F18ULL, 0x449A217DA9ABA117ULL, 
            0xCFDCB668BF14A07CULL, 0x2392B9A331CC0958ULL, 0xCCC100BFFF9FFB8AULL, 0x7EFF9BAD9AD6B188ULL, 
            0x9197E67028E8CA70ULL, 0x4041E39881AAA3BDULL, 0x7614D03D1926CF1FULL, 0x91D71B014D89A67DULL, 
            0x5124D9D348BFD679ULL, 0x2F5845A304B2F4B0ULL, 0xE4C715F54FDC828FULL, 0xE4D334B30A00E1DCULL
        },
        {
            0x57F7DCA38127ABE9ULL, 0xB9D09D9CE1F16ABEULL, 0x83F82CE044D9EAC6ULL, 0x73F03B1CB7BA7533ULL, 
            0x308EBDE5B8DE6A5EULL, 0x4C9BF8DDBBE273F2ULL, 0x955E8FC253E467ECULL, 0x04B9E2E99E4A5E04ULL, 
            0x6791459FA5D5E6D8ULL, 0xC6ACA27AFC93E0A4ULL, 0xBBB5035C859FD6C8ULL, 0xF8BDC81FCAEE709AULL, 
            0xA94BCD476DB49B4AULL, 0x320BC0156579ABA3ULL, 0x67D8D07A29044573ULL, 0xA75993C8F90D64BEULL, 
            0x06667AA195A95C70ULL, 0x96B193CFE0031C0EULL, 0x8911B77EB09CAC77ULL, 0x5406C5538E0D84E9ULL, 
            0x9A2F39C0F005CC50ULL, 0xD185101126E2D4C9ULL, 0x445FF32693FDF969ULL, 0x370B3E42ED1E1264ULL, 
            0x2E51D5363DC19942ULL, 0xDC0F41947550630CULL, 0x87E329CFAB3D2873ULL, 0x37D9A224C6F292E1ULL, 
            0x298E8174149D9742ULL, 0x4DA89DD6DB067EF0ULL, 0x3E6B4E79898E2E6FULL, 0xF57F2A22FDF35CCAULL
        },
        {
            0xF38850245CB8C5E6ULL, 0x15B329AD4A837377ULL, 0x1C64A85F9F221F9FULL, 0x9DF46651771A6781ULL, 
            0x74D1A583EB57A97EULL, 0x3231F096EF9A31C1ULL, 0x30D6B56B9701E22DULL, 0xEACC3D568047D54EULL, 
            0xE359151CE083B886ULL, 0xB3F12E981A1A61B1ULL, 0x294D3730F499AFA7ULL, 0xBF11E486DC9F3635ULL, 
            0x8DCDE00311869BBBULL, 0x9FEDBF7F3FFED3B7ULL, 0xE9E180625CB88E39ULL, 0x792ADEF229BE4348ULL, 
            0x488DF36E1E7ED11CULL, 0xB7274C02B97A8BDDULL, 0x0BCC0AFB1777109CULL, 0x353CC0237EF827B0ULL, 
            0x7E9A14DAA1A9DD59ULL, 0xD83EA890EF84402EULL, 0xCE575B0238427E97ULL, 0x0DD999F7206BFE82ULL, 
            0x9AD493E6E533E264ULL, 0xD8F112C651C7EB17ULL, 0xB3A0B58A2E92DBEEULL, 0xF6CDAC540C9E12CCULL, 
            0xEE697AF1F6F64C65ULL, 0x3EC80568EA314012ULL, 0x59893449714290D3ULL, 0x2D9AF146CB86571CULL
        },
        {
            0x7D4D33B3DC0D6C0EULL, 0x49790F7A38980D87ULL, 0xAB6A22EB0B8E96C5ULL, 0xE45778CB98720B41ULL, 
            0x76BFC15DD09DDAB9ULL, 0xA1D8712A64194A70ULL, 0x72CBEAC51303907AULL, 0xA711A241D67E9C27ULL, 
            0xA51257DAAD3849E9ULL, 0x4068E3635BEEA5ACULL, 0xCE0B571231D866BBULL, 0x596904520388025FULL, 
            0xDB0CEA1C35B661EEULL, 0x81E215707E9F35CEULL, 0xA488DB768C18A5BFULL, 0x855E6680E1808222ULL, 
            0x15620E60CA69C32EULL, 0xADA050D82AB3B4C3ULL, 0x6C85422288D8F392ULL, 0x6FD9C6050A119EE6ULL, 
            0x4C642FA1B49718CEULL, 0x45B17795697CD230ULL, 0x771D65FC13711EFEULL, 0xD37DCD7BCC645B08ULL, 
            0xAAAFBE4096112B32ULL, 0xDEC398BAC12D11B6ULL, 0x190CADB839A73C5FULL, 0x5567B007CA88B1A7ULL, 
            0xEAA2EF00BA9E051FULL, 0x028568145CBE86B9ULL, 0xF584A67AF110FC5CULL, 0xF022AA40010192D4ULL
        },
        {
            0xE80C351A1B373E7CULL, 0x585AC600BEFF2B6EULL, 0x89AEB65A37C967E0ULL, 0x6A030DFDB1B0E7DDULL, 
            0xE7BDD485B6EC9908ULL, 0xF5A247349C96EDC2ULL, 0xFD5C99CD7AFED0C5ULL, 0xF43263BA2956DC83ULL, 
            0x74F15A519A27212EULL, 0x84EDDADE8EA15B01ULL, 0x918D6C2DB71937EAULL, 0x30F42D6111C3B291ULL, 
            0xF482A4EBD7FDAA4FULL, 0x184039FBA026001BULL, 0x4A97087092B4C2B2ULL, 0x10AF525439C08C93ULL, 
            0x77E238675A2FEFBBULL, 0x33ECC59D0C2744FFULL, 0xCE8512BB994C212CULL, 0x0B056BD4418BA6C3ULL, 
            0x8A06B074E1E13954ULL, 0x2CCBBC73BA793A05ULL, 0x1817A388409D32D5ULL, 0xD53339873839CC7CULL, 
            0xFCED5978698E66F6ULL, 0x22641DD118A6BC4EULL, 0x6B3D9D071086DAF7ULL, 0x3BD6ACA62F5E4F1CULL, 
            0xBE0AA5C22B3A5B73ULL, 0xF5F4B1D8CF499FFEULL, 0x6871ECEA06BF90DFULL, 0x4561D30454BB6074ULL
        },
        {
            0xF8EF095FF17A4FACULL, 0x1C097B5056E0FF79ULL, 0x78249B7D2E3B3EDBULL, 0xDFFBB951F5F12DC1ULL, 
            0x42A221D10FD25324ULL, 0x2EF39802FC71AA06ULL, 0x4F86F0EEB86DEEECULL, 0xC10C4582CEC82FE0ULL, 
            0xAA01BDB6AD49AC8EULL, 0x274B1DBF69474429ULL, 0xC1BBBD3DD6BC67DAULL, 0xA793017E71E248F3ULL, 
            0xD077958BA452A59FULL, 0x2C2AA2BBB29E0573ULL, 0x7B9D629D29530E20ULL, 0x1C566B5FFDF38077ULL, 
            0xFDD00F7F5FA73BE8ULL, 0x2B0C4C1F2FFC82F5ULL, 0xE32F817CF6F6A484ULL, 0xFC49E5A3390A1AEAULL, 
            0x4B9F76C4D0F3E7ADULL, 0x1170BE80043E22A4ULL, 0x09CAD94C3964D4A4ULL, 0xAAC3A1D2B1DA5F5BULL, 
            0x8D49A489A942190CULL, 0xB2541ED73693124BULL, 0x15B006A385D9BB3DULL, 0x8705A61EC8B2DEF7ULL, 
            0x9CE267BE96B439DAULL, 0xC47E3D0A36D78198ULL, 0x3EF495E73A0E91D3ULL, 0x82E32DA4E8109D29ULL
        }
    },
    {
        {
            0x8EE25752D654A3F2ULL, 0x078FA780499A3D8BULL, 0xF42C56F515A07D27ULL, 0x756BB838B7879107ULL, 
            0x4DB222CD7D554BF3ULL, 0xA51D3E72DADE72D2ULL, 0xBEDF318648C7C8CCULL, 0xC80CE9BF6C560B77ULL, 
            0x89D41897415A874BULL, 0x741F7BC71DE715DFULL, 0x64DD715F679BEC25ULL, 0x44D1C70C927EB067ULL, 
            0xFC63363DEB149DE3ULL, 0x5200E2BD8D41BD2FULL, 0xD5A59143340C01D7ULL, 0x1DFDC0849D458ABFULL, 
            0xF77C26E7CE2B3317ULL, 0x385A7CD4EEF0828CULL, 0xC947F4DFFFADA73BULL, 0x4D1EDE663C6AF4F2ULL, 
            0xB71935FC77603FFFULL, 0x75B015C2674AC777ULL, 0x32B39E55BDAD36FDULL, 0x58E3A0F225A2396DULL, 
            0x84335E9D9F93CA5AULL, 0xB843E4242FAA500CULL, 0x3DB84914863EEABFULL, 0xF9545E0855B6EB6AULL, 
            0x40098B126D429906ULL, 0xD95CB5D2A62C616CULL, 0xF8CB944D7D09D11FULL, 0x49828A7AD041F9BDULL
        },
        {
            0x5869EF628E341C34ULL, 0x671F18F3F1E93AFBULL, 0x70FE14A0EEC7496DULL, 0x2C943D86B27A7ECEULL, 
            0xC7146D57465BCEE2ULL, 0xAE3690FF3E0C77E5ULL, 0x75F45D1C3C770980ULL, 0x039C60E30E48A276ULL, 
            0xC2D5BDA94D36F2E1ULL, 0x9F6236260DB9D029ULL, 0xE7EFC1EA535F9274ULL, 0x4A212C5387C4D8D0ULL, 
            0xC322AEF1A2C1C9C0ULL, 0x8257B43B28E763D0ULL, 0x3C03C6E4D6EDE530ULL, 0xC3A6F12D0B00AD5BULL, 
            0xF26E934680CC78E6ULL, 0x277D492F46C4CF89ULL, 0x74B2733D472515BBULL, 0x67EF9F621357A7C4ULL, 
            0x5FD55686A3634A70ULL, 0x16B26F3EF7600207ULL, 0x303D504D7D58CBB3ULL, 0xB4DC41264D09F6BCULL, 
            0xCE923BEA24BC08CCULL, 0x4B1A8E8B7EFAADE8ULL, 0x6E0122668911E391ULL, 0xF4E774BC80CA1BDFULL, 
            0x431E6859E4DAC624ULL, 0x2B71887D3022AC50ULL, 0x6A686C271B82E469ULL, 0xAA4958C9954B41ABULL
        },
        {
            0x0AEEAC6C2166EB8BULL, 0x17BCE4CF5202ECE3ULL, 0x4CB1D5C7A2062AA5ULL, 0x11D09A55D32F3BFDULL, 
            0x10A3DD11001DA2B4ULL, 0x6B65AE955BF50875ULL, 0xF72E06599864BDC7ULL, 0x574ECF7427728D5AULL, 
            0x1DB94891FC54297FULL, 0x4D429E2B36DF2611ULL, 0x64569DD34A124AFBULL, 0x2901463AD9DD1FF1ULL, 
            0xC9F4467E0B939902ULL, 0x1087BF4155CD3380ULL, 0xBAD867A5A784A66AULL, 0x02DAA39EA1959783ULL, 
            0xB1CFC964A9FBA805ULL, 0x0A02B397AA2EB8A5ULL, 0x432C7F2A0A8F48C9ULL, 0x0E9D5C4B13EC4ABAULL, 
            0xA6EE5B3B5A03D658ULL, 0x62331B09FF8933B2ULL, 0x78035C48EC0D03DEULL, 0x8E03E5BDCEB6C0E6ULL, 
            0x21D79870E9D9E68BULL, 0x96B98A56CDF843B7ULL, 0x21F6373645D28878ULL, 0xDB7216AFB1CD622AULL, 
            0xDB294453E479661EULL, 0xE980A428A4C55CE6ULL, 0x8E317B301F821F4DULL, 0xEF50B103C968C02FULL
        },
        {
            0x9BCF96BC269D53EFULL, 0x95562B865CF00A7AULL, 0x5F05C8B92F2B9706ULL, 0x1DA9234EEFAF44BEULL, 
            0xD3A60D98C0550C92ULL, 0x110FD9CE6390E4BEULL, 0xBE1083B035D8FA50ULL, 0x7B22DC46AA68718AULL, 
            0x5AAFCFDB07E8B3C3ULL, 0x4D0DB82612BBB6A8ULL, 0x381CFB382D3E1916ULL, 0xD78B6F1A3B9D1567ULL, 
            0xE1DC0CECAF413E0CULL, 0x9A5E0484444E416CULL, 0x3E6EC9F93CEC684CULL, 0x4F0D20566569986AULL, 
            0x328BA84C89F62023ULL, 0x294246CE02714086ULL, 0x282A1CDF76A09786ULL, 0x6EB2A5133458A1E1ULL, 
            0x0B4CF8997B5093F7ULL, 0xF9D23B47F32F69FCULL, 0xF28C7C7A2C6305B3ULL, 0x51E1A87D8C6C19ADULL, 
            0x32E515DD68CE42DDULL, 0xA2DBF1F917F86208ULL, 0xF61B3B5CEFF25473ULL, 0xAAD5EEE7F7CF0E01ULL, 
            0xE95578FBB265EFA8ULL, 0x8409F8372165E5C4ULL, 0xECF820BE56C05BC0ULL, 0x62AD3DD8D09E1075ULL
        },
        {
            0x6194AD8DD8170C59ULL, 0xEF54B6068F7AADEBULL, 0x0BF93C9594F2D1F2ULL, 0x4AEB1B7717B67794ULL, 
            0x4C6D9922578A2758ULL, 0x18201A9EE1516013ULL, 0x07493716A0EDDDEFULL, 0xCFF04D4BF5D9E752ULL, 
            0x484C8BCFD5AD6A6BULL, 0xF02E9D8A04ED14BCULL, 0x09A43960DE12C24EULL, 0x3D2004AC75292479ULL, 
            0x89E70D4B05E3FCEAULL, 0xE2C33E828084DE91ULL, 0xDD1030A8FD9C5ABFULL, 0x5D6820CDB5DECEABULL, 
            0x137528B730E042C9ULL, 0x4E0DAC77A6F1A484ULL, 0xE7A068F214526F06ULL, 0xEC17C626FBF66535ULL, 
            0xB002B4DAF10059B4ULL, 0x8CC11BD9E23CDC45ULL, 0xA03AC435A80E15CDULL, 0x052BD5BA2A086ED5ULL, 
            0x60B4BEFDF9D5F24AULL, 0xEC5B01A5FB92D826ULL, 0x20A1628238C55CB3ULL, 0x4B1F6E6789E6BA89ULL, 
            0x0291C21AC5B9CBC3ULL, 0x0DD4854D266A614CULL, 0x694D19BF16508A5CULL, 0x470CF4553986F3DDULL
        },
        {
            0x4A98B4D690BB6A71ULL, 0x27611A23C6BCF4ECULL, 0xE5F07ECA563F04E2ULL, 0x53EAF2FA4F46B0EFULL, 
            0x95EA98BA185971A0ULL, 0x23B7A831A6EECABFULL, 0x04B7435FDD49940FULL, 0x4D7E188518538CCDULL, 
            0x6705D38232B1D855ULL, 0xFCD92F0703323A9BULL, 0x5E2745BC26E62494ULL, 0x969EFB86A1A509BCULL, 
            0x4E8825579F2E9DDCULL, 0xB1C4116D18520DADULL, 0x2E2B063178EFCEB2ULL, 0x726C0811862DA902ULL, 
            0x886A048453D70E35ULL, 0xC755FC55D052A2CDULL, 0xE9D89B653BEF1605ULL, 0x656A6828BD97D98CULL, 
            0xEE2126C979FFC556ULL, 0x1651A0FCD74FF469ULL, 0x21DE4B0A4523D4C8ULL, 0x4767B8447FFAB197ULL, 
            0x3CF0F8B7FE7782CBULL, 0x7F1B02BA37223D57ULL, 0x3DC0BFCFAB3461D7ULL, 0xAA289246CBAC24D2ULL, 
            0x220435368F19C966ULL, 0x86952DAA1E96706CULL, 0x4B83FBE4CFA6CB7DULL, 0xA22F19A29E69881CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseHConstants = {
    0xCC3499259C02EAB9ULL,
    0x229DD926D66CD95AULL,
    0xCA05D22003416F04ULL,
    0xCC3499259C02EAB9ULL,
    0x229DD926D66CD95AULL,
    0xCA05D22003416F04ULL,
    0xB67AFF55821DC691ULL,
    0x999AF48F065402E4ULL,
    0x96,
    0x0D,
    0xD5,
    0xB8,
    0x3B,
    0x06,
    0xB2,
    0xD7
};

