#include "TwistExpander_Bowling.hpp"
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

TwistExpander_Bowling::TwistExpander_Bowling()
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

void TwistExpander_Bowling::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x916D619684CB9683ULL; std::uint64_t aIngress = 0xF528C556EE34A0F0ULL; std::uint64_t aCarry = 0xB7AFF10F74886BABULL;

    std::uint64_t aWandererA = 0x8B2617DCED41D4CCULL; std::uint64_t aWandererB = 0xED8A1FDCCD2E61D5ULL; std::uint64_t aWandererC = 0x8DEA359DD8C5BD10ULL; std::uint64_t aWandererD = 0x9E3B7E5D5B668E3CULL;
    std::uint64_t aWandererE = 0xCA7065B49DB68FE4ULL; std::uint64_t aWandererF = 0xF888B999C2BB5086ULL; std::uint64_t aWandererG = 0xA10DE42ADCA7CB29ULL; std::uint64_t aWandererH = 0xFE5CF4E32436A7C6ULL;
    std::uint64_t aWandererI = 0xB8FA5F3668849016ULL; std::uint64_t aWandererJ = 0xE83CEBA4447021A7ULL; std::uint64_t aWandererK = 0xC1AB0554B1CFB87EULL;

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
        aPrevious = 15933852325889043300U;
        aCarry = 13249458694706681094U;
        aWandererA = 12363213494434871847U;
        aWandererB = 9331759562001873616U;
        aWandererC = 11958223113074267195U;
        aWandererD = 12820705926479535744U;
        aWandererE = 16503810170121299319U;
        aWandererF = 10594659053162115871U;
        aWandererG = 10876585007212157243U;
        aWandererH = 15312222530123157116U;
        aWandererI = 12378396719607421618U;
        aWandererJ = 9568732046170435293U;
        aWandererK = 10539386988540526300U;
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
    TwistExpander_Bowling_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Bowling::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEBD781DF5788BAFCULL; std::uint64_t aIngress = 0xA8AA844095439A83ULL; std::uint64_t aCarry = 0xF0A039E545CA78DEULL;

    std::uint64_t aWandererA = 0xFAEBF38CF4BBE24EULL; std::uint64_t aWandererB = 0xB7BB2D846E11AC70ULL; std::uint64_t aWandererC = 0xEDBE383D1DE8BC41ULL; std::uint64_t aWandererD = 0xC8FC3F6DB2F27D7EULL;
    std::uint64_t aWandererE = 0xBB9EDAE31D3E9ECEULL; std::uint64_t aWandererF = 0xA917CD88D3655B7DULL; std::uint64_t aWandererG = 0xA878722D7CBD29F6ULL; std::uint64_t aWandererH = 0xF5F35A84F2AA37A5ULL;
    std::uint64_t aWandererI = 0xC565DA9C8D61FA00ULL; std::uint64_t aWandererJ = 0xE0B8834ADB2E3719ULL; std::uint64_t aWandererK = 0xF59B1DA1882DCD36ULL;

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
        aPrevious = 9391345329728963243U;
        aCarry = 9621815735412724024U;
        aWandererA = 9261971351788659764U;
        aWandererB = 15986044399808548527U;
        aWandererC = 18286580707143986344U;
        aWandererD = 18258973569508595802U;
        aWandererE = 9365686565981687361U;
        aWandererF = 13165320927475595553U;
        aWandererG = 14778256123343202955U;
        aWandererH = 15193201466113618476U;
        aWandererI = 16197972750885076155U;
        aWandererJ = 16659328639540674772U;
        aWandererK = 14497319045403524830U;
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
    TwistExpander_Bowling_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Bowling::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCDF59BB134568D3CULL;
    std::uint64_t aIngress = 0xF2AF85344A242F1CULL;
    std::uint64_t aCarry = 0xC31DD17CA8D33017ULL;

    std::uint64_t aWandererA = 0x8B9EC92766B7062EULL;
    std::uint64_t aWandererB = 0x99C711641700FF14ULL;
    std::uint64_t aWandererC = 0xA10AB6CA64D67D11ULL;
    std::uint64_t aWandererD = 0x91B22531AB708F9EULL;
    std::uint64_t aWandererE = 0xC7D3C79921A4E5CBULL;
    std::uint64_t aWandererF = 0xDB46821AEA020D54ULL;
    std::uint64_t aWandererG = 0xD7AB96A630E4FB01ULL;
    std::uint64_t aWandererH = 0x88A39766483D3937ULL;
    std::uint64_t aWandererI = 0xBB17BEFF1AA43889ULL;
    std::uint64_t aWandererJ = 0x999F4B9B4C3FF491ULL;
    std::uint64_t aWandererK = 0xC23881485D6D06E6ULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_Bowling_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Bowling_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Bowling::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Bowling::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA311166F00EAB38AULL; std::uint64_t aIngress = 0xF6F2FD1643BAE1F9ULL; std::uint64_t aCarry = 0xF06C2A3408B655A4ULL;

    std::uint64_t aWandererA = 0x86E0D05EC00A548FULL; std::uint64_t aWandererB = 0xFB18033EAAA828FAULL; std::uint64_t aWandererC = 0xB0AB796D2C0B0173ULL; std::uint64_t aWandererD = 0xDED339BD0F98B47AULL;
    std::uint64_t aWandererE = 0x823D904D8354541AULL; std::uint64_t aWandererF = 0xC63E055400853D5CULL; std::uint64_t aWandererG = 0xF56BDF00C5026F73ULL; std::uint64_t aWandererH = 0x803BDF89D71FC213ULL;
    std::uint64_t aWandererI = 0xBE35FC16F84A27B0ULL; std::uint64_t aWandererJ = 0xE990C353E5197816ULL; std::uint64_t aWandererK = 0xC0B6D3FF56F3A256ULL;

    // [seed]
    {
        aPrevious = 18247927722436240445U;
        aCarry = 11296251423123672937U;
        aWandererA = 14024064633371606840U;
        aWandererB = 16947925342547642723U;
        aWandererC = 10367531097047808639U;
        aWandererD = 16392573864026845940U;
        aWandererE = 14337737944681534218U;
        aWandererF = 11552238647215426219U;
        aWandererG = 12556613718476002016U;
        aWandererH = 11070702082057706987U;
        aWandererI = 12597544626837128628U;
        aWandererJ = 13016848853488413646U;
        aWandererK = 11358753954279195543U;
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
    TwistExpander_Bowling_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Bowling_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Bowling_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Bowling_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Bowling::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 0 with offsets 5263U, 5739U, 2220U, 2911U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5263U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5739U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2220U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2911U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 1743U, 2627U, 3458U, 66U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1743U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2627U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3458U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 66U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 2 with offsets 6414U, 2913U, 5911U, 3178U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6414U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2913U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5911U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3178U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 0, 3 with offsets 1441U, 3521U, 3436U, 4174U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1441U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3521U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3436U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4174U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 96U, 52U, 304U, 903U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 96U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 52U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 304U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 903U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 1, 2 with offsets 1138U, 25U, 1168U, 588U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1138U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1168U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 1, 0 with offsets 218U, 2U, 926U, 1987U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1987U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 0, 3 with offsets 1175U, 510U, 75U, 1329U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1175U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 75U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1329U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 29U, 1304U, 445U, 965U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 29U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1304U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 445U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 965U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Bowling::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 3, 0 with offsets 2186U, 4788U, 4965U, 5964U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2186U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4788U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4965U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5964U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 1 with offsets 4135U, 5494U, 6125U, 8119U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4135U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5494U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6125U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8119U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 0, 3 with offsets 7947U, 6952U, 5585U, 1709U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7947U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6952U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5585U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1709U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 2 with offsets 3504U, 1954U, 8046U, 2389U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3504U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1954U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8046U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2389U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2538U, 3287U, 6899U, 2621U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2538U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3287U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6899U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2621U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 387U, 502U, 1971U, 94U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 387U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 502U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1971U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 94U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 297U, 95U, 1412U, 66U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 297U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 95U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1412U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 66U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 456U, 1170U, 188U, 1539U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 456U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1170U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 188U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1539U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1528U, 238U, 778U, 1154U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1528U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 238U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 778U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1154U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 [0..<W_KEY]
        // offsets: 854U, 94U, 198U, 732U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 854U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 94U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 198U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 732U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseASalts = {
    {
        {
            0xAF5D0AADFD2139E4ULL, 0x479BA92E57BBF3CDULL, 0x80B7CE6614AB63BBULL, 0x6373FAB67B86E0ACULL, 
            0x13B663509213FD4BULL, 0x1DF098329D3FB56FULL, 0x49F04E1A9AF345FDULL, 0xA9B20CEA587CDE17ULL, 
            0x4EDF50D17C3227C0ULL, 0xB975589F08D53196ULL, 0x2370C9A0CC66D758ULL, 0x9482D31AD587661EULL, 
            0x7C762164BEFF9D6BULL, 0x558F2719F1A8B496ULL, 0x35B1C1DA88227F18ULL, 0x9A932401C86C0417ULL, 
            0x94D8925960301DC2ULL, 0x5A128EF3014D6C43ULL, 0x7C7DF2AC1004AB08ULL, 0x517CBE9E5BB0A9CAULL, 
            0x0892CBD2AF6D3DD7ULL, 0x94E4908525B6BC6BULL, 0x07564863DA9B1C7BULL, 0x9C28D47971C73532ULL, 
            0x1ABB20CC5D4A6FA1ULL, 0xAE058B589E0658F5ULL, 0x7416465779410E9AULL, 0x561A9F677028993EULL, 
            0xA0F54AF25A362824ULL, 0x050B6CB2952D4979ULL, 0xD7EF39D25FCC67ADULL, 0xBBAA0335604AD9EBULL
        },
        {
            0xD958FA576B392F92ULL, 0xCAB4C384FBA0DF6EULL, 0x0D93B86C7A0D0286ULL, 0xF3132D778120788AULL, 
            0x33E46B73E799DB2EULL, 0x3CEBDC14BFFDB323ULL, 0x29818E4739B9EA75ULL, 0x4B8B3F53DBDCAD01ULL, 
            0xA4BECF814848A225ULL, 0x9796A4457541C993ULL, 0x033AF795ADB6A33BULL, 0x63F05E80FC2DAA86ULL, 
            0x5B3204AB93A24478ULL, 0x4038AD19707515E1ULL, 0x080B15D834179D8CULL, 0x466FEC325196D970ULL, 
            0x41E9CBAF44AF4EBDULL, 0xD432F6206397971DULL, 0xD2509D7E1C921DD5ULL, 0xB4672EE26416F6D7ULL, 
            0xEEFEE843A5C09EA7ULL, 0x02BC03302F754800ULL, 0x6748AD734E716798ULL, 0x68FAA243EE23C9C8ULL, 
            0xAF1D619F771CC10EULL, 0x88A63FA74253D482ULL, 0x125287EEFD142324ULL, 0x1752EB9C97DD61CDULL, 
            0xBDA07C52CFD5B07FULL, 0x2EE20C16E52155F9ULL, 0x1F0BC45927A43FB1ULL, 0x58A65A6CE92CA308ULL
        },
        {
            0x69C3D71CF0E6DEB9ULL, 0xF49E1B78F8C68BC8ULL, 0xFCCA06DB2F2E8AD2ULL, 0x7127BCB4E1202833ULL, 
            0x2A2CB8A36688C1BDULL, 0x08C362C2FA3675A4ULL, 0xE89DECB019BC363AULL, 0xA9B6A98D1C34E0A5ULL, 
            0x389E6A325F2DE5E4ULL, 0x93CA736EFF07F903ULL, 0x2BE7E9A885C21378ULL, 0x92476C2387B70464ULL, 
            0x7D93388424460479ULL, 0x22E483181A7C20F0ULL, 0xA1D79BC377997106ULL, 0xE1CDC0F4239AD006ULL, 
            0x71623AF282BC364FULL, 0x1236617D437101D2ULL, 0xE5488F17D7BAFD57ULL, 0xC586CF448487E94FULL, 
            0x2373724928BA4459ULL, 0x69CB086327F45B89ULL, 0x7421221F23301927ULL, 0x17872B8F67F71E8CULL, 
            0x766CFE7EA867674EULL, 0xBE120E9C6C9B2835ULL, 0xDB2B64D07F796698ULL, 0xB1C3645D2837FD50ULL, 
            0xCC3E692D27767B8EULL, 0xAE0096D43DEB97F2ULL, 0xFE0C542828B3A9ABULL, 0x9D5105545124B9ACULL
        },
        {
            0x116C90EF20C8211FULL, 0x35B5F2BFF108BE18ULL, 0xE4B5F3773DF20941ULL, 0x1B2D3DD8CA8848DDULL, 
            0xAD37D5F3B7F32D75ULL, 0x0291E41A70407643ULL, 0xC943DB50BF37F269ULL, 0x801674B65110D8EEULL, 
            0xB7D0E747D51449A6ULL, 0xBDA7E1D14E2C1D74ULL, 0x8FB027AA0B4DDF33ULL, 0xA7582A418C3D9A3AULL, 
            0x46A05E8B651D238EULL, 0x4EF367CE3096A015ULL, 0x2BD05C0223D5FC1DULL, 0xD13E4A15A9AE6BB5ULL, 
            0x6B920400BAE62FD2ULL, 0x6E5550184775F52EULL, 0x2853F0A56303FB16ULL, 0x3004BFD68ACBDA7FULL, 
            0xD401E6D90F97E461ULL, 0xBB097D18989543B5ULL, 0x556816FD63C3FF66ULL, 0xD78E4B6210EF673DULL, 
            0x8920EA3111FFEB84ULL, 0xFA983220096CBFA7ULL, 0xAFA99135F7388E28ULL, 0xBAB61C43AD1BD700ULL, 
            0xF55DEA9D6B049470ULL, 0xF80AB91C56CC89DBULL, 0xDCEB7892948E3E41ULL, 0xE8C56AE38878B37BULL
        },
        {
            0xBDA2F96699A55FB1ULL, 0xADBEB76C8FB6E855ULL, 0x14D71955250C46FBULL, 0x225EF68DC3F1E595ULL, 
            0xEB62FFBE8C847C94ULL, 0x1871760A3D7D2955ULL, 0x857858AB49C133B7ULL, 0xB994619F898FF2E2ULL, 
            0x0FFE287973D9B09AULL, 0x3500564F717EADB5ULL, 0x85F7BFF5997EE9A8ULL, 0x16C1182029FA305DULL, 
            0xA6829A490372D404ULL, 0x06DED650DC6BB35AULL, 0xAE86A17E3E9A3197ULL, 0xC28930BE5B947AE8ULL, 
            0x402C0A63E389832FULL, 0x91AA43EF4425CBF1ULL, 0x248D05B1E710DEE1ULL, 0x42C321FA0B4A37F4ULL, 
            0xD93EB51B18021173ULL, 0x0A4B070001099582ULL, 0x60443032E21E927CULL, 0xF6352EAA8EAA59BBULL, 
            0x657AD0239BB6E53FULL, 0xFA6FF1E39A561A74ULL, 0xD9E3AA0F403FEEE0ULL, 0x737765212FC45626ULL, 
            0x79CA8DA86BB71720ULL, 0x88F060B577246DB4ULL, 0xB69357961BFC7F5DULL, 0xFB0C5835F29230BBULL
        },
        {
            0xD7991BDDCBFD6221ULL, 0xEE56C111EDB67F62ULL, 0x6DA4F81809BA246EULL, 0x8E582DA913AE5BB9ULL, 
            0x84FAA7A2A53C8E97ULL, 0xB31275771E321A7DULL, 0x8A964DA8D63E42DDULL, 0x8FEC02BC6E7CEF49ULL, 
            0xBDF81EB66D8CD04DULL, 0x23269128A4F29715ULL, 0x5A48002396A01F5DULL, 0x73DCDDEF81E1B3BAULL, 
            0xD458CF342C34A8D6ULL, 0x18FC3A50A92CED13ULL, 0x979E3EBC2E1466DDULL, 0x075100960F6BBFCEULL, 
            0xEA8053E73B41CFE8ULL, 0x54E36C5014D26BCAULL, 0xF8EF407050C12885ULL, 0x45223D973AD9271CULL, 
            0xD729DEDC28E6C810ULL, 0x7713B4320533CF3CULL, 0x3DF03330DCE3B10CULL, 0xAB46A1092056618CULL, 
            0x102E9D0FEC66BE1BULL, 0x44025E0C808EA13AULL, 0x0E46077AF3184290ULL, 0x6E843012D64BDD93ULL, 
            0x1B84C9A445CD07DEULL, 0xCCA299DC1843C33FULL, 0x9974F73A66F56E5BULL, 0x09707B0E71E48A3CULL
        }
    },
    {
        {
            0x8AD0887DD6EBEDE7ULL, 0x542C83D551029A1DULL, 0x74805D39338B74EEULL, 0x072038600BAE1FB6ULL, 
            0xD9E72630B6A470ADULL, 0x06F7B52E13951C49ULL, 0x656CA9C679570DF9ULL, 0xC55C9EBBCCC70D81ULL, 
            0x88F64F24354B90E3ULL, 0x924DBEA41260F0E0ULL, 0xCAD844D961135D55ULL, 0x6E5B60A8C3013114ULL, 
            0x77F98B1F90B14335ULL, 0x00F1921E868746FEULL, 0x121FDDE0710B8067ULL, 0x6F04687D0D6169D8ULL, 
            0x5AE8AD9288228909ULL, 0xF6C6B6E5671CC069ULL, 0xD724FE504B2DCA87ULL, 0xD63B422528DCFBE9ULL, 
            0x627AE4886E85975FULL, 0x39763F14B85F2D4DULL, 0x64E70DDBD3311F08ULL, 0x84A163FF303CA14AULL, 
            0x10694C07ADCA7B8BULL, 0x0680ACF5D5E48DC4ULL, 0xE0AF563F25B6DE30ULL, 0xD55B27DE2CDDBBB4ULL, 
            0x5286BC8C63751D80ULL, 0xD9C93787ACD60F1AULL, 0x9BA297B26FC8F88AULL, 0xEB2156ED88A2290DULL
        },
        {
            0x9E592D52D694C5D7ULL, 0x7FFA6838460C1D0BULL, 0x3785A786F9EFF0A1ULL, 0x3274484A223FEAEAULL, 
            0xC58D3EE1FCDC605BULL, 0x0E28F4893AEA2AB4ULL, 0x6962BFE25F0EA6C9ULL, 0x21D505EF608E106EULL, 
            0x85396D06330F5651ULL, 0xF1E4ACB3DBE1130CULL, 0x19F6EC599252AEAEULL, 0xD338C5EFD12D5A46ULL, 
            0x60A995BF2A2258D2ULL, 0x28E909727C4A088EULL, 0xAEF07F0083242A98ULL, 0xEE8A3F962C8454AEULL, 
            0xD98FBBA116565951ULL, 0x97DDCB3DAC68DC9EULL, 0xBD7816F483257585ULL, 0x5C486AC77FC5FFF1ULL, 
            0x406A50589E473129ULL, 0x7634E2E6F98DE493ULL, 0xAA4FDC0C71F15C94ULL, 0xEC351D0427D1C2D4ULL, 
            0xF85C447716956849ULL, 0x324D938A139BB9FCULL, 0xEB818B98F5CDFB91ULL, 0xA0DD6D8B2E0E49D9ULL, 
            0x96E8AD15B5FE6C67ULL, 0x361F656D68305F81ULL, 0x1A11CEE4FC40429FULL, 0x627F819A5731ADA5ULL
        },
        {
            0x7621D2696EFE6487ULL, 0x8989FF58D2C9186DULL, 0xD75D1F7DDE099AD1ULL, 0xED9D5403C9400390ULL, 
            0x845993D20B35D5A7ULL, 0x9007F60621FB9A1EULL, 0x30701EE3C281F435ULL, 0xF3D2E6E19EA78F26ULL, 
            0x2ABDF065166F1076ULL, 0x740E27A20DB734F1ULL, 0x8C28D60B4C6956C2ULL, 0x5B15786F0EB191BBULL, 
            0x02C62AF4028CD9C6ULL, 0xF2B42DE9A69A4D46ULL, 0x61BADF4C70AD3870ULL, 0x01AE6C6232C9CDE6ULL, 
            0x9757360BBA4BE744ULL, 0x0D212DA13E2AFD67ULL, 0x49E9C55AC055D382ULL, 0x034F9C5048CC6F54ULL, 
            0xFE74584C1DE9B266ULL, 0x9BA282CD4AE26D22ULL, 0x4A276360E34A3DC7ULL, 0x2FCE71B4C2516469ULL, 
            0xC523ABEEC0C3B384ULL, 0x6F8B1293175C4FB4ULL, 0x7930D16D9DFF5F70ULL, 0xCF3FC005F065F0A5ULL, 
            0x09714BA8303C7965ULL, 0x1A48FFAB92302A19ULL, 0xA7DABC9A485A8D9CULL, 0x458A4730C6E3F88EULL
        },
        {
            0xFBA25CBA7FA9F1F1ULL, 0x3341B7D6A788C808ULL, 0x4861F192B51540D8ULL, 0xB3A5DB08413E8B4AULL, 
            0xDDAD4341B58EC981ULL, 0x845825A9A52AD904ULL, 0x4A80C72E0A32DB1EULL, 0x2989BF7772B4D84FULL, 
            0xBD4BA36F7B8103E9ULL, 0xAD446B37E25AD7AAULL, 0xA6E086427B211B78ULL, 0x28CCE5481AEEAD34ULL, 
            0xAC129B33A431DC49ULL, 0xCF86AD427E7DCB33ULL, 0x4DA616DB79EC1CAFULL, 0x665496463DB3CC25ULL, 
            0x0AD6065E8B2B2961ULL, 0x5B2282603BD9D1DEULL, 0xB1CAF67587878AAEULL, 0x886BF2E6580D904DULL, 
            0xFB30DB0BF2F74443ULL, 0x05431C313B4FD4B2ULL, 0xF947F8577A2304E0ULL, 0xBE084F8A89DEBFFAULL, 
            0x76BA6680468E82E0ULL, 0xE29477E244922EBAULL, 0xB0C7E70C86947789ULL, 0xEA17A305B10C88B9ULL, 
            0x1B06726B3223F205ULL, 0x8E3809C5F3AD8082ULL, 0x0298C5B0AA3B59E7ULL, 0x6FC607AF94998783ULL
        },
        {
            0x91DE731DBBDCA6F8ULL, 0x198B3DAA877071CBULL, 0x6C086C74306F5CE5ULL, 0xA0F5C3AD58A5C87CULL, 
            0x0EA18695ED1BB173ULL, 0x57CFA0C7F72C092CULL, 0x639583F05864F757ULL, 0xC323F2FBB81310D8ULL, 
            0x3C2691EAADC90408ULL, 0xCC6A77FDB6FB013AULL, 0x9BB5E8E2C32BCB58ULL, 0x1D86093C42251327ULL, 
            0x112C739DEB5F4070ULL, 0x7AB9F8AB7B3B5D79ULL, 0x7DFB53F8C66B8453ULL, 0xA0ED44F81A380BCAULL, 
            0x69D852DCFE37AD13ULL, 0x759AB2FAB6C699C1ULL, 0x009E6E0B48E18016ULL, 0x9EFC8B7575AC50EDULL, 
            0x07972A812093E439ULL, 0xE6E4D842AFCE5E25ULL, 0xF256BBD6DC063472ULL, 0xFFA4F703E61B53C2ULL, 
            0xE702431A670EC07EULL, 0xC3F88910B81C97ACULL, 0x7814C45E2F6BAECCULL, 0x2912F3E80428BBEAULL, 
            0x929EDD2D252B1DBCULL, 0x24C5108DB1401D7AULL, 0xD60F465F748A187BULL, 0xBCB93D60170DE091ULL
        },
        {
            0xD7243B65C9D18913ULL, 0x18BFC59849A195E2ULL, 0x62EC93CDEE7872CBULL, 0xFF55FB1C34F22D46ULL, 
            0x05E18C9CF98E37B1ULL, 0xD217220C35B2144EULL, 0xA7B37359CDA39A07ULL, 0x6F00B950E8AA5FB0ULL, 
            0xD29DE7C4C23A8514ULL, 0xB62960A61032B19BULL, 0x51A85AB85BC2B3D5ULL, 0xC79537BEDB8D3A3EULL, 
            0x37D79813CE548280ULL, 0x7B172E853FDF147FULL, 0x858DF26701D7E7DAULL, 0x32DADB8F02F2775AULL, 
            0x201D4C93DB64C7D4ULL, 0x5552D33484D1E7D4ULL, 0x74BAEC730DE29F99ULL, 0x35133432C30937D8ULL, 
            0x3B6F3C93B8D74D63ULL, 0xA9AA71254FC04BCBULL, 0x8BE17980E1299249ULL, 0x3B5636EC5150302FULL, 
            0x14711C4DB21974B4ULL, 0x9DB40BA3BA0222BFULL, 0xFA46FDAF1E103CBBULL, 0x120E985731705ABFULL, 
            0x9C6B182D6E34B781ULL, 0x7504DBE8FD0DFDF3ULL, 0xBB9323424B4912B1ULL, 0x21BB1DC158920E4EULL
        }
    },
    {
        {
            0x55F25AE0F184FACFULL, 0x80F39077F6D8E177ULL, 0x7030F150468A562CULL, 0xADB8E7E11441E055ULL, 
            0xF38008200C6870B5ULL, 0x775DACEE4D99AE41ULL, 0xE17277006A19AB9AULL, 0xC27668D0E91B66A7ULL, 
            0x243701FD61B475A0ULL, 0x4654E7E63BC93246ULL, 0x51D3BF102A946166ULL, 0xF0227A8D7DD91089ULL, 
            0x20BC413540301D95ULL, 0x0035E3B8FB8CE23EULL, 0x7796B04A4A85E732ULL, 0x7ED8FB14C55CE18EULL, 
            0xB86535730CB0E246ULL, 0x63872B1FB114F912ULL, 0xEB34E4532E39E24CULL, 0x5E3FE0DC2E748AA6ULL, 
            0xA4B81CDFDE615084ULL, 0xAD6F92AE20F899D3ULL, 0xA6C9168A1A3CCEF1ULL, 0xA85B5A1F4DDA9C1CULL, 
            0x8DC76A680509D309ULL, 0x26092A8D2D86438BULL, 0x4455FDE2EC327977ULL, 0xDAD36AE8FFD75699ULL, 
            0xC8D024ED30743429ULL, 0x37ECD70BE03AC29BULL, 0x39FAD82A0DF7DABAULL, 0x3FBA68F279A614B4ULL
        },
        {
            0xACAEEA75D417DB9AULL, 0xD3FE67FA967E0D65ULL, 0x8B8469AF47FE57C3ULL, 0xBDBB2714BC8CEE43ULL, 
            0xAD30918C1E25F008ULL, 0x1D93EA93FE6D682DULL, 0xBCF1788107044FD5ULL, 0xD2BD97DE71BBD72CULL, 
            0x319330F2392BEFADULL, 0x8A47C70EB99B707BULL, 0x5EEA8417522F661FULL, 0x00F6583B3C9AA4A0ULL, 
            0x081C51B0C653D838ULL, 0x1BB39523921253D9ULL, 0x2213D8D0BCF4FC85ULL, 0xF99643367083A102ULL, 
            0x5D911DAB9E0A6688ULL, 0x809908FD727B1733ULL, 0xE9B4CFCE1F691308ULL, 0x89B7C5C4B452E1D3ULL, 
            0x85045E94E703E60BULL, 0x788E3622E46AEE12ULL, 0xF7BBB1E5B592A9E4ULL, 0xF9F118BF6240D940ULL, 
            0xCC744387C20A1153ULL, 0x060A85E534E817A5ULL, 0x245B7D136B021E46ULL, 0x2EE6358AC48C1611ULL, 
            0x4FA57D26645D67A4ULL, 0x9FF83FDA3A3617A5ULL, 0xA203554578B30FCAULL, 0x0AA707C0825D9D9BULL
        },
        {
            0x5430C7272190BA4EULL, 0x8C2464908342CEC2ULL, 0x0118E29F17F26CAFULL, 0xF5EAFD909480E11AULL, 
            0x12B1BA49128B00AFULL, 0x8C30323182B3D9F3ULL, 0x3BE7E5F483116263ULL, 0x73BBA4ECCB59DCE0ULL, 
            0xAEFFD807F04AD8C7ULL, 0xB64E33A07B843DDAULL, 0x8F7F0A62C967167EULL, 0x37BE1E10FF0CB8F8ULL, 
            0x2E8B992C4C701ACAULL, 0xFA3F7CDDB844A879ULL, 0xDD50D9B9ACAA3737ULL, 0x3709E94BC26CA0D1ULL, 
            0x147B0630819BBB8BULL, 0xF1F358D7D70195BDULL, 0xE8F6AC04FC2D9EBDULL, 0x7DABE7BA821D9C91ULL, 
            0x4E1663DBBB841A8BULL, 0x0D6EFEBE243AF41DULL, 0xB120CCA856B45F9EULL, 0x6050D9FF00867117ULL, 
            0x775BD7240F6E74CEULL, 0xB0F241C6AD7C9C21ULL, 0x6D49C366B971BE5CULL, 0xC14D1181B1C52E41ULL, 
            0x81B420433FF41FD3ULL, 0xE6A67A97C16ABBF7ULL, 0x1217FC43FBC40900ULL, 0xC8FD3BFAE92F26E8ULL
        },
        {
            0xD1126DFFD75F6911ULL, 0xDF6568B7C009BBCDULL, 0x5FBAA7C7A867C70EULL, 0x3EC7181C14DDDDF5ULL, 
            0x8C9C35179C652925ULL, 0xE9686FBEFCAD685BULL, 0x4E599A0B84A06304ULL, 0x196FF778D49043B9ULL, 
            0xB00A5146E99276D7ULL, 0xDC015FB9A2BF8C3BULL, 0x78A25A90EA111656ULL, 0xFC2BE796BD2E8FC9ULL, 
            0x0BF9EB5E358ED591ULL, 0x5ABA7752C445B3E7ULL, 0xCB942FAAB32EAA55ULL, 0x7E6D18B15E7F6429ULL, 
            0x2986672CA427D386ULL, 0xEA7447BF7A055889ULL, 0x14CD61BFC8D4793FULL, 0x670A0C8BD9EC7196ULL, 
            0x0E7DB76E7A4674BFULL, 0x810DCFCECAF60CF0ULL, 0xC453DB21BB12928AULL, 0x10BC6388F27DE11CULL, 
            0xC42368FE88F1FCE4ULL, 0x717D52466ECF4CC2ULL, 0xC4E1E4DE6FD1061AULL, 0xDE1718FA6FBC175FULL, 
            0xF818315BF61A9019ULL, 0xFDA490DAAA3FC8FAULL, 0x0802820274F164F7ULL, 0xB1D68C46FE8B24A9ULL
        },
        {
            0xD8C5EA4E66E84D4EULL, 0x1F8B33446F4D0CA2ULL, 0x793CE21707EFE124ULL, 0x813529C28BF048D3ULL, 
            0x4B2A0B09DDBC6FCAULL, 0x3E1B0418AC45835DULL, 0x8D172961CAB5089EULL, 0x419EE915990C3BBDULL, 
            0x44F9C17F5717DA2CULL, 0x811889914075FC2BULL, 0x6A68E72665152510ULL, 0x0FF006851CAFC47BULL, 
            0xF08178A0499A75F7ULL, 0x380F04BFC82756C2ULL, 0x243D3C727EAB6697ULL, 0x3CB2AB0F643189BDULL, 
            0xBA9176222CC22EA8ULL, 0x894EF27AC9B5AC86ULL, 0xC400FD644637683FULL, 0x5EE6612C22805AB1ULL, 
            0x1A94C1FB800F0CAAULL, 0xE30BAD2B8E6DF7FFULL, 0x2EFD7C6AA8932F85ULL, 0x5860416F887232E8ULL, 
            0x5111F3F3CF78EDF4ULL, 0x9ACC401823345B33ULL, 0xA8CC6661B60FA8D0ULL, 0x48EEC5412DF492FAULL, 
            0xEF5976FEBC46E374ULL, 0x2E545768111AF811ULL, 0x23F2E9E73AA99DD4ULL, 0xC5077F8966D94828ULL
        },
        {
            0x1BE661F210A6DBA2ULL, 0x3D9C0C95F92C8CD8ULL, 0x17FF470EBCBB4AEEULL, 0x5FFA3D5905E18DD3ULL, 
            0xF3C8FBCBC85173A7ULL, 0x7818425BBCA7AB46ULL, 0x1F38390166F84AA4ULL, 0x35274282C7B389D0ULL, 
            0x5B10B7FB67288B22ULL, 0xA5CE50D24AC692D7ULL, 0xF2522D3C917C0F07ULL, 0x6E69B22FDDB31461ULL, 
            0x5A6ED16F29C5A079ULL, 0xA0F6CC59227CF540ULL, 0x06CA877CBC03634CULL, 0xC310B930E88748E9ULL, 
            0x57A6BFA7A59B0910ULL, 0xC3B05F4E0959DEACULL, 0xB367BB1648C12D15ULL, 0xD89782B7047ACB01ULL, 
            0x4B7C58E495B42F7DULL, 0x6A466706BEE0C458ULL, 0x99025644E3203CC4ULL, 0xA28D00C305D553F1ULL, 
            0x0F73F0F37E9F20BDULL, 0xBB5A4EB4F6D28234ULL, 0x31E45426858F3D52ULL, 0x55DDEE4748DB1A46ULL, 
            0x16C45D10E65264F9ULL, 0x16904C6C35A678CEULL, 0x565FFAEA721604D2ULL, 0x44D7F9027A6086F1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseAConstants = {
    0xF9A04BC8877FB32DULL,
    0x23E28C2B69639DE6ULL,
    0xF074FE5422458513ULL,
    0xF9A04BC8877FB32DULL,
    0x23E28C2B69639DE6ULL,
    0xF074FE5422458513ULL,
    0xF32FC9A3180DD20AULL,
    0x50811996AA497E2AULL,
    0x72,
    0x98,
    0xD9,
    0xCC,
    0x75,
    0x0B,
    0x71,
    0x24
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseBSalts = {
    {
        {
            0x49A67E5D7344E389ULL, 0x2787BE5F4DB7FC5EULL, 0x30951C66DE21EAB3ULL, 0xC6B5B296856DA909ULL, 
            0x323390A5B68A20A7ULL, 0x66A5C8F653144808ULL, 0x4FE967B0EBD1B5F8ULL, 0x2D80D2B6517FDE66ULL, 
            0xAC5E9CC355FF94D6ULL, 0xFC52CE53ECE9D8D1ULL, 0xE9B6AEE7AFB3DF81ULL, 0xDC0B3F1172B668BEULL, 
            0x41BFD59A58F6CB79ULL, 0x71EE1477A8F7FA58ULL, 0xFD304097AFE4F56BULL, 0x9167C73C576987A4ULL, 
            0xC2658D4A07088D35ULL, 0x105B23EE633D7E87ULL, 0x01FB8F1ECAA020DDULL, 0x7B5FFBF1C3C5FD2AULL, 
            0xEDAF3EEE43020262ULL, 0x8B736E686EAF9CADULL, 0x3D132F4AC5BD8B1FULL, 0xABD1DCF57FE29C1DULL, 
            0x499F0807DD7546ABULL, 0x411B8319DD39F9D9ULL, 0x839F67DAA197A2F3ULL, 0x8352A0E95FED0B62ULL, 
            0xF0A6BBFF584C669EULL, 0xA97626BF3F594739ULL, 0x7A78F0CCFA576635ULL, 0x8DC8BF45024B9482ULL
        },
        {
            0x7CB34B0F3B98812FULL, 0x63402807763B25DFULL, 0x09FC49C710AC0A10ULL, 0xF7C1C33B3406E96AULL, 
            0x1307D496BD1CAE1CULL, 0xCF4721200DEDEE9EULL, 0xC980C56F326CCA6BULL, 0xA8C147123D137922ULL, 
            0x41BCA37FAB4CFE45ULL, 0x23C604B4B3A7960FULL, 0x51C25BCA44A56EE3ULL, 0x35EE66DAAA799935ULL, 
            0x7FC2C6EA5377E348ULL, 0x683239C840725ABCULL, 0xAE36DF5DFA333F3AULL, 0xC4D6465BEB406430ULL, 
            0x5729CA930C19A3B8ULL, 0x454151A221004BC4ULL, 0xD4C87CCD7EAD493CULL, 0xDDAF2187A49E7068ULL, 
            0xFFFD8F9E1FD8F529ULL, 0x769D5C72B38CA0E4ULL, 0x59EEA358E9F1EEECULL, 0xA9FD9B8368A9ABE5ULL, 
            0xDA2219B1C30CE168ULL, 0x1E8DE7C9CA3CE09FULL, 0x317E03F2F9C532D4ULL, 0x78D771BE5BE5B6FDULL, 
            0xBB54AC043BC28320ULL, 0xBEB92FBAA1789B94ULL, 0x686E2F91B3DFA25CULL, 0x7D66A57BBA0A23F1ULL
        },
        {
            0x25A016D2C201C312ULL, 0xE16B1F4C73424F21ULL, 0x6D156A9F81628123ULL, 0xDBD96B7B52BF0B50ULL, 
            0xDE452B7D4E3717B5ULL, 0x0B292066118B99A3ULL, 0xD08F032C0230E0A5ULL, 0x2E3A60F9EFDEAFB2ULL, 
            0x8AC06EA09C9AEDD8ULL, 0xE0FFE780103EEFAEULL, 0x45E6D8EC74EAE3DBULL, 0xFA92E6FEA8AF0F3CULL, 
            0x3E7DCA9026675865ULL, 0x666E3538831E6D7AULL, 0x5B720A44DCC3AE64ULL, 0xA96865ECE36B2401ULL, 
            0x6A419F0239B1A98FULL, 0x77698C157AA041CCULL, 0xE1F98F6F611C1EFBULL, 0xAEF6C85A4AF0027BULL, 
            0x52BB9488B6059ED6ULL, 0x5F2E55C70CDA6F02ULL, 0x635F1017C2A81662ULL, 0xCB1A77C581EE27E9ULL, 
            0xC55ED73DD3FC67D8ULL, 0xB90759154B29CC28ULL, 0x0A747649F60B97CEULL, 0x06DE3BCE986657A0ULL, 
            0xBAE4D29D3981FFCFULL, 0x5F8D901326AD0B6AULL, 0xF0409539EEB051A8ULL, 0x4C73C3A54255BAF9ULL
        },
        {
            0x8CF797FD51C2022BULL, 0xFA7A7889D7C2F4CFULL, 0x5D09B1D1166A22E0ULL, 0xC06F2F7FE08C25D7ULL, 
            0xAF3B60EE7000EF9AULL, 0x7DD6DF2212E4DA73ULL, 0x07638E292A3D8912ULL, 0x642386B299239301ULL, 
            0x930C589F350CF7C3ULL, 0xD22ACF8F8D2C78F2ULL, 0xF899BC06A0C51D4EULL, 0xBC66BC25AFA99CD1ULL, 
            0x42A61B30466BE543ULL, 0xF9EFAA1AF17EA653ULL, 0xD859045C08EA7657ULL, 0xF6EF938E7CA4CA18ULL, 
            0x55D578DE598ECC73ULL, 0x8C2F727754C0DBEEULL, 0x212FC26AC446BE88ULL, 0x8FF3C696859C1E3FULL, 
            0x7D0ADE9F553D7968ULL, 0x5235B4327815F66EULL, 0x6ED3029D779DEA8DULL, 0xADAA3A224BB3710DULL, 
            0x39708F7E9E415771ULL, 0x0DE6F27FC65DB7B6ULL, 0xBC96A6161450BED5ULL, 0xA8226BC91F64ED0DULL, 
            0xFAB219B3F7520F71ULL, 0x75002F9BA62C12E2ULL, 0x9633A7E2183FB810ULL, 0x41477DA6CEA5AE4CULL
        },
        {
            0xB3B565021A5C9F4FULL, 0x3B6EB2C00435D868ULL, 0x7C7DC8F92E3F76A1ULL, 0x8D35AC96DB99258CULL, 
            0x147310DB6C54E5B1ULL, 0x145C3A7C52DB5325ULL, 0x7602AE5229058169ULL, 0x09B3653BFDAE3FD3ULL, 
            0x9C7F6606039EA89FULL, 0xFE8DFD8709B80F7DULL, 0xA531141F0FB11031ULL, 0x6CF7FF97EFACF473ULL, 
            0x11100F432120B45EULL, 0xF4E5FF3D23216252ULL, 0xF6E69D2CAC7E8B14ULL, 0x6280A4F2D1848C98ULL, 
            0x0780958DE445AB79ULL, 0x258EA4295548D920ULL, 0x87A703190E850C52ULL, 0x0F3086FF62FFACA9ULL, 
            0xE8198508FF4F469BULL, 0xBB7BBC94D8F7F3DEULL, 0x5CAC850628C230E3ULL, 0x628DC30020817ECCULL, 
            0x35709C1EF06BD005ULL, 0x3527B3CAA482F5D3ULL, 0xA3F607F0EAD5F714ULL, 0x33F58409D36D32D3ULL, 
            0xC46278EEF9A3950DULL, 0xA5C01D83AB29AB75ULL, 0xC6CE573B4270F639ULL, 0x94DEA6A2A61F09D5ULL
        },
        {
            0x7A80CB0323F1127CULL, 0xCA6430EBD18004D2ULL, 0xCC86D4AD49630893ULL, 0xD9234D39B7BFB519ULL, 
            0x55512ACB656DA1CFULL, 0x4013D9398A6D9F5DULL, 0x2F5E005F915135D1ULL, 0x187B148AFC07B46AULL, 
            0xCD9809C7610DE735ULL, 0xF5578643717C69F5ULL, 0x8531FD6D49007B41ULL, 0x84F27374427C97A4ULL, 
            0x551E19DCA3F5D29AULL, 0xF409AA5D4364E667ULL, 0x23CF11D1AF78979EULL, 0x62A7E04E9DE2E8C9ULL, 
            0xB1EFB0C0C503E101ULL, 0x8ED32CA047CC841AULL, 0xC704066DD6EAF1D3ULL, 0xF086A249D59D6E5CULL, 
            0x0F29D4FE953E2CF9ULL, 0x7D99323CF3526490ULL, 0x5E5E014186014C71ULL, 0xEDD700FCBB778926ULL, 
            0x1F6518393D1D2EA9ULL, 0xB9CABD9668216384ULL, 0xB11EA8AEC452C18CULL, 0xC44BAD595A579DEDULL, 
            0x29FC0D3ADDA7BF23ULL, 0x404CD52CD08BD8B5ULL, 0x7AF2E8673092940FULL, 0x6BE26C9C7E609A66ULL
        }
    },
    {
        {
            0x8A7BB55E83D8BBADULL, 0x3B7238152B455215ULL, 0x2D7CC535C0414E69ULL, 0xA59E8263E0F4D62EULL, 
            0x1F2A2A7BD6596DCEULL, 0x09F86BF7EC46FD54ULL, 0x96BF21EFA90E5DE2ULL, 0x956EE64F2DCA7ACCULL, 
            0x036047B08345E7D6ULL, 0x94A5A67DDF4C257BULL, 0x76AAF58AE1BF726CULL, 0xD4D9D0A1E70024F1ULL, 
            0x02760CF4D8F3EBEFULL, 0x8FEDE3C24E223746ULL, 0x9F22C98017341743ULL, 0xA6EF41FF465FCC72ULL, 
            0xAEA3C196193E0E00ULL, 0xA568A575714E9A32ULL, 0x7188EF660266F24AULL, 0x86789AA0F3067580ULL, 
            0xBF97A70EACAB3590ULL, 0xA781A11CA3FADDD8ULL, 0x83379F7DE56C022FULL, 0x3105DB4F4FB1660AULL, 
            0xE23C7B9A7D27F527ULL, 0x5CCF7686F91032E7ULL, 0xFCEB979725ED10DEULL, 0xF3FA8B78BF9FB284ULL, 
            0xFC042266A131645BULL, 0x591CC6E312FF6F75ULL, 0x23ED2A495039CDD1ULL, 0x42D476CD2467D926ULL
        },
        {
            0xD4AE269C4F77F6C3ULL, 0x216CBA3B38B23F72ULL, 0x70DA656FF7070659ULL, 0x7F1AD9FB7B37D921ULL, 
            0xDF16B9A2EDCD0628ULL, 0xBFBA1299A3DFE426ULL, 0x691D19966BBFB89AULL, 0x0C431F27FD9A3E37ULL, 
            0xB5789024883E4654ULL, 0xABB1359EE2A0F9ACULL, 0xC65BC17E4FBB9901ULL, 0xA240DFABAA776BE0ULL, 
            0xC1AE48604CB3D559ULL, 0xA3487EB19EB06CA7ULL, 0xA60F6D09734F31D0ULL, 0x5BDC056DCB532BA2ULL, 
            0xBEE8FF88D7F7A0A2ULL, 0x6E9656022017F77DULL, 0xA831B6DCFE47A0DCULL, 0x0D1215ABFCA714E3ULL, 
            0xBD42A9E10C4906F6ULL, 0x4300AF03EE4C214BULL, 0x3C2FBAAB305DDE17ULL, 0x635A34A0305BDEEDULL, 
            0xB8DAAACC78725B6DULL, 0xA485B9DF8DEF8C52ULL, 0xACAE90AD1D11872CULL, 0x67B56E6DEFEAA3D7ULL, 
            0x6C0EDE81D7971FBFULL, 0x48F3A827A3412C15ULL, 0x92FA7E230D6DB051ULL, 0x225EAA4C5C4F2923ULL
        },
        {
            0x64B7AE9F43FFEAF0ULL, 0x4D9271C2A02D0B96ULL, 0x87B0CCF4E743D36EULL, 0xE06C125B46F75C35ULL, 
            0x737812D37F7967A5ULL, 0x42C886463AE5ED91ULL, 0xDCBA00733E702DA2ULL, 0x60A6D03474170FADULL, 
            0xB2293BD670E58CB3ULL, 0xB6C64A5CE25D8ED3ULL, 0xF1A8CBBEC5B44CA4ULL, 0x5CC38F756C69FF60ULL, 
            0x64C3BF0FBE3F13F7ULL, 0x59BA0356149B28FBULL, 0x5D76DEF4E9432F46ULL, 0xBFF24ADEC1B93635ULL, 
            0xF88E37C6BC77FBAEULL, 0x856D3B7AC630468EULL, 0xED3075485D9BA235ULL, 0xB16265AB313BAFBCULL, 
            0x4EEC9970BFC8C1A9ULL, 0x4DE34E3963810A74ULL, 0xAEB0B4C840C4128AULL, 0xC26E326D67305A02ULL, 
            0x012744A6B3B5D28DULL, 0xEC6724457EA6BC18ULL, 0x88477B827B7EB52EULL, 0xB8C9E6CBD8375A9DULL, 
            0x2665F165430838B4ULL, 0x63C28964D00ADF5BULL, 0x57CB2F1150237EAAULL, 0xCFFE1E1289B3EF6BULL
        },
        {
            0x2228FC54C1F26CB6ULL, 0xBCF74E5FD8782EAAULL, 0xC32C7C6CE33F007BULL, 0xEA330362CA0B839FULL, 
            0x7D7101636D5262A1ULL, 0x86419FDB3D664117ULL, 0xCD8924866D2F0CB2ULL, 0x3A2E07202329F7D8ULL, 
            0xE79BE85C7BDA5BE0ULL, 0x4FF939D835DC1CA8ULL, 0x43F5384347DC3357ULL, 0x3454C50A4EF353AEULL, 
            0x1049CB7FBC193CF4ULL, 0xC1B8B1AC74B27F73ULL, 0x3B4B416B54B99D98ULL, 0x3566581C3CC3D6D0ULL, 
            0x8C6A1BE3627B878CULL, 0xFC9993DCA5E72705ULL, 0x6BC3E38976088610ULL, 0x4CD047D2A145C84CULL, 
            0x3A3A9E89582E45BBULL, 0xF51A85C73B3C7145ULL, 0x51292ECEBE7012C7ULL, 0x42007609F7CB7B79ULL, 
            0x6C081A040487E54BULL, 0x089FC7097C370680ULL, 0x0D28E92F7A163C19ULL, 0x79CEBFADDE426EBBULL, 
            0x8F4D1EEBB1088DD9ULL, 0xB39B9DFBAC59CD85ULL, 0x44D5636A059BA0CDULL, 0xA7346B251D9CCCC8ULL
        },
        {
            0xCB6A814D312F03F6ULL, 0x2CDAE013C525F1C5ULL, 0xBBC5F730EE57C9DAULL, 0x371864D2AF260372ULL, 
            0xD1E89445B6F8D75CULL, 0x86D1ED03A8FAC294ULL, 0xDAF9385C96F3A1DBULL, 0xFDDA796023EFE9CCULL, 
            0xD6FA199861E8D3DEULL, 0x571A8DE52AF4F070ULL, 0x143BBD72B865343BULL, 0xA4EE2964F8E43DF3ULL, 
            0x42D42FAAB8AD32B3ULL, 0x8AF9D0F3690AC95EULL, 0x37F26A1A89FC338AULL, 0x8856B24541E02B27ULL, 
            0x0D5E53DDAA5A29F0ULL, 0x2760D9C1A31E7535ULL, 0x798C8B065987735FULL, 0x7202C8D3480C0067ULL, 
            0x5BABCCC9EE604AAEULL, 0x7ED62FA598A4199DULL, 0xB21BCA1A772AD092ULL, 0x71E9A626EB503E05ULL, 
            0x6B420A890BB8CF01ULL, 0xDA05E1C3BC0B0D79ULL, 0x20990F970D874380ULL, 0xA413FF88D308F8F5ULL, 
            0x28E06854A930E333ULL, 0x9EE77253EC130D94ULL, 0x79C990A1BF04CA2CULL, 0x75E8CA47B82C9AD5ULL
        },
        {
            0xE9B6BDBDA16134F0ULL, 0xB12EFCB363C8904EULL, 0xAEB1807A189122B6ULL, 0xDEFD438D5EAC19D5ULL, 
            0xDD40B9EA13BD5157ULL, 0xA16E22C68BA4445DULL, 0xB28446D9263212DAULL, 0xA0C6148779E82364ULL, 
            0xA45D909B78F7BACFULL, 0xDF544CBF5F0AC7F8ULL, 0x2957B4A66485A916ULL, 0xB3CC7ED58C006924ULL, 
            0x350E70167AE2796FULL, 0xC76D44323FFDC671ULL, 0x19D1C120F8B4B165ULL, 0x7992763DA0A49B5AULL, 
            0x5353FA716C899087ULL, 0x0976F0849895A3ADULL, 0xABD6FD7F611846D9ULL, 0x2EFE8AF080B812E1ULL, 
            0x6E31DF31E9ADB37DULL, 0x9EE55B89AC92A8C9ULL, 0x38655CFBD30CD63EULL, 0xB9632A58E72ED94EULL, 
            0x96F03704324ADFD1ULL, 0x49ED3AE47DBCBAF7ULL, 0xA3273EFCEC7B213AULL, 0x458359C4653A3468ULL, 
            0xC0B4C74E197FB6F9ULL, 0xD8C6FE1AF56E42A8ULL, 0xC12B730AE066296DULL, 0xCDEB226F1AAED5CCULL
        }
    },
    {
        {
            0xE4FB1BC3FC45E04DULL, 0x5907ABF78B1B817CULL, 0xC4A8B6BB7C003CFBULL, 0xBCC7A2425981ACBEULL, 
            0x64DC6F2BE4CFC854ULL, 0x45C58206ED1747B1ULL, 0x2134E3A60DE7CCFBULL, 0xE0B30892710F75ACULL, 
            0x6A4B4A2A21C048FCULL, 0xC152EBB176CA12D6ULL, 0xC4DAED8EC2CED56EULL, 0xB30DF554731C12ADULL, 
            0xAA319FC57BDC9455ULL, 0x15335F58BFFEDAC4ULL, 0x7CE0DB2497BD0A3EULL, 0x0886F1A4163165A3ULL, 
            0xF1206DF612F4B91BULL, 0xE1B52F57E41B9390ULL, 0x479960FF0346DD4FULL, 0x97C0FAD77BCFFF19ULL, 
            0x7A86EA6EA0371E14ULL, 0xE19FC667713E8699ULL, 0x538F3DBA15BF367CULL, 0x771AE6120EC687B1ULL, 
            0xD4D55B79F9333750ULL, 0xF32C04BC7F682C5FULL, 0x8FDEFE1303D10F68ULL, 0x6A01E1D8A715FF2AULL, 
            0x6109C1015F3BB5FDULL, 0x19252A30D183D0BEULL, 0x484BB5696EDA5742ULL, 0x431DE1E084A3C396ULL
        },
        {
            0x2856BD670E2629FFULL, 0x1C723A7811F1BEFCULL, 0x91BCE543838EF945ULL, 0xC1D76617B794A2B6ULL, 
            0x15873DDCFAF4D0F6ULL, 0xF5F980234E292EB6ULL, 0x21078DD8C08461EBULL, 0xB10719168D0C09D3ULL, 
            0xD8ADF1CC70026F35ULL, 0x0FA96FD406DE5A8AULL, 0x935ACA5814A0FDF4ULL, 0x40C4E4297E8FD35CULL, 
            0x988607AAEF122DFDULL, 0xA2252E5701B914AAULL, 0x424CFA43B2B9E485ULL, 0xBEAFE3B813E586D2ULL, 
            0xA0C68C5EB980EF56ULL, 0xB4DDDF984979B876ULL, 0x0368DE14F996EC58ULL, 0x326B89A4E92F1DF9ULL, 
            0x5EAC4E8781A85164ULL, 0x8F569AE7D54959E2ULL, 0xB322ACA91FAF1475ULL, 0x71D3936EAA271421ULL, 
            0x29D975924E17D2E4ULL, 0x7C38D5FBED50B287ULL, 0x56C350EB11798B1BULL, 0x580DE8A2BBFD3CF1ULL, 
            0x529613E3E278A791ULL, 0xA8CBA7F72F72CBC3ULL, 0x68C0152B4E509B98ULL, 0xFD96458CA7A157C7ULL
        },
        {
            0xC5A860CA5AD1E949ULL, 0xA939101DF9B6B570ULL, 0xABD100798EB260B6ULL, 0x276469210702FF51ULL, 
            0xB39CF538A3FD5390ULL, 0xE8C57ED145349967ULL, 0xEC0146B052F0E101ULL, 0x1CA0E0C65BD7618BULL, 
            0xBB9CE0D938EC8DC4ULL, 0x31BCF47F3F3F17C5ULL, 0xE0BE5C72D5175485ULL, 0xB546D28B3D353F2DULL, 
            0xE0BBB75E57CCDC07ULL, 0x79B52B1826953684ULL, 0xF7AB1C039E59C127ULL, 0xDAD93FAC1555D750ULL, 
            0x2CFE9A6E58544374ULL, 0x0D1C6EBFEB120032ULL, 0x3E904B4C7CFA8C4DULL, 0x8F77673802768468ULL, 
            0x4151CDCC90B33A00ULL, 0x6A6C532887C38B09ULL, 0xDCA2645359E0D9A9ULL, 0x6648351CE67542B1ULL, 
            0x1C87F7113DCCE0E9ULL, 0x1AB9EE8D73EFC4D6ULL, 0x39CD0388FF9EC86DULL, 0x3450D506A04452A7ULL, 
            0x188CF2EC534A3B2AULL, 0xFAD1F4929685344FULL, 0x3878581E4E78EB5FULL, 0x0BE26578FA8FBA64ULL
        },
        {
            0xC74CC7B774659CBCULL, 0x0F575EAFB7D273C6ULL, 0xBE705577972623F4ULL, 0x58A17BFF6F27F945ULL, 
            0x28C39940030721F2ULL, 0x260319459D625FB0ULL, 0xE44A0F63A400ED43ULL, 0xEB8E1FAE5EC3786CULL, 
            0xF0C4CD2F22CDE214ULL, 0x9277A2D519A2C06EULL, 0xFB90D1FB892B3730ULL, 0xA5CD82CE0759C0F7ULL, 
            0x1E9C5AE1251A0776ULL, 0x1CE984AC61BF1091ULL, 0xDF012C172D124CA2ULL, 0x2ADB3BD68B0A0A18ULL, 
            0x7B83B43D2518DEFFULL, 0x0A79572FB0A3AF43ULL, 0x0A7E6BB95F4C218FULL, 0x3D7BB59BE57B003BULL, 
            0x1A80FA8FF6C7806CULL, 0x8F43AFC051ED89B8ULL, 0x3E5A0DA18B8CA4BEULL, 0x786E9D08BF4DD1D2ULL, 
            0x9245BDD25FFC180AULL, 0x12871F7955AD5259ULL, 0xDA0B60892BD94B36ULL, 0x609081EB62BE6A49ULL, 
            0x42EC4C834A5C3BCDULL, 0x58FCA85810B97DE4ULL, 0x87DD09F04430E43AULL, 0x6D8C6307466B679BULL
        },
        {
            0x871D7CE88C817469ULL, 0xE42F0699ECA89694ULL, 0x71C3217A4DA90535ULL, 0x9CB84FC48EF8E4E8ULL, 
            0x9BF543AADA720D62ULL, 0x812E5F93047592FAULL, 0x160EEBDAA41A5E7AULL, 0x2C4646702D89A86CULL, 
            0x4183C25144E8164EULL, 0x6186B7645ACA406FULL, 0xBEB80F03FE93F00CULL, 0xEF1AA9ADFBD50FA3ULL, 
            0x4B3CC48FC002F4F0ULL, 0xECD092D55EC9727FULL, 0xBE1981BB961D4932ULL, 0xBB85F5D234FFBBE4ULL, 
            0xF13060F97ED920E3ULL, 0x566426FE80C8159FULL, 0xEBD5BC30030EA9BCULL, 0x944C492CAAAC19C7ULL, 
            0x1558C29A6D0FDD95ULL, 0x0450A5ABA622F2B7ULL, 0xD7D79C6E84B095D7ULL, 0x030B6CC849C99301ULL, 
            0xAE04045FCA8C99D1ULL, 0x47A886D2EFF5A56CULL, 0xFD693BFB845789A7ULL, 0xECDC80AAEE941EA8ULL, 
            0x87F652380FCF0112ULL, 0x67BF7254E0CB35EAULL, 0x351E44A398D682CBULL, 0xAC2169157A699A52ULL
        },
        {
            0x3906B2E0ADDBC432ULL, 0x29AADAEA1F818EDEULL, 0x43A2DBCB01CDF28BULL, 0xB4EB0F615B9840A5ULL, 
            0xA2E1D7200718A16AULL, 0xDC82DD4805A06D4DULL, 0x3205B2968B5428DCULL, 0x4BA16C06E0F67FFEULL, 
            0x81C91AF2233167E4ULL, 0xDB3E860F74C20F42ULL, 0xA1516A69A087EE22ULL, 0xA3628511381073E6ULL, 
            0x3279725466A50B7CULL, 0xB0B7D6E3F9C13A93ULL, 0x9B20A703B78DCF37ULL, 0x9A28747E8540A0CCULL, 
            0x4BABD55C4B6DCE32ULL, 0x3D4120DC4D8765B9ULL, 0x1FC1CF9B5A3B40C8ULL, 0x197FF6207D3D28A9ULL, 
            0xF5EBF9978FEF44DAULL, 0x0DA5A4900FB7D5B2ULL, 0x78BB29C18CB1106EULL, 0x2D8AA44E3B39D7C0ULL, 
            0x7F8546BAA6BA6ECBULL, 0xD4D6F2A6DE8354E3ULL, 0x28F4DAB5D900A0D6ULL, 0x7FB1E3E34B91AE75ULL, 
            0x5E2B9055519EF54FULL, 0x5DB2DC74540F41BDULL, 0x4F6A1ACA2E2368B9ULL, 0x8A99053FCC3F9BE0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseBConstants = {
    0x481474998CC09121ULL,
    0x4ABE8A7C09A50F92ULL,
    0xC7C0AB4D3E837DEAULL,
    0x481474998CC09121ULL,
    0x4ABE8A7C09A50F92ULL,
    0xC7C0AB4D3E837DEAULL,
    0x357F18D3149C44B5ULL,
    0xAA97436994ED63F1ULL,
    0x93,
    0xC1,
    0x7B,
    0x10,
    0x1A,
    0x4F,
    0x54,
    0x07
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseCSalts = {
    {
        {
            0xE4AF0016E6CD81C2ULL, 0xDC3AF4B17AEDA25BULL, 0x0A6C925B624E917CULL, 0x5DDE5A5AC744038FULL, 
            0x03726789350DD3FAULL, 0xF060D324614FEA13ULL, 0x052F1D79FABF0998ULL, 0xA2FF91FD65414EE4ULL, 
            0x1C8D72FC4E55FF14ULL, 0x4BB5006AE33BDEF5ULL, 0x17982C2511BF7CFDULL, 0x7455A3EE3741BA64ULL, 
            0x4857870FF7BF0418ULL, 0xC1B7BBF862EF32ABULL, 0xEA2412FD12967EBEULL, 0xEA2B1175D8C01105ULL, 
            0xE2B6A5D7420CACAAULL, 0x167ADCC0606D35D2ULL, 0x122A37518EC65976ULL, 0xF6858B493D05F687ULL, 
            0xEDB952745D80BBCAULL, 0x26B6D463E40979EDULL, 0x8EDC5C7D32B0A12CULL, 0xF517678807045EEFULL, 
            0xD454A99583702843ULL, 0x4FA9B8EE654220A5ULL, 0x2AB42F81662A0D9DULL, 0xD930C6A3768908AEULL, 
            0x901614A78AECB75DULL, 0x89C635513F3C6409ULL, 0xC41EBF43A0A57B9BULL, 0x026073D90589E222ULL
        },
        {
            0xED101659E2AA13CFULL, 0x7954EBC93EB24699ULL, 0x231DED47348664B9ULL, 0xC8FAD0F7BFEE782EULL, 
            0xB9349BFA34ADDD6FULL, 0xEB28EF5EA62A5FB4ULL, 0xC918CDC547C50C71ULL, 0x39C513E7EC5DA7B5ULL, 
            0x7EEA625907895711ULL, 0xEE5A077602BBFDA9ULL, 0x364547BFF3848526ULL, 0xFF185AA89AD49055ULL, 
            0x92A444B94D3C255FULL, 0xE468FCC6A22727F8ULL, 0x8384CDEA9EBCC98DULL, 0x3720DEA2A2ACF7E8ULL, 
            0x9EA7C1D071636A6BULL, 0x6F297EC0E693E032ULL, 0x7A4EE03B42F12C72ULL, 0xD879AF14ECF7DF11ULL, 
            0x34B644CDE7AB0033ULL, 0xC91DA3D9209E44D3ULL, 0x5D993641C4C02118ULL, 0xFF1182E0D51693CCULL, 
            0x506A271DD610A40AULL, 0x844715F5C8A6B56BULL, 0xB3254E23E1986CC6ULL, 0x0BA5B92E8393625CULL, 
            0x7FD3AB903954F344ULL, 0x2F3764D270A94591ULL, 0x21F477C6C33B4598ULL, 0x3BCFE7AA9DD031A4ULL
        },
        {
            0xE70E04302947B38AULL, 0xF37814D2BF3FB29CULL, 0x3CF8DF9BECFCB88CULL, 0x603C9EC515BF9FBBULL, 
            0xCC3BC96515F3BB1FULL, 0x81FCDA21B4CCE264ULL, 0x4051B2D13B3687AEULL, 0xF3E9D120EA5C06ECULL, 
            0x8C8252F55895CEA2ULL, 0x469755B76B39DADDULL, 0x4F4AA140C89EF54DULL, 0x0C535FFD251312C7ULL, 
            0xAE96321FC642AAF3ULL, 0xF05E2E0D82657BC4ULL, 0x8399128398C7E04BULL, 0xA457D054C7B02CCCULL, 
            0x39AEC32A88208704ULL, 0x98997EF6019F9B7BULL, 0x6E324EE40623EBF5ULL, 0x6C42A938CAC00B41ULL, 
            0x80AD48D297D83F52ULL, 0x1FDAB89924ADA0D8ULL, 0x7537FEB86C4BB915ULL, 0x9861AA03893C6149ULL, 
            0xE4621193BD108C0CULL, 0x01786DAAF9BD1FA0ULL, 0x8652DF1F605D0C4DULL, 0xE0C9E0D4B3AE4E58ULL, 
            0x786936902F8C04E2ULL, 0x92320147B49655B4ULL, 0x1EBF869DB2F7D080ULL, 0xBA5675FC303B5CD5ULL
        },
        {
            0x0D33B6C02F38EA18ULL, 0xEC511D28A3C5E869ULL, 0xDD0C8E25FD887BE4ULL, 0xDAA438A3D90F65D4ULL, 
            0xBC64F706072860F9ULL, 0x2025DEA9CCEB87F3ULL, 0xDBD2C0F9A04DC6EBULL, 0x5B40EE623D312801ULL, 
            0xCF886F152077DB21ULL, 0xC2E2E73EEE398B5CULL, 0x987114CCED0E3CC1ULL, 0x5C52012EF5CDD6DFULL, 
            0xDABBDC03190FBFFCULL, 0xB1C1497C53F602BCULL, 0x46621CF21B940E90ULL, 0x01326CE0690A2E68ULL, 
            0xB9D7B1232F83B5E9ULL, 0x2068C361AE030A20ULL, 0xE12BDB6EC238E6EAULL, 0xF49F76547F01BB31ULL, 
            0x33E5C7004200374EULL, 0x44C97BFADB8D1025ULL, 0xBE224E5148BEA007ULL, 0x4722CDA382C540F0ULL, 
            0xAC02BA9030CB0E73ULL, 0x4D6E77092906ED4AULL, 0x6BD2E07557DA9268ULL, 0x829B753D011353CFULL, 
            0x86F06B8FBFB27E26ULL, 0x5E0596F9F45A4BFAULL, 0xF945A6F68CFA68A5ULL, 0xFC0C2CD9FDEF84CAULL
        },
        {
            0xF66BF3E7D09C900EULL, 0xF97CEF2101A7D938ULL, 0x08ACC5DBE87B797BULL, 0xAC9FA0DDBF72C5D3ULL, 
            0x467284E21A4672D0ULL, 0x3D4603DF68B9E0EBULL, 0x59F7B00FF87870B1ULL, 0x3A2C70A45A3C10DFULL, 
            0x09D2254E53BB6065ULL, 0x84252F61A1AB4EA3ULL, 0xD0F2B52383456735ULL, 0x84FAD09463213FACULL, 
            0xCC1C35BD4AB9F28EULL, 0x8E5D662245A36E39ULL, 0x76E8751FA1AE7887ULL, 0xC7A6666655B8423DULL, 
            0x43CFFD0233111866ULL, 0x554A2D07ED9C84B1ULL, 0xBEF0CAADE7DD88AAULL, 0x11A3826E961118DCULL, 
            0xD9C3420A9B98CDBCULL, 0xD56FCF26104A1838ULL, 0xBBE0F52CE6A682D2ULL, 0x5694E0CEF56C6D2BULL, 
            0x7F13582802E736A8ULL, 0x45F095081C8421B5ULL, 0x572EF2CA5174CBF2ULL, 0x5B392BB70FDD34D2ULL, 
            0x8AF7D7D095A53CFCULL, 0xEDE02B9573270C5EULL, 0xBD91838F4696E355ULL, 0x69633A7964E12655ULL
        },
        {
            0x638112EAB8D0C0ADULL, 0xC58C4B0F24330FD0ULL, 0xB1DF5FF854F4CFDBULL, 0xD83A3473F5BF6F79ULL, 
            0xF27B7FE4D1D84997ULL, 0x1956E93861554574ULL, 0x14D5077916B642F6ULL, 0xB1EB033A15A67FDFULL, 
            0x8F994299A7BA5A07ULL, 0x116568BF5C37247CULL, 0x5268BB239A872D11ULL, 0x09DB21CA95CA530FULL, 
            0xA75A885BC0F5A263ULL, 0x0504297EE9CB0ECFULL, 0xC1D3CDC4F5F11C1BULL, 0x88764A3B1BFD0FE5ULL, 
            0x5BFC41DC8C01D2CEULL, 0x52C3346355929F63ULL, 0xF56587CD5C9B4CE1ULL, 0x19C9C6821F650DADULL, 
            0x8458025B7D56E821ULL, 0xF5CC4D5D9400FEBDULL, 0xD6D032A7F8D242BDULL, 0x3FF7AC4941F6B612ULL, 
            0x0AB93EEA4801869BULL, 0x3C4293CB1150717CULL, 0x5D3FE7AD186C9BFFULL, 0xDF5EA62F54689E5DULL, 
            0x719612266C582401ULL, 0xDDAAE4AC980AAF0AULL, 0xE983706E19FBF626ULL, 0x20443BE0E049430DULL
        }
    },
    {
        {
            0xF1E430F8A414316DULL, 0x91EAA37D602A3750ULL, 0xC596C449CADD42A9ULL, 0x4745D984ACD1726DULL, 
            0x96060183542D6F45ULL, 0x92227A85C6354A36ULL, 0x25F113DEC1EE6AD3ULL, 0x647DFA26E1807C6EULL, 
            0x575C8476C1CEC6ABULL, 0x5494E6093FD1C310ULL, 0x6AF88B2958A1E46BULL, 0x076254CFA8B097CFULL, 
            0xD7CDA7E2CCA002B8ULL, 0x9FCAE23B53E12BBCULL, 0x038696D6B6FF16EEULL, 0x804DEBEE893B04A1ULL, 
            0x25404147E450B658ULL, 0x0F6CBD3866CE0FB4ULL, 0x2DE0EB5BAFEE05D7ULL, 0x3BB4ED7C9C2DF53FULL, 
            0xA41E34856CC1B94DULL, 0xD362504CACEA9830ULL, 0x97C546EBDBA81131ULL, 0x9B68C7D42D2FD0AAULL, 
            0x4520322E5029510EULL, 0x90D8144F5B09E04DULL, 0xB0FBE97E961425C0ULL, 0x4C565B2F41E263CFULL, 
            0x1D9933901CD664BAULL, 0x9DBE09C5A9B3288AULL, 0x2BA870A4F587434BULL, 0x24E9885D975C7F2BULL
        },
        {
            0x505955A856F3BF1AULL, 0xC78156A8957C40A4ULL, 0x723D1E36D651D0B9ULL, 0x658BB59612DC8AB2ULL, 
            0x773FDFF088491BEDULL, 0x2FAB14184A4C7EFCULL, 0x92F50970BB437277ULL, 0x761B4679EF48C087ULL, 
            0x2CD83CA89116C5B2ULL, 0xF82A2354792DBA47ULL, 0xB7302231D4C6C630ULL, 0x29ABB2E02BBEF7E0ULL, 
            0xE5DB5E57737D36FEULL, 0x51924197F2D5DA25ULL, 0xF82D51C08D125ECAULL, 0x363C55571CD62A48ULL, 
            0x2070ACF7EDF9906DULL, 0x6C735061B3E4F756ULL, 0x579E7DE07DB72596ULL, 0xD586875E650302D4ULL, 
            0x23EE48C1585EEA58ULL, 0x4A3F670CFFE3D631ULL, 0x67325880FB2550E5ULL, 0xE7C82DEE6566BBE9ULL, 
            0x001E43C098845A5DULL, 0xF4D279B24C1158BCULL, 0x2FE18C2A3ECEEC40ULL, 0x8752373B23FE20A4ULL, 
            0xFDD7518675796723ULL, 0x50CDE8E495BB0E67ULL, 0xCAEA960712DB9473ULL, 0x41899E5BD7A8D4E5ULL
        },
        {
            0x9E62BE999AEC243CULL, 0x669AF63A5A4D2294ULL, 0x66813CAFF3303A61ULL, 0x739106BBBB536E15ULL, 
            0x98F32BAA03332E21ULL, 0x248A3E9CDDE8D81EULL, 0xA36FE6BDA1F9EFF8ULL, 0x65A27D35CAF6959FULL, 
            0x0B881BDEEBE3A2ECULL, 0x9AC9D7DE7A8527AFULL, 0xE44D9B8DB803EB6BULL, 0x06FD97D26496572BULL, 
            0xF71BA17775B0CEEAULL, 0x746B79D37FA84796ULL, 0x9699798B015D8D66ULL, 0x588EFE68718044BBULL, 
            0xC43FAC3ADD0F7150ULL, 0x3CAD6DABE3CAFB70ULL, 0xC649AD80D625602EULL, 0x83B7ABA5DB9DE46BULL, 
            0xE29136348B1196BEULL, 0x756A5885E8083941ULL, 0x19AC16A9E7C2B2E3ULL, 0x174B1C14C2F110BEULL, 
            0x4A7512C7378686B9ULL, 0x9D7913BE10E2D300ULL, 0x2F9429722F12CAE3ULL, 0x7140E1A156A985D9ULL, 
            0x25A94AB6227BE894ULL, 0x2D6AA8F5BBE330E8ULL, 0x6F71BAA4CBC0A296ULL, 0xB023C2CAC2BFB0DDULL
        },
        {
            0x075C6BDFB2D88F42ULL, 0x210C789258B238C5ULL, 0x4D4724347EB90E23ULL, 0x657E9A3EDA523310ULL, 
            0x84ACE8ADF661D6F9ULL, 0x4AFDC7D70B6682A6ULL, 0x1AC33CBCDB8997BBULL, 0xAC9F232C9D622AEEULL, 
            0xB4C8C210BE3A861DULL, 0x355329153AB5B8B1ULL, 0x32A0C5AF9D230382ULL, 0xEAB0F6D471AE861FULL, 
            0x45FF76403F8382E9ULL, 0x5CF2252D5656F0B0ULL, 0xCCCB5CEA77ED632CULL, 0xE6EFB44AB126B920ULL, 
            0xC3039B45DE3CDB51ULL, 0x7BAD7B2E95187CE5ULL, 0xA598E6B9190600C8ULL, 0x3A17CABC76CB6517ULL, 
            0x40C6511B97C89B32ULL, 0xD9D6D8058262BB3CULL, 0x37ED7558FD1D5159ULL, 0x4614604D5CFD4BBAULL, 
            0xBFC2E1E3C78F2958ULL, 0x66DC088823A1A581ULL, 0x46670673B707B7EBULL, 0x7BB93C6BFC5CE98BULL, 
            0x2643DDB1603AFF8DULL, 0x59D44B5D80B03681ULL, 0xE8CF7ADB946321E3ULL, 0x0E8C95571368A230ULL
        },
        {
            0x77A366A524328465ULL, 0xD7A06DC6ABD7FF50ULL, 0x1E767DBF5E70F8BDULL, 0x42DEB6215293D296ULL, 
            0x1B0D8FF4759C09CEULL, 0x56F976EC6856B16FULL, 0xED3107B986FD0788ULL, 0x93A2E02DA6CE7932ULL, 
            0x27376D2641D6E925ULL, 0xA2FCCFA43C47C0B8ULL, 0xFB22F07B765EF283ULL, 0x8BE71CBAF7112417ULL, 
            0x779377FE520DEC49ULL, 0xE947CC7B4CF1C6E7ULL, 0xE60B64C37625C2B7ULL, 0x0AAEE8EFB32AF35BULL, 
            0x8A7E8B730FC9F1DEULL, 0x078B109EDC8631D0ULL, 0xF81EE6F0F73631F2ULL, 0x009CD5C96AE88495ULL, 
            0xD9BBFCFFE726ECAEULL, 0x380A24A53FE3D030ULL, 0x46608886DAA06BDBULL, 0xBD8B71BFB2A93715ULL, 
            0x5AABDDF8ACFA2642ULL, 0xEF5482DBAC5D5D44ULL, 0x215003D73CCAADB4ULL, 0x8EDA105F5031F4BCULL, 
            0x0BEB8818B4C4238BULL, 0xC883FEED3EC862B5ULL, 0x7B08538DD148E520ULL, 0xE662F178BCE0BE69ULL
        },
        {
            0x184D7DD88C0198EEULL, 0x452752FB8791E7B1ULL, 0xE1A954E3827C4E23ULL, 0xE39598471E19968AULL, 
            0x15E2DB6A398C8880ULL, 0xF67C8F6863731FBAULL, 0xD3E4DE8BED4C9898ULL, 0xC6FFC3C7ECB8CC06ULL, 
            0x2E71D5767FB394FEULL, 0x8C00F4F137D3642EULL, 0x8D52A74276F75816ULL, 0x2F9AD32E14860BC6ULL, 
            0x4002F9B964A52779ULL, 0xF33A369A00CC99FEULL, 0x627498593E02F3F5ULL, 0x010D78265769547FULL, 
            0xCF5EC93C01BE20CDULL, 0xD37B900EDECFBC3CULL, 0xBC707DD2D11F36EFULL, 0x30BDA4CCDE0FBCBEULL, 
            0x3CA25423D0EBFBABULL, 0x3E9E8E60A0662419ULL, 0xDEBC24CB285F0BC6ULL, 0x680AC975CCC53C4BULL, 
            0x0F9066ECB39BC554ULL, 0x76087EAC6D2D4099ULL, 0x9919B9739123233BULL, 0x70F5077A59C066ADULL, 
            0xD4B5ED5FB5878998ULL, 0x494CEB1E0D1ED6E3ULL, 0xEE5261D36E5A77AFULL, 0xC41BDA56076C04E3ULL
        }
    },
    {
        {
            0x4E49E99E447C78EBULL, 0xFB9295BCCC723126ULL, 0xA43DEA6B19EFA068ULL, 0xC87E9017AF338749ULL, 
            0x66F1FDA9EE82B080ULL, 0x63B9735B205B89D3ULL, 0xC90C366BDBA25031ULL, 0x0AB6EE8F9E56F6EBULL, 
            0xB2B38B2292F3496FULL, 0x0480B7E5A49D576AULL, 0x619EECC70B111D53ULL, 0xD5230B495A396C35ULL, 
            0x7FA72B2375AFCF90ULL, 0xDE8C060184326658ULL, 0x926FA8AD16963873ULL, 0x914826FB9A6A7CA1ULL, 
            0xB77EBA57FEF5AA53ULL, 0x25468DB6D4A89DADULL, 0xF34B6E4E9629DC95ULL, 0x241D68D41FD175BDULL, 
            0x48047CBF299C548AULL, 0x159B90144B7BC68EULL, 0x8CD35F51D1DFDFA5ULL, 0xCA380174F33BD58CULL, 
            0x2AC8505E4D4076BEULL, 0xA0FD611FA95F8E2BULL, 0x804F48AD80C87618ULL, 0x8DE436042F8CC310ULL, 
            0xE76608EF2CAE636CULL, 0xF2A9997027FD4493ULL, 0x1C7F8B53771ABD3EULL, 0x67DDC4CB6533BF0BULL
        },
        {
            0x778D4D4E87E40469ULL, 0xFD4E8AB777C450B6ULL, 0x856744EBDB5538EBULL, 0x29C4FF0CDD5734CDULL, 
            0x9AB230B71EC6F3A2ULL, 0x17AD35A218276042ULL, 0x4E2A63930C65EAEDULL, 0xA66C95AA346BB3C6ULL, 
            0xDAD1EE9D58539602ULL, 0x716C88258E1AB9FBULL, 0xDECF61F5907928A7ULL, 0x59A1247A74391578ULL, 
            0xA62CADDD725A20E2ULL, 0x6B8437FD851DB4CAULL, 0xEE4FB15A0B206EAAULL, 0x3CF4C05463E0E3FBULL, 
            0xDE08EF899A9C146CULL, 0x37A1978FFFD9F129ULL, 0xFAB7B377202710E3ULL, 0x160A4F627B914427ULL, 
            0x3277D095207641D4ULL, 0x980671F04341D964ULL, 0x5AB516AC79FE38BDULL, 0x805F8B317F42DFE1ULL, 
            0x529D73CC0926FE28ULL, 0x0354ADBF2BDD0D5CULL, 0x7806D89395CE5664ULL, 0x18AE209EB18591B6ULL, 
            0x27F01A2170BA1D2EULL, 0x9027571F8017DEECULL, 0x1A6F31F5755036D6ULL, 0xF3E57C2AD31EACA2ULL
        },
        {
            0x5E7563CC6E52F385ULL, 0x4C5E70F20E1AD20BULL, 0x4EF6C3547C665EDFULL, 0x7ED31C3105DAE19BULL, 
            0xA6313E6359A91692ULL, 0x981472B4D3A6D7D4ULL, 0x338CE94E4DDF636DULL, 0x61BD7288FE5EC833ULL, 
            0xC5D4162DDADFB97CULL, 0x666ED439093AEBFFULL, 0x1233AF8560CD44A8ULL, 0x9B54288608551D79ULL, 
            0xF7683652F2760A5EULL, 0x61C9851BEA41EC50ULL, 0x50BF92FB9C6D7459ULL, 0x2D38B8C1DF2B5320ULL, 
            0x48053DACAE9A0B5CULL, 0x9450389B943FF354ULL, 0xD80620C515058BA6ULL, 0x6B0FA23517C85509ULL, 
            0x0D08CE16D410C396ULL, 0x374DE747017C550EULL, 0xEEE18AA5D5960EF2ULL, 0xDAA8F754A85C16BAULL, 
            0xF64C536FEC4617A3ULL, 0xE16046400ECD8B53ULL, 0xC9AD4319E0F6E999ULL, 0x79D482FD184B6445ULL, 
            0x7EEF70AAC95A9A60ULL, 0x0737F01F346A25C7ULL, 0x9742C6B18E767008ULL, 0x3E06F785E99E993CULL
        },
        {
            0xB642C3C66D483863ULL, 0x954DDB3407285266ULL, 0xBE6D5ECD78598037ULL, 0x2362CEE4F871C280ULL, 
            0x5B763017C37AB58AULL, 0x9FD6FB975F1AA908ULL, 0x888B5DE108093DB3ULL, 0x64697C1827DFFDC7ULL, 
            0x1FF14F3D6582D30EULL, 0x0DAE46EBEDA26007ULL, 0x0A17F5E9ED6EBBCDULL, 0xB8DF47798FD21D99ULL, 
            0xB00E926E6714DBEEULL, 0xF71BDC4F4E3C5B94ULL, 0x5991B5DF7C869DBCULL, 0xB24C06635F025BC4ULL, 
            0x57287D3F9932CA84ULL, 0xE17AEBD502B43672ULL, 0xFDF31D215E68D5D9ULL, 0x3F693D82D5DE7A03ULL, 
            0x2AB33ABDF34C3EC0ULL, 0xB675456CE38C871EULL, 0x0361B9D9966E33F0ULL, 0xD6A236F3E7B28A56ULL, 
            0xD403608640A780A3ULL, 0xC39025E27B31B04FULL, 0x5AD02BE28D67CACCULL, 0xF6DBA0DD42052D6BULL, 
            0x1E92F4C3454348BBULL, 0x66CE8732C2C04386ULL, 0x34D8955484054FDCULL, 0x314AB44800C514ABULL
        },
        {
            0x00E463295505B103ULL, 0x3945CE9AEBE4D3CEULL, 0x9A907EE2DB87CA31ULL, 0xED157985208EC5BDULL, 
            0x4B71707A78AEF665ULL, 0x327C1D7C19D85A9CULL, 0xAEA497A7C1D4FFAFULL, 0x35912B792000A118ULL, 
            0x2E51AC74F1E357FCULL, 0x28AFF863C2A48FF4ULL, 0x198B3823F3F4ADD8ULL, 0x2FDD06CD2417937FULL, 
            0xA71626043D0C3728ULL, 0x6BA5F406E43BF8E4ULL, 0xD1B1B2663A2E4BF9ULL, 0x6008F6378DCC1BE9ULL, 
            0xAE4EC143B66C2DEAULL, 0xDFF35B3D2CD4A004ULL, 0x729E180A047E3214ULL, 0xB663953C3E2257D7ULL, 
            0x099CCE75983CB8CEULL, 0x0E1FCAE98F374FDFULL, 0x4F958171BFF8CBA4ULL, 0x899F5576A4A04325ULL, 
            0xCBB8DADCE1F4DB88ULL, 0x9DCC0ACD0129E30CULL, 0xEFEECF2C9E002EC2ULL, 0x8D043E51B003EE7EULL, 
            0x6934A409EECB34CEULL, 0x669E2D11D3EF8C1AULL, 0x19FE7D7001E3C5EDULL, 0xF08AA7FF5AF0F9D0ULL
        },
        {
            0xA1EF01475A3814CBULL, 0x1C14BBAB6357554DULL, 0x67DFEDE1DAD63405ULL, 0x793DA66BE975B580ULL, 
            0x4BC7F7F81FA9BB23ULL, 0x430432B8D1B6ABB4ULL, 0xA1B765A3FD22949BULL, 0x8E944BE928C43A0EULL, 
            0xA6D3E12087C3E79AULL, 0xB250F4E123381272ULL, 0xE03846E2E062B5A2ULL, 0xE69A6CCB438BD26BULL, 
            0xFC916A60EB13B94FULL, 0xE492394ACFF9DD02ULL, 0xFA2E129C1B003147ULL, 0xD2C423DCBFE8A2C2ULL, 
            0xC2D08A2A983D148BULL, 0x35F2635E4CD586DEULL, 0xA2C33B7055DE9A13ULL, 0xD69099325465553DULL, 
            0xE095077B0FB204DDULL, 0xAD12B9EB1CF96975ULL, 0x4E639BB681DE072DULL, 0xF80B6ADCB2B9F6EBULL, 
            0xA67B2A1C02FE6470ULL, 0x013383BCB66C68A9ULL, 0x05687FAFE8C5A2E6ULL, 0x7F39EAE3C6F412BBULL, 
            0xD5F183CF3C87C47EULL, 0x07D0A857634F53B0ULL, 0x768AF43A0F6685FCULL, 0xE51B0B38569D9F69ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseCConstants = {
    0xBB5D3CB39A381B9DULL,
    0x665E2CA845E2089FULL,
    0x2A64DC55215E7AD6ULL,
    0xBB5D3CB39A381B9DULL,
    0x665E2CA845E2089FULL,
    0x2A64DC55215E7AD6ULL,
    0x6415F713E9DD7C0CULL,
    0x7F8009A8FF981888ULL,
    0xE2,
    0x25,
    0x0B,
    0xAF,
    0x3D,
    0x3E,
    0x9F,
    0x8A
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseDSalts = {
    {
        {
            0xA8FC602A095A7F50ULL, 0x7A44CF638F10FF35ULL, 0xC778AA8BDD58499CULL, 0xFB47B4ACB7E173B2ULL, 
            0x0EAB87A5D266F542ULL, 0xC9F075E91AF9A41EULL, 0x969BD3DBC1C21E28ULL, 0xD98909859498B6C3ULL, 
            0xA47AA4661820DCB5ULL, 0x793EA7429B485072ULL, 0x6FEE03EBEF16706CULL, 0x89C40228B0892343ULL, 
            0xDD7A0FD27C650DB5ULL, 0xC9147BA0EC6BAB44ULL, 0xDB16C88E7E264497ULL, 0xF5EA6C200CC80276ULL, 
            0x8B8AAF45BE918F25ULL, 0x92187C37D927D464ULL, 0xD044EDD8BD1C4357ULL, 0x32E401FA66518AB0ULL, 
            0x100DF9B70976B5CCULL, 0x6BB3F4D236731F22ULL, 0x77F3B4C5934BBC9AULL, 0xC7208829E4C0CA0AULL, 
            0x7FB3906B30DB0BBFULL, 0xB9867A0404ACDDEAULL, 0x8DB7948AFEE50385ULL, 0xD90278F42C3AE485ULL, 
            0x9C47B55E94D3404DULL, 0x5D1E5C69C7E610EDULL, 0xE9AA538EE1E8C0B6ULL, 0x74E0782E948997E0ULL
        },
        {
            0xF048736964D2149DULL, 0x76F9A6EDF28235C9ULL, 0x50A93E70A7F3946CULL, 0x5AEB46BFD94250B0ULL, 
            0x2A309A892725255AULL, 0x90714C48EF14EE49ULL, 0x9A92A2DFEEF619D1ULL, 0x422BAD47D21378F4ULL, 
            0x213416A2AA59D31FULL, 0x7D805F4BED36B569ULL, 0x414DDF771EB58E14ULL, 0xC36854A2218D4B97ULL, 
            0x9397F665CE8CFD46ULL, 0xEEC577D1C3391FF9ULL, 0x298795F69128CCBBULL, 0x7DDDD6406487109BULL, 
            0xCDA9F5D623326F81ULL, 0x07547DB666F68A90ULL, 0x4E2D19445CEC5526ULL, 0xD1B1137685456D99ULL, 
            0x47B9DB1D989913B5ULL, 0xE4C27B9BD1F9CCB9ULL, 0xEC8A86F2EC8D9721ULL, 0xE05A468C3073CABDULL, 
            0x8115DF93DB0C84EEULL, 0x1A803B34D892DEBCULL, 0xEB6180323CEE2123ULL, 0xB1340DFB65FFEB24ULL, 
            0x52DF0F654A751BBEULL, 0x472EF51B401774ABULL, 0x2A7F46201173082BULL, 0x169A1B61D070D502ULL
        },
        {
            0x147E1611B2209972ULL, 0x8C6AEE293B19C6B6ULL, 0xC34FBAF9CAC4569EULL, 0x810B2EEDA464CB35ULL, 
            0x12F9E26D30DAA8F3ULL, 0x7DE9984313014699ULL, 0x8C1768697B3FB109ULL, 0xA6BBFB39F03CCF96ULL, 
            0xEF486ED768FC7C89ULL, 0xC35B417B77FB4F70ULL, 0x56F3374A64FAE278ULL, 0x7BFBE9DF023939FEULL, 
            0x30B5A0CCC727B9C3ULL, 0x1E22C929D1BD7730ULL, 0x78AF8359A27CC216ULL, 0x9A783F1C4A921AD7ULL, 
            0x883F9EC03BD5D020ULL, 0x3CB4D1DFD7457109ULL, 0x0B55AC6926B0B8B5ULL, 0xD9E8C895DAF25F59ULL, 
            0x4FE8181DD15934C0ULL, 0xC12F898CDA8641B9ULL, 0x9B16E66A1EFB0741ULL, 0x486271944BBC2075ULL, 
            0xEE96587BB1CE4F02ULL, 0x6F09907A2F5F1A7CULL, 0x5E140D8E87010E54ULL, 0x56A44190109EDBCAULL, 
            0xC91F5E3E3F944340ULL, 0x8094F968C705681BULL, 0x9222D567433B68FCULL, 0x0772416F270AF5E7ULL
        },
        {
            0xA09C1965AE190824ULL, 0x8EEA21FEFAB5B8A3ULL, 0xDF8E4A9E396EA9EAULL, 0x6825B57FAC6FC7FCULL, 
            0x78E4DB792FC4501BULL, 0x32E1EDB7868C098BULL, 0xAF0FFA4A1694FA0EULL, 0xB2274217EF5A4735ULL, 
            0x41C93A54B2976CD1ULL, 0xBD6155F191FCA2A1ULL, 0x0B4C302AFA968F5CULL, 0x9818BD9D96DF350BULL, 
            0xC9637157164FBF6BULL, 0x4F98D760FBE55AC5ULL, 0xE58C2C0FD47B0A95ULL, 0x6BB1A3D33E174B7BULL, 
            0x266B8D63DC248A81ULL, 0x869EC8A90DD85EC2ULL, 0xADEE681E52E0AF41ULL, 0x56FA3E1E0E2FF4E4ULL, 
            0xE9E65F55A2F4431AULL, 0x9198BE329A33D4AFULL, 0x2978057C3008F296ULL, 0x36BC9B67383CE1C4ULL, 
            0x3C92470157E46688ULL, 0x46921EC3D623E6B8ULL, 0x07DBE720189D1098ULL, 0x576FDF3EA181D0CCULL, 
            0xE4DE85383DADF469ULL, 0xFED9C000A27C992BULL, 0x61541385C4808671ULL, 0xF938ED5EB9E5C10FULL
        },
        {
            0x9599542CFCC9D576ULL, 0x90C1A8B24470AFE2ULL, 0x8C5F4212B84DC06BULL, 0x30025062E7092470ULL, 
            0xE03BAC138E5D1797ULL, 0xC0AC2994EF94FAC9ULL, 0xBF4FDA51FE7AF319ULL, 0x1324C5F6AEDCD524ULL, 
            0x4145DCD84A9CE323ULL, 0x27B4FA18D82643F1ULL, 0x8A9A715FF0102CF9ULL, 0x1DF515BF49C53CE8ULL, 
            0xCA5E53540C0E62CDULL, 0x1E61327AF0E25AC3ULL, 0xE639BD2C28AD064EULL, 0x6E31E56F6269C6AFULL, 
            0x7FB372C055FC0AD7ULL, 0x215399F90CD08FEBULL, 0x53B947A91CBAD5E0ULL, 0x24CA1ED8189CD450ULL, 
            0x4D13341DAB47E0AFULL, 0x778EFAC8D6136038ULL, 0x8147FFF32D39A092ULL, 0xF5E2E8F3DD41F243ULL, 
            0x1FC06CF001DC3301ULL, 0x1AA628EA3599A100ULL, 0xB8B1E24C8E85EAB9ULL, 0xA1A3DBC7623D7AE5ULL, 
            0xC1088FE8FCDB973BULL, 0x688048B67A8377DEULL, 0x8B3D02ECD49D4AA8ULL, 0xDA49BFA652EF6498ULL
        },
        {
            0x93EE1AD9228DF29DULL, 0x665A8EED4A017BF7ULL, 0x706E3B75DA1CEC3EULL, 0xEE5D2F734C709843ULL, 
            0xA36019B51D7109A5ULL, 0x6693F688A867A9C3ULL, 0x07F815CEE17BF7C5ULL, 0x36F86D763B2FA773ULL, 
            0x630169A2A7F59E93ULL, 0x7622C8ABF06995D3ULL, 0xC1EF17A71EEBB9BFULL, 0x9124C31D0CAD645FULL, 
            0xB27EFFE52A87BA97ULL, 0x4B0C293AEFAC8155ULL, 0x73A380008CDF03EDULL, 0xACC72A73F90FC5BBULL, 
            0x96146BE603D7AFA2ULL, 0xFCBAFDB14057DBBDULL, 0xF26905C7B07D1856ULL, 0xDCAC7B7484B70732ULL, 
            0xD81C22432BF979C9ULL, 0x78038D6EA8FF2A82ULL, 0xAD01C148463967FEULL, 0xE0AB92E451CEED6FULL, 
            0xAA2B63A9363E0AA3ULL, 0xCAB59A6F9765A330ULL, 0x7C0E0E5BD57E3059ULL, 0x8F4875E46A3421A7ULL, 
            0xB8587A36B4746160ULL, 0x4C574342D248F155ULL, 0xE6F4668046BFA989ULL, 0x1924740D41E31926ULL
        }
    },
    {
        {
            0x0317BB0906BFA61FULL, 0x64AC9C5EB7B02D75ULL, 0xE5FA74DB63354B79ULL, 0x4BB42D06D0D1AF66ULL, 
            0xE899AA1B82586CFDULL, 0x056DA2477ECE0445ULL, 0xABBC6DCC95A9B015ULL, 0xD5906E6F3FE99D69ULL, 
            0x5C468B30BA6C331AULL, 0x86307B9EB5CFEE22ULL, 0x781FA6A9F4AFC7FEULL, 0x708A6DD6FD7DB0D9ULL, 
            0x0A87EB0F7891BF56ULL, 0x005D181C1A05113FULL, 0xD5B07674BD64F094ULL, 0x19E10E1636AA1DB0ULL, 
            0x123E45B3643335EEULL, 0x2CBB44B7DEC77373ULL, 0x95352C2813C42698ULL, 0x4306AAF2BB5ABC91ULL, 
            0x22E5B415DD1885C3ULL, 0x5EDF099F0ED303D3ULL, 0x0C7780EFBB369577ULL, 0xC0717A970075A306ULL, 
            0xAEC55698CB5613BBULL, 0xEEEB16E0DA55D760ULL, 0xBD1320D06DEE6CB8ULL, 0x3B3F8AB1170C2874ULL, 
            0xBA6545855BC66FA2ULL, 0x86E65D417032631FULL, 0xCD85A4BD1AB4E8D3ULL, 0x752DC930ED1097BEULL
        },
        {
            0x80E0AC6C00283E1EULL, 0xD35196E65B0991AEULL, 0x71521E85F853563DULL, 0x7213A57924DEDF0AULL, 
            0x5D430A2E49BCB015ULL, 0x1054373CB8ED3AA8ULL, 0xA8504388F0ACE860ULL, 0x8FFD8F87D3B3CC7FULL, 
            0xBF8026A73971977BULL, 0xA005B6E0A51C8A42ULL, 0x0B1C2F7E6632768EULL, 0x5E8CCD7722DA8F03ULL, 
            0x92BD2D941EE99AF5ULL, 0xDA881E7BCC2F0375ULL, 0x75208A6DBE5D78C6ULL, 0x5BE04C16BC288457ULL, 
            0xF9893157DE1F1F7AULL, 0x5718C8A33B50A298ULL, 0x02138F5A3C4CEF60ULL, 0x520CECD21F686E46ULL, 
            0x9F54374A79F5EC76ULL, 0xA3C1A33F3D23554EULL, 0x807E90EA05956074ULL, 0xE17F35F22F795C3DULL, 
            0x8BB2CABD99C9A8B4ULL, 0xB65D3FAFE2CC4735ULL, 0x66251D58BDEA56B9ULL, 0xE826C73B668185D6ULL, 
            0x8A6C524AC06B0E88ULL, 0xDB45B35817532D14ULL, 0xD334EA4E77DBAA82ULL, 0xE81A7E1A113AE5C2ULL
        },
        {
            0xF2044A570B858464ULL, 0x257E79F2A5BDC484ULL, 0x93038CAA6D3905CFULL, 0x3EB7F42DAA645CDAULL, 
            0xF1BB8D83E8EC31B4ULL, 0xA76A9ACDCAC09894ULL, 0x712FD1563B729BD8ULL, 0x9891AA76B607F892ULL, 
            0x7087D21B90F238C4ULL, 0x420A7B08E062EC08ULL, 0xB31D7536356CF1B6ULL, 0x4C7D9C192A7CDB67ULL, 
            0xA4C29DDD265820B1ULL, 0x449CF7D977D12D86ULL, 0x91B8A494CC241159ULL, 0x3C63D44D8A6DFE22ULL, 
            0xCD159DB773B86FB3ULL, 0x4AD86DBD6C0BD10EULL, 0xF98C617639134BEFULL, 0xFFC471AD73C8E5F7ULL, 
            0x989EE6D1BA510008ULL, 0x180C582DBC946DACULL, 0xDC5EB76CAEC21BC8ULL, 0xC7F560769F5089F4ULL, 
            0x42CB0919E8754DD9ULL, 0xB3ACF6E6862F6C0DULL, 0x6F2BCD48E245C66EULL, 0x774F6B940AEFC00AULL, 
            0x0ECA060AF51DD661ULL, 0x5A8F9AA2CB9CA05FULL, 0xAF2F435C7B9A13F6ULL, 0xE4EB95537AEF4E68ULL
        },
        {
            0x1263C2AD42269892ULL, 0x4AF392B8F458C364ULL, 0x81A63BC5C4758343ULL, 0x2F9766667667A310ULL, 
            0x51341A02926BA6A7ULL, 0xB97B28E3E7D5F5ACULL, 0x3E8DF3C884CFFCDBULL, 0xC0F934BB61BD500AULL, 
            0xB6571C20A1291481ULL, 0x95A32676392CAC5CULL, 0x9B174F22201E0743ULL, 0xF169AD0EE5B70C55ULL, 
            0xE79B6CD90F90A63AULL, 0xE56516EB05743763ULL, 0xA238AA9374FB1C9CULL, 0x6D8B8B9EDAE534B4ULL, 
            0xE7EB7C42FDAEFBEEULL, 0xF9936A08B8745B7DULL, 0xA4012684C0D6354BULL, 0xBAF73FFDCCC56D2CULL, 
            0x17649F7810B1F1F3ULL, 0x6BAA0F7C0D5662C8ULL, 0x73B10E087E7469A3ULL, 0x5D027051B58F8341ULL, 
            0x36B6956915C0DA98ULL, 0xE6E24479E3167DD9ULL, 0x6E72FD71055583E0ULL, 0x228D6D9D12821EF0ULL, 
            0x2AC316DA38C7632AULL, 0x63DAF0897EED7D84ULL, 0xCC14771551969E4AULL, 0x69EFD4135CF5D354ULL
        },
        {
            0x28E2DE34BC5D11C7ULL, 0x590FFF992059A31AULL, 0x9CE46EC7500A5965ULL, 0x6CF30BDAD82F13BEULL, 
            0x8AF67D9D2592646FULL, 0x0F3D1B8933B96DFDULL, 0x00C6AEAE26D90628ULL, 0xCBC5058524DD0D6EULL, 
            0x8EDDC4012F524051ULL, 0x91BA75DADD2AD1D6ULL, 0x2D2D2835F1C2EF83ULL, 0x7FA0463271500E36ULL, 
            0xB8419C53133A505FULL, 0xB4D40AB267927F92ULL, 0x23C9153CB224D759ULL, 0xEE3AA3ABEEED4FDFULL, 
            0xD80436E2FEF0F464ULL, 0x66BE5FB15AC497D3ULL, 0x64DDD4B2D7CBF62EULL, 0x0F58E578AC244AE8ULL, 
            0x5A09FC50F3F09CB1ULL, 0xC8AF2A78019075B7ULL, 0xF84908280BE78489ULL, 0xC23B6B781E7BA1B7ULL, 
            0x2F2EFA1DDF6E41B8ULL, 0x7CD7D84FD8698F4DULL, 0x5A7AB04EF54E039DULL, 0xD5041D674FDAB2A6ULL, 
            0x74055AAA07ECE235ULL, 0x4ED001F2084195AAULL, 0xF7605172466E18DBULL, 0x2BF73C3D47D6A0B4ULL
        },
        {
            0xA172021648C9A0F2ULL, 0xA76CDDF2C2557D5DULL, 0x20070CA562E54AA4ULL, 0xD4B1B60DA33AAECFULL, 
            0x7ED4E9D0A5E62B2DULL, 0x5983681F658C5E74ULL, 0x3389F0E53CB2FD1DULL, 0x9091869730406AC6ULL, 
            0x3D28AD2D8F55E641ULL, 0x830CB26456BE8E1FULL, 0x340E6D68D0366C03ULL, 0x26AFE3277B21DAB7ULL, 
            0x9246B34B3DC63E7AULL, 0x2AFCAF01ECC5C881ULL, 0x154C6AF22043894DULL, 0x0B481ED772DA9CBDULL, 
            0x37AF23CC3DEC95E1ULL, 0xE6287DFA17785D3BULL, 0x1044A87113607E00ULL, 0xAB49321FCE22C07FULL, 
            0xD856BDE0AFD43273ULL, 0xFFD90BA5C16ABD7AULL, 0xF15490EC6FCF95DCULL, 0x7D2DCE7D6D0E358BULL, 
            0x979F3924BB543DC5ULL, 0xD585A58537EC787FULL, 0xB1CD245866DA8983ULL, 0x35875F1C9232ABC9ULL, 
            0x82D5A520049CB9F8ULL, 0x2EA95F6B5B8A1F5BULL, 0x4B0A7875E48D0BDFULL, 0xA893E430AEF7F267ULL
        }
    },
    {
        {
            0x4A1FCF0E03AF3674ULL, 0x4725AE9EA331CE9EULL, 0x0557328CAE583761ULL, 0x735F384C6E01EFA6ULL, 
            0x086571A22855EDFFULL, 0x82CB175F963E76CDULL, 0x826834AB070F5CF0ULL, 0x74F1EFC33FB42649ULL, 
            0xC45D9B517B08BCFDULL, 0x10B5A97F963637BCULL, 0xE129A74EA125C238ULL, 0x7212C346DFFF3C5BULL, 
            0x3EC3D54398E9396CULL, 0xA0CDCB189B33A86EULL, 0x8A8E2E4D250DA593ULL, 0x3D6D5F67037657D8ULL, 
            0xEBEACB5AC3D6182AULL, 0x8373B423EB7E85B5ULL, 0xD9310DBA9AC46538ULL, 0xD54F0E91EB17C831ULL, 
            0xE8B9C50D86A3989EULL, 0x739D9145669D5358ULL, 0x4E16ED8116D62D89ULL, 0xF3EF66C4561EAEDAULL, 
            0x0C24CC11E54A90F5ULL, 0xDEF0E7B06E1523C7ULL, 0x40D0CC3FD8A01D69ULL, 0x94BFBC3BC60B233EULL, 
            0x6F95943EA3E40ACDULL, 0x9EED779CE4BF0058ULL, 0x98FF088B7A642C4BULL, 0x265AA6BCB9BE25BBULL
        },
        {
            0x27AF77269292BCC1ULL, 0xA9B9485621DBC557ULL, 0x86BD5D9C2801E4EDULL, 0xEBB69BEA55936EE7ULL, 
            0xAB5676E2B98EDCB6ULL, 0x348D9BA65BB9747EULL, 0x61061120F4517C1EULL, 0xFABFFE0426C52D06ULL, 
            0x011D0BDFB1FB26FDULL, 0x7C0094A6B6FC20CBULL, 0x87245835946E3074ULL, 0xA358E2E9D1AFF749ULL, 
            0xFF08D8EC36E1A696ULL, 0x721FB41A5A16332FULL, 0x5EECA303144277A4ULL, 0x8F47CD144609B931ULL, 
            0x97CCAB4415897117ULL, 0x6A43216C353F27FCULL, 0xD53C478A0E589025ULL, 0x7F5A4737DF3CBDF8ULL, 
            0xDD8EC9B57012879EULL, 0x08027B1901A76E7CULL, 0xF5BBD72323EB5670ULL, 0x698716866770F1FAULL, 
            0xBC278E271F114AD5ULL, 0x7114615187C44820ULL, 0xE05AAED314411D86ULL, 0x80EEAC0D4CAF386FULL, 
            0xDA6E886FEB3B2880ULL, 0x10E0DCC3E3413CD3ULL, 0x0BEE541FEFA59A4CULL, 0xDC4827F54C74B20EULL
        },
        {
            0xEC96C1A0270BCFB6ULL, 0xACA6CF840E3C7884ULL, 0x4198140B609E653FULL, 0x0571C3EEF09BD01BULL, 
            0xC3548F873D058B15ULL, 0x2F077B262EF3D6D8ULL, 0xC100E1BD75F931C8ULL, 0x184B8A37DE28C65CULL, 
            0x948599B2E7055DD1ULL, 0x1028A6627B80CA69ULL, 0xE52151278041E2FAULL, 0x3DA5FAB8B0B5D63AULL, 
            0x01C0469132C0015CULL, 0xE254E90BD84087DBULL, 0xBD7303EF9B2D231AULL, 0x1CBF6167ABFB2D1AULL, 
            0x63352797183C6954ULL, 0x6AEAAC838DA116B4ULL, 0xBD509DCC6EFFC749ULL, 0x903D8D3907DC242FULL, 
            0xE6943B6067DD0AA8ULL, 0xEADB4A69C56ADD8AULL, 0x51B8E9B52A368D40ULL, 0x35E31F6EB56543F7ULL, 
            0xCA2E5C25C7C3FD4FULL, 0x5908391DE7D72588ULL, 0x05178F5D9975311CULL, 0x725EDAC9DAA0F5D3ULL, 
            0x4EB308147EAEB5BDULL, 0x50BB6964BDB47794ULL, 0x08DF03817AB9B283ULL, 0x5E417373279FD99DULL
        },
        {
            0x2B506F0FC2AED543ULL, 0x6259AB6FCFB64F6CULL, 0x7EB767DEE6D40D85ULL, 0xA3DE22BCB7ABD355ULL, 
            0x1A218FEFE0BF40D9ULL, 0x3BD565EEF85C03F7ULL, 0x3D6C685766E8ACC3ULL, 0xE993D3B39EBB315CULL, 
            0x151637F89DB7816EULL, 0x8D8CE6711C9A0C30ULL, 0xF4032F46FD57E515ULL, 0x509E406DC9659970ULL, 
            0x5E879C79D74EC42BULL, 0xA19709C8F0385B0FULL, 0xF74B10C5BB6389A8ULL, 0xF138E81879CCE8C1ULL, 
            0x1287196EF935EA49ULL, 0x4FB557EE444D586DULL, 0xEA7E27948C18DA33ULL, 0xBBF4A15DC80B5586ULL, 
            0x667DFFE94F148078ULL, 0x48BE23AE110D8ECFULL, 0xFFF3A64A161218BFULL, 0xFE22606887D9DB39ULL, 
            0x82FA224C52AA5E70ULL, 0x5BF023362E573562ULL, 0x2938D34E248BCFCBULL, 0xFC710964973175C3ULL, 
            0x1B06E473F877E877ULL, 0x21FBC9F132E21AC2ULL, 0xFC90D41EFB48D18BULL, 0xD7FFC4498617EAE9ULL
        },
        {
            0xCADCF0AD473C3FDFULL, 0x2F260E0B18D8C33BULL, 0x694A62B0611DA00BULL, 0x58CF12000F446321ULL, 
            0xF241829A8976940DULL, 0x9EF2D145A2039076ULL, 0xB7C6A7A6DD33D3C1ULL, 0x0DC4A2CF5CFE2257ULL, 
            0x8B3294F1E73965C1ULL, 0xBC249C800719D1E5ULL, 0x86BF142D00BF4980ULL, 0xF80D73F3BD2FFD40ULL, 
            0xF44C855AA76DFFB8ULL, 0x3C33333813E5C8C0ULL, 0x1FAFB59BD2A17970ULL, 0xBE96718633311F9FULL, 
            0xFF1210E7FFAA978DULL, 0x689A8E02AFBB1DECULL, 0x537AB207670F6B71ULL, 0xD577D0E3594EC6A4ULL, 
            0x02A217E1D5C6D332ULL, 0xCF80814EE3E4221FULL, 0xFA7F9A832CAC8163ULL, 0x5BDD68AADF491924ULL, 
            0x035DFE22AB3B6F0FULL, 0x8058CD3A29BAE098ULL, 0x3E573A7961D96C45ULL, 0xAA78A619E89F242FULL, 
            0xA588F0791420D650ULL, 0x111670E15540E00BULL, 0x931FD22D81FD44F1ULL, 0x3EC08AD488E14DF0ULL
        },
        {
            0xDA5146492DC8C56EULL, 0x3827ED32296B45A2ULL, 0x8E2D67021208AE14ULL, 0x4DBA37E9E6C94946ULL, 
            0xFE727BF5BE6F8340ULL, 0x75CA356F835164B0ULL, 0xCC76D73F010AE7FEULL, 0x0133AF866DDD9B6EULL, 
            0x9FFEF733BC335738ULL, 0x24046F87204E420FULL, 0xDF7BAE4D7EB668C6ULL, 0x6DE2C4EB069B3CACULL, 
            0x2A20CA184C514321ULL, 0x80821FAA4203AB78ULL, 0xF4A516F4888977C2ULL, 0x79AC525008674710ULL, 
            0xE418DFF23084F6A4ULL, 0x0831936046248238ULL, 0x64C2D7FA959AB521ULL, 0xF39A46A74F5C87A1ULL, 
            0x7E57AF3402C65AFEULL, 0x5C7F1A5F059D4768ULL, 0xA9167DC7D7871824ULL, 0x21CABC6611DC41E6ULL, 
            0x73EBD82376CD45F3ULL, 0xDAF745AB894E9ECAULL, 0x1F00EBBA4CC336B3ULL, 0xFC36C48A82DF8D0DULL, 
            0x3153243C8BA9C1A4ULL, 0x746446C9E479C965ULL, 0x8D55327F97367F33ULL, 0x4B9E95D185952A63ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseDConstants = {
    0x540C12E355C36016ULL,
    0xAA34DFE2F1ED213CULL,
    0x34C9D90DDC1ACECDULL,
    0x540C12E355C36016ULL,
    0xAA34DFE2F1ED213CULL,
    0x34C9D90DDC1ACECDULL,
    0xAFCAE57F6DB3D933ULL,
    0x650E927A848369C8ULL,
    0x56,
    0x58,
    0x9F,
    0xFC,
    0x32,
    0xA6,
    0x39,
    0x14
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseESalts = {
    {
        {
            0xB964BB9A06572078ULL, 0xCFBE4FDD6B821EDEULL, 0xB5BEA9E817A8BF90ULL, 0x9B49F4F53B4D5C84ULL, 
            0x0F7F3EC8FCFC1A51ULL, 0x41C784912077A43FULL, 0x011A268073645ACDULL, 0x86E9E709939EAB1DULL, 
            0x04CF39C14B3DA7C6ULL, 0xABAE204E2DC5E988ULL, 0xF3960966AB409A1CULL, 0x26DE306D7E0629BDULL, 
            0xE69660BE344F7DD6ULL, 0x12D2CB57CA7B99E4ULL, 0xA830137921A2876EULL, 0x468CE8BDB88E1A92ULL, 
            0x0839E716CE78ED89ULL, 0xECEED45728C77F28ULL, 0x0DF4E1C1173E1CD4ULL, 0xB5587561BF9ACCFDULL, 
            0xF7DA48E3A9D6CA36ULL, 0x14A9C11A6802CFFDULL, 0x75167C49C607B91FULL, 0x899533EE4768E150ULL, 
            0x0035A6307C9695E1ULL, 0x397E701A0B7F78E6ULL, 0x0075F5A4EC5DC376ULL, 0x949655548194588FULL, 
            0x9CF6C9B419DF3AB0ULL, 0x2A89329E97825269ULL, 0x95A634865CF0B1CDULL, 0x2959A5034C8D76E0ULL
        },
        {
            0x36A86F81CD1BCC37ULL, 0xB5D1EF79B28E2575ULL, 0x41C5BF2D1C20542AULL, 0x2FE9172286321898ULL, 
            0x42CC62D79136C9D3ULL, 0x6444EC1AFEA11A4EULL, 0x10BF9B49F13C9F33ULL, 0x1E0A6D0765EA40F3ULL, 
            0x9B94ABC03EF3579FULL, 0xED44D03A9ADFA45FULL, 0xA5228135CEEF98CDULL, 0x47E4524918F86BBFULL, 
            0xA0240704A86C348EULL, 0x4A4DB979E1177B46ULL, 0x5D78AA5D887AC266ULL, 0xDE344C562FA43E2CULL, 
            0x75075BB7BD00EEA2ULL, 0x7C0B4E12C71A677BULL, 0xC927CCDFB3A53988ULL, 0x7B0F026175A6E14FULL, 
            0xAD294F6D234931D8ULL, 0xC2791E74C9CC3D4EULL, 0x0A37CDC03B5BE9B7ULL, 0x4C1EA79E6307F3F9ULL, 
            0x4CA1E3F9CB99CA54ULL, 0x61C46CAC27F35277ULL, 0xB629CE7B829AFDB8ULL, 0x67D194028A2284D1ULL, 
            0x313685209D747B36ULL, 0x2E4829B488DC42B9ULL, 0xF93DE5CAA9D806CEULL, 0x0E2E123A12F4F8AFULL
        },
        {
            0xBE63B9A5B9142C86ULL, 0xC970FC4EB020AEF0ULL, 0x6D00C30F3318737DULL, 0x67CE4AD19B5BC781ULL, 
            0x71D893187F115AF0ULL, 0x2308164786F1C12BULL, 0x0954010BC095E46EULL, 0x912856C3CA56DF03ULL, 
            0xEBC5F642B9501AACULL, 0x07EE01D44D90A522ULL, 0xDB293E1F6BDDB942ULL, 0xF7793392C0D6763DULL, 
            0xAC4436948BD4C340ULL, 0x1E8A0DB091972483ULL, 0x28F276985603E2BAULL, 0x595577D9317AA961ULL, 
            0x8FACC0EEFBFE2010ULL, 0x3B69DD1927660692ULL, 0xFD3BEE40865B0FA7ULL, 0xB941E48811596208ULL, 
            0x5870C8FB2D90EEEDULL, 0xFF56172882A1096EULL, 0x30A9B19C60FB5C6EULL, 0xA28F42AEC113F57BULL, 
            0xAEBE41B392CC7190ULL, 0xA13EFDA55CE5A234ULL, 0xE5FFF5E0CEE2DDDEULL, 0x62E7205D394DE0DCULL, 
            0x9E01BD8E3D78339EULL, 0xEABCE7A90260C991ULL, 0x9898A892623B0DEEULL, 0x30EE212F266E1B91ULL
        },
        {
            0x97FAFC67685F95BCULL, 0x3400B77E7BB7ADD9ULL, 0x9E9E18670BF22D93ULL, 0x108D0DBE7F54A2B1ULL, 
            0x1B6809D72C48FEF9ULL, 0xC7BC5530F5081CDEULL, 0x1E155104EE757DD4ULL, 0x7DC3ABC781FE4E61ULL, 
            0x5A80F5C5DBF23E29ULL, 0x2CDBCC6911B97CBDULL, 0xBE3F731583B35C28ULL, 0x2910FB4836B6D749ULL, 
            0xB60AAC29833EA45BULL, 0x517BC05AA181F094ULL, 0xBB7F6132F0E86EFCULL, 0x262AB393A46C3B20ULL, 
            0x74FFD6EC79FD89C4ULL, 0xD778D4E97B744734ULL, 0x53F77EE60A1130ADULL, 0xC8FB849AA0EACAF5ULL, 
            0xCF25103A69BE3B83ULL, 0xA9D9FC7E91FEB31CULL, 0x458EDCC5364F6670ULL, 0x034FE33C04822701ULL, 
            0x94ECDAC554844A65ULL, 0x0A7B76F7BF760097ULL, 0xD6FF8CFF20BEFEE1ULL, 0x3D444299383F978DULL, 
            0x7B3481A438266E6CULL, 0x751BD9EEF9FF0C2BULL, 0xD609C83A5664E7FFULL, 0x8584DD7FE81580E1ULL
        },
        {
            0x58BE7A4DC3E2503DULL, 0x5A40159E1BB424FFULL, 0xB36E8423791CA249ULL, 0x2980402C5866719DULL, 
            0x4D5B30FFC4EA07AEULL, 0xC7EAA4DDEE8374F8ULL, 0x6080B4D5BC23F52EULL, 0x3F78D00E2E03D64DULL, 
            0x6983EFEE0B61EFF4ULL, 0x45E6292F50479559ULL, 0x19C17B625B104B37ULL, 0xB399BDA5930B35FAULL, 
            0xF9EC8877D80762F5ULL, 0x0629BFADE2F91AC3ULL, 0x7AF31EE38AF371BFULL, 0x4620E586866EC621ULL, 
            0x6505BA41C55E173AULL, 0x4E21E8F44C77F292ULL, 0x990A504B10B0174AULL, 0x84FE9BD11FFB359DULL, 
            0xAE623F430F4F40A7ULL, 0xB0053CDE548DE4A4ULL, 0x0D6375A2873C727EULL, 0x1294B0D37A044FE1ULL, 
            0x9EE939D19B1CCED5ULL, 0x74C64397722BDB53ULL, 0x691F8709062670AAULL, 0x9EE1903233B88A00ULL, 
            0xB81564483103B388ULL, 0xCECF3483746C12D4ULL, 0x77C905219F22DBCDULL, 0xD928323CFBAB511BULL
        },
        {
            0x9ACDB24EF61CDBBEULL, 0x6C53C18923083723ULL, 0x238563090370461DULL, 0xC61EA2722D9CF74EULL, 
            0x489A1E036BB248C1ULL, 0x033761AAD7C2F6C4ULL, 0x754A5061567EC59EULL, 0x633876B12FCFDD36ULL, 
            0x7F6A9CC25FAFA6F9ULL, 0x61385AB3AC5288E5ULL, 0x23D9971FCE3B7CDFULL, 0x72C4AB7D633FE915ULL, 
            0x405E466690A1B006ULL, 0xC2D3DCBA228509B0ULL, 0x5B3726331E0B5936ULL, 0x9F344CC0804DE4AAULL, 
            0xEACF478D827C186FULL, 0x87D50D148E47352EULL, 0xAA73C66FC1A38AEDULL, 0x913DFD3001615B1BULL, 
            0x8175FEA24743D7FCULL, 0x53BEEEBCA6172F01ULL, 0x44D38535F2BD2D83ULL, 0x300EEA907A90364CULL, 
            0x2CE89CD13EBA96D2ULL, 0xFE58301EBB54B60DULL, 0x81BB24493427EA80ULL, 0xD5C71AA614743211ULL, 
            0xF61B5565F0060C8EULL, 0xCB9794D06D453CF2ULL, 0x868FAD40E8DC46E2ULL, 0x1B47CB021E442DA3ULL
        }
    },
    {
        {
            0x416D142CF28B6236ULL, 0x6C767EBB177DB905ULL, 0x4AC49891F85FD75FULL, 0x9DDE10E4B7049F21ULL, 
            0xD93D31FF43D27C4BULL, 0x80BC8A1071BFD4DFULL, 0x50D7CFD0B772D01FULL, 0xF6F41E7396BF4581ULL, 
            0x86605CBA75F65192ULL, 0xC909420EEB449071ULL, 0xBE3EBCCE7C9A5320ULL, 0x48C654C46DFE83C4ULL, 
            0x98FC5442973EEDB6ULL, 0xE268DAF4AFFAEACBULL, 0x9C49490AA67AC063ULL, 0xAAB532649D7E015CULL, 
            0x5F05F6BDCDEB7729ULL, 0xACE132281F6D85B0ULL, 0x1912E4D30727AF6FULL, 0x10F6AF2542CE1FDBULL, 
            0x701105EFADF873ADULL, 0x7E989F5247F818ABULL, 0xA56E10C2D4D43CADULL, 0xA229CA2673367088ULL, 
            0xA3CF22D4419BB303ULL, 0x48572698A914508BULL, 0x6BC5036153B5E2EAULL, 0xC373340EC6201015ULL, 
            0x142C5C7F66092A14ULL, 0xC98CE91836B373B3ULL, 0x52D0FBDACE0D923DULL, 0xB0207DEABE7D1963ULL
        },
        {
            0x33436D7753F871FCULL, 0xE694FC783CC064C9ULL, 0xF3F953E09898D944ULL, 0xC663E023BF059AC3ULL, 
            0x95D670F9465BE8BDULL, 0x9CC24655E598F95FULL, 0x980C69D44C1FA83AULL, 0xE3FDA23949C30707ULL, 
            0x11DA4135148F29D6ULL, 0x09500978100C9EFDULL, 0xD103866F87286117ULL, 0xDB486D7D91BE1965ULL, 
            0xF961C1C2D44002BFULL, 0x91A0AE1D3B04B309ULL, 0x6839F1AE930A51D8ULL, 0xA16DFFAEDE51171BULL, 
            0xF7D0F35633107C80ULL, 0x11476818EBCD12B5ULL, 0x949949CD2BF7CE90ULL, 0xC930B95C44C3A57FULL, 
            0x2DE120C6EE271BCCULL, 0x3EF2417B7F9C116DULL, 0xCAAD7407F0F9EE6EULL, 0x62B1D6AD59ED1ABBULL, 
            0xFF9625108036F418ULL, 0xC331993F2BD4F3E1ULL, 0xAE12B291BBC0361BULL, 0x1EAEAD9EC7320577ULL, 
            0xDAD5F74303EE6509ULL, 0x2653EF946624A050ULL, 0x40D387A8C11556E0ULL, 0xEE46D3F30F2135CCULL
        },
        {
            0x4AB0EAC2800D1AA8ULL, 0x4E26DF11D25BDF89ULL, 0x75610C31AE6D5C37ULL, 0x5ECF887947B82503ULL, 
            0xDD7174FD4690E488ULL, 0x9A1DDDA77880346EULL, 0xC5FC309C16B376F8ULL, 0x084CC9D2F364F175ULL, 
            0x1210920D86E4FDBDULL, 0x2C7EE77F18177E41ULL, 0xCAA6B0D8162821F2ULL, 0xD2B0F61DD3DABFDBULL, 
            0x7F1267097209D987ULL, 0xE6CAB1A45F838D94ULL, 0x84A90F6A386971A7ULL, 0xD6D8A201BD585C37ULL, 
            0xCF4B1069695202BAULL, 0x42FE7DA09D92F994ULL, 0x2148DABB9A555FE8ULL, 0x1D9234DE5066D353ULL, 
            0x8D6CA5AA226EFBD8ULL, 0x77E74734EE7703D9ULL, 0x4300EEAF5DEA30E6ULL, 0xDA80E18666FF8E18ULL, 
            0x53051D0A5A20B69DULL, 0x4F610D0949B8DC75ULL, 0x06A019314CDD63C0ULL, 0x6162F872AB632D62ULL, 
            0xBB3A91D83CE87636ULL, 0x9864163692641261ULL, 0xAA939E1781F54A1AULL, 0xF62C825213A8055CULL
        },
        {
            0x7CC231A942383DC8ULL, 0xFCD714B1A935F49DULL, 0x80D3DC49C3D8971FULL, 0x9FCB90C10F140205ULL, 
            0x0A44D272699D7EDDULL, 0x62EEA0D557079A5EULL, 0x09C2149BED7F62FCULL, 0x97B4C44C77BDB607ULL, 
            0x682490A6567919F2ULL, 0x89F67724AE8A58AAULL, 0x574D53835EF65CF8ULL, 0xAA6837F2ADD05A48ULL, 
            0x9A602649A23341BAULL, 0xB73371C7634A083CULL, 0x2DFE58AB15C38B3EULL, 0xE0C1DE4A0D0A93B2ULL, 
            0x5810BAEF25211F12ULL, 0x6E559F3404B08CF1ULL, 0x0FB307F43250DA37ULL, 0xEB4ED784B7303E88ULL, 
            0x05F828A46F0B1A3EULL, 0x3AE215D57AF17444ULL, 0x850D902C30B61D20ULL, 0x64841F699FF3D3EEULL, 
            0x5D186639C7280343ULL, 0x2586899659D8412EULL, 0x3F625066CED010BCULL, 0xB9B4502335866811ULL, 
            0xFE1B4B4F8871DA34ULL, 0x194B00E86FC2DB3EULL, 0xDE09F312745D73D8ULL, 0x6C037B95F413458AULL
        },
        {
            0x97CF058474E1A25FULL, 0xC5A727266B2DE0E9ULL, 0x6861CC6CEE8AABB1ULL, 0x6D55B4E575C171E2ULL, 
            0xA916CB617A39C659ULL, 0x313C2B4164B2251DULL, 0x4288CA819FC51E1CULL, 0x26C34CD14282D22AULL, 
            0xE988392BAA9140B3ULL, 0x39E2F25A4DA78213ULL, 0x0339F5C14EEA1C93ULL, 0xB34A679D7010A80EULL, 
            0x8B18892E685675EDULL, 0x362DC8E6BD8ABC7FULL, 0x52E99F8D5BD8352BULL, 0xAF167AFD0D8BAFAAULL, 
            0xF603975D69E73BD4ULL, 0x8E60891923D7E2C4ULL, 0xD0D817F1EFF735A6ULL, 0xB46881B7A90A4755ULL, 
            0x3396AA33A54324D9ULL, 0x87219656CE66419BULL, 0xE06C07F64C920F73ULL, 0x54ED05FF6AB0B273ULL, 
            0x402B9ACB54D8055FULL, 0xB3C73F834AB25823ULL, 0x1AB336075A04C7B7ULL, 0x25B26BC196CD1922ULL, 
            0x5D613F2D534921EEULL, 0xC36D0F6617BB7D27ULL, 0xC51CCE6AC1EFB694ULL, 0x0E09BE8283B5C597ULL
        },
        {
            0x1B3E3185DAEA065AULL, 0x44A5D7F3C3DD4439ULL, 0x6DEE03807AF76A5BULL, 0x0684C38065BF0DCEULL, 
            0x705D95FDD3141BA4ULL, 0x8B230179E75DC6E7ULL, 0x431B97421787C211ULL, 0xE06A268AB08A6F0EULL, 
            0x8398CDAB85242E7AULL, 0x53D14800DAFC5C16ULL, 0x2BC6060AA61B7D38ULL, 0x6B1B19310E71F80CULL, 
            0x7121286385846D91ULL, 0xBC6923B4BD2D4141ULL, 0x6A527AB17E1B8606ULL, 0xC9E01C1BFA65FE77ULL, 
            0x6DD3BBDEE9ABA614ULL, 0x4419CB30006CE505ULL, 0xF3F470FA593878F4ULL, 0x581A4CD59F5C8100ULL, 
            0x6AEC3558BC776441ULL, 0x5BFAFE825105418AULL, 0x31093CB787644B37ULL, 0x111EE24031C68967ULL, 
            0xB56C455C74B37F59ULL, 0x29BF04ED35C069C0ULL, 0xE91D549571625003ULL, 0x3A4C906EB11A38FAULL, 
            0x170FF0ECB75C390AULL, 0xE8799E6DF1C1452BULL, 0x501E2C3CC5FA551CULL, 0x85B9BB7F1342D7F4ULL
        }
    },
    {
        {
            0x99DD368B41388F7BULL, 0xFB7F4C5351F70DB9ULL, 0x11F28EAC59DB8965ULL, 0x97680671FF558D38ULL, 
            0x647DBF1780A1C33FULL, 0x82A99697BBD1413EULL, 0x0ED01EF7362B3AE8ULL, 0x06070909824F3F23ULL, 
            0xC03352D8DD57AC14ULL, 0xDD5F53ECE9A600B6ULL, 0x836057AF00F91A64ULL, 0x7120C7D3ECC33B93ULL, 
            0x4C9048774BC9EA93ULL, 0xF0D84D3BBBEC96F7ULL, 0x597ABE7750C26F4FULL, 0xE428C3EA40B4DCA4ULL, 
            0x790B1850BF5C9FCEULL, 0x175BBE0AF09999ABULL, 0xFE3C7AC7B46F00B2ULL, 0x4AB1B9FFC39E6227ULL, 
            0x8AF9567A13617D26ULL, 0xAEF7FB5076937512ULL, 0xF32B642EBFD18964ULL, 0x65BE1949D5E7A54DULL, 
            0xA64BC6C07E5E7533ULL, 0xE58687490F2AC9FCULL, 0x3184E73548D57310ULL, 0xD6DA6E9AF8C67277ULL, 
            0x09A4F4AECD42805BULL, 0x6DB94B8F014D3FB5ULL, 0x848B59526C49B6C6ULL, 0x9A00E4823A4A0A69ULL
        },
        {
            0xE27FAE7B1AF2962BULL, 0xE6EEEBB81330A249ULL, 0xEAD67EFD1BEE1BF0ULL, 0x63D5C5571DA21967ULL, 
            0x24FF97627C838BBAULL, 0x10AE6BC12B2914CEULL, 0xBD682E40F3C34BB1ULL, 0x3CB2498B372673C8ULL, 
            0x824BB64AB44DA7DEULL, 0x6C78B3DF4D9DED21ULL, 0xFC0571280048D2C3ULL, 0xBDDA56D0845FD5E7ULL, 
            0x47EA2E1986118C23ULL, 0x31D65580A4E1583BULL, 0x473CEF77191ED39CULL, 0x319F0294B60923B8ULL, 
            0xD61E2F24454A528AULL, 0x803E9A1F94C5F344ULL, 0xA96BD30150C08D25ULL, 0x878BD8E27E2940ABULL, 
            0x5CA1D90104BA21F8ULL, 0x53D8CD20D852E8A2ULL, 0x72C416E1FFF2C9E7ULL, 0x7011A4DEBE2E451EULL, 
            0xEE3E4B64767D488DULL, 0x0BE14FAEFC3A0410ULL, 0xC96871D0C6492C68ULL, 0xBFCBD688430F802EULL, 
            0x69290DE73F01632FULL, 0x98E091B1AE8CD642ULL, 0x8D44A4B7FC352DE6ULL, 0x61C2EC1BC9483CBDULL
        },
        {
            0xB7D25A4A551E28CBULL, 0x234133279AEDA319ULL, 0x173DE93BEC598B31ULL, 0x970C8774CB58588DULL, 
            0xA6664656155C628BULL, 0xDB1466254DD43CD6ULL, 0xE421069591471F68ULL, 0xA206A8FE9022BB6DULL, 
            0xFEBAEA3DC27175F4ULL, 0xB7D1434B97B1DD8EULL, 0xCC7CC966D69C0724ULL, 0xE07FA2B554288EA4ULL, 
            0x8CC76C9F56627972ULL, 0xB3D5E4B9146F65A0ULL, 0xC5CB9E8763CF75DEULL, 0xE4EC3F896F783C15ULL, 
            0x782309801BF2EB4EULL, 0xF26D6A256061675BULL, 0x28EB3E13F65E6060ULL, 0xBF0EDBAC1463A461ULL, 
            0xAC8F24964D9F6DA0ULL, 0x5458FDCEC1DAA6DFULL, 0xD69D2098ADEE0D8EULL, 0x153055D20F36AD46ULL, 
            0xE7D4187E2D0A708EULL, 0x5D8F34A7B84D07BEULL, 0x6F6B8F7610B489CFULL, 0xB62505023026C0A8ULL, 
            0xF31E4D7365F270A1ULL, 0x30A39E5F8FFE9709ULL, 0xC7F0A608AE45C7DAULL, 0xDF9B66DAE67AE7E0ULL
        },
        {
            0x2488DBBDD0F4C6E8ULL, 0xEE37F5440E810211ULL, 0x601EDBABB08C7049ULL, 0x06BB2D5294A3AEFEULL, 
            0xE88E48DC35C178DBULL, 0xF36E2090599D712EULL, 0x73F5A7744C5386D6ULL, 0x7FAE91A7AA4ECC6DULL, 
            0xC1A2F885DB1B5EEAULL, 0xE86E51E849C3A4E0ULL, 0xF2DD38805C74922EULL, 0x0DB32730B689DBADULL, 
            0x03FA731DB8A46AF6ULL, 0x74E746FABB3EA4CDULL, 0x84DA51C4E0EEA6F9ULL, 0x90FF14E782584281ULL, 
            0x26CED4EA326F3F3EULL, 0x2924E6D13BA8DB6AULL, 0xC3A06C178F5CF7E9ULL, 0xC84E819804B9F3BCULL, 
            0x003F213B2334B7B0ULL, 0xFA7224A50C6DB3BAULL, 0x8A1AF4D7EABF3330ULL, 0x7A581ACE079D73E2ULL, 
            0x454C4448D41FF9DFULL, 0x6822D4FA75B95DE7ULL, 0xB4B8F0F8767DE602ULL, 0x611664EFDB2FFFC0ULL, 
            0xECB7BC3EED2A84AFULL, 0x00B883114C31E921ULL, 0x8A0A7AD31BA97C04ULL, 0x57D36F4B74363811ULL
        },
        {
            0xFB1D92DB88CF8D2AULL, 0x84B5E27F42AE3FEBULL, 0x6B22917C9C31A567ULL, 0xBD267D1FAF78638DULL, 
            0xB2733059806F0EE2ULL, 0x8C453B32CAFBA21AULL, 0x1AD2751CE86CEDF8ULL, 0x39F8E2BB225A588BULL, 
            0x656C091B5C033890ULL, 0x9F42829CA9AFB3ECULL, 0x2198A5413D40E0E1ULL, 0x226F97186EB31AC9ULL, 
            0x87283DD352F948CEULL, 0x90117B88F1A658D2ULL, 0x12B0D79173CA46C2ULL, 0x0EF067FCE58DF05EULL, 
            0xE2E0256CA256D280ULL, 0x81C99808F696E2EBULL, 0x97A477C509FDF62EULL, 0x9380ADCE7E2FA13FULL, 
            0x131014542C75D0C5ULL, 0x7A137C06744D8C2BULL, 0x87D5A3EECDF8055AULL, 0xB7D9DB4C1160F5ABULL, 
            0x282E414514852E56ULL, 0xA718CAE579BF9FC8ULL, 0x1BC40224ECE257A8ULL, 0x45F8466B49328634ULL, 
            0x722ED6B8851C98D9ULL, 0x49877499B69104ACULL, 0xAB3C38D4E51B30CEULL, 0xCB89A2F3AC70B3A0ULL
        },
        {
            0x35815AD61CB7A78FULL, 0x6393C4101A728480ULL, 0x0125C5793AD999DEULL, 0xF8D0B13E1268B734ULL, 
            0x69AD5348AB9EDE5CULL, 0x767D2D5EC048F24AULL, 0x871DD7730D3CAE5AULL, 0x14A63DB7FEC1D872ULL, 
            0xB7A9E22B7CA9FF4BULL, 0x23CF35C1995EA3C3ULL, 0x5732881FACF6A924ULL, 0xAE6A7CEB695012D6ULL, 
            0x66B8CE464EC7219DULL, 0x08ACDCBF09DB0A9CULL, 0x02C1F0F87C4FDC02ULL, 0xE9F5697F9AF744ABULL, 
            0x5AD213E4F8AEDC9CULL, 0x131CA10B1390128FULL, 0x3A2389829ED11480ULL, 0x973A6E4FC981E033ULL, 
            0xC5EDF07BC10C9AE8ULL, 0x1374BF63B98A9C65ULL, 0x5E597FCDD94C2D74ULL, 0xF60540BF2DD7713AULL, 
            0x7C71629807EF6F41ULL, 0x482B1B1557B0D81BULL, 0x04DB5A2EDFD8FD42ULL, 0x34164BEEE4DA0EFEULL, 
            0xFC38EB19B5478151ULL, 0x227EBE72965E3A27ULL, 0xDB0E7D1A85856938ULL, 0x472545A61F0F3BF5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseEConstants = {
    0x937C1734171A24ECULL,
    0x4E187A29BFAF125DULL,
    0xF8CAC8005352EA5BULL,
    0x937C1734171A24ECULL,
    0x4E187A29BFAF125DULL,
    0xF8CAC8005352EA5BULL,
    0x9B076B7831BCE5E8ULL,
    0x2D53717CF7F1AB07ULL,
    0x2B,
    0xB4,
    0x28,
    0x6D,
    0xC4,
    0x14,
    0x93,
    0x8C
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseFSalts = {
    {
        {
            0xA7739753F359B860ULL, 0xB7EC06EAE4FB5CBBULL, 0xE24373C004ADD49DULL, 0x4B574E516D3A3DF9ULL, 
            0x8BDAAC1C314EA532ULL, 0x675F2E980EA4A458ULL, 0xA7B2C77225E164BAULL, 0xC6A6948B1426256AULL, 
            0x54B6DBBFAB1F2472ULL, 0xDAD2FA7DABE13567ULL, 0x718D4ECC2032730BULL, 0x83907090B7B4E1AFULL, 
            0xD4D76362A3479B72ULL, 0x5BD1723842F844B8ULL, 0x82D3C61C7A5D5176ULL, 0x64CD4A50503B984EULL, 
            0x4670CA95578FA4DEULL, 0x70B8A6F5932D7955ULL, 0xCBB85542DF4D6822ULL, 0xC47C69FF2DC1D84DULL, 
            0x28896DC0EFB66094ULL, 0x12B11D1ECC13BF77ULL, 0xF5C0698FE0C9A0CAULL, 0x2AC46C68F60694B2ULL, 
            0x9062A505652848F5ULL, 0xCB51FF573CF1C7CEULL, 0x397D8940B4D092EEULL, 0x8EEAB925D2C51ABCULL, 
            0x3D792657A1F2E625ULL, 0x83BAF9862580CFA8ULL, 0x1E3D4E777FF355E3ULL, 0x79A54D8726E3B228ULL
        },
        {
            0x41C7435613155B5DULL, 0xF45289EA52A05F80ULL, 0x3BF8C1F0FD5BCDD2ULL, 0xA19EEA834ADE8865ULL, 
            0x04F00354FA888FE4ULL, 0xB680DFB99F3D2CEDULL, 0xC164BBE015146019ULL, 0x04B6AB29D26C6D35ULL, 
            0x4BF7AF78F0E93174ULL, 0xF3A2104520F63C8DULL, 0x5CADD4450D5F8F37ULL, 0xAD2906585047AA99ULL, 
            0x8C894447D265E904ULL, 0x9A872BE8F1571189ULL, 0x6D9F5C67987F76C3ULL, 0xCF292602126FB490ULL, 
            0x656323F1A54814AAULL, 0xC489DB4FE09178C8ULL, 0x256709F9A1221E90ULL, 0xC6506C4237203EC2ULL, 
            0x2D60DC0B400F2B4CULL, 0x3D3C6D69AA3F04EFULL, 0x46E272F86AD78CA5ULL, 0xEB8CF63950AC7E84ULL, 
            0x17C1BE47D7F3F0F3ULL, 0xB911D46A499D8538ULL, 0x4186492B84FA2C58ULL, 0x7E3E6F16CCB7050EULL, 
            0x413502E28AEC1FB0ULL, 0x60D2116BA1E758C4ULL, 0x6A46EB93065D8986ULL, 0x70B863540926CC90ULL
        },
        {
            0xA70A272375DDEEFDULL, 0x0DD2153A8B40373CULL, 0x1BD6BB322EE732F9ULL, 0x0846758FD9D00CBEULL, 
            0x04C5B1D83919AEF4ULL, 0xF7A727441597E829ULL, 0xB815D4379D42A8E9ULL, 0x839AD0D6CE882CDAULL, 
            0xD47404CD15430D83ULL, 0xC22CC7E90CBF8C17ULL, 0xBCE7FBC8EC463017ULL, 0x24B35B1D652E4286ULL, 
            0xD41E97973C91BB2CULL, 0xF422871515E92C74ULL, 0x74683C6277652198ULL, 0x60AC83259DF9F392ULL, 
            0x2A1688522A3A8A30ULL, 0x44D5CBA9A829E53CULL, 0x883189ED700A3EF7ULL, 0x7839D88EB68F59EDULL, 
            0x994F112A7689844FULL, 0xD7A01C0E357DE1B1ULL, 0xC6C347A5470226CBULL, 0xF595BED1465321ADULL, 
            0xF26B104C7C267AB4ULL, 0x2329554F93A97E54ULL, 0x69F14BFA72975EFCULL, 0xEF8151D49D5938D3ULL, 
            0xCE316409388EAFABULL, 0xD5A850497E666C4CULL, 0x44401F3522334F9AULL, 0x0B867BC3814DB432ULL
        },
        {
            0x397C8AEA411CC627ULL, 0xD971C3E23DB77A2AULL, 0x3BB3A7C83AE4FD3EULL, 0x49A788D67EC0B59CULL, 
            0xEA46F7650F4F5658ULL, 0x249CA9DDECB76F2CULL, 0x0C896E6BF6B1E7BFULL, 0x81E46A03DD9F2EEAULL, 
            0x82B4F8EE58171C18ULL, 0x5ED86BFBC080FD15ULL, 0xE663111E1554E0ECULL, 0x596ECFB839A52A37ULL, 
            0x538E6C23F9250D5EULL, 0xD524D8DB2DE34866ULL, 0xF9885F5EA332CD8AULL, 0xEEF87F21757A6E32ULL, 
            0xFE4006E536750AC6ULL, 0x3D747DEE6E27FAE0ULL, 0xD5718F3D29157850ULL, 0x9D0CBAC705183235ULL, 
            0xD48601DA5DA6ADA8ULL, 0x3AE2C668897A054AULL, 0x1697DD543A6B73AAULL, 0x7C8EB3C702405185ULL, 
            0xB4ABAB41A31BA0AFULL, 0x97367C63004C120BULL, 0x316A0FBCBE611029ULL, 0xFC8C82455203BBECULL, 
            0x58EC73667ED964C4ULL, 0x5C606F0E20AC2259ULL, 0xA02252A5959CDF05ULL, 0xF76E0C6EC997D1A3ULL
        },
        {
            0x75C106B24EE82435ULL, 0x70380ACBD79B49B0ULL, 0xA1D4A9D9C627D8DFULL, 0x05F0316211FD3CA6ULL, 
            0xCAE7913FFDCA61A4ULL, 0x763E1D6A0D7876DEULL, 0x93DBCDAB53949925ULL, 0xB11C1B9130D1E910ULL, 
            0xEE79C84E44D91F54ULL, 0x9803307BD672C6EFULL, 0x0AE58429533A078DULL, 0x50D02749B5D3F87EULL, 
            0x1544B3841B5E26AAULL, 0x6A5ADC5D7166A6D4ULL, 0x90180D1AA6D60BD9ULL, 0x70F44D31A4256BB8ULL, 
            0x102ED8E2D522F900ULL, 0xB832FFC9EB835107ULL, 0xB48C83179522AF19ULL, 0x6850A8BA049D74FDULL, 
            0x757B92205BB2DC69ULL, 0xA8F157EEBBEC4303ULL, 0x25A9F27903D4394FULL, 0x75796198033D58F1ULL, 
            0x812DD290E4BA4117ULL, 0x7B9B00497F4F3893ULL, 0x5AFDDC337BD2FA0CULL, 0xF1AE2894548B627AULL, 
            0xBA63CC37B8D089DBULL, 0x97BB796DDA8820B6ULL, 0x8CE740EA0A5749AEULL, 0x6D15119E73EE4AF9ULL
        },
        {
            0x5B78D5CDE16698BAULL, 0x94804D558230C24DULL, 0xBFAA0DE1B9C0D29CULL, 0x77A427A3F92FA906ULL, 
            0x51C983FE504F080FULL, 0x5EF4356510B91C9AULL, 0xE5207FE3DA4A722CULL, 0x2CCCF7F82024EB04ULL, 
            0x144C2C2E637D62B2ULL, 0xA6A9ADBBB7A97397ULL, 0xD649F0FAFE2E7683ULL, 0x4CBB585E9CA21CD6ULL, 
            0x9F2AE09F581FD195ULL, 0x2A6E391C3C305B5FULL, 0x2E5D18BC11FB3009ULL, 0x3AD204F5511A7B84ULL, 
            0x5C405597993F5E0FULL, 0xF5B427DC8FABB9E3ULL, 0x29DFB6FD68262D9BULL, 0x5B27E736E837B986ULL, 
            0x550884A25464650FULL, 0xEDCFA4D2E7A69757ULL, 0xE17AC02C854F5D42ULL, 0x5D0EFA2F82583EA3ULL, 
            0x5027A6AC7DD59851ULL, 0x510DC5D89FE84151ULL, 0x338986613DD24CA5ULL, 0x7B762878D8CBB444ULL, 
            0x645B0BB303B6A30EULL, 0xEB093AA7D8625419ULL, 0x50629D9C844D3D62ULL, 0x04EA7468B46D106FULL
        }
    },
    {
        {
            0x0CD8D6120F6B5FCCULL, 0x82E1EB8BB8D3A55EULL, 0xA644699EF7CF50CDULL, 0x1AED47DFF5595C5FULL, 
            0x1E484CC513E0BE38ULL, 0x1A7A089D0BCC89EEULL, 0xA477CD6DCAD1853CULL, 0x6CE8C0205DC05270ULL, 
            0xEA26BF9FA3A52ACDULL, 0x39380B5B73A0C565ULL, 0xE87C57BD18230287ULL, 0xFFB63AC3EEEC97CCULL, 
            0xFEDAB8A5B33E6E30ULL, 0x38A05A0C885DAEECULL, 0x22A47E354C4DC987ULL, 0xAF5CF0E2936FCBBDULL, 
            0x69A3B80A95901E82ULL, 0x27D6711C63359A33ULL, 0x3C9B2F1BDA1DF680ULL, 0xBFB231ECB399C753ULL, 
            0x8688CAFC1ADFE5C5ULL, 0x18D30D9A5DA5E068ULL, 0xAE11A89C8DE48BB3ULL, 0x3AB83F370508FCF4ULL, 
            0x50E25F6918E60591ULL, 0x919C7F9139B2979AULL, 0x143B7D27A7156F14ULL, 0xB710D3BB70AF12FAULL, 
            0x583DA67D3BAACB76ULL, 0xF7FD5C19427B1E9EULL, 0xFDE9929A61CE605BULL, 0x871B811337F6B2BFULL
        },
        {
            0x78EE4F341C59BAC0ULL, 0x9A9E57307A99ABD4ULL, 0x671367A3F9F89858ULL, 0x7BC84D4014A53E30ULL, 
            0x184A5F1686BD6BFCULL, 0x012B650E1C29A3E5ULL, 0x684D82AA1276A15FULL, 0x472B81633A4FB26DULL, 
            0xBBF74D81E3D8EF8FULL, 0x804303B1232573A1ULL, 0x7C8099F8EDBC20EFULL, 0xA5E54973812CE301ULL, 
            0x8577177913CE08B8ULL, 0x111B4AE962B84ABAULL, 0x695461DDD20B1571ULL, 0x3717CCFEF1BA6DB4ULL, 
            0xA19791D2ABE42B4EULL, 0x80F3750FD611A5C2ULL, 0x65E6B9026FB1EB3BULL, 0xEA4F67B28BB3F12AULL, 
            0x7A793920D3F614D0ULL, 0xF4982CD6EA609804ULL, 0xFA47D2F501FFBC04ULL, 0x473B117490D2CF61ULL, 
            0x0FEFE4161FD3ABFCULL, 0xD52079AC09C8DA46ULL, 0xC062DBDE0988FD08ULL, 0x02FC5E6F573598B3ULL, 
            0x2A9BFEBF9143283BULL, 0x6F5716B92D751465ULL, 0x218D35ED8AB4A0DBULL, 0x95C637B773F6E9B3ULL
        },
        {
            0xF61E8E53D38EBA6DULL, 0xD36AE9C58770D2A6ULL, 0x56B0E0824904AEF4ULL, 0x24187DAB5C54F6D2ULL, 
            0x701A01EFCD8EC0B0ULL, 0x3A9FB4B40546597AULL, 0x553FAC90D0D01705ULL, 0x4C47B107FD6F64B2ULL, 
            0x41057272A6719280ULL, 0x9CB8C71A50237D4FULL, 0x601C7E15498D41C3ULL, 0x7685893DA005ABD4ULL, 
            0xE32AE7E768BC914DULL, 0x703934C330A51FA8ULL, 0xF5907CF041A491A8ULL, 0x63E1EB67052328B0ULL, 
            0x5A1ACEBC1915C547ULL, 0x7F48361B98AE4C18ULL, 0x90F6399B8C92BC60ULL, 0x90CFC964F62CD52FULL, 
            0xCBDC09BED482C0EDULL, 0xFDAE7FA8BDABEFE3ULL, 0x824A509DA6A0FC7FULL, 0xCA408F70FD0747DEULL, 
            0x6C3AB43FBF071970ULL, 0x9905AF1B43563B5EULL, 0x433A0F4768C908CCULL, 0xB4B03C9D77397D1FULL, 
            0x245E38CBB29B901AULL, 0xA96A2028A51204DFULL, 0x98AF86F272152C73ULL, 0x673F36EF9DA5C311ULL
        },
        {
            0x27C08A74D4EE867BULL, 0x4541999A588CC6A9ULL, 0x658867FD872E7B30ULL, 0xF166942CB0BF1744ULL, 
            0x243EAB9058DEB82CULL, 0xA5FC57BBF3766B42ULL, 0x7E6B74F368E08BF2ULL, 0xD539171DEF275382ULL, 
            0x1E2365443D6C274EULL, 0xC6F11265B7910B93ULL, 0x06DEBA417A6B75ABULL, 0x77A0EEF937823582ULL, 
            0x8255D6BD46DF4197ULL, 0x3FDE7EFB0C5489CEULL, 0x09214754563F7523ULL, 0xAFB8C52A245AEFC3ULL, 
            0xA06E11A53D9653F8ULL, 0x8428C6D5754DB0DFULL, 0x414C9EF934966FBAULL, 0x775C970DECDA7A4AULL, 
            0x366EBF2D5363CF92ULL, 0xAC14CC91772CE86EULL, 0x0D5227655467A9CAULL, 0x6F7028C614C7B3B3ULL, 
            0xAF6B0576B257D80DULL, 0xBF9628F4BC093821ULL, 0x3D72837642C5A444ULL, 0xC69919C42F03B450ULL, 
            0xC73DE76D7C95DB41ULL, 0x58EAC73AF7242658ULL, 0x0427C7F5DEA047C0ULL, 0x2C382FB67CC6D452ULL
        },
        {
            0x23EE132C5047A16EULL, 0x510A21DFA4E7564BULL, 0x8B8947A585EDA8DCULL, 0x2C8124240BD0C11CULL, 
            0x6976A46BFD78C24AULL, 0x99284E8CA2DD2FD8ULL, 0x3EBEB51DC9C1ECA5ULL, 0xC652AB75A9D047B7ULL, 
            0x29AAC646D15225FAULL, 0x51524242FC08F756ULL, 0xA1B683E3EA27A74AULL, 0x0BE545150BAD5462ULL, 
            0x73CE283A0E3BCA1EULL, 0xB4CCC17874C245DDULL, 0x3351E29E19C4406FULL, 0x6B809E5BDA0282A8ULL, 
            0x5FEC12037847EC99ULL, 0x255AB87C36E5B698ULL, 0x049FA2658BEAC57DULL, 0xAA27C354AC97A167ULL, 
            0x79BC43C8C3C541FDULL, 0xA8ED6016E6093485ULL, 0xCFE20BB272C96220ULL, 0xFF0E432BA34F9BCCULL, 
            0x9D134F8458758F5BULL, 0x7583D5F2BC6AB47CULL, 0x522302CAD3E271D5ULL, 0x4A3BE58109A7529BULL, 
            0xEE36F1151472EC91ULL, 0x43E524788CC2CF28ULL, 0x6FA2F2BF45A3F35AULL, 0x08D20BB68A0CC93FULL
        },
        {
            0xB09568053A90B856ULL, 0xE12078A2FDA1B2CAULL, 0x6877C8F10C059F03ULL, 0x03EB4BD6B9D1822DULL, 
            0x5ADA6E131041402BULL, 0x7429D03D8D5B009AULL, 0x25EEF061DFC83DBFULL, 0xC70C8AD036401133ULL, 
            0xE65817E470433EF2ULL, 0xD74735ACFFF8FE25ULL, 0x6D6AC898DD597CB6ULL, 0x77059586B4C27640ULL, 
            0xAF352B6B1926FEE2ULL, 0x89A664DA00605424ULL, 0xEE658F0EE388EBB5ULL, 0x38E2B6231C2B2848ULL, 
            0x50CB64E12959FDFBULL, 0xEAEDFDD1963D8FC7ULL, 0x3ACC0F574362C595ULL, 0x724C405BE8B6AE98ULL, 
            0xD57C9C9BBC2016E1ULL, 0xCAD73005A4273AE6ULL, 0xF9B126EB371271CDULL, 0xD103AD6AE42F42A2ULL, 
            0x08CDDADD04C7EF44ULL, 0x550242699E9FB64DULL, 0x68CE228593BF4326ULL, 0x154485D84FF96D51ULL, 
            0xA733F179E95B8715ULL, 0x0B0E8871ADE2056FULL, 0xD5EDE410CA608BD4ULL, 0x2B9D8668E7D71978ULL
        }
    },
    {
        {
            0x928C2896EA7030A4ULL, 0xF4D17098E8CB753CULL, 0x10B8470092A15996ULL, 0x778C87A71D8B805CULL, 
            0x595396C089C1254FULL, 0x08B3EA5EFB691305ULL, 0xFB563FE890AB3AE5ULL, 0x44567B130682C037ULL, 
            0x8BC78D0283D53E17ULL, 0x58F121A6B6476A32ULL, 0x30E6898C7A8563C2ULL, 0xCC2B2EB5DD8CF9D8ULL, 
            0x2DE0DA8552F0D1EDULL, 0xC839CCC2ED579276ULL, 0xC06F85C9C63EDE70ULL, 0x14B042604238D9F7ULL, 
            0x6A434ED8ADE759D9ULL, 0x4AD666605E52D9CDULL, 0x895879AB5D76DFE3ULL, 0x060A2DD655448705ULL, 
            0x329A843749C33B8CULL, 0x648C601153C4FDE2ULL, 0x2D011B9B64286858ULL, 0x0E0EC4AD84B9C8E9ULL, 
            0xFB4B3CBEDBCC6B7AULL, 0x79085576CEF54451ULL, 0x2710798854C62E89ULL, 0x0127AC8AAADB1315ULL, 
            0x98E349520CC58F75ULL, 0xDB2410427E9FF148ULL, 0x97A5FE17CC188FF6ULL, 0xA9D863EAB31B6469ULL
        },
        {
            0x48BEF3737AE88E86ULL, 0x988AE148281D6B4BULL, 0x6A67AD77EFD0BCF6ULL, 0x339147AF30A847E1ULL, 
            0x3143877EB212704DULL, 0xE023F3FBFAF22718ULL, 0x08AD403B33DA73E5ULL, 0x906C42F35B9CF594ULL, 
            0x1C75EB7F0F10A04AULL, 0x963D49B273F287F3ULL, 0x4C11994BB214FFB5ULL, 0x933BA4B4F22FB725ULL, 
            0x5BC06E051327E08CULL, 0xC7763636F6AB2E6DULL, 0xFD6BEFC482799C2BULL, 0x04B25B0651846A7BULL, 
            0x1C40338E8ACE5E31ULL, 0x54A31E4EE25F3732ULL, 0xA0920324A00B2046ULL, 0x00934E8B77CC64C3ULL, 
            0x4A7851B1F5AA6659ULL, 0xFBEAF42187771E1EULL, 0x365BDC7446BABF06ULL, 0xD06F12E0F93921DAULL, 
            0x8077E9BB8DC379DEULL, 0xA897F8EE87049D38ULL, 0x554736AFDFB153DBULL, 0xAC3F9AD3A03F071CULL, 
            0x61BE2058CAF3EF20ULL, 0x35F74C60A0DD58C1ULL, 0x4391B1CE0261A1DDULL, 0x0FA8F2ED67000CF8ULL
        },
        {
            0x0EBDEE11CB026933ULL, 0xB6BBACE848AC3DC7ULL, 0xD3F0FFBFCFB4879CULL, 0xDA33F02D8CFB8C16ULL, 
            0xE0D81886F5C27A2BULL, 0x839A5DC14F0F962BULL, 0xD2F7336359D1DFB0ULL, 0x18DD67280F1D11E0ULL, 
            0xF12ECC397EFFA018ULL, 0x8FCF42BA13EEC782ULL, 0x4F48BB033FA11F3CULL, 0x99611D881AC382C9ULL, 
            0x6D2BD586F073F1F8ULL, 0xBAD51F1AA99038B3ULL, 0x529BB8CFA91ABFCEULL, 0x69A4D1DCC29AEC85ULL, 
            0xC8BAA24094ABAC22ULL, 0x79E153B112882E51ULL, 0x2ECEA6D8FD05215AULL, 0x0BC957B2AAE0BA03ULL, 
            0xD46F8F74F78471F6ULL, 0xCBDF56373D284F89ULL, 0x4AF8FDD7613278D0ULL, 0x60BE15E8381C3B5DULL, 
            0xCA3A4102A347C7ABULL, 0xE5BD6AA26A66D244ULL, 0x61DCCDFFC7B0F293ULL, 0x0945A3D5E908C371ULL, 
            0x3365C1AF65C5E66FULL, 0x93C08EF4C1BB4A45ULL, 0x45EF5DFB2404C445ULL, 0x80F234E38A352F67ULL
        },
        {
            0xF4F3983296B86E7EULL, 0x3B0D2B0FAD58803EULL, 0xF960A7933A3C5337ULL, 0x4802C9B2596D6D54ULL, 
            0x17AE3FFBE9A14DFCULL, 0xFD8273DBE9CF7193ULL, 0x10BE1664588859CEULL, 0xB23D5E063387DCD7ULL, 
            0xEA983C47D19F6C32ULL, 0xB421858F1C5B632CULL, 0x998B2EAFAE280525ULL, 0xF3CD35D853ED2967ULL, 
            0xA28D43C99B8F9F0DULL, 0x56FB651F4DD85BBDULL, 0x7C43A49070FFFF58ULL, 0xDE8933D5BE859E74ULL, 
            0xB76C357BCE33F599ULL, 0x909B27DEA7C70F6EULL, 0xFB07D766FEA305C0ULL, 0x5A655352A5B80DB4ULL, 
            0xC70494C94FA5F3FAULL, 0x18409F5FBC1661F6ULL, 0x86F429F05C36ECA4ULL, 0xAF74DFD78994A39EULL, 
            0x2AE2918E51E99477ULL, 0x7044C56207600130ULL, 0x12B2E7F1D7586136ULL, 0xFDA00D701F8EF249ULL, 
            0xF707D8BFA3381C60ULL, 0xB235C760BDAA1AA1ULL, 0xA87A69FBC2D63A84ULL, 0x9DE4456557A8E63EULL
        },
        {
            0x2A9E774655B3C99BULL, 0x9BAA4D231E9DA120ULL, 0x66D5061227876961ULL, 0x5B110100BABA0070ULL, 
            0x2463657A87EBE517ULL, 0x822CC3B056D1BB54ULL, 0x15FE95C9FD58388DULL, 0x568216CC25B58D80ULL, 
            0xB4B9C8C2CDC260EAULL, 0x4AE33890F23E53EDULL, 0xC87BD4DF1280E080ULL, 0x666ACF01F25F2660ULL, 
            0xD75A982989A3E45AULL, 0x5CBDDFEB403AEC46ULL, 0xFB7AB46AC5FE0033ULL, 0x541ECAA65D6EB865ULL, 
            0xF46E2B73897136E0ULL, 0xB4AC7EDB354DA139ULL, 0xD3DB0363AE7AA131ULL, 0x5820708D0DF0FB8BULL, 
            0xFE8CCFD30A6968E1ULL, 0x0F780C01AD58EB2DULL, 0x9D6FADD80B3FC95CULL, 0xBEE9680FA1A4F9C6ULL, 
            0x67E05A8112F6AEF7ULL, 0x01669AD1B40EA380ULL, 0x2337EB37CD343136ULL, 0x18B7E9813D5E5EABULL, 
            0x78F26B3E2D315600ULL, 0xED62AB6638838F66ULL, 0xB9CB029BD636F4A3ULL, 0xEE88A349E5451147ULL
        },
        {
            0x06782029105F73FFULL, 0x25786411C93C3D87ULL, 0x49AEECE250E678D7ULL, 0x8ABE09C121B70942ULL, 
            0x988DCD88DD672EFAULL, 0x6B34F8F7FD506AECULL, 0x0D1E39E515058BE0ULL, 0xE1B9EA5A580A9BEBULL, 
            0x5EEE4174019CDFBBULL, 0xB10EA72F42CA47D1ULL, 0xB01A754D57E070A2ULL, 0x0BDAC7ABC24AFF4FULL, 
            0xF7C491FA414C44DFULL, 0xD21DF215745664FBULL, 0xCED0D7CC5AAF4012ULL, 0x8DCC3475E693912AULL, 
            0x3433B396042106E3ULL, 0xE6FBD6874FD6D2DAULL, 0x07DFF398F136E06DULL, 0xF3B425FDD67287CEULL, 
            0x95F26A269B2E8243ULL, 0x68F5DBDC95B2EE2EULL, 0x13A30D4C17F7F882ULL, 0x66943FD0B5E295FDULL, 
            0xB456A2D154F37FEEULL, 0xF551A57F6AA55466ULL, 0xFAA306C371CAF1D0ULL, 0xECB5E8A96F876B61ULL, 
            0x5F96D11C577FE8E4ULL, 0x7DA42FC265E5B3E7ULL, 0x6D401D61D5BE50A1ULL, 0x580E4FCF7F2FEBE9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseFConstants = {
    0xE9E1AEF3F9E2170DULL,
    0x60EB0E16027766EAULL,
    0xD4C3611B844E5577ULL,
    0xE9E1AEF3F9E2170DULL,
    0x60EB0E16027766EAULL,
    0xD4C3611B844E5577ULL,
    0xC2375627A28ABF87ULL,
    0x5EB1ED4FD8CEBACAULL,
    0xFE,
    0xE4,
    0x4E,
    0x68,
    0x06,
    0xD6,
    0x46,
    0x72
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseGSalts = {
    {
        {
            0x579E92DBFAC2233CULL, 0x2EA064FDA92AA7DEULL, 0x7E45EBC45404690EULL, 0x75D6CC61862CFDA7ULL, 
            0xA7F3F3AA4D03F2B9ULL, 0xDCC9322AA4A0CFCAULL, 0x8B240BF2D49F52DCULL, 0x96B4492C880F69EEULL, 
            0x4BDA1D7651B1FEBEULL, 0xF222EB23EB5130B3ULL, 0x69EA60C8DF9D8D4EULL, 0x23BD9A869E6B17EBULL, 
            0x931C0E382C21916DULL, 0x353894648A290D0AULL, 0x76EF03E8D0AA59BEULL, 0xD6C3AC91E64B3C97ULL, 
            0xD01F7ED86CC6C16DULL, 0xEF8197652D548E6DULL, 0xD4B400BC0FB7B782ULL, 0x9715F44D0763F8E9ULL, 
            0x44428E8B16910FB8ULL, 0x86BD10D6CBC1F770ULL, 0xE09E61E9F410B860ULL, 0x00AE0A8ECD69FB43ULL, 
            0xAB7423A61C9A9B10ULL, 0x98BD123270D735D6ULL, 0x889EFAB129FC05D6ULL, 0x53A0D7E7C8EED341ULL, 
            0xC7F9480AAA2F844DULL, 0xF7FF77DD6024F1F5ULL, 0x2B57413A354ADD4EULL, 0x34DEAF9A63B489E8ULL
        },
        {
            0x63CFD968F48CE6E6ULL, 0xB9FEF076FBF7E00CULL, 0x8B40005A7A0DE599ULL, 0xABAA17FD1765F1B7ULL, 
            0xC2F0934EDF6A47CDULL, 0x3EEDDA01A8E017EEULL, 0xC7D5A31CC6A3A573ULL, 0x3D3F1AE94B7FE825ULL, 
            0xDC2847FB7900009EULL, 0x2C35CE4A9017C174ULL, 0x2D5AED11884A5808ULL, 0xFE29DC0A8621F334ULL, 
            0x245AE9AFDE444A53ULL, 0xDE211D8C03BB3EF3ULL, 0x791ECD40B613D507ULL, 0x899F4259D45EF873ULL, 
            0xB9423C9D67023AB6ULL, 0x3B767CE323B84F4AULL, 0xA1A053074F0F9376ULL, 0x05B8C5BD2452F9E8ULL, 
            0x942940B9B64F81B6ULL, 0x32CE41092FEBFBBFULL, 0x52EC95FC4E0BDB1AULL, 0x7BB1EEACD2BF5F48ULL, 
            0x2D566BF636095281ULL, 0xD92F014190FA1584ULL, 0xB9C5E46530E49CC7ULL, 0x2B2798278D09DB99ULL, 
            0x29C18E9A274CADC3ULL, 0xA577964F3DDF1F30ULL, 0x7EF9D600313CA9E0ULL, 0x5D394E1D26886132ULL
        },
        {
            0x018547C933B21E02ULL, 0xE686E8ECFA483D20ULL, 0x477FE5A1B1EFD474ULL, 0xE7BB9E7EDF058711ULL, 
            0x11FDFB7F9A2BEFD4ULL, 0xDF0EE255064CC61BULL, 0xEB3193D45F0D092CULL, 0x5F50433D33F9AF74ULL, 
            0x4F35364B538FF483ULL, 0x144FF5B507CF90BBULL, 0x1FDC3CE19229A2EDULL, 0xB68E0A0A0DA6F67EULL, 
            0x5B15E77B14A6C5AFULL, 0xDB882FF824F5CDF3ULL, 0xF1B500D99E180A60ULL, 0x3BA092453A3EA30BULL, 
            0x1FD2425075637DD3ULL, 0xC9C2A31B48C352DCULL, 0xE90E0CEF070872BDULL, 0x475B90CDC37CD32CULL, 
            0x50C4CB193BA3855EULL, 0x7B90C080AF26A531ULL, 0x079058090F1E1772ULL, 0x37772B40334D4437ULL, 
            0x4E58EF17378E2BB8ULL, 0xC3ED5CA8CCD669ABULL, 0x134C4ED79D6B08C1ULL, 0x0DE5886226A4DC76ULL, 
            0xCAB36D17EF03F415ULL, 0x629BBAD1366FCCA8ULL, 0xD878A3EE97365F7BULL, 0x826B359127C6D186ULL
        },
        {
            0x1CD0D2750A5A6261ULL, 0xFD82143C59FE8841ULL, 0x891DE8AC9747E73FULL, 0xC14CE5F5DF703899ULL, 
            0x4082C6F4F75BF303ULL, 0xA672AB0A7CCBDA20ULL, 0x7F862546C917931CULL, 0x3C0182BF7BD9BFA4ULL, 
            0x355CA25ED9E59B4EULL, 0x530A7FD59D5E3A2AULL, 0xB197310BF4B596DCULL, 0x7136F8EF695052FCULL, 
            0x25022C8B7CAC1A25ULL, 0xF68944B63022E707ULL, 0x7B486A27197BE40EULL, 0xCFBD3A239B8FE728ULL, 
            0x5A1D8C2C7BD116A6ULL, 0x8A10F14B0464C8AAULL, 0xFCE15B320C7D51AEULL, 0x04150109AD51B6A6ULL, 
            0xF9F296CE5BE58044ULL, 0x53513A644F5CD21DULL, 0x6D7C1CBDF4CA18DFULL, 0x165E372D29E98DF0ULL, 
            0xED3789FCF6DF2675ULL, 0x7192134F4AB06E1BULL, 0x147AF87A8DE65260ULL, 0x0A444650B6BAA003ULL, 
            0x5A9932CB108AE76AULL, 0x36B8345D34A1D634ULL, 0xC62842698AB3AB98ULL, 0xBFEDABC0593A6455ULL
        },
        {
            0xC5CCBBF55D04E681ULL, 0x62A25ACCBE42156DULL, 0xC47ADEC08EB8D73CULL, 0x55C8B19E508702FBULL, 
            0x61661F9DA41D7282ULL, 0x0DA5EB0ABEAE7235ULL, 0x6AAC8E62563F159EULL, 0xC761DEA0683E958FULL, 
            0xD00FE2D5B435A165ULL, 0x89C8F3AD7606AEC6ULL, 0x02B0B0F9A424F16AULL, 0xDA28B0B5CF3F75AAULL, 
            0x84345D7D76DD7E87ULL, 0x664E44DF49F71235ULL, 0x87F15E856C703783ULL, 0xF5184D33962CFAD4ULL, 
            0xA7D6D300AA75AF8BULL, 0xAEEF2AAB814DEF25ULL, 0xA824E57F9CB65534ULL, 0xCCBFD04B04AD6E23ULL, 
            0x1614C1DCE677826FULL, 0xD3DBF2588D5D9457ULL, 0x6C8E34E604E529A3ULL, 0xC8F1E43F0B97AB0EULL, 
            0xEC4D787518FFB11FULL, 0xD46B87D76D7DF69CULL, 0xD18DCF46E8D10DCFULL, 0x57F1A510A3EB5553ULL, 
            0xA2E4818DBAE976E9ULL, 0x00FA7455FE13607FULL, 0x19FB9795964A9F7AULL, 0x5FE1511F814FBE54ULL
        },
        {
            0x63EC5900602F47DDULL, 0x4E34CD4D408C7C62ULL, 0x58358E91BA94D42BULL, 0x012D5E633AD6B3B0ULL, 
            0xAF092C294A9EEB69ULL, 0xD97FB1E90EF9D63CULL, 0xB181B09F832D4CA3ULL, 0xF3B6FA0EA7E9485EULL, 
            0x0991226A6910AC22ULL, 0x1D1BDAEDB4417BDDULL, 0x5C1F88C35CA61A1CULL, 0x6F830CF10BD914F2ULL, 
            0xFDDC422956FC524CULL, 0xE5EB03A34BA3FC33ULL, 0x152AB5A1AF2E42C7ULL, 0xDFF96BB935DA12F4ULL, 
            0x3BAAC97DF4FDCD6AULL, 0xA69CC48808B2D462ULL, 0x76F10A0AB3EED393ULL, 0x103CE98D075A2E82ULL, 
            0x598CCB3084F57391ULL, 0xA26D3CB1392D048CULL, 0x7A66ED13E106DE27ULL, 0x1D8FC5E2B13F07EBULL, 
            0x04FFDA914542E44EULL, 0xEEF954FACC76D914ULL, 0x5041BE16E7885407ULL, 0x0F24BC46D91044F4ULL, 
            0xF8A8ED1653C6B6F5ULL, 0xA5498B0708002F2EULL, 0x95A45002CE705994ULL, 0xE77665A5C3A42DB5ULL
        }
    },
    {
        {
            0x3DB8F13EAF4F1EBBULL, 0xE614B6CA39C19802ULL, 0x91A87DF07161E7EDULL, 0x0D68A47690252CCFULL, 
            0xF1F82BD038238EB2ULL, 0x756E04F17667CBAFULL, 0xA7117131CAF86A3DULL, 0x7C1E35FAE0545AD3ULL, 
            0x8D34D93EFB362E70ULL, 0x6C3998178AE5E7FCULL, 0xDDC9A48931B8BEB5ULL, 0x6DAAE341C9579DB8ULL, 
            0x32ED7A8B2FBCFCD2ULL, 0x1085FBFA8EAD8178ULL, 0xE205A94BB5952ACCULL, 0xA3D99734A4ECC680ULL, 
            0x29BF33782DB7124DULL, 0xE3A81F9EBF047F11ULL, 0x13697CA8E0AD3826ULL, 0xF319B83D0FD48300ULL, 
            0xCC35DE4F6AA2F2B9ULL, 0x1F83E6DF19F54E1CULL, 0x63D074B8FF3C6399ULL, 0xBB610BC6D4AF137DULL, 
            0x75FE670EFCEE9041ULL, 0xCCD20791044FDEB1ULL, 0xDCD8FAE339CF2E1DULL, 0x8AD8ACD70F665C5AULL, 
            0x11A96132E3D9849DULL, 0x89FDE83853A8B1C7ULL, 0x437744C74811792EULL, 0xE7299E3589891CEDULL
        },
        {
            0x46C7496CA889BBE2ULL, 0xBF6901AE4199DC3DULL, 0xC61BE9C60CA6A1CEULL, 0x36EA6329AC1842BEULL, 
            0x55B824207B0F0FCCULL, 0x6879E4E7FD972AFEULL, 0xB555A2772174F0C2ULL, 0x7D2EE651ED59E614ULL, 
            0x9DFAB8736B96E22CULL, 0xE9EE14074C6486F8ULL, 0x273DF0A760A51F68ULL, 0xB0C5617267886C62ULL, 
            0x5420E3C55838D573ULL, 0xC18E26AD547C65F6ULL, 0x994BF227EF4E656DULL, 0x2539F043A3C54011ULL, 
            0xE4C48E91C28C375EULL, 0x49267FAA7AFB31E1ULL, 0x75B40A56F012F8F0ULL, 0xB766B1AEC3862D4DULL, 
            0xEF6114FDD634D501ULL, 0xA9BC76C1008BD3F0ULL, 0x252A62B5668CA811ULL, 0x45B864D64B7B1A14ULL, 
            0x9FC508B04CEF3A86ULL, 0xA5AFC5A98874C029ULL, 0xF2590BDC1EDCFF7FULL, 0x56A9F339F7685986ULL, 
            0x5920779917B904C3ULL, 0x9BA5E619854A5BE2ULL, 0x5795C7DABDCD83D3ULL, 0x7E233E936964BDCDULL
        },
        {
            0x795E99261C00462EULL, 0x8D4131A167BA31C4ULL, 0x688FFEADE04397A7ULL, 0x32270C20FFD97080ULL, 
            0xA6275447D88B9477ULL, 0x15034564958BB917ULL, 0xF7E29CB01D26BDBAULL, 0xA808331A853C14CEULL, 
            0xD67EC2AE6BBD6AA2ULL, 0x0E62762336ED3431ULL, 0xA91B82F23349FE39ULL, 0x3278114B547B74D3ULL, 
            0x8A439062579E19D7ULL, 0x2EDFC9320D11C0B6ULL, 0xB5FAFB04EE3415BAULL, 0x6FE31D3C22D2700CULL, 
            0xF8CC21B56FC653C1ULL, 0x1CE7A5B826CF5C46ULL, 0x9EA9452295D613C3ULL, 0x5A2952712B21E515ULL, 
            0x1BC1E9EC2EC8D7E8ULL, 0x00CC1320FF2E9752ULL, 0xCB08AA0B236BE8B0ULL, 0x42822BA6D6934ECEULL, 
            0x9AE9978A3315F8EEULL, 0xBAEFBB2F3C5FF95FULL, 0xC1A3AAD5862E337EULL, 0x37D08633B2FC4AD0ULL, 
            0xBC06D5113C9AD4F6ULL, 0x19931D9389B02457ULL, 0x41D92A7613F0B667ULL, 0xE8DAEAD73E1EEA5CULL
        },
        {
            0x7342F493806BB847ULL, 0x86163F0E0CFE1631ULL, 0x0149361EFF0F6751ULL, 0xBF6759AA0F8211ABULL, 
            0x4A8D5234E6795933ULL, 0x6801B6FB102DECA3ULL, 0x7DFA30C38FDE3310ULL, 0x6CF06BD79DE17DC9ULL, 
            0x0EE2AF4C31767367ULL, 0xF864953B62610016ULL, 0xDD0F438B89D802F0ULL, 0x37E1C37B36A560F9ULL, 
            0xEDF5BFF56FF8F486ULL, 0x6A4AC5638E769105ULL, 0xD820D74645EEBDE8ULL, 0xFB502D2A794FAF29ULL, 
            0xD985B48511C57322ULL, 0xEFB42C0014931C15ULL, 0x5A07C0A8ED91DBF3ULL, 0xA8E338AE832AC346ULL, 
            0xD9D9E94F681A8335ULL, 0xF11BD3433749739DULL, 0x8F14BC929D0528CDULL, 0xC4C818090598F7D0ULL, 
            0x630EDD8C2876BB79ULL, 0xE8EC263906F53E3EULL, 0xBBA1CB7E23F28E62ULL, 0xFCA97AB1C5A36527ULL, 
            0xAFBB093562372F9DULL, 0x3AE98AA9A75B4136ULL, 0x5EC7D704355DBCEDULL, 0x399B9AEDB5A02E20ULL
        },
        {
            0xC6C5A8B390F4D596ULL, 0x4D77B1BA9F680514ULL, 0x42EF48B0BF6E780AULL, 0x369DF0CFDF92582FULL, 
            0xFA2BD275E182ECF4ULL, 0xF520DA34C9C524FDULL, 0xABF1142980AC95F9ULL, 0xD9F1D274EB3F6CEFULL, 
            0x2CA2F5D8441198D3ULL, 0x43875DB3CE543BFBULL, 0xB0CCBA4222379BA3ULL, 0x65B03C952E31257FULL, 
            0xBFAE565698929406ULL, 0x9632346EF5972F29ULL, 0x675C3C75697E4D43ULL, 0xC877EA11AF57B6D6ULL, 
            0x8242DF386F752E91ULL, 0xB7BCF62460B0590FULL, 0xB15E734A92506895ULL, 0x4E2173EFEDF1711BULL, 
            0x2C7B82FDC79673C1ULL, 0x3352A9BCE68D284FULL, 0x9BB62DC0A97B11CCULL, 0xCA123807D3E0B4C3ULL, 
            0xA74150DFA57650DAULL, 0x52BD0C54E54BF440ULL, 0x212F492F8D3C4002ULL, 0x246B29EEE1AB7B3BULL, 
            0xEAF85083672ECDBBULL, 0xAC80BA34AD3F268EULL, 0xFC9D9724740410C7ULL, 0x6EDFCE394DF99EABULL
        },
        {
            0x5839ED8F9319FFDBULL, 0x98B603936794BFA3ULL, 0x5E7CD1297E9DA07AULL, 0xEC3B9FECF25F418EULL, 
            0x6F1FD6636A6B8B33ULL, 0xC71D4052C544E47CULL, 0xFAACB69D08D843B5ULL, 0x446AE79855A9E2A5ULL, 
            0xFD0B4A3A8DC473B7ULL, 0x3DA2AF9761C595C6ULL, 0x0ECDF6488C21A082ULL, 0x9F36130ED6D8DBAEULL, 
            0x26F1D81725A132ABULL, 0x9F9B79C503730406ULL, 0x0E6B268CD8CEF716ULL, 0x49BFD33B1A9808EDULL, 
            0xDFC00AD091A51124ULL, 0x8590419F3A9D2FDCULL, 0xBDA2D9EADE7FB82BULL, 0x462B0B16A3956130ULL, 
            0x7D7E1D7F20E63A7EULL, 0xF7B6DA5A35BD3F7EULL, 0x09CC5E93B3D14087ULL, 0xAF0C8A88230744ECULL, 
            0xC26D7B64A6567EF3ULL, 0x869EA468148284D9ULL, 0x7509D28C81967D2BULL, 0x94AC64D5991D54B8ULL, 
            0x12C1F63D085A9C16ULL, 0x2B94D75F057BF825ULL, 0x7ECC0C4C140BA63DULL, 0x2DB8E227895FEC71ULL
        }
    },
    {
        {
            0x6E1B10F1BCF11DF1ULL, 0xCB1C40C5B6BC8DEEULL, 0x82D72B342018DC0EULL, 0xEF00B8BC2EB841FAULL, 
            0x8F205BFE62D3037CULL, 0xC70E3FB4492F832EULL, 0x4AE688F36B280066ULL, 0x805F292BAF57224AULL, 
            0x4F631135EDCA313AULL, 0xD89EE6FF63D4AAC1ULL, 0x5930980A3BD0BDDDULL, 0xB6DCEF9E20C2B06FULL, 
            0xB0C287221B8DAD78ULL, 0x37DEE752A2202F7AULL, 0xE82DC1C1B130DF57ULL, 0xC2141D5696333E3BULL, 
            0xCFE9808F080363BCULL, 0xB567091A62FEE389ULL, 0x519D3E50EFEAC0D2ULL, 0x0950AD53EA6DA41CULL, 
            0x528B96C2881CC25AULL, 0x6E65EF3012FBC52FULL, 0x2DB9CB8773BCF07EULL, 0x62C79B86BE5F3CFDULL, 
            0xF26B4E419239FC8FULL, 0xA5FE237433A4AD19ULL, 0x396D687C5E59DA20ULL, 0x11F17E381A795F5FULL, 
            0x91A2D4A00FD26DCFULL, 0x0CE99F4825E7B525ULL, 0x04DA297533C2AFABULL, 0x9CDCB63624B1A796ULL
        },
        {
            0x1FC28AF7CF62764BULL, 0x985921E2A7A55F58ULL, 0xB00FCC1443E8B413ULL, 0x85BE717B6CBA2257ULL, 
            0xBDE63354D20E1247ULL, 0xAA07A299E191B50BULL, 0xF2E51F1D6A2B0F2EULL, 0xC8D8A9D10F8B0E4EULL, 
            0xDECEC6A165652840ULL, 0xC493B72561BF699CULL, 0x6772F2EC21E0690BULL, 0x138B47BA811BE8A1ULL, 
            0x4F1A3AA51126991DULL, 0xD26BD11EB8A0DEFEULL, 0xD77F9EE387E4A692ULL, 0xB8C6AA306D797D6CULL, 
            0xFA85F73FAAB1F309ULL, 0x910F907CD6913C47ULL, 0xAB1F715C1C46954AULL, 0x7FFCAFCC9E600B1FULL, 
            0xFC4D6D059598B7FAULL, 0x9A3566A3F43F0592ULL, 0x5F5969EE2B4A6C85ULL, 0x76FF365919B616B9ULL, 
            0x905E90F6A375EA34ULL, 0x30B0D8D2AF63D680ULL, 0x67158931A6F9110BULL, 0x44CF6DB6E8E1D200ULL, 
            0x17D962321F4A261EULL, 0xD0360834E9BAFD09ULL, 0x7501CE9B4915DFE7ULL, 0x4496FFA4E89A8706ULL
        },
        {
            0x1DFF700E419E2258ULL, 0x5364A9D3520B079EULL, 0x8A3FEA9BD31EA2A6ULL, 0x14B9B7748E54E83EULL, 
            0x19C4418CFB3D9171ULL, 0x42B0E31411568782ULL, 0xFDDD462365EAD3F0ULL, 0x2D886A1FE81AE08BULL, 
            0xCE92378F4D5061B5ULL, 0xF6B8904EBA1F7C02ULL, 0xD082682D41C0DAC0ULL, 0x9BB411E9D4C7A648ULL, 
            0x2D09EEF0C598E4E3ULL, 0x2EA0167B7D1DCBBBULL, 0x38414C3C5FC814D2ULL, 0xCDE3FB43FF74912AULL, 
            0xF6345B70F17EA5E7ULL, 0x9A111078B68FD388ULL, 0x46D8A63BBDE19CCCULL, 0x6451855ABCAAF680ULL, 
            0x8923B914C864817EULL, 0x634945C8F3F71B9EULL, 0x5F99222BDB5C0465ULL, 0xA777B9643EBE264BULL, 
            0x96C185ECB5A782D3ULL, 0x365EC42AEAA72F83ULL, 0x83809D3AF25C8FA9ULL, 0x88D35ABC0E33FF35ULL, 
            0x430C47E9FBF34162ULL, 0x2705BD1744E42798ULL, 0x593EA98E05AF8195ULL, 0x5B7C85859A8E3420ULL
        },
        {
            0x02DC6066B1D4F5E5ULL, 0xE5398C72D1E776C5ULL, 0xBD6CA740E12401C5ULL, 0x65BDF8F7FA294876ULL, 
            0x859A4F16EE43EA4AULL, 0x645A2EA2E5214133ULL, 0x8BB02F4871820AD1ULL, 0xA16D97C6DC314D4CULL, 
            0x1A7345D38262BD04ULL, 0x69377557AF5C1975ULL, 0x7D4370475324BBA7ULL, 0x96A579DF3BEDD9C9ULL, 
            0x75A1416E97812E52ULL, 0xF3790A5174D8FB87ULL, 0x4895455935E6E81CULL, 0xE77D5E69FF421588ULL, 
            0x44E1218F67D568A3ULL, 0x4F77176E5177724AULL, 0xD5AE6E7926B31980ULL, 0xA7C34CD042E942F2ULL, 
            0xE6CDBF824E8CC839ULL, 0xCC6E442ED226844AULL, 0x695719C55CAC2A1DULL, 0x409D42FA8AA52873ULL, 
            0x35AB4B9EADF1357EULL, 0x4BD3226B216B7EDDULL, 0x05F7BD57AA28BD69ULL, 0x08770AFBB995AB09ULL, 
            0xCE3B909EF288019BULL, 0x53C855694D817B9EULL, 0xF7FCE30B35B33721ULL, 0x8E1F6185C722760AULL
        },
        {
            0x9E4568CF2CA02D7EULL, 0xA148F4BB4AED21ABULL, 0xC2A1CB9957432DE3ULL, 0x8B9FFD7BEBE09242ULL, 
            0x12CC4D109F6B6747ULL, 0xD4AC448203B9E731ULL, 0xBC0BE00271E92BC7ULL, 0x2FCE9A962DD8C424ULL, 
            0xCA3496432720EEB8ULL, 0x32C8FC24CFA1EAA5ULL, 0x4C17730CF9DBD0AFULL, 0xBEB62C4856FB9EEEULL, 
            0x82D3F8720FA67CD9ULL, 0x94052EC94ACE61B5ULL, 0x3D36AC02516D2F1EULL, 0x40B2243597489FBDULL, 
            0x78D18362AE45DBEEULL, 0x5D2132A87E6F55F7ULL, 0xA3B8C37AE8D663C9ULL, 0x5249446EE98330D9ULL, 
            0x99EE9BF1407AD907ULL, 0x3B8F953D3DF27C65ULL, 0x1EEF4730AB4A1A6BULL, 0x4243D96A186CF36DULL, 
            0x76B5CAE576E51888ULL, 0x06B076F1D10DC7B9ULL, 0xF745DF959518D28FULL, 0x4DAD442C1DEC1794ULL, 
            0x66EBEE2B5C48A69BULL, 0x660E76B0076D19F2ULL, 0x6B3F7E4A14E64626ULL, 0xC2E67DA3438CFCC5ULL
        },
        {
            0xC046B31D43E95047ULL, 0x044C5BD1820657D5ULL, 0xB89EC49661649E08ULL, 0x3D6536DA4D9B4A03ULL, 
            0x5015BB22E110206EULL, 0xD5675C0FC0E712F4ULL, 0x1A3A41CFFEB6F98DULL, 0x1B9EAFAA10D84AEFULL, 
            0xF540CD4223DE9CC3ULL, 0xDEFF6F6EEA24DA5BULL, 0x9A54B20CC4DFAFEAULL, 0xC53DBD0EB1AE6FFFULL, 
            0xCB102CE9D99C3953ULL, 0x58FA91EF6AB976C2ULL, 0x059B27E56B87D665ULL, 0xEB08B8E956897DEAULL, 
            0x8CEE24F658D16BFDULL, 0x9F69D9E54CF5C598ULL, 0x8919FEFBFEB45189ULL, 0x97409E33FC2A474CULL, 
            0xA053AE5047D3B92BULL, 0x76119A805829228EULL, 0x106A22BF69E2C2A0ULL, 0xB8A0EC5D6C6033C9ULL, 
            0xC7760F720EF36359ULL, 0x6853BFA60D76793AULL, 0x3431A9A797FDFE33ULL, 0x007B641F0271943DULL, 
            0x79F4956E7AE590CCULL, 0x9884A0646EF45602ULL, 0x6A4BF857786785E5ULL, 0xA86BF3D3E94CDF29ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseGConstants = {
    0xD0B2F677F1076EA4ULL,
    0xD93103FE75EC120DULL,
    0xFC46AF47416B527CULL,
    0xD0B2F677F1076EA4ULL,
    0xD93103FE75EC120DULL,
    0xFC46AF47416B527CULL,
    0x04B60305EE221846ULL,
    0xFFA567C373E80701ULL,
    0x32,
    0xEE,
    0x09,
    0x4C,
    0x30,
    0xB2,
    0x2A,
    0xF2
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseHSalts = {
    {
        {
            0x1E9C0893961A1AF6ULL, 0x2CF279BE0D43B1A3ULL, 0x0374371A2B2FD8F6ULL, 0x3DEC51E09D2A1957ULL, 
            0x6CD18D291DB2669DULL, 0x51D4DD10C1B78588ULL, 0x11B9569043A0EEDFULL, 0xF5FD8A56577D5C6AULL, 
            0x96BC0CD80BDEAA66ULL, 0x19AB84B86BE84609ULL, 0x562D4CB25D19B859ULL, 0x2D0B091739AF0EBCULL, 
            0x44371D7788DC55C8ULL, 0x1310C9677B521D8EULL, 0xEF74B2C05E101854ULL, 0xD5AB5E757F473BC2ULL, 
            0x8F7F20511CC486DFULL, 0x260990FE7A644819ULL, 0x4A784B572DD16994ULL, 0x2412A5DEDF32AEAEULL, 
            0xF1562ADA5277C0BEULL, 0x0F2E7298FBEE089FULL, 0xC4C591AE5DC64992ULL, 0x699F35ED0CD92695ULL, 
            0x88A65CF5D1613D04ULL, 0x55AE7CBB6D62C163ULL, 0xEB04AE5A3609EE59ULL, 0xE0090A05A9C1F724ULL, 
            0x929C80E28D9FF4DCULL, 0x0C5A99AFA888209FULL, 0x5D3F60CFAE5A2CDCULL, 0x355DA8BEF8D9BF90ULL
        },
        {
            0x30C10E1382E30283ULL, 0x2003EC5AB0038C3FULL, 0x45AEC9E7CFE23427ULL, 0x658B746F155D581DULL, 
            0x567C90E94E3C37A5ULL, 0x4E42C28EEA6D4F95ULL, 0xDD6A56A8BEBD8147ULL, 0x0302C8B296B41FAEULL, 
            0x6A7FACB76DEFCB23ULL, 0x1D70189DAE5C346AULL, 0x83120D62DDB27D32ULL, 0x243E4472FAC44B6DULL, 
            0x1D43D82AEBA5FC81ULL, 0xE0175B4D3F915362ULL, 0x716D2C44E9C833ABULL, 0x264B5E91EF9449E1ULL, 
            0xF342CCB5159A310BULL, 0xA5931E48B830CB9EULL, 0x1BBD559A6433782FULL, 0x465CD9E672B9A474ULL, 
            0x0F1FC490748C887AULL, 0x24E186BFE1DC6917ULL, 0x1AFB66BF8DAAB269ULL, 0xDD55A46B46ACFAEEULL, 
            0x994134CC0F8FE868ULL, 0x93394457D42868B2ULL, 0xFEBF85C4512E836DULL, 0xBA8A3CC801FFDF74ULL, 
            0x84C8EBC2BF9EA5CEULL, 0x6FD9D494B887CB13ULL, 0xC5C878D76038F181ULL, 0xB24059265743DEFAULL
        },
        {
            0x85D872BEAFA84F19ULL, 0x7EEDFED5762DE5F6ULL, 0x2419A5836F5F84CCULL, 0x250688A274A9B7FDULL, 
            0xE71A618B29AF3F81ULL, 0xC0E719DA55B5A724ULL, 0xC6FE40F10E8CE38DULL, 0xAA74DB74A26A3F55ULL, 
            0xB5C5BDBDCD02FD20ULL, 0xB17F77C50A8C1C47ULL, 0x0BE02CFD9EE551BEULL, 0x7B37FAE2374D90A0ULL, 
            0x1065E66068B36900ULL, 0xDBE309D8DA619FD3ULL, 0x0A101F00612731F4ULL, 0x23132B229580E6D7ULL, 
            0xD9C1E8BED7E8730CULL, 0xE52E36C5D93D5856ULL, 0x22FCAF4D0EA8CD16ULL, 0xD2C3A7EAE9C41974ULL, 
            0x1C1A0AB942E70E0EULL, 0xB8E774144B77D867ULL, 0xCB8590DB03EBF644ULL, 0x53174878CEAD09DAULL, 
            0x31C35613C56D716BULL, 0xDA7CA8F59D14F77EULL, 0x8F83B6A69C5FE831ULL, 0x50F57CE5C768DDBCULL, 
            0x08C64B90175F150FULL, 0x556C8E227589E1DAULL, 0x63F2624D03650C5DULL, 0xA2ACFBB407D8AAE3ULL
        },
        {
            0x69BE01A6E1DAE98AULL, 0x2C0CF2C1F6C1601FULL, 0x8E15455EA67D4054ULL, 0x8B45E3DB678F2414ULL, 
            0x82C114750389F31BULL, 0xB511AA33B46CDAE9ULL, 0xA9CA7065A5AC3BB0ULL, 0x6163F0D588DA3A56ULL, 
            0x24B049D390F20E90ULL, 0xD5F33D5286679251ULL, 0x72938645527A86B8ULL, 0x213CECF7B3B1D310ULL, 
            0x4BF0562D3AF9570FULL, 0xEF75568F08F12B73ULL, 0xA1FACCA2245B7BF0ULL, 0x599C84F37758B405ULL, 
            0xF8858B7825321098ULL, 0x2413F90185F148E6ULL, 0xC2F5037E90F87D90ULL, 0x1143B8B6F9E5E7DFULL, 
            0x49712CA6F0F95047ULL, 0xFE047D08E61BFFEBULL, 0xA1A0E3DBB50EFFA7ULL, 0x0B54909F3BC5DA7AULL, 
            0xE1D430AECFFC740DULL, 0x23BDAE9FE98A4488ULL, 0x05FECC5BC82B77CDULL, 0x4E25540C8710758DULL, 
            0x1932EBF2FE1B4CC6ULL, 0xC9480E985DF0FB54ULL, 0xF148ABE71B7FDBAEULL, 0x92F351BAF09DE524ULL
        },
        {
            0x93341B5049620DF3ULL, 0xA1F0E9BE78F56101ULL, 0x108127C3937DEC05ULL, 0x0C6E4391D0FC9CD2ULL, 
            0x29FCC2A5B4CCC9E4ULL, 0xCF38D38A2E81A701ULL, 0x669C3FEAA3E9545EULL, 0x6752C9197EC7EFD6ULL, 
            0x9C3A705E62DC5B15ULL, 0x3382BA63B771BB90ULL, 0x4F69BED46997AD53ULL, 0x3DCBC3FD11889A8CULL, 
            0xFCAEA0338A1515A9ULL, 0xB0FC895281E95514ULL, 0x9704C2BC8F224009ULL, 0xFF9CA0E967B7C060ULL, 
            0x66A9687F9F248A52ULL, 0xAFED1F78B5F066B5ULL, 0x9A1FEEA769EBB13EULL, 0x7B2832BF7066695FULL, 
            0x5A2FE4D0970E02BBULL, 0xD585166A20C76F2FULL, 0x8E7D80CBE811C6D8ULL, 0xC55DC03C0AF47274ULL, 
            0xA895E5C8EDEE049FULL, 0xC45160BEBADA0E78ULL, 0x91B6A3DD2321BEA6ULL, 0xF8CFB4052E4C97A5ULL, 
            0x1E61C80CAF46AF81ULL, 0x6BB08C60FE5AF7DCULL, 0x4356B28FAE2A5034ULL, 0x5E6FCC3610EAAF76ULL
        },
        {
            0x0ED9BF991DF00B41ULL, 0x461E8EFDB8485CF4ULL, 0x411F1E32FA2C8F4EULL, 0xD56EEB135789E1FCULL, 
            0xFDEEEFE1922D0872ULL, 0xEB61680A25445A51ULL, 0x609C4B51071A9DA6ULL, 0x42DB4F93AF1CA34FULL, 
            0xA60B1688D7093198ULL, 0x7E8AFB3534C72EEBULL, 0x5E346CA7E6319C0BULL, 0xC298CE256EBC05E6ULL, 
            0xCE1BF3382572D3EFULL, 0xE412C5640E33AD36ULL, 0x1CD158B6804511F7ULL, 0x5DD93CBDAF9D6D64ULL, 
            0xB0A7F3F074AE42C1ULL, 0x6A01D12CC849DB36ULL, 0x459367BDA8C34C19ULL, 0x4691123259CFC870ULL, 
            0xD364972C4F1634AEULL, 0x960458EFF32BAC03ULL, 0xC572A0BB8F7EE143ULL, 0x2FDA2C86F9E15F0AULL, 
            0xF4629769C7B4E296ULL, 0x00B4F89049D2B57CULL, 0xF6EF3967ACB9533AULL, 0xFE781F611EBD0A7EULL, 
            0x640ECC176D6FE79EULL, 0x3FB0D6186184A0F8ULL, 0xD1D7B3AA497FAF2AULL, 0xC1C0639AA70EDDCEULL
        }
    },
    {
        {
            0x4A00D165F60F0ACAULL, 0x53EDFB9AABAD784FULL, 0x0D4E3503AC9338C0ULL, 0xDD39C7E7FA5F9BF1ULL, 
            0x3D52DFD3DC85B16AULL, 0x81AAFD7A45A5BD47ULL, 0x029D1B01AC24C739ULL, 0x0A227129232FEBE5ULL, 
            0xD1519FA4FEB0CFEFULL, 0x96EE6C38DBB04376ULL, 0x1D25726FB29B528BULL, 0x02F63A6F1E66F6C3ULL, 
            0xB66B77DF53220689ULL, 0x9E98C67EECA14A57ULL, 0x396E36C71C666D0DULL, 0x2440F7353128BF88ULL, 
            0x219BD9E85D1AAF9FULL, 0x1C2023B561464351ULL, 0x9EA3168E62B6964EULL, 0x57D44C6A5B7BB8B5ULL, 
            0x1DAC9E4CF0A52952ULL, 0xFD45E5C80A32E62AULL, 0x334D0AA4CC60855FULL, 0x9DF98DB024F469A5ULL, 
            0x87E2DE81E7B3C29DULL, 0x337DE4A2B9A42294ULL, 0x10F802AE0D850AF5ULL, 0xF6F3B69FA215B96DULL, 
            0x4F2326C340862F85ULL, 0x6C2106592B90E1F0ULL, 0xABBDD97452C43351ULL, 0x288C1FDC346F9649ULL
        },
        {
            0x659982F787B2A3A5ULL, 0xF81A7703FAC634B6ULL, 0xB3D1CEEDD2CB6466ULL, 0x934652E7FBFFA845ULL, 
            0x3E5571410D1F8D7FULL, 0xAB00D10AAB6B8D3FULL, 0x2E5AF7F22EE3C510ULL, 0xA45D76D9F7E4B97DULL, 
            0x41F084DC944BF435ULL, 0x6CBD7660F06DBF01ULL, 0x62EBAD5701AF5F43ULL, 0x77AF142B82B54DF9ULL, 
            0x212E76C5FD0D3D7CULL, 0x450261AEA6C4FF74ULL, 0xD0EE039258D338A3ULL, 0x5045EA0255B9E732ULL, 
            0x30A694C61EF66781ULL, 0xF332BAF2CCDC6777ULL, 0xE59EC1337806C51DULL, 0x9DAEEF2F46FDD2EAULL, 
            0x45E0B8A6164CA317ULL, 0x0DB407FD24D81B2CULL, 0x32CE3B9D1C3DA87DULL, 0x8D0F2864656D8068ULL, 
            0x6DA284E1A6FF5A09ULL, 0x1700206DEDFE8C03ULL, 0x473D3104A64546C7ULL, 0x35B73587ADDF2284ULL, 
            0x2D9A43C204DEBC6EULL, 0x7E29F6CCEA566604ULL, 0x428C6A18F1890378ULL, 0xBC66AD2DAC304930ULL
        },
        {
            0x38925C6CD9E22B85ULL, 0xAC51F2977EE6191EULL, 0x68FAB2A28BBFCF9DULL, 0xBD8D7C0EDF8CD3C7ULL, 
            0x15C575641920DA7FULL, 0x47FF0D77A99F8BD2ULL, 0x04635A244888745AULL, 0x139C3E836335B75DULL, 
            0x35316116C4B91D09ULL, 0x5F18A16DCD3C4B27ULL, 0xA22E52C15D4CF8FDULL, 0x7316F6E813884B57ULL, 
            0x43EDF650AFC2C31BULL, 0xA2AF6DDCA1EF9DADULL, 0xC37760E032A26FBFULL, 0x2DED2CCE8CE2D1B2ULL, 
            0x54DA7F28036FE1D5ULL, 0x0029CA584D09871EULL, 0x4CC04DE82FC5FDA0ULL, 0xE266D18E474E29DCULL, 
            0x170EAE60DC878262ULL, 0x3E11CF0AC81B78F5ULL, 0x46FDE84FA481D60CULL, 0x9FD7130941AA8357ULL, 
            0x1357286A8D728BCCULL, 0x8790A800C77A96E9ULL, 0x522CBF86F9210DF0ULL, 0x2F688D3051975FE8ULL, 
            0x846DAF215484B4DFULL, 0x592EC642BD8736AFULL, 0x7DCD88286C251EFBULL, 0x5B9CC5282C7974F6ULL
        },
        {
            0x531B0361E33EB949ULL, 0x3C35A0DA08B9B17DULL, 0x93AF0CCCD19688D3ULL, 0xF4C8186D2A4DF5BFULL, 
            0xF551724D7BB3F047ULL, 0x486344CAEA7572D9ULL, 0x8E10C0091E27D0F6ULL, 0x593E70DD233A97B8ULL, 
            0xDCCF624B4D86117DULL, 0xC81BB00F713F949EULL, 0xE8853D1DF873709FULL, 0x2CF71D3C6AE43F01ULL, 
            0x32FBECAFBCEE34EBULL, 0x89146A005A078F73ULL, 0xD45F19A8E3856530ULL, 0x3E2228140BD76D65ULL, 
            0x07A6F7828FED50CDULL, 0xD60D84DD4C2EF5D6ULL, 0xB940E6A24096245BULL, 0x4F1B1887127D742BULL, 
            0xC330101E982A1026ULL, 0x13A53B71275D5CE1ULL, 0x7C152920640B0348ULL, 0xE206CF61811DB174ULL, 
            0x984759DB9F5D18CDULL, 0xC8BF4ED44FA1349BULL, 0x00685E832237D6CCULL, 0x5348660896ABEA98ULL, 
            0xE69C8ECB8B0A0642ULL, 0x837833BC80091AE0ULL, 0x8C719D551890794AULL, 0x3D987733AD406D05ULL
        },
        {
            0xD5956E4B9D38EFB6ULL, 0x3014E4DF14BF19FCULL, 0x3A23AB0B67154293ULL, 0x010A69A3728508ECULL, 
            0x3DE803983013E5B9ULL, 0x01717400C84EC7A7ULL, 0x326B9DBD38311E3FULL, 0x5562435946A996E3ULL, 
            0xE641F25BA90441FAULL, 0x99001B87C9FC4A64ULL, 0x3A2DE1D75C3C4564ULL, 0x56A2936F7FF2E7DDULL, 
            0x304DB40D547E8CD6ULL, 0xC4A2411FEF0C9812ULL, 0xAEC77FA6FDB969B3ULL, 0xC364F9AACA967CA8ULL, 
            0xC60220199CF4A2ECULL, 0x48F13992F86E7508ULL, 0x26E445469EDC7057ULL, 0x8EED349952E6B173ULL, 
            0x645B6026BDB310F2ULL, 0x402FE5060557E8F8ULL, 0xF67C53A03BA563E1ULL, 0xA24148D90404CEBBULL, 
            0xD4E9DB7DB31A326DULL, 0xDDF0F56A14CC4CB6ULL, 0x7A88D46EC591A3BEULL, 0x4AA229384FBE2A71ULL, 
            0x54A126174361861BULL, 0xC49C7A606F030BE7ULL, 0x29D4EBE883AF883EULL, 0x403E5F58C0D4AFAEULL
        },
        {
            0x316938741BAF0351ULL, 0xE82721AB405579B5ULL, 0x586F5E305A2BE595ULL, 0xD4B44E90736AA45DULL, 
            0xD4A7FA06C93E0FA1ULL, 0x197ED6F3808E478DULL, 0xDC9FAADAE6B048D1ULL, 0xBAC3F9727E75F17BULL, 
            0x20334275D2B58992ULL, 0x941B05B91F6C82F5ULL, 0x06F40C964B30DA48ULL, 0x9E815AFD86F30249ULL, 
            0x63506D2B5CBF645DULL, 0x779A62BB6829E642ULL, 0x86A7006EE2250252ULL, 0x2C287CDCF85C582DULL, 
            0xEE14164D2AC07C71ULL, 0x9B83C7D4C721EBD8ULL, 0x6A4974BDC06F5D38ULL, 0x7ADDF926E26166E7ULL, 
            0x85FB749609328930ULL, 0xBBC9A2A0F3BAA00AULL, 0x5795F6EAF7ED2A74ULL, 0x7CA26A5196D34484ULL, 
            0x4550D4942A9A399FULL, 0x4B1C4CA6709AC13CULL, 0xC6D2E5FEBA4286F6ULL, 0xDE86B7B30D95BCDDULL, 
            0x39608D9F554CE6ECULL, 0x4F0EAC1F7855E3F1ULL, 0xE8FD6DB192B5CC8DULL, 0xA2A6C2C5F5DD0527ULL
        }
    },
    {
        {
            0x2AAA7F3E3739EDC0ULL, 0xFE0C93F8B4A743CDULL, 0x284CCA14B53FE85FULL, 0x57D4A07277759CFCULL, 
            0x50AFE7A4509D4571ULL, 0xB51160EF8E0C13F0ULL, 0x69573FFAEAE0C7C3ULL, 0x0FD14ADE10AF9252ULL, 
            0xC8CB8A13E4807917ULL, 0x3D10F3B7EED94359ULL, 0x1D2CF32EDB8FA436ULL, 0xE716407364F3483AULL, 
            0xE43E71D4172F9BA7ULL, 0x92FF387C7B443731ULL, 0x96029B54D8A46D2CULL, 0x59CBC85D72FF885EULL, 
            0xE11DB3EE369A62AEULL, 0x2ABE9E526C39CE61ULL, 0x81FAFD380D8F245CULL, 0x4D044CC3D27C4C72ULL, 
            0x4074DA1E7A74049DULL, 0x4785DC6467D6F85CULL, 0xBD1E200B58CF83E7ULL, 0x628AF5B7C3C203A9ULL, 
            0x2E821EF2D0C367A2ULL, 0x22903961DE319D1FULL, 0x0AEDA3966661EE1CULL, 0x706B68C5FB2F7569ULL, 
            0xDE655CD149CA259CULL, 0x04297117707F4F53ULL, 0x34964CF5E9117384ULL, 0x34C8230405AAE39EULL
        },
        {
            0x387B4C9905A21B03ULL, 0x03B97F3852088E84ULL, 0x48610A7E1EBA1117ULL, 0xAD186B313469230DULL, 
            0x373C51281E4C2F16ULL, 0xEB4B5B04BD8F2C28ULL, 0x07F758783D04B179ULL, 0x1CEF6CC12C08A091ULL, 
            0x3F86E9803E19FE9EULL, 0x276EAEA731181DF4ULL, 0xC222D279E5797C8BULL, 0xE6DCED97F1613FC2ULL, 
            0xAD2B0074ACCA37C1ULL, 0x156F1BBA5A6105C0ULL, 0xDC47CFFC2687054EULL, 0x1784971F1BA223B5ULL, 
            0x1141F051C9C18003ULL, 0xD7067742AF034AACULL, 0xA93CC423FB0975DDULL, 0xB6B1E0B64D12796EULL, 
            0x32958E770A679EDBULL, 0xC5398A8996787E8FULL, 0x9F3482EA495EBDE6ULL, 0xA2F59DB3DE7A4FF6ULL, 
            0x401B198AF0079E20ULL, 0xF0BD49A844C368FAULL, 0x9691C6D641E6DB3AULL, 0x1D7A5DCD3CE1B10AULL, 
            0x82C9FB6660E2E35CULL, 0x22A1C34FB2137443ULL, 0x666F595F5FDA30E5ULL, 0xE71677B88373C263ULL
        },
        {
            0x1EDE7E0217BFE177ULL, 0xA0DF1F0FCBE3F68DULL, 0x6D5CC8C828FBF7BEULL, 0xF29579A8228A0DAAULL, 
            0xDFBD582B5C0A86F4ULL, 0x0F1A5A767E60494BULL, 0x195B4664A8DCF839ULL, 0xBDEA45B1778F9FCAULL, 
            0xD49043C5EA8ACA08ULL, 0x7CC812DFC1517F2CULL, 0xD2FFC87DF52DDE7EULL, 0x9CE75048213AAFA4ULL, 
            0xB8A03730372AA17EULL, 0xC227E40E038AC7C1ULL, 0x575F4FCEC319576CULL, 0x06E05BDFA282C1F2ULL, 
            0x49B08202076DD81EULL, 0x5B4BE7ECE8F1BF75ULL, 0x7D7932DE2DD9E797ULL, 0xCB43F811DD2EE9DCULL, 
            0x486A086627BED258ULL, 0x5A38E5A80BE2F4C2ULL, 0x98C0C92B46EB08AFULL, 0x2B8FC42D69DEEE99ULL, 
            0x0C8B035279494F85ULL, 0x82520A5C6918130CULL, 0xA499EFDCFEAA3A93ULL, 0x04D5733D9A1B7426ULL, 
            0x69755807CC1B6C7AULL, 0x9DF7A511994F813FULL, 0xF745A435340DF3B8ULL, 0x30A030037A812F80ULL
        },
        {
            0x151D5B46D5DEB54FULL, 0x7F604708E56E6D20ULL, 0x1CE3C1EEDFBC45ABULL, 0xE82306A90C3D2F35ULL, 
            0x45B6C5F523E84309ULL, 0xF421884371DC1705ULL, 0x008779285F57F05CULL, 0xE50D11330D8AE202ULL, 
            0xC1D34FAE2072D7F8ULL, 0x6848F4156199F3D0ULL, 0x5CA593D9FBE31DA2ULL, 0x1051DB3DADA489B2ULL, 
            0xBD529FB254C4CD28ULL, 0xD0D5FC4BBDD49C0CULL, 0xF5F002693469085FULL, 0x3A4D9BA73EBDA701ULL, 
            0xBA134B3F9158EFEDULL, 0x6687A7A80C487A81ULL, 0x7472ACF20A94EEC8ULL, 0x83966C4D7C33C96AULL, 
            0x5B00BDEC59BD3482ULL, 0x35D763B689B66F4EULL, 0x64F98B056AE31164ULL, 0x0EA698BC8A68C15BULL, 
            0xAEBAF21FB6637ADAULL, 0x3F5E0DD9EF0096E8ULL, 0x630D5D3934781FC8ULL, 0x01BF3A16DC8C0850ULL, 
            0x07268CC650651660ULL, 0x77A4674D34A8EDCAULL, 0x9F114E14A5AA070BULL, 0xB30E637C31A7A81FULL
        },
        {
            0x51E5F65B8BE119BEULL, 0x7F6BDE8DDC869D54ULL, 0xB4CDA123756BAB03ULL, 0xCA4FEB6AE9A09214ULL, 
            0x1F12E9E15F0E4E35ULL, 0x737A2E8B50D463A8ULL, 0x905891459D87FF97ULL, 0x3B087357937E4A64ULL, 
            0xFBE942FC8A8BD915ULL, 0x93C02D3A139D1F7EULL, 0xA8299FADCE119629ULL, 0x1D23B5A1D322FCC1ULL, 
            0xD10B4135B7641272ULL, 0xD346656B677AB961ULL, 0xCA11825704A922ACULL, 0x4736688C8050F8F1ULL, 
            0xECF360573FCBDF75ULL, 0x21C2260062F0B055ULL, 0xD0FBA3AAEFAA71CFULL, 0x537E5FC5C4C32240ULL, 
            0xAA3AE94146BFA6B6ULL, 0x9DFBD408E22AD967ULL, 0xD306014BC4E87C98ULL, 0x16BA361B902D3C44ULL, 
            0x92195919F1E028E3ULL, 0xA3E57A7096A0B25FULL, 0xD12653D6845D816FULL, 0xFEE934227FC75A57ULL, 
            0x48B7E82311B7EAE4ULL, 0x931F4368797C384AULL, 0xB5FCBD34749BF234ULL, 0xB261AAA95F1BADDBULL
        },
        {
            0xDD04F28DF2C76E7AULL, 0x73B00419EB102F76ULL, 0x0EB123E191B9EDADULL, 0x594BC7527E4D806BULL, 
            0xEE7C08235BF22939ULL, 0x07112748A18E4E52ULL, 0x532EB8C7D63AB05CULL, 0x5A94B140E3CBE364ULL, 
            0xA84CDD8686D9FDD1ULL, 0x1E88AAA792C25497ULL, 0x72F65CA1A45EF5B8ULL, 0xC0CA2C6C7C8EF8A9ULL, 
            0xD963F2FEE7024CF2ULL, 0xA5A01E45FD33B8ADULL, 0x9A4F1CAFC7D32EADULL, 0xCD8E71AEB43EE86AULL, 
            0x118D934E9BABA8B0ULL, 0xBCC36FD395CF03C9ULL, 0xCFCE45CF57E4F093ULL, 0x0AAB0D13A337CC36ULL, 
            0xC1752E564C9A64D8ULL, 0xD0D3897F7649E9F1ULL, 0x0AEFD2E06C599BFEULL, 0x3546F60959A0172DULL, 
            0x7D15AB260F86D326ULL, 0x1BBD9FAD3DC05A91ULL, 0x3121FB0A33776CD1ULL, 0x59E71BE87DBD9B37ULL, 
            0x4A38FDB3BADE46DEULL, 0xA0555C5D1562B6D6ULL, 0x5A34F2D096FF3DAEULL, 0x0BEFC3C5BF191740ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseHConstants = {
    0x12C11605F249C83FULL,
    0xCEBC5BEA54421961ULL,
    0xDB92D6BA50766AB9ULL,
    0x12C11605F249C83FULL,
    0xCEBC5BEA54421961ULL,
    0xDB92D6BA50766AB9ULL,
    0x8EEAAA27190E3A71ULL,
    0x93802F35BECEAE4BULL,
    0x47,
    0x45,
    0x34,
    0xF0,
    0x3E,
    0x3B,
    0xF8,
    0x15
};

