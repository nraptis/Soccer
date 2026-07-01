#include "TwistExpander_Fencing.hpp"
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

TwistExpander_Fencing::TwistExpander_Fencing()
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

void TwistExpander_Fencing::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB8DAFBBF24104421ULL; std::uint64_t aIngress = 0xA3B5D87B91463221ULL; std::uint64_t aCarry = 0xD36420DA9A7CA016ULL;

    std::uint64_t aWandererA = 0xFEAF3C81080B0B44ULL; std::uint64_t aWandererB = 0xB98A9F630EACCA4DULL; std::uint64_t aWandererC = 0xAECCF628F30CBCE4ULL; std::uint64_t aWandererD = 0xB3CB1D112862C285ULL;
    std::uint64_t aWandererE = 0xDA31C063224ED0E4ULL; std::uint64_t aWandererF = 0xD5E4BAD73DB2B325ULL; std::uint64_t aWandererG = 0xE92B0715C695C76DULL; std::uint64_t aWandererH = 0xA7A7013AD8D87EC7ULL;
    std::uint64_t aWandererI = 0xC54CDDC7572138B9ULL; std::uint64_t aWandererJ = 0x873269CA1A7A6CD1ULL; std::uint64_t aWandererK = 0xA1FA6B2CB364F409ULL;

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
        aPrevious = 12192580839213724622U;
        aCarry = 16914941337387255577U;
        aWandererA = 17456305508974916951U;
        aWandererB = 10766805661269313829U;
        aWandererC = 11233997330027532241U;
        aWandererD = 18381746137908190166U;
        aWandererE = 16272284128791129646U;
        aWandererF = 13946440383784844911U;
        aWandererG = 12851804066285616783U;
        aWandererH = 18206503182777598117U;
        aWandererI = 12608148210192625486U;
        aWandererJ = 14992299018839171289U;
        aWandererK = 10488261622989892246U;
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
    TwistExpander_Fencing_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Fencing::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA02626F49ECA7D54ULL; std::uint64_t aIngress = 0xC3D59D4E67718145ULL; std::uint64_t aCarry = 0xE87871D5AA355921ULL;

    std::uint64_t aWandererA = 0xEAF3981161228357ULL; std::uint64_t aWandererB = 0x82C3837108A2997BULL; std::uint64_t aWandererC = 0xF6A8A927D235D7E2ULL; std::uint64_t aWandererD = 0xEC0404B5E05E6A49ULL;
    std::uint64_t aWandererE = 0xF84B2D5F200FBB94ULL; std::uint64_t aWandererF = 0xFD031C336FEB809CULL; std::uint64_t aWandererG = 0xCA814D690E565324ULL; std::uint64_t aWandererH = 0xB01DB8AB61F1C716ULL;
    std::uint64_t aWandererI = 0xE61C6CF8DA8AA658ULL; std::uint64_t aWandererJ = 0xB4D6660D6E4B9124ULL; std::uint64_t aWandererK = 0xB5D27D8A4C6D3CB2ULL;

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
        aPrevious = 9791822485938324350U;
        aCarry = 12482658640853144750U;
        aWandererA = 9503333208547996592U;
        aWandererB = 15706036517897220388U;
        aWandererC = 9514971155210982159U;
        aWandererD = 13858420020627301509U;
        aWandererE = 9907760539714297129U;
        aWandererF = 13811152500764033112U;
        aWandererG = 13219616965341164204U;
        aWandererH = 16870944703817672015U;
        aWandererI = 15910601506914789870U;
        aWandererJ = 10863400847561195458U;
        aWandererK = 13460127332130070993U;
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
    TwistExpander_Fencing_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Fencing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB0963987A6B75AB4ULL;
    std::uint64_t aIngress = 0xEB5F8750F721E45FULL;
    std::uint64_t aCarry = 0xD9583ED60D1D1325ULL;

    std::uint64_t aWandererA = 0x939B7C61625453C1ULL;
    std::uint64_t aWandererB = 0xFE0DA85EEAC2A5A5ULL;
    std::uint64_t aWandererC = 0xCD686E60A3434A61ULL;
    std::uint64_t aWandererD = 0xD27628D23313CF3DULL;
    std::uint64_t aWandererE = 0xE7B5E9C3871CCB58ULL;
    std::uint64_t aWandererF = 0xD3AE54C676CB2B22ULL;
    std::uint64_t aWandererG = 0xE61F69AFDB6806D5ULL;
    std::uint64_t aWandererH = 0xC2084D544FE66290ULL;
    std::uint64_t aWandererI = 0xA6781C31C06E6010ULL;
    std::uint64_t aWandererJ = 0xD5C61A87085CEB92ULL;
    std::uint64_t aWandererK = 0xF5CFD431E29F9452ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneA);
        TwistSnow::Aria256Counter(aSource, aSnowLaneB);
        TwistSnow::AES256Counter(aSource, aSnowLaneC);
        TwistSnow::Sha256Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    TwistExpander_Fencing_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Fencing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Fencing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE438902E2AA9EE68ULL; std::uint64_t aIngress = 0xF7CC3EDC42C2ED86ULL; std::uint64_t aCarry = 0x9861459EC1CC4253ULL;

    std::uint64_t aWandererA = 0xEEAFA2DA6B7042F6ULL; std::uint64_t aWandererB = 0x95D54C284A5E4BF8ULL; std::uint64_t aWandererC = 0x98F877825D3AA742ULL; std::uint64_t aWandererD = 0x814354644D48408FULL;
    std::uint64_t aWandererE = 0xE0543CC8031ED1F5ULL; std::uint64_t aWandererF = 0xF6392CDA6410714FULL; std::uint64_t aWandererG = 0xECB2F92173F57810ULL; std::uint64_t aWandererH = 0xBDDBA5D317676FC1ULL;
    std::uint64_t aWandererI = 0x9EA5E5D8C3E637CBULL; std::uint64_t aWandererJ = 0xD90E5C45B1F678FEULL; std::uint64_t aWandererK = 0xE5A10CE2649875B6ULL;

    // [seed]
    {
        aPrevious = 9663388973540038961U;
        aCarry = 16896132911639052216U;
        aWandererA = 15193437240048271863U;
        aWandererB = 17286582282397253592U;
        aWandererC = 15152459316694510612U;
        aWandererD = 17464415655321496172U;
        aWandererE = 12603601358742487937U;
        aWandererF = 13160890272259345970U;
        aWandererG = 15581167836098666679U;
        aWandererH = 14145195765552604795U;
        aWandererI = 12259213262838074371U;
        aWandererJ = 13393855514209911569U;
        aWandererK = 16235005504000759099U;
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
    TwistExpander_Fencing_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Fencing_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Fencing_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Fencing_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Fencing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 2, 0, 1 with offsets 654U, 3907U, 6677U, 7660U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 654U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3907U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6677U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7660U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 1, 3, 0 with offsets 7323U, 7675U, 6530U, 986U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7323U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7675U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6530U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 986U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 2, 3 with offsets 7161U, 5639U, 5492U, 919U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7161U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5639U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5492U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 919U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 3, 1, 2 with offsets 7678U, 2911U, 842U, 4449U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7678U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2911U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 842U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4449U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 0, 2, 3 with offsets 1268U, 94U, 703U, 781U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1268U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 94U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 703U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 1, 3, 0, 2 with offsets 480U, 1475U, 2028U, 1115U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 480U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1115U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 3, 0, 2, 1 with offsets 1596U, 1450U, 83U, 503U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1596U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1450U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 83U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 503U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 0, 1, 2, 3 with offsets 1022U, 474U, 1918U, 1204U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1022U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 474U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1918U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1204U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 989U, 987U, 257U, 560U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 989U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 987U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 257U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 560U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Fencing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 2 with offsets 3452U, 5018U, 3290U, 5150U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3452U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3290U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5150U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 0, 3 with offsets 7435U, 7707U, 7190U, 2783U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7435U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7707U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7190U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2783U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 1 with offsets 2866U, 3463U, 2106U, 941U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2866U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3463U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2106U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 941U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 0 with offsets 1582U, 3905U, 8135U, 7352U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1582U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3905U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8135U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7352U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 441U, 2963U, 1632U, 5727U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 441U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 2963U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 1632U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 5727U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 39U, 943U, 10U, 221U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 39U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 10U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 221U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1286U, 1365U, 566U, 1801U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1365U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1801U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1996U, 1606U, 1670U, 884U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1996U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1606U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1670U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 884U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 58U, 1267U, 919U, 99U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 58U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1267U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 919U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 99U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 2, 0, 3, 1 [0..<W_KEY]
        // offsets: 35U, 556U, 1677U, 12U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 35U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1677U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 12U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseASalts = {
    {
        {
            0x3F3ABD22DB2825C5ULL, 0x66912E80B2F7AFC0ULL, 0x627ED59835D35030ULL, 0xF3193447C54AABF3ULL, 
            0xC099CA2C359E2FA7ULL, 0xC45253E84737C35BULL, 0xBB81C376A9C81F9EULL, 0x41D95AC948FCABE7ULL, 
            0x08F8F755380FAC9EULL, 0x918F11AF082B3CB6ULL, 0x5403379FBB9F91FBULL, 0x1E15299DF42E8D9CULL, 
            0x96D83E287F6A5C0FULL, 0xCDFE05315F41EA1AULL, 0x8D04BA5FD69CE1D6ULL, 0x5B505F2C291843CFULL, 
            0x978A1CACB21A1368ULL, 0x622C7623F86DF59EULL, 0x92FB63CAA0A9EC3CULL, 0x682D42D4E9D93208ULL, 
            0xFA9CA659BBA5482AULL, 0x7EB4E9D9516B32FBULL, 0x6DEC0AB1BBEF83FBULL, 0x6608CD13E8EC7C54ULL, 
            0xFA29B32B3C3B7354ULL, 0x942807BB4679DAFFULL, 0x06434736B9C7E582ULL, 0x74CCA67A51EB67F5ULL, 
            0x2C3CB700A6350C51ULL, 0x0795982222B447D7ULL, 0x7D0286C48627345FULL, 0x56FAE491B7246928ULL
        },
        {
            0x8C80F84D9F2DC686ULL, 0x0444B08A8BCC86CFULL, 0xE8294F1574B1CCA0ULL, 0x068BCF48587D217AULL, 
            0x3684CEFC6A4D1B92ULL, 0xC15BD00C24823178ULL, 0x8091FF4D57DBAA32ULL, 0xB1DC805B605167A1ULL, 
            0xA48AA5F5EF7113EDULL, 0xD6EE1A0938B1423BULL, 0xE666CB276DC95622ULL, 0xC458B10F94B94FDFULL, 
            0x12ED4D0DD4AF5999ULL, 0xD644295DFEA0222DULL, 0x4B0189401D56D723ULL, 0x7E056683FA8B5D64ULL, 
            0x5664E6C937A1CACAULL, 0x83699505C3168B0DULL, 0x7A4A88B8790C37C3ULL, 0x7689EA160177C5C9ULL, 
            0x1D351461076E949BULL, 0x07B5F6FE3949B42AULL, 0x19D0F0424621F9ADULL, 0x706D51C451E8D79EULL, 
            0x1F9DE1C9B4AD3BADULL, 0x687B832619E92A96ULL, 0x600986015B3F4AA2ULL, 0x7F34F68F68247952ULL, 
            0x148E99B20575A180ULL, 0xF9AAB45DA0068210ULL, 0xF3B9A89BB19B883CULL, 0x571F170634812998ULL
        },
        {
            0x073DEA95BAE1F948ULL, 0x93B9D690C9E317E0ULL, 0x826811CB886019FCULL, 0xB394E714236291B4ULL, 
            0x9092CD760E3CC5B9ULL, 0x09E769EF6671DA40ULL, 0x53CD11641AA9B9B9ULL, 0x824471A7711FE613ULL, 
            0xC821243A36D7A503ULL, 0x28CFAC04297ECB1FULL, 0x833A76471A820BB5ULL, 0x3A5A3CB54F4B917AULL, 
            0x978B52B08B2E6C4BULL, 0x00CED64820148D52ULL, 0xAAF9A95A0C135A1EULL, 0xACC8AD0F1F1E6B18ULL, 
            0xC955EA953B49CEBEULL, 0x6FAAED6C43EE2816ULL, 0x89B03190D52C2CAAULL, 0xD64B0814E97D71ACULL, 
            0x742433634B003954ULL, 0xE08637B86E381AEAULL, 0xDB826F04F740D226ULL, 0x4BDC60374DC10904ULL, 
            0x082385017E42AFF2ULL, 0x84E8671FC6297D33ULL, 0x471CB2FD8C917F12ULL, 0xCA12F6E98BD444EAULL, 
            0x86AD9ECEE12D155DULL, 0x4D94B5ADC9AC7D62ULL, 0x52BEEE27256969ACULL, 0xF2F3BB1D03CBD7D8ULL
        },
        {
            0x0985270823DCAB1CULL, 0xD23CCEBAEAFCFCE0ULL, 0x7D1D234D6F5EF81BULL, 0xE4B03C38D281D623ULL, 
            0x3394429F19EA04A0ULL, 0xA7401CD4C376D271ULL, 0x4233CE151DCCFC28ULL, 0x8EB14C15F7DF4CB8ULL, 
            0x333025775B652884ULL, 0x082E21BC9A91D71DULL, 0x398EB3BB6B531634ULL, 0x50EF69C6158A2CEFULL, 
            0x9B851D34B0B86565ULL, 0x02DF65DBBAD4C427ULL, 0xF37DA9F474BE9D88ULL, 0x62019D13027FDE77ULL, 
            0xFF290AC7E60D2C72ULL, 0x601E9F912C79FC86ULL, 0x30042EB85C327786ULL, 0xD5E30F2E7125B1BBULL, 
            0xDD5B6F3013D47AE2ULL, 0x63B709DDA54E43EAULL, 0x926CD1805574D16FULL, 0x90765BB9C23B5D32ULL, 
            0xE87BFE26C29325ECULL, 0xAD4143F9FE22BC4FULL, 0xB68E2CEC4B13644DULL, 0x73AAD05FB2520293ULL, 
            0xFFE21D933ECA9ED1ULL, 0x7955B6264279D7BFULL, 0x72861D0DA0C4CD3BULL, 0xBC38427264BA4B5DULL
        },
        {
            0xA9F7AADC8F6ABF64ULL, 0x454644BCC5BAFCFAULL, 0x8494C5BDF3C9450EULL, 0x74ED5A60D7DEE84BULL, 
            0x4E199BD767E93F29ULL, 0xD8F52948A553AC1CULL, 0x55D45E0CA5F3604EULL, 0xBF399612C5F90846ULL, 
            0x9098A6CA71558D57ULL, 0x36351DC8D3397FA8ULL, 0x93E2E065B23145AEULL, 0x1CC7B6DE3615CE06ULL, 
            0xD5EE4EA6CCF8EB96ULL, 0x9EEBFD40AEF7A441ULL, 0x7167B0FBEDB7A2E6ULL, 0x53C6D4CC90EC8743ULL, 
            0xB4408E25DC9E6B3DULL, 0xE9567785112A04E9ULL, 0x02DE5E9DE6753E85ULL, 0x1C437DAB5497127CULL, 
            0xEE36FC31C7CC5B74ULL, 0xECABB3B5CBBB593CULL, 0x17FF066AEC8B4CF7ULL, 0xD5973E13A614A873ULL, 
            0x6B2AE9F6296EB193ULL, 0xF6E288E507C67AE8ULL, 0x9300BCEF275A1783ULL, 0x41EBF4128855BC02ULL, 
            0xBF3C2BA1914CD12DULL, 0x5058DF0D508E5E28ULL, 0x31B7D1370BA50818ULL, 0x5B070DD3D846C463ULL
        },
        {
            0xBAD292E2F846C5E2ULL, 0x5F08E1CAB4A10D0FULL, 0x4A25D0C3DD7DEA73ULL, 0x51CEBFF023368D0CULL, 
            0x00BF470E236E02C9ULL, 0x0C4D70198DFFF0FAULL, 0x3BADA46DB7B96D06ULL, 0x78B49D8B32575EA3ULL, 
            0xB9A865749B1EC55BULL, 0x00814E6ADE12F24FULL, 0xBD785BF719FE93AAULL, 0x654ECD67E5A6DC53ULL, 
            0x2D3313D427E4F62EULL, 0xDBA6F088541D4513ULL, 0x81B59FCFE2AD4970ULL, 0x624F19D3465E2BA7ULL, 
            0x9D48149519945AAFULL, 0xAACF5351BEDC8656ULL, 0x323BC9B18E7EDFDFULL, 0x821DD20013F51A53ULL, 
            0x0DD6715A24D5BB6FULL, 0x0F241163A88D798CULL, 0x779DA8ABDB009707ULL, 0x760376F1471135DCULL, 
            0x6E893C43CA9CD6D4ULL, 0xA0A6D02B2CC1E5A2ULL, 0xD9AEF5072B42627AULL, 0x3530D804FA459A78ULL, 
            0xC5CBC0BC383DA1FDULL, 0xC1A373749632A152ULL, 0x16B040421E768906ULL, 0x1F353312718B8166ULL
        }
    },
    {
        {
            0x35302C5F3E530F4EULL, 0x95A67E8CCE5A302BULL, 0x4F273DDFFE812A51ULL, 0xF3A1C6B15C198C7FULL, 
            0xF8964CDFD01E2B6DULL, 0x1D6283B05B500C6AULL, 0x26291897C46D0D61ULL, 0xB1630DCDA508092BULL, 
            0x4AA12AC8121BBB37ULL, 0x4A0CC9E020542D4CULL, 0xF09BC5C5AFEA3BB4ULL, 0xFC946D7882CBCBF1ULL, 
            0x2604345195C0FD8CULL, 0x91D7D98461D4E2D1ULL, 0xBB5949287C5DEE2DULL, 0x7D0D1954A5EBDC38ULL, 
            0xB4B6A733C5F7B66FULL, 0x57AA491E58DDD96DULL, 0x7557BAFF5E9F9788ULL, 0x401AE12734ECC182ULL, 
            0x9A269949865D928BULL, 0x5C2715128FD39E36ULL, 0x6005B6C16A3B088CULL, 0x0ED6ABCA3B40F5C3ULL, 
            0xA820EE8A3B0B26BAULL, 0x21AEFC2DCD53F696ULL, 0x695C4E25E2E64CE7ULL, 0x9A52F8B8AD02D8A3ULL, 
            0x7013D3DBA748009DULL, 0xC8CBC454EE0B9624ULL, 0xB5EC09C67B7251FFULL, 0x03EDC9DE645D9981ULL
        },
        {
            0xCEB058653AD51D54ULL, 0xBBBD8606193B7944ULL, 0xE802A4BB206ED413ULL, 0x933C636BFA01D9FEULL, 
            0x7A7D0300482EEBB4ULL, 0xB370002AB1F5420FULL, 0xBDDFF7C95497684BULL, 0xADCB232725D10A33ULL, 
            0x4CAC578D4B3B1272ULL, 0x8FCB3848FE836BEDULL, 0xC7B3E79FD3908B4EULL, 0x62DBAE0D6B3EC46FULL, 
            0x36F7B87017198EC2ULL, 0x405EC18755813BD4ULL, 0x527E40B137E4205DULL, 0x039C4044FAC71F65ULL, 
            0xDBE66047253E8387ULL, 0x631E5FD980C95EBEULL, 0x91D81E0334F5D417ULL, 0xB074D4FF5D6F6F8DULL, 
            0x67EBB50C5D26EEE0ULL, 0x5C29187CCFCE2261ULL, 0xD4DF4BC2981A0911ULL, 0x2F0C4A3CB0E3AA29ULL, 
            0x48BC51ACC6FCC2A5ULL, 0x45375521F724715BULL, 0x78D02DF16B0BFDE6ULL, 0x654CF55191212537ULL, 
            0x389F60BE8E633F90ULL, 0x4A5FE486D5A4F9FBULL, 0x0A800B9179FD88D6ULL, 0xEE2AD530119FDFB4ULL
        },
        {
            0x6CB510E5AB0001A0ULL, 0x2303F6D20CC38D85ULL, 0xE81BAAA8E37C1345ULL, 0x74EC06ED2E28814AULL, 
            0x18E17421615E6510ULL, 0xEBDF83599D81AF7DULL, 0x4A1EF87C5AD5C9C7ULL, 0x117FF82E1EE269D8ULL, 
            0xF70CB0A4FE16BF48ULL, 0xC0935F456BBCBE11ULL, 0xCC2E4FF79660C6DCULL, 0x1A66CE8A395627FDULL, 
            0xF9740358DD8C51BEULL, 0xB741DAFE8254AA25ULL, 0xFEF7CE31D268EC70ULL, 0x3239A305B18C7D5DULL, 
            0xFAC9BEF4A7496B3FULL, 0xD02688EC17828277ULL, 0xB0DD3AA28BED57A2ULL, 0x080FF1A0F0ACC82BULL, 
            0xED4E2EA61E68B3BEULL, 0x47D098B1C173E4ADULL, 0xFCB4EFCD55A6948DULL, 0x5E5E6B7F11F2D3CEULL, 
            0xF4CCBE49B2FCAAF6ULL, 0x5263847C87BC20EAULL, 0xBD6C44F552EC0420ULL, 0x91D2CEC95B8F126FULL, 
            0x34DD0CAC0C0931A7ULL, 0x35A3718718B833C0ULL, 0x7BB8E2433866AB6DULL, 0xB8A4BE4886469DC0ULL
        },
        {
            0x4AA01326A0F10B92ULL, 0x93A3612086BEC117ULL, 0x3B842F1E99E641D6ULL, 0xACBE40A9DE4494A2ULL, 
            0x50FBE822A8B3AD5DULL, 0xEDCBD4D5093E1545ULL, 0x115638F6D23D2026ULL, 0x9A74B25BF5E92E0FULL, 
            0x3BFCB6B46488BCBEULL, 0xF4B300EB096487E6ULL, 0xAFEB43AD06B64EFDULL, 0xEFBECED6847A6A8FULL, 
            0x08D0848BE0B747F4ULL, 0x4AB37277BF760B49ULL, 0xB517205F527411FFULL, 0x924DD6C1357B2208ULL, 
            0x5744F687B9A607DDULL, 0xCF8176BB9FDA175EULL, 0x397550E21140E27DULL, 0x47FB9174DE99DD00ULL, 
            0xAC5554CE8BE0D8F4ULL, 0x538FF5C10DE27506ULL, 0x45656FB567A527FAULL, 0x736C0ED895C50D7AULL, 
            0xEF208B8A34E49AFEULL, 0x8D99385F6399ACA9ULL, 0xDB79B38EE5253775ULL, 0x17E99D60143215EFULL, 
            0x9879725A8BE63048ULL, 0x2A324DBD7071F13FULL, 0x677B28BC0169A2C6ULL, 0x7A209B72731DB758ULL
        },
        {
            0x4F2F106EAC262199ULL, 0x1CAD9A625409401EULL, 0x6AC2F95D9B589D33ULL, 0x8DD78B033A46EA30ULL, 
            0x9A5A0D5CDE03E39AULL, 0x90EA29F35CAF9F1EULL, 0x3DBC3341CC4DC2D3ULL, 0x28A352D216B39BC4ULL, 
            0xFE23A87FEAEC85EDULL, 0x4418947E58E0B8F6ULL, 0x3DB640B498A28936ULL, 0x19C0DAEBCD184BD3ULL, 
            0xE009619637A29E2DULL, 0x939A4E260B894831ULL, 0xB08621976F020F52ULL, 0x1A723A03AB954B2FULL, 
            0x386651E1B9209749ULL, 0x541F569ED362525CULL, 0x7C67484446763FFAULL, 0x1FC4021EDAF541E2ULL, 
            0x47938F1D23376981ULL, 0x7C95ADC351982EC2ULL, 0xE4572D78F892083EULL, 0xCE18B255D9B03E69ULL, 
            0x4596A8828194BA2EULL, 0xFEF6B8BDF89177C3ULL, 0x1E372FA6856C4902ULL, 0x22A05F0A07058F26ULL, 
            0x9F8EAA606B472F21ULL, 0x5A290FB0DFB8FFEAULL, 0x5A9BD09E3CFC4B04ULL, 0xE7C3280615960B4AULL
        },
        {
            0x34724DF0E1CE47B8ULL, 0x70FEAE3F4DBE16C2ULL, 0xBD6675923016A738ULL, 0xEC9F021A837A383EULL, 
            0x0C8510585924B9E7ULL, 0x626D972617BA77D7ULL, 0xDF0791695F6184A5ULL, 0xCEFB1EA71DA0AD6DULL, 
            0x36EDCEE7E6F202C3ULL, 0xEFB0AB0A1ABA0EAFULL, 0xFBC5B28C9699297EULL, 0x3D0CAF1BF87730DDULL, 
            0xA304A6337C94AADCULL, 0x15B81AE8A05F06CEULL, 0x5C4B27E99F072624ULL, 0x3502F5C91DF2DEE2ULL, 
            0xCC53C67AF66FB8BAULL, 0xBD03D53A2577290FULL, 0x1CFA9E15F26A3CADULL, 0xCBBAED84E3D0025BULL, 
            0x804F4320660562C0ULL, 0x58FBDA18778C5E12ULL, 0x912AF69623E72FCCULL, 0x11D77635F992B77EULL, 
            0x50DE7C26DBC7249BULL, 0xEC2AA66B7A2FA681ULL, 0x82E8F6DE023110C9ULL, 0xBAD4A8E64DCFBAFFULL, 
            0xB28E9812D414773BULL, 0x761FE03C673DDB37ULL, 0xD8C93658BB11199BULL, 0x20CF295083E9F33AULL
        }
    },
    {
        {
            0xF94D2A8F2547E095ULL, 0x88C1D7E13288592BULL, 0xC130102400937EF2ULL, 0xFB1A156D1976A1B3ULL, 
            0x65C34186CC5C094AULL, 0xE940DB11491EA080ULL, 0x92DAE6102102B830ULL, 0xEA9B3B19D63EB11CULL, 
            0x173EFEEA9C95B619ULL, 0xFDAD9799E62562D9ULL, 0x3CEA058FF4F802ACULL, 0x8DC57EC161B6446FULL, 
            0xA667F840E28F9EDBULL, 0x3D1CED507DB628A6ULL, 0x3A1904DC0030A297ULL, 0x2C291A9F34CF9698ULL, 
            0x6381540BB846A94BULL, 0xF0EF67A9C1C0DD33ULL, 0xA6B65D361A6B8051ULL, 0x700A3180D6723F1DULL, 
            0x384DDAEB46CCB02FULL, 0x6101A454E48037A3ULL, 0xA9B91C3DE20559CDULL, 0x54F649C63043EA97ULL, 
            0x4C3C0CDBE5ACBB99ULL, 0x3FB6C051F49E5064ULL, 0x8A0548D641351528ULL, 0x24C9EC136EBC20EFULL, 
            0x4022D6FB730EF57DULL, 0x46384A73A9BFB669ULL, 0x916E26F4AF72C5B1ULL, 0x827DD66A1E5B1611ULL
        },
        {
            0xBC60A33B87D7C1A8ULL, 0x50FB8DD14AE8C4F7ULL, 0x6F0E5037073D4495ULL, 0x3C6BDD3BF0BD0175ULL, 
            0x468F596E158B7C38ULL, 0x1D15ADB568889149ULL, 0x891FBE8D5B815A11ULL, 0xA3D358F85CE6D8F6ULL, 
            0x923B37EC55DE052AULL, 0x9AA09E6A318F1264ULL, 0xEC51514428DF13F5ULL, 0xB639B6A4D9F65D24ULL, 
            0x0A4952C58CC3C8D2ULL, 0x9952FC07E8387FE5ULL, 0x4265D325271A027FULL, 0x7E4E6EC787774BE6ULL, 
            0x612C875625CA9025ULL, 0x26F76390A9403336ULL, 0x7EECB834B0DE0F9CULL, 0xA518AD3DCA11A8DBULL, 
            0xD0EFF74182B3CF35ULL, 0xF7E05A742DA1F9ADULL, 0xC3AE95AC7E6B481AULL, 0x585D4EE670A2EA70ULL, 
            0xE413CDD36D9B0068ULL, 0x4C49913911C474FAULL, 0xFC55AFA83E00B0F5ULL, 0x089827E96C366C14ULL, 
            0x4D1488A6E1E4A631ULL, 0x8004D25956AE2FDAULL, 0x53DA5595FB080412ULL, 0x2992852B4EDFE872ULL
        },
        {
            0x4F0C19404088FD10ULL, 0xB9AFE6473F3DFCDEULL, 0xAB8C17BA2915482EULL, 0x2157FEA59A8C6163ULL, 
            0xD85C6BFBC1157A25ULL, 0xCD9B6A52D11B18E3ULL, 0xB5FB45864D0042D6ULL, 0x47E872D788AA8786ULL, 
            0x05BFB57F279D6FB4ULL, 0xACB2F77F9A8F74FDULL, 0xFC77DAF9B5164A96ULL, 0xEA74DA03977DA2D0ULL, 
            0xEACBA1B73E409DEDULL, 0xBEA0BA4A934FDF53ULL, 0x0078013FB3C456D2ULL, 0x09B5E358D5BD5C2FULL, 
            0xA423C2347D6A6F64ULL, 0x747237EFE22A9F05ULL, 0x297F0E8291588223ULL, 0x1139D5E81451515CULL, 
            0xC2D1FAC3CF2FC95FULL, 0x693C917C32254AEAULL, 0xC44ECF49A0946D2EULL, 0x716E15E829B6C9C7ULL, 
            0xBAE8A48CFE2411E0ULL, 0x95ADA3DBDA30332FULL, 0x6051A542545903BEULL, 0x2C68946C0337BE9EULL, 
            0xE867642A721FA615ULL, 0x5BC2DAC95185D818ULL, 0xEECE975306CC39EFULL, 0x77832608FC5C9060ULL
        },
        {
            0x804E4A7966FE571DULL, 0xC609512321AAE627ULL, 0xF178F84D78C1A653ULL, 0x3C528E493507B809ULL, 
            0x4BCA5B31A6F0338BULL, 0xE49C8BCF4A1C09AAULL, 0xAE8F2B50A8205045ULL, 0xFC12A6CE2D32A852ULL, 
            0x71B4A0215631A7FBULL, 0xA26E2B6BE3C0A121ULL, 0xF61A5BDCBF9B680AULL, 0xBA984C5538A0C019ULL, 
            0x99FDEAE5C3307640ULL, 0xDEE40AD40926E275ULL, 0x9DCD656197EF39D5ULL, 0x3EE9497CCCAE6737ULL, 
            0x6CD5EB10F2ECB7B5ULL, 0x83C9C9EBB03136F2ULL, 0xB67A4DA728949611ULL, 0x6C9450EEA750BA8FULL, 
            0x447CF64067CB5CD7ULL, 0x570AFF03A0F35CE6ULL, 0xA6B981B8C1913EC9ULL, 0xB5F1DE2894F4ED9FULL, 
            0x06ACFDB4FECABADDULL, 0xA6FA803DB758DC00ULL, 0xA24FF864B6CE1EC4ULL, 0xD00C8497B333DF3DULL, 
            0xFA5FFE8C7CE8D20CULL, 0xC9C2A86493350398ULL, 0xBC6277D25B95F219ULL, 0xBB2A45773B12D34EULL
        },
        {
            0x0191D0C6C92C80A6ULL, 0x7875B08376498B10ULL, 0x5A4C3C6AFBDD567EULL, 0x683101561D3C5DAAULL, 
            0x99838310F241A1B6ULL, 0x74D7261BB59B882EULL, 0x0399D98DF4D5D200ULL, 0xF79AE0A5E093FEADULL, 
            0xD623409DF0853E01ULL, 0xC87C7AB21F07F03AULL, 0xAAA0F3E7EE1D4922ULL, 0x5B335973C032CD92ULL, 
            0xE9599A63E4455F0DULL, 0x5613366585BD5003ULL, 0x93A14840D2783801ULL, 0x304C15CCC13784F1ULL, 
            0x0CB1F2BE20E8D629ULL, 0x1C1E508337F2FC4CULL, 0x8A54D64A603F0520ULL, 0xC6A3D2915EEAF9A3ULL, 
            0x08CC2A355081BD60ULL, 0xCE8C84EEE7B50625ULL, 0x300491349E51862FULL, 0xEF63FA8872D31AC8ULL, 
            0xFEAF46A3FFD00026ULL, 0x5653B596DB84CC74ULL, 0x66F292CADF5FA44DULL, 0x1E6DCE6323B59696ULL, 
            0x734656ED8203C71DULL, 0xAC6B958604CD5EF9ULL, 0x4BF5231FF34B0B76ULL, 0xBA6950D61F2A3FE1ULL
        },
        {
            0x9779CAAC72926627ULL, 0x95C3DFBD310AFE5FULL, 0x6CA9035404402828ULL, 0x1E1E03338918206CULL, 
            0x0A6450E45DC5FF0BULL, 0xA4E1DE11CD637551ULL, 0x710D3A62AD1E0073ULL, 0x1128F81F1F66240CULL, 
            0x2612FE975D08084EULL, 0x581B482F9580C36CULL, 0x4C9E9CF679C3D729ULL, 0x61337D08AAB98951ULL, 
            0x28A751DB08904FCDULL, 0x807D18254938D35CULL, 0xAE122F912D9C1818ULL, 0x5DFE9BD02051B3DAULL, 
            0x7EC112228ACFD957ULL, 0xFA9ED45BC69712F9ULL, 0xD81BC4C79CD4440FULL, 0xF333AACED88F27F5ULL, 
            0x56682F712474DD18ULL, 0xB3847207AF5A6E90ULL, 0xA7081FB43B5D9E3CULL, 0xB1D67F20494A0E3AULL, 
            0x136EEEF2384CAA57ULL, 0x1D30F8B8286A90F2ULL, 0xDE8B6758385D92DEULL, 0x254B875D47B983F6ULL, 
            0xA03D3D4A649E4202ULL, 0x1CA5FB802BC89CE9ULL, 0xA6DAE38087E14808ULL, 0xBD1CC10A8BB72066ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseAConstants = {
    0x3B7954183E6901E9ULL,
    0xB4A83028D4DA9C3BULL,
    0xA8A42F05D54F094FULL,
    0x3B7954183E6901E9ULL,
    0xB4A83028D4DA9C3BULL,
    0xA8A42F05D54F094FULL,
    0x60C919FE8B25BEA6ULL,
    0xD9E447A8CAE306E1ULL,
    0x2F,
    0xA5,
    0xE7,
    0x59,
    0xC4,
    0xD8,
    0xCD,
    0x78
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseBSalts = {
    {
        {
            0xC9B8E7B2C5303337ULL, 0xA37F0F75322CB245ULL, 0x3F80F717CECA6452ULL, 0x3020822BF8A7762EULL, 
            0x74D7EFEEBCF1B7C8ULL, 0x3CD4FF917B96FA0BULL, 0xBE1C9B15BA861449ULL, 0x85CDA406E28FB394ULL, 
            0xD8DF6AEE69F5E72AULL, 0x146B84E86771A599ULL, 0x14DB71F14578DBD3ULL, 0xFC37C3C5D681AE8AULL, 
            0xB8F99B53A7613D71ULL, 0x71E59650BA0AEE10ULL, 0xED9AC939D98CEA60ULL, 0x7B0F0929CDE83E8FULL, 
            0x403B03CA1E6A0363ULL, 0xA3B89F12E1FE3D3EULL, 0xE79C5F0D7CFF074FULL, 0x7C9164C320B709C6ULL, 
            0x15ED6A7EC2A85DC9ULL, 0x0BDECEFD9B12E543ULL, 0x407AEE6262FEA88BULL, 0x3386E156DE2E8CD1ULL, 
            0xE01A0FAB0DA93B56ULL, 0xE386E2BF71C80860ULL, 0xBA00CB61D3FE514FULL, 0x8F35E438D3A37D10ULL, 
            0xB4A0365936EE47D5ULL, 0x03B417648BC833C4ULL, 0x7989C138F8203A6EULL, 0xB03FE1B50FBF1E8FULL
        },
        {
            0x3033327E445C14B1ULL, 0x9FA685E520C71BF4ULL, 0xA2761D4F712BB272ULL, 0x4957D15B7570C146ULL, 
            0x5D7234650645E691ULL, 0x416E1709A62FE39DULL, 0x054946A26F09BC6EULL, 0x9C5E98ECB8596456ULL, 
            0x66213241D72709EDULL, 0x91AF74E5A516EB59ULL, 0x67C39A88C8BD80C7ULL, 0xB656AEA5E64D22C6ULL, 
            0xCDD28C5A3C46B671ULL, 0xE4BB8550A678C498ULL, 0x9924CBF355125C87ULL, 0x3CA7107BCFFDBD33ULL, 
            0x6B84A546B8016FBEULL, 0xB83FA7C0A739910FULL, 0x94DB32F5FE4C755DULL, 0xEC3363E2BBBC3715ULL, 
            0x2DB660276A50E8C4ULL, 0x3FB4FB3E90861B9DULL, 0x131069A36F5D7E8FULL, 0x3F794C9A22B57994ULL, 
            0x82ABE0A7A9FA31E8ULL, 0x1C70538522719FFCULL, 0x9A7B13D4C0721141ULL, 0xA78E962C7160FF97ULL, 
            0x025F37A21291CD72ULL, 0x56F98F5759EADB6CULL, 0xD1B4FA874BD5F77CULL, 0x714E337C5D613C9AULL
        },
        {
            0x7439EA01C854ED10ULL, 0xB2859C28DF547B59ULL, 0x21777FDF47CEF7BEULL, 0xCE08FA6510A94AFCULL, 
            0xB22665B83DF74893ULL, 0x9B3C7FC15B634099ULL, 0x39BAF84EDFF072BAULL, 0x9F2308731E1B98CAULL, 
            0x54FBC0C7DCB03DB9ULL, 0xFBF423FCBE422648ULL, 0xD8226053DA06F659ULL, 0xE461FBBB4BA1452BULL, 
            0xBC63206305E389E1ULL, 0x13C746B45AA4A959ULL, 0x93FA553C88FC0E76ULL, 0xB79413716B3A9410ULL, 
            0x87625602CB87E658ULL, 0xC547381924ADA1C1ULL, 0x4B839A1831BBB71FULL, 0x20E40DDBD1C7BCF5ULL, 
            0x111DDFE9BD0A980BULL, 0x7209011632C8CBF3ULL, 0x66BC58D51DCC440CULL, 0xE49EF762B38E250AULL, 
            0xB6B44CF9D51930C5ULL, 0x6A26244AA12626A1ULL, 0x13E80259824079E2ULL, 0x3011C1DDA3B6713BULL, 
            0xA3D0724D1087E379ULL, 0x5C10AA0EE2C8143AULL, 0x9F1DC7FE99CE57F1ULL, 0x6BCF0F89D40EE026ULL
        },
        {
            0xF91B42D1F102D036ULL, 0xE26F5805F4A7D6DFULL, 0xA601B0B5C27F4863ULL, 0x29396DA57B07388BULL, 
            0x3039BEE22032B4A8ULL, 0xD6493004B67C0A41ULL, 0x1D6F0FD47FAD5891ULL, 0x92A717EAB43A7DC3ULL, 
            0x3214D512A37CC28BULL, 0xADC44B441FA32727ULL, 0x1BFFEC5A2C6ED7DFULL, 0x150B35F1322DC38EULL, 
            0x717AFD5C2415CEACULL, 0x567F9A294726B875ULL, 0x335C9637A6DBC866ULL, 0xE8FAA0520CB80C5BULL, 
            0x673BC1A1F5687BE1ULL, 0x4BBC1C87EA5E36A6ULL, 0xE4B2A27BA59F1784ULL, 0x9697E6B406DE4659ULL, 
            0xA21AC599C23BA103ULL, 0xCE1E1489C05C000AULL, 0x3FA21C82598A38ACULL, 0xF1503A498ADE267AULL, 
            0x5C868AA0FF31F5AEULL, 0x7651584429DF2CF8ULL, 0xA2EBA049CF931532ULL, 0x6C632FA85F113674ULL, 
            0xAE40D095972D7CAEULL, 0x37F7F241369021EBULL, 0xB82C7560F7418EDBULL, 0xED7866EA239B0D4CULL
        },
        {
            0xE2A2353EF2C6DD40ULL, 0x4611CAE16218EF4AULL, 0x02C03D92B6259614ULL, 0x177F6D8AC9BB27A8ULL, 
            0xD1944474F1D4DADCULL, 0x8CE61C738830F61CULL, 0x80BF08C2D2731E10ULL, 0x2FFB0648559B4A6EULL, 
            0x9C18C0A0EFD92B23ULL, 0x03B884550DB076C9ULL, 0x05E9FD1CEFA0BD71ULL, 0x2D5135A942C393E3ULL, 
            0x65D457CFE1749618ULL, 0xD5CC60F08F8FC20DULL, 0x3E690EFF983835F7ULL, 0xFA7F2E5CC5272D86ULL, 
            0xAA012058BB5B5BFAULL, 0xD25D5222F988EDE5ULL, 0x9DEAE4FC7B7085A8ULL, 0x2E7207BC11905194ULL, 
            0x44CEE1D2C8F8E7DBULL, 0xB08E6706B21A9C24ULL, 0xA6D94660EA09102CULL, 0x89419F94BE12A910ULL, 
            0x24E31987A6E1C805ULL, 0x11CCFF3A18CBC3B9ULL, 0xA17A0E1638A56A03ULL, 0xBAD6897A00687B1FULL, 
            0x1F69E06F5F94F781ULL, 0x3111727041996848ULL, 0xBA860005EBE3AA63ULL, 0xA0E25B6BCAD1D233ULL
        },
        {
            0x0F2A00BA038B0275ULL, 0x02D768A31E451CD1ULL, 0x9BB828A7E001BD22ULL, 0xC5FCCE3F496E424AULL, 
            0x1B46C511E1C98815ULL, 0x54A71856547B7C14ULL, 0x71B012AC3742E9C9ULL, 0xCC2BC63B7511BAC2ULL, 
            0xB57D03DBF1C7BEC8ULL, 0x49C88239309CFB72ULL, 0x031C7879F85DCE28ULL, 0xE201A93C2EEAC699ULL, 
            0x3E98CA9EAA2F25AFULL, 0x4F33BF96EAB92654ULL, 0xE6322DD2108E3EECULL, 0x4D7FF04F16EFE64DULL, 
            0x2D43AE6CA241958FULL, 0x113DD204CDA70E26ULL, 0xD454C89572445BBCULL, 0x54C5203FA4316285ULL, 
            0x069488248B58495BULL, 0xFCAA0AEB7272F30DULL, 0x4BAFC15279FBA1F5ULL, 0x1530A937E034100EULL, 
            0xDA0AE24EAA922CDAULL, 0xBF68672315D24E71ULL, 0xA1B0629571BB9704ULL, 0xF6866E0A56B4F875ULL, 
            0xE60BD95101DD2D28ULL, 0xB01BEDC13B6FD552ULL, 0x51DB848E4C1583A2ULL, 0x37999BCBDF8BA603ULL
        }
    },
    {
        {
            0x31377C609EB9B4C0ULL, 0xF96E72B55FFF5822ULL, 0x0546CDCE0192C13AULL, 0x6E47CE925AA35CE8ULL, 
            0x3DF02AA3B4A50003ULL, 0x28D0B588F97F760FULL, 0xC7F56E7A05FA598DULL, 0x5E73CCE550CA25E3ULL, 
            0x4BB5BEB57925E1DDULL, 0x6806FB393F2035FCULL, 0xE4AF8E9B4AA15E32ULL, 0x41F4DB2B884C0ED4ULL, 
            0xEFA4F8D1C75F27D3ULL, 0xD75B9444566D22ECULL, 0x0362B8298C29647DULL, 0x39380D3FBBB793CBULL, 
            0x2EB6522B5805C4B6ULL, 0xD4E2035B00C4C4E2ULL, 0x7BA0650E4414BF7FULL, 0x2A12ABA466B956B6ULL, 
            0xB87C2D64154AB92AULL, 0xB445CF66F13BBE0EULL, 0xB74EF686EED0F3F5ULL, 0xE0A0384F980803BFULL, 
            0xBB35CE1D8EFA53C8ULL, 0x2234D399A2A15F8AULL, 0x0C6252A237860DC0ULL, 0x0AC495841C91D752ULL, 
            0xBDF7331D87EE14B5ULL, 0x276496D33F272FE6ULL, 0x1C79BA76F48AF725ULL, 0xEA6370380C84312EULL
        },
        {
            0xCFD811A483EB451AULL, 0xC31EA26DD978C941ULL, 0xE2302C363B10C25BULL, 0xF90D1B479133BB37ULL, 
            0x98C6BB05F4D78757ULL, 0x77CCD80490F28A25ULL, 0xC06BCA96B7965E95ULL, 0x40E079BE40BA45DBULL, 
            0xDF3A9B8E787E1AB0ULL, 0x0F722D732E4AB4B6ULL, 0xB5F028679EFE2E26ULL, 0xD629DEF5C4147647ULL, 
            0x315E57E6455A72F1ULL, 0x3CCE8721548E0276ULL, 0x66BB93ECB02BCF3DULL, 0xF1261448232D814AULL, 
            0xEAB217C5B4E3EA76ULL, 0x7D892404EDFAFB87ULL, 0x6E1DC2487C561AECULL, 0x1299FB032D62F7F7ULL, 
            0xA38C0EE9B1734F22ULL, 0x8EE35639E27A9660ULL, 0x57FB5A4C90603396ULL, 0x141CE63C199BD843ULL, 
            0x3F9B067B238BF529ULL, 0x11393319C09312A9ULL, 0xE022C21C12F8F511ULL, 0x217A08346B6B2D4DULL, 
            0xDA4B0A671FA40CB5ULL, 0xB694E096FE012B5FULL, 0xAE15CAED38C05F8AULL, 0x50835385A5B532EEULL
        },
        {
            0x6767439D7BB6A767ULL, 0xF804438BC830DF0FULL, 0x9EE59BD8523E430DULL, 0xAEC2BF2221BBC851ULL, 
            0x49EFBC4258FDCB32ULL, 0x0E821520E8994968ULL, 0x95D70E6640F558E5ULL, 0x83F0E9F8E5672ECCULL, 
            0xB7778976CDCA0931ULL, 0x576C003570082B3FULL, 0x85C299F7730DEDDCULL, 0x11EEC721DBA2BB71ULL, 
            0xDA05162C99EA3C90ULL, 0xFB606DA4CBBFFE0FULL, 0xA2A489869B0E95A0ULL, 0x176B54D8EB1F32E7ULL, 
            0xA9FF8874978910BBULL, 0x261AAC5857AD4AFCULL, 0x680DF758ACB093EBULL, 0xB706BAF2594137CDULL, 
            0x6DB85A208418DD16ULL, 0xD4F47D1DC95DAD53ULL, 0x4308ED10683C1049ULL, 0x430B923E3379F34FULL, 
            0x0699470F8657E247ULL, 0x3E12E69335FB9D98ULL, 0xCC76049DD5F37A66ULL, 0xE5B2116DEA773614ULL, 
            0x61A10935E0BC5CB2ULL, 0x93218CC6A97C2ED4ULL, 0xF8C97C1CD27E285CULL, 0xA2EA6AE455C9D7FEULL
        },
        {
            0xABEBE3DB0AAC0905ULL, 0x4EBCF5D54ED48945ULL, 0x0B833514D5300C17ULL, 0x4F6083DBBCDB468CULL, 
            0xC409B8A0F6CBE1A9ULL, 0xFD7EAAF1DA0D34EFULL, 0x45A09353F9CAA6B7ULL, 0xBDE7B20E50807123ULL, 
            0xBA170617B09A662CULL, 0xF3151B71A5D95B45ULL, 0xCC89A4FBE9B06711ULL, 0x04020EF9BEB4B390ULL, 
            0xBAB9543478EF7BE2ULL, 0x0E250ACB9CAE958CULL, 0xEB0FA1C6DC1A7732ULL, 0x058F053D493C87AEULL, 
            0x05BBA445B748DB70ULL, 0x89EB240D0D63814FULL, 0xB22FAA03059B1F7AULL, 0x0E56F66A870AA2CBULL, 
            0xFF6B53923473C0D9ULL, 0x823B5A0722150C19ULL, 0x55CFE340D126A360ULL, 0xCA6E8B4603312383ULL, 
            0xB2A5920E4323843DULL, 0x9E8C9076B9F035DBULL, 0x8CEA3C4EDB6E8D4BULL, 0x002C65F75457DE88ULL, 
            0xD608267CC9EEC456ULL, 0x8D6A145ED00BAFC8ULL, 0xC2957BBE68C66646ULL, 0x94DF147674C54F04ULL
        },
        {
            0x1F527231ADD20620ULL, 0x4DB80818B66BADC8ULL, 0xBCA7F133C2501810ULL, 0xB59A3E83F1AC981EULL, 
            0xD1D4AC0D0DC0C387ULL, 0x2CBA55432291B5F0ULL, 0x0C1C906EA7E17E3AULL, 0x204E4264B78D73A2ULL, 
            0xA913D2CB1F10D56BULL, 0x0A126F0D5DC8B8C6ULL, 0xCF87018C537C85BEULL, 0xECD64910CE1E4B2BULL, 
            0x7EBBC70395A698E8ULL, 0x4E5B381456AB2916ULL, 0x4F86F4DA825CABF9ULL, 0x7E387641C8FEE642ULL, 
            0x3B6B7E0E4103EC73ULL, 0xE7E37AB70C03F993ULL, 0xED448338F5A4608EULL, 0xB746C2BFB862E9F6ULL, 
            0x25F0A9A6788CA2A4ULL, 0x64F36F760E4A62B6ULL, 0x1C8A46708E4B4D98ULL, 0xB9C09FA416E19D9BULL, 
            0x29A6EB292FDDC799ULL, 0x8EAF0EA196A7C387ULL, 0x1AEC1C60F1C8B29AULL, 0xF5CB88E5EDFCDAD2ULL, 
            0xFCBDAA2122282895ULL, 0xB1D0CFF63067A3CAULL, 0xF7B132FB1A75B8C7ULL, 0x0180FFF34E7BF22FULL
        },
        {
            0xDB9E3D35EFE73643ULL, 0x868F7305F1D1F446ULL, 0x490299579BB8E8DFULL, 0x4E6443D5D6EC1602ULL, 
            0x81816609D939A0A5ULL, 0xDC4C7559C8D6BB11ULL, 0x0B900B9253468B69ULL, 0xA3EF6FEF06E4503CULL, 
            0xD629A9B489894F7FULL, 0xAF4FC8E2EC65C610ULL, 0x0C350EBC902B6B34ULL, 0xE5F1543AAB1BACCBULL, 
            0xF2921DD72BB5FB54ULL, 0x84E658BCD130DF6DULL, 0x63E54898E38E4E5FULL, 0x1FB81E6D5B9B20FCULL, 
            0x224DDEF30E8931AAULL, 0x46CC52A4123C2894ULL, 0xCF8B0B51A3BA903FULL, 0xF9AAE8368606892CULL, 
            0x7F6782B3A3A71D4BULL, 0x0C15AC1730A32086ULL, 0x2A7FC3A7336E98A9ULL, 0x36FDB5BFC2E9E96CULL, 
            0x0BF0BCCE3B7AB756ULL, 0x28DAD403AD0AC24AULL, 0x95548FE0D4E0000DULL, 0xB183CF5EB8391826ULL, 
            0x432E972B4040298BULL, 0x2052C351F7817E03ULL, 0x0D77ACE25A6E2185ULL, 0x42C44D7F242C91DBULL
        }
    },
    {
        {
            0x738F5123F2C311A0ULL, 0xD63AAA9A9B8DDE34ULL, 0x60401994EE86CD7FULL, 0x43AAED2BDD2541B3ULL, 
            0x4C9A7E51813CF7D6ULL, 0x7E050BE3A001C293ULL, 0x65F9EF095AC95A3DULL, 0xE368DA1A480C5369ULL, 
            0x97CFF384D76FEE2CULL, 0xEA2EC3433347719EULL, 0xB8BC793DC3A0EEB0ULL, 0xEC4B8E7E02B0BDEDULL, 
            0x6A194209B2A0E375ULL, 0xB2D353D1A3DC254DULL, 0x6151ED6C27499226ULL, 0x6FC3F8784B9F63F5ULL, 
            0x473360B11EDEF4C6ULL, 0x9141BE0A075DF715ULL, 0x5E7715DC87E214E0ULL, 0xB3E59DA810283DC3ULL, 
            0xCB74A3A374CC6E10ULL, 0xA7AA3E7C7A0D66DAULL, 0xC6E5B1CEDEEB7BD0ULL, 0xD04BCFCBCC475C79ULL, 
            0xB6FAF9AB24F1104BULL, 0x370A7B11B37A3594ULL, 0x99D3F6C526C5D4FEULL, 0xCED27F1C84D47615ULL, 
            0xFE26580BCD5BDCB4ULL, 0x9C3CD0CF15E44E96ULL, 0x0BD3852B946367B9ULL, 0x72F78FB1E646D1ABULL
        },
        {
            0xFD47332415283EA7ULL, 0x104AE5856C9AC9CEULL, 0xF8BD654B3D334CAAULL, 0x2A62100BE447E85CULL, 
            0xB735C5551C3C2C11ULL, 0xE10D8E139857132DULL, 0x7A3C0F27FD3AC42CULL, 0xA0A345298FA8C033ULL, 
            0x2DC03916FB3C0B61ULL, 0xD434DBAD105F59E0ULL, 0x613F4A1217CA91EBULL, 0xD66277FA02F78138ULL, 
            0x50658219B103299BULL, 0x44F3E2D0F86E1BDFULL, 0x07F37F98C19AAE3BULL, 0xCB55CF6944D87D8DULL, 
            0x041B166B844408F4ULL, 0xC39919996C671963ULL, 0x322F680773D8F152ULL, 0xAE48C565EF098550ULL, 
            0x6B235CDFA53D0017ULL, 0xDED22DE90D82A6EFULL, 0xD276798CA153F50EULL, 0x43137450D3D0A829ULL, 
            0xE3B3510CA4E0725FULL, 0x1BFDA66CC666B30CULL, 0x0333E9F99C6C0B3DULL, 0x138534126F8FA362ULL, 
            0xA89F107DD51C334DULL, 0x540A59FDCB085698ULL, 0xAFB31065E364F7D4ULL, 0x37B0F1A88C508E9EULL
        },
        {
            0xEB15F1F5DE394B71ULL, 0x6F28622C30794FFFULL, 0x604D734186DC8B17ULL, 0x9DF69CCB76BA341DULL, 
            0x1306E8437440B57FULL, 0xBB114C8B6B0F3434ULL, 0xAF2B01DAA3854410ULL, 0xF5C9481C5CD59C4FULL, 
            0xACB2BD37C89E76D2ULL, 0x691D367ECCF9E596ULL, 0xB506149C6DBBC064ULL, 0x77AFDE6BD35CB111ULL, 
            0xD30606EF6494CA54ULL, 0x4E5FB1D760439493ULL, 0x65978FCFDF7CA5CBULL, 0xD2628F789798BD3EULL, 
            0x1018A424BD89999DULL, 0x0733276C0E9A3EF8ULL, 0xF671616F96B45976ULL, 0x7EB81C5B99A31531ULL, 
            0xB61EEE3E5B97ACC9ULL, 0x0D8EF938FDB5DD26ULL, 0xAA03A03E45BCDABFULL, 0x4B2158546C984681ULL, 
            0x7C98EBE60EF49CF1ULL, 0x7FE64CDBFFB95A7EULL, 0x8EDEA699AA823AFCULL, 0x3C070E785F4D0344ULL, 
            0xCB26ADF3E8BD878BULL, 0x2F51C31F4F4F2A5AULL, 0xE7676181D7C6782BULL, 0xFD0A72168AD3D48AULL
        },
        {
            0x75765CFDB29187B2ULL, 0xE5BE51A0F0BB84A1ULL, 0x08DCA15CBE4F3D6FULL, 0x20878E3CD8864240ULL, 
            0x7C48A679A0D83414ULL, 0x047A63A9D0DFEDA6ULL, 0xC54ABE1E02178EF7ULL, 0x45E62C8B8A6725C7ULL, 
            0xF23370CEC7BB7A8FULL, 0x8F910CFD149D7258ULL, 0xF472E308CDC39BF4ULL, 0x66ED500A8ABC10DEULL, 
            0xC45417086B888B75ULL, 0xCEAF85E075636183ULL, 0x229B7C8D807BE23BULL, 0x31399B4BFBC0F07CULL, 
            0x0A58DDC2B4A5AAF5ULL, 0x70C4E73ED9DBBB0DULL, 0x0F56069DD3B7005CULL, 0xC55C5F4482992177ULL, 
            0xFC4786CEAE65DFAAULL, 0x3ABEF354663518E4ULL, 0x905B5C0252B6F842ULL, 0x5FE46393FF80B704ULL, 
            0x0BBE82C1E7685637ULL, 0x6C67807DCDC8E9D7ULL, 0x41333381CCD5C86DULL, 0xF30B75322B6E1712ULL, 
            0x4BFEEEB57348D6F5ULL, 0x0A8A39667DA7D089ULL, 0x8E7A926D77376184ULL, 0xA6C1E38E3F9C96A0ULL
        },
        {
            0xE7CBCC69410FA8FBULL, 0x89293CB966024FBEULL, 0x21314213BA2E7E97ULL, 0xB0580CD51B996BB7ULL, 
            0xB4DAED05DEA05A24ULL, 0xAE02EC98E25906CFULL, 0x9EAC32A2FDBB86E2ULL, 0x9C0EA90CE1EE6927ULL, 
            0x30F3A9EAB05ED172ULL, 0x0A1632806B177824ULL, 0xFB31698302E25DF5ULL, 0x65F7BEA690504A98ULL, 
            0x64CE2601549376F5ULL, 0xEFD3BB9595A304C0ULL, 0x7300680A3EF59E5AULL, 0x9BCF347FCAC4D092ULL, 
            0xBFCE4ED6D08C191AULL, 0xFC380D99125E6353ULL, 0x6A3F77D4E8779B4CULL, 0xD5D9296C1CAB2FA5ULL, 
            0xC2D54678822401CFULL, 0xE8A3A9FC4364A375ULL, 0x802274C216B38250ULL, 0xF4C634CE351E50BDULL, 
            0x1839EC666C595934ULL, 0xD86622B404567EBFULL, 0x2BC00AD596F9EC64ULL, 0xD7326364B6D07018ULL, 
            0xCBC6437850746C05ULL, 0x8E1828A6F0C3E898ULL, 0x872DB4FB8B860BFEULL, 0xD3A2E0F5AE40BBC8ULL
        },
        {
            0x40261978F5C27CDCULL, 0x20F51CDD2F9FB022ULL, 0x0D958B5A9B1C99D4ULL, 0x4E42AF2B8A9DBDCBULL, 
            0x9110C34789E3AA60ULL, 0x9A17FB3D1C7B7247ULL, 0x2CA740A0F7006A29ULL, 0x6FF905B27671007AULL, 
            0x755053B29D8E0282ULL, 0x4B78DDAAD281D78BULL, 0xABA972905451B7B9ULL, 0x6DB7847C78A02E25ULL, 
            0x21EAE0EE82AB5983ULL, 0xC00EB43F7EB4223EULL, 0xEBF0B523E3CB0742ULL, 0x28658A72C95E7F06ULL, 
            0x292240B1492BE7F2ULL, 0x0FD8F04E5FB19EE3ULL, 0x0315029FB2C6A0F5ULL, 0xACE792B2EB07B28EULL, 
            0x9A208C8556AAD7B2ULL, 0x3766D29C095338EDULL, 0xD43D0C95862D6B2FULL, 0x455CD11E17135CE9ULL, 
            0x6E2945CFE238E09CULL, 0x33538F20D51F3756ULL, 0x6796565CCB19C6A6ULL, 0x9C2B8C2F1328C70DULL, 
            0xD56589C2BE2DABBDULL, 0xBE19A4C5BBE73EF5ULL, 0x684CF7D13867C5AEULL, 0x712C84006D7F3E9CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseBConstants = {
    0xA0687D978CFEFB87ULL,
    0x985F37C1EAAD7C2FULL,
    0x827F8701CE132637ULL,
    0xA0687D978CFEFB87ULL,
    0x985F37C1EAAD7C2FULL,
    0x827F8701CE132637ULL,
    0x40449418A4BADA71ULL,
    0x6CD2EA788C81A207ULL,
    0x2F,
    0x62,
    0xDB,
    0x7F,
    0x9E,
    0xD0,
    0xB1,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseCSalts = {
    {
        {
            0x52366DD8838FBA57ULL, 0xE6B9CC86604F3408ULL, 0x0DC723212EB065DEULL, 0x71B83F7C7B367C9AULL, 
            0xB553C47C60CF7A44ULL, 0x8DF55D11D6E11487ULL, 0x063F363F31AF22BEULL, 0xB27C5DD171F1A92AULL, 
            0x6703753671CED04FULL, 0x96C1EDDA06CEA4F3ULL, 0x1F0A9E490FD59EF4ULL, 0xF8E9FDDE7A61754FULL, 
            0x833B7537509A241AULL, 0xF91076D76A5F9E0DULL, 0x89D815014A6076C0ULL, 0x86497BF8D035272FULL, 
            0xB79E5D4581C5697DULL, 0x925CBA06BCD81B46ULL, 0xCA30153E50C21E46ULL, 0xD29B952EA150A51FULL, 
            0x4F915C89FB72A471ULL, 0x479EE0A80E085200ULL, 0xBE025EECF17A49A5ULL, 0x6B6864119FDF523AULL, 
            0x2C4554258BC304C0ULL, 0xAFDB1E4454B05A02ULL, 0x54DFA6592DEF3228ULL, 0xA1A2480A63A40F14ULL, 
            0xD28976287FD74E92ULL, 0x140F32A5DAA9317EULL, 0x9EE06F2D0360B0F0ULL, 0x4335A3FDC7139B26ULL
        },
        {
            0xAE7B3489B4701D1AULL, 0xAE2B7FC9897311E1ULL, 0xC4B8E5AB34FBBCCFULL, 0xE65E687F7E92DCA8ULL, 
            0x1E11AD1DAAB64EBFULL, 0x4E16F49D0E58DA50ULL, 0x45D64292F9BA617EULL, 0xD62D2E01F7D1CA02ULL, 
            0xB0865A1AC909B1C2ULL, 0xB2BDA5EF3ABE1899ULL, 0x1410E98DCCC4428CULL, 0xD3257EA30917CCA8ULL, 
            0x67BAA5BCF2115618ULL, 0xC3F20F751AA62C4AULL, 0x26FA31D0CC1140C3ULL, 0x4B0AC9972557ABFCULL, 
            0xA85B83BAD1A12EF9ULL, 0x1A895CB4467294E0ULL, 0x9A92571051A03396ULL, 0xE47D3378E8F913EFULL, 
            0x9BF2FBDFDB9833C8ULL, 0xD7448706A586D072ULL, 0x76FE046DC6EF34A8ULL, 0xA6A2B4E2EE42BE2CULL, 
            0xCEBA07C1E0C5238BULL, 0x00A385E9D92D1FA5ULL, 0xC82D9417A006152CULL, 0xFD3F3238ECC48B79ULL, 
            0x15A59D7A4F889B63ULL, 0x42442A49914657A7ULL, 0x1C15617B2C233BF6ULL, 0x898E71D299D23F82ULL
        },
        {
            0xE9DE4C94CC755B0DULL, 0xBD148C3A46DC361BULL, 0x1443EC46AEEC39D2ULL, 0xB5F193349FDA4DABULL, 
            0x458ADEAE7F25DC73ULL, 0xCBE7E211B3A595E2ULL, 0x6A0A360FB60015E8ULL, 0x845193C1B5534BD4ULL, 
            0x8665077320809D47ULL, 0xC638EF8F84C879B5ULL, 0x7C1B49D67ACBEEB7ULL, 0x6D8C6ED47279F06BULL, 
            0xCF25A84F4616D279ULL, 0x2BB705CCC9F7B61AULL, 0x0FB5A38F87625D55ULL, 0xC53AF311F752115FULL, 
            0x41C23F8CB9ACB5C4ULL, 0xAF6697E7A0B7D0C4ULL, 0xF271238368A047F1ULL, 0x863F6454CAAC605DULL, 
            0x2CD7BC37F2CA5CEEULL, 0xC5E66E87550E3F11ULL, 0x23F24C9EA580B0D7ULL, 0xF8AE2180ABAD06DFULL, 
            0xEA99D9555C217648ULL, 0x0DF80283DE6DA634ULL, 0xFED51C725FCA2AAFULL, 0x69BCCA099A5F3FD1ULL, 
            0xECDEC77F58245141ULL, 0x2C2F987DDBBCFE00ULL, 0xEA909D5B37E1730AULL, 0x7297668E14838E64ULL
        },
        {
            0x0CFF2B7B352AF935ULL, 0xFE56C8107AF97AA4ULL, 0xA212714B5965ABEAULL, 0xF0382A1B561C9709ULL, 
            0x1F9D7313062762E0ULL, 0x144572DF4CAC78E3ULL, 0x613A41959545FFE8ULL, 0x271DC24036677034ULL, 
            0xC2472D56D24E7027ULL, 0x533B1945B441B6E2ULL, 0x157A5EB769A7DA71ULL, 0xE742F83E527C9919ULL, 
            0x0F4DE510A9C30729ULL, 0x3B82F5050E8A4538ULL, 0x73D26EF341B77650ULL, 0x987EBB9504E44ECAULL, 
            0x67C30BCCBBEE842EULL, 0x7F360C973C7D423CULL, 0x21D4CC8B8D5930FCULL, 0x5835F16D0BD01DA3ULL, 
            0x1597CECD9F221BB7ULL, 0x7FB0EDCA6CDE6F9BULL, 0x438CE6B36DF65FB0ULL, 0x81E367E922D87ABEULL, 
            0x44637DB3324A1CA4ULL, 0x80E95E956E07A2EAULL, 0xAC5FE6BD524188EAULL, 0x790865FA9457871BULL, 
            0x8E2B9FCCE4F6ADF7ULL, 0x2572007427A21624ULL, 0x2C7D62BC41B37AE8ULL, 0x189F09146983CBA0ULL
        },
        {
            0x42250B6C81076E8FULL, 0xC125C6E33D3F3782ULL, 0x18F2D97B1BC4DEBFULL, 0x685374AF50AFA4ECULL, 
            0x885698329D82E6FCULL, 0xD0689DA02422486EULL, 0xD1C1B6FA6CFDEC3FULL, 0xE877A9A921D4B541ULL, 
            0xED908A503D11E81DULL, 0x0983B28375F108DAULL, 0xD427FADB8F7242AAULL, 0xB9D1F2069E3A2061ULL, 
            0xB3B9803FEC2DEE08ULL, 0xA0A897A1CFE3EBC8ULL, 0x40D05838C0AA9F2FULL, 0xFB91DD856CDC2D24ULL, 
            0xABA250972C3B30FBULL, 0xB32FC714341F4B75ULL, 0x1A799A605E20126AULL, 0xC31FA9C10C05B098ULL, 
            0xF87B9FE8F58FAE20ULL, 0x59A443362C4F3B76ULL, 0x07954B56CDC6A15AULL, 0xA4E1588AFAAEC088ULL, 
            0x98AFF0B05A40EF66ULL, 0xFBDFED3CB0DED9ACULL, 0xB93EB3B216A2B387ULL, 0x27C039DD6CF26E05ULL, 
            0x77B791EA58491A7AULL, 0xA7F2E16921EB7961ULL, 0x7A44D744F319AB36ULL, 0x711A061CD67E8F73ULL
        },
        {
            0x968D2552737E1E6AULL, 0x56B998688BD91A9DULL, 0x890E2BFFD799CCA0ULL, 0x5E23AC42FE6BA5D8ULL, 
            0xCEEF9A85FD7ADAB0ULL, 0x2A6E6209A7F42A31ULL, 0x7E2A5C4B2D11DDA4ULL, 0x3325D1E643491CB8ULL, 
            0x30871526AB6CD396ULL, 0x2B7EA0759B31928FULL, 0x8BC26A1D8E3484A0ULL, 0xA84978DBDA15BA4DULL, 
            0x97437A53AA42B292ULL, 0x03B71D41982EC564ULL, 0xC06577172E6FD44EULL, 0x9ECEAF803E5C4784ULL, 
            0xF9159DD3BF89B982ULL, 0x15C15FA34E91190EULL, 0x936CCC9B1AAAE7B7ULL, 0x267929E221B143FAULL, 
            0x780BA2324DE60871ULL, 0x4E11592ED42CB242ULL, 0xBF8B97C2C27774C2ULL, 0xFDEBAEF6579DEA2CULL, 
            0xE4FA737486AF88A2ULL, 0x5A01CD4CFA1026E2ULL, 0x4CAE2338885B0835ULL, 0x26C8C5A78ECD3A35ULL, 
            0x50C28CFE6BD9C19AULL, 0xC5C6BBAB9B5379DBULL, 0xD057C1B09DEE241CULL, 0x1E1703544B536EAFULL
        }
    },
    {
        {
            0x58CEA60A351A6678ULL, 0xE9556B54602D4E0AULL, 0x9B2D440365A5958CULL, 0x43F4EED8C4E7602BULL, 
            0x62FA8707C08C9A76ULL, 0xE27435FAB55D31FEULL, 0x7A31F406592B6436ULL, 0x1F13C0167A6F58F8ULL, 
            0x0B48BE93F5522D3DULL, 0x32A1C73FD97A3DEEULL, 0xA99B472D0A95A171ULL, 0x381CC859226B7E47ULL, 
            0x3C00F3A75442198DULL, 0xB852447EA2CAA342ULL, 0x4DF7E8D2A368CB6AULL, 0xCA1422BE281ECBF1ULL, 
            0xA02AF60907A00B35ULL, 0x31F47812F73275A3ULL, 0x8CE12C92F0AEE52BULL, 0x9DAC9749A857CC06ULL, 
            0x932EE8C67494DB61ULL, 0xB848B60DA22AEEE7ULL, 0xFB6BE8FEFE5C3F4CULL, 0x7A74B4C7643B877EULL, 
            0x97FB57789B1FBA8AULL, 0x42BDBF40E5096357ULL, 0x8A23C91E9123FBF2ULL, 0x0044044D7DE002B0ULL, 
            0x472D9AA2C5286C5BULL, 0x8A4D76A1004169E4ULL, 0xD98E9E1B4C0FC627ULL, 0x1A6DBE747A8C36E1ULL
        },
        {
            0xC28127702AC06703ULL, 0xDC5E534C925B5987ULL, 0x31E4B710E46AEEEEULL, 0x23F700256100253BULL, 
            0xFB87C0E479D7905BULL, 0x727C312C31A6E576ULL, 0x1A66EC5490BD5776ULL, 0x08C956C2A16B9BBBULL, 
            0x0308B6F2293F4172ULL, 0x3D4FA825D8C9A185ULL, 0x2630DE0277F61B13ULL, 0x7FC3786DECF96E25ULL, 
            0x0BCCDF41A44DB2EEULL, 0xFF83B11BA9BE0FCAULL, 0x0625C635B220DF0CULL, 0x7CF45A3F3DB94A2FULL, 
            0x18D48572C4A4598CULL, 0x672283149D029F92ULL, 0xB06D75505413133BULL, 0x88BA03D74FFD787BULL, 
            0xD6646F4A3D6661D5ULL, 0x53FD1B4C4F2EDAE7ULL, 0xDB869D204E0DBBBEULL, 0x528FFCC4F684E4E1ULL, 
            0x87EA9617CADB3ABBULL, 0x8C1380D881023812ULL, 0x597F603C62BB0D50ULL, 0xB92A21847DE1894AULL, 
            0x417A08105AE50832ULL, 0x54E7F9EDFDB01775ULL, 0x2A7AA70C97D46C12ULL, 0x6D1CECA4207B00B6ULL
        },
        {
            0xEE952C2AB23A0FE4ULL, 0x9D899EC36BD706CBULL, 0xC68A8F8CB57F3869ULL, 0x0689ABCAF986DAF6ULL, 
            0x85E89CFC024092DDULL, 0x08222A670A79D1CFULL, 0x820D5872CD5625F5ULL, 0x15A44413C0F4C281ULL, 
            0xFBED89E7B1603846ULL, 0x868BFA84BBD2A98AULL, 0x50A53A213FC32347ULL, 0x41566A8079491754ULL, 
            0x64006A06892D6C4CULL, 0x4C25B69BD1D53A2EULL, 0x29690DCA927515D7ULL, 0x2368CDB74AF93EDFULL, 
            0x922EFF59A457A893ULL, 0x6C797A2F3F67DF2DULL, 0x9AF2B93EA48AF08DULL, 0x83F3E7A2A2EEBC03ULL, 
            0x7D01E4FB82C9A16BULL, 0xB5F1F700A72FF4ACULL, 0x0A8FB4F25F1C69D0ULL, 0x52223E559233AC03ULL, 
            0x0F4735E35DED0CBEULL, 0x0174245409253086ULL, 0xF90D01375CE6DBCCULL, 0x872500CC9492A3DAULL, 
            0x365602FFBA2CABDFULL, 0x4262469C91A89292ULL, 0xC6A8261C7AE4AFE1ULL, 0x02D48E0376AC9B82ULL
        },
        {
            0x144D596D172DAF68ULL, 0xC3DCE8CE653F0C75ULL, 0x9358D8AA6B752FE0ULL, 0xBA3978A613EA0334ULL, 
            0xFA40C7FF5BC5FCD6ULL, 0x38ABFCA0B7BA9E59ULL, 0x1EBC6FE6535EB486ULL, 0x2EF2A1C1C80B3EDDULL, 
            0x2ED1759E8C812626ULL, 0x4338212A68092481ULL, 0x10EFD1F579A39468ULL, 0x5B37C06B4B243639ULL, 
            0x9EF152C4BAA646CEULL, 0x1D5021DD372E7810ULL, 0x8CB6F726837C649BULL, 0xDA5DFC8F78AE2DD9ULL, 
            0x3CF190731B52B205ULL, 0x4FA1387E23659E41ULL, 0x14380A6AFBB5145AULL, 0x88514CEBCDFACBF3ULL, 
            0x49B546D7F1956E2DULL, 0x3DBB04E642752B17ULL, 0x6E4F6211305EBA17ULL, 0xEDD3FC12D507A775ULL, 
            0xB0B85E8D426BC4DFULL, 0x1AAEED9C04C28F0BULL, 0x4D69DDACFF8356CCULL, 0x1725575F31C91B0BULL, 
            0x7C4961BF3716A2A0ULL, 0x12F3FE355B2A126EULL, 0xDF63BFE97E7EF618ULL, 0xF09FB5988B410D6FULL
        },
        {
            0x57124C4625CB4BACULL, 0x4A2B2765B5BE7C39ULL, 0x36A7DE786D28B5F3ULL, 0x4A7E30C2BBF8B330ULL, 
            0xB6EC281B30529FB2ULL, 0x26825F8D92F38CFFULL, 0xA4A10F5064CA690CULL, 0x423DDED5755BF8F1ULL, 
            0xF796FD73EC8D60DEULL, 0xD91F7F0BA83DC09BULL, 0x0EEE1BB13F69C59DULL, 0x35EB2314C96F84CCULL, 
            0xDF56CFFAE6A0D346ULL, 0xB4918EEB02CE3F92ULL, 0xD7FA798C84740C04ULL, 0x6E4731EC8C83AD48ULL, 
            0x583A188370FB12B5ULL, 0x17B097AF4793D283ULL, 0xD2C68339566655ECULL, 0x03CFA9A4045C1D37ULL, 
            0x055E363390CEA4ADULL, 0x46850F59DD56C5A9ULL, 0x0F0D62FA08DB00D8ULL, 0x680E4E1939AC1F0EULL, 
            0x4473B32F054A2395ULL, 0x14F86180741D9400ULL, 0x38A54735BF31B331ULL, 0x6B2CD3A4BD4631D8ULL, 
            0xF205D60020DCD513ULL, 0x8F6BBD5EAEC9AB65ULL, 0xF1B1B142143EBF50ULL, 0xD7DE333AC3A52CBDULL
        },
        {
            0x82285341F3EC55D7ULL, 0xF4A80E3FAC35D8CCULL, 0x460E1942A5858443ULL, 0x498C0269D4EBCBB8ULL, 
            0x0A0735CC843E5B96ULL, 0xE5DBA58D87A1A63FULL, 0xA3C6229DA0BE1FA5ULL, 0x3E56255EBD6B369DULL, 
            0x76EA86E25B376760ULL, 0x4CEE5E46E514662DULL, 0xFE1B624E28F6822CULL, 0x1621200D4975BF09ULL, 
            0xDE1297DFEA8EBFE0ULL, 0x239E7E2F38D63E4FULL, 0x4196271CD89D048EULL, 0xAAE377A5DDBF782AULL, 
            0xC70E708A3033A628ULL, 0xA5C9A09EA8CAED15ULL, 0xE6FC9533E5B83DD9ULL, 0x108364A89A517C8CULL, 
            0xAB10A3E28319377CULL, 0xF876CCCD06F7B283ULL, 0xAE236F357B63CBE7ULL, 0xB080C418EFB24D70ULL, 
            0xF92110D70E9D5BD7ULL, 0xAB2BA988660608B1ULL, 0x817BBEC713E6435EULL, 0x14B8F2FEBE0BDAA7ULL, 
            0x5FCCEA034601CE9BULL, 0x85EED234E3A8BA10ULL, 0xA2CEBD4D97097F85ULL, 0xB626C79A137A95CFULL
        }
    },
    {
        {
            0x689D9E5065682DDDULL, 0xBC7086DF651673C2ULL, 0xA03A49396D3C51B0ULL, 0xC2D0E670B2B7B520ULL, 
            0x00CE582416DE39D7ULL, 0x646FFC875EB3A6FEULL, 0xB726B6371DC64D05ULL, 0x2DCB4BD77B4B13AFULL, 
            0x4824327369878DBBULL, 0xD07F7A945F1C2C65ULL, 0x96BD96BF0260C0A4ULL, 0x17CF4D2C11B24570ULL, 
            0x0054F9D02FEBD638ULL, 0x4F3C04D2C9FB110EULL, 0x3B526DEA6552C6DDULL, 0xCE03F367E85FF06CULL, 
            0xFA0E68920750B413ULL, 0xC318674288C0D5F8ULL, 0x84240EE88E75D4CCULL, 0xA9990A045EA37E75ULL, 
            0xC1A57ADDB71F0F92ULL, 0xDD4DE24EF1F86237ULL, 0xE18D66EC2DFD6EBFULL, 0x0FA1D4D5ECDB2A01ULL, 
            0xA8F765A3D8AAA9E5ULL, 0x7462165FBD9F21A3ULL, 0x12E07233424D7EB9ULL, 0x143C2676CCD8E960ULL, 
            0x2204167AA95B6CD8ULL, 0x26FECF0E49C01436ULL, 0x450CA26C58D1033DULL, 0x6077962238061DE0ULL
        },
        {
            0x2C6225A62BFECBF2ULL, 0xA482A2EC00FF67B3ULL, 0xE9C0D44571043F88ULL, 0x4AF894739C1FF180ULL, 
            0xC4EC65BB27CD74BEULL, 0x498648C355BFEB49ULL, 0xF4A8792D28B2D14FULL, 0xD92A74B636EFE32CULL, 
            0x79F9A1EF9DABDE91ULL, 0x73751C05396BF966ULL, 0x49CADC7590B32E07ULL, 0x488D926FAB8DC5EFULL, 
            0x088D7EA44F3D68BCULL, 0x7A3F5F7C7ECC3143ULL, 0xBF4ED6B3C587AE3DULL, 0x33D371B3BC5D3643ULL, 
            0x733576CD49F048B0ULL, 0x4A03E7AA95CF75CBULL, 0x426264F9CD0336C2ULL, 0x2C0ADA9793BE4952ULL, 
            0x40251AF1D9B2035EULL, 0x280C37D38462176AULL, 0x13109E438E5786C9ULL, 0x7572792172043899ULL, 
            0x7AFE6A384150212BULL, 0xDEB3319AF18865F1ULL, 0xFEA7188126C9DE01ULL, 0xB396B37808DE2AF6ULL, 
            0xED5F9CF3DA73F95FULL, 0x43047F321F5B8521ULL, 0x5EBBA75C3D4FF4BCULL, 0xD1FBFB0B07DA51D4ULL
        },
        {
            0x0AFAAE99524E0057ULL, 0xB8B76BE4999A44C5ULL, 0x959F2BA8EC8D6C7CULL, 0x1F56B5C99A300651ULL, 
            0x975749F83E55A185ULL, 0x5E2B227215AC434FULL, 0x8975863E0813D8ADULL, 0x5C33E3C85FA973A5ULL, 
            0x1F6A061FC7689885ULL, 0xE48B74F8B08D47B6ULL, 0x105BDD5A6F2D051FULL, 0xEBCEEEEEEF040029ULL, 
            0x20893C5E87619833ULL, 0x7435B39064E3B0CFULL, 0xEC52A758BADBA322ULL, 0x8D9A7D0D6EA15651ULL, 
            0x8F7E1937CE7CBDFBULL, 0x97C9CE288AD74B77ULL, 0xC8862C1C08265534ULL, 0x07E53DCE397166A0ULL, 
            0xAD7F08485B50BABBULL, 0xD313CFAF058C96BEULL, 0xB37A76D0E6DEC715ULL, 0x3B1B1BE6F31A5C10ULL, 
            0x84E7A2D0B8F451D3ULL, 0x224D1C562F74E25DULL, 0x6231171D5146E9C1ULL, 0xD8545339DE7F5034ULL, 
            0x26038E00A58DD1E8ULL, 0x9405CB62FB386AF7ULL, 0xF3577708990B93DBULL, 0xC43F605B1A53E528ULL
        },
        {
            0x30D7C2DD49E3EC2DULL, 0x16E74C5E3A485355ULL, 0x0D83B183C6CA8EAFULL, 0xC66DEE665BD146FCULL, 
            0x50487E9EB7BF2525ULL, 0x5CBFDB264B7CFC23ULL, 0x77634FC05253575DULL, 0x25440D7C5F0EA5E4ULL, 
            0x61B07B9C4DA56389ULL, 0xA5FC9BCA06A33D77ULL, 0xE36F2F7670E81B84ULL, 0xE4BA42A3EAF37CAAULL, 
            0x81D65338EF76BA72ULL, 0x783DB6E353964D8DULL, 0xDF9EBE78BE234167ULL, 0x8A98AD443C89CF31ULL, 
            0x7034EA286B7C6A81ULL, 0x08F6156F59B986C0ULL, 0x1AB821C64D1CC1BAULL, 0xF6C5571118038F9FULL, 
            0xC602962BB5F7B881ULL, 0xF4929363F7745C58ULL, 0xC84870468BFB654CULL, 0x00BFA405F42CA923ULL, 
            0x0729EA06EEE4BBC6ULL, 0xCCBA63F7D2019E76ULL, 0xA9B1062ED1DF4C89ULL, 0x9D19AC19B3574615ULL, 
            0x01D9265ED32994D8ULL, 0x5784419C10B4FDB9ULL, 0xC23C0D3539D714CAULL, 0x81756079E4D354E4ULL
        },
        {
            0xF1249DB3BC20AC9DULL, 0x973530C0CEEEB2E8ULL, 0x9D59A0B5EB1C207BULL, 0x113A540DF1EFD5B6ULL, 
            0x014B9540024C0793ULL, 0x1F99A5F4381D04DDULL, 0x9CD07E22E6F452E3ULL, 0x5B58AEA50F9EC0C8ULL, 
            0xEBB2AD962FBD380DULL, 0xB9B752A5C93CC7BFULL, 0xEB03E45C705CFD3DULL, 0x36C9DB2BE46544ECULL, 
            0x1BD1D4592CD4451BULL, 0x40B0ADBB974A0E86ULL, 0x62E817AEA9E4E80DULL, 0xCFCDE7833E7B6C65ULL, 
            0xE85374AA4007CECCULL, 0x97B3E88C652CD6F0ULL, 0x83BC3AD4C4B6C9CBULL, 0x77BA428EDC850986ULL, 
            0x446F0C15F60820E0ULL, 0x005FA13505C116E7ULL, 0xC99BCA08546C7344ULL, 0x666DAE3F435C674DULL, 
            0x898FEBA8C26C68D0ULL, 0x950F589E2ECAFE95ULL, 0xD66627954440E9DEULL, 0xA26E2E63678343AEULL, 
            0x86555A6C3708BCC0ULL, 0xE55589ACFC952603ULL, 0x3E8A019E3F9AC903ULL, 0x4AFCCCAFDE2B9A0FULL
        },
        {
            0xCFF9533E10842DB5ULL, 0x703858E26D76AB05ULL, 0xE76E79646085AC88ULL, 0xB3E856FF56D5518EULL, 
            0xC37479B156C9B75CULL, 0xCD5080491E24032AULL, 0x875A91BB8D1556C8ULL, 0xF44795B34B87F51BULL, 
            0xC60F4A8CAF59F366ULL, 0xF56A18D4448D84C0ULL, 0xDD87D81B7A11C72AULL, 0x8E9A8945234DCEBDULL, 
            0xB6DA07729D2C8A0BULL, 0x48CC20519BDAEDFCULL, 0x6D6A12C87B745FFCULL, 0x252D8788084C0252ULL, 
            0x55AB98E1452805A3ULL, 0xDE62475237C96A2BULL, 0x1FEB0A67D02D850CULL, 0x99E19CE3E5D21F64ULL, 
            0xB143FA102ACE48F5ULL, 0x75F9920C2727DDBDULL, 0x103986B5E2E7841BULL, 0x375D7ABEE037AE99ULL, 
            0x9D3AC65B6A76FFA7ULL, 0x4F387619A915E713ULL, 0x7D71B7B08A208A21ULL, 0xF22218F7CB4A5852ULL, 
            0xABED22BD3BA52765ULL, 0x3EDBDDE52EF477E0ULL, 0x67A2241A7063720CULL, 0x6E57CB11DAFB3F91ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseCConstants = {
    0x9CA1000E8ABE1E6AULL,
    0x372FC3DFCA697592ULL,
    0x7348BB81B3A04196ULL,
    0x9CA1000E8ABE1E6AULL,
    0x372FC3DFCA697592ULL,
    0x7348BB81B3A04196ULL,
    0x15D38E98EDE9282DULL,
    0x1652C5DF6D7F0453ULL,
    0x6F,
    0x4F,
    0x5E,
    0x71,
    0xBC,
    0x03,
    0x33,
    0x3F
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseDSalts = {
    {
        {
            0xEB1ED702EE96BB5EULL, 0x5E6D435570CA4593ULL, 0xDFB12EE3F99E0FEDULL, 0x72E1C72DB080A0BFULL, 
            0x1FAE225664C551E5ULL, 0xF662C44826D9FFDBULL, 0xB53DCA880D914202ULL, 0xE275BAAC88E0287CULL, 
            0xC552CEE863C2350DULL, 0xFA952CA998547BCAULL, 0x44A1CDDFCD0AA8A7ULL, 0xD50BFBA616679A49ULL, 
            0x4FF95746253B9886ULL, 0xA2545989064AA363ULL, 0x8F440D513C87117FULL, 0x1B5D6411C79E7BC6ULL, 
            0x7E9D9408469544BFULL, 0xDF3F37363D32F5CDULL, 0x5E45C88C4FF04D78ULL, 0x50230C1C5F38A753ULL, 
            0x1E2280D02031D37EULL, 0x1235396DC1A8BEA1ULL, 0xC4D2CB16D1B59275ULL, 0x4EDCE451DF8536B8ULL, 
            0x2B38DC1A5CC71D70ULL, 0x7F5CB71181868AB6ULL, 0x74A6330082686128ULL, 0x7D0561953059C962ULL, 
            0xC85408BE34938710ULL, 0x92920B125E4A5FF1ULL, 0xCBE5663C60EEE4F4ULL, 0xC0D2DBC2CDC664F7ULL
        },
        {
            0x7476B23162BF2CAEULL, 0x5B522452689ED1EFULL, 0xCA021BBFF1F9C295ULL, 0x927C6E9BB507BF73ULL, 
            0x95CA37615BC07ACFULL, 0x58C217689ADB6457ULL, 0xDD50C92C882CD384ULL, 0x61F9D3052EC81030ULL, 
            0x568FE20A2E84AB09ULL, 0x49D83265B5108AD2ULL, 0xD13B1A3F44C1A875ULL, 0xECAF524BD4E96804ULL, 
            0x8DBBCD3F5B21EE5FULL, 0xFCC22C847C5FC092ULL, 0x5ABB00211D3B3604ULL, 0x2522269E6971CD87ULL, 
            0x5900374980558518ULL, 0x4DCC7D3ED2D8E56FULL, 0x4B1CC02E1DA673FAULL, 0x2550C69CB13078F2ULL, 
            0x8D2B2C8F54C63181ULL, 0xCF89059BD0CB434FULL, 0x608DE26F82E28122ULL, 0x80F1998EE9A03B64ULL, 
            0xD17F5A82BCEB6CE5ULL, 0x554B8B417AA2742EULL, 0x2064373C459DA5D1ULL, 0x3255B90AD44BF177ULL, 
            0x4C286EF3DCB9A0F5ULL, 0x04666D5E18164BF3ULL, 0x08DB9CBC88F9C2F9ULL, 0xA35873FEEC4053D3ULL
        },
        {
            0xCA60BBD58E9431F9ULL, 0x0E719D5542AC39AEULL, 0xC286AC6280E619F8ULL, 0x0D7030847D36D28CULL, 
            0xBBFA2E42C8A1C197ULL, 0xD7633BB9CD5ACAF2ULL, 0x2AEB1B4D47A5C2C6ULL, 0x4E60157FF9FA1637ULL, 
            0xA1EB54868A3F1913ULL, 0x2CA1E360B4D3BEA9ULL, 0x3C8EA303BEF07564ULL, 0xADF411800EF81490ULL, 
            0x5CC3224274235AD0ULL, 0x5A7B79F756BA8F14ULL, 0xE54D8DA4763E23F4ULL, 0x84E37D162271EEE9ULL, 
            0x646A5F2F3827ABBFULL, 0xBFD4F36FE23DC5ABULL, 0x92F15D91F0B6E963ULL, 0x759878ADE14E3D12ULL, 
            0xD399E0E31C25FC81ULL, 0x957177C078B7C92AULL, 0x6F396994B0C7307FULL, 0x94CBD966CCB94F0DULL, 
            0xC22710DFE8476AA7ULL, 0xAF453D5AD7681C03ULL, 0xA99309645B273CD6ULL, 0x13B069B16114D6ECULL, 
            0x08E0DFCEF8A3CB59ULL, 0xF674EAD77EB6DE46ULL, 0x193F88F8B5B18B63ULL, 0x4B95DFA9E0D40137ULL
        },
        {
            0x7429CE7DB9D142CBULL, 0x10C8BFA73349F28DULL, 0x26B816A977200095ULL, 0x28828267F36C3A9DULL, 
            0x96CFD379CB3EA487ULL, 0x157DD4C98EAE27A5ULL, 0x1DCC298B76FAB9E3ULL, 0x79F065BA2A6A049AULL, 
            0xFE57C971BFF1426AULL, 0x422F395345D4C946ULL, 0x94E2A4630FB5013BULL, 0x31CF5BD93CDF5F76ULL, 
            0x23873E76CB4C515EULL, 0x78E25E330F8992DBULL, 0x19814E38CEEF4A58ULL, 0xD08634152BA9C246ULL, 
            0x0DDCD42F975107F3ULL, 0xDFF8D8D2E0EB9E84ULL, 0xA24681C8F1493432ULL, 0xC626A2F8A6AACF16ULL, 
            0x6992D4CC7BF2D078ULL, 0x769A3153BF5BF284ULL, 0x1A1B32BACA5FD902ULL, 0xC7CB4571426E779FULL, 
            0x1474C1EF9A6DB117ULL, 0x9FD01F491BD4EF49ULL, 0x096F0CA8E208AC53ULL, 0xB2A6DD4F676921A3ULL, 
            0x7A17BCF949C07945ULL, 0xFC20A68FFA0AA687ULL, 0x5B710A414BC99D7DULL, 0x1C8A23383002B642ULL
        },
        {
            0x078DC515693528C4ULL, 0x07D4676C4B909987ULL, 0x3DACAC1CD1828E54ULL, 0xF037DFFC1E8E60A0ULL, 
            0x868103C42C9535AAULL, 0xDE14F8DE228906DEULL, 0x667037F016DBDE8EULL, 0x78F21392F2A11160ULL, 
            0x228229BA2C74E24FULL, 0x1058D9774D27017DULL, 0xD418E28CFBDAAB11ULL, 0x47C7B68639E61431ULL, 
            0x155F889BB59F4B48ULL, 0x5AFDD2CB059F7A15ULL, 0x9A877FA70F3F9ED5ULL, 0x65E41DB5062419E6ULL, 
            0x6AD491ADDA7694F9ULL, 0xA4CCE45967BA7A2CULL, 0x09384CB2887037F2ULL, 0x105965AB777B1318ULL, 
            0x2C6EFA15840C6C1CULL, 0x1D354307824087DAULL, 0xC2D425842324F002ULL, 0xD28BBD595293CEB0ULL, 
            0xC6D595B55178548EULL, 0xCF140591F4F27E89ULL, 0xF824F9F3E5080406ULL, 0x0BDC981D9DA926B8ULL, 
            0x8AE1E53D6C1BE65AULL, 0xC1AED0C0F84DD8CBULL, 0x287BCB7D2C47C9E2ULL, 0x317826486F16BA37ULL
        },
        {
            0x745A9132AEE49C78ULL, 0x16DBBA586F8B5CC9ULL, 0x4CB5D8B6845EB175ULL, 0x42D163FDD94AFD62ULL, 
            0xF9AF61F1710CEB4CULL, 0x807842800A3D1EFDULL, 0x03A9883A56D10299ULL, 0x52AA5AEC3B4F5AC9ULL, 
            0x76BD205E300185D0ULL, 0x929AB7609E8B37B3ULL, 0xEBBBC8A1EE5F04B3ULL, 0x8EB2EFBF0AABFE59ULL, 
            0x73DCA6A50FF61F6CULL, 0xF26C1C6EB98B285BULL, 0x20FCC887F3C062EAULL, 0x81F00FDC4B7C9D54ULL, 
            0x236A90CC6CAE48D5ULL, 0xBF938CA656D5F288ULL, 0xAF1461E22D031E47ULL, 0xDCB2B000FBFF60BCULL, 
            0x2A8C15DEEC00CBD5ULL, 0xDE027D9431270BF4ULL, 0xDCE266462A04CA60ULL, 0xF88310CC2BDA5FD4ULL, 
            0x82A1EADE98F63629ULL, 0x479F30939CCA7E5AULL, 0xD4E7BA490667152BULL, 0x76A4F61840145C98ULL, 
            0xA627DDBA8E0E156CULL, 0x4E9DC4CC5ADCA616ULL, 0x4EF92F2955013BF5ULL, 0xCDB524160D9303F6ULL
        }
    },
    {
        {
            0xF6986977C5A3357BULL, 0xF72E3A6792E46EC9ULL, 0x580380B888745076ULL, 0x9DBAA7B71DA3A286ULL, 
            0x8A442E09816256B2ULL, 0x6F071D2C28DBE33EULL, 0x85B26FF6DD6A320BULL, 0x0C008AF19645FDAFULL, 
            0x7AABB1045EE8D52CULL, 0xA6BFF743C0A8F5FCULL, 0x940554A9031649E8ULL, 0xBFF9B1D0D7C2D836ULL, 
            0x0506FF4573B7CA9CULL, 0xD037F9B694F0F91CULL, 0x5613F8A49C7277ABULL, 0xAB9C100A7F301A9FULL, 
            0x014C92807477E3E3ULL, 0x4E392382885B1AE2ULL, 0x32497F76C20D06B6ULL, 0xFBA8BCFEFACE34A8ULL, 
            0x26EADC2FC5B9E62FULL, 0xC3D3A3DC92D23EAAULL, 0x74F41FF8AE5936B4ULL, 0xF57F7D8FBE86B7C8ULL, 
            0x1F02A36C4A28714FULL, 0x7EAC24E69C200853ULL, 0xAC7B8610D4D179C1ULL, 0x1C56CA6C993E2A39ULL, 
            0xCA19A67DBF9E66B6ULL, 0x9DD16D632091D4D7ULL, 0xB55709D6ED632DC3ULL, 0xEFA43698D9C1C6A3ULL
        },
        {
            0x3701B0CB9C2FCA90ULL, 0x97451717BCE86D44ULL, 0x774B5527E6BB1FD1ULL, 0x4B84A170902C8637ULL, 
            0xEB484C6FC94D2D92ULL, 0x9534CE61A8318CCCULL, 0x1D95826AD1FCDD2DULL, 0xE0B20BE3C8BAC2ABULL, 
            0x2D838A4D0E49DB04ULL, 0x467BC6359C32818DULL, 0xF64EAACDBA16EFD5ULL, 0x21E96A19C3936B3BULL, 
            0x3DE9A2E100E10EAFULL, 0x8E0CF8FA5DABE34DULL, 0x3C56EA8508DCF2C5ULL, 0x5E65ED7E8EE9DF60ULL, 
            0xBC4BADED633751FFULL, 0x8D82162B5FEE1DB3ULL, 0xDC821F6BFF7B273DULL, 0x6A3ACEE17FA8D1CDULL, 
            0xDBEC5C0BB77189AFULL, 0x63772556D108C65FULL, 0xD149F54EFA3FE2AAULL, 0x941291FD6ED6681BULL, 
            0x4399390BFE8BBD27ULL, 0x6BFF50B7674200CBULL, 0x6987A347402C00E1ULL, 0x209A9ADBED173984ULL, 
            0x52DBE54BC4B67825ULL, 0x2759AAF268EFAD3BULL, 0xDDBC8386F2F88479ULL, 0x11B78A640CB1BB5DULL
        },
        {
            0xC0F3D47F15742480ULL, 0xD503AD19A81837B8ULL, 0x32B60BECBFD54C08ULL, 0x35165104DA716C23ULL, 
            0xEE7BBBAA8714EC51ULL, 0x160B78A332D6401AULL, 0xE7E137C123DD8DE1ULL, 0x8CEBC29BD4A151D8ULL, 
            0x1C5D4B47EABA49C5ULL, 0xA472B3E3020F3B86ULL, 0x6BE7AD33EE508552ULL, 0xC5E4124AF97C2E94ULL, 
            0xC1244DE5EA684837ULL, 0x5C1B0C8078B8A6E1ULL, 0x72190F90E2BF0901ULL, 0xEB5E521DDB85814DULL, 
            0x36C33B229A8C29E8ULL, 0xF02E01D1927E6E99ULL, 0x501BEBDE18DBC056ULL, 0xF4F1B87B96522CDEULL, 
            0x257C522D0E3F95D1ULL, 0xBB05ADFE787EF2A4ULL, 0x6EC9DA991A85B63CULL, 0x86ED1068F526B050ULL, 
            0xD46CBE94CDF350FDULL, 0xFD391F69643D79AAULL, 0xBF88C8E656C8D79EULL, 0xCDCBAD38874AE65FULL, 
            0xD96D5186D5C04FBAULL, 0xB01AFB94DCD34A37ULL, 0x566B83473F41307EULL, 0xBC2FF40726325D12ULL
        },
        {
            0x98545FC8BD411525ULL, 0xED8BA4F62AF1920CULL, 0x2AFC0F79743FE369ULL, 0xA85EF0817237E1B7ULL, 
            0x16F1252FB42FCB02ULL, 0xB1A9C050D77A360BULL, 0x318606D9C76D2ECBULL, 0x6049F1E94E796F1EULL, 
            0xDA68E3D035A74890ULL, 0x1F8BDD89CE91773DULL, 0x5D90BCD3FE8048A4ULL, 0x589DF6FD9CD29961ULL, 
            0x2F1D577503B2BD86ULL, 0x2FC3BAF6AFE12F9DULL, 0x091C269C5B23D148ULL, 0x0181641F65842CCEULL, 
            0x2A263646D89ACCB1ULL, 0x8C131F9259C7DF2CULL, 0x2821743F6CFA2AB9ULL, 0xE8BCE23A31D51781ULL, 
            0x6FB7A20EB8E0BA9AULL, 0xEFC741C7A753E62AULL, 0xECF3A17418C1758DULL, 0x8CC9C99F60B9F70DULL, 
            0x803A7A950012359EULL, 0x5E04E375590E5D18ULL, 0x61A030A293916503ULL, 0xACC5FA22D3EA8B5CULL, 
            0x180CE87E82344D1DULL, 0xCBA1790D0E8F1E56ULL, 0xF1E76EBFE074C222ULL, 0x11E7188F6E2D4D8DULL
        },
        {
            0xF3406EA8DD7ADFF5ULL, 0x34ADDA9926478E9AULL, 0x6E9FAB3DF6CB220EULL, 0xE0CA35FF94063E15ULL, 
            0x3F8399D5582F1DF4ULL, 0xB580D3758081B117ULL, 0x13D629DA9A049484ULL, 0xD5D537B7BC23A1BAULL, 
            0xCBE82A87F7A21748ULL, 0x2BBE9ED1205E370DULL, 0x41246ECB3E0B14C5ULL, 0x57A4298C7213B75EULL, 
            0x21803C3630570E7BULL, 0xE94277104566AA29ULL, 0x118BF6858F5F03C4ULL, 0xF45F255F93F910FAULL, 
            0x4F7510B09C56A3F5ULL, 0xAB0AA1AC8EDDB71FULL, 0x0086B7E970AD85E9ULL, 0x47B98D5AA814BDEEULL, 
            0xAF10024F1D3308E1ULL, 0xDC73FCE139CA228FULL, 0xB3C24D669D8F152DULL, 0x7DEF85A72645C4BEULL, 
            0xAF707F7F40D6B94FULL, 0xBA72FF7C54ACF06DULL, 0x3A16ED4208B3F2B5ULL, 0x62987B6F46F96288ULL, 
            0xEC1297ABED43E599ULL, 0x18FBC635C162C408ULL, 0xF8600FB4401281E0ULL, 0xE093A3BBC34BE696ULL
        },
        {
            0xD175426CDFFA3F59ULL, 0xAFA3E53934BD8501ULL, 0x3A1BCBB3AE20D874ULL, 0x8E043396AFF99846ULL, 
            0x9905E7E9087BEED9ULL, 0x0811A70D01D79D32ULL, 0xBF47212019E29706ULL, 0x814BEC6C02351A03ULL, 
            0x830320590A3E5DB4ULL, 0x7D11484BDF81188BULL, 0x95D0B3487F7BA99BULL, 0x0F8E1C459946A33FULL, 
            0x8553E60BCE0AD96EULL, 0x29181F036039458BULL, 0x6C61D1083B34DE22ULL, 0x7A9218C6D7511BC4ULL, 
            0x57A0386F0B73DB61ULL, 0x1B6B84EEA888A3AFULL, 0x58DA503EA1F0A87BULL, 0x672001C499F7CE25ULL, 
            0x1A227F6ED7BFEB1EULL, 0xF89AA7B19281CFE9ULL, 0x05110ADEF5078977ULL, 0xCE1804BEB05AC997ULL, 
            0xB34F3BD66DF2AF15ULL, 0xA21CB2549D09C225ULL, 0x4BCEA57D53E6AB69ULL, 0xFB86BE950DDD187BULL, 
            0x758F56F5C595A24DULL, 0x8633F047B91881E8ULL, 0xDD055714AA08E208ULL, 0xD3BB2B5CB56F887DULL
        }
    },
    {
        {
            0xEA41C4011E365F4FULL, 0xFFABBA5F30A7E6D9ULL, 0xBB67EFAD5190D752ULL, 0x4FFB33B84FEB76B0ULL, 
            0xB094A45C4B62C754ULL, 0x834F17A3E06AEF96ULL, 0x8EE54E2B27048819ULL, 0x1890CBCBE0A9E9CEULL, 
            0x17B1E55FB63502B2ULL, 0xDA28586FF134A688ULL, 0x18B36B239C0D301DULL, 0xA331F7A9A6DD08D9ULL, 
            0xE4E576456B02CEF3ULL, 0x639624588701E062ULL, 0x491780DD3021C9F1ULL, 0x9A9476EFEE48ACA0ULL, 
            0x2FEBF1BDB8562269ULL, 0xC11EC62953C5095CULL, 0xD1AD2747A42406E7ULL, 0xF84D3FE7D638A9BAULL, 
            0x366206B43D2A1ED0ULL, 0x12E0571213882AD5ULL, 0x31D21917E9838DE5ULL, 0xF68A142957B7D140ULL, 
            0x4C5A1729C03C5A1CULL, 0xD82D8D331B9665AEULL, 0xC85B4FAB1ACB2CFFULL, 0xB10F6484462AE24CULL, 
            0x46A0E1EAD39C8FF1ULL, 0x0EB373DF5F7EE74EULL, 0xF8A6F48BB6506B94ULL, 0x9B3AAB06AD9299D5ULL
        },
        {
            0xF4A8252C4B6F5116ULL, 0x6156353D4A43331AULL, 0x51BD28A8BF094922ULL, 0xA46FBD5E0C85905EULL, 
            0x62FB8EC8BC4C632BULL, 0xA13EBE40FB40DDF4ULL, 0x35D74F961113F815ULL, 0x18F6490D672D871BULL, 
            0x02292071A6A48201ULL, 0xE58F1642862DFC7EULL, 0x0BE34198AE705863ULL, 0xBC69AF3A02C1E3FAULL, 
            0x9E00BE26D81CE9A2ULL, 0xA616E5B7115E6ED5ULL, 0xDD2AABA41F96E50AULL, 0x460C51A48AB9FF0FULL, 
            0xE0D83A87E6F12DC6ULL, 0xBE954A7905F63047ULL, 0x891011011B6743FFULL, 0xFB897DB6DC0AD2AAULL, 
            0x38ACF8756B90D0EFULL, 0x501FF21C4CA2C2E1ULL, 0xF5A6B34F92524E51ULL, 0x42322F5EE418360DULL, 
            0xB4BB5325FB78F9A0ULL, 0xB8A68A143BF73AA6ULL, 0x1998D0CC05F4E617ULL, 0x9648EDF6EEE5279CULL, 
            0x0DF8228B55F5800DULL, 0x94D605956BA1A5D7ULL, 0x73F4CEE35DC88F5AULL, 0x069B104AFF7E80B6ULL
        },
        {
            0x730F5ECCE76DFB52ULL, 0xB5B07C04039B75EEULL, 0xE66DD50A3F282ED7ULL, 0x14A331DCD5BD83CDULL, 
            0x7295D3190EBE06E6ULL, 0xA12A5819D0584EB4ULL, 0xEE1A8B0E2257EC5FULL, 0x66518023F68B05D4ULL, 
            0xBCE459A3294C5EA2ULL, 0xF86E665C9D9D3143ULL, 0xA77E2EFF9A1512AAULL, 0xA39015942CADF0F6ULL, 
            0x2DA444F0AA562E70ULL, 0x8A8DDDEB93C3B8F1ULL, 0xBB64F8DD8ED7635BULL, 0x50864AE2A91B31A0ULL, 
            0x183D0D7204104823ULL, 0xA26E65C850743135ULL, 0xB890129F56A46ED4ULL, 0x5000EE6BD15F6B90ULL, 
            0xBC1C2698777190F3ULL, 0x10029A52681A29E4ULL, 0xCA72C795DCC1FAA0ULL, 0x214A04E6EB1E1E54ULL, 
            0x54C0AE9CA9079803ULL, 0x04C5AFD1BB84D3DEULL, 0x42428CA9801C4A3DULL, 0x9CA5762952A4127FULL, 
            0x2FB6F0C154B1CDB2ULL, 0x2FF11A320428E8F0ULL, 0x10B0E1B697AF5A91ULL, 0xBAAD1E84040D5471ULL
        },
        {
            0xA15DA0E7D1F6C3B8ULL, 0x87798FA4D9E9612BULL, 0x3A9D4FD15879F97EULL, 0x22479354CCF20608ULL, 
            0xF8688311B5126560ULL, 0xE3B482E28AFA75F3ULL, 0x1BC95D078C2E04D4ULL, 0xF2DD2D9EDD918DA3ULL, 
            0xCCB93D4E19A8EC6EULL, 0x7215F2A143DA812EULL, 0xA5F59D9CA63FDED2ULL, 0x7372E6E504AEEC7BULL, 
            0x72A04F43FA8FE75FULL, 0xDCA19FED0CDB7D78ULL, 0x2529BEF239BABD6BULL, 0xBF3B40DFF883B3D3ULL, 
            0x5DEA7D12BA0233FBULL, 0x3ABB91B884CB5191ULL, 0xCA7F9603E2D10F59ULL, 0xE329F3A1BAFF3708ULL, 
            0x1B433CE8C9B99DB8ULL, 0x3A2FC8107B816C74ULL, 0x74F2DF580823B45EULL, 0x77D61DEB33CB3A90ULL, 
            0x005967B69825EA21ULL, 0xAA203B636BFEC3FAULL, 0x7046443A449EF283ULL, 0x728D00CDCBEF66FFULL, 
            0x331757917D1AA904ULL, 0x16C86288CD8048CAULL, 0x80D3CD06CEF54DA1ULL, 0x0218C0067F239405ULL
        },
        {
            0x0AE48F3853877082ULL, 0x7BC6FDB703699EA9ULL, 0x89B89B20CFA57F2DULL, 0x1E677B5915B3400CULL, 
            0xB258E3AD02AF9F85ULL, 0xF6910C8527B3A182ULL, 0x8B812768419FC993ULL, 0xCEC732AD9F6FF68AULL, 
            0x745A21B915CDB882ULL, 0x66251FB57F794BACULL, 0x63DD743F7AAD0523ULL, 0xC6C3E254AACC5FE1ULL, 
            0x07E6CBADC08A85F1ULL, 0xBDBA07AB3A095517ULL, 0x29FBD3AD203ADBEDULL, 0x913D7B6D60C3B357ULL, 
            0xC5BF8E471A620671ULL, 0x2BDF2168289CD4E2ULL, 0xD68076901A1BACCAULL, 0x34F168DCAB09D365ULL, 
            0xE09C6C0FB43E4F1DULL, 0x81438377C276891AULL, 0x222C189FE40F901DULL, 0x79BB289392A352F1ULL, 
            0xF7EA73209FB41D7BULL, 0xDA49EC4BC2F29535ULL, 0xB17BCAF92D0E85F1ULL, 0x7BC2C04AD1C05EFDULL, 
            0x13B7576B22AF7675ULL, 0xD1F8D4DE463842A7ULL, 0x947C28CFABA433C0ULL, 0x38C8B7666AE797CBULL
        },
        {
            0xC091C8C9E7D78EE5ULL, 0x057A848F8DB1AF43ULL, 0x3700BD9A4BE97432ULL, 0x8143D78F777B9B59ULL, 
            0x5E8C6241DE074329ULL, 0x8DCC7F2887F12196ULL, 0x2079974576A2D5CDULL, 0x52EF479F66AC23ACULL, 
            0x38DB15E25765527FULL, 0x9D35763BD5F7379CULL, 0x01E048F12C1B56C9ULL, 0x9F1241E01B5B65F7ULL, 
            0xD45B4474C1DDF6E5ULL, 0x31E214F816D6A6DFULL, 0xDFD96682D298A7D8ULL, 0xE1A3D93B17986A5EULL, 
            0xF29366172CE4E739ULL, 0x01F2BFF18A668791ULL, 0xE50311CF7DA38EAFULL, 0x1B29D36ADC435544ULL, 
            0xC48FE2B500FCD072ULL, 0xCC2950DDC90A026FULL, 0x30C1CC19AC79299BULL, 0xDD2B115E195D30A9ULL, 
            0xDA098ADA3D8F492DULL, 0xE3D5B92EFE3D6EBAULL, 0x32B9CD777A26F9E6ULL, 0x4AD2345D5FC6EBF9ULL, 
            0x1574DB774EDD1876ULL, 0x71B95908F3F951E7ULL, 0x2E1A060BBD5B0425ULL, 0x5812189AED298C98ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseDConstants = {
    0x78BD89769CC5E707ULL,
    0xBF4AA91585557322ULL,
    0x65599FAE6676D715ULL,
    0x78BD89769CC5E707ULL,
    0xBF4AA91585557322ULL,
    0x65599FAE6676D715ULL,
    0x5CBDFF0626C40BF4ULL,
    0x16FA6AA0A226592AULL,
    0x53,
    0x36,
    0x2C,
    0xC8,
    0xC4,
    0x59,
    0xFE,
    0xAF
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseESalts = {
    {
        {
            0xA720D64DA853C886ULL, 0x761A336DC9512A70ULL, 0xF32283B4FA54E6A6ULL, 0x9634C783985F36DEULL, 
            0xD394CA8AFBAB4529ULL, 0x5EE6CD38E6327CECULL, 0x437CE91B3B9E1175ULL, 0xC44D1D25C6DFEAA8ULL, 
            0x155680752EE0A892ULL, 0x70876CB196A71F7CULL, 0x1CDDE27B9A7E06E2ULL, 0xC8908EB4C65A8852ULL, 
            0xB3AB98C242D93B01ULL, 0x5D22029429D98459ULL, 0xBB6352400491752AULL, 0xB63F83DB2D522C23ULL, 
            0x966200F29912E5D9ULL, 0x8BA6CDE0C36EB5FDULL, 0xDCB897217A2F7D6FULL, 0x32E4228CD870D22DULL, 
            0x22DA2B0D46ABEE5FULL, 0xEB0027BE9E5111EBULL, 0xD44617AB548C17DFULL, 0xF26B9BB6E09C7EA6ULL, 
            0x6E2398FCB1458E0EULL, 0x8F602058D3D53011ULL, 0x6659BB5139F639AFULL, 0xBEFE46727757250DULL, 
            0x40C8BEE273A6681BULL, 0xCE0EFABD8DBD3921ULL, 0x73B754E6BF2DEDF1ULL, 0x1B00133CA74D05DDULL
        },
        {
            0x36F05A473B183F58ULL, 0x7A8FB093D61B329BULL, 0xFEEE25704688A331ULL, 0x401680FE288470D0ULL, 
            0x04550FDA164A3971ULL, 0x503F03EFE3361E48ULL, 0x40A7195A4C3711B9ULL, 0xB80A2E4D5F3B463EULL, 
            0x5F6DF96053F6467DULL, 0x5FAC4606297EFF3CULL, 0x9AE17E36BA46EA3AULL, 0x7B740E28ADD43F5CULL, 
            0xAC8CC19F901C882FULL, 0xA3E9EA51507779DCULL, 0xCA3C4B0D815CBB47ULL, 0xFE97BBFCF0D0A631ULL, 
            0x5406F04A76763E8DULL, 0x6E2463BD8A0958AAULL, 0xEEBF941FE0529EBAULL, 0x75929E664E04F928ULL, 
            0x972E2AF2ED86D4B5ULL, 0x9EC4DCE839A9D3CDULL, 0xD74FC902EA1FEC56ULL, 0x2CC63DA22CB0DDB9ULL, 
            0x83C3C92F7D4E0149ULL, 0x052AA61254D3577DULL, 0xFE2C90ADB6132F55ULL, 0xF85F41B5515692C4ULL, 
            0x2F0EDE6B72905BC6ULL, 0x08C6604F623887D2ULL, 0x3D5E9BE0F54D2978ULL, 0xBE1512DB858F23A6ULL
        },
        {
            0xC6E01AF259347817ULL, 0x5F79A116DBBED01CULL, 0xA41704FE55C525E0ULL, 0x6D719FEEC7568C90ULL, 
            0xCFC33B52D532DE0CULL, 0x2EC3EB464527F51AULL, 0xCD0557368841D48DULL, 0x16F4738A735D8719ULL, 
            0x2EA2BD34030D043AULL, 0xF65F78B525E7C0C4ULL, 0x6F6E1A6C52704D91ULL, 0x5BB3658F1487D614ULL, 
            0x994D915FBE61EC48ULL, 0xD56B9D7D21CD9D85ULL, 0x494D2C4405577120ULL, 0xB779A646EA8ABD60ULL, 
            0x6CAEA9389414FCE2ULL, 0x50F53459F06568E8ULL, 0x47CF7D852738D3EFULL, 0xB02024E696C2084EULL, 
            0xEAE6D1454540A1F0ULL, 0x87F38D8415C3AF50ULL, 0x77F6AE6D6D73CCBDULL, 0x74B0E7F47A2AEA2EULL, 
            0x7E65623263FE2FE6ULL, 0x63DEEE607396921DULL, 0xF36A894FDE634547ULL, 0xF15AA60C3E8ECEB0ULL, 
            0xDFA3A9A42A5FFE14ULL, 0x2B9E81C244D8DBB9ULL, 0x6DE16A4FCB3970C5ULL, 0x81A654C61C9B6B4FULL
        },
        {
            0xD2BDC31B9AF93CF3ULL, 0x87E21E1DFFB9AB7FULL, 0x95AC0EA9A1D14265ULL, 0x8AE67D4FF3272366ULL, 
            0xE22C0EFC88584E80ULL, 0x9A6BC0B645E44E1BULL, 0xBDC7435B26FC56B5ULL, 0x455814301A33666DULL, 
            0x325468F3F7690185ULL, 0xA396D333B716F6AEULL, 0x576F300CBDADFB84ULL, 0xEE12C7535145C9ECULL, 
            0x8DC382235C9BD83FULL, 0x2F9335D64D345066ULL, 0x8BB6ABD7CCAE5F72ULL, 0x59BD54BA5A99CEB3ULL, 
            0x9D20F44EB50FBADDULL, 0xFB16948C427A9112ULL, 0xE5DEDD7EF0DD6861ULL, 0x06F11B0984EFF694ULL, 
            0x820534009FF652A0ULL, 0x1978FA2EACE4AF83ULL, 0xC49C8736287EA34BULL, 0x6D30C67A97677F21ULL, 
            0xF9FFA200BDBA7E30ULL, 0x73A525000C0F9AC9ULL, 0x913F347022578C63ULL, 0x5CFE3B541904E422ULL, 
            0x8F4230402E56AD1AULL, 0x556D36E4BA329F9BULL, 0xA6F1AB5E28761BBEULL, 0x8DBD09DE86E888C3ULL
        },
        {
            0x32002A007E3003FAULL, 0xDB9E521C85FD2814ULL, 0x06B2BA485A4E56AAULL, 0x2D683DDA62004CD7ULL, 
            0xC023FF4691A9FC60ULL, 0x12BD5C8F169324DFULL, 0x3D348F2E3FA0C042ULL, 0xEC663B7084F4FB18ULL, 
            0x3B07599D39A180F5ULL, 0xB24B5ACFF14ADFB0ULL, 0x006FE5FE6498AFFCULL, 0xFB505017C0282BB6ULL, 
            0x0DDFBF9C5C4BAE61ULL, 0xE0D2D14AA93660AFULL, 0x0E4CB308BB154694ULL, 0xD58BCD7887854FC6ULL, 
            0xF9466E3F79350ADCULL, 0x24D341E0BD0AFFDAULL, 0xE4ABE655A79E840AULL, 0x1E349D8A092AA9CBULL, 
            0x923DB93CA9BA8EACULL, 0x62E6973E2CC65901ULL, 0x895B87DC488CF245ULL, 0xD61F3E660F8B7098ULL, 
            0x7D5B7A4A19FCFEC0ULL, 0xB3FC742C4953FBD1ULL, 0x99E9DC4B3676D210ULL, 0x06FDBA99C2465D29ULL, 
            0x906F99F558DB5712ULL, 0xAB0160A515426341ULL, 0x2537D15ECD0ED210ULL, 0x0ED4648809200338ULL
        },
        {
            0x615C4276B62D9B95ULL, 0xD8D1A6F36243CD22ULL, 0x6AFA39DEB225D496ULL, 0xC49AB44013A96128ULL, 
            0x7087BC69A46F480BULL, 0x63D41B1F0BB56ECCULL, 0x647CF18F789724E2ULL, 0xF79BD35618970392ULL, 
            0xE00F9F3E520F5737ULL, 0x5A299EF24F634ADDULL, 0xEB2A53ADE9AF01AAULL, 0x1904924490591310ULL, 
            0x9CE86C3BD62102F6ULL, 0x5B3D17B2DE5DE15CULL, 0x40FCC04A635D987DULL, 0xF806893E17CF08C0ULL, 
            0xA78342FE312A2CF8ULL, 0x906D42AE7535F7CEULL, 0xCA1AEE339B1F55B5ULL, 0xF54FADD5B1A7A006ULL, 
            0xEF5D3349E7A756BCULL, 0xBA8DFA21BCC9AEE9ULL, 0x235D4489C0DF4344ULL, 0x388A620294708FFAULL, 
            0xE48476DD293CE2C5ULL, 0x7E28FE4F040F1E94ULL, 0xE27F7474DAFB801DULL, 0x3D17049F5B8C8592ULL, 
            0x16A212A70F6898AEULL, 0x1373DDDC699C1160ULL, 0x0D10AD11CFE494CFULL, 0x0B9F4DFAFA331083ULL
        }
    },
    {
        {
            0x0B009AAF352E1FFEULL, 0x97729DD87A5E721EULL, 0x8DC3795B72F7C786ULL, 0x9886ED2B2B799763ULL, 
            0xD140C5CC5E940125ULL, 0x392E1F8C213ED89AULL, 0xFF968EEFBB0AEA6CULL, 0x0619A27DAF55B9AFULL, 
            0x0CEE8CDFFCF3F79DULL, 0x3900ECBC1660851AULL, 0x2B540D9E242A30A3ULL, 0x90534FD16D6074E3ULL, 
            0xF59C009D1EC0C945ULL, 0x8F3960A6B1C70183ULL, 0x23589F92D9A45AD5ULL, 0x749CC66F270DF387ULL, 
            0x9EC40E1F3C9E9D7EULL, 0x54C074FAFB264BEFULL, 0x7E5BC3BBC04EE7C8ULL, 0x82E83173EA997B2FULL, 
            0xF389CEFE388932E1ULL, 0xA250743C7E40FB76ULL, 0xC1606FADF4136CB9ULL, 0xC8E0F9E196AFFE30ULL, 
            0xB292C313A7FD2FC1ULL, 0x9F9E6F44CA245B2BULL, 0x7BE0D09693BD101FULL, 0x0CC8AEF0DA457B7CULL, 
            0xC2EBB535A91DA175ULL, 0x0304A44704B90C18ULL, 0x9FEF77C9A5249F96ULL, 0x403B7530AA802780ULL
        },
        {
            0xD916CEEB44152449ULL, 0xE76ADA93EC975336ULL, 0x1C074D33F7CDBB0BULL, 0xCE570B46B5FC1D89ULL, 
            0x7384D178FC3E0A54ULL, 0xB5939E45007AE5C6ULL, 0xED2F646A76751DEFULL, 0xE1F3291D972863E5ULL, 
            0x529E90D7C4E32018ULL, 0xD933324A10A17523ULL, 0x7D5F69E81A44354DULL, 0x64626BF7F943E1B4ULL, 
            0x21008E26535AE0C3ULL, 0xEBAEAD5260B5185EULL, 0x0E108A41C9E225B0ULL, 0xD05ECCB4C208E435ULL, 
            0x1C4865CF69D10252ULL, 0xCB938184BC9742DAULL, 0x2C1C84BA91A18DC0ULL, 0x20215FED7A033DBFULL, 
            0xCA7E616CED718396ULL, 0x0EC3A26FBA1E88B3ULL, 0xFD5A1E9CA95A3B26ULL, 0x3331B7949D2A7101ULL, 
            0x8D007B274CD14346ULL, 0x1819A1C0D5297F2CULL, 0x21D98FFEF8C042DEULL, 0x77351E389FE65C29ULL, 
            0x690B3909D8403BC9ULL, 0x5EDA7C721FB4EE28ULL, 0x892D19233C47091EULL, 0x48FDE8B91AC51703ULL
        },
        {
            0x2150BBAC1B75E63BULL, 0x54D41CE66A85B0B5ULL, 0xD4C42209E84EF96EULL, 0x777926B985D8F299ULL, 
            0x57CED560272A6E0DULL, 0x1DB1E9009962CCA2ULL, 0x784DD1D7499A259FULL, 0x362339F93F839D53ULL, 
            0xE16CA822413EE15BULL, 0xA937F6958D4CC985ULL, 0xD35E3EC503A81EE0ULL, 0xB822A85A83FEBD3FULL, 
            0xA6F1E892D0C85E19ULL, 0xABE6F3D8E2AE214AULL, 0x71A40B81E18FCB26ULL, 0xA4CD4D99D3016796ULL, 
            0x7802B1E26D213D52ULL, 0x401A809932815BC2ULL, 0x5CCC97D2F57A81DFULL, 0xABB3919956B589ACULL, 
            0x5843F470DD2DEA07ULL, 0xC1C53CB2AC96A485ULL, 0x7689938CD92B9DDFULL, 0x7C484488D246A175ULL, 
            0xD94488A01FB04ECEULL, 0x316DB41453B38A3BULL, 0x5B7B43FAF6F0D6ABULL, 0x5DE5AAADBEF1EC68ULL, 
            0xCD52B5C2C937F8BDULL, 0xEAF91AF6244FB025ULL, 0xF1162421D95090FFULL, 0xF42AAC08D3FB4D90ULL
        },
        {
            0x9F52AFF9C5D04DEAULL, 0xBDA59061ABE46187ULL, 0x2E231D3B17EEA995ULL, 0xC7FA226319028705ULL, 
            0xCDC912F2D5DA6DD5ULL, 0x3D9DD5155B8C7A1EULL, 0x4847246B052A4D63ULL, 0x2D40DE2CDA4370A9ULL, 
            0x4A56E6F1C76D2C76ULL, 0xB74C755A7BB29C1DULL, 0x4EF10AA3E4AE4997ULL, 0x16439401AB71206EULL, 
            0xD718F0E86E6ACA22ULL, 0x533F9A406C417A90ULL, 0x428AD005A79B869CULL, 0x03F153F4B74CE38EULL, 
            0x452740AFE61454DBULL, 0x7A894F8A395F13B8ULL, 0x379EAAE38478A7BEULL, 0x04976435CD069049ULL, 
            0xF0F5EE16FDAAEBF8ULL, 0x2F00E2FA632A6084ULL, 0x3E431C4ECA35B005ULL, 0xAA0CCA69619F82F7ULL, 
            0x87464085006B04E9ULL, 0x4899C2B2EAB42A40ULL, 0x04B9A8EA3E192B89ULL, 0xC444E976D5A02117ULL, 
            0x2B5C3ACDC7EB22F8ULL, 0xAB6867DB61CA3A5CULL, 0x56483B5182701F03ULL, 0xAEEC126A76BCE104ULL
        },
        {
            0x4A4C99353EB6B72DULL, 0x12EA979EB0F92CDEULL, 0x952EDCB7921D848FULL, 0x970DA3D7DAF27C8FULL, 
            0x874E725A37986145ULL, 0xD8BEF6441B4BEBE1ULL, 0xC96C09724680BFEBULL, 0xD812F7E58A3F12D5ULL, 
            0x74197D533BF2E25BULL, 0xFB6FC5E00866642FULL, 0x677B3BB8D3F55ACDULL, 0xFE867C6AED6EA309ULL, 
            0x93ABEB1FC674E294ULL, 0x06A1F63B109D331EULL, 0x77CE95603B6C58D1ULL, 0xCF797C4C27DDA77BULL, 
            0x6177E4BB1A75FD07ULL, 0x897E7D73D1CC70DAULL, 0x7CE5116431CBCC3BULL, 0x986F1BA91F69BE72ULL, 
            0x5BFF6DACC7AFF80DULL, 0x56EAB833B794FCD1ULL, 0x83B450D5B0FA9DA7ULL, 0xFB4AC184F7E1EE92ULL, 
            0x5C230D722719D0C5ULL, 0x7AEFEE5224AC2336ULL, 0xD27133DD947EBFDEULL, 0xDF3B79F989EBD87CULL, 
            0x34F55E7F16B9B24AULL, 0xF67A9FF3772944F5ULL, 0xB9DE91E7464F7789ULL, 0xFDCE8ECE6AFE92D0ULL
        },
        {
            0x33952E35CCDE642DULL, 0xC7345F547A407413ULL, 0x7C439FADE053C90EULL, 0x8A845906874C539CULL, 
            0xB478BBC0037C42D4ULL, 0xA1A631AB63CD683AULL, 0x7B1A0490BD03F980ULL, 0x3D086AD7B8E54094ULL, 
            0x59F348545F511E2BULL, 0x5739230F43809E1EULL, 0x66FB1BB36E9B3D5AULL, 0x89DA4E52F110F563ULL, 
            0x01BCF803E9320880ULL, 0x335D6673ABC62419ULL, 0x597166C2E18D115CULL, 0x016F34775C1CD631ULL, 
            0x07EB8BBAA0539E80ULL, 0xBC16DB82B7C2FD8EULL, 0x9917C04EF6A62DF6ULL, 0x8A28F648F1202C9EULL, 
            0x6E55DB3198D0C5E9ULL, 0x56072CCA980411F9ULL, 0x2A4F3FDBDA1C5309ULL, 0x49CD47E21102B828ULL, 
            0xBC8D61A188A25204ULL, 0xF53EB213A3FB0210ULL, 0x1DE553999E4BE4EEULL, 0x549ABD2AF2EB35D8ULL, 
            0x5E0D800FE667271BULL, 0x2CF9D7CFA6274D9FULL, 0xC747F94AB5A28AF1ULL, 0x687CD770F1B74109ULL
        }
    },
    {
        {
            0x156609AB3CA0A317ULL, 0x949167E70B212768ULL, 0xECFE68F01A06384FULL, 0x34A25E3AD37E7F22ULL, 
            0x97299378D590EAABULL, 0x2A861519F8F8EBE2ULL, 0x97E46366A2012C2EULL, 0xDC87BBB938062B13ULL, 
            0x78DDE82F5EE02EDEULL, 0xADA5DB5C2BA96C09ULL, 0x72411F7CB95BDD6DULL, 0xBF6AF170768111BBULL, 
            0xCB399CE46D535690ULL, 0x6A5D515489E50EA2ULL, 0xD4E7DC24BFF2CF59ULL, 0xF0509431AD348264ULL, 
            0x9AC405A358EDD546ULL, 0x97C6CD51C555EB95ULL, 0x53C0D9F3B6C11544ULL, 0xAC4D3176415483F8ULL, 
            0x5D2C745E4A2C7467ULL, 0x54D9CC14316DA174ULL, 0xE282E5B8A239F742ULL, 0xD1A94B97DD6EA85CULL, 
            0x969B6E8EEC1D4AF9ULL, 0xC794AD8B395CCFCFULL, 0x4CD5FD5D593623E5ULL, 0xC8F16703239DEAC0ULL, 
            0x73FBB9E7C84801A6ULL, 0x135E3B8C0FCE8D0AULL, 0x4E22528C4EE075DBULL, 0x15E21786D15D44DDULL
        },
        {
            0x50EC5937D4EE9769ULL, 0xAFC52BE7DB729938ULL, 0x99FCA68D5FBEEC39ULL, 0x26A5C6324E756E48ULL, 
            0x6F7CB3E6CA690BA9ULL, 0xA7361B10BA1957BAULL, 0x1C0B7DC9042FB274ULL, 0xE4CDC00EEEAB1AB1ULL, 
            0x77F3040366555924ULL, 0x844905040C3AB941ULL, 0xBE0A056E3152747EULL, 0x5F1FCA2B383994EDULL, 
            0xC687E52AD40B95F5ULL, 0xD38E1B4A6B482711ULL, 0xF3D61BC9AFAD8B72ULL, 0x693CEFEEAA44BE55ULL, 
            0x3B161589F3074F22ULL, 0x8FD184CD1EFBF0FCULL, 0x1B602E6E559CE16EULL, 0x8AA9C017E73253A4ULL, 
            0xB925F2B8ABCD3AEEULL, 0xDEEDB5B88A65C251ULL, 0x7E1C50534B6D086AULL, 0x9825A07774FB2940ULL, 
            0x1805617BF75117E3ULL, 0xDE42E9598385EED2ULL, 0xB83CB1EE5AF7383AULL, 0xEF3DF8B43DA8CE4FULL, 
            0x790FA6D970881881ULL, 0x9A2C463637402FFBULL, 0x5CC1A9FAA45F9D8BULL, 0xE19E1EFE461D2FE1ULL
        },
        {
            0xBFA59B179B982CF1ULL, 0x50EDAB9B57D15A65ULL, 0x920867BDF26636E8ULL, 0xEE3A45C36B79C607ULL, 
            0x45D8A5AA5C2FF7A4ULL, 0x0F75E8C1A1BED4E9ULL, 0x853CD267A9D560BFULL, 0xC11D477F46F93C02ULL, 
            0xBF76DEFD7A61A93CULL, 0x9A096C116CC72B6BULL, 0xC57D3DDBFA93A5EBULL, 0x4905455E5472A41DULL, 
            0xC64D6384B0AB9FC2ULL, 0xC4B36777F8F316A6ULL, 0xD21669846A99E2B4ULL, 0x810FB17A9FC1DAC0ULL, 
            0x68D856769F61CCD4ULL, 0xE7AFED646946810BULL, 0x4AB4E0C2037CD899ULL, 0x30C753954274A118ULL, 
            0xDA8E43C230063A5FULL, 0xFB0F1778A022BF77ULL, 0x54A43D10388D733CULL, 0x8394147D65E28A55ULL, 
            0xE0005D2A6D202C0AULL, 0x48B2313ABAF34B37ULL, 0xD4986E27DFAA9216ULL, 0x81E4DE982714A693ULL, 
            0x9058304A13C365E7ULL, 0x9782F1F982AE4B18ULL, 0x8922FFA35FC0E593ULL, 0xF0CA4D510D77FB2FULL
        },
        {
            0x494368338DB16A78ULL, 0x76110CC4BCD5F12AULL, 0x64E3A53F5A83CAC9ULL, 0x9F1909443BC7BB5CULL, 
            0xB7BBA539B9B5368CULL, 0xD0733BD475F9D280ULL, 0x45E288C70DD4BBC8ULL, 0x3CC0371611C173FFULL, 
            0xD24C4907CE75BFBEULL, 0xA4699274912C3288ULL, 0x35876F9F84C2762CULL, 0x2B69B54AE4CAEFE8ULL, 
            0x4D073F9797A79628ULL, 0x42CE1B138E555E12ULL, 0x311A7FEF34DC15D7ULL, 0x748AF9325DA841FCULL, 
            0xE89CE71EBF2DD03EULL, 0x54A074C7008769FAULL, 0x15ADA799023935EEULL, 0x88FA86CD184A8F69ULL, 
            0x2603052C7222AE8DULL, 0x1EC6662860DB8C28ULL, 0x69D63B2473E6C382ULL, 0x075EF3D082309F29ULL, 
            0x11D8A9A709E8B6C3ULL, 0x711DD608EE442C16ULL, 0x850A0584C8253869ULL, 0x1FB3F065099B57A4ULL, 
            0xF3C7E0AAB362A632ULL, 0x36D6D9038A8BD42AULL, 0xE37DC6E8E3A0B6E9ULL, 0x7FB8F8EB7B28A991ULL
        },
        {
            0xF029D8F4C3F1E342ULL, 0x4EF2A14B1DCAC658ULL, 0xFB6CD9798709E024ULL, 0x0547956FE9FDDF64ULL, 
            0x3852E2F4C983AA3DULL, 0x21CF930FF43BAE38ULL, 0x1E0C21A9CB756491ULL, 0xB5E360AAFF822552ULL, 
            0xA964F0CA1FC1BFD3ULL, 0x6D4583DE616BBF33ULL, 0xF72DC3FD4454283AULL, 0xADD20F508D57F670ULL, 
            0x438298B70A959A1CULL, 0xA77E204AC39FAD77ULL, 0xC237582ABD21F412ULL, 0x80CD64E9E4616271ULL, 
            0x3CE71205F95A0799ULL, 0xF7B55D23D7BE07BEULL, 0x63876D09FA2DECB4ULL, 0x3F0C8F0113606A01ULL, 
            0x4FA52F4D7CEA9DA4ULL, 0x30DBCD29A4F97675ULL, 0x7042CA6CBFB2900DULL, 0xBBDB6F3C4CBDA4A1ULL, 
            0x4A0EC4BFB2159219ULL, 0xBD654681FD8D4196ULL, 0xF4DEC3EB2CA7527CULL, 0x3882F3DE899DF93BULL, 
            0xDAE5CA6DA9D801DCULL, 0x52815FB98F142B60ULL, 0x0E2EDD47282A3017ULL, 0x7E71394E71C1D43DULL
        },
        {
            0xF439E9C627767F7AULL, 0x9EEF523B816D64DCULL, 0xA1B94CC7855AA96BULL, 0xABE516A3D3D0F68FULL, 
            0xC1C37204022DF49FULL, 0xF80667865B75E978ULL, 0x04DF1430C9FC2FB1ULL, 0x7DF087564D948AFBULL, 
            0x3BC44045378CB98BULL, 0x23FB2F19C434F75DULL, 0x3FB6E5E6EB9C5B88ULL, 0x2FD9AAF4441930AAULL, 
            0x37B4B0465F9CAC0CULL, 0xF1088B433DF72BFCULL, 0xFFD2B5B1CFA1AD8AULL, 0x2B383ACE733B938AULL, 
            0x1AB134B9636D7667ULL, 0x0678AAC39BB46EC6ULL, 0xD5237782DC94A320ULL, 0x94895E6BBF65D286ULL, 
            0xCF8116BA5729E73CULL, 0x41ABA6AD2315BE6CULL, 0x23441C7F12EFAB01ULL, 0xD85398AF7704FF7CULL, 
            0x0E76D348CCACF9C3ULL, 0x046A5061AB40F639ULL, 0xB44D215EE29B6CCAULL, 0x80D13BD4F1AA8999ULL, 
            0xA06218811B4A0EC1ULL, 0xBD250A6567986C21ULL, 0x8B1AD87D73592523ULL, 0xFA3408D5A01B445BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseEConstants = {
    0xCFE82C69696C05A2ULL,
    0x7DFAA1BB8B0DEB81ULL,
    0xEA19EF7E329B95E1ULL,
    0xCFE82C69696C05A2ULL,
    0x7DFAA1BB8B0DEB81ULL,
    0xEA19EF7E329B95E1ULL,
    0x4008F2C289CA0350ULL,
    0x01A3704EAB68CC6BULL,
    0x2E,
    0xBC,
    0x8D,
    0xC9,
    0xB7,
    0xCC,
    0x58,
    0x5D
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseFSalts = {
    {
        {
            0x561639D49DCCAAB2ULL, 0x574CA8B395B8D025ULL, 0x58FA16A0619E80EEULL, 0xEF3930B9A4E3F935ULL, 
            0x67D9308F9F7D5C62ULL, 0x647BB07B434E28D0ULL, 0x6762CFCDEF76FCF1ULL, 0xBBF0466161DB1C84ULL, 
            0x56339213B9CFA16BULL, 0x2993CAFA45504D52ULL, 0x4B86C2EBDFFC9B9FULL, 0xC25347AAA75091B5ULL, 
            0xAED5FDCDDD990575ULL, 0xD6BD3405D4415A56ULL, 0x2489568BFF61FBF1ULL, 0xBA9007FF37204A0EULL, 
            0x0A4BE0CC4BC97876ULL, 0x46BFF7A090638277ULL, 0x459C3D257DD0A1A2ULL, 0x7C97E3F1621CB369ULL, 
            0x8CA70EAACB0D9F13ULL, 0x6C2ED538904132A1ULL, 0xB93069CB02406F33ULL, 0xECF87373061F96FEULL, 
            0x523529F456B449B0ULL, 0x1B1491301D3E0962ULL, 0x73080AA91F706410ULL, 0x2A8BF86DDB53B870ULL, 
            0xADA10A9FAED5A658ULL, 0xDD35AEF960FF61E3ULL, 0x475DEAF18D81B15AULL, 0xF1EB3961177700CCULL
        },
        {
            0xDF25D2101FE4B4E6ULL, 0xD39A167B26152DB2ULL, 0x368EFDD3A744EDA3ULL, 0xCE98EF7B1258F4D7ULL, 
            0xBDDB09A52048C781ULL, 0xD2A17B068D0024C6ULL, 0x8ED87D3D77A906FFULL, 0xCE3644497C8613CCULL, 
            0xA5522183AE1F470BULL, 0x4F692BF5E67A3C57ULL, 0x5B1425A55D9238A0ULL, 0x1163B8AB89D36773ULL, 
            0xD3FDC6551E0EB8EEULL, 0xE3E1B6DEA0D13D2CULL, 0xFBC5E07C4834E4B7ULL, 0xC97E7866A7B0A80FULL, 
            0xA39ACCA6E4DD38DBULL, 0xDCEF103AC96D7F93ULL, 0xCEF61B4D6A853531ULL, 0x84C2A6081CF453FBULL, 
            0xAF94DB45C7DFC918ULL, 0xB219B542479302E1ULL, 0xB9E7AFBD051ED5CCULL, 0xA9DF40C933B86953ULL, 
            0x4D11971F6543C7BBULL, 0x27421FE4157759E3ULL, 0xC744640CD569CED0ULL, 0xDBF63D102163D5DEULL, 
            0x06C24D90FA611A65ULL, 0xC725BC3C1ADCD754ULL, 0x530C5E1605635297ULL, 0x5C840EDA14F7C9C4ULL
        },
        {
            0x4AF02110485AAE77ULL, 0x62BC4087189B6251ULL, 0x5E37868AD4A02942ULL, 0xFD93262041E729F4ULL, 
            0x590C5C0BD33DE4BBULL, 0x3390CD155565F61EULL, 0xBE77FE98CCFE5A68ULL, 0x9EF7CE548574D442ULL, 
            0xE93111B8A51E4C44ULL, 0xFC9DF8688BD69E1FULL, 0xF7475780AE86D5D1ULL, 0x29E939D2F7406EF3ULL, 
            0x1600DCB4D31D9F72ULL, 0x6A3D9336C1870F5CULL, 0xEF94D8A46CC9FBA0ULL, 0x55227BA8210D68F6ULL, 
            0xBE3B5C4D771FA874ULL, 0x16343724016B69C5ULL, 0x74BDB8DF236E7CA1ULL, 0x200DD87A17CDB1EBULL, 
            0x09349E1E9A928BAEULL, 0xB05BD65DA722FBD8ULL, 0x533BB17479806216ULL, 0xB5063863B19F7A53ULL, 
            0xA1F3B8FC3ECB103CULL, 0xEC156509EB54BB78ULL, 0xFA429312D83B1EEBULL, 0xBF02AC5A35E70BAEULL, 
            0xABBD06FDE6495D3DULL, 0xE5D48AF73AAAACA9ULL, 0x881A456AD6164AB5ULL, 0x29A338228E0AE571ULL
        },
        {
            0xD6BFC630C608446AULL, 0x59D1C3B4988FC366ULL, 0xE20254178953A7FEULL, 0x7B8B33A42C4B084DULL, 
            0xB4D135ABA876D054ULL, 0x6361DA157ED30601ULL, 0x3B75C906A962878FULL, 0x3B683B3B501B3911ULL, 
            0x5F07FA36B0A3A9C0ULL, 0x712C6BAB9B00A4A5ULL, 0xD2E3A8F5819E9146ULL, 0x01F8188BD11B0741ULL, 
            0xC76199BA3B73C33CULL, 0xF328E0CE0E20C746ULL, 0x0395DDA2441C866FULL, 0xEB8CFEDF2784945AULL, 
            0xF14BE3943FE3F4C2ULL, 0x5413C791A488831EULL, 0xD9DDCEE8881389A9ULL, 0xFEE1A202CA6A217CULL, 
            0x321750962EE1F086ULL, 0xAA0701F10EEB9DBEULL, 0xF00667712AD7E86FULL, 0x992A11FED9E5F8D4ULL, 
            0xBC773D6CCF7F06FAULL, 0x76E1E3538D735E5CULL, 0xE72F0F31E0E6CE61ULL, 0x996B9BBA9096BA70ULL, 
            0x8B192306776E94D8ULL, 0x0FB8FD1F8DEA9400ULL, 0x7C078AC327317C1DULL, 0xE747F33B4054D42DULL
        },
        {
            0x386FEEAFA3DF1435ULL, 0xAB2BA60223673F07ULL, 0xFAEA0A24A47F2F2DULL, 0x618802360D961D4CULL, 
            0x786DFC47F89A9675ULL, 0xD6A9644E39664F76ULL, 0x21878C764DD4BA28ULL, 0x2CE1A294139BC4EBULL, 
            0x862D0F058BAC1B5DULL, 0xAC225BF9DB52FA0DULL, 0xD5A4021C81DE892BULL, 0x89D1B084637451B1ULL, 
            0x27A30D80507D71F2ULL, 0x3D37DE50A7F01100ULL, 0xC252FB70B3BB46C2ULL, 0x5F0DF97D5AF25622ULL, 
            0xB27B2DF712C9CDB7ULL, 0x514C10BE9783DF2AULL, 0x208C7AE848D9C669ULL, 0xA4C2DAD933A6FFD8ULL, 
            0x16AAA20B58936B0CULL, 0xBE825E9782A5CF60ULL, 0x26462877660E5489ULL, 0x479A270C5232B442ULL, 
            0x2F93CEAAAF6C74E1ULL, 0xFE31A78A7D7BADE4ULL, 0x63B32A8751C4F55BULL, 0x6D8FB8B6AF2467B1ULL, 
            0x630CF46A40CA9DF4ULL, 0x34F56F67A3D9BC1FULL, 0xF06C2AB545F2E18AULL, 0xD6FF6CD4476BB783ULL
        },
        {
            0xBA0A25389D277C8EULL, 0x7FDCFDFC8EC5D518ULL, 0x564D4CEA7406D565ULL, 0xA0C75B6C103B3D7EULL, 
            0x2107E494D10389D0ULL, 0x2E8BD066413D661FULL, 0xD8B249A485E784B0ULL, 0xAC3DB7356ABAB1F6ULL, 
            0x69209560CD3C0410ULL, 0x8E80A0EA4A21F082ULL, 0x09CDC1396CD68DBEULL, 0x9B0298FA0D122C48ULL, 
            0xE347D8378E3C1C0CULL, 0x4F2FEC0A7497A7E6ULL, 0xC85F1945292C8B97ULL, 0x2FD7EB8A0550C8C3ULL, 
            0xF247865A0759BB74ULL, 0x2C7B9552A6F37721ULL, 0xB85BD22248E8C08AULL, 0x3DBBDC95CF3E40FAULL, 
            0x0A0FBA10284AE7EBULL, 0xB5A8A71C93DD3C32ULL, 0x5B34A75D40ABC84CULL, 0x08A2121DDC7A5614ULL, 
            0x6FBED5FD37088E3BULL, 0x08DCA624CC4AE2F8ULL, 0x09E06736E132982CULL, 0xAA96F0E631BFA3C8ULL, 
            0x143F606872A02F3AULL, 0x40E226F32C8D1457ULL, 0xD650C95D5E483EE2ULL, 0xE7DE65AF3D043DC1ULL
        }
    },
    {
        {
            0x86A8374787C6B83FULL, 0x0DC21B015E067CDDULL, 0x4620CFE7D4A460D0ULL, 0x1617CB02EB8E42A8ULL, 
            0x2CC1B64DE9F62C69ULL, 0xD084C6CC630225B1ULL, 0xE0D9BC96E802D6A9ULL, 0x665E5853AF9BE409ULL, 
            0xE3755705DFB781D6ULL, 0x4A5F0A8F091D0312ULL, 0x51A2DF909B9B39A6ULL, 0x96CAF8D8E4919B62ULL, 
            0x6A54910E40FF7FC9ULL, 0x0277D27D05A4E15FULL, 0x7BEBC249F1FE5638ULL, 0x41DEC70E3D16DD65ULL, 
            0x49EFB892F41ED368ULL, 0x424E5A13933A2A7AULL, 0x4A40E64347009CC5ULL, 0xF550C980D2F72D2DULL, 
            0x7A6CE2B3F76E0A6CULL, 0xB7D80C28E0F16E36ULL, 0xA682A37458BCBED9ULL, 0xF14B323B9C9CD0F0ULL, 
            0x1686AA8CCE6420D4ULL, 0x3A096ACD5358F638ULL, 0x19FE9C78A737F9C7ULL, 0xB040A978711F2B27ULL, 
            0xFF8B6A28EECFEB1FULL, 0x5EE8C1D00BD40A56ULL, 0x246FD88AC07E4C41ULL, 0x7DF990C23B809ACAULL
        },
        {
            0x0604B78A61D804ACULL, 0x4EEC55BD16C6286EULL, 0x67174F14ABA9D0CDULL, 0xB6A0F1D219C4CD58ULL, 
            0xF7FB6F2A94C16F87ULL, 0x8DCA27BC399DBD13ULL, 0x2AE1721CB7BF59F2ULL, 0x710F1D957CDAE839ULL, 
            0x212C46F7B54FCB48ULL, 0xA83A019C3FE67BADULL, 0xEB14AD96B7470289ULL, 0x9FE68A539CA3E274ULL, 
            0x913903BC988CBB9BULL, 0x6F8F473DF8BBB01DULL, 0x7081E763EEEF1217ULL, 0x581C5DE5D1AFC9B7ULL, 
            0x539E528640991538ULL, 0xC6A6C5514FDA3684ULL, 0xBA963C38D10A43B6ULL, 0x1CE545B60FC706DFULL, 
            0x905BCD8AE5BA0E57ULL, 0xD3EBFD738BD52256ULL, 0x33D03FBD77C14801ULL, 0x3E1C4A937ECADF94ULL, 
            0xE25FC2C8E05A4C16ULL, 0xDAF3477EBB850329ULL, 0x5E4B7E86A4FBE3DFULL, 0x4726996C5152EC7AULL, 
            0x84AD3A2CCEB84420ULL, 0xD18F46F5D16C817FULL, 0x2BF03EF5E9BE6459ULL, 0x8A9B4E9F5F6EA3CFULL
        },
        {
            0x4FB0479EFF7FF15EULL, 0x7C7982E014DBE106ULL, 0x1A6CA89CC3263236ULL, 0x59D8D465AED715ABULL, 
            0x399FA687BD055599ULL, 0x81E4E147937D9FB8ULL, 0xC7DCC4103728C937ULL, 0xC5ABABADB8F627C3ULL, 
            0x4F9F823132BE1619ULL, 0x2D97F5C78B43241CULL, 0xD020B7D3CCA8F9BEULL, 0x5C8AA0002666DCC0ULL, 
            0x39FD050E43B1DB4DULL, 0xE866CFCFBC01126EULL, 0x083CE040C7897682ULL, 0xEC1CC6D67279A76CULL, 
            0x966B6603E5D8D434ULL, 0x13F2F3EA0FB94AFEULL, 0xBBBEA717E2253415ULL, 0x0B7E32C3B440F88EULL, 
            0x8C7BD58CF1747CE7ULL, 0x033D97ECC741325CULL, 0x327B234B691F3C26ULL, 0xC6B0F8378D3C4D38ULL, 
            0xFE7736C3CF8FCCDAULL, 0x1D38FEA2CDBB48E0ULL, 0xEBE22982EEC8B2E4ULL, 0xAC671C0B8C1F95B3ULL, 
            0xEB4C00A2CCE8251BULL, 0x6A027F5EC324209FULL, 0xFBA35EE9D0610D93ULL, 0xDFE50D3A9AA60836ULL
        },
        {
            0x776DFAAF6A5FCFBEULL, 0x974FEBD48D33FD11ULL, 0x1BE183E61E650671ULL, 0xEFB991080DB74767ULL, 
            0x3606C0E2E8C1AE0DULL, 0x9D159B63072EEEB3ULL, 0xA0E2CAB809D47D29ULL, 0x49C84E769102D30FULL, 
            0x138A4BFD27896CCCULL, 0x12DFE8AA5FD6DFE9ULL, 0xD9E1E9E01036500FULL, 0xAB959E66B92DAD88ULL, 
            0xDA1D045D0245126EULL, 0x78DD10769D2398CBULL, 0x9D4A774C348CD721ULL, 0x7404FFEBEEEF4D6BULL, 
            0x4B62557A3871562AULL, 0x6E7A31AD552157A6ULL, 0xBE95D30F5E03D4B2ULL, 0x9F0B9C4A30CB4D07ULL, 
            0x854E23CA8EED31FFULL, 0x54C321E561DAE1C0ULL, 0x867D3FFF56B3BDDDULL, 0xFBAF2E14F2B657DDULL, 
            0xAAEEA8055011E42AULL, 0x78315DAD54D02909ULL, 0x4422D06B8C5AA467ULL, 0x1ACA7FF5927576B9ULL, 
            0x19E9796D90924C16ULL, 0x0C3B5DD3A7B34BDCULL, 0x0E5AE09BC0E566BCULL, 0x8EA2FFCE3D182F71ULL
        },
        {
            0x64C669AFC7D86532ULL, 0x622207AE91BD2C65ULL, 0x59CF065D9CE9500BULL, 0xD7402565C5A7F14CULL, 
            0xDD62CEB89D6BB3D1ULL, 0x9AE3EE2BACF3178DULL, 0xBEC048A1012267C8ULL, 0xF50CC5E1CA8D1CC3ULL, 
            0x4B04CBE208EC648DULL, 0xAFB7BFD4FAEF1A1BULL, 0xB0CC70D0F38B107CULL, 0x2AEE0E087861123BULL, 
            0x751911B67DC7E8C3ULL, 0x39988692AFD30330ULL, 0x260C5263A965F6FBULL, 0xF08156D9D554434BULL, 
            0xE3FB571FF25700A6ULL, 0xE2096323B74010E2ULL, 0x8434520B67D564E9ULL, 0x80BC0D44467AECB9ULL, 
            0xC34B74F1CAB9A66EULL, 0xF9877A7D7E7F5BBFULL, 0xF69C386D455E76E3ULL, 0x90A9F9384EA33AA1ULL, 
            0xF9A2A81A9C71FDB8ULL, 0xD1F491C8FB8AD372ULL, 0x5B94E94BD37A57F2ULL, 0x14812DE92FBC0FD8ULL, 
            0xFA9D6982330F58D0ULL, 0xA8A524B07509EF4DULL, 0xDB0E5301ED19B2E4ULL, 0xD69632D9306819EEULL
        },
        {
            0xF6C0D19B673DF5C0ULL, 0x962EA5149D47160BULL, 0x0C19F000FDBC7A24ULL, 0x5BE2EE8242E7CD64ULL, 
            0x7EEBF8DB13BA5956ULL, 0xB90D40DAB8056856ULL, 0x023809BC37085B14ULL, 0x0CB716F7C1AFB33DULL, 
            0x5AA65B3B0F2F4B8DULL, 0x7608DE9D79965AF9ULL, 0x98B99277CC3D5607ULL, 0xBB31143FAA14336AULL, 
            0x16E6741FF3A2E2DCULL, 0xF2EC8EF5488D087CULL, 0xAFF2EAC93A543323ULL, 0x0B00E6CAAE9AFCF5ULL, 
            0x1A88126FC0059817ULL, 0xC35BD9F0DBE28CA3ULL, 0xE5B7BD1638D47253ULL, 0x349EE5BFFC892628ULL, 
            0x92C0D47F3EBF4708ULL, 0xED23A376A9B9CA97ULL, 0xD26A77B2AD43139BULL, 0x20F33196BB2141ADULL, 
            0x388F86B67FFC671AULL, 0xB69DD857613790C2ULL, 0x08E879AB28BC07CFULL, 0x96020252594D1FEDULL, 
            0x02E727218D478DC7ULL, 0xB27ACFEC86004A1FULL, 0xA3EF4575052DCD77ULL, 0xB9FFEE5B821BF5B7ULL
        }
    },
    {
        {
            0xB3F2A6BD53AC9C0CULL, 0x0DD62EC702B740FEULL, 0xE03D6E9A0107F920ULL, 0xE044B176288C1DD4ULL, 
            0x88B95A1C565819F3ULL, 0xDDAFD68C9AB07971ULL, 0xAFA3854BD02A6957ULL, 0x8293D75949BC74A9ULL, 
            0xC8738A8F6AC8CB25ULL, 0xE13F8DDA0B3F8497ULL, 0xB028CAD842043FFCULL, 0x77E2FF4930186E76ULL, 
            0x9104EB86078B84A1ULL, 0xF3B0DC0E746915A9ULL, 0xD10D60F80F9B7415ULL, 0x652275E97701A543ULL, 
            0x51145F380A3BB657ULL, 0x9980F4DC5C3E7A23ULL, 0x8DACFEF36CA312E3ULL, 0x252CFD4D1454D227ULL, 
            0x8FCE5F3B62191179ULL, 0xB85E2E03D3CC3B66ULL, 0x73CCC0742FDDE2E6ULL, 0xC8861948CF9E5CECULL, 
            0x0998171E6E308E63ULL, 0x4CCF4C4CA24EE42CULL, 0x10FFD391A9E4ECF9ULL, 0x38613BF3506700ABULL, 
            0x585A675EB96263AFULL, 0xEC07E3980E120B3AULL, 0x3C2209B937E188F4ULL, 0xAB6AFB0305CB5975ULL
        },
        {
            0x9866271CF9520FC6ULL, 0x1C5C9037BD6CC4BDULL, 0x2AA8AA3455A980B9ULL, 0xE6367791660B0F4AULL, 
            0x9406158BF3A4BB50ULL, 0xCB1D5BE59E1C8D4FULL, 0xF8F8ED7B57A046EDULL, 0x08CE53DB0C9D35E2ULL, 
            0x50F82BBE9BD212B2ULL, 0xECEFA7A3C2E92B21ULL, 0x76F593E84358E84DULL, 0x3E455F3A7987D403ULL, 
            0xA0FBD05486CC5F6EULL, 0x8D50FBB1B9B022D4ULL, 0x65C0E5FD7BB303DDULL, 0x4ACFD111570F87D0ULL, 
            0x338CC881A8AF538AULL, 0xD4DBB3FAC6FFFD9CULL, 0x6A87BEAD1C2F53BAULL, 0x2A1B7A0C412F35B1ULL, 
            0x2C697022077C731AULL, 0x188C411774427812ULL, 0x2123D78B9E3C02EAULL, 0x1AAAB9C6C622B90BULL, 
            0xB1A5E3867AF72BE3ULL, 0x773FFD9480BC87EBULL, 0x66AC1E74AC4A898AULL, 0x7BB942F84E1EAA76ULL, 
            0xEF5E55DA5FAF1294ULL, 0x66DDD44749C21C69ULL, 0x5C43FD7C29991CF4ULL, 0x67BA182DF70DA35FULL
        },
        {
            0xD741798B3FA228CBULL, 0xA52583B0632F02F5ULL, 0x4C3C13103D842723ULL, 0x942A0304DE75FC23ULL, 
            0xECA207F80D86E2FBULL, 0xEC9F917CED794C7BULL, 0xBE546AC9110B159EULL, 0xBA07B4E10443DC8FULL, 
            0xC3668A3DE41AACDCULL, 0x3E8DCD850040BA4CULL, 0x1D5A69249EC38FFFULL, 0xF789E77EF154DF9BULL, 
            0xB1A4E7FAD22F3826ULL, 0xC6DF97680A00AE7DULL, 0x53876BADF46EF1E5ULL, 0x6C64322A714257D6ULL, 
            0xD7E84BAB19E83CE2ULL, 0x1EA372CF3A7D48F5ULL, 0x272DE0E4C34E5612ULL, 0x43BA8A79F98578AAULL, 
            0x9E7429843585C36CULL, 0x86170CBF0A9E48C3ULL, 0xB696766682E5F5CCULL, 0xBE7B1DA1878E1216ULL, 
            0x5282CA8B039CCA09ULL, 0x0C39CB674E368C0AULL, 0x747DF072241F3AF5ULL, 0xF429A85A9198E7F0ULL, 
            0x6E299182BC22A7B8ULL, 0xE1BBB64EF4C2FFBDULL, 0x461D0BC612BFC434ULL, 0x950B2D0FDC2A80CAULL
        },
        {
            0x1C65438733A1B1EFULL, 0x6EFA20E3115DC21FULL, 0x4F96770EB375DE58ULL, 0x1F45F65814525E06ULL, 
            0x71F0984D56DA38D0ULL, 0x4AD837B99C06E38EULL, 0xEC1AD2ED89F2FAD6ULL, 0x027D844086805DC7ULL, 
            0x4ACDD29E00B8D9ADULL, 0x4522E07BBA85E74FULL, 0xE2548057A5367E4CULL, 0x9AF29169FB2E9D31ULL, 
            0xBDAE612221FF6A8CULL, 0xF03E322663406DC7ULL, 0xC265B6A2EABD316DULL, 0x7DD42EF11E1A8EEFULL, 
            0x8A9FDB2E7C5C845EULL, 0xDAE34ED3A60FEFD4ULL, 0x48B8721C4B06932BULL, 0xE26D5F44121465BBULL, 
            0xAC5C828245102104ULL, 0xB6C1AA5B47CD5CE9ULL, 0xDE529FF3A1F376DFULL, 0xBE8D85BB1BC24C4AULL, 
            0x1A9217C3EE3EC338ULL, 0x595692767A445075ULL, 0xBFF42A17DC8E7197ULL, 0x14B576186E9D0684ULL, 
            0xCE15E85BC86EBECAULL, 0xFF1D7BB989B20690ULL, 0xE94D47E336D3027AULL, 0x29B210A1AC563301ULL
        },
        {
            0xB34AF98C193C767BULL, 0x94C506116B2320EBULL, 0xCBF954BD5F36CCF3ULL, 0x5A375D1944107358ULL, 
            0x6B6B4578F799E558ULL, 0x5094C92E31FC7492ULL, 0x07822298AF192550ULL, 0x401B4F94A5E10309ULL, 
            0x0F02AA1729D5D8A9ULL, 0xCCFF325C70DE26F5ULL, 0xB870A231A45CEB5EULL, 0xB18AEC1DA65E0AEDULL, 
            0xB7D1E1C8C1F14BC3ULL, 0x45468E0B21956353ULL, 0xF2CBB35BAB183585ULL, 0x64399821FAD0D942ULL, 
            0xBD648ABEDB7D0D61ULL, 0x184CE7C200D1804EULL, 0x7D1B7EFC1E809601ULL, 0x58E4B4670E029E60ULL, 
            0xACE96B9E4E42293EULL, 0x2E4CA81DD59F0DD4ULL, 0xBE74A3E0C093EAA0ULL, 0x9BF7E620AD8E8A5CULL, 
            0xE32467B7E4EC61E2ULL, 0xA5AC88437D74E7B6ULL, 0xFFC8B98B1FCD5694ULL, 0x6AEE2A692E1DF177ULL, 
            0x5412C0463BC4286FULL, 0x0EC9C7C412870895ULL, 0x022F741430173129ULL, 0x37FD1C52DFA7778CULL
        },
        {
            0x1A6017575B28FE9CULL, 0x57A2350182102540ULL, 0x38D4F96588CC9BB8ULL, 0x0F648190659854E7ULL, 
            0x74E6D35F86680C2DULL, 0xE416EFCDE755AA47ULL, 0x320175AFFE57ED82ULL, 0xBAE89C397774826BULL, 
            0x7F6D9429E411F506ULL, 0xF9F27E385241E073ULL, 0x75B6FA7006B3A049ULL, 0xFE090BD1075A26E7ULL, 
            0xA6D90DE941ADB561ULL, 0x82206BFE55C5B72BULL, 0xFDCC54F4925120D1ULL, 0x69A8E8E18A2D0114ULL, 
            0x225F24F9636D43E2ULL, 0x1625D0054FEDD809ULL, 0x0022E71415E1B4F8ULL, 0x03B5A99550A7E563ULL, 
            0xE4CDEB67F2FBED1CULL, 0x80CA96687AA01DF2ULL, 0xA0FFCACA145279C3ULL, 0xCB563EC440AB82C4ULL, 
            0xDC5C6A8D720EC36DULL, 0xFC2E017F06C8CB02ULL, 0xE92BD3B608521F2AULL, 0xBBB7BAE1D5F9E7E7ULL, 
            0xF19852F6CF096518ULL, 0x533545A04A6DFE3EULL, 0x3E092F71AB8EF393ULL, 0x825190B14E98C9DCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseFConstants = {
    0x0DEC1B5790AE512FULL,
    0xA14A883938C2E596ULL,
    0xCA0CC5B738FA8AE9ULL,
    0x0DEC1B5790AE512FULL,
    0xA14A883938C2E596ULL,
    0xCA0CC5B738FA8AE9ULL,
    0xD17BF22923B0CC47ULL,
    0x9D8AA73321F60F71ULL,
    0x61,
    0x9E,
    0xD2,
    0x9D,
    0x53,
    0xC9,
    0x6F,
    0x86
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseGSalts = {
    {
        {
            0x791771ED600E85D7ULL, 0x9AC49BEAD642201BULL, 0x0D6D185133CAFEC6ULL, 0x2AA18D432699A1ABULL, 
            0xD325B51BC6F520A3ULL, 0x3630F5855A55D32FULL, 0xE4430FA97E3EAC4DULL, 0x51D285AD2AFDBADEULL, 
            0x6DA0E378E1E965D1ULL, 0xCC6C9C4CD8818334ULL, 0x895C346F02255813ULL, 0x8BF8FA5DAAA2D06FULL, 
            0xEFB9D67E98A9638AULL, 0x34698D79E20CBF20ULL, 0x11399D4FC9B6C22FULL, 0x0E5DDCAFF627123DULL, 
            0xA70B43919C3ECBCBULL, 0xC89528D985DEE8E1ULL, 0x6A93A7F4BAAFEDDBULL, 0x90778447BA3D840BULL, 
            0x75CA6B0A781F3A5DULL, 0x109978316D2D336EULL, 0x7373FD054C6ACC64ULL, 0x0C8254F9D9AB36AFULL, 
            0xEEE43607FBB8197DULL, 0xB0763FBF1D2AB988ULL, 0x9DF1978178751BA5ULL, 0x0FCEC3C5D6B795ABULL, 
            0x95473681092DDA76ULL, 0x1DE9765B9F4C05A5ULL, 0x837A12812AC95057ULL, 0x701D4E754592DE22ULL
        },
        {
            0x7B8E141CAAF2D056ULL, 0x000081FB7F403860ULL, 0x95033E8D86190D93ULL, 0x4E7EC8BFA438F566ULL, 
            0x6179961F8B05D0DEULL, 0x2CEA063580FE2719ULL, 0xB51BA38A0BE2485EULL, 0x0F083D4DD27E85FCULL, 
            0x1008A973CDC09492ULL, 0xE038CAFD925EB1B9ULL, 0x4998F281AD606DC4ULL, 0xFA1EE0C320B51C98ULL, 
            0x46E0E28E157314DFULL, 0xC104D5CE1E49560FULL, 0x78E7875F106E6D21ULL, 0xA667FC100EA607F8ULL, 
            0x2436CEA8D1F38F85ULL, 0xA9A0DD6C244B5A46ULL, 0x0F9B667CE3C2F16DULL, 0x7422FE11E3DC8BB0ULL, 
            0x0AD776EBF2B1B6ECULL, 0xF22A9EB240653DE9ULL, 0x3721E0289016DC4DULL, 0x068D8BB2DBB38882ULL, 
            0xDE2D0D0D190C8FB1ULL, 0xECA2D7823E61FA82ULL, 0xABD982CDF9FE5A35ULL, 0x5C98854125CD9F4BULL, 
            0x3C44DF94267F144CULL, 0xFBB025F3E26D51C1ULL, 0x109F37604B9645ECULL, 0xFEC50E76D0BFB7BFULL
        },
        {
            0x6CA94ABFEF8E142FULL, 0x3D55217721235CE4ULL, 0x99585E774FC8DDBFULL, 0x0FD8BB4E63611F67ULL, 
            0xD9081717FCC0E29AULL, 0x6BD63A21DBB7C34EULL, 0x293B7043D1B3C000ULL, 0xBD4F49B7A1E745F4ULL, 
            0xF0DEC0970AA796D8ULL, 0xF9E9CD6E6A079C59ULL, 0x93C253531A1BE391ULL, 0x7B92649748BE6532ULL, 
            0x3DB5D992ED1FC0CCULL, 0x45BAA1F3B38FB870ULL, 0x908897A4A932E863ULL, 0x39C0D42820D0638FULL, 
            0xC8DE16F8E083D81AULL, 0x7B554CCF96057273ULL, 0x935F3396B42CC823ULL, 0x415D82F262C0B440ULL, 
            0x2A83A8F1658D1806ULL, 0x3333847B5570CE42ULL, 0x492C0BA7F2FE4FFCULL, 0xCAA6B53FB4398EB1ULL, 
            0x01C1EBC72A6CB16DULL, 0xA5EE8F89E44755CDULL, 0x29B00B9D1684078AULL, 0xE262AF0C44FA9CC9ULL, 
            0x5A11A53FF1D9BCF9ULL, 0x795C8A6A7942314BULL, 0x366A083FC3A197C3ULL, 0x0E8954771C5EC67CULL
        },
        {
            0x37D1CBE6180343E1ULL, 0x8E5897F6E966DBEBULL, 0x2E24196BFD2D1001ULL, 0xA10C154B8359271CULL, 
            0x8EAD81780F3626CAULL, 0xC3AA011D4CC731AAULL, 0xC11BD545D2759CCDULL, 0xEF4916EE8E5C88FBULL, 
            0xCF17D27BC3959A39ULL, 0xEA9E1D071B5901B4ULL, 0x2A0205FB16F304C3ULL, 0x13EB1EF0410E61EEULL, 
            0x54FDCD9A25A2DFDAULL, 0x7168ECFC05056A6DULL, 0x053BBD446733D9D8ULL, 0x880ED5A407091431ULL, 
            0xF3E75DFF30834468ULL, 0xD95A7C2CD276BECCULL, 0x67D97341E2925F52ULL, 0xD196A917A1DD3DECULL, 
            0x017995D07768F234ULL, 0x8A865CE883129587ULL, 0xA68BDCC67D2DA040ULL, 0x6AFA5441555A55C0ULL, 
            0x03A5836E8FA075E5ULL, 0x7FA6A949F84D560BULL, 0xE436377B1FFA7442ULL, 0xF91E246FB4B1F9F1ULL, 
            0x1C1BF1C18D34DE02ULL, 0x1DED082EF3A9F703ULL, 0xE2E9A215CE203DB2ULL, 0x6F19E099F08BC23DULL
        },
        {
            0xC6077574AA6A707DULL, 0x3BC48EF844780530ULL, 0xA7E4788DECCDE9FCULL, 0x1B275A6B25862970ULL, 
            0xBE927BA07B254BD6ULL, 0xB696078676891028ULL, 0x3C4DBD8A37CFF016ULL, 0x9B04B238A619FAEAULL, 
            0xBB77E41C90ECA3CBULL, 0x67451BEBB41E8BA4ULL, 0x1F7CC20D3E3CA725ULL, 0xCDA71E1BB178ACF0ULL, 
            0xE2495F505024E463ULL, 0xBCA1D694ED30B35BULL, 0xC7BFBA2F6ED48AF9ULL, 0xF09E956C585E4A54ULL, 
            0xDB9B67518992F4BEULL, 0xC32803C8A2D83361ULL, 0x2BB088DD963DD84DULL, 0xA93FA3EEB9F11006ULL, 
            0x554D51049143B907ULL, 0x707F7FF3223A35A9ULL, 0x6AE6D772A05DCBB6ULL, 0xD3935DA8F48AA371ULL, 
            0x8E7A2568318D05A8ULL, 0x62A423C1FEBA8BE2ULL, 0x3B9F4FD13D009EB1ULL, 0x969EA4AFEE97CE0EULL, 
            0x95A08460133660CFULL, 0x5215A29C150BB106ULL, 0xC6E1F0E3132781ADULL, 0xA225659033354129ULL
        },
        {
            0x61064ED4FC86A39DULL, 0xCCE53217E3F58081ULL, 0x27DADDF15B63BE62ULL, 0x6111874D475C2B61ULL, 
            0x8751B959ADA1A214ULL, 0xBBD43131D0F6C19DULL, 0x6AB2BB12A5175967ULL, 0x33F99303BC68BE4DULL, 
            0xF07F17EF5ACE9BBEULL, 0xD506A9BCDBB5EF9EULL, 0xDAC765396DB0B6BCULL, 0x836F2AB5C963F88EULL, 
            0xF1B6B844280904F8ULL, 0x626D2DD6A6AB019BULL, 0x595BF861B7D79588ULL, 0xC1D8B2883E7DD819ULL, 
            0x6E4E6F00FE061D9BULL, 0x43619E3AFD2094D5ULL, 0x50754790825651E4ULL, 0x1DEF590B2C9D9856ULL, 
            0xE64D2567233A036DULL, 0x396A5A6AFD33A47EULL, 0xBB726B025A014D34ULL, 0x30C2529DDEBB5B06ULL, 
            0xFA08239D1290EAD7ULL, 0x1C6A9E8F855A6B0EULL, 0xDC62C92CB1022E13ULL, 0xBA75E295C118043BULL, 
            0xF8974C5BE42EAAA7ULL, 0xA9CB093D0853FEECULL, 0x08365C52F04BD75EULL, 0xBC1CB8F0E28B4F5BULL
        }
    },
    {
        {
            0x3E17F153BC083B4BULL, 0x94C0234499663DAFULL, 0x7EA29CB225453D49ULL, 0xD3185B2015F6B69DULL, 
            0x308148786CC1226BULL, 0xE89E3A3B30737DF3ULL, 0xF7422C0E77C18F71ULL, 0xD71425698C1A5558ULL, 
            0x66CAF95BA99342F6ULL, 0x12694D3C1C665487ULL, 0xAEA9470B212E074AULL, 0x12A29E202C005A63ULL, 
            0x3711CC55A2C0E9E6ULL, 0xFD93689B724416B5ULL, 0x531BF97B8ABCED5FULL, 0x79B01FA7745B28DEULL, 
            0xAE9070BB4058589DULL, 0x0727CCA9ECDDA7CBULL, 0x3B1BFDD61648808AULL, 0x37CE95A5B6473AFDULL, 
            0x94AA1D9638F8C61DULL, 0x6968640C9C3C01FFULL, 0x9D907B75147F87FEULL, 0xFB277B58FA749F27ULL, 
            0x838C2F28835A03ABULL, 0x3DEB099CCA8F5877ULL, 0x217A91AF928E5CDEULL, 0xB16417B062D6A6EFULL, 
            0xA723A5D5D1C7F896ULL, 0xD3F7F499FF249B31ULL, 0x5BB552358A2E8E02ULL, 0xE4EA9A3ECDACDCEEULL
        },
        {
            0x43A43BA9CEE65C9EULL, 0x9FFE2B03432D617FULL, 0xEF9304530D6A4EE4ULL, 0xCCEA12A5322BE65EULL, 
            0x5B091D344EC82E0DULL, 0x3A9182411562E088ULL, 0x5D9066653D74558CULL, 0xA7864CDD1292F72FULL, 
            0xCC07E67BE7876FACULL, 0x1E11E7FA4F3A1718ULL, 0xB6431E7A8776A4F5ULL, 0x65DF5E54FA672C4FULL, 
            0x35CD87BBE771C7B4ULL, 0x2B1039922D7BEDEFULL, 0xFC84D09508E7F61CULL, 0x853B03AA46471044ULL, 
            0xB4B897C22F68E096ULL, 0x0EF51CB259724E2FULL, 0xAD68B739AC554725ULL, 0x9A48D887231149FAULL, 
            0x4186265C257ACE70ULL, 0xF3C0B44210FABAA6ULL, 0x734DDD29BD946EB6ULL, 0x8D8A9B39D9FA48ABULL, 
            0xE1C865D1669ADB1BULL, 0xBA82211C316EA7E9ULL, 0x61F3D374963FFC2FULL, 0x9B478E2B0738C51DULL, 
            0x43A5F799192530C1ULL, 0xCFF516AC81300927ULL, 0x3919DADECD60EFA6ULL, 0x414254323158A907ULL
        },
        {
            0x06C954692A72236EULL, 0x3E8653A42237EC0CULL, 0xF62E77029D145BBDULL, 0xA4C80C004CD4F766ULL, 
            0x0CC7638CC70328C5ULL, 0x81A62E7D0E2C313BULL, 0x2D73AED49546D161ULL, 0xCB452DC5482BCC63ULL, 
            0xB33F2F4828C4115DULL, 0x09059D179FA6CA2DULL, 0xA8BB1BB8DA62FE8BULL, 0xBCD6C3432D77154AULL, 
            0xDDB48AED407474DCULL, 0x5183AD7AF5CE1203ULL, 0x248560CC25A0CEA4ULL, 0x90813421C42B210BULL, 
            0xBDF7A02D22DBA00FULL, 0xA057471CEE458B0FULL, 0xB4722D083B2120FAULL, 0xCB0946CBAE5AAA07ULL, 
            0xC3030BAE3475A58AULL, 0x3825297F4028D573ULL, 0xCC50C5FEE8E7D9CCULL, 0x085B77D2E198CC5DULL, 
            0x3A50E30F6F3B7EBAULL, 0xC8D8002426961DFDULL, 0x29D6C80A7027CC29ULL, 0x81B6B1C3A6F6FF18ULL, 
            0xEC41B7CF399DE4DFULL, 0x64B887ABE82C619AULL, 0x70FA7FB64D2EE7E9ULL, 0xFBAB2C574C047BB4ULL
        },
        {
            0x44400D64E00BD4E5ULL, 0xF0B57CA8028B8F9AULL, 0xA088D37F6FE20AEEULL, 0x2EB242F8B6D29317ULL, 
            0xAC4C88978A5581A8ULL, 0x79DB4826C5DCA594ULL, 0xB85EABEDC85E97E2ULL, 0x19133EDE05DE12ABULL, 
            0x9FD9DC26ABFB962CULL, 0x7D6503F53DC6C907ULL, 0x8720DE10803F93FFULL, 0x4DF6A09C568D576AULL, 
            0x04E0B9F8CF30671BULL, 0xD0EF3E97D00239A3ULL, 0x14DA8F94F3C60305ULL, 0x13EB33C68C17B9BDULL, 
            0x69FDEC5FE894938AULL, 0x1C847DEB993DBAB2ULL, 0x632FB165581EF345ULL, 0xB8C56FEE76FCC20CULL, 
            0xE54D795B307B7C11ULL, 0xBA11E071A1FEF44FULL, 0x5CBAB809B6819648ULL, 0x164C95A720A4D01DULL, 
            0x4E26701F900D2FEFULL, 0x1420679BF89B04F8ULL, 0x1B24DC82B48C6B0CULL, 0x3972847DDF8ADF2BULL, 
            0x66877878F6620A28ULL, 0x4D92EBFB5960F11AULL, 0xF18517B7B8679338ULL, 0x1EECFF67BDB7ADD6ULL
        },
        {
            0xAB4B8EAB4EABA921ULL, 0xAB5BC891E119DA53ULL, 0x4467B673A7B931AFULL, 0xB11E533A83FC34EFULL, 
            0x599F0ED2AB977442ULL, 0xC2341EDEE75DB069ULL, 0x638600823602CC96ULL, 0xBF7540668CE92204ULL, 
            0xBE8EA3C07E800BC8ULL, 0x9585C6A7ABACBF02ULL, 0x3D165F552AC46D7DULL, 0x9F276C77713EB2B1ULL, 
            0x7A82AEF329F92F22ULL, 0x0B0DC2F715874A57ULL, 0x60B2AC41F7E3EA1AULL, 0xFB464EFE975BA030ULL, 
            0x206A18E9E3043293ULL, 0xC896DA4AD25E5C1BULL, 0xCFF45DE251640E3BULL, 0xFEBD265CC8AD9971ULL, 
            0xB120C6EA3553A32CULL, 0x548275E4BACADE0FULL, 0xA05024B72AB86BFFULL, 0xB9CE73523F6B820CULL, 
            0xFC63606F9BBADC5CULL, 0x37C506562F1CBA1AULL, 0x3350326942A9F0C0ULL, 0x8736D62319F9D16CULL, 
            0xF3A0ECDF6EE9C92DULL, 0xF364B0896880243EULL, 0x44BFD4EBA7E6BDD9ULL, 0xC4D4526E03A909C1ULL
        },
        {
            0x7891577CB51B8D7AULL, 0xD9381FA8BD3C3393ULL, 0x0244B12AA58BC4CCULL, 0x8D1F28A520631255ULL, 
            0x4A4F1C6229596369ULL, 0x410B1871E2A4495AULL, 0x07745F81E6C1E85BULL, 0xEE7761DC8F605B7FULL, 
            0x6BBD66386EB0BE7CULL, 0xA7ADF15596BCC0F3ULL, 0x05A0DEE5F36B4F1DULL, 0xF1E53BB1C9B02841ULL, 
            0xE3C1FF447CD95936ULL, 0x9A3907ACFB676FBDULL, 0x6FC41D414EDB4249ULL, 0xF39291381C4DF666ULL, 
            0xCDB555A868F0161DULL, 0x9BB1FB390B359C92ULL, 0x561D7D1E2FDEF389ULL, 0x5AEF9D0BDED85505ULL, 
            0xDC4A638A279AAFD2ULL, 0xF2B6EAB37901984CULL, 0xCDEB62D5C57F179DULL, 0xD73962479C317F85ULL, 
            0x75906E7216DDBBE5ULL, 0x6342B185DEBA2E9FULL, 0x6AA1B1DB2A71DA14ULL, 0xD0E02B7DC6427BC2ULL, 
            0x8B0BA99715C30EF1ULL, 0x38DCE8145400AA63ULL, 0xA5C885B22C95CAE5ULL, 0xA6682FB55069BFA6ULL
        }
    },
    {
        {
            0xF876816DBDE7066DULL, 0x909B7F51C92F69E4ULL, 0xC8AF12C18D50F61EULL, 0x7159BE44300AEE42ULL, 
            0x7AA8D19BD82FE5A3ULL, 0x536BFB84CD24DA39ULL, 0x66833E25293E1D27ULL, 0x8C4D07A4D53FAE26ULL, 
            0x45EACD9CF1C425F4ULL, 0x2AEF26631DFB3D5AULL, 0x3353D6DBEF1B1B2BULL, 0x011F5106F07D5F1FULL, 
            0x4160E905AC9D54F0ULL, 0xCABA8E33E9AF145DULL, 0x375E822AC9D5AC0BULL, 0xC402F86B0001643EULL, 
            0xBED71ACD51F6EF31ULL, 0x6338F8ECDA28D2CEULL, 0x768CD14F2B5C2C4EULL, 0x623891511624BEAAULL, 
            0x2D42F717A83663E4ULL, 0x2A6EEC9855E05BC9ULL, 0xAA960EAA9DC83705ULL, 0x3A2C649B1C920777ULL, 
            0xDD2A7E0D968EB720ULL, 0xC20082410A9F0898ULL, 0xBE469D40F1BFA6A2ULL, 0x45CDB7BFF9DC0DBCULL, 
            0x864A5C92F29B807AULL, 0xD55DB8D69F0DF769ULL, 0xC3D47A158C717C98ULL, 0x51DA0FD2C2FE477FULL
        },
        {
            0xF6BE2B2955A82F9BULL, 0xC50817B720FFF3BFULL, 0xA46E12C781403674ULL, 0x18DE550AB97E9518ULL, 
            0xE54431D6F811E78BULL, 0x08829CC75A108BEFULL, 0xCC266D5B2D285D5BULL, 0x3230C765D25D85EEULL, 
            0xC0603D31A9BA527FULL, 0xC78448ECD0665C9EULL, 0x2B08461598CCD04CULL, 0xAE905D05AA26493DULL, 
            0x256B08ACC2122176ULL, 0xD64BECF5CE2EC4F4ULL, 0xBCF83F7F61E1AADFULL, 0x0BC45B3D5FB809CDULL, 
            0xED8CEB1E15B14558ULL, 0xC01C9A42E380DB7FULL, 0x186CC8BC879766FBULL, 0x644FF52F58CACA52ULL, 
            0x19F2A1560B9A5FE9ULL, 0xE562AA21AC1E36C3ULL, 0xCA9E60294142853EULL, 0x71602B279CB4C5B0ULL, 
            0x9D9889A0C5E80C05ULL, 0xFFFA851D5F6F6A52ULL, 0x10C712C338CA34D4ULL, 0xA0FAAA6604DCAA08ULL, 
            0xE67C7B874372224DULL, 0x510AB2FB015FC23BULL, 0x5B3E2868DAF6868DULL, 0xBDF367CFDC21AC5DULL
        },
        {
            0xC8DBFF13A8CBDB76ULL, 0xBD73B31AD82AB7ADULL, 0x85AB7860B1C3B1ABULL, 0x299876CACCDDBCF9ULL, 
            0x5495151794AEDC7FULL, 0xA85811EFA6CFD9B3ULL, 0x5E312ED1914EDC04ULL, 0x1A4638655617EC0BULL, 
            0xE14437C71198CC11ULL, 0x6273C9C90B507C22ULL, 0xC1D338424E13C2D4ULL, 0x6AD6C249481FC8E0ULL, 
            0xDF78EAE1E4771A78ULL, 0x7FCBE4511235EF2BULL, 0x32B5FF1923EA5CC9ULL, 0xBD64AA204D9E4288ULL, 
            0xBEFAD11FF4766AA6ULL, 0xB026B58D7C1176EFULL, 0x92FEC531C864E5CFULL, 0xA8DC8F62D018766EULL, 
            0xF57AE4E9C9343515ULL, 0x6D9DC01439ADB800ULL, 0xAAC177B2CC9F72FDULL, 0xD1EF388E6026E322ULL, 
            0x4FAA714A3FA2BBC4ULL, 0x23DEDE895F43D3CEULL, 0x19F8026110657BBEULL, 0xA71142B0B9B9E1CBULL, 
            0x7D6C64346F6D66B3ULL, 0x49DC98A3FC77EFC2ULL, 0xBC35E46DC66764C2ULL, 0xCD455EFA164E1503ULL
        },
        {
            0x39C8BA88876C55B6ULL, 0xC31660C8C7A611B5ULL, 0x55C6F532216372F6ULL, 0xE7771272FE2A0FDAULL, 
            0x2596A651009527FBULL, 0x6A077C7F827EFEE5ULL, 0xC076F9F966731124ULL, 0x0EBD091597691A18ULL, 
            0x66A75FC17A5C5C36ULL, 0xAF3361BA4A8213B5ULL, 0x26213DED7354DF72ULL, 0x0ABE8A0BE105FF60ULL, 
            0x703993FC249F1FAFULL, 0xFBE0040C3E59B7B6ULL, 0x2CC960AF88CFB1B3ULL, 0xCD4D36312141076CULL, 
            0x4947C44A2765BEA1ULL, 0x8503C6A294D7C15BULL, 0x0E449190ACC952EFULL, 0x3E341C67BBAA22D5ULL, 
            0x9E92B30C9A4363B4ULL, 0x29C8D4B563A630B5ULL, 0xB82618A8A83253D9ULL, 0xE33311B5660B8258ULL, 
            0x6C1A381F5DD57846ULL, 0xD02B3C8AA07EAC99ULL, 0x07D4D34543DC3E78ULL, 0x8B3EBA6015F65BD3ULL, 
            0x7E6516BB8EB98641ULL, 0x4906D799BFF475CFULL, 0xEE94A518C52FA0FBULL, 0x4638A6B0D0408CCDULL
        },
        {
            0x07ECFE60AB17CEDBULL, 0x4A60B69C788E2334ULL, 0xDFCDF0474154087AULL, 0x7758DDA07A99AE66ULL, 
            0x322F7562E2342645ULL, 0xCAC5E7BECFA6F4A4ULL, 0xFB03D328BE97D1A7ULL, 0xFA22F2606B37EC06ULL, 
            0x3EE03465A5433204ULL, 0x12F6E6D6B8F70F4FULL, 0x931E97A983153396ULL, 0xDA8E49D85E5597E4ULL, 
            0xD55282224B5DDEBAULL, 0xDC804AA97F105A9CULL, 0x70ECEF5E2182279EULL, 0x7797FB3A0D814BE4ULL, 
            0xB8D6102B9AF9A548ULL, 0x88752AC7CE777888ULL, 0x74F961FCD06CB506ULL, 0x18C21B1768C5BA8EULL, 
            0x91E2BA8C35F897E5ULL, 0x540678E78E85DE5CULL, 0x0EB228B95E7EEF58ULL, 0xA6EDFF053B98874EULL, 
            0x89F2075CB733E77BULL, 0x053C2F46C15C1E95ULL, 0x083AF8D6C2BD1695ULL, 0x51967C04543D9422ULL, 
            0xAE6DD705C1F5999CULL, 0x6B7B4B47266DBA96ULL, 0xBA2EA9CE0BF65083ULL, 0x8EF43FD03196D7B1ULL
        },
        {
            0x7BE88388C036F0FCULL, 0x196431EEAC9816CDULL, 0x411CDF09662B21ADULL, 0xB26A4B3AE4E9FB5EULL, 
            0xF6CF588A2E04B61EULL, 0xCDE14918F113A17BULL, 0x38C8E3522C9F4B20ULL, 0xD9530B98702E3856ULL, 
            0x5D628B3B60E4BD42ULL, 0xCD80E0552D16D822ULL, 0xB00C7BBAFB8252C3ULL, 0x2D21F24A51CDCC33ULL, 
            0x0CAF9F5FDE3ACCDFULL, 0x62E7C9073AAA3137ULL, 0x93AF15D1DF699864ULL, 0x0A3E8419D11AB9D1ULL, 
            0x36558E7C357A192DULL, 0x5AEFE06E8BDA7A70ULL, 0x253804A00B427D67ULL, 0xA1F2660601D0E400ULL, 
            0x3471D1FF989FDCD6ULL, 0x13FAED3A55B09A83ULL, 0xBF5C44DBC7D30446ULL, 0x5DA055E2BF7974C8ULL, 
            0x9949E2970A19BB73ULL, 0x4FA8222047E87349ULL, 0x1F76E62E5BB1A6E6ULL, 0x832FF9FF0D6DD718ULL, 
            0xBB7DF0A221DD1650ULL, 0x6C353D4140ADDEB4ULL, 0x2B0953F783A1C483ULL, 0xDA9C194360750006ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseGConstants = {
    0x902C5C71993BDE96ULL,
    0x6B878154BAACD22DULL,
    0xB9627BD8C2036A02ULL,
    0x902C5C71993BDE96ULL,
    0x6B878154BAACD22DULL,
    0xB9627BD8C2036A02ULL,
    0x387C33FC0F0AC6DBULL,
    0xE27B8DE75FDF30C3ULL,
    0xB1,
    0xF9,
    0xE7,
    0x07,
    0xA3,
    0x36,
    0x94,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseHSalts = {
    {
        {
            0x0A825CE2042155A0ULL, 0xCB42B9C77F907FAAULL, 0x6A8148074E1CA3BAULL, 0x15E3F293162E375AULL, 
            0xF45FDDEE9DCCB5B2ULL, 0x1FB28A3B6CBFD98CULL, 0x40679632B964573EULL, 0xFD51FDAB127DBF16ULL, 
            0x59D2FB3F724FE04BULL, 0x339AE5A66980782BULL, 0xEFF672C95EA65206ULL, 0x5EC68D3C0F0A94BDULL, 
            0x2AB04E71AA6AF3C3ULL, 0xC0AADFF12A6B0C57ULL, 0x0799FD17B2F596E4ULL, 0x0954EB190BDDAF29ULL, 
            0xAE72880A9AEFAB48ULL, 0xDBB360258E9F1C86ULL, 0x6DF24641F0517652ULL, 0x0FAFBE2199EEF9BAULL, 
            0x627E60E6DCEFE1B8ULL, 0xE6E47AC9AB003302ULL, 0x5146EFD7666AE9E0ULL, 0x590DA2897E493355ULL, 
            0x27CFAD77F975D176ULL, 0xB18C0E3B3B5031B3ULL, 0x8DFBF534F225B87FULL, 0xC9A335DF340811C5ULL, 
            0xE74B134FF1747F6AULL, 0xC22AE63D9418CEDBULL, 0x5B12D93484DB7F2EULL, 0x81A54A863EF84A09ULL
        },
        {
            0xBB5E1AED2D7AF865ULL, 0xD9724B6D4B028396ULL, 0x0CB0633DE3A1290EULL, 0x8A33A6CD29A17D90ULL, 
            0xDB6D2414E695403CULL, 0x7E58BE02B75C6BCFULL, 0x9846FA0EB52FCDD8ULL, 0x50A2BCD8CEC092C8ULL, 
            0x4DA56AFB0E110C93ULL, 0xC5877561990677A0ULL, 0xA55FABE807CEFE06ULL, 0xA73AF5DF65B491AFULL, 
            0x75900F874D474574ULL, 0x9AB3E06F6D73BB2AULL, 0xB64E517B7F03E11AULL, 0xF7D1F4E9114EA035ULL, 
            0xEB22CB5E0ACD3651ULL, 0x003DE689ABC15DEAULL, 0xD18E17A66FCC3251ULL, 0x213FCF32D4E76BE8ULL, 
            0x0318788492E9BEFCULL, 0x151238A30E94D385ULL, 0x04C1B643C4221A56ULL, 0x5C22BC60B2E57676ULL, 
            0x04F6EDEDFBCAD2DEULL, 0x3BA0CE47F950CFCEULL, 0x121DDE8811F6B3AEULL, 0x421AACD6DB8209BBULL, 
            0xBAC0438612642341ULL, 0xB1B792FE9D7EE711ULL, 0x71A04A1A7BD5ECF4ULL, 0x8B8C486C9D7A4FA7ULL
        },
        {
            0x6ABB89AB9D7D2329ULL, 0xB436146895A26046ULL, 0x06DDC0EAE8CAC4FFULL, 0x7A9ECA272B3D45B8ULL, 
            0x8F8B655A649B4850ULL, 0xAF9A77EE90D9D8FBULL, 0x9117ECDD4C5CD48BULL, 0xC90216DFCF954039ULL, 
            0x08D2D4DE960C9A3AULL, 0x35EFC08FE2BD6A0FULL, 0xD5A6433057F2944AULL, 0x37296A5F5E0CC5E7ULL, 
            0x2A9D154A955192FCULL, 0xE5C3EED564BF6366ULL, 0x9B23828FA6E2A25CULL, 0x5F19E367B0BD2F16ULL, 
            0xD7679F610C1E44DCULL, 0x1FFE1D27CBA3B10DULL, 0x94A4C293476C21A8ULL, 0x5B95540E989913F5ULL, 
            0xC9CBED6E3DAF8D26ULL, 0xAF7BA2E0E649EA01ULL, 0xF7EE6858B461F2FEULL, 0x194D129C54554655ULL, 
            0x3C03536742CB7784ULL, 0xFA2A7EB632318F0BULL, 0xA1058666DA30F0EAULL, 0xD0299C5F9334FBE7ULL, 
            0xDBFB080397007755ULL, 0x6233CF8782E95990ULL, 0x3F2ADB11315BDDEFULL, 0x3B1E668B960BC978ULL
        },
        {
            0x12B251A929C4C44EULL, 0x3D42C8677B1923F5ULL, 0xD1575ED7E46BF2F6ULL, 0x34D8A3C36693442DULL, 
            0xB709620326A2F31FULL, 0x05E44963C46751E9ULL, 0xC3A44ACE45CF4B93ULL, 0xD80B961B9A06B5C5ULL, 
            0xC19A8055D1670944ULL, 0x87ACE414C2620AC8ULL, 0x7EE1964C4560E3CDULL, 0x04DB02058F5EA31EULL, 
            0x69984C3C0E36C441ULL, 0x3CF94C0D07FEBA4FULL, 0xB3747E5FA1AB85E1ULL, 0x64E4699A34A5EA9FULL, 
            0x09E3302E742E9973ULL, 0xC4DC33261ED99994ULL, 0xCB656939C29B79D1ULL, 0xE6FB73E06B94DD81ULL, 
            0xE346BE7D5BEF2539ULL, 0x4F2DE146AF8046A7ULL, 0x6BEFDDA436E6960FULL, 0xEAF8F4C029C831A5ULL, 
            0xFDED1EB105FE5517ULL, 0xAC82326BDBC53C61ULL, 0x4754D8827EC822D3ULL, 0x96D2008BC30C31E0ULL, 
            0x97782EB08487CE8BULL, 0x7DB4104C53ADA7CEULL, 0xF4F6B8BEF13AF450ULL, 0x59964BD6470ACAA2ULL
        },
        {
            0xCE3A50F986DB8E98ULL, 0x8B5D0736AAC82736ULL, 0xABED5022599CC464ULL, 0xA7397855DC2ED57FULL, 
            0x8E7007E8B6C2F7E9ULL, 0xA8F57A44537EFCC6ULL, 0x1241FB43A92ACD3AULL, 0x7B744A2DDC8C92C1ULL, 
            0xB169BA088D014CFAULL, 0x27C934BA10A7DBDEULL, 0x7FBC4E7FA47A3FF2ULL, 0xE5D33974F1CD93EEULL, 
            0x0BA6F6C4C6C7EAC4ULL, 0x46109EADE27282F0ULL, 0xB23FE22B32D95404ULL, 0xE0AE64D938DC663BULL, 
            0xBD601F2E5BB8A10FULL, 0x522C86CD10053A87ULL, 0x03F628588C5F8005ULL, 0xC6AD28B301E55332ULL, 
            0x10E795654176FAF3ULL, 0xCD2B96B2B84124CFULL, 0xFEAEF90DC610D911ULL, 0x840478549A0D448BULL, 
            0xABE4B38F17035FADULL, 0x1D14B13A624CE510ULL, 0x44B1046C1131F7EAULL, 0x191CAACB6CEA1DEDULL, 
            0x24076D4926251456ULL, 0x5C79A0CDC288FAEDULL, 0x7BE429CAA426FA68ULL, 0xA89A89A8878FD1C6ULL
        },
        {
            0x8EA6B16B6E99583AULL, 0x904FC4AD2225B9D6ULL, 0xC63F2E80A0DB4B8FULL, 0xCD82148D4839D472ULL, 
            0x0985E022DACDC4CEULL, 0xEF818E704CB02C7CULL, 0xA8B635499EDFE0A4ULL, 0x3454F043FD54AB7CULL, 
            0x33334C29D1E0F8FFULL, 0xC4595C054CC49847ULL, 0x8B85C6DD863A0710ULL, 0xD5D0237C13CBF31FULL, 
            0x7AEC3AE6532C9409ULL, 0xEB3985308498E5A9ULL, 0x6670B7ED7A7D848EULL, 0xCD162065DDCDAF4FULL, 
            0x348E28ABD8CCF446ULL, 0x33C99B59EED19523ULL, 0x3C5AB8ACA50EC87AULL, 0x31B1DCFDDECC8836ULL, 
            0x716A9716B012390FULL, 0x2ACC9F3875EC427AULL, 0xC5A2D2E325DBCA9DULL, 0x190FFF8F42A31860ULL, 
            0x1DC48030633AF340ULL, 0xFAC4A2A8DA4B201DULL, 0x67467C9E8CA49417ULL, 0xCFB79E5B91D73C82ULL, 
            0xEEC5F0D4DF633F60ULL, 0x87F1969E1B9BF48FULL, 0x7B614AEA634E7EF2ULL, 0xF0CF18433E8937A5ULL
        }
    },
    {
        {
            0x8BE6B7C3CBFA4050ULL, 0x243C9149AFCCDFE2ULL, 0x0213BAC9A6B14DF5ULL, 0xB61B764C9A80057EULL, 
            0x365176B11746F334ULL, 0x219129F100D9D430ULL, 0x978F560197480528ULL, 0x6C8DA73FCD74C64EULL, 
            0x13BC166A57E0B49AULL, 0xD671B5F2CB5FD2FBULL, 0x9125A3673527C4A7ULL, 0x5FAE086C6736328DULL, 
            0x3D524EEDA915FB60ULL, 0x2B65A75BAB9FD490ULL, 0x1277406795AAE9F8ULL, 0x581D759846E9882BULL, 
            0x7F4446EBD2010832ULL, 0xA0229C1AD889067FULL, 0x510CA56C22473DC3ULL, 0x86503848114655DAULL, 
            0x4BE61DA07FC000CCULL, 0x00CFEFDB5BB92A91ULL, 0x382C60BFCC60D4A5ULL, 0x7D7DB9F22EB9FB01ULL, 
            0xBDF25FAED6D808A6ULL, 0xD8ED88B32735FFCBULL, 0x410297320C71A717ULL, 0x2812B98F6996321FULL, 
            0x7B7513842BBC99EDULL, 0xEC39FAEA8C5FC915ULL, 0x27B8928EE295C6F6ULL, 0x0C98B3862648A7CBULL
        },
        {
            0xEDACA8F86351C4C7ULL, 0xFF9451FF3DD4F4BFULL, 0x9DD8EE255DE3861AULL, 0x24089D115C1D1C51ULL, 
            0x87342BC06C60D544ULL, 0x746A5AC95E6BEC81ULL, 0xEAAE7D651623610CULL, 0xCEF1899EB2D1C2C1ULL, 
            0xCBF33BD8330DDE48ULL, 0x2EBA8F93927E4121ULL, 0xE073117F7C964662ULL, 0x3F435ECC6684F494ULL, 
            0x84BDEBC5077E8935ULL, 0x94BC945660DB32ADULL, 0xFECC49B4B9A80E02ULL, 0x7216F82EE49BFED3ULL, 
            0xB79023EB1F8FA165ULL, 0x6B7B34CE085C64BFULL, 0x53809710885890B0ULL, 0x023D09F84456CD28ULL, 
            0xF6E9B7F35F37105CULL, 0x995813DA0B9B1075ULL, 0x701DF6821142940DULL, 0x142E5A88B150ECDBULL, 
            0x192D8A7F2914FE3EULL, 0x4DDA6F2486A5936EULL, 0x8898A095E47F5967ULL, 0xD119133B77E33B5BULL, 
            0x0FBACD5B04B309F8ULL, 0xCAC96B517BA5D7F5ULL, 0x463AFC6F42B94853ULL, 0x544C13791AB4D7C6ULL
        },
        {
            0x8328A2CD964E4246ULL, 0x995E41658245E4EAULL, 0x21142E257C42E6BDULL, 0x6EFF8B1EFB5374E4ULL, 
            0xBEB15BA3FE18E10DULL, 0x0F92E81C9E4415E6ULL, 0xD960814AD2D872DFULL, 0x35684B9B5D8381DAULL, 
            0xE84245A15F5DE1BDULL, 0xE3D3A3B1C67423CBULL, 0x63805DFE734A1B5CULL, 0xE3F4617B2272C78DULL, 
            0xB79DB5E0D2E66B71ULL, 0x8A322BDFFE33AEF6ULL, 0x32065CEFE6EAEDDCULL, 0x30885BD1C7DD91AFULL, 
            0xDFEE3AAFCE06E615ULL, 0x68BC56B1DADF37B4ULL, 0x0C69490E2D10B49BULL, 0x2A2F8DFCF7E0DD15ULL, 
            0x5F5EACC18247FAB0ULL, 0xC191BE8B5F04C5AEULL, 0xB5E5219AF10D01D0ULL, 0xFE48B51D24125074ULL, 
            0xD5DFF56A4769B2BFULL, 0x91CF86D3F98C770DULL, 0xFD6251DE6DB20868ULL, 0xECE8021A33BC8987ULL, 
            0x76FA983915B332A2ULL, 0x7F45758E681CFFABULL, 0x4AB8E055AA041936ULL, 0x978197055927C2B4ULL
        },
        {
            0xF86A90E9FCF82752ULL, 0xD21B997F7439F96CULL, 0x67442397A7559CAAULL, 0xBD022863459D3844ULL, 
            0x37F316D4FBE8F4F1ULL, 0x5622438504E4C11AULL, 0x704E2572796A7B07ULL, 0x55DA01ADAC6BA879ULL, 
            0x8A45659D282F8276ULL, 0xD788703BEF70DBA6ULL, 0x1349281F597A8244ULL, 0x496A35EBDF46EEBCULL, 
            0xF54B9E9510AA6EA3ULL, 0xF169BD5C34337348ULL, 0x9FB17D1162BCA25CULL, 0x3F0B43CA0FBDF6E6ULL, 
            0x2625D44705E87151ULL, 0xAE98B49C3EBB06C8ULL, 0xA4634A262D23BFD8ULL, 0x523014470C0AB650ULL, 
            0x9C839FCD9B03737BULL, 0x7E74B0D04FF221E3ULL, 0xDD38C08445301036ULL, 0x24B5B2A335629189ULL, 
            0xA0895E2AAAD14A42ULL, 0xA0E59DCCBAACCC33ULL, 0xAAF18FB0C0BA2E1CULL, 0x7D9E8AF56AC58451ULL, 
            0x2A138B5777671626ULL, 0xE187DA9899797F0DULL, 0x6DFAB8636465F51CULL, 0xDCF78743B8FCE88CULL
        },
        {
            0x67A8D868A1A71CA7ULL, 0x591A5AF784A53085ULL, 0x9E51747804BEF441ULL, 0xB6B28FFBBF715E37ULL, 
            0x29CA8E785AF07F56ULL, 0x611A68ED10D730EEULL, 0x7493FC88CA2D6AF8ULL, 0x5CB3D987CDA05856ULL, 
            0x847DD8542DAECF5AULL, 0x172BF3145DD79B4AULL, 0xC40C9F78951A6AF5ULL, 0x95CC9811ACD4516FULL, 
            0xAEC8791BBD918428ULL, 0xBEE6FCEE61EB33E7ULL, 0x54D4166F9CFF8C2EULL, 0x33B21824E8C1F27FULL, 
            0x92052A9A146B311BULL, 0x79382660998D87F5ULL, 0xC4C9FF3D49CA14CCULL, 0x151656D8801AB119ULL, 
            0x2909E20F0B1B789DULL, 0x46F9C3F1C0C6E621ULL, 0x09058254F84E1D9EULL, 0xCC3C7C1B994B21EAULL, 
            0xEEB0F9F1C7916B0FULL, 0x3D99DFABA0661D3EULL, 0x41E3450A3B05D039ULL, 0xE093B839D6130394ULL, 
            0x1B80B7CBC6B3A607ULL, 0xFA1DFCEDCB70410CULL, 0xC8272A0576194834ULL, 0x8E46DEA08BB4C4D4ULL
        },
        {
            0x5E9F6EBDC55B75E2ULL, 0xC7CFFA03F731409DULL, 0x014D676799977A1BULL, 0x4B3BBECFDC854AE6ULL, 
            0x62D97B0D43FCD149ULL, 0x9718033180E4EFBAULL, 0x8E3FE93DCC9E1687ULL, 0x3CC1C6B8E14B55C6ULL, 
            0x90CC6E73CE60E522ULL, 0xB6001BFD347B757EULL, 0xD9A3CF4A10D377C3ULL, 0x308EA8216E398E14ULL, 
            0xDF23B0A7CB82C825ULL, 0x6619780027976DB5ULL, 0xDA221CE3B1ABEADEULL, 0xED9EE8CD14CE6C80ULL, 
            0xEE3848C60C7581BDULL, 0xB006E1D2C1D00CACULL, 0xD9502FA0254F0284ULL, 0xE311D38E0802A0B8ULL, 
            0x885FE3D8A61AAF82ULL, 0xB7DC6ACC3FCB1EEAULL, 0xEF4905F9DB3535E9ULL, 0xB5BA93EAFBAAB933ULL, 
            0xA64FDCDF66A834C1ULL, 0x7C579C39CC31D5BAULL, 0x105BBDF2B1EE701DULL, 0xB73562250140D374ULL, 
            0xBEB2DC31CE3F8BFEULL, 0x33663120B37167F0ULL, 0x7F8FD4B79FBD9BA8ULL, 0x8D20AF8C51D5E938ULL
        }
    },
    {
        {
            0x7BD89A4562E5CC72ULL, 0x326BDDA9D794F2B3ULL, 0x8300654B9009BABBULL, 0xA3EDBD41476970C5ULL, 
            0x409DB4B8EF0AC3F8ULL, 0xE5251C205C689463ULL, 0x43E003BA56D51E99ULL, 0xD28825378A8FC261ULL, 
            0x09FFC1F6FE1DA363ULL, 0x9F4A52E9FFD458AAULL, 0xACC2CA38402C1B97ULL, 0x1E15272CF07771D3ULL, 
            0xF4176517B9FDB3B2ULL, 0x0821C3F32B318420ULL, 0x21AD5BBB42ABD352ULL, 0x1A433AEC42E66BAAULL, 
            0x0C9E49045712DA74ULL, 0xF587643287F5B4B1ULL, 0xFE92EA03093CBA3DULL, 0xFC069F438D5D3C1BULL, 
            0x82ACF660A1995FF1ULL, 0x1B237BF45E0CBFF3ULL, 0x678D0FA82992484BULL, 0xF5038B86059BDCF5ULL, 
            0x285913451BBBB133ULL, 0xF57FE3E0BC4308F0ULL, 0x537491C2BDD33EDBULL, 0x6DF58969476E5675ULL, 
            0x69F23AD8D98A8385ULL, 0x476280026910DA5DULL, 0x5E5B4B8319414A56ULL, 0x0A7B5BE38A607291ULL
        },
        {
            0x4005780BBDC66692ULL, 0xF274DFA643694FADULL, 0x8CE727485EB2EEEEULL, 0x4830DF8237E558A0ULL, 
            0x033314C5E1CB2218ULL, 0x2E53B1BF9FA19146ULL, 0x4ABFB9EB698D8D39ULL, 0x1A378FD0EE912AF2ULL, 
            0xDF5CFFAD0A3CB89EULL, 0x8DD30708A803502EULL, 0x37C7C2B974102600ULL, 0x73F099E8448B2EF5ULL, 
            0x35C7ADFCCD28E5CCULL, 0xB4DC102993343431ULL, 0x177EAEF9B9267D0EULL, 0x10AD0D60E7EF7693ULL, 
            0x09DC55CA2BDB1BD9ULL, 0x1DDD5B4B3E5C95F4ULL, 0xB3EAADCFBA397752ULL, 0xC39F128445C35D43ULL, 
            0xB2465E03472107FAULL, 0xE9C1CEE7503BDF3BULL, 0x7440DE626C7518A8ULL, 0xB9FA50A40F042783ULL, 
            0xCB68916AC065F7F9ULL, 0xC178AB26591E22D3ULL, 0x52C6E3B38CD6887AULL, 0x3A7A094313D9CC9FULL, 
            0x2019A54DC6DDC9F4ULL, 0xA8A09448D145C7ACULL, 0x03032EDB29421423ULL, 0x8BFAC07095D4231EULL
        },
        {
            0xECB32224653D2FFFULL, 0x3B31CA823AF9993FULL, 0x7C14D3640BD430DEULL, 0xD9D130AC1FECFB93ULL, 
            0x421D1D6A27DE2D92ULL, 0x4CD9736A6019BE1EULL, 0x1E2193CDD29CB8FBULL, 0xC2D6BA0060354DF7ULL, 
            0x5187BADCE68FCE1DULL, 0x43182C1203B559D6ULL, 0xBCEBF101A9F78CC5ULL, 0x5539438D90ED33FFULL, 
            0x13455F13686DBFFFULL, 0x81DBFCF3C964812BULL, 0x805DB33B2903F8ABULL, 0x4C2F9847E19BA2CDULL, 
            0x31B82C7667459091ULL, 0xB3ABEF8691A6462EULL, 0x6E1CB2682F7A4BC5ULL, 0xC78F0357545B5E99ULL, 
            0x5782241B08E779E3ULL, 0x29D6489EAE6748A5ULL, 0x75C70C6057A08CAFULL, 0xCC07376C42884D5FULL, 
            0xDC0593EC85D37924ULL, 0xBC30D5E2613DE8AAULL, 0xD1FABEBCD14504D9ULL, 0x739166E2AECF9BB6ULL, 
            0x047412D1F84C1763ULL, 0x7BC36DBA42577932ULL, 0xF9A8B068B19B2487ULL, 0x85EE9E811FA4FB77ULL
        },
        {
            0x99F5E70536F588FFULL, 0x0F9600BCE40652A1ULL, 0xF9EC4B6C890EE114ULL, 0x75A707AE0A1AC7D0ULL, 
            0x746559B80E88486FULL, 0x895C094C1B83B4C1ULL, 0x27B0D273FB5C7CE0ULL, 0x0D9286189131E15AULL, 
            0x91C7495ABB45A30AULL, 0xCAF412A3086D54D3ULL, 0x204246DFBAD993CCULL, 0x296E334AD2D7C814ULL, 
            0x44E53FE0E872E25BULL, 0xC0FE4BE900736388ULL, 0x82BFFF068CE0E78FULL, 0x2FAB8E21A4B02FA7ULL, 
            0x7F8C071B7BC2E56FULL, 0x0C697AC06816155BULL, 0xDFA83234F461E167ULL, 0xCEFFE0B455DFD6D7ULL, 
            0x9F258DA27BCC2D2FULL, 0xED72BCB76D709A9BULL, 0x2C6DC9242B63C7E2ULL, 0xA1141DDA3070A945ULL, 
            0x2AA7C11342B6B0FBULL, 0x9E70FDC954C838B0ULL, 0x1787EEF858BC6559ULL, 0xBD6A9B0B475117C2ULL, 
            0x15A3C0513CF710B0ULL, 0xCC6BABF99265EB8DULL, 0xFD2F86E73EC59BBAULL, 0xA84187D6C8B0A48AULL
        },
        {
            0xB494ED78FB02A25EULL, 0x227DC9FD2AF5904DULL, 0xFBDF018E372796D6ULL, 0x54F1BC92E502F08EULL, 
            0xC137747157CEE443ULL, 0x2CEC9A41D063DFF9ULL, 0x49AA25770AD97B56ULL, 0x5BA76173628215A8ULL, 
            0x2ED27E0AB849FE6BULL, 0x8837EF943FDB5043ULL, 0x1A028DD05A046013ULL, 0x831ACFB347C44806ULL, 
            0x4277229B44A66176ULL, 0xC444416B1D579AA3ULL, 0x374E51956D5893EFULL, 0xE8757E4B9207F614ULL, 
            0x5E7BEC1562A0A9F6ULL, 0xCA1AA2884B6A710BULL, 0x1F5660ED3AC6DD2AULL, 0xEBF4D997007F4A7FULL, 
            0x2C66F0D6D1F938F0ULL, 0x47479FD7CEAB7E95ULL, 0xCC7DCA44E1B75ED6ULL, 0x419D4AD34258E496ULL, 
            0xD2B574D3616E1E6BULL, 0x23ABA6743A8B120AULL, 0x49655582B31B4B4FULL, 0x5403089893AC6465ULL, 
            0xFD62730CAE6DDE5AULL, 0xB88EFBC785C825F3ULL, 0x5D8F57447910AE06ULL, 0x15624CB95C7AD196ULL
        },
        {
            0x2EE9322A51A78CEDULL, 0xC07F23E6DCF5E871ULL, 0xC8FD7C73E094520DULL, 0xA68CA73270DA2F6AULL, 
            0xF20D1C724FDE9C8EULL, 0xC7C2DDE55BDAAD54ULL, 0x9ABDDAD22A722A6CULL, 0x0213FEBCE67B2CB2ULL, 
            0xF32F6EAC0F98B236ULL, 0x1BBB4CACC67B8D53ULL, 0xE944F4461D365DC8ULL, 0x516C1BC7E91E7CD4ULL, 
            0x527B5C49B5504CBFULL, 0x7935DC8534257191ULL, 0xE55AFF74F500E2F3ULL, 0xCEA6DC9C9A235507ULL, 
            0xB2E02ED288C3BBFEULL, 0xB73FA0FB28B70509ULL, 0x08EB98FE3F1DC656ULL, 0x2C1E5F19AE0FB038ULL, 
            0x1BA133F89099C793ULL, 0xC22A549D5322F0A7ULL, 0x1300AEC52DE89BE8ULL, 0x5E20594C9006DC44ULL, 
            0xE4457CAF028BC333ULL, 0x6BEEF8D5E03821D5ULL, 0xF38DE0DBB1701167ULL, 0xEEDBF4351E200D63ULL, 
            0x54D28ADCAF04190DULL, 0x767FDC95FBD78603ULL, 0x83E4FF0B7065B16EULL, 0xAAA31C90BF20E426ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseHConstants = {
    0xFA07288CED6D1119ULL,
    0x761FB55C9704DB85ULL,
    0x3A5AE0444C874486ULL,
    0xFA07288CED6D1119ULL,
    0x761FB55C9704DB85ULL,
    0x3A5AE0444C874486ULL,
    0xC570CE8317368BFAULL,
    0x809CE6548F5F1E9FULL,
    0x72,
    0xC8,
    0x94,
    0x35,
    0x3E,
    0xF0,
    0x7E,
    0x7E
};

