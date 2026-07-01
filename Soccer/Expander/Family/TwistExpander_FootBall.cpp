#include "TwistExpander_FootBall.hpp"
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

TwistExpander_FootBall::TwistExpander_FootBall()
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

void TwistExpander_FootBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA422E2263488247DULL; std::uint64_t aIngress = 0xC4126918072500B4ULL; std::uint64_t aCarry = 0xDEE34FFF8BCC66DCULL;

    std::uint64_t aWandererA = 0xC51B85B4538EBEDEULL; std::uint64_t aWandererB = 0xF56845510E5646F9ULL; std::uint64_t aWandererC = 0x9C0C5918F99CCED8ULL; std::uint64_t aWandererD = 0x9EDD5D22AF60F556ULL;
    std::uint64_t aWandererE = 0xA2AF3036171A3C6EULL; std::uint64_t aWandererF = 0x8331A7569F79398BULL; std::uint64_t aWandererG = 0xD258215F3AC6AC52ULL; std::uint64_t aWandererH = 0x8B8041FFA66DD85BULL;
    std::uint64_t aWandererI = 0xF1F14DAA317256D8ULL; std::uint64_t aWandererJ = 0xF12B5D0FA865A1FFULL; std::uint64_t aWandererK = 0xFD2292CA8130DD60ULL;

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
        aPrevious = 11043743625654425852U;
        aCarry = 10947244040098179524U;
        aWandererA = 10664141863815086439U;
        aWandererB = 11416009645159518578U;
        aWandererC = 17738447890371189618U;
        aWandererD = 17268486042554732220U;
        aWandererE = 17073279256375403710U;
        aWandererF = 13183231705979801543U;
        aWandererG = 13336808827358733863U;
        aWandererH = 15620020966370366583U;
        aWandererI = 10116367760025655067U;
        aWandererJ = 14977828898455328985U;
        aWandererK = 10203857338461205435U;
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
    TwistExpander_FootBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_FootBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xF104DA8DA4853FE9ULL; std::uint64_t aIngress = 0xEB79E1F44C455732ULL; std::uint64_t aCarry = 0xECE3F84180CBD393ULL;

    std::uint64_t aWandererA = 0xE22EE73503E22FB9ULL; std::uint64_t aWandererB = 0xA7DE85A6E66F35EAULL; std::uint64_t aWandererC = 0xDE7ECA6CD2C902CDULL; std::uint64_t aWandererD = 0xE09131C38DC74D68ULL;
    std::uint64_t aWandererE = 0xBB1BC82008936907ULL; std::uint64_t aWandererF = 0xB520F3D9C3641C15ULL; std::uint64_t aWandererG = 0xBFAA247178148C2AULL; std::uint64_t aWandererH = 0xAD865E32F3B12CF2ULL;
    std::uint64_t aWandererI = 0xD556DB1797E493B3ULL; std::uint64_t aWandererJ = 0x8255DDDAC6E80C72ULL; std::uint64_t aWandererK = 0xD8972C3267C0EA2CULL;

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
        aPrevious = 18390353511110093116U;
        aCarry = 9436434674456162222U;
        aWandererA = 13142959455394881457U;
        aWandererB = 16195883007949286139U;
        aWandererC = 10453222694274120133U;
        aWandererD = 12323405631051549976U;
        aWandererE = 14288561747661800418U;
        aWandererF = 11996077840865297919U;
        aWandererG = 16288811083400384326U;
        aWandererH = 17586974634692831681U;
        aWandererI = 18446062621427631204U;
        aWandererJ = 15764060886744098042U;
        aWandererK = 13004836365998291369U;
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
    TwistExpander_FootBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_FootBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_FootBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA42ACCDBF4DD97A9ULL;
    std::uint64_t aIngress = 0xCCD64B48D9BCCA07ULL;
    std::uint64_t aCarry = 0xD5E58D380437CD20ULL;

    std::uint64_t aWandererA = 0xB2BF8EB301C3C4E1ULL;
    std::uint64_t aWandererB = 0xA43EBA0DA09BE7E8ULL;
    std::uint64_t aWandererC = 0xE8F18ED134D6D52BULL;
    std::uint64_t aWandererD = 0x9DCD66FE7CE7F277ULL;
    std::uint64_t aWandererE = 0xAA2CFDC992808CE0ULL;
    std::uint64_t aWandererF = 0x8D0B1792A03BC0C7ULL;
    std::uint64_t aWandererG = 0xC631794240EF976AULL;
    std::uint64_t aWandererH = 0x93715C6095BF7C67ULL;
    std::uint64_t aWandererI = 0xA35FE1F7288EE59CULL;
    std::uint64_t aWandererJ = 0xA910143C41F2D016ULL;
    std::uint64_t aWandererK = 0xF3E0C7B57E763205ULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::Aria256Counter(aSource, aSnowLaneB);
        TwistSnow::Sha256Counter(aSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    TwistExpander_FootBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_FootBall_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_FootBall_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_FootBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_FootBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB7C273E07F4769F2ULL; std::uint64_t aIngress = 0xE6E42C21E664668CULL; std::uint64_t aCarry = 0x988E2262EACC601FULL;

    std::uint64_t aWandererA = 0xE566106D52F76997ULL; std::uint64_t aWandererB = 0xA2F553DD14465F50ULL; std::uint64_t aWandererC = 0xB43FF202780B63ECULL; std::uint64_t aWandererD = 0x9EC3BEF347A0360DULL;
    std::uint64_t aWandererE = 0xFFC59778E9668133ULL; std::uint64_t aWandererF = 0xC2D58B8DB96C7ABBULL; std::uint64_t aWandererG = 0x878245BBED934BAEULL; std::uint64_t aWandererH = 0xE0E3C6B79C8753D5ULL;
    std::uint64_t aWandererI = 0xCE2938DD0F29FAA9ULL; std::uint64_t aWandererJ = 0xD5AE35F1192D93C8ULL; std::uint64_t aWandererK = 0xAA6FD29DE3DC6A78ULL;

    // [seed]
    {
        aPrevious = 17857679910142485483U;
        aCarry = 10639604493469265029U;
        aWandererA = 15033961289702159257U;
        aWandererB = 17850662130094809689U;
        aWandererC = 15811470435726982131U;
        aWandererD = 10777372610772945487U;
        aWandererE = 14109136539239213032U;
        aWandererF = 13463186085337837149U;
        aWandererG = 12460032497941058042U;
        aWandererH = 15741689218259323547U;
        aWandererI = 14600320371040017661U;
        aWandererJ = 17345828099536281887U;
        aWandererK = 15696169890885150637U;
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
    TwistExpander_FootBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_FootBall_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_FootBall_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_FootBall_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_FootBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 3, 1 with offsets 5588U, 7641U, 7160U, 290U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5588U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7641U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7160U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 290U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 2, 2, 0 with offsets 1765U, 2685U, 6522U, 7882U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1765U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2685U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6522U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7882U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 3, 0, 2 with offsets 75U, 3342U, 6809U, 1840U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 75U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3342U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6809U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1840U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 1, 1, 3 with offsets 6026U, 7980U, 4623U, 6798U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6026U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7980U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4623U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6798U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 2, 1, 0, 3 with offsets 785U, 1873U, 1236U, 882U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 785U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1873U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1236U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 882U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 1, 0, 3, 2 with offsets 1164U, 44U, 794U, 675U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1164U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 44U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 794U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 675U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 2, 0, 3, 1 with offsets 1130U, 990U, 175U, 941U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1130U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 990U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 175U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 941U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 1, 0, 3, 2 with offsets 836U, 560U, 1130U, 681U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 560U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1130U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 681U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1727U, 452U, 1175U, 1297U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1727U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 452U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1175U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1297U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_FootBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 0, 3 with offsets 2961U, 3824U, 2109U, 1604U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2961U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3824U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2109U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1604U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 0 with offsets 6178U, 5403U, 7676U, 1186U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6178U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5403U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7676U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1186U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 2 with offsets 230U, 2861U, 6499U, 5038U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 230U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2861U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6499U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5038U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 2, 1 with offsets 545U, 4038U, 5417U, 4580U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 545U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4038U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5417U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4580U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 7917U, 7024U, 6661U, 3814U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7917U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 7024U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 6661U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 3814U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 728U, 291U, 768U, 1996U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 728U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 291U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1996U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 992U, 1063U, 1945U, 1530U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 992U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1063U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1945U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1530U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 670U, 1399U, 354U, 1949U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 670U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 354U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 165U, 838U, 976U, 1960U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 165U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 838U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 976U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 1817U, 1083U, 986U, 819U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1817U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 986U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 819U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseASalts = {
    {
        {
            0xDA35F20D7F2D9703ULL, 0x0238FFD6DDE82F1FULL, 0x8F79D3A26FD259F0ULL, 0x407DC798E143DC5CULL, 
            0x90BB1E93353E8F08ULL, 0xC586618BE8D53160ULL, 0x3E838C3648D2604DULL, 0x13ACFBC4C6C63058ULL, 
            0xECCBA2EC4947430FULL, 0xE86DA61DA5CF7B91ULL, 0x6AAFA9FFFB9146A1ULL, 0x71301886A0F9D29EULL, 
            0x46753CB9AB29F70DULL, 0x3C221859C1203F06ULL, 0xEFF63B885FF4AF2FULL, 0xB65527392AD7861DULL, 
            0xB9DB1A545EB546D7ULL, 0xDB02C58DD83FA4E1ULL, 0x8E43074CE0F18FD7ULL, 0x285622135EA93E38ULL, 
            0x52C58498988B228CULL, 0xC4C6F6AB2AD295C0ULL, 0x51F064547FD33EDCULL, 0xA3B7A23A9E5ED948ULL, 
            0xDE2ABFA793BC8670ULL, 0x197B28A3AA6C6734ULL, 0xA3CEE45A0D1BA7ACULL, 0x87E2BB1D5B7C6282ULL, 
            0x1F891C5FC82B31E9ULL, 0x3FFB6DB92B417021ULL, 0xEA7376C7AD6528E0ULL, 0xD73F09458A12F391ULL
        },
        {
            0x0E8B5ABCBC99BE8BULL, 0x812E873F7DE2E831ULL, 0x662D022C922E3322ULL, 0xFACE641E9EDEACCFULL, 
            0x13A59A79CD5BA630ULL, 0x744447DC52F6779FULL, 0x05F749B66CC73413ULL, 0xDBA96532093B1FF7ULL, 
            0x47B72C9A6D3DE4C4ULL, 0x4A1BB33CECCA707FULL, 0x18D2FFD4E49877E4ULL, 0x29406B39D113FB1EULL, 
            0xC30CC41B5CF64792ULL, 0xE71F8D710EE21490ULL, 0x533D2245A1137901ULL, 0x9E5715364640BE52ULL, 
            0xC2029222050946C4ULL, 0x07B2DF89C2C3E69DULL, 0x22AF64EE725222D2ULL, 0x670693EA6DAF0A34ULL, 
            0xF32C6C63589A6D26ULL, 0x5ADCA3DEE31D7AE2ULL, 0xC3B691356C9B9DC6ULL, 0x450216FBD7A1486CULL, 
            0xB3192A4ABE229EEAULL, 0x11BF559D21695C0AULL, 0x46741A9C1785A0D3ULL, 0x70F177E9E5592454ULL, 
            0x0B3286A9A9310000ULL, 0xEF12A39175F3DA6FULL, 0x28EFDB6053B2ECF0ULL, 0x70EDA759869F7CC4ULL
        },
        {
            0x38C6A2D90330428FULL, 0xDFAF0B97E38CBEC1ULL, 0x841829B7C1F4BA20ULL, 0x1081EBCDD596B4A0ULL, 
            0xBEE3A0D83F72F7FEULL, 0xACED36936BD6DCD2ULL, 0x9E38898BDF1FF18BULL, 0x028C0062C86B0D43ULL, 
            0x0A998B65E408DF31ULL, 0x8E8BA09A7D660A37ULL, 0xF784460B80ECFDF6ULL, 0x4CAAD8080405BF2BULL, 
            0x608D316E34545178ULL, 0x673A20B91EAE3D5BULL, 0x8E78304CC7716FE4ULL, 0xAFBA14BD641DC801ULL, 
            0x26DB84D74D4E029BULL, 0xE1D759CCE9A4D3A5ULL, 0x1D6CD99A89C2374FULL, 0x065150BC74CA61C8ULL, 
            0x0AA039B18F6203EEULL, 0xC9AFB251D6F50FAAULL, 0xC143ADCBD521A4B2ULL, 0x852013D51497635BULL, 
            0x02E73C53694B2616ULL, 0xD66CEE7413A07DD2ULL, 0x97669F47FD1307B2ULL, 0xFB026650D0C1F21EULL, 
            0x2D9A329796FD54B9ULL, 0x331DCA0D5F0CA914ULL, 0xAFF1B3419319925EULL, 0x820C44CC0346F4E9ULL
        },
        {
            0x4AB07C7E1B9DDAF7ULL, 0xA4F18052CDD1405CULL, 0x9D08E98FD5ED07FBULL, 0x8202FDA0D723D39EULL, 
            0xA3B10540AA646EF5ULL, 0xB0D9C15632990A2CULL, 0xD481549D5F67834CULL, 0xED052E6281957020ULL, 
            0x5ECE10EC9413D9C8ULL, 0x5EC7D2D3BFB71C70ULL, 0x1C3BAF5EEF3F63AFULL, 0x9D6E647B1C94F02FULL, 
            0xF295DC72594A8519ULL, 0x64ED5D9A616BABFAULL, 0x042199F76866C797ULL, 0xBB4EAD4403D0B6DBULL, 
            0xF5802579908E5B0DULL, 0x27228B018C08D95FULL, 0xBF704F7B93D31910ULL, 0x9B97D65B487E4AACULL, 
            0xF62EF1DABD059780ULL, 0x24FF66431FB04E6AULL, 0xDAF82A317127CAA6ULL, 0xEE7E6C7BD18FFA3FULL, 
            0x81284BA1861F096EULL, 0xEAA07487BDF7363CULL, 0x6C1CDF837B3A269EULL, 0x5D7BF79C2599B0B8ULL, 
            0x0574865BFC4D8788ULL, 0x8EC2B640862874E2ULL, 0x4564422CBDF83A25ULL, 0xB39C0826DBB914F2ULL
        },
        {
            0xBF5817610AF0549FULL, 0x7397060C08CF2ADAULL, 0xFAFC5291C5A35EA0ULL, 0xAE56AE7BA5AD38BCULL, 
            0xD935189BC5A2CDA1ULL, 0x55906F73C734FFC2ULL, 0x43D8D312755BDEF5ULL, 0xE353DD77879B22A9ULL, 
            0x23184171FFBC59F2ULL, 0x433DF35BAF8AAACDULL, 0xD7B9BF1AEB2082A5ULL, 0x1500B6DAAC7B8B15ULL, 
            0xE1AF7D1DCE8041EAULL, 0x31D774F6CB2303E5ULL, 0x66FCD6F47A9D4E0DULL, 0xB6458B5D4CE1D154ULL, 
            0xE863BFFA7A6A9A02ULL, 0x0F471BB6F19CA544ULL, 0x39C4C0E28CF05CD4ULL, 0x723A7B34F22346DEULL, 
            0xBDF9F1D849C34F15ULL, 0x21FBAA4BF7FBFE4BULL, 0x4691CD2B038A9D68ULL, 0x98663B9F3D544965ULL, 
            0x6C680916F897CC85ULL, 0x62E867503EA4224FULL, 0x7B0007129A5258EAULL, 0x9B6A48FC20E6EBF6ULL, 
            0x3D49244890607FF0ULL, 0x418C2C79E3474F0DULL, 0xA052730037E97AF0ULL, 0x2DBE7F4E8D68CBA8ULL
        },
        {
            0xF990AD90707FB374ULL, 0xC15064C36BD73E1CULL, 0x3D059F7D615B156BULL, 0x0992A7B12D533C67ULL, 
            0x906670532BA94D37ULL, 0x696C63E2032B4830ULL, 0xD63305FAA912E675ULL, 0x9E438C4282D048B0ULL, 
            0x0EC9CDC0C76D046BULL, 0xE20F20BB7403E7DCULL, 0xBFB93B31CD624558ULL, 0x490C51BEC95D34EEULL, 
            0x118E381B64BF444AULL, 0x46E2AD0EC97BC94BULL, 0x434F4CAA083C0B8AULL, 0x663E3EFA63562D64ULL, 
            0xDA438141E20F1A8AULL, 0x16F7DF14283A4CB4ULL, 0x13025CE601D9E77FULL, 0x0496EFCCA10DDEA5ULL, 
            0xF3832303544DEF58ULL, 0xA277ACD4E7BF2A9BULL, 0x468CD9D1B5897431ULL, 0x7ED495C4CEAD1E4AULL, 
            0x96D5C7E4085E63CCULL, 0xD27A6EDEAFA2DAA5ULL, 0xC52A6F2B456AA20EULL, 0x75006D2DF018F341ULL, 
            0x65ACDFF56CE5FE04ULL, 0x3209A1466F82B7EEULL, 0x93173ED45A9EDE86ULL, 0x697C5620386F0C36ULL
        }
    },
    {
        {
            0xFE15A9E15984AEA6ULL, 0x7CD96889A00042EFULL, 0xB2BB23EDA409FF6BULL, 0xB24C7D7A620EE1E8ULL, 
            0xC6A870B146B768E5ULL, 0x6D4A587C6F6B41CCULL, 0x16736886CA24D067ULL, 0x1C91685C2AEDAD7AULL, 
            0xC09CFC5D23085671ULL, 0xB73191A1F87ECEA2ULL, 0x03DADF598948DE84ULL, 0x2100E3929013343CULL, 
            0x730D376C94A414FEULL, 0x15617171775472EBULL, 0x396017F98D365F42ULL, 0x1ECEDEB6E53AED9BULL, 
            0xF09CE8CCE6ACB1C2ULL, 0x865DE4BE0A8C02F1ULL, 0xFA5D59E02D26261DULL, 0x0E56D8AFA70E74A9ULL, 
            0xA0794772FDCC0C3DULL, 0x01C8E05FAE35D064ULL, 0x51CA14FAB8B81001ULL, 0x1F91F23760B84CCCULL, 
            0x1DA53380EB654C73ULL, 0x45BA77A67D209AC9ULL, 0x5E229E7D11379EB5ULL, 0x7668617DE3E89A7AULL, 
            0x3BF876C883E1B052ULL, 0xF364A30743110FC7ULL, 0x2920B3BB5A9FA413ULL, 0xC0C38D1EB7E17E3AULL
        },
        {
            0x13A709F4058AF495ULL, 0xF44278B4EA6F0250ULL, 0x002E3B4B631C36FDULL, 0xCD777DE6AD4968ACULL, 
            0x8050E94D57991C7EULL, 0x9B36B6292B4BA6B8ULL, 0xCF773109EBA81FDEULL, 0x75EE6064416CB553ULL, 
            0x052D3C30C14B4614ULL, 0x2F8136447CF7B6E0ULL, 0x7BC4BF4080697040ULL, 0xB4AD269C19434870ULL, 
            0xB2CEFA299796876AULL, 0x95BDCD2EE67741C0ULL, 0xDB4D01B4D2CEA476ULL, 0xE39C9B5DBC15DA96ULL, 
            0xB761F6F9B13B5E60ULL, 0xA7F39C19FEEA0E4FULL, 0xC91F1774C2067B4EULL, 0x41C8F70356FCE985ULL, 
            0x41863A329A80E28DULL, 0x487A9E8B28F4A11AULL, 0xECDA13592F433236ULL, 0x80C2CFF550A7ED75ULL, 
            0xC026AC292A464657ULL, 0xB8BF107761FDCB3EULL, 0x41FFAA557103BCA2ULL, 0xEE87AEE49143AB26ULL, 
            0x051FE1116316029BULL, 0x141C110F0B7ABED1ULL, 0x6AB0C0573A0D66D9ULL, 0x7124D99EAA0B910BULL
        },
        {
            0x7051750AC279B9C1ULL, 0x347F565DB847BF4EULL, 0x351F0BE93B841669ULL, 0xEFE1F4868A967A9BULL, 
            0xF28B8BFE4B97D1C2ULL, 0x6BCFC409D7F8BFBDULL, 0xF90F0065C044225BULL, 0x6EB8DB4F4D764D01ULL, 
            0x18D1D0774C6D6BDCULL, 0x1DFB7DE466B8B280ULL, 0x8B6DE8E53E1304D1ULL, 0x9547D1434D0636A3ULL, 
            0x4F4F333545453A0CULL, 0xFC71E7E8AF2CAA0DULL, 0xA948ACAB57CB1767ULL, 0xCF8484CFCF374A72ULL, 
            0xCE8E68C3C1445701ULL, 0x3433ED4E3F5C5D1BULL, 0xEB93C581DB0547B3ULL, 0xAEEF150754A1DAABULL, 
            0xBC290AED4919CCF3ULL, 0x6EEE73593D62EAB7ULL, 0xE34BED3D65854C31ULL, 0xA7613C647A0CA0C9ULL, 
            0xC2FD261A41337565ULL, 0xF10C80D13A57D494ULL, 0x96F5B1B0B9C98B55ULL, 0x88940A12EE647D37ULL, 
            0xC54D41481208AA0EULL, 0xA1A84766EF4A19A6ULL, 0x7E21FD2BF7AA90E3ULL, 0x9E7269EB22FACE31ULL
        },
        {
            0x8D7F6442F665F1EBULL, 0x722A7F8DB59397D1ULL, 0x88B3D7B9330E83AFULL, 0xB13169BB3ECFF28DULL, 
            0x305A147DAA5AD4A1ULL, 0x40CD2E9FC8CAAFAAULL, 0xA94CCABC7BA9A403ULL, 0xF5EF82DE9158FC47ULL, 
            0xD61DAEF611EC0354ULL, 0x5C0E95AB7A7A36C8ULL, 0x68DEC71765A9048CULL, 0x44C80CD828235E30ULL, 
            0xE75C2DD94DCD0913ULL, 0xFB348377CE7CF791ULL, 0x0E089E936DE19C20ULL, 0x1225935B775E68ECULL, 
            0xE17EA237D6E9898BULL, 0x635E22614A3B7660ULL, 0x0B4B3E5CC62ACBDAULL, 0xA9DCB55B91CD93D7ULL, 
            0x9D800DFE19B45DA2ULL, 0x8A41A993DCE5F1AAULL, 0xDA06E583AA45BD14ULL, 0xA7B88EE9BCCA9010ULL, 
            0xD3A801BD821C17C1ULL, 0xD194F3E4EB0736A2ULL, 0xA3524FC0E432E801ULL, 0xFF8C1B2F2125617DULL, 
            0xA4FCA7E865EB2B23ULL, 0x722C526DA3DE70C9ULL, 0xAD3BEAFD788AE6C1ULL, 0x38082FFBCAA9994DULL
        },
        {
            0x62C9CA9B95B44D5AULL, 0xFA12BB49B0C5C61EULL, 0x74D83BBF8147797FULL, 0x4E771DFAEE6DA0DEULL, 
            0x55F598AA39C5C5FDULL, 0x092811FBC30518BEULL, 0x1480E819A0824D49ULL, 0x2F21E1E04628EC6EULL, 
            0x0526D7FD3331FF99ULL, 0x8056249F6B17F93EULL, 0x729C778A75AE199BULL, 0xD8F8C5580F293CAEULL, 
            0x05204A5A4DBFFD8EULL, 0x54D1212708A1D9F4ULL, 0xC1912BB38CEEE141ULL, 0xEDE8D4B303118DDBULL, 
            0xA919E350E4C22119ULL, 0x7867529F11FF9112ULL, 0x335B62FD96C6E518ULL, 0x05BE94D63F4D8838ULL, 
            0xF4D88F15F1062FA2ULL, 0x6F7FD6298E08F52AULL, 0x0EDAA8EF3B8684DBULL, 0xBE0070E2C2FF1EA0ULL, 
            0xD911287887990487ULL, 0x39C902741410F775ULL, 0x2A7522D90D231581ULL, 0xE0000F24E4664798ULL, 
            0xDB6A656B386E2441ULL, 0x627DD28B1DF596AFULL, 0xF422200478852D28ULL, 0x9BEFE6CD9E1317B6ULL
        },
        {
            0xB477153E76749457ULL, 0xD6B093DAF3D3D966ULL, 0x8997BEE1D54D5300ULL, 0x9E814570AB94052FULL, 
            0xA5F04A932501FF10ULL, 0x8CF251F19AF6E6BDULL, 0xDE39E4864F78FAA3ULL, 0xB1C290D61434DD60ULL, 
            0x11047264C8742099ULL, 0xFB2F9C7CF2C750CAULL, 0x9F961575896ACA36ULL, 0x4AD4ED4D32044C84ULL, 
            0x0CE728B15C9BAA28ULL, 0xB8A7175F5A66BD29ULL, 0x359ACE2F82024CCAULL, 0x3172610420F4BA53ULL, 
            0x788D2F2B81464FA1ULL, 0x10093F94880330D5ULL, 0x74ED4F4FCC427BF6ULL, 0xCCC825770A536D1FULL, 
            0xF55BD55145FBE624ULL, 0xA9CBA7211D9F19D6ULL, 0xEA1615B95846E3DDULL, 0xC63CEF3F04D0AC77ULL, 
            0xE9C2B43E2D3C9EA4ULL, 0x8BC92D0D409FAB7CULL, 0x35B1BB73E00BAC14ULL, 0x568C9CF2FE1073FCULL, 
            0xEB3F6617BBB0E4C1ULL, 0x92E7A6FF2C7E6B14ULL, 0xB90C420A99FA69C7ULL, 0x1D49185994EA6B60ULL
        }
    },
    {
        {
            0x0DBAD37258603FA7ULL, 0x0A325D3D16C6624DULL, 0x0EEE862617742E04ULL, 0x4310A0A25E9EC9A3ULL, 
            0x093610D018FDAD31ULL, 0xEE70BBBD43E2A3BEULL, 0xCCAE0680A778F7B2ULL, 0x2EC45A68143179EAULL, 
            0x4623CFE15FFFAC0FULL, 0xE15BECAB2217AD83ULL, 0x488449627F5DF839ULL, 0xBC3B43BA068F875BULL, 
            0x84FED6D8FF0CD507ULL, 0x5AF47D9C46636FEFULL, 0x3BC63EECAE1F68DBULL, 0x6EFF2F08657D24E0ULL, 
            0x36995C54E95214F1ULL, 0x5CBB9814B2696FCAULL, 0x528F1325E0126334ULL, 0x75AF7674D8FEBC3BULL, 
            0x3BBD51C7373C6C1EULL, 0x979F532BB893D133ULL, 0xABE5C129B448038EULL, 0xC011945326C4FD87ULL, 
            0xB1FA41A8ADB84D05ULL, 0x65061BA1640C2B27ULL, 0xDCCB6521207DEA24ULL, 0x0C0A6C37958E7537ULL, 
            0xC29EA229DF6BCFCFULL, 0xD3086DEFDDC9B3B7ULL, 0x2A266FBACC61B1B3ULL, 0x9770CA2EA5A30D31ULL
        },
        {
            0x0C8C158A0A112F38ULL, 0xAB13C2D777697F24ULL, 0x1C407CDFE74D3110ULL, 0x648BD12B8EE5A43AULL, 
            0xB87476C0EF402B9EULL, 0xF6BDBE9156E58DCCULL, 0xCF34293585264CABULL, 0xF5E92E67DE191E7BULL, 
            0x4F78A277177AD216ULL, 0xA78CB83FBC58901CULL, 0x22E1F58C9EAE31B0ULL, 0x3ECA635DFB46C45CULL, 
            0x470DE88C7950D7BCULL, 0x5AD0062B4E1D248EULL, 0xEA8C6F9E7886FF14ULL, 0xA2B5FEE3177DD3DEULL, 
            0xD96AC4CA8DA9A6F9ULL, 0x9CD8806F0526B59BULL, 0x149A724D9CD82F14ULL, 0x2A25A5420EE080F8ULL, 
            0xA982F99619ABC69BULL, 0x04FB18CA3FD376D0ULL, 0x7928970C6CE93C57ULL, 0xBB3F3412BAB1E2A7ULL, 
            0xC7E5CA3F22A85EE5ULL, 0xCC0094F8D72F7C89ULL, 0x6845643D799C657BULL, 0x775B81D3835B1E29ULL, 
            0xC03A5ED9587E0403ULL, 0x8FF19330EECDDC46ULL, 0x0798B52BB58194EAULL, 0x67E2C221D9ABD2CCULL
        },
        {
            0x5013B5FF0985CE77ULL, 0x9317DE4D31E733DEULL, 0x39E02E2DEA89C4E8ULL, 0xE442799C9366161EULL, 
            0x871630A01EF71D97ULL, 0x66CDC8ABCFB710B5ULL, 0x921D128F3A661B3BULL, 0xD30DE4240A5B9F57ULL, 
            0xD3312B4EB6DA3B10ULL, 0xEEEDF69EF747CB5CULL, 0x4C45DFDC7D18133AULL, 0xB41480D0505268A3ULL, 
            0x94199A673B5F9B8EULL, 0x45AC239D1624C6CAULL, 0x0930D4DC27F1FA2EULL, 0x35935547DDC2302DULL, 
            0x76303CF0ABF943AAULL, 0xF73781B64D765E28ULL, 0x8BECE7D6DAB54169ULL, 0x13F5604F183C898AULL, 
            0x188509A5436278BBULL, 0xDFAC6F7FA8F82859ULL, 0x41D6AE7A5AF731FBULL, 0xC0BBD616C878AFB2ULL, 
            0x0842B2D0B2924DABULL, 0x34EAE31DAE384BDAULL, 0x99126DA722CD0E24ULL, 0xEFE992AF8BAEA150ULL, 
            0x53DEE9A564BFB29FULL, 0x99E9ADCAD7B85993ULL, 0xE5B7F9F504AA0D46ULL, 0x28F0C8C7850AEB1DULL
        },
        {
            0x4337384390095D89ULL, 0xFD2D1C668188BAFCULL, 0x87769D560150A2E9ULL, 0x3A897A9E224FC140ULL, 
            0x2DB6C4DEED09645AULL, 0x11D6BDD388E97595ULL, 0xEF52B22D8ADB15E3ULL, 0x7A90FB5630560F86ULL, 
            0xB1EEE9F6C257EA5CULL, 0x45076D2DA8F5B83CULL, 0xCD2EED5651EBE56CULL, 0x105B0F156780A39FULL, 
            0xA3A34575E5F16892ULL, 0xBAC2F8C0ADAD257AULL, 0x735B0EBF1629FD2AULL, 0xC09C6D17B62A5F5FULL, 
            0x3E089C2B568E4598ULL, 0x3D8A8C8BA2CD325CULL, 0xC607D3C5E18EE92BULL, 0x7B60C9EBF8110F3AULL, 
            0x2940E795BD264330ULL, 0xA3CF0BA3ECAE9E05ULL, 0xFBEE2DA6D1BACD91ULL, 0x409CC7925FB14E83ULL, 
            0xE43B610F7A262097ULL, 0x5AFB6C75F2EB7F54ULL, 0x5A08AE6D956C5980ULL, 0x61F8424811E58406ULL, 
            0xBFF546057528758BULL, 0xDA1BFD5B6CC19279ULL, 0x7A0CC89983FAAA9CULL, 0xEE7B84FC8D56D661ULL
        },
        {
            0xDD2A0B14016EB6E6ULL, 0x48D1CDC73D1FFA48ULL, 0x74FAC0E67D11F7FCULL, 0x1E2F512788B456BEULL, 
            0xC49C1E1CBB38BC6EULL, 0xD47B004B4D24317DULL, 0x245EB96B57D6EE5DULL, 0x81BCF69C10F420D4ULL, 
            0x7520F7521172B1D6ULL, 0x9869CBC561DFCAD8ULL, 0xAEDC2BF175A4996FULL, 0x4C8E8C93F5F20681ULL, 
            0xB48017A8FA378C09ULL, 0x95DE588886603170ULL, 0x818C3D7AA48780A9ULL, 0xB7A834B69FA278B5ULL, 
            0x5777025B4300B1D5ULL, 0x7A0D0EF3B4B423D4ULL, 0x2F894DD0691A5767ULL, 0xDF888DED86746977ULL, 
            0xAF6A81A3D4FAB81FULL, 0xCF85167CEE28F528ULL, 0x531CD92188F90407ULL, 0xAA28A17053E09003ULL, 
            0x879958BB3FE0C48DULL, 0x75C2B00F58F17275ULL, 0x1ADEAE9EAD58EEC9ULL, 0xA786CFC76ABBB449ULL, 
            0x123BEA1FC39C1664ULL, 0xE21B68A69C6DDD02ULL, 0x52A30CE9A4323D61ULL, 0x98156E72E146407CULL
        },
        {
            0xFBDA2650FB5A88ECULL, 0xDB9F2C74D54C1768ULL, 0x1619FD107FF8B685ULL, 0x21B7FC8F75BBC57CULL, 
            0x6027573F4A70BE50ULL, 0xA47FE18AAA5CB87DULL, 0x908A29FC0CBE8E9FULL, 0x1CEA52B21DAEB8E4ULL, 
            0x578F05B66FCBEF89ULL, 0x27DC3AF5A4FE2DEAULL, 0x9A55B50C3856CB4CULL, 0x1BCB114EEA320FAEULL, 
            0x2A66B61A5FD7D704ULL, 0x46011FA537FEFB15ULL, 0x2D54BB2F8546F399ULL, 0x7BDD3B153FACDF13ULL, 
            0x2B528B0D5D8F91F7ULL, 0x81B21FCDCC0902FDULL, 0x46D2BAACCDF2156FULL, 0x2470192DA723A555ULL, 
            0x16AA16688AE017FEULL, 0x46E04FA87EC8F2C7ULL, 0xA65CF1C43C153010ULL, 0xA5C315256B129DDFULL, 
            0xA4427DB5917C2B1CULL, 0x2542A7FD79DA3B39ULL, 0x57533AEC8BA7EBE0ULL, 0xA3ED5CFD93F0B2E5ULL, 
            0x854E7B9AEE281021ULL, 0xE7198FE4A582A716ULL, 0xBC8B994C41E73823ULL, 0x49149C7BACA55482ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseAConstants = {
    0x33B6C499C3961B74ULL,
    0xE567BD7E73E40332ULL,
    0x76F07D8EEA81B129ULL,
    0x33B6C499C3961B74ULL,
    0xE567BD7E73E40332ULL,
    0x76F07D8EEA81B129ULL,
    0xDE34FBCAB5E1E568ULL,
    0x1583D0FAEF8F348AULL,
    0xC8,
    0xA2,
    0xBD,
    0x35,
    0x24,
    0xCE,
    0x68,
    0x5F
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseBSalts = {
    {
        {
            0x1614251E6079A392ULL, 0xB54CEF723100151EULL, 0x837FD53A3D1AD89DULL, 0x3413A5D7289A9DE1ULL, 
            0xB0C7476E3161F001ULL, 0x6853C69B0C16938EULL, 0x0CC3327B4F3AEB07ULL, 0xD4B10FB19760E7D1ULL, 
            0x0B3FF5E8C0E1357FULL, 0x28B70E09FF1B47DAULL, 0x44DF7D27596A5CBCULL, 0xF2967435E8323582ULL, 
            0x301C784CDAAECC87ULL, 0x9C5AA87128450EF5ULL, 0x61B77D194F02D551ULL, 0xE7A35B8010CA06ECULL, 
            0xC38550625157CF57ULL, 0x35010BF08C8E8248ULL, 0x71FA8A394921FFEBULL, 0xBABF4C485B7BEB5AULL, 
            0x2BD5A7AC2E98C669ULL, 0xA34E8D53E570ED36ULL, 0x8002DD9273BE6C09ULL, 0xACC66B1C8410BBBAULL, 
            0xD17E08B58DF9A910ULL, 0xBA44B9EF863D26DDULL, 0xFFE81EC8E8767FCBULL, 0xEA43475EA492A131ULL, 
            0x3530C9FBF50AF283ULL, 0x81696E9CB6170A43ULL, 0xDD113302BE26F734ULL, 0x9139E6C52FFF0C8DULL
        },
        {
            0xB3B8DA5F19AE77BEULL, 0xC0F2243C114CC4C7ULL, 0x78A571D3DF7E8087ULL, 0x0E85D4A2456CC5F9ULL, 
            0x73C80E939966DD32ULL, 0x5BEC067E8095AA81ULL, 0xF4CD852C7DCC84A1ULL, 0x43B519B253EBD16AULL, 
            0x33012CA620893FD1ULL, 0x17BCFA5569E4E636ULL, 0x2DDE207BE8F7B55FULL, 0xC887994464195EF8ULL, 
            0xBA876814A0691291ULL, 0x9A84D02E94D1A95AULL, 0x5363AA61E567D98EULL, 0x5ADCF60F329E3214ULL, 
            0x593B47EC85F250DFULL, 0xEFDB953375F02790ULL, 0x22F7EF80D1E26F9DULL, 0x122F187A2A1851E1ULL, 
            0xC1A32A3B06949C2AULL, 0x03C58F16B5EC3AA3ULL, 0x5B475EB469E70FB5ULL, 0x42054B7EDECAE599ULL, 
            0xF61A3F9292A65C6FULL, 0xEB7567D96CA55123ULL, 0x831164E8B076D2F2ULL, 0x11C7DC73D4AF83B5ULL, 
            0xCFC54B43B9F17567ULL, 0xC16C532D4C8ACBC1ULL, 0xE97B87EA36AABF71ULL, 0x196D27BF5E1A6418ULL
        },
        {
            0xF7568817D6FFDA50ULL, 0x5A65C634CCE916A3ULL, 0xA5F88BED61FC5256ULL, 0x62627A0E85BAC21BULL, 
            0x7B9F10AD3AE83A8DULL, 0x80FE81286E21575CULL, 0x828CE35C1C861D76ULL, 0x901BEC77EC4EF97DULL, 
            0x0A3137574CFFA8DFULL, 0xF40212CE5D20F487ULL, 0xAF8F1BBFC50B6A1AULL, 0xEAAAD4117DFDFB3BULL, 
            0x794B1150197D0EC4ULL, 0xEB260E435BCA4B4DULL, 0x3889539D9222EE3AULL, 0x4F1A475BCD608444ULL, 
            0x581E28D77FE62F13ULL, 0x2597338DB49F4480ULL, 0x4DBEA2EC8D429C03ULL, 0xF9B85F05D639310FULL, 
            0x44288A37FEB8ED73ULL, 0x2BC0A006B3F09E1FULL, 0xD29CB56593F005D0ULL, 0x24E8CAD727AEFBB7ULL, 
            0x137D915F2B686996ULL, 0x07D8DEDB401468D9ULL, 0xCF94C62305A2F049ULL, 0xA7FBCE343568D3E5ULL, 
            0xBFFC1ECFE1F80DE4ULL, 0xF9FCF34B1DF7DFC1ULL, 0x2403326C7A4A946BULL, 0xF7FF48CB0B4B9CF2ULL
        },
        {
            0xC092E543E2E87879ULL, 0x2BBA0E57CD34D4F0ULL, 0xB34AE2C729667C78ULL, 0x8034DEBC287E73A2ULL, 
            0x940CB75D420FAFBEULL, 0x4EC69E4C3E90DA66ULL, 0xAB76A2DF38FACA3AULL, 0x3D5566744BD4806BULL, 
            0x0DD9A95BAF6665D2ULL, 0xE9FA3CAD7AAEE3C5ULL, 0xA88143FDF3D47369ULL, 0x6F74256FD49DB2AEULL, 
            0x7E204F7763ED1C35ULL, 0x8CC82AF3400C3B5FULL, 0x6732A52F7AAB93E5ULL, 0x86CCCB371111E6DBULL, 
            0xBF62BDEF2A0FD890ULL, 0x321E7795FD955A9FULL, 0xBCC1BA398929B64CULL, 0x549B3AB9884A4801ULL, 
            0xD7F71C5EC1BA0B84ULL, 0xB47D7F36D1132977ULL, 0x0C0B3F5B3E296D76ULL, 0x9E118C109531F632ULL, 
            0x7877D6F036D908A8ULL, 0x43012F820F8C660BULL, 0xA68D67C8EEBB1C55ULL, 0xC541B9B14DC0EC86ULL, 
            0x326E65F9FA2418B4ULL, 0x6BE0CFF0A6978BFFULL, 0x10C392DC54B418F5ULL, 0x5DD7310B759D33F5ULL
        },
        {
            0x8D48309DA1370062ULL, 0xEE773BC4BAE41780ULL, 0x764831CAFAB8CCB6ULL, 0x31CE085059013613ULL, 
            0x21EA5D7F298D8173ULL, 0xB0984F99405AA6E1ULL, 0x2A7E6E9CCD5499BEULL, 0x376C2E4FECA65535ULL, 
            0xF04216CBC5ECEED9ULL, 0x188882E59FDC8EE0ULL, 0x8819CD1FEB970E82ULL, 0xF587D3D87CD65F9AULL, 
            0xCFE0A10B5C30F717ULL, 0x2E7C84461FB410ADULL, 0xAC7330DB3B407640ULL, 0x155ED815A8A1B6A0ULL, 
            0x0A60F8F32A5A730CULL, 0x81CFD163D79E0715ULL, 0x447DDC8A0A984DC8ULL, 0x613D92874D4D1A3BULL, 
            0xCC3B40165D5A5622ULL, 0x51ADE63AA1AD3155ULL, 0x0FE1854B3BD4113AULL, 0xEEDFC78A65BA310FULL, 
            0x22F2E81ECC2DEAA1ULL, 0x4B2E2BBA66D9342FULL, 0xEB289B76DBA66210ULL, 0x361A16BF63372856ULL, 
            0x5917930FDD109703ULL, 0x57A461AC33CF63B7ULL, 0x09E8F798A89FEB94ULL, 0x9F3F603661C5327AULL
        },
        {
            0x6D588684A3C7942FULL, 0x91BFCEC84156E25DULL, 0x135637550FC254A7ULL, 0x5E9622B6ECC87DD0ULL, 
            0x62D0A6EA1151F64BULL, 0x5A78185D3CF77F84ULL, 0x34B58E74B0B2DFB5ULL, 0xB27B7C3F5249A002ULL, 
            0xF36C1399BC00B06DULL, 0xF6612E846B5BA9B5ULL, 0x9F665BC9D434EB5BULL, 0x3FDB05483FA4F249ULL, 
            0xC7AFB2017C528A95ULL, 0xC1ECE2AF13D8842FULL, 0xB2D0D3EA9F2A3121ULL, 0x3A1EC5535042E8C7ULL, 
            0xB8C2F7908A9A3B85ULL, 0x35BE2BAC95F00A34ULL, 0x55D721EA2B69348FULL, 0x8AF6A72B76DBB01DULL, 
            0x6B6F681D6CBBB060ULL, 0x9E8E58A000ACABDAULL, 0x73C277AA9053DBCDULL, 0x3208F1B70DEF70EBULL, 
            0x318D5670E741CFE9ULL, 0x6483A9AC84E32968ULL, 0xC7B149458D8F2F87ULL, 0xD2CFB57856B99731ULL, 
            0xB24E970DA6F91D47ULL, 0x66BC312FD5E78E30ULL, 0x62682131F8711754ULL, 0x93503DCA6FB5AB52ULL
        }
    },
    {
        {
            0x2CBC0E48AD5D4651ULL, 0xA67948A7EF4D1B8AULL, 0x82F34D37887B9BD6ULL, 0xD975820CABEFDC47ULL, 
            0xFAF4F82310A2BC24ULL, 0xA252281C6DC2F624ULL, 0x5953AB5B34EBC711ULL, 0xB842767FB44C7B7AULL, 
            0x3600628EF947F944ULL, 0xD8D1C728FD572304ULL, 0xBD69B8D3400E095AULL, 0x33083D92AC8BB148ULL, 
            0x3CA8EC5A4E7090D9ULL, 0xE56EFF062F045146ULL, 0xEF5ABF99C9695647ULL, 0x8D0979F7A49D4AEAULL, 
            0xA28C8ECC8E69EDC7ULL, 0xD19FDCBE4DEF54A2ULL, 0xE8F4CBC0A135B5B6ULL, 0x45702C513732E8BBULL, 
            0xDA87D8AC695A358FULL, 0x93BE7861A1F752D1ULL, 0xF5ACDE674F743AAAULL, 0x9A4ADC40F6A7D0E8ULL, 
            0xFA37CD55BC86BA7BULL, 0x29FDFCA7635E518DULL, 0x8A2B17FAAA6FDDBFULL, 0x72F7D5C86E5B447FULL, 
            0x5A323A261CDA637CULL, 0x2C092AD22142C370ULL, 0x13DCE25DAA1A36C2ULL, 0xCF1404EF78035DA5ULL
        },
        {
            0xC95963D05E6B3BDAULL, 0x40D4DAFF2EF52F1FULL, 0xE23E6F9921AE031BULL, 0x00BC8B8220577392ULL, 
            0xE7D0E745D7D85E5AULL, 0xF21791AC160D29A5ULL, 0x9BD15B83089A2375ULL, 0xC83036E257923C06ULL, 
            0xA820422F05444F6FULL, 0x580F4EC6BE1686AFULL, 0x60AB7813EB5D0104ULL, 0xE46B554904A82293ULL, 
            0x614645D77E456D68ULL, 0xA1CE307C3833B062ULL, 0x25A1FC0C1A883FEFULL, 0x07BCC3571BF66387ULL, 
            0x65B6657BEA2B318AULL, 0x1D00C363D2C1CA18ULL, 0x36620D1492F93583ULL, 0x37473204A1080D0DULL, 
            0x02A3246033CDCA29ULL, 0xD54EF43D333A4E01ULL, 0xC3DAEEEA27CB5F5CULL, 0x0A9FC5A7C51DB028ULL, 
            0xBCE482FBBFD3FC40ULL, 0xF5594B85235087EBULL, 0x655E56C09C726758ULL, 0x2B3FCCFD0C8E744CULL, 
            0xCA766417F539DE6CULL, 0xD3B4A98844E40FCFULL, 0x92AACB095DA2B4FBULL, 0x08F5C2786EE5834FULL
        },
        {
            0xCB6846BBAA790389ULL, 0x26ED53C03DE13AA9ULL, 0x338635681512A611ULL, 0xCCF75080A966D814ULL, 
            0x39502DC8D9F19143ULL, 0xD930A326644405E6ULL, 0x1AE5B0B6C30D0E2EULL, 0xCA5561FB0C89FCE6ULL, 
            0x45E0104C1A1A4094ULL, 0x487F0C8FD56F13DAULL, 0xE91686DD63D4065FULL, 0x85D9D1BBD8ABC364ULL, 
            0xA402AE0F823E74E7ULL, 0x930B741622F789EAULL, 0x8BA8C5688CA053C7ULL, 0x61C7C7810A0D0FCEULL, 
            0x980EF4D77EF26139ULL, 0x3903EC0345658F7BULL, 0xE7707B67DF034320ULL, 0xAF2370A0435E94BFULL, 
            0xA16BA1CEFC116C9FULL, 0x30FF14903D798D28ULL, 0x4EF746F8C1E007EEULL, 0xDB4590BEBD429F34ULL, 
            0x5DCF15CB8533E39CULL, 0xDE17227898E962BBULL, 0xB59DE62AD2F5EDFBULL, 0x5D1A10E08FC64051ULL, 
            0xA8825B4295B5F814ULL, 0x954EE99F939E17AFULL, 0xB5027CB8B9687806ULL, 0xEE86235F5CAF6BCFULL
        },
        {
            0xF777DBFC2BEBC7E0ULL, 0x3085BF8EC5CD73CAULL, 0x79269C2A87DC5A51ULL, 0x1267B49FEAB47A72ULL, 
            0x824A567664CA578DULL, 0x9D47C16AE109DC73ULL, 0xF85E47B271D6C39BULL, 0x273450550DB30014ULL, 
            0x25A17FB417E6B82AULL, 0x4ADA270FC63EBC78ULL, 0xF24848BA81CD36FCULL, 0x52432B1746C5BA79ULL, 
            0x3A90563DFC12DDB2ULL, 0x7A3E66986550BBB6ULL, 0x78584F3D9D4C0081ULL, 0xE91070557F5EEEACULL, 
            0x8CCC46D0C610B144ULL, 0x6A4996915C93F383ULL, 0x33B64EEBCB34B253ULL, 0x4BD0E5B8F1D7479AULL, 
            0x9A2884C2817E334FULL, 0x42F4A6F9C5E75B45ULL, 0x973B5782849B689CULL, 0xC745D2DE9DEFEB55ULL, 
            0xC3E5290DC9FC18D0ULL, 0x694036E83BCC4E2CULL, 0x53A5D31BE56373F3ULL, 0x22A0B824620E2C22ULL, 
            0xAB55098D38F6B5D1ULL, 0x2304233C92234315ULL, 0x399E785E7F3F8C33ULL, 0x0BEA814B59EAC046ULL
        },
        {
            0xB60C5CE3E88CEF1DULL, 0x79EBE4CDFF83B597ULL, 0xAA2D7FCEA1182F7DULL, 0xB5EBEE113EE0886EULL, 
            0x9E4D879F2F830E5FULL, 0xE8F782B1BCA7A72CULL, 0x2DE583B21F4C9BA3ULL, 0x314EF93A75A84542ULL, 
            0x7592CE5C53A1C714ULL, 0x23D9F98D9AEA6A44ULL, 0x2A5D43C441A151DBULL, 0xDAB5A9F2D4B55B66ULL, 
            0x3814AF063A924E95ULL, 0x806E4D82D5B0EDC8ULL, 0x5816924FCC0CADD5ULL, 0xCC8FE069B8464A8EULL, 
            0xB3C87D15E089D61AULL, 0xD36AB0F3104C6BDAULL, 0x2E8E43F8FF1ADAE5ULL, 0x22F6F60CEDFF1A5AULL, 
            0x8100046625B96795ULL, 0x8CD2794ACF75B5F6ULL, 0x11B9C88E03E493C4ULL, 0x2CDAD38C5D421FD2ULL, 
            0xD5749FDCE6B1445AULL, 0x59E2B3F5852D0A1AULL, 0xB9F8F55F86DDA47FULL, 0xE5BB21C65B9A493AULL, 
            0x0B636A91EA335107ULL, 0x7B36D3B3B00992A3ULL, 0x36C9A017E676C128ULL, 0x1B6AD9FAA763779CULL
        },
        {
            0x2B9249CB50A40EF9ULL, 0xB7D99BB3490BA500ULL, 0xB897E211A244C822ULL, 0x10091135C50CDF32ULL, 
            0x67CFA56683DBE6ADULL, 0x3BFFD76BC3C37DDCULL, 0xF323B7D6F89DE1C9ULL, 0xF704C63484948CA6ULL, 
            0xCBCE4A2AEBEC4BC6ULL, 0xCCA46745AD5417C0ULL, 0xD26E532412230339ULL, 0x923A0B24EA9E7432ULL, 
            0x29115ECFEC254F7CULL, 0x7BC43AEC7F2A7CFEULL, 0x303BCCB4B1C05352ULL, 0xC8D162A68137338DULL, 
            0xCFA5C3AE9212F279ULL, 0xE52908E739E8C023ULL, 0xE55A6FE8F1190FCDULL, 0xC564DED486147F4CULL, 
            0x666EB7F844B2CA42ULL, 0xF0948AEB0B24F52BULL, 0x4640077BEE9CA314ULL, 0xC00FBDC098125589ULL, 
            0xFA3C87A85EA831ADULL, 0x4745012D2DA53B1BULL, 0x92F2FDE70A1743C8ULL, 0x9BAC80A0AA5E1531ULL, 
            0x1DA7210BBD73B36FULL, 0x0E238035D3DBBB1BULL, 0x812863C8B242D68EULL, 0xB9F87916DCDB7706ULL
        }
    },
    {
        {
            0x17EA16A60DADD948ULL, 0x2B65E26DC7D963AFULL, 0xDAD689FD65DA5058ULL, 0xFAD175C9EA914606ULL, 
            0x96DF9E912D787E33ULL, 0x678BA7EB30DA339BULL, 0xAB81EA99CD85DC37ULL, 0x5EBA070BE7F77B76ULL, 
            0x33B66F5C4FE08904ULL, 0x2EB59C12671AE69DULL, 0x80288B44EFCF883AULL, 0x60E73C41E19B6A00ULL, 
            0x411CD63F1BF7A3C0ULL, 0x96D3F9373F75F06AULL, 0xED54223D11EA0967ULL, 0x4E56EE596655322BULL, 
            0x6FCD8E10E982B1E1ULL, 0xD15FE357CE7A95EFULL, 0x64068C635FB139FFULL, 0x647E42BD2E9F66E3ULL, 
            0x1D8C7F161E7C0905ULL, 0x23BC2370584C0CF9ULL, 0x7410F1CA9E42A8FFULL, 0x2F5646EC593B5728ULL, 
            0x33468E1B8489B16EULL, 0x035FA13D548CDFE5ULL, 0xE55AA03FB6A21D28ULL, 0x4A88909BDF3B373CULL, 
            0xB97A9D19360D706AULL, 0xBC4E713F45852C7CULL, 0x0AB43375B244ACBBULL, 0xA784656827B1CEF1ULL
        },
        {
            0x5AE4F50B132C5B6BULL, 0x651FEA27A1390BA2ULL, 0x08843AD1FD4A7E1AULL, 0x4D36F7951608014EULL, 
            0xDB2453D042D1B762ULL, 0xC1DAC75476B8AD12ULL, 0x406A1FCC45F3C9EAULL, 0x54CD69DA57DDB57BULL, 
            0x742CE6FC7D30A3EDULL, 0x833EEDB757666CB0ULL, 0x1867E85AB0ECA1B4ULL, 0xB761B7C17E718580ULL, 
            0x8BBAEFD89D70931CULL, 0x051BCCD5683C5EC4ULL, 0x4B025B57928345DBULL, 0xDAEB4D54CF239ED5ULL, 
            0x71D27B6D7852CCF7ULL, 0xAC75179CE4CCA8B5ULL, 0xFB97CB5A8D5C46FFULL, 0xC236459FE664E870ULL, 
            0x44D92D20DA6FC031ULL, 0x5251D98357A12D18ULL, 0x39F96DB25638DCF6ULL, 0x29AB72898075DCF7ULL, 
            0x6020A82E335EA6E3ULL, 0x57357C5AE702178BULL, 0x2DF45CC842F580B0ULL, 0x708B49D92D514523ULL, 
            0x97D973DF2EFD261EULL, 0x3EFDF7C1130AED42ULL, 0x4AAFF525A614908EULL, 0x0A8F41CAC4B3077BULL
        },
        {
            0x8DC55DB839BEE4BEULL, 0x74C53AB28A521AEAULL, 0x10EEA741F0753CDBULL, 0x45324AA415EC2509ULL, 
            0x02381BBADB9088F6ULL, 0x576A04FDA179D93CULL, 0xCC72A4ADE5CF89F7ULL, 0xEBA10DD0FE9FB83DULL, 
            0x8C393DE1C2B2B947ULL, 0xC10016D553D1A00BULL, 0x53A678E8833660E7ULL, 0x6F82CEC471F766C7ULL, 
            0x04F81157D0909A80ULL, 0xBCA3CB69A84CCEFCULL, 0x4B4346CF42B956E1ULL, 0x3E22EB9357FA3A75ULL, 
            0x6E09D047261267CCULL, 0x1F5D3A65DAF0CEB9ULL, 0x528AB8BD1EDCF510ULL, 0x73392B20DE2EB7C1ULL, 
            0xEA890FD30887F35FULL, 0x0221033AE8E067C6ULL, 0x9AD84D7E1CB1BC04ULL, 0xFEA5F94D7917E2DAULL, 
            0x8DC84C2246782357ULL, 0x53BE3760739AF636ULL, 0xB149D5D398AE774FULL, 0x84CBDAAB3241713EULL, 
            0x013708A2A30E41D4ULL, 0x090A3EE6E0EEBABDULL, 0xE5D5FD8AA23D31FFULL, 0x6EECF0F580BE6724ULL
        },
        {
            0xA985C64317B73BB0ULL, 0x962BCC10B50F202BULL, 0x9CB171C2DEC7A46FULL, 0x740773BFB4B03237ULL, 
            0x2BD5BD1431848562ULL, 0x82040D36FCCD763FULL, 0xE286ABCB37CE6E65ULL, 0xC82AFA2498986BE5ULL, 
            0x7609DECC9C9B45DFULL, 0xB46732BD37D87D3DULL, 0x8CE026239E852A36ULL, 0x3513E8BF64A4897DULL, 
            0xE0E6B06174D570EEULL, 0x4D27AD95F4F05626ULL, 0x66462E18CF57CA5AULL, 0x0A3AD036140A3466ULL, 
            0xBBA38B0D7E342ED6ULL, 0x0C7BC6A79D3C18F2ULL, 0x5134161AB08BF64BULL, 0x48BC17CB574A32D2ULL, 
            0x9FEB3015FD3EF0D5ULL, 0x6D1DAABE12683252ULL, 0x7B64CCE71BB6F3C2ULL, 0x5963DC9F1AF03485ULL, 
            0x2C64AC0357737A3CULL, 0x89288D31E800EA56ULL, 0x3CAE8E4CF602D440ULL, 0x9CDA05A3614B4BE3ULL, 
            0x651A1352F1F0EF6BULL, 0x5DCD77265BD03DCBULL, 0x69CB4B5CD021CBACULL, 0x815D3671435A8D1AULL
        },
        {
            0x35BABADA3E252017ULL, 0xA527CC394617C870ULL, 0xBC282BE67BF58BCDULL, 0x0FE3D408E4726CF1ULL, 
            0x0786E5F8FBFB32ACULL, 0x41E9A23C8ABC37F3ULL, 0xECC405001299C629ULL, 0xD6CE75A21D6B320FULL, 
            0xB29B7686EB43C1B3ULL, 0x5C348E54DF256ED3ULL, 0xE1EE99B30AAF5F76ULL, 0x28C814AFF4D1FB29ULL, 
            0xBB812E4A8F1B5509ULL, 0x7B93600CD9206275ULL, 0xFD088CC79F515D17ULL, 0xC93773D1F031B4EEULL, 
            0xDF33F4651D5B5007ULL, 0xBDAC6EB8760D6071ULL, 0x6FDC16EB23E1D294ULL, 0xF1118AD93200E13CULL, 
            0xD7FA7F9F23568395ULL, 0xA27402AA376EF5B1ULL, 0x8E765AA8663027BBULL, 0x62363001C035B6F5ULL, 
            0xACAB2B6E7F736976ULL, 0x8D5564C85E00F7C1ULL, 0xF986D2428B4CCBB6ULL, 0x39D461A0FADE9651ULL, 
            0xFA9C1BB7107D19B9ULL, 0x8100FD5A1E0D228DULL, 0x64714C7FA95A1067ULL, 0x41405E1BC6D31984ULL
        },
        {
            0xD28BE88925BBC7CFULL, 0x8C2334EF00BAEF47ULL, 0x3926877EBCA44B55ULL, 0xECFBBF75BB881E59ULL, 
            0x72D020E9321F315AULL, 0x360D23486E5936F7ULL, 0x14EB82A9C04D6F29ULL, 0x800C6EE7A154370CULL, 
            0xBC63A62C7955231BULL, 0x80D7750C25CBD683ULL, 0xBA3EB988352A81D1ULL, 0x9376CE71996DF9A0ULL, 
            0x777D183ACF8F6FFAULL, 0x08AFB0E5A3EA4EA3ULL, 0xE6EA15C722E44E88ULL, 0xE4B90119C4BD9FDCULL, 
            0xD7EB12CD5BEBE88FULL, 0xF4663F9285D34E98ULL, 0x642B113A7EBEF32CULL, 0xD5974163A06B9C41ULL, 
            0xD8288CC6132257E7ULL, 0x406DF3C32C43E885ULL, 0xCE08A3F65042090AULL, 0x3075DA448AC1CA7AULL, 
            0xFE67C027F650C49BULL, 0x0A5AC0193DF834F8ULL, 0x162DD4A7D3722423ULL, 0x2A79F4F1330C67EAULL, 
            0xED2A4287D7217273ULL, 0xD43E2044A0A21EF5ULL, 0xA29B185D0E18BFCBULL, 0x1DE67EB3903CED35ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseBConstants = {
    0x5B67312CDAC54FDBULL,
    0xEED5DECC2D44DF10ULL,
    0x2A701F3F4FAEA840ULL,
    0x5B67312CDAC54FDBULL,
    0xEED5DECC2D44DF10ULL,
    0x2A701F3F4FAEA840ULL,
    0x01F2EE008E167E54ULL,
    0x99C4C8772F6EF89FULL,
    0xF6,
    0xAB,
    0x44,
    0xCD,
    0xE0,
    0xEE,
    0x2E,
    0x0E
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseCSalts = {
    {
        {
            0xDD9F50B7D4775C19ULL, 0xE4620BCA0BE5368DULL, 0x66063906BCBCC1DBULL, 0x5B4751F657A95E46ULL, 
            0xF582163DF609AB57ULL, 0x2B2A1E06ADF018F5ULL, 0x5E3537C16BF0BBA1ULL, 0xC7017EEF88E3994BULL, 
            0x7DB0AABE7A123350ULL, 0xF4956943BCA4D63AULL, 0xA886BAFAAAA89C3DULL, 0x9B09D6D1C9F777A5ULL, 
            0xA8FE7D208A31B9B1ULL, 0x7420344AB8E77C56ULL, 0xC991C195587C0A73ULL, 0x8ECAE5F94D6EADF1ULL, 
            0x299280657F871281ULL, 0xDAA396F8CF6061E4ULL, 0x65FD844D39DFC078ULL, 0x97FBD7F5D3789E21ULL, 
            0xC0F0404AB0263EE1ULL, 0x2DE9221168D20FD9ULL, 0x5063EC1B63E988C4ULL, 0xF72D9F20997F3833ULL, 
            0xA61E01126897AB58ULL, 0xBFAD7914A47E91D0ULL, 0xC638577498BF2235ULL, 0x9BE00CE28E395ABDULL, 
            0x955CEEFA1F65DBFAULL, 0x15A57B1E2DA809E7ULL, 0xA742D5DD83C1CD22ULL, 0x60CC1EA23EC8BEEFULL
        },
        {
            0xC70B65ECF3A1CF71ULL, 0xC14E8BDE78DACF8FULL, 0x5E26A06031163A5BULL, 0xDDADB35DF1CFA768ULL, 
            0xD1B4115B435CA4E7ULL, 0x10F17E6525DCDB2FULL, 0xF5674591A460DACBULL, 0xDF5CE723A2A77920ULL, 
            0x47562427FF664A6AULL, 0x1C6050E2AC062FF8ULL, 0x28A87E4C08E42EC2ULL, 0x955E1CC02E7DC74CULL, 
            0xCE3E62D9A53B6612ULL, 0x0BB67881B36AD9CEULL, 0x109A3AC9EF89CA63ULL, 0xCE918A68A7003888ULL, 
            0x62520E99179BA041ULL, 0x6288240D3016287DULL, 0xEACA2B9F6CAF23DBULL, 0x8E816C8674E48DF5ULL, 
            0x366F466298BA6D7FULL, 0xD36FD11004EEDF83ULL, 0xE96D41EB8FBC31D5ULL, 0x5ADA4C9E581E358EULL, 
            0xE3751013F5041AA3ULL, 0x78D84F88A056BB64ULL, 0x24330A4C9ECC2DB6ULL, 0xE97B1B9C8E7E3B2BULL, 
            0xA6C3A3EBE1A5862CULL, 0x0A2C86FD45D464A8ULL, 0x0F0A6B622350DB1AULL, 0x8245F2184F605B7DULL
        },
        {
            0x44B6CEE146F303B2ULL, 0xB8F43A16E1ED8A55ULL, 0xE25F093A4C665D1EULL, 0xCC8250F1843277E8ULL, 
            0xBB6544B9819BD4F4ULL, 0x2E3A3EB9E5F3DB63ULL, 0x8A7E5B6835A94E51ULL, 0x19312F9CB21A6BF1ULL, 
            0x5846505191DE480EULL, 0x558BFE95D6F1DC03ULL, 0xB2CF61DB46E67352ULL, 0xB8FF7FEAC14FFB7FULL, 
            0x0886F35C14310C05ULL, 0x096BB31CFF2C6FDEULL, 0x8518D272DEB67838ULL, 0x53C3A3D8363717C0ULL, 
            0x846072381A9E56F3ULL, 0xB28BCEED666A4F02ULL, 0x14455C1BD5561EBBULL, 0x164C333B29F3851BULL, 
            0x06490AD9E4DA0FB5ULL, 0x5AB43C9981C65926ULL, 0xC9AAC30CB3A75848ULL, 0xDFC7DEC0F76C875DULL, 
            0xA5D2311156AA30CCULL, 0x6969622A8792256CULL, 0x277C654C5F17D072ULL, 0x1EA6A41CD0381D44ULL, 
            0x93CC163C5283721FULL, 0x914A390581641CB6ULL, 0x65EC7724BB3A58C1ULL, 0x1E83912BD84DC098ULL
        },
        {
            0xB098A35061F3ABE6ULL, 0x15BA4B1157EEBBC7ULL, 0xF0B613ECE449EF1CULL, 0x3CD4466DBBE7C457ULL, 
            0x6DAF0ABD29542599ULL, 0x5FB92C381738C3FFULL, 0x4C3FFF65774CB5F9ULL, 0x5F314B7A60D29CB3ULL, 
            0x808E3F955AC4A419ULL, 0xB4B965DA8121D09EULL, 0x31FB9401EB54252CULL, 0x3825BAB41B6161DAULL, 
            0x13C6B87CF99A55BFULL, 0x1BC137B2C443873BULL, 0x3EA1DDF5D3FA1E0CULL, 0x99CDBA64E912E304ULL, 
            0xB4CD39C2625A8B28ULL, 0x759D9359FFADBAC9ULL, 0x3C4BD233516DB624ULL, 0x6746A021489C40E5ULL, 
            0xF8BB0BAA6337FB14ULL, 0x2A5BC70594DE3564ULL, 0x3185CB92084395CAULL, 0x07341F3CE270AEA9ULL, 
            0x39857BBF455AE8BAULL, 0x02EB8BF0943B7020ULL, 0x1A41A00C7762A830ULL, 0x3FCA4EBAEEAD3CD2ULL, 
            0x30DF9AE5B724C207ULL, 0x311887DD84455483ULL, 0x367CF6219C56130EULL, 0x83831AFFDFAE0AA9ULL
        },
        {
            0xD2EBF14A19C97AEEULL, 0x9EB5FC79F1DD6775ULL, 0xF6E291BCDD68795DULL, 0x7E9FFA687DA3FFECULL, 
            0xBDEACDDE301B7524ULL, 0x68984177722C0A4BULL, 0xE625957777AE8E90ULL, 0xCAE10A7A9F494096ULL, 
            0xE726EDBDF1984459ULL, 0xDCD2C8AEDBAF6131ULL, 0x7FE4BC13B523B2EFULL, 0x5528528EEE07F841ULL, 
            0xB4458C16941B5D9DULL, 0x6FAA691D5B3B6690ULL, 0x6E4FC058A5E32DB4ULL, 0x5B473328A63D3413ULL, 
            0xD46888C28682F912ULL, 0x6F306C43CB28CC9FULL, 0x71EC8E6DC2871D2AULL, 0x4760B76A355D5798ULL, 
            0x2A8DAD17FDBB7F27ULL, 0xFEBD85D67313EBDDULL, 0xE720420AC89A38C2ULL, 0x22251FDEC2BBE1BFULL, 
            0xB4D52D318CA46E3FULL, 0xE8FF0EE4F5AEBD28ULL, 0x79C8E41063451820ULL, 0x850C5A96685C233AULL, 
            0x4E5D9E33064A61A8ULL, 0x6EEB6C249DC5DD87ULL, 0x08454953D92278AAULL, 0x99AD8F27649A3461ULL
        },
        {
            0x66D4AD762C100AF7ULL, 0x14C328993FA1C323ULL, 0x5D2B079A453EA87FULL, 0x4C3F87B60ACE6849ULL, 
            0xD4F6568C5635D22EULL, 0xED0E749ACA772309ULL, 0xDA4E22E1B64908DEULL, 0x20EA642DDABDD2EFULL, 
            0x121EAF2AF3BA3E59ULL, 0x8C0DE64E44DDB7A9ULL, 0x1ABF5A9757D90647ULL, 0xF4DC19E75CCD0F66ULL, 
            0x7DB344C002FAF5C1ULL, 0x70120A1988B6E88BULL, 0xEDA6AA53B4D11DF3ULL, 0x20EF819FF0907043ULL, 
            0xACA399978DDC39E8ULL, 0x229C7C1489BDFA1AULL, 0x6CDCD67D04F50285ULL, 0x72669DDA4C2AA542ULL, 
            0x8BCBF6EF8AA4EA48ULL, 0x5FC61AA656C0F516ULL, 0x6C2357003A763D05ULL, 0xE62C2AA2B6885407ULL, 
            0x7727FFFB94063261ULL, 0x31F910712DFA9C46ULL, 0xD61852201D4B07B3ULL, 0x7A31AAEF1DA82FE1ULL, 
            0xCEF1DB0F093AE33BULL, 0xCD78DDF84A7DFB01ULL, 0xCFB8ECCF2DDFFF82ULL, 0x42084E3B85C25802ULL
        }
    },
    {
        {
            0x8481E6AE55CEBB1CULL, 0x085145BEFC1F9F8EULL, 0x9F087FE8BC9AF3E3ULL, 0x27EDEFCBBEE70483ULL, 
            0xCE4E76559270FAA5ULL, 0x23500B31C4D5FDFBULL, 0xDA5E40F6C264CBB0ULL, 0x27D4E6CF7774B7D1ULL, 
            0x806CBAAB6D4849EDULL, 0xE6DF3DB4B63A7E6EULL, 0x758206A39D98CE66ULL, 0x5824297EF77DCEDDULL, 
            0x443351E48FDA6490ULL, 0x59372D8385F94861ULL, 0x96F5437AFDFB7D67ULL, 0x7FB57AE0FE1E5321ULL, 
            0x1A2F6EB21A1251B7ULL, 0x364AB755CBE420A6ULL, 0xB517AFCEFA30490CULL, 0x0914EF47308771BBULL, 
            0xB7F0EC36BEE1BB0CULL, 0xEC9B91083FD4E806ULL, 0x24414EEACF92EE86ULL, 0x5CEDB2A36C46BBCDULL, 
            0xDA65E84CE6672F63ULL, 0x1A98C8A2E9F4F19BULL, 0x3A2D93DD834F10C4ULL, 0x75049263CB25A5BEULL, 
            0xC1F69642CF1081DEULL, 0xFB2DC23949205CBFULL, 0x9EA64132281D6728ULL, 0xDBACA4EA7FA2543BULL
        },
        {
            0x4B5035D2E663C22AULL, 0x69BD975C4A63D9FBULL, 0x2B4A4B97F2DD5A55ULL, 0x5CF6EF5D732EA4DFULL, 
            0xBE4467EDE2D3C4A4ULL, 0xA75A31E262445D13ULL, 0x176D0BA0FFD45712ULL, 0x91CF7A32AB7CB7F7ULL, 
            0x8F42D69079009D7AULL, 0x83A4A0D2F36A6262ULL, 0xA99C6C7655119EBFULL, 0x3FB0C808D768B749ULL, 
            0xDAB7702E177DFBFBULL, 0x1C1041F89DC00616ULL, 0x17B5CD19DF103959ULL, 0x22C68C5A58B31BB1ULL, 
            0x5F74D82F2FD286AEULL, 0x79B4BBE144414E31ULL, 0xE31E10A8B8619914ULL, 0x0607A70848658F37ULL, 
            0x839F24D403293FDAULL, 0xF7C5E6C5019D34B4ULL, 0xAB79CD780C403211ULL, 0x6DBFEE2ED2ACF526ULL, 
            0x08CF52E709C381F8ULL, 0x8623DA147633F98CULL, 0xD724B98CF864D796ULL, 0x174AF16701A0DA3FULL, 
            0x6CF2141825339EB0ULL, 0xDB56DB0EF3C8B208ULL, 0xF9C60CB468490045ULL, 0xADDCADC2C590C6A4ULL
        },
        {
            0xC106A18D4D5BC70DULL, 0xE659B2ED0AD3C339ULL, 0xBD10FE57438E1AEFULL, 0x9DB27C8744C43AD7ULL, 
            0xCE597EEA2C782E10ULL, 0x26944289A188B345ULL, 0x30E24C008FABFF07ULL, 0xE6609700867F55E9ULL, 
            0x15DD89A1322EE0D5ULL, 0x8DE90DAC90D1CC4BULL, 0x28D38C31C7E9EA1DULL, 0xC4A2F79D44B0E6CCULL, 
            0xB9CCFCEEDFAB3E2FULL, 0xD0218E6DD31D2336ULL, 0xC925F5B63D5645CDULL, 0xE1AB088C6240FEDEULL, 
            0x75D14412CB4D66DBULL, 0x92AD34F5527985C2ULL, 0x450E6F8FD0379888ULL, 0xA4620FD4C481780BULL, 
            0x5394591A3A42C52DULL, 0x9D826E71CCE9E060ULL, 0xF3CD291782B06D86ULL, 0x17B694FF12849993ULL, 
            0x796E592198762CA7ULL, 0xA15962C268566A4DULL, 0x6A900EF292AABFAFULL, 0xCB6107B9D01665F1ULL, 
            0xFB55ECCA98645647ULL, 0x2C8201A056AB9FD6ULL, 0x9746B194A9CAC57FULL, 0x880F58EB0AE8A25DULL
        },
        {
            0x66974AE669139A4BULL, 0x80D9F6963A9A4B75ULL, 0x5F1E81299B78F3BDULL, 0x980786C00804FDAEULL, 
            0x09B0C34D0DB462FCULL, 0xC0529F96AC9EB47DULL, 0x7D757C258C65DDFDULL, 0x9B3EFED9D15284E4ULL, 
            0xB5043B84217544EFULL, 0xE4E5F596A2358DA6ULL, 0x3FF9D27F57AA2BB6ULL, 0x597DB0ADACAE86DEULL, 
            0x4B956C684987EEDFULL, 0x4038B5C5144A6F95ULL, 0x3D195BDAC9B56A62ULL, 0xCCD658CC3EF60D05ULL, 
            0x5DA78AE532B1C9FEULL, 0x3A3DCA142FD6B9E2ULL, 0x2F523BA5CB40C631ULL, 0x59F6EFD5A89A9973ULL, 
            0xC436D852D7DE608BULL, 0xFDA7D4DF458D5E1DULL, 0x823E8588C30F2B1AULL, 0x6B43C13876186929ULL, 
            0x8BB853E10651401DULL, 0x52461996C943771BULL, 0x77E1826D8865365DULL, 0x2E763DD3B4B1EC48ULL, 
            0x4A58053CD31AA98EULL, 0x04FDA0DE83BEFF4FULL, 0x24C3CA921C6B97A8ULL, 0x400C614CADF17721ULL
        },
        {
            0x4A27EBAC1AF4077FULL, 0xD128A4D2FC71F821ULL, 0x93A989C2ABB4277CULL, 0x8496D067389F9ED0ULL, 
            0x42019BB21C995292ULL, 0x0E63D6EDEDDBA601ULL, 0xE80B0FDF5B37D2EEULL, 0x1EF40158C552BB3DULL, 
            0xA066C36EAE543183ULL, 0xC8CC1433925413D6ULL, 0xA906089E5F48290BULL, 0x565979FDD8E9748CULL, 
            0xAF4BE5DE2EEBD7B2ULL, 0x0E2506E27BB6D2A9ULL, 0xD22E794AD8A91200ULL, 0x044FF2C7EE778271ULL, 
            0xB3C7076F3F3ECD0FULL, 0x0769AB0856F14AB2ULL, 0x5E3D966A95D8C341ULL, 0x20348F88EB34A677ULL, 
            0x69947E8CF462BBF3ULL, 0x6EFC83469E79ED88ULL, 0x0305AD758730653AULL, 0x71E99FE6D64E43D0ULL, 
            0x0AA741CF2D22E64FULL, 0x8FCC48B47D57341EULL, 0x2C09A9A3D2A9A2FDULL, 0xB8531442FAB0CC5DULL, 
            0x1F2254402CDD4665ULL, 0xC15F7AAB9B3B11E4ULL, 0x015C024405C625DCULL, 0x104C138ABBB113C4ULL
        },
        {
            0xDC607F0A6957B8B0ULL, 0x79897B3A24FBB83FULL, 0x75F9F29B2EA37230ULL, 0x7BDF76109D89546BULL, 
            0x982484F261EE6F65ULL, 0x1476CAA8C7B5AD6DULL, 0x8511B51528F97675ULL, 0x92FE0DA69F490F65ULL, 
            0x20148B37488EA064ULL, 0x6A080751E458A5DAULL, 0x9E7E6762E6ADFE38ULL, 0x9FCA598C15C1CDE1ULL, 
            0x1C5D7F822B8823DBULL, 0x23DF1FE85DF9C94AULL, 0x656716688F4745A2ULL, 0x6F9663081F9DAD1DULL, 
            0x0A26BB0517EB6B6AULL, 0x97B875665FEDE340ULL, 0x370932E6C11D6942ULL, 0xB3A7EADBB50F0234ULL, 
            0xC7EEDE140561D9FEULL, 0x10C062062EE300AEULL, 0x399571F80278CCD5ULL, 0xE91A202F8C8ED9A7ULL, 
            0x8979D29A3071F736ULL, 0xE3A9F8ED9AB86CD5ULL, 0x97ED8A51E3C570E6ULL, 0x50E4EAD6FE7918DEULL, 
            0x4A93DC15BC640830ULL, 0x8CFE4CAB7AFEB053ULL, 0xEC632CC8EC35D294ULL, 0xD3071881C47FB201ULL
        }
    },
    {
        {
            0x009E780BEAB97933ULL, 0xD75C2B1A3F8BA72AULL, 0xD59B80FAEAC2BE1AULL, 0xF83F524B3260CB58ULL, 
            0x8397B4BD7C912BB6ULL, 0xC9005FF503AA3CF1ULL, 0xD91F3E6E37FCB7FEULL, 0xF17C43BCF4EA6B09ULL, 
            0x3CE71AF77516E267ULL, 0xEE9094141820CF7DULL, 0x869D73ECC71F3F32ULL, 0x1DED16DD8EDF83FFULL, 
            0x284C3D6BBBD35079ULL, 0xD6BF657797A0FDCDULL, 0xC939102A5DCEBE2DULL, 0x7354F08D6C448B93ULL, 
            0xE1EACAEFAFDFF92DULL, 0xF5F2C995B9C48745ULL, 0xC2BB93D976E3C9C7ULL, 0x23DFCDDF701BF9E0ULL, 
            0x0D33960E00117C34ULL, 0x0A503213B008104BULL, 0xB3FFCB93D81036A1ULL, 0x28221D64B6CBF8D8ULL, 
            0x760A52DAEEDA68DCULL, 0xA5079F031C8B8722ULL, 0x8D4E07A0F79CC221ULL, 0xB6BAE2EA97FB4D90ULL, 
            0xF7B9FAEC3B931604ULL, 0x31681B8DD8C74C72ULL, 0xFB829B98E4521D92ULL, 0xEBF65766EB248BD6ULL
        },
        {
            0x48AA4AA17DC02358ULL, 0x4A99F1D8F5ED2155ULL, 0x5A8AA4039CCCEE63ULL, 0x92B042CE2FA49F8AULL, 
            0x833EF8CC4B6E3F84ULL, 0x0B537E365D819FB2ULL, 0xB861CDE65D7B7935ULL, 0x56B04C5AAB956015ULL, 
            0xCE34E1DD5B79B76FULL, 0x35EB04967CB34B25ULL, 0xA7020AAA97B81ABDULL, 0x2FC3A9CD65DF2919ULL, 
            0x53A37AAF16AA7A60ULL, 0x528A9C0376605585ULL, 0x5C215B1326058F51ULL, 0x24A8F94E18D94410ULL, 
            0xBC9BBC18BE7C32ADULL, 0x5B4325D536F46C8BULL, 0xFB736C44A6BA3600ULL, 0x18B5975ECC17BED5ULL, 
            0xAF0D3CF37FBE6B62ULL, 0x5E98AF1921CF7F26ULL, 0x829858D50BFD1628ULL, 0xE4CC9DC2A5A3F149ULL, 
            0xB329F076B694FBBCULL, 0x50906FF515D35863ULL, 0x2AB693F9022CD880ULL, 0x39053D6598EEE910ULL, 
            0x6F6C6BD5F8E5B171ULL, 0x1505CFD815950302ULL, 0xB9D8AAF3D966077DULL, 0x5F461EC1C04E8309ULL
        },
        {
            0x43E8F51C851FA95EULL, 0xE36FBB095B4F723BULL, 0x2ABD930801B29B64ULL, 0x0EB86B3B4103575DULL, 
            0xB51F14332C25A0F2ULL, 0x24BA988BA4BBB5D6ULL, 0x8F501C899BF5F6CBULL, 0x307418EB136F2CFCULL, 
            0x969CE309C5A49BB6ULL, 0x971C1811052E9176ULL, 0x930F109E66FA475EULL, 0x75313A87A5BDFCE0ULL, 
            0xA1BE6CEBCC7CC8E7ULL, 0xD79C2E5243A09A50ULL, 0x5AA99EBA2DA0F72CULL, 0xBF068A3BE9971CC7ULL, 
            0x74076873F9CA0617ULL, 0x43CE3D0C444C16E1ULL, 0xE0C8B2CBE6CB168AULL, 0x1022BB9D96EB4A92ULL, 
            0x8264CC8ECDF8CAD0ULL, 0x95F9E15FA308D552ULL, 0xCCBF687B9C501A57ULL, 0xE358B9D0E051CD90ULL, 
            0x551B557D3A1F66D7ULL, 0xEBB492A0B4C9980DULL, 0xE7D4E309A222EC64ULL, 0x9E213B9D43E179B4ULL, 
            0xBE5640E8D7D49594ULL, 0xAC42C2A032BD8001ULL, 0x3F4ECE7567B42778ULL, 0xE71E7C68F235D326ULL
        },
        {
            0x34678EBFF4A7915DULL, 0x7AF91A2068E2390FULL, 0xF893D59A8560D799ULL, 0x6ADCD68F5E9E55D5ULL, 
            0x5C2B3843BA1D6D07ULL, 0xED54AFF3CBD95839ULL, 0x0FE4F11BD57BEFD0ULL, 0xCECD36AE8A461B68ULL, 
            0xD6CC81216B0720D9ULL, 0x35ECC30048669E57ULL, 0xC8790B65E6F314D5ULL, 0x024A4E786B9E920DULL, 
            0x94A0244A1838B895ULL, 0x933B2C658641AE1AULL, 0x0011C1CC98A85EA7ULL, 0xEFB8C937F97B5AB7ULL, 
            0x5D014F42DF337154ULL, 0x505DC34916B9E04CULL, 0x77E572C18C4CABF4ULL, 0xB105799A744A8AC7ULL, 
            0x81DD408E2536E071ULL, 0xC3D4C5E6DB3057A4ULL, 0xEB7B0A9BB99F940FULL, 0x93DEA68311E67662ULL, 
            0xB4E39874BF03362CULL, 0x64937275AE4CF7D2ULL, 0x8DC834A5755C464DULL, 0x28FE168A9E69EC2FULL, 
            0xDAC5092F4C64EEFDULL, 0x9CF5E5FCC3F36B51ULL, 0xC52EADADD1854F87ULL, 0x41C18C43A54048E4ULL
        },
        {
            0x8B1432093F27816AULL, 0x35BF711C96AA3372ULL, 0x6AC8FA4BE31F5EFAULL, 0x7FDA40D0375B6E0AULL, 
            0x92D4BEF44D9021BFULL, 0x675C00EE0271BF4DULL, 0x9B7E19A09565EEE7ULL, 0x15E6E228AA53A01EULL, 
            0xD97A20AB6C4FE6A1ULL, 0x4855BCD8E321B69BULL, 0x9544B6E78489FA7CULL, 0xA89DBBD86539E4ACULL, 
            0x116293A86E62ADB0ULL, 0x6DB5379C40B13B9AULL, 0x54BB4558F615DD66ULL, 0x7DFB652ED6F54BECULL, 
            0x5E7DAADDCFD85F2CULL, 0x216CE6F4F50A927BULL, 0x5B68A8E107BBF4A1ULL, 0xC463094FB045E28BULL, 
            0xC1EEA98FC464EFABULL, 0x35438B574A22679DULL, 0x39B6735BC65F2409ULL, 0x73D050E78802C3A9ULL, 
            0x0D715CBC5E9571B2ULL, 0x476D0B573EDD35D5ULL, 0xBEB52A4B0B8E7B05ULL, 0xEE0E4C883653C135ULL, 
            0xF50D14C95A32337AULL, 0xE7A2CEEE4C459A89ULL, 0x11CD167A64FE7B0FULL, 0x222A9C14CF81BDA7ULL
        },
        {
            0xF60F27E083C1F012ULL, 0xBF2D6FC4E5777137ULL, 0xB1A23D635B692AB8ULL, 0x34CB84CA0C51A5D4ULL, 
            0xE445E0B7AE9BEBA4ULL, 0xADBAF554E99966CEULL, 0x9D3A2AD7C2114BD2ULL, 0x0A3D4C3A8481A470ULL, 
            0x4017508340FF446AULL, 0xC58C21577712F066ULL, 0xF35EE5A69B58C2E6ULL, 0xA7FBA47657E18C03ULL, 
            0x3A8D9CCCDA1FE894ULL, 0x4CB5EBDB2124EEEAULL, 0xC116732F1ABE2366ULL, 0x922FA78024CB7CD1ULL, 
            0xB4E57E8376CC964FULL, 0x3E6BA33E860097B2ULL, 0x5C59E4049314BF9BULL, 0xD3EE1FFCE4467034ULL, 
            0x1C245EC42C3C4BCFULL, 0x7E5DE55713D1E6AAULL, 0x4E4127EF752FA71CULL, 0xB05713363A0443B9ULL, 
            0x4CA0BFEE40458728ULL, 0x2E5F181E626EF588ULL, 0x226F90C3F82D2313ULL, 0x5AAABBAFFB1A1E2AULL, 
            0x7EB62137E160A8BFULL, 0x2632B1FB4481182DULL, 0x78E047C4C2A255A1ULL, 0x680A81A3ABE9CC53ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseCConstants = {
    0xFA8B086A4B2F25C9ULL,
    0x0479539CC72ED709ULL,
    0xA54A89C1FB6DBE5FULL,
    0xFA8B086A4B2F25C9ULL,
    0x0479539CC72ED709ULL,
    0xA54A89C1FB6DBE5FULL,
    0xA74042AF0D463938ULL,
    0x6D5E028B47FBC3C5ULL,
    0x33,
    0x83,
    0x20,
    0x01,
    0x80,
    0xAA,
    0x1E,
    0xB4
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseDSalts = {
    {
        {
            0x04AA09E68B6CB860ULL, 0x2144D608AD55DC55ULL, 0x5A97B4F6320E4A4FULL, 0x1A6DA81794611B27ULL, 
            0x0AFF107C8EE1CFA5ULL, 0x76578161BC6249E1ULL, 0x73BA84BA6A7AC4E5ULL, 0x506370177062DD01ULL, 
            0x0E52E70764B97D4EULL, 0xCD32F9B7167D29FCULL, 0x241B20ECFC0FA9EFULL, 0x07F4FACD05BD15D0ULL, 
            0x50776DC84873AC60ULL, 0x2FBEDCDB6EB3524EULL, 0x2581C9F7743BAA52ULL, 0xA4669B2E3543E125ULL, 
            0x31B84B08B84236C3ULL, 0xCA975FA4CA340583ULL, 0xBF4E867C9FA4F916ULL, 0x4B0751FF55E81253ULL, 
            0x8CFC9A1B6B1BB39EULL, 0xDAE0F0D3BA912C1DULL, 0x0BF808FDD622B708ULL, 0x67113897E7312C65ULL, 
            0xC701D36C7E9156CCULL, 0xFF7B991F05293DADULL, 0x8D5FACD0F695BADDULL, 0x9CAA370516614D4FULL, 
            0xE68C94656B787202ULL, 0xE1187E4904BC947DULL, 0xC58579ABED27F04FULL, 0x1A50B33A916DDFD4ULL
        },
        {
            0x6BF97C0050FBDDF8ULL, 0xD0ABA6822AAEF607ULL, 0x7144CDDC5C8FB2A4ULL, 0x02119338FB32E3F8ULL, 
            0xF4441420F6C85009ULL, 0x204B9FDC9FDC0F54ULL, 0x1B8255DD7E586692ULL, 0x09A70AE08714D1C8ULL, 
            0x18B98C91F232335CULL, 0xBE921F947296B3AAULL, 0x27CE260C7E4CED88ULL, 0x71924CD9EED976E8ULL, 
            0xC081CBEE0F0DDBD6ULL, 0x34B094B79968A595ULL, 0x14CA18A3E519285BULL, 0xB8A9CAAFD7681A5AULL, 
            0x7A672F5F5DA99988ULL, 0xBE19BFCF9B3F53C8ULL, 0x957E1157BCBF7940ULL, 0x4A8EBC4BBD63840BULL, 
            0x128F08ED44712673ULL, 0x4CC842CCDA8E893CULL, 0x5496027B234E6ED6ULL, 0x568EB39CDAF7A762ULL, 
            0x39C931CD4987B20DULL, 0xB72E8D9004677823ULL, 0xBC189F68BD1E994AULL, 0x34D730CE0F5BF08FULL, 
            0x73C20D09376E43E0ULL, 0x9A1D3DDBE1501F76ULL, 0xBC86F3F1182099D6ULL, 0x0F8A8247E9A19FFFULL
        },
        {
            0xF6AB96CFD95B4770ULL, 0x868723DFD0EAF106ULL, 0xAD19D8D81F02FFECULL, 0x3AAFA29513871C99ULL, 
            0xBF2932146D96DA95ULL, 0x276AEFAFE53C394DULL, 0xB7CB65E3B21F4099ULL, 0x7A91ABF73570469BULL, 
            0x1814E37DB9675A24ULL, 0x782CD5BD5CA74531ULL, 0x3C31321C6EA36799ULL, 0x069F5DEC61F174D6ULL, 
            0x4F686DDC1BE95916ULL, 0xDAB57FB465681F17ULL, 0x0EDC00CBC42D2301ULL, 0x22EF6AEB9D187A7FULL, 
            0xCF03788CF7436071ULL, 0xC60A4D8E500FF850ULL, 0x4A88E16F3A9C5589ULL, 0x08CB06B2F355B5F9ULL, 
            0x15363159B496FB44ULL, 0x6BC6D940B3252E6BULL, 0x1690EBDCE4FF137CULL, 0x9DAA08316C96D7B6ULL, 
            0x0E71FB9A9B4EF6C1ULL, 0x35CC957A05FB749FULL, 0xA6E0D676A79DCEF7ULL, 0xF865BC7E5822066EULL, 
            0xC7C727D886C8FD11ULL, 0x7C07C2DC63E016B5ULL, 0x7C35D0423BAF4B05ULL, 0x3B09D782C4BA2592ULL
        },
        {
            0x04848FAB47DB090DULL, 0xE7571AF9C574B9EBULL, 0x11C97EDD8C18FC3EULL, 0x4D6EA313C0B477A6ULL, 
            0x292AB5507349987DULL, 0xA8A8DA4A8366B44CULL, 0xF9F076518754C515ULL, 0x24DB7012652E50C7ULL, 
            0xF1DC5E67497F75FFULL, 0xD5170AADDBC85940ULL, 0xE02B9014CDE033BCULL, 0x05D48EA77B99EBAEULL, 
            0xBF1F0FCAA7E99F5EULL, 0x102A0BCE300CFF81ULL, 0x0250B446691B8475ULL, 0x13EE1EB1BA83254FULL, 
            0x804395A7B00CF2ADULL, 0xDC47C8758C533B23ULL, 0x53E4C45D33C7C1BCULL, 0x4DEC9483DF947CBAULL, 
            0x5A54E75F9DFF9E05ULL, 0x6B360311BD87F0D8ULL, 0x3BF2EB1BD07CF003ULL, 0x815EB83B1A748C14ULL, 
            0x388C7B42EE0B892CULL, 0x162352279660E9B2ULL, 0x487170F3473A013CULL, 0x491D2442C16AA3AAULL, 
            0xCD4F9FE2992E30F0ULL, 0xCDEBD5297178301DULL, 0x092C835F81B0EC24ULL, 0xDAA79E5BC3EE7449ULL
        },
        {
            0x069EE61F7C3C2DABULL, 0x54C6B9806B39BF58ULL, 0xDA3AEBE04D6DAFFAULL, 0x28FF0A2A3F60B60DULL, 
            0x7C976680C9581CEEULL, 0x5FFF216952409C77ULL, 0x4470571DA3427585ULL, 0x10A3DCFA47C69554ULL, 
            0x760007DCD3784EF3ULL, 0xAB57A28D1D9FAE47ULL, 0xDE53A9F91013A4E6ULL, 0xFFB06CA908F775AAULL, 
            0x0C6C1BCF62C8037DULL, 0xA6D86039AA0AC3AEULL, 0x17273FF354DF3FA5ULL, 0x2CAD25B0D3A7D936ULL, 
            0x922A4BE35A6068EBULL, 0xB5A4FEA169489A48ULL, 0xEE5204E4F56F4830ULL, 0xCAF9799048E6EFF3ULL, 
            0x1BCB7774487979F6ULL, 0xADA22F6FFFA88E95ULL, 0x7931A2AF90F5C9D9ULL, 0xE16F2245696D5A79ULL, 
            0xF98E2FB30B81A261ULL, 0x3EBECE013C59D4DBULL, 0x7CC16AA700662FAEULL, 0x7CE7A10A6EE0C4AAULL, 
            0x8DA2405CE443BDEDULL, 0xF299CF32BE009602ULL, 0x0266256C71BC0D48ULL, 0xB1EA5D181EF32E3AULL
        },
        {
            0x71AE3385C0372897ULL, 0xD4FADC673F8326B1ULL, 0x1DC259C94510BF3AULL, 0x4AB46B65FA6090A5ULL, 
            0xCE8B9B935FAB5852ULL, 0x82D20D57410F5349ULL, 0xF7A81EB35C9A24B4ULL, 0xA08D06A0C52C4195ULL, 
            0x96C045D5A353BF0AULL, 0xED1D6302B4FAED5EULL, 0x8EBEABDBFDFDD3BDULL, 0xA001A4EFBB35059FULL, 
            0x86879BFA8A23D61CULL, 0xE9BD6C8F407C5C16ULL, 0x78D135A2140BBB89ULL, 0xE6140D91DD3A5EB1ULL, 
            0xB030FFAA0E4C06FFULL, 0xA4A39D53C2EDFACEULL, 0x24C94D8F92A11225ULL, 0xAB906C5F6337D802ULL, 
            0xBE113E9577ED9F57ULL, 0xA08D44EE0C5A6F4FULL, 0xEDFFE1EB13AD4DC0ULL, 0xB4B88B80CA673A93ULL, 
            0x873EA20EEF4B9095ULL, 0x23EA5954DA6A465FULL, 0xC044BC4229678EF2ULL, 0x5255BB27299E2806ULL, 
            0x28BB317CD8E6FA2AULL, 0x1D39DF56DE9923BFULL, 0x200548FFFA3281C0ULL, 0x2C262DAB8D98B9B7ULL
        }
    },
    {
        {
            0xD76A09FCBE626D47ULL, 0x54D3FBF20787F111ULL, 0x4B657F7EB35615DDULL, 0x95D629647B380321ULL, 
            0x4AE75445526967B0ULL, 0x5B3BE77C3FF1A878ULL, 0x8E80FFF4D38B3763ULL, 0xE37746A2BD1BD09DULL, 
            0x95CC65A633598900ULL, 0xC62C78E4C4F45CEAULL, 0xBE35D0BC0F1BC646ULL, 0x4FB62B86D26A1E43ULL, 
            0x235524B08C61D325ULL, 0x3E7805C8CDD33713ULL, 0x4F27EAEED118F1F4ULL, 0x820CA9F9BA9D912DULL, 
            0x610FE8210D3A8095ULL, 0xE695318B6DB30575ULL, 0x29D468287D905BF4ULL, 0x4AD18313484A3779ULL, 
            0x905AD0D8341E471EULL, 0xAB8A696847B45314ULL, 0x48F92E65BB0DCAC5ULL, 0x3E584A41B23B0313ULL, 
            0x7AF6E910A4D91B5FULL, 0x182CC702CF63576EULL, 0xE02FF48535B470C7ULL, 0xD72E384921B285E3ULL, 
            0x921E7CF5987FA9D3ULL, 0xEE9AC33902627D74ULL, 0xA41FA35C2D5DD1B5ULL, 0xB1458B25A31D3343ULL
        },
        {
            0x8F85E3F34CA5252DULL, 0x4D61B9479317337EULL, 0xB40D52DF8F1398BBULL, 0xE6465FCD168CCCE1ULL, 
            0x8BC7F4A7A529FC67ULL, 0x0420C36CCF7D9194ULL, 0x4F3F06C50BB1B84EULL, 0xABE632C49703B1ADULL, 
            0xA3579E5A678FFA09ULL, 0xACE3813B76E6FC39ULL, 0xA4DA5F550C0EE353ULL, 0xB26B4FD0A88241C7ULL, 
            0x366150E148CD668DULL, 0x50601884AC644820ULL, 0x83354EC922C8A42AULL, 0xF484CA887DDF2C1CULL, 
            0x5FDCF35FC02C45D3ULL, 0x00B76AB161F03CF9ULL, 0xFF06318586CFD047ULL, 0xE2EEF68291342E4FULL, 
            0xCB3B8C1BE55F215CULL, 0xEFAECE30AAD8F494ULL, 0x97FDCFFF47BDB0F7ULL, 0xFB51AF47AB006754ULL, 
            0x12792BBB5DC02208ULL, 0xB2528CF2F8C2A670ULL, 0xECED8EBAEB275D10ULL, 0x3365482AC2076D72ULL, 
            0x280F4071D8E07845ULL, 0xDE878EC4C21A3CC9ULL, 0x7590D246BCBA50D1ULL, 0x14B8E9CF95432E02ULL
        },
        {
            0xABE2CD9CEA293F41ULL, 0x49223FDB2F56002AULL, 0x3F4C5E1629BA25D9ULL, 0x883AE7FF57A6B8B9ULL, 
            0x8FC84A83A7DDB9A4ULL, 0x22E020FA5FF76992ULL, 0xFAE58CDDAF47DCE2ULL, 0xCC5C240828870891ULL, 
            0x97216BFBB1DEDD8BULL, 0x3796E121B574C029ULL, 0x87A0C32BEC9C5435ULL, 0x5B06271A10A62561ULL, 
            0xD2C5E6433434B5B7ULL, 0x66D3C8E17D712C92ULL, 0xE2CF7257F9D9C1F6ULL, 0xE4271319C753CB8BULL, 
            0x63236A12BC26E2F7ULL, 0x8AD65607ADDEAAB9ULL, 0xF7314FB02F086296ULL, 0xC684D3015F3798CAULL, 
            0xED4AC3DB4FDFFF0DULL, 0x31C012448F69FF86ULL, 0xEAEAA846A7E305A8ULL, 0x1D045B9DB69DD4CCULL, 
            0xBE34C8E568C36662ULL, 0xECBCBA7423727DEAULL, 0x932F44EA4FDEF9E4ULL, 0x7ECFDCB8939B944DULL, 
            0xC7BBA03E7876364DULL, 0x57BDEECF53758642ULL, 0xE8006A21A83F57BFULL, 0x6CAFC5362575B11FULL
        },
        {
            0x7A0A1B7DF3F5E70DULL, 0xDE785593D1D36507ULL, 0x98C4FC0E4C923623ULL, 0xC9EF1F13559FE0CFULL, 
            0xF616F2FC89B0AF5BULL, 0x7A86EABAEE31F374ULL, 0x5B40A77BB30FA516ULL, 0x974C18AF55103E28ULL, 
            0x62E77692B0347660ULL, 0xE49C48E1A3144076ULL, 0xC653269B4B40B520ULL, 0x46579A74B39B2B59ULL, 
            0x5CA3A9594DBEEFA4ULL, 0x7DB9BCC793E49148ULL, 0x3B2B637FD8D77D96ULL, 0xDEC674749B383A6BULL, 
            0x700E00ADE23F4FD8ULL, 0x31C69FB9391024E7ULL, 0xD08B2F22ABF9EC09ULL, 0xBA31FCBBEF9222ABULL, 
            0xA47E1DFA2D6EE33FULL, 0xD3724245671C2CACULL, 0x319D1DDB1B338E02ULL, 0x1D609FE6ED721F5DULL, 
            0xBE845803426FD020ULL, 0x34F2BD44D05D472FULL, 0x016DF54EF57FEAFDULL, 0xE90C19CF62F8F209ULL, 
            0x39F5D452F9E772AEULL, 0x32DCF3A8C87D246CULL, 0x54647E20BA58EE77ULL, 0xDC76F47DF2FC8B9BULL
        },
        {
            0x9DBBEE00D80AA594ULL, 0xBE8E01FF534ED405ULL, 0x09C8E857731C0720ULL, 0xD6575499C3B34471ULL, 
            0x835BEEADDB1C33DAULL, 0x71400E5D04DB76B7ULL, 0xB2836ACE6B4B26F8ULL, 0x4C004C618110B438ULL, 
            0x74951A4A0ADC8D6FULL, 0x7E931796248D5706ULL, 0x9470A71C3B994982ULL, 0x5D18A1F1805B5DADULL, 
            0xD88A49FA7606AFB7ULL, 0xB8DAB439547A578CULL, 0x4E361302EA9F3C95ULL, 0x4DEC935E04E17756ULL, 
            0x086910E8EAB9B5E2ULL, 0xA85DD2442BCAFDEDULL, 0x909A3D328BB3325AULL, 0x62B2D9B167BE8DB7ULL, 
            0xDD4F2AA0E59D88BFULL, 0x375EFC1F983311E9ULL, 0xAD81C7413FA04850ULL, 0x2460E90606E86F42ULL, 
            0xBB2ACFB332F80768ULL, 0xF85B17F2035279EFULL, 0x56FB2BBBE73ECA92ULL, 0xFCCD39D65B96C08BULL, 
            0x7C1241C9396E851BULL, 0x6F9E8D7585364FD9ULL, 0x57DBA98817F79B73ULL, 0x40076D7F8BCCEEF9ULL
        },
        {
            0x28BA3481E6F97993ULL, 0x34054EA7E0CE1436ULL, 0xBC2027DCB4DC2D0FULL, 0x2327E0AA8F0E3830ULL, 
            0x94F9332685B4855AULL, 0x52309D7D7CD028F0ULL, 0x945D9BC42D473B4EULL, 0x942325840A8DC01FULL, 
            0xA2D4DFA2176D4873ULL, 0x53180A5730055A0DULL, 0xD48A13450BF32E08ULL, 0x64D5D668AFE81CDAULL, 
            0x7559C4B0E36B32A7ULL, 0x4C58195503C8BB86ULL, 0x1D8BF52A9F2D0598ULL, 0x8F6465211FF9F576ULL, 
            0x0847A6894DBD04DCULL, 0x0B472A01A361F7FDULL, 0xBC29A3E19B70DA31ULL, 0x5F5B089F130C279AULL, 
            0x3CB9985458B0BA57ULL, 0xF774455CB2A6D01FULL, 0xC51589388B8AEE8CULL, 0x69BD0F201E329D87ULL, 
            0x82E5BBC64BD73CE6ULL, 0x88EC3A51716EFC5CULL, 0x294397E10DC5C9B7ULL, 0xB5B9B8D384545079ULL, 
            0x0332D9D210031785ULL, 0x043AAE0B3C8C81ECULL, 0x497E76EAD798CF9DULL, 0xE6B9FC8E58E37E9BULL
        }
    },
    {
        {
            0x0D4A34CD63A17EFEULL, 0x4FC4FD36A896A8B6ULL, 0x2A7F3A40102AA00EULL, 0x5A0F4DD9AD24216AULL, 
            0xDEFEEA3352F4D021ULL, 0x41699A9E47BB2246ULL, 0x7A56E85BA4C0B2D0ULL, 0xFD29D46BB1B7D077ULL, 
            0xE2C76F9587C6AB2AULL, 0x50C97B4E6C14D521ULL, 0x46DF9C996A63FF96ULL, 0xBC077DA5DDEF16E3ULL, 
            0x6518C65CCCA69DB6ULL, 0xFCB33D024387790FULL, 0xBF122618A62E6E37ULL, 0x7CADE4C7473863D0ULL, 
            0x9FA4589D24463C4DULL, 0xF7229D947B42A9B9ULL, 0x9C460A96F9C84F94ULL, 0x1E3396E4BF5871D5ULL, 
            0xD912EF4FB530BF11ULL, 0x4B98BF86828892D5ULL, 0x2CFB74D682C8234DULL, 0xA8C962396A8CECF6ULL, 
            0x88D011B43C957E90ULL, 0x015EEDD28FDF6F02ULL, 0x740EC6F9B7B8162AULL, 0x554F3FE43E07DC38ULL, 
            0x11AA152F1A027B0AULL, 0x9F224B9C5FEB65A5ULL, 0xFA6E2A8681515A64ULL, 0x9EFCA4258E554AD6ULL
        },
        {
            0x7D0432088A30CF39ULL, 0x538F60214ABBEC4FULL, 0x2084B129DC5DDD8FULL, 0xEDE9DC7D686E0AACULL, 
            0xD3010EB6F70DEFEAULL, 0xFD1F1CB541CC2A20ULL, 0x9AA91C49E2AC4B03ULL, 0x58E905A63FB757C6ULL, 
            0xB4AC7CC54E8ABA1DULL, 0xB57EA3897E941612ULL, 0xE1210E9D6F8A9336ULL, 0x10077618385C40F6ULL, 
            0x136A8CF042D27C40ULL, 0x6C2D56E5A1B38FAFULL, 0x5444B9EF366FA423ULL, 0x85C3D2B99CF0052DULL, 
            0x68AC39614E71E2FEULL, 0x98A6250E236322FAULL, 0xB0015B96B09BBB5DULL, 0xA6B1CABFEA2D032FULL, 
            0xB38E143513157545ULL, 0x8CAE7AEC741A9784ULL, 0x9B5CB0A8E2696880ULL, 0x1ADF2994EBA98EE3ULL, 
            0x65A103515DFD8A75ULL, 0xC7B4A10F09C129B1ULL, 0x1A00DB93D0B39594ULL, 0xB39C2D34BC9F9915ULL, 
            0xE48B22A4156331C0ULL, 0x23879C3082E561E2ULL, 0x67AD640273ED81FCULL, 0x6E0F11FA718CB318ULL
        },
        {
            0xE78DE5ED25F18416ULL, 0x3DA45B9C65525227ULL, 0xAC3804C3CE44D805ULL, 0x50A33F21227AF343ULL, 
            0x7244621E56D6647AULL, 0x75BDE1495F5795FCULL, 0xD18A48AB7D7B624BULL, 0xAEC8A933A67FCF7BULL, 
            0x9CF9C82C55928A66ULL, 0x7D575744E96BD096ULL, 0x0837B959482A6BCDULL, 0x948D76216BC136D1ULL, 
            0xAC46F9942AD93C02ULL, 0x24DAA0F9A55BED77ULL, 0x13E77156D784CDE8ULL, 0x236419C1520872AFULL, 
            0x2B9DC0B5FDC8A057ULL, 0x74DA60C95333856FULL, 0xD5B29E8983CA2D85ULL, 0xCF7E5107199B70A1ULL, 
            0xA58EAC6802A4CA1EULL, 0x2B1C2DA31BDE36EDULL, 0x3CCA5CE4F216A56CULL, 0x4DD19F36318FFF8BULL, 
            0x584E09489AA99C62ULL, 0xF2A2E97A725E00F5ULL, 0x183AEF6E8490C461ULL, 0xBD6A7BC4568C25ABULL, 
            0xCD6D4CDA1E7043ECULL, 0x293A3A08BF8150F1ULL, 0x644DE37AE5ACAD41ULL, 0x13A3D0725AF2CB64ULL
        },
        {
            0xC4257C513F94B548ULL, 0xD5CF0E59E404BC34ULL, 0x8602C0B9CFE27252ULL, 0x9F53E9699F2F99D3ULL, 
            0x7110744CA8BCB518ULL, 0xB9B93113AC78974AULL, 0xDD81F338B9DE70E1ULL, 0x1C1826B10816B567ULL, 
            0x97E33DFFAA59DB5FULL, 0xA27BE310F33C9EE1ULL, 0xF975366474650F79ULL, 0x1AC9DD3D9817432DULL, 
            0xCA8E326DCE3D2B84ULL, 0x19E7AA96502CA1D4ULL, 0x768FF1EFD8A237B1ULL, 0xAD3B84135458DDEDULL, 
            0xB76914CF97FA761FULL, 0x12EDF8A263AC0955ULL, 0x128512CA6FBC55D1ULL, 0x4AC7449B52392CADULL, 
            0x15A94B5C2E6C8287ULL, 0xD858391A00108366ULL, 0x0097E1540A49BFC2ULL, 0x4D118D4FFD8DB841ULL, 
            0x9B2F6F412EA37F82ULL, 0x4BE79451BE1F2DD3ULL, 0xCB6C9B40021CFDD7ULL, 0x7057C3C458CB199DULL, 
            0xD30695D074EB89CDULL, 0xABF022D45A1228B4ULL, 0x0E3457CAA9F82978ULL, 0x90EEA9A53B1723B0ULL
        },
        {
            0x528693D6A94F2680ULL, 0xD673D8BBF0156547ULL, 0x87E6979B64C14B68ULL, 0xBB0407F7BB7FC899ULL, 
            0x7B9F345371B401FAULL, 0x989181D397A7EEA3ULL, 0x64EB90954DA165ACULL, 0x1EDC9CF59E3C4DB4ULL, 
            0x2CA566DE84326FB0ULL, 0x54479FBD0C87C144ULL, 0xAE5B0DCB31D2C5C6ULL, 0x7F666581DA8E26D1ULL, 
            0x3375E9CBE90669DDULL, 0x1C975508CB5D842CULL, 0x48563F919F53B913ULL, 0x304CF6D587AF5D18ULL, 
            0x32CD8E26BF48CC85ULL, 0x09EB9D2CAD7EDFB8ULL, 0xE51B03C2B2274BC2ULL, 0x9717D194B8C7C419ULL, 
            0x620FE9CBC8C050EDULL, 0x77683375958A149EULL, 0x8D6DA97C9F01056AULL, 0x2C6755EC738640F4ULL, 
            0xAA901DD1E0338A49ULL, 0xE41BDEFA04FD452DULL, 0xE38D703FF0BBB4A9ULL, 0x4622FD5E1263969CULL, 
            0x1E7FE7E36559CA36ULL, 0x83139BF181F9F2AEULL, 0xF3E8994478DEAD4AULL, 0x17A001B2E60B2CE9ULL
        },
        {
            0x6168400525A67FDDULL, 0x089D23C960654F23ULL, 0x05B46CD983AC6717ULL, 0x28E75DF506102C5DULL, 
            0xB13428C32FBD2A1AULL, 0xBD1D0D96A986C869ULL, 0x378456C37FC14C34ULL, 0xB02612048F2101FAULL, 
            0x5CA356B19EF34822ULL, 0x8EFF5DE355F59F17ULL, 0x338B85CBDFCDA039ULL, 0xD73451C25044ACAFULL, 
            0x5F0A99BE1F0BB493ULL, 0xBA6F4382603937CEULL, 0x291DD9DB0316E37AULL, 0xBF62AAE6CD27859BULL, 
            0xFD514D30A1E55B5CULL, 0xA75BC7943FDD6170ULL, 0x9718CE47245E4059ULL, 0x4A8D66F8E549E374ULL, 
            0xB577387AAE58BD82ULL, 0x6400C265371A4E58ULL, 0x3FF77101B32F41FFULL, 0xFCAB9B5A8DD70356ULL, 
            0xA57439F3645788D1ULL, 0xD76293B6B68C54B8ULL, 0x0DF12BB100E2E1D8ULL, 0xD96D9B8D6D7F7546ULL, 
            0xBFA1A4A866242823ULL, 0xCA80835348D46DB3ULL, 0x670ED172AB011D9EULL, 0xEEA72BDD443E13DDULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseDConstants = {
    0x3E9182679D54239CULL,
    0xF5EB01028E3D262BULL,
    0xCE98EA5AEC14198CULL,
    0x3E9182679D54239CULL,
    0xF5EB01028E3D262BULL,
    0xCE98EA5AEC14198CULL,
    0x98B176F2BDE33BA0ULL,
    0x6B73A50385038AFDULL,
    0xDB,
    0xE3,
    0x3D,
    0x27,
    0xE0,
    0x76,
    0x23,
    0xA9
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseESalts = {
    {
        {
            0xAF4523C3CD1BAA38ULL, 0x9B31782ED9550E39ULL, 0xC57F166843BEC479ULL, 0xAD62A6AC7582D04DULL, 
            0xDBA44F1EA245D1B5ULL, 0x33272276847470EEULL, 0x18428137FCBA3DE2ULL, 0x58D5C1029D27C08EULL, 
            0x653E7A455890DE8EULL, 0xD4D42AE1C57603E7ULL, 0x31B273C62F856920ULL, 0x357E8DCC338F5765ULL, 
            0xDD31A5CBEFE45DBFULL, 0xB1FFB56CF153F8FFULL, 0x32362A0E9B47D2CEULL, 0xC08E7585EFD60EAAULL, 
            0x21B2A81984BD86CAULL, 0x0CAACFED0B8F5FC3ULL, 0x018FCA1515C95F65ULL, 0x81F1D0BD7212CEDDULL, 
            0x33F9775078755DD4ULL, 0xAFD9D3ECC6D255A3ULL, 0x1FFDB9EB4D700B27ULL, 0x75B75CE6A0367FE9ULL, 
            0xAD8C5B2A30CD7D38ULL, 0x5CD255C1D51697A4ULL, 0xCF638790BE107B26ULL, 0x9AB1DDD7C4DEAA8DULL, 
            0xC5F051DD1F88AC28ULL, 0x3A5FF6F040932E05ULL, 0x3430986F24723CB6ULL, 0xBE7046488ADFE18CULL
        },
        {
            0x7382C9D75625311EULL, 0x39936BFAFC807AA0ULL, 0x382B86D6FE925F81ULL, 0xBBAED1A5E3422D29ULL, 
            0x4B35CE0EFF6BFA80ULL, 0x59DE2A934FAD6D9FULL, 0x2598282924097B48ULL, 0x5BD60DEA6C515E35ULL, 
            0x343AF32AB7E1AF10ULL, 0xFBCF0DAFBCBA1F10ULL, 0xD722C04DCC78EBABULL, 0xAC618CD12BE09085ULL, 
            0xD7FAB4C3EA77E5CFULL, 0xB1908B4E0590FD47ULL, 0x04D775F9DEC80C34ULL, 0x01E377E801321E13ULL, 
            0x2BFC078DE6273753ULL, 0xB390F2FF75B3A3F1ULL, 0x553EC436EFBDE4F6ULL, 0x6177D2E7A6362F28ULL, 
            0x06A74223C47E9E0EULL, 0xC85C3484EFFC2FFEULL, 0x486B265345B983B7ULL, 0x2385C79D69BD55BBULL, 
            0x54DAA876016F09D3ULL, 0x9BA7247E8655E0DAULL, 0x10DB18FFED5D855DULL, 0xA8792F8CFD7D5909ULL, 
            0x51A8E0E4B81592E0ULL, 0xF51C870653A8C7F4ULL, 0xB7449B0DA4DA8EFBULL, 0x09CA76225788DA95ULL
        },
        {
            0x6834316B789F40BBULL, 0x515110B7DD5ACCAAULL, 0xBAA621868BBB7128ULL, 0x1E593A08BD014A3EULL, 
            0xDD0F11E3A7F6592DULL, 0x691E2AEB40B082B3ULL, 0xDC25D1FB2044469DULL, 0xF1EE262F06DA57C0ULL, 
            0x7237156A27F9954BULL, 0x4D95D718E331AF02ULL, 0x9A836B946D61A825ULL, 0x924CAF1872FFE0DBULL, 
            0x53FAD29145FB254BULL, 0x714FBDFF14513951ULL, 0xF5FDBD75E9CBFC72ULL, 0x12D7D283749BDD4EULL, 
            0xC8056820BC2C4D1AULL, 0x7F278A98016B9E05ULL, 0xECA6F287DDDB13BDULL, 0x4E40832A09A717E0ULL, 
            0xE21DF61F38902149ULL, 0xFB57582803BFEE72ULL, 0xB3801B68D00C48E3ULL, 0xDB0765DF9C428A89ULL, 
            0xF8BAA5AD89F43D56ULL, 0x0FCF0906EA695C24ULL, 0x2484F65156266BB4ULL, 0xD30DCA2D249E20BFULL, 
            0xE0B824946A7AB6E0ULL, 0xA488CFCB468717DBULL, 0xE4976E2242AEDD65ULL, 0x6391C18D393F300CULL
        },
        {
            0x1A5FC79A9E60010EULL, 0x549D24932B629536ULL, 0xAD70D8F5D1D2C1AEULL, 0x387BB90F0DE0FCB5ULL, 
            0x0515680C93B5A68FULL, 0x931D3466A130C09AULL, 0x8B195C1D6EEB9787ULL, 0x95A34B445917FED8ULL, 
            0x9AF059314DA2FE49ULL, 0xE54240490CC80A56ULL, 0xF2BEA9183BF49515ULL, 0x086B12781C1210F6ULL, 
            0x78CC747A476CEA25ULL, 0xB353DC0D1F3F50FCULL, 0x09B71F7DD3F469D8ULL, 0x777477448D9673BAULL, 
            0x05AB817350D8CEFDULL, 0x375F9E56B6ACB4C7ULL, 0x7F01C2DCA879C6B0ULL, 0xB618B70FE7E701FAULL, 
            0x83D94434A7F9F835ULL, 0x0E7507A43BFFA2DDULL, 0x15C84B4D6672B56BULL, 0x2C7D147FC16D8174ULL, 
            0x03A0C064CEBB8942ULL, 0x0381BDDD6957D73FULL, 0x1DB394F856CEC06CULL, 0x808578C8B91B235FULL, 
            0x2BCE9524504C42FAULL, 0xFD2189F387D19839ULL, 0x46C25E3EF2A144F7ULL, 0x14E3EA70925D9E24ULL
        },
        {
            0xB15B18102EB6D75AULL, 0xB666982E315B8862ULL, 0xC7B851DEFB4E7BBEULL, 0x45C3E9FCE8A9B402ULL, 
            0x433777C5626B11E1ULL, 0x273988054246233EULL, 0xBB097B3063A57123ULL, 0x34A062303CF52150ULL, 
            0x09F8551FE646A1F7ULL, 0x89920A385353E63BULL, 0x96B4D016FAA57085ULL, 0xF327062279258504ULL, 
            0xD534E960D03FD8BDULL, 0x311DFEEC6DEB42D4ULL, 0xF71981B2CC14B4AEULL, 0x30B143936DB18B9FULL, 
            0x8EC4183D525BF08CULL, 0xD9D0378D95970CCBULL, 0x60D374F370D28982ULL, 0xF91223F1E5E3FF6CULL, 
            0xA1DC56BBFDE5A851ULL, 0x6F86D83D8E20131DULL, 0x437F04EA63FAE92EULL, 0xCFC34742C66ADC5EULL, 
            0xF35A2A06F44A1E5AULL, 0x1AD5681B5A8F5E49ULL, 0x30203F597A65E278ULL, 0xD34137B43574F41CULL, 
            0xF5F37BC3013C30B4ULL, 0x11FFAFDF8585518FULL, 0xFFCD78FD851949B8ULL, 0x5239D610C2885F7FULL
        },
        {
            0xA9AC311F52063835ULL, 0xE9EAB9AC057205F7ULL, 0x96BD505D53CBF0C0ULL, 0x992D14F4D865FECBULL, 
            0xCBE032EEEFFC4BD5ULL, 0x98DCA15A8ECB8110ULL, 0x3715FF7AF42AB8B5ULL, 0xCAB48FE34E92E253ULL, 
            0x2FB627AFD6DB3FE8ULL, 0x2825F5E3AFBC97C2ULL, 0x00438C300A9D9F25ULL, 0x36421C1E8C04CE16ULL, 
            0x9A0CEBE290E7ED79ULL, 0x370A2900EBD8B349ULL, 0xFCBDB571C8174FCEULL, 0x1EE8117EFA17163FULL, 
            0x784F2AFF96A9BABDULL, 0x26B8634AAB08852DULL, 0x87ADD9078D37A9DDULL, 0xCC4B41CD9D721E73ULL, 
            0xF9FB8C8A1A1CDAA1ULL, 0x1959823BD0056E8AULL, 0x3BC090296DD97F1AULL, 0xA53549089C8793A0ULL, 
            0x15067A37C0A6C996ULL, 0x4E1F21AE4692BA6BULL, 0xECF7615CF05AC411ULL, 0xFB2C2C07B0EE9999ULL, 
            0x634AEDE7B4EBA76CULL, 0xFB632200A44DA9D5ULL, 0x8730F60FE1789075ULL, 0x83614B71EBC8A82BULL
        }
    },
    {
        {
            0x5768840FEE19103DULL, 0x3CA0DBD5ECB86FB7ULL, 0x870D668FBF131EA1ULL, 0x6AD7F6F4BEF4F011ULL, 
            0x30968764DE250A20ULL, 0x8DC136DD501E4507ULL, 0x2AB7645D2D9B7734ULL, 0x2A3404BDD9A1E598ULL, 
            0x61F54D46A8470766ULL, 0x5416FD989F76DC80ULL, 0xD2B6A1881184C2D9ULL, 0xE08713F5F70782C6ULL, 
            0xD78C10B93941419AULL, 0x3336031F6FDF305EULL, 0x45D447ED189CA8F0ULL, 0x498EE1FEEE4E29F4ULL, 
            0x255A1067CB3A3C73ULL, 0x81225D52FCAC9A03ULL, 0x3C6E0496C1CC0C21ULL, 0x43149FAB85248C72ULL, 
            0x24EBF3ABA6D23C48ULL, 0xF9F811C574CC22FEULL, 0x90FEF44287E798D0ULL, 0x907A1E2707ED9DC9ULL, 
            0x1D991437F8989A12ULL, 0x20237EDC6750D614ULL, 0x5B538F3368FB902DULL, 0xF077128FE4EF6775ULL, 
            0x93974374037D6B5EULL, 0xC040189F4507A2B5ULL, 0x1AC89DB37EDE8602ULL, 0xC83A0D6355AFC522ULL
        },
        {
            0xD4921944DC6C94E3ULL, 0x5DC28D84B0D60737ULL, 0x85714F587E465F01ULL, 0x0F5D1DB2C322E21CULL, 
            0x28EA115FA3723DEFULL, 0x9DC1D6BCCFDE0585ULL, 0x41AE888C238F0E55ULL, 0x34A8AEBF7604BF52ULL, 
            0x8154DF23BDA2DFFAULL, 0x36266F060378C041ULL, 0x3C5CE6CF1E54A919ULL, 0xEA0A376E21812EB3ULL, 
            0xD4078725DCC1BFDCULL, 0x2DE5F25B4FAB0C6AULL, 0x54B4558DA40907CFULL, 0x59A6511562E121DFULL, 
            0x38C667C344224DEBULL, 0xDBEC71B50535DDC2ULL, 0x456897ECA08B07DAULL, 0xC86884619DC49C6EULL, 
            0x3642D90FB0BEA89AULL, 0x15630F3A45059B3EULL, 0x30E4CD497B1EE97AULL, 0xEA11BB58ED589B01ULL, 
            0xA5C86AB53862F2B3ULL, 0xE929002041CC1F21ULL, 0x0075D4AA14E5C0CAULL, 0x47681EF5D2E59351ULL, 
            0x295420A2B6D04CD8ULL, 0x971306849034031CULL, 0x77824C3FA6C1BC10ULL, 0x622D313A86F1C08DULL
        },
        {
            0x4BD46DCBB53BE196ULL, 0x33D9154A4438BD21ULL, 0x3E0906F8ED2E66CDULL, 0xDD0A2F139C2871E3ULL, 
            0x88B7021177501EE2ULL, 0x106EC242EF37E609ULL, 0xD4CB556A2438A7A6ULL, 0xE51220D2CB02CD2BULL, 
            0xDA4CC8E092CA5838ULL, 0x0A37D62A587B4E68ULL, 0xE2CFA4B679DBEB75ULL, 0xC939A69FB1040702ULL, 
            0x00FA14E4DF39932FULL, 0x3D35558B3AFD3360ULL, 0x4043A2ACB30CF9B3ULL, 0x3C832E167F70DA34ULL, 
            0x838609F6F08A1F9DULL, 0x59866EAB34BD320BULL, 0x3884D617D2BF8EACULL, 0x2AFCA92D3542C407ULL, 
            0xB9651A64B4395166ULL, 0x1553875BC76A090FULL, 0x064F7C24A505387BULL, 0x86A13A721D9CDF19ULL, 
            0x84326B628B3F3282ULL, 0x2451464FF4C8B9EDULL, 0x26154C6F3CD2C4A7ULL, 0x889E24DA11F879A6ULL, 
            0xBF6C24B98FB09A11ULL, 0xD596E2EF27A80AA6ULL, 0x6F9485823F6199B0ULL, 0xA8C89C28C7CC7CEAULL
        },
        {
            0xFD5F249A6C7EFE07ULL, 0xD3B86C30707B8C47ULL, 0x2AD325E26D999A67ULL, 0x225C560BFE081024ULL, 
            0x25124DBBD3CB05DEULL, 0x6DABDE5F26990960ULL, 0xF9E768075C39F705ULL, 0xCEB8F56B5754AE16ULL, 
            0x55D5D3E71F771C39ULL, 0xD4BD54059FB27240ULL, 0x57880634195B7D52ULL, 0x63BF05BDFBA5251BULL, 
            0xB26A0C60CD9B3782ULL, 0xE43945D03B621F55ULL, 0x1A0CB84676329771ULL, 0xEA4E6F7E3F2E764EULL, 
            0xD658C4394AA81E84ULL, 0x18C6C01E5B4F17D4ULL, 0x6640FCC85FE4A2B0ULL, 0x8D705362B379FF0EULL, 
            0xC4563D1C5FE2449EULL, 0x76C40D8C7ECC88D9ULL, 0x894978C165FEBF6BULL, 0x59ABBFC15332298DULL, 
            0x8CE29B1950CE08CAULL, 0xBD7F0A6B9D820CEDULL, 0xD540E1BDEB415017ULL, 0x9C0EEA0250371C7CULL, 
            0xE54163AF3BE0CB8BULL, 0x6F4B182D726B72BBULL, 0x31ADC7D98B93A2C2ULL, 0x8C319607754F6EB9ULL
        },
        {
            0x3DC5272289626853ULL, 0xB4FBC858B05FF840ULL, 0x9853BE7D3DE85956ULL, 0xE9DACD1E33F87C96ULL, 
            0xE7A714BA03CCF6D3ULL, 0xB27DB62E10AA7D54ULL, 0xC927FCAE5DE58C68ULL, 0x0F38C473241399FBULL, 
            0xF04B94E2133308D8ULL, 0x5295CE19DBA7DC0EULL, 0x6437743D41BA5B7CULL, 0xE2FD97564F152B7AULL, 
            0x68F0EF12B26039C8ULL, 0xFEE2F6D92517F757ULL, 0x25891C18DFAC903AULL, 0x7558A77A66C176AAULL, 
            0x2A3B2CFFD365B858ULL, 0x2864EB9C7245C780ULL, 0x9E07FE9C1EC5D128ULL, 0x0C5FE7D81011D7A5ULL, 
            0x682CDCAF055DC25DULL, 0x684B09DF4EC205BFULL, 0x723E6880E8402C35ULL, 0x06EDE82A99612897ULL, 
            0x58196F864EFEF32DULL, 0xA6EF57BCA8FE791AULL, 0x3EDFD06CAA37C859ULL, 0x3C30BDB012EB11C2ULL, 
            0x246C9B4CDBB67633ULL, 0xC3C3A436F5588998ULL, 0x1BFF63DA08CE3EF5ULL, 0x1C8AE2FC9F6A059DULL
        },
        {
            0x08C81F85CF691505ULL, 0x4CF67C581DAB736EULL, 0x73CD59CAEB445AC2ULL, 0xD29FD7F670EA11A4ULL, 
            0x68E8147353B6142EULL, 0x39CE07DAE2EB8877ULL, 0x027F114B4B7D6630ULL, 0x016BB9A48B03BECFULL, 
            0x82079C2E50229E7DULL, 0xB85A06C7E0BC984EULL, 0xD6F28C62A2D0E92EULL, 0xDE97E98A189316E2ULL, 
            0xA4F918AB441BF7F1ULL, 0xBCF7C92281DB83C1ULL, 0xCDD297B02ADB167AULL, 0xD17FAF4324EAEDEDULL, 
            0x93EBA0A7937701F5ULL, 0xCAFD63D01B8773ECULL, 0x5015129ED2479308ULL, 0x0A9FA46C5FDD352BULL, 
            0xA8EF2EF3C5EB9B47ULL, 0xF574D54FBF024A84ULL, 0x3B32607560848CA3ULL, 0x34B669B06F9685B2ULL, 
            0xDABCB2171D2A97BEULL, 0x4CFFFBF81FA9AF3DULL, 0x3B5EE664FF308706ULL, 0x91D7F7C8AC640B27ULL, 
            0xE5ECDAF578DB87CAULL, 0xF4B6AF7196B77B93ULL, 0x92D961CEC1259F24ULL, 0x27333B6F9EB7D479ULL
        }
    },
    {
        {
            0xBE5EF007D55FEE11ULL, 0xB7B972E8A0B75042ULL, 0x1D584E04B4D20E07ULL, 0x38DFE92139435D76ULL, 
            0xBF36A4114D9EF591ULL, 0xC3C5815C3727C7C4ULL, 0x2AE7DA64783FB62CULL, 0xF0688C43D8D86997ULL, 
            0xA4848E9616029908ULL, 0x5EE146B5C43F0AD7ULL, 0xB82E7E027753B3A4ULL, 0x1CE9AA90278634E2ULL, 
            0x38CD18B5D83E113DULL, 0xDC89290DAD0C0ED7ULL, 0x7D04023C5DDDD4C8ULL, 0x3BED68B570014EDFULL, 
            0x9CC4DF27C7DC4387ULL, 0xF04ACADF157BBDAAULL, 0x4428CBBA54C46358ULL, 0x27A86AC84CAC9855ULL, 
            0x21D7DF14BEFD0CE4ULL, 0xB87D5CF3B0967AE4ULL, 0x75FDE42CC68B3019ULL, 0x76B8259A79BFEA92ULL, 
            0x3365CC16196D9A28ULL, 0xD19F0FF0AED3FD06ULL, 0x3F68CAAC773CA890ULL, 0x0022A2053AFE08F8ULL, 
            0x31AA44597FBB173DULL, 0xD95BF318E0CDC27DULL, 0x3CAA2DA2A6F973F0ULL, 0xCE0BA65838A537C0ULL
        },
        {
            0x1C8B2A52F69BC093ULL, 0x78CA5C29F20A050CULL, 0x9549AE01CA5FA59EULL, 0x8525A5A8D54F8247ULL, 
            0x8BC78131996221AFULL, 0xE9EA92EA8825ECCEULL, 0xCE0623F5D8ABCBFDULL, 0x0AAAD60F2F33F5D8ULL, 
            0x59ABC540588DFD76ULL, 0xF1DCF8B1C1D3ECA2ULL, 0x6B97E3AF87B0211AULL, 0xAABDFC6957091D17ULL, 
            0xFF8F03101E350808ULL, 0xBD8484501820767CULL, 0xACEAB3D879772079ULL, 0x786D9F86C227D575ULL, 
            0xA41245541932BA95ULL, 0x4F9D84ABD20F87B8ULL, 0x6DFCD68C39074FCFULL, 0x3C1BF195B8977BB1ULL, 
            0xBC151E1845646B6AULL, 0x7B1BE6E2190C5CB9ULL, 0x2D140E6E9E56A2F4ULL, 0xDD9E0054449729F7ULL, 
            0xD95932A7A3614699ULL, 0x174C3F56DCF202D0ULL, 0x178D1E2B53F6CFD5ULL, 0xF5F6CE48C5B84272ULL, 
            0xCB805DEBD76EB917ULL, 0x2528D0F69BD6716AULL, 0xDFDCAC34C94D894BULL, 0xD91E5F172A1DA94CULL
        },
        {
            0x96FC01FDE4D8EA9EULL, 0xEB6D43792F7C565AULL, 0x2E364BDDD66044DDULL, 0x2ACB69ECA03875C8ULL, 
            0x2FE1BCE310839F46ULL, 0xC32D1CC6841EA5E2ULL, 0x5E80F6297A53EC99ULL, 0xBABEF9B18CE4ABB1ULL, 
            0x52B856BCF9E362E6ULL, 0x8ADD8DB1B3B28FCDULL, 0x7AC077DA01C6B7B8ULL, 0x4DAA10D5692BCE59ULL, 
            0x3578AF7ADFAD50A8ULL, 0x6A732D97269AD7ADULL, 0x7146D9C927E326E8ULL, 0x86D7A922CAF094E0ULL, 
            0xC060217E2BC0AB3EULL, 0x5B52C6EDE6A14EF5ULL, 0x046BD0DC223232E0ULL, 0xE5A488D109C23A50ULL, 
            0x01039D2E8263F820ULL, 0xAF128392232F4B44ULL, 0xB9DE136AC9F84109ULL, 0x7D64853438438734ULL, 
            0xF620CBFA2BCB1E5FULL, 0x633A75A55FC508E8ULL, 0xA3B4E77E78DA030DULL, 0x9E5D89375D239525ULL, 
            0xC6025860DC2D8C04ULL, 0x1D804B0FCBD88CCEULL, 0x4F410EB1826AFFCAULL, 0x54ACA302E6178048ULL
        },
        {
            0x834CCE1FC6129BCEULL, 0xEFA2E62DC9271940ULL, 0xF77B429EF3F2DDC9ULL, 0xE7C50AEBA97619C1ULL, 
            0xDDC5B238F5458C4EULL, 0xCEF0CDC60D5F96F9ULL, 0x301208A83F451CB5ULL, 0x31C4EAE12D08459EULL, 
            0x62AA21E990C7F5C8ULL, 0x3E60FA93A17CD7E1ULL, 0x3C29EFD43FB55BF1ULL, 0x5422DDD2F5F56B0EULL, 
            0xFF2BC7C70F5A7DDAULL, 0x38CA3823684BA5BAULL, 0xCBD42D06CF0AE8BEULL, 0x59D99A518EC5DDBFULL, 
            0x60924453EDE26F5CULL, 0x25AF6E5A8EFA528EULL, 0x3DD0BCE45DE62DFAULL, 0x5F2446BB30C0B3DBULL, 
            0x0C16C1BE90851C66ULL, 0x59F1FF8C769ADD31ULL, 0x0EF0226630F96E68ULL, 0xBF7F6DB04AC4D38AULL, 
            0x9D3CDD727479B8F8ULL, 0x986091B60ADF55C6ULL, 0x323A82A9A2840B39ULL, 0xE6CD6608227D5195ULL, 
            0x72E34C089AA655C3ULL, 0x5EBA769555CCB5BEULL, 0x83687CDD3B265F0AULL, 0x2D73093BB8EA35EEULL
        },
        {
            0xB96A14740A1B17FDULL, 0x29ED5B379BE4B007ULL, 0x7A2739E0AF4DB9EBULL, 0xF50EC6C36EBEFC47ULL, 
            0x0877BAE3F9EED38AULL, 0x605BB5D5CBA66B3DULL, 0x297BB1B87ADECE78ULL, 0x09ED94F08E51F76FULL, 
            0xF9309C061AA02B47ULL, 0xA815A0149628DF4EULL, 0x694CCEE3B0C636C3ULL, 0x28539ED9541CF1B2ULL, 
            0x69DCC47F0E0EEDDCULL, 0x69B6D675154DDF8EULL, 0x08BDC708AA6D6D65ULL, 0x2910ED1C1E71D689ULL, 
            0x0AC1CD7A4E1DFD71ULL, 0xD438842DA4715D1EULL, 0x255292F688142749ULL, 0xC504AE9E28845299ULL, 
            0x93005C60EEC5F3F7ULL, 0xDA5836918A968DCFULL, 0x7BF2438016E9E114ULL, 0x2CDBBDB25EBA5B1DULL, 
            0xF778ECABF9F09A4FULL, 0xC9EA673CD7CE5DACULL, 0x96BDEB3089B8F41BULL, 0x90B68C4E5E0A0939ULL, 
            0x0E97AF8169A6A377ULL, 0x23324025E34ADBFDULL, 0xA5CFF497637BE601ULL, 0x4C93C6791B0686E8ULL
        },
        {
            0x3EBD87728862E043ULL, 0x455A9CF25BCD7A02ULL, 0xD37241450F267379ULL, 0x4B4EBAA5A7ABE594ULL, 
            0x16DB606590D629E8ULL, 0x8E39A4F1FE89C574ULL, 0x36AFEDE639A327B3ULL, 0xB8E5EBF29698BE73ULL, 
            0xC8E3D12B78D717B0ULL, 0x3422BA16876C33A9ULL, 0x9B1CB7AF48C02FEEULL, 0xCBEF2891B15A0649ULL, 
            0x5936BF18B6DE5C0DULL, 0xAE3600DA49B62BF2ULL, 0xB2FA7FE27C085C83ULL, 0xCC88C23147C4AA96ULL, 
            0xF428160958FD9D38ULL, 0x6D830A6AE89F5F88ULL, 0x94040BEBE87C5470ULL, 0x06EE5D89DB2767F5ULL, 
            0x2E2C0A04317F509AULL, 0xDB69BE450CD0FF78ULL, 0x27F9E88D3D82C63AULL, 0x9AEC6D64D7E80D49ULL, 
            0xDD4480D63179075BULL, 0xBDBFAE3BDBB6C46CULL, 0x8EB232036A66A681ULL, 0x2E7183952098C3BFULL, 
            0xEAD83DFD2D5E788DULL, 0x8D400FBBE7B2E638ULL, 0xE4CE3B7547434D1CULL, 0x599AE6B7EC53B4D1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseEConstants = {
    0x9773D598A73BFB6FULL,
    0xDBF55790C33722B1ULL,
    0xA6577DCE600521A5ULL,
    0x9773D598A73BFB6FULL,
    0xDBF55790C33722B1ULL,
    0xA6577DCE600521A5ULL,
    0x4183AFD40DBECE50ULL,
    0x0E01E56D1D1EF516ULL,
    0x25,
    0xDA,
    0x11,
    0xE0,
    0x6E,
    0xD6,
    0xA1,
    0xB0
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseFSalts = {
    {
        {
            0xAFE8F3DBBAFD84C0ULL, 0x8E4662A878217070ULL, 0x39CA95646300F592ULL, 0xC046C4AE87CEF77BULL, 
            0xF4816DBE7D4831FCULL, 0x2A77AEF2284C72EEULL, 0x719F222EEAE327E0ULL, 0xF21E9E570E59F0D7ULL, 
            0xB2F0DEB7191F730BULL, 0xC1BCA4CA21399CE8ULL, 0x7D24C187C43CEF38ULL, 0x1617CA50301B1F05ULL, 
            0xBAA1BD0E3D824E83ULL, 0x7ADBEE2B586EA26AULL, 0x0D0735993C64A366ULL, 0xFCEEDF912488DD90ULL, 
            0x6138EEC2D7113779ULL, 0xF07B25290DE76AD3ULL, 0x2B86F6F24EA01DBDULL, 0x05763CE24FEFAA93ULL, 
            0x64B896ED1E3D1278ULL, 0xAB8662B41A1BFA72ULL, 0x0B42094D0AB0930FULL, 0x23E79B3B77369FF3ULL, 
            0x04C62B2F82D6495DULL, 0x3DDDC5C50BA318F0ULL, 0x665955B4A403FEFCULL, 0x11CB6ABAEAE3AAD3ULL, 
            0x2325B8CAB899EA64ULL, 0xFBAC63C78372DDE9ULL, 0x2E5E06E746D4C44DULL, 0x43774FFFD517C8F9ULL
        },
        {
            0xF91DCEBA306D219EULL, 0x2692F4C8E4C8403AULL, 0xC0E447F3D631DE99ULL, 0x9413E635A1FBA3CDULL, 
            0x9281438377AE56A6ULL, 0x688986353D8EFB69ULL, 0x47B7546F6EB7A282ULL, 0x40D7328ED4002FDBULL, 
            0x94C1C35833194A44ULL, 0x3A502C701FC259E0ULL, 0x6EF0C9972CB970D2ULL, 0x605238ECA153D783ULL, 
            0x42F100118AFEDB4CULL, 0xA6A691FCB87EF4E3ULL, 0x1072403ECF207A14ULL, 0x1CE9D26FBFC4E767ULL, 
            0x9B92D01EEBB10D00ULL, 0x36CED327212A99E0ULL, 0x575D2A64C255B649ULL, 0x4EABEC0A3662CB60ULL, 
            0x12F0B04A5D6EE3A2ULL, 0xF33FA4EE8FEBBBCFULL, 0xC9FF244F34C1F2D6ULL, 0xD282AD642161E653ULL, 
            0x72862416F23E17AEULL, 0xD118CF7BB4D5C09DULL, 0x2D41519D37CBB259ULL, 0x7CF95105802FDB9AULL, 
            0xF5FACB77F67DFE0BULL, 0x794DA46A9937827EULL, 0xD83D60E04C3CE5F5ULL, 0x5642B3764B1FC651ULL
        },
        {
            0x236D0136A8929443ULL, 0xCCCB2125411CB6AEULL, 0xF0C091B5ED17F75BULL, 0x4F27AC467647D6C0ULL, 
            0xB28C0904583D389CULL, 0x512067107D48D9E1ULL, 0x357A58A872D512DEULL, 0x66DC9E17CD18D12AULL, 
            0xB3F1BAC732886625ULL, 0x12AB1CD3982A0FA8ULL, 0xB224ECD01D148666ULL, 0xB11CBB98A17303AAULL, 
            0xECC413A22FD13429ULL, 0xC343258E09FA35CDULL, 0x52C726BF05B36FEAULL, 0x81681899B462FA12ULL, 
            0x9A6E1E92AB963C03ULL, 0x543EC2B74EDA47DCULL, 0xAC0533A974C75F1EULL, 0xB52EFE6594CCC9A5ULL, 
            0x8C325B83ED46C5EFULL, 0xC3D9C3EBC3C9F0D3ULL, 0x1DBFC97524ACD542ULL, 0x3A819D18A8CB68E5ULL, 
            0x304EC6E00B38B055ULL, 0x7871030B155BBA3EULL, 0xAD50A5D546C0271FULL, 0xBF8A5A58C11DD77CULL, 
            0x2C8689F64A07D5DFULL, 0xBAC5B12FFDA424F0ULL, 0x34F62D6907027A9FULL, 0x68931F15585A215AULL
        },
        {
            0x3C35DFA48D459C42ULL, 0x7E0617D0FD906C34ULL, 0xCB09D4CFB00C80B9ULL, 0xAB1A1937CF0FB29EULL, 
            0x0BDDAD2BBBC8A285ULL, 0x93A84DA1DACF72ABULL, 0xFF8892BA496DD1DEULL, 0xC0DB8BA45125CBD0ULL, 
            0x044BA1C0E5677482ULL, 0x48B8FBA4C8D6D280ULL, 0x8A48B8FEEC7B298FULL, 0x1F8E1B0E8111446AULL, 
            0xAFB178CF4829BB6AULL, 0x1F3445CDE7C98292ULL, 0xDC9E83DC638DDA89ULL, 0xF462947602A500E6ULL, 
            0x9080D92DD7D338B4ULL, 0x8848B1B8AEA5B460ULL, 0xEE52DB6A04C1A64AULL, 0xC68F79B0F5D39301ULL, 
            0xAEE82BB67646D519ULL, 0xE6585EE14629BBC8ULL, 0xB6D50FC6667A2E87ULL, 0xE4F195DCD39F98A9ULL, 
            0x7E392EECCFBCBBC5ULL, 0x9865FA344311194DULL, 0x59D031B8A70C4C05ULL, 0xE830760DDD5E5D96ULL, 
            0x7B0A04BCEFA93AD0ULL, 0xF23237C2557AA9F3ULL, 0x7F65C5B9F087C811ULL, 0x3DEF75C2F227E218ULL
        },
        {
            0xD3A38AA6C7130259ULL, 0xF9C7C3AF907DB123ULL, 0x68CC7436B517B90CULL, 0x68BF82193E338426ULL, 
            0x698516B230417878ULL, 0xDFE8F93EE26BE11DULL, 0x28600A68F2E90B9EULL, 0xB622D6901C1156DBULL, 
            0xE6019F0D447E2B81ULL, 0x709DAB0EB8685EAFULL, 0x0752146579E5ED60ULL, 0x707526948FAF7E6AULL, 
            0x1BA49151B8A2AD34ULL, 0xB291A1151076B578ULL, 0x449EDF00F078B0CBULL, 0x5A292578C702C33DULL, 
            0x350D8773BF2E9D4BULL, 0x2D1E7E0A6C3567BAULL, 0x03DB7DB1BBE62909ULL, 0xD282934A0FE747B5ULL, 
            0x1E2778542FD04D33ULL, 0x3BD7EE4F32B00EB9ULL, 0x18753AFAF5FD46D2ULL, 0xA5B005E2FF4A2591ULL, 
            0x4877B8F662302360ULL, 0x84BDD4FDFD5B03C8ULL, 0x8ABB39365C307CACULL, 0x1A0795EB29E3A6F4ULL, 
            0xFA4565A093047A7DULL, 0xE3F426F116911387ULL, 0xAF4A0000F6C046B9ULL, 0x891AD64AEDD92D7CULL
        },
        {
            0x9882275BC16DE08DULL, 0xB788F49A7FB81D2BULL, 0x1336862AEFA72456ULL, 0x7EA9057B2EC2FBE5ULL, 
            0x71EE92DA4BD7124FULL, 0x2036753B9E453BBFULL, 0xCA27334B371B31C9ULL, 0x1D8B932B5779D29BULL, 
            0xB7657E7D451F9E86ULL, 0x043F9A99BE76FFC4ULL, 0x5E914386C4950377ULL, 0x185F9E69C50139C5ULL, 
            0xB6C8BC5C3E84CF6EULL, 0xEFFAF5190C0C922BULL, 0x2962CF6E3DC354B6ULL, 0xF6624A44151910C4ULL, 
            0x8880883AD3C21CE1ULL, 0xD893D34CCB578409ULL, 0x43CAFB8323B2BB16ULL, 0x4F3525AE4076790DULL, 
            0xB7284A2BA9A6AF68ULL, 0x6011771E721C5826ULL, 0x565EB41428BC2B9DULL, 0xD78E1647B5A9AF99ULL, 
            0x2D4B200885758E18ULL, 0xCCCB128A8AAA8083ULL, 0x93A18D78977459FAULL, 0xA659944DE7FF4490ULL, 
            0x56A9286BBED4BFB1ULL, 0x5CC393E330270C2DULL, 0x57CD05A78F2E53E9ULL, 0x9FB6EA40CD516173ULL
        }
    },
    {
        {
            0x6588A765AC4DACABULL, 0xD9DDF0AA37E116D7ULL, 0x9EE7A5DDCBE34A97ULL, 0x73C8AFBA96DE88CCULL, 
            0x478601CBA36FA7FEULL, 0x4CA1AAEC651E7EC2ULL, 0x534C3ECE73640B2DULL, 0x898213AF4662BD59ULL, 
            0x9A3A9E5A3F98B516ULL, 0x7F11286A061D3D6BULL, 0x7D9A3424EAFF7B9DULL, 0x7A64229B289E8758ULL, 
            0x43CB4C44DF20C92AULL, 0xEC7E8167345AABE2ULL, 0x0A0696A4FD0EC6E0ULL, 0x29D6E4D49F64611BULL, 
            0xA7249D946D290314ULL, 0x8C085B3C64503979ULL, 0x7547B7BA6CFBBC51ULL, 0xB669A3D3A99A08B8ULL, 
            0x5E4D940DB52A98ABULL, 0x39C70F66BDFC6940ULL, 0x27E8B8B7C8FE26B4ULL, 0x21E3D766DB433A92ULL, 
            0x1D18E8CE93228E77ULL, 0xE5F360E65B33DAE5ULL, 0x351F18DC1733594DULL, 0xBC5D4AE1E9B08731ULL, 
            0xA9B7D66406FFD9C0ULL, 0x1234261E510AC983ULL, 0x07199EA3B6DF8E62ULL, 0x166FAE261B9BC861ULL
        },
        {
            0x6E8C31AB7E2ED02AULL, 0x0A517215C9D7B686ULL, 0xB99C59B5D62AA9ABULL, 0x69F19A8558389049ULL, 
            0xD0157FF4505D9CBEULL, 0x380556A23A69B49BULL, 0xAF03D6A2D372F91BULL, 0x6A81C401CD9FD158ULL, 
            0x34D38675CF76244BULL, 0xB068AD8DC270C703ULL, 0x066134B1E760257EULL, 0xFB42BE500212A34DULL, 
            0x8961284D2D33C497ULL, 0xD5CA0A0F678C3DF3ULL, 0x97F4C97A618AFCF0ULL, 0x6E9AA4D4E8EDA623ULL, 
            0xFFBE7B118F0069DCULL, 0xB4F060047ADFCDDCULL, 0x766B311321EAA4CEULL, 0x6F91484A7CE7596AULL, 
            0x44347260C33C2045ULL, 0xB2E9602EAA5BD7B8ULL, 0x159B8B9928E8175CULL, 0x20B8E7B544FBF653ULL, 
            0x2195A2E8027F9BB5ULL, 0xF8FF34A1BCC3B1BBULL, 0xE85767C5B1437D1CULL, 0xF86BF6B33ED75DA1ULL, 
            0xBE5FEADD22985DC4ULL, 0xF4ED734F70D8FC40ULL, 0x85549A6D5DA987D9ULL, 0x7AE6CB8E25589E9BULL
        },
        {
            0x007C379D66BDE16BULL, 0x9635CB4A5F441162ULL, 0x73BAC37DFA15061DULL, 0x3D2C407DA867BF44ULL, 
            0xCAF99D134A278D8AULL, 0xDA6FF93994F5602DULL, 0xF993EA07464356F0ULL, 0xE380B6D974F09CE3ULL, 
            0x49460018B9D8C9C7ULL, 0x6F0CB07B592BF072ULL, 0x22252F16F2CF9CE6ULL, 0xD9D36AA752F00261ULL, 
            0x687EEB3865834461ULL, 0xE2DF54A7C6A5B535ULL, 0x49A65CE259345AF8ULL, 0x02A475384A3CF2EBULL, 
            0x70BD08DFA92B51A8ULL, 0x6DE2418A63EC63C0ULL, 0x5C42A0C39393040BULL, 0x1C9E2197DA8FCE3EULL, 
            0x1C6D8377EE782AB2ULL, 0xC9E4DADB0B94E234ULL, 0x76FC4919BCAE0185ULL, 0xBE9BAA362E76EA67ULL, 
            0xEAB61DB067704B64ULL, 0x8966AE7045B33A16ULL, 0x11177CABB9CAB1B7ULL, 0xC8E93308F2ACA2FEULL, 
            0xC83A3B8C7D8F470AULL, 0x597B13DC7C2B4F41ULL, 0xD3CA5B55D6A3E693ULL, 0x8B103DE07EDEE907ULL
        },
        {
            0xED3C1B98D4C745EFULL, 0x6387A2B8AC0A0D9AULL, 0xB5AB1425B184FE19ULL, 0x6EB082E2FDDA9B9EULL, 
            0xB28BA6C52D28D7FBULL, 0x95905CD045ADA031ULL, 0x4BF7163803AD0B37ULL, 0x22A15085FF190DDDULL, 
            0x006789B65A8DB8BDULL, 0xC4B0F7EE29CC6503ULL, 0xE23DC2A4B58A9044ULL, 0xF07B09C05266C428ULL, 
            0x1FF9BF617641E292ULL, 0x46E0A0C26DD50816ULL, 0x6693E38D5DADC663ULL, 0xC0A454F32481DE76ULL, 
            0x24C76B633F800B7BULL, 0x359BE40B0DF651CBULL, 0xA415F8E4CA3DBB9CULL, 0x3A21D7E076EFC813ULL, 
            0x927747CF300A8003ULL, 0x9B2283B88230CD59ULL, 0x792A3A8520CE3AFFULL, 0xF6FE9EC1E7A5ED62ULL, 
            0xD61AAE869A907BDAULL, 0xC72FF7C4B5A0EB7CULL, 0x43F673D7C3061986ULL, 0x29E4727AF06FA4DEULL, 
            0x51084CEB445C59FDULL, 0x9CDE69EDC30CEED6ULL, 0x86F4C243455C0F64ULL, 0xCBC4B66A57C62BF6ULL
        },
        {
            0x6AFB52550B709EFAULL, 0xE3C33700A5F5B856ULL, 0x8DC2087258136ABBULL, 0xDF6708051CC89A69ULL, 
            0x612F3063038858B7ULL, 0xC1777037054710E4ULL, 0xD65FC814662E3659ULL, 0xE3C90793340CE9C9ULL, 
            0x1AD8F942F7006164ULL, 0x726CD869E60B5274ULL, 0x5E51D8F69203776AULL, 0x157A4A6C3AA12F8DULL, 
            0x998ACC5809DE3D5EULL, 0x4AA56DB1DE65BBC2ULL, 0xEE9B4850AB39D47BULL, 0x8D2B0F677212FFDAULL, 
            0x1773C75A23621A30ULL, 0xCFB74B9481CF04A7ULL, 0x5E0DD31980F06C0BULL, 0x2AED6B110583BE3DULL, 
            0x7E8FE9C8361D9E15ULL, 0xA23CC770E209BBC5ULL, 0x77E555D9A040AA1AULL, 0xF8D017DCBD89F87AULL, 
            0x0FCD7E6395ED12CDULL, 0xE38D0E73FD0855E0ULL, 0x6ECF90CDDDAF7E13ULL, 0xFCAAD479305776B9ULL, 
            0x3DE721E3823806E7ULL, 0x9CDD53D1DECF53C1ULL, 0x1561A7905D748335ULL, 0xEBA24A3703161CE1ULL
        },
        {
            0xFB6E3AC4BB8D5AE5ULL, 0xBCD6A4A9942728F7ULL, 0xADFF6090369C547DULL, 0x665DCAA946A2D7B1ULL, 
            0xEF644917A13A6D5AULL, 0xCD0CFA7C43AF7C2CULL, 0xAA99541D3E95B976ULL, 0x33318C362CB6431EULL, 
            0x160925FD58CA8AD6ULL, 0xE346A5DA44BFA47CULL, 0x32D3670074609519ULL, 0x3A9AE4131DCB272FULL, 
            0x777F0A9A93193EAAULL, 0xE5FFABB6B24EA656ULL, 0x257E3B9A89E9E843ULL, 0x6669F8A3CA1F47A4ULL, 
            0x7A22C41DE557C6EFULL, 0xA0DDCDCDEE1904E9ULL, 0x3DEEBB3B464F80CEULL, 0x7A0D215F7D3FA2DFULL, 
            0xD54B983CE8153154ULL, 0xFE54CF6605724CFEULL, 0xB048D7DC525880C9ULL, 0x4ABFD4B0D77DC657ULL, 
            0xDB0230DEBF3E7DF1ULL, 0x6E47B1979CF23E18ULL, 0xF40A84090D24557DULL, 0x01BE309DE664F298ULL, 
            0xEB73B916B58EA6C0ULL, 0xA865A9C4433E519FULL, 0x87D8C6B1480C2566ULL, 0x335BF5C039549C98ULL
        }
    },
    {
        {
            0x72D95660DCAFF380ULL, 0x0BA9FEBB3B78DC2EULL, 0x013683A22DEA9B90ULL, 0x1AC3A41046B37C88ULL, 
            0xF7B19A92FFAF7B09ULL, 0x71BD7C545C52850EULL, 0x36AEE34E3E1DE90EULL, 0xB47FE517F12EE768ULL, 
            0x5C62FA28294CCDA7ULL, 0x7F88582DEB99ECD7ULL, 0x86EF34B09CDB76EDULL, 0xAB4FEDD78A2D03A5ULL, 
            0xCDDA4DDA773A61BEULL, 0x92A55144C0DFE030ULL, 0x75BB15CD722D1927ULL, 0xED4E575C5EF048BEULL, 
            0x146ECDEA344BD060ULL, 0xEF5CAB145F2FCCDBULL, 0x6E4D84815AC4B1A1ULL, 0x39A014097FAC7A32ULL, 
            0xB33C64E22406A5FCULL, 0x3BBF8DBE35EEA60FULL, 0x683ADA27576C5239ULL, 0x5D17AF0C5190FAAFULL, 
            0x58E1F14F74577DE4ULL, 0x7CEA36FFE7E1DB9FULL, 0x2333AA057E80C97CULL, 0x866EBE1FDB90EB73ULL, 
            0x4DA6E59C02198AD5ULL, 0x95702667A4DBB567ULL, 0x1B6684BA6B62C985ULL, 0x7EE07F575EE38790ULL
        },
        {
            0x384F03BFB44D0500ULL, 0xE4515B26D1354C1CULL, 0x48C99C7415F37621ULL, 0x40BC7FA1FB8A46A4ULL, 
            0x2D7C55D7190CEDF8ULL, 0xA11D3E2BFA0EE788ULL, 0x9A96B5D6CE42930CULL, 0xE78E4FA40637A99CULL, 
            0xFF22E1EBE6F13F28ULL, 0xC393182CC88CC8A5ULL, 0xE903A1EBF53BD578ULL, 0xBA7E8B48BE8E4017ULL, 
            0x23BEE91AA5C65697ULL, 0x8702C9AEAE2EC45DULL, 0x3F024B4F835192CDULL, 0xD57C97569FA6B94DULL, 
            0x1E1378E99A810EE3ULL, 0xCF45E8A9E2696625ULL, 0x3F4FE955B42D3E45ULL, 0x0FFB6D0C6525DABBULL, 
            0x10988729F6CD213CULL, 0x9963BA018AA3B104ULL, 0x21B8400F7F7A599CULL, 0xB29A65BF98654F39ULL, 
            0x1D85CBB341A83E2AULL, 0xA9C4C143A5166502ULL, 0xB25E2CA93975E321ULL, 0xFFB23BF94B7C9577ULL, 
            0x5757D4790C2E19BEULL, 0x52A37C839BD0BC63ULL, 0xAE79186E9EA1CA38ULL, 0xAD7011176B28DC07ULL
        },
        {
            0xF59D190477D2DCDFULL, 0x2EFA3397989C0E9FULL, 0x6522B5E32FE3DECFULL, 0x71D6DD1F1C52F8C1ULL, 
            0x96C4AEEFC8CF11FAULL, 0xE598EA735C7A5514ULL, 0xBE24F027AED5852AULL, 0x457FEA8EF196675EULL, 
            0xDB770BF1FA007C94ULL, 0xD26429080EAE183AULL, 0x1BBCF1CB9944F193ULL, 0x9F2E814ECF0BE004ULL, 
            0x7E31F4ADFEA1671FULL, 0xCB862D2707E20805ULL, 0x5125870414AEF7AFULL, 0xF1228E67C0AB5BA6ULL, 
            0x0FEC450D37383AB0ULL, 0xE5405D479C668106ULL, 0x82B0D01082ACC2BAULL, 0xC334B3FB2274439FULL, 
            0x972A258B82A7CDA8ULL, 0x4BE4DC743EC46366ULL, 0x3C189FAE806E2323ULL, 0x195BA4D48C6934CFULL, 
            0x0D88E9DCAA53AFB5ULL, 0x771EE98C56F12125ULL, 0x901EC27958EF05CBULL, 0xBC6C9C2AC285054BULL, 
            0x8E6F159E3CE62519ULL, 0xABEE34121256356EULL, 0xC2D50A0DB6073BAEULL, 0xDE9DBCA8F9FDE640ULL
        },
        {
            0x11FCD5019F76C805ULL, 0x62E33A2D4B48423EULL, 0xB8EB435ABF4680AFULL, 0x3FD60EEBF01F07C7ULL, 
            0xE8CCC12A6222840BULL, 0xBADFB57419325B9CULL, 0x91BCE056DC2AE3EBULL, 0x720EADADE9E27FC5ULL, 
            0xCD5B99B423AE5C2AULL, 0x13A24C69D0EC087FULL, 0x9BCE16D9D3840626ULL, 0x1772A4939D385AEAULL, 
            0x342CBB1B717DFFD3ULL, 0x2A30FFF5FDF111BAULL, 0x59DD54CD3ACEB27CULL, 0x0B0A00FC2A66B949ULL, 
            0x2804BA79AB7054E5ULL, 0xCD0C563BB2D7BF3DULL, 0xE78F23D049578077ULL, 0x57FF55C73194E7FAULL, 
            0x13A4F26E4608E11BULL, 0xD453108705583525ULL, 0x3BE1E2267BA56F31ULL, 0xCE3C33A2C52E42EFULL, 
            0x4282EF77935A0D9AULL, 0xD33AB647432F0DA0ULL, 0x0E5168B6862DE638ULL, 0x26F63A288565A8F8ULL, 
            0x1EE585D3CC866394ULL, 0x906E2195EA2A86C5ULL, 0x162FC23DF22640FFULL, 0x0FBE4657D9E56D75ULL
        },
        {
            0x16BF042E6C0CAD52ULL, 0x01FD1C003641DD16ULL, 0x83AD1E20AA5FBDC8ULL, 0x1E30897F84496AFBULL, 
            0x53E659F4F6466575ULL, 0xBDE288528E1DE61EULL, 0x47BF40373D8E500CULL, 0xBC2C18D9C8189643ULL, 
            0x96963C747A97C584ULL, 0xB0FD784B16D52E44ULL, 0x039DF149B0E59422ULL, 0xA0CBC6238B996F01ULL, 
            0xC6B92CCD1500D676ULL, 0x54FCEE58169B19FEULL, 0x76643386F607C075ULL, 0xA50B352C8B854092ULL, 
            0xB7962038233DA3EDULL, 0xD6C6BB1BF239B304ULL, 0x006ADBBF5F56FAB4ULL, 0x830C84B7BB6D4AF6ULL, 
            0xF890BF9ECF654A67ULL, 0xEEEA0337656BA79FULL, 0x09EB21D4521041FCULL, 0x8E474432630A8E62ULL, 
            0x7B04E5225587EAB7ULL, 0x26E024B0FA186620ULL, 0x3A54D4FC48C5090BULL, 0xA1D31E2662E9BBA4ULL, 
            0xC6D11854FD4795A4ULL, 0x78FBBFE80775C9CDULL, 0x205D9F7C167996CFULL, 0xD2C43CE98EC90804ULL
        },
        {
            0x70C464977B40B4AAULL, 0x43D92EAF9AD87933ULL, 0x876CAEF5F66244F8ULL, 0x14EF5280945C7BFBULL, 
            0x4B5AC86905EEBD5BULL, 0x28366EE58ADBCAEBULL, 0x801C71911CAB8136ULL, 0xB1A7CE0002379922ULL, 
            0xD9BEED167D0298BDULL, 0x3FF229240C01877AULL, 0x2EC2595292015BFBULL, 0xF8BD4684DC0C1C57ULL, 
            0x2C88066EE64787D1ULL, 0xF208DA1F55BB4FD5ULL, 0x7E7FA6673CA9EAF7ULL, 0x6A64E555C51A785BULL, 
            0x2606992B4BFFB579ULL, 0xF1A6C92932CEF662ULL, 0x0412C94A4D4C7F18ULL, 0xC20078083710BAC8ULL, 
            0x92F853F793FE359EULL, 0xCB5B3E7F39F644C4ULL, 0xD069A6226FE3B429ULL, 0xE6A830D8EB40F0A5ULL, 
            0xD67FC826C358D690ULL, 0x40C280E4DA6DB136ULL, 0x9C2B40A28D8D2BFDULL, 0x634445DC239E8799ULL, 
            0xCC39AE2BE35B76CAULL, 0x28A8055859A8CC05ULL, 0x5945671E7111A59BULL, 0xD70F5066AF742E6CULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseFConstants = {
    0x1CAEB70087CC0E3CULL,
    0x4FFCE64E179E4865ULL,
    0xCA408F2ADB773011ULL,
    0x1CAEB70087CC0E3CULL,
    0x4FFCE64E179E4865ULL,
    0xCA408F2ADB773011ULL,
    0xBE806BCA99993FD9ULL,
    0x6870E3CE4EB93133ULL,
    0xCE,
    0x18,
    0x3B,
    0xA1,
    0x65,
    0x6E,
    0x4F,
    0x16
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseGSalts = {
    {
        {
            0xC2F7AF5871D54FAEULL, 0xADF66FC62E72ED66ULL, 0x97B019C707336CACULL, 0x9BACA78D8190C696ULL, 
            0x04364CBB8D046B5CULL, 0xDA3643C2194A75F9ULL, 0x78791B2D4B9F153BULL, 0xBAC90B280D958016ULL, 
            0x8F21EC2D18F8EF34ULL, 0x306DBE9BEA4E10C3ULL, 0x1E4C5AB841901331ULL, 0x367B329DEF3CF7EEULL, 
            0xAF20343F641E7636ULL, 0xB0C2C6225E4C5760ULL, 0x2D3B550B73DB8D71ULL, 0xE4B68614D0C7798CULL, 
            0xB9FDD6E7A185C7B3ULL, 0xB74603CBBF67EF31ULL, 0x089724759CB69D74ULL, 0x8EDA382B84012A47ULL, 
            0xE038CE9E0B41CE6FULL, 0xA4EADDE96872CBADULL, 0x4FA62052456D085BULL, 0xF9FF437C2EA405DFULL, 
            0xB0CBAE20FFFD9E13ULL, 0x3F4942E05D1483E9ULL, 0x22B585EB8EF2F204ULL, 0xFE37F3C52623EDF9ULL, 
            0x92D7D504F1B53393ULL, 0x296AFE43EBC6CECAULL, 0x5A69835499148C9DULL, 0xEA453EB5BB5B4F90ULL
        },
        {
            0xD1E3752B6A1588D3ULL, 0x193F880B8D13E110ULL, 0x4E9EA300290D52D2ULL, 0x8263B9C4504025F6ULL, 
            0xD5737CBDAD795D7DULL, 0x40BF01A3AFA35C9AULL, 0xB77439D34E7EDBFAULL, 0xBEE3CD482AB53BA9ULL, 
            0xE04FF3841DF7FA52ULL, 0x99C976598A253F51ULL, 0x9FC21C8A8D44A182ULL, 0x885FFCC3A9ECA1C8ULL, 
            0x6EDBFDF56B5532F6ULL, 0x20A3B309B6EC3F3DULL, 0x4EC721E0321968AAULL, 0x3D7A1D15C2EC2738ULL, 
            0x44850CD259FADBC3ULL, 0xA52FFAD6F4905FD5ULL, 0xEF94C6208F77668DULL, 0xA27C074B71F2CF68ULL, 
            0x102C92DA71FFD9CBULL, 0xB64BE8D7C3B1829EULL, 0x74D058F32DD86777ULL, 0x3810565A355B5839ULL, 
            0x377E0DAA658A426DULL, 0x64F08735FA4A27E0ULL, 0x91A2E0E33A6F7591ULL, 0xFBA0C484B2B16752ULL, 
            0x073A09B147B86707ULL, 0x00829373040475F8ULL, 0x52A159797A501750ULL, 0x2EFF7AD3B645D660ULL
        },
        {
            0x73A5F28C7F3F9FB9ULL, 0x9078639DBAF41BC3ULL, 0x375B45CC21CA687BULL, 0xBC48627FE3207524ULL, 
            0xB0C07DA06C77BEE6ULL, 0x76EABD7E966F1C17ULL, 0x7B9340FBAF1422EAULL, 0xBC76B64C0CC98040ULL, 
            0x50B9634E763F8701ULL, 0x1566D97197860BE8ULL, 0x710D6178C31E7983ULL, 0xE557D46D905087B6ULL, 
            0x8ED2AB3064AE0F60ULL, 0xA06533862F10E10CULL, 0x5CC18CE895B017A0ULL, 0xD4C466AD175AD391ULL, 
            0xE57304EDE19570B4ULL, 0xF6663F116674D2BAULL, 0x53329818BE1DEE1DULL, 0x25CDC960310EB560ULL, 
            0x9E1E490F9B7EF450ULL, 0x74DECFED461337A0ULL, 0x4BFBBC948E755E69ULL, 0x160686B54CED668DULL, 
            0x64EDF3BCC85F839EULL, 0xB65179596E58C7B7ULL, 0x971056D82FEAFC83ULL, 0x4B9F2451B2547E64ULL, 
            0x945F4F10D6366260ULL, 0x1AC28F9CD49D9570ULL, 0x76E8491F102241EDULL, 0xF382DEB6FD828FA0ULL
        },
        {
            0x26D5A58F4FEDD158ULL, 0xCA7D9415B9082124ULL, 0xAA3FBC5FBCF22E9DULL, 0xC308DCA856C4494CULL, 
            0xE47E54634C2AE1CBULL, 0x7DE74C077E56FAB7ULL, 0x27A1179713FBAA48ULL, 0x241374651739873AULL, 
            0x361F0F5AAE8F687EULL, 0x662B52C07A1749A2ULL, 0x08633B99855E5DA2ULL, 0xC807F3E8837A3D4EULL, 
            0x7C53079F5CE89F2BULL, 0x592736AD1589DC4FULL, 0xD563D5A2F15DA098ULL, 0x5E0F560839A612CDULL, 
            0xB4D071762F212031ULL, 0x80937749F73CC523ULL, 0x14F0EB50E86B8862ULL, 0x92291E6EDC8D0F1BULL, 
            0x055E0F29E1651F6CULL, 0x3A8294102F08BD27ULL, 0x64D0C5CFD21EA188ULL, 0x046E381DBE792C66ULL, 
            0xC785185AE94E9847ULL, 0x2294378AD47E2524ULL, 0x530F0E71A3302B7EULL, 0x5D0BEC462A3EC1C3ULL, 
            0xC2880FA73DE43AAEULL, 0xE5952EB7AADECF17ULL, 0xB6271209AC7B9A0AULL, 0x5860D11884F276FAULL
        },
        {
            0x5EC8D02AD753DB3BULL, 0x57AB2FDBCC9B5BFDULL, 0xBAF512579B810938ULL, 0xA79A5E4E2EEEAF1EULL, 
            0x1C47D31B2D76958EULL, 0x76A67D6DAF49277FULL, 0xF7DC2B24A1A27F03ULL, 0x8EC2AFC2CEBF6801ULL, 
            0x408C6318309A9119ULL, 0x488E0B9B68195560ULL, 0x46B6F25DED52C742ULL, 0x08FEFBF5502D8CF3ULL, 
            0x727F3316ECF1EE0CULL, 0x6054911A65DF2BA2ULL, 0xBFDAA65667641A07ULL, 0x99AA550F3D207195ULL, 
            0x85C5418C0FE49605ULL, 0x8FD27493BF27051FULL, 0xCA3609F3A272C249ULL, 0x8468AA1FC6082428ULL, 
            0xE690A7EDD1B21A41ULL, 0x79C648DC02FA2554ULL, 0x67F1DCBE7F4D21E2ULL, 0xD937E6A836E67EDDULL, 
            0xD81A40FF5213206DULL, 0xA81F40C75AF227C7ULL, 0x44A9FFE9BC4A5965ULL, 0xE71F2C097C4571AAULL, 
            0x960C0098BB9960DFULL, 0xA39CB0400FAC8D7BULL, 0x7DF45027A3A19BABULL, 0x0738CF3C9A0BC685ULL
        },
        {
            0x692C795D8D37DED5ULL, 0x62BA72D5D8D994DFULL, 0x11C19036AF59A93BULL, 0xF4F66AE2385FBDB2ULL, 
            0xCC9F705ABA5EC62EULL, 0x1B67C0407C13B64DULL, 0xFCACFCAD2E934822ULL, 0x840126235E13F319ULL, 
            0xE58597D8A919B91CULL, 0x98EE618976A745EEULL, 0x8CB0C2810F95D67EULL, 0x8C0A7D69EAE8F9F6ULL, 
            0x5596C636212DF8B3ULL, 0xEDE0D1A72F91DDADULL, 0x8FAAC18E7B5EBABFULL, 0x54B546796FBAF13BULL, 
            0x3BF89BB50425182DULL, 0xBCA819D63F283BCCULL, 0xABA216095380B4B6ULL, 0x49708DEA114BD7A4ULL, 
            0xF590DB003EF241D6ULL, 0x03C7EEE786ABA1FEULL, 0x91EF33554D058086ULL, 0x29397300BB67D4E6ULL, 
            0x7919C40EFC2AAD2EULL, 0x854C0AFA7909BE72ULL, 0xCC3B3D806F0E593AULL, 0xE4EFC8474FF65767ULL, 
            0x7E26393A2DEF23AEULL, 0xAAB01143BC7F225EULL, 0x27B14C6FC4C1D0DFULL, 0x5E53ABE18906A52EULL
        }
    },
    {
        {
            0xF9BBB39416CB1B9EULL, 0xD48AFA6DA4D84A31ULL, 0x4EE4B409907850F4ULL, 0xC46CC7D257B7895AULL, 
            0xA7608C1BEEB9BB5EULL, 0xD11AD7AEE705C180ULL, 0xADF4519DFF3DC4FFULL, 0x947D819150AA2516ULL, 
            0x2B83F762B689D1CFULL, 0x67F18D1C2DE664DCULL, 0xE0BC5E252E9EE7BAULL, 0x2EA02147E53CA72CULL, 
            0x1D4B24402F3F71E8ULL, 0x3F571175376A074BULL, 0xC54453712AC0F7FDULL, 0xF2150CF673CDAF15ULL, 
            0x2C356C8FDE760813ULL, 0xC5639E7C4AB285CDULL, 0x4255D04606C2CA04ULL, 0x00815E1B0E1C407FULL, 
            0x03968281546A0DD7ULL, 0xB9B5AFC839E92434ULL, 0xDF17B17CC0C35BBAULL, 0xCE3E8178BAB00246ULL, 
            0x21E6AA5BCE6675DDULL, 0x0326C2FAB7C9ABB5ULL, 0xF2F616D5F1B8DB09ULL, 0x547E02386E402D91ULL, 
            0x5BD0FC8D8F23F32CULL, 0x20D4A0F23FD03437ULL, 0x7D722861EAA5BE81ULL, 0x39325B5CBF82D90AULL
        },
        {
            0x7AAE2476AE8AF5E7ULL, 0x3CF2E98A1A0D166BULL, 0x75113B6C0F26E4A2ULL, 0x614EEA6A833D9852ULL, 
            0x1F04B2BD7CEBA230ULL, 0xD670AB1FCDD47894ULL, 0xB7179CDED522853FULL, 0x165ED6F10C5565DBULL, 
            0x7E324E624DC447EAULL, 0xA49BE17FFB897CEBULL, 0xD2ADF4AA8B20C0A0ULL, 0x7A9E17AB706B0025ULL, 
            0x039092EAF07678D5ULL, 0xD568327FD1974E7AULL, 0x7AAFA93090D5D57AULL, 0x7C0C9291F675D373ULL, 
            0x1C3B29DFF85824BEULL, 0xBEC7573046176EC3ULL, 0xA6ACF2A655246F59ULL, 0xFEC205F806DA5D37ULL, 
            0xC923D27B4DBA5792ULL, 0xD0518C7555A70F73ULL, 0x2EEEEA1B1D687272ULL, 0x2B0C4AB6F9744EDEULL, 
            0x2140B72170E18862ULL, 0xF3861EDDC8AC0E78ULL, 0x1E222023693DB711ULL, 0x1BD0C55F40521AD7ULL, 
            0x72E272BC7A924E19ULL, 0xBCA23A96118D0B2AULL, 0xE9DD57DE91ADBD74ULL, 0xBE61F0A0392C56A5ULL
        },
        {
            0x543926AEE776EAACULL, 0x0E510183DDB517A7ULL, 0x7F307117CE9890C6ULL, 0xC3E80F8CB9A9DF8EULL, 
            0x176756B100D3F3E2ULL, 0x6F1C28820F45E0F4ULL, 0x7F4B2BAADF0EFA59ULL, 0xA7710C1AC7CF64C4ULL, 
            0x5011B888CC1F5F1EULL, 0x18DB6F209F1805C3ULL, 0x359EC6DA333EADCCULL, 0x313AE54BE763AFADULL, 
            0x0D0264F38240E925ULL, 0xC457E00535E44C8DULL, 0xA9E7CCC79A1540A7ULL, 0x3C0CEE412025E5D4ULL, 
            0xE6459CFF4F10A0D4ULL, 0x11609F3730E5489FULL, 0xE38BE18C24448FB0ULL, 0x63B2C09BB76D6812ULL, 
            0xBC7DDD9C277AAF46ULL, 0x12BA9E41E1C9D52AULL, 0xF568AC6DA8FBBF32ULL, 0x76382AF1E399473BULL, 
            0x5A33D2650084E23CULL, 0xCF7B08BC58BF70B0ULL, 0xF01C27A16B10DB5EULL, 0xC9D78437F5621907ULL, 
            0x356575F2934F4266ULL, 0xB0F833DE67CEC679ULL, 0x53B39683BBFC0892ULL, 0x3E4FDF832D731B5FULL
        },
        {
            0xB3D36D98695CC815ULL, 0xB86F6322E132142CULL, 0x0FFDE845BD816417ULL, 0x86C5C32335E1AB50ULL, 
            0x62E7D329E84E5CEFULL, 0xE6216D5D57367C15ULL, 0x90FA3CF472D232A3ULL, 0xC5BB7B6724DA786CULL, 
            0xD3FFCD0F15A6F3D9ULL, 0xBDDC2CA9F29B1CFDULL, 0x36956184B109B684ULL, 0x42AE9AE550BCB602ULL, 
            0x4047915CD54D4481ULL, 0x8D8FCAD7F30D3263ULL, 0x458026481A4FDE1DULL, 0x2FAEA5CD486588B6ULL, 
            0x145C622628DE5C48ULL, 0xE74F0FBFC49DA121ULL, 0xBFB403EA915A1F88ULL, 0xC0B0746B7C10AD9BULL, 
            0x1746A12816B3662DULL, 0x59E7F12540DB8749ULL, 0x8675969858881F6FULL, 0x8818CA5DCC467CCCULL, 
            0x63909552D62F1A9EULL, 0x7756E9D61F2708B1ULL, 0xE04C8E6882319FD0ULL, 0x10759391E82DDBC4ULL, 
            0x6238A0B43820FBC4ULL, 0x17F01F34E178450EULL, 0x4472BE088D0D7643ULL, 0x13A7C9638539A44DULL
        },
        {
            0x287E7104B0A09D72ULL, 0xF993727EC47CB1EFULL, 0x249FC985DAB9CB68ULL, 0x96182B6D89F2B6D7ULL, 
            0xFDCA953FD9DDCD2EULL, 0x48A889EBFDA136F5ULL, 0xE730C108D4A1B88FULL, 0xDC6A6A9E4CC7BB1DULL, 
            0xD5658A406542D591ULL, 0xEF0856E86BD165FAULL, 0x2C937807AF44B03AULL, 0x907C3EF3A0B03D65ULL, 
            0x2A60E80007BFE29BULL, 0x726CF3BBB2F6BBBDULL, 0xF2BE463861B2DAB3ULL, 0x36C97EFAE17E62B9ULL, 
            0x95AA2CA8542E6C93ULL, 0xB95C9D50EEF87AC9ULL, 0x8783811707B4BA97ULL, 0xE2E3EF63148DB6DAULL, 
            0x081D503B1A5C53AFULL, 0x48FE116003F69652ULL, 0x3B90F6C0EEC27E40ULL, 0x86D9BADEC4B464EFULL, 
            0xB713014828895A9BULL, 0x301478677EFCAD28ULL, 0xB37B9356741F00D0ULL, 0x56DFD6F6B62D240DULL, 
            0xB15D07F5D9D76475ULL, 0x38E25CAFA58299BEULL, 0x986332982455AE12ULL, 0xE05F2904F29CF84EULL
        },
        {
            0x900CA51DCDA9AD45ULL, 0xA144CC44001AB376ULL, 0x9755D58E634DACD5ULL, 0xF0D7D57279594265ULL, 
            0x884AC71206CE3842ULL, 0xBD215313FC364040ULL, 0xCD7DFD82C07F25C4ULL, 0xADCA5EFC3D45CAD6ULL, 
            0xDBE60E7274084EDFULL, 0xCCFDE219D1825B4EULL, 0x29D9F3BBE1472FC3ULL, 0x01A2D676B354F4B4ULL, 
            0x0D03602275F6FA2CULL, 0x11391F3FBBBDCD3FULL, 0x0DE30C34747F0D70ULL, 0x21F2B985CEBC02B5ULL, 
            0xB8FC83AA8EF0B1DFULL, 0xA86E1AE221CE45E2ULL, 0xF44E7F822D451574ULL, 0xCDF601F5EBEB049FULL, 
            0xD14FB16B42816FE0ULL, 0x41EC4251E6BF4255ULL, 0x5B41EFF45921DAB6ULL, 0xB30E2D7EA68A4D84ULL, 
            0xEBAE5C4010C83D7EULL, 0xC5405C758E4D9D47ULL, 0x27509D98B3E0861BULL, 0x92587C05DC242FA5ULL, 
            0x8DDA5FB096960BCAULL, 0xB980ECB7212FA7BBULL, 0x41D2A5CEEC92DBBAULL, 0x0F5350536E6898B4ULL
        }
    },
    {
        {
            0x8BE1B9BDB85824F8ULL, 0x546D22FD68F49ECAULL, 0x76AC0EF94980A7CEULL, 0xC1C3BBC00CD9BCEBULL, 
            0x4AA6537F928CCE66ULL, 0xFBCBC2CCCA29FE13ULL, 0x7718EF125BBA5482ULL, 0xF45695CADE7CB907ULL, 
            0x5C9845702ACC61B5ULL, 0x9024085816FE1D72ULL, 0x3F36037291F0A63AULL, 0x0C34FBC423417E68ULL, 
            0xD307A360CAEB7BB6ULL, 0x5F45AD3648B78C29ULL, 0x473FE2520EB532E5ULL, 0xADE4A508C24A0F33ULL, 
            0x5708FA6B544F8C80ULL, 0x460068B5CA5A61F5ULL, 0xFCB27A806373D89BULL, 0xEE3E1B857DA04321ULL, 
            0xE1CB9EBE337E8127ULL, 0x5752E06312A3A555ULL, 0x8E1F4EA04C52035BULL, 0x02EEA89ACD1DAC00ULL, 
            0x77E83FDDC7700242ULL, 0x2E69758797F2A04CULL, 0x6D2723AA0C93C347ULL, 0x76B925B5433435F5ULL, 
            0x5F1EAC5F327174F1ULL, 0x21E660F5389792AFULL, 0x4A7D20F23533CAA3ULL, 0x899707CA605D6F3AULL
        },
        {
            0xBE60A89B40D54617ULL, 0x726897F190D7612FULL, 0x2D75CD71F6752C9FULL, 0x66144A2FF8E0B553ULL, 
            0x6E16CD786387817EULL, 0x21B362F5DF284FBCULL, 0x92EE4440F1C8630AULL, 0x3623890C426961F1ULL, 
            0x82FA3BB2F0B79998ULL, 0x9B11CDF986749D72ULL, 0x723AD6915D6A1A17ULL, 0x78C23D0BE817B33DULL, 
            0x96ABEE5D84CBA6DFULL, 0x9860698B1DDE47A1ULL, 0xC8C0DB1B3F52B114ULL, 0xE7045A8D13B4C93BULL, 
            0x9CDC67933BE4F076ULL, 0x196ADE92011D5261ULL, 0x1E21945966A31CA9ULL, 0x66307C4C6D073916ULL, 
            0x0B7484747D14210BULL, 0xDEC988E4E36F2254ULL, 0x7F59E41A256747BCULL, 0x494C17158528B7D9ULL, 
            0x237B42205ABDC84DULL, 0xC57428547B415A5DULL, 0xA1CDAFFEFE8E998DULL, 0x903BB3D72BDB0C97ULL, 
            0xD2D60E087DB5EEF5ULL, 0xA17C65BE962E5350ULL, 0x1F06090F78DEA3A4ULL, 0x4C0DCE674AEF4227ULL
        },
        {
            0x27D0D09DCD3D3A7FULL, 0x365C37E9AC5C8C15ULL, 0x28C777E090DD308BULL, 0xD65A985BC80EB525ULL, 
            0xD635F1F96696B8A8ULL, 0xADFE2854ED935588ULL, 0xF55D06BE871C2757ULL, 0x0F907D0C1EBE71C9ULL, 
            0x1FED54E829E84886ULL, 0xBF0CFBD788B75075ULL, 0x611A4BF9354A2F47ULL, 0x4F2F21F99979FAD1ULL, 
            0x3D6BEE697E510C59ULL, 0x5B88D391CB7076F3ULL, 0x5EA9888F89A9BFE3ULL, 0x852CFA2B2878009EULL, 
            0x0342712C29F0608FULL, 0x0138E3CEACF9C819ULL, 0x2D84EF405BDD4B88ULL, 0xD6F832CEA1EBAEFDULL, 
            0x336F0F2F1F5653F6ULL, 0xF2C06C7DE6A606C1ULL, 0x58D1DA4B480318D1ULL, 0xB9E59770C7B0FA0CULL, 
            0xEC2A80A6304C89CDULL, 0xB67D6B51F818A9A9ULL, 0xD0214FC677B3AEF4ULL, 0xD904CA3557388151ULL, 
            0x762128B699C7B681ULL, 0x8B02FE7EE6CB82D2ULL, 0x0127E954CE53D54DULL, 0xE612F1F8E38CFC83ULL
        },
        {
            0xC2F31B9EB3878D34ULL, 0xB70A1D514EA5F13DULL, 0xAAE25574667D4E9EULL, 0xF58AD6709C32CC27ULL, 
            0x53A5568CB01DADD9ULL, 0xF93E5F73FF105D71ULL, 0x2EB21D749FE142F0ULL, 0x65C54854DBD2DBA3ULL, 
            0x514137E27EFE5CA8ULL, 0xCB3D2C781CC824C3ULL, 0xE41127483F1CDA3EULL, 0x567935E49BB7A35BULL, 
            0xB8AFAA0650105695ULL, 0xE6D85A298146682EULL, 0x3904F1CEBA8C56FFULL, 0xF1C66E3435287E27ULL, 
            0x939A4DCBA04FD016ULL, 0xE24451B0A6C4C967ULL, 0xF53BD24C495FE664ULL, 0x04CAC6122913229BULL, 
            0x0695D04A3339A583ULL, 0xCBE7E4CF26C99F51ULL, 0x82611854F6F3AA5EULL, 0xF1965F968D58A95AULL, 
            0x5C0ADCBB69320E11ULL, 0xEAE10637EB1A118CULL, 0x4D16FF96A1EECC61ULL, 0x42E6BC4C3B36B3BDULL, 
            0xD6B76DC458860D25ULL, 0xAF4B60A544F63748ULL, 0x99C11C1C1B658942ULL, 0xF681FA3C4B9C7AC7ULL
        },
        {
            0x30F27AD3E755A572ULL, 0x676DD0A0220E92CBULL, 0xFEDF92AC6CF6171FULL, 0xC238EFAEF33694F2ULL, 
            0xF08D5D6F2206B0E8ULL, 0x42B2AD4DC904BA29ULL, 0xFA6F181A8D43FDACULL, 0x96147F0A38ED0F95ULL, 
            0xAA1794717D18E93EULL, 0x77687F4F0E9F46CDULL, 0x85545C10576AE1B7ULL, 0xC02B577DA667C18EULL, 
            0x5603CEEC4B020A02ULL, 0x10F8577AB85C5BBDULL, 0x94BB4CD56C611390ULL, 0x0703A2B75A585AEBULL, 
            0xE4E1D1629007731BULL, 0x8625FFE66DEF4E88ULL, 0x27F482BC5DF22571ULL, 0x7C43184C80372218ULL, 
            0xAA31CD859772B1E7ULL, 0xCE1AD9B13F387FB2ULL, 0x74DADF3C7039FD90ULL, 0xAD32B0E356CBB76EULL, 
            0xE950B61888310D2EULL, 0x59C9B3A87A0CF618ULL, 0x57B17A0C2F997CD3ULL, 0x8F7CBC1F0AB95E11ULL, 
            0x065369D118365E4AULL, 0xFA73035E193293D7ULL, 0x316253236672399AULL, 0x3651F6257D4325ABULL
        },
        {
            0x1649F7DD70E6A452ULL, 0x79F64A6973CA057BULL, 0xA09D0AE0095B30A9ULL, 0xA2AFF22556C92347ULL, 
            0x0D14257B519F1DC3ULL, 0x6D48C95A6E5C68BDULL, 0x81F1B0803738235FULL, 0xD3D90AF1A441A3AAULL, 
            0x473A3326C6DF8F66ULL, 0x1D8307E86A29B2E4ULL, 0xCADFDB1F0D8FA4A8ULL, 0x054F3C50CBADA4D6ULL, 
            0x819E9C2231E357F7ULL, 0xFBAD6040329D408DULL, 0x7A4526EA9E3D47CCULL, 0xC7E1375BF45FA1FEULL, 
            0x635C7F1E5653B4FFULL, 0x28829C1B054AC059ULL, 0xB5C3A30427245184ULL, 0x464FE3B7F9EAAE06ULL, 
            0x9949C64577E3A826ULL, 0x6B5CECDC9EF2B80FULL, 0x80DB7CCE7A046D69ULL, 0xA8F49E591EEBA77BULL, 
            0xCBEC3DB9962E9132ULL, 0x43667C881B109776ULL, 0xD760E03454D0239AULL, 0x634D61599B97571FULL, 
            0x75AC039C04763801ULL, 0x076A38C0B9980FD0ULL, 0x296E9F8F1BB8757BULL, 0xE32F6FF4BDFE1585ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseGConstants = {
    0xFA40013F501824D6ULL,
    0xC874537CCF111BD2ULL,
    0x05C2A25A51767482ULL,
    0xFA40013F501824D6ULL,
    0xC874537CCF111BD2ULL,
    0x05C2A25A51767482ULL,
    0xED66488D04DBC3FBULL,
    0x4FB4D17B89DF779FULL,
    0xEE,
    0x1F,
    0x0A,
    0x23,
    0x5C,
    0x58,
    0xB7,
    0xE8
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseHSalts = {
    {
        {
            0x047752C5E1785D15ULL, 0xFEA052E53E7ADAE3ULL, 0xB20D1F783197DEF0ULL, 0x7DC591B6F5EA6331ULL, 
            0xBA115FFDED034BB1ULL, 0x228919BC9AF8737DULL, 0x29DB1701C7CDFF3FULL, 0xE4599A4664232D25ULL, 
            0xB11D124CF2E96201ULL, 0x0D5950E8389AAE64ULL, 0x0CE1566F06CD74D6ULL, 0x2FE0B273ED141B52ULL, 
            0x95596A93B150F1A7ULL, 0xCD790381556AEAADULL, 0xE61D98AF15892600ULL, 0x4D4808FEB319FA47ULL, 
            0xBAA30DBCDFC6C2ECULL, 0xFB923C9A81C7FD98ULL, 0x1CBFEB51FF34DE25ULL, 0x301BE5572CD328E3ULL, 
            0x1E00A4E08DC19D52ULL, 0xC71923A898D82031ULL, 0x61AABF1390F8ECD7ULL, 0xF82567CB4D4A70F7ULL, 
            0xAA0C0BE8A01912C1ULL, 0x4612A6E663DBBAA4ULL, 0x95CC9FEC10E97856ULL, 0x9CE6FE36DF0026C4ULL, 
            0x521E22D1DE126B03ULL, 0x6C881F7998583DA8ULL, 0xA91EBE3B1391A22AULL, 0x79C3E105C8AE738EULL
        },
        {
            0xA5B679B6534303A2ULL, 0xFFA1DD11107479A1ULL, 0x18AC32057E50268EULL, 0x9B648E22CA7CFE58ULL, 
            0x2D22BD13631B60C5ULL, 0x285DD8853F1F1C50ULL, 0xB61A6D71FBF73416ULL, 0xD3E814340D5E7B34ULL, 
            0x7707F47EE2B792B2ULL, 0x92A013BF2A35946CULL, 0x26A400BC5A7C7453ULL, 0x93DD0F10C6F3B731ULL, 
            0x622ACD4B677C907FULL, 0x144497A6AB2920C6ULL, 0xF306D834B4B6AF98ULL, 0x29B7B3C1A0057D8CULL, 
            0x8CFAE6C63D3D1072ULL, 0xE8BCF5A821C3CB15ULL, 0x8E35AA75FC7C74A1ULL, 0x60FC389AA3D93D8CULL, 
            0xE16894D27F17AED9ULL, 0x2058682B18DB11DCULL, 0xF195497DCE6A8846ULL, 0x17F28C31F13AFDA3ULL, 
            0xCCB967BDBEF5DD5DULL, 0xE0C9C90ED86D2DE0ULL, 0xAF50D2CC6CA97192ULL, 0x0122D58F373D2102ULL, 
            0xCBBEB1734B4494AFULL, 0x11D8097957E348F7ULL, 0x44C2955966C9AA5DULL, 0x27062ADADA6B656CULL
        },
        {
            0xB2B7713C553E1508ULL, 0x6706264AF3D8DC54ULL, 0xB5B34DC1ACE14016ULL, 0x8DB9A64485BB6BA2ULL, 
            0x3255C5F672E12980ULL, 0x22A36AB8D74259E6ULL, 0xE3EC3F03DF7693D1ULL, 0x398B2D35D4653DC6ULL, 
            0x9DCCA2D45C0D07BAULL, 0xFD80EEC36EE1CE33ULL, 0x2E37BD3724200C43ULL, 0x9AE69B7615914962ULL, 
            0x4038969CF4220795ULL, 0x1A678375AB3ED976ULL, 0xC90E49FCDCEF1063ULL, 0x6018ED643EE98B93ULL, 
            0x035D0252ED82B497ULL, 0xE1509DBF97249182ULL, 0x53076A16AA41B626ULL, 0x4CF96D77FD0A75F9ULL, 
            0x2643EA1FE598DA2AULL, 0x61AD0918E4DEB120ULL, 0x8F7EA0F1A4121974ULL, 0xA45C384BB27573D8ULL, 
            0x933F038FD25A213CULL, 0x582941340E63BB6FULL, 0x74A4BBA57E3C07EAULL, 0xF10017F466F284C9ULL, 
            0x9EF670BAF055E347ULL, 0xAE33D2CF2E8B77FEULL, 0xA5E37D329EB9A701ULL, 0x0C53052CDC56F494ULL
        },
        {
            0x935A7F2862D1FFCBULL, 0x9E82EEA6520ABE3EULL, 0x4D57AAF98D2D36F0ULL, 0xA534E34FEBC5FE10ULL, 
            0x55EF37C4AF309A5EULL, 0xE0FF034A907DEBACULL, 0x5F5AEA8D9FAD9B68ULL, 0x918634125264D9D4ULL, 
            0x465F081A7799C13DULL, 0xA22769C97DAABD57ULL, 0xEE601E4AE6920388ULL, 0x342059271496B50DULL, 
            0x52BD8CEBB34F63F5ULL, 0x2423FD2A5109B25BULL, 0xDF49C21192E689D8ULL, 0xA07E656607F36BA9ULL, 
            0xBF101F3AE623FDA2ULL, 0xD2CE03412D844BE3ULL, 0xD0BA733FD2D9A485ULL, 0x2BD15473690C9670ULL, 
            0x1963A59A15AC93D4ULL, 0xC2D7E1D1345EE0F8ULL, 0x6E5F6F05B0C1E9B0ULL, 0x3693E614A0346F2EULL, 
            0x14A2252D57C4DA1AULL, 0x7D1D7B04ECED4C12ULL, 0xAC243A401A375442ULL, 0x85397ABEEDAF27C5ULL, 
            0x2A2958055CA71A43ULL, 0xBB1C5B4F39D4F67DULL, 0xFECB0A9A0BCDDC2DULL, 0x6DB6A6CEA8C0AA49ULL
        },
        {
            0xE2374A8A011B64D1ULL, 0x919ED8D1078BE51DULL, 0xAD089501FF2F637AULL, 0x5E56573A5EDFC55EULL, 
            0xACE86C69331AEBEAULL, 0x8779E5D326B118E4ULL, 0x8FD34D64F9C61894ULL, 0x9936172B37988A90ULL, 
            0xF1CA1FD53441D88BULL, 0x5BEB1E0A2F44A2C9ULL, 0x3D089D39C3D17489ULL, 0x7CA4E338C6AC582BULL, 
            0xC16C8C1D420917B3ULL, 0x2F1F3D4956F5B823ULL, 0xFFC7C7C3F8C39AA7ULL, 0x9F3FBD2268ED4256ULL, 
            0x7E0EBDECB1034113ULL, 0xD0CF03F9C024E8E6ULL, 0x1812CEF6BC5BE411ULL, 0x39CDE6D59B0E6303ULL, 
            0x19D729ED56E2FB1EULL, 0x4BC2D79D6A82E516ULL, 0x5E7B21FF581CF1FDULL, 0x7AC76CBC48E39302ULL, 
            0x8256454D88D8DEE5ULL, 0x3AD8EA09418B9252ULL, 0xEC8B770CA7DDEFAAULL, 0x198BC517942714FEULL, 
            0xB48F47B960F49C00ULL, 0x86CB5221D55433C6ULL, 0x0E04EF06852E52E3ULL, 0xF7EDE2660655B0C4ULL
        },
        {
            0x79FD23B6DA8430AAULL, 0x196276C2817F29E7ULL, 0xCE2F07F8A532DCA3ULL, 0xE86BDCED1AB96B59ULL, 
            0x4CF05233E4E367BAULL, 0xFE4979C8D6639C1FULL, 0x666AF2242DC72D37ULL, 0x9B95493FE91E736CULL, 
            0x36D4D4D6005D858DULL, 0x085834B0D738297DULL, 0x6676CE5DF0452AD6ULL, 0x7BE2BBD7E5A7DD3BULL, 
            0x7053008E32995B86ULL, 0xF0A7A2962B5AEB8DULL, 0xA527BAE3F68512A0ULL, 0xBA843A34FEDD3FC6ULL, 
            0x2C1D3A387936C211ULL, 0xDF8E76AE3DF6EC0AULL, 0x9300B53F4F68E314ULL, 0x74319E2EA20FA227ULL, 
            0x0A09EB07E16CD4E7ULL, 0xCF317947082A3E01ULL, 0x452D501FB03B5A81ULL, 0x695CE121DD16D6F4ULL, 
            0xD4063A9B6502A549ULL, 0x091D0818C56FF9F6ULL, 0x11A0A11608CD116BULL, 0x22792AD11E27AB59ULL, 
            0x9754504D418B7499ULL, 0x5B151CB09327AE2CULL, 0xC5A7C49AD248D6A7ULL, 0xD1458B521410BBBEULL
        }
    },
    {
        {
            0x289643E27485DA9AULL, 0x80E6A9DEADDE4690ULL, 0xCD77B2D4E420D3CAULL, 0xB3F3C4D502725B21ULL, 
            0xEB0B5E5434EDDD3BULL, 0x4FAAE05A23026744ULL, 0x397A6644A7612486ULL, 0x5DD847C39E797D4BULL, 
            0xC14F1FC8EDFE00D9ULL, 0x15E9CF9CE8E6BAA1ULL, 0x10A38698512D5212ULL, 0xA6EBFC8B5E7FE563ULL, 
            0xA115012A947C74C9ULL, 0x7CD6D12A36CB4F89ULL, 0x4C67688907D7D083ULL, 0x6EFF9A164F2D8DF6ULL, 
            0xC6B24FAEAC5D5D4AULL, 0xEC2E7B541583FB06ULL, 0x10237C34DC2100D2ULL, 0x1EC618C8A30B4FE3ULL, 
            0xE31DB7986E9F429CULL, 0x5A2600FE492CFB70ULL, 0x013715B0B0F1BAC5ULL, 0x707BD93FC6720642ULL, 
            0xF95F8D08D767C38AULL, 0xEF60D8C770380AA7ULL, 0xFBD0AD1AAD7A6A5CULL, 0x83D0A6721F3A13CBULL, 
            0x71D48F163BE1A631ULL, 0x27D448739A095CF1ULL, 0xDBC5C2AC5C94F68AULL, 0x6C8C455442DBA32DULL
        },
        {
            0xD83C23DB30C24C31ULL, 0xF831DFBA5CA354F9ULL, 0xBB6611042B8A7EACULL, 0xF9F9EEC9F481CF1AULL, 
            0xB9E093FE3EAAF9ECULL, 0x67FD394CF5E9A15DULL, 0x920C90FFFBC20C6EULL, 0x4E526B4136BC1D55ULL, 
            0xA8EA92B7FE339C4AULL, 0x34D4D24D8018B521ULL, 0xE6059ABED55D1659ULL, 0xF45EC0A3BB78441AULL, 
            0xDFA62E167C8AD967ULL, 0x8E0B0FE4B5513C05ULL, 0xF3BE211E55B8ECC1ULL, 0xD1CF4E24E3F2483BULL, 
            0x8D8D28FFF481D080ULL, 0xF14158DCF879B779ULL, 0xBF8021A5F49D227DULL, 0x998A873124BAD0EEULL, 
            0xF54347BC42126115ULL, 0xFDC5C56780C13D93ULL, 0x71C7288AE913EF12ULL, 0x99ED5ACD7485970BULL, 
            0x3B00FCC6026B2ABFULL, 0x61B03A1FC2231261ULL, 0x2D882517B85BF29CULL, 0xD254609C66B63D2FULL, 
            0x92669579E27EDA37ULL, 0x4A87E9BA883FC276ULL, 0x6183CE9F73A66AB9ULL, 0x36BE8AD8EEFD7870ULL
        },
        {
            0xF67BB5D0AFE8B6B6ULL, 0x7FE6B26C704B2C57ULL, 0x01F430FF8067007BULL, 0xDFD6C36DD9A163E5ULL, 
            0x63C8F20D069EDE78ULL, 0xDAF64D74BCB4AD8AULL, 0x8781C46C7DD5B5D1ULL, 0xC66A06061EFF8326ULL, 
            0x9EA566680B68A02DULL, 0xE93ED69CB9EB1BF6ULL, 0x3B52D2FE27B6D900ULL, 0x02753D6F59C3FE75ULL, 
            0xEDA9D9B7F19CF10BULL, 0x2CDA940AF4FD8F44ULL, 0xA1CE2FF8D256ED55ULL, 0x6DF73D6C1BE18405ULL, 
            0xF08D85A73CF207BCULL, 0x8F5E9E8D6ECA0BE6ULL, 0xCA29C927A0C49BCBULL, 0xB7076BA021E6995AULL, 
            0xF266E723FA26F482ULL, 0xB9202467254CEF29ULL, 0xBD9007BCB73DB99FULL, 0x61BA4AE499C31252ULL, 
            0x666F32565BB8C8CBULL, 0x856AB006D851A1D4ULL, 0x0C8F3004E3F5C2ABULL, 0xA777F7CE2CA2888EULL, 
            0xE3BDC485471372B2ULL, 0x75EBD3F2B0C01057ULL, 0x9A441238D7EB1BE4ULL, 0x9D6FA5C13418802CULL
        },
        {
            0x5CCB771AA67DAFE7ULL, 0xCE2D7728FBC5BC00ULL, 0x34906742F4056A35ULL, 0x516D736FB079C42DULL, 
            0xD7DA1597B3A88E83ULL, 0x45DC932AC55C6BDCULL, 0x555BD3E2F7CAC922ULL, 0x4367CC8B450CEF5AULL, 
            0xC8D62E1771F403C6ULL, 0xFD7606FA648D15C9ULL, 0x49CE1BDC4E54E566ULL, 0xDCB197B7FBB07EF0ULL, 
            0x5AFD61794FD3EDB2ULL, 0x64A862EF67B6B108ULL, 0x139CE12C7E2CD40AULL, 0x1333E243C5B5F738ULL, 
            0xBC1432BB2B3A8685ULL, 0xBE756D2FEA70AEEDULL, 0xFFD2FE602EB14BA4ULL, 0x4CAD70E37175B432ULL, 
            0xC8F70930089C9DA9ULL, 0xBC6522203F4351B0ULL, 0x91CC0B4A044CA119ULL, 0x29DA6A73B98A43BEULL, 
            0x4262952F3656DA8DULL, 0x67EA6A6FAD621461ULL, 0xB9C730DFB3BAE9B9ULL, 0xCB28C1FC983B6A57ULL, 
            0xBB4E4587D5639170ULL, 0x366CF3397D8929F8ULL, 0x9AA30B687F70CCA3ULL, 0x25F4A28BBE2E79AAULL
        },
        {
            0xF0E81C36EF2BC778ULL, 0x63BD18F051F5C4B6ULL, 0x1DE11BB130153D8CULL, 0x7BDADCDD2C3A73D5ULL, 
            0x7E9DF1769BBB1E0FULL, 0x3B65F752299C18BCULL, 0xE9C7F5B88428F4FAULL, 0x57E9DC54A8231F61ULL, 
            0x6C44AEB03BBF83FDULL, 0x8A04FB514AF811DEULL, 0x774339D3B42DF53DULL, 0xB918AFC822FE552DULL, 
            0x8114B37048FF1525ULL, 0x2C52708D187C5B7FULL, 0xE94024DE551106A1ULL, 0xF3756B7802C0AFC7ULL, 
            0xBBDC13D1774D8BA3ULL, 0xAD3D74B363C31DCFULL, 0x6939FF5A79460E7BULL, 0xEE4F50241D02F352ULL, 
            0x24BBBAE71E214C37ULL, 0xE1395BA64EE61DFAULL, 0xCCDB3F4910F7844CULL, 0xCED190F6BA155B19ULL, 
            0x4E4843097FA20707ULL, 0xD2080625EE683416ULL, 0x4EF332978AD0AF4FULL, 0xE45712226F686344ULL, 
            0xE608C58714BC37B4ULL, 0xF3C0A177F3FC0A09ULL, 0x20E5AFBC2A0735FEULL, 0xCED36C96A6F027FFULL
        },
        {
            0x023881DC9FCFAD4CULL, 0x54B4AB906E9D7111ULL, 0x75916B743EEF1364ULL, 0xE29C136EEEF4E914ULL, 
            0xA8712F38A65B9EC2ULL, 0xF7F1DC0A674C23F8ULL, 0x43C75E9624AEAFE5ULL, 0x67EFB900E08534B7ULL, 
            0x3FC8EE43E2498067ULL, 0x05728A1E4BC3D98AULL, 0x22227C6F4B9C8601ULL, 0x72936A6E640C0343ULL, 
            0x5508CB281E0B2CB3ULL, 0x11E6381BCD8F49D4ULL, 0xF942D720C92628FAULL, 0x0AFED310F7D5129CULL, 
            0x9C309426E41C915FULL, 0xCC40E53FE87F2051ULL, 0xD88D98467CDD0C34ULL, 0xC6961C4AC5D00BF0ULL, 
            0xF145EAC69C9727C3ULL, 0x5B06113C1769F1B7ULL, 0x5DD04FE345B0B1E6ULL, 0x4A510873B5FB570DULL, 
            0x9995F5D841083EA2ULL, 0xA967BC43246515A0ULL, 0x96D34D33BE98ACB4ULL, 0x5702FDD8EB36BD77ULL, 
            0x909E5128CD0EE413ULL, 0xC15553D69CE1EC7CULL, 0x37EE14A7D720BA86ULL, 0xA504109D73C6E879ULL
        }
    },
    {
        {
            0x3B82B10D88010EFAULL, 0x8146571A72F4E260ULL, 0x894D1F1CB717761FULL, 0x2B951B9C81E11A25ULL, 
            0x3C2B1770740CF44AULL, 0x4D73E99482E20813ULL, 0xE4019BB66840D127ULL, 0xB3696A15F5EB11FAULL, 
            0x4D325F2C78F5AF82ULL, 0x971EBFCFA50A1158ULL, 0xDEB48766EF14EBBCULL, 0xD1971077816BF565ULL, 
            0xC6992DA5E144E14DULL, 0x5CEC468A16ED277FULL, 0x0E36B04FA7206D9FULL, 0x9D7A110894B5E0DCULL, 
            0x150F3F1E0DA890F6ULL, 0x5F489C8CE912433EULL, 0xD39CEB0F64B84F2CULL, 0xE6DB4D5A9D5FBDA8ULL, 
            0x8DC218E24C7F698AULL, 0xCDCCA485AAC3D842ULL, 0x97FC4CB5A3D26C20ULL, 0x040381F825B690B6ULL, 
            0xCA2F7648DAE2C09FULL, 0xDE348FEFC961F973ULL, 0x5F30D7B887C0A031ULL, 0xAB964F130860E5CAULL, 
            0xF0A50022DB1322E8ULL, 0xBEC77642BAFA672AULL, 0x5D887F6EBE8A0653ULL, 0x13C3065D0EEF9EF9ULL
        },
        {
            0x3DF3339042F0E5D1ULL, 0xBE3FC092E0E1DDA1ULL, 0x214FC53D20EC0ADAULL, 0xE3B8A769EF23B691ULL, 
            0xDD0F534A0A295E6CULL, 0xA5C33EBCB04A42F2ULL, 0x092D1D5C272A945BULL, 0xDF4BBA7F5ED35368ULL, 
            0x246453310B69BAFDULL, 0xEFE64D6A99223A19ULL, 0xC19EB9A169BD995DULL, 0x213C9068FCE11C92ULL, 
            0xAC1A8888A32B717EULL, 0x63FD794D3F4C18CBULL, 0x678D3A54761516F0ULL, 0x49468BB3A5E5ABEFULL, 
            0xC4E20FF4EA766B5FULL, 0x23F013AB46DE99A7ULL, 0x75BA1F2900AD2360ULL, 0x6A27492B5131FDE5ULL, 
            0x8DAB82881C626A41ULL, 0x42E13891599A8B8CULL, 0xB22B20A939D520DAULL, 0x92166E0C92EDA709ULL, 
            0x2909AC655F2CFD27ULL, 0xCE3BF0225983E3B5ULL, 0x8F6104F7E02361C9ULL, 0x067C10F79C81BFCEULL, 
            0x44365391760B2CC9ULL, 0x70F45CF0012CE313ULL, 0xA7D701B58D225EA0ULL, 0x0FF4A8BB5602BF7FULL
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
            0x14B7BC51BCFFC9EBULL, 0x32EEA279D377F3DEULL, 0x01F7289109ED86CAULL, 0x03D6B530ABCAD02CULL, 
            0xC18EFCDF9DF1BDADULL, 0xB6C4D1821FE6E18EULL, 0xBAE56B1B4BB0A48CULL, 0x02506D7C4FD5CB63ULL, 
            0x7EE66C6B011DFCC5ULL, 0xE1FFE51E56CF9CE3ULL, 0x239B12D44B938311ULL, 0x44BF6F0B78C79619ULL, 
            0x1E9245228457126DULL, 0xE223DCFB4BEE42CBULL, 0xDE39467E9EEC89D1ULL, 0x5CC6273843E0422BULL, 
            0x0234E4D99E63E125ULL, 0xB8DC42EF3E79C204ULL, 0xE6ED679829794960ULL, 0x3B09BE72122A9C2BULL, 
            0x8D6C49BDBDB9F907ULL, 0xC16A189F081E9FACULL, 0x72A532517998D2C2ULL, 0xB780FC664E5627FEULL, 
            0x7FF6D8C2E3C8853BULL, 0x74921F4FFB69BAB8ULL, 0x8458CE0786EA178DULL, 0x41F11CCABEBD9263ULL, 
            0x0654F9157F2E2C80ULL, 0x9946E3F113C064E1ULL, 0xF635F39F8E243DC4ULL, 0x6D82384D78C82E2BULL
        },
        {
            0xCF0BACA2AAE7F97DULL, 0xD824639EF25AD303ULL, 0x1FEF156D43EC47D4ULL, 0x47EEDD395C76782AULL, 
            0xBF477F43F82B7CDDULL, 0xEB9CBF06CF4AE3BAULL, 0x8EDB93A279DC543FULL, 0x2F6B54DCF0B23519ULL, 
            0x5C290B5F83BA3E14ULL, 0x22AA5AEED07965A8ULL, 0x0376DFAF7679C472ULL, 0x8D396379FA6BF1E4ULL, 
            0xA6CCFAAA15CAD4DCULL, 0xD93876FC40BF5EB2ULL, 0xCFC0D72ED9188B2EULL, 0xB8559F1B0CD6EBFAULL, 
            0x900FA1DFFEA9FC80ULL, 0xCB97EBCCF326AD7EULL, 0x19F512D38012C80CULL, 0x9294694CCF819F04ULL, 
            0xB59DDCB8200AD4C6ULL, 0x0AB8EB6D735549C7ULL, 0xA9E87351B77E3813ULL, 0x9FDCBE5FAAAFAE01ULL, 
            0xFD22820909BDD4B6ULL, 0x85EC9D59D14233F1ULL, 0x3D22FC79B996488CULL, 0x28EFCFD7993B329EULL, 
            0x0173AF793ABE4F8CULL, 0xE2A657696C27B125ULL, 0xF23789B36F1B2D84ULL, 0x97D986CD2520D423ULL
        },
        {
            0x0D8379B630B76C82ULL, 0x81BC5E0160D5B946ULL, 0xDDC9DDC174690A91ULL, 0xE5F493528E86613EULL, 
            0xD4CA3D55D5B28666ULL, 0x0FE2346CB3BE9501ULL, 0x78D0380A94CB585FULL, 0x644E0F0998C182D7ULL, 
            0x331A92C09C79504EULL, 0x648CBC783466C3A3ULL, 0x50FA7D319DB71862ULL, 0xB7397BD31DB8AF8DULL, 
            0x6313DBF431D07552ULL, 0x42DA26D4EDF1F4E9ULL, 0x1DFD31D12BBB8C61ULL, 0x3A95C5CF5EEA58C0ULL, 
            0xFD8CD76FD9B2193FULL, 0xEE1EF47F89F95C7FULL, 0xA36F2F149E9FA170ULL, 0x0F11E47C691C3431ULL, 
            0x0C2B0AC73AD9E69CULL, 0xA1C9EEA38CE04EFAULL, 0xD6A5268A455E0596ULL, 0x513711E13A087761ULL, 
            0xB77BE31EA4D34932ULL, 0x49FFC6CB08DD01C7ULL, 0x2F3F97711D16E5E0ULL, 0xC69E02F38C46670AULL, 
            0x59BD130E63BA7922ULL, 0xDACB58CA1750AFFAULL, 0xD09691A1D502D825ULL, 0x3C16FC468D9BF1A5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseHConstants = {
    0x9FEA38BC56C112CAULL,
    0xD75E7C4356B58F84ULL,
    0x73CD478353E98D1DULL,
    0x9FEA38BC56C112CAULL,
    0xD75E7C4356B58F84ULL,
    0x73CD478353E98D1DULL,
    0xDA90745BAF5CC6B2ULL,
    0xF7C32C2FC1396035ULL,
    0x31,
    0xF3,
    0xA1,
    0xC3,
    0x86,
    0x5E,
    0x87,
    0xFB
};

