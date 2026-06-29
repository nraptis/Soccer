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
    std::uint64_t aPrevious = 0xE94779E93BABE4CCULL; std::uint64_t aIngress = 0xA11406ABBE8CB6B7ULL; std::uint64_t aCarry = 0x8C59022F09711EBEULL;

    std::uint64_t aWandererA = 0xAD97146B96ECF947ULL; std::uint64_t aWandererB = 0xAB35347C8EB3B0BCULL; std::uint64_t aWandererC = 0xBFDCEF9547B70E69ULL; std::uint64_t aWandererD = 0xDFCC6CA9F36B25FCULL;
    std::uint64_t aWandererE = 0x8DDA31BBC0EC4E10ULL; std::uint64_t aWandererF = 0xCE21DE59EC97077DULL; std::uint64_t aWandererG = 0xA4E0AB3DAF054997ULL; std::uint64_t aWandererH = 0x9B4F0B546FC4820FULL;
    std::uint64_t aWandererI = 0xCEDA4A94E840D3C5ULL; std::uint64_t aWandererJ = 0xE2FF5E87352C5343ULL; std::uint64_t aWandererK = 0xA744A2A9A15BABC0ULL;

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
        aPrevious = 13963998336845383048U;
        aCarry = 17632809084641938295U;
        aWandererA = 11357178584516704227U;
        aWandererB = 11011026946818831064U;
        aWandererC = 17143656014864978555U;
        aWandererD = 14134885613533711250U;
        aWandererE = 15507323012585508939U;
        aWandererF = 13331823768891446952U;
        aWandererG = 10840514764491990709U;
        aWandererH = 14051462165422361575U;
        aWandererI = 14931983195901123378U;
        aWandererJ = 17414283265120668649U;
        aWandererK = 14503677643421270647U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0xCF97886634590119ULL; std::uint64_t aIngress = 0x8CC023E6AA05C621ULL; std::uint64_t aCarry = 0x869F3BA88ACED8CEULL;

    std::uint64_t aWandererA = 0xF2DB9EAC6001E66DULL; std::uint64_t aWandererB = 0x87BE1BB2E401D812ULL; std::uint64_t aWandererC = 0xD77F02D4E71C138DULL; std::uint64_t aWandererD = 0xF8347BE3A89F1406ULL;
    std::uint64_t aWandererE = 0x8E6373F6E365C88DULL; std::uint64_t aWandererF = 0xDF708166FCA8C9F0ULL; std::uint64_t aWandererG = 0xFA4246FA323B6BC9ULL; std::uint64_t aWandererH = 0xBB8A6F069FEC09C1ULL;
    std::uint64_t aWandererI = 0xD788333D6617D05EULL; std::uint64_t aWandererJ = 0xE324F62127A01281ULL; std::uint64_t aWandererK = 0xB5D33750908D1E85ULL;

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
        aPrevious = 14462682601234261695U;
        aCarry = 12785307201992751590U;
        aWandererA = 17595366580253789796U;
        aWandererB = 18406105608213206456U;
        aWandererC = 9484285606875207009U;
        aWandererD = 13926888512129157551U;
        aWandererE = 15934274972574108666U;
        aWandererF = 12542478881146008212U;
        aWandererG = 16017314856293183435U;
        aWandererH = 12513412333686746572U;
        aWandererI = 17721886170080273594U;
        aWandererJ = 14491654394128055454U;
        aWandererK = 16871922892425998934U;
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
    std::uint64_t aPrevious = 0x9C81715C04E955B6ULL;
    std::uint64_t aIngress = 0xCC353BCE23BD12BEULL;
    std::uint64_t aCarry = 0xA3E8E68AB23BDB51ULL;

    std::uint64_t aWandererA = 0xD9763812DD509E2EULL;
    std::uint64_t aWandererB = 0x985A99E6BDD40ABFULL;
    std::uint64_t aWandererC = 0x97DC744898FD3DDCULL;
    std::uint64_t aWandererD = 0xF325984EF4684896ULL;
    std::uint64_t aWandererE = 0xACE194D82617F23AULL;
    std::uint64_t aWandererF = 0x8FA11B28F11777CEULL;
    std::uint64_t aWandererG = 0x95591DFED55E0905ULL;
    std::uint64_t aWandererH = 0xAF0AA8F96CFA8E7BULL;
    std::uint64_t aWandererI = 0xBD09978E18FC3AEBULL;
    std::uint64_t aWandererJ = 0xD8C7B76F33223E83ULL;
    std::uint64_t aWandererK = 0xBA45B2BBD7C21F0AULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneF);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
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
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
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
    std::uint64_t aPrevious = 0x9188042A3C14E29CULL; std::uint64_t aIngress = 0xAAC3AF66FD6DEE17ULL; std::uint64_t aCarry = 0x8F5A6FDCD06ED61BULL;

    std::uint64_t aWandererA = 0xD7156AC0F80AB651ULL; std::uint64_t aWandererB = 0x84B2910B84229A81ULL; std::uint64_t aWandererC = 0xBF3D53A1143EB2B5ULL; std::uint64_t aWandererD = 0xB61A44C9DF05D329ULL;
    std::uint64_t aWandererE = 0x86E34CD76EDFD138ULL; std::uint64_t aWandererF = 0xA63BA96398BAFA01ULL; std::uint64_t aWandererG = 0xF7971C3E045D3F08ULL; std::uint64_t aWandererH = 0xBAD7CA8888EB67F0ULL;
    std::uint64_t aWandererI = 0xF9C484A090C85D43ULL; std::uint64_t aWandererJ = 0xEF6C116DD52D00F0ULL; std::uint64_t aWandererK = 0xA8947ABDF6A93CB6ULL;

    // [seed]
    {
        aPrevious = 15803473141857258108U;
        aCarry = 12636199629835395810U;
        aWandererA = 14274366384907101541U;
        aWandererB = 14930963995781620274U;
        aWandererC = 15482456894075773256U;
        aWandererD = 13312525369017856434U;
        aWandererE = 9596294950137634791U;
        aWandererF = 9626661259467783809U;
        aWandererG = 10010023575087397982U;
        aWandererH = 11836518725570132348U;
        aWandererI = 17754912681453592314U;
        aWandererJ = 16863276654366567810U;
        aWandererK = 17932114150286118501U;
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
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 3, 0 with offsets 6745U, 1952U, 1340U, 7722U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6745U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1952U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1340U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7722U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 0, 1 with offsets 6365U, 819U, 7819U, 5024U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6365U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 819U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7819U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5024U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 3 with offsets 429U, 2061U, 4463U, 4386U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 429U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2061U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4463U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4386U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 2 with offsets 4148U, 7332U, 7088U, 7685U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4148U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7332U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7088U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7685U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 520U, 1310U, 1710U, 897U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1310U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1710U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 897U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 3, 1 with offsets 764U, 2033U, 1682U, 1305U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 764U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2033U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1682U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1305U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 0, 2 with offsets 857U, 382U, 1459U, 1481U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 857U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 382U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1459U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1481U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 0, 1 with offsets 231U, 1227U, 1906U, 1808U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 231U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1227U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1906U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1808U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1801U, 755U, 739U, 861U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1801U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 755U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 739U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 861U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 1 with offsets 3251U, 161U, 2119U, 1211U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3251U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2119U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1211U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 0 with offsets 2603U, 2600U, 54U, 6578U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2603U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2600U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 54U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6578U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 2398U, 507U, 5334U, 1993U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2398U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 507U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5334U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1993U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 3 with offsets 1604U, 5285U, 4881U, 7661U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1604U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5285U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4881U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7661U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4600U, 2347U, 2909U, 2844U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4600U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2347U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2909U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2844U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 743U, 2013U, 394U, 903U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 743U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2013U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 394U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 903U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1470U, 451U, 1131U, 1318U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1470U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 451U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1131U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1235U, 312U, 1333U, 1780U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1235U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 312U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1333U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1363U, 551U, 1016U, 1500U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1363U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 551U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1500U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 [0..<W_KEY]
        // offsets: 496U, 1323U, 492U, 742U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 496U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1323U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 492U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 742U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseASalts = {
    {
        {
            0x71609AD6C02FA5F7ULL, 0x0A42ECFC24509302ULL, 0xEDDC48DF7D25D3F0ULL, 0x6FB20A705EB8F862ULL, 
            0x155F447B92013C30ULL, 0x9FB8BBE84D24CB5FULL, 0x1CFB1E7F0BBCAAD1ULL, 0xA762BBFA369DAB68ULL, 
            0x7BDF5D8358D642DBULL, 0x9C5CB31CFD03E92FULL, 0xBA3C6B3A10C73ABEULL, 0x066208144AC6D2FDULL, 
            0x4FAEEFE00A496654ULL, 0x96918FE83AA15642ULL, 0x070177E7BC11AB47ULL, 0xE62A4B5EAB26F228ULL, 
            0x2B02F672492615CEULL, 0xFD08F060B97599ECULL, 0xD437172BF9DD5603ULL, 0x5EE6B14B125F82C2ULL, 
            0x7B6FC9449F84E6B0ULL, 0xEDD75FCB98D1740DULL, 0x829B946DC6801DF5ULL, 0x655996D535EBB122ULL, 
            0xDBA96034A6FB8405ULL, 0x12AC9A0FD39DE61FULL, 0x4F6F562893E5255BULL, 0xBC5DDB4330FB3759ULL, 
            0xF9B6AB282422A23BULL, 0x2654928EA4D9D96AULL, 0x3CFDFE3484647393ULL, 0xA3A7B63648F007CCULL
        },
        {
            0x2C783F3A42D3D9BAULL, 0x2D1DF165258ADBF2ULL, 0xCCE0D21FEE5C33B9ULL, 0x08B173F646B0B249ULL, 
            0x87CE8E5DB91A7640ULL, 0x968792CD56AFC388ULL, 0x90DD9C2EDA47932BULL, 0x42BD7E3E36E71B55ULL, 
            0x273D2C5BDAE987CEULL, 0x211E972078E97526ULL, 0x94C567170DE993BBULL, 0xB1BDFDAB5B03E12BULL, 
            0xDC1AE4F0C9A0B07BULL, 0x71BA1F10731E592CULL, 0x8466F9FE32845EB4ULL, 0x84FC2CE512ED154FULL, 
            0x4018881D5102D729ULL, 0xB3C9C6CF323049DCULL, 0xC917C9F24E4D17E4ULL, 0xE6A219F19C65F82CULL, 
            0x06E7774CBDE43996ULL, 0x0321492524AC43D5ULL, 0x3A27DBA66938DD5EULL, 0x9BB936B97FD2FB8EULL, 
            0xF77D87C3ECA9BCC7ULL, 0x9BC5DEAA66C67534ULL, 0x03E03525E4F36694ULL, 0x59840837F6EF4276ULL, 
            0x7902732258AEC0D0ULL, 0x1BD52E26E54F0CEFULL, 0x813A1828037433C4ULL, 0x2F7E7CCDE74CA90EULL
        },
        {
            0xD9B871DF5E61BE3CULL, 0x8B28636D313721CBULL, 0xE439666269B4C07DULL, 0x8B3ADFCD05AF9BF2ULL, 
            0xE7C9C05D280F1F04ULL, 0xFD54A983BDDABB17ULL, 0x3E9D7C4366A1C6E6ULL, 0xF5D7C924EEA6EE68ULL, 
            0xE7DCB051DD669818ULL, 0x57682A5BFE8CD05CULL, 0x05F7F8711474CB3BULL, 0x1DD11378A3EB5B84ULL, 
            0x89D7DC02903959A9ULL, 0x05AB2B0A3B16DA14ULL, 0x4B339BFE24D5CA8EULL, 0xE8B121146987FF7EULL, 
            0xD9A8CE731B28C674ULL, 0x34CC6286ADB227F5ULL, 0xB1E9A3188B350053ULL, 0x73A233982B2AFC77ULL, 
            0xD318A172371B5962ULL, 0x4B9D5F41BF1C8A39ULL, 0xE2D2643925F57D63ULL, 0x2A074545054AD870ULL, 
            0xFEBE16B0D420EF77ULL, 0xDFF22AFF796E3FE0ULL, 0xC4C744338A7BB238ULL, 0x50D4C5323CFB4995ULL, 
            0xAC8B533E4B73F206ULL, 0xC90817C0A88C6C4DULL, 0x69505AFAB45790C0ULL, 0xEF5A95AD2C1188D7ULL
        },
        {
            0x74E5BBF8260E4703ULL, 0x410A535ACB81A550ULL, 0x63482076E7164BDFULL, 0x2A6D875209850133ULL, 
            0xB5C1016929B196F7ULL, 0x03B5838480360A8AULL, 0x8373BB6E2139BBF3ULL, 0xEA90732E2A52BBD5ULL, 
            0xAB4C3C4F3139180BULL, 0x1357932FE88F98EDULL, 0xC3811E15DAD1B0A4ULL, 0x15971CB87708D63BULL, 
            0xEC1CFE98A6B61E8FULL, 0xA9829EB2DD6E1DC9ULL, 0x21B66BE186181EF8ULL, 0x4BC3A7581EE5BBBFULL, 
            0xB4C6B86F45416D14ULL, 0x440D19D0BE89BAAAULL, 0x15E20B1D6769C362ULL, 0x2243C9EA6853472AULL, 
            0x43185D7858EC5083ULL, 0x655D26B9F99C8D4FULL, 0x6786C825B2A69605ULL, 0x2C98E258EFA9A8FAULL, 
            0x9597A13B7B226D64ULL, 0x5E6D758FEF5C1867ULL, 0xC89E914221C948ADULL, 0x7C20930F12BDFBA8ULL, 
            0xF9DBB8415577488CULL, 0xF99ABCA6906E0A62ULL, 0x790927F240C89B0CULL, 0x26B1272907FF5ECCULL
        },
        {
            0xFFCF219EA93A157EULL, 0x147D84920B40D545ULL, 0x22D6073B1894F081ULL, 0x300E87198FEFC54BULL, 
            0xD017B0FDAFC871F8ULL, 0x4F6F3C667029DB4EULL, 0xB4E0171D641478ECULL, 0xF677A82264A67973ULL, 
            0x54DCAFC6A5720CBDULL, 0x4644ABA5317C4C07ULL, 0x59ACF15EB471EF7FULL, 0x7076D049AA43419EULL, 
            0x1BCFA011FEACD3ACULL, 0xB872A2373FDE59CBULL, 0x3A956F48E1A35472ULL, 0x6837C2E549D4742BULL, 
            0x73D609EB7FBC2FA5ULL, 0x67CA2B9031F68F02ULL, 0xD1DC62D27AF03915ULL, 0xC4D5FD61AD4DD341ULL, 
            0x3CA5225D41E17A98ULL, 0x3A9FB8F278C19902ULL, 0xC4A1FAEC698375AFULL, 0x422B8F6921388C6BULL, 
            0x2E83E934D745DA5AULL, 0x546DE9CE6DA3A6C5ULL, 0xFC2E89C72E9AFB3EULL, 0xE71CD34A2550F36EULL, 
            0x7E46B7CD9BE979DDULL, 0x215C010C517D6D37ULL, 0x43F15D4CC4C3152CULL, 0xF4CDD52F75ED7CB5ULL
        },
        {
            0xC9D79B849FB8A1DFULL, 0x5D870FCE4849687AULL, 0x923BDF2CC59E2011ULL, 0xC212C7D469E852D0ULL, 
            0x6EB32F3B11FB86F6ULL, 0x270544FE1358F39EULL, 0x29F4A99AF08FA27CULL, 0x7BA4B8EC41D273F2ULL, 
            0xB30AEA56C3B267A5ULL, 0x304EB0DC86A1757DULL, 0x636D7D55FFFF55F5ULL, 0xECFD000AD8A5872DULL, 
            0xB2D30AE870DADAAAULL, 0x8D425F8A41681F56ULL, 0x7779CAEE7A3EC2B7ULL, 0xB3B1476F32590338ULL, 
            0xEE1C29EB56B82C11ULL, 0x67EED866426F2708ULL, 0xA3D98F27CB7274D4ULL, 0xA2C39BA354BB7A55ULL, 
            0x4CA304D8079ACE67ULL, 0x2054A2EAA53EA8D2ULL, 0x74254AD2BA69CE04ULL, 0x6C7308061349DB68ULL, 
            0x890C9D5F2C1B42B0ULL, 0x78F2170E2D3613E5ULL, 0x6E678385AF65E933ULL, 0x6330BC5F2649740DULL, 
            0x0A5765B5E96B8EC1ULL, 0x868A387026EF9EB8ULL, 0xD4A98C56C8C8653BULL, 0x50B74DE6A9E7C25DULL
        }
    },
    {
        {
            0x82E677A0EF752CB1ULL, 0xC1DBB659C49D8874ULL, 0x56707614F94A9EF8ULL, 0xF2EDFC30A09F2DE6ULL, 
            0xA428779C437E88D5ULL, 0x68F8BCFB8C07082AULL, 0xB45FFE6339C79BB2ULL, 0xC374FCD3E39B0991ULL, 
            0xC8255067F9F8C7A5ULL, 0x8180515A8223F7B6ULL, 0x2C307B6BC546B516ULL, 0x8B563CAD5AC0F7F6ULL, 
            0x3E40EA3BB96818C0ULL, 0x29F653BC92CA51C2ULL, 0x088D164F7B9016F2ULL, 0xB4444D9DD4CDCC75ULL, 
            0x088C96D94135C21DULL, 0x1BD729285CDEAFB4ULL, 0x2C86692133E96E43ULL, 0x30F8A0809203D99DULL, 
            0xDC6B5012D0193161ULL, 0x01238D3A7FFCFE69ULL, 0x678FCDA5BC0D91FAULL, 0xDF0FA24FECF23703ULL, 
            0x3E971DD3AB49B818ULL, 0xBFC2E60DB726D067ULL, 0x0F5D0E7242A9850BULL, 0xE4F96D162A213D54ULL, 
            0xB01C6F76CBE2BB00ULL, 0x4337411048AC2FCDULL, 0x407DF8E190331BCFULL, 0xE684F12AB514A39EULL
        },
        {
            0xFAFE0623521E2A6DULL, 0x0DEAB2A8AEC7D9ADULL, 0xEEF45357A0C61566ULL, 0x439E3316A65956E1ULL, 
            0x9F378F111D367CF0ULL, 0x212C1C33C11CAB0AULL, 0x118A63A60B582174ULL, 0x5409A7FB5D236BE0ULL, 
            0x0B18E6AA049D0E05ULL, 0x3B4E610F01C8AB23ULL, 0x095BBD8C176EC79AULL, 0xBF6B41E22645E387ULL, 
            0xAD6F57390FB78DC2ULL, 0xC2064D9C43771033ULL, 0xB94DA3D32A5B0F32ULL, 0x9DC9561CA9A0611BULL, 
            0xE9393E6B68118856ULL, 0x26CC83ED383CA786ULL, 0xC3E0B0D98DD826F7ULL, 0x2CCDDF231F2C805EULL, 
            0x8438EE565EFFDD65ULL, 0xE55EA35846A4AC79ULL, 0x07E18FA8F3343E3CULL, 0xBB27D44AAB168BB2ULL, 
            0xCC9257C5F8902EC9ULL, 0xC76B4EFD45488EB8ULL, 0xDB964A2D83CD434BULL, 0x83ED5C70597E6AF6ULL, 
            0xFA85084875FB7756ULL, 0xB54BB6A13720E543ULL, 0xA92F672EE234BC5CULL, 0x9F527D5482EBC97AULL
        },
        {
            0xD55FCF7B9177637DULL, 0x8975117780E874D7ULL, 0x6E53AB9E7928B266ULL, 0x96FF2BBC8082F662ULL, 
            0x8D04461F446586FBULL, 0x70917685676188B1ULL, 0xCA56DD59AD0C4461ULL, 0x994346B5B486BE64ULL, 
            0x770961DE3E749EE1ULL, 0x3654AF5ED0B1AC4DULL, 0x52A4FE5D68F7FF2BULL, 0xD45EB22B353CF4FFULL, 
            0xDEBBFF9B79E032D1ULL, 0x742EDFE160AA07C6ULL, 0xCC42369DB8BC1919ULL, 0xF17B605BBE67A7CDULL, 
            0x36318B627D36E590ULL, 0x07C3B46B152214B1ULL, 0x7DE8045254D32B87ULL, 0x19CBADA08F725FE6ULL, 
            0xFA87DB5E38F1CA5CULL, 0x26FCABC1BC858397ULL, 0xF1D9DEAB9EE3874DULL, 0x60978A280EB6BB97ULL, 
            0xAE7753461DED8767ULL, 0xED9B74554EBC9176ULL, 0x8826366F735FAC9FULL, 0x863BCC8351C68484ULL, 
            0xA2462FD10FAF0A48ULL, 0xED15CA001D968CD3ULL, 0x97B7ABEE0F7BEBE3ULL, 0x275673E63FED72F2ULL
        },
        {
            0xD69D5E90D6FE9B46ULL, 0xD7B17D85E0A51E6FULL, 0x143511070B29815FULL, 0x433835F345D69EE8ULL, 
            0x3806C03C4AECF4E7ULL, 0x725BC6D35C92DE3BULL, 0x0C76227B849FEE3FULL, 0x6705EE471FA1C629ULL, 
            0x20347EC8B01CDA22ULL, 0x77DF895E666CF112ULL, 0x96E85C033C7E4B4EULL, 0x23B605E19194B75FULL, 
            0x4F167F31BF65344DULL, 0xD179F193AD2D75B4ULL, 0x6CA2A64FD4104DA8ULL, 0xB29AF6B59FFBEF59ULL, 
            0x31F8EBB790ED73EBULL, 0xDA984DBF3EAB2693ULL, 0x6BB452E23035C797ULL, 0xD48D38167E50601FULL, 
            0x88A5B6AA821F0CE2ULL, 0x37FEC8E09C81A667ULL, 0x1676D50E1B4C92C7ULL, 0x712F77FCFEA98AA6ULL, 
            0xD9E440643B52C33EULL, 0x38A316A036F995E0ULL, 0xE57411D9E72F12FDULL, 0x5767A97227DEE1CAULL, 
            0x57526326428CA0D6ULL, 0x691C5F410B097207ULL, 0x408730E27A31D452ULL, 0x924ECA974B1EC45AULL
        },
        {
            0x82F8B7CC2A45A03DULL, 0x7EF0D11E88F3AEAEULL, 0xCDFE9F2D70C66904ULL, 0xE62494F27642D038ULL, 
            0x46210217E6FC3F2CULL, 0x56AF01860BE6AA2BULL, 0x574F3789E76D9880ULL, 0xE70D67CB3131A60AULL, 
            0x9DC3CA2E5586FE57ULL, 0xCD21C314EA56AAEDULL, 0x7DEC90FAF146F40FULL, 0xAE2504C3073A41CFULL, 
            0x74210144ACF60D58ULL, 0x7B868B6F6BA482C8ULL, 0x88ED87ACE1CF439FULL, 0x17A8642CE1DDF36BULL, 
            0xA81BC177A44ABE27ULL, 0x5D05B3D29E17EC93ULL, 0xB28B6C38D96DA9C3ULL, 0xE6890AD662021F29ULL, 
            0x867171639D0C2163ULL, 0x66BC015A5E1C20D1ULL, 0x3F4FA6268F798F91ULL, 0x905D18CC5B295029ULL, 
            0x94268F82EA1A0F3CULL, 0x70EDEE373FA4E002ULL, 0x598DA9F082E94444ULL, 0x01565FE007857FC7ULL, 
            0x0E4984E58D6741A5ULL, 0x27B42DF3C9FC7201ULL, 0xF86DE20BA65DBFDFULL, 0xB81584FC9D14F67CULL
        },
        {
            0xC97D54914A970435ULL, 0x8D0F573A663C5E6FULL, 0x6EE86E5B37F99D18ULL, 0x00EF7F5D32A6C93BULL, 
            0xDC68FE43F47AF847ULL, 0x10A0FD719EC9CE3BULL, 0xA2450B1243987D7EULL, 0x7B1FE8F31CE1E9EDULL, 
            0x457360CBF9573BB3ULL, 0x7EC62F8ED6867A77ULL, 0x6CFBE3FCB2C6BCF8ULL, 0xE04A9B5FE152F014ULL, 
            0x67D787C5136CA23BULL, 0x356AAF8BF6F31321ULL, 0x434728FE1C1D7B5EULL, 0x51F80F4E40575B92ULL, 
            0xD5A7C5ADADDDF68CULL, 0x4D0EE0E438870F09ULL, 0x17D6507828CD9044ULL, 0xB77A767DB0217B08ULL, 
            0x73CA6693203127E9ULL, 0x1004A26C18446C86ULL, 0x713B70B395AA0240ULL, 0x03DA3B84FB279A8EULL, 
            0x083D9B8318C0E0C7ULL, 0x3410B06EB12AFC7CULL, 0xEDB4E334F9365403ULL, 0xBB6A7E844485C252ULL, 
            0x447FC338C51143A5ULL, 0xA224BE6A65D1724FULL, 0xA62799BE62C8E675ULL, 0xE7FD054DBEB43E25ULL
        }
    },
    {
        {
            0xCF200D3E3B3954C2ULL, 0xBDFB4C6576672F02ULL, 0x71C1C6558A870407ULL, 0xB3E7AEA6473B9961ULL, 
            0xBC6BB6F5CEBFC63CULL, 0xBFE0751A40587220ULL, 0x37AEF17E800C1FDBULL, 0xBB37CC8EB61BFD9BULL, 
            0x6822A065057EE0BDULL, 0x5084686AEC582AF2ULL, 0x8B50790B9275C95FULL, 0x99070619B6E31F33ULL, 
            0xF08E837CB54E9E27ULL, 0x7D5E4C2E31A9F9FBULL, 0x31E6F209706EE62CULL, 0xCCC390BD922E3615ULL, 
            0xC55FDB64076C5237ULL, 0xEED68FE8CE118983ULL, 0x2F9EF54E443ECCF7ULL, 0xC845D87C8DD41052ULL, 
            0xC00F27CDF5EA85D3ULL, 0xD760EBEF9EF73BD9ULL, 0x011F4833B1D00AC3ULL, 0x5B77C4612934B298ULL, 
            0x19736FE056FC17CEULL, 0xE63687865E245683ULL, 0x5B7CE200061349AFULL, 0xD8FAC99133A0A3B3ULL, 
            0x1012265113765E3BULL, 0xEC1003A5D8BCC9F0ULL, 0xE0ED85E77260F1AEULL, 0x84937B492CBBFB96ULL
        },
        {
            0x3F879EFBD81F2685ULL, 0x56624F65280DAD0EULL, 0x219242CB7128D39AULL, 0x45B0DCC138354217ULL, 
            0x0D646C3DE542506DULL, 0xAE163EF211B596B1ULL, 0xEB23DBE191F5BF4FULL, 0x4433D50BCB7CB374ULL, 
            0xF978C25303755696ULL, 0xC96C246DC15536BCULL, 0x49E6E88583FF8BEFULL, 0xA24D0D0822EE4EE8ULL, 
            0x7CAF9D97F3E538A0ULL, 0xE92DA48D6F490B80ULL, 0x0EA4ED07FAE64CA6ULL, 0x1808AAF9B9716F98ULL, 
            0x181EE63F69D12781ULL, 0xAD20AB65B0E684C6ULL, 0x4DF02BF1E4C0F595ULL, 0xD04ED5FBC4A3DE87ULL, 
            0x64DE95207BF2FF96ULL, 0x8212554ECA137CF6ULL, 0x41C964666691DEDEULL, 0xDF1F7BCE8FCA140FULL, 
            0xEAFDDDAEDDCAE454ULL, 0xD6F0CAE7918D53B8ULL, 0x185C2BB0A4F6D865ULL, 0xA0BAD90581A83968ULL, 
            0x9ACAFC15C236B4D8ULL, 0xDF08A958748FD7BFULL, 0x790537DFD2329ABDULL, 0x2E7C2FFD67996012ULL
        },
        {
            0x7A73E17D34182687ULL, 0x67CE6575437016A6ULL, 0x2CB099CE15E0C596ULL, 0x1FDEDE2714B62A1FULL, 
            0x36E0ABFF1400D512ULL, 0xBB91303D3A4EB902ULL, 0x79756A3702E0EC65ULL, 0xA5556FE8B28C571AULL, 
            0x55CABDA246399B6DULL, 0x0F0F8DC0864F1EE8ULL, 0x663138A93AFA7AF5ULL, 0xBB249F48D0494DD4ULL, 
            0x1070FB32E77654DAULL, 0x8C090799BDB37495ULL, 0x45FCAAC2ADC1C708ULL, 0x6A38EDEC43CDFB53ULL, 
            0x82BEB5BBB7DC7955ULL, 0xF686E2291136FFF2ULL, 0xAE31694186A2BFADULL, 0x18B3DE542A47F28CULL, 
            0xDC0C1443E0AA1A71ULL, 0x45FA403E25E57FE4ULL, 0xF4E1ABBDCFB7C6A7ULL, 0x191304B4A1E64238ULL, 
            0x157368D65398A5DFULL, 0x9802CBBB22E780D7ULL, 0x53411DD34297BBC9ULL, 0x8A58961C4369F561ULL, 
            0xA6581E7B6D7236ADULL, 0xFB0995A3446F9B56ULL, 0x06CB3C7940781682ULL, 0x2A27EE73177A5EB4ULL
        },
        {
            0xCB16BCE3FD5DB2ABULL, 0xA64672825176BABFULL, 0xFE52AEF78F5BE158ULL, 0xA9EE213C9CF37E43ULL, 
            0x72443B763944A5CBULL, 0xDEC40F1AA5A882ACULL, 0x6A3C5E510EF07ED9ULL, 0x7CF668775266F69CULL, 
            0xABB06FB7CB512DABULL, 0xB8206113F848028FULL, 0xFFBB96F47731941CULL, 0xA256827C2577F088ULL, 
            0x9C6B17E67C017A17ULL, 0xD3A7E32DF89C4B30ULL, 0x942C402EC0751D5DULL, 0xB9A82FFACC4408DEULL, 
            0xD4E0257F50639010ULL, 0xF159C48C54C4B393ULL, 0x96A03DDA973DF8BAULL, 0x60227404C4020903ULL, 
            0x62979CF432C927C4ULL, 0xBBCDE472D78868F8ULL, 0x39E89A2394776070ULL, 0x8BB1271DCD995C07ULL, 
            0xBA20940383B8654CULL, 0x3FFEECF5BB0AE403ULL, 0x528B4AC8014EE74EULL, 0x6B20FEEF7236CFACULL, 
            0x7B06F832D66DDF8BULL, 0xB490B0714B132088ULL, 0x14168EABB268C265ULL, 0x97AF8033494A472BULL
        },
        {
            0xB9A74F1F94A2B1D6ULL, 0x39E0321990F28ED7ULL, 0x5056261DD477EA44ULL, 0xEDB9816B5086029AULL, 
            0x246D28FCE4B48246ULL, 0x28A99BBAE8123061ULL, 0x16E4C4418D5E2126ULL, 0x89BE841D393A116EULL, 
            0xA50A0B8EB5583067ULL, 0x7DA4E20ECB59B952ULL, 0x3ED5899C60EEDDB0ULL, 0x04E89FF376AC00C6ULL, 
            0x66515EC143146E33ULL, 0x62E816B8088E0C34ULL, 0xD9DDF525EE157DCDULL, 0x4821127183B7E1A7ULL, 
            0xE1146A499E0518EFULL, 0x05FCC77CC24E8B5AULL, 0x79E5A94ADCB6A3C8ULL, 0xF9734DB8200E5324ULL, 
            0xC3FA2D0464C6788DULL, 0xB27FE2C134B29533ULL, 0xF8959D0FB00529C4ULL, 0xC25156CC002BAEF7ULL, 
            0x9836B2C9BD301174ULL, 0xCDD1111D7FFC27A0ULL, 0xF29B0D0D57AAF978ULL, 0xB3A15CB4CDEB5C90ULL, 
            0x77705830C03B05D7ULL, 0x7BD2B5A6F960FF4FULL, 0x65ED5DBF2826C591ULL, 0x4414E1D952D05716ULL
        },
        {
            0xEA959B13C8047039ULL, 0x5ED8ECFDE0E5BADDULL, 0x148581E9D1B9E402ULL, 0x660FB895CCC8AEE7ULL, 
            0xED19223F3A1CA76EULL, 0x38792A64F37FA9DFULL, 0x3FD3733428ADF7A4ULL, 0xC74FC56B6FF0B7AAULL, 
            0x74878D9846F651F8ULL, 0x65DDC7B1BB016ED2ULL, 0x657A71AC4A2322DDULL, 0x2D63D1ABD02DA466ULL, 
            0x8B7F531C060E5C58ULL, 0x1616CC3266BACDD0ULL, 0x81916950BD05849DULL, 0x4EFF31202D0A54EBULL, 
            0xC131BBB709E09774ULL, 0xBFD581CC5950FE69ULL, 0x2C95DDEB3F936288ULL, 0x2F3E5A361CFAE42FULL, 
            0xCE44A51A59C35A53ULL, 0x9E65A97F34E09CCEULL, 0x9FD390974BCB309EULL, 0xD1A1B91305F4EF25ULL, 
            0x2A45F4F22B23C13EULL, 0x40A2D128FA2035B1ULL, 0xA8A37A57C794A6D3ULL, 0x7D898D4E1C3A0243ULL, 
            0xDAA05837B4D2852DULL, 0x8461F583792C48C4ULL, 0x758858B3DB02009DULL, 0x6A6CD82CF4778F63ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseAConstants = {
    0xF0973240ECEEAC5BULL,
    0x0FFF5AF0D455520CULL,
    0x69A2AA81DAF30A01ULL,
    0xF0973240ECEEAC5BULL,
    0x0FFF5AF0D455520CULL,
    0x69A2AA81DAF30A01ULL,
    0x6E51C2959D76142EULL,
    0xE7F5444B6660EDC7ULL,
    0x31,
    0x15,
    0xDA,
    0xBB,
    0x5E,
    0x91,
    0x3C,
    0x9D
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseBSalts = {
    {
        {
            0xEBE35237FEBB40AFULL, 0xDEA03F9CFA2DE55BULL, 0x14EC71300D8CE18AULL, 0x96EB797FA087CE64ULL, 
            0xE11FD46B49CB5353ULL, 0xBFFBE80FB6EA40F1ULL, 0x9AD781F92947BA80ULL, 0x67AC573F7D91C8D4ULL, 
            0x3AE6EB51CCD41A5EULL, 0x7E07AE880CED446FULL, 0x4B303C9F4DF8BBE5ULL, 0x1ECD834923027851ULL, 
            0x8A9AC82411ACD3BEULL, 0x0DB69A0510394ACDULL, 0xE4903897D7C69C34ULL, 0x822C50116A686FB3ULL, 
            0x1FE699806E1AE54FULL, 0xB8510A9FF8BE780BULL, 0xA7B08B89DF5758E3ULL, 0x3BF909EC4673C977ULL, 
            0x74B38104F875FA6CULL, 0x8099899096706EF0ULL, 0xA98F3F49C917E91EULL, 0xBD8B948843468A69ULL, 
            0x04AFDD5BD9B4AE7AULL, 0x548A03B3FF659014ULL, 0xA31F9CA28BC632D5ULL, 0xE38A2718F456F66AULL, 
            0xF8B4D876C4FFE256ULL, 0xE5E7020855FE4B0BULL, 0x442FDC08E6B68670ULL, 0x71FDAD6768978C24ULL
        },
        {
            0x38363DC0ECE79C9DULL, 0x55F5E33421B32E3FULL, 0x800D17107E82D022ULL, 0x65C0097FFA9DC338ULL, 
            0xA695A7071F6101FCULL, 0xC36C702A5B04B1ADULL, 0xB4872483C77EA9C3ULL, 0x4A33FE6DCD5282F5ULL, 
            0x2CC83A96E3A960A1ULL, 0xBA20709390200982ULL, 0x813ED6D8D03E10B2ULL, 0x9C2579EB201C59A7ULL, 
            0xEB500FEC65B96F72ULL, 0x6E5B5B95812D98B5ULL, 0xD22197FAF94D3C69ULL, 0x0CE73EB7DDD6B6F2ULL, 
            0xB3DFBDD6C9AA63DEULL, 0xCC4393AA897FFB4DULL, 0x0F002E195035305CULL, 0x119C2665ECE71666ULL, 
            0xD4D3076FDA6CF85BULL, 0x7A3E6A8A26D63B02ULL, 0x106EE5C59E907C39ULL, 0x5CF57B409AC944CCULL, 
            0x164B49A9BA670706ULL, 0x7966FBDF02060C30ULL, 0x26EBA4100FD94C02ULL, 0x2B5CD51A74F99913ULL, 
            0xDB49F8081FC05A79ULL, 0xA60DAF81E46FDB44ULL, 0x6513C808ADA0415BULL, 0x9E73E2C9FE43A8B8ULL
        },
        {
            0xF32613C58CADC95AULL, 0x187BE2F90532AA8FULL, 0xB7AB4C6E9EF6D33BULL, 0x30FAD60DA929109CULL, 
            0xB512A89F2E15F335ULL, 0x6B13687C8DA1B708ULL, 0xBCD182DD4464DF1DULL, 0x165DABB7F3FE80CFULL, 
            0xBA4179E42AD10187ULL, 0x8DE4563FC71A0FA8ULL, 0x90165854D5BC9FF6ULL, 0xA4AD19EB2BDA7D82ULL, 
            0x05BF903AE685C869ULL, 0xCE715AA566D5CBD1ULL, 0x243F49A18D891D84ULL, 0xC446E81A4205E35AULL, 
            0xAFEB819BF471791CULL, 0x92380A8ACD43524CULL, 0xBBB21B03C4402BE4ULL, 0x6F3B1A95C816700CULL, 
            0xE6F69948B4C6D605ULL, 0x1BB1522D41C53943ULL, 0x322892E0F6C99003ULL, 0xAF59895EDC4563C1ULL, 
            0x41B3F7E78907EE5CULL, 0x2778680D83A513BCULL, 0x62EB9E898C91C8B4ULL, 0x8A7367DF16CB18A5ULL, 
            0x11A597F542A075E6ULL, 0x2F9406DB4C598B72ULL, 0x7315BA8BA8853BC7ULL, 0x6A7FBF906FF6D947ULL
        },
        {
            0xD3807AB7F594C7C6ULL, 0x7467F9AEDA037B51ULL, 0x6E146C5609D40793ULL, 0x339031CD61A8479AULL, 
            0x2A275AAD7A7BFC31ULL, 0x01A8C8688993A65EULL, 0x6F7D4E40ED196840ULL, 0xD4FF884CC53986C9ULL, 
            0xAD5A8015A7AE9C0EULL, 0xA6C886223B4A3BEAULL, 0x31EFFB93C86AF60FULL, 0xB7E2E9BCCCB828BBULL, 
            0x0CEBF08016EB0902ULL, 0xD3128C4530A5EE0DULL, 0x1D86A082C66472C9ULL, 0xED8970BA5CB1E4E7ULL, 
            0x180E842A4300F7E1ULL, 0xF6E16200CA26A0E1ULL, 0x2A2C6BE9FB5DD594ULL, 0x84EE44453D4A937EULL, 
            0xFA83832F035BFB26ULL, 0x45A5D52C8A5F3C1FULL, 0xD43E6A352CD83FEDULL, 0x29BC952E0D6BAB26ULL, 
            0x25F3A66E965B27C2ULL, 0x8BA9E0DEA42657E8ULL, 0xC92B823B5E1C9E9FULL, 0xD1F0685395832D24ULL, 
            0x40ABBD62FF388C86ULL, 0x6340CE79E2F49498ULL, 0xA984ACF54693E15EULL, 0xECBE82B20249E12AULL
        },
        {
            0x87CB0CDCDCB8977DULL, 0x3CFB038A0B9A1F46ULL, 0x3D6730FFBC10441BULL, 0xE5F2F14A215803DDULL, 
            0x1C8F6892DD6FC33BULL, 0x1D4B284A6B6BEC23ULL, 0x2F11CC3EA4DBCBBDULL, 0xA42E25D7C42AED03ULL, 
            0xF230A9867B4E29F1ULL, 0xB95DB9279770ACCEULL, 0x553C9D77F62B2C17ULL, 0x6A7EE0EC7D73CB7EULL, 
            0x1D9B68C7A7D7B59AULL, 0x72F63FBEBA9AB671ULL, 0x4E485A729EE6F625ULL, 0xF3FA001BBAF38F59ULL, 
            0x1A72B087B6E4577CULL, 0xE1B69A595451891EULL, 0xC683992D4BDFEB65ULL, 0x52E19C549120AA89ULL, 
            0xE50C28D3B90BFA22ULL, 0x4F71A94D543F8721ULL, 0x0A9E0A4AEE458ADCULL, 0xF577F0C7DAA1E9F4ULL, 
            0x00072CE6305100BDULL, 0x86F832723D656DA5ULL, 0x6306C07EC0B75BF8ULL, 0x8DE939F427E55EBAULL, 
            0x2662F5540214D0B4ULL, 0x77305BAC0D9F0CA4ULL, 0x321456941D99E8E9ULL, 0x158DA0C8F61F2FF9ULL
        },
        {
            0xABD6A17013AC3937ULL, 0xA2CF2FA2976AA014ULL, 0xB87D260BB338799CULL, 0x112BD71CB9DAD8D9ULL, 
            0xE73228886C0EDC83ULL, 0xF2EBA2984CD12C26ULL, 0xBF372D7419D16A84ULL, 0x7127EE36AEBFC86FULL, 
            0x36C05CE25C12A62CULL, 0x1AF589E84817E65EULL, 0x0CD4D3EF5C9467E3ULL, 0x9DA3C0B643FAD925ULL, 
            0x8A3B233B18C27089ULL, 0x72D398048FE56351ULL, 0xEA29ED1849997D59ULL, 0xAEC47085243D1C48ULL, 
            0x28D465ED3A63BA68ULL, 0x07ADD0C18CD26706ULL, 0x413B6E9BEDB0592DULL, 0x17E3D21932B694A4ULL, 
            0xBF7172DF7A0311E1ULL, 0x45A6CFF1499ECFFFULL, 0x99DBEF20C8E6B7EEULL, 0xF127E4473D06F0E2ULL, 
            0x7F377FED4E8A98DDULL, 0x95676B42779E29A9ULL, 0x62EFCC8606B2FBA0ULL, 0xC1662965E6B23DE5ULL, 
            0x4B36DF55B4A7ADA8ULL, 0x8E6FCA99EC2FE0C4ULL, 0x967577E921A6358AULL, 0x41DC49D0C2E73F46ULL
        }
    },
    {
        {
            0xC71D0082768D6E46ULL, 0x5D6B1744CC1D19A4ULL, 0x79C3231327B5F166ULL, 0x429C96B966EDE94CULL, 
            0x2BE46FCA1EB57ED6ULL, 0x3839F334A952956AULL, 0x0B45C13A3FA9F06EULL, 0xDCE1441CC53E6F12ULL, 
            0x1701044DEEA412C1ULL, 0x25896B5D641CC327ULL, 0x3D8D161278C5114EULL, 0x3F37E3A4590E8432ULL, 
            0xAB60CBFA3F432BD2ULL, 0xF155F715430BAD4DULL, 0x6A515FCEE11603A2ULL, 0x1A87196F9D5D2411ULL, 
            0x614B95FF0144B418ULL, 0x6CB3547FD8DE5376ULL, 0x652E8D77CF2522DCULL, 0x933C83CF0A0F2A77ULL, 
            0xFAC883AFE8C4A400ULL, 0xC2B9800B1A6DAAA8ULL, 0xF8B6CD03DC4FBC21ULL, 0xB6B442883A20FA89ULL, 
            0x7B13604FE1141A6EULL, 0x2FB9328B343468E6ULL, 0x0EBEA5DF30AAF0D6ULL, 0x69A7AF01568380C7ULL, 
            0x66176D77225DC4A4ULL, 0x2F3D377F3101B1C8ULL, 0x99B1928A4C5508BCULL, 0x7BB9A589D0BD0F6DULL
        },
        {
            0x76C378C482152214ULL, 0xFC9B20F998280020ULL, 0x75CF38BEA63E7387ULL, 0xFDCE4D09BFB5CAEFULL, 
            0x1BA226AF92CDE62BULL, 0x6B9E8FC91FB02227ULL, 0xFE3A72F6FDA737A6ULL, 0x9D636DD79AD04092ULL, 
            0xDC9E62C2B36B96BCULL, 0xC06E7B2F8BB586CFULL, 0x7D23ECA01EBA95EAULL, 0x56B5F4A25C73B15FULL, 
            0x6F5DDDC43DB9789CULL, 0xCE23D8CC314DEF93ULL, 0xF291B8E4B50857C8ULL, 0xAB5C004E765612EAULL, 
            0x3BDC60304AD334A0ULL, 0x32F4C9F00724C732ULL, 0x1F7B21EA77B29EECULL, 0x4D1708240483A13EULL, 
            0x10929E9DE62C700BULL, 0x1D01033F556C06C6ULL, 0xC162EE5720234FFAULL, 0x51BB968B556B9F59ULL, 
            0xDBE5FE9F9830EDA6ULL, 0xF01CE1A3D0F779B3ULL, 0xB943990B1A09CBF5ULL, 0x463E12129539D8A2ULL, 
            0xE77DAA70DA1F45AFULL, 0x5A024EFCC6C641FCULL, 0x317D4A992871DB6EULL, 0xE0C69B74DFCBF9E7ULL
        },
        {
            0x042FE8A80F78D98FULL, 0x39C587AC41F23559ULL, 0x0E1694D2F8954D35ULL, 0xCF87BB594A2BBA08ULL, 
            0xE7FE9DFEEB600DC1ULL, 0xC6028506F17D8ED4ULL, 0xC1FAF86E4EBA1E30ULL, 0xFF81AAD175F0B9C9ULL, 
            0xC27740A0D838D42FULL, 0x80F7EACA6638595AULL, 0x5EB80D2DA54090B2ULL, 0x36D5D85845AE78B9ULL, 
            0xA56F917D168C1651ULL, 0x15CE97E3AF08D286ULL, 0x30C5329D577FDBA8ULL, 0x7FF7B7A69491291AULL, 
            0x86A69DE2A60823F7ULL, 0xB4EDED8C4F61ED90ULL, 0xB5D8783AD2F52502ULL, 0xBF842C4CEDB1772BULL, 
            0x5EAB7B1CEF28D6A6ULL, 0x2C85D35CA97AD1FFULL, 0xB9B9CBA8140BCE8AULL, 0x8E8C760187475444ULL, 
            0x8DCABE50960550B2ULL, 0x89B9FCDDE5563111ULL, 0xDB58441006EA0A8FULL, 0x6717BF05D66F78E8ULL, 
            0x67CAFAC2157597C8ULL, 0xF8825F75DA79AE2AULL, 0xD25F644D7EFD1D6BULL, 0x32EBFAA3E8C86596ULL
        },
        {
            0x672F840AFEB9C0A2ULL, 0xE8155D5400590CCAULL, 0xB29ACFDB62DEE82EULL, 0x7F4B996DB4FA9343ULL, 
            0xA37E3CF5D04A36C8ULL, 0x7DFEBDFAEFAD786DULL, 0xA0C5A12DF600D209ULL, 0x57E1693A232372EAULL, 
            0xD6B1010967DA3063ULL, 0x81E5FB15063F3B43ULL, 0x559637DA42315C3EULL, 0x7DA40ACCB270A07BULL, 
            0x600305A9FB04BA86ULL, 0x14274CEAA299622CULL, 0x95A3F3CABF83C3FDULL, 0xE42C46C60D442CEFULL, 
            0xC6DF0FCCC14E2561ULL, 0x709897D68C1EE2B2ULL, 0x54FEE1B73B4189D4ULL, 0xB1A5B2C6F6E61B9EULL, 
            0x33FAC62801E19A6AULL, 0xDD8AD94D6F5AEE70ULL, 0xC85CFE2F50223030ULL, 0xD93CD4A4895790D3ULL, 
            0xD44E8CBA1FB288F0ULL, 0x1F5EA2EF59268878ULL, 0xD7E3DAF826C0519AULL, 0x62C4C20AB45616C9ULL, 
            0xDE45A25D1E53E887ULL, 0x49F2326EDA7A75ECULL, 0x29BA71FB10BDFED9ULL, 0x11344AEEBCA7B1D2ULL
        },
        {
            0x1586EDDBCDD3CF58ULL, 0x2AC1B23FD7AE7FCAULL, 0xA4A33512E7566131ULL, 0xC52D9B8213B69389ULL, 
            0x5D0BB94040234F72ULL, 0xDEB436456478BBC2ULL, 0x5254FFA664D3E67FULL, 0xADB3AD8A43C16F28ULL, 
            0x80158DB5D828362EULL, 0xB7290DC911352533ULL, 0xE80A93F1E0A56F69ULL, 0x5203429B719F4F9CULL, 
            0x10B1BFE33984767BULL, 0x723EB44CC9FD3DEFULL, 0x42E13C830B94ED8EULL, 0xF52E20A724793B55ULL, 
            0xAC8FD8B97EB00743ULL, 0x1374380AF2B19216ULL, 0x7BF5CF721E3F178BULL, 0x72219854829380E2ULL, 
            0x8D84B51F6811DD50ULL, 0x7E808A05D58C653CULL, 0x4612460344EF7ACFULL, 0x9DAF8E7DB342B351ULL, 
            0x1945DE08DC68DD5DULL, 0x05AA3C9252CAE190ULL, 0x508E0CF7515559AFULL, 0xA03EBFE70E1A93B8ULL, 
            0x2668350B7582572FULL, 0x5E3D0D02FF2A73A6ULL, 0x7086E77095478098ULL, 0x6035C5278CD508FDULL
        },
        {
            0x9ADC6B37B08BE3AFULL, 0xAAD57CA2669DE138ULL, 0x8D2D7B05107C3DA3ULL, 0x623142A58D556508ULL, 
            0xC37B3B7EEF5F7352ULL, 0x997971AECC336ED3ULL, 0x65B19AA77C823820ULL, 0xF088BE2D478ED3BAULL, 
            0xE21B59A75E57B477ULL, 0xB1AC4862535D8010ULL, 0x2ED0D41B8F527E98ULL, 0xC295F29936E1D02BULL, 
            0xF66CF31BFB21550CULL, 0xEA5F06562D94EFF9ULL, 0xBCD30FC69258004FULL, 0xD15C3FA81E2FFF63ULL, 
            0x30FC692BC98EBE04ULL, 0x16F2AAE8DCC96CF3ULL, 0x8B2ECFAF07006164ULL, 0x67D8626DD1E429D1ULL, 
            0xE4FCAAA8E3D790B3ULL, 0xFB38D335DDA93EAFULL, 0xD24CDE55A2894B79ULL, 0xCB59A3653AD81220ULL, 
            0x5117C4F054B984B3ULL, 0x6D59652C63F4FFE1ULL, 0x20B7DF7AEFDC3C8AULL, 0xCFDAF2C05F4B1B1CULL, 
            0xC65BA7972A7213A7ULL, 0x71D68DC9CBABB5BEULL, 0x327F7B8DCF9C2F1CULL, 0x8856AF8F3FF18DCAULL
        }
    },
    {
        {
            0x2AA7D3F615748FB6ULL, 0xF86BB6CE6D7488A0ULL, 0xD7BFDABCE4157E61ULL, 0x4125FDEABF8E3A04ULL, 
            0xB1EB6358CE8E0BB3ULL, 0x8EEC4445847F0507ULL, 0xF098DECE87C991CFULL, 0x5D690022BEC4C9F2ULL, 
            0xAC5FE2DE281F6AF0ULL, 0x543397E9E8FACB95ULL, 0xE4C47B8EB08A5AD5ULL, 0x86D391E618F7520EULL, 
            0x9AE9273D0ED4F1EEULL, 0xC9D5CB1A8FB9EDA6ULL, 0x2839BB4FE802CD72ULL, 0x2ED92F5F61E69429ULL, 
            0xD65E74DF53F2D4C2ULL, 0x1B83326C6C41FD08ULL, 0xADE7C245DF549482ULL, 0xF8EAB2AB6C0693EAULL, 
            0xF42A4F2AA7901982ULL, 0x1C96636C5FB38765ULL, 0x9BD0DABBD3E3BD8EULL, 0x3C88BF4C02689DCFULL, 
            0xC3323BC22915C35EULL, 0xE65B404FEB69E1A5ULL, 0x1CFA894531EF85ABULL, 0x50ED9863B541AA4AULL, 
            0xEAA23652C731DDB9ULL, 0xD2F23621EF3FC999ULL, 0x7F0F35337B26B1C2ULL, 0xB47289E79A0C8F5EULL
        },
        {
            0xE90CA8E7E8F371F3ULL, 0xE6277647BECA80D0ULL, 0xFB412F562D7CB4EBULL, 0x8CB0C4F9325861D2ULL, 
            0xB3F29E2771D73CB7ULL, 0x40BC4A2B2DDA2854ULL, 0x02814605A9BBF952ULL, 0xA2A3C27917EF2E71ULL, 
            0x4A510057AE3337F5ULL, 0x4B5FBF7DBA43C9D2ULL, 0xC539DD80B0E723AAULL, 0xC16752E1F2793416ULL, 
            0x89A73D4C41F47ECDULL, 0x179745186FADCC15ULL, 0xCDA233BB2837D18EULL, 0x7F199ADC146AD11BULL, 
            0x5F519F4D0DC9444FULL, 0x3F7C6E4E535AAD5CULL, 0x325DDCCF991A4FCCULL, 0xD21786AFE3F4F6FDULL, 
            0xC97875192F16AADDULL, 0xAD61554039CA3682ULL, 0x6B33EE1813F4AFA7ULL, 0x6AC737B2DC5C3B1EULL, 
            0x1890BF197FB0048CULL, 0xBF9E790F094EF0D2ULL, 0x79CF34EB6A855CEEULL, 0x3E4C4DC719A71677ULL, 
            0xF679B7F90589715AULL, 0xED0FAE801F8344FDULL, 0x534CC50B58D01153ULL, 0x64E2C137996608BCULL
        },
        {
            0xA622A479FDF7112AULL, 0xDFAA88D4AA4DA0EBULL, 0x15473702DF2F6D93ULL, 0xCC6AA7CFE13A4599ULL, 
            0xD387F4B19C47486AULL, 0x4E46AD47093A5A6EULL, 0x15BF945C39E75DDDULL, 0x3819AC45A8F6A1D8ULL, 
            0x187E189E28DDC5E0ULL, 0x6DB6C436C7CAFEB6ULL, 0x8BB04083CD7D9C43ULL, 0x7CAEADC8C6CDE892ULL, 
            0x4DEAAF8CB133ADF7ULL, 0xD24F0A7022412310ULL, 0xE3D025E45C032493ULL, 0x346B86D1E6E2EB13ULL, 
            0xD8A9B81BE9E8DB51ULL, 0x43B399D9D31EAFE5ULL, 0x3E008BF79DF75C6AULL, 0x6A3145C2475E49F1ULL, 
            0x28C36BEFB03B29A0ULL, 0x9FE3BC55BE4B3811ULL, 0xBEFB73B6353C0068ULL, 0x27718C3FADC7D07DULL, 
            0x77A252DBEC6F7639ULL, 0x948FDF96AD17B9D3ULL, 0x7EDF821E0C2B324FULL, 0x750A2F35E3C9C439ULL, 
            0x6B3012E1338BF165ULL, 0xCE357F48CDE9EAFFULL, 0x272B28BFD6DCD2B0ULL, 0x58C189E629DD7308ULL
        },
        {
            0xA33BE4D3AA22FC8DULL, 0xB669B578B4298A06ULL, 0x54934A133FA80EB2ULL, 0x39020C5CB58670BBULL, 
            0xE5AD115038A3B6FAULL, 0x79EB54B4FB53965DULL, 0xD21C3E073712779DULL, 0x5D2569C6E9E82587ULL, 
            0x5ECD6DDC19DE3928ULL, 0xC380598E96FBBAC8ULL, 0xC483C72D8CEF8485ULL, 0xBF891F31858B79B8ULL, 
            0x6BC38DF886781F17ULL, 0x6C03C61D8219556BULL, 0xD5E3E2508DCBF59CULL, 0x868CCB91218F870EULL, 
            0xB77338A6FEE563C7ULL, 0x4AD0095A0C681EAAULL, 0x36F0A8A173C6C83EULL, 0xEA54376BE08C8A90ULL, 
            0x7D170F895D959518ULL, 0xA1AD3F458B42E796ULL, 0xEBB356360ABD8F25ULL, 0x201DC77EC0BE8459ULL, 
            0xEE6F29493ECC86F4ULL, 0x8B659A903CBC1CE9ULL, 0x1B690A1FC08A601CULL, 0x974BA461678E150EULL, 
            0xCC469A799214CC88ULL, 0x16E8591DA6B7723DULL, 0xAEAE4B84B278750CULL, 0x88BA316E83C6ACA9ULL
        },
        {
            0xA8E6BF099AB5C2A6ULL, 0xC0A6626B18AC7748ULL, 0x3FD7B4AF5B379695ULL, 0xFA3366535473FF74ULL, 
            0x4F5A0003DE7B360EULL, 0xC7E8E1FDF364D9FBULL, 0x8D5A35A95A3D7DDAULL, 0x9D89217F8FB10345ULL, 
            0x82AF28810FCEBAB0ULL, 0xC5E0596C55DDBDE9ULL, 0xFBF35EBFF41DDA0FULL, 0x79137AAFFD50D7D1ULL, 
            0x4FF6AC5342663E43ULL, 0xFADB36CFCED05E50ULL, 0x7AD446FBD4DEFB96ULL, 0x0FC15BDEB273FC2CULL, 
            0xEC3A1BB742F3A977ULL, 0x43F74904FFD56A56ULL, 0x4517BD4C2EDE9F6DULL, 0xC2EE6A9E6F38215AULL, 
            0x6B03B1F27623F1DAULL, 0xBC95EF13E52F506BULL, 0xDC4DED882905EE59ULL, 0xF0FBD968E9EEDCDDULL, 
            0x8AE0606009EF157CULL, 0x98170DDF1B1DE860ULL, 0x42129AEE622C0D0DULL, 0xE21168B2287C6622ULL, 
            0x728A3D04A5C6AE4CULL, 0x038F2C145B64EEA1ULL, 0x5C02F5C6C0308C30ULL, 0x5BDF444F23121960ULL
        },
        {
            0x688654331C30FFD1ULL, 0x14B041373B6A975CULL, 0x3D584C9A16E44FF2ULL, 0x81F7752322D61EC8ULL, 
            0xEE42F5396583255CULL, 0xAFCE7A52FC7EC2F0ULL, 0xD034F44F2EC4682AULL, 0x742AFD86C16D3763ULL, 
            0xF063425E9693BB5FULL, 0xC98F82A33A401512ULL, 0xC88C40B90460B62AULL, 0x485C004479758741ULL, 
            0x8045BD6771DE4D8BULL, 0x65C6B0B7E214A3F4ULL, 0xD2122A2113073870ULL, 0x4871E4560D1BC52FULL, 
            0xE13CE9A56FB129B3ULL, 0x5EA3C857C84CA121ULL, 0x1776EA5507D1B70FULL, 0xC954AF48D21D6D19ULL, 
            0x6983C009B7443E6AULL, 0xD7F939D37C16C519ULL, 0xD30513173069D269ULL, 0x9EC70DF85116DB1CULL, 
            0x49012F8E6C98314CULL, 0xEBF99936BE5B101EULL, 0x2B725DC0295F76C5ULL, 0xB28EBE462992C844ULL, 
            0xC525AF4DF3D49101ULL, 0xE540EC58865903D3ULL, 0xEAA198EFA5607A9FULL, 0x3E0A61544F9A7A5DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseBConstants = {
    0xEE2DD07680CD5323ULL,
    0x5B1545C8FB2639A0ULL,
    0x2ADFF75217325A67ULL,
    0xEE2DD07680CD5323ULL,
    0x5B1545C8FB2639A0ULL,
    0x2ADFF75217325A67ULL,
    0xCFFCF9CCFFB1A948ULL,
    0xDE797F2489DF0DACULL,
    0x39,
    0xDB,
    0x72,
    0x3B,
    0x70,
    0x21,
    0xEE,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseCSalts = {
    {
        {
            0xE6940D65B4A552F3ULL, 0x8AB011BA542BAF99ULL, 0xAA02674AFF20FB1BULL, 0x1D66BEBF6A055EDAULL, 
            0xF4639C17A950B15AULL, 0x8728B95FDD3FBF13ULL, 0xB14996108DA16480ULL, 0xD4CEF378DB7106E2ULL, 
            0xCC9A2B6FC5A71276ULL, 0xF878B0549F738C2AULL, 0x54DEAA6B70435970ULL, 0xAC9EFB04652FF9E6ULL, 
            0x01C6EF3F623ACE22ULL, 0x4FA6EC9636665E6BULL, 0xA6921D40CE05F930ULL, 0x84977E4F749B3D58ULL, 
            0x47E8597B5A7F5CC2ULL, 0x5D921184860B45ECULL, 0x17597C067085084BULL, 0x4854FBAD77D24612ULL, 
            0xD17C0AA8F4CCC047ULL, 0x6BB27A340E5D88C0ULL, 0x630FA7AC3B05286AULL, 0x6C7E6BCD5BF052FCULL, 
            0xAC6F07034177D2F0ULL, 0x3EB94B001F6EA001ULL, 0x1BB5BEAD6C6C1844ULL, 0x6D61F7CD42568CEDULL, 
            0x98921C9D97A6715DULL, 0x14A75158120988E0ULL, 0x1BCAAAA387EAA011ULL, 0x7703FB02D6A4771FULL
        },
        {
            0x7122CD4FDECB6156ULL, 0x6328A653F9F1A812ULL, 0xAB1CA4CA0A6FA03EULL, 0xD87919C3D555CEFFULL, 
            0xB2788D3B1C4C721CULL, 0x7D6F93351E9B080EULL, 0xCCF55D3C12810BB4ULL, 0x263FEDB3EC276A08ULL, 
            0x737C37B8F13629E4ULL, 0x5786B34CFA4E82E8ULL, 0x0DC1B53F3031323DULL, 0xD27FB03DE9396C9CULL, 
            0x42CE717B3D1599A6ULL, 0xA46392958ABA4464ULL, 0x0FDEAD1F5E0B3161ULL, 0x758BA03B7CDF5A5CULL, 
            0x5B6D182C2DEF271AULL, 0xCD1FFB8A630D49C4ULL, 0x7928CBF59F87014CULL, 0x19583AA89AB9DF2CULL, 
            0x2EB63DCD1687CDB2ULL, 0xC4B0F8A1B7C51A25ULL, 0x97E088416E632D07ULL, 0x649E9ABC37DF84F8ULL, 
            0xD69E37AE62DCCA55ULL, 0xCB4F4B4BA54DA29AULL, 0xF2B0B75B320280C9ULL, 0xD113326762A535C2ULL, 
            0xD0C27BB66EF535A9ULL, 0x479100837CAC0460ULL, 0xC5C1B07F33841943ULL, 0x81F267DD9FE22BF1ULL
        },
        {
            0x5B191091293A67B5ULL, 0xD5FD1488FF2522F0ULL, 0x93C20F071E3E3146ULL, 0x4582546C2CC2E6B6ULL, 
            0x316BDF78F45C3AEEULL, 0x174A69692D1775D0ULL, 0xB50C6A8CF18C88D4ULL, 0xB1D66F6B6B67590BULL, 
            0x8066056AF553A3D3ULL, 0xC15110F89405AFDCULL, 0xD66C5531A6C77257ULL, 0x9C8229E728301775ULL, 
            0xD01F3D04A0F76C7BULL, 0x85771D9818589A06ULL, 0x0BB64362F934FC99ULL, 0x2B773BAC14BA03EEULL, 
            0xECD0DD9B18C9B901ULL, 0xEC766AD02AA5D533ULL, 0x672D11605096B382ULL, 0xAF36C2E8D4281A98ULL, 
            0x7B7C23A451886529ULL, 0x113C7F380B139F0BULL, 0x94F645A753637A10ULL, 0x216CC1653DDB5E42ULL, 
            0xE7923D1F7356EA16ULL, 0x62D431ABD999ECE1ULL, 0x574492CA297B86BCULL, 0x544CD527B13D013AULL, 
            0x6FEAE49965E616A2ULL, 0xBDFD16B2A7A16643ULL, 0x11609426FAC9E3ADULL, 0x1E227C614926D6E9ULL
        },
        {
            0xC390E7617D8439F3ULL, 0xEA4DEC2ED0D6BBABULL, 0xF26482CC00C9B095ULL, 0x030EF23554804039ULL, 
            0xB36596A63784484BULL, 0x695B00E69090489EULL, 0x1EB6F4520199C10CULL, 0x4FDE4F50AFB8EA91ULL, 
            0x24B240DBAEC19DD3ULL, 0xCEC6E06E2CC1A587ULL, 0xE68AFB9162626A13ULL, 0x646BF258F1DCB588ULL, 
            0x4F7476F432A290C5ULL, 0x52A384E63042A31CULL, 0xD92816147C869C2EULL, 0x2414CE75911BAA61ULL, 
            0xEB1272FB4D9F486BULL, 0xDC43366E53278C4CULL, 0xCE372BABA0FA7FC3ULL, 0x29CD3233518169B3ULL, 
            0x1EA5A0146E01E45FULL, 0xDEC17BAC2B1EAE89ULL, 0x71364D653D72777CULL, 0xB392CDD9CF631617ULL, 
            0x443BACB17A846456ULL, 0x1A826AD455BC3667ULL, 0xAE6DE563AF1C55EDULL, 0xAE9AB1DF5FA19E81ULL, 
            0xB720BA9140224A00ULL, 0x3526C4B75211E1CEULL, 0x8757C57167DB3BDEULL, 0x8F916DF3D57AADE0ULL
        },
        {
            0x9B6678B130C24F4EULL, 0x48099DDD7DA4917AULL, 0x321E62F1F95C8BD0ULL, 0xD87E25114D9CA0F0ULL, 
            0xA2BBDAD0BB40D92FULL, 0x95D3E45F6B5899BFULL, 0x7EB902C49D81E858ULL, 0x6CDFA1A1EEF25A96ULL, 
            0xB13AB33160058891ULL, 0xB3221AC6F4232E4CULL, 0x78F5C18181BDA3F3ULL, 0x0B7EA2E9834E7F43ULL, 
            0x92906AF3F5D06438ULL, 0x3E30411CFB448370ULL, 0xC522BE803650543EULL, 0x1BE1582A23C58FC4ULL, 
            0x9C9117A23C1F7321ULL, 0x50F5BED463E4B9D1ULL, 0x10E79EA31ACE325CULL, 0x932556C1F5C0BD18ULL, 
            0x62721A3550DFE465ULL, 0x0BAD8AEACFC78C4DULL, 0x19D9F44154D0E784ULL, 0x409CCB534F365FC7ULL, 
            0xBF7449B63EFA1962ULL, 0x89CD35D575057EA8ULL, 0x7F6BE34526959D69ULL, 0xEBC6759ECCE18780ULL, 
            0x71CF57FAB33D701EULL, 0x95193964544EA2C7ULL, 0x6BEE4D4E8BC7C899ULL, 0x15EC87DBFAC8D544ULL
        },
        {
            0xE61CB02B32ECED41ULL, 0x1322A8054B7F225AULL, 0x55F472A4316018F2ULL, 0xA29C21E7AF4ABA3DULL, 
            0x70A0D2383788B7EEULL, 0x53946BCD9A1524F4ULL, 0xDB930F1AF6BA07FDULL, 0x9C222F3C39043BB8ULL, 
            0xA198A03ED7EFFE3EULL, 0x39E95F4CFAD67464ULL, 0x6B4CD8C4A81B29FBULL, 0xF22806802DE20556ULL, 
            0xE2E916FB69C4FF87ULL, 0xEF1692A140F5EC26ULL, 0xF8680B7B09F06EBEULL, 0xEA99433787F99B24ULL, 
            0xA50A845F961D2851ULL, 0x541E9D4F28EF703AULL, 0x92347D513F2181ABULL, 0x6FFBE9EAD2E1B72EULL, 
            0x23AFA03ECDFA7640ULL, 0x772A788D60C39F0CULL, 0xD86EEFF574E61884ULL, 0x32A5F8438A84DDA2ULL, 
            0xA69235C9C200D349ULL, 0x5904021678C60A0DULL, 0xC91A8DE39B31338DULL, 0x61BB07598D5316C2ULL, 
            0xB472A8BD3F5F0673ULL, 0x26A16189C9BDB0AEULL, 0x9B9CECCA7D9553F6ULL, 0xA5A5E59FD868514CULL
        }
    },
    {
        {
            0x550C663DEAA3A3FFULL, 0x1E24FE5B25A8F8E4ULL, 0x069DD3D3E92388B0ULL, 0xB084755813766C3CULL, 
            0x5A8C101279996E65ULL, 0xF4F633AC522D5C8EULL, 0x0B5460397E6DDEC5ULL, 0x05F165B61D2D4CD7ULL, 
            0x0E5DF115066A6E64ULL, 0xFABD059A4E66B874ULL, 0xBC787319339F4C95ULL, 0x95FCB3D9FF7B595BULL, 
            0x0A85D571E5ABB9D9ULL, 0xEC7471FDA2986FD6ULL, 0x04E05EF86EEB732CULL, 0xC90C3CD81CA1B5E6ULL, 
            0x46BEEF92D4C5FC59ULL, 0x52952D5F5AD43585ULL, 0x48014FAB6929CAFAULL, 0xCC86741B75091FA6ULL, 
            0xDD7B48D4C24268B7ULL, 0xEFF1D541AC8496A6ULL, 0xA35C729C7B4C51C5ULL, 0xA3322859EAA9FB16ULL, 
            0x59A0FD151DB4971EULL, 0x425DCF424BBF1FCCULL, 0x87F7249A6DC1D57BULL, 0xDFF2D33E462A4CFFULL, 
            0xF11DE84F14524567ULL, 0xB9480A29C6DD5073ULL, 0x14E3DDE7AE1983C6ULL, 0x8D88C59145CEE116ULL
        },
        {
            0x419FDE2DE48EE52AULL, 0xA4C62CA47C07953EULL, 0x96D1994FDD6134B1ULL, 0xDEBFF3142E8349DDULL, 
            0xBA9CD375C9BB1E88ULL, 0x2310E3895EF2EF64ULL, 0x5F22F1115328011BULL, 0xF91981C1E5BE2F9CULL, 
            0x9B88EA7CC146283DULL, 0x3BE6088F7C9575F1ULL, 0xF9067B4CF06CC145ULL, 0x435A11D2F39FECCDULL, 
            0xC835D552D43F2811ULL, 0x16562B3C615AE72FULL, 0xE3A54D483B49CFA0ULL, 0xA318E0412C4DAFDFULL, 
            0x263DEE4D77AB732BULL, 0xD626F190B1663451ULL, 0xA6CD1B002655C876ULL, 0x88F31B0EC8A08979ULL, 
            0x601644B09AB0828CULL, 0xAC9DDC25F7242389ULL, 0xB1BE17273EAFEDF4ULL, 0x83EA082259D1CC4EULL, 
            0xC2AE0A0F3B89B1A4ULL, 0xF1F182D0681289D5ULL, 0x49DEED37B69D4BFDULL, 0xD3182ECCE2579DD8ULL, 
            0x1C2D11F59D3098DAULL, 0xA565F9B70FA29B08ULL, 0x1009E6DBB32ED285ULL, 0xA09F9896955E29C7ULL
        },
        {
            0x98C986F8B50EA984ULL, 0xE1DBFFD4B293EEF9ULL, 0x75F82A3102829FDCULL, 0x2DFC73CF83183BF4ULL, 
            0x8123A46C4FB3002CULL, 0xC8FFFFEBFCA5A4CCULL, 0x6C97D204766D9146ULL, 0x01593B428353DF42ULL, 
            0x26E247851E804435ULL, 0xB5C4253A868DF6F6ULL, 0x9E80C2BF82C860A6ULL, 0x6DF200CA7DE91F9CULL, 
            0x664B44248757FD0BULL, 0xEDC30BDBBFDF37EAULL, 0x2BBD73900ED01151ULL, 0x842E55D78C7718D9ULL, 
            0xD4671646FA77680EULL, 0x9AF64A54CBD79373ULL, 0xAAF022306B7D606BULL, 0xB7C4DA9B9E89B261ULL, 
            0x8DA31899583A03A8ULL, 0xD65A42199F6EEA22ULL, 0xE57FE759145D8D0CULL, 0x57437CDD57E5771BULL, 
            0x8C7F73840C14FE94ULL, 0x38A2AD20F72BDAB5ULL, 0xBE44F81928611532ULL, 0x9E533BD83E1CC16BULL, 
            0xDE9B1AA8F9DADB7FULL, 0xABF2B4C3D569A892ULL, 0x5FAB30F30AF52C15ULL, 0xE12FA897AEA716E9ULL
        },
        {
            0x17ADDAA1FC5A5F4DULL, 0x206872648A42C8FEULL, 0xCE5038B411383540ULL, 0x08FC47E12BCCE3D1ULL, 
            0xA5D1A6E9DEE5A8D0ULL, 0x0739031385D46A67ULL, 0xCEF436AFDB93676AULL, 0xE1B77BBCD993750AULL, 
            0x4ED07F467BE8F4F5ULL, 0xC87BEAC33816CFADULL, 0xDD3490320707B4EBULL, 0x4EA763AF78AE9E29ULL, 
            0xCA0D3FF22CD21C9AULL, 0x371F6592C19B7363ULL, 0xEED7C29946A07309ULL, 0x19E5C05F462C9024ULL, 
            0x649BC808B0707099ULL, 0x7B45379ECEECB256ULL, 0x9245F3BDFDCDA4D9ULL, 0x6902DDE8429E2246ULL, 
            0x2499FB9A4039C881ULL, 0x77B34E6798745718ULL, 0xCDE6C205CC58BDA0ULL, 0x3F5E3501BE6F28FDULL, 
            0x301B6A4162A95A92ULL, 0x94BF2552E66FEBFBULL, 0x780411C266D95F64ULL, 0xD9CA9FDD6ADE8554ULL, 
            0x82EA8784CF693CB4ULL, 0x07B5BEA3EDF51002ULL, 0x0733DC4696A35932ULL, 0xCFF61AACFA7B8F55ULL
        },
        {
            0x62E16B62633098FBULL, 0x3B3D97D9BED946F5ULL, 0x645A353C5319450CULL, 0x68687A78FBBA956AULL, 
            0xD776608E1EF43E99ULL, 0xD58B32B090262917ULL, 0x956062FF05A5A4A7ULL, 0xF20CC251C0C3F3C0ULL, 
            0xAD226A5441D1A382ULL, 0xC3E7A81DBC47DD70ULL, 0x98ADE951EA38FBB7ULL, 0x8D78D696ED326FB6ULL, 
            0xA9DD5C072C32FDBEULL, 0xEFDB6A3DC3CCFA29ULL, 0xDB3291827C1F8491ULL, 0x667AA7DF29ABCE73ULL, 
            0xCE021FEF827B6947ULL, 0xD6AD93DACF1ADA5AULL, 0xB1C7BC06F7A752C0ULL, 0xB4B37603E27ACC79ULL, 
            0x33F4263BC8B32DDFULL, 0x80C39DD73330FC4DULL, 0x09553A58684179D3ULL, 0x1C7857C280ACC944ULL, 
            0x999EBA3A66F4D73FULL, 0xD2DEFEC1E2C5642EULL, 0x846DA494D988453EULL, 0xA366B7A32559F65BULL, 
            0x6600AAF15BFB7685ULL, 0x7C91D053AEC00BE1ULL, 0x2F6730B29B7F9214ULL, 0x58A9D12F72DE7E43ULL
        },
        {
            0xF19B58C971BB9F3FULL, 0xB684C884EE17E011ULL, 0x34C9CB1FA8403CDBULL, 0xEB36FA9D0779311CULL, 
            0xB84D766C6C812FE3ULL, 0xB57AFF21BFA79744ULL, 0x98D492E3636CDAC4ULL, 0x3B7EE3F35988AAD9ULL, 
            0x7AE75D1F7FB55A65ULL, 0xDB070CD5CD9DA8F2ULL, 0xD99DEEC15AE1DFC8ULL, 0xD15151688A8877F9ULL, 
            0x2420FB1B35BC5DC9ULL, 0x25770EF6D7F06945ULL, 0x40F724996623396AULL, 0x50A9B7D777959717ULL, 
            0xA17C41F1250C29A7ULL, 0xC0322E6979F14340ULL, 0x4CD8742F16F51CF1ULL, 0x651372C2028F4D88ULL, 
            0x9265EA9F1305B041ULL, 0x03DB66EC5D38A2C1ULL, 0x22C05E64C1C32734ULL, 0x0C6C3E499C85DB81ULL, 
            0x6B33B66C7D2064D7ULL, 0x331043C0F176F997ULL, 0xF63CCD1E9BBBF800ULL, 0xB43F90B89DBC3E7EULL, 
            0xEFC878D0DDFC899AULL, 0x8584129BA7231570ULL, 0xF124D36C728A6113ULL, 0x0C13768B9B32E63FULL
        }
    },
    {
        {
            0x5DAE946A45381170ULL, 0x1C2FAC0AD32C0298ULL, 0xC4BEB925BFA0996AULL, 0x2D667C6E3F541741ULL, 
            0x7197C8F696F12C24ULL, 0x27004CC8417F59DBULL, 0xDC5C4D9353FDD8D8ULL, 0xBB0EBD3E815315CEULL, 
            0x4C0FE0D2305BEB9AULL, 0x8BF764E779364417ULL, 0xD514B7A90F79A317ULL, 0xD9B44504D3F5611CULL, 
            0xCDA0F6DBF6FF1EDBULL, 0x5E027EC1D694F194ULL, 0x5751416A097FF7EFULL, 0xC86D37BDDAC6B406ULL, 
            0x2D9FA887BC4F4E0CULL, 0xC4265BCF674A0A99ULL, 0xD4F0ABEC59E6EB0FULL, 0xF377AB4158E5204AULL, 
            0xFD01DB2CDB0CF1CBULL, 0x168C28D8374A349CULL, 0x59F519CD2E4D5858ULL, 0x4705FBAFF33AA9DFULL, 
            0xCF3C35C290A079A7ULL, 0x0BC04EA5393B74C5ULL, 0xC04E88CACB7CC697ULL, 0x98D4FB40124EB946ULL, 
            0xC5B890BBECAC9487ULL, 0xC63A5957A0024C11ULL, 0x0D3E1FFF3B072008ULL, 0x7F4E80A1BCCE452FULL
        },
        {
            0x41A98F79AF47EF5FULL, 0xB9D6A31456C543FDULL, 0xF9BE611AD5A4BFD6ULL, 0x508E3880A660066DULL, 
            0x1EA1FBBEF7C9CC5FULL, 0xA8F993D80873539CULL, 0xCBA16DEF3B16515DULL, 0xA3E521B38FDA1347ULL, 
            0x84A62F1E2973C5E3ULL, 0x3B0BB67D304D2E94ULL, 0x32B74608E97A28EDULL, 0x21F047F20F56B38DULL, 
            0x37CB6DCBE51750C9ULL, 0xEE005789BD72B526ULL, 0x306658B8B5E773CBULL, 0xE7C5259453E02B10ULL, 
            0xE1E5C54AE5218A3FULL, 0x79116B96AD1F5B8AULL, 0xD26E994318FC5222ULL, 0x8ACD8C752F513B2EULL, 
            0xEBD9DE3737C3B6B8ULL, 0x94A8E26F2C79A672ULL, 0x3786EA8DC52B9FBEULL, 0x48D5D22CFE0F6ED4ULL, 
            0x2EA8FD275A66A240ULL, 0x783884762BBF4B60ULL, 0xB1B0A17CF02536C6ULL, 0x3FFB263FC09846F7ULL, 
            0xEAA61FFCEFAF5120ULL, 0xF47172982A8CAC5EULL, 0xF7A3C1908109524CULL, 0x56C155062DB9B74EULL
        },
        {
            0xA8A393EF0DEE1257ULL, 0x68AB0B33C84DA63CULL, 0x60B7C048445C591BULL, 0x1C6A03FCB930BEABULL, 
            0xA3DEBA4D83F56759ULL, 0xA3E2A7EB61104D14ULL, 0xFE9F0FD7CAE347D0ULL, 0x7E8F70415804C5BFULL, 
            0xF7010B599DF386B4ULL, 0xF17F647AE6E4A321ULL, 0xAD8DAB68DE5B4616ULL, 0x73A4B0B77DC4AB58ULL, 
            0xCB3198212CE67381ULL, 0xF1B53505EDF14B6EULL, 0x96396E09213BF29DULL, 0x3AADF0BB4B0C660FULL, 
            0xAB0DCDD068940575ULL, 0xF7E08B953EF8E4C3ULL, 0xE8BA08353747C45BULL, 0x084B0BB8B37BF725ULL, 
            0xE1C0E0B2193511BBULL, 0x35903A648AB43AE1ULL, 0x83F50BDE7E3C033BULL, 0x96DB33AC4F9605E0ULL, 
            0x318985F53025E459ULL, 0xBB8B1F0C1786292BULL, 0x44FB3E0D3DB219EDULL, 0x85EAA1D61458EBB7ULL, 
            0x63ED2C14286962FAULL, 0xC28CF84C0191C9D8ULL, 0xDC43D773AFDC02B6ULL, 0x8178C2A8643ECC7CULL
        },
        {
            0xE7D9155D6597A70EULL, 0xC7BCDC5C275B2461ULL, 0xBBEF4088D17C3A15ULL, 0x24274F0728664423ULL, 
            0xF3EF032786A07E2EULL, 0x4508FA117EFF21FAULL, 0x54E61DF184DCB536ULL, 0xE0BFF439B38C1F7BULL, 
            0xD06656C2AFEEAF2DULL, 0xAE0607F4791EB35BULL, 0x857B590A3DBB68C2ULL, 0xE0B82B67B377BF48ULL, 
            0xCE17F4772EC79C7FULL, 0x168248A6F698E283ULL, 0xD02CCFBA4DADE9B8ULL, 0x16BC2CAF776F2DA3ULL, 
            0x2E3631D623DCB622ULL, 0x410FB9B6C7E0B5AAULL, 0x1F5CE63FECC3747FULL, 0x69D3EF5862C2A35FULL, 
            0x1A2B944399F8C18FULL, 0x3DE1545D1871B6A3ULL, 0xB5BB639F336397A6ULL, 0xA5295381D63A0343ULL, 
            0x2F89D75C1300409EULL, 0x9362417C67996DCAULL, 0x12579B8C2398DA29ULL, 0x8EFE46E2CA67A84DULL, 
            0xB881302069C042B7ULL, 0x9FBAC9F65798F731ULL, 0xC0F5BE79D045FA70ULL, 0x3AACD5CCFB3F1091ULL
        },
        {
            0x7D23F5147EF2C2E3ULL, 0x68195D015C9A16AFULL, 0x16555A7B22D925E7ULL, 0xE807967325573112ULL, 
            0xA6A2C9CD4875FD49ULL, 0x2133EEF900C7D870ULL, 0x5E8892B956804553ULL, 0x96BAE5405C6986D6ULL, 
            0xB5FC4E2BA967654EULL, 0xBE38A011418B43EEULL, 0xAA724BC1E0D83F2EULL, 0xC0952E9F486B6348ULL, 
            0xDAC412BD3884BC57ULL, 0xF61CCEE9327738E4ULL, 0x19C8C5D1BA3DF57EULL, 0xA6088B1C5A66DCA6ULL, 
            0x703F30264CAFC9F9ULL, 0x9357C8E89695B35EULL, 0xA57EC1C5204F3F94ULL, 0x305F6BC903A69379ULL, 
            0xECD84B56FAB5483EULL, 0x04F44769DA7972BAULL, 0xF2AABEC3C8E909A2ULL, 0xD248783E70085983ULL, 
            0xAEACAD99524DFB09ULL, 0x2DF5AE383B6C2D36ULL, 0x7DC331AF6E34C960ULL, 0x11ADABCF00EDFA05ULL, 
            0xFCF05CFB485B6708ULL, 0x31340CDC6565D39FULL, 0xAC99F536426EE84FULL, 0xDEA29968D39C50ACULL
        },
        {
            0x5644F46FBD7CD322ULL, 0x095858C9BCA3E55CULL, 0x27AD88B920376A8FULL, 0x25E98EE3422366D8ULL, 
            0x46433DB9003C6CADULL, 0x95F37ACC5917D30DULL, 0x561E0923D29FEAEFULL, 0xF0F4A0F134C07F13ULL, 
            0x81C289C93688A112ULL, 0x8EAAA60DCA62E722ULL, 0x91B6AF4B48FC1658ULL, 0x97DA7FF8D5034EE7ULL, 
            0x1BAC07F23B5DBFF6ULL, 0xDE069B3D40227111ULL, 0x724162EE4B1A4ACCULL, 0x26A69DFD15045357ULL, 
            0x0188EBB7F0A1074CULL, 0xFA94547C915B21B0ULL, 0x1347E8D6A62B3388ULL, 0x5127F51D677D0A24ULL, 
            0x56C40289D29E8641ULL, 0x8E9B9E2D9E2E9FBDULL, 0x2DCB202DD56CF048ULL, 0x4F342F74093C9BB6ULL, 
            0x431D181868EB0CCAULL, 0x662C5F97BB37C553ULL, 0x4C31FC19DC8F627AULL, 0x59EED081368EBEF6ULL, 
            0xDD4646497B2DBC64ULL, 0x774D445F409E717AULL, 0x326C01B3AB8314A3ULL, 0x4973F1ECBA0A69B8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseCConstants = {
    0x473453F8DF3EAC58ULL,
    0x43C4AEB7ED125159ULL,
    0x9BCBEB886710D33CULL,
    0x473453F8DF3EAC58ULL,
    0x43C4AEB7ED125159ULL,
    0x9BCBEB886710D33CULL,
    0x35C4660841A687F3ULL,
    0x847165B2FD5496CCULL,
    0xE7,
    0x3A,
    0xE5,
    0x9C,
    0x20,
    0x56,
    0x06,
    0x57
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseDSalts = {
    {
        {
            0x9B21DCCBB4057DA7ULL, 0x9B6DD1DA93984FB5ULL, 0x89DBF21A1B7CAB17ULL, 0xF79759FE06499C5FULL, 
            0x0A05C64D35458DB7ULL, 0x4A859330DC8B92EFULL, 0xAA64F9F2D5F84785ULL, 0x9ACD37CE57DBE2EAULL, 
            0x9DBD54ED05758D6FULL, 0xA760B16B25059633ULL, 0xFF5E044F4286D1ECULL, 0x31E4E55E57B096ACULL, 
            0x58FF4F13738E48B4ULL, 0xDDF838F3A1C89444ULL, 0xD24CFA280327624AULL, 0x9A9527551611CE63ULL, 
            0xAC7905649887BAC2ULL, 0x7616268EBC2B57BAULL, 0xCEDEF0B84A82D937ULL, 0x629AB8C8BBAF5A29ULL, 
            0x7B80AFE38C1EB09DULL, 0xA96D68911184C205ULL, 0x65FF50FA6166FA9EULL, 0x7B813C4BA352EF89ULL, 
            0xE360CA47318FD974ULL, 0x55A97646AF42BB8FULL, 0x83D4F6D20FFC6586ULL, 0x8517418CEEBE3F7FULL, 
            0xC7CD95AD39A34DC9ULL, 0x19DC7B291CD73BEFULL, 0xA2C41609F0B1CF31ULL, 0x6EAD8E50DE02B809ULL
        },
        {
            0x579FE6D669B2A7E7ULL, 0x6268DEBC494B1947ULL, 0x970B9351451493F3ULL, 0x6D4786683A728B43ULL, 
            0x6576DF632C8A02EBULL, 0x6625023A62ED36EAULL, 0xAD5E83DD5664F367ULL, 0x0D32FCFDE61919BEULL, 
            0x27CFDA566E5334A1ULL, 0xBE1678738D3F9E7BULL, 0xF431B8533E727643ULL, 0x3E30FF0ED10FAF9AULL, 
            0xE36C1B925A3F35F9ULL, 0x7A7626B7C4D7F2A6ULL, 0xB93965158F88FBAEULL, 0xC6DD702ABF2EC872ULL, 
            0x26341DECBB0D73EFULL, 0x416BA2A1B60623D6ULL, 0x3717323B2F22DAFEULL, 0xDC959228AFF4662EULL, 
            0x167FED4E29A0EC60ULL, 0x23C9D415F3E60F6EULL, 0x159B4499D8EAE252ULL, 0x9EBB535AB561FF13ULL, 
            0x2890B37FF4240570ULL, 0xAC0E497DC5953F6CULL, 0x3CD6E0DD8D382273ULL, 0x11CD3B444DC8EDF6ULL, 
            0x9A1C92D50508A149ULL, 0x0A062621ED51E450ULL, 0x38BD484FE3B89E2FULL, 0x10124CCFBF227C86ULL
        },
        {
            0xD0C533F0D1C344CBULL, 0x5CEFF3227D3ABA28ULL, 0x784DCEF1A7947B20ULL, 0xC3B55CE1B4DF0C08ULL, 
            0x3DC731EE158A5609ULL, 0x9CED3640B1D08188ULL, 0xDD4210FD84190062ULL, 0x7ADAC033B27BE014ULL, 
            0x5EEC32392CF2C2E2ULL, 0xBFD18DDFE4D87139ULL, 0x3076CEEA1C8C1CD9ULL, 0x5547D3D7027DF1C8ULL, 
            0x54CF0F0BFE1BBBC2ULL, 0x4DA8C4BCA177D499ULL, 0x880B9A099649D5F7ULL, 0xC2F90C445416AA4EULL, 
            0x3E511A35554D8516ULL, 0xFD9C822095EFFA35ULL, 0xA3477CFEDCB8044FULL, 0x9C980F54FA04CF1CULL, 
            0xACCCBD9E85467D67ULL, 0x087A04952AA272CEULL, 0x62D65D53ACA72410ULL, 0x528A30CBD8DDA108ULL, 
            0x00B1794C262D6874ULL, 0x415DA66D320D89BFULL, 0x625D35BEF3ECD71DULL, 0xE90C2BD0ECB0703FULL, 
            0xCC9B9DF8A6C05225ULL, 0xD9A1C053CB2FE808ULL, 0x32D5717A176F33ABULL, 0xF38A7926BB3028EFULL
        },
        {
            0xEA9D48C8BD0CED7EULL, 0x08D2184D7DD07165ULL, 0xC8B60FD13926726CULL, 0x1FB08103C41B4FAFULL, 
            0x37B4F2C35233ECD2ULL, 0xF89C00A8B8396401ULL, 0x23D02868A15813BEULL, 0xC96745197F3DF1DBULL, 
            0x6AD7291D7E026D6EULL, 0x1D7DA2524E5BC7A1ULL, 0x76EEDE20863AE21CULL, 0xB4AEF38E082D16F6ULL, 
            0x5BA1902CA94BCBD1ULL, 0x30597B5F09478A23ULL, 0xC7A4CB32E91D3C61ULL, 0x03602C5D4070B912ULL, 
            0x64148E65739880D5ULL, 0xF26E452CE8DB3803ULL, 0xB23AFBCE1BA678D8ULL, 0x6554816ABADD4137ULL, 
            0x06F3081B96986A8AULL, 0x822C5235144220B9ULL, 0x962E7ED97491A11EULL, 0x49D23C7D4EF8731FULL, 
            0xF28D395A258181BEULL, 0xF1E0A2BAC8E62C23ULL, 0x6059601976B45CDEULL, 0x08F2D50FFE3E0B43ULL, 
            0xD8B76B2719097E8BULL, 0xA2547ADD9675A1BFULL, 0x738981F66E580E1FULL, 0x3A138619D1689BE3ULL
        },
        {
            0x9775DC426448EA46ULL, 0x35D03FBA2EBA248EULL, 0x53BF7A681B39667AULL, 0x5E867352EC380C73ULL, 
            0x605170D9F1E8068BULL, 0xC0E6D4D74816DBEDULL, 0xD42D32705A978CABULL, 0xF2D1486AB403C181ULL, 
            0x7B2DFD45911B0526ULL, 0x6A9362520E4881ECULL, 0xDFFED3EE2B7F2897ULL, 0xC7D28E67692AA02BULL, 
            0x7637779EBE38FCEDULL, 0x07619C383C5D4DCCULL, 0xED44AFB10E499019ULL, 0x1C9E13FDCCF9136CULL, 
            0xEAC417F787E77CB8ULL, 0xBA4CD62A02386E8BULL, 0x6DB6ECF38A940897ULL, 0x974F189EC612DB19ULL, 
            0xCBEB18996D17C336ULL, 0x2908FA7AEDC21ACEULL, 0xD653CA2291C8961EULL, 0x525207F4B8A6C3F7ULL, 
            0x9C1E57B3B4D2808AULL, 0x00189F0420E55CAAULL, 0xD74F2D97799EC35DULL, 0x416105E6C2AA383BULL, 
            0x8839C795D2BFCADBULL, 0x020E226BC30BC942ULL, 0x28B60CFFE76F37B6ULL, 0x860CCE02F61DC7BDULL
        },
        {
            0x9D895A4CB90C4040ULL, 0xB69DD4E4F2531311ULL, 0x2CE58EBBE77D35D2ULL, 0xDAB115724F31B7F0ULL, 
            0x0FF050894F00DCCBULL, 0x210795C57BA8BEDEULL, 0x90EBFA95A9EEDE1EULL, 0x2935859E909583C6ULL, 
            0x5520D2F27E1F02A5ULL, 0x3F7FF42EAE4DAF8AULL, 0x6B1C3E64026F7617ULL, 0xEE5BB18786F15D47ULL, 
            0xA88141FE8FC0550AULL, 0x71845AA656870D48ULL, 0x134E377EFF8CE9EBULL, 0xC40D6185DF2DE425ULL, 
            0x1F26D6C78A3EF612ULL, 0x1FFB27F4561A8C94ULL, 0x04256F825056C5A3ULL, 0xA442A4D17C3E2D8AULL, 
            0xB4DDFDD082660ADAULL, 0x3D8B83F065A5F1D5ULL, 0xF9C8A5B4DBE778FDULL, 0x15F4030A93A28887ULL, 
            0xBD6CFB77E5B29656ULL, 0x008C22E66C62C996ULL, 0x6B8DF1CC3A4D140DULL, 0x66E3AB3A614728D4ULL, 
            0xC2DD48194DA5D0A1ULL, 0xBB46562E16060669ULL, 0x348F6AC17E5A20C4ULL, 0xEB2A8C4865125CCBULL
        }
    },
    {
        {
            0x54519AB9A5E84671ULL, 0x715D4A850699594FULL, 0x1FD498FEEF3CF0E6ULL, 0xF4E18DF46417351AULL, 
            0xD3C4ECF49E11A5DFULL, 0xA6BB5CCF6E7FCF54ULL, 0x064D35BC7CC288AFULL, 0xEC8233FDECDC51FAULL, 
            0x302396B1542B8259ULL, 0x943536DF36E732C7ULL, 0x8AAE59827BD1F5B8ULL, 0xB7A62FB4A0CD0A1DULL, 
            0xFC9476C390CECD35ULL, 0x8C4101398097F2FEULL, 0x95A36DCA5D6CF6EFULL, 0xAF792ECA7C9FCBBEULL, 
            0xAC4C85904D8E3838ULL, 0x6D7389E1C789891DULL, 0x4288B5CF1BD38849ULL, 0x4CB52B3C6CB1D4B0ULL, 
            0xA9C10C7043B67EABULL, 0xF328EB396E0A2811ULL, 0xB2BB51168915AF64ULL, 0xBBC37C3CDDF39E82ULL, 
            0xE3ECA168AF153D27ULL, 0xC45E0D66BDCE3A6BULL, 0xD2E145CE9EE457D0ULL, 0xC8D27423B44546A7ULL, 
            0x0235B8F748213C1DULL, 0xA57BD260EBFC2364ULL, 0x344F3C36476FE88FULL, 0x502797F33350099DULL
        },
        {
            0xE15791F2B60ECE1EULL, 0x2ACBB0EAC3B5951FULL, 0x78E446D667B03924ULL, 0xB76E568C7F8DA4DEULL, 
            0xAA0E7F6013725AF7ULL, 0x7E06DF3D324F3B9FULL, 0x41D9A1C0188A1622ULL, 0xCB24D4611F3985B7ULL, 
            0x175CD32C1C8EDB1DULL, 0x47F8B499EA3D0257ULL, 0x2E28CE36B929D59CULL, 0x5B756E77123F1A66ULL, 
            0xEE37F1422B534DDDULL, 0xBA70DA8BE4E7E00DULL, 0x97AA07EF8144C88AULL, 0xF9A6E752B9C5BB74ULL, 
            0xD2C0224295F00B22ULL, 0xF1E58BC9FBE1A938ULL, 0xEA82835D92C48FF1ULL, 0x6CCE052BCA371D58ULL, 
            0xCBB9BCBA7A193BBDULL, 0xC723963560F211A5ULL, 0x0CA17A1691D8210BULL, 0x69B9919182A6CE5DULL, 
            0xB32215A6D6F1D81AULL, 0x8E258102B0721427ULL, 0xA57C38FBDF1A94C8ULL, 0x63AA38CFF97D0F64ULL, 
            0xFE4ED1604650FFE7ULL, 0xB631893ED0AED938ULL, 0xF5EE019C6B358A61ULL, 0x4D6FEF0DEC281EA1ULL
        },
        {
            0xA584EA4749F1AAE4ULL, 0x7C1F8949021100DBULL, 0x43EAC1EA92520D15ULL, 0x0FCA1187CA7EB1F7ULL, 
            0x72C64F44A3828FA3ULL, 0x9633A9C20BB906CCULL, 0x8C9785EDDF35AEF7ULL, 0xFC4550E188923474ULL, 
            0x034DB77C03265CB3ULL, 0xF8BE547A7C5E9849ULL, 0xEE86DCDFB02A2967ULL, 0xBEC7798CD67D1EF2ULL, 
            0xEAB07311D49D1B01ULL, 0xB5D662A255A4FC64ULL, 0x18FF341E949C91EAULL, 0x59B0098B67010EB8ULL, 
            0x6EC209336166D91DULL, 0x5F25D09F5766C7F4ULL, 0xF0D52632ED8939E4ULL, 0xA486ADCA46A7623FULL, 
            0x63D1EE510F674D2BULL, 0x92A72A39E9954426ULL, 0xD244D5CEEFF12D67ULL, 0x902FA0BB238EE881ULL, 
            0x3E3D88E4A07FBC3DULL, 0xF80A88BB73345FC2ULL, 0x6E6E8F2C1CD6A2C9ULL, 0xC9CA93AF015299ABULL, 
            0xA2D844ED766FFE14ULL, 0x8B70BCC1F354686DULL, 0xCDFD681ECB547F05ULL, 0x21D98583ADF0AFB5ULL
        },
        {
            0x523CBDEAF1004426ULL, 0x14738C853ABAF601ULL, 0x7BB3128B2D5ACEC9ULL, 0x10BB138BB3AA911EULL, 
            0xF4304A3C919D3A6FULL, 0x45D8B5B339B96C2BULL, 0xDA792320E2553CDFULL, 0x5C2A8B78149126C0ULL, 
            0x1AE4B4EABF33D986ULL, 0x3BE04AA31388EF44ULL, 0xE1BAD2068972DAB9ULL, 0x351268670484F2A9ULL, 
            0xC4A55FD50B89E85CULL, 0x3AADFD5F037D9A87ULL, 0xC36D56B599CC273CULL, 0x510CEE1A14F26E08ULL, 
            0x0A1785D7D69B05F3ULL, 0xB8FF2146EBB3FC96ULL, 0x4D1D6B800C202401ULL, 0x3347B65BB0F15B1FULL, 
            0x62622B3D1D200164ULL, 0xA2CC6B4071698FEEULL, 0x20B0B49906B5DBBEULL, 0x2E59B62402576548ULL, 
            0x6A9309B1A69E2CBBULL, 0x7E3A9DDB21F9AE36ULL, 0x74CD397350ACA59AULL, 0xA1E4CEF17EE12BEBULL, 
            0x759BDAE9FC6FB8DFULL, 0x698DF2DF1D40DFC7ULL, 0x602988B082731340ULL, 0x5F267EA1249A4DAAULL
        },
        {
            0xE062984CBE142A6CULL, 0xB92019873F1C8362ULL, 0xDAEA4B5511C17B03ULL, 0x15FDCD1590A5D7A6ULL, 
            0x2C0F3EEAD5CFA8FAULL, 0x03E6F22E12B4C5E4ULL, 0xE0452FE0E0AC72B6ULL, 0x36C7349EEF87B946ULL, 
            0x5CCD327A5D078540ULL, 0x2B05C830715D9D46ULL, 0xA060F3E56C070684ULL, 0x4A6820F75AB05FF1ULL, 
            0x00D1A31E204C8145ULL, 0x847544E90428DDDAULL, 0xB5B40C8EB50B67F5ULL, 0x26ADAB352420D758ULL, 
            0x6AB6A83E6EA86965ULL, 0x1C64FEACE8F2FC5FULL, 0xEFC74F275D9218C5ULL, 0xFAE2487119A28205ULL, 
            0x5148F712F76A2ECBULL, 0x7D1C7B6F719BBCE5ULL, 0xA7206A6DF40E2057ULL, 0x86315DB33DBADC5EULL, 
            0x48D0C0EEB021C9ADULL, 0x58FA6FC7A25CAD08ULL, 0x26FB89D4ABDFB293ULL, 0x28DF1141939A2F53ULL, 
            0xC8AAFE81C66F58D5ULL, 0x5CE64557A33F6A9DULL, 0xD5E008264E61D7B5ULL, 0x6101ADAB4CCACD43ULL
        },
        {
            0x6F24D45A5ED07F60ULL, 0x0C4A85C3F20D0704ULL, 0x3787CA906B11DDA4ULL, 0xE3F8E279909CB573ULL, 
            0xB80B4297BA3DE795ULL, 0x7DD9F089B0DEBA58ULL, 0xA0E6752BB0C3B8F0ULL, 0xD367B4B263BDC46EULL, 
            0xF46D5CED8BD8D76BULL, 0x0235F506C06402A1ULL, 0x14DE65DFDB7DD1E9ULL, 0x1E726A1695DCF643ULL, 
            0xEBC4B28CBD4C0321ULL, 0xDA7A7BA42AF2F3A7ULL, 0x526598A067FB905AULL, 0x44E9716F3E52D0EFULL, 
            0xF8BF0ABC3F365FD8ULL, 0xBBD8F41C8422D748ULL, 0x2871D1F7D67F153CULL, 0xA976A1509FB7B3A7ULL, 
            0x7AB1010E6B5F3A4AULL, 0xD0AF4C18CFA8199DULL, 0xBCF89CD95F5C637DULL, 0x944DC416DBE56F89ULL, 
            0x17046274707DACF5ULL, 0x12AA0555040D3BD3ULL, 0xDBABF79228AFEED4ULL, 0x06C37C928C4890DFULL, 
            0x6E9E634BB4C729EFULL, 0xB72A05B41AF75B9DULL, 0xB619DCB094387432ULL, 0xF1A1AEA9A036BDECULL
        }
    },
    {
        {
            0x1F90AE40BDB3C139ULL, 0x6B4FF2A00F78B50AULL, 0x122450900740218BULL, 0x9CD182488C7ECA95ULL, 
            0x7AF8EAF04340CE50ULL, 0x38DB1F8D487F0AEFULL, 0xB96894E19C9B1CDBULL, 0x57D95F887C7CA8E2ULL, 
            0xD1F7CB50077E3409ULL, 0x85DA3F6DCF128CBCULL, 0x142C78078351D491ULL, 0xBA07E03DD7BEE2E5ULL, 
            0x1797AF5FC3F3FA18ULL, 0xA40E48D292CAC294ULL, 0x86BA108CF8AB4E61ULL, 0xB5BDB394D3628EE6ULL, 
            0xA5D62C131587521BULL, 0x1B8050DC1470FE62ULL, 0xEDD6AFF91070117EULL, 0xB8E0C41004C8B481ULL, 
            0xA985ECFF7150546DULL, 0x866C41B526FCB672ULL, 0x926130B8979B8F52ULL, 0x0902AE48866AF1ABULL, 
            0x4F12C720C5BEC4D3ULL, 0x60A222195F83627EULL, 0x8094182B1FC56AA3ULL, 0x2D49D24AB54A1B56ULL, 
            0x552D378CA2F02C7FULL, 0xB8A0E3262365494DULL, 0x532E6BBAF5E26EADULL, 0x581B21AB5E1D82A7ULL
        },
        {
            0xFF81567709DBCCB6ULL, 0xD01CE4FC4C268337ULL, 0x48288EF3127C4D83ULL, 0xAFE4C1719A34BA99ULL, 
            0x72CDCA247D923329ULL, 0x286E75DE38AB8901ULL, 0x89D886818563829BULL, 0xC753AF65BE03DED6ULL, 
            0x4DF023508182DB47ULL, 0xFD4FC0FBFDDAEE17ULL, 0x1D7D32DDB6496C7AULL, 0x0AADA8AE372EB296ULL, 
            0x7DA2010E689AA0BBULL, 0x7B0155AD2D3D13A7ULL, 0x2AEF7076575A3F55ULL, 0xC2D211D6020CD086ULL, 
            0xD80CED4ED7BD1206ULL, 0xE081E36462723C04ULL, 0xD45E20DC10742C7BULL, 0xA9F3153B55C6F347ULL, 
            0xCF419A344015DCA8ULL, 0x9B46D5656D0CF8A5ULL, 0x73309281C25E5E27ULL, 0x51D47D3D070C0255ULL, 
            0x157B48FE1B7E7325ULL, 0x746DC342C2BA6D22ULL, 0xB8049DECB629D064ULL, 0x862B4C84CD52A16CULL, 
            0x6FD67D85B03F1D0DULL, 0xC9FC33BA50E5A1D1ULL, 0xC1D0CBA17BA74D29ULL, 0xA50AE63136FE85F7ULL
        },
        {
            0x0D21E1E6FF4FAACCULL, 0x301C88686538EB75ULL, 0xF2597B1C204F234BULL, 0xF64697CE6BD972FAULL, 
            0x6907A0170783467CULL, 0x649FA12206B78C87ULL, 0x82079EFCCB81E4E7ULL, 0xDA6B9D5B1DAA85D2ULL, 
            0x3090028EE7650B36ULL, 0x412A3FA26A093811ULL, 0x1B6ED9E907906251ULL, 0x2C280E3D55F545D2ULL, 
            0x0AD208BADC315537ULL, 0xBEA0CC2FE2E8B1CBULL, 0x69697884C73079B3ULL, 0xC7533630B466E5EAULL, 
            0x33DFBC894C819153ULL, 0xB0CDE481DF0EF2B1ULL, 0x715A1EA1B5052F69ULL, 0x270E2794D7D25196ULL, 
            0xDC38269EDC7CC7D8ULL, 0xDB2F37C8C35C2D0BULL, 0x80235C68598AFF35ULL, 0x1E0ACD95EEA36785ULL, 
            0x76E42547B42D110FULL, 0x42171541586A1FB4ULL, 0xECAC128A565201EAULL, 0xB4B9A2FE0063523EULL, 
            0xDAD407BD640D0BE0ULL, 0xF5CA971D6A0C96FDULL, 0x9E76F636DC5A793FULL, 0x4FFDD0C8E6EAD6A5ULL
        },
        {
            0x4C45446279E585ABULL, 0xDA66F5AF5446D769ULL, 0xB80DF03B8FD12B0EULL, 0xD9C46CAE79C4C77DULL, 
            0xF08066F0A8F2BDE9ULL, 0x09ADFD79FB0B54D8ULL, 0xBEB7CA156C6B3AADULL, 0xC8CB3198A1003286ULL, 
            0x9FC4A1476F52E43FULL, 0xEAE5D69A2438B722ULL, 0x46A2F04754C56303ULL, 0xC24E5B5A997C5738ULL, 
            0xC1FA94FABCEE5A19ULL, 0xBBDB3FC09B6AD884ULL, 0xA36EAAF43F2632A1ULL, 0x8BB00B356C0384E2ULL, 
            0xC99F982BE09EEBA3ULL, 0x0CBC1F9A2723711FULL, 0x5FF02739CFC9EE99ULL, 0x6F1E5DC7EEED3F29ULL, 
            0x0956D62ECB821CAAULL, 0xD5B68D92B3A33971ULL, 0x21EFC68831193560ULL, 0x03858118D67A981FULL, 
            0xE9380C7DC5458B71ULL, 0xB542A978CD7A9C01ULL, 0xFA165D2D82E61F6AULL, 0x30DF78703C2A6EEDULL, 
            0x6F0CB0DBA95A07E0ULL, 0x3B2F372CE8894F93ULL, 0x57FA1F02731C1965ULL, 0x0E5252C94CE5DB90ULL
        },
        {
            0xBB48E463761EFF54ULL, 0xA7356231B1D401F2ULL, 0xF9A5652391EBF491ULL, 0xB2E047C1AAA850DFULL, 
            0x1611EC0C22FDC3DBULL, 0x16BB19BF26678893ULL, 0xAC2704DC733B5CBEULL, 0x6A7937DCAFE080DCULL, 
            0xA795F56D709EB193ULL, 0x9C13FDADCA5870D5ULL, 0x21D2FDC102641584ULL, 0x5EF52C1DB9B5FE88ULL, 
            0x80BF92B78988DEF8ULL, 0xA58348BAE4C25EF3ULL, 0x125001DCAE049B43ULL, 0x5F9433354EBCCD1FULL, 
            0xDCB74A5A27E87756ULL, 0x1232455C32F15D2DULL, 0xEA5C3DE6B581AB06ULL, 0x20476F5E2FFCE011ULL, 
            0xB802619400014601ULL, 0x11BD0C9E83290B2AULL, 0xD37DF6BCE1F21124ULL, 0x9183E676AC3B0A81ULL, 
            0xF489A764A7B5CAA5ULL, 0x32806DCB9D96DEB2ULL, 0x2BC0326F512C2E63ULL, 0x544B518134B78981ULL, 
            0x171CB48A7B137CA7ULL, 0x26145A368733DC48ULL, 0xBE07402A84DF4292ULL, 0x9BDE502C31BDF38FULL
        },
        {
            0x485EE58B579E2086ULL, 0xFA696878149DFD95ULL, 0xCAC3237D755E2376ULL, 0x2C933E6629D98561ULL, 
            0x2FAC4B0D4BBC02F2ULL, 0x2CB385A9698285E1ULL, 0xC7209AEF847B577FULL, 0x2F58B67E117C4468ULL, 
            0x665AD65017B404A2ULL, 0xB6EB49CF12BBF7ACULL, 0xC5921145992A3C46ULL, 0xC0BF68480372728CULL, 
            0x63630C871D5FF34BULL, 0x119BCE1B1AE25DBBULL, 0x86AA2AD6506E7932ULL, 0x39D3AA39DA169537ULL, 
            0xB220D436EE7A80A5ULL, 0x260B979CC9BE4910ULL, 0x5446283BF578DEA0ULL, 0x2B9F25388B148ACEULL, 
            0xC7F36A0BC1FDE75DULL, 0x45610C12F8186A40ULL, 0xB69ACCF950926A40ULL, 0x93E2E021BA51AAC8ULL, 
            0x73ABFE35D2D0967AULL, 0x9330F30E1EBFE958ULL, 0x8BF3FCAF9BA937B5ULL, 0xB02697D61E81B83CULL, 
            0xB640C2CA8F48B451ULL, 0x9CCE752AF1FD5A6AULL, 0xF17793A1C981F601ULL, 0xE79B89747212F492ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseDConstants = {
    0x9CE15C7B4A4C2907ULL,
    0x5587B7AF73200B26ULL,
    0x3EBAF4C2A327D177ULL,
    0x9CE15C7B4A4C2907ULL,
    0x5587B7AF73200B26ULL,
    0x3EBAF4C2A327D177ULL,
    0xC1937EC3BE45FEB0ULL,
    0x376440C0DAF98154ULL,
    0x48,
    0xD2,
    0xAE,
    0x81,
    0x58,
    0xF0,
    0x56,
    0xA4
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseESalts = {
    {
        {
            0xBEE7B513D2BAD12AULL, 0xCC041349AF1BB99BULL, 0xBB6F341F663EF978ULL, 0xA2D55A8B9FD4AC59ULL, 
            0x045E9ABDA683E211ULL, 0x0805F00328B8B61EULL, 0x7A207D9B8E2A07BCULL, 0x09DD680D9B63AEFDULL, 
            0xA19AEB38E00B528AULL, 0x9CCE24CE6C885CA1ULL, 0x5CE909EF33845D12ULL, 0x333943974040414EULL, 
            0xE851A0C6AB460AECULL, 0x5A3170256C09F3C7ULL, 0xDCA8BCBC9ED26415ULL, 0xE6C24FB3D5B6EF5CULL, 
            0x07DB9B798629AA77ULL, 0x5AF650A19A078CA0ULL, 0xD5635F750107B2B4ULL, 0x61054715D2330729ULL, 
            0x2C0C9C92744FA500ULL, 0xFB3F8C19B34E961CULL, 0xF397DC68BDF66662ULL, 0xA557B2841A4EFD3AULL, 
            0x3FF89E61E2769B26ULL, 0x7EB7670ABE7B46C7ULL, 0x903ECB1EE4D815B4ULL, 0xFABD3EAFE5799F89ULL, 
            0x8D10BF6BF529F51BULL, 0xAB752EE7C733DC77ULL, 0x551F064D7CB11D7CULL, 0x32DC22E09317D409ULL
        },
        {
            0xB67061E6435430DFULL, 0x02B9A3A3A515ED28ULL, 0x7C74CBB21C56AD6EULL, 0x8A20E3BA7298312BULL, 
            0xC2C197B378661E4DULL, 0x53F770EBDBA94EB2ULL, 0xAB93846ED4F9B06EULL, 0x62AE0D7760594D4DULL, 
            0x62ED5F6AEB0981E3ULL, 0xB3D2590E0A75401EULL, 0xF0D6617741C2B090ULL, 0x5E1F636EE3CCECA2ULL, 
            0xC4D97644DF0B9582ULL, 0x0F63FD3D5C8B604FULL, 0xEE148439BADB6227ULL, 0x90B658B2E4A1BEFBULL, 
            0x8E61BA977251C6B1ULL, 0x756E20A73B847890ULL, 0x6E38147EA3E75F8DULL, 0x45ACD4DF81652E6BULL, 
            0x26FDE7C6D237EFF7ULL, 0x8C624B173FC33F8EULL, 0x4729344AA9DE2D57ULL, 0xB546AB8D15F204FFULL, 
            0x9092597645F2FE78ULL, 0x1E6F0B2472BF2412ULL, 0x3AEE804902B22138ULL, 0xABE0D33B3693EA3FULL, 
            0x846817703BB080E9ULL, 0xDB61EDBAD63DBA30ULL, 0xC9C605E1D2CA55B6ULL, 0x3A436AD158E07DC7ULL
        },
        {
            0xC1D25D462325CB7BULL, 0xD6CD4AB3223C931CULL, 0xBFE7A55D569ABABDULL, 0x8003AA6599E739A7ULL, 
            0x9C42D1C4991142F1ULL, 0x7C8A18C26557C738ULL, 0xD7C2756F263112F4ULL, 0x9E0417EA5C30EB97ULL, 
            0xB2469B41454E169EULL, 0x198EDF2E1F52CCCEULL, 0x66A5B14E57765937ULL, 0x7DB9C9F6AA0975E7ULL, 
            0x9E1DA1314FEB360FULL, 0x5665D7BF87E9414EULL, 0xB1C6A4019CD01AFFULL, 0x3630A27238C530CAULL, 
            0x68BB34104BC57307ULL, 0x9482A92FE2BFC5ACULL, 0x55CAD81DCEDC5A6FULL, 0x4465B0A7783F4229ULL, 
            0x98EC6AA42547D096ULL, 0x025A263C31AD2681ULL, 0x29B031FB3DD44307ULL, 0x87E1AF054241AAE5ULL, 
            0x73FC36E5947704B2ULL, 0xC62721F6D1A82B34ULL, 0xD69FFAB8156718E4ULL, 0xC393EC0A8C5152EBULL, 
            0x20AF250C165A86C3ULL, 0x18FEAB48DADAD3C4ULL, 0xA56A83CA51FBE476ULL, 0x40B719370D893EAFULL
        },
        {
            0x168B20F35DFF200AULL, 0x56116762105B0328ULL, 0x67DA4728B4159B82ULL, 0xFCBEAE7F5543FE3AULL, 
            0xA0DF39D7826D4334ULL, 0x98418AE5C9D669B1ULL, 0xED817F6B5B7E82ECULL, 0x8CE369CED79C004CULL, 
            0x7A1884D2E3F6E77AULL, 0x656F0E5BEF3EDAAEULL, 0xDEF7B474D1B3A19FULL, 0x160223066E3EB3ADULL, 
            0xC3D51FD6300C3767ULL, 0x9DF7D02E9B7D7283ULL, 0x1F7D3BFDF845EACCULL, 0x2C9AC68491600EE9ULL, 
            0x9D98B3BDDF56D207ULL, 0xE5825FA7EF706937ULL, 0xF925A75A35B104FBULL, 0x1A9B539696DBE45EULL, 
            0x77F9E89FA0B74A4AULL, 0xF0DD57A9D481B066ULL, 0x75EAC68F9CDF815BULL, 0x89F43E05AC8893D4ULL, 
            0xBA666485FCCF12ECULL, 0xC6E0BA583A3C56E0ULL, 0x6566D37479AD4C88ULL, 0xB804A27705F33658ULL, 
            0x91BBC4E9A0A5157EULL, 0x5A5018B9E994FEA8ULL, 0x5BDF0241F4F906AFULL, 0x66C051E3BBBB1C73ULL
        },
        {
            0x304532F958F70005ULL, 0x4C4345C8D0F853BDULL, 0x1D34982CF0F2B5DAULL, 0x6E1E170A1AF627B1ULL, 
            0x37EA222471B29D8DULL, 0x0E21FE443F638795ULL, 0x8C43044D552FED51ULL, 0xBD717D931A02CBE3ULL, 
            0x2A424AC9C4703A0EULL, 0x4DD14D1EAA60A4AEULL, 0x9FC4E9944090BE9EULL, 0xF8D2C73E49800EEBULL, 
            0x241981A6B9A0DC96ULL, 0x3F1803F0D50D4B44ULL, 0xF4067C96B612550DULL, 0x81646524384FB6A9ULL, 
            0x0495DAD2D2DEB3C9ULL, 0x30021053A15BA94FULL, 0x825767F5DD82C4A4ULL, 0x1B09F47AA48A6DA6ULL, 
            0xF54BB06D46CBE511ULL, 0x1EFFBCBB6DEDBDBFULL, 0x73F20E933622F3AAULL, 0x8AFE9715C1DDEF78ULL, 
            0xCBAD777FB8ACB2C7ULL, 0x9EA4CE9F39AFE6D3ULL, 0xB3545F54B9EDD200ULL, 0x61ACF8C5140CB3F5ULL, 
            0x7E41D253B67D9D0AULL, 0x300B9C4E47272C2EULL, 0xED1861A6C1787D8DULL, 0x40674693DFA71057ULL
        },
        {
            0xEFE76DC75FC9D89EULL, 0xCD532F6AE1D49A03ULL, 0x632C4AB893E09FE6ULL, 0xB6199200046B118BULL, 
            0x25F28C089B8DA094ULL, 0x09416A80CEEDC099ULL, 0x95F30614EFF417C4ULL, 0x7B1DE5ED8677A7C8ULL, 
            0xF975F4DE2AF2B8DEULL, 0xC0FF3EF709E85725ULL, 0x4BC68C1089E40A7CULL, 0x54846193113D5278ULL, 
            0x841AF2864160F7CCULL, 0xE3FA610FBAF7083CULL, 0xDCC19481FF7BCC10ULL, 0x4AED1C6A69865B9AULL, 
            0x8AA8F3BC3DE8E565ULL, 0x9BC8B6B80CB81454ULL, 0xF4DBBE4DD230C3E4ULL, 0xC427A77EDBB450E3ULL, 
            0xBDFCD94C3A00D054ULL, 0x59246F2ADC049140ULL, 0x77BFE169553E454FULL, 0x06608E05AFECF509ULL, 
            0xE4F69CCB2CE6D3DBULL, 0xE9E562D0D7C16AC7ULL, 0xBC1BB72262F4DBE4ULL, 0x72AECABFFD554781ULL, 
            0xC599A1D8D9D1E98DULL, 0x1FA84F682AC962CAULL, 0x2FFDCD3DF6A5FF0CULL, 0x399111D9CEF3F094ULL
        }
    },
    {
        {
            0xB8E7D434FE0C947DULL, 0x4418F617A7E81919ULL, 0x9E0545E91CE88163ULL, 0xFBD36EAE151DE5F2ULL, 
            0x73354A7E68BA78FFULL, 0x0A8DA5F383BD9B9AULL, 0x1C26AA186E61A2A9ULL, 0x2728C4B2DC60AD17ULL, 
            0x99226B31E61D6D8DULL, 0x186B33185DC7E2BCULL, 0x42259AFC41EBD8EFULL, 0x697F75965DB3EA65ULL, 
            0xA529B773E4AF1288ULL, 0x8473FA10543193A4ULL, 0x16A906D980E5FC30ULL, 0xFA83BF9600799A4DULL, 
            0x5C678F38FF02C698ULL, 0xF036980D9FBE2F01ULL, 0x4DBB2704238806D2ULL, 0xE1FCE2F19F787FDCULL, 
            0x67E3C60F8FDEE1A1ULL, 0xA5B0B297746520A4ULL, 0xCE0E96374454543EULL, 0xC476A1FFD9303B58ULL, 
            0x2ED3A3788E6C4006ULL, 0xF613C25E4D519041ULL, 0xC2D3A32B37817D56ULL, 0x7022D407AAFA933DULL, 
            0xF7C6A5F5367F6AF2ULL, 0x39A33986B719B0FDULL, 0x7AD969B65454F289ULL, 0xE7B5754407610372ULL
        },
        {
            0xD3B83627382DB148ULL, 0x42523E24116CFBC4ULL, 0xA9257EBB316B4903ULL, 0x442177F4C23CBA0BULL, 
            0xFEE19E1534133AF9ULL, 0x0CA4381F7E2690B7ULL, 0x8B1C3070C76EE06FULL, 0x7AB62A158330B78BULL, 
            0x23D59D2FC5BE46BEULL, 0xA3462CBAC08C1C9CULL, 0x610D9013BB1C457DULL, 0x2F46E1198638AA50ULL, 
            0x5FA73FE277DFEFE2ULL, 0x8A0CF313267CE316ULL, 0xC5AB1BE1AF440C4FULL, 0x24EF0EF3BA20E191ULL, 
            0x5E60EFEBEE7F3A58ULL, 0x57D8383E03F568F8ULL, 0x7F7B4294DBA6A074ULL, 0x1B07652CC6985048ULL, 
            0x571DF41A06B0BF54ULL, 0x9A58465940399CF6ULL, 0x53A180AFCC9D25F9ULL, 0x663FC6B8E19A21B9ULL, 
            0x6F54B24C07AA10B5ULL, 0xD734F93DE2BBEA8CULL, 0x7261C5C5C520B87CULL, 0xFDD120D405D450CCULL, 
            0x3AF999CA0EDF0D8AULL, 0x11DB2DF270FFA9DEULL, 0xD336C31181017615ULL, 0xC08752C0B9EE9688ULL
        },
        {
            0x77734F643F38E008ULL, 0x8B87AE46BF518232ULL, 0x72E9CEA78ECE1541ULL, 0xC129EA3D55E4604AULL, 
            0x967737FA645A2579ULL, 0xBFCE9F651381A759ULL, 0x20E709DB0947C7C8ULL, 0x9DC957711E217DF0ULL, 
            0x9563410CADC66D05ULL, 0x857C7F88E150B3FEULL, 0xB4FA5C8302DE54BFULL, 0xD2BE713A4B53E0D1ULL, 
            0xE3E12215F60CB60CULL, 0x2D4D262CB5D61051ULL, 0x02439CF618A40D5CULL, 0x4AB23771563753BDULL, 
            0x8639AFF35B604283ULL, 0x1EE5C3376AD8A3C7ULL, 0x9861887C65CDE937ULL, 0x7897ECF23DF21BB5ULL, 
            0x2C9A9EC48B3940B3ULL, 0x2BCC484EB18E1CD9ULL, 0x281A1C26BABA8637ULL, 0x56474BCAA2316567ULL, 
            0x12E4967867D95261ULL, 0xF90CB15D76A20E59ULL, 0x9C7D2CEC336606D1ULL, 0xAB10C0B6FE8DCB16ULL, 
            0x9D7311FE201B6655ULL, 0x8CBD80872F548B43ULL, 0x401235950322C82EULL, 0x8E2C40924ECDB988ULL
        },
        {
            0xC96368E6EC13BE4BULL, 0x63C93257D4EC98C1ULL, 0xEAD25ADCF023B533ULL, 0x0A9F8F22C1EDE98CULL, 
            0x7BD692617414DF9CULL, 0x28F404C6C6535090ULL, 0x98463D647860FF15ULL, 0xDE9587DE3766FE3DULL, 
            0x3EE5374F4BB326DEULL, 0xF52173562F3FE1A1ULL, 0x43E829E18A4AD448ULL, 0xB14FA2CE5E999B47ULL, 
            0x2763DCEDED0F9C62ULL, 0x4AC0424DED83203BULL, 0x88921B5B7D77D24EULL, 0x38BEE19E8E523F88ULL, 
            0x03747363D186BF56ULL, 0x10973C18747735CDULL, 0x10F85462108F5D52ULL, 0x4A94ACCCED1DDC97ULL, 
            0xDB27FF889218F61FULL, 0x8DFB792A3F01C00CULL, 0x5596C7ED849CE6C7ULL, 0xE7A798B5AED1E1B5ULL, 
            0x26120481D980885EULL, 0x371533AEBB898106ULL, 0x02468C9D13A8D4B1ULL, 0x0F9E22F81D0B7EEFULL, 
            0xA1AEC5BE2B38BC16ULL, 0xDB407B8EFF48AC6EULL, 0xBC1387A77727799FULL, 0xE4EC7269A1799533ULL
        },
        {
            0x07A27BCA3CA97779ULL, 0x04C9C687439B0C57ULL, 0x1807030451A14CBCULL, 0x1237A1E39DAACA31ULL, 
            0xA157942CB159CC7BULL, 0x37417ABA991BB7EFULL, 0x29916066833360F0ULL, 0x93FCA3EC7C3BCB53ULL, 
            0x6EA20763D83F84E0ULL, 0xBDB34F8532E4C3FFULL, 0x08BE2F7EAE053BABULL, 0x0CE2277AD851B8AAULL, 
            0x69E9A74A03F220F2ULL, 0x5C86C9E1A74E7AF0ULL, 0x3F85FE1F9BC4090CULL, 0xC1FB66091560988FULL, 
            0x53108D7BA950D11DULL, 0xDAEB07962B53DB97ULL, 0xD3529358FD67E458ULL, 0x8A9D7BF3E0A56574ULL, 
            0x37A7205A7D2D3ECFULL, 0x676ED4379880900AULL, 0xCC24ED212E5B89DEULL, 0xE7C3CC45C311B65FULL, 
            0x9FA940A741FFF1D6ULL, 0xFD5A223475E9D7ABULL, 0xEC380E59FC57678AULL, 0xFEA4AB8D810C1700ULL, 
            0x24ACBA5AC46AA666ULL, 0x5FB2E51D591D0F56ULL, 0x065556DFD33143A1ULL, 0xEC58D942BF1588C4ULL
        },
        {
            0x84FAF92E9B012321ULL, 0xBAA174F727993B66ULL, 0x1015279E2142054EULL, 0x0C925DCBC915A797ULL, 
            0xD151A9375745D28FULL, 0xE0C56436479FB161ULL, 0xAACD0A54858D8B26ULL, 0x4FF1DEEBF4EABD88ULL, 
            0x40A674C0F186D9F1ULL, 0x7FB8673E5326B88BULL, 0xF04B39008D9923FDULL, 0x619484E5B06DDCACULL, 
            0x9D8F9046A04E7340ULL, 0x724D91BDA59D8CE0ULL, 0x53F4F278854BA83FULL, 0xBF1445B0DE11C3B0ULL, 
            0xC2EA1453547A4A20ULL, 0x1A3A7D7CC670D5A3ULL, 0x467C0E832602D340ULL, 0xF18F03D2659142B5ULL, 
            0xA9731B824F9C030CULL, 0x44526810CBCEAD83ULL, 0xB1102A0BDD6C9C18ULL, 0x45D07A61DFD660B0ULL, 
            0x29531ADD4FAA354AULL, 0x0082CB2858E2792AULL, 0xE7B7BFFD96FC61E2ULL, 0x4508245080511401ULL, 
            0xE13B340AE8C5EE33ULL, 0xA79DFAC135C74158ULL, 0x7475307639F887DEULL, 0x2FCEA3C8A6D179BFULL
        }
    },
    {
        {
            0x299457BC9EE275A9ULL, 0xBA75F42C97A0BC31ULL, 0xA1549823AAE53CC0ULL, 0x0EEDF1B0C8ADD7A8ULL, 
            0x0B1DF1D3C89FA853ULL, 0x6371931214AE3E4BULL, 0x1AD86D61463DF038ULL, 0xD08629782F7669E0ULL, 
            0xB9B3536CAC72FCB1ULL, 0x437C1C114D6F75DBULL, 0x177CDC546EEC6DF1ULL, 0x573CD201889BA6A6ULL, 
            0x3EBE038F50D5BA0BULL, 0x2678C236EC74F35CULL, 0x9868B9367ACC3C91ULL, 0x8E2AAB7F86451551ULL, 
            0xCC62D3CC70501316ULL, 0x6F65320C3775DD5EULL, 0x01C2E898158530DAULL, 0x5B026CD88633CCA8ULL, 
            0x27A3D63FB25B739BULL, 0x18193D6DD7C95A14ULL, 0x94029EF95480A98CULL, 0x39FF74AC1ECC357CULL, 
            0x5D760C7D2624695EULL, 0x97286B69D2643495ULL, 0xF86799A3994E7BB5ULL, 0x1C8EF2475F43EA0FULL, 
            0xDD0BEA564FB8F284ULL, 0xF8C8BBF08EAD4E9AULL, 0x481DA69064355241ULL, 0xAD7159F14D67923BULL
        },
        {
            0x6E0343C541DDE8CFULL, 0x87410FA641DD134FULL, 0xB1A6D710AFB4662BULL, 0x203B8153F93B50A2ULL, 
            0x77237FA7FD6625FDULL, 0x51F32A15614D4616ULL, 0xCCB34CD12E988B23ULL, 0xFCD2A3AE36550EEAULL, 
            0x22CABCAC27E3C52FULL, 0xEB8B10F6FE2CDCA1ULL, 0x7264C5B38410C12EULL, 0x43AC6F400F83EEB4ULL, 
            0xFB9CE804D48F45FDULL, 0x1948EEAACC107FDBULL, 0x876E90DBC86CAC75ULL, 0x609E00FA9D095F36ULL, 
            0x0EC26326966D723CULL, 0xA93453B1C6522E45ULL, 0x452E41D234456854ULL, 0x51C766FB1E51789DULL, 
            0xB0AA67F29FB256ACULL, 0x82091181542FFC37ULL, 0xA9045DC3D1EF61CFULL, 0x545B46F8E549A591ULL, 
            0xA6E4DDA453A39996ULL, 0x5DB0316A56946BC6ULL, 0x6F0DC30431B080ECULL, 0xF73FC18D148939A2ULL, 
            0xB9257D06FCCCCD9DULL, 0xB85F83AE6A18FB87ULL, 0xA7EA5E8431040339ULL, 0xD3C95208F1DDDD5AULL
        },
        {
            0x4CA7CC346AACD316ULL, 0xC406DE85A58BCE94ULL, 0x437BFB065D5703D1ULL, 0xB3DE0BA979CC6B94ULL, 
            0xF35246E7E619ACFDULL, 0x3F4F22D0ED49E330ULL, 0xCDBB782361CC1A08ULL, 0x6D31BFA27F0E7036ULL, 
            0xE9E394CE30C78C51ULL, 0x366DE1F6C4E77181ULL, 0x0E403A437D9043A8ULL, 0x2FDE5E61754C2944ULL, 
            0xCC058A9104CA5BBEULL, 0xEEC1B50662443980ULL, 0xE9306AC1D7BD2558ULL, 0x589DCE94B73FD379ULL, 
            0x8B4B9718CFAFFE40ULL, 0x2175921BD461E23FULL, 0x7D3B7EFF9AFA3C3DULL, 0x06F095BD0F1F1724ULL, 
            0xBB17ECBC3943EA25ULL, 0x7053C9499AB9C7CBULL, 0x90CE8A085AFC1FE7ULL, 0x9BCB39CF3BAC119CULL, 
            0x4E008D46F4D9A4BFULL, 0x224315D5355F1902ULL, 0xA5A412BD8E92733CULL, 0xE88C71826CEC2134ULL, 
            0xC9BA6AA0C5ECBD61ULL, 0x2934F53F8FCB076DULL, 0x244B8D604D5583C4ULL, 0x25F29C0A4FA7C12EULL
        },
        {
            0x17285B079393CF56ULL, 0xD639844496B04598ULL, 0x3D6C4CA81B0BA5BBULL, 0xF8261F792EFD1C16ULL, 
            0xFF8B78CA2ACF394AULL, 0xDA3B344BFE064DD1ULL, 0x427990FE77B0492DULL, 0x8D86EBB0214C28E2ULL, 
            0x023D422265B712ECULL, 0xAC916E7C9B3D1737ULL, 0x0D60A1BA7DCE76E9ULL, 0x19487493F9108596ULL, 
            0x14319177EB475AB2ULL, 0x9D59AC35CDD8367AULL, 0x15CC920A2DFF2770ULL, 0xD8A2C982B685D0CDULL, 
            0x4A3F3B5E7AE0A263ULL, 0x07BE29274A60982BULL, 0xA9755927EAE42009ULL, 0xCACC7C82DEA756BEULL, 
            0xE00B678EDEB1CC0CULL, 0x86EE8923340F3779ULL, 0x303AFA5F4E972E88ULL, 0xA1E40BB7BD17A0DDULL, 
            0xD3A23BAED487656FULL, 0x4B6080FCA7BD0EA3ULL, 0xFC9BB51A770B969EULL, 0x8984A52D807A88ADULL, 
            0xA090CBE6B10D2D09ULL, 0x57BFF45A8251DF90ULL, 0x585B91BFF09CA8D1ULL, 0x9EB5D70AC63EC97AULL
        },
        {
            0x85F8B10D99B3B36BULL, 0x91A67CECD74CD438ULL, 0xA4E61F62E3161DE7ULL, 0x9BE2D8855BEF33FFULL, 
            0xF1C8182A872187A3ULL, 0x41E9AE3F3E9B895EULL, 0xE4FD10397E5711A5ULL, 0x1AEA443BDFCCB6D1ULL, 
            0x92A6803ED8380F59ULL, 0xB7F3243F5119A3E7ULL, 0x82947348BB1ED536ULL, 0x11B67BAAD56F374EULL, 
            0x1533710C3D9000A4ULL, 0x0547403586AD5D10ULL, 0xF5342B56D368164AULL, 0xFAC8B6CEDCFB6466ULL, 
            0x7CBEB1E885ECDD52ULL, 0x788F66D915732FBAULL, 0xE840FFD9AC1EDFF5ULL, 0xE43FE9901CF1233CULL, 
            0x54E4AC1D94365484ULL, 0x865468C1A72E9D7DULL, 0xB4BB6CCA74B97342ULL, 0xCC5589A171318684ULL, 
            0x7E74A20450DE0A4EULL, 0x8B4018EB358B0856ULL, 0x70018A28ADF38F89ULL, 0x093D0B6099DE757CULL, 
            0xEDB7D6CF43A6D04BULL, 0x2D98AB665B17712CULL, 0x392DAE54E7454A56ULL, 0x04F211ECE594642BULL
        },
        {
            0x4147F709A85C1C89ULL, 0xA531697A67158B31ULL, 0x727CB19A93FBA1E2ULL, 0xEA0E331B97843B1BULL, 
            0xE6012ECF7765AA1DULL, 0x55BCDE4F99880A40ULL, 0xD1E6713A51984883ULL, 0xB03BCDDA370597FEULL, 
            0xA4AF4B50EE14757FULL, 0xA7F4DE277A61F3AEULL, 0xB22ADB07D2D86816ULL, 0xAF7E56149CBAE40EULL, 
            0xFBA6C14639B2E7C2ULL, 0x7533CBB2A9BC9AF1ULL, 0x2467C9D08774DAF3ULL, 0xB3938D1B36FF320CULL, 
            0xE07BB133FA2EDB59ULL, 0x9119CE0B7EEF3C27ULL, 0xAECE39D517CCC248ULL, 0xDCB915A6F4DDFE73ULL, 
            0xBCB1EFBEB32517FBULL, 0xB96D902E30D2AABBULL, 0xCEB9477D4CA11365ULL, 0xA3C90D7F26EA2FDDULL, 
            0x2CBC998AA5FBAF27ULL, 0xA8FCD2096108163BULL, 0x4E55C08DDC01E694ULL, 0x2A911541A20F880EULL, 
            0xCBF3B7AD27B47976ULL, 0x142B0AAEDE949B37ULL, 0xF8540D5BC01E5AFCULL, 0xF88F9C051FBCEC2EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseEConstants = {
    0x797CB67F4FD75872ULL,
    0x77D60228AB88D5BCULL,
    0xD3FA60B96718857FULL,
    0x797CB67F4FD75872ULL,
    0x77D60228AB88D5BCULL,
    0xD3FA60B96718857FULL,
    0x9092E1A1470F6448ULL,
    0x191553CE3D8738BCULL,
    0x18,
    0x6E,
    0x3C,
    0xBC,
    0xD1,
    0x52,
    0xE3,
    0x9A
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseFSalts = {
    {
        {
            0x4E105994E94D0F37ULL, 0x1ABA7C9EE0C2918BULL, 0x07CD73848467AC33ULL, 0xB37459FE4EAFA486ULL, 
            0x6136A9A006CDA77BULL, 0x7CE6FC4F70777C3CULL, 0x58FB942FECC9B409ULL, 0xEE9C7FD0FFC5D6E0ULL, 
            0xB03328A7C9C0DC87ULL, 0x42A31CEDCB0A2A58ULL, 0xB46359B17A211C1CULL, 0x10B0F4F62E4DD547ULL, 
            0x4D97D9B536B78DE5ULL, 0x2F5B2CF6046E7CD5ULL, 0x6E70B84466713A81ULL, 0xB9465DF95B497C3DULL, 
            0x45BD0605FCF922BEULL, 0x18E09C018D066551ULL, 0x701B789D2DA56975ULL, 0x2AD814545DD4E16FULL, 
            0xBABB4319A77846B6ULL, 0x681C2FABFDA06C4FULL, 0xA146900193E68B5AULL, 0x078E18AACD2B05EBULL, 
            0x0CC95F20D767688AULL, 0x1103649DF570BEB6ULL, 0x5F76B6DA33C9855EULL, 0x69A394F0189DB40BULL, 
            0x9C401DF0A3FF088CULL, 0x584EABE95D1DE250ULL, 0x336FF8D58C684D71ULL, 0xB0FBF6820B002C6CULL
        },
        {
            0xD558D3D962C7843CULL, 0xFB117E006E4F86E1ULL, 0x45C90485E6842C9EULL, 0x0EE1E39FC1BD4AE2ULL, 
            0x379FDAC8ECF27844ULL, 0x54A1C16C3107254AULL, 0x6938088A3D3295FAULL, 0x7156268056043A9AULL, 
            0x9D09C447D1E6E23FULL, 0xFDB3E49B002A3B9FULL, 0x9A9ECB76FF717F2CULL, 0x1733F23A7B082A97ULL, 
            0x91ADB94B60AEDA8EULL, 0x98F54B069E33E8AAULL, 0xCD863BAFC1381CF0ULL, 0x0B6F9E6AD32A5CAFULL, 
            0xA47310EB8662FBFDULL, 0x94A89005E1F642FCULL, 0xFB462C51B59D8D0CULL, 0xFADCF7041E7BE80BULL, 
            0xF3D3184FCD17A488ULL, 0x36E2908453A8CECCULL, 0xDDB81107CA91D54CULL, 0x8BA0480ECFF79EACULL, 
            0x5327B75847624392ULL, 0xDBE920D1C86924E5ULL, 0x5A374219A859A80BULL, 0xF4E8489A7926F20AULL, 
            0x423F289BF9FFB548ULL, 0x0D311D45B1937B6BULL, 0xB574C4C7323B2F23ULL, 0xAE09645764D9EEB5ULL
        },
        {
            0x93AC3E21017BBDB5ULL, 0x6D6D4AF1F460700EULL, 0x324C8EEA63BBFD6CULL, 0xBD019DCBEAE7F73AULL, 
            0x6871FC86D8FC6491ULL, 0x492DB03D712B0AFBULL, 0x9FEEB779DCA381A9ULL, 0x926CDA3EB59B9CD5ULL, 
            0xF7A00F2F35E627B3ULL, 0xC61CC5B98FBD463BULL, 0x27E6CD0B92BFFF5DULL, 0x1AF1CADF9CF9A6BCULL, 
            0x2BF1A61E881A06AAULL, 0xFE2F9A78537092F6ULL, 0xF3674100881EE574ULL, 0x3CBFB60111A445FDULL, 
            0xCBD84F49E7ECCA1EULL, 0x466CC437A0224851ULL, 0x1AF628B357A066C8ULL, 0x48108B5A41608F60ULL, 
            0x68B760A9D7D47699ULL, 0xCC20BA61BD18BE9AULL, 0xBE48844D813ED8F8ULL, 0xC617E07F92D1711DULL, 
            0x79EC23390134496AULL, 0xAFA221DFA6CEE69BULL, 0x651E8A6DD84ED29EULL, 0xE6E942CCC728A085ULL, 
            0x6C4535DD5C781679ULL, 0xCA71C4CD724A1864ULL, 0x2A9E8514F41B1E59ULL, 0xFF75B625AE84C2F3ULL
        },
        {
            0x654C7B1D65E9B476ULL, 0x85A8C8AEF99E9765ULL, 0xAB8508109D21E7F5ULL, 0x4545AF1918ABAFACULL, 
            0x3E8A2759DB72C90DULL, 0xD3972EBD10D35C4BULL, 0xFFCB5BD0E329509EULL, 0xF7BBF1A828F5E8C4ULL, 
            0x3E252920E3EB7547ULL, 0x4EAC96A1FBDB7CF5ULL, 0x1F71A54BCC861587ULL, 0x60C2B64BFEA09DE8ULL, 
            0x7680462C51C0912FULL, 0x2A35E930F185496DULL, 0x8FD5AC6ADB90558BULL, 0xD3C0448D1A90AE4CULL, 
            0xE4066EA1A69212F3ULL, 0xF70DEAE65DD3BBFFULL, 0xE3BFEA3881D67037ULL, 0xB631EEFC028D002AULL, 
            0x57EB101B1A013C74ULL, 0xE906475D2B9E25A4ULL, 0x8579AB25F355E6BDULL, 0x3025D756C584A5AAULL, 
            0xC28BEE3F90769F59ULL, 0x7AD2A9F5188BD463ULL, 0xE7B4B355A4BE8AB6ULL, 0x6039458254F287A1ULL, 
            0xBF8501EBF82ED2F7ULL, 0xB5ECAEBC556AB6B8ULL, 0xBEAF7413B0D8BE22ULL, 0x68D043935304E51AULL
        },
        {
            0x4142B4B2C17F8C3FULL, 0x5C23D2617A0B8EE7ULL, 0xE351FFD7D9E70ABDULL, 0xFB5D3785E81FD2F6ULL, 
            0xB3CEF2ACC7EB48D2ULL, 0x04778BCAC9B881BDULL, 0xAF3EDB8791B675C5ULL, 0xD8A634BE16650EA1ULL, 
            0x9C471DE8F17AFA42ULL, 0xDEC5EDC8337DE598ULL, 0xCB0BB493881EAEAEULL, 0xFD020159D7BAFB4BULL, 
            0xE784CF6CA5876155ULL, 0x844E2EADD2BF0A2DULL, 0xDA5BCADA1B481248ULL, 0xFD1C25E6ACA71DA0ULL, 
            0x2E05F2885E97EF35ULL, 0xC234F1BF9D1AB39AULL, 0xB054FE2A0114972FULL, 0xBBE8BBFCD2BE8F49ULL, 
            0xD3A2736075AC94DAULL, 0x4E3D77716CB0B714ULL, 0xB8C309A7DE2F49ADULL, 0x7B8A006C04B9560AULL, 
            0x9D60683B5EF38262ULL, 0x7BA4C50826101E56ULL, 0xC7BBB97106EAF9F6ULL, 0x01FA1842BD4C72EEULL, 
            0xD6AEEF249A812A40ULL, 0x24CEAF515A2C9593ULL, 0x4DADA21AA571EB26ULL, 0x6573BD146BABF72EULL
        },
        {
            0x8E34D08440BEE0BAULL, 0x150AAFA2CF5C657FULL, 0xF732B40CB6F72812ULL, 0xA8C4AC36B635E14BULL, 
            0xE328480880907481ULL, 0xE6B609E44357868AULL, 0x5284CE7E41947EFAULL, 0x57E954E935A2282BULL, 
            0x40D1A33DF977CDFCULL, 0x385CDAB4AAF8EB0FULL, 0x9BB3647936FE7445ULL, 0x26906149ADC12E58ULL, 
            0x30F69D195D36279BULL, 0x73E162133353C18DULL, 0x7F441E9A453A1B04ULL, 0x0F88A5204BD156D7ULL, 
            0xCEF84EEAF1BE8375ULL, 0xA74BB3AE81F2220FULL, 0x289CC4163082EF8DULL, 0x7B7F47375CABCA2EULL, 
            0xB3409F6FD25C9DC6ULL, 0xB58EDF157197EC07ULL, 0x095C73FED701913EULL, 0xFFE732B81BE57E46ULL, 
            0x469564E519669498ULL, 0x1022BBE2ABFD1E24ULL, 0x8747B7880F01CB5FULL, 0xD06136C6B0FDA70FULL, 
            0xEAEEDC8E8DA38D86ULL, 0x4E921D0F969B59CBULL, 0x8125054B0EB58EE6ULL, 0x42C7D2B00B081BE7ULL
        }
    },
    {
        {
            0x93D16404708F845BULL, 0xEA4A363F7BD7A942ULL, 0xC01C58EB0764D514ULL, 0xA9CB73A72F170888ULL, 
            0x32AD7089BE2614D6ULL, 0x9E8DE8FF39FCF30EULL, 0x22E43C40D4216FDDULL, 0x79D64D3E4F054CC6ULL, 
            0x76E4A73605E48DB0ULL, 0xDB84DB48316D4A85ULL, 0x963D9555B881BA22ULL, 0xA0FD4725545BFAC2ULL, 
            0x2BD6102AEA980308ULL, 0xF7EF5255F1B39882ULL, 0xBB33EAD0BEA6CC9EULL, 0x482B1ACA7CBA0FC6ULL, 
            0xF88951805AA6B471ULL, 0x4B013B9AC9C1EEE7ULL, 0x6D86BA119578FC12ULL, 0xFD6B730300CEEA48ULL, 
            0x4E44639E35F404DFULL, 0x35A9E3BEE7B85F88ULL, 0x34EB6F6561733D1CULL, 0x52F11DD8581080E8ULL, 
            0xD5CCD5D8196C52B0ULL, 0xE5865E4F26D94095ULL, 0x2CBB69708FFEAD9FULL, 0x6BF670C34FC01D0FULL, 
            0x860C8135B12B274AULL, 0xA1FF4B15652BECE3ULL, 0x595037F6EC7E62EAULL, 0x1F91D51CE2F2F6B5ULL
        },
        {
            0x3F72F26565052158ULL, 0xD43C2075A4B1950AULL, 0xE9072631A2B0F9C1ULL, 0xF117AEF8E459ED68ULL, 
            0x17A462ECBE8B37D1ULL, 0x94A808AF85A79EB6ULL, 0x19E72F48C5D4FB39ULL, 0xF306A3E1E54E2A0BULL, 
            0x73265DBA3A970474ULL, 0x3E272B6E7DB90877ULL, 0xAF839AA69E1B09DBULL, 0xAAA10DE25BF09F1EULL, 
            0xDB31AE91DD9C1ECFULL, 0xF5CEC48E454C5AB0ULL, 0xE87CB0C8D6004974ULL, 0xAF6989C17F830C04ULL, 
            0x5DF082AD6945D4D1ULL, 0x7BDA5BCC1ECF1A96ULL, 0x0B84639E68C23135ULL, 0x5E73B8100DE4D84CULL, 
            0x565D7C1A53D13CC1ULL, 0x57F4A225EAAA40FCULL, 0x350E81CD8518CA29ULL, 0xC682E73E1B1F5319ULL, 
            0xBB06E45A88355650ULL, 0x9F1764EF4FFEB48FULL, 0xBC1621946206BB7EULL, 0x526DD7EB0E49BED1ULL, 
            0xFAA0BF6C2F0F6377ULL, 0x015F83102EF6EFD5ULL, 0x2B39F43A78C09657ULL, 0xD4CD522E1390A1CBULL
        },
        {
            0xBDE3858FA674B8DCULL, 0xC5ED15C26EF236C9ULL, 0x56D66F02F2477E73ULL, 0x7BA2811FAEE07176ULL, 
            0x62C9E503F092D00BULL, 0xEB73B62F2B69288BULL, 0x31324E513E6962FCULL, 0xE15C6696F5171D11ULL, 
            0xFBB79EB2900461ADULL, 0x1B7A305E8F3B7B9CULL, 0xC7950347E0471B10ULL, 0xFEB51FCC393628EBULL, 
            0x4BD34F1840CA4380ULL, 0x8A3611DA356043D5ULL, 0xC0FD138E8E8362EDULL, 0x999BDDE158086289ULL, 
            0xAA1DF02B21DD1A6DULL, 0xA62985D752EB9A7EULL, 0xFADB04FA8A928D25ULL, 0x5C34B99E29B842D3ULL, 
            0xEDEB7DD557C79580ULL, 0x6044E042F157ECBAULL, 0xEF248301894EA9F9ULL, 0x2B8DB1B00F5CC26AULL, 
            0x2EAB66CB4EEB97EAULL, 0x375199F1C6747275ULL, 0x4E84CFFA27D0C793ULL, 0x403E5C5B52C2C02BULL, 
            0x222E204BC0BD329CULL, 0x5C6C14D090EF8CAAULL, 0xDA6532BB37CDD0EAULL, 0x838BF03489D720AEULL
        },
        {
            0xDEF1E4DE0EAEB05FULL, 0x8797E3FA825B02C3ULL, 0xD0DF54D7E56819CEULL, 0x82D79EFD74D60988ULL, 
            0xF7688C9F783DF610ULL, 0xD19DF3FA0EBCA09FULL, 0xA394C9881DA59C4DULL, 0x0F1274FB6CA33603ULL, 
            0xD93EE6CF13D0A87DULL, 0xDC345CED24BAB577ULL, 0xC971884361D736EDULL, 0xA52D90A7B786EB96ULL, 
            0x2315C26D216FA57EULL, 0x877B5DE621AC921DULL, 0x8F9F082542095265ULL, 0x4086034D4E86F2B9ULL, 
            0xE17905187E842A73ULL, 0xC81EA7AD0D669AC2ULL, 0x58C7DD935EF1435DULL, 0x719F40AE5FF939EBULL, 
            0x054B0AB523B2BB86ULL, 0x7D8785D81085A5E3ULL, 0x5CF947116696A866ULL, 0x5588AF96CD4F1689ULL, 
            0x55730D0DE128114BULL, 0x3C5960B759725840ULL, 0xB4FEBAAE454F624AULL, 0xDCF7A9E32ED70427ULL, 
            0xBE4DA722324E2F42ULL, 0xB1C4E3BDDB99512FULL, 0x65074AB422292091ULL, 0x1496282F886DA90BULL
        },
        {
            0xE94483D82B294786ULL, 0xAA26E0A567322F83ULL, 0x5C69F457453E64C6ULL, 0x8741BB8DC231B188ULL, 
            0xEE8ECE961D8AD9BBULL, 0x2796B3EE67164F8EULL, 0xDA35A94BACA05DD1ULL, 0xE130017FF1AC9CD1ULL, 
            0x747AAEB536C2100FULL, 0xACD80DAD5EE21FC9ULL, 0x6DA7D84CF9E81679ULL, 0x72922D0E8148E3AEULL, 
            0x0F57FB2943EE341FULL, 0xA7FEF61E6EF15524ULL, 0x27657ACA4D7E72ACULL, 0x15EB036155DD33BEULL, 
            0xF1322C3CA6B47848ULL, 0x5D28B9914B20C4D6ULL, 0xCDFD705BB5236390ULL, 0x3363F1E8318CD9B2ULL, 
            0x8021E9B4AA07A5CBULL, 0x304F9CD5F7549DB3ULL, 0x4A4E49D8AF7A56DCULL, 0xB783FEEE12F98DF3ULL, 
            0x53681B40FA77AB79ULL, 0x525DD3A094F5FA75ULL, 0x9F7897D063F8E95EULL, 0xF55CB816754A0566ULL, 
            0x6844810670228DA5ULL, 0xD328CD64C46E7971ULL, 0x9D0C9DD24B392315ULL, 0x2EB8BC8BD76E8DF6ULL
        },
        {
            0x08607BD5994716F8ULL, 0x8BE94596DD428CF4ULL, 0xD047ED63F7AEB86DULL, 0x482DED63E6A1D9F2ULL, 
            0x3A5F81E293384911ULL, 0xAC7EF333FC112E63ULL, 0x12F9DCB070A31E91ULL, 0x48C1DE2DF1F97E2BULL, 
            0x12A268A2C3A2E28FULL, 0xCEA00B535EDBA5ACULL, 0x7AFBDA2E2BBEB3FFULL, 0x08B10DEC596828CBULL, 
            0x787CBED4EF2B8974ULL, 0x532C7DD140E4B836ULL, 0xD694F9ABF9CB7116ULL, 0xBBEB72C1629ABD9DULL, 
            0x5179702DC6BED455ULL, 0xBC98F24DB36353B4ULL, 0x61FA2E254A8BD97AULL, 0x3F5732D9A6BD172EULL, 
            0x4CA94ACC07DF91D7ULL, 0x342D4083CC874934ULL, 0x4BC103674D725041ULL, 0x6F5DD91EC267330BULL, 
            0xDA1013985BA7E30CULL, 0xB7D372368FFC674CULL, 0x2D8F64460AC2C4D0ULL, 0xD6B03D317455D4C5ULL, 
            0x7D7E7E6F2E67ED50ULL, 0x52A5460970C176D1ULL, 0xD391CF5AE8F6842CULL, 0x67333FA767CE6CF6ULL
        }
    },
    {
        {
            0xCB40BEE6FC9B1D89ULL, 0xB9985E5C6F75F34BULL, 0x44639B7C3FBB6886ULL, 0x7DA2477F8C71AAADULL, 
            0xAC8C75E39673BB27ULL, 0x43846D0147223A38ULL, 0xB54F8F99D4661264ULL, 0xA321BEB5275A1F0DULL, 
            0x21034BC85BE6744CULL, 0x56245BAD4D70CBE5ULL, 0x09394634F6E522C8ULL, 0x3AAFAC86B1A6EDCCULL, 
            0xA1691A77C8B0C9A7ULL, 0xE225BF14CCE7AAF3ULL, 0xBF04AC3F964EE571ULL, 0xF18B21E4AF071DBEULL, 
            0xAF069A9883A8262DULL, 0x872FFBE2464FC665ULL, 0x9F3308E20BB05A99ULL, 0xF8C1D6B8ABDB6B9BULL, 
            0x54E20B1A4C56A8E9ULL, 0x3F73676C59CFF34AULL, 0x1D0DF552B1D57DF2ULL, 0x595E0274E95178D9ULL, 
            0x2D1434BC02FDC486ULL, 0xB779C20384C4E5A1ULL, 0x7FE27D43E19BDD2EULL, 0x05F407C8135DAA6AULL, 
            0x178984F885F4E1F5ULL, 0x00252C934A4C084EULL, 0xA68C5CA558B6AD9EULL, 0x760D114E7DEA4AD5ULL
        },
        {
            0xA651129BA6A502D8ULL, 0xF2792341134DB4ECULL, 0x43846D5391FC8D03ULL, 0x926851E17FA36022ULL, 
            0xF50DCD1F1E96F0F7ULL, 0xC3E1BFD8A34B64D4ULL, 0xC896BB134EEC9512ULL, 0x94A43A4D85E4FCF0ULL, 
            0x57D011FA52060AAEULL, 0xEC535CFFC887EDB8ULL, 0x1421B56BA466EAA6ULL, 0xAAA0B2F5A392BFD4ULL, 
            0xEDD055C89DA28AEDULL, 0x64C9747D558DB21CULL, 0xF70473ADA011F97CULL, 0xFDCFA8B6A1FFCFB1ULL, 
            0x50052068C8D5FBE1ULL, 0x8258296F63DF2974ULL, 0x0BBC5C46E0D37362ULL, 0xCF12B8DEFE2DC2C5ULL, 
            0x97919E7E82950D2BULL, 0x9C0B8B7987B3A1A2ULL, 0x29E7FC5667A1AE8CULL, 0x09544F939965D433ULL, 
            0xB5DB6B0C072A8C2DULL, 0x245057D7CA2DC2FCULL, 0xBA0E6BADE00B7B11ULL, 0x72FD6A443DA146AAULL, 
            0x7EA51A5763B5599AULL, 0x15C118D1EE13193BULL, 0x8CBB75AF10174A82ULL, 0x30898B7F8A6675DAULL
        },
        {
            0x3476094D1C628232ULL, 0x931543366D527046ULL, 0x84CB93B3E73986BEULL, 0x8480C3BCD81FEDFAULL, 
            0x03A4CFD1DEAF5552ULL, 0x1AFD250C1C8B35A1ULL, 0xA9339AF1FFE673FDULL, 0x76EEA80622804918ULL, 
            0x66DAF80015FF923DULL, 0x031C04ABF6674FA6ULL, 0xDFE3DD192A819084ULL, 0xD2E9EFD5228DED88ULL, 
            0x6FABECA3D1F67D7EULL, 0x412D079201FF9928ULL, 0x03727144FF63F0C2ULL, 0x6C964321C1516B4CULL, 
            0xB767E3220E166EFBULL, 0x16D790949E07E8FEULL, 0xADC499C0C70FF939ULL, 0x755D9C6AB04080BFULL, 
            0x934B38C2C4B4DDA8ULL, 0x55544FA9BFC0656EULL, 0x4718B42C56028516ULL, 0x7F71CB311A19E1D0ULL, 
            0x6E060F50516B7EA3ULL, 0x498C885DD7FFF4CFULL, 0x9B0F20A98D77A050ULL, 0x78AB8DE6355005D9ULL, 
            0x558C08C990A8AB86ULL, 0xC7FED5C639F561B8ULL, 0x1AFF17B9689B2AEAULL, 0x6799BC00DC97A151ULL
        },
        {
            0x1503A835A95263ADULL, 0xCD6B40BC559622FBULL, 0x0AC805F5454FA0A5ULL, 0x7383F55360281831ULL, 
            0xE2BBDAA2798C5838ULL, 0x4C7B64451E4537E3ULL, 0xA990F8E71129627DULL, 0x38072FDF91CF3BF7ULL, 
            0x8E7161F7CE8EC84EULL, 0x379A43039E25AE50ULL, 0xA8DD609C4DD14C72ULL, 0x9CEE5588DED0C12EULL, 
            0xB0A793B94F8F6F8CULL, 0xB04DB1547AEFFDFDULL, 0xCCA7426244C152C6ULL, 0x23BBEFA2D7C42537ULL, 
            0xE02F128363A233DDULL, 0x8DFD45643645DE08ULL, 0x9814825A8BC37224ULL, 0x9E22190E3E89BD83ULL, 
            0xAF43C7E80E1E4352ULL, 0xB58F0D2B9F4D05F2ULL, 0x2CFB1A1BFD8E1DF4ULL, 0x54B1411C15301FB0ULL, 
            0xC099D61657958F02ULL, 0x9E5057EA5F548C27ULL, 0x0E5F45D81911976BULL, 0xABB9D87310BE01B8ULL, 
            0x76FD94B64D621C04ULL, 0xAF85D4BD6A0BFB6BULL, 0xB682F12366304182ULL, 0x22627495AE545272ULL
        },
        {
            0xC5775FE87390AC1EULL, 0x2029C1ED505F4145ULL, 0x63C9D1D0CFF4BF55ULL, 0x2B1C71916EBFBF21ULL, 
            0x36797CBEAAA74B86ULL, 0x4FF2AEE9225E4C2FULL, 0x557E143FAD1D04F6ULL, 0x12FC57628A6DBA89ULL, 
            0x0D07D963D1019378ULL, 0xCB2C165BC3C9145EULL, 0x093C307241AD060AULL, 0x3EEBE911C4EED502ULL, 
            0xBA45DAC784390CFBULL, 0x84CE85073C78F4A6ULL, 0x8B522718ADC7D1C4ULL, 0x49E858998E4ECA1BULL, 
            0x5C0817FFCA19AC98ULL, 0xDA645679DB8E45FBULL, 0x55557FA5EF272768ULL, 0x62BEC1D5249D8980ULL, 
            0x647451D6CA01DBC4ULL, 0xF36C667F5E5CFB15ULL, 0x6F4B50C2A21A1D9FULL, 0x370763EE967BEB6EULL, 
            0xBF4EB75CB647C9F7ULL, 0x0421528F2647F193ULL, 0x453AB0D87104FC02ULL, 0xC23594BF8AADC9C4ULL, 
            0x8F60A6D33252B5CFULL, 0x481B328395640E1AULL, 0x93BF8E63E0637EBEULL, 0x69FBB915BB618271ULL
        },
        {
            0x35EDB144FC556064ULL, 0xC7618AD898EFD83FULL, 0xFDF95648033E4F8FULL, 0x836952C44FE130D9ULL, 
            0xA690D2BAFEE81AEAULL, 0x3EEC7AE191F38919ULL, 0x576C225DF033FD7DULL, 0x945001A3F1FD3361ULL, 
            0x134E18FE9E3EC0D0ULL, 0x5483A87459B6D494ULL, 0xDE3A926327BC94B0ULL, 0x4799E56F7FE39158ULL, 
            0x4C9F15F65D9C223AULL, 0x3638F1B15B702ABDULL, 0xE495AEA80BFE0D1FULL, 0xB86F4D9E67A06900ULL, 
            0xF9C8796D3B69F9B6ULL, 0x51E0616775A977B3ULL, 0xCCFF472A4EDF1830ULL, 0x7C278F720489478BULL, 
            0xC8A998698BD1127BULL, 0x7F59362019E4E8B3ULL, 0x8D19FE2605033BF1ULL, 0x149B82FD059B50B4ULL, 
            0x516871F967E0EFD0ULL, 0x7980342C08567D40ULL, 0x92E100347A9364E3ULL, 0x6F91037F0F323339ULL, 
            0xF4FC0B804AB9953BULL, 0x30E22C456B230AEAULL, 0x85325DA8906D974DULL, 0x2D933DA9AADBF553ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseFConstants = {
    0xEBC2C689126E77ADULL,
    0x82D738A8B1A1A797ULL,
    0x3C23F8B555C51F75ULL,
    0xEBC2C689126E77ADULL,
    0x82D738A8B1A1A797ULL,
    0x3C23F8B555C51F75ULL,
    0x71AF9432166D4F7BULL,
    0x92F0029714E51549ULL,
    0x64,
    0xA6,
    0x64,
    0x14,
    0xEE,
    0x79,
    0xF7,
    0x70
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseGSalts = {
    {
        {
            0x7336FEDF173F6124ULL, 0xF89D1DEBA23AA2FDULL, 0x8111D84E6BAC74ACULL, 0xAA3C97FD04499433ULL, 
            0x84D3DDA691D10814ULL, 0x48FB6E9322F04943ULL, 0xD48878100B7880ADULL, 0x6836EDD1BEDCDF47ULL, 
            0xDE84A05EBD9266C2ULL, 0x59455B404A5B6CC2ULL, 0xAEA25B16958A315AULL, 0xAF4F4EEAE39C7A4AULL, 
            0xDEC78557C73CC74AULL, 0xAACA04B31CE3E5F0ULL, 0x5244E9C3179F2A0EULL, 0x812B9C36E403A91CULL, 
            0x65408AEE615F07B8ULL, 0xD4BFE8C05F30BC89ULL, 0x04BAA54E79EC1006ULL, 0x65869B92772EDCF8ULL, 
            0x1A2815CE5A3A8E06ULL, 0xFE3D26885A7E3957ULL, 0xE1E7DF532F809505ULL, 0x4BE012B68226B4BBULL, 
            0x858079C8E7CE4348ULL, 0x796FA8AF2119078CULL, 0xC501223D2B4BB43EULL, 0x7798A5776D401F54ULL, 
            0xF02FF9D6A728E5EDULL, 0xA62F74719BA3FF04ULL, 0x1D4DFB6A890324C1ULL, 0xC2FEC688B753CF9EULL
        },
        {
            0xD2CE75F2688E8D4FULL, 0x4794CCF7BD757D81ULL, 0x8ABA8AD6A6429E6EULL, 0x0EBF2B31F3BD6B96ULL, 
            0x88BFBF3E5EDA3D9FULL, 0x8CC717D7B4159B82ULL, 0x90A51B45A6D3F3F3ULL, 0x9D6487FFF3F76503ULL, 
            0xB647A5F7BC0B6AD3ULL, 0xFAC54A93C5068C6EULL, 0xF69F11E3578930EFULL, 0x3D1E5B5650B629E4ULL, 
            0xF59E0C638389E34FULL, 0x7CA1EFBFF0EFFBD1ULL, 0xDCC01225D4D4858FULL, 0x0A9002F4948F3023ULL, 
            0x0E3CD6651758E9B9ULL, 0x41ECEF6654277378ULL, 0x8247384CB314CCBEULL, 0x489149A3C0145B17ULL, 
            0x75C148238D6F34E9ULL, 0x744EBBB97601D4A6ULL, 0x78D0645C1AC7BAB8ULL, 0xC1636185A5926738ULL, 
            0x2804DA55DF45E548ULL, 0xAD034E829087AFC1ULL, 0x25270C032D7423BBULL, 0x07B3713F0E05A119ULL, 
            0x59204373A6566F1EULL, 0x8C0DD806BBF46197ULL, 0xA06B558FD91DE563ULL, 0x92AAB4E64BAF2CDFULL
        },
        {
            0x6D9D9E9C42D602FDULL, 0xCFE14FE47B7124D1ULL, 0x2715295B8B2958D5ULL, 0x5A58DEEDC7A263AFULL, 
            0x1ECA453BC566AD36ULL, 0x3C9D36600524EE08ULL, 0xE214DF0B060E6173ULL, 0xBE3ABCD30BB16D5DULL, 
            0xC4F195FC9F9B8960ULL, 0x1B135ABC6838E6D4ULL, 0xBEB4288AEFBD230EULL, 0x9D9822075BFE89D7ULL, 
            0xB9DA88323DEB56E2ULL, 0x744A5188878172E2ULL, 0x56656E4B2329EB4FULL, 0x56F9BE6FD08A999FULL, 
            0x0E3361B14F7F3B3CULL, 0xE18084D00C81B387ULL, 0xB8C90DBE20C38000ULL, 0x9E10F24039143BEAULL, 
            0xCDA0B0B40FD5A1B5ULL, 0xE3EC446FAC389A71ULL, 0x310CE2F895692C43ULL, 0x6819263929F1FC20ULL, 
            0x06A95D23113B28FAULL, 0xEAE8B25911724BCAULL, 0xBAEF9FD443F39CE6ULL, 0xEF07E053932C28B6ULL, 
            0x84DCC919400B2157ULL, 0x141873763386A7EDULL, 0xB796322FD3CD20F8ULL, 0x62E6C00C761D983FULL
        },
        {
            0xFD4A7DB4FD0CEC6BULL, 0x4F414F7E20340B23ULL, 0xFEEC918CB2C9534DULL, 0x7D9505F422DEF543ULL, 
            0x182FA6324A7B2292ULL, 0x22784BCE87000C58ULL, 0x480CC9957BAB82A0ULL, 0x48941B63B1518D59ULL, 
            0x28CBE127C9092EA0ULL, 0x046B63E7CBE538D9ULL, 0x87FB58CDFA1C57DBULL, 0x368BF12C55D13ABDULL, 
            0x10DB3BA246B074FFULL, 0x87671D3A366370D3ULL, 0x1AD8BDD5B3BC1F58ULL, 0x8E22876BDD1229F1ULL, 
            0x58E7373B2DE320E1ULL, 0xCC667F0E6EE68089ULL, 0x55E6E00574AD408EULL, 0xD1B465312863B536ULL, 
            0xAFE70658CD746FE1ULL, 0x41DED5C1F9834BC7ULL, 0xA1765A3D9EFB35C2ULL, 0x870162E51006560BULL, 
            0x74C72D43B9FD1338ULL, 0x1AE8A288430B5C41ULL, 0x5C02A27EC23E2462ULL, 0x85B84E29502679FDULL, 
            0x508E8B22368BF1D7ULL, 0x978B468EAAE41882ULL, 0xBB48FDC01DADF686ULL, 0xD5094E02456C872AULL
        },
        {
            0xEA863AB78F546EACULL, 0x8D3075D9B4B2AE42ULL, 0x098A44A13C017888ULL, 0x21E8486D7445D146ULL, 
            0xE8D197823EC5A95CULL, 0xCF946D9B978F6293ULL, 0x97AFC821A049499FULL, 0x39BD4141306E6F9EULL, 
            0x12C292058E3F93F7ULL, 0xADAC4CFE4F2BB022ULL, 0x7449582E2A90BEC5ULL, 0x88C00F9AD5935751ULL, 
            0x943605660A94D9B1ULL, 0xB2F7C06478320759ULL, 0x266B0A96DE87BE7DULL, 0x9C95D17680B1199FULL, 
            0x9E067D0A37E6D9DAULL, 0xCBD45EC812FB03ECULL, 0xA2484FCAA6D53272ULL, 0x2E15BCAABF6CB0C1ULL, 
            0x550B2E7E817140C8ULL, 0xCF5AEF08F55F748EULL, 0xA4FA536425AA6F8FULL, 0xB266DD232F57B9DCULL, 
            0xD6F0EEE9FC45B1D8ULL, 0xBFE0DF87062E8E2FULL, 0xFE2667B560EC99DAULL, 0x6721491056472FAAULL, 
            0xF0A6A411BF197729ULL, 0xC5F41550AEF04055ULL, 0x98A6650AD1462DCDULL, 0xEE3FFF99827F17E2ULL
        },
        {
            0x3E43A248A16FB753ULL, 0x534F277CC3C1187EULL, 0x48EE8D0BE02E9000ULL, 0xB18AF199247686B3ULL, 
            0x6433C56A46F8E8FCULL, 0x2EB2FFA8062214E6ULL, 0x017E8BBAB270A8CEULL, 0x33FBEF6EEAEF6B62ULL, 
            0xABB578040903D456ULL, 0x6237D90C490CD7F3ULL, 0x24A2BF9D0F1A8D77ULL, 0x404A8D59FE013DBDULL, 
            0xF21689118918D61AULL, 0x2903D81DF28182E2ULL, 0xF9132498C9A117EAULL, 0xD013F2DAD00B53FBULL, 
            0xF9EF85DB07E0335EULL, 0xEECC0CACC7072D93ULL, 0x89BBF3D17EBB37CFULL, 0x77883F4761308594ULL, 
            0xB2E9C85966A03B7BULL, 0x856794FDB4FA38CCULL, 0xA6C93EBE649F63B0ULL, 0x076A27A98D9D6B17ULL, 
            0xA80E3B86C6E31BABULL, 0x9BBE38CBB0EF4DA1ULL, 0xCBC19F9A3BD3642EULL, 0x361AACD80200520FULL, 
            0x90C81268E7E0A0BFULL, 0xCD34AD0B3AC15A4AULL, 0x6AA029AA8E21AC11ULL, 0x11235C1B12172306ULL
        }
    },
    {
        {
            0x5590B8E0E75DCF6AULL, 0x0AAF8C86DEFE99CFULL, 0xE1A3C770C31E8D6BULL, 0xC57D83D18D30EC8EULL, 
            0xD2DCFEBA29737E61ULL, 0x69406A286860346AULL, 0xD1CC6F226D8C642BULL, 0xE99040C1800486F6ULL, 
            0xE8C78AB343D5C920ULL, 0xEBA270A37202A212ULL, 0x9BEE38E6F097EFA8ULL, 0x505F4F307A3FF7AEULL, 
            0x4B7FE54F7BD11F24ULL, 0xAA8B4F23372AACEDULL, 0x4DE8024A3B9E2322ULL, 0xCA912C019BD4E31CULL, 
            0x0DBEA942F8873200ULL, 0xAB3A2529F84368C4ULL, 0xB37C7C3F1B14A5B5ULL, 0xCB548EC2E26329BAULL, 
            0x4035B9826FA00B5EULL, 0xF55B322255097F57ULL, 0x13FE3ABBA89FF80EULL, 0xCC3FC4CC81400A72ULL, 
            0x3435F7F71ED624EFULL, 0xF13C1417151FB007ULL, 0xC6E88DC753451096ULL, 0x8D978F50951B02FDULL, 
            0xE0C66CDE74428C34ULL, 0xC06C7BC7C5D98DBDULL, 0x1F15E65F3F2BFCA4ULL, 0x647A4136CBAE1C4FULL
        },
        {
            0x19A52A3E05FBD7DEULL, 0x5A9C2022A640CD71ULL, 0xD0ED64786A282866ULL, 0xEF7A8C4C97F29A2DULL, 
            0x57A345D9306018A2ULL, 0xFFDF2F47AF1E4985ULL, 0x57EA428EFA15FC21ULL, 0x666CBE58ABEEE551ULL, 
            0xA185391CB09D5BACULL, 0xA8F4B5BFE1865D89ULL, 0x77EFFDE4C5C586F0ULL, 0x011B7ACCB4CE945EULL, 
            0xD8A4B5117BC255D9ULL, 0xFCA01B4C756E5BE3ULL, 0x5CED9A95678272E8ULL, 0x4DA1362B4D419950ULL, 
            0xA41DC2F5A00C4B13ULL, 0x745D21A81FB1D7C8ULL, 0xAB83CE9ACC9C8858ULL, 0x78CC6CCEDAD6737AULL, 
            0x80F022A1D6CDDFB7ULL, 0x65698C4F3E5FB1A6ULL, 0x78036D7F809EB3C3ULL, 0xCC7798BB913BEC83ULL, 
            0x8BD4405E759B8D5AULL, 0xDA9AFB604CAEC3DBULL, 0x04274541353CC0FFULL, 0x883267A680FAA0CEULL, 
            0x75E09AB164828C36ULL, 0xB9CCD50202DB3417ULL, 0x55E691953179D697ULL, 0x5EBC6716556D5A05ULL
        },
        {
            0x3D3BE22423F13DBDULL, 0x82986AF9D2E1EC1FULL, 0x71FBBFB2526371FFULL, 0x765BF92C5B6185FFULL, 
            0xEE3788EA6C1A6CBFULL, 0xB1EB68FA159C2B33ULL, 0x4A2D9A763F193501ULL, 0xEFB5B83B7B3C2EBBULL, 
            0xFBCC38207612993DULL, 0x725E5CD37BC1BF2BULL, 0x35DBC22ED6352D63ULL, 0xC8D127294AD464ADULL, 
            0x8C2326F49CE72683ULL, 0xC4E1969F3E7FEF11ULL, 0x5F3A03955914FA9BULL, 0x5E20E36C4CFB1683ULL, 
            0xF256D4087B7727E0ULL, 0xEACB43D1DEC420EAULL, 0x245F3F53E4C28AD8ULL, 0x3359DEC54E66C07CULL, 
            0xE5BBA7B72CAA10F2ULL, 0x37E03F25548C881EULL, 0xFE467C69F37F391CULL, 0x5B5B5B4F2064AA2CULL, 
            0xB221C0F60A210445ULL, 0x9274821192D6ACA0ULL, 0xEC989CD5350FE16AULL, 0x30115D4C64C808E9ULL, 
            0x0A772B97EF51FF34ULL, 0xDDBD80C32C9C3C43ULL, 0x35720771475DA398ULL, 0x540E846D568DD811ULL
        },
        {
            0x28C98E42F7E8F6F7ULL, 0x2A3774716A01F511ULL, 0x15705D583018EB6EULL, 0x9E232630AA57C4EFULL, 
            0xAEA5B70824B41895ULL, 0x23FF8663D6A48259ULL, 0x7F858101ABADAAB0ULL, 0x14BC9785D45323A8ULL, 
            0x6DC2088890DA1B84ULL, 0x0C7178C2DD9B9B57ULL, 0x7A3A5BD2FF872BD4ULL, 0x0ED0A71EFA402FF8ULL, 
            0x2B2480A677FCA959ULL, 0xCCC54FE56BFD0E66ULL, 0x13E57FA90B4F0A28ULL, 0x25BD1383F4E8DD90ULL, 
            0x50FE97DEC0922D4BULL, 0xBBEEB2CEC110E1FEULL, 0x7500C43F15D5831CULL, 0x7456C78A2CA83DA5ULL, 
            0xA432F1748F6A6E79ULL, 0x03C54E8D73BFCC94ULL, 0xC4D0776FD629F7AEULL, 0xB0CB8F0C289A02E2ULL, 
            0x44E6BAEF0B220650ULL, 0xC7376696325D4867ULL, 0x9E76E2F2F66DB37EULL, 0x945984EA337E1E67ULL, 
            0xD079231E3C83EC13ULL, 0xE403238B6096779BULL, 0x084CF02537D71974ULL, 0x80569A533DC1CEC0ULL
        },
        {
            0x9153F5D0DB83D932ULL, 0x5505AA260BBABFC5ULL, 0x715449A0D4E63C50ULL, 0xF564DFC90DF8EF14ULL, 
            0xCACC071FC8EBEF98ULL, 0x3B575ADBDD10796EULL, 0x5186B1A350748315ULL, 0xCEC1F026298C616DULL, 
            0x5BA7425EF77396BDULL, 0x7540861FF3BDF56FULL, 0xDBF047468A52C7B7ULL, 0xB5983372D90231E9ULL, 
            0xFDC83802AC4ADC24ULL, 0x61855B7B0E72F673ULL, 0xA22579BF9A39CBA8ULL, 0x48D2C0569A035843ULL, 
            0x79DCD449512C2145ULL, 0x620814C65BA940ACULL, 0xFE5FD303E10DD82AULL, 0x3107FDEC396F51B2ULL, 
            0x619B84C38C6B06D0ULL, 0x172579DE49419FF1ULL, 0xE14952C1E651447EULL, 0x12B234A27EE97996ULL, 
            0x0D8AFE5175D84117ULL, 0x6EA21A545B9E60F2ULL, 0x6CB6392B579CDF63ULL, 0x1CCF86FCCB0B992DULL, 
            0xA640374842A6DDCDULL, 0xEE6BC013DDF37FCBULL, 0x98DF7A23022D563CULL, 0x06738BA71F999B33ULL
        },
        {
            0xE2C9B0D5A75C6109ULL, 0x38F4018B93943AD7ULL, 0x7C60A6489FD47111ULL, 0xDAE08B15D9FA14BBULL, 
            0xA70D0BA7C0912A19ULL, 0xCF91B756F938BE9AULL, 0x7552628F0653A6EBULL, 0x2E2DD7E592EA6406ULL, 
            0x9DE33D2E876DAF96ULL, 0x4D5F669EC93CA0D0ULL, 0x6AA235D95CF420A9ULL, 0x94EB88BDF6E98833ULL, 
            0x1DD9EF0F9682A445ULL, 0xD83A8531EDDC063DULL, 0x34609853EBEF0C3EULL, 0x0BE0160F514D6456ULL, 
            0x6B0C202CBD783F8CULL, 0x5DBD107DF493715EULL, 0xCB4CF872E00D6DEEULL, 0xE9782D776838E3A1ULL, 
            0x6F800A0B3B013F59ULL, 0x709C9284911D79CAULL, 0xE816BCC85CF3CD97ULL, 0x47E4CAB7C4DE3E69ULL, 
            0xEA66F2546A7CEE78ULL, 0x49FF7715447A50FEULL, 0x9E8250D364311A0EULL, 0x4707260C65C06FE5ULL, 
            0xC4F24345C9E38A9FULL, 0xD7FCD68D62DDCFD2ULL, 0xDDB9030162F312D1ULL, 0xCEEC89D34476EE02ULL
        }
    },
    {
        {
            0x38ACAA405D1E5D3CULL, 0x24494DA7EA827CAFULL, 0xFDCB5324C19CACFCULL, 0x36D99423C8003C42ULL, 
            0x7FB28DDB7E011FB5ULL, 0x843C8BD238F7E542ULL, 0x757AA492931CC3BBULL, 0x166B9E2AB3CB761BULL, 
            0xA0625E08BD784426ULL, 0xC86AC0E49DCB8377ULL, 0x1A9F4E99121B6615ULL, 0x4D31387FB0474987ULL, 
            0x0C636B5C354D4F70ULL, 0xD241D716595135A8ULL, 0x65A344C415279EA9ULL, 0xCAEA66B40FCAD1E3ULL, 
            0x348ECC304528BFC9ULL, 0xE8E8AD187B5A3281ULL, 0x6A19C420A23CAFA8ULL, 0xA50B954B621A5673ULL, 
            0x523FDA14E466CC8DULL, 0x97AF4DFEDD263A75ULL, 0xB058982550E09E16ULL, 0x5C8A2AA711204295ULL, 
            0x26512980EC2F4A22ULL, 0x37B76A59CC9DA764ULL, 0x7BF3D3B9D1B815D2ULL, 0x617216C77042117BULL, 
            0xD606F852E4D7DC89ULL, 0x06229D3D89DC5A6FULL, 0x978278A1B94A14F8ULL, 0x55C538C32B3C1D6FULL
        },
        {
            0x79E649F7DD431817ULL, 0x0541F0930A8743F7ULL, 0x1F97A9589060635EULL, 0x7D54C1A0A4F51163ULL, 
            0x67CA1099D1B4ADEBULL, 0x4A485E3209AD70B3ULL, 0xBE9A85897E148192ULL, 0xDCFC0389B6887A03ULL, 
            0x7F88CD023C2213E8ULL, 0x285D1E8BD61C3E7EULL, 0x0F66AC683AA9DE69ULL, 0x58593583DEA5B9D1ULL, 
            0xAD7A5F0C31E11989ULL, 0x27B299BEE4DE9A45ULL, 0x00C1E7401F1AB190ULL, 0x782C28D73171F90CULL, 
            0x57EB1CBDBFD235F8ULL, 0xD20360AE2FFB79F1ULL, 0x22A892A433A4B565ULL, 0xE8D8800371F18529ULL, 
            0xAECA6EA905B4066BULL, 0xFAC787C4EDD3D6CDULL, 0x5EEA06FFA939524CULL, 0x87E7F89D85953BCFULL, 
            0xC23446AF3C3CCD4DULL, 0x2773B41C4FCF61D9ULL, 0x1FD1EC53F924F863ULL, 0xEE4BAB7498F30D87ULL, 
            0x9ABF82A48B4AE26CULL, 0x5CB60AAB369B2047ULL, 0x4CBF6D55AE87D8E2ULL, 0x7F1C4C083B947058ULL
        },
        {
            0x3F0AE86AE70BB067ULL, 0xBD358CE9D96B3C0EULL, 0x881B709DE40FA0F1ULL, 0xA9966D4F6B9AC8C9ULL, 
            0x30B51F07989372DFULL, 0x12B039043ADFCC2BULL, 0x95A3B44A5F7E2614ULL, 0x3D3731191D10D10BULL, 
            0xD303D4E1A1466651ULL, 0xDB3A14721BA172D4ULL, 0x7E7EC017926C390CULL, 0x3BE4279181899C27ULL, 
            0xCC412DCC705EAFC3ULL, 0x9B8BB7863B9574F2ULL, 0x0434043D3A9349F5ULL, 0xCECB87DB1616D0AAULL, 
            0x7D098DAB73D2493FULL, 0xA1E502517A6FE8FAULL, 0x017B5F9F03FD34A8ULL, 0x2E9F4EC06EDF43C6ULL, 
            0x1011702068184B3AULL, 0xAEC33DF8D8C9A354ULL, 0xB30B2389A7FF38CFULL, 0xC5A2CFC86031505FULL, 
            0x5DC6D75B6E0C4327ULL, 0x392D04E4FED48B55ULL, 0x1046D838F8246D50ULL, 0x5B6CEE7294157A6AULL, 
            0x5AA51EE9AC74ED93ULL, 0x2732341D43CE16DAULL, 0xE9D51D7ABDCE2C94ULL, 0xDDDA6E3730473B5FULL
        },
        {
            0x036046006F7A533FULL, 0x8EB8A08E6FC778C0ULL, 0xDBB1F9727152CEBBULL, 0xFE7D76DD8383003EULL, 
            0x6CDA09AB88061F51ULL, 0x19A97135D2FC3210ULL, 0xE7A829F34BCAD9BEULL, 0xDB7345B74515D18CULL, 
            0x9EB02E20D1FCD1D5ULL, 0xEE01B8E6EDF191D9ULL, 0x19BB813FEE2CA977ULL, 0x32DB66858017CBABULL, 
            0xF7C771D2593BA428ULL, 0xA525A4C8962F419CULL, 0x0DB24FDC60759236ULL, 0x662829D7B3F237BDULL, 
            0x21FEDD6302CA10D6ULL, 0x37D77CA497E9CC50ULL, 0x53D6577115FF7179ULL, 0x9A2E73C28ABC9012ULL, 
            0xCBCD1586A38462E7ULL, 0x8BA5E5D4D7E73122ULL, 0x77302A4BAC1B2EA5ULL, 0x80F95DCB5D25DB12ULL, 
            0xE66B6959313DAC70ULL, 0xE102F36406341F45ULL, 0xCE6B963002A810B5ULL, 0xB31F5D1C8D992B9DULL, 
            0x7BF9998CCB45468BULL, 0xCF22FE4541A6CD47ULL, 0x47BABA84D1DAF72DULL, 0xC00050A0EC02D6A0ULL
        },
        {
            0xA8852BB6E84DAB2DULL, 0x9EAB65175050EE93ULL, 0x44487D14AA6AFCCEULL, 0xEE5C673DE988E3C5ULL, 
            0xE06FFBE5401F0364ULL, 0xC58DE707CDCB2FC8ULL, 0x2F5E62ADA2F9A4F2ULL, 0xF1CAAAFC897439A2ULL, 
            0xD58A7906A6698819ULL, 0xDD06F804B7383DB2ULL, 0x96E0DB2E2AE7DDE9ULL, 0xDD1A8F6E428E0DD1ULL, 
            0x7B56BE2D068C2B96ULL, 0x5D8D23657F149A86ULL, 0x51C6433986016414ULL, 0xAF5154D42CF68DF3ULL, 
            0xB0D1319011B4B318ULL, 0x5DB3966C79644585ULL, 0xE1F517442ACE1133ULL, 0x615A9EE395BD48CCULL, 
            0x1F2EE699DF26FB86ULL, 0xBF1F4EAD0B71297FULL, 0x5A4207ED632D87BEULL, 0x72BD29DF059DFD0AULL, 
            0xCE6AB13E3B24E08EULL, 0xA313ED2DD6B28637ULL, 0x572A64D00FDCBC71ULL, 0xFBCB73F70908AC33ULL, 
            0x0FB55658DA7185BAULL, 0x65B06AB5D0AB6C3AULL, 0xC8F77E87882BE95FULL, 0x33BB1FF6153C9C80ULL
        },
        {
            0xCB3729A072815C63ULL, 0xE42FD0D9351DB2ECULL, 0x7905D0C69FAFF431ULL, 0xD0F1E21341EC171BULL, 
            0x771A207116015938ULL, 0x013454938CF086A9ULL, 0xEACBB560EA38BC17ULL, 0x2957BF8EB87F0119ULL, 
            0xAEDEC78B3E77EE7AULL, 0xA99D2ABD85F56748ULL, 0x5FF2B8E5D173A364ULL, 0xDCF9C8A1E6C0A01EULL, 
            0x224EBB781A2C6626ULL, 0xDD7643449954D019ULL, 0x1ABD716F2A76F552ULL, 0xFB252F248B214F63ULL, 
            0x4DC823D0D53F89D5ULL, 0xDC677669DAC1E2EDULL, 0xC135F58DAD74DE0FULL, 0x9EFEE4795C29A166ULL, 
            0xA3C6C7A08DBEF89CULL, 0xE5B706DF4AD86547ULL, 0x98C4585A043BE008ULL, 0x2F09FF3E5EE72D04ULL, 
            0x1B61DCE9963CD846ULL, 0xB34BD925F7127455ULL, 0xF9061AF4674C5CC1ULL, 0xFD02EF40C564B337ULL, 
            0x81E68EF2CD11E10BULL, 0xBFCDD08459606118ULL, 0x35A824297C94BF65ULL, 0x70C4E476DA3237A3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseGConstants = {
    0xAA67D5F6062E40D5ULL,
    0x2199B483951BA308ULL,
    0x5C9F9FAC8C8DCC18ULL,
    0xAA67D5F6062E40D5ULL,
    0x2199B483951BA308ULL,
    0x5C9F9FAC8C8DCC18ULL,
    0x3BA2420398CE99FEULL,
    0x9A80F65732B5F67AULL,
    0x9F,
    0x3C,
    0x19,
    0xC4,
    0x55,
    0xAE,
    0x1D,
    0x31
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseHSalts = {
    {
        {
            0x20D242D26FAD9A7AULL, 0x5F2448217EE58DE3ULL, 0x10EA0842FFF771C6ULL, 0x481A3855530F14EAULL, 
            0xD0905E439D4FE970ULL, 0x301A42D3BBCE6FB0ULL, 0xCA9CE59794E8FFDDULL, 0x2DF42E8E6B661F4AULL, 
            0x3A930D298698F670ULL, 0x4210583E014C9DD8ULL, 0x98467F9531FC9A97ULL, 0xEA83514C49A89544ULL, 
            0x64F67B024FC97487ULL, 0x5DB7A78E1F01A37CULL, 0xB407D9A3CBE1A372ULL, 0xB74E724FB642089AULL, 
            0xB0BE6654611C3552ULL, 0x3A7EA23E9B3BC0F5ULL, 0xEF4A0491E70FB444ULL, 0xEAA632F76E10C4C1ULL, 
            0xBC6619CEFE1C680BULL, 0x4AAEA7CEE8DD1911ULL, 0x86E9D9424C9DED30ULL, 0x4497C209189DE521ULL, 
            0xA95CC325DE9D727DULL, 0x771E6A080B22C1CEULL, 0x2891202543C9DAD4ULL, 0x632E0FF30E2ADA63ULL, 
            0x485368FD32306EF4ULL, 0x7EA6789FF53FF8F5ULL, 0xBB5371FB9A6E0F78ULL, 0xA93D976419B44CE5ULL
        },
        {
            0xF9F08F9820907094ULL, 0xFB434C89E9E4E5E2ULL, 0x3501619B777C2ABFULL, 0x4D28F55EDA0ED324ULL, 
            0x130C1A1F1A5A4EA6ULL, 0x5741B2266339FEF4ULL, 0x769BCAA09CD90162ULL, 0xF7BAD7C5959E1F14ULL, 
            0x1F06A033A1164A15ULL, 0xF79D6CDF7BB848A5ULL, 0x1CD781D99692F9DDULL, 0xA9CE06C551FC1DA2ULL, 
            0xA78841880E86A629ULL, 0x91ADDB9F762275E7ULL, 0x3CEE291ECC3630D1ULL, 0xECDB83C57E9677FDULL, 
            0x5DC08430BF7DCFD0ULL, 0x7F46190B7A36CE5CULL, 0xAC1CE87FAF5C1AF3ULL, 0x8789A8F67BACC029ULL, 
            0x6BE4A9690068E63AULL, 0xD33E2B11A43E0984ULL, 0x64B4A80099317342ULL, 0xFEDD469C79C8E6A7ULL, 
            0x16D762A9BC7898A4ULL, 0x3A04300269B03E66ULL, 0x94DDCDBABE8C842BULL, 0xE7069F96F7D44EEDULL, 
            0x1D8D4838933FD28CULL, 0x1B1A34E1E4049B2CULL, 0x6379741D05F01D80ULL, 0xC8D205136B4539A3ULL
        },
        {
            0x43DA5789ED89A680ULL, 0x5FAFBA8949F1CAC7ULL, 0x7E27C6598C6E148CULL, 0xF4EA0500D409D610ULL, 
            0xDE62442B23668055ULL, 0xC413056519384530ULL, 0x167295DAAD608969ULL, 0xC7904856932B3F4BULL, 
            0x2BD511F69C345532ULL, 0x10EBEECF8184CD82ULL, 0x9108335C4F5B56F1ULL, 0x90D162C9DF203FEBULL, 
            0x0616809CA0CF68DBULL, 0xD4ECED1416071987ULL, 0xB8042EB15542E722ULL, 0xE92C35BB6F9D5F16ULL, 
            0x6171A63DD6377F0AULL, 0xC8C8D79FE3FC6B62ULL, 0x3D7C443EC66E1F05ULL, 0x8FE63E76F4D1BB5BULL, 
            0xCE07853984832681ULL, 0x97552854DAC729ADULL, 0x453027A3FA967718ULL, 0xE7A8EA588844AFCBULL, 
            0x17A8D4C232D8FD2AULL, 0x73E86289611AE39AULL, 0x78541C838CEF856BULL, 0xF9425EEEAEC654E4ULL, 
            0x7599E9107F5698EFULL, 0x32D9BA53FCD1A922ULL, 0x86DA7E1CB29702DEULL, 0xE898984B25EC23CEULL
        },
        {
            0xF559103405383EEBULL, 0x9787777CAE53FE2CULL, 0x04D97329F89B0E39ULL, 0xEB514BEE81A3A98AULL, 
            0xF99A29DD5823B45DULL, 0xEF83B871FA9C3B9EULL, 0x44A981E085B7FC83ULL, 0xF730919AF28041EDULL, 
            0xA24250EE86FE93DEULL, 0x0DF4F3636D80499FULL, 0xDC349B1C5F1983C8ULL, 0x4D9F9636F1ED460AULL, 
            0xF8A5DB933D39B70CULL, 0xDEE91AF379BCC027ULL, 0x2ADDE5B024DEC1E2ULL, 0xE1AD83EDFBEFAAA1ULL, 
            0x28A31FC147E3DFBEULL, 0x8290B031614839B3ULL, 0xB8596EBADB1692CFULL, 0xB72AA96293549D7DULL, 
            0x50EFAB47FD0FA8B3ULL, 0x7AA3CAC6A21F4A93ULL, 0xAD0DE21DFA642603ULL, 0x38893B6766FAE8B6ULL, 
            0x9C2129D71C589C41ULL, 0x60CAC7EF52993591ULL, 0x11FBC9984F7E5AD2ULL, 0x19B2D28EB2F65B79ULL, 
            0xF4334F6FA1ACD0ABULL, 0x7C44C9AF7C865F61ULL, 0x450A78F2D5D75481ULL, 0xFF1216DE216BE587ULL
        },
        {
            0x149A6DC98E46FF85ULL, 0x46628F443FE08B35ULL, 0xF398CEF5456FE685ULL, 0x87783E4C4964D640ULL, 
            0x37DC74854B6CDA10ULL, 0x2EB45C27A26EA24FULL, 0xE2643F30C41D1DE1ULL, 0x93DB2E6DEF9B9641ULL, 
            0x3555098E21755451ULL, 0x8E98ADB74033B425ULL, 0x18A13B80814B2253ULL, 0x6AD420AA3BD65EEDULL, 
            0xC2EBF98B74749E62ULL, 0x0E8EA27956D1C873ULL, 0x689D83578852B78DULL, 0x8B73BC4DC5E815D3ULL, 
            0x59E18BEE30A8A1B1ULL, 0x4EDB64625A131E53ULL, 0xA2981577688D915CULL, 0xC7D53651BBA6D2B6ULL, 
            0xCBE3FB79FA596178ULL, 0xEDB513407D3B6289ULL, 0xE08D4DE6C12F47D0ULL, 0xBC43AE688BB1843AULL, 
            0xDE5F52EEF9B8CF18ULL, 0xCD6FF72AB3976245ULL, 0x4F38DD84E0379C66ULL, 0x314C5564D7314910ULL, 
            0x1B2B6B2DA6778E92ULL, 0x83B01B93475535D2ULL, 0xCFE051FFF19DE18EULL, 0xE4296BE61F1B0298ULL
        },
        {
            0x9F62FFE5BB57C777ULL, 0x79A7AD1914FDF1A5ULL, 0x3C2C3ABD1D17134BULL, 0x9EED06048089A0CFULL, 
            0xEF2AA944C2487BCCULL, 0x0C6C64DB4D46B7FFULL, 0x840723325C5E8F1CULL, 0x860654A060583122ULL, 
            0x203B556982DB330AULL, 0x5A0FD7A008252235ULL, 0xBEDAE75FD28247E9ULL, 0xE68B3E7478A6CF64ULL, 
            0xC982E40B506120B1ULL, 0x73EB2A5790985D71ULL, 0x06FF19C016A15389ULL, 0x5A5223F0DF571DCDULL, 
            0xAF920030D0052256ULL, 0xBF6BFA910387DEABULL, 0xAA2417A03876C64BULL, 0x022B597CBD801D29ULL, 
            0xF4E12F94DA083527ULL, 0x40A247605747EB5BULL, 0xA7159217FBE4F0D7ULL, 0xF1B3E18D4BD1C02AULL, 
            0x64F2220BE31A9E80ULL, 0xD96E3D33B962FCC9ULL, 0xE4DD1C5C5F056546ULL, 0x119CBD05B95D8940ULL, 
            0x462F354D47AFDE13ULL, 0xB0655CB30617C102ULL, 0xF30F2CA86D96D3DCULL, 0xC7B9212508BBB2A5ULL
        }
    },
    {
        {
            0xB59F3B967DB1097CULL, 0x6D1A84AB87A6D314ULL, 0x1A6B21DEEF272043ULL, 0xB9DF692B99971347ULL, 
            0xBD6A34E50B5D3D8CULL, 0x3E883BD9F99C98AAULL, 0x795A9E0579CE14A7ULL, 0xC810FF069A5A9E52ULL, 
            0x527EFD9B3A7F252EULL, 0x8796F06C61C62487ULL, 0xD3E0B7EE622F73E1ULL, 0xEFC1D68A371409F4ULL, 
            0xBDDFDA0433567FD4ULL, 0x5A40DFBB7D7AFE70ULL, 0xC1A58CA769B27FF4ULL, 0xBEF83FA708177030ULL, 
            0xDD911BF1C22FF574ULL, 0x18E236E6482A2388ULL, 0x3D1025D2B9964AA0ULL, 0x53C4B21D9113B452ULL, 
            0x2E97D32F782EB6BDULL, 0x6ADFAA842BD965B1ULL, 0xB2A09EAFEF319EBAULL, 0x9BEDBF917E68AE32ULL, 
            0xB329CDB90E9B3602ULL, 0x706B636C26D98ABDULL, 0x07F7107BEB42BD40ULL, 0x0D2974EB054A9F5EULL, 
            0x1A2B9158FCD0F1A6ULL, 0x5FA25CE2D42F70D0ULL, 0x50A32F3AF26366F0ULL, 0xC1361A2D5DF0448AULL
        },
        {
            0x247B1E36B26EDA8BULL, 0x34290269FF42B539ULL, 0x9CC3CE9EEAAE28C5ULL, 0xE944D9F35695B5BEULL, 
            0x20BCFB556FD27B97ULL, 0x579E6E8666D15E6FULL, 0x0E4B98C93E5543A1ULL, 0xA42EBB9991F8B87DULL, 
            0xA52B05B7F2BB5E38ULL, 0x8BC543B330CBCC08ULL, 0x904A01A065DD566BULL, 0xB004D830230EFB00ULL, 
            0x7EA772EFBAC162C0ULL, 0xBE00B00FCA177F0DULL, 0x0C9B987A7DDA1BF7ULL, 0xD7651701B3590BDDULL, 
            0x18E85743C189F5A7ULL, 0xFAEFA5D4315E5DCCULL, 0xFE6FCF8405EC27DFULL, 0x1CF661C9061F8F0CULL, 
            0x9B131FC11E42B674ULL, 0x6E52254B0ACB0D83ULL, 0x2F16C18D03C9FD60ULL, 0x8EE8160F240DBC81ULL, 
            0x534EED6A70884724ULL, 0xF596EEFC8929C9D6ULL, 0x32BA16353D03B88BULL, 0x2EC6AE8619F48B8EULL, 
            0xD635E7B3CFA3D80DULL, 0x98B094FE010E54AEULL, 0xA3F4BF129EA161E7ULL, 0xEA92EC66B31E9F98ULL
        },
        {
            0x9FAC0433F1923424ULL, 0x526C2FCDD1B24044ULL, 0x549FA9A542C7B08DULL, 0xE52CF55A5297D353ULL, 
            0x40D4C0D533C92C30ULL, 0x9B7BDD1815A81868ULL, 0x96CDEA5677994FEAULL, 0xFE6FC0F8A5A29C63ULL, 
            0x71FD5EDBCA1445C4ULL, 0x8171D45156700ED7ULL, 0xDBD6C4E45F84C4C6ULL, 0xCB253AEA2479F398ULL, 
            0xE87A947B73F2441CULL, 0x2034348E97F73B8FULL, 0xD85C77F72D5DEA66ULL, 0x5D97C0782E134C5EULL, 
            0x8CE1109A2222DD2FULL, 0xDC876760542B8CE0ULL, 0x245ABFA41E31D826ULL, 0x4FE2EBA6ABD4DF50ULL, 
            0xC59106B4E33D33A7ULL, 0x48C33139429D3A2CULL, 0x2E0554BAAEEBDA61ULL, 0x27CCAC024485A8F1ULL, 
            0x8C6BE3961BCF7BFAULL, 0x726591A59B9154E4ULL, 0x030EBE668E3727A5ULL, 0x2EF7489D4E3BA873ULL, 
            0xC04A273EEC3BF6A3ULL, 0x267897302D3212A0ULL, 0xB0A7218A4774DB0CULL, 0x1BBF3797CA31F138ULL
        },
        {
            0x775F9F03E5030FB6ULL, 0xD71258AF69A8B3F6ULL, 0x26BCA33D550D3BA2ULL, 0xA741C45B5415541CULL, 
            0xA68A27365E0254F5ULL, 0x4914EA4590B0E113ULL, 0x8D9F01DC54AD4164ULL, 0x1CF53BE3517A93E4ULL, 
            0x4C18CD2B632E233BULL, 0x1969CD94C8FFD3CFULL, 0xF718BE90375E926BULL, 0xF6B3889992C76A7BULL, 
            0x162C93348CA1C63FULL, 0xD73A6C91D40FBFB0ULL, 0xE06616F0CFCBB839ULL, 0x3399FF662861DBF9ULL, 
            0xEC036BDDD63CBCFDULL, 0x3C75438DF59292A8ULL, 0xB82CC584982CEC93ULL, 0xC9ED0D1B99B51CF7ULL, 
            0xA715CC9582BAE1DFULL, 0xCBCF8216B8E15B58ULL, 0xD8C688BC4E89F95CULL, 0xBD4C11D68886B058ULL, 
            0x04ED60C8F18FEA5CULL, 0xF71AB0970DE8AE96ULL, 0x6B946CC844759096ULL, 0xC382828BEC5B558AULL, 
            0xCA03D1EB995528B8ULL, 0xFA7D672D3EF31247ULL, 0xCC74EC88D6E01F28ULL, 0xD621F8BD44B39D19ULL
        },
        {
            0xB04B3D3AE2906A27ULL, 0xD586224E1CEED9F4ULL, 0x2CB7431E8FF4D7D9ULL, 0xEBF9AED251DB9912ULL, 
            0x88AF8C206B33A408ULL, 0xF2AC2FFDE9C1CB90ULL, 0x88A35B6A29728351ULL, 0x1C8BF61084A5A7BFULL, 
            0x778C02C6E75B98BFULL, 0x5E503B4520A81453ULL, 0x356DF43BCD15DF44ULL, 0xD5834041C049D580ULL, 
            0xCE452FE18153382BULL, 0x7ED397FE9A168FAAULL, 0xAA92020AC8D87BDAULL, 0xDDA816878C92D61FULL, 
            0x963F84F16A4153F7ULL, 0xE9B2B9247BF52B57ULL, 0x3D7CE499E22205B1ULL, 0x5F76B6206BB2FD53ULL, 
            0x4E5DE79BCF98C6C5ULL, 0x52C50B224D423E0BULL, 0x1FBCF08DEDCB9E4FULL, 0x6A758290129E6781ULL, 
            0x66DCFB638DA9DA0AULL, 0x100D50B893F16AD1ULL, 0x5469E14F060C518CULL, 0x71F1C8C3C15DA239ULL, 
            0xA787BAD85CC255BBULL, 0xA49286F45E8BA366ULL, 0x4DA9708FF007ACFFULL, 0x914BF62FA99A6856ULL
        },
        {
            0x4FCF819B40572093ULL, 0xD607951D9CFDAC72ULL, 0xCD8A805A952562C4ULL, 0xC6C1887092A83277ULL, 
            0xA28293429C3C4B2CULL, 0x60B0AF765AE54394ULL, 0x81D46D96ECA2C7EEULL, 0x83C9CC6B0B0162E4ULL, 
            0x8C273F5A61901CDFULL, 0xF5C9A0769459C5BCULL, 0x24744556282DA6ACULL, 0x92AB0DD8678ED6E6ULL, 
            0x496983FE45E52A61ULL, 0xAFCCE11096268841ULL, 0x6AE771A8905237CAULL, 0xCCDF4017347C7802ULL, 
            0x9C56245A57B22C5DULL, 0xBB9C455E68F71923ULL, 0xB2FA4065A3B1C62DULL, 0xD49656C7F5FFF4FCULL, 
            0x9AFFF39873D04F76ULL, 0x3152F27D1352826EULL, 0x99A86C3E35A65D7AULL, 0x7331E5362625880CULL, 
            0xFB456ACD57AEA0B2ULL, 0x6989162BF316F9F9ULL, 0x9495C1BF91BB971FULL, 0xC47A1B17AEAC216DULL, 
            0xCAD041DE8FCF6E85ULL, 0x607042BEF003CE6AULL, 0x41784F35641F1D4CULL, 0xBD0A6170639634E8ULL
        }
    },
    {
        {
            0x11F96DD70F91EFFCULL, 0xCE864FDD5D781547ULL, 0x3B92F41C6910D3D7ULL, 0xF29EFBB66BD88F1EULL, 
            0x0A94F5C43E57F646ULL, 0xA4818A500E7E6B80ULL, 0x1C542D82A262EF32ULL, 0xC791D6E3C251D1D1ULL, 
            0x49C1F4655E90DADEULL, 0x9E43894FE9BE1966ULL, 0x7D9D3500C5585A7DULL, 0xCDD23DB684D83E03ULL, 
            0x5C164D1DE54364BAULL, 0x95FCCC8258625BB8ULL, 0xCD16560D08C48305ULL, 0x612C7C7BD423572CULL, 
            0x9711450E66CA6B9EULL, 0xF3F4484A4E90CA65ULL, 0x89BD211815273E3CULL, 0xA523C4FE03D2A621ULL, 
            0x46828C369803A175ULL, 0xD3CA91C640B8CC4BULL, 0x270C727A845DD7A7ULL, 0x3B429B0A2577093CULL, 
            0xC8B80E41388E9734ULL, 0xB6985F6F8FA8ECCAULL, 0xDFE08C34175CB0F1ULL, 0xA01AA326EC90B835ULL, 
            0x053D7525911A0976ULL, 0xC71D47573480AB3AULL, 0x918224EEA6BF04A3ULL, 0x50AD306DC4FE37AEULL
        },
        {
            0x7813335CA31F13E1ULL, 0x57E161DD7B2904CDULL, 0xF2227339BD4A4BECULL, 0x7A2008C234A28110ULL, 
            0xF75E0C87B6722027ULL, 0x94B3B7D116699F8DULL, 0x133DD0238B53D312ULL, 0xA5401F482CF04EEFULL, 
            0xF8CC5C68B6B2CBA2ULL, 0x833E96223979F17AULL, 0xEAB78AD28813DE60ULL, 0xDD325A989001B352ULL, 
            0x01035A334BF80348ULL, 0x22E55D84FCF92211ULL, 0xCEB7A0F9D8AF0CE9ULL, 0x8B519DE37DE0BF2CULL, 
            0xF68C441A604408C5ULL, 0xCDF98581BBD8223EULL, 0xF764F9CB5AFF8D7CULL, 0x307611A17BB2D470ULL, 
            0xFA4F5D35824A1926ULL, 0x48FEF9847179C496ULL, 0x797A652697BCBE06ULL, 0xAC64B6DC77EFAB5FULL, 
            0x835C37E328127F3AULL, 0xB991C6BE69C41032ULL, 0xE8F4AD378A5B1A50ULL, 0x9B13104982B3DCAAULL, 
            0x875BDC0381D6ADE4ULL, 0x5913607E557D1DC2ULL, 0x1E1087475AF5D2A1ULL, 0xEA1C4FEDCD6360E0ULL
        },
        {
            0x8A9FC22F0B18C6B0ULL, 0x035DEE8B4DC8BC59ULL, 0xDF10017CB4EEC93EULL, 0xD8B680012A26F715ULL, 
            0x160058F867D03CBCULL, 0xD2A6F0859DB5F07CULL, 0xD3C1049FA80445DBULL, 0x8C1EF0E8F98BB447ULL, 
            0x820C96DEE152D15AULL, 0x55C5F02968A37A86ULL, 0xCB0C7FE56CA2BF68ULL, 0x4F9BE4A10D15EC34ULL, 
            0x140CB6EC6B53967CULL, 0x05C1A19160B4DBCBULL, 0x4B6F62F14A322C14ULL, 0x68FF0D02AA6A5EF2ULL, 
            0xE3966209CCDF6799ULL, 0x0CA35800BA7A3F83ULL, 0x375CAA68463D53D8ULL, 0xC670803C9E7C13A2ULL, 
            0x7D066CD99A85C4FAULL, 0x6FFBAFD892B12980ULL, 0xD97F67B585DF95A9ULL, 0x51E3371453E8D0DCULL, 
            0xAE7D36DCEF688692ULL, 0xC9CA9ABBB6CB5B60ULL, 0x4BA79C176239311DULL, 0xE9F63651393BDFDBULL, 
            0x252FFDEA68B00B98ULL, 0xB46652684FB4CD0FULL, 0xE08A672A9223E6AEULL, 0x0851646C5713E8C8ULL
        },
        {
            0x0523C7CDD5F5FA96ULL, 0x1B6AE895B4914592ULL, 0x3AD57686CED57E2FULL, 0x3F00F63507FB9B93ULL, 
            0xFDE7B44E1F6B1457ULL, 0xC87EF8C39C6B98F0ULL, 0xA85EE38AD08001EAULL, 0x23DE49E393404BE9ULL, 
            0x62A76E5A2C83A2F9ULL, 0x3D23F65AA454EA70ULL, 0x52858D91DA2CF905ULL, 0x4F4D182F96CBBACCULL, 
            0xD5B36CDFCE67D01AULL, 0xA96E2641A5BD9D8AULL, 0xEDA0EE6DD237C2BBULL, 0x97ED548ACC1940C7ULL, 
            0x69CC55CD2C3940BCULL, 0x8C49E15BD892E254ULL, 0xF6AB46E39AFA36D3ULL, 0x6179145B84339086ULL, 
            0xB7EA4E2875971ED3ULL, 0x9E98D22289D9BCA9ULL, 0x4D4E236466DFCB7BULL, 0x4717EFF7764639C2ULL, 
            0x4874795BE207668FULL, 0x3F0D593345259AF4ULL, 0xEA03735B124D242DULL, 0x4B3FF1EC3FD99617ULL, 
            0xBA890F301E77216DULL, 0x62B368AFB1362EEDULL, 0x842DB9F0BFFF5E17ULL, 0xB21AE7A7BCB49781ULL
        },
        {
            0x63414C97F3A9DDBEULL, 0x1C2531E948D9643EULL, 0x38D75AC478413F5CULL, 0x5C4EEE21A4878B2AULL, 
            0x1EA904B569D32F57ULL, 0xCFFF62677299AAF7ULL, 0xF47485C310D63E82ULL, 0x215B8E68BDB05832ULL, 
            0x8339394A690E93B4ULL, 0x337D5130152B41D3ULL, 0xA23287752E753684ULL, 0x46BB499A358A925DULL, 
            0x53E4931B06DDC1DBULL, 0x8F8DF96EAF42E824ULL, 0x876DC97D473C3BBEULL, 0x6E1559C4851D1064ULL, 
            0x5F47DD1A48E7A561ULL, 0x1B0E5E8E010DA217ULL, 0xA972B2F56761C4FAULL, 0xC4B35A782C5C8E35ULL, 
            0x5F63BF39F1B6E16AULL, 0x575252F4317D0AA5ULL, 0x9189950262D00258ULL, 0xEDF9A512FEB34E01ULL, 
            0x2533638665C74129ULL, 0x05792F956853ED39ULL, 0x9E854DE1087C7265ULL, 0x52A4B2B8BB914197ULL, 
            0xE1DAA3A56B4CD14FULL, 0x90B157F1F41C4FE4ULL, 0x1A7B35111EB1A401ULL, 0x2731F0C9D3B88682ULL
        },
        {
            0x622407D800327640ULL, 0x14E52E1ECFBA0B4BULL, 0x9BA707D1BFC60EE0ULL, 0x551A7C2604AC59C8ULL, 
            0x5F835E4F92C33349ULL, 0xB39BDEEAE418BEF9ULL, 0xF45B96CD4A677E3FULL, 0xDEDA1EA3596A2F62ULL, 
            0xD92C72821A8977E8ULL, 0x1EBEC87093B78B80ULL, 0xFDCD2447950D8243ULL, 0xA003385B6D61DC8DULL, 
            0xAFBCACD5469D9253ULL, 0x5F61D731955EF499ULL, 0x79188F93A672AE21ULL, 0x71FC40925032C39DULL, 
            0x30DDF64B03EDABECULL, 0x2D6B514579D625B7ULL, 0x13D4F46DCA3EA78EULL, 0x6EE86469F24E3058ULL, 
            0x6079C8BF95E9AB06ULL, 0x693D0872C528BD0FULL, 0x231857DE54756F05ULL, 0x43787210BDB407B1ULL, 
            0x45E20760C595BA6DULL, 0x690593FC97B1F902ULL, 0x8D2250CB87D8C373ULL, 0xC712B082DFEA9F4DULL, 
            0xC763E07B88D1F84CULL, 0x1A0FDBF280F35959ULL, 0xDF295706B3DE2F8CULL, 0x2CDC9EA026D683CEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseHConstants = {
    0x191B9B2762DE23BEULL,
    0xCB20992F841D7107ULL,
    0xDA1C5D2F85C0EF20ULL,
    0x191B9B2762DE23BEULL,
    0xCB20992F841D7107ULL,
    0xDA1C5D2F85C0EF20ULL,
    0xE6E2F2A64456B132ULL,
    0x04EA55D6749CA3DCULL,
    0x5F,
    0xF2,
    0xBC,
    0xCD,
    0x49,
    0xAD,
    0xE7,
    0x33
};

