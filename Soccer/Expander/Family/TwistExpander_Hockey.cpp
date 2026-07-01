#include "TwistExpander_Hockey.hpp"
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

TwistExpander_Hockey::TwistExpander_Hockey()
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

void TwistExpander_Hockey::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xCCBC603AEC5AAA86ULL; std::uint64_t aIngress = 0x9692F5321CA70FACULL; std::uint64_t aCarry = 0x845EC4A03893DBD4ULL;

    std::uint64_t aWandererA = 0xA31A64AE9D5831C2ULL; std::uint64_t aWandererB = 0x837C35B77EDF5E64ULL; std::uint64_t aWandererC = 0x90DB8A3AD2606F62ULL; std::uint64_t aWandererD = 0xBE77771387798D78ULL;
    std::uint64_t aWandererE = 0xA9BC99C1D0EB1794ULL; std::uint64_t aWandererF = 0x8F573FFFDBB072CAULL; std::uint64_t aWandererG = 0x988C5BC57366BAD4ULL; std::uint64_t aWandererH = 0xE2192EC92E9129E4ULL;
    std::uint64_t aWandererI = 0x872361E06B2CC10EULL; std::uint64_t aWandererJ = 0xEE632D25E3B73EC9ULL; std::uint64_t aWandererK = 0xD56BE12E627C8268ULL;

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
        aPrevious = 17321548179830861069U;
        aCarry = 10692740139278855953U;
        aWandererA = 11784670924377965870U;
        aWandererB = 13644504808359147529U;
        aWandererC = 9943878472976518206U;
        aWandererD = 14612132784283672910U;
        aWandererE = 13860129852317450463U;
        aWandererF = 9341993291401336940U;
        aWandererG = 10632722956108224775U;
        aWandererH = 16259741564479756750U;
        aWandererI = 17698891595696582542U;
        aWandererJ = 9696832247609227327U;
        aWandererK = 11969680507375118395U;
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
    TwistExpander_Hockey_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Hockey::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD9C03DA3106D33FDULL; std::uint64_t aIngress = 0xCE902E5CC032D28CULL; std::uint64_t aCarry = 0x86A5E1757EDFDBBBULL;

    std::uint64_t aWandererA = 0xD7C353836492A06AULL; std::uint64_t aWandererB = 0x9D0670B13584F740ULL; std::uint64_t aWandererC = 0xB4AF732CF3388B6DULL; std::uint64_t aWandererD = 0xC5EFBB4487FB011AULL;
    std::uint64_t aWandererE = 0xF302D097AE5EDE4CULL; std::uint64_t aWandererF = 0xE88DE273D178ED00ULL; std::uint64_t aWandererG = 0x86191136851DBE2DULL; std::uint64_t aWandererH = 0x8B970CA4740A4FCDULL;
    std::uint64_t aWandererI = 0xECB648DF9A37D7A1ULL; std::uint64_t aWandererJ = 0xAAFE46C1907F9DBDULL; std::uint64_t aWandererK = 0x8C95AB05AD910459ULL;

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
        aPrevious = 11514161294256423320U;
        aCarry = 14712572831570679988U;
        aWandererA = 17600134179139876416U;
        aWandererB = 17770973621317716503U;
        aWandererC = 14487950307231027871U;
        aWandererD = 14917735665103429136U;
        aWandererE = 9466729250773379250U;
        aWandererF = 15430603766386387571U;
        aWandererG = 16053025710845851292U;
        aWandererH = 12739962639755721631U;
        aWandererI = 17556154956947088900U;
        aWandererJ = 17750040425388728881U;
        aWandererK = 16193117027267313794U;
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
    TwistExpander_Hockey_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Hockey_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Hockey::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9299935D737A9EA9ULL;
    std::uint64_t aIngress = 0xA1030B755574FCEFULL;
    std::uint64_t aCarry = 0xBA4B6FC8EA85E01EULL;

    std::uint64_t aWandererA = 0xF4392D8AB8FDF07AULL;
    std::uint64_t aWandererB = 0xA16EBC2C7DC59115ULL;
    std::uint64_t aWandererC = 0xD79CBA95E3BD6BEBULL;
    std::uint64_t aWandererD = 0x962FA3AF5A6E595CULL;
    std::uint64_t aWandererE = 0xDA0E000B4FB8B91EULL;
    std::uint64_t aWandererF = 0xB20CB6AEE0EB60E8ULL;
    std::uint64_t aWandererG = 0xEFA8951CC51ED583ULL;
    std::uint64_t aWandererH = 0xD2359D46DAB3C7F0ULL;
    std::uint64_t aWandererI = 0xACAA8CCBB69B85CFULL;
    std::uint64_t aWandererJ = 0xC91B0EE66E6614CEULL;
    std::uint64_t aWandererK = 0x9A67DB8C49CDD0FFULL;

    // [seed]
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneA);
        TwistSnow::AES256Counter(aSource, aSnowLaneB);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    TwistExpander_Hockey_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Hockey_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Hockey_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Hockey::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Hockey::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA02372A6815AE993ULL; std::uint64_t aIngress = 0xDA4326347D99C722ULL; std::uint64_t aCarry = 0xB29D44BBE1D3487EULL;

    std::uint64_t aWandererA = 0xE7B5E7B6FC47870EULL; std::uint64_t aWandererB = 0xAB744497BCFDAAFDULL; std::uint64_t aWandererC = 0xB8AD7D2406DA9F29ULL; std::uint64_t aWandererD = 0xD7225EAF94797E25ULL;
    std::uint64_t aWandererE = 0xE4CA8BA98B762E35ULL; std::uint64_t aWandererF = 0x8E3160DDE4394560ULL; std::uint64_t aWandererG = 0xAB09C6B65C0F9ECAULL; std::uint64_t aWandererH = 0x91BEB3FD7A42AADDULL;
    std::uint64_t aWandererI = 0xDDCA654420FA4783ULL; std::uint64_t aWandererJ = 0xBBCECCFB3440BE19ULL; std::uint64_t aWandererK = 0xF22BB0EBB2BC9BB3ULL;

    // [seed]
    {
        aPrevious = 17973739171805832205U;
        aCarry = 14761772314301499634U;
        aWandererA = 9456704627482419689U;
        aWandererB = 18086489609509179161U;
        aWandererC = 17072690911296068160U;
        aWandererD = 14507899835183597020U;
        aWandererE = 15375144007181724322U;
        aWandererF = 10979923844768969490U;
        aWandererG = 14615457606836041244U;
        aWandererH = 10528893484802355208U;
        aWandererI = 14552837934635110108U;
        aWandererJ = 12467289762222881434U;
        aWandererK = 9898416773292487465U;
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
    TwistExpander_Hockey_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Hockey_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Hockey_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Hockey_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Hockey::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 3, 1, 0 with offsets 4594U, 3876U, 6804U, 7672U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4594U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3876U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6804U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7672U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 2, 0, 2 with offsets 3128U, 2793U, 5837U, 7264U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3128U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2793U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5837U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7264U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 2, 3 with offsets 4588U, 2751U, 1U, 5509U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4588U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2751U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5509U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 1, 3, 1 with offsets 4064U, 5205U, 6528U, 7705U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4064U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5205U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6528U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7705U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 0, 1, 3, 2 with offsets 52U, 1834U, 1190U, 1042U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 52U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1834U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1190U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1042U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 2, 1, 3, 0 with offsets 643U, 841U, 611U, 1500U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 643U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 841U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1500U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 0, 3, 1, 2 with offsets 1954U, 1296U, 1610U, 1005U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1954U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 3, 1, 0, 2 with offsets 1747U, 1919U, 269U, 1015U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1747U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1919U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 269U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1692U, 1549U, 1323U, 1622U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1692U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1549U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1323U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1622U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Hockey::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 1 with offsets 6146U, 7111U, 4163U, 7878U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6146U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7111U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4163U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7878U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 0 with offsets 2937U, 6841U, 7071U, 2475U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2937U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6841U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7071U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2475U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 2 with offsets 4466U, 937U, 817U, 5512U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4466U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 937U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 817U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5512U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 3 with offsets 5841U, 5155U, 2824U, 3359U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5841U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5155U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2824U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3359U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 4488U, 5121U, 8017U, 3076U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4488U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 5121U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 8017U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 3076U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 804U, 923U, 386U, 357U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 804U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 923U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 357U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1477U, 316U, 1248U, 1596U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1477U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 316U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1248U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1596U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1188U, 428U, 1821U, 1625U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1188U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 428U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1821U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1625U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 795U, 787U, 1253U, 648U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 795U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 787U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1253U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 648U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 1, 0, 2, 3 [0..<W_KEY]
        // offsets: 1534U, 1787U, 2029U, 1432U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1787U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1432U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseASalts = {
    {
        {
            0x3A80452DD558C483ULL, 0x30639EB8202DD716ULL, 0x2DF02F1999443AD5ULL, 0x11B3F5FCF35B662AULL, 
            0xDEACCE5D29B829D0ULL, 0x3D27355ADB0C3261ULL, 0x86729A27670152F3ULL, 0xE1069BCC4A579643ULL, 
            0xE20CA18D6ED11EBEULL, 0xF7255FFCC957FF26ULL, 0x7EDACC21CBBB37A0ULL, 0xCCF0C6BC046BBE90ULL, 
            0xE34E11FB7BF1F4F9ULL, 0x00613D5B492FCC36ULL, 0x351829D34D5FCF65ULL, 0xDB58BF6726092C18ULL, 
            0x7E8058F0526CD5CFULL, 0x4BB2014B2E3C4DA2ULL, 0x852E65DC2C699CB3ULL, 0x545B8DD501ABCC54ULL, 
            0x1DCD14C51B464B3EULL, 0x793F996521008FEDULL, 0x788A63836DB21BCFULL, 0x9887A5ACD2A4CCECULL, 
            0x201668CEAFF66D79ULL, 0xF0B7D91E268BD67EULL, 0x5A2C477973C8158AULL, 0xAC9C931FAA487289ULL, 
            0xF6B1050A23BA0397ULL, 0x5AFED0B0E7647A14ULL, 0x7920A3A0FF56D4A8ULL, 0x41EBAB2F594A5DA6ULL
        },
        {
            0x5A5ADF67653D2CECULL, 0x482720A182581D39ULL, 0xA5F8E8AF188110BCULL, 0xA7C507620B515234ULL, 
            0x044A1D1FED50125DULL, 0x107B8A61CA2BAFDFULL, 0x06EC33BF6B9BE899ULL, 0xD199FCF20D2783ECULL, 
            0x45BE88AA6CD4FA3DULL, 0x3BB5EC413FA5C50AULL, 0x3AC9E73313A838FDULL, 0x3030132F30872F81ULL, 
            0xCFCF7683FAEDF8C6ULL, 0x0F15F7A4B26DE860ULL, 0x12F61E2E7AF975AFULL, 0xC1A57E2F46AFF441ULL, 
            0x04BB424207A3DF2BULL, 0xABAA54979356EA3BULL, 0xE0C973B38750B182ULL, 0x80C2B7358708271CULL, 
            0xBF12BCCD4DE25667ULL, 0x564BC13499D78C33ULL, 0x198369B6C0CCDAB4ULL, 0x2BE35AC5B5285FF5ULL, 
            0xF42401F0B8FC5E13ULL, 0x1DDD971C997ABECDULL, 0x97D59169A686E829ULL, 0xB9B959B32E99C80DULL, 
            0xA7C1FA9F5571FA19ULL, 0xAE77FFFEB31A652CULL, 0xDB5828FD84B74B87ULL, 0xABA4969EBD7C83B8ULL
        },
        {
            0x3461B2024745C6BCULL, 0x32EB9090AB95B4AEULL, 0xDCA91975EF742CF7ULL, 0xBFF88726E03FAC52ULL, 
            0x52FE3889449E2876ULL, 0x0330BC3F46D6CF91ULL, 0x92042846AE07529AULL, 0x023644AF4136E08BULL, 
            0x6D2BF4B71027AA1EULL, 0x559D26983DBACE8CULL, 0x82A89AFD66A5F18FULL, 0x609373C9C0A8B6A9ULL, 
            0xC26B6A3996C95646ULL, 0x41F5A956029E9E08ULL, 0x2B4F64F04C677996ULL, 0xE481A3D693C0D3F3ULL, 
            0x82E7138F33B1F0CFULL, 0x72A927E626F2AED0ULL, 0x99F45C740E7CA29DULL, 0x9DCEC42F45034301ULL, 
            0x1E02630EAF0C0164ULL, 0x62BEEF6F07353D2FULL, 0xEC4779E1608AA796ULL, 0x54623C1CD27E0963ULL, 
            0xFAF9FEEFCB19100FULL, 0xC21416B037550C2DULL, 0x11AD78CEA9762AF4ULL, 0xA272907ACA33E10FULL, 
            0xC889FFD9B819D5F6ULL, 0xB265D9026496D83DULL, 0x3B05E22E88A0D87EULL, 0x94E07AAA40669D3BULL
        },
        {
            0x5E060B34F393A6C8ULL, 0xEC9208B6832169AFULL, 0x1882AEFD4FC51DD3ULL, 0x67552DD198D72F4DULL, 
            0xC241DF603C2C9672ULL, 0x91F6A04F118866D7ULL, 0x3E0ED0A795702A76ULL, 0x0DBF9C5A517743CAULL, 
            0x5876D65099846089ULL, 0x281C1194FA5E8C5EULL, 0x0880375101650865ULL, 0x8428051DB010BCC9ULL, 
            0xF0D43EEC00902224ULL, 0x48297A4DC338C860ULL, 0xF3BF9E3C307F36F0ULL, 0x6CAEEBEE90920B99ULL, 
            0x5F31AFA11BD27BBDULL, 0x972E47F8D340A965ULL, 0xC0E96F0BF0638581ULL, 0x0D651B71E7CC1E6DULL, 
            0xC1DF356476DF847AULL, 0xA3B6F8AC669DC0E1ULL, 0x898FFBBBAE3F6B91ULL, 0xD1831B21C8D4EBEDULL, 
            0x501D0A3EAC5FDB3CULL, 0xE77433907DE47BAAULL, 0x5AC2022578B753BFULL, 0xF6C92A9EB30C0433ULL, 
            0xF152C563340DA3A6ULL, 0x4F7A10A7C68AA744ULL, 0x03DA64EDA5ECD4B4ULL, 0x9E0C3FDF09F9D33AULL
        },
        {
            0x5EAD94A4CCA740F7ULL, 0x6B98C7D69D176242ULL, 0xE47E4E671669AC18ULL, 0xC9F4E4FFC5CC9DFFULL, 
            0xA668303BA06AC104ULL, 0x4558BB58ADA12510ULL, 0xBC0879C0A966D433ULL, 0xE006A7B11BD47F12ULL, 
            0xAF75420B599191E1ULL, 0x39AB04E6D54135CDULL, 0x16653B8575E412C8ULL, 0x7D08406FE0465748ULL, 
            0xE6F8386C6B13B96EULL, 0xD0234F349C508408ULL, 0xA60F3D7560E36BFEULL, 0x877199C9B53BDD2CULL, 
            0xAC721D2DD060C7FCULL, 0xC4192351E49D2913ULL, 0xBB0C2D09A7DDF979ULL, 0xA44B198A9A418E13ULL, 
            0xF9486DBD3F9188DBULL, 0x0A9905019B6E47B2ULL, 0x227F6B00626D71CFULL, 0xE641A32B5A15DE5CULL, 
            0x8AB948F670535D14ULL, 0x5F064E535876AD5CULL, 0x0282AF431B54D3ADULL, 0x2FAAA2E1A64E8F7AULL, 
            0x99E56892A23672F8ULL, 0xD92C54C21AA27B0EULL, 0x78D160CC9B2CC983ULL, 0xB64F2B983FAD5141ULL
        },
        {
            0x182A4DD2BFD80401ULL, 0xD1BDEE2CE8E9DDE0ULL, 0x9E7C90B7D8901075ULL, 0x4C72D507E1451D2BULL, 
            0xA791F360CE7A7498ULL, 0x085E600E1EEA8A13ULL, 0xBA947179B971CA53ULL, 0x52FB36731602146FULL, 
            0x99EE60F7BF9F9F06ULL, 0x0A6D23FB43563E7BULL, 0x66FE2F4F7E9651E4ULL, 0xD80682BAAA80DE87ULL, 
            0x9B0AC91D826C743DULL, 0x5E077CB85F05C390ULL, 0xE2A896E20B5730EAULL, 0x2B62044DA70B299FULL, 
            0x375F77C8EC07A1A7ULL, 0xFB23493800DED512ULL, 0x15FDE11F56B09513ULL, 0x1CE4F28D020EE1ABULL, 
            0x8A48C06310D668E1ULL, 0x3F1F111B28919DA2ULL, 0xD49E092ABBE35F8DULL, 0xCF91A0FE7DD9DEA9ULL, 
            0xFAD3B85029CE303AULL, 0xC0B248D76E3E2FC5ULL, 0x2B1C274C6C84A0EDULL, 0xFC4A38209D28CF84ULL, 
            0xF2CE567A32AE9B70ULL, 0xDE6726AC23FE464CULL, 0xD601E331110ACE74ULL, 0xA5C655636B32573CULL
        }
    },
    {
        {
            0x00747A05B402A4B8ULL, 0xB60B3C05D45CC960ULL, 0x5B7F4A1C8F36C769ULL, 0x2AA67E6D3C77836CULL, 
            0xA63CB438E4A19F95ULL, 0x6BD55371F09052B6ULL, 0xD7ECD2723D6C932FULL, 0x9DBDF7BE6177EEDAULL, 
            0xC5D5A2FDDF0A98EEULL, 0x63EA7369D48752C4ULL, 0x16A1979AD2E2FE70ULL, 0xB1896E302E60D58FULL, 
            0x1B0B5856F45289C0ULL, 0xFEE670D0A61B9552ULL, 0x08AD107A5E2F97CCULL, 0xDB5D6C96E61F9BF1ULL, 
            0xA7A5409B2A14868AULL, 0x7795508234EF3F33ULL, 0x24A1DCC2212EC74AULL, 0x5E7ED6703BE64FFCULL, 
            0x15C20609E5148978ULL, 0x19FA868B4A9F8CD2ULL, 0x65BAC615B9DBE99BULL, 0x89087363E4F9089BULL, 
            0xE7AF37A4D4438DE9ULL, 0x91FE1CE3A59F9166ULL, 0x3A1633191FA0BE4DULL, 0x639AE759D8E2E115ULL, 
            0x15C6300EDF376C1DULL, 0x1C627B6ACEA849AEULL, 0xE4E776019A102F21ULL, 0xBD8C67A5226B58A9ULL
        },
        {
            0x2AA668C29F9F89C3ULL, 0x386994A3E53D3B98ULL, 0xC7765D71CED445B9ULL, 0xD9E716247B7D7A9BULL, 
            0xF04028C27CF492C3ULL, 0x4426F67D00F19DEAULL, 0x22B94EF81C11D9D7ULL, 0xF9A39447302BE249ULL, 
            0x811C51C3FCE0F56AULL, 0x3EA1DA796FEAD311ULL, 0xBF38357C4D91D2C4ULL, 0x792A1E6BEF72EB27ULL, 
            0x6B533E4169FACCE5ULL, 0x138D5DAE2B869E1DULL, 0xC8A55FE643BCB4F1ULL, 0x10B4DF11AF12CACEULL, 
            0x5DE77F26DAF13249ULL, 0xED3F5789D7E58CD0ULL, 0x68D3A9655F975966ULL, 0x2689BFC356C187B0ULL, 
            0xBBE52F2AABF0F785ULL, 0x6CFE016AB0230306ULL, 0x4D334C71CDFB4AC2ULL, 0xF62CA97EB4B1A322ULL, 
            0xF902F11084C99B29ULL, 0xE7527C4B980386ECULL, 0xCB6D4E32357FA5D5ULL, 0xAA3EEA81EBD91EC0ULL, 
            0x42C43889B2F0EFDFULL, 0x5C15435FF3D75DA2ULL, 0x2D7E60ACE83AB1D0ULL, 0xBAD0E2A69F265D0EULL
        },
        {
            0x4AE38DBF14A01452ULL, 0xAB0F8E3F845F66A1ULL, 0x01AA75CF28E53E16ULL, 0x2449FEB136DD8EB2ULL, 
            0xCD334AC8B4EDFB8EULL, 0x66B4A47CE2C322D6ULL, 0x0494A954525B9938ULL, 0x36C7459FF7045779ULL, 
            0x4118D91CD80B38CEULL, 0x1B3E7BD75EB2E6C9ULL, 0xFEE5C8C0407CB2BCULL, 0x36BAA3E762FE05A0ULL, 
            0x48A4D9AA8EF27139ULL, 0xA69944EEC0F57CD3ULL, 0x37D21F02CBD321D3ULL, 0x923F19FBCE54F612ULL, 
            0xACBBB9F1DC3497FFULL, 0x80D5D1EA3BCE33DBULL, 0xD672157B546158BFULL, 0xE41DB10264EC8993ULL, 
            0x40B15164F74D728DULL, 0x560BB65F26C34A09ULL, 0xEB9310FD72B14907ULL, 0x486AE52D625C0A78ULL, 
            0x2150B410F2D1D31CULL, 0x007FA5D64835421AULL, 0x1BEAE3334BC17DF8ULL, 0xBE0F30C720D1AA11ULL, 
            0x8A3644F7AD61744BULL, 0xF06D612354903508ULL, 0xD738D30EECA87E9CULL, 0x904C173CF0397069ULL
        },
        {
            0xF2CB0BC5491872DEULL, 0x79F29BAE9D41F592ULL, 0x404BC757EBC6147EULL, 0xFE3076F9F2363605ULL, 
            0x0A34045926D3A1B2ULL, 0x8A5930119F6334FBULL, 0x77FD0A4B576115D9ULL, 0x701C1482915F472FULL, 
            0x58AD779BD88DF131ULL, 0x7188DD828DD4D675ULL, 0x151FA4F1774FDA9FULL, 0xB4BEE0040D61B5E2ULL, 
            0x84BEC325A89FB7F2ULL, 0xC31A9C1A2F572B2FULL, 0x92BA38698AD9C57CULL, 0xAC9FAE47BAA2FB93ULL, 
            0xFE6847402510331DULL, 0xB68089B7DE47AC7CULL, 0xC466FE5D7786D512ULL, 0x51FD75FA61181D86ULL, 
            0xD01852EB649C7B02ULL, 0x8A9A2C773DAA702EULL, 0x7D534F01C9566F3FULL, 0x25C1E3343AD1D0C3ULL, 
            0x76CDFFFB3601A223ULL, 0x54B25559AB0C1718ULL, 0xE19D656D412D9CDCULL, 0xF245F005274FF8AFULL, 
            0xBD9B7B06378DB4A2ULL, 0x2C7B0FFD886C2F00ULL, 0x928D76445F93B174ULL, 0xDDD819F6CBC95139ULL
        },
        {
            0x77EE7DFD3395BC25ULL, 0xCBE5BE288D5541B8ULL, 0x39363614C491F469ULL, 0xDB5187E1E5EFCC63ULL, 
            0xEFF17460DC00B7A5ULL, 0x2D408B28B91403F3ULL, 0xBFA47DFF60683766ULL, 0x6F2EDDF5655D839EULL, 
            0x87013FAD1280A24CULL, 0x110BFB7AB650440CULL, 0x3BAAA6E2954E7323ULL, 0x51089B54948C0A83ULL, 
            0x34430DFEF85EEB91ULL, 0xABF695DC7E4823E8ULL, 0xDD229685F25A8B17ULL, 0x225F641C954686C8ULL, 
            0xD9E2A09D1FDDDEB9ULL, 0x4B99A846ABE26CBDULL, 0x5C17BA2CA30C6941ULL, 0xC0268870FA9655BFULL, 
            0x524EE99D116C3D8EULL, 0x2B433167CA37B9BEULL, 0x15686FA7E7A398BDULL, 0x5F682EB8FA516984ULL, 
            0x9EB3B0A58D62F976ULL, 0x2C46399E8D1C8ED1ULL, 0xFCB777A2D4AEF914ULL, 0xCC552DA0A52EFA19ULL, 
            0x1059056E068F0EDCULL, 0x206E08DEE97197F6ULL, 0xF45FCF1F1B3E788AULL, 0x6270E2FF5083454CULL
        },
        {
            0x935A9C5BF94F3B7CULL, 0x3D5BC146372C49BEULL, 0xE0715E29C2ED263BULL, 0x7212011A962B6B60ULL, 
            0x3F8C54DEA421E14BULL, 0xCC4F164B4EB45EC9ULL, 0xD84C67723DF21079ULL, 0x31857D62D8407531ULL, 
            0xE566829847D81951ULL, 0x6A066851D34EE86CULL, 0x562545E2D27F26B1ULL, 0x90EFF1062C50339CULL, 
            0x8F57F5F673A8AB15ULL, 0x7742921F0DE2A695ULL, 0x4CB1AEEC2162A6C3ULL, 0x6F9BE8C8FCC06AAFULL, 
            0x5812F04D90FAEBB9ULL, 0x9FC1C24147780B26ULL, 0xC237F8D267B298EAULL, 0xF089071AC69CCF5BULL, 
            0x3E7A6B9F0A2E632AULL, 0x998FCD887757E83CULL, 0xDA53BCC5B96C25D5ULL, 0x68C07FFE769A46F9ULL, 
            0x5727F97540891034ULL, 0x2142D886AF8783C9ULL, 0x35797580F39F9672ULL, 0xC2D605906BF02ED0ULL, 
            0x542C3B078A19CD63ULL, 0xDDB411F8C2D81AA7ULL, 0x6BA23D4DE4BAA192ULL, 0x80C92100CA160227ULL
        }
    },
    {
        {
            0xCCF90729D13765FAULL, 0xE277901554375AA8ULL, 0x170C65E33B45BCF9ULL, 0x086F4DCDF4CCF0C4ULL, 
            0x6CA1F9BD72FF1EFFULL, 0xE8F72EA4AA22546AULL, 0x374D6ACEA3D2C15BULL, 0x30A676ED430728F9ULL, 
            0x1CD0F42341C862E8ULL, 0x909E132E99F14F27ULL, 0xA03BB91618C01488ULL, 0x9D63E1F48DB66CE0ULL, 
            0x601610CC02068DE3ULL, 0x12E6F2A79A853492ULL, 0x1D9F1CABF3A55D0BULL, 0x44267467F4EB81EEULL, 
            0x55DC0FECCDF03674ULL, 0x0FA12B93B9A2C315ULL, 0x4EF6FFFA40A9B373ULL, 0xF8D96B8507367C21ULL, 
            0xD01E8D883E4B82BEULL, 0x37311181898A3645ULL, 0x16B1D7A7A412967CULL, 0x841D97281C26BC91ULL, 
            0x5EFF510EC220A890ULL, 0x72FA3DCB0C5BEF55ULL, 0xCDE48B2288266CEFULL, 0x745C727598C018F0ULL, 
            0x4C9CC2507C0A6263ULL, 0x705EEC693541F232ULL, 0x526501175CBDE1A4ULL, 0x7D7F1E1A32EA4598ULL
        },
        {
            0xDF03DB10B0CE45E1ULL, 0x86C1B4090E462D87ULL, 0xAD3D611BB4229E77ULL, 0x4615C72A678FABC3ULL, 
            0x8D9C80779AD7E156ULL, 0x0B9062D6CB23E252ULL, 0x740555A3BBCF7E52ULL, 0x5E9147E29CFA3214ULL, 
            0x2C74BC4D97B929B5ULL, 0x9ED748D544B7F543ULL, 0x8C2B6C8BBBDF6096ULL, 0x9E661834590342F0ULL, 
            0x099923839582B3C3ULL, 0x27201E1D9BB66B8CULL, 0xA31CADC2A3C9D88DULL, 0x065CBF38BD90EA7CULL, 
            0x7142E6B45710F06BULL, 0xDAE7B33E307C5650ULL, 0x709A32602A3822FAULL, 0x4D8EF5AF0CFCFF74ULL, 
            0xE402062E1D13D0EEULL, 0x9EA288556331EF66ULL, 0x61772BC51C7D9666ULL, 0xDD60119CBAF57BE9ULL, 
            0xCEBAE1513BD8EC91ULL, 0x3C55FFD5DA1C039CULL, 0x27EC13F874AF086AULL, 0xA627D415F9DAEDF8ULL, 
            0x4E72968C992C31BAULL, 0x4FF5271557EA550AULL, 0xCAFD10E2398712DDULL, 0x9FAA87C02085EB95ULL
        },
        {
            0x6BF42A0E7A32002FULL, 0x143459CF1ECD7C00ULL, 0xECB728D451CDCAF4ULL, 0xEAFE73B0AE32B488ULL, 
            0x524823D883AB59ABULL, 0x0BF19C90760A0859ULL, 0x0756BBEA83A45033ULL, 0x1D7DED475EFB75BEULL, 
            0xCEDB597929E5DFDEULL, 0x0822D1EF6BE4722FULL, 0x14724A96C954A2CDULL, 0xCAFEE3DA217ED022ULL, 
            0xFE9F7871E831A692ULL, 0x4452489CF2B25D1EULL, 0xFEB2644BF0A5965DULL, 0x4E7A0DF8D1DBEA4AULL, 
            0xB942549F332A4BEAULL, 0x34287167298E768FULL, 0xECC60A13C657BD05ULL, 0x65B5DFCD3BB0E0A0ULL, 
            0x0DE5DB690C7F1FEBULL, 0xA0E6A53236A40C21ULL, 0xA6B4CC5E4510BDACULL, 0x3FE11F287F31DA1CULL, 
            0xD84B78FB658DA572ULL, 0x3EC61782A1C9B5A7ULL, 0x4F05B31E2890A83EULL, 0xB128ABD47AAFD1ACULL, 
            0x81736B8C57238163ULL, 0x06937B7700371FF2ULL, 0x04533174398F31B9ULL, 0x0A417B36BA7FD111ULL
        },
        {
            0x8EFBF4923E27668DULL, 0x4129473B91793741ULL, 0xC022DC75025FCBE2ULL, 0x2F0763C3F29CA7C3ULL, 
            0x05257710F2FA9EEDULL, 0xC3062775918EFB91ULL, 0x11926BCC4554061DULL, 0x668C390472217009ULL, 
            0xDEF7F87149C46B92ULL, 0x29D49ACECA7F18D0ULL, 0xE1B0457726003427ULL, 0x503BB5DEA5F7090FULL, 
            0x821D5BF72D6000A5ULL, 0xAD8EFBDBD3CA96B4ULL, 0x3BD0FFD17BCD3567ULL, 0xCF8C6499FF1EF777ULL, 
            0x82101173D97E1C2EULL, 0x77BD0EB614AB1144ULL, 0xF792B5B851A6CE5AULL, 0x8BC5F7C0E401D1D2ULL, 
            0x436C2B428FA2087FULL, 0x55C1743C8602C457ULL, 0x035E27C20A96D959ULL, 0xA1F51AB8B0C62A65ULL, 
            0xE8C8E5B487886B75ULL, 0xE7BB10618E56B6AEULL, 0x4CDF14FA69BF4670ULL, 0x779592D0D6F0ECF1ULL, 
            0x457B734C61F79606ULL, 0x59C12DAB17516DFDULL, 0xBDD798F73610A5A0ULL, 0x149BABA7EFEFC96CULL
        },
        {
            0x0A28953E10798941ULL, 0x6FE3374712E9C6D7ULL, 0x8FC1AA8CC9B7D4FAULL, 0xD1001F3E2ECEA292ULL, 
            0x299EAE4E5247E0AFULL, 0xB42262400B357804ULL, 0xCE74E624AEB0F4A5ULL, 0xC44BCC4645DF030DULL, 
            0xAD623EA3EEF0972AULL, 0xA041FDBB542DE4CAULL, 0xAF7ECC67AA5D566EULL, 0xE062117F3EAE92EDULL, 
            0x11BDFC846BAAEA08ULL, 0xB5350C2F3B7D75EFULL, 0x581B2119E715DE76ULL, 0x2C9676FF73F35796ULL, 
            0x4EF9DF1A3E69A841ULL, 0x3016C60AEB1D2FC1ULL, 0xE505998136B654DAULL, 0xBA1E10F8A9228619ULL, 
            0x4019833EDE14EB3FULL, 0xFB6E8619972244A7ULL, 0x75395B750817746CULL, 0xD8B38A868EB92B23ULL, 
            0x3F5C2031C480C045ULL, 0x4ED32D58DBFD229DULL, 0x3487B8F0F2DB8539ULL, 0x8B963085C5CACA9AULL, 
            0x9187D91132A76952ULL, 0x926AFE75AB6E1CE9ULL, 0xD4DFEF041EA924E2ULL, 0x32FCA69B56CF7FABULL
        },
        {
            0x86300120A2FB5259ULL, 0x5B651E3B76B50DC2ULL, 0x3B016AA80048EC13ULL, 0x78B271C300DADE58ULL, 
            0xD83BFC5465DECEAAULL, 0x4A6F7C89E4D2EBEAULL, 0x594201401FE6C0B2ULL, 0xF9C2E7B2EDD68BFEULL, 
            0x52042F17E90B6A72ULL, 0x282079774EAA7B68ULL, 0xC971F796DAD5C25CULL, 0x4968B025A596B888ULL, 
            0xA1971053D528347EULL, 0x45C774BD66A5CFC0ULL, 0x697B045C7CC75445ULL, 0xB4EAE23CFAA0B1A1ULL, 
            0xA9226B0BA4B87D25ULL, 0xD64AFB47C2D5B01AULL, 0xB57F955E22428D5DULL, 0xA34D1D42A5B1A1BDULL, 
            0xE64F3647E816E480ULL, 0xA2973DE8EF196707ULL, 0x090135683FB83DBAULL, 0x53A7479FA82B5735ULL, 
            0xEB6387BE77689E1BULL, 0x6E2EBFCB434D20F8ULL, 0xFA2A365714DFE4F9ULL, 0x5F056C34E50B44DCULL, 
            0x56569609FE15B867ULL, 0xDDE16D37E82981BEULL, 0xBD791A7B6BCDF33AULL, 0xDBF52B8282D31948ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseAConstants = {
    0xFF13A03C55E68DB9ULL,
    0x7CEF23A1A2F60E2AULL,
    0x1A089720104560F8ULL,
    0xFF13A03C55E68DB9ULL,
    0x7CEF23A1A2F60E2AULL,
    0x1A089720104560F8ULL,
    0x7612840491F328AAULL,
    0xA198E04DD47713CBULL,
    0xAA,
    0xF9,
    0xD3,
    0xA5,
    0x22,
    0x5A,
    0xFD,
    0xD7
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseBSalts = {
    {
        {
            0x254DCF6FF60B465CULL, 0x592D6CF288FE302DULL, 0x01F8F88B14C82470ULL, 0x3B8E73F6F6AEDB52ULL, 
            0xDC9C009B8D918EE1ULL, 0xE3693FF9C2B92BE3ULL, 0x1D2409A4BCE5CDA0ULL, 0xD9D16B9CEEBAC98AULL, 
            0xF0C708123C9E6A66ULL, 0xC0C1E538F007142CULL, 0x69A8465947E8274CULL, 0x3DD484B9C9F00700ULL, 
            0x05F5CB3A306783E7ULL, 0x1AE2C90A192FFB91ULL, 0x1B5F341E380CAA2AULL, 0xCFF096BC91735700ULL, 
            0xDCD6E94F68713972ULL, 0x4BA87CD7E850874AULL, 0x3EB6BE3162FB0873ULL, 0x43244DBF8C376D61ULL, 
            0x336A4640CF83E2E4ULL, 0x938192C1CFE1BE7AULL, 0xAC4D42541B05DBF1ULL, 0xEAF881901C31E56CULL, 
            0x8B9C2E00943795D1ULL, 0xE55E338168F55838ULL, 0x484E386E69B764D3ULL, 0xC78B343C70CD2667ULL, 
            0xBAD45AA8A5DCF470ULL, 0x7341B93CD836908AULL, 0x9DA3CFCC36C3BAB7ULL, 0x03BC9807160C9057ULL
        },
        {
            0x180634AB073D97A3ULL, 0x7AEF78ADC8974B96ULL, 0xE956BCB3501C0A2DULL, 0x6FD8E3EC1F264A52ULL, 
            0x0693041C4BDA2173ULL, 0x49E8A1223CF19757ULL, 0x3E1D21D416DD5C81ULL, 0x58A0BFD5D6CBBACAULL, 
            0xD80745528DA7DFC8ULL, 0x9BF26F1EF4B2C749ULL, 0xB8B98A2FDEDEC730ULL, 0xAEC9DA85CE1BC191ULL, 
            0x89AA2CCDAC1DB764ULL, 0x26810F7A193DBAEEULL, 0x0D087A3243FA6E35ULL, 0xF2D537FB80AB3D84ULL, 
            0x8DA3549F0729A914ULL, 0x6FE9C89238496F6DULL, 0xFADA937A93AAA171ULL, 0x9DD0A420ADB0E3C7ULL, 
            0xA42C2EC4996394B8ULL, 0x4A84A151BE6960F9ULL, 0x631F18DBDE607A06ULL, 0x043B137E82247743ULL, 
            0xA577C2EE48388CCEULL, 0x376784DD4D6E332DULL, 0xF948A31DB42864EFULL, 0x0B0319219AF46393ULL, 
            0x539F42201443FEBDULL, 0x9668938440DE908BULL, 0xCB3E2895E3C981E8ULL, 0x3040ADA48F2CBB5BULL
        },
        {
            0xC939F1E847EADDA9ULL, 0x334014851CF2F90CULL, 0x54DA411428432899ULL, 0xDD3850CE395118C1ULL, 
            0x184EE84E603D9659ULL, 0xFDB9E0C2071EBC42ULL, 0xE4DC412C7E55E981ULL, 0xB47ED0C6EF2A4A45ULL, 
            0xEC60902654792E94ULL, 0x03BC6D1DB10B3D72ULL, 0xFC0CEF9544C3FEAFULL, 0x6F88757CD1A659EBULL, 
            0x29B4F154DB09BEF3ULL, 0x55FF74BA9ACCE0D4ULL, 0x5A0189B5B2A49B55ULL, 0x011E312B564CC7D1ULL, 
            0x15908E5E456264E7ULL, 0x12B71584E2AC0057ULL, 0x19C36A9D0B15199BULL, 0x716BCFD46AF0DB39ULL, 
            0x2FD392C13D6BB135ULL, 0xA146E0A7BC710BE3ULL, 0xFCACBE1568A9E3FEULL, 0xB357448999525CE6ULL, 
            0x9BB65B1AD4306ED3ULL, 0x91335181DA15F927ULL, 0xDBB42533EF477E9FULL, 0x815AA25540648AACULL, 
            0x9DBD859696C4B9DBULL, 0x0152899306D8105CULL, 0x1EDCDE99388D6348ULL, 0x9E5C7589135BBBE4ULL
        },
        {
            0xB74707861121F5EAULL, 0x948591CE9377B63EULL, 0xBA0AB3F802A189C3ULL, 0x16AA716590B940FCULL, 
            0x2CEF9CEBFE383DAFULL, 0x8D0F2C0A134199EDULL, 0x36607894504BE4A2ULL, 0x9A9165213A361A7FULL, 
            0x7D8F76AB391A19A4ULL, 0x711C7F5B745D4DDEULL, 0xFA75A6D46E1ED5F0ULL, 0xBE2E6ACBE1D0BCEDULL, 
            0x15665F8F44DD2B1BULL, 0x0641BEDB531FB8B4ULL, 0xDFC766925DECAE8CULL, 0xE033496A7650E947ULL, 
            0xE9478AE7C5682350ULL, 0xC2E232792FB5FCC5ULL, 0x35CF9B061B797E93ULL, 0x7D3FE12B0DA2F0AFULL, 
            0xCF238AE650184CE6ULL, 0xBB59E4946825F1A9ULL, 0x027A82F5683D1019ULL, 0xF8C3A74992BDE3DEULL, 
            0x0A50474C20262B57ULL, 0xD88A8EC8BE78A427ULL, 0x52280DB071F5D7C9ULL, 0x2EB577ECA896ED33ULL, 
            0xF3B284DABAD0582CULL, 0x1F5F96D4CDA0F3EAULL, 0x5D986E961FAFAB6EULL, 0xA5E9A0A087B4CF41ULL
        },
        {
            0x5C0E6CAAE4E8B9D0ULL, 0x7044596A2F92703FULL, 0xFB9E03CAB49412BEULL, 0xD74FC4B894B4105EULL, 
            0xB5828467ECA7984EULL, 0xBD80DB415D39A0BEULL, 0x5C747575917598AFULL, 0x3FB0A09FAECD07CCULL, 
            0xBEE9A1ABCEB2E1B0ULL, 0x4DCF1C769F833C22ULL, 0x80136B34693FA6D0ULL, 0x8D1490F3EDB66F7DULL, 
            0x694EDCC1EABE8A6EULL, 0xC3923B8D1AEC298CULL, 0x6CF3484AF57DC99DULL, 0x606BA8279AD6FEFCULL, 
            0xA8BF440CA1329238ULL, 0xE63AD3C8E13D3D1DULL, 0x7864E2A82C5678B7ULL, 0x2D8E1579DB5EE523ULL, 
            0xB7942C6726E7B822ULL, 0x5949A01573245372ULL, 0xD18357FDFC76AB9BULL, 0x931DAEA2FBB2690AULL, 
            0xAF7EE2299288B843ULL, 0xFD2EF8943CDF6135ULL, 0x5CCA72D8AC37D0CEULL, 0xC3A60B856673ECFDULL, 
            0x78C494BC84E81D72ULL, 0xCC6934157C1AC329ULL, 0xBED43024065D23FFULL, 0x780B2234FE00FE5DULL
        },
        {
            0x160E5339D1C6241AULL, 0xB14840C511A6DCE1ULL, 0xE3842517C8C044BCULL, 0x3CA35348FE5D22D2ULL, 
            0xE5A5F9A128D05093ULL, 0x3F00F74E86C8BB3CULL, 0x90C47E23FAFA3909ULL, 0xB9B62AAE15B18579ULL, 
            0x1668201199FE446DULL, 0xC2849A7E2E20A767ULL, 0x5C1B4006ADB20BAEULL, 0x53787186EFA56F9CULL, 
            0x2F8E4788CA3D64D7ULL, 0x63E60FF7C640DE0CULL, 0xF8D3D105D4C43FA4ULL, 0x697A4EE91D3B028AULL, 
            0x3F92331FE5D4B1D3ULL, 0x3EC2B2779E77AE88ULL, 0xF2EC907627CBB9AEULL, 0x5E2EBEBD6FDD1336ULL, 
            0x7D80EAE952C0673DULL, 0x93542E502DA81EDCULL, 0xE00A9CF65958F2FCULL, 0x11B66476BB2A9AACULL, 
            0xD056CCA8765F3A8EULL, 0xB223D94544C01FC0ULL, 0x988DED34475A8E47ULL, 0x5812BB7F5105EA59ULL, 
            0x036D9B968BA236A9ULL, 0x053A0A6D9A7C2BA8ULL, 0xD363314630B762E3ULL, 0x6027EDCC035C800FULL
        }
    },
    {
        {
            0x623ECF15D0E5DC3EULL, 0xD8316B31BC35D949ULL, 0x82D9335879713C8FULL, 0x7336912782800653ULL, 
            0x0AE93EEF0118F866ULL, 0x17E55FBE4CE3BA5BULL, 0xC06BDABA497D276EULL, 0xE4D0210D40562BA7ULL, 
            0xC272C89A2EECAA54ULL, 0x453195135BFD277AULL, 0xA3FAA0CDD8215B22ULL, 0xD2C4815088D593CEULL, 
            0xEBD6F2A4261886D6ULL, 0x54F958FE3737A893ULL, 0x394E8EBEB1AC2915ULL, 0xEB5D352260B2DF16ULL, 
            0x86B0F6AED6CDAF93ULL, 0xC0CD8B84BA9A65E0ULL, 0x7413F7616B611F51ULL, 0xC7B25136D0BABB32ULL, 
            0xAD86D820B4C958A4ULL, 0x462D5D931A3808BEULL, 0x07648CF046E268A9ULL, 0xA95C11BD1F14950BULL, 
            0xDBC776222AFC02BBULL, 0x0675423F78875B48ULL, 0x3868012EDC867E66ULL, 0x33FB6FA8944CD1D0ULL, 
            0x77F64D27D3C951E3ULL, 0x7C72329B7C113F6CULL, 0x08DFF03EF427F941ULL, 0x2725D7F1B65BD08AULL
        },
        {
            0x6C9F21E8D7C43B47ULL, 0x14E3F93D258B01BFULL, 0x7C663EF0C3109CD6ULL, 0x3E9D2FB53480C29FULL, 
            0x6F9106659D399EFEULL, 0x8DAC69B86284FB52ULL, 0x736BC699547EB187ULL, 0x7F7025C2FD3C2405ULL, 
            0x7CDE64D3A3B146F9ULL, 0xDF1C4670B793D6DFULL, 0xFAE371FB3AD7CE11ULL, 0x91421CFF2D6303A2ULL, 
            0x6A1E4E1D56424BABULL, 0x0D572A6F8D63275FULL, 0x99EB67184F53EF4EULL, 0x69884E68E3B9F502ULL, 
            0x5BB496A0C6E05A52ULL, 0x2E5AAB3DE96986CEULL, 0x88798C1EBC70D5C2ULL, 0xE5E48F909E4BCF0AULL, 
            0x8CC4BC512A52E048ULL, 0x8704A4469138C832ULL, 0x602A5F3DD2CD6FD1ULL, 0x9C05816BEF1D3609ULL, 
            0x9E08F371D24D6ADDULL, 0x0DCA27EEE2EFAD49ULL, 0x6FED64B007A5007FULL, 0xECEB18B4D17A3977ULL, 
            0xC4B8F3A30A93C0B7ULL, 0xDC47132C1FD82854ULL, 0xEF7EECDFA5E3BEF6ULL, 0xB192B32F2FDDBF5BULL
        },
        {
            0x4D83F1DE981FD244ULL, 0xE3930B07121EBEBAULL, 0x3C57B6FC3663E1D8ULL, 0x42E6517715C72914ULL, 
            0xC3290D1019D90A88ULL, 0x2FCE93C3D5194856ULL, 0x3ED3C3997C0A0A35ULL, 0x82510813B98C4BB9ULL, 
            0x972CF728D93EAE3DULL, 0xECA1C793C9B5D188ULL, 0xE2C1F17938985B42ULL, 0x12D0B34B8762D324ULL, 
            0x58AA86EB5F238536ULL, 0xCD8CEE4899474C64ULL, 0x3DC72ED801B50E9AULL, 0x6FD104AECE8B11DDULL, 
            0x706265F4962D4B89ULL, 0xA6465790129566E7ULL, 0x74D0B9E0D019B469ULL, 0x0DF0324375BC94A4ULL, 
            0x621778716721661FULL, 0x8C9E80D917C93DE3ULL, 0x6D8A637F7F892D5AULL, 0x4C9E4B7A127C8C45ULL, 
            0xA002D76BFC1A398BULL, 0xE704A3D478148452ULL, 0x3B8CB8154E3997D6ULL, 0xC74312DEB7C177A4ULL, 
            0xA9B91B20304A3937ULL, 0x714EA7E7F84DABADULL, 0x7F7BCD3C5992CE40ULL, 0x655F1B992C395624ULL
        },
        {
            0x9D64BFC17A3BD2D0ULL, 0xA698F267B19C0512ULL, 0x7B24037BF7641C56ULL, 0x56E03FA5ADB32051ULL, 
            0x3FE26392A34D6C1FULL, 0xB7A74BBFBCCE4DB9ULL, 0xBEF71327D00FB8E4ULL, 0x64AFB87982B2FCD4ULL, 
            0x4CC703F13217ECCCULL, 0xA443772368A32663ULL, 0x0DCB567A05860F44ULL, 0x7D7554B2A6DEAD8EULL, 
            0x6D8E6CB5AA222534ULL, 0xF6C1EBE9AFDF3D5FULL, 0x924C7D668AC1FA55ULL, 0x27F09F2D3C4DBF2FULL, 
            0x1282E84E00477267ULL, 0xD48D6EFA29A74C60ULL, 0x210EC6F5B23B5FFBULL, 0x6167CEC421925BECULL, 
            0x4FE1B11C7196435BULL, 0x96BB291646AB758BULL, 0x700203CB2DE8B2C2ULL, 0xD4F31F9AD7CF24DDULL, 
            0xD45B741266840EF9ULL, 0xA2DA5270E6B28C12ULL, 0xABD232AEF28447B2ULL, 0x1CA4A4117C5D7C91ULL, 
            0x1B131A1547668B70ULL, 0x4717019E63C6C89EULL, 0xF167F742E705B901ULL, 0xE2BDDA94FA6E0476ULL
        },
        {
            0x5908F33FB19B006AULL, 0xE5504005D2E43C15ULL, 0x7EFF1494D1BF6EC7ULL, 0x32F870FC7E1BB010ULL, 
            0x92989DF5D33F0F55ULL, 0x36D947DA9A3305B3ULL, 0xC64ABF6659EAB339ULL, 0x3C287656AE995BAAULL, 
            0x3422AC06A75686CFULL, 0x6696354E0AF58E77ULL, 0x57812B18B7C55708ULL, 0x8EA373777254B497ULL, 
            0xE52D30414D07A8D0ULL, 0x8B668FD571493707ULL, 0xC93B239D6A37FCB4ULL, 0xE3172DE7B29653F7ULL, 
            0x0DF16C386BBE17AFULL, 0x6926E248BA94ADF4ULL, 0xA0409CCAE9987FC2ULL, 0x68C89F7F41FEDF18ULL, 
            0x58C911DC2CE9AF0AULL, 0x2EE14620CD6819FDULL, 0x041C87F0110FC746ULL, 0xB1E2B253387D4510ULL, 
            0x659371F4BE65724EULL, 0x2D36528B3FEA3368ULL, 0x078986DE45BF41E9ULL, 0x97D9FB72AFAAE50AULL, 
            0xF2EA8517BFBB6299ULL, 0x0A2AFBCB40B14DE5ULL, 0xD44AF6653456B10BULL, 0x19548B861A600009ULL
        },
        {
            0x3CF544527823721EULL, 0xA8793F64030DF082ULL, 0xD957895CD8A0D002ULL, 0x99172A909534D63FULL, 
            0xAD8C91D71AEAFAC4ULL, 0x95B49C0384680BF1ULL, 0x50F74A8D69A9A27AULL, 0xDD535690FB858BB0ULL, 
            0x4329E854A703262EULL, 0xADA7BCC1C4D2C033ULL, 0x5022784BAADFC267ULL, 0xE8288EC266403354ULL, 
            0xF68CA7ED36F96369ULL, 0xADB4611FCC26E2A6ULL, 0xD407F57986658D89ULL, 0x00CC3561EEBE51F1ULL, 
            0xE87BE76824A2A106ULL, 0xBDF150E1CBC3E293ULL, 0x606FE861D6D10BBDULL, 0xDB17BF1406BA6370ULL, 
            0x13FBF97A1D07E63EULL, 0x688131220722D5DBULL, 0xA9B86559B4ADE8FEULL, 0xA22F1C0CF537D26FULL, 
            0x5962436254CB1385ULL, 0xB2F10FE96494FB7EULL, 0x90FCDB1E1728B216ULL, 0x150172B0DBE3DD45ULL, 
            0xF0B5448DF755E84DULL, 0x5625B5488E6AA383ULL, 0xB75DE0FBA0EE7333ULL, 0x63A0C1B8B2CA18FAULL
        }
    },
    {
        {
            0x2E9B54D99D90DA63ULL, 0x775E17CF14D0E301ULL, 0x44B00913B3EE370AULL, 0x8EDD5EB2E0C66E78ULL, 
            0x0960DAC301C4BE56ULL, 0x752B42C97DF452BCULL, 0x80BD9E142BBAA1BDULL, 0xCA8D24C10D707128ULL, 
            0xCE1158C5331035D9ULL, 0xC363A8468F861036ULL, 0x2AD61C45CD7BB656ULL, 0x6C4BDD42D0DC60C1ULL, 
            0x08ED355BDBADC787ULL, 0x97D96F8EB727955AULL, 0x817A5372B3D8D1D1ULL, 0x5DF26F306E26A591ULL, 
            0x8ECA4C83CF0D00BAULL, 0x8772A48DA1F65BAEULL, 0x6C73AC6AC923F2B3ULL, 0xA7D9159A558F30BEULL, 
            0x825583D2D87E9EE0ULL, 0xD269952DEE434622ULL, 0xFA22A256DB885213ULL, 0xE674A289C4A75DE3ULL, 
            0xBCB6B6D213C444B5ULL, 0x395DC0B343E3C861ULL, 0x822E771D0A83FB5EULL, 0x74E6753E93489EA0ULL, 
            0x69732CDDF0C8AD23ULL, 0xEB119F03CBE8D56CULL, 0x79FF5C892E74767BULL, 0xB9C77CBE4D4F6400ULL
        },
        {
            0x9DCAF7B755147EE1ULL, 0x51CF917CCDE17CF6ULL, 0xCE3488AB46EDC3FFULL, 0x138A4215AC106F0EULL, 
            0xA78DCDE2F8494DE4ULL, 0xE5EBA100010C87F8ULL, 0x6BE86236A0F4F6CCULL, 0xBE08988CD5F8A42BULL, 
            0x5E2CC7A32E9F18AFULL, 0xB08C083B46445AD4ULL, 0xF53E6135490D94B3ULL, 0x7859A8F142B1DD83ULL, 
            0xC36D995C5E64AC2CULL, 0xBF4400598E6E70DAULL, 0xE1B59B4640B35B84ULL, 0xECB7530C52692408ULL, 
            0xF1FF17650C7277E4ULL, 0x58E542B1CD790324ULL, 0xC5F995D2392BE1BDULL, 0x35E1F66F8A491B21ULL, 
            0x4A9E00B6185CBC98ULL, 0xE4AD05D36FB1965AULL, 0xF56C9532C335F487ULL, 0x6FA7E913C5182736ULL, 
            0x546AB2F69FBBC49AULL, 0xB524158B3569B0ABULL, 0x053E7BB107990B34ULL, 0xA8399438DBE115DBULL, 
            0x5B205984FE28F6BCULL, 0xEC10EBE953E31AF2ULL, 0xD9BA75DF825B7524ULL, 0x5580A7EBDDF44FB7ULL
        },
        {
            0xFDE2A397E89927D8ULL, 0x0ED50AA20373693CULL, 0x697BFC2E7B518231ULL, 0xFCB86E87EED3A51DULL, 
            0x0E5E842B83E225B9ULL, 0x30619A3C51F40E98ULL, 0x10F9CD1F4690C101ULL, 0xE0B423FAC00743C5ULL, 
            0xBECFA5671FE8EE46ULL, 0x8A87916B3C8B08A1ULL, 0x8949AA85F542C4C4ULL, 0x1F7FA5108054EBE1ULL, 
            0x83E4AC1D5F90C0A4ULL, 0x761E674107898968ULL, 0x712589ED48134CC5ULL, 0x53DDB6FD64D7C17DULL, 
            0xA2B976EB39614D45ULL, 0x9828951514EE72C8ULL, 0x97BCE6D8A26C9B63ULL, 0xD475960100ABBEB3ULL, 
            0xE0CF876ACEFC2626ULL, 0x0C32C6AF27F072D7ULL, 0xF0BD1A4137F3154DULL, 0x1DFF5FCAAE0F2AB3ULL, 
            0x01C862830D4A8F4DULL, 0x2AE081B1ACF882BAULL, 0xFBD51821EFE3D1EBULL, 0x6E047DC8FE9D951DULL, 
            0x894B362164BB8605ULL, 0x53144B3FAFFC514FULL, 0x822ECEC218E3F62DULL, 0x5536C6B94AEBBD52ULL
        },
        {
            0xD3D56B665C249D1DULL, 0xD107E621EFD2C078ULL, 0xA04C11F9E4374F4BULL, 0x5FA3BD25D7B99423ULL, 
            0xC480945FA374F32BULL, 0x0752890BF231AA05ULL, 0x6ED80033FB0909ADULL, 0x706A6FF3EBDD329AULL, 
            0x8B9F82D1E5D3BA66ULL, 0x2D2FF9064381DBB2ULL, 0x436F4F00150EA884ULL, 0x63CF7A291D5C3AF1ULL, 
            0xDAB59CEE4A14AC82ULL, 0x6B62AC7AAFCE046DULL, 0x659173EB6394C70BULL, 0x07D4704A49858068ULL, 
            0x0DAD5BE22880AF13ULL, 0x28043137C3C623F7ULL, 0xB6BE2D3DEB66FCA0ULL, 0xE7E1FE9B1A985896ULL, 
            0xE0B2F1EAE2F4A8B9ULL, 0xA980261C4D3873BEULL, 0x66CE172FCF9AC18FULL, 0xAF5AC3942FC15DFDULL, 
            0xD455B06EF7A7FF92ULL, 0x32179687193AB9D7ULL, 0xA1C7F8E4AE5A64EDULL, 0x946E7716788D4A57ULL, 
            0x966CC62C464D6718ULL, 0xAB2272FFE2518438ULL, 0x401849AD9495DC45ULL, 0x07D5DAD41ADA3C83ULL
        },
        {
            0xA522AA2FC27D6F12ULL, 0x98B71BF88681C596ULL, 0xE48C0233537BD483ULL, 0x97341CE9A25895CAULL, 
            0x3E458F560A54EBBBULL, 0xE5FE80E31DD6DB10ULL, 0x2907C628EB3B0BD0ULL, 0x4EFAFA3D23860A4EULL, 
            0x22D113CDFDDD836FULL, 0x5ADCCC4FAA0090DEULL, 0x8EB2DDA1C5451BE3ULL, 0x4D2AEC5DA1D761C5ULL, 
            0x2B08B351E5B243C4ULL, 0xAE71491AE7A825A5ULL, 0x29DB2E73626702AEULL, 0x86C1332DCE03BCFBULL, 
            0x983F73A31932F51DULL, 0x5A5FA241B77BE531ULL, 0x51B13CADD1620F7DULL, 0x7F067A499EE3CC3AULL, 
            0x92F01EF9E72D2A23ULL, 0x9618B8EE9BF874B7ULL, 0xE466F044796A968BULL, 0x8223AFF43ABE0488ULL, 
            0xF2DA0ECC9B68F9B9ULL, 0xCD8E58682A583903ULL, 0xE6B6ACED06EBE3B1ULL, 0x54378962DF833FF4ULL, 
            0x731A617C0320BB38ULL, 0x9703DAD42B1A396EULL, 0xFCD1F358631DB8E2ULL, 0xC1E9F5EC8BA3509AULL
        },
        {
            0x91B55522952A86C3ULL, 0xCCE7D01926F5174CULL, 0x0C34E4342F157537ULL, 0x62C0540AFA06737EULL, 
            0xCB53E7854DC53F51ULL, 0x962453CA91AA9E9EULL, 0xD73C9D1BBB78A723ULL, 0x2B8DF65A4E8A0F62ULL, 
            0xC4DB89CC130D092BULL, 0xB88B4A9182C89F27ULL, 0x91FEFCDEF206233DULL, 0xD7303E69C85BF2B7ULL, 
            0xDA6F52C13147344DULL, 0x58F3DB6C7BEA11D2ULL, 0xBA39908F7CE94FB3ULL, 0x0603822A234440E2ULL, 
            0x0296B3656AFC1B86ULL, 0x368ADA3AF572A228ULL, 0xB62F71720BCB0313ULL, 0x6875E0DA14A7D4A0ULL, 
            0xBDB513DAADD02463ULL, 0xC93FA2D6620629DFULL, 0xFCBFFF7314127585ULL, 0x6157638A7C3AB0EFULL, 
            0x3B31C0E68B242FE2ULL, 0x5A85117125B23532ULL, 0x6A8AFD304683326AULL, 0xD468E8E7B2C8313AULL, 
            0xC93C0A10168D7402ULL, 0x11CA0A1B78E86C30ULL, 0xA88DAEB2F93BE803ULL, 0x99673A438E93180EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseBConstants = {
    0x6D0892C0EB8875A7ULL,
    0x728D9A4F56D550C1ULL,
    0x28742F70587C9ED7ULL,
    0x6D0892C0EB8875A7ULL,
    0x728D9A4F56D550C1ULL,
    0x28742F70587C9ED7ULL,
    0x9F4B468B7554F5A6ULL,
    0x181A5589C8DC178BULL,
    0x04,
    0x92,
    0xFB,
    0x9F,
    0x5A,
    0xBA,
    0x38,
    0x9C
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseCSalts = {
    {
        {
            0xB4BC0AC2DAC3EAF0ULL, 0x9FC5BC79E2E68B7EULL, 0xA1D046A932B389C1ULL, 0xFB1DFB12157A3B28ULL, 
            0xEBC51891AD236B9EULL, 0x1E754A726962A967ULL, 0x20DF500DE3F100B6ULL, 0x183CC37C77D9E8C0ULL, 
            0xD429064E0EDBAF88ULL, 0xCDA428DB0A832CC4ULL, 0x54D88F834D9C40ABULL, 0x0589A2A29C56BE51ULL, 
            0x504427DEC9D784C4ULL, 0xE42532DCB40CDC31ULL, 0xF57BE2F33820A2DCULL, 0x7BFCB6916A148A68ULL, 
            0xC80EC12E9FAF8466ULL, 0x4AD072D031AAB88BULL, 0x51278A8E7B78490FULL, 0x94727C66DFA9B8C8ULL, 
            0x04F8C770B49DC31AULL, 0x2C97B2E43E9C18BCULL, 0x743B2C5CC59B352DULL, 0x24F28A892B9646CAULL, 
            0x01050CD7615B17D8ULL, 0x7F9F73A0B4BDDDFDULL, 0xC5A7FF1BCF27D18BULL, 0x5A68F935E7B3907CULL, 
            0xCBFD76F010AFDCE1ULL, 0x39C7B118D90FC784ULL, 0xB78AF349407D10E8ULL, 0xDA2EA9B52E8561DDULL
        },
        {
            0x364D71E459E83D54ULL, 0xB951EF4201DF0018ULL, 0xBE02EE974A87E6EDULL, 0xDFEF282B8DE9D8BAULL, 
            0x1A85FF1C5C10AD19ULL, 0xC81456FFDF1DA8DFULL, 0xF9D4AA61D314423FULL, 0x345B6F3A3D0A6727ULL, 
            0x7034DEBA4B3E1B4EULL, 0x361AFFBC30C77840ULL, 0xBC52521DC01FD283ULL, 0x8BF2C530FDDADAF0ULL, 
            0x5EE5F4017DACE361ULL, 0x55E1641317BC72BCULL, 0xE68A15FD23C634B6ULL, 0x4E49F77DDAA3B721ULL, 
            0xF8D9C4280FB49633ULL, 0xF336E763321BAB83ULL, 0x4943D431DC6A7FD7ULL, 0xD65EBE5EB69C06E1ULL, 
            0x07DB8AE380D1FFA1ULL, 0x146840ECFE12A3A9ULL, 0x8B869B8C6C464FF8ULL, 0x7FDA9BC08CCE6FA2ULL, 
            0xA52345F9B3184A6EULL, 0x5B152AEAF6B49C13ULL, 0xB655F42C723E92B8ULL, 0x719021EAD93AE0DEULL, 
            0x51F268E565754C53ULL, 0x385D1A0A899570F2ULL, 0x3668EA46E11C252CULL, 0x60FCD4132A63A8BFULL
        },
        {
            0x916A8751B71B39D2ULL, 0xF380F354D54E8D9EULL, 0xE5D3F2E22A9D08B8ULL, 0x85B83232F31D3E2FULL, 
            0x38CA93A274EBC122ULL, 0x92BA7C2E0D938135ULL, 0x8D05D09211C12425ULL, 0x12CBA80EE28434BCULL, 
            0x15FB97FE1E654B44ULL, 0xA29D7F3FB2C52361ULL, 0x3DF8EF22F682979CULL, 0x58125732BDEA8A96ULL, 
            0xE62547211D368BB9ULL, 0x793829153B95FDF9ULL, 0xAB5F4AC8F438AAE5ULL, 0xEB63BDFD7EB1AE81ULL, 
            0xB41B0534188C8C85ULL, 0x7D5DEC617EBF26E6ULL, 0x683DE7425622D615ULL, 0xE7FB3A178E437F35ULL, 
            0x7056E391EA63CF44ULL, 0x2752BE607E5082E6ULL, 0xD8AF9AA1D375A3DFULL, 0xE08E466151EB73CBULL, 
            0x044670EB2CE3EA36ULL, 0x548BDC6E92A53EACULL, 0x7E25BD9861E81E8BULL, 0x63E2ADF7E6E9DA7BULL, 
            0x53A04DFA408F2EC5ULL, 0x27A8E2069E5FDFDBULL, 0xDB235CEF95A45958ULL, 0xC18732631C12CCD8ULL
        },
        {
            0x81DF0B9269C1A056ULL, 0x9AA86FD13347CB7BULL, 0xA97466DA7B38FF84ULL, 0x4D4A4D0BA02B660BULL, 
            0x811650F5315EAED3ULL, 0x86C39487CF414480ULL, 0x38BC7F5D18EAD0AAULL, 0x3570ACABF5290700ULL, 
            0x6D5FD51CAB5703AAULL, 0xED396F6198283946ULL, 0x5418F4C198BFCC7FULL, 0xDECFAFABA729E260ULL, 
            0x6A9969C1961945ECULL, 0xB117325F64FB444EULL, 0xA7912F701CF00D2DULL, 0x6B6F4C3D4543493CULL, 
            0x272AE19F63691484ULL, 0xF4078993E8702D78ULL, 0x120D762E662C9F92ULL, 0x4166D63EAC68F501ULL, 
            0x8F9A5D0ED8503238ULL, 0xE55AF93000E78F24ULL, 0xFB9160F2E7B25E33ULL, 0x7D653EEFBC47D718ULL, 
            0x83EAF4D314B5E5E7ULL, 0xFA44168F08FBE9A2ULL, 0x02AEBF6635E86A11ULL, 0xE254150D80E1F410ULL, 
            0xF1461E77CA552BA5ULL, 0xC4B6F60EA8E6DC32ULL, 0x953FFB1E39C40309ULL, 0x327759F54F387635ULL
        },
        {
            0x4EE925B218F8B135ULL, 0xF2AB56742FACF292ULL, 0x541791BFB01B046AULL, 0xD0EAB3CF4BE999A8ULL, 
            0xAEC527455525F65BULL, 0x68719265D4E299E3ULL, 0x960CAAB125DFC3BCULL, 0xE2552B1A27A672ADULL, 
            0x28837FC1759506D6ULL, 0xC462C4FF6EC35F28ULL, 0x970DDF89E275C2CCULL, 0xF33F6384B1FDE062ULL, 
            0x022350B9D96F68E5ULL, 0xA7785E35CDE3FAAEULL, 0x061A301C1A35381EULL, 0x1311E39E68BA129DULL, 
            0xABA6BA5ED9A8BA51ULL, 0x6A03F1602BE07960ULL, 0x27C332D53C256C3AULL, 0x7782C5DFE13AFD0CULL, 
            0x81785F6ADD2BEE23ULL, 0x3548FB86379D6EAAULL, 0xFEC1F333BBB92AE9ULL, 0xA9B9225FA0346F11ULL, 
            0x018A9BC9B010E58FULL, 0x5024F566040CBB3AULL, 0xB98BC251651F3452ULL, 0x9BE5D9022703F3E7ULL, 
            0xDDE632391EBDC817ULL, 0x3DCF7D603353A622ULL, 0xE08BBE554A662862ULL, 0x47BF356283C31A01ULL
        },
        {
            0x8EEEAA73366BC67EULL, 0x5F02FEEFE9E19FE8ULL, 0x7A0DFEB794F4B63BULL, 0xB3E6F3A2C5E9D5FAULL, 
            0x5AD064CE902E3FDBULL, 0xCBC82DD46E2A4B4BULL, 0xDCEA2A07A50BD0B7ULL, 0x005094B8A4E66C9DULL, 
            0x3725E8D9D5121E86ULL, 0x3EF7341688CA8846ULL, 0x2B8D8CDC419D7C11ULL, 0x3F69D414D69EDF7CULL, 
            0x330CD93B3581D560ULL, 0x2E7D1CC8370EF5D1ULL, 0x0840A50C352DFD82ULL, 0x63ECCCCA6F89A0F2ULL, 
            0xBB075892E5F2A2A1ULL, 0x4FEC4C3647D61123ULL, 0x0459F7F0BD253B30ULL, 0x188C9F5C82382F68ULL, 
            0x7F35208261CDFDE2ULL, 0xC5D53F94A3352173ULL, 0xAABBF90BA967B700ULL, 0x3C9FD3D714DDD283ULL, 
            0x75E6E1B604C3AE39ULL, 0xE5E2F339AA47132CULL, 0xD0A500B0DDCF98EBULL, 0x6FAF5EDA99159527ULL, 
            0x91C5BCDBB7988527ULL, 0x251BD50B4A52F0B3ULL, 0x1F07E96AEB8AD416ULL, 0x6B4A8822D8EE2313ULL
        }
    },
    {
        {
            0xE3963576CA8CBFA2ULL, 0x7B1F13E4A8FCEB03ULL, 0x42B2252FDD130081ULL, 0xB805741BD69F6D45ULL, 
            0x161806D339E1A2C7ULL, 0xF68CDD375BFE8ED6ULL, 0xCAF25E1C1F029E40ULL, 0x6F6E167C46BD2561ULL, 
            0xEBF1D6527FC1D69CULL, 0xDDD0DC72432A906DULL, 0x217B635C6CA6EADAULL, 0xE15CFDF45293C168ULL, 
            0x5C3FA9A6F2D1F2B2ULL, 0xF998EA700FB98147ULL, 0x4CAC1F0D01908973ULL, 0x84C4ABCEB31D51ABULL, 
            0x746008381A6EA720ULL, 0xF9EC9401F59B6BF6ULL, 0xC2F2C75895D4CE91ULL, 0xBB2A1F921A72F75DULL, 
            0x5EACEC11F75018B9ULL, 0x4B0336EE18FED0D9ULL, 0xC5B3558655BC5ECFULL, 0xA850D69E67BEF066ULL, 
            0x1E8390D64FACA5F5ULL, 0xE217580B5F1881F7ULL, 0xB8D733919A10D095ULL, 0x51843DE5D33B2845ULL, 
            0x910869993BD178FDULL, 0x10A7B4D209C3E6DDULL, 0xDB09B1D1A6C29B27ULL, 0xEDC75249CC8E2DE0ULL
        },
        {
            0x942A219A58CD5C0DULL, 0x6B77D7682F839CC6ULL, 0x2B0CE528BA2814D5ULL, 0xD02B8B77BF36746CULL, 
            0x1432F45AEBB66F4AULL, 0x600236CE2D36E468ULL, 0xC9891BC6D6D79116ULL, 0xD458C487B3FF020AULL, 
            0x78C7D06DB1195894ULL, 0xBCDFB335D991919DULL, 0xB60FB0A99E17D282ULL, 0x473668C72418B3C0ULL, 
            0xAF965EB5FFCDBF53ULL, 0x01A49769D43168CDULL, 0x884C648989FA3EE8ULL, 0xFCAD0D5E26DD8296ULL, 
            0xBDEF2FB7864A6781ULL, 0xB844922EB0303CE3ULL, 0xAEE28FA323E29845ULL, 0x4429FF10679F9641ULL, 
            0xA354954C8356C85EULL, 0x6B1C40901CD0F1FBULL, 0xC83616D0A285B5C9ULL, 0x69B02650D727BD6CULL, 
            0xE7C397057A5EB17FULL, 0xE3AD4F8C127517BAULL, 0x731BF36D8A54EB1AULL, 0xDAB61F63F2A13986ULL, 
            0x8DFBDFA5EDA794B8ULL, 0x19637CC005C1DD32ULL, 0x967D0A592A668C1AULL, 0xB56D6690E73E89CDULL
        },
        {
            0x57D015A34E1654BDULL, 0x70A9F81833DC1FA3ULL, 0x9E4B258AC5EE06F4ULL, 0x270BDED54CFC6988ULL, 
            0x3D358E45B419D02FULL, 0x68FB37D43A84BE20ULL, 0x72D50487413DA618ULL, 0x4B0B96EAF9D6FC10ULL, 
            0xC1F85EED488006C8ULL, 0xBE04B844E6059BAFULL, 0x10CF8B867AB239BAULL, 0x6BD50C049616361CULL, 
            0x546F41A635DDE2A8ULL, 0x51D3388B1DE04813ULL, 0xE5EDC5445FAF4ED2ULL, 0xF3B66F6DBB0C80EEULL, 
            0xE28AC8CD2FDD1D0BULL, 0x6A582FC313D07484ULL, 0x6B2A9E6292D25A9AULL, 0x3EA29B038A5D75F9ULL, 
            0x60FA7D73EC736C2AULL, 0x7D2E47217AAA3FCCULL, 0x9B819532E74F6BCAULL, 0x378D4578CFAD96DFULL, 
            0xA9F952809083F13CULL, 0x63AEA8EB2E60FC33ULL, 0xFC52DF0B790A9F24ULL, 0x2422FDDC4F03DEB3ULL, 
            0xDD8705961C703567ULL, 0xB550228083AF552AULL, 0x6464883EC73A4507ULL, 0x2794ACD85CC6CC0DULL
        },
        {
            0xE5E62526528532FFULL, 0x6507B310B723E21BULL, 0xF3235637AA1FEAF3ULL, 0x40E41D964017643EULL, 
            0x2877A08F23C62D76ULL, 0x232B326F48CEC09EULL, 0x69AE593CBF424210ULL, 0xBA353E49CD1F6D02ULL, 
            0x7457D9CE32F53957ULL, 0xADFE5A22FE1AD367ULL, 0xC93CBB325AD3772FULL, 0xF24942BB9D3AEBA4ULL, 
            0x63736CACC275D465ULL, 0x849546AA2B170273ULL, 0xB8E93E18B772C26AULL, 0xD47F3F301FFFF4A4ULL, 
            0xDA3702E57759F8DAULL, 0x02B3476A2FD2A489ULL, 0x6C140D2ADD54FB32ULL, 0x8136C67916D0ADA5ULL, 
            0x1C794CB7D49C6D01ULL, 0x00994E063285C271ULL, 0x83BC400A631BD706ULL, 0x2F3480E9417FE562ULL, 
            0x5E7FA2A9C9ECAE78ULL, 0xD7CCC8BD94558F8AULL, 0xB2287A04919BD686ULL, 0x7E5393D17E2708D5ULL, 
            0xF5BBCA8011643249ULL, 0x7156E506897D62BAULL, 0x1DFFE91DFD727AFBULL, 0xB22FCD369CE963E6ULL
        },
        {
            0x2421258867C8FD71ULL, 0x1CE13EFAF3AD323FULL, 0x546FE6BA99454EDDULL, 0x226244BAAF26FA67ULL, 
            0xEF54B0A531B20BA7ULL, 0x93A7CCCBAC0458B9ULL, 0xFD14BBCF8F66F242ULL, 0xF7346E11806DC113ULL, 
            0x9E55CA976A8FEC3DULL, 0x4307353DCB8328A0ULL, 0xA051970D83627AACULL, 0x687714E85229192CULL, 
            0x097B5FF5D39F01CBULL, 0x8908A46A34F7159EULL, 0x201BC25C733EF6A3ULL, 0x3178BB458B5956F0ULL, 
            0x551EBB74FD80779CULL, 0xBFF1B17EC05C7170ULL, 0xC9ED7BECF7ED59EDULL, 0xC8C241378C31AB63ULL, 
            0x9CF8E01AC484FAAEULL, 0x4C106220E4EF1168ULL, 0x98E94695FE28D3BBULL, 0x19574C84FCA6E98BULL, 
            0x8C5940767E3F73FBULL, 0xDCD51E41F34B8457ULL, 0x99F7DA26AB5A9D75ULL, 0xEBD5056371899869ULL, 
            0xC1490611C2BF87EDULL, 0xAF00140A92473E0BULL, 0xC2C415DE643E7AE1ULL, 0x425421983236788DULL
        },
        {
            0xB8D8F00A5BA7F7B5ULL, 0xEAC408D198A75E5EULL, 0x2F54C1A744A38A46ULL, 0xDDF16E9352536332ULL, 
            0xFD69AC007EB1D5C2ULL, 0x72643EFB0D673E7FULL, 0x0150248062572D03ULL, 0xBC9AB87C8FC7E575ULL, 
            0x1F2C1035A9D1F7ECULL, 0x2B7EF39E905FB8DEULL, 0xC97C38B3D20293B1ULL, 0x736D51A05CFFB7CAULL, 
            0x7FF95AC82D8C88F4ULL, 0xD6812310873B4DCBULL, 0xA63E911E185E2EEBULL, 0x963F4D63703BADAAULL, 
            0x1FBBEBB68661BB00ULL, 0x3B6EF952CA42DA7EULL, 0xA1DE6773473CD3D2ULL, 0x0D6A02E056301B53ULL, 
            0x076C4C2338B1EDC9ULL, 0x167F343BBDFDC3DCULL, 0xD79172342FDBDF85ULL, 0xC0BCC435E9813D58ULL, 
            0x59647115F2260A03ULL, 0x2D99A5976685F90AULL, 0xCA9E07EC4577F4FBULL, 0xB2BACEC782050746ULL, 
            0xC26EB6CD652B9892ULL, 0x7575DAC52248C639ULL, 0xFA87BA0FCDF14ED6ULL, 0xDA2A0E38C7427DC5ULL
        }
    },
    {
        {
            0xB1B8BE1D2BD5E120ULL, 0xE649F0BB7BF0ADECULL, 0xB79D5C6E198D6C5CULL, 0x24A6B284E6D7C142ULL, 
            0xCBCAADB2325DE387ULL, 0x7BDD6FBD6C973576ULL, 0xEC1CB6268EC5B9D3ULL, 0xE8CEDF3FD508B705ULL, 
            0x407FF2DADD01CEF6ULL, 0x0D01F2D20ABE071DULL, 0xA2BFAEA45480A9B3ULL, 0x9655A2D2A009B5CFULL, 
            0xB83CEEEC822F1701ULL, 0x42EC7C42685215F4ULL, 0xFD397FCECE8960F0ULL, 0x5C2F8EA625FB9A64ULL, 
            0xF295915AF920F5A6ULL, 0xA94339CB3265B26CULL, 0x7A7F0517D77B7570ULL, 0x98AD9A84F2F7A74DULL, 
            0x3EDA14E8C83C213FULL, 0xD2A4E7736099F0CAULL, 0x182C4DBBDFAFE0D3ULL, 0x3A758473E72F278BULL, 
            0xD5DB0BBB6B6EF457ULL, 0xE98F5CE2B9567E10ULL, 0xF0A02DCFE7A64151ULL, 0x7B66720A98B9A8AEULL, 
            0xB400B2739B222481ULL, 0x85E85FA9D67F556FULL, 0xC299A3A9FFFF536DULL, 0x6017C9C6FFFC616EULL
        },
        {
            0x6FA3C6D431EF98DAULL, 0x455C1F27A08C49B0ULL, 0xB444DD8B221C8851ULL, 0x95BDF12CA9A10ED2ULL, 
            0xFBE15662FDC1F73DULL, 0x86484D682A55CCFAULL, 0x9DF8F12068821D61ULL, 0xC96D2D74676B2B41ULL, 
            0x0D0A18442B2E132BULL, 0x3E6164009F72B205ULL, 0x4D4C1B02DF429495ULL, 0xFB42378751200660ULL, 
            0x79CE03C5CB189B88ULL, 0xD16A981BCE8F241FULL, 0x05B6CBE12F7869F0ULL, 0xEE0469C08F3AA3C4ULL, 
            0x1B8690ECB89B9648ULL, 0xAF7C4746210368F8ULL, 0x9517FECC7B510921ULL, 0x7B6223EA78CE4190ULL, 
            0x0FF2F4C120F504DDULL, 0x40E94D92FFD24EDEULL, 0x5F5A20110CB07BB4ULL, 0x4C1DDA928DD34C38ULL, 
            0x857CDCA2F4F18216ULL, 0xF2C335207387063BULL, 0x64DF97341DBEEBEEULL, 0x718EC096C5B87A2FULL, 
            0xAE364161BB8EE4E1ULL, 0x34F4C2A468D1C201ULL, 0x73873DF58B6F1A23ULL, 0x734F98CA43FE13D2ULL
        },
        {
            0x491C5EDFD38B0A7FULL, 0xBEBBAACC5CF3D2D3ULL, 0x5FB1C910245F4FD9ULL, 0x1C18F5EF3ACE2C75ULL, 
            0xA2AF50503124BE98ULL, 0xA9975418520F7E45ULL, 0x4684F732D59BB669ULL, 0x6F3F0AC79ABAC009ULL, 
            0x60D2C4F3594A6D77ULL, 0x7AFDFE2AC1F85E17ULL, 0x3FF5CD8A33ED0EF4ULL, 0x49D5DDF0541E51A9ULL, 
            0x136A01C9E7BE9CF2ULL, 0xEE0E91FDEF1DE560ULL, 0xA33EF595F6FAD095ULL, 0xE346853CC4E1CDBBULL, 
            0x3B31CD4771EE5CABULL, 0xD7C2C6166FC14CBBULL, 0xCBA751E300E2B062ULL, 0x863438F0F16F2C5CULL, 
            0x087C0F7A96C4C68DULL, 0x89A470CFCB0A4779ULL, 0x1732F06D6F194BAEULL, 0x04E1EE3CC529459BULL, 
            0x03951C39A40DD7A4ULL, 0xB995214BFE78329BULL, 0xBFC8687B005EA8ADULL, 0x692E593FD6A56C21ULL, 
            0xB69ACB6AA578EBC5ULL, 0x811CC63A28C25B73ULL, 0xABFB1F3ECC1CCD85ULL, 0x575710CBE20DC0E2ULL
        },
        {
            0x808E13462D8074E2ULL, 0xD5C490E489A5FA3CULL, 0xE582855A12A60A7AULL, 0x08C71A8CADD5290BULL, 
            0x32DAEA4F1C5CB4C7ULL, 0x345AE1EDB327EA04ULL, 0x1BCE1CBA9A31502BULL, 0xC51A2295E6A94890ULL, 
            0xD3524F4CD6CC77BCULL, 0xD12776C2B61CACB5ULL, 0xDFF70EF648C2905AULL, 0x09AC8D8DBDF66468ULL, 
            0x7EC9AB55DFD20FC4ULL, 0x534D7F9A865F52F5ULL, 0xA242816EBA43CAE9ULL, 0xE71F9489527DB9E6ULL, 
            0x8E215644A0EA9BA0ULL, 0xD408B40992E43955ULL, 0x339320A19B0A45D1ULL, 0x9896303ED8801BD1ULL, 
            0xF0B41C46D04BE1DBULL, 0x4C3A76FAF4BBF7A2ULL, 0xA89C46A2D1220903ULL, 0x658FA6A2D7FC21B8ULL, 
            0x0B3FCE47ADEC24D6ULL, 0xDD54958888C55D87ULL, 0x57329BA908958F3AULL, 0x61469DDAAB3042A0ULL, 
            0x650022DC0A733282ULL, 0x73DBA49CA2C685B8ULL, 0x80003A16293CD088ULL, 0x5E1348F759E01FC3ULL
        },
        {
            0x4D9FCDE600B06525ULL, 0x5B28E431080A1033ULL, 0xB867EBF9F0AD35E9ULL, 0x3BFC1C8C2BAB9E1FULL, 
            0xB14F32DA2698EBC3ULL, 0xA2056253623B01F8ULL, 0x56622AE4E4ADFEC3ULL, 0xAAEE5B32FCD4D463ULL, 
            0x2F1AA18A39528A70ULL, 0xE1EFB2C4B601FA37ULL, 0x35CBE34775CFE1B4ULL, 0xCD3E10C2F6451593ULL, 
            0x3785E724E0BA93BBULL, 0xE919B429D987A9E9ULL, 0x48299F6795EA7A27ULL, 0x0FC74AEAADA5E231ULL, 
            0xE7DF4A532C6256CDULL, 0x5EF93EE13C3068F2ULL, 0x2E55DE8CA662F0C0ULL, 0xBC0995408FD5341DULL, 
            0x36DD92DBCC90DC40ULL, 0xD2B26B2D48498B9DULL, 0x8468BF8B7F8DC08BULL, 0x984D4048C543607CULL, 
            0x4B8E7754E2248049ULL, 0x93C9EA96319AB70DULL, 0x9E8114907B9BA15AULL, 0x76460349081922CAULL, 
            0x579A33D948B6A468ULL, 0xC0241BFC5B8D961EULL, 0x2D0278CF0B57AD8CULL, 0xDF161C40DA17B4E1ULL
        },
        {
            0x403666F563FC38F1ULL, 0xE9DA417F6E7D8973ULL, 0x3F0D53FB16B0E03AULL, 0x7442035669AE1EECULL, 
            0xA5DF6C2CAC33E929ULL, 0xC13D35CD3EEA338BULL, 0x8EC552AAAB18E288ULL, 0x3491906A73A8DBD3ULL, 
            0x8C8A85C4740FDC31ULL, 0x46CD66F717EFF1D9ULL, 0x3A0F7B81733C1ED4ULL, 0x491233F512953B66ULL, 
            0x1F80DC1F9B9334BCULL, 0x163A0CEA655A5577ULL, 0xFCEDA49D44536A7EULL, 0x87D676FC8F818012ULL, 
            0x638D9BBCD1931B36ULL, 0xB62A89BD389029DEULL, 0x58AFAEF5833A9233ULL, 0x224BA3F98413741FULL, 
            0x981DABC4C49AC802ULL, 0xF10B41B4BB555E1DULL, 0xDDCDEE400A2519F6ULL, 0xF850A80C8EFE2636ULL, 
            0xEDF048F1820A9C7AULL, 0x92DAB0EF1ABE0C6FULL, 0x3B0D5737062E19E1ULL, 0xA99C9EAC8C8F57B7ULL, 
            0xE19F901A7617BFBBULL, 0xE1A61E2514F7ED6EULL, 0xA879E85CF7C46447ULL, 0x52F67709513D605CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseCConstants = {
    0xEB8C0CE023519F6EULL,
    0x99E103988768765EULL,
    0x438D576F2BBB5457ULL,
    0xEB8C0CE023519F6EULL,
    0x99E103988768765EULL,
    0x438D576F2BBB5457ULL,
    0x0E17271E01A3362EULL,
    0xA47480EB3D1F1801ULL,
    0x89,
    0xDD,
    0xD2,
    0x89,
    0x76,
    0x33,
    0x3C,
    0xCC
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseDSalts = {
    {
        {
            0x5E49698983512768ULL, 0x466F19DB6972DA19ULL, 0x09BCA76EE813214FULL, 0xEAFC9E36280A6D7EULL, 
            0x7DE6400FCE1471E4ULL, 0x83A2329C47BE46DDULL, 0x1040F35199D19612ULL, 0x5F59A5A66E5A08BCULL, 
            0x72315CEA65A3F1ABULL, 0xFC3AD93CE5FE1D4AULL, 0xE9A50199D472028FULL, 0xAB1275C4E5934F11ULL, 
            0x9A202C3D656D1EBBULL, 0x5D0083F0C7D0AE3CULL, 0xACB2289ADD1FDF3EULL, 0x940A4714B06D6533ULL, 
            0xD9D0693FE4070DD7ULL, 0xBDE47A6058D71988ULL, 0xD5602FA2453AD3B6ULL, 0x212E8C3482A60531ULL, 
            0xE17275FF594E5B8CULL, 0xB5454578552805B2ULL, 0x59F0EC5C578A93D7ULL, 0xCF128822D819D0BAULL, 
            0xD7BEABE16E6850E3ULL, 0xC429403012F7437FULL, 0xCF69055EE15191D9ULL, 0x55DEB3B768F2A46BULL, 
            0x65B045C92383CBDAULL, 0x1AB5C3E6D4F67E70ULL, 0x9AF71DD0DC1AEDCEULL, 0xFFE50974BEDC3EFEULL
        },
        {
            0x9EB8663A4F4BAA1DULL, 0x59EFF057417D9D5EULL, 0x4793D2FE6542455FULL, 0xD5A7DB1CD97DF296ULL, 
            0x623E47E79AB45B79ULL, 0x8FCB5BB8F69856F9ULL, 0x694A5EB1532F1066ULL, 0xD81D674D60C7F8BBULL, 
            0xF4ED0AA3E5E8183AULL, 0xBC0B0F63986A3288ULL, 0x3A2D78F207C6A6CAULL, 0x1B849363FBD158F5ULL, 
            0xE79F4509FB038653ULL, 0x8443B49E9111A7F9ULL, 0x3D4956B05B50A3B7ULL, 0x1A527F8B4EB27605ULL, 
            0x6B05055FA8AD28A2ULL, 0x6DCD7956ABBFA963ULL, 0x7E07FEA301B67394ULL, 0xE3A961A0A0E91E9EULL, 
            0x04CE3012C2A2D42EULL, 0x47D75FE888475F30ULL, 0x6429AE50D599332AULL, 0x7BD3E707A8209C67ULL, 
            0xC009B80C9C61CFD5ULL, 0x84E464E6D6667243ULL, 0x19F19B9457609E5CULL, 0xFD1F1E793E1E5685ULL, 
            0x297307A597DF098FULL, 0x38E993F750F30A84ULL, 0x0BD9A579C208E2C0ULL, 0x129B3F4F6FBB9FA8ULL
        },
        {
            0x483E49F35AC45A5CULL, 0xC4D628E220E81EEBULL, 0x91B0EE3916A54276ULL, 0x48217B34FAAB4ED1ULL, 
            0x63F718A80531D1F4ULL, 0x64779ECD6570ECA9ULL, 0xD8251885B441F0F9ULL, 0x57E29A5AF6425665ULL, 
            0x3C47E986F9F6FFE0ULL, 0x4B0EC91816529787ULL, 0x49C9C4774D199942ULL, 0x44C3446F72240C39ULL, 
            0x714B2D77DE1FF9B8ULL, 0xC4FCD5933B8CBBAEULL, 0x1908AE677FF33650ULL, 0x2EA6DB72D2A399A1ULL, 
            0x2E47C7EC8A66D1E1ULL, 0xF6C9DB77EBE3A2CBULL, 0x881CB1467A24A641ULL, 0x75867EF2D8FC8DBFULL, 
            0x994606A041D036C3ULL, 0x8F82F6624DCBEE8FULL, 0x68958296174EA595ULL, 0x1A89BEB60D56BFFDULL, 
            0x7E395522295D23D1ULL, 0x4B59C65292344B4CULL, 0xCA0849552B6A0A3DULL, 0xC931241B2D5030A5ULL, 
            0xB96B117247CBAB76ULL, 0xB84F261C2A080D56ULL, 0xB9906D11D6AB260BULL, 0x8FF93648292E7545ULL
        },
        {
            0xEA0E0D3F251A77C9ULL, 0xA6BBF0C6D7F48063ULL, 0x743AC38892958B43ULL, 0x220A1FD977213FA3ULL, 
            0x0E92840E8938BC72ULL, 0x7F52110B116839BCULL, 0xAC350E905A248920ULL, 0x36B35094DE24E6C0ULL, 
            0x200F426CF05B5554ULL, 0x0FF8191A8ECD6CD6ULL, 0xBA4140179360D148ULL, 0x6F20EC666BB06FB6ULL, 
            0x85C66BA9AE60F869ULL, 0x6EC2101FC79F0DBDULL, 0x1064699F08FC00CFULL, 0xDDEE4F6C71E28C48ULL, 
            0xC03C5B36F4321878ULL, 0x5BD9E9BFE677FC8CULL, 0x31FB9EA6D4A38332ULL, 0xA69B0AF83413D174ULL, 
            0x35935FBEFDCD2C0DULL, 0xE1E3DAE37657E6B3ULL, 0x7D69A4F7CA019114ULL, 0x3937819FF229A7FAULL, 
            0x1C929C5ECBD36269ULL, 0x03D41F4BB16B0734ULL, 0xA06104ADBD652E49ULL, 0xEF86B6C21AAFC0CFULL, 
            0xDD8A1807019FB2E6ULL, 0xDE93C2DC8111073CULL, 0x261E74570BB0401AULL, 0x3590CD4D09E5A733ULL
        },
        {
            0x2DF9F924E8F28A4AULL, 0x2BFAB38DC607E54EULL, 0x028C43CCB89627A6ULL, 0x217B0CE636D576C1ULL, 
            0x28DBD551D854CAC8ULL, 0x1A620C733901FE77ULL, 0x5410CF4D02913AE8ULL, 0xB7023C63C2EF01BEULL, 
            0xDDE4F8C71D403D30ULL, 0x58D56BB8703A1328ULL, 0x07B82F18CE6CE995ULL, 0x34E5F2CA241E4D32ULL, 
            0xE99A6B4653A536FBULL, 0xEAA39FC164F71579ULL, 0xE0A64C150A5CA973ULL, 0x8B84FAD5128D0280ULL, 
            0xB3FE7876756DDB68ULL, 0x960C1335D06F9C94ULL, 0xE1DD12B62925F0A5ULL, 0xE2047E2285D21C32ULL, 
            0x4656AEA4787AF2A9ULL, 0xB6604FBC9759387CULL, 0xBF0BD1362883DEBAULL, 0xD9FEC1B70A03DDFAULL, 
            0x9C6829CAC6A19F6DULL, 0x27B8905472993C60ULL, 0x9C69DD0DBCAD4E56ULL, 0x5E725BB8A3469A02ULL, 
            0x043721F2838D32DDULL, 0x756D5C8A5F494C80ULL, 0x929E0039F50C8BC4ULL, 0x072FB39C0E6A3E71ULL
        },
        {
            0xD0F61DA6991327E1ULL, 0x630FBD92B1318991ULL, 0xA4BA6B9BAD02A6E2ULL, 0x39C333252C3CB167ULL, 
            0xD40D3B69C93FFADBULL, 0x25AAB9622C6ED237ULL, 0xB1510CF38A479701ULL, 0xA7BA74FDB070E491ULL, 
            0xF7E0B3CF41BEE189ULL, 0xC688C22EE033F43BULL, 0x529646943193F141ULL, 0xCA881A6744BBD21AULL, 
            0xF85D9E98C115E727ULL, 0x8443B7DF821CAFB8ULL, 0xCC3139A74A084B2CULL, 0xFB18A112A23A970AULL, 
            0x6F8AF8F755D63BA2ULL, 0xB1F215369D7C8ED4ULL, 0x155380CA90F847B4ULL, 0x2FC70523552F262CULL, 
            0xD39281118FF46F71ULL, 0xC4106D53AADAFDB4ULL, 0x36556CC4FA62BEBFULL, 0x000BA6E5A0B7E6DCULL, 
            0xBE12A5FA1322B1C9ULL, 0xF6A5FD3C04B1E56FULL, 0x3FB2C9379F9C0C14ULL, 0x2C1EDF01B63C0DBFULL, 
            0xB3D26E1432601384ULL, 0x9ED5A067D0CE1375ULL, 0xD7996FED5BFB55A8ULL, 0x87D3941ACFEDD48DULL
        }
    },
    {
        {
            0xDE3FDC30E754790FULL, 0xD936065B2BE1C310ULL, 0x906509D07A47DDADULL, 0x985E78F34B2C27FFULL, 
            0x6A331D41035F67CAULL, 0x18BBFA3525DD32C4ULL, 0xFD26969E1D9C1C53ULL, 0xBE883BC20BDBB3DAULL, 
            0x01E6D01A7D29C0E0ULL, 0xF79CD79052EEA746ULL, 0x9F4EA5F220CE90DBULL, 0x5F93E1CA9FE67C05ULL, 
            0xA8F120C33421BC15ULL, 0xE355BBFCC50AA9A3ULL, 0x9E37CEA9429DFC6CULL, 0x38ACA31C3C696179ULL, 
            0x65381B28A6E54B7BULL, 0x55A9221338B26F0CULL, 0x51568D2046F0BB08ULL, 0xF656394D5BAD1FCDULL, 
            0x42983CAC3C502DAAULL, 0x7643EA5C4DC588F4ULL, 0x0747F7545F6CAEC1ULL, 0x2E86A0C109F0E6FAULL, 
            0x787CD30EA7D4F7B7ULL, 0x171AB40B69DE6F1DULL, 0xBDDFD7FF9B4B369EULL, 0xCB80E66CEB30BE44ULL, 
            0xB39019C41E76A44DULL, 0xBE4D544F4D636479ULL, 0xCE157386C56B08E1ULL, 0x01D52EA0F6D6E17BULL
        },
        {
            0xB955AAA1B80F69BEULL, 0x995C7F939FA2B755ULL, 0x1A0D45F39D223534ULL, 0xC9A03AED134355F4ULL, 
            0xA8B46DB082FABA56ULL, 0x847D70537537297DULL, 0x5B98A712CCE4E955ULL, 0x188C5EEB99930AE9ULL, 
            0xD3584DA655FAD7FBULL, 0x19D162874BF11514ULL, 0xD3CA583C4018378CULL, 0xE30615A07948A6FEULL, 
            0x61608F478CFC2A85ULL, 0xE5B691575E6C23F6ULL, 0x87DB68354037EC7CULL, 0x5DC2464428ADAA07ULL, 
            0x2AEDAFEB3BC45CD8ULL, 0xED0ACAFD3D2493ABULL, 0x20C52865C95597F2ULL, 0x629555F31ABF3FC9ULL, 
            0xC218DD97D9C933DDULL, 0x746556F56BB882E1ULL, 0xF0AFEB562CE6961CULL, 0x1C8CAEC2BC410E48ULL, 
            0x455A69EF46BAF67CULL, 0xB0E2FEB91FE9CA77ULL, 0x1711D50F5105009FULL, 0x728C90B58232EA1EULL, 
            0x1C5A955BD9A3DA8BULL, 0x57C1EFF9E3D4FE8AULL, 0x4639A49F41451805ULL, 0xBF20F2BCC5517799ULL
        },
        {
            0x432AA4B3EA04F9DAULL, 0x2D0EEFAA6EBB87EDULL, 0xB6E4D9E928B43748ULL, 0x5E33A7B8F4BE30A9ULL, 
            0x1841334429ACF5D8ULL, 0x531842F388228DC5ULL, 0x1A00AF8BD1235147ULL, 0x3F2C54E94666BC5BULL, 
            0x1FD96CD889617DA7ULL, 0xF51B498760CD8F67ULL, 0x5C53BC301AD2BCA8ULL, 0x712DB204E7A2CA00ULL, 
            0x044EA16333B1B56FULL, 0x335A09BFE01D584CULL, 0xC14BCE606D9BD7C6ULL, 0xE9B8EB64A30CC65BULL, 
            0x84C560BD513AD0F4ULL, 0xD2D3F6AC4AB27082ULL, 0x7F5E8A671913F25DULL, 0xC1B1598A67726E6DULL, 
            0x60E4CDA755844013ULL, 0x8816C4BB618A9347ULL, 0x343C296761006D63ULL, 0x675FFFA7D347727BULL, 
            0x71B0205BACED6517ULL, 0x76B065F2AEB18D0FULL, 0xB155B400B8416BAAULL, 0x892CF53DB39A4C5EULL, 
            0x40DFB4A882DD665BULL, 0xB7979E2E8DA8E541ULL, 0xF04F950DDF974627ULL, 0x2F11F5D739345568ULL
        },
        {
            0x0AF355D9E4EB9EEBULL, 0xFD965F4E62B91F95ULL, 0xFE975AA505DA3BACULL, 0x589E6876763271B6ULL, 
            0x1C36390B8E3B7463ULL, 0x6717C3ED24DDAB83ULL, 0x4D982E4653C03E47ULL, 0xF4AB73CEE5095F0CULL, 
            0x6B064608A63ADB45ULL, 0xECEDF7C871E63E73ULL, 0xCCFF1A2972CE4B7AULL, 0x5FBCBEE46E4F83CCULL, 
            0x95170D08FCB5BE24ULL, 0x681E943559304C96ULL, 0xCC60DE5C31F8CD03ULL, 0x8BB446CF4D2D3F48ULL, 
            0xAD8D79185DFF3D38ULL, 0xF389C1649CABE0C1ULL, 0x1A63D1FC6A5E5FF9ULL, 0x2F1DB88191379B7DULL, 
            0x651B5F228DC81313ULL, 0x8BBBE3CD207435A4ULL, 0xE1BFDBBD8201B2A3ULL, 0x2EEF550DD8416E8BULL, 
            0x6562DA701876F492ULL, 0x3DB91D53F13A6321ULL, 0xEF5736E3BA176559ULL, 0x5E2A01F444CBB78FULL, 
            0x03AD858963237139ULL, 0x3D6DB7D448160314ULL, 0x52BE11B34F07B087ULL, 0x912C4C592D8EB872ULL
        },
        {
            0x03B6CCC6BD09D865ULL, 0x7D8CB5F3B21F60B6ULL, 0xF601B8A8507DFEB1ULL, 0x668E94786EAF6EF7ULL, 
            0x876FE7FAB4586264ULL, 0xCA9F358FF279AF60ULL, 0x20ED99B0FFC61A4AULL, 0x7334FCBC4B5DEED6ULL, 
            0xBF05E06B7ECA6A43ULL, 0x1C9DA157FFE80C9CULL, 0xBA803C857DEBDC85ULL, 0x7436D488030F322BULL, 
            0xEBC789F2ADBC11EAULL, 0x89D099034850CA41ULL, 0x5BB7B8E9DC446851ULL, 0x30AA1462EB4157E6ULL, 
            0xE91A704C6F11E184ULL, 0x674FE0109DD8FBF0ULL, 0xC4832B148C67960DULL, 0xDA446541D560F08FULL, 
            0xA063744A7AE4246CULL, 0xA17DABDBFC8275A3ULL, 0xCC04359BA47E9DA5ULL, 0x99DA7B6BE8C86E33ULL, 
            0xEF30F129CB29E4F6ULL, 0x6E8AC99EA207573FULL, 0xCDB1967787A99ADDULL, 0x310251D47A37177CULL, 
            0x607F79EF7DB4686DULL, 0xC7C59A2AE1761405ULL, 0x7C3F7669DA54BEC5ULL, 0xB362D1CA4D213807ULL
        },
        {
            0x265E1EF8F12239ECULL, 0xB13F26776FA052B7ULL, 0xA8362DE270810BF4ULL, 0x5D34411EC5413659ULL, 
            0x26C880CE700286ABULL, 0x28300E7236B857CDULL, 0x235570165274461CULL, 0x55BE4032B041F393ULL, 
            0x4BD6932698C373FEULL, 0x67E60E993206045FULL, 0x58C727684FF14D07ULL, 0xC42AD524E23D1244ULL, 
            0x1CC089B210A03F07ULL, 0x5DF5B7DEC8A63B62ULL, 0x1746B234B5618A8DULL, 0xE2F0410525A5B92AULL, 
            0x6F16D08CF45751C9ULL, 0x1936C6C629152A17ULL, 0x1297C2D9D3C954E4ULL, 0x8227C40737F41737ULL, 
            0x1B5E5CCF3EC279FAULL, 0xC79AFC3F1B46D459ULL, 0x9F899060CC523B4DULL, 0x1F166C120EE6F8C5ULL, 
            0xEF0E3D96AB04E264ULL, 0x2A5BAF6F566625A3ULL, 0x687F42F98913BF0AULL, 0xB14565A7B1D3D0F0ULL, 
            0x6B93D8DC5EC94A5FULL, 0xCA1B0439463E8E1CULL, 0x892C30B175C4447EULL, 0x32354A60BAAFEA20ULL
        }
    },
    {
        {
            0x2E3E6C728298B3FDULL, 0x9CA753E7DB916F82ULL, 0x9AD10C4778147D77ULL, 0x2ED8B3ACD4A2C89BULL, 
            0xEE1FA5ED734D56DEULL, 0x5741C16776D9E688ULL, 0xDAE378EF1F1F4637ULL, 0x969EBB8294B68BE0ULL, 
            0x083706A301123828ULL, 0x0C92E08B3C195438ULL, 0x9BE631EE25278549ULL, 0xFAD4702B892C2BB1ULL, 
            0x7D5CE571DB9E8861ULL, 0x1B6ADDC6DAA09E3DULL, 0xBCB76CCFF92063D6ULL, 0x345F7DD2D6E288D8ULL, 
            0xAB29ED3378EDC741ULL, 0xDE5DABE04F218358ULL, 0x714F85FBCC1F88A7ULL, 0x484107800DF065FCULL, 
            0xA5E16052B5C08CBAULL, 0x4EB3AED3186C13EAULL, 0xA97512F8F860D209ULL, 0xFC14AB1703BC828BULL, 
            0xE6551F93463F5FDFULL, 0x8102E77FFB3993F2ULL, 0xD19BEAC673F1C913ULL, 0x941B8A539E182456ULL, 
            0x506CA22DC0C84CE0ULL, 0x8EE31D3AE0B0F1EAULL, 0x9D7DCD966E0B886DULL, 0x184E52495178680AULL
        },
        {
            0x99C397674A7FD8AEULL, 0xB89A4976F628EDDDULL, 0x30940B69F90F3508ULL, 0xCC1BFF49970D1F23ULL, 
            0x7E730B2EBBE032DDULL, 0x169EDC5ED97F6EC9ULL, 0x1D2DF0649E3E7D9EULL, 0x492F0130C4DFB697ULL, 
            0x20BBF69B9BE4B192ULL, 0x46432670B853CF27ULL, 0x926413413F8143A8ULL, 0x03CA06BE1A5E5686ULL, 
            0x717C55314FBBA03FULL, 0x3A456B60C1DFBCDEULL, 0x244FDF13D9284528ULL, 0x3DD3F580771CB3ACULL, 
            0xC55418325E3E7EA2ULL, 0xEDF638423928A78DULL, 0xB4E6DAAD5C567917ULL, 0x34156CFB54212436ULL, 
            0x1431CE5B743CED64ULL, 0xDDD953087CE2946DULL, 0x22D177543B8A3C7EULL, 0xDB0DC999E8638CDDULL, 
            0x23BB7EC183731ED8ULL, 0x0AE7667D3A10AC30ULL, 0x52109798EB4CFC90ULL, 0xB330C5E5BF1E0D1AULL, 
            0xF0F571871E266024ULL, 0xB0DF9D10DAF6AF64ULL, 0x1DE08F9FF5308716ULL, 0x354CA265EF5854D0ULL
        },
        {
            0xDFA15A2DA895CB37ULL, 0x6A3ACAA985C2A1D2ULL, 0xB41334ABD9CA31A1ULL, 0x0B41CD52B730A168ULL, 
            0x9384B925FF684291ULL, 0x1C09CEB325953A47ULL, 0xB98A3A58B39AA59DULL, 0xA11F14A3FBD07427ULL, 
            0x3F38C2D41C5D8B5AULL, 0xE2E6D2490BA30341ULL, 0x68AEBF7809700595ULL, 0x65C3CD3A681426B7ULL, 
            0x0B344808D4AD705BULL, 0x305A95CFE445627DULL, 0x57D6E5DF07076807ULL, 0x0229331B609FC76AULL, 
            0xC40EFF5C3DBAA8FFULL, 0x1393652292F3C3A0ULL, 0x1A7243D617C60037ULL, 0xD05AE485E9BD1525ULL, 
            0xC284AB8069957E0BULL, 0x35BFAF50380074C7ULL, 0x9CA7A7F2D76CD012ULL, 0x5D15C5ED7E535CE0ULL, 
            0x8583D707427A9F42ULL, 0xE775D3C85C3927CAULL, 0xA9B55AD6C7EF9F17ULL, 0x5E5685A991D37001ULL, 
            0x37C5EC9E06EE00C3ULL, 0xC6E2E9E3A4C77831ULL, 0x4F4C9DEB0AEEC670ULL, 0x53061295D7DFF4C7ULL
        },
        {
            0x40F1C9B2647D6AE8ULL, 0xFE3C01C4600FB168ULL, 0x382BEB4EE546A380ULL, 0x7BC41B40C5411174ULL, 
            0x001207447EFE6D9AULL, 0x87CEAD8E9A613B1DULL, 0xD066F0AF27AF2580ULL, 0x1E7DDD3178F67EDAULL, 
            0x3E860DBD2967C3FFULL, 0xE612D201AD3F5E63ULL, 0x5D6E48BEB2561D35ULL, 0xA6DB9582D7AA87DFULL, 
            0x9AA4203A3D10C194ULL, 0x0BBF63A5BC47D9C4ULL, 0xCD2A285A7498FDC7ULL, 0x549DCA1A4612FC46ULL, 
            0x18C85054F2C77C8AULL, 0xEF4EF44044D9F98CULL, 0x0C474EF5D37F72A9ULL, 0x4F946A6D9ACBFEF3ULL, 
            0x21F550297AF04801ULL, 0xA3ABAC630801EDB2ULL, 0x4F3D752928B40341ULL, 0xB24A33304A8B780DULL, 
            0x2C142FB465F8BCBDULL, 0xB95235CFEA50C22BULL, 0xDA144508A348BF44ULL, 0x16B46CAE765BE9BBULL, 
            0x2A8811FD7A291C23ULL, 0x1A9A34EA761D66CDULL, 0x893C9073F16B6926ULL, 0x504E2F6AB09E0FAFULL
        },
        {
            0xE4DA8340639C4385ULL, 0x1C3C85CB8B3AF6FBULL, 0x4EC0551BAF64DAA1ULL, 0xFA134BDB7846612EULL, 
            0x1AFFEF918475AC73ULL, 0xA3AC3866F759F400ULL, 0x10C02AE88351B980ULL, 0xE523ED91A8743443ULL, 
            0x610497EEAE859E92ULL, 0x4E0B62532C933CC8ULL, 0x955701BD0BF388F9ULL, 0xB9B298312D11E663ULL, 
            0xE9B24B2BB7DB7567ULL, 0x627356E6934151ECULL, 0x5E2282063DC2FAEAULL, 0x9C6F4F82DD82E264ULL, 
            0xD68CEF50A4FBC530ULL, 0x98AE7FA62A26C0DCULL, 0x441C4DA9423EB921ULL, 0xD23C3BDB02E58186ULL, 
            0x6CAE5EBC28B046A1ULL, 0xD4C8F5F7B7AB71D1ULL, 0x8C089DF121B38BF8ULL, 0xC929A32A3302AFCDULL, 
            0x1C396AC2817AB9D8ULL, 0xEEDC0BF103F6E391ULL, 0xE8EFD480AA5487E2ULL, 0x193C67885AABE926ULL, 
            0x6B3F1CD4CFBC4F8CULL, 0xB5151155FEDEE857ULL, 0x0BDD87AC8ABF1E27ULL, 0xCBF608B9C74C8967ULL
        },
        {
            0x6EC7D71DEC143963ULL, 0xF1CE5FD00B23D332ULL, 0xCBC491D1FE4CC88DULL, 0x9C8075C50ECE03ABULL, 
            0xFBDDFEFC68903FFFULL, 0x18F8F7287EDD0E29ULL, 0xCB4986807B20D18BULL, 0x39EA5013B0723D12ULL, 
            0xA55F8BF56E2618CAULL, 0xC9CD1AE17DFE2E9FULL, 0x28C37C6DBDE4FFE0ULL, 0x83E7E53FF65DE53EULL, 
            0x9EE8E5092A507027ULL, 0x21AEF974E1B975DDULL, 0x83876809E785CC33ULL, 0x064AFF33448F2CEBULL, 
            0x4DC25A04B9263C84ULL, 0x3E35455DB449005DULL, 0x21413982C8BF46B9ULL, 0x0B3E2009BDA3CEBAULL, 
            0x1EB4A74C147BA390ULL, 0x10850D441D9ED055ULL, 0xDCF279F03F612B1AULL, 0x783552746DA9C49FULL, 
            0x39E330BE58DD917DULL, 0xA68E7B260C09B44FULL, 0xB71975FAC7D357D7ULL, 0xF3A382CA0F6990EFULL, 
            0xC1041D151E7B5A3EULL, 0x5B17F8AC82C059CAULL, 0x068DCB7893709D71ULL, 0xD6479A15C9A101F6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseDConstants = {
    0xFB757C728A07DA5CULL,
    0x742D8C4B4EF2567DULL,
    0x156182B0ADDA2CECULL,
    0xFB757C728A07DA5CULL,
    0x742D8C4B4EF2567DULL,
    0x156182B0ADDA2CECULL,
    0xA791ADCB56E8206AULL,
    0x96588D002BA2A0A9ULL,
    0x35,
    0x56,
    0x2D,
    0x84,
    0xA0,
    0x6A,
    0x8E,
    0x8F
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseESalts = {
    {
        {
            0x7D819F1EBECD4E1AULL, 0x87ACDAD314100798ULL, 0xC31A60D5494A473AULL, 0x60E7013729A20526ULL, 
            0x7A5A7F2087D22093ULL, 0x0CC204F3587E1B0BULL, 0x89593C39AC96C59BULL, 0xD45AB752D110F8E8ULL, 
            0x8C21C43E211FD7AFULL, 0x6F33245CA544A1CCULL, 0xC400D11A787F9520ULL, 0x430F6B6972CCA588ULL, 
            0x0B3BFC5A446EFB5DULL, 0xBA2AED5E625916E6ULL, 0xC2752F7F54824051ULL, 0x26CEF7EFB788B467ULL, 
            0x2AFA30850C6C89FBULL, 0x71D2CE1B05BFD62EULL, 0x4B3B32D19C54B418ULL, 0x576691B24E2ED4A7ULL, 
            0xEC159E1198FB5527ULL, 0xD838E45C235219D8ULL, 0xBCED582D72EF963EULL, 0x95E444CD688002DFULL, 
            0x71B544D21B22B254ULL, 0xD17149FC120BBC4CULL, 0x49A631F79A34D236ULL, 0x358F5108AE63019BULL, 
            0x0CD11003122832CFULL, 0xFA5EEA03BC479BFBULL, 0x0BCDC1C08636246DULL, 0xC172922B2FFC26E1ULL
        },
        {
            0xFDA94901F5B4F1F4ULL, 0x2E1C6E96B07EC958ULL, 0x9EBF495796D5D576ULL, 0xBB4E65D3C3554765ULL, 
            0x053575073D535861ULL, 0x62C747293322BE55ULL, 0x8BDF357CDEB32E21ULL, 0x77D86593ADE0AE59ULL, 
            0x4DBBA76F734E20DBULL, 0x0BD4919EFD2B6F43ULL, 0xCA06EE56C08F36CAULL, 0x8E7BD0052D13DE53ULL, 
            0xD4A37F03A5BA798CULL, 0x136470BB851255ACULL, 0xE93E9620ABEF39C1ULL, 0xF4F8EFD5850678F6ULL, 
            0xBCDBC05758E65D3DULL, 0x241884B3BA28FB0DULL, 0x819B6E9B6F388CF6ULL, 0xC2AF175D413B004FULL, 
            0x5806A301FBF19E0BULL, 0xBAE6D4E0CEC1CDBBULL, 0x8E955DD231B610F4ULL, 0x9585BE96E7DECCD7ULL, 
            0xC864BFCB3F108ADBULL, 0x7264096469ADB267ULL, 0x20E0AAFDFCFE7BFCULL, 0x3D09CA6B063CC359ULL, 
            0xAD701D6C62213017ULL, 0x168FF6321D5E5A66ULL, 0x86BA3E545FE8D628ULL, 0x7A1D15F430F341F4ULL
        },
        {
            0x990AF1ADDEE0117EULL, 0xC438FE106CA23220ULL, 0xBD6A8052CA35BDB7ULL, 0x18CD707455783B43ULL, 
            0xE3785BC81AA89528ULL, 0x103EF38272407EB6ULL, 0x7F14FFA4F1BF11FCULL, 0xC0824F03E0CCD7CEULL, 
            0xA151EC91A6836C53ULL, 0x193CBE5BD49D2A75ULL, 0x851B41DAE86B75DAULL, 0x916A889CA34FB8E6ULL, 
            0x75D63FCB5939B9BFULL, 0x135A9B61EFF637A9ULL, 0xCD56E4D0BC1088FBULL, 0xBEF139413820EBFBULL, 
            0x2598B7ABCBB28EC8ULL, 0xE41AE509DB73F4A0ULL, 0xA4D8B09CF25854C1ULL, 0x6C582E523AE72705ULL, 
            0xE90ED94985B51080ULL, 0x261008BBE387C343ULL, 0xDCA2E3005931B87EULL, 0xDABDD604BD259615ULL, 
            0xE8C112DDF0F9A6A5ULL, 0x49CA6E086F043926ULL, 0xEFCDA9B51E1BC5C2ULL, 0x8B311485A46B124EULL, 
            0x0CA4B03E4D28735DULL, 0x1FD6768109C41A9DULL, 0x0A38ACDD6DBD2509ULL, 0x8B27073C57B25EE2ULL
        },
        {
            0xA85C302C1AF5F381ULL, 0xD6944716715415B5ULL, 0x4C8DBDCAA7B72043ULL, 0xEB71F6F7CE9D0815ULL, 
            0x7921957EA43BA4EFULL, 0x59E71ED54FF25D25ULL, 0x3539A6CACBF30BA4ULL, 0x4F8539ED63BE5976ULL, 
            0xD2CD4F43DED61DEDULL, 0x83948913916EED37ULL, 0xDC2DBE2680901169ULL, 0x6BF62E544CDAF5AAULL, 
            0x66B69C1F439E150AULL, 0x82FC8113E317D14EULL, 0x9D1D572433D17D23ULL, 0x8FB0FF392FDD5360ULL, 
            0xDE2E220944C680A3ULL, 0xB962A8205A0000AEULL, 0xC163CBD6484EE16FULL, 0x6755A9CA430A9D26ULL, 
            0x3FF71DD082A2A5E3ULL, 0xAE198FC57749CBE4ULL, 0xA50703F1F1B98F19ULL, 0x89F8FA4F884EF3E3ULL, 
            0xDC7B447A5979D451ULL, 0xB1E916A7E25C0897ULL, 0x2024B4CED5EB0C41ULL, 0x9F451A792B48FC43ULL, 
            0xA621DEBC17BA8461ULL, 0xA9C2FD4050C886A4ULL, 0x3E0BAEEBC97E9737ULL, 0xC7536951A602FB8DULL
        },
        {
            0xB8575B8ADCDE14C0ULL, 0x303636544ECA91EAULL, 0xED560105C5B6ED7FULL, 0xEB755FDD5C4F4661ULL, 
            0xBBA4D3AF1AAC1EEAULL, 0x9471D626AB646277ULL, 0x748E2F9E5A0129FCULL, 0xD11D59AAE7FD5C39ULL, 
            0xA84BB0E00AE33ECBULL, 0xC53EDFF9EA64251DULL, 0x70F3276694552543ULL, 0x5C73394B81B38A4DULL, 
            0x8F570A36BF83EE42ULL, 0x4646E17571DB9D41ULL, 0x6C2DA0998387C2F2ULL, 0x1DCCF56329F5B062ULL, 
            0xF2BB25B1F3ACDE83ULL, 0x4B416C6BE5684F70ULL, 0x8B849637A1B2E35CULL, 0xCB60982CFB378861ULL, 
            0x19386EAC1912C6F8ULL, 0x3CB163B9B9705696ULL, 0x675CEC2E3A46F10DULL, 0x21205598E1AF7B9BULL, 
            0xB869062B93194BCCULL, 0xA56AF450F46F9F12ULL, 0xEA9B2C62E6911C88ULL, 0x8B1F2A74C4469D75ULL, 
            0x968D70EBC400E061ULL, 0xE30F14D2DA9FDC85ULL, 0x8CFD52F01C89AA52ULL, 0xCF2A23F93CBC78F0ULL
        },
        {
            0x408B167E97E99FEBULL, 0x5C2FED005EF70219ULL, 0xB4F4FFACB657E659ULL, 0x640D31C60D934DDCULL, 
            0x529CC2195D907E56ULL, 0x11E338BFB6981619ULL, 0x7A5883A13FDDE2D1ULL, 0xAF30375CB2676158ULL, 
            0xC02224517DBEE370ULL, 0x7DBCD5F8E2536182ULL, 0x14F43DD2FB616D86ULL, 0xD48DF27B0D6A8B75ULL, 
            0x90C6CDA60D5FECAAULL, 0xC29EA6287DDC913EULL, 0x64312A0B644BB994ULL, 0x5F52D1D2BC3F8413ULL, 
            0x1C4D4977F24CB7E5ULL, 0x4173CF2FA924853EULL, 0x362B53E2A2AC7828ULL, 0x1724A8AF2FD26FA5ULL, 
            0x79E5DA3780FAC9C7ULL, 0x87F84161081AD1E6ULL, 0x64E624EEBFE95083ULL, 0x499888A2AAD646D4ULL, 
            0x32F57E7E2766FE84ULL, 0x79D58E95739E032EULL, 0x6801EDFE075ECE54ULL, 0x8FB9B0AE51AE9420ULL, 
            0x464DC41BB8F9EE40ULL, 0x95ECCC13ACBA07DDULL, 0x4FF9BC84D8F01430ULL, 0xA6BA6AB92B9C0CBDULL
        }
    },
    {
        {
            0xC4386CBCB6D58113ULL, 0x3B279F16861CDD88ULL, 0x22620EF4274D28B5ULL, 0x9CADA05CD7326FDEULL, 
            0x12AD3DFEAC88D6F5ULL, 0x1C3AA52DD10366DAULL, 0x51712A34A77DB2FCULL, 0xEA39DAD135F09A48ULL, 
            0x59179C0E29D11BFFULL, 0xEC7BEEA852C91CADULL, 0x7E812C6174717236ULL, 0xC97B9C37AE10A68EULL, 
            0xAA472480A348BAF8ULL, 0x7803D4A8FD7C862AULL, 0x1968E983AF37C7EFULL, 0xDB8A050370DF48FBULL, 
            0xF5C5C21C9A9BB5FEULL, 0xAC0FC054E605C54EULL, 0xE044C290F8E2B45BULL, 0xCC54AE8B81A7513EULL, 
            0xE6CD7233489AD859ULL, 0x3889C2F8AD9E302DULL, 0x04C91F641F8DC26CULL, 0x7FE792A2F6BA36F0ULL, 
            0x43AE6D945A6C64ABULL, 0x8D7AA7E331001A2AULL, 0x1B18AFD62332FFD9ULL, 0x295F24DB7965EB99ULL, 
            0x0EBB4CAD5127E70BULL, 0x17F5455E1DCD6C07ULL, 0x1ADE7624EB7606FDULL, 0x213ECAF14543A35DULL
        },
        {
            0xF9F19F7A579EB720ULL, 0x4E108DD51674452EULL, 0x4AFE4F0CCF5CB4EFULL, 0x5F30C6E561B9F385ULL, 
            0xB7507BCA681AD4F0ULL, 0x31F3AEDEAA51B045ULL, 0x9254A419C69768EFULL, 0xCAE5D72C5F3370AFULL, 
            0xADE99DC435254EEBULL, 0xA9F51BB1C87B2B47ULL, 0xE032AD06AEB0C872ULL, 0xCC755DC1CFFAF5D8ULL, 
            0x13D412E6D1982EB0ULL, 0xBA5F76F13F0ED1EFULL, 0x491E1407FADEE11DULL, 0xD16C6988E629FDE9ULL, 
            0x03E3C5EE5FB47210ULL, 0x4673DC75E5B07D23ULL, 0xE32F0035545DEE8FULL, 0x78655231A95C0858ULL, 
            0x428670584E2B57F2ULL, 0x72004323D8904100ULL, 0x752B3BBEC2FA1133ULL, 0x253B40FAD5B3FDFCULL, 
            0x7F2A55506CF4D9E2ULL, 0xA89679758C39791FULL, 0x8B57DF78CB1DF5CBULL, 0x9BC9B6E662CEBFB3ULL, 
            0xC15FFDC76796056CULL, 0xB131FB68D8C6C1F2ULL, 0xDF953B95DD7038C2ULL, 0x725D4D0190E9F133ULL
        },
        {
            0x91348F5F5C32436FULL, 0x59E5F1355DC8EB4DULL, 0xC1F44E8B2C626B79ULL, 0xF1567AC9841D3BB3ULL, 
            0x862D08C62E67E8C3ULL, 0x76E00DE2E243DB4BULL, 0x4286200591610662ULL, 0xE912F7EECE6A1865ULL, 
            0x3F0611E34F2032EEULL, 0x46218CA88C2239CFULL, 0xDE44FC25B6C354CCULL, 0x8320F61FA7A4D0CFULL, 
            0x94CE46FAE9EAEE52ULL, 0x65D2D4612C9F7697ULL, 0x4D3C40CCB45CA915ULL, 0x9CC4108B7721C93FULL, 
            0x531992B0C41E1449ULL, 0xE757FF63C8B73C81ULL, 0xEFC267C41458FBB9ULL, 0xD0337B2D25150FDAULL, 
            0xBE25175442C9E213ULL, 0x73F8F8251A7FF8B3ULL, 0xBDF06460475B2D26ULL, 0xD3BFAD8BD87F2FEFULL, 
            0x5501F5323A72C703ULL, 0x283CE89DA25EA541ULL, 0xEB37782C174B433DULL, 0xA6E698C10E15731AULL, 
            0xFFBC042D7BCCC547ULL, 0xBCA3EBA5C245086DULL, 0xCE44B5CCB3D2404CULL, 0xBA4C26C92AF31D35ULL
        },
        {
            0x48C2C038698FA5D9ULL, 0x01BB79A536F331D1ULL, 0xF76B68FABF1A9A0AULL, 0x97B192F93217A9EBULL, 
            0xDEAD95C60E68E4BDULL, 0x56366241A8712D96ULL, 0x7E2B3FFF487D8C30ULL, 0xEA1E2876BBA01FEFULL, 
            0x7D303E61DAE4C9EBULL, 0x985FCC40753A29C7ULL, 0xD7E05F97741A19D3ULL, 0xA53E09FC654905A9ULL, 
            0x7000FA05628616DEULL, 0x9691FC4A28FF87B3ULL, 0x47C0F3BE16BA883DULL, 0x9A0BA6B7978BC74EULL, 
            0x4C499CAD2692033EULL, 0xA447D87983A82AD5ULL, 0x7B0830A1234D276AULL, 0xCF1775E5DD0C3DA1ULL, 
            0x1BF1D0A1BDE2CE8AULL, 0xC223F21358A8A823ULL, 0xBE558EA7E95FA486ULL, 0x2EA7DA59373652B4ULL, 
            0x4404247FEC20BDE0ULL, 0x8B53E39D170175A7ULL, 0xEE0F3127993AD600ULL, 0x68429B5438E45E52ULL, 
            0xF241EB86DE5D1837ULL, 0x610455F91F3A2BA8ULL, 0xDC1F48D3E716D7ADULL, 0x3644FF214ECEF971ULL
        },
        {
            0xDA238DEFB1603E2AULL, 0xF7441E02BC20BBA4ULL, 0xA999BE91C055AEAEULL, 0x95DC1A43F357BE8EULL, 
            0x9C88F8F2FD0328EBULL, 0x38B833DFAE33255EULL, 0x6A5947295F6D431BULL, 0x83B0FD6937D9C1B2ULL, 
            0x6C04B34BF86B43ADULL, 0x068C367C85489F3CULL, 0xF2705B3B81E5D10EULL, 0xCB2555E266ABCF82ULL, 
            0xF2012ED78B18A528ULL, 0xF4E5617714D6A421ULL, 0x86C6B7324F402C17ULL, 0xC5EDB38615A7A286ULL, 
            0x3B51DC683F081090ULL, 0x8D0C64679F2223EEULL, 0x68AB62C8631717EFULL, 0xD6E1098A21E75A73ULL, 
            0x41B4D23FC195DBE7ULL, 0x1765AE44DE32B910ULL, 0xACBFD8052B02DAF5ULL, 0x1F882BB9CF32ABADULL, 
            0xEC893F8851ECE963ULL, 0xC56CF503F640C7F5ULL, 0xDD366BEBDC94A084ULL, 0xCECFF009BC00D8ECULL, 
            0xB5AA98A5E1D6D912ULL, 0x527214354F73B3F2ULL, 0x41D1EE6524701B10ULL, 0x7E4E9D7570B47FF3ULL
        },
        {
            0x3888AD1022E0D13CULL, 0xB3F0C7CE0BD2A60EULL, 0xA5BEB095C72285A9ULL, 0xE854BFB2B1E11BCAULL, 
            0x3B8BE664EBF115A3ULL, 0xF9014726EA145D0CULL, 0x0F8BC8D60A907616ULL, 0xCC6CF424A613250EULL, 
            0x357A5FEB0F8129F7ULL, 0x3C89C5CB88EB60C0ULL, 0x0A321B701F5E9761ULL, 0x330E51FCB15B114FULL, 
            0xC712C244D92A7B66ULL, 0x1212F71C04B92D92ULL, 0xE00B2E664E821FF6ULL, 0x7500CC24CDA34FE8ULL, 
            0xACD220855504931BULL, 0xE4F888B85CCA1106ULL, 0xE4529AE85EF4E4BBULL, 0xE0D252FBD79CB3A8ULL, 
            0xDC995C0AEDE162BEULL, 0xDE65D4275CAAB22BULL, 0x2F32D1E6741C66D6ULL, 0x1FD561016E8A1A71ULL, 
            0xDA7F77292F59CA8DULL, 0xEF61E70971D933B1ULL, 0x13C7FFAD2E04A40AULL, 0x9296DB74A6AE54EFULL, 
            0xC333B9C6CA105F9BULL, 0x16BEBAD2B5240756ULL, 0xFB66996E17CD51D7ULL, 0x95EA19A3F637EB09ULL
        }
    },
    {
        {
            0xF5E4E9C6E66B16FCULL, 0xDEBDEC9741CD137AULL, 0x87098DC1CBCD9F78ULL, 0xCEB2370D1DAC33EAULL, 
            0xFE35B6F71BA37E4FULL, 0x569F59246BA8E846ULL, 0x44C9D660D7C528A8ULL, 0x188C53AF33ECABC2ULL, 
            0xB2A269C38B6AF601ULL, 0x9A8E3B72E7113001ULL, 0x32BE09CD18F77D2CULL, 0xAFB46B9CCF23C02FULL, 
            0x6E13AFC9281540F1ULL, 0xFBCCB40EC437B827ULL, 0xFABF0C93F98452A8ULL, 0xCD6134689DF620E7ULL, 
            0xC13CA838EA8B3730ULL, 0x4DB9CF1054B9C601ULL, 0xB2CA9000DEF572B6ULL, 0x5307821154B99138ULL, 
            0x35A765E4B028FCFCULL, 0xD2BD13268227C836ULL, 0x9E6D6F99959204DBULL, 0xE6F76D27851923EFULL, 
            0x5E268A175E3F315BULL, 0x0E2BC8AD4919AA4EULL, 0xE0B6311220D54835ULL, 0x0748427B1D958F17ULL, 
            0x90081116A6D911CFULL, 0x97F4CF94E633EC3BULL, 0x96B568DB0A04C0F7ULL, 0x514E25E858686546ULL
        },
        {
            0xF800862929D4BC55ULL, 0xEC1AD491CB366F3FULL, 0x1DE7D7D5A73ADAACULL, 0x096260427DE88E73ULL, 
            0xEDCF2F38A56126A9ULL, 0xD2EC100ED137417BULL, 0x4BFD0B64F539BD31ULL, 0x67E3EFD300A6A230ULL, 
            0xAE8826841137AD12ULL, 0x927EFF1682FAE86BULL, 0x86625156FB8FAA2DULL, 0xA82EB2B271720859ULL, 
            0xD28630830B92AECBULL, 0xAAA3DE7549440A34ULL, 0x3FE3A3D481374CF5ULL, 0xA560334AE26854F0ULL, 
            0x5B200B035DE87B08ULL, 0x6D06588E2C1F1BC6ULL, 0x2D84A40D6FD7C592ULL, 0xEA5A2A04492AEA6AULL, 
            0x7E993AA2BE2BB2A4ULL, 0x7911495F150CF301ULL, 0x5CDD2E38A8DBCE8FULL, 0x0EDDF97B72433C42ULL, 
            0x27DDBAFDCB29073EULL, 0x48961237F78E8A1AULL, 0xD8A9516C3B64558DULL, 0x3D94283A6BCC1344ULL, 
            0x1E0ED9F2A47D6CD5ULL, 0x6EE928141EC576F2ULL, 0xDC41A1A37062D758ULL, 0x544172164FE0B867ULL
        },
        {
            0xFD5CB8A01A6BA8A2ULL, 0x718E2A9D601E7D06ULL, 0x22592CD70C7FDBDBULL, 0xA72663CA523B5857ULL, 
            0x2685BA16FB84720AULL, 0x581659EF38CE7B1FULL, 0x8E4150A5D4398816ULL, 0x322962CFD9C40013ULL, 
            0xBF1D765127A26BFAULL, 0x6FC322F796BDFE54ULL, 0x47C0487A541CB472ULL, 0x88C81B63B20FC578ULL, 
            0xF4BC8D0ED87CD61EULL, 0x6846574ED44BA520ULL, 0x98B7AA90179DB107ULL, 0x76884E0EEDFAE1C9ULL, 
            0xC3A66E53173B27A5ULL, 0x26F689D2BDC56439ULL, 0x733E1E5A0552BE2FULL, 0xAD479699498DF875ULL, 
            0x81DBE951A0AEEB99ULL, 0x4D75487BDB6B8EF7ULL, 0x8AB3F943F6FA40BDULL, 0x215CBBBE8D133A2AULL, 
            0xDEA077412B2E3BD5ULL, 0xEAAB609E91EF1450ULL, 0xF0B0D20D0D8D146DULL, 0x05FD33C15DB86FECULL, 
            0x55C88554C5C09DA6ULL, 0x08BDA8D51367CCBFULL, 0x44877BF5011EBEF9ULL, 0x79CB2FD781D23D5EULL
        },
        {
            0xE2986190F16BA714ULL, 0x5EAA3A73D1C86098ULL, 0x10FD0C66AB21E50BULL, 0xA6D573DF3084F20EULL, 
            0x5274504E79AA50DBULL, 0x38A612601C4BEAADULL, 0x1B35D2087C37FD48ULL, 0x21AA9B0475AC6F4BULL, 
            0x3A0EEF75A61FEFB8ULL, 0xD594677E37564EB0ULL, 0x5CE576389FDF8A52ULL, 0xC37F55C71AF7B43EULL, 
            0x392E0663110E81B6ULL, 0xCB0927AC3FC57354ULL, 0x22ACFD1A5FE22917ULL, 0x6AF9B30B0936A1EDULL, 
            0xA426CF076833139CULL, 0xBB0D678D43ED5E09ULL, 0x636BFB8780692922ULL, 0x39EFB2A5DE6F0B3AULL, 
            0xFFD453B1FD7F2DDDULL, 0xB9F5991F52031CB8ULL, 0xC3293DD4742AEEF5ULL, 0x6687856E8378DE4DULL, 
            0x6C2601CC76234054ULL, 0x431A9E3DAF334C1CULL, 0x93909CA92FA43FF4ULL, 0x6CAFE9B881F2959EULL, 
            0xBE1B5090DA54D90DULL, 0xFE6E5859A5D7ED13ULL, 0x871F6F1EC9F90FAFULL, 0x5FD63BF6CD6218C6ULL
        },
        {
            0x5424C423EB26308EULL, 0x8FED7C09BB45DF1FULL, 0xE138327FBBA73B4DULL, 0x9834EB770FDD8726ULL, 
            0xCF65D0559FDD825AULL, 0xCD07DACC1956C9F9ULL, 0x6C2121B24CC47780ULL, 0x2E67394E6361FDD2ULL, 
            0xDA73260D9AC24816ULL, 0x84D75ADFDF1C9D43ULL, 0xE1E56BE35F81F428ULL, 0xC6D0DDFA59C1AC6FULL, 
            0xE87591E84ACDAB69ULL, 0xEC5DACD95EC6E6DFULL, 0x834E641A337ED097ULL, 0x26C8B0715BD62A59ULL, 
            0x7242740CCEB38AD5ULL, 0xEDEB2D291CB9879EULL, 0x4D05DEC2339BBCD4ULL, 0x6C29156381148922ULL, 
            0x4A0C3ED35D352CEBULL, 0x158B06C70921CBD8ULL, 0xD86EB1F98EA6B0CBULL, 0x22B6C26E7D674C74ULL, 
            0x00A9DCA13DB9B36BULL, 0xF9FB88372BB6FA67ULL, 0xBD7AA1FF95D632D5ULL, 0xD8D4A94527AB7884ULL, 
            0x6C9C6846AA70DEE0ULL, 0xF45CF2FD0DC42A5CULL, 0xE1DFAD9AAAEEE7D3ULL, 0xED4C8AC74A7AEE46ULL
        },
        {
            0xC2A40F62F2358925ULL, 0x4BF512D48F665B50ULL, 0xC9D61827C44DA20EULL, 0x7FDBDA9133B171ECULL, 
            0x5E49C95B34CED04EULL, 0xE453F32D5B0DD25CULL, 0xC23BF5773EA0DF8BULL, 0x19C9D520179A008EULL, 
            0x84AA028DA8AB9FB5ULL, 0xDC19EBB97742FF83ULL, 0x374353DCEBCF18A6ULL, 0xA06EEB0EB59DE885ULL, 
            0x73AF783234B9DD4AULL, 0x6F3873F028BED3F5ULL, 0x54B6D9578A206E81ULL, 0x69F492487659A49BULL, 
            0x1D72C90C793A16B4ULL, 0x29CDC60BDE1E8619ULL, 0xC98E5A009373B288ULL, 0x8F7B201BDE87FD52ULL, 
            0xC5E5798DACC03CB6ULL, 0xBB9D36701B91497CULL, 0xD90AAED1976E9B6BULL, 0x63C4063D1C0BB970ULL, 
            0x97C20A31EF420DECULL, 0x6CDAD240A533B9B4ULL, 0x259C9916A4A01822ULL, 0x40BE5E84C5A590B0ULL, 
            0x32C3B97E7F3CF95CULL, 0x85CCE0AE49C25213ULL, 0x0641A996F03DFCD8ULL, 0x5E6BED4297FA8C39ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseEConstants = {
    0x653DF6AED38CDBACULL,
    0xA92B74D731318E4CULL,
    0x49E4E782B111EE4CULL,
    0x653DF6AED38CDBACULL,
    0xA92B74D731318E4CULL,
    0x49E4E782B111EE4CULL,
    0xBAEBD2A15517427EULL,
    0x544C1517CFCD9FB6ULL,
    0x52,
    0x6E,
    0xAE,
    0x41,
    0x42,
    0xAB,
    0x0C,
    0x70
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseFSalts = {
    {
        {
            0x13235796BC833075ULL, 0xAEEBD7B3AB87121EULL, 0xEF02AB6FE2297B04ULL, 0xAB518FA432CF96C3ULL, 
            0x24B3285637B617D9ULL, 0x339E1B2659135FF3ULL, 0x50F1D6FF757A6FE1ULL, 0x311B2DC964E7F76BULL, 
            0x5344BDD3FFEA3A8AULL, 0xD8AEF5F30393BA8CULL, 0x96496CDC4EADFA0EULL, 0xD3E050BEF42521EAULL, 
            0xE978BA251D5D4290ULL, 0x1BB0E16F23A81CE5ULL, 0xDAB34E2ACDC7D35EULL, 0x64099307A027BA9BULL, 
            0x28E5CBFAF81DF91DULL, 0x54844B3B912C74F8ULL, 0xAA4B5028023BD360ULL, 0x18F882A4DA3C36F6ULL, 
            0x1FBCAD551AB2365CULL, 0x51883E170A3F12FEULL, 0xCB66B5837BF8A0D8ULL, 0x5F9B097526191209ULL, 
            0x45E82079579A7181ULL, 0x5562EFD1CCDAE19EULL, 0x22FC3FD18FF7E884ULL, 0x3CAD41B90870D148ULL, 
            0xCC29F0B9BEC68E91ULL, 0x56EB27CC5F302887ULL, 0x8A2D0D79003EB031ULL, 0xDEA81750B02E0F23ULL
        },
        {
            0xD615DB411FDBF125ULL, 0x799B560BCE4D5CAAULL, 0x43DCDA55DE2AD26EULL, 0xB522F5DE075EF61CULL, 
            0xC693A01547B57AC0ULL, 0x11426B0C8EA2DAD1ULL, 0xECA9FE785540DCBBULL, 0xDC97D201DE282C89ULL, 
            0x26144229511E0A24ULL, 0x0252B085E856B195ULL, 0x85C99DD55914F02DULL, 0x9459E9B871291811ULL, 
            0x9CE3DF644E1A8FFBULL, 0xCEC8EE3357998F38ULL, 0x3C757382C672C3DAULL, 0xFDC9A6E0EAFBA132ULL, 
            0xC9699DCD42FB32FDULL, 0x07DA24AE1B414F99ULL, 0xF0D4C69ACB2482D0ULL, 0x61A8AD4DAAD25008ULL, 
            0xE2F50D6B306EA3ADULL, 0x580358BBDAEFDDC0ULL, 0xD455582394EE82A1ULL, 0x3AE6A49A154F396CULL, 
            0xD553C8D4DCBFBF10ULL, 0x8A9ECA8A46C199EAULL, 0xC31394D7668CB701ULL, 0x6E77B56D4D5AA72CULL, 
            0x5E8E7EDEF25CDD61ULL, 0x5A08ACCF00A7906EULL, 0xAF606E5B17F192EDULL, 0x09AD24BA29B8FDF3ULL
        },
        {
            0x122F069CE992FDFAULL, 0x0F5B8E3038A4D302ULL, 0x295D7E61BFE69BB6ULL, 0xA73803921AA2784BULL, 
            0x1C65995AD8033B33ULL, 0x15D8F0A17909DD5FULL, 0xDEA95142788E6580ULL, 0xD98FA98BA8E3AF82ULL, 
            0x7A018082838708B9ULL, 0xA088D57DFC8641C2ULL, 0xD99773D6455AFD5EULL, 0x6B3276B691A71AFCULL, 
            0x829484DD0372258DULL, 0x9DB0BFD996821931ULL, 0x40CC1F663DE2BDA3ULL, 0x4C09799132242547ULL, 
            0xA61E9B47DFD6DDE7ULL, 0x23F61FC5FB7B58E1ULL, 0x22903E1354D12C04ULL, 0x5D16DBBBF30DCEE9ULL, 
            0xF1DDF2FB2AE256F5ULL, 0xEC9F171E850E4B8AULL, 0xC63F6D27A3BD1F7EULL, 0xCD7E31D875C59841ULL, 
            0x3A93E6C51659943DULL, 0x36858170458A3DAAULL, 0x630E5492A6352D57ULL, 0x5150E24469C1B46DULL, 
            0x41ECD1DD36A074F5ULL, 0xB6DC269BE8DE21C0ULL, 0x17CBAA6406B122E0ULL, 0x715BC7B58DEFC8F2ULL
        },
        {
            0xB9B3BEFB9A96B0D3ULL, 0x639404BC8B68F611ULL, 0x1349D82E788C8CCBULL, 0x58333FD27848E9F4ULL, 
            0x24D79E351AABC3F4ULL, 0xFD567CA7E15BEA5BULL, 0x2AB3727E81DF26F3ULL, 0x0B5556EF1CB9D03BULL, 
            0xC8A1798A0BF4E7E3ULL, 0x878F75B99CFE3AB9ULL, 0x4918240FC86DB7C1ULL, 0x06D65B9C07F24237ULL, 
            0x3E30DBD83BE113E3ULL, 0xFA7B9EF533467D84ULL, 0xBAAACF940AE31A7AULL, 0xF64D4E590A96F13AULL, 
            0x014170AE4911D8B7ULL, 0x5BECE09483CB5143ULL, 0x78ADE6D4C95D3AE5ULL, 0xFD43EE92956D95CEULL, 
            0x706E9A37307D2D51ULL, 0xF7B33D28E619A1EAULL, 0xCF324B7F4440AE25ULL, 0xECA048CCC4501D65ULL, 
            0x09FE05257A9B684FULL, 0xC6A0032201579123ULL, 0xE99D36EA67DAA7C9ULL, 0xF11CAC3D7F073653ULL, 
            0x421ACE0F4CC0F1D4ULL, 0x4B812F831827B192ULL, 0x58FC39D56C1B9DA6ULL, 0xE7F8D84BB6D5F2BEULL
        },
        {
            0xEAC19880ACDAF270ULL, 0xCC381B9E129E6F75ULL, 0x279D6BC6D35B6908ULL, 0x3E10F26B43A17990ULL, 
            0x06183B1E31257D2DULL, 0x7CFCD6ED4293E2A5ULL, 0xBF6A7CBD3F5BC5D4ULL, 0x44C792F1747C9E8AULL, 
            0xB48F63A9C869B684ULL, 0x354BC18A62829C06ULL, 0x2F1C696AA22BDABCULL, 0x0240F82B877905C0ULL, 
            0x0A759128C0C21025ULL, 0xDD75510A0C9991A0ULL, 0x7249E5AEB0F75390ULL, 0xF6A1297C9728FCBBULL, 
            0xFDA6A08AAE0F201BULL, 0x568866648A22879FULL, 0x39DFA342F03EEDCBULL, 0x1ACF5BFC03AFFBE4ULL, 
            0xC9614C6F22BE0CECULL, 0x96D8A93884FC35B3ULL, 0x0E2CAB68D4F214FFULL, 0x8D5812EC9B34F5F1ULL, 
            0x6726065E912EBF20ULL, 0x14A9FE1A6DBB05CFULL, 0xFF19A5469B0D78C3ULL, 0x47310006530FEA1CULL, 
            0x18ED6EF7B1A21120ULL, 0x87FB9FB0129B5C97ULL, 0x27C60253BEEDC47FULL, 0x918CCDE81B120EB7ULL
        },
        {
            0x18820CDA5DE9EB9EULL, 0x34D42DF4152B8A35ULL, 0x37C0BAF6C9813176ULL, 0xD42A684E6B6CA620ULL, 
            0xCCAA92C5A1905502ULL, 0x2860BF453CC9DAD5ULL, 0x0A4A7B24A28099CFULL, 0x979EB21AB8E587ABULL, 
            0xB0C8B0E3AD369253ULL, 0x8E31650C6AC6202BULL, 0xF3C40F420AA17FA5ULL, 0xE696864D38E4D0E2ULL, 
            0x89456E8B4AC8A91AULL, 0x33A1ECDEC1D611A9ULL, 0x91A7A06740606AFAULL, 0xCC61D8BF765BB332ULL, 
            0x3CFA5DF0F0C3B6BAULL, 0x1144EE2A74AD9688ULL, 0x4A9373238078178BULL, 0x0658B755B1BF061FULL, 
            0x608D7E7EB3026706ULL, 0x6DCB1C6E68A54ECDULL, 0x576ABB10E5F80055ULL, 0x08F524E275CA3103ULL, 
            0x71CDFBBDA45CC944ULL, 0x9775D42FA177D569ULL, 0xB2BF27C4D2248386ULL, 0x3B5BE77C7709878FULL, 
            0x051746ED5116CF30ULL, 0x0E43F9E11F5702C3ULL, 0x2E760B35AC77E8F4ULL, 0xD37F171D4106F0AFULL
        }
    },
    {
        {
            0xC5D6237C12DAFE06ULL, 0x7E21D80DA5223C2FULL, 0x446DB2B0374F7C32ULL, 0x39F26C32D2926F0DULL, 
            0xC809535FBDD49A0BULL, 0xC6C5763AEC8FC2C5ULL, 0x9C713999D091390BULL, 0xC3840ECE0B7B76A9ULL, 
            0x9CF2D5FE1F004A1FULL, 0x1F024DC0F8210906ULL, 0x40EBAD82049F0E5AULL, 0xDC284C3CA66DC0F9ULL, 
            0xE5693A3E5AE08C8CULL, 0x71456D174F58870DULL, 0x757DD0A04C2B4DFBULL, 0xC44648154A21EABCULL, 
            0x26F47A16D44605D3ULL, 0x50E6FEA016700A09ULL, 0x0DA2CCBC80B8EE73ULL, 0xD4A277B7A0D89493ULL, 
            0x41C4978300A35580ULL, 0xB8B7FE2CCBE39CA9ULL, 0x17998B7B26F335E7ULL, 0xA534DF285A0F851CULL, 
            0x1D7BB7A91747A0F2ULL, 0xB4D81088CDB18640ULL, 0xE2942507BA4C156BULL, 0x8ED52FEDF4346930ULL, 
            0x2E750F32D99247F2ULL, 0xBE7EAD212D023D50ULL, 0xC62738CF8D3785C0ULL, 0x2ABB52A8256411A2ULL
        },
        {
            0x4DD72CC650C39FB5ULL, 0x7C56B0E0A61295B2ULL, 0x9DC5070C39963604ULL, 0xFB69F7B41CB16CF2ULL, 
            0xA21CC310A26D26ADULL, 0xD7881474DD091BFFULL, 0x26E716AAC9D97D34ULL, 0x814276C6F134808FULL, 
            0x4293274F0E1D4DB1ULL, 0xFA71B6C788708418ULL, 0x962AF4ECDD3075D5ULL, 0x732C8B6D30798950ULL, 
            0xA242E4856F37B263ULL, 0xD31AFACF854D1271ULL, 0xD1D78C3308FA1BB4ULL, 0xF9D1666AD06D5D99ULL, 
            0x4C4312CC2E5CAC51ULL, 0xA3220E506AEE3FAFULL, 0x6D703A404A0B9CCCULL, 0x87CCD654E9C940DEULL, 
            0x35B90B9AF870FD39ULL, 0xF744892D2AE71895ULL, 0x9F8795EB13786A5FULL, 0x36F195E3816A8046ULL, 
            0x82E4E9662A055EDAULL, 0x3961A1E63616A1DBULL, 0x6EC37A87C5141198ULL, 0xD60D8FF8912DA349ULL, 
            0x13CA6AEAF222C4BEULL, 0x04FC51B7C2D538C4ULL, 0xB25E63CFD00D3213ULL, 0x774C0E6E2F88F8DBULL
        },
        {
            0xF0BA7D8A8230B352ULL, 0xBC8B555616CB121EULL, 0x07A70BE4B0D833BAULL, 0xB827BE95A16CB4A1ULL, 
            0xD5E4E3D6204E40D7ULL, 0xC9A3CE1D112EF868ULL, 0x6E4D15D3857F6E8FULL, 0x18A8B93DFEEE427EULL, 
            0xDDE8F06F8001AB40ULL, 0x5F17811C408D9BF4ULL, 0x0281902C44E90BACULL, 0x595194D051B264FCULL, 
            0x88A53051EC681A30ULL, 0x65400B0A600058C4ULL, 0x8D7EFD2F6A57DAD7ULL, 0xC45C4658EE41C4E5ULL, 
            0x9414F0528D81DFECULL, 0x1487A4F43F514FCBULL, 0xC05629CB07EF3CECULL, 0xDC283DD012427121ULL, 
            0x452FF1BAD9B682B0ULL, 0xCC56C1B4DBCA0A74ULL, 0x1A6445D730766D8FULL, 0x419D99ACE696F1E7ULL, 
            0x1564AD4C90BD2598ULL, 0x6CF3935EF2A1D4C5ULL, 0x1F4629095014D47AULL, 0x1B80F196B364D949ULL, 
            0xD617B4128DD01C46ULL, 0xC47B9C0B619D260CULL, 0x384E1AE477CE8B25ULL, 0xE7F9D99CD1DDF946ULL
        },
        {
            0xBB5D2CB7BCA773A3ULL, 0x5219D610BFFCE5ECULL, 0x6DE2C84F9F00B9CDULL, 0x7403F13C24CCDA53ULL, 
            0x3F6948EF64CB5314ULL, 0x2A746CA445F0F0D0ULL, 0x0E8B49BD7E5B376DULL, 0x66257F48E1341DA9ULL, 
            0xA6B3B805E8837BCBULL, 0x0FD22EC9462F1B02ULL, 0xD3BF59F463EE8ACBULL, 0x81AC94C0DB03952FULL, 
            0x33EFC8C9B0359E49ULL, 0xF76096C3BEEC9B7DULL, 0x43013A9639EAEE10ULL, 0x344404EEF6F83168ULL, 
            0xC04944B3F7F591E7ULL, 0xCC2AA5F684C3F80BULL, 0x4B5BD3EE69B2C961ULL, 0xC8E7B52AEEAE538CULL, 
            0x77F90A68AC628C51ULL, 0xBD56ED1C14D960F7ULL, 0xCDFA1880F04970EFULL, 0x8097777AC6B68BE4ULL, 
            0x645B32AEB24B0A1CULL, 0x8C896A7FD7703175ULL, 0x6E968479775E38C3ULL, 0x085B3AC4AB3FAD6FULL, 
            0x704533D0B48F4AFFULL, 0x673DF3BF54C690FDULL, 0x3F2FD7EFA4A2D2F1ULL, 0x390351B4B78CC282ULL
        },
        {
            0x58D5B43B2265E20AULL, 0xED46568E12F1BAD1ULL, 0xA5D99887268B02A2ULL, 0xA46B68DA984C08EDULL, 
            0xC3D2BDF71A8553D4ULL, 0x1A0A9BACC79DAB91ULL, 0x04F1FA1726C777DDULL, 0xB0C82E53FF9B12D3ULL, 
            0x1038F485185E1812ULL, 0x0530596492E5E6ABULL, 0xB6639B86F9C7FDDEULL, 0x87AAA3CBFD883735ULL, 
            0x9F1C0981272B50DAULL, 0xC5582B293AD515C7ULL, 0x5E2E53B5227ACFEFULL, 0x929E78E3952CBC0AULL, 
            0x2F69B3442BD2C8FEULL, 0x8C3828528AF439EAULL, 0x0FE322317B3E3402ULL, 0x44EEC6F652C6A485ULL, 
            0xA38E1D25C64E5AA7ULL, 0xD2C795C0D41E3510ULL, 0x82F5DE083CD3211AULL, 0x0682DFA624032337ULL, 
            0x4987A64EE889E6E6ULL, 0xBD6024C3746C4E4BULL, 0xC3993ACF0080BDC7ULL, 0x23DEA915C215E59BULL, 
            0x77E8B98A58125FE0ULL, 0x03D1BF4B1D6F6972ULL, 0x60439378B2714215ULL, 0x54FD4819442ECBCFULL
        },
        {
            0x0CBC275F2E4939AFULL, 0xC901D49CBE352DDCULL, 0xC825FB2D516BDF7DULL, 0x359A4AE4CD5E03ADULL, 
            0xB230AC6932728020ULL, 0xE0E64BE5E01FD739ULL, 0x605AEF691A021004ULL, 0x1FED7EE8D1C6B767ULL, 
            0xDCC6F869EEE98506ULL, 0x4C6D5C7FDF33817BULL, 0x4794F4021F5934F5ULL, 0xAAE73D7DEA2B5C0FULL, 
            0xD54200818A9315CBULL, 0xEC3910B5D8F8E205ULL, 0xEA60DFB81671B69FULL, 0xFEF9ABBDC5DD436DULL, 
            0x674DD3814ACE5EAFULL, 0x9628A581C6ECECE3ULL, 0xC479C0FFA65089C6ULL, 0x5BE1D6369ED3666CULL, 
            0xADECCF6ED0B0E644ULL, 0x659FDC34D698020AULL, 0x220206ADA0C64088ULL, 0x62F83950B87723EDULL, 
            0x67CB584DA93D3482ULL, 0x6A0EF8B4AD84671DULL, 0x1C7412F0E7B9CFF6ULL, 0xBDB41E5504E82681ULL, 
            0x3EEF0BA52403E778ULL, 0xBFD848EB408F06A8ULL, 0x7497F5FEC316BC87ULL, 0xD172088D391CC061ULL
        }
    },
    {
        {
            0xAAC75C0B2B7DF815ULL, 0x50D5864A5A78048EULL, 0x8F0C7917FB47D704ULL, 0xCCFEE716867C8CFBULL, 
            0x3A56DD38E6410B36ULL, 0xAC2561995D9E1C93ULL, 0x53CAA62BCE90679EULL, 0x3AE03D99C51001ECULL, 
            0x57D1FFDF9F0CC8BAULL, 0xEC459D1139656284ULL, 0xFE98A95BE4D88174ULL, 0xE1526C0238B0F69BULL, 
            0x7149457D664965DFULL, 0x5B7C0D8086F5A7AAULL, 0xB88D182692978D05ULL, 0x86947FC9C9E9B1FAULL, 
            0xAD96590BC1733B74ULL, 0x34919C7299384B0BULL, 0xAD3603EF4C9254A6ULL, 0x760A184A8407D445ULL, 
            0x3B8D5F0C28145C29ULL, 0xC65A2617B50C28A6ULL, 0x2BAB9D61AC9872F3ULL, 0xA8C13690FF315560ULL, 
            0x1BFF19083A9D332FULL, 0xBC3451E102A65F36ULL, 0x2EC0B5655B89DF2AULL, 0x712764B945AE4475ULL, 
            0xF8A4D2F2B10B2E9FULL, 0xCA5C23656ED1AD0DULL, 0x2F668A6064AF8679ULL, 0xEF4B7A1B7FD7BBD8ULL
        },
        {
            0xA23C77361BF506A6ULL, 0x87D2B814119481F2ULL, 0xD63DF5BF008FEFD9ULL, 0x9F93AFC57DD6E170ULL, 
            0xEDE7314BCCF4E7E0ULL, 0x9645DBBBB52850FEULL, 0xEC94516D21752C22ULL, 0x2F26B7900B7AF487ULL, 
            0x84259E5E7667B3EEULL, 0x1866E25160E8DBD6ULL, 0x963B6B1BCD3512C3ULL, 0xA7A8FA9EADFA7807ULL, 
            0x81331957CDF7A1A9ULL, 0xA0BF62E207CB392CULL, 0xF738F0A391AFD9D9ULL, 0x96C25C20AA1FFE6FULL, 
            0xCF0FCB9A0FAE513FULL, 0x2460B255DB759ECBULL, 0x247229B727C8F2E8ULL, 0xCA9D6F83670A399AULL, 
            0x2EF911DC2A626044ULL, 0x00336AC35D3BD749ULL, 0x4144E7AD7A004ED4ULL, 0x406EBA387CF78751ULL, 
            0xB87A9A0175304BC7ULL, 0x3B2912297964076CULL, 0x03F8DA7E182081A3ULL, 0xEAF048180D252AC4ULL, 
            0xF7AE03824C8C5B81ULL, 0x1808FDAD30A44477ULL, 0xB120468F1AF742BBULL, 0x9B95C6186EED34D8ULL
        },
        {
            0x286F33A51C9B374AULL, 0x2552E1F129E252F2ULL, 0xB994A1C210D9895EULL, 0x58369FA6ACA71825ULL, 
            0xDAEF0DCD0A9E3A01ULL, 0x916D0078D4967850ULL, 0x3D3C593EF81E4E9EULL, 0xA2C564CFFD4D64B6ULL, 
            0xD7039B0A876B1EC4ULL, 0x9C4586DC40E95E9CULL, 0x0CF8A7802DB98272ULL, 0x2A018AFD1C8B468BULL, 
            0x5AD7C2A784EE22ACULL, 0xA2CEDFEB12FE4898ULL, 0xD726819621FD0CB2ULL, 0x3AA564841DBA5B67ULL, 
            0xC895AD48EA1A59EBULL, 0xD24A43CED3263B88ULL, 0xC348959A166FD6F5ULL, 0x94DDFC424050339CULL, 
            0xA70E93F63B4C250AULL, 0x166EA1305D1A9690ULL, 0x6C7FF1A8569F8CEEULL, 0x4D2859CACA211F1FULL, 
            0xE302D721696BADF2ULL, 0x0DBD49907C94C37AULL, 0x8D63486EEC195369ULL, 0x186588B5F7718092ULL, 
            0x9FE37EC642A6EC44ULL, 0xB113634C5A027C24ULL, 0xE5941EC7869D01D5ULL, 0x040E5881286E4B70ULL
        },
        {
            0x5A4747F5242718CCULL, 0xEEB2A4657826EB33ULL, 0xE708E036B084C6DAULL, 0xC83954CD46CBB5BEULL, 
            0xD72B57E356B20A9BULL, 0xD39B40D6ED8CC2D0ULL, 0x4A3A05A62FEAD694ULL, 0x2FEC8F16D4F1C5C1ULL, 
            0x7F5D17BD913D28A2ULL, 0x1CDB008777043A41ULL, 0xB323868AB2464021ULL, 0x49E6BB7DDA544313ULL, 
            0x90F0821F49F9338FULL, 0x6F923885CB2C9AD0ULL, 0xDC80349443B0192DULL, 0xBC42E7C8E0DBED46ULL, 
            0x5C6B87769A3BAB21ULL, 0xD0C28CA567A7508BULL, 0xBBBD963C39F551C0ULL, 0x116CD331A694B0AFULL, 
            0x340F56182A221A12ULL, 0xFF3D65C9465CE8BCULL, 0xD30F1653723AE3D6ULL, 0x5EC134D0210F8857ULL, 
            0xB88A54448DB419FBULL, 0xE049D98A3A661BE6ULL, 0xAEA6178CF4822CA6ULL, 0x03275C38CE939548ULL, 
            0x19439013F9AF5E25ULL, 0x5512768DB661D378ULL, 0x02B133E3295B5FE5ULL, 0xCC9644CAAAE1C00AULL
        },
        {
            0x11E345A055F133F2ULL, 0xB97738ED27937DEFULL, 0x274758E3A4E2A1ABULL, 0x6B3AC575A959DEBBULL, 
            0xC6BC7CFA4568ECE4ULL, 0x2811102170539024ULL, 0x498873C577F3C6E5ULL, 0xD3AFE42AC9D4D781ULL, 
            0xF4010BEDC3A35D25ULL, 0x13E4FA63BFBE7AF7ULL, 0xD7869A79432C6475ULL, 0xAB8882E5FC2CC2A0ULL, 
            0xAE630EA19BCBCBE3ULL, 0x117D1DC0728331B8ULL, 0x6A2AE25EA30C7D96ULL, 0x2BB2763976AAAB96ULL, 
            0x32E246AA6E0E8A90ULL, 0xC3C8FF0012F9F1DCULL, 0x5D5B77BD90A0F719ULL, 0xF633D5710AE25A4BULL, 
            0x1E262EB7B295B9D0ULL, 0x73CEDC9FAC921547ULL, 0x25D96D68DCBEB73BULL, 0x2F4131F6CC6B3716ULL, 
            0x3759273866FAE083ULL, 0x66E513528EDD3603ULL, 0xF0B838AFBDB92BFEULL, 0x1E4A3CB8D34154F5ULL, 
            0x4D00D50574913B8EULL, 0x23A24FF3D5BCFF3BULL, 0x284FF075BDAF088AULL, 0x07E45748DDBB3D33ULL
        },
        {
            0x63B9E20CF0D4736BULL, 0x60C9FDB40E125A4FULL, 0x2FCB3F88DEB97C2DULL, 0xB56DB936ECA214CFULL, 
            0xD2153907A5624DCEULL, 0x7B39173E155146FAULL, 0xF2FBFDB16CFBA9ADULL, 0xCE37F9B02C0095E5ULL, 
            0xF6D0E9A57F4E5391ULL, 0x4CCDDEAB7982DEB8ULL, 0xD7FDD4B76CAEB655ULL, 0x2E4340D00AB80DB9ULL, 
            0xAD1D333AB83E5F18ULL, 0xC960EA38F3E9443DULL, 0xEA8CE507972C840FULL, 0x8A6195675371BD44ULL, 
            0x7600B73DA8C7A2AAULL, 0x3034EAE6B76EE0D1ULL, 0x5BE376CE8F38CBD3ULL, 0xEB9CE56DC53E8E5FULL, 
            0xF8E52FE51457C81FULL, 0x58C546AADB5EAA8FULL, 0x6599D4881D6CB9AFULL, 0x8B559147B1A42C55ULL, 
            0x35ED9E58850849CAULL, 0xF6D4AE9B1B498807ULL, 0xD49F1B4C6EA2EAEEULL, 0x43DDCD1BFCBAFD7DULL, 
            0x7BD91460ED4AF747ULL, 0x7EB2664BB1398CE0ULL, 0xEF5CC2C0B0CAA026ULL, 0x04B1C5DF5275121EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseFConstants = {
    0x69CC1A104CD3C893ULL,
    0x76BD02050A7DDA9BULL,
    0x669A26ADD58F6C53ULL,
    0x69CC1A104CD3C893ULL,
    0x76BD02050A7DDA9BULL,
    0x669A26ADD58F6C53ULL,
    0x3F7D2D10CAB9A1F0ULL,
    0x9147F750802BAEB9ULL,
    0xE2,
    0x3F,
    0xF2,
    0x6D,
    0xF7,
    0xA8,
    0xB8,
    0x80
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseGSalts = {
    {
        {
            0xB0DFF3FDDCBFBB8DULL, 0x3564B0C34CC88249ULL, 0x7E039A1F0A55458DULL, 0xB0B84E18BE35C98BULL, 
            0xFC7C70579F0B0161ULL, 0x161983571B975ED3ULL, 0x9E2514C1F9F0BADFULL, 0xD9D8D4E5453310BDULL, 
            0xC6E593544901F0F9ULL, 0xD571CDD7F77B0BFFULL, 0x90E2C3423DBEF55EULL, 0xA76CFE1C3C5A2E95ULL, 
            0x7BAEFFDA8DA4D2CEULL, 0x1DCF7F8AD30F6B31ULL, 0x4ED25832B327196BULL, 0x64BB28C35E8656C6ULL, 
            0xB082E99C15968496ULL, 0xE8B884DA15710812ULL, 0x24C7A9E3F903C0D8ULL, 0x459DB0CA9D55D742ULL, 
            0x0C923F2DA59F7031ULL, 0x68864EEC31F3C754ULL, 0xFA1AA69925496C1DULL, 0xC438DC724A61FCC0ULL, 
            0xCB25D40D684072CBULL, 0x6D7F7CD53FEC3363ULL, 0x8A3752EF5D9177C2ULL, 0xA28363E8FA584613ULL, 
            0xD115A697B2309CD8ULL, 0xF748CCFE054E55FDULL, 0xA646A61BFFF286BAULL, 0xC4823ED27302A85AULL
        },
        {
            0xDA3B80E486E95EFBULL, 0xCF4CD7827A02F1FFULL, 0xF32DE0D60E6D9E17ULL, 0xD11598419B7608F4ULL, 
            0xBAC5932814567D4AULL, 0x57846A7E521B106DULL, 0x8AF5BA13EAD3CA57ULL, 0x9ECA31F15520F5FCULL, 
            0x6EFF5BF377B3BE90ULL, 0x7380FAEED904F33FULL, 0x260E8D8B86C1ED04ULL, 0xA994983357B25AA7ULL, 
            0xD5F244BA81FAFD80ULL, 0xB9ADFA72E5C2BD44ULL, 0x087DC4402182E596ULL, 0xA64F97A7C2DA8C0DULL, 
            0x09F74F5EAB0CF208ULL, 0x5324CA0C9364D416ULL, 0x68C56D9F47ADAF04ULL, 0xE93E4200AFB0E6BEULL, 
            0x2550C91CD9758420ULL, 0xA297786F1F52F8D9ULL, 0x5FDF74B9C9DA09FBULL, 0x6FD1DAC255C5EA46ULL, 
            0x358C47C36E70A8BEULL, 0x1E578F272D5FDFE1ULL, 0x60A8573D3AE69FC6ULL, 0x815DB87FD5B0627EULL, 
            0x0CDE1E99AD7E7884ULL, 0x0F24296F7262490AULL, 0xAA490C1167FA2F95ULL, 0x15E5288D7EC44D01ULL
        },
        {
            0x29EE68F57D082833ULL, 0xA9C5DCF22403DF41ULL, 0xA15EE2AEF2EE294FULL, 0xCDF9C7A9D8E35BDAULL, 
            0x99D777D86625EDCCULL, 0x69F24335D514B682ULL, 0x95CB25B28C32ACDDULL, 0x5A0E85E17B6F5C5CULL, 
            0x2EC77F0689A8520BULL, 0x5757AA71FBB3C19CULL, 0x2679C0CE07AA2A25ULL, 0x55FA2BD13F927FD5ULL, 
            0xC7F6B9BA16FF1AEEULL, 0xC85496D65496BDA1ULL, 0x45949D9983C5BD49ULL, 0xDFB27E6488D38925ULL, 
            0xD4A94FD54DC613B3ULL, 0x551E72C7A3313CF9ULL, 0x1906527172847CA5ULL, 0xB825D5CC679BBC52ULL, 
            0x6B332BF5A6C0B940ULL, 0xC47A503660A0B204ULL, 0x9E1E6697150B5E38ULL, 0x61E30175693CAAA9ULL, 
            0x304E7B54F0B35F85ULL, 0xB586F287842779FBULL, 0x7C34778698976BC8ULL, 0x8F87FCAFDC9FC416ULL, 
            0x1FBE44C451F62158ULL, 0x6D1501C4180FB2DAULL, 0x3BCAF81E6116F2D8ULL, 0x08AB881654B2350BULL
        },
        {
            0xA39BF3FC6EA2EEC4ULL, 0xA89825D5EA28924EULL, 0xAC3FA37C7D7ABCABULL, 0x41AED7B4E921563AULL, 
            0xF3949385459E4BD8ULL, 0x636D8ABDA6930AE7ULL, 0x8D81B40D4962FC5CULL, 0x013095A8BDB0D13DULL, 
            0x4266EFAACC848426ULL, 0xBB60F538F42BFC6BULL, 0xE8D006517AFA41DCULL, 0x0D4F1261034D3DC0ULL, 
            0xC063B8F09146A513ULL, 0xDD710F92C4579177ULL, 0x9BEC16049F56E669ULL, 0x83C9BD4E9C55CBD1ULL, 
            0x386DD44E6533AC39ULL, 0x56403F979718FB15ULL, 0x3106B2A608D4728FULL, 0xB1E15AFF80A7495CULL, 
            0x3FDDDFE11EAAC47BULL, 0x19AB65205DD4B252ULL, 0xE2084D4F9B097A1CULL, 0x6A94DE4F859B5700ULL, 
            0xB1F2DD9FFFE704E6ULL, 0x82C7A38F34D7E6E7ULL, 0x4F9AFFD6DE348D1CULL, 0xA95478E56E1E8E72ULL, 
            0x574524BA659AFF4AULL, 0x954B67236043294FULL, 0x5D894BFF2974D46BULL, 0x8AEEBD9558FC3D41ULL
        },
        {
            0x29EC85FB504FE983ULL, 0x367375D45E53655CULL, 0xF401769649CF7554ULL, 0xA2A499C80B15346AULL, 
            0xF8E893952BD36BFEULL, 0x35FDBDBAFADCC042ULL, 0x1A0AEEF74D95E25DULL, 0xE06D6B1E6EEC2F61ULL, 
            0x4727421E81D0F545ULL, 0x08C81B22BBB60886ULL, 0xE1788BC3F92D45ACULL, 0x8FF54F2673374471ULL, 
            0x7A933EACF93D2AA8ULL, 0xE101D90049897AD4ULL, 0x4985CCFB52B884D4ULL, 0x93E75E17477AEFE4ULL, 
            0xF2555C1D62950E99ULL, 0x89C080979BF60127ULL, 0x3720A2F9586AD60EULL, 0x8E0942AF6EC6B3F6ULL, 
            0x8EE4782B41440A8FULL, 0x04BEBBD696396925ULL, 0x2E43F95BD6A2C6D2ULL, 0x58C835738E21EAC3ULL, 
            0x26CEF8250C83F5C0ULL, 0xB62C595F49FA9EF6ULL, 0xBF81B3BEAA3A7551ULL, 0xCBB6D0DE6D5D0D5DULL, 
            0xBE47E277625772D0ULL, 0xA1B623AE388B0450ULL, 0x26007752109A6C63ULL, 0x7045BBFFABC20D4BULL
        },
        {
            0xA560416FB3B92BC0ULL, 0x8865EE432CC7BD51ULL, 0x64450782D7A345CCULL, 0x5352A0C90AADF22FULL, 
            0x9F788DD2E189A8B6ULL, 0x9E475528703CAA35ULL, 0x5AA90DD832EA1154ULL, 0x5412F1412327FB4BULL, 
            0xC82BD8FE9792D974ULL, 0x7EBA676DA5B197DCULL, 0x45D31DE1A2889B0AULL, 0x71CC57F85D7420D8ULL, 
            0x063FA3036117FF4FULL, 0x294B31581D17C2B3ULL, 0x508CBA0466F81F1BULL, 0x737148ADB59C8494ULL, 
            0xD8B6B84D388FBE0EULL, 0x505A9680DA595CC5ULL, 0xA3AB88E9AA0C825AULL, 0xCA2EAA3F74AACA54ULL, 
            0x89BFFC4A56A7B375ULL, 0xE142D854703826CEULL, 0x5BF2910BE436DDE5ULL, 0x4B5B548865F1CF46ULL, 
            0xCDEF0EC1154F3C42ULL, 0x9BF818A31CB4924BULL, 0xE5E368613689E202ULL, 0x081BB6E88EA195C7ULL, 
            0xA293A5D501145778ULL, 0xF8FBFB715C946AA7ULL, 0xAD7A3EF6CF02E6C1ULL, 0xF2961A82244182EEULL
        }
    },
    {
        {
            0x38635880557BAE08ULL, 0x12A979E43C979665ULL, 0xB369EF8BDAF0CAA2ULL, 0x6A975B82B4BF32E9ULL, 
            0xEB61F50769D60B03ULL, 0x97EC3644C9CB0B07ULL, 0x6E7314571C48E44EULL, 0xC3B79F0CDA53670AULL, 
            0x470A637DE8B3ADD7ULL, 0x6EDA17CD71B6BE53ULL, 0xDDAB63E18ABB304CULL, 0xCB31605C1B60E256ULL, 
            0x79F2575EC5F72ECDULL, 0x1BC6C2AB68C39FCEULL, 0x0EC28D6FDF030E6BULL, 0x84D462A4C856B13AULL, 
            0xB7F08CE312115091ULL, 0xA842B0983E9B8D5BULL, 0x445B107147C6CCB3ULL, 0x78361C28FCE13A51ULL, 
            0x1983C5F3CE0DB226ULL, 0xD396470BDBF32F62ULL, 0xD0BB11A2D7A13BF8ULL, 0xE0494817FFB72C21ULL, 
            0x052541D1E9FBC5F8ULL, 0x93B3FFFAF42F46BDULL, 0xD10B3227080B695BULL, 0x5557037425E246F7ULL, 
            0xFB7E7A45C102EF6CULL, 0xA1453488311D3750ULL, 0xBAEDFD61BF60EAE7ULL, 0xEC738D7C1BC2210BULL
        },
        {
            0x4641776064E402A1ULL, 0xEF36F753F9973261ULL, 0x8F7A6C3D87D92C5FULL, 0x614393C7658E77F1ULL, 
            0x44E43A0DB1438634ULL, 0x3C04A9E8C050AB0EULL, 0xBBEC679646AFF02AULL, 0x7AAE01834409B9EBULL, 
            0xE828F003CA1E8301ULL, 0xF23153F92A1180FDULL, 0xF7ADB514EF8C2CC0ULL, 0x54FBA512931E8779ULL, 
            0x5CD7846526635CFAULL, 0xD98EDC23510BC6B1ULL, 0xA95FF39EE7630AFFULL, 0xA53DB1F64E66707AULL, 
            0x84FCAC5E2E4ADBD8ULL, 0x65B41C743911302FULL, 0xA34E7D4692FE0152ULL, 0xFC6C4F5418F07DECULL, 
            0xC3983369510AA237ULL, 0x33EEE762E4E0C717ULL, 0x19E30ED708BA123BULL, 0x623D26E53ABDFAE1ULL, 
            0x03DEF3C688E9CDECULL, 0x2784F06E0731156DULL, 0x542DB011F72C8D67ULL, 0xA47B0DB4158E8EFBULL, 
            0x5AC8C9C5AEDDA287ULL, 0xC4C44EDEA4ECB6FEULL, 0x33608F4F62760572ULL, 0xA6C1F5AB10E29567ULL
        },
        {
            0x2537068B1304159CULL, 0x58BEC08E5F5C934BULL, 0xC7AB0F6D7F0EA9AFULL, 0x603F10A48200D7BEULL, 
            0xB6744834F80F37BFULL, 0x744086EBCC739BE9ULL, 0x35242DAD134E7B42ULL, 0x258627CC88753E0CULL, 
            0x1E400343DD411A76ULL, 0x071D42C2DF9D9C1FULL, 0xC304022C676342A8ULL, 0x14AB12CEC7D3038FULL, 
            0x2F8524B133FFC749ULL, 0x66D05C327B221976ULL, 0x11D4F47000316455ULL, 0x1921C9722BF31906ULL, 
            0x72EB615559A00207ULL, 0xD8ED5D9BA5E414E5ULL, 0xF5D1CF79288F8BD9ULL, 0xD084A54821E4D8CAULL, 
            0xE91BC69DCD84DDEEULL, 0xF1415C2FE753F54AULL, 0x18F5AD1A57377FDCULL, 0x924C5EE8FF8BBBFCULL, 
            0x54C064A254EC2ED0ULL, 0xB3ADB59405BC9B2BULL, 0xAD411AA804358F0DULL, 0x29306152D32C3CA8ULL, 
            0x66494A2920B695AEULL, 0x20DE49DEE6C1AFF9ULL, 0x4653DD1AD0DCBA82ULL, 0x7CF6A2F720EB1AD8ULL
        },
        {
            0x3F5B6947B9510892ULL, 0xAEA4ECC016EB1C96ULL, 0xE356BCCBBA1E5CA2ULL, 0x93800389CAA430C2ULL, 
            0x9D5BA2C2830BF633ULL, 0xF5E7DA40A5C26D10ULL, 0x2885DAA8EC28797DULL, 0xB80DE0E56479B631ULL, 
            0x3BD9FDD0D4590E1FULL, 0xE2EAE313ABD34A27ULL, 0x4B1DC935B8C952F3ULL, 0xBFA017E8792DB9B0ULL, 
            0x4D6DD419DFC47F03ULL, 0xB7F87BF26F8AC1C8ULL, 0x48010400D84A4582ULL, 0x1BB31340748DA0C0ULL, 
            0x9262C696D09425CBULL, 0x202F7823A6AA0B4EULL, 0x702BF7BCA0D5950EULL, 0x6F556DB1954631C3ULL, 
            0xA6A7285828D9B911ULL, 0x26A200B8D3B2AD83ULL, 0x1423BB54A28D7DE9ULL, 0x7A01F100EEEF939EULL, 
            0xFF2775AF884D7021ULL, 0xC3912903E0CE152EULL, 0xC0CE863739C0E735ULL, 0x7F2BFDA82226FE22ULL, 
            0x1DBE115AD1C04CA8ULL, 0x99D6210E5F7E6434ULL, 0x2B7DD3D7424DC4C6ULL, 0x61C701197EC7113EULL
        },
        {
            0x51773C9F3A7CFCCDULL, 0xC8CF152D3838826AULL, 0x186DEE9A61FEA9F4ULL, 0x02BFFDB90F465E4CULL, 
            0xB66F73AB8D7ECC29ULL, 0xF538575381E1C117ULL, 0xB15759D85DE1ACE3ULL, 0x6C9EEF6BC71E903CULL, 
            0x076BE2CA8D24DA19ULL, 0xDCC49CBE27651E98ULL, 0xDA595C8447745D96ULL, 0x194A11A3A6CA8929ULL, 
            0xFE114DD83DA52378ULL, 0xAC443B334D87265CULL, 0x846090FB82ED21E8ULL, 0xF2E3B73F0C08B4FCULL, 
            0x403A2B532DD0E177ULL, 0x4556DD1094A14BD2ULL, 0xC2C113724816E843ULL, 0x4B42F2CED0F15E93ULL, 
            0x22063AB56977738BULL, 0x5E9EC8212A3683D2ULL, 0x1DB53F140B8125C1ULL, 0xD84B020BFA8061D0ULL, 
            0x1A60BA04633EA2EEULL, 0x7C50372954FB5180ULL, 0x20672D7F5E7C69ACULL, 0x665494687A7DE662ULL, 
            0x15B8CBDB9D0A36D1ULL, 0xCBE113F2A9ED4576ULL, 0x61FDC63F41A0331CULL, 0x82EA27F5C951D4DBULL
        },
        {
            0x2544A7E846FFFB6EULL, 0xF43A59B9BC9CD118ULL, 0xBE71AC8A43968E71ULL, 0x603610511EB51EC3ULL, 
            0x94B9848C52A91870ULL, 0x938E4EA35A527C13ULL, 0x8BD393C94EAF8AB6ULL, 0xF727F7C2EB785C71ULL, 
            0x7672F6A3600100FCULL, 0x1760714872947ED7ULL, 0x588F8D000C9AC582ULL, 0xBB01BACE6ABBA764ULL, 
            0x95A67B86CA2E9EC8ULL, 0x8F34F66B1F8E601EULL, 0xF1229F01B9CC846EULL, 0x389DC30780455B32ULL, 
            0x16D7DEA02F252B60ULL, 0xF666C4A7706AA39CULL, 0x5364DC0C579319BEULL, 0x09E537C845D679EDULL, 
            0x8321770ADAC095EFULL, 0x70761F7C7D7CC48EULL, 0x460A67B5B778C2F2ULL, 0x9C82A58CE495009EULL, 
            0x083D6D30D90B522EULL, 0x28DA89B0D6BEE194ULL, 0x9C548CC50497BC95ULL, 0x4414BC987BD58EE9ULL, 
            0xFBFE6BC10126514FULL, 0x37989196AD4DB4E1ULL, 0x656C0AE98E692220ULL, 0xCAF7A127CCE160A1ULL
        }
    },
    {
        {
            0x4AF589ACB6F865F3ULL, 0xF9F1408AB281D580ULL, 0xD87E129BC746761FULL, 0x99A58DA976BB9507ULL, 
            0x2D9390FD0DC64E0FULL, 0x4AFFE403E3C88B12ULL, 0x9EFEEBF970C0F427ULL, 0x1C2D53278E154796ULL, 
            0xDD2357121093104EULL, 0x1622BEBE51A53B2CULL, 0x7DFBE9154FAAF1DEULL, 0x2D14B3EDCCFC862EULL, 
            0x770383F9D8C02607ULL, 0x746C3D3904AD6552ULL, 0x484340149DCE5814ULL, 0xCF87F1958CBD410AULL, 
            0xEDA5056B69129CB6ULL, 0x6902BCE8CC333BE7ULL, 0x00E64340821C1089ULL, 0x97038EDFB0A8578AULL, 
            0x9AE6EF35102716A3ULL, 0x10E0E8F23B0DE436ULL, 0xE49D7102D2E4BCC7ULL, 0x8B808F401CF35D97ULL, 
            0xD27D2986D1B10AEAULL, 0x725BA5D8023E81FFULL, 0xD62F6C38B15C6222ULL, 0xD6AE3F64DD644AD4ULL, 
            0xF48100B7729E2127ULL, 0xACEFAEBCB23D038AULL, 0x227FE676646174FDULL, 0x039E1E76BED79D0FULL
        },
        {
            0xCE9820D289352F88ULL, 0x3DF9981B57FB0492ULL, 0x0C280BED799DE44CULL, 0x934B2E5FD380A04FULL, 
            0x90C5459F8BB3DCC7ULL, 0xD0A52D98968ED3FEULL, 0x90C9EBBE3AB17079ULL, 0xEEE3B2E7BF4A862AULL, 
            0xCBE4DD2FFACD2809ULL, 0x342DA27DC704FAA0ULL, 0x3C84B4FF539E8CD3ULL, 0xA1F0FA67893538E1ULL, 
            0xB6EF45C9D3C9880FULL, 0x48758CB3D933F5C9ULL, 0x078518ADED58D848ULL, 0x8AD2EAFDDEAE3394ULL, 
            0x3042C648249C84F2ULL, 0xA761A5CDFE4D3B9BULL, 0x5E68886AE1D57390ULL, 0x109A59F2DD9A5C8BULL, 
            0x527AE7BFB4855650ULL, 0x839E04210AFE450AULL, 0x1089B46C4EE690A9ULL, 0x2ADD1CD924984745ULL, 
            0x1C3D65EB6EA49CE0ULL, 0x3B1D472530A00726ULL, 0x48C8FBC0309F04DCULL, 0x9B14905FC31E1A92ULL, 
            0xFA225AA5078FFAB7ULL, 0x74989B764A3C75BFULL, 0x2C26080A36AFE350ULL, 0x77453CF465CA0CD8ULL
        },
        {
            0xE506976B9542233DULL, 0x9A800DEF3FA41DEEULL, 0x5769F0F385CEC2B4ULL, 0x01FE07F06D7F86A1ULL, 
            0x077DC013813BD0C1ULL, 0xA3675CC8279D2B20ULL, 0xE164972B00A1FAD4ULL, 0xD3587D40429F3A51ULL, 
            0xC91FFBFE9B1DF977ULL, 0xDC9A2E9E3863F395ULL, 0xBC33EB8C9D81630BULL, 0x9580C800B4E70C4AULL, 
            0x7BB7707047D21077ULL, 0xF99935332C7A0EE3ULL, 0x6682C9779DBC2F1FULL, 0x5CE2F5E4AF473145ULL, 
            0xD08FDCAB479EF905ULL, 0xDFCD817E32B2B526ULL, 0x731EA5E558097367ULL, 0x05F90702B674C19EULL, 
            0x689216D119CF13A1ULL, 0x6B3B517C5682063CULL, 0xAF6509157FF4FF22ULL, 0xAE3D81B2E0E1D727ULL, 
            0xF1608DC9D9CDBEBEULL, 0x47234DA42E590988ULL, 0x38559CA9EC0E3A7EULL, 0xE2C0EF6C7B39863CULL, 
            0xE27BD77F96343F65ULL, 0x6B4C69871179ECB3ULL, 0x63F946BA4942D0A3ULL, 0xC2AECCD3EE674F9EULL
        },
        {
            0xFEFC49A9DF0CA473ULL, 0x0E5393CD3F50BE90ULL, 0x6D739FAE54088386ULL, 0xC4E8C871C74BCEA7ULL, 
            0x66464B166231E288ULL, 0xDF560C25AD4342F5ULL, 0xE7E74C3A62181588ULL, 0xC969BADE0E809477ULL, 
            0xDDEDCB5753D9C232ULL, 0x7397E89137E382F4ULL, 0x78A36740C50C8615ULL, 0x1212DBB135F1965EULL, 
            0x9B4B956C285827CEULL, 0x16B74345D601FAA4ULL, 0x08842D19F158660FULL, 0x4307931FA6057D79ULL, 
            0x2A2CEF7CFDA6F96CULL, 0xBF74F16B64F62847ULL, 0xF805705887BCE613ULL, 0x03C3EE7E03CB4C0AULL, 
            0xCC6EC63A2C213874ULL, 0x98AC0E0332A44F0AULL, 0x7B63A4DB58624832ULL, 0x3EC657E1C9502EE9ULL, 
            0x81008BD3D97F6E8BULL, 0x72AEB1288E7ED863ULL, 0x4B02067CD5794062ULL, 0x1DE35E9C8E0D4324ULL, 
            0x9521E3049C463676ULL, 0x54A7D6B689D6671CULL, 0xBD824D9E9A848422ULL, 0x57FAD7EE04FBA6F5ULL
        },
        {
            0x982FD4EE078465A6ULL, 0x6A5E14FA17141BC9ULL, 0x6030494312D84759ULL, 0xA37050F9100B56E9ULL, 
            0xA1C6D9EC2164A4B2ULL, 0x048FA7C869EEBA45ULL, 0x364CA3299307028CULL, 0x9D96A95D82241332ULL, 
            0x51FFA2B9D2A601FEULL, 0xF02F01D745B9595CULL, 0x629FF7FC7BBDF1C6ULL, 0x0A247BB6335E8B7DULL, 
            0xD4C79990C9A1CADAULL, 0x5C2CEBF891903FF5ULL, 0x3B03E16E88C64FC8ULL, 0xF57369D92CE090A3ULL, 
            0x0B78542AD08906E6ULL, 0x3BE368F2D78A170EULL, 0xDE0540569DF5C9F1ULL, 0x1DFD6A2F2A56F427ULL, 
            0x6B1FECDBD74C44F1ULL, 0xB374AE63EB94DBC7ULL, 0x904370B8675CDFE1ULL, 0x49B899AAD3AD6B03ULL, 
            0xF79E86A0D282F7BCULL, 0x84114FCBC0309010ULL, 0x3CAFF9BF28B10486ULL, 0x2A1B0D7A078CB69DULL, 
            0x185A969AF5A03319ULL, 0xA08A5A546330D5A7ULL, 0x40BBD64259660DA3ULL, 0x7B217726B3E3E049ULL
        },
        {
            0x32B2D2553782D7E4ULL, 0xDEE0DA27D1EF4452ULL, 0xE210AA2532542385ULL, 0x8A762DD352BCF2C5ULL, 
            0x6D90F33533773351ULL, 0xAB3E801A63DC60AFULL, 0x8E09932B4349FB99ULL, 0x04EBAA715C999404ULL, 
            0x64B92340C4C09530ULL, 0xD19B61E42F5A4A86ULL, 0x540A3C54F3213254ULL, 0x7CAB20A7A917E2DAULL, 
            0x0B3B13E8A62DD411ULL, 0x60CDF93CFECDD124ULL, 0x5300B3AB3D8623E3ULL, 0xC9F8894664144E1BULL, 
            0x142DA523D04F2C8FULL, 0x7165508B7EE66CECULL, 0xAC3A9F5A857DD9A6ULL, 0xF9AC984AE4DFFAD7ULL, 
            0x8EFA3F06D8E9921BULL, 0x8C65106DF9007C59ULL, 0xFC854076D716E73AULL, 0xCFC68AB6D77205EFULL, 
            0xCE3CF5451ECDE760ULL, 0xCB9CED962ED133EDULL, 0x283678B89E9F3802ULL, 0xD84E9EB706B47318ULL, 
            0x3120B2B125A9DB64ULL, 0xBE3D2F6152FE7ABCULL, 0x5CE61DA6220CB91EULL, 0x2D5676AC2A0F910AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseGConstants = {
    0x0D69E832FE9F297DULL,
    0x74FE67C5AF9368D7ULL,
    0x57CF8F83ABC6E153ULL,
    0x0D69E832FE9F297DULL,
    0x74FE67C5AF9368D7ULL,
    0x57CF8F83ABC6E153ULL,
    0x3E90C2F010E13E3AULL,
    0x065A3F6622B8B5B4ULL,
    0x21,
    0x28,
    0xC1,
    0x4B,
    0x40,
    0x47,
    0x67,
    0x63
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseHSalts = {
    {
        {
            0xA48CBABF08829AEEULL, 0x733F43E1E981F9D7ULL, 0x409EF0D036C882DCULL, 0x9054A9F664C95A8AULL, 
            0x9C5E5C05762A2744ULL, 0xEA30EC128C9DC2AEULL, 0x6C3DA33AFA3AF0D5ULL, 0xDC86974E6C4B20C7ULL, 
            0x1345C2EFB209A8C9ULL, 0xC31130E67D599281ULL, 0xC8449C10D6136A08ULL, 0xD5676C1BCC403AFBULL, 
            0xE2DE1F232A449481ULL, 0x99F17C488FCF6DF5ULL, 0x2137DFB8B6CADF85ULL, 0x22B341B88BE4A80CULL, 
            0x4CAA54B39D160A7CULL, 0x3B6595CDAB3471D5ULL, 0x403F4F3EF52E2703ULL, 0x67AC887919465D7BULL, 
            0x0F9927A5252DEE2BULL, 0x4C20561942A6F911ULL, 0x60CF9678D7BEC98EULL, 0x0E6F659C6577FC5BULL, 
            0xB3E5CFC7CE1FD2F7ULL, 0x3B580CDFC817E998ULL, 0x4BCC439D774D777EULL, 0x4400F9248BCC3EEBULL, 
            0x28D6336467AE5901ULL, 0x256DBB55A3468F6EULL, 0xF65EC5C95555CF50ULL, 0x9424845427F7ACC8ULL
        },
        {
            0x7090BAA95E72F2E7ULL, 0x0A758CE1E3F21D00ULL, 0x1FE62D440EDD1D72ULL, 0x5B4648B07AF722B7ULL, 
            0x2E994BC3B2731425ULL, 0xAC4272B8E5DEC38DULL, 0x12A58F3B2A814D48ULL, 0xE81A08F8B7B1D9A1ULL, 
            0xF5796131D80C6C14ULL, 0x12B6016B44A611CDULL, 0xFD5BAD5605B7CF87ULL, 0x7860BE5D128BF7E7ULL, 
            0x83BEDCAE680AB11EULL, 0x2412F1F125E68D44ULL, 0xFB5BBC10D53665ACULL, 0xE0338B971378DD44ULL, 
            0xEBC29CC48DA72260ULL, 0x68D667512D2F51ADULL, 0xCC6F99F664F644E5ULL, 0xD1EFBDA0614FAA91ULL, 
            0x7E1A6CEFCB573787ULL, 0x57B232DAF9EAA520ULL, 0x91FA89084D289DF7ULL, 0x9D557FA976811B9CULL, 
            0x02AAA04A800A2065ULL, 0x384576EEEC4D98E7ULL, 0x776CA6A4A4991EFFULL, 0x281F7416AD789F83ULL, 
            0x2A7B8B5640D0FFEBULL, 0xAE62CBAD10D7742DULL, 0xD5824DA85594D905ULL, 0xAE64A916CC968477ULL
        },
        {
            0x930E448C07C887F3ULL, 0x84FC87CAEF6F9E77ULL, 0x51111FEC1D48023AULL, 0x4383170B3F36FEA9ULL, 
            0x8EC7B33B2859B998ULL, 0xFE2A356A0B66AA6CULL, 0x045626735BBCD49BULL, 0x4EE527B17FB4F19BULL, 
            0x93FAAC75E37BD025ULL, 0xDD25B415D9F2290CULL, 0x1F1918C106B7AF80ULL, 0x65CADFA675125A91ULL, 
            0x5FAAEA0339A586FFULL, 0x10167B18B2433290ULL, 0xC316F98174680C4CULL, 0x653CB4AD03AE91B4ULL, 
            0x649372E3089804BCULL, 0xEFCA59449ACE6F1AULL, 0xA10818282771B5EBULL, 0xA00805E9EAF9101CULL, 
            0x7C17F66A59E869EDULL, 0xDA109B7D6FB7D1E9ULL, 0x4B8E0683679FF107ULL, 0x28C8E405F5833F32ULL, 
            0xCFA6BE1E1C3F84DEULL, 0x8B278AA7D2BD9F48ULL, 0x1CA0721FA75E0B45ULL, 0xA2CC6A73D31CEB6AULL, 
            0x9484944D18599EC7ULL, 0x1DE64729ABBD1B36ULL, 0x57EE19529D60018BULL, 0x99832F8918F25A79ULL
        },
        {
            0x7FE53F2FC925B754ULL, 0xF5C5DC2B3133B4AEULL, 0xAD0E71B247134BFCULL, 0xE5D3D07C891ABD26ULL, 
            0xFE093D8CCB6358C5ULL, 0x25653DA32DB96EACULL, 0x84C602F61424070CULL, 0x9B58211FBFFB48C8ULL, 
            0xEF8859DDB53435F3ULL, 0xD688223CE4900D52ULL, 0xD63AFF6B0D72389AULL, 0x27ADC80EE440C03BULL, 
            0x2DFDD06E10202CEFULL, 0x0540B2CF6D467282ULL, 0x6D985AFE88757ABAULL, 0x1E741D3073EE6663ULL, 
            0x759B42604DE94173ULL, 0x81319A881F41A1FFULL, 0xC09C3EC998375869ULL, 0xF7527AF00DAFC802ULL, 
            0x579C5DCE6BF7FE1AULL, 0x7B168127A363305DULL, 0xD4EEA73D9B60F01BULL, 0x65A55D6E2DEA034AULL, 
            0x71DB1F42A797FB38ULL, 0x077E6BA0B7DE3E47ULL, 0xB2D7B303E00F7913ULL, 0xD83E9D2C7A687FD2ULL, 
            0xDC65DF9083B13184ULL, 0xE5C59E8FFD14D754ULL, 0x49CFB80FCE6125DDULL, 0x803C542472C4C0ABULL
        },
        {
            0xF15EC3CBF3D35EAFULL, 0x3D1384BFA0F8CB16ULL, 0xFB40EAD7F5DD7D02ULL, 0xF3AF886AC0481A61ULL, 
            0xBE8B0B9BEEC48873ULL, 0x482659113FA74966ULL, 0x33B4E0D50D37F484ULL, 0x573BF87BC54EC0FCULL, 
            0x6A74ADA490408A6EULL, 0x78EE7CFA3EF7FD71ULL, 0x3E13DA6CE69F5406ULL, 0xD978413F09995F85ULL, 
            0x5AE9E25AA4231267ULL, 0x188A44615E9D9CEAULL, 0xD8B189A5B6B2840EULL, 0x55559CADFF760738ULL, 
            0xED7302747C967423ULL, 0x820E451D0990D8A8ULL, 0x10B1BFEC1C41E2E9ULL, 0x72782BED205A3175ULL, 
            0xFF4B61EF85517E74ULL, 0x086D18F074B9B81EULL, 0xDB5257EEED47F87DULL, 0xBC5EFE8F92BFD464ULL, 
            0x509646B9AEDFDC68ULL, 0xE119CAE2B743E572ULL, 0x644EA4C480BD90E0ULL, 0x07DF6BAB19AF9D14ULL, 
            0x0DF8AA0EEC15C891ULL, 0x56F9EB238D041AEFULL, 0xF40FB876DB59470AULL, 0x1935BF63AA6F6AECULL
        },
        {
            0x638B4A6B22A24EE3ULL, 0xFEC126FD2FE9A4FBULL, 0x5FCDF055B073C27BULL, 0x1AFD40A77EDA82AEULL, 
            0x492FC29698F2500CULL, 0x43FCFBF8900907C0ULL, 0x1B3E22740E4A0CB4ULL, 0xD55E9C59FFCC9F43ULL, 
            0x866E115EFD8E2BBCULL, 0xA7B51721FDA12AE7ULL, 0xDD76708B3D0C8ACCULL, 0x56929D7BBEBA98A0ULL, 
            0x2D78571A2653217EULL, 0x01AA8F1F0EC8A22DULL, 0x26C1AB603055127DULL, 0xBC254B01DD60707CULL, 
            0xF898468E6F75F1B8ULL, 0xAE5D6EC192E6CED7ULL, 0x142CB569D8E61C88ULL, 0x9CBABC815CA92117ULL, 
            0xDE63038AAB6F781AULL, 0x778C6F942CEC2F0FULL, 0xBB5CE64821E3D616ULL, 0x25FBAB8FBE805808ULL, 
            0xDA1B0DD6C0D16561ULL, 0xE617C3F742EB0569ULL, 0xD979F98EB1B623DAULL, 0xADC40ECE9459BD01ULL, 
            0x1BBABE461619AE8CULL, 0x650CAAAF8C436D7CULL, 0x268C6AE005D676BEULL, 0x01D041C2BF5D7C67ULL
        }
    },
    {
        {
            0x379904F09819F67AULL, 0x8657B10764AA7EC4ULL, 0xF0127FA7F0B4E01EULL, 0x43C1B84E9468F328ULL, 
            0x7E58A6B3CA257F1BULL, 0x72A4331D99BCF173ULL, 0x0A957B0D38AF54E4ULL, 0xB491CBF5468FB67BULL, 
            0xA852D03284273707ULL, 0xC01D9C197D084B73ULL, 0x669DCCDE9ED4CE7CULL, 0xE10713D3BA3D5B7CULL, 
            0xE7512718F10AD7E4ULL, 0xD0D4F748CE6AABA6ULL, 0x9DCA11AAD635D985ULL, 0x7E57DB8F601CEA2EULL, 
            0x37F98DFED3FDE5D7ULL, 0xEB38DC81F4425D47ULL, 0xB43F32B04F851DB3ULL, 0xDC18E0C3C9A3C4ACULL, 
            0xF729C6A92D091D03ULL, 0xA858165A759A858BULL, 0x6431E63DC73AD0D0ULL, 0x34EC07D1CA054A73ULL, 
            0xD050D56D5D0C45EFULL, 0x232B9B65059C0F9FULL, 0xDAE0EBB92EB29AE7ULL, 0xAD512C0E04732719ULL, 
            0x2219BCAA4C25086BULL, 0x226A750F4E943B6CULL, 0x425BA0D359BAEF53ULL, 0x8FF0D3172C1558DBULL
        },
        {
            0x59E8691E5FE3C5B8ULL, 0xB65B7145D2641DA4ULL, 0xB041B591D539D9DEULL, 0x68E968A8F7A8E7BBULL, 
            0x547B4A2C089961EDULL, 0x6542D43297D072A7ULL, 0x0328AB63030FBEA1ULL, 0x76E9FE9824C88DC2ULL, 
            0xC5B1954666FD15BDULL, 0x7BFC659876CA6C21ULL, 0x90FD29C70F89B8FBULL, 0x1D7270D470BAEAC1ULL, 
            0xB5AB5EC935C1350BULL, 0x2A8DEB638E4999D6ULL, 0x4891521B845B2074ULL, 0x4E12CF552118C6C5ULL, 
            0x797917C46310DEAAULL, 0xE0A4EC02E901FBBCULL, 0x3B3841E358EEBDE3ULL, 0x57AA0E10FB2EFD8FULL, 
            0x9862EC2C2FB87369ULL, 0x50AA81BBB6ECE44CULL, 0x08B56119F8E07577ULL, 0xBF2815B5C1622E49ULL, 
            0x7D5502BF4D219F4EULL, 0x812EC1F8B1A49B53ULL, 0x055FB4A4437F1DF1ULL, 0xF0C49B46152AD9BDULL, 
            0x6CE5D3E1E45E3A4CULL, 0x5997FC9498D58E7FULL, 0x2BFCEB566D54E5D6ULL, 0x1C9D277C71D64642ULL
        },
        {
            0x770ACDAB4792FF07ULL, 0x7478E8E1F7B69EFCULL, 0x150318D4A6DA852BULL, 0x357EC7FF9A89417CULL, 
            0xCBE7DE4A6D26A6BFULL, 0x1E8E98C4E3B7EDDEULL, 0xC0C72E1801A2600FULL, 0xE386139E9AD65BB2ULL, 
            0x95B5F77CA11AF95AULL, 0x9424D2581597303CULL, 0x0A94540F3D5B7096ULL, 0x052F683E9D946B22ULL, 
            0x3B2E137315CF3897ULL, 0x82001230ABBF0FE3ULL, 0x73FC46986E05CC42ULL, 0x0551A67AE148ADA1ULL, 
            0xE80A4863FD247B98ULL, 0xD8EE59CCEEC86AE3ULL, 0xFB9F6B65BC62FF79ULL, 0xAB2CA7154B906C40ULL, 
            0x2F511A4C44C7F184ULL, 0x2C692ED1F5D0F848ULL, 0xB95C839DEEAABC54ULL, 0xA3D576E6AC291ECEULL, 
            0xCB11BAE3C6A5C7BAULL, 0x37066A8B8E0B914BULL, 0xC383B4D9CC6802EEULL, 0x5DB24EDB3AC9029BULL, 
            0xFA8C6617B206ECC7ULL, 0xEE6529272D76722DULL, 0xDD417341E36D2535ULL, 0x7A84DC05080D53C1ULL
        },
        {
            0xD3CE78A9CA54F1EFULL, 0x5193667F72389210ULL, 0x00B4C959F116CCEBULL, 0xA8177055734CFC39ULL, 
            0xA19FF94781A0FA95ULL, 0xD81729684C8E7A2CULL, 0xF2080EE6C4D94C42ULL, 0xF80589B77984E878ULL, 
            0x551AB3EECF8BC22EULL, 0x7FB3B1A262F7E6E9ULL, 0xF434F52AD30A089DULL, 0x75EC89B7035F82A4ULL, 
            0xC2759413FF9CA219ULL, 0x651BC628C05F7D3AULL, 0xFD26F2DBF8D6178DULL, 0x13FFF593DFD0ACDBULL, 
            0x1AFA068F40248B27ULL, 0x11C83B66654E1765ULL, 0x9FD581827CF894D0ULL, 0x117FAD8864EB291BULL, 
            0x1B29289132F848C7ULL, 0x23256DCB34C41E96ULL, 0x4918F9117C163CDDULL, 0x0A25F2A64CEA0200ULL, 
            0x598AABF095D60927ULL, 0x3877E9B9028F5E6DULL, 0xB9A9D0CBDFBA3AD0ULL, 0xEBE65EF80DDA9BE3ULL, 
            0x57446680309D43DAULL, 0xA033FF58431532BCULL, 0xB69B34FF736945D4ULL, 0xA7E301BD77235105ULL
        },
        {
            0x66E8FD4475C4A13CULL, 0xB0E20526F50B6AC8ULL, 0x6449B5D9BAD0371FULL, 0xF8AECE53418A677DULL, 
            0xD7373A90F0877FDEULL, 0xD53D4F35485D409EULL, 0xEB1B8FDD828591FEULL, 0xD5035E1893F5DDDBULL, 
            0xB02C51E2316C08A3ULL, 0x02A2202BA7700648ULL, 0x1329C2C0CB42B785ULL, 0xDFCA1D76AA19E4C0ULL, 
            0xA6EA0E6B90D38079ULL, 0xEF9E4FEBCA2DCEA5ULL, 0xA01A36F05FA18FAAULL, 0x3D226FAB861DEFFEULL, 
            0x1121FCE3BBAA1CD4ULL, 0x90C57D77BA1DE563ULL, 0x2ABC98801E87ECC3ULL, 0xA73B5D083243298AULL, 
            0x1409E52AA63D364AULL, 0x9CCFA6FBE1214D2CULL, 0x86A9A1C25335853EULL, 0x04078AEA2CB2CDFDULL, 
            0xBA722F2C68DEA1A1ULL, 0x5AB1147D6B0259A8ULL, 0x5F6273F918E9F3C9ULL, 0xC33F6899AB02F4EEULL, 
            0x49CFAC7F73FC8907ULL, 0x9BE2249CE5401D60ULL, 0x5DB481C86182C30DULL, 0x7229ECE7E078955DULL
        },
        {
            0x4EE854A1A231C804ULL, 0xA1CBAB3648116C68ULL, 0x31C4E4FE9394E1E0ULL, 0x393F93ADB4F5DCF2ULL, 
            0xB6193E4E0AB1C0EDULL, 0x581263131CCA7BD6ULL, 0x9518499429C8C817ULL, 0xDD9A9FA01838D8EDULL, 
            0x431D118CE8DE5E38ULL, 0xB121A841622AAD94ULL, 0x9186AD4837A92854ULL, 0xA7BF8A81109B9CAFULL, 
            0x1C8C769D89F8C959ULL, 0xCFB574FBECE00D7FULL, 0x8C6A19BADA18BBFCULL, 0xCD26E6466192EA54ULL, 
            0x04CF293935A5C964ULL, 0xBCD4638BB9D442C7ULL, 0xDC7E2E339BAAE537ULL, 0x48F1FF282877044DULL, 
            0x936DFDFC34716C16ULL, 0xF88D030D0CD41FB0ULL, 0xE050BEBA44CDC0AEULL, 0xAC5E0BB603D3FCBBULL, 
            0xDBD5571B49617DC8ULL, 0xEB9DB0640375B2D4ULL, 0xFAD0E4BC62C2BCB0ULL, 0xE3EA59372451D6C0ULL, 
            0xB586DCE8BCA6D69FULL, 0x16E559D4BB4EF17DULL, 0x71288708698C4E28ULL, 0x9592B3A320191697ULL
        }
    },
    {
        {
            0xFD603E4FF02D30E3ULL, 0xE1863D93B71A0C56ULL, 0x9C06160FA17DE55BULL, 0x3D7593FC7821DC80ULL, 
            0x6900D5548F7030D6ULL, 0x0EDB7EED3606AACEULL, 0x95E34A6F48C66585ULL, 0x17B93AAE36C00833ULL, 
            0x92A5DE327C43DD40ULL, 0x32E3DE1867A9E788ULL, 0xABB0C009032FC8A6ULL, 0x5338D1DF7DDCE684ULL, 
            0xD24AA31F74842AFEULL, 0xD20D08E7B5C31156ULL, 0x0204A568F489BF96ULL, 0xF2F351BD64536D29ULL, 
            0x0FB7E5DD1213F3CFULL, 0x35129A29DEF817B2ULL, 0xD80C0128DFD32F6EULL, 0x2D7A41CA27F9339EULL, 
            0xBAA713B23ABE4575ULL, 0x992C53E9118EBB23ULL, 0xF7286C058ABDB2D8ULL, 0x56A8E48F4B254CDEULL, 
            0xFDD263F1F2C1D235ULL, 0xA067AEB60FC9BDE5ULL, 0x2C845CD356793C49ULL, 0x038834D084FE665CULL, 
            0x186755222D2F8D61ULL, 0x1446718F833A047FULL, 0x55728EBFFE0132DEULL, 0x4AB02D107A585628ULL
        },
        {
            0xC761766A6EF7A64DULL, 0x503FAEDEA2FD9991ULL, 0xC6A03430D075AA7CULL, 0xE99BF009D8576979ULL, 
            0x242E21159060C8D1ULL, 0xB5B853D48CCE2AB2ULL, 0x08E8340BE084E74AULL, 0x058A128C03C17C82ULL, 
            0x7AA4EAA176DF5679ULL, 0x4645B786E5E43DA3ULL, 0x7E732A9D0C6E8E7AULL, 0xFB922D3732E5AD46ULL, 
            0xCA4C565148596D43ULL, 0x1230C5B8CFCC2784ULL, 0xC37330AB0DBF39D1ULL, 0xF8EF5C59F7E32DDBULL, 
            0xF35EFDB6757A7FADULL, 0xF29B6233B8E6A6E2ULL, 0x3E9F6E188FBB9E6BULL, 0xB57E9B9E51B7E77DULL, 
            0x2B326AAAB05BE00AULL, 0xCE9C58E1F896F034ULL, 0x7F61F13F30C6BF6FULL, 0x660DF74B0F47A25CULL, 
            0x21A630F2DC9AB20DULL, 0x7DE1609B77105B64ULL, 0xDD30FD364DAEEE74ULL, 0x8E1DA60EF4A70A74ULL, 
            0x072560617031AD2BULL, 0x1A25F5AD1875453DULL, 0xC4118E0996627ECBULL, 0x0C6404CB57387943ULL
        },
        {
            0xB5078466A2B75E7FULL, 0xA5187592CA13B6D2ULL, 0xDA8513D5C620C7CEULL, 0xB2124A73623767C3ULL, 
            0x5942B9A04294C89CULL, 0x269798DD66CBFAA7ULL, 0x6B7479B537761B46ULL, 0x4051AEEFC63127F4ULL, 
            0xD606E486026BC78FULL, 0x9B642B102E08B91AULL, 0xB537BC701748AE0EULL, 0x1B94EB59F70E8CFDULL, 
            0x0D4AA43C3340881DULL, 0x7CCE853DA92F62CEULL, 0xA1F7CBBCE079B7A9ULL, 0x6146AF3E8CBF53ADULL, 
            0xF6BD83EA39EE1175ULL, 0xD2CFD24930576DFDULL, 0xD82BB378F13F566CULL, 0x50902A5EB97C091AULL, 
            0xC2BB126E8E191771ULL, 0xCE3B9BBEA5E60BE1ULL, 0x41A93DDA8F3C6169ULL, 0xFF990196A042D534ULL, 
            0x2A56061CBDD0A555ULL, 0x75AFB995DC0C115FULL, 0x8873A41AE818EA7BULL, 0xBD1827D66BE574DEULL, 
            0x4B5547804F72D2E8ULL, 0x1D198D14B973DC4AULL, 0xF7932A6A46A2EC19ULL, 0x1FAF520CA54B946BULL
        },
        {
            0xE696CDA4F26FDB55ULL, 0xC37113722B09237DULL, 0x2FD8D14629117DD6ULL, 0x059FEB3646813CC3ULL, 
            0x6F7E3E8EA01B248DULL, 0xE5490BDCAA55F100ULL, 0xA631EF9F57F4DCBEULL, 0x5E9CA763BF37A470ULL, 
            0x18A53D23FD083E40ULL, 0xE4D932E2F339081FULL, 0x9350A2603308AD0DULL, 0xB2382E1B5D4CBB15ULL, 
            0x5D1A0EDDBAFED7C7ULL, 0xBD823929EFF6FA34ULL, 0x07EF43228552D9B5ULL, 0x07E95CE2E92A88D2ULL, 
            0xFE0C84607F5327F8ULL, 0xC678F0D0D72DCB71ULL, 0x65341CB8054E77F9ULL, 0x2B36496966229DABULL, 
            0xD3D1A8EE16152446ULL, 0x4591810071E69F8EULL, 0xE8F59C951CDF2265ULL, 0xA7C6786503CFAAE1ULL, 
            0x9D795D66D2BAC964ULL, 0x7ED494D241218BB6ULL, 0x95CE3B3D9B7F7554ULL, 0x674A283B956CCE35ULL, 
            0x00807EC328D0AE6CULL, 0x3D6BF04562A769F3ULL, 0x8A19CAF3B106A8C4ULL, 0x122FA4713C75DA94ULL
        },
        {
            0xBA5E99B22FD6209DULL, 0x4F776B0D1F6A8B42ULL, 0x92CDA6E737AC2E54ULL, 0xC3716583C045D47FULL, 
            0x84803BD3C8507463ULL, 0x61F195EC9ABBCA2CULL, 0xF6940CB95B62E7E1ULL, 0xC82C7FE39EA451C4ULL, 
            0x6B9F658131538BD6ULL, 0x936ED76B30C24AD0ULL, 0x30E959E8DDBE98E7ULL, 0x7C684411B8EA7320ULL, 
            0x286CDDBDEDA6BCFFULL, 0x5901616FE90B371BULL, 0xC3D6E09404F276F4ULL, 0x015C23580E78ACF0ULL, 
            0x62D7E3DC28B240B0ULL, 0x5179938DA18DF552ULL, 0xFC398310E49A9670ULL, 0xE12BE83C293EB7BEULL, 
            0xDD2C85325907CDF8ULL, 0x80583C4FD054680AULL, 0xFAE155D5C4BB9D88ULL, 0xE4F4D256F9E3643DULL, 
            0x7DDAB7A35D1C0D61ULL, 0x3D853675627A1AAAULL, 0x5A3E7FDA45002F5FULL, 0x76ED43400FD51BB5ULL, 
            0x6183AC8ACAB8A5E3ULL, 0xA1648F3D385FCE20ULL, 0xD7579D4F21500B20ULL, 0xBA4A846A38EBCE83ULL
        },
        {
            0xEB41EC8E318A2946ULL, 0xBE78C6560BA1482DULL, 0xAAD66358F1EB25E8ULL, 0xAEFA9FB070CA7485ULL, 
            0x62C57BE86161FA34ULL, 0x9DB78081CCE804B7ULL, 0x110650C10821637BULL, 0xB841EBF69628E849ULL, 
            0xEDC0C5F5743A1B52ULL, 0x187FA31E50A397FFULL, 0x2DD76D384EBC32B0ULL, 0x7F35A73E8D520F04ULL, 
            0x233268E51A564EE9ULL, 0x962E95398632E2C7ULL, 0x8B09985FE3CE862CULL, 0x71FBF20DDD158A5EULL, 
            0xB4E5E9F687648A59ULL, 0x374B36A165647FE1ULL, 0x8BEF3228E54C97C5ULL, 0xE232A7603DD8E6EEULL, 
            0xAB871283F4DA7612ULL, 0xD7371C5C4E350567ULL, 0x4C4CE673F8A09038ULL, 0xF69AE343657AA339ULL, 
            0x4DAB643FF0D9BC05ULL, 0x1FC58EB84316CBF1ULL, 0x6B5C66CE8DF42FFCULL, 0x65726BDFC7D09FE2ULL, 
            0xF96BC6FD4A169A47ULL, 0x5FF32689BD85CC7DULL, 0xE2065203243C4B5AULL, 0x4E6E4A64D82D9532ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseHConstants = {
    0x73E6843EF241111DULL,
    0x3335DD45A260C154ULL,
    0x09243678A37B1E13ULL,
    0x73E6843EF241111DULL,
    0x3335DD45A260C154ULL,
    0x09243678A37B1E13ULL,
    0xF94DA742C7B8B6C7ULL,
    0x60CE2850BB4B3227ULL,
    0xF7,
    0x92,
    0x62,
    0x5E,
    0x83,
    0x0E,
    0x4E,
    0x6E
};

