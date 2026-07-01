#include "TwistExpander_Karate.hpp"
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

TwistExpander_Karate::TwistExpander_Karate()
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

void TwistExpander_Karate::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xE1B94576C93E92D1ULL; std::uint64_t aIngress = 0xFECE96711DDE450EULL; std::uint64_t aCarry = 0xFF9F1F0BE95D0D8BULL;

    std::uint64_t aWandererA = 0xBD7154660373BE9CULL; std::uint64_t aWandererB = 0x87CF5F77601D1D26ULL; std::uint64_t aWandererC = 0xA2649C4B9C390EC6ULL; std::uint64_t aWandererD = 0xD7816479E899C77BULL;
    std::uint64_t aWandererE = 0xA7F7FD72FC18E4A7ULL; std::uint64_t aWandererF = 0xCFEA3C506A9D54D4ULL; std::uint64_t aWandererG = 0xE3AD132085F17632ULL; std::uint64_t aWandererH = 0xB9987B3243E1CEE7ULL;
    std::uint64_t aWandererI = 0xEB0A9BE9FC5993EFULL; std::uint64_t aWandererJ = 0xFF29CD585E786019ULL; std::uint64_t aWandererK = 0x84673611BC59FBA2ULL;

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
        aPrevious = 10060821718453343467U;
        aCarry = 11085138214737313800U;
        aWandererA = 10355972342641213650U;
        aWandererB = 13766785155392702103U;
        aWandererC = 13394641740130913316U;
        aWandererD = 14648785799961159694U;
        aWandererE = 12624890910035665761U;
        aWandererF = 18278073669934399902U;
        aWandererG = 12729857272684589706U;
        aWandererH = 12881614973588452366U;
        aWandererI = 9514544411446660948U;
        aWandererJ = 17465205750722731884U;
        aWandererK = 10622287780035420598U;
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
    TwistExpander_Karate_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Karate::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xE42FC8011063E492ULL; std::uint64_t aIngress = 0xF3337DB41A423018ULL; std::uint64_t aCarry = 0xA48BCDB9E5A29C79ULL;

    std::uint64_t aWandererA = 0x807F19CE2C83D636ULL; std::uint64_t aWandererB = 0xC450A6F61D6F7AFEULL; std::uint64_t aWandererC = 0xEB4906CB0353A4BEULL; std::uint64_t aWandererD = 0xBA150629CCEE7740ULL;
    std::uint64_t aWandererE = 0xA21E81B5D20EBC0CULL; std::uint64_t aWandererF = 0xE4C48D848A1BB6D4ULL; std::uint64_t aWandererG = 0x8BAF8D1E1A15B8EDULL; std::uint64_t aWandererH = 0xDB39789109208C23ULL;
    std::uint64_t aWandererI = 0xE4A2093A8AF518E7ULL; std::uint64_t aWandererJ = 0xCAE51F847ADE2DDBULL; std::uint64_t aWandererK = 0xD20BC36D60D28D0EULL;

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
        aPrevious = 11520819349529871263U;
        aCarry = 14058557761029547141U;
        aWandererA = 11569773164488116554U;
        aWandererB = 13027828292883145427U;
        aWandererC = 15495354458741332070U;
        aWandererD = 11469043505331189004U;
        aWandererE = 16498038041125801537U;
        aWandererF = 15268072251418366907U;
        aWandererG = 12161086291617477437U;
        aWandererH = 13242868887171102422U;
        aWandererI = 17539996273032054455U;
        aWandererJ = 13516241276170755286U;
        aWandererK = 11773948359247117159U;
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
    TwistExpander_Karate_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Karate::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAF2DBC058A14FB2BULL;
    std::uint64_t aIngress = 0xF6037BD787B5A225ULL;
    std::uint64_t aCarry = 0xA7D3BC16F1D4892BULL;

    std::uint64_t aWandererA = 0x92420BA81DF052B4ULL;
    std::uint64_t aWandererB = 0xA07163A5CD619FB7ULL;
    std::uint64_t aWandererC = 0xDE127538544F5A9AULL;
    std::uint64_t aWandererD = 0xC5D3A67F69783AF5ULL;
    std::uint64_t aWandererE = 0x80EE1C6C1CE6905FULL;
    std::uint64_t aWandererF = 0xF1805D751A976DEFULL;
    std::uint64_t aWandererG = 0xE445FEF85DA6E723ULL;
    std::uint64_t aWandererH = 0xB115C2F7EA334424ULL;
    std::uint64_t aWandererI = 0x919135E3B5D9182CULL;
    std::uint64_t aWandererJ = 0xB7FAA6042D1A8088ULL;
    std::uint64_t aWandererK = 0xDF9618BC0B57C56BULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::Sha256Counter(aSource, aSnowLaneB);
        TwistSnow::Aria256Counter(aSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    TwistExpander_Karate_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Karate_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Karate_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Karate::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Karate::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x97A6827034E0FED0ULL; std::uint64_t aIngress = 0xB0FEC532D7810DFEULL; std::uint64_t aCarry = 0xB126EB4D2C1969A6ULL;

    std::uint64_t aWandererA = 0xB508CB7C9BE1B2FBULL; std::uint64_t aWandererB = 0x8EF17576CC3D91A6ULL; std::uint64_t aWandererC = 0xAA676BAB6AFEF8FDULL; std::uint64_t aWandererD = 0x91FA058274A12DB5ULL;
    std::uint64_t aWandererE = 0xBA26C7BF1B246D50ULL; std::uint64_t aWandererF = 0xDF9F42B2D829DDAFULL; std::uint64_t aWandererG = 0x96BDF74DF1A09501ULL; std::uint64_t aWandererH = 0xAA07C85D7DA0BB13ULL;
    std::uint64_t aWandererI = 0xF51D7D1051579A71ULL; std::uint64_t aWandererJ = 0xE4B43E39E8BB4384ULL; std::uint64_t aWandererK = 0xFEA7E35812B8ACACULL;

    // [seed]
    {
        aPrevious = 9874535105837211375U;
        aCarry = 14438943124292896815U;
        aWandererA = 16400952741496389820U;
        aWandererB = 15054998181061188707U;
        aWandererC = 12117721277475137771U;
        aWandererD = 15471890479079625156U;
        aWandererE = 10887099496704708612U;
        aWandererF = 17573061763585228501U;
        aWandererG = 14795728789086749656U;
        aWandererH = 9980485921217077703U;
        aWandererI = 17029814888326329238U;
        aWandererJ = 17726029909967583637U;
        aWandererK = 12058103302838860180U;
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
    TwistExpander_Karate_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Karate_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Karate_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Karate::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 3, 0, 2 with offsets 4865U, 4777U, 3049U, 3127U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4865U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4777U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3049U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3127U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 0, 1, 1 with offsets 7548U, 494U, 1387U, 277U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7548U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 494U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1387U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 277U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 1, 3, 0 with offsets 355U, 7210U, 7355U, 5876U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 355U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7210U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7355U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5876U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 2, 2, 3 with offsets 5967U, 6403U, 4942U, 1873U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5967U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6403U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4942U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1873U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 3, 2, 0 with offsets 789U, 1708U, 619U, 1464U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 789U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1708U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 619U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1464U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 1, 2, 3, 0 with offsets 320U, 1357U, 1721U, 937U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 320U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1357U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1721U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 937U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 2, 3, 1, 0 with offsets 1302U, 171U, 71U, 1395U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1302U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 171U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1395U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 0, 2, 3, 1 with offsets 17U, 1362U, 306U, 927U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 17U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1362U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 306U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 927U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1717U, 868U, 1842U, 66U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1717U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 868U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1842U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 66U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Karate::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 2, 0 with offsets 7860U, 5176U, 436U, 1403U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7860U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5176U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 436U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1403U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 3, 2 with offsets 3660U, 1102U, 5033U, 7449U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3660U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1102U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5033U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7449U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 1 with offsets 1286U, 387U, 2457U, 785U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 387U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2457U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 785U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 3 with offsets 6387U, 6561U, 6184U, 5337U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6387U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6561U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6184U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5337U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 4327U, 5825U, 7223U, 1820U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4327U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 5825U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 7223U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 1820U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 819U, 1221U, 622U, 358U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 819U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1221U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 622U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 358U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 772U, 702U, 2018U, 494U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 772U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 702U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2018U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 494U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1584U, 1748U, 1914U, 1669U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1584U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1748U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1914U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1835U, 1647U, 713U, 270U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1835U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1647U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 713U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 270U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 950U, 1994U, 393U, 1431U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 950U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 393U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Karate::kPhaseASalts = {
    {
        {
            0x6BB0F43CDA400898ULL, 0x2912D63D22670617ULL, 0x7E27B74D1323D8C3ULL, 0x8BC8EE79D2398D86ULL, 
            0x2E4632E652DC5C87ULL, 0xC42879B4E2A013D1ULL, 0x8E87E776E670E99DULL, 0x12FFA12614E78A4BULL, 
            0x1BE742A856E95817ULL, 0x2A27E7F6F1A73DD5ULL, 0x887BFE10BD0581C3ULL, 0x0447451E17F36545ULL, 
            0x6B5E0FCFD2767595ULL, 0x147255D8AF5A9746ULL, 0x3FE15CE79D4208EDULL, 0x00680FACA7AEFD5AULL, 
            0xF7472D5E386E7D97ULL, 0x5E0A812EEF8883B3ULL, 0x7BABE3B45952140BULL, 0xF2F9712D982D3632ULL, 
            0x858182F00DA07F64ULL, 0xFBDC264DD198CCBCULL, 0x6463FBF460D5CA6FULL, 0xA8CE0CB12895AD6DULL, 
            0xD7B8723FFFCFF715ULL, 0xDB5B17C2B07AB510ULL, 0x7A474DC0AE16B3CBULL, 0x911A5DEFBF258BD2ULL, 
            0x1EB4916875329F39ULL, 0x0F12D110929F8A07ULL, 0x7E353F0BBC44CC1BULL, 0x502C08A24EA2AAE1ULL
        },
        {
            0x2D76499AFE2EBC26ULL, 0x892B24CD726A5873ULL, 0x74BA0513CD583069ULL, 0xADE95A5694111DE8ULL, 
            0x8FA6803F650BF099ULL, 0x1BF526B08C0D042DULL, 0x395F84D7E0887454ULL, 0xBC6E6FE4F717F497ULL, 
            0x25115546BCDFA1E5ULL, 0xA53AE9B0CEF0ABA8ULL, 0x0A1E780FDB91713FULL, 0x36697EF663A75FFCULL, 
            0x22B8900A18FA8161ULL, 0x5DBF12DA114ADB13ULL, 0xC2F1F1365CBDE430ULL, 0xC4D3197335DA9E4BULL, 
            0xE432CB1CC29CFCC7ULL, 0x579735AA8D877FBFULL, 0xB957572D941247E4ULL, 0xB3CC28749D6214B5ULL, 
            0xB2678E7FBBBF5703ULL, 0x6221E915F7BBE0C4ULL, 0xF42CABE0D86FD5CBULL, 0x58B9E1E50B30FB46ULL, 
            0x0BBD2C11E5DF560CULL, 0x7A4CB1181D701576ULL, 0x373287B3E8EA828FULL, 0x003ADFF93713B02FULL, 
            0x2F85828E48F723D6ULL, 0xD3592787073AD30CULL, 0x679364CEED6E3096ULL, 0xC3FAE45391D26D1CULL
        },
        {
            0xF643B093A73B007CULL, 0x1936F6DF7672A8E8ULL, 0xED70C18EEC3BCFADULL, 0x2E682D4EBCCA4010ULL, 
            0x6518AE487FEA3082ULL, 0x40FD82DAE77DFFC7ULL, 0x1AEE4B00744A0813ULL, 0x44EACA96A266F925ULL, 
            0x155F3D57C26DA540ULL, 0xAB8C0EFAD5D33763ULL, 0xFB3636F9C1BF908DULL, 0x6F427B863AF64ED2ULL, 
            0xEE7DD0F1B877BEA2ULL, 0x05B8B9186E00837FULL, 0x1C374D9C9406FD78ULL, 0x557E86C57DD62C0EULL, 
            0xA9D10D178EEE66F3ULL, 0x32CBA66E8E0DFC14ULL, 0x2B3A47BB24BF1246ULL, 0x9754A1DF7EC29FBFULL, 
            0x56FDDCA2F87FA8D1ULL, 0x1FC0A446FF90CF34ULL, 0xA73CC1A45C4BCA4CULL, 0x68001DDBC69FFD3AULL, 
            0x1B0BFB6CE5DC9CAAULL, 0x9343959B58D8CD41ULL, 0x5081FE942F845600ULL, 0xD6E027EEA788CF3AULL, 
            0xA738A0F49F359221ULL, 0xCC671F0AC773C3B7ULL, 0x6095CB56E5F90B94ULL, 0x0B938B45480036B7ULL
        },
        {
            0x8D156A8AF9A389F1ULL, 0xF682ECBB999FCC04ULL, 0x14DF7116FB670A53ULL, 0x5E9054B66356288EULL, 
            0xD4ACEB5B22E00F77ULL, 0x2D4F28021F0AE310ULL, 0x2451AB4817B80198ULL, 0x9AEC1EEC2F3A1496ULL, 
            0xCDB9A6F70AEBF4FFULL, 0x60365A975175CB97ULL, 0x8CE913F655ADB8E6ULL, 0x8E8C31DFEB1FA97EULL, 
            0x045EC913EA5A5112ULL, 0x708BB56C89A32DA0ULL, 0xE775C5169D1AA150ULL, 0x4B37569C38766520ULL, 
            0x0AE9F466D2602924ULL, 0x58019F83997C3B83ULL, 0x1B87937D1FA531F5ULL, 0x98096A7F413786E3ULL, 
            0xE7EC00D0F6935A5AULL, 0xC4CCD19093E82903ULL, 0x32EDC6A52AE7A6B2ULL, 0x983586411274FB7FULL, 
            0x4E1EE2DB31C13114ULL, 0xCB09644D7CB8993AULL, 0x423F174152E97E2DULL, 0x2D100DD00BC2D901ULL, 
            0xD659A8C5855DD54DULL, 0xAF9167F39988C8FCULL, 0x41772C6A31E4EC20ULL, 0x3E7D7DE4B0965DB9ULL
        },
        {
            0x99D2F629BB1BD647ULL, 0x47922B2E6ABADD2BULL, 0x7D80DEA3954242DCULL, 0x1757F81657C9B5FBULL, 
            0x58A68D53AD57602DULL, 0x13D7670D15550E7BULL, 0x15584FAEC42B3657ULL, 0xCE68BEB54536D35DULL, 
            0xDA8993E949F8866FULL, 0x51FCF6A8DCAC6250ULL, 0xA73C3DBEFE94B8C2ULL, 0x82BDEA66157ADF96ULL, 
            0x513657FEC7CDF009ULL, 0xC1C706BDFE57123CULL, 0xB24FE07E0DB36C23ULL, 0x5C6BB8866BAE9668ULL, 
            0xDB5E55C323028068ULL, 0x46E3AD72352C50ADULL, 0x0A340CBC5BA4E49FULL, 0x54135D801CCB0643ULL, 
            0x8FCE2C599BCBD6B1ULL, 0xB5DA574DC82B0F95ULL, 0x2B8803D0A0932A01ULL, 0x3664C560CFBD5644ULL, 
            0xB114F0F1B0D3078FULL, 0xF3B07D5EABF29179ULL, 0xE20E865EDA2D156CULL, 0x58CD8473136F0E32ULL, 
            0x87167273F0FE1650ULL, 0xDD366A80511AC2FBULL, 0xE1694D3A254FA917ULL, 0x76F04C3AFFD660F9ULL
        },
        {
            0xAB99C51C3F074D7EULL, 0x9DA7C86A0EDA3EBBULL, 0xFC3BA9768FFF6664ULL, 0x5E9FE02879707304ULL, 
            0xCD3CA369EADEEB07ULL, 0xAF6BFFDB8B84DE1EULL, 0xD418C625ADC41F4DULL, 0x8F062B75DE27E85EULL, 
            0xD34A9181EBF4D323ULL, 0x02BA9816867AF3AEULL, 0xAE74559D6396EB09ULL, 0x35F8B775EA0774A9ULL, 
            0xC739DCC029E784D1ULL, 0xED0D81941F7B3E87ULL, 0x9A6A42358DA3864FULL, 0xB5CD400E71010F9CULL, 
            0x3C0D07D5B00B90CAULL, 0x4FBBB60BD37A1B7BULL, 0xBE493EE5118048E0ULL, 0x49BD822FDF83FCF1ULL, 
            0xC74F335D6E746D8DULL, 0xE8EBA839D8F9E43AULL, 0x55B524D7D9F66F51ULL, 0x7C6D3D953352595CULL, 
            0x5F3F7E4CB5A179C4ULL, 0x1BF99BCF18491657ULL, 0xAED275C3B12FF885ULL, 0x0871CF5E383F2EA2ULL, 
            0xC13DB60A302F43E0ULL, 0x31F54BB31CA756B8ULL, 0xAD1A0047BA44E6BAULL, 0x4B5354B4E7B5C6D6ULL
        }
    },
    {
        {
            0xAFBD5E7C7B08C9BCULL, 0x9A31100C54F94CEEULL, 0x50D1E7B2CB686A8DULL, 0x12CEA36A022791F7ULL, 
            0x31AF1BE8B5760EDFULL, 0xC541D44A343BE6A2ULL, 0x8873B0F7B705F1D2ULL, 0xED3029763EF1D25FULL, 
            0x3E40ACE76FD2721CULL, 0xC0BD6BDA549E509EULL, 0xB135CC335912E830ULL, 0xACAC39AF5B36DF03ULL, 
            0x7410D41F45C00E1BULL, 0x5CC64334DC3CBE11ULL, 0xC3058151ED16AB3BULL, 0xDFA9596A24BD690DULL, 
            0xD7B4EB91C673CF61ULL, 0xDFDBD720D731A3A9ULL, 0xD070ACEAA43EF8BCULL, 0xCA7B7C355BA412C6ULL, 
            0xF221BF6549666113ULL, 0x587AD33000383693ULL, 0xE05FD47D616F5423ULL, 0xC7FCD19417CD62FCULL, 
            0x450C08331667D204ULL, 0xF15336C71878E717ULL, 0x90D53545EE28B3C9ULL, 0x4663207F12B18427ULL, 
            0x4A3B54400909F362ULL, 0xE129DFD491B96EECULL, 0x1265DCC7E21A190CULL, 0x13F74F77E35D6101ULL
        },
        {
            0xCCF30408B5A2DC40ULL, 0x196A7D5884C5DB84ULL, 0xE2FF4E2BE6EFAC4CULL, 0xF7B7E145C9B42CB5ULL, 
            0xC3FFE02CD5941797ULL, 0x329D9AE325886525ULL, 0xEB80B48ECF72FAADULL, 0x727A5843C48DA7E0ULL, 
            0x202774DC55511F08ULL, 0x6F9F39A2897EDE7CULL, 0x0881ADE53149E4CFULL, 0xAEBCF7612CC174F0ULL, 
            0x7F708AE129B3B864ULL, 0x792D30FA89054CC1ULL, 0xCA4BA8B4E3D46B05ULL, 0xDEAE798F7302F771ULL, 
            0x531267EAF9B2C5F7ULL, 0xE14709A3A0092348ULL, 0x023DB73D1BBA5300ULL, 0xD68D2F5B449AEDAAULL, 
            0xD3563B2913BC0BBEULL, 0xCFB8ACD8358C81FDULL, 0xBCF89EEAEB70FB2AULL, 0xC4202FB2A365DB2AULL, 
            0x0EF96BDC4714031BULL, 0x9F49953E9979263DULL, 0xB0DDDD542EA45B99ULL, 0x863AD2DDF9C73919ULL, 
            0xED4A5A6D2FD5B145ULL, 0xA3F83F1843A77A47ULL, 0xF66BAF270D7E8C08ULL, 0xAB5CC081692A1129ULL
        },
        {
            0xB5C3930E592FF504ULL, 0x49562EB2E23F05F9ULL, 0xC27C9E914440B6A4ULL, 0xE453009979359B82ULL, 
            0xC061306F9CFFAFE3ULL, 0x5D52C307F2659EDFULL, 0xA0A96BF095F66BD6ULL, 0xBE41FD2110C64F40ULL, 
            0x0817C9B36C686732ULL, 0xDF2ECF16DDC6716EULL, 0xEF9CD953289DB009ULL, 0x071B6A1A0B6923B9ULL, 
            0x3997D0161C7738ECULL, 0xF5260A236E9A0F42ULL, 0xA0016E2749900D38ULL, 0x71551EB74A871BDEULL, 
            0x232DBC006E39A8D7ULL, 0xB00160D51905D4FBULL, 0x4FF80618288E74BFULL, 0xE57F29D4ACCFDB88ULL, 
            0x49D880AB9022D488ULL, 0x8ED4BB1501243B01ULL, 0x7D6569A63A814284ULL, 0xF60239979B311546ULL, 
            0xD9B2E53D414317D7ULL, 0x324A539CD542A510ULL, 0xB3088F639B47A054ULL, 0x1288B8A953894E5BULL, 
            0xB44F55CAD49F6B95ULL, 0x81C59428AE8835F9ULL, 0x0B743E0D62840ABBULL, 0x0EEE9C81736B8A6FULL
        },
        {
            0x5B12F9CA2A34B5B7ULL, 0x1C240E936F7A0EB9ULL, 0x236255009AB4D1D2ULL, 0xB90C2E9934AD7610ULL, 
            0x989E099388CEA410ULL, 0x0FA7909F725DB55CULL, 0xE327BEB132CD13DAULL, 0xA04FD9BE6BC3BD3EULL, 
            0x45C91750BD4EA71DULL, 0x93EA513577FA1968ULL, 0x4B5AD132B17C8057ULL, 0x44D261D5327787F9ULL, 
            0x963F47694E4C0F07ULL, 0x1381FE905BE15AF9ULL, 0x462905A7C0E31598ULL, 0xDAD9D82E8E5C53B8ULL, 
            0xE6DEE3796144F6E3ULL, 0xAC9E8DEC10B3341AULL, 0xB894DE1E342603A8ULL, 0xC48C688BAC36295BULL, 
            0x9E565AC5850DA4F3ULL, 0xA1DFE80E4551F031ULL, 0x428A0D973917A32DULL, 0xE448D90D8EF110A2ULL, 
            0x3A20923391520177ULL, 0x7AB04174C53C31CAULL, 0x68055E6EF4986D3BULL, 0x46F8EBA9F4C04CDDULL, 
            0xBB01C9982596858AULL, 0xC8E11BAB08829AFDULL, 0xB19039E2057890ECULL, 0xCD80BAAEBA9A2145ULL
        },
        {
            0x2557D4A8E6110D06ULL, 0x959B953C72EB14E1ULL, 0x9723103738CEBE72ULL, 0x0481F2BF8D8D295DULL, 
            0x1E9D25134E241CD6ULL, 0x46C552E51E740ED3ULL, 0xE32083C93BDE4718ULL, 0x0139DAE0AD8258F6ULL, 
            0x059101947228BB22ULL, 0x50DBFCB5C3F84EDFULL, 0x5179C36D41204477ULL, 0x7330F3D490BF6914ULL, 
            0xD1A25F4F0875A8F2ULL, 0xDE9FBECC8C5B853DULL, 0x31FF8597CA059166ULL, 0x9E5EDB757E50D897ULL, 
            0x9A04F5B08D9BC526ULL, 0x057C4CC27C4A028EULL, 0x36A37823A9274F11ULL, 0x8920B8025817D174ULL, 
            0x5BD7AF547469F068ULL, 0x554CDDC8139FCF2EULL, 0x0387939123C453C6ULL, 0x1C1E26F5C2BB4125ULL, 
            0x3FCC6B0C8609F133ULL, 0xD9B35F1530D261FFULL, 0xDF1EAB5F42EAAF54ULL, 0x77534D14ABE69A77ULL, 
            0x0F41F88FDB6B7DA1ULL, 0x10A7DA38879F2E94ULL, 0xFDEDE55391E93B19ULL, 0x9BFD7CABEC5CC376ULL
        },
        {
            0xFA5B64BACA181477ULL, 0x1473866D207D19F2ULL, 0xE294D70330682A76ULL, 0x5F3E1269DF0D9484ULL, 
            0xBC6550C4488A5B80ULL, 0x9361645C59435F46ULL, 0x2E8117F7515A6875ULL, 0x7748DB7BB0B8E705ULL, 
            0x5C54079448688527ULL, 0x9E43B09D467A393AULL, 0xEF64CBC6328B66A2ULL, 0x779FECAA0DD48B9CULL, 
            0x58CEED6356160C83ULL, 0xD5DDADE212985A1EULL, 0x7A67BD16E8FDDA21ULL, 0x11790483601A9086ULL, 
            0x031CFFCBCA2BFC70ULL, 0x57D93678A2EBDEB2ULL, 0x7762EFE4DE7B63E6ULL, 0x5B4E6617C45BFA33ULL, 
            0x4D1E5661CF3FC00FULL, 0x30480B6434A7069CULL, 0xE9233A9BF77B9083ULL, 0x231ADAD8EC02F428ULL, 
            0xD04BD5099208D04EULL, 0x9537377678D8B6AEULL, 0x0BA8F04A5EFAE708ULL, 0x1953B2A3B4CBE741ULL, 
            0x2D2D75FF50A0F8C2ULL, 0xDEAE089B4B7688A1ULL, 0xBB68A50A9EAEED3DULL, 0x3054BEC5742E9058ULL
        }
    },
    {
        {
            0x6A93E3296FB6C2BAULL, 0x3EC25260F789F388ULL, 0x9C9CA0347F002D98ULL, 0xB3901F060C95D26CULL, 
            0x45337A3FF3D03B27ULL, 0xDE0B4CAF8086DA7FULL, 0xD3B37D7ECE804810ULL, 0x083C2159C0812D55ULL, 
            0xAA78003A8D3E0C04ULL, 0x08CCE59461F551ACULL, 0x5C74CC72573B6D90ULL, 0xB7EB03C6949AB162ULL, 
            0x0D2E7C69A1C52809ULL, 0xBB2777CF5037F110ULL, 0x6B5E6B2D1AFA546BULL, 0xEB8FE4D98F75F8A9ULL, 
            0xE720C8DB7A25B93AULL, 0x5FE17E9EB4ADD069ULL, 0x5114B91F05642A30ULL, 0xCE6BE95F45194628ULL, 
            0x7D53E5383BCD6ACDULL, 0xD8CFC2BB71A0B18EULL, 0x7692C15076B33CD8ULL, 0x8B81B17C39A2DF05ULL, 
            0x312C39D516338986ULL, 0xA50E0FAF8E22B31DULL, 0xC0032A7E04081F19ULL, 0xC361BB8EB49BCBA8ULL, 
            0x8DB9614075F1C530ULL, 0x6AB0E4AC377CD021ULL, 0xCD8D142156CB0216ULL, 0x0CE52C38722C3049ULL
        },
        {
            0x0B2EE94BA9826FAFULL, 0xAB009E53F15608B3ULL, 0x416E37C3C189E536ULL, 0x12D7F7296B54EF6BULL, 
            0x46C198C24F2E8591ULL, 0xE8E46DA4497A787CULL, 0xFF5ECD2641B98801ULL, 0x9E3B750536267DFDULL, 
            0x673268E6AA1358E8ULL, 0xEE99762386C3BA26ULL, 0x8EF2B8C429DD3CBEULL, 0xBA82EB60E0DC4A16ULL, 
            0xC608069724A956ECULL, 0x7A91C381313B1EC5ULL, 0x63C9A6EBEB8BA836ULL, 0x92829DFE23D199B7ULL, 
            0x03B72DA0613E708DULL, 0x5621EE95E0D447B7ULL, 0x44676633A2E5B4B6ULL, 0x89D1E3B5FE79DEAAULL, 
            0x9F45E57DD6914A69ULL, 0x1560C9C72D131358ULL, 0x0FE4E37C357FD99AULL, 0x6BD60D2C8A7EEFFFULL, 
            0xA896EF0A15E1AC45ULL, 0x7427B21CB0BD9088ULL, 0x9EBE541318922152ULL, 0x7BECB91B0F26FED5ULL, 
            0xF8FFE5CE763BA7F0ULL, 0x7C9D381C878C0617ULL, 0xF56C8D46B9EABD2DULL, 0x4F2A502CA9D7DBF4ULL
        },
        {
            0x5C31ADFA0AC59BF5ULL, 0x7B54F1D76D1A964DULL, 0x36BB8113D0B0529FULL, 0xCBEA8F3F42A5EC4BULL, 
            0xE64726238AFEEB41ULL, 0x57A5A05055BC7322ULL, 0x6921FB5D391DBA95ULL, 0xC1BB71B653752BEDULL, 
            0x5ED726C5307D35E5ULL, 0xA544237C18DA3845ULL, 0xF98F5D98088D2CEAULL, 0xD6F5AC9D0D4E34A7ULL, 
            0xA74F45460739C187ULL, 0x523D6E50CEDB7EDDULL, 0x198D153DE23BD397ULL, 0x4D00351263035F5DULL, 
            0xC33E9EF0054ED138ULL, 0x8CDF41824EBF0A33ULL, 0xFECC57A3636F3F12ULL, 0x9025F1EE544474C8ULL, 
            0x373617BFDB1F4B52ULL, 0xF18BCA85E731518EULL, 0x4E73E90612C3EC1FULL, 0x8307DA96D951B686ULL, 
            0xE99CEAC626C99709ULL, 0x6D8F86F6151CCE31ULL, 0x82ED0BBAFF74B8D0ULL, 0xBB32DAF9250FA5BAULL, 
            0xE581F50AA97FA535ULL, 0xC33B9F8951CCC379ULL, 0x8F2F8A8C4E3C244EULL, 0x7097ACCC638F26ADULL
        },
        {
            0x6D3A9A2A85ACB1B9ULL, 0x87E3FEE1D560DEF9ULL, 0xAE4081790C45A679ULL, 0x13F72E351CDEBF5DULL, 
            0xD8D4505E109015B7ULL, 0xA5C23EF661C61BEBULL, 0xF78CD0BDDBBA66F9ULL, 0x00FA01EC8FE16303ULL, 
            0xBAE1F0061961C62DULL, 0x28AA632CFDBDD794ULL, 0x5A72D2CA305C8D41ULL, 0xC44E38FEAFB049CAULL, 
            0xFA26BB9038AC3B0CULL, 0xB444A3BD1C998B95ULL, 0x8B92AEC488C1D5AAULL, 0x5A3D527B8EC9B242ULL, 
            0xDD91097524F8C5D3ULL, 0x0E0BB95195665480ULL, 0xE6C87A73FDB4E86AULL, 0x71DA157AED2B9668ULL, 
            0xEF4CD40F1A33B9D9ULL, 0xB71857C99AF7985BULL, 0x41678312B8679468ULL, 0xC489EF0441591D89ULL, 
            0x113363ADD86D136AULL, 0x56D3501D37B042E3ULL, 0x483522BD0B8C1DD0ULL, 0xD7CEF4B86904E727ULL, 
            0x596747ED84735578ULL, 0xA92B16B2E16B362FULL, 0x686DDA04494E4F47ULL, 0x2590F2B1A1C9C669ULL
        },
        {
            0xF1B7235F4410930AULL, 0x91E72E794A1DCE10ULL, 0x222C894EE8E47FAFULL, 0x70B0BF6F595EA0EBULL, 
            0x23EB26116347E25CULL, 0x6AED9708729F05DEULL, 0x1835934217BE8C95ULL, 0x363161CC15D06D48ULL, 
            0x590DEA754ABE73C6ULL, 0x6C3A0AAF9699127DULL, 0xBEA7F172BB7F2C20ULL, 0x0CC33B898C82B2E8ULL, 
            0xE10728A89820AACFULL, 0x833A126B30FCC255ULL, 0x9BBCEFA8CC7C65F8ULL, 0x0A4F4719947E036CULL, 
            0x751CE22DA0D62341ULL, 0x6E6CE220E64C4D78ULL, 0xCAFD1E2C467CBD5FULL, 0x72F25293B64860CEULL, 
            0x70C5C1EFC9C19543ULL, 0xB78E2AC56D26275EULL, 0xB95BC8E864788F11ULL, 0x8CA8A0715B49CCE2ULL, 
            0x26CC83B85BA43EF9ULL, 0xB4112AA643B12E7DULL, 0x72A78091C0C30A58ULL, 0x130DCF7B01E71712ULL, 
            0xA8B7A7FCE56F1C3AULL, 0x975E87C6E8CBA75AULL, 0xE89EC75ACE41B177ULL, 0x3B4E72B49E8153BCULL
        },
        {
            0xFD573E4FE23FA17DULL, 0x4E6BA87FA03D4A04ULL, 0xCC0BA78C3FFAA572ULL, 0x947C658FE527A89BULL, 
            0x950F1D3D2DB4BD73ULL, 0x89E375377DCE17B4ULL, 0x9A8D65D20D45457AULL, 0x1F5E83D5FE8AD630ULL, 
            0xE9ED0E751B6B6D03ULL, 0x613E384853CACAD7ULL, 0xF65FB63FA43C57A7ULL, 0xE28A772C1379C2F3ULL, 
            0xE785E9A4E4BC1899ULL, 0xA910692E4670A84AULL, 0xA82D73D16ED5D6DAULL, 0xAFC993DAB0C10F62ULL, 
            0x41B35A93B4997EE7ULL, 0x0100CEA6916AF4DBULL, 0xD541E8998FC87017ULL, 0x43CCF31355C3497FULL, 
            0xFA06738D0D3B35E0ULL, 0xF26A189D7F878615ULL, 0xD13E50E363734704ULL, 0xFB873B90C35ED7FCULL, 
            0xD10D8742906683EAULL, 0xBE8519853AD3F1F5ULL, 0x9FA765BD6008F698ULL, 0x781A34D13087F886ULL, 
            0x804229F6811358E1ULL, 0x38BEA93B40096CD0ULL, 0x3B998A4959DF2770ULL, 0x5088B97206FC299FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseAConstants = {
    0xC676848CC15ACAD6ULL,
    0x3AC3F090B5AA3E5CULL,
    0x322698C8AF20232EULL,
    0xC676848CC15ACAD6ULL,
    0x3AC3F090B5AA3E5CULL,
    0x322698C8AF20232EULL,
    0xDB727C869D029A73ULL,
    0x68DB943210BA60B0ULL,
    0x2C,
    0x35,
    0xF7,
    0xC1,
    0x1D,
    0x57,
    0x5B,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseBSalts = {
    {
        {
            0xC153D3CA27447419ULL, 0x445F92FBE3646545ULL, 0xA893827FA86D0184ULL, 0xA8B0439D64513931ULL, 
            0xCCACD7808B434327ULL, 0x922094CF2D1FC746ULL, 0x26038F4A7963C707ULL, 0xFA08E0303FED803AULL, 
            0x54E6FDE93E3CEECBULL, 0xBE7E36D571D85091ULL, 0xC3FC168CD0B1A1D6ULL, 0x800EEA463B5C3B59ULL, 
            0xBAAB7BC865A6B0C0ULL, 0xEE68347664DE6FF0ULL, 0x47BF2A6D44FDE94CULL, 0x63CDE5594752FAC2ULL, 
            0x111E5564826BFDD4ULL, 0x201701B2256A2E59ULL, 0x88DB9504D92A3876ULL, 0x5ABA7396A7B76080ULL, 
            0xE3B7B0A4334FEAB6ULL, 0xF747CC00840167E0ULL, 0x9DD635059D1B4373ULL, 0x963FF029C292D623ULL, 
            0x396BF23730CDCFA4ULL, 0xFB9222D7587124FEULL, 0x0C13A7800160C293ULL, 0xD3B86BEDB761F9FDULL, 
            0xD29438CB36F1E601ULL, 0xD901633D2784B473ULL, 0xDE810E22D6487330ULL, 0x3177214D81AE48DBULL
        },
        {
            0x6A5EA1CF09C4AA21ULL, 0x33A474C97E4D0442ULL, 0xFE73E0C9F0FAF5A7ULL, 0x7E80EBCF85EA5F0EULL, 
            0xE984F92B18E32D50ULL, 0xCE0DF9EB0219EF4EULL, 0x0054242AD6CB217DULL, 0x85712E8D3D8F246FULL, 
            0x398D60B62BC0B7B8ULL, 0x35246611E5AD576AULL, 0x0E0E3D242425B716ULL, 0xC7E95CB486A4F522ULL, 
            0xC9B90055D9957DDFULL, 0xF16876390F1DCEDCULL, 0xB8506501DC811491ULL, 0xC9054518A8BE429CULL, 
            0x2F3C0FB3F5FE9450ULL, 0x19AB463D5E7E16E6ULL, 0xC4332311DE861055ULL, 0x9FF24E591EC0E491ULL, 
            0x84FBA2B292DBA25DULL, 0x9029B2F4738B23B1ULL, 0x9B0196BE14A2C16EULL, 0x10A49D4F7091F2EDULL, 
            0x3F33A7AFC5BC2F6EULL, 0x9FB28725A77D3EB9ULL, 0x36826A5AE0C05C20ULL, 0x7A6EE5D0840964B4ULL, 
            0xAB89CE163659ED9CULL, 0x1355EE644DEBDFC0ULL, 0xE0DDD7B9697DDCFEULL, 0x1F0C11C838F5AB4AULL
        },
        {
            0xD42DE7D4681168C7ULL, 0x9651CE187A005CA6ULL, 0xFDC7F70692B7FCF0ULL, 0x43B085D9BA31C883ULL, 
            0x9E2628A7CF9A6F26ULL, 0x6EC0AFB9E7FAE403ULL, 0xC655ACE505CB26CAULL, 0xC6B6EBA2731A9E10ULL, 
            0xCBB9D884E7251AB9ULL, 0xD7BE98FB9F8271AAULL, 0xD6560DB29775BBBFULL, 0x797C6E74EC1F805EULL, 
            0xA218E91A9723E1A5ULL, 0xE724D098280FC412ULL, 0xC34319F181FB8A5AULL, 0x6E8F72A637939FECULL, 
            0x77040805C043191EULL, 0xDF64A810B2445657ULL, 0xD6BAAB566D88C22BULL, 0x3BCDC07E04825B0BULL, 
            0x9AAC0FF1D99F3DECULL, 0x058E87317C0DF91EULL, 0x71D8EE119543CD1BULL, 0x263A573F10B92D3BULL, 
            0x6D60A9A39FBD4F1FULL, 0x9AA9198B5B43E08FULL, 0xE04BE0CEBE1F2802ULL, 0x7E9AB1F80788592EULL, 
            0xB4A7F106BB5C6B01ULL, 0x46496A94E1CCC05EULL, 0x5A07A1A50340035AULL, 0xF5B9DA076CE69E34ULL
        },
        {
            0x03A642EEB6EF5FA2ULL, 0x70563FF54DA591DDULL, 0x46BAF3485AE4C57DULL, 0x13C0D3A4595753B7ULL, 
            0x3C2B705D43B9E6AAULL, 0x0E39C3644F72B62DULL, 0x812851F5EC005742ULL, 0x947C99CB8A8C6996ULL, 
            0x57407496A335C3C1ULL, 0xE33C95DF153A8A60ULL, 0x7D28B2037083B535ULL, 0xE8BA4FE35721E384ULL, 
            0x4017D78EF2A06D86ULL, 0x17668245520DAA36ULL, 0xD4A7E078B7003DB1ULL, 0x742B4E7C7C4F2931ULL, 
            0xAACB63B715C11194ULL, 0xB8A0B506CCF0E319ULL, 0x08185A3C8898A6F8ULL, 0x69BF4E427EE94E88ULL, 
            0xBACF7FA0F107A0C1ULL, 0xA23A0FBA02368D4FULL, 0x9319532E35AED644ULL, 0xEE0D653132E47397ULL, 
            0x8C8423BC1CBF194EULL, 0x58253E5D401D6DB0ULL, 0xEE136F7CA0E91265ULL, 0x4DD1B08635B04A10ULL, 
            0xBF0698954331B6E2ULL, 0xB0B8509FB1DE207BULL, 0xD666DB081059358DULL, 0x52BC215E56AE2FBDULL
        },
        {
            0xC660D0ADCDAEFCEEULL, 0x15D00805BBBEF440ULL, 0xE5463C852A15432CULL, 0x50AB8EE47BAEEEC6ULL, 
            0xC13EEDA84CA101E0ULL, 0xB32048047D3B3EDAULL, 0x3BB814B18A4D4CF8ULL, 0x2FF4BF71CED43DA9ULL, 
            0xA13D7E3BCC7D1D5FULL, 0x1C32E34A8C457913ULL, 0xC43EF4C7A03C1459ULL, 0xAFE41E25949624B9ULL, 
            0xE70C8749B8FD3252ULL, 0xE575A2B57BF10166ULL, 0xA7DF6AF1DA9C2F5FULL, 0xDC680275FFA165BAULL, 
            0xC579C1DA7B03553EULL, 0x6294A18E44335666ULL, 0x00CD9BB9CE722DA4ULL, 0xE2B2AEEB57E73BE5ULL, 
            0x347C877CAC9E0A43ULL, 0x98E9448F6BB409B8ULL, 0x5F79E958B3F9C551ULL, 0x7820BA63E3B836AFULL, 
            0x07F6E30B2D7F8466ULL, 0x254203F0DD945DC5ULL, 0x9D75515EA6C0918CULL, 0x64A434462608F620ULL, 
            0x1D2F27351BCE3C26ULL, 0x905B6DFD0AA0A374ULL, 0xD74DAB9ED81B89DDULL, 0xB98A17BCFE456B07ULL
        },
        {
            0xBFB21B4B102E993DULL, 0x304658F2A7CC8B4FULL, 0x9DCDCE04C62BC7FBULL, 0x082B9CF46BBDCFE2ULL, 
            0x290CAAF096605307ULL, 0x6D1B680967526E97ULL, 0xE4EF6497C0BDFDF0ULL, 0x501A002B79DE6405ULL, 
            0x26B4BFB9150EC36EULL, 0x0CD1F999652D9086ULL, 0x0BFAED25E64733D2ULL, 0x5E580C4368137061ULL, 
            0x4243D6890021114CULL, 0xE015D48210986AA7ULL, 0x0D1D13DDAF1E436CULL, 0x5D63832134CEC24CULL, 
            0x5149A1B77535E29AULL, 0x9B3FEF27F7407623ULL, 0x1EE95D5ACB2FA34BULL, 0x7158EEB4867BAF10ULL, 
            0x13AF05D8A03A931CULL, 0x1923D3E05112FE1CULL, 0x293D054D02E08D6FULL, 0xB234E87EB5D44F99ULL, 
            0x92CD9B3416F72F80ULL, 0xF32F174BDCB7D79DULL, 0xCBE3AEA98A1ED526ULL, 0xD21BF9ADE0990B30ULL, 
            0xCEEDC57642291AAFULL, 0x249A7170BF8E1530ULL, 0xC7DAD26CFDCFCE4AULL, 0x5FD0CEA5C227E6AAULL
        }
    },
    {
        {
            0x97D1E08E95C980A0ULL, 0x83974648D41DB95CULL, 0xD36F09CE02F260F0ULL, 0xB36623E0395E011CULL, 
            0x66600DD2D4D4568EULL, 0x28EB4831E328DDD9ULL, 0xD9A7997704C03D39ULL, 0x57CE4723E504B424ULL, 
            0xEC5BE63162D7A4F4ULL, 0x0DC49851711F0D04ULL, 0x4939022B06D13E52ULL, 0xC089CD8DE8B0E7FEULL, 
            0x4ED3397DBBEA68B7ULL, 0xA06E4E7AEBA6D1C7ULL, 0x9720DB795C853494ULL, 0x4B657EB20D0291BCULL, 
            0x13B657F2798064A8ULL, 0x004D0F09A4400B39ULL, 0xB7A80CB8AF9706AFULL, 0x44AF8BE71FF046BAULL, 
            0x02CA0CD6EB55E11CULL, 0xFF72A2DC07E7A64DULL, 0x85AF6C6C3500DDB5ULL, 0x431098F897E2DAB5ULL, 
            0xA1B133A4A0D4D745ULL, 0xC74DEB4BFEC457B2ULL, 0x70BEAB12F7B2D950ULL, 0xEF6F37BFD223B32FULL, 
            0x2AB29EA701BA3477ULL, 0x03EAD158F57CBD11ULL, 0x904A4011DE2425B8ULL, 0xB181AAC51422CAFEULL
        },
        {
            0x1A7F18535D316E95ULL, 0x47CF7537B4E04732ULL, 0x68ED4569D216DDA8ULL, 0xBE22A52374698F42ULL, 
            0x50FE7100B122EAAFULL, 0x232EE98E14E5C672ULL, 0x16C6379E6871D762ULL, 0xAADAEBBC2E36A8E1ULL, 
            0x1EC3922F16EF0A58ULL, 0xE87C58A63BD9192BULL, 0xB906108AEB0F5B0AULL, 0xC0B446D30599BB5FULL, 
            0xB012F10560838B0FULL, 0x1F08DC7590EE497CULL, 0x7C698BC1E1BB992FULL, 0x2C1B6A20DD85145CULL, 
            0x9F1A3237F2178FD9ULL, 0x5CAAE87E181478F3ULL, 0xB806F4FB7E587165ULL, 0xBF1687710EED437AULL, 
            0x70A8010478D4C798ULL, 0xCBB16E80D3CB23F6ULL, 0xCFF96E273432BB14ULL, 0x48CD5B2E26A182EDULL, 
            0x6EFD2605CE1421EDULL, 0xC65DA8ED98200908ULL, 0x68745DA2DC1123A5ULL, 0x3BE6EEB3E25EB047ULL, 
            0x8B6FB0400C9C4A29ULL, 0xC0B9937E5CCC557DULL, 0x08829996EC66DCDDULL, 0xE9F17FCDBB32F5D5ULL
        },
        {
            0xC1EBDC42058D43E8ULL, 0x767BD2B90D20FBA5ULL, 0x9435F585944B45B3ULL, 0x28BB48B0F1FB8AB1ULL, 
            0x0FDF7DA50BD4445AULL, 0x9192FB6665AC28E4ULL, 0xBD36EFF65A612B7BULL, 0xCCCF0F99DF1F8D97ULL, 
            0xA2FEBCFAA8675DF2ULL, 0x4DDD75E4C56DAA81ULL, 0x49D0B94CD3447840ULL, 0x80FF04E5A7668996ULL, 
            0xD3F3DE1A61163C50ULL, 0xA8A0883E6A8FB528ULL, 0xFC7BCEC10C5A4046ULL, 0x68E003DA83F11E71ULL, 
            0x1EAD185DC116C93BULL, 0x4C8E39BCE9A4BDD5ULL, 0xCEE6B29155ECFC73ULL, 0x5719CCF1B3E0BD0DULL, 
            0xC83A15EC8CA2BFB2ULL, 0xD161229E96F54FC2ULL, 0x282E41B8A156F078ULL, 0x19E4B1EAA90BC200ULL, 
            0x54B229699559151BULL, 0x9D7B0E9674557FFBULL, 0x6EC1BEFC75A4E75BULL, 0x483DBD22D6A72FB4ULL, 
            0x1C672A61AD2BA9B8ULL, 0x4064FE8E46D811D1ULL, 0x824B36290FC1BFB9ULL, 0x8934DE8147645F55ULL
        },
        {
            0xC1E015A9654A0806ULL, 0xD991FBC0D876DFC2ULL, 0x72D61274EF194AE0ULL, 0x0413E872E64B341AULL, 
            0x5AFA6421D46C4672ULL, 0xD31F8A50601CBAFAULL, 0x61156A1747EEFBCBULL, 0x7890E7C224221B7EULL, 
            0x09B4DADB1C08BC0AULL, 0x1F2ADE0A7FB7A757ULL, 0xE415BB2917F350D1ULL, 0xFF49CB9721B7C3A7ULL, 
            0xCC8D92E8ECF56F6FULL, 0x16E92E98AC073FECULL, 0xA24F048C15E5143CULL, 0x6DA1EC9554E0AD3DULL, 
            0x2D58169FEAD91651ULL, 0x1F1EB29F6F77D9C6ULL, 0x1A67A847EFB62DFCULL, 0xA9BF584F1D6FCBF9ULL, 
            0x53E436BCD5F3E797ULL, 0xCC0299E5C41F19EBULL, 0xAACFA74718F2BF06ULL, 0xDAB57502307240D5ULL, 
            0xC893A60B7B1D2A7BULL, 0xEBDF99D9CA23F1CAULL, 0x84333BDADA4C8E87ULL, 0x67EBC7269951120BULL, 
            0x45C77A6E4AE4C3DEULL, 0x7D1E4EDE955C9563ULL, 0x8CE96597057173A3ULL, 0xB3AE2EF918D4C5A5ULL
        },
        {
            0x4F37D89D9F936BDCULL, 0x4C635417E6DE25D6ULL, 0xD60D8909C0474690ULL, 0xC4B15C05BA4D8515ULL, 
            0x6178EE7170FD4AE1ULL, 0x8BA6FF6D1F1DBC09ULL, 0x4AFAB49EFED53FB7ULL, 0xB5AE7F12F3B020D0ULL, 
            0xC7F3F0A45ADE66F3ULL, 0xF848405DF42F0037ULL, 0x55612CA3B32D7105ULL, 0x3CF20D53C27BB1F4ULL, 
            0xE451A44F53D2C3AEULL, 0x9E18245F29068502ULL, 0x7DB56D2CB95B62ECULL, 0x0F5F172E5E5D15C3ULL, 
            0x5BB4D9840EB89894ULL, 0x93434C5B4917E391ULL, 0xDAA4CC22E2319C0EULL, 0xA2E997062290F79CULL, 
            0xEF614CC0F534CD07ULL, 0x6A79321C5CDE2D93ULL, 0x8CFAFCEBF396D3D0ULL, 0xB7357B83FB81D0BBULL, 
            0xD25EAD97A4C42E58ULL, 0xDA83867C39589D14ULL, 0x4D74BE2B73D7CF5FULL, 0xF72C67AE276ED378ULL, 
            0xE14C10A7BB6E8FDDULL, 0x163B9F5576C31B55ULL, 0x4F6C8D997AD42A48ULL, 0xA110FD79076D501DULL
        },
        {
            0xF16BF6B97CF8BF69ULL, 0xE25EB0E54182E47AULL, 0x2FDAA012B7EF0F0AULL, 0xB81ED234F7E8B8B5ULL, 
            0xF4311FC55B77EE68ULL, 0xAD4FF38A272765C4ULL, 0xE1455D9FC7479F6FULL, 0xB960BCCCCCF68278ULL, 
            0x2C934280517C87D6ULL, 0x87B7D56CE51A00BFULL, 0xF4C468CF550593B7ULL, 0x23648727E93EE2E4ULL, 
            0x3310B95710DCEB05ULL, 0x7C9D705E91189EDDULL, 0x90C82D55B15293BBULL, 0x54A16B2233A42CE0ULL, 
            0xCCA629441A9154D1ULL, 0x3F0F420B56236372ULL, 0x6F3C6AB52567F499ULL, 0xBEE50A9C0581BB8CULL, 
            0xA7D1592863DEDD8BULL, 0x6C181138E18F71D2ULL, 0x8456FFF0EE64014AULL, 0x7E54F58D4E28BF5AULL, 
            0xA5FEA69B70332F72ULL, 0x6C4BFCB3C8AF580AULL, 0x81D11314DC46FDE2ULL, 0x1C8236D45C14A60FULL, 
            0xF70A3CB2FEDE5EDAULL, 0x3097F2B6429F04E1ULL, 0x7CE19923826CD56FULL, 0x8F96C44874AE3069ULL
        }
    },
    {
        {
            0x2DD0CF5CBB0541A0ULL, 0x9BB240EAE5E68CCEULL, 0xA01F7E97F172F810ULL, 0x46DCDFDB1046BA0DULL, 
            0xADD3ACBD4904836DULL, 0xEBCD52BB51AC396EULL, 0x07E4C28CB7C1E953ULL, 0xAE7B82657D994C94ULL, 
            0x48A494FF8582201BULL, 0x5ADA6CFBB4E6A1F2ULL, 0xC0459D7D4C943BC9ULL, 0x7267CB49FB9EFF6DULL, 
            0x852069D74CD9607FULL, 0x44B0913EF39AD89EULL, 0x07D1DDF6265F00A2ULL, 0xBC4579F27BF0E7AEULL, 
            0xE926864D8E63D1BAULL, 0xA0F5953BFD139A76ULL, 0x2D70418D3CC587ABULL, 0x18AFB378D28050F8ULL, 
            0x4AF5EA4DE10AFB29ULL, 0xC1D45B83F270E865ULL, 0xA85A03B888C9D24BULL, 0xAF0C01D17E946B7DULL, 
            0x349850C5914C8525ULL, 0xE9F17AFE2DBB2953ULL, 0xE231222CDC7EB2A8ULL, 0xADB7030728E89C3DULL, 
            0xA3630BF20636CF7CULL, 0x480323A3E889C560ULL, 0x2CA8214A945B3909ULL, 0xF49671FD8A98C04FULL
        },
        {
            0x9895C2E538E484A7ULL, 0x33500A0FD2C369FFULL, 0xB76DE5A9C4B4A07FULL, 0x852DD4E8756C7211ULL, 
            0x957ADEB3BCE8356EULL, 0xCE3F23145A99FCCEULL, 0x2B936F0905B46B0AULL, 0xF96E68185C3DB5DDULL, 
            0x592687697A26FBDEULL, 0xDD8A523AE175D466ULL, 0xDF80B85F875A77E5ULL, 0x7695BE50A4990F3CULL, 
            0x9ED9213D95A449FBULL, 0x686D840008146B8BULL, 0xDE72DF5C90D690ECULL, 0x561547A3BA5AD885ULL, 
            0x12C343A75E1D76D1ULL, 0x644E1FFA91A2479EULL, 0xDAF16D9A39D7E716ULL, 0xBF13F4F711096419ULL, 
            0x49A1A24D280DB201ULL, 0xA906095E936C2519ULL, 0xAF27698201AC97DBULL, 0xC0EEB185E3AA4066ULL, 
            0x8E9E1BBFCC30F2DCULL, 0xBE69D6020AF3BCA6ULL, 0x4134043512A11053ULL, 0xFCB6F62D5B659BA4ULL, 
            0xB929685C30252725ULL, 0xD7B6D2612639C1ECULL, 0x32F8A78A212E92EDULL, 0xA7A4E542AD6BEA86ULL
        },
        {
            0x4E5878D24D3DF9BAULL, 0x1AF4C318F5526E3EULL, 0xE3C372B61108C9E7ULL, 0x0B762334B52608F3ULL, 
            0x222F520428216A45ULL, 0x0E86D7D158AA440CULL, 0x7C2F88285E0453C6ULL, 0x2A26977B87E39F8DULL, 
            0x940894ECED472170ULL, 0xDC3FF012CEBF9321ULL, 0x4CC690F6562CC462ULL, 0x21D0481BB78097E0ULL, 
            0xAACB058BDA7253B3ULL, 0xA97E7BC6F32679C4ULL, 0x4AF568AA212D3800ULL, 0x3CDCEA4A480B9675ULL, 
            0x80121E0E5A0FC826ULL, 0x1378250A77AC2782ULL, 0x64C05CFDDE883FBCULL, 0x1844F0AD6AF2EB3FULL, 
            0x27411C7942C57C51ULL, 0x678D59D4485C0A1BULL, 0x6118CEE8212240DCULL, 0xF18C1E93D09FB31AULL, 
            0xB112531A2296627AULL, 0xEF1DB734F105E52CULL, 0x9A06DDC8BE74F734ULL, 0xBF55DB02FE2C1DD7ULL, 
            0x607A77FB2BD72CBCULL, 0xCED6D14E4905A49FULL, 0xB178EB0EA8CE75F6ULL, 0x0D1E2F19FEE130E8ULL
        },
        {
            0x632D03FC49A2B43DULL, 0xE4EB76870D1A50D1ULL, 0x5E5085B22F7EDC43ULL, 0xC2B67B32CC1A1519ULL, 
            0x573B45B4B2D8525BULL, 0xCD8B8D6E027C421FULL, 0x85EA667CFD685B15ULL, 0xB854BB551A781C4EULL, 
            0xD0CCA61C81AE5EEEULL, 0xFD438D60C7D1FA8EULL, 0x35EFAA2DA1B8B624ULL, 0xB1BB7D38013E0402ULL, 
            0xBC1471CB78683C05ULL, 0xF00B646482FAEA32ULL, 0xF3682CDC3A153927ULL, 0x84ECF7958691201AULL, 
            0x4DA048CFD1A14EE9ULL, 0x4D9872AB770DC45CULL, 0x6E294A1416FF2598ULL, 0x02F4D2F68DB0B279ULL, 
            0x2503D5517B01EEB6ULL, 0x259CA45E47B214DEULL, 0xC51D5D6FA7677BD5ULL, 0x41E6984383AB4AF1ULL, 
            0xCE012547CCC4EB5EULL, 0x4004C4FB8208CC9AULL, 0x2403C4F6FD3B9C2BULL, 0xC8C98EDF2B76991DULL, 
            0x358FF376387E14AEULL, 0xC580B67492BB8BEBULL, 0x899C453C7ECBB27BULL, 0x0F5EE2D76DA7EEF0ULL
        },
        {
            0x7DB52D2185269CA5ULL, 0x653C6F7F64181157ULL, 0xBEA8000F093739EEULL, 0xDF333B75CFA33168ULL, 
            0xBE5FFB42C38BA103ULL, 0x8D47737628608A27ULL, 0x6B54E5EF1E23DE62ULL, 0x3E49B9CD06AABC6BULL, 
            0x76CAC98E6696B1E1ULL, 0x948A7E001ECED9DDULL, 0x2721DBC59C860811ULL, 0x253148412A2D6996ULL, 
            0x0470844948D3285AULL, 0x292D07F440AD058BULL, 0xB04EA488DAAB7E53ULL, 0x3594D200AF4CC30BULL, 
            0x6B5D2B01ABBEDD25ULL, 0x307972EFE7D7EE15ULL, 0xEFEFDC1EF34ABD75ULL, 0xE8B971E42D2B953AULL, 
            0x506DE3E05B4BBE07ULL, 0x1723A51E2074E74EULL, 0xD32163FA70E7D4B9ULL, 0xE63F3CF7D83F0337ULL, 
            0x4DB2CEA7A4390771ULL, 0x0FD65D56E730B6F8ULL, 0x2A4385831C8C1E9DULL, 0xC78CE99B1769537AULL, 
            0xD7AD4D9697B8669FULL, 0xC6D5566871ABC83CULL, 0x1C25689D44703C38ULL, 0xAF2129FCDC44EB8CULL
        },
        {
            0x11E05808EC105CEBULL, 0x80E744F0DD587C0BULL, 0xEFCFFDE8A366653BULL, 0xE85EB40D30E56937ULL, 
            0x107D0E5133D9B5CFULL, 0xCABFC373AD38C786ULL, 0xD1B70117ABCD74E7ULL, 0xCF26B680FC1A5102ULL, 
            0xF778D8B992F8C332ULL, 0x4C38F64040F46269ULL, 0xB92E929CDC1606D7ULL, 0xD47A8D5024E01954ULL, 
            0xEF96A2226F0EF226ULL, 0xF4D0AFACD104719EULL, 0x27D71F102A4026BEULL, 0xA140BF98C0885EA9ULL, 
            0x9FA6BC6A20975C59ULL, 0xDB5CB046E1D6ECABULL, 0x5B3B4DCB98CC66B4ULL, 0xF8EA1779A875454FULL, 
            0x255C6335F067A700ULL, 0xBE4266BDA102F407ULL, 0xE63DCD2FE93AFED6ULL, 0xB90CA09586522587ULL, 
            0x295ACAC34489BEEBULL, 0x2D07A9BA0B566849ULL, 0x4C6406664847481CULL, 0x0EA5EE307E2C918CULL, 
            0x2596D3AA5DAA3155ULL, 0xABAF1885D0992F3AULL, 0x954BB2BFFCD2754BULL, 0xB95308F32FFD7E64ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseBConstants = {
    0xE7A3A30B75FCAB04ULL,
    0x796766F08F6FF5CCULL,
    0x6B6EEA840A50A697ULL,
    0xE7A3A30B75FCAB04ULL,
    0x796766F08F6FF5CCULL,
    0x6B6EEA840A50A697ULL,
    0x223445F14FAE7544ULL,
    0x77CC7546245FC85FULL,
    0x3C,
    0xEE,
    0xF0,
    0x69,
    0x5F,
    0x4F,
    0x8A,
    0xF4
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseCSalts = {
    {
        {
            0x209EFAC975541D58ULL, 0x8A48AE342CF7F9C0ULL, 0x0AD19162C6DB8B67ULL, 0x40F6D25C33F0342FULL, 
            0xB525478DDBFBCC33ULL, 0xDA28753F82CC3D22ULL, 0x2B40DE4F623D7C71ULL, 0xD468160284B0037AULL, 
            0x73C7673CA2706BFBULL, 0x96909B69BC26A6D9ULL, 0x101411ED1A6E25C0ULL, 0x85780DB627DF9700ULL, 
            0x24601C4377BDDDCFULL, 0x54DE6B8F045BC623ULL, 0x72026CCA244B87CDULL, 0xBB4D1BE415034B21ULL, 
            0x773AA182C539E97EULL, 0x99ACB56ADC002B5DULL, 0x2E1D8FDE86CDED83ULL, 0xE886EC67CF581C42ULL, 
            0xB7D914C2D8A6EE4DULL, 0x1E0169D9379C4564ULL, 0xD5B3B5C9708F167DULL, 0xA531C8AB931DB85EULL, 
            0x62E3BA47B87C7A2CULL, 0xD7F85354AFB56F60ULL, 0x06EE64B3D2973B23ULL, 0xDAADAFCED85FD23EULL, 
            0x373492255F9ECDB5ULL, 0x248AC136C1669A74ULL, 0x297128803B63CC39ULL, 0x79DD0AB44C6DD6CCULL
        },
        {
            0xAB92B2D73251EBE0ULL, 0x61A23E751564B8B7ULL, 0x20A2203B3AF845D0ULL, 0x52C4C91E82395109ULL, 
            0xC4CFCD76F422667BULL, 0xA329D64C2C1CE818ULL, 0x6DAACAE3C5E5D55EULL, 0x0C34DC3EF904AF5CULL, 
            0x5447022467A1C452ULL, 0x84EE54BDC00809EFULL, 0x221840006C602947ULL, 0xF055C2F061FCC24BULL, 
            0x74B705063C88BF7FULL, 0x824056342461003BULL, 0x4E61DB18B1F8FD49ULL, 0x5144B5FEE0FA36F1ULL, 
            0x5E7E23BB7C678C56ULL, 0xC9DD4B6E02870D63ULL, 0xCE4DEFAF74658B2CULL, 0xA049E9C7A61AAE34ULL, 
            0x16971006CB615435ULL, 0xE5955EF8A3EB2D17ULL, 0x88AF412F8CE63E24ULL, 0xDB2482308D4FCE3CULL, 
            0xCB2F7AA7EE19BCA2ULL, 0x57C1F0FEE9F94FA3ULL, 0x7C6478DD32C97CC2ULL, 0x9C7BE0E2FBC77A49ULL, 
            0x0F854F887BA3B38EULL, 0x5424C91A1764C48BULL, 0x6A6AB6CD6E3656E6ULL, 0xB98ACB34EB070064ULL
        },
        {
            0xD7C1C454FAF117DBULL, 0xC0C485C5FAB1DD4FULL, 0x843AF5361DBF5485ULL, 0x59CF44A1CFE83803ULL, 
            0x0E9B74D943EA83A1ULL, 0x1C896B53795EB329ULL, 0x77B477FAC45A1044ULL, 0xDC635036C9A0A67EULL, 
            0x790BD004F814E2A5ULL, 0x69DD549490DC318CULL, 0x10AB1B6866D19196ULL, 0x43ECE423A67CBDA5ULL, 
            0xB3E83EDAF018880BULL, 0xEE8D394AD0741F8BULL, 0x80239C5AAA20A484ULL, 0x662F71F69F2FB59EULL, 
            0xE420305A125AB635ULL, 0x000E510FAD7F1222ULL, 0xCC0D50EA3FBEB341ULL, 0x2F7D145F3530BF24ULL, 
            0x97794C3CF2F6DEC1ULL, 0x06CEBC46E0901A7FULL, 0x0AE0856325F126D0ULL, 0x14713CCB2B44FD21ULL, 
            0x65BFAEBEE5F7F2B1ULL, 0xCAB8F9D34AFE5579ULL, 0x321B9546B209F109ULL, 0x533B4C5A9CE6A890ULL, 
            0xC22BC176E48BD479ULL, 0x73C60B40AE6A4794ULL, 0x3B62C4EA93A16D47ULL, 0x64146402610B40ECULL
        },
        {
            0xB38D681987E3BD26ULL, 0x041CDC0F02F29A2DULL, 0x23366E8C8F332593ULL, 0x8348A47696145E80ULL, 
            0xB14FC0E61F31ECE8ULL, 0x58774A7EB4899847ULL, 0x37BD63B5A0562AC4ULL, 0x25C1938911273330ULL, 
            0xBA68D035CF5CD94CULL, 0x20248CC3B4C6C1D9ULL, 0xEF50E24A93C63D5CULL, 0xC9E8B770919609F7ULL, 
            0x26991791697437DFULL, 0x9A4AEE3221B51CF2ULL, 0x1C4CD686340481EBULL, 0x587755681CF11EF1ULL, 
            0xD32FF62350275DE7ULL, 0x3253881CEC6DF302ULL, 0xA5B11F0E8242A43DULL, 0x7DB1780345CA4A49ULL, 
            0x9F98A12E42D27CA1ULL, 0x46A8CBA95E51EB94ULL, 0x709CF48446206235ULL, 0xEB86FCE0ACF33116ULL, 
            0x4593A74C4E10FF3AULL, 0x1DF7668202178F72ULL, 0x0E474A936BDAFE3AULL, 0xEA59AFCFFFD22888ULL, 
            0xE40A78301FE1E3D6ULL, 0xD8729A1EF0D47934ULL, 0xB8E8720A1C8570C4ULL, 0x474A5D25F3658FE5ULL
        },
        {
            0x08560E10670BE5A8ULL, 0x577CF2A2E84C717BULL, 0x960D82D50048ECA8ULL, 0x5552A70C2AB44CF2ULL, 
            0x8630F59CDC6431B3ULL, 0x126144B3D1C91E3CULL, 0x696F7058496445CFULL, 0x36DC6AD399BDC498ULL, 
            0x475B3F418B64321CULL, 0x1FAF50D071A13E6CULL, 0x81CA2953A4CA4C9CULL, 0xAB4CADA2119AB784ULL, 
            0x81A786D4360CBE24ULL, 0x2EED36257AA87D09ULL, 0x2534EFC405E1D469ULL, 0x3D2E492ABDFE429DULL, 
            0xC5E86A86C35B93ACULL, 0x10828CF66BDAC110ULL, 0x81E0C195AC548087ULL, 0xC46632AFE9AB63EFULL, 
            0x519B73A941948A3FULL, 0x9072284D2CD119FAULL, 0x9D74AE117F0F776AULL, 0x4F895EAFF926BCB5ULL, 
            0x3304700799FDCFA8ULL, 0xCA874B7B45F7A887ULL, 0x2C58E0C412B1514BULL, 0x4AA24DFF68D96267ULL, 
            0xD6E3D5B3CBE80396ULL, 0xC97FC57496937AD8ULL, 0x1BDCB66F32834D46ULL, 0x35FDDC3300AB52A5ULL
        },
        {
            0xBADFE3A12298359BULL, 0xCBBE138820DE7B69ULL, 0x38F16FA3AFA7A1E0ULL, 0xEC3082118F3AF2B7ULL, 
            0xBB8792C05F0BA5A6ULL, 0x5893A0683E39BCCAULL, 0xF0F2E1B06F2F45BAULL, 0x1EA5C8B4FB4952EBULL, 
            0x68DFD2109035D40EULL, 0x5145B6990087E2C2ULL, 0x4697F27D6A20098AULL, 0xCA0CF9157552D211ULL, 
            0x97DD1FD7142A8402ULL, 0x891A5422A3F3EB29ULL, 0xF734EEA25C0E04BEULL, 0xEDAFA23EB1BF3111ULL, 
            0xCCA4D5FDED439BDCULL, 0x0C364BAC881F36C5ULL, 0x3CE7AABE78550097ULL, 0x907A02CB86769F20ULL, 
            0x18A6D470EB89D7C2ULL, 0x27FE33D6272095ADULL, 0x49AE6322583546A5ULL, 0xF97382A93B02BE0DULL, 
            0x7A70A2F945D01CA0ULL, 0x63D245270EE51562ULL, 0xE7BCF9B95BDE7AD8ULL, 0xBFF91D6E06C68791ULL, 
            0xDB82CEA387310537ULL, 0x6BB5AF870DBEB05EULL, 0x7DB672CF60BA27E4ULL, 0x2A6832B8C9671A61ULL
        }
    },
    {
        {
            0x238E2A604FD9BE40ULL, 0x2B410370F5BE4E71ULL, 0x8BC5B87F76B5F577ULL, 0x1C319F47B2BA2F9DULL, 
            0x9D132D19976F56A3ULL, 0xA06DC4F25469F44CULL, 0x0F60E287DC8D8A82ULL, 0x23A83F20260F9BD3ULL, 
            0xACA6E84FF4BF4096ULL, 0x493130BE9949F21BULL, 0x67AA22DB061724C0ULL, 0x3AFCF004C1BF03C0ULL, 
            0xC881B117763D62FFULL, 0x69B88E6CE3FE69FFULL, 0x4014CFB2FA2F3648ULL, 0x7DAE5506F3D8A6E5ULL, 
            0x350B0CCAFF7C8283ULL, 0xA2F16474AB362373ULL, 0xCFB5C4C11C530AE2ULL, 0x205BFC570F422707ULL, 
            0x15D310CCE4492F17ULL, 0xBFFABC76B664EDC1ULL, 0xB49B484CF29DF65DULL, 0x8CE9501AA4DC3836ULL, 
            0x73746DF83D7B50E3ULL, 0xE9DFAC9DDA870C99ULL, 0x480E5AAEBF52749FULL, 0x171C93240A854F52ULL, 
            0x500CB9E42A94614BULL, 0x121A30DE611CCF44ULL, 0x85026E10CB751108ULL, 0x9C66690C40769E34ULL
        },
        {
            0xD71223D3F6858082ULL, 0x114B73558B2541CCULL, 0xC99DB5D88D3AB07FULL, 0x08E4505F42C27568ULL, 
            0xEAE9482F4C8A0BFDULL, 0xFD8354CBA0AF5C8EULL, 0xF0E06D5B4D6876EFULL, 0xBAAD0D0F6DCB054FULL, 
            0x4EE2C7F62C180C23ULL, 0x784F3F6878915E7FULL, 0x6F0A026EF646A5FBULL, 0x664D7193713E54D2ULL, 
            0xF5E78F2CA6B6BF03ULL, 0x326B91D4D8C76882ULL, 0x9C4940EDD618BFECULL, 0x11972EE6B7E68203ULL, 
            0x1DF1C715AE18D243ULL, 0xE9B33830BE9B16ECULL, 0xA03EC333AFA2CE1BULL, 0x4469A0F269F7EEBFULL, 
            0xDCD4832B68F62D67ULL, 0x554D33EF38A95CF1ULL, 0x406D2E045EA29915ULL, 0x802FE70F7E6542D9ULL, 
            0x76AC48CD6877DFDBULL, 0xF738F2A7CFB17BC4ULL, 0x1E71713CAB5EFEAAULL, 0x550B3A8B0C2F8D36ULL, 
            0xF2F25DE11F21A8DEULL, 0x6FE562AFE73BD401ULL, 0x1F753864B3C1AF23ULL, 0x8BAC875F69AD23E4ULL
        },
        {
            0xEF80DE13ECA572FEULL, 0x40AF28076CF827E3ULL, 0x942AD8BFD48AD51DULL, 0xBE3DC44209768CCEULL, 
            0x49302A5AFCF197BDULL, 0x030830D87726C861ULL, 0xC92251AA9F9D62DAULL, 0xEA586E7A459B2CDAULL, 
            0xF34E2F012305225CULL, 0x27D828624F74C138ULL, 0x38C04B9E205E815BULL, 0x62E5BB8F3A18AE6FULL, 
            0x2EF87DA759A3A877ULL, 0xC6AB5CC7C7C83B78ULL, 0x4179E0C2929509C2ULL, 0x7C2E4554DAB16B6BULL, 
            0x85FEC1ED504F237EULL, 0x32EA2AEB1B75DC2FULL, 0xCE5119B9AA585162ULL, 0xD053A1757C7AC2AAULL, 
            0x6CF84B5DC45F7A08ULL, 0xCD92CECE24364AC2ULL, 0x11452345D5E2B727ULL, 0xC48909F716B5284AULL, 
            0x2D1278ED77FEAD6EULL, 0xBE8F2D0E7968409BULL, 0x9DFAEAA4F326E0FEULL, 0xA2378FF93A6C9006ULL, 
            0x06D01E8D9BC0FEBFULL, 0x4BF23866A3367A86ULL, 0xC142DFC9BDAECC70ULL, 0xB64616D9F3522886ULL
        },
        {
            0x5C0E9010AF553E32ULL, 0x88D43F8EB0C4147EULL, 0x9760E610BA95031AULL, 0xFFEF9145643AE478ULL, 
            0x3DBCDF5F15318BF5ULL, 0xC1CCAABC08AFF5F0ULL, 0x62A21EFA88050595ULL, 0xE4F619F15A4B2F30ULL, 
            0xBDF6FD420CC1F9ACULL, 0xE919AFA237942133ULL, 0x21D01B2AA1622DD7ULL, 0x91FBB8B9EB1A4D85ULL, 
            0x47A2FFD5FE1D5028ULL, 0x0D96E32636AE0A35ULL, 0x614E2B24657F72B3ULL, 0x0B339E0876549298ULL, 
            0x058B2D6CE78491DDULL, 0x1BC8E701F7DC1BFFULL, 0xAE60206C649D7A9CULL, 0x2EFE083A3AAC7D53ULL, 
            0x4A6B80949EBA2C5AULL, 0xF80E5EE71127814EULL, 0x932295F70F142624ULL, 0xCC105C6696304F50ULL, 
            0x9F95C81B64DF0725ULL, 0xC1D553C208F949BBULL, 0xC1A0C3266BB3D1AEULL, 0x0C83ED67591A6DC5ULL, 
            0x6D413B0EAF6108B0ULL, 0x06E25A9A90615D9EULL, 0xBD7FB388DE79B867ULL, 0xA912D133D2087293ULL
        },
        {
            0x438E86FF1BD58DF8ULL, 0x90118C4093C0DAFAULL, 0xA43145FC4D71736AULL, 0x1340C33C1004DF0CULL, 
            0x249835D895DF8D5FULL, 0x085F67DA934B8B78ULL, 0x10FDF30CE7BFE246ULL, 0x554595BFEED6F62BULL, 
            0x529C3C05B3C17DEDULL, 0x0800F3A94132FF29ULL, 0x09857BB7101DADBDULL, 0xC836471F0024ACCFULL, 
            0x595C64A5B78872A1ULL, 0xF908748922FCC280ULL, 0xA9C97212AD144C85ULL, 0xB62CCA237BE6D645ULL, 
            0x1FB4940661B6A93EULL, 0x87FB0EA4C258EDFEULL, 0xC9AF11AB52B5AE7EULL, 0x21BE773B66A43B6DULL, 
            0x2DED2B60B9A7C667ULL, 0x3D5FE24BDE7F0FC7ULL, 0x040DD29A5F16AEC1ULL, 0x8BA9E2A66B40319DULL, 
            0xCE16577919E3E488ULL, 0x091980E1F57BA73CULL, 0x550B54003A99B78BULL, 0xBA74E699AC658DBAULL, 
            0x3A9DFE6016633003ULL, 0x0A922C7320DADE08ULL, 0xADD7E3B310E11D50ULL, 0xB58BC25BAD7B4E65ULL
        },
        {
            0xA651D0C6164CDF1EULL, 0xF08D5AEF66887798ULL, 0xA6E31F6FC4431685ULL, 0x88ECF48EB3DE701EULL, 
            0x9B0CC2426901269BULL, 0xB4F34820D2C0E5EFULL, 0x6DF79D5D1DF99543ULL, 0xCEA4EFF9CFB74488ULL, 
            0xA6D7AB831A589C03ULL, 0x799E3CD77472FC8CULL, 0x79E5F9D5E79DE005ULL, 0x37C852F80885C816ULL, 
            0xBDF9E81DE37B7A32ULL, 0x12C97A1C7F8CE464ULL, 0x3B35BB7080FBBA73ULL, 0x1936DC79F45FE313ULL, 
            0xF6DD704349AE6746ULL, 0x5D397C5648FC4C14ULL, 0x7DBFA1AD1C2D620DULL, 0xDFBA338927E8ABB0ULL, 
            0x6FE54DAF4C1DE2A8ULL, 0x3C9E99C824B13272ULL, 0xB91A3FA402513B56ULL, 0x6881A1ABA7F1619EULL, 
            0xFC70C32F83A2E516ULL, 0x6B85BBB09E97FE7EULL, 0x4798EC0123708094ULL, 0xDBF5CEE79AEDB3BCULL, 
            0x996FB056BEBFC807ULL, 0x46C9DA7FE83FFBF3ULL, 0x945D86B838EBDFF9ULL, 0x2A3B04DB5571C007ULL
        }
    },
    {
        {
            0x15CC4C6E7DA339CCULL, 0x422169EC8AA145E4ULL, 0x51C9758A05BE92BEULL, 0xF9662292A2D7CD6AULL, 
            0x616A665198B0D4B0ULL, 0x45757734056BEC8BULL, 0xA0A9975EE4FABDF1ULL, 0x21125E1B7FB3D0A4ULL, 
            0x617253046B6243C2ULL, 0xA015FA98971A802BULL, 0xCA47036FF3FA95EEULL, 0x247C7C4252EC4E61ULL, 
            0x8546AB0F3DC8BFC3ULL, 0x909733BADD8A5BE0ULL, 0x6A8B617CC615EDF1ULL, 0x729E388852B860B5ULL, 
            0xAF8AF97047486454ULL, 0x14C4F8ED0C3FBCDAULL, 0xF6D6BC367CF3EF57ULL, 0x12C0FB00138AF9AFULL, 
            0xDEC242A548E9760CULL, 0x8783F7ADD45796DDULL, 0xEA6B630EE779C438ULL, 0x7C0D2160323E5C8AULL, 
            0xBD6A09816895A68AULL, 0x4D80D454DF8931B6ULL, 0x361E77DE8AF8FBADULL, 0x3872C84861CE9ECBULL, 
            0xE0EFE435FC741145ULL, 0xCD8DF00BDF2BA6B1ULL, 0x93ABBCC04A980D1EULL, 0x91F9A013BA68E5ECULL
        },
        {
            0x28795160A6A99A71ULL, 0x21ABB18EE7A97752ULL, 0x29FAB5B4B6AF19DDULL, 0xF9F15816CEE7FF6CULL, 
            0xAC2F2B74FDA647E3ULL, 0xCBC63DBF13A5AC6EULL, 0xAC85B1BC36791D2AULL, 0x62B3064F3584ACB1ULL, 
            0x60EB6991A2D4B064ULL, 0xE924F672F94743C1ULL, 0xD19A2A8CC4DA17E8ULL, 0x26E540E1FA7DA2E0ULL, 
            0x986FF9CFA6D5C987ULL, 0xEBBDD72816C19F5EULL, 0x2B4BF7B2DAEFB3C0ULL, 0xAC7F4528AD3347ACULL, 
            0xBD76A7EEA9AA8B1EULL, 0x0A8BAF4E023D84C1ULL, 0x32B8004A1C7F8E13ULL, 0x537D322D93755D02ULL, 
            0x0D18393C7E156B39ULL, 0xE174B0E9D31910CCULL, 0x535831011B672CB1ULL, 0x45728C6EFC7168FDULL, 
            0x4343BE2C56E2AA9AULL, 0x13C0571505CB6002ULL, 0x04DD539BF60A5674ULL, 0xBD8F4A4147F94A0DULL, 
            0x3633A08798D74922ULL, 0x41A55BAF40F400D7ULL, 0x7CC145DE6B043315ULL, 0xB2B38205FCFFC3FCULL
        },
        {
            0xD440A917A7C1B647ULL, 0xBA3A16DC1011E898ULL, 0x87126D6422BD2985ULL, 0xBA20106575DA2490ULL, 
            0x32FE72FDF1F9966BULL, 0x15056BCBC24A54B5ULL, 0xF3629D0A16BCB8A5ULL, 0x803666DEB0B6C864ULL, 
            0x9D28F9F37EFCCDDCULL, 0xC83C7DF528FC2864ULL, 0xA067BD25F32FBE12ULL, 0xC39C3C2F5A6019A6ULL, 
            0xA59CEE64CA24222AULL, 0xF4E876FD7EE63F4EULL, 0x079C1C930FD12D89ULL, 0x1FF3BDF9B2B71FEFULL, 
            0xB1C3CDD2AF47E2EAULL, 0x21084CFB4F80277EULL, 0x9B475453149E55D7ULL, 0xED3401B93000E87FULL, 
            0x793D538F52199533ULL, 0x461C5615579C4364ULL, 0x2F27C1FCF1D0F46FULL, 0x7733E00AF7917268ULL, 
            0x2CE846B454901B0BULL, 0x4CD1F49911212D98ULL, 0xF9FDDC6BDF98315AULL, 0x0C373EEDD39963ACULL, 
            0xAA26B5FDD06F6A74ULL, 0xA50B0D870EBFE57AULL, 0xEF5EB743D1A5E3EEULL, 0xC421622F53ADE02AULL
        },
        {
            0x7885AE7DB1DCB289ULL, 0x9FA31DD05A4FAD8DULL, 0x671D3D2BE88280E3ULL, 0x21F25A5F5A0E5412ULL, 
            0xDE1EF8FEF9E8928BULL, 0xBED088BFBC6F4F1FULL, 0x4E1402389B564D23ULL, 0x065AB09F91BFB6CEULL, 
            0xC1077FEDA9A7EB33ULL, 0xFA9385E91ACA6EB0ULL, 0x2E9CD41B97034ED4ULL, 0x47D62DFB4F7814ACULL, 
            0x055B54E855355DDBULL, 0xD12D19ACE7A5E2AFULL, 0x9A06AC71440DB8A3ULL, 0x06E869DD49B21C44ULL, 
            0x27AB98FDE9D43C25ULL, 0x8517C179096489EDULL, 0x5A6B5C073B1AF552ULL, 0x3C7E73EDCE5F5875ULL, 
            0x047AF2FAB6CC7AF4ULL, 0x7965115B5D9FE6AEULL, 0x46B830A263A28CBBULL, 0xF27A95AF083850A9ULL, 
            0xE3B21431D0755BA6ULL, 0x2A0CAD18A3AE5293ULL, 0x25CC94116CEB3299ULL, 0xAA6BCFAD5C47BFE0ULL, 
            0x0BED07738B49AE81ULL, 0xCD7CA74883803570ULL, 0x08471FFA8E486CE0ULL, 0xF14185D4791ECB1DULL
        },
        {
            0x2D8A5EF3EA5406DDULL, 0x7A40F0236BAB528AULL, 0x1312DFF2D746ABE6ULL, 0x253AB5E2D5AC799BULL, 
            0x8670AC606A1B61A4ULL, 0x163098C3853E5673ULL, 0x707166ACEDAC7268ULL, 0x57BE29BA1040AFE0ULL, 
            0xB8BF6595B046EA01ULL, 0x1110706D90C70702ULL, 0xBCDF58BD8187C5EDULL, 0x37CB476A1E8C39A1ULL, 
            0x8736F2CCB632F784ULL, 0x4A274C50A0E96CD1ULL, 0xB989CCE6C41660C4ULL, 0x03BDB7531F584084ULL, 
            0x03958A38642A0A6FULL, 0xD92AD88E952F06B9ULL, 0x71C1B01C126F13CDULL, 0xF5BA798A576CD0ACULL, 
            0xAC9367DEBF34CF73ULL, 0x28F98E1CE397820CULL, 0x665C291005457285ULL, 0xEA94E87DCCCBEFF5ULL, 
            0x8FDB1CA9C7FB59F5ULL, 0x6392565D12DEF849ULL, 0x1D3E1E29540C4592ULL, 0xC6606A8DD163B0F9ULL, 
            0xFB8ABF687B180DDFULL, 0xEF5EA61874E5A3D3ULL, 0xBDA409A6922EFB8AULL, 0x3FBAAA7100650F90ULL
        },
        {
            0xDF1EDA556EEDB77CULL, 0x835D589966132049ULL, 0xF06CACADD7D3E7FDULL, 0x75135C89DE06F471ULL, 
            0xB14578776EB6B09EULL, 0x077FD4AF691F592AULL, 0x430AB04805F6AF77ULL, 0x76D4EC7DA71CFB2DULL, 
            0x6D715216F183E55BULL, 0xD38EC9B20081897DULL, 0x2BF97AC32F9109B9ULL, 0xEB071914AF9F64C6ULL, 
            0x9CC743F3A82B132AULL, 0x870A1F544D693E35ULL, 0xB25D06CDF27FA5FCULL, 0x933242AF25A5FB06ULL, 
            0x3253937E20C183B5ULL, 0x8FA66970C9A4E209ULL, 0x704BD69DBED00BE1ULL, 0x1CED68C5A6BED7F7ULL, 
            0x49A40382650C7F2DULL, 0x0459217100AC0856ULL, 0x5822BB84CD10C79EULL, 0xD3FAD69403445CA9ULL, 
            0xA4897D051E1D0257ULL, 0xD038732CBC0D00D3ULL, 0x42864A1196806976ULL, 0x74F6607959A7F4FEULL, 
            0x2E5871DB2EFFFE77ULL, 0x57B847EF15650B1EULL, 0xDC549BA10FA2DB9AULL, 0xE149242B023F7076ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseCConstants = {
    0xCFD69CA587D646D4ULL,
    0xEEA2DC750B033D91ULL,
    0x0867C3903B5D991DULL,
    0xCFD69CA587D646D4ULL,
    0xEEA2DC750B033D91ULL,
    0x0867C3903B5D991DULL,
    0x983972C61F4D2AC7ULL,
    0xAB8460686D6BB1C1ULL,
    0x92,
    0x5E,
    0x7E,
    0x1C,
    0x5D,
    0x3A,
    0xDF,
    0xC1
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseDSalts = {
    {
        {
            0x2F37DAB12979BC3DULL, 0x28AD35CCA91B1C82ULL, 0xF9A43646C6BD649BULL, 0x414335CB6B996D09ULL, 
            0xFF7E8FCEBD1DD11AULL, 0x69C0D09001AF56FDULL, 0x79504BDFEE400387ULL, 0x6CC710751185E9DDULL, 
            0xABDC2A07592C8C64ULL, 0xC032C776EBFD2CD3ULL, 0x8FF53D780F179D99ULL, 0xB3AD6195FF8EFDECULL, 
            0xC36B356675C19E27ULL, 0xC9FDD8A483920AB4ULL, 0xF17BDCDB8276469BULL, 0x16B974FA491AC164ULL, 
            0x0AC90AFD6FFDED30ULL, 0x22DAADDFF2C7DB2CULL, 0x8873DA135A83E9C8ULL, 0xB610B2F466F0DB03ULL, 
            0x3FD763B771B703C1ULL, 0x7A7190E5978F3711ULL, 0xAB9BCEB1056C3C36ULL, 0x73DE062B093A6EDCULL, 
            0x628A04F672752D52ULL, 0xC892015AE0DCC3D6ULL, 0xA4DFE798D38463B2ULL, 0x5FE588EEBE36D118ULL, 
            0x5EFF8061A964C8A6ULL, 0x1B53D25503FB95BBULL, 0x9F7792E36AB492AEULL, 0x21BA01E016F2A77AULL
        },
        {
            0x587940138B733AC8ULL, 0xF56439D7B38FC603ULL, 0x462F43FE7DB30CDBULL, 0x3C1AB5AA6D6EC1A2ULL, 
            0xF409EDD98902FEF4ULL, 0xAB1DFC003FEBDC7FULL, 0xC1F2DB5BA234905FULL, 0x71E1265A43CD80BDULL, 
            0xC1B1F887F4AE1655ULL, 0xEEB4CCDAC266687FULL, 0x6C1354790E238777ULL, 0x0B130AA58B1295A1ULL, 
            0xADBBCB5FF4D8B1B9ULL, 0x604B1DF9F8450630ULL, 0x5EC4ECC0228BDE5BULL, 0xF6A08B526337D96AULL, 
            0x88F7CD8587BC44F4ULL, 0x149177EF2F63FEDAULL, 0x694ED1256EBBAF1DULL, 0xA5CCC1249E4BF88AULL, 
            0x614E53B4C7B2310AULL, 0xBE08D64CCA8A6EE9ULL, 0x4DBC071EED11FCE3ULL, 0x717838317AE0804CULL, 
            0x612CB9BAA3B20979ULL, 0x5CCC4D71073991D2ULL, 0x4A8673F6C674F120ULL, 0x47C29DF72574141FULL, 
            0xEF86294B8A85BD6EULL, 0x8D88B4B28964243CULL, 0x250519117F17FF1DULL, 0x85DDCC95B3423200ULL
        },
        {
            0x176076858F5625E2ULL, 0xB576C2C72840B95AULL, 0x0AB8505987EC1531ULL, 0x09124C5FE05218ABULL, 
            0x7EBFE0D6062843E7ULL, 0x89A495A70578CBCCULL, 0x91AFAC089DB25ACAULL, 0x6E8FB74F165493CBULL, 
            0x7D5B7082AE8AA9BDULL, 0xCFE2662FC1B8C819ULL, 0xA515B08EB98FAFF0ULL, 0xA7EB69F73B4C8B73ULL, 
            0x48056333FF0E5820ULL, 0xD948CA131AA218D7ULL, 0x430EF17DD19CAB23ULL, 0x953AA25D299215D0ULL, 
            0x35BAA71B961E033EULL, 0x4790C4A02D9166BCULL, 0xF8119223989F9F24ULL, 0xD088E57C0FC94C02ULL, 
            0xD9DEB0948AF7A532ULL, 0xF651805F4455CC93ULL, 0x401CD608A4B1A7E5ULL, 0xF50E03F7B8036768ULL, 
            0x3E6550D0DD2A507BULL, 0xF4BBB7649C6DD2E1ULL, 0x4A579722B1FC0DDCULL, 0x63F080EF65591A84ULL, 
            0x19A72AEEE6D6CE2AULL, 0xC7E490E12E11FAE3ULL, 0x9939FE2FD56ED330ULL, 0xB5BBEF03E50BB4F0ULL
        },
        {
            0x247CFC65F0769442ULL, 0xE9299269F7A8198BULL, 0xFEA6E175F3388D9BULL, 0x758214E5FCC4F359ULL, 
            0xB8BED361B3D4EC20ULL, 0xC4EA8C10F3B80652ULL, 0x49B3C568E2186C46ULL, 0xD09C86E36090FDA6ULL, 
            0xB5D13D427F62D7BEULL, 0xF70F81E74B9EC879ULL, 0x026CC9B048B29B5EULL, 0x14430DE60613C7B7ULL, 
            0x1733D9FF73B2621EULL, 0xA8B4BD81BE3694F8ULL, 0xFBB37AA3300DFCC6ULL, 0xB0C96A11D71A37ECULL, 
            0xD4E8AB095A923817ULL, 0x44FAD0348107432BULL, 0x8D938B312A716A18ULL, 0x9B379CDED088B302ULL, 
            0xAA16C36D3EE34FABULL, 0x0F1ED4AACA39F123ULL, 0xB5EED2C2B50EDAF5ULL, 0x792C3BA744D3ED39ULL, 
            0xDB0C2EB89A57D404ULL, 0xB3B5F34E81F6A229ULL, 0xAC8692546550FF93ULL, 0xB5B839FB0E5838A0ULL, 
            0xD9F5B0130E720A07ULL, 0x49565C0349A5E507ULL, 0x6FA18987972AF841ULL, 0x2559586AA05D9C08ULL
        },
        {
            0xED67DEF6BAE9E76DULL, 0x79FF6A078466C5DFULL, 0x58F08EF16D76E68EULL, 0x0975D36028AC9C2CULL, 
            0x7B0B8DC1A14DC734ULL, 0x87BFD6426B7019CEULL, 0x1BE60A9464227C1DULL, 0x14C60723F4BBEFB5ULL, 
            0xD517DF1FFB42F6D3ULL, 0x5770A744698BB44CULL, 0xA261656624928FD6ULL, 0x0FB1310AFC41FC2CULL, 
            0xDE7BC0DD09628FF1ULL, 0xD9ECC6140795FF71ULL, 0xD84DD13AD03CAD2EULL, 0x995A5DEDC1ACCBAFULL, 
            0xF8DB0FFA701259B2ULL, 0xDE9A81A3A5BC4E0FULL, 0x24318B5185A7D77CULL, 0x5AC6C099FB39D3F6ULL, 
            0x4966A018C7534797ULL, 0xACF168F368F8D188ULL, 0xE9FB8D27064E86ADULL, 0xB91AE5ACF628FADAULL, 
            0x2767CDC26738FCFEULL, 0x000FA21E10249FBDULL, 0xF2E054309C8914D6ULL, 0xD98ADE0C88E6C253ULL, 
            0x3A9359D911AA1D0CULL, 0xC41DC7CDF3D36813ULL, 0xF9B251DCFA6510B9ULL, 0x5D682E5E8EA59413ULL
        },
        {
            0x387F2F6B7736CF85ULL, 0xDC5912EFEAD363B4ULL, 0x33EDE94672201EC7ULL, 0xCBADA3CF3ABF979FULL, 
            0x444F399755230B64ULL, 0xAB8835452E788FD3ULL, 0xD8C9D9B3DEA24838ULL, 0xA2BCEA4D48194D69ULL, 
            0x7770914C083AC107ULL, 0x2833560C24731AD3ULL, 0xA0E6B56E4FE7A2DEULL, 0x56A49942A99AE60EULL, 
            0x914304B8B2E19F60ULL, 0xD510DB1190EC8DFEULL, 0x26650D7A81114ECFULL, 0x6853AC387F040511ULL, 
            0xED7BD8FFD32DA8DCULL, 0xD638F9B83AA0AD34ULL, 0xE6B8F784EF544AF3ULL, 0xD50967F8B3E4C943ULL, 
            0x85A55188867B1C7EULL, 0x4043C03B20AEA0BCULL, 0x3B418C1333AE0C67ULL, 0xA8499B5607CEA8B5ULL, 
            0x2FDF7C4E6E4FF210ULL, 0x2BF3B5F7105A7EF0ULL, 0xCD35304699DD4CA1ULL, 0xC058BA17E94D0CBBULL, 
            0x85729BC6BBBC21ACULL, 0x0947419187715330ULL, 0xFF0590653808CAB6ULL, 0x7FCB325D5062FF83ULL
        }
    },
    {
        {
            0xFA891244A7015892ULL, 0x2C160FBEFCA3B54AULL, 0xE9BE0900AEE54A2CULL, 0x22E2BF80799004AEULL, 
            0xA607D2F1ED2DB161ULL, 0x75C0A479E11C58E8ULL, 0x178560183A357E13ULL, 0x1C4FDE49C167B0B5ULL, 
            0xCA1643BD3539ED4DULL, 0xEC4E79F850D2EE2BULL, 0x1130F55D3AF3194DULL, 0x410AEA2B6E30B07EULL, 
            0xB63029612C5C4CB3ULL, 0xD778E493A6F64737ULL, 0x51B100F8F1F92C7CULL, 0x49519D4B7E017F5AULL, 
            0xD620FDD4F5CF991DULL, 0x864DB2C326D6E56AULL, 0xFEDF316ADAEFFC3BULL, 0xDA1B2A8E49D43A11ULL, 
            0x3BCBD2714A719A8FULL, 0xD9F9A976476A74F9ULL, 0xBD8E0FE1D021D535ULL, 0x5A84E3E452E58BCAULL, 
            0x26BC4597B85C7975ULL, 0x96364B4F5C647186ULL, 0x9EE7E86C8A928511ULL, 0x6BD2185351DAB8A3ULL, 
            0x82A279AA44D916AEULL, 0x6B1ADBFC1D5F1E27ULL, 0xE9024D00F1DEEB78ULL, 0x5749A5D89FA0466CULL
        },
        {
            0xDC1CDE8BED224E2AULL, 0xBD96C26EBDB13A5CULL, 0x2A276CCEB4FDAE86ULL, 0xE12B78DDF5B10B85ULL, 
            0x7EBBB2E7C988D398ULL, 0xB69FD32D1757F5F8ULL, 0x107A4B373211FD98ULL, 0xB127F7247DA24ECAULL, 
            0x7649D8676D817EF8ULL, 0xE70B19DF8B536AEFULL, 0x0DA24E4DDA12D75FULL, 0x25E0EBBF2ADAB0ABULL, 
            0x0D300BF751207368ULL, 0x879F58DD85278591ULL, 0x1AD1177989DC87ACULL, 0x2009B7CEC595F4E5ULL, 
            0x8D2EA713E4F004D5ULL, 0x26AC6B96B4EB1CFDULL, 0x31FF6187AA4071A4ULL, 0x08F96E81162D07D9ULL, 
            0x3C104D73F0A10CC2ULL, 0xBEDD3CD5FD46C015ULL, 0x5A0EC66CD3F98987ULL, 0x5EAF3B6A3CA60AE6ULL, 
            0xA87C2AD7432D81C6ULL, 0x017FCFB779D870A9ULL, 0x6A1396B2BBA09407ULL, 0xC981BFAACE4A2312ULL, 
            0xD46274906E09713AULL, 0x1DF775CA98F2EEF9ULL, 0x58107D1937EFAA4EULL, 0xB9DF93B7E585BFDAULL
        },
        {
            0x4B13F879204AA0EDULL, 0x0762C9719F10660BULL, 0x9AD167D7D5519917ULL, 0x50705326521A0D3AULL, 
            0x2D0C8393F8032C47ULL, 0xA6D67CE6D3D5455DULL, 0xFCB07F2DB4DF7290ULL, 0x9C5639F5C4BE68D0ULL, 
            0x99CAB127A894A899ULL, 0xD675CD27417E5236ULL, 0x3344131098B5D6BBULL, 0x7C9BA7E3C0404FCCULL, 
            0xB915B26DBD53767DULL, 0x02B0BAC976907BFDULL, 0x9400F93A469EEDBCULL, 0x2E8A19861BC7870AULL, 
            0x4E9789B1D32EE85FULL, 0x5BE383E6C2786E7FULL, 0x8751B299AEDCE27CULL, 0x3C33F049F086D231ULL, 
            0x131D68B157214790ULL, 0x50203746AB9431FCULL, 0x780FF29233A70491ULL, 0x773A7B24AD8D3BEEULL, 
            0xB6D4508756D8F3D7ULL, 0xD82B4E47642DA558ULL, 0x60EC82BE39E85BF7ULL, 0x617F151CEF584EBEULL, 
            0x2C83B2B3B7B8B7D3ULL, 0x08084E686B6911EDULL, 0x1D9278F51DCB6DFBULL, 0x45B3BC3BF22C61B8ULL
        },
        {
            0x7909F57B0B81F3F5ULL, 0xC18EDDE9A5F88DF3ULL, 0xE3396BB3E9B6479AULL, 0x30AE7F089F46C75EULL, 
            0x38F11B63D9C5F339ULL, 0xCF14CB86EDB878BFULL, 0xCA020DF0E8643FDCULL, 0x38A2D882D918F882ULL, 
            0x61A2B3A9A9A1A598ULL, 0xB034729CEA308B83ULL, 0x960F5395F63F6C53ULL, 0xA12075B8E49ECE3DULL, 
            0xF832D41779576F23ULL, 0x06AF687C80D0FC81ULL, 0x261CA58BB672CEE9ULL, 0xB9C9461DB7703A5BULL, 
            0x0B634EF2308ECDECULL, 0x272B60DC23A02C41ULL, 0x2A11FD167F0E837DULL, 0x8E89743EF27FE302ULL, 
            0xCB0AE336C4FBE4F9ULL, 0xA058A444AE577F5BULL, 0xD1F8295FF199A1D4ULL, 0xF5B98CF546E65488ULL, 
            0xAEF4280F54190F33ULL, 0x816509D516CE611EULL, 0x3D50B47489E6A692ULL, 0x63E71154D6843138ULL, 
            0x6048BDA7D2DDE8C3ULL, 0x08E6122463CF80E5ULL, 0x0EC124AFC4FA1BAAULL, 0xED3F0A82BDF5A513ULL
        },
        {
            0xB997A1D32ED142CBULL, 0x2EFD6D622C1A370BULL, 0x278871331C26B33CULL, 0x4E3F9BB1C52E3435ULL, 
            0xED216692B1AFDB85ULL, 0x81649D0AA4FE499EULL, 0x2506856965E29A17ULL, 0xFBBC5ACD9C462C11ULL, 
            0x38E918B1C08237A7ULL, 0x7EADF2BFC02FB7C6ULL, 0x3F3FEC7721ADC9B6ULL, 0xF3572E5A608BA291ULL, 
            0xEDE6810DD2746076ULL, 0xBE9CA41616A706C1ULL, 0x66DF3AB403F96CD4ULL, 0xBEE5D386BE4E3FCFULL, 
            0xB74F515E572E20FBULL, 0xC2F14647C7A22167ULL, 0xC6A28C4841BD1A76ULL, 0x99BE11A1DB8ED108ULL, 
            0x370750F9433DDB4FULL, 0xD599DB66D4AF3C86ULL, 0x4E779C1FF77C3BA9ULL, 0x778AA6FD4B7EE6E0ULL, 
            0xC8F82345A5E00761ULL, 0x7B338A1B6D5BDCFDULL, 0xBF16FCB1A687698DULL, 0x50AC561E71A5FC6EULL, 
            0x00C436831EBD9594ULL, 0x2C70C38C600FB935ULL, 0x3C1BD198B927A0D5ULL, 0xD0341BAAF30244F2ULL
        },
        {
            0x92823C384CEBD93CULL, 0x5865CD1E05B79368ULL, 0x0AFB4E6A5D94E746ULL, 0x3B0346E19BB561A1ULL, 
            0xFEDA21547D20DADDULL, 0x87238178FCAF3B6DULL, 0xAC59F07DCF07B042ULL, 0x07CB24435199AA4EULL, 
            0x89DD40D98DEECF80ULL, 0x9CD9BBF4849A3497ULL, 0xD628C9EA3CE28175ULL, 0xC18905DB7A62FBCFULL, 
            0xDB9FEDD2D7862416ULL, 0x16B0ECE4933F5111ULL, 0xC5AFB3E825DB3460ULL, 0xE3D18BEF938C782BULL, 
            0x17BF382630E3192CULL, 0xBD31212D5B519EA1ULL, 0x89ED1A1148194293ULL, 0x93A38DC224AF1C89ULL, 
            0xD2A53A67AC296849ULL, 0x3C4D9AD449B6B3BBULL, 0xDE583DBA9340395DULL, 0x689E4B5F44E8937AULL, 
            0x7FAA4CF29FE8EFC6ULL, 0xCE41841B72266695ULL, 0x919CD96F5D69FCDEULL, 0xABBE31C32215FC74ULL, 
            0xB1C8BEE8A95763E8ULL, 0x6E9D2D7F0BDDBA68ULL, 0xB71616BE12832B70ULL, 0xFF828935CC686D40ULL
        }
    },
    {
        {
            0xD0F444C5D8BE81A7ULL, 0x25BF2C5D0BF58CA9ULL, 0x8D530D7CE27EFB09ULL, 0x6ED6326C7402593FULL, 
            0x3E6AF2E3E116790EULL, 0xFABD7D1D5BEE0656ULL, 0xF9FAAEC92BD426BBULL, 0x30335745433CC27EULL, 
            0x6EE1D1A8B565FBABULL, 0xC041FF7B4BC27F81ULL, 0xF087CA3E1DCA00C8ULL, 0x1E85CB6FB205598FULL, 
            0x93EC629F002C8F7EULL, 0xE3127D2ED38826A4ULL, 0x2C67DC199022A36BULL, 0x774B0E8E2682EC31ULL, 
            0xFC7A1FE372261EE6ULL, 0xB9F6A0F4EF6F5F3FULL, 0x3AC2C7795BB1BC98ULL, 0x70CD2F16B61FB3D9ULL, 
            0x182D99133DBCB5F9ULL, 0xFCE841AAA3C93335ULL, 0x6A37C7D490BF90EBULL, 0xB3B1075EF51D08F7ULL, 
            0x3D9972C2191100E0ULL, 0xB93FB854F6A8D8EFULL, 0xA6B71805EDB0728FULL, 0x31D60F65ED7E3DBFULL, 
            0x4DE09FCD1ACE5EACULL, 0xCFD1104E366C4399ULL, 0xD3A9C8122FC70F9CULL, 0x380FD99D43A4FFEFULL
        },
        {
            0xFD6D0E3D78562EACULL, 0x051432F1B003B1ADULL, 0x400A97BBC2CAE24FULL, 0x3F58B7A4BA129BF6ULL, 
            0x173DC5B3E7B91375ULL, 0xC828D2F98C1A73E6ULL, 0x29A00BF10791FF0AULL, 0x7C76757621F35E13ULL, 
            0xD9EFF1898235F016ULL, 0xA0E7630ABA84A432ULL, 0xF7B761DD8A272346ULL, 0xD41E8F658059E973ULL, 
            0xBD46161FC27254B4ULL, 0x164C41599D95D1D1ULL, 0x41C8638F0492573EULL, 0x28F9ABA4DB6A05F6ULL, 
            0x6DE9586E6BE3701BULL, 0x63687F00342A88EBULL, 0x63CCAAF3626B42C5ULL, 0xB6E6905C0EBF28C6ULL, 
            0xC07EF1F314A6E8D8ULL, 0xD17AB333798D31DDULL, 0x008864A40432FE6DULL, 0x382EC27703C2A896ULL, 
            0x57FAE6B769A5D089ULL, 0x82AE00ED42316DDCULL, 0xAB798763145895D1ULL, 0x12FFCE3A581270D7ULL, 
            0xB1C82C90638B327BULL, 0x18253EAB49C4843BULL, 0xBA75E4A993F79E09ULL, 0x3C44F3CA9CECE41EULL
        },
        {
            0x58E3DC763C4A3975ULL, 0x6D55BA987109646DULL, 0x176BD2E1467E9A5DULL, 0x72A932B66E2A7265ULL, 
            0x0E873E1B026AC55AULL, 0x819971C0C2631C2CULL, 0xAB6A1347BC80DA43ULL, 0x6EF042826A0132AAULL, 
            0x378F5137829B05B0ULL, 0x05779BDBCCEDECC1ULL, 0x4EF596288F12DF27ULL, 0xDE3660FF73F21A08ULL, 
            0xEF8A50EE509CAC85ULL, 0xB47E038323FAD845ULL, 0x50920A3378665A90ULL, 0xE9479E64622DB979ULL, 
            0x2876A85B95B8FB9EULL, 0xF735009587B5856BULL, 0x0BBEF4DBFA430A40ULL, 0xE387375913436A3BULL, 
            0x30ACB4612ED7104AULL, 0x641BFE5797A19320ULL, 0x62A88C531676DA1CULL, 0xA3E9FE641B361830ULL, 
            0x1C9EDE8383D83A7DULL, 0x1B626F4840C47D86ULL, 0xACA223021BC57E8DULL, 0xF60A3563B5727BEAULL, 
            0x8383357EA1246577ULL, 0xDCBEB228C2EFC599ULL, 0x0652E9B7B2DF8671ULL, 0xCBD27C66E17FAB60ULL
        },
        {
            0x035B2ACB9AABCC4CULL, 0xF81F0BD2A821E7D0ULL, 0x738CEAADA82E1DB9ULL, 0x21C5D0266F255C09ULL, 
            0x5BBFB2AAEBA17EC3ULL, 0x3AF7A10095F6C437ULL, 0x117B7FB10FC63476ULL, 0x4957B1E4273F38B2ULL, 
            0xA38F4E78E651DB01ULL, 0x0548E5F703F1C2DBULL, 0xDD845A1E077B7F76ULL, 0x4262A34DE08C90F4ULL, 
            0x10291850375ADBA9ULL, 0x29C4A2A1DA148C55ULL, 0x64E9E7D6AE8CA31DULL, 0xEBE77ACE5AB1220AULL, 
            0x0B0E75D99F010702ULL, 0xF2E1D3090D15BEB2ULL, 0xA1D5DA17252F88A5ULL, 0xFF8505A31CE2E46CULL, 
            0xA5DEFEB516B2C03BULL, 0x4039EB72A4D45942ULL, 0xE413B41596C6A4E0ULL, 0xFB2E0E153B3CEC5CULL, 
            0xB6D9839CBFCAD6D8ULL, 0xC480601A34126C58ULL, 0x76EC92115006D746ULL, 0xA20BBB9DCFD81301ULL, 
            0xC339E23FAD97E790ULL, 0x3FB8BC6EDD1AB533ULL, 0x3F48ECF5CE981E26ULL, 0x1A7248C9F522E5BBULL
        },
        {
            0xCF651BD0732587A4ULL, 0x2A14A40E9D2299CFULL, 0x34D080440A42462DULL, 0x0CD6BD35452F755AULL, 
            0x72654A77B6CAACF2ULL, 0x50884260ACC2386FULL, 0xA055BF10C382F534ULL, 0x1A787AE67542784EULL, 
            0x6AB0B423A65782D4ULL, 0xC402059085C28448ULL, 0x2EBC58F28C0655B1ULL, 0xED0C10B140EC0CECULL, 
            0xA4FF863C6675D846ULL, 0x92844C2DED0AAFCDULL, 0xD4D6E37CA096A6C5ULL, 0x48CA5228A0DA489EULL, 
            0x8DB9E57DBFC3BF78ULL, 0x2101ADF9829237D7ULL, 0xF586FB803D5C7C2EULL, 0xBEE1B5CF99D64D4DULL, 
            0x1AC4996BEDA67F99ULL, 0x7738D0AC6AA10990ULL, 0x72E47175A953946CULL, 0x6EFB8BCDC07B8FDFULL, 
            0x27E025EE50C25AA7ULL, 0x6DB80A6C76665610ULL, 0xDC4ED13B74B6AFFDULL, 0x6E39B4015EC774C2ULL, 
            0xCBAF605654382889ULL, 0x10B9416BF1C511DDULL, 0xC5E9C513D9DEF278ULL, 0x352ADCAA0BCD98A6ULL
        },
        {
            0xB7DAA462DDC9A8A4ULL, 0xE425DC2093FC011CULL, 0xDB5520F14586ED78ULL, 0xA9B01672B6252798ULL, 
            0x25336A04A3D8D79FULL, 0x41B745F72811D976ULL, 0x1BAD6D0773910B8CULL, 0x895AF2429510FCFEULL, 
            0xA3B1B7095E31E2CEULL, 0x622C5D9FC2C18EFEULL, 0xCE8589D85869215CULL, 0x60F54595124B6E23ULL, 
            0x175B418359ECD4E0ULL, 0xCCD4C2E4AA8F32EBULL, 0x14247D5D2498F63DULL, 0x2507E36D7DDA2ED8ULL, 
            0x3148F0E1A8CD8241ULL, 0x7346FF88640C173EULL, 0xCAE742F9C86975D3ULL, 0x0E0BA4A2881CE8D7ULL, 
            0xE9775A35A025990AULL, 0x146C8B6B979B005CULL, 0xAD0A15BCB2B39FFAULL, 0x257D6A7B4A8F4603ULL, 
            0xD66E326502E691C1ULL, 0x5C4572016DC05DE4ULL, 0xBB47E848D37D2362ULL, 0xD8B67A4F5B46568FULL, 
            0x0ACE9ACFEF5B48C7ULL, 0x7B7FEA6A3D7ED8F8ULL, 0x371747564E6B73D5ULL, 0x487A2ECED2A66175ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseDConstants = {
    0x98AC94F3B397D9F1ULL,
    0xB3F09328CB670256ULL,
    0xDAD31C69C86D6B85ULL,
    0x98AC94F3B397D9F1ULL,
    0xB3F09328CB670256ULL,
    0xDAD31C69C86D6B85ULL,
    0x5DC6E7D7C7C7CB88ULL,
    0x89F5F69317653ABDULL,
    0xEC,
    0x33,
    0xBF,
    0x78,
    0x45,
    0x16,
    0x71,
    0x1A
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseESalts = {
    {
        {
            0x78499DC895FC16B7ULL, 0xB0ABC34F008F2EB0ULL, 0x2829A54340762203ULL, 0x2BA4D0160A4703BDULL, 
            0xB54AC368E611B934ULL, 0xC21D465E141E284FULL, 0x0F4DAE2487E571EFULL, 0xD35F4600CD48F45FULL, 
            0x028C94DF7ECAFB33ULL, 0x151F37CADDD8AA42ULL, 0x5F5502F85CEB0CB2ULL, 0xBBAA7F0FEB377C35ULL, 
            0x9E6F803B56A69C6EULL, 0xE1EA6D79378F77F7ULL, 0x976BEDEF78999BB3ULL, 0x65E47224D62A4F6CULL, 
            0x549283CDDE26D1FFULL, 0xA2D0C5BF588B64DDULL, 0x4BA697714B3B4137ULL, 0x4B63A07AE32BADE2ULL, 
            0x2122A1236927A733ULL, 0x6B5EEA68DAB1B4EAULL, 0x2379550E05708365ULL, 0x690B615A104B14BAULL, 
            0xF0AD7C152459C67DULL, 0xBEF2344E5D51D1C5ULL, 0x4EBA4A4749BC4044ULL, 0x250B18FE7C95D96EULL, 
            0x7B3AD93A9B45D839ULL, 0x99699E96D7F2B584ULL, 0x289DAB73718078CBULL, 0xF59759AF36004967ULL
        },
        {
            0x240CAC6597B5F47EULL, 0x78F2D77ACD956D4EULL, 0x4E2BBB930037A280ULL, 0xC63C6D643B84716AULL, 
            0x8F497ADDB83ED400ULL, 0x1D529D8A9A647E2DULL, 0x42DDA9D78E504BF8ULL, 0xE346F915AC549C76ULL, 
            0x0B15644CFF4E0EA1ULL, 0xDC846020B4ED5EC7ULL, 0x6D7A08532AE009ACULL, 0xF1B5CE72517B4FACULL, 
            0xCD772FA84C87EEF0ULL, 0xD756E0916C4D5A86ULL, 0x1FC057CE942FA50FULL, 0x12FDB489CF52A247ULL, 
            0x0EAD6F878FFF5A7EULL, 0xB86DBCE52B1BD392ULL, 0xE285ADF2EEF6CFDEULL, 0x36264661116C3EAEULL, 
            0xC4DD90627D29D299ULL, 0x8D00DDBEA120B1B0ULL, 0x1D6C9FA4FB1F4013ULL, 0x14E58FA757A03D04ULL, 
            0x5DBD65CC01896FA8ULL, 0x1868DC0BB933F709ULL, 0x5F39249AAC182C58ULL, 0x4C21E1ABD924A5C4ULL, 
            0x0322C1404CE055C9ULL, 0x6ACDD7FFC6DDE18DULL, 0x64617EDBB8B7B8FCULL, 0x4D08916A655098E3ULL
        },
        {
            0x7C444FF0500D81FAULL, 0xA6ACE050185294A6ULL, 0xB69C2702D865E9C0ULL, 0x54F736616DE4A131ULL, 
            0xACE81A4C26E4A3B9ULL, 0xA5C7A78A72C5902DULL, 0xEFFBC0BFD4B70A10ULL, 0xD5CD7F145A1BE70FULL, 
            0xFA2C085BD487B633ULL, 0x11C6B7FF5DCE54AEULL, 0x3DCE95EEE64F96C4ULL, 0x391E38D8CBD9E909ULL, 
            0x4D9B2FDB044FCD27ULL, 0xDD2F66CDE1E9AFFEULL, 0xEC6F78DDB8E7DA6AULL, 0x7314238EEBBF0932ULL, 
            0x154BD4E58905C0BAULL, 0xD47279C1F310E817ULL, 0x5E9CFB5A7E66B966ULL, 0x2CCB44748990CA77ULL, 
            0x20EF21CF56AC5E39ULL, 0x0E777883468D7043ULL, 0x2E6C11CF57DFBBD8ULL, 0xFC74AECCE318C289ULL, 
            0x8B941EEB68EB5A37ULL, 0x92E0837286F6CDC0ULL, 0xBBCE70D5DFAEFE33ULL, 0xAAD9CD5152C93066ULL, 
            0x6FE44C0005F36B43ULL, 0x555765F9BAFFC314ULL, 0xFAE1884BAD190DD9ULL, 0xA936A25C414075B9ULL
        },
        {
            0xC61B7F7B2BBE0172ULL, 0xE1F83FD71242D922ULL, 0x6B3E50D75558E909ULL, 0xF4CC6D7EB8DA93B0ULL, 
            0x7281868A3CF0A229ULL, 0x26583EE15C57FFC8ULL, 0x5F19C0436EA069D8ULL, 0xFCBD33CF6E891368ULL, 
            0x0F06C897D08ADA37ULL, 0x11CB3CA1894D7DA9ULL, 0x85281C2A7EA573EBULL, 0x2340B073B1973AB0ULL, 
            0xC189671DA370A065ULL, 0x2F1D4290922578B7ULL, 0xB143744AAEF07740ULL, 0xCBBEA129C2474C57ULL, 
            0xA149374D0BE22214ULL, 0x1A921B2B1BE987A8ULL, 0xA70C5F7A56ACE657ULL, 0x91CF3DEDC4885F42ULL, 
            0x932B0461654D383FULL, 0xB5072C8B02FE5C76ULL, 0x3FCC55146186A7A1ULL, 0xA1D4E87C9BA86E7FULL, 
            0x7E8B652FBE69653CULL, 0xA656C822139BDA4AULL, 0x8B443CFED959A626ULL, 0xD7F144A6BB53D5DBULL, 
            0xDDDD78294A2703EFULL, 0xD58D3776008C7586ULL, 0x04836FECDEC6119FULL, 0xC6548844034C47A3ULL
        },
        {
            0x77ECB6DC15B7DE09ULL, 0x283889E1F1DED990ULL, 0xD97BF7877A14603AULL, 0x5DE9E5E9B051BBA1ULL, 
            0x141031C390661EF9ULL, 0xFA9D1E0ED972D0CEULL, 0xA59C70B22841E863ULL, 0x2FB307EC1630A160ULL, 
            0xBC6AE42967887FFDULL, 0x702CE831FFE695C9ULL, 0x7A21DC2AC122B7DAULL, 0x3DBE5DA42B4A7B1AULL, 
            0xCD8B33E8169014E7ULL, 0x25EB8A0151C6C819ULL, 0xE31FAF6EED8E81BDULL, 0xD7A00FFF36DB47D1ULL, 
            0xD820954049736B6FULL, 0x169A3C0D0823E3F5ULL, 0x65CC88AE648828B7ULL, 0xE749CFAC8998B059ULL, 
            0x57B25109E348908CULL, 0xD943710BA1E0DE80ULL, 0x7EE600FD6F2FB30DULL, 0x6D2E1D0CDB0FDCC7ULL, 
            0x3E9303B3B3176179ULL, 0x0EB42C46F5FEA087ULL, 0xDAB7174D2C539BE0ULL, 0x0230AF1EEAAFD7EDULL, 
            0x5C85E45AEEB6DD63ULL, 0x5EF13D830CFB8375ULL, 0x07C7F594C15BA2D8ULL, 0x126875FB50531A2CULL
        },
        {
            0x6B72722DD282B75CULL, 0xEF2EF7E62CE91076ULL, 0x86B6773F4DC2DE9FULL, 0x20B22A8545CBF0ACULL, 
            0xD7D3808A2D2EC5C0ULL, 0x3FB30A2A2A5B58B5ULL, 0x8A1FEE9683FB1F28ULL, 0xA59F5E613ECBBCF8ULL, 
            0x042487FFBBF9D156ULL, 0xE94B1C32FA4DD856ULL, 0x9E3985BA9D8E540FULL, 0x99DE6CBC92F5FCBBULL, 
            0xF757A7BBD78A7A7BULL, 0xC2D4816DB91B25ADULL, 0x24CA1581BA499A35ULL, 0x44F1DDD7EA3A92A5ULL, 
            0x6485D6147247D60CULL, 0x8C30927787557C76ULL, 0xFE64759FC54AE3EDULL, 0x2766854AED1E8783ULL, 
            0xEAA2DC0918D96AD0ULL, 0x1F38CDAB30EA4CEAULL, 0x16EBA1239B600C01ULL, 0x0079FDB2B316575AULL, 
            0xBD90F2E894942ADEULL, 0x27018BE361D54D69ULL, 0xD2168FFD81584282ULL, 0x2173C8AC4164B34EULL, 
            0x72C6F31B164667BAULL, 0x1AE9AD6F8698E22EULL, 0x0EBCFB17EEDD9A51ULL, 0x3B9142B7EB403086ULL
        }
    },
    {
        {
            0x26C6798FB5BF15B2ULL, 0x62BC79411E3E80D6ULL, 0xF59528C2DE24F42AULL, 0x7647BF8F564ED765ULL, 
            0xD3817D06D454DCA4ULL, 0x8BC4E753E8D7D028ULL, 0x493A9F633560CD40ULL, 0xA32C41C82EB25456ULL, 
            0xFEE33F867E63493CULL, 0xC576A4E877AFFD29ULL, 0x049DE4EE339F8F7EULL, 0x7EB3977FAD59ECD4ULL, 
            0x2B74191765CABBF4ULL, 0xC28F81C1182B5EA0ULL, 0x590FFE341136CEF0ULL, 0xDF0DE5925FD32E2EULL, 
            0x7934E9411C4BC85CULL, 0xC35774B4CEB1A0C7ULL, 0xE22267DABC954AAAULL, 0x7190F0549E141307ULL, 
            0x0ECB6A6D4A46BC45ULL, 0x32D7950F477F0D47ULL, 0x05696F755BD7D086ULL, 0x2A9155D9F9F8C271ULL, 
            0xA7FD4E4022799CABULL, 0x2B9BC5E74A980917ULL, 0x9A522D2DD834FEF1ULL, 0xC3AD265A692833C1ULL, 
            0x09D7D1E5287FFE08ULL, 0x3074C26E0267190CULL, 0x5B5BB8D24CFCD42DULL, 0x1A1BC17AA1D8203BULL
        },
        {
            0x238A9298CBB69080ULL, 0xD637B262917D0A03ULL, 0x0C2819CFC3CE191DULL, 0x68DFDAE4E083BC19ULL, 
            0x08FC43AF61FAAB73ULL, 0x098637963213435FULL, 0x7021AAA63E9E00B6ULL, 0x58274BF8050C4082ULL, 
            0x3669E2E356FF6305ULL, 0x74286CE57B5943E8ULL, 0x345E4F84AFBC74E8ULL, 0xDD3CF84E9CA4AC3AULL, 
            0xA7E35DA0BB513536ULL, 0xE0EAF366D6E11686ULL, 0x71FC588886AB9F83ULL, 0x9D4F50439A237F2AULL, 
            0xBA5C494CD7B9FAAEULL, 0x1A1EA27C68D62188ULL, 0xF4BBD2782BE078E9ULL, 0x9629E406BBC4E281ULL, 
            0x0BCE9CF7584CA675ULL, 0x9DB383855DDC7C37ULL, 0xFBD14FBB6DDF5AC4ULL, 0x6A663DF9F6A22F38ULL, 
            0x7D5ED19D00939923ULL, 0x45BC5F3382952B64ULL, 0xF84FF1ADF32558DEULL, 0xED9F326B1E088585ULL, 
            0xB78955F713F76669ULL, 0xEE97254B9E98426EULL, 0x8B81386F01A75E16ULL, 0x5A74E91C52724136ULL
        },
        {
            0x70B7173EFAEE2B3FULL, 0x6FF8706F4BE9BFC5ULL, 0xF3E81CC590C0628DULL, 0xD9DC50F2A46DF9B8ULL, 
            0xA9893BD840A7060EULL, 0x73DF1DA25A948E17ULL, 0x5DA32FC634C1A06BULL, 0x7446BAC4BF3D2EBAULL, 
            0xF22AEBA21AFD51BDULL, 0xC169B4075BBC5DCEULL, 0xF4BC936A11F0EBD1ULL, 0x3BD5099BE119D1EBULL, 
            0x16FD6EC742D75646ULL, 0x913114772BAB5287ULL, 0xFD99AA171246E724ULL, 0x700F59CD9BB095A8ULL, 
            0x39C589F686BFF2F0ULL, 0xEA01244F24A12FCAULL, 0x0C19092D5C8A15E2ULL, 0xE2DE18E851732AF0ULL, 
            0x033B5196FC92401CULL, 0xD9DBDB617D2E8854ULL, 0xDEC861753398F7EEULL, 0xEDC45971BEE8F7CFULL, 
            0xB0A90467B3CCC9A0ULL, 0xB9EC914CF1425A9FULL, 0xA2FD145DFB0095B8ULL, 0x4C5B3E2EF5768D13ULL, 
            0xA8A8D4EB4FE10AB7ULL, 0x30AB5122BF74B7C0ULL, 0xAB2FBC14EA8D5785ULL, 0x438E8D7CBC93AFCBULL
        },
        {
            0xFC1C62B39E889E5AULL, 0x3321EFDDC6CC57A9ULL, 0xEC012D4124BB4D85ULL, 0xE0B51C47225DF636ULL, 
            0x7B75DF715E63243DULL, 0x08956449CC517978ULL, 0x89AD425E5BFD4D3CULL, 0xC0A3E3F4C11FB685ULL, 
            0x2948653F42FBADABULL, 0x396A2295FA1ACFF1ULL, 0xCED7C28F77A9AE07ULL, 0x3AFA3CA82E90C5F7ULL, 
            0x354A2DCEA946920AULL, 0x8F0391158380FDEBULL, 0x34374F4113EB517CULL, 0xD11FC4693EA566EDULL, 
            0xE6E8A8E7E270BDC8ULL, 0x0554F5E05138B49AULL, 0x877D3750B9EDE67CULL, 0x91866C820D843406ULL, 
            0xBACAF6AFD75F3188ULL, 0xE2576E231BBE92F3ULL, 0x41BCFCFCF45D12ACULL, 0xAE3AEB4CFEAEB850ULL, 
            0x523BC6E98E636FC5ULL, 0xB300F50B96AF2042ULL, 0x7C23BE23C3D9CBB1ULL, 0x3FD9978EA6C350B1ULL, 
            0x62020D730F93DE99ULL, 0xB0C23D9E37B1C9D3ULL, 0xAE44DE29159BD815ULL, 0x91812ED9E3098E6DULL
        },
        {
            0xA8E9C357D0651745ULL, 0xBAF27325572378D7ULL, 0x283A950726C85E4DULL, 0x6C78D389EDF29873ULL, 
            0x16302ADEB1396C48ULL, 0x96CFCC1255FC9E50ULL, 0xD4C210C2B8554E81ULL, 0x720F5F0C789AFA19ULL, 
            0x7DDA6BA9DCA31CA6ULL, 0x43DAE38AB7CE6CD5ULL, 0x9BF05BADF621A647ULL, 0xD438D820362BA56FULL, 
            0x4D6605A2C1535B61ULL, 0xEC0F005B324D070FULL, 0xB3E608257C77CA46ULL, 0xC313A958973D613DULL, 
            0xF704A544B58A2941ULL, 0xE50CB9DB4102F4C2ULL, 0x04237BEA193E587FULL, 0x78D2F77671F8E2B9ULL, 
            0xCEE2A3206FA21C35ULL, 0x5CDF37687FC063CBULL, 0x91D5940C01359F8FULL, 0x134540AD1B4F3BB8ULL, 
            0x2CA1581636BA0D59ULL, 0x44C87944C7DC6BD0ULL, 0x1DA518F9A7F68C3FULL, 0x68AB01F04095C44BULL, 
            0x416FF9D9E0C0901BULL, 0xF7358C7B8B514F71ULL, 0xED2B501E164EB21BULL, 0x485E9F9DB2EB6D97ULL
        },
        {
            0xF58C951EA5A98C21ULL, 0x8D3AC0F3CF494447ULL, 0x87E817219D56AB4DULL, 0x3AA768F6D97C72EFULL, 
            0xEE3435C092F45A90ULL, 0xDCFEF402B8D7DAF8ULL, 0xE786CA5022A2CC77ULL, 0x3166DC7E0F891D82ULL, 
            0xD814AE40E530DFF1ULL, 0x9B234C2748641434ULL, 0xC04C65E71B093226ULL, 0x39AFABCAF0F2E383ULL, 
            0x3A1AEE9B501820D8ULL, 0xBA9755E03F45417DULL, 0xB928D0D3EB5EF4D6ULL, 0x7A4925C4DA4511D6ULL, 
            0x69433DA5F00E4C3CULL, 0x35D00E14F46FF4B4ULL, 0xCB2F63E6B0A76D96ULL, 0x732D23EF350E37ECULL, 
            0xD23C1A6BDD9E1A6CULL, 0x3511F655B8FABB6BULL, 0x2019E0A84BE67ECAULL, 0xAC0D1B96AD211380ULL, 
            0x11FFBC5F11E8F8A7ULL, 0xF20D48E150C46C30ULL, 0x3D6A6F0E0E07D862ULL, 0x9928441AC60A4143ULL, 
            0xF0941103C196439AULL, 0xA29075B26D21CE2EULL, 0x778857CAF693CD28ULL, 0x063014CC2CB3AD23ULL
        }
    },
    {
        {
            0x6C49682404919EF0ULL, 0x160526930C696DF3ULL, 0xBE13C151E09B5367ULL, 0x020795A38FCE7A72ULL, 
            0xDCA0A354E35BF8E7ULL, 0x0DA413E9A031B0D7ULL, 0x3F6D9FDC8D9A3464ULL, 0x0722D849C8664189ULL, 
            0xA761D4C9408888DFULL, 0xF0BA4C4BC803E259ULL, 0x11BF8F1D1FCB492AULL, 0xBCFD16AD4F88AC29ULL, 
            0x6A4A557083F8471EULL, 0xBDA53E3EEF2D85AFULL, 0x7383725EEEA687D7ULL, 0x048E74F66638E38BULL, 
            0xE8412EA4B59C2DFAULL, 0xFDCD71C362F9E7E8ULL, 0xEFF84B21B2B04C1EULL, 0x8962CC3C690636F5ULL, 
            0x12FD9FA2CEE4BB9BULL, 0x73347E83E51CE0F8ULL, 0x50F631F0D82DEB3DULL, 0x2BDA66195F5D9E60ULL, 
            0xA49DE3B56D7D6EDAULL, 0x0A7406BE70BE356CULL, 0xD734D0CBCE666544ULL, 0x072C4BEDD9CA614CULL, 
            0xCE9EF2A1BA4A7D0FULL, 0x42102DAAA9F59BFEULL, 0xBF6A8E2C1587F822ULL, 0xF99CE5C170CBBBA8ULL
        },
        {
            0xABA77214F927D7FCULL, 0x8E6E8E1E9E8314E9ULL, 0x63A97DD4FB926453ULL, 0x053865C14825EA42ULL, 
            0x6A1DAAD8E9FDFBB4ULL, 0xCE9EBC64B4D1C2ACULL, 0x772E1F6E96B272ECULL, 0xBEBD69F7C53900F9ULL, 
            0xDA5E6817C543BF51ULL, 0x5318E72494D17503ULL, 0x019250FB81B4CC12ULL, 0x0626B3F8CBBB1293ULL, 
            0x60AB95597AD714E3ULL, 0x7E598ACFD59250E5ULL, 0x70B5242A1C451078ULL, 0xC7C23C1F179AE6C2ULL, 
            0x90D229749AB42F42ULL, 0x11B1310364454329ULL, 0x2B1B5A7DF698065AULL, 0x2878BE8114E3D0E4ULL, 
            0xB140DE475550976DULL, 0x08A96E91EAD02B45ULL, 0x09CDD8F4C9A86520ULL, 0xD0CCE24E70181617ULL, 
            0xC692915860DB3DDAULL, 0x353F4E6484E7AE0DULL, 0x721C341502AAA97FULL, 0xFF3B8D192DEC8449ULL, 
            0x46EBA2AA7AC5F063ULL, 0x2EA67DDED35B2FDCULL, 0x729679C0F5A9FAB0ULL, 0xFD3C8ABD53EBEED2ULL
        },
        {
            0x5C91131D1AE29762ULL, 0xC6966C010208A7AAULL, 0xDCDA900D011252E3ULL, 0xC400AA009BE2542FULL, 
            0xD526F26EA1FF5BBEULL, 0xB453A311786EEC2CULL, 0xF9F8790F670E892CULL, 0xBB6B72D3F316FCACULL, 
            0x5CC107E3D2C1C657ULL, 0xAE2979E25CF7F996ULL, 0x5CFB38E6E96FCC2AULL, 0x5A032C870BEFBAD7ULL, 
            0xE4F507A709896F17ULL, 0xACB2EDC01E08DD30ULL, 0x1D566869A396870BULL, 0x7F08D366F93CE6ABULL, 
            0x66860AA4CA5032E5ULL, 0x83240CE72FB3F7CAULL, 0xC22BBE9345FFD629ULL, 0x7A86ADD85B33616CULL, 
            0xAE63FAF8BDF23479ULL, 0xCB7B0D0753245478ULL, 0x972201539701422CULL, 0x0360F5FBDA029D39ULL, 
            0xA790226C974963A7ULL, 0x49B2F5B221B82088ULL, 0x009B6A4E7FA2CC9CULL, 0xBC171E6F133CFC26ULL, 
            0xD2B5CA3264F5A612ULL, 0x252BED8DCBBFEBFCULL, 0x1EB5EFF5B31835C5ULL, 0x792A1397206B4C18ULL
        },
        {
            0xEC7197DA93650B40ULL, 0x5112D39CC34B7DD3ULL, 0xCBD80BDA4CA0419CULL, 0x1CB55141FFE29F00ULL, 
            0xD515029FCCDA18CDULL, 0xA08AC426AC6BEF8BULL, 0xFC64367DE2CB28E1ULL, 0xEBE2EBF11B40563EULL, 
            0xE7D76300FA262831ULL, 0x8FD75584B994F295ULL, 0x24CCABB697D628D6ULL, 0x83290A0D5FE811C8ULL, 
            0x99DD06CEA09E8911ULL, 0x0CEA6255296EB3E9ULL, 0xCB27384076185B70ULL, 0x873F865D6D10373DULL, 
            0xF64A73FF870DD2E4ULL, 0x0A3B3BC0EC0A3ACDULL, 0x3D1FA982EFD49F90ULL, 0x303D428562EAF6ABULL, 
            0xE5FE124BFC0643B9ULL, 0xA0A8D6B2A2138DF3ULL, 0xC6839DDF7F565DC2ULL, 0x993AE05EF66F768DULL, 
            0xD6A488B89E9BA996ULL, 0x2C706A9A6F4156F0ULL, 0x6022AB3DA042CCE3ULL, 0xAA90D9D8D1D1929FULL, 
            0x46D4762A0A80E0A9ULL, 0x34BF40A77D9422AEULL, 0x6D50C777A3D63EB0ULL, 0x03468D886826D37FULL
        },
        {
            0x13CB438A3E5362E7ULL, 0x8DD56A9266F2BA5AULL, 0x0148772512838E5DULL, 0xF75041135157CC35ULL, 
            0xE8080E6E5337A60EULL, 0xB52D83249CFE09F4ULL, 0x9FA788201893E51CULL, 0xB7CE02FE4E9C3E12ULL, 
            0x517324A9E65FACCEULL, 0x840C63074BCD9768ULL, 0x377C457FD85555A3ULL, 0xCECD981EC03B6446ULL, 
            0xB6F17C8BFEBF359AULL, 0x5B46102F767E477DULL, 0x21D74D99985AABD4ULL, 0x389ED7006F293827ULL, 
            0x419EEA5E86D7C947ULL, 0x624116DA60BA1F6DULL, 0xB08DE766041B380AULL, 0x7E24B76BC2CC031BULL, 
            0xB0D2821A412B8CCEULL, 0x05870F350899506BULL, 0xFFAF1C3CDA426893ULL, 0x82203B3859EE3319ULL, 
            0x4C038ECB70430EFAULL, 0xBCC53A775274B865ULL, 0x38452A5ABA00330AULL, 0x4237D2285EFB42ECULL, 
            0xC661ACB6F57F5248ULL, 0x16BAFDFF3753D1FAULL, 0xD7216C3303B57A38ULL, 0xAA337B6884168326ULL
        },
        {
            0x75ECF473F94310E2ULL, 0x1C3E32A208E25FD5ULL, 0xA1FB6600E7D27578ULL, 0xBF3E90471E1E7DECULL, 
            0xCB88C77BC03A00E4ULL, 0xC43967CC4CDCA314ULL, 0x8036F82C97CA16DFULL, 0x69FEC91675784E7AULL, 
            0xC13004CDCE732B19ULL, 0x908CDC1C2E768E2FULL, 0xD1A568E539D3F4A9ULL, 0xCDCB8591F14A9703ULL, 
            0xA94EB28818828409ULL, 0xAB3ED055FE010C2CULL, 0x7CEB36F55D9432DCULL, 0x65B814A4345D4386ULL, 
            0x0BF312B6FD638816ULL, 0x7B9406F581104411ULL, 0x3983935B0055D483ULL, 0x68908C02EC540791ULL, 
            0x8C47A77C3FD5ED41ULL, 0x1EE43F0F62638B43ULL, 0x766FF6E883F86D29ULL, 0x6DCEA7E0CB99573DULL, 
            0xA918F9A500CD0887ULL, 0xFAEE8C2ABAD65BBDULL, 0xDA17F9A105A4872EULL, 0xACE5CFD76A201C50ULL, 
            0x49A7C58C64AF4BC6ULL, 0xE4AD569A25B8BB35ULL, 0x565CA65E54DA568BULL, 0xD5EE24857A4A7479ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseEConstants = {
    0x60A3186436EE6E52ULL,
    0xF72E650E0CDCE5B8ULL,
    0xCC6E2C152F9A56D6ULL,
    0x60A3186436EE6E52ULL,
    0xF72E650E0CDCE5B8ULL,
    0xCC6E2C152F9A56D6ULL,
    0xCA849C40A71D9891ULL,
    0x4853B1ED8F975C8FULL,
    0xBB,
    0xDD,
    0xA0,
    0x0F,
    0x73,
    0xC1,
    0x6D,
    0xBA
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseFSalts = {
    {
        {
            0xF3EC496C07CD1927ULL, 0xAEDF6DA38F802911ULL, 0x79DAE8F3819A343FULL, 0x11101CDDE09C2676ULL, 
            0xE8426B967474DBA0ULL, 0x9EB8FF1C90A02593ULL, 0x3FD8C3CFDBC8A52BULL, 0x01646A5085EBB460ULL, 
            0xB6E78615D99E63B8ULL, 0xF4BF0FC1DF9DEFFDULL, 0x44FF21289392454BULL, 0x9A2B57B2785BF043ULL, 
            0xDF9A42580D5266D3ULL, 0x4381F244B01CA7EFULL, 0xFCB99DC2FF144B50ULL, 0x56ED4F544C5AC9CBULL, 
            0xF61971AF341FABFEULL, 0x507E281C04B28193ULL, 0x4B28EF584827D508ULL, 0xBFECB4D758673072ULL, 
            0xD1E98E356D3C6030ULL, 0x963EC74DABB79A10ULL, 0xD8CECADE36A3E07AULL, 0x48822011BB4EE765ULL, 
            0xEAF458B0AFD3A754ULL, 0xAC07993D98D6B4ACULL, 0x95F93A092B79BA3AULL, 0x0A388BE19DB1C9CFULL, 
            0x08239D71CB1E202FULL, 0xD46DACA960CD53AFULL, 0x588D739489CC6CF1ULL, 0xC36B5286C3523BF1ULL
        },
        {
            0x4DE2E94D1C292738ULL, 0x17AB51F4590B8EDAULL, 0x988B6EC08CD1EA47ULL, 0xE4B5C3C1F30EBBAAULL, 
            0x750ADBF84DE59C58ULL, 0x6D6E420D28774F6BULL, 0x65C28142C03321BDULL, 0xB6E7BD11EC779A3EULL, 
            0x7F31B8C85BC9F0D5ULL, 0x9E15D1895F4B3930ULL, 0xF4DD7CEF1C8A3615ULL, 0x54467355F95FEB74ULL, 
            0xDCA396313C0A1BB6ULL, 0x19F311C6D16E6BDDULL, 0x04C87F0AAC1D0A64ULL, 0x628EE4DD29EFAD8CULL, 
            0x7793F1F5041508B8ULL, 0x3D9BC8C8FF68DAE1ULL, 0x56ED5BA596D2CBFAULL, 0x3DDD49AA5175714BULL, 
            0x5F6E1A8295BA09FFULL, 0xC55E09F173EB0C22ULL, 0x204D9EF84BC7C43EULL, 0x230C9FFF3C2F68ACULL, 
            0xC14EC46A7125AD99ULL, 0x8679B94250C03A63ULL, 0x852E6CC20F0F11EFULL, 0x77806E526D822E09ULL, 
            0xB2ED1180380AC46AULL, 0x0ECA5DDCA8F568B4ULL, 0x6B9680B138350519ULL, 0x02A64ED24CCB735BULL
        },
        {
            0x04A259A172B66D6AULL, 0xD028A56237C4DD22ULL, 0xC0F87D12025843E6ULL, 0x217B9A5F7B3FF852ULL, 
            0xDE66DAD769BB49D0ULL, 0x2B36FD6745A3A71AULL, 0xFF4A87E620BA09EFULL, 0x6E1066613B23C43CULL, 
            0x489584DD014DD340ULL, 0xB07676D8729F9592ULL, 0x3F144C8F046469D9ULL, 0x7641A71D03613C2FULL, 
            0x693E678F5F741E4DULL, 0x015E527C6D96ADCFULL, 0x796C9544AEDC170FULL, 0x5ED2FCB886B2087BULL, 
            0x64E0EF745DE03375ULL, 0x9817E883C6048C46ULL, 0x9F49648487A7F28AULL, 0xFD6240C260FC2A45ULL, 
            0x88860B7A3F8C1C61ULL, 0x285E2B27506A4423ULL, 0x11C952A45E1C7B54ULL, 0x75BE4CD4E69A54A2ULL, 
            0xEB11617ADF1E9FA5ULL, 0x138DFE26B27A70A0ULL, 0xB3F0028CDE3B3812ULL, 0x5D0CC7CABB72BB60ULL, 
            0x498CC99E0B40EAB1ULL, 0xF5D24AB8EAA63848ULL, 0x86D9A984F81B052EULL, 0x41524086A5CF97E9ULL
        },
        {
            0x43CF6A799620AFE5ULL, 0x0606852589F62B02ULL, 0x27401D4E9B5C4831ULL, 0x430059E5CA7F4B6FULL, 
            0xA2FA743A3FB558F3ULL, 0x94B48110DA34B3DBULL, 0x1B7B3E2C30CC72CCULL, 0x582830093E16F31AULL, 
            0x5442CB7F3E8A0BC0ULL, 0xD397E28208CC5351ULL, 0xACE994B278F60A8FULL, 0x0B3568192FFD1A3BULL, 
            0x9F9891BE1A8C5BDBULL, 0x394F94E3E8D470C7ULL, 0x51A20C563656D519ULL, 0x4C39230D742A71A2ULL, 
            0x4712CD0382404D73ULL, 0x1CCD92002EE0D4FEULL, 0xB62450038CFDBD0FULL, 0x78631DD38F1BAC41ULL, 
            0x2888ED1A3036CA58ULL, 0xDF9C972D15D88402ULL, 0x7E61278ACD48E975ULL, 0x13F714B7B1D6E281ULL, 
            0x4283BE85A3A58DA2ULL, 0x54F67E1E3CF47A01ULL, 0x90C334252D14A672ULL, 0x8DFFFECA6146DFC1ULL, 
            0xC53E6C77F8F1CDB8ULL, 0x1F9C4C9EBBFCC098ULL, 0x11401B70F0A74E4DULL, 0xC15CCF2B3CC075D6ULL
        },
        {
            0xB11120A143067789ULL, 0xC46ED28E5C739924ULL, 0x7AE4EB799E06BECCULL, 0x3A0899B1A92335FFULL, 
            0x416200588FF83C9BULL, 0x227E2F99DBC8F9F1ULL, 0xBE27F6A24320443CULL, 0x836E31A2A9E898FEULL, 
            0x3C55727AE3A31651ULL, 0x6AAEB5EE37455EC6ULL, 0x7419AA1300AA4BC6ULL, 0x45B01F5810729776ULL, 
            0x0056866D99D00976ULL, 0xCB4AE0CF90472D91ULL, 0x70A7D888DC6A6E27ULL, 0x450FC173096FA6D2ULL, 
            0x6AA88ADE7523A8DEULL, 0xA2BADF53CCDCC0B9ULL, 0xFE8AD86CB1A96C66ULL, 0x30EDEED9D7FB5901ULL, 
            0xF129DF70D7999C4FULL, 0xFCAE27D4F0CD807EULL, 0x6A038A38865950E0ULL, 0x8DC6DDB4E724C963ULL, 
            0xE1177BCFD9A7ADCFULL, 0xD8F0B77B3DB4CE3EULL, 0x62F0DF3E5231974CULL, 0xD2E220579469C44EULL, 
            0x03B6FB9800C607B1ULL, 0xC701B8B9BA601B4FULL, 0x0033702F767A5F7AULL, 0x79F2537B19481D0EULL
        },
        {
            0xB904C27CF6205B8EULL, 0x8A4CB927988FF12AULL, 0x8B3EBC21988513EFULL, 0x737C6655E402C532ULL, 
            0x21A6AD302093079EULL, 0x5AE654D7F707F2BAULL, 0x2D84E06E9F0F7756ULL, 0x814EDDB4477647B8ULL, 
            0x66660C338CD7E920ULL, 0xEE4BF180BA00EA74ULL, 0x93A391A4DD3CF713ULL, 0x49C062F6FD6260FDULL, 
            0xB40B30CAC63A5919ULL, 0x05411D15B02C6775ULL, 0xF825C23DD89348B9ULL, 0x53EEED75090416E3ULL, 
            0x1F57B960F71DC660ULL, 0x11D9A63F51FB3E8FULL, 0xDA6F40BD3FBCB7F3ULL, 0x1B0AB461E4971962ULL, 
            0x8373FCEE3FF2C22FULL, 0xE4255C288D88C9E4ULL, 0xF9A102B92A5E7B88ULL, 0x95214171C504DA35ULL, 
            0xEEF404A4255BD851ULL, 0x450D402045641C56ULL, 0x3C135981F354E08EULL, 0x150DCD5EC1EC4ED1ULL, 
            0x7E2D4321E26499C7ULL, 0xA55D4FBA957B33D2ULL, 0x1E6BECCAD73590E6ULL, 0x104133D823BAB409ULL
        }
    },
    {
        {
            0x9EB105455A44435AULL, 0x9E625F3E56B2E29DULL, 0x27D9425B02BDCD03ULL, 0x5791B31FE86F38DBULL, 
            0xB93B7FEBF5CD5AC8ULL, 0x7AA33B25CFF7FFB7ULL, 0xF568BF6C50C15E69ULL, 0x065B91AA708D00C3ULL, 
            0x8840D052587FFEB9ULL, 0xE34FE315974B0AA2ULL, 0x19C79279ED3BA744ULL, 0xCA7955900A4F1DF3ULL, 
            0xE9CED0964A4EAD01ULL, 0x0407482C477F9768ULL, 0x33E857197215DE0EULL, 0xA52A3D255E746630ULL, 
            0xE4B0E215141F7F66ULL, 0xC1F2B32FC0BB8328ULL, 0x3904C403F6D55796ULL, 0x15ECA9C0086FBB32ULL, 
            0x27830D1BF48ABFF8ULL, 0xE1414C7CC231001EULL, 0x928402BC19F03F7CULL, 0xA9385DD77E04F566ULL, 
            0xFCF73CF33E17E8D1ULL, 0x6C8DD76B856E293DULL, 0x231C612D04C2BB43ULL, 0x7EEE824DFFD020ABULL, 
            0x1CB9096A670D518FULL, 0x8C5F94AA3FB9BE61ULL, 0x0C5C31010F72DF42ULL, 0xE691630A7A82C41DULL
        },
        {
            0x3F67A11C8505B491ULL, 0x2CB3318F240D094CULL, 0x20D3EB6A8D0AC1F7ULL, 0xEF7783825A950134ULL, 
            0x0697AACF86C75518ULL, 0x74CE7BC03B9F29C6ULL, 0x986F9CBDBB938089ULL, 0xECA0CEC4BBF67261ULL, 
            0xA2B9133DC7F35365ULL, 0xB6A3C960B707DD09ULL, 0xCB6B64F1DAC19F5BULL, 0xFCF985D7B43B8F30ULL, 
            0x5C9A2440CC60E7A5ULL, 0x3FE21A029A7DF42CULL, 0x41436EE75E1F1EB4ULL, 0x5E85A18B45265BFCULL, 
            0x61A140CD052E7B5DULL, 0x3B82705DA0EDB862ULL, 0xE8B6841A7F1534FFULL, 0xE96F5B5288945CC8ULL, 
            0x6B722DF00632F400ULL, 0x4D58848AF7AAF142ULL, 0x163DB97C9362F149ULL, 0x5FF3220BE8853A29ULL, 
            0xA34154FD4AC112A4ULL, 0x0853DCE5D80E4586ULL, 0x79432DB82861F58BULL, 0x99ACEDDD974E3F3AULL, 
            0xE233A048FB3C726BULL, 0xD11E74CC22990318ULL, 0x0854EFC71E0E3D91ULL, 0x53AB416AF3440C58ULL
        },
        {
            0xBEB594C8DECF2098ULL, 0xB4FF451D7A4024C6ULL, 0x64AB323C29BDC64FULL, 0xF6382557A201EDFCULL, 
            0xACA5D406F15CAE19ULL, 0xDF8D44945C8E7042ULL, 0xF74B8E49DBB24213ULL, 0x4BDE7C69EDFC1FBEULL, 
            0x170569463C335BD8ULL, 0xB667AA6736D3D226ULL, 0xDB04750B9BC314E4ULL, 0xC2C735625E0F66CBULL, 
            0xCF40706E2B6232EAULL, 0x41D3AB3E538F3757ULL, 0x7B8EB8954369238CULL, 0xCB9DC436DEF5E3CFULL, 
            0xCDF0028CF00E8E28ULL, 0x5E6000C9C964CCD6ULL, 0xE2DE3135B0BA0FC6ULL, 0x285E7F5F0C79B203ULL, 
            0xCFC2D272883FF46AULL, 0x3F9FC49CFBA4548EULL, 0xD4E80E868E71C829ULL, 0x02763B0B6346C7E1ULL, 
            0x5531318D2F622581ULL, 0x2DF0F365EBEAA87BULL, 0xD2AF8EA09DDABFA2ULL, 0xA59851279BD20DD4ULL, 
            0xE764B0CE8B9D0A50ULL, 0xE12D240F606FA9F2ULL, 0x1C3330CB426381B1ULL, 0x75695A3349F85A5EULL
        },
        {
            0x4DA348DF2B48591AULL, 0x3E3BA4A03304B6F8ULL, 0xB701D89821894670ULL, 0x0CA2B68AB9B99D6BULL, 
            0x3077B85530D76796ULL, 0xE1536369EC2F9AA5ULL, 0x7F19A89C9DEDECB9ULL, 0x745C1692703EC2EEULL, 
            0x3178B881422608D4ULL, 0xBE9745755FF0BD1FULL, 0x5E07156C680A6C27ULL, 0xD7702B32F4770F74ULL, 
            0x06BBFC4F8907B5A1ULL, 0x2647F1107EEA5BA3ULL, 0x2B9F0FE17B19C878ULL, 0x9B50D74CD4478CD6ULL, 
            0x244F267287D8BE9AULL, 0x906DDDB8A02BD085ULL, 0xB13D1B38D6E777A3ULL, 0x13A3511CF74E4D1EULL, 
            0xF8B7066F95F089FFULL, 0x5A86E14844FB1BC6ULL, 0x7B0B8EB6E01CA3C0ULL, 0xF2D506E19C097BB8ULL, 
            0xD0A7DFD9909EC6C2ULL, 0x42B7AE4EA0A9428FULL, 0x79448B85131E2E59ULL, 0xC3F64055087B3A15ULL, 
            0x73BBEDB8E6D65C10ULL, 0xA78402DDF546B150ULL, 0x8A39DA8B3B18DF5DULL, 0x2BBB514346FBDD64ULL
        },
        {
            0xD25C4770E55F33EEULL, 0x91DDBA3727822BF7ULL, 0x7BB8BF72EF93F70CULL, 0xA65FFE84DCF70C58ULL, 
            0xC87EE217DDFF1DF4ULL, 0x056EDD4B49711251ULL, 0x1E17C4805A4C6078ULL, 0x796005DD644477FEULL, 
            0x3491047635FB420AULL, 0x953F193F277B241EULL, 0xD748D4CAC7C23532ULL, 0xD8601A918A4C4245ULL, 
            0x3DEC384A4F7E21A1ULL, 0xFAFCC80178539CABULL, 0xF72451C97B898751ULL, 0xB1D4D3B2FE46770DULL, 
            0x8366DA7CB7923421ULL, 0x8D2569D9C7E358BEULL, 0x72461D00DB553BBAULL, 0xAAF06222AC03FD01ULL, 
            0x9C4954A70C37D826ULL, 0xB2DC545B97AC02B8ULL, 0x98C4882A414B2D3CULL, 0xA170D85925526BE1ULL, 
            0x02F19A1E0A1F3251ULL, 0xDC87B0561C164863ULL, 0x1EAC65B17F03B678ULL, 0x7BEDE73D57D465FEULL, 
            0x5CACC8536BE24D7DULL, 0xC85B9A13AC7B396FULL, 0xEA9BEF58D5423FC7ULL, 0x16E1C16F20FB8C67ULL
        },
        {
            0x338454DE4B1EA224ULL, 0xA166AD0CDFBBD6F7ULL, 0x713E28F6210F58E9ULL, 0xE2EF723422E73A16ULL, 
            0x3898B1020AAA554EULL, 0x85CE1ADFE43FAD3DULL, 0x02FB84C75C8393ACULL, 0x2AEDA2BADB9987E2ULL, 
            0x6ADD89BB2FC48E61ULL, 0x6CB4AD7ACE961BBAULL, 0x04D436D107BACB17ULL, 0xE2A30B5462956457ULL, 
            0xE317E2552BE41053ULL, 0x101F1FF4F8CA8D8AULL, 0x3360D3703D7983B0ULL, 0x833B342B79B09706ULL, 
            0x759FF2BA1A30DBFAULL, 0x27B9B7754F437DAEULL, 0x67920DE58F415262ULL, 0xD877AE2A1EBABA25ULL, 
            0x324DA16B6F0C76A4ULL, 0xA5750A70841B2EB0ULL, 0x2363AAB4BC32D2EAULL, 0xD997E3EEF903B812ULL, 
            0x171385FD6677B7DCULL, 0xA7CA847BB27B1DCBULL, 0xA52D4EEF2B4AA69EULL, 0x9001E4A530102590ULL, 
            0xE854E8B92E4693D8ULL, 0xEDC79040AFE747F7ULL, 0xB14603758F9A50C7ULL, 0xA6C3349CC3DCB219ULL
        }
    },
    {
        {
            0xE3DDCEC8CA56E900ULL, 0x6CE09F5C6240FA58ULL, 0x7F25B6DADF3EDACEULL, 0xF1A6599F81D1A68DULL, 
            0x5AB41891596611FCULL, 0x2200EA6473C507B3ULL, 0x47FADFF6C7174EB9ULL, 0xEE8E3B312BBABEC3ULL, 
            0xCC80E31B11EE3D0AULL, 0xB3C66221F08B7214ULL, 0x9B777370F8FB29F8ULL, 0x5524256267E53598ULL, 
            0xCB367BD94E1166B8ULL, 0x44830F1A00C0F4B7ULL, 0x766AA4563A9664D8ULL, 0xC8077A6DCF314757ULL, 
            0x460DC46C335127FFULL, 0xA30E3C49DE09F126ULL, 0x8A30174D0F7A7A2EULL, 0x1F51B5029A3D7DCDULL, 
            0x53EC1A952B18E62DULL, 0x6F25BD8CE15ED303ULL, 0xDC4FC5709587F8F4ULL, 0xCCB85B698EF790CFULL, 
            0x0A0C2762E1F70B81ULL, 0x618BD10F13AAA3E8ULL, 0xC59E969F17825DFFULL, 0xFD133FDAD4AF75A9ULL, 
            0x2618CE6FEB272B17ULL, 0x7A267CE85B8DEEF8ULL, 0xB691789763404D1FULL, 0x275A380ECE772EE0ULL
        },
        {
            0x09AA9EE98A0AD427ULL, 0x00D15612E83F14BDULL, 0x4D297F705DA5C1AAULL, 0xB20E976087F1B88AULL, 
            0xE016EE0C92F32675ULL, 0xA32599E0128E8FADULL, 0x181DB98E8777D0BEULL, 0xF5D111E68B0BC017ULL, 
            0x222A7EC7678CBD3FULL, 0x81160B3867C2E0E2ULL, 0xF9585C3CBE9350F7ULL, 0x027854482B727D71ULL, 
            0x6AC769E9314D2A84ULL, 0xC33189DCC62070B7ULL, 0x02CDE0156453227CULL, 0x8249C7015E41403DULL, 
            0x773C71C0C0A81D3AULL, 0x310438CD1582AA11ULL, 0xA144E4052E3F48BFULL, 0x53F791BB37A92343ULL, 
            0x0F650FA4CC1D54ACULL, 0xC32FC4D05E66CC50ULL, 0x7010DF91FB764639ULL, 0x72DDC0A062EEEE0AULL, 
            0xB87C5C1010867140ULL, 0xC08960BB3E72A7BEULL, 0xAC36593BF8452174ULL, 0xE47CB980F1E4A231ULL, 
            0xF1C14E831B71A7D7ULL, 0x494F41397AD44FB1ULL, 0xF973B009B3C59206ULL, 0x3E76B0193A9E4678ULL
        },
        {
            0x293760C02B6DF166ULL, 0xE140D424984EB976ULL, 0xBB636F2DA3B306C8ULL, 0xB60D0FA52A69E4E2ULL, 
            0xE065C1B183BFF009ULL, 0x37CEFC8F0A501F4FULL, 0x1BAB99316806FBA0ULL, 0x3832A9D8D893B909ULL, 
            0xD47583128CCBC73DULL, 0x8345708735F7AEC5ULL, 0x9BBD305352143A80ULL, 0x4D606CF187575F85ULL, 
            0xD1786EAE06A16B25ULL, 0xB8A6F90BAF10F6A1ULL, 0xAB2EC2FB543ED15EULL, 0x20883BA61088B15AULL, 
            0x11D2F7A899E7BC23ULL, 0xA9B795A4EDBB1A86ULL, 0xFC3D9314EC4A26EBULL, 0xD7D9F74707F4831CULL, 
            0x101445EE03D333CAULL, 0xF664EB1BFDC3FEE9ULL, 0x1292B1CED8F072C6ULL, 0x6B6779FF4401C0DCULL, 
            0x508DEEE08E4A4B7BULL, 0xAFADCB807B71893BULL, 0x38F911CDEB01345CULL, 0x9BCD8F734B8C4E85ULL, 
            0x5C526B6F55FBDA29ULL, 0x3444965833C60C84ULL, 0xB4BF294408E1B887ULL, 0x395377EDD424D301ULL
        },
        {
            0xDBAB9D533A2FC206ULL, 0x9C66E78FF775C950ULL, 0x6E3F451AE98CA440ULL, 0xE74689D88686F085ULL, 
            0x2574F8CB5C839921ULL, 0xB2DB9DE5BEF11556ULL, 0x5993939A43EDF3B3ULL, 0x9B3A931D4D4B01D8ULL, 
            0xC065D3831D98ECF1ULL, 0xAA4B3C588032A32BULL, 0x3DC6BA1000F3FAFEULL, 0xF32586C0EF38180AULL, 
            0x5E10231D488CF27AULL, 0x86FC3DDCA23691F9ULL, 0xEEE3BC65DCA939DFULL, 0x8214D1BB7BAD6FD4ULL, 
            0xA6087AF1B2810595ULL, 0x65A32A534F975149ULL, 0x81FA5D21E04A8E62ULL, 0xF63C5CDB11EBA4B0ULL, 
            0x4B4CF623A5B8C5FEULL, 0x5FE2865C43A96001ULL, 0xA8206A20DDB7D825ULL, 0x73D030B1D781DB71ULL, 
            0xC1E487F96619C83CULL, 0x331EDA16BC1FB9FCULL, 0xE837E7BBB39EFBA0ULL, 0xAB84587F63B20247ULL, 
            0x24F0D1592B34DF76ULL, 0x2B75EC8A3D0A5DC4ULL, 0x58465FB5CD4E65B1ULL, 0x055684A489B92FAFULL
        },
        {
            0x78036A6071359FC8ULL, 0xF282164AE988A677ULL, 0xACD42D50496BC37AULL, 0x7FFE4E3243F06F2BULL, 
            0xBF827831AD30E2FDULL, 0xAF5B7CE673BD870AULL, 0x6149FF5329E48F1BULL, 0x4BD5EC82A70C982EULL, 
            0x4982E00D4E7A0DD9ULL, 0xD37C9A655D3593B1ULL, 0x14A81AEC8DE40698ULL, 0x09725118BCD86994ULL, 
            0x56EE76696634CA45ULL, 0x2F319AC1F45B74A0ULL, 0x0A8A50F2E4F87277ULL, 0xC1A376F201197BE9ULL, 
            0xFE4FD760A7176F2BULL, 0x40F5CE955FDF16B6ULL, 0xCD65FD909296B4FBULL, 0xCDC5699213849C92ULL, 
            0x728EC895570558A9ULL, 0xE26918500C73516FULL, 0x240FC1459893EA48ULL, 0xFBD6CEDEE9A22CE9ULL, 
            0xDB26D09A43E632D8ULL, 0x5B98C34C51C0433DULL, 0xF5FAD08068858020ULL, 0xEE94007A6DFE244EULL, 
            0x8C5B84CCD963E9DEULL, 0xE8F1818815D790B5ULL, 0x0F0DC2D1E1D8BDF6ULL, 0x9986A066209D637CULL
        },
        {
            0x722E50CD3F489168ULL, 0x0E8514D404D69D47ULL, 0x3A22A191FE8BBD5BULL, 0x0AC1E8BBC4F2CB2EULL, 
            0x921370EB5589DB34ULL, 0xE04A59E61F06E645ULL, 0x64C220DA1F3EA1CBULL, 0x375B4A316F67AFBBULL, 
            0xEA5FD2B827B78A1FULL, 0x5B855DA9312B6728ULL, 0x2A5FF02D2EF955B8ULL, 0x4542BEBE36DAB293ULL, 
            0xB6AA0D70E244F7EFULL, 0x8172EEFF8C5DBABDULL, 0x41238039AB3F6CF9ULL, 0xF4A1962A6C89AD66ULL, 
            0x9C1F49320425C51DULL, 0xA38315E72854AADFULL, 0x11DD30882A311FA6ULL, 0x9CA0B0654B5750E4ULL, 
            0x72D14E5C514B18ADULL, 0x9D88F032E2D6593CULL, 0xF7D5BA36703C34BEULL, 0xAF2E12DC0FB14513ULL, 
            0xA31A3130B0E852F3ULL, 0x1A3A85E5BACB7621ULL, 0xFB5E78E1836D3E96ULL, 0x246BEF33EEC5ABC7ULL, 
            0xBC4F097ABFF6A807ULL, 0x24FFC70CBC3CB660ULL, 0xD776FCB5C8C22331ULL, 0xCF69C2DCF0E04C76ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseFConstants = {
    0x7F61A19914A67EA0ULL,
    0x5C47EF2EAA2EB778ULL,
    0x01CAD0794D26D448ULL,
    0x7F61A19914A67EA0ULL,
    0x5C47EF2EAA2EB778ULL,
    0x01CAD0794D26D448ULL,
    0x91B284535B73C98BULL,
    0x68F6BF24EA8ED134ULL,
    0xAD,
    0x31,
    0xB6,
    0x0C,
    0xEB,
    0xC5,
    0x5B,
    0x58
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseGSalts = {
    {
        {
            0x5D6455240EBACF2DULL, 0xFDEEC87612E4FD6DULL, 0xA98C6F4CC2FABE45ULL, 0x41043112A8DDEFD5ULL, 
            0x7F0D3C717AAB64C1ULL, 0x11B3D56C03985F18ULL, 0xE436A95F7759C28EULL, 0xFA385215BEF584EFULL, 
            0xAD9F5C39C426F501ULL, 0x6989987BB2D3A241ULL, 0x301471023DF329A9ULL, 0x5CD651C7514CE794ULL, 
            0xEA1A793D0F23E42DULL, 0xCC3CC4ADC4B31331ULL, 0x6C4E87DA02DD9A76ULL, 0x68B50DC21BDE8563ULL, 
            0x704FE232802FD18EULL, 0xE8FAD2B2EC6402F3ULL, 0x6BD23F895E28C741ULL, 0x3AA3451C2111DE2FULL, 
            0x77EB44D344D11982ULL, 0x9A170FF7BD628E06ULL, 0xB2048120C8A2ED02ULL, 0xBAB9F5ECAB782270ULL, 
            0x9FA34AEA993D91DBULL, 0x51F8018E5CF4B51CULL, 0x55D66A50E3829DDEULL, 0x9D16F17168C2A6F3ULL, 
            0x5A3CCDFA0202005EULL, 0x2593F3E07DF022F7ULL, 0x9623B2F9DA184652ULL, 0x09AF0F367D331E53ULL
        },
        {
            0x03BF9284E98E49E1ULL, 0x2EF66E781A8441A2ULL, 0xD771CA3D3F6ED3C7ULL, 0x69EA3DE77A22B53DULL, 
            0xD24CF0BCF5BE52E3ULL, 0xF5B1925397757AF8ULL, 0xA6BC8351C7EDAD94ULL, 0xF62348D24AF20EB1ULL, 
            0xC46827C0137D3B32ULL, 0x188DFD933A40D116ULL, 0x638CAC51E143E503ULL, 0x01FE44DA83501FE4ULL, 
            0xFCC1B7F761CF3E5FULL, 0xF182F372603E2D3EULL, 0x110200D3EA126628ULL, 0x07B6332FECB40540ULL, 
            0xF00DC34A3CC610B0ULL, 0xF4924BFEC38132DDULL, 0x8C251B364140DC7BULL, 0x1A0A27211B2BB744ULL, 
            0xB64423AD8462A123ULL, 0x62DC5F38C4A7F16CULL, 0x5AE17D9531BA970CULL, 0x7DDF63ADC3E3BE90ULL, 
            0xA210A2EA6FB0B44AULL, 0x7C3A2560118D9527ULL, 0xC6E4FCA2B2CE9891ULL, 0x27AA76A727C1C57DULL, 
            0x340362D70384910BULL, 0xE1B8C43B4A2B6A69ULL, 0x8A62317FEAD46A87ULL, 0x9A612AE2BB0688ACULL
        },
        {
            0xC68AEB90FDB86185ULL, 0x221E4D3C15D798EDULL, 0x62AEF9EF05D52407ULL, 0xA5BB83D56A1FF0CCULL, 
            0xF4668317F1FD3A37ULL, 0xA4351059D8339654ULL, 0x4B36EC0B340AD84CULL, 0xC8109EEB2209DCF4ULL, 
            0x82E33DE128A9B781ULL, 0x64C943BCDEB32D76ULL, 0xE32AC0F541F14FA5ULL, 0x6CD17EABA1F672C7ULL, 
            0x416FD85EAE2C1503ULL, 0x49B11A16CB7693B8ULL, 0x14D0AD33BC07EBABULL, 0x985D25315CEA16CDULL, 
            0x4274374BA4022AFDULL, 0x9F5169B3DAFD85DEULL, 0xCD7794F03C0ADA96ULL, 0xD2B5346897988008ULL, 
            0xD1FAFD33408CBB06ULL, 0x14F39DDEC36EFBB8ULL, 0x3BF0F9FAE39C0C5AULL, 0x533D62BB54A6B2A5ULL, 
            0x3C77E9446C2A8D93ULL, 0xB16A0CFC1EDB3F4DULL, 0xB85ADFC287EB3FE7ULL, 0x8173FFB827627869ULL, 
            0xF44A6BC31C89948BULL, 0xC5616550034177DCULL, 0x8840FBB5F7DA35A3ULL, 0xBC8BE87A397A002EULL
        },
        {
            0x1E07988F3B3FFC74ULL, 0xBD47AB0331257F66ULL, 0x880264D91FBBB3A0ULL, 0x475528AEDCB573CAULL, 
            0xF95E7D55AFEA534CULL, 0x5E47F411F06334CBULL, 0x81905801994B2984ULL, 0x2E9A138973825B28ULL, 
            0xA17474FE39FA631AULL, 0x1936B6C7FA9DFBD4ULL, 0xDCF61970A61EEC74ULL, 0x359686EA80D1BEE5ULL, 
            0x9529CE041B09F02BULL, 0x05C1FAB9937EF100ULL, 0xF57A69914EFB78BFULL, 0x71D30E347AA6B1D6ULL, 
            0x057B6BC2AAF9F448ULL, 0x5AC5262D3140B377ULL, 0x75AFE97451BC2E7EULL, 0x096D441E1D3AD392ULL, 
            0x1A37F72F5D6F8C89ULL, 0x4FD7FB04D7545D59ULL, 0x51667DA0835BE10FULL, 0x81247B6464545D99ULL, 
            0x0B0915BB59237CF8ULL, 0x5673D879ECD5407EULL, 0x98FA7B239D547ED4ULL, 0x16416F0668E80369ULL, 
            0xD6E6573BD7F7AE50ULL, 0x24D6CFB90CE0ABDBULL, 0x8D8B64BF728C6AD4ULL, 0xC4EA0634EBB70D97ULL
        },
        {
            0xD51BA45ADE508C2FULL, 0xF5B375EB7D7546A2ULL, 0xBF7296643157D0D5ULL, 0xD7152A950C39761CULL, 
            0xFC0F7A1F3A53E26DULL, 0x4655BDC0816C058CULL, 0x515D80E541574D79ULL, 0x00E45086B0889D85ULL, 
            0xEEEB50F1F280D2A2ULL, 0xAD9A531017E52DF5ULL, 0x091F608482C8B68DULL, 0xC4F124C2DBB01EB8ULL, 
            0xB9A73A7A5F5AE99CULL, 0x196E525A4FC0A6C9ULL, 0x4E267B3D0534243FULL, 0xA1C62FC3B970E6CFULL, 
            0x5BAD35504E19E582ULL, 0x98D0E0502CCC27E4ULL, 0x70CF92B1F8888E76ULL, 0x69CCDE215FFDE3C1ULL, 
            0xC53BA3BAA65453C6ULL, 0xB30553FE0F6401A6ULL, 0xCDE60BB265338431ULL, 0xBFD3E76C32FAB519ULL, 
            0x38555BF6249D3352ULL, 0xE9B3C89A88B47345ULL, 0x79E86FA9DB11840AULL, 0x07A7E57D7813813DULL, 
            0xB55641D490851067ULL, 0xF249603DC31A8F2BULL, 0x0292191970F550CEULL, 0x0C72341F96CF55D8ULL
        },
        {
            0x0CA94C1BD6ABA4BAULL, 0xFD0976CF40F1034EULL, 0x2B9754F3C8CB90D1ULL, 0x2BDB8474844CC4E8ULL, 
            0x7358D082BC04B9B2ULL, 0x4A5DB99E98BEA07CULL, 0x8555514013009961ULL, 0xCEFE0ECB87BA12ADULL, 
            0xB98D04FD29EB766BULL, 0x8EFBB127AA2A246CULL, 0x8956DF9C40010EF8ULL, 0x5834F15543F58C57ULL, 
            0xE475D2DEACDB3AE5ULL, 0x63669CDE5ED8B206ULL, 0x197419DF5D4AE70BULL, 0x6D67A61EDD73976EULL, 
            0x27C1A878B909042FULL, 0xC5E0220EA3883048ULL, 0x997CFB94762FF255ULL, 0xEFB7A807045B3A8AULL, 
            0x6BF9A13B7E6C6E39ULL, 0x93B59624D73C3834ULL, 0xD06FCAD2D2016250ULL, 0x4B2F2B314DF9DB44ULL, 
            0xB0D8514B2206F700ULL, 0x87598DD66018DCF9ULL, 0x7D86257AD843FDFDULL, 0x6271F51F8CB5C115ULL, 
            0x530686A533AD9888ULL, 0x8C3B2E2FA7D3FA54ULL, 0x7A33DE1AB7DABA51ULL, 0x6B9A1627972910F1ULL
        }
    },
    {
        {
            0x276583B1B7938919ULL, 0x8E3B87D2F5D41DB1ULL, 0x42887F1B6FCF5151ULL, 0x3015061B84120C8BULL, 
            0x897C7914A0523584ULL, 0x1AB254725FFA8CC6ULL, 0x18B647F63A6F0224ULL, 0xDB67A66B93DF35E3ULL, 
            0x924B9F6823693590ULL, 0x111C64E9690D624EULL, 0xD9FE34F806401082ULL, 0x246FBEC9B86760CAULL, 
            0xD855CB20B3B0ECA0ULL, 0x98EF9F387126F93AULL, 0x12FD7C5A9C9486A9ULL, 0xABD2317C7EE2C7C9ULL, 
            0x312B5298D7470C31ULL, 0x99AF4EAA068258A4ULL, 0xAFFCCF5817CF4A8EULL, 0x496DC7B01549E5B3ULL, 
            0xB756B96B014491B4ULL, 0x7B6A579721870C24ULL, 0x2DBE8DA6F15BDE71ULL, 0x25A7CB46BD02F67DULL, 
            0xA6D6936172D6AC24ULL, 0x8E63219D6ECC0FA5ULL, 0x56D73094D26277FFULL, 0x5AFB53AC660B32EDULL, 
            0xAF9661187AB5B3EDULL, 0x8EE2C03162053037ULL, 0xD603086EBE15EB8EULL, 0x7043D408DD3A564FULL
        },
        {
            0xDA3055196913FF46ULL, 0x0130B37E89BB37DBULL, 0x2BBD7EA1398C8D9EULL, 0x6C6476849E976D82ULL, 
            0xA4744482D5483204ULL, 0x861F0D99F9887561ULL, 0x0273B48E92E0C207ULL, 0x8B2D916D88662936ULL, 
            0x57E331DBB8FCF70EULL, 0xC804551E5A83FDE3ULL, 0x3829476C24435830ULL, 0xEC9ABF028BB2DC97ULL, 
            0xEB794D995BF6F109ULL, 0x529F94D870FB4ADBULL, 0x20FFC96CC0C624B6ULL, 0x04FFA1794C027760ULL, 
            0xE37C0D885D66810DULL, 0x9488E7612BFA4920ULL, 0x751EC8CF6390D4DBULL, 0xED6CAF3B889C5707ULL, 
            0xB5CAE67B54641145ULL, 0x69D4838D91AA8120ULL, 0x78B1BC2E59CF9345ULL, 0xCFE55D58361FE6F0ULL, 
            0x1195917DD5F3B284ULL, 0x46996B7326255E83ULL, 0xCF232004B740BB49ULL, 0x533D8F5900A9A062ULL, 
            0x48CA9B651852D54CULL, 0x1204DD7427707962ULL, 0x88537E7574456776ULL, 0x064698390D101815ULL
        },
        {
            0xBD48E49684220925ULL, 0xB6FB72C291CC389FULL, 0x6B451DA99B0359D9ULL, 0x0CE84FF2C2AE1084ULL, 
            0x63E2396F71E08A9FULL, 0x9EFFD5F10396A0F5ULL, 0x63A7843331FDBD60ULL, 0x35F46B03209801D3ULL, 
            0xAFC296C2F0AA18F0ULL, 0x6CE1F1B5B2BF956AULL, 0x068C054D09BF939EULL, 0xC7DC40810F727402ULL, 
            0x5533B033DB54ABA0ULL, 0xE2D6E47064984D5AULL, 0xBE152A384F11E6A4ULL, 0x1D8678D8D8600AEDULL, 
            0x2627B5F4F8DCB765ULL, 0x0538A68900963834ULL, 0x3EAB8F892A83BD77ULL, 0xA42D827D76FEA242ULL, 
            0x964C8E144DFD7CBEULL, 0x268429E0B3B344CEULL, 0xC0CA3D67D105CD1AULL, 0xB6C2A1F6E4CE98C0ULL, 
            0x3CFCA7C1B94B7BC6ULL, 0xE8BA3AFEEA7B3642ULL, 0xFACC96C08CF6AD93ULL, 0xA6AFDA42AC73C000ULL, 
            0x643E29F26FE46D48ULL, 0x8F49D9D3C7DAE0A6ULL, 0x473260E25B6FB0FDULL, 0xF1CD828E64F57E95ULL
        },
        {
            0x9C295C48BB0FE902ULL, 0xAE5C8B6330A9C62EULL, 0x5DBEA9386C8F8AB0ULL, 0xBEEDFF561C524BD4ULL, 
            0xFFDBE483146CE4EBULL, 0x8525540322E85A77ULL, 0x6B8714F3D87B0660ULL, 0xE285AE0B1F668FFFULL, 
            0xB9BCA74C63566C30ULL, 0xECCD3B0BDAAA8713ULL, 0xC1BED886F87944FBULL, 0x92F6DA05E3004D00ULL, 
            0xC2797AB1B8DEEC12ULL, 0xFEEE56A4E5F0A8DDULL, 0xEA6DA96E415A9B36ULL, 0x4A5C60FE8F1F27EFULL, 
            0x5BCF8386DAF29D76ULL, 0x7BD1F337DD575C51ULL, 0x0CEF512F5822203CULL, 0x43617D9881FDA6A9ULL, 
            0x4F2CC97EF2188214ULL, 0x21F52CA786A87FCAULL, 0xDD061BE17FFE654DULL, 0x89AC776AEA6E17F9ULL, 
            0x7C5415227D9CE93BULL, 0x62FB3A7F39D21CDFULL, 0x9D780B1E58124587ULL, 0x8B40D667BCACAF68ULL, 
            0x81DF25D09DE62F74ULL, 0xE750E870ED1FB815ULL, 0x2188592F7481B655ULL, 0xE02ECC69F958D2EBULL
        },
        {
            0xE8B62CD12725A322ULL, 0xAC9BDC23BD684CC1ULL, 0x029B4A9181B774BCULL, 0x9FF5D0ADF5931CB7ULL, 
            0x3D8E4DBDCF5C5FE7ULL, 0x20A19F837CE65953ULL, 0x2FC9E210B3BFF80AULL, 0xDDBEABE8C4569EFFULL, 
            0xC7A8BD3BD376AD18ULL, 0x823C747A718FCA64ULL, 0x274CDC94B777DEEBULL, 0x3AC13B25FDCC4049ULL, 
            0x0134FB06C04CE043ULL, 0x88E06AED46ECF4C0ULL, 0x32F75A4BB6F45F7BULL, 0x8F6A5F99FD221349ULL, 
            0x0F7AE5A28AF1519EULL, 0x701B5DD78079B9F2ULL, 0x44700A623125B86CULL, 0xA6A14970CC126CBEULL, 
            0x930B0D35A186BC60ULL, 0x583BF91838231F50ULL, 0x0781FABEE24EB3EDULL, 0xF45556E00AEA2FE3ULL, 
            0xA29A57CCE57DB951ULL, 0xADAE2F26792DED9BULL, 0xFA897450028C2F0BULL, 0x45A32B6259951157ULL, 
            0xFB218410C9BD1BC2ULL, 0xD8D6B7EF332AA32AULL, 0xFE5F19E8723F2700ULL, 0xE62F9D052182DA32ULL
        },
        {
            0xF0EAACA9E365B7CEULL, 0x74FAD20C2E39EE48ULL, 0xE3013A574F829A4CULL, 0x5A4020175AB358BBULL, 
            0x763A79F36F67FF51ULL, 0x5BE2EB2F1D4CEF1AULL, 0x95ABAFF44671D2FEULL, 0xA0DF91921E63428DULL, 
            0x40A0F7F5BB024186ULL, 0x356CC3654A0ABB7AULL, 0xD32B1A4D644BBA39ULL, 0xA2653A3E07BCF23DULL, 
            0x4726C6B5FD845A75ULL, 0xDCD020C885515F03ULL, 0x423A0D94436D0BC4ULL, 0xED2B282A81292BE2ULL, 
            0x2946797024230E5DULL, 0xDDFA40346EDCE1EBULL, 0xBB9E15B9B027B68DULL, 0xC8F52796680EB51AULL, 
            0x73BA4B21FF1CC9B9ULL, 0x018E1537C465B72EULL, 0x7DE3E7763CAB74E6ULL, 0x93AD3575EF2FB9F5ULL, 
            0x774EB08CF1E6B72BULL, 0x3BA509EAAEE69F25ULL, 0x2A7A18A58AED93F6ULL, 0x84B3554F5C8AD69AULL, 
            0xBDD6D87FB1EBC42FULL, 0x4BDDF7586E54A1B1ULL, 0xC98628120320272BULL, 0xA5A626977DA88728ULL
        }
    },
    {
        {
            0x32850403D5792596ULL, 0x116F9ADB9644358FULL, 0x209F3B9C971599BAULL, 0xC8E8D8AC96A57B28ULL, 
            0x03CDDF2A6FBC0E25ULL, 0xAFA4F6058E8B0E90ULL, 0xCB37E7853D1583B7ULL, 0xB688B358776D9A48ULL, 
            0x9B898C0A1B9C50BFULL, 0xFC4C39890CF1C864ULL, 0xF810CBE4F7599EE3ULL, 0x7821C15C3E361B7DULL, 
            0x460447982C44F2AFULL, 0x00463A52B81D76DDULL, 0xB1F77CAA1B977919ULL, 0xF5A51A9D71E3D8C4ULL, 
            0x0195735F8A5CB944ULL, 0x25DFCD9257036891ULL, 0xCB1B68742E973A60ULL, 0x3090ABAA61667748ULL, 
            0x5F32B9EEA15E4F65ULL, 0x1C78AEB72E83190DULL, 0xA174C8212474F52EULL, 0x62B4EB683D352513ULL, 
            0x88BF2BFE152DC306ULL, 0xDE241E1291A22A9FULL, 0x8D934209E5BCEE24ULL, 0xA90E495C2F22332FULL, 
            0x035A54E3D0D41316ULL, 0x081BABDFF327A9B6ULL, 0xEEC31712BAEF15E9ULL, 0x635A60B6BEBB7A49ULL
        },
        {
            0xDE3D9EA26B786445ULL, 0xB6C783BB774403A3ULL, 0xCBA9AEF904FBCAD0ULL, 0x533CD574F97C6583ULL, 
            0xEA445404C8EFD016ULL, 0x53AB9D78B603D088ULL, 0x949C2FCA2B006AD4ULL, 0x0ABC7F5E1EE754FAULL, 
            0x29EDED222AF0FDD1ULL, 0x466C7CA97F5C877DULL, 0x4C5A07B5E54FFD10ULL, 0x1ECCC8929CDE9E50ULL, 
            0x4235021BCE78B2D3ULL, 0x8B4DCBD7FB32E9FDULL, 0x1E6BF66CD6239551ULL, 0xC36190A39C832005ULL, 
            0x879B6082E0B7C5EBULL, 0xC2D8EC745F8DA977ULL, 0x93F797D06A58EEDBULL, 0x579A3F6D372BF76FULL, 
            0x4D9E7A6F61C811F3ULL, 0x046A47544C60426CULL, 0x49AC71354D3B277BULL, 0x21CD9CA783E2ED9FULL, 
            0xCC2C365F704C2696ULL, 0xE6DDD753450CB34FULL, 0xF0BDC0B83CFA2B49ULL, 0xA626187A1F87171BULL, 
            0xCDD899D0A2870A0DULL, 0x8FF142F466A203FEULL, 0xF58E257DAAC8F41AULL, 0x1C1A5B03F792652BULL
        },
        {
            0x7BBA4E020474D95FULL, 0x2267FA29081AEA46ULL, 0xC5872203B7E2A9CFULL, 0x0C045218637ECBD1ULL, 
            0xE4FE2A5D5384F2FDULL, 0x920476F3CAA9D082ULL, 0x4A0AF16628445A67ULL, 0x99DA96A6F4AA8E6DULL, 
            0xD1DC8A019ECC096FULL, 0xEEAB8144498A436FULL, 0x73E37172E2815CE5ULL, 0xE98E6F28FA30A683ULL, 
            0xE39FF46D18260BA9ULL, 0x07FEF349AA60AAE4ULL, 0xD80ED9D6A21D1C4FULL, 0x86B3082A9D5D7926ULL, 
            0xD59D6078927EEE50ULL, 0x92EDD087128D39C1ULL, 0x0E05F56C9C87855CULL, 0x8263F0FAB6C3F2F9ULL, 
            0x10C28BE733036F00ULL, 0x6E12AE5B6C829DC8ULL, 0x9CB57256558DA3D3ULL, 0xA61972F851E1D9C3ULL, 
            0x4C6308FCD5ECDAE2ULL, 0x75661289D7C2903FULL, 0x9049F24089EDBF3EULL, 0xFF642966B54BE740ULL, 
            0x687D60C581EA92E8ULL, 0x5D2FE7B60F908FABULL, 0xC4D781CA925755A6ULL, 0xAEF0CAF4667A2FFDULL
        },
        {
            0x4D3021ADB6F9D21BULL, 0x1D48CFD727FFE311ULL, 0xE712C02BEADF018EULL, 0x233F74AE2089E2D9ULL, 
            0x6FD8BB2DCF9E50C3ULL, 0x270065F1074EE0DEULL, 0x1A6877A1100D6858ULL, 0xFD02C3F1ECFAE4BDULL, 
            0x4456F1DA0142CF74ULL, 0xD8575D78B86AF99AULL, 0x53316F65DD73125AULL, 0x8DB07064D336CEDFULL, 
            0x2946AC05AA153EA3ULL, 0xF6CAF6AB7583B35CULL, 0x6347FFF0817CAD24ULL, 0x6D7DC4680F9E6FAAULL, 
            0x2BFF14D4FF17E2ECULL, 0xFA993E7AA4BA91CFULL, 0xE334160A7FBC648AULL, 0xBACEB0142560EEC7ULL, 
            0xF4B2DA5426D3568DULL, 0xAA708D9AB5EB22FCULL, 0x514FEE22807A9E9FULL, 0x32454E82CE10B5F4ULL, 
            0x1F565EC2D24E5DC0ULL, 0xE342A3C29DB76C5EULL, 0x775AF5ABCCB60CBDULL, 0x2F01102A3D3C7703ULL, 
            0x3760995FD4A1C325ULL, 0x9727780586A09EECULL, 0x602EE9C71113EBF1ULL, 0x52A91F25BD695876ULL
        },
        {
            0xBB4A00F186A5C33CULL, 0x8990264DC39713B7ULL, 0x380A84C3055C921DULL, 0xA5E952EB9016897FULL, 
            0x22789AF344431115ULL, 0x04B54CBA7AA5E58AULL, 0x77D3AEE6CD67CCDCULL, 0xEDD4AC3F8257228AULL, 
            0xF72D5E9D99EC0B0DULL, 0xF8340DEC5B0B0EAFULL, 0x6BD2BD94A100027EULL, 0xED642C8C7356D775ULL, 
            0x239BCC381F1D7D90ULL, 0x661C19A974D44A02ULL, 0x5D4FF64CABABFC21ULL, 0x4FCF2373BA05C4E8ULL, 
            0xDAAFB55BE8565433ULL, 0xA68F1787EFB4EB21ULL, 0x7B6FFBF4957A0A9EULL, 0x4C0EF6CD7F610283ULL, 
            0xE9488D78E7996DCCULL, 0x5BA3859271F4942FULL, 0x0ED6D0B742708A30ULL, 0x5C5A2320CC9D8875ULL, 
            0xB61E089EE526B86AULL, 0x29D8889C21BD168BULL, 0xB83C71B93F5D38DCULL, 0xE090F5DA088E46F0ULL, 
            0x9D93A20AA4D6ABE1ULL, 0xAC058CE331772F06ULL, 0xABF70D5966DF12B9ULL, 0x2644631B3B6471C7ULL
        },
        {
            0xB26019D8298B4CAEULL, 0x57E7651795714AF3ULL, 0x584711E7EFBCE139ULL, 0x50A8A5C91C63FFC1ULL, 
            0x4BE7D4EDE7D128EBULL, 0x3184C50187F677F2ULL, 0x41220E3E7F735ABCULL, 0xB76E262D3F9567F7ULL, 
            0x0717E6E4958CAF86ULL, 0x9F95AB6578ABCFC3ULL, 0x1B7071F8349EDBA1ULL, 0xB9F4C64FFF533938ULL, 
            0x859D57323C5BDCC3ULL, 0x25306D8E8DD126FFULL, 0x5130308A088BDD4FULL, 0xB3662C54FAAF882FULL, 
            0x331F7FEB9048F9FFULL, 0x75B3B43A806A3558ULL, 0x89C8C3163A805DCDULL, 0xCDDB94730B74EC0AULL, 
            0x76F789A7530F7461ULL, 0xF878A32F0D20A92FULL, 0x21B499B0C5942BAEULL, 0xBF8E62E2138C145FULL, 
            0x84DAA0A1F24ADB25ULL, 0xC591CE3055ED44E0ULL, 0x92D842A56E883CB2ULL, 0xF7DD553ED5954B6BULL, 
            0xB2B9A83D25BDC0EFULL, 0x5240669B80303EE6ULL, 0xA2D534986AB4785BULL, 0x089376935F674D2FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseGConstants = {
    0xB32C14DAE1D66562ULL,
    0x1B4B6C45DCA05E2EULL,
    0x9FA65BEDE182A834ULL,
    0xB32C14DAE1D66562ULL,
    0x1B4B6C45DCA05E2EULL,
    0x9FA65BEDE182A834ULL,
    0xB6090E4A7D3C2ED6ULL,
    0xB3C89685C1611F67ULL,
    0x1C,
    0xAB,
    0x79,
    0xAA,
    0x76,
    0xA5,
    0xA8,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseHSalts = {
    {
        {
            0x9824EE9B01C38D4BULL, 0x76F7E26C10149FF0ULL, 0x482936C523E685DEULL, 0x373FB7DA184D7719ULL, 
            0x3D01F30C1F573B2CULL, 0x6C21482221A24AA2ULL, 0x6F6BCA1DF9271A99ULL, 0x9629A9CEE29C33AEULL, 
            0xA67E19147A5C0A9EULL, 0xB41372DE0F752DF5ULL, 0x2FBA0F5C7887815FULL, 0xA1C82D72BBC476BBULL, 
            0x42FD3E89E6902F2EULL, 0x2D0DFA9A711395EBULL, 0x01CBAF4FBB4301FCULL, 0xDB0E9F12195BDA12ULL, 
            0x63B52EAB28C8699AULL, 0x94F1E526926131DDULL, 0x273CE982CD901797ULL, 0xA978DF9ECFD6FEA7ULL, 
            0x6F6696A6D6600703ULL, 0x1E8601CE39C56774ULL, 0x8B888F2AF2A95F29ULL, 0x9B3BE132E6919219ULL, 
            0xDD8F1613609DC66EULL, 0xFCCFB3597BB3DE01ULL, 0xFDDE7AB6A6F3D805ULL, 0x53FA99A1F0583D6DULL, 
            0x1CE49663A84358BFULL, 0xE2E297F162456FDEULL, 0xBDDE06A272B139A0ULL, 0xD8291B7327CAC686ULL
        },
        {
            0x3583FD998DD07DE6ULL, 0x772FFE878A43AF8AULL, 0x969AE6FD9E15D412ULL, 0x1A38E91E960638D6ULL, 
            0xA18C806BA223A6BEULL, 0x8AABEFA5E523A0A7ULL, 0x28355E1C3459EDA6ULL, 0x17884F830F472380ULL, 
            0x1D3699544A9AAAACULL, 0x199C4DF49597D778ULL, 0x44029ECEA0D4DBE3ULL, 0x32D9F778EB3A92C9ULL, 
            0x5D53CD5D2893AE06ULL, 0xB12543C4DF2C4EF8ULL, 0x79E456E04FF9257FULL, 0xAB8D0F965F0685BAULL, 
            0xC0A28EDBEBC5446DULL, 0xFAC5D4465046A336ULL, 0xC9CB13ED0155B768ULL, 0x521F181F3604E44BULL, 
            0x54A7ADB26B93E062ULL, 0xD3C5F5E43A83DD1DULL, 0x20A72BE42AF181A2ULL, 0xA2B87516084B1AA6ULL, 
            0x958C2685B9C26BF9ULL, 0x65743C6C58338073ULL, 0x834D97A212DD109BULL, 0x258AD3805D0CB6C0ULL, 
            0x948E582B2B711A14ULL, 0x3D7B3BFA1EF14674ULL, 0x690241CF97B1C907ULL, 0x7D2F8FB89C6E616EULL
        },
        {
            0xFFF2B6B7B4321FBFULL, 0x99BFD28528ECCCEBULL, 0x3882337A0D045D73ULL, 0x481DAEF86B59943DULL, 
            0x2297A74F0A613F0BULL, 0xF3B5A5CEF1050FD2ULL, 0x7CDBFF2B4A3504E3ULL, 0xED213DCD39F758C6ULL, 
            0x3B0ACFC56254500BULL, 0x12CC403DF00652F4ULL, 0xB3AF17CF864B5937ULL, 0x1059C80997090F2BULL, 
            0x02D3BD13B4636D98ULL, 0x0B51FD0228B50F01ULL, 0x8D5B3C403EDF544DULL, 0x85C751D5A68C2521ULL, 
            0xDECD2D229E1C792BULL, 0x194D87A287B464C2ULL, 0x5BCBC34DF414C0EDULL, 0xB2BE6D681155434DULL, 
            0x21866FE72146667EULL, 0xF36F0FE4EC483B1CULL, 0x497A152CCE0C6A7BULL, 0x3DD02B74E7E4B393ULL, 
            0x10AE005A404B08A7ULL, 0x6B0912613D7ADE75ULL, 0x13F9A4EBDF641F85ULL, 0x258F7EB66DD8D9B1ULL, 
            0xE7C5F63EF9801DA3ULL, 0xD1569E2FAFAC4289ULL, 0xC830BE30A0978161ULL, 0x2CC097D92815296DULL
        },
        {
            0x2F3F9C33B48BF3DCULL, 0xD01C50E4A2AB954DULL, 0xE56C2F471168B1B1ULL, 0x71130DD71AD0C3E6ULL, 
            0xE125F5D97508E424ULL, 0x995C3AB1831681B2ULL, 0xC62B88E0ABA57FBEULL, 0x47A4B2094D216C30ULL, 
            0x1FD000FD0CBDD062ULL, 0xD7E442A7EF5D682EULL, 0xD15A96BF561E6599ULL, 0x2AA633331E0C4663ULL, 
            0xEF73489B80A0E7A0ULL, 0xE4CBDFACC4ABCDD7ULL, 0x7824A86672F64F66ULL, 0x22F950D198866816ULL, 
            0xB8243D3E9BB0DC84ULL, 0x85BA848025CDC950ULL, 0x52897BD0FFD82422ULL, 0x28D269B51C44096BULL, 
            0xFEB35A4329997822ULL, 0x41825A61406F54B3ULL, 0xD78A5F94A08653B6ULL, 0xED5CE1EDC379BFB0ULL, 
            0x5E0CE3AAE4AC628EULL, 0xD25F502F09839D5EULL, 0xF6306F2E8435AADFULL, 0xA95DCFFBA4E14A81ULL, 
            0xADB112F7100A2BBDULL, 0xBB8689E80A2827BBULL, 0xF95556490FC4C785ULL, 0x60169659FA3B2848ULL
        },
        {
            0x7492E159480947BFULL, 0x856C34A993071B5AULL, 0x8FDC126B44EBAF2DULL, 0x937F9F7B1099AE7CULL, 
            0x47DD0E96F7F8E0EAULL, 0x285F46A636A6A777ULL, 0xFD439FE72E10ED6FULL, 0x9929640F97A53BF5ULL, 
            0xA12DA60DCD035DBFULL, 0x87C9DA3E4AD5CFD5ULL, 0xF70BEE1402713B99ULL, 0xB5E56B8D1A36F56DULL, 
            0x5FFE6250470D68C6ULL, 0x61F94BD31DC799A7ULL, 0xDE3BEA197A68402FULL, 0x8A033C0AE1C25131ULL, 
            0xBEAC1BADF1912675ULL, 0x04DE2991C5D32DD0ULL, 0xB645F4A4B44356EDULL, 0x37FCF4E16C5DD7B8ULL, 
            0xB5751A4DBE20659AULL, 0xAA85388D7D623D89ULL, 0xDEE5CDF33E12D46AULL, 0x8EDA9FBD45F8F5E4ULL, 
            0xBB196056A8779A7CULL, 0xACBE82B0EB4804FBULL, 0xF5661D278722AE1BULL, 0x6322BEAC301F5ABEULL, 
            0x2A05F49676A14AF7ULL, 0xC51285F7B99C6DDDULL, 0xC216DCDF0C23AC20ULL, 0x6E8D8F9FD1187A8FULL
        },
        {
            0x2C685D4E5DA96C94ULL, 0xBE835347424CFA6AULL, 0x6C296F707AD67DFEULL, 0xBEA7EE1204070AABULL, 
            0x7CA424FA4F180BB5ULL, 0x7D26F0C7703772C2ULL, 0x2CAFBCC9CB9D72D1ULL, 0x2652046B08C72BE4ULL, 
            0x4A6A3EA9E4DF454CULL, 0x7B607DD3F809F672ULL, 0x24A2DA6F85231403ULL, 0xA4002009295EF695ULL, 
            0x80582002B791C322ULL, 0x222F89DA4C3939C8ULL, 0xE0C58E0890DCDB8DULL, 0xD72CCF6D1C1FA21CULL, 
            0x02C180C6DFA4D4E7ULL, 0x089E9DBCD0BB57ABULL, 0xC2F60EA65946920AULL, 0x8BB19E1CA39F9713ULL, 
            0x595FFDEA6E2767E5ULL, 0x138AB1330F9B52A6ULL, 0x40A63F06F166B48AULL, 0x4BFC2C39AEC5F552ULL, 
            0x3794CC974AC28AD1ULL, 0x0E22C8F0DE9AFBE9ULL, 0xE6D48F59D22B170FULL, 0xEF5B8476254E94C8ULL, 
            0x8915AE218EE9B97DULL, 0x6DF3B89E93CD3AAEULL, 0x91A3830E27F4C05EULL, 0x9242612B3FB94AC2ULL
        }
    },
    {
        {
            0xA37AE4956B580037ULL, 0x08A1AB5F1C29E961ULL, 0xB6B38534813022C2ULL, 0xCE3BF5C99CC6746CULL, 
            0xC08C5F0F73687F49ULL, 0xA6FDCA302BCE0189ULL, 0x4CEDB8808E013B3FULL, 0x8C794149DF7983E8ULL, 
            0x03D11725E015E1E0ULL, 0xAB125C4744E14E76ULL, 0xC08DF88DE44421AFULL, 0xC24B8424733259EEULL, 
            0x0EF7040EE2B807EAULL, 0x245149087935041AULL, 0xC347A841259FC630ULL, 0x796FF69D1755711FULL, 
            0x5EEF1F5AB3AA6B19ULL, 0x2DD8F13830F5C0DEULL, 0xF8CCAFB7E70E8BD4ULL, 0xF99F871E2C1A6871ULL, 
            0x0BDFEC93DFC21522ULL, 0xCA36C117CDDF683DULL, 0x2610478EBB11A9FFULL, 0x37905826593889C1ULL, 
            0x03CFA08C1C917EC0ULL, 0x1BC67CC47E56A71EULL, 0xAFBCD3D0AE8A7976ULL, 0xD5C5D82CC126861AULL, 
            0x4A951E41A8161114ULL, 0x4CD6B3D317F7F5D5ULL, 0xDD0F5601DD48A35BULL, 0x866EF68C3D590326ULL
        },
        {
            0x237991896E379B30ULL, 0x6D8861A041CB5ACCULL, 0xD90605CB66A137F7ULL, 0xE4BF0859CD88A222ULL, 
            0x18BDEB48A9F3D6D3ULL, 0xCB76EAE7E20E0116ULL, 0x3BF0AEEDF6E2B3CBULL, 0x069EE752575CCCFAULL, 
            0xEAAB428A237BAD6EULL, 0x8E2B5D4FCFDBB523ULL, 0xDF2736B38EBC2DB8ULL, 0x967BA6BD88117C26ULL, 
            0x4E75434F642368CEULL, 0xFD4D16922BC12AD2ULL, 0xCA8FE7426133C0D3ULL, 0x6C2B1116222C55AFULL, 
            0x853106AA6FE9169DULL, 0x1D8C28B3181C5254ULL, 0x23F3576630BCAD46ULL, 0xE83581B1384CAAEFULL, 
            0x0E4FCD569C985CB4ULL, 0xFBFBDEFD1B4A308AULL, 0x40571F8068CBC2EDULL, 0x0FC74C8992F6F53DULL, 
            0xB83D9E0D5144020AULL, 0x3470760255817473ULL, 0x0869A2F2A07D3AA0ULL, 0xCBA12299169B83BAULL, 
            0x9398A733F343AE45ULL, 0x315522EAE81FE2F0ULL, 0xA5B6C1AA1A7BB126ULL, 0x7A69F3006DFBC2B0ULL
        },
        {
            0x45E37D9AD79EB9E3ULL, 0xC37CF18ED4AB66F7ULL, 0xD7839F5C96803B51ULL, 0x680950CE5D2A9B17ULL, 
            0x22338CA4AD84B6A7ULL, 0x93002BC7C81FF242ULL, 0x52637F5DF993CFCCULL, 0xB5D7138B814AD2D4ULL, 
            0x9C60914FD83F4BB7ULL, 0x2EF8D7D265B70438ULL, 0x73059D6F9EE084F4ULL, 0xE348C770C677C870ULL, 
            0xA5ABBA78D7BFB829ULL, 0x0678936D0D00D76EULL, 0xCB3B451ADDB6AFF6ULL, 0xF117461AFAA5F9A2ULL, 
            0xECA34D2CC7F05A34ULL, 0x8448D9D147ECFE92ULL, 0xCB7802D87B0CAC1FULL, 0x89BCEC6F46DAB966ULL, 
            0x5AFD4F74C25E0E9EULL, 0xE999E17C553607C0ULL, 0x1A2DAC97CE33807CULL, 0xA2BE682E87985C1CULL, 
            0x1883B4C82790E486ULL, 0xE17BA3A9E9940DD2ULL, 0xCBC0FF9F265AE816ULL, 0x81F589D9411C4C90ULL, 
            0x6285FB3B238C0C3CULL, 0x9C1AF31C28B0A57DULL, 0xAE1F97B8206BDC25ULL, 0xB7C96D60CA0E6569ULL
        },
        {
            0x90C515C19F7AA887ULL, 0xF9CDF082BA602EBCULL, 0xBAAC597374BA1A2CULL, 0xF04D3B8520C850D7ULL, 
            0xBC1212CFE1B78B8EULL, 0xCF4E5F0BA688515DULL, 0xB21F22E9D9EB6A82ULL, 0x7F5BA3ADC23771D1ULL, 
            0xDD24CE094BB6EDE3ULL, 0x0242145BB6C3CC04ULL, 0x9860A0EE78A5272CULL, 0x333DD9C4E44E69C6ULL, 
            0xDB5B1858EF3E539EULL, 0xDDF6C0CDCB96C61AULL, 0xAD04F4AC6192018AULL, 0x762E45741919D757ULL, 
            0xF856CC93895734D8ULL, 0x001D77B3D7CE98AFULL, 0x12CE7BD44827B53EULL, 0x7E4F24D03A8C7DECULL, 
            0xEEBFF8BB8682814FULL, 0x50BF8A3CA5E3514CULL, 0xEA744BB8688DFB10ULL, 0x1DA50A87C45A1B02ULL, 
            0xFA4E11243B692450ULL, 0x8F1E78F1256B1680ULL, 0x255DBDED8B5E844EULL, 0xC10BCD55C02E428EULL, 
            0xF20A19E269DB7794ULL, 0x81872C1C3EB9FF24ULL, 0xB44223C51CC2B419ULL, 0xA2CC6AFBD3A81895ULL
        },
        {
            0x1214DA50CF9F5B5BULL, 0x528752DFEE5787C4ULL, 0xAECA28879B3E4FF8ULL, 0x8DEA5B73CDA57EF2ULL, 
            0xE795B964E5C470F4ULL, 0xD07A40C4FD6D4B4AULL, 0x87F2441080D11879ULL, 0xBB3040DB2FBED4FBULL, 
            0x5AE2367D3B3FC668ULL, 0x69D9ECFBDA64E532ULL, 0x88934B7C490D3C22ULL, 0x945F66603ECC47C6ULL, 
            0xED685CF51B649C41ULL, 0x2E7B470A2CC0661EULL, 0x0955FF0B5D633489ULL, 0xD258D0B4425C95CAULL, 
            0x2525A7B9E456DBE3ULL, 0x3F8096FB5CE30039ULL, 0x18D790D0F0AA613DULL, 0x1AF0BF9EF34F0F97ULL, 
            0x07E48C89BA911E1EULL, 0x04705FF5C1D1A7CAULL, 0x86AF30875DD27B16ULL, 0x27A1D8860CCF526FULL, 
            0xA57882267912D2EAULL, 0x16D5B99AD87D9A43ULL, 0x12C575D1FC846D47ULL, 0x2C193D0BB885334CULL, 
            0x52F4482B19D4EDE8ULL, 0xED9022BD1DD91A58ULL, 0xE762307F0140B551ULL, 0x11E8C91748E571FEULL
        },
        {
            0x19915178394104CDULL, 0xBE80529B46DE73C4ULL, 0x9EDCB40880676DE7ULL, 0x91DDAEB9C979E2B2ULL, 
            0xD5F1D886C4D15ED3ULL, 0x85C3788161FF3696ULL, 0xBCD0F77E70991CFFULL, 0x903F1702EDB64AA8ULL, 
            0xF2486D83E96931C2ULL, 0xD577968DAD9E253FULL, 0xAE3EEB67E8291BC0ULL, 0xFD7149F69389A230ULL, 
            0x413D8BDCD44CDC95ULL, 0xE7858AFDD256C770ULL, 0x4F07984425D71DD0ULL, 0xF59B300B3509CBA5ULL, 
            0xA95CD3A12FAE4877ULL, 0x9B98A09B6D14CC56ULL, 0xF1E5FF8E40C4E047ULL, 0x35185D958BF955DAULL, 
            0xFD1249BDBC9E61F3ULL, 0x0F349615382AF82CULL, 0xAFFAE835A247FC13ULL, 0xB6EF12EB78DC6888ULL, 
            0x74440F9BCA662CF7ULL, 0x2D2BCFE6EA857347ULL, 0x23E189A3B8931532ULL, 0x16A538A0DCA1529AULL, 
            0xC22BCF14CF2990F7ULL, 0x66919EB19FDDBBDAULL, 0xC49346082A3C61AEULL, 0xDFBCA1CE66383613ULL
        }
    },
    {
        {
            0x00B64744DAA499B2ULL, 0x6B369DA5BA4FED71ULL, 0xBA402935905A5045ULL, 0x3C639755E8E66BB7ULL, 
            0xD76E772FA50D9C3BULL, 0x0FF277F9E67E8BD5ULL, 0x5D0C7EA96F79B88BULL, 0xAD6278B192FD0CE6ULL, 
            0xD265C7437F10178BULL, 0x986C8C6DF0F405FBULL, 0x9F531E5CC179DABBULL, 0xDC88A31B7A6CC80DULL, 
            0x7D4E6910CD4997E5ULL, 0x08C415C4B45B9A88ULL, 0xAFCE9B766331E9FBULL, 0xFAD0D13AFF50B8D1ULL, 
            0x8FD17E8B5973F404ULL, 0xA0543408FDDF3031ULL, 0xBC08A10630FD0B7CULL, 0x540CD80A802212FFULL, 
            0xFCF202D4C8223696ULL, 0xB38E38E18CD91E92ULL, 0xE17CD5A1FAD329C1ULL, 0x0ED0A2E1243E86CFULL, 
            0x080FD54C6FE78115ULL, 0x4EF927109FEBFF78ULL, 0x7EF2FE212A4816BAULL, 0xAAB2597E3226F6D9ULL, 
            0x4CD5CEC18BFA0DCAULL, 0x310635ED55E8099BULL, 0x1E30AA4C8177318FULL, 0x82082AB917A817B3ULL
        },
        {
            0x01B668CD7B7893FCULL, 0x7C91C0E0C91DA809ULL, 0x8E689D089FA0F60EULL, 0xC46395C705B3B107ULL, 
            0xAEAB9C066F0BE596ULL, 0x86B47AD6925C2985ULL, 0xEFECBFF3CDF0869DULL, 0xBF4F3ADD649F828DULL, 
            0x50E2D5E35753E84AULL, 0x18A1A802E032C86AULL, 0x8768B61D43C8B40AULL, 0xA38492FFDDE4C6A9ULL, 
            0xC4C6D44356719ED1ULL, 0x7B7CB25FAD70F194ULL, 0x67F65BE9698A3001ULL, 0xAC17D505F8A71FB1ULL, 
            0xEB6E258414471112ULL, 0x43C8C21A2A81DE0AULL, 0x30D59C3349453D0BULL, 0x6F418B15769B8E55ULL, 
            0xADD23D7633AA66B9ULL, 0x287D94986B245D95ULL, 0xC0E31E70F885C161ULL, 0x9F1AB6B98EB91710ULL, 
            0x40060FF7F8947530ULL, 0x565A1B233ED060F3ULL, 0xA44C2B87D1BD4E71ULL, 0x60A1440466080707ULL, 
            0x7695CE53C6F06E61ULL, 0xA55E820C33299ACDULL, 0xBB479944A554548AULL, 0x77CE5B4A1B74E609ULL
        },
        {
            0x758898C27C138E34ULL, 0x6314350380F3EF29ULL, 0xB43BFD2791109922ULL, 0xDBC9A3B2D1996CDDULL, 
            0xA81A213D5EC5C8FFULL, 0xADB7EEC48283968DULL, 0xE5D94CA7A32598BFULL, 0xFE870B201C388452ULL, 
            0x986E0B298F195FE7ULL, 0x48B4B3234DA2A563ULL, 0xCDB65C2F7F9D0779ULL, 0x098B79B5C795F97DULL, 
            0x5DC2ACE44AC2FE54ULL, 0xA5C400EDC4CDA42EULL, 0x32D9BDAF79D0B6F3ULL, 0x0EEB58E38E42C594ULL, 
            0xB6360F92D9040426ULL, 0xD7318E921C763493ULL, 0xB257B4C7A3FD1263ULL, 0x894E970522ED8F19ULL, 
            0xAC4AB0CE3E5736D9ULL, 0xE5567B0099C0979AULL, 0xA02C16BFAE6F68E4ULL, 0xB2AD4B22913353F0ULL, 
            0x8B337068F1D5D86CULL, 0xFD6EFFA82D311C3AULL, 0xBDD9F558A5FA5BB7ULL, 0xF6D54B659A9EB33AULL, 
            0xA2D92024695C44EBULL, 0x5E783A18F2DF9E07ULL, 0x5EFB6E5585B45544ULL, 0x4611C467E6E6806AULL
        },
        {
            0xF54C989B879FD58BULL, 0x44F7A71C05BE5623ULL, 0xBB034E9646FD03D0ULL, 0x60EFD802733BB890ULL, 
            0xDC37CA268F7B0AE2ULL, 0x088AAF45DE85D48FULL, 0x857A646B9E1638D3ULL, 0x2BCAF7903E4354BAULL, 
            0xAF1EAA404BAF2661ULL, 0xC12B388968D45836ULL, 0xC04FC1EA14233607ULL, 0xC4683806990C51B5ULL, 
            0xC68E64A691A11088ULL, 0x199A4F5256222159ULL, 0xBC5378591A08E69FULL, 0x3C86AC80DB373344ULL, 
            0x1AB2300CF3E1013EULL, 0x23EEE31EF8E2CC71ULL, 0xA07AC7B00D33BF45ULL, 0x1C351177C25A7A1AULL, 
            0x525707B6355E52B3ULL, 0xB95E7FE676F0944BULL, 0x814DEBA816CA0630ULL, 0xFD18DA87B1769D7DULL, 
            0xD57F6258AFD95775ULL, 0xD03B2029E42C6DF2ULL, 0x849D8855BF7FFF75ULL, 0x9A74B46C76191F1EULL, 
            0xAA2DBC5A094275B6ULL, 0x8AA57DEECE6DAAE8ULL, 0xCDF58C6BC54526A0ULL, 0xDCB93CAFB189C23EULL
        },
        {
            0xF52C877478C5922DULL, 0x37AB2B242D9D7C43ULL, 0x5D46C34D95B05360ULL, 0x3B58F7EC0BD72B7AULL, 
            0x26B6C2CBD41BCA95ULL, 0xF7BA417CCC164DB7ULL, 0xC7F1450B1417A44AULL, 0x44C3A81ACE40BEF0ULL, 
            0x1ADAC2F64BE9011AULL, 0xDBF687406D2F63ACULL, 0xF9860E7CB235CD83ULL, 0x1C2FF6A53BF26406ULL, 
            0xD42965702E0F7809ULL, 0x5E7F071121E7AD45ULL, 0xF7BD27EED75519ABULL, 0xBDFEC7F26B4E7492ULL, 
            0x4CA4534DBA3B424CULL, 0xBA437A8B6617BE91ULL, 0x1A59B72760088610ULL, 0xEA02B98BB6D609F9ULL, 
            0xC5376C7DD6814B35ULL, 0xE43CEC5855412C27ULL, 0x113B0A5B3B516537ULL, 0xFEC2070B24495A3AULL, 
            0xDE15B87C7DC2F9A3ULL, 0x40A7C8D4F9DD23A0ULL, 0x43CF1EB9B61E38E5ULL, 0x010396A53F581277ULL, 
            0x33B5797688E4ED2AULL, 0x5771B3A2214C8CBAULL, 0x9CCAB3B98A6AE892ULL, 0x48E541C03C0259AAULL
        },
        {
            0x68549F0DA8B1A955ULL, 0xA6CE676A944BF9E8ULL, 0xB0E46C7F47859201ULL, 0x374E8A34F3EED1B0ULL, 
            0xCFF9214C33BA4821ULL, 0x0F37FC9C66507F4EULL, 0xD3E432C7C56D86FCULL, 0x2B878CE8EB1221DEULL, 
            0x658CB013C3EFADE4ULL, 0xDBFF91632D2A29E4ULL, 0xF368001123F0F280ULL, 0x74414E817D13B626ULL, 
            0x55C01E5B9D9685C2ULL, 0xBB5E7A9F36E47C35ULL, 0x0FCAB65E95B53916ULL, 0x1FD23B4563269061ULL, 
            0xE02A704932F42C3FULL, 0x3126A2DAC63EA405ULL, 0xECD84369162E0690ULL, 0x31A288D77C4251ACULL, 
            0xE3BE302C34994D60ULL, 0xD7526EDD111851CDULL, 0xE4077480C9B69948ULL, 0xC84F7FAE7460E699ULL, 
            0x5EE1744F8DD7F0ECULL, 0x966468D01F37986BULL, 0xBCC304683C23CCFFULL, 0x0EFD6647E95ABCF6ULL, 
            0xC6DB6CEC5B67EF3CULL, 0x4CD69D4FC95A4F27ULL, 0x75376DA1CB7457F2ULL, 0x7F8093C840EE26F9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseHConstants = {
    0xFAA63287B5BDAB46ULL,
    0x3F9D15FAD013599EULL,
    0x210D72089DC85178ULL,
    0xFAA63287B5BDAB46ULL,
    0x3F9D15FAD013599EULL,
    0x210D72089DC85178ULL,
    0x582B13DA6D25B984ULL,
    0xB2BF7A09821A0DA0ULL,
    0xD0,
    0x03,
    0x4B,
    0xBA,
    0x2F,
    0x44,
    0x01,
    0x83
};

