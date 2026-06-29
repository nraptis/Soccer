#include "TwistExpander_Cricket.hpp"
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

TwistExpander_Cricket::TwistExpander_Cricket()
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

void TwistExpander_Cricket::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB5A5B11F5A2CFD7EULL; std::uint64_t aIngress = 0xFF71F221F9A025F7ULL; std::uint64_t aCarry = 0xC306C51D7CC24964ULL;

    std::uint64_t aWandererA = 0xE2D5A5D9DD6ABA9EULL; std::uint64_t aWandererB = 0xB3023CBD50A4C447ULL; std::uint64_t aWandererC = 0xBB3FB4AD22E65711ULL; std::uint64_t aWandererD = 0xB38AD5B0C848E7C0ULL;
    std::uint64_t aWandererE = 0x88E73F60BE51E135ULL; std::uint64_t aWandererF = 0xD4CAE30AEAF2560CULL; std::uint64_t aWandererG = 0xC7408A235ED5F059ULL; std::uint64_t aWandererH = 0x9818EB0EA0400DADULL;
    std::uint64_t aWandererI = 0x9B8539018F52A6C6ULL; std::uint64_t aWandererJ = 0x97E3D042430A0738ULL; std::uint64_t aWandererK = 0xCD0A999EFE4D7212ULL;

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
        aPrevious = 15675430206452650329U;
        aCarry = 10050068768029648794U;
        aWandererA = 17978157220032911207U;
        aWandererB = 10324053975251403571U;
        aWandererC = 14010282482382791135U;
        aWandererD = 9958804919618219651U;
        aWandererE = 12778656038067231347U;
        aWandererF = 11086694226740139831U;
        aWandererG = 13763398243814519748U;
        aWandererH = 11091282486579044213U;
        aWandererI = 11720240010343556316U;
        aWandererJ = 13398762520622035793U;
        aWandererK = 15764557055980721923U;
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
    TwistExpander_Cricket_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Cricket::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x805119268254D532ULL; std::uint64_t aIngress = 0xD9EE53B4758AEBB4ULL; std::uint64_t aCarry = 0xACC88EC152C14163ULL;

    std::uint64_t aWandererA = 0xE6E54418E702F3A7ULL; std::uint64_t aWandererB = 0xBA14EAC61F05A5A7ULL; std::uint64_t aWandererC = 0xC7EE8FB4EEB661BDULL; std::uint64_t aWandererD = 0x82F8F5BD1DE354F7ULL;
    std::uint64_t aWandererE = 0xABD3DAE6CFA55F88ULL; std::uint64_t aWandererF = 0x96B8308BC9DA1358ULL; std::uint64_t aWandererG = 0xC67EE8878709FFEBULL; std::uint64_t aWandererH = 0xB0E5D3A5D9D19552ULL;
    std::uint64_t aWandererI = 0xC3D87C8DCBDE1586ULL; std::uint64_t aWandererJ = 0xA18B64F80D36A954ULL; std::uint64_t aWandererK = 0xA1BA69D09C5A5E1EULL;

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
        aPrevious = 14298757226904871523U;
        aCarry = 12425546140382849393U;
        aWandererA = 11697464953732121282U;
        aWandererB = 17290117641213047795U;
        aWandererC = 17448226444697946631U;
        aWandererD = 14788135795467502337U;
        aWandererE = 10609077071604820532U;
        aWandererF = 9624645958679107510U;
        aWandererG = 11092822978165569183U;
        aWandererH = 16487356084259520223U;
        aWandererI = 13888794687994105741U;
        aWandererJ = 13150709464848122643U;
        aWandererK = 14706617838668018744U;
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
    TwistExpander_Cricket_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Cricket::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB5DFF1F1192939FAULL;
    std::uint64_t aIngress = 0xA59AC9BA16129FE4ULL;
    std::uint64_t aCarry = 0xB0FD8E3F3DD99D30ULL;

    std::uint64_t aWandererA = 0x8F9C625FCBF5117EULL;
    std::uint64_t aWandererB = 0xA15E7F5D97E0F21CULL;
    std::uint64_t aWandererC = 0xC0E0CA33E2557E42ULL;
    std::uint64_t aWandererD = 0x91C4CC3278AE1BF2ULL;
    std::uint64_t aWandererE = 0xF5CD00B034386649ULL;
    std::uint64_t aWandererF = 0xB9F09EA9EEA78EE4ULL;
    std::uint64_t aWandererG = 0xD6BC4CB79D68C909ULL;
    std::uint64_t aWandererH = 0xF9D262EF27D27182ULL;
    std::uint64_t aWandererI = 0x95BDB99B86FD3E7EULL;
    std::uint64_t aWandererJ = 0x95CBE38CB68A82B5ULL;
    std::uint64_t aWandererK = 0x8C83974D6C29B5FAULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneH);
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
    TwistExpander_Cricket_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Cricket::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE61FBE533FBEA1ADULL; std::uint64_t aIngress = 0xFEA8880E9C0E7251ULL; std::uint64_t aCarry = 0xC398F08B02BBBB39ULL;

    std::uint64_t aWandererA = 0xEAD1B590142BE7A1ULL; std::uint64_t aWandererB = 0x8A913105475F42A6ULL; std::uint64_t aWandererC = 0x8F6B74F5030D6C5EULL; std::uint64_t aWandererD = 0xF67F62B111D84C03ULL;
    std::uint64_t aWandererE = 0x9891122CBEBCBF96ULL; std::uint64_t aWandererF = 0xFA6A1F3F2AFEE09DULL; std::uint64_t aWandererG = 0xD0CBBF83D83BD862ULL; std::uint64_t aWandererH = 0xF39DFFFFF4111E73ULL;
    std::uint64_t aWandererI = 0xABFFDB4F5E166995ULL; std::uint64_t aWandererJ = 0xEDF8967CFFFBB125ULL; std::uint64_t aWandererK = 0x8F67145F7402F8EAULL;

    // [seed]
    {
        aPrevious = 15428681826663691436U;
        aCarry = 15172599322548005207U;
        aWandererA = 13784555397455549478U;
        aWandererB = 14998237682398072730U;
        aWandererC = 14069971990145977868U;
        aWandererD = 10834315158462355854U;
        aWandererE = 12281671318346540141U;
        aWandererF = 9918873003550528183U;
        aWandererG = 12630170044806575073U;
        aWandererH = 13809893943801426727U;
        aWandererI = 15875786847560364635U;
        aWandererJ = 12753045261989840002U;
        aWandererK = 18378161380313885947U;
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
    TwistExpander_Cricket_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 0, 3 with offsets 3189U, 4619U, 892U, 6807U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3189U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4619U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 892U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6807U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 1 with offsets 6084U, 5785U, 7535U, 7503U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6084U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5785U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7535U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7503U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 1, 2 with offsets 874U, 7046U, 7596U, 2896U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 874U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7046U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7596U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2896U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 3, 0 with offsets 2356U, 7554U, 21U, 4667U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2356U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7554U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 21U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4667U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 351U, 1249U, 1109U, 1838U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 351U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1249U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1109U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1838U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 1, 0 with offsets 936U, 1898U, 333U, 725U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 936U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1898U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 333U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 725U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 2, 0 with offsets 818U, 1924U, 388U, 863U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 818U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1924U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 388U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 863U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 1, 0, 2 with offsets 1441U, 816U, 753U, 151U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1441U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 816U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 753U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 151U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 941U, 908U, 833U, 271U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 941U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 908U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 833U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 271U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Cricket::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 3 with offsets 1857U, 588U, 6573U, 7055U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1857U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6573U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7055U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 2 with offsets 7862U, 4556U, 5325U, 1091U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7862U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4556U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5325U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1091U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 3, 1 with offsets 5021U, 8110U, 4456U, 5295U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5021U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4456U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5295U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 0 with offsets 6514U, 6341U, 5525U, 1167U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6514U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6341U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5525U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1167U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7328U, 1426U, 5613U, 1746U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7328U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1426U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5613U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1746U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 871U, 1421U, 585U, 2045U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 871U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 585U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2045U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 914U, 247U, 1248U, 618U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 914U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 247U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1248U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 618U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1856U, 1693U, 1828U, 799U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1856U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1693U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1828U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 799U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 896U, 209U, 1166U, 1605U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 896U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 209U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1166U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1605U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 2, 0 [0..<W_KEY]
        // offsets: 628U, 1464U, 1212U, 56U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 628U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1464U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1212U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 56U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseASalts = {
    {
        {
            0x578CABCA91559218ULL, 0x8395CE785C8FD141ULL, 0x46F1804845F0CB82ULL, 0x4CAD8490070C40E1ULL, 
            0x86723B7E959FF1E1ULL, 0x9CF00F59498427FBULL, 0x3AE4BC56A8456B28ULL, 0x5C116031B22A1DF6ULL, 
            0x5416B84C315A9D99ULL, 0x4A771037898C0D4EULL, 0x808AC7FC457F7EFFULL, 0x3A1400503A509E06ULL, 
            0x9A280A88BA97BB68ULL, 0xECFE9AED56BDE30DULL, 0x6FBBD71DDB974690ULL, 0x61760679655607D8ULL, 
            0x19B4B491CE6AF48AULL, 0x656A11DE82DD2778ULL, 0x7C6DB495E650AA09ULL, 0x8F9356FFCAF97F2DULL, 
            0x0D64935A51122F7EULL, 0xFB001773CAFF154EULL, 0x0C4D7958233D9FD1ULL, 0x7AC0F99CFCD9A17BULL, 
            0xF2C6616DA8882408ULL, 0x72B5119A850FBEAEULL, 0x77E9353696401905ULL, 0xFF627A8A3696EE60ULL, 
            0xF608156C760434C7ULL, 0xCBD055A5779555ACULL, 0x2AA4C2EF598E503CULL, 0x208DF556FB73D36AULL
        },
        {
            0xE6DFD475844685E2ULL, 0x9A58FD1630AC8D1CULL, 0xF44B8C4CF841BE44ULL, 0xAFF98D396F4C1A56ULL, 
            0x6A60496D8F198864ULL, 0x1CCCEE98DF9396F6ULL, 0x3B6D5587F352742DULL, 0xEA05626A73FC6781ULL, 
            0x2DC89E88AAD2F044ULL, 0x1A0CD54A0B75E927ULL, 0x92BC18BA75B8A617ULL, 0xAD3FC6F0BCD67293ULL, 
            0xBB528BA55C33C98DULL, 0x290EBFF39D9F7ADFULL, 0x2390B710FDBE665CULL, 0xA16889A3590C9E66ULL, 
            0x3AF2F65441FF55BAULL, 0x97957436DE48E7E3ULL, 0x242F53A9CF468015ULL, 0xEC3A202F44A6B412ULL, 
            0xA444AFEA5523D12BULL, 0x59B4C8D8DD10301BULL, 0xE81370BE4D300E25ULL, 0xB43C024F8CD2DB3DULL, 
            0xE7367993145A84AFULL, 0xF33A64901E90B303ULL, 0x26326C6A23A3AFF1ULL, 0x62E37F83F8BFE31DULL, 
            0x74D09093F9ACE1BBULL, 0x0ACEAFD2DCDE3762ULL, 0xA63223DF16E1247BULL, 0xCEC865AAE1A38FC1ULL
        },
        {
            0xFFC64F6FB8B137F6ULL, 0x2BA71240E63A930BULL, 0x0FDF4DCD23D84D1BULL, 0xEEAF9DE8584E8EF5ULL, 
            0xD1E6726C03FB5A14ULL, 0x9D84F83940D7AE4FULL, 0xFB6F90563E681C0BULL, 0x53D3166A817A4EB0ULL, 
            0xE78FF8085C5BF8EAULL, 0x8AFC79DD72A58452ULL, 0x2B21054C958DD3E3ULL, 0x90580150E72B92A2ULL, 
            0xDC82A329F4D0498EULL, 0x6B45348001D49738ULL, 0x99811FB0689C64E6ULL, 0x1532D5B4F4EF3C7CULL, 
            0x315EE3E64570D2B1ULL, 0x2063F2F4287DF097ULL, 0x4CEB1C309F11296CULL, 0x2FA9343E18596649ULL, 
            0xC53318CE7CE5F806ULL, 0xA6961E1668AFC668ULL, 0xC72DC8AAA1514D84ULL, 0xD7C99F52A3A5EF2AULL, 
            0x4963B3ED315D2243ULL, 0x660B8204A5F19DFAULL, 0x9217307A7E89EB18ULL, 0x2C8A92BA8EC3F1CAULL, 
            0xCE9A0CBD3427A375ULL, 0x7913F432C0074AB4ULL, 0xA33B9164AEB9BD26ULL, 0x713149DD4491B7CDULL
        },
        {
            0xE417C590912CA845ULL, 0xE16530D687A280ACULL, 0x604123B14022F7DFULL, 0x143389D4590CB8DBULL, 
            0x09BBCBF2CB945BC0ULL, 0x6DEC4907E29773BCULL, 0xF0A3E101F44A2957ULL, 0x3CD6B4C68DADDFBEULL, 
            0xD20EB1FC5EFB32FDULL, 0x84593D9FCDC89A5DULL, 0xBCA6EEE57AB4F8C3ULL, 0xA77B32CC971D2081ULL, 
            0x27CBA739B9007806ULL, 0x60F6C8319E6A3676ULL, 0x7E7D6B87D4D7A68BULL, 0xE91358F1CBF48EF0ULL, 
            0xA12396F25DECCC9DULL, 0x3C575A769D6B1FC7ULL, 0xFF2775906E7AC611ULL, 0xCCBF79194EFFAF6EULL, 
            0x7EA6A96F31A55354ULL, 0x79BCD5324DA7341EULL, 0xA333BD14D74523ADULL, 0xBB90B193F8AB2429ULL, 
            0x251FD4951ED692C3ULL, 0x23C6D7B616959F4BULL, 0x0156A3F7C3245C0BULL, 0x02636FCC34C8B39DULL, 
            0x6EF7BF2A259F752FULL, 0x0DCC0A7272637A02ULL, 0xA2061B91340ACA27ULL, 0xFF9C48FAA12ED17DULL
        },
        {
            0xE157868629EC662BULL, 0x2CF883ADD3414EF8ULL, 0xCF718EBB69CE6F06ULL, 0x3A4814BB71C96260ULL, 
            0xFBD273584AA336A6ULL, 0x14A85C4CAE124BBCULL, 0x1D9D601D43D718A8ULL, 0x88893F935B936842ULL, 
            0x9A404966E7E1512CULL, 0x0664156BCB357FDFULL, 0xCDCE271220DB88A8ULL, 0x8D3C819E7A7EE20BULL, 
            0xCBDD2321DED013C2ULL, 0xD2C4F1BA9B1E5E66ULL, 0x699F150D14415B98ULL, 0xB38D5083869A6503ULL, 
            0x90990448D62374C5ULL, 0x33B1D09F29FDA9B4ULL, 0x80EE1448CDE05936ULL, 0x4591A7ED3241A54BULL, 
            0x8111E6DDBFC88BB1ULL, 0x700D187F632DA6DBULL, 0x5E3D6C18F651D228ULL, 0x3C9FFCEB6B60E77CULL, 
            0x834AB0223C54ECBCULL, 0x638D453F6268EC11ULL, 0x5C1CAF1CF9E22209ULL, 0xCDA592ACE0B7034DULL, 
            0x3AC6C6DA03646316ULL, 0x83B2AD0083F1CB6AULL, 0xB2C43B0843303821ULL, 0xDD5392ACA2013195ULL
        },
        {
            0x6888008251EE5D58ULL, 0x1EEB4C90A0B73890ULL, 0xD3A67C51ECB44861ULL, 0x592EE6AB6EB6E85EULL, 
            0xA6FC3EF2C16658DCULL, 0x2EE14384E7B95B85ULL, 0x33A3823089BEB890ULL, 0x06F95C47D8E4EA81ULL, 
            0xEFCC1F9199F55EEAULL, 0x0BB2CDBA253E9CB9ULL, 0x1834D98FF23F914FULL, 0x20D26B03AD6B8912ULL, 
            0x62E42EB6781902F6ULL, 0xA683957FE456DC31ULL, 0xFFE1EFC9ED81451FULL, 0xE78FB833A24640F0ULL, 
            0xD452C55ED726294EULL, 0x004CEAC4691D579EULL, 0x773B84E418D3A8EFULL, 0x700EEF853528AF0BULL, 
            0xE61B0C3BAAECFD88ULL, 0x30C607F0191A1D5AULL, 0x121908E4D61B4048ULL, 0x1E96A8B5BCB07047ULL, 
            0x9B306855A45A89D2ULL, 0x49CFB975D83CF64EULL, 0x7A59A75E041EBA73ULL, 0x85C7B5ABD1201F59ULL, 
            0x39B30205042BF1D7ULL, 0x72B0C6FC28D9910FULL, 0x9A89202A2675C74AULL, 0xDC86912ECD80A7DCULL
        }
    },
    {
        {
            0x513FB6F6B2F8496CULL, 0x9E6CD31DD687198CULL, 0x36EE57A73B680DE9ULL, 0xDDA5055803672C3CULL, 
            0x9BB05BDEBB8DD61EULL, 0x56F4CADEDD5B2DD8ULL, 0x076D1E2D1BE0420FULL, 0x58396F0C4D215196ULL, 
            0xF47E0FB382CCF9A2ULL, 0xFFCA5F71236C40DAULL, 0x7007D92F00C0F202ULL, 0xE6863C3EEAF6658DULL, 
            0xC493DF87B184DB4FULL, 0x054DE04E129DC87DULL, 0x75BDCB1E37A8C4DAULL, 0xA6B40C230168834FULL, 
            0x05D9C078744BE4D6ULL, 0x73CADE60C3CE5B09ULL, 0x5D0BCD778F349000ULL, 0x7003E9D96C18CBEBULL, 
            0xF840136A68811D5DULL, 0xC0E6040C44FCE387ULL, 0x7EA29740CC755801ULL, 0x2E7E61B64D76D116ULL, 
            0x99F133EFA2F545E9ULL, 0x9F12E754CE3F2FFEULL, 0x7D915CA1FFB80E1FULL, 0x562214AC148CC6AEULL, 
            0xC6ACAD348F15971BULL, 0x701B29993B610EB0ULL, 0x3F148B5080D17B37ULL, 0x35D6A87FFCF63A0EULL
        },
        {
            0x99EEA13DC0B8DD52ULL, 0xDC6F0058E22D4D3EULL, 0x12888FE668F774CDULL, 0x8E82ED251EF1786AULL, 
            0x671460746B5E83FBULL, 0x083D4C0C5B7703D4ULL, 0x0AA35AB3943E75B7ULL, 0x264D34B5CD9110A3ULL, 
            0xD4B799D3AD8826BEULL, 0x5A2F263413CD962AULL, 0x08E3717F8616F89AULL, 0x8A633078874AB5EEULL, 
            0x203315EF74D1E3F0ULL, 0xDF18DC9DD8F44393ULL, 0x4DF576DF29394219ULL, 0x15D649C66278D770ULL, 
            0x8032E911781D40EDULL, 0x96CBB1F59BBFFC80ULL, 0xA3E038C2C6A5249BULL, 0xFFD81A7112621B60ULL, 
            0x28DE7FBAEB7B907BULL, 0xD7731DB8B4F1AB8FULL, 0xB1F2756A40BA47CDULL, 0x31CDA54E95D40489ULL, 
            0x4C2F9CA8F7711DCBULL, 0x4AF68073338A261FULL, 0x3D9827D8D83886E8ULL, 0x8699852651301BB1ULL, 
            0xC55DFE08511F9B0AULL, 0xEE11F3AF5C8B7C8BULL, 0x53A5544D29AB7072ULL, 0x2BB282087E717A16ULL
        },
        {
            0xA10724E2E6D8433FULL, 0x3AFD37B9FCD26683ULL, 0x591DAF9D13CE0EFCULL, 0xC7AFD539C6DB22C7ULL, 
            0xE3A12B4FA4FFEE29ULL, 0xE781320EB0030C68ULL, 0x0444DD34BF240BE1ULL, 0x08F9F818EED64AFAULL, 
            0x9635ABB27AA4A24AULL, 0xC32413AF30CE91BAULL, 0x85619C4B37DF2613ULL, 0x6FB1A3CFECCCB922ULL, 
            0x0B2E11090B6E4C47ULL, 0xBD529485867DFC9DULL, 0xA69E3D7FA89C47B9ULL, 0xB9AE7A350B3667B1ULL, 
            0x4469B9DB1E6752EEULL, 0x16B6D2C168979CF4ULL, 0xAFC5486604142EF9ULL, 0x9A04B4DD2402643FULL, 
            0x920C6015FFE1568CULL, 0xDD84C2FFCDCF6AFCULL, 0x0C2428DECECBDBDCULL, 0x88BDD3BABB525493ULL, 
            0x35B0B14BC878BE18ULL, 0x6B6C76AFC8308581ULL, 0xF5594237B701A1A7ULL, 0xD7014B738BDF31C1ULL, 
            0x687738AB46F77FC8ULL, 0xB72CFA130E185FE2ULL, 0xED8E8081B11F8B51ULL, 0x1A6F72D8C6C90982ULL
        },
        {
            0x98CB4CA8DF26779DULL, 0xAD564A96370F6E32ULL, 0xC0A3ED49C7D97036ULL, 0xDD8561339EDE514AULL, 
            0x4E2907479210E52CULL, 0x3EA1A4797F4BD896ULL, 0x4DDCB2993FF3581CULL, 0x5933F34F6ED75819ULL, 
            0xA4FC5541D72B2E3BULL, 0x243B888412852369ULL, 0x7EBDA9ED0BFB86ACULL, 0x6BBEACBCAD158321ULL, 
            0x1D834CE4E811EBB1ULL, 0xAFD3257310AB32A9ULL, 0x71491F61C7B2FDF2ULL, 0xE2A69555C7E4C9D8ULL, 
            0x620639C81D7E193BULL, 0xA70B466CBC1485FBULL, 0xAE285D6B7627FFB1ULL, 0xA0D6D9B3AC1B42DFULL, 
            0x17E70D199C43E416ULL, 0x73D336F7F6F1ECE4ULL, 0x64CC9D0239FB2F38ULL, 0x5204218EA8B5F056ULL, 
            0x5A5C8163C84A2B43ULL, 0xCDEDA6730B12D14BULL, 0x0573C44159685975ULL, 0xAE2C206F755E1C69ULL, 
            0x18F1A0FE08E10DC0ULL, 0x499CFE54B73F27EEULL, 0x2F4DFB2D5017CE57ULL, 0xFDC48202577FEB1CULL
        },
        {
            0x766137090BA6C7B2ULL, 0xE5CA7F3D7BA669DAULL, 0xB301CA2DF4D4B11BULL, 0x629657B381FFEA36ULL, 
            0xBD46FDC2781AA572ULL, 0xA9BCBA2F6A10EA00ULL, 0xC6FE7538F76E3261ULL, 0xCB68CD814B3E518BULL, 
            0xE740AC6F7D738ACFULL, 0xC49A6BB3EC6B182FULL, 0x212D9685EA680ED5ULL, 0xB1C031FE51504195ULL, 
            0xD4CDAFC525F8380FULL, 0x694C53997E6D97ACULL, 0x33F5156EE1CE68F0ULL, 0xB1C26632A22E77A6ULL, 
            0x575C9AD316841CA8ULL, 0xE3A914B244AA8746ULL, 0x884E3934BD897CFBULL, 0xA030D781A0E0A67EULL, 
            0xEE9006B447D035E7ULL, 0x3B626D1CACE1B915ULL, 0xA11603CEF522BA11ULL, 0xE8506ED4E73D221AULL, 
            0x21C6CCCCF7BC5218ULL, 0x7312FF90F20EF2F9ULL, 0x0F1BD99B92F53664ULL, 0x2B77A479904BB267ULL, 
            0x53A2CE35A5C8BBC4ULL, 0xF46F33322A77886AULL, 0xD455F96F203EA2C1ULL, 0xAC4A3ED1621C01ADULL
        },
        {
            0x0416FEFECEDB7120ULL, 0xFFFE2C7049D46873ULL, 0xB8EA353CEB9D8D53ULL, 0x2CBB484FE7B6854CULL, 
            0xE4C1545127DCD662ULL, 0xE5A95D591D1C2F9BULL, 0xAD5B03D4FDDD305FULL, 0x2ECF0E7847D4FEAFULL, 
            0x1D6D6E2C6B495914ULL, 0x97A6157104B9B0F0ULL, 0x9321674764E87BF9ULL, 0x155D9B63AF4CEE12ULL, 
            0x23AD805471407D62ULL, 0x35E759B063CD9AD7ULL, 0xF18D7A61384957E4ULL, 0x8CCFA8BDA5A0932AULL, 
            0x14CF68CF7F0CC00FULL, 0xC0E59D845EC4C779ULL, 0xE2638B90BEC4A77BULL, 0x52C0974BFE068D33ULL, 
            0x2B2F615484060872ULL, 0xDA3729B2737C6E0BULL, 0x30478587B4BE0E1EULL, 0x580721676B4B968FULL, 
            0xE6A98508001F94E9ULL, 0xB6704BB552F0F634ULL, 0x16AD9EB5D5FE5AE1ULL, 0xBED2E7BA48907119ULL, 
            0xADF50E2305658B0EULL, 0xB8D92E755318A14AULL, 0xFFB2361CABC45B28ULL, 0x12F99C154178762CULL
        }
    },
    {
        {
            0xCB2CD71609924C2BULL, 0x0854C51E04CB6F00ULL, 0x8B51A9D25883B08CULL, 0x8052FB892347A26CULL, 
            0x4B63DC3DA15658FAULL, 0x117D0FA0D985D1E5ULL, 0x348ECF392A51570FULL, 0xEBF5F5C60D9D19BEULL, 
            0x830296419140FD67ULL, 0x64BCCF7A2A48ED3FULL, 0x29AD249B0019C4BBULL, 0xF97DD5E2D580454DULL, 
            0x857D1E1B23F49C59ULL, 0x7C1383F77586671FULL, 0x45207267739C4FC5ULL, 0x45C26E262A240CE5ULL, 
            0x910F50AD1AE9FE74ULL, 0x2C9BC84F0EE3CCE6ULL, 0xB12E900DAC1DB7CBULL, 0x1FF4407A2E6C3082ULL, 
            0xE683CD85BA724CC6ULL, 0x2F5BDBA043E2F6BCULL, 0x254DA7F94E7AB64EULL, 0xD551A5E9E751F386ULL, 
            0xC37D849D284F58F3ULL, 0x1BE71FE6170F57BAULL, 0x6A8407BD11084C38ULL, 0xAF86BCE26D7AEF56ULL, 
            0xF9BD2EB2A43AFBB4ULL, 0x89349FD8E53DACFBULL, 0x37A9E7184865C6B7ULL, 0x43103137D708C616ULL
        },
        {
            0x1BE8A3E6E18AD4E6ULL, 0x93A6BEF354F69C00ULL, 0xC49002D6C0A9B67DULL, 0xA7C932F308B54E16ULL, 
            0xED2FB537E5DACCE1ULL, 0x2825A79A0084BCD0ULL, 0x95FB8A347F5214E4ULL, 0xD5ED96EE44AA06EFULL, 
            0x3EB5C051BEF89500ULL, 0xA151F9AF85B4A1CCULL, 0x884BA154C5E19BD8ULL, 0x5678D68AC652DFC2ULL, 
            0x3D87521691A288BBULL, 0x665F10010B4434EEULL, 0x49582C1A42E23625ULL, 0x15C518AA86D9E897ULL, 
            0x3B5AAF315295F9D0ULL, 0x1998DCB3C4BD1496ULL, 0x7721E94E5542933FULL, 0x91A3E9E7D24F1D66ULL, 
            0xE3131C6F6F59E3E1ULL, 0xFFECAD176012AE29ULL, 0xAF707C553CA92ABCULL, 0x8C49D545BA635908ULL, 
            0x79360ADA3783D8EDULL, 0x84F0FB8E41BCEBB5ULL, 0x2A1263F9C804BEA2ULL, 0x5B7CAB53030BB05CULL, 
            0x2338AC1F4EA3A365ULL, 0xDECCC5BBF9C9EB8FULL, 0x9434EA2E049F0837ULL, 0xCD4105B407C1B5D0ULL
        },
        {
            0xFB96621B72D83CAAULL, 0x1D36476E8901B7ECULL, 0x4F424D27161E5914ULL, 0x531B3F8798A193F0ULL, 
            0x18E84B5C5C785C59ULL, 0x84EEB4AD66AEDB69ULL, 0xEB0C54A2883D0921ULL, 0x3290A04246180E30ULL, 
            0xF63224037EDD1B3CULL, 0xDB180823DDBC0256ULL, 0x371D2C442D1151F8ULL, 0x25AC858443CB27A7ULL, 
            0x2B8848940CC6078DULL, 0x81D24A5F0F465BBFULL, 0xF5F92BC73363D24EULL, 0x5BB19A918352C626ULL, 
            0x7543E896FB6288F6ULL, 0x67903B7304AA3D25ULL, 0x62546ACBB3CCA6DEULL, 0x8580A6023EBC6EBCULL, 
            0x128A4C2881B54D54ULL, 0x52BD88B69E141BDEULL, 0x93D163E7CAC4B77BULL, 0x85AD3195CC2CC00BULL, 
            0xE3ABE4630A3B8B98ULL, 0xEC000FCD1B9B5CD9ULL, 0xAA9F34EAE0893AD8ULL, 0x2E0776BF425EF2C8ULL, 
            0x15D34D23392109DCULL, 0x0C4F24642AA88D0DULL, 0xC560E6B2CCA06E97ULL, 0xBDAFFB92D85C08C1ULL
        },
        {
            0x622D8871AF84DCD7ULL, 0x12FD1BC3EE3B6C0CULL, 0xDF524B79D8B0AB05ULL, 0x5B3E441071244821ULL, 
            0x31931B6A39F06EE0ULL, 0x275FAA8953C43CA1ULL, 0xA03B2AD81B24910CULL, 0xAAE0C3A9299C1D5FULL, 
            0x79FE885570AB1901ULL, 0x8D966A63F4856D73ULL, 0x66DD085129E1FC22ULL, 0x9BAD73683EA0561CULL, 
            0x85F766F9D4989053ULL, 0x28E6C214D1239818ULL, 0xFB42E808818FF7B5ULL, 0xAEF8BB71E0A5EB0EULL, 
            0xEEB10B250FC8A292ULL, 0xD85814903057FC7AULL, 0xF4ACA24CB804F434ULL, 0x84A85209B3B144CAULL, 
            0x1CA81AAF4B57AEEFULL, 0x41B95988D042C8D5ULL, 0x8FEF856FA86B1E93ULL, 0xA6C89962BB5EAC1EULL, 
            0x1F9A56CA5ABDC5C3ULL, 0x569B1EA13D5B96BCULL, 0xB292FB7F6F244339ULL, 0x8D87BE736D08066DULL, 
            0x9856C1ADE1BCF3E1ULL, 0x7E55E838A33A8CD6ULL, 0xBF2A55D20D486111ULL, 0x3AB24CCFB4FDBF38ULL
        },
        {
            0x2F44E972492A3F95ULL, 0x1C07F936062B7FCBULL, 0xE58AA47F4A324218ULL, 0xBDF565E74019F6E5ULL, 
            0x99AC01AAD55DBEDDULL, 0x40925D4A30D1BFEEULL, 0x007642109749EB4AULL, 0x14DA28852A64F64EULL, 
            0x144695DA2F901D9FULL, 0x6AD93FD1551FBA64ULL, 0xDF0DD6245005C33FULL, 0x008F68F283000079ULL, 
            0xC92C6E3B71D9374EULL, 0xA507B5BCF54849E0ULL, 0x57979A1E98A2D198ULL, 0x8F5B490E609E3EE6ULL, 
            0x730CB8BE64C4CFC4ULL, 0x393D9127D4572021ULL, 0x9F0608CDC4A75F5BULL, 0xBE1BBC61B584CC46ULL, 
            0x0E8E2D0C32E3D13FULL, 0xB525FCA9C01BCD3BULL, 0x3070FD3D05F75EB1ULL, 0x9F00F4FE4AEE7839ULL, 
            0xCA84B6926625EA6AULL, 0x377D7BD3DE2DDCC1ULL, 0xAC5346D06B8F3434ULL, 0x8418B77099C74EC3ULL, 
            0xB8DB4F0F1015AC38ULL, 0x87B5D7A67D99CD51ULL, 0xB1C80B4766C61472ULL, 0x7082566B1B7FC7A2ULL
        },
        {
            0x23B147AA80D7A21AULL, 0xDDEF719A4FAEDB92ULL, 0xE075A1E8F62982D8ULL, 0xF3E22258884243E0ULL, 
            0xA32ACB4CA5CB40C3ULL, 0x4AFF3ECA3BB56CF5ULL, 0x61FA6BC640822E3EULL, 0x9E43670CA0DB0ECDULL, 
            0x3DFE68267F0BB5DBULL, 0x201C21FA64AD01CEULL, 0x2AA24C64DB3296DFULL, 0x7D090D3DA86D28D6ULL, 
            0x23326C8234E9FD1AULL, 0x7FF93A9E35AF9DA5ULL, 0x6B762448945764B7ULL, 0x99A767AF406FA631ULL, 
            0x17AADED51BDAA429ULL, 0x42EDAEB123BD0ADCULL, 0xF7147698D64F7550ULL, 0x18422E648316AED8ULL, 
            0x03EA2B034C096261ULL, 0x2A69C95CDF3B6C2DULL, 0x85B424B5441A0018ULL, 0x8632A8E10BE8CB21ULL, 
            0x7018E9124BE7C682ULL, 0x95517F56FCE37F7FULL, 0x91E5A0CE723D0FA0ULL, 0xFA9D5900B9A78D29ULL, 
            0xF061739FDC9AF204ULL, 0x20C5FCCF2CC391EAULL, 0x3FB189B7DF259208ULL, 0x9D8AB3FA4C1D239EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseAConstants = {
    0x209DE3A45A09F4D7ULL,
    0x75B7DC1ADEDA7020ULL,
    0x7F83F76906313F18ULL,
    0x209DE3A45A09F4D7ULL,
    0x75B7DC1ADEDA7020ULL,
    0x7F83F76906313F18ULL,
    0xAE27DCE441A99047ULL,
    0xA25D85B2C3A4F346ULL,
    0x6B,
    0x1F,
    0x4A,
    0x8F,
    0x93,
    0xB5,
    0x1C,
    0xD6
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseBSalts = {
    {
        {
            0x2D42B9E973D6976CULL, 0xF08F09FE360546CEULL, 0xE8380D5AFEBDFF15ULL, 0x5FCF0BF5D5C15995ULL, 
            0x90247B840F8AD6F0ULL, 0x48E1D94E2953136EULL, 0x75BA41EE0A623853ULL, 0x9A2ACBC3E54CA744ULL, 
            0x81F43480A83E35DEULL, 0x53090EF2D2D2987EULL, 0x92E8E404899A241EULL, 0xE92AAB47DDE582EAULL, 
            0x43C5DCFD7CDD661CULL, 0x1B88A4AB631FEC00ULL, 0xC9113ABB8E9A9C57ULL, 0xB050CF79A7609AE4ULL, 
            0xAFA3454984D2521AULL, 0x5B97A8BAE1A7F1AFULL, 0xCA5731936B423023ULL, 0xFBD8C41B4F71A15DULL, 
            0xFA80F189CAE2920DULL, 0xA33EB8CF43980918ULL, 0x76FF7C7A82548A75ULL, 0xDABFE19464EBAAA4ULL, 
            0xD2C0B0FCB8E8B4CBULL, 0xCD9BAE4218ABDB57ULL, 0x149B66F45D44F289ULL, 0x5DE339D301812C49ULL, 
            0x56EE192675EE1DDFULL, 0x51017CBA156C9F69ULL, 0x0A7E48EA13D247D7ULL, 0x1DB6D2B5BC15528CULL
        },
        {
            0x26AA53D332586F2DULL, 0x8158DB266024D659ULL, 0xE51D5FC0EDA70095ULL, 0xD849CCEA11DBCC5CULL, 
            0xD828AFB17A749C05ULL, 0x551229F803740904ULL, 0xAD90751596D66B0AULL, 0x8A928804A226C23FULL, 
            0xB527A3C74E5DF1DDULL, 0x10BFC74A5F455EBCULL, 0xD5441B9B723D67E0ULL, 0xE0DD20784C3C1A50ULL, 
            0x10BADF9E01C3E2DAULL, 0x7EB0A1F1FC679854ULL, 0x0B37AB9EDBBB9E62ULL, 0xA77ADF7C6D212D0DULL, 
            0x22D2D8BDA71C3EE3ULL, 0x6613EC1F2F2C0F06ULL, 0x99FD1E79594FCDC0ULL, 0x42C20BB6077E3A85ULL, 
            0x3B9F4118B1A55985ULL, 0x2F94DD0BF053FC3EULL, 0x3FB3153EEAAF30B1ULL, 0x5C80A21FF91EDC3DULL, 
            0x1D103ED1A7954EF0ULL, 0x2B2F1210814D1CFAULL, 0xB6C1405B9FDF3E49ULL, 0xCB6754C908CF595AULL, 
            0x4A62CF1338736EE7ULL, 0x140F6276C08E3AD2ULL, 0xAB1BAAD7E5A73F60ULL, 0xE03F1CC6903C4818ULL
        },
        {
            0xA4CCC12F2DCFE44FULL, 0x55C3FD538C5E3F56ULL, 0x6EE1BCCC6BB9EC72ULL, 0x7654859A3E3E179AULL, 
            0xE2C9B6B4900A95F2ULL, 0x948803C45301F035ULL, 0x7D4BFD1FD5EE6CFBULL, 0xD25DC4E74329B99EULL, 
            0x072C66C99489EAAEULL, 0x50FB4CD13E47B764ULL, 0xE490397DC08049AEULL, 0x6C7709A2EDC7C803ULL, 
            0x185144012DA26703ULL, 0xCA63CC85591242BCULL, 0x85D00DDF0256BE12ULL, 0xD11ECC3765F8092BULL, 
            0xE65610433DEDB73EULL, 0x9F72C7F04E194390ULL, 0xDE3E6D87ABF6D8FDULL, 0xF7D95541365B77F1ULL, 
            0xB032BE593DA8BC17ULL, 0x5DD83BBA8908EEBFULL, 0x604FC6C2D51EEE85ULL, 0xF9EACF0627F9800FULL, 
            0x6D64A48EE8C5CC44ULL, 0xCBD8E0E45807A13EULL, 0x4CCC49B21968EA6BULL, 0xC6C4F64791B52CEFULL, 
            0x2949877B55F612FFULL, 0x0BF09144FDCA8204ULL, 0x228D9FBDBFDE347CULL, 0xA1DEB394D5DFF091ULL
        },
        {
            0xD07076C0517DC5BDULL, 0xA769340F2418BFE8ULL, 0xA721F20AB1695CCFULL, 0xA207D260F66955B2ULL, 
            0xCE56C0D3C6CB1826ULL, 0xA19AAC0073D2D21AULL, 0x4FA409A4A1A44064ULL, 0xA8CBEBF9BEB19C5AULL, 
            0x8FB155A9EA5279D2ULL, 0xB4DBAAD025C7321CULL, 0xE2CBB021E6E96FBFULL, 0x84DD134C79C6F308ULL, 
            0x6C5874D6D711F96DULL, 0x7BC8F05AC93E30ECULL, 0xCF3C329F213461BFULL, 0x3C0A34CFC01CD6C3ULL, 
            0xF8353C3CC718592EULL, 0x1D54C22D097D779CULL, 0xEFF1311BC91C0552ULL, 0x1B925854D9972407ULL, 
            0xBB5DA95A0F8BD2F6ULL, 0x4EF832B0DC9BB4A3ULL, 0xFF0382456A0ED1C1ULL, 0x7606490E72C3BA1EULL, 
            0xB33D3028082D3358ULL, 0x6BF9A6C12582C693ULL, 0x770BE3AFB8D8A962ULL, 0x7E9DD008715018F8ULL, 
            0x16F8744250781EDAULL, 0xD7F44CE41B37040BULL, 0xA99456637B63F23EULL, 0x41F572173989789BULL
        },
        {
            0xCE40F5FEA5C1ECF8ULL, 0x48FB9026D49A2281ULL, 0x37A792C7DC192C0FULL, 0x8DA3673F1CFDD9B7ULL, 
            0x524E33256B175803ULL, 0x5FB753368870333AULL, 0x7CF3644ED54B01CFULL, 0xF903B3343B5963ADULL, 
            0x083480180057E193ULL, 0x3CEC9907A51BA9E1ULL, 0x7D220136E81411E8ULL, 0x71CE9C2F625E304BULL, 
            0x31601B32927D7907ULL, 0x0E0D6E4AF9FEDFEDULL, 0x7AAF3F20F0FEFFC0ULL, 0xB474F8C0B95EF3F2ULL, 
            0xD982134071E487DEULL, 0x76B6B4FD4D4DA3E0ULL, 0x3C4D45396F898397ULL, 0x37AD51932E5B7649ULL, 
            0xF36BB4C863D70771ULL, 0x9DF6847316526136ULL, 0xAEF3E7C2657D4234ULL, 0x657F738FB7C42679ULL, 
            0xFB82D9DE30FC1F3CULL, 0x695BE33D5A0F0069ULL, 0xC8F6A6B1EE08D69EULL, 0x1F685373E430158EULL, 
            0xF6C47A0D0FB46C42ULL, 0x1BB9C5A7FF7D5429ULL, 0x94364C67C3A22ADCULL, 0x9E6E4EE72D06ECFBULL
        },
        {
            0x075E6360E9C0FBE8ULL, 0xA86DFA1D2E391084ULL, 0x9ED53D4E81393E44ULL, 0x9A517E084612DCEDULL, 
            0xCF9349D74D5DC36EULL, 0xABD05D1C535CCB12ULL, 0xF3E36BCDE1DC8D1FULL, 0x5AA50ACDA74EEDF7ULL, 
            0x9733E2BFAAA3BCCCULL, 0xDDA3663EFDA7897EULL, 0x355EBD174FA7A05BULL, 0x3948C3FDD4E634BEULL, 
            0xE4D940A5A610CC4FULL, 0x181E83827E02B09AULL, 0x206CAB14E1C53421ULL, 0xA7D54BFDAF324EDCULL, 
            0x5C2B3B06179A2729ULL, 0x8FEEB5A2E47EE716ULL, 0x7BCD9A3A86087B92ULL, 0x955EE71FEAC1BF79ULL, 
            0xFD124B085FC7F549ULL, 0xE1F8C6AFB03AD487ULL, 0x456ECE6AC992D9FDULL, 0x34CB4CF6E7DC9EE2ULL, 
            0xC956C85FFDFD041AULL, 0x9B61A676E7D96CC2ULL, 0x14D49054FC141854ULL, 0x9F1746EC9F217FC0ULL, 
            0x617648011AA24997ULL, 0x3AF3075BB5A7FB72ULL, 0x972457E99389404FULL, 0xD08E1774EF33C9B1ULL
        }
    },
    {
        {
            0xE6025E04018BF6CEULL, 0x977C46E043A20B89ULL, 0x7EE1AF5117BE93DFULL, 0x5482A58F09D064FDULL, 
            0x1F04325914524E6DULL, 0x41E5F9803773998AULL, 0xCEC95101300DFF7EULL, 0xB7189768836DA07CULL, 
            0x56A1C2A3F214DA50ULL, 0x03617C7A4AC95BF2ULL, 0x22D3859DFCBEF1BEULL, 0x442E8666B2EB57F7ULL, 
            0x2F97CCDA55E8DCE1ULL, 0x956AF888A2A4FB04ULL, 0x8208FC5860CDFF03ULL, 0xFE84EEC1B44842E4ULL, 
            0x86C002F85FAB10C8ULL, 0xA1ECF77697444FA2ULL, 0xF3C96F30FD3DBC88ULL, 0x661C5F4B34C461BEULL, 
            0x358F303489D77D84ULL, 0x3CB16F1F9B405949ULL, 0x7827DDCD1E1AECD0ULL, 0xE196292C37B10230ULL, 
            0xA6C5C74C66E35C4DULL, 0x5F4F05563373BE2EULL, 0xFD22C9A61F0F724CULL, 0x433D88C376A5EA46ULL, 
            0xDCC86F33812852E6ULL, 0x4FD892F432D9F17BULL, 0x4001F07894DDF76DULL, 0xB008D9ADA8D16BA4ULL
        },
        {
            0xE9B6E2954933F57EULL, 0x28F0B73DE37CF948ULL, 0x54E3701ABFAD16F5ULL, 0xD063292848BB928DULL, 
            0x4969F57D39B69670ULL, 0x5C21E930B875A136ULL, 0x6EA0E54E51E03C32ULL, 0x2B38ED47934A1DC2ULL, 
            0xB99E7F31063D9694ULL, 0x948874781F5C74DDULL, 0xBCE3D83A7FDBCB89ULL, 0xA1AA3582AC70F60AULL, 
            0xB44DEC84CA3A6347ULL, 0x4BEB9856147C70D0ULL, 0x4FDAC5EB05174280ULL, 0x0402DBBF90892ADFULL, 
            0x8EFBA183BABAE7AFULL, 0xD8ECBDF5816AC745ULL, 0xD47C23D5820B4C1EULL, 0xBF746B52076AA055ULL, 
            0xBD05329936EB88B2ULL, 0x96D447F820248C21ULL, 0x8D0817E6628040C4ULL, 0x29D8615EA1B4F0CDULL, 
            0x4CB6CD86957630D4ULL, 0x54385533C081AE8CULL, 0x9CC0B1DA5B1E7531ULL, 0xE3E7EA1DCF0383C2ULL, 
            0x0C2F0BE1728FC2F7ULL, 0xCEB7C3A47447D00BULL, 0x6FF07EDF70221344ULL, 0x8B9532F3E8DDD199ULL
        },
        {
            0xA48127D4A40D40B1ULL, 0x8FEC71ECDD53BAF1ULL, 0x25D55C850625F69CULL, 0xF86991D744739848ULL, 
            0xE6190BFA5B0B34CCULL, 0x7681E4C23FF4BC22ULL, 0xB27820927414B563ULL, 0x24CABEFB8CCF7F36ULL, 
            0x1AA057AE47200758ULL, 0xCD8D4EA6CF19696BULL, 0x665633BE93386DCCULL, 0xDFC4D795FED0187EULL, 
            0x6FA5D047FE9A9835ULL, 0x00997FEBF84C6642ULL, 0x3A0A7FFBB3F326B0ULL, 0x0A905BB098EFE37DULL, 
            0x16F1C4EAF3805F74ULL, 0xF84C89E4BB445E9EULL, 0xBBCCF8352BB3E80CULL, 0x77F0E41F94FC1E4FULL, 
            0xA4E456F9E0E37686ULL, 0x83928F8B9B1A1A91ULL, 0xEE3D8419E22F85ABULL, 0x92D81C4263742FC5ULL, 
            0x7E1711DADCB532DFULL, 0x96B13820D7BFF693ULL, 0xA611C29ED65C98A7ULL, 0x1218B7E05E5177A6ULL, 
            0x012A6DB5CA96D8AFULL, 0x2CA2F86587349441ULL, 0x3B529673BDEE8CCAULL, 0x0D7F0AFFA8A9F743ULL
        },
        {
            0x476B9E280AF5DF2CULL, 0x43FB3928959F4F67ULL, 0x1C6BB01FE65C1897ULL, 0x2087E1D27901EA14ULL, 
            0xA5CF602CB54EB51CULL, 0x1BBE68205FCD6AE5ULL, 0xC8714B9D681044E3ULL, 0xC66DF28A75B979AEULL, 
            0x635B0AD559EB4D98ULL, 0x15754D4F314DC364ULL, 0x5E0ED114ED13D0B3ULL, 0x801F96A2308A692CULL, 
            0x77ED5FD75A37DFFEULL, 0xACEBA0025B74837EULL, 0xACE1F514714D8F7AULL, 0xBF7DA1F0A218AEA8ULL, 
            0xBE9788A20D2FBAF6ULL, 0xF7D5CB4A7BDDB9EAULL, 0x08C266D7A3FD69F0ULL, 0xD2B661F6B9392517ULL, 
            0xB324C6847C936355ULL, 0xA314976339E018FEULL, 0x0AC84F4C0627359FULL, 0x915154DEFEBE953FULL, 
            0xD2E7A423CAFC67E9ULL, 0x8F52460A84AD33AFULL, 0x008385F6B8858E33ULL, 0xF5B7A6757587EEB4ULL, 
            0xA2B8CF5C02AD2A13ULL, 0xB0515AADD02346D0ULL, 0x7A728DA3FF8D5DF1ULL, 0xCEC179310814C184ULL
        },
        {
            0xF7FF01E3D91835CCULL, 0xC0A841171F2F1681ULL, 0x432F9E7565BB31E8ULL, 0x8ADC46F674B8B9E7ULL, 
            0x87F3DF1BC07D9550ULL, 0x7CB4764DB0362040ULL, 0x5436782796C2D7F6ULL, 0x4263B3B9F0A1CF3CULL, 
            0xEECCF14F0B473869ULL, 0xF3B5F245B698651DULL, 0x13493BB612D68CD1ULL, 0x0B6B693CF8D97528ULL, 
            0x39A1F7E3B70A58CEULL, 0x9A21EE7FB45572E2ULL, 0xCCED4EDD52316F69ULL, 0xDC326651E30F992CULL, 
            0x2053F859588F8E93ULL, 0xE6F00CA4F37F55D7ULL, 0x62322794B050DCE7ULL, 0x82C8C1AA3D838522ULL, 
            0x798E2F5FB3AB7145ULL, 0x87195EC549ED7919ULL, 0xCF8EB95ABCB13C4FULL, 0xAD5C7DC29E8A4CA4ULL, 
            0xA13389048F7CEC03ULL, 0x239D04E5FA3B6565ULL, 0x9BC1DE7FD1AC7E65ULL, 0xEF86747E22430365ULL, 
            0x959B884F664A2E0FULL, 0x292DFA106B285D90ULL, 0x89C9FABCECBC3FEBULL, 0x890276DE3FF3200CULL
        },
        {
            0xACAABF465E7493B1ULL, 0xE680B682B566DC30ULL, 0x210696C6F0FAE00FULL, 0xB6F183504C0E6E99ULL, 
            0xC15909BF856ADBA9ULL, 0xFCC900AEF2E0C398ULL, 0x109B07A9FD2DF77FULL, 0xC3F2C20E66B3B3C2ULL, 
            0x3E04F5130DBE5CD2ULL, 0x020B68D15761F26DULL, 0x2F3956D35BBFB6FEULL, 0xB425EC99EB171EF6ULL, 
            0x2C6D9405E95FD94BULL, 0x974C6704762E9ACEULL, 0x37A4B358D5B1796BULL, 0xDBF34E0CC2893FF9ULL, 
            0xF9D3245EA1B38091ULL, 0x1C043F36047CDA01ULL, 0xDA547DABEFDCDAEFULL, 0x4AB5D6C512A9C6B0ULL, 
            0x0D21C5FEAFCDDBE4ULL, 0x1B1CA91F04120966ULL, 0x34BD09B128BF26EBULL, 0x5076034D4C100175ULL, 
            0xF5EC622B4454C299ULL, 0x48A3F8808CD47186ULL, 0x8AA36D3A05849D6EULL, 0x8D55B2F82C32CD84ULL, 
            0xBB64E5616B6CA265ULL, 0x6D9972B71C51F292ULL, 0x7E070F42750699C3ULL, 0x825064616951AA1DULL
        }
    },
    {
        {
            0x8C662D3454363751ULL, 0x8DF3BB8A628C95F2ULL, 0xB1A8F5508CFFCD57ULL, 0xD0370A0C83AE52F1ULL, 
            0x0EBDA3EB0FB06A18ULL, 0xE3A75A18173EB3EAULL, 0x2181F3B66E1DB214ULL, 0xD120648C0ECBFDFBULL, 
            0xD8234F55EE707B5CULL, 0xB92BD5CF5C383EC0ULL, 0xC1922C9136065D5CULL, 0xB52A350FB1E9037EULL, 
            0xB2D89A64C02ACF54ULL, 0xE547437851D23313ULL, 0xD6A7BAD2B38FD1FCULL, 0x678CD7888B28380FULL, 
            0xE4ED59A6AF9D1104ULL, 0x5B6F0EE7D311FC4FULL, 0x2A3B930A32D3B0B6ULL, 0xC0F27DBF2E3EB9A4ULL, 
            0x950323E1B78AA53EULL, 0x6FFF62F6F08097F0ULL, 0x618A9D5A873E5A0FULL, 0xB07455D5D79F4CCAULL, 
            0x4AF629E8CD0CDC66ULL, 0x215198342D2F64F5ULL, 0xC99D7F4A845C3377ULL, 0xF3AD9A56C1504521ULL, 
            0x29341BB8A5BDA676ULL, 0x087BCA1AD23E54B1ULL, 0x9861B063600B4F4FULL, 0x9D6E9477F233A956ULL
        },
        {
            0x3883D9FF93F65AE3ULL, 0x44B7CB3FC8ECBA75ULL, 0x648EBBA25F6C77E8ULL, 0x3C70C1CB82713684ULL, 
            0x883E0CE3E809F02CULL, 0xD956D4F1E6849D9DULL, 0x7257EA157F52F6EBULL, 0x726D8572586B4B03ULL, 
            0xFB7B8998408D056AULL, 0x676FB1995253855FULL, 0xE744C2CBF07F1353ULL, 0x758002766B6569A8ULL, 
            0x24F13C1CDF0B802AULL, 0x06AE2F6DEDA00406ULL, 0xDC6BFD70022BCFA6ULL, 0xF0452292A6BEF08CULL, 
            0x5620DDBAD0879379ULL, 0x46C98B3E09651206ULL, 0x546785EAE29BF8F6ULL, 0xC1BA1A52FCD18BD4ULL, 
            0xA83A99AE780CB05FULL, 0x62D484B84D3AC769ULL, 0xCAB2339E251F1782ULL, 0xEA049D8EC73FACE6ULL, 
            0xA8CA5C90EAE31113ULL, 0xFAD80F7E1A748EA0ULL, 0xA81BD9954522E740ULL, 0x85B591138BBCDC6EULL, 
            0x9763E33DF26D19EFULL, 0x59C64027B1D0916AULL, 0xEE646BC2CDC51023ULL, 0x5B0E8C6C38C34089ULL
        },
        {
            0xD0F4E900B668B7A9ULL, 0x004A142CAE5B660AULL, 0x5275147A18169ADFULL, 0x9119714FD5FC199AULL, 
            0xDF73B885E9521D68ULL, 0x2CE93DB3A118D4A9ULL, 0x86A8F2767C01AD9CULL, 0xE483D0214F50C300ULL, 
            0x7E06B4A0D950D926ULL, 0x0748F32000CDB80CULL, 0x05EAB7E4805F5510ULL, 0xB8363EEA1C0B43E0ULL, 
            0xE8759CD5CFD2B2D8ULL, 0x1172A1B2C2BAF818ULL, 0x06B8F7E6F6B05FB1ULL, 0x37202F325F74F70BULL, 
            0xF040CD841CE12772ULL, 0xA1E38832B564BE27ULL, 0x0D34C67CC7E2FE9DULL, 0x9B0857CF92DA40ECULL, 
            0xC689936FB1E39B8EULL, 0x3FE407BB2C9C4D01ULL, 0x9445390F02D87DD8ULL, 0x31AC1812B22D94BBULL, 
            0x47502B7948470FD3ULL, 0x2C57A09E749354B4ULL, 0x67B60BAB90FA9FE8ULL, 0x14C325753AEA9EDAULL, 
            0x196876D0742D831CULL, 0xC6E123A14B94A9EEULL, 0x8854A1D5E2F0E807ULL, 0xEC2536F75CA370D0ULL
        },
        {
            0x223746179070D637ULL, 0x5AEF83470D0DBE63ULL, 0xAC347335F015247CULL, 0xFDDE00260EA7EB16ULL, 
            0x826569C23FABF589ULL, 0x88939FEA7E7D9165ULL, 0x4B060D2013F128A9ULL, 0x6DDE642520377ADAULL, 
            0x3F855E6BE7E8D504ULL, 0xACC2601B91AC0820ULL, 0x0C42A13407734010ULL, 0xE924EDF7E3B64197ULL, 
            0xD6C198B56A6D2E0FULL, 0xB157F3A6912AB668ULL, 0x565A99B4A060B945ULL, 0x4FEF1AD8CEB7A27FULL, 
            0x46F90033F8767B97ULL, 0x579CDD033AB293E6ULL, 0xA039AF6979B604A6ULL, 0x22ADED6C5B2FB10CULL, 
            0x9A113D792E6C5C83ULL, 0x68B7BB750B1CE38CULL, 0xE3026074F1CC598EULL, 0x2A5F78E6981995C8ULL, 
            0xF6998B61D1CB22EEULL, 0x703A00889A98C13CULL, 0x4E5B5A1C4A88868EULL, 0x42CB60BB6887EB90ULL, 
            0x6445232390B11063ULL, 0xA223B9061F0B307DULL, 0x21FAB422866E79DEULL, 0xAF342BB1585B719BULL
        },
        {
            0xC30A0B30210D93D1ULL, 0x020DD2E5070404CAULL, 0xC8175313A9AB1093ULL, 0x4264FBBF56D7A5A2ULL, 
            0xFDFBC1E00F218F78ULL, 0xD3CCF743886D7F54ULL, 0xB16761A92CADF46AULL, 0x097DCF0849ED406EULL, 
            0x77CE47057A76DC6CULL, 0x3F5050DF8394431CULL, 0x1937CE4D80D4FCB3ULL, 0x31B4454B4172722AULL, 
            0xE922C31797EBF261ULL, 0x62C79C32D923F5D9ULL, 0x087CC761117DDC2CULL, 0x8EA9382E919EE4B9ULL, 
            0x0F334CFD9EEC185EULL, 0xBB691AAC08693367ULL, 0x724127F7A918423EULL, 0x4A5622B0B9241037ULL, 
            0xE34F307224525D7AULL, 0x9E59FC70AFAFCAB4ULL, 0x99195FC386324DB9ULL, 0x62E704668AEA9EE1ULL, 
            0x35B2C55534325E0CULL, 0xBE614D8C2FCA668CULL, 0x88A0A6DC935A0EFDULL, 0x9A6A68AC9C4189B7ULL, 
            0xA3E4F408FA6C0C1CULL, 0x541C54C29DA103B1ULL, 0xD5DD9F6AEB74AB6BULL, 0x83708D91324BD9F1ULL
        },
        {
            0xC1BC9DAB4F04497BULL, 0x1119AF2C8E8A4602ULL, 0xE89FD74C461FE94CULL, 0x138BA0EE060D42ABULL, 
            0xE37A9460780B78B1ULL, 0x962EBC2A8956E590ULL, 0xBD5B36BFBC5246BBULL, 0x6E1B1D49568300ABULL, 
            0xF35988324528DB5EULL, 0xBB8250C96A86DE7CULL, 0xE1932168B2BC28E8ULL, 0x57176FF7827E2D50ULL, 
            0x5FEBE9A66EB05C33ULL, 0x4C994FBCDF5E211AULL, 0x7B683D5711FD269BULL, 0xFEB726953508832BULL, 
            0xA3129F2B0FC25BE6ULL, 0x460DC4C92DB14CD6ULL, 0x34B43F3B8BAD500AULL, 0x9A9577B40FF72A54ULL, 
            0xA5632A7CF1786D07ULL, 0x92932CB4AE41F6B7ULL, 0x8714DF748E6A6AECULL, 0x3DD2DB95A5BCCD3FULL, 
            0x040B9D574CE775A9ULL, 0xAD1F609546529D81ULL, 0x2950D1C6A1C1F709ULL, 0x4785E3C715D5594AULL, 
            0xDF5CA47E7E5B187FULL, 0x0B1A4927FD8FFD59ULL, 0x43A69C2FDA7D674BULL, 0xCCEF24791BBA26DFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseBConstants = {
    0xB409BEFDD6C5ADFAULL,
    0xBA8FCD6F48B97A32ULL,
    0x5710F25CC1CFDF64ULL,
    0xB409BEFDD6C5ADFAULL,
    0xBA8FCD6F48B97A32ULL,
    0x5710F25CC1CFDF64ULL,
    0x5D32147775788559ULL,
    0x3AE885FB9F0814C2ULL,
    0x42,
    0x46,
    0x77,
    0xE5,
    0x5D,
    0xCC,
    0x4C,
    0x16
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseCSalts = {
    {
        {
            0xE45D3220CABB06EBULL, 0xAC2751DA28BA5F90ULL, 0x81962F5D2D4173B8ULL, 0x49BEB6607D13A527ULL, 
            0x069188D9C6E9643FULL, 0xB8B71FDD6D270F24ULL, 0xED550730DB2A37C5ULL, 0xA3539DDCE5CB97C5ULL, 
            0xE25FEDC2E3DDE34EULL, 0x4260A4FC8CF914F3ULL, 0x2C87AC6E3CC45E9FULL, 0x663BCA1342A961CFULL, 
            0x4B72EE7915AC772AULL, 0x6EDA3EFCA139BD1AULL, 0x15BF1E4C90F81B1BULL, 0xD766BD5FC845486FULL, 
            0x8C8481E77B03D45AULL, 0x7342E944700750CCULL, 0xCA2BCC6C01E14CE1ULL, 0xD49B4B1778C9F639ULL, 
            0xA9FEF1C26610AAA7ULL, 0x5832308CC334370DULL, 0x5F10CF93F32F7107ULL, 0x337C3D73965E8E5CULL, 
            0xEA8F7D21BEF88CDCULL, 0x3AD6866301E88A1CULL, 0x70F8209ABFB52A29ULL, 0xE11474E6C49059EAULL, 
            0x4FE68AEF0F8A17F6ULL, 0xD4C37A7F2A319BD4ULL, 0x9E265BE9BB1F58F7ULL, 0x7057AF7671F02329ULL
        },
        {
            0xDFC06D627FCFEDEFULL, 0xDE7856A4B4EE3A4EULL, 0x8CB60E1C083C70AEULL, 0x346A70BC1DCE89D3ULL, 
            0x9578F67801ECD1F8ULL, 0x71249B3E391F482BULL, 0xBD0B8C173FF93E7BULL, 0xF27279BFC2EEFE1FULL, 
            0xD36CD1404001BB82ULL, 0xED158D51D88C018FULL, 0x6AEB5A29537C60CAULL, 0x4A8AE922C1545397ULL, 
            0x5023EFF9CDA4E783ULL, 0x49B13FD21F4BC3FAULL, 0xA84BDC75790564A4ULL, 0x3C026537C67F26F2ULL, 
            0x06A125A66B584837ULL, 0x29251F91F8F4489BULL, 0x0E4B570DB044BEFBULL, 0xC0FA94EB97581189ULL, 
            0xCE493DB34FF0DFA8ULL, 0x01EA6B369BA71803ULL, 0x20FE60040BA96837ULL, 0x8166093CC936A663ULL, 
            0x86759AD31170011BULL, 0x5A13F49DA9F5CA68ULL, 0x73C449D14671F451ULL, 0x3199C6CF93B1A697ULL, 
            0x2A1B6C949D37A59BULL, 0x9F195518D04482D6ULL, 0xD31096B2E09C52B2ULL, 0x6CBA80EC73C7DEB9ULL
        },
        {
            0xF1CF6F7067364D46ULL, 0x895D75C19C496451ULL, 0x6A14DCB995D1CFF4ULL, 0xA87D2CB65700D77FULL, 
            0x0C16DB7759556531ULL, 0x156B2FFDD74DFFA8ULL, 0x0BE03F89C2F2C439ULL, 0xCAF1279B93A20057ULL, 
            0x572939281D8AB7C0ULL, 0xA89C333AB9804A34ULL, 0x00353AB6B379FBC5ULL, 0x989288E19A4D1013ULL, 
            0xFC8771F23E3AFD66ULL, 0x9FA2E6BE636A938AULL, 0xC76F04A5B686D44FULL, 0x690013479EC87035ULL, 
            0xF5452AAA40E9ECBDULL, 0x1F2935A14846A589ULL, 0x778CB3B693D895B5ULL, 0x10CC4BC02FC55CC1ULL, 
            0xF4832CD26812FF2DULL, 0x114CEE23F4761C53ULL, 0x2002940C7AD82680ULL, 0x9B2BB1565E39FEB8ULL, 
            0xC303ACFAF9A76EA4ULL, 0x04CD27C8F6EFBB37ULL, 0xAED9CE720375CF9FULL, 0xB11C9F4D16AA3A55ULL, 
            0xF7EC8FFB4E5048E4ULL, 0xDDE0336B374A80E6ULL, 0xD2D5D94980AF9270ULL, 0x89238DA390077EEAULL
        },
        {
            0xFB40BC38C0C19917ULL, 0x4738C04612728B8CULL, 0xFEEE6EC2A0D3E153ULL, 0xC31A0F5938BBA5FEULL, 
            0x18780440E9DCFD28ULL, 0x7C6F3068EA7846F9ULL, 0x515FEE1147837DD0ULL, 0x5C76791AAA757A3DULL, 
            0x99791CFEF52586D6ULL, 0x1E816EE1CE5F354EULL, 0xA40629CC293B24B3ULL, 0xC2613DA5B43F844AULL, 
            0x1DE185BAFBBE297EULL, 0x3967C83C87DA5B63ULL, 0xBD773E70D448D5B6ULL, 0x4D52F005F008C5CCULL, 
            0xB40B857ABA764B56ULL, 0x18F576A11375CFCAULL, 0x4DA1C86194E8D9F8ULL, 0xC5BD2D3C1CB42A5AULL, 
            0xA88A826918DFFD52ULL, 0x8C57B6D327F32712ULL, 0x7E7BD329A45A64ACULL, 0x123E27047F850C91ULL, 
            0x650734247380E6DCULL, 0xDC8670F5554E62A6ULL, 0x5A0563A3115EA739ULL, 0xF50BAB4F2B34942BULL, 
            0x80F47B9965D4913FULL, 0x89A4CBCC103FEE29ULL, 0xB1F04F0700F2B2DEULL, 0x075D280AC4F313DEULL
        },
        {
            0x17CCC18F2E3E521DULL, 0x8453E5FCF2F10DA6ULL, 0x50E539E259F69651ULL, 0x55A97EB5AE3E0229ULL, 
            0x4472D71A91EE9B50ULL, 0x1F5FD082CA5DC7DEULL, 0xB110ED59B99491C4ULL, 0x6C484EE5C61744DFULL, 
            0xFB8CAE0B17DE4A9DULL, 0x1013623757DFDA2EULL, 0xD0DE8C676464C89CULL, 0x57A5B0AFC931791AULL, 
            0xC02FA01331D60E1AULL, 0x0433A43F445F8E10ULL, 0x12B78B07193C6B26ULL, 0x3E8643FB4152BB62ULL, 
            0x4D170EB08572A7EFULL, 0xB6E0700AF918D2BBULL, 0x42625A68179FD0EAULL, 0x0833D908504DA0D4ULL, 
            0xCA0324948756CC20ULL, 0xB902EB044ED74BAFULL, 0x73D71CABE715104EULL, 0x4DCA18DB61C23067ULL, 
            0x8348892D2B60A394ULL, 0x7F85F8DAD93E928CULL, 0xA6A2657514427684ULL, 0xF9706D6977017E10ULL, 
            0x9044C3497E3693BEULL, 0x35778759E59549A5ULL, 0xBD6EE2967397F9A9ULL, 0x753D935CD0242026ULL
        },
        {
            0x9AA51F4F236B82B4ULL, 0x32293243680C7DC6ULL, 0x8E2EDED69E746371ULL, 0x6E90DD6C1352DD5FULL, 
            0xA9D8D961FD84AE92ULL, 0x36E290DC463811D5ULL, 0xDF2D34A7A2226A6CULL, 0xDC59D2087962CE92ULL, 
            0x3EB62806AC094E1CULL, 0xEE48260E86085B13ULL, 0xDD735BDBB39EC5D0ULL, 0x38B5D1B233A0A19FULL, 
            0x859B455A1B8800A2ULL, 0x7617DC036C48B067ULL, 0xD73F2FBD6841AB07ULL, 0x53D2CA859246E846ULL, 
            0x24EB1A8C4306AC82ULL, 0x64E3086EFF7641BAULL, 0x0D46BAA1ABA5F885ULL, 0xACB75AE68495F77DULL, 
            0x79E17C484FDE47AEULL, 0x65DA668C8938ABAEULL, 0x2C05108A3DCC245FULL, 0xF1EB270C7CDC6A2BULL, 
            0xEE4D08D598C4DE0FULL, 0x54DE0BC0B655083CULL, 0xA54F5BFF3F112F10ULL, 0xDB07D931289044DFULL, 
            0xC6528FCF0AC16A01ULL, 0x59C1BDAD1353FAFCULL, 0x11942908FA995D6AULL, 0x5F38C9449E960ACDULL
        }
    },
    {
        {
            0xA2116E07FDF19E0DULL, 0xEBA6DF1A3AB34FBDULL, 0xC725562ADB593582ULL, 0xD8382D5F8EDA4FA5ULL, 
            0x0ABDA62837F09C6DULL, 0xFAFE5CD9684DEEB1ULL, 0xC792C635F6998837ULL, 0x3FB562FD7A1A1792ULL, 
            0xC7280E79464BADF9ULL, 0x39AFFD3557F0C872ULL, 0x97AF9DA173C537B6ULL, 0x6A234618119C70F8ULL, 
            0x78125D132C9A7C29ULL, 0xEAE87BCD70667E06ULL, 0x17EF444B66370FCBULL, 0x020CF92B74D90E30ULL, 
            0x2971B9F6DFEAEDEDULL, 0xF0457F5D6A618C20ULL, 0x6AF6ED34D93CB967ULL, 0x734665271D38502AULL, 
            0xEA4EEEB84446B7C5ULL, 0x326A678086F7A458ULL, 0xBA8EA72C57316473ULL, 0xFA88E2B19003C20BULL, 
            0x403F809F9C31E808ULL, 0xFCA892742C3DC6EAULL, 0x06EAE272B44E9690ULL, 0xEBCA5647290371B7ULL, 
            0xB1DB66F4D5476E1DULL, 0x3A5FC529DCC0D22AULL, 0x231AB10062A4C8B2ULL, 0xCEE8243BAB774584ULL
        },
        {
            0xAD047AE44174DBA7ULL, 0x5B9D66E66A250AEDULL, 0x72572D48B7582131ULL, 0x06F7348819803EBAULL, 
            0x4EDC8E468F5DF80DULL, 0xCA6BE5D15D976075ULL, 0x0EE85FC72FEDD3D1ULL, 0x8279616FAD503203ULL, 
            0x9B57010B9047BA32ULL, 0x4AABC97CEC8DC2FCULL, 0xA371AF4318EE005CULL, 0x086BA142ACF9FD03ULL, 
            0x4FB5840723B0C0B8ULL, 0xA2724B2244BA6761ULL, 0xBE49CE60E97442DFULL, 0xB05977A81D1729B9ULL, 
            0x88015186EC2DE706ULL, 0x4D77E1911E835FD0ULL, 0xC4DC727AE698E04FULL, 0xDE04A3C338160938ULL, 
            0x675D9A89CB413FFFULL, 0x35B4D8E57CFC530EULL, 0xA9AAFE8159D27BE3ULL, 0x957903B7FC18548EULL, 
            0x2DED285B9410CAEEULL, 0x26B997D4B14789F1ULL, 0x6374ED351243D662ULL, 0xB0E872285BAE5CB2ULL, 
            0x867841F964B8D7A6ULL, 0x4DDC6CF4A91D43C8ULL, 0xEE302BE1DDF2981CULL, 0x737EFCE14CF30ADAULL
        },
        {
            0x180C73614D3500CBULL, 0x9066BF003A3C08C2ULL, 0x5FC61E62B7656DEEULL, 0xEA82ECF5DE773AC3ULL, 
            0xCDFD4B8450854019ULL, 0xB6971625E74AD827ULL, 0xEA8BA6AD8D5977DFULL, 0x1CAEC73A3AC3D26BULL, 
            0x0035D4E2D9D74A9AULL, 0x7BC3AB70A4604AD6ULL, 0x33C6440BBF8E9A41ULL, 0xA7281BC3D09F05C1ULL, 
            0x65F4BA632B70D9F0ULL, 0xA3F9A28C8A723DC4ULL, 0xB5E699BC5ECAE24EULL, 0xAE9E931AEE46F841ULL, 
            0x346EF416AF746A81ULL, 0x9FEA4E106189E273ULL, 0x05C38F3C52459EBAULL, 0x37A4B64F1163CA9DULL, 
            0x6DFC777D72EE3802ULL, 0x303B8AAC97F411AAULL, 0x13899F2EB1731573ULL, 0x5169E096705BCC26ULL, 
            0xD82FF53E4ECA84ACULL, 0x3AF81A4D76526456ULL, 0xCCAD068F37332E40ULL, 0xC3323FC5D9AFC532ULL, 
            0x3319F0BB178B8F01ULL, 0xE2D3A61EFC1E4963ULL, 0x47307EA9D6375359ULL, 0xE7C36005AC575E5DULL
        },
        {
            0x31BD1B9F57D2361EULL, 0x4E3577AA135652E4ULL, 0x7A9C3968A5502642ULL, 0x3AD3D6CFC8F21C19ULL, 
            0xE4DE30F66A8A6786ULL, 0xF9C5584CD9692B51ULL, 0xE289E38ED1A2DC0DULL, 0x446404754B805B7BULL, 
            0xDA2A7F80400FB989ULL, 0xB2A1CED2D1666502ULL, 0x9ABBB6ADAAB336EEULL, 0xBE3D365967E44F62ULL, 
            0x78B0216C4AD5EBBDULL, 0x7B7B0CAEFD46C8F0ULL, 0xE4F9F422541B4FB8ULL, 0x5C1D7E33FDF1C47EULL, 
            0x4047C2CE7E704619ULL, 0xC36E33A72145FCB4ULL, 0x3CE58DB94008EA8DULL, 0xE22F5559E0692800ULL, 
            0xE1C9B7BBDDF90671ULL, 0x0A77956900EA91ECULL, 0xCE3C68A2831D9B37ULL, 0xFFE0C2C214BD03F7ULL, 
            0x316EA320050F9F14ULL, 0x6F0EE2E1A4E04C65ULL, 0xD0AF489ED5507EEEULL, 0x499C18A1923FCE75ULL, 
            0x2908F20A555B4A4CULL, 0x9CC231D98F337AD9ULL, 0xD92C21335A1B5241ULL, 0x7439A828B91A8976ULL
        },
        {
            0x52A01D5DA34F4423ULL, 0xAD3B4AAFC2CEF206ULL, 0x3EABB59EB90DE409ULL, 0x49FCE63C8B39FA79ULL, 
            0xD1FCB42B6712ED9CULL, 0x616F63B0B4A19C12ULL, 0xECE17E7C0534B4FCULL, 0x43429F0EE074E036ULL, 
            0xD7D4F1C6E5057F78ULL, 0x7E513C0C49F5B779ULL, 0x5E7AFE472FBB538EULL, 0xE1ECD7FAD1F2914FULL, 
            0x99B8DCF6E0EEA45AULL, 0xC812A1525B48DEA9ULL, 0x54F5809D9311FEDAULL, 0xA47CFF654A0A350EULL, 
            0xA83CE4F9E87BA2E0ULL, 0x0B2486C6B74A1E18ULL, 0x5553106652688289ULL, 0x34A7C7EF4B3C547DULL, 
            0x83926A5EFE692BF4ULL, 0x1D6276DAB955E39CULL, 0x011808E5CE774ABBULL, 0x555FDED6F3603571ULL, 
            0xEC8985A96E833084ULL, 0xA67F0CD999456BF3ULL, 0x30FD8E17F18AC457ULL, 0xB6A6E0683C4F4738ULL, 
            0x6FBDCE332A2F1D34ULL, 0xF4CCED8727ED67DBULL, 0x6336960B83D88D31ULL, 0x615E215DF6FCDB90ULL
        },
        {
            0x0CFD08548162E91FULL, 0x1E31205C4A9B5739ULL, 0x82FF731A06EE8DE9ULL, 0x7E1DAD3D68705B11ULL, 
            0x3DAE95D0909B7B83ULL, 0x704C4073835010DBULL, 0x150C7A8D3830EAB3ULL, 0x05BEFBA81F253295ULL, 
            0x0FA363272AE94021ULL, 0x0AB106B9C89E66CDULL, 0x1D4DBC4A6E9820EFULL, 0x18108332924C4DC8ULL, 
            0x59BAB8412E8A5B2EULL, 0x0A15E2D019871894ULL, 0xCE3D655DAA4822B9ULL, 0xA9889A91FBF0EF36ULL, 
            0x30E3C97A6AA48152ULL, 0x10030209B6CEC1E8ULL, 0x07AF6549A0C2B99DULL, 0x9B79B115DD559FE4ULL, 
            0xD53FEE3BE47D327FULL, 0xCF93A83A5B03F101ULL, 0x2E2C4A2D81DC43BAULL, 0x9560DC1B23CEC9EEULL, 
            0x7A67431EF5DD5789ULL, 0x456D7B2D04F6B193ULL, 0x03244A5F72EBFE17ULL, 0x1E9A5FFB90631987ULL, 
            0x8B9B293C0C70A3BBULL, 0xCBC518D424FFEC5FULL, 0x5543D0E9819EE086ULL, 0x4FD3E73E684C97EEULL
        }
    },
    {
        {
            0xA94A318497DC72EEULL, 0x52838A968B276C6FULL, 0x9A4FE1A34DF9CE17ULL, 0x70AA5E583BA0E061ULL, 
            0x3FB0E9BD042F7799ULL, 0xC006E2F63CF198AFULL, 0xE247A58CCAAF6CA4ULL, 0xAD5C18C0642A803EULL, 
            0xB63EB7E80DEEFDEEULL, 0x932109508F71CAB1ULL, 0x85FE09803CC98ABFULL, 0xE03F873EE4C316C0ULL, 
            0x159B9413EA7DBF17ULL, 0x60B94603617EF66BULL, 0x21A9183B9856AEB8ULL, 0x243CD61E9F7C1B6BULL, 
            0xEB73B39B6E1771CEULL, 0xC40E35436B76B267ULL, 0x5F8135267EFD61EFULL, 0x98E30061CBBD95FAULL, 
            0x4CE47D12A2A4591BULL, 0x50A4F1190F71C3AFULL, 0x601ECDC924439E42ULL, 0x3E859C66DA23AB9FULL, 
            0x371014116E05C58BULL, 0x4743652FF29B099CULL, 0x38E895D0534D4D82ULL, 0x23240FC6821B1346ULL, 
            0xC22F0CE3C5BFE9A4ULL, 0x3C44E5BC0678F5C9ULL, 0x5CAFD3859A6EAFE0ULL, 0x984E2294A91E9125ULL
        },
        {
            0xFC59373842F2100DULL, 0x0F2B2711F3FA7BF9ULL, 0x0DCBFFA5751B1231ULL, 0x61F9AD00300DBA78ULL, 
            0x20C81C8681A34D5AULL, 0xD68C02E2EFE7FF25ULL, 0xC20AFE1C75B8D49FULL, 0xD3F8EA41A6B70FDFULL, 
            0x1C5E2C7BF30BD4C9ULL, 0x82EFD5B7C401FC94ULL, 0x4BE8468F5CB4C966ULL, 0xA64C48D8E12D887FULL, 
            0x7D9C70C923FF7B64ULL, 0x77C95A6514A00E74ULL, 0xDDFFFCD27D7E16FBULL, 0x9E8BE2A6C55E01F4ULL, 
            0xCDC79C68AC1FA839ULL, 0x373E2E490EF0A51CULL, 0xAD15A12F15D87493ULL, 0x0EB08C0F92221C30ULL, 
            0xD6219E03964AF479ULL, 0xF1DA9AB80B0AF749ULL, 0xEA775FC22A154BD9ULL, 0xB90985E1CC6A22FCULL, 
            0xF66B261E6C781153ULL, 0xDBE23E45B7C550A9ULL, 0x3598D660F2DF7B2AULL, 0xFA165F93B8F3BA71ULL, 
            0x8EC33545DBB0E1DCULL, 0x857ACE350651B80CULL, 0xCA48ED7385FE7136ULL, 0x7991D9162F1674F0ULL
        },
        {
            0x71D7B32654E3D60BULL, 0xD437BCB75C2726A4ULL, 0xB5F159B55E4145C0ULL, 0x20768E6B79A622DAULL, 
            0x31ADB02572D02906ULL, 0xD76277338003B8EBULL, 0x42A88D7F39F9A018ULL, 0x15B33BB4FFE2E912ULL, 
            0x6C4BF6740CE1FA08ULL, 0xD4E6131372F07909ULL, 0x4A2912D70754E687ULL, 0xFE3D715A70C1059FULL, 
            0xD422E2BD8E97C5A3ULL, 0xD7DD1292BA5C02A6ULL, 0x38DF25400E11093FULL, 0xE394013F9F913673ULL, 
            0x71BCD2BAFC07A6BEULL, 0xFC0F66B0B8D97C93ULL, 0xC664BA5D35E93B39ULL, 0x165713F607C04D08ULL, 
            0x5E078F51D39FF4E4ULL, 0x0D8433628A651CD2ULL, 0x881BAF5C02C915D0ULL, 0xAA4E7B279604BED3ULL, 
            0x0E3BB008661E4820ULL, 0xD3E9519557739A04ULL, 0x8929FB7AE5AE7E6CULL, 0x96D01CA8BEE70186ULL, 
            0xC26D1783E69D3B55ULL, 0x8BC04E4199F3A57EULL, 0x634AEEF42FC49648ULL, 0xF0FF2DD8B659D7EDULL
        },
        {
            0xD7FD606AD95307B8ULL, 0x0BA7AD48F8ECD1FCULL, 0x63ACD09075FC9999ULL, 0x264E7A6D2A928C64ULL, 
            0xE0295C7E62A45B63ULL, 0xF181A38A907B4696ULL, 0x4C6FE106A5A22EF1ULL, 0x932BCDA09F712C25ULL, 
            0xE2427B3D192156C5ULL, 0x4ACB3EB80DECD91CULL, 0x1821263B9C9FE878ULL, 0x9C409D84D83ADCE0ULL, 
            0x2B108C015FCA4347ULL, 0xC8729CDD577699BAULL, 0x3E5690950E1FFF30ULL, 0xFCAC1E2E896EB305ULL, 
            0x04BE6B6BC52EC0B9ULL, 0x3F1C9E38A0BA0ACCULL, 0x5157D0D4DA227BF8ULL, 0x58DAF4C7929CEBFBULL, 
            0xD00934E7E021DD71ULL, 0x1188E6E3A3469239ULL, 0x88FAEE19D31964F4ULL, 0xDFA1EC36E903B4DFULL, 
            0x8C83D418B911CF6BULL, 0x30D2CA3C742F4CB7ULL, 0xB0ECFCE385D6689DULL, 0xB0DDF6FD90C03B88ULL, 
            0x0CF910E6B43792D6ULL, 0x20926A8453D077EAULL, 0xCF9E8BA5C39AE5B8ULL, 0x50BE05105C4D026CULL
        },
        {
            0x0B396E872236367BULL, 0x9E06EE3C54CF4D59ULL, 0x7D19D7DE3A5E8926ULL, 0xF2D3783F079DDEECULL, 
            0xBF7CDD86775A0DC7ULL, 0xABF513DECEFCA88FULL, 0xB3EBE68EBA35FA84ULL, 0x619A0B88615F3FF1ULL, 
            0x0EAA8CEBCAA47A93ULL, 0xE2416D1EF3FA03D9ULL, 0xE6E6915942A8AB7DULL, 0xBB4419C6D56B3956ULL, 
            0x562CFBB2D16EF787ULL, 0xC459B9D03ED90488ULL, 0x564F45DD23702E5FULL, 0x34B07748E844EBA5ULL, 
            0xC1C53C12460DBE44ULL, 0x985FA7D27E39BBDEULL, 0x71AEFD5CE9F692E8ULL, 0x323F648F41450FBAULL, 
            0xA1131AFF24982F36ULL, 0x54FBBA5DDDACAA7CULL, 0x81DBD9B8C128D0EDULL, 0xE883E4A2B1FCA728ULL, 
            0xF902BCFE76D0EE37ULL, 0x7DAE9D46A1B6B283ULL, 0xC96811049D24EC49ULL, 0x26029FE99B55FDC5ULL, 
            0x9D2AD2457491AB81ULL, 0x89B6FBD3FE17C8E8ULL, 0x5DD0B27246BA7EF1ULL, 0xF0410D59C9D6B4F3ULL
        },
        {
            0x261E67D8C31A8B62ULL, 0xCD7003D1737089C2ULL, 0x29C2F122F05D42BFULL, 0x11F22FA1946D1ACEULL, 
            0x9848337C3BB3881DULL, 0xBB56221F3B905D3EULL, 0xE14BEBEC8BAA1BFEULL, 0xD5168C66E4013974ULL, 
            0x6AF89A55B3C3FFCCULL, 0x93F50D0382B642A5ULL, 0x2AD77D22A00F5AD9ULL, 0x16E007D0B83D48DCULL, 
            0x1E1E8294A7B7AFDCULL, 0x0741D471A7F299A3ULL, 0x78EBF35A4890A494ULL, 0xB2B8D9EC3E0FA973ULL, 
            0x38EC3DA3073EA420ULL, 0xD4C77857BB53975FULL, 0x8B848DA020DAE561ULL, 0xF5C60C86FEA522F4ULL, 
            0xBE40B3E6650E37C1ULL, 0x814A4BA8ACAAF73FULL, 0x5734EB5E9CFF7768ULL, 0xF73E6BED0C8F881AULL, 
            0x0CA5B095BE0D0E34ULL, 0x886B92EFF6406FE4ULL, 0x6CF9C0F509258F47ULL, 0xDBDAAD3854269FC1ULL, 
            0x82E969A31618061FULL, 0xF684C491FD38D1D9ULL, 0xA9D0BCD1F4390A1BULL, 0x27EC552752DCCAF9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseCConstants = {
    0x859F272E0388AE09ULL,
    0x2737D4BD451147BBULL,
    0x23189D36DCA4B9A2ULL,
    0x859F272E0388AE09ULL,
    0x2737D4BD451147BBULL,
    0x23189D36DCA4B9A2ULL,
    0xAEF71D162E60B5DCULL,
    0xFA6FCC931DE9D49EULL,
    0xDC,
    0x85,
    0x6E,
    0x3F,
    0xE0,
    0x7A,
    0x9E,
    0xC2
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseDSalts = {
    {
        {
            0x9FB394F45B4BBA27ULL, 0x299A305B37523462ULL, 0xAC2087AFE9BEDD84ULL, 0xC25C0A2EFF383999ULL, 
            0xC81DB4AF1B659A96ULL, 0xE15DA4858ABB8C9EULL, 0x1468015C86CD0D6DULL, 0x8FA41A38B1C11BEDULL, 
            0xB3527013C69D3830ULL, 0xB2D8F957C67ABEA4ULL, 0x79DB880856AD319AULL, 0x6DDA99B1BC339521ULL, 
            0xDECD70D691BB903CULL, 0xA3DD2F07E5B1FEC8ULL, 0xC232EAF6F12D3FCDULL, 0xDC748D3B9B1FF243ULL, 
            0xF38AE8BAA02FA7B0ULL, 0x0D5D6C6901951DD1ULL, 0xBC2D17460FDA386DULL, 0x410216F8A766E14DULL, 
            0x328DD18A67F07290ULL, 0xF9BC8225477E26EFULL, 0xC733CEEC48FE21C1ULL, 0xD1850E01C8A8974CULL, 
            0x4EBAAC833B116C16ULL, 0x82EA22B1F99FA2DBULL, 0xF1978A25E7A9B410ULL, 0x1F51DAD6BA1120CAULL, 
            0xF8916A7636382EEDULL, 0x5E25D0674C3D8BB2ULL, 0x2A02DA41D894BB2CULL, 0x21241C4B1E07E0FCULL
        },
        {
            0x705C64716BA02F1BULL, 0xE3129D4C8AC70975ULL, 0x4B20C0EEC1C7ABF3ULL, 0x2DAD3F7A5DE0D5D3ULL, 
            0x6CFF7F17556D051FULL, 0x248ED236DA496E03ULL, 0x424B1A71C0CD9748ULL, 0xAE869D2194EC022FULL, 
            0xE32DC3692F4165A1ULL, 0x5BD33EAE719E9979ULL, 0xA9FD463F1F957D9CULL, 0x1426F29D314B5E13ULL, 
            0x796E88BCACB6F413ULL, 0x58758345C7E3DF8CULL, 0x5FA174E26973CA0FULL, 0x02A2F206B6FDBBC6ULL, 
            0x4A422DD89FB47411ULL, 0xD7E3B5AB3F910385ULL, 0x968B84DE7096F199ULL, 0xB016DF0F4B3D96F4ULL, 
            0x4C10AAB18EC65D27ULL, 0xE29927AB09B1A8B3ULL, 0xE1F9091866F05709ULL, 0x29E229A8AD672C43ULL, 
            0xD67F3B56E15FA04BULL, 0x2C61287359385574ULL, 0x6268E3BF9CCCB1F3ULL, 0x52457B5C23F25DC9ULL, 
            0xAB8A990CDC6D59A0ULL, 0x4AC2B91E844B72E0ULL, 0x70B51DB5F3F35C19ULL, 0x519B8F94C66FD2F6ULL
        },
        {
            0xD70F134E87838472ULL, 0x03AA3059C0C9CB23ULL, 0x1BABEE8ECBD2C70BULL, 0xB3C6CB6B78C6CCD2ULL, 
            0x734B5A0CE9765AB7ULL, 0x9B75338A0E221C55ULL, 0xABD83D213428AF0AULL, 0xE61BE215CD4099FCULL, 
            0xC2D6E4941B107F9CULL, 0x6F7C2F7D0ED4D26DULL, 0xDA7B9087D8F1F594ULL, 0x26C1EC2A1E09938EULL, 
            0x832A8DF35B82086FULL, 0x15622BF1E868D3F3ULL, 0xBC14BCCC6EA4DDD4ULL, 0x493CBD159109CD2DULL, 
            0x64A1AA97072FEB07ULL, 0x988189EE79196F32ULL, 0xA2E17F3A1A5EE464ULL, 0x3F90101BEABA0A84ULL, 
            0x649DF0AEAB4C68B9ULL, 0xBEDDBA5C07488765ULL, 0xD41B63D9A58118C8ULL, 0x89306DA2B2B11C83ULL, 
            0x139070AE48146D6BULL, 0xB11D86CDF3B5CCDDULL, 0xC7202C031B09F608ULL, 0x9D684B7181C6AAE7ULL, 
            0xB1E4E795E7460AEEULL, 0xF9590BA56C626E1DULL, 0x5431C0610268DECEULL, 0x95134B5A0F590852ULL
        },
        {
            0xE166D4A3611A4559ULL, 0x4203612131379B2EULL, 0xA3362D3B17EC22ACULL, 0xB37CAA65CFBA2FB4ULL, 
            0x41D9DCC7792BC2D0ULL, 0xBBE61C9D3300C970ULL, 0xA5FF5E10EA0F2F85ULL, 0xFD526DF029CB902AULL, 
            0x04F5C466DF7688B4ULL, 0x1679E3AAD18A0351ULL, 0xA9E1BF21F5152ECEULL, 0x1BFF5237735EF0DDULL, 
            0x38FA3A2715BFAA4CULL, 0x59D84AEFECAD61ACULL, 0x1AD4080734570E8CULL, 0xEA058AB1BC0368AFULL, 
            0x1EE09B0347109A6AULL, 0x00A93849F27B1264ULL, 0x9986DD6BA8479739ULL, 0xEDD70764E1D8C25AULL, 
            0x773E313ED58FC186ULL, 0xF050C8CE0F7868CDULL, 0x73152288951B9296ULL, 0xDF1EEB2859EC02EDULL, 
            0x1A3DF52B018F42D6ULL, 0x031059127921B41DULL, 0x8B700B951923691FULL, 0x5B6C952EAE37090FULL, 
            0x10A090C6FE1098F3ULL, 0x0822C3244F8FA5BBULL, 0x2D9F5653DB325457ULL, 0xEAECE0582ABC0FD1ULL
        },
        {
            0x52FA006CE9868B8DULL, 0xCBBF74D829FBA61BULL, 0x0C78E7924B06346AULL, 0xEC1BFE185897A1DBULL, 
            0x1CAC5D5E59C4BEC1ULL, 0x5A7234EA4F4733E4ULL, 0x0994E75073238787ULL, 0xB0F7AD7620ED6A70ULL, 
            0x2F62776154B08069ULL, 0xA13DBEB33AF2054FULL, 0x598B5AFEE5514537ULL, 0xA7694BEEB726FC78ULL, 
            0x60F0687534ECD6E8ULL, 0x770BD79BE854DD2BULL, 0x603A9988402400EFULL, 0xB845C477E8DE479BULL, 
            0x234B9CD85B29F05EULL, 0x6281E8DF2D4C429FULL, 0x0D5A2B9834CAA46CULL, 0x1E5BE48EBC11BB28ULL, 
            0x2BB248793BF91777ULL, 0x101F9413C0AE84DDULL, 0x62962E618E80D574ULL, 0xFE6AD464DECBCA3AULL, 
            0x31A41780D303281BULL, 0xCC12A9B0C1E45976ULL, 0xC25BB07AC6686502ULL, 0x269B2E4EB6C1AA9FULL, 
            0x87F2D855443D3201ULL, 0x5AC3593C518B3B9FULL, 0x3FDBDA3C00CD5D17ULL, 0x2009BA84EEADEFFAULL
        },
        {
            0x753C4875DC04E448ULL, 0xA2600277C0064B8EULL, 0xA2AEF2DC8AF57523ULL, 0x56BB8E97B41BB75BULL, 
            0x4BED1CFB419208EEULL, 0x2238AAAA5CB15EF1ULL, 0xEDAFA3DD73D06A46ULL, 0xC231124E51E5340FULL, 
            0x0A541F8EEADD8827ULL, 0x7CE5A106FBED98B5ULL, 0x488EA89DDE7E2247ULL, 0x30B4E88F4A683C84ULL, 
            0x9BC5BC40724CEB00ULL, 0x762520DE1A0B8BAAULL, 0x5361A479CA001873ULL, 0x0E091A6F3DF5A955ULL, 
            0x18ADEF80F326BF38ULL, 0x08D02D94DBD45EB7ULL, 0xB2A7A9969330915BULL, 0x17CC2F16BE34C7BFULL, 
            0x61008A2AC3E18B51ULL, 0x7DC9759199EBC4E8ULL, 0x000A8A1BCCAA82E6ULL, 0xC2116F8A6CB19F98ULL, 
            0x5A876BF4B248D06DULL, 0xD6CD76AD17F7D30CULL, 0x4DF76A893B584673ULL, 0x2F273BACF1EAAC08ULL, 
            0xB29EC7ED85A6FF8AULL, 0x48ED2B50AFBD9800ULL, 0xEB7459173CEE7C5EULL, 0xFF6DE0C9C06632B0ULL
        }
    },
    {
        {
            0x2543A3CDF5D20B4DULL, 0xF8D842C7C7603462ULL, 0xADA0E6D4D3DFA604ULL, 0x44EACD4A7BB8C343ULL, 
            0xBDBE29ADE9F7A632ULL, 0x0ECE25ED53A02902ULL, 0xF5AB668DC50D20D4ULL, 0x4C57A4A5C27BCBEDULL, 
            0x1369836C3F0943B8ULL, 0xAE08E3EA34BCE65BULL, 0x5EF339265442AF27ULL, 0x654831E91F0C251DULL, 
            0x36453437EDE26295ULL, 0xA9FF88C34AA176E3ULL, 0x53D3A7810D14A5EDULL, 0xECC8C04F4A1B3BA3ULL, 
            0x8A5C2D5FA016C2BBULL, 0xE2D5177FE677227FULL, 0xCB58F2167FDBD982ULL, 0xE47AA5104FF962BEULL, 
            0xF50681B4E6DF5EE5ULL, 0xFB54321F63BBC5ECULL, 0xE702EF71EF822FCCULL, 0xE085DAE70A4B0D09ULL, 
            0x82E338A8A79ED91DULL, 0xF9949D76624C4275ULL, 0xDC16976AA3B0D2D2ULL, 0x5CDA464168977293ULL, 
            0x121A482BC9011144ULL, 0x6142DAC2F0B8D43CULL, 0x32EDF91D99F26133ULL, 0x932499F6A04FD9B7ULL
        },
        {
            0xC49C4F8774C99BB2ULL, 0x6DFD13B0A849FE6EULL, 0xF4F4C15059F65755ULL, 0x7E120CD7B2A738A0ULL, 
            0xB89A56A9F2597F2EULL, 0x8D71AE7640F0CAF4ULL, 0x9A92D0528DA0892FULL, 0xA1941CEF7A77C1B4ULL, 
            0xB865A5F6D87E0AADULL, 0xDF03FFC2414642EFULL, 0x55FDD5A79F08DCD2ULL, 0x8C4CB78DE5E15EE7ULL, 
            0xC873DEA577BAE28DULL, 0x84D6EA24CD184BC3ULL, 0x0143CE240C5E2CB3ULL, 0xE4A1B7197AECB5A9ULL, 
            0xAE137D64FA1B720FULL, 0x0B57668775EEBC17ULL, 0xC3B4F2AC604E9860ULL, 0x82A58A0EB1AEC21EULL, 
            0xDA7AED1B17E871D8ULL, 0x7386EC89C48038F6ULL, 0x98BAA4D431FB7A3EULL, 0xEC7967EA2D10F420ULL, 
            0x01C0D45E7966E397ULL, 0x422DC2FF4EFD3345ULL, 0x7DEF024F922F679CULL, 0x262255B1C79F1AE0ULL, 
            0x20C658783D1AC3FBULL, 0x0E716683073E7C8AULL, 0x0D097287B12A2792ULL, 0x053524AEF8C1E6ACULL
        },
        {
            0xAFA9FF22747700E1ULL, 0x435DED49B425DC55ULL, 0x92ACB4C8FFBEA2C1ULL, 0x6A33C811B42621F2ULL, 
            0xA3C1ED96B037A683ULL, 0x8425A1E1DEA82ADFULL, 0x0F74E21F551EB78AULL, 0xA490B8C5BC497B7DULL, 
            0x4382AFFA1D1E70EBULL, 0x4B895B1689A0CE72ULL, 0xC7B1B9EEC4E8D327ULL, 0x80FEBDD7C9BFA714ULL, 
            0x92B501D8F808F628ULL, 0x193CEB9550A9F672ULL, 0x795A60F2BD156930ULL, 0x0812A7DC45EF21C1ULL, 
            0x3EFE7798C320ED4AULL, 0x07D2A172BA8311E6ULL, 0x772DFF0730C2CF4DULL, 0xE29ABE4B363472FEULL, 
            0xE36F769B86A4EB3DULL, 0x9DC3D81553DFF911ULL, 0xE0DB57CE2D697A4BULL, 0x475C0E67DCC8E3C7ULL, 
            0x87ACFBD7CE99B9B3ULL, 0xF2C784FE9E3B0410ULL, 0x3AC9767251C554CAULL, 0x8BA716E58966689DULL, 
            0x4310C7C1DB1EF462ULL, 0xDA243AB4C0C5A39BULL, 0x4E06016BE92D54B0ULL, 0x5A735A496D1F9373ULL
        },
        {
            0xED7316935F76CCD6ULL, 0x8B044C7B57E93A6DULL, 0xD6C56B0DAB030FD8ULL, 0x8183F7BD95108710ULL, 
            0xCE0E7AFD07EA5ADCULL, 0xB669351FEE491526ULL, 0x2B56D1C5FBDA1471ULL, 0xFD55BB119810114EULL, 
            0x96D3405FBD92AD77ULL, 0x493B30356AFECC56ULL, 0xB490A5F548489C84ULL, 0x343536517C16E01AULL, 
            0xA087C48438239C27ULL, 0x7C526B999E0B0C7DULL, 0x4010FEC8501D4C5AULL, 0x434761616286FA53ULL, 
            0x13CBD4A06CF49E97ULL, 0x26BA29124246C672ULL, 0xE822CF22D22D0BAFULL, 0xB0F83D240A8C1913ULL, 
            0x71357AEE61976015ULL, 0xB4DCE1EA27A13B48ULL, 0xAE7ECF7E86A4DB6EULL, 0x321A4091F17197B8ULL, 
            0x5466D85AE6E2F050ULL, 0xD719C2DBAA174F26ULL, 0x8AA25E9E0372A5B2ULL, 0x8ABA60A1EBBD790EULL, 
            0x4915E4BDF6934CA0ULL, 0xBE41AA327CACDB22ULL, 0x31EA61E57A16C5A0ULL, 0x0FD8951C6F15C5A6ULL
        },
        {
            0xC2262F296A8739CBULL, 0xA04FFFBB8AA8E88CULL, 0x204D85E03F3FB332ULL, 0xC24E1881EDC89854ULL, 
            0xF05E8018FA45D0DBULL, 0x156B96AF94767F32ULL, 0x358648D3487E4CFAULL, 0xAD2BF2302C92C647ULL, 
            0xF6023425FC61C9D5ULL, 0xEED303DBD98DD8BEULL, 0x3E1F33EB5828BB00ULL, 0x3B9025574143B4C7ULL, 
            0xBE83020FE3C6E669ULL, 0xF6A1651CC0658A6EULL, 0x4B080BDC56159C8FULL, 0x5C66F95D792D0DC9ULL, 
            0xFDA6C2CC633F5754ULL, 0xFD6878A9A52BD5A2ULL, 0x5A6D98D29662782DULL, 0xAC930777F24C6D20ULL, 
            0x18754D1CC372761BULL, 0x418C34B9CDA52831ULL, 0x94BE550420FDE1A3ULL, 0x5EC5B79FE4C723D4ULL, 
            0xE5B996D5F7DCACD8ULL, 0xEB990665FAF0E2A5ULL, 0x73A8DB2A81A8883AULL, 0x5829C831C7307D75ULL, 
            0x120E50815394A184ULL, 0x7C91F1E4D3F8ECFFULL, 0x29B5AA466976403BULL, 0xA6EB4609B54A2F06ULL
        },
        {
            0xB844064A283C84C6ULL, 0x9EC5331EE0001343ULL, 0x2688275C2A999FB5ULL, 0xE8AF1742EBD7C1C2ULL, 
            0x9E15BFCF503B5B3BULL, 0x2E0F334D84F871AEULL, 0x19C203AD71B8454AULL, 0x1EC81A7F889F639FULL, 
            0x426667CA80E2315DULL, 0xB3252B8313230663ULL, 0xE9C0DD487558EF7CULL, 0xE0C044F47B530980ULL, 
            0xA335C68662E7F6BFULL, 0x3975133C9113107EULL, 0x1E7EDF303F41FFB4ULL, 0x45CF30B3B19A3C91ULL, 
            0x3EC19E35BDC1C2B5ULL, 0x2BC656AFC36AF93DULL, 0x4CEB270B38C74B57ULL, 0xE428A827CF85A626ULL, 
            0xB9D0DB912507A4B7ULL, 0xC7AD8DF41DF09AB4ULL, 0xDFDE3A1079897FA9ULL, 0x51D1ADB049BAF68DULL, 
            0xF7DA289E3D977B8AULL, 0x0607CF9FB4B021A6ULL, 0xEC9E82B5A9DEAE68ULL, 0x03223F9D5C9F9F04ULL, 
            0x7F30A7F9EA2A75F3ULL, 0x874F9E8DEB407340ULL, 0xBE6B6DFD597EC863ULL, 0xF0F119FDBD2FD501ULL
        }
    },
    {
        {
            0x403A7C9999FB7FE3ULL, 0xE82E1A7F699E2B84ULL, 0x232AB848CF8F4717ULL, 0x467A2B7AB364BFFFULL, 
            0x320CF851D0329B59ULL, 0x10D68AFA03A44F91ULL, 0x612B6FB2FAA9896DULL, 0x204B7D15361D795FULL, 
            0x3317B16B861C47ADULL, 0x065F71B9BEED051CULL, 0xE857E1AB112F27F7ULL, 0x142BD3934936A9D7ULL, 
            0x1765E37777D518E1ULL, 0x59A698D1875004C4ULL, 0x7D07CF559123EADAULL, 0x291437DAF5996784ULL, 
            0x362BA2F661B5DC42ULL, 0x8AD2754876F096FEULL, 0x7187016CC654504DULL, 0x7970103D65C317C5ULL, 
            0x41D0677359724E15ULL, 0xF795CFC579F823C7ULL, 0x39C781A87103ADE7ULL, 0x551D13A3A93F445FULL, 
            0x600CC4EE57A20078ULL, 0xECF906DE8908782AULL, 0x1ED5543AC33E0604ULL, 0x5058BEF4F6E0EC36ULL, 
            0x2DE6EA9F27F3BB06ULL, 0x725E420444BA225BULL, 0xB354C6F28A93CBB3ULL, 0xCBEAC9A169642B08ULL
        },
        {
            0xCC0CA69B84B10A94ULL, 0xAC2A7A938E1D2834ULL, 0xCEF82462BC1A7B16ULL, 0x6D4BCA3EAB9C35DCULL, 
            0x5AF35ADAB3917EB3ULL, 0x74B258C593EA0D9DULL, 0xDA23BC62D52BFC7AULL, 0x484F384048BAEF16ULL, 
            0x78D058B70454DAECULL, 0x757109557ED616BFULL, 0x9B6FC4A374959017ULL, 0x581702D803F865E3ULL, 
            0xC36669ADFAA63D99ULL, 0xA0C615059A38173DULL, 0x479D0E4E227AAAE6ULL, 0x16311165615B3CBEULL, 
            0x08EDC90E3B4B080BULL, 0x6C0D66F489E831E0ULL, 0x6E53034FB808C404ULL, 0xDF47FE266A432DC8ULL, 
            0x51B8F94F474118C8ULL, 0x208D3AC445D8CF10ULL, 0xE171A359728B690EULL, 0x0E08F89A60AD4A6BULL, 
            0x62BC1ADECCED0E66ULL, 0xEBD750FDBB74997CULL, 0x2E16C013988A884AULL, 0x85ED43691626286AULL, 
            0xD6EF54CB0A8B6454ULL, 0x92D6E59F02D83312ULL, 0x55C548FDDB77C5FCULL, 0x20D35156B00B36CDULL
        },
        {
            0x83AC00581D811F1DULL, 0x381DAAEF57E34974ULL, 0x02AD50A835312457ULL, 0x04D8020D9E0BBD1FULL, 
            0xC293038F2032EE09ULL, 0x20B2253B80D0326FULL, 0x8C014A2540CA2421ULL, 0x48446EBDAC9C30EBULL, 
            0x6AB948177386B324ULL, 0xD9047242B5AED940ULL, 0x85E5EB3028FE1393ULL, 0x3266FF8F45A7BB67ULL, 
            0xCC060B1826650550ULL, 0x854CB247476B1CCAULL, 0x31519817BA6C90E0ULL, 0xC7227A3B853F89DEULL, 
            0xBE0E5194166F6B4AULL, 0xEECB25330615C1AFULL, 0x173BC764C5A78771ULL, 0x26A811DED5FD8DA9ULL, 
            0xBBE23D7C31502673ULL, 0x8042172E91C29266ULL, 0x5AE8E6FE8C11E088ULL, 0x587B9F9C9396F985ULL, 
            0x32B0A5667ED1B43EULL, 0x55762DD998E8C486ULL, 0x519886E4EA76F7FCULL, 0x0FC256B7767E9277ULL, 
            0xFF367DCB0BC97E2DULL, 0xF51BD5CA0D758306ULL, 0xFCDDD50F5EBF1C49ULL, 0x8D559B1B7982FEF3ULL
        },
        {
            0x6B97CE8B59CA03A7ULL, 0x96F73C30A71F55A2ULL, 0x5BC952D41853EDB9ULL, 0x9EEEE2E475EF9986ULL, 
            0x877D7EA91E80BBDDULL, 0x4748C5F53AE6A4D3ULL, 0x0DF201355D208FE9ULL, 0xFF8A1FC42FDDA475ULL, 
            0x6EE34105A42C964AULL, 0x58B6A9484798C706ULL, 0xBCA448BAE6B07DB9ULL, 0x0F15FF5EDEBC0493ULL, 
            0xC677EFBFDB1DEFBFULL, 0xEC0F34D429FC0BCCULL, 0xCA082DD6EFFFACD5ULL, 0xEA4D6D811E04821DULL, 
            0x595F195FCF772916ULL, 0x69C3B0790AD6703EULL, 0xB2325041BE9ACC16ULL, 0x0974DC8D9371BDF9ULL, 
            0xFEE64EDCB3D978FAULL, 0xE18EF8CFBCE9C737ULL, 0x3B828CE40180D609ULL, 0x2FC142CAD47B7666ULL, 
            0x3C095B1C4AE0D1DDULL, 0xD4677CF693CF8A2EULL, 0x7BED43E5437B62F2ULL, 0x040F6184A96B6E68ULL, 
            0xC2960B069F8CF79DULL, 0x1AD826D38D787928ULL, 0x4DDFDFB0EED9846FULL, 0x04BAFFADCAE1A0C1ULL
        },
        {
            0x5F44992B567FC1DBULL, 0x6CC2A7D5E6A2093DULL, 0x4ABCA89C1C1516F7ULL, 0xC9664049EE3CBEF5ULL, 
            0x453A7EE2C1A00F51ULL, 0xADBBE0122FCF4DFEULL, 0x1C7EC9BB2716D668ULL, 0x21B106FF603A749BULL, 
            0xA918DD5251D1FB2EULL, 0xE3BFE8F63CF75EA2ULL, 0xF18A91AE44255007ULL, 0x6FF173D09A697C48ULL, 
            0x21B03C28252659B1ULL, 0x78B609D59F23F382ULL, 0x277831E962929B41ULL, 0x721758568D3821E9ULL, 
            0xF3C0788E105AD73EULL, 0x0D9ADAFA50DA92F2ULL, 0x19188E45C6F55C8EULL, 0x44E6D1879178FC23ULL, 
            0x7CD79F7BEBBA5756ULL, 0xA928C41A8A71AE4FULL, 0xA0107B0C366F27C5ULL, 0xE60A8CA6969C9AE1ULL, 
            0x2FDD4016E74E4520ULL, 0xBCA3596EF4BBCE99ULL, 0x6B55A555BEB0A9CFULL, 0x104A7ADAD61BD8D6ULL, 
            0x8026E9B1D9152BEBULL, 0x29D279E6A73747EEULL, 0x9332ED291761725BULL, 0xFF852A63FDF62694ULL
        },
        {
            0xAD5225E0334D278EULL, 0x77291507EF578314ULL, 0x9C18EE815E909487ULL, 0x334D1D0B12C8B347ULL, 
            0x4E68E20EAC9FA79DULL, 0xCB817476FABAE719ULL, 0xC987B2AA613A3D49ULL, 0xA369D03AB5C11A3EULL, 
            0xB2E4CDA1B28EAC24ULL, 0x52BF1F06E3722779ULL, 0xD367AE95BF82B641ULL, 0xC9ABB0E3275D8EEEULL, 
            0xF809475747C0D47CULL, 0x9E79F2D9BA94CB36ULL, 0x5A9482B57AEB1878ULL, 0x3B33EAC21D9835CDULL, 
            0x77D6A3330E9744C2ULL, 0xBABA61B951C9F95DULL, 0xF46F05DF8E665997ULL, 0x911CC7C1CC981AB8ULL, 
            0xE28F7CDCADDEB5C0ULL, 0x1A4B5B3DEB6D7673ULL, 0x0FB8808BC56F8C77ULL, 0xDC47118174748986ULL, 
            0x926A85389BFA53B1ULL, 0xFEC5A85ADB45B0BDULL, 0x3E30AE113F9B50C6ULL, 0x7F121908A2873E58ULL, 
            0xB9712A217A77FA67ULL, 0x32D83FA6FA854994ULL, 0x0EF0E024510E6328ULL, 0x295EC8880AC13554ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseDConstants = {
    0xB911A1E115463771ULL,
    0x053ADB0AD6F5969AULL,
    0x9FB6A41EF846F4B8ULL,
    0xB911A1E115463771ULL,
    0x053ADB0AD6F5969AULL,
    0x9FB6A41EF846F4B8ULL,
    0xE634E4AFD2F47D47ULL,
    0xAAAD055E435FFE8CULL,
    0x53,
    0x0F,
    0xDB,
    0x54,
    0x10,
    0x35,
    0x93,
    0x70
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseESalts = {
    {
        {
            0xB551BEAC1A5BA3C1ULL, 0x58E056798B1BCAE8ULL, 0xE47A3685C153460AULL, 0xA3BCBB54A2ECA75EULL, 
            0x0D6C78DEC0BC3C15ULL, 0x38E154BF46EA491FULL, 0x11CFF80934FDBC63ULL, 0x8D0794A54660F3A0ULL, 
            0x33B263B65330A78FULL, 0xE824F6F86C82DCE1ULL, 0xDEDD7EE2203C78CAULL, 0xAEF1535F2116CA0AULL, 
            0x492715CC57D21AAAULL, 0xB40276A30FAEE200ULL, 0x01995F92EF8D416AULL, 0x02BBA63BE0056625ULL, 
            0x7A4A909EFC47FE69ULL, 0x392F3C8AC990B358ULL, 0xF6A1573C005DD9DCULL, 0xED850BBB67414382ULL, 
            0xD028D8E755FA09F1ULL, 0x7D5B6C7DAFB6C4D1ULL, 0x871F3E01F3DE8C25ULL, 0x69A89295FF9FC546ULL, 
            0xD77070A4CACE736CULL, 0xDA24FC270F8E50DBULL, 0x2BFE575880DED7E4ULL, 0xD0222E2B070E3966ULL, 
            0x06035462FEE5DFF3ULL, 0xFC9B12837925FCADULL, 0xCBCB998764DFFC3DULL, 0xFAFF4D6B1D72DE5CULL
        },
        {
            0x61672EDA7E3E7B82ULL, 0xC6B18FFC03C68D48ULL, 0x9DEFB883C8F84D6EULL, 0x777D8BE10CDE4E4DULL, 
            0xE8B8E73EA2009895ULL, 0xB1F165AD50CB3469ULL, 0xD4929F4E65B89948ULL, 0xDF860B00DCAB8138ULL, 
            0x68700E5C9E5F433BULL, 0x1990C40E1A04321EULL, 0xDA26DC92793AC354ULL, 0xC133C35AEF56D627ULL, 
            0x25CEEB625A5D651FULL, 0xD26B66FC10CAC3A1ULL, 0x0070B358A638D9B5ULL, 0x686AEDADB1E8784DULL, 
            0x598B0EBA7B60FA27ULL, 0xAA0D6102B0E0680BULL, 0xC364924569C613D5ULL, 0x884B6B41165CDFFAULL, 
            0x0B1766309A7D56F6ULL, 0xF97FDD171CABCAD4ULL, 0x1126624802184C4AULL, 0xA472CA13486B8F2FULL, 
            0x131687AD5A6666A7ULL, 0xBF6EED8B94F27F8AULL, 0x86360ABE3380D5B0ULL, 0x8E80B5CB3F8CFE44ULL, 
            0xB292A3CF9D3A969AULL, 0x88A3326356842979ULL, 0xDE9CF9112B10CAEEULL, 0x11DB74A1D1322EF7ULL
        },
        {
            0x3416136DEBACC8ACULL, 0x6DE71FA48AA9E522ULL, 0x8F815AB60CF9FA58ULL, 0xFFCEDDED665D5EB2ULL, 
            0xADE4FB473DFF4236ULL, 0x88E95CD38EEF0F5EULL, 0xB496715868B7CA05ULL, 0x4BF4CFD1FD39D4A1ULL, 
            0x942733433B812AC4ULL, 0x54FD194CFC81F640ULL, 0x4B994CD41AAD1EECULL, 0x6FBEA06192EB62A5ULL, 
            0x75B01FD77A180E7EULL, 0x29C96A20C7F84623ULL, 0x12D8BB824B7AC24CULL, 0xE04F11F36ED673B0ULL, 
            0x583853F69121AA36ULL, 0x6255A52DF3E5D5C9ULL, 0xD6B492D0DE2912BCULL, 0x3B825DDB2863C45EULL, 
            0x318EAAC28F970561ULL, 0x51E5C1FB97AA9178ULL, 0xF816E9EFDE0FCCC7ULL, 0x3E4F50FB137FD8C3ULL, 
            0xA353DBA42666DB14ULL, 0x8651A841CD4209BBULL, 0x271F33FEC9CA2256ULL, 0x181A4B5C4520AE5DULL, 
            0x98636365A360F8CDULL, 0x6745A58A9450C37CULL, 0x3F110A61520B539EULL, 0xF7FB1131DA2A12B3ULL
        },
        {
            0xA208B679BCF106CDULL, 0xA1BE5D5C6D74C6E8ULL, 0x826C071F96A54D2CULL, 0x5EC56D10293DE416ULL, 
            0x331408594C3DA91FULL, 0x51143DCDF47CC956ULL, 0x528F6C24F2EED4CDULL, 0xC65712DDC1A3A0B9ULL, 
            0xEEE9098D17A3AB9FULL, 0x4823131698FBB0E6ULL, 0x0220BFC66DF89FBAULL, 0xB0A14B0960645D6BULL, 
            0x8F25DE045A66A377ULL, 0x9D1ECA3E6456B1EDULL, 0xC32D968BA70920FBULL, 0x380D130431811C43ULL, 
            0xD819A632BA1A7108ULL, 0xC037291973557210ULL, 0x4C210A6A821C466CULL, 0x9D9514B49E4C23CCULL, 
            0xFE51547741EE8A42ULL, 0xC69974F435E176E9ULL, 0xD56EC0D59429BBD5ULL, 0x1D39F1680D01C156ULL, 
            0x5E3B5A27558DB170ULL, 0xFB80692D01E378DBULL, 0xD8C6D7BBCEDD2CE0ULL, 0x3D3C4FE5FEAE033CULL, 
            0x314B15FB2CD8C79EULL, 0xB177F933E0254DB8ULL, 0xCE17D9CEE7402834ULL, 0xD571F647D6BE37A6ULL
        },
        {
            0x5367006A6535CC7BULL, 0xF6D7FC9D76F0F0E2ULL, 0x4019E75B7756E392ULL, 0x1E2334B6EECA19DDULL, 
            0xFC87425B63C4CE51ULL, 0xFDE9AB2ED1663979ULL, 0xC9D05DFBE53CF603ULL, 0x4ECCC2DBE3F62D16ULL, 
            0xE6F3CEC05C7469DDULL, 0xAD4F55A7CBE71103ULL, 0x3F9DF8473974291DULL, 0x842DA89389C01C64ULL, 
            0x4879D24ADCBE00ADULL, 0x942B9607FF9B3B94ULL, 0xC93A7A4A330118FEULL, 0x13678C32A25537BFULL, 
            0x50EF63E189771FDCULL, 0xB31FEBA6E30C002EULL, 0xB271CD60507622D9ULL, 0xB911048C1216D62BULL, 
            0x718B3832AFF0AB46ULL, 0xD3168D73688774E5ULL, 0x16EFEF4504BE9C7BULL, 0x46B0EB918984782BULL, 
            0xB7AE1EDA758579AFULL, 0x2FDA9AEB3F06D9CFULL, 0x0127F0A87E663DAEULL, 0x36721AF4AA5ADDFBULL, 
            0x3CBD195D25C512E0ULL, 0xE9A3906CCECF0350ULL, 0x72FB1D5B00CED2D8ULL, 0xECCF5AAB06C0A9F0ULL
        },
        {
            0x88737102C95BC32BULL, 0xB50A5FA59EE2CC8BULL, 0x5BEB1BEEAD55BB24ULL, 0x48BBD7E9682015B4ULL, 
            0x2BD6F8E37ABA7A58ULL, 0x53814FE933B8E127ULL, 0x3F1A7E1B27898927ULL, 0x93751E0B6FA819CBULL, 
            0xC6286BD383102972ULL, 0x140AB6FC270820D0ULL, 0xA62688C704007827ULL, 0xEE31AF626944DE06ULL, 
            0xF4732034B1DAE645ULL, 0x16E7E9A23C134EF0ULL, 0x72F2C865561ADCC0ULL, 0xA6F730A8CDCBF925ULL, 
            0x16161A52F45D34BEULL, 0xE81E356B18A80FC9ULL, 0x906B151E3FD434BAULL, 0x4B27D515D126B7ABULL, 
            0x55D9FF586C45F563ULL, 0x4788F3AAC5ED2E54ULL, 0x4A50CE04BFFE2B13ULL, 0x98976859CDEB3C1FULL, 
            0xD9C2E956B46CD17CULL, 0x5505FDB325D9F7D6ULL, 0x8EF650F7BE1C0CFAULL, 0xECE3F4B1F8B3B17CULL, 
            0x8B00D066805E1896ULL, 0x63696BE9A7A0C909ULL, 0xC88978DF1D9045A6ULL, 0xE32050576E61C935ULL
        }
    },
    {
        {
            0xE53865A40EAEBA52ULL, 0x2714E0695C83F4CEULL, 0xC12EE9F109832651ULL, 0x1F920CD3A0ECC1DFULL, 
            0x093AC5272B8E4D03ULL, 0xA34107A639C0A43BULL, 0x05A0E16724C866ABULL, 0x8A4400E3C3E30A74ULL, 
            0xCAE335C09283C5DDULL, 0x551EB8B494BCE31BULL, 0xFF3843632D363878ULL, 0x41EB6C2945025CEDULL, 
            0x41B4AB6C4EF2E4A6ULL, 0x81901CC7D5CB40C2ULL, 0x1ACF3ECFC5EC87FFULL, 0x8884E6F6CC1290A6ULL, 
            0xEBE88A2261EBB29FULL, 0xE388ADAF92928307ULL, 0x4E37A1DD9CF0882EULL, 0xB71D2585778B176AULL, 
            0xE0D91E0296F3705DULL, 0xEFD1E4BC16333A91ULL, 0x1C2B51B33F546795ULL, 0x1B74B26FCA995A4AULL, 
            0xBDBA1675058A1765ULL, 0xB225B95457A3D81BULL, 0x497623A8F63F1180ULL, 0x26B659F8C3E9CD68ULL, 
            0xAF3BF56C5052FEA9ULL, 0xED4C40FD7899A872ULL, 0x2C9E85128CBF50EAULL, 0x3606689ED5002217ULL
        },
        {
            0xA649836C15DDDB8FULL, 0x2B74308D8369577EULL, 0xEAF061402545AFD7ULL, 0x4FB3F18E5724D184ULL, 
            0xF2EF3C9024884D46ULL, 0x407F8F854CDB8619ULL, 0xE1BA22A1C1187482ULL, 0xC52254536DA1AD76ULL, 
            0x5408DF3C0F6EFC31ULL, 0xF00AAE54264723AEULL, 0x071E3D07E0E3151AULL, 0x476B1262639A2AB0ULL, 
            0x3FA5A2EA690543BAULL, 0x33C4062240C5077CULL, 0xA67D876F13A98A7AULL, 0xB7B15C2FD22FCBDBULL, 
            0xA6E9B5A10C8ED1C5ULL, 0x923BE8858CA6F2B9ULL, 0x6F50DBD30F43D8ECULL, 0xE69AFCBC41022D88ULL, 
            0x755307AB3D1C12DDULL, 0xD679183179857310ULL, 0x8B664536447284EEULL, 0x15F53AF8112823F3ULL, 
            0xF88D5D20E72789B8ULL, 0x4970249C9059E3BAULL, 0xCC66B180DD351C07ULL, 0xF2A202B49311D4E5ULL, 
            0x731663F27A10FA6FULL, 0x2EC83C5FA92D31E0ULL, 0x25670BC51C511FC3ULL, 0x483CD6951D8A739BULL
        },
        {
            0x9CAA5A2294FB55BBULL, 0x392F71B2D1F675C9ULL, 0xA2B8BCBD2969667DULL, 0x9909F7AD7C48E1B2ULL, 
            0x8742EBB2F12C6074ULL, 0xBD611B49049EE602ULL, 0x6340F415E676FADFULL, 0xAB67BD7B1DA2EBC1ULL, 
            0x218D94FC676C361AULL, 0x85D31D63CF07C3D1ULL, 0x7A8FE27468618893ULL, 0xB15AE5796EE75718ULL, 
            0x7B79585C937331E5ULL, 0x5238F8C0D54FC0FEULL, 0x127DC072E954CCC8ULL, 0x5E9BAE9A223E6B16ULL, 
            0x394BD48FC823FBDAULL, 0x12F1D287C623C283ULL, 0x017B4523E225CB9FULL, 0x2100FA466E8C0146ULL, 
            0xC2D0423648A7D95CULL, 0xB0437715AAE6BBB1ULL, 0xEFA79716BD71A106ULL, 0x877DAD7EB29BCC2CULL, 
            0x8CB2603C21BE887DULL, 0xFC88FE36EB190436ULL, 0x43913AF055E29C53ULL, 0x35EC758397C2F64BULL, 
            0xCF2213940DACC7E3ULL, 0xB7A04D790E5567FCULL, 0xD6D3A61DDD76EE35ULL, 0xF1721B3B37A50287ULL
        },
        {
            0xCA1AD946EC0681D5ULL, 0x185CA6FB5D288468ULL, 0x6D0F5D1DE71A9A64ULL, 0xBCE0BAFA6B158D84ULL, 
            0x55C795E23755A326ULL, 0xBA9D035C78D15D2EULL, 0x822FCD14FCD757C9ULL, 0xC0164E80751D6EFBULL, 
            0x7E02AC43313B3DBEULL, 0x1C2AB660C0678E4FULL, 0x9F1738AEAD52CC5FULL, 0xFCB2F16C6DF2BEF5ULL, 
            0x7D875D90284FD377ULL, 0xAE1D3AF8BD068B31ULL, 0xE8526097D4754AFCULL, 0xB461F2187B246703ULL, 
            0x2314CBE9F0D2451CULL, 0xBD143BC6BFC25CB8ULL, 0x4796E050562F66AFULL, 0xAA9BCEF84FF2478BULL, 
            0xCDA59CCB86497DA1ULL, 0x1FE95138AFB5CA52ULL, 0xB670C7CE473CCE94ULL, 0x4A2B53C7D2299D65ULL, 
            0x5ABA83EA1B4D33FAULL, 0x8EF6CAE4506D35B5ULL, 0xC3F03942D87CF9B6ULL, 0x930F1EF54094D0D6ULL, 
            0x83C67941402694E6ULL, 0x8020241C2A29D8F2ULL, 0xAA1BC13BF85F0966ULL, 0x7FC98E4B9FFB44F5ULL
        },
        {
            0x7A1DC785E860E90BULL, 0x0039E2707D76779CULL, 0x7C347D2C6EF7345CULL, 0xA958E9394D8705C9ULL, 
            0x9D8F9428C3E4DA50ULL, 0xE79B52C9F2F6BB7AULL, 0x4C44D03C5F58770EULL, 0x9576CC82A05E1788ULL, 
            0x44BCA1DCAAF0A75AULL, 0x8EDD867075F1374CULL, 0x3C65A3A5099D8E67ULL, 0x01CE59E313F4FA3BULL, 
            0x4A2592D36345863EULL, 0x913DBCCD9C60E07CULL, 0xDA8480B84D5B109DULL, 0xA4C9BEFEF631CB57ULL, 
            0x8C178988F979E9ABULL, 0x0DE452291EA1CFF3ULL, 0x5D1FE980103216BAULL, 0x18F87E12B268F7A9ULL, 
            0x806A824FF0ADC98FULL, 0x75BB4CAB543A274DULL, 0xB6D2653135BA6B09ULL, 0x6611D8B6DD6B99EBULL, 
            0xD23DEF0DCFDA1F55ULL, 0x5361FE99F47C6D2AULL, 0x8476E80C683E25D6ULL, 0xB45FA45854C85477ULL, 
            0xF64B597904D12574ULL, 0x3435B949FBA6EF29ULL, 0x5468DD0EE97E6801ULL, 0x0595E221238DF017ULL
        },
        {
            0x27AE80C1098D830FULL, 0x1657F7320ABCC1D1ULL, 0x9AF9847A7599FC36ULL, 0x46C14D8224D37FF2ULL, 
            0xAF03C489B5F0376CULL, 0x18C12A797208BA79ULL, 0x6606ACCB2900547BULL, 0x6908B0339048E95FULL, 
            0x45E2084E65AE3D62ULL, 0xF659092FC3E15D9FULL, 0x6936FFED9A0E4429ULL, 0x55082F26E4DEB9DDULL, 
            0xDEDFCB7C8B9055C4ULL, 0x0FDA3DF12EFA986AULL, 0x217FBBDF5756AB77ULL, 0xCF5936F9265166D6ULL, 
            0x3AB3F31566820F6EULL, 0xC3E39252A24F5B8BULL, 0x83F068F03925A86EULL, 0x9BD47E5FE0F5EA25ULL, 
            0x98172417BAE8760DULL, 0x485AB08C36CD77B9ULL, 0xBC892A933FA5E9ECULL, 0xB500B2B2FF3E4BB5ULL, 
            0x0C1C2D2BFC4F2857ULL, 0xC5C057CA5E5826E7ULL, 0x2F74BD180D9B7C3FULL, 0xE444E409D0A9782BULL, 
            0xDF384AC964B359CEULL, 0x42E2644425A4CF99ULL, 0xA0CE6D951BE38084ULL, 0x9E801621B55ED74FULL
        }
    },
    {
        {
            0xBEBFC14DA356CB1AULL, 0x38947CAF5477A64DULL, 0xD4C034E24134DE33ULL, 0xC2F053E980EF2CA4ULL, 
            0xEA850209F38B1D41ULL, 0x1ED37D9505CC80BCULL, 0xFBBF1B191037D84FULL, 0x93AD065B43365101ULL, 
            0xD2D0F2718C8671D2ULL, 0x04AF7A8A6A69DF4FULL, 0x07CE175F00F02E41ULL, 0xF273A5EE15DA7919ULL, 
            0xC011D8A2A77758F8ULL, 0xEFF04F2B04499136ULL, 0xDFEDEEE7075C3B26ULL, 0xE86F1DD0350A44E3ULL, 
            0xF239C4D0D1336837ULL, 0xEE2DABFDB9657A9BULL, 0x030FE303DE604DE3ULL, 0x7DEFA9C05B722519ULL, 
            0xC0966DCC81239BCDULL, 0x69070CEF1C265BE6ULL, 0xD5AD666128101362ULL, 0xC55DF114F0C4D591ULL, 
            0xEF47C1F27D579698ULL, 0xC038935626421577ULL, 0xD9388775ABB2E174ULL, 0x3700540BDF32870EULL, 
            0x212DE45795193505ULL, 0x2D68F4643928EF2CULL, 0x3313D8F1D6CF643DULL, 0xB590A138B9E8914EULL
        },
        {
            0xBD11E540E49D2734ULL, 0x64824F2C97592A8CULL, 0x2E76C8716CBF88EEULL, 0x94CDE78A46CA150BULL, 
            0x347E0C7C782E6727ULL, 0x178590B24F94D6B9ULL, 0x0FE4AF457BF7A329ULL, 0xFC891E3357B157F4ULL, 
            0x47911EEE87C90CB5ULL, 0xBA0B4DF53C4AABF0ULL, 0x17F8ED97ADEFB8BDULL, 0x2CE068A2A1430821ULL, 
            0xC063BFB3CEF857EEULL, 0xA9DB1D0D3D1E2674ULL, 0xD3A42418BC704B6AULL, 0x2E68FC8DCE0DEDDDULL, 
            0xC2A6E3CA415B47C0ULL, 0x2A0D196C7F3C6FD1ULL, 0xF89C162C4481A200ULL, 0x28E3822DA92366B2ULL, 
            0xBB283900EF128F60ULL, 0x0B0411FE19633F76ULL, 0x8BAB3581E8AFD884ULL, 0xE833B8401BCE8C0DULL, 
            0xB63AEA4338E2562CULL, 0xD9E58FA440501F96ULL, 0x884B999F9F3B9351ULL, 0xA407D254EDCCD33FULL, 
            0x379085B205E8966BULL, 0x070BFAF959CFD612ULL, 0xB65E19F070FA8DDAULL, 0xC28EA526A1AF1DAFULL
        },
        {
            0xE092E03BB33567A1ULL, 0xC7843C292306AD48ULL, 0x011E0C2C28E3A528ULL, 0x490E74BE647B3524ULL, 
            0x95E2D0C2C04CED9BULL, 0x78077F1DA5E2F1E4ULL, 0xD4C0B554EF3EC318ULL, 0xFD863923C9FCEDAEULL, 
            0x692A43877C0AE563ULL, 0x4F688EA2ECA73E6BULL, 0x0E691010A39686E9ULL, 0xC9C666C291BF9F76ULL, 
            0x92A223217AB95E75ULL, 0xF530B0D8AFC525CFULL, 0xD1643BB3143B80D7ULL, 0x03DB17420E67B5FEULL, 
            0xBEDBBDBDA024176EULL, 0x01D702F4BAE1E342ULL, 0x90823B1EC9C0CE40ULL, 0xF5949D42AFBFF9F1ULL, 
            0xB697A7748266BCE6ULL, 0xD02D312F6868FE19ULL, 0x75D346AE132ED26DULL, 0xC8956922E68CFB8AULL, 
            0x28154324C5A6A663ULL, 0xEA37D287210E7A57ULL, 0xD1465E7020407E8DULL, 0x826DB41DEACC25CEULL, 
            0xE29688264C774BD0ULL, 0x9EA0E253555E4D70ULL, 0x9554B71BD230DB36ULL, 0xB67973604B071935ULL
        },
        {
            0x083B866700169F2AULL, 0x35304BD725D09C43ULL, 0x1DEB742D9385B82CULL, 0x34F8C60910C5133FULL, 
            0x4DE219AF6AB004C4ULL, 0xB8AFEF85F7D96855ULL, 0xCC3C27C545917CE2ULL, 0x3BDFFDAE0C59BDCFULL, 
            0x278C40816719F62FULL, 0x6A0A4D18F6BD7F54ULL, 0xB84AA415CCC78691ULL, 0x61708C7679732BF5ULL, 
            0xF4770FE19D17027FULL, 0x9E57406D9F77380BULL, 0x7B6CDA0128C0698BULL, 0x432854618CCB3B23ULL, 
            0x7EB8E1AF4E24A0DDULL, 0xB52D18C05371F714ULL, 0xB2BEC9C559BCF6BFULL, 0xF30DF8240662C7CBULL, 
            0xA0524DBD5B36298EULL, 0x8A87776803CF1777ULL, 0xF29104460F1DCB72ULL, 0x3BB825F03E79E22BULL, 
            0xBDF70EFB5486512AULL, 0x1563798DA7F60A3BULL, 0x0701620022AFA1B5ULL, 0xA4801FE627EFB27CULL, 
            0xD925B24106EF12E4ULL, 0x2E11FE30518D50E9ULL, 0x8D83F31C1DD20606ULL, 0x56334B4726AA9D62ULL
        },
        {
            0xA2A438CE30885268ULL, 0xD6D6C2CC77426264ULL, 0x0CF0365DA5521B91ULL, 0xF5F9DE2C7DE441F8ULL, 
            0xDAE5E1B295ED8FBCULL, 0x70CD31BDEDEB6594ULL, 0x70F5F8A9C9718514ULL, 0xA52CB526DFF5A13DULL, 
            0xF648CA9E760ED223ULL, 0xB906EFBA9BBAAE43ULL, 0xC4570ACA49322F71ULL, 0x85BB59A7592591D5ULL, 
            0x953EC7E0A694F90CULL, 0x6AEAA6CA3567B53AULL, 0xB95CC9462D3FFABCULL, 0x615EC31A74D7FF79ULL, 
            0x3C34596187DCFFC4ULL, 0xB84510B0B3E523F3ULL, 0x7CC612AA51F56F3DULL, 0xF2DEA1F638845767ULL, 
            0x730415078D4EDB0EULL, 0x56577B0DA2C7E752ULL, 0xF5AE69E99D459E2EULL, 0x2C1AB0114A56B516ULL, 
            0xE3BE416C997A63E8ULL, 0x6FED76A33EA26CBAULL, 0x1246660BB8F058D9ULL, 0xF00006C804D66588ULL, 
            0xC14DFA5B95D08353ULL, 0xB001339273B2F94FULL, 0x79F5BF5027061EC2ULL, 0x7939D6F22431B77BULL
        },
        {
            0x362D2FAFB7E1B971ULL, 0x79298F7A8B7471FFULL, 0xC4EB4912ACFB7828ULL, 0xE2D1A86A608977AEULL, 
            0xDEF01938FFB67F19ULL, 0x173430CCB010C5DAULL, 0x9C3470D14ACDA96DULL, 0x3CA594F78A01ACBBULL, 
            0x4016FEFE9F6711C9ULL, 0x1CCE87850DEC1130ULL, 0x62549BF0284AC5D6ULL, 0xACDFC4E6D0E65B08ULL, 
            0x190CB91E0FAC9D5CULL, 0x6AD0C33CF9D4D858ULL, 0xDCA5DECFEA6249D4ULL, 0xCEE8D3C978B3DC47ULL, 
            0x25BDE0BC9EB762B1ULL, 0x53F74E96A4E0EC7AULL, 0xBB941E6D6FEA980BULL, 0xABEE836DEDEE8A76ULL, 
            0xB1F00A41D144AA7FULL, 0x1EE2C034E7044825ULL, 0xCF5E5D3D1E0E1F57ULL, 0xAF6BB60180F0631AULL, 
            0x8E211FF60C92F3D6ULL, 0x67A28D3663D73F7BULL, 0x183FF22EFDE56E5FULL, 0x40629A1B43EEC4CBULL, 
            0x8F30EF2F47928EA0ULL, 0x6A7543F17CA46FA0ULL, 0x2AD0E21F4F800682ULL, 0x884D2D555C1678CAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseEConstants = {
    0xA9A02FF31C70EAC8ULL,
    0x8B2D973F25ECF41EULL,
    0x80780358CAD94E2FULL,
    0xA9A02FF31C70EAC8ULL,
    0x8B2D973F25ECF41EULL,
    0x80780358CAD94E2FULL,
    0xDDA56294D7121F38ULL,
    0x7A841C6D96A35777ULL,
    0xB1,
    0x48,
    0xF7,
    0xBD,
    0xF5,
    0xBA,
    0x3C,
    0xCC
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseFSalts = {
    {
        {
            0x66269E1B74849ADEULL, 0x0E5230FFF3B482C0ULL, 0xC696E5EB15743EEAULL, 0x6D317DE12C50EF9BULL, 
            0x08D7AAFDF03367CDULL, 0xBA3BDE0E067653ADULL, 0xED3B56C461CDDADFULL, 0x77917BDF67076FB5ULL, 
            0x4DA5A420394C87C8ULL, 0xCD878E79C3C1E63EULL, 0xE448521E4CCEDE8BULL, 0x74D0A1910A2440F3ULL, 
            0x9748A225F81A86BFULL, 0x9E51E4E0F6A4F01AULL, 0x3775A8CD37CCE60DULL, 0xF56916EA0A0D06A3ULL, 
            0xE653AA08A5087C6EULL, 0x4F5B712D5DE9DF43ULL, 0x19CE7D9D37817FE2ULL, 0xF42D8876E97F2ECEULL, 
            0x5EA51B58C75F286CULL, 0x6A6748CCCDC97FD6ULL, 0x2E87B2089AA20329ULL, 0xAA25BBFA15520A52ULL, 
            0xDD9D795BABA20DC5ULL, 0x41A342EE34D1AF30ULL, 0x6389406B7E230556ULL, 0xE5E8EE374A7A38F2ULL, 
            0x681F24F2D497A353ULL, 0x3125A5CFDBD8C873ULL, 0x17D04F18ABACF882ULL, 0xE5A867D2ACCE8187ULL
        },
        {
            0xC486B491822D7313ULL, 0x20DCA7AD2B0F52E0ULL, 0x9F8CA0CBA7CCFC4AULL, 0x3C932C5145450EB6ULL, 
            0x0650652B52FECE79ULL, 0xD3A8950F8C58700EULL, 0x56EB03B843F2C6D0ULL, 0xA41FA1724D4B4E25ULL, 
            0xA8C595A640FE63EDULL, 0x6AEBD7C943757EE7ULL, 0x97167C544B315711ULL, 0x31440D510BD66AB2ULL, 
            0x83D9D2AFF04FC152ULL, 0x372B2754547D27C3ULL, 0x3F7790785522B6B8ULL, 0x5D944AF11B631EEAULL, 
            0x92E5402BF7A8A4B7ULL, 0xDF0A9B5A68BFCB5EULL, 0x644EE1FBB95D2A4AULL, 0x6BB1E19B29F42ED0ULL, 
            0x0D2C7E5FB9853515ULL, 0xD6B9DFAEB4FF6FF0ULL, 0x737E661784AA897DULL, 0x6B5F6C3581B45EC4ULL, 
            0xAEDCD4E61BA81AFDULL, 0xF8E3F742662EF063ULL, 0xDB405C9DF4F21FCAULL, 0xE7EC96AE5454E5BBULL, 
            0xA32314ACA9051C31ULL, 0xAC678557ADBCDE46ULL, 0xB409543418DF04BEULL, 0x6C0C5C34A109DCF3ULL
        },
        {
            0x75CF2EFD6FC4B65EULL, 0x5AEA7BC10F319F9EULL, 0xE3A663FC34056493ULL, 0xFC7B32E633DAF35DULL, 
            0x078D4E42F869E588ULL, 0x2A3912B316B28B56ULL, 0x83E4F370BDFC4057ULL, 0xB92C9915CC89218BULL, 
            0x745FE6918509CBE6ULL, 0x2842EA76047B879BULL, 0x5700BA100E67819DULL, 0xA46218F8EA903BC4ULL, 
            0xC3098E213C0C323EULL, 0x19653901F0CA772AULL, 0x23C3A3614915F9FBULL, 0x3C184AB19865149EULL, 
            0xF705A9A83FDB7CDEULL, 0xB7E0BBBD52CDC632ULL, 0x0D7E2277CE885301ULL, 0xC8B9378EA32D3C74ULL, 
            0x472EB6014025848DULL, 0xCAA749BDCC366C78ULL, 0xCCB8849629A1865BULL, 0x35B05E396962A868ULL, 
            0x070E836AFA95BB1FULL, 0x78236CBB7976D9B8ULL, 0x8C7CD9C2E73D9812ULL, 0x2AB040733BE488AAULL, 
            0xEC4749F8C84D5DA1ULL, 0x0BC44F5C116745DBULL, 0x3CDDCE2F230DEE65ULL, 0x5F30AA054DB8D906ULL
        },
        {
            0xEE4922E4B0EE4450ULL, 0xBB77B3E53A3B094DULL, 0xF1657A11BC38B2CBULL, 0x97DA9396CDD0EA08ULL, 
            0x60D83E616B1770AEULL, 0xD033A1361654B15BULL, 0xC792DC5329B64215ULL, 0xD8B914533664B88EULL, 
            0x33E55A994B82D0EDULL, 0xD2D5A4C5DA033275ULL, 0x0185E027AACED4CDULL, 0xC675E164A1CB475FULL, 
            0x09A6317002E33228ULL, 0xB2831996A289928EULL, 0x437DFEF9113E70DEULL, 0xB0D4B8F2E4549C6AULL, 
            0xBD7050E196AF8FA8ULL, 0x7399323884060BCFULL, 0x189FA16048080B3BULL, 0x0F8416C59C561806ULL, 
            0xF2D5CC306792295CULL, 0x9EB1808095FD9691ULL, 0x719BECF8EECA8FBBULL, 0x296A54E25C532431ULL, 
            0xCC41B45712C58F42ULL, 0xCD8D7F1A9C781A56ULL, 0x533EDCD69F165EE2ULL, 0xB3D5654FF05CF517ULL, 
            0x33AD4B114AA62DF8ULL, 0xD296BB8D93A2D83BULL, 0xCB61760FCF154BCBULL, 0x7ECE10233248A1BBULL
        },
        {
            0x1B3A95ADD326CB56ULL, 0x173425EB435FAFE3ULL, 0x5524194CD1DE45D6ULL, 0x1FE906101E2DBB3BULL, 
            0x52C53A974644F8F7ULL, 0x5489FEC6FE483B9FULL, 0x7F3797D637446F87ULL, 0x5A06EFD100528A2BULL, 
            0x4D217D1A3E48DBD0ULL, 0xA97930A2F187FCBFULL, 0xB5C7F423656DD6F8ULL, 0xB672C37910285A57ULL, 
            0x9BD6E2D59FAC3583ULL, 0x8FC912DB1FCEDF02ULL, 0x0274975D999D67D4ULL, 0xB973C541DB7F17E2ULL, 
            0x6B3FD3AAE1437D99ULL, 0x0F6074C3853179DDULL, 0xE67B3F9769CD104CULL, 0x3B40B1ADBBBF12C3ULL, 
            0xA0538C4B661F790FULL, 0x470D376BDEF77452ULL, 0xEC7DEFA7DFA7D4B0ULL, 0x81AEE43A0D9818DAULL, 
            0xC5C58AC34425140DULL, 0x78B6F9EC73392740ULL, 0xCDA55FC6803D71A9ULL, 0xE4B826176B320961ULL, 
            0xF0439956120202E1ULL, 0xC8E29BD95D2774F7ULL, 0x8E09111FE7DAA1A4ULL, 0xAEA395B3CFD1B041ULL
        },
        {
            0x0785D19919C51D46ULL, 0x16A939D98877F931ULL, 0xBCE0066C1C1820B1ULL, 0x549837801BB65817ULL, 
            0xB72710A67957277BULL, 0x6FF7D549BB3C93C4ULL, 0xDE79E606748F8410ULL, 0xF2FC17A79119E8EDULL, 
            0x82EE61819AFE0E41ULL, 0xED0065BBF205E333ULL, 0x709778D55514BE7FULL, 0x1B25B279993FA2C3ULL, 
            0xDF3EFFC83DC23B11ULL, 0x3C48B55384839993ULL, 0xFE18B2DF11F5A947ULL, 0x2C72F8A407E137F3ULL, 
            0x5C23A7256EF4BA63ULL, 0xE29DE9F770FD1F75ULL, 0x1D4684C8F524DB4BULL, 0xD299D8399DF882EBULL, 
            0x2D701422CC83C99FULL, 0xFB85D9956800F19EULL, 0x5280B67CD2B29734ULL, 0x477A88DDA41DB97EULL, 
            0xA70CA61ADD6B0099ULL, 0x3FC3B5EFCF8B9556ULL, 0xFC9F4619A265256BULL, 0x484AF038A3613C90ULL, 
            0xE022A1B176DFD6CDULL, 0xF9D31DE2DD5BB9D7ULL, 0x91F388C46823B14CULL, 0xA494FD7464ED1A4AULL
        }
    },
    {
        {
            0x91DCFB86766A8B00ULL, 0xC639BE1DFA9C9B2BULL, 0xC8F878BDFF13770FULL, 0xDD01404D9EA4747FULL, 
            0x12B10B66664C2D4BULL, 0x49B49D436912453CULL, 0x38F1A39154822528ULL, 0xE1FA19CBC3C2E211ULL, 
            0x895F57B38716903AULL, 0x950466CB01A8F94CULL, 0xB752471933456E35ULL, 0x9431F0E590663FCFULL, 
            0x5F5782AF3DE3825FULL, 0xCBD8DFB478706CEFULL, 0x152D617A1F5989BDULL, 0x00B984DB2D6B56C3ULL, 
            0x442B481075359BDFULL, 0x4344D367D798C41DULL, 0xB655A6CDC56B9B90ULL, 0x52CE9BDF99EA4BCBULL, 
            0xE3D7E0E16FBF5CF2ULL, 0xC5433C798636B885ULL, 0x9167614C4AFC4A3CULL, 0x4E76FA57A2F1E458ULL, 
            0xAF21A9EAF103D9D9ULL, 0xF5372373E92D2BCFULL, 0x9152E6F6CD28EE99ULL, 0x956C4F9F70EBF78EULL, 
            0xDF5B1259A2E340CFULL, 0x3A11834B20F6D0CBULL, 0x331FF91BAC696646ULL, 0x6B6251BA12DFB357ULL
        },
        {
            0x34B40A97E13B6E28ULL, 0x29F91B46F9FE10E5ULL, 0xC628DAFBC4587496ULL, 0x836F762C942DA527ULL, 
            0x735C40FB0F78E9EDULL, 0xDFF1244660F9589DULL, 0xDF236C0F70006576ULL, 0x66B952DB94DF7400ULL, 
            0x47C141657953999AULL, 0xCBE5C83DC5F714A4ULL, 0x39C8C55038C6A313ULL, 0x03160BECE5C1358FULL, 
            0x743D90C197BDA64AULL, 0x11E780C99172DF88ULL, 0xB3B6B45A4CC62837ULL, 0xC761913A428F3CFDULL, 
            0x6EA94730AEBF2D1DULL, 0x7B39F5CA5E6C8077ULL, 0xEAE0584AE372286AULL, 0xEF5A747D7810C362ULL, 
            0x3B6DBFA5567B83C8ULL, 0x6464C5F08084B883ULL, 0xFB5BE11F167403E5ULL, 0x95A2F9216760D266ULL, 
            0x4D066DA210BE7E87ULL, 0xC5225F274242C432ULL, 0x8E3ACA1422B82997ULL, 0xED4E8F8045B95BEBULL, 
            0xB82C4CD8750F9805ULL, 0xE70C9F2A5437F1D1ULL, 0x88DEDD60A7266AC1ULL, 0xAD72F503DB4F95CBULL
        },
        {
            0x9F3A3C257782794BULL, 0x61BBC9F7B450C6FAULL, 0x5A95890BB80F1DF0ULL, 0xBA0D006401CD5127ULL, 
            0x9AFA1E624B74508FULL, 0x74F965B9A324742FULL, 0xDB3E976BF9D7BFB4ULL, 0xA9FC8977DBAA11F3ULL, 
            0xA3F5E42EDB90F1C0ULL, 0x735A5C3A94231C60ULL, 0xA40255193F596787ULL, 0x345471850B9E8F1AULL, 
            0xCC2CFB99AE707E3EULL, 0x3D313958B5DD6247ULL, 0xBB2F9D28EEE921FCULL, 0xB210F67B83C520A0ULL, 
            0x926FF4506121BB33ULL, 0xE606DEC85DE3AE0FULL, 0x50014749F9755FADULL, 0x3D6F25517B5293ADULL, 
            0x485766166675BF22ULL, 0x4A067185F3F82D6DULL, 0x7A2A9BEDFD333999ULL, 0xF1A6FF283A0F989DULL, 
            0x73E524810425C216ULL, 0xA6E17CF0748D6A63ULL, 0xF7240AF83077C945ULL, 0x7AFEE4A4B72D4776ULL, 
            0x74EC2B14380A7C93ULL, 0x12D55220F8E8A499ULL, 0x16ED26A845B64C7AULL, 0xFE97D9E328387A18ULL
        },
        {
            0xFB4B9365E84AD25DULL, 0xE86C3836B9189E81ULL, 0x12EBA4DAFD41E380ULL, 0xE95294C0BD4B5EEEULL, 
            0x7F26FCAEAB0E7E1FULL, 0xB39BC15DF4A6BC51ULL, 0xB3CFC8B7F28DDA56ULL, 0x33A44A195B2CCBC0ULL, 
            0x85B713BBA1FBAC85ULL, 0x420BAE20B6654DEEULL, 0x17CF878DBDEA3E29ULL, 0xF18BA6BDC11196ACULL, 
            0x0B2DE6C3606B5568ULL, 0x9649BCC6D3DC9E12ULL, 0x323AB95D5002B267ULL, 0xFC8434C249F6D572ULL, 
            0xF79848EF2589EACBULL, 0xE2ADC29B6D31E760ULL, 0xBC4B19906497C030ULL, 0x54848BF246A2AB5CULL, 
            0x7F9C9E90BE3BABADULL, 0x4B484FD21C4F1F1DULL, 0x1D5CEBAD6F62DE12ULL, 0x73680B7FCE11BF25ULL, 
            0x8276BFFE594117F6ULL, 0xE7B86079BE4B841CULL, 0x6F28F032AA72B75FULL, 0x3EE0FD513A2B501AULL, 
            0xCA7A4A95427253B1ULL, 0x1739F25DB78B729DULL, 0x7C698313A2C05798ULL, 0xD6120E6835F06888ULL
        },
        {
            0x9B55FF1F82B34255ULL, 0xF7881EFA24626890ULL, 0xC6BD3C5C33D1152DULL, 0x1E23E767F21AF13CULL, 
            0xF0ACE3134DE8C3B5ULL, 0xFC1906DBB130980FULL, 0x510498B31ECB0681ULL, 0xACF6C010C85D3D6DULL, 
            0x13A170054C64E3D6ULL, 0xDE504E99CF68F400ULL, 0x0EC2798DDD7FA67BULL, 0x486CCE65F9C861D1ULL, 
            0x7DBC897A55139384ULL, 0xC3406E0607ADCC0BULL, 0x27F0D940D6ADAF34ULL, 0x873566F7D2794F11ULL, 
            0xBAEE5B41A69F05B8ULL, 0xEFD9B406661C2828ULL, 0x3611DBBDB88CCFB5ULL, 0x5BC72365A9B7847FULL, 
            0x1538FB0D217EB971ULL, 0x759A8CCAB01CABF1ULL, 0x57370B8DC2F85B97ULL, 0xACCF285A2DAFEDD5ULL, 
            0xA88A871D0862FA78ULL, 0x802BD8BF4CED6DC7ULL, 0x452023488C6DBE5EULL, 0x9BF54F6996941B16ULL, 
            0xABDBB55A1ADBC44EULL, 0xA86D87ABA22459ADULL, 0x6CF9158FC2D0D76FULL, 0xB2CA2D6B4DEC477DULL
        },
        {
            0xEC7ADDCB2A465E81ULL, 0x64EE65E6C60F8645ULL, 0xD6CEA641BD5760BDULL, 0xBAB0E052168C9B62ULL, 
            0xD76C0569EC240EE1ULL, 0xB6DCCDC5B381A70AULL, 0x99DB1FF90F1E6414ULL, 0xA9C44F3B9C7D6E7DULL, 
            0x36689583BA73EC6CULL, 0x47D31230AA8C5C82ULL, 0xD75009DD01BCF704ULL, 0x4FE2F7000B28137AULL, 
            0xC522919A005E8CD2ULL, 0x0808F2052378168FULL, 0x91CC1AC73873F71EULL, 0x331FF1E8D5F51ADFULL, 
            0x21BC19C574400D02ULL, 0xAA86AF39BE867ECAULL, 0x14E25229C4024422ULL, 0x38DA1DA800A107D8ULL, 
            0x768C9E8263E4D185ULL, 0x3D9A5E6F31EE986BULL, 0x2D2E5F023F8DEE8FULL, 0x70A6C2F49A657BFCULL, 
            0xE8291F8A75903315ULL, 0x5B5CB7242A86CE19ULL, 0x72EB6EA904E9B750ULL, 0x431DED69A71C0049ULL, 
            0x5E73D3952A905B61ULL, 0x4B72EF93959ADDDDULL, 0x8587FBDF874CB9DFULL, 0x385333B2676A1BACULL
        }
    },
    {
        {
            0x9874C598CBC78C8BULL, 0xE597B4C6D6271722ULL, 0x851C8CA1A4750BACULL, 0x178DFDAB0CB66D2CULL, 
            0x8BCE99E1EC5E93C7ULL, 0x63B9D804636D966FULL, 0x6AFEEF0301F63C7DULL, 0x546E1C2D03864A04ULL, 
            0x0142B7FBA09C424BULL, 0x4E191D359F85788DULL, 0x14CDFC5BFCCEF0D4ULL, 0xE7B5C19C1BFCDAE4ULL, 
            0xD41889958D824953ULL, 0xA346B4D67285C03AULL, 0x0D4C7F8FD3E21B2EULL, 0x0AAF19658C1EA33DULL, 
            0x18257389FCACA8EFULL, 0x27C70F62C3133B09ULL, 0xBE2A96949A62C647ULL, 0xDF2276578EA495BCULL, 
            0x5EA1F0CD238C2C0AULL, 0x1F53DE0C4CF81722ULL, 0xDA6ACA2C37663EBDULL, 0xFB9CA75996E0BB7DULL, 
            0xD5959A47343FB0F2ULL, 0x179C7896C11FC88BULL, 0x5D1A94EB0407C4A0ULL, 0x9E44B5DE2E2AD198ULL, 
            0x0481414CB72DA70FULL, 0xD1E5595E44103591ULL, 0x78AA6CF2CD8BBED7ULL, 0xCAD840FCC379EE05ULL
        },
        {
            0xFFB78BB3D1E52CC7ULL, 0x8D56F5374C143BFEULL, 0x4D0AA7A361EB4DFCULL, 0xA2B525AA42F034F5ULL, 
            0xF6386215E996A75EULL, 0x3F457161355AD6F4ULL, 0x858EC46E178503B0ULL, 0xA56524C32428DD08ULL, 
            0x5D683D5D9680668AULL, 0x33B44BFBDE92C080ULL, 0xE9B9F30DFE1FA251ULL, 0x8E0C0C6FAD52C601ULL, 
            0x6518C69712E0B2B8ULL, 0x1B6BE6BDDA7783D3ULL, 0xBFF159AB24A89F3FULL, 0x4F6D53B7F6760351ULL, 
            0x1449DF047ECEE698ULL, 0x67D5592DAA0E9E17ULL, 0x58FFF2F8007FC0B7ULL, 0x813EA3FF11739C8EULL, 
            0x4078ECC89C0423C7ULL, 0x6A3231CCE2BA5B04ULL, 0x4103F7A0E51E9BE4ULL, 0xE1E8CFE72577CDD5ULL, 
            0xB2358F71CCDC3AAFULL, 0xDB42044CBE4AA2C1ULL, 0x9C88C47CE6EAC847ULL, 0xED7113F2CF92BF34ULL, 
            0xC6D743F80EA7521DULL, 0x566AE3261CBD347BULL, 0xB38D700E09CAC5C0ULL, 0x89D42A836475A26AULL
        },
        {
            0xEE4FA72CB66B2C70ULL, 0x8084AD11F8E521DAULL, 0xD94587A9BA308717ULL, 0x6E0C12D23026A4ADULL, 
            0xD0C93B008E834BC6ULL, 0xB7D083C799F07829ULL, 0x5E8BB96900A030D7ULL, 0x328141DC67986269ULL, 
            0x68D26CC81A734CF1ULL, 0x4151579AC0F48644ULL, 0x259D67CB7EEB2096ULL, 0x2D3A0A96C05078D7ULL, 
            0x43657C9A5757B99AULL, 0x067F50DE2968AFAEULL, 0x123FFD0C7D32E099ULL, 0x0762AD02EC481810ULL, 
            0xC578CB86FCE1768AULL, 0x3F984A2A9C5CD073ULL, 0xA23991E5CA7BFCB2ULL, 0x89CF564E28029270ULL, 
            0x33DF39C5D9A3517AULL, 0x3412B6768DF9DE50ULL, 0x7C47C380206B46E8ULL, 0x3F1C6455074C3CE1ULL, 
            0x46688FD1B815ED6EULL, 0xDA253DD7D01A81D0ULL, 0xF4B2C84FB2366528ULL, 0x7899DFF89723F8B3ULL, 
            0x88B364D4F3310868ULL, 0x8B5B7E8145BECD32ULL, 0x119240EF1732FDFDULL, 0xDC332EE9841ED23DULL
        },
        {
            0xB5749C2E60965E5AULL, 0xCEDBA09ECB9E70F9ULL, 0xD8762DDFA69E4780ULL, 0x56D9756675196E91ULL, 
            0x27EA9259F798E8D7ULL, 0x16CD8B0D10F709E1ULL, 0x0344498E66DAEBCDULL, 0x4CF4E5C52D199563ULL, 
            0xBEAAE686C88B0C7CULL, 0x9760A4A1E3F8A046ULL, 0xF520B8C22DA598CAULL, 0x60456F7E67A096C7ULL, 
            0xF61ED6B13C4DC697ULL, 0xF81E834F64284F07ULL, 0x68B61CA0EBFA2D09ULL, 0xFE43E86428C1A3B6ULL, 
            0x543EEF509A96732AULL, 0xF152449C55E59440ULL, 0x6A83183B20DAC162ULL, 0x17FE7559B02072E6ULL, 
            0x3E90B1423DF0A807ULL, 0x5D6ADC95AB91EFC6ULL, 0xA46E8C79B64DF017ULL, 0xCBA726305467BD22ULL, 
            0x5F021A78E0F192EEULL, 0xB95EB8410AD60BA3ULL, 0xA98FDBD15C067C35ULL, 0x98870F8B3780991AULL, 
            0xEAF531939345C90FULL, 0x4C8F4D994BC009D2ULL, 0x1FFFF546A0E46A18ULL, 0xFDE2587FBB6184EEULL
        },
        {
            0xF4B6F2518BF288C1ULL, 0x88B63C2000EF66B6ULL, 0x9BF9DCEF72CDD998ULL, 0x2DAA51DC8D016B21ULL, 
            0x15A0A69B3B686A88ULL, 0x423C56088EB77CE0ULL, 0xF8B31119A880F3EEULL, 0x67420A81CE3A7021ULL, 
            0x54285B77CDDE97FEULL, 0x77DF625F508D91D9ULL, 0x3AF64970043BA083ULL, 0x3DBC2214EA000CDAULL, 
            0xC92EE0E87257351CULL, 0x0D60F5B2FE2CE053ULL, 0xE6314D15F50778B9ULL, 0xF1648157A82F3B04ULL, 
            0xC912E2466E5CAB43ULL, 0x79E49C03C4377F50ULL, 0x9DA457876C2C045AULL, 0x5C99CA0473009B58ULL, 
            0x850CEA311B259E79ULL, 0x54056BA6974AEC00ULL, 0x58BCCC307D738CF7ULL, 0xC918E0DA54292040ULL, 
            0x352EB82FA30D4F1DULL, 0xAD3ED6FE6DAD5451ULL, 0xB8B532745A5E9385ULL, 0x2584B26A8D6E792DULL, 
            0x2E554E7FB01C5068ULL, 0xED130C4610BE14BFULL, 0xC448190B0772941CULL, 0xA38919903FA6E344ULL
        },
        {
            0x305E41499F8D5343ULL, 0x4A95ABEA995C96DCULL, 0x250242F9E1878DF1ULL, 0xBC30C361473BB95BULL, 
            0xE1108C1DD35E4880ULL, 0x2BC32DBE09E0A62DULL, 0x40A1518B6FB3A2E3ULL, 0x063EA6B4EE0286BDULL, 
            0xFDC17DFA5FD3EA0AULL, 0x074480D79BE2C731ULL, 0x5D0EBEC0E44FACF4ULL, 0xE234B878EF1B3BD7ULL, 
            0xE94406F76E152403ULL, 0x2E163E93D8B0ACB4ULL, 0x1CC4C73BFB2E3903ULL, 0xD876632EE56DC4D1ULL, 
            0x17CC4389FD55B82DULL, 0x775A410EE1652A39ULL, 0x0C83EFEFAE601EECULL, 0x353ADD381B302E5EULL, 
            0x014E35958CE2ACDAULL, 0x2B8207C77B59EA18ULL, 0x2FDE97A73D23462BULL, 0xAC145A3A304B0A26ULL, 
            0x0FC838E139E39ABEULL, 0x940B69CDB57F35F0ULL, 0x6E88F5B33399B2E2ULL, 0x6A33948A8C84D11AULL, 
            0xE386F93C7EDCD356ULL, 0x0F20095EAE791208ULL, 0xC45C15A95F189584ULL, 0x15EFCC4D3CDD1989ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseFConstants = {
    0x88339F4E91FFAF0EULL,
    0x22CB22182B697F1DULL,
    0x68B0D9FF662A9A61ULL,
    0x88339F4E91FFAF0EULL,
    0x22CB22182B697F1DULL,
    0x68B0D9FF662A9A61ULL,
    0xAF2596AAF0F86A42ULL,
    0x43440416106C7FD4ULL,
    0x47,
    0x8D,
    0xE0,
    0x28,
    0x90,
    0x74,
    0x5F,
    0x44
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseGSalts = {
    {
        {
            0x7DE84F0899056F55ULL, 0x5E239BFB73D10CD0ULL, 0x680CE18E3844F6C6ULL, 0xDBA8951EA2EB9013ULL, 
            0x8134D37DCA3C5C28ULL, 0xD8AEB2FA4930D85BULL, 0xFB184ED1E6851215ULL, 0x971D148176D8DB0FULL, 
            0x07278984BAB73D11ULL, 0x5272BD72E4D38E76ULL, 0xEF743264666D2E3EULL, 0xDB015A23CFC43262ULL, 
            0xA655299AE78452DDULL, 0xF0B0BD62453BF015ULL, 0x7BA563B836ED6A81ULL, 0x0AAD333AC68077F4ULL, 
            0x38465852BD69C0EEULL, 0xEF166286FB532DC9ULL, 0x186C93823C1B06C4ULL, 0x7970FF442C9164BCULL, 
            0x63244A693583C628ULL, 0x036A034B80D31D1EULL, 0x1EE6649BD9279E97ULL, 0x30BDFDD7522AF6EEULL, 
            0x11CBA9348FC81523ULL, 0xF62ABF53E8998EB7ULL, 0x3E169064E2EED08DULL, 0x7EF50E6D696FAC6DULL, 
            0x2997C30C610BE5EEULL, 0x24F2D299F149A5ABULL, 0xB4F6ED4D29DAEB75ULL, 0x0ECF6DDC0458A5B6ULL
        },
        {
            0xE6FAA721A572586FULL, 0xE3DE32B04359EDC8ULL, 0x15A4774547F2B952ULL, 0x890A26D0F01A4FF8ULL, 
            0xD02ECFF2628328B2ULL, 0x02536C0ADFAD6BE6ULL, 0x648345263A2F8AAEULL, 0x1C36CA657F5DC9C6ULL, 
            0x7A298300BF600F11ULL, 0x147C2793B01856D3ULL, 0x3C65CCD78C552089ULL, 0x187967DF1A361BE5ULL, 
            0xBCADF48DF3F4415DULL, 0x1C4773900D34BF6AULL, 0x82F1A7ED838090E6ULL, 0x437F3934DA92AE24ULL, 
            0xC569B12A0BF8B4C0ULL, 0x1D2E45EA3DAF30F5ULL, 0xCF63D0445F909513ULL, 0x0C53D74CE4D6F967ULL, 
            0xA98C2E187D5FCB16ULL, 0x5131B0AB65E71B76ULL, 0xC288CCAACB42D691ULL, 0x27D5C5DBF37443F6ULL, 
            0x10EF67B1E05BCE2CULL, 0x9100E7B9BFFF6151ULL, 0x396F5462C31EC3D6ULL, 0xA5AA54DB7CF4E51EULL, 
            0x3B2F116F9BCC1882ULL, 0x3E7AE199D4F8C1B5ULL, 0xFC80B7D66A7C18F0ULL, 0x7E41BE411F1A77ECULL
        },
        {
            0xB2A5C55A5A4F6D80ULL, 0x21B239668537D48DULL, 0xE7C4C8A52DF3176CULL, 0xD550766DA53073DAULL, 
            0xE225F6102582E0ECULL, 0x4543DC2883829323ULL, 0x27F18C31D0E45176ULL, 0xFA24D45262E59217ULL, 
            0x136E675AC20539CAULL, 0x9344F9C9AEB2E21EULL, 0xBC94D948B321F107ULL, 0x78EDF4AD741D7C79ULL, 
            0x28B88F48513DD064ULL, 0x9EFE4665D5E275F1ULL, 0x828B46419F1BFFE1ULL, 0xAC7355CF0FEC3F2EULL, 
            0x01C467E83B0FADA7ULL, 0x960D19FF996E5230ULL, 0x1E352B1A5FB06328ULL, 0xCB67BF90F9A00FC8ULL, 
            0x7F34C03590AED9A2ULL, 0x644F552A711BA675ULL, 0x34909D006CB6DF67ULL, 0xCD5CE298550B56D7ULL, 
            0x31BD8CE439C58485ULL, 0xB2068812AF9F6589ULL, 0x22BDA0BB54984E9FULL, 0x05CAFB4AA964ED6FULL, 
            0xA0DF0301DBE2141FULL, 0x54590663B83497FBULL, 0x9305B24A2A717FA8ULL, 0x69D76FDC0CD0188CULL
        },
        {
            0x8CD4D351A64E7F6BULL, 0x86CFCE8546619A14ULL, 0x02C2F65D9849A037ULL, 0x0C47326C25DB34E2ULL, 
            0x4317F2C34B8F9B13ULL, 0x4E660E43AE6B67B1ULL, 0x2F959740A879895FULL, 0x36C9ADA09A960884ULL, 
            0x6AD039BC236E6309ULL, 0xE7535F3F920D89C1ULL, 0x415B16B0B86C6FAFULL, 0xF8FC1EA83FCA38BFULL, 
            0x29BAE22E741B717BULL, 0x4C2A44FA55640CF9ULL, 0xED0CFDF86B6F79B2ULL, 0x8CC47AF77A493FCAULL, 
            0x445C6E9309540014ULL, 0x049640E66FBD6FFFULL, 0x14048BE62A2E71B2ULL, 0x35202A6C1514F526ULL, 
            0xFBCDF8FBA450DAC9ULL, 0xFCA069DF9FA356A3ULL, 0x7C99AB4D2325536FULL, 0x2BF909E1F3EC3FFCULL, 
            0x86509452A9D55EB7ULL, 0xFCE4FA6ED89E27AAULL, 0x9625D9CD63ABF297ULL, 0x116B406204F9D6A3ULL, 
            0x006545CA7B5B015AULL, 0x3078B7068B646553ULL, 0x614F89CFCE4316B3ULL, 0xC5A180606ADA2B48ULL
        },
        {
            0xB51643D09B2C1AA0ULL, 0x93450688075EC7B9ULL, 0x0D54635E6770D94BULL, 0x4AEA469A5640EF19ULL, 
            0x4B92394106CF0EB2ULL, 0x9E01F87837545F12ULL, 0x3C06AFF755A3A736ULL, 0xAEC6BB0466C22DEAULL, 
            0x344EE32A547848B3ULL, 0x48C475F6636FE3BCULL, 0xD2A0276C816BBA21ULL, 0xA972FB75E188B1EDULL, 
            0x04356678E976D4FAULL, 0x096D1D33D98C6190ULL, 0x516450B2257B9FB5ULL, 0xFB93ECED22108BC4ULL, 
            0x4E0BC813B262CA93ULL, 0xEBCC93759A6E56DFULL, 0x1DE6880EB6F1133CULL, 0x261F3EBF1557405EULL, 
            0x7D0C18D4D6D21119ULL, 0x2D8E5C28C002F6DFULL, 0x86AAFFF23DA80707ULL, 0x827583347CB4B8E9ULL, 
            0x70C83D3910E96E97ULL, 0xC8850F197FC81421ULL, 0x4F84BCE533589672ULL, 0x028E904E3D417B03ULL, 
            0xD1877219229AA20EULL, 0x590AE37DCAE49E8FULL, 0x5A4ADC4F028374A2ULL, 0x821195353C04D272ULL
        },
        {
            0xD18B7886663C3F3EULL, 0xF713735F210B9AFFULL, 0x5B203E531DECA0B6ULL, 0xD2A95D84E5131D10ULL, 
            0x91EAD3B6C175AADEULL, 0x6D7747FB7CE26908ULL, 0x82D7EF082BFCA5AAULL, 0xA3380051D7D8FDF5ULL, 
            0xD4A3FD09DB1551A7ULL, 0x3DC201A8BC39E0C8ULL, 0xF76456F4A9EC8257ULL, 0xD0B557BE3135EBA8ULL, 
            0x1872A39D6D144AB2ULL, 0x45E357F0CC26C003ULL, 0xDA4C048B8CE944A5ULL, 0xC0DB0A7CC7B84B85ULL, 
            0x1CBEFBDC11F9E03DULL, 0x818939B20917E47EULL, 0x9A32B88C83422DABULL, 0x41AA231AF75CD3D4ULL, 
            0xA7AEF5AA3DBED281ULL, 0xDC87CB9165BFB3E4ULL, 0x4F720E8B43726A05ULL, 0x352B20BDC8FAF391ULL, 
            0x1EF7701C698EE48CULL, 0xD83D04B5CE200ECAULL, 0xAC2B49AF0E285A70ULL, 0xE29EB0AAD36FB606ULL, 
            0x05C8E2783CF6F95FULL, 0xC84B14CA69D07865ULL, 0xFC8978496B11CF3EULL, 0xCDF0DFC697DD8D9DULL
        }
    },
    {
        {
            0xF13AD24CD13257C5ULL, 0xA769D2DE5D4EE700ULL, 0xCC062E9555C90366ULL, 0x2117C936E6425F15ULL, 
            0x4F07181CE811D3B9ULL, 0x4CCB02F42958435EULL, 0xC8FB55E181518E12ULL, 0x5EE064A4BCFCCEC2ULL, 
            0x6FDEABB038D0E568ULL, 0x665B2DC40E173C99ULL, 0xFDA57D2EFE4DC3B5ULL, 0xC7D50728D04960ABULL, 
            0x2B952468778F142EULL, 0x8E42A90F92C65A4AULL, 0x78C6670722909F61ULL, 0xFAFF1EDAB3E08F6DULL, 
            0x03E50F4DF6B7436FULL, 0x7805AE836D6F483AULL, 0xF375B91BBCD45C73ULL, 0x139AAFCD3B3AAAC5ULL, 
            0xF960FD5C7C62F795ULL, 0x0F3036E5F302972DULL, 0x398CC121E396606AULL, 0x266EDC67A9DF54F8ULL, 
            0x239FDE376090806AULL, 0xBC5811E6F60A9D27ULL, 0xD7FCBF5B0B182AA1ULL, 0xC49B56379B4392F9ULL, 
            0x6E383765C13EF4F2ULL, 0xFE9CDB096AD9FE63ULL, 0xACAAC9913F24FCDDULL, 0xE1C69877AA872775ULL
        },
        {
            0x9B81CB8A487C94D6ULL, 0x00C1FBB05C45E620ULL, 0x9B174CD4207A00C6ULL, 0xEE4E3FA6F2EE2F18ULL, 
            0xD9CE2E3DE721D144ULL, 0x7A7474A79525B9A2ULL, 0x16680220AF225C44ULL, 0x6B798831B813D7B5ULL, 
            0x918F4A5D68600351ULL, 0xF2523F42F57AF609ULL, 0x1D6A6A9828C3394DULL, 0xA49AC85816235997ULL, 
            0xD2A4FEE34E7323C1ULL, 0x7CF2CE3DB108E247ULL, 0xD4614FFE9BE0F7A3ULL, 0x05FBAB8FD18A2CA8ULL, 
            0x9FBB54F9301D7517ULL, 0x69C5124DFE6E5C7EULL, 0x4AD758E9F354131AULL, 0x6AA247B0BDBD6004ULL, 
            0xADD8B023CD44F15AULL, 0xD39635D5DE657B6BULL, 0x538AA52B9F8166BAULL, 0x178E5C5B83C62E76ULL, 
            0x73DB4225D3C7B300ULL, 0x16530875D9CFCD52ULL, 0x303E9AC008466984ULL, 0x7F28F982939E2E66ULL, 
            0xCE0588F9DEF1B380ULL, 0x658E247764D65516ULL, 0xF292B98C2A941087ULL, 0x4D8D993BC2DBA756ULL
        },
        {
            0xAA659DBD6E494E31ULL, 0x2181FB7E79730D5DULL, 0x1C18D989774E8B53ULL, 0x927DF45B8701733BULL, 
            0x2DAAA81C115BCF7DULL, 0xCCC01AF98FA31BB5ULL, 0xDB207FD6DF7D93FBULL, 0x6B35CD92015B19D7ULL, 
            0xBB535AB50B2935DBULL, 0xD1C1D9D244262405ULL, 0x936CD25986ADC62FULL, 0xDA4AEE0C00864987ULL, 
            0x81776A703973DD62ULL, 0xF8337307D657531FULL, 0x2D3D56BBFEAA7659ULL, 0x75A23042E7028041ULL, 
            0x2F557597AAF2C6F0ULL, 0xF9847482AAFD2237ULL, 0x23ACE035C1F193C6ULL, 0x8D18E6DA05A2A989ULL, 
            0x172AFAB6D8AE680AULL, 0xA62D59A20B65DDD1ULL, 0x7D837CCD804DCBB4ULL, 0x9ADDB4600466FFF3ULL, 
            0xA054564746626A1CULL, 0x1BFE02AA326AC215ULL, 0x9C4014A883CAAA84ULL, 0x649914F05A467958ULL, 
            0xC81BF837CF1A227EULL, 0x46FDDF5AE6CE14BFULL, 0x9B27DD1C78C0B4C0ULL, 0x5E52FB10A64F6D87ULL
        },
        {
            0x07740DC5C964E5E7ULL, 0x6CBF45B6B8C539D7ULL, 0xB83FBF9CB2C12445ULL, 0x4D83FEDD2EF743E7ULL, 
            0xD4A537ABCD04B6F3ULL, 0x44516A40EB462462ULL, 0x11DCCA3BB786475EULL, 0xD59FC4D65534AC33ULL, 
            0x7B59D88D5EBEA632ULL, 0xC578B99887313E1EULL, 0x235C191C14B52E83ULL, 0xB705ECF2FBF2CDD9ULL, 
            0x56CA080DF3F47BB1ULL, 0x9F3AD010463F0B15ULL, 0x6B6A90D7CA499C1FULL, 0x23B716C278E9F2F1ULL, 
            0x4361FCB06B948E0FULL, 0x128287FF50C20BE1ULL, 0x07F9E54208C34205ULL, 0x0A58EFDF359D0448ULL, 
            0x00E468DCF62543D7ULL, 0x80D45C0C397B37A3ULL, 0x5FF000696BD17B35ULL, 0xB457D30BC40E17F1ULL, 
            0x1E20A97923AB8FB3ULL, 0x99EBB813ACDC85CDULL, 0x07188B6345B47A26ULL, 0xD33910AD9442E839ULL, 
            0x64076FD6CFD72230ULL, 0xB2721285D374E3D3ULL, 0x3046D55CA4102724ULL, 0x00DF9DCB68C9DD0BULL
        },
        {
            0x5B1BB0810F27F686ULL, 0xCC54FAD51A4E7A1FULL, 0x0A9A6A44D19AE34AULL, 0x0CBF9BFB89F96EACULL, 
            0x4C2F303A7DD2C57BULL, 0x6F33F3D9571BCA47ULL, 0x39527DF8AAAD0946ULL, 0x604DFC3A52B7B91DULL, 
            0x97C3AFA2000A5D81ULL, 0xD08EAAE3EE1AFD93ULL, 0x92F2AFDD707FB3BCULL, 0x0E33D80B552D7B88ULL, 
            0xB76BE8FCFBB250C3ULL, 0x2BB5003971A10598ULL, 0xA3888191F4176C1CULL, 0x6641B8CE202684B2ULL, 
            0x9540512A807C2E70ULL, 0x42FCC5B6ADA2A83CULL, 0x7B17FBF311DE8468ULL, 0x60B359919A7EB044ULL, 
            0xAF5FF1885878F0E6ULL, 0x8D0B52CF1945A2D5ULL, 0x753CAA712BE9993BULL, 0x7519145E64ACC1E8ULL, 
            0x8F8EE0CAD1F9A2AFULL, 0x4FC1293206B4556CULL, 0xD285CA730063DC5AULL, 0xBF8BDB5AB3324F39ULL, 
            0x0599A5D059CC5527ULL, 0x9484550BF24CCF98ULL, 0xB3CACD4787AAA037ULL, 0x84BF6A7D59F84E2DULL
        },
        {
            0x07F511437EB6DA0BULL, 0xE3F503C8C392A8C4ULL, 0x6FA4D55623154938ULL, 0x493B4683565F4251ULL, 
            0xD7F07550A78BC157ULL, 0x0EE47C51073927EEULL, 0x52A6C9D9491B8A57ULL, 0x6636C258121E8E6DULL, 
            0xD686234722B1858AULL, 0x9F2D2B2F18394B60ULL, 0xBE61C5CDA19945B4ULL, 0x5C0E1FE933EE8FB9ULL, 
            0x3C3CA3FAF9B6CBBEULL, 0x3B09306A070ECD1BULL, 0xE5F31289A4F5D274ULL, 0xA4B4FA45C811E4CBULL, 
            0x0995E378F65121C1ULL, 0x77663FEAA960FE85ULL, 0xF8C63E28CC6104D4ULL, 0x8C218D93C08161AFULL, 
            0x180546459CDBBC0DULL, 0x4B3535F68A758C9CULL, 0x9995C8D6824EEBE6ULL, 0xA29D52E0A8BDE4CFULL, 
            0x11ADE2305735F6ABULL, 0x0A9209B0AEEB79DBULL, 0x9AB835DE10DB5ECDULL, 0x2BBCDD7DE6595F97ULL, 
            0xED97C39D158C52A1ULL, 0x4550CA685B238F44ULL, 0x13E75BE39F1B7585ULL, 0x2966F277675202B3ULL
        }
    },
    {
        {
            0x975E40CAE87B0EECULL, 0xBCE2ECDE50F85292ULL, 0xA9856F85FB4ABFE8ULL, 0x6FCB849A07829FA4ULL, 
            0xE68C3656532077D4ULL, 0x927E8AFC65A44441ULL, 0x3C4E5DB40ADE237BULL, 0xC4F5FF050DFF3CFCULL, 
            0xC2FFEA3F77C1EFECULL, 0x8AEC5BC366C147ECULL, 0xA3ADF79960F8492FULL, 0x7B36A1156D75F99BULL, 
            0xB96D142D9986AF5EULL, 0xEA21E664660BA653ULL, 0x7A5AF6197C3DA40AULL, 0xA5B89740B773418AULL, 
            0x6834EC32B9465B42ULL, 0x32499F2B30500864ULL, 0xB834B0ED64368B9BULL, 0x6CDA2DF07DF235D4ULL, 
            0xD34C8D6FE53627E9ULL, 0x1D7535EC5DE12794ULL, 0x6AF60B9CA87B2F15ULL, 0x62B9F6E9E57E3861ULL, 
            0x7D38771FFA10D4F6ULL, 0x7AC8C9BFCD45F027ULL, 0x4AB94EFBD9267680ULL, 0xEC04A088E0C5FF0BULL, 
            0xDBB9FE8A06991BC4ULL, 0xA5575DCCDA44B4CCULL, 0x44490F7F62E14558ULL, 0x31CAE60F3DB1A347ULL
        },
        {
            0xD1D742C4FB275EF5ULL, 0xD10E46C96359BE74ULL, 0x3AEA3FA8FAD4C579ULL, 0x2C253FAA67FCBB1DULL, 
            0xFAEC26EAA009A1FDULL, 0x0D4319D0F261DCC3ULL, 0x9A1838DFEF63E639ULL, 0xB012339B92047DB7ULL, 
            0xDF9FFFDEC3407B41ULL, 0x6B4E5EB70F5A69CCULL, 0xEC24FE7B339CE62EULL, 0x314FA500F0AC4B32ULL, 
            0xB8B1E3581A57F244ULL, 0x4CDE3C60D0F54FE9ULL, 0x4F99B293D4AE6426ULL, 0xF83D4EE5C59BB0D9ULL, 
            0xE6E9DC366C3CC6FEULL, 0x02633F32A2782577ULL, 0x9F77BAA40CF786CAULL, 0x618E100135E012CEULL, 
            0xB808D76A1E18FED4ULL, 0x7E07E3D2BA93B835ULL, 0xF3E42F80218EF471ULL, 0x08AD53EAA3F7E605ULL, 
            0xB723FD4B5C81D7AEULL, 0x611848C5B89FF57BULL, 0x0DAAF61DFD8C6965ULL, 0xDC8D0AB8D05D7510ULL, 
            0xE83B49542CD19A5BULL, 0x9F6627A77EBBDB41ULL, 0x53CBA262D707BE7BULL, 0xD96FC69B74117096ULL
        },
        {
            0xD24ECFB729D4FC86ULL, 0x3224C7E39E584629ULL, 0x646B306CC56B3349ULL, 0xD19689D3E8F851BEULL, 
            0x8F4A21B4B66CC0CCULL, 0x1307581A34B5568AULL, 0x0C986B899A561850ULL, 0x7467CE58DA22C49FULL, 
            0xB01A5249FF527255ULL, 0xFBB50415DD0D7A99ULL, 0x06DF9E5019F37E28ULL, 0x1EE37772C6147104ULL, 
            0x8ED947E9CB761AB9ULL, 0xC286628F42012A8FULL, 0xF29C015991BAA38CULL, 0x25CDF0539F5BAC51ULL, 
            0xA7AC30231233CF33ULL, 0x3206CDFAEA16F523ULL, 0xF9FB682DF75AE047ULL, 0x5701B483D38A50A3ULL, 
            0x33EA5955994B057CULL, 0x7C7F6E8D18DD49CAULL, 0x91E4A71D0315920AULL, 0xF490DAA980A75D00ULL, 
            0xA8AEFA3B626D5C78ULL, 0x019FF239D8287A25ULL, 0x2E1C6E027D41EB08ULL, 0x6BECD135375CFA46ULL, 
            0xB34C8590EE523E3DULL, 0x2A77F0F580F3B146ULL, 0x1ECE177C68D79C62ULL, 0x7B9060C8E83D3BB7ULL
        },
        {
            0x09B04E16EDDECC58ULL, 0x08BFBE205CE47A21ULL, 0x5E337624368A52C7ULL, 0xD96F473855A3F5FFULL, 
            0x1819BD5EB7614871ULL, 0x4C566F115677F7FCULL, 0xA9B50B2D888F0018ULL, 0x1F6FEDFCD5126C8FULL, 
            0x2CE9184FB595376EULL, 0xC077B18B10A4D4ADULL, 0xDACA62BD32C34711ULL, 0xF4BF5BEC20644AA7ULL, 
            0xC6E136C2966F4D5FULL, 0x8517A2F581E1C0F2ULL, 0x8333A9319385C280ULL, 0x1FEC093B561259BEULL, 
            0x376AA1ADD4F034C8ULL, 0xC5F97C0B4723C996ULL, 0x131B541E96451CB2ULL, 0xC66A7B0110B471ABULL, 
            0xB58BD3D60D0CFE34ULL, 0x74C863D936965DE7ULL, 0x900F628A9A43E54BULL, 0xBB9A5299813654FEULL, 
            0x8789C35B54C85AA1ULL, 0x276CC24A00AC4394ULL, 0x9391CB8FC022C9AFULL, 0xF57DA356BA1BC642ULL, 
            0x7995691BAEFFF814ULL, 0x7AADA5F1922FB741ULL, 0xC0F6220DB8BA77A8ULL, 0xF6B7C0EF22684864ULL
        },
        {
            0x7C7E584ADD3B643CULL, 0x38A88883C2210C9BULL, 0x872873B3EF9B4CB3ULL, 0x3ECD386C226E6EBCULL, 
            0x09BC605240C9A05BULL, 0x19FF45BBA8C96FF8ULL, 0x0035458F724963F3ULL, 0x12B685FA58808E18ULL, 
            0x118B4B83FC6A3969ULL, 0x7B693CEFD061EED3ULL, 0x4E78FB94897BBA38ULL, 0xDDF38DE064AAE4B0ULL, 
            0x2125DF021CBB9B79ULL, 0x7B560A738FC053A9ULL, 0x65A67991DC5B49D3ULL, 0x068FBA112280447DULL, 
            0x9A05E8D04E7CA0EBULL, 0x3F49959FE245BE0BULL, 0x97B88EB6829FA8ECULL, 0xD4C98ED8C715DA81ULL, 
            0xB8A6AF0B18B88180ULL, 0x708F397A2769A336ULL, 0x622A2BF3232ED7C0ULL, 0xAA7CDDFCF7F76185ULL, 
            0x2248AE47310441ECULL, 0x157673C26BDB6DA2ULL, 0x73AF47E1FECA09A4ULL, 0x17CE4915A97487CFULL, 
            0x1075171CFA84CCC4ULL, 0x4284CF1313DEA040ULL, 0x8DBDE0ABE45025DDULL, 0x59328281530957D5ULL
        },
        {
            0x7AD342E82D4F9533ULL, 0xC88DB4841BB4F3BBULL, 0x1B0F8A5E438D662CULL, 0x2B2F0D8F7CCB3D46ULL, 
            0x00556EB113B44E1DULL, 0x0CB4D73908DF7587ULL, 0xC6286F0C2F0D3EB9ULL, 0xF4929B75C83C6671ULL, 
            0x8464146EC790700EULL, 0x6B6125B7117D09B5ULL, 0x39E4F43B42D07BF4ULL, 0x0A6504A5A2E30AA7ULL, 
            0x9A6C143E64B9B245ULL, 0xB03EDFB6269E1F7BULL, 0x43F3D5847ECA8F16ULL, 0x64ADC3989B017C25ULL, 
            0x6CE1D31677594ACFULL, 0x100433C18ACBFF15ULL, 0xD93C409BA72DA903ULL, 0x494DAB2EA34CEF06ULL, 
            0xEEFB3520950FD8E2ULL, 0xC7F9CF982F41D242ULL, 0xD0228EF6BD9F2756ULL, 0xD3E72A5C3D4D63B2ULL, 
            0x919A17FCA76C08C4ULL, 0x39369C3571AE3155ULL, 0x32AEE7E10B6B9378ULL, 0x9957545648E84689ULL, 
            0xBF5A1B14DBF0E7D4ULL, 0x676645D48620E3B5ULL, 0x120586ABBD6781FFULL, 0x32C606DD91C5842BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseGConstants = {
    0x39D5FF84A8872517ULL,
    0x946A5681A8D72AB9ULL,
    0x61AE901EDE16D10FULL,
    0x39D5FF84A8872517ULL,
    0x946A5681A8D72AB9ULL,
    0x61AE901EDE16D10FULL,
    0x5BCCFF1F07997E2AULL,
    0x5C6F56206E596189ULL,
    0x01,
    0x2E,
    0x67,
    0x28,
    0xF8,
    0x67,
    0x09,
    0x39
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseHSalts = {
    {
        {
            0x312914EF62E5A0C0ULL, 0x18067F642E4EC990ULL, 0x042A63F148F1FD29ULL, 0x0C731593E1393A3EULL, 
            0xC51A73C46D9ACD75ULL, 0x8AC1FE5F6A7432D3ULL, 0x8240268E828DF6CDULL, 0x4A58FFDC866F9018ULL, 
            0xE716E7150B9F15C3ULL, 0xD0CAD77231CCFD0EULL, 0x8B003C48BC46C29AULL, 0x55855B2CA35D393AULL, 
            0xA28925A33F7D15E0ULL, 0x0C31B3F22B4881C0ULL, 0xAD94EC66DC098E81ULL, 0x754740257CA7987FULL, 
            0x2D4144B2F5D1FD83ULL, 0x4E31765A4A0F1FB7ULL, 0x53EC35049761627CULL, 0x1933553384213918ULL, 
            0xE7CEBD7B7923E0A2ULL, 0xC9F83BCC9FD78BD9ULL, 0xAFB6FF2414221A17ULL, 0x1CC5B765E81EFAE8ULL, 
            0xA1908D2F7BCA4C51ULL, 0x0D7A139E83F15962ULL, 0x758945A5A22EDCD8ULL, 0xDA7D652D63B89342ULL, 
            0xFD9F3B4EE5930EBDULL, 0xFFD303548D7A89F6ULL, 0x25AFB77BC216ACD3ULL, 0xE7FAF58084F79A63ULL
        },
        {
            0xB1CADB9EA7D0034EULL, 0x557B69984D433AC3ULL, 0xD105C22679EA7679ULL, 0xD9AB671A1ECBC121ULL, 
            0x18103425E2CBCDDCULL, 0x07188402A1FF9F44ULL, 0x78C8A53CF1AFE233ULL, 0x453ED7BC0852FA8DULL, 
            0x0D7955434907249EULL, 0x43187286D1D135BBULL, 0xA889D291CFE15811ULL, 0x6C5C3BA3C55ADD18ULL, 
            0x4DBF9C3C145938DDULL, 0x52572FC8196480ABULL, 0x854D0649518AFEE8ULL, 0x3DF35BE52D5CF99EULL, 
            0x5C2DF89BD63165CFULL, 0x49FC8B61F8BF8991ULL, 0xC0546569F6CDCABFULL, 0xDA11939A7AD8DB74ULL, 
            0x131490750B368E90ULL, 0x6CE4B9C148BA8623ULL, 0x9BCF01BF74CD3C7BULL, 0x36472EEC06347964ULL, 
            0x3F344280375350A0ULL, 0x6699B3FD6339C3ACULL, 0x5C607B280FA521B4ULL, 0x2E71CF85C701C61DULL, 
            0xD5115207419614AFULL, 0x07B2CF26CC25D9B5ULL, 0xFABBAF060A261CCCULL, 0xF245CEF160B3FCD4ULL
        },
        {
            0xADAA84A09639EC2DULL, 0x522C471299D532A7ULL, 0xFACFFC8E3D2FD046ULL, 0xED0EA3C85846051FULL, 
            0xDD758B9897673B8FULL, 0xF8E95D34D040F476ULL, 0x51700F8D2E30D381ULL, 0x69B1DEDEBB087F3FULL, 
            0xF1E0931E477C103EULL, 0x30818CE6E1FA282FULL, 0x927E307CFD03342AULL, 0xBAF50C622FB44DAFULL, 
            0xB10AEF6C005C2802ULL, 0xD8E7A0BD81CAA8A4ULL, 0xE4E9B9701B148EDEULL, 0xC259B757B0856078ULL, 
            0x3D09D7B14B7E5D1FULL, 0x7180F4D7EDC9C249ULL, 0xF8B58AB31C734A67ULL, 0xA531AF74B2AD817EULL, 
            0x593A6E9C5CD6434AULL, 0x2467E7D63AA7D298ULL, 0x1D701BB4168CD35EULL, 0xE30A605D0A46584AULL, 
            0xB8F47267FE3AF069ULL, 0xA3734ACE7968E134ULL, 0x1DECDF860510AF02ULL, 0x8469CE77B242E7CAULL, 
            0x6ABB565E8DDDDAABULL, 0xE768AE24774D8D0CULL, 0x41013B8BACDB0A14ULL, 0x251FB0403FBC8572ULL
        },
        {
            0x94785D266D777042ULL, 0xA34D125C9D32CB99ULL, 0xF2F4D53AB46B032FULL, 0x0F877BFF42EAE251ULL, 
            0x4E411B29A0D6B70DULL, 0xC25B8B8E4D5DB522ULL, 0x3C0195A776213121ULL, 0x4B58BFD952BAA384ULL, 
            0x2D4E3A58D5A6379EULL, 0xCD31E9AE3A982634ULL, 0xC136254D23F20E7EULL, 0x5787171F23AD2FF8ULL, 
            0xE22D903D28D7F6D4ULL, 0xCE9643C1342B2B93ULL, 0x1FCAA33A4142DB16ULL, 0xE6882CC1A77EFBCDULL, 
            0x8E86B0AA1B77858FULL, 0xD781276875F2B3ABULL, 0x2277289A007AD5A5ULL, 0xE52DDA79D8C701E7ULL, 
            0x48BEC81A3D6317B4ULL, 0xAB19EDC0CF9B0896ULL, 0x7167F732A8A0C61EULL, 0x435CE9C0B415F529ULL, 
            0x45C234413E0A655FULL, 0x555490122993769FULL, 0x950C6E48E6556968ULL, 0x839ADFAC7F4F4CBFULL, 
            0xD35BE85F1FEEBC25ULL, 0x16906F22C5F2B55FULL, 0x4567CB4ED8E09F39ULL, 0xEA93805D608EC350ULL
        },
        {
            0x2EE2122C131F5CC3ULL, 0xE5595DD493F74FD5ULL, 0x4C4C377E29C15995ULL, 0x0C6A5977D0ABA08EULL, 
            0xE9AE5DDBCDD7CAD6ULL, 0xD97C4E5CA6491B81ULL, 0xC351C0F9A144FBD3ULL, 0xCA2F6B9FE98B2938ULL, 
            0x84CE62470794DD0EULL, 0x995A12B8E1B6F29EULL, 0xD262EE6788796C11ULL, 0xCF5D1CC7177139CBULL, 
            0x12F00276CF7FF920ULL, 0xD2F4429CCE758940ULL, 0xECBA220723E64B84ULL, 0x86A66CBD05888BE3ULL, 
            0x352D1FD079721EFCULL, 0x06189479EF8E101DULL, 0x57FF0C08BBB22C74ULL, 0xC5BA1411D2CC5DB1ULL, 
            0x0012105741F0659FULL, 0xDE10669FDD2B043FULL, 0x69056C658CD0995CULL, 0xDFDBE08F4CB8184BULL, 
            0x53BEC70406F3F82BULL, 0xB4761360E941701DULL, 0x49E10D7B63B8F115ULL, 0xADA0290F1BE62C30ULL, 
            0x0667CDD837A577CAULL, 0x76D636E34D40FA58ULL, 0x40D3495648F12BABULL, 0x8B2F395EA9696374ULL
        },
        {
            0xE0E5F45ED01A4802ULL, 0xCBCAF8120DAFFC23ULL, 0x3E156D5343A55FE0ULL, 0x4968512973F46BA4ULL, 
            0x93F560FEBE7EE0E1ULL, 0x788D62657AA3DFEFULL, 0x76397C6DA9F7FAEEULL, 0x612689C92101963AULL, 
            0xCC2B03D3402F0D77ULL, 0x414CC2DD69ACE045ULL, 0x434A6ECC0385C1E5ULL, 0xD3B9120DA34E3D7EULL, 
            0xEF43F6097B546A2DULL, 0xC14148BFF546464AULL, 0xFA9CB24374D6FA4DULL, 0x191119BC4BCBF10AULL, 
            0xD34FB71C7CCFE2AEULL, 0x8354BCA14995EFBEULL, 0xDCCC61298544819DULL, 0xFD641FA1B0EDD5E0ULL, 
            0x23DABD6F638D3B7BULL, 0x992D0D6BA3CA5D7DULL, 0x073975BF6A53F7ADULL, 0xD69A3C0218DE3AFBULL, 
            0x63DA8ECF93C46DE1ULL, 0xD5EA8858CD8669BBULL, 0xF526E39D501D7608ULL, 0xD21B1388E94B207FULL, 
            0xC471B09618140B23ULL, 0x114FC56B12A4F5E6ULL, 0x6A777288558871B6ULL, 0x3C7C7BB54BC9B314ULL
        }
    },
    {
        {
            0x1E280189C4B2296EULL, 0xEC99BC47E4A5858FULL, 0x11BA543699241D44ULL, 0x9B59509BB9ECB093ULL, 
            0x9EB21B972BF802FDULL, 0xC1E45CB954C40423ULL, 0x4A894339D41AAD33ULL, 0xACAB36426B58044DULL, 
            0x1C1ECE48EEDE3E7FULL, 0xA8FA2A9DD4B2C76AULL, 0x5503BDC694E65D52ULL, 0x2E9CB70504695426ULL, 
            0xE3B6E5E78E35EF41ULL, 0xDD4A8EAB28763E73ULL, 0x8C17C455F3B42364ULL, 0x804C21CCCFF152D0ULL, 
            0x00F09B77498A9CE3ULL, 0x24DF0D955654ADA8ULL, 0x44D336EBE6EE0393ULL, 0xDCDEA6B03FB0F891ULL, 
            0x98BDB084A26192D1ULL, 0xDC790E138A59540BULL, 0x8E337EA04D110A40ULL, 0xB9C0E1322900E0BFULL, 
            0xAC163533281D531CULL, 0xB283200026FBB55EULL, 0xDC46DF7B13BAAFDDULL, 0x4B8A5BE80313F047ULL, 
            0xAC3B61D0C1CEB555ULL, 0x6FC7DD2766A21567ULL, 0xB9D23AA8E8F7E1D1ULL, 0xB5E23E7C4E772F5BULL
        },
        {
            0xD7BCE480A38B655DULL, 0x3B08F29DAAE6C653ULL, 0x067BC4A6B1244F3CULL, 0x8DFA13B2447D8455ULL, 
            0x47F7FEBEFDB0CA60ULL, 0xE0653F47ABAE1D9FULL, 0x4B29B76BF0E6B629ULL, 0xEFB4B216E95AE690ULL, 
            0x7204486A948C987FULL, 0x2A4C9B6E45AA8309ULL, 0x7AC38879A2E817D9ULL, 0x853B09EB8D24FCBDULL, 
            0x7A8ED2B523C049D3ULL, 0x630E870764E935CBULL, 0x74948F25BC45B7D7ULL, 0x2A254C092A473BA9ULL, 
            0x27541FC519D6799BULL, 0xA46014B38662D069ULL, 0x3778238F67EA7233ULL, 0x01432404E673E94BULL, 
            0xAF330751D575F9C1ULL, 0x38C300DB1DF49E2AULL, 0x3AB2936AA28BB268ULL, 0xCBC1FEDB2EE4E028ULL, 
            0x459C1A82228F9CBDULL, 0x83C95D68780FCF55ULL, 0x825252E207F627CDULL, 0xFEF5FBB289783A44ULL, 
            0x80A2D5AF625CFFC1ULL, 0x1B0999553A2B1D31ULL, 0x9EB73AFFDCF57DAAULL, 0x443E36570737372DULL
        },
        {
            0xB80AE08B89071A78ULL, 0x3F431BA3E3DFD828ULL, 0x81470390D8876A60ULL, 0x14DCC4135978966CULL, 
            0x6F5549001984DBB3ULL, 0x9D13CD35FE01D7C6ULL, 0x84E6C609662E42CBULL, 0x3EF7B5583398FED1ULL, 
            0xD5AAD91853C4A429ULL, 0xFD7CC439538A5470ULL, 0xF2DBF8E50D35BDBFULL, 0x36A02DFFBBD7D909ULL, 
            0xCA58FB71BE12452BULL, 0xDAD73E6E3D3EE6F4ULL, 0x6154CD868C542A12ULL, 0x9FEE1DA0909BEEC9ULL, 
            0xA8B573ADF184CF6AULL, 0x8F0475E98F7271FAULL, 0xA9184393941E3D51ULL, 0x378F016258A00720ULL, 
            0x257BB928B538AC61ULL, 0x48A5D18B3A5EE7D3ULL, 0x12DF7E2B9A47EFDDULL, 0x90D49FE19FEB1FDDULL, 
            0x0694672B1C5040A8ULL, 0x93B6B5F9E1CF57D4ULL, 0x5BF9CC3FC03A4E7AULL, 0xBB4DC4B9F8EE135CULL, 
            0xC56BD32CC494F613ULL, 0xBED1840F2F9E7E74ULL, 0x45B6D53301E50D12ULL, 0xDC5D935E12DB53EEULL
        },
        {
            0xF638570E2F2CE8A8ULL, 0x5A6C8FB4B1B22275ULL, 0x3F7E71A410CD36EAULL, 0x80526B7CC9410598ULL, 
            0x7A946F1195B996D2ULL, 0xDAD666F7A84D27A9ULL, 0x8659FA3F25231CB2ULL, 0x76B0A3747C246C5BULL, 
            0xE248941654424568ULL, 0xA64EFBC479AE7C08ULL, 0xA72F2566778965F8ULL, 0xF809D10A23090B1EULL, 
            0x23ADF360D505E3EBULL, 0x537A44B1EFCD8403ULL, 0x0295048EDAEF257FULL, 0x9F13CB8238C402A4ULL, 
            0xE443A53C37D6C396ULL, 0x507CB162A0A0C127ULL, 0x1291453425CE9E13ULL, 0x097930AE0ADC2576ULL, 
            0x4602E2B22E3AB1F7ULL, 0x602643813400187FULL, 0x54E815F2D7B89812ULL, 0xD64A6875C2208E55ULL, 
            0x06DD1371C45ADD68ULL, 0x2BAB51401DBC3CB2ULL, 0x50621470CA9D584BULL, 0x46CF05E1BC552D1CULL, 
            0x93E371FFAAA58666ULL, 0xD34947BA5C8C69A7ULL, 0xFCCFD19D61B42A76ULL, 0x2A120106F9D517A0ULL
        },
        {
            0x9805D8E74B27AAB1ULL, 0x07A594C0744171F7ULL, 0x0BAEC21F4976DC11ULL, 0x7A9CD20E80E32898ULL, 
            0xABF259A83B869BF7ULL, 0xE33A3AE9793A9E29ULL, 0xD6E6820BE965906DULL, 0x3308A25846880A14ULL, 
            0x7890405B3B2E58AEULL, 0x3B8BF939CE4DE6D8ULL, 0x7068825304075D22ULL, 0xECD3F259EABD9D04ULL, 
            0xCB739A870DF03EB4ULL, 0xBC407F2B155FDFE0ULL, 0x99F6DE0225DD7BB5ULL, 0x4D36A89BF59838B3ULL, 
            0x7F7482A73D5AABBFULL, 0x99AC285400A0D48CULL, 0xA6EBBB1AD5A8F3A5ULL, 0x509F940B63E6227EULL, 
            0x9BDD184AA64D85C9ULL, 0xBF4F637623C6A02AULL, 0x22602B4809B9AE91ULL, 0xC2A5E92155E17399ULL, 
            0xD03EACE39775B2F9ULL, 0xEB5DABF31E0F2F54ULL, 0xAE54C20504E87F97ULL, 0x775BF1236996FD5DULL, 
            0x3F1370427E18159EULL, 0x560FA7F24DFE516CULL, 0xED56177CA4495E08ULL, 0x03D2FC21CA49F7C6ULL
        },
        {
            0xC0B61855006B6B90ULL, 0xEB098E3EFC47AA67ULL, 0x547174FC04B5145CULL, 0x759082F2CA80E4A4ULL, 
            0x7968CEFF30107EB1ULL, 0x79260DAD2A42E822ULL, 0x6E72A2F371DE8BBFULL, 0xE18A3D285ABC3FB7ULL, 
            0xFC9E47B6B13B2392ULL, 0x2FD05E5DF0562C51ULL, 0x7DD10CBF20220DC0ULL, 0x82A1EF7A92813852ULL, 
            0xCD1F667883EE5970ULL, 0x0A667500E05E10C4ULL, 0xA1FAB3F961717099ULL, 0xF84C026D64427D9EULL, 
            0x05FA40B427829C77ULL, 0xACE60859C7F69FC7ULL, 0x7C5AEB0A46B118DDULL, 0xDA5A5161B14B11B7ULL, 
            0x964C192EE331230AULL, 0x2BD827AA96802D77ULL, 0xD14D05AE0AD8CB9EULL, 0x433FE0F1642AA35EULL, 
            0xC07CDC9074E65340ULL, 0x52811B4D99542279ULL, 0x27759FAF732844B7ULL, 0x3223DCCBE666DEEAULL, 
            0xDC2F8B5540EB06F3ULL, 0xEEF336053AEF8CBFULL, 0x078B46F276181C42ULL, 0x2F1838B358640DEFULL
        }
    },
    {
        {
            0x06FA0E1D7D336AFDULL, 0x5BCF4965F59FA898ULL, 0xCC60D9AF13EE312FULL, 0xDD0BD5986DAD89E4ULL, 
            0x7E8114F3E7C7C589ULL, 0x403B4A6B264639EBULL, 0x59D86F0304186154ULL, 0xFFB8101B69E112D2ULL, 
            0x4C184EF2D33E3B30ULL, 0x8D4685E2025AD400ULL, 0x8ECFA0831BFC314DULL, 0x66A2963A347FE6DCULL, 
            0x4A4F37FB731DC01AULL, 0x6D50D862CB4B90A7ULL, 0xEAB5ABA430E73C3EULL, 0x52FFE081303EFB68ULL, 
            0x7E18D34C00F315FEULL, 0x92732E87E2084E65ULL, 0x04AF2BA011617195ULL, 0xE5846A59C0407B74ULL, 
            0x5DFE1239D79C36FAULL, 0x254801751BDBB184ULL, 0x009D54A9CB4E6349ULL, 0x111DA2B76FE577F1ULL, 
            0x066BCA3226C91007ULL, 0x5316A3FD940161CFULL, 0xF79EC781E8E1C300ULL, 0x81409B6F72DDC5AFULL, 
            0x32E1CE54D823BF8FULL, 0xC106DEC9165D11D8ULL, 0x53A7069FDF9191ECULL, 0x72E1D83985355208ULL
        },
        {
            0x0C66E9F9802015E5ULL, 0x91F9640744C31C90ULL, 0x5E8E6D514B35876EULL, 0xED919B24E1E1DCC0ULL, 
            0xDA81EC9324D96417ULL, 0x855D09F2E8BE8CCCULL, 0xEE3A5005C9EB563CULL, 0x4D184765738011A2ULL, 
            0x1379D9D54F2D4A91ULL, 0x2E0C04A6415E0F46ULL, 0x4693796DB77E6C5AULL, 0xD3D7DCC601C99C7FULL, 
            0x9DAE999BC46A25D1ULL, 0xB6BEC58DE4EEB9CFULL, 0x029B0A7BA9F99886ULL, 0xF82C046ED4F73762ULL, 
            0x91D5AAA6599C1BC7ULL, 0x8DBE7641B9B453C0ULL, 0x077FCDB4A4D4C2A3ULL, 0x8D3592A500587112ULL, 
            0xD77B7753A933DBC3ULL, 0x991D255F1B3702EBULL, 0xE5B1974C47CE918FULL, 0xA79E0C0B92BC7AC6ULL, 
            0xEAE97E74EBBEC81BULL, 0xED9A0A5DC31A7029ULL, 0xEC426A5473CA7015ULL, 0x87EFF4BF6DF5C422ULL, 
            0xB20B21EDD34E13E7ULL, 0xE4E46798CFFD0D9BULL, 0xD9B42DCF068D28F1ULL, 0xB548102E4A3AC92EULL
        },
        {
            0x8E82E81166F29751ULL, 0x68F0CB0E4E2A9506ULL, 0x7C887E3310D41950ULL, 0x8D05756ECE75B74BULL, 
            0x1A84C3623F656D22ULL, 0x6077D146931E97B6ULL, 0x47CE2E5DA70C9AE3ULL, 0x653343CE6E493426ULL, 
            0x4D98EE02B94F0CC0ULL, 0xCD3EC58ECECF3B0AULL, 0xD9E54F367AE56815ULL, 0x789F535E25A7591EULL, 
            0x06216A0137FE6F38ULL, 0x4EBEA8724F6F75D2ULL, 0xF1695D0771E1482CULL, 0x899A28C9B937E3C7ULL, 
            0xCEE1D7D22054193AULL, 0x12083FD3D9DF1418ULL, 0x93D41E6CF652E976ULL, 0x6CE9DCC0FFA70225ULL, 
            0x769B7419FACC37AEULL, 0xD34658168BA547A3ULL, 0xECEC8E186B5A92C4ULL, 0xEAB57E709B99A276ULL, 
            0xBBA09B4D03E2BA37ULL, 0xC88067F05CA8ECE2ULL, 0xD42FA280F912C17AULL, 0x3C7C90D4A26ABAA6ULL, 
            0x152E1901F85D4C39ULL, 0x8ACCEA6E7F19CD02ULL, 0x4527D2B078C20386ULL, 0x11C1210FB7955908ULL
        },
        {
            0x553EED4B37CD7223ULL, 0x8FC52CCD7B0F9B07ULL, 0x2A685CACDD56E7B8ULL, 0x8F08FB908A718639ULL, 
            0x7C24BCCD1DB7B8FDULL, 0x7E02E31CC0267E46ULL, 0x3EE7C9E064E26DBBULL, 0x25E44007E20904C4ULL, 
            0xBE276485A4498678ULL, 0xF88BA98B986BCBE0ULL, 0x41C529271B4643FFULL, 0xD67AE53F10233D87ULL, 
            0xA46A7BF7EDD98201ULL, 0xD4213546BF0FFFB2ULL, 0x9163D53AC21BD294ULL, 0xBEF2AEC4AED9AA9FULL, 
            0x8BAAC70E305FD3AFULL, 0x85DEAC9A5D7E889BULL, 0xAC5A56579FD1AE71ULL, 0x90354397E8BB9C38ULL, 
            0xCF3AA99AF4C25073ULL, 0xD259248FDD8B851FULL, 0x1AB00E53A7CDB25CULL, 0xC32B35284F97D82FULL, 
            0xA716CDF320509B27ULL, 0x079DD36B12A1F57DULL, 0x3435CFE91746DE98ULL, 0x71DC384526E86C86ULL, 
            0xA52F1E89C01AA825ULL, 0x7FCBB92C8999A997ULL, 0x8F6F5CB477B075B9ULL, 0x432753F2C10BFECFULL
        },
        {
            0xEC5A90CF25E869BCULL, 0x4629DF9CD774AEEEULL, 0x8D326440DDFB9E5EULL, 0x319151E444966D8DULL, 
            0x333B5269084AF53CULL, 0x0B4ABED4AD951DCCULL, 0xDF5C5F3611E55ADDULL, 0x3F557AF2256FB58BULL, 
            0x357F22BC73BE526BULL, 0x65EE69777C624879ULL, 0xCFCFF40B1904692DULL, 0x9F37CF097EF984A7ULL, 
            0x6A393271673DA793ULL, 0x459D5728806B7DABULL, 0x8F2F7B123C617948ULL, 0xB32AD62BE5040D9FULL, 
            0x41F2CE32E66C36BDULL, 0x4E5541A955A242BFULL, 0x76A80E888DB360CAULL, 0xECB1D4CD2601E939ULL, 
            0x13246F00A2AAADF3ULL, 0x30A1A7833B4E9658ULL, 0xD207E8A44B6E2C71ULL, 0xB2BCB60C29532AF7ULL, 
            0xD6CA6E906F149AA9ULL, 0xE0FD78D48FA0AAD0ULL, 0x91440B20720E8120ULL, 0x5E9E52C3D04BB5E7ULL, 
            0xF8F35D3EE616D065ULL, 0x3B0149251F509D20ULL, 0x0D98D8B5999B88E3ULL, 0x8B17F212D7DB70C8ULL
        },
        {
            0x34164C0C53CC6E24ULL, 0x9F98AB7E5BB57ACCULL, 0x7C6900DEC98A0E5CULL, 0xBA71E87C96382CCFULL, 
            0x4E83C642592E5EA1ULL, 0x2EA0BEC0B2F41EA8ULL, 0x68E152A388BD3F5CULL, 0xCAAF4D7D245D9A9BULL, 
            0x918045A072C3AE9EULL, 0x53660246C87BE138ULL, 0x3ECC80084A050460ULL, 0x82FC632C5EF8391FULL, 
            0x8F9450BE111423F5ULL, 0xAF350C7862FB4CE4ULL, 0x52AAE76EDEFC1068ULL, 0x6ADD25AB00C874A2ULL, 
            0x88E9A0BAAA7D70CDULL, 0xC87222B5D41CBA49ULL, 0xA87997AFCB5FD24DULL, 0x1A3796447D694D9EULL, 
            0x362742A7AA0D4715ULL, 0x7AA8BAFB53284385ULL, 0xCDEF2A0EF0128128ULL, 0x05C8BE257D60D141ULL, 
            0x99022A58B1178ACCULL, 0x57B8729D9D2B276AULL, 0x8C415825C4969054ULL, 0xE1B1AED8BE4EB6CEULL, 
            0x07DE01016B2DDEBEULL, 0xC7D0B567E61DA71FULL, 0x0A59AFF8DEA76051ULL, 0x3D4D23A52076A618ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseHConstants = {
    0x640739950454C169ULL,
    0xA736F816D2EB74FEULL,
    0x5C1C965F6706D706ULL,
    0x640739950454C169ULL,
    0xA736F816D2EB74FEULL,
    0x5C1C965F6706D706ULL,
    0x7DD6CF93C4817564ULL,
    0xC6DFA09156B01226ULL,
    0xC1,
    0xF9,
    0xC6,
    0x33,
    0xB2,
    0x68,
    0xA4,
    0xB9
};

