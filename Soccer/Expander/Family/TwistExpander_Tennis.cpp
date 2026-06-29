#include "TwistExpander_Tennis.hpp"
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

TwistExpander_Tennis::TwistExpander_Tennis()
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

void TwistExpander_Tennis::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xF8A9A010725D9FA7ULL; std::uint64_t aIngress = 0xACB459EC16FA3408ULL; std::uint64_t aCarry = 0x95D14412E7CD53AAULL;

    std::uint64_t aWandererA = 0xAF31D25DD5A99809ULL; std::uint64_t aWandererB = 0x80AEA5782094E752ULL; std::uint64_t aWandererC = 0xA385552DEF48994AULL; std::uint64_t aWandererD = 0xF2F7A08D8129C078ULL;
    std::uint64_t aWandererE = 0x8FE2130EF6F68AF3ULL; std::uint64_t aWandererF = 0xC286C4406BC5F5F6ULL; std::uint64_t aWandererG = 0xCF212C633A229033ULL; std::uint64_t aWandererH = 0xBD90ED2E46BE2A2CULL;
    std::uint64_t aWandererI = 0xB97726FBEB36286BULL; std::uint64_t aWandererJ = 0x852FB55CC58088DDULL; std::uint64_t aWandererK = 0xA902969F53587732ULL;

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
        aPrevious = 16059832229301174262U;
        aCarry = 15617908731412443466U;
        aWandererA = 10316046308880595007U;
        aWandererB = 9902714848650951000U;
        aWandererC = 16936169686845063046U;
        aWandererD = 14668639517272540022U;
        aWandererE = 18367508035850369736U;
        aWandererF = 15785986518330471633U;
        aWandererG = 11954207159331080475U;
        aWandererH = 15456589013885288254U;
        aWandererI = 17936838232535442815U;
        aWandererJ = 13045363668709383156U;
        aWandererK = 14824354703811145168U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: fire_a, fire_b
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_A(pWorkSpace,
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_c, fire_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_B(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Tennis::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xBB0823B77689CCBCULL; std::uint64_t aIngress = 0xD13CAC12133AF448ULL; std::uint64_t aCarry = 0x8672D39D75290895ULL;

    std::uint64_t aWandererA = 0xC5514832A6BC4CBEULL; std::uint64_t aWandererB = 0xD40D3795C84A018FULL; std::uint64_t aWandererC = 0x911476962C3DAC14ULL; std::uint64_t aWandererD = 0xEA37BBED39F8AE00ULL;
    std::uint64_t aWandererE = 0xBE5F00DC92486F43ULL; std::uint64_t aWandererF = 0xA619652D3F09ECF7ULL; std::uint64_t aWandererG = 0xC106FDCB89B8202DULL; std::uint64_t aWandererH = 0xB08BF9587AD324A5ULL;
    std::uint64_t aWandererI = 0x9E4897BB061CF2DAULL; std::uint64_t aWandererJ = 0xA9EB2D8C8E14122AULL; std::uint64_t aWandererK = 0xE20AB5A8ADE6CB07ULL;

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
        aPrevious = 13027744696706135722U;
        aCarry = 17333413243303243267U;
        aWandererA = 13508124055401163792U;
        aWandererB = 18121959475876435916U;
        aWandererC = 12429831440381273240U;
        aWandererD = 17042950918586189986U;
        aWandererE = 12648713560362101104U;
        aWandererF = 10012010745074952483U;
        aWandererG = 10441840829379394755U;
        aWandererH = 11536922360964079408U;
        aWandererI = 13358073673015521806U;
        aWandererJ = 12522529639428192032U;
        aWandererK = 16136193281001762451U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Tennis_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Tennis::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA91E7B9CD0C2A4F3ULL;
    std::uint64_t aIngress = 0xAA573837749D0EF9ULL;
    std::uint64_t aCarry = 0xF1D46833A40261D5ULL;

    std::uint64_t aWandererA = 0x9650AB1436AE7516ULL;
    std::uint64_t aWandererB = 0xF659F55D3A7FEDA9ULL;
    std::uint64_t aWandererC = 0xA132E904688452FCULL;
    std::uint64_t aWandererD = 0x845AB94641AF52FFULL;
    std::uint64_t aWandererE = 0xACB42D6BE0A92E7EULL;
    std::uint64_t aWandererF = 0xD00C62CAB1E07C38ULL;
    std::uint64_t aWandererG = 0xF5B2B043EEF35D02ULL;
    std::uint64_t aWandererH = 0xE7FFF7968A306911ULL;
    std::uint64_t aWandererI = 0xAB8B114DC3814EA4ULL;
    std::uint64_t aWandererJ = 0xDEC127BC2D378EF7ULL;
    std::uint64_t aWandererK = 0xD2819F722645DB2CULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneF);
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneA);
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Seed_B(pWorkSpace,
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
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_C(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_D(pWorkSpace,
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
    // write to: snow_a, snow_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_E(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_F(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_G(pWorkSpace,
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

        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Tennis_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Tennis::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Tennis::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA0968A1FC50B718FULL; std::uint64_t aIngress = 0xC9CF373952138F65ULL; std::uint64_t aCarry = 0x8679889AD2A025EAULL;

    std::uint64_t aWandererA = 0xD5C52E8656F3C42CULL; std::uint64_t aWandererB = 0xFFE3508B9F39738BULL; std::uint64_t aWandererC = 0xD3DBD06E5D0F7C97ULL; std::uint64_t aWandererD = 0x818941A9F8124EDDULL;
    std::uint64_t aWandererE = 0xA9314AAEFD21A588ULL; std::uint64_t aWandererF = 0xED8014F1AD116414ULL; std::uint64_t aWandererG = 0xC806E3ECDDDEBDC9ULL; std::uint64_t aWandererH = 0xA1DA1A780FA8DFE4ULL;
    std::uint64_t aWandererI = 0xE58E940EBD04F768ULL; std::uint64_t aWandererJ = 0xBD0EC4ABAB8E002BULL; std::uint64_t aWandererK = 0xAF5B7F3483B2F99AULL;

    // [seed]
    {
        aPrevious = 16591828982048238660U;
        aCarry = 9575226295873417788U;
        aWandererA = 15752195812647410742U;
        aWandererB = 13876489997915885123U;
        aWandererC = 15212349343960502817U;
        aWandererD = 11798978810821891786U;
        aWandererE = 16168163107002618151U;
        aWandererF = 16913032957596477349U;
        aWandererG = 16177987894101342532U;
        aWandererH = 12551430108732073693U;
        aWandererI = 14006778843054864061U;
        aWandererJ = 10299361877091962850U;
        aWandererK = 16810850002687657747U;
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
    TwistExpander_Tennis_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Tennis_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Tennis_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Tennis_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Tennis::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 1, 0 with offsets 6748U, 4780U, 1409U, 6909U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6748U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4780U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1409U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6909U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 2, 3 with offsets 7719U, 316U, 5314U, 4349U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7719U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 316U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5314U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4349U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 1 with offsets 1114U, 2246U, 189U, 2273U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1114U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2246U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 189U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2273U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 2 with offsets 3330U, 43U, 5563U, 2862U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3330U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 43U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5563U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2862U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 with offsets 1422U, 761U, 74U, 1974U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1422U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 761U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 74U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1974U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 2, 3 with offsets 2037U, 1260U, 758U, 1878U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2037U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1260U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1878U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 3, 0 with offsets 2030U, 862U, 125U, 808U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2030U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 862U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 125U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 808U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 0, 2, 3 with offsets 238U, 1655U, 1348U, 1640U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 238U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1348U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1640U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 70U, 1603U, 19U, 648U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 70U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1603U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 19U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 648U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Tennis::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 3 with offsets 7195U, 2685U, 1774U, 1420U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7195U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2685U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1774U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 2 with offsets 5685U, 1879U, 8078U, 8005U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5685U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1879U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8078U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8005U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 0 with offsets 1645U, 6210U, 1329U, 4039U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6210U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1329U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4039U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 1 with offsets 947U, 3421U, 3201U, 5743U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 947U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3421U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3201U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5743U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3184U, 5611U, 5973U, 5778U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3184U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5611U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5973U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5778U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 241U, 1041U, 1765U, 1802U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 241U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1041U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1765U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1802U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 355U, 1011U, 1997U, 1895U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 355U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1011U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1997U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1895U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 405U, 612U, 511U, 576U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 405U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 612U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 511U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 576U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 448U, 595U, 153U, 22U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 448U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 595U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 153U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 22U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 [0..<W_KEY]
        // offsets: 1658U, 1737U, 19U, 2032U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1658U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1737U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 19U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2032U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseASalts = {
    {
        {
            0xD470B3FA5F2B2A8DULL, 0x53100A3226B36F61ULL, 0x1125A94041859779ULL, 0xB058D84D593117C2ULL, 
            0x4AB673583BAC51D9ULL, 0x4EB860A8BF621DF1ULL, 0x2DF2801C3021DF85ULL, 0xC3538ADBBF669D3AULL, 
            0x97B88C655C29E947ULL, 0x0BEF285A4D60D32DULL, 0x81CBB6852C42F8A4ULL, 0x499E37196404485EULL, 
            0x9D47AE4A161FDE77ULL, 0x09F296BB03BCA5F9ULL, 0xF44D4CE4B082C4BFULL, 0xD95AAB97C40F47A6ULL, 
            0x9C694B3584FA9F47ULL, 0x6640BBD5DCA88492ULL, 0x2FDCF66D408C05BBULL, 0x462373C932A653B1ULL, 
            0x3433B089432551EBULL, 0x4320E03DBB59BC01ULL, 0x583A83B7F332B8D4ULL, 0xE6F5C4648B4A60A5ULL, 
            0x463154824679B0E1ULL, 0x56E68CCE90933C48ULL, 0x0F164BE294E4013EULL, 0xAAC384B18B273EE0ULL, 
            0xD1D8F31F18681AB9ULL, 0x2C5EA12046816A19ULL, 0x7BEEED7A4D08CB83ULL, 0x2EC1C126D6F95078ULL
        },
        {
            0x71694B9A72816DCDULL, 0xF0FC598935FC4ED6ULL, 0x35752E497A2BC286ULL, 0xD6872310B8084941ULL, 
            0x84700A5A46A33381ULL, 0xE25A5CF98FC25D54ULL, 0x1D51BE8FCA47EB86ULL, 0x38EF7C8FDC0A1D30ULL, 
            0x29894CA34CCC5128ULL, 0x58F97E36CA1511B6ULL, 0xF3C49785AB7ADC51ULL, 0x821075CEE828D83FULL, 
            0x638E692D6F3B516BULL, 0x8BFF64802E9BDD88ULL, 0x0F6A884ABD6B9D26ULL, 0xCAEFA9460CE76843ULL, 
            0x7DCC7F04CCBCAF32ULL, 0x166BF2D1210D2FD5ULL, 0x6EE7833D26BAD597ULL, 0xAC2663B952A91EE0ULL, 
            0x5784B826A6FCDD9EULL, 0x68156575E703CCEDULL, 0x957256782951AC2CULL, 0x2B2BFED5776B42CEULL, 
            0x4CFEA31DC3B1EFD9ULL, 0x9D9EFC341565D08CULL, 0xD09B97E97F5DE7FBULL, 0x917DD15005FD8ADCULL, 
            0xE275928C04463867ULL, 0x9A9E108877DB1BF0ULL, 0xFF58A001FF7535C3ULL, 0x8294705443B5521BULL
        },
        {
            0xCB8D4743B40B3677ULL, 0x1611D28B3E583708ULL, 0x761B9EEFD51FE0F8ULL, 0xD6750B989D6B5032ULL, 
            0xA793B3F7992A4F05ULL, 0x34CDC94CB9B5EB1EULL, 0x0B8B5F8B7423E559ULL, 0x8591DC2208FF5FA1ULL, 
            0x097E66CE8BA75EF1ULL, 0x4FF80D0FC62E5FF1ULL, 0xB9252B7AEBEC2CC4ULL, 0x111DC2DF864A3750ULL, 
            0x65B2357D910469E5ULL, 0xA577AAB97A5310B4ULL, 0x94D2E92C162398A2ULL, 0xAB90C117DF848562ULL, 
            0xC504CF38517523CBULL, 0x6A79BD510844B94CULL, 0x202B5812390003A2ULL, 0xA19747A7D427590EULL, 
            0xA90053411C049283ULL, 0x583ECF747CF63A35ULL, 0xFDBFCA326FF518E5ULL, 0xDAC6EED0B5EF949BULL, 
            0xD2668C8D17AE23F0ULL, 0x8A3D83BA6C985E68ULL, 0xF274304B637AE3A9ULL, 0xAF8BD970F6059860ULL, 
            0x08C68876FA674F80ULL, 0xE8E998340D8A0F31ULL, 0x887C60BE24F38F73ULL, 0x2DE2CC5144B90299ULL
        },
        {
            0xA2C1E2013CA4C68EULL, 0xF6D41A5244EA8A99ULL, 0xCC2D51FC4CFB6582ULL, 0x6A388B328CCC57E6ULL, 
            0x8AA5FA8C4FA3A9A7ULL, 0x54A01F5D97FB7A82ULL, 0xBFD4842D6D52CF7EULL, 0x476EC66B798C3A78ULL, 
            0x0B675BADB01ED243ULL, 0x5CA2CFAEC888A614ULL, 0x6CE404D887D3E1E6ULL, 0xCC4CCE2187AE19F0ULL, 
            0x46A9D02BA27604DEULL, 0x5E09800CBAA529F1ULL, 0x8910110183A75307ULL, 0x4B16A3D95459DC52ULL, 
            0x8D82E81DE21012C2ULL, 0x41D5EF883540A246ULL, 0x6071E2303CD16CFBULL, 0x88CAC298BAC23F00ULL, 
            0x917DF5FB2B7278B2ULL, 0x01B6B8B86643DC06ULL, 0x8A6BE4525B2C3623ULL, 0x354B8504AC8B9FF9ULL, 
            0xDA6B7E7D9D7DC8A1ULL, 0xF400C41B85797799ULL, 0x8F85EE1B80D1943FULL, 0xC725F17B0FDC930FULL, 
            0x5208570C8128EA33ULL, 0x6D3FE80B33CFE31DULL, 0xF1A5BAAA571823C3ULL, 0x3DF9C24CF4AA1A58ULL
        },
        {
            0x25AF3720ED5F8A66ULL, 0x3EA374EE78D3CF01ULL, 0xB7D1BA80A634C7CBULL, 0x81881F01BAAFDFFBULL, 
            0x459B4051236F2CD8ULL, 0x86F68EEA5B783D1DULL, 0xEEE4C2BDB4686961ULL, 0x296CD7DF1543C63DULL, 
            0x48093217A37F51B8ULL, 0xA37EA82FE876615BULL, 0x79BEEEAA0A813026ULL, 0x5706E4BA319978B3ULL, 
            0xF00CFE9484D4B9BDULL, 0x4C2C631166998D8EULL, 0x6235BC9C042E9512ULL, 0x89B883CD11B956C8ULL, 
            0x87CA553FC0078377ULL, 0x8B5EB8EE8B017EF4ULL, 0x0AB6D981BADEDBB1ULL, 0x8D6C9A9004C5424CULL, 
            0x69C08DABF5346AB8ULL, 0xCAA7225FBA956A76ULL, 0x95C86564C4A5F3D5ULL, 0x1037D17970CFEA02ULL, 
            0x88968CB558DC107CULL, 0x369D168E578A0904ULL, 0x15D3F0787F8C0E9DULL, 0xD08AD7715F20DA12ULL, 
            0x72EF1C27C0487287ULL, 0xF3AF4A27C41A4DB5ULL, 0x0EF2E648FB6A4648ULL, 0xE484FC4660E3F9ABULL
        },
        {
            0x4B620F5D2290ED1EULL, 0xFE7E9253E716429CULL, 0x1504DB39CD77942DULL, 0x064AC44D320BC16CULL, 
            0x25D19D2393C81218ULL, 0x43398C464F92ECC6ULL, 0x017FE843ECC75212ULL, 0x4A2398CAC671936BULL, 
            0xD4FA63DF0CE4AA60ULL, 0xC556E475C71F11C7ULL, 0xD7CD110D6063DC29ULL, 0x753E4788B0EA301CULL, 
            0xCF3222DCFE07E960ULL, 0x0B580560924322A4ULL, 0x84E60E22FC5F3BD8ULL, 0x10401A3988DB49AAULL, 
            0x1D42803B4578DC1CULL, 0x439A3A011E4F151FULL, 0x510DAAB53F926641ULL, 0x9100DBB2E6152C47ULL, 
            0x32FE23C7AD6F15D9ULL, 0x64202AC2AB4437C3ULL, 0x57276783486EA483ULL, 0xF00F3A4EE5DEB8DEULL, 
            0xB6FF2C9EDEA95DE2ULL, 0xE8EA686373682113ULL, 0xEF6F62EE09715F3FULL, 0x6B0A1923F3A0E6ECULL, 
            0x4A0B9FCFECE7A588ULL, 0xAEA8E76151EB78A1ULL, 0x110B195C90A1F647ULL, 0x3FFC5BAC53A78C98ULL
        }
    },
    {
        {
            0xFEFD895F4F2788A9ULL, 0xDAD462DC2BDB5793ULL, 0xB8B65497C8A733AEULL, 0x69EC2CA417C391B1ULL, 
            0xACEA23733FA37493ULL, 0xE14A48F73A605686ULL, 0x427C81F40802EFB3ULL, 0x882A5A80B697AC41ULL, 
            0x57E1F81F90C18619ULL, 0x0334B0CC5447F9F0ULL, 0xA7E73B597AB2F253ULL, 0x5F58BB0A9095B863ULL, 
            0xE2CA5237E84525F6ULL, 0x58CF688EF9CB5DC2ULL, 0x108EB735D9141058ULL, 0xA8EC10567D497C03ULL, 
            0xA88A88BBF4F74C1BULL, 0x7367922AA7F5763BULL, 0x16AC00342EF0541FULL, 0x082BCE621797A93AULL, 
            0xA59419EE6B76A629ULL, 0xD8EE8654466FBB99ULL, 0x9A331E009401F089ULL, 0xD2F6C166EE9FF157ULL, 
            0xD6FBE3BB61BFA43FULL, 0xAD01A007D89F6ED6ULL, 0xCD6FABAE28F19781ULL, 0x988D46C0B5BCE2FAULL, 
            0x579E76221AAEF8A2ULL, 0x85B0E76EBDC1D23CULL, 0x58ADAF0A06C4235EULL, 0xBB067D2EFB3D55A1ULL
        },
        {
            0x00B647D1E714C9AFULL, 0xBE577CF0B91CD967ULL, 0x9AA81F51E6652B8DULL, 0x15CD48426A5B2080ULL, 
            0xF426DD55F9C52459ULL, 0x7ED39BF828232F0CULL, 0x8C47385CD6DD9965ULL, 0xCBC0E8F56A37ABA2ULL, 
            0xA88175F02E56859BULL, 0xDF33A495E0CC18FFULL, 0xE3DB9A0AC5F1C574ULL, 0xC5D6270EDACA0D69ULL, 
            0xB00693A5D8C3056CULL, 0xADFAEF2D8B658659ULL, 0x65A69289F2256EB8ULL, 0x6F989F3DF01F6B3EULL, 
            0x13979DF8D0201103ULL, 0xDBD434518062EA80ULL, 0x000C51EE7FBE9D8AULL, 0x632F118D69BD7534ULL, 
            0x942FED8F6C10ED70ULL, 0x37732CC31CD909F0ULL, 0xC809C1D13BD50BD4ULL, 0x7AC6DE8952DB4D10ULL, 
            0xC4739FDC43A4D58BULL, 0x84445846CF9496D0ULL, 0x6E54AF52CE7128FCULL, 0xA78E734A51751EB7ULL, 
            0x9C8526B3AC8E85D6ULL, 0x765ACA6272EB4F76ULL, 0xD40CE61F3822A967ULL, 0x68F284B5ACB139D8ULL
        },
        {
            0x14603FF706A67C5AULL, 0xF1AAC49E8026F5E2ULL, 0xA83E0042A2A195D3ULL, 0xDD28D156238F9AAFULL, 
            0xB2B76107BD8D2C9AULL, 0x0FC42712DD8D0C53ULL, 0x33D61119F548C8EAULL, 0x286C9C687CCF90D3ULL, 
            0xB3CD29E4E61862F4ULL, 0x15F3AA4E9738B71CULL, 0xC746894EB8FF6D6BULL, 0x8D39300B68E6BCB0ULL, 
            0xAC57DB58725A013EULL, 0x5DC2ED5A569CEC4EULL, 0x10F85FA75367CC35ULL, 0xE81722B32A8A165EULL, 
            0x003EA6CB51A09DD7ULL, 0x0A4DA7997AD1B04BULL, 0xDBA13032B8DF52F4ULL, 0x679D4AA473F9AF17ULL, 
            0x2BAAC31C5077016CULL, 0x4D48FB07B22C14CDULL, 0x979B165B1092413DULL, 0xB1215E1F00BC8DB7ULL, 
            0x5CEF0E97737F62E8ULL, 0x1F9A5BD3EB786D89ULL, 0x80D3F86E4F32846CULL, 0x3CE585D6E54D0B5BULL, 
            0xA5572ECB497FA45FULL, 0x47104521959D20B0ULL, 0x668B178C74985EECULL, 0xD075F8B8188868C9ULL
        },
        {
            0xCFE8A768FD6EB896ULL, 0xED5FC9D308882A15ULL, 0x32E1B70C73330AC1ULL, 0xA1CCA5F8874F203DULL, 
            0x495B50791D2B59D2ULL, 0xC6E9A1A87AB73823ULL, 0xE0A7FF7CB94F7C02ULL, 0xE4B4F1E9121BE549ULL, 
            0xB39EA28EFAD02492ULL, 0x937260CA0F942B9CULL, 0xAFC9EB7FEE512696ULL, 0x0CBF5649D759C68BULL, 
            0xD9E30652BA62D01BULL, 0x15B14ED97638C7A8ULL, 0xEBEEFC0A75C3AF56ULL, 0xE89FA5A60FD04F9BULL, 
            0xCDC464A594E4248DULL, 0xC704F4AE255888E4ULL, 0x90E93F429EB73FAAULL, 0x81FDF0C9498C4DE9ULL, 
            0x827BCBC996904D47ULL, 0x6B36E63B98448D6AULL, 0x7AB496C0F8AD65E6ULL, 0xF2DED972C0F703E7ULL, 
            0x49F9C8BA58973DB3ULL, 0xDF0836212701A3A0ULL, 0x5D23E8833BDF2083ULL, 0xE0EE93A8714DBADCULL, 
            0x235DC728222ECE4DULL, 0x0CC7224A1064F546ULL, 0xBA423440A879F124ULL, 0xD2E6AD1DEDDB9CFBULL
        },
        {
            0x70FE9F7EB168EDE1ULL, 0xC3E7648DDB8DF170ULL, 0x1FB174D57E260006ULL, 0x0F3306A734790F73ULL, 
            0xC08DE6AA1F1595F0ULL, 0x95D02B5B0EA325A5ULL, 0x31053E39FE23440FULL, 0xA8B2F2A4B5BCE6F6ULL, 
            0x6B72E2D35973CAB7ULL, 0x66C87E8551E1DAF5ULL, 0x82E0BC9D6D15461AULL, 0xB66E2A8821C584ADULL, 
            0x0A9E7B6D59028F36ULL, 0x0D27FB4072078DB4ULL, 0x2D54BACDD27AA1EFULL, 0x09AEA4D680AD50C8ULL, 
            0x20CA3C9621C7FA58ULL, 0x90F644697F19FAFAULL, 0xC11697432F9779D7ULL, 0x553CB3F3B2CFE837ULL, 
            0x7FBB7113328C52A4ULL, 0x0C2C7504EB1F168BULL, 0x963BAC4EEA71756CULL, 0xB7233B22BBAF1974ULL, 
            0xCCDB0FC8CA92B86AULL, 0xDAF9BAFDD2BA5AFFULL, 0x5A79D4C22E07A481ULL, 0x84D9F181769EED4FULL, 
            0x0370661507DC7DE3ULL, 0xB7A6CC475E1C20B2ULL, 0x9F56A7B70B18B8C4ULL, 0xE068B54B2822F61CULL
        },
        {
            0xAD0C0B92FF76565EULL, 0x3A529F3E909C4B7EULL, 0xC95F44C3A5B348D5ULL, 0x89532B511C468839ULL, 
            0xAF1555F59A9FB983ULL, 0x1E78BA9171AC2055ULL, 0x5497A2BFC8643DD2ULL, 0x68EDD7219933C29FULL, 
            0x286451919D049B1AULL, 0x92A6106B5FF7AD9DULL, 0xEA65436B4519F254ULL, 0x73192B81F0541144ULL, 
            0xBD3204492A2EE5DDULL, 0x3877989CEBB41BC9ULL, 0x3355EEF1EB36597AULL, 0x4A658E06E9C27E28ULL, 
            0xAE8732D02D08366DULL, 0x5ABDA047B24A7DACULL, 0x06A8B06C6A5B0035ULL, 0x7EE208A10FFDBD3AULL, 
            0x25039D574490DDE1ULL, 0x74AE663A0F3A1FBFULL, 0x5A6ADB9956A3111FULL, 0xE86C9633C211A82AULL, 
            0x511BA6F51279158BULL, 0xCA654AC0B8A70B97ULL, 0x71DED7B3763FCB90ULL, 0xAF6B21D55F176F31ULL, 
            0x81DCB2A783C07CD0ULL, 0xEB9A74ED3EA98329ULL, 0xE285FA2CF9390FF1ULL, 0x0DDBF1BE7E04F5EDULL
        }
    },
    {
        {
            0x7387AAFC70F931A9ULL, 0xC898981125D03C10ULL, 0xD51BEA281EAA553FULL, 0xDF5ECDCCCF450395ULL, 
            0x3B68C53FB484A0FDULL, 0xE54DD18BC8A10AE6ULL, 0x439E55FB9B560119ULL, 0x2F93E66BCDAAAB62ULL, 
            0x2D38F2DA62B0A3EFULL, 0xD3BA99CE77B891CAULL, 0x1F1BB83BB1627AB6ULL, 0x3A7CE944F427664EULL, 
            0xFC374FE1535D9BB4ULL, 0x8EB1336A38768469ULL, 0x998B611F19B14BACULL, 0xB9E49FC522F37D25ULL, 
            0x1352A1814622833BULL, 0xB7EA02AAFCA861C0ULL, 0xB57C22512E27302AULL, 0x7C42E7E86B5F701FULL, 
            0x3DCC9A13909AA807ULL, 0x83A1E2DB0E002DA9ULL, 0x1D638306070B6745ULL, 0x46CE87A0C8EBD248ULL, 
            0xBA7F2EC19F3F9A5EULL, 0x1A7DFF0354F570FCULL, 0x25BF979DC062D931ULL, 0xC0FCC1DEE8A59568ULL, 
            0x5611D2B4A7AF05D6ULL, 0x7F3D3571A4B1AE09ULL, 0xE158CBBC1DD31B44ULL, 0x2D88A2282016A49CULL
        },
        {
            0x06C023AC0DFDA399ULL, 0x61287C9FBBA30C3CULL, 0x521E6372F28B7447ULL, 0x216F7A075E248CA6ULL, 
            0xF443F27F7BD3E437ULL, 0x474006EFFECB63C5ULL, 0x3E673F823789D64DULL, 0x10597230C45BD86FULL, 
            0x829D40505619D725ULL, 0x1EDE8D591310C2C2ULL, 0x7BECB52C0937B33EULL, 0xF612345B5D58CB2AULL, 
            0xF2D2498D5C9D894EULL, 0x207ADFAA7FC9204AULL, 0x23878D30CFD11C2AULL, 0x39BF497190B2FC87ULL, 
            0xE4C1D49FCBFA5A50ULL, 0x4F4ABCDC4D2B8AA8ULL, 0xCA8CBCC98014A0EFULL, 0xC6EFD00DED3BB163ULL, 
            0x4F0D1C75165B8BF4ULL, 0x2E3F0D02780141C1ULL, 0x251D78402F77D278ULL, 0x1843586809BEE116ULL, 
            0x5149CD1D0D7EA889ULL, 0x7F3F1ED327497998ULL, 0xCED01F22CB5E260EULL, 0xA1FC920833FBE8AEULL, 
            0x7B3DA7158B162F77ULL, 0x759EB80A4EB50345ULL, 0x470A2F606030DFE2ULL, 0x8A2263AC7DF6C2F2ULL
        },
        {
            0x87BD87C207A25181ULL, 0x27C67F3277E89D99ULL, 0x3409BC532D4628CDULL, 0xE46B8DE052C2ECB9ULL, 
            0xE973D6C6A518D504ULL, 0x64F1FD048CCFC5B8ULL, 0xA82A708588F5AA23ULL, 0xA56F864ECBD04FBAULL, 
            0xE549D180455C115FULL, 0xA230237C664782C8ULL, 0x8B91A60AEDCC28BFULL, 0x6DE7E91E8736405AULL, 
            0xC5E6B3EAFE51E5A8ULL, 0x00E4BC1FB5BDFFE5ULL, 0x8DF73DBE47E7DE9FULL, 0x8AC29DE51B3D383AULL, 
            0xE22F4C3CCE5D693DULL, 0x2C4A8C23A5E8D6DAULL, 0x5C47D96CE4CC6E7AULL, 0xB6C4ED091936313DULL, 
            0xCB21EA5715C8E453ULL, 0x2A665123047EA55EULL, 0xE5A4738EB8EBA74FULL, 0xB5AAE186365E77E3ULL, 
            0x43E2A351C2161102ULL, 0x1625A0160D866374ULL, 0x2706F224D5A6FBD3ULL, 0xE05065DB4B954867ULL, 
            0xB8C8D86631513D03ULL, 0x61CE4668A66D9744ULL, 0xEA5CCD10E313B411ULL, 0x0C6C0B57B8D8AE1DULL
        },
        {
            0x68CDFCF1029F092EULL, 0x79F8561E201BF2CEULL, 0x26CCDDB77E61A984ULL, 0x9F51A3A9AA270590ULL, 
            0xA5593B7042036BF4ULL, 0xC3220EF33728F5DAULL, 0x37E1A51F84991C0CULL, 0x8C09701DA9050673ULL, 
            0xC87EA6F209C1D439ULL, 0x46F666F2C3EBED07ULL, 0x9AD5009DC3B48ECAULL, 0x090BF15ABC6B48F1ULL, 
            0x856D63BA570BE393ULL, 0x1BD841FDF8F6F17DULL, 0x38FA1BD4BFB6BD18ULL, 0xCD4C4FAF8AFF07C7ULL, 
            0xFFEFCA1331168ECBULL, 0x802B42BE1E619DE0ULL, 0xADAB9FAED203C9B2ULL, 0xD6E53E46A7B021EEULL, 
            0x062B7A08F0D0560DULL, 0xC9B08DF4526E635FULL, 0x6C92F3B1AA1E1FB5ULL, 0xB726D3E82B4539C4ULL, 
            0xDD95FF3C4034F811ULL, 0xD2556E22001C94AEULL, 0x7FA2CF0A5F77265EULL, 0x4CA328A473511D5DULL, 
            0x89ADA5B1DFA4B39FULL, 0x1F4235772DAF41DDULL, 0xDAAE20E3ED53CA95ULL, 0xD99DC738219EC333ULL
        },
        {
            0x04113DDB94CA774AULL, 0x485B23EE6D728901ULL, 0x7E7FC4BB38107385ULL, 0x38F0538C28F06AF7ULL, 
            0x4937141E92A303CDULL, 0xE06660580CE5AB40ULL, 0xF043E56CDBE5813BULL, 0xDE368623D58F37A6ULL, 
            0x6C98ABB647F7FB18ULL, 0xA2487FF61D5586CEULL, 0x66446E7D2E97EA52ULL, 0xBD9EE2DB5724560FULL, 
            0xAFEC4D3BD4207A05ULL, 0x716444CA574E3EBBULL, 0xBF65FF7EC370EDD7ULL, 0x92B3E2B0E2F72018ULL, 
            0x0331DFEABCD15D74ULL, 0x09B4C63DEB58291EULL, 0x8DB1BC608088BBC2ULL, 0xE7327DCB6F7FD60CULL, 
            0x4AE6ECC768E4A2B1ULL, 0x99F517F32E422377ULL, 0x8D62639509B2735BULL, 0xC3FC8694261D5A24ULL, 
            0xF78C5C8000FF5A07ULL, 0x852CD946F463FF8DULL, 0x8A498BB3A7629017ULL, 0x05CC1F19979B1266ULL, 
            0x42BD9E7ED79F2A24ULL, 0xE7D610687FCC2487ULL, 0xF9D54A1C046D6FCBULL, 0x46198BBBF9023B82ULL
        },
        {
            0xDC30952DE2B66F0FULL, 0x08A132ECCD844BA5ULL, 0xC85BFDF87BF326ABULL, 0xC0FD7EC4C4E5E29FULL, 
            0xFF2A4B5FA7A1B1BCULL, 0x7603FB1F0936EF7AULL, 0xD9F7B346BC29785DULL, 0x98371693E82FA09DULL, 
            0x4D48E1959BE21812ULL, 0x1C9EDC9F7EC89D1CULL, 0xB5419CF82C6D8468ULL, 0xEAC5D5CB8799DDE5ULL, 
            0xF117DE6F4725F955ULL, 0x7127DAF235250210ULL, 0xF532034B9D950CDBULL, 0x9E85124A7ADE5B03ULL, 
            0x61EB49F4709D629EULL, 0xF55EAC48338ECF25ULL, 0x9EA6E2C8C6677ACDULL, 0xA193DC2E5B03DE3DULL, 
            0x68F5BB53E3734642ULL, 0x285D4ABB5254BB61ULL, 0xFD4AD90DAD9D9770ULL, 0xFD7D3BA1C3D94141ULL, 
            0xDE3757688404F24BULL, 0x397637390DF75235ULL, 0x79B2A60D8FC5C5FAULL, 0x4DECEEBC7B593B37ULL, 
            0xBCB7101A7E0AB8BAULL, 0x4CC9B9E2923C9243ULL, 0x98CF670EB0C880DBULL, 0x9169614AF7728990ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseAConstants = {
    0x7F95ABD5EA412E03ULL,
    0x4812F431EE77C7A1ULL,
    0xDDF543E4B5A7542CULL,
    0x7F95ABD5EA412E03ULL,
    0x4812F431EE77C7A1ULL,
    0xDDF543E4B5A7542CULL,
    0x0C5032FC17572223ULL,
    0x917E58B737C371E7ULL,
    0xB1,
    0x6C,
    0x90,
    0xE2,
    0xAC,
    0x47,
    0xB2,
    0x3D
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseBSalts = {
    {
        {
            0x6BB7A67D84F7C1DCULL, 0x058F4B001BA8A2D8ULL, 0x1C6C100928B785ABULL, 0x2F08732178AE3826ULL, 
            0xA4D286E7098F291FULL, 0x9E135E193CB64413ULL, 0xEA578811066C6960ULL, 0xC8A5E7E78620DA35ULL, 
            0xE077A858CC61676CULL, 0xF64F6CA542797CBAULL, 0xEBF07F7CF51936D7ULL, 0xAEBD26997A92ACBCULL, 
            0x4ED1082177215F56ULL, 0x3DD72E7BAD67EF7BULL, 0x975E00796D25B666ULL, 0x6FB69821155D2CE7ULL, 
            0x2CC49E89F2000E03ULL, 0xCE5F32ED60AAA824ULL, 0x7053935463DEB6D1ULL, 0x212846B3D4E57C65ULL, 
            0x8C0AEA8EE2B0F987ULL, 0xCEBC5325EA76DC91ULL, 0x44073A9EA11617FAULL, 0x863E85C0B2D7A8B1ULL, 
            0x02120D6FCD498113ULL, 0x5B6DA61E2300AB5EULL, 0x28BA1BC3E081E314ULL, 0x87611117230D677EULL, 
            0x3ED9A5747D42EA9AULL, 0xC32766B904735626ULL, 0x544D0D9B2C690525ULL, 0x9B80E4AEF0271061ULL
        },
        {
            0x1A4B95BB3CB4A5F1ULL, 0x1474277D722C0E2DULL, 0x303949C5593C4261ULL, 0xEC3E9A1498873990ULL, 
            0x344BEA7EFE2EA1DAULL, 0xB41DE363C0D3B0B4ULL, 0xD557432F8180206FULL, 0x1CAF09EF3922D190ULL, 
            0x28F42407DD2944C2ULL, 0x131A26C565529521ULL, 0xD3EBB84554C6361DULL, 0x743E4C7B551229D7ULL, 
            0x7CE50ADE83DF0627ULL, 0x08606431DDD82E0FULL, 0x24DB27374570D459ULL, 0x155623457BF7AF2AULL, 
            0x75C801C61AB42335ULL, 0x57AD63621F91796AULL, 0x422220E7351ACA6DULL, 0xAB959C74F3173524ULL, 
            0xA7BB198FF23474E9ULL, 0xBDB3700FE59BA1FCULL, 0x2AF75E0B98BAE47CULL, 0xE521BF63192D162FULL, 
            0xEAF0570834C6485AULL, 0xA099FC7E602DA828ULL, 0x800595785D6770DAULL, 0xF5BF5F2AD8416DC9ULL, 
            0x4B6469C1954EC867ULL, 0x887F3A4FB0D6BD8BULL, 0xC980435651FF8E1BULL, 0x502464A78555C3A4ULL
        },
        {
            0xC3D4FF05516656DFULL, 0x62A294A77C7D0375ULL, 0x47D4CA06513B4E6BULL, 0x16EDA860EBB39CDBULL, 
            0x54453BFBD0A33455ULL, 0xCC9C3ED69E3B8BDBULL, 0x8290564F57746E7AULL, 0x0E0900A1493C4840ULL, 
            0x6E815F5D33DECBF6ULL, 0x3564838F6C2251EBULL, 0x5231725FBD5D79F1ULL, 0x10BF186ECBF0A74FULL, 
            0x0D62C9E74EE54A2AULL, 0xBD2B3D9813404023ULL, 0x7A320043657DF7DFULL, 0xFFA73219E0E12F99ULL, 
            0x6F09FD92B16F6788ULL, 0x046AFAC65E240306ULL, 0xADED5F98F8678042ULL, 0xDAD5D89C5D13B889ULL, 
            0x30F829BB615C962CULL, 0x1E9718543C85D3EEULL, 0x8DA4EF408A4FDC36ULL, 0xA2AFF3586D33B356ULL, 
            0x65FE53B85FB3042DULL, 0x659E7D70B52B70BCULL, 0x6FF0949264BDB5DEULL, 0x24946D1FAA69EE6EULL, 
            0xBC61F5FF6FD9D686ULL, 0xD550B02F90E8EC70ULL, 0xF7A110CCA0854665ULL, 0xFF5F123AA3604ACEULL
        },
        {
            0x48F0C4D316883AB6ULL, 0xA7CF0FA76C4F2DB9ULL, 0x59B58445BD17F59BULL, 0x743A5455B4F846D3ULL, 
            0xF4658934A4DD3F5DULL, 0x54712945CC021A74ULL, 0xD8F46A4C0A0E6932ULL, 0x723DF6C04CEB3C95ULL, 
            0x33FC25BA9E59E1D1ULL, 0xDCC57F1AC7BBBC36ULL, 0xCD3B75CF7D6771E3ULL, 0xBBAB0031DA308DC5ULL, 
            0xA838D6DA732F81E3ULL, 0xCB58EC518C01E417ULL, 0x0828806242C4A6C3ULL, 0x661D42C47A367B5FULL, 
            0x713A059A4D37E93CULL, 0x9A13E1FEB4AC03B4ULL, 0x9F8BC5B7E470AF43ULL, 0x48266124E9723CBCULL, 
            0x8C81C0A53931D3ABULL, 0xB883BD0C0383C05EULL, 0x146E4803788510E8ULL, 0xF76E13C06D8507F7ULL, 
            0xD770C6F879619FFBULL, 0x57A99C0B67CB2759ULL, 0x8F6F4B042379F4AAULL, 0x3B563EA09D21113FULL, 
            0x5A6DCD9DC515F18CULL, 0xC813FA6A36C66807ULL, 0xAE9AF516E0366B1FULL, 0x611D18AE2C533D56ULL
        },
        {
            0x65AC54A127503F98ULL, 0xE43AF824BE0B3C53ULL, 0x4022BBA174F92ECAULL, 0x198688B0B510FD6EULL, 
            0xE773C8B3D8BB5FF4ULL, 0x9990C65B73E56034ULL, 0x5AD1006F2A036A1BULL, 0xE1B60463DCECAB46ULL, 
            0x21DBB1A1848705B0ULL, 0x4E8667941634A086ULL, 0x33AF803CA1460E55ULL, 0x7F1337341917C822ULL, 
            0x12CE447C6B2E8BB6ULL, 0xCB45E80505696061ULL, 0x44B72A106AE994BEULL, 0xAE1339E75476BED1ULL, 
            0x85EF90B29FF4CA84ULL, 0xEAB437DA4A9D0CB5ULL, 0x98C3AC0F25F6FC46ULL, 0x1CA4702ECDBC64BEULL, 
            0x4E1C0BE96B9A07F8ULL, 0x956DF317A51FC7AAULL, 0x7734F46768D8A1C7ULL, 0x978089E87094A1FDULL, 
            0x8F484BA739DC0FD0ULL, 0x830547517A21EE7EULL, 0xBFC60D9A675D4AB6ULL, 0x8A504DC69A985515ULL, 
            0xD68FB8A1A73E09DAULL, 0x26043E66155DD6F7ULL, 0x12BFC7E9E93D1FF8ULL, 0x0B76A17028EA8667ULL
        },
        {
            0xE6D963435AB89B31ULL, 0x256919B5F31BC1CFULL, 0xC86A0B41151CA4BDULL, 0x1F1CE2ED0E747C80ULL, 
            0xE4E7978374BE3D90ULL, 0xFCA9227010CED924ULL, 0x5C15D377580AEF65ULL, 0xDFFC9B584B82BF7BULL, 
            0x6884805F7223E1FDULL, 0xED8B856868617DC9ULL, 0xBD860792726ECD45ULL, 0x0F671F9BB1CB1751ULL, 
            0x5486C6C1DA8F3D32ULL, 0x139954FE179483B3ULL, 0xFC52B9915E91D8FEULL, 0x354736F617143F18ULL, 
            0xA35AA627D7293418ULL, 0x0BC3CB024E0D0675ULL, 0xC6872A0622E39781ULL, 0x9891540A44F153DCULL, 
            0x10388CFE1D290EB9ULL, 0xB56B544418C632DCULL, 0x967B0EC6F0D413D1ULL, 0x986B5EDAFAE7727CULL, 
            0xBF5EDACB2BBD7EEEULL, 0x8CB573F1094D0C4EULL, 0xA65F1A0C974862B6ULL, 0x2CE42293EAD42ABCULL, 
            0x43C0F60813CA9BB2ULL, 0xAE3D5E14F60CBDEAULL, 0xB15E866CD70ACCEAULL, 0x498DBEA1C1DC0E00ULL
        }
    },
    {
        {
            0xAC48EBA2D1D75BCAULL, 0x3FF421A3CA88C49DULL, 0x7F19677557E1FEF6ULL, 0xA3C88A5DA450A7A1ULL, 
            0xF0C1CC6769E15468ULL, 0x7648D5018B7B8D7BULL, 0x6327C093B9B4B87DULL, 0x05A0810C46D67F29ULL, 
            0x68A25362A5E1A632ULL, 0xDBFC90ECDF2EA628ULL, 0x6D0BD36CBA3F2EE1ULL, 0x9E0650ED89DD932CULL, 
            0xF3E987C1D8793E0EULL, 0x6C01F7C9A1065210ULL, 0x5B1905D4C8FFF2D2ULL, 0xAF0C5D16B9AFC76BULL, 
            0x322D5DF01F3C3C44ULL, 0x78F3011F503324B7ULL, 0xAA5316DF09CAAD0BULL, 0x79116A207C2A94C5ULL, 
            0xED0F9531D5A9C983ULL, 0x51500109CF445DAAULL, 0x76D24714AF5AC934ULL, 0xBA3C5EF9226981B3ULL, 
            0x6A13574D29A26352ULL, 0x891B2B2DA7F39A3BULL, 0x88EF0D677882C7F1ULL, 0x4C68097DE3D281E0ULL, 
            0xD791D5C16775A1A5ULL, 0xB01BDEBDA864131CULL, 0xDC1802DFF6665F34ULL, 0x75CE67220B55A14FULL
        },
        {
            0xC7CF83B965583F29ULL, 0x09C1A41D7C347B7CULL, 0xF8E8372A5D62837BULL, 0xB9714D35BEE2B833ULL, 
            0x9CB8B1B033DAF7AAULL, 0x238143FEB91EFD49ULL, 0xE21124EE40D3D9FFULL, 0xB1153E9A7D325857ULL, 
            0x4D96139D94733FEAULL, 0x765114F4C33E196FULL, 0x3A85F918C131899AULL, 0xF2A08A99797642EFULL, 
            0x2AA144109315B6AEULL, 0x252052B476459AEFULL, 0xC8B628403950E02EULL, 0x3A2A3E14102A83AEULL, 
            0x2015AA36F63165C1ULL, 0x5CCFC670E05B2B0BULL, 0xE696954E1F19F526ULL, 0x2A55D51F0A9590C3ULL, 
            0xAE759E1CA025942FULL, 0x786B028029412905ULL, 0x90E35C90A0335476ULL, 0xEC4448E6D6FFBA54ULL, 
            0x6CF7A018F6945257ULL, 0xE879522622881E88ULL, 0x875FF28EB9F619F1ULL, 0x766A7DFEF02E484FULL, 
            0xC43015809F795437ULL, 0x026E3BBE07F3DDE3ULL, 0xF9A8A64FCD65FFBFULL, 0x9B0A2CBC9E9DF342ULL
        },
        {
            0x0A34DFB2D580E9AFULL, 0xD0B92DAFFDCEB91CULL, 0x40224891788813A6ULL, 0x9DD8031588AF16A7ULL, 
            0x462AB8F3F80ED482ULL, 0x1693E02B35D4CB33ULL, 0xF8490E9D8F05A0AFULL, 0x22592D76C63736E6ULL, 
            0x86768842D21CD3A8ULL, 0x63BC0C50B9E768ECULL, 0xBD0B7BD0912A5ED2ULL, 0x40EC1E5EF8C29BE6ULL, 
            0xBA705B82693E9A97ULL, 0xC314850CB9AB9774ULL, 0x120E54675C8F4654ULL, 0x39C82C1C37D4B545ULL, 
            0x0800BC6CBB4B0209ULL, 0x73C90CDFDDF711A4ULL, 0x9D3A0C6C96790507ULL, 0x0371FE96CE61670AULL, 
            0x8BD06CCF4890EA66ULL, 0x90F8C23B96FA86CEULL, 0x0D7FB5EFE7431BE7ULL, 0x40B90862AD6F5DB4ULL, 
            0x20C98B6BA7F277D5ULL, 0xE41B65D2EC688A39ULL, 0x4F8815DE90281926ULL, 0x7EE1E942196FA07AULL, 
            0x7BA485265C0A1E76ULL, 0x7C41F9FB3C5EBECBULL, 0x5FD465A0F4DB78ABULL, 0xF2390C9DB81E43CAULL
        },
        {
            0xDE318A728121D551ULL, 0xE987FD0CA53CC377ULL, 0x0BAC6D022AFCF64EULL, 0x8DCEA3F2BCF2EB3CULL, 
            0x47714C7EA2B4C35CULL, 0x86615DDDEC97F3A6ULL, 0xF582F6921A1FA5EFULL, 0x503CBBA36878FB14ULL, 
            0xF69AFF561765B236ULL, 0xD12A099C40754820ULL, 0x9BEC04B445FF43E6ULL, 0x51BC89F81E37AABFULL, 
            0x99167728211C1772ULL, 0xC9F0707DD84A13F1ULL, 0xE6DA654686031AD6ULL, 0x5D61CF7A3FA496C7ULL, 
            0x9D44571645FAFEFAULL, 0xB39F481895880E9EULL, 0x9BEBD07F5AF89200ULL, 0xB15B045ED254A19FULL, 
            0xE0133458BC4A5D6AULL, 0xD2CAAA48C6CF1619ULL, 0xAAFBEE2A9EA7F437ULL, 0xFB18A13542A4AA1EULL, 
            0xAC5D38857E08B276ULL, 0x5FD97A98D86467FEULL, 0x7DB5D699A1B4392EULL, 0x61390C1A15E0A8A2ULL, 
            0x1EB6A7E08513B60FULL, 0x5039528FBFFC2599ULL, 0xAF1FC175A6346964ULL, 0xE4D091900392EA09ULL
        },
        {
            0x740273D52EA7B731ULL, 0x44F13D074B2971CCULL, 0x4A08289478F4EE2CULL, 0x3B2C3BBB31EFAA45ULL, 
            0xFF70758760F16F30ULL, 0x64E5BE609D92CE25ULL, 0x2148531C783C392CULL, 0xD9AD77C5DFB926A7ULL, 
            0x57667542A2A1AA19ULL, 0xD679AECD5AD3D119ULL, 0x1831BA4201CAB23CULL, 0xD63D6060A092C669ULL, 
            0x568B27CDE578CA11ULL, 0x6E24231CC481DA5EULL, 0xF9E27766D52FC8EAULL, 0xF7CE9804871C3238ULL, 
            0x0994B8569DD65343ULL, 0xFE62EFB4542308E7ULL, 0x4F40285641E326FEULL, 0xFB314A8D8699C172ULL, 
            0xA922CD514A38806BULL, 0xC1A25DFC1BF139E7ULL, 0x644AE26103F461E0ULL, 0xF5A66CCDC8CB552EULL, 
            0xFA9131D788B83B3CULL, 0xAD3A0ED7B4026213ULL, 0x818C5BB9592A6CD7ULL, 0x076AFF6A6D1EB9B8ULL, 
            0x066482FFAE0A2E1FULL, 0x0F1E674CCC6B835AULL, 0x83D95E6CCFFFDBAFULL, 0xC0EBE535515ABB7EULL
        },
        {
            0xE34D3D51C12C78CAULL, 0x906A77F1DD4BA106ULL, 0x8B28F167216DD8E5ULL, 0x9CD8BBB1FBF61D14ULL, 
            0x9B24F3135DA3DFBAULL, 0x498CFBF1842549CDULL, 0x7C322CFB4EC9D7A8ULL, 0x878451B124309F02ULL, 
            0x90DAA561D41925A4ULL, 0x71D88DA9BB8E4A30ULL, 0xE656FC38AA6B9DDEULL, 0xF38C8AC32DA4AC42ULL, 
            0xF68ABB18FC30A826ULL, 0xB97DD56A5388B5FBULL, 0xC7131BFC282CB585ULL, 0x6E49EBBE62622791ULL, 
            0xCF0893C2DACB3918ULL, 0x804C85E424245826ULL, 0x8FCE1738DDF33540ULL, 0x9D9BAEE65FBF6E83ULL, 
            0xD158466FBBBEA1E1ULL, 0x5408129CD9761CA3ULL, 0x5CEAE0264E98053EULL, 0x9B57D0F360FAA58DULL, 
            0x5BEA497396B034F3ULL, 0x1D018177739AF226ULL, 0x4CC24BB0EE5C9F00ULL, 0x0D96B755D53BCF74ULL, 
            0x368C803829762E91ULL, 0x75F3126D5F30CCC5ULL, 0x91DDC030B731FCF3ULL, 0xC048ECADB26A55FDULL
        }
    },
    {
        {
            0xDEFE391142180E11ULL, 0xF466A95487677B5CULL, 0xE0E514119AC719C3ULL, 0xB3A4CA3ADE4AFDE4ULL, 
            0x12370BFF5868225CULL, 0x5970C811B11A65EFULL, 0x996A5DFE31909337ULL, 0x96B4AD6CFACFC8D6ULL, 
            0x1AEB34CFB2127228ULL, 0x72E7EC3BD622F1ACULL, 0x3C6C796F7465492AULL, 0x22AB5784BBFF904CULL, 
            0x886A1D0A3CD78B7BULL, 0x792DC741302D8F71ULL, 0xAD3F383A8E701767ULL, 0x85228DA9DA0FDDFFULL, 
            0x569D7F2E5B06ED72ULL, 0x76AFAFD73D00497BULL, 0x208D4DA60D63CC19ULL, 0x35C3CB9306615412ULL, 
            0xB12EFD8C0C59CAEDULL, 0x429506E28AD8C29CULL, 0x626857994D253220ULL, 0xF0CAA2CA1A7CDA59ULL, 
            0xC49D8836A74501A7ULL, 0xAE0EDFC1A176F90BULL, 0x0C23EED871A24ACEULL, 0xD9D379CCDE423914ULL, 
            0xFA637EA401CCB610ULL, 0x6B6C696F92349225ULL, 0xD402E57A731C91AAULL, 0x06E2A29A424E2FDEULL
        },
        {
            0xC665AB0AF6E451CCULL, 0x01F82BF2874469C0ULL, 0x10583F266894C59AULL, 0xCA18B652FFCD18BFULL, 
            0x3034DE57FB499904ULL, 0xF25F1D372ED5B992ULL, 0x8061A0AF80686C72ULL, 0x72A3786D4C2ECAB4ULL, 
            0x2E05DF53C34E597CULL, 0xA6DFDFE7C2CC3693ULL, 0x13FEDB96E27765EDULL, 0x9F8B2FC6442CC96EULL, 
            0x41F2C4F1A5533EDAULL, 0x3C92E6FD71CE83DCULL, 0xB8699E0B094020D1ULL, 0x70EB9DC5AD90F819ULL, 
            0x91664987E8F08267ULL, 0xD93A00BCF73A553EULL, 0xDF1F7C12B73BF146ULL, 0x573A95F34EB2C55CULL, 
            0x575D8CFD3DA9D39EULL, 0x692472AB59FA195FULL, 0x62E01BCEB3FC629AULL, 0xE9C3AE34F26834DDULL, 
            0x67D1824AA1F0C34AULL, 0xCC03BE63771CCC60ULL, 0xA4767C227CB9A154ULL, 0x70CBCCF356845512ULL, 
            0xE6F68782104DA178ULL, 0xE24E98EB8DFF0399ULL, 0xDB3A8ABAED9F9451ULL, 0x817439C37D41B04BULL
        },
        {
            0xBACA22C9A8BB6116ULL, 0xEEFD7AD9337E3FBEULL, 0x46483658113CCAACULL, 0xC1242A2515772E92ULL, 
            0x7851F9689728D2B7ULL, 0x82755EEA27807B19ULL, 0x7933CE0D654A0146ULL, 0x10EA7B7EA9D42090ULL, 
            0x945E2E1D24A6EC6AULL, 0xA9B5426FD3E89117ULL, 0xC02C5AB1B783F52EULL, 0x66D591A0A6F3F7BAULL, 
            0xBB14B80F3FFB3B8FULL, 0x1CB73880D4501F10ULL, 0xEA6ADF0EAB25A3F4ULL, 0xBB267009ED2E93ECULL, 
            0x303467BCB2FBA45CULL, 0x5094D32B17253011ULL, 0xB002AB18CBBFEBBFULL, 0x0E53FE50373C67AAULL, 
            0x5EF7A4D7B2745D88ULL, 0xBF5A709CCD247ABAULL, 0xBC36EEF7870137EAULL, 0xE99D6D62E3591EBBULL, 
            0x9C85863606DA40DBULL, 0x93EA693D1A912D39ULL, 0xC1BCBC080411442EULL, 0x1F86187329E383D5ULL, 
            0x47EC4936D12F14B4ULL, 0x1B957A3DA4709EDAULL, 0x361601FD6D0F038DULL, 0xF588FDA26604781AULL
        },
        {
            0x5BBBB1DEAD86AA00ULL, 0x68D834DC4A405FABULL, 0xA1A65CA4ED17EEAEULL, 0xD22EF35F455AA2B0ULL, 
            0x4B9F246964ABC6DCULL, 0xEF9DCA84731F75B3ULL, 0xBC7FD7F58FE97D71ULL, 0x7964AB09E3D4EF13ULL, 
            0x84D2AD6FB5CBD038ULL, 0x06724FD0835E8390ULL, 0x4334FC430598CAB8ULL, 0x453091F5A8015C95ULL, 
            0xEC52C480CC5E5F79ULL, 0x0CAC16AACCBC67FBULL, 0x1ACB74EEAE6D9ABBULL, 0x6DF76A9B7A7941E1ULL, 
            0x287C051B6654179FULL, 0xBFD51C47A646B74CULL, 0x0D475D460E1A7D42ULL, 0x838CFF7A5F80960DULL, 
            0xCE09FEE4587964C2ULL, 0x79DF713CCDEBE70BULL, 0x1C2B54F1D709BA7AULL, 0x0F3FD9498168B4D8ULL, 
            0x00B070CB08B78557ULL, 0x8AEC7C95A4530C0FULL, 0x78561D6BE6E90443ULL, 0xCEA919DB095BBF6BULL, 
            0x04B0E1D20E4EEB0DULL, 0x89A0C9A47A4408D6ULL, 0xDB546ABC827E64F9ULL, 0x67F00949B881428EULL
        },
        {
            0x64B72AD17036D044ULL, 0xD0A4957CDD0F1D58ULL, 0x0BC507136222BEACULL, 0xEBF263623C1A4DD8ULL, 
            0xBE35D8C4C0E5DD9DULL, 0xEFC4FF368D2FDB1FULL, 0xCE7C01CFC835EA85ULL, 0xC48E6305936CDC09ULL, 
            0xAA65F4F0A8D43DE4ULL, 0x32BCA1165B2BEFC2ULL, 0xB2C54AC41736432CULL, 0x384F72292B60D824ULL, 
            0xCFBFD40CF16F09EAULL, 0x2B0C42EED35C865BULL, 0x526FFD4DA32A5775ULL, 0xAB7234E5A36E3C34ULL, 
            0xE6AC79751E9F8830ULL, 0x99A12C788C4E3415ULL, 0xDFB5F3554DD7F965ULL, 0xBA7F5F266AD88800ULL, 
            0x20131DF26F02D6A7ULL, 0x66BBF5DBBE0B3FAAULL, 0x4F3DC8D028230448ULL, 0x9AF8159D8B9723E9ULL, 
            0x23FED44679699681ULL, 0x81AE2E17733DACF4ULL, 0xAC137AE62F95AEE0ULL, 0x0FD075C0686A54DAULL, 
            0x42E5CC3F0AFF1E14ULL, 0x49C39DE28D273002ULL, 0xAF3FC93AE2DC5189ULL, 0xD262D6DD778E0761ULL
        },
        {
            0x1116F14BD3D10C0FULL, 0xC292A247D2166B05ULL, 0x8A5DAAF8C8E49BB4ULL, 0xBB4E72B94E40D393ULL, 
            0xB7EC0118D553162CULL, 0xC43E83B7E8DA9FF6ULL, 0x309E098130F71A72ULL, 0x0830CC99FD70F8B2ULL, 
            0xBD6BAD9B2F3327C8ULL, 0xD8817A1F57C86FD3ULL, 0x5D5FF2AE93EB2467ULL, 0x83939BF88BC9DB66ULL, 
            0x96964E407FFA715AULL, 0xEF1A8941B687A513ULL, 0xC868487295073608ULL, 0xF77CCF3F78CDAF11ULL, 
            0xC8B90233467CE930ULL, 0xF0BEA95988D4AADBULL, 0x0EF30674F8069EF0ULL, 0xB2C6DB751A78442CULL, 
            0x870427A5589ABBE4ULL, 0xF4E43BB7843FC829ULL, 0xB5ABCD81882CA0FAULL, 0xC3B163ADB2B0A62CULL, 
            0x0F0D2D1481FB21CBULL, 0x3B5B0E10E1E92B0BULL, 0x13ACA1B744B3170AULL, 0x34FDD1ACBB04F0DBULL, 
            0x38D7DBC3C2AA9A98ULL, 0x32222502565042BCULL, 0x24724ACCCCD5D47BULL, 0x9FDC6B8CC38C1AB4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseBConstants = {
    0x029CA2548CC1D210ULL,
    0x207AF44C0DCF8970ULL,
    0x85FB069E931EAE06ULL,
    0x029CA2548CC1D210ULL,
    0x207AF44C0DCF8970ULL,
    0x85FB069E931EAE06ULL,
    0x2B97BE4D342FD3A8ULL,
    0x924F0F0D24FAFC47ULL,
    0x38,
    0x56,
    0x3E,
    0x6D,
    0x72,
    0xC6,
    0x04,
    0xE6
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseCSalts = {
    {
        {
            0x8BEB530414157D4CULL, 0x54343B5671E45124ULL, 0x92DD4DC9FF204FCFULL, 0x0845DF5C75727598ULL, 
            0x6AA210697AAD82B1ULL, 0x6BD2CD84AE3AE9A8ULL, 0x62922E243D95E212ULL, 0xA6D518485D335760ULL, 
            0x91E10E3D4821D54EULL, 0xDE0A39FD69D28A70ULL, 0x4DA80A0A4BE6B4B6ULL, 0x4CC90C17477246FEULL, 
            0x904433EC39DB21BDULL, 0xA2393B87D13720CBULL, 0x7789B61C25D58E69ULL, 0x48A7C60F426A1EB8ULL, 
            0xC253DE2A0D26F5C3ULL, 0x2D91B6D4CBAA3F5FULL, 0x3346B807CD80011BULL, 0xDD2F30AA14736DF3ULL, 
            0x1FE3998AAC6F7DF6ULL, 0x26B25A778B49B5A7ULL, 0x3AF375E72C81D93AULL, 0xFCB110B8BEAFF923ULL, 
            0x383E4BA09607C112ULL, 0x7C3FFD61DC876B96ULL, 0xC64951E4A96DC072ULL, 0x661F35F86B67300DULL, 
            0xD8E754E2B9E25627ULL, 0xDE3BF714903E36BBULL, 0x1D079F164F1C0236ULL, 0x712370FF2496FF7FULL
        },
        {
            0xA2C90441117F01A9ULL, 0x65FF6C938AF17509ULL, 0x88EDA94698F2EB44ULL, 0x15148BF677516F55ULL, 
            0x75BB2F38E1AF2FF7ULL, 0x6C8D00584911AEF7ULL, 0x5BF77FD8B28D7289ULL, 0xAC2D71AB8155996BULL, 
            0xA39F909B2C26EFBDULL, 0xD1DDD8BAB64FDF98ULL, 0x71F24C5C6FA90932ULL, 0x163D3F143A2B15BDULL, 
            0x44F56F5623B372C7ULL, 0x576CF3F6A3F6091CULL, 0x0BCF770D696A2D87ULL, 0xB8D0985997895264ULL, 
            0xC835613237F49792ULL, 0x6E1E79ADB0AF22E5ULL, 0xC912527DD90ED707ULL, 0x358B74BD245DBC67ULL, 
            0x2DC2B76EB86118E4ULL, 0x9A5161CC04CE710CULL, 0x0DAB03AC9A3FAAABULL, 0x2408441C1E5A29E7ULL, 
            0x0A07F60D588065E7ULL, 0xD44D5579ED714BBDULL, 0xAE61F4BBCEAFD23FULL, 0x45C99E02803EDB6AULL, 
            0x27A5BBCDC9FF1331ULL, 0x9B76A5A5F095A0A6ULL, 0x78193F50886B2165ULL, 0xE8F8CE4F719B56CCULL
        },
        {
            0xBE8684887BD819D4ULL, 0x2EB58C81A16D4899ULL, 0x1F95A74056265018ULL, 0x6C8EA022B3917913ULL, 
            0x68DF56D377570A75ULL, 0x9CC3A969CE9099F4ULL, 0xE5033D86804DF79EULL, 0xE6C0404B69F78C3AULL, 
            0x44F905281A525AFBULL, 0x2BFE80FEF6FD51D9ULL, 0xACCF155E15A6AE1EULL, 0x88E79E277E9F1DB1ULL, 
            0x7D88943CAE3958B0ULL, 0x9E8F0EB5B8D74686ULL, 0xD6D44C9DC67E34E8ULL, 0xE1B60A680CD2FBD7ULL, 
            0x6B3401F35A1E354EULL, 0x12E06B9C2A9C5FE8ULL, 0x6AEAFCDAE5F91FCFULL, 0xB3A8C1A68EBEC0ACULL, 
            0x80B32E02456BF6D1ULL, 0x548CD0311C457A46ULL, 0x25F4E23C6A5DD696ULL, 0xDC6EF20CC32D9C8FULL, 
            0xF29BB233C195206BULL, 0xC047FA7DCB1426C9ULL, 0xB3F46D11B7587B17ULL, 0xD47C9FB28E48B36CULL, 
            0x4AEB8A139258529EULL, 0x0C383872F72AED5FULL, 0x92370FDAD569121CULL, 0x7F644047BA8E5105ULL
        },
        {
            0xADAA06C60F651E6BULL, 0x4AC65288BE4E57B6ULL, 0x457C143A033D232EULL, 0x60B512DAF4552A63ULL, 
            0xA3A59A13EE46CD78ULL, 0xA71BB4D4B60FA5D0ULL, 0xEA38F1E8DCF82DCFULL, 0x65F9D325EB70BF2AULL, 
            0xE0339D71B98B8FDDULL, 0x3766A0A84CE3BC7EULL, 0x944099195D1BF217ULL, 0x2B8F955B08E1226CULL, 
            0xE11E97575AEF1AC8ULL, 0x8DDF78CB1F1DEE7BULL, 0x81FEA5B97FDEEA56ULL, 0x7CE67454ECA447B8ULL, 
            0x902982294E63FC64ULL, 0xC5EBDEE2D5C8415EULL, 0xAD68D00E8C53E5D7ULL, 0x6919C18359B424BDULL, 
            0xFB9B45643B3B522CULL, 0x58BD0A81D067D4AAULL, 0x92BBA811B42D0069ULL, 0xDCFFF1A6617ED554ULL, 
            0x3D73875BF16D669BULL, 0xE8AF12051167CF5EULL, 0xACB3BD1776ACC82CULL, 0xD2083DB9A3E2321CULL, 
            0x62A6C781503C9E39ULL, 0x43952A3CCAAFA145ULL, 0x5B1C661B2DCF459CULL, 0x11893E23172515C7ULL
        },
        {
            0xA788D32878C05657ULL, 0xD68E4D741E9F439CULL, 0xDE5AFFF7F299292CULL, 0x95F0414A65A12B3AULL, 
            0x137A2235A4CF5BD2ULL, 0x013D2D5989B26CB4ULL, 0x4A45DA16B13A6F41ULL, 0x6BA7F82D448E8DCDULL, 
            0x23240B6D5F9AAE33ULL, 0x09BB406DF230AC67ULL, 0x7CC0EBD9E5C34E62ULL, 0x94A327B05B1B25B1ULL, 
            0x71655F765523D125ULL, 0x3F428D6ABDFC8C61ULL, 0x4BFD86E38E9B7B2AULL, 0xD5E7C1A86AEB24B5ULL, 
            0x446F2FA1A35F8597ULL, 0xFEFE41823748D217ULL, 0xB37062FB66624097ULL, 0x79205995E28D8485ULL, 
            0x1D378B06BAA561EDULL, 0xF81389351D3EC5DCULL, 0xF63631AC57663EF6ULL, 0xB07A7ABC9C257F28ULL, 
            0xDD1591F6D64DD95FULL, 0xD0EE6804284259D4ULL, 0x62D89AC4C915F137ULL, 0x0AABC78FDB317C75ULL, 
            0xB435F5541AC66331ULL, 0x6793821E71AF8114ULL, 0x1635B577F48AFFF9ULL, 0x652800C3AF3DD829ULL
        },
        {
            0x37C5C6CB31F25AF6ULL, 0x651928F1153F08BAULL, 0x0F534C8F6E36EC3DULL, 0x86E0AFB45F848E9BULL, 
            0x60D87BC9266BE4A3ULL, 0xD3255F9B07F7032BULL, 0xB4E81F94DF1F0DEDULL, 0xAD806A837B2EED2EULL, 
            0x8D85B08FEC87E63AULL, 0x1458B1D14EC75788ULL, 0x0F3172C7C368CBF4ULL, 0x93256E675A75DDAEULL, 
            0x9E818D931C51132AULL, 0x4D489F6722687108ULL, 0x9E704E3BCDD140FDULL, 0x8A1094927594A9B8ULL, 
            0x7DB3762C01EAA945ULL, 0x3DF0FE5095C2AC02ULL, 0x27012CB262EAA245ULL, 0xF74BD2F29790D61CULL, 
            0x4B17351F54F13EDCULL, 0x619BEC3F7DB9B71FULL, 0x8BDF7F4B617BBA3CULL, 0x9391DD02A228B143ULL, 
            0x46211085EAC335D0ULL, 0xB78DE46EF6CC1AD7ULL, 0x86B95027BB810ECEULL, 0x0CA0C7B3ECBD5C45ULL, 
            0x044B8322430EC7D3ULL, 0x0F971FDCE8AA03CAULL, 0x2331E0F50034A674ULL, 0x56D86880FD43C42AULL
        }
    },
    {
        {
            0xBCBA1CC78D9CDC49ULL, 0x34844B34E5D0C19AULL, 0xA351BDD54C0E6012ULL, 0xFAB2858AB7F0619BULL, 
            0x52088D13C057FB06ULL, 0xFC8BEA21DA79F741ULL, 0x587790659F53995BULL, 0x2C2639D6685AFFE1ULL, 
            0xDD1B1AEA51D3C7B4ULL, 0xC0C47451895AD8CDULL, 0xE2E2747B60777D01ULL, 0xF3479609BF445CB9ULL, 
            0x935439D4802CB81FULL, 0x835436DE2AD23503ULL, 0x0010C7D2438010B3ULL, 0x8863E28CEBE896D0ULL, 
            0xD34C918C5245C9E9ULL, 0x60D194317E9F5666ULL, 0x52275C10AA6688C2ULL, 0x45E18D8CA81C12FFULL, 
            0x627109862173B0ACULL, 0xB8834DA6E9D45073ULL, 0x1D21271D9E8A0E7BULL, 0x57C60A0313A65686ULL, 
            0x89554F82809B71ABULL, 0xE74D8DFF6720F69EULL, 0xFBFEAB2AC839363CULL, 0x4B25549DF05E3A30ULL, 
            0x0399B5FCC7FCC0EBULL, 0xBDD615600694CBEBULL, 0x48393FC789C6463FULL, 0x65B48884EC03D41FULL
        },
        {
            0x4E1EE9338BD331E7ULL, 0xB6A933969DA3CC41ULL, 0x2F5F5FC964794787ULL, 0x0B97A153C1C38A0DULL, 
            0x4BF89C5D777F848FULL, 0xC0A4D4B4DA0331B1ULL, 0xAF0F9747053809A8ULL, 0xC01F40F92137352EULL, 
            0x99ADCFC997A3AC89ULL, 0x3850919BB33737B1ULL, 0xDE3EA51AC60DA5D5ULL, 0xC0FA57A7DEB2C373ULL, 
            0x305169FD48FB41F8ULL, 0xEA505CEC89883475ULL, 0xD5E5C2E3CCB891B2ULL, 0x5A87DD559AD499EBULL, 
            0x5E28F2442AB43A65ULL, 0xBC11EE496AD4754CULL, 0x0D84B0D93703A002ULL, 0x338BF34ECF4CD595ULL, 
            0xF2603A9AB92F4153ULL, 0x8B4F23968507CE10ULL, 0x3E71B00991DBC474ULL, 0x67B2B0535AA58DEBULL, 
            0x34DB6CF55B1BE0A1ULL, 0x33DE43AEFEFB8171ULL, 0x31916D0944A33B6AULL, 0x91A180CEDA8A69E9ULL, 
            0xB317D1269223A562ULL, 0x31E3EF445CA8FACFULL, 0xCFB9CE3D909BCCD8ULL, 0x4A1AA751D1DB3FE6ULL
        },
        {
            0xBC34BDE21BDBD3A2ULL, 0xCC64F81AF916F9CDULL, 0x34CEF0E2D2504FC8ULL, 0xF7589CD3484F4D54ULL, 
            0x47136B945E02ECD6ULL, 0xCEC64D2459AB1B0CULL, 0x33A1C46BDD74D250ULL, 0xA38A87ABC63D6A10ULL, 
            0x4DD3B16F65A7C4E7ULL, 0x398CCE5818C9130FULL, 0x3C980D1BC37B8945ULL, 0x11B0010C0D4D1F9EULL, 
            0xF91F2471CD5C3963ULL, 0xD0AD40AE6BDC677BULL, 0x918F2A117B306978ULL, 0xB7AAFA66EE279E97ULL, 
            0x2B818CE6E65862A8ULL, 0x3395986C3D7FEB2AULL, 0xE6A276987D688AF8ULL, 0x86E1697CD9B4E2F8ULL, 
            0xA9B078BCEFEBE2A8ULL, 0xAA121BF41EF58E73ULL, 0x0B2EB1C88888473FULL, 0x9E2B4C0ACD81B383ULL, 
            0x5FDFA823428EBE59ULL, 0xC60A589573A48DD1ULL, 0x125BC0008F9ADE63ULL, 0x1F8AAB890738B5DAULL, 
            0xEF882ABF3DD9F042ULL, 0x2380EB58FF8E2095ULL, 0x761B5CF38E0754EFULL, 0x14C57E241D55AD9DULL
        },
        {
            0x067D9437BA370241ULL, 0xC7D27D7DE755BA06ULL, 0xF661014F03BC1ED1ULL, 0x79490891A5682242ULL, 
            0xF5F3008909A1EFB3ULL, 0x0A48482CEC195A8DULL, 0x5D03AAD8219A27F4ULL, 0x460E24F1ADA89E12ULL, 
            0xB0721AE03AFCE248ULL, 0xEEB5E232BBDAB60DULL, 0x9D2390EBE0C0BE67ULL, 0x818DFAD550FF1C50ULL, 
            0x18B213E72A7B875BULL, 0x4D4282E7A1E237ECULL, 0xAA8A7E229364D93AULL, 0x75B1B8BB5B1376D6ULL, 
            0xB713A083FD7FA51EULL, 0x4ECC3E04549B80E7ULL, 0xE3E7C8E005E13209ULL, 0x35E619266D0B21E3ULL, 
            0x13A13D9833B68CEEULL, 0x9B238A3D670E85EAULL, 0xD1C9FA2EB1A32418ULL, 0x85BB636F8170A2D0ULL, 
            0x619E5476DC2294DDULL, 0xA950B1AEF8E6E021ULL, 0xDD936702E2D6BFF6ULL, 0xA7D4C62AD45F4E49ULL, 
            0xDFE9FCF495E9F32FULL, 0xEDBCC792B5E5B030ULL, 0x811FBBE4B36C6A23ULL, 0x48B51E50D4CDD2E1ULL
        },
        {
            0xDAB2AB1353E26BC6ULL, 0x16DBC51C0FFB3DF3ULL, 0xDAAB4A540E9541FEULL, 0x005906D2D6C39915ULL, 
            0x6646FEC51E287A2CULL, 0xA26ADFE288432CFAULL, 0xD1EE0A13D777992BULL, 0x75B98FE36E16FA14ULL, 
            0x60F6374AB25254CBULL, 0x0801080D059427ECULL, 0xDAD110D1955F4BE2ULL, 0x6B779B7CD988F46EULL, 
            0x05A52C0081E3960CULL, 0x2C71C823A2909661ULL, 0xF26DA5117D11BAA7ULL, 0x0EAC3B87470735BFULL, 
            0x2A9B1E1D4A4B6498ULL, 0xB1C34C09CD86BB7DULL, 0x3F606B3CB1F2DF0CULL, 0x66BEA75353125B40ULL, 
            0x98FC2C23E5656768ULL, 0x6E1BE8A8C43F94E5ULL, 0x7D80CD9D34E4A532ULL, 0x6683C3AB17F7F9BAULL, 
            0xE9BAABAC3242A6D9ULL, 0xF59FC794E829B379ULL, 0x727B34ABC6EA18FFULL, 0xB714DBC2201755FEULL, 
            0x3B86F6831177D581ULL, 0x240E9942D5330D9CULL, 0x384B3923A74D4D93ULL, 0x06DB61509241BCD9ULL
        },
        {
            0x380EA0B228F58ADCULL, 0xF7BC08C7908976B7ULL, 0x21710A43E52E7758ULL, 0x016589945DE40D71ULL, 
            0xAFC3678044C87AA5ULL, 0x3F61091CF1F8E71EULL, 0x85F5E7E0D846A094ULL, 0x5251CD3D4A7FD4F1ULL, 
            0x1C861E495EF60E8EULL, 0xE5D46DCD5F5A79B5ULL, 0x6876FFA91481DEE5ULL, 0xA5EED1F568C68CE1ULL, 
            0xDBB9078BD005981EULL, 0x12D6BE39F77EFAA0ULL, 0xB73DE9B4DA5DBFC1ULL, 0x347BA449730BEA1FULL, 
            0x1ABE5E3D96D8C752ULL, 0x0758CCF608E8F4A6ULL, 0x6A66461BC94D68C3ULL, 0x7D5B4967207C0FD6ULL, 
            0x4D8912328A141BC3ULL, 0xDCB63E3A8B70042AULL, 0x4F1FA805AD7C8905ULL, 0x273FD871070B6529ULL, 
            0xF2BDFEB77E1C8775ULL, 0xEFAFB8BC0D7B766FULL, 0x45561C000F054AFDULL, 0x987AC4033269308DULL, 
            0x318A14095BEC57ABULL, 0xABD206CCA6FE1377ULL, 0x07513B01ED4484BAULL, 0xC88772FDD7694B2AULL
        }
    },
    {
        {
            0xF0DC2D2C27FB3410ULL, 0xA9987AAC1AF75164ULL, 0x343661D2793E2DBFULL, 0xAA948BFE05CC9197ULL, 
            0xBE74387A4A627D4EULL, 0x0DB6E73ECC9AB649ULL, 0x49D4946B9F5FF06EULL, 0x1E95074010E4BAA0ULL, 
            0xFB6C429689347BB5ULL, 0x3B3286F158E5AE1DULL, 0x462E22E6CB475E7BULL, 0x37E643F82B371288ULL, 
            0x891BF8A590956B68ULL, 0xF83E208899FE6637ULL, 0x0CE61141CF19F40FULL, 0xFFBBFE7DFE86686CULL, 
            0x05C2990079DFEF9CULL, 0x0E50B55F58E79DF5ULL, 0xA28AD4D788E1E1F5ULL, 0x6F968BF07BC9F6D9ULL, 
            0x59F4B5CA93EA79B3ULL, 0x4566979E550DBE87ULL, 0x49E5A823473ACA76ULL, 0x01DB5C1F09BDC1C2ULL, 
            0x5B3AE6B6F2448326ULL, 0xEDF71ED6D40A3314ULL, 0xD6AB5C5BEB897DE7ULL, 0x268F7B8E9A402F84ULL, 
            0x78CC4956D45E5DB4ULL, 0x40B5951A14012C89ULL, 0xBE9DD5992959F74EULL, 0xCB3C0327626CD197ULL
        },
        {
            0xFBF55AF68478199CULL, 0x3EF8DBDEC225B954ULL, 0x1746410191413534ULL, 0x889574CBC03CA7D3ULL, 
            0x14112BC51A219350ULL, 0x1BD89EBB822AB366ULL, 0x96119B0F746CF090ULL, 0x299800533FD126F5ULL, 
            0xB6B6E87F9E013BD6ULL, 0x60F3616301CA0E25ULL, 0xBE1752885E95907DULL, 0xA16A198CC9C3E5CEULL, 
            0xFD95572170F38744ULL, 0x8EC70AC0D03232E4ULL, 0x4748BAE8CB31482DULL, 0x3A7AA5147E5AC221ULL, 
            0x2736F867FD8A4FE7ULL, 0x4716C1DC4AF5CFA1ULL, 0x6914889051E9FB52ULL, 0x5F1AFF0F2FF7159AULL, 
            0x4935F7BC1BFE0ADCULL, 0x0A5FBB09713E25F1ULL, 0x50C1CEB7E192C9DBULL, 0x47F2F14CE4CAB80FULL, 
            0x817BDF70664A897EULL, 0x764997FEA0EF679DULL, 0x667007A8A8AA7720ULL, 0x9051D4BCB9701984ULL, 
            0x5B8C1E9644CD9D82ULL, 0x83626E767269CD91ULL, 0x4B989691947EEB92ULL, 0xC2F7DDC29BEDD8FDULL
        },
        {
            0xD178E87030968F72ULL, 0xB9F2E2ED3FE26CAAULL, 0xCD4D7E9A4231A04BULL, 0x608EB0560C01AD0FULL, 
            0x6DAAF5B407803143ULL, 0xE4A388F90390DCDBULL, 0xFFA96E3AFB90194EULL, 0x3171E69A7DF93E30ULL, 
            0x4339F21180DBB354ULL, 0x01E41A71C2647018ULL, 0x2DAE52C5A605B96EULL, 0xC5549A5E8EBC337EULL, 
            0x700BFA7C76D1CFC0ULL, 0xB35494A7E8A35308ULL, 0x9B93D72103057C84ULL, 0x4A21DA1B2FF84767ULL, 
            0xC0828E58AB7661C9ULL, 0x447EAF3687E875CCULL, 0xFEC56A7340160360ULL, 0xA4A983FF2402ED33ULL, 
            0x1C0AA8BEAC928F9EULL, 0x176FA4E4A76ABAB2ULL, 0xE6A678FE4331DAB3ULL, 0xDF1B5B45C3638FA3ULL, 
            0xE880800F4CB8405EULL, 0xCE69B22B7F181DE7ULL, 0xB435C8C469479603ULL, 0x93E2E1E72E37977EULL, 
            0x54A5BA9DDC19F322ULL, 0xAAF5AB4453F54410ULL, 0x95F5FA289984D715ULL, 0xBE1733EE4B505C30ULL
        },
        {
            0x0AB600168C77C423ULL, 0xD5D21CF582CED3F0ULL, 0x60035C24AD1886EAULL, 0xD4DF03EA92C7D72DULL, 
            0x4781E6477EB0943DULL, 0x22E81FD13EBD5376ULL, 0x8D6AE4B68D82D8D2ULL, 0x1A1B8CBC0AEF7C5DULL, 
            0x9FA030CB8D031537ULL, 0x725D33609457331FULL, 0xAA75E7F386B9DF75ULL, 0x318B9E22D026BD14ULL, 
            0xACBAC717651B841AULL, 0xC00F83D3D45893D9ULL, 0xBEB4719944567E92ULL, 0x2038F7C7BAD343D1ULL, 
            0xF41BB801EDCE7F05ULL, 0xE89E927E20606FCCULL, 0x74AD8EC6CC973629ULL, 0x738ACF8BA4D9979BULL, 
            0x5727751EF7511620ULL, 0x3942552B830BAFE1ULL, 0xEF13A4284CECF5BDULL, 0x14F64316D1E5E4D0ULL, 
            0xD68CA26006BCB0CCULL, 0xD6BF56D9C8DB3924ULL, 0x3D87E24210B8D86EULL, 0x199297913D5E5757ULL, 
            0xFFF50A9CDFD9BE57ULL, 0x12A0990A1DE9F2BEULL, 0x5614EFA2B995CCEBULL, 0xCBD2CF2349222F84ULL
        },
        {
            0x3154472F08FB7D22ULL, 0x5F533294197AC644ULL, 0x7AFF8EF4E1E7FA2DULL, 0xFAB6367637C58F3DULL, 
            0xCE2C3AC4A3587257ULL, 0x911BEDA22795C5A3ULL, 0xB82E4F9C93334FD6ULL, 0x11F95723AF2BB8A5ULL, 
            0xDFD40BD98850BF84ULL, 0xEC0AA0B640A83D80ULL, 0xDAFF9349C63DB24AULL, 0x2E01D32BA39AD876ULL, 
            0x30C5D0272B477B86ULL, 0x35261BDFBB5528BCULL, 0x35A0C478B38A6E37ULL, 0x28AB6B68AA8B6D21ULL, 
            0x39EA3A391FE719B5ULL, 0x6BA78C0A9C897D4CULL, 0xAF27204C84F4966DULL, 0x4D6DB31ADE7BE67DULL, 
            0x68F1EBCA6615A7B0ULL, 0xCDE076C7CC11258BULL, 0x3745F2FC24EAF6CAULL, 0x486F8582D5B1AEF1ULL, 
            0xBB02FF7FC4867801ULL, 0xF4AC0D175D82F1B6ULL, 0xF337C1B0CE4D00BCULL, 0x32F00BB8BE06DC63ULL, 
            0x383E9E6548B2043CULL, 0x6ABCA0520845EDECULL, 0x90178527429F11EAULL, 0xD9E1A7B6B04E949BULL
        },
        {
            0x5F5D3E08FED3693CULL, 0x88C063FBE65326FBULL, 0xD5AFE9ADDFB1744FULL, 0x7B8A974796DED157ULL, 
            0x06F64ADCAC190432ULL, 0xF293E104AB6ABF99ULL, 0x411C566A15325F36ULL, 0x480B549EA67E8455ULL, 
            0x710051BBAA1A9602ULL, 0x958307EFEEDD816AULL, 0x3E2D4C4792ADD67DULL, 0x325CF77CA5703B86ULL, 
            0x422152ACDAE54097ULL, 0xC1643C24F4B5A4A4ULL, 0x21AD17B765CF68F1ULL, 0x41BA85243CB6D963ULL, 
            0x350515DE68A043D9ULL, 0x08CDC825C0C37FF0ULL, 0x2D9D27D61D6B446EULL, 0x7AEF07316244AAD3ULL, 
            0x78BEBFE1CE7F8860ULL, 0xD7CA37CE282847C6ULL, 0xF828FAE8F581F7E6ULL, 0x334E5A8BB04AB169ULL, 
            0x87BA997C9993E9E2ULL, 0x3250D0C828D7F108ULL, 0x9635F646C1C02C9FULL, 0xB8B041FC5B65EA85ULL, 
            0x58B0AA3ABC0EFA1CULL, 0x4B320F68D66ACBA5ULL, 0xD0D14436BD952F73ULL, 0x59E85DFA944A5BF2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseCConstants = {
    0xF7378D498BC539A8ULL,
    0x04DE985F384001B7ULL,
    0x00A30B4017E0D8C7ULL,
    0xF7378D498BC539A8ULL,
    0x04DE985F384001B7ULL,
    0x00A30B4017E0D8C7ULL,
    0xC5CB0231ADE575BBULL,
    0xE02C1DF50107FB7EULL,
    0xC1,
    0xBF,
    0x83,
    0x75,
    0xD7,
    0xCE,
    0x42,
    0x75
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseDSalts = {
    {
        {
            0xF96DBFC68DC34069ULL, 0xCDEB4454E58ED42EULL, 0x35C4B5CFDB908893ULL, 0xFA6FA235450B51A1ULL, 
            0x7D32309707110B66ULL, 0x57DB379A74BCF997ULL, 0x15E2375BDB95E488ULL, 0x822913155D76A985ULL, 
            0xE271D16A771642F1ULL, 0x0816704D945ADC63ULL, 0x1B4BB20C7418ECB6ULL, 0x01B5477F66445037ULL, 
            0xD31C332CFAF8AC4CULL, 0x143B429345715355ULL, 0x6199DF624029816CULL, 0xD2D4F46A28287988ULL, 
            0x62ABA0D3D76BD1D1ULL, 0x701A3129F60B3F3EULL, 0x4F371A0CAA079434ULL, 0x5D5E53867FA72EC7ULL, 
            0x60ED7FD0224580FFULL, 0x3F973310B0A528B4ULL, 0x57BAE1E80914D493ULL, 0x244B87F6A8BEC264ULL, 
            0x9DB9B69C7C6A4D76ULL, 0x69BB6B12C573DD1DULL, 0x41DA7A1FC2042E7FULL, 0x8240C81E6D3E52C8ULL, 
            0x93C9060ECF93FBD1ULL, 0x40F5272D6338A7D5ULL, 0xA6E529A6F1051345ULL, 0x805D021D2A6656A4ULL
        },
        {
            0xE88511935B8DB04AULL, 0x3A1741D8B1508C5EULL, 0x412D9282DE5F5F9DULL, 0x70D7B3D9129E56BEULL, 
            0x3A29575D63283059ULL, 0x89CC04CD008F81B2ULL, 0xAA76E0B54201A589ULL, 0x6876958A0A190061ULL, 
            0x0F1C75D8E992F0DDULL, 0x40ED0021E5978BCCULL, 0xEA3F8B46E579D8ADULL, 0x7B5ACFA055D81F4DULL, 
            0xBD66A23E62989494ULL, 0x7AEBA2225BEBD626ULL, 0x44AC3EE46B46CE00ULL, 0xF470644FDF43BC2DULL, 
            0xEB5CD62981321BB2ULL, 0x91B7553926FC0E2EULL, 0x66B3AE8C2467AB3DULL, 0x4736F5546D9D683CULL, 
            0x45123919B843879FULL, 0x51BD3B3320CF1F35ULL, 0x62FBB3F9E11B460CULL, 0x69B1CEFAC9DE677FULL, 
            0x0B6E47EB9663D9B6ULL, 0x4C4BFB843E068D04ULL, 0xE2B92EDEEB5C986AULL, 0xEB1A006FA5C22FBDULL, 
            0xB535C9C26650E3CFULL, 0xFF37EDB153E49E48ULL, 0x5D8D8A0D837EDC9CULL, 0xA6539702E7772B8BULL
        },
        {
            0x5106EAE27528AB1AULL, 0x7FBF0F323CBE4424ULL, 0x5C63761B82CE5202ULL, 0x3C773167597BA63EULL, 
            0x17D70F4888E0CA76ULL, 0x255916A41A7B3B56ULL, 0x1CBFF0BE94C93C78ULL, 0x0BBF127C1206CD2BULL, 
            0x6BBA8C8329AA92EAULL, 0x9D44491E3A28EE2BULL, 0xDCE2787B1FDFFF42ULL, 0xC5BDA3E6A51FBCB0ULL, 
            0x03D2E4B6AEF2C127ULL, 0x93C512A59EC5B04FULL, 0xD37E4763CA303592ULL, 0xC2CC08F9F4F0F6BFULL, 
            0x097A22B6276F974DULL, 0x8326679E9DA665D4ULL, 0xDBAB0778D4965DBDULL, 0x06CFCA48C0E54915ULL, 
            0x054C70D4F55FD0C1ULL, 0x50C6CE4CED11D9BCULL, 0x0F55DF2598655D94ULL, 0x7D3EBD6F70A394F1ULL, 
            0x550021D66CA951F1ULL, 0x3FFEFB4592712D34ULL, 0xC3389A6FA184994EULL, 0x83CFE379AAF1F08CULL, 
            0x1DA96AADB03692D5ULL, 0x12101D7E193BEB29ULL, 0x70D613B09AFB8C72ULL, 0xED404559EAF675BEULL
        },
        {
            0xA3BD396D1708BFCAULL, 0x7FC3E26E3C326715ULL, 0x17C6A8DF32DF1C8BULL, 0xE4496555412C68B4ULL, 
            0xA75FB8477FCE8A92ULL, 0x1B9D1EB6A6E5F774ULL, 0xB68CDC5B69DBC869ULL, 0xC374162715A3F33BULL, 
            0x768A3EE05D548DF0ULL, 0x3A575D512BA62733ULL, 0xA311374453A57A9BULL, 0xC34BA248476F12DAULL, 
            0x0DB6DC81273114D1ULL, 0x744BC1791E46DE81ULL, 0x51477ABC3E8CE6ABULL, 0x85C8A0F6E1CBA37CULL, 
            0x2DAFA2581892F7C7ULL, 0xE24CDC1C42CCC912ULL, 0xE2010497B193EB4DULL, 0x7B214B8CF8078C17ULL, 
            0xB8E8ABD1CDA84932ULL, 0x5EA82752F67616F0ULL, 0xF20AD2EEB75D5F13ULL, 0xD330E81E25C52811ULL, 
            0x095ECCA0A5B40D65ULL, 0x980867A40EB8D8B8ULL, 0xC4D1EED734A6F145ULL, 0x15F9887F127E83AAULL, 
            0x02AB074050BFE67AULL, 0xED13A0E3784E4390ULL, 0x0A9C3717287B700AULL, 0x13B37723647C7060ULL
        },
        {
            0x2ABB217299E132EEULL, 0x449B092288E5C584ULL, 0x471533DDC18EA065ULL, 0x113A2282D2A7CBA7ULL, 
            0x2754999358AB174EULL, 0x5AE34C0F4DE65410ULL, 0xCCEFC3D6915ADF7DULL, 0x193B22B0E5D43458ULL, 
            0x4C292ECDFB5C7194ULL, 0x4ED875536AEC3B83ULL, 0x7E33CB35A6885DCCULL, 0xC36AC3AF881E17A5ULL, 
            0xCF16F4EA60606529ULL, 0x5F10DFC79751E257ULL, 0x400FB55A2F7B5E58ULL, 0xB63B30BCCB379EBBULL, 
            0x052010BCD5F7EB78ULL, 0x2315B1F7798AE258ULL, 0xD7516528D4E7FA69ULL, 0x59A81B8552084180ULL, 
            0xCC33C1E0229B2301ULL, 0x0E77CA9AAAA65976ULL, 0x86EE027CF8BDF0F9ULL, 0xAE0DE1D4987E3BD6ULL, 
            0x7BB63DB6D84017ABULL, 0x20CFE2E2DDB87F00ULL, 0xF035BC14EB32CE38ULL, 0xF9407F30A800CA7EULL, 
            0xF8E8961E77D98048ULL, 0x3F12B8FE0DA22750ULL, 0x309E2D3A793E57B5ULL, 0x9603FBA5B5A59E1BULL
        },
        {
            0xECE7047E48A0BB33ULL, 0x0E7E75F73783D37BULL, 0x558736F8A9B34D09ULL, 0x85BAA418F52E49C8ULL, 
            0xD970BFB314E8AD4BULL, 0x7A0F45EBE18B7E3DULL, 0xF2CAF9B1053DD1FAULL, 0x6B26098E29E0B4F3ULL, 
            0xD343C5D56F708409ULL, 0x3B9147603B623E44ULL, 0x5EBC943FC310A90FULL, 0xCBE08C9CF8AE5297ULL, 
            0x0379E499AEBDDA85ULL, 0x718AC41FF5702E4FULL, 0xEA405E36840B5C13ULL, 0x16F5C5DA142E2A1DULL, 
            0x6DDB9240CEA0665AULL, 0x1B308A9CCE6BAD5DULL, 0x6B47FD65881A4EF6ULL, 0x37E1D5877A5652EEULL, 
            0xD0E77D3DE757FB3CULL, 0xE26F68F7F8DA1B41ULL, 0xC902A78A87629166ULL, 0xDBD990810DFBD767ULL, 
            0x450D96A92995F5ACULL, 0xB2459D69A48D40EAULL, 0xC90D37C683391F88ULL, 0xE9971CA5D498CB49ULL, 
            0x3678A37123BABC79ULL, 0x1D884518C5BF32C4ULL, 0xD193A94A6A24F541ULL, 0xEE45700BD85BFD68ULL
        }
    },
    {
        {
            0x389664A8649FC364ULL, 0x74F694E72F43DB84ULL, 0xB328C8176011E80EULL, 0x068FB37D288298A7ULL, 
            0x7AA078D065E5D967ULL, 0xF670C610E1AD65E6ULL, 0x59672F262988E623ULL, 0x66CE103BB6632CBBULL, 
            0x5DD9527AC8A3C286ULL, 0x4E48F53D0F999113ULL, 0xFE39FDCC44C94A4AULL, 0x066C14CADB2F7DA0ULL, 
            0x760148928BCEBF90ULL, 0x8DDAC46E6E55AE57ULL, 0x4C5BFB517AD58130ULL, 0x470DDB5AC98F9D7BULL, 
            0x1BB27394F9AEB9DAULL, 0xFC01BABD1FF296FCULL, 0xB4B5B74B1B165BFAULL, 0x15F3866A78B0B4A7ULL, 
            0xAD806D94B8A6C414ULL, 0xA865A6BD1ED99DEEULL, 0xBFA625B206DE0952ULL, 0xF3F17880C68D6C69ULL, 
            0x56F93FFED840655FULL, 0x5324DFFF1936D6E1ULL, 0xEF8BB1570746EBBBULL, 0xD81884E71F1A5750ULL, 
            0xDB88D921A03A84F9ULL, 0x0ABE8F20884753F9ULL, 0x9A65CA55A2C60755ULL, 0xDAD2D92C4C04F19FULL
        },
        {
            0x429FDEB29BF82EB9ULL, 0x5620E52B3674723AULL, 0xE58ADA8D52FF2E3FULL, 0x1D940373CBF41A59ULL, 
            0xF20078B06733B958ULL, 0xB1F81819266B5DFAULL, 0xF0A287F8878A6F38ULL, 0x85BDD5EACA4CD7D6ULL, 
            0xDF840478A94B99ABULL, 0x67CF943534D133FDULL, 0xB4B976AFDDB32BD7ULL, 0xB14D1BA874F5D535ULL, 
            0xBEAB26CDCB999013ULL, 0x8AE544B44C3E8F3FULL, 0xF3E89D9F6E4AC2C7ULL, 0x0C4526B387D32F4AULL, 
            0x5518DE6B5018B9DCULL, 0x8D8A671F8C78A72EULL, 0xAE5AB9EFF6FCF2DCULL, 0x84393514CD6BF0C8ULL, 
            0x8B3C633D726BCD9BULL, 0xF6C214F542A24704ULL, 0x281DA5FF6CF8BC63ULL, 0xB72E708B2483059EULL, 
            0x6C5552D9CB3D669BULL, 0xF7CE1CE0570B3898ULL, 0x0D9EE5F13003FEB7ULL, 0xEA25018F6FDBB1A5ULL, 
            0x6217ED76FEF0EC66ULL, 0x4BABD31EDAABA15FULL, 0xE732C5D89BF7B9B9ULL, 0x149B4BB595AC00E6ULL
        },
        {
            0x8C2193F18EA5F4EDULL, 0x49E258029FD51824ULL, 0x04B30571851E0C8EULL, 0x04E07A26587E7F73ULL, 
            0xBE9D19CD4E7C4820ULL, 0xD8C1BC0CB09AC96BULL, 0x221E7C96C6BD2B12ULL, 0x7F4E72016F4A538DULL, 
            0x0E49D7DFF4DD0ECAULL, 0xD9C52730EEE3EB6DULL, 0x178F2C078C2A5D48ULL, 0x3DFFB8073D2721A8ULL, 
            0x6CB6D0EFEC73BB9FULL, 0x3CDAA73EC44EDA19ULL, 0x3EEC010FA480AA8EULL, 0x46C7F98087778537ULL, 
            0xD170928FBA756B4CULL, 0x7907AA63D167A706ULL, 0xFAA97FDFB9C4865BULL, 0xAE2AC97530F16F53ULL, 
            0x0E3F18888D3535BCULL, 0x0530E6575D772E52ULL, 0x082F4EAC33FA2678ULL, 0xE3756D89313B0D4EULL, 
            0x1EDB9CFB52698DF6ULL, 0x326A8810F46CD773ULL, 0x03601901C7E88315ULL, 0x76391C18414EA29BULL, 
            0x36D3B56DE8CB204AULL, 0x61DDB7FF0E40589BULL, 0xF7EA29F95D4AEC9DULL, 0x38665C85279F9841ULL
        },
        {
            0x865E320993AC3B25ULL, 0x386688F3E57D3F0CULL, 0x107FFA6EF2DD8DD3ULL, 0xCB316B2BB2E8D7F3ULL, 
            0x8D78986AC093B28BULL, 0x1E48595020CB11D3ULL, 0xE2E9DE2ACA6E4663ULL, 0x40ECCBFC38AD98CDULL, 
            0x130507BA4C942963ULL, 0x4E9810C113574430ULL, 0xCA1FDDDCD14DF0BEULL, 0x0ADD4C8FF5AA786FULL, 
            0x7567C575F1A40444ULL, 0xB7C36689F9BD5BBBULL, 0x33AF41BB4665B327ULL, 0x1291A4774A16C507ULL, 
            0xE3ED7D7C08C16EE5ULL, 0x6B92C931AA3ACC83ULL, 0x8F155EC2DE43C875ULL, 0x292AAC7DBA0043D1ULL, 
            0xC34627F1BA8CB1F0ULL, 0xEFF125118A00C2DDULL, 0xAA22B36D7B38528AULL, 0xBCAAC7E0A5B2387BULL, 
            0x93320030BDAF671CULL, 0x0864AC1DCBBFEE57ULL, 0x207DA7F71AA6919BULL, 0x88513371C4ACD318ULL, 
            0x8AEB060C7CAA87A1ULL, 0x3C336B992145B63AULL, 0x12C7EDA436BB3E7CULL, 0xE29BD6B82E6F4254ULL
        },
        {
            0x7572294FB2D40545ULL, 0xCA019EE3125B7112ULL, 0x7B9AF07C97DFEC38ULL, 0x8182591998F10477ULL, 
            0x53ED8ABDCB18AC83ULL, 0xF885EF5226E2F654ULL, 0x6B9C2B4DD688D738ULL, 0xDE2322682A5E8079ULL, 
            0xF6F4D89D9D19E451ULL, 0xA418F8A925AE42DFULL, 0xBAFBE3863AF222A6ULL, 0x5ED9A0C991B63697ULL, 
            0xF39E225D1805A921ULL, 0x1FA016890564F4A4ULL, 0xB44B48BE938CADB9ULL, 0xAD18BB2891572038ULL, 
            0xB767DF25EFB0F368ULL, 0x516FCAB3A8B784D3ULL, 0x1639A15D8C435D18ULL, 0xCC1770D9724D124EULL, 
            0x03FB7F252463ACCAULL, 0x200D162EAB645094ULL, 0x91852262E54DA03AULL, 0x6AA010A07CF52E42ULL, 
            0x03242B34F1B6AE3DULL, 0xFA766A39B3B6EEB5ULL, 0x180D57926F6007E2ULL, 0x7C469CD7934423B7ULL, 
            0x99422B23461522D1ULL, 0x640A0113DBE47C7FULL, 0xCBC0E20674280F9BULL, 0x60F196F6860DF785ULL
        },
        {
            0x8AE2FDE6A49F535FULL, 0xABBAB54D6A6E964FULL, 0x87DA9AD09DF0CCE7ULL, 0xF77352D82A63F9B2ULL, 
            0xBC0A030EDB235C22ULL, 0xDA5A6854FACF266EULL, 0x2B1FCAE4633790FBULL, 0xB9CAAFFF7599BF02ULL, 
            0x8527D53FB7304C66ULL, 0x5AC752CD9852A63AULL, 0xF19C241D31F11ED7ULL, 0xD73C44E3B7843148ULL, 
            0x696E3111BD284AFEULL, 0xC9FB560DE29ECBB8ULL, 0x725F71A48553B285ULL, 0x1EE2BFD1D3760216ULL, 
            0x1BF5ED1E7A437FFCULL, 0xEB6B06075F6B1863ULL, 0x1DF89002CCEBAB5AULL, 0x10BE3F87ADEF5DCDULL, 
            0xA4D14C5C6284FBD6ULL, 0x9E879DBA258614C6ULL, 0x263E1ADF75759744ULL, 0xF8743E71C28572DEULL, 
            0xA34F86C018B00C90ULL, 0x67F92F818A4A783CULL, 0x392791B07CAC5F8DULL, 0x41544B55F2AD6C42ULL, 
            0x47136E3A425DF95CULL, 0x219C78C9FE1AD16CULL, 0x75C1B72A6E3A888BULL, 0x40E8A6367C9EFBF5ULL
        }
    },
    {
        {
            0xEBE19FA28C86CDBEULL, 0x31ACAFB1C03E471BULL, 0x723410359DC177F5ULL, 0xFE67C935409E0EB6ULL, 
            0xD654E9B9C4749119ULL, 0x6E9661FF7F93D25CULL, 0x6D6FA1E8BCD22A9AULL, 0xB3099F06F852F304ULL, 
            0x6A2271DF1D565E0DULL, 0x733DB910BEE0FC02ULL, 0x06DE748EE2760408ULL, 0x8FF2A27B2D08E5BEULL, 
            0xFD034671B1E1DD92ULL, 0xE6A3C191F57A37FBULL, 0x04299D401D93CC7DULL, 0xD47E0F2A95178F54ULL, 
            0x477050252E10D3F0ULL, 0xE2929D16FD78A7C8ULL, 0x40D3E359DA0CC956ULL, 0x8B8AAFEBF0A99432ULL, 
            0x2BE189D8E2CCC4C6ULL, 0x6794F38AEE6C635CULL, 0x9674BB28E59004C8ULL, 0x3D5457A3505A2538ULL, 
            0x6AAE4F3493B668F0ULL, 0xB5B8B6B4A5A62C83ULL, 0x9C55CF8CE9AFB5D0ULL, 0x71F302922086D9F2ULL, 
            0x0A665C6888A41364ULL, 0xCA2577146EF9E77CULL, 0xFC1C1BE37410B432ULL, 0xD8CFFD8ACDC5FB1AULL
        },
        {
            0xDC55FE8CD1976875ULL, 0x7D35DED4C4B6E8C2ULL, 0x5DF2475AEB53FBE7ULL, 0x1B07042FC2630A50ULL, 
            0xACA6961FBF0C0C9EULL, 0xC2B37B676087C06EULL, 0x78F78EA2E7EEC145ULL, 0x6F1B62D4A3AB8762ULL, 
            0x4B228F0A15F502A3ULL, 0x9F0D5A1CCEF6E27FULL, 0xF122D6DBD05366F6ULL, 0x8B065C5A10A033A4ULL, 
            0xA4226325EC8325F9ULL, 0x511B2D61FC4F5625ULL, 0x0D8AFF673BDDB66EULL, 0x4270ED4F2E86CB17ULL, 
            0xC43DF9A7D8D16512ULL, 0xDE92424D6740CD3FULL, 0x9EA9C0814047A11BULL, 0x5A96C4262C01A419ULL, 
            0x78C4DD9EEEE7FD38ULL, 0xEC135F576D467D39ULL, 0xA499C9AD9FADE0F1ULL, 0xD4979D5B7F5D54DFULL, 
            0xBA2469895F969BF2ULL, 0x7927BB35BC863B08ULL, 0xC70FF54FA2DE8EDAULL, 0xEDD1B158F3CB1631ULL, 
            0xAA917DF56E701F45ULL, 0xF81C5A57FE805E89ULL, 0x6EFF6E828E28F436ULL, 0x9A28C9101FDD22ABULL
        },
        {
            0x7D9AD3AB6567F659ULL, 0xF4A9C54684CB7A98ULL, 0x9CFECC9EFCC30D78ULL, 0xDAE58388A1134409ULL, 
            0xF5A2810766E12C21ULL, 0xC6A8F27B0D131424ULL, 0x72B25E7C43BC06D0ULL, 0x43B3B1D88D9A48DDULL, 
            0xC6F9B1CEA3DBDACBULL, 0xE0E38F8E76F941ECULL, 0xB19BBCC318DA5685ULL, 0x0CEEFDA9B9184890ULL, 
            0xCC780F1F31DDB44BULL, 0x8FB636786FA84744ULL, 0xA989D20C35A1098FULL, 0x2DB43F913D256B75ULL, 
            0x2F89C78FE21CCDB7ULL, 0x9172ABB23995EE58ULL, 0x5A6F22A20C9BFC91ULL, 0x05E54ECCEAC5E810ULL, 
            0x56EB936D8F81A00AULL, 0x563B05022FA1FE62ULL, 0x7087E1137FC569F8ULL, 0x192E25F2AFD55261ULL, 
            0xA2F4FC6CDC80AD72ULL, 0x0841354974DCF7D9ULL, 0xD40B89D31A43B67BULL, 0xB70B3652ACF7F240ULL, 
            0x418B6803049A8BF8ULL, 0x71B86005619444B8ULL, 0x7D86B8D51FD567CFULL, 0x8ECB240D4875353EULL
        },
        {
            0x156295B33234435CULL, 0x5501D0F4D41ED066ULL, 0x9FF2E94BB0A27FA6ULL, 0x9D1D3F5618498513ULL, 
            0x85A6F9C4DFF28E7CULL, 0x73E987AF56A0E1D9ULL, 0x789C65ECD97495D6ULL, 0x3F358796D842A470ULL, 
            0xA1608CDB87E2F67AULL, 0x420C7B1D4AACE4B4ULL, 0x904F61D6DC5E8FA8ULL, 0x40E6FFFD6EEC3652ULL, 
            0x7A3E26E0797B8E73ULL, 0x80307A7AB45960FCULL, 0xF45018DC65062A33ULL, 0xAF47B30D5ACB3F78ULL, 
            0x484D93F9952E5FD4ULL, 0x563CB17216FF43BBULL, 0x99F1CA4253D4FBECULL, 0x010B48D07EB1D595ULL, 
            0x983836250BE4318BULL, 0xCDB35581E2BEF515ULL, 0x54A09AA5ACEEED32ULL, 0xD95E82516B415296ULL, 
            0x8AB8AAB502953983ULL, 0xDB333853547CD4A4ULL, 0xF290C95DF4B413C3ULL, 0xADE0670028039F1DULL, 
            0xB4ACEF8642434D92ULL, 0x0E1DDC95E3562F53ULL, 0x23AD408D1B9A1FBCULL, 0xE6227EE486385F0EULL
        },
        {
            0x1665F00381EF6107ULL, 0x1A4A843BC29C6BA4ULL, 0xB966A568552E1C99ULL, 0xB4FD759D698FC6EEULL, 
            0xE7B51B4C5C98FB4AULL, 0x98A7DE0C3A579686ULL, 0x097AECB942BD8B41ULL, 0xF10786D78658A7B8ULL, 
            0x33F0A3BA152AB3E4ULL, 0xEA8543A67D3BACB5ULL, 0xB33008E2F2E60544ULL, 0x1C36B085BEB6E0B0ULL, 
            0xDC06AE979F8F6E89ULL, 0xFD157E9366892F28ULL, 0x2A6A35F7B7237AECULL, 0xA34D54D42436A65FULL, 
            0x4D2EECDFE054A2F1ULL, 0x48F975C193D3E7EFULL, 0xEEF9B38F9FCABB59ULL, 0x6523327F20922789ULL, 
            0x2A19CEFE20472ED4ULL, 0x613DE6F9CECE36A1ULL, 0x5328FABE150B39CBULL, 0x90DE59BC5C9C0AC9ULL, 
            0x3A50DB0794A7E0E9ULL, 0xEC609C1B1407896EULL, 0x91FCA1520A280619ULL, 0xC177898241F96B4EULL, 
            0xD132B082E3094601ULL, 0xA1DE0A19F86F0D76ULL, 0xE3540B8A33481E71ULL, 0xC99E86BA5C37A98FULL
        },
        {
            0x96B4CE9D0298C2BEULL, 0xE1BFFCF31C11CC30ULL, 0xD8A1DEAEAE819CE4ULL, 0x13650DCFA9CE5D36ULL, 
            0x8309E61C65DA0D47ULL, 0x4918BF0A6D22B06FULL, 0xDC5C948B9744F0FAULL, 0xEA89D19401252B1FULL, 
            0xA45CCE9E9F3EFA25ULL, 0x4334259EC0FC0ACBULL, 0x67729B5BE1B7F5DCULL, 0x3771EC2719206C51ULL, 
            0x30E1EDABBDE54F4CULL, 0xC653976C67BC8CC0ULL, 0xC2876CE0EEEEE42AULL, 0xDA314AD6BA2A232CULL, 
            0x228CAB23345656F7ULL, 0xBF5CB683BBADB04FULL, 0x5645481472892C6FULL, 0x695F4736C066D1DDULL, 
            0xE71A3B55997E4CE6ULL, 0x29B00D4CC02F5E0CULL, 0xA1B70DC46792180CULL, 0x63FF2A59C523B287ULL, 
            0x484A8F7D3AF7839FULL, 0x15DCCBC1382ADAC6ULL, 0x32DA61C10DA2E41BULL, 0x6B03AF20FFEE6480ULL, 
            0xCF22595B93B0A899ULL, 0x9D7EB752CC2D6F3DULL, 0xEB966B01F814E593ULL, 0xE4D451B4820B6F8FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseDConstants = {
    0x4699BFA69239C83BULL,
    0xB2D6D78CABB61B1FULL,
    0x2EF106B246193330ULL,
    0x4699BFA69239C83BULL,
    0xB2D6D78CABB61B1FULL,
    0x2EF106B246193330ULL,
    0x6BDCF593C18720B4ULL,
    0x958D1E4618F5F51DULL,
    0x88,
    0x0F,
    0x32,
    0x32,
    0x49,
    0x17,
    0x78,
    0x3F
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseESalts = {
    {
        {
            0xB6AE43584DE0970EULL, 0x8683F74F95D35D79ULL, 0x0FE46D4C0C2C55AFULL, 0x55BC6A412A9442F0ULL, 
            0x89A526EF45DE571EULL, 0xEE73C632A4E6AA18ULL, 0xC51217BC10C87881ULL, 0xBE8F7C132724310EULL, 
            0x27BB63FE0E9FF3E4ULL, 0x3705F8A5F17440ADULL, 0xEF231581D44446B2ULL, 0x6B7FA01184714637ULL, 
            0xD4BA792538F78FD4ULL, 0xAB9AD12A18A4C394ULL, 0x2C2EEA7BDF428674ULL, 0x01919BC8DA285F24ULL, 
            0x3AACA651D19F59CFULL, 0x01B5CC1436AD0830ULL, 0x22DE7E4E9836953CULL, 0x7979EBC65067BE51ULL, 
            0x8BA1B8F49627B3A5ULL, 0x48D5191EE2F2611FULL, 0x32D4F7FD01DE90F1ULL, 0xE04D5AAB6D90F67DULL, 
            0x062002CBCAA2C7BAULL, 0xD3C9904ED304096AULL, 0x30F7F9FF3805ACA3ULL, 0x1591AFEFFB102883ULL, 
            0xCF3B1BE5CB846D61ULL, 0x34C9A2E4DA357B82ULL, 0xFFBB6EE6F6155C38ULL, 0xEEF8AF414749BB4DULL
        },
        {
            0x3868522C4A3D6C4BULL, 0x22411567713BF0F5ULL, 0x9FE1DCBDD8A006ACULL, 0xE3626AFAFE72532EULL, 
            0xB5518E29294F7C41ULL, 0x2A7712E73159DE42ULL, 0x8DF725AB3CD04305ULL, 0xAAB780EBED1BECEFULL, 
            0x453BC81B2B8427E6ULL, 0x507AF0CE1380DFE7ULL, 0xC9DA48000AA2F504ULL, 0x6E230A6255A77D41ULL, 
            0x505919639126D6CCULL, 0x761FD6B72CF17B70ULL, 0x7E0AB54923D74A53ULL, 0x581496AAA429E6DEULL, 
            0xC218FF203BE97A94ULL, 0x841F574538E43EADULL, 0x37EAE0DAC630BD0FULL, 0x7497BEAF3A8F4C81ULL, 
            0xA2D40B231599FC7CULL, 0x351CE7C09370C144ULL, 0x932962A17167C5D8ULL, 0x22E0D28DFE5B227CULL, 
            0xCBD6B2AC5D4ABB45ULL, 0x00087669B4C95AA9ULL, 0x780AA94AA2A4E4BEULL, 0xC5C676BD635CA1E0ULL, 
            0xF78E07D48A8B7355ULL, 0x77B7CEF958BAE87CULL, 0xD7EFBBFF7D49C71DULL, 0x5C1D9419B23A6689ULL
        },
        {
            0xA030D446B78DFADCULL, 0xAA6514716F0B6B35ULL, 0x7686A6CF6E12C7F3ULL, 0x4C5C228295D9571FULL, 
            0xEFC98F296A944800ULL, 0x57F982628B244560ULL, 0x022FAC362CB946BFULL, 0x05BB3FF5FA1B5520ULL, 
            0x8D4D299A42D671DAULL, 0x6A7A9FAFBDFED9B8ULL, 0x8AD4833A2ED73C19ULL, 0x33B7572C33865897ULL, 
            0xF8FA264A31DEEEEEULL, 0x9699589F6C9192B1ULL, 0x6AAF1D0259D1E445ULL, 0xDBBA6D9BEFD242CFULL, 
            0x74E04A327AFB5669ULL, 0xA13455EBAE9631FBULL, 0x11FE41072A76F0C3ULL, 0x8969FC33E9351C2EULL, 
            0xF5B344D99AA3AE79ULL, 0x7D9B0EEDEC31C219ULL, 0x6D0E4259A65F48D0ULL, 0xAB3A14D3AA3AA370ULL, 
            0xF127DA1257FB2758ULL, 0x8495CB4FA5DECCE1ULL, 0xA83AEDD625918F78ULL, 0x91872B93BAA07EB8ULL, 
            0xBDD5EA63BFDC356FULL, 0x322D0EA2D2314F7DULL, 0x2FB77A87840F70CFULL, 0x448C471845C7C0BBULL
        },
        {
            0x784DE6F913313565ULL, 0xCB058974CBBEC5F5ULL, 0x4028BA4785B4F208ULL, 0x860062CC3BA0EF92ULL, 
            0x197354D794E7D983ULL, 0xF29AF881F160EA1CULL, 0xA2C3A4E6492F553BULL, 0xD4793635E666FB2CULL, 
            0x8316019FE8CE067EULL, 0x153A339FB96D019CULL, 0x6EF3D749EC643B01ULL, 0x30387A169067A45CULL, 
            0x33A61171C66871D5ULL, 0xD7CCEA2359C73D9AULL, 0xD725573AF0E7DC11ULL, 0x5A2D1B9758E1D64CULL, 
            0x35FC486F0540E89AULL, 0x0DD47B40E44EA418ULL, 0x2A7E9BE136482BD5ULL, 0x5BE5283702A0A9E4ULL, 
            0xA89003997459BD92ULL, 0x8105D15F61500792ULL, 0xCDCFA53E036489C1ULL, 0x73CBDF69FDF8CB03ULL, 
            0x2B8D311771716C69ULL, 0x26FED020BC6250A1ULL, 0xEB79C724C4279A8CULL, 0x985B8A8F95219603ULL, 
            0xAB17EA56616FEDDBULL, 0x56FDAF7927DF6606ULL, 0x588383463782F982ULL, 0xAA8939148FA0E5A3ULL
        },
        {
            0x5022922548FF98D8ULL, 0x06FF85743714225AULL, 0x96CD2E84AD589420ULL, 0x17755DA0F14A6135ULL, 
            0x852EF2FA34A5086CULL, 0x1296244FB1CE9466ULL, 0x2A9D169C38633C1AULL, 0x9ABEF6C40AABBCECULL, 
            0x1696A5BB9CB23208ULL, 0x72B4A4B6884B10D1ULL, 0x48C6318A72E1FEFAULL, 0xF50BEF1518F51FB6ULL, 
            0x01ABD4A1D78BB116ULL, 0x6E14EE764EBB6E7FULL, 0x833278CE9AC333D0ULL, 0x31620AA5A782EFC8ULL, 
            0x5C548BD0D0BC8680ULL, 0x218FFB5574750FE7ULL, 0xE47633418E980276ULL, 0x4773352D602D1020ULL, 
            0x63C70CBCDA0FBAE2ULL, 0xB6F358D50F06DF1EULL, 0x3842C30CBD6EB86EULL, 0xB9B100FB328478E3ULL, 
            0x8B8947EE6A0378FAULL, 0xDA30056603025205ULL, 0x8DC8D5A4645D9BD4ULL, 0x80F17637BA5D3D6EULL, 
            0xF703569B58CCBB2AULL, 0x926DB69E02A0DAA5ULL, 0xABA6298BA74D9D12ULL, 0xA9EE932FA3D96394ULL
        },
        {
            0xB5723CEC6C0397BCULL, 0x358373573C0C227DULL, 0x4EDD29D030FEB04BULL, 0xDE7ADB2692BCACFCULL, 
            0x685D76F30BBBBE8BULL, 0x87DE503A25203BC4ULL, 0x4EE84215AC03CBF7ULL, 0x8D0FB431C7F391C9ULL, 
            0x5B0F19DA1D668350ULL, 0x890829F345FCE39BULL, 0x1C831DEE686A7F16ULL, 0x77532D70D709E829ULL, 
            0xA4230D48A9A066D6ULL, 0xCCB784A5DB583BB3ULL, 0x1C955EE8EE0CAAFBULL, 0x93A4CC7B7E7D8CAEULL, 
            0xF06B201038542382ULL, 0xDA0A9063DB14C4F9ULL, 0x0344FD9B0055F407ULL, 0xCA4199C1C4A5F43EULL, 
            0x6631FD72393D301EULL, 0xF30DF0E8A0B1D4F0ULL, 0xF294662078216AA2ULL, 0xEB48C5F6098CA78AULL, 
            0x1E69B01CAA0DC260ULL, 0x35D48F6A44D49639ULL, 0xF88FFE9F3B80C05EULL, 0xA6709F3D4350DBEFULL, 
            0x0FD16F276AAED851ULL, 0xC6D6D2E8A5DB3483ULL, 0x9EEB131914D60392ULL, 0x7A0810D073537B9FULL
        }
    },
    {
        {
            0xD4E6737D2BD1852CULL, 0x2289119FB252528AULL, 0xAEEBBFEDCD7ADD01ULL, 0xEDB32FCE0DE1467BULL, 
            0xF420ED442B40FD99ULL, 0x05D03C5699298AEBULL, 0x31BA32FC2D2FBBA9ULL, 0x272932B206DDA6E5ULL, 
            0x0D174FA05001FC02ULL, 0x32839DB7F4FB122FULL, 0x81D00CC701E24CC3ULL, 0x6A11A0133C656F0FULL, 
            0x8EB7D91E9AE99521ULL, 0xA73628D2C28B2A13ULL, 0xA2A1C1D075BDF19DULL, 0x1641AC719C41CDD3ULL, 
            0x378D0702C6C54F03ULL, 0x8073F8EB2774E45FULL, 0xC9A63FA845E335A2ULL, 0x462E4B8F0C579032ULL, 
            0x0DF70A8B15121FF0ULL, 0x9F96681BB54A749FULL, 0x99ABAFAF4A1951FCULL, 0xDD53956E3DEEAC2AULL, 
            0xF8D5F29D64329442ULL, 0xB4EDD0EEDED5387AULL, 0xBADA08D61C571020ULL, 0xA097F1590A0919FBULL, 
            0x745FF2F8A49955F9ULL, 0x9C9644283389CEC3ULL, 0xA392393239A423D4ULL, 0xA2E5DB392B95FD88ULL
        },
        {
            0x9CB833116531757FULL, 0x5E6856EA896F428BULL, 0x72DED7365A4E035CULL, 0x838720B37E3A3674ULL, 
            0x6364EF14630FC125ULL, 0x96A9E0FA95783120ULL, 0x79AB4A1FA57661BFULL, 0x37F3B33104DECCB2ULL, 
            0xC44DA7946B498593ULL, 0x5E7BC4038783F06BULL, 0xD4B079859DC857E9ULL, 0x708199CB787CEBDFULL, 
            0xCD629E01AEC57086ULL, 0x1E273713CE4DA59BULL, 0x2C2D5A0B839EFE22ULL, 0xC3CD404F1F439CCEULL, 
            0xF9F269BF40F8B299ULL, 0x8A0A8F592B7B6B02ULL, 0xE9A6FD3ADB1E1257ULL, 0x3F90B6A8E3C7B6D8ULL, 
            0x3EDD423E9AF273C8ULL, 0xB3FB7E9E9BA82A08ULL, 0x381428E4201CAE33ULL, 0x8CB62E2CEE8CA02AULL, 
            0x74C73F9904F48AB8ULL, 0xD1015A70946468DCULL, 0x0B847B568E22AF0CULL, 0xB50000027EEBC8DEULL, 
            0x28E034FE820C19ECULL, 0x4D7852BACC853E2EULL, 0xDB95971DE72A6B4FULL, 0x0DBD862EEFDE318FULL
        },
        {
            0x21ED5D5CACB1975BULL, 0x7AE22C8C110F0665ULL, 0x21C399870244BE89ULL, 0x97EE17633B12D1A0ULL, 
            0xADA9DBC9E8040B8CULL, 0xD18F02416C7E75B8ULL, 0x2361BA549331AC1AULL, 0x9DABF91E2B0402E4ULL, 
            0xA94E326E8642D5E7ULL, 0x82947F019BC7E09DULL, 0xE1D3821EA2AC4E76ULL, 0x6BAD1111622AA361ULL, 
            0x662512706425F310ULL, 0xA276533DE086A030ULL, 0xB0B70741E9B186DBULL, 0xA6B2684CE3A74C9EULL, 
            0x28184E244C824DF9ULL, 0xC8009D06C7CD1038ULL, 0xEE14866C98F64F98ULL, 0x46E8348ABF81A45FULL, 
            0xCF3502B12DFD78C4ULL, 0x194C8A7030D730B8ULL, 0x673303EF78FB41B4ULL, 0x458D842DB94662B9ULL, 
            0xBEB69A81F540ABCEULL, 0x99052976326FE995ULL, 0x75004847E4E2B8B1ULL, 0x453E49506880890DULL, 
            0xA274CBEBF8562918ULL, 0xFA666D360B507CA1ULL, 0xE10FB94908A544BDULL, 0x1D8565588840C85CULL
        },
        {
            0x47761087D93DDE58ULL, 0xDDBF1916653110ACULL, 0xF524FB25A24DDE1AULL, 0x473DE0DC9FEF9176ULL, 
            0xE721D009F06BB7B1ULL, 0xA6731C16123A41BEULL, 0x2DA032AF951F924DULL, 0x727F4284022A8323ULL, 
            0x71FD29CEF0F05366ULL, 0xEE2936AF6CF5318BULL, 0x08C0DE464A42C9DEULL, 0x9C206BA5ECABBEA0ULL, 
            0xB4C5AADAC5CF1A78ULL, 0xAC7BF6316EC2E3C0ULL, 0xF8A3F75F53D0889FULL, 0x548F9ACB4F6C71DFULL, 
            0x158A160F4B26D83EULL, 0xB27F7DE0F74A8306ULL, 0x02444ECFAA44FA10ULL, 0xB1248404C25EAA3EULL, 
            0x2AA7A144097F6445ULL, 0x453865358C0FC4AAULL, 0x5DE0BCA42060F4F6ULL, 0x9CF945AC273B560FULL, 
            0xA9D3B45477DDFE15ULL, 0x566C488753A05498ULL, 0xB8609CF9255D212AULL, 0x2B6858396B038AA2ULL, 
            0x6A60115F36FE9641ULL, 0x120693AF9C032E2DULL, 0x5A82E7A00C3E5C65ULL, 0xBADA2AD8B714D37FULL
        },
        {
            0x3A00ECF33048646EULL, 0xBD1D371D5E1E7FA4ULL, 0xD2A873CF1E9F17FEULL, 0xD1404E2AE2833E2FULL, 
            0x5BDA58641167B9B5ULL, 0xB0231BC79D29ED56ULL, 0x9E8ACBA97F91D9DAULL, 0x7FF097CCF61DD956ULL, 
            0x44225FC4A53DB671ULL, 0x5EFCEB765D9F6ACAULL, 0xB2B502713D92963CULL, 0x34CF08B531DF3DE2ULL, 
            0xBED22E3E13D896EFULL, 0x892EBB5C41BDA369ULL, 0x3CB61DE783E1E968ULL, 0x86244AD6105E2682ULL, 
            0x02F423985EBEB013ULL, 0x5C166E3BE6A33409ULL, 0x26CD143F4D240FDBULL, 0x5185066092796DABULL, 
            0xB49832CBFA29666EULL, 0x37F7287EB26FA213ULL, 0xF854BFFFB0F6D063ULL, 0x9EE19A22FEDF7A95ULL, 
            0x8FC51984425104EBULL, 0x53015806F7752CD6ULL, 0x081F3FD4B79A1E55ULL, 0xC38B8E38AFED17F0ULL, 
            0x7EF2117CA96C0833ULL, 0x49665FE41CB8F465ULL, 0x12A1EA0332202D09ULL, 0xCC3DFA63F7E5C561ULL
        },
        {
            0x9BE5345E8473D77FULL, 0x099180AC14AAC586ULL, 0xD5248019A5E85D0FULL, 0x622E2362A63E20ACULL, 
            0xDF2FCE154458D608ULL, 0xF804D36624F20E6CULL, 0x5947321F82948E09ULL, 0xA806D6C772EC5B91ULL, 
            0x547CF5ADA8960BF5ULL, 0xAB9BDF0132568F52ULL, 0x35ABA3D18602A9ACULL, 0xEDB16F5650AF07E7ULL, 
            0x3189EA9701051349ULL, 0x5C4BB6A152A5CEEEULL, 0xC9E26C20AF34919EULL, 0xE4A2E2F32A6BFE46ULL, 
            0xD1FD02A8D32AF64BULL, 0x525A9CDE98B6AD55ULL, 0xD10D237F5073ABCBULL, 0xC3401C28E0AC0ED2ULL, 
            0x82DD12DAAECE423EULL, 0x8D65EC31F0727E0CULL, 0xDFBAE403D238CE71ULL, 0xBFF3C0C227CA2986ULL, 
            0xEF51685C2830AA73ULL, 0x961DF815AAC8E408ULL, 0x8BC5F2EB5184B7BFULL, 0x52E4AFEC61CFE654ULL, 
            0xB58F8E16669C1E3EULL, 0xBA6617BA11B344EBULL, 0x1CF43DABE52F6970ULL, 0x469DBFB823521A1FULL
        }
    },
    {
        {
            0x9D1B610B823EEA21ULL, 0x30C0FDDAEEF74442ULL, 0x98646B507C9CDC1AULL, 0xC42B818D32116018ULL, 
            0x24AE268644D98D80ULL, 0xA438889D13EC80E4ULL, 0xA5CB56AF60BC9D40ULL, 0x5525F7E6E5F9D6D8ULL, 
            0xE3BF36E726FCA656ULL, 0x6ECF74B21173511CULL, 0xF972BB2325AB7103ULL, 0x6FE7B0768286FEB0ULL, 
            0x86B173B6E81FAFAFULL, 0x54C087826C9B307FULL, 0x1FC8A3C8FFC822C4ULL, 0x02ADAC362098F118ULL, 
            0x0322C0B9CF0391BEULL, 0xDC33ED0C85FBB1C4ULL, 0xEBCD866901CE9240ULL, 0x2BF408046845F736ULL, 
            0xE9B107EB4681DE1EULL, 0xD50A1BA05C309D1AULL, 0x37F7AAFC2ECA196CULL, 0x77878C9C70606E0FULL, 
            0xB8C1DC82E141D1ABULL, 0x826AEE577B63E295ULL, 0x1D4E1FB0167DCD2BULL, 0x95D81EF215DD9D6AULL, 
            0x7A09B2932FC1E018ULL, 0xD2A4D18C6BE876D6ULL, 0xB25BCAA95CA227B9ULL, 0x4F1AC77D096E875EULL
        },
        {
            0xEF7AC0FFE118449CULL, 0x0770FBAA6C893BB3ULL, 0x02906773A01DE49FULL, 0x4D880B49897BFA98ULL, 
            0x663B3D95E97EF915ULL, 0xA86289FD6447E92DULL, 0x81DEC5E454EDAE6DULL, 0x46020F08E6E71D20ULL, 
            0xF748A76D28849550ULL, 0x4AC4941BFBD33D7DULL, 0x8346537EF238CAEAULL, 0xD4FC6C78CE4FDE78ULL, 
            0xFFAC7C9A17AE3ECBULL, 0x478DCA1915C4A2BBULL, 0xFB0A6B3397B17135ULL, 0x0C4910D90E0FD941ULL, 
            0x8CE7115445C27D9AULL, 0x7B1BF4F9389E5F37ULL, 0xBF645023CFD0BCB0ULL, 0xEBB8C72647AAF227ULL, 
            0x55DBAD9A3C7E81DFULL, 0x636EB27413BF8497ULL, 0xFCB77C3EDD4D901AULL, 0x906DCC4D1AEF0750ULL, 
            0xE28E200D7358D014ULL, 0xDE0B9265C47F9313ULL, 0xF9FEF06731075FADULL, 0x5FE581F529942841ULL, 
            0x4647393FD4E36682ULL, 0xB8F8D0083EE76124ULL, 0x5451694F8AC1F538ULL, 0xF40882E0B6AABE96ULL
        },
        {
            0x9C7A3EA94B191765ULL, 0x069DA58C3FFE9108ULL, 0x639707D5EACA6F41ULL, 0xB2B81555D3DE3A74ULL, 
            0x25CB37E3444AF293ULL, 0x8A26186CD9F03B57ULL, 0x9182B66EC1528653ULL, 0xA9B39D090A40DF12ULL, 
            0xF62DEAB7FB472952ULL, 0x464A5F29A77FA8FCULL, 0x17024BF6F6462BA8ULL, 0xF7C12B3277EB3FCAULL, 
            0x14F8826B49342BC7ULL, 0x2EC0DF11B819A7BBULL, 0xAF632899C0169EC1ULL, 0x59912C3FAE0F62C6ULL, 
            0x69D41B544FF8D756ULL, 0x35ECB44387A6A159ULL, 0x678935D0C8F90A2BULL, 0x3C43EF512C5249B4ULL, 
            0xBDB3040780586546ULL, 0x4E656E011D248074ULL, 0x880AB217766CDEF0ULL, 0xD073DA60E298BF8BULL, 
            0x4407AE229418C930ULL, 0xD5B121AEDFA70F35ULL, 0xA8397E543204D65FULL, 0x9B9072A1640CE088ULL, 
            0xDE03FC8242CB4A48ULL, 0x080B9D9252F633BAULL, 0x1E8B9DB2CBAF0888ULL, 0x7DEA2E55B145EBADULL
        },
        {
            0xA3371BED38DBFF7AULL, 0x3CADF65489CA3F3BULL, 0x651A8B6791ABF8FCULL, 0x28DB2956AA81B3C5ULL, 
            0xE3DA2318B30394D5ULL, 0x92A6EA2718887D44ULL, 0xB16F2C180AEF5A2EULL, 0x63DC846F4C3FEF8BULL, 
            0xEC995D66D9F165C5ULL, 0x6DD5147CE0301AEFULL, 0xC0788FFD40CC213FULL, 0xC550D608D3E83CE1ULL, 
            0x6C1C923BC8787F48ULL, 0x1AF7C6E800232ACAULL, 0x068047EF19273127ULL, 0x407D6EFEF7081034ULL, 
            0xB3F68F3EC1401A40ULL, 0x231E8AB63DE41A95ULL, 0x47A4172883441E69ULL, 0x9E62E29CAFECBD72ULL, 
            0xB7403B76C19A7870ULL, 0x8774F92890E797A5ULL, 0xE777BD7608DEBC08ULL, 0x89B9BFF214A52B60ULL, 
            0xFC9F3E1A9F2661DCULL, 0x703EDFD1358F7FA2ULL, 0xEDC691B6C2A29A9AULL, 0xBB2810C01A81B352ULL, 
            0xD6B7FD0EF9754290ULL, 0xDEA2DD96C3CC05A9ULL, 0x5BEE1906D22F1EAEULL, 0x3AE9738CA393F613ULL
        },
        {
            0xE7D67EB72707DDFEULL, 0x6A2ABBEF6FA0E31DULL, 0x6CC1EF80821EE030ULL, 0x8A920C29D8AE2336ULL, 
            0x3B4074C242F00A62ULL, 0x928317E87ADA6F5FULL, 0x2EC5A5E44D6E7DFEULL, 0xDA928F9D3B16D222ULL, 
            0x7FC0A0B85F124E75ULL, 0x462C98DA5EECB694ULL, 0xB7D5E8E7F9C58271ULL, 0xA83201EA99355436ULL, 
            0x23028FB6116D01F5ULL, 0x70B8BF3E14914019ULL, 0x22DC44ED16228D10ULL, 0xD69354332F91D7F7ULL, 
            0x78229AF87FC74D77ULL, 0x62A3A0E1D624D6C5ULL, 0x57C46ECE12D30F43ULL, 0x484837E30A702375ULL, 
            0xA841A4F46BB6D3D1ULL, 0xDFBCF8B161932655ULL, 0x9AF6710FC684BA36ULL, 0x6AE721A9513D37D1ULL, 
            0xC903F90EB195A424ULL, 0xD9EDCCA051F6132DULL, 0x10F8C99175AE34E1ULL, 0xCA6B84CC041827EBULL, 
            0x03BC34821A416DD5ULL, 0xDCEDEC62B37FC04FULL, 0xFC132CFF224075A3ULL, 0x4DE54455B05AF964ULL
        },
        {
            0x2B56699D9EB3C2EDULL, 0xDE1055A70BE61DF3ULL, 0x358A334BCBC04378ULL, 0xD4C4D3FB1C5F638CULL, 
            0xB976BB103C00FD47ULL, 0x871CCA2E59845E6AULL, 0xF46343C30AAE7E55ULL, 0x2B9BF23C6D84A828ULL, 
            0x920F3D75807234B3ULL, 0x0AB3904019AA3434ULL, 0xA570E64ABC34FC46ULL, 0x383293528D530DF7ULL, 
            0x18CF4A72F545E8ADULL, 0x96FB2D4A0E1AA05CULL, 0x9CBD092E3138EE8FULL, 0xC91E3B32FE656548ULL, 
            0x53C5710DBFD50846ULL, 0x2B6361BF16F983BAULL, 0x67A0052AD443EE85ULL, 0x334C5DB75DEF6EB7ULL, 
            0xFE33CB1FE5BECCFDULL, 0xCDC679989314F5DAULL, 0xD01C3E8996EF83D1ULL, 0x13B4D05E928ECE3BULL, 
            0x4479772A54D37D8AULL, 0x7E944E24374AFF59ULL, 0x21F048B86D90FE7EULL, 0x156A10D9286A685FULL, 
            0x42663EF67C4E4AE5ULL, 0x591CC86A23C5A9B9ULL, 0xA1006FD11F80930AULL, 0x7E510D4184DC05DCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseEConstants = {
    0x2237731AD133A722ULL,
    0x9264CC3723CCFF69ULL,
    0x7D6F67628D982C4EULL,
    0x2237731AD133A722ULL,
    0x9264CC3723CCFF69ULL,
    0x7D6F67628D982C4EULL,
    0x9F8A54D35D2C2BF7ULL,
    0xA6CC5A4A55E27440ULL,
    0x2A,
    0x17,
    0xBF,
    0x50,
    0x8D,
    0x1D,
    0x99,
    0x38
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseFSalts = {
    {
        {
            0x707BA5DF2F09FF23ULL, 0x3CFD805EDA8C5520ULL, 0x956A4A1F4EF3C0C2ULL, 0x30FFFA651F9E1F55ULL, 
            0xF6C377A0543E551DULL, 0x2A3B2B94DF144C04ULL, 0xA52E3F5E19161CDBULL, 0x206E9A6BF2AC1CC1ULL, 
            0x80705CB7703A5F8DULL, 0x889002167933D45AULL, 0x5F02ED23D4DD731BULL, 0x0C716FDC3BAE3204ULL, 
            0x55E72A23C6322059ULL, 0xC9C96032378E9BB5ULL, 0xB48473CD86C95508ULL, 0x5EFAF38FB6BF4D12ULL, 
            0x76DE9911BCDE10BBULL, 0x2085DEE9B7A58AAFULL, 0xFECD5EACD828E646ULL, 0x6403CEED0516BE6CULL, 
            0x734B4BA84ADB8C70ULL, 0x4EA6F9ADD399D4C0ULL, 0xE43707E907F57950ULL, 0x29D1107A84780603ULL, 
            0x088A13E3DF09AEBFULL, 0xF7C4CFABBC18A75EULL, 0x09E3389139AD3A35ULL, 0x3876B13DEF164C64ULL, 
            0x36BFCF6893297C1AULL, 0x7BE3996DB98B3E2BULL, 0x17EABCAB25197FBFULL, 0x76912B3BB9A81AB0ULL
        },
        {
            0x96E8F11BF685C3B5ULL, 0xE235EA195278F735ULL, 0xF39E78A036D2E20CULL, 0xF510AA0373AE9069ULL, 
            0xF16049A5E17C2EF8ULL, 0x11BAAACE071C4F93ULL, 0x957D68A3C5CCB8E5ULL, 0xD71E304587A4E7FAULL, 
            0xFE3236A3A5F5B276ULL, 0xF97436831E377946ULL, 0xF0C6A1CD2F0E453BULL, 0x3B63AC9EC8D9AF09ULL, 
            0x639F9606C7B8330EULL, 0xDFB87423CF32CD59ULL, 0x811FE4E65D2C334AULL, 0x3A0E63498F481921ULL, 
            0x1985509201B47320ULL, 0xEEE09923AD8D187DULL, 0x04AD595D8BC2534AULL, 0x06CFD4FBF3EAC267ULL, 
            0x9E48D10C17C01CB7ULL, 0xCBE62F53505A9A17ULL, 0xF766E6E191C1E3C4ULL, 0xC191E54B3317E712ULL, 
            0xB93D96A35A6109C7ULL, 0x8B1C080BCBE60076ULL, 0x44FE9867B464DE1FULL, 0x7E23A707B0248E81ULL, 
            0x2DF658835D57A81AULL, 0x818BE37A37AECCBEULL, 0xC0ACA1A1679781F7ULL, 0xB53772366011723BULL
        },
        {
            0x901D72F44706B9F6ULL, 0x3756E2EE1E4F0835ULL, 0x8BB8C0FE98D1FA6DULL, 0xA2A49D7094B9C4B0ULL, 
            0xA4D90DDB5169FDA0ULL, 0x8D7D97E5D7894F5CULL, 0x7CDE06C4D1717E2FULL, 0x58C37937F72DAD52ULL, 
            0x0F4BE2917D515BEDULL, 0xE7DC0209F0E836CBULL, 0x0121C0637576948CULL, 0x8F20966B25A6C6D4ULL, 
            0xFEC4E4FDCF7F3DB2ULL, 0x470FB3D050473C12ULL, 0xD20BA8B1D0EAA07AULL, 0x5EA6E3B1E9CEFEAEULL, 
            0x6436E28090B9D18DULL, 0x5B41EDF42E772D56ULL, 0xABADA920126D3D75ULL, 0x109BFDDE32AE84D7ULL, 
            0xFE90F4FA93F5EEACULL, 0x5ED6692B637CB848ULL, 0xE73476084BB5B180ULL, 0x49E3ABE2478C19F2ULL, 
            0x88486C7A75E8BA6AULL, 0x4475EE40042BE324ULL, 0x39112A0243E66251ULL, 0x7EFBEE5A206C77EFULL, 
            0x66098F2D91AC69A0ULL, 0x0C795531FDBE1D0DULL, 0xD827820F843EAF69ULL, 0x2D890126C878156AULL
        },
        {
            0xAF019E94D9E52DBFULL, 0x456FB019B706F1E6ULL, 0xD98EB3181B301FE9ULL, 0xD41A6ED56676B57EULL, 
            0xAB8B6C96CA0305B2ULL, 0x3C50E90168C0A29DULL, 0x6DB39EBDD24A8112ULL, 0x4C389F22429DA517ULL, 
            0x27DA1EB325F97AD8ULL, 0x4974832F894799A9ULL, 0x1C3DDEE661EEF22CULL, 0xD2B0495B75797E36ULL, 
            0x5D38EA0C831C2937ULL, 0xD9F76ED1170D4A77ULL, 0x42CCE829DC3B4FA1ULL, 0xCCB27B0B671D8032ULL, 
            0xE65862F05EEB68D5ULL, 0x57F26374F5440773ULL, 0x09BD79972177DF25ULL, 0x75F41D26940B6E52ULL, 
            0x0988E4AA2D514482ULL, 0x32F0F3794C450180ULL, 0x659FFBA697ADE0E4ULL, 0x313EA0B96FE83E2EULL, 
            0xD572C24D913E203CULL, 0xF6B8411A954EFEE6ULL, 0x4B182C45D470A383ULL, 0xB9EB5251D76CFB78ULL, 
            0x89228995AA7FBF47ULL, 0x9A9337A8A5FDDB66ULL, 0xEC62334A360BB79CULL, 0xABBD30694650DD14ULL
        },
        {
            0x652840F5E3348EC9ULL, 0xC1976EAD5186EC92ULL, 0x0168E5DBA2E2C69AULL, 0x6D4C7921E582B278ULL, 
            0x90D9BB116FF64284ULL, 0xEAC6ABDEDE82DBDDULL, 0x9C7B63F8BCE81CBFULL, 0x1EF9CCB3180F7319ULL, 
            0x4F344AAA673A0DC0ULL, 0x19B2601F99FEBEECULL, 0x00F32801B772799BULL, 0x7F3A67DC9676A045ULL, 
            0x2C8C3B700CBF861CULL, 0x1179C4C7B5FADDDCULL, 0xF3B4638BDC6D8EA6ULL, 0xDD64D59961778521ULL, 
            0x23CA46C2D69BED54ULL, 0xA731A78DB4520AAEULL, 0x0D3700B50C2CD9F8ULL, 0x9AFB15275E8876E0ULL, 
            0xCBCE92B7753603E5ULL, 0x82D552236FC6EF04ULL, 0x28C3082A255BA44DULL, 0x72433D0C62694E6FULL, 
            0x55F3CA43FD7865F6ULL, 0xC566F39D2D2C5B85ULL, 0x4E9354E87E8B8456ULL, 0xA4A842F81B846F8DULL, 
            0xFCDB427467E93001ULL, 0x7531E239A6B35EE6ULL, 0x0689D027BC542DC3ULL, 0xB8C7BC99DC4399ABULL
        },
        {
            0x1A080C4A6EB3651DULL, 0xDAE0BDC2CD203F9BULL, 0xDBEF893C1653CDFFULL, 0x0486AF0667D347E1ULL, 
            0xAA91D7D7CD6A48A5ULL, 0x3A8569634A9FFCF3ULL, 0xF93BB88A7A655E29ULL, 0xD6157E41B68E764CULL, 
            0x513CFAF03419FAE3ULL, 0x32CEFAF245D95299ULL, 0x77C247168532B464ULL, 0x7BD1EE1C15CD6B8CULL, 
            0x47C466E795F619A6ULL, 0x6CF48446C601C7AEULL, 0x87B87108454C15CBULL, 0x40E5D9D2AB780642ULL, 
            0x7568EC74C17B241BULL, 0x0824BDECDEF8DF18ULL, 0x4DA48C6BE4C8B9BFULL, 0x6C6BC034F6A10E35ULL, 
            0xF388307F26217078ULL, 0x80310DFBC979D5EAULL, 0xE4AB3D69C18313E5ULL, 0x4A76239394EAF202ULL, 
            0xAE629CCB53806C79ULL, 0x14A771B6D043F520ULL, 0xE0003682E4961DCAULL, 0xE3C0D1F40637EFA2ULL, 
            0xAA4A553D9E5BD742ULL, 0xBA08D1468EECF189ULL, 0x360E6C88BC6C859DULL, 0x1C6917745A6974B6ULL
        }
    },
    {
        {
            0x8E6E65F1EECA49ADULL, 0x00AAD101FED1B111ULL, 0x8AC831BCC3F58310ULL, 0x4DAF33C967968004ULL, 
            0x7B4D6F934570CBDDULL, 0x8040DE4F570B71B5ULL, 0xC76CE59D2AEAD79BULL, 0xF3EA9D7B13D11C80ULL, 
            0xB92C698C9A727B65ULL, 0x723828DEC9C76A16ULL, 0x344243285A7FE8E5ULL, 0x9FC215CC7656C21BULL, 
            0x661F39ED2907B0E9ULL, 0xD45905950F839084ULL, 0x369DC4C710112F33ULL, 0x224D4F2CB8BAD4F0ULL, 
            0xA723C77D0FCE3DBDULL, 0xEC7DFE4681D222D3ULL, 0x943FDFEE96D20150ULL, 0x3C7AF5E4ED1BB17EULL, 
            0xED5BE0B4BC77F02DULL, 0x931DA4CF02E0623DULL, 0xA99ED9AA44F4D432ULL, 0xB36D77234FF28674ULL, 
            0x656DF592D3A28369ULL, 0x44D089A12EC0D389ULL, 0x81291973ED1806DBULL, 0x4EDA8530D88A7873ULL, 
            0x937CE3751ECEA6CBULL, 0x89018AA386665CD9ULL, 0xACED8B4F9FA0CF53ULL, 0x5D4F28C9B88DD4A9ULL
        },
        {
            0xD55287756C1612F6ULL, 0x16114E26782939ADULL, 0xFDB1A1369A376DF5ULL, 0x081A04C865F8E166ULL, 
            0xE377EA35FB98535EULL, 0xFEFBB5721F6374D4ULL, 0x2E88D50E24EADC57ULL, 0xE8229F66B0C4FE3AULL, 
            0x4BE7511CD7580878ULL, 0x7962043E07271173ULL, 0xB252CD973BAA968CULL, 0x0A272D8E087D75CDULL, 
            0x90C4262466420AE2ULL, 0xC8D80A7ABB20043BULL, 0xA5FFE19A082E15B4ULL, 0x6F353AF1FFE035A8ULL, 
            0xD32E402957BCEC55ULL, 0xDB236BCF1BCCCB6CULL, 0x4BC0348C2FB24EF9ULL, 0x58DCE5FD5BC0C20BULL, 
            0x3095F4B3793080B7ULL, 0x91BE0DC871116D57ULL, 0x56E1A11211F566C2ULL, 0x45096ACAB285431EULL, 
            0xFC41FBF0CC97409BULL, 0x75EDC3A2EABCC531ULL, 0x25F81719DE3DCAABULL, 0xC012B3BD3DE9F1EFULL, 
            0x24CF2ADA0BCEA120ULL, 0x380BFF9ADFFAB51EULL, 0x349B830FD8564E9AULL, 0xD58C183DFBAD89B6ULL
        },
        {
            0x45B1C3E8C987D8B7ULL, 0x0A4843DB4C8D3015ULL, 0x04BABC2F1271DC9FULL, 0x808EE3F5A8F18C4EULL, 
            0xF0ECA724A3070FB2ULL, 0x3DB45E0905CEB339ULL, 0xB1304831E4C3CC05ULL, 0x87D299DD6A879C2DULL, 
            0xE5CD62FBEC92D908ULL, 0x92E8A24D4DB4AF9CULL, 0x35E09D5AFDB426DDULL, 0x447C20305C8905DBULL, 
            0x2735395808C825C0ULL, 0x0B69AD5C1804390FULL, 0x059C7F2E49405A5EULL, 0x512865764A56422AULL, 
            0x723E41FB9F0A5DE6ULL, 0x8A1E9557ED396333ULL, 0x45F9491802A535B7ULL, 0xE7AFF962E2181231ULL, 
            0xC297A5842D5CA5B4ULL, 0x7DC03ED8FCFFC80EULL, 0xEE736721132F665CULL, 0x90D8354A09AE845CULL, 
            0x71FA7E5394749D2DULL, 0x7D6C651D719F9A1CULL, 0x5FBE63A663954966ULL, 0x98930E25713C9B2DULL, 
            0x25C8FB9E51982AE7ULL, 0xA8D84D565B85987EULL, 0x4E67C0E84076F1B1ULL, 0x7FDA0428912FE8CAULL
        },
        {
            0x4777FE94992E9C42ULL, 0x10F1D81417F5A45CULL, 0xC5E44654DA1A40AFULL, 0x181996207DA156B9ULL, 
            0x3A1B9A674B925CC8ULL, 0xFC8524FE6D6DFC72ULL, 0xB6645532672EF4AEULL, 0x2C5E824E7BB0DF80ULL, 
            0x93FB2AF47FF6E4DDULL, 0x617F09D46C6E7F1CULL, 0x696735A5EE07E1E4ULL, 0x4AA7C45666670118ULL, 
            0x18C3DD948893E170ULL, 0x5061CEA4514A157DULL, 0x8D9BF91BF9D2023AULL, 0x316081F94678A18BULL, 
            0xF495EB80FB40A8AAULL, 0x6E5D579BCCC85368ULL, 0x44254BF69904352DULL, 0xAC58258207F448EFULL, 
            0x60D00DAB8AB37DBFULL, 0x03502097C597901CULL, 0x454EEDF4B2D02D9EULL, 0x2897546266F56013ULL, 
            0xBB8F6BDFDA3EB5EFULL, 0xEDB9D5B0E2F73D83ULL, 0xE82D616F8C34D489ULL, 0xA8E75CE2BED8D15FULL, 
            0xDF0BCBA8AF581F9FULL, 0x79BD50C4B68B2018ULL, 0x71DD8E53FDD3E3C7ULL, 0xA6B965493BB4B384ULL
        },
        {
            0xF79ED45FEFEF76E1ULL, 0x55D46068F185B223ULL, 0x3C6EE3ADD43FC4F0ULL, 0x2B86748F2ED414D0ULL, 
            0x127663C7DFFEE4D8ULL, 0x7B262A75522F47B9ULL, 0x4BD89AAA77018A39ULL, 0xB05AFBCB0E2D5BD6ULL, 
            0x976FA36D1200CD2CULL, 0x92589667CD2C7ADEULL, 0x3C28C72C55444A3FULL, 0x5DA023B91FF61391ULL, 
            0xC06CB9CED73FF028ULL, 0xC5D6B6652704F9C3ULL, 0xFB9ADC248C592CBFULL, 0x5A6AD100FC7338AFULL, 
            0x5BDF156170116806ULL, 0x9741C9BCDF369319ULL, 0x288A8F683AECFF87ULL, 0x0AA9E68697E5C4A4ULL, 
            0xD843F8A6C8570CF6ULL, 0x151B8E1D01F4399FULL, 0xA45C4AD19D893C3BULL, 0xF999723FF1D82DD0ULL, 
            0x3BF3C0C46840B4F5ULL, 0xB6BCC30F239B5162ULL, 0xF4DA5A9043542F26ULL, 0xE4E043641447EF10ULL, 
            0x1D928105C623677DULL, 0xD774592A1C90E5F0ULL, 0x316A417F146D4189ULL, 0xCC31ABB63D135E6EULL
        },
        {
            0x6A6EE50F35DE6887ULL, 0x227CEB9E6B500B90ULL, 0x4540826D8783B659ULL, 0xD2B463109FD4F4A6ULL, 
            0xE150770666A17185ULL, 0x25FFA4F65621D3DEULL, 0xB1573DFEE92767EFULL, 0xF6F8A46DA864002AULL, 
            0x5B4600254DC58B1BULL, 0x7F715987FBE2571AULL, 0x7043A1FF4F778029ULL, 0x6A447CDE85F838ADULL, 
            0x7DFBCD54B0246E73ULL, 0xE52D1C6CCE6034A1ULL, 0x05CAC0E2C70CF9B5ULL, 0x13FFEDC62693340CULL, 
            0x2C0E4C3AF0AFB5E3ULL, 0x64BBB1918E520AE8ULL, 0x23791C3D0484AEA8ULL, 0x577EC60803FE2D2AULL, 
            0x2ADEEE86806EE926ULL, 0x5929C4B14EBD5C55ULL, 0x3A103DEA059D41BDULL, 0xD0624C05FA6971BFULL, 
            0xD02C3A21296479D3ULL, 0x7D60234A73F09342ULL, 0x36A5AF3EB9A27339ULL, 0xD81E7BF16B609B0AULL, 
            0xC6AF4F5480FB1491ULL, 0x01A6CE466B721734ULL, 0x7BB820313639B63CULL, 0x7E5702419824C985ULL
        }
    },
    {
        {
            0x4077E6A347F32535ULL, 0x933C76C18586C7BFULL, 0x816FF86331BFA159ULL, 0x5D8D877CE49CE7E0ULL, 
            0x2986C795EC91045EULL, 0xE211869F36E7976FULL, 0xE15F82CACA077012ULL, 0xDA27BED2AEDCBE65ULL, 
            0xC12B6020173F6D70ULL, 0x83205723DA4FDF70ULL, 0xC8B6AC519D9804F4ULL, 0x63A27FA409DA1FDDULL, 
            0x4174ACE1D9681064ULL, 0x0CF2F95EB24475A3ULL, 0xEBB807FE1DFE7B8CULL, 0xFB61D7A242E4B05FULL, 
            0xA569AE172BA27F27ULL, 0x89E49F17652A7779ULL, 0x1F4AB3FBBE78A704ULL, 0xD0850CFFD836F516ULL, 
            0xF684CB60429046D0ULL, 0x5DA326C53818FCD8ULL, 0x48E4DEF4B54C91DCULL, 0x7E5774260729824DULL, 
            0xC8166B729F860B3EULL, 0xB890E7ED74849963ULL, 0x785A667539567510ULL, 0x172F3F9D202F6ED5ULL, 
            0x5BA8A144E7F7DD73ULL, 0xF8C731DA2CB25114ULL, 0x0E1C9CBD87E0707CULL, 0x5FE0FEC14077087BULL
        },
        {
            0x13A0A61497E1F432ULL, 0x4B7AF5B7E80EF274ULL, 0x5FBBF894F70A4401ULL, 0xEABBCC2AF7B2EEC5ULL, 
            0x0BFB853FB6992B2DULL, 0x7AADA92C015E941FULL, 0x32159EECF4FB5DE8ULL, 0x664EDBB8744BDA2DULL, 
            0xC58184E6DC58C3FDULL, 0x7B59EC1B5F5559AFULL, 0xE29E4B34298EFCCCULL, 0x96703D95579882BDULL, 
            0xE676C7F807658731ULL, 0x075A78D8B98E4FA1ULL, 0xACCA38A8093A51BDULL, 0x02ED01C6CEFC0FC5ULL, 
            0xC4BB3E741BACADA3ULL, 0x6838F986E6E1FAF0ULL, 0x006D1AA88BAE95C0ULL, 0x30FB7343571D2A86ULL, 
            0x5605EA4CC67FDD74ULL, 0xE5A0695D956531D4ULL, 0x062F6A0F561831E2ULL, 0x6BA5262BA405E57AULL, 
            0xB2FDDA778DB25406ULL, 0xF80EAF5E18932CF9ULL, 0x32F6A0AF157061AAULL, 0x29C1F435826A2F49ULL, 
            0xB2C3DFFE48FC279CULL, 0xC056EF7E3542E5D7ULL, 0x8D32596E8607A6EAULL, 0xB66BF9EB05781E1FULL
        },
        {
            0x1519A18CA72B5446ULL, 0x36EF3CD00FBCE1A8ULL, 0x16F42F0159A5BB88ULL, 0xBCD9D99FEE2A5F7DULL, 
            0x7D4D658EB77D3BA0ULL, 0x9DE3C7B7973E3AC6ULL, 0xC1841053A0FDAF77ULL, 0x647ED6CD273E9809ULL, 
            0xA9F94C3CBC72A5E8ULL, 0x59A83240AA6FA38AULL, 0xB7ED76A7EA777421ULL, 0x080A230923C6756DULL, 
            0xD81A06C884A3EB66ULL, 0x1CB90C65FE5DFC30ULL, 0x1E52C59B14E35C39ULL, 0x57366E8914A99BC2ULL, 
            0xFE7AA81F1470B9E2ULL, 0x9E5928225C4351BDULL, 0x08432F43EA9FD192ULL, 0xFB1908770ABD44B5ULL, 
            0x8D67F5831EEA90C1ULL, 0x7FABC1AC22919504ULL, 0xDD91C2463448783FULL, 0x2778C6E1404F989BULL, 
            0x3D7FE2C5A312D4E8ULL, 0x5787738AE7DDF41EULL, 0x4E6E3C4ADB876682ULL, 0x697A018010F90EBFULL, 
            0xDF35DC4313BFC565ULL, 0x3E685867DB063369ULL, 0xD7AA5DF33F72FAB4ULL, 0x2AB3614C33B613EAULL
        },
        {
            0xD59D6DF5E6629EBFULL, 0x10748182772D0C4FULL, 0xA1F69D1CAFBB89D4ULL, 0xCDB0126325329072ULL, 
            0xEC1BD7DE0892939FULL, 0xBC189DDFC9B8172DULL, 0xE1016C5253A8C3DCULL, 0x98050DF7406AB9E3ULL, 
            0xCA3176D82E9886C7ULL, 0xEC7C8DD1E4FDCDD2ULL, 0xAB276F563321155FULL, 0x6B407DBCA6250DF2ULL, 
            0x58F31A53A9953E50ULL, 0xE71DCE6C46345F04ULL, 0xD651E5180847685EULL, 0xDD939936DF97AB78ULL, 
            0x83FED4D79F44543BULL, 0x09CD45A153AB3F4BULL, 0x135C76A73F1F7811ULL, 0x06A46EA7CE8CDA7FULL, 
            0x54A4C65E45A336F6ULL, 0x142CCDD40EEF1036ULL, 0x26C9AC3CE17073A2ULL, 0x12DAB9B7BEAC014EULL, 
            0x7FB56553708D2839ULL, 0x0DD15DEB8FD0605EULL, 0x1BCEF6996FB7608CULL, 0xB7A3ED81E796C07BULL, 
            0x1E5857CE3BBAD8F9ULL, 0xBB359B84866F2348ULL, 0x324537D4E57A0AE1ULL, 0x071BA01E4FCDAF19ULL
        },
        {
            0x2A3D720DD0ACFD55ULL, 0x720C16635A3DC081ULL, 0xE9D18D936BDFAFA2ULL, 0xC611E2CA674EFC24ULL, 
            0xBCBD86046681D7F0ULL, 0x45C2FB1C2C35D00BULL, 0x36A582A571A74C7FULL, 0x23A5EA8EBB3EF815ULL, 
            0x9016FC707EBFC971ULL, 0x44183BBB41145294ULL, 0x1769613B45A2238DULL, 0x9B38D044A9722FF9ULL, 
            0x4B2C4EB8D9B562BEULL, 0x3A325A909A95D6E2ULL, 0xCDF040780BF4C4C0ULL, 0x0751B696B86C4935ULL, 
            0x7577B48C73F26222ULL, 0x21D6C2EF9220DD10ULL, 0xD3C0F960447DC153ULL, 0xD3050E9FC61D96B8ULL, 
            0x5FEFB748C323A6ADULL, 0x2758DBF3B0ECDDCCULL, 0x80E731761DDFD748ULL, 0x28B21CB10B8A0593ULL, 
            0xABD3D7320400F074ULL, 0x00C111B9ECD27CBBULL, 0x58535D015605B32BULL, 0xCD56AB89D78B72DEULL, 
            0x4D08AFB632CFB872ULL, 0x8DBDF38C32C95BD8ULL, 0x5AF780D66C76F4D9ULL, 0x91183C998607C370ULL
        },
        {
            0x4EAD0E8445A611CEULL, 0xAF44A2DF8259169EULL, 0x0381DF64FD240961ULL, 0xA68F255FF10D465DULL, 
            0x91CBF3043CAF6933ULL, 0x9F9278E99304C76EULL, 0x3EB03B2559F87345ULL, 0x5AA476782D6B6B71ULL, 
            0xD223C1CF83362940ULL, 0xC7840F526EF324B9ULL, 0xE084716C86EC3D91ULL, 0x1221D27B129C324AULL, 
            0x488880EB47E091F8ULL, 0x822D0206DB4EE227ULL, 0xDB9CD0650716B9D6ULL, 0x52117190F9DBEC64ULL, 
            0x41364042CA1AD047ULL, 0x7D5C67923F0110ACULL, 0x245A51A3FDCED3AFULL, 0xB675C20B0DA31DB5ULL, 
            0xC6C813B5C671C65AULL, 0x53F1B3D83784EE7BULL, 0x975167ED3872BB4BULL, 0x0DD2BF9F609845BCULL, 
            0x1F128452559E168BULL, 0xF08FF8B8B29D1E60ULL, 0x7022413AC4BA7116ULL, 0x7D35FD125FBD206BULL, 
            0xF0E4A39F525F849BULL, 0x2B72163FC92A6D91ULL, 0x12A960D49BCED547ULL, 0x37491CDF2316B03AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseFConstants = {
    0x5C74737259D79345ULL,
    0x807194FDC5C782AFULL,
    0xEF6DF8C834C32493ULL,
    0x5C74737259D79345ULL,
    0x807194FDC5C782AFULL,
    0xEF6DF8C834C32493ULL,
    0xCA652473A3241F04ULL,
    0x1543558E0BE08C98ULL,
    0x94,
    0x42,
    0x18,
    0x13,
    0x94,
    0xE5,
    0xF1,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseGSalts = {
    {
        {
            0xA61D4F113B09437FULL, 0xDCFC982515EDE9C3ULL, 0xB875AFC9C27CADDDULL, 0x25EEF18DBB81AE73ULL, 
            0x389E5EB20760E351ULL, 0xC285DF26C3CA32F5ULL, 0xD876DE2163FCF39CULL, 0x7B12F60975D7A8CAULL, 
            0x7C731A7BD5C61321ULL, 0x41AE11AE6E1C5D83ULL, 0xB245BB62431BEDA3ULL, 0xC7CCFFC8E0C467C3ULL, 
            0x320D5BD75C128A95ULL, 0xE2ABF8CF92B30500ULL, 0x034693D72E6EC70FULL, 0xD841FE0981AF7BC0ULL, 
            0x0E3D809C34C37F4FULL, 0x3ECC1EFB677494A7ULL, 0xEB0DFCBC598F2483ULL, 0xA44B35FAF0DB2D64ULL, 
            0x3C160887F18789E6ULL, 0x17E49255182A4465ULL, 0x61BA8CE94F81FBF3ULL, 0x1A1A2AF9314A43CAULL, 
            0x0B6861A506C03C3EULL, 0x976DD7704E5CC0DBULL, 0x21B8BD6B634B3F1AULL, 0x83FCC129878FA734ULL, 
            0xDA754F55D594B96EULL, 0x5FBA642552A667E7ULL, 0xD117C5A46645C5FEULL, 0x55F8F86FDD574420ULL
        },
        {
            0x0E58E2C846EBCC1BULL, 0xAB2B965C8C055958ULL, 0x88215DEE1781BC6CULL, 0x6B505128A0C0C3B1ULL, 
            0xC1156BDF049B2134ULL, 0xF93554A8BBC3B2E8ULL, 0x508B078BE3E0F226ULL, 0xD83BD3AA6F4ADF33ULL, 
            0xFD1863A83E140902ULL, 0x04B6AF4FA6FF5C9EULL, 0xE501DAAF03DFA500ULL, 0x75C8527F883ADDC6ULL, 
            0xA7E9DDED77980C9DULL, 0xFD1B2FC9BD7F50D5ULL, 0x3604E94B3F22E4F2ULL, 0x29886B1E51123035ULL, 
            0xD9932EA52E8F6BD3ULL, 0xD1E1DAE0C021B81EULL, 0x841436B67EC1F588ULL, 0xC4119DBE0194C4B9ULL, 
            0xAA7AE41715F2A1D4ULL, 0x6BF3094D1C32B374ULL, 0x55A864B8466A85CAULL, 0x2409F5B816D1E052ULL, 
            0xBC023236D0135FD2ULL, 0x7A3244DAE790BB85ULL, 0x3F0E2097E77B2CF5ULL, 0x50490196F590127AULL, 
            0xE929654CB47A43FAULL, 0x7C28CB9C807A5D1CULL, 0x9C247384FCFEB313ULL, 0xC4313444D45D617DULL
        },
        {
            0x0A4608122989CFCEULL, 0xA5450CF2D171C4C3ULL, 0xF1FD816C4B2F608DULL, 0x0856D76CC71B81E6ULL, 
            0x735D179394CC41BAULL, 0xD6285C11DE46D02AULL, 0xA5121EE21EF1C501ULL, 0xEDFA712B501857BEULL, 
            0x2C69AE6106E3722AULL, 0xA2648B89EFD5F821ULL, 0xDC20614ACD5A7B37ULL, 0xDA4478D2847E5263ULL, 
            0xAA2E6BAD8087C014ULL, 0x84A5AE17DE136DDEULL, 0xD88939DDB2FB7DF6ULL, 0xDA5BD01B4840DFB4ULL, 
            0x689B458A177B26FAULL, 0x195C027672DA2EAFULL, 0x95D14A62C41F0977ULL, 0xB22519ACB3A383FAULL, 
            0x299FF9614C566A34ULL, 0x0AF6E457621D93EBULL, 0x118528CA0B4DEBA9ULL, 0x031150961563F210ULL, 
            0xB2892AD96D142292ULL, 0x58997626D83201B7ULL, 0x81EC6C2C8F02EB8FULL, 0x53A3B256D196D657ULL, 
            0xDBBF1890211E73FCULL, 0x5ACFA0F7441DE7BDULL, 0xA07E9A476C388251ULL, 0x4562F38337CC64BAULL
        },
        {
            0x229F1CA998E7773CULL, 0x098BB495A02F1BABULL, 0x3BBFBE220BDA26DDULL, 0x1BFE29A0401C2F9CULL, 
            0x3F5C3805C7F08C2FULL, 0x4671550B02461E21ULL, 0x0F66FDE5A7382B16ULL, 0xFC60148519781328ULL, 
            0x5E65259B09AB1EC4ULL, 0xE23E7E97F2507D02ULL, 0xFBC269C4A0096BD4ULL, 0xEE9B97EBBE864ED4ULL, 
            0x816546E37D23D990ULL, 0x41413C649D2D97EEULL, 0x800089746A43D12FULL, 0x6DEAF9C4E8B7D19BULL, 
            0x6DA76C123CC80635ULL, 0xD92D2ED3D8FFC4D3ULL, 0x1864A9DF75E3A0CBULL, 0x5E98FD07142FB414ULL, 
            0x98CA30151310EC41ULL, 0xD82329ADBC168101ULL, 0x4759172BBC6D3D12ULL, 0xC1ECA38C019FDA8FULL, 
            0x3E8522D41CFBE079ULL, 0xCCCD757C349E3D23ULL, 0x99F44FFC50D1869EULL, 0x94EB4B28D25ACCCCULL, 
            0xFE68E5CB2220C1C6ULL, 0x9ADC5532F4219BF2ULL, 0xD2DA90C721DF6842ULL, 0x2A6E2D27A1ACD8E9ULL
        },
        {
            0xC8F02C354C3880CAULL, 0xE20DDE7064AF4185ULL, 0xB55BA80CBCA88F13ULL, 0x010A112F0B5829CEULL, 
            0x2ED81EE51AF8D0C6ULL, 0x018EB237048B3CD3ULL, 0xAF721221E56F93C5ULL, 0xB9A550BF85BEA78EULL, 
            0x447542769939DC21ULL, 0x0DAFFB2C3130DE42ULL, 0x09F0B4408C788C1CULL, 0xED66D9AF84BC705AULL, 
            0x15B6EEB643E3D2C7ULL, 0x729D4BB6C88F6E62ULL, 0x3C2EEA879CE80DE0ULL, 0xCCE9D7C6124A2526ULL, 
            0x9A01C981B423FE1BULL, 0x0F55B5F5AF68D5D6ULL, 0xE56DDB764E2D78A2ULL, 0x3F4A17FA50DCE675ULL, 
            0x156FFB7381A5305DULL, 0xDAFEAFECC3065F2DULL, 0xAF1FFD9546722032ULL, 0x7D7D1ABA27DC4F1CULL, 
            0xBF9DFE79F828B3D9ULL, 0x0EB687029787A52CULL, 0xFABE025732136312ULL, 0x5F9B1A89C9D8B93AULL, 
            0x751A20B4E9C29276ULL, 0xF84A535A2C21A20AULL, 0xD6004D531C42AF3BULL, 0xCE2102BDA558F2DFULL
        },
        {
            0x2C18BD34241593F0ULL, 0x20BF6177D2FC1853ULL, 0x70067B7BEE660503ULL, 0x9CB829E3D7073496ULL, 
            0x61B76E824860999DULL, 0x70B7D5E3F7229EBEULL, 0xF05B83A34E48C7A5ULL, 0x185A7762161EE7EAULL, 
            0x5875707D67894982ULL, 0x1EAC98BB471A3441ULL, 0xB3857507F3A48118ULL, 0x05801F3984A530A3ULL, 
            0x23F18C2E9E4C03E5ULL, 0x8C2FC6211F8BDBA1ULL, 0x738E69FBECDAED19ULL, 0xA9B1F6FA5947F19DULL, 
            0xF006B04A8A9B6831ULL, 0x79B85D733E884B10ULL, 0xE4D8C79B480EC597ULL, 0xACD8547AA0C7AF2AULL, 
            0xE102207AA628FB93ULL, 0x72990D6932829092ULL, 0xE42B6FD127BBFFF2ULL, 0x989EB3EC53F28AB7ULL, 
            0x21F809547BC59F19ULL, 0x432DDEA0608BF7CBULL, 0xC517C1E7FB97BA54ULL, 0xADDACBBF6352D70AULL, 
            0xBDD5F70F41151605ULL, 0x49E39644877ADE20ULL, 0x2A45367402281F41ULL, 0x8DFBE5E739881B84ULL
        }
    },
    {
        {
            0x72D2FDA97D0B5F7FULL, 0xD644FEDEEE90307AULL, 0x7CD8FCABA56F6C06ULL, 0xAD857BF22D0E2221ULL, 
            0xB66CF2FA79E96392ULL, 0x2188D3BC2AD5C18AULL, 0x1A9FB3FD06B8E296ULL, 0x60DF506574C69F98ULL, 
            0xEF23388F61C31818ULL, 0x4161F54B8626D09FULL, 0x8B07E01756F82EFEULL, 0x8B22722CAFF070D2ULL, 
            0x0FB510AE1D59AEB0ULL, 0xDDCC186C4242532FULL, 0x374FC5179B2CB605ULL, 0x4E6EEADC37B24FB4ULL, 
            0x2E94E020E711406DULL, 0xEDBBB1D21699BEABULL, 0x38A4E099F57C7E66ULL, 0x47E6BF7D01BDECE4ULL, 
            0xFF059D9778B19977ULL, 0x561591275260E712ULL, 0x1BD13A42C1C7B913ULL, 0x8A870B2032BC8F8FULL, 
            0x428E7A962F167426ULL, 0xBF8F1783231DE166ULL, 0x0687E5960D4FB969ULL, 0xB0810375248569E4ULL, 
            0xA3260FB98C2F1D69ULL, 0x58ED092BF6373B24ULL, 0xDEA713F8EA2C20C4ULL, 0x0580251B6484CDB7ULL
        },
        {
            0x79E687A522631EBBULL, 0x15BAF22E44F83B2DULL, 0x8A875FE9DD5432B3ULL, 0x2FADB18FDAE2C3BEULL, 
            0x38A7448122145E70ULL, 0xC4A4FCC53247E535ULL, 0x16223C8897190136ULL, 0x9A443734A3E4A957ULL, 
            0x0B982C53093268B4ULL, 0x4E6C149473C8F534ULL, 0x2B0C2FD751102D69ULL, 0x2E463EBA03312ED6ULL, 
            0x4A6E10EF5808A356ULL, 0xCB1F742FFEC43C45ULL, 0x9362AF7A8FDE5961ULL, 0x37611DE8CFC9AAD7ULL, 
            0xE58CB720CA2C467FULL, 0x33C913F7A917C7D1ULL, 0x67AC4871C4AB6E2DULL, 0x4AF1AEA58A037ECEULL, 
            0x623C01AC31CCA68CULL, 0xF10FD906F205D16CULL, 0x36F57BD051E9E846ULL, 0x3B941E1D3B3A8062ULL, 
            0x8CA388E89CF49A13ULL, 0x828CF2186E3B5839ULL, 0xBE4DEC5F17DEBBCDULL, 0xB63A796E8B19E5D7ULL, 
            0x6A7227857BFF305DULL, 0x576BFE153B065356ULL, 0xD51E5FA2F8034DFDULL, 0x0244164D920ADAD2ULL
        },
        {
            0xE9E41D9795AD4BEBULL, 0xEDC1E4C88445D4E9ULL, 0xCD176EDBAF60DA5DULL, 0xACEFF0F072C67D68ULL, 
            0xA0CCD53F7D4F4C4BULL, 0x45F6A606DE842D0AULL, 0xC588B77CAFA78C2EULL, 0xA94B20FED02DF5AEULL, 
            0x403B67C6788269D6ULL, 0x2CA86511394D6524ULL, 0x76543C515D0BCFECULL, 0x68E31E854641ED75ULL, 
            0x1187536C498CDF84ULL, 0xB0D0B0374740038AULL, 0x4384E7DB32A2F469ULL, 0x82EBFA3AD5B0B4D0ULL, 
            0xF6AF9A8F0A7576A2ULL, 0x173076208E0DCA50ULL, 0xF40294D0FBB454B3ULL, 0x093ED73DF7EC2540ULL, 
            0xBC11A93929FCCC18ULL, 0xD85319CA9369CE49ULL, 0xCB24647B016451D9ULL, 0x1A4088FF85A522E1ULL, 
            0x8C5EC941EC1B65ACULL, 0xAB3C30CA8C601E01ULL, 0x0BC29CCAAC435464ULL, 0xCEE20F94A8B2266EULL, 
            0x769B1067E9E2BEC1ULL, 0x312A1D1F8DF5893CULL, 0x4F49122C2812180AULL, 0x4A84E164F0A67CD8ULL
        },
        {
            0xFAE853B521081285ULL, 0x6F86159804C6B871ULL, 0x27A509BC05160AA4ULL, 0x409FDD86BB78A451ULL, 
            0xB01BF19D8978413AULL, 0x2AD940DCCC0579FDULL, 0x692E8F41A6E3CF42ULL, 0x645328AD63AFD5C4ULL, 
            0x732A0D5CD1968E16ULL, 0x3E7ED51600AF04EAULL, 0xAF93E9E5CAACBC35ULL, 0x4B3B9A532A06BA8EULL, 
            0xBF4B4B10FC60A89CULL, 0x505FD37AFE055432ULL, 0xFA6B01955A366B49ULL, 0xF3C3091B0251A251ULL, 
            0x8E2FEFE0778236CBULL, 0x55C81BC135B26BFDULL, 0x68418DB33CC73DC4ULL, 0xF7A3261D3A30CFBBULL, 
            0x167D1DBCE9B172A2ULL, 0x6F6ABFF4D4015004ULL, 0x540C41319077EE92ULL, 0x01E9DD7CD0968037ULL, 
            0x2A82E7504524C950ULL, 0xC8A642500C9CA525ULL, 0xEAD84394D3BF33BBULL, 0x3594BC27F39F732BULL, 
            0xBA8B214A8F662645ULL, 0x166961AEBB6CD927ULL, 0xEC2ADB7F0BC2FDDCULL, 0xD00F2190155CC231ULL
        },
        {
            0xB0902ED216222B9CULL, 0x75CC4D3242EF2913ULL, 0x8502ECDF17FAC39AULL, 0x1D9FDB741BA1A7F1ULL, 
            0x32E3F1A6B7123DB2ULL, 0xE8CA51BFF267FC29ULL, 0xBC8463FBCA6E0827ULL, 0x0B9802008F4B963AULL, 
            0x1C32974E8730152BULL, 0x0711425C90B9F326ULL, 0x640E8D3DDD941A2BULL, 0xD79E837129E2D84CULL, 
            0x1133097CDEFEC1C5ULL, 0xC0B0279AFD85E2ECULL, 0x10ADEE7B3CE3B928ULL, 0x917753E25298F0ABULL, 
            0x2DEE5859FA92FFBEULL, 0x2EACAEBFB585C167ULL, 0x80C65D2983A52D61ULL, 0xF7943630300C0812ULL, 
            0xE11C998DFD7B3012ULL, 0x47A315DC1634258AULL, 0x482C498E7721FBFDULL, 0x9EC155A06CE9654EULL, 
            0x0DC4B0A6FD47AA1AULL, 0xCCFFE99FD0BB61F4ULL, 0x2A625950A9EE16F7ULL, 0x490356B32F84D308ULL, 
            0x2960957645026BDAULL, 0xF387CEA7EC8DA3F6ULL, 0x24F64BFD7BDD7C77ULL, 0x5E3621991E1F74E7ULL
        },
        {
            0x4840C6F67D9771B7ULL, 0x31AFC20F579D1802ULL, 0xF9CD7A2875041FC4ULL, 0xDB42C071C9B70E53ULL, 
            0xDCD86D2A19BDD3EEULL, 0xA44C58195B140E75ULL, 0xA22093A01CD0B261ULL, 0x6E7ECC97C2139E95ULL, 
            0xCA627EFE9AB432A7ULL, 0x940A02A4ABDEDF26ULL, 0x03EF567DC248B798ULL, 0x332C56D557295CA6ULL, 
            0xB0C5A2FF32B4AAA6ULL, 0x4557AADBC2B349FEULL, 0x669DAE6182F991D9ULL, 0x5267874A4EABEC5AULL, 
            0xE7C6210F7EB9E81AULL, 0x4428A6A09FECF9DBULL, 0x16A69168F56CF32AULL, 0x3E992D2C538B79C8ULL, 
            0x3D60630FF8EC2B52ULL, 0x6402141F4CAB2004ULL, 0x6FD2B5629978ED99ULL, 0x48652D48DF0C3A08ULL, 
            0x8765CE2DF71F25DDULL, 0x08B023BEFE7F9A96ULL, 0xC1A4A4ECD518DEB5ULL, 0x1AD231DD56AE0BD1ULL, 
            0x2AD82BAEB7B2D645ULL, 0x85DAB65DB96D693EULL, 0x239C9AC8341D672CULL, 0xE0AF60062EBD40EBULL
        }
    },
    {
        {
            0x8D5DDE1FCF613046ULL, 0xAA24C6EBA418DCB6ULL, 0x630FA692F0DF855FULL, 0x671098785B3B336FULL, 
            0x00732D0444723E5DULL, 0x01D943B1F0AD6306ULL, 0x1F21F570F2C664A3ULL, 0xA90799A2279338DDULL, 
            0xC5766DC274C6831DULL, 0xABD8F0C22BEC8A3FULL, 0x636A1DC3E465E7CAULL, 0x05525470263A7E2EULL, 
            0xBB0AD1DDA9E0D2E2ULL, 0x2187A8AE8E7F29CDULL, 0xFD2FA6CF0BE1678CULL, 0x5473973ED11C9B74ULL, 
            0x886E7F80671EF214ULL, 0xFD86A413424E1322ULL, 0xFBDFD94B50B6FE39ULL, 0xD36491A539F9E55CULL, 
            0xBEE3B184BAD9965DULL, 0x1CAA15410001AD01ULL, 0x8648B5B010993404ULL, 0x69CAB614752AEDCDULL, 
            0xB6A021402CD6D54DULL, 0xF1DB133B3F2CF473ULL, 0xFBF426EB957B8616ULL, 0xAD7D71CA792898A1ULL, 
            0x08EB92C30FA619DDULL, 0x60F02F5215F7A484ULL, 0x25BBB5B33CDB22ADULL, 0xD48CFE830774F695ULL
        },
        {
            0x6963DC11CD7B295FULL, 0xD648560371456854ULL, 0x81C7865918140654ULL, 0x1E6EE3841CCA163AULL, 
            0x2CB66503BD171761ULL, 0x0302AC762E4B05ABULL, 0xA1C276F84906C3D8ULL, 0x3D1174CB6DF49A6AULL, 
            0x8CA822557BF03139ULL, 0xC0B63CEDF034942AULL, 0x8B3BB02B97CBA77FULL, 0x18BEE3238C62CE65ULL, 
            0xE286645800505228ULL, 0x60CBBD68961DF389ULL, 0x0E189E81495CE89BULL, 0x7D0B5EB17C467A46ULL, 
            0x89A5A7F35407377BULL, 0xCEAAAB4652ACB820ULL, 0xF151F88CC3794381ULL, 0xDBB98A1221F080D2ULL, 
            0x2174EDED4B09A4F3ULL, 0x90C4749FCC39DC1DULL, 0xC8524C8259CC6A83ULL, 0x3993CC97391AC0D2ULL, 
            0x99C7B293A33A15C7ULL, 0x2ABBFEC40EB591F0ULL, 0xFD77E56887E108F0ULL, 0x84E8CFE0F5440F2AULL, 
            0x6A1C62E80ECBAB61ULL, 0xD1B8CCD94007333EULL, 0xEC5BF9E54AD41A65ULL, 0x3712CAA8B9569679ULL
        },
        {
            0xB96142EC2B391005ULL, 0xDE722B1800CBD395ULL, 0xAB164D892444A920ULL, 0xE541D7108C32091EULL, 
            0x2220771B297FF449ULL, 0x1B6FDDD17168BF25ULL, 0xB97E3D8D2CAA2B9DULL, 0x4C217F9B5C94C365ULL, 
            0xD40BAE3044E1C60BULL, 0xBA3ACE4B9F3F54C5ULL, 0x0DEADADC6408BC97ULL, 0x29EA9EA80D50989BULL, 
            0x582905B0C95B1E94ULL, 0xE98F521A05F362E7ULL, 0x7592898718C88997ULL, 0x5CBF8799AB8DDB7AULL, 
            0xD6CAA0051BBB6B6EULL, 0xFC9BE4BDAD6B04FDULL, 0x93ECFF6294DC8A00ULL, 0x73B2E76CBDCA10F6ULL, 
            0xEC5433AFE7FBC8E6ULL, 0xBBD23E1A39579C2CULL, 0x73094B6F691CDF31ULL, 0x87D0812AD58EE9BAULL, 
            0x0D9D23F4AD120747ULL, 0x4ABFE1224BF92200ULL, 0x2997354FA500616BULL, 0xCBEE4CBF8C38D1F2ULL, 
            0x2CA61F144E5EA374ULL, 0x55804437BAF7191BULL, 0x2496333D61C9BD6DULL, 0xC83CFB3D0C37C37DULL
        },
        {
            0xF9ACA1661197DDA2ULL, 0x87982C9CDD2D7A50ULL, 0x4D2966C9DABEC8D0ULL, 0x067752A27599FE71ULL, 
            0xA28B76E4DA5EF27DULL, 0x10E2F5B3A6422789ULL, 0xDC40AC6AADDD49E5ULL, 0xCEE9625A19FC6387ULL, 
            0x85C4B78182D7D757ULL, 0x06BC4B07B629F20EULL, 0x18D96A2663F5E70EULL, 0xEFBD9574BA998A66ULL, 
            0xF8C2F1A1DEF67C7BULL, 0x607A549728350CE5ULL, 0xDE0AEFAFBF598195ULL, 0x2152401631E1A531ULL, 
            0xEC4CB623E380ED81ULL, 0xA09D5DD17F3D2968ULL, 0xC266446BCF534852ULL, 0xAB7BFB9230CCC7C5ULL, 
            0xFB64BF9635CAB56AULL, 0xA1CE879F19D14B5BULL, 0xB7C9C0880B922657ULL, 0x6009689CEFB9066CULL, 
            0xE90CED65702D31F9ULL, 0x2DDDDB84CD1E73FAULL, 0x2E88E02B34BBB77DULL, 0x7B6DEA98CADF7B96ULL, 
            0xC7737D6B450B3C35ULL, 0x2DB2B6E33061900EULL, 0xB4509E92A950AD71ULL, 0xF27A574969516ECEULL
        },
        {
            0x667F8F5E69F66253ULL, 0xAE3E7F8B73123394ULL, 0xD5FD7D4B0E46DFC9ULL, 0xEF16C9697D9381B8ULL, 
            0x1976FE8D37D7476EULL, 0x115A3A2061213F15ULL, 0x5A4F870E76732E62ULL, 0x20D0D5E1B43B1A44ULL, 
            0x92FFA13016B3BC75ULL, 0x6FB3512240E68C01ULL, 0x8DAD693CCC5FB424ULL, 0x29DB509742CBC370ULL, 
            0x001141BB13DF538BULL, 0x3C0A41A54F22A56CULL, 0xDD613682E814C772ULL, 0x1D443BE8B4186A5DULL, 
            0x50F9A36084021C96ULL, 0x130B0CDAD0511EEBULL, 0x50F9A807071CF23AULL, 0x1A2A8161FE01D23EULL, 
            0xE8DAAF01B1027BBFULL, 0xB53E76B2E7D26990ULL, 0x5E696A6E5D1625B6ULL, 0xE30234E90130D3B4ULL, 
            0x452C075C2FD71781ULL, 0xDDE134204B64BFD8ULL, 0xEF21609B26B57521ULL, 0x50D6F7A2C6494183ULL, 
            0xB0FE9562BCAF381AULL, 0x925BD1BF281442FCULL, 0x5607119B541F15F9ULL, 0x685253534D4D7797ULL
        },
        {
            0x19F09FEAC4709DD4ULL, 0xD6C948C071A99058ULL, 0x59AC53B976AE839EULL, 0x0BFC4D03F9CEE72DULL, 
            0x3ABA5CCC07002C97ULL, 0x14BFCF119289E85CULL, 0xBEABABFE512D4826ULL, 0xCBD2F4F49D78E0CAULL, 
            0x87E1321345BEB7A3ULL, 0x52092EFFDA8F996EULL, 0x67A5DC2A48926C67ULL, 0x2A4633D46A5A6E3EULL, 
            0x0726468F5E7DD5C2ULL, 0x95CF084930AE62CFULL, 0xEFACDA24EE969EF5ULL, 0x63DA72460CECCF0CULL, 
            0xFAA9D4615BC3D280ULL, 0x78D958F9DC58F1F6ULL, 0xF232E1EDED7F7235ULL, 0x2B879EE02890E5BDULL, 
            0x318000E3E732F832ULL, 0x1E044702077EC371ULL, 0xFF37EFAF34CF0A37ULL, 0x0B4D51E0CBFAC4BEULL, 
            0x04F122251E7F407FULL, 0x8F8997DE4A1740C0ULL, 0x8918DBE78CDC41A7ULL, 0xF79370915938EE7AULL, 
            0xEF7F763EABF1609AULL, 0xCA7AF57ED421173EULL, 0x309CB4920DD5DEDCULL, 0x6DBBF986A53D04F1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseGConstants = {
    0x423E0938EE638FACULL,
    0x48F33EEFEE11D199ULL,
    0x8270AEE4A81AF6B5ULL,
    0x423E0938EE638FACULL,
    0x48F33EEFEE11D199ULL,
    0x8270AEE4A81AF6B5ULL,
    0x9BAE308EE998EFBCULL,
    0x5AC066D8BD7541DEULL,
    0x4A,
    0x46,
    0xC2,
    0x43,
    0x76,
    0x70,
    0x8F,
    0xD5
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseHSalts = {
    {
        {
            0xCAAFAA248072C468ULL, 0xFB9C790134090F45ULL, 0xE8F4791B3818E6C6ULL, 0x65A2A7870F55B1F5ULL, 
            0x1FDFAEE019453797ULL, 0xA6559348456F8FC1ULL, 0x52CAFDD5DDC1681BULL, 0x1C75B5DA1FCB6B97ULL, 
            0x23C20AD55B9DE4D5ULL, 0xDC8B0781B2FDAEB5ULL, 0x29BB10A8B6167096ULL, 0x893E6B534E03074DULL, 
            0x887E509418C7A5B7ULL, 0x42C22E8246CEFAC0ULL, 0x9D7C15FB6100D40CULL, 0xB8EEDBC5948E68F4ULL, 
            0xA64DC915EE7B05BFULL, 0xB8D6D11BCFEAA9B0ULL, 0x198BE0AF0E2698CBULL, 0xE2D5DEE1FC6DD073ULL, 
            0xF8F7714B74D11132ULL, 0x6D530ACC585A708DULL, 0x2785363D9E56E700ULL, 0x5BC6CFC68682A6D7ULL, 
            0xA694BDE51A85FD5FULL, 0x29F7983FBAF2A39CULL, 0x1A62C88F7E9B81B1ULL, 0xE77F5F6B34A8F786ULL, 
            0x63182BA2D30D5626ULL, 0x198F7570943DEB3BULL, 0x157446D7242FCB5DULL, 0x73E66128F9103C98ULL
        },
        {
            0xE404DB13DE1771C2ULL, 0xB5CA863482A0FA1EULL, 0xB90AABA1265399DEULL, 0x51F2CF1D82AEBB5CULL, 
            0x442822DB0F27CC2AULL, 0x9738523E8649768AULL, 0xB7FE7AA01E18BD53ULL, 0xE5D4210F335B4FF4ULL, 
            0xD20D5C34737640CEULL, 0xDD01D0221A949548ULL, 0xC9A98A19E9D71D72ULL, 0x5D2ADA2D2CA6FA6CULL, 
            0x1B5BD28A39597E3AULL, 0xD1356C9B9EA09CC7ULL, 0x5514F3FDABF97E87ULL, 0x4723E7BBBA084DD4ULL, 
            0xAE72CA970FF6F921ULL, 0x656AB128BBCA5536ULL, 0x2FF3AE9FCC67DBA5ULL, 0xE04299B34EFD3FD2ULL, 
            0xBA509D9A45F2E81EULL, 0xC95347FBADF45110ULL, 0xF0A34555AB1E1CD2ULL, 0xBB2242D89F125DE7ULL, 
            0x830234B0071C5171ULL, 0x9F651109DEA16CD6ULL, 0xEF049590EA6E357CULL, 0x89331778E19AA1D1ULL, 
            0xC8F483EC93878A9AULL, 0x88862A67FD78271FULL, 0x6BC4ACDA42510265ULL, 0xBBE39B48DD60CABDULL
        },
        {
            0x71347319223F6BB3ULL, 0xC23D3FFE2416FC08ULL, 0x8086C4509B7DBEFAULL, 0x823DD5BDF456F4A8ULL, 
            0x587E1AA6AAD28E83ULL, 0x1781CEDFA2676705ULL, 0x4B566FDDB64C79B9ULL, 0x84E5E3E0A9B3EDA5ULL, 
            0x7D196CDC2DE009EDULL, 0xC5BE3BAB4AEF1FE7ULL, 0xC784750A841DF477ULL, 0x1E1B52151F6E3BD4ULL, 
            0x5B8D36EED401B776ULL, 0xB6F2ED609CD7CA1FULL, 0x6B2AB26AC901326FULL, 0x61E4802E4A1B4428ULL, 
            0x6F237732D6182B0FULL, 0x86AC112E187E6C98ULL, 0x8C142900389F74ECULL, 0x5B712E42BAF59AACULL, 
            0x6040AD54C26A2DAEULL, 0x964A5E467BF312F7ULL, 0xDB6B025709B7EDA0ULL, 0x973157A3D7048DBEULL, 
            0xA2118969BE1DA494ULL, 0x8A5970F027E6F52EULL, 0x35D94AEC32948DE4ULL, 0x9F13A6D9FAF17C73ULL, 
            0xDCDCD7660EFEC68BULL, 0x31E865F0512E5BB8ULL, 0x1E7BFED277E2648AULL, 0x1EFACAF569626038ULL
        },
        {
            0xA5A6D28E806D80BCULL, 0xD0F5C4E59D165C93ULL, 0xE65EBBE57A083587ULL, 0x817A715BCD907D19ULL, 
            0x322E4687EAE81D4BULL, 0xEF4BFA873349CD19ULL, 0xF87987E4BC953A9EULL, 0x2F03C75CC2935320ULL, 
            0x3B18E099A7F30EDBULL, 0xDF58B5563FACBCA6ULL, 0xBE7ADDBD67A92BBCULL, 0x3AA0FE6B0F45C771ULL, 
            0xEF80FA298D304085ULL, 0xD7446F0DDDFF5C5DULL, 0xF40B400822E5B9B3ULL, 0x2C2207DC09035704ULL, 
            0xC21310266E793697ULL, 0xD5BFD9BD6B63DD7FULL, 0x1D3C3F91A8164C22ULL, 0xE29E4D3BA65947ECULL, 
            0x1AB41122CB6110EDULL, 0x505C2A13BE583E5CULL, 0xFD9A7290D5165CE1ULL, 0x54B2BF385068A195ULL, 
            0xE19E99BADCEC8834ULL, 0x59B74E4408FEC98EULL, 0x451CD20C0C999FBEULL, 0x183E96FE4400154AULL, 
            0x9A5C92418A63F9ACULL, 0x1C6C653625038E88ULL, 0x7729474D2B5ACF16ULL, 0xD3907D8007A07A29ULL
        },
        {
            0xC65E40B7B0E344C0ULL, 0x95735D87C94A6081ULL, 0x6D208209365775B4ULL, 0x86C3FF559EBEACA4ULL, 
            0x23845B91239A4E39ULL, 0x26864AB844D2C47BULL, 0x43D67C8E392E9E74ULL, 0xF7EB6EFE640CFD5BULL, 
            0x1196FCA4BAB19FCCULL, 0x8347E7EAFD10E0DAULL, 0x882523D3E3F7CF73ULL, 0xA916ACE6D3AB3E47ULL, 
            0x603C828639934FAFULL, 0xCED4F5CA9EF559DBULL, 0x3BFC0738330A7E92ULL, 0x28814AC19A518C3CULL, 
            0x6F6E9903193BF74DULL, 0xB839D3DDB581FB07ULL, 0xB8412AE423836C13ULL, 0x464BC075235A78DBULL, 
            0x156362FDF908C433ULL, 0xF4991481465DA64DULL, 0x12D6E12DD93381DAULL, 0x1FF47973E0A9B665ULL, 
            0x560FDB17C6D21986ULL, 0x6909279C77B9FA24ULL, 0xB24366FBEB7C917AULL, 0x4E31AE71CEC627E5ULL, 
            0x34C44D9471211FDDULL, 0x5BD12BBF820F8337ULL, 0xB1B139BD2D14F837ULL, 0xF4A624E888DEE6ACULL
        },
        {
            0xD39F017FFF44416CULL, 0xF01E9685CE018319ULL, 0xE08D8B96075FBD6AULL, 0x7E4E6F723D6C8B5AULL, 
            0xB00C10147C786283ULL, 0x859FAD59F3854E21ULL, 0xAD22BDAC527BCFD7ULL, 0xC5A0EEDC9D2A764DULL, 
            0x99A2213C1CEE1F91ULL, 0x540E418ED55AA6F5ULL, 0x61F400298E5BA691ULL, 0xB2D04353D9CB12A2ULL, 
            0x0842A4E9778FD7E2ULL, 0xC5788E504447A9B5ULL, 0x998790EC37D4BBDBULL, 0x3EE8F06001A3AC49ULL, 
            0x81BB519461A221D3ULL, 0x53CA6292E4312645ULL, 0x88FCEBB69E6298C4ULL, 0xF5427E0C2BA975FDULL, 
            0xDFB14979C7D1B7FDULL, 0x77635CDF2D7C05D3ULL, 0x5CCD7D0DE31482DDULL, 0x8DAE2F85E743774CULL, 
            0x40B06E033A5092DCULL, 0xD36FCC4053D8DB73ULL, 0x62BF915A52DB418AULL, 0xF7C7A07409C0FC4FULL, 
            0x6CC57367C7AA6D7DULL, 0x781D1ECD0C0389CDULL, 0x7A486F9D1FE04274ULL, 0x9C24C58131181CCEULL
        }
    },
    {
        {
            0xB89BC5B68D867489ULL, 0x94AFBA250AD0DF59ULL, 0x2D89DB3943A518FFULL, 0x7C4B4A6F320BC724ULL, 
            0x3C3B59E1402FBA90ULL, 0x8C578FB91596315CULL, 0xF37AB79086BCED84ULL, 0x018F3950443CB49AULL, 
            0x2FB11CC80AC10524ULL, 0x67F252BA541F21DFULL, 0x63C6C5C0A471CB48ULL, 0x4BE246D402716835ULL, 
            0x6D5B27C2529DF76EULL, 0x8FC24F1DE22324DAULL, 0x3ACA2802A4341798ULL, 0x265362B2BBAD48AEULL, 
            0x50D740A63EF5DCDEULL, 0x7430417244C276A9ULL, 0xCDCE027A65B80AD0ULL, 0xC90F5D247859726AULL, 
            0x9144A181795FF320ULL, 0xE522824BE8FA5C3DULL, 0xFDC3AB2709403FD0ULL, 0x6CB65A14AFA60DF5ULL, 
            0x9EE59EC4B3B8507BULL, 0x783023DC1ED93B96ULL, 0x824E6D7841E307DAULL, 0x2F4F77479FA98CD0ULL, 
            0x0B12B802FFE7C712ULL, 0xFA8AA6DF7A304EC7ULL, 0x88E77E42E416D2F6ULL, 0x8B8A65C969CCFEBEULL
        },
        {
            0x92BC6B989A7B490CULL, 0xDA335AA7D5490030ULL, 0xB82F0613225DAC6DULL, 0xBF7130C60275DE7CULL, 
            0xE3BFD278BDECB10EULL, 0x89CB378F533D488CULL, 0xEA9EF7AA305443EAULL, 0x5E2604968879538AULL, 
            0xF6D41060D793561AULL, 0xE22005271406BAAEULL, 0x1CE0B5CC99605D29ULL, 0x1440584C493AC9B7ULL, 
            0xCE5D9A1C7B0A3870ULL, 0xBD0E09D6D500ED73ULL, 0xBFF1F62CFD0513F5ULL, 0x33CB050C83E7537FULL, 
            0x28100A2E2A5912BAULL, 0xDF82D4ABA282D4A2ULL, 0xC008F020C36CA371ULL, 0x3655BDB05080EE5EULL, 
            0x4785514FA76B75C2ULL, 0xB04E3146D94413EFULL, 0x7AF59779B94A2DC0ULL, 0xB1385E7EAAEA56D8ULL, 
            0xCDF823B0E6B02C17ULL, 0x1D0BECD4F80C4C57ULL, 0x135B9648AE0FA8D8ULL, 0x37C35029707114B9ULL, 
            0x209D55F51637734AULL, 0x39EA01E01BFEED6DULL, 0x7357D8B0302D04DAULL, 0x74392FBC613CAA81ULL
        },
        {
            0xB41D192C5198D2A5ULL, 0x2FC64880D9F4D557ULL, 0xF296C508DD5D658CULL, 0x838E973E2C6158B5ULL, 
            0x2E157AA47CA11A6CULL, 0x9104C881ED865D7FULL, 0x85855D6CADE68156ULL, 0xB5D5EAA90AF7036CULL, 
            0xE7150591EBCCEC5BULL, 0xA92D9B13C390BF9EULL, 0x8361FE7507F78288ULL, 0x2233C16A07298D32ULL, 
            0x305C7BA3607C3B54ULL, 0x641562AE02AD58E3ULL, 0x8D456CE6B78D48BBULL, 0x7ABB5E72F8CC9182ULL, 
            0x25DF4EF903194B6AULL, 0x65409452FE3952D2ULL, 0xE0962A20D8195643ULL, 0xFBA2C096D2E0C96FULL, 
            0x912ED136FF93F63FULL, 0xE4F4B8B3DB50C0B8ULL, 0x43A162BBD54FE85CULL, 0xE783C7253A7814E5ULL, 
            0x07A9A7390FBC2993ULL, 0xCC62E83065CE5F6CULL, 0xCF4B007AFBE2B98BULL, 0xB4334D26BD7D0E13ULL, 
            0x8A5E4910798BDF9BULL, 0x1705CAC2003077FCULL, 0x1274AB579ABE46F5ULL, 0x586BEB369C84D528ULL
        },
        {
            0x59CBC22DAEDCDD52ULL, 0x9790D47C87BD8AFEULL, 0x953494DABD5A9D34ULL, 0x20B6EC626105D492ULL, 
            0xDAD79880AAFAD307ULL, 0x5CEDD9301B68453CULL, 0xF3D00E6FDA08EBE9ULL, 0x361A407E9A51E592ULL, 
            0xC91751D70C7BE59FULL, 0x1FA02984C3E97CFBULL, 0xDB2054FEBE899082ULL, 0xBF5A7D6BC5C093EDULL, 
            0x2FCBB6169A93C645ULL, 0x31B1912E496B04D7ULL, 0xE7C7507170A52A71ULL, 0x3EDA6B540258110FULL, 
            0x003A2C231637E72EULL, 0x749913EDDC89B46EULL, 0x46FC8B87C7D43A4BULL, 0xF4E18FBC2F1F7A83ULL, 
            0xAD9F3C11749B856CULL, 0xE4841DC68ED80CA0ULL, 0xD20BD004AD40171FULL, 0xABB63D6A0AE77385ULL, 
            0x7C3E081D2E3C9241ULL, 0xCFCC649D90F4017FULL, 0x4B46386E3EEADB3DULL, 0x84E2C7B2266C0032ULL, 
            0x45123BB73806FEB7ULL, 0x782FEB92D82FF174ULL, 0x22C5671D52ED39F7ULL, 0x83A71D092E7FDB67ULL
        },
        {
            0x2D9AD18186A5F0BCULL, 0x29C9DB872F1249ABULL, 0x23AB8C2F39449D1CULL, 0x8D9B6FCB1D69CA6FULL, 
            0xE76D51B1864E0F37ULL, 0xD7DBE324915BA6A2ULL, 0x56601E9D068D4EDBULL, 0xC89AE1B25578988FULL, 
            0x81777D9A997D41A6ULL, 0xB33C088E8ADB106AULL, 0x908EE68E6F2C79C7ULL, 0x81EC15043BF06C3FULL, 
            0x25066E12EC8CA5DCULL, 0x8DFEC2E39639881BULL, 0x278BF37A511F9A2BULL, 0xDF55055DEAAE2B83ULL, 
            0x9CBB1E25CD7B139EULL, 0x467B653227848952ULL, 0x88271E173EAFD8F3ULL, 0xB0A4D1A244110CF7ULL, 
            0x7656D95776111214ULL, 0x8FF9575112FDFEF8ULL, 0x2E87D18D79A38CD4ULL, 0x3A35DD4B40380ED4ULL, 
            0xA58D79F7D16068FFULL, 0xE847079525A99886ULL, 0xFBFA142807C16D5BULL, 0xA5E7326E97544399ULL, 
            0x79EBC3DCDE5C1D80ULL, 0x5F30675A84B247EFULL, 0x40268E0324B0FA65ULL, 0xF8C9E2370934B44EULL
        },
        {
            0x182D447C218C2DCFULL, 0xC1519AB88AC66BDFULL, 0x487D400EDC3CC9A5ULL, 0xC93A6CEFEC7E030BULL, 
            0xBF0099879C3E3C78ULL, 0x5909B9B4D86E2D75ULL, 0x207D867618651500ULL, 0x98985757C1FC3DFEULL, 
            0xAD3A23C5CA091EC4ULL, 0xD5DBE57F454C38BCULL, 0xF2E7CBFF1811A377ULL, 0x429F4D5EC3B60983ULL, 
            0x980BB3107112C1BAULL, 0x78F0ADEA3CE52700ULL, 0x290B04F452B4E1AFULL, 0x177871AEAEB8B42EULL, 
            0x7FA7D9B1A6A8A960ULL, 0xA1F4EDF44C27C916ULL, 0xA48E6FBC0C07F353ULL, 0xEBFF637D91FEEC52ULL, 
            0x3FFAD2683278178BULL, 0x971CFCA6160481CDULL, 0xE3840049781C7CDEULL, 0x3549669FC901D300ULL, 
            0xC3BE983C369F55E6ULL, 0xF37A63D459991BEBULL, 0x541A217A707CDD62ULL, 0x10BF7DBE21D3D34DULL, 
            0x13B2B9DFA9A79B4DULL, 0x7366613783C03972ULL, 0x14F6DE7C2E9F9402ULL, 0x628055A75B7013BFULL
        }
    },
    {
        {
            0x69E786B11A817962ULL, 0x1E033AF9F61C14F8ULL, 0xAD7CD6356DCD014FULL, 0x5ED90FD2B74E3FDCULL, 
            0xA80E3527B0A3DDCFULL, 0x54E379FE072AD554ULL, 0xCC4BCF0C2D2B1F34ULL, 0xEEB934495595F4AAULL, 
            0x14649761D536E330ULL, 0x98EC949AA728391BULL, 0xAEAC53566615C3B2ULL, 0x56486ECD9911C6A9ULL, 
            0x05BF1479FDE0C267ULL, 0x7728D5F698760B88ULL, 0x1B1B4754E1F95FA8ULL, 0x9276A42D4FECE873ULL, 
            0x97C0F41F15BE1A04ULL, 0xE89438D90F07FA0CULL, 0x3F4715608898C247ULL, 0x3F423F79FB9AB649ULL, 
            0x6A993C51F03D88ACULL, 0xD4E7098FCF8ACD2CULL, 0xCA0A3D15C71316C1ULL, 0x236F8D4253A74524ULL, 
            0x2949AA8739C09C6BULL, 0x70FF90083BB853C6ULL, 0xC440C9D200F297FEULL, 0xE542E1ECA2CAE6BEULL, 
            0x9B439DD8915A74E1ULL, 0x90F8776DC0F2AB88ULL, 0xB3CD0575CEC63C05ULL, 0x17EEBE1A9614CBDEULL
        },
        {
            0x5DDC9ED5E5F3AD93ULL, 0x7DC82D0A5A8C1749ULL, 0x29A24B5A91924593ULL, 0x61E0DB07437D210CULL, 
            0x930B24CCB0D0E89DULL, 0x0A86FBCB5B4213B7ULL, 0x5DFA75A68895CECCULL, 0x748CEA34C067B6E9ULL, 
            0x4115D4B619FE8D8AULL, 0xAF243CE71DC8FE3DULL, 0xBD679B1AC051AF15ULL, 0x702719B76C6AF6B9ULL, 
            0xCD500A9A3FAEC5B4ULL, 0x3020F89440D526D5ULL, 0x93EA5E1F5099A9A1ULL, 0x6642C0FB654BA35DULL, 
            0x89E487B908581668ULL, 0x5BE86AC3EF66CF01ULL, 0x1FF964792B4E96A5ULL, 0x90FC35A790C8B240ULL, 
            0x323B5002FAB09BC2ULL, 0x94A7FF4E22EF04F4ULL, 0x31BB668FC0A3E31DULL, 0x3A43A92C8C8C1189ULL, 
            0xFFA6F5CC9BF0C3D2ULL, 0x20EA90B1BFE99089ULL, 0x231A1F9B03D4D480ULL, 0x0C6DBD363E328BEEULL, 
            0xBE6474412B593FADULL, 0xD31D27DB18225BB0ULL, 0x77D954D52CB129A2ULL, 0x45EC9F19C7E1F8F2ULL
        },
        {
            0x5CD1A868283870CEULL, 0x593E4819689370F2ULL, 0xF6941A9A2A5CB53CULL, 0x0C58450D7D356C3BULL, 
            0x8C2BDC23B9A4B6F0ULL, 0xF64D154C4EA98213ULL, 0x171E953D58959017ULL, 0xFD79F1757350ACC3ULL, 
            0x88C345AF277CDDE3ULL, 0x6B6A94B8A3C106A0ULL, 0xE8BB19E2DF630983ULL, 0x2B3EF3A14E0E9652ULL, 
            0x2354BD4761FB3327ULL, 0x80D84E9BDFB534D9ULL, 0x5793E2C5C5391698ULL, 0x4C0D8C681A7A1B34ULL, 
            0x485F9AEF733237F9ULL, 0x516FA2FDF0F0B551ULL, 0x2F91FA592613E397ULL, 0x18395EB35D92946BULL, 
            0x63F080A3CDBCF62DULL, 0xD80E567C38810181ULL, 0xAD08DA5766670332ULL, 0x63513449C24CCA7CULL, 
            0x96128E136DB28B35ULL, 0xD32E1D2C1A50E779ULL, 0x4BCF29B673462A3CULL, 0xA69DEDE1DA300C0FULL, 
            0xDC83CA69607573E1ULL, 0xF40C799A869622E6ULL, 0x2CAFD0C41917F50EULL, 0x57F765C2EE5A0216ULL
        },
        {
            0xCF7AC906DA180B78ULL, 0xA460F3415A9F73D2ULL, 0xA6EF350E53DE3E80ULL, 0x44E1400A585E4B9BULL, 
            0xE956C2E8B824002FULL, 0xEFE6199B9E14E533ULL, 0xD7C8100944C52888ULL, 0x0AFAFDFF7608F644ULL, 
            0xE81D1BBBFBD9B768ULL, 0x967FD546CC251F96ULL, 0x99DA0AFA81BF7D79ULL, 0x2FC58EEAF237A08CULL, 
            0x530C9B55E1C7A1BAULL, 0x555B951EE373DE06ULL, 0x683E1952052DA3CEULL, 0x2634FDAC15E25EE0ULL, 
            0x1424BE349B84BA08ULL, 0x9CE67CCEB4487138ULL, 0xD1C040B4EF7408A6ULL, 0x095BD0002D739B34ULL, 
            0x25795F905ADF4085ULL, 0x2B6842B382AF5B9DULL, 0xE2D9F79506A48E30ULL, 0xDF6657F997655157ULL, 
            0xF55C153E64568FEEULL, 0xD1CBE140BE984823ULL, 0x1A64F6C9F876B0C8ULL, 0xA3C74873D327CD61ULL, 
            0xCB206B8DC8536DE4ULL, 0x2EE1FFB4745E22C6ULL, 0xE138955B12A2B554ULL, 0x2FBC5CA0DDFE56F2ULL
        },
        {
            0x3CCB9EEC336265CDULL, 0xE7545A9EFA18EC7BULL, 0x45061CA5D7E74669ULL, 0x2BDF1D46FA00D6E0ULL, 
            0x679F2225575367BAULL, 0xF04B45D006D4B327ULL, 0xEF83011D6F5B86CFULL, 0x7AB9B3371BB84ABBULL, 
            0xD371D61331F4C982ULL, 0x254D2A3F5F2E64A8ULL, 0x79C0300BDA3650DFULL, 0xE7F451A3635EC62EULL, 
            0xABFA6261F176A7C5ULL, 0xA18022B9DF4DAB5AULL, 0x5EE5553D3CAA69B7ULL, 0xF5C5982CE090C0FBULL, 
            0x8E5C51DF0797E2BDULL, 0x5A51CBCEFC8602D6ULL, 0x1CA0D85DB95A664EULL, 0x5AA5331D7E10A16FULL, 
            0x06BF2908706811AAULL, 0xE738F5C0AC55FCAEULL, 0xEF76B5F48D06BD25ULL, 0xD993BB57229222D3ULL, 
            0x9771F823FAB8AF26ULL, 0x34BE0BE9A71FF621ULL, 0x81ABA4F19E5EC1A1ULL, 0x9FA76107B4E21713ULL, 
            0x0BF6CAA7542EB297ULL, 0xF512298B24A65167ULL, 0xB50C0763EE5908EEULL, 0x57A02C6A44217113ULL
        },
        {
            0x8D5437F7082DE970ULL, 0xFCA79E4930C2807EULL, 0x8360DC8D9F60FA32ULL, 0x7BE42D1BF9A3960EULL, 
            0x1891D81607058270ULL, 0xE362CF492884A3FAULL, 0x0977FFB69627516CULL, 0x29E989759B1EE0ACULL, 
            0xA19B3BD83D791965ULL, 0x883AB8354E441F4CULL, 0xF74D54F91258B7D2ULL, 0x487EAA81D9515FB6ULL, 
            0x9D6447A0F56AF5BAULL, 0xEBCFBB6FDE14BCC7ULL, 0x52DD0DA2B21F3E2AULL, 0x584297F25AA4D28EULL, 
            0xCE902025420AB201ULL, 0xF3E90AECFAE0300AULL, 0x158EBCDA0BBDCA70ULL, 0x09CDB46E2F89A7D4ULL, 
            0xE37F8F5E40DF5641ULL, 0xC224087F22B40E10ULL, 0xD6D14F7E6451E3ADULL, 0xA369C54508DCFBBDULL, 
            0xA9618F3C378538ECULL, 0x7913C939BAF7C763ULL, 0xE62F151B110FB449ULL, 0xCE60FA3982A7BFC6ULL, 
            0xB51F7BA79F608CDBULL, 0x37A92BC9C4211BAAULL, 0x7CA0FAEF514F2AA9ULL, 0x843153F5928AD926ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseHConstants = {
    0xFFC402443D605FF1ULL,
    0x4A95F4BB06DF8E8FULL,
    0x506C51D78FE8E71FULL,
    0xFFC402443D605FF1ULL,
    0x4A95F4BB06DF8E8FULL,
    0x506C51D78FE8E71FULL,
    0xE00CC4724283A328ULL,
    0xE0ABEAD953BE0DA2ULL,
    0x4D,
    0x4E,
    0x95,
    0xE9,
    0xB1,
    0x38,
    0x95,
    0x29
};

