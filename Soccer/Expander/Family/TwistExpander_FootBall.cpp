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
    std::memcpy(&mDomainBundleEphemeral, &mDomainBundleInbuilt, sizeof(mDomainBundleEphemeral));
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
    std::uint64_t aPrevious = 0xC2885A268C956A79ULL; std::uint64_t aIngress = 0xABF8222E76ECA984ULL; std::uint64_t aCarry = 0xD910AF4867EF37AFULL;

    std::uint64_t aWandererA = 0xDA5FAE179CE53CD5ULL; std::uint64_t aWandererB = 0x8AB6C078DE1AA57FULL; std::uint64_t aWandererC = 0xA816B4EEA8520401ULL; std::uint64_t aWandererD = 0xBD3C0F3206A912E0ULL;
    std::uint64_t aWandererE = 0xB062D1B0C623B3A0ULL; std::uint64_t aWandererF = 0x954CE4D434CC398FULL; std::uint64_t aWandererG = 0x9DC8857350D73995ULL; std::uint64_t aWandererH = 0x983BCB4E785605D3ULL;
    std::uint64_t aWandererI = 0xB49AA49FE57F667AULL; std::uint64_t aWandererJ = 0xF501FC92F6F4795EULL; std::uint64_t aWandererK = 0xC49E3315F2F54FF1ULL;

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
        aPrevious = 9277819407645697683U;
        aCarry = 9749208723955568918U;
        aWandererA = 11219735285147048214U;
        aWandererB = 15931678081707388937U;
        aWandererC = 15047661043126365431U;
        aWandererD = 17017598244386271213U;
        aWandererE = 17050613242487899998U;
        aWandererF = 16641707445857290210U;
        aWandererG = 10278862732133991728U;
        aWandererH = 13776098593506345901U;
        aWandererI = 9581752133396800903U;
        aWandererJ = 17753304307720181906U;
        aWandererK = 10017562477501711125U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
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

}

void TwistExpander_FootBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA7A21AAAE870F314ULL; std::uint64_t aIngress = 0xBCD0F787ACC0ADAAULL; std::uint64_t aCarry = 0xEFDB741769637556ULL;

    std::uint64_t aWandererA = 0xDB6FC6E7EBEA70D6ULL; std::uint64_t aWandererB = 0x9D6E32DA7229E6FEULL; std::uint64_t aWandererC = 0xBCC016DC899560D8ULL; std::uint64_t aWandererD = 0xF203C61D59B96F1FULL;
    std::uint64_t aWandererE = 0xF07BE710809DD605ULL; std::uint64_t aWandererF = 0xF188EA4343BEDCCAULL; std::uint64_t aWandererG = 0xFE68D7B80DED2241ULL; std::uint64_t aWandererH = 0xDB4548B630D32B2FULL;
    std::uint64_t aWandererI = 0xA6B1D76BAC93ED9CULL; std::uint64_t aWandererJ = 0xBCD0FDB4D3D391EEULL; std::uint64_t aWandererK = 0xA3E156CC7D5195D4ULL;

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
        aPrevious = 17052548989100206173U;
        aCarry = 14051410774491567505U;
        aWandererA = 9914818582849525114U;
        aWandererB = 13015107623229160547U;
        aWandererC = 16156751472011164003U;
        aWandererD = 17470175378213355324U;
        aWandererE = 18070687519603760433U;
        aWandererF = 11202106536245854298U;
        aWandererG = 10006403481024608970U;
        aWandererH = 14384480043461746707U;
        aWandererI = 17098267272049708759U;
        aWandererJ = 16078630620033097359U;
        aWandererK = 14979701343136993424U;
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
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
    std::uint64_t aPrevious = 0xB95335A50B966805ULL;
    std::uint64_t aIngress = 0xFEF9677675155FACULL;
    std::uint64_t aCarry = 0xDD05F2175DC00CA7ULL;

    std::uint64_t aWandererA = 0xCF6C0F8D44392C64ULL;
    std::uint64_t aWandererB = 0xECCBABDABD7F14F5ULL;
    std::uint64_t aWandererC = 0xC724C1F8E9FB713BULL;
    std::uint64_t aWandererD = 0xA597017090B239F5ULL;
    std::uint64_t aWandererE = 0xCA938686AE4A77E9ULL;
    std::uint64_t aWandererF = 0xD3DF4237196D01C8ULL;
    std::uint64_t aWandererG = 0x9C107A625C384C1EULL;
    std::uint64_t aWandererH = 0xE5F562878062870EULL;
    std::uint64_t aWandererI = 0xFD93BB42AB8626DFULL;
    std::uint64_t aWandererJ = 0x933ADBFBFA27FBA5ULL;
    std::uint64_t aWandererK = 0x95106FCEE84AE309ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, operation_a, operation_b, operation_c, operation_d
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // GSeedRunSeed_F seed_loop_f:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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

        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
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
    std::uint64_t aPrevious = 0xE0A88E12733D20FCULL; std::uint64_t aIngress = 0x9553C15DE84ACD5FULL; std::uint64_t aCarry = 0xD437A4D3AF9F6BC9ULL;

    std::uint64_t aWandererA = 0xD01340EA0E405677ULL; std::uint64_t aWandererB = 0x8161BBBDA5A9997EULL; std::uint64_t aWandererC = 0xADBD5804058EA7ADULL; std::uint64_t aWandererD = 0xA088A1F85E574302ULL;
    std::uint64_t aWandererE = 0x8CF445CBCB10AA3AULL; std::uint64_t aWandererF = 0xE2445CC941DD37B1ULL; std::uint64_t aWandererG = 0xB569C1436DE57A64ULL; std::uint64_t aWandererH = 0xD776852B6049E5C5ULL;
    std::uint64_t aWandererI = 0xB6439B42249A9EE1ULL; std::uint64_t aWandererJ = 0xDB02E0694DC9B848ULL; std::uint64_t aWandererK = 0xF37AAEF096A861A1ULL;

    // [seed]
    {
        aPrevious = 11564310830962064030U;
        aCarry = 16109115795220449584U;
        aWandererA = 15443703072343054541U;
        aWandererB = 11992458554106553137U;
        aWandererC = 15225241776662763322U;
        aWandererD = 14781179788217179641U;
        aWandererE = 13305171590584964269U;
        aWandererF = 11037186598795369512U;
        aWandererG = 10379475264847027690U;
        aWandererH = 15638285155309091441U;
        aWandererI = 11073701795985234366U;
        aWandererJ = 16488990500571097089U;
        aWandererK = 11157552289374204392U;
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
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
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        // ---------------------------------------------------
        // write to: work_a, work_b, work_c, work_d
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
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 2, 3 with offsets 7882U, 5934U, 5608U, 7468U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7882U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5934U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5608U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7468U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 2 with offsets 4352U, 2967U, 7023U, 1463U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4352U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2967U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7023U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1463U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 288U, 1732U, 5814U, 5192U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 288U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1732U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5814U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5192U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 1 with offsets 3376U, 75U, 7686U, 4900U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3376U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 75U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7686U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4900U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 with offsets 88U, 1923U, 525U, 664U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 88U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1923U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 525U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 664U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 2, 1 with offsets 1675U, 1130U, 720U, 1308U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1675U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1130U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 720U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 0, 3 with offsets 1056U, 1180U, 742U, 749U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1056U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1180U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 742U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 749U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 449U, 430U, 305U, 967U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 449U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 305U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 967U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 607U, 422U, 149U, 415U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 607U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 422U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 149U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 415U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_FootBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 3 with offsets 1255U, 1109U, 7124U, 1942U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1255U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1109U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1942U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 0 with offsets 4789U, 7113U, 1696U, 3183U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4789U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7113U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1696U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3183U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 1 with offsets 1206U, 2755U, 4099U, 5446U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1206U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2755U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4099U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5446U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 2 with offsets 7748U, 4219U, 5448U, 5771U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7748U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4219U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5448U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5771U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5894U, 7776U, 535U, 5198U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5894U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7776U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 535U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5198U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1525U, 1088U, 289U, 1215U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1525U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1088U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 289U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1215U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 616U, 1931U, 373U, 1950U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 616U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1931U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 373U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1950U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 712U, 1961U, 1169U, 1306U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 712U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1169U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1306U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1306U, 570U, 228U, 1099U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1306U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 570U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1099U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 0, 2 [0..<W_KEY]
        // offsets: 837U, 849U, 498U, 1610U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 837U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseASalts = {
    {
        {
            0xC9F11A8664661352ULL, 0x1F55926BF34F1F8BULL, 0xC8126ACA505C0F52ULL, 0x60665D605D5B7D8BULL, 
            0xCCF03D75C1D77B30ULL, 0x16AE650C574BB54EULL, 0x748F78313096BF03ULL, 0x50F91F53FAAAE66BULL, 
            0xC396A7F165522746ULL, 0x8AF77B413735BD14ULL, 0x541FC901BDB977A2ULL, 0x9C9CEDAA077EB2AAULL, 
            0x28FCD8589ACB5B48ULL, 0xE58B1BBF0B269E6BULL, 0xADE5B2984EF4A261ULL, 0xB508E27A9D594B1AULL, 
            0x254C5D25D953D452ULL, 0x8B40B79FE3815355ULL, 0x81B9A49BF4A3196BULL, 0x7A3914ACDF018448ULL, 
            0x4FAE07CB5D50EBB1ULL, 0xB2488893E2ECF6B3ULL, 0xB02938D062CDF341ULL, 0xC93B6F946EFE306AULL, 
            0x4C7169DBB48021ABULL, 0x84183E63DCB1286CULL, 0x2CBFEB46CFB8E5DAULL, 0x6B35F66CC4E3B266ULL, 
            0x5B6323947E584D79ULL, 0x54D7C18C92CAEE5FULL, 0x888B8BB20B2EE0C9ULL, 0xA4E0F4065FC16554ULL
        },
        {
            0x93B13501894C0008ULL, 0xF72E7886C8B31FFCULL, 0x277A0A98A75E35D5ULL, 0x7F314FD4BCCB221DULL, 
            0xE0DA7EDA2DDED9E4ULL, 0x983AEB26F2B4A6CBULL, 0xD5C2F1DA7EC49BE4ULL, 0xDA47ED5598028468ULL, 
            0x3C811A64FFE4520CULL, 0x0C2A2D161C4B9170ULL, 0x9934C1B7EBDE6C7FULL, 0x88187C5D21F3A668ULL, 
            0x5EDB55ED3D980953ULL, 0x292CA751A2FD0116ULL, 0xF677BBE3EFDB718FULL, 0x0A0AB95A5F19232BULL, 
            0x621AE57FA0B4D354ULL, 0x59465DA7B4231C21ULL, 0xA5C273935A9B5C72ULL, 0xD3913D19B2C0B642ULL, 
            0xAD81C4E6CA6D87A6ULL, 0x5635F8AEAC69A6D4ULL, 0xEED47F331ADE60E4ULL, 0xA957F54CB5CB9DE8ULL, 
            0x3BADFA1F0F6F8FE9ULL, 0xD99A0CCD60EEE852ULL, 0x5F3ADD57BAA80610ULL, 0xB86223317CEA0448ULL, 
            0x490B624772555065ULL, 0x4900B78855FB2402ULL, 0x207942D1721378FDULL, 0x64728A41D74111B0ULL
        },
        {
            0xFC54877E9E1123A9ULL, 0x6689EC159FDE2720ULL, 0x78BB7B9D341F1590ULL, 0x723099326A28EC90ULL, 
            0x6BA46547BD338A20ULL, 0x4FF9E5981F777241ULL, 0x86A5F4D7062CF79CULL, 0xBB71633519311924ULL, 
            0xCAB2FF46088780CBULL, 0x690925E05AF5C7D1ULL, 0x3C4390290A9FA117ULL, 0x84683F9D8177D46EULL, 
            0x3425592520EF514BULL, 0x85CAC4C413FE4C73ULL, 0xC825EDB98319DAC3ULL, 0x5FFD9F1BC034E0EBULL, 
            0x1F8ECBAB3BCABF86ULL, 0x7F7DA493319DE1C1ULL, 0xAACAB7A6BD8B3E0FULL, 0x97016A54D5E2C7F2ULL, 
            0x98790F042617A9D1ULL, 0xC461E3E3E2AD8506ULL, 0x2BFC73C9FF02DA28ULL, 0x4A31F9E59F52866FULL, 
            0xAD7512C95A39F4E7ULL, 0xCAB24CD555CABFCCULL, 0xED423A07AC004EA5ULL, 0xA1AD3E57C1D0EFC6ULL, 
            0xE73D0376ECEBE97AULL, 0xAFB761C1740486A0ULL, 0x3BCB2BE24B13B8DEULL, 0xAAC44EAD6D3D9336ULL
        },
        {
            0x51C21C69EA4F7A00ULL, 0x0D35B2FCCC683395ULL, 0xA25D95ED6B8A3612ULL, 0x9732444AEBAB6444ULL, 
            0xA0EF928F58C0B0B5ULL, 0x69343AA605331383ULL, 0x82E3DB2B3D7169B5ULL, 0x7462899B396F08FFULL, 
            0x23F45B0E7FB75FC1ULL, 0xB79A6AC196095FC3ULL, 0x993334FCD97D02A4ULL, 0xA84623EBD29E0B08ULL, 
            0xAF1C0F2D192EE644ULL, 0x25396167013BCAE8ULL, 0xBFFD988B6C3E55B4ULL, 0x83EBDA436ED848FEULL, 
            0x9F5E3B621A1B5AF7ULL, 0x530A0EEFE6121DEDULL, 0x4C5E3C918C2ED8A9ULL, 0x94C6163E29F3AAE0ULL, 
            0x9D06F520C1B2390BULL, 0x3EFD25563FE35C1EULL, 0x1CB2CD4D71194D59ULL, 0xDC3CA13E7DFAFBDFULL, 
            0x3953F0D57912AA68ULL, 0x02D801B019BB290CULL, 0xB89A474764238A60ULL, 0x21C52E7B155EBCDBULL, 
            0xA10220B392BBD938ULL, 0xB435BC78885FA578ULL, 0xC44C97DD752D1524ULL, 0x68B0F1C4516CF49EULL
        },
        {
            0x2AB7D2F48082F285ULL, 0x5BF0DDF1A49DC8A6ULL, 0x03F9D2AC9AE7A7DEULL, 0x918620677511F10CULL, 
            0xA918633380B94BC7ULL, 0xA1CF40EBE8657EC4ULL, 0x66A7EF7E9F0EB40BULL, 0x5407DA12ECA0E7A7ULL, 
            0xF2C4790870B47DF3ULL, 0x72443A9D8979359DULL, 0x2B5D05C2B0FE7FE2ULL, 0xE48AF1C58218AA0AULL, 
            0xB364B80160F82D88ULL, 0xE2DA282C5620A940ULL, 0x112564262A0E72D4ULL, 0x7D793E94288B3582ULL, 
            0x9CD10ED43ADB0617ULL, 0x93C353C76C77E8DFULL, 0x1E3743FA9B118C2AULL, 0x450089CF697D2C40ULL, 
            0x3FD5C1D865FBDEE6ULL, 0x771F4C4B26D5A7B2ULL, 0x340A2DE06C61509FULL, 0xB1A03284753F5DDEULL, 
            0xB32930A533EE561CULL, 0x942DAA3C9085F757ULL, 0x759F750403111F74ULL, 0x330E135AC5D17776ULL, 
            0x9A1C0FA040E82C78ULL, 0xF91799888757E25EULL, 0xFC6FDED711437D0EULL, 0xCD8F78F2F1FEF40AULL
        },
        {
            0xA0043AA167C7B083ULL, 0x0ABD31284CF34ECDULL, 0xFA4B65E0FBDB553FULL, 0x7772FC955E90BF81ULL, 
            0x81A579BBB15C8F9FULL, 0x91D2E432BE3692ABULL, 0x05B19A5A2D0A15E2ULL, 0x60A6E7A8756F028AULL, 
            0x9ABFBFA5C16597C8ULL, 0x921A14EE24772B11ULL, 0x295A6BDA4FA327E3ULL, 0xBD5FD553B29D9F6EULL, 
            0x7A91798D20A3A262ULL, 0xCE87B95AC8B156AAULL, 0x1D2E84BE3248F75EULL, 0x94192850C3C74857ULL, 
            0x897B2EF208A886CEULL, 0xE34C639A36462383ULL, 0x14F4CA02527C41B2ULL, 0x03A9C73790E4E269ULL, 
            0x209F44530F0E99E7ULL, 0x6388444E3C4BCF14ULL, 0x3F4993E452AB364BULL, 0x7257D9EF554967BDULL, 
            0x847E576B9213AE4DULL, 0xD3EEF3139B86F792ULL, 0x3E110B637B12BC4DULL, 0xF0594429E45C8D1AULL, 
            0x407E1E63E671E26DULL, 0xA4EB4EBE7349252FULL, 0xF58C0F8303F1E773ULL, 0x839D3AC2BF5F6706ULL
        }
    },
    {
        {
            0xE633175364CF5DB1ULL, 0xEB6C1ED33F08BF1AULL, 0xC04C03164CD73ABCULL, 0x205D3CD5981AAC4AULL, 
            0x91D2E2CF540B06CBULL, 0x69BAA770370B0D0FULL, 0x09B7520EB5E78DD9ULL, 0xE5EAA3B3E8A876E8ULL, 
            0xBAF3C1DA6DBF6941ULL, 0x1B6B74060216F260ULL, 0x8BD6D17A9ECF252FULL, 0x6A1B2BABD5A92DC9ULL, 
            0xBC2BBE5E66C99C00ULL, 0xAB7113D670E58BD5ULL, 0x78E70161AD3C05A9ULL, 0xB5E540EB8C13F267ULL, 
            0xEA44DB55EC138DC7ULL, 0x05F649F93C2FF944ULL, 0xE6F10F5B6A30502AULL, 0x9A023A32932EE910ULL, 
            0xF21152CB5495F6C3ULL, 0xF4CEFD36B6B350DBULL, 0x119D33BCB7182E0FULL, 0x663EFAF701144F8DULL, 
            0xD9551005934682AEULL, 0xC05B709DFF1916B1ULL, 0x58613AF044AA6A0BULL, 0x58AED19516C9E7F3ULL, 
            0x08F9AE45BDAC98F0ULL, 0x0D567DB727056DC5ULL, 0x641A47FD4BC9EFC8ULL, 0xBC5037096E348F89ULL
        },
        {
            0x0389869EEE9725D5ULL, 0x06896A1F64B7752AULL, 0x9D78EEAAD8425BC0ULL, 0xF32D2AE2E9C09706ULL, 
            0xA314726BF266FC2EULL, 0xEF0089D1493AC2EFULL, 0x60E10391E6AC9039ULL, 0xA71659F797914E17ULL, 
            0xD87391A3EC81C4EFULL, 0x6EF183822858793AULL, 0x374B9B4E92E0D417ULL, 0xA8D3710D5F715398ULL, 
            0x6D55E8AD3B1F1F25ULL, 0xAFAE560C9E02160BULL, 0x90691909C2903EA4ULL, 0xE6932C765305A7FEULL, 
            0x3D084F02C1600FE4ULL, 0xB6E4D605F5521BEFULL, 0xCF646E646EBE37BDULL, 0x55D5DF49D300FFDDULL, 
            0xF459DD22679FE97EULL, 0xBFFF5BEF2DD9D7C0ULL, 0x3CAE8E61B4C98C6CULL, 0x89C214875625A9C9ULL, 
            0x5043C7E5C5369C51ULL, 0x40E9404132A13872ULL, 0x3E8648FAF78AB524ULL, 0x31302C6C080505CDULL, 
            0x4BFFDD37A7E41CB1ULL, 0xA85B6A2066B56632ULL, 0xC43CB6C61D419E22ULL, 0xAA5B2A39704C92F8ULL
        },
        {
            0x0E16EB248F6DF46EULL, 0x1DCFE415B49C8CAEULL, 0xF195D9B679763947ULL, 0x5D69DA0339DF3887ULL, 
            0x5F00435E738EC635ULL, 0xE3B002750AEA18FFULL, 0x0BB35476FE2FC549ULL, 0x70C2C93047395200ULL, 
            0xB0D84AAD292789BFULL, 0x32E7C674B4809A9DULL, 0x069B02971B1A7B52ULL, 0x0579BDB26FADFE31ULL, 
            0x5D11472FBACCDC79ULL, 0xE08F44E359E3C766ULL, 0xBB2F8F0E2D8400E8ULL, 0x5138740D4B56585AULL, 
            0xBB85F3D2FB60AC4FULL, 0xBFFEEE3772A60AC6ULL, 0x1BB3E5934D0B82DBULL, 0x768E3674A8063549ULL, 
            0x19AAACECBED3740CULL, 0x3DCF4125455F890EULL, 0x3A18660C5B539D48ULL, 0xAA37AA255A31DD5BULL, 
            0x3619AFE0FB06B0ECULL, 0x75FBE555773FB32EULL, 0x2AE4227B1D28F52CULL, 0x92BFF62911CCD98BULL, 
            0xE085ECCF78ECF65DULL, 0x0CFCE69145C73467ULL, 0x65CAD6FA70C35B41ULL, 0x097A984B99694CEEULL
        },
        {
            0x5EBFF643CF255057ULL, 0x3D0AC4CEF0B0F328ULL, 0xF7D755B720CD6B30ULL, 0x8DE8F6F404EB7884ULL, 
            0xD1F6AE9BD794EB3EULL, 0x30E67B27934AF5A1ULL, 0x9475A6406FAFD306ULL, 0xCF5C214F717E5889ULL, 
            0x87452B1B6643862CULL, 0x677DF8301ACAF852ULL, 0x391D94AC1CE48F81ULL, 0x3C2C30002B393091ULL, 
            0x55BFEEB48E99EA69ULL, 0x406231C417308D3BULL, 0x28C31CCB155998B2ULL, 0x4BD1696F69359F15ULL, 
            0xDC43428A4084BD62ULL, 0xB8D23DE3A55CFC47ULL, 0xB7E15C0C27C4EF20ULL, 0xBDD37A7A88BA4D61ULL, 
            0x1DDD645888EC291CULL, 0x509EFF887EB2AE92ULL, 0x0F7B06BF226F84E2ULL, 0xA3307134B4974EFBULL, 
            0x7F41EC26C6F93046ULL, 0x94D56A040137EE64ULL, 0x7E6F1C76276DBA9EULL, 0xA4A1BC4A05A8B72AULL, 
            0x5CEC232C9FC7ACE6ULL, 0x6BB9240CCF7967C5ULL, 0xE55BF0F5CE3E3898ULL, 0x20F7CEE8D7B3A435ULL
        },
        {
            0xC6F19DC355877E33ULL, 0x055C4035CA277C2AULL, 0xDD8C1677AE5386E9ULL, 0xCA294AE626779841ULL, 
            0xB3B9DD35F953AFBAULL, 0x4117AE811E3E8260ULL, 0xFD0156655D1A8164ULL, 0xD312FC4CED41BF12ULL, 
            0x2EBDD08646A4F7C5ULL, 0xCE43EDF9C60E7036ULL, 0x23ADEDCAAA99EAA4ULL, 0x64BDB355BD0591F5ULL, 
            0xF7D31404695A40FFULL, 0x82A779BD3F525E7CULL, 0x6C8AFA6DE6B08BE2ULL, 0x34C697DAAC17454CULL, 
            0xC7D6FA52EDE7FF07ULL, 0x85A80287CBD8B23FULL, 0x4C78CF2811263B98ULL, 0x353210220E05314AULL, 
            0x1F674C742AB2E580ULL, 0x417CD48463E61570ULL, 0x20210F85258CBC91ULL, 0x2D73842962041ABEULL, 
            0x00E4EA432FDD2FB5ULL, 0x65ED76249B95F8B4ULL, 0xA45040852D744842ULL, 0x1C00DE690B08A9E4ULL, 
            0x8CC5C8762349F8A7ULL, 0x758294DEFF40D894ULL, 0xE04036436CF331D0ULL, 0x7778EA44B94F7017ULL
        },
        {
            0x739CA34A26EC0E11ULL, 0xF08D661BB8B25158ULL, 0x3400A4B5CC28AE09ULL, 0x14C507911B265890ULL, 
            0xAAC07124697C38CCULL, 0xE02628E3093B4956ULL, 0x98F21545CE95B9D8ULL, 0x1C638AA2BA7B819CULL, 
            0x4E76AD2527E78948ULL, 0x7912C2F8BF0035C4ULL, 0x901D2A55EE4E26B2ULL, 0x032096B861BA54E9ULL, 
            0x3C461AF3F4A16465ULL, 0x88B161CC0544258FULL, 0xDF8F315EC40304ACULL, 0x1101849AF63E039CULL, 
            0xF174B0EC955C0C8EULL, 0xF82999B6D8018B8DULL, 0xAD0218AF2FC047A1ULL, 0x7C760AC6C179DDEEULL, 
            0x6183B9528804002FULL, 0x742DB6584F7BBE62ULL, 0x9A93385C0182DFA6ULL, 0x19640C1E455502B6ULL, 
            0xE67E90E1EA922EBAULL, 0xF307FFDC99740536ULL, 0x1529DA7553B988B9ULL, 0xCFF70626ADE41E08ULL, 
            0xCC30758ED78C25F5ULL, 0x31566F6FA82BAC50ULL, 0x1D134F3B27A697ECULL, 0xCD0B826BBE5937FBULL
        }
    },
    {
        {
            0x69B7CCAA61FCC14EULL, 0x1F2FC3E16199E6ABULL, 0x87E3871802EA3622ULL, 0xC2352BF81782EF89ULL, 
            0xC826F7D7FCC471C0ULL, 0x23B437EBDBE94E76ULL, 0x72EB9AF82E4221A2ULL, 0x8B0F30D9C55DE1B7ULL, 
            0x741452E7D4757ACEULL, 0xDDAE5AD879563002ULL, 0xA6DC45ECB2843156ULL, 0xCBE0169CA6D09150ULL, 
            0xF7B6547292F2DF1DULL, 0x8A00933BA70E2A42ULL, 0xAFB72746771A226BULL, 0x05EA6B6ED220F562ULL, 
            0x185AF45E054C76CBULL, 0xB6EB023A2011E2C2ULL, 0x20BDC3A1A0503D06ULL, 0xEFBF4986A4EC0DC7ULL, 
            0xE88912D33793184DULL, 0x7838777749FADFCEULL, 0xB2D32E88A9606399ULL, 0x33D3112F65F7AD92ULL, 
            0x02342FFE286C1697ULL, 0x9CC0394296C5865FULL, 0x63897BA6E01C4FCFULL, 0x29473946E3FB49BAULL, 
            0x1E4A3B84726CBD63ULL, 0x7ABA8E9B8EF2F80EULL, 0xBA778B1AA4DF9513ULL, 0x86C0E2884C6E3BA9ULL
        },
        {
            0xFAE5C86EC3051CC8ULL, 0x39AE5139191C1917ULL, 0x7E414D1931A7E778ULL, 0x8F550FD270E56734ULL, 
            0xC978DCE2FD83D9A1ULL, 0xB46CFB17F5B4E13AULL, 0x839B923C94D92EAAULL, 0x01ED7BB48E5B8FB0ULL, 
            0x01BF25C70A254F10ULL, 0x5EC4553A6EEDEAD8ULL, 0x8453E944B607CEDEULL, 0x7C021368F7853991ULL, 
            0xF3A98676238194F1ULL, 0xCFAACCFFD49BF193ULL, 0x8D4A131F61354782ULL, 0x562A9DABC8A8D25EULL, 
            0x6F35FEBF3CBDE127ULL, 0x22127C78132DC186ULL, 0xBBA89DBB178AB65BULL, 0x16B837AA38C743ABULL, 
            0xFE3AE16C8A65CA2BULL, 0xF9A7B63F9DAB4B33ULL, 0xC08A038B735F6E3FULL, 0x02A7D48AA6ADC86FULL, 
            0x030519F547CA0F76ULL, 0x1F52FF1979F8B1DAULL, 0x385B8EC65AA713F7ULL, 0x1EDB06A3EA6DF1D6ULL, 
            0x7FF336379B5B21E6ULL, 0xEC95965092FCE0F5ULL, 0x65392325284D1AEBULL, 0xCE555FDEC0DF4C8EULL
        },
        {
            0xD61520712950E833ULL, 0x3321434A8D787C56ULL, 0x324AB05BDCCF7244ULL, 0x4A54F57AB025DAC9ULL, 
            0x52AF62686B149F5FULL, 0x7045FAFE03ED0D58ULL, 0xF064C31478FA5EFCULL, 0xA0C126EDCFE2835FULL, 
            0x7DA560AECAF153BDULL, 0xA52DDD6BD41F18CCULL, 0xBD3A08B71D1F2F6DULL, 0x9B51BD3420714454ULL, 
            0x05C30D94B3E007B2ULL, 0xCDD7B673CE0E0285ULL, 0x8BC41AE5C8027579ULL, 0x24AEFA487861BAA7ULL, 
            0x92471800362E7D71ULL, 0xFBB27BE44F341BB2ULL, 0x3B79C10799ECF065ULL, 0x9E66A4EAB9EC3CBDULL, 
            0xBA1128CD0B59BA48ULL, 0x97B6DFDAE88B4A69ULL, 0xFAA9C542FA87CA7FULL, 0x7D48C07219BB5F99ULL, 
            0x82F44AB80C5EDACAULL, 0x85F2AAFA171D152CULL, 0x73D2205CF42A0265ULL, 0xF093B52B415EFB9DULL, 
            0xBB8F2215F2D51612ULL, 0x1644953A83516825ULL, 0xE35773526597D79CULL, 0x1AAE7E5C6139B1C1ULL
        },
        {
            0xC4CB0CC3CFC09C03ULL, 0xAA856EF90B5BEEFBULL, 0x1120B4C2CE70B029ULL, 0x412B9DC799CE9CC4ULL, 
            0x134D1566601374CDULL, 0x9E0CAC4789D2756CULL, 0x1505A2E1FDE70FE1ULL, 0x88040037AFED2E41ULL, 
            0xF0C5E15AA67334B7ULL, 0xE87DAC5C219B2733ULL, 0x3DD22E4072132429ULL, 0xEF30D8AF79184514ULL, 
            0xF743C2DF6044529CULL, 0xCBFDB253641B4142ULL, 0xA96C26E8B0DD6510ULL, 0x5304CCD28009E08BULL, 
            0x1C21AB1D04420BA1ULL, 0xF27C7D03AA2171A1ULL, 0xFE5719958D4BD1E1ULL, 0x42645EF7245A73A8ULL, 
            0xB9D3C433D0DCA35AULL, 0xE3E52A0259C0CD7CULL, 0x43E214D8C896633DULL, 0x6DC99D1CF4C67B00ULL, 
            0x5C27AB3FBC82E118ULL, 0x63217D96194720DAULL, 0x470D0E5A18461F83ULL, 0x84A580E8F3942C11ULL, 
            0x66FB75007B0CAE3DULL, 0xD40CEFB64A2BFFE4ULL, 0x8C91FB01C79380C6ULL, 0x255BECECAAD81A51ULL
        },
        {
            0xB1BD35E42A072C2AULL, 0x393A9C87BC157F23ULL, 0x344C71EBC23B175DULL, 0x4EF947111CA6EBBFULL, 
            0x412606FE2F46698BULL, 0x2330C01D24809485ULL, 0x93B550CC5B911F63ULL, 0x84EB99DCD57EFF6DULL, 
            0xECF87FA021387232ULL, 0x3E3AFB730C3E42DEULL, 0x90E5D079F2943380ULL, 0xFD15ED6CF66D3D44ULL, 
            0x9F881F72F80208C3ULL, 0xC0C6DBB0F9CFC55CULL, 0xFE771D67F1F783A6ULL, 0xE63C4158A1D2C8DDULL, 
            0xB19FC11109F57906ULL, 0x61FFAA50FB3571A3ULL, 0x5FC4F627B64221E6ULL, 0xB2A7B235EE0F971BULL, 
            0x284F814F24E09AF7ULL, 0x5B63549DFBCE0CF9ULL, 0x83FBFDAF42B167EEULL, 0x93A1D98B39F320D7ULL, 
            0xFE4E653E1925A1ADULL, 0x1F0F8176DD2C6619ULL, 0x0E4486BDA6606F98ULL, 0xAE0C696B18A5F551ULL, 
            0xA78885678E458837ULL, 0xBEDC28BAB62ED19EULL, 0xD475E4CC933A65C3ULL, 0xD91BD66D87F1D340ULL
        },
        {
            0xED2EAB271232D3ACULL, 0x7449999D782DDBDCULL, 0x38B8EB80B34F8A4AULL, 0xC1B9A08C0AB453DFULL, 
            0x6DEF64006E157206ULL, 0xA566D6056FB47158ULL, 0x7839B2FF40387416ULL, 0x3B578CC27E8E995DULL, 
            0x2A9139292B0C7358ULL, 0x56A9219E7265FE52ULL, 0xB5E765F35A92134AULL, 0xC52FE6ACCFAA4610ULL, 
            0xC018DC5A9C02E788ULL, 0x839466FF5FD2FF86ULL, 0x8E2ABAE495AACD14ULL, 0x6CC94634C094C9D9ULL, 
            0x1B8936D0059C4212ULL, 0x80208F395B662873ULL, 0x9B379EDF8F6D054FULL, 0x59B0D1C6729EFD99ULL, 
            0x2B285658FEF1BAAFULL, 0x5008248D42FB9D73ULL, 0x8FEF89EC1F46E96BULL, 0x930F339F0054BBBAULL, 
            0xDA81380DEB0EE505ULL, 0x556325359F4EB2F3ULL, 0xF917FE4B89A27F4DULL, 0x9CE4F43A063CA90AULL, 
            0xC264BA5D54619E1AULL, 0xB171621E650962F0ULL, 0x241EEE09B6BA38CAULL, 0xFA4DA9C6CE5BD46FULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseAConstants = {
    0x0C79F46D9681E281ULL,
    0x8935138FE7995154ULL,
    0x938D1E3F996D8707ULL,
    0x0C79F46D9681E281ULL,
    0x8935138FE7995154ULL,
    0x938D1E3F996D8707ULL,
    0xE28BA8CD22AF0B6AULL,
    0xD681E29666A3FD6CULL,
    0x10,
    0x02,
    0xCE,
    0x86,
    0x77,
    0x54,
    0x0C,
    0x80
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseBSalts = {
    {
        {
            0xE76275CF93A5E4A8ULL, 0xEFE853A43B10E6F0ULL, 0x9DC4FA7787101571ULL, 0x1DC0F0E384AF1205ULL, 
            0xE042C0E41656E302ULL, 0xEB7B2984E29D7306ULL, 0xC53AE33495F2C3BDULL, 0x07F0D49D9AC40A64ULL, 
            0x83ADF90D700A0198ULL, 0xC8E9831287CFCED5ULL, 0x8D592573D4C6988EULL, 0xD9C712FBFBE203E5ULL, 
            0x19D72E22F0A021E5ULL, 0x1C4B7F50D70E727AULL, 0xDF2434D3328EE4C2ULL, 0x991FCDAB3F2EBBBFULL, 
            0x2AC20EA64DA3D4AAULL, 0x7F81876FFC9954F5ULL, 0xFB7738CCEDBFDA4BULL, 0x220FE1485BF51E3FULL, 
            0xFE3BB234536CC547ULL, 0x5168EFCA48C790AEULL, 0x5013F734C1928D9CULL, 0x96020E1FC142F7C6ULL, 
            0x982352686F88041BULL, 0x66DBD98E90283C60ULL, 0x49C8A29F87E632B3ULL, 0xDC78D8C53186476EULL, 
            0x7085C011B46C6217ULL, 0xC8BDA5D4C777C808ULL, 0x71904A1903B667F9ULL, 0x8044B5A8239B1EF0ULL
        },
        {
            0xE10ACA03B13D963BULL, 0x3D11769ABE047CF8ULL, 0xAB6F21F732F16663ULL, 0xE4E38BA9ABA21CABULL, 
            0x22A9C6E35977925EULL, 0x74A8800B1520D9C9ULL, 0x14C20BB347BACE78ULL, 0x1E02D47C6B9DBD7DULL, 
            0x542829F50FC10709ULL, 0x5E6C7C4EA7D76244ULL, 0xA02D0383C6C6D0ECULL, 0xB902F5935EE53150ULL, 
            0x1C9930EFD5AB0D37ULL, 0xD7E74359AD679F6CULL, 0xD9F66138A363039CULL, 0xAA971F1B49A00E96ULL, 
            0x1A644E92C2B0D5A9ULL, 0xC8D1C48A73880779ULL, 0x713894A1DA47CB5BULL, 0x3D02027B12FFE4D5ULL, 
            0x67B0B200FA528D91ULL, 0xB3EA8BA60C1B2050ULL, 0xFAE96FAA93E6E43EULL, 0x02C1FA378B29448AULL, 
            0x52361D6C0379440BULL, 0xB67E895F48131CC3ULL, 0x3C67B536004C23F8ULL, 0xADF4185BE121FB12ULL, 
            0x9E372077EC116AF9ULL, 0xF97F3893BD0186ECULL, 0x3D0B4B69AE8CBA41ULL, 0x1EDB4C493EB2AECFULL
        },
        {
            0x4818AB337B482E9BULL, 0x741C62536645BE68ULL, 0x2CF833D0E75A83BCULL, 0xCD8DA48583D5AE30ULL, 
            0xDAF0A5DB8DD1AADCULL, 0xABE17328E8CC0526ULL, 0x3F3C6B8299DEF096ULL, 0xFDA7C24BE59086F3ULL, 
            0xEFA25FDE5E6035DBULL, 0xD544B4CF43AC8AA1ULL, 0x4D92D37FCE4DCB29ULL, 0x9F1D803B22D339B7ULL, 
            0xA9D8F1CAE720CF4BULL, 0x8177A130D9BEE004ULL, 0x9DCBA8CDD5D9BE46ULL, 0x9C1D7D514FF6456AULL, 
            0x7327C9817B742A14ULL, 0xFC8663376E1F10E2ULL, 0xAFA8ADDA2A076AD9ULL, 0x1BD26E8177BEDBF2ULL, 
            0x43B0B390857FC234ULL, 0x14772F927C3739F2ULL, 0x063B9201AD944C58ULL, 0x91DA0860D57D1EA0ULL, 
            0x70BA4D5B618B4AC8ULL, 0xCF68A12982AEBC95ULL, 0xA37BD6EAE600F7A9ULL, 0xD86AE55519688DE0ULL, 
            0x96BFF82ADB21C1E9ULL, 0x5FC77EC331458CCFULL, 0xB98716AE2BC05CE8ULL, 0xD55D5C27324BF091ULL
        },
        {
            0x07D66B2AD7C3D984ULL, 0x3BFF9F63D19C16E6ULL, 0x5AFCDE383E92A68AULL, 0xFD609C24926AB813ULL, 
            0x33A49274BD6F0B8AULL, 0xF6C6F6505B5A9C8AULL, 0x92C2039802CFB7BEULL, 0xCA9DFBA7EC8774DDULL, 
            0x0D470F5AAB99F166ULL, 0x9F1F1A6418469A1BULL, 0x044A994E2F3931F8ULL, 0xD0E5B70C1C64E44CULL, 
            0x5BF400AEB4A1A78EULL, 0x4B4ADB19DA0A8B98ULL, 0x2BE55D9FBF277BA7ULL, 0xF7FD004FF0CF927DULL, 
            0x0DAB23B7B9AAD38DULL, 0x7E9A9A2B7B53BB09ULL, 0x14AD0A0DE53EFE5BULL, 0x04D3EB5B685BC963ULL, 
            0xD9F7BE1D58BB5482ULL, 0xD3D924570739CE69ULL, 0x3B17310F7FB3D9AFULL, 0x313C8284A76087C2ULL, 
            0x1B5D9580F8524345ULL, 0x939AF71367ADD633ULL, 0x3799FEDE4E424AD4ULL, 0x371E7DAFCBE76EFBULL, 
            0xDECE2B9B8D16A477ULL, 0xB52D1D156ECE3120ULL, 0x8B9E07DC7CAE83B9ULL, 0xD91A89C4BBEF9DE4ULL
        },
        {
            0x4C99DACDF1999342ULL, 0xF7DE264E3B194A99ULL, 0x63E3A179838D2285ULL, 0xFEDEA23F7378661CULL, 
            0x6A81219493077E47ULL, 0x39E02ABABC48B45FULL, 0xE92FE311B4F53E31ULL, 0x336BA76ACA0F915CULL, 
            0x2D4088AD5063B27FULL, 0xB96C58FC542CDA4BULL, 0x0276D7978FD8CBCAULL, 0xBBDB20B0C0612E0FULL, 
            0x2E3C01021403EEF3ULL, 0x37586E8D9CD2E403ULL, 0x46D638FDAA3065D4ULL, 0x05041FBD1A259DDEULL, 
            0xF413D3C74AB8325AULL, 0x43741B7113F04BDDULL, 0x92DC2E053CD05507ULL, 0xC3020022B3E7DF9AULL, 
            0xCD892964ACBC5395ULL, 0x601247A0C3B05D3FULL, 0x9738BF81AB2CF80FULL, 0xCC0B48A3A0C97512ULL, 
            0x8B1B20C7743C504CULL, 0x633278EF0A78E33EULL, 0x67CB7A401D819CB1ULL, 0x2DC0F7795FF3854BULL, 
            0x9D0D504F07EB9F7BULL, 0x02EDE769BE488E41ULL, 0xF7DF24246CDC5BAAULL, 0xB4B4B33AD2B63FCEULL
        },
        {
            0x2B7A66D360E74495ULL, 0x0F0B3525882EC98FULL, 0xCE45E037EF12C9B8ULL, 0xD9768B7527C13573ULL, 
            0x56433B21EFBDAE65ULL, 0x6D6732A34FFFBE91ULL, 0x64E80E17CF2C24A2ULL, 0x1BC19878DCA0B75BULL, 
            0x86286994FA52D1E2ULL, 0x8C3068EADB4836A3ULL, 0x8ED8B6500231B393ULL, 0x1C43DE528A9B27A3ULL, 
            0x171D1F3A87A00658ULL, 0x86DFF3249C28ECA5ULL, 0x3223FCDFFF42EA6AULL, 0x5635B9B45A90825DULL, 
            0xB30F0831436CA25AULL, 0x7070C40D4312D7D8ULL, 0xB8772846EC57C98EULL, 0x87124C18C213C001ULL, 
            0xE0B516BA4C763068ULL, 0xFA2272068C9C4B4AULL, 0x811826658C320C09ULL, 0xA52A0E220E131D3DULL, 
            0xEE2B18D4C78BC54FULL, 0xF8B4EA59F4677B1EULL, 0x78A268B2294855FCULL, 0x7BD9FAB07FA85020ULL, 
            0x40459FF206F26D10ULL, 0x78DCA82298712DFCULL, 0x321C0CA6D2F65B54ULL, 0x1B34BC3D1A8E113CULL
        }
    },
    {
        {
            0xEF16656873D1524CULL, 0xD7A68A7044D771A8ULL, 0x4CFCD9D836A831F2ULL, 0xD2146984AB9AB249ULL, 
            0xD86E738F93D3906DULL, 0xE7E8DC341995FDE3ULL, 0xDE3C15BA0B01E9E9ULL, 0xD6775AAA6051417BULL, 
            0x3D71C559C38A53FEULL, 0x72E55AD099CF4247ULL, 0xB0203170CCBE3FB2ULL, 0xBB2D98E256F8C6D3ULL, 
            0xD844412AA6D92AFEULL, 0x4F0986E9461DD523ULL, 0x8BC191FF9E7BDDA5ULL, 0xC131945D755FA750ULL, 
            0xF42E4C98591B1E0CULL, 0x3E9B042D706FC195ULL, 0xE392149AFC241199ULL, 0x9F9D20CBD32441AEULL, 
            0xC6A32CA3F6D6DAA0ULL, 0x2E8479EA056CED0CULL, 0x92A802ABC5AA919BULL, 0xFDC764706A02DDB1ULL, 
            0x7258E7EA7F743E0FULL, 0xD742CFE26125D692ULL, 0x51E325411C70489DULL, 0xD31E46A35379A98CULL, 
            0x79D0D985539576BAULL, 0x80EFC613E983180CULL, 0x99FF29DAA0BBD94DULL, 0x0286674457A4667DULL
        },
        {
            0xD44444F604C702BAULL, 0x41FCDF62A5E281AFULL, 0x4E1713C961E8456DULL, 0x1E663D5010A679BAULL, 
            0x02179A25680E32A4ULL, 0xDEA263827720EBABULL, 0x1630D580F1F3E3A7ULL, 0xA9CAAB6F34D32DFEULL, 
            0x53C6EF56AF459524ULL, 0x67EF2B87CD841485ULL, 0x724598A33DFEF634ULL, 0x8C957D62E77CBB2FULL, 
            0x2EE3F7F173A74440ULL, 0xBC94B9AB4578F8E3ULL, 0x2A3DBA9ADEE188F7ULL, 0x4CF9DD35E4F0C79FULL, 
            0x5132072CBE9C88D8ULL, 0x72FC0BE628899F3AULL, 0xF183FB201D6E50ADULL, 0x3A8CA9DF24E064B3ULL, 
            0x4398704C9426DC89ULL, 0x62F19C72548FE032ULL, 0xA64AA9CACD2AA72AULL, 0x2A5070BC49A4B61DULL, 
            0x60A26ABDE16E15B3ULL, 0x098CA865DB2F7F2CULL, 0x4394A3952E099A21ULL, 0x73D801D30EFA1C86ULL, 
            0x85808AFB7D3CA75CULL, 0x4FA95B37DA6362ACULL, 0xC3351E353CB5420EULL, 0x9A097CD05DD1D778ULL
        },
        {
            0xB227818438CEDAF4ULL, 0x0F90D834A66E05B1ULL, 0x6D50274DEA2CB6BCULL, 0xD916F7AE020B87A0ULL, 
            0xA0ADFB1298FC7D89ULL, 0xA7423D35C1305646ULL, 0x1784F06B0A1D4708ULL, 0x93F3FF3D7CB12904ULL, 
            0xC81C83A66B5B123EULL, 0xBC4B3A5E5997D8FDULL, 0x3C440000DA5467FEULL, 0x51BD7497D17AAC67ULL, 
            0x104C9DB758D1BEA4ULL, 0x777FCE1269960CCCULL, 0x19493F2322B45305ULL, 0x5F253E83B4764363ULL, 
            0x3617B1728E370654ULL, 0xD90A3F5125C4CE33ULL, 0x5AD83127B046A1F1ULL, 0xD5DBDF935BD07EEEULL, 
            0xF24290DB36B08900ULL, 0x3118B7F75C56DB25ULL, 0x007A87ECC2E3316CULL, 0xE11D8B95E8980C25ULL, 
            0x5AB0BCF9D6729376ULL, 0x3E7F3F8DAF9A872EULL, 0xD22892A835D06885ULL, 0x2EDAA4E5454F1C2FULL, 
            0xC5A761750E7AB029ULL, 0x78008BFDFE9EF3E9ULL, 0x2B737434411D5230ULL, 0xA2441CD90FE4EDF5ULL
        },
        {
            0xEFD2964D02117847ULL, 0xE965625AE95D6FA8ULL, 0x963796C493A012F7ULL, 0xF44053AA2A09D109ULL, 
            0x56D20C7FD8FEEB2AULL, 0x1396212ED916CCB8ULL, 0xA92812CCB9C7A652ULL, 0x9BC253D1B0722514ULL, 
            0xBDA34F0ED626A1A0ULL, 0x76578EF2E57B0E5FULL, 0x579A7E851C3C0863ULL, 0x2FFB3118EC84C7D0ULL, 
            0x6BB818945ED6A104ULL, 0x7C05AE184E076CA8ULL, 0x89AE94424442517CULL, 0x92385DDDC7D7DAF0ULL, 
            0x4E2EC7A2CE676D6AULL, 0x0D1DB8B2198F8651ULL, 0xC92A6D7240741FFAULL, 0x43C95062590514A8ULL, 
            0xF055469EAE1DF6FFULL, 0x2A0730047F8A0F95ULL, 0xBD1C7A991F264C50ULL, 0x823716447A06C018ULL, 
            0xB69B4ADD8F6BEBF0ULL, 0x7E6559055ED93AEFULL, 0xFE6B1AE302DD7EAEULL, 0x965192F017314A58ULL, 
            0x6E85B8B1190EAEAAULL, 0x5F57D1FFA2963BEDULL, 0x5C9B9B7644364C96ULL, 0xC436A97C507618AEULL
        },
        {
            0x6EB5131048E0D361ULL, 0x7A461D448BDEA565ULL, 0xD69A1CD8DE9EFF9FULL, 0x2FEDF56E6C81917FULL, 
            0x92CDD4FBD8D1E9B4ULL, 0x77602C0F94E620FEULL, 0xA53D1972CDE2FCCFULL, 0x6B72C778002432B3ULL, 
            0xC65F5472B6F45B43ULL, 0xFFEA006196C44CA4ULL, 0x523A6FC66C48D7A9ULL, 0x555647617C00351AULL, 
            0x718ABCA6B850DF12ULL, 0xE3C385D3767DE01AULL, 0xA2F0E63B779D41FEULL, 0x1122379FDAC5F246ULL, 
            0xB6C7F16E661AF042ULL, 0x9CAB994D2299FC9DULL, 0xC1A1EB1B5F09DA39ULL, 0x25430EEF325CE29DULL, 
            0xA5F296A8980EB31BULL, 0x786B2AEF71AB3364ULL, 0x20C230819C400FEAULL, 0xEA77A8D34B19C930ULL, 
            0xAD2EAE05A3C37188ULL, 0xA5F8A2C8F5028C7DULL, 0x8E06BB9354A6EEE5ULL, 0x1A79D20776A4C5F9ULL, 
            0xF8AD77AFA5753145ULL, 0xC79110520C60D035ULL, 0x571B97205D9BA348ULL, 0x578618C7CCFAA6AEULL
        },
        {
            0x4DEFD85861325492ULL, 0xF25F75B87EB5FDDBULL, 0x204E4F6532AF3BFFULL, 0x12F8397EA2729C06ULL, 
            0x7E2D1499105475CCULL, 0xB6D4C6D29E334BA6ULL, 0xBAFAE12153097568ULL, 0x8C062A4B9EC6415CULL, 
            0x048EDD6FABD5D01AULL, 0xC2E21095D7B8D121ULL, 0x18AB80196554EE09ULL, 0xFD23C5424D93ECADULL, 
            0x8E54B738518AFF84ULL, 0x47665FB7146C402EULL, 0x42B7CA3653C5BE39ULL, 0xF77FDB5C7D62FE74ULL, 
            0x4769AD2B22F46681ULL, 0xFDBB93F724B1F1DFULL, 0xC78B68B4211CDCCDULL, 0xFCDF2764B72752E5ULL, 
            0x4BECED94A4B1CA92ULL, 0x3199C5DD577CD15FULL, 0x6EF3F6E2A5CFEE18ULL, 0xD05C0308C37D6095ULL, 
            0xCC7AD4F7FD68BE3EULL, 0x0E8B241979392ED2ULL, 0x43E525D8186FD4D4ULL, 0x69441522E7B4AEE1ULL, 
            0xBEB0676DEAD3D8BFULL, 0xB34BEC33D90A09BBULL, 0x83690FDB8092FBF4ULL, 0x2E788AA4972CCD00ULL
        }
    },
    {
        {
            0xECB2817A8532E7E4ULL, 0x58D28B49A2A7F133ULL, 0xA40EF435E43F7CD4ULL, 0xBF42B70387BF044FULL, 
            0xBE04937AE3805862ULL, 0xF35F87FFE610A509ULL, 0x7541A8206B619C9FULL, 0xE9E0C5C7B49FB7DEULL, 
            0x8071C8B619293ECCULL, 0x5A266DE7D80776AEULL, 0xA37B38CF0BA47E4DULL, 0x820402B06A7481F3ULL, 
            0xCCE43B2136C6F20BULL, 0x94094C066D4BA11CULL, 0x50713F4BCA46A263ULL, 0xA3CBD348A6C83688ULL, 
            0xA3D7089CEFAB1BE0ULL, 0x205457C790D88436ULL, 0x0AB1718AD0854056ULL, 0x3A5CD22EC33C9FB9ULL, 
            0x466055122877E40BULL, 0x582862BC9F68D4CFULL, 0xDDD6D5D6C25FAB63ULL, 0xDA59D7789D3F048BULL, 
            0x30B55E28CC9366F8ULL, 0xD793B1E5655613C9ULL, 0x85E878D057572973ULL, 0x787D36FB6E36620BULL, 
            0x43EEC73C797ACCD7ULL, 0xFDC799E09FE118D2ULL, 0x1131FF9676159359ULL, 0x12791418EAC3FD5BULL
        },
        {
            0x4065BA04363C4A0BULL, 0xD914E2783950F819ULL, 0x2D9260825739054BULL, 0xA91320B2D9421A55ULL, 
            0xB0965DD17641C6B0ULL, 0x2EB4D818F04947A5ULL, 0x2C9B634164552F29ULL, 0x0D8C57775BBD4694ULL, 
            0x9008FC798C75F10DULL, 0x3EDD537860DF1A58ULL, 0x294C61DBA97C9F3CULL, 0xC2012454923E23C5ULL, 
            0x282F18A3CF325E07ULL, 0x6106FA94780AC5DDULL, 0x9F2152467317E2E2ULL, 0x7ED59AC232245750ULL, 
            0x94077D05E198DD3BULL, 0xA0318C85E38A49EDULL, 0xEE489466290FB4B3ULL, 0x36F0B1EB524B85FAULL, 
            0x993FEB96CD287A1CULL, 0xF334848957989F4AULL, 0x0964E40610DB7598ULL, 0x8174DCF7D830DB62ULL, 
            0x378D358D0CC92D21ULL, 0x812E21B4BFDD2FB6ULL, 0xAEB4B1E6F2351CD1ULL, 0xF55194919C282B8DULL, 
            0x61374DDA5BA7E510ULL, 0x6545C7A8510519B0ULL, 0x916406BE60BF0813ULL, 0x2BBF52287C38D9DCULL
        },
        {
            0x7043CBA7E709A53FULL, 0x142D90B00C55EF67ULL, 0x8AA0DB60CE451C13ULL, 0x260BAF1233310C43ULL, 
            0x0717EC1B37DDF705ULL, 0x90D6EEE3AB2A2CD9ULL, 0x87928A502F83ECD1ULL, 0xFAF6EFD23F798017ULL, 
            0xE9F010974B8CF2D3ULL, 0x39F8B63B1359BA6EULL, 0x10B170AD0E8FD243ULL, 0xA7E523D9AE7264AAULL, 
            0x43821DC8AD20DC82ULL, 0x3B1C08C9E3195BC7ULL, 0xFAEE8CA7F4ED4FCDULL, 0x71E7FE956E89A99AULL, 
            0x86ED6AB98FB49E97ULL, 0xFD42AAC8F7F7E7EEULL, 0x542C2431AA0A1CE0ULL, 0xCA405FFC35416D7AULL, 
            0xE2AA81D34309BA53ULL, 0x444DBEC356C17816ULL, 0x65BAC999917C129AULL, 0x00323B0ACBFC5FF6ULL, 
            0x80FC698CD015D638ULL, 0x23B66D1E45E15561ULL, 0x5CFE3751FBF87B90ULL, 0x03756C6CC9FD0A5DULL, 
            0x3FFBB9C2FCAE9670ULL, 0xAFE485D17F87992FULL, 0x5CBB8FAEE87EAB11ULL, 0x290B2502DF8CD26EULL
        },
        {
            0xAD015680136867F9ULL, 0xCC63A5A0BBE7B4CFULL, 0xCE71B1B1A9657961ULL, 0x0326D1431FED3C8AULL, 
            0x3AABCF16F1D623E9ULL, 0x853CF85F71AD2776ULL, 0x37A69CFD9B72FD89ULL, 0xA0775B0005FE6DA8ULL, 
            0x5341684CE1464095ULL, 0x69767A8668AC056EULL, 0x4748C81D022072EAULL, 0x8B57E30FF862BB49ULL, 
            0x28F622CCF67DB278ULL, 0x01C65D860DA4B414ULL, 0xFB7738C1AAFDADC7ULL, 0x51E0F7672362ECCAULL, 
            0xAF270B853411E800ULL, 0x9CC1C46AAD9B71CDULL, 0x61AC426D46B7F775ULL, 0x981427FBA1510A28ULL, 
            0xD8329F4583656733ULL, 0x04BB001C476ADC3CULL, 0xDDDCBE104052B6F8ULL, 0x9A18C23BF86B2728ULL, 
            0x8FAC3AC70CA331C0ULL, 0x2A7CD64524ACE183ULL, 0xAF0A005ED569C6A2ULL, 0xDB885569315C2C7EULL, 
            0xC905F7E5785951AEULL, 0x1ECE85E319FEC3F7ULL, 0x3B91060CDD9D6BCFULL, 0xEEFBA1AF429A676DULL
        },
        {
            0x999C6089049429D7ULL, 0x916FFFA393D20DB0ULL, 0x58CD2519D5A42038ULL, 0xB94B8902E36F0652ULL, 
            0xEEFD9B33C2BF9157ULL, 0x8B0195117F8B0858ULL, 0x0001CBC963624854ULL, 0xDCF6B37488CC8A20ULL, 
            0xB187B43991FFF54EULL, 0x3C611CE3A25838A2ULL, 0xAA1B7C764C222AFBULL, 0xF0F07AC831307DC6ULL, 
            0x07234369B0FC371DULL, 0x52E30E268A1EE2D7ULL, 0x5270EB3AD31CFE68ULL, 0x95630992FCA71766ULL, 
            0x3EB90DDA5195AD9AULL, 0xB51368AC7D9BD5D1ULL, 0x9119D839558137BEULL, 0xBC9893D9EAC150A1ULL, 
            0xDC4783DE4BD66D35ULL, 0xC71DDD7C32CCB34EULL, 0x7CA02B3146B650E5ULL, 0x433B95FC2F117D21ULL, 
            0x3973A25D7388DF11ULL, 0x588FA59DE8B8F15EULL, 0xD08C17551F3CB92CULL, 0x1C4915B8E80BB714ULL, 
            0xB936201E7AC12A97ULL, 0xFF4B528FEC816C36ULL, 0x5821DAB447BF871BULL, 0x1FCBF4BFF7785A9DULL
        },
        {
            0xB9EC6ED4E31A1173ULL, 0x4D83AF7E4824DC67ULL, 0x907BBD3E77E598CBULL, 0xABF5B0D19D4B7441ULL, 
            0x360E9937C6B02934ULL, 0xD40135217EB55549ULL, 0x90539A370BF3DFA2ULL, 0xCBAB4FFBC485D096ULL, 
            0xABD43653EAFB15C9ULL, 0x474BC72999632F4DULL, 0xFAB46FE8B8C96347ULL, 0xDB1FAF1AF0E3C77EULL, 
            0x2AB81EB0E26A9E50ULL, 0x26DB5487514BE865ULL, 0x308F8770720545A4ULL, 0x2E407C5D444649D6ULL, 
            0xB789E22B15146DB9ULL, 0xB32CBA4E26A61B14ULL, 0x006C8A513D5D696FULL, 0xF92E0D3CC474CEC5ULL, 
            0x6A149F73A47CFD53ULL, 0x06A7DFA1D0DB9715ULL, 0xAF2C38E8017EA7D3ULL, 0xDB165AC95BE478FBULL, 
            0x136CA525B8084069ULL, 0x2274510EB189404DULL, 0xC39E1064213AF955ULL, 0x0D513B16E8440A68ULL, 
            0xB84EC625D516A662ULL, 0x6B6B99844D085F01ULL, 0xA6C31CE5602D52FFULL, 0x359BD8A20C2C35A8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseBConstants = {
    0x7CD0A8F88E1BCA63ULL,
    0xE202FBB674B7B5ADULL,
    0x062CF33DE98BF3D5ULL,
    0x7CD0A8F88E1BCA63ULL,
    0xE202FBB674B7B5ADULL,
    0x062CF33DE98BF3D5ULL,
    0x5C3EF717408F6256ULL,
    0x21C16AA3BFFED918ULL,
    0x13,
    0xCC,
    0x8D,
    0x1B,
    0xD6,
    0x74,
    0xD9,
    0x78
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseCSalts = {
    {
        {
            0x178AA1504C9C04A7ULL, 0xF372E88AFAFF8A97ULL, 0x181DBF969EBCBBB2ULL, 0xEF0CA0FDA9D79660ULL, 
            0x9A460B3F7E55F6ADULL, 0x2771837205E67ECDULL, 0xF0086311F636DABCULL, 0x8FEE0336047CDB63ULL, 
            0x3B725138316F35CCULL, 0xF8F4BB788FDA7268ULL, 0xF105F1289EDECC60ULL, 0x38B73CBDE40D14BDULL, 
            0x2684CE03E08DD6C3ULL, 0x62160CF7C04C6A53ULL, 0xAED517B79FDB1C60ULL, 0xE50762FA2605EA86ULL, 
            0x42666254D74D59BEULL, 0x805965070F7DD6AEULL, 0x2D140AF9EEC7D836ULL, 0xBFECE43402BC02FFULL, 
            0x88092359CFADE894ULL, 0x6176CC12883A5590ULL, 0xFFB8B056DA9A4435ULL, 0x98164DBA9DE3DEA8ULL, 
            0x262D7919F36F9B0BULL, 0x67CE1FDADD6B01E8ULL, 0x217A50E9AEE75647ULL, 0x16F113217B1C481DULL, 
            0x13D57D485694C97DULL, 0x1B14BFA4CA53FFC0ULL, 0xD5B80D16396C89D0ULL, 0x61CC0C1542ADF7DEULL
        },
        {
            0xF1ED1CC01724D732ULL, 0x503B9E3AF033CDFCULL, 0x1E6E4B5CAB5CF07AULL, 0x30C23F9AEF3F43F6ULL, 
            0x699B542D00A0A434ULL, 0xA9CB77A95AB41E81ULL, 0xD998C8946C41B1A5ULL, 0xF628537158F99DEEULL, 
            0x92609A84252EC10AULL, 0x8862FD10306FA2F7ULL, 0x16A62CCA95090CA2ULL, 0xD5D30E1845F5FE3AULL, 
            0x650B263A7EEB4E52ULL, 0x982E4987EB865BA2ULL, 0x695C2353C8BD449CULL, 0xA2060A320A2A9B98ULL, 
            0x90B86BE5B7AB7F5BULL, 0x21185842EFB387C2ULL, 0x87CDAA4C0D35974FULL, 0x5B5628AB1EE90C7FULL, 
            0x2D8057562586668EULL, 0xEC7B1E20D08AC303ULL, 0x2494FB7B41C51C00ULL, 0xAEECA565E1AA9B30ULL, 
            0x3B4CF20F9FEA57ADULL, 0xD57A195F3C94B2AEULL, 0xC4DC006402535D86ULL, 0x7496C3941764EDD8ULL, 
            0xB4C416D5B69D8B6AULL, 0xF11F88DD31777BECULL, 0xC2A734E688519B01ULL, 0x608EF47ED40BDB00ULL
        },
        {
            0x1C69BB91416819E5ULL, 0x35F33A4052CE75CFULL, 0x55EDDBE364B58156ULL, 0x96270FDCF70BEFB4ULL, 
            0x13F02230C2692D12ULL, 0x42560026427C38F9ULL, 0x289B245E59635710ULL, 0x613E3E8274E9972CULL, 
            0x07D4933D3AC21AC8ULL, 0x1BF04D3C0E702ED2ULL, 0xCE8F3BEABAE5F718ULL, 0xDC4E05103C484820ULL, 
            0xA52C1ED8940B66EBULL, 0x97A8B86BB5893AC7ULL, 0x173E90B791E31D57ULL, 0x5E1492C2291E1FD2ULL, 
            0xAC154B7F08BBF569ULL, 0x183C03D7D5DB2131ULL, 0x030A61336D9775EFULL, 0xA8897642A99F2751ULL, 
            0x640CCADD7D05AE56ULL, 0x1EC3DF0A29455AD5ULL, 0x6B218F6BBB9D5C49ULL, 0xA62DFAD5158B42AEULL, 
            0xB881E042CD658DA7ULL, 0xB1D598456C0AFE74ULL, 0xD60E7D7AB80E8DE6ULL, 0xF3C93F8BBCF3A8F7ULL, 
            0x66CC17990D6C97E9ULL, 0x0161639A8C666961ULL, 0xF6491A62E6D14C67ULL, 0xC587E7F7B975501CULL
        },
        {
            0x459C5A411BB3DE34ULL, 0x6E801882A8B7D63CULL, 0x9A3950D0827DFC6EULL, 0xE195489CF9C6E6F5ULL, 
            0xCD50502B5E02282AULL, 0xC04120B8E71E75F6ULL, 0x44F1313C49FF99BAULL, 0xF786FA359A3EC030ULL, 
            0x671ECB059F3709CEULL, 0x77F73DBF3D74DFB2ULL, 0xC82E5D5F508C75E0ULL, 0xC30C178075E0B157ULL, 
            0x87253A372FB520E0ULL, 0xF6AAFCC52B4D2AC2ULL, 0x18B4D03C9D27CE7BULL, 0xD1975E9A10B4E84FULL, 
            0x2A8F625CC4023877ULL, 0xA5ED003E54294796ULL, 0x305B9A5AF728BC2BULL, 0xF0A1DE8082183AD4ULL, 
            0x8F03C0DE9C78C4CDULL, 0xFBF237615A59039EULL, 0xE10D8AA81068F924ULL, 0x390F57E15735A645ULL, 
            0xF7D4C1A035D46424ULL, 0xEEBE5DA39B46BF07ULL, 0xE903CB8B4934BAABULL, 0xCDD74C935F2B449DULL, 
            0xCEBAFE26BCFB2F71ULL, 0x2E564EE88448EE1FULL, 0x0E64E2E528492EB1ULL, 0x406730B0D69F941EULL
        },
        {
            0xA49A73EB43A72130ULL, 0x013CB3D2EF936171ULL, 0x80AA02AC01CB9466ULL, 0x4DFBDEAFF0B9CD3EULL, 
            0xA246A1CE34A44C9BULL, 0x8C4C1DE02A7BE056ULL, 0x0058F2711C206E33ULL, 0xD8F7A8757F228309ULL, 
            0xF50E634F7CF73599ULL, 0xEB6CA41032AE7758ULL, 0xD9A5EE7048CD80BBULL, 0xF8C5C441777D09F3ULL, 
            0xCCB3AA69BF0AAEC6ULL, 0x56E4707697B3803FULL, 0x880082D2A0AD8662ULL, 0xEB5F5BE34E43302DULL, 
            0xBBC7688C2F8891DAULL, 0x8B75B620A652EF9CULL, 0xF0682AD0269E0BFBULL, 0x98A3CAF2CCABAAEDULL, 
            0xC88F34C355D960FAULL, 0x0FE79B9648886992ULL, 0x7B9656E24025E269ULL, 0x00DFD4C02CD607CFULL, 
            0x13BDE267F6EC15B7ULL, 0x760C211E534DFEE6ULL, 0x7A847719E54F0196ULL, 0xBE8C3CA3377F5510ULL, 
            0x351B94CBB0785D5CULL, 0xC6114381F80241FCULL, 0x55841A93D6CA05C5ULL, 0x1C0D62435BE1F198ULL
        },
        {
            0x8817774488CBBABCULL, 0x8F8CD4A746E53B7AULL, 0xB55D3247C32DB47EULL, 0x47B17CCB2F042181ULL, 
            0x862B9E74201DA7CCULL, 0x8E292C3246C01A61ULL, 0x4D1225BE99A44255ULL, 0x97E6C2D2DCC533BEULL, 
            0xA5F5F32437B045C4ULL, 0xAEB13FAEE504B5C6ULL, 0x7F98A2388E5A3E3AULL, 0x9EF9D2239A8B0EA4ULL, 
            0x8B8AADFF3F4C83A2ULL, 0x6C0286734B75E34CULL, 0xAE60160F2CC76507ULL, 0x02560C745113C2B3ULL, 
            0x649D50F3AE536750ULL, 0x96C087963192A5E4ULL, 0x9BF77C4E07DC2C33ULL, 0x5A4D6474A05F6887ULL, 
            0x05F2910BFF8FF019ULL, 0x8F5C5746BAA832C2ULL, 0xEB9218BFA61F059AULL, 0x05A69C8E5DD4CA87ULL, 
            0x40FA968A27C4681CULL, 0x3BFA390F1D266E32ULL, 0x5DECC63E949083E8ULL, 0xB71AEE6FA8F0EDB8ULL, 
            0x6D071AC4BBDCFA41ULL, 0x396623D149D87002ULL, 0x00EB452B28CABEC7ULL, 0xC6215FC8975224AFULL
        }
    },
    {
        {
            0xA8FC9D7161F0DD04ULL, 0xA916EB22927DC246ULL, 0x346938361CFDC750ULL, 0x9497ED7DE6B0F7E2ULL, 
            0xFB4E6846F0BBEFEEULL, 0x382BCE4D954190A7ULL, 0x33590BC43AAEE078ULL, 0x23EC635D6069D5B2ULL, 
            0xD5F526C52D2991C9ULL, 0xB3F654DCCE7E5ADAULL, 0x26FA0B8FCB4842BFULL, 0x62AEEF90B2D55092ULL, 
            0xB9CD6A8CC4C891C6ULL, 0x65DCA2A372F9D6C0ULL, 0xC0B0A56143867405ULL, 0x47961BE78A81721EULL, 
            0x6876193957D62853ULL, 0x306D4F6E882C1C43ULL, 0x2D30711EBF325E82ULL, 0xD5B210F2B5A9A706ULL, 
            0x138F9407F5B40455ULL, 0x35BD7B6BD6D1300DULL, 0xB5FBD1BA820870C3ULL, 0xA5E07B025D8D4CC0ULL, 
            0xA1BEF8EF9704E71DULL, 0xDC9ECABCD6173529ULL, 0xE8D2B1D8B5B3A55CULL, 0x28236E7C280C7437ULL, 
            0xFAFFF412FBF4BB74ULL, 0x8771B18A3FB117A2ULL, 0x0DE365D3475D79E3ULL, 0xB92E7728AA81B45AULL
        },
        {
            0x46A10ECEFDDC1C5DULL, 0xE611468802A1FA1CULL, 0x50F1CCF08CDD62CFULL, 0xEE4CB7BDCCCB77ACULL, 
            0xE91986BEA34C1530ULL, 0x839957B15B8F4E96ULL, 0xE824CDE8D00B4BADULL, 0x440E6FB37789B5EBULL, 
            0x50CF87DBD93B0F2CULL, 0x5AD48296FF4A070EULL, 0xE9E46F011E0C27BDULL, 0x8922E58B120E5E75ULL, 
            0x9ED5C555312A6132ULL, 0xD322108895C3BCFBULL, 0x9834B415DB98AC1FULL, 0x9EF6237B14E493F5ULL, 
            0x24D5A99384BB1D01ULL, 0x88FB1D558923AD55ULL, 0x9A529E0E184F3640ULL, 0x6A76D63A06954F7DULL, 
            0xB142FD25A0864E9AULL, 0x7FA48381556247C8ULL, 0xCA0D2D3A37858FC3ULL, 0xE9BB26361BD8DB4AULL, 
            0x567254C5D4A1D9B9ULL, 0x34B4BE1D6AA3D6D0ULL, 0x997CF56102589CB2ULL, 0x715EC4BCD4BBE51DULL, 
            0x2701F01EB503284EULL, 0x057FB9FC233CDA0AULL, 0x51C60C695A29CE90ULL, 0x71F3A7D342B94D17ULL
        },
        {
            0x7913D330DD9F8701ULL, 0xFDB5948A8289EF8AULL, 0xF25E794DAD21F4B0ULL, 0x0ECDEDEF92CD146DULL, 
            0x4A21499A0D09196CULL, 0xE0131545998F4A64ULL, 0x016718AA3E6E783CULL, 0x6739ACCFEE0B3FC1ULL, 
            0x0FF6B632F67F9229ULL, 0xBB8222D76C9EEC25ULL, 0x47DAC2E01AD2075CULL, 0x075BB6F00AAA3176ULL, 
            0x775C8616B259446DULL, 0x81309B27F9D40B08ULL, 0xDC9576E301E91402ULL, 0xA37E1A19CBD6DD33ULL, 
            0x897D9D4911AFF6D7ULL, 0xCADA2FCB416E9FCCULL, 0xC0D77CD26F65D1B2ULL, 0xFC8ACD6BEAB8157FULL, 
            0x813664C488129C7BULL, 0x67B0AFBF274C2D81ULL, 0x61654E738BD42CBBULL, 0xF47949C89B8AAD9BULL, 
            0x14BA977DCAF11C3AULL, 0xDA34CC648188DFDFULL, 0x542B42D60B0A2098ULL, 0xA5C8631B2D45E582ULL, 
            0x4F370C76E5B78847ULL, 0xEB71955D46AB1B21ULL, 0xD6D6E163FD399735ULL, 0x55B8883EFD3F3628ULL
        },
        {
            0xFB64547F51FB46C5ULL, 0x4A36992CA6E38924ULL, 0xF3B0D653A870135DULL, 0x15248D0EEE1E407FULL, 
            0xF762A6053A9FB225ULL, 0xABCD822C795903A0ULL, 0xC04D2689AD31D271ULL, 0xBDC09B3F6D530380ULL, 
            0x9A1AF0AB4429AE29ULL, 0x89CDEAAE4F486E92ULL, 0x2E20EC3845DBEFDBULL, 0x69F8FF65C26E38D7ULL, 
            0xB1DD9DC58E9A42FAULL, 0x56A13C3D7C600A68ULL, 0x5211ED8E291A334CULL, 0x70A9D9BE0882B257ULL, 
            0x73487EB3B14427F8ULL, 0x5DFB05EB4B19BA18ULL, 0xBBAF317E27E054BBULL, 0xB205F51D8819BBEDULL, 
            0xA97A4672F85C2464ULL, 0x5621A8DCB7868CDAULL, 0xF35FEFE0201B3EB2ULL, 0x8AAA511A61F11044ULL, 
            0x62B3C49EEEC72493ULL, 0xB1CD73AB73EE57CDULL, 0x212E70838CDC6B9BULL, 0x10B0D5CF5D421081ULL, 
            0xCD5CDBAF3A89347CULL, 0xB66C928FA44883B5ULL, 0x15D396B4A9794B32ULL, 0x6C995A73412087E5ULL
        },
        {
            0x330328C63EB9F857ULL, 0xB2E1500302C8D8B3ULL, 0x18E483145456EDBBULL, 0x209BF26BC3EAA5FFULL, 
            0x46C58AAAF6924E30ULL, 0x39BAEB402CD65AB8ULL, 0x9C742E040C4DD36AULL, 0xB7C07AFC4253C99FULL, 
            0xDB55862648A2276EULL, 0xE1B427D434005A60ULL, 0x821757BE3BBF1ACBULL, 0x562EC354DC6637B0ULL, 
            0x703522183B1AAECFULL, 0x452E5032C2CC3DABULL, 0x10C93279D5ACC6E0ULL, 0x1671C9DA0EB3D1F8ULL, 
            0x890B71C59838D711ULL, 0x2138C72D207885EFULL, 0xA0D71F5968AB43E9ULL, 0xF55D4AE841E8D351ULL, 
            0x2D1A8BCBA9742E8EULL, 0xF0C8D3FA60C78D1AULL, 0x8F1A1409725AA678ULL, 0x51784BAAF126369BULL, 
            0x201A3AE046C801B9ULL, 0x8394458B5374F949ULL, 0x47CB627E59577F51ULL, 0xFD0ADD6942D7BA35ULL, 
            0x5D42ACE437F3DBB1ULL, 0xBD7466163693FBCEULL, 0xF05BC95FB410F341ULL, 0xA2DBBBD8A6D444B1ULL
        },
        {
            0x873F9D646474BD00ULL, 0xD8B031B4742B11DBULL, 0x7B7716D1E80256D3ULL, 0x2CCC22DC6460F1D6ULL, 
            0x0878217D2DD3356DULL, 0x086DAF3EC3D5C60AULL, 0x4D5E53EFE599AF0FULL, 0xC4225905213A83BEULL, 
            0x4B352392FC88324CULL, 0x52B011A595DD7988ULL, 0x8B22C5061B2957B5ULL, 0x74E94C7A275967A0ULL, 
            0xC914663BD551E8D5ULL, 0x72C7DDC980A77CD2ULL, 0x9EFACEA34664E00DULL, 0xCB15FB5E59FC3F00ULL, 
            0x5C5714CDB19EF54BULL, 0x845E6E0F4F656794ULL, 0x7160F5A7AD197BDBULL, 0x4F74F74524571B87ULL, 
            0x89188FDBFFD3E6CCULL, 0x061585B1276989F7ULL, 0x3CD29C9B91F9E591ULL, 0x64357F21884059F9ULL, 
            0x1006BA486B727663ULL, 0xE54144BA21A3B90CULL, 0x2B2B1CF62552DE83ULL, 0x2F66828F826C318FULL, 
            0x6E760B3C5B6E5379ULL, 0x7E52243432C8C8D1ULL, 0x1E1A32C6D50C3C58ULL, 0xB6655F60786ECA30ULL
        }
    },
    {
        {
            0xD55259E54A15B2F0ULL, 0x199C14B136D10FA8ULL, 0x8744B977A691F21BULL, 0x1A48C1E284942C06ULL, 
            0xC8975B5D30F3A21CULL, 0xCC7869DE016A5BE5ULL, 0x543BEAC0EA98ADCAULL, 0x3E903FF5EA8803B6ULL, 
            0x52BC2CA109E754E1ULL, 0x97EEBF3BFD975C98ULL, 0x6AC560671C58E68BULL, 0x00506370882946E8ULL, 
            0xAA953E878D18D943ULL, 0xF490540DA188C4B9ULL, 0x6C892B9459DDAE3CULL, 0xB010CB3D100225C0ULL, 
            0x5C755D9C7F01DC31ULL, 0xEE6A7C77FE7C71C7ULL, 0x840E9C6D4D754FD8ULL, 0x8511E7CD0A4C5411ULL, 
            0xF8F40F039BDC2A2DULL, 0x33145E3972AF4D5FULL, 0x3C805C3BEF7A171CULL, 0xB8AC8736F30CD924ULL, 
            0xA94CC42744676A8EULL, 0xC75E6CDE2FC9CE5EULL, 0xF9D6827E0FEBCDBEULL, 0x3BBD9E9C59FB768BULL, 
            0x8686E6CE6B40EF75ULL, 0x8159DA46468FB49AULL, 0xE177A7D0D4F3C0E5ULL, 0x6210F58A83D926D0ULL
        },
        {
            0xD77FBFAC90302821ULL, 0x0A73DC050AF4E003ULL, 0xFECD3F4979C4E090ULL, 0x6147A0028A3520EAULL, 
            0x23C5C9F0F10957B4ULL, 0xF4688BD5E8AB35BCULL, 0x69E6595FB6A41453ULL, 0x08F2D22314A0F5A7ULL, 
            0x9613A2637A5FD154ULL, 0x3462583FCAA1D678ULL, 0xB2CE9D48A68B1952ULL, 0xA746789BF5267527ULL, 
            0x9FD1B6A42521803DULL, 0xDC03F0BD8BA650F0ULL, 0x1E3F06ABF8CD052FULL, 0xC94421EE4FC32A17ULL, 
            0x7A5A9DFA84AE4832ULL, 0xD44F1D2A3804EF11ULL, 0x99DEDD57CBD741FDULL, 0xB37B7847CA4B6994ULL, 
            0xDEB9FD2C16D50CE4ULL, 0x01F3DF857B5D8510ULL, 0xEDAC956DB40A559FULL, 0x0AA83763CDDD25FDULL, 
            0x0A5EA37E20D4190CULL, 0xF3DEA1B108219CB3ULL, 0xF21C4DA4EA55A744ULL, 0xDDA0E090B9A24848ULL, 
            0x1BBA8B290EF6E6EAULL, 0xA8DCCA6C0CBEBE96ULL, 0xADA2227E45D2D7D4ULL, 0x7629759D17442EBAULL
        },
        {
            0x10EF7CA959A34EB7ULL, 0x31CC910B31B74D58ULL, 0x28372E188458031CULL, 0xCB21D297CC88FBE9ULL, 
            0xFCFCEE0E3644A560ULL, 0x99738FEC16051958ULL, 0x93136253AAB7F85BULL, 0x0EAC3C4935B06C74ULL, 
            0xC611366A7F4BFE99ULL, 0xBF365C86BA222132ULL, 0x141D15431C513F3EULL, 0x9EA818EA84AEBEE7ULL, 
            0x4D459A1509D6FC23ULL, 0xEF65E589F550E28DULL, 0x842DC2627CA8713DULL, 0xAB1B9178593895EBULL, 
            0x8212091B622BACC4ULL, 0xC605C2DD02069450ULL, 0xF0E69D5E13CDC6A5ULL, 0x2C7CB9064169DA0FULL, 
            0xA80850319EE40484ULL, 0xD49D07CC1163394FULL, 0x84301993C14ADDDFULL, 0x9E650F69BCD63029ULL, 
            0x922E95E124F11649ULL, 0x0E981B1F57448E1EULL, 0x059EE1122B690340ULL, 0x429E844C9B557B16ULL, 
            0x26E8308477F55F35ULL, 0x4D7962C6CA346535ULL, 0x6604F8A9D1D1A7A6ULL, 0x152E913F29481B91ULL
        },
        {
            0x67BF2F4823625EDDULL, 0xA9342FE854C6AA19ULL, 0x6279608129B589FAULL, 0xAE486685A3C96EF1ULL, 
            0xF08A194F47F248EEULL, 0xE1FBE32C21BC950BULL, 0x5F4C64F5F8787482ULL, 0xCCD654392F052E24ULL, 
            0xF6DD11CF28874BF3ULL, 0x0DC8C102EF571B16ULL, 0xEA5C2D67B5D6EB76ULL, 0x9A5548FC6A9FF390ULL, 
            0x70F1108C67D40664ULL, 0xB725867AFB351F61ULL, 0x24CBFF38BCA581CFULL, 0xEB90791D18E725C0ULL, 
            0xE00CC401234DADBEULL, 0xF73FAA07F0899C8CULL, 0x2294620155BBD089ULL, 0xC8C25ED2C62B4A97ULL, 
            0xA458E8E94C58A4E8ULL, 0xBC3E11E7897B3460ULL, 0x7D754F1D4E285BBDULL, 0xD8442439C96DCD12ULL, 
            0x40B8136728C32C57ULL, 0xFB7B9D4BE6DFE485ULL, 0xCEFE7F8DEA1D4543ULL, 0x5CE28D0326AAFD4BULL, 
            0xE142157B3200C5FFULL, 0x7F7FA522089D7DFBULL, 0x4D7361EC1FE080ECULL, 0x95E5CDC718F7632AULL
        },
        {
            0x12B2856C3E8D18B7ULL, 0x09086300A015F9C8ULL, 0x289F4A1AD82A4FF1ULL, 0xC50AD4059B13A8DDULL, 
            0xB6BE7EB5422EC3F0ULL, 0xCA3B65E37D606CCFULL, 0xBDFB9125CBCCCF9AULL, 0x8A309F0B2C00D374ULL, 
            0xD77DB160E76D1EA8ULL, 0x549DEE144E152202ULL, 0xF7F12CBA06ED9C23ULL, 0x11192B372B9D2411ULL, 
            0x17EC9F217EFE4DF6ULL, 0x0B906478165BF7A2ULL, 0x91E12781DCBEE73DULL, 0xF767325FB4EFCBDEULL, 
            0x18E659A117C8A95EULL, 0xF50630E40CE87120ULL, 0x94D603357EE1D5C7ULL, 0x94C82CAF4C0BEF63ULL, 
            0x28FF6C085EECC117ULL, 0x21747B02F48A294FULL, 0x20BC9BF567ACE77AULL, 0x2538A4454C0EF91AULL, 
            0x9A9569E0D7035103ULL, 0x9B091712A048C6A7ULL, 0xFD0AE405A631C218ULL, 0x136A36BC2A886664ULL, 
            0xA198D98CD2D3A68AULL, 0xC27D6133948EAA8FULL, 0xB12CE246F09E1F2CULL, 0xE61E6095061F29B2ULL
        },
        {
            0xDED733D1B8B4F23DULL, 0x90235A5DD9E545B4ULL, 0xEE2C8D05C0B08581ULL, 0x55753CE36F2050DBULL, 
            0x324F288189E64CA1ULL, 0xD8F82E1CDE298FC4ULL, 0xA5C08666A512E340ULL, 0x3F6C42AEAC1D4BC3ULL, 
            0x0C9BC72F70598C97ULL, 0xA0D8F1FEE3C275BEULL, 0xB7D540FE97C35E2EULL, 0xCB7D300F039A3F84ULL, 
            0x88D3B57142F19D1AULL, 0x57BAD4D5F0EC5050ULL, 0xDD08D9E3DC776BE0ULL, 0xA8D01322C58DE283ULL, 
            0x215082D4F327DD16ULL, 0x725342B0A33F541CULL, 0x45AC629F7B8ABC16ULL, 0x1B1268760C6859F0ULL, 
            0x508B5B37E063A49CULL, 0x346DA199F3D98C17ULL, 0x99BB30B33AE80C66ULL, 0xB5169CE157250B01ULL, 
            0x090B2EA4ED1793FEULL, 0x7405E257B22B2B8CULL, 0xBD4AF00B6E00EB01ULL, 0xCB6725E91E76AA2AULL, 
            0x86A5FE442052227AULL, 0x19FF14CBC9B9E500ULL, 0xA62A0CD3BAB43B26ULL, 0xCB548757466E22DCULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseCConstants = {
    0x1CA89DC86473F7CFULL,
    0x351DA173C3E7CCF6ULL,
    0xC746A63B6C72E1B4ULL,
    0x1CA89DC86473F7CFULL,
    0x351DA173C3E7CCF6ULL,
    0xC746A63B6C72E1B4ULL,
    0x9F5E50E3EC36E0D3ULL,
    0x084FF856CBF503DFULL,
    0x46,
    0x72,
    0x79,
    0x96,
    0x69,
    0x69,
    0x40,
    0xAC
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseDSalts = {
    {
        {
            0x4ACD036737EFABB7ULL, 0x007D7D8AF0D75FC8ULL, 0x55182A9CDBA64FF9ULL, 0x45159352E929AB7FULL, 
            0x3AB4B6E2733CAEC0ULL, 0x5F3231370AC5C835ULL, 0x57F158021F30CEAFULL, 0x0893A6CEA836564AULL, 
            0xFD536A51DF197174ULL, 0x6885DBAC1E8C7EC6ULL, 0xFF3D42CF3516E0E3ULL, 0xAAA62D03D310C63FULL, 
            0xA2EF2B2E5711D589ULL, 0xCC1DC74CC803FCBFULL, 0xC3C7A419CCDCB982ULL, 0xEADA24E17F899DD4ULL, 
            0x5909DF669F5048E5ULL, 0x58DE202145DF7C72ULL, 0x87FA1B65D41F8693ULL, 0xBB16E2F6A0125239ULL, 
            0x1706198C73904526ULL, 0xCEA39F4FA1074DA6ULL, 0x582ADF54CEB53964ULL, 0xFC9C3D914BBF343BULL, 
            0xF120996CF50642D6ULL, 0xEB5A3C25F75BB93BULL, 0xED7BAAFD5EDC3C96ULL, 0x114C901200D413A6ULL, 
            0x29E6EC9E822A71F0ULL, 0xB2D4CB8EBA3AB1DAULL, 0x1154F73414FA37EFULL, 0x3F15514CC63016FFULL
        },
        {
            0x1ECEC59861DD6A6EULL, 0x0DDA360E4A59B1ABULL, 0xCF490CF7D52252F1ULL, 0x9154754CC7E926ABULL, 
            0x469107BCB8C20100ULL, 0x8C706A15F96231D9ULL, 0x8778A9743A228F9EULL, 0xF779C10E7E72F83CULL, 
            0x31C23E776E4495ADULL, 0x21A774D1C9362437ULL, 0x9055F35A99707C62ULL, 0xDE927A8CA1939FEBULL, 
            0xA796430DEDBD7B9FULL, 0xC7AE3181DD5081F8ULL, 0xCE0E02BF3EA5DE7EULL, 0x29A0323A4CE25F03ULL, 
            0xA34D8322B8284AAFULL, 0x11A5A7028840AC60ULL, 0x48009895BD984105ULL, 0x203EB421FF1FD092ULL, 
            0x6027C63E73707637ULL, 0x6AC6E8E98C90C5C7ULL, 0x222B73D5A648E56AULL, 0x38629CA64CA9B964ULL, 
            0x7E6391F91D4649A6ULL, 0x95A4E1068C1A040FULL, 0x298D9C94FA3797FFULL, 0xF9623ABE1922582CULL, 
            0x0AFE50185A50E5D5ULL, 0x755F4B687517B4CEULL, 0xD9B0728DD28BF885ULL, 0x1885CD0EF7C2E876ULL
        },
        {
            0x1A70A7CDA1F6A6E1ULL, 0x4F7E419F529C4480ULL, 0x0CC5E527809F8322ULL, 0x0E8CB526A3540713ULL, 
            0x845CA395C59E08EDULL, 0xEA85E9DF8B2C9B79ULL, 0xB4A33D46ABBB3F2AULL, 0x446049ADBA85C5EFULL, 
            0x0FD2F3ACEA382D24ULL, 0xD18F56CB4510DB49ULL, 0xED3EE54897DEF7DAULL, 0xFCF9919638CEA822ULL, 
            0x14773C7FA5D158CDULL, 0xB2565ACAD800133AULL, 0x072341F1CD9C128EULL, 0xF83A81DE89E49240ULL, 
            0x8D3844A69CD06056ULL, 0xDA8BDDD88100ADE1ULL, 0x17C3DF46F999C7EAULL, 0x07829EC74FD6D84AULL, 
            0xB65548C78747370EULL, 0x9E90C79FA4119A85ULL, 0xC24E43226AFC87D7ULL, 0x8A5BCC7596AA7BE6ULL, 
            0xC85223012255707DULL, 0x1495D5F0B1AF46E4ULL, 0xBA3880CDB28C9D2AULL, 0x0F4EC836BE5609F8ULL, 
            0xB40860C43153A3D6ULL, 0x41451302E6D4C0C3ULL, 0x4BABB86EBB67C4B3ULL, 0x3F9475D2EFA19749ULL
        },
        {
            0x6399C780C6071E6DULL, 0x83CD25CE8BDF31D7ULL, 0x851A3DA8F703BCD9ULL, 0x4DFB6B71BCEA6B2FULL, 
            0x53A88BEF3676D7A5ULL, 0x30696FAA4FC9725CULL, 0xD90718CB3E55F2BCULL, 0x3A23EEABFC844817ULL, 
            0x302427276BEF4D7FULL, 0xF0F4B0BFD1B9499CULL, 0x1795E4C2047A33DEULL, 0x11635139FAAE91AAULL, 
            0xAB12D45A78FA1E52ULL, 0x2352A376B8635CEDULL, 0xF4A85D355F1E9C42ULL, 0x0D99B62D0A51073EULL, 
            0xDD72688130D964CEULL, 0x60EE81F88B650E4CULL, 0x6D1F5F1472BBAF0FULL, 0x0012CFCE493F1FDFULL, 
            0x84BF5EAF2AA41927ULL, 0x5E58FC7507A574D8ULL, 0xE9A15862015C2E1EULL, 0xE6699B28AA9006FBULL, 
            0x8E1A4BB55DDE7500ULL, 0x2B9A0D0227CFF398ULL, 0x3E2387BACF606D7CULL, 0x71EF99421925FA11ULL, 
            0xB494A9EBE53B1FE3ULL, 0xC87F69F426E65D29ULL, 0x28923EE763D00DB5ULL, 0xA3A76B537C6EA27DULL
        },
        {
            0x709E4928506A8759ULL, 0x4F3068909FCFDA9EULL, 0x4296635E32305D58ULL, 0x9A0F727B78C5C0A0ULL, 
            0x61FE8CC440BA7CFBULL, 0xF2F16F41F3232AF5ULL, 0xB249E50958A984D8ULL, 0x2A6D50ADA6357061ULL, 
            0x5C285FD295EBBBF3ULL, 0xBA424E90F159B846ULL, 0xEB4DAFDEE851EBD9ULL, 0xAE43D0C9BC6085A5ULL, 
            0xE0D316E71877485EULL, 0xBBBAE4E17097142AULL, 0xAE5340F96A6297A2ULL, 0x0FE0AB14459237E7ULL, 
            0x9EDDB47C1E98F470ULL, 0xAB0758308EBFDB30ULL, 0x6DF66CDC49292676ULL, 0xDB02EFA62A903C78ULL, 
            0xF93ECB89DA73B0B2ULL, 0xDC503BEA979DA794ULL, 0x8E5A7B2F967A07B7ULL, 0x4456595783DEB0EAULL, 
            0x05818AC21CE0D971ULL, 0xE346ABC2FFCEB2F8ULL, 0xEB8D14FBB17F5D3AULL, 0x6F823FF7C2B8B563ULL, 
            0x7ED25715280246F5ULL, 0x8B59E04C8BB6AA1AULL, 0xA0B1C053D0E59EDFULL, 0x5BC704F53AB70E49ULL
        },
        {
            0x81B3E22017CAE445ULL, 0xA7183C98B40ABD6CULL, 0x7634B522AA854697ULL, 0xE6DFB351E91BB0DAULL, 
            0xD4FCAC39FEDF496DULL, 0x1B21C6FA6AD266E8ULL, 0xBFD44A27533F0C48ULL, 0xE030399609539632ULL, 
            0xB85DC91E7EF25FB5ULL, 0xB8E06DE592EC6FD9ULL, 0xE41A3F02F5F43718ULL, 0x192C0AC4703230C6ULL, 
            0x99D56F79E9A25F35ULL, 0xD1EC1DCB47352251ULL, 0xAB3FA37353414E1FULL, 0x3AC601192B057420ULL, 
            0x6AA8486AAA805DF7ULL, 0x94D4690B9BEC545AULL, 0xEE2DC4D9898F1D8AULL, 0x547DB92263653BF0ULL, 
            0x2349BF074C7CEC35ULL, 0x20ADF8335AD4ABA9ULL, 0x6B1784500D461D85ULL, 0xD3B380F134057174ULL, 
            0x8E1E368A306B63EAULL, 0x1C6069E9E0003E0EULL, 0xA1D1C7EA3B4DB9C6ULL, 0xBC042EC2342E3768ULL, 
            0xBE11E634839FDEC8ULL, 0x6799E66B6D4BF02BULL, 0xB60270F766432B64ULL, 0x250094735B525C89ULL
        }
    },
    {
        {
            0xB54FCB38799BE2FDULL, 0x42A5E04CE8FEBB92ULL, 0xF40EEA1A0223E125ULL, 0x17FD5630755A709BULL, 
            0xA462C87E279BB69EULL, 0x7DE759FECF3AF7DDULL, 0x076E82929C61F7AAULL, 0xCB08D3E4A35325BDULL, 
            0x65F5A2863A964B4EULL, 0xD512F779F96EF4C0ULL, 0x23A3A953B795E103ULL, 0x3CEB4990F7D437DAULL, 
            0x2EAA34C011F1DFC8ULL, 0x581168E9A4D05CF5ULL, 0xD8BA76F8A0F0EE17ULL, 0xA3D4F8068A18358EULL, 
            0xE8724EB3345EC7B0ULL, 0xB00102A877D21DB7ULL, 0x8C144659199AFD57ULL, 0xA0B59E196E6D2138ULL, 
            0x8AA6135939A01EC7ULL, 0xAED3D6CCA2D512F4ULL, 0x020466C868968F50ULL, 0xB275C314AA3079CDULL, 
            0x077581C1E69E19D4ULL, 0xE3B9A228A7D58BBBULL, 0x539F8E5A202A4C7BULL, 0x6F3D283E66C83A5BULL, 
            0x6606AEF7636A13B2ULL, 0x72719548ED788AF1ULL, 0x95B9255C152D1514ULL, 0xA4E68466FB91FD0AULL
        },
        {
            0x3655D6DA7A072BA0ULL, 0x77AF1E87F53B36F6ULL, 0x4255D4976BCF2885ULL, 0x36389A3740DAAE72ULL, 
            0xF13E0033F4B32295ULL, 0x7CC8FAA379682992ULL, 0x97C058D80D4C6F5FULL, 0xB2AB558FC10300ACULL, 
            0xD13972CAD740C753ULL, 0x859B2311573C42F7ULL, 0x954B26228877BC20ULL, 0x6E2912EC4BAD3C1AULL, 
            0xF73C7C5190307D7FULL, 0x29BC230024C0A777ULL, 0x051CC0CC22797758ULL, 0xF37036E1E819A5EBULL, 
            0xA829A329AB4A45E8ULL, 0xA42EDF478A374C44ULL, 0x791A4AAC042AC7DFULL, 0x683C1A0ADE52A6BCULL, 
            0x6AB5B651611D00EAULL, 0x738DA6B3B5E6A654ULL, 0x1778A8F978FE49A9ULL, 0x0DB2A5886637F3CCULL, 
            0x088C08C53834BF35ULL, 0x2F2F4DE20A3ADAE0ULL, 0xAB9CE043033FC79BULL, 0xF620150650A1649EULL, 
            0x42DD20205C287DD6ULL, 0x7727CBBAABB78E19ULL, 0x7AEB22429472ABC1ULL, 0xEAB9D722F8D8C5B4ULL
        },
        {
            0x27D787CC0A60D4EAULL, 0x108203BC7AA39F80ULL, 0x51EBCF8EB3165FC7ULL, 0xBA3EDBDF8D14528EULL, 
            0x5DC5DBCE1C6373D0ULL, 0xB8B03D43355733A5ULL, 0x8C8F20628151545AULL, 0x6ED5AB777D86D5C9ULL, 
            0x9CEE2D54BDA09E90ULL, 0x816F27AF1B07AB87ULL, 0xA137098766F24120ULL, 0x50CB9FF7E028C3CDULL, 
            0xC52A5E95A6B5A4D1ULL, 0xFF2597F3360269D3ULL, 0x5B12BB80328AA293ULL, 0x3F4F88B66E940082ULL, 
            0x2253B75D3C5C3BB8ULL, 0x14D35EA7BAEC10E4ULL, 0xC19A54E7A0DA04B5ULL, 0xCF08643C264D8142ULL, 
            0x50CA453088F03FFDULL, 0xAD47A48B3DDCC50FULL, 0x4730167B81160734ULL, 0x1C58F8926770068FULL, 
            0x444F190CB05AFC51ULL, 0xF2B4A4C4E93FB218ULL, 0x14BBE58DE074969CULL, 0x3137B1093498C435ULL, 
            0x1BEBEC17AC863E51ULL, 0x9D62D4CEFBADC34EULL, 0x5C5EDB644C6937BFULL, 0xD7FB4FF5FDB0D3D5ULL
        },
        {
            0x4EE076F25B8B6624ULL, 0xF93A432B0E19FD2EULL, 0xD4E2975E8052A01CULL, 0x1CAB94BA126C283DULL, 
            0x744E3252EBE7A2F6ULL, 0x15EBA7AEF883CCD0ULL, 0xCA242DD1CCE96B5CULL, 0x3679893FABEBCF08ULL, 
            0xF8746869E36E8E35ULL, 0x31C9D3A8E7CF3E7EULL, 0x7219AD96D72F5B75ULL, 0x47B8C3562EE444E9ULL, 
            0x70AFEE9FFCB1B15EULL, 0x3E42BDFDF196C3CDULL, 0x8CC233AF0794D48AULL, 0x6EA9E61AEC452690ULL, 
            0x66D13254FF286F61ULL, 0x0CF43B3654DB626FULL, 0x45200B31A6198678ULL, 0x51B1F38F42C27EECULL, 
            0x904CA4A39E9B1880ULL, 0xA85C5075A9FC51EDULL, 0xA171EE56A6EDBA66ULL, 0xD84DE0C922B164B6ULL, 
            0x427A5FF47C40765CULL, 0xCB038C06E8A3DF21ULL, 0x308D90510C01552BULL, 0xB00969E88BCAFDF2ULL, 
            0xED54C6C8DAAABFE8ULL, 0x15F5C5BA16F93572ULL, 0x62A8C299D32C1F6EULL, 0x308BA9E977408055ULL
        },
        {
            0x86AD8B0618BDD05BULL, 0x61A75EE41CC33D27ULL, 0xFB4A5E7C4306F93CULL, 0xC89DF2BBB7B544F2ULL, 
            0x597575EB11F85F1EULL, 0x9B846761CC98746EULL, 0xD9F7F3F6E50E4CE5ULL, 0x7E3F118933839C75ULL, 
            0xF0DEE9DDFAC59311ULL, 0x46277B1FD618C853ULL, 0x7D8D1CFAEB95F9A5ULL, 0xD81FC3E3921304BFULL, 
            0xA97816D07DFA5D3AULL, 0x8D5BD47CC70DF41DULL, 0xA8E2E0994EBFFE31ULL, 0x07D46A8FC48602B4ULL, 
            0xDCD636D5248F2E77ULL, 0x9DA2618159219802ULL, 0x7F1F07F8BA3F6BA0ULL, 0x9DA015AFCB9BDEB9ULL, 
            0x52640DE31D2FECA6ULL, 0x7C50810761AE9BF9ULL, 0x672EF98C9A4830ECULL, 0xDC4FC2349ABECF38ULL, 
            0x0431CCDB4FB6D675ULL, 0x6451AF104AF01E82ULL, 0x0B49CF4D34611D2FULL, 0x5C52C295C0EBBBB9ULL, 
            0x6715A4A65368A95FULL, 0x918AC10369519555ULL, 0x9F1CEA5855AE0220ULL, 0x71A06C079BC833E6ULL
        },
        {
            0xB4519C7A44EE38B2ULL, 0x87F35617D71F9292ULL, 0x308F68BBEAEFE94DULL, 0xA38C27BD2AAA8924ULL, 
            0xE64C90C3850F9951ULL, 0xC24C2C9308D6A3A8ULL, 0x5AADB405D20A52EBULL, 0x6369E364BB6A5579ULL, 
            0x5FE531C4F3CE8E15ULL, 0x20DAEB7C9579E566ULL, 0x823E314F5EA98381ULL, 0xAB2220214E64B7F6ULL, 
            0x760A53C14CA26924ULL, 0x65B2D4AE359CF395ULL, 0x2C4720424C0A7111ULL, 0x8FE8C27053241E61ULL, 
            0xDCBBD9FEA1C64118ULL, 0x301599CA312A525CULL, 0xEC5268968EF36B50ULL, 0x4904F44E7A0F5DBBULL, 
            0x4AEA8856FE8F2C16ULL, 0x72A602430F800DC5ULL, 0xD76829B3FA465902ULL, 0xB9B2574F04898B88ULL, 
            0xC2C97A54D47259AAULL, 0x4EEC5DA468D1397DULL, 0x03A72F70C5E2B5F7ULL, 0x6C9A81A00D2F3A7FULL, 
            0xD22715A1801A5C77ULL, 0xA623961627601290ULL, 0x4C3385EC8B7B8123ULL, 0xEBAA71FB00732174ULL
        }
    },
    {
        {
            0x059608218361D7BCULL, 0x743FBFABCAAB2ADAULL, 0xC60AF0FA88601CA0ULL, 0x8B9AEAC5337A8716ULL, 
            0xD6DAC66CEEAF4392ULL, 0x686315212CE1354BULL, 0x09573C1CE6EE3BD4ULL, 0x8842BBAE6F045C85ULL, 
            0xFDCFF5B083942D9AULL, 0xEEF79B143964BE43ULL, 0x1563116CAACFC3CFULL, 0x01194FFC9E40B2BFULL, 
            0x04FD4B10DAA7A20BULL, 0x9F2F1F5267CF47CDULL, 0x468DD0792246404CULL, 0x784F356322F14919ULL, 
            0x1317485D632184B9ULL, 0xED21383250DC70C0ULL, 0xF9680298FE6B1F9BULL, 0xCCF7C3AE3785B3A7ULL, 
            0x857F2A1EB596DD03ULL, 0x6D3C8A8472CCE333ULL, 0x0E6BD516C9AD1084ULL, 0xD13A09DA7527C583ULL, 
            0xCF45F834EA35ADE4ULL, 0xF82459E5EF7EDE16ULL, 0x1ED6F96C7A9FB5C1ULL, 0x2E20FC29E690B3BBULL, 
            0x617842C17D7908B5ULL, 0xF2EFF81C162F99DFULL, 0xE883549240DCC967ULL, 0x714949556408ADD1ULL
        },
        {
            0x87B346C96B099961ULL, 0xD42EDE13AECD487FULL, 0x6CD78E3B98ACDF86ULL, 0xC2783CDE90BE973DULL, 
            0xAAF7CD21AE8BDDFEULL, 0xF71E685D97CF65F5ULL, 0x2F816F7A777B9A5CULL, 0xCA44001D601A9169ULL, 
            0xBCEA2646F3B303BEULL, 0xD990BD66D6E543A1ULL, 0x356E2946B90D4550ULL, 0x7F315AE2E624E8E8ULL, 
            0x5E9DF193572147BDULL, 0xD9F199375C914F90ULL, 0xEB53587293A70F05ULL, 0x284806F622395BACULL, 
            0x6800B8A075085697ULL, 0x2CB3309D9D51313BULL, 0x56726839B8B218D7ULL, 0x219A9247FE6DDD30ULL, 
            0xC4825BA48F7D711BULL, 0xCC98224617AAA7B0ULL, 0x4178096909FB8FC2ULL, 0x2FC4FC7BB94ECAEAULL, 
            0xE54BDBD5BD8D3CACULL, 0x014824C5624E95E9ULL, 0xEC250B8655704711ULL, 0x17878D03889F092EULL, 
            0xB291571314A34D86ULL, 0xDEB18790B8713834ULL, 0xDC02EC9CC1C7C252ULL, 0x543D2C97CB3E69BFULL
        },
        {
            0x3FFDB1BBB28597AEULL, 0xEC5B17447D66EACCULL, 0x9F6EDCE3BE072372ULL, 0xF9B5500363503780ULL, 
            0x4951A3E3669F0B4BULL, 0x0D3D86119C9FFDBFULL, 0xE2391DC50263772EULL, 0x3DF56A24560115EBULL, 
            0x1A82932CB9B77B2BULL, 0x46056203C9A23D7CULL, 0x9CF9BE2E89C6533EULL, 0x41D0D5D57278B19AULL, 
            0x65412DC2D18EAC82ULL, 0x6130EAFD21DBF654ULL, 0x0A43EB71F825A475ULL, 0xE5DAED7B8247A8A5ULL, 
            0x97BEF75D803FABC8ULL, 0xBB5324F427265B02ULL, 0x09E6E6E15CDC876CULL, 0x73B99209E48C8CB9ULL, 
            0xE447FAB331C8612CULL, 0xDC881C4DCA9569BAULL, 0x06E1EA6875C6A715ULL, 0x717CFB575B2144E7ULL, 
            0xFCD99BCE7171CB04ULL, 0x407514EB6F0560EEULL, 0x3808A67DC26A4025ULL, 0x6F1FDB51ABE0679FULL, 
            0xB0CD40FFC4D6E026ULL, 0x641917ED70DD0E44ULL, 0x6CB98459A51089D0ULL, 0xC3F80E2580B35BA4ULL
        },
        {
            0x710CA708E3A0A101ULL, 0x20B45887DC123D47ULL, 0xA8B9141D210E9B66ULL, 0xD4A020D8268BD23BULL, 
            0x5E975847613CA9AFULL, 0xECE33B3B8D601AACULL, 0xC9FEBA12417A9A8EULL, 0x276C97DE9937CD9FULL, 
            0xA3D96365FA88DF48ULL, 0xC94E062D9C43B20EULL, 0xD9FAE3D1FA63B375ULL, 0xD04DF29A876AED15ULL, 
            0x0D1D5CD319F62505ULL, 0xD37E6AA1ABF3316CULL, 0x695C37E1D5A60060ULL, 0x5399938DC4FDE3A1ULL, 
            0xCA6CD1E567CAB7C6ULL, 0x75A8D2EB085BB977ULL, 0x5C1B2449A0B1A2EAULL, 0x54370B4AEBC04E67ULL, 
            0x8DEF918F8C7F681CULL, 0xD9FF2477708F4D45ULL, 0x2386A6D6A5738813ULL, 0xF4187CEC00F02155ULL, 
            0xAE46477DD16B54CDULL, 0x755A24CE8FC4A49FULL, 0x2449C0D08607EDE5ULL, 0x5638989C684AC40FULL, 
            0x3212A1BEE8C18C4BULL, 0x511FF2244AAB01D6ULL, 0x8B501FC23D7A859DULL, 0x6D1CF83BF4F422F8ULL
        },
        {
            0xF94D905F883848B9ULL, 0x0C0F212360436657ULL, 0x1B39E18001A12C1AULL, 0x8C080A17965AE9F8ULL, 
            0xAB5E0A82362AE54AULL, 0x0DDBDEB361EC4202ULL, 0xECE815CF324F4494ULL, 0x3121D22A8FE134C0ULL, 
            0x9E79C31F729D47DDULL, 0x8C7E066CAE254F0DULL, 0x30480BC3ABA084DCULL, 0x964091A868B9FCA8ULL, 
            0x58693ABFDE83ECEFULL, 0x6E9E7AD9F33C7BC2ULL, 0x71C37E14F8791AACULL, 0x1610EC0CE6B830F5ULL, 
            0x620E8FA4FC6865B7ULL, 0x7F34CA161006A811ULL, 0x1C380865D2262A5BULL, 0xC9A2D0CD86CC032BULL, 
            0xBF85ABD76DEF7F42ULL, 0xE39F2D2A0A67BDCBULL, 0x84C9C50D0A8A4F69ULL, 0x47922F301C0E0A06ULL, 
            0x09B693FAF322FDD1ULL, 0x77F2AC5783BA97A4ULL, 0x1F252C3599965083ULL, 0x8B6BFE6D6046795DULL, 
            0x73DD73565674F77EULL, 0xE5A24053D84A2DE8ULL, 0xCE0A5BC0B5497B61ULL, 0x7D069952ABD5C6E5ULL
        },
        {
            0xFDF6EB864AECE5FBULL, 0x528ED4464D8118D2ULL, 0x9C52B9083A2EB497ULL, 0x8D1F36F8AF020CABULL, 
            0x8AB85C3A7F9E4C7DULL, 0x0F1C6E8A117E931DULL, 0x7F2CE3D452AF2860ULL, 0xA8DF9E0305278D33ULL, 
            0x2E3DB8CA541745CAULL, 0xD809A03D4AA59C9FULL, 0x82FA99992A32F1D7ULL, 0x332AA6EC494B6E70ULL, 
            0xE8A864036F49366BULL, 0x2965BC2729F0F5F3ULL, 0x43C97BFDBCE52EEBULL, 0xCE2C24E1D8C4F01EULL, 
            0x03920D304DE9AFA1ULL, 0x03CE4283323043F8ULL, 0x7700BF5E2A526165ULL, 0x1E7655FA8CE29462ULL, 
            0x3747BA3BF6E4FD5EULL, 0xFB71B58EC80E1F4EULL, 0xCC54071E20734A0FULL, 0xEF03D5734955279FULL, 
            0xC2C623775A57F3F4ULL, 0xE429922ADE3CECE2ULL, 0x9394162A9D0D789EULL, 0xCEE05B264DADF266ULL, 
            0x3D3D8D45AFE9EDB9ULL, 0xC4838970DE3A7A6DULL, 0xF3635626B0354AA2ULL, 0x36BE444FD23351D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseDConstants = {
    0x8B87E0A208ED0020ULL,
    0x90B82F2D185A78DEULL,
    0x711BA8BD3EAB3E36ULL,
    0x8B87E0A208ED0020ULL,
    0x90B82F2D185A78DEULL,
    0x711BA8BD3EAB3E36ULL,
    0x1987D00F65E3772CULL,
    0x658B014E93822977ULL,
    0xA8,
    0x10,
    0x67,
    0xD6,
    0x38,
    0x22,
    0x3A,
    0xCE
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseESalts = {
    {
        {
            0xBCCE10A2662AAFC9ULL, 0x5B8C3A030FD95A6EULL, 0xD6876DC839738D5DULL, 0x1336575EB397C0C2ULL, 
            0x92D378FA71CB1C12ULL, 0x1FFDCF7E9CF078CAULL, 0xD1A529A2A1DF2058ULL, 0x796D0A252609E868ULL, 
            0x941A2975405D3D2CULL, 0xFCB0ADDBA873D559ULL, 0x690983FF3F4FF483ULL, 0x592C4C6C7F7766CAULL, 
            0xEC619869ABEBF0ADULL, 0xBAA52475A4EDF323ULL, 0x4AD9625E1EFFA00EULL, 0x00FE48A1A2FF7945ULL, 
            0xD4B105EEDD7D7C86ULL, 0x01D0FE3CA5078A28ULL, 0x5DEABBB0B82BBD20ULL, 0xA3220CF64BA0AEF0ULL, 
            0x77ACEFF11CE8D4A5ULL, 0x5623E90CEB1204B0ULL, 0xD0F3B9C74065D0C6ULL, 0xAD4FDA63A4E61BD1ULL, 
            0xA1465EE0CEC96037ULL, 0xD055828474DC8062ULL, 0xC51F07047F641804ULL, 0x00CBFBF0BAB32656ULL, 
            0x27A0A7672FFCAD81ULL, 0xE067030B3C0ED989ULL, 0xC18B095DB43BF055ULL, 0x35CDB298745AE44DULL
        },
        {
            0x35EEB0D0C62885C0ULL, 0x3E582E5588EDC25CULL, 0x84E938BE1C9C6DC2ULL, 0xB2033A9090B32238ULL, 
            0x99E37AF000C49FF7ULL, 0xF62E18A6A40CBB32ULL, 0x0A934C4D8F90B3A7ULL, 0xECC7EC5832A14CEDULL, 
            0x78FF3ADE0985C1A2ULL, 0x24A5405AD147689BULL, 0xB0C13BC1C2552DE7ULL, 0x9AC96BF328A01059ULL, 
            0x4920F2620BB3B5B2ULL, 0x5BD64AF264014EDEULL, 0x05268D64E53E0BEDULL, 0xC5FC9F5B4D6B5BA0ULL, 
            0xA5EFDEB1E4004959ULL, 0xD50F0E158C6AC4F9ULL, 0x1CC475F1423D8DBBULL, 0x805E804C8DB847A9ULL, 
            0xEA0217D56D6FFA65ULL, 0x081B5CD32BF34C14ULL, 0x9049E5F04C75DE10ULL, 0x99404BC38C689B1DULL, 
            0xA07CE7E09B697AB7ULL, 0x44A1EC012DC06FE5ULL, 0x594D28A4CEAE09F2ULL, 0xE4360B66916DC136ULL, 
            0x532DDF109197BD8EULL, 0x228CDA7ED7A0CFD8ULL, 0x1EBE6590AC5B9741ULL, 0x040DB29E24D7290DULL
        },
        {
            0xE271610E0D659BEBULL, 0xF27BD287B515D5D6ULL, 0x10887741BF98174DULL, 0x78E585ABD76FD9F1ULL, 
            0x2A9A990F7B2A3B74ULL, 0x568DE6E4275BD3C1ULL, 0x8F6463118DBB0195ULL, 0x56E006A43B68CEC7ULL, 
            0xC6DB98437526519FULL, 0x72F16CF0FB875745ULL, 0xF6750ED6AEF53356ULL, 0x0385475F2DE4D8C0ULL, 
            0x771B07F94BFD2CDEULL, 0x0D3D72409D5EB2F8ULL, 0xEFFA09B9B09579E9ULL, 0x349A7CB19F2C4FDEULL, 
            0x4FE57E6415B32105ULL, 0x5351339279BF2B57ULL, 0x91753A0D13DFB986ULL, 0xDA7AE1B6FEDBFB72ULL, 
            0x0D92859288DB1B1EULL, 0x71B754F5D6A43672ULL, 0xF4E420FE137A0235ULL, 0x0F1800902336DD4BULL, 
            0x146F1E87364CCFFAULL, 0xF2CEE60500E62367ULL, 0x50B6F0CADB3C2B7DULL, 0xAB7E20D42979F51DULL, 
            0xB7CD17FCD564F8A0ULL, 0x6DCD6D09F836D7F5ULL, 0xA1D8F8D0A2682C2DULL, 0x2A7B92D5DA96D131ULL
        },
        {
            0xBD684C2007030D7BULL, 0x4B468067656661BDULL, 0x83B71470E8052486ULL, 0x2C6A76BB9EC34CB9ULL, 
            0xBDB566EE5264A468ULL, 0xE9A1B935DDD97956ULL, 0x001C20706F901E94ULL, 0xF254B82F5F3E8E31ULL, 
            0xF4250426CAB96D8FULL, 0xFE97EC9AB6830134ULL, 0x095E896FF476E751ULL, 0x0B84DFB664E6CA1CULL, 
            0x5F31204162B83D70ULL, 0x3897BD29E428F61EULL, 0xE1E1A1C4E75F1A16ULL, 0x05F1E31334C400F6ULL, 
            0xFFA02A7B5C931590ULL, 0xB5BBEB5BE7FEBAB5ULL, 0x33A041A7D2784E42ULL, 0xE5E98267B7701C55ULL, 
            0xD4C28AB35C73D7E0ULL, 0xBCB563701C72D339ULL, 0xD0C25458BC7547BBULL, 0xCBF63377C763C75FULL, 
            0x3A1A29A315808E9CULL, 0x03CDFDB5E8F4F7C8ULL, 0xF08CA6CE604844F1ULL, 0xFDFD729873785BB2ULL, 
            0x62772023823416C6ULL, 0x6934C1779061D62FULL, 0x9529AF1BE942A7E1ULL, 0x91650FF3B1FBCAE4ULL
        },
        {
            0xC5CF0F05181F0A14ULL, 0xC61B6A0CA4C40C52ULL, 0x15D9A9F7F9BB5109ULL, 0xF7CCC271E969D14EULL, 
            0x2BBB020BB5465572ULL, 0xE224E9B373BB7C5CULL, 0xB3298F49E7864AF8ULL, 0xF66D5230FF5FBD74ULL, 
            0x463DE5ED0A88D6D0ULL, 0x024613C80CC18E9EULL, 0x02F8D4E3C39F35C1ULL, 0x1A7B70F5301DA97CULL, 
            0x7BB655E9FBCD3CC3ULL, 0x188FB626CCD8FA9FULL, 0xD417B5C5BF2FAC44ULL, 0x3DF034A98953EE6FULL, 
            0x21A50802FC32D432ULL, 0x8635B916AFA0DC32ULL, 0x0D00972D417F9E21ULL, 0xB0574D340D615E57ULL, 
            0x3DF1D01EAAD20897ULL, 0x67DAA1B0C9E27674ULL, 0xB9A47B1AEBD5B0D9ULL, 0x5947551842B26FEBULL, 
            0x03FF28DD95609F0EULL, 0x863591F4AAAC4841ULL, 0xC52966554A0C0A25ULL, 0x91C22132549E9C5EULL, 
            0x51CE9C4BE070084DULL, 0xC62EAD0633772942ULL, 0xB1E056B57BFAED1AULL, 0x75D4E8656ADF519EULL
        },
        {
            0x6175E3765161A00BULL, 0x90D7EA5D56439E4FULL, 0x790F01F2222B9E7DULL, 0x92FF92438FB4329DULL, 
            0xD2DEAFFDF471DF3FULL, 0x60663C539D64ACCDULL, 0xA8B23878FEE2D873ULL, 0x2F611C83532FE9CAULL, 
            0xCAF95D671DEDE6B5ULL, 0xC76EF377767E8183ULL, 0x86B7287C9335F0DDULL, 0x39A8BF59EC25F428ULL, 
            0x4C25369EA7C682CFULL, 0xF263A1C9145BC612ULL, 0x634454637B1500D3ULL, 0xB09F6E3DCDE77B1CULL, 
            0xA9ACE753C3A2830AULL, 0x9F702CD3330E968DULL, 0xB9006513059D14BEULL, 0x491388F44D7419E6ULL, 
            0x13ECCB15CD1C4DC1ULL, 0xDF0C662CE8BCEFDCULL, 0x16314BC8AF82C7F5ULL, 0x5713BA9FA6AF2BCFULL, 
            0xFCCF1D600EBB0FF7ULL, 0x6E513C584F6A3AC9ULL, 0x9E7DB0B0C29FF382ULL, 0x00C946424BB192EFULL, 
            0xFDD8AAC479CBC198ULL, 0x4B45B134823D5F2EULL, 0x3FCD804735080230ULL, 0x50B14330E0E6D2A3ULL
        }
    },
    {
        {
            0x6B437A9C7D44AF83ULL, 0x1CC371E6B4309EC0ULL, 0xD67A6163AE58AF69ULL, 0xA72C8304F7789BF9ULL, 
            0x02BCD875F24EDCEEULL, 0x9B2E24A0EBDD69BFULL, 0x8534B5D060F7D0D6ULL, 0x23577B4B84E128F6ULL, 
            0x4655FFD60B700E4DULL, 0x877FE08C5109144CULL, 0x9522376D8321E8ABULL, 0x8702D59E6E13DC65ULL, 
            0x287944C1B90455B8ULL, 0x4DF46400302A9647ULL, 0x64FC21FD83394EADULL, 0x4B16FBBABB56A0DDULL, 
            0x0E5179553888B17FULL, 0x8563B46981E4A9D6ULL, 0xE8FA8A98EBC1F85EULL, 0xC93C7FDDFE5AFDF7ULL, 
            0x6DEEBE289E7FCBF1ULL, 0xAF822EE73D403633ULL, 0x8729C07B989A325CULL, 0xBE284C2887419702ULL, 
            0x70B0882852F56707ULL, 0xCCAD49090CB04416ULL, 0x6D0F2637633CD74BULL, 0xE525C58806AAA5B2ULL, 
            0x88ABE21C380D7B6DULL, 0xB08970AC38A68C3EULL, 0xD2BBDC523CEECE39ULL, 0x5FDB73096BBDB8C4ULL
        },
        {
            0x02E6A5B6A6A4E13EULL, 0x9589B1C98C2257E4ULL, 0xC3217B77C7177307ULL, 0x405E0F128ACB1E22ULL, 
            0x462F57B65A301D16ULL, 0xC09F830F62FC59D8ULL, 0x48603E1CCDEB7076ULL, 0x22B1832F064A32A9ULL, 
            0xFC33C854E4AF6DC6ULL, 0x178BAC3A48357EC0ULL, 0xC081B1191371F39EULL, 0xCF26CCEC11A0525FULL, 
            0xE0416177348FC24DULL, 0x3AFBDD9CC5EFCEC5ULL, 0x8F587824295EE8D6ULL, 0x41DE63D41B510CABULL, 
            0xB8D90C7DEECCEF59ULL, 0x6C40FC89E1B58A5AULL, 0xB89F1970A2EEC871ULL, 0x8881E3224C1767BAULL, 
            0x716655ADF4D19546ULL, 0x90F10D3939C45CF7ULL, 0xD4A6778EFC5EFC08ULL, 0x09DF71D4BD0C2B1BULL, 
            0x3596E2A8211E1B84ULL, 0xE1D475A813943FA3ULL, 0x1F4D8C56A8942304ULL, 0xFA367E38C4702483ULL, 
            0xB7972704EDE23ACDULL, 0x042B8496341E3391ULL, 0xCDD4E5C9863D4041ULL, 0xBC9340CD41CE3D97ULL
        },
        {
            0xAEA41D4E5ED1F548ULL, 0xCDA1C6374464D554ULL, 0xF3DBBDC4DC01E4AAULL, 0xDF1305AB16116D7CULL, 
            0xABFC8A6EA4C3CFD2ULL, 0x8086657249B3E64BULL, 0xA1FDEB6C8E5784F8ULL, 0x2BDB7DEEE788D23AULL, 
            0xB5CF0781F8271294ULL, 0x1E8E327D5E358E61ULL, 0xC0F1E7E98F85B56CULL, 0x7E54504E63BD1D76ULL, 
            0xDBF6EDBC755EC312ULL, 0x6F81A33B7FBAB56FULL, 0x937B6442AAA19BCCULL, 0x03B6036E167008AAULL, 
            0xF68998525A97B1C0ULL, 0x267A76035EAA3995ULL, 0x9C4FF3ABE666F446ULL, 0xC56097EE595550C0ULL, 
            0x5F6738A886BD1ECDULL, 0x9EA702CED525681CULL, 0xD8078A1BFDB3FA1DULL, 0x2F1D09D5D86FD682ULL, 
            0x839B0DCFDA6B89AFULL, 0x50F925B2653856FFULL, 0xD425907B8BB8F457ULL, 0xF161BADC6E1CE3E0ULL, 
            0x85D8592F120C6D2CULL, 0x0DF5C133C3A84CD8ULL, 0x04CF95EA4960CD25ULL, 0x71A823F3B34E866FULL
        },
        {
            0xDE77B47E023C4F96ULL, 0x1411EF04C9D40365ULL, 0x9BC94FC05187A656ULL, 0x38DAD59090D2C0CAULL, 
            0x1E90EAB563A9CADBULL, 0x3026F0BFC9E452F3ULL, 0xDC694D22D06C4E2FULL, 0x44F6D6F941BFD374ULL, 
            0x3BA48E74C6EBC701ULL, 0x12ABD08F8C36B2E4ULL, 0xFA5FCA76719E5C8AULL, 0x1AD20D963348EB44ULL, 
            0xE9E19CA125669134ULL, 0xAADDD819C5295C32ULL, 0x68F5AB4D95D6D4E9ULL, 0x69AB96641F40CB0AULL, 
            0xD489D77B05C41A5FULL, 0xC0F9F019381636B3ULL, 0x738A38593E345EFCULL, 0xD604994156A5E331ULL, 
            0x56CC47CA5C8458FFULL, 0xFD80327B239EE676ULL, 0x09A64D4DDFA3AB1AULL, 0x9115C2C5D4663B49ULL, 
            0xBA78B2F052C44EDDULL, 0x360F36A5A5D60F2FULL, 0x4B9AFA1EF2E4F7F4ULL, 0xF4A4B5B94B8E70A8ULL, 
            0x54D4431A10733426ULL, 0x4EA32F17C223FD88ULL, 0x7F166D8715BDA6F2ULL, 0x0C113DAB19C35D4AULL
        },
        {
            0xF94F2EF804B5D137ULL, 0xDC49679A41B52F83ULL, 0xDF12DC54DC502171ULL, 0xA7742AACBAC52D09ULL, 
            0x7D75A31A9AD07F4DULL, 0xBF055CB7CE00171FULL, 0xB784AF5A5719C44FULL, 0x871289DD3DEF15D7ULL, 
            0x0227EE571ABD9EDCULL, 0x090352F455CC8C7CULL, 0x7A34F453E28C07B0ULL, 0xA6CB529228759CB2ULL, 
            0x39259AD7C53A8973ULL, 0x514DBDFF46180581ULL, 0xBDA5828B19229D3FULL, 0x12B86BC88B4BF41EULL, 
            0xE24153E979C40A91ULL, 0x3BC201A255E6684AULL, 0x2E0ACFD0C633D4B2ULL, 0x891E1321E9B7941EULL, 
            0xF4E0B729F1194A94ULL, 0xDE4D17151A49EA2AULL, 0xF711836B846E2C5CULL, 0x678133F957891433ULL, 
            0xF4C1DBD91EE5EA06ULL, 0x53722ECF672A45CDULL, 0x4A6FF824CE11FE0AULL, 0xA45410627629FC52ULL, 
            0x31FCF220F21514F7ULL, 0xFE7F58BF61F262CFULL, 0xB91313CA6B7CDA6FULL, 0x32DE3CE3B3069EA3ULL
        },
        {
            0x6E779C9BBFC97367ULL, 0xC4278C8C36E84F0EULL, 0x49530296C76FB81BULL, 0x1EB21A59E319F75DULL, 
            0xBACDA7EAD92CB244ULL, 0x125B2E3526731897ULL, 0xC0D4E1510E7B7FC0ULL, 0xF5B5652F30484FCFULL, 
            0xF0CBD29DFD053F66ULL, 0xAAD46106990CE91AULL, 0x7B29960AB428FDE2ULL, 0x672FD4406A353271ULL, 
            0x95E677C37FE2B94FULL, 0xF6836D40857E9737ULL, 0x3B9C6FD8702BD1B1ULL, 0xD7091BC4F51D749EULL, 
            0x91A7238AA27B7EF8ULL, 0xBDA8A9E7CCEA2D81ULL, 0x154564469FA0D6AFULL, 0x12848EBC73BE6888ULL, 
            0x77C1D462B2AB5727ULL, 0xAFD2ECB5946B87DCULL, 0x8859914A9DF51A60ULL, 0x51A869561A1FD097ULL, 
            0x4B24398B245960BDULL, 0x54D32184B2EA07A9ULL, 0x0C271B41C63D1FEDULL, 0x964A1EC65C7ACA01ULL, 
            0x5F5245107D1DC4D3ULL, 0xD440CB45F2AFEF8AULL, 0x1F9F2DF0281D42B5ULL, 0x39E934D2936CB56AULL
        }
    },
    {
        {
            0xAB3264E97CF0B4D6ULL, 0xDFC24BAF640F330AULL, 0xF7B06F5F3D75484EULL, 0x66B511ED366CA68AULL, 
            0x43BE7E29FACCA691ULL, 0x0D3F2F98C2B0FC6AULL, 0x95118EDDEAF151B7ULL, 0x510DD1DC63313058ULL, 
            0x26B4EC532CF829F1ULL, 0x0F0E4AF9E594DDABULL, 0x2A794E6588D6AAB2ULL, 0x708C36408E6F8C7CULL, 
            0x6FAB462796F50E43ULL, 0x46F1EE56F8066FFDULL, 0x07C8560B4409F8F2ULL, 0xCC15610A23004B5FULL, 
            0x9768C19AFE95D415ULL, 0xF1CBDA28F5AB0FF1ULL, 0x86662A2218BF754EULL, 0x68BD5FD43FCABA80ULL, 
            0x16148F5EF2B611CCULL, 0xADCC61484E5D77A7ULL, 0xBC887EDA261E2E86ULL, 0x22193D90FCF8B11FULL, 
            0xF5728BC28FE0F6F7ULL, 0x11610DD641EB6AE5ULL, 0x99B0323C56B28181ULL, 0xF86496A70360EEE6ULL, 
            0xF97C48FF7A1F3760ULL, 0x7E177AA79A9E66FDULL, 0xFF8815BB40D04440ULL, 0xF41FC777AEC97F84ULL
        },
        {
            0xCD372DE81FE6D769ULL, 0x5E4875DEDA6F978FULL, 0xCA42DCE196B610D8ULL, 0x1595BCC8F43E0AD1ULL, 
            0x2573E30826B8AFB2ULL, 0x6DAB0FF189C3F12BULL, 0x53F0FB7A065D4DC7ULL, 0xA3778306EB7761FEULL, 
            0xC4637DF6C79E194BULL, 0x79A71D0E43801228ULL, 0x6CA8919872FA8B92ULL, 0x684F4855DF14439EULL, 
            0xF03DFB191AB41C91ULL, 0xDD2FA31C372FE233ULL, 0xF94121C6E8B012A3ULL, 0xF441549ACE58CE61ULL, 
            0x63C7354A66C2FE5DULL, 0x3A1A903D022961EFULL, 0x2C88355F044E789CULL, 0x62B0B3B6AD0E1AC0ULL, 
            0x5A7851FB0B64D0F8ULL, 0x33B0509030843421ULL, 0x0D86C8A7E5E7E4C4ULL, 0x0FBBE754677158F8ULL, 
            0x922648A81F904E05ULL, 0xCA8068E875EB6966ULL, 0x928C0DB260851158ULL, 0x12C9BEB7698613E2ULL, 
            0xA9F6B7658701DFB4ULL, 0x775430906DA23921ULL, 0xB9D41AB1F40FD8DFULL, 0x14A98CC1A198998EULL
        },
        {
            0x641A73C70FC12788ULL, 0x7EE30C44756F0615ULL, 0xB809CA6D15A4F4C2ULL, 0xFA04EC32CDA6FACBULL, 
            0xF3DB74D86590BB3BULL, 0x2497061A0A51F2FAULL, 0x3A0CC7AA4E9EE584ULL, 0xD849F05512CF6897ULL, 
            0x7638040C556A0DCAULL, 0x2042424623A00890ULL, 0x442C737A467442DCULL, 0x8304DF6B7331B2DBULL, 
            0x0C16984E270CB2BEULL, 0x0241AD854ECF34E9ULL, 0x4A02E9C88165E62FULL, 0xA893039C709816A4ULL, 
            0xBD8CD331D64EB30CULL, 0x10E8A4B82F388D4FULL, 0x0254CF15C7C7AF4EULL, 0xBAC487DE4356AB06ULL, 
            0xF0B539DE14D239C6ULL, 0x5F5A8259CBEC9437ULL, 0x0CFC0BD53475B626ULL, 0xB9DD4083E28020A5ULL, 
            0x232EBA70B326AEF9ULL, 0x9DA0F4379CD33F0EULL, 0xCE2092805840F575ULL, 0x824F6EA33C5156ABULL, 
            0x14D6337226493B7BULL, 0x8E274D902F70D018ULL, 0x798E97C5C5171DCBULL, 0x3707FC87A2D1C5BBULL
        },
        {
            0x8252A7FA628BD698ULL, 0xA4F70D8768B41AC7ULL, 0x22D5E703751A1B56ULL, 0x78AAD39A0D4E8820ULL, 
            0x29DD3517FA950EADULL, 0xAFC01F563FC5E6F1ULL, 0xB8060FC4166B5DF9ULL, 0x3D698E56A331FBD4ULL, 
            0xFDC5C779C50F8479ULL, 0xEEC5B01E5D9E9039ULL, 0xA5D8FAB04FBC9DF3ULL, 0xF56D942CA0A6F000ULL, 
            0xBAD2879C408454E2ULL, 0x87223CF7E3139068ULL, 0x44D1252F248B5003ULL, 0xF9F19FC94E9B0931ULL, 
            0xB7D2B188E8E1ACE4ULL, 0x1AEF3D631509089AULL, 0x3A7CFBE7118236A4ULL, 0x4C1C9FE7E52DBDCAULL, 
            0x452C0B3F4D9C5C8BULL, 0xA8427FA0A35A0C03ULL, 0xD7C73D074450BB39ULL, 0x25AFCD7C31D6E90CULL, 
            0xA32446EC54532120ULL, 0x50D166D18E591DB5ULL, 0x686F79A140721CA1ULL, 0x8417C98B326F2A57ULL, 
            0xCFB40F1ECAD06A75ULL, 0x04FD65E6F511E12DULL, 0x84A67731C4D4422DULL, 0x3D70BA1003C92E69ULL
        },
        {
            0xD5697FC4D1A80726ULL, 0x90057364DE7A263FULL, 0x66B72E83B3F84185ULL, 0x355FBCF25CCAD27CULL, 
            0x7AD20F5882A830BAULL, 0x087A2DFD9578172CULL, 0x963FA7CBCE0DA4F1ULL, 0x67CF9D3DA9AE3262ULL, 
            0xB8B197BB711BFBB8ULL, 0x9048BC836B04D0BAULL, 0xC4F84A10A470A476ULL, 0xB4E30B94AA24E9D3ULL, 
            0x1CC272EBE4280EEDULL, 0x348E403D4628ED24ULL, 0x1E787350B12AAC97ULL, 0xC52AC7B695E17AECULL, 
            0xBF72F37C4B4BB0F2ULL, 0x6444ECFE6659B230ULL, 0x8E641A96728B4576ULL, 0x3D57DAE5F8B65DC7ULL, 
            0xEB6BC11A05C98F6AULL, 0xA818540E8C999B9FULL, 0x8234E68B93B804C4ULL, 0xCA56F6CE615D162DULL, 
            0x5C43DD8FBB120A12ULL, 0x837CCCAEA4BA0721ULL, 0x9E2F5E7FDA9E077CULL, 0x987780DE5C4D9F28ULL, 
            0x465E876869E5F9FFULL, 0x7CBADA2CE9C700F0ULL, 0x8F3A05B361922372ULL, 0xC9A176FAF5F5E266ULL
        },
        {
            0xD8067777067C0F59ULL, 0x3B5216F9F79E5F24ULL, 0x10EB6CC75CEBE959ULL, 0xFD06144153C90A2DULL, 
            0x7AAE286E7502B79AULL, 0x07291E9EE9DFB55CULL, 0xA51F536AC3BFDBA1ULL, 0xA4C57C5DEF6B33EAULL, 
            0x593E80288541BC72ULL, 0x8B89F0A0C310B122ULL, 0x61D98E2C88E57CBAULL, 0xE4A6214528A86633ULL, 
            0x135396AAF001B09AULL, 0x43813B433F6533FDULL, 0xDCD3BE6DB717A17BULL, 0xCD58843D88D71309ULL, 
            0xE0DE33A86EE53304ULL, 0xD76C7B94555DF215ULL, 0xF6DA4306C90F7F2BULL, 0xF1D5A3763A51C502ULL, 
            0x38AB22FAFA0B96B7ULL, 0x23DACBD347425CB0ULL, 0xF6005A5C9654ECB5ULL, 0x83732D077328522FULL, 
            0x9A63F3BB9073ADF6ULL, 0xB4D6FE47279AE1AEULL, 0xE5AA32D1E321CD59ULL, 0x8E04CC94BD403D72ULL, 
            0x14DD30316B668794ULL, 0x993D44A30947F87BULL, 0xF93F49B59BE059ECULL, 0x89B76ED555CFA5BCULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseEConstants = {
    0x5835E98E3ED7180CULL,
    0xB331D47FC5E26073ULL,
    0x1A5D5D3FEEBB42C5ULL,
    0x5835E98E3ED7180CULL,
    0xB331D47FC5E26073ULL,
    0x1A5D5D3FEEBB42C5ULL,
    0x83631C4BE1C0F670ULL,
    0x4F6DC149A4D19EBEULL,
    0xA3,
    0xF8,
    0xD2,
    0x54,
    0xFB,
    0xF3,
    0xA0,
    0xEF
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseFSalts = {
    {
        {
            0xB75E3285E58233DAULL, 0xA8FB6217960A33B3ULL, 0x31A272CCCD52E31AULL, 0x585081CD7AF1777AULL, 
            0x80B816BFBFEE9998ULL, 0x7F19B779C6E218BAULL, 0xC08C7AB75501896CULL, 0x006C1112B6E44AA5ULL, 
            0x5F9D6D2DC34CCA35ULL, 0xF09FA1CCBEF0B61EULL, 0x80A446606AE99E7FULL, 0xBFF9EE1C2DD5D7DFULL, 
            0x9C67F77D878D1E4BULL, 0xA42E88FEC757B2BEULL, 0x9C137274510A0F14ULL, 0x88A74941A0D3DFC2ULL, 
            0xBBF16BFCAC2F0E1CULL, 0x018AA2721CD12CFCULL, 0x034E73C619369360ULL, 0x305D65D6CC67C2F9ULL, 
            0xC70413B1E858EE9FULL, 0xD944A30925F3ABB4ULL, 0xA9C8C3E67D248F7DULL, 0x279DD6203676C017ULL, 
            0x350F122DC801B167ULL, 0x306B6E085DFDA56DULL, 0x357DC2913D9E0CD8ULL, 0xAB8CA31D59F88608ULL, 
            0x1B4EDA365F993EC1ULL, 0x0D9BF8A483CCD81BULL, 0x5616C93733BCFC84ULL, 0xA8E333D5ABCD5EE5ULL
        },
        {
            0xFB76C88CCDC003BBULL, 0x054C7E3BF7A474A1ULL, 0x9FEA71D90EA64C39ULL, 0x021B58DAB2B971C5ULL, 
            0x3C8396CCDFB93273ULL, 0xF5E4D94569B0F033ULL, 0x6D97DC74AAA88EB6ULL, 0x577E8B9D02ADE3FBULL, 
            0x69D332A753404411ULL, 0xBC25546E35C968DEULL, 0xDC66DCCF410F7D19ULL, 0xA79921A710DAF916ULL, 
            0x0958EDA144D7BC10ULL, 0xD4482530F24F1CD3ULL, 0xA24FF5836BD39430ULL, 0x33D99F01CF90FD28ULL, 
            0x29C1EB9559667EE8ULL, 0x71AA6305062DC361ULL, 0x20610CBD2B3CE229ULL, 0x6B0439464425FB92ULL, 
            0x82C8F983089027D3ULL, 0x0F2A76B486827795ULL, 0xB259CE64A150FC59ULL, 0x604FD355E05E3D17ULL, 
            0x5F0D20A7857FE6B7ULL, 0xC7D06A013157E618ULL, 0xD0161231B1A56558ULL, 0xBB98A67A48BD8984ULL, 
            0x7F5ED6713FC1FD55ULL, 0x6CCE22363E3E0BEAULL, 0x0A3EC788A5DAFA5AULL, 0x4A4B9324FDEE7E92ULL
        },
        {
            0x14AC2E945B0A0F5CULL, 0xF15B4E5A8998BA87ULL, 0xCF8181665FFBB5BAULL, 0x573D6036739CFA0CULL, 
            0xDF571FAF071FB6BEULL, 0x9A4CC816B6EF6695ULL, 0x26C660BB38955C50ULL, 0x1C39A1A66D9DC546ULL, 
            0xDFC2027F6E496C08ULL, 0xB5408CD3F0814E13ULL, 0x6D6EAA75246BD6F8ULL, 0x32B5F8B7E3810F3CULL, 
            0xE3382943D038DFD2ULL, 0xC175FB0378583B1BULL, 0xBA29A892B1784A5AULL, 0x7425BD089A1078ECULL, 
            0xBF81D51C6408A6F7ULL, 0x9824124169925008ULL, 0x3035C69E1ED3C29AULL, 0x1D829C3F29862A5FULL, 
            0xE20EF442591E4D6EULL, 0xCBFE71818D5A0F30ULL, 0xD242F5A6DF638ECCULL, 0x35A26991E491285CULL, 
            0x8F8692DA91A1E519ULL, 0xEF28DF41E1D415B2ULL, 0x717330C3947D3462ULL, 0xA44A616CC5F0E629ULL, 
            0x0E552622C8EDF3BAULL, 0x6F2041D726551BC2ULL, 0xFFD22FE5518FB932ULL, 0xA95E343C5F7FC259ULL
        },
        {
            0x792DB13B729AC765ULL, 0xE471B8612F5F350AULL, 0xDBB7ED66F88FAE42ULL, 0x8918D0963D7DF53FULL, 
            0xA0873E3374463B30ULL, 0xAE3DF8945BF97B8FULL, 0x97AD867626044965ULL, 0x14572B4B5EAD5FEBULL, 
            0x63F70221C868990BULL, 0x3D268C1A41E54CE7ULL, 0xDDF1F36801F969CCULL, 0x5FC48CD48471FB47ULL, 
            0xDEF50B945493B20DULL, 0x56D010356E53B18CULL, 0xFBE7CF9D603006B8ULL, 0x0CA9564A6E020C28ULL, 
            0x6C61BC828DC52D43ULL, 0x79BF43655A885B2EULL, 0xC09ED328B636951AULL, 0xD55086FD911516A8ULL, 
            0x5BB25E7A44F6730CULL, 0x50288CE396BC163BULL, 0x1D15067B35672133ULL, 0xA339616DD91C12A4ULL, 
            0x62EB7F0685379F30ULL, 0x3EAE6FC0633687A4ULL, 0x1CA51A30CDAC2D32ULL, 0xC8CE7FDDEDA19932ULL, 
            0x4CD3259BEB6EDD2AULL, 0xCE6F9134FCFA14A2ULL, 0xADEAA3AA85C8D5D6ULL, 0x3ACB8EADDC345B8AULL
        },
        {
            0xFAAA99401C48E321ULL, 0x5E4D921C4EF6CE88ULL, 0x7285F235A234A312ULL, 0x667BFF68BA3FB41FULL, 
            0x2EF7CFBE8EDD7F5DULL, 0xA77BC3C2B2ADEBCBULL, 0x49F22DD801AD46D4ULL, 0x7CD4A60AE1E199A8ULL, 
            0x6ED16E59CFE19DA2ULL, 0x61955594B19E0096ULL, 0x3174EEF6A2F37CDCULL, 0x7EC20B44B3C2388EULL, 
            0x254F402BC8FF5AEAULL, 0x1FB54E2748817E2EULL, 0x2365E25CAC69C35BULL, 0x5D54C953AABFD19DULL, 
            0xEF08DD4B3A657328ULL, 0xA2B35F51C06BA221ULL, 0x25E16CAB8097A484ULL, 0xD0333FB908A9E7A0ULL, 
            0x65726D03F464B540ULL, 0xF8B02CEC6660E4CEULL, 0xE24B645DB993800EULL, 0xC903561C93563238ULL, 
            0x848752838D5B5C8DULL, 0xBEA7509F75EC4470ULL, 0x21B08ECF44980CEDULL, 0xA6515EC6ED9C862CULL, 
            0xA716BF1D38853051ULL, 0x74056D7B545EC31BULL, 0xD124201ACC114776ULL, 0x99EB85B2D6C221FFULL
        },
        {
            0xB05FC51F81AD4A98ULL, 0x701F864B953E8277ULL, 0x6FAEB9F8C2F92F14ULL, 0xEBF241ADDA5E2A73ULL, 
            0xB9C8FF378A7633ACULL, 0x0549571AA12F04BEULL, 0x1BB3EEC41D00FA92ULL, 0x6C25DCF55C46621BULL, 
            0x8C0373377AB31FCEULL, 0x9E8E5E0B12BCAB02ULL, 0x5D3AE6A668F27D05ULL, 0xAFF525EADC0384C9ULL, 
            0xF8AA1D81A7AAA20DULL, 0x09D1CEEBE15E466AULL, 0x76BD757E214CFE35ULL, 0x4AE8BBB00F43C490ULL, 
            0x9649C37F0EB4CAB8ULL, 0xCCE2A874E62A2F67ULL, 0x73F798514B89173BULL, 0x7D63F1AED809D3B1ULL, 
            0xF209C7B703D21B3BULL, 0x453578D019672779ULL, 0x949BDB3A0EDF873AULL, 0x1B8492BBA2BDE74EULL, 
            0xD1C7D807BD0C77CDULL, 0x33C341BA723BAE8BULL, 0x5DB62A182C132AF8ULL, 0xB00A6E9F4A0E7B8BULL, 
            0x051822346CC30F5AULL, 0xC7E55B064253C2D0ULL, 0x84ED6179E3098F83ULL, 0x6EC7B99DF8CD6CB0ULL
        }
    },
    {
        {
            0x73740DBB68E40A3DULL, 0xF983BA6B55848221ULL, 0xF98688F937134479ULL, 0xD65A0FBCDCA4EECEULL, 
            0xD48CD02F3267C0DEULL, 0x08650239C164C046ULL, 0xC578CDA2E7EE99B1ULL, 0x3B445937BD3A1B65ULL, 
            0x6D8BAA0E474224ECULL, 0xC0AE931F6AAD293DULL, 0x81059A0AF0020BC2ULL, 0x8FACEA653C5C26EDULL, 
            0x9F691720C777FA8DULL, 0x95ADD3E90F449583ULL, 0x41BC6E12B5C3C9B7ULL, 0xA710B7F16F147808ULL, 
            0x50799D6958E41D75ULL, 0x627AE07DB0CDBC81ULL, 0x450881932E0185A6ULL, 0x70CE8967530B0DEDULL, 
            0x2304A8040B848E67ULL, 0x370353ECFF21E757ULL, 0x91275A0861026744ULL, 0xAD041B1EA7AE2428ULL, 
            0x17ABFBE416555C75ULL, 0x885C5D6F579E7CEAULL, 0x535E8E2A1B3543F8ULL, 0x1804B94A1D41736BULL, 
            0xC88912EED64527A9ULL, 0x4792F6E75B262A11ULL, 0x185C6A77663B63BCULL, 0x555770C2B74F54C7ULL
        },
        {
            0x6CEB065C0B1B4ABFULL, 0x995BA49B32E28C72ULL, 0x1B2D0B752A9CDFD3ULL, 0x2C30520DBB9AB5C7ULL, 
            0x8C79AC37C348C179ULL, 0xE1ED43F691DE29FAULL, 0x7F768672B0BE570FULL, 0x2F675E04D245E378ULL, 
            0x853F908D7BEA1542ULL, 0xD91FD4313A07EEFFULL, 0xE916553DE2306B97ULL, 0x63E6754F0EC9B70BULL, 
            0x054685E9B0A8154CULL, 0xF19F2916ABA9F50DULL, 0xCA75B7D5EBD113D5ULL, 0xD59D17717D1BE3B1ULL, 
            0x68315E00581D8845ULL, 0xD5F9607D9ECAA43DULL, 0xB1CB95F2EF0836F2ULL, 0x070DD04925BD2A58ULL, 
            0x43070EF28B8A0563ULL, 0xA98388C2B0E09183ULL, 0xCF474FEF8C798998ULL, 0xCF2C11AB716D3B6AULL, 
            0xE0A8505D06EB5968ULL, 0x395085E702E2259FULL, 0x26F4C1ED0E536B84ULL, 0x4EB62104512155A7ULL, 
            0x0F61F2335D1D602AULL, 0x9436FCF2725506CBULL, 0xED6E07A02EC99951ULL, 0x97DD923F771D43B9ULL
        },
        {
            0xBE26ADC03082B3E2ULL, 0x96DDD68054075E04ULL, 0x03B639091D4F73B9ULL, 0xC40A501AA740D21BULL, 
            0x389A5B6974DBBA51ULL, 0x7718B7CEF4598A58ULL, 0x88DAE30E9EDA86EAULL, 0x239ED4B2C2C70975ULL, 
            0x21084D0C7CB936D2ULL, 0x8D88A52B9B5733D7ULL, 0xC7BD631429B39ABAULL, 0x3CCECC632C3B9725ULL, 
            0xA5C04C3704B83047ULL, 0xB19AB89FF2863502ULL, 0xD10BCBE87BDFE1C6ULL, 0xDA494D380F53F43BULL, 
            0x284FCCF5852D7168ULL, 0x6F3765D60DB7D0D3ULL, 0xE2DA9B88F8F9F159ULL, 0xFDC985F61B9F50C5ULL, 
            0x89F44B2386EA22E3ULL, 0x6276342C4E2ACFA7ULL, 0xF914927BABDD8216ULL, 0x28B298F346D737E9ULL, 
            0x9DCD688F61BFD59AULL, 0x9B9294625260F96DULL, 0xAFBAD23155ADCB05ULL, 0xDAA2878B138B646EULL, 
            0xA99A2BB8114C9B6CULL, 0x48B62145884B2603ULL, 0x57BCF18E4CCDF791ULL, 0xE7A7AE30449323CDULL
        },
        {
            0xF545BAA3DCCD0B3CULL, 0x336DF1FCCDAA9996ULL, 0xDB13E0491AAA3817ULL, 0xD6E1287B5A037FA5ULL, 
            0xA551E8E66757F66EULL, 0x5D422F14FAA55029ULL, 0x3F379FD37E234F2DULL, 0x8B4A5F013297A096ULL, 
            0x3F09C612FC204766ULL, 0x0C464FE87B2E15A4ULL, 0x800814726A575D56ULL, 0xF009C571BBB9CDE3ULL, 
            0x570669BDE80253F5ULL, 0xE58EE99BBCCD8F15ULL, 0x6ACA17AD8FD2E54CULL, 0x0DE8B3056BE5481FULL, 
            0x4884065B24E0F2BFULL, 0x108B3C33177404CBULL, 0x69BBBEA6763860B2ULL, 0x7DE48D5A9B06B367ULL, 
            0xBA8FA46895618A39ULL, 0x7ADDEFF3F45ABA6EULL, 0xDF10801480BEE0D3ULL, 0x5D925A48F0144403ULL, 
            0x1B05473FE09DE791ULL, 0xE6FEA85F299F7C76ULL, 0x6A2A985A1B2EA9D7ULL, 0xC2A1EAE1D6DC11BCULL, 
            0x0666893136ECEEC9ULL, 0x1BB6BA35894EECE9ULL, 0x066F24925E131DD9ULL, 0x9C7936A075F7F643ULL
        },
        {
            0x898C5747819986B3ULL, 0xD47243842CAF64BFULL, 0x6D60273A954A536CULL, 0x0B9321184D2E729BULL, 
            0x06426A6EEA42809EULL, 0x3149D17E83B11AD5ULL, 0xCBD65D6F2E2EE8D5ULL, 0xD9B05D8A1EE61D72ULL, 
            0xAE12FD01A2E5D9AFULL, 0x0E50979101788BD9ULL, 0x52A57F9C5790239EULL, 0xAEEBAE51AFB955C5ULL, 
            0x666E245AF4397CD0ULL, 0xEA7B0C057BDC8719ULL, 0x5ECD47CF2B8AB1F0ULL, 0xC9C4B1406EDE5C7EULL, 
            0x22BD20B324B8ACFBULL, 0x795D0C2E29A38BAFULL, 0x72E2925C75544A75ULL, 0x4C10EB52C77962C3ULL, 
            0x85527D124A14536EULL, 0xF2AD52441181C04FULL, 0x1DDE2376A24A236BULL, 0x608CE6824BB36E4DULL, 
            0xC98DA787A426AFA2ULL, 0x76B3938534B4B290ULL, 0xC1D957D70F25871CULL, 0x896D17D97F1CB982ULL, 
            0x78460773CBDD5DC7ULL, 0xD0E4DFD17179C8F5ULL, 0xE5F5E30FF16461E2ULL, 0x77CD3BE7C9DAC4FBULL
        },
        {
            0x8279BE9ED999D2ABULL, 0xE02EE67CCEAF77B5ULL, 0x34D1D46F3235E627ULL, 0xE2D39C878B88EDB0ULL, 
            0xEB8AB85543F3865DULL, 0x80A8D0F256E716E4ULL, 0xAD1027187C2CC3E8ULL, 0xBB648EA1E8DA3EE0ULL, 
            0x22151D100FE4D4A4ULL, 0xFA1239611D47532FULL, 0xB4223269C80E975CULL, 0xADF067F93510CC80ULL, 
            0x041B5539B5607CCEULL, 0x7B7A53313978989FULL, 0xF94575BF6EEE52C0ULL, 0x135B77B4E33B5B42ULL, 
            0xC502271E4B043EF7ULL, 0x8CAEBEB75F7863F3ULL, 0x9E3BAD71E12E52B4ULL, 0x46FF74A89140CD44ULL, 
            0x3DB435A42AC60173ULL, 0x31C9677CB06DCFE1ULL, 0xD460E55F5BB2F62BULL, 0xEB5F5BDF9D6FAAC6ULL, 
            0x43DE0746930EA367ULL, 0x2F413B6E2007DF87ULL, 0xB7C01604306BA441ULL, 0x25F150BA10BA213BULL, 
            0xBA1176C0CE1E29CAULL, 0x535F34E08A4E1C9AULL, 0x69C3206FC2976F5CULL, 0xA317A4E7960BDAE9ULL
        }
    },
    {
        {
            0x79F0F7ABBA349881ULL, 0x5AC060736BEF2292ULL, 0x36221E2EB1149965ULL, 0x2E73C432BABB93B1ULL, 
            0xD1EE233457A59A54ULL, 0x3F9B884312C2EB23ULL, 0x890B7923E8649C2BULL, 0xBECF46313FDEEFD1ULL, 
            0x615042330A778D02ULL, 0xFA52319BD4E756EBULL, 0xB3ED8630262F67BFULL, 0x96A7F62BAE5DA3F5ULL, 
            0xE90BE3A77CEDBB09ULL, 0x692AB5DDC673AF94ULL, 0xC3E0FD5E56EE247CULL, 0x747F2B7B829CBBD5ULL, 
            0x96310F7EEA546D10ULL, 0x8D630965FF690681ULL, 0x5C0C788F210B34B7ULL, 0x98088E80C94D2ABBULL, 
            0x21003CE35F48579FULL, 0x09F8EF6DF3ED4062ULL, 0x11AC988A46F9B866ULL, 0xF5CC6DF4302038B5ULL, 
            0xFDCAABA218111B60ULL, 0xD126FE935DCA5647ULL, 0x382F63757767C03CULL, 0xF4ED145A2D69A653ULL, 
            0x19940C87BD02BF1BULL, 0xAE030F69E7AFCFBDULL, 0x7786E46A3C164DA2ULL, 0x67783D544B37255DULL
        },
        {
            0x32E79112E6FF6908ULL, 0xAAE92A25EA3B83F5ULL, 0xDF68B09E02D673C9ULL, 0x07BFCB45656DAA57ULL, 
            0x839928B2E7D4D7BAULL, 0x26F4775A6E594A56ULL, 0x6D0741E5673332C4ULL, 0x613B09B52783080CULL, 
            0xEA3BFC99281E2201ULL, 0xF1D829B02B6AB06DULL, 0xEE0DC2F817557266ULL, 0xEE8BA05A97006FBCULL, 
            0xE04D639C30ED16D7ULL, 0x567F1F00B41685A6ULL, 0x6F6AFFB1133EA9EFULL, 0x8A28CFE78F809362ULL, 
            0x58B41596A2D5C11BULL, 0xBE3842F03672D1ECULL, 0xCCCB6ACC4FB1621CULL, 0x8BA71178D5169959ULL, 
            0x09F838D8876FA60DULL, 0xBF44B280353F0217ULL, 0xF32679059DE56411ULL, 0x3C34A2CCF15F9C3FULL, 
            0x4CA3947839CF6B5DULL, 0x8F97160F51E8DE4EULL, 0xBEAAA1B0B618029EULL, 0xD90A84C23C5EEC8AULL, 
            0xB53B4BB0F32B94B0ULL, 0x63628577F95967ABULL, 0x2B1E25E3CD59E1EBULL, 0xC668D8EC92C772B5ULL
        },
        {
            0x96252FF39EAB635CULL, 0x1B660C2C727249BEULL, 0x47BAC13B83425BA3ULL, 0x2EB18514ADDBFD4EULL, 
            0x797B432F389E1448ULL, 0x046D6B6714CA35FBULL, 0x6FEF598C3E291E8FULL, 0xFC695C61CDB06779ULL, 
            0xBF514634D802EE96ULL, 0x92653DAE2E6F5D20ULL, 0x05FE9464BAC25BA0ULL, 0x693433CF76C87771ULL, 
            0x8292FDACEEA1DE6EULL, 0xB7CD93048B9AFCAAULL, 0xAE61255AFA5F8FF5ULL, 0x5D6B076089CF1277ULL, 
            0xF8D77C1D2A16907FULL, 0x7E855BD4672C77BEULL, 0xAA388EB4B21DAB8CULL, 0x0A6850F13E8199A7ULL, 
            0xF22C06E441D48B94ULL, 0x241C2CDEE2DF9AA7ULL, 0x89B992E468ACBC29ULL, 0x71004A8F60710D0BULL, 
            0x1E00D727E2016D58ULL, 0x97762077993A3129ULL, 0x83AAF787EC493979ULL, 0xFEAB43797E362325ULL, 
            0x6A4EBC80D9C0344FULL, 0xD6A33BEC92D71D5FULL, 0xE53AC1E8C0047D42ULL, 0x865F29E3B566B23BULL
        },
        {
            0x15BFE054EC8CA301ULL, 0x0B2B65C73FB94CEDULL, 0x62183E928B2F2084ULL, 0x59645D9556FE7FE7ULL, 
            0xC78B73A323D6D4A3ULL, 0xF9C3DB8614E1AAE2ULL, 0xAC3C10836D84A2C4ULL, 0x320476940A747A7DULL, 
            0x16E4352D67C7D491ULL, 0x3D80373129C6D5BDULL, 0x5953741C18802719ULL, 0xDBA1C64ACE5F5BBBULL, 
            0xB8CD5E9C9C4CAC4BULL, 0xB06422EABD07A8B2ULL, 0x2FBC2E96B024EB56ULL, 0x06E319E6F30CD491ULL, 
            0x862109A423B4791DULL, 0xCDC6F00BAF946A5AULL, 0x88294CCB5F743D06ULL, 0x258838768CCE1165ULL, 
            0xCB5B371AB40FD870ULL, 0x864E22474545B117ULL, 0xC66B79A2CAEA2872ULL, 0x8DB10D911A82451EULL, 
            0xBC81479A830FF1ACULL, 0x08B8609F3B316E10ULL, 0xCCA93C88BBE55D73ULL, 0x32EC0F1268C972B8ULL, 
            0x373297568DF5256FULL, 0xB7D65C6D7AC2E78EULL, 0xAE13FE6B78DFB790ULL, 0xB126A327AF110C69ULL
        },
        {
            0xD7356496E4871FBEULL, 0xC36A53F38D5A6F1CULL, 0xD1913B324E37422BULL, 0x4B0C602C4100C099ULL, 
            0x7B1174ABA0F5BD03ULL, 0x14D802CCB05E1881ULL, 0x8253F5BC04058A59ULL, 0xB613C91B926659B3ULL, 
            0xD10B8E3F42A8CB98ULL, 0xC3F36215D172BBFDULL, 0xE66BC7554602B256ULL, 0xA70315DE3AD24919ULL, 
            0x109FF10DE266992CULL, 0x037EEED0C0FF73CCULL, 0x467A0BFC122AF32FULL, 0xBFEABC3D906C513BULL, 
            0x8EA6F069E87EA793ULL, 0xEC2F3163F1ADC4BEULL, 0xE9E0702EA466BD44ULL, 0x5F17309A859E8DDAULL, 
            0x276E20874A0E72B9ULL, 0x5E4F7975B3E5F141ULL, 0x5544AE8081F58B10ULL, 0x4B39CA9B48A4D768ULL, 
            0x691CAEA36FA7243EULL, 0x361DF9F9C06EBDCBULL, 0x22FE501154994B96ULL, 0x3705332CEBF53D57ULL, 
            0xD97363AB51F63378ULL, 0x4002EBB295D3F900ULL, 0xABE9ABC0CBB20FD8ULL, 0x9F32B15B08A820CBULL
        },
        {
            0x864E3003BB2B01D5ULL, 0x334FF1D4C7A2633DULL, 0xBD0ED1541A381EE6ULL, 0xE44F4834D799C509ULL, 
            0x1AFD9110CD0754A5ULL, 0xABB8182E43812059ULL, 0x5EA9F470FE044CC1ULL, 0xE3111279545EAEA2ULL, 
            0x759C8C11F983EE9BULL, 0xCD57A979138537C3ULL, 0x5ACEE91DF5415DAAULL, 0x1B569C93A728DECEULL, 
            0x198B187DE841B282ULL, 0x7EE2FA461B7A1BE3ULL, 0xA0FB97AF9990FFE2ULL, 0x1C991EE17F437780ULL, 
            0x018AA764035C7376ULL, 0x84E9462A25742BCCULL, 0x8A5C67557F81C89EULL, 0x29D7CB8696D5E3CAULL, 
            0x61E31530B3B4F84EULL, 0x2D826129F82EA549ULL, 0x8D722976C32A3CE5ULL, 0x6DFACEC185F60F38ULL, 
            0xB10532FFAC13BAA0ULL, 0xB91A77D85BB9EBD8ULL, 0x591332B90BF46212ULL, 0xEEA58EC18EA83575ULL, 
            0x4C5ED445B0C3A8C5ULL, 0xD1AA836923A45C07ULL, 0xD24597B818227B95ULL, 0xC7FD312C4D7CCDBBULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseFConstants = {
    0x51E2D96BFE678F5FULL,
    0xC78B5AFF47D58EE8ULL,
    0x732010A96FC6A987ULL,
    0x51E2D96BFE678F5FULL,
    0xC78B5AFF47D58EE8ULL,
    0x732010A96FC6A987ULL,
    0x5A16AF47A67F08FAULL,
    0xFDAA8AE0BA9621F2ULL,
    0xA8,
    0x1F,
    0x7A,
    0x48,
    0xCB,
    0x56,
    0x61,
    0x19
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseGSalts = {
    {
        {
            0xA1D05AD52B0E68EFULL, 0xA957DB76199DDC88ULL, 0xBAC08A8300510F3BULL, 0xE20683CCD39CA50FULL, 
            0xAF7C06FF5B57E25BULL, 0x1612381AA1C6DFE3ULL, 0x110344A04A17B2B9ULL, 0x2B36ECF1E594C167ULL, 
            0x9151AE92FBC1233AULL, 0xAEAF1464CCFDDACFULL, 0xE7E9EBFE2D4DEE37ULL, 0x5360E3522E217AB7ULL, 
            0x2C155043B12465CAULL, 0x5120DE86C27C0B9BULL, 0x3C7F39C5B50BD487ULL, 0xD850B2E11F7F2160ULL, 
            0x2CE33356DD6E9B12ULL, 0x2A4A098CA2D033A9ULL, 0x2F8F382644D87B2DULL, 0x5ACA4EA3B1751CC9ULL, 
            0xB4D0CF538EA47339ULL, 0x39512E5B7BEFA147ULL, 0xE6BADBE0A1F2280BULL, 0xB662F0D3600D6B74ULL, 
            0xC52B5D1A60B3D45EULL, 0x668A9BF421B64B7DULL, 0xC3772CE01275AABAULL, 0xC4798E660545C726ULL, 
            0xDDBCCFCC3CB28702ULL, 0x3259DB854202E376ULL, 0x4C8A7763972141F1ULL, 0x78F16AAB27EB5CDDULL
        },
        {
            0xCF0B314A4D98BADBULL, 0xD6799B0C667BCA3CULL, 0x505D6B745775C430ULL, 0x8C4B30D0D6BC1D50ULL, 
            0x13050C49DFB9D57EULL, 0xBF357DCE0DDD08CAULL, 0x9C833FE62D3112ABULL, 0xB0347009C4AEE7C9ULL, 
            0x0BCC1B2E87134691ULL, 0xB2C3B26DD9EAC47AULL, 0x209AD06A59D942A2ULL, 0xCD8A3EAE0A8076D8ULL, 
            0x92C0E41F5686C22CULL, 0x18B6F57ACA296725ULL, 0xAAE327BF87533E90ULL, 0xD82D7BCD529B05E6ULL, 
            0x7B2819AF90883960ULL, 0x39565FD727846948ULL, 0xA199D6390A6C9249ULL, 0xF01246F350B6B91CULL, 
            0xA67904196C8CB470ULL, 0x3AF695466214BD49ULL, 0x5124C3C9759ABA8CULL, 0x581B44CBCBFFAAE0ULL, 
            0xA3D0C6A6DE55D903ULL, 0x20B98676AC0D8183ULL, 0xD590ED0979DA7FF5ULL, 0xD324C6FE85830626ULL, 
            0xB7DA0320FC31D242ULL, 0x944C1214D753DFBBULL, 0xCEF21362E3163208ULL, 0xBAF7FD1D435BBA99ULL
        },
        {
            0x9ADE0BB3DECEB3BCULL, 0x56CB4A5A6D73CFCAULL, 0x50056638A9B89E1CULL, 0x731F084E2454C5E3ULL, 
            0x112B88F0B481F7AFULL, 0x61B30DE996F21FEEULL, 0xCA9D7D48FAE7A603ULL, 0x3B29679CE1A42826ULL, 
            0xA470C795DE8DAB91ULL, 0xDF5EB8484199694CULL, 0x6501B74E90973328ULL, 0xB3BC0EE3081F23D8ULL, 
            0xB727B9EA74A932B2ULL, 0xBE4E4857A63D5345ULL, 0x5005D150104A9EDFULL, 0x3E56ED669B850706ULL, 
            0xE6B2F0C15933B9C9ULL, 0xD4ED73D7AC89E578ULL, 0xACD7E964FB65DBECULL, 0xBC4FE8B81D81AE37ULL, 
            0x8C4DA55CB4EE2249ULL, 0x8A0AD311BB3E746EULL, 0xB8873460BA30B68BULL, 0xB8CEDAE8477EE9A0ULL, 
            0x49BF07C8D06F7E19ULL, 0xEA10610FD7716877ULL, 0xB5A3287CDBC7C03BULL, 0xA040BB41BD880630ULL, 
            0x5860499928F89799ULL, 0x442E230BD96E1033ULL, 0xEEA840D186BA16B5ULL, 0x281FA60842225131ULL
        },
        {
            0x958F4347CD046D5FULL, 0xDB87738A8F1959ADULL, 0xE71A2DEAF2C8CB99ULL, 0x6684A7A158E840FAULL, 
            0xF358EAF590D39C52ULL, 0x423DFB278F2B77E5ULL, 0xD4C90FCD45731083ULL, 0x9CC7CBA3381BB131ULL, 
            0x0DBF2DCD544A4FBCULL, 0x7D917A6F33BC67DAULL, 0x92CE34A78456B5FAULL, 0xB4DDB2F3A63E567BULL, 
            0x7CAC89B451E6353BULL, 0x1AFB5367B4F601B1ULL, 0xAE9F6136BE22C87CULL, 0x37824A5A2B01EF85ULL, 
            0xDC1CA79ABBFC5A44ULL, 0xE2845AA85078D2F4ULL, 0xFA7DC852AEED414AULL, 0xC5A3A2CB74C42E33ULL, 
            0x8460BD87F807040CULL, 0x34975EE38920D2B4ULL, 0xD4BE47DD6DB49A1CULL, 0xE8F2C5DCFCDB812BULL, 
            0xF8032118D2432C9DULL, 0x3F88CF0D77EA8917ULL, 0x5FC1F65C98889BEDULL, 0xEC3548BC306C54CDULL, 
            0xFE1575458AC2F334ULL, 0x4025BAB066A9ABADULL, 0xCF4B6A039C0B2EBCULL, 0xE04CB70F40B29BE8ULL
        },
        {
            0x6055D9F271E7ED3EULL, 0x5C9F1A1380222C5EULL, 0x0424649051D7AE94ULL, 0xE5477315B55A5AA9ULL, 
            0x46E8D0C3AB45099DULL, 0xE251CAB78B66E8BBULL, 0x0EDDA1E2FB7DB259ULL, 0x5B73ACB1FF3A4B7FULL, 
            0x0D1C574F52DD0065ULL, 0x22949599AF3D66D1ULL, 0x826492719E236BE8ULL, 0x2999C1EECF493245ULL, 
            0xC719997369069591ULL, 0x6849DECBD0FAC010ULL, 0x87FB69E6DDDE020BULL, 0x4FED9B679CB7D413ULL, 
            0x11CF4A359467A1FBULL, 0xD628FC016778E656ULL, 0x88336A70A35BDCCBULL, 0xB43911548F5F437BULL, 
            0x75579827C4C50FC1ULL, 0x3F9A424D9E1289E9ULL, 0x0C76986E063AA517ULL, 0xA36B2ABBA4891245ULL, 
            0x639A85453ED761F9ULL, 0x2F017C6F3442068BULL, 0x40A035608641CBBFULL, 0xE7772E1A76B83FF6ULL, 
            0xD0C7D53E466F3E42ULL, 0x33A1E760885899ADULL, 0x7D4C5D8D114E9EE2ULL, 0xBF65B8229C51E265ULL
        },
        {
            0xABEF8F7ACBA29C41ULL, 0x03AD67DBDA8FA6EFULL, 0xB00531ED7E019940ULL, 0x6D21930501F941A6ULL, 
            0x8509F1BCDB79BE10ULL, 0x8821DAB455470FE7ULL, 0xFCD4112B589D2DD9ULL, 0x57AD875DA4A5D4FEULL, 
            0xD80E30BEBFE73810ULL, 0xCC82BDE11733050AULL, 0x541591EB07F03A00ULL, 0x1E21600EA6A5E87AULL, 
            0xC6E02BEE57231346ULL, 0x92C5C595B0903320ULL, 0xD8764651EE4707E7ULL, 0x8FCDAC3BB36A7A1CULL, 
            0xA4E4EA55ABD3D77CULL, 0x614B9A15C05B8285ULL, 0x4272FCF485744650ULL, 0x39C1E078F178DF25ULL, 
            0x733FAA1B4A270B13ULL, 0x276A05731B347136ULL, 0x38405F3B77B1B388ULL, 0x73D1C57746F7B244ULL, 
            0xB7D68856557B9259ULL, 0xE74B21F0A63BF381ULL, 0xBA933AAA2B4369A1ULL, 0xFEAB61399BBEBB22ULL, 
            0x1323A249CBA23D4DULL, 0xF6F06C99CDE8CE6DULL, 0x1E3B3559AC1795E9ULL, 0x41045BA47573FD97ULL
        }
    },
    {
        {
            0x9C9B5246EE289BF9ULL, 0xAE34A401C7BD97DDULL, 0xC0F83B4025070C87ULL, 0x2BC1A19D4DA36085ULL, 
            0xE3A599DA2B6B9971ULL, 0x588031249C717BEAULL, 0xC91B9DC5440E05A9ULL, 0x6E7BF698A45B59ACULL, 
            0xAD7BAD0344816938ULL, 0x9A8A5CFDBCECB333ULL, 0x917458976C24BC23ULL, 0xFCC42FAF48CB397EULL, 
            0x82DD144DD5158954ULL, 0xDA850A4C33D8909FULL, 0x361182BE6460083DULL, 0xB94D92E702864D2EULL, 
            0x65BFBF799118FC78ULL, 0x7B573DA7BC667B3CULL, 0xD833DE73975A93F5ULL, 0xB66486E805C795C1ULL, 
            0x573DA1629AA20073ULL, 0x4F9906A45E116966ULL, 0x4581E3067CD8E166ULL, 0x1407D8E8BD488894ULL, 
            0x389ADCFC29875C1DULL, 0x44D9A5CD906CEE37ULL, 0xBB1088ACBE3A2EFAULL, 0xA7174FA867BBDD00ULL, 
            0xCEDE030E67B44F25ULL, 0x837A4828A9EDF648ULL, 0x806A7B664159018DULL, 0xDBDCB146293BE1E2ULL
        },
        {
            0x2B3D22C89E0F1340ULL, 0xDAEB492AC3C8738CULL, 0x1A88D129BBCAF384ULL, 0xD7C4FB7C9F5C29B3ULL, 
            0x6B96B80268CC1B7EULL, 0x31086A956A508C96ULL, 0x6E43B5B9CE0301F6ULL, 0x8BBB1EBA520D07BFULL, 
            0x2438758E22761D1BULL, 0xFF86ABD3D18344EAULL, 0xCBD0A32DD4D0B2B5ULL, 0xDD923374E0979A19ULL, 
            0xB7EB9FDA3D8E381FULL, 0x56CF90F5DF3A1B18ULL, 0x12CBC043825C2E3AULL, 0x84688BE441D5DC95ULL, 
            0xE008D211BBF55A2AULL, 0x7055D4898AB137E7ULL, 0x1E4667E473CB3337ULL, 0x471B393E5D58FE70ULL, 
            0x276B2398C587A325ULL, 0x5413F4F4AFC7F9BEULL, 0x50CAA7868C263758ULL, 0xE070D92A1378EA15ULL, 
            0xC542BA603587CE8FULL, 0x08F1D9E4BA0DA28CULL, 0x3699D5CA9D4E4369ULL, 0x899A2BF29023BEFDULL, 
            0xB3E56DC7F503DCC5ULL, 0x677A80F3350FF750ULL, 0xA4EA4C2D7E4B1EBAULL, 0x002727E7D46390C9ULL
        },
        {
            0x9C1C43D5502874A8ULL, 0xB6B277FAB46D8217ULL, 0x7C98A39BBEECD171ULL, 0xD2696560CF872A35ULL, 
            0x532F8B3098E2930DULL, 0xFDE393A2DF2D329CULL, 0x6D7C5A47D4D4CB8FULL, 0xE2D49752359DA7F0ULL, 
            0xB46377F24C26A4A5ULL, 0x8AF5902835FB5040ULL, 0x091F67D2BEE5A2E6ULL, 0xE797E0A4E7546B84ULL, 
            0xF21230F6AE8C6B13ULL, 0xE45EEDA7548C2891ULL, 0xA61E020E4D4F0433ULL, 0x4C831124C30FEE40ULL, 
            0x8D7E677FA263C817ULL, 0x669A0388349B0FEDULL, 0xDBC9B318D4058E41ULL, 0x6600C050C2C36040ULL, 
            0xDF03AADCB4582146ULL, 0x30305423C728D149ULL, 0x0840032657F0A823ULL, 0x779A2490025629A8ULL, 
            0xE8B738AF4C7C89E1ULL, 0x58179369274C9301ULL, 0x08A29ABBB543D586ULL, 0x4424AA3E59B1ED73ULL, 
            0x68893904B4BB7C2CULL, 0x7C30C118476FEC86ULL, 0xAD9BF52983C4CE92ULL, 0x0EBEEE51BAF167C9ULL
        },
        {
            0x003AFFAE08321BA5ULL, 0xF394F3F9E0185BEBULL, 0x1BE1B3EAD7430F27ULL, 0x6685BB1568470A4FULL, 
            0x920DFF7DD0A56FDDULL, 0x913F792168CDFFEAULL, 0xE2F649ECA0BCF220ULL, 0x3358EC1B6CA2B973ULL, 
            0x9518364A621AD87EULL, 0x2F6C34E7D8FE263BULL, 0xDB4553548E0CF32DULL, 0x4517FBEFE867D34BULL, 
            0x53743BD9D02B38BDULL, 0x2082CBB287FDEEB8ULL, 0x9592A57475A485B8ULL, 0x05B17651C1A75E26ULL, 
            0xE16574A6DE430A18ULL, 0x15F048F1051B51FAULL, 0xF23ABA2EE8D31099ULL, 0x44920A6DD39C0E61ULL, 
            0x980E9815CBBF4062ULL, 0xAE140114FBFF4F3CULL, 0x10BDD268CD7F5593ULL, 0x0A9C0A400893F4DAULL, 
            0xDA6EF7C1D0F7CC9DULL, 0xEC7D29BBDC5D568AULL, 0xED41F156FD782A92ULL, 0x8A8354ACFA1A0ADBULL, 
            0x63777995E35FA606ULL, 0x19B4289073895852ULL, 0x6327312EF78BCCCCULL, 0x2EFB27C875B1581EULL
        },
        {
            0xFA4525DB7E599B4BULL, 0xF9C5CA896D7D7596ULL, 0x38EC37A976DF1607ULL, 0xC06A719E0806E521ULL, 
            0x8EF69FDB624F5EE7ULL, 0xC6249DD62B8A565BULL, 0x18FC229735D4B21EULL, 0xC8D91EF98A4573FBULL, 
            0xAAE0A4D531998423ULL, 0x426FF9105437C034ULL, 0x563C6183581FC08DULL, 0xAF52B783A98DB4C1ULL, 
            0x5BFB77B879314A34ULL, 0x734AB8174F5184A7ULL, 0xE2FCF23494CBECB6ULL, 0x8FD3BB14DB6C8D7BULL, 
            0xDB547252B17AB26CULL, 0x79E2BCC91FE54ADDULL, 0x7FDF7E6E29E36AD1ULL, 0xA905798E78917E9DULL, 
            0x13B4D67D56377773ULL, 0xFE7E74938E0450AFULL, 0x4C4CAA7A0C673356ULL, 0x3AF8EAC8C4C5DC8BULL, 
            0x2E48D831F32AE7A7ULL, 0x829E5C9149BD770FULL, 0xB73F84B0D5F79483ULL, 0x0310A57B3F2AF1F3ULL, 
            0xEA4D94F0CD566936ULL, 0x5AE512C0513BDBB2ULL, 0xB754DEC70C238F28ULL, 0xC2D07CB8192B52BCULL
        },
        {
            0xC51FD9FF74408B60ULL, 0x5B449D33944A32D0ULL, 0x4DCDE750E663D2F3ULL, 0x875EAB727815259CULL, 
            0x9E2481648A307BCCULL, 0x629F7020D14562E1ULL, 0x9D5DB2FED276E86BULL, 0xEDA9B5DF1B09D988ULL, 
            0x1E436122476524CEULL, 0xFF6F4202919C28D9ULL, 0x225236D576FBE07CULL, 0x373C22996AAF8618ULL, 
            0xCE7DE94A5C029C4EULL, 0xE6D6BE1FA5FCF3E4ULL, 0x27465A2E023CB017ULL, 0x55B3DD26F91075A2ULL, 
            0xB97FAE1BBC3BA34EULL, 0x8F45A1A24BD0A727ULL, 0x018C2AC228E3DF5BULL, 0x56457BCA7B2423B4ULL, 
            0x64807A9476DB9CBEULL, 0xA4254CAF4C2F6A68ULL, 0x0B1BA54E097F8D82ULL, 0x189A26E8CB93CF96ULL, 
            0x9E8FC032182AD816ULL, 0x6A4C68BA191DC95BULL, 0x00A48556C4AF3B5BULL, 0x76BEF2DE4830CE3CULL, 
            0x0EC2EB3D8B1374BBULL, 0x82B36EA9DA131FA6ULL, 0x3887E493F3E547C5ULL, 0x8DEF94CE0030A55AULL
        }
    },
    {
        {
            0xAC096702AFBF035AULL, 0x94AEBAD0D46C74BBULL, 0xDCB8C1A1ADF83358ULL, 0x5077266D549AE88AULL, 
            0x697445C8A08F3B4DULL, 0x6245BC115AC17868ULL, 0xEC78C3B4EFD898C4ULL, 0x4F7E130C95BD6906ULL, 
            0x9EBDE69CBAF1F732ULL, 0x90A4CD4DB30AAB5CULL, 0x1FE2FDB69E0BB3EAULL, 0x3EBF700511099437ULL, 
            0x21025EE4B4E029B6ULL, 0xD5917ADA7CF1A3FFULL, 0x5CD63B3B72971D60ULL, 0x344000A9876A8255ULL, 
            0xA8B1789F23A03431ULL, 0xD5376F028814574EULL, 0x0D4B3498092515B3ULL, 0x05B98D95EB634603ULL, 
            0xFC3975F3CB2B423BULL, 0xD4A950E8CD57F851ULL, 0x0F176B2C5FE7A023ULL, 0x638CE8135BE566ECULL, 
            0xBBEF910109F99905ULL, 0x7CEC4E6A5F2AEBD6ULL, 0x735CBBA9F2C55CD8ULL, 0x5F589817C25DE8C3ULL, 
            0x1408FD4DD86920BFULL, 0x2ADE278E131F65FCULL, 0xB56B96B38750D926ULL, 0xBCA5E68B53396401ULL
        },
        {
            0x65DF8F7F2F7D949CULL, 0x87D3F32EEAC828DAULL, 0xF331102A0AE76932ULL, 0x67073372FC29A94DULL, 
            0x6FE0FF6547D866C9ULL, 0x5C3FBDC9C59AB14DULL, 0x5B3B02DFA7C6DC66ULL, 0x84EC27269CC3122DULL, 
            0x537EA4F5A016A9CBULL, 0x4E12651EC80028FEULL, 0xB1506251D4E6DF24ULL, 0x21916FF21617493CULL, 
            0xCF21C31F6196A27BULL, 0x62AB4AE41AE823F3ULL, 0xE85FA3566D4CB552ULL, 0x3AE76FECC5527B9CULL, 
            0xF8357DFE87DD4DCEULL, 0xDFCB92D31ED444DAULL, 0x391EDB62F0D47BC7ULL, 0x97A5961F701E8A6FULL, 
            0x2AE648D0ACBACEB0ULL, 0x71F5E56A87D9C721ULL, 0xCA654CC2967E1E91ULL, 0xC30F33342616455FULL, 
            0x5E48AB7BF5D14636ULL, 0xE80F47FAF9011FFEULL, 0x0796A95D63AC117EULL, 0x61BCC22C96E5E0C2ULL, 
            0x7571FF37FF0F7307ULL, 0x5EE90EE2D2142F52ULL, 0x252EC0D4AF3E0105ULL, 0x0BA3A157F293E2BCULL
        },
        {
            0xD7E8EC6445BA566FULL, 0xBF802549D56B49ACULL, 0xBD1AFA98D25D4FCAULL, 0xC12D61E009FEEF04ULL, 
            0x17BAA02FC8EB6B63ULL, 0x5C473DA26088D5C1ULL, 0xEAF3342C609D01D8ULL, 0xD16A9DB044295E23ULL, 
            0x4CC20D0B7FCE0121ULL, 0xD03C8DC504C55FADULL, 0xDB5519F0A2A02C59ULL, 0xBC5B565AAB4224BAULL, 
            0x6275CF3A174F074DULL, 0x4EF8EF12182EEAAEULL, 0x81B9BFEAB92ED59DULL, 0xF11A1D1279839328ULL, 
            0xFD1498C0AFE242A1ULL, 0x26131E99F8A9F8C5ULL, 0x9757C43346988078ULL, 0xFFB719C0A0AD20FFULL, 
            0x28947BD5BC87EB6CULL, 0x3359CF6219F37344ULL, 0x31502792139899FFULL, 0x0C9142C3CB68A970ULL, 
            0x86AF433ABCAB267CULL, 0x5EB864808EEAC296ULL, 0xDF77696BE7AB75E2ULL, 0x74382121902F40A5ULL, 
            0x0CDAB1CD0137D151ULL, 0xDEE81626E43D5E95ULL, 0x319A39E7FD1392E2ULL, 0x0B88074A6D33F96BULL
        },
        {
            0x8D52829A66BC5E73ULL, 0xD47431BF038BB75EULL, 0x9BFA20B2F36B9825ULL, 0x702B3BA75B86862FULL, 
            0x47E37CBBD6BE9991ULL, 0x53EB7C78FD20B6E8ULL, 0x91083617ABAD90B3ULL, 0xA5CF5498D86C6BD2ULL, 
            0x4D0AB053C88964CDULL, 0xFE5EEFE8C163A72CULL, 0x9B5BEE75DD28A42CULL, 0x07858412F1E772CCULL, 
            0xDC5BF2D1FFE4FF4CULL, 0xC34DBAA99610BA59ULL, 0x984188E00B198B4AULL, 0x0766E3DCD0863456ULL, 
            0x11F6BB570F235F54ULL, 0xF420E9A93C3BB661ULL, 0x616F07F9CE7A52F4ULL, 0xC5A756BF8494E829ULL, 
            0x5184D94C83A86880ULL, 0x4C72BC8ABC83A19CULL, 0x78DA4454F2D55BA1ULL, 0xE8924CE0DD35E9DCULL, 
            0x5415C2F88F3A9106ULL, 0x0B12A692814FD9F5ULL, 0xDBEBD8FC3665B14BULL, 0x15C325C0007AFA49ULL, 
            0xE0DA0953BB071FBBULL, 0x9227388F6E3E4D72ULL, 0x69FE70819CDDA12EULL, 0x84CF34423A66AB45ULL
        },
        {
            0x61AD56EEDCE2462BULL, 0x450EEB11D77C122DULL, 0xD6EA58A78259525EULL, 0x8344EFDBA08B1EEDULL, 
            0x4312633C06AB2739ULL, 0x9A52E834BE9B1F0DULL, 0x8E441BA9357DDF66ULL, 0x63BBEA20F095A612ULL, 
            0xC6EB7FF9D7F50B1FULL, 0x45ECC4F082D04887ULL, 0x03F8DDFF5A92A63BULL, 0xB1A4DE8D2A2A0D1BULL, 
            0xA11053585CA9932DULL, 0xA76B558AE84B0368ULL, 0x18A0C10EDF5D7B4BULL, 0xEEC30F60D0C0DD81ULL, 
            0x497467E8925EB8C9ULL, 0xBEBFFAE1C7C0E619ULL, 0x2F899FA2EF69F422ULL, 0x9EF0F9214D4768E6ULL, 
            0x6FB09E22E08B79CEULL, 0x7B6A7B0915741B99ULL, 0x052EF670480540E2ULL, 0x87C4D48912194D1FULL, 
            0x5D11EBDABB5C710AULL, 0xBD23F4CC4A3E4953ULL, 0xB41513706EAC2321ULL, 0x77ED1F0461DBDB6AULL, 
            0xD986432D275DD4AAULL, 0x08833A5CEF2D71E2ULL, 0x290AE2211AB95B93ULL, 0x29FDBE57D4FDF813ULL
        },
        {
            0x9D21BB203321789EULL, 0x16C4FF3236412C6DULL, 0xE907A4C05A97C693ULL, 0x5039A8EADE18D080ULL, 
            0x60792F5D9E6959A5ULL, 0x7D6E7EBF3C850BFFULL, 0x59782F798914730EULL, 0x4EA8C51820D24B88ULL, 
            0xEAE76ABA509E673BULL, 0x11014B261A638515ULL, 0x31AD9FDD4002A696ULL, 0xA4E9D73B32F748E3ULL, 
            0x2C3CD36188A022CEULL, 0xEB4A1A24081E996BULL, 0xF356D081B56B2101ULL, 0x55E8233886D27469ULL, 
            0x65B265FF6AF331A7ULL, 0x6D564873C03B185AULL, 0x9F95341DF0C76548ULL, 0x6262E7026DC5B1D4ULL, 
            0x6347AF38AC453259ULL, 0xCE6F8E0B1D68B185ULL, 0x73DAED8BAF2D9E1CULL, 0x1B61FAD98B59CDEFULL, 
            0x2DA21FB6D5DB57D6ULL, 0x094E85CE3CB2FA30ULL, 0x9B54F9E300C4D5F6ULL, 0x6D8246F424AFE4C5ULL, 
            0x175C057B5D1FCE07ULL, 0x49D1965A5743077DULL, 0x781131C9922A65A3ULL, 0x942DCC6BBD1D520AULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseGConstants = {
    0x6088B932F1F2321EULL,
    0xB3C434E7694BCDEBULL,
    0x672D503993A18D2BULL,
    0x6088B932F1F2321EULL,
    0xB3C434E7694BCDEBULL,
    0x672D503993A18D2BULL,
    0x5701E04F9FFB0340ULL,
    0x8C38C5A1CD8489C4ULL,
    0x0E,
    0x0F,
    0x63,
    0x56,
    0x76,
    0xB8,
    0x4C,
    0xDB
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseHSalts = {
    {
        {
            0xDF0859A7AEFBFDF3ULL, 0xE2E0B042F62B3296ULL, 0xA1AECFF2E563DAECULL, 0x5E4C9E8E81D2D12BULL, 
            0x2A3142C13E0D9B88ULL, 0x31AE936FE8A37CB7ULL, 0x6CA702218248AAF6ULL, 0x9218B262C88D0733ULL, 
            0x047A819150791865ULL, 0x095E4FBEDB32F249ULL, 0x5ABBE568559EFA94ULL, 0x7F8C83C412FBD914ULL, 
            0x9D3B50937DB5DE33ULL, 0x64252499A1156FC7ULL, 0x2DEA97C3EC73652CULL, 0x526A5C22C4BEF652ULL, 
            0x82061865549F0AC4ULL, 0x5859064721D18BCAULL, 0x65F297C5D0B55104ULL, 0xEB5EED652220317DULL, 
            0x78CC47331AAFE30DULL, 0x287F7E84B3210DFCULL, 0xE9F5D45219888E18ULL, 0x31905D5EB619C8A4ULL, 
            0x43169554F60024FDULL, 0x96FFEEE1231AD0EFULL, 0x0F7376582F805E6DULL, 0x1D04BCF8FA187D5FULL, 
            0x6DEFB4EF6BD81198ULL, 0xD4F52ABC723C5468ULL, 0x62ECA30C5D12895CULL, 0xDD5253A2EC293C8EULL
        },
        {
            0xEC47F40A8F461D07ULL, 0x4AF0033D18B1FC3FULL, 0xFC1D6EB41D2F70E1ULL, 0x60945C96C506F724ULL, 
            0x8125ADAB0358C624ULL, 0x527DFB25D912011EULL, 0x607A0DB4D99F5507ULL, 0x5ABBF8A2419CCBD4ULL, 
            0x0D4567775B4B5D54ULL, 0x7C34F010B7ED1025ULL, 0xCFAB1D03D5DF6AECULL, 0x7A8C0CFA24EACF53ULL, 
            0xE6A299D68D9E194AULL, 0x83AA2657FC312966ULL, 0x792ABCBACDC035EEULL, 0xA7716079C0C0E0E7ULL, 
            0x997FE20F261758DDULL, 0x7F2C9FE9FC2103BAULL, 0xCAE3BA001EC824ECULL, 0xEDDE500AF31C8ED9ULL, 
            0x05F42D576DA6B043ULL, 0x5B1FE38605A3B847ULL, 0x4E4D1F3FB61FEF26ULL, 0xAA9EBE558216E36EULL, 
            0x824B7CA8955F0965ULL, 0x38507126F867690DULL, 0x0C4A8AF06D3EBFB1ULL, 0x109C6C7E3DF15789ULL, 
            0xF8C94C08ADBE2858ULL, 0x9B91AB50F082DE63ULL, 0xA3881C4389E788CBULL, 0x69F6EF00FD6DA304ULL
        },
        {
            0xA0E00A6D87AB9C60ULL, 0xD1BE83651C38E742ULL, 0x4FD6F98C91B2830BULL, 0x8F44603AE1F82B5BULL, 
            0xECA7F728DD4A6077ULL, 0x369ADDF5865C740DULL, 0x432BBF68AA534D88ULL, 0x54EEBD890AD01E94ULL, 
            0xEDB374B414B73E53ULL, 0x6F490E57C151DF46ULL, 0x0C7DD60F34B23B3EULL, 0x33C6EEF908376AD5ULL, 
            0x421A1EE4E8CEBDCDULL, 0x674DE94461FBBFC8ULL, 0x64A931B0F811C8D7ULL, 0xBEF110C44319ACC7ULL, 
            0x6904F4A3BA656D23ULL, 0x0B9426AC07221D3FULL, 0x09D76142CDAC8418ULL, 0xA113632D5DCA35E4ULL, 
            0x527926BF23A5CBDAULL, 0xCC02217F16951F21ULL, 0x85A5F8E5D9798AE9ULL, 0x232F0F5A08E37EC7ULL, 
            0xF9E619DE94A5E72BULL, 0x003E65D29445C7A0ULL, 0x4DC4B967DE5538B2ULL, 0x39224FFDE58F8727ULL, 
            0xB761AF2BFDB458C3ULL, 0xD0E151DB71919434ULL, 0x760691980155E15BULL, 0x1996241B7DF8D9B7ULL
        },
        {
            0xC52E1A10C489F475ULL, 0xCEB5E5DF51998447ULL, 0x3850093E65919EF4ULL, 0x318DB5BE984D3D21ULL, 
            0x53DA7338EA4D4053ULL, 0xBD174E2735330E50ULL, 0x3F7527B6E171A754ULL, 0x1DB36DBF147CECA2ULL, 
            0xB4093727505F99ABULL, 0x786A9388C7DB76FDULL, 0x5DFC515D5408A633ULL, 0x8678FA2CC0281A1AULL, 
            0x421914CB59E46CCAULL, 0xA3882D71062D8CB2ULL, 0x238759A21D0AEA41ULL, 0x3AD530EB7AD5E93AULL, 
            0x299A33D1F8C06F73ULL, 0xE350282569E37E16ULL, 0xE29E7FCF154BE7EBULL, 0x404E758AD8238F81ULL, 
            0xF0F71478C01AB703ULL, 0x3D1ECB16A6BDD1DFULL, 0xA0F96B1D78C16172ULL, 0x85A56052B96BAE02ULL, 
            0x4DA175B02592665AULL, 0x6418AFA195C2D222ULL, 0xE95A0159323350E4ULL, 0x41F81FEB5089BF34ULL, 
            0x88E490BF7D312EACULL, 0xDDE25180166E9098ULL, 0xCC76F842FFCE8363ULL, 0xD9F7B6A8ECBE05A8ULL
        },
        {
            0x48FE67CDC1E400D2ULL, 0xADAC03C8CD9A0E42ULL, 0xD676203FCD9B3390ULL, 0x089D8E1EE3D9EA8FULL, 
            0xACBCBDADEC27B388ULL, 0xC001C20BC1FBAFADULL, 0x3C95C9FCBEA7BFFEULL, 0x66D960BA7FF31FFCULL, 
            0x33442472342D9EBDULL, 0x2FAF2D5E6090F5F0ULL, 0xD26CFD13C91F30FBULL, 0x822D7E413E702516ULL, 
            0x958990C17F384B62ULL, 0x709945B30A28BEB2ULL, 0xF76048D0C058F148ULL, 0xA85689AA590252F1ULL, 
            0x905335366FDB78E0ULL, 0x9015D4AB21A6626BULL, 0xF3BA74D0A74390FDULL, 0x971D9CE307D8E9ECULL, 
            0x0BC5A8F741FCC6A6ULL, 0x9084DA055BF05DE5ULL, 0x428840A56C7AC2EEULL, 0x11EE7519D663C6A4ULL, 
            0xBA476AC0A238DF15ULL, 0xDC5235531E69E360ULL, 0x9E584A20B8EF0BDEULL, 0x07FE00DE10774B3AULL, 
            0xF9B140CAC021A0C9ULL, 0xACAE7816D72C71ACULL, 0x019DCAA5A6536D2BULL, 0xBBAE968726ECECE3ULL
        },
        {
            0x97B51624183CEE23ULL, 0x3E78BB5777957664ULL, 0x9A04955B9F4C169BULL, 0x35B20CBCF56199EDULL, 
            0x9A103E9D3F5EBF57ULL, 0x3C7A37980A7C4B92ULL, 0x650AC5D7CCE86237ULL, 0xF5E99218CDD443FDULL, 
            0x3BB4BB112029DA50ULL, 0x349099CBE3F9209DULL, 0x853486D9DD61431DULL, 0x308C29830EE73BB7ULL, 
            0x85FF4AF25E93B6A6ULL, 0x5AA5A6E78B833AA6ULL, 0xC2856A8B80F3CE5EULL, 0xFFA12041E8A6E1F5ULL, 
            0x73EE6CC1AD38926FULL, 0xD48F0D3655B03BA1ULL, 0xDEE343216026B420ULL, 0x0D91EB2EAD09AF63ULL, 
            0x6A533A612544925CULL, 0x79110386E684E7C0ULL, 0x3860598D242DB958ULL, 0x5CB2C18FEC01DFCCULL, 
            0x62CC495DC47CF578ULL, 0x66C760147FEE8856ULL, 0x12FE58ACE7E620FAULL, 0x7D328F6F57B7E89EULL, 
            0xFEDB8C8A0B36105DULL, 0xD6DA81036523CEF2ULL, 0x19C5B744F15CE53AULL, 0xDCA9FFFB5035FF0AULL
        }
    },
    {
        {
            0x77EBCEB403EF2B75ULL, 0x3E300F92AD1610ABULL, 0x97DBA23B0D0387BDULL, 0xA21E28B37211601AULL, 
            0x8A817AFB8293027BULL, 0xFC377E4AE684A040ULL, 0xBDBEE641CE16989CULL, 0x8122587D6A20F463ULL, 
            0x4BFCD25C6567C2D6ULL, 0xAA310AF033276D56ULL, 0xF0962AC302B5C2D6ULL, 0xCEEAC9A93AECA5FCULL, 
            0x128C080574BDB321ULL, 0xBE16E76779FB713EULL, 0x0B9368D7A7572843ULL, 0xF2B03AE2DCEFE4C7ULL, 
            0x8913244B29C4A559ULL, 0x0D491A2EA611AD65ULL, 0x5370F177D7AF1B74ULL, 0x86823C30FDD6FCC7ULL, 
            0xF6D7468AF26E1311ULL, 0xCDDADAE28E7E8852ULL, 0x6FF8583A456C9197ULL, 0x952F3D61D341C3B7ULL, 
            0xB949DAE0A8416645ULL, 0x15BDBD6705AADC27ULL, 0x756C583C8FD3437BULL, 0x758A01B85E436156ULL, 
            0x96D4B9D16B004199ULL, 0x2B992EFA3908DF8EULL, 0x4505B9A28F3C54BFULL, 0xD231893085A182E8ULL
        },
        {
            0x8FE83C064B8A7D1EULL, 0xD44194061D0AC0BCULL, 0xA24914F95498A124ULL, 0xE2DB5D260600777AULL, 
            0x738662CD2115E10AULL, 0xCD3ED1628C102D7BULL, 0x892551472F6EDB79ULL, 0x5CD7B04EE317D0E6ULL, 
            0x26129460F060541AULL, 0x63537316B3E3927CULL, 0x02F98EF50B3D2990ULL, 0xEB96349B20A8568BULL, 
            0xEB2F4A4535624023ULL, 0x3201345FB8DD5F6FULL, 0xA1EE1B840A09B457ULL, 0xBF75CB5087F1C7CDULL, 
            0x0FBE27529621B125ULL, 0x390A15B27F281B4BULL, 0x88179F6416C5D1EDULL, 0xDD081E5D8CAE71B7ULL, 
            0x3FCBDD1D9625A34BULL, 0x201661E00D8E8495ULL, 0xD04045C04BD6EC8FULL, 0x2B2DD8D0C896F506ULL, 
            0x074EF04C7F571BDDULL, 0x68EF96158AE04737ULL, 0xEC79D080B213AA72ULL, 0x4A9E7BC1855D0F4FULL, 
            0xED703B1FBBC82A77ULL, 0x75C67794FE0EA8EAULL, 0x30C2FDB64935AA4FULL, 0xFEB09FE21F17BA5BULL
        },
        {
            0x9BA3D4A0FD42286AULL, 0x88B90297733D63A8ULL, 0x9EEF65EFE8269B0BULL, 0x311A90ADCB84332AULL, 
            0x6200EB3564B1ABF1ULL, 0x89DA81A6DFDB5500ULL, 0x1B782EAADD6448DAULL, 0x04BD7F7E90092496ULL, 
            0xAFC918EE8A766C5FULL, 0xE5C33236907501C8ULL, 0xA1209735098EE8FCULL, 0xFFEF8CDACFE08F4DULL, 
            0x270A45810DE6EDC0ULL, 0x9AFDF310B0BF8D46ULL, 0x2F63B1BF41D6A998ULL, 0x910F31EE098B636DULL, 
            0xDC2FBDE0B589F10AULL, 0x8C85F22BA8DDCA51ULL, 0x3E99F93497999E79ULL, 0xC0E9BD206A6B1CD7ULL, 
            0xFEFF0E7FEC3F3A65ULL, 0x8CE4A276C943E703ULL, 0x216B6D3FEC3DEBB2ULL, 0xE3B6506A4262F67FULL, 
            0xC01F79F7E94D9FC7ULL, 0x9ECD2E73D8E9E16DULL, 0xD91832CD1ED76077ULL, 0x7A78EE0EDAA999ABULL, 
            0x458683A5F66CC872ULL, 0xEAF8AC1E37E3F024ULL, 0xCA8DD83830F6AFB7ULL, 0x5A908D516B378C25ULL
        },
        {
            0x0C3E95C86819ED55ULL, 0x2D95DF6CBD848D3CULL, 0xC31FD97F42896F8CULL, 0x1854AF791674E44FULL, 
            0xEE8ABEBA49BD3FF9ULL, 0xC5CF6FAFBCA9DADEULL, 0x9758245A7B3DF1E0ULL, 0x2F311D4A874E1496ULL, 
            0x0A37264E60FE7A6AULL, 0x9B446BB831B92D25ULL, 0x147A39CEEB899424ULL, 0x63B48625FAB5A06EULL, 
            0x69FD9A7E485EA797ULL, 0x658E95E3BD6B763FULL, 0xCEE0BC53A09381D5ULL, 0x0B68A7B6A143F458ULL, 
            0x16DD3A36FC694BA0ULL, 0x1450527314A75AB4ULL, 0x9C834EEA8759FA3EULL, 0x1239DD227DB9A0CDULL, 
            0x0201EF319C13E73EULL, 0x077E1CDC6A8CA9FBULL, 0x9768AAF0328D45ECULL, 0x8247BF36303B7B9AULL, 
            0xE978CBD9D2DDA343ULL, 0xD8BEA221AA8CB318ULL, 0x183275B1D300E275ULL, 0x90F35461373F2511ULL, 
            0xBF78CEFF1F56C2E4ULL, 0x9F78DB9B54AC937CULL, 0xE84AEF6221F2530AULL, 0xB81B08AE2F3F5214ULL
        },
        {
            0x77F8BE5F23E20678ULL, 0xF1F26F5C28D05F15ULL, 0xFC285284D7326996ULL, 0x34892D272B21187FULL, 
            0x41CCDF872409D4D6ULL, 0xF8BF7648C74B84E6ULL, 0x62FCA7331A47EB80ULL, 0x310506EF4C46DF37ULL, 
            0x61E1188F766E14B5ULL, 0xCDDE5DA5762C9CA3ULL, 0x8729E0CD11F83F19ULL, 0xF7BD0BFC26824265ULL, 
            0x8E825FCF759EFB05ULL, 0xAE1779C9CC0F774AULL, 0x586F7771FCB8A311ULL, 0x90718FEA35889A8FULL, 
            0x02CEF451414258F4ULL, 0xD6E7EE26FF191CE8ULL, 0xCDB34DC0A61F280EULL, 0x500C360F26FC08DAULL, 
            0x9FD967C77490B121ULL, 0x8BABFD1A2224759DULL, 0x96AF3ADB75F852E1ULL, 0x1FC08D1C978F8717ULL, 
            0x6B89388A9926F8FBULL, 0x07D0F4664B5CAEBEULL, 0x089F7DA26BC439DBULL, 0xB54EA4E97439441AULL, 
            0x3EB1A31C4320CE31ULL, 0x550A7EC6573B6DFEULL, 0xA7DE2F7D5432F712ULL, 0x334338F6C644AC35ULL
        },
        {
            0xE6011DD0D1F67BA0ULL, 0xD18A8F9DEC138474ULL, 0x32D105B830DF02C9ULL, 0xC099D86E09B304DFULL, 
            0xACD64ACE5E975410ULL, 0xED924E709D4B7FFFULL, 0x6A659903D1F593EFULL, 0xACABE8C49FB66EA2ULL, 
            0x78627E07508C9E96ULL, 0x7E4A13BBED43CAA9ULL, 0x7C66178F592F2FAAULL, 0xE6EC5D9AB3314121ULL, 
            0x945E20C613C21926ULL, 0x664C06F2225F3134ULL, 0x91DAA39C06D8B630ULL, 0x1AB3345813441C3DULL, 
            0x6ACF44621F19F896ULL, 0x24DA5E6E3F8FB510ULL, 0x84BD1B877E14EC5FULL, 0xAD3091C37A33D067ULL, 
            0xA4F3FFF788BE0E58ULL, 0xB369051889C0D7B5ULL, 0x31EE6DE723A80FAEULL, 0x4481D0E84E175228ULL, 
            0x95F0033231F87143ULL, 0xDA2471F28098679CULL, 0xD23FB0180EA6E7C2ULL, 0x58A959F36FC31B42ULL, 
            0xA8E3D02E2CB070BDULL, 0x2A7FFAA0DDFB067DULL, 0xDF1ED92B33111B24ULL, 0x301377A96604D667ULL
        }
    },
    {
        {
            0x8E99497BB1B7E6A1ULL, 0xD4026835970553B8ULL, 0x001C5700CF65C594ULL, 0x8E186EE972A3F9EEULL, 
            0x6282866E54257DEBULL, 0xA7C839460E18B9A8ULL, 0xA7195A1BB449AFD9ULL, 0x7DC0B10C030FD5C6ULL, 
            0x847DD91824F70408ULL, 0x81CDD73FFEDB2DF6ULL, 0x20D930E813BEDD30ULL, 0xD0ED04553BD5929CULL, 
            0x414F185B2D0DF8B2ULL, 0xE8122033E6CCD7FDULL, 0xA260CA2600AFAB22ULL, 0x9BFE6102ACFCC004ULL, 
            0x299F31D32B4ECDB1ULL, 0xD1E6C8754C37DB0FULL, 0xAAE8B2721A19591CULL, 0x7A17FCD5D7CE08DFULL, 
            0xD371F5DB15C61889ULL, 0x782746CD5D1703E2ULL, 0x862FCB9D07141764ULL, 0xEA3CAF67A1991326ULL, 
            0x8D1492B9B2E64153ULL, 0x73A7268572721DD7ULL, 0x9AF818E7D8CD60BBULL, 0x56C9901E2A0D04F3ULL, 
            0xB51FD245A5B36877ULL, 0x29C1518E00D33CA8ULL, 0x63F564DAA9F4DB6AULL, 0xEC0BB910FD0A7945ULL
        },
        {
            0x1D5F63B6F1B1E16FULL, 0xCEFFFB13B15F259EULL, 0xA38EED6C534E60C7ULL, 0x2451E8F4EAF9A9E8ULL, 
            0xC16E980941AB14F0ULL, 0xF479EB6AFCC68AE1ULL, 0x791A0C21B508E83FULL, 0xCFE6FC9574293C3FULL, 
            0x48D5BCEF67345272ULL, 0xA5DED2E40E782EA6ULL, 0xC2894EA243B4E6D4ULL, 0xB4A66FBFA7F90163ULL, 
            0xB5F441C79458F5F7ULL, 0x4A9E2DF1239D72F6ULL, 0x2CA9D83CDC404D1FULL, 0x361A9B84921DE796ULL, 
            0x24811C36A520C87AULL, 0xF0BE2AD3C2132B41ULL, 0xBB4ABB01F7F6EB65ULL, 0xBD3006D1D13AF118ULL, 
            0x169E31E2C956A226ULL, 0xD09DD0C0B4C83522ULL, 0x6ED6DFE35BCE8CB8ULL, 0xD9FC82959B19C63AULL, 
            0xE2D691E5B8F37C5EULL, 0x30A710310F1263A9ULL, 0xA3A8E47B0B5D30AEULL, 0x7E24A708E228794EULL, 
            0x7EC99D12FE9E879CULL, 0x28D6A6F0C6003926ULL, 0xDDB1656AB37C3227ULL, 0x92F149474DD6F519ULL
        },
        {
            0x74758DE54BF6C0ECULL, 0xE8B3BC17504144E3ULL, 0x63799E8166FB4F1BULL, 0x06E5351832B2DAF1ULL, 
            0xB41A313F5FECF8D1ULL, 0x6B26F18FD18B84EEULL, 0xF3A100418121CD71ULL, 0x7106D6087CF6E6FDULL, 
            0x6CA2A462C6F1DB4FULL, 0xAE97E1F1A0E194C3ULL, 0x4B53476138290D88ULL, 0xEC6B59FFF61F1314ULL, 
            0x1FA0C0532893202AULL, 0xFF7E051CB50669EBULL, 0x56048E69D163394AULL, 0xA12D9D0EC7E79DF8ULL, 
            0x4A3F8001CFB5969DULL, 0x9AF3E8F3C0D7E83BULL, 0x0CAEAE639C9766C2ULL, 0xEB3889660D6D519FULL, 
            0xDB64EED2B9DBB614ULL, 0x319A67796C2307A5ULL, 0x0CC99A4DADAA6071ULL, 0x8D0D670B9C7110B7ULL, 
            0xBACD6FA7276B3C5DULL, 0x75DA51D566CE8906ULL, 0x6ABC899E89DF1F7EULL, 0xF5741FA7AB302F8DULL, 
            0x798132B2C07D79AFULL, 0xB33123A4DF05AC52ULL, 0xDDC1D15B70E5F1D4ULL, 0x2A6EAB94A0FED771ULL
        },
        {
            0x283D5893D2E010BDULL, 0xE06D19652A95FCB8ULL, 0x517A3F5F4B0DAD7DULL, 0xA208D2EC9B284D5BULL, 
            0x8763E897245798DAULL, 0x54A9AB67959B41CDULL, 0x3D9CBC2D8972DE30ULL, 0x0F5C4413A6BD2042ULL, 
            0xE652F30B6C54099DULL, 0x18F034D6619D717BULL, 0x2FFA55866A30ED83ULL, 0xF43462629BD00039ULL, 
            0xB503BC39D0F901A0ULL, 0x9337E05A0C3C0DA7ULL, 0x0890FF93CB6CBB6EULL, 0x593E9BAC73E793A2ULL, 
            0xC99E5EC258A99E17ULL, 0x00415424B659DE91ULL, 0x8E492D53D3906395ULL, 0xD73A10AFFF40040CULL, 
            0x0FE723570E952B20ULL, 0x31AE389B6FB3D53BULL, 0x8AF151AB99DEAF76ULL, 0x8445E78C0F89977EULL, 
            0x8F5B8F94E0B388F7ULL, 0x36AA5FDB3B79544DULL, 0x71161B0F8C55230EULL, 0x4EBA75C4CDCF4F69ULL, 
            0x24AA7C240CF71AFCULL, 0x9141283E5ADC498BULL, 0xA4A3F982C2D9B894ULL, 0x086377CA8A08DFE8ULL
        },
        {
            0xB9F8C52FE3EC34FCULL, 0x141080323481C2B9ULL, 0x7F1A9F0C0EB4D457ULL, 0x404AFC867E035FDBULL, 
            0x5FF75123E3F6BBF5ULL, 0x91BB77528AC0DF5FULL, 0xBDE319F7BA02E26BULL, 0x889F96A4B7488EEFULL, 
            0x4C0C7857440200C8ULL, 0xF5DF1B2A2C47DE07ULL, 0x00CEBC04674AF9ECULL, 0xC1BC51669940E65DULL, 
            0xCE25F3002BA8D075ULL, 0x566F7F1BC277B0D7ULL, 0xE47B93CB216B7128ULL, 0x371EE9C00CC1F94AULL, 
            0x9F70209EA4D38D83ULL, 0xF496C841C0D3EBD3ULL, 0x6B110BDF6E312108ULL, 0xA34ED00F6A83B632ULL, 
            0xF20C8204B3EA4F2AULL, 0xC578E4D2D9342B20ULL, 0x34F24DB2AA727D9FULL, 0xB5326442A874BE06ULL, 
            0xA0AAB8501428B9FCULL, 0x311B1799FA894241ULL, 0xEB65D9DECCD8976FULL, 0x676248A074E1A451ULL, 
            0xD0CBBD9588F64A8BULL, 0xC7C9C9E6F72D8FD0ULL, 0x4BCC498E058F304FULL, 0x81DB0E54DD4FD47DULL
        },
        {
            0xF112C808662519FFULL, 0x45DEC38BADE373B2ULL, 0x1E06B43F8B05C879ULL, 0x7C548D9C6713AF9CULL, 
            0xB1DC4E70A8C9E0F2ULL, 0x4E6F53B709E728A4ULL, 0xB2D15D36FB7F68B0ULL, 0x0BBFF7A128AB909BULL, 
            0x532B7BFAC854D35BULL, 0xC8A8A30E06BAA3A5ULL, 0xF4F898B936168E50ULL, 0x3A9385B38CC2B925ULL, 
            0xCC84B62E15AD1E69ULL, 0x9BE90BE11358248DULL, 0x5C1479EEF613EB5FULL, 0xE9F475F3242155F2ULL, 
            0x1A263EF2C6D1B363ULL, 0x5053C48E456E43D7ULL, 0x5D88F4D0997A0CBCULL, 0x510C928ED3C2BC17ULL, 
            0x663386C221AB485CULL, 0x1749EACF90DADE16ULL, 0x5980D7C2388B539FULL, 0x0FFEC446B43BAE1AULL, 
            0xAD350D7AAF69C1B3ULL, 0x5D3B1B9BE4B9B205ULL, 0x161C8856453138FEULL, 0xBC58913113323F8EULL, 
            0x888B2C11219C28E1ULL, 0x4FDFA147F9CD7097ULL, 0x0B3AEDDC7C306A94ULL, 0x98CCC10D901D4099ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseHConstants = {
    0xE662657C02C125A0ULL,
    0xCFE3AC71B4021009ULL,
    0xCFC7CAE265E09767ULL,
    0xE662657C02C125A0ULL,
    0xCFE3AC71B4021009ULL,
    0xCFC7CAE265E09767ULL,
    0x239434AD272189A1ULL,
    0x0C9170145E1C59E4ULL,
    0x8D,
    0x5C,
    0xDD,
    0x8F,
    0x1D,
    0x50,
    0x0A,
    0x05
};

