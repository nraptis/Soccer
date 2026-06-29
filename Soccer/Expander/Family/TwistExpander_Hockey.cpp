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
    std::memcpy(&mDomainBundleEphemeral, &mDomainBundleInbuilt, sizeof(mDomainBundleEphemeral));
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
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xA9AB4849ABC897E7ULL; std::uint64_t aIngress = 0xA03656FC5CF41943ULL; std::uint64_t aCarry = 0x8BD60A9AB9F21DFAULL;

    std::uint64_t aWandererA = 0x8139BBCF208C7C84ULL; std::uint64_t aWandererB = 0xF4E231E7FDC63841ULL; std::uint64_t aWandererC = 0xF45E209509573E1BULL; std::uint64_t aWandererD = 0xED2E29640FD671C3ULL;
    std::uint64_t aWandererE = 0x84E53EF929699FAEULL; std::uint64_t aWandererF = 0xDA30FD68CE59508AULL; std::uint64_t aWandererG = 0xD8A9D1800919FE98ULL; std::uint64_t aWandererH = 0xC54741E477862DC9ULL;
    std::uint64_t aWandererI = 0x80D7C6751EA4DA03ULL; std::uint64_t aWandererJ = 0xF6EDE8C5F94FB8B1ULL; std::uint64_t aWandererK = 0xEE90621F1E450307ULL;

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
        aPrevious = 18414756742840684012U;
        aCarry = 15022853739273795520U;
        aWandererA = 14544186946228038643U;
        aWandererB = 18430363722278705953U;
        aWandererC = 15568185902994716903U;
        aWandererD = 9491525764261417371U;
        aWandererE = 17666437139157760214U;
        aWandererF = 10205904124149674505U;
        aWandererG = 16292394901252773462U;
        aWandererH = 14752656940362638753U;
        aWandererI = 14456255117745832726U;
        aWandererJ = 10106418311215189855U;
        aWandererK = 11496548518297221701U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: work_a, work_b, fire_a, fire_b, fire_c, fire_d
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
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

    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
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
    // KDF_A_D kdf_a_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
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

}

void TwistExpander_Hockey::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
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
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x8858E69663C1E0AEULL; std::uint64_t aIngress = 0xAEB100D957BBB605ULL; std::uint64_t aCarry = 0xBD7CC8D7546DC165ULL;

    std::uint64_t aWandererA = 0xCAF78180860110F8ULL; std::uint64_t aWandererB = 0xD7F1DE5CA0B04749ULL; std::uint64_t aWandererC = 0xFC389E57E8103412ULL; std::uint64_t aWandererD = 0xBADC6544D313060AULL;
    std::uint64_t aWandererE = 0xE5AB60A3A5D2C74AULL; std::uint64_t aWandererF = 0xD7331A010FD6168BULL; std::uint64_t aWandererG = 0xA6B79D657FAA6365ULL; std::uint64_t aWandererH = 0xFAD2B242C1769AC3ULL;
    std::uint64_t aWandererI = 0xD2F6597CD091C10AULL; std::uint64_t aWandererJ = 0x9325D4940F99C1D4ULL; std::uint64_t aWandererK = 0x9C0D6A9320B8221CULL;

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
        aPrevious = 11340662995186359878U;
        aCarry = 13162227688930035101U;
        aWandererA = 13086099555755218240U;
        aWandererB = 18037135623237687410U;
        aWandererC = 17282248770500763285U;
        aWandererD = 15063706441803008218U;
        aWandererE = 14713669670677580905U;
        aWandererF = 17191950684132272976U;
        aWandererG = 16475414372023560800U;
        aWandererH = 10430166801669782988U;
        aWandererI = 9487168394118178378U;
        aWandererJ = 17088086845849044084U;
        aWandererK = 12865712966002127583U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0x8B2D279BD48466A7ULL;
    std::uint64_t aIngress = 0xC789E23C0346C29EULL;
    std::uint64_t aCarry = 0xCE3BB76628590F53ULL;

    std::uint64_t aWandererA = 0xE35116DC43D876C4ULL;
    std::uint64_t aWandererB = 0xBF707DC3B9874547ULL;
    std::uint64_t aWandererC = 0xC9FB48BE6F8378C5ULL;
    std::uint64_t aWandererD = 0xD8DECBE3BB2C9316ULL;
    std::uint64_t aWandererE = 0x934509251696AA18ULL;
    std::uint64_t aWandererF = 0x8CC4456767EAE037ULL;
    std::uint64_t aWandererG = 0xA01E6D9BAA689365ULL;
    std::uint64_t aWandererH = 0xF115AF96F371B98AULL;
    std::uint64_t aWandererI = 0x82EEDD5EA17136DDULL;
    std::uint64_t aWandererJ = 0xBF66A14AE544C47EULL;
    std::uint64_t aWandererK = 0xA168E0673CED063FULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, operation_a, operation_b, operation_c, operation_d
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
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
    // GSeedRunSeed_D seed_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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

    //
    // ---------------------------------------------------
    // GSeedRunSeed_E seed_loop_e:
    // ---------------------------------------------------
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // GSeedRunSeed_F seed_loop_f:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aSnowLaneA, aSnowLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
                         aSnowLaneC, aSnowLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_h:
    // ---------------------------------------------------
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
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

        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
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
    std::uint64_t aPrevious = 0x8A190B1BD0D17DF3ULL; std::uint64_t aIngress = 0x9E4F15C203BD7244ULL; std::uint64_t aCarry = 0x8F830F17465A1CB7ULL;

    std::uint64_t aWandererA = 0xB07ECCD6660C2199ULL; std::uint64_t aWandererB = 0x90FFDE7F039249E1ULL; std::uint64_t aWandererC = 0x8CD6282F5BEB87EAULL; std::uint64_t aWandererD = 0xE63CA51BE8E97B55ULL;
    std::uint64_t aWandererE = 0xCE747F8A26CABE68ULL; std::uint64_t aWandererF = 0xFA10F2D10C6C8389ULL; std::uint64_t aWandererG = 0xA673615792EF80B1ULL; std::uint64_t aWandererH = 0x8CD7C36F65CA705AULL;
    std::uint64_t aWandererI = 0xE9ADF4551F2F83CFULL; std::uint64_t aWandererJ = 0x83BA384F5F43531EULL; std::uint64_t aWandererK = 0xDC57E662B41B70BAULL;

    // [seed]
    {
        aPrevious = 18222174494267494643U;
        aCarry = 11794372913155888338U;
        aWandererA = 14687429974000129559U;
        aWandererB = 10529892251351163698U;
        aWandererC = 17912583037905946648U;
        aWandererD = 12349571518979214979U;
        aWandererE = 18206230012773483201U;
        aWandererF = 9632312242393743386U;
        aWandererG = 12855984468567954617U;
        aWandererH = 15661420296422250998U;
        aWandererI = 12538678710366373178U;
        aWandererJ = 14504356191093986850U;
        aWandererK = 15353488179544733644U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        //
        // ---------------------------------------------------
        // GROW_A grow_key_a:
        // ---------------------------------------------------
        // read from: work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        // write to: expand_a, expand_b, expand_c, expand_d
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
        // ---------------------------------------------------
        // write to: work_a, work_b, work_c, work_d
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);

    // [grow key a]
    // GKeyFoldA grow_key_a_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldA expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 2318U, 6378U, 5833U, 2204U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2318U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6378U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5833U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2204U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 2 with offsets 6976U, 7165U, 5265U, 1368U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6976U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7165U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5265U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1368U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 0, 3 with offsets 6373U, 8097U, 1548U, 2512U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6373U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8097U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1548U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2512U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 2, 1 with offsets 6845U, 6990U, 2701U, 3452U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6845U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6990U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2701U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3452U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 with offsets 1542U, 1712U, 928U, 1574U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1542U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1712U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 928U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1574U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 3, 0 with offsets 482U, 1461U, 352U, 236U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 482U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1461U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 352U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 236U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 708U, 1899U, 918U, 1481U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 708U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1899U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 918U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1481U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 2, 1 with offsets 1027U, 1819U, 460U, 719U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1027U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1819U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 460U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 719U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 801U, 1998U, 993U, 1451U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 801U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1998U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 993U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1451U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Hockey::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);

    // [grow key b]
    // GKeyFoldB grow_key_b_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldB expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 1 with offsets 6104U, 6016U, 5808U, 6444U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6104U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6016U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5808U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6444U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 0 with offsets 3658U, 729U, 3563U, 4578U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3658U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 729U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3563U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4578U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 2 with offsets 962U, 849U, 7943U, 2912U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 962U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 849U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7943U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2912U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 3 with offsets 6282U, 3333U, 1900U, 6310U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6282U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3333U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1900U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6310U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1464U, 1733U, 4109U, 6647U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1464U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1733U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4109U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6647U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1384U, 458U, 1504U, 157U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1384U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 458U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1504U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 157U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1106U, 2026U, 1579U, 554U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2026U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 554U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1022U, 549U, 1801U, 1301U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1022U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 549U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1801U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1301U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 364U, 906U, 493U, 1284U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 364U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 906U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 493U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1284U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 0, 2 [0..<W_KEY]
        // offsets: 808U, 994U, 1556U, 322U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 808U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 322U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseASalts = {
    {
        {
            0x65508DD3480A73FBULL, 0xA246FD63B7A4943BULL, 0x91F595FEB73BD904ULL, 0x1FB75E7059BB62F7ULL, 
            0x8FBEE563CF4BDB50ULL, 0xB64E8E87E8ED56A6ULL, 0xF5C83B3C59432ED7ULL, 0xCD429EC82AA91E8CULL, 
            0xF9C313277C6ED696ULL, 0x959C20FAC685CB96ULL, 0x1E6658EFEB939925ULL, 0x925C80C0FC1506A4ULL, 
            0x9E688840DD0C6E10ULL, 0x30EB96D6F4AE29B4ULL, 0xC26ED5DE6BEF777CULL, 0xB04CC2C2A2464A07ULL, 
            0x523C1DF5422E73EDULL, 0x73459B871F94F63AULL, 0x19A0BB0B9DBBB009ULL, 0x72495EA1E00B3B71ULL, 
            0x048B2745CAC077BAULL, 0x1A3AE0726B66C7D1ULL, 0xA2CBDDBD01C64A8BULL, 0x04ADDBD17CA777F1ULL, 
            0xE69BC451E3B8F401ULL, 0x765CAA1A5AF16181ULL, 0x7E2499FB359680BBULL, 0xF21AB3A44B4393E0ULL, 
            0x949FD8376CD1596DULL, 0xEA3881D3C2A0395EULL, 0x241D5968678D7520ULL, 0x5ED3B611B0F3A0D1ULL
        },
        {
            0xE6E68F138217E847ULL, 0xF7DF925EC7173A29ULL, 0x4C96A7772C4CD41AULL, 0x170A0E22480EDFCCULL, 
            0x6BB3E571AC886C0FULL, 0x4CEB4E809B41A2AEULL, 0xE4DC7CC892068294ULL, 0xB7C6061E440DACC0ULL, 
            0xD7041A9D450454E8ULL, 0xC70CCFEEEB2BC93CULL, 0x3E54E71AE5D8FAB5ULL, 0xB2C679E80310FDF0ULL, 
            0x0398D5E80A6BBB99ULL, 0xE702C7009B2D1A38ULL, 0x718A4EED41E33DD2ULL, 0xD1CC8BBC3BE427F0ULL, 
            0x015E0DBF668129C1ULL, 0xA37E5879835B7DC9ULL, 0x4DF4CEEA5C2C6F89ULL, 0xF307DF5311AC15AEULL, 
            0x4214A796DF03CCAEULL, 0x51FC40143846C2C7ULL, 0x6AD2973B09636511ULL, 0xE6F1E83927021C2FULL, 
            0xCBE52E7D50A682C6ULL, 0x5274A29EB11F545DULL, 0xA8939176B2FBD670ULL, 0xE67F63890FB1A62DULL, 
            0x67346AFB76C08C36ULL, 0x4620E57B04069F0FULL, 0x6C48C393293C3A14ULL, 0xC3397EC01B81BE6BULL
        },
        {
            0xF7EFB180AD9FA1BDULL, 0x3FCFAC6712E1B1C4ULL, 0xEA9A06D7E40FF034ULL, 0xAC5FA4B443BC29A9ULL, 
            0xAC2814876F98774DULL, 0x20DB49775CFC91CBULL, 0x389141FF9887DA5EULL, 0xD86C668BE376D7CAULL, 
            0x2F3A5151C777379AULL, 0x43C162E4EC9E3E2CULL, 0x34FD2786D980617FULL, 0xB067CBC3B2E36D12ULL, 
            0x432C2DBBB580640CULL, 0x0D3C2A1026C6DD8CULL, 0x52E396117690FD6EULL, 0x5578D32E94B2D602ULL, 
            0xB2735B0E6B2DC2F0ULL, 0x4956F3AA00BDB599ULL, 0x02DC239F2CD59CE2ULL, 0x9C91DBB7D32CAC00ULL, 
            0xEF579105CECDA273ULL, 0xD05EEDE7D2B2EFDDULL, 0x1A91F7A604AC66DDULL, 0xECAE0AAE7834FCF3ULL, 
            0xBA6DA59BB3FB5F76ULL, 0xCA247C028B53A2C5ULL, 0x2E89284576B0E0ECULL, 0x6FED3C2BC335DF82ULL, 
            0xCC2216454B62EF06ULL, 0xD22D6E295F0B5C36ULL, 0xC94F0B6673217FE6ULL, 0x8A384810D9E34FD4ULL
        },
        {
            0x051901B1B3D135EDULL, 0xA77C9D4C5706F824ULL, 0x1DB60163CB57FDE6ULL, 0x2E328F941567163DULL, 
            0x691924879EEB3CA1ULL, 0xC832239F07B02166ULL, 0xCD63ABC91A5B22C2ULL, 0x8AC4E7D40CC9A5B2ULL, 
            0x22F2151C59DA92DFULL, 0xBD7F0320C852F896ULL, 0xE5F20267A370CA0BULL, 0x60458D4DA25D6C4CULL, 
            0xCCA6663F492FF56EULL, 0xA3DC36DA786165D4ULL, 0x05713EB04C0F1BBDULL, 0x9DDE5DEC14675A0BULL, 
            0x3FDDB110F5CED802ULL, 0xA7ACC8108A5D2E4EULL, 0x498A21C741FE2FA1ULL, 0x3B7B838BAECD70CEULL, 
            0x2B1C40A55035D910ULL, 0x760A287363BFA857ULL, 0xAC2DDD76600CE22BULL, 0x6DCB931D30F35DFAULL, 
            0x2AE9A7120ACC23D4ULL, 0x1CF036B882CE3F10ULL, 0x598CFB1DBBE51DE7ULL, 0x4C0BA46016598E56ULL, 
            0xB36C7B7058DACFD5ULL, 0x690EED44843E6FD2ULL, 0xFCAF8C0E0C6ABD1FULL, 0x484AF69396C9A7E5ULL
        },
        {
            0x20D6A86B9B8FDF1DULL, 0x0202FB56640A0E69ULL, 0x9208EF21A1F56C2AULL, 0x75FD116D0CC0F96CULL, 
            0x9A8C82B82E63AC23ULL, 0x1E73CC1F335089A5ULL, 0xEF7DA1104E4B6E54ULL, 0x73BCFE05B1C262F4ULL, 
            0xE2B32E1783280B6CULL, 0x754AFCF81B16CA12ULL, 0x1717DDD577FD2693ULL, 0xBB12E8C7052A0442ULL, 
            0x709A75A30070AB5EULL, 0x39939161A1A689BDULL, 0xC88D3711C4A5DEBCULL, 0x5708B1B9569BE0B8ULL, 
            0x4ECAC336726FABC7ULL, 0xB9A7FABC8407D875ULL, 0xE3FA421FF49A62F9ULL, 0x09C878BE28D99CBAULL, 
            0x7C8EC31BA7113085ULL, 0xD7D23A8D31C90D38ULL, 0x16DCA61D2EBC6172ULL, 0x3DB86AB5FCBADDA5ULL, 
            0xD208B174FFB59A55ULL, 0xF534FC134F06C6C0ULL, 0xEA93F33B3B0FBD44ULL, 0xC368C0114B514295ULL, 
            0x2E09B5CEB1C70A9CULL, 0xB9678AA895BA488AULL, 0xA6E18126E31048A6ULL, 0xB07D0CF2DB632C21ULL
        },
        {
            0x7D581B21FBF41A58ULL, 0x6234BE352BFEE8BFULL, 0x2B5EB59BBB197F7FULL, 0x5902E75CF5504C11ULL, 
            0x9F7E96108385C911ULL, 0x6FB79A88901B8E52ULL, 0xC7182F58872F9CC3ULL, 0x7908B37A8000A68CULL, 
            0xF591D8256644FE0FULL, 0xCE6217DA7E22F928ULL, 0xC4C2A9552574950BULL, 0x35FADC7D8714A830ULL, 
            0x0D5A69A2878B3902ULL, 0x8DE25FFE84A99652ULL, 0x73D8F6BDF98A3815ULL, 0x4BFA67BAF9588B21ULL, 
            0xA3A5298E036EAE2DULL, 0x2735A50963AE300AULL, 0xB97FD584E8FB94B0ULL, 0x503B34C149A2191AULL, 
            0x479106B339B8BC79ULL, 0xBBFFB83C53C0E4F5ULL, 0xD64DDA481DC166FCULL, 0x68703CC461B8D47DULL, 
            0xB94D7EB13249BA77ULL, 0xC8BA2C561C492F0CULL, 0x07584DFF647129BDULL, 0xD46A26018D3D3CDEULL, 
            0x646A897188028AB2ULL, 0x0073703131D8C1DDULL, 0x174354CDA8EF7A3CULL, 0x5514760FC6D1FC63ULL
        }
    },
    {
        {
            0xCEE9C90D8D14120FULL, 0xBA6689A7FCF74A18ULL, 0xEB7186973F86BEB2ULL, 0x54787194805ADB34ULL, 
            0xB8C469D580B32124ULL, 0x54842F9772344CC7ULL, 0x67DFFC1ED0C82306ULL, 0xD22211F0345429B2ULL, 
            0xD4BD04F841DD6E80ULL, 0x3000C0073C35F562ULL, 0xB6C6CEC0A4B56D24ULL, 0xDF4E9B26A4200E87ULL, 
            0x0686F49BF42E8377ULL, 0xC5EB4174DA5BD61DULL, 0x1E405539D7F81444ULL, 0x6905C6B3306BB78CULL, 
            0x63CD02F95A00A7E5ULL, 0x04851A0086ACFD0BULL, 0xA9D9FD467ACB8D84ULL, 0xA88BC826FA1DA83CULL, 
            0x2D8233173C0DBC9AULL, 0xB650DDBCD6FD7D7EULL, 0x694B6E213ABEE858ULL, 0x59F174F4153F38B6ULL, 
            0xE6D5DA25D4C832F8ULL, 0x735CB8895E8D357EULL, 0xE7F9934A0A018BAAULL, 0xE94E78E036E1FF71ULL, 
            0x476999076EE916B9ULL, 0x8F94D9BF02782234ULL, 0xB99B5B1D02672EF3ULL, 0xB2965E29B93223BCULL
        },
        {
            0x5EDD6BD1BE2B4FF4ULL, 0x93C76724F2BF11C1ULL, 0x4DA09EE3974F7611ULL, 0xDADA86574B58D3C9ULL, 
            0x65EF6504F42A69C0ULL, 0x81D366CCC3AB9FFDULL, 0x083BB3ADECCCEEE3ULL, 0x779A53E1A8A2CF90ULL, 
            0x824331E2ADC56AB1ULL, 0x9358735C8C1A5352ULL, 0xDD207697710BB205ULL, 0x9321A61FB68DD005ULL, 
            0xBB6FAB100DA5DDAFULL, 0x6A9DE2B2EB6C0297ULL, 0x3667EE55229774B0ULL, 0xA221EE2955D0C91FULL, 
            0xF4A8835EAC5DE600ULL, 0xA44F0A2EB98D3985ULL, 0xBCE235E7AD20D9A2ULL, 0xEBAD1E4E1950A6A3ULL, 
            0x718EF184163FA25FULL, 0x722EFC464F99962BULL, 0xFFF98502DFDD5895ULL, 0x76A3B7FBFCA58264ULL, 
            0xF98660FA7B93CE25ULL, 0x1B11B5A8DD920191ULL, 0xAE2C3D547A73802AULL, 0x8DB9E08789341003ULL, 
            0x62C0A90923561697ULL, 0x23E92F9DED8B74FAULL, 0xE757D0C5ACDBDD1EULL, 0xE2F50E1AD962C99DULL
        },
        {
            0x27F9765843AFD426ULL, 0x6BDB6A6B61C98523ULL, 0xAF77002C106965F2ULL, 0x7DBFA727E4109145ULL, 
            0x09C3FAE417B424A9ULL, 0xE651A76F8B69C397ULL, 0x737C7E468B4E7A8AULL, 0xA5F0255AF4174B29ULL, 
            0x7F87E8836C71C375ULL, 0xBDDFF5118196F612ULL, 0xFCBC16134B1B3626ULL, 0x8FED31C2A73290DFULL, 
            0x2E7D11A9101A4D76ULL, 0x7FC67E8A57D6BE3EULL, 0x2DEA71CD409FC453ULL, 0xCE4211D5D8B75BC2ULL, 
            0xD77F784DD374CEA3ULL, 0xBFDDF589F0326A5CULL, 0xF2B32B788B791681ULL, 0x7D61D756D510C6A8ULL, 
            0xCCA2A2F48DE2B458ULL, 0x3826701CC7269D50ULL, 0x7708811598386CFAULL, 0x0A95A602C39CB3A6ULL, 
            0x44108FE419E1A3C2ULL, 0x9C352741E50950D2ULL, 0xAD62A27A346CB6C4ULL, 0x389A5E558ACB9402ULL, 
            0xC902C5BFBB3A663AULL, 0x93C50924E09ACA71ULL, 0x97DB8A10EA2CA08DULL, 0x3A505DF1B285877EULL
        },
        {
            0x6FBD367E33FAA580ULL, 0x4361CE8E62668ED6ULL, 0x714E4CB359A027E0ULL, 0xB60CFE5062EFD0DEULL, 
            0x74D4969C1586FB05ULL, 0x5214C1B9D0A7AECBULL, 0x3F045F22CFC9F113ULL, 0x7AD2293C195A74D8ULL, 
            0x71EABA7E91F32A5DULL, 0xE5666D18CFFECE0AULL, 0xA912C41A8EB6D9B2ULL, 0xF256888B56F4710CULL, 
            0x6F8374AB0D609D7AULL, 0x857645FBD63D83E5ULL, 0xA3A9F0B0EB1562EBULL, 0x275DA3893F909928ULL, 
            0x08C054824A6E239AULL, 0x3E259DA967D27691ULL, 0x1C2652F8DA5DFEA9ULL, 0xA9AAA00D4E9E26CEULL, 
            0xA83E9E65A081AE52ULL, 0x54B7D4405479521DULL, 0x38EA29361F2A2974ULL, 0xE3AC5797870CE31DULL, 
            0x39F6756E64A351E7ULL, 0xD71B62B1CAD37495ULL, 0x681F911909BE0086ULL, 0x46D54D1BC78D1CAFULL, 
            0xF62F6735629FEE4AULL, 0x1D34D6E77DC1AF2CULL, 0x5D817D74E7C2ED9FULL, 0xC3FEAEF8E658019AULL
        },
        {
            0xA8C9BD28CC22E2D0ULL, 0x2957A9DCF4F9E016ULL, 0xAD41C2F3EBA31B28ULL, 0xAAE1037504CCD339ULL, 
            0xB5CA6C862B01B67DULL, 0xF21B924E9967C1ADULL, 0x87269E9EDCE46E9EULL, 0x64C14A93090FFB05ULL, 
            0xE3D51A418DB9289BULL, 0x056B91C269CA2425ULL, 0xE1152D4A7E358ADDULL, 0x7FE9DD3F44DE8C49ULL, 
            0x6D5F7DAD075590B7ULL, 0x81AB3E78D61A4B9BULL, 0x54273F89A86D2444ULL, 0x56E3C1F7BE809CF0ULL, 
            0x9C32A293C768FD9CULL, 0x7C91CF20904B6B3EULL, 0xE7EAA05527C96150ULL, 0x6E493E8D20187F2CULL, 
            0x984988D7377ABFFEULL, 0xF69307BCDA666701ULL, 0x1159FBE9B4CDCDFEULL, 0x37FCB1740B32AA24ULL, 
            0x57CED86FF4DC0C68ULL, 0xDBF903E5B02C9473ULL, 0xE61CAFE480A4F96BULL, 0xDB5835E063F5FB4FULL, 
            0xCB212BB407630464ULL, 0x11032D0ABF7A1FB5ULL, 0xA30E6B699E082FC6ULL, 0x43EB146C1EEC8DD2ULL
        },
        {
            0xCCA1D1E16D40DEDCULL, 0xAB1FBEB091A84B2FULL, 0x119B2A0EE38DFA73ULL, 0x71BE30CF4089C6A3ULL, 
            0xCDD865ADB5B09BAAULL, 0xC34D8E72086EF494ULL, 0x36D167D46487B9A4ULL, 0x0D9683D4DDBC0F62ULL, 
            0x0BFF1A239739067DULL, 0x9C8E03110D97BF6DULL, 0xE6F1B50EC0F80F1FULL, 0x6672AE7AD8761298ULL, 
            0xD63CBBDCBF325F39ULL, 0x05CE79AC07150BFFULL, 0xEEC0251A0124C145ULL, 0xC5769193B832A2E4ULL, 
            0x6C0BB0C828602610ULL, 0x1DEC4224EAD7A5A3ULL, 0x38E617A377EB66C3ULL, 0x731D8C1E6356B7C2ULL, 
            0xB450950CE837BDA5ULL, 0xC4B9BF1ADF5424E3ULL, 0xE7D79BA01279CC84ULL, 0x53AB4023CCB61BF3ULL, 
            0xAA800E84CD51980DULL, 0x3429C39017A6FFC8ULL, 0x79E2B5ADCF3A3CABULL, 0xEECFB7C169F97C66ULL, 
            0xF398770F74C7114FULL, 0x74A8ACD3F2CA380BULL, 0xD560B9D106AE007AULL, 0xA248AAFE5B2A883DULL
        }
    },
    {
        {
            0x5291576347CBF0F7ULL, 0xCF813C982AE71992ULL, 0xE201349569562A7FULL, 0xC2F12F2B063472E9ULL, 
            0x5D95F63326946301ULL, 0x2760022BC1209E5EULL, 0x7DF1C8F789E54DCBULL, 0xADCBFE4CA7457050ULL, 
            0x1CB8C4C109A128C1ULL, 0x8CD48807F893816FULL, 0xF915BE1AFE7EAE8EULL, 0xE2911000E04868C1ULL, 
            0x895FA38D3280B621ULL, 0xF603F365CCFD413FULL, 0xD0CCA6EBFDF97F55ULL, 0xD3DCCDABEAD337DAULL, 
            0xCDD8504D2B89BBF3ULL, 0x19F700D3B3C5B91CULL, 0x55E1F2B4B3FD87C4ULL, 0x094D197F4FF06AEEULL, 
            0xF26FB382D3BB2252ULL, 0x25E6BD18B4736D3BULL, 0xBE24DD97CAEAFBFFULL, 0xEC8369A94FA5CCFEULL, 
            0xA81409F6BE8C091BULL, 0xF9C6FF3C9F2A9F45ULL, 0xF3DA69C28B243634ULL, 0xB834FEA34FFBA886ULL, 
            0xFC596626AB2DBF22ULL, 0x1889AFA9F329BC4FULL, 0x2B67AB5325EBCB7AULL, 0x8E8BC4B5006FB68CULL
        },
        {
            0x6D4430BF1B5179D1ULL, 0xA814600D1858E330ULL, 0x5A5596557799A170ULL, 0xA8CD962D25B547BBULL, 
            0xDC24B903B6EDD5EDULL, 0xA944304A6118F91FULL, 0x026142B3C949EF49ULL, 0x5CD940189D7E6A11ULL, 
            0x039529DB6D9DF45FULL, 0x5ED8F6F1C78DC7F7ULL, 0xBCCA268D87CA5E2CULL, 0xFA885774CAFFA4B6ULL, 
            0x43B82FC9998E73AAULL, 0xB8F2C26A33FB6D94ULL, 0xEF0C0216A924EDADULL, 0xB62F927954A160B6ULL, 
            0x0A6737BF77F8C44CULL, 0xA2B9AF0219139750ULL, 0x463B55F82591FABBULL, 0x6124D8CD00021EB8ULL, 
            0xB02EEF46DBB9C733ULL, 0xCDEA020D71F90CBFULL, 0xC14DFAA4C28FA523ULL, 0xEE8DF1EC99C0DD95ULL, 
            0xFC578B33E283092DULL, 0x6B3B0F6CA5458723ULL, 0x3FCB1A69DA28B55DULL, 0x66FF6DD5ED4BA259ULL, 
            0x2942367B370A7FB6ULL, 0x13E925540205E9ABULL, 0x136C88F1A2C19547ULL, 0xE3277E11CD0172BAULL
        },
        {
            0x8A4C24C3D38D4EEEULL, 0xAF18ADE2C0D085A3ULL, 0x1315754621F02C59ULL, 0x351FD083C0F7787AULL, 
            0x2A98A0258050860BULL, 0xE870926FEB565897ULL, 0xF17980E04FA85E54ULL, 0x5E61C064629D21C5ULL, 
            0xA5BBEB02DD8EF0E1ULL, 0x98DF15D7BDF3D6B3ULL, 0x849562B51783EA6CULL, 0x0EC25966AF3FEB3AULL, 
            0x0BD36D37207B9A76ULL, 0x125091BC21EC7431ULL, 0x7263DA16DFE89AC4ULL, 0x3C86DADB7AFBF6D8ULL, 
            0xE4827B79488972ACULL, 0xDAE2A85445CA4ED0ULL, 0xB22AF97919C37A4FULL, 0x1ADE21D0654C32BBULL, 
            0x06B5E493B2EA2A66ULL, 0x96F5CC3F96B208FFULL, 0xB3FCDDDEE40087BDULL, 0xDCB399CC26BD227DULL, 
            0xA04B9139AB8B8CD3ULL, 0xFDA3773FF06CC14DULL, 0x962AE133F2E71E73ULL, 0x9D855BA54694CBA8ULL, 
            0xEC12C377CF618381ULL, 0xC68C1EC1EE4B17C1ULL, 0xA3B132A1CFBE2661ULL, 0x36ABDC924E43F463ULL
        },
        {
            0x765BC455F0738B46ULL, 0x4BB34CE90547EDC6ULL, 0xB94100F3E9B8FA14ULL, 0x569BE1BB31F1A102ULL, 
            0x3825400695DDB12CULL, 0xB8E09BD802CD3277ULL, 0x958D7C7E34356EF1ULL, 0x80FC4C40AA17A69FULL, 
            0x555333B9521F9C8AULL, 0x24727828DCFA52ACULL, 0xD24E700D6C7F3C01ULL, 0x3F9E9409E369055DULL, 
            0x3BB0EF52BCFC450EULL, 0x3BA7C8E0BECB9613ULL, 0x9AB75B0C54CBE650ULL, 0x8909DBB605F0D51EULL, 
            0x677ACB19C5B38002ULL, 0xE23C7A501EC02A43ULL, 0x19073623C24206B7ULL, 0xEA1FB2F45844E33FULL, 
            0x25A9A28B692E0876ULL, 0xB5C7BCC373D665CAULL, 0x8A9473F1E36124A5ULL, 0x9FDA370DD0BB61C4ULL, 
            0x2623DC3D376CBFA4ULL, 0x7423A818FFD266DFULL, 0x8369E3DD0E674FEAULL, 0x6931E56EB49B4477ULL, 
            0x2A6F999D13BEFEC0ULL, 0x52501E503345045DULL, 0x31A1286F57AC8ADCULL, 0xBDF74E2699B2C7E6ULL
        },
        {
            0x32032131285A339CULL, 0xB3065693F1BF2E6BULL, 0xA9A22E954324CDD8ULL, 0x898526C66AC019C6ULL, 
            0xBA827E01141085A2ULL, 0xC0A1CA2EECB2E8E8ULL, 0x24D7D9CD57CA5B84ULL, 0x99B46AB3A0E6EBBCULL, 
            0xABDDE5341B2A07BDULL, 0x4CA760B20283DAA4ULL, 0x0A6A1FC89F289E68ULL, 0x50709AEEDDC98C34ULL, 
            0x6EFAFA564975AE5EULL, 0x8EF4F94E5EFDF9CEULL, 0xB1AE2679EA1C1577ULL, 0x90192B21B495CEB1ULL, 
            0x80A6B4F41494F585ULL, 0xD4CFE299092FE6E6ULL, 0x48AD6814949A3889ULL, 0x4011A6A56158699EULL, 
            0x5EAFDD304BB7448BULL, 0x73A2146479B32E36ULL, 0x9E06CFCFFEFB76A1ULL, 0xACFF9D48E0FD3D57ULL, 
            0xB601B11E1DF10AFEULL, 0xECCD710AD841E68EULL, 0xDA77124DA7AF9390ULL, 0x7CE27DE97FEB5DC3ULL, 
            0xF6FE3449CE79ABBDULL, 0xD4DED60F3301FF4FULL, 0xFE342E12BAA6AAD2ULL, 0xC419FCEC9A6CB6D0ULL
        },
        {
            0xCF5543DBDBF4850BULL, 0x671C61167E9E6B5AULL, 0x37766C770DD156DAULL, 0xB9DA39C1DA62B616ULL, 
            0xCA079683BC07FB41ULL, 0x154606B00CCA4B49ULL, 0x69AD441BECA4442CULL, 0x7A52D169768CBCDEULL, 
            0xD8D3650C7FF1349EULL, 0x39A5B181AF180430ULL, 0x5B4950EA491019DFULL, 0x4394AB37669FD583ULL, 
            0x85D53FDAA5537016ULL, 0x810A7939FE07AE81ULL, 0x9D0A6E018E165C73ULL, 0xA6DFDA18C2207488ULL, 
            0x2574FE153E4AFB0FULL, 0xD0A2799484C87F39ULL, 0xE1327DCC94BB7D04ULL, 0x5DC0885D2A3EF9E7ULL, 
            0x7CAB263B3B74A076ULL, 0xE10E080100C47FCEULL, 0xF8CE40C9A861554EULL, 0x2518BA68CB41D021ULL, 
            0xAED85B78C1DFE3F5ULL, 0x8452E03B0596362EULL, 0x9949B842CB594F3FULL, 0x262C350C63120068ULL, 
            0x6EF9B38F493C0AA2ULL, 0xDD6C6337A073D40CULL, 0x3407518EADDDE9F7ULL, 0xB81A8795B559BD3FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseAConstants = {
    0x15F8127F86288492ULL,
    0x79ED154A56395D71ULL,
    0x4ECD00903F388268ULL,
    0x15F8127F86288492ULL,
    0x79ED154A56395D71ULL,
    0x4ECD00903F388268ULL,
    0x93B7BDE0DFB490DBULL,
    0x0F1F0E2D592416D3ULL,
    0x8E,
    0x20,
    0x13,
    0xBF,
    0x8A,
    0xD6,
    0xF2,
    0x23
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseBSalts = {
    {
        {
            0xD762B247FF91F0CAULL, 0x4690953B49A3CA14ULL, 0x42CE4B86FEB0C7C8ULL, 0xB5235A1DD8E48DFCULL, 
            0x48EE06C5F4D450AEULL, 0x3A76A1E0DEDD2F7AULL, 0x99B226F8778034E1ULL, 0x244C43F3CA056D05ULL, 
            0xADC61BCB39112D15ULL, 0x2EEE909D8AB75E7FULL, 0xA27FB8CDB28CDE14ULL, 0x15E31952DB865338ULL, 
            0x0CE9DC7ACBE76F74ULL, 0xFFADEAFD33AFA2D0ULL, 0x57F3180720145318ULL, 0x0E250D80C2B94EAAULL, 
            0x11BBFCC61951DDBBULL, 0x73D8FAAEDBBAC629ULL, 0x14E9BD5392C28C60ULL, 0xCC4FEE6B9FAE8F48ULL, 
            0xF83A1A7B72B338EBULL, 0xE60423E0DAF3D334ULL, 0xF74905165E0EF8DEULL, 0x80FB3E244B1A8F55ULL, 
            0xE896745469EE80BEULL, 0x245344B107AE6DE7ULL, 0x336679AD2C979B49ULL, 0xAE610A130B90CB32ULL, 
            0x44CD18D837C4DCD2ULL, 0xB3097161F238169AULL, 0x7C7BAD4D9FB41E43ULL, 0x4E263F3B0A7F0961ULL
        },
        {
            0xD467D718E26237ECULL, 0x9168DFC9902D782CULL, 0xDEC59B6F78C8AD6AULL, 0xF0B5660534DBAD26ULL, 
            0xB26A449A0BACC267ULL, 0x7967712177610D4AULL, 0x777FFA650C768A40ULL, 0x6FCC864BFD2FBEA7ULL, 
            0x98B17122EF175E41ULL, 0xDE4C4522070FB371ULL, 0x1BE0F20253EBF7B4ULL, 0x5ED22270A66310E8ULL, 
            0x65F02BE6E08AECC9ULL, 0x563BAE6A49A50149ULL, 0xDBF6DC04CD8A4B62ULL, 0x6965F2524BC831A2ULL, 
            0xBE1CF80E7018A803ULL, 0xF1A0F7B625B6F22FULL, 0x4B69F95065BFE137ULL, 0xB3F2C3F1A5C3E738ULL, 
            0xA0A94F91CEF25572ULL, 0x68DF1B1B72F328A7ULL, 0x0A721767D7E9A4A3ULL, 0x27D91B347C28D0D9ULL, 
            0xA68B16D4CDCBC972ULL, 0x5EF219342CE3A292ULL, 0x40B9D0720C4E68D6ULL, 0x4B691966D0769C8BULL, 
            0x6331A64124E7B1B0ULL, 0xC1D6CA4D2EE07DB8ULL, 0x90A6CDAAA8558722ULL, 0x5F2F56A16B60AFADULL
        },
        {
            0x79435ADA00AA62ABULL, 0x953230BBC9829A05ULL, 0x1F1FD75DC01BBE41ULL, 0xFAD21A830D3B3663ULL, 
            0x50238CB1AC77902DULL, 0xE77399C68A52C607ULL, 0x15D0540EB16E9FAAULL, 0x238BDB9FE9B23905ULL, 
            0x2E2B5436A6823538ULL, 0x60E3CC89CDB251DAULL, 0xF7FD2112A90A5904ULL, 0x375F32FF88CF8EF4ULL, 
            0x2A38C2A56FE6E4CBULL, 0xEEE02F63C2105626ULL, 0x3166CDF85ADF15C5ULL, 0x0048CFE56BF21E23ULL, 
            0x5E5CF435B8072418ULL, 0x65F5BD8DDE91E302ULL, 0xBAF3F923305D56E4ULL, 0x969110E95EB52B5EULL, 
            0x9068AE300DC0CAC5ULL, 0x21FDE66EB8AFDD98ULL, 0x892CED6DC78A5C85ULL, 0x3E50FE39E5093975ULL, 
            0xE445810018F2F5C3ULL, 0x10B98044C81EDA33ULL, 0xA424AD5CF927A84BULL, 0xDB8AA586F6F170E6ULL, 
            0x1AB7A89225AA06C9ULL, 0x7F2AA3AB82D654E1ULL, 0xB84F2D628F5848C8ULL, 0xEF8DF76E25A41CADULL
        },
        {
            0x213075E6B45D8FA7ULL, 0x7B8E345719335D2CULL, 0x59984CB209EF8F7FULL, 0x9F821050A19D4B62ULL, 
            0x44F98808E93F46B6ULL, 0xF5C9F57A4FF1E19DULL, 0xA288A90AC80DC578ULL, 0xF2F8CDC0BA005A15ULL, 
            0x4D559C751DC4E21FULL, 0x1C78BF9AD52929E8ULL, 0xA6A1441BAEAB67B9ULL, 0x38307403C5760C8FULL, 
            0x6BC7179AEB10D56DULL, 0x417D06DC52C7049EULL, 0xC4C4464ACD75091EULL, 0x24261B9F551ABF2BULL, 
            0x4BD7A61299CC0A07ULL, 0x1DC80BD709EDE1B4ULL, 0x2A92149D282B50B1ULL, 0x8DDC2FAD7B5F5473ULL, 
            0x4B99E3AB372CE272ULL, 0xA73629720D7494D5ULL, 0x04E8BEC9A76686D7ULL, 0x8408C2CBBC074E8AULL, 
            0x9C02028F5529A9B1ULL, 0xE235D5319D7A4616ULL, 0x063F124137432667ULL, 0xBE85F59A21140461ULL, 
            0x92AF816DC850257AULL, 0xC0DB948F2818D97FULL, 0xED06ACE4EE2AF8BDULL, 0x962638B505786294ULL
        },
        {
            0x91AA81BAD6BA93EBULL, 0x3D137770C1462ED0ULL, 0xA1A74A4C8B345A5EULL, 0xF579B02E6C486120ULL, 
            0xFEDBF0749915146CULL, 0x1093A434DA89BC75ULL, 0x97A119A212CAED26ULL, 0x4B66033B13D0AEDAULL, 
            0x1708F4F393E36E96ULL, 0x3BAFB1DB63CA0EF9ULL, 0x8899B102AEB5D9EAULL, 0x6E696D7C3140FBC7ULL, 
            0xA46B6A5390AEB7BBULL, 0x2F9F2C15EF412C98ULL, 0x205C180C43523068ULL, 0xF651A7FE36F92598ULL, 
            0x9A7E1CDE20F08945ULL, 0xE873D5473C21BFF5ULL, 0xC5A5F06BF46CB45EULL, 0xD8631BAB19478E7AULL, 
            0x486DABCD8EF72A72ULL, 0x7990D9ED8A589532ULL, 0xE0C67B56E57C52C1ULL, 0xA8CC22A4B94F1C37ULL, 
            0xC4DDB4B6C78815C3ULL, 0xE9B4223A5E856BBCULL, 0x46CD353AC64C7B49ULL, 0x6769BA662757E059ULL, 
            0xDB39327201DA6325ULL, 0x03A1F5E8418884D5ULL, 0x697AC734892C0BFFULL, 0x443A2D2595AF6C76ULL
        },
        {
            0x873ED1E972936047ULL, 0x3CFE9CADDB2C60DEULL, 0x3963FA4487E64E5EULL, 0x2DEEFA407E8495E9ULL, 
            0x4663C947C88D0374ULL, 0x8A5371B6ECDA3C1EULL, 0x2C0DCEAE3F28503AULL, 0xB8695E13F4B511A0ULL, 
            0xFDE72FFAB398D21EULL, 0x4CF855D7C97895E1ULL, 0x56121AFA9FD838DAULL, 0x9DF71470FB41F8F5ULL, 
            0xB50EA706E918A6D6ULL, 0xFEE0DC99EFAC31F1ULL, 0xD4E3352682F34551ULL, 0x3071CBE3F6F94C53ULL, 
            0xBB138C1B65627318ULL, 0x7B8EE302B2DE37AAULL, 0x52D7A6E53B0D5FEBULL, 0x3534980CD81A9141ULL, 
            0xC0DB8DA7FDA42EB0ULL, 0xDABC35E5E4F2957DULL, 0x0724A6DE5C63FE66ULL, 0x28A61E93F1F6EB72ULL, 
            0xE74E12266D347C44ULL, 0xA6929974F37DB371ULL, 0x8608ACAAA1B55878ULL, 0x445C574925684E99ULL, 
            0x38EB748D74B7063FULL, 0x9070B43AF1DFB8CCULL, 0x6A8DFD26C3DF05A0ULL, 0x80F479DBB6960669ULL
        }
    },
    {
        {
            0x32CD631889407448ULL, 0xF0588BFA12C663C0ULL, 0x21DE786BCD528BA3ULL, 0x72829CD64CD12198ULL, 
            0x59E6672B09753518ULL, 0x4EB71E26ADE8DC76ULL, 0x39D71613DF1B5AACULL, 0x9160E3A2507D3217ULL, 
            0xE470226F108B8FFBULL, 0x0337BFB333484C7AULL, 0xAEC905D8DAC6AF8FULL, 0xD6F7DC78F451A0CBULL, 
            0x69D8B7246EDF9F3EULL, 0x439829DD0DCB32F0ULL, 0x4FA3E571E61764DBULL, 0x3AEF6CCCBCC3AA7BULL, 
            0x3625CE573CBCF0DCULL, 0x217E789BF5BFEAD0ULL, 0xB72FB1A32FB80BC1ULL, 0x45C8FA034B8595E3ULL, 
            0xD5F0D9095244D03EULL, 0x55E7CB46BAB35BC7ULL, 0x3FFD09B07C881181ULL, 0xFE93A4807C226FBCULL, 
            0x4BF3A6D1BAB749FCULL, 0x9F2B703EDB682607ULL, 0x50CEF40A6A7BD47EULL, 0x5BB3EFC8F7615F27ULL, 
            0x0746F1C64E557482ULL, 0x042909B280FA988BULL, 0x2C0F9942D6B1040CULL, 0xFE8940D5CBD613B2ULL
        },
        {
            0x6F02AF403B2A34C4ULL, 0x41B2061947582A90ULL, 0x6B3348D926E56ECAULL, 0xF4FA56D87FA77AACULL, 
            0xE30D0448C535E264ULL, 0xEB6EF9CEFD6D267BULL, 0xA229CD88CE686750ULL, 0x748E755615B6577FULL, 
            0xD73F806A70E3580DULL, 0x259FA3AB71762355ULL, 0xB878015EC41AAA2EULL, 0x06CD3E978016EB1BULL, 
            0x609A8027485E0EDCULL, 0xC6D9A02EE6768AA4ULL, 0x7D614172FFBD28BFULL, 0xE5F1FA333B468735ULL, 
            0x683607688518293BULL, 0xB02136BD182854D9ULL, 0xD00A6768461960B8ULL, 0x7268ED9DF0B8ABEFULL, 
            0xB03D719425489C03ULL, 0x07FB4AAAC8DC27ECULL, 0xCEBCED97D7892F08ULL, 0xC89105FB13576B8BULL, 
            0x64834317018AEA19ULL, 0x36C7DC72F2E42403ULL, 0x312A58B058F63030ULL, 0x0764BE4D44A3BDABULL, 
            0xFED14E3A1F8E25FAULL, 0x4671E6A6372F88ABULL, 0x3477DDFA198515B5ULL, 0x9DE6EF3FF4022522ULL
        },
        {
            0x104808B0FC518BBBULL, 0x632D656B205DDDB1ULL, 0x0CCC3CD4C64DFF69ULL, 0x93B159B83BC3B2E8ULL, 
            0x0B8ED9584FD932A4ULL, 0x8C4EBE41B3FD904BULL, 0x4ABE6FF14C67EDB7ULL, 0x54B20D7BC9C5589BULL, 
            0xE89F7AA1FF3D05FFULL, 0xEF818862FED22BD8ULL, 0x88E603C72846C966ULL, 0x5D35DF362DFCCC9CULL, 
            0x4F538760562BDD3BULL, 0xF967936D3721A797ULL, 0x6EC8364E23735291ULL, 0x5D059A9553C423FCULL, 
            0x1E1D46F35C4C9A39ULL, 0xDBB44626637432DDULL, 0xA9B0FF83E839466AULL, 0x427350BC3BB2AF98ULL, 
            0x0ADDB8F276540984ULL, 0xE537B6E35A448D7CULL, 0xC65633C38B9F59EAULL, 0xCF68B725B0418BD3ULL, 
            0xFE793A5F0D1BF5F0ULL, 0xC8BFE34A75A5C221ULL, 0xFA7B837C8262CC29ULL, 0x38FC93CCCBC49C96ULL, 
            0xB06D3CB0F2D8AEADULL, 0x80B0EB82A3D344ECULL, 0xB4B638E371B0ADABULL, 0x1867D1983B49CF07ULL
        },
        {
            0x379990E42269D2D1ULL, 0x99075008CD0F330BULL, 0xB0B89B81349F0A73ULL, 0xBE967F3385353110ULL, 
            0xE365D6CC8BB8A718ULL, 0x1DB98CC018292E9CULL, 0x0A260D33D89AA6ADULL, 0x2943805FCB509E10ULL, 
            0xD8C518A9E7E33E7EULL, 0xF749294C4680E733ULL, 0x32EBEE7B74F78176ULL, 0xDB20AEFB3E40F664ULL, 
            0x8EEFADB628810DB9ULL, 0x3978CC9274F42D5CULL, 0x9014776E5F0EEC03ULL, 0x6F184A2289FB4F87ULL, 
            0xBA91BA31C1807E1DULL, 0xF41214AE8A02DA9FULL, 0x903222FAFD051FE9ULL, 0xEB9DA009D341DA4FULL, 
            0x471BEBEC65D0A749ULL, 0x0CF09219C984A24AULL, 0x0F31C9073B7CCD91ULL, 0xD3CDEF01CF59B471ULL, 
            0x04931EEA87C9BCFCULL, 0x0A692AE35514B563ULL, 0xFC4D06062E9BFD80ULL, 0x7D93F34F75D6BACEULL, 
            0x353A2568E8D8F4F7ULL, 0x589990FE2FF5D62EULL, 0x782D2801197A8C94ULL, 0xE06A4145AF8C276CULL
        },
        {
            0xA1B42E4DA32560B9ULL, 0x91ED989B30F7E3D9ULL, 0x4DC167262D28A832ULL, 0xBF827C0A9B2A9E20ULL, 
            0xD126EBA3E5BF2955ULL, 0xBCD98165451D6EAAULL, 0xFDD899498A732F64ULL, 0x90A65581CE829251ULL, 
            0x73FA3ACB3C834C5CULL, 0xD63A24753C51E38FULL, 0x144399F26B28CAB7ULL, 0xCE098A0C7CB36B9FULL, 
            0x63B9C27BE2F2F947ULL, 0xD6591DB5E1413EFEULL, 0x6BF79B2A9F4C4AECULL, 0xD5C2BD593EF88684ULL, 
            0x7E3987ECACDE250CULL, 0x71340A2E769907E1ULL, 0xA8D5E67FC0C63A53ULL, 0x7C0F3BCC2C31C834ULL, 
            0xECECC57BBD5595F3ULL, 0x7D784CB040A37411ULL, 0x5CA5DBFE6D9223AFULL, 0x64D40BCC2CC896FCULL, 
            0x86CDFA71D51BE4B7ULL, 0xEF3ED7F7B018F097ULL, 0xCFEC424C816F65A3ULL, 0xB557A3F206DD908EULL, 
            0xFC904961B9FAC357ULL, 0x7730A8B946AE58C6ULL, 0x7D7B34073952D169ULL, 0x5A50A321B1B7A3A9ULL
        },
        {
            0x59DAEA41F8774E98ULL, 0xA356E2798F770678ULL, 0xCBFB57349C71D1E4ULL, 0xFDFBA0B598B6947AULL, 
            0x7BC42E340347F994ULL, 0x713FB2DF63F9E353ULL, 0x5CF530704001CDE8ULL, 0x1903C8F505459EA3ULL, 
            0xA259265FC6E0DF00ULL, 0xDFEA86F36715B465ULL, 0x8846FEF64FD0F820ULL, 0xDC0CAA4C61C14483ULL, 
            0x3BF5BA3EFA26FE18ULL, 0xD1DCAB28420205D5ULL, 0xF9CEDBB6B1CF751CULL, 0xDF45CCECFC5C2074ULL, 
            0xDF1B6489D1837273ULL, 0xEC5E79DE1C6C7E08ULL, 0x2677E32CF7C86A82ULL, 0x55B8F8F2FBD6E9AAULL, 
            0x468A66D95A566D76ULL, 0xEE5D0A2D819831DEULL, 0x9F682B92CE1BEBBFULL, 0x422CA773A7C11F7FULL, 
            0xA72A5879CD4AEEB8ULL, 0x5972EB7A3828DC2CULL, 0x0B618312B6358366ULL, 0xA41257C03984A0D6ULL, 
            0x96CBC38397CB15C1ULL, 0xEAF330A04E4A2199ULL, 0xBAFA480E0DBBF641ULL, 0x660AD03D3EC40E9CULL
        }
    },
    {
        {
            0x6FC72D9AF89BF98AULL, 0x6D7D8BE41E7B490AULL, 0xF2BF0A8D429AA29DULL, 0x50448BA73A207066ULL, 
            0x2CAD85F3F2B68D0FULL, 0x91E17250E8875081ULL, 0xCE311EA2DC57A8ABULL, 0xE680F403DF092282ULL, 
            0x2192F679437CCF08ULL, 0xAC05C6960598446DULL, 0x82165FB5F836FE0EULL, 0xB3CE3DD58A70C00AULL, 
            0xE79DCC662CC4C141ULL, 0xAC925B9C64A08B42ULL, 0x2F26B5EBE577930DULL, 0x876F4D251A766181ULL, 
            0x8451C82CF1FE4EA3ULL, 0x1AFC4713DE38B3C9ULL, 0x41610925D1CDA1E5ULL, 0x9D193F7FE2737598ULL, 
            0x5E46D030C6FC2664ULL, 0xAC7A52378BA3600BULL, 0x8D95F3D47A839DACULL, 0x2648B4D789C39668ULL, 
            0xDB26A4BF01C3C56FULL, 0x1A907C5453CF3F14ULL, 0xD387736B1FE27B44ULL, 0xAAD7C28DDE54E4A8ULL, 
            0x885BBD3C39C012BEULL, 0x1DD47CF653842CC0ULL, 0x108505C574C2258AULL, 0x96DA8733A36DC5E6ULL
        },
        {
            0x9C718DDF282744AFULL, 0x177DFF1DD2750897ULL, 0x385BF315826DE2F8ULL, 0x6EE9419AC8A8CBC5ULL, 
            0x4E49931FA9775FDDULL, 0x4365003D8CDFDB5BULL, 0xE5719B053C9D9FE2ULL, 0x4CE17185F6BB62EEULL, 
            0x37952CD9E7FF8308ULL, 0xAC8C772B89B7B81BULL, 0x617AA551723C1508ULL, 0x8AA3C767A4FAD4A3ULL, 
            0xD52800B6F2665A1BULL, 0x819992339D3B15B0ULL, 0x1F5FC5B01631EB93ULL, 0x3E9F81EB5586ADEBULL, 
            0xC7C1BE8BD1EDB8F0ULL, 0x68208120B785C8C3ULL, 0x51B8E287B2121BC4ULL, 0xCE143EFFBBA832B1ULL, 
            0x076F13EEF3C00480ULL, 0xA3A68049218A22E5ULL, 0x2A91BD79F9DE886DULL, 0x1EC8E63B85D994F7ULL, 
            0x1340255C12C4C01FULL, 0x0021280FD9BFF2DBULL, 0xAE61B9500B1D4BFFULL, 0xFA82AF4260C2AEDDULL, 
            0xAD58651ED8F6231BULL, 0xE8968883E39A95E1ULL, 0x02FA266E86143143ULL, 0x496F4E7D2C10E4E6ULL
        },
        {
            0x3202F028D616103AULL, 0xD18C0C0EE8A71C1EULL, 0xE1FF07C88063C90AULL, 0xF4EB2A44671A3926ULL, 
            0x37013DA363B2D391ULL, 0xD423A15AE616F632ULL, 0x6E1CD835DA759B80ULL, 0x1069BC972DCEE0ABULL, 
            0x9A6E19E91388B8EDULL, 0xE86E478981EDF597ULL, 0x3785737E640B5437ULL, 0xB0D9EFE6EE8DD00AULL, 
            0x567B4059E3A9390FULL, 0xB31348B7D9426360ULL, 0x27E3366B6A9F7A74ULL, 0xB60E653D227E23E4ULL, 
            0xC74D5296921062F4ULL, 0x1AD6623BC91919BAULL, 0xEBB7A50FAF48D4EFULL, 0x1137A5D728E2B389ULL, 
            0x873374991B05EA09ULL, 0x569EF99E63F1D477ULL, 0x7207B1E32DBEF5A5ULL, 0xBCC8E00DB66F4199ULL, 
            0xD4684E880E694E95ULL, 0xB2C42E6F1DD6B9D5ULL, 0x6B35CB7F132203C8ULL, 0x42E884FC3FAEE77EULL, 
            0xA138242F1F190D80ULL, 0x51D1870ED5830BEFULL, 0x0CBE30EF024451D2ULL, 0x2599A341152EE80BULL
        },
        {
            0xC13366AFD050CD87ULL, 0x598C0A1BEDA1562EULL, 0xC8B6BC22EA2B8BC0ULL, 0x3A00582C7F875042ULL, 
            0x3ECB5F7CC15E91F2ULL, 0x66199142BB83B84EULL, 0x8E942CC78414BFD0ULL, 0xB908034489F28726ULL, 
            0xFFD6E0CAF1451A34ULL, 0x341CD867FD91DCB4ULL, 0x924A205F7D773AF4ULL, 0x44EAFEAF2946271DULL, 
            0x90EEB12B7A03F8C7ULL, 0x157816DA9DD720EAULL, 0xB5FB4747EF115CA6ULL, 0x0CE3D11667441F51ULL, 
            0x5AFA0B9722A10C1DULL, 0x0B85F812C03D4708ULL, 0x33A5F9EDE8A3B45BULL, 0x10D4B72AA2723E61ULL, 
            0xA2D1BE8489DBC8C9ULL, 0x8066F6D436829724ULL, 0x3CEC52D8364E2856ULL, 0x00262ED9CFE801D3ULL, 
            0x6E95411E5F8A0FF2ULL, 0x337C5DAB9FE80458ULL, 0x81FA6912AE3FE68BULL, 0x13319395E2E2291BULL, 
            0xA7BEEF639BEECD5DULL, 0x94D2A0256D09D505ULL, 0x63806F868F7449FDULL, 0x8BA319675DAF8FB1ULL
        },
        {
            0xC7B94B00B7EC96F1ULL, 0xA5C988495691EF26ULL, 0x24898E61F11FBB2AULL, 0x13A40D611BBE5869ULL, 
            0xCDD49E79B38FAA2CULL, 0x3EF999A8685EA8EAULL, 0xF62FFA20826662D6ULL, 0x257614D244496FC8ULL, 
            0x8B09F042F3FC6664ULL, 0xCC774FB3C2DE5F09ULL, 0x3F596B950019585FULL, 0xCEA318CF32D60AF5ULL, 
            0xC44E4C17B80F4D0AULL, 0xAAEFEB4ADE133EA8ULL, 0xE0BEB666D92A0F2DULL, 0x53092176B5514C60ULL, 
            0xFEEF944389EC18DDULL, 0x55029FDE65CAC83FULL, 0x74A1D9F2A67C975CULL, 0xC0FC5F36E7B1EA53ULL, 
            0x57748060E3D74864ULL, 0xD55496F0A026EE71ULL, 0xFB4D2ECD870F9DB6ULL, 0x2468DF08218EC401ULL, 
            0x03B83B28E46FB7E4ULL, 0x96684612442E345FULL, 0xC00711564EE4C993ULL, 0x0319BB225C7713A5ULL, 
            0x09DF2B5AC637741EULL, 0x58892D1A15FA3543ULL, 0xA11894161032F295ULL, 0x16A2E474DFBC52CCULL
        },
        {
            0x6EA3A5438CD19940ULL, 0x4B59C70139BE7481ULL, 0xC64ECAECB6712511ULL, 0x641236D92D24A5C3ULL, 
            0x1D30B049ACAF23B5ULL, 0x72906E9B44829AE1ULL, 0x9B0E187AE688CC9FULL, 0xE7A0EBEE8E8C2F95ULL, 
            0x974FF9930235A678ULL, 0xEA245CA6CC90E42AULL, 0xCCA2F54E18FD79ACULL, 0x147A852E52FCA8FCULL, 
            0x8A32C4C784EC4D7BULL, 0xA8AC8FCBABF03E44ULL, 0xB92823E6DBAC80B5ULL, 0x0365A96BF4F81432ULL, 
            0x9C2219E39B78BB36ULL, 0x793FE64F9E990FD9ULL, 0x02C806CB51895713ULL, 0xEE672DA17ADE0EE9ULL, 
            0x63C4D47B62594BDAULL, 0x4A6FF6EDB20D5FC5ULL, 0xACF941784EAD14BEULL, 0x01AF0409E97F2915ULL, 
            0x932351801F817AE9ULL, 0x33C01E72B69BD5DBULL, 0x49CADF012A2D5896ULL, 0x91266938C750094BULL, 
            0x8D8348B98B6B44A2ULL, 0x4954623CA3CA385FULL, 0x2854A0DE74D61586ULL, 0x8C278C6DB231DC84ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseBConstants = {
    0x7C58AB78567474B4ULL,
    0x55B262B470FA7B43ULL,
    0x58F9F212505B5C58ULL,
    0x7C58AB78567474B4ULL,
    0x55B262B470FA7B43ULL,
    0x58F9F212505B5C58ULL,
    0x7F3C2C53757C56C8ULL,
    0xA11860338F5777F0ULL,
    0x70,
    0x20,
    0x99,
    0xAC,
    0x15,
    0x2B,
    0x67,
    0x2C
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseCSalts = {
    {
        {
            0xBE3E3AB97B323E26ULL, 0xEB75199402A7216CULL, 0x7446918337A440F8ULL, 0xDDD01FBB16A8CEF2ULL, 
            0xA4DB6D5D095540F9ULL, 0x67D4E97CCCCCA5F2ULL, 0x88241885C527D631ULL, 0xBDF915EEBD968CB9ULL, 
            0xC16F54BE64096562ULL, 0x7010034C12C61FCBULL, 0x71F615F04A0484F3ULL, 0x23E4BB20A4B9E12CULL, 
            0x671A19E10134863FULL, 0x410345B75FE5E10DULL, 0xD8D8A54219012C46ULL, 0x157D9B981EC87B72ULL, 
            0xB42859501815F77AULL, 0x39FD9F5136EE631AULL, 0x953FE17B24E95210ULL, 0xC286A1080850D942ULL, 
            0xAD373C3663179E5BULL, 0xCDD33734341F2BB0ULL, 0x04C89C53F3F54382ULL, 0x0B2704163B5895F8ULL, 
            0xCA9A6476612CE0ABULL, 0x3B13DA454BAC8A1FULL, 0x17E5205CB2E2D5ABULL, 0xD00F1DE929D79570ULL, 
            0xE70BDF407D8EEBA6ULL, 0xEF23A8D15CD27651ULL, 0xA7E254C589EB8262ULL, 0xEBBEF7D182F98276ULL
        },
        {
            0x4EF23006C162C133ULL, 0x883AA88BD620A182ULL, 0xF352E6FF956D13CAULL, 0x47DB197A00C74B0CULL, 
            0xFE24ED1CB74765D1ULL, 0xC393A4424A84368DULL, 0x8A3600DAD7F14253ULL, 0x153E6BBDF6675AFDULL, 
            0x417863CE6016F8D0ULL, 0x5E20A2FFF74B46BAULL, 0xCE4E433E10998C8BULL, 0x825033F89A27C0F9ULL, 
            0x706806BB41146A9EULL, 0xAF8FDF6FA68E9F9CULL, 0x2C7A21D9BD4F78DFULL, 0x50FAF76126D57268ULL, 
            0x25A23651471C8464ULL, 0x4B14976CAD085772ULL, 0xF6792E22CA8453ADULL, 0x1BB1A6528C0D0B60ULL, 
            0x8F9182CFB6701C00ULL, 0x46278594A6F71B5CULL, 0x1EE376CDD89A133FULL, 0x82A14CADF25803F1ULL, 
            0x70E0B764AFCBDAEDULL, 0xDC440DA2EC780B71ULL, 0xBEB469C1939AEDE3ULL, 0xB669AA72A2E3F720ULL, 
            0x3006182BAF4BC160ULL, 0x40D542F4633DA464ULL, 0x130669F885A3E44DULL, 0x27C67D22B5FC0E3EULL
        },
        {
            0xC881008EA3CF3EC6ULL, 0x92B3C05758931EB8ULL, 0xAA5C8E2E45880118ULL, 0x3D6A13CE7CB672AFULL, 
            0x8957A78A9EA2760AULL, 0x394FEF4104A5CC13ULL, 0x3DD01CBBC2CB1E0EULL, 0xCF3C30E147A39DD7ULL, 
            0x787A3F923777AEDCULL, 0x913D98509C1BD16CULL, 0x632C31458B9644F3ULL, 0xE927B6FA67CE07AAULL, 
            0x261D2CBB54C8A005ULL, 0xE87BE404C7E34DE7ULL, 0xD827B9B47986B169ULL, 0x7A2DF883C3DF2CB6ULL, 
            0x571E4C37D4E03D6DULL, 0x7140D957C715D965ULL, 0xCDD3E7B89FEA83E7ULL, 0x297A74452E055E58ULL, 
            0x51D87C9EC9B628DFULL, 0xE16D4375BB668CC8ULL, 0x4F0982F7F2543DDDULL, 0x97020DC62374AF40ULL, 
            0x501336CC5EDBB306ULL, 0x12B1447E0973C8CEULL, 0x4A86044B6B681326ULL, 0xA6ACB9D3F1AE2BA5ULL, 
            0xC40972621EE868FEULL, 0x61F84E31B64CBECBULL, 0x2CE4CB3CDD5CA968ULL, 0xDA66BDC45DD1E59DULL
        },
        {
            0xDCBD95CE472B6A0BULL, 0x5D3FF5C4946823E7ULL, 0x1413B4DB69FC192DULL, 0x36C7E58238587A97ULL, 
            0xFB48B515D3E147C2ULL, 0xBFF432A095CCBA92ULL, 0xC7167A7FB9C2EA77ULL, 0x3E25ADCAC3F55D01ULL, 
            0xD57897AA02329D4FULL, 0x3144B1401161C9C0ULL, 0x3E3FF608F826817BULL, 0xB58E19745DFC0C96ULL, 
            0x444956585565625CULL, 0xB69D6FEB3832850AULL, 0xCCE0D72D12612C7CULL, 0xAAC52A658A3A23B4ULL, 
            0xB0D40D46E27CE384ULL, 0x8A9CCD1B594D2144ULL, 0x92B977F6FE4B62B5ULL, 0x9F8BE9F49E4C13ACULL, 
            0x27E30FA4C2F96B64ULL, 0x7C16EF4F24F6ED92ULL, 0xE2AEC6F1111F73BDULL, 0xE61ADD1816CAE947ULL, 
            0x701A048C06E4BBBFULL, 0xB7DF817A5C9BE1ACULL, 0x10F4B19276BDBA70ULL, 0x3AED9727F3E969E4ULL, 
            0x427241F7D6E80710ULL, 0xFBB0DA71E7C748DEULL, 0x3280289C1AC65008ULL, 0xAB19ADD39214172DULL
        },
        {
            0x354C869C6B15057CULL, 0xCD257177F4B6E179ULL, 0xE62AD0B57B89FCD2ULL, 0x178600717A4A5464ULL, 
            0x1B2533867B8E3DA5ULL, 0x4C4CB088A155BED3ULL, 0x1DC4D1AE4300930EULL, 0x99D0D9A8A010F9CEULL, 
            0x2C666C7A107319A0ULL, 0x09AC8BCDFF24BDA5ULL, 0x73CF052AC9DED65EULL, 0x41953D40FCDA9815ULL, 
            0x5CC9AAAC5169D3D8ULL, 0xFF8A8ECDDE7FEDF8ULL, 0x9EF941306B8E23C2ULL, 0x33AD905E3A4133F3ULL, 
            0xBB913F0BF6FE8A40ULL, 0x0E0C7359CFDC036EULL, 0xA4FCAC661FD8E061ULL, 0x730B835D6DF227A0ULL, 
            0xD64681C6026E8CC2ULL, 0x4D4700DF372565DCULL, 0x9F38A0CE9232C3EFULL, 0xAC5A5CF9869E232DULL, 
            0xB2B59D8CF339EB66ULL, 0x8057EFBE08808E67ULL, 0xBC4305991D5A0A72ULL, 0x5D3A2A1A2FBCF299ULL, 
            0x5CD852EA78ABFC1AULL, 0x16CF80F9218A5264ULL, 0x93EA7F47AF080E1AULL, 0x3A8B79FDE2C1BC8BULL
        },
        {
            0xA8A6C2D776E9C5F1ULL, 0x373247E80860EDD2ULL, 0x859DF0269E879FFDULL, 0xE7EE5A1789C30421ULL, 
            0xC470B7586723C26EULL, 0x665BAFAF9D3B4F40ULL, 0xF33708558EC0EA24ULL, 0x2253E41848AAA608ULL, 
            0xCC25A18193C62D48ULL, 0x091CE637F50B4301ULL, 0x3628A6D2EB0D75D6ULL, 0x9663737755FA13C3ULL, 
            0x6734286139C3CE6FULL, 0x2815FE32F449C1AAULL, 0xE71AAEF8ECCB889AULL, 0x5B197540D2A94256ULL, 
            0xB4B1C0D1D14B7CD2ULL, 0x1EA50C0AC32D652CULL, 0x503B643EF26FD3F4ULL, 0x92082663AE5DB946ULL, 
            0x2749A8A4080242A9ULL, 0xF0A90CFF0D60AEB9ULL, 0xD54E3CCCA609F40BULL, 0x16B4667F9C8DF9E7ULL, 
            0xE8DB43359CD708E0ULL, 0xC93C8064C3928A97ULL, 0x28F48E979FBF97EBULL, 0xCE47E2F4D1C54D9AULL, 
            0xD1205E4C7955FF4DULL, 0x26A6DF1BBFE5447BULL, 0x5B235B19FF1105BCULL, 0x6C6856DF8FD22AACULL
        }
    },
    {
        {
            0xF7215C63EB84BE03ULL, 0x485F8629F91B976AULL, 0xC795D74B4C5BBFAAULL, 0x0B070833E2B89CADULL, 
            0x257E3EF8611FD786ULL, 0xAA97B5217A3D1AF1ULL, 0x9CE9BD88BD5A525CULL, 0x8F742364F0BB319DULL, 
            0xFD7F486785DA9D7BULL, 0xC4241BC7F954A243ULL, 0xE15DE00819A526CCULL, 0xFAE9FA0D2B455F65ULL, 
            0xC8269756568E7DF2ULL, 0xF305B6F553B30074ULL, 0xD4B8E614E7531E1FULL, 0xBE773D9CBE8698A6ULL, 
            0xAE130915B5731786ULL, 0x3220FECE2ADA9373ULL, 0xFE70191CCC307326ULL, 0xDA548134E65CE761ULL, 
            0xBCFD67A7780A1517ULL, 0xCE2C69BC1E95767BULL, 0x5C21C4F2F1B82F55ULL, 0x40FCABC052F15BF5ULL, 
            0x35FF04C161FA1663ULL, 0xCBD1071D2311F94DULL, 0xE5E8910C60DA3B2EULL, 0xF9D1CF226F49BC58ULL, 
            0x2BC20B87C83E221CULL, 0xE6DF83C94CB1E133ULL, 0x09670830FFB0ED17ULL, 0x741A3DC576E01BE2ULL
        },
        {
            0x2E54026895862D81ULL, 0x17ACD051F3D5538BULL, 0x423933ADB7E99A55ULL, 0x13DC23D2126D7957ULL, 
            0x165B35C16F4E054EULL, 0x1D1E69FA9E4AECC6ULL, 0x732B2B54AE682DC7ULL, 0xA9F11F56E80DE101ULL, 
            0x5B9C4BF188DBDD5AULL, 0xDEA31A2D807160E7ULL, 0x811272A6313A85CDULL, 0x8C01814C43235199ULL, 
            0xF1417CE0EF02F22CULL, 0xA35630DDE8721357ULL, 0x9466875814A63B3EULL, 0x7BF1CAC499511A77ULL, 
            0x17D037F1CF85A93FULL, 0x43DE5E0A0F8D0C3FULL, 0x13E38407EDB79816ULL, 0x37C6A9D17F385374ULL, 
            0xA61F35AD714DC7C5ULL, 0x0037B6A66CE2A277ULL, 0xC4524BB8A9282005ULL, 0x76F5C9797D160F8DULL, 
            0x560990B6B2645B5AULL, 0xC8F9BF8583826AFBULL, 0x56027A1D1F875406ULL, 0xA6191755D408923BULL, 
            0xB7917D5215142F01ULL, 0x6FD9A7694B50EECBULL, 0x053519AA12AE4CEFULL, 0x13FB76B9B6C4849AULL
        },
        {
            0x70692DA94898FC69ULL, 0xB8C08095CAE2DCAFULL, 0xAC1B8342710F75A8ULL, 0xC29EE4929BF06970ULL, 
            0xBFCDEDD1B48DD1E9ULL, 0x3B7DADACB50F47DFULL, 0x342750063BCAAB9EULL, 0x8FD2E6B2B4AAB184ULL, 
            0xD4CE3B376867F17EULL, 0xBD33934FF3FB8864ULL, 0xE9A3ED9F273F46D5ULL, 0x83D694FCF1E220EBULL, 
            0x665107374265BAB8ULL, 0x8E01845022C33CFEULL, 0x12ECB278C99BE91DULL, 0x551B5DAEDE3FB9BBULL, 
            0x6F65A15A677BB837ULL, 0xB3F5FC756C704E1BULL, 0x29DAA352B24CEBBBULL, 0x33FF1965BA97A9DCULL, 
            0xE060ACBC9C335E43ULL, 0x5E8393E775E02DA6ULL, 0xDDF3536CE3A78A09ULL, 0x460A3DCC20EAC891ULL, 
            0x24131E44E685DE76ULL, 0xA8D918268C3ACB78ULL, 0x983F19889175B460ULL, 0x03456914920BF6BDULL, 
            0xBAF35E90D2D8C502ULL, 0xA69178410CC37226ULL, 0xD3C40DDC9A7B76C6ULL, 0xCEF755ED85AD1A47ULL
        },
        {
            0xEDD45DC32DEC3A98ULL, 0x836CAD3E56CED604ULL, 0x7116F0386DE0AD10ULL, 0x83D87183CFE20EA0ULL, 
            0x46E3AA49330F6B40ULL, 0xAFBE471D8C3CD144ULL, 0x9DDEA847E5D2FC22ULL, 0x6F2081B2140F628BULL, 
            0x767ECACC87983C81ULL, 0xABF84C83FD899EAFULL, 0x84A4568DBA70DF6EULL, 0xDE7CFBEA0A9D0AECULL, 
            0x84D38A712574B68AULL, 0x794851E7076A3748ULL, 0xB23C8DD18129332EULL, 0x5DA910AB3BC280ACULL, 
            0x83615B949C22A128ULL, 0x0E971C9BB0B14781ULL, 0x62ABBB3811E74E4DULL, 0x4386BEE983594C64ULL, 
            0x23CCB4F45AD392C8ULL, 0x21F9435601E6905FULL, 0xD10F6E834397A52FULL, 0x2C98C418B3C84D05ULL, 
            0x62436D645B39DC8FULL, 0x8C74765E6612D79DULL, 0xCAAA937B10B43A2BULL, 0x1C73C2A46CACFD79ULL, 
            0xDAA7099655158FBCULL, 0x3263E094C668C1B4ULL, 0xA0E5B3693A24033FULL, 0x3D07E7E5255A225EULL
        },
        {
            0xD2465B9BCF353546ULL, 0xF73D39EDD60B6120ULL, 0x40FD3D5E03FA9762ULL, 0x949F787A11F4AA5DULL, 
            0x044564E7224CD3D8ULL, 0x6D3FB40AEE18B292ULL, 0xBB44E3192D70F907ULL, 0x8905CE8605977237ULL, 
            0x5458DD7917D04388ULL, 0xA44EA8BA61E82A4AULL, 0x542DFA40536B458CULL, 0x2D4D3D4C775CB10CULL, 
            0x9C4744179FD6BD53ULL, 0xB71AD789DE79E41CULL, 0xA1F04C5FDA6A1EA8ULL, 0x1E1922C1F2FBAC64ULL, 
            0xF97BAC17236AC9D7ULL, 0x2B7C6CEFEDD5A80EULL, 0xBFA05EBDC194F80CULL, 0x744D4D8ED3442595ULL, 
            0x4DAA476F55CCC89BULL, 0x058853A2400B4000ULL, 0xD55D4C223E175E49ULL, 0xFCEED76AC715F082ULL, 
            0x01D931AFF4B18026ULL, 0xE051638E5F7913F6ULL, 0x54DFB62902F352F7ULL, 0x15BBD5CE6CA670EFULL, 
            0xF3E05AC14F8DB66EULL, 0x1F1D5E39756FD127ULL, 0xE5478B43E3574D43ULL, 0xE6B0F31F42C6CB0BULL
        },
        {
            0xC49DFFC61F60B8C3ULL, 0x2FB5B02FD8784CBAULL, 0x7A20571D0C595C76ULL, 0x5EED6132569DDAB3ULL, 
            0x27925F41AD184E07ULL, 0x53659F7BE98D928DULL, 0x203D9FC98D49FFEEULL, 0xE2E8E9EF3D2EE08AULL, 
            0x11C358058E4D9FC3ULL, 0x84FE5A0A8C9188C7ULL, 0xEEFD9179416CEE16ULL, 0xC83F435160216589ULL, 
            0xB31369018FA02D9BULL, 0x43B6DC459610B52EULL, 0x0D6355FF33E99C64ULL, 0xC59B0D8B5CEA0EABULL, 
            0x3E65F5629877F767ULL, 0xE6CF4E6FB4288CB8ULL, 0xCF26C5B73FD173A8ULL, 0x4BF6A60332E7D988ULL, 
            0xCAFDC23AE0E31414ULL, 0xDB3415DBB5771804ULL, 0x7274E2162B8CED66ULL, 0x936CC487D3BF9E5FULL, 
            0x5B969B19304F91A4ULL, 0x214CF27978A7FF7CULL, 0xA8E96FB53E3ECBAEULL, 0xC75ED89A0DF76A94ULL, 
            0x75FB95AB10AC2A96ULL, 0x375625E317EC23CBULL, 0x6258C32B7C916A09ULL, 0x776CFB758F2EB9A7ULL
        }
    },
    {
        {
            0x7E3D742D13A4F6F4ULL, 0xDB6FF27E9679F18DULL, 0x6EEBA63BD02FFD0AULL, 0x35D6A46EB7A1BCFAULL, 
            0xC6F1508C94378125ULL, 0x8E87D7655EF71FD3ULL, 0xC6216E6C29B7265BULL, 0xB86AB6B45E80EA25ULL, 
            0x448C4B09C37D9520ULL, 0x2D5893850E899609ULL, 0x63BA7548A98BF485ULL, 0x45F2AA9CB4754FD5ULL, 
            0x21AFAC1740277EF8ULL, 0xAC72B6FB47ABA1ACULL, 0xC127BA15F6242275ULL, 0x80F84835FB26998EULL, 
            0x32518BA62BD56E09ULL, 0x95ABA18C883901F7ULL, 0xB6E081472894FA58ULL, 0xBC715A25FF98948FULL, 
            0xD7D392B717DE17FAULL, 0x54FC66F0CF608715ULL, 0xC4358A72FB9D9EB1ULL, 0x9BB8085CC73216C6ULL, 
            0x0311E53784CA9CABULL, 0x18579C99B20350FCULL, 0x90597373CD282D76ULL, 0x74ABDC6E0C02FF6FULL, 
            0x56E3648ABE6414B5ULL, 0x83FD3ED711CFDB07ULL, 0x370E98B254255F4DULL, 0x11BD3F64DA88E1A2ULL
        },
        {
            0x11AC12F9B246CC6FULL, 0x5D365965591C11AAULL, 0xA1B34080A411F41AULL, 0xEE3375C62B040EDDULL, 
            0xC38AC612E593435AULL, 0xC259A24632117B4BULL, 0xCB11394A7B3A0923ULL, 0xCD7262CC796C3A8CULL, 
            0xC198BF6881B0FEC6ULL, 0xFB5390DE970AD55CULL, 0x611AECBEC97FD91EULL, 0x72499437B55706A6ULL, 
            0x04280B9D5E4F2BA9ULL, 0x8E6C04A5E2D4F8D1ULL, 0x94CA425C2C8F37B2ULL, 0xB4E049CFF5517E81ULL, 
            0x70C6E19DDCF3486BULL, 0x1B5D8859ED5F0E8DULL, 0xD5DA2AAF6F1B941AULL, 0xFDBC7A98C67E3992ULL, 
            0xF0D237434131EE46ULL, 0xE455852CDCD0B8FBULL, 0x65B1D50BFFC24D15ULL, 0x1AC68C2CF5248039ULL, 
            0xDB15AC9A5E8624C1ULL, 0x359C3A5BCBBBDC06ULL, 0x421401FA582B9F4DULL, 0x9C1D685C9AECBCB9ULL, 
            0x596739427966A192ULL, 0xF395375EA062A0DDULL, 0x1C6C696CCD577D05ULL, 0xFCC32B46095BAEF8ULL
        },
        {
            0xF71EFBA5E03291F3ULL, 0xA6BFFA273BD8A855ULL, 0x0701145AC02D77E0ULL, 0x46302231334A642EULL, 
            0x93A4994C4E9896C5ULL, 0xED55D23CCA542BEEULL, 0xD8C44F51EFAD3B5BULL, 0xA03B40DFA13C77D4ULL, 
            0xE90D75425DB59B0DULL, 0xB95B39DA0ED2A611ULL, 0x0121B37D5ACDCD50ULL, 0xB77F8093F610C47DULL, 
            0xBBE4BA59AC32F2BFULL, 0x7FF14305C1CAC0B2ULL, 0x9CFB8DCE1241C372ULL, 0x3144444C2F672329ULL, 
            0x5A0B8C84E17587F8ULL, 0x98E1F1C6BD59B4B9ULL, 0x827B6616B378E985ULL, 0xA81EDF2A4ECCC8FBULL, 
            0x3DF8EB83F80A1633ULL, 0xBA5FC1E75A9A80DAULL, 0xF6862EFE882010EFULL, 0x392E0B8A7DDB20FEULL, 
            0xCCAA139EC6B419F3ULL, 0xAF7915217B87C297ULL, 0xDB07F4C6DDCD74E8ULL, 0x6829DAD41C4DE80BULL, 
            0xB5DF76D73381599AULL, 0xEFCC2FD2FB98FF44ULL, 0x51BC1AFA0A1A65A6ULL, 0xD621F9A85BBF63F5ULL
        },
        {
            0xA5715AD1CF8D1476ULL, 0xCAA12426D585D364ULL, 0xD43554A007246F01ULL, 0x8692D986502C6D96ULL, 
            0xDF95FC4A162877F1ULL, 0x68912B678D5B31A0ULL, 0x47887BB3AA9EEDBFULL, 0x4571E64448FD8E76ULL, 
            0xB8C8B7B223DF227EULL, 0x5240F1689802FB3BULL, 0x48B324AD55C4FE02ULL, 0x48BF1ABFAECB3066ULL, 
            0xCE13D41F6CB9C026ULL, 0x7763E93E0C041759ULL, 0x1EA2383FB16468F6ULL, 0x1D3834B231098F16ULL, 
            0x203D6E09E399FBA6ULL, 0xD79DC0E2DD7A30B2ULL, 0xAEFC6F95EBD92BA4ULL, 0x814EC0DE5357E9E3ULL, 
            0x7AA393CEBCABF5CBULL, 0xF15150DD8DA7B249ULL, 0x03B292EE5C6595FCULL, 0x70D02D6B9E0BC225ULL, 
            0x63BF05995BAA3220ULL, 0xB99BC21C23483116ULL, 0xCA268A1D1BC4F573ULL, 0xDFF25CEBE4F26040ULL, 
            0x5CD9D5D902EA7443ULL, 0x97105D010B5F0028ULL, 0xDB6F9851AF376DCBULL, 0xCDF942239B808CB5ULL
        },
        {
            0x90F4A6F79C281E73ULL, 0x6689052CABD1D573ULL, 0x6F5C126AC396E8B6ULL, 0xCA7DC7B62CE5745CULL, 
            0x46F555025EF34CA0ULL, 0xB2972310AF2417C1ULL, 0x49019C90CDBF1388ULL, 0x5C0C4FC601C7A35CULL, 
            0xFA1CF1187230FEE1ULL, 0xC4CC4E2FFAA6A05BULL, 0xBFC0512E30A9DF34ULL, 0xF8EDEAD0BA0F7D31ULL, 
            0x56EE1FB81802ACEDULL, 0x85A9DD7630AA4DA0ULL, 0x5C20E821429D6582ULL, 0xE6475A8748F705F1ULL, 
            0xDCF640D0AB1D956EULL, 0x0F527C3B1AEFCA43ULL, 0x7C7854390D0632A4ULL, 0x25C3974BAA22A7D6ULL, 
            0xF7F7B547A6CD13D2ULL, 0x1C2174BB9B38D290ULL, 0x725CC6E9493FB70EULL, 0x52EF552764C12236ULL, 
            0xDF4B21F2A0969046ULL, 0x4F78179624960547ULL, 0x331AE6B843477D66ULL, 0xD7119532B9EAE1D8ULL, 
            0x8611BCD321858345ULL, 0x3087A23D89DC4392ULL, 0x5061C677C1F91AA6ULL, 0x3D1B234E9EC7CBC7ULL
        },
        {
            0x8A774E08F11E7FEFULL, 0x0FC640C49FE3B277ULL, 0x95EBFE30164F45EAULL, 0xDB3968097DC245F0ULL, 
            0x707B2349D2CE4D74ULL, 0x34B324F7155FAD1EULL, 0x21B408E5173D2A57ULL, 0x48627C9814E735C6ULL, 
            0xBB27BE6DB28EC91BULL, 0x2E75D4A9C391FA66ULL, 0x654DF9CC62CE02AEULL, 0x910D763112DCD813ULL, 
            0x58007C1F9241C613ULL, 0xEB465FFAA62E527BULL, 0x59BA6C13F24A66A3ULL, 0x65558F6416AFC196ULL, 
            0xA2DFC95F78799AC8ULL, 0x152135273B5BA0C9ULL, 0xBCA6D0D902084FC6ULL, 0x40FE0662B51BC5C8ULL, 
            0x249C83872B52EF2EULL, 0x83544CD7B660FAEEULL, 0xCC47526D5431C540ULL, 0xA84743EF8C042A10ULL, 
            0x77DF3E617D960193ULL, 0x2374906788F7C30BULL, 0xD26C375A9DBC0AC3ULL, 0x581DAF4A5E330B01ULL, 
            0xC2B588A32604372EULL, 0xAEDE12F79630D44DULL, 0xD68C51B9B5865F61ULL, 0x55835BB0660488A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseCConstants = {
    0xD2E50AA24A011412ULL,
    0xFCFBA89D46E8481DULL,
    0x389B50C7E785F79FULL,
    0xD2E50AA24A011412ULL,
    0xFCFBA89D46E8481DULL,
    0x389B50C7E785F79FULL,
    0xCB1A6B1E7B3505CFULL,
    0xAAEF166EE83C22CBULL,
    0x4B,
    0x95,
    0x16,
    0x0D,
    0xF2,
    0xDA,
    0xF2,
    0x9A
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseDSalts = {
    {
        {
            0x3ACAE29B46356843ULL, 0x02ED55281A304139ULL, 0xD72B96B6377C6427ULL, 0x056A33D0C96D2DCDULL, 
            0x360507C83993A5CCULL, 0xA41396087135A03AULL, 0x8F3AA6F06234AD51ULL, 0xA8235A2CBFAC7270ULL, 
            0x9DCA42BEE6438D36ULL, 0x5DDA072FAF58595BULL, 0xDDECD868D4EFCF5CULL, 0x0C9E8D4722FCB981ULL, 
            0xB30A5DF299134538ULL, 0x5F9AFEC8C9767320ULL, 0x7583F47038CCEB52ULL, 0x7BA068A61AA5C166ULL, 
            0x74866BE4B4D03A94ULL, 0x1B05C25BD1184635ULL, 0x7F963FF2D9BC0622ULL, 0xE367CC77A62A14C0ULL, 
            0xA76558DC92C81EFDULL, 0x8748B8C5DA9D14B7ULL, 0x0CBDE1B23770CEEBULL, 0x61429E4107641129ULL, 
            0xBCBE1B5D80E10F84ULL, 0xBCCF7548F4691CC0ULL, 0x842B3381B80D73E0ULL, 0x16FBFCF59361E097ULL, 
            0x8A0CD0021CFAF4AEULL, 0x735F945667DD010BULL, 0x920C561CE9440C59ULL, 0x5A235F72DEC21974ULL
        },
        {
            0xF7D3E5D6F37DD3BBULL, 0xD120334026F21E10ULL, 0x9D93ADE32D490B48ULL, 0xC2FE19C5F426CFAEULL, 
            0x9FE74277071C0FEDULL, 0xE76A0A73F5EE0392ULL, 0x31455F099AB1AB3CULL, 0x69F0C1D1503C9000ULL, 
            0x52F15FDDDC3F35BBULL, 0x8518B6DAD820FD16ULL, 0xD9AC103AD1B2C176ULL, 0xA95C9A0E2B7A4D5FULL, 
            0xD3A64AD13E79F557ULL, 0x9370CC7B1EDF833CULL, 0x8336E3FD55C30161ULL, 0x8C49A585D952BC66ULL, 
            0xE034206A7A6C60B5ULL, 0x1799F2EE71D7B06CULL, 0x17459DCBFE6CB2DBULL, 0x2961D505082CEEBCULL, 
            0x0F69839A04ACCD34ULL, 0x238382309447A61EULL, 0x90D0576F558995C3ULL, 0x4D0839A8AD95331FULL, 
            0x9E127094C62079C8ULL, 0x5FBE3F19A786BAD3ULL, 0x147F7B099B48BE69ULL, 0xEC72DF48DE21A6ECULL, 
            0xE59FF0B662177A1FULL, 0xB0EA539D89270C7EULL, 0x6DF8EBBD0ABF24FFULL, 0x78EFF70BEE8147C6ULL
        },
        {
            0x42140DC1D508265AULL, 0xBE2ECB71E02E8894ULL, 0xDFA910A5BE895310ULL, 0x1DA1594797933314ULL, 
            0xEE5FB5C55B147894ULL, 0xE05BC1BA8F39124DULL, 0x426D1ED2B4BDA00AULL, 0xB75211BE880E0909ULL, 
            0x2B058BB5F488E94CULL, 0x1C6763BA69DCC395ULL, 0xF7AABD75B5BD26B7ULL, 0x7C09479D38B90B84ULL, 
            0x800B9781E8BBA2A2ULL, 0x0DCF30EB4C7148C0ULL, 0xD02CAB1B5838AC00ULL, 0x72259EE2E11F615AULL, 
            0x07B04C82D734BE83ULL, 0xE3395BC0C2094F3EULL, 0x16329ADDDC21CB95ULL, 0x2CC7CFCF724CFF27ULL, 
            0x0B515AA91A11D557ULL, 0x34D4429E3612C608ULL, 0xA612D84E12742BB1ULL, 0x34ADC7EDB755BF30ULL, 
            0x5B102A1B3F2885C3ULL, 0xCFF1C5C02B570AF0ULL, 0xD6D4EF4AC2498D12ULL, 0x6670ADA42AC66A97ULL, 
            0x035253D4582A11F8ULL, 0x95BF1A3FFE7BBD2DULL, 0xF2760887092B69D9ULL, 0xBA29CEF302B4899BULL
        },
        {
            0x2372CC0D325594ABULL, 0x2BA321E2798F890DULL, 0x4C2AF1D19B2276CFULL, 0x42084173557CF513ULL, 
            0xBDBDD65D350B28C9ULL, 0xBFCE4E6899CED7D1ULL, 0xDC4F517633741A7AULL, 0xEBC7E26BD36E2D9BULL, 
            0x91985B9B50C41AB9ULL, 0x1E1AD8E2C68F3D17ULL, 0x2DFEEBA132CA4941ULL, 0x7FE70781EB859B8EULL, 
            0x05EA499ACE9204D1ULL, 0x67FA3D41FF98D428ULL, 0xE56EC56767447FAEULL, 0x58FE9CA912348F11ULL, 
            0xF26997A7BB023A32ULL, 0xD38E07A8B18542B9ULL, 0x51CA30FD0A6ABA5BULL, 0xEE6273EFCF9377D7ULL, 
            0xF4E8A6DB691A980AULL, 0xE6CE80E5F2446901ULL, 0x8B8346BCDFFFF24CULL, 0x726E0831D4279EF9ULL, 
            0x9733F80E55BFB83EULL, 0xD02F6E333885112FULL, 0xC4B384D79BCB5EADULL, 0xB984DDA98C634675ULL, 
            0x9E89679618987CD0ULL, 0xECC8303CC59D82D2ULL, 0x670412179027960DULL, 0x6E41F449899B5681ULL
        },
        {
            0x42BECB38DC7882E5ULL, 0x034D3477C3BDF180ULL, 0x6524EC999185F87BULL, 0xFE68B2098C6E8EEBULL, 
            0x968EAF66201B460CULL, 0x050313957D1BD744ULL, 0x7E9B1E52B6A80CE6ULL, 0x06001BBD4CCC296BULL, 
            0x43ED72AE1A5AC591ULL, 0xDDCBD2C53039EC17ULL, 0xFD965A6669EAD37EULL, 0x571A8378930117BCULL, 
            0xE1FDA1A46A8CBC06ULL, 0xBB01ABE0FE396976ULL, 0x63BAE2D8D21A5383ULL, 0xA35673F94EE346F1ULL, 
            0x8512922375749E32ULL, 0x2222EE9281ABB041ULL, 0x3D1EBB519C3AF7C7ULL, 0xA12DB3A01334CBB0ULL, 
            0x2861FD746C00A473ULL, 0xE35DC155A803AAE3ULL, 0x465E970421ACA4FCULL, 0x22D6386FA9AE6167ULL, 
            0x76260B8F5594915CULL, 0xCB6E83E1A6BE294BULL, 0x07D4EB682BCB18D8ULL, 0x8CB17260028E2AC2ULL, 
            0xEC6B4AC63CD4CB2DULL, 0x6ED2954F28EF86FCULL, 0x0B35923B0CE48D7CULL, 0x5F08D4C8D1FE8CC4ULL
        },
        {
            0x5DE0688F45A04B67ULL, 0x3ECFE8C030F61D9AULL, 0x875C35C3973D6B26ULL, 0x6C165FAF0222A579ULL, 
            0xF0F94E75E004734AULL, 0xC576E31D06B6A37BULL, 0x54FE7B7605F86DBDULL, 0x62A3F03A515575B9ULL, 
            0x29DE9B17311BE977ULL, 0xD3062E7D6D1528CFULL, 0x5EB0490A5D839D0CULL, 0x3CF29D4BE56801D3ULL, 
            0x0CAD40C585C58F34ULL, 0x661A911B2D2152F0ULL, 0xF941D6979383359DULL, 0x9A6B8C80272DA528ULL, 
            0xC3EF1FC6687C67BCULL, 0x5C41613463252C56ULL, 0xEB21DDDB1F8F1B91ULL, 0xDECED445523CCE4BULL, 
            0xE10312AD994AE586ULL, 0xBB5835E4A938A20BULL, 0x8A113A33EDD24724ULL, 0x04F9C719095A8042ULL, 
            0x662214A4E3893D5DULL, 0xE37D4DD0173F807CULL, 0xFE626108C1686D7FULL, 0x5B405839D4B6E724ULL, 
            0x074C523F7057DF3FULL, 0xEDE3FD1CB1FE9AF2ULL, 0xC8ECAAFF35D67D81ULL, 0x78DA8C8427EFE1CCULL
        }
    },
    {
        {
            0x3BB43F488EA73B00ULL, 0x4ADCE760CB09C70EULL, 0xB569B16286D911AAULL, 0x5DAE2A8F230910CBULL, 
            0x46609C5643ADE081ULL, 0xD11E25402BA4DF77ULL, 0xF695892DC1A38FBDULL, 0x84194A153033A15BULL, 
            0xA9F5358DFCD05A8DULL, 0x54B3BA12D4028AE6ULL, 0x9DDBEF7613CD4117ULL, 0x8477CEF2C9B4956DULL, 
            0x11C6540711793545ULL, 0xAFB119C3E4F20076ULL, 0xC7666A661C640DADULL, 0x48CDD2DE8D2C351AULL, 
            0xE1D8EF84D44AEF37ULL, 0xC48756632D2640CFULL, 0x4541DCA03CAFA2A4ULL, 0x4D0D853C81C7BA00ULL, 
            0xA23B548BD6B6D5C5ULL, 0xA1C0B4C3E52C4A6FULL, 0xA9AEC54355F953FDULL, 0x441AA958FA193F18ULL, 
            0xAB1A55B5F1A87A7AULL, 0xEF56C5E661D10C30ULL, 0xD62E8F0B9C03955FULL, 0xC7E9B24B7F5834B2ULL, 
            0x0C3E7DB1249B34FAULL, 0x3D60431E0B0C4357ULL, 0x1E5AF18E69F0BC02ULL, 0x6ACD2DE042CED105ULL
        },
        {
            0xA8CA7010C7DCD2D3ULL, 0xE7A6DDB14173A265ULL, 0x58ACA1F3E83354CBULL, 0xEE867117A411479DULL, 
            0x34AA128D9342678BULL, 0x9B7AA1F061F30FB0ULL, 0xF69546157CAA5FE9ULL, 0x934CB3DB68754871ULL, 
            0xFA1F91E0527BF2EDULL, 0xA80F10BE31BDE727ULL, 0x436DEAE9DC2B43B5ULL, 0x290115CB2BA7D50CULL, 
            0x857FBF8C32A622CFULL, 0x0658859146D73590ULL, 0x1AD5A5A4436E075FULL, 0x30311DC18C3547BAULL, 
            0xF10D2A8BD162ED86ULL, 0x99608E822A09CE1FULL, 0x2D143B1C6C58B5A9ULL, 0x602BBA2E9E46FFA9ULL, 
            0x608E992F87796ABDULL, 0x1659207E410BC471ULL, 0xFA462C16B3CBCBE9ULL, 0x077145ABD11AB182ULL, 
            0xCDCE2A83A45EA569ULL, 0x38C26ED98CDC1D91ULL, 0xFD3A7CEC7BA0F28EULL, 0xE2B8300322A83EF7ULL, 
            0xBD01064D563B2E1EULL, 0x9475086EB3F03C6EULL, 0xC5EEDC04CD606177ULL, 0x9B912A44C1C94110ULL
        },
        {
            0x4778159AB714FBFDULL, 0xE5A3AAC709E582B1ULL, 0x3DF6617A62E62FFAULL, 0xF9A8D1D9CDD9DF46ULL, 
            0xB7376D1BCBC0CDF9ULL, 0x607DC2DCF405B34CULL, 0x809E94C3AE9C322AULL, 0x7458981DFC5333A0ULL, 
            0xA0AFEA3A9F1BAEDBULL, 0x5C2CC91DF7939F7FULL, 0xD42734A4ACD2C56CULL, 0xB7A2C696EC9CFDC3ULL, 
            0xDFDEC71B091B67A2ULL, 0x648F9F9100E3E746ULL, 0xB35F48C7261054DAULL, 0x340F305D34E1379CULL, 
            0x11EE0AB8CC56F65FULL, 0x30A476E1627C1144ULL, 0x6BFE0658007CE13BULL, 0x2FDDC2FB7C3F254BULL, 
            0x144A9B8664D86CE9ULL, 0xEAC39E55322EAF84ULL, 0x2C93F64B1D9792C1ULL, 0x902C815F63E0FB26ULL, 
            0x1E60E8D7DA32C136ULL, 0x40611BAE00A36AFCULL, 0xAD00B10877162FB4ULL, 0x4ED24FCBECF6BD0EULL, 
            0xA1960CD7164A82C7ULL, 0x662A2BC845879BABULL, 0xF3D3FED15BEEE7CCULL, 0xE64CC4B8F9ACA749ULL
        },
        {
            0xDAAB9F7F16DE6BA3ULL, 0xB5F710F9F650D154ULL, 0xD7F2642A430642E6ULL, 0x5492E8769BFF85BBULL, 
            0xF2049B3ABA0B30D6ULL, 0xCAD54CA96FD7E225ULL, 0x95CBD7C3CA9E8D9AULL, 0x834D89ED16E1E446ULL, 
            0x86BF4F4CFD9346F8ULL, 0x3E75B570B33253BBULL, 0x7A1A858717169AD5ULL, 0x5BD76BCFB955D0D0ULL, 
            0x0A96D17735836E15ULL, 0x443C3752BB4AA7B2ULL, 0xDA1213CACD69AAAEULL, 0x654F99B4CB130955ULL, 
            0xE8B66E5294C19762ULL, 0xAA25560F8B6B9EF9ULL, 0x8F054F0A519D6C14ULL, 0x2E7A2929A600757AULL, 
            0x5D43811D759530C3ULL, 0xAD8A95E915387EE7ULL, 0x3DC9F1D739B62561ULL, 0x088330F40D620DACULL, 
            0x8D5FED8CFFEA28CBULL, 0x94825E03E3D3A43AULL, 0xE9EC2665B7E437C7ULL, 0x7696A924D0BDA0F6ULL, 
            0x0339EE6B16D66070ULL, 0x9D7F22E76F72E25EULL, 0x773FFE9FC40FD918ULL, 0x90027311F9CEAFEFULL
        },
        {
            0x8219619A09872AC5ULL, 0xDA434267EC8926CDULL, 0x4BD65C9E56CA91B4ULL, 0xA29A71F13DE61EDFULL, 
            0xBF031E3E04982D65ULL, 0xCC6843DA7F90745EULL, 0xAB5390EAA9D0045AULL, 0x0B7B7CCC4C40C19FULL, 
            0x084A21E7C4DA7206ULL, 0x22D7C1EB544B02BEULL, 0xFDFA5A546B850B42ULL, 0x89DD53DD790D2C13ULL, 
            0xE140E23222BF7805ULL, 0xC2AC3378EAF13E07ULL, 0x376290DFE071D221ULL, 0xBC8A5A3DC90E458FULL, 
            0x8771AAC8D4F5887DULL, 0x88B1BE30CE3C1476ULL, 0xD484068FB09964C7ULL, 0xC17163DDBB469E58ULL, 
            0x778CDB04E159694DULL, 0x050947AB53162783ULL, 0x175DE22E8333C433ULL, 0xE7A5B7F98E4B6FCDULL, 
            0x859924A7575D8DA8ULL, 0x68B0C67723039639ULL, 0xF4B0175BA999BAF3ULL, 0x0C7BA20ED056459EULL, 
            0xEED84EA2BF80D792ULL, 0xD0F2CAA8CEE6D79CULL, 0x1DF93FCF6841E5B5ULL, 0x45C7A0ED8CA5638CULL
        },
        {
            0x7C4EE9D635B750A1ULL, 0xB6511AE6337BB40AULL, 0x0680A7149AC1229AULL, 0xA8A81F47907F3A4AULL, 
            0xE5EE5D5056400F21ULL, 0xBD08530E9F66D649ULL, 0x719B02C00AA1B61EULL, 0xBE0FB0C8E9CFD760ULL, 
            0xF78F778B315B9CFCULL, 0xD4280199F05730D1ULL, 0xC8ABA5980AC9E616ULL, 0x8B9E2C65BCD20406ULL, 
            0x809DE7908CB94C01ULL, 0xFFCEC2DBD2D3557BULL, 0x2141FBE046801845ULL, 0x4F6A5FD876D92167ULL, 
            0xFFC4BB509B208B22ULL, 0x197B92D788B0A54CULL, 0x4329560E8B421943ULL, 0x5FD5227D298905E0ULL, 
            0xECF99E170CFF7564ULL, 0xB71FCCFC567B253BULL, 0x665F9A5F865B1C51ULL, 0xBF77E5E1D79DB3C0ULL, 
            0x4BCA1EE8299C0936ULL, 0x08E62292F509526BULL, 0xCE929DF102C55B7CULL, 0xA6715504F7480530ULL, 
            0xFF247ECE608E7C86ULL, 0x8BD9A46AB485D4E4ULL, 0x0F218F3669DC0B2DULL, 0x3ADD56AFDB3262F2ULL
        }
    },
    {
        {
            0x394FBF5364501DC5ULL, 0x59404F1B69AC2D75ULL, 0x087A5BF06FA8F1E5ULL, 0xE0BE5B2F080CE3C3ULL, 
            0x06D869C5D2738450ULL, 0xEFAC3F7AB24DDC36ULL, 0xD3FFF84041456EA6ULL, 0x63E46DC63656B75CULL, 
            0xFA8AB1A239A6B019ULL, 0x825B9AE95AE87221ULL, 0x4A888CC0FBCB4ED8ULL, 0x97B1ECA6FFFB0058ULL, 
            0x51644C52E5C5CE85ULL, 0x2145894E7BD52464ULL, 0x6999FBBCB27B71B6ULL, 0x483E3CA535944115ULL, 
            0x644F71D1A5D5A7DBULL, 0x304757515B88ADB7ULL, 0x94DE3268DF9F08EBULL, 0xA1E8F71B3ED5E433ULL, 
            0x0B058D5F962DBFE5ULL, 0xBD1AA2790A38031CULL, 0xB796F4964B23D2E2ULL, 0x9C80FBD5CFDD6051ULL, 
            0x3022DDE8621A7A7CULL, 0xAE6F08743FB92D32ULL, 0x22045FDB53914182ULL, 0x6F825920CC952DBFULL, 
            0x3762A2CC22693917ULL, 0xFD2559D35DBDD307ULL, 0x7217049A1F861A41ULL, 0x4994D8650C341EF5ULL
        },
        {
            0x9026F027A00F60F6ULL, 0x592F7860A8F3889BULL, 0xD2D62ADB8C17B981ULL, 0xAD511EC3BC3245FAULL, 
            0x79269EF1445215DCULL, 0x841A88B6EAF08138ULL, 0x424055DF642DFAD4ULL, 0xFAC8E24EBED74BD5ULL, 
            0x67B3AA1BA8BBDCDAULL, 0xDC820190EBF20846ULL, 0xB606BB68FD12F663ULL, 0xED6DAB8B986AE1ABULL, 
            0x7A7AB98A3C6CC594ULL, 0x104399C845A5B0D6ULL, 0xC3074A2787661A0AULL, 0x35BA474F31C79C18ULL, 
            0x7C1CFA9A4D5B08A3ULL, 0x8462078B4E02CF96ULL, 0x2FDA0646E8AC466AULL, 0xBFF32CA0249FF676ULL, 
            0xBA60D933AEF9E3D0ULL, 0x99D5460E006AB82FULL, 0x77C3126A9841FCEFULL, 0x8F36CD879310E336ULL, 
            0x4936B9BFCAFE5D67ULL, 0xDAEE9F3D2788FED5ULL, 0x84512DD014E9B828ULL, 0xE83BAAD2712FEBA1ULL, 
            0xE6516EB63147E0C8ULL, 0x20DC6E01A04FFD13ULL, 0x672BD95DEBB5FCBDULL, 0x0C4BD4F61582AF3EULL
        },
        {
            0x6C12BABC692ED210ULL, 0x0FCC3F8051BAB8F9ULL, 0x146ED5F896D3C80EULL, 0xFD80FC26F38E0994ULL, 
            0x5F2C89E51F33F423ULL, 0x7739FA44C0AAAA33ULL, 0x5BFF00D3621972E4ULL, 0x8C7C207FB1BDEF01ULL, 
            0x18F863FEF27A535CULL, 0x94B1A5704F33F145ULL, 0x0BB66776CC21E041ULL, 0x97B98744A83D6A4AULL, 
            0x96710B4297FC3C84ULL, 0x1BEDEF1AD01C8817ULL, 0x59E30BA62E4C521EULL, 0xA436BEA0937CA23EULL, 
            0x6C034F9079C81A79ULL, 0x516214C520CD125DULL, 0x89E531429675F0E2ULL, 0x0A4475162B5CB752ULL, 
            0x9C66D12E70C4E708ULL, 0x5A41FFBD57B0DF70ULL, 0x659B89FF54256152ULL, 0x4859E880FD650B0FULL, 
            0x5E36052F5D2464F6ULL, 0x7EB2BA703E2639F8ULL, 0x73D71173B781C65AULL, 0xCABFC8B670972AC9ULL, 
            0x2104748D99EA7524ULL, 0x275B2D2BE44BF2FAULL, 0x99DCAA71391FA167ULL, 0x52EF07EDFC15612EULL
        },
        {
            0x418A29241E1AE882ULL, 0x379A2A624F2FF78AULL, 0x6747E20E74C4C1AFULL, 0x7D010256510ADA82ULL, 
            0xC96241079B7E820BULL, 0xD498D2BCD0EB6877ULL, 0x14D151FCBC2855EEULL, 0x4C9A9798F919E776ULL, 
            0x6770C1924A552609ULL, 0x6616591E5396C2D1ULL, 0x75A62786F224402AULL, 0x34AF241C781318D3ULL, 
            0x7E4D7990694A0939ULL, 0xBD5F65015E8BEEA9ULL, 0x231DC76E132031B3ULL, 0x3A54181EC9317D94ULL, 
            0xC60A259C1652D771ULL, 0x07111B8A4D4812EAULL, 0x25CFBBC2782FAE0CULL, 0xECD5DBE3D8BD05D7ULL, 
            0xCB90EEB3A8A8CBAAULL, 0xE2CE012EF07C1878ULL, 0xE04C2AAB7E7A8625ULL, 0x925723E8A579A503ULL, 
            0x77E1E8335538BA38ULL, 0xB2EECB98D49DE314ULL, 0xEDA410F05D7E3C6DULL, 0x76AA70BB5DA607B8ULL, 
            0x8FFF6A12E2312D6FULL, 0x1DD91327A1ED5CD0ULL, 0x02CDBD2FD5A0CAC8ULL, 0xE4ECF14FA7150652ULL
        },
        {
            0x17FD265B1A74B004ULL, 0xB737EE8DF0F54558ULL, 0x38D916FA6B177F53ULL, 0x5293ABF6C910A39BULL, 
            0x794B77D678370EE8ULL, 0x4072DF5F7F2B19C9ULL, 0x3266B014E2F1B8B1ULL, 0xB960B370D8A8696CULL, 
            0x0AE15403124A2F6DULL, 0x2300E678E84C634BULL, 0x5BF9B14EB756CB58ULL, 0xF98724B0D3E9D4FAULL, 
            0xA14ED3A5C9CE0909ULL, 0x2789533535751028ULL, 0xCD556BB897F6A316ULL, 0x8E6538AA49D25440ULL, 
            0xC50EA1075FE9AC67ULL, 0x3F90377E8F8F0328ULL, 0x29C9247930DEDE4EULL, 0x252D1B570F8D0D72ULL, 
            0xB58BBA41363D5CD7ULL, 0x0C048DFC923BB1E3ULL, 0x9B547DF2F9D458C1ULL, 0x7194760655863D4DULL, 
            0xBC84CDECEF8D2ED7ULL, 0x9685000A9B908FC3ULL, 0xA22E5E1A9CB3368EULL, 0xDFA7A405C5BDD9CCULL, 
            0x1E61FB45C3DE065DULL, 0x3ACEBB453A60B326ULL, 0xFCA97B76CEB09CFCULL, 0xF7A8E03AF9CFE3D1ULL
        },
        {
            0xE8379D2D86A4DBD7ULL, 0x19F127F15513E8C7ULL, 0x6E96C8F73AE7ACE2ULL, 0x4788F8F631771F3CULL, 
            0x9C886F1367077F9DULL, 0xCF9383F0E66F2954ULL, 0x1BD1864F14662E03ULL, 0x622561A6AFE61005ULL, 
            0xBF093FA1A6DAF0E9ULL, 0x58962EDBAD63001CULL, 0x26675A96D24F715FULL, 0xE2A776B3194AD102ULL, 
            0xF7D6F3E24D272B25ULL, 0xAF15CD5B12264471ULL, 0x705B152472EC0316ULL, 0xB7A83B4B2EBECBF3ULL, 
            0xA811E70A2D0B6EC8ULL, 0x939546C85D4210C4ULL, 0xADED17D33D2E07D9ULL, 0x01C030E5989AD0BCULL, 
            0xEFABF067673032E3ULL, 0xC05DB72A8D06D56CULL, 0xE3B6C3E78FB665E9ULL, 0x36EE281D746654BBULL, 
            0x75DEF7BAA373D561ULL, 0x81E03C3F9B42C811ULL, 0xA689270F67335B13ULL, 0x8CEFA2475A6DF794ULL, 
            0x70DCC897B1437295ULL, 0x6D69A9F9883BB103ULL, 0x9E17D541EAC81DB0ULL, 0x73ABB41C7D20260DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseDConstants = {
    0xBF0CC55A9C1759B4ULL,
    0xE4A993259DECB313ULL,
    0x15A939BD760C0B4AULL,
    0xBF0CC55A9C1759B4ULL,
    0xE4A993259DECB313ULL,
    0x15A939BD760C0B4AULL,
    0xA15280EFBA83C6A8ULL,
    0xD1513CB2A2B387F5ULL,
    0xFE,
    0xB4,
    0x31,
    0x20,
    0x9D,
    0x55,
    0x0C,
    0x28
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseESalts = {
    {
        {
            0x0A3390A3B49BD6C1ULL, 0x0FD2CAD43ECE689EULL, 0x9822958390989327ULL, 0x862E927B23D8002EULL, 
            0x164AD64D6D294650ULL, 0xEC2A4E2363A32AD2ULL, 0x3E54E664B04484BCULL, 0xA5671CFA49B560FCULL, 
            0x869BEB4A2AFFADD6ULL, 0xA8AAE2097EBC798FULL, 0xED8834D5485771A0ULL, 0x468E4A30C622C57BULL, 
            0xFFA93D05A623E5EBULL, 0xB0D2EA7004BD22DDULL, 0xAE265D98B23FC62EULL, 0x6EEB88D3FA0B1A68ULL, 
            0xB4C476F14BEDED59ULL, 0xA5AFFD9D02B1BAACULL, 0x0BB650D408CF50A0ULL, 0x479F863E47EBE736ULL, 
            0xEE83A8923C66028EULL, 0xB75519F9B50FDB2DULL, 0x09987C11B566E0B7ULL, 0x82F5C4234F368FACULL, 
            0x09EF5F0A6836DF83ULL, 0xE757D9DE4AEB5137ULL, 0xF55C527FBE59999FULL, 0xA3ECB5637DAA490DULL, 
            0x1A7C017A6B1F555FULL, 0x279F39ED887216C1ULL, 0x1B04CE1DFDA0E482ULL, 0x05606ABCAEDB4BC4ULL
        },
        {
            0xDB42205EDAE25442ULL, 0x2F634D67403F3C22ULL, 0xBC44915281EDFFC4ULL, 0xA3676F56DFBB0722ULL, 
            0x49A977B0A50731D1ULL, 0x4D926C5B8F400D62ULL, 0x2EDD595A4B7B8D59ULL, 0x99F902EA03F94AE5ULL, 
            0x7A8D77D7BCD127B2ULL, 0xA570C7D5582412BAULL, 0x78CC8ADCADE5A9EAULL, 0x7988DDB9C3D993F6ULL, 
            0xC35B981559B0A6CBULL, 0xE12E5EF2382D4A8CULL, 0x1C525B2E51A4D47BULL, 0x0AE85BE20EBFDE96ULL, 
            0xBA6EB7263D5744DEULL, 0x60AE8236875A05D7ULL, 0xD4ECC52CB4A11766ULL, 0x28A1C421DBE5C2BDULL, 
            0xAA6A3BAE8B850FCAULL, 0xDFC239339009DCE3ULL, 0xCF8A3C94A5BDC6D3ULL, 0x080AC1ECCE3DA4F2ULL, 
            0xEDD31080B5AEDE6AULL, 0xF1F46542A542FE3CULL, 0x35D2A16BF94C4411ULL, 0xDE27511FFC3014D1ULL, 
            0x2A52320D74013087ULL, 0x682B1644261A8631ULL, 0xA2262D2A2A5FF7CFULL, 0x6D14EF7769B9AAD6ULL
        },
        {
            0x45D879C108172157ULL, 0x70AE10AFAA44225FULL, 0x54CC5D955D74E3DBULL, 0x8278BCA38EB92CFBULL, 
            0xB574B964432CEEFBULL, 0x8E63D57D3D6AD651ULL, 0x5A6E66B2C03A45B1ULL, 0xDFB924AFA3B0B34DULL, 
            0x2A70FD4200EF1783ULL, 0x745DBBBF387399B8ULL, 0x2229A7F841469293ULL, 0x46BEA221E3B9B9E9ULL, 
            0x6BAF15ECE40B8EB5ULL, 0x024447425E1F4815ULL, 0xFECEF7B16E6CE4D7ULL, 0xBA9B5A3B1B931AF3ULL, 
            0x16BA43057A0F9B48ULL, 0x66E86A06F3602F83ULL, 0x634304EA9786E032ULL, 0x7FAD0B2B4DFE5427ULL, 
            0xD07F3456E843F1B8ULL, 0x1B45BC365A8D6DCBULL, 0x577D174BA641B44BULL, 0x2D24A04356BC90DCULL, 
            0xBA8FD04CEA52215BULL, 0x68FE795313820EA1ULL, 0xE87C3C03A2C5CF84ULL, 0x7981C7EDE89C05AFULL, 
            0xF3F1884F78D48AF5ULL, 0x5251183654FC0F78ULL, 0xAD2BD5B44ECF6351ULL, 0x9410FE26E2D1475CULL
        },
        {
            0xC1AD28017A8ED32FULL, 0x6BBAC33562AEEEC8ULL, 0xD8C82546C5953DF5ULL, 0xBCF89698417443CFULL, 
            0xF119ACC9DE8DD975ULL, 0xA4873208A056E074ULL, 0x9BF18A02BD51A454ULL, 0xBE541008C1383ACAULL, 
            0xBE2EB885DC30410DULL, 0xFE588BF11059721CULL, 0xDF9403196588ECE6ULL, 0x2AD3698EF0C95FBDULL, 
            0x8BBFC8D429DCC178ULL, 0xC46C0777C823DE99ULL, 0x1E7371B614AE7690ULL, 0xBB280AA5737050B9ULL, 
            0xBC7D6F87C0049DADULL, 0xFF0B0D448C4EC34FULL, 0x597870F403FEDF64ULL, 0x842795147FA0171FULL, 
            0x1CDB5C6A66A438FBULL, 0x524BC7F4ECBA9130ULL, 0xCAB38CC81498C734ULL, 0x10684865B7C44DB1ULL, 
            0xA55F519323D83355ULL, 0x842747680329B5E4ULL, 0x7394CCA6F292398DULL, 0x6D4AA6252C8950FAULL, 
            0xB775D453C2B8B820ULL, 0x3ABAB7485E418550ULL, 0xEAF8927500AFD3D5ULL, 0x28379F385223EF88ULL
        },
        {
            0x615F05089032116BULL, 0xD0F0FA37DD02963BULL, 0xBC76AD5549F85A7DULL, 0x42F5F012C32563F1ULL, 
            0x20EF814FDCB3060FULL, 0xA31A0EFA09948157ULL, 0xA75985A017678375ULL, 0x8A0D4D7D5FC8CE02ULL, 
            0xE470069E55A08862ULL, 0x1BA4CB327FFE26FDULL, 0x18A45B634792AA0BULL, 0xC22F55F14C3D5E80ULL, 
            0x74512ECC8F9307F0ULL, 0x85F7C72B21707061ULL, 0x11C9A27675EF314BULL, 0xAB5CFE6B25BFA1A6ULL, 
            0x79C2E1A0D40E7324ULL, 0xDE01F51B2F770FF2ULL, 0xD320BA4025405134ULL, 0x336E670871FACF13ULL, 
            0xD4703D408161C078ULL, 0x9F8F0F1E5ACF01D6ULL, 0x9F4C8B832862EF7CULL, 0xB1730C598F992252ULL, 
            0x81B51760D052D0ABULL, 0xE55C59042761109FULL, 0x4D430E8A9A438AFEULL, 0x480A3DEBDBEB6ADCULL, 
            0x93EA84F8EFB9A318ULL, 0xFA1A6556D6D066F4ULL, 0x37B7CA6E95EA774BULL, 0x419ED887E2637CD5ULL
        },
        {
            0x9CD6A74B5A5C0B8EULL, 0xD47954326BFB95DFULL, 0x1368C457A8A9606FULL, 0xC700638314F32195ULL, 
            0x979768759CD2B781ULL, 0xB68F6071591E8138ULL, 0x38B92E22EB4FB2B6ULL, 0xE99AC849EB71A924ULL, 
            0x507E2BA28A8FCB84ULL, 0x0145C7665C8363C1ULL, 0x3FB7E288A521A941ULL, 0x7DDEFEB4787D701AULL, 
            0x0F77EF23C34E3E99ULL, 0xC2E237F95BDE733FULL, 0x9284A4F3740ADC0AULL, 0xA86DD1227829E23EULL, 
            0x41B3EA836102F743ULL, 0xBE9D7332CC327CC6ULL, 0x088DAD78F897917FULL, 0xF5E4A5726E566BA4ULL, 
            0xEDE649051A941BFFULL, 0x3FC15869F0A6176FULL, 0x46D27CB05361C757ULL, 0x369C45CC31325ED4ULL, 
            0x2EE948D1A4ED9251ULL, 0x6DA94346AC538001ULL, 0xE080DE3477D0DF15ULL, 0x148D66CC417149ECULL, 
            0x69A328FAB14C01C2ULL, 0x4BA15E58572FDA74ULL, 0x2539961F59469A65ULL, 0x56BB18F81074605BULL
        }
    },
    {
        {
            0x7C9E90C25C75DA70ULL, 0x737DC2C334A3678AULL, 0xA5EDB7972B8B3F63ULL, 0xD62FB3BD44441EBFULL, 
            0x83CB4762E8CD9811ULL, 0x4A51E02F44822805ULL, 0xA76A747D27E15DD0ULL, 0x55D4AA8FD9430070ULL, 
            0x1C5BD810C40AE7B7ULL, 0x65F5F65A5A546232ULL, 0x7F9A7D2EEB0DB245ULL, 0x6405D68E78DFD53BULL, 
            0x0D05B2D4FAC1F6D3ULL, 0xE9D6655AA94B00F0ULL, 0x1242A5601579A669ULL, 0xFEC0E70A10E59A04ULL, 
            0xF4D23D9F8807FC07ULL, 0xAAB6EAA2945732A2ULL, 0x8CC8759F234491CCULL, 0x3F0B311E53A5D961ULL, 
            0x9A94283546E3A94EULL, 0xB77331904D490DD2ULL, 0x297F720453BD8CC4ULL, 0x6F1592B332AA795AULL, 
            0xB0AE228029A3EED6ULL, 0xCC2C4F7ACE725178ULL, 0x71FB204A2D3D4472ULL, 0x013F998E50D739F4ULL, 
            0x97F47CFB146BD989ULL, 0x813C201350E2DB6AULL, 0x5829253705F3E475ULL, 0xC21EBA7B6556A69BULL
        },
        {
            0x8505BA7A5E725DECULL, 0x16BA70E68AAD6C01ULL, 0xD36FE911429F50BAULL, 0x1C9B72BF89F579B3ULL, 
            0x8F50270AB9A33C75ULL, 0x5E2A353F6945B1A4ULL, 0x643295C7486D5BC8ULL, 0x519F128EC3464F97ULL, 
            0x8DD8DBE717A4A3ACULL, 0xE1E7AC21176AD5CBULL, 0xE724DA84CE223C83ULL, 0xAA3633B9739E2FC8ULL, 
            0x1BBF09045E147756ULL, 0x71FEAE0884785351ULL, 0xC138AB5D5F540A69ULL, 0xC0CCC3049E67E5D9ULL, 
            0xD697343D971D6026ULL, 0x4198AFBFB0C5E6A8ULL, 0x4F8139E2112530EBULL, 0xDB8E8A8D3B785646ULL, 
            0x2AD32C47005FE5E6ULL, 0x79D37525DD20B39BULL, 0x4DBBAFF8C5C85DD7ULL, 0xA0DD86754425C0EDULL, 
            0x8B847A121F582254ULL, 0xB54F601CE7F74DA8ULL, 0xB3DA98FCB9A283ABULL, 0xF6C4D69F6A88472DULL, 
            0x4B17E6EE0E76F7A6ULL, 0x6898D957F99B103AULL, 0x494E84029924FEB4ULL, 0x884236EF2FD83BCFULL
        },
        {
            0xA318A3A327AEE8D8ULL, 0x4CA48E74180E5320ULL, 0x6491EBE8CE1A6D96ULL, 0x53B7C8D68EAAC512ULL, 
            0x973501858D5BF08EULL, 0x023E70605C6D3447ULL, 0x9263FF4A5F23B6FCULL, 0xC4B0CF6710C04AC7ULL, 
            0x83B7874AE343BB13ULL, 0xB33959C90EDEBC01ULL, 0xCCB0BB0B2370C2C5ULL, 0x14DE92BAF9A08C15ULL, 
            0x731E0DFD52713FD8ULL, 0x76DA88DBFFD8158DULL, 0x37FB049D386A8F8BULL, 0xF30C0E09CA7CC123ULL, 
            0xD2FEDFF00863B01CULL, 0xD03695038D0BE968ULL, 0x4F261A3CE4901DB4ULL, 0xE824CD611335CCD7ULL, 
            0x093015EF81E4C708ULL, 0x50DB6A527AA305DAULL, 0x802E2CCB80AF055DULL, 0x14791E6C989D5D1BULL, 
            0x1388AC8C48516AFDULL, 0xCFE21749785C8AEBULL, 0x0CFF242FF90EF340ULL, 0x951B84DF332A11B4ULL, 
            0x437454BE5350E3BFULL, 0x9F7B6D3C83BE546EULL, 0xADDD03731BD12EBDULL, 0x0D6CB408DA3F32DEULL
        },
        {
            0x3B24287A4EC5D458ULL, 0x382040EB42DA23E6ULL, 0x72337C586ED76543ULL, 0xE56C8478D8C456C0ULL, 
            0x046EECF82A424D7BULL, 0x462D38CFAE9DEDECULL, 0x13A43AD260529C37ULL, 0xD6A2D1A414AF3DBBULL, 
            0x10D6CE5C6A75AB60ULL, 0x7E5EA806180574B1ULL, 0x91A2A2581EC12170ULL, 0x07C9217608CB78D9ULL, 
            0xCE64BF3272B758CDULL, 0x93DFEC30A9E1954BULL, 0xE6BD97689A6ACAC5ULL, 0xF1A5B17D1AC5F9DCULL, 
            0xBE434E8C9B78CC0CULL, 0x92A88E59698621FBULL, 0x16D97C649ED0D81DULL, 0x02C2F91832E743CEULL, 
            0x7285E8C6E344A7A7ULL, 0xE4B73EF25032F1A5ULL, 0xE4F14624F91FCF7EULL, 0xC43A2FD8EC0610B9ULL, 
            0xB39DB1F308E279B2ULL, 0x7E0A396C3C458BDAULL, 0x14B7C57147ED9BDAULL, 0xC8694DFD24BA8312ULL, 
            0x38D4E7544FD7A335ULL, 0x68090D6C3D5A4DBEULL, 0xFB212F5B18DB9B79ULL, 0x3AF79D9179913FF4ULL
        },
        {
            0xAF1DAFA06F1BCAA3ULL, 0xF278A15051C2B362ULL, 0xAB4772F72950D7ECULL, 0x38636A035A1C1045ULL, 
            0x46851E8B7AA9B289ULL, 0xD241587B2623D0C5ULL, 0xD0889F37FD9F325AULL, 0x45A3F0B81C6AF3B4ULL, 
            0x46AB0CA38BA9BA3CULL, 0x8C34BE1CAFF120F1ULL, 0x422EDCABADC321B0ULL, 0x0B47D6DDC6468132ULL, 
            0xCE6702EAC0B3A462ULL, 0x505B966E010D8048ULL, 0xD686925358281C9AULL, 0x94E72CD6E0EA8B4EULL, 
            0x666B1B60148894C8ULL, 0x56643CFA4BE38BD3ULL, 0xCB0281B4206E2B2CULL, 0xF0408587EEF48A89ULL, 
            0x802402783DAF4DE6ULL, 0x6F6304411DF25A14ULL, 0x4B2E845BA13DA50DULL, 0x3830823117485061ULL, 
            0x03AB677F08845DB9ULL, 0xD3EC499D7F096FDEULL, 0x2B2E75ED1E6AB28FULL, 0xDB5F7AF913D4CC07ULL, 
            0xAB911B627B3FDD34ULL, 0xD08E993010B94A4FULL, 0xF4A66E417F07753EULL, 0xEF767F575543EE79ULL
        },
        {
            0x8DEE361B90646D03ULL, 0x485FE96F39B365A3ULL, 0x06B69AD396CF59E6ULL, 0x5775F8BB8014CCDBULL, 
            0x8664033E38A7BD49ULL, 0x0E263C70E36AB7F8ULL, 0x9E6395ED063E3CB4ULL, 0x18F6DAC007147BC8ULL, 
            0xEE8D0F2E2F14CD65ULL, 0x323D719218A0787BULL, 0x999208E76FE3F358ULL, 0x39AF0D0EC3F08EECULL, 
            0xAE6C737D400E18D2ULL, 0xD1E860D13C557FD3ULL, 0x87C9CEE62DB45404ULL, 0x383A5DA05646567BULL, 
            0x46796F3363145630ULL, 0xF601DAD3463C1610ULL, 0x364F37AC1491F530ULL, 0xE0A582691AF900B7ULL, 
            0x51E79293456A4762ULL, 0x603C6C4FB129029DULL, 0xF7758D6153A86EF2ULL, 0xDE0678289B879BB6ULL, 
            0x48D83EA28224D1F6ULL, 0xDE14D60D430580BFULL, 0x594B376AA5E623FEULL, 0x66E0B7245193C2F3ULL, 
            0xB78DF223812720AFULL, 0xAD021581F8308863ULL, 0x960C7B7E0FE99D62ULL, 0xE47351631121DD22ULL
        }
    },
    {
        {
            0xD5885FB7956386C5ULL, 0x3E74AF517C045A6BULL, 0x8161E9E64F198ED0ULL, 0x190D6339FEEB214AULL, 
            0xCE4D655BD2F0472CULL, 0x7FA88CEC3970496DULL, 0xC7CFA9203FEEED2AULL, 0x24AB319822882B42ULL, 
            0x4290AF7755CD8F72ULL, 0xDDECC0C9E339E035ULL, 0x98E9FA0960F3B493ULL, 0x291071C75C765482ULL, 
            0x19F4AEC95AFA24B7ULL, 0x97B91C623B84E476ULL, 0x329FAE295E84E1C1ULL, 0xD4BEB9B8E67206DEULL, 
            0xF46C577EB09028D1ULL, 0x10657E4F7566E99DULL, 0x8165BA7994F6E302ULL, 0x9BBAB956C4A59F86ULL, 
            0xC784ACA47B5FDBBEULL, 0xCE3D22A4532C8C59ULL, 0x42225E4573185DECULL, 0xB0C017CBB3774986ULL, 
            0x0BFA958B0E12E07AULL, 0x6A9230C66D69D0CDULL, 0x20F46ED2EB218B68ULL, 0x288E2BA80AA0B337ULL, 
            0x2A927303747B68E2ULL, 0x45282D77DE558C18ULL, 0x14A1062993DA5409ULL, 0xE09FA2516B83B891ULL
        },
        {
            0x143566FC54D5616EULL, 0x30B88192C88730A3ULL, 0xE5A01B7EE59FC82AULL, 0xB82A02968AE3E8C9ULL, 
            0x335AAB3B91BF229AULL, 0x3847451CFCE89C3CULL, 0x4011CD2B9EEDE47CULL, 0x9F9354AE9B26D796ULL, 
            0x49DAE6E501853F0BULL, 0x44C5B2776BAE792CULL, 0x8E3A8392CE62CF5EULL, 0x2292599588C3EE19ULL, 
            0x3DAC8A35D40C1256ULL, 0x894FC80FB8AE9E0FULL, 0x4FC5703BE25FED5EULL, 0x7F70BC82979EDF71ULL, 
            0x2593FDF42D9EDE86ULL, 0x1E4F54E7EE498659ULL, 0x793E50F822EEDDE4ULL, 0x54F931A61F78F76BULL, 
            0x69C8F845287B89BDULL, 0x7335D5170048ADC3ULL, 0x10998FB9DE914A1EULL, 0x54A5762ADBDDA8D6ULL, 
            0x1A606AFF4751122FULL, 0x000EF4200650BB9AULL, 0xBBB1B9D61816564CULL, 0xB8A873A135BD509BULL, 
            0x0FE67B30D2B731F9ULL, 0xBC50043E58EE6A97ULL, 0x16CC795318BDCF6AULL, 0x189FE192352F9932ULL
        },
        {
            0x0AF95EACBD7151E6ULL, 0x9C9347DEA8A7CFAEULL, 0x89C10F66479393D8ULL, 0x5F1A0FF601B3FFB9ULL, 
            0x4C37D6B10D0D582DULL, 0x48557DD930B2C2A2ULL, 0x1D9C9D32F6B1E181ULL, 0xEF7E3BA4CF7F2A95ULL, 
            0xD60F6CA64D0D279BULL, 0xC542FCE7B3C2673AULL, 0x8A3D92476AE33C03ULL, 0x8A03FE85DE1DE883ULL, 
            0xFF43B8C571BF4803ULL, 0x8C6282A7CE1571F9ULL, 0x6FEB560DC28C38B0ULL, 0x0366C7A3B59BD9D0ULL, 
            0x66C61FA9ED895FC6ULL, 0x8FD627D1CE241A20ULL, 0xED1C89184B441CF9ULL, 0x2B3A2D8CB8F97DE2ULL, 
            0x3240AB7A8E895711ULL, 0x4D91D28DAD460ED2ULL, 0xFE45B0DC81D09D4CULL, 0x274C52807B1C4BB0ULL, 
            0xB0CE10DC7A8106C8ULL, 0x2D635C7184F15229ULL, 0xE8867BB0D08C03A1ULL, 0x24A82FF99AEB50BFULL, 
            0x95AF09026AE2377BULL, 0x32E48F91D8AA5F1EULL, 0xF7C3B0AD2276493EULL, 0x756EDE609176DEB4ULL
        },
        {
            0xECD289174BBBD814ULL, 0xA43F807B80AB79B3ULL, 0x86C37AEEA10A7DCCULL, 0xD5424B5E62BC9B9EULL, 
            0xFD4CDD9FEB9A7369ULL, 0x97D9E39FE78A5290ULL, 0x075E8C07E16FF180ULL, 0xD8FF6015A4B34580ULL, 
            0xA577ECB5C8D9A4AEULL, 0x630CE9E5AEECC022ULL, 0x34759A5EBF59656CULL, 0xAE429DECA9BE6E18ULL, 
            0x3E84281EE619C141ULL, 0x973684F5A00A0D91ULL, 0x1B5CD760DCDE1CFEULL, 0x0E2B5E9F4A0E7210ULL, 
            0x87F75416537375A5ULL, 0x2F67955C8223320EULL, 0x22C5EE8309D9D4A9ULL, 0xAA86E09991227524ULL, 
            0x468760D8DE3876CAULL, 0x914192C789E9BF0BULL, 0xF0E9133293D5B568ULL, 0xC00C4A62C7614D83ULL, 
            0xCBFFC3402D917170ULL, 0xDA365340494B7865ULL, 0xB227AAE224EFEAB9ULL, 0x97D3344A81E21643ULL, 
            0xC3516F9F72ECDF53ULL, 0xB45EF62605A423AEULL, 0x9449DAF161EA2C66ULL, 0x5EE6617FEAB2A59EULL
        },
        {
            0x677C607985F67ADDULL, 0xFAF8B4C4A9C4F3DFULL, 0x49996C9143CA3BC1ULL, 0x8D8D2F746FD04180ULL, 
            0xB896977630FBEDA5ULL, 0xE4AF52BB2F7D2D8EULL, 0x1AFADB8C459625EAULL, 0x9FD188F9EA4D7C28ULL, 
            0xDC27B051B7EA5789ULL, 0x105B584E6185BDF4ULL, 0x123F5B36FE4CD5FBULL, 0x832621A1206BFAADULL, 
            0x380BCFF325A68A03ULL, 0x13D9209C118BE780ULL, 0xAF6235523F50D5BEULL, 0x2D13B4621EACB37CULL, 
            0x35F6150CCA71ADB7ULL, 0xCC645C088C3AD1F6ULL, 0xB7226136EDC26209ULL, 0x6E31D0F6041493A5ULL, 
            0xD31FF339C21D1B77ULL, 0x583BA1643B21BC24ULL, 0x082685E4F4531860ULL, 0xF430FC8C7266734DULL, 
            0x5A02D9DDF4485B05ULL, 0x2491E264D7ED77F4ULL, 0x363830107D101E57ULL, 0x2CA239037BD9D54AULL, 
            0x26F117D10481192EULL, 0x0A854966B02F7164ULL, 0x30E2BAC42777BCF1ULL, 0xD5CE0DD3E567AAA8ULL
        },
        {
            0xE8738FBBF0182099ULL, 0x4C5CF042115CCF2AULL, 0x8DE121F8C3028F44ULL, 0xA9E8C96B361B247CULL, 
            0x84CB5EB25469B8C1ULL, 0xD257BA4D1D1997DEULL, 0xD43180A5823B6FC8ULL, 0xA2175A5D460CE140ULL, 
            0x7AE1E3A7FB439C34ULL, 0x32023F469DFD8D4AULL, 0x3E65FAEA57E54A54ULL, 0x78928762BBD78B41ULL, 
            0x016D25031D5BC7FEULL, 0x4D19699EEFA2CA1EULL, 0x16F6FC642A3611D6ULL, 0x7CAB2B4598CBE8FBULL, 
            0x60BEFEC26DF71DBBULL, 0x238ED161CCF4860EULL, 0xDBD262D5CDC607F3ULL, 0xC3B5CE1C36B54699ULL, 
            0xD58F59999B6E55AFULL, 0x85CBFF5E42CAE3AAULL, 0x7F15FE140108CEC2ULL, 0xAA88D973BF6AC978ULL, 
            0x0FFC0509DC1A4A17ULL, 0x9C51BF9E57273B1DULL, 0xA512E71C1F88F272ULL, 0x0EBBD846B78F5AEFULL, 
            0xEBE2F4C728DBAB0FULL, 0x9677B3A29DFF5FD5ULL, 0x07B85A51F780A741ULL, 0x2CCB288110710BD3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseEConstants = {
    0xF2596A7410AC222FULL,
    0x388E97E972C9B55CULL,
    0x278C94F3D8F2452CULL,
    0xF2596A7410AC222FULL,
    0x388E97E972C9B55CULL,
    0x278C94F3D8F2452CULL,
    0xC972DECC5763F5DFULL,
    0xAEEDD026CD1D7249ULL,
    0x11,
    0x14,
    0x4A,
    0x87,
    0x39,
    0xCC,
    0x33,
    0xBB
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseFSalts = {
    {
        {
            0x467A078F439DE0CCULL, 0x799ED098F708B598ULL, 0xB7C9E901B5B89B29ULL, 0xB0A9E81BA49A780DULL, 
            0x992FB1252FDDE06AULL, 0xE04D23BB6CF06BF1ULL, 0x98F77151D6BCFEAFULL, 0x1963FB57E8C4002EULL, 
            0x49D30D93257E5979ULL, 0x0EA08A90E11F4769ULL, 0xC5923A7B0753B838ULL, 0x21611928B3EC7009ULL, 
            0xCFBB7C5C9BB05618ULL, 0x6C32FEED1F00043BULL, 0xDD341B954116BFF0ULL, 0xF48DB0A6BD5DB410ULL, 
            0x120871E436BB45B6ULL, 0x7119B4FD7A5AFA66ULL, 0xB80DB88E99987406ULL, 0xC6DB494966A66A0BULL, 
            0x2EB2CAAB524E90C2ULL, 0xE3BE26A3A4ED08B8ULL, 0xECDB6FE5A6D2C21FULL, 0xB584FD5C60FB56B0ULL, 
            0x12D2B55E86032891ULL, 0xEC1CA4B1B4EFEC0CULL, 0xAE722226ACA575D7ULL, 0xE829773B96BAF8D2ULL, 
            0xCAA5D355C2D894C2ULL, 0x19C3093A50BD33ADULL, 0x7D2F057DD0009670ULL, 0x60435DF9D2DFEDC0ULL
        },
        {
            0x53C9F48E187DAE08ULL, 0x269BA038BE32BBB8ULL, 0xD3FEA31072D2876AULL, 0x7F07F0EA870C2219ULL, 
            0x22CA31AEDE6C2A43ULL, 0x1FA15D33D5195023ULL, 0xA4FEBBE83E0836FFULL, 0x5A9369890AD4CD17ULL, 
            0x14A5D1CFAE74C944ULL, 0xF44A7C76E53C5408ULL, 0x6AD5215340AB1367ULL, 0x414C07EF5A391E47ULL, 
            0x606E5E906EB5D8D1ULL, 0x6F9BE67EA50D0F0DULL, 0x34EBC2A9ABA0AC33ULL, 0x6DA9E445329361B1ULL, 
            0x1D68F92835CA10C2ULL, 0x3E789D14CFCAF1E7ULL, 0x919315C2EC274674ULL, 0xA2A098E731E78509ULL, 
            0x77C436DDD303DC93ULL, 0x3B117E0D8D9F3D64ULL, 0x3F38F1E70E6DAAB5ULL, 0x88D9597E572EFDC3ULL, 
            0xF02C5D741F16B48AULL, 0x7DBEE0C9CFDD8536ULL, 0xE85E1BDF798B19CDULL, 0x56DC734A5A78E8F8ULL, 
            0x3ADB333A34E700ECULL, 0x174209F150F5A2C0ULL, 0xA5B30360D7EFCCFDULL, 0x9DFB1CC5494AA51AULL
        },
        {
            0xE5B67DB7A80E0991ULL, 0x7EB27E041162CC51ULL, 0x23A7EA9BD0FBBCCFULL, 0xE62DF6E9CC30E68BULL, 
            0x5C9165C80FACFB6EULL, 0x1251DB7067245E96ULL, 0xB8500578D82BF053ULL, 0xE0526942FD9CF109ULL, 
            0x00DAE58FC5FAFCB9ULL, 0x56E066CF13AFEE6CULL, 0x20E814E8AAF71991ULL, 0x357C1A968AFC2854ULL, 
            0xC5B7E28237B6DAF6ULL, 0x33FE65B5AC2981D4ULL, 0x6CE96C965445FF09ULL, 0x6081032885F15C05ULL, 
            0x89C421617D92EDACULL, 0x9F6C211C2F521957ULL, 0x57694F6EEF804C4EULL, 0xB2DC9CFDE30A5361ULL, 
            0xC4D6A7845709F743ULL, 0x695C1DAA2D3EC3B5ULL, 0x30A79D1440450FAAULL, 0x5469B28A2BD2E5FAULL, 
            0x96A31BDAD9A035E2ULL, 0x4EE4AE89ECCE15D0ULL, 0xD0C757F89B2FD1D7ULL, 0x999A15BE8B44CF3CULL, 
            0x440B7673A98250DEULL, 0xF11690CE9C9A44ECULL, 0x752360690CC0E520ULL, 0x834E83CF61245792ULL
        },
        {
            0xE0D3A829C1699D87ULL, 0x45B11E48914E4777ULL, 0x50BC83E1B03E7096ULL, 0xED746E97F0484E23ULL, 
            0x1E73FEB9C6B9A02CULL, 0xB04836B21696BF2DULL, 0xC7F11A6F5EB06389ULL, 0x6B82DEDD7EBC2F3CULL, 
            0x710FFA9E660A9D89ULL, 0x0B61ED1D7879CCBBULL, 0x6EB3C573380AA2C3ULL, 0x5B9F7CDB23447F4AULL, 
            0x2ED4CBEBF6EBE7DBULL, 0x93BB50064A61CE45ULL, 0x1A9380F2BFF18D09ULL, 0xF562B09F1836B637ULL, 
            0x92109D2B86FE2187ULL, 0xA5528877B4C2DD87ULL, 0x5E90374BCC334923ULL, 0x17C55D3B34858B09ULL, 
            0xDA79CB24FD050F87ULL, 0x6512D9FF346F403CULL, 0xEBBA3C9264A2777BULL, 0xC3DCC8383F70B630ULL, 
            0xF2C7922025A94E3FULL, 0xF811D1D524BF7F81ULL, 0xBDA105459ED07EABULL, 0x101832D58CF6DB23ULL, 
            0xA69C65FED7B6713BULL, 0xBF303C89EA168932ULL, 0xE20A74E5C35E7C00ULL, 0xBA88D20AC2A20529ULL
        },
        {
            0xE3D17C32BFD03774ULL, 0x5BB173FE63370341ULL, 0x87E4B93E214AA773ULL, 0xFE5C4B0AF72C95F6ULL, 
            0xEEB716FF7BD65FEDULL, 0x8DAC08B7F7685370ULL, 0xD1CC1FEAF0DEFBDBULL, 0x5E5A5BA50C7EC93BULL, 
            0xB3AA1DF1849DFA1DULL, 0x700A74B88F9E54E5ULL, 0xFF3611E1F2F63EC2ULL, 0xAEFAB3B4976C4198ULL, 
            0x457EBA5B568AE1E6ULL, 0x89763529961FF05BULL, 0x28B894577C646E7AULL, 0x14DDB896385EB520ULL, 
            0x9B47686624CDFA11ULL, 0xE441FD3C5E0CD3F6ULL, 0x9067EEFA388711BBULL, 0xFDD7D8310C0ABAE5ULL, 
            0x1F68586A8CFDC255ULL, 0x1998D5135ACA39E6ULL, 0xE5D3FEE0651D2B5BULL, 0xF51B1A8BF095BC2CULL, 
            0xEC40B734C39770E7ULL, 0x447B0CA85E4D1240ULL, 0x827BADE2FF249949ULL, 0xA8C902610245B269ULL, 
            0xFA7BB35FF880133DULL, 0xAFF5CC4D4A57D911ULL, 0x24EC44765AEB7DA9ULL, 0xD10528188CB589E0ULL
        },
        {
            0x7D8855FA2009F05CULL, 0x52D1D584DAC57201ULL, 0x299A243E4FAE3397ULL, 0x45A97E24CB2EB566ULL, 
            0x667771ED095B61BCULL, 0x7E18E828D0FFCBEBULL, 0xBEB9B2A55E9C469CULL, 0x252605FA26D95189ULL, 
            0x429A08F333FB9B23ULL, 0xAF5600EC637C595AULL, 0x3B04712CCBDB7FEEULL, 0x5191AABC1E7A1AD2ULL, 
            0xC5D383EDE198B3E8ULL, 0xE0879AC21B9540B5ULL, 0x13BACD9C65280DD9ULL, 0x46F56C9D67A27D01ULL, 
            0xA23067EE202493CBULL, 0xFD2ACC396C6C88ABULL, 0xA679FD2EBD9E7A47ULL, 0x2705914D19F13D60ULL, 
            0x3BEC14617B62484AULL, 0xECF7008BB33C0A4DULL, 0x7E1FF527E413A11CULL, 0xF8296ED0BFBAA162ULL, 
            0x8D3950A65C691007ULL, 0x719152DC016998BFULL, 0xBF2F5B7182842570ULL, 0xE9F74B3A61A10F0DULL, 
            0xAE6BFDE8EF4B9C48ULL, 0xE3CBFEA395143644ULL, 0x7D569CEBAD18DA01ULL, 0x210E0D252AECAF41ULL
        }
    },
    {
        {
            0x2D9457254C4C7D59ULL, 0xDE1FD4655F6110C9ULL, 0x1B037C45143EF8B9ULL, 0x4CE5ACA186ED9B9EULL, 
            0x01F71CFC60CFBED7ULL, 0xC6DC93893436AE3EULL, 0xC19FFA93C1021824ULL, 0x9A51EFEEFA82F855ULL, 
            0xC2B6D7794FA91BC8ULL, 0xA28107F082005609ULL, 0xE3251ADA9EFC411EULL, 0x3A2FD40DAC7290BAULL, 
            0xBA225FA45E9E6D56ULL, 0xE9D43DFE8E4E73A6ULL, 0x7E3D117C37CCFB3BULL, 0x8D754C07C54D4A51ULL, 
            0x97B72147A1245038ULL, 0x07305AD69E58E31EULL, 0xAB94DD69EB49BED0ULL, 0xEEE2C5D33E21BB24ULL, 
            0xC91531039616CD71ULL, 0x2BD09CEABA397371ULL, 0x145E214F89EFAB2CULL, 0xE90120E8B9EC16A0ULL, 
            0x7FC5B04DB9C0F281ULL, 0x55896DE140C62009ULL, 0x05B42137246D0DBBULL, 0x1447EFC2C085DB69ULL, 
            0x1DBFE77286960882ULL, 0xE7703F1828DF32A5ULL, 0xE5B5767B5242BF48ULL, 0xD20D9C24B577E955ULL
        },
        {
            0x5C2BC542460C3FFDULL, 0x6E00938EC6CBBE97ULL, 0x222B8FC1200D8E42ULL, 0x01F4E8C56CD6D834ULL, 
            0xB52E798DA1EA4EE1ULL, 0x31F9A3D29B6F8B9FULL, 0x454183B437261B0FULL, 0x71E5F1DAC8C8AB90ULL, 
            0x9972B8F29455955EULL, 0x776EC8A85C0FD84DULL, 0x1D963B1ED40A4116ULL, 0xA9236302A1E8A185ULL, 
            0xA04A77099AB09462ULL, 0xE82C1C3575D8A1F9ULL, 0xE5E1A16B9A89F9EFULL, 0xA7509B5F0A28699BULL, 
            0x53681859AACE0AD3ULL, 0xDD98BD4887345789ULL, 0x5AF651F13E3B4143ULL, 0xC496573A2C46A476ULL, 
            0xE440FB1EA8207AAAULL, 0x3BC6A2ACF180250EULL, 0x8C0A97B5D6B3B3ADULL, 0xB1A4939D2ED849CBULL, 
            0xA0F7709AA88EB0BDULL, 0xEE9923206003AC86ULL, 0xA6C4399C1AE0080BULL, 0x73151DAB134B9ED2ULL, 
            0xB45461FA30848AE6ULL, 0x4A06CA16D4C2D182ULL, 0x02B3A8EA3F63AD14ULL, 0xF4C6CEE472D9E73DULL
        },
        {
            0x0B7A69AD3258AA2DULL, 0x6AE73F894DBAE113ULL, 0xC85479B59090FB1EULL, 0xA269DC58ECD5FC01ULL, 
            0x2D7C3A991AD3D579ULL, 0x3613FEA654671EE4ULL, 0x088DA1BFA1050572ULL, 0x109E2A0653FE0353ULL, 
            0xA378B44B49E2461BULL, 0xECC075B2E2495F6CULL, 0x3FCC0145A726FF51ULL, 0xE9B3E205E8A68BD0ULL, 
            0x5BC6427AE3E3C70CULL, 0x8675919D20D7A7FFULL, 0x106F8E71344DCF8EULL, 0x7B9AF4B4A5EDB0A4ULL, 
            0x22E3AB8211DF89BDULL, 0x4EA479B82C43096EULL, 0x2BDEC791F5D70C07ULL, 0x8BB82A24569B38ABULL, 
            0xAB54532121E53FAAULL, 0xB87527255A2DD2CBULL, 0x75024BBE5F6500B4ULL, 0x83A28BFE0CDA1579ULL, 
            0xF9D856C39D6839C9ULL, 0xDCD8F17AB861DBC0ULL, 0xB038AE356C0943CBULL, 0x0A4DA308161EA25DULL, 
            0x0E698C9585869700ULL, 0x9838E93A5C7A6E03ULL, 0x7DB70D949AA581C3ULL, 0x5ED8A832149E139DULL
        },
        {
            0xDAFCE64E5DFB318EULL, 0xD97816DDC36F8B67ULL, 0xD1E847B261443F79ULL, 0x304D97FA15B7C9C9ULL, 
            0xB8EACF26B2822DD5ULL, 0x384EA04C05E7000FULL, 0x56D705A3AA734421ULL, 0xE6E57313F1CAE8C6ULL, 
            0xB4F7523E23E7762DULL, 0x1834FD8D665FA793ULL, 0x90981814EBAC5650ULL, 0x749B89E570D25D22ULL, 
            0xF1B9DF2ED1E8F940ULL, 0x46DC9AD0EFC24B54ULL, 0x6099D91655D0746CULL, 0xE5C8465EBB4B8D82ULL, 
            0xC7F60667BE2BC5CDULL, 0x9C37E1F765D91990ULL, 0xB7601E4C08952772ULL, 0x2625FC5334B39C41ULL, 
            0xB6143926FE306879ULL, 0x9F4565B3EC926E42ULL, 0x22A091DC9EC0630DULL, 0xFAFFCD2431B6B8FBULL, 
            0x6D1B15D08D9A28B0ULL, 0x29C108C42A9F80A0ULL, 0x1F0BCC0D1A317F37ULL, 0x71631F66DE405CE3ULL, 
            0xEAC857F80B449A0CULL, 0x3AA7B482E2B6B054ULL, 0xAF15280CBEBC5AB4ULL, 0xFA4A1F624510B16EULL
        },
        {
            0xA88EB620C5D9BCBEULL, 0x82DC7886177003EAULL, 0x176E3AF500ABB7DAULL, 0x24C7238ED3F5496EULL, 
            0x8F2291A975625854ULL, 0xB68592A355412BDFULL, 0xD9C0F09055DDFCE3ULL, 0x33BAB2EDE159F64CULL, 
            0x3294076CC53CE4B4ULL, 0xFE5977156E6FFCE3ULL, 0x92CC60C541842D07ULL, 0xB6A30BDD754D33B2ULL, 
            0x85A483D1C5E68120ULL, 0x8A402622224E061DULL, 0xAEE614F3A89392CAULL, 0xD35909C1F5CA199BULL, 
            0xAF687FF2689F43FEULL, 0x73BED77BC01199EEULL, 0x6EF3B617ADEEA09AULL, 0x5237710F9310A249ULL, 
            0xD0F94506327E368BULL, 0xC4793E6FFFA2E192ULL, 0xD2A2224B0CFA8792ULL, 0x03A6BF7725380654ULL, 
            0x7E1E2202E22243BAULL, 0x367A0D1F1A43CA2AULL, 0x528687A98BEF7EF4ULL, 0xD103D8539AF02595ULL, 
            0x1D6C18C523CBEBCBULL, 0x6D92A83163D3744FULL, 0x6E10F7998C4D9CE0ULL, 0x0E04641BE232753FULL
        },
        {
            0x885332CA05541EBEULL, 0xC1806AAF427A882BULL, 0x46BEBD2D9EBE4AD3ULL, 0x61A520838FE8FB43ULL, 
            0xE9D25937466A1FBEULL, 0x0B777999C9372651ULL, 0x1620FA58B99E06B1ULL, 0x00BE9AA8D35BEF74ULL, 
            0x4123D248B32023DAULL, 0xB27693B6B3EEFB4BULL, 0x9FA0E067423D2981ULL, 0x725E899F6EA80CE8ULL, 
            0x4CC267C6BC011BC7ULL, 0x4A31EBD4A74F3B3FULL, 0xD2FB23EF166D338DULL, 0x672AF26CD165FE05ULL, 
            0x9ED257F2016D2482ULL, 0x889D763EF1EBEE07ULL, 0x1AFA99775AB55AE5ULL, 0x97A7129E6596B8A5ULL, 
            0x235FD422E175D3E6ULL, 0xC4ACF6AA5B3B656DULL, 0x4549F9EC157154B8ULL, 0x22FC0ABF3334FD35ULL, 
            0xAE02C245064AEC5CULL, 0x7C6FA546DC1767AFULL, 0x1E7EB468E3722B72ULL, 0x5544ED9DE029C033ULL, 
            0x91F6A31918328330ULL, 0x7DF2D7D8D733F79FULL, 0x9368C30AFF2ABBA6ULL, 0xEEA81E8415E62196ULL
        }
    },
    {
        {
            0x80D51FB536733C38ULL, 0x5C26A625452A96AEULL, 0x04325D1D93085486ULL, 0x76D7FAA35D796AE3ULL, 
            0xFEABB80C9D531598ULL, 0xD5090C7DBB81F6A5ULL, 0x35D4AA1B7637AE50ULL, 0xF2672EB86022A007ULL, 
            0xF15E46DEF709271FULL, 0x708781BAC0A40989ULL, 0x084022ECC44C8BB2ULL, 0x28B9B9E711B36DCCULL, 
            0xB02C9196F0156BA6ULL, 0xAFC8958D3B2A599CULL, 0x7CF1C91325AE980AULL, 0x49E0AC53E96A5DFCULL, 
            0x5DFA669BB6848DFEULL, 0xE71C2DE1C4C30754ULL, 0x94D2DF122C1619FDULL, 0xDE82CF8F35BCBC5DULL, 
            0xEDFA4CA78BECFABEULL, 0x97873C6071910B40ULL, 0xAA336C8002673E85ULL, 0x03CA7851634DF332ULL, 
            0xFE7F3211CB916126ULL, 0x7E6F81AB72EE3F3EULL, 0x56B424A93B1F716FULL, 0xC4DE12117C718925ULL, 
            0xE54656B5FFC17099ULL, 0xC5D93B4E101D0337ULL, 0x66E3F44E5739C028ULL, 0x2F205C77B75C1CE5ULL
        },
        {
            0xB9F739ABD1AB9408ULL, 0x034FE424763C72C5ULL, 0x1562D61FD0824D11ULL, 0x71DE0017A61B54A2ULL, 
            0x1C19F6AD59D859DCULL, 0x543A75534C7070CCULL, 0x9BE933F627F9696EULL, 0x142DB6A620A4AE30ULL, 
            0xD9FBBC2007BE76A5ULL, 0x9BB62A82061212DDULL, 0x1768806DF3F8012AULL, 0x82F355BBFE8E9CF8ULL, 
            0x1A8478D38976FD2FULL, 0x1F244E98C4A422A0ULL, 0xA4BA9E4EC5C5CD74ULL, 0x63FAC76BF8867535ULL, 
            0x3EC249DFFB432E43ULL, 0xF2F8AE25753ED4F4ULL, 0x412AB81416FFF55DULL, 0xD3B714B3C94DA79AULL, 
            0x7A6BB5EEE95E663AULL, 0xB02B2BFDA0434B82ULL, 0x788CAACCF680D74DULL, 0x0A3020880B1B3705ULL, 
            0xAA3A1C7A21904861ULL, 0x826056F672AB2A73ULL, 0xC46F61F97876AC72ULL, 0x1FA6A691DA5762A4ULL, 
            0xD5E883F32266AD81ULL, 0x883D321907A2373EULL, 0xE085EBF9A5C7CFBAULL, 0xD55454C43163BAB0ULL
        },
        {
            0xD97234BE01968FBBULL, 0xB613F52F3AD6B72AULL, 0x4310EBD37236043DULL, 0xB13D9FE35906B5A4ULL, 
            0xA952FFEFC0C35160ULL, 0x38BFE71ECE400F08ULL, 0xA0A779EB7AFC2F36ULL, 0x6ED60F6E3B8F46A6ULL, 
            0xB07B58F39014D4F1ULL, 0x9D4FA7A63F2EC8BCULL, 0x35BF99FCDAEBDDBEULL, 0xD11D834F2D97208DULL, 
            0x4B882606AFF88A1EULL, 0x7C2ADE628738633FULL, 0xEA34A1099BD525AEULL, 0x2BD030557E339A38ULL, 
            0xBF99F85AA9AE1C16ULL, 0x7A9CCF3B6596D34EULL, 0x00CD8236CF850893ULL, 0x243C300AB5EE96F7ULL, 
            0xC923FCCF03AAB625ULL, 0xC222E3D2F0D42919ULL, 0x48D6BF0C438B66BFULL, 0xC48DFC6104198F3BULL, 
            0xD05A2FDBB8A102BAULL, 0x259D580BFF8D606AULL, 0x9B6557E92A2F0382ULL, 0x7DAE5D209B5EAA31ULL, 
            0xEE15F7EB496DDAFBULL, 0x02183D00C252B745ULL, 0x15C50C71BB3EE337ULL, 0x3A9A798AC25C508DULL
        },
        {
            0xA9C3DA77BD691FF0ULL, 0xFA5FB7A615778B4FULL, 0x376E1F8CAB3E5DCAULL, 0xDC17D6536182FF68ULL, 
            0x98CD78E22B964DB7ULL, 0x9F71EFCAE61B05C0ULL, 0x25EC6645F1759A86ULL, 0xD1A67C93B4848ACEULL, 
            0x764622576DE188CBULL, 0x0A324EA9378B4F12ULL, 0x25185F161732F42CULL, 0xE89E6AAB9BD3D922ULL, 
            0x642033307F6934F5ULL, 0x26CAB8F7F7824AF9ULL, 0x747A17749EE136D0ULL, 0x157B6E5A60DA770FULL, 
            0x30F8F75EEFFC1DEEULL, 0xA18584C0366029B4ULL, 0x58E447577D13F8EDULL, 0xADDD3D976E8F5837ULL, 
            0x4645E3262D96BFECULL, 0x8C2766109CCE95C7ULL, 0x1CC13DD665B8827EULL, 0x62C0798356533105ULL, 
            0xFD0E870EA2575900ULL, 0xA4518DE8132165D4ULL, 0xE0977757FA856E93ULL, 0xB41E0D0EF8F30377ULL, 
            0x30A2CEB0E614D728ULL, 0x748A0775FFE2593DULL, 0x481E45A41E3BB479ULL, 0x2C8FBD3002CDB34DULL
        },
        {
            0x5FA356A4CB0A03F3ULL, 0xA25E829592149F9EULL, 0x84FD6319A4AAB686ULL, 0xA758F2A4A61BDB01ULL, 
            0x6E68EF13149E9AFAULL, 0x4A00E1F3C0F7A400ULL, 0x8D08DBF75D974A67ULL, 0x057FA40028611ABAULL, 
            0x5C108796444E0A82ULL, 0xE7859F27F52B8D92ULL, 0x4C2507D160BEEA04ULL, 0xF850DB65645417E7ULL, 
            0x63DF6FC233622C0DULL, 0x1067528AFDE4D257ULL, 0xD20ED70A885C13DDULL, 0xF9E18A4926604998ULL, 
            0x1EA6DBA3505C63AEULL, 0xC11899DE6A4F710EULL, 0x44E8892C83C0EE83ULL, 0x6F29EAC55C261A09ULL, 
            0x42080A4733DEF95BULL, 0xD7B599CCCA26F47AULL, 0xE388C58C77999F9DULL, 0x6B35B623D6103458ULL, 
            0xEE44DFEB9599BB75ULL, 0x8C94A91C09DA7785ULL, 0xC30EFBD07E3E2C7BULL, 0xC358B7592AE22D91ULL, 
            0x463B179114A49394ULL, 0x2FD6DC179EE09086ULL, 0xACB6D7461CB8DC47ULL, 0xE3CC27963C7E4B83ULL
        },
        {
            0xEEE8E4F2984E4A2FULL, 0xDAA757746F735BB6ULL, 0x5E7E233D21042616ULL, 0x95D768129F5555CAULL, 
            0xD7DD919F447DF2A9ULL, 0xE753935B78D2851BULL, 0x044560794E60BCC1ULL, 0xDDD8B755DA5D382BULL, 
            0x1520A9CA8434965BULL, 0x0DD6CCDA66FC05A5ULL, 0xC6D6313FB9249503ULL, 0x5666F84E217209ADULL, 
            0x6E7E610E951567A3ULL, 0x07288824FD1F395BULL, 0x3DDB94EC81EA2A5CULL, 0xB4BF553051088790ULL, 
            0xA324512EDAD55D5DULL, 0x58AAE9465A8D0301ULL, 0xD19610E23F76952FULL, 0x45A6F3B733D45E4EULL, 
            0x1225462CB152154BULL, 0x931D7D92832FA3F8ULL, 0x63AF72A8984492D6ULL, 0xA3DD412AFB3407D9ULL, 
            0x43D24331C3C75974ULL, 0x31683789CB463501ULL, 0xE3A98645A746D686ULL, 0x5E7FA9BE0CF80473ULL, 
            0x5C9C97EA626081B7ULL, 0xCB0F137D479336E7ULL, 0x60B484B6A83D242DULL, 0x987503533F5EABB5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseFConstants = {
    0xDB69F6B52E44A864ULL,
    0xC21A17C5A8703B43ULL,
    0xAAFB5704E6FFBFFCULL,
    0xDB69F6B52E44A864ULL,
    0xC21A17C5A8703B43ULL,
    0xAAFB5704E6FFBFFCULL,
    0xAAFD42AC2A817D5CULL,
    0x0CFD3F76D838647CULL,
    0xD1,
    0x5F,
    0x0E,
    0x62,
    0x1D,
    0x52,
    0xBF,
    0x94
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseGSalts = {
    {
        {
            0x402C03AE9B14E251ULL, 0x971A8792CDC2DC96ULL, 0x1C74B832E8E95683ULL, 0x5E3D956CCC42061DULL, 
            0x0896CEE77765A652ULL, 0x4897CA490273C5C5ULL, 0xED2A03376B2FE7F0ULL, 0x0E02A37D92CC5098ULL, 
            0x851F3582FD4999B8ULL, 0x44798CEF87B0AF57ULL, 0xF2FBAF13D77BE727ULL, 0xFF72B91242194837ULL, 
            0x90CE22D2FD8E73C3ULL, 0xE37A374508C7E3AAULL, 0xEFDAFBFB9C49F362ULL, 0x16DA77DE36E7ED4EULL, 
            0xC0BDB0C8150BBAA2ULL, 0x28565A5E77F114ADULL, 0xB004EB6EB9DB1F4FULL, 0x62F2FF3C683C8A06ULL, 
            0x81C9BCED565C08B6ULL, 0xDDB7A42119D09FF8ULL, 0x398F36AA80DCA8CEULL, 0x7A63E9DA3D6B18C5ULL, 
            0xE19E302D19338262ULL, 0x97DAB5EF5721CAB4ULL, 0xF7AFA36B6B304CD1ULL, 0xDE9852C769A9EBC3ULL, 
            0x9A0BFF2524050460ULL, 0xC82B6D30C7A59609ULL, 0xB0489A3FD6E3D2D4ULL, 0xC36C9272642EE86DULL
        },
        {
            0x1EF9264232ED8341ULL, 0xED34D174FA49E143ULL, 0xCDB67506AFD67EA9ULL, 0xA1053323A2F39EBEULL, 
            0x1977217436240BDCULL, 0x699DC86A9E89EB71ULL, 0x7AA551E1CBB6868DULL, 0x769725629313F2B9ULL, 
            0xD631F87EF16B09FDULL, 0x6670DEE8805D0B80ULL, 0xD42DBB501729F27BULL, 0xC9537FF78A8E6CB2ULL, 
            0xB032D8EEE608CE58ULL, 0x65F117575B887556ULL, 0x7852D12E58EAF031ULL, 0xD501FB060045032FULL, 
            0xB4D0A218C7A99CADULL, 0x3A24506E9A0BA4E2ULL, 0xC6DAE4A5678F3C79ULL, 0x575161E3B61BBDC1ULL, 
            0x33FECFBF663E428FULL, 0x2D1747CEB5C5B73BULL, 0x7A054E3FC418DAD7ULL, 0x719E68DB9ED5769EULL, 
            0x8462475F42FB1986ULL, 0xBE66E48FD3E69817ULL, 0x337D203678E92DDEULL, 0x84C3CD56ECBBC3E9ULL, 
            0xA8576922EEB77D95ULL, 0xF4D8473F0EA6A564ULL, 0xC71F0DFAD0A9F6AFULL, 0x1CD16631336BD827ULL
        },
        {
            0x1E57A14951A5BA39ULL, 0x216433AD62F781D0ULL, 0xFB11FE8F7885F0ACULL, 0xD7B50B9F21FC97ADULL, 
            0x17AF59DCFEB70225ULL, 0xBA2606C837D19B45ULL, 0x1598049B7F63C6CEULL, 0xA5CD749120067B03ULL, 
            0x9BEC316721A3DA07ULL, 0xD20C1C66FB7FE6CBULL, 0xA6C5E12204CAF08BULL, 0x76AC3F27ABEDCDE7ULL, 
            0xB52C81C8950BC624ULL, 0x2299D69A6B214DB8ULL, 0x1819752DE6248146ULL, 0xD7F0D189F23045FFULL, 
            0x4160BCB10B589847ULL, 0xE6E1A88D84EA6842ULL, 0x8480F7CD603DBA9DULL, 0x6509D37767CA407AULL, 
            0xA36E29F6AC3A7D55ULL, 0xDCE69ED2C4FF47E1ULL, 0x93B5759ABA9C0360ULL, 0x5E954339BD25E5BAULL, 
            0x97097010DE573DF1ULL, 0xA6A6D0066518EBB8ULL, 0x38BA803F95317AA4ULL, 0xEDD802D747CFCB15ULL, 
            0x807B8A134B28D16FULL, 0x609AB592E69B423CULL, 0x315FA4430A0C77CBULL, 0x0F74BAC064C4929EULL
        },
        {
            0xC4497C643205C90BULL, 0xDEC7A0C7ABBCA45BULL, 0x6427A10A03F539CAULL, 0xB818BA65296E73EBULL, 
            0x383FEF9ED26767B0ULL, 0xD90554CFEA0A3EEBULL, 0x5892E08D40B762ABULL, 0x1A8087388E178E63ULL, 
            0x9B8C6358EBBD8BB1ULL, 0x0A84F5C630D5D25CULL, 0x4B362D83C6665D2AULL, 0xCF8FBE5F433AE585ULL, 
            0xCE03D7E9A34691D6ULL, 0x99CF0DE9B03F426DULL, 0x4DC6E02D610E2CF2ULL, 0x2BE308780FCC369AULL, 
            0x83AB09BC03629936ULL, 0x64DE891CDE7DC7C7ULL, 0x8C0C2672A0224280ULL, 0x4B7F59A5BF0F090FULL, 
            0x8FA63B3B956AC1E9ULL, 0x9F3C20E55D232278ULL, 0xEDA2BE1F6DA54347ULL, 0x9E332896B83B17BFULL, 
            0x40E21B5DFBC304BDULL, 0x3CEDD269FDDDBF72ULL, 0xFC5C208A4720CF2BULL, 0xC9F6B3DC01718C34ULL, 
            0x19DA0326522B67E0ULL, 0xBE56C35D3D1CCBA7ULL, 0xA7B03CB2B3B0C83FULL, 0x4E799D150A5CC941ULL
        },
        {
            0x879A70715ED6D069ULL, 0x411A522E0B4CB226ULL, 0xF758E28EAA357F35ULL, 0x70071E60588CE3B3ULL, 
            0xFB6C9D829778DD35ULL, 0x9E750450421ED1D8ULL, 0xB2FEE662AAFBF00CULL, 0x2B4E391EEAE006B6ULL, 
            0xE1FA97787E55B436ULL, 0x52F88F6741E3FEFDULL, 0x58B18087C6F5C23BULL, 0x497E029B3B329E95ULL, 
            0x6C2F797F671B6F00ULL, 0x58D43C7F1CEB26C7ULL, 0x48B6422164F05E0CULL, 0xA7835446EC318A01ULL, 
            0x9A2233E4D71CF687ULL, 0x991A29145D363958ULL, 0xCEF2CD1B770513F8ULL, 0x9A7DB82FA618CC1FULL, 
            0xEB7B0968F73D498DULL, 0x692031A540066FE2ULL, 0xF5CB347CEF6A9213ULL, 0xEE36AA2729E1E16BULL, 
            0xC7F0B0CFE26ED32BULL, 0x5B550F34EDFDF06AULL, 0xAFD5AFBE313494EAULL, 0x9ACD3279725CADBEULL, 
            0xFF07B6E537CC8F3AULL, 0xD43F9F48782104E8ULL, 0xB46836706BB6EE00ULL, 0xB7DC32D83646A2A7ULL
        },
        {
            0xA6A66F580DAA70BDULL, 0x10B58C687F173034ULL, 0x3027E17CC6EB90C0ULL, 0x5FE5C80EAB95A093ULL, 
            0x1E7FD7DCD674B4CEULL, 0x26BBAD192749FC15ULL, 0xBB1059003AF82D44ULL, 0xA7202C09BF276C52ULL, 
            0x887570D6EC443D2EULL, 0x1450A3E2F47A3AB4ULL, 0x35CE8EFF353BAD25ULL, 0xB59E631C44EC54D3ULL, 
            0x40C59414806F391CULL, 0xB44DE95647630D64ULL, 0x5EC1361080489FBFULL, 0xFF9B706D6A1915A7ULL, 
            0x588100BABD42EE10ULL, 0xBDB23B3FD40359D2ULL, 0xF88C2BD90E4FA5EFULL, 0x96F1CE6215A7BFC2ULL, 
            0x8B2069D36130B340ULL, 0x3551ED1F64822764ULL, 0xCD915D6A8F8DFF6BULL, 0xB8245B9E2B0A1EAFULL, 
            0x1E21B9238414C5B3ULL, 0x49D8BB013760DCD7ULL, 0xCDC029EE6AFE756CULL, 0x3FCF045E67719EA2ULL, 
            0xB8B18BA15ABC6ED2ULL, 0xEEA5D61AE862376AULL, 0x3E983212A824870EULL, 0x40405A05785FC5E9ULL
        }
    },
    {
        {
            0xD0E67AC76B15D8D3ULL, 0xF66D4F8398FA6CE8ULL, 0x44812ED1F0F026AFULL, 0x7B39CF5F6DD32F70ULL, 
            0xC5B8B85A8C2E1E27ULL, 0xB1D8A029652E3C3AULL, 0xC2D8FA7BEB6176B9ULL, 0x69AE94A48BB660EBULL, 
            0x289DBBB44F58A2AAULL, 0x138EDCF1F7CD63B8ULL, 0xD997C5BFB4F4D8D0ULL, 0x9E817428EC8490D7ULL, 
            0x5F80ABBD7A73545DULL, 0x8AAA82A3D31A3C55ULL, 0x05FB5646F13862DCULL, 0xEC885E9CFB706796ULL, 
            0x940C44DF30D63388ULL, 0x866F924EFB2C610DULL, 0x96AEBEF0A3ABE15AULL, 0x36B8775AC990ED1AULL, 
            0xE18E4B80A9789DBFULL, 0xED4D629111D1DFC8ULL, 0x20559FAB4F1F013FULL, 0x6255015C910FB2ABULL, 
            0x70B60DCAEB029CFFULL, 0x601F1A4C1F40E6BAULL, 0x18711A66ABB6E49DULL, 0xFC3627BDF6B2E48AULL, 
            0x7D48246204974ADBULL, 0x528730469B3E14C4ULL, 0x86CEB33A1D2C6061ULL, 0x9301DE38D11D552AULL
        },
        {
            0x56A5786127AE17B1ULL, 0x061E751436EAA5D4ULL, 0x942FBEFB6E96D899ULL, 0x27BA99C3EB9311DFULL, 
            0xCD6CB94143E9F4F2ULL, 0x0E1078A6E393B9F7ULL, 0x88FBF41CAA05188AULL, 0x038570E25F3C4B7FULL, 
            0x9B9EAB921D1F0316ULL, 0xFFA468B29C8B92C1ULL, 0xBC94EC9514E1D4BFULL, 0xE8462543F12E1CE7ULL, 
            0x033BF644D00170E7ULL, 0xA9CA15E5CACBE981ULL, 0x190825387F68A22FULL, 0xCC9462BA68C94C75ULL, 
            0x5AB98E6AB01EC868ULL, 0x80D6DC2FE7913915ULL, 0x32265BBE014280C0ULL, 0x4F469FEEF97B85D4ULL, 
            0x64B881CD323CEE45ULL, 0x8842CA2557C515EEULL, 0x74E2921409B555D7ULL, 0xE1C2AB5B29D93567ULL, 
            0x4C88AC353BA199B5ULL, 0x92D7208FBF7326CFULL, 0xEAF962A593B30AF8ULL, 0xD44749FE8328CA76ULL, 
            0xA7604930CFE51229ULL, 0x683584E85340078EULL, 0x6206CCE264DB9592ULL, 0x3271F0FE336D3960ULL
        },
        {
            0x4CC5EABAA84900F1ULL, 0xFB6EF7829C780B59ULL, 0x5E31215545785A74ULL, 0xDA9E5EF7931327B2ULL, 
            0x9D261E0ED99B40FBULL, 0x44EE4069657B96BAULL, 0x8704D7AAE90D5DF1ULL, 0x21F081D9B8EB6295ULL, 
            0x2B9CEF145633DE56ULL, 0x517E37F3AC3026FAULL, 0x0F97FBFF1BAF6333ULL, 0x01B45BD40E40D20BULL, 
            0x5E39E9B1A25C0319ULL, 0x764878A209CDE560ULL, 0x63ABCFE157DA5701ULL, 0x9861DAC47751045BULL, 
            0x80F6FFA8A5F7B114ULL, 0x5A27C752AF446DEDULL, 0x967C6E92BCB96800ULL, 0x6ECB5D5DFE08D81CULL, 
            0xAC411AFB0EF60ADDULL, 0x3D151455F60E60FAULL, 0x002A330FEFFF7248ULL, 0xB0156075CE533ADFULL, 
            0x1FD4ADC8B7CD54B4ULL, 0x217FE98F427C7028ULL, 0x98940E771A4DE6B5ULL, 0x3CF51B1AF211463FULL, 
            0x433F6AD84FD8887FULL, 0x121CCEF74197CA06ULL, 0x7255C7334036E614ULL, 0x0AA0528330AE311DULL
        },
        {
            0x8CD8B151FE797EF9ULL, 0x9ECFFA98B9276F92ULL, 0x603928AEE356C9FDULL, 0xEB9088C478116E11ULL, 
            0x10B8A8BE7CC5ADE7ULL, 0xA22EA178BBB6BDEBULL, 0xBAB62E83977D39E3ULL, 0xFE60B2805EF73F13ULL, 
            0x15AF110B4EAAB728ULL, 0xAA60FF1EBD191B73ULL, 0xC28F60AA50CD72B6ULL, 0xF15B66DD6EFDED76ULL, 
            0xC25C1B07F62A3B78ULL, 0xEE505B268A89F084ULL, 0xBCCB05BC1F2BACA8ULL, 0x5A8E433B696AEAB7ULL, 
            0x12810341286DB766ULL, 0x49993E48991898FCULL, 0x1980AD2CE9E4B7D2ULL, 0x5533BF2B2F2AB722ULL, 
            0x7ED6F662DBBAF472ULL, 0x972605002B477781ULL, 0xA441C3904DEFEA0AULL, 0x5DF5AE219C874EFAULL, 
            0x403FB5AB7F4D0A71ULL, 0xE348A2E34E0A2592ULL, 0x3A3C468F83538068ULL, 0x9F4403712DF6AAADULL, 
            0x60FF5BCE0A27E6E3ULL, 0xAC82CB3EA1E413CCULL, 0xC42DD94ED048E4CAULL, 0xEA5FC3BC6FB964B0ULL
        },
        {
            0x01BDBA205D18BA7CULL, 0x3F7F95F9E2DF2DD7ULL, 0x9B120A045A203984ULL, 0x54B9DEDBD56D68B5ULL, 
            0xD2C1120C7E9FFC15ULL, 0x3D5D18F29FA04C08ULL, 0xAE93AB511CBF1399ULL, 0x5D75CD9124CC0918ULL, 
            0x1EBF8E703A206D97ULL, 0x33720852E4A4A54DULL, 0xB7EC039A15D92666ULL, 0xA7921AED6087B545ULL, 
            0xEA83982DEE2B7D02ULL, 0xB3E42612D46C705AULL, 0x57BD0AAA9746F670ULL, 0x4CA1933714F4DDFFULL, 
            0xA403D2DFAA14C65CULL, 0x175311B8FD2A3270ULL, 0x9CA662C19F62460EULL, 0x23C9F7A36BBC7D7EULL, 
            0x9957BB46FD5B7BA4ULL, 0x6262CB23651FE26EULL, 0x794E04CD0DEF95B7ULL, 0x9E355605A137BB9EULL, 
            0x09A5A3B78C8D316AULL, 0xD7B02C5BF7036B18ULL, 0xFAC2ADDC8AA6E987ULL, 0xFF453875987EB327ULL, 
            0xC0DDD618E4292B91ULL, 0x82D6844710706520ULL, 0xD065E60030C59911ULL, 0xA51088F644BD3752ULL
        },
        {
            0x5BBB30EB349B56E9ULL, 0xD4B9064D661E443DULL, 0x3389035BF0BF7586ULL, 0x01441DE96EB2447DULL, 
            0x04EBEA393A6C1EEDULL, 0x3DE18D4F7A990523ULL, 0xB07F4513DFDBCCBCULL, 0x8935DB72446F4DBAULL, 
            0x88E154C20C7CDCADULL, 0x6090698FBFB1FF31ULL, 0xDA950BE25D6C969CULL, 0xA13ED15CED31C088ULL, 
            0xA9C8D2AD4CEAE6D3ULL, 0x6BA80E2F716BE46EULL, 0x4E95EAAD1B3D5748ULL, 0x3D19C258B3E46BF0ULL, 
            0x0C497277E0702E51ULL, 0xDA65D4180553A57BULL, 0xBF7DF11DB3332BF9ULL, 0x0532DC2528DFA948ULL, 
            0x8C3D7BECB5F36321ULL, 0xC1FD022328FDBA4EULL, 0xC2C57EFE92BF243FULL, 0x8C54E8BE9B8BDE16ULL, 
            0xBED39D73DECDC47DULL, 0xEF63F3A91BF7C07EULL, 0xBAB7AECBD21839D5ULL, 0x94C7B697463DB497ULL, 
            0xCD74FB12FFDB0C0EULL, 0xFFD7F79567109C34ULL, 0x3CD3FB0A1DF23840ULL, 0x63FF446F78260266ULL
        }
    },
    {
        {
            0xCB0D96A3B27D64D8ULL, 0xE4E9799F90C1961AULL, 0x9A99C60E3F686C23ULL, 0x3B1085DDBD06FE8EULL, 
            0x2DE61906A2A245B2ULL, 0x5BB5865335DB143AULL, 0x24F01840C3791EBDULL, 0x28B54011480D7DF2ULL, 
            0x2D77C9122C41FB8FULL, 0xC3C3753306C28927ULL, 0x15C9B665ABFB9A7AULL, 0xA36531D15B3697CDULL, 
            0xD0E904CD182138EBULL, 0x111B89F9718DFFD8ULL, 0x5F769D3747D71F85ULL, 0x85D6D8A5EE7C40C4ULL, 
            0xA7E38CA57397E0A8ULL, 0xE4D39794734942F1ULL, 0x38F2A0447BE6ADEBULL, 0x92BBAA39926B127AULL, 
            0x1FE94571C0B630A1ULL, 0x125FD591B7DA6F7DULL, 0x16322FA80DE0EE6FULL, 0xE7EA64B254C9E7A3ULL, 
            0xF6E082DAE3B14BEDULL, 0x22EBA56958CF12E6ULL, 0x49673CB2FE74D3A0ULL, 0x698BE83B1C9543A5ULL, 
            0xF8F2E2D16A5DE716ULL, 0x3652AB8CC3ABF206ULL, 0xEEB92C8EE7752C0EULL, 0x284F22678693FF69ULL
        },
        {
            0xCB9FD763C32B4AF2ULL, 0xC359821E476C1C88ULL, 0x93F472433F07097DULL, 0xC20DE9B2DE046551ULL, 
            0x33882D0E763CFBC0ULL, 0x786F0ACECAC41AD7ULL, 0x3012C309F5A39C33ULL, 0x48555D8D8870AAC3ULL, 
            0x952D4ED57A84EAA9ULL, 0x2A9B875B3DAFA34FULL, 0x01A81AC8A5AEB4B5ULL, 0xB439BABB70B9BF0DULL, 
            0xDAB611348B7884DCULL, 0x3020F662DA117AFAULL, 0xE5C8F9C5AB7DF4F9ULL, 0x10A92F9719D7990AULL, 
            0xFDCE4EA6D6C71FB1ULL, 0x931FAD6AE0AF638FULL, 0xC56229756B58A4BBULL, 0x5CFDABCCA2324A7EULL, 
            0x962AAB21131DFABFULL, 0x34115EE2B59DFA96ULL, 0x7102E911A61368FEULL, 0xD28E640B2E9B9EADULL, 
            0xD3EF93B2DC5C2C70ULL, 0x8AD0DC1724484AA2ULL, 0x573E76F7DEE9A54CULL, 0x2BB40EBFC03D3BD5ULL, 
            0x145F0F7A2B806114ULL, 0xD170BF47947C2E1BULL, 0xEE1B2EA609204FFAULL, 0x750CD37D264D85DFULL
        },
        {
            0x4CAB94167C2CF1E6ULL, 0x96FFD6B66D2B6D34ULL, 0x3624FD77A7319457ULL, 0x055E13D585AAA37FULL, 
            0xE6A2FABDFA4E3BCFULL, 0x69642CD96FF76D1EULL, 0xF160C12DAC229DF3ULL, 0xF7C953F609755652ULL, 
            0xD02AFF4DE7F05A54ULL, 0x4014B4BF7DD53F36ULL, 0x7E379B3B10BCCEC9ULL, 0xE8E658DBEBD98941ULL, 
            0x62DE4E5F0592B2DBULL, 0x06C421BA3F2FCD1EULL, 0x264CA4825236AD59ULL, 0xF702186D85EAD48BULL, 
            0x9CBF3CE4CEB55C9AULL, 0x9F3CEB5003803908ULL, 0x2303E6F90CB78ADCULL, 0x7D455E70B1775093ULL, 
            0x14EA2836D26C0638ULL, 0xB3DCDB4D51F95BDDULL, 0x30AFCE3126373C18ULL, 0xF564C50AD9EA8A1EULL, 
            0xC988912A08A4B3B8ULL, 0x630895ADDAF553B2ULL, 0x44F58BF47B1B26F8ULL, 0x53084BFAD895D457ULL, 
            0xE5E6F8B5A377814BULL, 0x1A148529F23B557AULL, 0xCD149D29A6943F0EULL, 0xDA6A3F6E2F7A22AEULL
        },
        {
            0xC9906AFC1D251FA2ULL, 0x2D1A36EA2528A897ULL, 0x6DB2B043AA8D46F0ULL, 0x323B45424E572E99ULL, 
            0xC871151D7846AA8EULL, 0x2F83F5A1839FA39CULL, 0x5FCBD19D501B3010ULL, 0xF7880E3E5502515DULL, 
            0xADFF26EC26A68938ULL, 0x1637A070895BB0EBULL, 0xC500727116508E04ULL, 0x1422056060260DD5ULL, 
            0xE4A9DD29A3663835ULL, 0xBB01AB8A223EABCFULL, 0xC76F88A66A46DA9AULL, 0x5B41641179AAEACDULL, 
            0x78B03D32767A2991ULL, 0x725D027236D310AAULL, 0xA19C20F363FCA306ULL, 0x04F4547AFDF5C4B6ULL, 
            0x718F2442E3C872C1ULL, 0x2CF18803113E4E3AULL, 0x642FEC3A38ADAE27ULL, 0x958E47BA355D53E3ULL, 
            0x546AAF158A78A247ULL, 0x6B2C92FBDF0CEF4EULL, 0x4E6566D807408D32ULL, 0xBD70CA5E6A71A31FULL, 
            0xAF6D06191247BE9EULL, 0x85924107165E93EDULL, 0xCCA38952B4EED127ULL, 0xECAB15A963076CFAULL
        },
        {
            0x9F2CC42B09157619ULL, 0xB4FED600ED3B5374ULL, 0x24ADF605F5630F74ULL, 0x26E92039CC017850ULL, 
            0xDB6FA62606F01B71ULL, 0xFA12B9C79B953BDEULL, 0x442B88222DE980FBULL, 0x37B5EDDB0AD528F5ULL, 
            0xA84A0D03FF6047DCULL, 0xF0FC9AAF7772D4DDULL, 0x1862A30ADF41DD38ULL, 0x250C010C70F0B6CCULL, 
            0x31D5186B2E8B0FBAULL, 0x1F0F10E295E5C22BULL, 0xA2E056482DBFE261ULL, 0x9344888ED7FEA6E6ULL, 
            0x82A306515F9CEA23ULL, 0x3470AF1633BE6C82ULL, 0x290576ED53A9C1D1ULL, 0x89702626E1F98F2BULL, 
            0xFE7764F8703B09AEULL, 0xEE7702F2409C5564ULL, 0x8D127B8E7C501A11ULL, 0x3AA7473E695232F2ULL, 
            0xFEC2EBBDD73E4965ULL, 0xDCA15BCD3A3A745FULL, 0xE41F641E9179F881ULL, 0xBB8AFF0B31899372ULL, 
            0xB62DA924A140FB3CULL, 0x0D3B694A0AE9580CULL, 0x786A34D0260C6483ULL, 0x5CF1661AA91CE4C3ULL
        },
        {
            0xB2237D1284B83909ULL, 0x9CBBB72ED21ACF09ULL, 0xD3EF9DC1A4859083ULL, 0x212D26B798BB9C23ULL, 
            0x0B1F9B576FB170DCULL, 0x754A671E728D5BA1ULL, 0x2D43C3CCA76108DCULL, 0x0A5E522273511E0DULL, 
            0x36D7F174D6115002ULL, 0xE82FF18B61D21757ULL, 0x2EEE9FBCE88B926FULL, 0x8E053A3C51D4BF03ULL, 
            0x7B02A2D02AF8A87CULL, 0x01CF46F6FFEADD04ULL, 0xC63CA2B9B8426608ULL, 0x5DA024141D7722D0ULL, 
            0x01E32E4078BAAD62ULL, 0x8EBE65FD0645C73BULL, 0xC57D997EC3B5E862ULL, 0xAE4531045AB6965FULL, 
            0xD897866D497F76B5ULL, 0x72836D061B128B56ULL, 0xF980135B64B85F13ULL, 0x67A3074DAB1C3C0CULL, 
            0xB48B54927EBC2EA4ULL, 0x6F59BFD932477B4FULL, 0xFAAA3702C7A5E381ULL, 0x14A00A1AABE8592FULL, 
            0x5B8476183DF6941FULL, 0xFE42B338735AC835ULL, 0x99CCFDC9ED15457BULL, 0x1FC7B922D18E69DEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseGConstants = {
    0xD66FA7C4FBE31D07ULL,
    0x85B6098379DC44DDULL,
    0x8C7CBA781EB7FC2CULL,
    0xD66FA7C4FBE31D07ULL,
    0x85B6098379DC44DDULL,
    0x8C7CBA781EB7FC2CULL,
    0xCB90F9B5D63E182FULL,
    0x8CA921E0DCB12567ULL,
    0xEC,
    0xCF,
    0x3B,
    0x2F,
    0xFC,
    0x82,
    0x5B,
    0xD3
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseHSalts = {
    {
        {
            0xB3EE17908430D84AULL, 0x7CDD19985100DD4DULL, 0x9818C3F784325814ULL, 0xFF6306381031ECCAULL, 
            0x30D28BED7BDD244FULL, 0xCD0B0CF6698C1462ULL, 0x9FB3D5DABF502E17ULL, 0x16B61263F4727939ULL, 
            0x168C138ABBD24ECEULL, 0xBA42D8083CA2B2A1ULL, 0xAB07F242D6D8C4CDULL, 0x07778324A4478101ULL, 
            0x883E5E7C21EED8D3ULL, 0x10AA988290FE2512ULL, 0x8F2DB924A01A4D2FULL, 0x49C007AA1CE7787EULL, 
            0x98A740863443AE02ULL, 0xC7BD273FE6932417ULL, 0x315B430100FEC4EDULL, 0x0F59EDBBBC6AEF99ULL, 
            0x64707CA4ECE23291ULL, 0x242D3CB12648EDB5ULL, 0x84A6CC27119ECCD0ULL, 0xAE67B835A5C274D0ULL, 
            0xBED6F1CA52D5BFA3ULL, 0xDB30A3A6FBE9CE0BULL, 0x8BC3AC4672A774B7ULL, 0x7661482F2F743022ULL, 
            0x7388F7C65A145911ULL, 0x589E9BDD7B2194B4ULL, 0xCAE7DC14042412E3ULL, 0x1911522632EC7A23ULL
        },
        {
            0xA34B6879D1630FC6ULL, 0x5BF3C6FB2552C31FULL, 0xE8FA2C45595F25E3ULL, 0x2987A7F439C4ACE2ULL, 
            0xA642A6717AABD96FULL, 0x978E0CC49C0C2373ULL, 0x52C51A1E23F26E95ULL, 0xB2FFB9017DCEEA50ULL, 
            0x02D528A08D897D6DULL, 0xF04945C448CE7408ULL, 0x51D224BD03E16D77ULL, 0xEE0EAE877C151F1FULL, 
            0x40BD028EC0DE3409ULL, 0x9184EC944356F2B6ULL, 0x9DE3C749B8C8CDD0ULL, 0x81C3F4BAFBC2D40CULL, 
            0x8C11D89D3C759D0BULL, 0x1FF7946AA3F9879AULL, 0xF5DEB25A3ED84D78ULL, 0x5352063842D64E1EULL, 
            0x5E7FB35E1E284B87ULL, 0x724AE3ADFD71859BULL, 0x1C2F0AE8AE990BD2ULL, 0x3749B7B8DA7EBC8AULL, 
            0x80C1FD781BBD8C59ULL, 0xCB9D7D22CF1FCB2BULL, 0xBF58B7F9752A454FULL, 0x191D71214729DFBBULL, 
            0xEA3954D9848F9784ULL, 0xDB35AFCAD108D536ULL, 0xEFFA1EDBF3664E3FULL, 0x652E59959C7D769EULL
        },
        {
            0xC14D72E47FB34390ULL, 0x418BA0C7375AC068ULL, 0xD2D27D1083667F9AULL, 0x3070CF6F63D0A295ULL, 
            0x271988314D2D1562ULL, 0xEB5A73201A7495FFULL, 0xE43AE74385F5F32CULL, 0x07FEB84FAA343C75ULL, 
            0x56D0FD49BAF2235FULL, 0xC866756F4299A0D5ULL, 0x4D6B510BA9543EF0ULL, 0xF1B2A03DB4F3F17DULL, 
            0x6063EEA71AD6720BULL, 0x6A79802950CC86F2ULL, 0x5065965093D59491ULL, 0x468905B1B5EE5389ULL, 
            0xE48E59C94504784DULL, 0x19DF70391B91FE44ULL, 0x53F629C67B40FBD9ULL, 0xFE657CD09C620A6BULL, 
            0x01980C97DF8E2297ULL, 0x40A2A9FB579E1586ULL, 0x455322BBD2E34358ULL, 0xBF9B022D3F45115FULL, 
            0x780D1CFFC149F88CULL, 0x6A1BE5ADD4D4B95CULL, 0x7EE0315014275ABFULL, 0x1D8F2DBB9F6B89A7ULL, 
            0x245C9895FB34E575ULL, 0x3991D762142F55BEULL, 0x27868861332A431BULL, 0x2F60765EB673BA00ULL
        },
        {
            0xF4969E5161D11698ULL, 0xE7CD74EAD74D8BB4ULL, 0xCDD263ECE9B7F056ULL, 0x658894E7E1948EAAULL, 
            0x012FD02C88948DDFULL, 0x9CF5C466E529DCDBULL, 0x84CE639A330EE874ULL, 0x56733B482E9C3A0AULL, 
            0x9DEB589AD9AC0DEFULL, 0x7A4831A4CFC98EFDULL, 0xF473A76F836215F6ULL, 0x41C47AF537992470ULL, 
            0x5563E24A63C418FEULL, 0xAAD28F5C4F467095ULL, 0x50B361BC566BCD30ULL, 0x5D3E6C9A56F9BB60ULL, 
            0xF2A238498F56E48DULL, 0x271822FD7C3E6470ULL, 0x3F3C1ABB59B03386ULL, 0x5E706A128B09247CULL, 
            0xED407D65033665ADULL, 0xD8DB39871B2765ADULL, 0xA81551C4D755FE83ULL, 0x498DAC706626D986ULL, 
            0xC9998067AA9F7421ULL, 0x33E6BE1231AAB1BEULL, 0x4BB7A5FBD805004FULL, 0xB3682B84904D62C8ULL, 
            0x38B65872D7C90666ULL, 0xEA7E5D5AF160C2C5ULL, 0xC225D70D4E0010F8ULL, 0xAB77A29B7AAA7A5FULL
        },
        {
            0xFB5E188F687BC27CULL, 0x553EF48B9862F89AULL, 0x239B89CCC9B9489AULL, 0xAF902911C805980EULL, 
            0x4D0C1FEB237407F5ULL, 0x2AF6842A6D6E9329ULL, 0x1113D978FAE6F966ULL, 0x6881E5762574F67CULL, 
            0x936026D457171235ULL, 0xDE70543C11CE3C91ULL, 0x7729219F6888010BULL, 0xFA7753A7A56A8461ULL, 
            0x07CF93FA914D8F63ULL, 0xFF0F35585438B50BULL, 0x3A9D1AF403797AFAULL, 0x059454EA7C995E54ULL, 
            0x11813B8A2BEAFE82ULL, 0xAA521C8A74CA5969ULL, 0xA0FB1278A5E33F2CULL, 0x46E3FDE57B288659ULL, 
            0x2E0D385AA277BE61ULL, 0x543ADF035CABC4F5ULL, 0xAE2D23D1B145F947ULL, 0x4277CA6ED9A24CE1ULL, 
            0x0B602DC7E450ABC0ULL, 0x52785936E0CBC5B3ULL, 0xFE672CBE630228B1ULL, 0x7B47422B698E846FULL, 
            0xDD86C06B2224C451ULL, 0x71590D346F035EB4ULL, 0xEC24608F61CDF498ULL, 0x6182B7C0F156414DULL
        },
        {
            0xC43DEEDE85DAA84BULL, 0x4A6A8233F0C2BA7DULL, 0x1FCB569CD9A098DEULL, 0xF0A751AE57DBB2A9ULL, 
            0x9FD7C46287339D0BULL, 0xAE3CD9EA3563866FULL, 0x93E1545EF4ABC2ABULL, 0x37A62C3B0D8DA5A0ULL, 
            0x2671FD5A18075D4CULL, 0x8F1F07403EA7A4D9ULL, 0x9AEC90F6277ABD8EULL, 0x01B92B925FA74754ULL, 
            0xB073DFD5A7C551EAULL, 0x95229F8FCC65E6A5ULL, 0xED231F1CD9B2FA84ULL, 0xB4D17D817183CFA3ULL, 
            0xA300BF0DA3F0EE4FULL, 0x24D2E0AB45BDF3CAULL, 0x9402F0993BB6F4BBULL, 0xC323E79F5CD7678BULL, 
            0x80CE1EB19BFD9C4AULL, 0xA0BAB0DC6028427FULL, 0xD49B46CDD08CDC06ULL, 0x60C50D45AAFC59D9ULL, 
            0xAC30E8B3BC4C44D7ULL, 0xB4E3EA7533505E02ULL, 0x9D7A6D5269F4AEC1ULL, 0x139C7798AE554667ULL, 
            0x255C3C72AC83D159ULL, 0x71328083B8DE874EULL, 0x786100AF0E9C8EFEULL, 0xA77C73262C3DF5CFULL
        }
    },
    {
        {
            0x6935116063734BEEULL, 0xA32768B168190392ULL, 0x5967F889602EFD6CULL, 0x9F3FF3DFCA66D463ULL, 
            0x823B11353964798AULL, 0x8269300D835F95D7ULL, 0x91AF26668252C551ULL, 0xE2DB96955438F3A9ULL, 
            0x596EE11632476070ULL, 0xD6291AD961806125ULL, 0x655CCD92E71E8C9EULL, 0xBBDE3AE4C41D7AE2ULL, 
            0xF54CB078B4053031ULL, 0xC44A080A324CCBEAULL, 0xE0EF0DF3714F013BULL, 0x884D3B36C630827FULL, 
            0x5EE0BBA4284A8EF5ULL, 0x747FAE38885A205CULL, 0x80C6B1839794236DULL, 0x5732BC66C452E56DULL, 
            0x6CB80A3A6455E66DULL, 0x35454520D76D88E1ULL, 0xB71962E69DB4A413ULL, 0x54A84576622D9C3AULL, 
            0x92B4FB50A54E6BBEULL, 0x4187CC4F0B2E4D12ULL, 0x9F8C770FECAC8C83ULL, 0xD7798569290B0031ULL, 
            0x5B34615BFF32105FULL, 0x3A002433A5FF18AEULL, 0x9C3C7BE3D786A955ULL, 0x21590CA2C1F08AABULL
        },
        {
            0x1CFC4A360BF49527ULL, 0x7E32CFB618730FCEULL, 0x55B3E7F0CC463D0FULL, 0x8071F27BB09E71E8ULL, 
            0xB664D5E397B9E86FULL, 0x51FC17628644B98CULL, 0xFDC9CA2028BAE687ULL, 0x454DE1A89D536A5FULL, 
            0x0DDDE36E6B6F7309ULL, 0xFD5024639D3C6634ULL, 0xADD584AE12702D0FULL, 0x6CB5477BC03260F4ULL, 
            0xE10773291501A36AULL, 0xE1456D23627F7E6AULL, 0x4788156824BC5866ULL, 0x95CC31B15A868A2FULL, 
            0x7357AE133D4B2308ULL, 0xFBDB0BABA9D6BCFDULL, 0x22BA367A6C055B54ULL, 0xCE6C204B88090718ULL, 
            0xCA3E699B8BBAA19EULL, 0xDCD55F8916AFE60EULL, 0xA31133CD78B45D91ULL, 0x1E7C7A3AAE1E5AD3ULL, 
            0xB8821060580C920BULL, 0xAA36E6AFB5CEA68AULL, 0x121176C23D72B682ULL, 0xEF2FD3C4FD939A2DULL, 
            0x28A2B7C40BE6EF90ULL, 0xDD58F0A8A006DD43ULL, 0x48F6AC01E2A82373ULL, 0x963F67E96A5E6F75ULL
        },
        {
            0x2EEC278541E50D2FULL, 0x3D929CD904FE8C9AULL, 0x688674C047E7E727ULL, 0xF78A1D22258FB2AEULL, 
            0x1EAD4E7BA122B9C3ULL, 0x67792447BC07CBA7ULL, 0x712D71A8FA5DA4D1ULL, 0x0FC8471310C60ED3ULL, 
            0x576C07836C6AB655ULL, 0x6AE1FD0A0CFA2EACULL, 0x6578E79982DF2A43ULL, 0x310BAEEBE42D6D04ULL, 
            0x2A7B626F6657743FULL, 0xC9EA43B2760FFCD3ULL, 0x202DA3936EE0F969ULL, 0x5128AE94E097FE0CULL, 
            0xEDA16E470FCF1F82ULL, 0xF5BC8F2BB786A808ULL, 0x51D786CF31924827ULL, 0x8AB27B9CC5671266ULL, 
            0xEC5CCC0FFD780CE4ULL, 0xE7EE20FC1229EF8FULL, 0xE45B8899173ABE49ULL, 0x3F6287359E6C3F0CULL, 
            0x1EAF33E45BA72775ULL, 0x25AD3DC54D8E1D8CULL, 0x997EC3D749BC19B6ULL, 0x55F5C1C8D5393459ULL, 
            0x97ACFB16DB294914ULL, 0x52DC80E10D8318FCULL, 0xB6E93EFB65D3E59DULL, 0x5B447999CD5818CDULL
        },
        {
            0x69BE62EBF996B4B2ULL, 0xC20969CB332E963DULL, 0xE0C26370CA099A98ULL, 0x907727D95B0D85DCULL, 
            0xD06BCCDFF848D049ULL, 0x65CC4EDF60C84CA4ULL, 0x5BD9DCF08E24EE7FULL, 0xB2142266838F6C91ULL, 
            0xB2ADC2B54F2B8F01ULL, 0xAE49F606EB945FD2ULL, 0x6B85955C91A7EA2BULL, 0x69E83ABD85FEEB81ULL, 
            0x8C040FFEECD90FF5ULL, 0x0E7F70CE9F564BB0ULL, 0x671B0ACCDFE0619AULL, 0xE30562724D8D5858ULL, 
            0x82D352B5A7A30801ULL, 0x6D6FCDED669BF67BULL, 0xAF2CED9071B73F87ULL, 0x480889C1E3994065ULL, 
            0x89F4DA3DDA3FA484ULL, 0xC989B3040F846811ULL, 0x2560C395EED06275ULL, 0x8E59B71137621591ULL, 
            0x6E612869AB2C17A6ULL, 0xDF629E41801A6FFEULL, 0xCD260041456EB23AULL, 0x0EA34572F622985CULL, 
            0xE155E3B08507BE9DULL, 0x27F431B09C2D127DULL, 0x3AC26E7B0FE4C619ULL, 0x85A241414FFB1D75ULL
        },
        {
            0x3BA2AC364E53ECE6ULL, 0x047281DB553BA8AAULL, 0xADB0323CEC662B7BULL, 0xBA86EAD2BF8498AEULL, 
            0xA49243AA34741860ULL, 0x8FF954A927AED891ULL, 0xA71CD1056D225B70ULL, 0x0180AB7454A20D1EULL, 
            0xC4076EE13739EABDULL, 0xD6574FFF8BBA23DDULL, 0x8A3D3B0E9C9FB66FULL, 0x958E83D45B3EC948ULL, 
            0xDC68620BB53DB68FULL, 0xECFB30BE3A34A963ULL, 0xAA134A0AD2B7B166ULL, 0x6E870D04D01CE332ULL, 
            0xF1905A17B0CBEFBDULL, 0x42E53FCEF019CDD0ULL, 0xC6B7973322FBF877ULL, 0x7671A2C3878159FCULL, 
            0xBCBA13CF0E30D104ULL, 0x0500D903F8E47D5BULL, 0xDDA7247501CD3A35ULL, 0x3E119CC17329B8D5ULL, 
            0xBDA9771DFBE0E332ULL, 0xAD77DB139ABF62AFULL, 0x05C0C292FC857D0CULL, 0x5027A1ECB30B60C0ULL, 
            0x119C1C29101E30D5ULL, 0xBD23BCF7DFB11FE2ULL, 0x6DF6900ECBD59E4DULL, 0x2F4C29F7568484E2ULL
        },
        {
            0xB04D275217C1E9A0ULL, 0x3360FABBC4541C12ULL, 0x3261EBE908CFFC14ULL, 0xD5B4C9E4A3BF3063ULL, 
            0xBC552C413517DEC0ULL, 0xE538DFDAC3AF6AF9ULL, 0xC27A36D47BF056D9ULL, 0x2904FAAA685F3736ULL, 
            0xD54EFADECE6947C9ULL, 0x04F97AE6B1D073B8ULL, 0x7DF86C9A644B0A1AULL, 0x03F0041BB30A794BULL, 
            0xB818912F12EB8D0AULL, 0x616E8A1FA57B05E0ULL, 0xFF545D60777DD43CULL, 0xB778B4762710966BULL, 
            0xEE19636B5DA78D89ULL, 0xC49C7476324030D2ULL, 0xDE0CB1040586925BULL, 0x3537AEEEB6D49093ULL, 
            0x648A1E5B77AE9E53ULL, 0x4AFD48DC4C353300ULL, 0x6C5FBAD78FBBC1ABULL, 0x53A07EF12227F5E4ULL, 
            0x4F867520B7883927ULL, 0x707DBEA9C25D19E8ULL, 0x3F0523C1560E0016ULL, 0xA1FEE00552A3B8C5ULL, 
            0xCECF8E1E48729A55ULL, 0x6E00284695EDA99AULL, 0xBA1398B373AFCDEAULL, 0x1369E59112162F70ULL
        }
    },
    {
        {
            0xF9F70BB4FB6F7617ULL, 0xA3BB94E2E284D98EULL, 0x5969B62362077D3CULL, 0xCA04AC4E19FED614ULL, 
            0x9E1FEBC4D389BE54ULL, 0xBA3B69B383EDFB45ULL, 0x127560A94321713CULL, 0x95A8CA428B351F6BULL, 
            0x29A426FF50BA2A57ULL, 0x4A24D5D940735C68ULL, 0x51558335E74A5864ULL, 0xA506DF5A17087CDAULL, 
            0x11567998DB7CB53EULL, 0x835B0576D94E6B95ULL, 0x168FD551D6E4AFC8ULL, 0x4AC8D98843B9270CULL, 
            0x65A98341F43FEA2CULL, 0xC70C52248631C241ULL, 0xEA2DD78E1BD98B3DULL, 0x1A0CE40920B4CD7BULL, 
            0xFDCBBBA86F06A37CULL, 0x4E891BEC8D25005DULL, 0x215986E53E333D17ULL, 0x3C2BDE1C35A12588ULL, 
            0xB9B4D461DD6D4443ULL, 0x54AC043583D98032ULL, 0x6B9E87D1193173F2ULL, 0x5B1B412ECD159E69ULL, 
            0xE68B009AF5361CAFULL, 0xB716AA24E88FF1E8ULL, 0x78827BA34F87EEF5ULL, 0xAD736F70FAB0EDEBULL
        },
        {
            0x13639CDE5C0361FDULL, 0x920D6DE64F9D21EFULL, 0x31C960E16864156BULL, 0x650F8C91525D5D6BULL, 
            0xB8E3444BAE6A9D88ULL, 0xBD0B8328FB8A04E4ULL, 0x0B37749B363099A6ULL, 0x7BFC2A5325FF5D37ULL, 
            0x2BF3F26CE3BD9676ULL, 0x5E914ECF9043687CULL, 0xCB559FFD04D055F2ULL, 0x77CF00F34ECCE408ULL, 
            0xCA9D7E08BCECE055ULL, 0xB2CD1705D1385176ULL, 0x781F623A5FD0F1FBULL, 0x293A8D6B18CC41FDULL, 
            0xCEDEE4489612A2D8ULL, 0x2919ED39BB8319B3ULL, 0x36BD88FE5AF50C87ULL, 0xE65D9FB2F82474BBULL, 
            0xA50220CB2BC4D567ULL, 0xCFCE426F889B5633ULL, 0x798A6A79BFCEDBCAULL, 0x9DADF1018B82FB1BULL, 
            0x55067F2D313A64FFULL, 0xA279FE43D22F07B8ULL, 0xD5D02E262C0D1398ULL, 0x114BB6C54AD42546ULL, 
            0x90BF73FD8F5143FAULL, 0x34C1D56882B5CF83ULL, 0xE8F0302EC9E2FF70ULL, 0x49E51B1702D0E0CCULL
        },
        {
            0xCEDA2D83A50F10CCULL, 0x1580851CB5F0731BULL, 0x858E95D5063C8E12ULL, 0xF35E6C890DBB2BE9ULL, 
            0x562EB3594778F8D8ULL, 0xA98287D3D3F82752ULL, 0xD0A53E580B405967ULL, 0xE4FE079A79384951ULL, 
            0x041B7DF3F190E9A0ULL, 0xDCDA171258E8A9BBULL, 0x82E8B059E74A80C8ULL, 0x2EC465D2359968EEULL, 
            0x5A72B9DACB5757FEULL, 0x42F8C700B612B6FBULL, 0xF49D2A5B136EF2C4ULL, 0xC6D7E25A2984D5A9ULL, 
            0xFFD482B536E7A5CCULL, 0xE046753B0EF9A511ULL, 0x5280B1D3F3475FEFULL, 0x72C865B059E8C50DULL, 
            0x96C66600A54D98DFULL, 0x8558E769E5CFE526ULL, 0x74627746D184960AULL, 0xB7C525E6B1DF2448ULL, 
            0x0AD258A2088C6853ULL, 0x5C9AD09FABAE0A5EULL, 0x7FE46E58015C769BULL, 0x0AD3340B11BD4512ULL, 
            0x872A2F0602E680A4ULL, 0xB0E25DD019D0F45AULL, 0xBD0DE362EDBE7E2AULL, 0x9CCCFA4AA62A847AULL
        },
        {
            0x3F398F538AE8E1B4ULL, 0x901E970C74B923A2ULL, 0x126F5FD7406CF745ULL, 0x3D38AD82017FF2C7ULL, 
            0xFD0995C7C5796168ULL, 0xA8522051BF53A6E4ULL, 0x6ED33CC96C9878E2ULL, 0x9A6999DF15AAD47BULL, 
            0x862137DF389ECA50ULL, 0xD07DEA7E89258D2EULL, 0x7406D816D043F467ULL, 0x6E79DA030439CF43ULL, 
            0xC77935B799B2D462ULL, 0x17236A1262E615E4ULL, 0xE4525ABA1554E7B7ULL, 0x878C5CC812D9FB55ULL, 
            0xB4CDF5FC4B0728AFULL, 0xE08F889F397D80BAULL, 0xC67F214EFC91DD16ULL, 0x2420C1B15CD76D1DULL, 
            0x68BD310B6108F554ULL, 0x57964EA480A213F4ULL, 0x9505B40B6B62CAEDULL, 0x4D4631F68A53E9C8ULL, 
            0xF11408A7305D7ECAULL, 0x027EE6021DAA2142ULL, 0xBA6EBA7B55DE0E42ULL, 0xAEDCEACD7DEF9170ULL, 
            0x03DF7592A985A092ULL, 0xA523BED5E2A1E739ULL, 0xB35CE79AD774DD78ULL, 0x1BA3684E11A0E0C6ULL
        },
        {
            0x91CC77FE324C2E3DULL, 0xEB3AFB900EEE79B0ULL, 0xD10A998A52916A89ULL, 0x3707B49AB0F109DFULL, 
            0x7F0FCEF3C7CAADFAULL, 0x8A85172D027A035CULL, 0x17AC5990C749D15DULL, 0x44BEB8A9DBF23938ULL, 
            0x00144EEC8DD55DB4ULL, 0x5F79AD41CE11B909ULL, 0x066C92B9AC94D28FULL, 0xF9D93712C8EFEE2DULL, 
            0xE4A537DDF0E91A69ULL, 0xF3AF797A132D125EULL, 0x636DC7D637DB1250ULL, 0x42FBFFDC43379AE0ULL, 
            0xB196E49289542B39ULL, 0xDFB18F7FB01018B9ULL, 0xB1805EE5210CB309ULL, 0x39CA1724B42EBCC7ULL, 
            0x8ABD67C2DDAEA604ULL, 0xBAF4B7AFCD7A4E74ULL, 0xEF274D7F701FC986ULL, 0xE62A7B7C3F179BB7ULL, 
            0x5587121CC5D3A494ULL, 0x0B01BED78782FEAAULL, 0x33B53BCFB8538F30ULL, 0x241D0692A1D501C1ULL, 
            0x4702FE56CAF7D35DULL, 0xCAA0D833D05A8BA8ULL, 0x6D311BFF88FD2D32ULL, 0x237EC8B8FF2E0DB4ULL
        },
        {
            0xB8AFED9117440DA1ULL, 0xBD67B4F76778AC10ULL, 0xB993B84FCEEAFB54ULL, 0xA31A7D4AA4051DEBULL, 
            0xA8CFCB71F6882AF6ULL, 0x104CBDC7FDA9F260ULL, 0xD08F4A6D5BA40977ULL, 0x5E1D2E6BD46B3E56ULL, 
            0xB15B36063D685407ULL, 0x14425EE4B7DD9155ULL, 0x9FFEAC81676276C4ULL, 0xA3A1A6189346E2EAULL, 
            0x2E208912C75683AAULL, 0x3A76470749F7E7D2ULL, 0x4A4739E2B0EE3520ULL, 0x36AB13D7114827D4ULL, 
            0x71ED6F17EA201058ULL, 0xCCA9BE89DDA9972CULL, 0xB806E6F361C34675ULL, 0xE6AEA945D43C8AA2ULL, 
            0x90EDF19A2E90EF5DULL, 0x33AC47A4DFA59355ULL, 0x73B8C823733C8710ULL, 0x9FE859E4019C0674ULL, 
            0x7065FEA975562D12ULL, 0x9364CC608063489EULL, 0x7317C922506965D5ULL, 0x4ED0FF08B5EE68BDULL, 
            0xADA302D6DFFCA0C0ULL, 0x0392096E6D4E92B9ULL, 0x3D96BC48CFBF677EULL, 0xE8340B9C2AE05206ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseHConstants = {
    0x075E5B8F6F7F7FDDULL,
    0xAC3DBC3E12947204ULL,
    0xACA16C1D6E7B0C59ULL,
    0x075E5B8F6F7F7FDDULL,
    0xAC3DBC3E12947204ULL,
    0xACA16C1D6E7B0C59ULL,
    0x37862E5AF05BACFAULL,
    0x192D62586DA3423EULL,
    0x4A,
    0xF7,
    0x44,
    0x16,
    0x8F,
    0x6D,
    0x0E,
    0xFC
};

