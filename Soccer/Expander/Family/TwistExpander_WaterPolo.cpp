#include "TwistExpander_WaterPolo.hpp"
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

TwistExpander_WaterPolo::TwistExpander_WaterPolo()
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

void TwistExpander_WaterPolo::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xD54E5E53C7507DDAULL; std::uint64_t aIngress = 0xB56C042788F7D4ECULL; std::uint64_t aCarry = 0xCDB2E8812D28F696ULL;

    std::uint64_t aWandererA = 0xFEDD543766165701ULL; std::uint64_t aWandererB = 0xE02D4731AC17AFEDULL; std::uint64_t aWandererC = 0xE6204672F1D18935ULL; std::uint64_t aWandererD = 0xFC5D4F86152C2CA0ULL;
    std::uint64_t aWandererE = 0xDEBADBB954CB7040ULL; std::uint64_t aWandererF = 0xF072F4CC1DF74603ULL; std::uint64_t aWandererG = 0xEFFE85233F1B86EFULL; std::uint64_t aWandererH = 0xBEA016BC340C3CEBULL;
    std::uint64_t aWandererI = 0xD04B99BF9E242141ULL; std::uint64_t aWandererJ = 0xE56043795A1BE7DAULL; std::uint64_t aWandererK = 0xC83FCA3670F5110BULL;

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
        aPrevious = 14862291637298402065U;
        aCarry = 16443112747288669173U;
        aWandererA = 14181608136618795082U;
        aWandererB = 10816770471258551641U;
        aWandererC = 10730080735998827607U;
        aWandererD = 15107047445521316155U;
        aWandererE = 9487965733022974007U;
        aWandererF = 12245336585016882148U;
        aWandererG = 13400649572411857828U;
        aWandererH = 13749082410149514277U;
        aWandererI = 14738951468040163650U;
        aWandererJ = 11212621675015273526U;
        aWandererK = 13084748859898077163U;
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
    TwistExpander_WaterPolo_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_WaterPolo::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x96D1BD559B608DE4ULL; std::uint64_t aIngress = 0x86EE07B2046FCC55ULL; std::uint64_t aCarry = 0xFC94CB540A1A82BEULL;

    std::uint64_t aWandererA = 0xF6E1D3C0A1EF5CDFULL; std::uint64_t aWandererB = 0xBD7E284152848B1CULL; std::uint64_t aWandererC = 0xC1AAA262320C92B4ULL; std::uint64_t aWandererD = 0x918587D6A683EF30ULL;
    std::uint64_t aWandererE = 0xF9159C3E2C1F5B4BULL; std::uint64_t aWandererF = 0xCD2BF827CDDA750AULL; std::uint64_t aWandererG = 0xB82EED463A95836FULL; std::uint64_t aWandererH = 0xDF64A8587A4C6C1DULL;
    std::uint64_t aWandererI = 0xEB181411678C8681ULL; std::uint64_t aWandererJ = 0xCAC4099EC3F0C4FCULL; std::uint64_t aWandererK = 0x9B107D6705086FA1ULL;

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
        aPrevious = 11169864975345339093U;
        aCarry = 9963367386312880755U;
        aWandererA = 18161729416318607438U;
        aWandererB = 14347787931008205021U;
        aWandererC = 9579572625211468259U;
        aWandererD = 15662589480023744731U;
        aWandererE = 13950131548559200662U;
        aWandererF = 10055917748830688350U;
        aWandererG = 12361580785496980713U;
        aWandererH = 14907313933606390927U;
        aWandererI = 15626213768765679851U;
        aWandererJ = 17550912438092811616U;
        aWandererK = 11222673396488161483U;
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
    TwistExpander_WaterPolo_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_WaterPolo::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA69141BFA7D72529ULL;
    std::uint64_t aIngress = 0xD8BFA4ED00793A24ULL;
    std::uint64_t aCarry = 0xE7E60DD7C67429EAULL;

    std::uint64_t aWandererA = 0xE53DE2F6B3CE5A02ULL;
    std::uint64_t aWandererB = 0xE8D8C2D97B4520ECULL;
    std::uint64_t aWandererC = 0x84B0D5915D9034D9ULL;
    std::uint64_t aWandererD = 0x840325C36895BBC6ULL;
    std::uint64_t aWandererE = 0x80F34AFC1F226354ULL;
    std::uint64_t aWandererF = 0xAECDE9D81DCE109EULL;
    std::uint64_t aWandererG = 0xA26AA931A53F4730ULL;
    std::uint64_t aWandererH = 0xDC1434A929CFBB7DULL;
    std::uint64_t aWandererI = 0x8F96882F069F149DULL;
    std::uint64_t aWandererJ = 0xCD717AF99D1A48DAULL;
    std::uint64_t aWandererK = 0xA445781C9229CC26ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_WaterPolo_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_WaterPolo::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_WaterPolo::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8475F0AE38DD929AULL; std::uint64_t aIngress = 0xB2DC63F84980DF31ULL; std::uint64_t aCarry = 0xD13C2C335B1AE38DULL;

    std::uint64_t aWandererA = 0xD92EC86D67B4184EULL; std::uint64_t aWandererB = 0xB5F535DD9DBE04B2ULL; std::uint64_t aWandererC = 0xBE82CBDA4A28D98EULL; std::uint64_t aWandererD = 0xD6DDF015B8B8A7E9ULL;
    std::uint64_t aWandererE = 0xC185139B3DFE446AULL; std::uint64_t aWandererF = 0xB56C4B433F6B92C0ULL; std::uint64_t aWandererG = 0xE487C90402B62A3EULL; std::uint64_t aWandererH = 0x8B423D1C58792CAFULL;
    std::uint64_t aWandererI = 0xD6F93ACDD93BC9F3ULL; std::uint64_t aWandererJ = 0xFFA04F900D09815DULL; std::uint64_t aWandererK = 0xD4FD2B71C4E69375ULL;

    // [seed]
    {
        aPrevious = 9783675912413763707U;
        aCarry = 12009090230606341690U;
        aWandererA = 10807079193652500755U;
        aWandererB = 15143376319918014553U;
        aWandererC = 14982664640907799028U;
        aWandererD = 10031371578613927861U;
        aWandererE = 13288840978379292709U;
        aWandererF = 10096677374202478142U;
        aWandererG = 11814713953478548037U;
        aWandererH = 15878852494825187969U;
        aWandererI = 18361048472660869338U;
        aWandererJ = 12057586296132578941U;
        aWandererK = 12809495229868328897U;
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
    TwistExpander_WaterPolo_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_WaterPolo_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_WaterPolo_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_WaterPolo::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 0 with offsets 5653U, 7679U, 5665U, 7467U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5653U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7679U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5665U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7467U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 3 with offsets 5749U, 5227U, 2890U, 4395U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5749U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5227U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2890U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4395U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 1 with offsets 1435U, 3970U, 4428U, 3813U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1435U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3970U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4428U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3813U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 2 with offsets 5127U, 2330U, 3983U, 2503U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5127U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2330U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3983U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2503U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 with offsets 1357U, 161U, 1961U, 667U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1357U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 667U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 3, 1 with offsets 720U, 1855U, 1771U, 1704U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 720U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1855U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1771U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1704U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 2, 1, 0 with offsets 928U, 801U, 1650U, 551U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 928U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 801U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1650U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 551U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 1036U, 211U, 1333U, 75U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1036U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 211U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1333U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 75U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1927U, 426U, 1516U, 1663U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1927U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 426U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1516U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1663U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_WaterPolo::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 1 with offsets 3491U, 3380U, 5913U, 2848U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3491U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3380U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5913U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2848U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 3 with offsets 5054U, 1031U, 6726U, 2995U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5054U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1031U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6726U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2995U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 2 with offsets 6311U, 2411U, 8011U, 6032U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6311U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2411U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8011U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6032U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 0 with offsets 7750U, 460U, 2528U, 2464U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7750U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 460U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2528U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2464U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5173U, 3116U, 1722U, 5701U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5173U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3116U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1722U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5701U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1759U, 527U, 1952U, 1814U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 527U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1952U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1814U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1919U, 767U, 865U, 1543U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1919U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 767U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 865U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1713U, 1122U, 690U, 912U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1122U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 690U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 912U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1116U, 1842U, 1979U, 1031U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1116U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1842U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1979U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1031U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 [0..<W_KEY]
        // offsets: 1846U, 247U, 1592U, 62U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1846U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 247U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1592U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 62U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseASalts = {
    {
        {
            0x547C1CECDA240049ULL, 0x7D4106E32FAE33DCULL, 0x3A015469060A6191ULL, 0xC3C75B8FB88DB2ACULL, 
            0x3292C5D135AB07D9ULL, 0xF93FE6D3E175DD5EULL, 0x1F03544B0F7861B8ULL, 0x42185B7242C19BBCULL, 
            0x6AF5070BE34071BAULL, 0x67C6174D98BE550CULL, 0x6C68D74FCC5263CCULL, 0x69F1F4A87087ED6EULL, 
            0x951DE244CC7D59D5ULL, 0x7A7B95E5844BA653ULL, 0x9C627C0288931718ULL, 0x50BDACDFFE6E79EFULL, 
            0x180A2A2A7E5EBE52ULL, 0xAA4E298540CEAAA1ULL, 0x281855937D6FDCCBULL, 0x923C764B583B93B4ULL, 
            0x392E0716931A769BULL, 0xF7A5B19676C5AF90ULL, 0x3B794C238A97FAD6ULL, 0x7FB876F13BE71962ULL, 
            0xADD5947EFE615969ULL, 0x923EB751A7104736ULL, 0x2BD9B4DE2BC73D85ULL, 0xD52514E8B4F5FBE1ULL, 
            0x195388D2C58F3A39ULL, 0xADD2D259A5304D2DULL, 0x890879447147B57AULL, 0x70533EEA0A8A04A2ULL
        },
        {
            0xA4E2300B78164897ULL, 0x8857E0F6A254136FULL, 0x6C6AD5D1D8269F93ULL, 0x390B6B070F8FC101ULL, 
            0x6A7579D090844D05ULL, 0x0743BB4D7AF183A2ULL, 0x39F0F3A806E57343ULL, 0x9377C8DCF4FE3541ULL, 
            0xB031E89FF8B57050ULL, 0x71BB9D641578E8C9ULL, 0x767212A5B8BD9228ULL, 0x1BCD00BEC37DAB58ULL, 
            0x60CEB1F16EC71958ULL, 0x23436904F73C67B5ULL, 0x7A7B80314FA77EBFULL, 0x51E2ED86677C5F64ULL, 
            0xEC2C81B44FA755D9ULL, 0x34AFC2388C9F4056ULL, 0xBD05263496FDA804ULL, 0x45564891DF2ABD68ULL, 
            0xF3AA2B11DFB9797CULL, 0x23975A26542FFDAEULL, 0x5740C25057545FF7ULL, 0xD4B7FE3F7304A072ULL, 
            0x65876F2475EADDD1ULL, 0xBBBBD95555C8510EULL, 0x29C1A65EDB233900ULL, 0x096DAC60B0509125ULL, 
            0x3EC26CDBFCF12C0AULL, 0x40B6C6F489E98F59ULL, 0xCC69F1F2D6C5305AULL, 0x86B25C116C61F1E6ULL
        },
        {
            0x0C5B6B4C83D04247ULL, 0xF48F4D3848117846ULL, 0x308E7C400FEA4A9BULL, 0xFF6689EB820CC27EULL, 
            0x5FADF427F92EBE9AULL, 0x4D9809531579387DULL, 0x74A64CEC272190A5ULL, 0xDAE978933AEB7FFFULL, 
            0xF19B5F86D4E701E9ULL, 0x0EA638345E274EC3ULL, 0xA8336CF05B32FB89ULL, 0xA623AC12311EA439ULL, 
            0xAD4641AB3E3F96BAULL, 0xB0AFCAD0CE7EC548ULL, 0x5E8876C778BA85D5ULL, 0x197DB132471177D6ULL, 
            0x86A488EA3724A1F4ULL, 0xD25DB4EE89EAF3B5ULL, 0x4B9C608C707D21FDULL, 0xF45E152F9046849EULL, 
            0xA9026E6941D4CA04ULL, 0xAEEA0CDA5E8C0DA1ULL, 0xC38B8E5BC58822F4ULL, 0x62116A37FC079235ULL, 
            0x7C93C1CC27236ACEULL, 0x5DC2E5BEF9ACFA65ULL, 0xFBC77562B1BEE4F2ULL, 0xC0341CD28FC5A325ULL, 
            0x85F8FB1915BDA0B3ULL, 0x2CA8FD3653921383ULL, 0x3FA5CAADB28403C0ULL, 0xE64FADB447F2D3B9ULL
        },
        {
            0xF4028033C512CFDFULL, 0x5F24296130003822ULL, 0xE44E4C551C819751ULL, 0x1E073F3E7549B52EULL, 
            0x167A2AF327FDFD1DULL, 0xE3A3025AF019FDD4ULL, 0x99B2F49BF1DA6C6AULL, 0x3BC9C7DAE5FF4FFCULL, 
            0x4E2B162C6CC8CC82ULL, 0x41077941DF4E4C14ULL, 0x107C63DC37C70510ULL, 0xD47B29777BB0A1DBULL, 
            0x01383145B86901E2ULL, 0xA9C042B2E408A965ULL, 0x5A2F8B33886C4E3AULL, 0xA97F54399C9DDB9DULL, 
            0x93EDF134F916D7FDULL, 0xDDC382BA1298BD3FULL, 0x2A98B0A4CB485D3AULL, 0x07D92630BA13EB8AULL, 
            0xC167A4641A733BA8ULL, 0xD989B40D8138CDD0ULL, 0xA7E7EA0F18697F1EULL, 0xF9D07CD5DEE26214ULL, 
            0x31B03C0A5B2B6743ULL, 0x89488BCDC7861072ULL, 0xF049089D10F78D03ULL, 0x521D7DE17C49352DULL, 
            0x138C013B40F6CDD0ULL, 0xBFC0C35EF0B6FB5EULL, 0x01BFBA8A60B1757AULL, 0xEEABE85AE9579165ULL
        },
        {
            0xC4E452C602A0A55CULL, 0x4F252EB1F6C54865ULL, 0xE76F1D9D9D3DCBFAULL, 0x584FBA0CA446302AULL, 
            0xD9F3C3B584DC2CD4ULL, 0x47688AF41CFDD032ULL, 0x0A75F6175369B92FULL, 0x47660A406B429EE2ULL, 
            0x7A646EFB13ED3F95ULL, 0x47666DDAE232D62DULL, 0x1F0B88497BA2B329ULL, 0x5F0EDE3C9573F531ULL, 
            0x2FC2367E0643C22FULL, 0xCF50B6C3FC1B6894ULL, 0x6274B79D3AAF8DE0ULL, 0xA72DE17E55BC766AULL, 
            0xBBC516E3E490374EULL, 0xB325F197D1D19FF6ULL, 0x8B7DE237E8F08881ULL, 0xCAD1406D51CE0566ULL, 
            0xC52141679DC680D7ULL, 0x2262F8FCE1E8F783ULL, 0x0B52F68FB173560AULL, 0x433C5B3023E2F24DULL, 
            0x50D7A5C6CD0BC8B3ULL, 0x047C0FCE6EB66EA8ULL, 0x7155196FE623D6DBULL, 0x1784C6114866DEBFULL, 
            0xFBBA99D4F27389B4ULL, 0xA2C65D1D65D07E14ULL, 0xC8435726E4396574ULL, 0xCA3D1D3F435DEDABULL
        },
        {
            0x85B88DC65626472EULL, 0xCF8B8DE721811786ULL, 0x20CECC74C8BAD227ULL, 0x36827DCBB218C473ULL, 
            0x90BA988A330DB631ULL, 0x78431DDDFFC55E69ULL, 0xB634F77961B2C225ULL, 0x4AF35C879A726336ULL, 
            0x6D48AF8B90762E0BULL, 0xF72B9563988B4A3DULL, 0x3AD7A32105A1C398ULL, 0x0BD5566F62E97C36ULL, 
            0x0C91E89EEB050FCCULL, 0x046CDCE0FE4A6ECBULL, 0x664F0E083EB85FEDULL, 0xED06417996A05E3DULL, 
            0x89A4BE709EAFF2F5ULL, 0x998B6C0ABA0287DBULL, 0x6D56BDE6B1DE6825ULL, 0x2B4BF57F4A1F9E99ULL, 
            0xF406C406740C16A3ULL, 0xC48081197D71E065ULL, 0x6794B66DF69BA36FULL, 0x281D75CBE169F1D0ULL, 
            0xB184D00B7F54C0F9ULL, 0x1B019AD8E1570862ULL, 0xC86CF3B1D9755BC9ULL, 0xECC1B7B3BDC5556FULL, 
            0xF73FE5EE2F7D6362ULL, 0x1CD0EB49A63BABC1ULL, 0x88510DD2152C2FBEULL, 0xD165E8732D4FDEF5ULL
        }
    },
    {
        {
            0xA30FA9BC45791A52ULL, 0xF78ECC084B3AA2DAULL, 0x8DC3AB69015CF953ULL, 0xB33FC794CF252167ULL, 
            0x9F111C795A643008ULL, 0x4E9B2C31D1260837ULL, 0xBF538E88C5064F96ULL, 0x4B0B7C2122C2F3E0ULL, 
            0x20E08614D5A68067ULL, 0x970E09E4CCA345A6ULL, 0x6CE371E3C6C81448ULL, 0x6C1B1FBC899CEE9BULL, 
            0x787E69BCA0C05032ULL, 0xB5CA1E5CED3B291DULL, 0x4778404ED6BF96E1ULL, 0x4E09B85731E46B97ULL, 
            0xE82C29A00A062CA4ULL, 0xC2F9899A2BD9670DULL, 0xD6309408F50386DEULL, 0x8B125E998FE5B046ULL, 
            0x26EF988BC37988D3ULL, 0xCC8081D8D4D85B1CULL, 0x91D54CDEFA5458E5ULL, 0xEB8739C5C2A78641ULL, 
            0xEFF09FF6B6434F0BULL, 0x8D7BD69E30A9A58CULL, 0x26930EC6DBB891A8ULL, 0x7809ABBFC671D586ULL, 
            0x096525826248AD98ULL, 0x4D099D61E842AC23ULL, 0x974E25D3BD25AE6BULL, 0x360A8F715C089403ULL
        },
        {
            0x4500709811B9B673ULL, 0x78B38DCA13946BAFULL, 0xEACFAAD1361FDF08ULL, 0x19CACB7003B12B36ULL, 
            0x2943EA9F77B70BC4ULL, 0xD28474AA8BFBD806ULL, 0xBF0BF5DB357736E4ULL, 0x5AEE44FA258603ECULL, 
            0x5816E8E1154B64B0ULL, 0xDCA96B75A875DBBBULL, 0xCBD06E5EE5BC2F5BULL, 0x8EA4769EC7FFB55CULL, 
            0xE3EEEA74373D01EBULL, 0x83DD482E115DBFBCULL, 0x3E6B52257CACA9ACULL, 0xF4BA25EE5EDA8D0CULL, 
            0x2DA8065EACA771D0ULL, 0x93991D8133B33840ULL, 0x4ACF04CB680930DDULL, 0x269B94ED59BF8962ULL, 
            0xC109E882E9530F51ULL, 0x3BF7875AE8ECCFC5ULL, 0xE18C7D5D962E6F6FULL, 0xD83EA971589412C9ULL, 
            0x2E8C20C7D85DA5EAULL, 0x79412A208DB77217ULL, 0x6EC31A60388CF1FCULL, 0xF39C1FB5A8D37A1EULL, 
            0x30F880F966F97592ULL, 0xEE88ECF0510B8A4CULL, 0x1F7FE4305363BAE8ULL, 0x5431AA015B03A3A3ULL
        },
        {
            0xAE65E64A9712CDA0ULL, 0xB8C75A868E6918F0ULL, 0x659E3D332D70FFC1ULL, 0xA1983A3FEF15492DULL, 
            0x820ADDC758AD2FD1ULL, 0x04C59E37BA6A8234ULL, 0x10F9099D3F219F04ULL, 0x42515939D944FEC0ULL, 
            0x0FE38101E4478D36ULL, 0x267ECFB848F1AEE8ULL, 0x66B7CB9CBA282549ULL, 0xF386646DD2A2E450ULL, 
            0xA570DE8C537F40D1ULL, 0xED047A64AB7C625EULL, 0x5342A03B6122494AULL, 0x1511B9BD55E4931DULL, 
            0x8E1096D2E362723FULL, 0xA93044D084526358ULL, 0x75348753F4E800DDULL, 0x43A96C5C4CA98700ULL, 
            0x7BFF7307C035D7FAULL, 0xD4502F2D6A419B42ULL, 0xA6B0633EA272457AULL, 0x70AC11496EC20EC9ULL, 
            0xA027F97DC6ED5947ULL, 0x3B65045F885B870AULL, 0xFF01923394B87FDBULL, 0xF5E9CC83496BDD47ULL, 
            0xFD0D4E64C0BC759FULL, 0xABDAB7AD8712C32AULL, 0x08F714D3A22E227AULL, 0xAE9E7D42DCCC7373ULL
        },
        {
            0x4B9F020B1B0B8AE8ULL, 0x2CDE4B81A7DDE0D1ULL, 0x39228BB4134AE2B8ULL, 0x832150FA1C5EC2C7ULL, 
            0xB79CBA509DD206F4ULL, 0xE265441CDF1A0687ULL, 0x81D262D2080E8053ULL, 0x3A9EAE4096E07852ULL, 
            0xC3B43F77FA31B331ULL, 0x7551D492500BFB21ULL, 0x90F1AB5D7FB27482ULL, 0x8FF28B1F6FB524BCULL, 
            0x9FBF6419D28F3243ULL, 0xF2681316D7BC598CULL, 0x7565D0CFC2E9080FULL, 0x0B5C0C671DBC7965ULL, 
            0xC7C4EA67BCC269B4ULL, 0xF780471A628B7468ULL, 0xA4587F8026B6ED03ULL, 0x22935E0BCB0C948EULL, 
            0xB42DF5DAB2C49A73ULL, 0x866C2B9D8CCD63BDULL, 0x5E09DF0FEE9A42DDULL, 0xC32154CE5A4A2CFFULL, 
            0x49EA49D6B30F9391ULL, 0xF1042892133B3C6DULL, 0xB5B54BDA882BCC1BULL, 0xCEBCF451E131ACC7ULL, 
            0x26658AB77CD0AB4FULL, 0xE903FD640FF620BCULL, 0xCF249CA770D29A9DULL, 0xB1529EBC93074401ULL
        },
        {
            0x77C9022DA72F0C4AULL, 0x16A833D24037C33CULL, 0x3E3C386B00DF2DF7ULL, 0x9840A601074F481BULL, 
            0x12786EBAADA619CBULL, 0x8CE1DF69BC43C504ULL, 0x921C842F6BAC1CAEULL, 0xD9792EEF135E215FULL, 
            0x93C86BA3AC284747ULL, 0xCF2395AA137095EEULL, 0x19B3454910EBBA3BULL, 0x751B85521AA80A67ULL, 
            0x1B2F84AE7C4C68F6ULL, 0x11103D07296A9104ULL, 0x59935F371C0512A5ULL, 0x41DB34FA83AEABC1ULL, 
            0x2DAB279079277E87ULL, 0xD295C95DE5F20530ULL, 0x380F8BBAA3EC2B19ULL, 0x6A37E7017028D4CDULL, 
            0xFE98EB1A602BEFB0ULL, 0x5C6043CE14B905EFULL, 0x82DDD0A5C39E42F3ULL, 0x7D8DE5E7875F8C9BULL, 
            0x0227B9B36403DBAAULL, 0x35D1990A4D6F8C0EULL, 0x266C5FBEE44A3F35ULL, 0xD841A0B2F1C7B5B5ULL, 
            0xD3334D2FAA598EF8ULL, 0x46318E4234D35963ULL, 0xE215C1CD4C8E3169ULL, 0x67171086FE235E2FULL
        },
        {
            0xD96942CF6F6F838FULL, 0x759C0BEB0C07031BULL, 0x63E37590C9DF33D2ULL, 0xF32944EEF1EFE826ULL, 
            0x18860594CB63E63CULL, 0x05B1063A70389F32ULL, 0x6A0EB0345FB5AF8EULL, 0x4294452728BF8559ULL, 
            0x86457B9D96BF4C17ULL, 0x63789C731F0C6346ULL, 0xE11C9B66D2FB81A4ULL, 0x9870CC0B035F226CULL, 
            0x14FF1EB14A07C95AULL, 0xEB2732285D1AB73BULL, 0x458E265A5F4ABE7DULL, 0x36EAF48A1477D086ULL, 
            0x07AE771150A36ED3ULL, 0xAC38DFB0A07E1A85ULL, 0xC4419ED5C9F8DFCFULL, 0xE037774D4A841067ULL, 
            0x5D0BBBC590F98E6CULL, 0xA5C79D3B1703A905ULL, 0xB88E2A557A104BEEULL, 0xCD55DCD6732EC932ULL, 
            0x5DC85F0DA74E5C52ULL, 0x2E5D717DE38099ADULL, 0x08049D4B7F106305ULL, 0xDE7F0BEB07C85C98ULL, 
            0xE4C498B4049B3DC4ULL, 0x2CB0F20000539C23ULL, 0x24B6D6351E3641ABULL, 0xC81125496E91A9C1ULL
        }
    },
    {
        {
            0xB0E13AE1C0893FF7ULL, 0x2778596B30D4C13EULL, 0x15A52B9D9FD5B91AULL, 0x9A7B611A3620D173ULL, 
            0x71A0F8193598D3D3ULL, 0xB5BAC0B7B8674A02ULL, 0x3969D280DDF4A20DULL, 0x3022C29A44B4347FULL, 
            0x9E355CC70E7442D9ULL, 0x0568C8E3FF48D14BULL, 0xB64ACA07952A2819ULL, 0xB14191F9D548A569ULL, 
            0xDA24415B9E2BC943ULL, 0xD06672A3AAA2DF41ULL, 0x50DB8FF622121784ULL, 0x9F052FE524F94D02ULL, 
            0x7A857F37CA4875EAULL, 0x7F3A4913CEA5B680ULL, 0x5029C6BE554EC4B0ULL, 0x37AC56881F701247ULL, 
            0xC932A98AA72409EBULL, 0x3674BF9585C8206CULL, 0xC64B5D99A3BF8CDDULL, 0x0B75E4FC6A41AE4DULL, 
            0x1BFFEF97191D4165ULL, 0xB9898CF15987CF21ULL, 0x7BEE3C95AFF435A4ULL, 0x5D6441D8935BF265ULL, 
            0x5947228AD5163FEAULL, 0x609AB26F74F65C7EULL, 0xDCA9C976135B86D5ULL, 0xA60599AAF7243E66ULL
        },
        {
            0x0AD2082A2DED8733ULL, 0xD3E3D457AE5A8A04ULL, 0x2A5C320008896649ULL, 0xD3026503A7BA4E12ULL, 
            0xD4ED2D8FE74457F9ULL, 0x381FE2831BF00FE1ULL, 0x400776567F24DC4FULL, 0x35978E0D57C62F44ULL, 
            0xFE4BC241E10BBD4EULL, 0x7821F213593B00B1ULL, 0x7BC2F1F58BCAA0D6ULL, 0x6B2D5449DF065659ULL, 
            0xD49815A41125B7DCULL, 0x659BB6A959DA38CAULL, 0xD061513FF15FF37CULL, 0xC9958C0DC737114FULL, 
            0xB526EE9DBBB555A7ULL, 0x7184909741EDA39EULL, 0xBB03784533B374D6ULL, 0x0D9177BC811E9C50ULL, 
            0xCDD16ACB4D7AA424ULL, 0x864D7FD602E78545ULL, 0xDCB59A87FDCEF89FULL, 0xB092C97BF483C570ULL, 
            0x0AECED126476845EULL, 0x4EAD5F4D8FBC7C77ULL, 0x92721531991DFF07ULL, 0xD6A4F57C95001E84ULL, 
            0x26C9C04E3C21FB7AULL, 0xFA84CAB31F32A980ULL, 0x027A510C745166CAULL, 0x90522C96609E0F6EULL
        },
        {
            0xD0782D6DC4554E33ULL, 0xBEC89092F8DF254CULL, 0x92BB6D7BDEA79F26ULL, 0x5313718B5A022A2DULL, 
            0xD8A56E36B87FBD3FULL, 0x7F20021E82E6220EULL, 0xEFEEE0EF77151876ULL, 0x8A9D04684B0408A8ULL, 
            0xFD053FFF3E745388ULL, 0x774939ADC93FBDD1ULL, 0x548CAB426789A6EFULL, 0x564D93E73EF231AAULL, 
            0x1EF4EC5789EF0AE6ULL, 0x8EE83B277C5CF280ULL, 0x4F6634CE0CE517B3ULL, 0x0E3DE799B2C8DC39ULL, 
            0x664A458716E00C08ULL, 0x935400C1D6AD404FULL, 0x4DEF6A0BFD6CC93AULL, 0x84F922D54EFDC349ULL, 
            0x1961E57B7B37C9CCULL, 0x76F6936A9B5A7E68ULL, 0xFB9BFADCC9BBFF0BULL, 0xB28CD33188B7FE9FULL, 
            0xCB2D5A08F25198CAULL, 0x23586C7FDCCF6773ULL, 0xE42B9F4BCB5BEBF8ULL, 0x00BB016B6D0B67DEULL, 
            0x899F5D18172F92BBULL, 0x419C73987EFEF290ULL, 0x25C590B5D6EEB809ULL, 0x43AF0C75E4F8353AULL
        },
        {
            0x511DB315E3B844B1ULL, 0xB0A7E44DAF107E5AULL, 0xDC6812BED04CADB6ULL, 0x104E939E8CC825DFULL, 
            0xBAFDE35DF7FA4763ULL, 0xBD215300BA11BD08ULL, 0xB58DD8FBE48B4CCEULL, 0xED2BCA0A0DA2A638ULL, 
            0x4208B39B3E368002ULL, 0x0CBB20B81964D3BAULL, 0xE2B2626DA4E05A82ULL, 0x819DF6DE55583E56ULL, 
            0x3FD6FB08D530E70FULL, 0x833936D34FA0A54CULL, 0x9A80F54015EA598CULL, 0x8860CA638C8A117AULL, 
            0x97315288230B87BBULL, 0x0EA6BE1585BA1DF7ULL, 0xDDF31E38329E0F93ULL, 0xB9008ABF8BF60CADULL, 
            0x36B6C1C409829404ULL, 0xAC9E42123509178FULL, 0x25621735C67760F2ULL, 0x36E6A826D749D395ULL, 
            0x54CBFA5B8500FE6CULL, 0x5BF9F383B150F4D4ULL, 0x9E99337A0BD30285ULL, 0xB5A2D5852C47D128ULL, 
            0x92495F5DCA203BA4ULL, 0x000085F11F3AE506ULL, 0x26BFBD2910F8E061ULL, 0xFB41DD8A8A3E215CULL
        },
        {
            0xEDDE7198EF5BC7B0ULL, 0x9D1DAE1CC133F94AULL, 0x5C9E7044A1C7FEECULL, 0x2A7BD8A5261FD613ULL, 
            0xCD6867FAC2675841ULL, 0xD02AE64A2266F675ULL, 0xAEA41A182249C3CCULL, 0xCE440F319459B398ULL, 
            0xCA18F693845C8F4BULL, 0xC80B45312CD621ABULL, 0x65C8B7235894B478ULL, 0xC1799A741FD959DCULL, 
            0xB4E5C38B6F8798F4ULL, 0x7B6528EA272CEA92ULL, 0xE12179B9778A87A0ULL, 0x8B7C6D4D5194B786ULL, 
            0x11ABA40260CAFDB2ULL, 0x21E29F85014C5620ULL, 0xF47449E9CAFE7FB5ULL, 0x4675258E5ABA1DC4ULL, 
            0x9018C9F1E45ECC09ULL, 0xA6FB82BC888D887EULL, 0x0237ABE6E6BC1BE2ULL, 0x213135F5DD855A08ULL, 
            0x048859887E77D17FULL, 0xFE75278124A68C7BULL, 0x1F64405959965C4EULL, 0xE746F48DE897CA1AULL, 
            0x7ED27982075FE352ULL, 0x8A446195F009CBFDULL, 0xA21D4BBE70DA074BULL, 0x7449E5B9DFD67B6FULL
        },
        {
            0x18E84DCF13952FE4ULL, 0xEC0C89A8C99133DCULL, 0xED478500E95D6D81ULL, 0xD4A925F7C162C8A3ULL, 
            0x5E7F83D52A73463DULL, 0xE182641B3D811680ULL, 0x7E69A1F5A5B8C9BEULL, 0xB20D1381A1F18C38ULL, 
            0x901D4E466C6BA9C1ULL, 0x6D1A3291F8BC17EFULL, 0xB5A072A9E166257FULL, 0x41F82FFA66104945ULL, 
            0x2162AA121774CC42ULL, 0x33C46A9E3383E72CULL, 0x0D77BF27B5458931ULL, 0x12779BA50F32F42FULL, 
            0xE63429821534BB61ULL, 0x2BCE5B70B50BCB21ULL, 0xDD0CAEECDEFF15E8ULL, 0xE17920B8025D1AE0ULL, 
            0xA67BEB6DF9BF0FADULL, 0x0EF8FC3560C50A20ULL, 0x9C707392BA2956EBULL, 0x737502E37584D642ULL, 
            0x6DB2E80480F8D36CULL, 0x1E9104DDEF5B5ADAULL, 0xA8861CBEA511C3FAULL, 0x6462CECF2D149318ULL, 
            0xF29457AB589FCF64ULL, 0xAC523321EAB16BFCULL, 0xF935A0440C9FBEBDULL, 0xCDEFC7CB5AE62BC1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseAConstants = {
    0x39D6505900EC9CC4ULL,
    0x55454AEB86253C07ULL,
    0x9D8F7A5C8599AC77ULL,
    0x39D6505900EC9CC4ULL,
    0x55454AEB86253C07ULL,
    0x9D8F7A5C8599AC77ULL,
    0x0C06344A69A39454ULL,
    0x7DE83309B8040CF2ULL,
    0xDB,
    0x82,
    0x96,
    0xF0,
    0xD9,
    0x3E,
    0xE5,
    0xCE
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseBSalts = {
    {
        {
            0x4AD7F3854027E2B7ULL, 0xA3DD73A89995B65DULL, 0x7FE19FA9FDDBAA84ULL, 0xF6B7E395FB3C8AC6ULL, 
            0xB24512C6F67C7430ULL, 0x443431871B2B2748ULL, 0xA0EAD12838234947ULL, 0x0ED07A7DDFC01A0CULL, 
            0x68890B3474301AD9ULL, 0xE365EC232D414E5CULL, 0x1F3D71C4CF1E1C5CULL, 0xC2B744040BE33811ULL, 
            0x0BD9C40B9D335707ULL, 0xA79F24DA91237854ULL, 0xDC1D2C4A2A170194ULL, 0x4B82D3E81CF7DA11ULL, 
            0x378597F568F3318BULL, 0xEAE57B6CF21C2114ULL, 0xF87D94DE61267CF8ULL, 0xB13AAD5DB47031C2ULL, 
            0x165F92FE60CD12F6ULL, 0x02687D80086E2C4EULL, 0x67AF205950CEC5D0ULL, 0x51912A35BE58046DULL, 
            0x3EDBAFDB49B3C2BAULL, 0x877252B367D0B748ULL, 0x109E81A74E52AD52ULL, 0x9FBD0CBC171B3A99ULL, 
            0xAEC3A6C98A6AE6FEULL, 0x12B9B98BD58BAC6BULL, 0xC7090B846A3C8A8EULL, 0x0783CA5C6803A436ULL
        },
        {
            0xC2896D9236785276ULL, 0x50A892A35674AF0DULL, 0xE3C172459D9E1FC2ULL, 0x4B767216C8E6111DULL, 
            0x47B79F8E5FC22D00ULL, 0x7ABC77FC74634EB8ULL, 0x7ED8DDEF472F60A3ULL, 0x5A63EBF6F8487438ULL, 
            0x4327CC8928FCADF8ULL, 0xF29D24F59A5149D3ULL, 0xA86A7FA6AD9B5AFBULL, 0xC369722620B9321FULL, 
            0x78CCE97F80D39BD0ULL, 0x82090EB66FD855E4ULL, 0xC09E08324A7592AEULL, 0x361AD87AF7D4607BULL, 
            0xD342B2EE4C77DBAAULL, 0xF8A468B50285D926ULL, 0x9F657A101C31AE40ULL, 0xA314554EF370835BULL, 
            0x3D18268F9271907DULL, 0xD7A588299E36BC54ULL, 0x010BC414D535D64EULL, 0xCE030888D21F1E6AULL, 
            0x7B35230A49F781D3ULL, 0xE21D90D09FBA904EULL, 0x9394E5EF011E6A32ULL, 0x3E9CE64DDC0C1304ULL, 
            0x07D774A5E057AFC9ULL, 0xFB8B11A9E31700E6ULL, 0x68B4A766C2630C04ULL, 0xDAE50DA9C791822CULL
        },
        {
            0xBED08A09DB237491ULL, 0x6C31BB5DD4866EF5ULL, 0xB34F30F8D744522FULL, 0x8BB0E17A561FE18DULL, 
            0x0A42BD5DB4E48ED4ULL, 0xDB13E3BFFC2E492FULL, 0x503477929E4F0512ULL, 0x16DA979A916D9477ULL, 
            0xA08306E19F16F40CULL, 0x8E60FA90608C12DEULL, 0xE3659EECB8C02F24ULL, 0x923DFD81C49A2086ULL, 
            0x16B2DB38937E190FULL, 0xB7C6B8427B65791FULL, 0xB8D51B42D56ADF56ULL, 0xD0628AF772905A16ULL, 
            0xE06F08A67CCA7F92ULL, 0x50E0E36B6DF9F6B1ULL, 0xB59CACCB15E88323ULL, 0x1BDB9D877638C696ULL, 
            0xC223FE0E1630DA6FULL, 0x1246E5BF003AC9F0ULL, 0x96A43186DD29C3A1ULL, 0xE2DC17FD4D2BF8E3ULL, 
            0x1BEE4EA108BCF901ULL, 0xF3B121A1D29FC353ULL, 0x0A830A8F65A932A2ULL, 0x584A8AB717A33553ULL, 
            0x3C8F072FF0B42B58ULL, 0x3252CFCAD79902A4ULL, 0x4BE70A3096703A56ULL, 0xB263F458330FD00BULL
        },
        {
            0xB2AC16E648F33E5EULL, 0x8F92CE575AA4C6C6ULL, 0x77552EEC5D3D34FDULL, 0x285BDFDEF4D87468ULL, 
            0x2322C32ADB1F68BEULL, 0x1784A34E7FB72570ULL, 0x72970AF7FBBF3976ULL, 0xC3627A865DC21EE4ULL, 
            0xA676D5439B7E735FULL, 0xEFE291C68855F0ADULL, 0xD29A1ACB657D4868ULL, 0x2747D7F5FC4D83D2ULL, 
            0x0185EC09DA8775FDULL, 0x1746AB347CA49DE4ULL, 0x5980376B571C6DF1ULL, 0xF6E44F2E5329F4ACULL, 
            0x82F5195885E4997EULL, 0x71F59928111A591FULL, 0xBC847ABC43636724ULL, 0x3BA622CEFB96ED37ULL, 
            0x48C269190F7831F0ULL, 0x8CFC3C243FDB7A27ULL, 0x43E4A1A5F19075B0ULL, 0x2F8EAD25C02E48F5ULL, 
            0x434E5221D58F71D4ULL, 0xF3AB792C057A2A8EULL, 0x7252145689AA201EULL, 0x9FCC54FEC8DBF918ULL, 
            0x0A387F7B20D2A83AULL, 0xB00A091A37CEB940ULL, 0xB7BFB4F28DDE756AULL, 0x53FA6E315F72B08CULL
        },
        {
            0x0399B7AF53452E37ULL, 0xD0B881BE53C1297DULL, 0xED16EA1AE95F8FCAULL, 0x72E202EB35E56435ULL, 
            0x79B15A858F91B693ULL, 0xB14616B63851FC60ULL, 0x0879716317003DBDULL, 0x6BE0CC510FB9BFA7ULL, 
            0xF27D107CA90717D7ULL, 0x8B3E3972E4C12BB5ULL, 0x130D836FC10C331EULL, 0x4CA25AD3D629DF66ULL, 
            0x991D04AA05E22C11ULL, 0x9F808D281E9B24E1ULL, 0x7EF25AE5220EAAF2ULL, 0xFE13879B9AA238B0ULL, 
            0xE915570845F82A4BULL, 0xF3F272C189681DBCULL, 0xA0A9C6E65AEC46FCULL, 0x2666C730804D9237ULL, 
            0x504F22FA1D68F2DCULL, 0x4D874EE18C3097B3ULL, 0x572E8729CA617825ULL, 0xDAAD402D72FE27B4ULL, 
            0xECB2C563B2642D4EULL, 0x94203A070A6C0924ULL, 0xD2DE2564BB883164ULL, 0xB7E246070257C313ULL, 
            0xC5B2D22209CACF46ULL, 0x3F2DCD31C78552F3ULL, 0x913A01203397DE31ULL, 0x5DF039E1619A352DULL
        },
        {
            0xD7AFC582957B089DULL, 0x4C9E8A9576FD2C10ULL, 0x9E54E5582EB9FF87ULL, 0xE9EEBA7C7B95A770ULL, 
            0x853D9CC7C179C4AAULL, 0x81D1B3602486756FULL, 0x89D3DD64B6536883ULL, 0x862ABA2A6D47189BULL, 
            0x3573BD7CC7F198CEULL, 0x279F91896A0D405AULL, 0x50FE8C9652784834ULL, 0xFDDB5F90436A6F5FULL, 
            0x83A52AD10721503BULL, 0x2299FEF4F9E1805BULL, 0xB9ABA8B8BDD18BD1ULL, 0x277B87955C677316ULL, 
            0xAD2FCC7E89FD92B7ULL, 0x717D1A2461DFDDC9ULL, 0x747FE0FEE130A27AULL, 0xFDF76D4633F8FAF9ULL, 
            0x6D208953DFB30D86ULL, 0x4CF0977702533005ULL, 0xAAFF5E83D1FFDD04ULL, 0x98971852D95D7495ULL, 
            0xE27D2952660923D7ULL, 0xF1A94D2AC1F3DD95ULL, 0x1881B2AD0F0DA87CULL, 0x41CF4CEE37F29B5CULL, 
            0x507C8A0FBD45B491ULL, 0x34FC67B50619D56DULL, 0xD885ABE8F178F6E5ULL, 0x7852AFF3A7C2FDD1ULL
        }
    },
    {
        {
            0x7C592CE43E499F29ULL, 0xD46716B547B68088ULL, 0x2CED10AF2AB34DBDULL, 0x42B4D2BC4F96168FULL, 
            0xB930F36F02137D92ULL, 0xB5E9F5192007544DULL, 0x75028D50DCA8FD34ULL, 0xBEC01CE35560A4B1ULL, 
            0x064538A7DDFB9A5AULL, 0x15885219C812185FULL, 0x387642E97C11784EULL, 0x8010AC8AFEA25121ULL, 
            0x7A14D793C8A79AEBULL, 0x99A33DADE27D8585ULL, 0xFE87600CD29C8AD8ULL, 0x15D80D170C2FCA4EULL, 
            0x7DD4562A74C572BAULL, 0x0142A8FA20F658EDULL, 0xFC95E142F7517A33ULL, 0x897D7024467CCF43ULL, 
            0x62BA8AF84DF422D9ULL, 0xC6CCC433DC5C8F08ULL, 0x3FFB99D80D4E7157ULL, 0x616D888D02109A5AULL, 
            0xAE18EBA1DECA7667ULL, 0xC6BF5C4CBDAC5B59ULL, 0x8A6004E9840E95D3ULL, 0x62840EBD743BDA74ULL, 
            0x2120524D4E530C5CULL, 0x7869699EFD059150ULL, 0x3794D14C524F6859ULL, 0x74FBF7DBD95575BDULL
        },
        {
            0x00877523E340AADCULL, 0x2E189944B2D9D1A1ULL, 0x8B38BF5E149AE969ULL, 0x6A15ABD11C4A5834ULL, 
            0xBF085997F6F886B8ULL, 0x2AC2FA80B910832FULL, 0x2CB25514857F441AULL, 0x46AF83714A084353ULL, 
            0x0A6B710CE56883AEULL, 0xF46F978282FA3038ULL, 0x4DEE686D40AA7DE5ULL, 0xD21874CE28591D91ULL, 
            0xDC9A1D774036793FULL, 0x97FA666F6FD994E5ULL, 0xA6F7F314D9B28953ULL, 0x36E14BC7F3EF3EEFULL, 
            0x08C55B7978256F9DULL, 0x40D897FE2E398ABBULL, 0xF05E24BD2D3B6E33ULL, 0xB5DE8EDEC5CD7622ULL, 
            0x31617AB59D92D2F9ULL, 0x29096B08420AE11EULL, 0xFA6543A9FD7CA62BULL, 0xFD06CDEFFE68A7D0ULL, 
            0xE72BB73AA19CEE96ULL, 0x9D229410D70ED231ULL, 0xB63B8468E3196F2EULL, 0x84248603149D1990ULL, 
            0xE49F3F7B8B448C59ULL, 0xE5FE52B93BA78D48ULL, 0xB114F0C4246EDBD6ULL, 0xCACFF669D58914EDULL
        },
        {
            0x07411B7CE69075E8ULL, 0x3DE237504927991FULL, 0x392A106DDD8BCD89ULL, 0x15B25A0FC220CA5AULL, 
            0x0BEF564BDFEFAA1EULL, 0x7ADD293071B45762ULL, 0x6C30E48A24F11D09ULL, 0x89C1D80EA11885F3ULL, 
            0x5328E09AD60CF7ABULL, 0x9AE33407461B8985ULL, 0x2684B6B661B04D9BULL, 0xEAAD7913755D4082ULL, 
            0x4D6EBDCE708B3203ULL, 0xC0AF54416500537EULL, 0x1B5243B6BEC646DFULL, 0x015B015D9EA2B541ULL, 
            0xC273BA91984F20CBULL, 0xBE625E99006AD1AFULL, 0xE2077C84DD4129FDULL, 0xEA8A4698FDA90EFFULL, 
            0x7DE8AE31D5B67E87ULL, 0x9B2E7C2A37CB02DDULL, 0xC538BA000F70D746ULL, 0xCFAF933E75D73985ULL, 
            0xF240A11E221844F7ULL, 0x5250FA3AE6F192BFULL, 0x428DDCE8EFDD1257ULL, 0x212DD36E2D495960ULL, 
            0xFE4F4CB33C70C14CULL, 0xBB2A4B5412DE0A3BULL, 0x1EED6EC86D75C96AULL, 0x7C33E7CD6D8AC346ULL
        },
        {
            0xD30AF62C6ADF2BC5ULL, 0x0E88FB36E7FF8E7DULL, 0x971801FD0609829CULL, 0xB95D7CDF17F77CD7ULL, 
            0xFD3625AF978CFC58ULL, 0xC97262E138CF1D5AULL, 0x92B13E585FFC4087ULL, 0x4FBEC7D212CFF806ULL, 
            0x9EFB77C44AF066DBULL, 0x9F9FFAAEC92C9423ULL, 0x07CE35E8686DB6DBULL, 0x3FF3E4EA2C5B01E2ULL, 
            0xF7BEFE7DD82F13EEULL, 0x1640AD687A077E78ULL, 0x73E2B29FE8004D86ULL, 0x1F0EC9D2EEF08851ULL, 
            0xBB4A468D44EA1C88ULL, 0xB1E0B74B46F4E404ULL, 0x33D53546769A6081ULL, 0x2BF8A93C7F197AA3ULL, 
            0xE6884523C012D93DULL, 0xCF5FE95C78FFCDE5ULL, 0x6A35420797854A0FULL, 0xD114280D7E0BE4F6ULL, 
            0x305AC87B5D4D1E41ULL, 0x2444C0AABE157BA1ULL, 0x9D2E5D5E73BFB473ULL, 0xC1A36C4B983543F7ULL, 
            0x5E8FA9A6D82BC27BULL, 0x23770D755DAE930FULL, 0x2721AF80B89909D4ULL, 0x7C9EB0C8FBD1BD03ULL
        },
        {
            0x78DA130E6B46CC6AULL, 0x13587C5BDE65A1E0ULL, 0xC2D89313FE151A40ULL, 0xC6F1EB395673B26AULL, 
            0x5527A5735A060D3BULL, 0xA2851D8A3759734DULL, 0x9DFE3FC5A9576F5DULL, 0xE69B07DED766280AULL, 
            0xF14F39E2F2328142ULL, 0xCC069168C3A8FDDFULL, 0xB645BBF7D845DD72ULL, 0x6E33B4F66B03B985ULL, 
            0x2FF5A437F79B8BEAULL, 0x662A3C3FA4321A4EULL, 0xEBF1870C0D64FAB1ULL, 0x4A77F83D74F45C4CULL, 
            0x8D48EA57901E790DULL, 0xEE814F64FDDAFF46ULL, 0xECAFE83D7821BF68ULL, 0xBA4E69A48788EEDFULL, 
            0x4E839B6262A9D481ULL, 0x832848E2006F51B0ULL, 0xA5DCE9653ED11678ULL, 0x03FBACB67E208B4FULL, 
            0xF14EF734A2443079ULL, 0xCA4640475C770B13ULL, 0xC5E152AD390AC4AFULL, 0xA144D5AA2481C4B4ULL, 
            0x293560C4B892252EULL, 0x6E9A430E0ABF061EULL, 0x2C5B365B6E4F3E07ULL, 0xB7EA7DDDBE7AF04DULL
        },
        {
            0x20625F8F73524F77ULL, 0x9CA166483D0F5794ULL, 0xE7B18AC420E288F7ULL, 0x001F57D9F8E83BA7ULL, 
            0x23A5C99D9B29162BULL, 0xED5E86ADC36086A3ULL, 0x2A53D85A552BA0CEULL, 0xC4A21FF25772841CULL, 
            0xF176FBC10DCA4C19ULL, 0xDAF30CBC68925348ULL, 0x90D7CB6D161ABF4DULL, 0x32A66C8C5AE98911ULL, 
            0x31C3EDC776F9C236ULL, 0xD0841098A9B4AA62ULL, 0x901996181AC54392ULL, 0x5BB80351CAD46C71ULL, 
            0x03A9400AB34B27CCULL, 0x3FB1999500F4A017ULL, 0x2767BB27333BF027ULL, 0x5FEDD988C91D49ABULL, 
            0xC6EFFF08B06051E1ULL, 0x3993CCB8E3283F4AULL, 0xE3A6A3658ADBDEF4ULL, 0x6ACB155328B25B06ULL, 
            0x9720C0889A4CE08BULL, 0x7B70A0E22BA1A994ULL, 0x8C2AE7BF2F4814EDULL, 0xA7858893B84175A7ULL, 
            0x0887F37AB2046702ULL, 0x2F67847746E4EE10ULL, 0x3657697701464D2DULL, 0xE6AB30B2A42435C2ULL
        }
    },
    {
        {
            0x7A9EA12724886C89ULL, 0x361D0A108E7A2A02ULL, 0x7B841E3CC3DDF88FULL, 0xDFA1D8BE1639E793ULL, 
            0x6A7E71DC265D3921ULL, 0x90CBC188E28C31ABULL, 0x33CC77291F9487F5ULL, 0x93B28174D4AC4E58ULL, 
            0xDADB0713B82224EDULL, 0x24C41F95CAD09449ULL, 0x2EAF341DCACF7115ULL, 0x3BD6981670DB7788ULL, 
            0x1563EA59139838CAULL, 0xB997851EBB970A89ULL, 0xB24E3A653302F4C8ULL, 0x0F857B9AFBE022F9ULL, 
            0x23317EC53F54A8E1ULL, 0x63AADC9A8C9E3AFEULL, 0x4493F7F618345872ULL, 0x273065344A28E461ULL, 
            0x587D9963C3D00456ULL, 0x7DEB2D867614581FULL, 0x7CECD79581B8AD8DULL, 0x218DD4DBA57ADC09ULL, 
            0x3508C363A7B961A4ULL, 0x5BE51C2BC1412BF0ULL, 0x21C255086A9CEA9EULL, 0xE6EFF19E7E9B35C7ULL, 
            0x9C0AA816C7D725EDULL, 0xAB099DC025A8B343ULL, 0x3E83AD662F40DB33ULL, 0x20D55EED0BC90DBCULL
        },
        {
            0x58714B094AB724A3ULL, 0x1C7F3A3CA38C677DULL, 0xB155F3038E84A52EULL, 0x76CE077C1F3F23BDULL, 
            0xC951865949D9B1A3ULL, 0x83F22CDF93C97C2DULL, 0xA1A267B7AAA02D42ULL, 0xA8A96DC87D354E91ULL, 
            0x48F18F18D549809FULL, 0x87FF261123D01218ULL, 0xE135A2510BECE925ULL, 0xBD9FEDAA6623345EULL, 
            0xE5EE32D47A8EDB63ULL, 0xBA82610B8CA83C27ULL, 0x874DFC7A86B6EFECULL, 0x07AC190FF2A74361ULL, 
            0x1CC4804BCAD7CA5FULL, 0xDA3A34968F8EBEA7ULL, 0x783E2CF73F04232DULL, 0x85010DDA0BF57CF4ULL, 
            0xBFB63F3B2F77F9D0ULL, 0x8B6A8AE6FE7A7115ULL, 0x0D4C8B614C22A124ULL, 0x2E300BAE39585BD2ULL, 
            0x3FF5A90C75D4FAECULL, 0xB447792D61BEE544ULL, 0x2F0324202112897AULL, 0xE5D5FC1046FF02CCULL, 
            0xA35E164F4EA245ADULL, 0x275A4B6B404B0CD8ULL, 0x04682F994894A7D0ULL, 0xE44794D8713228E9ULL
        },
        {
            0x4E5FC992871B6813ULL, 0xE94538F088F456DCULL, 0xC3C86BBBBDDBF107ULL, 0x309A572E2CEE23C3ULL, 
            0x9A8B2B1E6DDAC9FCULL, 0x679AA93FF2939266ULL, 0x8B97DA5CCAEBC3E2ULL, 0x57208122F2C51FADULL, 
            0xCB1C70CA272AE2D0ULL, 0x20A0479E877B17C2ULL, 0xF76F783E80EFCB4CULL, 0x930763B5F75DB54FULL, 
            0xC4FF1733234919C1ULL, 0xB486E211D4843EACULL, 0xA8D32431E632059DULL, 0x0E60B612BD0CDBA5ULL, 
            0xE16CAE72903CDA23ULL, 0xA787F48AFA1CFBDBULL, 0xE5628B51FCD69A22ULL, 0xABF25CFEE0A468E5ULL, 
            0xCBAADF95B1F5F439ULL, 0xC2130F797578FB87ULL, 0xCC9C69766230D75EULL, 0xAA18D4DAACE2F3CBULL, 
            0x68DBA8A510241BC6ULL, 0xD176411F0FAAC4CFULL, 0xBCFA9F43F397E55AULL, 0x2A528BFB3AABD55CULL, 
            0x4AD9D0C031BF88B4ULL, 0x5A0810E1D83B44AAULL, 0x36563101CAC7182CULL, 0x0E203C3DFFCE17B1ULL
        },
        {
            0x8F5C43E9CBEE6918ULL, 0x6DC9CF83B9820A99ULL, 0x22354F9091361022ULL, 0x3B75F04A9C6F8690ULL, 
            0x0452613C483AC0A5ULL, 0x08B5DC2F9DE7FAB4ULL, 0x030B9E6E88B38B84ULL, 0x109CD204250DA8A5ULL, 
            0xFCAAA6E9AE5C953AULL, 0x9CB5B8900EEF4794ULL, 0x9915778B5B08A4BDULL, 0x4E91F8C2E4CF7A99ULL, 
            0xC00DDC19B0BDF954ULL, 0x59CB2CB92ACE5BEBULL, 0x6F2E6E42D409D7EDULL, 0x0A3251DEE75E02C1ULL, 
            0x5C2CBF008511BA86ULL, 0x559D137925633F17ULL, 0x82B3AECDEB0A1DB0ULL, 0xAD50F971C560159BULL, 
            0xCDD09552C898EEADULL, 0x91E619FBF057064CULL, 0x502B475B4D8E35F9ULL, 0x1981631A537719E5ULL, 
            0xD07A49C9965D1382ULL, 0x27E73350BEF61D93ULL, 0xB9FCEFCC08906C18ULL, 0xA829BB84E2FB2E93ULL, 
            0xBC089C35F46C9C77ULL, 0x4E0C1FFB750032C7ULL, 0x78154BB2CEDDBC7BULL, 0x6DAD5264DB4B88D5ULL
        },
        {
            0x4923134467243EC0ULL, 0x3C26C528200BF941ULL, 0x4189FFA306264C02ULL, 0x215B82B6D1441BA5ULL, 
            0x44F70AF1864EA8B2ULL, 0x6A505515BE5FC0FFULL, 0xFD6A75A7B45950C0ULL, 0xC909348251D5514BULL, 
            0x6ABA9DAB31F06DFEULL, 0x47B7DEC883E7AC7AULL, 0xCED0E0BB0366A6EDULL, 0xCABD134C0C349773ULL, 
            0x8E5D18815E144682ULL, 0xEEE3EA6E858F9BB6ULL, 0x9189043207159B2DULL, 0x4C93ACC17D446C05ULL, 
            0x01F56DCE27EB10BCULL, 0x43D95216BA33C1BAULL, 0x069C5835D6F6352BULL, 0xCCF0D6C12FBB73CAULL, 
            0x721245B32745993CULL, 0x6E4E10E506D9404BULL, 0x44238C9A2D6C5606ULL, 0x14DCA60D1A79F25CULL, 
            0xA53C24A4A3F24EC0ULL, 0xB4563E935F00CDEFULL, 0x35775FD2DBBABB84ULL, 0xA536AD9AE2D662BBULL, 
            0xD650A98318F38B9EULL, 0xB0AC7F5AC3CF6895ULL, 0x45A04BAF7F160CB8ULL, 0xA60310883AC83120ULL
        },
        {
            0xE7DA188B47A0D7A7ULL, 0x62E3EB98689AEE70ULL, 0xBBC798568CC38919ULL, 0xF9F5FDD8523B6295ULL, 
            0xFC492CA50030FA88ULL, 0x8865F5AF2FACC1DAULL, 0x08EE6A8336ACF9AAULL, 0x2EF2751CDEDF194AULL, 
            0xD360726360765F73ULL, 0x33EE02CABBD96C75ULL, 0x3D1AEF5BE711D04AULL, 0x4BC315A2AC959952ULL, 
            0x696CBF5C4D91B0D3ULL, 0xB7F04BD22391CC56ULL, 0xFD1D2EAB567757FFULL, 0x900EAFB9F4699DA0ULL, 
            0xD1EF179255015A55ULL, 0x50F2BB04576C4158ULL, 0xAECC5BA52B13470AULL, 0x44CF4691B0854004ULL, 
            0xCA41B73A237C0A7BULL, 0x003B905544AB3B53ULL, 0xC7D4CD45A7BFB88FULL, 0x66A6C63A6CF06CF3ULL, 
            0x8DBFEDBA7D41AEA3ULL, 0xC06EC9061E22E8BDULL, 0x3384CE61CEEB7675ULL, 0x9CBF536B998523A2ULL, 
            0x85F9079B7031B351ULL, 0x380C0746BED3D64AULL, 0x7272B81ECC87240CULL, 0x7AD6A42E886DCE57ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseBConstants = {
    0x3DBE3887A75A89FAULL,
    0xBBB75DDB019C63F9ULL,
    0x02DD4B600AB9AB95ULL,
    0x3DBE3887A75A89FAULL,
    0xBBB75DDB019C63F9ULL,
    0x02DD4B600AB9AB95ULL,
    0x36B5FC2C2EC6E621ULL,
    0x2C86B2DBB5DC59CDULL,
    0x30,
    0x5A,
    0x3E,
    0x03,
    0xB2,
    0xB7,
    0x1F,
    0x71
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseCSalts = {
    {
        {
            0xEA9C6253F5D25094ULL, 0x0408F7BF1A3A6319ULL, 0xA901086E1F861ADFULL, 0x506E5D3D716A5DE2ULL, 
            0xF3F2CC24C9B6CCDAULL, 0xFA26C82C0A4BA310ULL, 0x6FA0ABB902AE1E9CULL, 0xE87EC96D4663FE8CULL, 
            0xF68B9B015032AA1CULL, 0x74520A3F4E0F542AULL, 0xAC5BEF0B786669E9ULL, 0x170708C5BF676205ULL, 
            0xFA5FE8F8599BB170ULL, 0x5283648A2C162DD3ULL, 0x8DE61A41E4AA2396ULL, 0xCC03CD007E43643EULL, 
            0x2DBBBB0A4D5DE642ULL, 0xF1CB273DF2E6EEBBULL, 0xD6473095EE8B83CDULL, 0xBF1651AD8A9FE0ECULL, 
            0x0E7C077124D948DCULL, 0xB0D11187EEBD5562ULL, 0xB589050B01C4684DULL, 0x9116AC8047E411C4ULL, 
            0x88B2C37BE3A6EB6DULL, 0xCF2F12EFAE916074ULL, 0x7E1F0CFA48C0572EULL, 0xED09E1D5DE5690B8ULL, 
            0xCF7C534AA1C89C30ULL, 0x4B1A547F8B8E781BULL, 0x8626F54F51EE2774ULL, 0x730C4643F9FFB286ULL
        },
        {
            0x2FB4726DB41DD1F4ULL, 0x75AA50D598D78A96ULL, 0xD49CC846D549EF25ULL, 0x7569BD8E541D90F3ULL, 
            0x43C160790AB7FB74ULL, 0xB21CE4210A3853ABULL, 0xB91EA6C000CFF89DULL, 0x5C0CF5B8DFD3871DULL, 
            0x170233E2362741B0ULL, 0xA98DF6220CAA7265ULL, 0xB3F1189CB153185CULL, 0x53EC1E96668DB757ULL, 
            0xC5C3185150A43560ULL, 0x9AFEB411E92262CFULL, 0xEA5965A46AEEB876ULL, 0x636E8D6ECDA38E89ULL, 
            0x2E2399C07E763571ULL, 0x951E51EFF41E9833ULL, 0x3B85040A6CDFA9A6ULL, 0x9EA25FDAA1425222ULL, 
            0xFF57E9E4657B7875ULL, 0xA6FBCB8FD32F2E36ULL, 0xE4C8EF1A22009DCEULL, 0xF7CA433D09DF8B6DULL, 
            0x2A3F642617B400F5ULL, 0x32C818E533C20DEAULL, 0x4ED7418837DF224BULL, 0x60BCE80581FA8BC8ULL, 
            0x247B0633917E2A52ULL, 0x3D9EE7A12CA71E2BULL, 0x92471DECC46D2E23ULL, 0x89727871293701C7ULL
        },
        {
            0xAC5DF616CF90ECDAULL, 0x3C663472E1C61374ULL, 0x851736BDA6065530ULL, 0x4884822486A8885DULL, 
            0x61A83CA788A37D9BULL, 0xFB4971DA5AAD40AAULL, 0x4F72157209E2E464ULL, 0x259EA4523368F1E0ULL, 
            0xBE286B79BB889D1BULL, 0x842B41A878965B40ULL, 0x440F5338467545C6ULL, 0x83CEED52E0ECB781ULL, 
            0xC7C20C18285A56EEULL, 0x55EA3E60488C42D3ULL, 0xC38D9F01152A19DBULL, 0x17205AA10C97BC86ULL, 
            0x42B837C2AD7B312FULL, 0x327A98BBC55567F4ULL, 0x3403CE7B7340D04BULL, 0xAD99B5F15035B762ULL, 
            0xDAED54FDAF36BC29ULL, 0x69090235722F1E39ULL, 0x4D33A58E12A648A0ULL, 0x0893986B6A037A22ULL, 
            0xDA7B560044F0D82FULL, 0x55D657FCD557E2A7ULL, 0xF071ECD251BAB347ULL, 0xAAEAE2B6E7010CEAULL, 
            0x8004957140281C2AULL, 0x07191BC6BC748765ULL, 0xC2AC464385F9F01CULL, 0x773D45A31F7516C3ULL
        },
        {
            0x06C11288198ED007ULL, 0xB1DF542787D35781ULL, 0x22E2C73435E128A6ULL, 0x454F8F625F18139DULL, 
            0xB1471769FAC68A5FULL, 0x9C34F7A7328738D3ULL, 0xA754B3EB250D0282ULL, 0x1FC845C7CCACDB8EULL, 
            0x3A57888A24CC4040ULL, 0xF63233C2D931AE24ULL, 0xDE87D790CFAF5BF0ULL, 0xC1B07D2195DA9F16ULL, 
            0x72CE3DC38C374623ULL, 0x6858FA5E95838181ULL, 0xAAF58B6F9442AD43ULL, 0x3EC8E44902F10B9EULL, 
            0xA519F1F04B005C1CULL, 0x5EF808106AFD3898ULL, 0x9DD89588096BEE3EULL, 0x332C2A7575570FB9ULL, 
            0x3E09D303369DEACAULL, 0x14B7BFDCB4A0EA7EULL, 0x38906188CC9D3078ULL, 0xE4F4D9806C31081AULL, 
            0x1360A22B15C3E179ULL, 0x9D01BFA4B9F1DD53ULL, 0x374D53F33E1B30F7ULL, 0x9560397C3AE2DB47ULL, 
            0x8D6DB2C8FF0F021DULL, 0xC51B5330E1E11C9EULL, 0xD4622B4BD9CAAE95ULL, 0x860551400F13096EULL
        },
        {
            0xE91B9CEBE68834D7ULL, 0x78BCD9F0C8BC28BCULL, 0x63E5E9280BA8D6AFULL, 0x45C882193534F987ULL, 
            0xB0BA4B7403BB3DC0ULL, 0x35C20378019F16ECULL, 0x0146BE8291D283E4ULL, 0x1263884775CA5D9CULL, 
            0xFE0EEAC195EABBCBULL, 0x7199A7498B817F96ULL, 0x4DC36505443A5EAEULL, 0xDF34C01A6B26FB19ULL, 
            0xD15180DC14D85455ULL, 0xB0F654EDF7327042ULL, 0x305069E3FC74CFC4ULL, 0x6D98282372820DFCULL, 
            0xD6FC086B345AB957ULL, 0xF62182499AA83E08ULL, 0x255F3F97AF75B5EFULL, 0x65978BDB70D30E4CULL, 
            0x60F49ACD5B379E8AULL, 0xD9C59D08D3D9ECD9ULL, 0xA97A7DD692FB6456ULL, 0x021E2FE38A9CD8BDULL, 
            0xA754CF7B968375B5ULL, 0x4534A3AB6C0CF2FFULL, 0x7CDE9D99C4D3C597ULL, 0xE386B0984AA03499ULL, 
            0xF3104F7796DB86B9ULL, 0xE78FF16588ECE3BDULL, 0x659BF161088D9F6DULL, 0xE724A543F579E06DULL
        },
        {
            0xAAF3E13A5C098BA6ULL, 0xA6F6826D4CAAD3AAULL, 0xA2111A98C83297B3ULL, 0x4CC77B1DFB78697DULL, 
            0xF3D709B3EA587D19ULL, 0x79C96D639E019250ULL, 0x40ACD2DC35BFC9DFULL, 0xAC660ECF57708EB7ULL, 
            0xE5AE2B5B9D592153ULL, 0x398E3BEFB09D6EA9ULL, 0xCD93B6D21107B89CULL, 0xDEFA17A4D2FF231BULL, 
            0x2CF367F8CD55E60AULL, 0x38C1F2A00AC3973EULL, 0xE4CE854A7832E4CAULL, 0xADC93C02046C765AULL, 
            0x2FBDF31300CFF7D6ULL, 0x26A28AED0B3E4490ULL, 0xB035C5E6FC9BADE7ULL, 0xAEB6723BC252E6B1ULL, 
            0x248267CE2D00829FULL, 0x7CB4FBACE9F1D1E3ULL, 0x4A393BAAAF883468ULL, 0xA68FCF864F0C0657ULL, 
            0x670F43D07F421E5DULL, 0x1B9E541211E364D3ULL, 0x524DE7EE4220D03EULL, 0x5F6400D4907E1475ULL, 
            0x9338E9FBD7BD05C2ULL, 0xB62E8506D553CE0BULL, 0x026FBEFC982E563EULL, 0x7FCD17DD67FB47BAULL
        }
    },
    {
        {
            0x5317C901D541EA21ULL, 0xC926AB843E398197ULL, 0x00F6B7D49EE68340ULL, 0x98D487D339E59F4CULL, 
            0xB6EA175279708953ULL, 0x3BD02F55D76C5C5FULL, 0x589A9523F4908A4BULL, 0x99B2F782AC7AF8EBULL, 
            0x6C479A6737421887ULL, 0x059B16C0B78369E6ULL, 0x67503FA72F581F81ULL, 0xEAB06F745C027C27ULL, 
            0x65D0979620CE3790ULL, 0xBEB9095300144448ULL, 0x47B692731D00A939ULL, 0xB38AA5333BAA63E6ULL, 
            0xF129402E6BC471FFULL, 0x1E9D81C35012AAD3ULL, 0x55D21A93700778C8ULL, 0x52D8754C195DD882ULL, 
            0x002706092C651881ULL, 0x82E7E9D781B39721ULL, 0xDAAEC82F5AAA2A9BULL, 0x7AF65A71AC89B241ULL, 
            0x13C75D49EF4C5D1DULL, 0x01014B417242C11CULL, 0xEDE880564E4FC864ULL, 0xC10C9255B77EFC36ULL, 
            0xA041ACD178C796C0ULL, 0x048E085683084D99ULL, 0x61ADA0E6B34C8D38ULL, 0x6895D0CF1629060EULL
        },
        {
            0xE15F48DD9E22DA40ULL, 0x2E432A88696302EFULL, 0x4ED6EB91832EAF26ULL, 0x9A5EEC7FA28BEAD0ULL, 
            0xAFAFEDF6ABE8362BULL, 0x2499EBC8705369EEULL, 0xDA5F3BE50EAEE40EULL, 0x3EA09FB0CAC97727ULL, 
            0x37F1DEA7969C5FFEULL, 0x619579E7BAAB5052ULL, 0x633ECB4A8CF10DF3ULL, 0x779ACF16BDD65E79ULL, 
            0x4D9386039A8A416DULL, 0xF7BC869FC73C5C33ULL, 0x316AC8420236D462ULL, 0x552A3F3DDD2A3E36ULL, 
            0x021A24DF744BE56CULL, 0x7E74E7A9B58132CFULL, 0x09AEDA0BADEF42FFULL, 0x2FDEF13BF5D9E1C5ULL, 
            0xDFBEB1BD294DC63BULL, 0xE2DDD7672FDA90C4ULL, 0xFD964C45D9D76958ULL, 0x5A034EDC87427BD5ULL, 
            0x2FD23149C8142295ULL, 0x17C1FE9885459555ULL, 0xE88D5DE4323F4575ULL, 0x596F84DDDBEAE3EFULL, 
            0xE8F8F2CC04167419ULL, 0xDEBAA76D5E28FEBDULL, 0x4942DA5A945E1987ULL, 0x891940A178A4B647ULL
        },
        {
            0x44BB38A73EDEE5DFULL, 0x8D06D026D268FE25ULL, 0xA11D9A20581370ABULL, 0xC560CD1A0B7D537BULL, 
            0x6C29A7AFC931EFAAULL, 0xDA3BF122CF9F95A7ULL, 0x0349C68AD635B5C2ULL, 0x6347AE8802383D37ULL, 
            0xB9B35122CFCC11DAULL, 0xDCCD778251641ABDULL, 0xA4C262D15E242D16ULL, 0xDFC57DF054C7A79CULL, 
            0x141A74B4F365EE29ULL, 0xE457CCA4417E88B8ULL, 0x0F098C60B65417E3ULL, 0x2F3EC4BE22053C69ULL, 
            0x0BCB4B32D1B64D83ULL, 0xE0534F22216FA4B2ULL, 0xE0C1CD27C5CF2F31ULL, 0xAE445C30274F1B53ULL, 
            0x6AEEE9A2B05D6B78ULL, 0x36773AB2BC64B132ULL, 0x3917156571BD3E30ULL, 0x8D2E98F70F64CAD6ULL, 
            0x3B9392B8B292BF65ULL, 0xBE4D1341E8646ECAULL, 0x86698255722B9B1BULL, 0xBC8DD6731E023471ULL, 
            0x36C0AD8F69819762ULL, 0xAA4ACD0CBF82ED1BULL, 0x0260DB3D6AD4495BULL, 0xAF8E72AE02FA907DULL
        },
        {
            0xDB7391A8667D3CCEULL, 0xE85B63C7F3CDB336ULL, 0x68CE16B44C4B8819ULL, 0x0AD566259C238A03ULL, 
            0x91C1CB4FB822B38CULL, 0xAE21349746BD88BEULL, 0x0D99EBCFF188599FULL, 0x70FDAE217174C67DULL, 
            0xF66F15CA99092321ULL, 0xCB6E03E9C186E01EULL, 0x7300922FB588F7D6ULL, 0x03BFB0F16155BEC8ULL, 
            0x3AAEBEEF24953F9EULL, 0x0616AE3D5890DDC6ULL, 0x5831EE34AEB05997ULL, 0x9DF68994B4360A20ULL, 
            0x7343BB09A75428CFULL, 0x144CEBEA7DD46F3FULL, 0xBD4CC813C5EE851BULL, 0x3FBF2D08B6462104ULL, 
            0x4A016129BB18E7DBULL, 0x3C2F4BBFB64064A0ULL, 0xF0223DE170E2F181ULL, 0xCD961230B46B509FULL, 
            0x9EDC0DC4CACD4957ULL, 0x385F2D85DFA8CA47ULL, 0x3E175F09C4F6D10AULL, 0x9F9084AE1117B2A4ULL, 
            0x645BF3E3EB37FCF2ULL, 0xA5AAD6DABCBA41A1ULL, 0xB25931887C277A06ULL, 0xBB9E19D285D7EB25ULL
        },
        {
            0x95C40B037E5B06CFULL, 0x172D1E5CDE8FE442ULL, 0xEBEF958213361AE9ULL, 0xE199AC48DA2FE5A3ULL, 
            0x9D8A26C3DB5609E9ULL, 0x9F4CEEA6D00ECEB3ULL, 0x7DBAFFEAB6268EC4ULL, 0x2BBD7B8675503346ULL, 
            0x911D95AF11B4944AULL, 0x00084A82CCBC4C4CULL, 0xCAAA64AFACB0CFE4ULL, 0xD3EAE9C71E451A42ULL, 
            0x96575D115A258523ULL, 0x1ADDE4D38C4037FAULL, 0x580BB48A53B5AD53ULL, 0xD113E0D72516AAF0ULL, 
            0x053948F43D62145FULL, 0x4AAC706B090CAE54ULL, 0x8A3072237E6AEA27ULL, 0x72858030B54CF30FULL, 
            0xA0A3AF13A20D86A6ULL, 0xFF2D533120C3B99EULL, 0xEB630DF83B09414DULL, 0x0E4E9672147AF6C9ULL, 
            0xB8FE88D0283F855BULL, 0xB0F88C80865B4D86ULL, 0xB4807A68AF703554ULL, 0x3643668B5613D21DULL, 
            0xA4933B0A030FEDAEULL, 0x9ECAB872525297B5ULL, 0x8866B30D81D7026BULL, 0x829DAD362EC66CF3ULL
        },
        {
            0xF21E1A0EA254B95DULL, 0x66C6068B42B96677ULL, 0x1F000292C6CDFF61ULL, 0x4CC7130BD840952EULL, 
            0xB74F75A5FC6C98F1ULL, 0x80E960ED0B26EDB5ULL, 0x7BED2577B8330073ULL, 0x1FD310E86C175AF4ULL, 
            0x0155B8BEE0134D1AULL, 0xECB2D9BF9A8A7C2CULL, 0xDA5EE0766321C182ULL, 0xEA1B965F7026CDEDULL, 
            0xC85864C38DBA9628ULL, 0xDD643DC9E37365E8ULL, 0x9579BDDAC89AC1EAULL, 0x32BC6FA524A4EE96ULL, 
            0x8F20C3D02B26FF22ULL, 0x79F6A33F72B6A089ULL, 0xE865D0DE95C7B4FDULL, 0x15EE3C6A9F174DA1ULL, 
            0x3B61FCD8F8A76C66ULL, 0xF4FB3A8EBEEFCF1FULL, 0x4AAF997FD3ACF3ECULL, 0x925D2509232784E4ULL, 
            0x29678AD374572B3CULL, 0x2BA7945D1BEF9B44ULL, 0xBE92BF845ED83260ULL, 0x9A9BDEDE8244FF76ULL, 
            0xBDE2FBF52ED9B26AULL, 0xD59A6B400819DEE1ULL, 0x0B411B6976D31DE6ULL, 0x11F99FFFB7D5C105ULL
        }
    },
    {
        {
            0x017920D4469AA351ULL, 0xBF41824DEB140699ULL, 0x320E3FCF793B5BCDULL, 0x993646DEA1335BBCULL, 
            0x2B8AAC6CE47F2464ULL, 0xB96C36630CAC2EFBULL, 0x169C7767BE210177ULL, 0x082E8DF13B77F93BULL, 
            0x0F5EC8E8FDF35803ULL, 0x4701C4AF6D1E9B3EULL, 0x35C8E9BBFDE192A6ULL, 0x8D59652BDA3AD75FULL, 
            0x18A2B222685E7126ULL, 0x22157991F46D8B24ULL, 0x25C6A13D8D0CD871ULL, 0x83312AE79048E0A2ULL, 
            0xFD509681710E0BC8ULL, 0xC835526AF7A8220AULL, 0x00C6CD6F09C8596BULL, 0xEFA1FB5B7E7DDBEFULL, 
            0xE55C38869A216FB4ULL, 0x430241AEF7FE88B4ULL, 0xF87651D946E3C9FCULL, 0x5F70FD08B5292F61ULL, 
            0x7D626A4B87DF19E1ULL, 0xD7906C97878E5169ULL, 0x0A753EE43312F22BULL, 0x50E06B87672742E5ULL, 
            0x7875EACDE51A8085ULL, 0x8942F6E51546FB06ULL, 0xDFF92DAE87CFEE18ULL, 0x6FA5F3C3EFBFCD64ULL
        },
        {
            0xFA301E956B6B41FDULL, 0x37EE138D93F5E1FAULL, 0xB79C70A0386C8302ULL, 0x7F5C9E6D0F5F2D5DULL, 
            0xB6F4813210222D5BULL, 0xBA8A40B05ECA08B8ULL, 0xB758D40CED15142CULL, 0x44C6080D481E27D0ULL, 
            0x5F600CEA9D1B4E9CULL, 0xDEF3EDA1D239B0AFULL, 0xF983402E992C7016ULL, 0xDD0EB0B5640863D9ULL, 
            0x9A5A64BDC6906468ULL, 0xD7929D92EB678330ULL, 0xCD937B2B83928CA2ULL, 0xA3CBF16E37B900E6ULL, 
            0x83388B5839F2019FULL, 0x5A5C1BA3AF8A54A1ULL, 0x72AB5F4C881E047BULL, 0xB7BDB668D3AA50BDULL, 
            0xE1D7D3D71F5C9259ULL, 0x9EB0145C33014F28ULL, 0x1141CC5E655E0A10ULL, 0xAAA4D7BA063AC7B3ULL, 
            0xCC685108F6D87BD6ULL, 0xA001192115E33699ULL, 0x195A6CF05729B909ULL, 0x00217EC3A22843F4ULL, 
            0x18D6985C674E9A41ULL, 0xB065282BA662AE4DULL, 0x9BB4B71F856BE96EULL, 0xDE525889292E4E76ULL
        },
        {
            0x7F26590AC00DBB39ULL, 0x8E66CAF9D8EFD28BULL, 0x8AFE7675FA765A26ULL, 0x48F5EB93646B7649ULL, 
            0xFF6F1C2D67C25D2EULL, 0x558713BD00080F16ULL, 0x368BD8DB776D42B3ULL, 0x88C05017D43EA7CDULL, 
            0x7BE6F09CE61E8690ULL, 0x3AC4578F5F732A7FULL, 0xB813E50AF31045C3ULL, 0xA4000BD8FFC512E2ULL, 
            0x62C69238C9F81B21ULL, 0x9AAF5EBEB79BCD62ULL, 0x028DDAC0E3CFD0BDULL, 0x3A5E7CE105547B15ULL, 
            0x777E41149BF4D5E7ULL, 0xCA9571FF034C86E1ULL, 0x35E88C99AC21E080ULL, 0x6DA2BCFF61647A5CULL, 
            0x382FFE421F575491ULL, 0x56C3818F7A9796BFULL, 0x8199D87656144225ULL, 0x072FA07767010D3CULL, 
            0x2EE92119B4BB860BULL, 0xA2FE2D8EA6771AA8ULL, 0x43A7DC5D1046CBAEULL, 0xB71A90B5944C046EULL, 
            0x867C6E2F3A20E9FAULL, 0xAA50E6EE2B9816E4ULL, 0xEE0DAB508D3247E6ULL, 0xE10CB53C3325E048ULL
        },
        {
            0x233B627663F14291ULL, 0x8009C466D20C6171ULL, 0x42E6D6CA77480767ULL, 0x135B17C517FBFEC5ULL, 
            0x60C5455EC8EB56E2ULL, 0xFD63F67317A7696EULL, 0x0D43AE1315E619CCULL, 0x54C710364CC0501BULL, 
            0xFA72485EC2EFBE69ULL, 0xC4490059F463F464ULL, 0xB20927A4B7F402A0ULL, 0xC62107F24A30EF0DULL, 
            0x55EF661969A2752BULL, 0x771AFE6B8CE4B690ULL, 0xFA3EAB29C89A7129ULL, 0x09D7618F350BBEDFULL, 
            0xE0FB6FFD1442888AULL, 0xB0CADD8090AFF500ULL, 0xB35F165C9A665D7DULL, 0xE41F045CBDF70D1AULL, 
            0x576D0A86DF8567ABULL, 0x0FB457C4F44A5E7CULL, 0xD18B8D675DB4EA72ULL, 0x1530FF0394B7837EULL, 
            0x99175AEF326BD4C5ULL, 0x3D957475DD67224BULL, 0x2C15C9D5B0242F9EULL, 0x6185C7A95CA087A7ULL, 
            0xBC5CC1B41BD8FD84ULL, 0x1F1CD946196E06A6ULL, 0xE299F8AD69BBCBE9ULL, 0x3977E794E57F500BULL
        },
        {
            0x238B81693F738DC4ULL, 0xFE40D9EBE2607208ULL, 0x720D59488B072FE3ULL, 0xAB1151C26A6301DEULL, 
            0xD23C584A0FAE1BC0ULL, 0x4A234D481AC618D8ULL, 0x44940209FC1BA17FULL, 0xBFC6F08CB664B76BULL, 
            0x5D219288B5738474ULL, 0xDD7294B733FA35F7ULL, 0xF584A44329BDD186ULL, 0x9A8692F65443002AULL, 
            0x238F23311683AF59ULL, 0x4F0A48C391D5BEB6ULL, 0xF84F7E39EE2FCF1BULL, 0xF56E5E84E3A89CCDULL, 
            0x6F289D70210147BEULL, 0xFB1DD5B2273801C5ULL, 0x0D6A9C2095260EDBULL, 0x1C3EA7CAF783640CULL, 
            0x136AA0CC0F7B1E4CULL, 0x9CF60A57766E59A6ULL, 0x16B04EF41581D1E0ULL, 0xB291E0C3D1D668E5ULL, 
            0x8995762D6AD07819ULL, 0xC3F331FE160CE613ULL, 0xF9ADA44628F1EF77ULL, 0x618C97F04CFD56B8ULL, 
            0x77E99161840BC3CEULL, 0xBDF5625962473E1CULL, 0x5CF67280EF575E12ULL, 0x043A7288CD750545ULL
        },
        {
            0xDA7266D6ACCFA8A0ULL, 0x735BD3D5636F1C5BULL, 0x61FC6CA45727CC8CULL, 0x71312DD32FC8C068ULL, 
            0xBD71425931D93440ULL, 0x6F1095095E627411ULL, 0x821F0E48D28547D6ULL, 0x6E72C5A6E91DF82AULL, 
            0x7B6540AD1EF2D5A0ULL, 0x8ED3EF8611B5844DULL, 0xAB8C24D77E20A34CULL, 0x9B1C990206A86274ULL, 
            0xE1ED5D8FC3D0F437ULL, 0xE76B050B778C26CFULL, 0x9DF0E57847E9CD38ULL, 0x01A052B1D6870D86ULL, 
            0x452E1193A771D400ULL, 0xEE410928AF4114D5ULL, 0x84B65B506DB15178ULL, 0xFB714769C9E6C8DDULL, 
            0xC712CF8DE8AD0157ULL, 0x923AC18385EA85A8ULL, 0x964A1470EF338D8CULL, 0x6B75B8E46B3C48BEULL, 
            0x439D450F28D6BB72ULL, 0x1B47CD58B49FE643ULL, 0xBE2C123316A7056EULL, 0x7FC8173A024B6A8AULL, 
            0xAD25AD9577F11428ULL, 0x917BAF1ED607F40AULL, 0xA9B9341967A9F6BCULL, 0x46CAEC12406C0ED0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseCConstants = {
    0x56467C389AB94569ULL,
    0xB6CF6CD4A089C605ULL,
    0x18A1299E615CC20CULL,
    0x56467C389AB94569ULL,
    0xB6CF6CD4A089C605ULL,
    0x18A1299E615CC20CULL,
    0x6466C7C633F65938ULL,
    0xBDB72317AB130456ULL,
    0x38,
    0x98,
    0x90,
    0x5C,
    0x66,
    0xC3,
    0xB4,
    0x20
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseDSalts = {
    {
        {
            0x31B51EAFF5DE4F04ULL, 0xCE9C8764EA6E8EEEULL, 0x94298F7AA41C769CULL, 0xABDF2E990EBEB078ULL, 
            0x6F8801CEC86F16E3ULL, 0xC6401FD4307E92A6ULL, 0xE11EEF4C48AA28B3ULL, 0xFB3B89B8DC8D0461ULL, 
            0x796010C0B8981CCCULL, 0x1EA0A7881F8A8060ULL, 0x70CAA065DAB0C76FULL, 0x201529DFA709D756ULL, 
            0xE60FE60DEF19593AULL, 0x85BABD29B23920DAULL, 0x51F28FAE27D384EBULL, 0xB7E21519BEA17B7CULL, 
            0x0D6394DB1E6BAE29ULL, 0xFC4A18DB1C30CC79ULL, 0xBC73F0695AFCAD8DULL, 0x535D1221271C264CULL, 
            0x793E27C6BD25C5D1ULL, 0x783C596CB030BA2AULL, 0xA0B930DE9D82E69CULL, 0x9CAC2792A31BF6D7ULL, 
            0x82D86686BDD7492CULL, 0xB5893B293D4A121CULL, 0x1B483025673C94EAULL, 0x4661452E46B2B7C9ULL, 
            0x89B4B4ECEA826C00ULL, 0xA0DA15DCD0DAC19BULL, 0x61ADDE807EA07C0FULL, 0xD64B39BAFE7E46B9ULL
        },
        {
            0x13BD93826B51B07BULL, 0x25FD8E95DA2844E8ULL, 0xC30C3A1B6ECAD80BULL, 0x09AE9CD87F604925ULL, 
            0xF768414738ACE039ULL, 0xFF36760F8DA4CF44ULL, 0x75399BDF94DFB8F4ULL, 0xA899225A4EB0E7D4ULL, 
            0xB501B6CB49115D76ULL, 0xAE550FB0F75700E7ULL, 0x92C71BBD8EC8B3B1ULL, 0xF08E0902735352FCULL, 
            0x0AA35C72F04F8E16ULL, 0x2E2B9ED8FF865805ULL, 0x27C4C7FC58D8D4CDULL, 0xDA0571F87F10435DULL, 
            0xEFB7FDD09CB26885ULL, 0x9BD7DBA0035FF376ULL, 0xD8132C5EEB4BB7A7ULL, 0x12B0A0402BB66A4AULL, 
            0x52A9871CDC34DA7EULL, 0x51A0E0395ED5F1EFULL, 0x0BDF2356E9ACA88FULL, 0x046010459D4E006EULL, 
            0x05647A0E84074C60ULL, 0x8E5FC25DBA6C02B9ULL, 0xF6CB1A1F344BB37FULL, 0xE740D766BECAD58DULL, 
            0x4033F84EB17E14D4ULL, 0xE5E57F1D8BF01AC3ULL, 0x998037A66562C3B8ULL, 0x597D550B8559FDF3ULL
        },
        {
            0x1781F715CFCED616ULL, 0x57F33B77BC9F3645ULL, 0x0307BE22876D232DULL, 0xECF367FB4C3B272DULL, 
            0x04D62F5D54A40E06ULL, 0x2F1AC962A5054A3BULL, 0xBB4AB3C08C92CAB5ULL, 0x69F5457E6012B95CULL, 
            0x43C12FAA0B1D253BULL, 0x7ED3C1A34B0B3D96ULL, 0x9E2D4E0F2159B21BULL, 0x9A7A4DF6CE7EB64FULL, 
            0xEEFB015A26FD923CULL, 0x98F332AA04E730A4ULL, 0x09B177C4B7234A90ULL, 0x29756C0EAC75C037ULL, 
            0x926515861AEA823CULL, 0x3C44C3216F86B73EULL, 0x500595B490EFE188ULL, 0x6D572952B7ED57F2ULL, 
            0x16A9C0228490A029ULL, 0x3E07C8BAB9166D59ULL, 0x7919346608AD8051ULL, 0x3A868DFCC9AE4CF5ULL, 
            0xA182F9A61B6FDC49ULL, 0x3429F8AD7BBA7738ULL, 0x8D4BBC054EE96977ULL, 0x4AABF3559DEB7706ULL, 
            0xBEF07BBD2C338AC4ULL, 0x2A01FB72723C3EE8ULL, 0xB55CE10C31D842D2ULL, 0x162BA1BC890B33D9ULL
        },
        {
            0x1E59C9087BE94465ULL, 0x7A5594B529F6A0FBULL, 0x5BD8D08793B1B665ULL, 0xED082A57B4833681ULL, 
            0x6999CF764844A948ULL, 0x706AFEF76B059251ULL, 0xAEF0A4659B4F6E79ULL, 0x5AEE2823F80782B2ULL, 
            0xB7E6F4ACEA610CF4ULL, 0x46F96316BE11672AULL, 0x23567AF035AB6F1EULL, 0xA2DEDFE2B9C9B2D4ULL, 
            0xBB132008E22757CFULL, 0x975ED16C62DDB0D0ULL, 0x57B1FA337AF0A8F3ULL, 0x03A183A86BC6DE33ULL, 
            0x6FE65D488A51EED9ULL, 0xE4C0A8C99E39899FULL, 0xA590696A6304EC3CULL, 0xAF761478BEFA3237ULL, 
            0x1D6DD3BEBC7C458DULL, 0x8E564B0E210FA762ULL, 0xD357428C834315C8ULL, 0xE9169649FE74C12FULL, 
            0x6D6A59CDE578B82EULL, 0x4EE110E76C4E92CCULL, 0x5C0C02CB54015E3DULL, 0x7A01633278EA9354ULL, 
            0x0B81058C9D3EEF0BULL, 0xAF9162ABEC7D0F6FULL, 0x6EFCA254A661C2ADULL, 0xD85FA1B3D9F9AD99ULL
        },
        {
            0x32E2215636BA5505ULL, 0x9D2802437567598FULL, 0xD591F09075B4D37AULL, 0x1544A563A2016595ULL, 
            0x6345ABABE7F9A95AULL, 0x5F5ADC83EBD21D4FULL, 0x2AC7E9258F7ADEE2ULL, 0x81B429F9F6B84A78ULL, 
            0xA18768E8F6396578ULL, 0xE66076DD2B8E19CAULL, 0x290366B384EB185DULL, 0x3F6FF5AC911FF623ULL, 
            0x37D024CC882B9097ULL, 0x5986D33AA7CB53BCULL, 0xDAB025775E821A72ULL, 0x0EBAC08DE075A46FULL, 
            0xF605B26286117F4AULL, 0x6B9741DC5CCEA585ULL, 0xD7232EA3EC8EF5CDULL, 0x8191EE6527620E36ULL, 
            0xC1F61250ACEC33BFULL, 0x0D1535268C33F8D3ULL, 0x2987C003FF7AA867ULL, 0xE28C2231491089AFULL, 
            0xD3CBF05E0217EE04ULL, 0x0A4CB5D32282D107ULL, 0xA1A7AA75B5E5D167ULL, 0xA09A0E1480955BB4ULL, 
            0xD48ACDD091C8A5ABULL, 0x871BB12BFA83ED50ULL, 0x62F106C2A37B69A7ULL, 0x3012AE1C7E3D6FAEULL
        },
        {
            0xCA8795EAB7161493ULL, 0x70A9661AF5148A2EULL, 0x2725E0A45647BFDBULL, 0x82CDF184714BA6C9ULL, 
            0xEED79FA3B294167DULL, 0xDE713EBFF63F2AB9ULL, 0x46FC6C86A6D78C51ULL, 0x5CBDC7DE5CDEDF92ULL, 
            0x31F352AC3638651FULL, 0x6A6EAC2073560D4CULL, 0x3AABD80A921B2F76ULL, 0x122BC9A223373AC4ULL, 
            0xBA7812D5C9795EF7ULL, 0x753B174D9B95422FULL, 0x69860A32134C6078ULL, 0x767DC35EB766C89CULL, 
            0x3BB73041BF04DCBAULL, 0xF4338D5294900EE7ULL, 0xAAF1C4097373AD6DULL, 0x68AF6A9CA5776AE0ULL, 
            0xBAA5FE0132F2AF23ULL, 0x913D657E2CB2DE56ULL, 0xF3192DA23E0C5AE6ULL, 0x9659215992143E34ULL, 
            0x3875A25235C076F5ULL, 0x6BD2735FA2A4DC2EULL, 0x2CB20177C340FE13ULL, 0x39CD678D0D63A024ULL, 
            0xEA2D75B367BA4C8BULL, 0x59A9D335AE459E0FULL, 0xEBF86D0742CAF949ULL, 0xBBE11E44A27D2464ULL
        }
    },
    {
        {
            0xC8AA5ACE3076C3C7ULL, 0x080813DAD493809EULL, 0xC51C9307563950BEULL, 0x8FC811C643B47F0CULL, 
            0x32CDFFEC74F42DDFULL, 0x56D9E035F01238A1ULL, 0x7270E9C0C3CC664EULL, 0x80FD44A468C0A709ULL, 
            0x9F101ECEC9E689D0ULL, 0xADDE26718D662DDEULL, 0xDD030344C3F76C2FULL, 0x645D2E89A8E16699ULL, 
            0x836D4CA9A02A784DULL, 0xFF069975CBA18B73ULL, 0x77739FA9A36D1F07ULL, 0x4D033C7E8121E596ULL, 
            0xB3324A71C857A462ULL, 0xF9941A50C363F673ULL, 0x90606D4041E6B66EULL, 0x8A9298B6C93A4EE6ULL, 
            0x9148C901CBCB9CA2ULL, 0x5C46AD7777DFE923ULL, 0xA38968781314AC85ULL, 0x74A015A7434AE78FULL, 
            0xFE88FF718310FFB3ULL, 0xF6D9B77F82D3BCE3ULL, 0x81DA0173778FE6A6ULL, 0xFB375D4C8D29F499ULL, 
            0x7AC552F402467C38ULL, 0x07EB8B8DDF311ED6ULL, 0x762B1915007C3675ULL, 0xD1FDC287CD0102ABULL
        },
        {
            0x4F0B2FD0E09262A3ULL, 0x3F66AE997666F505ULL, 0x226F67B7FE70A9DBULL, 0xBB5D691E2B11C88BULL, 
            0xAD54FCEB2074816CULL, 0x483F11423C2AC76EULL, 0x053E4120055D280FULL, 0x3E456A8607D9962BULL, 
            0xD89465111DC23EB5ULL, 0xA22648888C26BF57ULL, 0x0654C33C1E0F6AB6ULL, 0x5F67E1231EFBE907ULL, 
            0x62F3CBCE9B015D59ULL, 0xE7D18ADA66AD16CAULL, 0xA7D31672BC337253ULL, 0x1155AB689714977FULL, 
            0x3055CBC3BD2F8923ULL, 0x153CC36356FDC9BFULL, 0x5FA414F853DD527BULL, 0xA01B6D55D7EADCF6ULL, 
            0xC22E3EF7986B6B61ULL, 0x2D1DD9A9E77AD9E9ULL, 0xCDE2934ACCAE21C1ULL, 0xC1F00AD07E070E61ULL, 
            0x0943AE3CA3F68955ULL, 0x433E040D9E415805ULL, 0xCC0BA07AC426CC91ULL, 0xB6FFF1B0CF55D231ULL, 
            0xBEAAF25007CEBBE6ULL, 0x9AC5063EF9E755D3ULL, 0xBA4A257A9739508FULL, 0xAAD0D40DB6F4EF21ULL
        },
        {
            0x6A3182B851592919ULL, 0x59735F798FEA8C01ULL, 0xD2B4887ECE6DB2DFULL, 0xA15E99E2B27ADD92ULL, 
            0xAFCDDD534EE6B2DAULL, 0x0E04FB3E2CA73FF3ULL, 0x776C8C0D23C586B3ULL, 0x8F58E5F5B649985DULL, 
            0xD9C4CCE81CA656BBULL, 0x3AFCAD4E6B1CC816ULL, 0xAB01949E7E54A3FEULL, 0x7BA4D01A4C28BB3BULL, 
            0x3B9344E3D912B15AULL, 0xC74144C061747B67ULL, 0x3925A4B7B63F40C0ULL, 0x5856E926147B5DA7ULL, 
            0x912426D16CB92324ULL, 0xFBF9673E8AE382EAULL, 0x42DE0B4500B633E2ULL, 0xA48AAD327FB2AB59ULL, 
            0xFDBF5AB4618A0955ULL, 0x0C24486BF9266C14ULL, 0x4C4DC74DA458A380ULL, 0xD71EF34300F3504FULL, 
            0x7AE9DA1E77F21E16ULL, 0xAD620CD8B43B4282ULL, 0x15B857A66B553135ULL, 0x9842D1E30F20643DULL, 
            0x78EBA0E914D488E3ULL, 0x78CEFA7FF4AF52BBULL, 0x770A7E496FC6E16BULL, 0x5748D74B68D5061AULL
        },
        {
            0x46FE7BECC5394BD2ULL, 0x4F9C9FA8EDFF639AULL, 0x773EB182BD0D1ACDULL, 0xBCA7EB30F089BEC0ULL, 
            0x93F8067D45116BEFULL, 0xC0675631C3D97D7AULL, 0xCE9BFD88145A8C04ULL, 0xF7D850498DC7D439ULL, 
            0x58A285E829A5405BULL, 0x1AD52EAF24592693ULL, 0x587CD0DC95829944ULL, 0x81AC6A7E2FA2D0F9ULL, 
            0xACBD4113E3E5582DULL, 0x50F40A52B7A4CBFAULL, 0x464A182651EA1B47ULL, 0x81F56D8BA0432DC0ULL, 
            0xF9E2C82A04093C4EULL, 0x8921802EBBD9AE70ULL, 0x899CB3AE0D291BA2ULL, 0x692000FF31B7E460ULL, 
            0xA0338BA179B51BC7ULL, 0x9E97A66CEADDA643ULL, 0xAFEFAD230703B506ULL, 0x311879AA12E5E232ULL, 
            0x65F8755BB6173B74ULL, 0x28F5B51E3B40546CULL, 0x919B9FFB7ACE969BULL, 0x4F0E8B072BB961CAULL, 
            0x4AE183066F09DF96ULL, 0x046DFE174C540E04ULL, 0xA14082870342A972ULL, 0x4297A424AB71EFB7ULL
        },
        {
            0x0251E03261B4ACEDULL, 0xCC8800C93766D7F2ULL, 0x178BEA7F7DAB116BULL, 0x1159683D31B532C8ULL, 
            0x8D9DCE26C000F439ULL, 0x7D133D37B72BDBCFULL, 0x41DEB952E9943C09ULL, 0x92D885927E584997ULL, 
            0x80938964D5CEC79EULL, 0x968CB85F0BBF7A62ULL, 0x873EF6593DE6A425ULL, 0x81E381FE8F87FF80ULL, 
            0xFD5CB058BEFB37E7ULL, 0xB400AAB9FCFA1218ULL, 0x3632CEE196AA1BE7ULL, 0x7DEC9A1C4A9CBBCAULL, 
            0x87AC9413EC97AAE3ULL, 0xC1AD937A909CEA2EULL, 0x0630D236B6888405ULL, 0x7232FFC1A4083CE8ULL, 
            0x2886AEC2842C44A5ULL, 0x78D318EBCC8630F3ULL, 0x473737C2C1F1A696ULL, 0x33C9D0D9AB7F4506ULL, 
            0x5C726658ACF79FA7ULL, 0xA9952FD7B1A48667ULL, 0x85270F3B2C72403BULL, 0x78F50FE54CD21446ULL, 
            0xB170774698F5343CULL, 0x30BDA005EC4A27D1ULL, 0x7FFA48C3C0D48FD2ULL, 0xCC72B4CCB513DB6EULL
        },
        {
            0xFF2CA83A1804AE9AULL, 0xE3E8ED3DB3AC1F36ULL, 0x958F404080E2C04FULL, 0x1BE71A4910389AB9ULL, 
            0x8FCEFFD190076C2AULL, 0xDEE2D292FAE28F3FULL, 0x58FB91529C4CD62AULL, 0x40120D40B266E7D7ULL, 
            0x59306F7492B5B682ULL, 0x32A6ED17B4C969D3ULL, 0xF6793D73EE760E70ULL, 0xB1BA0CFC7266177AULL, 
            0x075E44A1D24439EEULL, 0x45C90E4D60F823BAULL, 0x7E1DA4F3E22610E9ULL, 0xE7D548B04F044772ULL, 
            0xC6F00AD914895A90ULL, 0xA560583D156181DEULL, 0xA0FFB6849E76FA09ULL, 0xDFEAB396A7E4B6A6ULL, 
            0xF5470E93997D29DDULL, 0x3EC59ADBD39F74E4ULL, 0x1605D259C9203DF9ULL, 0xE01453B639E27E40ULL, 
            0x3E4D6198F5EE7863ULL, 0xA9C8DE10F7D24427ULL, 0x06D6192E626FA67EULL, 0x9AC274DA8D07646AULL, 
            0xDCDCA3AA77E53396ULL, 0x72B46FEDA64E4E2FULL, 0x4EFDBA324ECCD32CULL, 0xB4FEA86BCBBE8D94ULL
        }
    },
    {
        {
            0xD0D40CB56646F7A0ULL, 0xB868FC89CF0AF392ULL, 0xDE5E6FA202EDB808ULL, 0x465E8A4C1350B5E9ULL, 
            0x284F9995A4D41157ULL, 0x725834302301CF66ULL, 0x35592D52E66EBA05ULL, 0x142349C71E0989AFULL, 
            0x522239274CF7F607ULL, 0xC5A103E97FEF77AEULL, 0xA77446AA40AD37ACULL, 0x2C03A44F119AAFC6ULL, 
            0x1B160D0F8B89A27AULL, 0xE2FF1473BC9BA9E5ULL, 0x70C19D4AC3D9BA3CULL, 0xB38F1D30E6828AF2ULL, 
            0x79220BFEB479D14DULL, 0xD348F9290D29ECEEULL, 0xDE4FD3F7530BE34DULL, 0xD1B8B184DBAD7195ULL, 
            0x81A3211E5BDDBFB5ULL, 0xAC7F2E2935ED76F4ULL, 0xDFC426D91CF164EFULL, 0xF7B4BE8843D7539DULL, 
            0x28585155FEAE6B87ULL, 0xCC2C5269956A14CEULL, 0x7D780C00DF271FE1ULL, 0x40543AB336A3463DULL, 
            0x4E516D6B68C02223ULL, 0xEEA0E1A07F58494BULL, 0x3AEB08CE605CFD70ULL, 0x9CCC47809D790C03ULL
        },
        {
            0xDD6092C29C641A58ULL, 0x4730ECCE2270F7E1ULL, 0xDF79669E032A6C3DULL, 0x87426B738AEB1A7AULL, 
            0x8D610D8612B09375ULL, 0x6D62DB7FA2A6D103ULL, 0x341D7374F13377A3ULL, 0xF5350882A27C45F9ULL, 
            0x01E6F5D65EDA94E1ULL, 0x25322A470A5CD0F1ULL, 0x56D620ABFAB9C57BULL, 0x5F42DF7BDC50DB0BULL, 
            0xF1612AF8ED4E36CBULL, 0x2B32F9670A0453CCULL, 0xAC70300FF8575DC3ULL, 0x17F5EC2C332D7D7FULL, 
            0x30028F1027E69FF6ULL, 0x7C61985C47E3AD5CULL, 0x1269B91251394C64ULL, 0x25857DAA26E02317ULL, 
            0xD3610C6D0EC204C4ULL, 0xE709D4F57578FBABULL, 0xBD824315303B9F72ULL, 0xEF27C623108E5A09ULL, 
            0x32D19D1596D7F55FULL, 0xA641BA6158726D52ULL, 0xC329BB56A8A76D78ULL, 0x53F8A0596A1C7FB3ULL, 
            0x4724CF0170C26B0BULL, 0xC2004C07838E40E4ULL, 0x55E2CEDAA8C946BCULL, 0x209E9143FC5E838BULL
        },
        {
            0x8D75E6B3B5B80BD4ULL, 0x99C9C6D862DEF1A0ULL, 0x67431A0F91900B36ULL, 0x2A4B8CAAC0FAC646ULL, 
            0xC0522843C2C66391ULL, 0x6C8524E366CA0EA3ULL, 0xA14C0B60363A6BF3ULL, 0xB1226EE1EB563BF0ULL, 
            0x8EFFC86CEC810BA2ULL, 0xB18BFB1EFE5A5670ULL, 0xA3E50D7B0BB03023ULL, 0x710802B9C57AA437ULL, 
            0x2B319360149F4480ULL, 0x672D1B68C7A3B35FULL, 0x68A0DF20EF291141ULL, 0x57717290ADA95827ULL, 
            0xDB1E258E0915E0A8ULL, 0x3F0597395796F2A3ULL, 0x8859FBBE8A36A7D4ULL, 0x587531A5BF60339DULL, 
            0x76A8B1EC2F1D88B5ULL, 0xEF9891E216BF3037ULL, 0x0D296E21639F44CDULL, 0x14942E7295BFD2B2ULL, 
            0xE71325BC7F8A93D1ULL, 0xC5274300F1478393ULL, 0x17841F094770CF1CULL, 0xFD2A78FFACD702E0ULL, 
            0x69AADD4C600A8AFFULL, 0xD383899C88CAC33DULL, 0x79101B68FA511CE2ULL, 0xD48866FEFBE96C87ULL
        },
        {
            0xF73C66A96FB8B5EAULL, 0x397B50CC4A702730ULL, 0x0B8A1B6415BE921BULL, 0x745BCCE95E44AC3CULL, 
            0x9CFB820F89F47B01ULL, 0x2F96FD357B2FEE05ULL, 0x5C43BF03FFABA9EBULL, 0x58C0726261B8912DULL, 
            0x6541C515E1BE5BB0ULL, 0xC9E062C00540C80EULL, 0x0F8C990B8E87BEEEULL, 0x9CCB0DAEC72C9692ULL, 
            0xAC0571134DA13029ULL, 0xFEAC186B3DFB8404ULL, 0x8ACC3E0EE4333197ULL, 0x962FD5B733C23CC4ULL, 
            0xC508DAB9D61D031CULL, 0xE78556521E5D9F7AULL, 0xB3C467EFE2EC7001ULL, 0xF142C5BF356EC3D7ULL, 
            0xABBC939286BC115FULL, 0xF46079A06EBF2745ULL, 0xDC9CE0ED88789B3DULL, 0x69BC3360407DCCBDULL, 
            0xB1005677A273D4B3ULL, 0x5619B70B69A33742ULL, 0xE526042C8A7999B6ULL, 0x55319788423C3346ULL, 
            0xDB9B7B5D4194A639ULL, 0x1C0DAC80C387BF19ULL, 0x4D5EDE6710FFD06EULL, 0x6F79F7D0468391A5ULL
        },
        {
            0xA21FFF76C4003A5BULL, 0x7871D64C4A85AFE8ULL, 0xA7DE585107E261D4ULL, 0x46CE3B0B135C210AULL, 
            0x1B70BA72F6FCACA7ULL, 0xDAB1184D17A274D9ULL, 0x3283337AA288307EULL, 0xC0074EC1C58C593CULL, 
            0x819B614354867328ULL, 0x8EC1E2EBB6624F42ULL, 0x4F6A5F3CFC40210DULL, 0x9D5DA6BB9B17F6CFULL, 
            0x9DD659DBE4CD13E1ULL, 0x4B22EEE375B10C0AULL, 0x65114430889F32C8ULL, 0xF578A6E4C3FD7247ULL, 
            0xB3EC79E772EE8DCBULL, 0x49FB1B5CCE4AE93EULL, 0x358CC5D91D21A125ULL, 0xB9406975210DCE9EULL, 
            0x040ED67CFD762965ULL, 0x48F7929903D0C5CBULL, 0xF6FBB342C5E29955ULL, 0x112508DACA8DED3AULL, 
            0x0588E7FC5FA3DB2DULL, 0xDEF87837C6B30461ULL, 0x4F2DC8DB179B4F28ULL, 0xF46F45C857F5EED2ULL, 
            0xEC6E088CE7237C32ULL, 0x9EBD25C1DF0D64F3ULL, 0xE345D776A496142AULL, 0x830A86E40C178A50ULL
        },
        {
            0x5DCB8AF82919A44DULL, 0xA1B026AD6DC1FA48ULL, 0x92D05275BBD8A432ULL, 0x0247D91FA2D10862ULL, 
            0xD48AFD83135F16E5ULL, 0x1833BDF9887826C3ULL, 0x115438D45103C8C1ULL, 0x5252C3173E26BC4CULL, 
            0xF6A384A9D3E9D15EULL, 0xB00A072D20F56C98ULL, 0x5D817747B36E33E1ULL, 0xBD08AAB4870EE984ULL, 
            0x82D6C5E39170DAAFULL, 0x4E3180433C48FB9BULL, 0xA20F6EC50C63BB15ULL, 0x8E674D975651E3E3ULL, 
            0x6929E833A65EF68AULL, 0xE8C980D7C0DE398DULL, 0xAB8E39176CE07BF4ULL, 0x4CF979D0495A1A99ULL, 
            0x7AEEB4B40652A69BULL, 0x5C04583B8DC06844ULL, 0x6DD42BBB13B907F5ULL, 0xBB8E4C789FDBDC1FULL, 
            0xBEC0BA840EEC6BA5ULL, 0x12786AF3759248EBULL, 0xABDBFE8D88DD17A9ULL, 0xEFC1DA3DAC09A041ULL, 
            0xAB31FE7CB09307E2ULL, 0x422E5884060EB3BCULL, 0x18FC2061D425A753ULL, 0x5EF5DE0FD4C257C4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseDConstants = {
    0x70A3F0ADE8D28CFCULL,
    0x7338CFA8BC634E68ULL,
    0xAEC7B36F85D7DCB2ULL,
    0x70A3F0ADE8D28CFCULL,
    0x7338CFA8BC634E68ULL,
    0xAEC7B36F85D7DCB2ULL,
    0x25FEA7BF1ECF8E1EULL,
    0x9DBA98885B17C737ULL,
    0x9C,
    0xFA,
    0x98,
    0x4B,
    0x74,
    0x62,
    0xF4,
    0x72
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseESalts = {
    {
        {
            0x46901A17A4C72A2DULL, 0xA4179593138877B5ULL, 0x38A341F259DF14F1ULL, 0x164A5B0D5BB9189FULL, 
            0x7F88EF3A656BD73FULL, 0x883815A5EE60ED7DULL, 0x11C0BE2A34BE45F1ULL, 0xCFD3A24F89755CE6ULL, 
            0xD52B8C5A38ECC679ULL, 0x8407E09E0EE901C4ULL, 0xE88C1D6EFB771CFFULL, 0xC5AA4DEE18EE545EULL, 
            0x8818E5C7410DB89CULL, 0xE033C1BFCB23D9BEULL, 0xCBFFF13F893A1FC4ULL, 0x461666B2AD20FA72ULL, 
            0x98D6516BC46E0DAEULL, 0x9E9297D02A805E39ULL, 0xEA9DF66251EAEBB9ULL, 0xF5F80D87FB7DE78CULL, 
            0x1BE14E6BC99555C8ULL, 0x07100B923766982EULL, 0x1B9786D6FA75E6EAULL, 0x17089FE3D4ACD248ULL, 
            0xEA163B20DFFE62B3ULL, 0xC645BFF0A7821391ULL, 0x843005F34872928CULL, 0xE1D6BD41FF4275E2ULL, 
            0x6EB77877E1ACE36CULL, 0xCC82FD077873DECAULL, 0x1C95F099DC76E1BFULL, 0x4327E65E6C9C0D6BULL
        },
        {
            0xA4F941C2F4B077B5ULL, 0xACED84263F9DA8ADULL, 0xC2FD14044A79A8F2ULL, 0x035201232BBE3697ULL, 
            0xEF4905273FEF2FDFULL, 0x657EF4D2E1CEFAB1ULL, 0x714CEA95EE3C7D98ULL, 0x217FA9077C5E3A22ULL, 
            0x8DB10EB634D27DB4ULL, 0x7F5933BACF385211ULL, 0x378DF1E5F980B592ULL, 0x55DCF2FC02783B42ULL, 
            0x3BEB594EF71EB759ULL, 0x64B82D67561E6E8EULL, 0xED5CDAA7561A59B1ULL, 0x4F76B9DB1E057E3EULL, 
            0x2F66F3D645C3A367ULL, 0xE5F7B1F33E852213ULL, 0x88EA0245854EDC4FULL, 0xD07C78E6985981EEULL, 
            0xE429405F9C7E4004ULL, 0x95F27AF8C2C2159AULL, 0xCF304D714658A972ULL, 0x8123A19D7AFE2E5CULL, 
            0x848717B34E90032FULL, 0x6995AD93CAF673ACULL, 0x32892F050DCF2E19ULL, 0x6FAE69F7CF557A93ULL, 
            0x43182EF6CCDD755EULL, 0xBF2836F18769A3BFULL, 0xCBB02A51C0F40A01ULL, 0x4CFDF44A1D46D816ULL
        },
        {
            0x9C1FAD919BAA6826ULL, 0x0C794E0BF854A100ULL, 0x967F9878AAA7A059ULL, 0x88AE1A02B134FE29ULL, 
            0x9D30AD75F419A789ULL, 0xACC407E9C8EB1E48ULL, 0xB4ACE6EFC658885BULL, 0xE128D7CE45E92DA4ULL, 
            0xAACB10087CFC24DBULL, 0x89B7D5C4823FD988ULL, 0xA3FEB586F00E4C10ULL, 0x0455D4C5669E4469ULL, 
            0x2002A566799C64E5ULL, 0xA923CCFB215C7215ULL, 0x3E8116E7FE41586AULL, 0x584D9D2BF3C65E36ULL, 
            0x4DB5702F4002D2B6ULL, 0x98C6803637970BA1ULL, 0xFB2BF529F2E7D95DULL, 0x04FC13C74203EF9EULL, 
            0x1AC661B50B8B4112ULL, 0x74D7E6C945797BBCULL, 0x333E02CC94DCFD1CULL, 0xE7E4F03129B5F80FULL, 
            0x9AECD920B4180987ULL, 0x90F3F1E2F4516D07ULL, 0x2043D5A6D5A1B03DULL, 0x60947965B3EF57EBULL, 
            0x47D9C1AC929A9C1DULL, 0x1D88EC0C383879E3ULL, 0xC5FA8D31B1AE5165ULL, 0x33A7CBA548D15CD7ULL
        },
        {
            0xD4BFA091EE4E1A41ULL, 0x30C5E19A1B366E19ULL, 0x5DB683F526FC3A92ULL, 0x309F8FC8B7696B57ULL, 
            0x96940E205C667E36ULL, 0x52619C65D11D14A0ULL, 0x11B25E834587EE74ULL, 0xA17800FB5457B620ULL, 
            0x3C67605D28627A21ULL, 0x26E2ECE8864ED428ULL, 0x87C7C9843746EA89ULL, 0xD7D4177866EE3A5AULL, 
            0x7DA981720E990810ULL, 0x69FE164F3510B92FULL, 0xA5549F61FBDAADC8ULL, 0x6572BCE7B63F49FBULL, 
            0x7ABFDA3FA1B0279AULL, 0x493EB60DA167D98FULL, 0xBF23DD08D53DB654ULL, 0x1E8E18343C1C7184ULL, 
            0x9160B4A59D3A3614ULL, 0xA473986D49BA183CULL, 0x786A28D2747C372FULL, 0xD55281770C39FAB7ULL, 
            0x5BC546C1B3A99E3DULL, 0xDB4053847ACC2019ULL, 0x619B255485FD9CD2ULL, 0xA9861C5BFDB36854ULL, 
            0xAF207E758B205746ULL, 0x752B1C28274DC868ULL, 0x72132119AA9CDCE8ULL, 0x2C13FD2B27F45A82ULL
        },
        {
            0xAE03B6ACEFEC6670ULL, 0xF5F66A1E06937615ULL, 0x4E373CE66D49F650ULL, 0xF4C6BE75E3FF3F8CULL, 
            0xD347A1C7D9DDC059ULL, 0xA5DF10F60CF3E66FULL, 0xE516C91167F98FA3ULL, 0x283990A433DF5260ULL, 
            0x5DA14F5D1AE54900ULL, 0xBA58EDFFB38416A6ULL, 0xDB21EBAA25C525D5ULL, 0x42A22A6248BC6A2FULL, 
            0xB09C6B9DA0DDFCA3ULL, 0xF2D310BDEDE91EE0ULL, 0x14AA6B1B253C953DULL, 0xBA0563C902750663ULL, 
            0x7C14374560B1317AULL, 0xCF7B1C3F7F9FFBD4ULL, 0x32173A5921DD3FEBULL, 0x9EC32A2E9A24C814ULL, 
            0x842DF5015EF8AFA3ULL, 0x76BE3824A14C2EDCULL, 0xE8EAE407B7535122ULL, 0xC609C1ED9698D5B1ULL, 
            0x1959610227C3B5B2ULL, 0x914D135C6437449BULL, 0xD2F946A804F88409ULL, 0x8C1252B4E6DE1FA9ULL, 
            0x51007922122308FDULL, 0xFDF60F1A487CC8A3ULL, 0x4907337DBAB686C8ULL, 0xD752D6AA6AB1A22BULL
        },
        {
            0xFE6E1BF0887B4280ULL, 0x6277FA9DA6AAB631ULL, 0xB8C03548DC3B5C00ULL, 0xA6BAFB7343286883ULL, 
            0x0386454E7032011DULL, 0xD969FDDFDE465C8CULL, 0x2C0A23E9D8C06D13ULL, 0x37592B68E8932011ULL, 
            0xB0234598D319C006ULL, 0x32BF07C129DE43D7ULL, 0xFDE3D8D8DCE97530ULL, 0xAF4AA99F8AF6FA8CULL, 
            0xFB59BCCE0ABE947DULL, 0xC32337A00BE3DD8AULL, 0xC34ADDC3C960AF7CULL, 0xA0F66ECC88DA5B82ULL, 
            0x1BB0CD8250FA1954ULL, 0x1BC509958D9AC413ULL, 0x991EFCBAF27BE9F6ULL, 0x5139A01D38048666ULL, 
            0x3D9E56077AB9C2BFULL, 0x02F9832A13342D6CULL, 0x38A52D11EB8B72C0ULL, 0xD24A28F8EBDF2CD6ULL, 
            0x7EA5191975E8C46FULL, 0x78C03014C2B829B6ULL, 0x99624C52B13F683AULL, 0xD76330A760D57BF3ULL, 
            0xE9BCCB32EADEFB3DULL, 0x2D541753AA263761ULL, 0xB285652F43D24300ULL, 0x33079EE645CBD934ULL
        }
    },
    {
        {
            0x1AEE634D245C83BEULL, 0xC5C5AC1C5E29DAA2ULL, 0xC04B0DE13F05F69AULL, 0x3A95DB849408BD43ULL, 
            0xB35D1F86AD062C42ULL, 0xA6D8B53EA8C65C65ULL, 0x439C8602CF0D0EEEULL, 0x4598EA6708894357ULL, 
            0xFBFC0EB34768F060ULL, 0x6AF5CE6E1E6705A3ULL, 0xD77B52A937BDF5AEULL, 0xE8F351CD4D31E03EULL, 
            0x5626CCAF48169171ULL, 0x722602CA95FB4534ULL, 0x20CDFC67CF09CC5AULL, 0xA0CB9415EB0D5E6AULL, 
            0x89D47A3D669BC536ULL, 0xC6837DC39AA93804ULL, 0xEDBB514100C031C0ULL, 0xF5496DA91AF5824CULL, 
            0x292359CE50055874ULL, 0xC646C9A35FEEBAC8ULL, 0xA8F1BA3A900C5934ULL, 0x5DF0B6FCDDCD1998ULL, 
            0x972A4D762E6F2A9BULL, 0x4DD96507319C52A9ULL, 0x77E8C5ED7538A618ULL, 0xE598E0F5BF6C598AULL, 
            0xC1540E4B44831F32ULL, 0x94132DBE24FD3690ULL, 0xEDBA61638DAEAF66ULL, 0x3358EBF7206CA0E6ULL
        },
        {
            0xD7577A7A95626A78ULL, 0x57876E6924D34E8BULL, 0xD0A0D6AD5DE09F8DULL, 0x1D58B711B716DB5DULL, 
            0xABA3CC82E4F7A68CULL, 0x07DCC5F06990AF3AULL, 0xDEFD346F3417E646ULL, 0xF3A89C185DD728CBULL, 
            0x8FD3CB57F0928025ULL, 0xB9552662F577FA40ULL, 0xAAED4F8B86F7C190ULL, 0x4C295DB699333681ULL, 
            0xAD9219362CC585CEULL, 0xF761D9A9E67609A0ULL, 0xBAC76F65CED623D8ULL, 0x9D784229A86E0311ULL, 
            0x3E813F2BEACF5545ULL, 0xB2BD76FC7E55B93DULL, 0xF1EF62F1EA4F3DB1ULL, 0x269B7AF7008474D5ULL, 
            0x76813704A4DCCC1DULL, 0x777F3D3A69D4039CULL, 0x889719C543D7C1C1ULL, 0xE74B9E32886FE349ULL, 
            0x54FFB241CD3B00CFULL, 0x16CAF4AEB1909CEFULL, 0xB3C95FE0731BA17CULL, 0x025541168E400106ULL, 
            0x51ABEAB207B6B217ULL, 0x555DFD6B0AD4880BULL, 0x053BA6D475FCCB66ULL, 0xC90A36C71E076380ULL
        },
        {
            0xE489FA3F38D121A2ULL, 0x234F90233D7E2A65ULL, 0xA94766CEF22F04C1ULL, 0x1F11297692EEB270ULL, 
            0x443171B76E096DB4ULL, 0x3700919356928D45ULL, 0x448DF9F5D6AE7575ULL, 0x33B54F9BB48588B1ULL, 
            0x1CA139706046B96BULL, 0x000270267BC4326AULL, 0x79A4B930A64E6268ULL, 0xFD4A30A21D1FA1A3ULL, 
            0x4DCC6A78A9F39C54ULL, 0x77BBE1370ADD8F52ULL, 0x94245668899FBFA0ULL, 0xF787314FA41BF8ECULL, 
            0x6143FB72C45FF861ULL, 0xE72D7277B76CAA6AULL, 0x1897440EF59BA031ULL, 0x111DB415BBFE4611ULL, 
            0xBFD4DD69BBE2FBDFULL, 0xFA7FD9E5A6C7DF8EULL, 0x25BD78E77D5213A1ULL, 0x5A5F172B3491BFDFULL, 
            0xF811C9A2D831B5ADULL, 0x2D7CB7A4DCD6F693ULL, 0x8F9C8153D5BFDC44ULL, 0x4EACAF0D01CC4C31ULL, 
            0xB129F357DDBBBE84ULL, 0xF187CA1F1D409BE1ULL, 0x2ABB178B18A8D4F7ULL, 0x6A16A5158F28841FULL
        },
        {
            0xAA4D06FA71158B49ULL, 0xDBE75BA04EFF0B04ULL, 0x499ADD67941B2E22ULL, 0x4B0BE46EBCF8B23FULL, 
            0x48C03AAB7D631441ULL, 0x38598493608DD2CBULL, 0x5943A94904FC5D8EULL, 0x349526FEC0760262ULL, 
            0x91FEE3ED3EAB2FEFULL, 0x0C88B71C73A5DEA3ULL, 0x62C3ABAC8A45C209ULL, 0x3DACDDEB8C819641ULL, 
            0x1693B760A9F67DA0ULL, 0x594DDD7094BB1A29ULL, 0x867D81E065755269ULL, 0x48F1E23265695930ULL, 
            0x6076053FFFAC9BFBULL, 0x69861009D558587DULL, 0x6C72D79C9A42AB75ULL, 0x76415663981E3277ULL, 
            0xA9D9D8E18F5CD481ULL, 0x93F627524A4DAE22ULL, 0x13AE8347F3F3E30AULL, 0x6ABE5882189D15BFULL, 
            0x632A8FABF9733F0CULL, 0xD03DDA1D388C57EFULL, 0x5CD0510F94681B6BULL, 0xAD7F9572D23EF1FFULL, 
            0x51E51B419922928BULL, 0xC3019D162F382A0BULL, 0x479622C12E7DB5B4ULL, 0x727AEAB8BE00C9B3ULL
        },
        {
            0x7F93623C014E74D5ULL, 0x1F504BB1321816ADULL, 0x4153D1300AC8AF1DULL, 0xB1A4DBE756975361ULL, 
            0x476253B147A0F0B1ULL, 0x0BE8EED6A6070970ULL, 0x9C76D2FB4BEE97BAULL, 0xE5CA6A1FCBC73FC8ULL, 
            0xC65F6BA4ED882617ULL, 0x156D6767B8B0BF72ULL, 0xFC604C819268DE93ULL, 0x26FAFE36AE2D8F35ULL, 
            0xE197E927DC8323C0ULL, 0x3697600F3615EA52ULL, 0x438ACFD771B12C36ULL, 0xEF423D2B12BCE001ULL, 
            0x6CDA004C2FC77AE4ULL, 0x013A9948489BF111ULL, 0xBF53BBF6D4313E31ULL, 0x1D59C1B7BD4E90AEULL, 
            0x8FFB9AFC87890927ULL, 0x624E01D129E5E3C2ULL, 0x4874E7805D905551ULL, 0x6407112A6AC7C8D2ULL, 
            0x04B56E10C61EB8E6ULL, 0x38E12A4F402CC6C9ULL, 0x853C267AC1C685E8ULL, 0x86F41ED76AFEF46FULL, 
            0x6D5D883136650A83ULL, 0xFC2457CFBF842D4AULL, 0x38C22EF8B6DDBA7DULL, 0xCC4FB1572195DF39ULL
        },
        {
            0xD7D3DD96EBF07362ULL, 0x21DDC5D36032D113ULL, 0x72C90851A42FEF53ULL, 0xCD60AE559F4FD61EULL, 
            0xB212B5F4D23CE36BULL, 0x7E1FD2C7675A3836ULL, 0x45946308945E30EAULL, 0x4F84900F6E46B625ULL, 
            0xB9BCC3A374942010ULL, 0xDF0F3BECED2A151FULL, 0xA3251EBA072C3E45ULL, 0x6C93FD818701B5C9ULL, 
            0xB6AEC786E5621357ULL, 0x9DA7E5E57F56C789ULL, 0x24E3066F46049446ULL, 0x27D996623AB8C83DULL, 
            0x2753EDCB1CD53221ULL, 0xCA6A119440631093ULL, 0xD22964A9D8240DA6ULL, 0xC0FC0CE58DBCBAB4ULL, 
            0x477A94C8120959FAULL, 0x723D11DFA6ECE037ULL, 0x7D2ED25812B852C2ULL, 0x8109BE90DE53BB72ULL, 
            0x37F251CB74454754ULL, 0x724842D817D432E8ULL, 0xE66E5B20E49AA62DULL, 0xF6A53D36A85CDD75ULL, 
            0x6D035ECABF29506CULL, 0x1158D3D14299E040ULL, 0xEDE5E5658A9B41A7ULL, 0xCA4F1422205FE302ULL
        }
    },
    {
        {
            0x4C28481ADCD40992ULL, 0x23FF93E6F78F4295ULL, 0x3650502C1432F130ULL, 0x5E01095F027DBB45ULL, 
            0x0A50CD6FF5C0ADF5ULL, 0x3F199B124EA869D4ULL, 0x78EF9224CACFBB93ULL, 0x49AEE0BF8C30481BULL, 
            0x944769D52698C6F6ULL, 0x13AAB44E332D4C50ULL, 0x3FCE53BCE1E26F01ULL, 0xF1575F0E8F44360AULL, 
            0x6B19C1639A3D6855ULL, 0x57A75809F8D112BDULL, 0xAF869B0D13CB88FAULL, 0x272D396CA9D3AEF3ULL, 
            0x800AC3393F6EC20CULL, 0xF2652A891DDF7428ULL, 0x2EA75654197147F7ULL, 0x34013183503ED898ULL, 
            0x443BB8C1950B40FFULL, 0x7B868CC4C0F56CDDULL, 0x0468C4AA387D44C4ULL, 0x77F707C5034F53C0ULL, 
            0xB2488C6CF36D3651ULL, 0xD2D9707B69B53C66ULL, 0xA50F32292B6A0260ULL, 0x0965D78AA273D968ULL, 
            0xC9D5FF4E42035D5DULL, 0x438E2EE8683CC591ULL, 0x0CEF6DAEDCBECAC6ULL, 0x08B46763A24A2C69ULL
        },
        {
            0x369F90549B3876E2ULL, 0x0573E337C385FB38ULL, 0x22EA689E8846F442ULL, 0xF126B1B83BD1CE7DULL, 
            0x8CDA31C261EFE08CULL, 0xD9FB048C7A0FC6FDULL, 0xEC40A6267DED5ACEULL, 0x9F8516E1B197CD0BULL, 
            0x5B81F8D136357982ULL, 0x3BF621A8AB227D42ULL, 0x7E61E7603AE0BE2EULL, 0x2260E6B240567507ULL, 
            0xDB56929E6905767BULL, 0xDA6B8BA21299C76CULL, 0x9F98B63CF977844EULL, 0xE2BE1D1BA7F034B4ULL, 
            0x9E58910BA4F3A944ULL, 0x513340B7B7A7B300ULL, 0x64E01CC9316C7637ULL, 0xF662E94342CEA094ULL, 
            0xD602E0058BA5C82FULL, 0x0FEC6D57A37E5753ULL, 0xD8413F715C816953ULL, 0xCE529AC38AEE4E97ULL, 
            0x30544F5FDF82EAE4ULL, 0xB01236A4390EE9B6ULL, 0x5C0A10D2096AF745ULL, 0xAF0798AAC94D9D5DULL, 
            0x6A9AF6D380A43476ULL, 0x4BE33403918E1461ULL, 0xB5C3C1179A517FC5ULL, 0xFCFE599428E88C4DULL
        },
        {
            0x798F66C1105CF8E3ULL, 0x84C53CDEE0D388BEULL, 0x0542B9CDACCE26CBULL, 0x52BB955C0543F495ULL, 
            0x171A4CB98C9BF77AULL, 0x3C7696C950F60057ULL, 0x7947BA3880DC3E54ULL, 0x66EC56919EA9BC74ULL, 
            0xDD31CD35AC5701F4ULL, 0x697C210E5C27D836ULL, 0x0305E1A889CFFF2CULL, 0xA3A22C0E528622CDULL, 
            0x07BA3A92A169D99BULL, 0xCBEB3C3E82CFE61AULL, 0xEC8DCF036D9CC7E6ULL, 0x0D2D9876EE26C9A4ULL, 
            0xED78B4BBE006A4C3ULL, 0xC0B8E6EAE0F4B71CULL, 0xB57116B64D83D485ULL, 0x28C559C620FEF268ULL, 
            0x10E006745FBC6480ULL, 0xB2BF3BC4EA304EB3ULL, 0x98840AC3B4496092ULL, 0xDBD6B15D16561FF9ULL, 
            0x5E1FEF6D7D2FACC6ULL, 0x0CB0EEC204591B8BULL, 0xCAA1DF9E9C8CD9A2ULL, 0xCE570554D5805DD4ULL, 
            0x72635ECDFBBF5260ULL, 0xDAE384BC51D1D806ULL, 0x0647CD6EA78FA074ULL, 0x013AE3B595ADE787ULL
        },
        {
            0xEAA3411B23F02E8CULL, 0x8232939BF7380411ULL, 0xE4EAF6A89ACB1C04ULL, 0x7E96AF4E3010100DULL, 
            0x42A8E954CE319A45ULL, 0x10C5DEF95133BA13ULL, 0x43EDBA63C6973C72ULL, 0xDF09E172474192ECULL, 
            0x23D81BEEFEEE659EULL, 0xC28DC853ECDBAF9AULL, 0xD537FD52DEA105E8ULL, 0xAE758B4A462EB0BDULL, 
            0xC0FF70F0ADE80551ULL, 0x65DDF157ADF8BB6FULL, 0x93FE7109D32E7001ULL, 0x989D6E948B2FED4DULL, 
            0xE097B64F9ABE2458ULL, 0x1999075A3C8E5B40ULL, 0xEDE72A550DEF78C5ULL, 0xCDDC6DF7E4103298ULL, 
            0x2EAF7048521C4693ULL, 0xD621EB6839473DD0ULL, 0xB5DAA8F263E83F45ULL, 0x732F40709F921D28ULL, 
            0xB7C9002E9F9784CCULL, 0xE8EB30819F198F9BULL, 0x1702222C06E06C2FULL, 0x8CF9744DB9308096ULL, 
            0x67245B66047D3211ULL, 0xC2B48DEA2E58E266ULL, 0xDC5D3E470C96142DULL, 0x6E70E2E0A6885D7CULL
        },
        {
            0x5D13F69CCC82AF92ULL, 0x8FDFD10583C20681ULL, 0xCE6A5D8ED6E8F8EEULL, 0x4EE4F13037B31682ULL, 
            0xBCF745EAFA87FD0CULL, 0xE6A25E5D5C19846CULL, 0x4FFDBED839C26C41ULL, 0xC7B178E3A1A64417ULL, 
            0x2DD90BEDA4A39BB4ULL, 0xB5C9D0187A07561AULL, 0xA7CBC451DD74863CULL, 0xE62ED24771CF4C32ULL, 
            0xA076CB28681906F0ULL, 0xB8D737B7D8B7C71EULL, 0x24EA88D6D75D7D99ULL, 0xF62CB71E6123F933ULL, 
            0x3C2968ECA5E7E183ULL, 0x9DA3EEBD1073AB6BULL, 0x9CBF44DBE6C3BFE1ULL, 0x366A528686ED67BCULL, 
            0x8C0DF3ADE389D319ULL, 0x5C7C0F1F73DEB4C6ULL, 0x37F618AD3F86E3A6ULL, 0x9AF1545E64AB61ADULL, 
            0x043E425CFB1F7999ULL, 0xDC1DA559DB9B24B1ULL, 0xD68FF6D2D61EEDB5ULL, 0x919D3914F2BC3645ULL, 
            0x5080F7B9B7C286B7ULL, 0x22BB68CD616788BDULL, 0x60CEA3F0888A4A43ULL, 0x8D08099E77C26462ULL
        },
        {
            0x099D1C0390665DCBULL, 0xBCA8349D3BFAC6CBULL, 0x97527125D8252672ULL, 0x93EE3C6B8BD4530FULL, 
            0x4AE6AA2023E5D067ULL, 0x623FC74927DE9833ULL, 0xB90794333F1ED5D5ULL, 0xE44A4E06FAF0DF5CULL, 
            0x16D5D32BA1BA80B9ULL, 0x5D34E949DC59BE4BULL, 0x69661E4EE774C29EULL, 0x38605985465345E4ULL, 
            0x2746FA21CBF2EA8CULL, 0x26C8D2494C1BD683ULL, 0xA716C43FC5DF42BAULL, 0x7BEB32C77779EE54ULL, 
            0x88199D1D1055791AULL, 0x09A580F672C67AA8ULL, 0x72F080A7EF7C508CULL, 0x90BB07D8F849BE17ULL, 
            0x007A419236EE9360ULL, 0x112CFE1FD7F82FDCULL, 0x1C6A13B5E2291EEBULL, 0x3AED6A311C39DD82ULL, 
            0x6CA1CAF13CAE229FULL, 0xC1E3B9ECC55B166CULL, 0xEE0782A61D292AEAULL, 0x0E318C5974C67CBFULL, 
            0x77A8EDD2FC0B86A2ULL, 0x2F346722DD00E19DULL, 0x0F58F7DBDFE453F2ULL, 0x2AF64AD8F716BC20ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseEConstants = {
    0x93170DE491BCAE8CULL,
    0xFD626AA9F87F78E7ULL,
    0x7EC00655669D4418ULL,
    0x93170DE491BCAE8CULL,
    0xFD626AA9F87F78E7ULL,
    0x7EC00655669D4418ULL,
    0x1B75FB23685DD28DULL,
    0xED2DF1F25904DB60ULL,
    0xDE,
    0xF9,
    0xC9,
    0xEA,
    0x05,
    0xF0,
    0x0C,
    0xA2
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseFSalts = {
    {
        {
            0x8BDE3DD612EACFCAULL, 0x28BB906E52F0C26EULL, 0xD67E6A86BC24779DULL, 0x67A4C274B43D768AULL, 
            0x9CA4E44C91D79920ULL, 0xAF053C9F883C0E5CULL, 0xD5B0E954EEBCCCE9ULL, 0xA4BB5FF7093CC76DULL, 
            0x23A9E442F921DF2EULL, 0x90AEF5F7F15FB00AULL, 0x2F2B6241CCD33EEEULL, 0xC9CB67C0560B7642ULL, 
            0xF953861F6B8CFF5EULL, 0x4C09953DA7D5F653ULL, 0x19E5F341356C7B44ULL, 0x7952C3313F1D3CE9ULL, 
            0x367204899C454EDAULL, 0x001D03AE0508C4B9ULL, 0x864143974AEFCBA0ULL, 0xE62F03287EBD0309ULL, 
            0x78BEBF2CD0E19CC4ULL, 0xB79508CC3B1DBC31ULL, 0xAA80337366DD055DULL, 0xD265D66758BDE770ULL, 
            0x321219B8BAC14246ULL, 0x6A043BC3131BD7CAULL, 0xE36E972C039217B4ULL, 0xC18E0696D4E9ECD0ULL, 
            0x18B63C31375CA2C9ULL, 0x025A7FE5DD1AC555ULL, 0xF461CD11C5C7F996ULL, 0x3A4B32E1DC8E1C84ULL
        },
        {
            0xF058DBA6EED2781BULL, 0xD36E08C9DAAF22F3ULL, 0xFE83E172B2E6738DULL, 0x725D39A75025B7FFULL, 
            0xBD6D1541F42D642FULL, 0xFA9B09F6D938D22AULL, 0x0F8B4AB885DFC9F7ULL, 0x81DCA55BF22A5B8DULL, 
            0x10EE6B3DC6023152ULL, 0xDB5A5E61AE3DA12BULL, 0x2E474E4F47667D45ULL, 0xC441805CE278F42AULL, 
            0xD2D3996D4CE8DB75ULL, 0xDA7C48269D21F6DCULL, 0x7FC30506DB9B8AF6ULL, 0xEF2A448EC4854670ULL, 
            0x7ED7854236BF575CULL, 0x21054B359DED743FULL, 0xDC099C489BF3476BULL, 0xCC812E02847A5A32ULL, 
            0x491938A6411A26BCULL, 0xAC246557D0C560D3ULL, 0x40786A2D2F455645ULL, 0x0B0DDEE28F05C4E8ULL, 
            0xB5DB93FB828210D6ULL, 0x0C5E988C7FEC948CULL, 0xA4BA8FFFC8E66B1AULL, 0x4C16D77CEE7D6875ULL, 
            0x674629F0CC38E621ULL, 0xF74531D065A7A168ULL, 0xD8C0D70F9225C39BULL, 0x134A7C5C886ABF70ULL
        },
        {
            0x349CEB2812D1D53BULL, 0xC2A73FB8249728FBULL, 0x6A3D8CF5B35A1C39ULL, 0xF8C0B33836DFBB44ULL, 
            0xF24B588CB6FFCE52ULL, 0xDA74C28B79017DC7ULL, 0x4094063769B135F3ULL, 0x592820AF843A80F2ULL, 
            0xECCCAE5292B062DFULL, 0x1D1B101B44D9F44CULL, 0xC82B4CFF5F8AED38ULL, 0x881D80067CFB009BULL, 
            0xD5DEF68506B598CDULL, 0xA656C9447FACFE46ULL, 0xFAA0BDEB2F1F2535ULL, 0x7D3F6624BE23F8E9ULL, 
            0x1255C2C721E0AABDULL, 0x17A5FA57C91E7C42ULL, 0xBB5340C6D5C54F11ULL, 0xACB943A003F0E082ULL, 
            0xC1E03BBC897B8224ULL, 0x0B1777E6F4E6A33EULL, 0xA277B666EB746EFFULL, 0xB6926CB54C7F65A8ULL, 
            0xDCA6E9FBB6777C6CULL, 0xCAA1B30104A24C7EULL, 0x9B21D244C67D8EFFULL, 0xDFD3B4E25419081CULL, 
            0x61618B477058FFC9ULL, 0x8E7830EF6EC37E2CULL, 0x4002E7B4A871AEB3ULL, 0xF52A90C907698EA1ULL
        },
        {
            0x20D26FCA157070FBULL, 0xCCA8366FCC8EA849ULL, 0xEBEA1462577F73E5ULL, 0x420A88F6381C1FC1ULL, 
            0x20D3C204957F6171ULL, 0x54BD3B48E5AA428AULL, 0x8D26ECDC52504A56ULL, 0x11385AFDC0E86D1CULL, 
            0x1AAF59066B8A4C38ULL, 0x4C0BDC549B2E8A94ULL, 0x009A3679721CD074ULL, 0xAF3F564719E8906EULL, 
            0x76A5819543A15623ULL, 0x8E243A388A852B9FULL, 0x848EDF7AE951E192ULL, 0x1873B9947EA73722ULL, 
            0x18E23B6C89AE5E1CULL, 0x892836A2D53E91B1ULL, 0x33317AAF690A8808ULL, 0x8973E05785D51FC1ULL, 
            0xD6D336F64D1BCE0AULL, 0xE967F220192269E0ULL, 0xB17778B00C5B84AFULL, 0x1D96A21C4BB6A3ABULL, 
            0x8CE44BB3E8782BABULL, 0xD81E35F0CA5166C9ULL, 0xA6C6F65E38B8A08AULL, 0xF1E3F9C238ADB4FAULL, 
            0x9E28912977A8DFBDULL, 0x871368918F1739E2ULL, 0x90408DEFDDF87A69ULL, 0xD0A70949C767BB84ULL
        },
        {
            0x967F3F8CA0E10918ULL, 0x37EFFBE9BD2DDF73ULL, 0xBD26EA899930341EULL, 0x29AB72BD45B4A44CULL, 
            0x1A7CFEF55F37030FULL, 0x1F95208443AC10E4ULL, 0x61B0F935F4783497ULL, 0x7EB17CDAD81CD4E0ULL, 
            0x82C818820974D17BULL, 0x2078FE687BEAED16ULL, 0xDB4C50DE27580580ULL, 0xB2EEA068AB42A895ULL, 
            0x7A167AF956940CE0ULL, 0x8258C2EB542069FCULL, 0x08ADA8177E45A179ULL, 0x5A525F2F52A349E0ULL, 
            0x2716B07C753E4BA7ULL, 0x64C06783A823F588ULL, 0x429E1E64D0B69E18ULL, 0x6568732D59C52EB8ULL, 
            0xEAD47B486F7D3754ULL, 0xF860C133F138A05AULL, 0xA5C320AD9F185882ULL, 0xEF479868809BD15AULL, 
            0xF1A904D8290E0D92ULL, 0xFCCA284B7C637E83ULL, 0xABB9C6A0C153A09DULL, 0x5AE5A533A90E915FULL, 
            0x58733DACEA5CEF19ULL, 0x241157F615BD946FULL, 0xC4BB346E383A682CULL, 0x104F03F244D0CB19ULL
        },
        {
            0x49DEE40192F48D81ULL, 0x47ACB8FCD0347105ULL, 0xECFFCB97451D8F99ULL, 0xF7107FCA475B3211ULL, 
            0x349175131D7C43FDULL, 0xB091DD556CBEE36AULL, 0xDA034E9453B247FAULL, 0x1CC2FA4CB9E6B575ULL, 
            0xAD2B09E5ECD30053ULL, 0xA2906FF56BB6D82AULL, 0x61B13F031BC7CE2FULL, 0xE19B268D86AED9D4ULL, 
            0xE02A462BEE758011ULL, 0x743BB9726F3C9279ULL, 0x7E2493252D9EB3B5ULL, 0x20341DFD53B80A9AULL, 
            0x6775ADA356FD9DAEULL, 0xDADEDF239F6BEB93ULL, 0x532A98700696FB6AULL, 0xADDB6EF85217C86FULL, 
            0xE905A0EB4759F83CULL, 0xD027964C660E25EDULL, 0xA59259113653AA6DULL, 0x544C37AABAE72C85ULL, 
            0xC720C306C5650FDBULL, 0xEE0486AE8DC3E4BAULL, 0x41CDEA6C98BFD0B8ULL, 0x7CBAC5735C972E0CULL, 
            0xEACBCC55D5DD0346ULL, 0x64EE746A924B0DD7ULL, 0x3FB21AF09CB126F3ULL, 0x68ED41FBCD54B1FBULL
        }
    },
    {
        {
            0xBC32BC444633E821ULL, 0x146116AB22597B27ULL, 0xF552D913EF61409AULL, 0xEC1D3428678BA96FULL, 
            0xE4E3E0D7E22408E7ULL, 0x3ACEA7A2206571D4ULL, 0x37E9985435C6FE61ULL, 0x8D2B52637B5F909CULL, 
            0xFA3E106850DE7348ULL, 0xD2E4D1F57F57BD5DULL, 0xF8289104B4004A27ULL, 0x03078C2BDB2B2E42ULL, 
            0xD419D66949C83816ULL, 0xEF2FB6F5ECE42300ULL, 0x06859D40537EA662ULL, 0x2B30C647C6552439ULL, 
            0xC4B6B4C42723208AULL, 0xE3EDD86CE3392B53ULL, 0xC7C88898A6D31275ULL, 0x7611DBAA88D122C8ULL, 
            0x90F857C4E61FE443ULL, 0x49B59490561E655BULL, 0xB0B79297E50038B0ULL, 0xF9C5A1CA365CA10CULL, 
            0x3C00B0A76329E595ULL, 0x6CC60EFA69D01720ULL, 0x87C7CB197986FD91ULL, 0xD3FE7AF43D33D81CULL, 
            0xC26B9FE1479E7C56ULL, 0x265C32AEAD264333ULL, 0x81A689841FFEFC11ULL, 0x981D7F82EDC6DCE4ULL
        },
        {
            0x9145FD8948B75590ULL, 0xC4E2B0B6DA6D705EULL, 0x0D985EB476FE76BEULL, 0x9168A27F71571FEEULL, 
            0x3BF5C1617600FDCAULL, 0x628571090A6F07C6ULL, 0x34BF57AFCBAE8352ULL, 0x774AA97950D4AE56ULL, 
            0xC1E05255D801D894ULL, 0xFF12DDF4D61728AEULL, 0xF1C57CA0BE2804CCULL, 0x024277AAF8B08CF5ULL, 
            0xE2FE3B915BAB9993ULL, 0x89E8F123CF66F121ULL, 0xB9B6EF0E3E6F7684ULL, 0x1DF153F5312CD549ULL, 
            0xA6F6DF3F2499DF66ULL, 0xAD9E8CD7A00C2BF7ULL, 0x3FB8731E537D94B8ULL, 0x1FEF35B13F531355ULL, 
            0x452349B48F8AE232ULL, 0xEC09B97BF82934AAULL, 0xBC7FD4E33450CFC1ULL, 0x24A08275FFF555FDULL, 
            0x6A43E4DF23D68FAAULL, 0xA0598047E997B1A4ULL, 0xFD6CE5FE5B75FD74ULL, 0xF16420FD62C47CDEULL, 
            0xD0AAAA84CC0D7EB4ULL, 0x281CFFA3B9BCE948ULL, 0x44C313B886EDA292ULL, 0xFCD8D991FEC5D2E5ULL
        },
        {
            0x6AEC059464628A09ULL, 0x199E40381E42466AULL, 0x538FEFD2418F97F4ULL, 0x64CE150824989269ULL, 
            0x0BC115454B8B8B91ULL, 0x36D284B3D553778FULL, 0x5C815B15D8DCAD34ULL, 0x25E87D2FCB0F7931ULL, 
            0x7398C9D8DAFA8D49ULL, 0x43F956B99ADCD68CULL, 0xCDEFB52DA4DCFC6AULL, 0xE5F7FAB40D982832ULL, 
            0xCB87343BC13BA292ULL, 0xF263DD397F3425D2ULL, 0x3E4CED6883E38DE2ULL, 0x235554132724C97CULL, 
            0xE3149F45864E1E70ULL, 0x01BC20F5309C37C2ULL, 0x0BCE7CB955530232ULL, 0xE7045C318C551D93ULL, 
            0x9DBC662BE0A0B6F7ULL, 0x56269ADFD06B9406ULL, 0x668346667C80B7A4ULL, 0xA509C3E996C3E67EULL, 
            0xE4810800471C1233ULL, 0xD055490F1CF697A3ULL, 0x38C5D43313B9739AULL, 0xB90131330889956AULL, 
            0x40C08351C9200378ULL, 0xF7A29952FECAAF94ULL, 0xC208C8AAE88A2691ULL, 0x5C23FB8B4EE0A377ULL
        },
        {
            0xECD14A09934A6728ULL, 0x58B756CB35DE880EULL, 0x74D2D9A6A1155DDBULL, 0xDAC981CA5B0E4F6DULL, 
            0xC9AFFD9C895EA184ULL, 0x8F2BB69FE6E617FFULL, 0xB6BE4EFE80011931ULL, 0x6EA332A239898F9DULL, 
            0xBD1D49035184041DULL, 0x238AE1DAC17CAD75ULL, 0x6C23F8EF74BF384AULL, 0xD5CB1B426FED1934ULL, 
            0x35D3836C34DD7BF5ULL, 0x9BB08E5AE0B57FDFULL, 0xDFA1CC09CA4289DFULL, 0xD7D259824651703BULL, 
            0x5FD7F2486E28F152ULL, 0xD9525ED3821B564AULL, 0xBCD17A140DF55D75ULL, 0x849ED1EE558AD013ULL, 
            0x18D1CA81E3C0D76CULL, 0xF84EC10E184BBBEAULL, 0x28DD2BE6FAB72CF4ULL, 0xBEF76136E5532C3EULL, 
            0x957EF7B946165776ULL, 0x15162607A7413D3CULL, 0x8AFDE06A2AAB0336ULL, 0x7905237179D683B4ULL, 
            0x52D2BAEEB3217D7FULL, 0xE4401029F67E1B66ULL, 0x7433FDFFA3A76B28ULL, 0xA2D16FC1C1D41960ULL
        },
        {
            0x101979802EC972E3ULL, 0xA1E82CB963E9B275ULL, 0x2E3B660DE362F37BULL, 0x23A693A9CBAEBB7BULL, 
            0xAB3B9A22933CC1A4ULL, 0x048029437A9C5D62ULL, 0x24C9DBE9A39D16BAULL, 0xE83C2587171B0448ULL, 
            0x3B933D5741D33404ULL, 0xC7033EC1BB06B704ULL, 0xC63E83A3CBD7EDCFULL, 0x498A1A620AE610D6ULL, 
            0xEB88501C785FE4C3ULL, 0xB6CDF56C216B380EULL, 0x54759FD58BF291ACULL, 0x3F9524FDB61CC711ULL, 
            0x65C2E35214D0D77AULL, 0xC81803A70A7BBFDBULL, 0xEFD893EF4D0F4737ULL, 0x336EF59A80F6A06DULL, 
            0x01C58AA46093AAA0ULL, 0x14318DA40D5317BCULL, 0xAC53B0DFC3F6F5FCULL, 0x2CDF582244B0A982ULL, 
            0x8F21260C8869AB8EULL, 0x840C4D45EB7D2203ULL, 0xAF6D49DFF867C751ULL, 0x94E973EB124E001FULL, 
            0x0CCCFEBACDB2079EULL, 0xB2CA95700DA6374EULL, 0x69C0113BF496282FULL, 0xBAEEF16027AF06E2ULL
        },
        {
            0x5D9E29B850CC9E58ULL, 0x2EC06F01D7E37B38ULL, 0x150CBCE011965B91ULL, 0x7CBDD4D73D95078DULL, 
            0xB96F0009CF444283ULL, 0x88493C20E7D4F6A1ULL, 0xB9BB6988EA5E2718ULL, 0xB240D8ABE31E50F5ULL, 
            0xEAD73AABFA15D0F4ULL, 0x9930DDBFFA07203EULL, 0x619E1AFB1D9E6989ULL, 0x7DBB2AF15E3EA7B7ULL, 
            0x64FCDAB612CF8A0CULL, 0x155FA806959B0F0DULL, 0xD47C0D7FDC3131DFULL, 0xFC4E62897AD22B0EULL, 
            0x8417504A888903BDULL, 0xC90ACE53D419CDAFULL, 0xE6F814DDF566BA96ULL, 0xC487F108CEC49868ULL, 
            0x6AE5DB9BD6C02F6BULL, 0x95644469405E1701ULL, 0x35B750344D17A4C8ULL, 0x864B49BE9FE4F8E0ULL, 
            0x2982895BBA4CCE47ULL, 0x9B38F7942B36B128ULL, 0x5537848462680EA4ULL, 0x6B23752786754A90ULL, 
            0x40947F6422417FC2ULL, 0x4F50D879BFE99298ULL, 0xAE0184E27C322816ULL, 0x184B99DE5FFB2DE5ULL
        }
    },
    {
        {
            0x8F2F6E4D9FB82C2EULL, 0x67969F47721EE565ULL, 0x4C3DDFF9CD64C705ULL, 0x76B75D0EC65517A4ULL, 
            0x76831E667CAD9831ULL, 0x9434AD448C309D88ULL, 0x9B2C7A4CD4A05BE9ULL, 0x334067616063A1F9ULL, 
            0xE2FB9F09C675F52AULL, 0xD47C84DB0A79CB44ULL, 0x57F26740635A85C1ULL, 0xD2DED54F8D2F3562ULL, 
            0x03B183B41A6919B4ULL, 0x8712288A557A462EULL, 0x48ACBB8054BA1E9BULL, 0x904B733DD890EB61ULL, 
            0x38E65A2A6D614767ULL, 0x69F3EAE2C3A314DDULL, 0xDF1EE9115F8C936EULL, 0x08C27B68F4A1C9B0ULL, 
            0x7CCF2EEEBF5F5294ULL, 0xE7904F5EB2A9F033ULL, 0xC8F42BC39B509FC3ULL, 0x6371A45ECB808F04ULL, 
            0x2EDDFFFB4E3B1BEFULL, 0xAC4198F703508F20ULL, 0x77186E4972B663DFULL, 0x83EC79B4CD3230B8ULL, 
            0x1DEC5250C3A10716ULL, 0x1ECB840D03B85594ULL, 0xAF06320FBE1C4DA3ULL, 0xD5D33DBB7BE54B8DULL
        },
        {
            0x089E2AFCDD212CD0ULL, 0x7D3219A2A40CB1D8ULL, 0x20B278533DD618F8ULL, 0x297A4C801863D9B4ULL, 
            0x6A11885B1EADDFB4ULL, 0xC9D9B38B6480BBF1ULL, 0xD8F19D8042278835ULL, 0xDC240F5224A4F0F8ULL, 
            0x143B84AE3C08DCACULL, 0xC23F059EEEC94439ULL, 0xC76FA8AA39A5873EULL, 0x9CDE068BF7FEC684ULL, 
            0xAEDBFA443FCD43C3ULL, 0x2FE02E6EB6602388ULL, 0x4E80DF25028A5D79ULL, 0x5EF428A5AE29749BULL, 
            0x8CC401B54CE96422ULL, 0xE5064AE17DCB5FEFULL, 0xD1C53F6729699DDEULL, 0xDEF8ED6C4BDCD21CULL, 
            0x3DF25A035FCDB297ULL, 0x35B8D50E3E1B97C4ULL, 0x3A4D4D9A9F68D9FAULL, 0x46F283576CEC2B35ULL, 
            0x8689A0A28D5413DFULL, 0xE1D441636B8122E6ULL, 0xFCD10534CEBA748FULL, 0x65487951E4D32287ULL, 
            0xEB773AF1563E5A2AULL, 0xB3BD2531DA756EABULL, 0x7CC0D19CFCFDEFCCULL, 0x6C9C8D393F1EF994ULL
        },
        {
            0xABEE67EEA31B2D41ULL, 0x20C79E1FD79489E1ULL, 0xCCE2D57FD3FB8ECCULL, 0xF603DD3F42461E7EULL, 
            0xFF0C7E36D42C5778ULL, 0x52AF35DD35A01EE4ULL, 0x952A384DF0233DE1ULL, 0x8C6E9D50B5303CC2ULL, 
            0x880D585CDA11D87EULL, 0x4BB89A10CD55CB0DULL, 0x1240C6EF11B1F3C8ULL, 0x24BB2D69CABF812BULL, 
            0xBFF5CCE0E65815C0ULL, 0x30FE73E2257F08BFULL, 0xAC93A251370C2F63ULL, 0xCA370607BC1719C3ULL, 
            0xA129BAAFAD6B2F42ULL, 0x52797D509736A419ULL, 0x9139BA020553E54DULL, 0x50592CF52865ECDDULL, 
            0x5A71A22740914396ULL, 0xB66C60BAEDF803E6ULL, 0xCE3E22690CC2D487ULL, 0x72C03A533EE52D81ULL, 
            0xCBD5A905C2058A82ULL, 0x684A2861C854B932ULL, 0x334BBC7F7BB8C9B0ULL, 0x425813A78AA0FB0EULL, 
            0x3FE12D496FEBC4E5ULL, 0x66287EADC6122AC5ULL, 0x4A561CD7A73FAA38ULL, 0x202AB0E86A8D7104ULL
        },
        {
            0x55A44D05CA92E50EULL, 0x96805E025E3EF4EEULL, 0x1E2858FA4A0E9352ULL, 0x224149046C115171ULL, 
            0xE9D3480A40C1B56CULL, 0xAE5034FEE8FDFC5EULL, 0xB5BD9108CA0B9270ULL, 0x9AE0B01A4F99FB15ULL, 
            0x35CA1A907FDE5C31ULL, 0xAF8D3ED1EC9BA2DBULL, 0xDFC2BDAB2F060B08ULL, 0xD6C21E952168EC7AULL, 
            0xB65BBF5406A32E73ULL, 0x22E2C448FDBA7A44ULL, 0xC9AB09BF0D219CC1ULL, 0xE4910CE2E0EE69D7ULL, 
            0x32580ACDB902B66EULL, 0x6D0DD8D8897AA3B6ULL, 0xD2C99B6321EC8A42ULL, 0x9E775E6FBBD24539ULL, 
            0x3FA2BBB974D271EDULL, 0x89468E360AC42D3BULL, 0xF391BBC7181E9B20ULL, 0x8BBC76327684226CULL, 
            0x5F5C42640FD4B312ULL, 0x84BEAD27E7AC7768ULL, 0xA43FE657FBDB8F6DULL, 0xAACBC565069D17DEULL, 
            0xDD3406A423474F1AULL, 0x063CF1C6E806AEE7ULL, 0x1317534C1507F2E7ULL, 0x63CC4D684E4B59CFULL
        },
        {
            0x5C0D0F5D77991FA9ULL, 0x68C598E2B1063AE2ULL, 0x4136FA4FB083AE48ULL, 0x2F2C3E05E49360A7ULL, 
            0xDDB63740EEFD426AULL, 0x8827331233367754ULL, 0xFE26D5C8E942DDD5ULL, 0x35FE401A1EBD9E23ULL, 
            0x08689861F203EA36ULL, 0x5CFC2D86FD31400BULL, 0x0F8449981E0CB52FULL, 0xE23F75A0468F9123ULL, 
            0x18A509CDE5F2BEEEULL, 0x40DFFEAA304DF95AULL, 0x7C2CDCE9A0CC84F8ULL, 0x60B1730A49498A5CULL, 
            0xC6B461DD01A6FC4FULL, 0x397DD65435BB4DBCULL, 0x4DE2EF74746A0E5CULL, 0x950A47BE849505C5ULL, 
            0xEBF520688D9118F0ULL, 0x171CB41C31E30F94ULL, 0x0980380849AF4865ULL, 0x88DCA029350B97A1ULL, 
            0xDF4509B4538E8335ULL, 0x1EACD89D7A963909ULL, 0x37F9F0C0AA45B4F8ULL, 0xFD9000D9BAC33FCCULL, 
            0x04DB868CC3B15A0DULL, 0xEA2E0EA0F9A045B3ULL, 0xD0026DAFB7538F04ULL, 0xBEB991495076BB70ULL
        },
        {
            0x57DC8B3297D5ACEAULL, 0x4C4DAAB093B0669DULL, 0x168A72DADC0FC7B7ULL, 0xABAD5AC8B480F2F3ULL, 
            0x22DC501B55B57F7EULL, 0xCF39B78E3D642728ULL, 0x2A30AD36089B336BULL, 0x621D2AB2A2EF9535ULL, 
            0x6ABEAD69B01FF47FULL, 0x861D94185825D3A8ULL, 0x363FC8D5C52F3798ULL, 0x560F613AB71A78C7ULL, 
            0x5545A6FA7B287E68ULL, 0xEDCBD3F36386D7F6ULL, 0xAF4454CF490699F8ULL, 0x7375FD3DB692EAC6ULL, 
            0x226574AE7079599EULL, 0x89F52DBE02F8BED1ULL, 0x7CE82AC9A93511C0ULL, 0x244F98390E71E583ULL, 
            0xC5D7BDE6DE33E031ULL, 0x92015F6505972063ULL, 0x0503074911342201ULL, 0x441F3BEE893183ABULL, 
            0xBA09EE9264BAFD54ULL, 0x3A6E90436AD53FD1ULL, 0xE0A524CC29BE5F3EULL, 0xB480D7F20F3902B0ULL, 
            0xBC1FEF63C913405AULL, 0x3D2979DF8561415EULL, 0x4FF27190B9135F3CULL, 0xFE619904F89063E8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseFConstants = {
    0x04BA986A1136A2F3ULL,
    0x205D6A350F01CB7FULL,
    0xB5BE0D542784829EULL,
    0x04BA986A1136A2F3ULL,
    0x205D6A350F01CB7FULL,
    0xB5BE0D542784829EULL,
    0x42BF3DC8DC64ACA6ULL,
    0xF9A3492E3FA0A170ULL,
    0xD9,
    0x69,
    0x90,
    0xAD,
    0x1C,
    0xAA,
    0xB4,
    0x97
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseGSalts = {
    {
        {
            0xA648E0CAD4D3F4E0ULL, 0xACC997BC5ABD771BULL, 0x420886EB4EF4F824ULL, 0x3FF7D16F04F2CEB7ULL, 
            0xFAB03DA5064F6779ULL, 0xF3DF4396FB4BD646ULL, 0x011D483EAB441618ULL, 0xB8ED2C2B4730C974ULL, 
            0xAFEA78595D2E5C91ULL, 0x3085C48AA316147DULL, 0x6D9137C782EE5081ULL, 0xA6E76E1891B000D1ULL, 
            0xA6BA660B2CED7C67ULL, 0xF20E91B0DEBF0E43ULL, 0xAD58FF555D6123A1ULL, 0x8D214F1E9433896BULL, 
            0x44FE96BB9EA933EBULL, 0x012FF1A0F1FE46C1ULL, 0x66F8B4D123496095ULL, 0xACCB529B3BEE5B67ULL, 
            0xADA06FCE6DD9F44CULL, 0x7F6C332126827F39ULL, 0x30159ECFB1F83843ULL, 0xCF49D3E9FBB946D3ULL, 
            0xEEA081182B0F2CAEULL, 0xE942919FD16FC481ULL, 0x7ADEC8C8F8D03C5EULL, 0xC38D78A91C69B1E2ULL, 
            0xDC1909411F17795FULL, 0xBE4F044FFA6687A6ULL, 0xBE2CD7D22DC999D1ULL, 0x957007CB53492EE7ULL
        },
        {
            0x3B0E56EE21951739ULL, 0xDECD1A634DEE5958ULL, 0x3289CE3FBB727B2BULL, 0x0E3457193CA3688FULL, 
            0xE0291D8E9FE250EBULL, 0x0B9149493DAC2344ULL, 0x2188FF186F60A08FULL, 0xD5FA80E466A9B55CULL, 
            0x5B931A12C9A0ACE5ULL, 0x25AC52D0D140178AULL, 0xFAEEAC7C7F622DD9ULL, 0xF9149B29820C2D71ULL, 
            0x6086E218AAD20F75ULL, 0xF3026A6AE8F40A12ULL, 0x929872DB5C78105DULL, 0xF3CF831024DFE6AEULL, 
            0xD09CDFD03821E4B8ULL, 0xC301CF5F8921D23DULL, 0x71BC64B1851AF349ULL, 0x13D92DD6A4836720ULL, 
            0x23F849CFE107FC33ULL, 0xD8C1568768764822ULL, 0xA0132FC2FECBCD51ULL, 0x6F6700104A91EB39ULL, 
            0x7E5C9A921ACC6491ULL, 0xF5D0EAED48259960ULL, 0x12F885807E2AC404ULL, 0x4B2F5B5734B9183FULL, 
            0xA98F0C7168E8388DULL, 0x0B33B8038D87D5EAULL, 0x622C6DBBB525E95BULL, 0x241D4D7F06941F87ULL
        },
        {
            0x51B38FA2C73500CCULL, 0xFA780D3FAF4D4351ULL, 0x850F66E14640ABD7ULL, 0x70BCFA3036B466C5ULL, 
            0x8F2511EBC203B939ULL, 0xD2F2E3420FC2F39AULL, 0x0067A0DC80725379ULL, 0x1BF3A069DFD20018ULL, 
            0xF60F1E0736808C31ULL, 0x0B7E84FAA53F3D67ULL, 0xD2CF12B5433B8D04ULL, 0xA998CC7DCE25462DULL, 
            0x5D0429847D4FBADDULL, 0xE70F4E659D003588ULL, 0x172021733BB597BBULL, 0xF38C1469A5FD7A10ULL, 
            0x8EB535670F5F1753ULL, 0x3EB1CC05F1E97382ULL, 0xF0CC9D1BA19BF427ULL, 0x6B4B14070D3182D8ULL, 
            0x6D2C1EC2FCC12085ULL, 0xF6AE5E2A0D9DF939ULL, 0x15B569D0E0477C3FULL, 0x30B109B93AB8193EULL, 
            0x0BA567734198D87DULL, 0x4D197F10060FDF04ULL, 0x282382F4607E1DD7ULL, 0x2D128968C85AD84FULL, 
            0xBDFB0F8C6EFDE92AULL, 0x5C84344422A976E8ULL, 0x92CAA6D883B87EFFULL, 0xC180D0834FC75582ULL
        },
        {
            0x92DD01BD1DCE6093ULL, 0x54729D776E3EE6BDULL, 0x4D8FF7A832A2D2BCULL, 0x776A629B6574ABC7ULL, 
            0x74DDE783F2F32249ULL, 0xDCE9D0AC96284139ULL, 0x78E2716288AFCAC9ULL, 0xFA3C20486A2BC6AAULL, 
            0x9B425EB15064DF60ULL, 0x7CC0FAC193316102ULL, 0xCCDF39C265FB2949ULL, 0xE7C8A41726E0AB7EULL, 
            0x764D3970D11960FDULL, 0x33BBE68D067B35B2ULL, 0x52E33C9F28B8A071ULL, 0xF0ACAC74C6EDCF74ULL, 
            0x54DB9171D6C0F8A2ULL, 0x5D89564412E51053ULL, 0xEC8E07E79CB88E4DULL, 0x6BD740660A8D5D29ULL, 
            0xDC90249657399C53ULL, 0xE611AE7203E749F2ULL, 0x0CD3F2D04112094DULL, 0x7BF805FABB97F256ULL, 
            0x4155ECF387CED338ULL, 0x3657286FC8A3D4BEULL, 0xAD496C9FEC528B5FULL, 0x899057A00D17E5EFULL, 
            0xC2A8F8EA6331D39EULL, 0x05D2F3E0098D08EAULL, 0x04683763200D0933ULL, 0x7951B93B3895A566ULL
        },
        {
            0x4665888213C50781ULL, 0x84AE591F0F6C0962ULL, 0xC9EB9F77BB78A95EULL, 0xC21D63160EA88336ULL, 
            0x57F119F7ED1E2C57ULL, 0xD39A279B9EE268B6ULL, 0x1906289165A45506ULL, 0x953DA58F2F73B693ULL, 
            0x698EEF412561E060ULL, 0x2DC8E290F9B818DBULL, 0xF164C1EF50E849BCULL, 0x08F2D247383C6666ULL, 
            0x2B68BAEC6BDE7961ULL, 0x284A02D42A4F106CULL, 0x4C55738B1AA4E0E1ULL, 0x8603DF4C240CB84BULL, 
            0x1D2FA8E2458884FFULL, 0x42E5933CDC0E87F5ULL, 0x54909A05010BE410ULL, 0xD32A03CA4028C9DEULL, 
            0x48F6D973660CC790ULL, 0xCCAF72D578FAB1A9ULL, 0x5BB64D962E685F0DULL, 0x79BA2E91E8A9B271ULL, 
            0x0EB4D8F7BEC4744CULL, 0xAA7D31CA011F8BF3ULL, 0x5E30D14711B291B9ULL, 0x7D0E23E0ABB536CAULL, 
            0x054A78243720A08DULL, 0x7B3BA88DCF5C4967ULL, 0x8418E120C9E09CE6ULL, 0xF4FF0887C04B08E6ULL
        },
        {
            0x3AEA785A83086E32ULL, 0xE8D725454B732704ULL, 0x8AA2DCD1A0EAD64AULL, 0x05AC5FD7578BF3E2ULL, 
            0xC2C249BE51A0F28FULL, 0x3A22F78820299831ULL, 0x7A6338C1424A901CULL, 0x6786AB0BF2BF058DULL, 
            0x8279B6CED9132845ULL, 0x7C2676E35495BC51ULL, 0xF44D9AA8CB824662ULL, 0xE6E8A19136F800E3ULL, 
            0xB7C5B12DE2062A80ULL, 0x2BF76901C303509BULL, 0xB160B6C4FE32E51AULL, 0xE136918AA22D0215ULL, 
            0x0E393E1E58B6BBECULL, 0x5645EBA69009C2D1ULL, 0xA1BA727999D8652DULL, 0xA590407D767F44F8ULL, 
            0xD38EDE6464C3AF8DULL, 0x2274F59453E60619ULL, 0xB0FDB90537BFBC74ULL, 0xDCEFCA0C8C008DEEULL, 
            0x645EFF38D47D844EULL, 0x0CE551E8C5F1EAF3ULL, 0x8160FC20680B086DULL, 0x6DEE65387FFB862DULL, 
            0xB6598F7F855DDD79ULL, 0x02B6CA3C17BCB806ULL, 0xC63287026BBA6E63ULL, 0x3C2E5BBBCF8A1CE6ULL
        }
    },
    {
        {
            0x47FA858539CC68E8ULL, 0x4F61E3E4EF33553EULL, 0x53056810DD913685ULL, 0x5F3BB4A653DDF49AULL, 
            0xE9BD66D6B471614AULL, 0x46DD4B5F1E7C87A1ULL, 0xA99AB6ED3D9E78ABULL, 0xDAA0506DD9938CF8ULL, 
            0x7BA0F0A61F210389ULL, 0x4D332E832255F816ULL, 0x87020138EF4446C1ULL, 0x1C51B6658EDBA7B1ULL, 
            0x0C2CADB7908C7EA0ULL, 0x9BDD74AAA9B60BA6ULL, 0xC4CB7A30765F8484ULL, 0x696282364CC87833ULL, 
            0xF5C36B405A8924AEULL, 0x44C86EA485099C8CULL, 0xC209CBF033F9C6E5ULL, 0xB82985D5C688F69FULL, 
            0xEE6BC61C19E7192BULL, 0x7771D995FB164FC6ULL, 0xBBA8C56564BD4593ULL, 0x7177C665659A325BULL, 
            0x45FFA53F9146B8FDULL, 0x192B216616F2691BULL, 0x670AFB75F3C60056ULL, 0xEEE69974B1AD84F8ULL, 
            0xE0C53D111870E9FBULL, 0x2A5E3A7C7C3607A2ULL, 0xAD7C63805286D0DBULL, 0x25CC36F5DCD712B5ULL
        },
        {
            0xBDD6EAACBA675391ULL, 0x1458EB48B09DE26AULL, 0x13249E01C59FCC20ULL, 0x38B0DE6A79DD4417ULL, 
            0x5ED45E937B47D542ULL, 0xC09F95F6224447A6ULL, 0x5295BF0991112466ULL, 0x485CA04E43FA5918ULL, 
            0xFDBEC7077BF6E80CULL, 0x781868F5B566C49BULL, 0x786D469A9B185C26ULL, 0x1AE952901DD61315ULL, 
            0x60FBB8D3B76F0F6FULL, 0x40BF94B51B061E8CULL, 0x82A2A226586D2605ULL, 0x7C0213223B17FAFDULL, 
            0xAB620D7D4D238785ULL, 0xEC211F3F9811A28FULL, 0x11EF98DEF1F5643EULL, 0x30897B6134BA9CC6ULL, 
            0x143321EAAD5A3B77ULL, 0x50244441FD1B8265ULL, 0xEA19E67F727D9B69ULL, 0xEDAAB2E1B73F1437ULL, 
            0xB688CE8989AE81CEULL, 0xAD307091FF888FD7ULL, 0x20C2EE85BDD253CDULL, 0x7F8CBE7C2EE5F186ULL, 
            0x41AF23F93E4EE69AULL, 0x65604F690E64F7BCULL, 0x7130A22B163E4CD3ULL, 0x6FB38D26DDC7BA75ULL
        },
        {
            0xABF2484D9522B2D2ULL, 0xF5C8FCC112429053ULL, 0xB811A80AA64F4526ULL, 0xCDA51769FD3A62EEULL, 
            0xF02270D8D4476A1CULL, 0x0519CE7A0F1F26BDULL, 0x2BEF8B0A34D40014ULL, 0xC5E886A3F0FA9B8BULL, 
            0x346CEC60980498D7ULL, 0xC2A42E20B720C2E4ULL, 0x96D3E1EE3C7F3871ULL, 0x0A31EDBC7883EB2EULL, 
            0x7FF6C3411C04F93BULL, 0x8F9777C2246EF147ULL, 0x378B8E01D3C87C77ULL, 0x266DEAC990816B8CULL, 
            0x88E59307FBEECCCEULL, 0x13F5B76F874BAF10ULL, 0x044F558081D816CEULL, 0xA8FBD4F7227980F5ULL, 
            0x19A512FB2BCC8B70ULL, 0x01F2426C412F2B65ULL, 0xF2F152A4A7C3A911ULL, 0xF01165586288496CULL, 
            0x0AF318B162AC683BULL, 0x23E237650FB411D0ULL, 0x039AB97F4DB74160ULL, 0xAC1780F926BB849BULL, 
            0x8B2AADFDE4EDB103ULL, 0x43F48EFE4F5AE005ULL, 0x9F745FD938A1961FULL, 0x69EDF2A7584C7D0EULL
        },
        {
            0x6D9E629AE2F0CA0FULL, 0xFDC47CD216DBDB27ULL, 0xB5399FC249C73C25ULL, 0x2BD5C57AC246717DULL, 
            0xD65FE12323B4D09EULL, 0xE414094B1FA9B9E2ULL, 0x82C6D13A9057A19DULL, 0xEA969AA1C411EC7DULL, 
            0xF555CBA743B1B26BULL, 0x4DD30FCB0D1A6F17ULL, 0x9CD11086FE5510CBULL, 0x4C13DB94B5D86AB8ULL, 
            0xD34DB1FBAAD8F2E9ULL, 0xFF6AD555D7A5C1CFULL, 0xFDCE8FEB60AC5AC7ULL, 0xF3FD8424E979F165ULL, 
            0xA9209E8C851EBB31ULL, 0x7060F4D23D7DCFB4ULL, 0x7BB31081722D33D8ULL, 0x91B96C74EC27E840ULL, 
            0x118A61273C8E23E1ULL, 0x0812C9A2A3B4178FULL, 0x424A10AE53908F23ULL, 0x0CB0D5394CBC64A7ULL, 
            0x9ECC478417D92001ULL, 0x653BC11B37AC5E98ULL, 0x2BD799B9C88E7653ULL, 0x0838EF97A6E6C573ULL, 
            0x6452DA6C0021A8C9ULL, 0x2EEC72129ABFD43AULL, 0xD5ABF94D79A8977BULL, 0x77876B7496B9CE47ULL
        },
        {
            0xDDAF6D10ACCE1AFBULL, 0x22C85AF40A014281ULL, 0x6E72CDEF975EEFCAULL, 0xB97E7635B661D5B2ULL, 
            0x14E06C55BBE4A8B7ULL, 0x6836D4B4BD37C414ULL, 0x4FF200F47075B79EULL, 0xC655EBFBFC21F7D9ULL, 
            0xC25E2A683806E986ULL, 0x89EDCA1F6029A953ULL, 0xAC4304C40BEDBB82ULL, 0x9FB290CFD50BA6CDULL, 
            0xB15809D76D9BF4D8ULL, 0xE26DB638DF73285BULL, 0x244F442E0F6BA3E7ULL, 0x0E210F04E2ACDF86ULL, 
            0x10F478ABDDB67CE8ULL, 0x43800EE0226D76BEULL, 0x81019959065A932FULL, 0x209B5DD16DD07CF8ULL, 
            0x4CD4BC1533821736ULL, 0x64B64C1F2CDD5779ULL, 0x0395056FCEF91F6AULL, 0xD346F423078A3BBCULL, 
            0x462B38103BAF8114ULL, 0x03A853EFEA8AEFA7ULL, 0xF7674E8CC77D8AD6ULL, 0xE741D496BCEDA5B8ULL, 
            0xAA22FFEF305B06D4ULL, 0x90F9C3A9FEFB54F3ULL, 0xD350629251B94878ULL, 0x6C3EED994815DC76ULL
        },
        {
            0x7F3280794FF6EBABULL, 0x93B5ACD37ECDEFC2ULL, 0xB012A4B37C7D81C5ULL, 0xF17EBD28B0A4E8FBULL, 
            0x6DEEC723AA441476ULL, 0x5E530FFC3CF55FE4ULL, 0x40242E37EBDF1619ULL, 0xD4A4D8A3F9BB32F1ULL, 
            0x6CC2B4BC520539F2ULL, 0x0E7CFFE521727DA0ULL, 0xDFBD03CC87A6A024ULL, 0x51A7D064EDF3C902ULL, 
            0xE2C2A683F25F9333ULL, 0x9694CC0DFD2795F2ULL, 0xBFD4C7853B751DC7ULL, 0xE11045AF65D6483BULL, 
            0x22EEDDDA987C8E27ULL, 0x39081BF392785227ULL, 0xC8885798E94C3BE1ULL, 0xA46EC2F338C413A1ULL, 
            0x64726302A0676AD8ULL, 0x715B518B82AB56BFULL, 0xC86570E3A1A23047ULL, 0xCA59677553C1B87DULL, 
            0x23CEBE3AE36E2113ULL, 0xBC136C5CD31FE3B9ULL, 0x32C3B1DF5E664418ULL, 0x41DE816FA96E95B8ULL, 
            0x8A33822FC75508D3ULL, 0x319F534AB9B90BB8ULL, 0x31EBA538F766EA2BULL, 0x18B00D9F52F2C07CULL
        }
    },
    {
        {
            0xC2E4758F0C4E0D02ULL, 0xC7AE0F3770E0476BULL, 0x4F26278A4D46B162ULL, 0x88D4CA6AF8791FAFULL, 
            0x11BF07235C34AEA1ULL, 0x62C55E8DA43368B8ULL, 0xA1477454E928C93FULL, 0xB715777AB564F1A4ULL, 
            0x3DBF5771DF6CE1FAULL, 0x9D7DFED706677F5DULL, 0x59017D2D524873F6ULL, 0x7DCB8F88F405851EULL, 
            0x56FE29FFB1B69123ULL, 0x7103E80E12CB1528ULL, 0x4F3D4F0954881B28ULL, 0x5C1C0EA7EC99A69EULL, 
            0x7FDAE08A1BFE65DFULL, 0x508B928C9D27A971ULL, 0x97DBBB400CC5297FULL, 0x180F00E729C87A4FULL, 
            0xC736C3A75BB8C106ULL, 0xA241D67737D09082ULL, 0xCDA0239FFAF03A8EULL, 0xD25C96E7DD237DBDULL, 
            0xC6E29D963E42E4E4ULL, 0xA0C655C9AB53EE56ULL, 0x5F42CD11C37359E8ULL, 0x0E83D1E4B8B3A187ULL, 
            0x8F304C9AC02B14DEULL, 0x7312B15BACF0690EULL, 0xE81AE25098A4C6F8ULL, 0xF4C62A61028D9C3CULL
        },
        {
            0x7ED26758868B945DULL, 0x66FDAAABB283F307ULL, 0x14350E9707032DF3ULL, 0x2E3434C1B12BB951ULL, 
            0x20C02D2D6CE2E123ULL, 0xAA5676EB331698FCULL, 0xD41B2C22B1451304ULL, 0x98EEA9D436677FD8ULL, 
            0xAEE6D97BD0B30569ULL, 0x1F0FC7B361944C7FULL, 0x16D07DDF552CC6B1ULL, 0x6E91D116D7BA6F35ULL, 
            0xFEF7365B5A948874ULL, 0x298F775E899D5206ULL, 0x418B5BEC018B3D32ULL, 0x5FE43234A9DA85CAULL, 
            0x7199C23D2467A395ULL, 0x3AC465B24A770873ULL, 0x47FC9C04E79A4686ULL, 0x47C57154679A3618ULL, 
            0x283DE95F82F8D4AEULL, 0x47EA114299B93E8DULL, 0xDA9E0C92009E82C7ULL, 0xE46124A4325D263EULL, 
            0x04BF75C3692733B4ULL, 0xCFA898C38BF8E238ULL, 0xA80E877073450891ULL, 0x37F10609AD908A9CULL, 
            0x8052AB3E7B1871BFULL, 0x1237E87FACA1B0CFULL, 0x00EF3913BBDA6DF4ULL, 0x51CCC48C6190C8A0ULL
        },
        {
            0xFDECFA91A3B9C39BULL, 0x39367DF0D435599FULL, 0xB9BF83E2FE566496ULL, 0xFF27E64771FC906DULL, 
            0x2E42CDCF354010C7ULL, 0x3513CD76FD210B6FULL, 0x471C833DAECBBA67ULL, 0x6E191176897DF23EULL, 
            0x218A8446C6EB2D15ULL, 0xF573D0BE2FFF56F3ULL, 0xDA769C28BB716C7FULL, 0xD20228829C21C0F5ULL, 
            0x619555FC4D6E0987ULL, 0x6901D38BAE174F5CULL, 0x4DB63B895AE3A59EULL, 0x6C2B01BCCE10CE57ULL, 
            0x73B919B45B444BA0ULL, 0x863E2914D0A8E013ULL, 0x6343955D7A6556E7ULL, 0xA280836F865795D9ULL, 
            0xCA6A4FDE5E8DD71FULL, 0x8634E9ADA41757DCULL, 0xE17C20FD3392F07BULL, 0x942F5DD2D85CEA7FULL, 
            0x0D3A2C2230FB1E2CULL, 0x9AC83E9992263CB6ULL, 0x728E0523E06893C0ULL, 0xB698C7F1CED00D2AULL, 
            0x5AE83C0BE4FE12A7ULL, 0xCCDA9D2D672B14FCULL, 0xEFC1AC5877B5D0F5ULL, 0x34ED1B6DF022DEF0ULL
        },
        {
            0x2220DDAAF3A5D061ULL, 0xDEE3DE5FC892C681ULL, 0xD94E424B0B0C5D24ULL, 0xE5A2B2181177D8D2ULL, 
            0x73C46179835AD4F0ULL, 0x42A1E95FD1ECF0B1ULL, 0xD1A58EED74CCC537ULL, 0x090D192AFDB2A0A0ULL, 
            0x4808EA988BF0D120ULL, 0xDAF8228F51503B93ULL, 0x6D23EDA93163AF16ULL, 0xC7C1DD627EB7D59EULL, 
            0xBF308DD3B25BD272ULL, 0xA28BE6BF740163AAULL, 0x609F11FCB8382C70ULL, 0xE1521F3671815797ULL, 
            0xCC9DBAC0C0908439ULL, 0xE2D9EA17BE71766AULL, 0x1E2F37272201E2C2ULL, 0x10D9255660DDE9F8ULL, 
            0x393FA3C433C729E1ULL, 0x225DF537292611A2ULL, 0x9D818DBC53A486F7ULL, 0x1CCDD365D0A5B27DULL, 
            0x8A87D5A128A4B678ULL, 0xA88849262A8B89ADULL, 0x550BC2BAD419EB90ULL, 0xCB5634504FFB79B9ULL, 
            0xA3071DE3537D5A34ULL, 0x303D7C7971B8242DULL, 0x135BF525F4ADEE51ULL, 0x68346B641723D509ULL
        },
        {
            0x1B4D1009BA7F6B25ULL, 0xCA5434BCC5AD009EULL, 0xA8732CD782EDB3A0ULL, 0x7669EF78EC7022DDULL, 
            0xA1D31B726C70B232ULL, 0xD7671A634B7244BBULL, 0xDD52C128F5006DDFULL, 0xE83D87B2BB8F1557ULL, 
            0x77447121F5FEF543ULL, 0xF8EF8B3624ED4973ULL, 0x29C1A7D1C9838CD1ULL, 0xCF2AA6BB1DCEF4C8ULL, 
            0x7E9290A640D533B8ULL, 0xEAC53E6A7B7C3A39ULL, 0xCC785EB12FA8FD57ULL, 0xE4189BF1BDC5F7D4ULL, 
            0x5F8953AC8E94C076ULL, 0x2A9D95097DD3A05CULL, 0xE86FC6BC4BA323D1ULL, 0x6A707C464B887C4AULL, 
            0xC9A94F1797607D98ULL, 0xCDF7E2A13EE3DA7BULL, 0xBC492CD78188B1A2ULL, 0xDF2C06E7D4E331B8ULL, 
            0x887395E4B3AD6562ULL, 0x316D23EBCB75FD8CULL, 0xDB85CD7E10F07A0EULL, 0xC80700FB34F0DF1BULL, 
            0x472A027404A159BBULL, 0xDBF5BE61D50C4245ULL, 0xE387CF997BF749CFULL, 0x675525EB66C9B3EDULL
        },
        {
            0x3BBEFA1BD56E81A4ULL, 0x32B50A8299112CF1ULL, 0xBE7FBCE25C45B380ULL, 0x1A7ACE98873E19C8ULL, 
            0x931218B06B152EDFULL, 0x6F6E60353E1C7F03ULL, 0x42A94AA5FD9F5529ULL, 0x9152A0D94F30B2F5ULL, 
            0xE712E72EC6A7B2FEULL, 0xDFAEC0425EFE5D9FULL, 0x626A9363A660B438ULL, 0x565A8E7DA65BF79BULL, 
            0x26B50EB654385E59ULL, 0x36CC4D87D8D04C24ULL, 0x72907E3AE51BA78BULL, 0xBF54718DFFB8D0E2ULL, 
            0x9BC42B8964998872ULL, 0xFD0E3493BB8E574BULL, 0xC4F57B1E4D267E5BULL, 0x45A37DBAE60669AEULL, 
            0x6537412954AABFC8ULL, 0x546046440687FFB2ULL, 0xEA2A1C6F77CE1293ULL, 0xE1129CA202B02A28ULL, 
            0xEB830C3FAEEE8D6BULL, 0x17D6F031D647DAD8ULL, 0x1FAC55D6CF61E41DULL, 0xDC475DCBDB6EE32BULL, 
            0xD2C7607E69938955ULL, 0xBA8BFBFB7D7A5EDAULL, 0xFEFFD0FDAEB1DAD8ULL, 0x3B6CFCC319835546ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseGConstants = {
    0x652C35C52B55F43CULL,
    0x7D8E4CD9C931E3C1ULL,
    0x61F424271B524177ULL,
    0x652C35C52B55F43CULL,
    0x7D8E4CD9C931E3C1ULL,
    0x61F424271B524177ULL,
    0xA24C08FD54196D06ULL,
    0xE6E0C06A30918108ULL,
    0xFA,
    0x5D,
    0x4B,
    0x3F,
    0x4A,
    0xE5,
    0x02,
    0xF8
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseHSalts = {
    {
        {
            0x06B42D3284DEEEB0ULL, 0x13C7CCBF3EA67461ULL, 0x0F671E90DCD20259ULL, 0x2B9A159AAC19CAFEULL, 
            0xA62F2D313CE80CBBULL, 0xA39B8096DBA0A063ULL, 0x0B95334AEE774739ULL, 0xC412A6C77B3D5900ULL, 
            0xD827AFF4BFBC11E9ULL, 0xF134FC1CEA1E680AULL, 0x1DC1CCDBDE36E433ULL, 0x67B47B8458E66CD8ULL, 
            0xE5E331309E2C3E4AULL, 0x33EC16C715B56325ULL, 0x061FB41E088153C3ULL, 0x73E5D9AEEA59BC2AULL, 
            0x3CE904C89D5120ECULL, 0x532ADBCB87565C93ULL, 0x1C14D339C0C21EA9ULL, 0x0F9A0D7FD0443980ULL, 
            0x752DD62F6CAEDD1BULL, 0xB14F748A20D2B574ULL, 0xD2FF65F4F182A22BULL, 0x727409D9A9574597ULL, 
            0x02034DB1FAFF9034ULL, 0x908483C5762E1573ULL, 0x73C2C5A10269D712ULL, 0x164953975B5B6BDEULL, 
            0x1E0AF713C442C039ULL, 0x7F4966EB7F9EC3B7ULL, 0xAED7484C98E73DBAULL, 0x74C2B91C3DA8C404ULL
        },
        {
            0x571EEE1B0B83BE37ULL, 0xB717520CBFB0399DULL, 0x146908C145B9B428ULL, 0x400882BD22FD245DULL, 
            0x0ECB1A4DB069A0B9ULL, 0xAB40C46A64B06427ULL, 0x7ACAFCAFD1BF57EEULL, 0xE4476CCAFB0DDDDDULL, 
            0x160F725A8A4756D0ULL, 0xE70C5B03855756E8ULL, 0x3AE1B038884E2E8CULL, 0x9584CCEEFBFFB1F9ULL, 
            0x8821682C0D715ED4ULL, 0xE44CEFC413B09531ULL, 0x39AB4404D2A76630ULL, 0xD9EF847399A675E1ULL, 
            0x350406CE08D6273DULL, 0x9E4A9D3654A36A82ULL, 0x37D2E0F1E82622DDULL, 0x6B31EF8D1329644FULL, 
            0x21A9CF6792FCD7D7ULL, 0xA053F24C75C39961ULL, 0x10D810304D388876ULL, 0xC1CDFEBEA8542A42ULL, 
            0xD540080EC1E849C2ULL, 0xC1F3A8659F20EF37ULL, 0x0672708A149F02D0ULL, 0x8EEA92B8B478AC9FULL, 
            0x9CB3E5DF824BEFBCULL, 0xC3C170B4340E198EULL, 0x0303CC2CE7A2B53EULL, 0x7BB0F3E2ABDBFD30ULL
        },
        {
            0x3A882DEFEC809A8EULL, 0x59E320DD17847FB3ULL, 0xBF5F57586D493FEEULL, 0x84746A1C56376FEEULL, 
            0x363F8755DBF948B8ULL, 0x8AAF1A71E452684EULL, 0x25291D023A15294BULL, 0x3A5AA2C2EF37206BULL, 
            0x68B6A2C42D4172BCULL, 0xDE615EEE1A83CD3AULL, 0x4A5724469AB17574ULL, 0xBEB32CC58B7A5201ULL, 
            0xB345E69C18764D70ULL, 0x72C2C4DE94E4FE52ULL, 0xE93BE2BE63E37587ULL, 0xF99F2920147D1626ULL, 
            0x8E062D5F9A893355ULL, 0x27EC9CE4E5CFDAB4ULL, 0x8D26F25CF8F2031DULL, 0x78DE98DB92E6BF50ULL, 
            0x710C7843DF8A6363ULL, 0x8584A9E860709B22ULL, 0x488FF15F6A93A539ULL, 0x78BFD3FF17B06FC6ULL, 
            0xC25EDBE5853495E4ULL, 0x5C2AF4687A770151ULL, 0x2613365CF04E6740ULL, 0x3307236019A7B230ULL, 
            0x32423A931CE32F2EULL, 0xA01F52145B6FE1ABULL, 0x5F0EBAC44CC023FBULL, 0x10495D3DB4FF70A8ULL
        },
        {
            0x6A614D34DAE631D0ULL, 0xFEE2138898DE1F25ULL, 0x0ECC1E31BC7AEC05ULL, 0x547BB382E4B4C328ULL, 
            0xBDD761F133D16A47ULL, 0x88A86AE1C0B3AD52ULL, 0xBA9E3DEBCF922A18ULL, 0xB854C56C11D589AAULL, 
            0xB127B7B4D6EB4610ULL, 0x7B1AE34F70E042A9ULL, 0x3853A53FEE35E484ULL, 0x5E4DAFBD3E96450DULL, 
            0x144AD22B9EEE6427ULL, 0x42ED931446279909ULL, 0x0D2516630A787F4EULL, 0xFE5CBE84ADC01CE8ULL, 
            0xF647693941CA6D64ULL, 0x0CD07925C971F42AULL, 0xB821B381DC780876ULL, 0xE0CF42176EF230D1ULL, 
            0xEBBB8CA570978FA9ULL, 0x8A4E3626068D9310ULL, 0x7EDA8F95D80681CFULL, 0x7DE05CB8A0E1DC55ULL, 
            0xE19EBE50DCA98062ULL, 0x3FB74B17C9D31EB4ULL, 0xED32D7D9D6E2D77BULL, 0x781927A562DCE01AULL, 
            0x98A2D99430E8808EULL, 0x9F831ECCDBA7565EULL, 0xFB78BA92ECD1175EULL, 0xF5A68F9778525204ULL
        },
        {
            0xF5DBEBAFE9FB6541ULL, 0x4865E3910ED48FA1ULL, 0x09EB0BF6991D209BULL, 0x803657386F4C698BULL, 
            0x5F4FF6B4474D379DULL, 0x402D796CB3F9CE92ULL, 0x2980C9496809DEC4ULL, 0x3B84DB4E07E7E797ULL, 
            0xF64D5CB48CCE00F0ULL, 0xD0B1CB488B981B92ULL, 0x7027C5D1C8A15CFDULL, 0x6263956F19B4B3BEULL, 
            0x3FA710ADE5EBC0A4ULL, 0x002CE9AE55237C53ULL, 0x8287BA6457A50023ULL, 0x877D149ACFC01B72ULL, 
            0x63FE4F1C8DD3D09EULL, 0x970473E827833C7CULL, 0xE3E904AB37F79400ULL, 0x7A2FE3B9BECCA045ULL, 
            0xD1AA64CD7FED23A0ULL, 0x3B619EEE590D5723ULL, 0x1B809038672A437CULL, 0xEC335D0B0E40B338ULL, 
            0x94E07350B0F69DEDULL, 0x7350BA77F7FFCF20ULL, 0xB32911B07898B1BCULL, 0xA20520B89482065EULL, 
            0x12A6FBEFFC0E8B61ULL, 0xF36D2D5A4D7921EFULL, 0x7823142E0F31258EULL, 0xFBFD84CA3A8EDB9EULL
        },
        {
            0x496BD3095DFE0B9FULL, 0xB8F65339AD0CCA33ULL, 0x0BB9AE46CACB03E1ULL, 0x8E7D4599EDDE198DULL, 
            0x5F1A773B1024A900ULL, 0x7B3F6C1952DFACAAULL, 0x92606A93856F73E7ULL, 0xD45C61F5A6186EFBULL, 
            0xA2A9513770B5DFBDULL, 0x4F05594C28141FB4ULL, 0x900C85AF53A07060ULL, 0x846F06200D74E467ULL, 
            0x39FD186A285BB249ULL, 0x54DC84317A3120B2ULL, 0xE4309A6019AA5983ULL, 0xC5881398C7B78CC8ULL, 
            0x0BA42ED699CF5E1AULL, 0x753A39D0EC1BFF99ULL, 0x718D9AF367018FAAULL, 0xACC586902C6F5A36ULL, 
            0x9059D3B2F592D640ULL, 0x1886FB2895924315ULL, 0x61D64C0237554B64ULL, 0xEB4608F0FC5E8E52ULL, 
            0x779AF495099D42DDULL, 0xC3C33FE6C5BD501FULL, 0x29F8DFF7889E3480ULL, 0x4D408AEF81E54BDEULL, 
            0x32DA453C863F1AD1ULL, 0xF8F2C1889B53A1F7ULL, 0xA6ABD1C3086BB5B5ULL, 0x44EB8CF8750F6C69ULL
        }
    },
    {
        {
            0xFA7DA33761D66F6FULL, 0x3C9FC893A4FC19CEULL, 0x0222734D3CEFC183ULL, 0x59050747988AAC54ULL, 
            0x19386FDB4B7019C4ULL, 0x2338BE59F021C195ULL, 0xAF6166D1C74639F5ULL, 0x2BB230D9B436A04DULL, 
            0xB67BE45427644DE4ULL, 0x58CC8E8789EC346CULL, 0x19BE1BA0C4330842ULL, 0x02D6A6BEE4A9EADCULL, 
            0x856AB1718D9BDA60ULL, 0x32FC9DB70F593DC6ULL, 0xF2523FEBECD8CD2FULL, 0x7B372C04D6F8FFB2ULL, 
            0xE90AC66CD8E7546CULL, 0x078D911227B66EA5ULL, 0x639ED3BC22FD7FD2ULL, 0xAE7BBA891B050273ULL, 
            0x2EE7ABF8CEA3B74AULL, 0x303A98DCDE4E6770ULL, 0xFD02D78D69515B07ULL, 0xCEFEC6168C70C947ULL, 
            0xB846EA2B2BA3AF8EULL, 0x4FE787FDA5539453ULL, 0x259404DA3441F23BULL, 0xFE2BD3EE69B47D67ULL, 
            0x56847619FE7D43ABULL, 0x52206036B82D0BFDULL, 0x987681AD8433A389ULL, 0xD47682B1D71DCBFEULL
        },
        {
            0x9721A15C619F9D65ULL, 0x10BB67B72718587DULL, 0x545F809C4432EE73ULL, 0x41760022BE0CFE8FULL, 
            0x002650945C2F4624ULL, 0x59C711915B76F739ULL, 0x8C4167482C2A14B6ULL, 0xF69CC891F05E2668ULL, 
            0x3F36F87E3C34508AULL, 0x9479741C9B5ADE9BULL, 0x6338B89D5A83ADF4ULL, 0xA84614376CAEEB5CULL, 
            0xB57B506B7657BA3AULL, 0x0F76D178C13E60ACULL, 0xD55D166E0BB608F0ULL, 0x8A6410C91ABC4859ULL, 
            0x57D6DC8BF45D626CULL, 0x923AE8950E5EA5F0ULL, 0xD78470BFEB9100F3ULL, 0x065C863EB31F7E56ULL, 
            0x2B106EFFD798BECFULL, 0x9394852318866952ULL, 0x3BBC160D3CCE2A18ULL, 0x066D70AA2F7E8E68ULL, 
            0x34C7BA350B3CF16EULL, 0xC36C3F089B2237EAULL, 0x07D22620B17DD229ULL, 0xF36E84F3A6A4CEA6ULL, 
            0xEDDD2153676CD623ULL, 0x8FB440DD8E68C6DAULL, 0x10FDDD85A91D23A4ULL, 0xD72521E070071090ULL
        },
        {
            0xB0256D5166B8EF2AULL, 0xFBE8735E6233344AULL, 0x04ABF632336D2A1BULL, 0xCB0DCF32FE55563CULL, 
            0xB202ED3774F5DBE6ULL, 0x2FA37B00363D6317ULL, 0x5228A8435892EAF4ULL, 0x1A366557528AC699ULL, 
            0xF7442E2F87C3329EULL, 0xC8B09FFDCD02F19FULL, 0x6C73F601D319D61FULL, 0x3ADB09C337436E1EULL, 
            0x144AB22AB9C6F659ULL, 0xFE4B6684020F3363ULL, 0x10A093C9E1C67D4EULL, 0x5721B07A1C597AFDULL, 
            0x0B8BEC0EAE8EA024ULL, 0xF919C384C45C9959ULL, 0x60DEDA0736FF601BULL, 0x3E06DA8333EAB192ULL, 
            0xDA18825C236B3780ULL, 0xCB78328B89277A80ULL, 0xA4B739E45432DF2DULL, 0x566399F69C224B8AULL, 
            0xF0CEFA5DC9721A2BULL, 0x11419DACBE5644ADULL, 0x15E5726F31A405E6ULL, 0x243A9DA452C3D541ULL, 
            0x0534EC0BC1175258ULL, 0x728B2A1D6F0FF276ULL, 0x0F02C1D876370CEAULL, 0x41EA47D67CF740D0ULL
        },
        {
            0x3CD74CD0390C2FECULL, 0x05874322A61F3C44ULL, 0xA8B79ACF8C32D1ECULL, 0xD976B05C087C1817ULL, 
            0x4BED441720DDC2B0ULL, 0xADF81560E6027E00ULL, 0xABB1F1EFF961AEE3ULL, 0xBE015A7500A126E8ULL, 
            0x739D73030C6889DDULL, 0xD76D260D4C4C58DBULL, 0x4C7940B13B8CE511ULL, 0xEE9BD202734C241DULL, 
            0x556DCEE9DC334EC3ULL, 0x7C581DC21331673BULL, 0x38FB3CF57873949FULL, 0x652775558E0FEA4AULL, 
            0x003D2F4E2F12B41AULL, 0x000AFE4C10697CF8ULL, 0xD6200516A13BB13FULL, 0xCA4C2C9545F6D8C1ULL, 
            0x480687F99A7DE3E0ULL, 0x007C979AB4118FF7ULL, 0x9F8496A3321E6A4AULL, 0xAFB423F54B78926BULL, 
            0xE0D02FBAA6F453E4ULL, 0xEC47E89EBF3B523FULL, 0x6BB87044C694137DULL, 0x98F9C23244A7D8C0ULL, 
            0x8A28D374FCD870F6ULL, 0x1001F6B231F900BEULL, 0x905810DA967B24FDULL, 0xA818A7F78E058E80ULL
        },
        {
            0xC33094E937A06D8BULL, 0x3DFA48B8CA44B49BULL, 0xAC84674642AEE2A6ULL, 0x12B59AB76834E05EULL, 
            0x18DB5607A4D342E7ULL, 0x0BD58201DB03F48DULL, 0xF6C6A0A92755D34BULL, 0x9FD60A043EE8B58AULL, 
            0x0764A21E4B9F00AAULL, 0x289AB8DE03C30D78ULL, 0xE9991CF0E3001104ULL, 0x6DEA91E752A87414ULL, 
            0x8FF6A6C84EAE6B20ULL, 0xC6890691B6A27BF9ULL, 0x0C0A9A37EB560C16ULL, 0x12A258AF6D3DCA75ULL, 
            0x1FB9D5E6C7E097BBULL, 0x4B427C8EF4EE6119ULL, 0x69282BE6E7CE53BEULL, 0xC9AED47A3F3D5371ULL, 
            0xEF274F76A1D32644ULL, 0xF4F878F2893CC62EULL, 0xBA5FE45F00697412ULL, 0xAE1569CD4702D15EULL, 
            0xAF753352FD6176D6ULL, 0xB183935429354230ULL, 0x6253C7055DCD372DULL, 0x5A1AFCF4FE253575ULL, 
            0x900495BD7C48F6B4ULL, 0xD0CD5762B6A7F73AULL, 0xAE55064A5407C2E2ULL, 0x8B42F9502D2129F2ULL
        },
        {
            0x8967C2DA68070E5EULL, 0xAFE4619BC60DD374ULL, 0x3D12F019CEC43095ULL, 0x1036AC80C0C3E1FAULL, 
            0x5C9D5E8EC9C459D6ULL, 0xB943408FE777FA68ULL, 0x60F1568763699224ULL, 0xA04D4C059106A503ULL, 
            0x3F48583017DDA29FULL, 0x009518CC085F8F67ULL, 0x74A2AF8DD65A8E2AULL, 0x3CE2188C17B21175ULL, 
            0x85798EF3BB666BA3ULL, 0xB4FDA3BD8AA14BBDULL, 0xB6152C0E75C400FAULL, 0x709659B2E3976200ULL, 
            0x2AFF7114A8B1AD70ULL, 0x43DD1F8358CAE62CULL, 0xB26BE249010169FAULL, 0x44E5CF6A26DF79E3ULL, 
            0x25A34E4FE8AF5E38ULL, 0x8AB1A51B8F005F51ULL, 0x6426EE365B6BA74FULL, 0x7E9AE888C7E5E975ULL, 
            0xD0D98CFC9B571CF9ULL, 0x2A705C080389F551ULL, 0xC5EE4B91EA9DB4A4ULL, 0x7A8604B75CD41017ULL, 
            0xF04703A0AAA5C2CAULL, 0x9EF7AC2F348C0B15ULL, 0x5E07841C70987855ULL, 0xAAAC8CD34C5B9500ULL
        }
    },
    {
        {
            0xBD5785E216FBAD4FULL, 0xEA7EC926F15D143FULL, 0xAD10A3C88B936336ULL, 0x1B891F29A4C46968ULL, 
            0x80933FFCD31F0343ULL, 0x01E825229DD7374FULL, 0x721EC8F3FC13FADCULL, 0xBB60F2BC8D04EEEDULL, 
            0x24AE0A301BEF193AULL, 0x09E2F9775B97A611ULL, 0xA771AE8806976D43ULL, 0x796A3593B80D7EF2ULL, 
            0x4D1A1228084701ACULL, 0xE2F61B28B2D054AFULL, 0x610DED6ED1CD7589ULL, 0xD7E03E9508B37F37ULL, 
            0xD2D68C34C00BEDAFULL, 0x2E87A60CB8678221ULL, 0x9C8E597244E02CD2ULL, 0xFF63891F7FBE6646ULL, 
            0x87906B88F00D8F12ULL, 0x86BA2DBF18EE2660ULL, 0xBE92A6411B70C5AEULL, 0xCD47E1427B43A020ULL, 
            0xD4AD6F1D493ADD43ULL, 0x2679DD84CFC0C35DULL, 0x099E6FFF9B890098ULL, 0x2A19E1B3AD668B8BULL, 
            0x1008A4D008CAEC3FULL, 0x3AE01A292E76738BULL, 0x45BE9641F1E4176AULL, 0x2375E4133BC3AF24ULL
        },
        {
            0x1DDCBF5E80071654ULL, 0xA2495EE29237F03AULL, 0xCF61CEFF9D3EDEA1ULL, 0x346BE5383AD2C44CULL, 
            0xBA4A4A230C2E2139ULL, 0x19E9C8ADBC621431ULL, 0x7759FA3452DA65B6ULL, 0xA4B0559929B08BD7ULL, 
            0xAE65C4BD3517B22DULL, 0x2B08C99F31DC18C8ULL, 0xA0C42B57770E45A1ULL, 0x8B2347446796FB14ULL, 
            0xE787066B5C789C62ULL, 0xC14F81DC8B7BE910ULL, 0x88522E5BF2712570ULL, 0x6C3238AA3C73C25BULL, 
            0xC32396723B552D1FULL, 0xFA1410388C90D79EULL, 0x516AB9866970EDC7ULL, 0x442BEDC40FC747C2ULL, 
            0x9D00C9E2DB5AF943ULL, 0x3F7251793CFDDD10ULL, 0x06B3D79F5A6FAFB9ULL, 0xFDFFEC4D1FB0D3CBULL, 
            0xB47604412B405614ULL, 0x9B2FC4AADD4B420EULL, 0x5922DF1B69D32D5DULL, 0xD6102E1E831CAB74ULL, 
            0x1C9A23B51457D921ULL, 0x21F2D7DBFDE7EAB1ULL, 0x47E8D8AA89F52E91ULL, 0xB913E4E769FA19F8ULL
        },
        {
            0x4440053E85E84E22ULL, 0x1CBFCBF5B0659876ULL, 0x69F97EE261385CCEULL, 0xF59768B649A7EAF3ULL, 
            0x39847511EAA340A0ULL, 0x5DC058E54CC8090EULL, 0x78DE716A5898AA86ULL, 0x0B165E8FC7190F26ULL, 
            0x470A9BAEB406A49AULL, 0xA14B2AD2C71450FAULL, 0x8320CD1FB753D042ULL, 0xD007654E2DC926EAULL, 
            0xFE5B1D39A047E4D0ULL, 0xF53C1BC42976B909ULL, 0xE559FA02E2C6A1E0ULL, 0xC7D1312558E24E4CULL, 
            0x0DC81D5EA00E140EULL, 0x91E2A30685E43A39ULL, 0x636473030900D65EULL, 0x063F512B9073756BULL, 
            0xED79C5946FB586A7ULL, 0x486ACC39C0258ACBULL, 0x3294B03C086190CFULL, 0x65AF4CC4F93C6903ULL, 
            0x6B4E8CF65DED5F25ULL, 0xA95A62B1C64174EAULL, 0xA8D831D327AF2D08ULL, 0xA1AA5F77FDFEC654ULL, 
            0xCA2885DB52684388ULL, 0x668C3142876D4220ULL, 0x8630950FB34E24AEULL, 0xA081FA59306715C4ULL
        },
        {
            0xD5435F4AC5B5C845ULL, 0x72C9B71A3760A1F5ULL, 0x5D734083FA3815F9ULL, 0xB4E01EB308CDD8F7ULL, 
            0xBFD1CD8D1DE23499ULL, 0xC1B9DFC9C58CA289ULL, 0x3825AB75A1451144ULL, 0x745787119533B827ULL, 
            0x913DF57DFEA58D18ULL, 0x718665558CE85097ULL, 0x306931635169B460ULL, 0x1C6C2DCCEBD60FD4ULL, 
            0x3D520641C01A93E8ULL, 0x4BFB2849F2F10DB3ULL, 0x98F8BBDAF9D3C2FEULL, 0x6860C28CE3BFA524ULL, 
            0x8F6A941046638CB1ULL, 0x85B9775AA78B9D1FULL, 0x4792AA5AAC811BC5ULL, 0x8B17ECA4200A18D2ULL, 
            0x3934CED098BC0535ULL, 0xE7D122990147ED60ULL, 0x500278499C4BCFDFULL, 0x811F01A660A8F6A1ULL, 
            0xB9A4D83C61DA0C10ULL, 0xB7F1FFB48F8863C8ULL, 0x3C593392D01C9613ULL, 0x61C31C639DAF7AA3ULL, 
            0x306A454468A7AE94ULL, 0x4645429976851EAFULL, 0xAB382FB89AB99B35ULL, 0x1D9ED2BFC2E3DB24ULL
        },
        {
            0x027D90988D594E32ULL, 0x00383DFB25E16FB1ULL, 0x70EF8B98E466BA04ULL, 0xEFB7BF177D9A0E1CULL, 
            0x04756FE518D3622BULL, 0xF077CFD009A3CD7CULL, 0x18114FCCE812E521ULL, 0x77F9E29FB12CEDB6ULL, 
            0x682DF00ED752C905ULL, 0xD988A3C0694D4A16ULL, 0xB810B52A9F7F60D9ULL, 0xD556183353F8D0ACULL, 
            0xA56DB864C2CAA14FULL, 0xAABBD85C711F72C8ULL, 0x2AA4CB70A53C15BFULL, 0x0B580789EDD39BA4ULL, 
            0x2C4221A1CDB5F915ULL, 0x5FC4CB6799D9ACEBULL, 0xD51F3300AA8146A2ULL, 0x29A14E5B46327FA4ULL, 
            0x63CA949C9267E53FULL, 0xA6B3D479EC78DA33ULL, 0xDFAD8FBBA66EDEF6ULL, 0x80F3ECD0962A8974ULL, 
            0x2D2825451B9AE6CDULL, 0x223CFFABEECAC2C0ULL, 0x4F5549D75148DB64ULL, 0xEAB8FF8E58207E2AULL, 
            0x42EF2CE1CAD8F9A6ULL, 0x66503DE14A10D2EEULL, 0xC84D3CC4233F1FF3ULL, 0x8D43DE8602B05661ULL
        },
        {
            0x006AF4BA43697C70ULL, 0x928C0AD40EB15DD0ULL, 0x010CD910F7E6D6C3ULL, 0xB9FA6CC14BEBE82AULL, 
            0xD0DFA04292E3BE09ULL, 0x88BE642E436D759AULL, 0x698563DE89DF1E9FULL, 0x179BD3BA1271D0D7ULL, 
            0x710D5B4067EA26DDULL, 0xFE469EB8CF19B5A6ULL, 0xA9BB39877E16AF91ULL, 0x542EAE1D15F45557ULL, 
            0xC96BB1E296062E85ULL, 0x0CD87209F25A40B6ULL, 0x9A7E5CC36B1EC32DULL, 0x0563E1D122BC95F9ULL, 
            0x0AE316F465C15B26ULL, 0x1AC5EF35D9238775ULL, 0xAA4D5B00D01A56AFULL, 0x33181E5D868608D3ULL, 
            0x854C6A8D0E39FF34ULL, 0xF9B4B4587F699DF9ULL, 0xF3D2B6FC9AF25F84ULL, 0xF018612C09150412ULL, 
            0xC3EE0E27361EEC28ULL, 0xC44C4B1BD84BCC8DULL, 0x7578DB71A681193CULL, 0xD7685F379E338FACULL, 
            0xF8B6E75D4AB557E4ULL, 0xD5FCF8413CCBA670ULL, 0x8375508BE4244792ULL, 0x650DAF00A387BCCAULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseHConstants = {
    0x32C897FBDB17E297ULL,
    0xF4887DB8F2950204ULL,
    0x5BB085BD7708EC8CULL,
    0x32C897FBDB17E297ULL,
    0xF4887DB8F2950204ULL,
    0x5BB085BD7708EC8CULL,
    0xADEE5243946D2412ULL,
    0xC11BA3D9DDBB3B95ULL,
    0xED,
    0x91,
    0xB2,
    0x0F,
    0x91,
    0x5D,
    0x43,
    0x7E
};

