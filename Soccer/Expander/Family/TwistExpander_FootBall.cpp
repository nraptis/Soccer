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
    std::uint64_t aPrevious = 0xE5A81892DBA9593EULL; std::uint64_t aIngress = 0x9A3EE6A9320BB86FULL; std::uint64_t aCarry = 0xA66A485CAF71FD5CULL;

    std::uint64_t aWandererA = 0xC85B3ADDE6643F2FULL; std::uint64_t aWandererB = 0x9621E220B459F60BULL; std::uint64_t aWandererC = 0xEA65BE4147C502A0ULL; std::uint64_t aWandererD = 0xFF85DE5A4B3F2BCDULL;
    std::uint64_t aWandererE = 0xDB75449B81B9D06DULL; std::uint64_t aWandererF = 0xC46A8064F82E1FC8ULL; std::uint64_t aWandererG = 0xC5CEDCE5558BE25CULL; std::uint64_t aWandererH = 0xB0BC0D492B9B42DEULL;
    std::uint64_t aWandererI = 0xEA4679487509CE32ULL; std::uint64_t aWandererJ = 0xF5C1DFD5FCAC2737ULL; std::uint64_t aWandererK = 0xEAA5D3DB956A630EULL;

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
        aPrevious = 10426663004208620315U;
        aCarry = 18045910082724113709U;
        aWandererA = 17852224622608582633U;
        aWandererB = 9783174240441059396U;
        aWandererC = 15880791483521710957U;
        aWandererD = 17316371427147174995U;
        aWandererE = 10790945607902383678U;
        aWandererF = 16059220551981499605U;
        aWandererG = 10875001622230087285U;
        aWandererH = 13015633105149010962U;
        aWandererI = 18434526592724188282U;
        aWandererJ = 17776701124501081741U;
        aWandererK = 10071207400542159427U;
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
    std::uint64_t aPrevious = 0xF99BE29F252094D4ULL; std::uint64_t aIngress = 0xE4262464F8FB18F3ULL; std::uint64_t aCarry = 0xAA09492AFB9F06C9ULL;

    std::uint64_t aWandererA = 0x8844CA22BDD39CBAULL; std::uint64_t aWandererB = 0x80E7FF00C2BCAF41ULL; std::uint64_t aWandererC = 0xCFDC2B91FD722868ULL; std::uint64_t aWandererD = 0xB786BA6367776070ULL;
    std::uint64_t aWandererE = 0xB51295B6A33BD00FULL; std::uint64_t aWandererF = 0x98E8B72B6590474CULL; std::uint64_t aWandererG = 0xD26A2CA6A5B02098ULL; std::uint64_t aWandererH = 0xBEFD01E58FF76227ULL;
    std::uint64_t aWandererI = 0xCE427F947F00968FULL; std::uint64_t aWandererJ = 0xF6D68B375CFD0271ULL; std::uint64_t aWandererK = 0xA08AEBC00C8D0AD2ULL;

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
        aPrevious = 11194521310579714251U;
        aCarry = 16975307835897227536U;
        aWandererA = 16930488548766508275U;
        aWandererB = 13032768361351229780U;
        aWandererC = 11233944101373615034U;
        aWandererD = 17297708352276261391U;
        aWandererE = 17418040558045166311U;
        aWandererF = 11085653388912771837U;
        aWandererG = 16058155084961490533U;
        aWandererH = 11885525308933683933U;
        aWandererI = 10509054722037988806U;
        aWandererJ = 17040852630996433581U;
        aWandererK = 16102832514759493319U;
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
    std::uint64_t aPrevious = 0x8F12DF5C44786B91ULL;
    std::uint64_t aIngress = 0xDB278674A8317649ULL;
    std::uint64_t aCarry = 0xDABE0C7285055E2AULL;

    std::uint64_t aWandererA = 0xD0870FB07FB42E3AULL;
    std::uint64_t aWandererB = 0xD4DB72BC513617E7ULL;
    std::uint64_t aWandererC = 0xA15CEDB282AE0C55ULL;
    std::uint64_t aWandererD = 0x9BF3928C0959FDBEULL;
    std::uint64_t aWandererE = 0xB18695F6518A1A03ULL;
    std::uint64_t aWandererF = 0xF395BD1275477CE2ULL;
    std::uint64_t aWandererG = 0xD36BFDBD0C409A2DULL;
    std::uint64_t aWandererH = 0x90A6C7E6756DD3BFULL;
    std::uint64_t aWandererI = 0xE16CEBDB288F44A9ULL;
    std::uint64_t aWandererJ = 0x80C746F0D797731FULL;
    std::uint64_t aWandererK = 0xBFCFB15EE39B901DULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
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
    std::uint64_t aPrevious = 0xF546B2A0C8DD904CULL; std::uint64_t aIngress = 0xBC9206BF91994C9BULL; std::uint64_t aCarry = 0xA2B0C391DAF49F44ULL;

    std::uint64_t aWandererA = 0x92A83439C1436F91ULL; std::uint64_t aWandererB = 0xEA9CF10C252F69B0ULL; std::uint64_t aWandererC = 0xF649FE446E093285ULL; std::uint64_t aWandererD = 0x94F4F48F25E15ED7ULL;
    std::uint64_t aWandererE = 0xCF4A83B4E9700E1AULL; std::uint64_t aWandererF = 0xCB00827663625ADDULL; std::uint64_t aWandererG = 0xCDDA27925B85F71CULL; std::uint64_t aWandererH = 0xABF320B261750FEEULL;
    std::uint64_t aWandererI = 0xFB956DB07E386479ULL; std::uint64_t aWandererJ = 0x9961444F60E150A1ULL; std::uint64_t aWandererK = 0xD7A13BF0B3A69D8EULL;

    // [seed]
    {
        aPrevious = 11735517031190329051U;
        aCarry = 14841787162327007955U;
        aWandererA = 10845012704733236144U;
        aWandererB = 17966307307620690451U;
        aWandererC = 17882526167977367833U;
        aWandererD = 12995040948833792952U;
        aWandererE = 9831744009724490098U;
        aWandererF = 16873810744538805158U;
        aWandererG = 13393668691041177156U;
        aWandererH = 16506772330260925524U;
        aWandererI = 9225826421615652502U;
        aWandererJ = 17841442180814432708U;
        aWandererK = 13250826001466027438U;
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 1, 0 with offsets 1867U, 4732U, 3781U, 1156U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1867U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4732U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3781U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1156U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 3 with offsets 6902U, 3580U, 6515U, 710U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6902U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3580U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6515U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 710U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 2 with offsets 3305U, 2569U, 1497U, 7648U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3305U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2569U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1497U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7648U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 1 with offsets 4043U, 4980U, 5486U, 2329U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4043U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4980U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5486U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2329U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 3, 2 with offsets 370U, 1542U, 1801U, 1506U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 370U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1542U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1801U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1506U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 0, 1 with offsets 267U, 373U, 1524U, 1738U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 267U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 373U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1524U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1738U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 3, 1 with offsets 1484U, 1202U, 1789U, 1968U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1484U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1202U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1789U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1968U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 1399U, 634U, 113U, 800U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 634U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 113U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 800U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1304U, 1419U, 601U, 328U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1304U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1419U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 601U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 328U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 1 with offsets 5279U, 7447U, 1267U, 3186U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5279U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7447U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1267U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3186U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 3 with offsets 4395U, 5458U, 1637U, 1009U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4395U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5458U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1637U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1009U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 2, 0 with offsets 3387U, 4611U, 1246U, 6417U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3387U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4611U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1246U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6417U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 2 with offsets 5642U, 831U, 2582U, 6747U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5642U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 831U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6747U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7399U, 3996U, 958U, 1035U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7399U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3996U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 958U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1035U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1320U, 812U, 403U, 1914U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1320U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 812U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 403U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1914U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 911U, 876U, 5U, 756U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 911U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 876U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 5U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 756U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1930U, 1210U, 771U, 1192U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1930U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1210U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 771U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1192U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 546U, 52U, 1773U, 1856U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 546U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 52U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1773U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1856U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 [0..<W_KEY]
        // offsets: 1793U, 1607U, 1181U, 319U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1793U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1607U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1181U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 319U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseASalts = {
    {
        {
            0x1CAD9FD057C3976EULL, 0xCF5BFFF515680BFBULL, 0x08297229DB109ECDULL, 0x724394C82B618DC9ULL, 
            0xC3D030FAA3926546ULL, 0x418E75A15DE97A9DULL, 0x4A48629E4F6F7A4FULL, 0x2D486D1D2429E4E8ULL, 
            0x1665706B80F6D5C5ULL, 0x44B11D86DD8EDC57ULL, 0x61FB16A5F92928DFULL, 0xDC589F78B8DA5476ULL, 
            0x0EEE93A9769EE4EBULL, 0x2D409A4F1F00CF63ULL, 0x569E4D37DEF850F9ULL, 0xE4D3B5E1D1B21CF2ULL, 
            0x3C3938A4898B8338ULL, 0xB63C48AB91266151ULL, 0xA4001916F215A1C1ULL, 0x8D5752EA1317CD04ULL, 
            0xB1B229E718C38D77ULL, 0xFC2C564E300333FFULL, 0x58D85BE23E62D263ULL, 0x18BC5E295A160466ULL, 
            0x66F7902087B16BA8ULL, 0x768386E3E3C0CA78ULL, 0x4E2573770E87D7D6ULL, 0x9E8A52D433E79A4FULL, 
            0x88878458301DC32EULL, 0x09392B95685B423CULL, 0x085922FF4E015D62ULL, 0x0D0902E1C10D7DF0ULL
        },
        {
            0x375BE52D1AFD64C5ULL, 0xE54388FA935233A0ULL, 0x7047C9D64609326DULL, 0xC95A9BEFCB8F4D76ULL, 
            0x6D88BAF4284F236CULL, 0x6C99B53FF41D5E1EULL, 0x9FFACAE1B5B001F4ULL, 0x9C83464F947E0176ULL, 
            0x48CA89C97077B459ULL, 0x43DB77F7D03A825FULL, 0x48367438DB06B2E2ULL, 0x0D592FE06F631034ULL, 
            0xE06D34E12F48A330ULL, 0x2AAA570D7AA14D2BULL, 0x2BA604BF922DAE73ULL, 0xBE7CBD1BCAE09232ULL, 
            0x21613F942350F804ULL, 0x74D20C1EEF091BD3ULL, 0xD52CD044F4FA0F7BULL, 0x45DA08B7F1177ACBULL, 
            0xBA6A4B5B7CA2C971ULL, 0x4672CA7BBA6E58A8ULL, 0x1DE478377FFF6D90ULL, 0x7C38242ABBF2A6DDULL, 
            0x1799D8EF7D631719ULL, 0x00D8C6C245DC8305ULL, 0x59F6BC5A9C02B46FULL, 0xA5745122887F4C11ULL, 
            0x6B7D4A8207C46936ULL, 0x2F167785CBB7B6F8ULL, 0x390CACE399C89489ULL, 0xF894DD7CB543C658ULL
        },
        {
            0x01E076673ACBE6ECULL, 0x4552FC95B8C935C8ULL, 0x28A81945B303A38DULL, 0x3546D7DE0D221E91ULL, 
            0xD4DC8F9C29BD7262ULL, 0x07AC02300BCE15DBULL, 0xC738108DD0F1685EULL, 0xECEB0D99E02614D2ULL, 
            0x86B2D696352427DEULL, 0x3EE2D8B6F99238BBULL, 0x496697D611E32705ULL, 0x458CD3A8A81873E3ULL, 
            0x1506CE6439445AF8ULL, 0x18356DB60638F0B3ULL, 0xEE24BE0B03EB4F85ULL, 0xBA1BDBF17508678EULL, 
            0xF75447980A6E1200ULL, 0x03CA69D0DA8E46A8ULL, 0x3943FCF52209D611ULL, 0xD15A80FA1169B17CULL, 
            0xA7CF7DFA1BEB3194ULL, 0xB32028C452097B25ULL, 0xD87A352F83F6091AULL, 0xEAF5415800202E70ULL, 
            0x07726C552C509A46ULL, 0x67DD53A05D4426ACULL, 0x926394F97FC38A51ULL, 0xD4104F73683DD867ULL, 
            0xD94CBF2AF43B2060ULL, 0x6D131F79AC12E740ULL, 0x71370C4109DADB5EULL, 0xE622A819941478A6ULL
        },
        {
            0xF931D5FD9502CE3FULL, 0x2D4F3E893E46BEA7ULL, 0xAFE3FBCC0FE05F51ULL, 0x0C41C93FB2A7E215ULL, 
            0x64398306A411B242ULL, 0x15AC13350B3BD00FULL, 0xE77EE1159FFC0290ULL, 0x06EFAC0BEFA5A479ULL, 
            0x67D61A211FEF3074ULL, 0x148E2548FF937822ULL, 0xE3D699DCCD0DD555ULL, 0x41907747DD1D4D85ULL, 
            0x0E145A6EC3700128ULL, 0x87FB4D5B039EDC3DULL, 0x8704B19DCFA2447BULL, 0xCB53344D066A1BB2ULL, 
            0x094307B9E4D9C2B5ULL, 0x80C28B720BA96731ULL, 0xE4A31487B9974977ULL, 0x75DAF66CA8AA1B1FULL, 
            0xB48ACCC906CED370ULL, 0x1DF5B1B9CAB95E96ULL, 0xCB5980173DDFD037ULL, 0xA964FE5DC5EA1858ULL, 
            0xFA28269A74DBDC11ULL, 0xF8D4F4C7BE7D75CEULL, 0xA9063ACDD4C4AF90ULL, 0x807D0DA88E9F2223ULL, 
            0x6F9BA3AD65C87BEFULL, 0x13243A64C6CE69F0ULL, 0x183F0584D48729F4ULL, 0x4F08AE6F668E83A1ULL
        },
        {
            0x10D1129C245E5061ULL, 0x0103C502A3B828BEULL, 0x6ED46D75C33B4F0FULL, 0x40A65FF702745904ULL, 
            0x0E8C7C7D3C061FA0ULL, 0x0BA708BF9CCF9B25ULL, 0xAD2E3732D7091D0EULL, 0xEB7007EA3A3404A0ULL, 
            0x443151A9EEDE12C7ULL, 0xD0DCC5C0CD402053ULL, 0xFB538D254E9F672BULL, 0x330C81EFC4552CA3ULL, 
            0x56A20BA443272EEAULL, 0xDEDCE9940B24F518ULL, 0x8009D1E73D3F8B27ULL, 0xDBD4E156D0C08623ULL, 
            0x56DEC1ACB4AA422CULL, 0xAE72C3C502B4ACBFULL, 0xE79D5058D0BA4334ULL, 0x80DAC4FD87C17170ULL, 
            0xAAC5E258BAA389D4ULL, 0x686613653E9CAAF1ULL, 0x47D239D43B848277ULL, 0xC652D860F7268F72ULL, 
            0xF9F958BDE0360A5AULL, 0x7368BC26DA8D534AULL, 0xD66E91B97707EED4ULL, 0xC6C43A2C2A63ACE9ULL, 
            0x7429EF4B991291B2ULL, 0xFF48C1FBE8319562ULL, 0xF10DE391D9119B29ULL, 0x2ED3231F2DB1F69AULL
        },
        {
            0x9AE430A0FC572F43ULL, 0xC86C87B7A9CDEF68ULL, 0xD18B1673D604E5ECULL, 0x3220720358CD2CC9ULL, 
            0xBC249B97A0CA391EULL, 0x303E4073D2EC8D63ULL, 0xE551A1DC825A4A79ULL, 0xDECCFEAC161179E1ULL, 
            0xB74564457F3B8B14ULL, 0x98AA35E726E6EBF9ULL, 0x19A9A15A85144E15ULL, 0x05FC33EE94842ED5ULL, 
            0x40282CA27D891524ULL, 0xE1668DAEB1B24D74ULL, 0x6DD6BA61C674E839ULL, 0x49B0EF2263BCF885ULL, 
            0x9BFEFA7F2EE18C4DULL, 0x990983BD3F1F3245ULL, 0xC5E02C7CABDA8A41ULL, 0x95BAF769B3A2F507ULL, 
            0xDD0D237284929BEFULL, 0x8EBB78E976F63585ULL, 0xA7190C701C9ED969ULL, 0x78504F15A8D20CAFULL, 
            0xD98E84B77C742747ULL, 0x1633901317554A6EULL, 0x92C4566C9096AC5BULL, 0x3C542B48C6165194ULL, 
            0xEB88C9008189362EULL, 0x1BDEE244DA64133BULL, 0xEBF17D564869AF11ULL, 0xFE9B049FF870B41EULL
        }
    },
    {
        {
            0x6B8862EA7D3D7289ULL, 0xC1B98AA1FD8F9BE5ULL, 0xDBE4E276B71BB157ULL, 0x2A9F5F35422E457EULL, 
            0x996F7DD1ECF6A960ULL, 0xB1B7B4F794E68DCCULL, 0x20F553FD7B361D8CULL, 0xBE72A26FE0ED7F98ULL, 
            0xDEE5B38B6A282FEEULL, 0xAD00FDC95ABC655CULL, 0x4303B701C1A05C2CULL, 0x1045CE35B4774643ULL, 
            0x091547FC4EAA6303ULL, 0x1CD4C8F4EDEDCA75ULL, 0x161EEEB4658D9A83ULL, 0x74CC0B8F201267C1ULL, 
            0x9A9167963D36E107ULL, 0xFF8B7ACA246518A2ULL, 0xEFF7CDD15D2B98A9ULL, 0xA9CFC454F4FFD285ULL, 
            0x0DEF66D413C82E3AULL, 0x510C1C48FCCA7A61ULL, 0x062807467CB78D22ULL, 0x38AF089B0C436B05ULL, 
            0x70076B49DE9745DBULL, 0x9300ABAF2A8F8710ULL, 0x0DD49B097C7DE3E1ULL, 0x6A8272E2BDA79B71ULL, 
            0xC3C54588F052B239ULL, 0x2BF0DBD392CB9DDBULL, 0x69532858F2E9677DULL, 0x952A026E946A47CFULL
        },
        {
            0x94D57969AA189E5BULL, 0xB9309325A18B7B2CULL, 0x20374FCDC1B512EEULL, 0x3AF1051257DDD1CEULL, 
            0x92D61302BDC001AAULL, 0xEFA1682C784900DFULL, 0xBDB67989042664BBULL, 0x0B94DC1858260D04ULL, 
            0x95A8004BBEEDD54AULL, 0x60081CFF7912CB1FULL, 0xE7F08FE9C6E860D2ULL, 0xFC75302FE3E49EFDULL, 
            0x98DA7B4C303B2E1BULL, 0xDA0BAB85A68303E1ULL, 0xFBD639EC15C8D606ULL, 0x3D66799502ED4311ULL, 
            0x5FA3D3E439397C9DULL, 0x1B827ADEEB6B26E4ULL, 0x6FC27478FD9FDF80ULL, 0x020B46E5EF4D0FFFULL, 
            0x421B3B016B120318ULL, 0xB7E498876AFC3F2AULL, 0xDD6A363CC854B1FAULL, 0xC02F2491924E2086ULL, 
            0xFA5B37B1280628FBULL, 0x87A7E2079CD48AB5ULL, 0x7AC418E329226FFDULL, 0x6678C28BF5CB387AULL, 
            0x5CE5B56C3392070BULL, 0x358C3546118C63F7ULL, 0x760D9A888BFBC9CAULL, 0xF4DDBDB7A02ACB77ULL
        },
        {
            0x3497A1C310DD5966ULL, 0x5152B62AE7264F8EULL, 0xE8441A8EA8576AFBULL, 0x0827EBD7ABF708D6ULL, 
            0xB778DDA816B68F8BULL, 0x28DFFD4FB5059917ULL, 0x60ABE8677FB21795ULL, 0xFCC05A8ED33F727CULL, 
            0x271843D330C3E47DULL, 0x36ED12E7228C5FC3ULL, 0xBC678FA4C2FB992FULL, 0x54FD79C758FCF7DEULL, 
            0x5C5F13A19DEBBDBDULL, 0xE6395BFF5772A95AULL, 0x7ECDADCB7596675FULL, 0xC76C5D50921E0892ULL, 
            0x41C6CC4ECF859EC2ULL, 0x1E521E8FAB7927C7ULL, 0x6A87E5ACE033C475ULL, 0x2904C2CAFC920673ULL, 
            0xB8FA5CCB87AF86B9ULL, 0x36F08E30F9FA8CA2ULL, 0xFE23F0B2DD1C7F3BULL, 0xF33155B0E3F5296DULL, 
            0x0EEC8EA36FEA6429ULL, 0x7660E3BF18D2BFF2ULL, 0x3FFB8A6CB015FC72ULL, 0xC6175CDC76CDB010ULL, 
            0x396AF3CF6DA36144ULL, 0xB80CAD1F27D8FBF0ULL, 0x68F9CC4E3DAFFB81ULL, 0xCB0ED4AC942D0054ULL
        },
        {
            0x034CBE42D910023AULL, 0x3991E60570086552ULL, 0xD9B0AEF4BED6C8C6ULL, 0xBBA451350DE7CF61ULL, 
            0x6F210DFF20720098ULL, 0x5C0F57BD22647BBEULL, 0x8C4D8F671D59D667ULL, 0xCD8B9EE1FEADAB0EULL, 
            0x64D898589D152ACDULL, 0x4B52AB9162365F2DULL, 0x05999227B36C3E79ULL, 0x9C0F51A8AFE7D572ULL, 
            0x5E6E03A96693F1DCULL, 0xBC21AFA1F697CEC3ULL, 0x19178D25ADEB387AULL, 0x279923ACC6DAD25CULL, 
            0x71A01AB40BD9E48DULL, 0x5B4358D2D9F89C98ULL, 0x1A3834804A0CF304ULL, 0x5477E2662EAB0FA4ULL, 
            0xA5476086975D5324ULL, 0x024AF0E7943447DCULL, 0x1B03ED9C18E0235CULL, 0x738417E3FD982B1CULL, 
            0xBE6DC8CFDB59DFC5ULL, 0x7F1EB3D3164B4DF9ULL, 0x0D18984C9A56F870ULL, 0xDA0E5F5F8122E3DFULL, 
            0x5F2080522C5C29F3ULL, 0xCE8830B3F861F198ULL, 0x22101BE75C5255E8ULL, 0xBDA6732C2F2C1D60ULL
        },
        {
            0x78945B50993A1323ULL, 0xA2DC55C737A3C069ULL, 0xC30AE846DC63993FULL, 0xAAFD19DA7EA25A9CULL, 
            0x55B56D2ED866A571ULL, 0x2A41F47668CB026BULL, 0x8E164A11A778F40EULL, 0xFF9C237799785B58ULL, 
            0x5D3E88E6DC7E326EULL, 0xEB9A05ED1BD7F8E7ULL, 0x837411D96E1FBE47ULL, 0xB635A0F88D5D72F2ULL, 
            0xD759B00204F28293ULL, 0x3508273BA39FE471ULL, 0xBD69E2F6CE66264FULL, 0xAD43E3A948CB99A5ULL, 
            0xCAD16023BC30B473ULL, 0xAA215A93B89C8EE0ULL, 0x21FAA54DA2C3A538ULL, 0xA491F26C15E7FD03ULL, 
            0xAFC727DB8A4414E4ULL, 0x96716B08ACB7497FULL, 0x14089F88ED8A7B17ULL, 0xC25892CFCAF473B4ULL, 
            0xCBA6E3984EAFDD38ULL, 0xE8912D69A8A369C4ULL, 0x8C287E821420C41AULL, 0x1B498304DD813096ULL, 
            0xE972B0C4D1FC700EULL, 0xE9630D6E7942C30BULL, 0xD3DBE5BFCAC34468ULL, 0xF29F769DC4BFD92BULL
        },
        {
            0x5338335A5A1EA3DBULL, 0x1F203060A06A991FULL, 0x59BAE3A9D54FC016ULL, 0xF49F2F758E88805DULL, 
            0x105F747F9B162D13ULL, 0x1848E5C157FB11C1ULL, 0xEFF0755213611DA7ULL, 0x6CE083B2DB278C4DULL, 
            0x1B6B93F97A957A44ULL, 0x43A7D1AD332E7301ULL, 0x1C3FF387FCAF766AULL, 0x7698E88FD7171B45ULL, 
            0x97D0A4836E952E5CULL, 0x58F4C384E3412B3AULL, 0x93E8792119D3A966ULL, 0xC8139A7AF5E55789ULL, 
            0x1D1C7403C84E42F7ULL, 0xF1B44CF01E6DCE16ULL, 0x4EB6E71066367C53ULL, 0x852A6D7B43A9E21EULL, 
            0xB4F8E0AE67AB928CULL, 0x84668FFE61862CDFULL, 0x3094133A6F50D4BEULL, 0x07D748FB2867A626ULL, 
            0x0E5BA02C0A79D9A2ULL, 0x98C0DBED572A7EF3ULL, 0xF73D618C96C5D4D5ULL, 0xBB35B63A9C16A0DCULL, 
            0x12336ED16561C0AEULL, 0x0D3840D176370955ULL, 0x2A30E64F7D3DDDDEULL, 0x7BEDAE132F7A0254ULL
        }
    },
    {
        {
            0x6805EC95FE71AFA7ULL, 0x78063AF504A42656ULL, 0xF101A980985DE429ULL, 0x0F9D95B7CE8AAF98ULL, 
            0xA34CD869BD9896A6ULL, 0x36751C9848CF5211ULL, 0x0ABA1CDB2481DF43ULL, 0x087C90D4369AAFC1ULL, 
            0x0BD2020D16C45B42ULL, 0x15BA5FB7D53DB57EULL, 0x926E90495C5AB0ADULL, 0x4E4FB7B5F57CBEDDULL, 
            0x81EBEC0C5F8BA033ULL, 0xCDC5FF32B133573CULL, 0xBD173FF55F3DE7B3ULL, 0x6B4337EDEE39F1DFULL, 
            0xF9C11BF980B74D24ULL, 0x16FB0A7C324845FBULL, 0x82044A9606CA1ED9ULL, 0x9BB0F0FD4A787064ULL, 
            0x628561C1355074B4ULL, 0xC1747D4D425BD282ULL, 0xF1AA8974F0420A0FULL, 0x37EB11506D10673FULL, 
            0xF1376B7EDD3DEEF6ULL, 0x383CFCBE3AA493C9ULL, 0xF3A4C7A371E4469FULL, 0x18AA543FC243F525ULL, 
            0x9D2507E07AF03356ULL, 0xFDBA2AFFED075ECEULL, 0x9C65759B642499E7ULL, 0xEED36E8130D0EAB8ULL
        },
        {
            0x562EA3B4A479BF7EULL, 0x2AF467160524FF2BULL, 0x588EC63DF899E346ULL, 0x56938D89A8D4F3AFULL, 
            0xD72CC3FB24F976D0ULL, 0x44C7A7D62DDE4F33ULL, 0x265A76AAF66C0F8BULL, 0xE59A454F53D1C7DCULL, 
            0x7C071C0AD30652A3ULL, 0x419E276556D6E7CDULL, 0x4302679E8D78A5F2ULL, 0x4AC19842979239DDULL, 
            0xCE3F985197C3FDFCULL, 0x99E03285A4F7AAADULL, 0x815DA75AB8E3BD08ULL, 0x3828B58F5C0ED685ULL, 
            0x92C8A6762A775F02ULL, 0xD87A55DE94984E91ULL, 0xA871C026AECC8FACULL, 0x0417495D385D4B28ULL, 
            0x5396B39DC03F5CD8ULL, 0xC4F8683DB7F14F39ULL, 0xCCB7138EB2F41244ULL, 0x7DBDFAC197D0CB7AULL, 
            0xB94734B803F4A313ULL, 0x6FC6ED33A69D57B2ULL, 0xD015F1A95F2F4718ULL, 0xA80100044D1C2DC4ULL, 
            0x43F360FDF9E736DAULL, 0xCAD6AF20D17B97F4ULL, 0x87AF914DF11DB10AULL, 0xDACFE11081B854D8ULL
        },
        {
            0x0C246FEFDC517343ULL, 0xB4AAEBAEC67DFA2EULL, 0x647800C4FC17533CULL, 0x440A7B98F3C8C187ULL, 
            0xE0728971DAD883DEULL, 0xEF35B262221D78C9ULL, 0xD5ECD7BC788F05DEULL, 0xF849B5C86CCDE3CAULL, 
            0x6A3E9F7BE1F91718ULL, 0x3A7345D5212CA247ULL, 0x35A810579821A509ULL, 0x95F19F52655C9BD3ULL, 
            0x714A4F7C0C130450ULL, 0x31F7E74E694C0836ULL, 0x34D1A1A7B6513A99ULL, 0x8F6551964BA735E0ULL, 
            0xE41C54D6CBA24167ULL, 0xD782B46AF10FDC96ULL, 0x7CDE1CB4C18D067DULL, 0x625FDD2CAEF4BAF4ULL, 
            0x1950A7CAA97A21D9ULL, 0xFFD68C7998DA462FULL, 0xEC28798DEF34D892ULL, 0x68D348A8FE96E2D9ULL, 
            0xFA2AB5B6D74158F2ULL, 0x40A07345B2431C88ULL, 0x8F308AAEFFEAB66CULL, 0x2FA95B4661D5F944ULL, 
            0x6AF2FFA9942B317BULL, 0x3BD609CBFDBC59CAULL, 0xC42AF12E6DD88388ULL, 0x87222EF81E07EFE6ULL
        },
        {
            0xEBCCA5DA386D9C78ULL, 0x0DDEEDBAA57810B2ULL, 0x0B567F29D5928374ULL, 0xFBF46155DB0ED0D7ULL, 
            0xDF0F585165BF7774ULL, 0xB1871DC75C016ADAULL, 0xAB6D8B0556403696ULL, 0xADDBAE590F874AB4ULL, 
            0x098F26FBA3A241CDULL, 0x91B76771CCFCA18BULL, 0x8095A3301CF015D8ULL, 0xC5B837804D6B639FULL, 
            0x1DC9479C8FD32FFEULL, 0xCC72AC3DFEB7CD97ULL, 0x52DF6658FF81212EULL, 0xBDF64983DE21F670ULL, 
            0xDB40C7356AF3F145ULL, 0x4721735DA28DF4D3ULL, 0xEE97C276EE8CDF68ULL, 0x3FF5F52890DC2A85ULL, 
            0x05FFAF45827459B2ULL, 0xE49B0C09198AC30CULL, 0xE0B01BF315FDD01CULL, 0x5556660095F69769ULL, 
            0xDABE3EFCC1B46F92ULL, 0xB903A65D1AA1441EULL, 0x5CE1F2142259A5E6ULL, 0x45BB1D963FACCCE5ULL, 
            0x63EAF3A524A1A365ULL, 0xDB909C045367C020ULL, 0xBC627FB2B06222E7ULL, 0x68086A0BE7B4789BULL
        },
        {
            0x8357BCA270DD86B2ULL, 0x9D5FC1D3CC081DBEULL, 0xBD8DDD3182ADED8BULL, 0x4FD1DFD97ADBA83AULL, 
            0xF5E2CB2CD3AADC3AULL, 0xE060C2E88D94EDF7ULL, 0x4DF9CA0FDC29AC92ULL, 0x5E0CBE0D1B99F4AFULL, 
            0x73A5F1DA434124A4ULL, 0x1172A640D545FB77ULL, 0xBA7437B05D37E948ULL, 0x3C01974D3F4505B6ULL, 
            0xCEBE12B984D4D5A7ULL, 0x48502A662643B9F3ULL, 0xD88C1FE18BDA7129ULL, 0xDD4801E9FF574A28ULL, 
            0x7B8437F1C0397E12ULL, 0x842BAC92B2A3EBD2ULL, 0x01DCD09C3A5AD575ULL, 0x51BB721AB8030C93ULL, 
            0x9672654F551913E0ULL, 0xCFC7C155EDE7EB6CULL, 0x6A57095B638E24CBULL, 0xF2DA12EA716322B6ULL, 
            0xFFF686A88B76D22AULL, 0xF3BD917C4F16E3FBULL, 0xD4B1236E09859674ULL, 0x5D6F06007321FB5CULL, 
            0xFA3EA0DAB7B0030AULL, 0x3DB7B4E59A6DE55DULL, 0x22ABF3A1E97D4C7BULL, 0xC8281DE40FE53EB9ULL
        },
        {
            0x5DEC04B0044CBD7BULL, 0x1902FA287145CC10ULL, 0xB88EC119968633F9ULL, 0xCE0EACAEF5D860EEULL, 
            0x04B37CAEF54C4CB7ULL, 0x3D0DD50A370D5BA4ULL, 0x07D3DC04A872D02BULL, 0x677AE09486E721F1ULL, 
            0x499BC5230BACA217ULL, 0x86CC1866D713478BULL, 0xC6384452F8A25859ULL, 0x542D1804BAC089EAULL, 
            0x5FE4F5DF456C4F45ULL, 0xD4FDD82DED2D7CBBULL, 0x54F77B809D408C44ULL, 0x8DE9C2C9340A230BULL, 
            0xE9E9F6B133BEFCCEULL, 0xAE389377C943336AULL, 0x71F26F4CC8F591D2ULL, 0x7C241589E7BA4AA6ULL, 
            0xF3D1021AD4E8267CULL, 0xABF1DA2F73A7459EULL, 0x0E3295184EE61F03ULL, 0xCFB8CCC78749B673ULL, 
            0x4EEB2631F751E21DULL, 0x7F799B61398D0C7FULL, 0x99B8F4F0FB7A6186ULL, 0x8906654162D0E1ACULL, 
            0xD840C7479F459E42ULL, 0x486A2E655438D7AAULL, 0xD328B383815EB7F5ULL, 0xD658DDD70449784FULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseAConstants = {
    0x213FE65137B8D821ULL,
    0x023CBC9732A252B6ULL,
    0x69CFB63E01F4ED19ULL,
    0x213FE65137B8D821ULL,
    0x023CBC9732A252B6ULL,
    0x69CFB63E01F4ED19ULL,
    0x94BE296BAC519638ULL,
    0xE8AC6E45D412A1C5ULL,
    0xE4,
    0x53,
    0xAF,
    0xD0,
    0xA0,
    0x94,
    0x04,
    0x6E
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseBSalts = {
    {
        {
            0xE7230C092B3B3C0AULL, 0x111C9C8FD16D2511ULL, 0x7216E4C61B053004ULL, 0xDDC6A8C7FD0B7A11ULL, 
            0x62F23701647DF5D7ULL, 0x73B8FFD1331593EBULL, 0xF1E9B0D5D0F65E0AULL, 0xCB6A78CC8E9EA238ULL, 
            0xE04428A2D2F4CA6FULL, 0x65E882DABDC109B0ULL, 0x2C5513B89F65790BULL, 0x1A07E78DFF17C83DULL, 
            0x10AD723231643B3EULL, 0x0D048041B5E60A68ULL, 0x3BA91FD04EDB3100ULL, 0xF604D60762197AD1ULL, 
            0x5CE59016BF6DB20AULL, 0xFB3C9C20BDD44F5FULL, 0xF7CECDAAC58B3E17ULL, 0x1BD2B09FA78750C7ULL, 
            0x56CC947CEBD98F29ULL, 0xEB7D9BAFCF21D888ULL, 0x93469E3E50BCA3FEULL, 0xB97F6FD818C7C120ULL, 
            0xC8BBDF33581ADF3BULL, 0x3677716A50836443ULL, 0x7E81E4B7A86F9C0AULL, 0x892531B8A0BAD383ULL, 
            0x05B3A86682D840D2ULL, 0x53400E1E098F785DULL, 0x3130EA0C0A91C59BULL, 0xC152BC4C3DD5D80CULL
        },
        {
            0x9384304A7F9C81A7ULL, 0x39AF9D74ACD09AF6ULL, 0x2B6F148AEC980D98ULL, 0x1B16C7608E4F03ABULL, 
            0xEC1175A5FED0AE4DULL, 0xADD39BD4150A5DDEULL, 0x2E6B01B80C50122FULL, 0x90017DEE69D26E13ULL, 
            0x54C5955472A907BDULL, 0x483B97AFD6BDE0D6ULL, 0x724F9D66444446CEULL, 0xB0A252E7C4DF712AULL, 
            0x0DD1F52948C580B8ULL, 0xA1BFA80A8081DC54ULL, 0x264C643209A9E82DULL, 0x558385796E6D0791ULL, 
            0x200033BD118943ADULL, 0x87EE7031C9CDA1EDULL, 0x459A611A5D935B27ULL, 0xDCDB60D14BD67E55ULL, 
            0x6539A5A6A69FB383ULL, 0x753C2481286F8110ULL, 0x258EF2D6F2BF0714ULL, 0x70141319DAABDC00ULL, 
            0x811CD5B4F6056AE2ULL, 0xCAD2B2D027C3924EULL, 0x7013B230A87879D2ULL, 0x1A3334D68EA1C436ULL, 
            0xCA0FD3E265C0AE39ULL, 0x9B6A0D5C51F7DA67ULL, 0xDC1CCF7CA63277C6ULL, 0xB60372B79ABA3B08ULL
        },
        {
            0x4DB758F3FFCC597EULL, 0xE1EDBF08807F9446ULL, 0x3DFB5DC613346C17ULL, 0x77D3B383FC49E052ULL, 
            0xE31DF7BE2C54DE60ULL, 0x5A7A454C8BE42D49ULL, 0xF8F084232A7E5EF7ULL, 0x176CE0E08B18F870ULL, 
            0x5150F17DB30F3BDCULL, 0x8E5470DCA0B726F0ULL, 0x7B19E4CB0AB2D182ULL, 0xE765381B563C8A46ULL, 
            0x094094EC37690658ULL, 0xD13BC63F5A9A0757ULL, 0xED552EAA1A4BE07CULL, 0x3C8C49EF9C3B77A6ULL, 
            0x99CCA0220F36D384ULL, 0x45E82FD32730552FULL, 0xA5AC04E1658FD481ULL, 0xB6C775B4C24FAF18ULL, 
            0x3916DE041808B03BULL, 0x853483D1895FCA64ULL, 0xFF51114F45F8A4C9ULL, 0x1420109BF6D18E2AULL, 
            0x9DAB1F353DAC4BDEULL, 0xEE31490225C180EEULL, 0x6DB45E73B96EEFB8ULL, 0x40F3CF5B88736866ULL, 
            0x82BD0E611BD42785ULL, 0xAD24FB4FDA3BC797ULL, 0xBD74EFC54C0E43AFULL, 0x69937F8A6033BDBBULL
        },
        {
            0xFE76B9FEBD367D1AULL, 0x6508EE0E726ECC10ULL, 0xAE0F34CEB437BB7FULL, 0x310FE1D5E79783BFULL, 
            0xACC914766A74FA0EULL, 0x0D0823230731AE75ULL, 0x3540280D78D09844ULL, 0xC5DEB775F05D4BF8ULL, 
            0x45E2E699701E99C2ULL, 0x5480D17BC07DFB7DULL, 0x4094F002C40FCA1AULL, 0x08EF0BB46928FF2EULL, 
            0x32AE7610CB2D430AULL, 0x3FE0D3004A6944C6ULL, 0x292B577C7E90D38BULL, 0x696A436874392FE7ULL, 
            0x55B7C518AA05F0DCULL, 0x21A6E17A99F99527ULL, 0x4E0A0E4AA3EAC8D8ULL, 0x0773A7ED6FF856BAULL, 
            0x58CBA9B923074D67ULL, 0xE1A3ADED48414C58ULL, 0x2455E02823B70785ULL, 0x964B0728CC7873EFULL, 
            0x664A90F7CB25B0B4ULL, 0x73AA9A35052A908AULL, 0x787989B8A8E439F6ULL, 0x15116D9706391347ULL, 
            0xAE913259B9753AB4ULL, 0xBF377729A3F303E8ULL, 0xDCB8716F49C77686ULL, 0x6BA4F00A180B038FULL
        },
        {
            0x23F0C4EE85103E59ULL, 0x4D68BC5BE8EB327AULL, 0x65A990BF9D28C4BEULL, 0xD8858CE92CDD9102ULL, 
            0xCA90A92B8D91D23EULL, 0xCA25386123E86050ULL, 0xDA06C5F1DA924886ULL, 0xFA6F41DEEB9F84D1ULL, 
            0x01119B06D885662AULL, 0x8E65F2B7A6896837ULL, 0xD4B2A02E3722993CULL, 0xD768372F23082118ULL, 
            0x74169F0670058EEEULL, 0xB9BEA1BC636F4316ULL, 0x8C498E87EBEE2C3FULL, 0xDB13117F9FB96430ULL, 
            0xF296AF1F7831A3EFULL, 0x60AFC9C6C35A76C6ULL, 0x0CB0B3CCF36B05FAULL, 0xBB83C75325D4EF28ULL, 
            0x45D96A9FFA93790DULL, 0xB231B3B8F9BB0298ULL, 0x510B2E89F0E81967ULL, 0xF3767A50A01ADF5FULL, 
            0xE84856479C9D5503ULL, 0xCE38B18DF180E22CULL, 0x5BDD905F1859E31CULL, 0x35C3A0654F462B4CULL, 
            0xD89DB37CFD3CA9BDULL, 0x1D3738008AFE3814ULL, 0x3E4A53E09E297C96ULL, 0xA5833258CBCCEFC5ULL
        },
        {
            0xFBE4BFDDAD55A187ULL, 0xCD042290C750AFA0ULL, 0x3A4B2E90080B2D77ULL, 0x4EDE8A227647AA54ULL, 
            0x6E88B159F32E6FCFULL, 0x50E6FE6CA3FAA685ULL, 0x2CDBA1425633BB1DULL, 0x08E8B6F81E064A41ULL, 
            0xFA11C27170644A45ULL, 0xD37F6764B06AC0BAULL, 0x4BE56E230ECD097EULL, 0x16159EC3CF64C39CULL, 
            0x2B89D5690487691DULL, 0x70AF694113A0CAD3ULL, 0xA531E43F671623ACULL, 0xBFD6D9DDFCE489D3ULL, 
            0xB99DA861DB047A72ULL, 0xFDD92EE44C1F1026ULL, 0x0520D69CA9847675ULL, 0xF7095845F877166FULL, 
            0x0263DCB9835DE756ULL, 0x73313406B5C357A8ULL, 0xA05D6AC8F3A63951ULL, 0x25BD19E91B6E102BULL, 
            0x26936916DECF74ADULL, 0xB16E68629BDC4994ULL, 0xAB4EF06B8013E0E3ULL, 0xCB4AF6ED98066863ULL, 
            0x76892455998BEF65ULL, 0x1B7052A111F2D26EULL, 0x4C154365F21982C7ULL, 0x7D10FE6E98D5B3EEULL
        }
    },
    {
        {
            0xDA18E9DEC675E0B3ULL, 0x3657D3EF7A6C27E6ULL, 0x1E4CC8A9CE828D59ULL, 0x7F5D1E79A14E262FULL, 
            0x2367D76729FEF1D7ULL, 0xD760E62EEE55F1E5ULL, 0x3E2AA800295FB791ULL, 0xF4CF46C63E8290B0ULL, 
            0x9C05F659DED8D0CCULL, 0x29825C0B13B875E0ULL, 0x640A6BED8F6852DFULL, 0xC4554ED9428CB849ULL, 
            0x3F786338C0AACB7CULL, 0x915BD2C2BCCCD775ULL, 0x45896C46450800A9ULL, 0xE8EBA7AB3537BF96ULL, 
            0x428574AD23510044ULL, 0xFD394D5BDE8BB020ULL, 0x6DE4AB719F829918ULL, 0x20A0A06EA1382683ULL, 
            0x3CAE801B15F70C48ULL, 0x991BEB1BD88E6CFBULL, 0x71AFF42467BE0007ULL, 0xD718F8A3BA623DEEULL, 
            0xFC62BA06D095CF99ULL, 0xCEDCF86C40372FF0ULL, 0xA0E8F5F128F245FAULL, 0x1E479586C8F6CC1EULL, 
            0xEC48BE5EDB751521ULL, 0x82714229DAA224ABULL, 0xE475129A1DFEE73BULL, 0x1CF7922170729FFBULL
        },
        {
            0x2CB3F53DE1E99E65ULL, 0x69FE65F565F73D6DULL, 0xB47B0DEF561B08A7ULL, 0x6BFF9D617D4B15B0ULL, 
            0xD672F0876ECC6A7BULL, 0xF2BB5295D384D4F2ULL, 0x65BB34AC5B4DA116ULL, 0xA5CFBD2DD37451D3ULL, 
            0x57F25019E14F0926ULL, 0x847C51BBDB0A65DAULL, 0xC44352B6C0A22206ULL, 0x7DD7B57C9E6BEB7BULL, 
            0x5C288AE806155F05ULL, 0x3861EEA3703410F8ULL, 0xD180E062B5C9CAE3ULL, 0x3124517F776A85E1ULL, 
            0x65F8C4E387206CB8ULL, 0xD137045C1C5B2E65ULL, 0xE874F5E4204E2011ULL, 0x687F645D7BA1572CULL, 
            0x8C9F90A1129189F0ULL, 0x4E37B1D16242AEEFULL, 0xDD4D4B1C0FB1F170ULL, 0xD15D4087D821502BULL, 
            0x4D3625678B2CF705ULL, 0xC9717B230DC6B7F9ULL, 0xB6ADB14C0040A1ADULL, 0x28A9E3EAD9DFC4D7ULL, 
            0xE0A1EF056CDDB126ULL, 0x246658EB5B236E52ULL, 0x790C8EE91BDE9CFCULL, 0x2610FD29041EADAEULL
        },
        {
            0x245D4C0194D31800ULL, 0x75FBE88FED4D895DULL, 0xCE9FF0C2BE1B96EBULL, 0xC37EE832222361BCULL, 
            0x6D0F9BB1C0BDDC04ULL, 0x64734BF6057141A8ULL, 0x76FE7141937C1C98ULL, 0xADA80F3985B86A26ULL, 
            0x01DEFB2293F8C65FULL, 0xE5FC2262EA00AC89ULL, 0xA76284A0DB4DB6EBULL, 0xDF752DF89DFFF2E6ULL, 
            0x1D6465763B3796D5ULL, 0xE5ECAF0C47F050B7ULL, 0x62DAC6178B6C6444ULL, 0x8D03D16F5798D7EAULL, 
            0x1727A8C650D2B30DULL, 0x16371BD949120EACULL, 0xDD6FE0EC7A1DA0CFULL, 0xEA925EC044645FD4ULL, 
            0xE74F803F51A4B3A1ULL, 0x4ACC88CA08C5AD96ULL, 0xD8E3165F577714C3ULL, 0xCCBF151E198F1493ULL, 
            0xA50B5E182E7C3767ULL, 0xEA9A7BC769442DA9ULL, 0xC62DBEEA3473C794ULL, 0xC9027873BFA1FC6FULL, 
            0x08155E9AAE3287D7ULL, 0xBB2923D103D56D8EULL, 0xA4E83710E58E06AFULL, 0xFB1611631B72DFDCULL
        },
        {
            0xC26C57D3ABC65E50ULL, 0x92D847CEF6BB7978ULL, 0xAE79270EA91B45F8ULL, 0x48240174E03766B9ULL, 
            0x6B75091B8B302F44ULL, 0xB7855BD6758D4F8FULL, 0x2CF59FF4E910FE68ULL, 0x3FDA574BAE769584ULL, 
            0x2D095DEFDD521A95ULL, 0x084140DC17F8C0ECULL, 0xE35366ABC319715EULL, 0xAED9D4CC7ECC3742ULL, 
            0x381228BDCC0139C2ULL, 0xC5947922D2D3B159ULL, 0x3AB60D79E249D285ULL, 0x92164A4326F06649ULL, 
            0xA413D1BAAAE23A16ULL, 0x655E9ECA85E9778AULL, 0x3C53EE303951FB35ULL, 0xBC11601EAC6965D4ULL, 
            0xE49BBF74928F26BBULL, 0x57B6755C87259ACBULL, 0xB0BC0BEA1DAE9000ULL, 0x8102AF400BE5D5EBULL, 
            0x0E4A868BD7A8B25DULL, 0x4F703752A09E89F4ULL, 0x18C6D8203365D703ULL, 0x313FE20EA2AC29D6ULL, 
            0x17E812D5257412D8ULL, 0xD48E28F87B73BCF0ULL, 0xB34EF8ABB27A2E2AULL, 0xF4FCEE5629D9C7A2ULL
        },
        {
            0xEDFE7D2D9E3C8583ULL, 0xE0DE2B28337C710EULL, 0x538BEE696F92F415ULL, 0x78C5EACE336B3CE0ULL, 
            0x7BE05C351888FD30ULL, 0x564B7F2EC9BF7E42ULL, 0x3D10167FEB84F5F3ULL, 0xE7AF3DC2FB4FF8DCULL, 
            0x57604662F6CB5566ULL, 0xB683A71C8ABA9FFEULL, 0x8027E0FF9EEB99A6ULL, 0xF5D204878E11287AULL, 
            0xC77A8311FBA57024ULL, 0xEEB8A7E102483E56ULL, 0xA14F5941950B34A0ULL, 0x9AF651BE7A213CDAULL, 
            0xBCE48BEAE636605AULL, 0x39B0257DA1B65098ULL, 0xE30DB10C14F2B6E8ULL, 0xEBC684604D348C53ULL, 
            0x010E45C9E95F73B3ULL, 0x324F44E2D0AD000EULL, 0x0884B0C877277D51ULL, 0xCD04BE3DF0D35F67ULL, 
            0x42C24E47DEF71009ULL, 0x0549A246CA08F7E3ULL, 0xFDBE043128BE579AULL, 0xF6314DE9FAFEB4D8ULL, 
            0x47BBF02A521E99B4ULL, 0xFA8A240A11CD99DFULL, 0x1AB983C4667B2EF7ULL, 0x782276F34AA74F8FULL
        },
        {
            0xF40F1BFF45F7C42DULL, 0x471645D300825CD7ULL, 0x84DC948983C0E394ULL, 0x21CE5C05754DC13AULL, 
            0xC08C419A23C1B5C2ULL, 0x0610F8C448ED51B5ULL, 0xEECFC29E737F398CULL, 0xAF5248E8224F2A60ULL, 
            0x10B8262CA7FEF5C7ULL, 0xB405F19479D2FC14ULL, 0x55768F62BB43E625ULL, 0x31FD1F233E3D3ABFULL, 
            0x51F4273B2F3D0FBCULL, 0x2483A9D614D01109ULL, 0x751F1B4B2280C89AULL, 0x983BDD0FC20F2ED2ULL, 
            0xB431ED9A493AE458ULL, 0x5FB061F75BBC2AA1ULL, 0x2771E7534B5E7753ULL, 0xB79D237A78B33F6AULL, 
            0x0CEBBF2AD57C964CULL, 0xA52F8F77AB8CDFCBULL, 0x9A39C2000116719DULL, 0xB5F0641C5349C56CULL, 
            0x94953719262694A6ULL, 0x9B83ABFDE6FE1736ULL, 0xB147822CB84DEEFFULL, 0xEBB96417564F8017ULL, 
            0x40515C9E69ADF430ULL, 0x7C1CDABD88E93D91ULL, 0xA7F9FD036CBFBD74ULL, 0xF9340D9F886A0BBCULL
        }
    },
    {
        {
            0xA169281D2A50D298ULL, 0x5A2C737287B3994EULL, 0x641FB1E143B72727ULL, 0x226CCAA0F055CD27ULL, 
            0x3A58AFCC2C43CE7AULL, 0xA6174A2A7A9F3B65ULL, 0x7A0278B4A8AAA8FEULL, 0x6287C0FFD88A5876ULL, 
            0xC918D6C62769418CULL, 0x8EE23221BACE03DAULL, 0xC54A5AFDD9F96F89ULL, 0xDC295B47B6333B17ULL, 
            0x1CB5225E59CD8FA4ULL, 0x7C3D93689EFDDFA3ULL, 0x36704C3977A57560ULL, 0x96C37C4965CCC978ULL, 
            0x00C32F27A06EA9A1ULL, 0xE7195C695886632DULL, 0x54387E7A965C99EFULL, 0xF7153E5DAD2A6814ULL, 
            0x6085326D5BE43AFCULL, 0x9509407CB014BB89ULL, 0xA49DC66B1AB5F7A4ULL, 0x5D5C2FF0AC3C496EULL, 
            0xFC5FC2A662F6AB2DULL, 0x10F9F1D71C6ED9D0ULL, 0x4EF01F48E17B77E7ULL, 0x78377AE863503D94ULL, 
            0x3B691FAEA8C57A2EULL, 0x62E85E7DDCD1767AULL, 0x486B7FB87EDAD2EEULL, 0x34812B1DC7CBDD1BULL
        },
        {
            0x77D4A5D5EA1C4D5CULL, 0x9847D4F1B549791BULL, 0xDD94E0F230713B9DULL, 0x65A22C2763A0213CULL, 
            0x1E23BF044EAC5113ULL, 0xEFCC391346ABF11DULL, 0x1DE77BE695D722C2ULL, 0xC7C8764E4A698BE0ULL, 
            0xE49C1BD8FD10AB7AULL, 0x3983717F9503B67EULL, 0x9EB93EDAD7DAF261ULL, 0xCB681B1BA8AF6F0EULL, 
            0xC31DBC0E26239AC7ULL, 0xBC4B119926816E1AULL, 0xF5BF1B36789766E5ULL, 0x53BE44BED90A4037ULL, 
            0xDF22BAF11BA8572AULL, 0x0942820A2C15441EULL, 0x8D9EA77C2EDB4E9AULL, 0x9FE67C104AC6DD61ULL, 
            0x2AD5A79CB0F52C09ULL, 0xE01C71E407B0615CULL, 0xBDEA5B40CE4BEDC4ULL, 0x6CD90861FB5719BFULL, 
            0x9EB3C36E8A2E242AULL, 0xE4E961828A0DE207ULL, 0x11A56B2D839F629AULL, 0x3FA3077C2EABD170ULL, 
            0xD8B3F375B0ACAE9FULL, 0xBFF9B5D8B06D7869ULL, 0xE7AC858F27846320ULL, 0x0DA7958A28A07020ULL
        },
        {
            0xE96CC113CBEFCEACULL, 0x968B76F568190840ULL, 0xCF1D82B9DE431AECULL, 0xB0B9CCF28A6B8D69ULL, 
            0xA5447484A429D0ADULL, 0x4057C7941D9237C6ULL, 0x571E4B28C533A3F8ULL, 0x5306B8FB2D4D8979ULL, 
            0xED67E7FF9A670506ULL, 0x497B71E842F234EAULL, 0xFF3BF0E280C6BE74ULL, 0x2B260939B99FD157ULL, 
            0x3A084A49C974627BULL, 0x47132CE5CDF1E170ULL, 0x7235D7D1BF81C837ULL, 0xD4577A7541F6D431ULL, 
            0x6B360EB63B729BBBULL, 0x4F917F4E45E150E4ULL, 0x2E30C9442D9D1075ULL, 0x2450C92ED9871FE1ULL, 
            0x754525C5B3EA1729ULL, 0xED72E26BF342A21AULL, 0x3294B1B8A9FDD4F6ULL, 0x0961778BFB4C92DEULL, 
            0x79A571E79ED98660ULL, 0x0D38379A302E9033ULL, 0x7BF3155F06B2C8CBULL, 0xD9ADAA720DFE5955ULL, 
            0xB58E7E5CBBEA6204ULL, 0x9292145AB3054719ULL, 0x5D1DD90F9B62DE98ULL, 0x115EF7CD22B62C7CULL
        },
        {
            0x762DF662B69930ADULL, 0x8B17004D4F73478CULL, 0xD5B462E81446A714ULL, 0xBE07769B7D985A48ULL, 
            0xA4D11023C2274320ULL, 0x242121E611414D89ULL, 0x9DB9A1AACF885115ULL, 0x27CD1CE35A1F4F9FULL, 
            0xE0BB611965C96145ULL, 0xB8C3DAED55AE6355ULL, 0x3092BAB745B5D506ULL, 0xB14010860B19EC2AULL, 
            0x37D4ADD1A514B997ULL, 0x65216221C8784315ULL, 0x9D8684D6325867F7ULL, 0xDB81F45D6A55ABB1ULL, 
            0xF67DC3AD1B78BC8CULL, 0x7A27E1C744601AFFULL, 0x7611BFC6D09E55B0ULL, 0x631B69A121FBAC1CULL, 
            0x2F7FF4B37C6B15CFULL, 0xA73059314DDA5C9DULL, 0x51F282785F62D695ULL, 0xF19AA3F242EA0DFEULL, 
            0xF0DCF9461D13418BULL, 0x24AA03A16B056342ULL, 0x12484B04C9CE8822ULL, 0x9C79C0C51814DFB9ULL, 
            0x0EBB3F6145DDB3CBULL, 0x48C488862C8BE734ULL, 0x7E6A2EDAB0DFCCD5ULL, 0x99DD7BF160613999ULL
        },
        {
            0xB38D22878CF6D184ULL, 0x802A7411301CE056ULL, 0x4E7F8839B88AEC9BULL, 0x1BE507ACD4C6B900ULL, 
            0x1D95A937EF454F9EULL, 0xDE3331203A2B93C3ULL, 0x7FC36380A1D820EAULL, 0x2BC2B8C804533FDEULL, 
            0x118D6C5E19A55055ULL, 0x3D4E0ED0005FCCB8ULL, 0x1352F5EA9D37557AULL, 0x4244F2865551DED7ULL, 
            0x7DE8F5B82FE210ACULL, 0x775EB3C28844D805ULL, 0xE7B8E888F61813F0ULL, 0x1E4A87A60329D33BULL, 
            0x800C17F8C54F437DULL, 0xA69C925EA036545BULL, 0x0C64F4E59B40DCFFULL, 0xE4A0EDA3DD0076ECULL, 
            0x9B3EEF749C157D95ULL, 0x99B9D63865CADA50ULL, 0x411063E1B46E9076ULL, 0x009824480A7F5908ULL, 
            0x2188FFC2B121A1EDULL, 0x6EF3605D1F797C6BULL, 0x81C21C721A86A5FBULL, 0xA0BE40F038D03605ULL, 
            0x6BFA8B7EEFBA929BULL, 0x6AED5D6A934CE1D4ULL, 0xE4E814263CDDF822ULL, 0xD8BAC049FA673428ULL
        },
        {
            0x39C537D425B2893CULL, 0xBCE04DB3EB2F40B8ULL, 0x312E1BB7EDBF9A84ULL, 0x03E1FB90F9C94693ULL, 
            0x4A931C72CA6DE8D9ULL, 0x3B478243BE2FA806ULL, 0xB4015B4E69943C88ULL, 0x837D057BF4AD37A0ULL, 
            0xFAF5354E504ADAC1ULL, 0xEAA1EE9BF08B61CFULL, 0xC8D0DC067AC4C8C2ULL, 0x3FD203D4C3093180ULL, 
            0x196B16C3C1D12D85ULL, 0x095E20D89872D7D7ULL, 0x8AA744D9088C95C5ULL, 0xFFB7CF2101B93722ULL, 
            0xF96C8ADAD76E24B3ULL, 0x1FDD311C1C241299ULL, 0x05DCA4BCD01EF9C3ULL, 0x104DA557CEBB161DULL, 
            0x52745963C12C431AULL, 0xB7A764849205476CULL, 0x36847C0F5AA44AEBULL, 0x43C61C98D85E6B5AULL, 
            0x1530B8FB4206B5AAULL, 0xA8E231680E696A76ULL, 0xBB68E63BCC91E138ULL, 0x43ED4ED45F724622ULL, 
            0xB8D225C9118DAF9AULL, 0xAEE00A299FDA31ACULL, 0x429322AD19049355ULL, 0x5149A4436CC01070ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseBConstants = {
    0x048312B1CE7FF6AEULL,
    0x05FC75869FBDFD9FULL,
    0x84FC7E18E2193D7BULL,
    0x048312B1CE7FF6AEULL,
    0x05FC75869FBDFD9FULL,
    0x84FC7E18E2193D7BULL,
    0x07F040FB1360F050ULL,
    0xD74583D5DB30B2BAULL,
    0x6E,
    0x26,
    0x61,
    0xF7,
    0xCB,
    0x55,
    0xFD,
    0x52
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseCSalts = {
    {
        {
            0x3D0E6218FF195BECULL, 0x3B161500EAD48CD5ULL, 0x874C0F8727571684ULL, 0xC5DB98BC72E60ECAULL, 
            0x2C49464B39482774ULL, 0x7B0F872E1183F532ULL, 0x8AEBE2D06A68B69AULL, 0x69958000F0F90272ULL, 
            0x44D804403B98584EULL, 0xDDA2F87090CE0E8EULL, 0x8AF1CB1447DB2135ULL, 0x1D79AA150BD9A6DFULL, 
            0xC21BCFF1034F0C48ULL, 0x38B7D6A8BDE5A730ULL, 0x6677424CFEF86C4CULL, 0x7C2B9D1D4B758FFCULL, 
            0xEF479F72A8A25D84ULL, 0x48DA63BC0EAF62D6ULL, 0x240DE4C050B6D7F1ULL, 0x7EFFD961FD938FB6ULL, 
            0x6E02F6B62641AACEULL, 0xAED79A974CD69B4EULL, 0xE5D8059C65643ED0ULL, 0xE5BEF7E12943493AULL, 
            0x545D5DBBCC79D264ULL, 0x564606BDEFFBEEBDULL, 0x9A5158B0057D3ACEULL, 0x8883BCA20A963CCAULL, 
            0x8FA710B2261D52D7ULL, 0xDE6C92FA3B60AE19ULL, 0x2232846B6B895B2CULL, 0xE869D35309905881ULL
        },
        {
            0x1A03C345CED7F3BCULL, 0x4E4E21DA43D46179ULL, 0xC6BFE5C7BB72909EULL, 0x7CDCDE8DC435D741ULL, 
            0xD455C265BC9948A7ULL, 0x9D2F7627EB2C9FB5ULL, 0x147FB75505356A7DULL, 0x032167F739B8B55AULL, 
            0x771629DF602B3EA4ULL, 0xDC1991C3BC83D280ULL, 0x7C3E404926E8696BULL, 0x3E875C3181E7018FULL, 
            0x6181B22D66BE6325ULL, 0xD0DC5F857EB0263BULL, 0xFD4BDD36D325717CULL, 0x74346A6A81AA800DULL, 
            0x1E7C34E342709377ULL, 0xF3CD3190A25B184CULL, 0x423976AEA23F4DDEULL, 0x2781D0E1F2BA3136ULL, 
            0x7251E02B6D624CA0ULL, 0xE32082A36C2657EAULL, 0x4C81613F7A832D68ULL, 0xA6DCD051DC6EBCBCULL, 
            0x9BD38A4C8DE7F9FFULL, 0x970A87AD23717663ULL, 0x64EE77B681A1C9FAULL, 0xABE04D111776A9D4ULL, 
            0x4F8C1EB5DE1B2500ULL, 0xE1FC639277D81E6CULL, 0x8BAFE676B8C95D06ULL, 0x19A4F0F3236EB8ACULL
        },
        {
            0xB6B7D42D965247E4ULL, 0x30FF354A354BD267ULL, 0xAAC8E7620226739FULL, 0xB15DBABFB21CA879ULL, 
            0xF4772C7F48B1C431ULL, 0x3883E2E86EBA751BULL, 0xFD74F305063F4B9FULL, 0x9F533917803E6717ULL, 
            0xE539FBF108A28BCDULL, 0x45C04D2713321B16ULL, 0x1B2356A6C3B187CAULL, 0x51B4154725C12B40ULL, 
            0x7EF4E7F85DF0DF21ULL, 0x7441B61686B29A0BULL, 0x48E7D035D70BEC0DULL, 0x4C9A9D774E85FC18ULL, 
            0x689F2DA1F28449B5ULL, 0x7F694A81CE831EEDULL, 0x64A47AFC3522D97DULL, 0x503123A4829A49E7ULL, 
            0x3E12F2C259CA3A9FULL, 0x3FFF462CAAE85C91ULL, 0x03371E6D07FAE524ULL, 0x60A4871FB6693F63ULL, 
            0x487D1E7F1BCE35D5ULL, 0xE8FB5667E267ACA1ULL, 0xF0BC64944E2A88D7ULL, 0x85021D8ABA31116FULL, 
            0x9E10567A8B345BAEULL, 0x0A95E7C0D48083CBULL, 0x6B99AD69A6AD5D88ULL, 0x7B355E1E2B0C9A60ULL
        },
        {
            0x9919A68BA27C1C1EULL, 0x611EDC07E806D00AULL, 0x6C2A83E47A9BAFBBULL, 0x7910779BF00D9D27ULL, 
            0x90313E3D46CD136AULL, 0x089E9E1D0C4E2D77ULL, 0x05FE37E07C1DAC9DULL, 0x087B8E2E131D6CAFULL, 
            0xC24423933814D906ULL, 0x5342C9E61D201C84ULL, 0x87A4E259148A445DULL, 0x57B68DD659EC9B0EULL, 
            0x3417DA6873550C75ULL, 0x124DB1FF57C033F0ULL, 0x352DB41F5A1F431AULL, 0x4E21587C078BF356ULL, 
            0xCC8FD9732AB5979EULL, 0x6976AA97D9B8BD36ULL, 0x9BADCA9FAD6B340AULL, 0x250D4EBD5987FAC7ULL, 
            0x8400342E87BBC413ULL, 0x5A9F9C89F2E02A9DULL, 0x987C36B6F495EC31ULL, 0x3F33C7D65751040AULL, 
            0x669F197CC6F595CFULL, 0xA93B83329B6E05ACULL, 0x7E755556BCE382C8ULL, 0xBD40353E36A50BEAULL, 
            0x013488F9F302B596ULL, 0x8D377D8CCF5F7765ULL, 0xE9FB9D4096905A2AULL, 0xE856C034AA62D35EULL
        },
        {
            0x85E025489B64B50AULL, 0xE667634499EA5F0DULL, 0x22B4BF7B3B7BC084ULL, 0x217D06CC04247164ULL, 
            0x906DF116EAACB1A8ULL, 0xEAFCB3F09F59C554ULL, 0x08772F14CB18B02FULL, 0xD9BFCC080A086806ULL, 
            0xD910119C2B1775FCULL, 0xB39918B8949177DDULL, 0xAE75A82C424C9055ULL, 0xC97EC1776F278D65ULL, 
            0x46B04E83319B2775ULL, 0xE250B1248A8C5954ULL, 0x1664F3D8E589D4DEULL, 0xADF0925A23EDFB13ULL, 
            0x0EC2EA162979F55BULL, 0x877C8E5216E0AB3CULL, 0x00F3ADCF8444C331ULL, 0xAFB1968B2203577CULL, 
            0x2247D86CD9639A81ULL, 0x569F80E89112C4ABULL, 0x02EAD52A92D474A9ULL, 0x48F5B0AC366FD9ECULL, 
            0x815D5DD426C56284ULL, 0x33E64AA15D673CF8ULL, 0x48EBD92CC5F8DFDDULL, 0xAEC782CEDF059E90ULL, 
            0x2E4DC9E8D37F5C5DULL, 0x50BB68C7D6FDEC91ULL, 0xF180069C0E87FD87ULL, 0x44CCB8BD9F32A5CCULL
        },
        {
            0x28CF828EB16D47FDULL, 0x999A6A65C52B42D5ULL, 0xF38D97E5AA98F6E6ULL, 0x8467AA412C600137ULL, 
            0xC057B89DE19D7648ULL, 0x65DBF4042C2D2C28ULL, 0x3BEA164DE2D1B3A6ULL, 0x77BFF9E013713A00ULL, 
            0x81A15851F43C0E88ULL, 0xCB22F8ECE3301D25ULL, 0x2DCF275A03B3770CULL, 0xAA43B3A9E544EBF4ULL, 
            0xE7A09F68FFA79B70ULL, 0x99490947920C5BB8ULL, 0xE16C5C8BBE91D910ULL, 0x13A04685B383A4CCULL, 
            0x16809BFDA451469AULL, 0x70D81744D344D2C0ULL, 0x496B24760AA0BE29ULL, 0x481BF7490C55C9A7ULL, 
            0x608CBAE522B403F9ULL, 0xAEB9C93285B14717ULL, 0xA5E8A9AF538F9734ULL, 0x6482B06E70BAC1F8ULL, 
            0x1D1D342DFA43BDEFULL, 0x1B18E2152727B263ULL, 0x2C8E214F4738BFC1ULL, 0xE90FC3BDC98AB10AULL, 
            0x4874D92D3D0F24D4ULL, 0xA84311BA7AA19FF3ULL, 0x34CC425D057AFDF3ULL, 0x2B2064128BFAADD7ULL
        }
    },
    {
        {
            0xFF1D1C990CAC21F4ULL, 0x1439E24B41A61FD9ULL, 0x0E124962EA64DC6DULL, 0x74931F712525F55EULL, 
            0xB68BA18329AEB04AULL, 0x59D2BC24175EEC39ULL, 0x447E55DF2461FEA1ULL, 0xD0DD9D65878E8B72ULL, 
            0xC0D82087D6BB3F79ULL, 0x0B8B3ED68B6BCE20ULL, 0x5C19EEEA8C5E12ACULL, 0xDBE1420F9591CD4AULL, 
            0x554D4B2E5C211317ULL, 0xE1079BC265326B5DULL, 0xB3C28C9970848AA0ULL, 0xCFDD92149593D1D4ULL, 
            0x34F541E3486B7F38ULL, 0x4A2F672243A0CB09ULL, 0x41CE9AAA8EEA5AA4ULL, 0xC4C60E8E6AB6F6AAULL, 
            0xAE17FC8994C47159ULL, 0x07850910703F10C7ULL, 0x42A97DBD6647E671ULL, 0x5F30CFDBEB582725ULL, 
            0xE653291A50D329F3ULL, 0xCE5A81992D61F884ULL, 0xF995521FEA31EA2AULL, 0x5DA06E027B85DCD7ULL, 
            0x7FB9A959C55D42C9ULL, 0xEC052CCC6D6B7347ULL, 0xFFE979159523377CULL, 0x79B0C86FCCAFE1A5ULL
        },
        {
            0x7297F5DE6567CB6BULL, 0xB3391E8F5D106E82ULL, 0x11E7784A5145CA13ULL, 0x12CDAC5C10005E9BULL, 
            0xBA3A27701207D9BAULL, 0x9352E7BF4CE808E7ULL, 0x3A5FB89A5D73F2C8ULL, 0x18316580FA39E456ULL, 
            0x030212E0169E2A64ULL, 0x7CFE8D3FEB7A8FC8ULL, 0x11047CE3AA8008F6ULL, 0xD2C3768D58F46C74ULL, 
            0xB8F9A82B2071385CULL, 0x4A266DCC1D89760BULL, 0x639B76C9F70BE893ULL, 0x0A685912E2BDBEBEULL, 
            0x1402CC69D4CC1641ULL, 0x844A4A86317E9992ULL, 0x00E520D8BC1A16EFULL, 0xF4220ADC47F487E5ULL, 
            0x30BBD0C45BEE1899ULL, 0x9078B0BEDEEFD1F9ULL, 0x050258221086AD96ULL, 0x4EEB42B125309E78ULL, 
            0x2066F2A12FF9037DULL, 0x98B7379BFB80FB3CULL, 0xC13ED3F8BDEF4EF3ULL, 0x2CF8BCF6220648FCULL, 
            0xCF55256CFD0209C3ULL, 0x4A36EF303CDFCF91ULL, 0xC533EA6827F66012ULL, 0x359B443FFC315413ULL
        },
        {
            0x0FABBCD7EB69332BULL, 0x63E57EE42BC86A4CULL, 0x464AEFF9457B5488ULL, 0xDE03287B3421C3C7ULL, 
            0x871F0B95936E2C21ULL, 0x21244DC30808EAFDULL, 0x751DB7FFA96B6F6DULL, 0x631A36F49D0F6219ULL, 
            0x442232936656F1D0ULL, 0x1502D851E4AB990AULL, 0x1877E02BDF803925ULL, 0x7E8633E54EBC63E9ULL, 
            0x7A34D7E71CBFA03DULL, 0xE54DB6FBCE38BCADULL, 0x7A5B850602CC3FC1ULL, 0x916AFA1EBFF5A829ULL, 
            0x89368AD882D94CD9ULL, 0x60CD68B4974F8B6EULL, 0x1444A6021D27BA15ULL, 0xD0236455163D6956ULL, 
            0x8643E6693C553776ULL, 0x600CBDCAF5E70CBFULL, 0x7B3F348412A6D49DULL, 0x19E6DDD20024D331ULL, 
            0x968C77A4113B6801ULL, 0xA687947917D9D9C5ULL, 0x47EF6D16E2B20F35ULL, 0x7FF7A24215FF9D87ULL, 
            0x848B39CB94782F43ULL, 0x1D9D6F278F8298BDULL, 0x98870E8983CD44CCULL, 0x39909D9A8BF76596ULL
        },
        {
            0x16FE38A6999E4D87ULL, 0x089E20A126D507E5ULL, 0xC6751C7EF3701336ULL, 0x36652301DD2D2F54ULL, 
            0xD7A8742EAD270EA3ULL, 0xD9FF74B9BC09DF1FULL, 0xBFB66890D7B83566ULL, 0xE62CF4365C3CD034ULL, 
            0x88FB1654A2025081ULL, 0xA9C5C62030A5CA0CULL, 0x43FD07BFC62CF807ULL, 0x6687789EB5E65B12ULL, 
            0x36D1FE308FE2F96DULL, 0xE826F00B74FB6EA4ULL, 0x54E18B5AB0E1C402ULL, 0x1FD72B5959BFBCE5ULL, 
            0x910CA53A23D64081ULL, 0x80F008C85E756C8EULL, 0x636C00069BE8DCF1ULL, 0xF92D3438F99AC2BDULL, 
            0x6C7FC691503E6D8AULL, 0xA76771381BD36BF3ULL, 0x4E5FD905FA983971ULL, 0x9A66EAC5FBE2B538ULL, 
            0xAC970F9414AC311AULL, 0x4D7647DA61D54351ULL, 0xDB894A1867DE68A1ULL, 0xD060681137CE4B53ULL, 
            0x54313FABA661152AULL, 0xD6CD4FCDE159D765ULL, 0xD87952252860D90CULL, 0x83B2C7A7C19B4993ULL
        },
        {
            0xE87F18B9B41B9EA3ULL, 0xFBAEB7A4A6B2B9AEULL, 0x67F910C678BE9445ULL, 0xDA4E770185B97173ULL, 
            0xD1F489BD3FE099C7ULL, 0x7A620531477FAF2DULL, 0xBA74CA9A66659C6DULL, 0xCFD6F59605D84011ULL, 
            0x30E82C5B74E01FEDULL, 0xA64EDAE3EDD3D21FULL, 0x5EC616804D8F027EULL, 0x6CCFC7EDD5E7EEA9ULL, 
            0x5B5D2CBFDF8BA93EULL, 0x51C368946B04D1C3ULL, 0x4A34D5D4A1B2F212ULL, 0x241AEF66D7F8E236ULL, 
            0x3AAF08729FE4EF93ULL, 0x9D538886BC13514AULL, 0x0FE8C6D330ED63C2ULL, 0x7ADAB32AA20AA9B0ULL, 
            0x598D4F6A11FEA5B7ULL, 0xB451D7A7445BE85CULL, 0x111E33DAAEC29E0AULL, 0x69D9477BD8257A2FULL, 
            0x3FDCC919E48E89D5ULL, 0x509F6ECA82CC41BEULL, 0x4A5E750E003F0970ULL, 0xC20E6BEB8F60F77CULL, 
            0x4C827FFC9B547561ULL, 0x3875577EF2C37FAEULL, 0x1C4FDB19B8481536ULL, 0x4917529B5232FE87ULL
        },
        {
            0x1193D820C5C21F31ULL, 0xBCAAC345847FEBA5ULL, 0xE029C3857F05D398ULL, 0xB5712C73A59A517CULL, 
            0x7E7FAA0B3495FFC9ULL, 0x43B98824E536ADE6ULL, 0xE00C24251CC44BDEULL, 0x710F11796C64E3CAULL, 
            0xDA92A6D2A1C1670BULL, 0x529F2D799DE90606ULL, 0xA6271F6400AE334DULL, 0xB565DB4D2BE77EB5ULL, 
            0xB3ED146B5D9501B0ULL, 0xF1B01D1FF234E52EULL, 0x57EAF1B81AD5EEA1ULL, 0xACC9E36B6C2940C2ULL, 
            0x18DF3CF90B19A0FBULL, 0xEAF620F0CCD7C798ULL, 0x44217A464F6DD7A4ULL, 0x903160723ED1D78FULL, 
            0x60A4EAB787208EB5ULL, 0x9AFF068D966FB5D6ULL, 0x74A73AC2B62A69DCULL, 0xC0F7F8E85B86DFDEULL, 
            0x5C684F559805BCB0ULL, 0xDA7A008F097ABC19ULL, 0x8F371B00E0DCE179ULL, 0xA4652DAB240B58ABULL, 
            0x8EDC5A4A853287B1ULL, 0xD933CC4FD5E6970FULL, 0x449821249E52B35DULL, 0x9C8051672C2FCBE1ULL
        }
    },
    {
        {
            0x64F6313CA816DBFCULL, 0x848708674DF7C4F0ULL, 0x569E0FE4A6E18B52ULL, 0xF2D01BA03C429AD6ULL, 
            0xC128C6BE249D0E9AULL, 0x20C5079D44F6712AULL, 0x84C38A913A0BE6EFULL, 0x608E2186E60C9990ULL, 
            0x000B299C44CA5B2DULL, 0x5B455C036AC9CCDCULL, 0x3137631EDAF554D1ULL, 0x6902F9D388D872F3ULL, 
            0x4012FC3F41F4EDD1ULL, 0x1630CDFE45AB4DC9ULL, 0x6B407AB62C844823ULL, 0x24D6559AE67A6F58ULL, 
            0xB290E1893F59CBAEULL, 0x8E57F35FEFCFFC0EULL, 0x23698EA6C87E27D5ULL, 0x0DE6ABCFEED7A2FAULL, 
            0x4EC5675EFA5D1284ULL, 0xC61DF0BAE8B0D6DCULL, 0xFEB2B06CA7A669AAULL, 0x46BAA8DE2301AC7AULL, 
            0xEC6A915B2E7F4784ULL, 0x4184336E06F06439ULL, 0x93B89945843DD545ULL, 0xD57DE666AACC6237ULL, 
            0x727A27B7AB272B9EULL, 0x50486A28C77F2764ULL, 0x2251ED2BF83AE308ULL, 0x34C9582710F6B66EULL
        },
        {
            0x6992818BB8A5CB19ULL, 0xECEDC686F0C939FDULL, 0x756A37C94C57A2DEULL, 0x48AFD4AD9871458DULL, 
            0x171F2C5EEC95BE0EULL, 0x9D3B339875D9C95BULL, 0x475D4D111FB21874ULL, 0x615E05756DCE9FE4ULL, 
            0x969DAF31338DECABULL, 0xBD3A81B7B07713C5ULL, 0xD37F92B9F48696A8ULL, 0x8BE0492A3E50F81DULL, 
            0x630115A86128546FULL, 0xC7715DED2ACB4652ULL, 0x3C173133018B532FULL, 0xDF2FCECBB8CAEDD5ULL, 
            0x98E447C26934561FULL, 0xFF236A51A188EA13ULL, 0x36416A6DC4EB4A24ULL, 0xAA4C9C5E0C743907ULL, 
            0xAB57BB99F6BA8624ULL, 0xDB540401B32F528EULL, 0x2C563AB2D4EA0339ULL, 0xF18EAAF9A3B290F3ULL, 
            0xB03E117F90B50DF8ULL, 0x1BDC9503FD17FD97ULL, 0xB5A35AF138629E39ULL, 0xDABDD8C86558617DULL, 
            0x9DA809A1674341B0ULL, 0xF4A7ED0E4C9CC2EEULL, 0xD0ADAF75059DFF3AULL, 0x3D262C5D7B123ADDULL
        },
        {
            0xC8082DF30637D4A7ULL, 0x615B0FCF6889FAB9ULL, 0x3D54CB19B43F37E6ULL, 0x83D5CF68763C6068ULL, 
            0x5B0A3A2D25753F08ULL, 0x89CC424B907ACA47ULL, 0x0A71F590D572EB33ULL, 0xB9EC5C991B5657ACULL, 
            0xC526793565B2AA0FULL, 0xC16EE407CDE12D95ULL, 0xA722BBFD66438CE9ULL, 0x917F482E2A2D04DDULL, 
            0x125666356DE585F7ULL, 0x217E5FF3AD793763ULL, 0x21D0C6BE98A581E1ULL, 0xDE84B4AE800EAD12ULL, 
            0x9520585C645C0525ULL, 0x20A798971D2978CDULL, 0x8A177753D3480FF8ULL, 0xA9959C6162F26FF8ULL, 
            0x9D0C9FA0D03E3EE8ULL, 0xE6CF564609CDADF1ULL, 0xF7B4DD5B67F70B9AULL, 0xE672948CB4A6E094ULL, 
            0xEC45AA5845763C71ULL, 0xB8960B949D7E1F15ULL, 0xA9EF04E4C857F1A3ULL, 0xA7584E104FAEFDD2ULL, 
            0x4BE68946796B42F1ULL, 0xE8C7B45643B9A73AULL, 0x8616DCC2F0638ECAULL, 0x2ACCD9BF596F6347ULL
        },
        {
            0xC32E02FF4898C236ULL, 0xAA6A316D95B36D9CULL, 0x7D81E329C4B065C2ULL, 0x680579FB4352F2E2ULL, 
            0x743494FC880A391CULL, 0xC946F20925AF3587ULL, 0xF7488D716CDB73BAULL, 0x91F5ADAB2BF4B6F4ULL, 
            0x712213CC73CC32B5ULL, 0x2F58C67FF85F51C2ULL, 0x9890B922AA8EC7EFULL, 0xCE90BC224370EFECULL, 
            0xC595817DEED2C94AULL, 0xC218FB469D2D4534ULL, 0xEEC51B1C548D545CULL, 0x181422910AE3F5C9ULL, 
            0x519E186EBDE75D96ULL, 0x83DCCAC31A586163ULL, 0xB9E9C91286EB0530ULL, 0x835886C5F5A8CA43ULL, 
            0x7CCDC0B88DA65E5BULL, 0x6F337BDBE9AD7C4BULL, 0x91F77D9C4C392231ULL, 0x64901C3E92710665ULL, 
            0xA5D067D1462C3897ULL, 0xE631AE9D57E7F532ULL, 0x43CACA288C0344C9ULL, 0xD3AB4DB01C767F03ULL, 
            0x1A1ED0445FE6A856ULL, 0xE0326F997FB4D735ULL, 0x4475B013F3E523AAULL, 0xE9FA7FE0DE4780A6ULL
        },
        {
            0xDFBA405A47F8D9C0ULL, 0x18B01C9E5EB741AEULL, 0xB8AD9830DFA7683FULL, 0x4B602A5BE6D2981DULL, 
            0x200A804315CFB520ULL, 0x241C5C47E03805F6ULL, 0x49E59519A0BCE56DULL, 0x17D107EEF975B199ULL, 
            0xCA70E475237ADA0CULL, 0x6E075898786CAA1BULL, 0xF004FF53C710A8D2ULL, 0x4AF3261D422689A3ULL, 
            0xF69B361F240D5D08ULL, 0xAFB18940FFB1057DULL, 0x792D393756492FD1ULL, 0x7FC2A43D1944A318ULL, 
            0x4ECCD536E5D69B82ULL, 0xBC640672298E474CULL, 0x77CFCC8499148BFBULL, 0x8BB08AF154DA0327ULL, 
            0xD9DE4FC57A295060ULL, 0x7699626918322A49ULL, 0xD98B1B899CF3DD0DULL, 0x3F2B1B95CC48AC5AULL, 
            0xDDCDB6AB64A4541CULL, 0x79A9B9582CBA1EA9ULL, 0xE2682C8C76042994ULL, 0xC51CA5C2877B3763ULL, 
            0xDEA75EEB215F50D7ULL, 0x65BA2EB8AB89167CULL, 0x5355A708E85E85CAULL, 0xABE0AD20C262AA91ULL
        },
        {
            0x0B758A4BF195723BULL, 0x2BF1E399CEFA395BULL, 0xCB2868943C12656CULL, 0x61026D8C0FE169A8ULL, 
            0xF18FFDA29CFAD54BULL, 0x7925ECC2BA58D0BEULL, 0xBCF2F29FB0451AA7ULL, 0xFE317E830C63583EULL, 
            0x31981EC5E1F6BAF4ULL, 0x4E5F63B388E04DA7ULL, 0x8941E4CA0157FB26ULL, 0x04A2833457884166ULL, 
            0xBE382040487C124CULL, 0x3E6DBD06661C20C6ULL, 0x5A83F27DACA5D681ULL, 0x28574250EAD9D5EAULL, 
            0x7ECFF424EF0BEAFFULL, 0xDBFF9548AFD0E54AULL, 0x81B75B156EAF99A5ULL, 0x3A8B348AA777A024ULL, 
            0x78222C3D036DE495ULL, 0x9A90071546D824F4ULL, 0xA37C90E6F607F385ULL, 0x734ACFF287BE88DEULL, 
            0xA54711BA67DAD3A6ULL, 0x2D1AABF6E6BA9A50ULL, 0x9BE84593D7F9DA0AULL, 0x937178929331B2A2ULL, 
            0x477D1F43C36693AAULL, 0xEEE109DC3D2665FAULL, 0x1C681E3D03B875F3ULL, 0xCA62D218194D9744ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseCConstants = {
    0x721D158FAF5D06AFULL,
    0x4FD1CD792791B467ULL,
    0x21F6C8AB1C081C91ULL,
    0x721D158FAF5D06AFULL,
    0x4FD1CD792791B467ULL,
    0x21F6C8AB1C081C91ULL,
    0x4156336C82F68A37ULL,
    0x00D84F15D9A98C6BULL,
    0x38,
    0x8B,
    0xF4,
    0xC9,
    0x08,
    0x78,
    0x64,
    0x79
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseDSalts = {
    {
        {
            0x9EC3B327658BD84CULL, 0x646FA915C86CF47BULL, 0xB4E8E5E43AE29684ULL, 0x8178F517F3B2074FULL, 
            0x1BCC1C0E1718CFF4ULL, 0x82DC40C7A58DA797ULL, 0x2C414F2065B29D6EULL, 0x8206CB5AA3D30092ULL, 
            0x6425AAA501E048B4ULL, 0xE25C716FB6F425E1ULL, 0x6B0AC72D27DA6160ULL, 0x9CB7C427F9FADA02ULL, 
            0x5406431292394D7EULL, 0xDCD5FE2BFCB80088ULL, 0xEB182FE825F9095CULL, 0xD76F49561811F06FULL, 
            0xF8CCA0E5D31085D8ULL, 0x41032B95B084A1DAULL, 0x42FF7135FDD9499FULL, 0x6F74634ECCDCBC97ULL, 
            0xACD23F69F4DF04E3ULL, 0x1A40DFBC1CAAC7DCULL, 0xFD75369D6B2A9FF1ULL, 0x25A97F15187B7383ULL, 
            0xAAC01CD8AC037259ULL, 0xFA333CCC2DF4C571ULL, 0x965FF7460DD6D0F2ULL, 0x8227FFB605DD3472ULL, 
            0xACC9BBD8FF7434EEULL, 0x0A4904DF3E99D52BULL, 0x24AECAA4D285DF9CULL, 0x0BA235992DCD0EBDULL
        },
        {
            0x96B2ABEDD7B3AD8EULL, 0x59C914260A4CA1F7ULL, 0xD7EE2C862364F31AULL, 0x13FB032CD31FF93BULL, 
            0xC56BD7EB71665EE3ULL, 0x1A818DC82FF00D32ULL, 0x0081965A83B46AB0ULL, 0xAC0D2C8CBFC3550EULL, 
            0xFA7A20C44362FB49ULL, 0x88A62C18DCD1005DULL, 0x2B85D48D930C284BULL, 0x261C5784D63F5046ULL, 
            0xBA27D2CAD5933EE1ULL, 0xE971E39255B5BA0CULL, 0xE767C18DEDC94177ULL, 0x97E4E36FF66CCA45ULL, 
            0x2EA1123321CF6532ULL, 0xB7D4BFC6789B3A13ULL, 0xC92C9BA826247F4EULL, 0xB3163827DB92AA18ULL, 
            0x3724984F9DD53E3EULL, 0x7BBA00CF575DFED8ULL, 0x12638D9C326BCD5DULL, 0x3D8096B8B8C1EB65ULL, 
            0x3E2E774942C9E6CCULL, 0x12980F9FAC1F81E2ULL, 0x04844813F3B3B4D1ULL, 0x210FD8761DD843D0ULL, 
            0xF868049B55BD3C3EULL, 0x738E261CCE489F1AULL, 0x98606CECAA2791C4ULL, 0x58DDDC7CCD36B2CBULL
        },
        {
            0x19879D7586342B18ULL, 0xC5D5FCCD3466319DULL, 0xEB255D4B3F262B5AULL, 0x1F554CB6BA35A90EULL, 
            0x991D2C34A92ECAA4ULL, 0xC63DBBD433BF305DULL, 0x147B4FE8325E1476ULL, 0x22CC9B056CFDCF7BULL, 
            0xD8E41A1DD03C275BULL, 0x960875BD9A72ECC8ULL, 0x8DB0EEE92B9AD680ULL, 0xD615391F3FBE3306ULL, 
            0x522A6B798FE93523ULL, 0x637ED70875FBE7E4ULL, 0xFD2C5C660010F1FAULL, 0x00F173DF10B2D388ULL, 
            0x1786F9CE3B391BF4ULL, 0xF140E17A3554023AULL, 0x186AD9115906B9D8ULL, 0x7530527D3B671AB1ULL, 
            0xAC99E6A6D6094748ULL, 0x8E54B26D2B993A2CULL, 0x056A01DC84FF452CULL, 0x2080C4E3409D2D19ULL, 
            0x7B591537964F97A6ULL, 0x731E7C7FC21E8CA1ULL, 0x62BBAEEC4987810AULL, 0xBFB0F651309E34A5ULL, 
            0x2F2FF1F419366E80ULL, 0xDD94FF15C75E5614ULL, 0x9D3FAF77354CC358ULL, 0x25A8C2140BF3FF74ULL
        },
        {
            0xE08F8E1C8E4C5FBCULL, 0x77EE2E122FAA774EULL, 0x234EAA72BED59C07ULL, 0x18535423C1F4B6DBULL, 
            0x00E3F1DBBE8AE53CULL, 0x30B35182FC837C65ULL, 0xF5D44058CEA7612BULL, 0x16BEB302F3BFD84DULL, 
            0xA797F94BF8462369ULL, 0x0D77AADCEF7C5253ULL, 0xB08FC592DF2C77D6ULL, 0x5E0EF1187F4C846CULL, 
            0xACDF9D47FD901D0CULL, 0xB458A272304E7C1EULL, 0x456B9351AD6506D6ULL, 0x671C351FFD2617B0ULL, 
            0x311CD8A521A202C8ULL, 0x99B56B741F2A3091ULL, 0x9E1961C8C6BE7941ULL, 0xEFD1DD1DB1C30B7AULL, 
            0x463B8F49119E92A5ULL, 0x0C29741576144B68ULL, 0x96BD860294892AB2ULL, 0xBB3957B83F22390DULL, 
            0x1C34B6F26CCC7936ULL, 0x4C7F0E0A74A9883AULL, 0x640F1A639CB41CA5ULL, 0x6ADDBCD370FFBBB2ULL, 
            0xBA7C7DC85EAE73BBULL, 0x0CC3988C0A5CA386ULL, 0x291E625980ACD693ULL, 0x75E2D984FD631815ULL
        },
        {
            0xD59E785B2791514EULL, 0x43F3B9C82FFFE750ULL, 0xC7DCE7FEBF59AC31ULL, 0x26BAE0673FF696E8ULL, 
            0x824560BD25CB6EE3ULL, 0x63334ACAD1BD030FULL, 0x2EE3F3045CCFF526ULL, 0x2A5AF5A7F6D11889ULL, 
            0x8A198CFEF36DFF87ULL, 0x4A2254E5E9EF18B1ULL, 0xDDCAF4D79E984482ULL, 0x3A7BAFAAF257345DULL, 
            0xB6B7DE8BA031A3DCULL, 0x7C108106EC3E307BULL, 0x9CC500D181395BC0ULL, 0x0723ECA2DE080BEBULL, 
            0xBF068E617E24541CULL, 0x90D6C5843B899215ULL, 0xFF9BC09BB28A2EBAULL, 0x07526D24C51BBB07ULL, 
            0x088CF37625193B3AULL, 0xDABB6CF11F522A10ULL, 0x3C2BE6830E8A12B6ULL, 0xEE63129ED0998D6DULL, 
            0x2CBCE8CEC4CC8875ULL, 0x69C29E0EADB9330CULL, 0x497113973F2C631EULL, 0x1D8434D1C7A87671ULL, 
            0x73CC51FBEE841D02ULL, 0x7908BE80A8C154A4ULL, 0x8CAC1D47E5B2D1F6ULL, 0x1BD955FA4E5DB0E2ULL
        },
        {
            0x7A98D91D4E6290FBULL, 0x79DAF3D108F67D57ULL, 0xCD2D92488AEABD1DULL, 0x3B28FA4E13978077ULL, 
            0x8205A0FC8C18C74BULL, 0x016605A3DBB5EB21ULL, 0xEE3D7F83A0279BDBULL, 0x4CE2B52E7AFDCCC5ULL, 
            0x32B46195D199C551ULL, 0xDD58721778A0953FULL, 0x10DE0B0F7F841C7DULL, 0xB1F4C5CC54091A33ULL, 
            0xB939E8AE307EFEC1ULL, 0x209FA4078E019126ULL, 0x8716287CD0376CE9ULL, 0x3D827908BBB32B96ULL, 
            0x81C15D977583EBD0ULL, 0xF4F972275391B326ULL, 0x5133B03BF0215509ULL, 0x4D012A69481DC895ULL, 
            0x64AC25E327C2F664ULL, 0x66D9E2C1F83214D9ULL, 0xC208F6401C32F81AULL, 0x3F44746849A15F30ULL, 
            0x1077D06DC6B628DBULL, 0x6F27E33C1B035780ULL, 0xFBB025C95F1DB73CULL, 0x1B1DDB50D5B29F48ULL, 
            0x6176E91A0593A9B6ULL, 0x89C731789AB9463FULL, 0x8CB9E4D0DAE585E9ULL, 0x4276F82DB935E02AULL
        }
    },
    {
        {
            0x7141A95CF7EF5D5EULL, 0xDDAA9EF5885836CDULL, 0xCF1D392EA150DA34ULL, 0xD8F6509557E88EECULL, 
            0x865461DB1D53EB0AULL, 0xE42E7C05815BE8C7ULL, 0x35E0179EF5BF793EULL, 0xB1859342F9F55C85ULL, 
            0xAB8982C866B38E7FULL, 0xFA4E5DA7FF5F942EULL, 0x2480465D55D22F82ULL, 0x9050A350F2CCE183ULL, 
            0x467E2ADEFE43A8B7ULL, 0x2B49EB17FD755FE9ULL, 0xBD119E8FBA458B0DULL, 0x0D0F3A96E954ABAAULL, 
            0xC835C9C941AD02EEULL, 0x02764E1EAA1CF4CDULL, 0xA73E5F4682A5566AULL, 0xF497C9809BA530F1ULL, 
            0x909701665AF9DFDFULL, 0x2FA802222D600F52ULL, 0x1D5634895A1B0C49ULL, 0x4ED11C01D6D048F6ULL, 
            0xF8D33F536C9A4665ULL, 0x738606F459D0EC5BULL, 0x08D99B85DB3BE70CULL, 0x91C450E0486F8064ULL, 
            0xACD75D360C8C941CULL, 0x68B399DDD12DA183ULL, 0x248CC71B7B35CCCAULL, 0xD64968A6483D707DULL
        },
        {
            0x5E4450B138D0A6ABULL, 0xBB97DB31CCA2D8C7ULL, 0x29F93EF05AAD6CD0ULL, 0x69CC554FBD261D55ULL, 
            0x7936043E93D6E6C2ULL, 0xE11CAADBA544A2EDULL, 0x4748BD7CE7C1E67EULL, 0xC855FEC1FD843648ULL, 
            0x502D7031C43BE2C3ULL, 0xFC85D61365B217FFULL, 0x00FAED547FD4892DULL, 0x5EAAE4033F438FF7ULL, 
            0xED012191D77ADBE8ULL, 0x95FE91222D948F46ULL, 0x8E5D26223AC1B241ULL, 0x75566D43A7E9D2F9ULL, 
            0xB3ABD64FD852595EULL, 0x284376E849BB327FULL, 0xDF83490374D34E4CULL, 0xB04CF9785E0E7B88ULL, 
            0xD11DE533BCBED9FCULL, 0x8614848CD24A3972ULL, 0x941C87E93A96526FULL, 0xE35967DE4A575553ULL, 
            0x0AD87EC4F296DF8CULL, 0xE3FCCDC56DB3585CULL, 0x55361BFB805CB7B6ULL, 0x33E8E2AEEC1EC6C1ULL, 
            0x164C5E70181AF16FULL, 0x5137E5D61386D392ULL, 0xD8E1B09AA6025DB7ULL, 0x8673AE90B79A0849ULL
        },
        {
            0x4992AD32079D4508ULL, 0x25523826B79A5271ULL, 0xD50455BDA05EEFC8ULL, 0xE6168267177A701EULL, 
            0xA7700A38854E3F3EULL, 0x71DE2205B1E3166BULL, 0x559A979DCCF7ABC3ULL, 0xF55F0F70C1FF3164ULL, 
            0xD3F7D9B4B46581F5ULL, 0xB9577F6642847496ULL, 0xAEA9E5517FC2C40DULL, 0xE405AAFDA89B5B7FULL, 
            0x6893D113BDA5DBBAULL, 0x4135BA51DF008076ULL, 0x9374E936205A966EULL, 0x8D5938F78806DCE7ULL, 
            0x7426F2787D345751ULL, 0x8C8EFE11FA9F3F85ULL, 0x1ADF7FFB1F820BE6ULL, 0xE1E6DCC05D849BE7ULL, 
            0xB31F4C8F59FE4599ULL, 0x61470C18D275950EULL, 0x7B6038A17CEC9620ULL, 0xF3994EDE8A6F2DDAULL, 
            0x88328EC316A40A33ULL, 0x42A275DF3F355B88ULL, 0x6D4D825C2092640DULL, 0x8AF28BD989DEC146ULL, 
            0x76385474FCF5CFBEULL, 0xCD7315D1BF338D7CULL, 0xF7041E2797FB69E7ULL, 0xD55CF6E9754091FCULL
        },
        {
            0xD6FC49A9AE898F1EULL, 0x0AEEFE45437A40A7ULL, 0x5A1DE3281A2C3502ULL, 0x6ED0A908383C7C0BULL, 
            0x9B59062B1C1514A6ULL, 0x99319AECC56356B8ULL, 0xCDC7EF916B03638CULL, 0x9CDB51FCF262CB11ULL, 
            0x8AAB7F70B5CE74ECULL, 0x00BC422492345E3AULL, 0x167C72D6FA624BC2ULL, 0xA1E1ED236B3704AAULL, 
            0xDF06D9D34CFB74EAULL, 0x17663E08FF76A7EBULL, 0xFF0449F50B69FA16ULL, 0x8270BE8C67522DCAULL, 
            0xE488DE7EFD14E1BBULL, 0x35CA7606170BDFF4ULL, 0x7C20C70492F18CAAULL, 0xC70551010DA17604ULL, 
            0x9F58FE71F97D804EULL, 0x74D0CF7B64F1A45EULL, 0x0285870FF5A9040CULL, 0x69E7647647B891A8ULL, 
            0x9A2D973AD07B4990ULL, 0x26A24C14D9874B4CULL, 0x10E7637C5CE7DAB1ULL, 0x14714CD3E160F756ULL, 
            0xF9CBB5E5E9B19A95ULL, 0x1253E43F5C4DC92AULL, 0x0D1EF500BFDB9373ULL, 0x42148FC94556CFC7ULL
        },
        {
            0x7C6D2D3395236AB9ULL, 0x7213CE3CB6E72E5EULL, 0xF83CD0B22228A5E5ULL, 0x6519CE43A23B0874ULL, 
            0x37583E3A2349D32DULL, 0x5087AE44523255FDULL, 0x337EEC5409DF75F2ULL, 0xCA5BA28FDFE74816ULL, 
            0x1FCD249731B7E012ULL, 0xC810228EE0B46DD0ULL, 0x7991BF847078FEA3ULL, 0x483DFA069ADEF59DULL, 
            0x051A60EF2EFA6CCDULL, 0x52A3653C75896B1DULL, 0x1D33AACFF0C39966ULL, 0x1BE8A895C222C75EULL, 
            0xF977665257495CA8ULL, 0x989980AA872AC488ULL, 0x30C6A79E1474F0A2ULL, 0x544012FEA24380B1ULL, 
            0x6BD3F69A1941D58DULL, 0x90387172BD6BCA6AULL, 0x89BF56E354B174A2ULL, 0x08EF41EE130569D0ULL, 
            0x215EBB6751CE2B57ULL, 0x1F4796E670331C22ULL, 0xC33D53414158DAE6ULL, 0x4807901F69AA77EFULL, 
            0xC33684DB0720404AULL, 0xBA2CC753F2AEBDE2ULL, 0x703A39467CD67D01ULL, 0x6B4FDD3057A36E72ULL
        },
        {
            0x4E9612BF2B32248FULL, 0x85EBBCAB916A3915ULL, 0x522454AAD4E2D5AEULL, 0xD2DC16ADC2937772ULL, 
            0x00C3392380DDB109ULL, 0x25E2205A69FE3152ULL, 0x31EB10A50DBF693CULL, 0x8616DBE0FD028E5CULL, 
            0x3FFF54A3E84D59EDULL, 0xD6F3E6BA9FE16A61ULL, 0xFA049F07197DC1CAULL, 0xCEE35EF9B8E652E4ULL, 
            0xD11F97A3F19624CEULL, 0x0038CD7625225B88ULL, 0x72D823AEFA82725CULL, 0x050E866475861AA8ULL, 
            0x78D1E060EE259E3AULL, 0xF9326C703221A431ULL, 0x70B429E3B8904D90ULL, 0x0BF43CA0432220F8ULL, 
            0x7043C9368159ECBFULL, 0x324B0F387D3C1F52ULL, 0xD7F98A132EDF2993ULL, 0x9101604E9FBD05CDULL, 
            0x80CBAC0F13AF56BFULL, 0xFE31F4AE4324110CULL, 0x118003CA14FF4409ULL, 0xAC8DBC06FC8545A9ULL, 
            0x8E66BB7F55C3E2EDULL, 0x7D65BFDBFF334AECULL, 0x297F46F2D650D830ULL, 0x1AFD8757CFE6F2C0ULL
        }
    },
    {
        {
            0x944C211C40BC7521ULL, 0x93A75A2E52B6366BULL, 0x545264E72D04895DULL, 0xEC7BB3EB47F4A617ULL, 
            0xF9FE8858CD87B6D8ULL, 0x1812CDCBBED3C887ULL, 0x9F119DDD44456B53ULL, 0xA55803BFEE98F6C6ULL, 
            0xBD90D28887D19690ULL, 0xB68209368543590EULL, 0x9A83F74A11F220B5ULL, 0x783534C6F1BB7D7CULL, 
            0x81880C0394714133ULL, 0x58A6DE2DA34410DEULL, 0x25C5132ED18560AAULL, 0x67BB8AF55C2F0E28ULL, 
            0xD564B1BE6800F806ULL, 0x3E2C6FF690C6638FULL, 0xD69DFA9DBAD70F05ULL, 0x778630B6717D417FULL, 
            0xA42AA0CE515C5309ULL, 0x96076F09C7415F53ULL, 0x678C0DAFF45898A4ULL, 0x39D00B404D78E8AAULL, 
            0x01837FA1F49E43F0ULL, 0x6A5EA028299D8722ULL, 0xA2727C9137579F10ULL, 0xE25FC62F9BE0D5D0ULL, 
            0x8749CDB95FC0F9ACULL, 0x150330EA1FDD91A5ULL, 0xF96D7426E80497C9ULL, 0xBC7AFEF16D70CC3EULL
        },
        {
            0x64AD1029C8C59A52ULL, 0x5BDFBE84EB152EEEULL, 0xFDA64B222CB7BC0EULL, 0x585423C349694313ULL, 
            0x6DE720A986525580ULL, 0x9866B968F766580DULL, 0x97B2C42A87F369ADULL, 0x0F8EFF95C3EE2E07ULL, 
            0x50004B2F9BC12599ULL, 0x9AF8C4A935C86CBAULL, 0x8A1F798AB5882F0BULL, 0xA646836A54E9E696ULL, 
            0x51EFFA0E0A401F8DULL, 0x78027E228058C875ULL, 0xB706E24E6E7900D5ULL, 0xA0C8E7AB691649F4ULL, 
            0xAB27AB6265203E8CULL, 0x2D3F336AADB1222FULL, 0x41A80DE48B5B6D5BULL, 0xD1A233A038C7AFFEULL, 
            0x69CF9F0024BC4803ULL, 0x14AFE108EE27F118ULL, 0x89006116AA7A9F7DULL, 0x8BF187B92B10DD32ULL, 
            0x830FD13A7AC730F9ULL, 0x2CE95904F2808508ULL, 0x86BA94824EC1F388ULL, 0x715F33CF317650CCULL, 
            0xA0C8AC5C7651256EULL, 0xF56AC04466E41BBBULL, 0xA8C75A1CC0334B9DULL, 0xB039C9D5D7CA8B42ULL
        },
        {
            0x5E52471BD6BFB19EULL, 0x61A04121CFF16EDDULL, 0x46882F794DF66E11ULL, 0x2614DB6EAF644797ULL, 
            0xF51739FD61B42210ULL, 0x081FCE3C650C18F1ULL, 0xA24BFCB10B1392A5ULL, 0x2C7679E16C5B4A00ULL, 
            0xB915A48B34311956ULL, 0xAF854629344B5939ULL, 0x5E4CABBAA24EC1ACULL, 0x2C9B167DE3FCB921ULL, 
            0x2123C5E18FC8F6B1ULL, 0x59D6E8AF17024006ULL, 0x9D42358657358DCEULL, 0x1E24F84D37503AC5ULL, 
            0x4E97BA8279C59501ULL, 0xE6B31EA03DAC80B1ULL, 0x7B11217719B659CBULL, 0x026C337880AFB8A8ULL, 
            0x62272965F3D0853CULL, 0x7F50703022A9B9E1ULL, 0x6653FA1ADE887379ULL, 0x5F5E26AE26659005ULL, 
            0x26FC23F4395582EFULL, 0x242CCDD17542B5D3ULL, 0x9BBCB4DE9A33ED1CULL, 0x1CAE769881C46C0FULL, 
            0x790ABA18D2577D5CULL, 0x550AD0335FBFFEA7ULL, 0x77F92BFAD0618A9FULL, 0x52DA5AD35388FA06ULL
        },
        {
            0x81376E1F93CECCA5ULL, 0x85E16005CB190B51ULL, 0x20C826A5941B4B58ULL, 0x1B749DAE5DCCC75EULL, 
            0xF205DC0F9B4A64B0ULL, 0x8F0607C0EFB9DAB5ULL, 0x51A1E4E581C10112ULL, 0xA1A04EF9D2533EABULL, 
            0x07EC342FA6CDC0E7ULL, 0x10BA55D7630508B9ULL, 0xFF6DD8877709D90CULL, 0x2B4747BB3F48D58DULL, 
            0x23EE8A206B4D0806ULL, 0x0AEC28BA2901D90DULL, 0xEECBFC778BB56070ULL, 0xE6ADA67AE93F4C0EULL, 
            0x1CE0237A6467F922ULL, 0xE40D1CC649DE76F8ULL, 0x3B7F5161EDD60C44ULL, 0xD885927D2FC102E4ULL, 
            0x8C8915E761171948ULL, 0x335411523CE0F81FULL, 0x64735FC4C72BB48AULL, 0x48156D66D829627CULL, 
            0x8048871062996A53ULL, 0x1C26A92D1EF4041EULL, 0x906644A83AE37CACULL, 0x759BE5E951B343C0ULL, 
            0xF4A36E3B4D0901FAULL, 0xDD5A97DD6B6A2794ULL, 0x3C5C8D7D6E18321BULL, 0xAE8DEF56E4AE6A64ULL
        },
        {
            0xFB9496034EEBB43CULL, 0x2937F2503C78389BULL, 0xB9B4A856A6451BEFULL, 0xBB0347D8E07DA7EBULL, 
            0x10C6C768D6E2B407ULL, 0x1D4DFF1295996C11ULL, 0x5C799839314291D4ULL, 0x63E27ACED70524A6ULL, 
            0xA05B71B259EDE02AULL, 0xC409935C52D84EA0ULL, 0xCE2FF4A521EB9F10ULL, 0x3EA1BEDC28AAEED2ULL, 
            0xC2AB745ED9092195ULL, 0x0DE10F35FA47F109ULL, 0x90E03E5486089879ULL, 0x3A3FB7849509745AULL, 
            0xCAE525945A515FD4ULL, 0xD4FD4AF5A4C282D0ULL, 0x6797420F68051FB5ULL, 0xE055BCEEFCE2C053ULL, 
            0x651CFC3395067ADBULL, 0xBDA3484AA7C20AD7ULL, 0xD2305CFF83F62B55ULL, 0xC57D0491EF8A1860ULL, 
            0xE1AFDFFDFEAA1404ULL, 0x45309CAAC0A3C8F3ULL, 0xA092F2CDE3FD7832ULL, 0x56F1D17B707D6D81ULL, 
            0x502D2CD567EC3EF1ULL, 0xE4B0223D6F3AA1DEULL, 0x66DA3EA3D5E1D173ULL, 0x1FB5118E02D73C0CULL
        },
        {
            0xC05CC187C9E28B40ULL, 0x8ED03E7057BD9578ULL, 0x2F6A8E12ECCF47D7ULL, 0xB194D9624E6924DBULL, 
            0x68C543CAA1CBB694ULL, 0xAEB645FD1BD8E189ULL, 0xCAE46701E2160A89ULL, 0x30199504920C79A3ULL, 
            0x56B700FB38A72F89ULL, 0x9D5C484F3673CB72ULL, 0x2DEF5AF27A138647ULL, 0x59E267F70FBFB8E6ULL, 
            0xE00FE7FCC0865A7BULL, 0xAFD97C7E9F558130ULL, 0xC72543D81DAEFFDEULL, 0x5A3F54A487469233ULL, 
            0xF255DDE7C07A70ABULL, 0x41D0BDBC581A7C40ULL, 0x468A015A4B79FB24ULL, 0x33DFADA12B399310ULL, 
            0xC4AFB3DC66FB6980ULL, 0x56FBFE05D74B0F5BULL, 0x715F12AB9DAACFBFULL, 0x54129A4A3C059412ULL, 
            0x0AF1C6C9AA37E57EULL, 0xDCC8E40A2D74653DULL, 0xBB76DB7DE0451833ULL, 0xB6FD6E5899E7A853ULL, 
            0x82637AC9F849A639ULL, 0x3A9B1A2CAE170719ULL, 0x161ED2E9AA641542ULL, 0x43DCD7F91132B349ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseDConstants = {
    0xE93C07ED72F67AC0ULL,
    0x492BA4998F31CD6AULL,
    0xFCC4D0978F87DE76ULL,
    0xE93C07ED72F67AC0ULL,
    0x492BA4998F31CD6AULL,
    0xFCC4D0978F87DE76ULL,
    0x02FD6E62A4F44423ULL,
    0x989FF2B484867261ULL,
    0x1C,
    0xE3,
    0xEA,
    0x0A,
    0xF6,
    0xA1,
    0x2E,
    0x70
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseESalts = {
    {
        {
            0xD6A98133249C2C41ULL, 0x1A55EC2AF027DBEDULL, 0x817AB98B578EEF92ULL, 0x68D96CB691D0345CULL, 
            0xC1F4196CBED4A839ULL, 0x947545FAC7E58C0FULL, 0x3EFFC5ABAFD0C79FULL, 0x245900933F506BEFULL, 
            0x396D961937A8D443ULL, 0xF2D3D7010367CC42ULL, 0x861826CBD6F938ABULL, 0xBF9B2AF9836FD4A5ULL, 
            0x5249E74CEA38B402ULL, 0xDE09C0B54102FE3CULL, 0x17660B20B9DEF1B0ULL, 0x23BBA27DC6117BB8ULL, 
            0x9F00B004441A94D3ULL, 0x9A02CFAC2B367430ULL, 0xECCBA2AB69940C06ULL, 0xD47944F9F50404C8ULL, 
            0xF1167880F6462CDAULL, 0x0E2553048658A67EULL, 0x47BD76866CCCECF4ULL, 0xD64EA2840479116EULL, 
            0x358FDFEFFF077BACULL, 0xC09B36210E09E2E0ULL, 0xA1CC92C562C1B1CEULL, 0xEE528C8BC07ACAB4ULL, 
            0xA0F9EF5FF5E4D041ULL, 0x824C4A173D4FC5C6ULL, 0xF2DDEC349C4DB233ULL, 0x7E940006F62A2929ULL
        },
        {
            0xC04024CC257CC4AAULL, 0x4E86571B9F7A6F98ULL, 0x2E441ADDE708B01AULL, 0x7720519CE8A56A5AULL, 
            0xF20EFA6C9C4BEE1FULL, 0x0117FEB4C310CA7BULL, 0x0E174D1BDEEBEB82ULL, 0x03DC968BF33D9C2DULL, 
            0xD874670BFF4709FAULL, 0x251F24459FB9776AULL, 0x97977774F846CE07ULL, 0x0B9C5E01FE2288A1ULL, 
            0x959153AA6032ECB6ULL, 0x9F9D7105DDBE551FULL, 0x220244E42841BC04ULL, 0x0AA78F60E83917AFULL, 
            0x0846B665EFDCE562ULL, 0x5CD9C2237C22AECBULL, 0x4C36A3BF540796DEULL, 0xE2169333A6DC4D03ULL, 
            0x3912178D6B9BFE09ULL, 0x8BE80060B29F198AULL, 0x33153731A5EAFD1DULL, 0x4A8E0612AD2EC749ULL, 
            0xDEAFE7BBF4401060ULL, 0xE6CCDA5BC0864C13ULL, 0xC7EC43C2B0FE05CDULL, 0xE1DD1BA565C61D9DULL, 
            0x09A5E01B4819666EULL, 0xD8137BAE0682A6B8ULL, 0xA405656DC29CF529ULL, 0x0F010ADEA822EE7FULL
        },
        {
            0xC3388581009B5737ULL, 0xD4C841A2789A7068ULL, 0x82A6486C0A5ED836ULL, 0x9605EC76716AAC67ULL, 
            0xEAFB2116F1C15390ULL, 0x8D2EF5CEE44379F0ULL, 0x1AAFB6A895ED7A01ULL, 0xF4A510F3A290CCDAULL, 
            0xE80C5A8674A67AC8ULL, 0x3E5374E854DCD69CULL, 0xC6C1891A7062DB87ULL, 0xB5761C52E714EC73ULL, 
            0x8A6430597D5327D4ULL, 0x642B5578FF0E1C7BULL, 0xCAA2BFCC94838F3FULL, 0xA7D8B8CC483FA8CEULL, 
            0x63CF173BFE0BCB75ULL, 0x8AC0105492A3D5AEULL, 0x27825FB50DFFE35DULL, 0xE34EBB9FE18D9F06ULL, 
            0xE4D91FAC3E3E164AULL, 0xA64E4990454E661CULL, 0xF9E0D3568F751619ULL, 0x8D817C2103EDC986ULL, 
            0x9208BB41C5AE01F0ULL, 0x649547CB9F4FFDF6ULL, 0x60B8F9D8CB004F1DULL, 0xD47EBB488EAD2FF3ULL, 
            0xAB0C8A6F060BC90DULL, 0x0E08F2F2EE3FB27EULL, 0x26552C9CA1650B61ULL, 0xB438D982A636AAA2ULL
        },
        {
            0x217D476E2E5D854EULL, 0x3F8FA76AD3542984ULL, 0x78E1BD1AD79404DDULL, 0xCDB8414694A5B3F1ULL, 
            0x1232D8F2C7021FECULL, 0xB732EAAE39CF4391ULL, 0x7E3F7EB68075BFFFULL, 0x6668A3873B5A081CULL, 
            0xEF7085E637F13E0CULL, 0x9328782C3EBA13E0ULL, 0x388B428E5501D98AULL, 0xD2888D2A216E964CULL, 
            0x06F1A3E52029D2A9ULL, 0x05A498DB6EF7258EULL, 0x4EE6591FDEDBC9AFULL, 0xD7C1BBF6CF22FAA5ULL, 
            0x96026C331A15BF3FULL, 0x12C3CAFFF58F3A4DULL, 0x99E891A177D3A46CULL, 0xC5EAB01DDD5D3A9AULL, 
            0x2CF7B2487D01BEFCULL, 0xA8D468AB23CDBAF8ULL, 0x7A12FAD08ED322ACULL, 0x401F1310743F0A69ULL, 
            0x31A54C974AA385A2ULL, 0x33A5F1603CA10D44ULL, 0xF8E7A6C7D12A92C1ULL, 0x9B6D6F44052AFD40ULL, 
            0x8A33254ABDB893D4ULL, 0xA4CF23ED4CA7DC7EULL, 0xE9974ACA870E76FBULL, 0xF19CF0B0FF931663ULL
        },
        {
            0x8DA882E277EA54E2ULL, 0x538327885CA38930ULL, 0xBEBF64706845187CULL, 0x8AEEA38F371A25DCULL, 
            0xFFFB5733D6FB5417ULL, 0x2C4F3B47E8B80C17ULL, 0x8B05518337651DDFULL, 0x4BC7D29CEF65F6C8ULL, 
            0xED3975A58824000FULL, 0x470B358BF688C1E3ULL, 0xDF34B52A9675852EULL, 0xF14C4FB5EA25DFC5ULL, 
            0xBBA58B067F8DEDD3ULL, 0x070268549CBFC8B7ULL, 0xDE0A543AF89C5EA7ULL, 0xCB917C9EDADCC7A7ULL, 
            0xAF1CF18F2D5F3B04ULL, 0x474351D511346EC2ULL, 0x09F5CCB22291F4DBULL, 0x69905C0EB0801ACCULL, 
            0x678646D6A719512EULL, 0xB1A0C3061DB6D954ULL, 0x399026D5FC3DEF03ULL, 0x889A41EDB1B31CD8ULL, 
            0x7C9050CB99F67A5BULL, 0x0165CA5629652571ULL, 0xFD1390045595B7B3ULL, 0xE8C6F6C8CC1A1592ULL, 
            0xB118A5E42540D5C9ULL, 0x6C92BDE28DD51FA0ULL, 0xD59CA09B3A44320EULL, 0xDAD67151D9A80C78ULL
        },
        {
            0xAD445846DB6EDFDBULL, 0xBAEAA3B747EF8CB1ULL, 0xBE6D1FF8F1EA156BULL, 0x714B9F4FF3F2D6CAULL, 
            0x8C9A3ED624C5B6A3ULL, 0x378990D796EA642AULL, 0xC5238AA2CF1A2F68ULL, 0x11D4916B42FE6791ULL, 
            0x8F57B2B9C81A6CB6ULL, 0x8B51F65E3767923EULL, 0x73CDCE5576E549D4ULL, 0x542B8393FF5FD5DBULL, 
            0xFD7C50D136D89477ULL, 0x48CABDDFCDBE1EFEULL, 0x7524C0EF0660E49DULL, 0x9B04B2DFD111EAC1ULL, 
            0xDCE895EF802DD8A1ULL, 0x5892A9E95B964395ULL, 0xA158EF06282C8C7BULL, 0x0B83C5DD22AEF9FEULL, 
            0x2E37437F96F0F99BULL, 0x5B78CBB004A0B912ULL, 0x7A82E14CB120F2D3ULL, 0x3189C1868D1191A1ULL, 
            0xA722A25D43F30FB7ULL, 0xFD86A0302C883024ULL, 0xBA8DBE058A48978DULL, 0xDA5F1F255D43674BULL, 
            0x93489E718D0BE0F2ULL, 0xFD6A7342BE74AC6BULL, 0xBF49CB1094B0FFF3ULL, 0xDFBF3864C8F14663ULL
        }
    },
    {
        {
            0xF3442CB015E08C3AULL, 0x0C3941023834CF0DULL, 0xF71647BC34868CC1ULL, 0x8E2B7A6AD2D8CB60ULL, 
            0x884ED4A569A27343ULL, 0x96D75BC15980862BULL, 0x72418567442B3D66ULL, 0x389411D70F5CDA27ULL, 
            0xA57216A4BBFD6DE6ULL, 0x63F67F934C39D1ACULL, 0xB811314108CC1DDAULL, 0x4C390FABAFDBCD55ULL, 
            0x8593B6B9A4A56957ULL, 0xE2C9C3D16CC7AB57ULL, 0xAB5FC4886AE19313ULL, 0xD60033B3624C9956ULL, 
            0xBFEE71EB65347168ULL, 0xFAD6BD215FF5BC47ULL, 0xEFDF761D8B82656DULL, 0x809FAD6E7FCE483BULL, 
            0x60CCADE4326E005CULL, 0x0ED48BCDF45AE76BULL, 0x0C0E02B4BA6156DCULL, 0x882212FA28A9567EULL, 
            0x44DD681324833EA5ULL, 0x186D46F6719C8253ULL, 0xCB0C0E4162DE2BC1ULL, 0xC9A20950785E2921ULL, 
            0x1A5BC1AD2CD9F18BULL, 0x83DABFE498E2C878ULL, 0x23B31A0562CC316FULL, 0xF282821D066A1D60ULL
        },
        {
            0x685ABD0DC8536149ULL, 0xA549F0494A937680ULL, 0x9C5CBE9B53796853ULL, 0x3D6CDDF40D7A1227ULL, 
            0x1198B4FD5062DE8DULL, 0x8A6D83696B8BFEA5ULL, 0x0DC5BE471813EE29ULL, 0x43A6B8635FEF9E8BULL, 
            0x34576814863632BEULL, 0x9797D000C5A35C22ULL, 0xD8068BDA45A9B19BULL, 0x8B13C98012349FCDULL, 
            0x16C983FE58769B22ULL, 0xCC42D0C5F3468A74ULL, 0x429585281FA68100ULL, 0x293A35F6F70E5071ULL, 
            0x57A301DF676996C2ULL, 0xE953A39917B0F5DFULL, 0x3E15B3379E206C36ULL, 0x754D01B01AE12124ULL, 
            0xDFD4C07B44DF1E64ULL, 0x58453AF654C5AA8FULL, 0x01C196FABA68B389ULL, 0x26071A5AC2635D2FULL, 
            0x545EFC068C582233ULL, 0xEF20B4406E42433BULL, 0x933255EF44D8E18DULL, 0xA4E4C1820B51C408ULL, 
            0x2A68CB58BE4E507FULL, 0x6AF5DE2C40EC3C39ULL, 0x5EBF636068594703ULL, 0x2AD01A7A4E1A4C0DULL
        },
        {
            0x0B7076F6900619D1ULL, 0x02605E93E9E22E3FULL, 0xBEC418AB1D0AF02AULL, 0xBDE639B2A2ABC4D6ULL, 
            0xCEA3A4B765C22086ULL, 0x86E58307C84A5E0BULL, 0x69F3FBA793B7209BULL, 0xCF4C51A29D5C6516ULL, 
            0x0AB02F54B794F8DAULL, 0x853A0F4186BBC692ULL, 0x089BF567B57F179CULL, 0xBCC6DADA19150A3DULL, 
            0x09FC4928F13A39C8ULL, 0xAD516AC4D58F0923ULL, 0x115C5D8F9DDC9247ULL, 0x0E37038D7894CFD9ULL, 
            0xA13E2765993A7DB0ULL, 0xE5020EA4C9C1CE61ULL, 0x0EC070AE7291E471ULL, 0xB83B255EC8A5E5E8ULL, 
            0xA676B2D6109CBF9DULL, 0x752E6EF64EC00704ULL, 0x39A17F36F72B0B8EULL, 0x30CCDFA9E45A2678ULL, 
            0xEF7301A2457AE33BULL, 0x3CD0B10CD72DAD84ULL, 0x9E3435FAE463E9F8ULL, 0xB8256CCF06EF2326ULL, 
            0x86753E0DD30FC852ULL, 0x9B5C8E0923AAE880ULL, 0x4FD9B0CA548E4BF0ULL, 0x2BF2C13C1587030CULL
        },
        {
            0xE25BE90DF387521AULL, 0x413D14762CB29DB9ULL, 0x6AD34FE48348CD73ULL, 0x7173A7D8013A3715ULL, 
            0x044F4375EE4B58AAULL, 0x41586452C3C563BCULL, 0x9B3C67AE0AB88CD9ULL, 0xD99DB71ABB43B189ULL, 
            0xF79C4BC0EA530DD1ULL, 0xB66833371524BA18ULL, 0x609C072310AC2AA3ULL, 0xEA524D216D6BD740ULL, 
            0x112A83FC097832EAULL, 0x75B504E30C5F7548ULL, 0x0D72E38C38E60D14ULL, 0x4718F300989A6AE0ULL, 
            0x981741E582ED64EEULL, 0xF1B67D0F26A654ABULL, 0x8190DEC1B8228AF2ULL, 0x6FAB9F50CCAC6379ULL, 
            0xF26AFA41C6F8FC8FULL, 0xB238B48873BDFE2FULL, 0xEC0D6CB417E339E7ULL, 0x66ED99EE5226708CULL, 
            0x81D0CE837CF552CAULL, 0xA2791F4FE5CC36B9ULL, 0x4E85B17CA560256DULL, 0x24FDF0BF103C4B1FULL, 
            0xC7EDA48DA6E84A07ULL, 0x40CBAF520E3AACCEULL, 0x899673BB89C33957ULL, 0x9DD8F1E6423884D1ULL
        },
        {
            0x29BD49FB233E2EA3ULL, 0x6AAAEFDFB2ABA1B5ULL, 0x7F4E7AF9BA387938ULL, 0xA8EC959088F6FA66ULL, 
            0x02E2E0B5E980B04BULL, 0xDE14FB5B789AA101ULL, 0x7D32AA19702936CCULL, 0x83C96D29AA068402ULL, 
            0xE1E07ECD2C0AE976ULL, 0x63FCFD8C589471A8ULL, 0xC6ECE006C71E23F2ULL, 0xC0615890BCDAB24AULL, 
            0xCAFF8862236EAAC9ULL, 0xE44840F179C1A2D0ULL, 0x6CAA963A86B4250BULL, 0xF149A9791789DB60ULL, 
            0x462A61FB5191BB82ULL, 0xE548F3F2C0A9AF35ULL, 0xDEB2CD24C55E8DD0ULL, 0xF09A8DADB557BFB9ULL, 
            0xB25559C0906F5AA7ULL, 0x428213FB9DD4D556ULL, 0xB5C778ED991DD93AULL, 0x9BB9FE8230013002ULL, 
            0x6AD2A2F67940227CULL, 0xF7593A5E52174A68ULL, 0x7D53D88A9BF33ADEULL, 0x89709B760B5B2919ULL, 
            0x4D8294C8CBFAA6DDULL, 0xD7E1745134D2C2FAULL, 0x10ECF750F2172DA5ULL, 0x25E8E26BC67D2272ULL
        },
        {
            0xB0B308C4C7965607ULL, 0xFC21477F76C683B4ULL, 0x31DA7ADEB454DCDAULL, 0x9C70BD395B6159CBULL, 
            0x65421ECD89835547ULL, 0xD906EED12AA7BF9FULL, 0x97EEE1D82A6A88A0ULL, 0x8DE507581D34B1B4ULL, 
            0x519DDA4B3490F38AULL, 0x345463B54448A3C2ULL, 0xF32E762DA36EE517ULL, 0xCA5F49DBB6BFAA7AULL, 
            0xAFD5FF2B903B67EEULL, 0xAF1AF283FD01385EULL, 0x1E11797AB8CA1E2BULL, 0xC785BFD5D1BEA7D2ULL, 
            0xEE41103F27D168D2ULL, 0x9BE497549D1DE229ULL, 0x22A98C78F334FCF1ULL, 0x8E2A093697EEC3C7ULL, 
            0x3C5934ECB95C27ECULL, 0xCC2184E540890D63ULL, 0xD386BC0EFEEDDC93ULL, 0x4BE7F8E39DA835C7ULL, 
            0xF6B88BCFED780FB0ULL, 0x1FD87499B23EEEECULL, 0x00228C8F9343190BULL, 0xC9FA22BCD88B6567ULL, 
            0xB58546FFADC1166DULL, 0x3706BEBEF682F450ULL, 0xB4818375F95CB698ULL, 0x0C9F6D4AD740358DULL
        }
    },
    {
        {
            0x8EDCCCDC2FD6A092ULL, 0x5C466F11578E634FULL, 0x3868A27AEFABCC82ULL, 0x8D24530732800F9BULL, 
            0xE9D2392596558321ULL, 0x1CC6CAAEBEBC7BD9ULL, 0x7759D562BFEF8868ULL, 0x5248DA3ABF93110BULL, 
            0x7833A5171E206146ULL, 0x363988D1E10F36ACULL, 0xD1D426BD13C01B12ULL, 0xA5EF259A3F7EA0B9ULL, 
            0x3EE18CB291A0233CULL, 0x844F0B7C1BC26173ULL, 0xF72879FD7D292306ULL, 0xF94ADCE2A7224C93ULL, 
            0x411B5803692E5440ULL, 0xFC812A19ABDB7741ULL, 0xD47394167C3C870FULL, 0x063CA95E920701B1ULL, 
            0xA55DA448A099613FULL, 0xE6C526D2C2C902ECULL, 0xCFA5FC721CEF1163ULL, 0x09F444EBD5B4AA54ULL, 
            0xC4BEE22EACFFF20FULL, 0x9F22F61CBB1778C7ULL, 0x97A74075B05040AAULL, 0x0BC85CB98DBC0705ULL, 
            0x8E0C2564C981F403ULL, 0xBAD62895C46FDC1FULL, 0xFC65B11D287B8E08ULL, 0x9D4B5E79EC0156FFULL
        },
        {
            0x7A4545D910E2145EULL, 0x9F563CA7509BFFA0ULL, 0x078233A7E0003009ULL, 0x3A5939ED2C92379AULL, 
            0xF81DC61B6C068B0CULL, 0x667694937F1203B9ULL, 0x9735A54F92FF30A5ULL, 0x418903DCE9684AACULL, 
            0x4DA7D9E61FD53301ULL, 0x8679F91B046D6DF4ULL, 0xDF4A9E329CC90456ULL, 0x1BFB380D02CB60C8ULL, 
            0x6AC29031E1EA2B6BULL, 0xFAA7214FADAEF749ULL, 0xBF3300698B9E268EULL, 0x624343CB891AE87FULL, 
            0x7D2B2E017F97FF65ULL, 0x513AC8758BAF6B2CULL, 0x6347130B4FA6B579ULL, 0xE00A59CA31D3B3F8ULL, 
            0x2CE6F69D51F6FAC9ULL, 0xAE858FB5843F115FULL, 0x8FB6DB92097F30D6ULL, 0xE09A2EE86011AC3BULL, 
            0x4391ADB18197E1A3ULL, 0xFC9470A689233A5EULL, 0xF68E101070DE05E0ULL, 0xB662A1AB8E1E38DEULL, 
            0xBAC85F8AC1F70ABCULL, 0x23E1DBAB2A5139C0ULL, 0x1E61C3CF27945A31ULL, 0x4754B4E4AF9B79BFULL
        },
        {
            0x09CCFE9282AEE900ULL, 0x2412CE545487FF57ULL, 0x1406C7F82CAF9357ULL, 0x13288F12ECFBF671ULL, 
            0xF0C1A73379A4C871ULL, 0x0A7D1262452A6578ULL, 0x9E636649B634D184ULL, 0x52816E079D6BC4C9ULL, 
            0x4164B5301B94BE01ULL, 0x53D6375A4A61EA8CULL, 0x3C313E6FFF8E4768ULL, 0x273D843B5441B70FULL, 
            0x12051FA66811F185ULL, 0x39B026CA660FC7D1ULL, 0x047EF544BB67C584ULL, 0x7726F03AB4452170ULL, 
            0x479DCDFF9C7DBD37ULL, 0xDB358990C2AB3474ULL, 0x896932041C37CB5AULL, 0xF59C2CDF86E69BECULL, 
            0x6849267B5299A53FULL, 0x5C4E38B6399171AAULL, 0x5189F814BE0D4AF7ULL, 0x9FCBED1260453B8DULL, 
            0x0C2D1A098035CFF9ULL, 0xC35DACF43C29434BULL, 0xF6129D50C1FBD4BFULL, 0xDA8D6128CF225B04ULL, 
            0x231AB568C9B9406CULL, 0x51AA615C72EA977BULL, 0xBBF1DFDBD408C8E4ULL, 0x3C7305C9198307ADULL
        },
        {
            0xC5F1CBD58D8E184BULL, 0x34F4D11702C6FE4CULL, 0x0DB07F9CAE55C839ULL, 0xF227D948EF29E74EULL, 
            0x922BC9B6084F761AULL, 0x5873704B8D592FB1ULL, 0xA400D82DF0AD196CULL, 0x3F679DABC658DA5FULL, 
            0x4CBA58F906C1C741ULL, 0x50F3BDF9FACED0F1ULL, 0xFB0F9B9F772BEA71ULL, 0xDE39670C317649D4ULL, 
            0x1EE57B962DC195A2ULL, 0x97B56F972CF3EB1AULL, 0x5422EA63F0362916ULL, 0x26B37ABBCF139B8FULL, 
            0x660E7C41F7E12BD4ULL, 0x30201BE3C2C09F84ULL, 0x632CA635C209152FULL, 0x113417E368CEC216ULL, 
            0x0987C785DC385872ULL, 0x254CF4DE5ADE898DULL, 0xE1DC536C836FA759ULL, 0x17E0AD06A8327456ULL, 
            0x743D339A21DBA86CULL, 0x1588E5BA8E9AEF47ULL, 0xB4225F8BA7F8CC9DULL, 0x1E4C2098CEC6D989ULL, 
            0xA3B24FA2C75AC25AULL, 0xC10180A229B51EB2ULL, 0x13DFB642AD7AC59AULL, 0x6193B57FC9E9714BULL
        },
        {
            0xF105486C741490AFULL, 0x05DE4C46188CF30BULL, 0xEE2DA96C27A84D70ULL, 0x4EBA679EF9065CBCULL, 
            0x91CF5801ADFEFCE2ULL, 0xBA01D89A5C6E4F9EULL, 0x5F9221A013397775ULL, 0x8E05FCB681C28C14ULL, 
            0x0E77822F90F770E4ULL, 0xE0BAF65151C95564ULL, 0x367FC4567CA05EF0ULL, 0xCD5135FB0A0768A1ULL, 
            0x71241D0BD7C021F6ULL, 0xE68CD168F63765E8ULL, 0x4A64596CE0710A70ULL, 0xCA15A074F953B7FDULL, 
            0xA605B21BEF53E30EULL, 0x5F5CFAE4F260A877ULL, 0x5BF47E4576543A32ULL, 0x3844B350D64E2AACULL, 
            0xAC643B3DBC84B368ULL, 0xCB12B583EBA612F3ULL, 0xB97855E02A8D0CD8ULL, 0x46E82E2E86591F99ULL, 
            0xDC899B34EA66C7A4ULL, 0xB18972A3AEC37D9AULL, 0x25DA6F1583FACADDULL, 0x28094A5391D419B3ULL, 
            0x9EBC385D236C5E60ULL, 0x57711EAC178F8454ULL, 0xD1FB7C73E2C4D388ULL, 0x100144B3C4B6A63CULL
        },
        {
            0xA4F39AD6985A93D8ULL, 0x32471CCC8A7350FEULL, 0x7EF4C04632F69592ULL, 0xE0B6CF8B70202C12ULL, 
            0x22914171597A3E8DULL, 0x437636864D526107ULL, 0x9D3F82B30A9C128BULL, 0x9B852B6D1D92FDF9ULL, 
            0x5D994BC51052C9B4ULL, 0xFFEAB0F147EB1D97ULL, 0xF620AB1266F50E92ULL, 0x018D3067443E7624ULL, 
            0x653F5531859D4174ULL, 0xBC9E186E5BA38F48ULL, 0x80B0D86DC2393722ULL, 0x393632FF85C9EB9DULL, 
            0x6B6062F62764B164ULL, 0xE28CA231742021A7ULL, 0x7B9E1476D5358E35ULL, 0x7D7FB1335D0D6BC6ULL, 
            0x203C7CE30C8E10FCULL, 0x494CD36512B82471ULL, 0xACF2886EF4F3018DULL, 0x2E434DB0A37C49CDULL, 
            0x16EE26F9ED81F497ULL, 0x8801362D9AA717AFULL, 0x5B18F2947BCEFB4AULL, 0x200247699CACCC4FULL, 
            0x6523494EE3418B00ULL, 0x5C0DFCBFEFE95A48ULL, 0x8F27A4BCBB3F68BDULL, 0x927E5203F71DBCFDULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseEConstants = {
    0x45AB071F88972439ULL,
    0x6D5919C5723D63BCULL,
    0xB2EA2691C5C82A81ULL,
    0x45AB071F88972439ULL,
    0x6D5919C5723D63BCULL,
    0xB2EA2691C5C82A81ULL,
    0xCE6AB38C0DCBBA7FULL,
    0x64DE9CB7A18F120CULL,
    0x38,
    0x18,
    0x0A,
    0xF8,
    0x65,
    0x8F,
    0x4E,
    0xE6
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseFSalts = {
    {
        {
            0x34EF015310604584ULL, 0x4B0D84CFFE089F83ULL, 0x97F6A8BBF181179BULL, 0xEBD1D1701E50A52EULL, 
            0xA1C0D41EC6863DCFULL, 0x7D56D9201433E4EAULL, 0x4560169F51492B0AULL, 0x6C6FD06E7F0397A1ULL, 
            0xFA00CB6CFC3C12E8ULL, 0xA30C5742CC18B066ULL, 0xD1A3EA4A820C8C11ULL, 0x5B0FFA6C563D7065ULL, 
            0x9F22BA94873D953FULL, 0x198CA5F065C012BAULL, 0x3EFBAF84E4A79196ULL, 0x808104EEF88C27ABULL, 
            0x0DEDC4AD5ED41E90ULL, 0x2707B6953F4EECE1ULL, 0x31DA3B31E9D55626ULL, 0x832B373143A9FE87ULL, 
            0x5D2005967BCCB2ABULL, 0x2B18675F9D302D91ULL, 0x78B86A035D1DE228ULL, 0xBC2728C2ACB5D4D8ULL, 
            0xF2EE4656673E3AF8ULL, 0x5DF575D5D75EBCE5ULL, 0x3395E5043C48C3B2ULL, 0xEC6225A89A93FA93ULL, 
            0x58FEB044F457EDDDULL, 0x7F1D16CA07CC1F03ULL, 0xBD9CDF2A9BCD7172ULL, 0x864F0DDB3B13F75AULL
        },
        {
            0x36C89EC63C2D179DULL, 0xC1AAB541CC43854BULL, 0x918FDCBEF4A96DC1ULL, 0xE59E27D73B2FAAE5ULL, 
            0x52B0621B320CCFE4ULL, 0x1FF6EDBBF40A32EFULL, 0x478951E79191BF34ULL, 0x182AB0E86213AEDBULL, 
            0x1CB560CA561267F1ULL, 0xCCEC8EF77DCBB37DULL, 0x28F865F8B4B30FC4ULL, 0x0B0C4495FFB8B8D8ULL, 
            0x10C75C25F3719DDFULL, 0x64846560884A3388ULL, 0xB6D01462EADBCAB0ULL, 0x5CF27E51259459A7ULL, 
            0xD4F8F9D9B1C98B87ULL, 0x44674110D50DBAF7ULL, 0xC1F3E36FE63586A5ULL, 0x9E12D18D7CC47682ULL, 
            0x7B887E897C9A4DB2ULL, 0x9C725CAC293AF77BULL, 0x9701CBF2949664F8ULL, 0x41971B25E30C22CBULL, 
            0x3990F5F78F0B562DULL, 0x110F488E184043A1ULL, 0x25B7E6F1180E7445ULL, 0xC5ACBC335984A6FCULL, 
            0xBD78C502920890ACULL, 0xBEDF9A04A5A2B9F4ULL, 0xFCD7521C09CAB2CDULL, 0x756B9A81E9A815E8ULL
        },
        {
            0xAD31B93CFFCA7E61ULL, 0xDB0B482EF0952321ULL, 0xDA6907BC5642C445ULL, 0x0D25239F11683499ULL, 
            0xCA5A71056E9BBF47ULL, 0x54E292587FBA0076ULL, 0x68DAE0EA8122863FULL, 0x1A49EAEA791BE3DEULL, 
            0x48360689276CE9F8ULL, 0x12AC39E5D404BD5DULL, 0x684254DC6C52FF61ULL, 0x0D6013D3F28384B5ULL, 
            0xDA046478B624D13DULL, 0xC0A0E21B4870C49AULL, 0xB640FB48C956077DULL, 0xA79D2F35E32628D1ULL, 
            0x80FBB2D32792D5BDULL, 0x486D722AD316A33AULL, 0xC030CB588E2D85BCULL, 0x1A4E73B6BAB22E24ULL, 
            0x8AF83792B2FD89D9ULL, 0x4A87F0705C156A61ULL, 0xB4C59EC0E6BBB0B3ULL, 0xEC7DC4BE745C081AULL, 
            0x53153AB901A652E8ULL, 0xCCD6B6DF40FB90A6ULL, 0x18B7B7D2F18C4245ULL, 0xD199D80D0147267CULL, 
            0x3761A44CB409D6C6ULL, 0xFC892D363D4DE45CULL, 0x711C19295243BC78ULL, 0x78BFA309634068CDULL
        },
        {
            0x8EDA1A85DE7E8B8EULL, 0x9E897AFE33C7330CULL, 0xAFDC2F87B140CDF7ULL, 0x867E9C901C72CA0CULL, 
            0x8F27DBB982307064ULL, 0x7D6563172F274FDEULL, 0xAD7BC7915F24354EULL, 0x81EFAECB7A35474EULL, 
            0xEDF08EB428DA32D7ULL, 0xA4C3F8A2423FD92CULL, 0xA5DDB4D3C278563AULL, 0x51367E4D33BBDAB0ULL, 
            0x2AA00DDD6E15AB71ULL, 0x447BBC7B40BF1AB2ULL, 0x7A4E9B4095E1D37EULL, 0x32C53211A0BF152DULL, 
            0x43C473F2737213DBULL, 0xD09601676DE7E7F0ULL, 0xBF418C09D8438559ULL, 0x46A3F5A788916E3CULL, 
            0xBDD54FC0B7E3DC8AULL, 0xB3E218AE767BA88CULL, 0x657EFF7756B6D196ULL, 0x0EFB3C49EA0445E5ULL, 
            0x64D8BC8CD7F023EEULL, 0x70EAC565BC972C4CULL, 0x96EC1C6D9D48746DULL, 0x8F6338E2AEC17F5CULL, 
            0xAA954066980B5F61ULL, 0x8E342B7A03FA3543ULL, 0x35E553E855C7D5DDULL, 0x3E2E99925CF8DC22ULL
        },
        {
            0x0A4C6B4DF1E81A3AULL, 0xBC5F5D84E4233891ULL, 0x19341398690A5290ULL, 0x13DD87136748AE48ULL, 
            0x307273946CF6812EULL, 0x1FCC56ED460EE9F2ULL, 0xC2FE961F13DDF3D1ULL, 0xFB5C165319A8CA53ULL, 
            0x475CF83AA27F3EC9ULL, 0xE897F2A23F5E096BULL, 0xBFD507C68BE9F557ULL, 0x40806753378D1EFBULL, 
            0xCDD1655B0E146D3FULL, 0x9460CC7F3FF7BF6FULL, 0x82FF8B1522E0D0B8ULL, 0xF6046D71FBEC3092ULL, 
            0x7FAF0436DA990698ULL, 0xA348A40E994CE93EULL, 0x1BEE5015BD2A5BB5ULL, 0x1C4EDF9D96944D78ULL, 
            0xC84E593E528352B5ULL, 0x3E38DD0D31A4650FULL, 0x8EE823A58FA65615ULL, 0xAE107893C7E7F9B1ULL, 
            0x27636C1EB6C4900EULL, 0x4C988F5F8698E611ULL, 0x312B9DBC11BD8FC4ULL, 0x5331468486F8027FULL, 
            0xE9CF375D0674DD2BULL, 0xA69F660D45F8D990ULL, 0xF037E133A27A546CULL, 0x12FC7FEF249EF4E2ULL
        },
        {
            0x3FF6FEE7B755F9C7ULL, 0x2C2E34154D59CDB8ULL, 0xBAD12D85ECFDAA0CULL, 0x1C5BDBEE880D1B89ULL, 
            0x4D3212106C448804ULL, 0x8E9B14925218ABE5ULL, 0xA8127D1B58CB5F1BULL, 0x22000E64D3932B8AULL, 
            0x353F2F8421612FEBULL, 0x207813E38F7448F2ULL, 0xE5BB591387B6DF8EULL, 0xC4A7F360B9B10DDCULL, 
            0xFAAAA8E2D63F4E1FULL, 0xCB89E3FFCBB99624ULL, 0x49B3AB9706F4BDE3ULL, 0xA399D00281C71BBBULL, 
            0x9C26398ACE795387ULL, 0x255A16BD31D17DF8ULL, 0x713800C264678712ULL, 0x516027378D1C7F19ULL, 
            0x2E1859F1B032EEADULL, 0x5BD1B294A1CAE3F4ULL, 0xBD6B08FA012F2D74ULL, 0x528DB7F1551682AEULL, 
            0xCA00F60084A7F8CEULL, 0x270D3A8CA3A051BAULL, 0x22DCB816534077C8ULL, 0x4CD6F01021F480F3ULL, 
            0x81423113D01FBCB4ULL, 0x9B66165A1B889483ULL, 0xC2CC1687BC05B0FEULL, 0x3F5B4F5444E19D5AULL
        }
    },
    {
        {
            0x8CA098FC2B8DCCCCULL, 0x4F8EB3B233F42538ULL, 0x5BF668AA33A90DA9ULL, 0x6DEAFB659AB46270ULL, 
            0xBBAD753E10376E1BULL, 0x98718D718A783CC3ULL, 0x034C2EB3A273920AULL, 0x978E741806E3136CULL, 
            0xE2AAC2F0A0DE8277ULL, 0x2777061AB2B76C63ULL, 0xA7BC2341F84C779DULL, 0x249ADFBB19268831ULL, 
            0x1F0E85989BA169ACULL, 0xE2A50B2A7E3ED127ULL, 0xFFFFB012F6DB5D55ULL, 0x9FBC0EF4FFC13761ULL, 
            0xE2280D5373B27ABBULL, 0x5F905A735D44B14CULL, 0x065548061852C110ULL, 0x43B9FE82A692905DULL, 
            0x47593F004A75DF9FULL, 0x28AB9F2B7136860FULL, 0x73F6446B3C635F60ULL, 0xF4543E15D38C0BA5ULL, 
            0x5E71CBD8FBA4FC0DULL, 0x5245640F24EF64ACULL, 0x124FA79DCE83E21BULL, 0xFC21E2F81A53734AULL, 
            0x9CA88967B8366EA9ULL, 0xA5C5CF9B8240F444ULL, 0xB5F9F5C7DD271B53ULL, 0x8AC95E86CCF73AA9ULL
        },
        {
            0xF9DC3EC1F9693FDBULL, 0x20FF6DCEF3E65BB9ULL, 0x5CBE7E950A36F84BULL, 0xB7A67FB925031C87ULL, 
            0xDC837DCA4B888E46ULL, 0x53703302E36C3411ULL, 0xDAE9ED6F8F7D7DCBULL, 0x3910040EDE7FE628ULL, 
            0x5D90075CBF9B8B30ULL, 0x09A22FFCD69ACE66ULL, 0x4E3E62EA85CEA818ULL, 0xD7055F7793E38015ULL, 
            0x04DC0E4B1A19406DULL, 0xDD19A7FD6946991EULL, 0x75AAF928544307F2ULL, 0x1EEFA45B1831B08DULL, 
            0x037278C78B48A992ULL, 0x1CEDEA3DF1B5DEDDULL, 0x33846B92C2F37F9AULL, 0xFE1B9949B4E3B192ULL, 
            0xC5949E372AA25F73ULL, 0x08CE0A754764D24EULL, 0x9EA150E827C1D660ULL, 0xE71E7B6741CBBE66ULL, 
            0x69FC2593A3A0B653ULL, 0x1F8FB9D82FBBA286ULL, 0xB2FFA4E89E3C3AD1ULL, 0x62DA9186B6DB13E7ULL, 
            0x87A886338F2C5813ULL, 0x303AB5AB465F2461ULL, 0xD7F3FEAD078E21ADULL, 0xD2AEAAC17444AA95ULL
        },
        {
            0x3E5CDA9C9DA0CDCEULL, 0x4720672192295809ULL, 0xA8837CEB9B5CA8AFULL, 0xB6BF92226F9E6DBFULL, 
            0x4F6E005DE955C437ULL, 0x7E3C3E40EC7C7D6DULL, 0x05193D0553BE0950ULL, 0x0422A2535EDF3752ULL, 
            0x94715057C1F999E4ULL, 0xC901CA4CF2EE0C94ULL, 0xEE6EEB00CBCF8D81ULL, 0xE52B64AE3773B630ULL, 
            0xFA70BD8B1D048764ULL, 0x38606E8BF9EFE9BDULL, 0x64E9EFC474924871ULL, 0x609EBEC6C719D1F3ULL, 
            0x4BEEE64C98A84558ULL, 0x5356CBB3D33005C9ULL, 0xD7A2EEFC8CE7DDEEULL, 0xAC52A3410149A1FCULL, 
            0xD47BB55404E1E43EULL, 0xAF1F0C1B37E2B0FCULL, 0xB3CFA3C2EBB0AAAEULL, 0xD37B4159A748078CULL, 
            0x5C3CBAF4F25DA7FCULL, 0x5E5B6E24287AFA3FULL, 0x30669AB53DA14824ULL, 0x020E50399F88A80EULL, 
            0x3365A5E954DA47E4ULL, 0x0613AFBFEEB58A32ULL, 0x65DA6E43B71F3C60ULL, 0xF43444F5725BE66AULL
        },
        {
            0xCCCC5630EDAF9858ULL, 0x9AE83F75D868D6D0ULL, 0x1E18299E468FA1FBULL, 0x87C57F56633772A7ULL, 
            0x93FEA34C3F991D2EULL, 0xA5BF71CD41AF822DULL, 0xC4AC5AE6F7073D4CULL, 0x7FB6A0DB12440D41ULL, 
            0xCC5D9C065E818852ULL, 0x95C469D2C7D466D9ULL, 0x90505A60F0F728DFULL, 0xD97EC8614F7DBB35ULL, 
            0x6CB39989C9726508ULL, 0x3254B6E6CC46F7DEULL, 0xBF279B8741350C4BULL, 0x2EEEC9FFA9477DC7ULL, 
            0xB30AD805924E0F29ULL, 0x4E1C3A9DA8692911ULL, 0xC2883137BA54E900ULL, 0x33703C0EB5E62C94ULL, 
            0x8B10ED5929F37A98ULL, 0x3EE73740F4C7E6F3ULL, 0xDBA629F940FCF3A2ULL, 0xB702399C835AF37FULL, 
            0x9D39E02109D29CA2ULL, 0xA30369A5D2F8CC2EULL, 0x5AA39AD5307237F8ULL, 0x044A751CD254BF57ULL, 
            0x939B9DA3E0300907ULL, 0xFCBECBAA4099E603ULL, 0xA12AC81DFE2946B5ULL, 0x3287E9229A5DAD32ULL
        },
        {
            0x2BA84AD18B96FA4AULL, 0xB3E51B63AB486E8FULL, 0x47D8B831D3A85EF3ULL, 0xB1CE8E5A5AA48324ULL, 
            0x9E1BDDF8356E4254ULL, 0x428AA1D25A9FBC8CULL, 0x10DFA5CC1DD19E48ULL, 0x08CFB47D8B818524ULL, 
            0x74488292AE8BF5FFULL, 0x57B81B38AF49B430ULL, 0xAA40B79B452A381AULL, 0xE33A0958623C3B73ULL, 
            0xE21C483700083FDBULL, 0xDDDE80C449CC6D7DULL, 0xBD6EF6FC224F2B04ULL, 0x927B61CB3AFE9C24ULL, 
            0xE4E4C970B15A2B1CULL, 0xF7657CAF3CA9B717ULL, 0xDA25BE466AA42896ULL, 0x14C788911E9C038FULL, 
            0x9E0BC7D22C191B8BULL, 0xDA3C77116CFFCA21ULL, 0xB1D239E9FDD12E2EULL, 0xA256EEA011962218ULL, 
            0x1892E572657DBDEBULL, 0x566DB40D32D09F94ULL, 0xEBBC623A9E9C8B23ULL, 0x9E98A0A5D50DCF7EULL, 
            0xAD191B3F1AC98FDCULL, 0x4C7E631B5E930937ULL, 0xBD14CDF3033F5072ULL, 0x7FCE49A89B0E4612ULL
        },
        {
            0x014B8101B544B3A2ULL, 0x4D1A7EF71AEAC33AULL, 0xFAE881A4162FDBAAULL, 0xE4794ADB9013593BULL, 
            0xF190D45520C24EE6ULL, 0x0B83FFF1039B89A5ULL, 0xE9349DB2FAD6CFC4ULL, 0xC71FCE6CEBCCFA5FULL, 
            0xBDB41E88C439826FULL, 0x3425B5C526D4DF89ULL, 0xB7FE75A1E9AD215BULL, 0x7DED1BE4677EE276ULL, 
            0x89BB59D2F7D91CCAULL, 0x875D254318025D3DULL, 0x85D5ED8115E295D8ULL, 0x8AEE4572951812B5ULL, 
            0x3954E80FB4A79808ULL, 0x8BB4D3188DF3C6E2ULL, 0x8958E070BC057AE2ULL, 0x64AC8FA8182DD26AULL, 
            0x12B9592AB31906B0ULL, 0xC401BD0D8E6E501CULL, 0x7DBE29585666A333ULL, 0x381F7483529F1B25ULL, 
            0xE0CF000C5CBF57B9ULL, 0xDC6C9BDCFAE7CB16ULL, 0x2CEF6F5526E2151DULL, 0xC3F0C1F7042A82A7ULL, 
            0x389FCCF794FA3C4FULL, 0x813DC304274CECDEULL, 0xC8D207C746E37C47ULL, 0x1A8C3EA3F6DB608BULL
        }
    },
    {
        {
            0x09C2D7FBAB23C008ULL, 0xC9F3F2F4EC4692FCULL, 0xDD9937EB606ED53FULL, 0x883AF39E21A5BAF8ULL, 
            0x57A289C2CB86B327ULL, 0x15C9925699506556ULL, 0x6349B878E584098DULL, 0xBE109E68B88ED20FULL, 
            0xE398DE3F66BA3A56ULL, 0x6AA068A7FB08E07AULL, 0x5093635710286D2FULL, 0x1E1C50FBED81981DULL, 
            0x7A51B3E726819C2DULL, 0xF400785445AA2C88ULL, 0x371DC9D74A68E893ULL, 0x575850CAB8BBA986ULL, 
            0x7AFC3815E398E60EULL, 0xB601328B4CF305E1ULL, 0x1496BE355E39C173ULL, 0xC35EFB86E79E75CFULL, 
            0x588B7091E5255684ULL, 0xA144B00587E7F810ULL, 0xC4DC4AACAB0F16F2ULL, 0x5214A9A8C898336DULL, 
            0x035CCE8FE9E467FEULL, 0x984E9FDE9C6E4EA2ULL, 0xD65915B7D3D23225ULL, 0x5585D098A394DBD1ULL, 
            0xAF29626E6BE6FD80ULL, 0x4E67F1B4B7251C91ULL, 0xE19D5CF247E06778ULL, 0x59F11831591D85D7ULL
        },
        {
            0x560F1D55BB8114A2ULL, 0xD4906FBE288F8334ULL, 0xE19583A21E578AD8ULL, 0x1E0A21B1FC65BFDBULL, 
            0xE77DFF66C33963A5ULL, 0x94E60BBFCAC31533ULL, 0x0052251B634B296BULL, 0x732FAF51742FCB54ULL, 
            0x298D0A550969B26CULL, 0x8D795A4F86BED5F8ULL, 0x03AFC4BE68A442D7ULL, 0xE3000C5A6C1D4A30ULL, 
            0x0DB177C0D9627D85ULL, 0xD7436FADABC3E54EULL, 0xE5D65A9EA6B079B6ULL, 0xE3349848FB829EF3ULL, 
            0x781DC41649050B9FULL, 0x072D087126036F60ULL, 0x02C6B7948B250FFFULL, 0x97B13281577D0153ULL, 
            0x37CC4A32B8C37BBCULL, 0xE2448B018C512F04ULL, 0xB153A98B9B057E51ULL, 0x6CCCC08E51274723ULL, 
            0x9DA99496274120AEULL, 0x1F20877EDA26701FULL, 0x95F94CACE1E30FE8ULL, 0xC1BB388A2256DDADULL, 
            0x297203D927415095ULL, 0x88CBC789D0A0DB0DULL, 0xF2F0561BD5934A38ULL, 0xAEEB69038FD14EE4ULL
        },
        {
            0x526FF70A90EB0385ULL, 0xB930F9D11A6009A4ULL, 0xF81C5D238AFDE158ULL, 0xAA749A3D7712B0C6ULL, 
            0x5C175BEC9D25F350ULL, 0x329DEA11C26491F5ULL, 0x0A789365B625840DULL, 0x955B4585CF76FBC1ULL, 
            0x5EF8FC4253E478FAULL, 0x23C9D03B47294BE1ULL, 0xE0A3D18699389883ULL, 0x1C80950B99606821ULL, 
            0x9B423B2C7DCDB8C9ULL, 0x061AE06AC2CF698BULL, 0xE34F51D4DF093A4AULL, 0x42CD4B5283FC5387ULL, 
            0xCD8170A1D781B68EULL, 0x0054E14EFDCE18D4ULL, 0x13F1CC486E16F63DULL, 0x1FA7D6BC13F6E0F9ULL, 
            0x530F016A6824158BULL, 0xC487E6BDA0B94732ULL, 0x7D82E5490A55F413ULL, 0x70B2E5AB1D19768AULL, 
            0x9E246E562D2D8AB1ULL, 0x297A0ED22608850BULL, 0x483CD5AA1F691823ULL, 0x881F74C6B0176A8EULL, 
            0xF25934A92D8BEA5BULL, 0xCC0B39614683C931ULL, 0xD487B4E61EF82BD8ULL, 0xD5776959D2A597AEULL
        },
        {
            0xD9E827C0D90C2F43ULL, 0x8FB35E18B47ECCB5ULL, 0x2CEFE3330AA52DE8ULL, 0x60725C0798AD772DULL, 
            0x1D682CCF279C1F7CULL, 0x9442E6D8FC32AF52ULL, 0x1BA565B11C4E98A6ULL, 0xBEEE7E0E074D12D1ULL, 
            0x70F8658069D4BC97ULL, 0x84F83718CDB540E5ULL, 0x3C6B0B2EE6A586FDULL, 0x163523FD12A47F4AULL, 
            0x074B44BEC0934044ULL, 0xE7FA3E4E07DCEBDBULL, 0x6738EFC5D6193AAAULL, 0xCF4777CA5C70991AULL, 
            0x04CE5E593AF75C52ULL, 0x3991A2897F8A04B1ULL, 0x1D0A2C0C0887A39DULL, 0xB03227F17C9EF7F0ULL, 
            0x1BCBD45C8FCF48D1ULL, 0xC745E3C186CA3191ULL, 0xD7A66C8D001BF807ULL, 0x5484C931A210F502ULL, 
            0x5145CB05C3DA4468ULL, 0x1C0945AD198F6F60ULL, 0x8E8CD2BAF23447AEULL, 0xEE82618F93BA5CD1ULL, 
            0x6087BBDD6D8E2BDAULL, 0x971417C11C1733A2ULL, 0xAC9589B0E3DE22EBULL, 0x5157AFE22479DD79ULL
        },
        {
            0x77112662F777E5AFULL, 0x1804F820A999E171ULL, 0xFB81665F6A53BCF9ULL, 0xDC6D1A57B1590B8EULL, 
            0x49197521AAB7B371ULL, 0x1BD133D0943BA486ULL, 0x8C16D25DD425A090ULL, 0xB046CF4E6C76A965ULL, 
            0x46330CC49F1AC059ULL, 0xDD4DA77653357D6BULL, 0xB5902E16E6B34874ULL, 0x54BDAAB0D0994381ULL, 
            0x2DE2079E1AE3FF39ULL, 0x6AECEB4F8F6A16B2ULL, 0xC9DF0EDE58680695ULL, 0x20DE9FCF204199C3ULL, 
            0x385AAFA6A13321EFULL, 0x57C89167A776253FULL, 0xFC0AC0F9A8677F54ULL, 0xAB0E16062E439D01ULL, 
            0x2C4C520532BE14A5ULL, 0x23ABFC2DFE34BA5AULL, 0xB87C8204C1A8CC0FULL, 0x84607E0D987A2317ULL, 
            0x788A73951512CCD9ULL, 0x3853692DD6CE61AAULL, 0xB9AEB0F9DBBD76EAULL, 0x790837DB1BA55776ULL, 
            0x3552EC8C9E4B9E04ULL, 0xEC7A15DA2558338AULL, 0x8BF0916503978746ULL, 0x3ECE59753A4B2306ULL
        },
        {
            0xFFAC5E8DE9D5345AULL, 0xF11A82D9F18789B0ULL, 0xCF1B8DF82EC63D7CULL, 0xA4FA38EF276A42A9ULL, 
            0x8A5DAB953D37BDBBULL, 0xF041054A94BC373EULL, 0x43AEC92FC1180116ULL, 0x105ACAF18CC7227DULL, 
            0x9DFE68319491C98BULL, 0xF2BE21BD1D2BAE21ULL, 0x10079D7B816287CBULL, 0x5899E52CAB240160ULL, 
            0xEF78657F6CCFA0D2ULL, 0xCEA5113DCB1F5AFFULL, 0x8A6C41DF50E02F59ULL, 0x3EFA2B14AA3769DAULL, 
            0xFEF46E340B29DF28ULL, 0x0EB3B849A6331881ULL, 0x32BC230BC73433E1ULL, 0x29D2BD360E6178BBULL, 
            0xA61DB70A333B9340ULL, 0x303B0E173F2CC8F9ULL, 0x5179D864021557E8ULL, 0x8054F07B3F97A945ULL, 
            0x0455178D3CA67AECULL, 0x46F0DBF21C209EB0ULL, 0xE20D4569597ED106ULL, 0x8E9FBAA34EEF4368ULL, 
            0x40F4C85FFC395E0CULL, 0xE08FD7CCCC12A7E1ULL, 0xD81A85F274B3250FULL, 0xEE9D0F34340DAE12ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseFConstants = {
    0x80677E7B87F6107AULL,
    0x7661C04982F4C375ULL,
    0xC624254DD456EA0FULL,
    0x80677E7B87F6107AULL,
    0x7661C04982F4C375ULL,
    0xC624254DD456EA0FULL,
    0x528D36983B995C3BULL,
    0x59B929BEF0C2C29DULL,
    0x2A,
    0x42,
    0x53,
    0x8A,
    0x9E,
    0x40,
    0x6B,
    0x99
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseGSalts = {
    {
        {
            0xF9D83770E30B885CULL, 0x89EF72FC112FD09EULL, 0x07F2BDAD6249DD60ULL, 0x14AE0EBFFE2B1683ULL, 
            0x2FF388EA5CAFF006ULL, 0xF7D9984A6599B556ULL, 0xD49FA1FE96613E2DULL, 0xCC585EBE94AB70CBULL, 
            0x6692EBECFCE0D341ULL, 0xA60265894E708243ULL, 0x614C9DE009D5D4A1ULL, 0x723E62CF28AEA51EULL, 
            0x00EC54B6E2284314ULL, 0x11E9D4D23BE84AA2ULL, 0xD4547563742E0313ULL, 0x5AADB144ED8FD520ULL, 
            0x179ECBE564E90CEEULL, 0x45FB19026573D11CULL, 0x3B1ECA85A0227A24ULL, 0x9577E2EC1BD94D28ULL, 
            0xD26876CB58C3CCDCULL, 0x4A217608E635F53BULL, 0x3AD8397C46FEF172ULL, 0x436C0AAEA9A3A394ULL, 
            0x475CC51EF95C0C63ULL, 0x58DCCBB7E86AF5D1ULL, 0x8BEB6AF45763AA1FULL, 0x8405B76D6CB47DEFULL, 
            0xEDD1B9FA47E6EFE1ULL, 0x0D18C69F98DADA68ULL, 0x27FFD24EF8BF9E0CULL, 0xB0B3D15E75AA0A76ULL
        },
        {
            0x95D38CB0F593780EULL, 0x2D6605853A67860CULL, 0x4DDC2DF606DA771EULL, 0x1AF5DE5A7F09C2AFULL, 
            0x8C62E10D4D3ABE5FULL, 0xA4D4D53799116C91ULL, 0x04078A52107FC407ULL, 0x44474E48FD7F8B32ULL, 
            0x82593B91C1883E51ULL, 0x4E84AB021130104DULL, 0x1E921B2C4D681CE0ULL, 0x433908ACF84766DDULL, 
            0x922C9A5BAB2B4490ULL, 0x2EBB8DE40BB13DD1ULL, 0xFEDE22A8CA092AA2ULL, 0x5D56C0A73A9D55CFULL, 
            0x1D9B827C8D220666ULL, 0xAF6632A11A577057ULL, 0xB6AB24708EC93DDCULL, 0x3457857C91CF1694ULL, 
            0xAD8025A7748556E6ULL, 0x5B0268D82B5D34DDULL, 0x86BB3E02C3D5CFB8ULL, 0xEDC0C3F19B2EE632ULL, 
            0x986BA3289B1FD0AAULL, 0x7476965FAA558764ULL, 0xB0941C04F9BFEBA1ULL, 0xFE561B09E7515ED1ULL, 
            0x486C2C224689E7C6ULL, 0xB82C8518864A7A36ULL, 0x2B617C4A56C37269ULL, 0xFF2C9BAFD2624AB9ULL
        },
        {
            0x92E41BC484DA52A7ULL, 0xD225A2851C6F75ACULL, 0x291FBFF3B53CB9EAULL, 0xB2F4A6406AAE81E1ULL, 
            0x2CA2A8C404F8F59CULL, 0x325ABF7BE904CCD3ULL, 0xFFD8BCC540BDA112ULL, 0xC8B98FDE735DE920ULL, 
            0xFA399B365B593843ULL, 0x8D31DAFC8E970131ULL, 0x89DE2F2932BD4F96ULL, 0xDE821994F2525CB8ULL, 
            0x9492169912F23E0DULL, 0xB39A58935A44120EULL, 0x2B3D98B8A5923516ULL, 0xC4021FB8455BCCEBULL, 
            0x087F90225C13943CULL, 0x4B3972D6C2CAA230ULL, 0x3E53CD1F2857D649ULL, 0x229638E85814EAC5ULL, 
            0x325DC0D7982DB670ULL, 0xBFC037872FB1A5A7ULL, 0x323FDA42B319ADBFULL, 0x02982867CE93D65EULL, 
            0x4420C1CD9C612CC8ULL, 0xD5C462C39EC3D22CULL, 0xF69F59D21197FEF6ULL, 0x91AB33D4401C0161ULL, 
            0x2E395F07CC96F905ULL, 0xFAA96C96D1437B76ULL, 0x052F835AB0072451ULL, 0xE7D0B78A73FED43EULL
        },
        {
            0x4D16AE6873FD6088ULL, 0x36258EBB54ECB65BULL, 0x5F6D0F0692E921F8ULL, 0xAA9027BF46A017EDULL, 
            0x1BD7A98BE625D70EULL, 0x4B70BCF5F34017C6ULL, 0x8413B6501A81C7EEULL, 0x6BACFCA189D4514DULL, 
            0xF8A481B78195497AULL, 0x3AB45AE1E7D39409ULL, 0x032DD93E5EF4455BULL, 0xCCCBFC577DCA78D4ULL, 
            0xF321BDA9367674DDULL, 0x7C605FE93E3972C1ULL, 0x06BF3C917E61F43FULL, 0x51754474E68B6DD5ULL, 
            0x85E06980645A0DB3ULL, 0xDEE25A2A1B1833CEULL, 0xF387096D431D0424ULL, 0x0AA8B11E6B205FB2ULL, 
            0xFD5464D69300ABB3ULL, 0x4068F076A3E70228ULL, 0x9DDF279C933B85E5ULL, 0x3C6E5763E122C5A3ULL, 
            0x8238EF0953A51130ULL, 0xBCDF62ECEA7098C0ULL, 0x5A5FDF7B2E173FE6ULL, 0x0CE0C1FD38D197C5ULL, 
            0x2C00852940E4A52AULL, 0x28F93AE7F90DA0C4ULL, 0x3F5BFABC5492A4C4ULL, 0x035F13279E7BC6D9ULL
        },
        {
            0xE5D6E43A3448656BULL, 0x5F0D82A2B7DDB85BULL, 0x6FC71AC4E36E54C4ULL, 0x478FFFCBD3EF9F00ULL, 
            0x6759DD2EC8FFFE68ULL, 0xD698AC9C740FE827ULL, 0x959B8F229E9553E7ULL, 0xE2817D5B4E9F9CBBULL, 
            0xA1467243B5090C10ULL, 0x5220329BFB90CBC3ULL, 0xED45A0228F9CB860ULL, 0xBA1AA8853174B82CULL, 
            0x91063F08077EA854ULL, 0xDDD0950B46DD5686ULL, 0x79F4468AD70AD7B3ULL, 0x1FFEE560DEA1ECFAULL, 
            0xB441FB1AF0B912F5ULL, 0xF9CD362DCE1B9499ULL, 0xDB773EA5E508AD7BULL, 0xA95144ED46874608ULL, 
            0x424B05715A6D72BBULL, 0x738F169BF30FA141ULL, 0x7F5400CF07B98B4BULL, 0x11F68D7C151E6C87ULL, 
            0x08741C7AD73FF6C1ULL, 0xBEAA698DE5FBF221ULL, 0x02FA01ED25756042ULL, 0x0D328045A38F6EA0ULL, 
            0xE2C5F316B2DCA00FULL, 0x700199A06A72022CULL, 0x79D44A82EC75E13FULL, 0x08671682567E174EULL
        },
        {
            0x2C70B0F73C2CC9C1ULL, 0x7731D20D1A634578ULL, 0xAE5E48D4AE713582ULL, 0xB78D26630498563DULL, 
            0x8D80E64F37B0E398ULL, 0xD0226EC61A8C64F3ULL, 0x49FF5C69EA31A515ULL, 0xA3852E20D8788596ULL, 
            0x0B51D313B1D14541ULL, 0xCE195791BDCB168BULL, 0x428FECC12A90E1D5ULL, 0x49D1F903A287FE97ULL, 
            0x33C19F1076F6B457ULL, 0x76B91BDFF0FBAE71ULL, 0xE3055AC61BD12842ULL, 0xB72C8AE5F5AF125FULL, 
            0xBE866D1C92BF9650ULL, 0x829664C923D1771EULL, 0x35A8E237CC7ABF6FULL, 0xC2ADE974699C9047ULL, 
            0xFB451EE1CC9F1BC6ULL, 0xDF7976853D92C894ULL, 0xAFAF4489764CE184ULL, 0x03D549161DFC4D66ULL, 
            0x3D893F7F4988C013ULL, 0x752A81DA8FBCADECULL, 0x5544AF031299D242ULL, 0x881B5654C2CE681BULL, 
            0x8861159797DCA09AULL, 0xA5B517E5314DCA89ULL, 0x59835EF3532DB9B3ULL, 0xE847D81CFEDBF965ULL
        }
    },
    {
        {
            0x903EAF3933F4B27DULL, 0x5C1EF96C69DEF03FULL, 0x7332C7467BB9628CULL, 0x5A843464D4A3A689ULL, 
            0xF8799497C23BC56DULL, 0x7E2DF66DF38F6985ULL, 0x200C80B2CD7E3489ULL, 0x63125AE42CAB90E4ULL, 
            0x4E571460551F4162ULL, 0x1CA7524EEA8929DCULL, 0x998264895FDA3C03ULL, 0xA434E17C9C517126ULL, 
            0x9C94C6BEAE4B494DULL, 0x1C9A7E6539093583ULL, 0x163870DDF93C5DCEULL, 0xD458F9FBC3F47104ULL, 
            0x4555CDA2C06BFCC2ULL, 0x364A97052B4C28BBULL, 0xCFC1EF6AE22C2160ULL, 0x4F4F752739F26527ULL, 
            0xA2AC8A1055EAB038ULL, 0xE6224F9C69E8045BULL, 0x93A6D10224E9EB78ULL, 0x7AB9689C19E12E46ULL, 
            0xBEF8832A75418299ULL, 0x502F822FF4113456ULL, 0x39A08955AFBE71BAULL, 0x2B4E7F3FD0237652ULL, 
            0x9A46DE2E31FBFCDBULL, 0x76A091A33BCFF191ULL, 0xB9F869C24241424AULL, 0x28C96C1F07A80110ULL
        },
        {
            0xCA201D9A8C05E4F8ULL, 0x51254D2D6739EBBFULL, 0xB1DF22500D86B9E1ULL, 0x015DBE62BD2FE91BULL, 
            0x14CEA270716F8475ULL, 0x21EC33C1C9633B63ULL, 0x3485CFA50B17D688ULL, 0x46FA802BFDD06924ULL, 
            0xCF76B164C7BEF520ULL, 0x4AA8C97730024D94ULL, 0xE3E39BD2DEEF22CBULL, 0x445AFB940440B2B0ULL, 
            0x4C118BC17175F839ULL, 0x4CC15FF7D608288DULL, 0xB20414B172FB063EULL, 0xFF3E48483F9D9178ULL, 
            0x07391B19A86274F1ULL, 0x4C7741ED09669A94ULL, 0x2132E288E53E49EAULL, 0x7A4096AA0F688545ULL, 
            0x23EEA81CF5F0A09FULL, 0x64F37489682F8D0CULL, 0x6B5B3948B8D49809ULL, 0x1B86126D5311DD86ULL, 
            0x0E42DB6E64F24740ULL, 0x5A5B6FADA1BFD108ULL, 0x1F2FCAED0C4105D1ULL, 0xA6FA0B1DC0AEF881ULL, 
            0xBCEFF79AA8020104ULL, 0xC0F4A24012BFF429ULL, 0xE84612AD33D4683AULL, 0x5F5908A2EB15D66BULL
        },
        {
            0x23A4021F0084BE36ULL, 0xD7C42A508AD17427ULL, 0x56D3A7AB00C344C8ULL, 0x9A5FF2D8A2D89B57ULL, 
            0x1F474108C41F8A2DULL, 0x622265A0CE2DE707ULL, 0xEF5FDB1B1AD50A24ULL, 0x61A365778DA54314ULL, 
            0x405E57B89F754887ULL, 0x86CE391AB4BD48D4ULL, 0xAD5E767F023C8778ULL, 0x6756D979B7066F93ULL, 
            0x7B178386AE416858ULL, 0x1F4593B64005244DULL, 0x0C7324726824F342ULL, 0x4AF7991955B677F3ULL, 
            0x900085D767AC3F39ULL, 0xEAE4F4CA9F4436F2ULL, 0x0A02D0355C2383FDULL, 0xC351C965BB5FC3BAULL, 
            0xCBE9401854E7C4ADULL, 0xB40B3C38E2A18F0DULL, 0xC39D2A0888C1290CULL, 0xC988E58C0A5E7374ULL, 
            0x36DDDF0087E0254EULL, 0x5275FF064DE519C7ULL, 0xEA03FF13AA949A3BULL, 0x806175AFBA0E411DULL, 
            0x19090A74193291E8ULL, 0x90CD8BEA46FDB653ULL, 0x5DD09CCB898BEE33ULL, 0xA0721A0DFEA4778AULL
        },
        {
            0x83379611A7CC7BE2ULL, 0x818A370A9E9FBCD7ULL, 0x9EE3A66E0781922AULL, 0x4E2F2497DAA8BDBFULL, 
            0xEC6D44A2A1190162ULL, 0xA33765B214E15622ULL, 0x72F1786985A9341BULL, 0x12418D9AD1156F76ULL, 
            0x4392EF9EDE4CF756ULL, 0x07262F13D199E027ULL, 0xED75205AA4F960BAULL, 0xE118C57255E1CBB1ULL, 
            0x535556FA2D7FDE61ULL, 0xF6B61694F9601DCEULL, 0xFD9E11C33A84619FULL, 0x2B45EE8E4814F1F5ULL, 
            0x918D06AE62BABFFCULL, 0xB7D5E02C0749C435ULL, 0xEF0C07AF0B33DDB8ULL, 0xBD55FBE0A2265074ULL, 
            0xE6DBBF54605D1266ULL, 0xADDFF60407CDC374ULL, 0x2330736CE64427A0ULL, 0xE7F5B641AA3B4529ULL, 
            0x0CA511D651F9822AULL, 0x6FAD6C62FA9B583FULL, 0x5BA15B424909CBAFULL, 0xC1E0625BE1C323B7ULL, 
            0x55E0541FFCEF331DULL, 0x96A478B016BA9F2AULL, 0x611CD52AC91BDCA4ULL, 0x3A8FA0AEF5E96B90ULL
        },
        {
            0xA820D02B50D096FBULL, 0x3AC5165801715D5CULL, 0x74BC37BFF1894C2FULL, 0x17C5DF128FECB861ULL, 
            0x2D30B51A38644622ULL, 0xA4EA9BD6EB1BAEB9ULL, 0xE8263586A229B454ULL, 0x105C55FA83A3CAD7ULL, 
            0x20C2B552D6CF9A69ULL, 0xFB93AEF4BB6BC5FEULL, 0x004BD817D3617E2AULL, 0xF9DB5EFBEA6A1197ULL, 
            0x46FB6D5EE9FFA041ULL, 0x2B12CD1583FBF212ULL, 0x28E597DFA264B1CAULL, 0x1EE3DB187ADB2EEEULL, 
            0x46ADEB57C8C4F6A6ULL, 0x4C6FEB24A3F29B15ULL, 0x6A6CD5EADBBBF629ULL, 0xAD53FE4044CC98B0ULL, 
            0x7C7108BB1DA3D273ULL, 0xBBB406E518C7B793ULL, 0x7AF549914E5B1160ULL, 0x169B39BEEC1BC617ULL, 
            0xFBA8051DB9097961ULL, 0x76CF7DFCA37DC0F9ULL, 0xC8A719DA0A91AB4DULL, 0xB80339C5554E7236ULL, 
            0xEF9CA01E8FCD50F5ULL, 0x2BB45B39096DF9BCULL, 0x4BC60921F8B4EFBFULL, 0xA327F863D8B582D7ULL
        },
        {
            0xF4820EF1ACFBF200ULL, 0x34CC99AEAC638A47ULL, 0x949CB179C8BD97D1ULL, 0x856CFE2492E115A8ULL, 
            0xB7B08BCEDD8D6511ULL, 0x4AC306E55A0F8322ULL, 0x05737EBAF6621C5AULL, 0x88D05BBEE02C7D28ULL, 
            0xF0EA79F81372F68CULL, 0xF68E10847BC7003FULL, 0x2B7B53D2F4351886ULL, 0xB9CE0DF261CF53C5ULL, 
            0x53A7A54166B8905AULL, 0x3D5C8C46839D5831ULL, 0xBB114CB9858AA4F6ULL, 0xC7AFAEAA6AFED025ULL, 
            0xFE724863C72F6E32ULL, 0x3F0FBC2C0FEEC70FULL, 0xA98940B91BB16EB6ULL, 0x0419589F8AB5DACAULL, 
            0x93CD97BED1A4F71DULL, 0x4A2AD7891629DCAAULL, 0x1AE70CFEEA90B1A0ULL, 0xDFB4725C8763A4F6ULL, 
            0x5F86B3F8C50CEEFBULL, 0x44BC7E3191E0EB51ULL, 0x2273961A25DB6C53ULL, 0x0B3297176B47D1A0ULL, 
            0x7635C9D85A37D597ULL, 0x4C303D26B7072B13ULL, 0xE658B77A68DFDA78ULL, 0x18977259A0EFCC3DULL
        }
    },
    {
        {
            0x80EBDB632AF8EA48ULL, 0x5455A7A834550CFBULL, 0x201B7965163183D8ULL, 0x2A6C827C233497E4ULL, 
            0x4AA0160E39F86FCDULL, 0xCC9A5E1B3B13634BULL, 0xC4108CF60255BF5CULL, 0xAE119F66696A4BEDULL, 
            0xCFD5B3E9787BBDF8ULL, 0xD26E42DE649D62E6ULL, 0x55BDFECA52032C12ULL, 0xB6C0558A67831924ULL, 
            0xA21FFC9F28C1021DULL, 0x44C90FEB945E02D6ULL, 0x42B72EADB8418C1AULL, 0x8EA7BEC42C1D2934ULL, 
            0x78BE1270E2179D4FULL, 0x201B9447407B31E9ULL, 0x9FFC7DE732842095ULL, 0x5EFFD31421F1D08AULL, 
            0x2DFE550A4FEC2E82ULL, 0x3CABC33F70F1FB9EULL, 0x0BD1B5BF0B05186CULL, 0x873E3F81C3B13C68ULL, 
            0x00B33F7E9C940B5EULL, 0xFE22688909AB4361ULL, 0xA369F0A62D66A066ULL, 0xA55C28FDACF79A7FULL, 
            0x09746AD54AEBB56BULL, 0xC010B09FD5206939ULL, 0x89CBE1425F2BF7DAULL, 0x13460C6A8F5BA1E7ULL
        },
        {
            0x0E08321FEE58BE6CULL, 0x1E0004F2E6DCB92AULL, 0x6A25A1748E855B55ULL, 0xFB7C70686AFEE98AULL, 
            0xA07047838835B974ULL, 0xE56762C7A6B48731ULL, 0xBAAC0FD867E8EAD4ULL, 0x83F06161F8187B02ULL, 
            0xEC4A87B90C71B04DULL, 0xCFB2F0A03CDF36A2ULL, 0x88B512BEB09277D4ULL, 0x71EFB5FF26F38827ULL, 
            0x3235FCD98EBCDDAAULL, 0xC4C015E8DC264C12ULL, 0x84ECDEBE2EA6DFEBULL, 0x38415FE34B7011F0ULL, 
            0xB26E5CB23BFD5849ULL, 0xFA8CF3EC3FE17A54ULL, 0xA2FDEDD0254D706CULL, 0x008D701BE71B60A3ULL, 
            0xD5302693A8A4EC26ULL, 0x842989D31ECF62ACULL, 0xE9A58DE5BB6843FCULL, 0x73EA6E058423A9B9ULL, 
            0x3A2CBF895AE7C0F0ULL, 0x7B5C4B8D476B1EC9ULL, 0xC78489A407BF334CULL, 0xC1F4242DE36D2724ULL, 
            0xDB902CD68ED72811ULL, 0x4414E7914625E93CULL, 0xA96E7B0FA3F63371ULL, 0x33EAD74F3AED683DULL
        },
        {
            0x1EF8FED0EB4DB63DULL, 0xF944A5193B914A31ULL, 0x9EC296FCFB650337ULL, 0x81D2C234A9C21843ULL, 
            0x54BACCF4E1505C7DULL, 0xCEAA4218AC63C52AULL, 0x3DBE741F1F2AC578ULL, 0xFDF4AB291848DFFBULL, 
            0xFAE397AC6A07A574ULL, 0x6D3D8234A6216F9BULL, 0xD472B725A0C6C96BULL, 0xDB6FAE9C10C6A23DULL, 
            0x5A26F24808972E74ULL, 0x6FCB410FCE9D184AULL, 0x1D363E3DD6A17A4FULL, 0x164140561992AF0AULL, 
            0x5C7A4B35149B19A3ULL, 0x9FCDC4BCC179039DULL, 0x6E4897910C7F60BBULL, 0xFC8AE93D7ED8BA13ULL, 
            0xEB69C9F4658AA136ULL, 0x1FDB3693E2E2C410ULL, 0x516C01AFE239C8D7ULL, 0x30475361E6A2F91DULL, 
            0x96715AE15A79B8EAULL, 0xB48577EDF17630BAULL, 0x85943CB0BF650C7FULL, 0x5F8AFD81C1C8FE6DULL, 
            0x2741A7D0F73E4EF1ULL, 0x6EF66D48F57BF7AFULL, 0x41293A570E670617ULL, 0xAEDE475FD9A4A569ULL
        },
        {
            0xB741FFE1CDE5F6B6ULL, 0xE4501E265D315C04ULL, 0x236D88C1116B7179ULL, 0xCEC0E9832C59A82EULL, 
            0x20B97C973CE64933ULL, 0x7EF61AA66B8691C3ULL, 0x27B42598C4756DD7ULL, 0x54A948B12D647EE0ULL, 
            0xD45C5C0BA4A9F55EULL, 0xFBF7A308FC3407DFULL, 0x8BF601DFB2A0A270ULL, 0xA36DA909ADC236D5ULL, 
            0x692D51AAD33D0804ULL, 0x7AA5870FC67E3B01ULL, 0xA52D77D6AF4F014FULL, 0x3851F83A078B72E0ULL, 
            0xF89DDED8738D6A6FULL, 0x07A46B0F5EE0CFABULL, 0x97228E26CE7F8E42ULL, 0x8BB53C56B6184819ULL, 
            0x48ABBDB793B6CDE1ULL, 0x82DB03F1C946FA97ULL, 0xA4C9ABE48B2F2DF1ULL, 0x85A1DFAAD1BB7324ULL, 
            0x76C2FEFBB0751978ULL, 0x0F4A5A31E389FFFAULL, 0x04543C4FABF7BBB6ULL, 0x6EB9F15AB31C588FULL, 
            0xBB946847EA37BBCEULL, 0x7AAE81985F0EA4C4ULL, 0xEB8A186E5534F5B6ULL, 0xA4C097A77291AF49ULL
        },
        {
            0xB159E9CEE015C763ULL, 0x15887461A35E08B1ULL, 0xA5316AB7B7C45F25ULL, 0x99069F1FF6693A56ULL, 
            0xBAA88B1F9964CEC2ULL, 0x75AC6686D6ED7261ULL, 0x282635FEFAA58927ULL, 0x06E93C7E6E9ABBBFULL, 
            0x8AE67BD2F44388C3ULL, 0x75B8E4D6C9C79102ULL, 0x10E0048DFC3784ECULL, 0x23137EF4204AB1E9ULL, 
            0x70E8D97D4D68DFDEULL, 0x5055F2FA69A58020ULL, 0x1285FB7F25B442C7ULL, 0xE6820AF3DFE0DCD9ULL, 
            0x1B596DA42212C99EULL, 0x566881827E54F178ULL, 0x0A3E0EE6C5EE2C88ULL, 0xB55557705162DF99ULL, 
            0xCA0BF6EEC110BA40ULL, 0x26139400BDAE57F5ULL, 0xC78BFB851B74D197ULL, 0x2F8A3ED45593FE76ULL, 
            0xFCC77F69992DA68FULL, 0x8D2CE3A54F05800CULL, 0xE4E187DB58DC14E4ULL, 0x041453EB543F4D63ULL, 
            0x0D84C126C640285FULL, 0x4C3D02DDC0459315ULL, 0xE79881A9C4FB4DC3ULL, 0x9277EBEEA2B3352CULL
        },
        {
            0xA6F963755C163448ULL, 0x4228F123BBE456A3ULL, 0x9B4DBDEC2435D254ULL, 0x5D5BCBA63ADB08FAULL, 
            0x48C5C866904E6007ULL, 0x4A8611EB6DC8F0C2ULL, 0x0B41250F8237D259ULL, 0x5B251DCF286897CAULL, 
            0x81440EDEA0D53832ULL, 0x637A1DBB58137105ULL, 0x489C1468AFBD75EEULL, 0x84C717A43FEE4B5FULL, 
            0xEA8042FB1F1A815CULL, 0x927E6BB041858D53ULL, 0x882C6C2512721CC7ULL, 0x73A40FC5E935C5C6ULL, 
            0xF90C1D90E4DBBBC6ULL, 0xDE77773109DABE63ULL, 0xBCF6A0E12794D3AFULL, 0x40A5B66F7E658DC1ULL, 
            0xD1FCAB756EB1A391ULL, 0x70E5545E3C91ED48ULL, 0x527D9751E98F261DULL, 0xE401BA0BA6016E4AULL, 
            0xCFF1D8D97C6EC384ULL, 0x9F8A97FE3A56C1C5ULL, 0xED058AE5E23FBDD6ULL, 0xD663E5D7988D5DA7ULL, 
            0xD63A378140B354C6ULL, 0x468D0321D3DEA3D2ULL, 0xAE1F451D41E4E897ULL, 0x1D9F9D895E47E22DULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseGConstants = {
    0x168F598B2758BA43ULL,
    0x7CA24BB4D99F48ADULL,
    0xFC3F63924A8D9D24ULL,
    0x168F598B2758BA43ULL,
    0x7CA24BB4D99F48ADULL,
    0xFC3F63924A8D9D24ULL,
    0xE0F984C7FC189FFAULL,
    0x2A321557F671B10EULL,
    0x40,
    0x7D,
    0xEC,
    0x35,
    0xDD,
    0x4A,
    0xE3,
    0xA7
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseHSalts = {
    {
        {
            0xEAEF9FC210EDCCD5ULL, 0x23C72D63D2860EF4ULL, 0xE26AFE599545CCB8ULL, 0xF0A79BF888B77B36ULL, 
            0xCDF8DB4F5A410A63ULL, 0x7E0C9D894D8C1C89ULL, 0x99F87ED15D3E1B15ULL, 0x7E08741097BF0B7FULL, 
            0xF74B511DF48FA776ULL, 0x6F2703D55263A73DULL, 0xB02E46F00A6B404BULL, 0x4D1F47C0A40B196BULL, 
            0x9308322F507C75BAULL, 0x547B378D4443B3FAULL, 0xBC47F40FA17611E5ULL, 0x44FFB17A1D522D42ULL, 
            0x8B213CB03202662CULL, 0xC7CB242E159659E0ULL, 0x364587A04092F389ULL, 0x2C81D268CBBB5EC7ULL, 
            0x873714F8394B2986ULL, 0xD34149BBDFB6AA35ULL, 0x3BC6E05CCAD94740ULL, 0xCBAC63CD6CCFB69EULL, 
            0x285352E71086A4F2ULL, 0x742C2366E8E90304ULL, 0xFD6146C178FD16DBULL, 0x65B5FCAA9E7B0965ULL, 
            0x8A8B132CB7FBFF7BULL, 0x21EA06C9F2852FE9ULL, 0x42F2F7BCD036E5D8ULL, 0x8E613EFDEE758D58ULL
        },
        {
            0x17A458AFFDB31A45ULL, 0x253BDD449CC1BDFBULL, 0x3CD1D53662647C3AULL, 0x1041D202F41E5743ULL, 
            0x609B2A303347F135ULL, 0xBB9B60E7907E35ECULL, 0x9924E54A570CF2FFULL, 0xB0BA139BC565D977ULL, 
            0x3A09A981F47975CEULL, 0xB40DE492F113905EULL, 0x2F773A60B3CCF38FULL, 0xEE7F56008B017781ULL, 
            0x7BD38EF276B8F47AULL, 0xBEABC8338075EF24ULL, 0x5E6A60FC7B1B1CC7ULL, 0xBC4D2D0DB72B1F14ULL, 
            0x78C6467185115EE7ULL, 0x479A9BFA34122EE1ULL, 0x5F0405E56693ECE9ULL, 0xC0B42538BF092F87ULL, 
            0xF07426C09DDD798BULL, 0x19B6A0E48281BE1AULL, 0x3E89C1BAA445F5F5ULL, 0x4FB99BE1D99D51FDULL, 
            0x968611DCE92C4395ULL, 0x5D8E4A4EBEC4BA7CULL, 0x8F4CA6981943744DULL, 0x6C56E2611E49DAB2ULL, 
            0x2CD7A6A3850591D6ULL, 0x6BF7D39DDB6F32B9ULL, 0x44114C9D621D2006ULL, 0x09E4A82D5A4F69A3ULL
        },
        {
            0x6AB7F3910B7267F0ULL, 0x8A08A70C04C5C13CULL, 0x4BEDF75FFE4BF049ULL, 0x6197B726793EE6F2ULL, 
            0x0329D4AFF7F5148EULL, 0x771740449238CB74ULL, 0x88AC33FD2C904C79ULL, 0x7FF740D6EDC4350AULL, 
            0xADCE59470BF86664ULL, 0xC03A44EC5867CBE0ULL, 0xE0D173D4322A3A16ULL, 0x0C9B5A6C18E7E717ULL, 
            0x387E7E09729E9962ULL, 0x63D87B5A88DFA70CULL, 0x6A64DFB4BA115B5EULL, 0x052BFBE7D151F6B0ULL, 
            0x76A30A56E952C6BBULL, 0x5543EC172456364FULL, 0x57FF8677D6E27049ULL, 0xECD1C5B629091A8CULL, 
            0x41E1D889C9D6CFDCULL, 0x1FA5095C30B1B4A0ULL, 0xEFD9F7D7C61EDE74ULL, 0x2E12D139AA08D9C2ULL, 
            0xEFDE0D9CCFDF9C81ULL, 0xE927C0328C32242DULL, 0x17370616EFE39940ULL, 0xEFE6048DA0FD86FFULL, 
            0xE5EB29F5FB83EE57ULL, 0x5D6421EDA43492C7ULL, 0xF340D66AC75C5C1EULL, 0xF02D74610D32F673ULL
        },
        {
            0x313153E7120AAC50ULL, 0x4EDB0E9365920B55ULL, 0x993FA5D5671EC3FEULL, 0xDFF66A8A5FB7126EULL, 
            0x4EE6D49C71FAE4F2ULL, 0x3E32802468FD8E97ULL, 0x5B013E05203B555DULL, 0x2F15A9D2377676E5ULL, 
            0x6562F49FD8D45114ULL, 0xAA81F79BFDFB8846ULL, 0x3043284EDFC7EB90ULL, 0x90CA1449CD39E0C3ULL, 
            0xA457F0E04F8C29CEULL, 0x04A41C9318FCDC41ULL, 0x8AF178EBED3A9490ULL, 0x50725D629FE913A6ULL, 
            0x824A770A924D2F35ULL, 0xE5434A10494A422CULL, 0x4090D2C30E5FD8E3ULL, 0x4C7AC07FAF633117ULL, 
            0x4F94686B0683C69BULL, 0x77275035E1A6C8DEULL, 0x2E25BB235666E9B9ULL, 0x1A69875050C3543BULL, 
            0x53E93F4BC5B22FC0ULL, 0x6FFBA840D0EA388DULL, 0xD5D2C7CD9D7CE4C3ULL, 0xC37B471FAD1E5CE0ULL, 
            0xE6E9FCE136FC9B3FULL, 0xAC30B408231859CCULL, 0xD45001DC2F1BECD5ULL, 0xBDCD1F6F451C8DA4ULL
        },
        {
            0xB78382B8CFD47F58ULL, 0xAF2AC3179EF521F1ULL, 0x7D590335590F0869ULL, 0x7AB335A3F98F8A12ULL, 
            0x2B213D4058B20940ULL, 0x6BE8C1D8894A61AFULL, 0xBB4A2377908B101DULL, 0x66E61056C5E4EF73ULL, 
            0x5F5688C531CE0FE3ULL, 0xA40AE7DA4BC34EBBULL, 0x4D7FC3859F0E0DEDULL, 0xB919123B17976ADDULL, 
            0x6F55BBD2F6A4BF37ULL, 0xF70F23D1F67E4494ULL, 0x9CEEEF4907E68674ULL, 0x13509339C00D10A6ULL, 
            0x9FC1FEDCCE2A4246ULL, 0x6C8B299320F86CE6ULL, 0x9E70B24A15E709B9ULL, 0xC498F87F936528F2ULL, 
            0x196846A7C557D30EULL, 0x653025A3B328AD3CULL, 0xFB2DD8210EFBF71FULL, 0x56EFD5098CC6A750ULL, 
            0x529765224765BD27ULL, 0x7D11744900E0391BULL, 0x6A53621E61993940ULL, 0xBD1F1D71462EA560ULL, 
            0xE4FB8C301EE021D0ULL, 0xB167EB02CC653DABULL, 0x8F1433217B0985D5ULL, 0xF164A9C8D1976191ULL
        },
        {
            0x053500CF2B1E1C91ULL, 0x40BE4ACF253B0F7DULL, 0x4B4849EFB8C1FC9AULL, 0x5668688A66A8026FULL, 
            0xFA7BE2DBE100474CULL, 0x153D6FCEF6B4D57DULL, 0x187FDD5CC7A16473ULL, 0xE379B83058DDA549ULL, 
            0x2FAAA628EBF15435ULL, 0x88C34C55C8256927ULL, 0xF89BF85C87497596ULL, 0x66DAECBDACD11DD6ULL, 
            0x788E332AE637926BULL, 0xFA505F478BE58E25ULL, 0xF1CEBFBED625A94AULL, 0x7E9F62D0A89BD9EDULL, 
            0xB1F1B35F71F1D083ULL, 0xCF306D52EFCC2E2BULL, 0x84AC7D06289278E4ULL, 0xA50523ED8F8E39F7ULL, 
            0x78FF2C41A7B665EAULL, 0x24186D9673D4DD82ULL, 0x4CC707E5B2123112ULL, 0x4C19E8DAB0AD9953ULL, 
            0x51C7148D84B2ED20ULL, 0x4947C304AF0A6781ULL, 0xB1536EEA160247FCULL, 0x293138F3B8668651ULL, 
            0xC69C58D86C06754FULL, 0xE9BE548F3019269BULL, 0xA4AA098A0B347C05ULL, 0x10CEB66A3ACCCB97ULL
        }
    },
    {
        {
            0x7645300A54F1A7BFULL, 0xC7AB15603878C9B1ULL, 0x9F915A5FC03D215DULL, 0xF378ED2FD7B3413BULL, 
            0x0931227197F04230ULL, 0x4D561D7193C61CC5ULL, 0xF3CC282FF355BE4BULL, 0x4AE81F24A5D84404ULL, 
            0xE04A9E6E289CC332ULL, 0xEB8130969DC7852AULL, 0xEF3CA2A4CD3C39D7ULL, 0x34CB0E63D7A28B8AULL, 
            0x1909D5C3C848A079ULL, 0xB63F1623754E095BULL, 0xCF43458E124535EBULL, 0xBE3C532D5A35C2FFULL, 
            0x6431A4C7ECA41213ULL, 0x50FEC7C6DDBBE751ULL, 0x36B7EA16FF2C85ACULL, 0xAA4782BAEFE6F138ULL, 
            0xBAED3A24823F7F59ULL, 0xF4145FF75B4BED4DULL, 0xB0CC2E5173959E2EULL, 0x88F59599F59E3916ULL, 
            0x1B4BA49A26721F38ULL, 0x032AC50293FA1489ULL, 0xCC23270C947252B2ULL, 0xA92D9FE56880183DULL, 
            0xF7E55D87F0B033C2ULL, 0x71EC9A4373C7885DULL, 0x7A0ED15589555245ULL, 0xBCCE48A04C7EEB5EULL
        },
        {
            0x0EDBDC327BBF46A7ULL, 0x24ECB0F0DB25DB8DULL, 0xE35A7D3B38038132ULL, 0xF99C4CD2042ED8FFULL, 
            0x9BAFDFAD4167323BULL, 0xBBDD2B45326FE586ULL, 0x4F7334C27590C21DULL, 0xD9BCA3CB448C7099ULL, 
            0xBCD8474BE946BB8BULL, 0x82F0850BC4986A10ULL, 0xE0BD35D1CD336BAEULL, 0xB3ABBCE68B946818ULL, 
            0x40D7836578BD5627ULL, 0xCD40E77DE7A57EB8ULL, 0xAB1494566C2F6C84ULL, 0xDAFB866D9D46076BULL, 
            0x95253D63B3AEDCC8ULL, 0x7F526621DA95235FULL, 0x0F45FF754517C572ULL, 0xF4F7DCBF5A21F807ULL, 
            0xAF25C1B427992972ULL, 0xCFF1D56EC5F614C5ULL, 0xA0A98FEC044C8817ULL, 0x6076A5306A0D5335ULL, 
            0xF5BA109791617072ULL, 0xACE03D928E16C4FAULL, 0x6A028FDDF5AE4114ULL, 0xE6C1D12668279320ULL, 
            0x23F8D340DC9152E9ULL, 0xCD65BDBD9A5EBB88ULL, 0xE2FA0BC50DE310D7ULL, 0x0FFC9289F538CD1AULL
        },
        {
            0x815EC04F69558E65ULL, 0x164D92859D360E19ULL, 0x44DA182E824D8F77ULL, 0x869CB5B00995DCB0ULL, 
            0xE3A8ED21C645499EULL, 0x04BAB013C16DB92FULL, 0x3B2A73E33CA44873ULL, 0xE03826DE1D6539ADULL, 
            0x241B059F753C2905ULL, 0x01D749D7285AF67DULL, 0x743A1D6C14E19D6AULL, 0xC2EB7600AB1D5E34ULL, 
            0x2D554593D9EDF39FULL, 0x26001F5981F7BC43ULL, 0x84922B193553D593ULL, 0xDABD190D3CE43675ULL, 
            0xED0191375FE9ECEBULL, 0x8EAA4D501EC28EBDULL, 0x482C8F38FC470A98ULL, 0x27BB3DD42C66A932ULL, 
            0x88DC1B09C3E6BC9BULL, 0x33D9BE530B03F780ULL, 0x4BF70504472C10ABULL, 0xA00952097DAC5734ULL, 
            0x1ADF7C7C60382039ULL, 0x93CB788C00818606ULL, 0x8850ECA69FEB6330ULL, 0xAB2A7FC225764A13ULL, 
            0xFA68BC8423CE399DULL, 0x6CDC03624A044595ULL, 0xDFE90EACF2A215C2ULL, 0xFF6080E65EC69138ULL
        },
        {
            0x577297D368085E0DULL, 0x49A69F763A8E6DC0ULL, 0x7ED71AE87DCE309AULL, 0xEA40FE6DAB0E2FDCULL, 
            0x93E7BDE6EA9C9C56ULL, 0x5F0133593586BFADULL, 0xDF46D817F8DFAD06ULL, 0x6F43F5E093441487ULL, 
            0x0462E219D34BCEB1ULL, 0x904C41A351331087ULL, 0x19C7DC14F2DE0046ULL, 0xCA0C35E6D57AAF51ULL, 
            0xACEE7DB76637B96CULL, 0x00460429CC8EE88FULL, 0x1E25A7473FF95D32ULL, 0xC1F2DA5A0E1F466AULL, 
            0x9D8713867A032365ULL, 0x9848FCEC74867F58ULL, 0x5D414A4EA23B19E5ULL, 0x112581A2C5BD885BULL, 
            0x7AF9996D568FC9B8ULL, 0x3923DF822F164E95ULL, 0xE5A754AFB842D1BAULL, 0xF28E6B6BE0CEF614ULL, 
            0x51C22D23186C440EULL, 0xCAF81383A1A8CD09ULL, 0xA1473929A2FFBC2AULL, 0xA8867AC57C7599DBULL, 
            0x10D223F176AE93AAULL, 0x9BBCA661F5D5CE3EULL, 0xA3EADDA7A995B08EULL, 0xF949919501DC8582ULL
        },
        {
            0x0328BC0DFDFB9E04ULL, 0x4E6A37A1141BE54FULL, 0x2D0B6268911558BEULL, 0x29BEA3ACA18D479AULL, 
            0x244ADE6E0A40192BULL, 0x2FD55F475D4957C1ULL, 0x8D63DFBF0029FFB3ULL, 0x6F1B84AA71A93922ULL, 
            0xAD458D7FE7346100ULL, 0xFBA84A74F5DB3C33ULL, 0xAF55EE4C72C9861DULL, 0x27FEECD4F74F9236ULL, 
            0x9FE19B949E3DD8D6ULL, 0x0A659B4B7C430217ULL, 0x704E05B7EC868D44ULL, 0xBFA4D1084F4C7BB1ULL, 
            0xCED571E68F2FB006ULL, 0xAF944746194D7355ULL, 0x40E51A341C603A3FULL, 0x4EDF4C1B080DA38CULL, 
            0xCF11C8C7A0E473EEULL, 0x5855EFE31DCA25AFULL, 0x8875CFA2D7BE4A04ULL, 0x871C22C5CFE7B715ULL, 
            0x994CA38314D5B4CCULL, 0x30945A1E0B7D3519ULL, 0x221F77C0B7FC5B9BULL, 0x18A77BDCB7D49EF2ULL, 
            0xA4760DF33BE090C4ULL, 0x8935089141BFE666ULL, 0xA82195A0828D558BULL, 0xDF9E7E7ECF4CCBDCULL
        },
        {
            0xC8C34123DA8FFECEULL, 0x796A16865B7C1F2BULL, 0xBD37097398034265ULL, 0x7C66FE951CB57F8DULL, 
            0x3B8FE32E0424984BULL, 0x4B597ECEA668B30CULL, 0xBD3A07DCAAA0B0D9ULL, 0xBBBC29150C9A0245ULL, 
            0xA45F70AD85112DDBULL, 0x90892D60C84F7CA1ULL, 0x544EAB7C5B2A681FULL, 0x8E798EB255A39482ULL, 
            0xCAEC8DDDF9B474DFULL, 0x10059CE57D83D486ULL, 0x0FD45CCDA850EA8FULL, 0x40F00B98397D521AULL, 
            0xC81417F7CD24FFAAULL, 0xA40D09BEF0114CCBULL, 0xDB01E986A4C4E1AAULL, 0x3A9F9193888192D2ULL, 
            0x13CDB24B0042C6FEULL, 0x45BC439B2B169B14ULL, 0x4CB667218AC0C2ADULL, 0xE84F13D6FC209118ULL, 
            0xD807D3AA5BD15E26ULL, 0x270D2FA9D4A5A07FULL, 0x983188724DDB1104ULL, 0x82B86E365831DB4BULL, 
            0x1AE7C41223FE1184ULL, 0x6640021DA99B898AULL, 0x53B228C03AE2F495ULL, 0x363E7F6C93A7110BULL
        }
    },
    {
        {
            0xA82C55D1DEDF856DULL, 0x45085CD881FAA9FFULL, 0x147791DC0284D78EULL, 0x9E6061BE3541BC9AULL, 
            0xB7FB73B42C1B930FULL, 0xE8684C0AC2828BFDULL, 0xAF0BD19B866D6498ULL, 0x3C7A0A1322A34032ULL, 
            0xDA36149A9F430901ULL, 0x2DC16D4D3A24BFCEULL, 0x7B30B71F7B6999FEULL, 0x7395B6186A751510ULL, 
            0x2F8A2BBB092BA890ULL, 0x7745DE523D64B3FAULL, 0xBCC210B282E78229ULL, 0x8D33CAF88E4D07D4ULL, 
            0xE397994F8B68BF3BULL, 0xB552ED0E7A9C5332ULL, 0xF061D76BA2F8543BULL, 0x63265B630D323DABULL, 
            0x594A66B4F52DF4B3ULL, 0xB32483128861A258ULL, 0x87419E4CBB18F9FEULL, 0x4DBA6CAC461EFEF5ULL, 
            0xBF8A5FCA380D5237ULL, 0x44EB61BEFA1BDEB5ULL, 0x7A23D56E912FB4C2ULL, 0x8B71DDACC1312B61ULL, 
            0x382BA2CCE428679DULL, 0x08B4893930E2B657ULL, 0xE4151984ACF4C9DAULL, 0x9E7170C986189342ULL
        },
        {
            0xDFB9BB5B1407CF84ULL, 0x934D0E78000B1C79ULL, 0x260637A34A65DDE0ULL, 0x41C78CABA6DFA64AULL, 
            0xA4AA71D6920A7B56ULL, 0x370CB042CC771A27ULL, 0xDD34919757947AA5ULL, 0x1C283AAC7607E1E8ULL, 
            0xDAF79AC22090A10AULL, 0xB04CD96E4CE02DA9ULL, 0xE8112D0669EED6DCULL, 0x283C81DFE5A0F0F8ULL, 
            0xB1F665C3BC106316ULL, 0x5C5CF1CDB0D607D5ULL, 0x06CD599B8325C58EULL, 0xE891824D78607413ULL, 
            0x3D3D26CDB09AFB41ULL, 0x3519021220C3C571ULL, 0xDCEB19D4E413960EULL, 0x03316A753DA7D340ULL, 
            0xD07B1DAF63B57842ULL, 0xF6D93C53DC12AC46ULL, 0x9B6A8FA209C31239ULL, 0x133664B61C89B116ULL, 
            0x1E3AA65E083CBDB1ULL, 0x8E3F965574309E58ULL, 0x849B6A2EF3B070ADULL, 0xCEAFA39D961895BDULL, 
            0x0D65EE3EFCD24396ULL, 0x209A7EA427348A38ULL, 0x7396EE14A9E6968CULL, 0x229C47DBF10726CCULL
        },
        {
            0x1B44C4815544D327ULL, 0xA9902BF59B0315F1ULL, 0x5019791E0EE66141ULL, 0xAAAB4310D6A7FA06ULL, 
            0x4E737E47633B08A6ULL, 0xB572D89B25664B99ULL, 0xD8E45319B94D3FB1ULL, 0x0513304AB44D2F11ULL, 
            0xAF2397AA6F2F7009ULL, 0x0BFCF2132F110563ULL, 0x4CD2A43BC6546F08ULL, 0xB97ED1366E890D6AULL, 
            0x2DEF292F9322AF20ULL, 0x8E87FF7DD40036ECULL, 0x79046276AF655DAFULL, 0x46F52ABC69DF6394ULL, 
            0x260077E246EE89ECULL, 0x6921E80E2B9534AEULL, 0xB6C679F355CE5F08ULL, 0x531A21807EEF5F8DULL, 
            0xB38B391279E319A6ULL, 0xCE5DB275CEE6582CULL, 0x1048114432F8664DULL, 0x0922E19B5F3DB042ULL, 
            0xB9A786B547606C35ULL, 0x5806859039F6A56AULL, 0xBB9B01A8A0E1CE6EULL, 0x01887C37D51DC6D6ULL, 
            0x23C152621E571D46ULL, 0x09F72824E30891DFULL, 0x26CD9B0328D52A2CULL, 0xCA4E36C714F9B440ULL
        },
        {
            0x0E99F9FFD31D4D5FULL, 0x79DDC2B5C0FB5389ULL, 0x69434D261FCD3DADULL, 0x9D595AC1943447D3ULL, 
            0x4689849CE188A116ULL, 0x8E80AA06B550CCBCULL, 0xFFC37F20050C0052ULL, 0x604A813FB7F86FFCULL, 
            0xB05AD09B3211E112ULL, 0xDFF03D8776283108ULL, 0x69F11876EC375923ULL, 0x02B5EA015205AE8FULL, 
            0xF58CA5C689559159ULL, 0x69E382A6834606FFULL, 0x55849EAE2773EFB3ULL, 0x2EFA1CDD966F2998ULL, 
            0xC3A26D47A825A272ULL, 0x573E8E3A4D1501EAULL, 0xD8E1CC9099DB07F8ULL, 0x764F9FBEB26FFC0FULL, 
            0x7C32AB0C16092C23ULL, 0x5DEE5F7F5C8D1BEDULL, 0xB65AA58BBA117B43ULL, 0xD749A6041CC38A2CULL, 
            0xDCCB47708FDD5FA5ULL, 0xDFBBAA80BF6C82E6ULL, 0x4A402523492CE13FULL, 0xB8BC357F8C3EBA47ULL, 
            0xD2D5E77AAD8D3641ULL, 0xB3E627A208ADBCA7ULL, 0x778F727D1E61558FULL, 0x1F4D3A684AF3B986ULL
        },
        {
            0x397D984BAF7A7249ULL, 0xD7EFD201558EFDD0ULL, 0x6D843E6426FA479DULL, 0x3F055A8E65121CDBULL, 
            0x3AA323DAAEEAD870ULL, 0x57119D2468B82CC7ULL, 0xDB2DE452008A94B4ULL, 0x217501BC8FC0F5ACULL, 
            0x6BBCE242FCED4353ULL, 0xDDDDD7AEE92769CBULL, 0x691A9A14C0CE0D5DULL, 0x1997078AE8363F09ULL, 
            0xD813775CDC2489DEULL, 0xB0E78206A67E11DEULL, 0xF2AECA6776E3D612ULL, 0x26B90FEA258A0A23ULL, 
            0x95B86648407D635FULL, 0x94142E2A8AA971FCULL, 0x9D969B53DA691219ULL, 0x7DC01144D89D8805ULL, 
            0xB5A823E6C12C499FULL, 0x0446841DD4C83B26ULL, 0x26DB48A29A84B3D1ULL, 0x224075BE75B18527ULL, 
            0xAB3B72893A3F47D6ULL, 0x2C9D3E7157DC66DBULL, 0xFC4E034E7B46F41AULL, 0xC1A1CBFC20E257DEULL, 
            0x7DFCC366738DBA58ULL, 0x6F29D0FE298C0B3DULL, 0x7ED537E80E456D3DULL, 0x3A21C852674C85A5ULL
        },
        {
            0x1045F70F352BB41BULL, 0xD8E9EE69C6F046B6ULL, 0xA24FC8A3F9466EC9ULL, 0x24DA440685019C9FULL, 
            0x1D938CC49CA0967DULL, 0x02ED713EC96C5277ULL, 0xFF81853F2AA8DB09ULL, 0x5FDCCA6077D1EA29ULL, 
            0x6A58B3F051740089ULL, 0xF64458C71F82D8C8ULL, 0x465507E7DCC71D5DULL, 0xE2FE6E3BE9CF93BDULL, 
            0x8C45765B3C134A6BULL, 0xD36C28FCCC5FDA01ULL, 0x3347950648FB7931ULL, 0x693587140B947A62ULL, 
            0xD99FFF7F4EC5B95EULL, 0x11ADE404B40D0DFAULL, 0x20F6B61A057CCEFDULL, 0x7B5482C95BC2E83DULL, 
            0x6FC44EF9045501FCULL, 0x44EE4FAAF8BD05CAULL, 0x17786B2CDD2D1B27ULL, 0x77D3BCDB3DA1E431ULL, 
            0xB23F4B53D2CECD4EULL, 0x15773EF01DCB783BULL, 0xB6744F99204D9ABEULL, 0x42B73F7A800AEBC3ULL, 
            0x840D72FFB452570FULL, 0x06348D77CAEA278AULL, 0xF72F8FFD13973BEDULL, 0x9E05E4CFE83ACDEEULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseHConstants = {
    0xCF27D070AF1C4464ULL,
    0x48C4F757C8B1A41EULL,
    0xBF3A38CB282632F6ULL,
    0xCF27D070AF1C4464ULL,
    0x48C4F757C8B1A41EULL,
    0xBF3A38CB282632F6ULL,
    0x96356E8191377E01ULL,
    0x10BA4363B6D32DA9ULL,
    0x30,
    0xE0,
    0xFA,
    0xD2,
    0x7D,
    0xFA,
    0x84,
    0xD6
};

