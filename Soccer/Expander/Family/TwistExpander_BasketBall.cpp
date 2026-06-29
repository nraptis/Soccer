#include "TwistExpander_BasketBall.hpp"
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

TwistExpander_BasketBall::TwistExpander_BasketBall()
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

void TwistExpander_BasketBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xCEF88C3ECC453E48ULL; std::uint64_t aIngress = 0x8E82B0A6CCCB3E21ULL; std::uint64_t aCarry = 0xB29BD1B4E70597DBULL;

    std::uint64_t aWandererA = 0x872413963373F6F9ULL; std::uint64_t aWandererB = 0x931B36AD9F772232ULL; std::uint64_t aWandererC = 0xF0170F270EDCDB9AULL; std::uint64_t aWandererD = 0xAA730E757ACFE983ULL;
    std::uint64_t aWandererE = 0xF7925A8C49500404ULL; std::uint64_t aWandererF = 0xC7EEB50F3C7DB011ULL; std::uint64_t aWandererG = 0xA595BF85524C7907ULL; std::uint64_t aWandererH = 0xED4FB82620F2C405ULL;
    std::uint64_t aWandererI = 0xF2EC529342C1155FULL; std::uint64_t aWandererJ = 0xD459113FAC673E1FULL; std::uint64_t aWandererK = 0xFAAA793A90EDB9A9ULL;

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
        aPrevious = 16172342680880192813U;
        aCarry = 15155723001533606458U;
        aWandererA = 14254960177119198028U;
        aWandererB = 10103019281110134884U;
        aWandererC = 15701654851275608540U;
        aWandererD = 15062486258418440427U;
        aWandererE = 12150195351036217175U;
        aWandererF = 17801811833917605913U;
        aWandererG = 11697114662215937863U;
        aWandererH = 14203433751430714664U;
        aWandererI = 15090968202353128843U;
        aWandererJ = 9249188142023590192U;
        aWandererK = 13323626423725341592U;
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
    TwistExpander_BasketBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_BasketBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8E54A178DDBBEB69ULL; std::uint64_t aIngress = 0xA8D3DA3696508DE2ULL; std::uint64_t aCarry = 0xC0DDD5973B926C70ULL;

    std::uint64_t aWandererA = 0x8E8D384A5DA14EA4ULL; std::uint64_t aWandererB = 0x9829DE0033F4B214ULL; std::uint64_t aWandererC = 0x9F270BFFF87DEF4FULL; std::uint64_t aWandererD = 0xBA0D49F5A7351E72ULL;
    std::uint64_t aWandererE = 0xCB72C561E6B26AF5ULL; std::uint64_t aWandererF = 0xC434CC0FF5E539BBULL; std::uint64_t aWandererG = 0xA32352E23A762368ULL; std::uint64_t aWandererH = 0xD0BBEDF084AC4926ULL;
    std::uint64_t aWandererI = 0xB6D83A94D4708F73ULL; std::uint64_t aWandererJ = 0xBE4191C8CEAC1875ULL; std::uint64_t aWandererK = 0x83115CC1A9DB0E9DULL;

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
        aPrevious = 16056861805437013325U;
        aCarry = 15949905951855938949U;
        aWandererA = 15103953633950998096U;
        aWandererB = 15005253794945088959U;
        aWandererC = 17281766071629317579U;
        aWandererD = 12476332336044127475U;
        aWandererE = 16523751949610955904U;
        aWandererF = 11426081615427688518U;
        aWandererG = 15818482240557753711U;
        aWandererH = 17665133235460788599U;
        aWandererI = 16998588354857006557U;
        aWandererJ = 11374334186603285988U;
        aWandererK = 14813192088374642098U;
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
    TwistExpander_BasketBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_BasketBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x89EC6A6E74EAA08FULL;
    std::uint64_t aIngress = 0xB632DF11CF573E01ULL;
    std::uint64_t aCarry = 0xC71B698E8B109387ULL;

    std::uint64_t aWandererA = 0xCDDCE802296B27B7ULL;
    std::uint64_t aWandererB = 0xCC7E4D32CB001DB0ULL;
    std::uint64_t aWandererC = 0xFE261B366DAF842BULL;
    std::uint64_t aWandererD = 0xDD1C062ED8806F50ULL;
    std::uint64_t aWandererE = 0xA1CED304B7CE832FULL;
    std::uint64_t aWandererF = 0xA7CE0334F4E9F99AULL;
    std::uint64_t aWandererG = 0xB365522253725F2FULL;
    std::uint64_t aWandererH = 0xE5E19E80E2EACBD1ULL;
    std::uint64_t aWandererI = 0xE80B229C73E43526ULL;
    std::uint64_t aWandererJ = 0xD6788704F80947DCULL;
    std::uint64_t aWandererK = 0xDD9235F2D7EFAB00ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BasketBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_BasketBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF12F5642A990A231ULL; std::uint64_t aIngress = 0xD648DA9D51E43406ULL; std::uint64_t aCarry = 0xDE68F52AF17814FDULL;

    std::uint64_t aWandererA = 0x989EBFE61619DF7AULL; std::uint64_t aWandererB = 0xE523AAF2C72A7F31ULL; std::uint64_t aWandererC = 0xD87AC6EFC506534AULL; std::uint64_t aWandererD = 0xC1D8B46FE16094E4ULL;
    std::uint64_t aWandererE = 0xD495AE30228EFF46ULL; std::uint64_t aWandererF = 0xE9A8A1936539E603ULL; std::uint64_t aWandererG = 0x85B8E64A5E8495ABULL; std::uint64_t aWandererH = 0xA95C06C785D91F71ULL;
    std::uint64_t aWandererI = 0xEBC791B9C9F54253ULL; std::uint64_t aWandererJ = 0xAA63A3EF0CCC51EBULL; std::uint64_t aWandererK = 0xCF10666B58174B5DULL;

    // [seed]
    {
        aPrevious = 16478756170567344042U;
        aCarry = 11750881731665975971U;
        aWandererA = 18240994142234026992U;
        aWandererB = 14854208664463448918U;
        aWandererC = 12132144951352187539U;
        aWandererD = 9294129221900605025U;
        aWandererE = 12074207543426713977U;
        aWandererF = 12081817374786392863U;
        aWandererG = 14887541232429624414U;
        aWandererH = 12146321375935767640U;
        aWandererI = 13328580016124220343U;
        aWandererJ = 11042526637229475919U;
        aWandererK = 14823671249742453425U;
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
    TwistExpander_BasketBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_BasketBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_BasketBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_BasketBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 1, 2, 0, 2 with offsets 772U, 788U, 8124U, 2787U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 772U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 788U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2787U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 2, 0 with offsets 6693U, 3733U, 1735U, 3273U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6693U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3733U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3273U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 1 with offsets 6603U, 6435U, 4213U, 3298U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6603U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6435U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4213U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3298U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 1, 3 with offsets 7888U, 2957U, 1230U, 3309U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7888U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2957U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1230U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3309U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 1, 3 with offsets 1197U, 1720U, 2003U, 558U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1197U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1720U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2003U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 558U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 1, 2 with offsets 1454U, 1306U, 619U, 1247U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1454U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1306U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 619U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1247U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 0, 3 with offsets 874U, 1122U, 1310U, 1652U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 874U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1122U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1310U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1652U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 1194U, 1650U, 1624U, 468U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1194U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1650U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 468U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1399U, 1952U, 1677U, 517U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1399U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1952U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1677U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 517U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BasketBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 2 with offsets 2891U, 1203U, 3473U, 4813U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2891U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1203U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3473U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4813U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 0 with offsets 2690U, 8106U, 5962U, 7984U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2690U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8106U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5962U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7984U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 1 with offsets 2371U, 2739U, 6818U, 7158U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2371U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2739U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6818U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7158U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 3 with offsets 4097U, 1053U, 123U, 3667U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4097U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1053U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 123U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3667U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4843U, 2456U, 2540U, 1942U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4843U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2456U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2540U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1942U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 393U, 538U, 183U, 1874U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 393U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 538U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1874U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1121U, 715U, 727U, 1264U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1121U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 715U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 727U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 2010U, 2033U, 1385U, 1312U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2010U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2033U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1385U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1312U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1917U, 847U, 1170U, 1818U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1917U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 847U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1170U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1818U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 [0..<W_KEY]
        // offsets: 1940U, 703U, 1873U, 1247U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1940U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 703U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1873U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1247U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseASalts = {
    {
        {
            0x34A5EF292492A0B4ULL, 0xE6C3E08AD41B0AC3ULL, 0x25DA98ECD7AC0441ULL, 0x61113D0A80394049ULL, 
            0x7FE666B737E8B735ULL, 0xD6ABE8364BFEAB9EULL, 0xF741A0E4416D6727ULL, 0xD743C8C326B217EEULL, 
            0xC469BED15FC5AEA1ULL, 0x22C7D80400C9E12CULL, 0x17A88E94E4629563ULL, 0x0A37A43C0DDCE3B4ULL, 
            0x1FE151CE0E12CF60ULL, 0x108D1D1D6547EAF3ULL, 0xEDD9283DC2B4A7D6ULL, 0xB5A0B9333DE06CF6ULL, 
            0x05D2E4B4F3E73A31ULL, 0x9EC49FB3279440D3ULL, 0x5DE8872AD3B68056ULL, 0x3AF6ADA4FE01B475ULL, 
            0xAEFA397E1815CAB1ULL, 0xA4719AA87DA640ECULL, 0xCA1507657E46E0FCULL, 0x76673028E39B094BULL, 
            0x79AB1448A33D0476ULL, 0xF4454E0DA0422CBEULL, 0x350D5C0DCBC4807BULL, 0xEEC8C274617AEDFEULL, 
            0x8A6317417F2819D2ULL, 0x6BB71B595B558015ULL, 0xCD9362B16B879981ULL, 0x301A507C0CCFF6C1ULL
        },
        {
            0xD890971792F6FD96ULL, 0xB0FF9A2B5D06A2CEULL, 0xF1C4A21C627FDF7AULL, 0x2869B97EF6E423CFULL, 
            0xC4119068D908BBFBULL, 0xD46581C56FE7BBB5ULL, 0xAA62073E0C38D33BULL, 0xDAC8DE2981D3119CULL, 
            0x2C4EE34B057C2127ULL, 0x94ECFD8390047F82ULL, 0x3EFA74F70B5394FCULL, 0x29377D842C5DF5AFULL, 
            0xEF27FC52C8CDE01DULL, 0x74C6B7F0FDA0A6E0ULL, 0xD80EA47457D87EC8ULL, 0xE3380D2486DA1A48ULL, 
            0x6EFB77066263C89EULL, 0x8E38048EF02B0E0DULL, 0xCBA3DC3E64A05794ULL, 0xDBC1D21D2D333AC2ULL, 
            0xE59EAC8A4BDF0FFCULL, 0x71E0D37807346FAEULL, 0xE05F2ED15FE0D73AULL, 0x76B4F5BB6C530B09ULL, 
            0x18C0625F5E1A1A33ULL, 0x8FC2EC09AFE27244ULL, 0x143B049D507AA6ACULL, 0xC0F5D306D49FE6B9ULL, 
            0x60C09DC31C56E989ULL, 0x60F48E57BB80F2DDULL, 0x7FC57778177EDF31ULL, 0x5ECAE2C4465B25CDULL
        },
        {
            0x10E980D864923D51ULL, 0x1E3ABCD8A61B274AULL, 0x6C12C68EB81C7EAEULL, 0x430A541EA6308815ULL, 
            0x52116F03F7B0A5F7ULL, 0x69FDEC93C60041A6ULL, 0x2FE2755B1DC037C9ULL, 0xFA54CAF95AC5B65EULL, 
            0x1E0F5BABF285E3A2ULL, 0x006FC9A8F43EB4D9ULL, 0xC5CC9D30493E8603ULL, 0x4A3F3BD8E93B97B2ULL, 
            0x1CBB357274519ACDULL, 0x23187097747C085DULL, 0x3A67FD2B69A9B411ULL, 0xF6B947917C27F616ULL, 
            0xC7502FBCF2DA73E0ULL, 0x13BC95B5CCC3ACB7ULL, 0xEA6E2B7A4FCA0213ULL, 0xFEAD3EF018570E26ULL, 
            0x5F0A097F2D7BD4B7ULL, 0x0F9FA8E6789B3C97ULL, 0xD7C17A2FDDB90C31ULL, 0x862654012FC2DA05ULL, 
            0xA61452A2A2A25088ULL, 0x47C676CB0A5E9FB2ULL, 0xF84495FAEE506547ULL, 0xEA4A9C44B0E5E7D7ULL, 
            0x949ECEE21F1405D6ULL, 0xCC8EB9E59D705F6CULL, 0x2335D2F286FBEB1AULL, 0x6F8C96D8E8775111ULL
        },
        {
            0x1BF59655DA8E6489ULL, 0xF43850BE054FE8E3ULL, 0xC3D330DEEF6DCE24ULL, 0x66A56FFB26BDDCA9ULL, 
            0xA7E6A256981663D6ULL, 0xF41F6154032D1F1EULL, 0xABD881D9538F2B9EULL, 0x4F4F08950960F263ULL, 
            0xA2A85948488809ACULL, 0x0CEB42EDE257D62EULL, 0x8408D779976959F9ULL, 0xCCCF6B37CC908F9EULL, 
            0x2BAEBF22BB458332ULL, 0x3827E12B0D754C20ULL, 0x4AA6AE3C58724F23ULL, 0xE325E1DAF31CF4B5ULL, 
            0x6C816DAB1DF501E9ULL, 0xF0230DA8D0D60A47ULL, 0x7ED8896BF7A18824ULL, 0xDB0CBE81C6704DAEULL, 
            0x69BF4F2D2361C8AEULL, 0x1FBE544A09A2F8A0ULL, 0x94D636689F662092ULL, 0x68411C706CE1683CULL, 
            0x3B536E1D50DC3592ULL, 0xF46F624AF0A60861ULL, 0xAA65639071F7244FULL, 0x73B18BBB88765FE7ULL, 
            0xDAEA696DE3F6C044ULL, 0x732B7CE4582C2748ULL, 0x64180E772ADDD892ULL, 0x80193D0D89B14D9AULL
        },
        {
            0x25D6FD850EBDBA28ULL, 0xD846C420317E0F2DULL, 0x4A76D491C276150BULL, 0xC09C130084A44852ULL, 
            0x6E874F802BA6D60DULL, 0xDFB05C70E2FE34A5ULL, 0x3342D5EA99A3AAD2ULL, 0x62E5EC9BC3C3CD7BULL, 
            0x7A26A78263521EABULL, 0x9BE1953F872B5BB1ULL, 0x0C1675782BD4F529ULL, 0xA39449419B617CA3ULL, 
            0xA268A8E98E3F5A04ULL, 0x865C0B4BEBEF4ACDULL, 0x4B5C084B09E30765ULL, 0x7B874F5EC8AE1D06ULL, 
            0xA1D36D5795F7F4BAULL, 0xE6F397F63019BDAEULL, 0x9DFBC4D14839762DULL, 0x6F95ECE4FC463451ULL, 
            0xE251061BD8F0E305ULL, 0x1933C6683E87FB76ULL, 0xC661FF69D918466CULL, 0x388E2F12FFE33BD8ULL, 
            0xDCF945094BE59F8EULL, 0x599AE14328700A8FULL, 0x7AF7E0EEC2E1BACCULL, 0x6CCCCA97203732B5ULL, 
            0xEF48633BDD481BB1ULL, 0x7D18521EAA1797D2ULL, 0xACBE88BAC42DD463ULL, 0xCD136E29DC2AB3D3ULL
        },
        {
            0x465460987A0FD114ULL, 0xAAB696A797CD7AA2ULL, 0xE3E0F5F0D1857FA6ULL, 0xD0CE807C16356F8EULL, 
            0x83E1BE1174E5E57EULL, 0xC91C85E95EFEF73AULL, 0xA9E466AB26877CE4ULL, 0xAF3703D6C12EF0C5ULL, 
            0x71E2BD3336E9C2B0ULL, 0xC1FA1B0D1F912D76ULL, 0x9789A4837364C60CULL, 0x6E4329E94C3156B2ULL, 
            0x82E651CAC5C3BEFAULL, 0x12F3170213D1F70EULL, 0xC21D0E4FED412F91ULL, 0x71D66C02651CD5F1ULL, 
            0x7F54F09E826180FEULL, 0xA9C0D23272324F4AULL, 0x62AE6C0CC9CDDD75ULL, 0xF430622C870418BDULL, 
            0x17F6325EC62AED9BULL, 0xCCA9E588E2702AD5ULL, 0x8B071B4A04E638A1ULL, 0xEC7031581DB91AFBULL, 
            0xAC7F424B332B5414ULL, 0x9D91769BF1FC7F9DULL, 0xB7C45F5256372312ULL, 0xCB81110ED19C8074ULL, 
            0xBF87C5DBB5EADA01ULL, 0xD1E19AE61227E405ULL, 0x8AB7F749D4ACBD3BULL, 0xBA268A4AF607C0E2ULL
        }
    },
    {
        {
            0x881452CE9E3FBE16ULL, 0x86BE84146C689145ULL, 0xFB317774376ED176ULL, 0x788E1F3EAD75279EULL, 
            0x0D778822098C2BBBULL, 0xCF36EB56D4D7B258ULL, 0x510AF7A9E1AAF66CULL, 0x03A7574A5CFB95F9ULL, 
            0x202D82E9D5F7B51BULL, 0xC192FF2C49243483ULL, 0x4799DB7A7F550522ULL, 0xDF964BB28895F3A5ULL, 
            0x571AD7E88267EFA2ULL, 0xA44F62AB0E0161D7ULL, 0x8DBBD6FF0A925E8DULL, 0x779FD7C5EE5FA8F3ULL, 
            0xF39A82A9E7549440ULL, 0x2F75EE3FF54469D3ULL, 0x2CCBE669A0C4093CULL, 0x04F280525627682BULL, 
            0x54D70FEFE7900351ULL, 0xBB8010C5C77B8A53ULL, 0xF4257DDD0DD8881CULL, 0x374E8CD8BF81BB75ULL, 
            0xBE3E7E8F6EBDAFDAULL, 0x2D89FB858B7F8B69ULL, 0x4D35ED95C321FAA3ULL, 0xA1FA7FC6DF597D37ULL, 
            0xF5FDA6EC6B5CF830ULL, 0x319CC29EAA786943ULL, 0xA096B946B2CD86E0ULL, 0xFB21A143A6821F81ULL
        },
        {
            0xF912C04CE4905DA0ULL, 0xD7E1FD23045C7F35ULL, 0x4E3531EF03C2A747ULL, 0x28C0A64186BFC969ULL, 
            0x3DDED607DA2052D5ULL, 0xC0C35BABEFFF5FE7ULL, 0x03C777932BFACDCDULL, 0x7CB19B65081A4F61ULL, 
            0xC85C7890C6039189ULL, 0x839C0E9AA60E26B4ULL, 0x590062306DDE39A5ULL, 0x4E98A384A41BFE1EULL, 
            0xF8210BD667C13DE6ULL, 0x1215725F1627D02FULL, 0x84EDE5728E1DDECFULL, 0xE0D7B43846B45C0CULL, 
            0x63B9225F76A2BF36ULL, 0x5155994154C77864ULL, 0x63ECF8110130AD42ULL, 0xE486A03FF54373E7ULL, 
            0xAD348A182F3072C5ULL, 0x0C613C7B5D1BDFEEULL, 0xD0CC7A79D72F1ACEULL, 0x5AA11EEB035FAAFFULL, 
            0xC20839AFA3BAA454ULL, 0xA77D1EF318B9D9FBULL, 0x094C864BCDE127A8ULL, 0x85C6D00107237A3BULL, 
            0x3C037750B64E7433ULL, 0xA4A9FFD9D4B1E866ULL, 0xAB8298B435D5348EULL, 0xA0617F31EB26A710ULL
        },
        {
            0x283592377DCF3D6FULL, 0x965A3C14625C0446ULL, 0x8108ED55DEA0ECE7ULL, 0x08731DDF372A7F37ULL, 
            0xB0A1EAAA99B80F2AULL, 0x4D6D730E7EC823E6ULL, 0xC4D1979F741DE445ULL, 0xA1B177B8C5906557ULL, 
            0x30AB85B6C3955819ULL, 0x4DFB53A220A4B9A9ULL, 0xDDAE2A220A273D99ULL, 0xAF6571EB776C514FULL, 
            0xAB8CFBE2D59A5DEFULL, 0x4761FF36DF0EBCA0ULL, 0x05F057E046427896ULL, 0x3D1964287F778961ULL, 
            0x952A39DDDC445AB5ULL, 0x0115D3E2CDB2C1E5ULL, 0xC85049A2AAB393C2ULL, 0x5F95A3E85A5BFF0AULL, 
            0x45C625384A7C7A45ULL, 0xBFD8C1ABBE4BF790ULL, 0xBABC81DF86F6BC90ULL, 0xDDE6312E5AE0E180ULL, 
            0x538F1DDFEF7463AFULL, 0x1674F4D05C794BA2ULL, 0x2D2C8E9293C3D1E9ULL, 0x5D43686EDCE722B3ULL, 
            0x9AFE30B255469CC8ULL, 0xB8736F743A04EEA0ULL, 0x4E8A0E86D9E7BF17ULL, 0x74E72BEF5BD2F2F0ULL
        },
        {
            0x6E94C63C8D184732ULL, 0xB06B15C8CEAA92E0ULL, 0x39022B59BC1E8524ULL, 0xC533B3B93E2AE998ULL, 
            0x51417D1AB8CD1D91ULL, 0x26E6C3143AA084FEULL, 0xF6A3526B2B7B59DDULL, 0x75DAE2BFDD5AF486ULL, 
            0x4DC4D1C5FD98AB0AULL, 0x13FF996BA425F7E5ULL, 0x482CE3473F23D279ULL, 0xA3DE32E73650D775ULL, 
            0x78E6B83349441DECULL, 0x61731F390470D283ULL, 0x3635E72D36EBD847ULL, 0xFACCB4F2F2B95458ULL, 
            0xD2974A7D70D827C6ULL, 0xB79F586890F6432DULL, 0x269D5CE61F0C31C9ULL, 0x5D652397F925FF5AULL, 
            0xC782E1014F8F5D44ULL, 0x2085C20E9BA14A9FULL, 0xBF00101B38273A37ULL, 0xBDF0CC00E1F9FBFAULL, 
            0x9110A1AF4D0CB7D6ULL, 0xD54806FEE0A1D218ULL, 0x8101049F856A3F0AULL, 0xB90A86771272D239ULL, 
            0xCE8007904996DB3BULL, 0x8D42026EA589C9C5ULL, 0xB8C2A095380E8DB1ULL, 0x5C89073EFC46E14DULL
        },
        {
            0x4112884686237C10ULL, 0xC1E2D89802D8BF20ULL, 0x0768D32898D7D864ULL, 0xECCA6A1B6D9DAE1BULL, 
            0xE54718643D8F4474ULL, 0x29E554C238642C9FULL, 0x2E038789F751F5C4ULL, 0xFC1DAA39A48100B1ULL, 
            0x631360AB75C84994ULL, 0x787ABDAE13DA0646ULL, 0xEB30D149285C5CBCULL, 0x068A478564D4EBA4ULL, 
            0x5308C35A65142B7CULL, 0x7B0517E7DD094A3AULL, 0xD81AA47F0344A418ULL, 0x6E90B4DB28EF2775ULL, 
            0xA26619022B1A882CULL, 0xEDE5987B539C064DULL, 0x6BFB6E75C993AFECULL, 0xA8F8B2FF4E2F3017ULL, 
            0x2484EF63B63BDDFAULL, 0xD534E2DEE4608DBAULL, 0x4FB9CB47E4C71A19ULL, 0xC6DB1652B36C34DEULL, 
            0x095F5D6B78D19A45ULL, 0xCDE0E58B58714750ULL, 0x6CD62E374D563C9DULL, 0x414CF53CE1FAA142ULL, 
            0x5C256D462AFD90E8ULL, 0x013C0C65DCEFADF5ULL, 0x29ED6B774B0BD7E5ULL, 0xA9EF7507A7319D39ULL
        },
        {
            0x6FFC51C8C52172FCULL, 0x1582257132E3C1B8ULL, 0x359BDCB3998E5CCCULL, 0xB0775C732B9622F5ULL, 
            0xB9BE6B5F2FE1EDEAULL, 0xA9C20568E45199D0ULL, 0xA0CDC988936B1E54ULL, 0xD0BB595214E045A4ULL, 
            0x3BA995F46B2A012AULL, 0x91C26D2D1F6BA007ULL, 0x8A3AF51C6C8AA909ULL, 0x1549BFB4B47949CEULL, 
            0xFA1BF78045EF5F2EULL, 0x0CF5F92D0896C68EULL, 0x7E62AE93C40D9471ULL, 0x8141AC8CE091E3CCULL, 
            0x9686947AF2304AB9ULL, 0x021F76F830406C3FULL, 0xE4DD964165371909ULL, 0x5F25463AE7277251ULL, 
            0x6930DC0390E89D93ULL, 0xED65B7BA858CE72CULL, 0x2B0C981D05E8DDDEULL, 0xF5FC0D46714E3CCEULL, 
            0x0448F867F71B1E7CULL, 0x5056EAA28B643B9DULL, 0x5A3E128EFE9B69B9ULL, 0x6E1D70B5FE13F93CULL, 
            0x7C3F67E76E94706EULL, 0x096A485ABA46215FULL, 0xA2B2E08E80082A1DULL, 0x5E48D6B78311BC79ULL
        }
    },
    {
        {
            0x03C1626C9A12542BULL, 0x6AF83A03BAC5F6E6ULL, 0xF78814EF9153F92DULL, 0x9B77FE6101A1C119ULL, 
            0xF23625084225FC91ULL, 0xE7A2177901468F61ULL, 0xB800D554EEEE8B58ULL, 0x359F9054428A9EEEULL, 
            0xB5EEB5ED8E306FC7ULL, 0xDAF6BCA3DB5E0579ULL, 0x69A2C07552486785ULL, 0xC4F1C1B9C72736AEULL, 
            0x76B9B2ACE39A5A59ULL, 0x1D569490CC03D1CFULL, 0x112C210FF4F3D421ULL, 0x72F801BE962C9FEAULL, 
            0x1659A2E9B1B36B44ULL, 0x50DF7559D54E8973ULL, 0x957BECF665A9A3FCULL, 0xD65B4FF7B0866665ULL, 
            0x3843A90FCF0CA1FFULL, 0x026A8E0DAA45FDF1ULL, 0xC17055B78AA20604ULL, 0x72F94ECC64BF231CULL, 
            0x738BD56BDCD5DF94ULL, 0x3B464F775A495D93ULL, 0x3F0AC017CD06E8DAULL, 0xF3E6AD61A066F04DULL, 
            0x50359FDE8D96CCF0ULL, 0x927C9CE4A1D1FAC6ULL, 0x1A0BEA18DB017955ULL, 0x61212ECCBA5659D8ULL
        },
        {
            0x4864B4E8FDDFA770ULL, 0x3A03B5C7B993C3C7ULL, 0x1C3E7C58C05ED50CULL, 0xBE9869F854DDC125ULL, 
            0x077C1FEBA9E9904FULL, 0xEA14230C34F5EAFBULL, 0x738BD2EE5C765222ULL, 0xA71BE892B3D68454ULL, 
            0x831FB6AD23B01E92ULL, 0xAE7289F65E12C208ULL, 0x2D6ED75E2D1A2E55ULL, 0x08AAA64EE1B6DBECULL, 
            0x7F8086FB449C5970ULL, 0x42F8F0C0BE646713ULL, 0xAD53C51EC910641BULL, 0xFE2DDBCADDCF21FEULL, 
            0xC694356D16BC6A7BULL, 0x5CC31A8CFC7717D1ULL, 0x996882E666D6C370ULL, 0x7B5F3633F7DA06BDULL, 
            0xDB751BE5D07A925EULL, 0xDD2CA1C4403F7455ULL, 0xBCDFE0DB38B407E4ULL, 0x97135F38DD3C9C90ULL, 
            0xBBCA8426EBF99526ULL, 0x7520E3CF2CD524CCULL, 0x75583AC2D3F6A1ABULL, 0x0A114CF7A3840FA6ULL, 
            0x651C17EA0144916FULL, 0xF11584E291881104ULL, 0x75BB6727C82865CEULL, 0x5FE4FE9B5003E1DEULL
        },
        {
            0x2DD509716EC2DBECULL, 0x62CB463BE4C44D57ULL, 0x2970E052DAAD1498ULL, 0x35D6730830AF690CULL, 
            0x1A8D0F1AAE234EEDULL, 0xB6556B54814C4B65ULL, 0x8F708C932A985902ULL, 0xE829D7DB98DCD812ULL, 
            0x03AD5BDA7E97DD53ULL, 0x1FFA2175C1B895A0ULL, 0x05B04D98C3F05E9EULL, 0x1FBD866F6C816316ULL, 
            0x5387851BE52E2F36ULL, 0xB54DFC4451E00C22ULL, 0x9A7C247B0048732BULL, 0xCA398CDF8451D46FULL, 
            0x85EAA2C2A877F447ULL, 0xB7EAA70C50A49FD7ULL, 0xE09A00AC60C596BBULL, 0x28D94CD57D762EC8ULL, 
            0x11CA3D77625CB02DULL, 0xD6FBAE1603434FC7ULL, 0x2BA675EDCB11659DULL, 0x0EC0423A0F28A6D3ULL, 
            0x1B2AA1FF715F85BBULL, 0x1C95589D1C91716CULL, 0xE0B71E56D842C811ULL, 0xC4560C7FF4F9CD7AULL, 
            0x25E295E0ED625B69ULL, 0x51A4FC4177A473C5ULL, 0x37F1D6A96F95C515ULL, 0x31CF5F10C87B9097ULL
        },
        {
            0x4E7C632E9DCF8FE1ULL, 0xDAE971755632473BULL, 0x0E8DF33DD82DE7C2ULL, 0xC37E07DE20DF8738ULL, 
            0xE096D68ACCF5ACC0ULL, 0x5CA3446C63D79B3EULL, 0x82B152E52CF0FD70ULL, 0xA6F8650A5AD197D8ULL, 
            0x88EF1C53DC90DB6BULL, 0x5787CAF829BF701CULL, 0x1146AC99E789E338ULL, 0x4478A20E895E429DULL, 
            0xCC0C9A0D2CB00056ULL, 0x00F801433323BC41ULL, 0x1093EA1DE1AC4718ULL, 0x8FBBF712685F7115ULL, 
            0x6C7FA579C92A9116ULL, 0x1ADF69986C80B52FULL, 0xC12F5D6057AE902DULL, 0xA5387ADC53DD2AFDULL, 
            0x24747EAAB5F6CDA4ULL, 0xA225E747CC75856AULL, 0x94324F28EBBEE2BEULL, 0x96FB5EA4D65E1994ULL, 
            0xE540BDC3A6C21234ULL, 0x303FDCC3942061E9ULL, 0xB4238F11A0553085ULL, 0x3A18D14742C90C72ULL, 
            0x0C5B90AE7381E254ULL, 0x0B55C7D82FBD8292ULL, 0x5334B7BB7DAD1C61ULL, 0x24321AF701115B91ULL
        },
        {
            0xB5229FDC8453158CULL, 0x2871F85D38A983BEULL, 0x54E7448EE41532B3ULL, 0x6FBB2853C6411B9EULL, 
            0xE18ABFB183F3C751ULL, 0x8879749631FDEA11ULL, 0x8F3F3DD0B727414EULL, 0x3AAC250DAA9ACA8FULL, 
            0xA6430A5694710B5AULL, 0x2BE92295629BF6B7ULL, 0x87F316DE7490385CULL, 0xD8E34ECEFC5C5D17ULL, 
            0xA85A9E8CE6491A57ULL, 0xF431C3AA0EFEF505ULL, 0x51C1ED493F6E4821ULL, 0x3CDBC918300236F6ULL, 
            0xAD7046B19262F2B3ULL, 0x1FADBD2B1A4AA8A3ULL, 0x7269784074142F91ULL, 0xDB1BEEB88360370AULL, 
            0xEF2A1BF8BEBA4C2AULL, 0x0996CD0F9A55CE41ULL, 0x15F2D2CBFF0206A7ULL, 0x9E625A93F8ABCDE8ULL, 
            0x5B758C9A1C0A47D3ULL, 0xA87F181B889CAB21ULL, 0x567931F9876FC252ULL, 0xA69EB3C16D641385ULL, 
            0x063A2B7C306AB2A6ULL, 0x2CA77B6BC0DA154AULL, 0x68EFF237BC225549ULL, 0x2EF1384BC89B0A8EULL
        },
        {
            0x41663512267E1F7BULL, 0x1736192A7785463BULL, 0x17878E53273F1BFEULL, 0x984B031DE480306FULL, 
            0x1189BCADEE44B547ULL, 0xE58EDC2487D2EC28ULL, 0x92BCF8D6C426391AULL, 0xD21A51DAB7448690ULL, 
            0x3E286A2CEB5F74D4ULL, 0x9B30A05BBDB4B4C8ULL, 0x3BBE8AF3409115C8ULL, 0x4A8FF5347E22B026ULL, 
            0x492EE81345EAC46DULL, 0xBF7B5AB398313AAAULL, 0xC33831893D23DD85ULL, 0xA76652E47D7087A8ULL, 
            0x3F1CBB4B9E2E34F8ULL, 0x260C4E412B76B8BEULL, 0xDC5DBA632376D880ULL, 0x102D7C34BC27E4E2ULL, 
            0x2C6CB3394E9C9141ULL, 0xC5FB8FF7D0C02BE0ULL, 0x0CF3E79FB965A822ULL, 0x7BF44A746950ED3CULL, 
            0xA3707C3960BE56CDULL, 0xC9BABEFE5FF7D0A7ULL, 0x70761CCB19CE3237ULL, 0x883F47DA34F1A123ULL, 
            0xB86ABDEC6C32EFB3ULL, 0xD748C50854E47B90ULL, 0x1AA9DB15C09FC633ULL, 0x7BBD0708C99B259DULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseAConstants = {
    0x33667B408FAB5C71ULL,
    0x9603D20427B0AAE1ULL,
    0x8E4D50E1B50078B0ULL,
    0x33667B408FAB5C71ULL,
    0x9603D20427B0AAE1ULL,
    0x8E4D50E1B50078B0ULL,
    0xB8786F7EAC706B2EULL,
    0xBF40761A0474EDD4ULL,
    0x51,
    0xC7,
    0xD1,
    0xA7,
    0x30,
    0x41,
    0xD6,
    0xF5
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseBSalts = {
    {
        {
            0xC137DE3F120B4423ULL, 0x9CFB1EFAC8B9E5EAULL, 0x52F4DA94693D3DD8ULL, 0x4756293D6E801681ULL, 
            0x8895645C5E7920EAULL, 0xB2716115C252C8F8ULL, 0xE34FE69FFC6C4D26ULL, 0x370F066E77E46B66ULL, 
            0x52A97D38E79A2B99ULL, 0xE06330C3EA7D6FDCULL, 0xB2E5733DAF3A3C2BULL, 0x7B3EC379F977F370ULL, 
            0x0F4B91706274FCD0ULL, 0x928CB831E5BD5CDFULL, 0x79798C7168A1EF1EULL, 0x897A6E3E872D4483ULL, 
            0x1D605D1A0486A487ULL, 0x75A7330CEF735226ULL, 0x87C45BB018E0C2D6ULL, 0x81B59225449AD8F8ULL, 
            0x2754880667181298ULL, 0x9B1A58E946656A17ULL, 0x60BA5E3D23C6E7C6ULL, 0x4BB5CDC8F16AC12DULL, 
            0xE59BAB0B6CEEE29EULL, 0xA4ADC08D1CFD05C7ULL, 0x252751A22F2E4DBDULL, 0xA130676AC4E82E06ULL, 
            0x0FA8649FAB84BD84ULL, 0xCD0C1464F4F46AA7ULL, 0xAC3DC15B83C16600ULL, 0x402FB03318215C88ULL
        },
        {
            0x2DE7589CCC750E55ULL, 0x4F68AD8D5745437BULL, 0x71F146FA338A2EAFULL, 0x548FBC14F905C20EULL, 
            0xBCAF0F26E204F77AULL, 0xD166D8CB405F764FULL, 0x40C268D918C091D3ULL, 0xA94D57840EEC41B1ULL, 
            0x413274AEB9AD2DEAULL, 0x96BC66361015063DULL, 0x1E49EF96F4E5C482ULL, 0xF41A6F70325CE28AULL, 
            0x6745D24AF1DBE9B7ULL, 0xA287479B819DF48CULL, 0xC72218C3AB72DAD2ULL, 0x9EDB4DE519BA10A1ULL, 
            0xD59E895499D905E5ULL, 0xA8BDABD755E48B20ULL, 0x0B5993FBC6693349ULL, 0x600D382800423EEDULL, 
            0x444F5A9C110361A6ULL, 0xC37E8D6FE7E6DD92ULL, 0x930D38423C1AD0FEULL, 0xC868CA26B4191DB4ULL, 
            0x0AA8336D059AAD6BULL, 0x7CE0CCC2C93634E1ULL, 0x9DE68FFE387C6DFCULL, 0x7BA460B53678158DULL, 
            0x53306CBC0DA96269ULL, 0x5101C9594C840789ULL, 0x68D08DD7CD36EE30ULL, 0x044CBF4647E3EC12ULL
        },
        {
            0x8F18CBE1B6F6C235ULL, 0x28862D27401C4EF1ULL, 0x75DBD72C380F597AULL, 0xCE2B103B1188C3E9ULL, 
            0xAD5764E757C86267ULL, 0xF7B1DB7DE6F897E6ULL, 0xFAAC86E79B0CE3EEULL, 0x98FE142E471E76F2ULL, 
            0x0D0C6483F3E3D772ULL, 0xEFA96B4871D87DD9ULL, 0xB68C4C5785D1278CULL, 0xEBBD63E3B706F260ULL, 
            0xDDEA6BBF15A147AAULL, 0xD9F3E744552DDB94ULL, 0x635EDFB23F1402D7ULL, 0xE358263536FA8718ULL, 
            0x48260021F3B5AD61ULL, 0xEC6A93F6668A82A7ULL, 0x5992ED5ACC02D522ULL, 0x63F842F902F67223ULL, 
            0xFAC16178CB3ED2EAULL, 0xD3B4340A490B69C4ULL, 0x60E399A1979C546BULL, 0x36CDC4A785FA786FULL, 
            0x0FF97DD246B3F09BULL, 0xDE25B30EC7C7F006ULL, 0x3AE7A99F5DDFFD9AULL, 0xB07F903F448BB7F5ULL, 
            0x55EBE88021DE6B3FULL, 0x85BB3F141C8A74EBULL, 0xFBEECE7F6EF48BB2ULL, 0x700801325BEE4168ULL
        },
        {
            0xFD105759827C75F2ULL, 0xEBA135A2C6F222E5ULL, 0xC708EC38BF80D15DULL, 0x17AB5E2BB5C3878AULL, 
            0x6B9110FB9C49A9D4ULL, 0x6E8C83A2EEC4C78CULL, 0xDCC9598432F70520ULL, 0x2E779E9DE6C5A6FEULL, 
            0x472D728F91601DCCULL, 0xC77F1D7D91EF5EA1ULL, 0xDE77A4AF337CEDCAULL, 0x6F810AB6815FCAAAULL, 
            0xA83337315CD23D8DULL, 0x26F6421057062AB6ULL, 0x08D77305EEB236C5ULL, 0x03605D5B23144D7EULL, 
            0x92F44B16774BC62DULL, 0x39E866E053B88650ULL, 0xDBB05D080EF21028ULL, 0x6B168C6BCF9CA1D6ULL, 
            0x2795FA5E51DF93BFULL, 0x97A137E72C3B6842ULL, 0x7CA7D3067B9DC0F4ULL, 0x0A889252F2042CBBULL, 
            0x90349465BF922073ULL, 0x92D180D9885F18DCULL, 0x2F903592F23A8E1FULL, 0x532E759462CC6EA5ULL, 
            0xB1EC2AE0D52C7D7DULL, 0x253C6B7F743ABA9EULL, 0x2E8C0A0473823538ULL, 0x9CC8D5EFDCA39676ULL
        },
        {
            0x4AE7365835E0209DULL, 0xA78DA577E610A889ULL, 0x8827FAF069ACB793ULL, 0xAAE7062BF2A2DDD8ULL, 
            0xEA0173C3B6F49A45ULL, 0xA99FFE7281219453ULL, 0x8AAE136D4F49A8FBULL, 0xA75EAE99007E978BULL, 
            0xAC5ED110B23382FBULL, 0x94B13231676CB1D8ULL, 0x92F632ABA2FF0D79ULL, 0x060B6DF1989C1422ULL, 
            0x113CA8A09BD26C8EULL, 0xFA493CC274913152ULL, 0x0BDB93CBE120F879ULL, 0xC20947775810AAB8ULL, 
            0x4DEA69BDA2074282ULL, 0xC83419FE0F128D1BULL, 0x81570E48D30C73CFULL, 0x4D0E8C5D12332353ULL, 
            0x4012AB6257CB1AC5ULL, 0x9191A4E35DF3FCBCULL, 0xED03E15965C2D163ULL, 0xE3BE2BB6C93E5A51ULL, 
            0x35E77F7F220EBB3CULL, 0x173A55E53628B96FULL, 0xF450AE0883D0AD5DULL, 0x949A5BE9BB48F902ULL, 
            0xFE90E16B0FA59FE6ULL, 0x3E063CC52F518A47ULL, 0x1846FDD2F98708D3ULL, 0x673072C3AEA00063ULL
        },
        {
            0x4DC745A5900CE53BULL, 0x4E94268A6567CD59ULL, 0x1CD87EFE038DFC49ULL, 0xC75F431DECF4F5F0ULL, 
            0x1B8DF61196A3DEE6ULL, 0xA046F4375F66BCE7ULL, 0x623F39B4B7933C2BULL, 0xE339BF8AA3A6BF94ULL, 
            0x0787A6C83A86591AULL, 0xC5E9A8379F29EEAEULL, 0x9B881010E5A1F380ULL, 0x6F73388E2E944D8FULL, 
            0x0C5AD554D516D865ULL, 0x6E21DEDBB47FD41EULL, 0xB21740416E2F819DULL, 0x4C77EF19F5407C7FULL, 
            0x9F08037A4B9928C1ULL, 0x1918CC0580AAA1E0ULL, 0x068EFC77C14ECEB6ULL, 0x33BC08B7E12680C4ULL, 
            0xEC8E2869007A27B6ULL, 0xA064BC4C579BA530ULL, 0x164072D5CCB0DF33ULL, 0xCF35E207166EB0BEULL, 
            0x82E63E1D6DEF6368ULL, 0xD3297DD06BFA765BULL, 0xD70365FA79348F23ULL, 0x482A1C59C0C7FE45ULL, 
            0x088FBCC8E4D543BBULL, 0xF458C187B2E2B850ULL, 0x63B8E83BDFAAD6A4ULL, 0xFCB986A424142448ULL
        }
    },
    {
        {
            0x7BB56F1C201ED113ULL, 0x914FF3CF73780507ULL, 0x0C0ECAB2DA525D4CULL, 0xC66B2EC820563C00ULL, 
            0x2F212ADF920EB973ULL, 0x82D5A0A352D844AFULL, 0xC2498290CDE4488AULL, 0x3F39CBA87034DE2EULL, 
            0x506B621E093EBBC4ULL, 0x993ADB29092E521DULL, 0x801A9E39D8E70C50ULL, 0xB98545F7E6A61B97ULL, 
            0x77924BE888807CB2ULL, 0x77375DCF6E6326E3ULL, 0x328834500D39AE08ULL, 0xE3133B9AD4FF7AFCULL, 
            0x719B2E34EA3780F0ULL, 0xF46F4B61ECF0535AULL, 0x5A020C5E37CBC206ULL, 0x13FFE8251D6BB575ULL, 
            0xDDB9863A25E7E8FEULL, 0xC55D065B68D1C545ULL, 0x658D14FA94DF83CCULL, 0x6C72C44DD6B94E94ULL, 
            0x4D805F06D1D7C42AULL, 0xFF3B0DE867858705ULL, 0x9DCE53DE66A238E5ULL, 0x62E5A132234831E2ULL, 
            0x72D0F40B94D16375ULL, 0x8DA606F85675C023ULL, 0xE3DE6398F6C55013ULL, 0xCCC679F9F4F40398ULL
        },
        {
            0x7BDF8C24E4F2A8B4ULL, 0x93ECCDD7D5919F25ULL, 0x69A7B51FD2AD9854ULL, 0x3B17C9E7C1809D89ULL, 
            0xBBB46BA058417257ULL, 0x548F38CE49410FF9ULL, 0xA9824044240E5DAEULL, 0x1EF2C2CBD43CE788ULL, 
            0xAFEC4A13EF438FF7ULL, 0x5428329B98413683ULL, 0xB21EA18927A3666AULL, 0x9CB3E84E37B9AA48ULL, 
            0x337D19DABE6A0ECBULL, 0xC84BA31FE7B80A65ULL, 0xB3BFF7F7DD821EACULL, 0x86A30FDBBFA42FFEULL, 
            0xA1113A9F3F2CCFD0ULL, 0x9BC0F4A10414A412ULL, 0x325D6CEC69539631ULL, 0x6A09BF2523B7F5B4ULL, 
            0x442100E26703FB8FULL, 0xE80FFD493CB225DCULL, 0x8CC666BAC2D7E132ULL, 0xE490C58539970DB6ULL, 
            0xF4D32BED0859DFEAULL, 0x97EC6B77C9589B0AULL, 0x3A68002549BA2B27ULL, 0x16AE8809D046ABE2ULL, 
            0xF73570D6BADF7EC1ULL, 0x4CDD56BD4C6CD74CULL, 0x4B5EBC65B826F035ULL, 0x5566C54D104A6790ULL
        },
        {
            0x8AF8F6D27A0142EBULL, 0x25615494D0624B20ULL, 0x198F6F8D97E3C707ULL, 0x5420EE07E16C1E2EULL, 
            0x2E04C94C5E6DDB7AULL, 0x8BFC168CF1B80FFFULL, 0xA90D8940262F13DAULL, 0xF28D942E1346EBD5ULL, 
            0x777B69D987705358ULL, 0xA5C0B1B52A72B6ADULL, 0x2568BF1CBE5B7A88ULL, 0x58EE34D0BA45E48DULL, 
            0x4532E88AE037AA50ULL, 0x0C6D3B334A1C0056ULL, 0x17343C96E1758832ULL, 0xF7D6B06A12C53479ULL, 
            0x680D0094E65DD2BBULL, 0xAA6828307D83AA8AULL, 0x6638E45B3A9B22FAULL, 0x799219545E3E74F6ULL, 
            0x4ADDF070DBAB8CFEULL, 0x3479613ED3FE9C61ULL, 0x16DEEB91886BF0BDULL, 0x1BF432BDCBB74906ULL, 
            0x1AD0AEC93602A8D1ULL, 0x26BFF217D18BBD23ULL, 0x0DE814562817FD24ULL, 0xBABB6C1EAF37F87FULL, 
            0x8E7B4D5E3EF3A3A2ULL, 0xA4C87EAE38F82C2CULL, 0xC0BBAE68C6AB7125ULL, 0x69B16FD8317C5879ULL
        },
        {
            0x7187CE11247032FEULL, 0x6EBDC19491818651ULL, 0x6217205ABAB6D5A5ULL, 0x51EB8FB8325B3DDEULL, 
            0xA04D104ADC4AD4E6ULL, 0x35832EA45C749E2EULL, 0x4EFD0ADCBBBDD43AULL, 0x49AB5792B301F91FULL, 
            0x1E70B81EC830392FULL, 0x615F314494B4501FULL, 0xB9E95BAEC4104F23ULL, 0xA09FBCC9F694A7D1ULL, 
            0xD6B9F93EBDFEE310ULL, 0xCD298D6A222E5065ULL, 0xC29C89F688FBBA71ULL, 0x1FF24193F85783BBULL, 
            0x7EA2A879E8F0C293ULL, 0x43F66D6022B3A23AULL, 0x676E193252F2782DULL, 0x33B1C593F022318CULL, 
            0xC795FBF756B24183ULL, 0x85F4E16DB3525FE2ULL, 0x247D41AA8A1BC222ULL, 0x57EF7CDF72F0B872ULL, 
            0xDECAB697EB119CABULL, 0x0A0EB0F6640D0AE7ULL, 0x0D27A9E5B8035E53ULL, 0x261B52E20E608413ULL, 
            0xE332B198E7CAE046ULL, 0xFB5E643DD75EF593ULL, 0xB349EED10EEEE256ULL, 0xD0435848D6127687ULL
        },
        {
            0xEBB04C4E58E82C0DULL, 0x2703B8B57F36CCFAULL, 0x75560789C148DF0FULL, 0xBD7821CCD2BB3B20ULL, 
            0xFB7EDC20475A07CBULL, 0xAA72384B6E7C740BULL, 0xBDD25860F0BDDBB0ULL, 0xE5F349590234CD61ULL, 
            0xC166975F3CD95EDAULL, 0x363BDD95EC85BE3DULL, 0x53D6F8B7FABCDE6EULL, 0x9E4AD776368C6FA0ULL, 
            0x72D12203AB44DABCULL, 0x2963C2126757093DULL, 0x98A1494122F59A9EULL, 0xB7F15ED5DABF37F4ULL, 
            0x19B05EF0B337F2E4ULL, 0x0BA659CEBDDD28DAULL, 0x04CEB125E675F7BDULL, 0xA7727A0D1EACC1D1ULL, 
            0xFD615E62C93425DEULL, 0x04A1A624E736F43AULL, 0x5777797A4D9B8FC2ULL, 0x71363E8148F457EDULL, 
            0x1D628B7ABEF7DB04ULL, 0x600365F56A3CFF36ULL, 0x9EE60114D85983B5ULL, 0x4C1BBD793A87BC7DULL, 
            0x5BAF2BD1A098CFAFULL, 0xE0510B100BBD35A9ULL, 0xD58FCC2433E27AF4ULL, 0xAA2AFD9FE18B83F1ULL
        },
        {
            0xCD1293F6A58A2400ULL, 0x0694F67BA6E76E30ULL, 0x0F868121E5CF3F5AULL, 0xCF13AEBD46709DC5ULL, 
            0xE6D64B76D040C9A9ULL, 0xA792960C8D161D24ULL, 0x412DF49E1F28C904ULL, 0x7057E1C9FC996540ULL, 
            0xB0D9832834C8EE72ULL, 0xD58EA3634646DB6BULL, 0x8D898A58E9004585ULL, 0xB296CDF2848288CCULL, 
            0xE6FD999FDB11F747ULL, 0x0041AECDAEA79C1CULL, 0xDDF5A11A140175CFULL, 0xC79691B29D2AFFDDULL, 
            0xBCBC4A5AC7D69DB7ULL, 0xE1A123E3EB161BC4ULL, 0xDF7A7C1FB7FF89BDULL, 0x2F29A05373B2A13BULL, 
            0xB29952CE98A0FF4FULL, 0x8490DDF2404FCDAAULL, 0x5427BEDC4CBC0939ULL, 0x38A3E942B0EFEBADULL, 
            0x62771CAABDD9AD3FULL, 0xEAF819E95C8C259CULL, 0x91D20BD9E7B71F43ULL, 0xBACA372F617C2813ULL, 
            0x1C099FDAD0C0CF09ULL, 0x972B07706F236019ULL, 0xE4F0F029AFD442E9ULL, 0x562B3E264FF2B4DEULL
        }
    },
    {
        {
            0xC5846BBF68AB12C1ULL, 0xC6CCE204F6BA5D82ULL, 0x04F17F894735610DULL, 0x5E3117C8C5F8563DULL, 
            0x7FE55E4EC779344CULL, 0xBB6749797076E446ULL, 0x0F8D64BCAA96E8A7ULL, 0x35CEEEA078C0B096ULL, 
            0x9CA975A391B2C499ULL, 0x507B149D7A0E1B66ULL, 0xF8089A561B665C22ULL, 0x8BE361E6120CB22BULL, 
            0x71545CC6438366B5ULL, 0xD62E1169AF5735FBULL, 0x9C79033C94B5767CULL, 0x4D69B973626E1946ULL, 
            0x683732A1EC71EE1EULL, 0xE3C329BA0E699596ULL, 0x37ACBAD3F1DE95DDULL, 0xEBF7234AAD4076D3ULL, 
            0xDB642E1CAFCE7BBCULL, 0xE4F8269D6D41DCB7ULL, 0x30B581AD2B3D870AULL, 0x27D8922E269428CCULL, 
            0x0BCE91965187DA72ULL, 0xF01958217A3402EDULL, 0xCF410D968AA39F49ULL, 0x744093D1939F94FCULL, 
            0x11AD3FFB7DDD240AULL, 0x0A411181264FC4E3ULL, 0x58C84B5F896445E1ULL, 0xBD12F4E4F654712BULL
        },
        {
            0x39EC8448AA2B693EULL, 0xBA6828E74DEE2F71ULL, 0x7705B9ED36D1EBB6ULL, 0xACE0CB1CBDB0CA00ULL, 
            0x881551E8779917F3ULL, 0x170099236DFF7B2EULL, 0xCA37C661070AE903ULL, 0x975720BED18CE62CULL, 
            0xAE306D6DA95C7AA5ULL, 0x9157A0C6DEE7FA69ULL, 0xE04603F64E93EF7FULL, 0xC7BBF6AFB2D5EC91ULL, 
            0x1506A75F46C8FD9FULL, 0xB11AAA7EBB3548ABULL, 0xAF43C95A6787DC46ULL, 0xFFE8AA9D48CB1E65ULL, 
            0x450FEF7CBE7645C4ULL, 0xBE8F936294667EFDULL, 0x58EE1B7B846354E2ULL, 0x10C07F78D82F66E8ULL, 
            0xCF1F988F896A2D89ULL, 0x5387B678828B2827ULL, 0xE921782637F7517CULL, 0x65475A507066B302ULL, 
            0x3034D033F7815067ULL, 0x0365EBC020A30449ULL, 0x93CBEFD135406B2DULL, 0x0ACEAB3849F3E97AULL, 
            0x484C568667C4F7D3ULL, 0x821360B6C177A78BULL, 0x8E48EAA75750B510ULL, 0xF6E94166E69E6F53ULL
        },
        {
            0xBD6BADCF5229FD39ULL, 0xC5D1E0565FDA92A9ULL, 0xD156B164BD60B02EULL, 0xDD27133FBD4717A8ULL, 
            0x1BDFD55D75531FBBULL, 0x245A5283BCA43955ULL, 0x7A30D4DB4307AF11ULL, 0x85ACF3F749A3297FULL, 
            0xB84737B4DC9A8051ULL, 0xA917FD9890204F40ULL, 0x5365354DD18E41A6ULL, 0xF32DE0C8B58D46D7ULL, 
            0x7E24DF2D7D6223BEULL, 0x8CF17AC615FAB807ULL, 0x44EBEC9BCD344A60ULL, 0xE226579651F57E02ULL, 
            0xE0E1582A5684F4C0ULL, 0x762E1835B95C938FULL, 0x0C1A83D2E905FA2EULL, 0x093DE355894B1FACULL, 
            0x147E1A1BD7671867ULL, 0xCF9158C11F85DB8BULL, 0xA75485D922BBCF51ULL, 0xEC6E4B3AEF455847ULL, 
            0x5AD69DE27726B3FFULL, 0x881D4310D39C3AC0ULL, 0x63C7ADF50E8BA1BDULL, 0xBFB9BDD2CBD42350ULL, 
            0x365C603B5E99433DULL, 0x25A3639A928DB1E5ULL, 0x078A6560C4AEA4CDULL, 0xFF4AD1651265B067ULL
        },
        {
            0x416FF48DE04C29E5ULL, 0x5D04A6FF1D50F522ULL, 0xFACFC3725A08E7B9ULL, 0x4142D34D080B3F20ULL, 
            0xEDEEBED3CCD76CC9ULL, 0x3ED2E6756F1BE5F7ULL, 0xBC5F5BF0A4674EE0ULL, 0xC051B3116140E133ULL, 
            0x78BDAC1DDF8587C1ULL, 0x14FD4C09143F1836ULL, 0x49D081B714EDC617ULL, 0x057775640885B33AULL, 
            0x6674F784ABB7B80CULL, 0x1DBAD06BE1D2847DULL, 0xB1F89964892E571AULL, 0xFFED8E628A325A7BULL, 
            0x03C12708B86295B4ULL, 0x8EB90329F24295F7ULL, 0xF911679BC4507FCBULL, 0x1BF79B408916CB67ULL, 
            0x084921B7245A2E62ULL, 0xE9A17A61E0A70505ULL, 0xFD913526267585A8ULL, 0x43D37D24A64739C7ULL, 
            0x7778BE4C0ED34ADEULL, 0xE6EF7049207F8E0BULL, 0x797D75B527F3543BULL, 0x2388A365C0227B6FULL, 
            0x8257770A16B27049ULL, 0x1658C7ACF1255EB3ULL, 0xA43E395433EB4FA6ULL, 0xD62FCE798A86E8B7ULL
        },
        {
            0xD57A0CA85CE23597ULL, 0x734BB315E51275D2ULL, 0xD416CC3F7EFB9C46ULL, 0x8BBA4D3CD084BFB2ULL, 
            0x842014B11E1556BDULL, 0x59FB1C55638C5563ULL, 0x87680A69F2EED141ULL, 0x1BEF3ABB5875149CULL, 
            0xD13224AA5D1E862BULL, 0xEB2F8540DDB08073ULL, 0x35D18A19C868DF8FULL, 0xA1809F07844894E9ULL, 
            0x91A24E5CCEFEB3F0ULL, 0x6C779E2EE0E15FACULL, 0x47A6C95FC5F7569CULL, 0x0752B98959D88E9DULL, 
            0x490FF0BC3C88ECEFULL, 0x9850AB2BBF0F0CDBULL, 0xFBD9F146A70B4A1FULL, 0x565E429B1DB1C6D2ULL, 
            0xF08B8BFD93292CD2ULL, 0x820E76D772768519ULL, 0x2AE6A55D13594798ULL, 0x2DAE636B3A5B68A1ULL, 
            0x5E69DDC8CF556248ULL, 0x7E82C7B568A0CA73ULL, 0xA372F379D8DA34CCULL, 0x39C2A9F5A8290F3AULL, 
            0x99EE3286E5CC5489ULL, 0x076A5233FAB7C200ULL, 0x311E64739701F2A7ULL, 0x7740A47DBDBA9BA7ULL
        },
        {
            0xFE15C40383ECD27FULL, 0xCDEF2D2E1A31EB77ULL, 0x8CD269AAAAC285ADULL, 0x33B24715A837F7D3ULL, 
            0x29229939C00E9B32ULL, 0xF64E7E533CEA0B7EULL, 0x9D2449BC0E96BCAEULL, 0xBF4FBFF9564F137EULL, 
            0xB33582C48DB05AD0ULL, 0x69C8FAC039EE9BB0ULL, 0x42B3B61C2EA5C619ULL, 0xFD67B54CC9206806ULL, 
            0xF5DCEAC153BAB8FDULL, 0x31AE7EA455EE525AULL, 0x5AC8D0FCF5CDF1D1ULL, 0x77C3AD4AD0364653ULL, 
            0xE7D1A5761D5AB6D5ULL, 0x7A92787370E5377BULL, 0xB54F565F99B24364ULL, 0x0477A3BBE61E09C9ULL, 
            0xF2EF8904B4C45207ULL, 0x9D8597BDC9BFB9B6ULL, 0x76EEE4AF55967BB0ULL, 0x6DAA9433AE9FC71EULL, 
            0xE74DA2B9E41D692DULL, 0x9F4D1875713FEA31ULL, 0x4F0D22054ABA85BCULL, 0xEA7FA22D916A5DD4ULL, 
            0x00FA8A074416574AULL, 0xB951CD2F3803755FULL, 0x6EA5EC210C7A5CA3ULL, 0x00EDD439BAC2DF30ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseBConstants = {
    0x5DD66D9B8F7D9001ULL,
    0x3288A2848FB8055FULL,
    0x02E3A6F28E0EE854ULL,
    0x5DD66D9B8F7D9001ULL,
    0x3288A2848FB8055FULL,
    0x02E3A6F28E0EE854ULL,
    0xBC1970761AF73602ULL,
    0x1E8C875D8919845DULL,
    0x46,
    0x6E,
    0xB1,
    0x82,
    0x02,
    0x3E,
    0xA6,
    0x38
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseCSalts = {
    {
        {
            0xCD52DC145D9DCEC1ULL, 0x1095BF11704B2586ULL, 0x32DCDD41260B69B5ULL, 0x60CC186E383A91F6ULL, 
            0xF78474D0C0121665ULL, 0x772362FD50555B62ULL, 0xFDCB1ED8A9A2E4D8ULL, 0x597D74104E631783ULL, 
            0xE23C5E981B5A0CECULL, 0x05B81674FC1B50FFULL, 0x6B08F65AFC0D0800ULL, 0x9C71A5C9CE700979ULL, 
            0x229202583121396AULL, 0xDE12A1F5016F873FULL, 0xDF3622E4ACF5B532ULL, 0x5F78BB48AD60F889ULL, 
            0x147676B7FEF6F061ULL, 0x266AAEA4B127E3C5ULL, 0x923BBF69FBC81A83ULL, 0x7D403DC679FCD3E7ULL, 
            0x8C14F0793CA45963ULL, 0xA91C229BB2D74801ULL, 0x052307B884ECFC7CULL, 0x313842C2E89610D0ULL, 
            0xE5A64EA0B05D925AULL, 0x658B21E9649879FAULL, 0xA3D6D995F6791DBBULL, 0xBD5C083035821673ULL, 
            0x44CA6CAD09B9B836ULL, 0x541D97EEBD7ABF76ULL, 0x903EC6B35A756EEDULL, 0xA982520998813F70ULL
        },
        {
            0x3A7DD377D2E5EA21ULL, 0x834DCA36E54C0EBCULL, 0x8200B66C30BF4A49ULL, 0xBB2C25C75890FDCCULL, 
            0xD6A2761BF3BCE901ULL, 0x639A7519F467FB19ULL, 0x1F6FAA03BE7EE8B1ULL, 0xD7C3F60F00A2603EULL, 
            0x26345B294B9FB105ULL, 0xE8852FE4D401DFADULL, 0x6132452F2B2C4D46ULL, 0x8C6AA6D5FD1BD3A4ULL, 
            0x4350C3F0844B74A4ULL, 0x12B71A7FB3B1C2DDULL, 0x1659B0ED011BEBFFULL, 0x75B57FB4246F7A46ULL, 
            0x408E38105F8F4C10ULL, 0x30B67DD8368A3138ULL, 0x6A35377B9DDFD951ULL, 0x4FEF96DEBFE2FDB6ULL, 
            0x7EB5EF22CDB1837FULL, 0x24C568D1F057E00DULL, 0x1C8763D6537936ADULL, 0xA6E2664649446234ULL, 
            0xC232959A66CBEEECULL, 0x6739265B6BCF285FULL, 0x2BAE8D94E3719AA7ULL, 0x4853F959E4F95A20ULL, 
            0x3FF53C0F9661B876ULL, 0xFFD64A8A520DDF84ULL, 0xF48E08C5E161A781ULL, 0x49D25407437B0A29ULL
        },
        {
            0x251ADE228BAD25EAULL, 0xEB0098A3AA5B4BCAULL, 0x75A6C185DC104FDCULL, 0xC8D7B67875721ACDULL, 
            0xC380ADB7276BDBFAULL, 0x85B2FD8715A119BAULL, 0xAC4D77C6CD3292ACULL, 0x78A16DDD946631E1ULL, 
            0xCD71D5FEEC2B89CAULL, 0xB481B9AC24E64E09ULL, 0x95B282FAD9D24A4CULL, 0xABA2E5669155659EULL, 
            0x6C645509D3ABF52EULL, 0x78CB6F8B530A8A48ULL, 0x79F9DD9CCFFEC44DULL, 0xF17FF0FC3B866DB2ULL, 
            0xFB561C870B3990AFULL, 0xFF14C6A996F250EAULL, 0xFA71F51FD7F7AC2DULL, 0xA906000A19D5AF97ULL, 
            0x647966D910F226ADULL, 0xD596DBB280439126ULL, 0x88D7D034D4A5BF99ULL, 0x5EBF5F551F59C1ADULL, 
            0x63D71D379A4F9A76ULL, 0xDACB77B8FB8E165EULL, 0x2F589453EEABC8FDULL, 0x6E09B4026F0B6E76ULL, 
            0xA68359B91B2F5332ULL, 0x31F512754105666AULL, 0x6531F15F1C0C79EDULL, 0x6053440CFE110542ULL
        },
        {
            0xFFDE57C9023038F1ULL, 0x074F0728F6A841CCULL, 0x8C64301DC0E9741EULL, 0x9C8B222FE7AFD2A3ULL, 
            0xE7CD29FBA7107B2DULL, 0xEFB254BE72EA8BEFULL, 0xF1CE1357A2F18E0DULL, 0xD89273914336A75BULL, 
            0xB680BF820FEAEDC5ULL, 0x8FB4E308D7E50895ULL, 0x8BAD405077EF1EFFULL, 0xDF3A3AAF5A2ADF16ULL, 
            0x4288ACFCE0CA0648ULL, 0x758D0B7FD40C5B39ULL, 0xA8137546FF9E3DE2ULL, 0xA373E074E00EECE4ULL, 
            0x4BE2D4291A692944ULL, 0xD6F800F6B3FE0A38ULL, 0x8A3C2FF9D5BE0DD4ULL, 0xA4A5CC970D8F6F70ULL, 
            0x75EC259AC4E28099ULL, 0xA22D7E41AAED4A5FULL, 0x59F9A06737EAEF44ULL, 0x34BEE50820D1D0B8ULL, 
            0xDBE89420EBE2F71BULL, 0xA0B58A47DDDC01FAULL, 0xBB2DD84AF0685928ULL, 0xF158D498E16C4BC0ULL, 
            0x241B79C1102214D4ULL, 0x338A03AC1FC7E92EULL, 0x10A572844BFC0EAEULL, 0xE417646C40A6079AULL
        },
        {
            0xF68A3E3025D2A7B6ULL, 0xE3D45C0DBD272523ULL, 0xA0E5B5D50E4AB199ULL, 0x7609AB55DDA939C6ULL, 
            0x476012FB812AAF4CULL, 0x7C06FDF55DE56CAAULL, 0x9186347895696AD3ULL, 0xF4E79CDB96E86E80ULL, 
            0xD39493FA1C186126ULL, 0xAA6FC02C46E3DE06ULL, 0xE3FC83CEE893E9E5ULL, 0x74497BCFD5B0032DULL, 
            0xED9E9442D6999735ULL, 0x03188A9CCBBC2D03ULL, 0xA36F5F616C689B60ULL, 0x09AD09F15DF35D9CULL, 
            0x897A718A25118792ULL, 0x5B2988EF63C39D6AULL, 0xE0622438E1BF34D7ULL, 0x080387B87506D300ULL, 
            0x69684009A3D505C4ULL, 0xFF90FE64C7ECCCA3ULL, 0xCD5DE206624723F2ULL, 0xF1F87B576B0FEB0FULL, 
            0x2328DFA780227EABULL, 0x64286C8AD9FAE2B4ULL, 0x5D27E4ACC2D2E4D5ULL, 0x942D85615B3174A7ULL, 
            0x0D009571832BDA88ULL, 0x0DE998F79116D78CULL, 0x0F553DC18AFB5049ULL, 0x4EBB0181AB3A728CULL
        },
        {
            0x7D634964E842EDE4ULL, 0xDCF83D314B9E1F72ULL, 0x73CDF4BE06A83218ULL, 0xDC9F4FA423E47E2AULL, 
            0xA578A4EDF243E1FBULL, 0x03EA8EC450729D71ULL, 0xACC098E1610FACABULL, 0xB3B6F1D9F2D8A505ULL, 
            0x551F2FEE2397153FULL, 0x751ECD78E0542007ULL, 0x87E5713FD1F05D19ULL, 0xB5626F959F0170EFULL, 
            0x9D92796F911CC0D8ULL, 0x1B9C15FF4DBF951AULL, 0x07E52E7F43638B37ULL, 0x839A7A2E681BFF7BULL, 
            0x4424D6FC7AE814D7ULL, 0x557D2D8BB4BD1C7BULL, 0x47A103FAFE16E6C2ULL, 0x2A03038DABA945D3ULL, 
            0xC4979598C941C9C3ULL, 0x48311939AAD48695ULL, 0x8B4F990C3BE7966DULL, 0x11B0704F14FCDDC5ULL, 
            0xDB1C8482DCE59D15ULL, 0xED78D31CC14AE227ULL, 0x4ECD98CBC4A4D255ULL, 0x20C103B70C4B3BFAULL, 
            0x5FAC8674F5E4A104ULL, 0xD7CB8508B9BBA25BULL, 0xBBC8CE0621D273B4ULL, 0x5FDF2F645A464CECULL
        }
    },
    {
        {
            0x2DB021B469BECBECULL, 0x4897D481EAD5E8E6ULL, 0x0B4E7F09D8180BC4ULL, 0x8B88E8D44DBE1804ULL, 
            0x4C1C40D03400B0D7ULL, 0x5089D17C18E447A6ULL, 0x6CA852B182A1C576ULL, 0xDAF2FFBE67846EE3ULL, 
            0x1484BA575001B131ULL, 0x149BA80FBA4AED7EULL, 0x4A95F9434188D920ULL, 0x431B2D94712EC0DEULL, 
            0xE6B927D24B29F9EAULL, 0x020C8E881A3AC4A5ULL, 0xE1B405F174F0F550ULL, 0xEDF2613BFA185963ULL, 
            0xBD79A8CD5F370DC1ULL, 0x20FDA178575B3650ULL, 0x3856FA7F5C80A049ULL, 0xF9936F3151484249ULL, 
            0x8C92EE7EA35C03F8ULL, 0xDFD955B455792A4CULL, 0xFD05C25392599929ULL, 0x8BE1BBEC3AC6A7E0ULL, 
            0x03DAB4B0871AAACCULL, 0x3BC4D5ED81E33BE6ULL, 0xC4A340EDD74914D4ULL, 0x1702374C9ACAEE13ULL, 
            0x2A52DB91A930A603ULL, 0xD8EA5546B66D2C8EULL, 0x5F1327F47087B2B5ULL, 0x497E31C7E52F93D7ULL
        },
        {
            0xCB1A8CA936DD3699ULL, 0x6DBE874B1969BF29ULL, 0x95261C268CE75409ULL, 0x1EF4AA485D82E81EULL, 
            0xC3E417C808108A7EULL, 0xDC1FF231B5A25DF5ULL, 0xB1ED11EB70A1D26AULL, 0x4A0655B001D9689BULL, 
            0xEC83B511C38977BFULL, 0x037B8BC5E9F36458ULL, 0x63B574246F6AF7AAULL, 0x4E05A240BFF4C42BULL, 
            0xE4B53305C3F77E85ULL, 0x7E33930BD8F759E0ULL, 0xC9FE87320AEC457CULL, 0xC84079D204944194ULL, 
            0xB463E69A786A638FULL, 0x9D896F18A74FCF93ULL, 0x02478278EF1A6F60ULL, 0x42F3D69E1A2517A9ULL, 
            0x4C2C9A9CE3850AB5ULL, 0x80B813C4EA08D320ULL, 0x5774FFF470DA30BCULL, 0x029EDC240AD9ABD5ULL, 
            0xEC9BF7F1CACA5484ULL, 0x01A362BEC884205EULL, 0xDD56C181A475D2E4ULL, 0x8019C652C88DEE92ULL, 
            0xA694502CCCDD0413ULL, 0xCA7D61AAE4F4FCFBULL, 0x1B21590AA581109FULL, 0xB202EFB063496F89ULL
        },
        {
            0xDC8A77E2BA4DDC61ULL, 0x821466F7BF390AFEULL, 0x2D270A5E5AD27955ULL, 0x90325BB80E4F9CC9ULL, 
            0x0DD75A745940B0EDULL, 0x54F9FF1B5397A654ULL, 0xD127CED535C188DAULL, 0x9C6B378A5685AE52ULL, 
            0xA126B2859873C6CEULL, 0x78C5B6DD05D8AD78ULL, 0xC171504E43C72CCDULL, 0xBBA5590B6D4B3129ULL, 
            0xCE0AF89B7396BF08ULL, 0xBEFDB8AE99F7764EULL, 0x70BCA84562C3B4A1ULL, 0x40974CDD7DA23D9FULL, 
            0xD06EBFFF4A2D604DULL, 0x5404245D9AF8812AULL, 0x21A2FF3AA5E96205ULL, 0x462515123D6BB0DBULL, 
            0x91BE69E640E63A9AULL, 0x224A547A8AF91A21ULL, 0x801713227933943FULL, 0x1D799AAF8641A07DULL, 
            0xE0F42E1547902810ULL, 0x315855E2925743BDULL, 0x5AE6F02A1CCAF435ULL, 0xC495BAAB5C09BF42ULL, 
            0xD5335C4AB8756C89ULL, 0xC69DA5DEA07D3A02ULL, 0xDAAD97FFE110AC0FULL, 0x9457079E1E9F25B0ULL
        },
        {
            0xB3F60A8101357971ULL, 0xB3068385F76BF9F0ULL, 0x9711D43BD6BC0000ULL, 0x967A09C0C9452E79ULL, 
            0x4F314AEE369D422FULL, 0xF66CF510B55A6983ULL, 0x9C3032C9F5FFBC68ULL, 0x917F17DCF3A00659ULL, 
            0x6B36858E1A782443ULL, 0x50696EB6F98CCF91ULL, 0xFC0A18BC606B6017ULL, 0x235452E417C5DA75ULL, 
            0xA06C3CB0462EE98AULL, 0x2669FB40475D4367ULL, 0x4A2FE01DE8CF2A49ULL, 0x23C319310B2941A7ULL, 
            0xDF7FF025794BADEFULL, 0x0693CA35D368243CULL, 0xFF0B2BB7CB3F18DFULL, 0xAD8AECEA994CE12CULL, 
            0x029F68972BC51668ULL, 0x9020BF8D6FABF09BULL, 0xFD89ACF6D7998CABULL, 0xD53959E9ED518ADAULL, 
            0x56FB5FB80463CECAULL, 0x5AF09B5F21178FF4ULL, 0x6A1A6F0AFCAFC168ULL, 0xDC935E5874528D62ULL, 
            0xA5DC9E632F77D0E6ULL, 0x62B9E6BE814BEBE5ULL, 0x58B171F4DAB8F9E9ULL, 0xA0094D1B4260E593ULL
        },
        {
            0x163B918BF6FCB05AULL, 0x381607BC004C1D63ULL, 0x2B4012AEDAF48F6EULL, 0x1C4B51C471280089ULL, 
            0xAABF1F142E953D05ULL, 0x5EFBD9682F5CAE9DULL, 0x7E14BE671E943C7CULL, 0x8488EA3F6FDF0207ULL, 
            0x5ACC0A43A976D8CEULL, 0x4D9E55C9BC96A745ULL, 0x8295C4E4161C41C0ULL, 0x34B349777B470B62ULL, 
            0xB8C3E57083293B16ULL, 0x1E179805CD1BBC3EULL, 0xA035D0BE3C9C2C9CULL, 0x6E4D27BDAC4B8E17ULL, 
            0x02ADEB1C2B9ABFCFULL, 0x53F75D276E3FF7B9ULL, 0x9384D5274BB78361ULL, 0x46B4C15A2AD7EC2FULL, 
            0x0EED5CC260B1C108ULL, 0xD66AD3EC9140C73AULL, 0x9E6C1CB0BA4EE00CULL, 0x4B441C8FF19F1167ULL, 
            0x6682EF95211BA424ULL, 0x1E201C5EC9996FD7ULL, 0x148C456FC827EA6AULL, 0x36E2825A4C357724ULL, 
            0x9637D616C71DE11FULL, 0xAB19E0A08BF12746ULL, 0xF1041CD3E6D40FFBULL, 0x22A373AB6C2BFF34ULL
        },
        {
            0x82BFC58E3E3B149AULL, 0x643CB7D7C304B402ULL, 0xB7044767D07FA55FULL, 0x5C6CB7CEA1BAE074ULL, 
            0x9340E803EE6FCA40ULL, 0x95C593C1F698EE35ULL, 0xAD25A52CD41D4D2EULL, 0x333A65DEA6163054ULL, 
            0xA70E9A2E9A8B7329ULL, 0xDAFC12334E36BB22ULL, 0xF4B34F0C3C28F763ULL, 0xA310920638BCC586ULL, 
            0x74A4FDA7A509EB10ULL, 0xF656BFB4AAB5AB4AULL, 0xBF9BCD3556A03415ULL, 0xAE4C4060E1C8872EULL, 
            0xE390F2A9F4889232ULL, 0xCDD13ABD04097C53ULL, 0x38421F500CAB8F0BULL, 0x86CBF0B5234F19CDULL, 
            0x9322CFFDE98A5F93ULL, 0x89431BF8E4D5C8DAULL, 0x40C19AE088AA6DF7ULL, 0x7BBF2B272788A077ULL, 
            0xE92BE629238CD787ULL, 0xBC41F1AE64C46629ULL, 0x5817E688CF2EEB36ULL, 0xB9A3D1022D65F259ULL, 
            0x9FB4A344CAB7F4B8ULL, 0xEE51AFF70CEE69DCULL, 0x0551EC031D550D7FULL, 0xF8453022EEAFEF3AULL
        }
    },
    {
        {
            0xF40AA58F189A3E4FULL, 0x75F364F54C39A6AEULL, 0x3680B89999A16323ULL, 0xDEE68BC7665F82B3ULL, 
            0x7D6AB73324760EBEULL, 0x30E4CA26A91AD1C7ULL, 0xFCA76592C84BFE7DULL, 0x2C6426A4F7CED5AEULL, 
            0x90F41CC5CEE55E3CULL, 0x091B6886A277AD46ULL, 0x996A275AE5A4C8BBULL, 0xAD2F40FF7E2727B9ULL, 
            0x94B6A3D1E1AD24B4ULL, 0xDF01C00EADFFA2D5ULL, 0xD71E1F34E5ECC00EULL, 0x8DD21174C4041476ULL, 
            0x9634611B7C4C5289ULL, 0x0129DEF33F0BA9AEULL, 0xA4D57ADFEB94EDD0ULL, 0x0D556E8276C3FB6CULL, 
            0xFA44835E53BA9930ULL, 0x4A55A4D5AE72FB77ULL, 0x548D3EDFE4E007DFULL, 0x47536DC2C6215A90ULL, 
            0xCFD753D51655B75DULL, 0x365E30CFE120232BULL, 0x8950BF421C68CF85ULL, 0x7A31A825D1E09111ULL, 
            0xB87A11E45CC3F6C8ULL, 0x2E9FE9A3D9CEDD91ULL, 0x0A79E5B95182ABF2ULL, 0x0924820C16378D6FULL
        },
        {
            0x082A343D1D0A6CE8ULL, 0x272339B8F1CABDD3ULL, 0xC6C0AB607A1A5181ULL, 0x733769C5BF8B596DULL, 
            0x198402A8D1880CC3ULL, 0x6EA440E8F2D5AFF6ULL, 0x6A1C8955AF4A958BULL, 0x284218B1639110BAULL, 
            0x2C28C63DC5D3D28FULL, 0x4AA720D51705C79CULL, 0x6569DFB860723E79ULL, 0x592532F39BF79A25ULL, 
            0x469DE6E5DAF207EAULL, 0x6FFAE61D00B34FF2ULL, 0xE24D2B1729370BD8ULL, 0x6AFABB8E19A43AA6ULL, 
            0x5F4AA83B93B31720ULL, 0xB55DF5C2F53F76DCULL, 0x991271B6D33F019EULL, 0x30B3878DEAC53AB2ULL, 
            0xE6F5559B4DCB679FULL, 0x16ABC190391CC3ABULL, 0xB70A1ABEAF49431DULL, 0x42B0E537D76B00ECULL, 
            0x454846E6B464AD3FULL, 0xA706C9F6766C4A70ULL, 0x4FEB83C9BA731ECDULL, 0xA68D76F322B4AA38ULL, 
            0x2621F164739E8D5EULL, 0x835FD270431BC539ULL, 0xD2F0EAD558036EE8ULL, 0x0D6A80EC9CD342FFULL
        },
        {
            0xFBA02CD367337CE8ULL, 0x92619AFF02764369ULL, 0x315F50EB8B9DCB06ULL, 0x0FB4D77E01F147C2ULL, 
            0xF37F094CE410B114ULL, 0xFE7CED1D97E18ECAULL, 0x0E3CFA93DDC1266DULL, 0xCC33AA55CCD92A0CULL, 
            0x72B2DF07AD93F06AULL, 0xCE22BE44EB188F6DULL, 0x339DE3526BB7203EULL, 0x191BE41CBCEF28D8ULL, 
            0xA3F178FD4F0C5BC7ULL, 0xADAA40ACA4E9E1F7ULL, 0x4F196B1F2017DD0DULL, 0xA57C6569AC6710B1ULL, 
            0x795E685C1A7F4443ULL, 0x2302A75A40EF5979ULL, 0x6FBD122930F81E9DULL, 0x2258FCE66876DA7DULL, 
            0x75FF405AEA563841ULL, 0x0A567EE0249F3570ULL, 0xBDCCFD9D94618B8CULL, 0xA232770FCC3B1086ULL, 
            0x21F3E10AD58636B0ULL, 0xC28DD98766B3967FULL, 0x0C8879D8BF1CDEBCULL, 0xF0434152CD1799EDULL, 
            0x63C344A08F8C5540ULL, 0xE5D18606F273AA2DULL, 0xBB4E82DEAD88A256ULL, 0x501A23F624BE7A47ULL
        },
        {
            0xDB05723BD1C9BA97ULL, 0x94B5D6B303BF7D29ULL, 0x9C2ADC236884C23EULL, 0x5EE88F584FF36BD6ULL, 
            0x94FC9712C329C4CAULL, 0x22687BB3D0AA0D69ULL, 0x44409BEC7F492B5FULL, 0xAB06394008B0D8B6ULL, 
            0x693C28057370222DULL, 0x42D738351AA053F0ULL, 0xC6D6DFD96CD4C014ULL, 0x7B16EC325AABE703ULL, 
            0x60CCC9963D218195ULL, 0x613B723C4D6307F9ULL, 0xBFF851FC29570B78ULL, 0x30F3B505A7BCDA2FULL, 
            0xF1443C7D5BB2DD64ULL, 0x7DD9D0A265BDFBECULL, 0x7437277E22611811ULL, 0x90BD4B9DE54AC772ULL, 
            0xE1DE4056A07AF4ADULL, 0xB1A2D1A38B4414F3ULL, 0x511DFBBAC0D4A056ULL, 0x8DE029EA2A979423ULL, 
            0xF819609C1220C4B8ULL, 0x77CE8A9FBB6DF97AULL, 0xED3E5B044A3EE4F1ULL, 0xE640F7F1AB9B0BA4ULL, 
            0x72624BF20B370B69ULL, 0xBCB7F492C9316E44ULL, 0xC516A510D74D6799ULL, 0xDA76A706E02BDD92ULL
        },
        {
            0xDF2DAEBE49D56FECULL, 0x887616F0B220BDC8ULL, 0x705A5077532CA939ULL, 0x6456AF7577E5F82AULL, 
            0xCCE08DF8F4D7FFF5ULL, 0x5B51580842175414ULL, 0xF50B5244C5B62FA5ULL, 0xC3B30EEF0D297D5AULL, 
            0xB941D6F47B81F6ADULL, 0x9CD9556E7BE42FA2ULL, 0x6E9F2926FC8510C1ULL, 0x459F9B51E2CCB43BULL, 
            0x8566E60E22C0F0AEULL, 0x5C472E2EC6A16E5FULL, 0x450541025735A82AULL, 0xA3FC915145843516ULL, 
            0x173B15FBBC9346C2ULL, 0x37D19CC702F3C881ULL, 0x583A4ED5464B2241ULL, 0xE1EE41FE81FE343FULL, 
            0xF90EE234C4C3785CULL, 0x9F68F6FF88BD9130ULL, 0x3EEA5B4062568DE1ULL, 0x840F115E2C7D9FF3ULL, 
            0x4C30468D70D6C0ABULL, 0xD1D2FA34F0F6F456ULL, 0x9062C8066F0477DBULL, 0x6E2B642113C30964ULL, 
            0xE6265C1751AB55A9ULL, 0x7324E6B146D9129DULL, 0x79062DCFA39E3334ULL, 0x66ADC4AB62D3BC22ULL
        },
        {
            0xF34862A095A629BCULL, 0x4CF7CED6D1F0FF24ULL, 0x29DED561127F52D0ULL, 0x672C82AA86B1CD03ULL, 
            0xE956D21E4EAA20A4ULL, 0xC2E967587E78E1BCULL, 0x47F8553E8F7410FAULL, 0x3E7DE91E37B6C970ULL, 
            0x2F9E68D4355647B7ULL, 0x8C2F4E9AED857CEBULL, 0x03DAC2A568E989FCULL, 0x1E35502FEE43321BULL, 
            0x4A028115E506F69AULL, 0x720A2D6267F9D1E7ULL, 0xB991834F824FAB57ULL, 0x9898B29E825D512EULL, 
            0x6D73DF734A97EB46ULL, 0x99852D43E1458EDBULL, 0x63871948AC71E66FULL, 0x07961ADE54C3E570ULL, 
            0xA35DC81C9546B6E9ULL, 0x265D2150AA3E989FULL, 0x281644693E29299BULL, 0x25BD9F444895DDECULL, 
            0xE0D6F27419E3D08FULL, 0xD6C195B72B5D8AEDULL, 0x8747B88C644F71D3ULL, 0xA644B291DCB8A000ULL, 
            0x9BB014BB9E254D95ULL, 0xE505432862BF5573ULL, 0xF35FF410FADC8A39ULL, 0xE53E4AC3C30C0F32ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseCConstants = {
    0xBC2B303DA1AD7D42ULL,
    0xDE994CB68331D6C3ULL,
    0xB97138EA91F2B31AULL,
    0xBC2B303DA1AD7D42ULL,
    0xDE994CB68331D6C3ULL,
    0xB97138EA91F2B31AULL,
    0xAE50A3275F5C7B28ULL,
    0x00ED722B278337E8ULL,
    0xD0,
    0x02,
    0x47,
    0x81,
    0x49,
    0x87,
    0x5E,
    0x7F
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseDSalts = {
    {
        {
            0x478662D3B4273580ULL, 0x22943CC8B8963E44ULL, 0x5DFA1029856576A6ULL, 0x36271E4F2757EF79ULL, 
            0x43D30803924E4F7EULL, 0x58056EEF0230C5B2ULL, 0xBDF0319F2859E326ULL, 0xD7BE3566231C8FEAULL, 
            0xA98D11C3C8DF9F09ULL, 0xA79FDE01449F76A8ULL, 0x0197C010413657DAULL, 0x0010396430C05413ULL, 
            0x5D4609E372D4850FULL, 0x23DBB2F0F61A90BBULL, 0x52BE2B2CE19AD693ULL, 0x18E5FF53C9424D51ULL, 
            0xB15259372DCF19A1ULL, 0x83A572D029AEF71DULL, 0xD05848FEA14E1169ULL, 0xA69D359F16DD85FFULL, 
            0x76F505C7425EE15AULL, 0x9F54A6E6EA78FEDBULL, 0x6D1F4F3E01A9CCBAULL, 0x4528347FD95C3541ULL, 
            0x3AE173788FE7B6D9ULL, 0x02F6EA91850FE339ULL, 0x2EED86404B0EFFCCULL, 0xD19EA09164386771ULL, 
            0xF3D3D0639099DB0EULL, 0x1819A3FEA4665A08ULL, 0x8E3DBF7096F4D2F5ULL, 0x8769D01E48CE74F6ULL
        },
        {
            0x971AC036E2E8C217ULL, 0xC4F85B39CA9CF903ULL, 0x058316BA1BEEF3EDULL, 0x8A5F28BA74FB72B6ULL, 
            0xC753FC66062DEA52ULL, 0xB0C1E78A40A660FBULL, 0x1AE4683541B5B056ULL, 0x2112EAACD0BE3281ULL, 
            0xB410B5B3F24454E2ULL, 0xE780DAF1E43FAF98ULL, 0xD808A766F91CB396ULL, 0x65B1D13062584406ULL, 
            0xE94FA9807EB8D1B2ULL, 0x2EB84F95DB169A72ULL, 0xCE59F2C3DCF8BAEFULL, 0x732CE4CC0297E889ULL, 
            0xAA12B2C66AE9889BULL, 0x924C671C2545DCB0ULL, 0x1D50DF2F27A94683ULL, 0xB0461C724B0EF8EEULL, 
            0x9CD822BFD5D1E440ULL, 0x9DD8B98A30A5D829ULL, 0x0DF16452E6CF3C43ULL, 0xC9FFBD59D4084FAFULL, 
            0xFB7F76E83223DA78ULL, 0x54B3D9F1EEAA0C25ULL, 0xB4F80D66740E02AAULL, 0x20143ED21E022F3EULL, 
            0xB192A37DFCE9584BULL, 0x2FEE6B5D50A33C0DULL, 0xC3C6B7A11DED9069ULL, 0x84149CFAD68617E7ULL
        },
        {
            0xC80B38BBAFB40449ULL, 0xD9EA04364719401BULL, 0xEC2A268DBD28AF43ULL, 0x24DD386FFAF27B63ULL, 
            0x276A7DF5211DD4BAULL, 0x2CE77CF60AF91776ULL, 0x3427E8D08E42924FULL, 0x645D829B2C0F36B6ULL, 
            0x68C000DF938DDD5AULL, 0x682331048C8200FCULL, 0xC14CDE755110B3C9ULL, 0x138B8ABEDF678FC2ULL, 
            0x30D2E95A7E79B57FULL, 0x5A206D71EE06BA69ULL, 0x332499B487A76FF6ULL, 0x62D729DF58B20307ULL, 
            0x29D75B205E68ABF3ULL, 0x2EC0D1DAF261BB82ULL, 0x5830041BA1111056ULL, 0xDE13C6346CC43AC3ULL, 
            0xDA15AF35E0E7FC8CULL, 0x59BB1BAD5489B9EFULL, 0x1DEB606BF0E2D1D8ULL, 0xB421A36E137896A6ULL, 
            0x349B0F8C2EE9A7ACULL, 0x0D4A7D2197467522ULL, 0x6FC8D42829784942ULL, 0xECCE73F5A8C1D14DULL, 
            0x253AB060AAF35FDBULL, 0x2B5BD01E551C8ABEULL, 0x856A89CD58B547A4ULL, 0xE58806202137F85CULL
        },
        {
            0xAEE670FE2774EF68ULL, 0xECECBF02855D4C3CULL, 0xE24C66AF2A1CA70DULL, 0x383DE2FFBD57768FULL, 
            0x353540929044617EULL, 0xE50A24557CC502CBULL, 0x03DDC83C222EDD18ULL, 0x2623AB1AED645D98ULL, 
            0xD3DFE7100E1D0542ULL, 0x7CB65814C65F60B4ULL, 0x31E06284BF715CAEULL, 0x5205AC0C9DBFCDC9ULL, 
            0x60E5C252978D618FULL, 0x8F040E7F8DC08157ULL, 0xEBD0728ED557DD66ULL, 0xAB752017AC12F35BULL, 
            0xBF58CC8E335C51D0ULL, 0x4658BD5019ED99BCULL, 0x1A67E6E3ABF1F2D0ULL, 0xA3CA5AA8CF2BAB29ULL, 
            0x7B55695E748E8C6AULL, 0xFB0E1FE51E4CF90CULL, 0x0CF7366827498962ULL, 0xE267B896A48A36BBULL, 
            0x17F76439237B55D1ULL, 0x2D581A15E34094C9ULL, 0xA66C60B7AE8195F0ULL, 0x9CDA8DDDEAC0E2F1ULL, 
            0x45BDB9BA7557195EULL, 0xF8E03CA62E7675B5ULL, 0x0EF9A22CF62CBA2CULL, 0x711228516F21F570ULL
        },
        {
            0xFFABAD07F3D4261EULL, 0xEC9FF2C081EF9066ULL, 0x0AF2E5B92BA2DDF5ULL, 0xB33786101BF8A143ULL, 
            0xC15BB858A1F1F79EULL, 0x0927D3334A3E0F43ULL, 0xC92BE83B74DED971ULL, 0x921639DCA4FC6EB4ULL, 
            0xEDF74A90B1311EA5ULL, 0xBD9837EC104397ACULL, 0xB794E188B7D959FFULL, 0x54D131CAF720DE10ULL, 
            0x1A3C7B053515D265ULL, 0xA85D9A382A189AC4ULL, 0x3B04EEBD0E0A9582ULL, 0x2783B155431874D2ULL, 
            0x1FBDD776FE590EFEULL, 0x560E9B20E0FE1E20ULL, 0xFD5778C436196AB9ULL, 0x3743409B01AA44C2ULL, 
            0xCA557823FE7C3A92ULL, 0x5AFFFD94DDD8070EULL, 0xFF9A08B67EB00F48ULL, 0x3B46C046B3F0D66EULL, 
            0xCC214A955F6F70A4ULL, 0xCD4146451968909EULL, 0xE7FBD37B3FF7CF10ULL, 0x030453F3E7D1C9A1ULL, 
            0x3F8FACEDE6FBFCA7ULL, 0xFB74BA9867D30260ULL, 0x1B1E60202AFCFDC4ULL, 0xB354F57952F07DACULL
        },
        {
            0xB3D2318914B0DB51ULL, 0x626D718B0838B949ULL, 0x8CCE5D301E571A15ULL, 0x2ECA15D30D3B54D4ULL, 
            0xA28CF4A6EAD3FD66ULL, 0x96222CA22EC2EF7DULL, 0x1A02774EF7531921ULL, 0x781C4EA3E7F55BCBULL, 
            0xB17A5691AFD82809ULL, 0xF19F186AA0AFDB79ULL, 0xD6FF718503081EB7ULL, 0xC43CF5FB23CB4CB0ULL, 
            0x42BCCA6EF2CC9457ULL, 0xC509AA46B21F902BULL, 0x8DEE75540B9340C1ULL, 0x26911BD9F6A6A4CFULL, 
            0x8232E53C08786D34ULL, 0x4F84030AB51F56AEULL, 0x91A9726DE2EBD4FFULL, 0x904D519A40509699ULL, 
            0xA39D1867A23B7783ULL, 0xA19A3B4E9C5C2121ULL, 0x62C72F4A862AD867ULL, 0x497400CB53F1CDAAULL, 
            0x91361AE1D4BF679CULL, 0x1C7CAB7E222E8349ULL, 0x04B0C17143D645C7ULL, 0x5F4808FE8A90E5B0ULL, 
            0x2D4EDF908DA7F823ULL, 0x51BD7E008320CEF9ULL, 0x93CCA0B04881BB59ULL, 0xA40171D3444F199AULL
        }
    },
    {
        {
            0xD71513C91B2E4929ULL, 0xAB987CB91A4E6B34ULL, 0x2519287812FB72B1ULL, 0x01070AEE1D46A641ULL, 
            0x7AA3DC25EFE20A3BULL, 0x2532EF110B4023B6ULL, 0x5ACE3C20AC48A422ULL, 0x004905A22DCF9DA0ULL, 
            0xF9D9F5AFC9C87E97ULL, 0x8300189774E37016ULL, 0xE7747714D1DCCDABULL, 0x96D1177E261DF524ULL, 
            0x28EC3C545B352983ULL, 0xA875404A36772F4FULL, 0xCB01D1D89C732DFDULL, 0x0144BD36B6114AD0ULL, 
            0x42C31AE9C34F7DEAULL, 0xEE514D891711A553ULL, 0x8F5C85EA12257487ULL, 0xB5B28497CD4AC373ULL, 
            0xDF93DD1573ACD668ULL, 0xC77A1010D9AEBEABULL, 0x9651B1FACE8B20D2ULL, 0x3F50E19AE8F368B6ULL, 
            0x24B142AD570C1B89ULL, 0x3B70742151EE6EE5ULL, 0xD26D69A941F3FA1BULL, 0xF0287E576418504AULL, 
            0x7EF59D63C60823E2ULL, 0x92BF7A1F10E8E086ULL, 0xADA24471EB0E4CA5ULL, 0x771E8B14EBD61035ULL
        },
        {
            0x26E1EB5B18274EB6ULL, 0xD53AC80B06A88D81ULL, 0x76882744F46F17B8ULL, 0x2706F8762873456EULL, 
            0x871666A20A2D569EULL, 0x8F7640F14814B45EULL, 0x5F835A2C5D00A39CULL, 0x54DCAC27C24E0CB3ULL, 
            0x7C5939E0C4C4D21BULL, 0xB17B53531F01DCE4ULL, 0x11AE5BC4FB1BE5FDULL, 0x8CE328357027601CULL, 
            0xB8F96CF4DE18FC61ULL, 0x1D24B58B31865977ULL, 0xD2784CAAD72944DAULL, 0xD3E74A22E06630CCULL, 
            0x6B65800193401BCEULL, 0x93D5C49420521BC1ULL, 0x9D0B973E80FF9DB3ULL, 0x29DACDA6CC31B5DCULL, 
            0xABC84E85FE85BFE4ULL, 0x1DCB3248FFC65DDCULL, 0x83DE1AE7622FA7E5ULL, 0x946914538A1FE79AULL, 
            0x829B4CD88AF4D25DULL, 0x7B60796D2E4A37AEULL, 0x86CD09FA49E35A4DULL, 0x1D21CF3E9799B87BULL, 
            0x2B882B0B4E9E9591ULL, 0xA5A726102EE16DE0ULL, 0xCA12F41752827F98ULL, 0xB3DF7D15764244B3ULL
        },
        {
            0x6652E7709CF8DE3BULL, 0x48FA2C4305D549A2ULL, 0xA4106741570C31B0ULL, 0xCECBD742D50EAA90ULL, 
            0xAACF5E4AA896EA6EULL, 0x3DDA747A74CF7DA5ULL, 0x74A44E3B2DD023A1ULL, 0x4D3E9FBDE60D6A7DULL, 
            0x85FE1BDAB34523C4ULL, 0xE43A2ED68E315193ULL, 0x3E915E09E27C3B32ULL, 0xA0E55FC6B5DF0A25ULL, 
            0x49B50BF5045DA21AULL, 0x22CB0D50705AD33CULL, 0xACB6FD933096AC82ULL, 0x4CB21A8B483D078AULL, 
            0x638DED748B5F29E5ULL, 0x037211B8389D119CULL, 0x67894222CFB92BBDULL, 0xE2E98C436D1070BAULL, 
            0x63C7664E737793EBULL, 0x9725491CCD93DE15ULL, 0x170EFFEDA634BB69ULL, 0xEC4EBAF5D2C4DE79ULL, 
            0xC6C1CED355142ABFULL, 0xC0CE45E38B8E1F45ULL, 0x3CD3AF026F14695AULL, 0x76AA43AACDC5EE97ULL, 
            0xCB4AAE2EB0EA0CD0ULL, 0x9DCC89BE8A35E826ULL, 0x31CD20FCEDEFAEA7ULL, 0x5D38F2372267DC65ULL
        },
        {
            0x5DD7F51AD4413A04ULL, 0x8095B7984C81C617ULL, 0xF56539B6F2486814ULL, 0xE95844357F496D14ULL, 
            0x41A12553A6154456ULL, 0x728D6F332F1C7863ULL, 0x459FCCA06BCB3FDDULL, 0x484754BD838BF3F3ULL, 
            0xEC3C3B4DBC31953BULL, 0xDEC828322315A254ULL, 0x9FBFD6D77F222382ULL, 0x52F05EAE0D9DFFD5ULL, 
            0x3B0DD405059951A7ULL, 0x17884F879D16CC2FULL, 0xEE9C9AD0164F7697ULL, 0x3F0B53E541A7BFE3ULL, 
            0x0B2F5F864C81353AULL, 0x7F4951C270762A1BULL, 0x7D3E76EF03864027ULL, 0x53747611CA97A043ULL, 
            0xD8D5A02920AC6DD4ULL, 0xCF3212417B2B9611ULL, 0xEBD552B28CF31113ULL, 0xA1DECB489BB3189FULL, 
            0x199E691F18F7D056ULL, 0x44343F84F61B37DCULL, 0xCEECB30116E42F7AULL, 0xE86921E87A51074DULL, 
            0xB1254BE57578DEC1ULL, 0xC132C07777F3860EULL, 0x0DFAC73F696BD059ULL, 0x689249AE3CA88788ULL
        },
        {
            0xD939BE7AD4D91063ULL, 0x2B2CE8FD0337166FULL, 0x7B3D4AFDE0E3F518ULL, 0xD9744AD15F7BAFE7ULL, 
            0xC5BF10CD1BAF0E02ULL, 0x710BA0DBB529B049ULL, 0x760CE71202500A99ULL, 0x08E494CDDECB24ABULL, 
            0x1A3F341D51ACC3DDULL, 0x91950551A85A1662ULL, 0x21436793481A0C32ULL, 0x848F365502EC9355ULL, 
            0xEB15DF4CF2C1F2EBULL, 0x5698BFF5B7D39F5CULL, 0x4D06E73B1A1A56C8ULL, 0xD523542F2AD67112ULL, 
            0x55B4E0FBB4EF2340ULL, 0x70DAD7C382383D2BULL, 0x2306B91C13839B5BULL, 0x108E7397393D574EULL, 
            0xA4025349216B33BEULL, 0x4F17802D46D9CA97ULL, 0xD3BB09B23D73E1DEULL, 0xC0488ACCD3384D89ULL, 
            0x11104932B5DC1817ULL, 0x1546D4DFF746B7B7ULL, 0xE4C5BAE95F3169C0ULL, 0x30E1D1E06F65CB63ULL, 
            0x7716375D7B38D21DULL, 0xFEFF1E0C7448BF63ULL, 0x08051839B8A2565FULL, 0xA8EC32CD2C091D47ULL
        },
        {
            0xC35005A76CD7212FULL, 0x8189C9C435C39C2AULL, 0x3E3D36EFBBE512B6ULL, 0x76860E2D6B59E2EFULL, 
            0xB47F5689B2003E00ULL, 0xE054CB07B8B7CE9FULL, 0x3BD616E428A04519ULL, 0x20DB53604BC28F99ULL, 
            0xC629285CEFE0639BULL, 0xA2FCE11C9B35D46CULL, 0x71B5D74EBEBE3352ULL, 0x3E7AB720A6730F83ULL, 
            0x6A962672F61F0763ULL, 0xC9092A2341A2417EULL, 0x3E29992CDCB76E4CULL, 0x0F15B084541D1F1BULL, 
            0x22940993FEBCCCEAULL, 0x31BB1FF6FC7D99A6ULL, 0xB46AA84453CA111FULL, 0xC537A84774514F82ULL, 
            0xC86A15160867B4A8ULL, 0x5FD666DC6BEE5D3DULL, 0x1B38304E5383A374ULL, 0xB5FBBA631AD5E76DULL, 
            0x6A626C6462E68C0CULL, 0x62E05FCD500286F2ULL, 0xB9B9FD5A59943F3DULL, 0xCDC905338E74FA1BULL, 
            0x32BFF63C1090E33BULL, 0x72C08564D270ACE6ULL, 0xA80BE7FE43959227ULL, 0x32114CA6D7B20F9CULL
        }
    },
    {
        {
            0xCC322D679BA90AE2ULL, 0x648AE0648CDE5CDFULL, 0x3A8213132D7822B7ULL, 0x7B9CBA52A3DF6A8EULL, 
            0x7972D8BD7C88B73FULL, 0xA68A2265FA191016ULL, 0x3A1BF5157BEBF14FULL, 0x0EFD588AC9E49CEDULL, 
            0xB242D4BBB2AB9C2DULL, 0xD590BE58F6110D36ULL, 0xACD0C3A22785CC41ULL, 0x829BF2EDDCC9604BULL, 
            0xE80B035305B19C52ULL, 0x2D7BBB2E910CDA3AULL, 0x99B2750F66E3F66EULL, 0x93609DA700C425FEULL, 
            0xC4E8EEA8B64E18FCULL, 0xAC3B01EF57BA35D3ULL, 0x09A85AC1CA8EFC82ULL, 0x52FAB6763E0BF823ULL, 
            0xF41F99D14FACABCBULL, 0xAB851448028AEF33ULL, 0xFA8CA21E2769F4FBULL, 0xF3520BEBE5B770BFULL, 
            0x1CCB877F5AD2E6AEULL, 0x124C02994ADDB275ULL, 0x832CFD7C3FDA2419ULL, 0x86A341322C8F9AD1ULL, 
            0xA8B698FC5560B9CFULL, 0x74EAB493045DE40CULL, 0x27232C455EF2C9BCULL, 0xDF917DE649C09C30ULL
        },
        {
            0xD6F1D600847B93E9ULL, 0x33701E25EE440440ULL, 0xB4FADBC8013A4013ULL, 0x08FD5B4D83A3DEADULL, 
            0xA048518BBB80AB0BULL, 0x2792D8FCC88F325FULL, 0x32F745E72F11C907ULL, 0xDDC54A72E44B46DAULL, 
            0x5CE9F5FD64BEA849ULL, 0x653C669F161F3BB0ULL, 0xA097E07804334BDEULL, 0x9E637B9E7EE1C61EULL, 
            0xB47FDDE67A17D26BULL, 0xDDA458021E877CE9ULL, 0x04D160F7A444BB6CULL, 0xEE57CE17ED4000F7ULL, 
            0x4A693D22E96942CAULL, 0x00E77A74A324D9DBULL, 0xA9B84DD32E771C33ULL, 0x410D66712CEFA874ULL, 
            0xF5EE02C777A0595DULL, 0xA71A9A66FCB27169ULL, 0xEA08E94A1E1B1789ULL, 0x94A0827624F2D7CBULL, 
            0x0DB7ADC9173040E8ULL, 0x78E4B9DF9F663E5AULL, 0x73C22C859E3CF66CULL, 0x9594E38B34DB7B03ULL, 
            0xE12B2FCEA9CF4A1BULL, 0xE175BBA0DDD76EFAULL, 0xA0ACF0A5298D889DULL, 0x12B441E1D0974E40ULL
        },
        {
            0x06A0C5735ACF0800ULL, 0x2F009B07212271D8ULL, 0x07B646D27580FD69ULL, 0xD342460C784C768EULL, 
            0xEC06B5F5F678C7E9ULL, 0x2A920D488954AC91ULL, 0x9CA24C4DBBA267A1ULL, 0xB08C0D03CF903D1EULL, 
            0x97CDE0F062DD21A4ULL, 0xD34B5AB6EC8C9405ULL, 0xE487BC4C4BE9B4CCULL, 0x2049805196C30E92ULL, 
            0x9B4C3CA1F184B6D9ULL, 0xAB0BD613F0FCD375ULL, 0x6C05C37FFD9563B8ULL, 0x4B73EC9E2985F8D6ULL, 
            0xE4D534DE9352EF1CULL, 0x48754485CDADCCE1ULL, 0x384E40C13CA1DC5EULL, 0x73BAE9B4C6A281C4ULL, 
            0xD2B9B2DB5C4418ECULL, 0x059E94A736C0D9C6ULL, 0xDB33420254C674F9ULL, 0xC4793BC97EA6BFA4ULL, 
            0x751DA5C1D04C2B17ULL, 0xC6AC92ACF7D0C470ULL, 0xA0D39F03B0DEB3BCULL, 0xDCE5FA5C766E826DULL, 
            0xCAEADF8E8999D3DBULL, 0x4F63D195D62662DFULL, 0x3A0F7AAC745B8278ULL, 0xDFF07D11A4E413CDULL
        },
        {
            0x052AEBE2943CBD5AULL, 0x04C4C01F1F2AFBBDULL, 0x11EB3A9A516C0A5AULL, 0x7D7E3E2C9B59CE79ULL, 
            0x7B6A3C87F62BBA4BULL, 0x8951C067D88D1EC0ULL, 0xF57C54DBEA458714ULL, 0x4ED83D3525B58541ULL, 
            0x02D4B4D8F9868E34ULL, 0xF2312B3C8407B1F3ULL, 0x071F43368BFC852AULL, 0xA4DB6511C1EB91E0ULL, 
            0xEA3131CA43936ED7ULL, 0x77BF929A6F56FFAFULL, 0x388012DD57D72C2CULL, 0x53041BD87416701BULL, 
            0x2BF24E6B936CADFCULL, 0x348CC9BC8973D21BULL, 0x4F1E552919964B01ULL, 0xCC9C946EEDC66428ULL, 
            0x6D033F8BB841B8D1ULL, 0xD2F2B6DFD75CF820ULL, 0x3921D2EBEF5C51FDULL, 0x4373F97DF95DDB0BULL, 
            0x3611E2C7A40DE93CULL, 0x0DA74257AC1558C7ULL, 0xBDD0517A5CCA40F6ULL, 0xAB69BA93BFE1D9EBULL, 
            0xAF4349C2F5C78AEDULL, 0x329FC7A7E180D537ULL, 0x5B4782895A16BE39ULL, 0xE960846DEBE5C475ULL
        },
        {
            0x9DE9A9EC11FF6774ULL, 0xA6E66DCBB382B6F2ULL, 0xCBA2E1272BB7E6CEULL, 0xC2E92E5C13891F46ULL, 
            0x045A7CFC0649559BULL, 0x7AA32812B4EA26FCULL, 0x6F6BFA97E35BF6BFULL, 0xDE941B56C9DA88D6ULL, 
            0xE3E9BF678291D557ULL, 0x1F812C8197DEF9DDULL, 0xBD1236ABE353726CULL, 0x1DE39D823F565891ULL, 
            0xCB0E36D2B52EE062ULL, 0x6091538D2EEB827BULL, 0xF5034160BA11286AULL, 0xDE575A655482E316ULL, 
            0x3359B09F7716ECCCULL, 0x6CA1855510CD3210ULL, 0xB48223500535AA57ULL, 0x81665E16E9395F5AULL, 
            0xC555A35AC3565FCAULL, 0x53C7F68A06700EFAULL, 0x22211A660EE06E34ULL, 0xE72AD8C8AFEEADF4ULL, 
            0xE4066B13E729CA6DULL, 0xA7C72338597CEC1CULL, 0xB4170A512F2BF8BAULL, 0xABB5485315D0DFB4ULL, 
            0x01E07318C6F6EB07ULL, 0xE1F8E2ECCD9ABF2CULL, 0x09FDFC033D71A679ULL, 0xC19365ECA17D04E4ULL
        },
        {
            0x590C4CC1FDCE89AFULL, 0xDB0857A9BA84E2FBULL, 0xEB4EA4A6BDD5F84EULL, 0x26742FE885787441ULL, 
            0xAB6A1A8D64892597ULL, 0x7434EFF8706A0608ULL, 0xF2094E3102ECB4A3ULL, 0x13A8FCE980418990ULL, 
            0x0CF5ED16F7F55C8EULL, 0x2FC2DAB966B015EDULL, 0xC90E923EE7F37F95ULL, 0x2162BF1E20B06933ULL, 
            0xBC89FCCA4EA8CC25ULL, 0x954ECDF4396E524EULL, 0x12C24CE0FB8F0A6EULL, 0x2F799FDE5299280BULL, 
            0xA4F4259184E51CDBULL, 0xB8B07359E12551BBULL, 0xDD966215265E6317ULL, 0x02776C2E4C118C90ULL, 
            0xE6D6ADE04D89B765ULL, 0x92A6677688191EBCULL, 0x6206B73763443BDBULL, 0x045B8DA8CCB315A1ULL, 
            0x0FF1CAD646B2691BULL, 0xEEA140CADA841A7DULL, 0x69B01BE31982AB7EULL, 0x07637FC92C3A83FFULL, 
            0xF05C6CE66974AA29ULL, 0x3720F4A850A6294AULL, 0x4FDAB14CC65B8868ULL, 0x214859144D5FA35CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseDConstants = {
    0x5B836D9A40828984ULL,
    0x93747448A9E1B061ULL,
    0x434D52B74A624B3BULL,
    0x5B836D9A40828984ULL,
    0x93747448A9E1B061ULL,
    0x434D52B74A624B3BULL,
    0x6F94164A2959A2D3ULL,
    0x4A3995C98BD5DEA2ULL,
    0x91,
    0x58,
    0x4B,
    0xA2,
    0x58,
    0xDC,
    0x33,
    0x23
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseESalts = {
    {
        {
            0x76A96721B2D110B3ULL, 0x5A2180AF1FB24F58ULL, 0x34C7E697F609B820ULL, 0x571460BEC3BAD798ULL, 
            0x9EFDE5B2F47D054AULL, 0xF75324D99A9CA09AULL, 0x597B8CD65B363E6EULL, 0xF64EC461D2948C8CULL, 
            0xB4956A625E5A11F0ULL, 0xED75BDEE4BD5DBEBULL, 0x85FA85CE9F98ACB3ULL, 0x294398ECB27185FFULL, 
            0x30143ABA1E3B10B3ULL, 0xC732650C8CFB68CBULL, 0x1B121882D9865EBAULL, 0x4A57C042F44F0BDEULL, 
            0x6390D0FCCC3BB373ULL, 0x8303EECBCB55B863ULL, 0x96561E8BA050CABDULL, 0xC97B77E0EBEF0773ULL, 
            0xD99095BD45BD6993ULL, 0xDF985C2E9D8CE1F4ULL, 0x55557CF2C07E02D4ULL, 0x425E45FEB7D92F67ULL, 
            0x11854B1C3BC217ACULL, 0x65FB01EFA1BA5B03ULL, 0xC7DC5345221A6B91ULL, 0x886E9CD2241657F6ULL, 
            0x0024921781EB6542ULL, 0x591911FEC28CE58DULL, 0xC0FE6CEC40C8BAE1ULL, 0xCBC3BFCDB0162B02ULL
        },
        {
            0x2963444E92F32B7AULL, 0x1F273C62882C3CF1ULL, 0x14643978B4438B57ULL, 0x5C3C38DDA9D58C7DULL, 
            0x98C3BD5BCE36FD71ULL, 0x9C9511A347BB7327ULL, 0xD0CC836BDC999D0EULL, 0xFE1781EE4C37A8E8ULL, 
            0x98DBCA4BDA088909ULL, 0x6772A5845D2061EDULL, 0xC90DF4BD90A81B12ULL, 0xE30F95B263FE3C6CULL, 
            0x5EAD0EA6C0FB7BD1ULL, 0x32522D82D754A1DAULL, 0x48144F1E1A210CA2ULL, 0xFDEAEC20F3E55C16ULL, 
            0x573FB874B4070049ULL, 0x2411AF96391FBAA1ULL, 0x8923F2BF558C6F8EULL, 0x0A3F331C62FEEE19ULL, 
            0x0390DFB9611FF168ULL, 0x26248C6BE25C56B1ULL, 0xBB5DF17BC6BB37E3ULL, 0x7E320F57F185B94BULL, 
            0xCDA48AEC871AA1CAULL, 0xB7C66F1D8C85967CULL, 0x2F8653BB6F8275E7ULL, 0x1C87742D9F2C5D19ULL, 
            0x16138ECF5C39DB78ULL, 0x38E4AA018B1EB52EULL, 0x1F060D977CC9065BULL, 0x3C3D9082ACA90DE3ULL
        },
        {
            0x55F42F2920D9A3F3ULL, 0x86DBBF7CF8605534ULL, 0xB3795FBC336AAE28ULL, 0xD5CED18D12635987ULL, 
            0xB083CEEED2FB5C7CULL, 0x50FC878FB23F94CFULL, 0xDACE3A4C78389C7BULL, 0xB8CE64ECB0DBB563ULL, 
            0xDC8C046A3E0D2A4AULL, 0xADBE9E0407E2F813ULL, 0x12BE6A65F0087B65ULL, 0x5F01BFF0877F63E5ULL, 
            0x223CFD47D65EF423ULL, 0x5EC602E558536E0FULL, 0x8EEAC4566EBB04AEULL, 0xC938308562E7D14CULL, 
            0xC9E39B94A37D19E3ULL, 0xF375C140A16E3F2AULL, 0xD5084F8874EE1AF3ULL, 0x94DD651AB6DAE487ULL, 
            0x0FCDB31F2F79BF87ULL, 0xB4C7F208F85B0578ULL, 0x0CDDE91B9308185AULL, 0xAD9190BF986D88C1ULL, 
            0x41CEADB0F7CD2DF6ULL, 0x7E99B1FA4CD9510DULL, 0xEDDB3F801D9BE1C6ULL, 0xD8CF0D96BB3B84ADULL, 
            0x44AF5F13D12A16B1ULL, 0xFC6FD6E0F2A3CABCULL, 0x0E43134ABF8B6876ULL, 0x629A4945B628F44CULL
        },
        {
            0xC919608FC3FA6BA3ULL, 0x049D2D30D1865FCEULL, 0x6C5FCB0D71E3E934ULL, 0x0111996CAFBEACEAULL, 
            0x4BE365D61B5D8DD2ULL, 0xBB1ACA1E45A0A058ULL, 0x1F963C4F525D7419ULL, 0x5B10930A46490C8DULL, 
            0xCF3909D4D101926BULL, 0x208BE42A8580236DULL, 0xD94BEF6DFC2164CEULL, 0x3198EC1495333B96ULL, 
            0x8C58AC627C7048FBULL, 0x0823CDD9DA33848DULL, 0x12664E1478CE6146ULL, 0xE00DEBCCFA4A8969ULL, 
            0xA6B6CCD9E26AAF25ULL, 0xE5EECC1CF080CA11ULL, 0x1CCE8476A07C4C9BULL, 0xA4D0CFF671134CE7ULL, 
            0x4405ED7DD08FC078ULL, 0x0B7BFBB218962859ULL, 0x88B121E1DA6D066CULL, 0x87641AF8C2BC46C9ULL, 
            0x8E0554A940C3C568ULL, 0xD8144D8DEE2FB83FULL, 0xD7BFADE1E1603B9FULL, 0x8A86A6570D37800CULL, 
            0x8F6AE8FD29689F0EULL, 0xCDE3E1ADCAD300B1ULL, 0xED11C04E563CD79CULL, 0x6C56818B6BB0205BULL
        },
        {
            0xDA4A4D0202A53B5DULL, 0x05146EFB63F0B59EULL, 0x09BACD7DCACEC93EULL, 0x92BA28B8AFB3724EULL, 
            0x80B545B901E8EC18ULL, 0xFB4FA75AEE36B444ULL, 0x1DFAD5741E72AF15ULL, 0x8F5BAAFA5BD3D65EULL, 
            0xE44FD6C30FB65AE1ULL, 0xB61FF7A0F8CE7B75ULL, 0xEBB0A0AC9EABF0EAULL, 0xC1A2D9801F5E79FBULL, 
            0xDF6859C3759FF5D5ULL, 0x1E6DD29124B8D1D9ULL, 0x34BC1806B1301975ULL, 0x7A124EB5AF07C0D2ULL, 
            0x7F98689C9AA0C0A6ULL, 0x0CFA91E145A43A8AULL, 0xC01EDF8243876359ULL, 0xF373CAC82AE8EAABULL, 
            0xE53E6300DF691F45ULL, 0x2093B667F2973F82ULL, 0x6DC92F249A180AC6ULL, 0xB03418DFF7287D10ULL, 
            0xD3996669E06DAAFAULL, 0xBD57D2D056431BEAULL, 0xDF6972F428811C15ULL, 0xCB6E54BFDF151107ULL, 
            0x42A21700909E26F9ULL, 0x59AAD97240625E06ULL, 0xB3EB989F8CCDFB1EULL, 0xCA11BA108D8F415DULL
        },
        {
            0x6CDD3D7CB6B9270EULL, 0x76E4D09E68367338ULL, 0xF8F7A3EF8A8E071BULL, 0x4F9CBD18360F87EFULL, 
            0x6DF4DC1FD0BBB911ULL, 0xF5D2FFB5D1939E0CULL, 0xB33546C7C8278AA6ULL, 0x795472156A57C178ULL, 
            0x6A94E63E633888A2ULL, 0x12F1587D5F6672B1ULL, 0x214C0F489BA61CE2ULL, 0xE2C44F275F10A6E7ULL, 
            0x0321D7EB64062455ULL, 0xD99863F09C2DC145ULL, 0xBD53229ACF52642DULL, 0xB937FB20DC6B21B7ULL, 
            0x689831ADF17E303BULL, 0xC7040AFE00062C32ULL, 0xDE42A1EF87D26966ULL, 0x9FF6BE895A20F574ULL, 
            0x6EFDE758F9B6DE5BULL, 0xF4473D7A6BC2FD16ULL, 0xE04C6D852120F0C7ULL, 0xC2491FC3634E3DAEULL, 
            0x390670718869BEC0ULL, 0xA2AF80267EB012E0ULL, 0x1791D128BBAA11E7ULL, 0x3229AA26C2194F0BULL, 
            0xEFA8195050B70C13ULL, 0x1CE58EB86548B86DULL, 0xDCDB124AF2F84D81ULL, 0x92EB57A15992F6C4ULL
        }
    },
    {
        {
            0x912450677B7ABC7EULL, 0x0590EBDF715B05B0ULL, 0x18298FB2DF674319ULL, 0xC04466CD42EE3510ULL, 
            0x3D498A5935E6D85CULL, 0x84A208CD8959331DULL, 0x7249803165D6B086ULL, 0xCADEA5CB98607D0FULL, 
            0xF19C7EE5C48CB4D1ULL, 0x6AC366B73D1776BBULL, 0x9602E49F004C9BE7ULL, 0xA9D014DD535AA8F4ULL, 
            0xB4741B3215E462B6ULL, 0x5F43ABDBEB38300AULL, 0xE02840253AD0F04CULL, 0x0D26183CA9AF5CD4ULL, 
            0xE18907D864BE7AD9ULL, 0x6DD3CAC79CB4342BULL, 0x988ACAB1ABCC1C48ULL, 0x2303C1925225D807ULL, 
            0xB67938202B1108F8ULL, 0x45D903956276D322ULL, 0x4716C73EC90D6486ULL, 0xC4237C506251C2BDULL, 
            0xA41AE2129C311AA5ULL, 0xE0D22E2C1DDC315EULL, 0xAE5D41E64E9D3938ULL, 0x2FD0C1DFE647EA55ULL, 
            0x9D99712A0B83F18EULL, 0xB9C4D7BD7E40AF28ULL, 0xB3815DF932636DD8ULL, 0xB3E7AE7A03621898ULL
        },
        {
            0x3315740A2A4F4CF2ULL, 0xC2F24B98680F0DCFULL, 0x4634BC982E236AB0ULL, 0x1ED46877ADF9C3BCULL, 
            0xDCCA0894DD8BB1A9ULL, 0x415244AB40CF9BFDULL, 0x92F6632740059555ULL, 0x37433500D8FD2CC2ULL, 
            0x49950055D47EC3A8ULL, 0xECFDD05E75FFD7D6ULL, 0xC54517EF82C2D71EULL, 0x758BDE2496800E62ULL, 
            0x930EE49F13A5BD4DULL, 0xC400E78C5975C19EULL, 0xA2F057D486D7F8C5ULL, 0x38BA66776444EEB5ULL, 
            0x4BD154051F6179C3ULL, 0x95D5155D260F5E63ULL, 0x008D78D4598CFE4BULL, 0xA8575EF4089893CAULL, 
            0x612D0D060C1C387DULL, 0x3C3019C2B1AF01D6ULL, 0x95CBFF60BF07E924ULL, 0xD146A47C6FD4961BULL, 
            0x58DB04F33D03C99AULL, 0x403D3DF61C950906ULL, 0xB49F70C4B62B7574ULL, 0x941A91D92645B634ULL, 
            0x00586C1C20596A47ULL, 0x070626A2CED0E64FULL, 0xD5DCFDD89585CDB5ULL, 0xB0DBE839D067627CULL
        },
        {
            0x78DC9218B57A3D86ULL, 0x718D628776B18A16ULL, 0xB9BE0CE37D61D861ULL, 0xC0A259D721D098D1ULL, 
            0x583A6CA7CE5433D9ULL, 0x7A48FB90A437689DULL, 0x46018A46A2DA684CULL, 0x2193E4B9A1A6F0D0ULL, 
            0x95679EB035460C34ULL, 0xA7975E3AB954681CULL, 0x1706AE0C1F66D6B6ULL, 0xD9211CA8547FE0E2ULL, 
            0xC972369818A26119ULL, 0x6CF4B86C9319266BULL, 0xF9B2DB7A9998C3DDULL, 0x4AD3A2D926AED383ULL, 
            0x8B26792BD6BA13F4ULL, 0xE09AB10A83B1B278ULL, 0xBEF6402EA52D92DBULL, 0x7D0915EF5A40328DULL, 
            0xE957AA5692FBC2A8ULL, 0x37512BE895959A6EULL, 0xAA10DCF16FCFABE8ULL, 0x136FE708FEBC301BULL, 
            0x4A723154EC729F6EULL, 0xD2168093BC755B77ULL, 0xAAEEB46E10A75AC3ULL, 0xC576DE032FC41DEAULL, 
            0x5EA7BA49E9CE2B9CULL, 0x4C41CB5C88DBB621ULL, 0xD16EFAA2C90026B6ULL, 0x1BAA43E956ABEA87ULL
        },
        {
            0xDF719772019740A8ULL, 0x27604B2D3E4AC803ULL, 0x2422BB2A011A5D86ULL, 0x22E60BE048DAA429ULL, 
            0x7F647DC6A044C21EULL, 0xE3E8D77120C28BD6ULL, 0xB53DDA13A6B9C8ACULL, 0x6C22654840683354ULL, 
            0x279A2AC732AA99A7ULL, 0x15C52CAF8BCAB8BFULL, 0xE9A83C2F3B9A8F06ULL, 0xC50D06CA58E38FD2ULL, 
            0x9DC5E887A9F9F6DCULL, 0xE56694A8584F7F3CULL, 0x40CBDB9FD3DA4FCDULL, 0xA30BF8D057769818ULL, 
            0x898A78747CB35749ULL, 0xC98AEDF63C8B3E5FULL, 0x645611CAE4D0B1D7ULL, 0x45BD27988FBF5F53ULL, 
            0xEBD41456E62FC8F1ULL, 0x04F7513657F0AF37ULL, 0x9294B94198A96123ULL, 0xA13FAFAA6F0E39F7ULL, 
            0xC1A74AF52B2196BDULL, 0xFBCD7E354AC9FC76ULL, 0x44AA0D1F900BB98DULL, 0x56E256AEB075E86AULL, 
            0xCAA2FC4205ACF506ULL, 0xE86892FDD60778C9ULL, 0x33E15EDE33FA588EULL, 0x99D753A608411F60ULL
        },
        {
            0xA1234563BDFCC345ULL, 0xDECB6DDA800472A4ULL, 0x089DADE00D5F7E97ULL, 0xCA9172DB673B7AA8ULL, 
            0xE753D4031F4289A0ULL, 0xBD7691A3C03A80F3ULL, 0xB5CF2DEE231C6D66ULL, 0xEAFC2A8761C2D289ULL, 
            0xDC0CFDD4CD6A2902ULL, 0xD7764214C7D4DF51ULL, 0x5A1BD6CB1B753453ULL, 0x50BE9CED5743DBECULL, 
            0xFC1BBD47CD79BFF8ULL, 0xC4EB8E53327F43F2ULL, 0x7A1499308A37D959ULL, 0xB1B3994EB1AD70E4ULL, 
            0x9FCF863868590D52ULL, 0x90D56DB0526B830DULL, 0x8441B4336F71E01FULL, 0xFB38F4EA54B53DA7ULL, 
            0x45E179A46F88EAC8ULL, 0x3C27E145E5BBA0ACULL, 0x3485A21373285DB0ULL, 0x77EE583C0F1AF8A9ULL, 
            0x5E4E1C563CAA6AB1ULL, 0xB40EFBA2FAAA83F6ULL, 0x433FD54EC5FA934FULL, 0x26E873165445537AULL, 
            0xBB8AF93902308FE4ULL, 0x3F13ED3F6B8AE219ULL, 0x2C8A35303E3D778DULL, 0x836ECB363B940486ULL
        },
        {
            0x459571105824C966ULL, 0x16954E73B5155E23ULL, 0xDFEC3DE66481088CULL, 0xADC10CE0A0132BE5ULL, 
            0x565BA3A2EB26F13DULL, 0xCE995F6BE81E298AULL, 0x151393F6F6A6C8CEULL, 0xA4A746AB1A15B196ULL, 
            0x7D23510A903AA76AULL, 0x62F98C0AACA1B4ADULL, 0xE0D4041040C79059ULL, 0x326A31AEE773899DULL, 
            0xD6D99E2D27D393B7ULL, 0x7E6B40382593D3DCULL, 0x9CA2440158FF6196ULL, 0x4A9E3109DF70F260ULL, 
            0xA90C977FC9918329ULL, 0x887A42781EBE71F8ULL, 0x5E1BC2A6EAD40936ULL, 0x223117520128C688ULL, 
            0x0632CC3A43268565ULL, 0x441133C147D79BDCULL, 0xB3907A7A6C147AFBULL, 0x7FE0F7A929BD181DULL, 
            0x2BB2E8EE3FFD2C69ULL, 0x4B72E8BDF98069FAULL, 0x3FEE8B180C7B0BEDULL, 0x88A497E67AEA0694ULL, 
            0x4B54A69357891D6EULL, 0x805235D891F2D991ULL, 0x0CACAB55374887FCULL, 0xB588F7E527F0E8E3ULL
        }
    },
    {
        {
            0xC0C4072936975B87ULL, 0xEE65595FA061A1DFULL, 0x6BC3295741119ED4ULL, 0x9A6E634C98A48FA9ULL, 
            0xAA8C6F4B7D06E514ULL, 0x075A73CD5F50AD5CULL, 0x6CD759F0F9FB63C1ULL, 0x5F931A3B62861FF2ULL, 
            0xB42B7A1CE287D78BULL, 0x21F1618249338F01ULL, 0xBC4A60A9C8553D91ULL, 0x7E6CBFA2FE1DBDFEULL, 
            0x032EB3B32B1E0FF9ULL, 0xDA100BD756D42F45ULL, 0x184367DF5DBBA727ULL, 0x1C48D5E3DA433FDBULL, 
            0xC8CCA6826783E955ULL, 0xBB8A1F658147DC9BULL, 0xE346C4C8D2D0BB10ULL, 0x743237A6920AF68EULL, 
            0xB3E54881BBC4B108ULL, 0x556899DAB32921B5ULL, 0xE42C1F0C02D88172ULL, 0xB59EC5A168832293ULL, 
            0xD3D8401B461712A7ULL, 0xC2417E39C5D1C75CULL, 0x84D19EF08E6637CAULL, 0xB2C8DDCEF1ECA32BULL, 
            0x2FD56BB1F2B451C9ULL, 0x76326CC8F15E67F0ULL, 0x52645FFBF9EA5DEAULL, 0xDC79033921F6604EULL
        },
        {
            0x20CCE802DACFC60AULL, 0xEA0EB13C2165C380ULL, 0xE2EA5BC96430F5F3ULL, 0xAE3F46556CDF8D2FULL, 
            0xADE0A3F6C01F84BCULL, 0x0B2E26F235FBF500ULL, 0x697C3ACF0CAE0D9BULL, 0xDFC38BCCBF2EF16FULL, 
            0x93C76274B45B2E32ULL, 0xDE075DCA63E0796EULL, 0xE79FCCEB8B0B6A9DULL, 0x8DD04C57D919CD02ULL, 
            0x3AE23374DE2645B7ULL, 0xEB7B1401733C6BD0ULL, 0xC66C84BE5B50EA71ULL, 0x80F64BF907120BEDULL, 
            0x40A65FBECE04BB66ULL, 0x09493150CF84B351ULL, 0xD883DCF1EB80E1C7ULL, 0x1AA213E00C916E85ULL, 
            0xBFEB0AEF80BBCAD5ULL, 0x03724316D7E40AB7ULL, 0x06D8DCB57C85C66DULL, 0x9DA438488B681D14ULL, 
            0x76BC043F0C969093ULL, 0x920DD14A78041149ULL, 0x7D82160972E363F3ULL, 0x3064E551B1A6B16CULL, 
            0xCD7C248C73BA1C0BULL, 0xEB1BC5AC906E71DBULL, 0x203678955285EDADULL, 0x1329F6BF529C28E8ULL
        },
        {
            0x59062A476F1CD3B1ULL, 0xCF5A2DF6A999BE60ULL, 0x5E63A7B8C51AEF24ULL, 0x587E0990A97FED2FULL, 
            0x518E023822D0DE2FULL, 0x6F969F3E97D27034ULL, 0x486E73AE9885A4D1ULL, 0x8460C34769A66383ULL, 
            0xE22CFE6B69AB418DULL, 0x4FD9C1641D39D74DULL, 0x64FEE382AAC74C52ULL, 0xA07AA3BE0B00FEBCULL, 
            0x5A6FFAE029210361ULL, 0x463C02E7816E28ACULL, 0x5202FA0E0894FFA4ULL, 0x8C11B2B1604A45EFULL, 
            0xDEB720CC5B29803DULL, 0xE3DB8D4D34DFA2EFULL, 0x0BCCB992D5795FE8ULL, 0x6D89559179DF4790ULL, 
            0xAAE8089B30B2F4D4ULL, 0x584382C970802DE3ULL, 0xCFCF27B63FD3486BULL, 0xF262DF778161BF13ULL, 
            0xEB8CBFB01A600764ULL, 0xD9A702E9AC47F9F3ULL, 0xD6B49EC4E54C37C2ULL, 0x48BB197AE9708392ULL, 
            0xE1A6A60D36BFEFCBULL, 0xF85710DF68B9D7A3ULL, 0x56A7CD4B94912E58ULL, 0x726E8987094D49D3ULL
        },
        {
            0x5E5F66B37BC8AA65ULL, 0x9DE36A46D18957EFULL, 0x5C1DD75567D3F047ULL, 0xCCE258757C6CC2EEULL, 
            0x67ADE6AD2D91A4ABULL, 0xE8DAFACA457B7A3AULL, 0x58A3A0CDAD0D1D84ULL, 0xF50CEB832F000A1FULL, 
            0x0A17CAF4814019AEULL, 0x0650F08D5D80C2A5ULL, 0xA826FE64DDD25F38ULL, 0x62D53442B3E8B04EULL, 
            0x9110C456988F866CULL, 0x9A5B93D7BA9CD039ULL, 0x63A53D9AB466AF06ULL, 0x5F48E4DF6A832E04ULL, 
            0xAB6F4F40E740F578ULL, 0xE1395E56FD42FF0DULL, 0x57E473AF3C9FB455ULL, 0x023DC18FC5619B88ULL, 
            0xDF59D2E6D623F167ULL, 0xC6A0F8C6E72F8C1CULL, 0xA91DF700EFAA7327ULL, 0x652EBAE658B6C879ULL, 
            0xD99A7E717F16E021ULL, 0x640E9283A77B6A1FULL, 0xCCBEAF1CF67CB2C6ULL, 0xBFD800BEA57937B6ULL, 
            0x493EB2ACBD5D1573ULL, 0x4E2FFD9930BD23AEULL, 0x5E71566BC2174AF5ULL, 0x6EA457E587C30C86ULL
        },
        {
            0x6D2B75D854F0CBA4ULL, 0x2C4F0327E9B37C30ULL, 0x35C36E5DE2D2AE63ULL, 0x79A396DE0910999DULL, 
            0xD9DBD4DBCB798FECULL, 0xC1B4A75B5B02E8D4ULL, 0xA1BEA5675D3CB94AULL, 0x915B4FA524CE239CULL, 
            0x9346A5F5F8230DB3ULL, 0x5E0D7EDFB273C5DDULL, 0x0225375925C243CFULL, 0xF5058BDF88764C1AULL, 
            0x19E4649C9D759FDBULL, 0x5CE8A3FA1066715AULL, 0xB1260FCC984AD8CCULL, 0xDF8A39A5991D705FULL, 
            0x07CB002716A8EF57ULL, 0x81C10EF3D4A672CFULL, 0x3AFCCCDB8070BA99ULL, 0x8CE24ADEA028797DULL, 
            0xD9E6A3933DB3D4FFULL, 0x89CEDD62E1F720B6ULL, 0x2E69BC823A169FE1ULL, 0xC8640597AD6040E1ULL, 
            0xE0832573C2FBE43FULL, 0xE45B13C13D423A7EULL, 0x01C2289FA9FB0648ULL, 0x721188EF535B63F3ULL, 
            0x2815CED4AFF56CB7ULL, 0x9079E56BD7EEB589ULL, 0xD94ACD46ABB8341AULL, 0x4D7B0B07626A4408ULL
        },
        {
            0xAA12FBC2915ADAD3ULL, 0x991D2DD9188D1EFCULL, 0x209A7A102DDA0AB5ULL, 0x94475BCB08CC6B8DULL, 
            0x3C7EA5558C8AA36EULL, 0xEABF08D345ED4659ULL, 0x6DA135E07F7660E6ULL, 0xE163C0CF5D7FE26AULL, 
            0x54C9B5DF8C812D9BULL, 0x1A9990437F6FBDE0ULL, 0x06988B1845DC18FCULL, 0x2D6F88B24AEDF56FULL, 
            0x95C48C98C677111DULL, 0x73D895D7F19471F8ULL, 0x773407A16FDB1F38ULL, 0xCA050C4596BE9D5CULL, 
            0x035385B2C0EDB0BCULL, 0x87CD44E34AD278CEULL, 0xE944E5E102ED694AULL, 0x6BAFDAD69B47B2A1ULL, 
            0x99F6DB7EFE6D386EULL, 0x0B9B01FAEC792574ULL, 0x34DA13AB5F6A1A0EULL, 0xE3E9D114B808AF63ULL, 
            0x6D6FE5CCEB6F75A7ULL, 0xFBF14F32631A9EACULL, 0x3F3A126F63B96889ULL, 0x2A445F705E489B1AULL, 
            0xBE5A528F3799C2A0ULL, 0xA45893BB90EC3C4AULL, 0x63E08A5046656BFCULL, 0x89ABA269FAD348E4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseEConstants = {
    0xBA7F954D9C91DCD4ULL,
    0x8B82FD3269650B58ULL,
    0x538152FC3351709FULL,
    0xBA7F954D9C91DCD4ULL,
    0x8B82FD3269650B58ULL,
    0x538152FC3351709FULL,
    0x50E89C87A101B46EULL,
    0x0D8C50EFF1F041E5ULL,
    0x27,
    0xD7,
    0x07,
    0xB4,
    0x44,
    0xA6,
    0x0D,
    0xD9
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseFSalts = {
    {
        {
            0xB97E022A226AEDF4ULL, 0x7A2DA78A3FF498B0ULL, 0x1A7159B84F4F488DULL, 0xFB9E7373FF788DF9ULL, 
            0x0AE52EBCE2BCAF8AULL, 0xBBDED998834B38A0ULL, 0x1FF31F2AF4797A65ULL, 0xF41D643EB1938E0FULL, 
            0x4AFC2C51E24F2F03ULL, 0x275C05C8448FF0DAULL, 0x052C741DA02E6BA1ULL, 0x392B7AE330C5FB41ULL, 
            0x97CC3307547AFA06ULL, 0x0F3615825AB6F758ULL, 0x4840CCA02C0B80E5ULL, 0x21EA6DEC5AACA952ULL, 
            0xC56E6D4B91572E95ULL, 0x6F3FAD1AE8F65EAEULL, 0x2C49989C110A6784ULL, 0x376761033DC2EB45ULL, 
            0x0168B1E54EF386A2ULL, 0x4C1A9C4C4CEF9DDFULL, 0x04485A786E0B94D5ULL, 0x29A78D2F71F83588ULL, 
            0xB038D97F11C6D5F9ULL, 0x68C28F20DA99B974ULL, 0xB1D60663A4C44A79ULL, 0xC7D7B6072F74A12AULL, 
            0x12A4FA78C941E003ULL, 0x7C1D29CBA373C7FBULL, 0x344E3521DC292F3AULL, 0x771837B20A9A48D4ULL
        },
        {
            0xDEA3622E6B45D12EULL, 0xE0E7709368C4920FULL, 0xA1BC749D7142626DULL, 0x421FE10781791032ULL, 
            0xE5FD561BED8B1598ULL, 0x274F34306B7139D7ULL, 0x0D830215642AF0AFULL, 0x4E7CE5754566C087ULL, 
            0x3FD173E3E4A8D66FULL, 0x800F4DE6184F5125ULL, 0x75CFEC8A24274978ULL, 0xA400021B7C01891FULL, 
            0x186D8C43E116F842ULL, 0xACC9C892936396E4ULL, 0x7D6D33E456330653ULL, 0xDEBE86B442597609ULL, 
            0xD0B41D1A95090A17ULL, 0x1B6B03E0AFDE0B10ULL, 0xD4C104F6F1B8C7DFULL, 0xA5C1E491682019EDULL, 
            0x8D78FCFEE2416895ULL, 0x38EA85E6DE0311ADULL, 0x2BD2C0DF11035769ULL, 0x882E9521535013B2ULL, 
            0x21CA6BD4A8BE0A4AULL, 0x23BE2E7DFE1B07D7ULL, 0x8AA95FE4ED826B24ULL, 0xA3F64CBA0E429F38ULL, 
            0x345F90CFC37F805BULL, 0x432F162A411C5DD9ULL, 0xD5D86F9510D7CEF5ULL, 0x412E80D9DE0597AAULL
        },
        {
            0xDA9828A40A55F16DULL, 0x936F2EA6CB14FE5BULL, 0x4E546CFABD372CAAULL, 0x31311283977650E2ULL, 
            0xED9BC75CCC5EBA70ULL, 0xF992580792140D2CULL, 0xAC169DFCD04EFAD2ULL, 0xC93577CF0819BD31ULL, 
            0xA9D7E42CAA2BFA80ULL, 0x1A46B4E60A118F76ULL, 0xD04F4806F38357A7ULL, 0x29B4FF04197B0277ULL, 
            0x49904E5F681F347EULL, 0xC2C43F7F58D3F63FULL, 0xF0BC5631345715DFULL, 0x6B31E3649AA00C67ULL, 
            0x54C942891D3C347DULL, 0xB2F805A724FD3843ULL, 0xDA825DDBC7B4BAE2ULL, 0x6CFB55A5592BE214ULL, 
            0x422263E1267F912FULL, 0xED93AEAAB2A669E0ULL, 0xFED0353535E0C97AULL, 0x244C69E9C1A6F72DULL, 
            0x5D558774F70D58CFULL, 0x3F1C99DB25F58492ULL, 0x29DFFA05309FE273ULL, 0x9F081EB801BB5B33ULL, 
            0xE724F48B19DF2AECULL, 0x476FDF2238A19C87ULL, 0xC5D82BB8C70F2B93ULL, 0x5E0F9806350DE2C3ULL
        },
        {
            0x642CE667E5838923ULL, 0x9C5896A8CB1A10EAULL, 0xAF0BB51D8E33B7C0ULL, 0xB5EA6A9F6B80AA7BULL, 
            0x10B3340E5F040499ULL, 0xAC2708FE7EAFD962ULL, 0x7C37578CDD2D50DCULL, 0xE0D2B0450D6F025EULL, 
            0xD7EF5A33028A0146ULL, 0x118AC6C739792AE0ULL, 0xA38A1D69A1D3CFA6ULL, 0xED20FD19C8DC9F1FULL, 
            0x48F2478EACE35733ULL, 0xA0DF5C7F3C56A8DEULL, 0xA4AAD7F97B972588ULL, 0xD8E23CBDAE4C2396ULL, 
            0x56C589943C0D9722ULL, 0xB75C63D6F7038315ULL, 0x7E0AAA89E03522BEULL, 0x5EE95F7407D0A116ULL, 
            0x94CB9467AD180B87ULL, 0xB4C8E469D6CAB6E6ULL, 0x7B755A88F908DCACULL, 0x61291FD67C328230ULL, 
            0x29B1E855AEA416F0ULL, 0xDF71CE1C3241BF24ULL, 0x83300FBBB470680EULL, 0xC0A33E2A7CC1E858ULL, 
            0xF428AD2C3583885BULL, 0x56B69CA5FC5B7492ULL, 0x94143E171BA4A66EULL, 0x2EC5C63A6092BE5FULL
        },
        {
            0x97652536F108AC04ULL, 0x5D4F87554BB47FD3ULL, 0x4A9D6E88CE313433ULL, 0x1C6C3ADF5BE91E79ULL, 
            0x8F892CDDB3F89614ULL, 0x5058AD3ED32A3195ULL, 0x563D19C25EBCD7B9ULL, 0xC36ED8F5E201F7B3ULL, 
            0xBF8129633D35BCB3ULL, 0x9403F0315501A8D1ULL, 0xBBBD2FDDA20AAC15ULL, 0x891844C3685B8871ULL, 
            0x32370A1E9587A093ULL, 0x8DE67B932B868A0AULL, 0x260FCB62B1B3FA0FULL, 0x5D5A355ECE02ABE1ULL, 
            0x7F85E3BCADEC1C78ULL, 0xE24914B0B3C94D63ULL, 0x409288FD3729C2DEULL, 0xB79F6FB9E76BE334ULL, 
            0xDB1A83008EC75A3AULL, 0xD55B89BC26C20DB5ULL, 0xAA51A99BEF3B41DDULL, 0x944D45A541DE9153ULL, 
            0x8CC3C2AE44DD7BD3ULL, 0x3CAD0E1AE24B3C40ULL, 0xE888BD41CAFD45F8ULL, 0x0D03DCDA281380FDULL, 
            0x467E9D59C93B611FULL, 0xF9B40EE77BC9BA67ULL, 0x59070CCBA444B7E3ULL, 0x9565B2E08E78237FULL
        },
        {
            0x148ED527DEF6B4C5ULL, 0x78E177795D7F9F1EULL, 0x183792FEACD99FD5ULL, 0x286A7227905D899EULL, 
            0x2D26CA30336C5BB3ULL, 0x180CAA7575957AADULL, 0xA502DCF650E09300ULL, 0x1D46AE1332DB576EULL, 
            0x37964C5600D281E6ULL, 0xD0183E80222225A6ULL, 0x58596ED6022FAFE3ULL, 0x8E6CE9A5DD842688ULL, 
            0x15EE0E06872104A6ULL, 0xB40D39D759E98646ULL, 0x63C9D2C4FC03EA3DULL, 0x9D143FDA77BA804CULL, 
            0x5A816679D1D95E97ULL, 0xE3A81528BC5449E8ULL, 0x506A1B28AEF40B66ULL, 0xFB381C6F5770F29CULL, 
            0x92E520617B885344ULL, 0x8300A865D54CE23AULL, 0xD0CE34D9D3FC5FF6ULL, 0x82D692CA9565317CULL, 
            0x08938865EB66056EULL, 0xB7CC2E9D847B4E55ULL, 0x7DB0DF5D1546D427ULL, 0xF4FCE74CB0BFDD60ULL, 
            0x7901D8390DA12E41ULL, 0x387AF2E6CE4D45D0ULL, 0x40F5E81586ED0CABULL, 0x4B6D9BFBF9A92DEDULL
        }
    },
    {
        {
            0x309D0CF682258291ULL, 0xF051C100359A9619ULL, 0xA866039CEBB9E94EULL, 0x6980EED126D10C89ULL, 
            0x094ABD87BD6E6A67ULL, 0x5525923489EAE724ULL, 0xD6331CFDD65CFD77ULL, 0x0B0C7D03B672BDADULL, 
            0xD1B75F4081296BD9ULL, 0xAAE98A2394650128ULL, 0x0857375C8166AAB9ULL, 0xE8A39B642773D22EULL, 
            0x2C4BEB7EDC008929ULL, 0xC8869E47D4F8B6E7ULL, 0x9D16A2D290BF8342ULL, 0x6FBCE0006FCD2B66ULL, 
            0x4BA4746D5F520106ULL, 0x30236E90D2E08299ULL, 0xB7DD71045ABC7ED6ULL, 0x667214325CF6BC7FULL, 
            0xE849CE2236C181EEULL, 0xC1017112A08F15C6ULL, 0x584DC49AC3BE0D2BULL, 0xE6F800D686E57F72ULL, 
            0xF004D6C471DA4455ULL, 0x49A2F7CA5178C1B5ULL, 0xB20D2E78FA58D1C0ULL, 0x2E03AD872259E8CFULL, 
            0x920BCCF74784A9E3ULL, 0xC25234B11BEE0DE5ULL, 0x01C9C2520A024360ULL, 0x656A98CA7C172DCFULL
        },
        {
            0xCD3A09105A5E3E56ULL, 0x0E71EC2CD62782ECULL, 0x0751BB27433678DFULL, 0xB5EC33A9F4899FF3ULL, 
            0x8793AF4F27E748C5ULL, 0xA5747ACAA2DC02C4ULL, 0xD88190A62DC95B06ULL, 0xC57A87EC7B643A3EULL, 
            0xBFA405A5DA4689FBULL, 0x1E79F2FA2CDD59A7ULL, 0xDA83775E0EA9B2CDULL, 0x3AF95E773EC08C9DULL, 
            0xF7D74E9290A38832ULL, 0x8E529273392DF2EFULL, 0x27DD05DAC7AC9338ULL, 0xB17A9FA30D06EB89ULL, 
            0x685E7C5EAC981F30ULL, 0x12177DFA045E86BCULL, 0xEFACB2A6F40353B5ULL, 0xC4678B9ED0D384E1ULL, 
            0x5C7F8EE618DF4EE3ULL, 0x33E21F3DED86E893ULL, 0x49435185B15618AFULL, 0xBA52D6A81870D45CULL, 
            0xCAC16CA2E475428BULL, 0x9149237FE442F152ULL, 0x2AC34931746C998DULL, 0x563FE4941CD0D0E4ULL, 
            0xE3AA1D8BEF19DD88ULL, 0x6AEF5EB8D802A9FDULL, 0x59574FC07E657DD9ULL, 0xEE038D0864A34362ULL
        },
        {
            0x6FAD243D12278AE3ULL, 0xB7D99D948E0921CEULL, 0xF59BE6D958E9BF88ULL, 0x304E0605960841B8ULL, 
            0xD034B012689040A8ULL, 0x4AF20C2426C43B88ULL, 0x729FC084A85091E3ULL, 0xF423100D7E8772DAULL, 
            0x296401C0ECD3FA51ULL, 0x7BFCB713A27DD984ULL, 0x2384B24EB9FC56BEULL, 0xD61A33EDBD59C969ULL, 
            0xB390D2CA2D6911FCULL, 0x745A875B8698923DULL, 0x774E63204A647405ULL, 0x57122EEBB649E0A4ULL, 
            0xAF5FD754AC8B9CD5ULL, 0xA82B27700FC10CC4ULL, 0xCF2649D7704FEBA4ULL, 0x75DACEBFA135138FULL, 
            0x2657D60D73098A08ULL, 0x75452FD10A975CB9ULL, 0x3F7C1555D781331CULL, 0xF521E7091EE340EBULL, 
            0x4170D8EB024EA5E1ULL, 0xC099D4BC40CE9E01ULL, 0x10A404231D7AE368ULL, 0x6453B0490F624938ULL, 
            0xBC77EFE80000D9B0ULL, 0x6B649142BBAE80ECULL, 0x9FC014122F8EA8ACULL, 0xF4608D7FAEB21EBCULL
        },
        {
            0x2D4F918EDD6536DAULL, 0x27882A3419171C3EULL, 0x0D64520C3E9857DCULL, 0x1215FB9239A0C754ULL, 
            0xE8593395B5998E1CULL, 0x1416D0DE918CC953ULL, 0xCF3D57AEC1528544ULL, 0xF5AE82439A7B1FD5ULL, 
            0x21F01B93B7BB446AULL, 0x766A9A36FB54DBE4ULL, 0x7A886EBDED141C3BULL, 0x2568CA03C994B9AFULL, 
            0xF31414B5ADA58732ULL, 0x010243910F276476ULL, 0xB5C262C30EB4A16AULL, 0xE3D2FF633A0EC745ULL, 
            0xC25E4699F8E0CD57ULL, 0x74ADBE911D1BD436ULL, 0x30DC2BA10ACAE3D5ULL, 0x2BE0A89368044495ULL, 
            0x25EA75EC02511378ULL, 0x1E7B7F92CEFB5073ULL, 0x0B8790F5BDC92F20ULL, 0xC2C361059BF15CB3ULL, 
            0x6BDBA095261B0D50ULL, 0x87FAAFD86FACE3C5ULL, 0xADCE8A4EC7CD2614ULL, 0xA5C4FB2A2D7F9318ULL, 
            0x771235CBE1D5C199ULL, 0x2EACB94CA6DE784AULL, 0x205017EE2C1750CDULL, 0x1E9A859705FEF47DULL
        },
        {
            0x5E37038683CFD2D9ULL, 0x2C5B4FF60C3D7CA5ULL, 0x0A43BB388544C3EBULL, 0xFFDD439626DBFBDDULL, 
            0xC57337C5CA949823ULL, 0x9EE9EE221934C66AULL, 0x27F08137A55A732AULL, 0x65006359065F3938ULL, 
            0x95CE3344AD7186A3ULL, 0xFC28849B7301581DULL, 0x4CC681BE062D0DC8ULL, 0xBF2E9ED7A673F57AULL, 
            0x269AEF1A46BAEA5DULL, 0xA5234DA4D60D9712ULL, 0x16939916AABEE69CULL, 0x7B18DB21D2CF47BBULL, 
            0x35C4FF89CF1553CBULL, 0x7F14ADC405EF5225ULL, 0x61FFD6BB8F6E5E1FULL, 0xE9FB84F3872E1C0EULL, 
            0x0AA56C9FCA1AA3ACULL, 0x0F1667CB6BECCDC6ULL, 0x33968CE76F3E11F1ULL, 0x4E7E112AEB16BF0CULL, 
            0x715BA69841222C16ULL, 0xFBB73B3CEA2CE315ULL, 0x6D0C0E1C20C788E1ULL, 0xC4A8A2D795C2444FULL, 
            0x70A8CB1F8D727351ULL, 0x56C9466231DDCA7FULL, 0x743A94D1D6467946ULL, 0xF79914FBBA246B49ULL
        },
        {
            0xCFD6E1F0257BDB16ULL, 0x4C9700E958E1C34FULL, 0xC2349CDDD55DDA43ULL, 0x61EB84486F124AFAULL, 
            0xE5B2611799AD4F7FULL, 0x85BC2320189C783CULL, 0x78AA079836EA15A0ULL, 0x72917E77D3B1658AULL, 
            0xC80DD50C5FCC7F4BULL, 0x0EBB1DB3D0D9D3C4ULL, 0x629B9C1B3EF4D60EULL, 0xBFCE9AB1ACF535E3ULL, 
            0xF433DEB74359AFCCULL, 0xD8CEF51F96C7402FULL, 0xA1FC8E6AD04EB8F9ULL, 0xD4548C6602246483ULL, 
            0xAA596204D3090C8BULL, 0x3FA334E9AD118CD9ULL, 0xCEE41CF2B7E89A73ULL, 0xE11F5BEF4F858F92ULL, 
            0xB3A521FD9835B387ULL, 0xEC762A1BA9614FA2ULL, 0x0532071C026584F4ULL, 0x863F7826C497BF22ULL, 
            0x415D9C459CDE9901ULL, 0xDAD98CE3FDFF1A3EULL, 0xDDEC169429BD0FCBULL, 0x7E4E8E33674D7774ULL, 
            0x8329803D7FCAB7E5ULL, 0xC3C0298525A9A165ULL, 0x0A8929DBDF467D45ULL, 0x411387E318189718ULL
        }
    },
    {
        {
            0xEB196EB758085B0CULL, 0xB77D198791F3C408ULL, 0x133DCD59785C053CULL, 0x7625100836BD3DECULL, 
            0x0C96A99501EAA66BULL, 0x74BF9365694B9F90ULL, 0x387BC46BE0A02BECULL, 0x642534D171BC090AULL, 
            0xE747C30AA2DC4C1BULL, 0x705D0E47E0129B5BULL, 0x660FFFBBAB3C2A66ULL, 0xC4F337910120D121ULL, 
            0x729D17BAC362655EULL, 0x19113CE9EA49B0BAULL, 0x787B55462722D0E2ULL, 0x5BBC41A1EC36FDFDULL, 
            0x767BD5DE8BD6B812ULL, 0x5FDE287FC945029DULL, 0xAE5C3E7E5AE97F82ULL, 0x301985A9769716F9ULL, 
            0x4D2EACFB5A2F15F6ULL, 0x687D5A117AC37C9FULL, 0xB2FDC825FAF58F75ULL, 0x7D4928515C5B0433ULL, 
            0xA4465AC719CF5AA1ULL, 0x681FFAFA6BBA0632ULL, 0x581B3C6ED2C696EAULL, 0x0AFCD09B3C40122DULL, 
            0x00096C30D4311360ULL, 0x7D8BA71032B72F70ULL, 0x302A022962FEDBCEULL, 0x936CF07214D9CC23ULL
        },
        {
            0xE2F5CB9AA48876C6ULL, 0xAAC258BAD98C16CCULL, 0x5DB8E0979812E2D2ULL, 0x01381717E3E93D62ULL, 
            0xBF2E5E93A6D99439ULL, 0xCA55C2BC6E28858BULL, 0x45C2B0A3FDDA7726ULL, 0x3078B73F535B7716ULL, 
            0xDD83240EF791AC93ULL, 0x6E4A2C5354706D79ULL, 0xBFF4B6C0F3483BCAULL, 0x73EB85BE84587819ULL, 
            0xA5D33DEBC80F993CULL, 0x8C3AFDBE87E8D98BULL, 0x5058A11376635DF0ULL, 0x3FA33E0F66F64B81ULL, 
            0xE9E0D1EFFB86EE43ULL, 0x258A597A2596EF4CULL, 0xB252F208DFD6D4BEULL, 0xAF6E7A3F3839D624ULL, 
            0xB20F7DCC9FD97435ULL, 0x3132CEDF19F04B35ULL, 0xC9AF2DA4F5E77764ULL, 0x6E37C8538F621BCBULL, 
            0xBA43C4B51F96A033ULL, 0xEF6AA28A3A308301ULL, 0x1367DD32D23B66BAULL, 0xE16E8D3302FAC3B9ULL, 
            0x41183393B5CA1BCEULL, 0xE13A5C3A67CDE56AULL, 0x3E7F9956BA12F51BULL, 0x3EBF716AE509BD34ULL
        },
        {
            0x40574D8CBABFEEACULL, 0xC8EAC73EF2925704ULL, 0xFD3249E6E43A7EABULL, 0xDD477675C4200B3DULL, 
            0xB8AEF5E63BD9550EULL, 0x2E68D3B3475D6663ULL, 0xAB615A5EB71711D6ULL, 0x7AD522DCED49D961ULL, 
            0x787D60CFEC178CB2ULL, 0x8D76933DCB6765E8ULL, 0x0993B58CAB753435ULL, 0x7158E5CAB604E6D5ULL, 
            0xF4A1F77CC47ACE07ULL, 0x2E8B837153A2CB94ULL, 0x8133570BC4FAB9BCULL, 0xF4DA43EC9E667A15ULL, 
            0x955F1380AA91C521ULL, 0x98B30B9F16A00FC9ULL, 0xFC4598B68C776547ULL, 0x93B134F6331A40DCULL, 
            0xE91B0A0E8A5AD90EULL, 0x04E238FF9BB07D54ULL, 0xF03BE78422120734ULL, 0x2CC832DEED0131A3ULL, 
            0x1381C271FC8CEB9AULL, 0xF478511AC566DA36ULL, 0x13062B4D0630F7FBULL, 0x313936598B4D4504ULL, 
            0xAAAB4521E8C24EAEULL, 0x1C291371126DF004ULL, 0x173B1F51AB5A3176ULL, 0x8354072E13B3422AULL
        },
        {
            0x79A2F31534B69900ULL, 0xE6B3C4AE58029A69ULL, 0xFF22DAC8998D68FAULL, 0xBA4480D6EDD1B04CULL, 
            0xE72EB56D98B22781ULL, 0xAD816C846CFAC46AULL, 0xCDF85EF36999170DULL, 0x2C4BB1DC1CA28154ULL, 
            0xB134D7CED0A0536EULL, 0x761B9DC69CA8B64FULL, 0x3BFF7551F0632816ULL, 0x61CBDCC73E93C738ULL, 
            0x3854181EB18992EBULL, 0xFC5EA8D5520587A6ULL, 0x327634A7F2256D36ULL, 0x273637535A8FA4DCULL, 
            0x0E430ED46E853458ULL, 0x5540EBBD14FEA74CULL, 0x482E06AF47EB5B30ULL, 0x98A4D97ED388C31FULL, 
            0x4C647C8EC8A5B514ULL, 0x6102BC9FF0331AF7ULL, 0x6A7433ED99F332E0ULL, 0x1B788875AAA85F8BULL, 
            0x1303929D0081AC37ULL, 0xA3824CBF0F576A0DULL, 0xA3419CBCF16732C4ULL, 0x963BCDF3FCFBB6C1ULL, 
            0xE523C8DB8C0E11ABULL, 0xDB44CBE0103B9D01ULL, 0xBABAE39C12161A54ULL, 0x24DC1E5D1AD399DCULL
        },
        {
            0x01A07CE4C0BAE082ULL, 0x8F993C3C7C912BEFULL, 0x54DE1C0D804BF85FULL, 0x31E89202A7B4D7A4ULL, 
            0xCE829A3F971CA3F8ULL, 0xB5E56F91B512CEBCULL, 0x0374EFDF95512CDCULL, 0xEB8C7A44F7107F69ULL, 
            0xB6FE7F3701F9A788ULL, 0xF1A8F5FBD9A4A887ULL, 0xDAA9DF80B5632EBDULL, 0x3A8EBE05413A596EULL, 
            0xAC30F3854963B9A8ULL, 0x715945B07D25F5B4ULL, 0x1A7FAD63D6161CDEULL, 0x4A6A34B733E2FF62ULL, 
            0xCFC428755915E381ULL, 0x80E9CA6494163E35ULL, 0xD9D788E3A7251E74ULL, 0xC503581877B6BF4CULL, 
            0xDE9C2D47539C021FULL, 0xA95B12711FDA871AULL, 0xF56E46788C2D93ECULL, 0x6F38D4085D10D711ULL, 
            0x69D3C2AAB620BA8FULL, 0x43CE7D139C7116AEULL, 0xBBB9CF779AFE01BDULL, 0x4BA49304F764BD45ULL, 
            0x5E7240E1020EE4C2ULL, 0xBC676297407A408DULL, 0x431394C5FC0BD396ULL, 0xE2431331BDF6029EULL
        },
        {
            0x0D630ED497D88466ULL, 0x390CBB79973BAA16ULL, 0xC8F21C572DD14BBAULL, 0x3882B91550FD1534ULL, 
            0xFB20E198931D42D8ULL, 0x517713D348E55677ULL, 0x7056E1184B1FB4B8ULL, 0x74FEAF3BCEB030FFULL, 
            0x2D0609B54B831A5EULL, 0x8D226B6F6109DF76ULL, 0xA9B1C83C2FF1060EULL, 0x8688AC18DCE8B56DULL, 
            0x6BD4169D02ABAC42ULL, 0x44AFFFBA1DEECC46ULL, 0x90A039999B883BE1ULL, 0xC2D539B290C8C320ULL, 
            0x466F24ACE232C501ULL, 0xFA4E8C6ECD1ADE15ULL, 0x47CEDFBE1CFC9AFBULL, 0x85613D06AF41ADB7ULL, 
            0xD1CCB31ACC64D0B9ULL, 0xE651F0612B8C3F0BULL, 0x19E9AC879B04DF8DULL, 0x55177BBCE66B9EDEULL, 
            0x59E5372051182FBFULL, 0xA43EB8BAD3D6549FULL, 0x2606C87266931369ULL, 0xA828070583B25712ULL, 
            0xAE948312FC66DDF8ULL, 0x3A056F165666EF83ULL, 0x0F151799A1AD1D04ULL, 0x5B7D86A55103FDD0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseFConstants = {
    0xCA2A95F3A6A546B6ULL,
    0xCCF6F060F247C328ULL,
    0x938341B292B66FA4ULL,
    0xCA2A95F3A6A546B6ULL,
    0xCCF6F060F247C328ULL,
    0x938341B292B66FA4ULL,
    0x292018D0BB132A6BULL,
    0xF341857934B14AC4ULL,
    0x3B,
    0x7A,
    0x84,
    0x1C,
    0x3B,
    0x72,
    0x7A,
    0x86
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseGSalts = {
    {
        {
            0x079D7E8CC14B21C2ULL, 0x86A108181651BD9BULL, 0xF34E7ABB0669C9FDULL, 0x3954A918236CC53CULL, 
            0x5D11F54236EB0A29ULL, 0x6396B3F35CF3C305ULL, 0xCE2773BEAA081346ULL, 0xE9F981D4C6518040ULL, 
            0x76FDC0EE7E420279ULL, 0x9470020A82349A4AULL, 0x67DF5E94F4BA1F9BULL, 0x543B8826E6795F96ULL, 
            0xB3A739CC2897473CULL, 0x4AC4220182D7D354ULL, 0xE3A988AA4AB67615ULL, 0x92D5E175F66BD5C2ULL, 
            0x2BC3CF6989FE788AULL, 0x54949C8FBA212D97ULL, 0x683E38A22229AA9CULL, 0x512CE766FC9A2CBAULL, 
            0xFE847277458F2260ULL, 0x2A910358A14633B2ULL, 0xB667CA2020D46926ULL, 0x2DD7EE572604D287ULL, 
            0x1D3FD3913E9FB820ULL, 0x98AFA7A4FCD63A5CULL, 0x8776AFC946CC7F71ULL, 0xC3852A2293B584A5ULL, 
            0x6786613F4FCC74B8ULL, 0xB754CAB499AC45E5ULL, 0xFB287024379C21E2ULL, 0xC71C1B322D39783EULL
        },
        {
            0x4237EBCA9A26074FULL, 0x30CEDD85BE87D33AULL, 0x8D80D198B28A6A56ULL, 0x6F8F2D398750CCBBULL, 
            0xDCF780643D41807DULL, 0x7CCA6A1B0870841CULL, 0xB678122CEED6CC8CULL, 0xA6394934BF0AD822ULL, 
            0xEC166E61C235C548ULL, 0xBA078D05CF49C8B2ULL, 0xD4F9DA67944EEF70ULL, 0x9919C3A2EADF4203ULL, 
            0x49E27E220F770107ULL, 0x4E160B8ABD7108D3ULL, 0x8EB98AD50CF9E845ULL, 0x43CC1466C77590A7ULL, 
            0x78B64C15E722EDB3ULL, 0x7E599F6451473AB0ULL, 0x2D2635C8CBD124F8ULL, 0x46742A04D60EE07BULL, 
            0x2247045DABC0A654ULL, 0x4D1ECA3699899ADCULL, 0xDE61751D4B349E53ULL, 0x761B756FD8CB7FA4ULL, 
            0x6FB387F6783D4ACDULL, 0xDCC6BD004BEEBC73ULL, 0xD1DDE403D62FBB92ULL, 0x4A6E7A2B697A4316ULL, 
            0x03A32B430D913BADULL, 0x27AE83619A054C0FULL, 0x76BD8D8A804AE785ULL, 0xB138E96E3F6B00DEULL
        },
        {
            0xE33CB221F6604FDBULL, 0xCF80279F965FCEE5ULL, 0x69C7DBB1925E6985ULL, 0x3076ABEDD656298EULL, 
            0x2B75B962D4CB1DCFULL, 0x4026884524D35F55ULL, 0x4BC902931B56E340ULL, 0xBE74669E7EB0EF49ULL, 
            0xD2C1364C3EECA3F0ULL, 0xE06F2ADA6F2C4CEBULL, 0xFDB7B152AC159E46ULL, 0x696849DE922311D6ULL, 
            0xB1E855B58AA2174CULL, 0xB6FF09B34B79D88FULL, 0xA56A6921EE2AB525ULL, 0xCFB63AD5E01ED2CDULL, 
            0x1D8336F987BC39EEULL, 0x5E47A2DE2F0F98D6ULL, 0x96912D0B282BD718ULL, 0x3967C940D4F4D789ULL, 
            0x2BE4B04B4E66DB89ULL, 0xCC61269A44B1191BULL, 0xB15C5EF8DD85F537ULL, 0xC37C74F3063998A8ULL, 
            0x914726A92020536AULL, 0xEAD97C74FB783E4AULL, 0xA692F229297309D1ULL, 0x5A79BE85D6F022F6ULL, 
            0xEF0ECB937C3D6C13ULL, 0x8516B0AF9CB4B528ULL, 0x2F14F92572C71219ULL, 0x7591E0A32B64567FULL
        },
        {
            0xD45F3CAA7651C302ULL, 0xC617041A9384B982ULL, 0x04CA683B14930515ULL, 0x164DFB644DBF0140ULL, 
            0xDF52306395091371ULL, 0x087A6D5E923CFCF8ULL, 0x6AF9DEE09342C2CEULL, 0x5209C6393ECE1FF8ULL, 
            0x03AE8F8F1EBC8A5FULL, 0x47D61AEB1D3E7842ULL, 0x72F70FF90F5EDED0ULL, 0x90E545E4B8C292DAULL, 
            0x556E9E53527E2290ULL, 0x08A2F48E9FDC5D36ULL, 0x06AF31F116C6F829ULL, 0xB7C54E2A427AA73FULL, 
            0x7F51A2BFB05AC46DULL, 0x7427B5FE7F958414ULL, 0xD1CFD13EDE90FF27ULL, 0x629839D4C362FE55ULL, 
            0xAF8F618043B7DFAEULL, 0x350B0894FC4ADB3DULL, 0x73604F3FE8616C5FULL, 0x7D359062EA139A7AULL, 
            0xC28BCC33B83983C6ULL, 0x38E6E1110C3DB6D2ULL, 0xE0F9E336756E5269ULL, 0x27A7622208E766D5ULL, 
            0x2E20FF161514AB1AULL, 0x5517982EDC0A8822ULL, 0x7E0783B089DC84A9ULL, 0x8FF37AB097ABF5C4ULL
        },
        {
            0x232C28554098F2F6ULL, 0x0530647843BCE98DULL, 0x89A50EDB55B0B4A1ULL, 0x55ADB1D7E9B1A45FULL, 
            0x68244E7D73F4AF06ULL, 0xA859C27B07B794F4ULL, 0x20D8ED9440370DFBULL, 0xCC6278C59F34C524ULL, 
            0x12632590EC859834ULL, 0xE3811A9A624CB40EULL, 0x81BAC0BADEEE58CAULL, 0xB9186E303920B21DULL, 
            0xCA8BE5BE539004B1ULL, 0xFB270F8C9E9EE956ULL, 0x9B863DFA4B969BCFULL, 0xBCA8FE29FD9FFC2CULL, 
            0x365FA3519E62454BULL, 0x2F434002A65CFB46ULL, 0x608D1D1C1361EA6BULL, 0xF852CFC8D3AF8A44ULL, 
            0x411DCD102C49F311ULL, 0x37E81BA32EE44BDCULL, 0x9C5D08913D999CAEULL, 0xCC19E0DA21CF59F5ULL, 
            0xAE9A6E101F7BBC4DULL, 0xB284623201605685ULL, 0xAF131CFDB37CD169ULL, 0x847AD981741DBB65ULL, 
            0x612870686CAC43AFULL, 0x3898C263F902388AULL, 0xCDF15CF075BD515BULL, 0xF12A052733B3A17FULL
        },
        {
            0xAAF26D6D192F0CE5ULL, 0x5E52F3E58E046A66ULL, 0x70EB0B124FE21FD9ULL, 0xBE4E3CCA65D64330ULL, 
            0x47E9AB4F1B7C0801ULL, 0xCEE2108A2F256E1EULL, 0xE08A2929E18AC50AULL, 0xD1747D08C1C8CDA1ULL, 
            0x86A3D21CA5FDF7CCULL, 0x50209C7997CEB1D2ULL, 0x41FF7052A5555C5FULL, 0x35FB56EC02B012AFULL, 
            0x130E85129CB0C07AULL, 0x73FEAB1B33A01F33ULL, 0x5FD0F52B0F818843ULL, 0xF40B8B853B757897ULL, 
            0x2C9157726B30F8D7ULL, 0x22B5D7950DE9557FULL, 0x8DD5382C88C2794CULL, 0xAA5607CBB23AAEF6ULL, 
            0x8B1048DBDE5E4684ULL, 0x7109537A365A7700ULL, 0x248941BF9F37DACDULL, 0x8324A98A875CC3C8ULL, 
            0xF59B3FEE6A50A100ULL, 0x42D4C20772D94A93ULL, 0x98C47FCB5B40FEC6ULL, 0xC0BDDFF8D0FC36FDULL, 
            0xE3A8E6F920315FB6ULL, 0xE4ACE1361713D8E9ULL, 0xF5D9E91309BEC119ULL, 0x7BDBAB17668C10F5ULL
        }
    },
    {
        {
            0x8B8939A5A09C8204ULL, 0x22934F407916DF81ULL, 0xE3D59CF7D02EE497ULL, 0x838EFAC084620086ULL, 
            0x75A15A4BEC86245BULL, 0xA08ED6EFA6427FC7ULL, 0xA1B693F36D4A4C64ULL, 0x2AF943126578036CULL, 
            0xD2158F439278951BULL, 0x79D2A46686418148ULL, 0x029B616AB9875BFEULL, 0x150185CB3711B7D3ULL, 
            0x3FF97C4B88821804ULL, 0x2345D4AC39C56CCFULL, 0x3DC4D367E1A7F1BFULL, 0x9872E34BDC4CB727ULL, 
            0x2D9B6E2A82207019ULL, 0x46EC8B1D58CB6585ULL, 0xFB2C21713A9717F7ULL, 0xAB8E1AA0DF8DDAF2ULL, 
            0x0A4CBAD2280EE1E6ULL, 0x3F045818972C20F0ULL, 0xAAB956809700764FULL, 0xDCBFEA06D0949A98ULL, 
            0x1918F944186888F1ULL, 0x9F8841F2432BF163ULL, 0xF6090FDD69E93056ULL, 0x0162D2B807E335FAULL, 
            0x743927C2B8FE3168ULL, 0xB2C793A438E1402BULL, 0x6D553CD06FD43EC9ULL, 0x663910F217D3AFF0ULL
        },
        {
            0xF0EBCD1AC9D4AA84ULL, 0x521C0450FABB7EA3ULL, 0x0EEE2CA7BDC623E3ULL, 0x51501FAEC8EC97C5ULL, 
            0x53C2FA590251A323ULL, 0x980E7683E37919E6ULL, 0xB5638D473E0D9A1BULL, 0x451BB3EB94670C20ULL, 
            0x1BBCC9C9A965FE24ULL, 0x43A0618D5A7D0CC6ULL, 0xD11E74B19A4A37E5ULL, 0x7334E83CAFCA0F36ULL, 
            0xEAA674BDD9D2CC13ULL, 0x475ECD4F599BD19CULL, 0x0518B7AA5FFA9CC9ULL, 0xC72BD62127C56D5FULL, 
            0xFBAED5863153B827ULL, 0xC47D197507AE4B5DULL, 0x73FECAAA3FA07C40ULL, 0x1B6D9B6022881894ULL, 
            0x717F8F3CF6A0B00AULL, 0x8556D64A4B429B64ULL, 0x06F666D127CC3098ULL, 0x424CB97D5EEC205FULL, 
            0xAAC12E9276B477CAULL, 0x8C9AA785FDF5E12CULL, 0x46496CD6F6726169ULL, 0xD0DBEF0342FBF55FULL, 
            0x850647004C277CB9ULL, 0x72BDA3F717EA03CDULL, 0x7F03733682A14AEBULL, 0x05333B6CA4DEC900ULL
        },
        {
            0x39AD116B7CE11E91ULL, 0x65E67A64723004AEULL, 0x62385F3F74BD0693ULL, 0xEC0C597C552B6BDFULL, 
            0xA404FA6749908276ULL, 0xC88CC44A0CEFF752ULL, 0x36EB506C8991A6FEULL, 0xB22817C3CFADCE55ULL, 
            0x0B4F3A0D30D3FE54ULL, 0x5872FE8149A1F4FFULL, 0x40F78728BBFACC99ULL, 0xA3D9C1D41FDA08CFULL, 
            0xDA116EC827319C64ULL, 0x1A726B0253821C44ULL, 0x0AA9478224FAA267ULL, 0xDC82E978B4D0FC50ULL, 
            0x174E7B641A2A6681ULL, 0x1E5872BA499ED2E8ULL, 0x992896F9B65A316BULL, 0x002A93B5BF1C5B4AULL, 
            0xAEF3D58A7CC64A37ULL, 0x34F3F3DCB32DF138ULL, 0x2F62532DFA37FC38ULL, 0xC8676774FFCB57A1ULL, 
            0x4042E1C2BFC596C3ULL, 0xCD9C45E6F74275C5ULL, 0x01C102CFD3950692ULL, 0x71F42BC702F7E823ULL, 
            0xED3CEE7B4346A96AULL, 0x49C424A85AD30B76ULL, 0x85D53BA905E10223ULL, 0xF11C60FA3F00058DULL
        },
        {
            0x4024695DE003063FULL, 0x598CE9EB4F1A380FULL, 0xF408BD6FB8546D0CULL, 0x7861FE369BC03045ULL, 
            0xE1B5EA6FFAA91179ULL, 0xA475093EACBE8C53ULL, 0x13138C3AC03286BCULL, 0x04B71912D9A303D0ULL, 
            0xBE0481722286E146ULL, 0xB470C378D4501872ULL, 0x0C474C73A9F4C6CAULL, 0xFB194D97811331B1ULL, 
            0x63DB834C5487BAD2ULL, 0x39D8B7FABF39FA94ULL, 0xF53CFD1C1BF29C27ULL, 0x38E600F261D8EF27ULL, 
            0x419514C47EA03B83ULL, 0xC30C0C6CC4DCD6A0ULL, 0x56B2255A50E7909BULL, 0xA6CB79F43E438FB0ULL, 
            0x718659FEE4A0E8A3ULL, 0x93993B298AF4C9D8ULL, 0x6811F2DFE8F9AA10ULL, 0x930F9B74D1139A0DULL, 
            0x749C8EB8701B18BAULL, 0xBCBCBD313D713166ULL, 0x55F9B70ECE9BCDDAULL, 0x604CDD11403E572EULL, 
            0xAC7AC3BE3A313D57ULL, 0x9E6CE1F05602BF80ULL, 0xE3F93610B478DCADULL, 0x788DE8183013E256ULL
        },
        {
            0xFFE3421B1FAC9A86ULL, 0x078F3BB9B42CF457ULL, 0x19F64C0CEC3CEDDFULL, 0x49E0BDF05D340BFFULL, 
            0x6929EBC35615128EULL, 0xA8E91F8161D4EE31ULL, 0xED19BFE133307F38ULL, 0x5DFB79CC87CB0477ULL, 
            0x63B82BCB9D4607D6ULL, 0x0734192F8C0BDAA4ULL, 0x0A5F4FC35221CE5CULL, 0x27AA0C0AA7CAE9F1ULL, 
            0x292D1D202424E3ADULL, 0x8F81C414709F4C68ULL, 0x8340EBE9AF372D00ULL, 0x01D623A08436E7B6ULL, 
            0x5DDE755D3BE91B1EULL, 0x29CD7B7E23A281C9ULL, 0x823D23845FAB8A96ULL, 0xD55BFC530901D1A1ULL, 
            0x1F305936CAF235B2ULL, 0x325BB0A8149B18EBULL, 0x40ADBCC120BB509EULL, 0x3D13F1A12CB7136CULL, 
            0xEC321B004A943ED2ULL, 0x9649453780207272ULL, 0xFB100A92B0C3EA39ULL, 0x65390006E6C23847ULL, 
            0xCED6BE95890E7571ULL, 0xF812C88AA89D9BADULL, 0x2B0D810335CAC29DULL, 0xA186F1EC78443DC8ULL
        },
        {
            0x6BDE7E3C0C914C59ULL, 0x95FC94F5AEA8E8C5ULL, 0xA40B7208600F21D5ULL, 0x2AE4AF9462BED3E3ULL, 
            0x46290498C39C173BULL, 0xBFC6C1EB0DDB4273ULL, 0xB550E57EF8037699ULL, 0x4DFD7C2B2F12D4C8ULL, 
            0x0952B2C67B66C625ULL, 0xDDD58040A32E81E6ULL, 0x2B2ECF0CD155D4DAULL, 0xCB000FFEA66945F7ULL, 
            0x99D08930C01585EBULL, 0x49CA6348DFBC302EULL, 0xDF1CE4CC0BFB5F85ULL, 0xFD941FA2C240D71BULL, 
            0x335783A0F106E7CBULL, 0x3403C7C5DB575259ULL, 0x057C8FE762B85928ULL, 0xF2A1D221D0B8D4ECULL, 
            0xE57535F34506611CULL, 0x6314B939F57EC8CCULL, 0xB0B54C5658B2B210ULL, 0x7B8BA04D41A611A4ULL, 
            0xDE076C6743111055ULL, 0x657BF971639F0914ULL, 0x3A473EE7A6088E60ULL, 0xCF6EBB61AD094C4CULL, 
            0x20A366CFBFAFD7F7ULL, 0xBCEA34534B5CC27CULL, 0xFBAA6D0BD3E784D3ULL, 0x27A18DEC07A62F5FULL
        }
    },
    {
        {
            0xE2C3CA6FC3F9D45BULL, 0x2A1056BE960D886AULL, 0x7C9A58F6CB4D4AEAULL, 0xA5D2860590592DBDULL, 
            0x740C2B37DD7D0E7BULL, 0x09DF9D548A0AFD96ULL, 0x420B139F06379768ULL, 0xD69949EF18961A30ULL, 
            0x728E2770312F61F6ULL, 0x76DBEEEBA1EF72B1ULL, 0xE11DE1C7446AE222ULL, 0x16AD9E49ED555297ULL, 
            0x635DD728791D15DBULL, 0x264C7E173217DC4CULL, 0x70B3B45E89DAA2A3ULL, 0x627C7654D6B857A9ULL, 
            0x31262899CE72ACFEULL, 0x5BC89BAB32750B0DULL, 0x78CC21C2F15ED88AULL, 0xCB71BC211F75CC61ULL, 
            0xF254525A36417BC4ULL, 0x790AC09EEA0F33CBULL, 0xB1F5B71E3928AEE9ULL, 0xF0556E18CBB67F14ULL, 
            0x412F5ABEAA99D4E4ULL, 0x2971D35576F965E9ULL, 0xCE5D6621374A9A48ULL, 0x38E4BB99AB31D9F1ULL, 
            0x4A0B923C5100CB99ULL, 0xB15CA36BA18BFC59ULL, 0x7E355329B45B604EULL, 0x9C1A6E99AE0BF8C0ULL
        },
        {
            0x6F6053D37C8351BAULL, 0x5F1F4A68A33EC8EEULL, 0xEA43FF31B020EBD5ULL, 0x55DBE6876A30D9A1ULL, 
            0x1938C6B22F5DE838ULL, 0x163D833C57FCFE47ULL, 0xC92AF798F97CB9D7ULL, 0x02795B3B031C0043ULL, 
            0x8866091F2B66B18BULL, 0xBED15F2B5E519CC5ULL, 0xC77341DA06A5CB34ULL, 0xA28BD7F0A911F9CDULL, 
            0x4A44D6EF0741AAEDULL, 0x3552974528EB156EULL, 0x8BA512FB4AEE9E00ULL, 0x355E3C0FFAD8DADBULL, 
            0xE8D9CDD9D2D1C6E3ULL, 0x94EFB4EC8D7DBC33ULL, 0x2A32BFDFBB622252ULL, 0x06FCDEC0B6E01F4FULL, 
            0xFACBB1DBF4E6EDF7ULL, 0xFD3FC6DBA7B1FA3DULL, 0x87D68224BCFC7B87ULL, 0xFADC1F87495026FDULL, 
            0x6606844B9CA45361ULL, 0x4636668018928E76ULL, 0x3A24C76844A132C1ULL, 0xBF83527F30E9BBBEULL, 
            0x372B9F02AB993F24ULL, 0x64816094BD39BC9AULL, 0x2555DBC1268E9FF6ULL, 0xEC4076DB12FA7646ULL
        },
        {
            0x767C4BBF8D9A06AEULL, 0xA679B1CF4D26E458ULL, 0x9019ED9CFC8632F8ULL, 0x645DA8F06D8F0E37ULL, 
            0xCD0970D1695ED1CDULL, 0x4F17A1950F5F86DBULL, 0x2C8BA5E3EA279FE0ULL, 0x0CD7C11189DD8EA3ULL, 
            0x895010914B622D8EULL, 0x4E76C2423C67257AULL, 0xD1C7E9575D8525B7ULL, 0x43F733A382363ED2ULL, 
            0xFEC54FA9B5D6AAB7ULL, 0x17183FA4530EFEE4ULL, 0xB5BCDA574308CBE1ULL, 0x7DBD5C39A51398B6ULL, 
            0x215206F14D3F1C5DULL, 0x68B03A7923261AB8ULL, 0x508320F4C336047CULL, 0xC612EF773B52D2FFULL, 
            0xE6791FF3CE519DD6ULL, 0x4EDE77AB80032397ULL, 0xCC38FEAB19BAACBFULL, 0x06632E385068A83CULL, 
            0xE347C076F3AF701FULL, 0xA36B13DB61F65E55ULL, 0x9494BFCBCA3F6EF3ULL, 0x5E634B078EF4E505ULL, 
            0x0ADB31014C8457E8ULL, 0xD821522A00CA117FULL, 0x88F3A13F75C2E508ULL, 0xE0663EE62ABD2D0CULL
        },
        {
            0x222037D4D0906BF3ULL, 0x1F9E2517AF4E7A85ULL, 0xF1B527568F304C9DULL, 0x54FD32FEEBE1E60CULL, 
            0xAE54E6CEA6B88321ULL, 0x6C9923B0ABBE7A27ULL, 0x88CF9D1076B0B50CULL, 0x45390FF6502FDDAEULL, 
            0x2854EEBE7B9B982FULL, 0x53477EE40BC78C07ULL, 0x8A32441B30921679ULL, 0x275291BB04C79670ULL, 
            0x5311A27CE50B1B27ULL, 0x938FE15D2F4F4DCAULL, 0xBF13F90CC81D9FD1ULL, 0x607A0F071144AD30ULL, 
            0x7157CBB8D8CA1500ULL, 0x99FC312AA4CD35E9ULL, 0x64B9FC965FEB248BULL, 0x5BA602E0A81C3677ULL, 
            0x742A095CB3B6BA11ULL, 0x3C910F6D372968BDULL, 0xA19F1027ACA582F9ULL, 0x3D30CEB1B53E470AULL, 
            0x5EB8261616EF3C01ULL, 0xEE282E7902965EEEULL, 0x7841292A615C9F48ULL, 0xE7FFDFD7EAF64BAFULL, 
            0xB8D7F1A2308FC092ULL, 0x8C3DB66DC69E010CULL, 0xD3BE054DCA4F6CD5ULL, 0x75D817E2D92D4FABULL
        },
        {
            0x7DFE4DB6B9788119ULL, 0xC2E8083DE6FFADE6ULL, 0x2ABAAA7EDF28584FULL, 0x3E507B01D961A170ULL, 
            0x983B12BD7E0ABE4BULL, 0x2970D894A8846FFEULL, 0xC425832A0A4DA5A0ULL, 0x36052035D09E4DEDULL, 
            0x9D7CD79DC21DE9E6ULL, 0xC373921D5FA875D5ULL, 0x6247E4AE93E6B933ULL, 0x07A4247F0BCC9BF8ULL, 
            0x980DFB48E646E3AAULL, 0xBF8B460818FDD976ULL, 0x4A2660EFD033FF91ULL, 0x01E4154F468CF14DULL, 
            0x22BBC33F97EE3525ULL, 0x94AE1EEC1EB5A5B4ULL, 0xA000B5A18886373EULL, 0x3882E137DC2174C4ULL, 
            0xADA8ADC5289ABB9CULL, 0xCA117C8988F765BAULL, 0xB3A15579EEBA0E3DULL, 0x8014BB2E6870A49CULL, 
            0x7A3F2BF3DF8FB447ULL, 0x68650E52385DF7B6ULL, 0x5910478A76967469ULL, 0xAEDCEFAD9A74B4BEULL, 
            0xEA4867DCF48E8E10ULL, 0x5F5EAF9D3B1C1D29ULL, 0xA86B433CB8213D41ULL, 0xB2E2DBF125D53D58ULL
        },
        {
            0x3F3FD4A2F321E123ULL, 0xFBEC433201220F30ULL, 0xD9AD30CF468A20E0ULL, 0xD5A371E0128E7152ULL, 
            0x4133E483DA671440ULL, 0xEE4E03F16CFED976ULL, 0xC7D5BF6A5F029BE7ULL, 0x308710BB6CF9A366ULL, 
            0x33124A90BCE88620ULL, 0xB52991DBDDEC70F8ULL, 0xA156DFD4504FA710ULL, 0x3A933A9B3C601F39ULL, 
            0x06503AFEC6022403ULL, 0x2345380EE860DEF4ULL, 0x87653DE44FA54E0CULL, 0xAB2BDA374BAF228EULL, 
            0x6B0E0D19A01C77F2ULL, 0x50CC0EE26018FB75ULL, 0xA96E197A764151D4ULL, 0x86B409B105906B8DULL, 
            0x3FAA2BFB91E1D71EULL, 0x657D1B6C2650B29DULL, 0x1D6DFF0A45CEFCF6ULL, 0xC5A114F4FB91545BULL, 
            0x6106CEBDB46614FDULL, 0x1D6350953F739D1FULL, 0x30AFEB42695AA2E1ULL, 0xC2FFFE6A0AB7582FULL, 
            0x0FF6426B61BA5DBDULL, 0x4C67BE0D68E76959ULL, 0xC9362E0730918502ULL, 0xBDD586FA6C63E1B6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseGConstants = {
    0x9FA12D83F640C1F9ULL,
    0x2263F10E584460CFULL,
    0x5DD97215229B9623ULL,
    0x9FA12D83F640C1F9ULL,
    0x2263F10E584460CFULL,
    0x5DD97215229B9623ULL,
    0x7ACB25B4AD6F5C4EULL,
    0x7114ECE1D32C25B8ULL,
    0x11,
    0x5C,
    0xDB,
    0xF5,
    0x3B,
    0x91,
    0xF5,
    0xB4
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseHSalts = {
    {
        {
            0x7C0EE131DA62B029ULL, 0x90630009ED9DF4BFULL, 0x1E90F101B82BD010ULL, 0x920BB6AFA8268F83ULL, 
            0x3C430FE2A130FAA9ULL, 0x6B5A46E19ADB32AFULL, 0xDE20A71240786353ULL, 0x4482D252DBD7B487ULL, 
            0x4F92956D59CAD336ULL, 0xE44B083068370D1CULL, 0x34DDBB065D25498FULL, 0x1A11DBAD374CF7C5ULL, 
            0x022B1B2FD3644E3CULL, 0x3ED3B0AC1CB563FFULL, 0x4A9CE1A5F0BD9D68ULL, 0x9003B403D517F24EULL, 
            0x5614149EDB5889E0ULL, 0xFFF3A00F99226527ULL, 0x8CE198288CD1FF2CULL, 0xCD71740750B028A4ULL, 
            0x71A7C4E1BB79FC73ULL, 0xA8509358755C49F9ULL, 0x07719289DFC83F05ULL, 0x6E26B55DD921F315ULL, 
            0xDC0DDD3964F85AF1ULL, 0x7603DBB020FA43D3ULL, 0x172C7A6A7B3C9B6AULL, 0xA586D5F77953C7D4ULL, 
            0xBFA5F9BA732BF7C5ULL, 0x509D9A0CFE5A97EAULL, 0x9414BA68C16CC92DULL, 0xD25FA68C05A2010BULL
        },
        {
            0x9A49A06CD5674E74ULL, 0xD1908367021F3C3BULL, 0x2E0940F129A87321ULL, 0x2EC8B8CFC755A70AULL, 
            0xBD32FDE56201A19DULL, 0xE6610CFF0F1179BFULL, 0xC57C27A9060F8B0CULL, 0x7439E6843203BDD0ULL, 
            0x9B4F756E0AC64D45ULL, 0x2667545F3F0BD0C3ULL, 0x9EBE2578CBB429E5ULL, 0x9CD4A3860679800DULL, 
            0x59487F80C67A36E4ULL, 0x4E00E14239235C6BULL, 0x0DEC649205FE3CA3ULL, 0x150F1CD61CE17FECULL, 
            0x8E916B7E78648A5EULL, 0x98552BA183E055DCULL, 0x136B99E517388A97ULL, 0x6CC2C5B2195B0A97ULL, 
            0x4628AB03C1509B61ULL, 0xFA5637EAF193D5EEULL, 0xBBA9CD753A14C25AULL, 0x0151512B47D65D62ULL, 
            0xBF5E8F6D0D0F3E53ULL, 0x5D1F5BC057538CAEULL, 0xDE608B9D3146679AULL, 0x5E7077292A83C8D6ULL, 
            0xB58F7E345D189046ULL, 0x078D302F7D55486FULL, 0xDA9AEB31ADC998AAULL, 0x05F8789FD28CE798ULL
        },
        {
            0xCEAFC39726F1C334ULL, 0xC01E08991AF4C384ULL, 0xB4194A36A3D8A90AULL, 0x8D19E0DCDC6DBAA4ULL, 
            0x263196A141BFCF9EULL, 0xC9CFABCBEB04BEF1ULL, 0x0D369AAB3AA0398AULL, 0x6BE181BF75B353A8ULL, 
            0xDDC6F5E7D709FD30ULL, 0x88F86002FCCFBB54ULL, 0x2C6EAAF65B4518EEULL, 0xA7A78130C017EB07ULL, 
            0xB3E06C3C46629B46ULL, 0xE11970EAE771E3FBULL, 0x61D0EE2AB28AD172ULL, 0x2B77F1AEB78AFC7FULL, 
            0xBEEAC351794ADDF8ULL, 0x9C205FFB0162AE28ULL, 0x5DD11842531FAA31ULL, 0xEE0DFC9B2BB11F1EULL, 
            0x44ED64C4A3342B30ULL, 0x70790C2741D01CDFULL, 0x61E79E235A87586AULL, 0xD0DDC5BD76DE9D88ULL, 
            0xDA9062DDED1A32BEULL, 0x1882C9F4361BD387ULL, 0x97170BD0DE1693A4ULL, 0x045A7BC94DB83C73ULL, 
            0x89F9DCBBB82DEB21ULL, 0x0B90C98C6E6D0B5AULL, 0x80AE4060FC6D1657ULL, 0xF66AEB7077895551ULL
        },
        {
            0x8D8E4D6A465A6586ULL, 0xD4A79968144A1EE9ULL, 0xE171757741916906ULL, 0x841EFBF0A47706A9ULL, 
            0x23340130024E3355ULL, 0x9E439853982F7F19ULL, 0x96938ABE860C5626ULL, 0x5931484E6939318EULL, 
            0xEF886491346094A6ULL, 0x22FB0AB16B5F6F94ULL, 0x099155DF68CE468FULL, 0x3406EDFC44F68CBCULL, 
            0x41E8BBF4624CA784ULL, 0x224EAF6F5B8845E1ULL, 0x36426A885A7AC5F5ULL, 0x7F93FE1430334D40ULL, 
            0x1961E47BD7EF3D83ULL, 0xA89DC6A0539F8FA9ULL, 0x576DDB8309CA5F81ULL, 0x663D0E57CE642AB4ULL, 
            0xF92857EDD6F6D527ULL, 0x99432A10352866C6ULL, 0xA16BCF88E41B1FB6ULL, 0xD0306C8E27BA4106ULL, 
            0x8B2C7DA0C3DF0666ULL, 0x03924C91BBF46C21ULL, 0x114A7DA3A99708A9ULL, 0xAE72EFB6287023C1ULL, 
            0x148C6749624FAF1CULL, 0x40F11A62A400BFCAULL, 0x588A397F23742242ULL, 0xA4336D13075904E3ULL
        },
        {
            0xADDE6C839F6D8CE5ULL, 0x386D36F2131DC6F8ULL, 0x3CA16ED7E36C5D3BULL, 0x81494D5494CF3C1BULL, 
            0x38A4755F70C4A7C8ULL, 0xA804A060F7B3A8EAULL, 0x5E976FEAE59D1DC3ULL, 0xBC393866FD15BB36ULL, 
            0x8DFDD05C7A706716ULL, 0xE87D37D71C53C986ULL, 0x8CDE3C48448B5519ULL, 0x624DBED9A5CEBF2BULL, 
            0x017F00E22B67CA2BULL, 0x5B63763659FD4EC1ULL, 0x633764CB601BEBFDULL, 0x2BB3109494E9469CULL, 
            0x64DA760719F6490BULL, 0xC355F5D62C3E5821ULL, 0xE020F8D88C8B1AF7ULL, 0xD90C6D099E0ECAF9ULL, 
            0x871EB203D3891600ULL, 0x3466EB9892C3C638ULL, 0xBB1733996AEFA389ULL, 0x17D81969DF2EF62EULL, 
            0xA49D0DEEBEAB0AD4ULL, 0x819457248A20596BULL, 0xC0B03766EBEF00BDULL, 0xE33E57405BCFEDE7ULL, 
            0xEB6E983F0874E247ULL, 0xCF00BA89679C34DFULL, 0x03CC5AF8AAB24415ULL, 0x98C5CCA752A6B223ULL
        },
        {
            0x80AE6B0107559219ULL, 0x4794563762B8FE80ULL, 0x02812A0D86377408ULL, 0x5C47A99C1D0F4DC2ULL, 
            0x508C28B8CAAA1445ULL, 0x10DE3BC8A72C89A7ULL, 0x88B0432356CDDEE9ULL, 0x18F5A64CA441EE38ULL, 
            0x62E9DCEEC73A7505ULL, 0x37404F4C141F4EABULL, 0xCA3A3C4DC2178A69ULL, 0x207080DA399EB473ULL, 
            0x97C31F771EA9E93CULL, 0x1771949FCF17267EULL, 0x600670793AFDED9AULL, 0xD95D1C8F057F3762ULL, 
            0x8945D95FB6D77DC1ULL, 0x44EC3C4180DA1607ULL, 0x2827C98C703E2CADULL, 0xDFE0C1FA802D5F64ULL, 
            0x4E0DF53418323D7EULL, 0x63B707F97A12C2D4ULL, 0xA827C7DF4D6CA85AULL, 0x257848CF262E4B71ULL, 
            0xE107CD9127782D1DULL, 0xEAD86753F803E7B4ULL, 0x5D285617FB3C22AAULL, 0xB329D3396225F48FULL, 
            0xC4FC16727B856FB0ULL, 0x32D5E9ECFBAD6BC5ULL, 0xFAE12FBF5F169772ULL, 0xEC8EC0F1F5F1C25CULL
        }
    },
    {
        {
            0x71B5FA25119B24E3ULL, 0x9515120520567222ULL, 0x61D1AD1CC7FAEE4EULL, 0x6AF02E40BD954573ULL, 
            0xE389CF5CE4F9F81AULL, 0x60831B453206D0ECULL, 0x6BCCEF386638ED8AULL, 0xE629D159B584F7D6ULL, 
            0x92863FEAD7DC48F0ULL, 0x3946CD4D6D267135ULL, 0xDB9D9E77DED6AA2CULL, 0x107F0A1DAD8F28F8ULL, 
            0xC5B8BDA29B823CA4ULL, 0x1717764C01560245ULL, 0xE960B63DFCC4849FULL, 0x0FFEF384BF91CC71ULL, 
            0xD92DC4873B30D781ULL, 0x6CADB1DC065ACEFCULL, 0xF818D716DA244473ULL, 0x0BFC21718EB55C2FULL, 
            0xEC4176AD81B3018BULL, 0xC969984E68E026E3ULL, 0x85E6AB69D3EF163AULL, 0x723DEAD90AC6D040ULL, 
            0xEF05BD8575D11689ULL, 0xCCA70E3EF0AB8874ULL, 0x40023A7FFC079A5DULL, 0xC39738658F028BB0ULL, 
            0xEAEB9E5EB103F8C1ULL, 0xB348FC87C5D778E7ULL, 0xBCD372A77BAE3C9BULL, 0xB9F5A19E935B1CA7ULL
        },
        {
            0xD46E02320FAC6AC4ULL, 0xB0DBD686A2504A3FULL, 0xE8E37957FB8BB86FULL, 0xE54D117E892298B9ULL, 
            0x598F0F9C6601F675ULL, 0x3F4331181148DAF6ULL, 0x8383AB91DA2C5AEDULL, 0xD70FD8B94E4C5975ULL, 
            0x6B92D1F387D5CA0DULL, 0xB6EF6B1843BEF4BAULL, 0x8BEE974925F18238ULL, 0xCFF898940758F845ULL, 
            0x4D38EF744EB4A58EULL, 0x1A2071889709F6A7ULL, 0xC21CE2DFC0B51DC6ULL, 0xF3F097AB58072B48ULL, 
            0xF596263FCA7DCCE2ULL, 0x6D36BB4345C80BE2ULL, 0x8952BF14A1DC6CF6ULL, 0xDAC46E9745876215ULL, 
            0x48DE1CC1B0E85CD2ULL, 0x14102623EE434044ULL, 0x6C1D67D35190BB21ULL, 0x9AF70B2C80083931ULL, 
            0xF922E9FFA8747E7BULL, 0x9ADA8BC7DE8B4AF7ULL, 0x110C54C126D0A69DULL, 0xC6DC40C2D94ECCEBULL, 
            0x1FB2D2374198CF2CULL, 0x2FD52F56046BA859ULL, 0xCE5D1741C37FF1DCULL, 0x76B21EC5D264F2C9ULL
        },
        {
            0x400FB628F5546F36ULL, 0xC40EDE91351B7BACULL, 0xC03A583D3FA040BDULL, 0xB2362E8BE637FEE6ULL, 
            0xCA50C38F53374E0BULL, 0xB8CDEA9583DC0EB3ULL, 0xC9638AC5E45130E4ULL, 0x4DFE527196BF493FULL, 
            0x23DDB94509A1F92EULL, 0x8DF2C7B271851C9DULL, 0xCEA7FDE762D0A340ULL, 0x75EDE3F24B443122ULL, 
            0xCD5B9EE72D6632A3ULL, 0x1B12173C6DB8254AULL, 0xED30C0F0D9C2B011ULL, 0xA7EFA6D3F4BD699EULL, 
            0x73BCFF71BE9F7843ULL, 0x66F6B59B436A8AC4ULL, 0xCEFEFDFAAD7A8FE6ULL, 0x7BBDE01D452E20DEULL, 
            0xA0C11699A45A71EFULL, 0xB20F365FD6AB6C42ULL, 0x93B0A295880205ABULL, 0xC7F3BB59EA828E6AULL, 
            0x3246E5F34BE5DF0DULL, 0x62420513B6527521ULL, 0x6E2D47F8AE7A99E8ULL, 0x86FB3F2B52474FD2ULL, 
            0xF596BE5A7B2B7A2FULL, 0x4028329B5AC7BC40ULL, 0xEF59E864D97CC411ULL, 0x56A31461132476B4ULL
        },
        {
            0x4DD011EB2E1F8BDFULL, 0x7EFB92752CFA1047ULL, 0x5427BFB432DDB0B7ULL, 0x97232612F3CAD9A1ULL, 
            0x55691545BC9BCF2AULL, 0x682DE169E770E5AFULL, 0x5F2662E8C04CCBD1ULL, 0xC4F15A7C6266D258ULL, 
            0x8EB5579A26D1D014ULL, 0x90641639CB0C1A44ULL, 0x1FCED41C7C572C7DULL, 0x4C6E1411FCF19660ULL, 
            0x75A5DED8ADE08A5EULL, 0xACE3561AC7077E3BULL, 0xCAFFD4AE9DB3CAD7ULL, 0x49FFC89B44098ADBULL, 
            0x39B3A867A36ECDCCULL, 0xE7D42D68A8CBB139ULL, 0x3EBEA2BCA5532040ULL, 0x8890320430D84649ULL, 
            0x4A698F841580B5E5ULL, 0x9C3D812336BFB8A2ULL, 0x0313C1ACD8519A0CULL, 0xFEFBD46DF3F6E00BULL, 
            0x4C8779FAE06F268DULL, 0x0229836294F50ED9ULL, 0x167E191F61A2CE64ULL, 0x632B60B626DC0512ULL, 
            0x8EF5891E19C34A19ULL, 0x19AFE5D49FBB6120ULL, 0x6A78EE9A2312B47AULL, 0x552656A29E76AA7EULL
        },
        {
            0x4227055E38D5CCEEULL, 0x3AD7B82185D59AD0ULL, 0x9EC0E845216EB5ACULL, 0x1E44594C2EA824D3ULL, 
            0x084E5F0F02223FC7ULL, 0x1D215FC82A4C7A91ULL, 0x8E474415D2929912ULL, 0x7D2BE3A16DAB7534ULL, 
            0xA51688194AE815DFULL, 0xA1146D163AE567E8ULL, 0x3B74004DD4AA0B92ULL, 0xA912E3D53EA2C306ULL, 
            0xAFE247573D774A52ULL, 0xE142F399149DE16EULL, 0x01D36678E831C210ULL, 0x0111C79093BF4BDEULL, 
            0x16E513BD4106C720ULL, 0x58F0BB0868E8C4B3ULL, 0xAE30B6624DAFDD0EULL, 0x698A1979E8F3B1EFULL, 
            0x124D1DE978B50DC8ULL, 0x0EF6C93D8D7C2D4AULL, 0x6EB6A7085C38E80EULL, 0x99E71D14FF6713DDULL, 
            0x25DEA6E66DC83A38ULL, 0x437EC1C8A89DB6ABULL, 0x2B0F9F8E178A20A4ULL, 0x136D782506E05DC8ULL, 
            0x4B4FA71F177618C2ULL, 0x86305A3C3FDAAF83ULL, 0xC9C4A482D2BE4B63ULL, 0xB638C5A407762BD4ULL
        },
        {
            0x769F7A0C31E70F43ULL, 0x4A5D10F2DAECA896ULL, 0x18826C17892C5C9AULL, 0xE636B4FBDDB3384FULL, 
            0x9ADA574559575188ULL, 0x47E66207F79AF035ULL, 0xE3E31FCE4A2D678CULL, 0x527C1901CDF96C1BULL, 
            0x224DF5F3742CB10EULL, 0x73E6D7683CEC6797ULL, 0x52C09B71F8D97C79ULL, 0x2D1780F97D5BBE33ULL, 
            0xBBA2F1F42CABA1DBULL, 0x3C6704B10ED7DB71ULL, 0xD4B3574DDC9B6475ULL, 0x61F115B2FCF805AAULL, 
            0xD9855CE180D472F4ULL, 0xD6A1015C26DC3D77ULL, 0x6117D28FB3EB92B4ULL, 0xD3AA828591DAE4B2ULL, 
            0x2F0ED64D7B053C23ULL, 0x4F00533986BDC704ULL, 0xF7C697D35887C15CULL, 0x06E7830DF94AE984ULL, 
            0xA100F4BD8BD95345ULL, 0x435F2A9E8D6261F1ULL, 0xBC15204EB3856673ULL, 0xDB8BE22450025DB7ULL, 
            0x3508D9AB559DF8A2ULL, 0x20884A3B5343994EULL, 0x083085188743C295ULL, 0x66A4842FC8950830ULL
        }
    },
    {
        {
            0x06106BD1D9858D74ULL, 0x8EB7E4E7224DF849ULL, 0xC12689374A9FEF0BULL, 0xBB3AAF095557DD9AULL, 
            0xF2EF6830025D53AAULL, 0xA82564B630D91715ULL, 0xBC427261C6427354ULL, 0x0242BBBE419A9703ULL, 
            0x8A45E82AE2EC037AULL, 0xA80B7CB4FD9418C7ULL, 0xB7A31DDF89DCDA61ULL, 0x76A5B548952B0A22ULL, 
            0x2438739E401B1972ULL, 0xF0A1B49E7B214ADDULL, 0xF40BC3076EA0F99EULL, 0xF58E5F227D24E3C8ULL, 
            0xEEF1BFAFAAFF4D8CULL, 0x6DA768F50E829473ULL, 0x093D93D0AB2A25D9ULL, 0xC8345007B9C93191ULL, 
            0x754AE979CD9653E5ULL, 0x6B0F195D0FF1688BULL, 0x75A3BFC4D2DDC8E7ULL, 0x2C9D9D108A10C265ULL, 
            0x309FDBEF34BE386DULL, 0x2E94E683A0F4FE2DULL, 0x9E4F05006A5B8EDDULL, 0x5930D40CB9C1ED85ULL, 
            0xAC25784D4F74E8B2ULL, 0x74E160ABC1D0BF6AULL, 0x4375C0D7214564B5ULL, 0x6E3AB9FFB3FB1F40ULL
        },
        {
            0x5E12025ACC9B8A57ULL, 0xE4A7D8517FBB7B54ULL, 0x9FAB6D0665555FCEULL, 0x3F489CEAAA20F847ULL, 
            0x5799F9AF84F804C6ULL, 0x663032514EA16077ULL, 0xCB2A0ABB10BA84FFULL, 0x06B279C6C040D32EULL, 
            0xEBE617FDDC4F0797ULL, 0x1FC16414EDEEDC8EULL, 0x7A3D97F80695FBD1ULL, 0xB0EA2BEA926357ACULL, 
            0x388B38E9DF5836B9ULL, 0xFC183D933E791D01ULL, 0x485181B46BF6AB44ULL, 0x3B5B1CE6390D2004ULL, 
            0x98C599D3CCF36AFCULL, 0xECE1F655C757DF99ULL, 0x9EBA4F22C99D726EULL, 0x051535DDF618B45BULL, 
            0x31F7553907330008ULL, 0x4C50ABBAD4462636ULL, 0xC4BD3C243BC57087ULL, 0x6D5303A754CCA880ULL, 
            0xF6753EB00F17C48EULL, 0x1EAB3324B53B5217ULL, 0x7EB7D9DF2ACE4C85ULL, 0xF4CB6002AF5AE875ULL, 
            0xA1D721C6F16EF72FULL, 0x9F883CD4F00225AEULL, 0xA5BACB5B6FC264A6ULL, 0x8860D4F5906DD585ULL
        },
        {
            0x1EFEF7BC9D761A45ULL, 0xBC0827D878AD72B9ULL, 0xD46165FD5E5B2F5DULL, 0x352C8A4E24998FB1ULL, 
            0x047D8699A526AA77ULL, 0x692AE004D08A28CFULL, 0xC0B24BB6CC3D38E3ULL, 0x86CC9F3D70D93AEBULL, 
            0xC78AB1F95921DEA4ULL, 0xE48069E519EBFB3FULL, 0x7CE8D0B2E93BCA55ULL, 0xF8777D19C3BAB4F5ULL, 
            0x10F4F79A8CBB6D02ULL, 0x88A15EED375CDC0BULL, 0x4A465530EC460E0DULL, 0xE1B3D0317F923074ULL, 
            0xBCC3E49856FD586AULL, 0xF78F3036C1E53BFFULL, 0x9265148C13F50B05ULL, 0xE3FC8DB41AFDFD3AULL, 
            0x9F7F089C4167387AULL, 0xC6893DA3CB42BEF4ULL, 0x07E974CB6F86C093ULL, 0x24B9612C9A008F1AULL, 
            0x5DFAE102B628659CULL, 0xBF14BB2241387DA4ULL, 0x9F04876D95BF3346ULL, 0x8534D3D91BBFA54EULL, 
            0xE093EFEDD6561509ULL, 0x60A601443B5E00C4ULL, 0x84DCF5E1C1EB5FAEULL, 0xD9C299C1C169CBC3ULL
        },
        {
            0x8FDE4A713212C41BULL, 0x8AC1B60A18148AEFULL, 0xDB8CF0AFB2491BA5ULL, 0xDAB03675FFAD44FBULL, 
            0x9C8A1BCF49A39704ULL, 0x2471633FF42C36F2ULL, 0xD95F6D144845000EULL, 0x2BB5D4381C6C6DD3ULL, 
            0xA9CD63968BB39BA4ULL, 0xE4EEABEB6389F896ULL, 0xD9E1238480F05400ULL, 0x7A979BDD003CB376ULL, 
            0xECD8BAC443F901FBULL, 0x31C10CA27FEEE80DULL, 0x2D444ACA2C7EE1FAULL, 0xF1DF1359CCB1DD3FULL, 
            0x90B699D654097E02ULL, 0x4DAEF015D38ACDF4ULL, 0xE5C4613D4CFA0817ULL, 0x5EEE6AFF72C28AFDULL, 
            0x1B66821625CAA88CULL, 0xCA61A068960DA2F9ULL, 0xB73735864AF9B985ULL, 0x1C3531EA0CFEF032ULL, 
            0xEEDBACBC3A43C895ULL, 0x578EAEB9CE947B15ULL, 0x48C37F9F13B6346EULL, 0xA1DBDAA433969367ULL, 
            0x1B821E80671EFA63ULL, 0xA0DB08C1D549ADDCULL, 0x144D7E1CDC3A63E5ULL, 0x9FEDE3031E4DE84CULL
        },
        {
            0xE951304A2CC74FD7ULL, 0x75AD7F4C4023863EULL, 0x9654785181DB37EEULL, 0x042B6AE83980ED98ULL, 
            0x6038A8FB310EE4ABULL, 0x6DE9A6EE2237BD5BULL, 0x6CF062AA1785711BULL, 0xD558D2F19DEFF8F5ULL, 
            0x2D3C9495A1F161F8ULL, 0x1C928F9EC73119F7ULL, 0xF97D6A723B8B5C4FULL, 0xD01562A431E71438ULL, 
            0x110F907C2EF32775ULL, 0xA7243B8674CD213EULL, 0xABB61FE58F877D1BULL, 0xFAC44F5F18ED5E37ULL, 
            0x39256200B01CDAC7ULL, 0xF19B0B8A7739944FULL, 0x2571BBB2974A4D2CULL, 0x8E7A0DA042B6AA46ULL, 
            0xF9CFCD62ADD82866ULL, 0x9A577BC920423C2CULL, 0x1FFD0C71E5E7C13FULL, 0x5556E881A2517D15ULL, 
            0xD84A7337111EF717ULL, 0x25BE6F6BE1C5F25CULL, 0x11C5AE63F7B92463ULL, 0xFE6383228A9FB539ULL, 
            0x75AF173FACC819D1ULL, 0x154A51A0C219B07EULL, 0x2C6B371B74555B0AULL, 0x630FA5BEAFCBFEBCULL
        },
        {
            0xD2271A32D77F2226ULL, 0x3926540F37D3BC02ULL, 0x21EF37CC1A7A4712ULL, 0x1D2F0F0C83E6449CULL, 
            0x30B2AA8F1DB366B6ULL, 0x9C8C44DB2D40F5F3ULL, 0x96AC6B7D3F35F5D8ULL, 0x37CA3F89134C666EULL, 
            0x0008F42BCD6682E9ULL, 0xD6F1FF06F46380D3ULL, 0xCAD6D1592A4687A1ULL, 0x624127B693CCF29CULL, 
            0x57C11F59BD385022ULL, 0xB6A5A563642585CAULL, 0xBB7E97EA82AFB8E8ULL, 0x00CD67D9FB08A48CULL, 
            0xE8168FD82C253612ULL, 0x67012082F31B483EULL, 0x2009F78CE465B549ULL, 0x014464471ADB8B8BULL, 
            0x2E492E6D37E878F7ULL, 0xC0367E69F3D0D71BULL, 0xC0D605CD4581D70BULL, 0x012C32C930EE3B69ULL, 
            0x440C94E952019660ULL, 0x5D198F2E5CC41A1EULL, 0x21A0DAB849929894ULL, 0x9292BBAA90E33ACCULL, 
            0x80866325C5E40260ULL, 0xE17C3E469818DD79ULL, 0x3B970DA16F4406FEULL, 0x9F33EDF4A4D149E1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseHConstants = {
    0x97E2CFA367019056ULL,
    0x612D0419A46DB922ULL,
    0x76D7481943668118ULL,
    0x97E2CFA367019056ULL,
    0x612D0419A46DB922ULL,
    0x76D7481943668118ULL,
    0x44E026CD339C9716ULL,
    0xDBEB8BE4A56A7B23ULL,
    0x23,
    0x6E,
    0xFE,
    0x90,
    0xD9,
    0xE9,
    0x8C,
    0xD6
};

