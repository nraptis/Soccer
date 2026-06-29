#include "TwistExpander_VolleyBall.hpp"
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

TwistExpander_VolleyBall::TwistExpander_VolleyBall()
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

void TwistExpander_VolleyBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEE13E7D8604C2CD7ULL; std::uint64_t aIngress = 0xC45B3CA645E75B1CULL; std::uint64_t aCarry = 0xE438CECD967A860BULL;

    std::uint64_t aWandererA = 0xB3411C6B4E95EC89ULL; std::uint64_t aWandererB = 0xE277AC667AAB49F4ULL; std::uint64_t aWandererC = 0xA431CDB75D0C0556ULL; std::uint64_t aWandererD = 0x92541D00C20DB329ULL;
    std::uint64_t aWandererE = 0xB28DE19904FDEFF3ULL; std::uint64_t aWandererF = 0x81C8255374559E55ULL; std::uint64_t aWandererG = 0xEFAA0CF1271A3EEEULL; std::uint64_t aWandererH = 0xEDD2EB07E362691DULL;
    std::uint64_t aWandererI = 0xB4466AC52ED214ACULL; std::uint64_t aWandererJ = 0xC6AEECECC492A81DULL; std::uint64_t aWandererK = 0xE6F6C277EA7CDBC8ULL;

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
        aPrevious = 12640968145916236035U;
        aCarry = 10242356161287141498U;
        aWandererA = 16515525786672008262U;
        aWandererB = 14147321661868924844U;
        aWandererC = 16295494111516652938U;
        aWandererD = 10133075283011844332U;
        aWandererE = 14347936887114749857U;
        aWandererF = 13756793498362084387U;
        aWandererG = 17301555832050527351U;
        aWandererH = 12876629417591195869U;
        aWandererI = 10257489403940311756U;
        aWandererJ = 18167122866976275217U;
        aWandererK = 18282593359058636693U;
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
    TwistExpander_VolleyBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_VolleyBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA42091BC494CF659ULL; std::uint64_t aIngress = 0xED9B8A1FA1111D06ULL; std::uint64_t aCarry = 0xB2AA171045F30453ULL;

    std::uint64_t aWandererA = 0x877AF8E827ED9594ULL; std::uint64_t aWandererB = 0x93458CF3C3590F6EULL; std::uint64_t aWandererC = 0xDC6C274E6E10C595ULL; std::uint64_t aWandererD = 0xEDCAF3B670925314ULL;
    std::uint64_t aWandererE = 0xC4451922B8D97321ULL; std::uint64_t aWandererF = 0xDE6982C7B90F9C27ULL; std::uint64_t aWandererG = 0xA69A717FB3DDF45FULL; std::uint64_t aWandererH = 0xA9CCCD24086FC353ULL;
    std::uint64_t aWandererI = 0xDABFE23CF6992B67ULL; std::uint64_t aWandererJ = 0xFCB5A0A1A3FE793AULL; std::uint64_t aWandererK = 0xCFAFFD9A57CDFA4FULL;

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
        aPrevious = 16499926274397356939U;
        aCarry = 16787950337558951397U;
        aWandererA = 9288372263367889709U;
        aWandererB = 10683820965065622365U;
        aWandererC = 13123433342490212028U;
        aWandererD = 9727363790950740294U;
        aWandererE = 10589627291577786327U;
        aWandererF = 13432003931012683428U;
        aWandererG = 12054463354053629973U;
        aWandererH = 10842723078346239818U;
        aWandererI = 13837619054929325464U;
        aWandererJ = 14971646603504750562U;
        aWandererK = 17401046742987803452U;
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
    TwistExpander_VolleyBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_VolleyBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEC70B696623492CDULL;
    std::uint64_t aIngress = 0xC3E0F41625895CB7ULL;
    std::uint64_t aCarry = 0x8F82E9468DF659DEULL;

    std::uint64_t aWandererA = 0xA6E08B5E61DC7811ULL;
    std::uint64_t aWandererB = 0x80FFA51557CAD4DAULL;
    std::uint64_t aWandererC = 0xE9BE07A3AF5B2290ULL;
    std::uint64_t aWandererD = 0x947F69F7B513CCE7ULL;
    std::uint64_t aWandererE = 0xA578971370AC3E8FULL;
    std::uint64_t aWandererF = 0x87421F0969BE8DBFULL;
    std::uint64_t aWandererG = 0xD9DAF2DDC94C6DF3ULL;
    std::uint64_t aWandererH = 0x87811D1865D016F5ULL;
    std::uint64_t aWandererI = 0xBDB1A3DA62313B83ULL;
    std::uint64_t aWandererJ = 0xD39B395244299121ULL;
    std::uint64_t aWandererK = 0x88ECBA1B898C27D9ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneC);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_VolleyBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_VolleyBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_VolleyBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC93D55ED553D11A2ULL; std::uint64_t aIngress = 0xDA57BD3B8F80FE4FULL; std::uint64_t aCarry = 0xD8EFC8828B3A509FULL;

    std::uint64_t aWandererA = 0xDF0BDD7694D838DAULL; std::uint64_t aWandererB = 0xE74970C8A6CD5EE2ULL; std::uint64_t aWandererC = 0xDA42D26CC9B10E47ULL; std::uint64_t aWandererD = 0x8B181239FF630132ULL;
    std::uint64_t aWandererE = 0xC24098E0694C83FAULL; std::uint64_t aWandererF = 0x8B5BF183E40FFB28ULL; std::uint64_t aWandererG = 0xE4774134B9DC9DC5ULL; std::uint64_t aWandererH = 0xD8FFCB4567C5D89FULL;
    std::uint64_t aWandererI = 0xB99A8CE71AF8A9F8ULL; std::uint64_t aWandererJ = 0x869BF6D898836436ULL; std::uint64_t aWandererK = 0x8A65B4A02251608BULL;

    // [seed]
    {
        aPrevious = 18039755645758901775U;
        aCarry = 13512325610741117861U;
        aWandererA = 9992323353719169627U;
        aWandererB = 15488797085469801688U;
        aWandererC = 17019036408847509427U;
        aWandererD = 10550257278686533088U;
        aWandererE = 17608458704779488350U;
        aWandererF = 14107049494362595209U;
        aWandererG = 14595247391762796153U;
        aWandererH = 16808822305986611498U;
        aWandererI = 10085876913939846478U;
        aWandererJ = 13066903158766180734U;
        aWandererK = 13712413546020838444U;
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
    TwistExpander_VolleyBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_VolleyBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_VolleyBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_VolleyBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_VolleyBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 0 with offsets 8070U, 4371U, 584U, 2195U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8070U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4371U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 584U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2195U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 2 with offsets 535U, 4729U, 6632U, 6605U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 535U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4729U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6632U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6605U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 2, 3 with offsets 5354U, 3547U, 7622U, 4416U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5354U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3547U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7622U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4416U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 1 with offsets 564U, 1959U, 5154U, 982U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 564U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1959U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5154U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 982U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 with offsets 727U, 1327U, 819U, 1090U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 727U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1327U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 819U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1090U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 0, 3 with offsets 473U, 1800U, 1264U, 137U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 473U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1800U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 1, 3 with offsets 265U, 1354U, 789U, 1748U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 265U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 789U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1748U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 3, 1 with offsets 1909U, 1333U, 1173U, 1122U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1909U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1333U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1122U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 61U, 235U, 778U, 1524U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 61U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 235U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 778U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1524U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_VolleyBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 2 with offsets 450U, 3075U, 2571U, 1656U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 450U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3075U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2571U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1656U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 0 with offsets 1878U, 1183U, 5227U, 2488U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1878U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1183U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5227U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2488U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 1 with offsets 7202U, 6700U, 3353U, 583U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7202U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6700U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3353U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 583U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 3 with offsets 3872U, 191U, 47U, 7704U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3872U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 191U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7704U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4678U, 591U, 374U, 3193U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4678U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 591U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 374U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3193U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1291U, 832U, 694U, 785U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1291U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 832U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 694U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 785U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1368U, 1302U, 1120U, 274U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1368U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1302U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1120U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 274U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1555U, 969U, 969U, 445U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 969U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 969U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 445U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 419U, 299U, 1169U, 1669U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 419U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 299U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1169U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 [0..<W_KEY]
        // offsets: 1330U, 553U, 195U, 1506U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 553U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1506U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseASalts = {
    {
        {
            0x98BBB7A8E6D1F2A9ULL, 0xE7130F9BCF72E93EULL, 0x4A8F3C96249E2FECULL, 0x5498E1EAC3B1CAD8ULL, 
            0xBA31DD2A9B742AE8ULL, 0xA40C34F974EF1A49ULL, 0x41CB829E2EE4F412ULL, 0xA30351E922713BFFULL, 
            0x08BDDAAA6DE568AFULL, 0xF14B9E197296614BULL, 0x0548D02C81F01975ULL, 0xD5C20398AC14B23FULL, 
            0x7D020540D9D0E7BCULL, 0xB1460EFB0B066D56ULL, 0x08DC355FD4DFB04AULL, 0xEF2909A127AEC571ULL, 
            0xF3165FA5CDB4ADECULL, 0x91560E09E30FBE87ULL, 0x32C0F08BB28111FDULL, 0x98E95894765E4A1EULL, 
            0x515494AFCFC98FEEULL, 0xBCDF816FE31AAF89ULL, 0x2D5702E32B371375ULL, 0x2F8AA01FAC08017DULL, 
            0x5A605AF07C50A628ULL, 0x5632E6F816D7B817ULL, 0x9797D55940287AB4ULL, 0xC687FA0A9633AC50ULL, 
            0xCE258A5AE997327EULL, 0x196D89EF44507CB1ULL, 0xF1A527D760AA644DULL, 0x0CBDBB7581BB705AULL
        },
        {
            0x5F2F50C04B29FE89ULL, 0x1493ABA4A03AE7CCULL, 0xDB34E19E551EDC5BULL, 0x49919647AA2B370BULL, 
            0x301C469327461437ULL, 0x7AEC78FAD038F959ULL, 0x5CCBE279E1BB484DULL, 0x60E799938BC2E132ULL, 
            0x57A87FF0BFE0D2DBULL, 0x39F54978583F0D84ULL, 0xA89AB11A1198A278ULL, 0x1A091DBCBE2073D8ULL, 
            0x9A1FF71377E49505ULL, 0xC9209EA2A523D04BULL, 0x931576EC81A1DA33ULL, 0xAFA5B80E47B64878ULL, 
            0xC2FBE6DB7445CF64ULL, 0x33AEACC746A519A6ULL, 0x37E20E86CD028C1CULL, 0x265A5D6BE832AA39ULL, 
            0x56DD9B9C88E117B2ULL, 0xE8150CE27B6C44B2ULL, 0xD0E1E3DD4AEF5515ULL, 0xA36F1A49E98E2360ULL, 
            0x8A55E9771BEA6E72ULL, 0x7428584C9B12A19CULL, 0x093ACD928976C504ULL, 0x5119683AF2765CE6ULL, 
            0x8F2898E7BBD8AF28ULL, 0x2AAC64C38F13E537ULL, 0x4D7689F06DB027FFULL, 0xBEA27B56F87B3C7BULL
        },
        {
            0x6FE74E0491AE43F3ULL, 0x8BCE8D0C67EB96A8ULL, 0x27A7F93740DCAD5AULL, 0x44A33A2C9A9A77BBULL, 
            0xAA8DE26039FDEBB5ULL, 0xE934FA0B1307DD28ULL, 0xAE8BBB35634D23A7ULL, 0x9BEB8420080D3816ULL, 
            0x82ADAF7A29626F23ULL, 0x5BE7414A39B9005FULL, 0x41C857EA05B5CF68ULL, 0xA5EC13243C40064AULL, 
            0x49437AE9E816E58FULL, 0xD5746CF7C55727AAULL, 0x9759AAB4472D5EB5ULL, 0xDB196C75CC0526F4ULL, 
            0x6112BAFB51819D5FULL, 0xDD9002928C5C6B81ULL, 0x9D206D624CEF8C88ULL, 0xB17B7566B6945097ULL, 
            0x39C862670AA10153ULL, 0x3F84C12844C6283CULL, 0xEE079147D4A9E753ULL, 0xA0ECAE41643690E2ULL, 
            0x17D33A344317C731ULL, 0xEC6DC1E97B2E65D9ULL, 0x7B544B761D9D7C8BULL, 0x9233ED6E1AFD45D4ULL, 
            0x52A7ECE869BE7A47ULL, 0x28F42604C5F4CD0BULL, 0x9272BBE5D381DBCBULL, 0x51D0E25E978A404FULL
        },
        {
            0xD4FA071F91261957ULL, 0x182608E59C191D54ULL, 0xE7A7AA5B2DD4D4BAULL, 0x310740A2CBE6459FULL, 
            0x7B0BC220B5CD48CEULL, 0x6CDDC84BAE57EED4ULL, 0x1B04B1535E1A129CULL, 0x67A576C741D31DE0ULL, 
            0xB345CD75B0CCAD7EULL, 0x3379171D31A0BA21ULL, 0x41CA5030BC0C55C2ULL, 0x21E903FBAB6BF523ULL, 
            0xBE1D5027EA7D8131ULL, 0x27F6E69D4A750442ULL, 0xFF3379B19566F01FULL, 0xE0C260F9560B36F0ULL, 
            0xCD0588DF217383B5ULL, 0x29F3E441001EF2B3ULL, 0x0536EBC42D3E5718ULL, 0x0B6B3A9F4552EBD8ULL, 
            0x2FAA2309D80AED76ULL, 0x1652E83E947517F4ULL, 0x11E90BF5395862B5ULL, 0x460619364DD91BA1ULL, 
            0x5F01E9A405B998DBULL, 0x50839FA837D7066CULL, 0x29DF3FF20B6593A5ULL, 0x6A682CF6CE62F8DAULL, 
            0x93110DBE9E8916ABULL, 0x3DC53B039292BACAULL, 0x19ADB2DF662734A5ULL, 0x2DAA463500D63A27ULL
        },
        {
            0x610F062EE8ABB182ULL, 0xDA00795EEB7FC4A8ULL, 0xFB5E86E87F6215CDULL, 0xAA8EC385A6F67DD4ULL, 
            0x800F6340B6705322ULL, 0x53944AC27BF113D2ULL, 0x23B719E987FDCFF4ULL, 0x3705E5EE60C44FFEULL, 
            0x20709F09D25003BCULL, 0x19200F29F690D194ULL, 0x1571DD82838486BCULL, 0x4A61357584164ABBULL, 
            0x49AF6D1E1A78C7C1ULL, 0x883B4EFADB3E4FECULL, 0x7BF4E02BEDD12731ULL, 0xFEC6EED6EFDB6478ULL, 
            0xB7FF81C68E615B1BULL, 0x933AF93CA941A630ULL, 0xF15CBFF8CC0A5386ULL, 0xEC33CC6CD1BBB24FULL, 
            0xBBFFA1D04D8C6B39ULL, 0xE8410BA133A9609DULL, 0x2F842B33DE1834DEULL, 0x0D70153424A4098FULL, 
            0x01C3E0C0C1C3A9E3ULL, 0x3E7E806C0ADC0464ULL, 0xB866E5E0B7699515ULL, 0x979684EB1C4796D6ULL, 
            0x02679068C783AB5FULL, 0x482DF32A260FBC2DULL, 0xDB5844D02A40C2BBULL, 0x9A30C9355270E240ULL
        },
        {
            0x31FF89E644E1B2FFULL, 0x1330F7779EA7E1A2ULL, 0x2A2834A42B6E8B6AULL, 0xBB8496729B24C6F3ULL, 
            0xCDDA7534C286BA92ULL, 0xDB6349E5AC61C41AULL, 0x9E94C5979941AA2AULL, 0x3CC7FD18809C3569ULL, 
            0x399C13C6622B059AULL, 0x20677DB02DE584FDULL, 0x4FE4C6478694941CULL, 0x30FEBB03F0BDDC66ULL, 
            0xC8B1ED9F3B306B11ULL, 0x51C3FC34FE35C133ULL, 0xC73D5984FA674422ULL, 0x8C1CB70F1A4740BDULL, 
            0xF6515AB3744902AFULL, 0xBB7850EFE0D67B8FULL, 0x9920DB9E8E9235A5ULL, 0xDEE7B20FBAF5EBDCULL, 
            0xFF73DF172B2047DEULL, 0xECAA1524B270B298ULL, 0xE2C45ED83E38A8C3ULL, 0xF8CE06DC1F05AB6FULL, 
            0xCF454F71DBA73BFFULL, 0xB8064A6A605307DCULL, 0x6668CB2B62CA9B0FULL, 0xE369D94B5F06E779ULL, 
            0xC6CBEEE78E733C04ULL, 0xA04B255077ABD47FULL, 0xB6DA0D509A1A08D3ULL, 0x6252550C6792EA57ULL
        }
    },
    {
        {
            0x50A742D8B71864C7ULL, 0xB398F89FC32BE8BAULL, 0xF489B0A707827798ULL, 0x8B595C1A804A99CDULL, 
            0xBFA46E0E98C42DD7ULL, 0x72FA4D07353DAC3FULL, 0x2217AB59A4724C95ULL, 0x4446C839CC2E0876ULL, 
            0x97D83949E51937CBULL, 0x990D8033AAC669C0ULL, 0xB7ADFB8BDEC800ECULL, 0xEAFC3ED4458DB48BULL, 
            0x501765E5D54F76D1ULL, 0x5FA24B89219089CFULL, 0xEF1C60F4B8BD8FD2ULL, 0xE3831122C4DD3011ULL, 
            0xFCB795CBE8A8C6CEULL, 0xF3ECA8EC8A6F7B1BULL, 0xB534845BE287767BULL, 0xDC3FB546D6812999ULL, 
            0xFF8531B367C3B866ULL, 0x25E1F07D2B149B14ULL, 0xB2CE27C355D98917ULL, 0x85A368D0083459C7ULL, 
            0x8ABD9B841E1248ECULL, 0x5A333032373EF3B2ULL, 0x24B59ADD55F6F96DULL, 0xC4EB521D0CC1BA8BULL, 
            0x6E54D0E646A998B6ULL, 0xFE304EC7E1DE2523ULL, 0xC6AC5CB53967FF9DULL, 0x8704222E1323464DULL
        },
        {
            0x0A4FE00D0CE6206BULL, 0xDE043A12C0BA9E5EULL, 0xCD9EAD2A54242AAFULL, 0xE1A0B951D303C99BULL, 
            0x56648AD9903194ECULL, 0xC59C2A84CBBDC3FFULL, 0xF477A21590602657ULL, 0x1151BB24F37DD604ULL, 
            0x1D5E4B4A8A684C07ULL, 0xBB944909C397132CULL, 0x1BA53CC9996780C4ULL, 0x32B8AFDB3BAD90D4ULL, 
            0xB370ABA0EF7CA7F5ULL, 0x7EEC8ED28972E67BULL, 0x279744A061FC61C5ULL, 0x73A7C57CD0D92FC0ULL, 
            0x33E087E063E8FC1DULL, 0xF1724F49B17C8D70ULL, 0x72127FD9F4C97413ULL, 0xFF8BD1138947436EULL, 
            0x8680B02B2D373630ULL, 0x43E6FE0249DFC941ULL, 0x6BBD999ED5224967ULL, 0xCFABA1A6911D049AULL, 
            0xCB7F67CEDE15947BULL, 0x284BAC99B8232A64ULL, 0xD05471969ED3F7D8ULL, 0x793FC91A8D8D09FFULL, 
            0xBB9515F4BFBEA304ULL, 0xF462E01F97B99D28ULL, 0x2DC6B68606F5B53BULL, 0x73351DA485CB4431ULL
        },
        {
            0x8798EDBC1749FE98ULL, 0xE73637ADED5CFF46ULL, 0xF428FD3B93E4DDD0ULL, 0x5CEFD220E60A7BCAULL, 
            0xA99ADB809D2341B3ULL, 0x9EC07B73D36BB903ULL, 0x6050C483905963BAULL, 0x9824A88459609EF8ULL, 
            0x6DCEF2854F1B87C4ULL, 0x8619346A744E2285ULL, 0x983F4995D4AC85ECULL, 0x39173BC1ED425732ULL, 
            0xFA39744E436F32C0ULL, 0x61A75D8B9973CC2CULL, 0x997D2CB7086E3105ULL, 0x06DA9353858C7CAAULL, 
            0x8D5DF4438CABCF9AULL, 0x576F0BCA6B91C82DULL, 0x5BBD59C6C28AD911ULL, 0x5D7E85D4996C6A6AULL, 
            0x1242088C84F41D70ULL, 0x9C036C72AF3E5BCAULL, 0x3768C1571D3BBBCFULL, 0x63DA068F42E0148FULL, 
            0xC23A1E6A88D7E0F9ULL, 0xBD423347B86CC6DCULL, 0x81FFF1CA069DBB58ULL, 0x4D02CEC332F5C3E8ULL, 
            0x8C191BE6C5ED0955ULL, 0xE4939441BBF537B6ULL, 0xCAF5B92EF994E703ULL, 0x229A4FE809EEF245ULL
        },
        {
            0x314EAC2E217EB6C6ULL, 0x3EBC61C663347207ULL, 0x13A465E0533FE84CULL, 0xF418EAC44115F25EULL, 
            0x2139FD62CBD9DF1FULL, 0x6C8ABCA84676FF50ULL, 0x16EC8E51C0245B55ULL, 0x3E5F4B4487325A72ULL, 
            0xA611D550F9B7ECCCULL, 0x2973B71AC1863744ULL, 0x64F4AF8FA34AA070ULL, 0xC548289099560929ULL, 
            0x2210822977AE2374ULL, 0xB4B8755A440CD74BULL, 0xE7F87843C8EFCA6AULL, 0x9B00FB1E3D77CC71ULL, 
            0x77823539C32B54C1ULL, 0x7E98A796EF0B7624ULL, 0x7FB7F70298A048D0ULL, 0xEC968F8BA7D5717EULL, 
            0x78B4C7FE670ADD4CULL, 0x64679D661B5B0689ULL, 0x470410ADF4C18470ULL, 0x26F862DA690136CAULL, 
            0xBF7B7576D1988C54ULL, 0x7DC5E57889A5EB47ULL, 0x96E4EAC4A3F7008CULL, 0xECD6480D13801320ULL, 
            0x041B05B38F49B45BULL, 0xE358AD7DEF116B46ULL, 0x9CBE1463BB23C289ULL, 0x17E7F6E2F5B53368ULL
        },
        {
            0xAE6822032EF6AB1BULL, 0x62EC9C61C3D516E8ULL, 0xF04D802AA11EF77CULL, 0xDC5CE22727AC8525ULL, 
            0xCBE530222B08E437ULL, 0x3F1BFC3C63FC2057ULL, 0x7C52B5083ED07E30ULL, 0xA30BBAEB5DBCF851ULL, 
            0x91A5CD335117E2D5ULL, 0x17D7F982F2ABAECAULL, 0x86B83B0D3F8A3D73ULL, 0x984A85D81CFE2231ULL, 
            0xF167DD9CD95CC93AULL, 0x7E521536BE9AE849ULL, 0xBAF5E6A9DB6A9940ULL, 0x9FCB11A55DD5F02BULL, 
            0x3095A4213C7A1651ULL, 0x9519EA95CF3F0781ULL, 0x01D8255797B6C970ULL, 0xE0E91B675000A9C2ULL, 
            0x5BEA156B13FF7C48ULL, 0x66413F049B95C4EDULL, 0x9E1A6F68245F2DDEULL, 0xF0F08EF2B74E7A79ULL, 
            0x85BDA157D698754EULL, 0x3BAF0CAA0EF45B70ULL, 0x734F3BF81865545FULL, 0x8BA7674A6367B3E5ULL, 
            0x0D4805D6D3558CC4ULL, 0xFB19B4DD3970EABDULL, 0x250E6691443E365BULL, 0x898DDAEF45ACD513ULL
        },
        {
            0x560F1C52530E7C83ULL, 0x048E9B4E66B49DD1ULL, 0x3BB23C7D6B525141ULL, 0x15BE6FCE064BF15FULL, 
            0x38098D9A212AA668ULL, 0xDA99AD0B93F2947DULL, 0x5B763560784C2DC4ULL, 0xEC447A4021902CE3ULL, 
            0x76C39560E4ECE418ULL, 0x5166F60B9F7FDF45ULL, 0xA09877609933C77CULL, 0xA05E0983FAB390ADULL, 
            0x64E3ABB7C797160CULL, 0x4C1F27970D9AFF51ULL, 0x6F7013FEA1E4ED02ULL, 0x5C83DA822940B688ULL, 
            0x7D0817B8A2B1179EULL, 0x4CB1B825CE66B3F5ULL, 0x95EC095F56428E4EULL, 0xFC1BB1B3A096CD8EULL, 
            0x1E1C73D411CDD92AULL, 0x7DB4B64ECF14A3E9ULL, 0x92A5596E39DED908ULL, 0x974EB27214C4F210ULL, 
            0x3B3A808E377E2A24ULL, 0x755A7D437F590281ULL, 0x38E3453939D0FE95ULL, 0x1747ED4530BF0808ULL, 
            0xB5FBD6C058A6D2D1ULL, 0x7FB6E9BDC766858CULL, 0x2AD014D50DA85BE3ULL, 0xA05F75FBECB83F26ULL
        }
    },
    {
        {
            0x45ED9EEEC618CCC1ULL, 0x2D271CA57825E87DULL, 0x4FBDEF8F1DCD2E22ULL, 0x10B317E301828699ULL, 
            0x776F7981E744DFAFULL, 0x3E735629E6499846ULL, 0xFAA42A9F76A6866DULL, 0x15C589562DA19C82ULL, 
            0x47DA300566F87903ULL, 0x2425E468B29AEDA3ULL, 0x8966E5735E5180B9ULL, 0x7CBA4CD21C0F00BFULL, 
            0xB1F4242B422C2EBDULL, 0x26AD6CFC8E695C26ULL, 0x441629CEC0E02DAEULL, 0x7B7B593971DD7DF3ULL, 
            0x62A26C113CABCCB8ULL, 0x1F13BD113A55E683ULL, 0x7D101F76FD426B31ULL, 0x32AFEA4A559ED351ULL, 
            0xFF43552842532750ULL, 0xC8221F5190F42D24ULL, 0x41917AB1A3F67E50ULL, 0x1B9F6D759ED421D0ULL, 
            0x120CB529371A6656ULL, 0x5A4E09E7C7D26B8AULL, 0xFE9B46A5ADCC0CEAULL, 0xDBA0C2C0F2CBC4DCULL, 
            0x46EEE9681E68A95DULL, 0x27B5588DC1B2ACC7ULL, 0xA48A23A6F2AB9CE4ULL, 0x0E1EB0A85FAC2F27ULL
        },
        {
            0x3E71510534260514ULL, 0x5CB39C658A812FE1ULL, 0xBA61D79C665DE82DULL, 0x37811D8AA287C78FULL, 
            0xCE5058366B3A9A2BULL, 0xFB35B41BE0F3A94CULL, 0x93960D930D36DEFCULL, 0x725F30FBF8D8ED6AULL, 
            0xE5ACCF7724A6C6FFULL, 0xC88F405E6AD9D75BULL, 0xFF33BF092AEAE133ULL, 0x8A6341339193BAF8ULL, 
            0xCB4026536DEA5481ULL, 0x0819E6E2E3C1163DULL, 0xC526B0EB9828D6E3ULL, 0xB94B16773493F784ULL, 
            0x1029EAFCEACF22EEULL, 0xB6FC14CD4D5BD4F7ULL, 0x61978E89A93655ABULL, 0xA7EB0B01C2A22AECULL, 
            0x1DA3CFC646370190ULL, 0x6041F505D47C1CDDULL, 0xF209A18B31E4EF16ULL, 0xF8C2DB70215B539DULL, 
            0x3E17B62F1984C107ULL, 0xB6F6CA5366272E7EULL, 0xFF0ADD68FA05908DULL, 0xB7A6920C3202B68AULL, 
            0x917AA961E4350583ULL, 0x5F30945835CFDB10ULL, 0xC74FBD8E911AB02EULL, 0xF39E6DB45DEA466BULL
        },
        {
            0xFF02541606DF9880ULL, 0x767BE3F68CD09C0FULL, 0x81D8057FEE4F4794ULL, 0x4756095FC8329233ULL, 
            0x559A42CC99C53DF8ULL, 0x9EC05BCAF9373F6EULL, 0x97D88594629BD24DULL, 0x77F88EB0368B073CULL, 
            0xAB00AFC6E26603A8ULL, 0xF97D9995A35ED5ADULL, 0x1E1F999D61F427C4ULL, 0x2C3E5D53FE428667ULL, 
            0x810C768B41D8F294ULL, 0x6BB074568C9B3FFAULL, 0xE7871015070565C0ULL, 0x760BA4B92DCC8B16ULL, 
            0x1386E8880BE6FBA2ULL, 0x4F850BA1DE319E01ULL, 0xDD9D60129DDE2A1FULL, 0x4466D0F407ECFB9FULL, 
            0x3F45151A9F00E178ULL, 0xE8AF1AE5C3848DC0ULL, 0xC7B02C59B8D2C0AFULL, 0x6EEDFECDC4A8FA0AULL, 
            0xC8674D7758A7B65CULL, 0x77D5FD797A27BAF2ULL, 0xF6C0776055EE3D2DULL, 0xCDED63A0F2CDDDFBULL, 
            0x9FE355B7FCED9FA9ULL, 0xD3E4716DC28B02B6ULL, 0xE8C54AED3E77413FULL, 0xB04FE25C5309FFF4ULL
        },
        {
            0xE861082325A11715ULL, 0x23BED3953F32BA2CULL, 0x9AC21B22D3DD6BC3ULL, 0xA824F01C7B780E84ULL, 
            0xF508BAA4669D6CE9ULL, 0x3003BA5110FF7C3CULL, 0xC95B9F9D46435661ULL, 0x95DF6C0DE3FEE5B1ULL, 
            0xF6515CB6D30ACD95ULL, 0x0F0FC87AA0CC8C11ULL, 0xAD15B6FF94112F14ULL, 0x4796DF58C66400E8ULL, 
            0x53F59F1F8EDA706AULL, 0x36DF84A1F02200EAULL, 0xF001233EF2CE2A60ULL, 0xD4F7BB601B866B05ULL, 
            0x6E6BDD74603463C8ULL, 0xC3FD8B161F62CAA5ULL, 0xED6173EEABD1BA9DULL, 0x42E0891461D31B62ULL, 
            0x13DCDFAE2C8FE75BULL, 0x12BBBF7B32232294ULL, 0xFF19E5B6696BB7D3ULL, 0x71ACA244667E5EACULL, 
            0x0AF035676BB1F561ULL, 0x8DC7E69770523E9CULL, 0xDE0EA65E474F3822ULL, 0x30C3F17031D53AEBULL, 
            0x45A3D6E587D2FBACULL, 0x0E1DB18635AAD002ULL, 0xBEC4558E41A007EBULL, 0xB36EA00EE54C1C9DULL
        },
        {
            0x4644B1DB5D1EF9B9ULL, 0x23BF2472E6F5FB2DULL, 0xBEE1588D252A6D77ULL, 0x25916C9DA91DACC0ULL, 
            0xAD8520DBD80914E5ULL, 0xB42E19D3D2DAE695ULL, 0xBB5A5BB2AB0E1FDEULL, 0xFC3DE4C7E4889057ULL, 
            0x2F1BE71C65E57FC9ULL, 0xE809AA31E07760EEULL, 0xDE0852341B412731ULL, 0x21C43DBC7FB19300ULL, 
            0xD1CA576FA4EBBBF3ULL, 0xF063458A5F287E15ULL, 0x0632372B2C42584CULL, 0xB112E77A0F9B6BD7ULL, 
            0x032959558ADC227BULL, 0x97DA2FEEAA98CB0EULL, 0x6C4C729D2B5AAD56ULL, 0x13B474E8CD349097ULL, 
            0xB679E6CC85AA54ABULL, 0xA6C9CA4925159CF5ULL, 0xF559B5E3399E49D4ULL, 0xB40FB1349AD71DB1ULL, 
            0xF2299A6FD8C93517ULL, 0x889824C6C58B9753ULL, 0xB612A759330D1885ULL, 0x4F12AFD2D9522258ULL, 
            0xD850D0B4A64695CFULL, 0x4A37E827538CC4C9ULL, 0x78601ADCE73A131DULL, 0xC0FCFD18F20BAFCFULL
        },
        {
            0x34A760D2F794E0C3ULL, 0x99C3D4081C65F07AULL, 0xFA289A90A61EFD47ULL, 0x4C95EB3A5AD1ADD8ULL, 
            0x2F648A77581D0E6BULL, 0xB29AEFE36B7E8ECFULL, 0x777C6F2B3ECCF4D2ULL, 0x44579EEDA0B9C976ULL, 
            0xE0097943867FDB64ULL, 0x3B32A410461B7D75ULL, 0xCC2C7880748C65F2ULL, 0x184267FD1CB34FE5ULL, 
            0x33A2E0250FF9141BULL, 0xF92EC5F8C22B2460ULL, 0xEB19ED88FD7AC22FULL, 0x7B15FFA5330897FAULL, 
            0xDB802FF1AC3F0E64ULL, 0x4AEC87E38285A16CULL, 0xDC678CE4638BE4A0ULL, 0x059424522AC991A5ULL, 
            0x7701CA1BC0F4001EULL, 0x67C241A058D1D2B5ULL, 0x5A1179CCECF5C064ULL, 0xEE03D4AA844D0B88ULL, 
            0xBFCC5FBF09ECB6A6ULL, 0x29D71FB0A31A18C5ULL, 0xAB4D2250D5FBA65EULL, 0xF8BBBC6AAC9469CAULL, 
            0x0657AC1C39CD6535ULL, 0x7808280FF6B4F20FULL, 0x6946228811CFC837ULL, 0x6358E56B7CF2394DULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseAConstants = {
    0xC676848CC15ACAD6ULL,
    0x90B260BF82DEAA2BULL,
    0xFC281B2BC05CC3F5ULL,
    0xC676848CC15ACAD6ULL,
    0x90B260BF82DEAA2BULL,
    0xFC281B2BC05CC3F5ULL,
    0x129D68C896A52CD7ULL,
    0xF089F493D0ACC8F9ULL,
    0xF9,
    0xE3,
    0x65,
    0xFD,
    0x56,
    0xB8,
    0xEC,
    0x46
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseBSalts = {
    {
        {
            0xD6B3085CDE5FD4F2ULL, 0xEFCB0DF714640F22ULL, 0xDCFCCE2E7728F90AULL, 0x2D4C6EFBF3E91503ULL, 
            0xE0ADDEFDEC08BB10ULL, 0xC13E3480529BE169ULL, 0x9EB1D768C8B3E511ULL, 0x8F08E3045B1793F6ULL, 
            0xE46189D1DAB4AD27ULL, 0xB6D7349AB37303CBULL, 0x8A253434065CCF0FULL, 0x390A784814513B2DULL, 
            0x932E08FC82A7C4EBULL, 0x2E907179F9DBF64FULL, 0xB3CFDD7B7A5B48F0ULL, 0xC090E75AC6CCBBBDULL, 
            0xBBB10EB91DFB310CULL, 0xC31489E3D31B71FDULL, 0x4BD3351A6BBC44BEULL, 0x1758F23D20F7E908ULL, 
            0x34932C6C36C27AA6ULL, 0xDDB9A4905B2666A3ULL, 0x85AA37F767D2D0E9ULL, 0x273F7EC02456E5C0ULL, 
            0x2B482BA08B41FE2EULL, 0x9A5F6DE36BB5F9C5ULL, 0x74495232B3BDD3E9ULL, 0x88B567A87503EF49ULL, 
            0xA1CE981342D191C5ULL, 0x165FD24975A1DF36ULL, 0x3E833320CBE2A9B2ULL, 0x6F0B70EF9C557EA2ULL
        },
        {
            0x97EBEAE22051A9C1ULL, 0x64275E143A167252ULL, 0xE4D8D6741446398EULL, 0x1B10E38EC2521D50ULL, 
            0x553797E71C51FD05ULL, 0xF91C340A8CD41354ULL, 0xCB0F021C8B8B8842ULL, 0x3F2B1340F723AA5BULL, 
            0xD79EAD62C1B78828ULL, 0xA33840E31FEA37A6ULL, 0x3FC8A671F1F2AFAFULL, 0xA2A178622542CB91ULL, 
            0x62DFE38CA3F603CDULL, 0xEADA623364A158CCULL, 0x33FF42818464B44DULL, 0x83DA571CCE11C5EFULL, 
            0x199D70227EA8DB08ULL, 0xFF649CB4CD008C53ULL, 0x13183257D058E74BULL, 0xCE227931F95E063BULL, 
            0x8AEF411C01282324ULL, 0xEC73D2C290FCF9E8ULL, 0x73A9ED56613A2C5DULL, 0x94214CFA20FE0E06ULL, 
            0x09F12F1A35162C48ULL, 0x09320E202A21E6FEULL, 0x054194B4C3989192ULL, 0xBAC55E67CEA7D940ULL, 
            0xFCE58183E43757DBULL, 0x2975C40B56880AACULL, 0x192B5B8E955831FEULL, 0x87A9CB0B2D449660ULL
        },
        {
            0xD8C4B4CE7A5D7806ULL, 0x7CA3C7B75541205CULL, 0xABC89C148A2D2AF7ULL, 0x24DB5DC5DA4212E1ULL, 
            0x34FBBD0D127CE6B1ULL, 0xC1670B90D89E4795ULL, 0x869C199761123762ULL, 0xB8696D88C7A611EFULL, 
            0x8DF4B2D573E8269FULL, 0x99DABA4F80ACECB7ULL, 0x23C4C88869C9AF7CULL, 0xF946A8CE9ECCBBFDULL, 
            0xC0D9C333CD78ACBAULL, 0x39FDD89DCBD31D71ULL, 0x90031681FF118385ULL, 0x620381E57E01ECC9ULL, 
            0xA06C397CFBE059BEULL, 0xE857C8B8F7EC91F3ULL, 0x7F8F7FAC3E305F7BULL, 0xF3609B1B8C1F8B92ULL, 
            0xF258F963DAE6F20BULL, 0xA072245B4FADAAAFULL, 0x84C8BF7A67865585ULL, 0xB8BEA84077D401C9ULL, 
            0x3D81B0E6F5D0E996ULL, 0x32DA4C4DA4DC12EAULL, 0x9CE1FF5624FC034FULL, 0x85B7ADC476DC06C2ULL, 
            0xC12E9DF09AA51FB5ULL, 0xC6E7177B0DC34295ULL, 0x182B76DD96A01FA5ULL, 0xAC004CDB804643B5ULL
        },
        {
            0x5E7A5A7871AF471EULL, 0xBF86F71AF69F7AD1ULL, 0xDD78BC036D4F7D52ULL, 0x3DBD0C60191419BCULL, 
            0x321E74F5A17E44ADULL, 0x8AF04E1C847255EFULL, 0x2B4FA632E75E74F4ULL, 0xFD7F1C78A33D60C5ULL, 
            0xE684D57991630BBAULL, 0x9101125767F72561ULL, 0xD9EBCA1965FAC967ULL, 0x5448C96CC04F73ADULL, 
            0xAD7D5A119EAA937FULL, 0x9D613F8BAAA07505ULL, 0x745C15E40544E1C6ULL, 0x3F13C32793FB3E1DULL, 
            0x1FDC779F8D1B198FULL, 0xD5D3EEF937B25B6FULL, 0x466BABACAA4E508AULL, 0x6640714980C1AA97ULL, 
            0x443317E6F9A2A088ULL, 0x5B4E8809129BABEFULL, 0x02797CB42B2D756AULL, 0x7F9D61CDFF7BB4C3ULL, 
            0x235AA1968FE8F5C4ULL, 0x9FF6037D6B961367ULL, 0xA76B95AE2AAD31B9ULL, 0x558B7C7F46317162ULL, 
            0x4A46D6BF5A4FC769ULL, 0x08419DC805F55F7DULL, 0x0C7E034BD0B05AB4ULL, 0x34916F827F39E4AFULL
        },
        {
            0xAEB2FB96DCB5B20FULL, 0x0A8480FE27270889ULL, 0x0543132FFC56357EULL, 0x4DDE31CACC786C17ULL, 
            0x189F77FFB56D1115ULL, 0xCFCBFD487F667B38ULL, 0x8D304EABD620B203ULL, 0xCD8C8834C18328CFULL, 
            0xF7B278C941AB601EULL, 0x49CAD8CADD0CDA2BULL, 0x203D43CE428E8D6FULL, 0xB89A480AD824BE2EULL, 
            0x5995FF86D16AF6E0ULL, 0x43D43B157ABEDE14ULL, 0xDD03BBF6539BA1B2ULL, 0xDFC46F8F49ACF775ULL, 
            0xB91223CDF5152C08ULL, 0x8A9033DC750A9CA1ULL, 0x8B52E6E60D2FF447ULL, 0xD688E6771F811093ULL, 
            0x390157239EC6EFAFULL, 0x0CA221F281FCF352ULL, 0x6B592D3ED6D24294ULL, 0x0B0720EC44021A40ULL, 
            0xCC15A0400833F3F5ULL, 0x8912574C5FE257F3ULL, 0x40925439CF0D2C52ULL, 0x71122C772D32C6ACULL, 
            0x07E2F64D702DE69BULL, 0x07FA951B06E0957CULL, 0xDE99F324E3A8538DULL, 0x44BF65E9E43B3C4FULL
        },
        {
            0x5539613B4ECC73BFULL, 0x023BEFEE085ED9E0ULL, 0xF12F78C76B4DF22FULL, 0xE0901E7957AC2225ULL, 
            0x845B7C6509B53A30ULL, 0xF2FF1375D0C7499DULL, 0x6E2745407F645C15ULL, 0xAC80A2069CBF4BDDULL, 
            0xAC6903B897D1B4A8ULL, 0x8328F883E07EC751ULL, 0x34167B4C62A01519ULL, 0x2E1F72B49F906339ULL, 
            0x78EDEAC398DD34F7ULL, 0x59525561569E83D4ULL, 0x86F4153C7AEAA4EBULL, 0xA42BD2E143932E5EULL, 
            0xF49BE110F9706449ULL, 0xF44359A60A8F91E6ULL, 0x42670A6AA5833FB8ULL, 0xD517C9DE14407B34ULL, 
            0xA60A3E342E8DA16BULL, 0x489FE23944C6F2E8ULL, 0xFBBB026F57770F0FULL, 0xB3C252CAF237D38AULL, 
            0x009166E535ADE51DULL, 0xC7E29798FD4A3107ULL, 0x93E255648CE2D05DULL, 0x163F73E5867668A3ULL, 
            0x7697CE42D1BE8FABULL, 0x2A5FC8D4DB59FC7DULL, 0x59435742580DCB8AULL, 0x29083DB944F62112ULL
        }
    },
    {
        {
            0xC4DB33B380F1793CULL, 0x4D8551F06379F60AULL, 0x8A29790CF51E3559ULL, 0x5B84D0CA33AF2CEAULL, 
            0xD5F88EBB1309050CULL, 0x8865CD9774746F2DULL, 0x2E12C9A7ABB4D511ULL, 0x70D847F3ABBD5464ULL, 
            0x6DCF4B43A3C54FF2ULL, 0x34862F2F68B07E84ULL, 0x550EA9803F70D7A7ULL, 0x27ED8D9ADF1EE05EULL, 
            0xED49CBF7C3E4494DULL, 0x2FB4979D8D00ACE3ULL, 0xD5DA4DA4E3D74983ULL, 0x5985C3B05787AD25ULL, 
            0x944EC27AA5260A77ULL, 0x71A8B9893DEFD391ULL, 0xF081EDE0B877A440ULL, 0xD6BE62CE57226E31ULL, 
            0xBFF9B6D69753CF16ULL, 0x25FBB481DFA2FFA1ULL, 0x6F8A07DE62899A20ULL, 0xFB93ECE44DF721B4ULL, 
            0x4228E6B36AFB9F8AULL, 0x388BBFB933166A34ULL, 0xC4B1FAFA8738F02CULL, 0x9DF6D10080703E85ULL, 
            0xDC73E6B00FB2908FULL, 0x9EC686C92142B5E5ULL, 0xF332FACD1CDBE549ULL, 0x49078E4F387BB70AULL
        },
        {
            0xCCE4A806589A88F8ULL, 0xD2133A4E1C3BF56CULL, 0x20A01BD2D628AA13ULL, 0x4BE8F74B0DEBB955ULL, 
            0x0738625CB213BC89ULL, 0x4EF7FAAAC8CAA1E9ULL, 0xC395785AA7353918ULL, 0x16ECCBDDF45EA311ULL, 
            0xA41CF8A38222798DULL, 0x58D9123C125EB672ULL, 0xA3F543411BB0BC25ULL, 0x0EC4885FA51F219AULL, 
            0xFB3EC0FB80077D29ULL, 0x9912144F5A34057CULL, 0x0D808B1BE89FCEE9ULL, 0xF915290F43B89286ULL, 
            0xB001A39D8A75FE2EULL, 0xF020F71DFC875BF0ULL, 0x067B19CE6340D610ULL, 0xCACA36A7AEA060BDULL, 
            0xCBD1181506104EC4ULL, 0x1F26637C6A5E4FB1ULL, 0x75214FAA574076C8ULL, 0x09B14B238DC87AB2ULL, 
            0xEEFF9B35E4FBCAD1ULL, 0x4B94769B79C61A23ULL, 0x4BC77F1F61198DC5ULL, 0x1C6B1B22B2DA7C23ULL, 
            0x1A64B688D268B14BULL, 0x8254A1D177744D41ULL, 0x8BBE10443F1F17B7ULL, 0x14844D7220EAEFDDULL
        },
        {
            0x073D58C7EC1FE098ULL, 0xDA2346B50F12ADECULL, 0xA165AEE963C984F5ULL, 0xED117E544FFCAAD7ULL, 
            0xF1AF194F694B207FULL, 0x2187C0526ACD8B4BULL, 0xD6DDB7E38485C599ULL, 0x0D2534BF8653FC83ULL, 
            0xAED461B0234C888CULL, 0xD319AB85672CBB29ULL, 0x93E69BAEE0BBD164ULL, 0x415965B206EBB1C9ULL, 
            0xBCC20C510C523B77ULL, 0x2B2F58180FBE762FULL, 0x8FB38C7236837F23ULL, 0x8BBBAD3BB23F535FULL, 
            0xE97C6C9EA9EA742BULL, 0x60414825FA5FD5E5ULL, 0xA3872BBBBB8DD67EULL, 0x3AFEFCFEF8EA4946ULL, 
            0xFB5EEF6D7530C65FULL, 0x0C5CD8B4CB32118EULL, 0x24F82B72B9D36092ULL, 0xA8792494E6E821E1ULL, 
            0xD4DC9562408784E4ULL, 0xCAFB702D26B602A3ULL, 0x563B41528830D23CULL, 0x4184EEC448E20B1EULL, 
            0xBDDDBEE6AB45DF73ULL, 0x3B62B9F336E74181ULL, 0xED4664A49F133718ULL, 0xC19362FD87629DDFULL
        },
        {
            0x75FD8A93C276FE1FULL, 0xDE9B07F74033CF61ULL, 0x1F8D4465316620C2ULL, 0x6E759BDFA8DF3F8FULL, 
            0x4DD93157F8460886ULL, 0x4C6194E1E3BF7A1BULL, 0x11C10C9E7D04C513ULL, 0xC5229263869934B2ULL, 
            0x8B06A31B65837F92ULL, 0xE8EDCC9FDEFB11FDULL, 0xE06BB3CF849D9240ULL, 0xB953DB8EA89DD1B6ULL, 
            0x5DEC4874405DB183ULL, 0x941B361A6B65B7D6ULL, 0x2FCC4AD94AC35B63ULL, 0xA6A1326A6113D1C9ULL, 
            0x2B77CE4CE700F389ULL, 0xC4F3D343BE696859ULL, 0x52E54BBC831EBF55ULL, 0xE6607449602CBD78ULL, 
            0xDB3E91D9F430176CULL, 0x675B4F6816A317A9ULL, 0xC0F433F8DE5AEC93ULL, 0x41ACB2F5A2914E5AULL, 
            0x0EA84122DC6B1378ULL, 0x361BB992C4034BEDULL, 0xF9E984618FBE9CB1ULL, 0x6F7E388B77F81728ULL, 
            0x7376E1AB69DF240DULL, 0x7E93448C4CCE6673ULL, 0x60AA86534EF3E889ULL, 0x823CC0CA426BA354ULL
        },
        {
            0x0A851AE282FADBB6ULL, 0x93A4A15E70617408ULL, 0x7626FAA050F3D2D0ULL, 0x91F2127B37BEB7D1ULL, 
            0x02D771DD2F3405F5ULL, 0xDB95A8EE7C378DA1ULL, 0x8C3E20582195ED7FULL, 0x57A476A043D3F7A4ULL, 
            0xBEB6D6DC3DC4A77FULL, 0x49691B87A56A2B63ULL, 0x6BD845CD9A9BDEF9ULL, 0x0CBAAC41B5E97F83ULL, 
            0x3B681A5348D74561ULL, 0x67E76489A5C9565EULL, 0xED83A0E348668732ULL, 0x24F289F7792D2824ULL, 
            0x6CB18D5BE8ABF4C6ULL, 0x654618E4310CF323ULL, 0xADC9BFEAAD95D49FULL, 0x14CD6B8FE3F49BF3ULL, 
            0x99D0A40F68CC73CCULL, 0x297D5D27BA3252D2ULL, 0x4E2DF84EB101B1A5ULL, 0x44AF429FABA93929ULL, 
            0x6E2F5A38926E82E7ULL, 0x5C73D622E1E95F60ULL, 0x2FA4202582FD36F0ULL, 0x13874ADDA1B15C73ULL, 
            0x1FA4B6C1EB79C22AULL, 0xAE097DA8D2ED4306ULL, 0x4A98B36A70592F0EULL, 0xB406A113FD7DDFE6ULL
        },
        {
            0x008C146A423BEBBBULL, 0xB993428D29E3641FULL, 0xCDA2D082ED1EDD3DULL, 0xD6FCCB734515A181ULL, 
            0x24887001235411CEULL, 0x366F6BB6B84D615BULL, 0xBA33464E1CB88B16ULL, 0x4DBDBC7ED00CA4B7ULL, 
            0x681554A3C3F9FC6DULL, 0x83750DB626FD166EULL, 0xA38C9B8C20529BEDULL, 0x5613B276D71761F5ULL, 
            0x546D6C9C778FD8D2ULL, 0x9C4D0972042377FBULL, 0xE83E0595F2B3A35DULL, 0xB0302F318208BC52ULL, 
            0x32AC6D306D75EC12ULL, 0x568E9524D9532455ULL, 0xD8477B3E0A2BD423ULL, 0x8BFE8FB5EC663912ULL, 
            0x8FA0905FED470A61ULL, 0x172953FCA68D6516ULL, 0x78423707D027CF8AULL, 0x18F1EA398BA650B4ULL, 
            0x2E74142BBEC2FD27ULL, 0x95D317C29C210E0EULL, 0x2CB5B14F1EF83721ULL, 0x6267D6EEA24749E7ULL, 
            0xC6A9B5540A3ACB87ULL, 0x3047EB68C16CE064ULL, 0x94106260E45A130EULL, 0x5BB240795EFDCA43ULL
        }
    },
    {
        {
            0xC4CDE32C239EF0B7ULL, 0xE3501A9161AAD5C8ULL, 0x77D5290D7F5C0711ULL, 0x1178859C178C1653ULL, 
            0x51478F5350DA253BULL, 0x55378DA51F28513FULL, 0xC98C255FF21DB5D3ULL, 0xF8CE794B05230F7FULL, 
            0x1A9B5630D4E9C51DULL, 0x49AE27DFEF195DA4ULL, 0xBA8D36D2D9239D7DULL, 0x608BAA11731F924AULL, 
            0x8C66355409E1B8FBULL, 0x8527B015637E5EE6ULL, 0x9A2568B599556C98ULL, 0x8891DC4B304ACC0DULL, 
            0x2C51220A7D2983C8ULL, 0x38F6E2F81960870CULL, 0x3EE2E69E1654DD14ULL, 0xA73A305829DE29C7ULL, 
            0x5FCBCBA267D18833ULL, 0xA5FFFA77A6A6452CULL, 0x84A25A84D0EF49EFULL, 0x53676655F51CA062ULL, 
            0xD4EB24312A70A023ULL, 0xFD47C51EA452D545ULL, 0x97664CAFB79CD58DULL, 0x3DCC1C399696C584ULL, 
            0x17DC03514CA490F3ULL, 0xB9AECDFCE3B5E3C6ULL, 0x04EAA7896658B52FULL, 0xEA51DC5FCABD51A6ULL
        },
        {
            0x9525C172C3AE6506ULL, 0x37E1F0FE0CBAD2A3ULL, 0x3778CE0652102205ULL, 0xC31E161604CF9DABULL, 
            0x1808BAA79F290CA1ULL, 0x34AF6C2C7EAFD840ULL, 0x1075AF657E52E8EDULL, 0x015B838071503D58ULL, 
            0xE6F5F4F54D60EE9CULL, 0xBD35A34741216E63ULL, 0x56BD53BBB54C9A77ULL, 0xECB180397AD44AB3ULL, 
            0xF536A64811B23232ULL, 0xFA7517FB0808E73EULL, 0x5DE8329CA3F6A1C7ULL, 0xD2D441512B33968CULL, 
            0x6C2E9A62FC84A30FULL, 0xE33707241533C254ULL, 0xD4688C9AB41CBD58ULL, 0x018C04576F56AFB0ULL, 
            0xCEF7F81A6DFE8C4FULL, 0x8139E191A26471D8ULL, 0x38C1160BE46DF989ULL, 0xC4B5BFB59CC84AE6ULL, 
            0x98CF074C6DBFD8B2ULL, 0x5D5E00EB993FA309ULL, 0x5F77A8C8F91EE839ULL, 0x04690C2EC3DC186DULL, 
            0x635939BA2523FA27ULL, 0xAD1CEA41541DF320ULL, 0xA92FA869DF51A631ULL, 0x9134C39CD56DC179ULL
        },
        {
            0x8F0F6D630B77ABF9ULL, 0x67E2BF16B734BBB4ULL, 0x0F95C3C6DEA59D38ULL, 0x9566CF9A82272025ULL, 
            0xC55886392B5AB2C2ULL, 0xD311EA14F699827DULL, 0x79FE7D720E6BFD64ULL, 0xF0285555F62FAF18ULL, 
            0x8DC3D3A42EDDA6E0ULL, 0xF433BB8605F34AD8ULL, 0x4C9B91A075B5461BULL, 0x997207FF63E0CCFFULL, 
            0x4E91997541C6FE90ULL, 0x1B6F33E87AD7C2EBULL, 0x0563DD6A9873B919ULL, 0x9CA705AFE60EE462ULL, 
            0x188F482BC7FF4C75ULL, 0x8B4C40F2C387BA90ULL, 0x48638C3AB744E525ULL, 0x3A711AD59AA2A7DBULL, 
            0x10B34AFE08FBF1A0ULL, 0x1B21AD8E60E9D4D1ULL, 0x66C9380BA9648EC0ULL, 0xDC3158231F04B2F7ULL, 
            0x7A826A012BD95D66ULL, 0xDC9FC9A4EF21ECC2ULL, 0xF29D65BFC749AA84ULL, 0xB331B3906743F737ULL, 
            0x8B38C2EB5D896A3AULL, 0xC706DCD2091576F0ULL, 0x24364239C34A0E05ULL, 0xBA979CA0682E7A23ULL
        },
        {
            0x3775708A6DEAA623ULL, 0xB03AB54E5EF929CFULL, 0x1DF5CD2B347750BEULL, 0xD591D665DD60D477ULL, 
            0x77FE9CDF99CBCA6DULL, 0x7DA496DA5A9C77B0ULL, 0x512BE4FD13CEA435ULL, 0x280FE2AA31C40ABBULL, 
            0xBF640E10D9D51196ULL, 0xB2D7AA4088F4FBEEULL, 0x1F524C243CF395B9ULL, 0x5900AE540D8BE675ULL, 
            0x87A4F111DFE2B8E3ULL, 0x853E762D9B503B8BULL, 0xD2F990F8245C8945ULL, 0xD9863966F82B07D0ULL, 
            0xA35BEAE4ED4C7B1FULL, 0xF8F8AC4E0E8A87B8ULL, 0x3A5CCD080616EEE2ULL, 0xAFF16537E32B48DDULL, 
            0xBB77AD18B7472432ULL, 0x936F2D44E8565110ULL, 0x73AF9C21FE6F7EE6ULL, 0x54AEE752E361E49CULL, 
            0x7CA268ABE66642ACULL, 0x0BED0AFBE2279F15ULL, 0x8FBEC9CBE817889EULL, 0xD519899DA0B42460ULL, 
            0x58F54F3C8778938EULL, 0x092023F7315B69B6ULL, 0x120C4EA29E5783ACULL, 0x872126EEE6C09873ULL
        },
        {
            0x43DC92C56BD9A768ULL, 0xB6D087A61DD197A6ULL, 0x6E1B3B233ED1035CULL, 0x7C1765C5D1BA671AULL, 
            0x48E1F3ABC85ED49EULL, 0xE36B1AEC0FE3733AULL, 0xD400558663903908ULL, 0xB3640CEC89220A0CULL, 
            0x4415E65D4D736273ULL, 0xE2DA21EE16FF0C8AULL, 0x295BD8CF46EE4794ULL, 0x2D59D64258B03D5DULL, 
            0xE60D73ECC5094F34ULL, 0x990FDC286557DA43ULL, 0xD51E58489D44D6BAULL, 0xCEF1C9D8C13204EAULL, 
            0xE938CC65CEB6C1D6ULL, 0x728AE0D9958A3F1FULL, 0x1EF91C6EC0AA32A5ULL, 0x97D449CC6F27D630ULL, 
            0xE10833ACA9BC6FE2ULL, 0x571BBEE9C67ADDB7ULL, 0x0A7ABF147A462DE5ULL, 0xEF42EE48A5879A5AULL, 
            0x95B7C282BAF02FCFULL, 0xBF2874543AB44A5CULL, 0x7A495B567836AB3FULL, 0xCA59484BD356F4EDULL, 
            0xDAD7437810DB7297ULL, 0x1CA1C1001C67E6D8ULL, 0xCAC4385188CB2829ULL, 0x66F30AEAEC93F332ULL
        },
        {
            0x6AE0E2F0EF3685DFULL, 0x355F17C96B7B8D8CULL, 0x94269713034BFE42ULL, 0x185D127CA5094122ULL, 
            0x3403153CEE342F6AULL, 0x55CD1169EC48AB12ULL, 0xFB3571EF57083D6FULL, 0x0938C69059B6A8AFULL, 
            0x0506A62789BAF279ULL, 0xA26769A8A0FA0EB4ULL, 0x951F674D896A94D2ULL, 0x54628F0E3647EBFDULL, 
            0xFE8938CE750C8375ULL, 0xBBBA7CCC9997A4BEULL, 0xB819BC1FF017ACAFULL, 0xF69509800136CDDDULL, 
            0xBC16407E2DA78EA9ULL, 0x073C4EBF67EA423EULL, 0x55CA4BAEDDA67BF0ULL, 0x87B1DD4610C54F84ULL, 
            0x4AC9B69EF72DE401ULL, 0x2592850E414824CFULL, 0x695A86154A4B8EDEULL, 0xEC7AB4876D9D0288ULL, 
            0xA6E2E2D480B2235CULL, 0xF392C28E988B4250ULL, 0x40AFF22F84688A80ULL, 0x0BFA6F6468446ABDULL, 
            0x9129034F83378E4AULL, 0x4FFC9D76885CC6D1ULL, 0x7A6CD5E5542E2D3FULL, 0x70065D3917A2BA70ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseBConstants = {
    0x8C703F834A6FC1BDULL,
    0x565D4A9A71B386BAULL,
    0x90DA01C013FFAE8FULL,
    0x8C703F834A6FC1BDULL,
    0x565D4A9A71B386BAULL,
    0x90DA01C013FFAE8FULL,
    0x9E94CB2ED3EF3126ULL,
    0x989C1CDDB33102FDULL,
    0xC3,
    0x08,
    0xB0,
    0xCC,
    0x5A,
    0xB5,
    0x75,
    0x66
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseCSalts = {
    {
        {
            0x141C9AA9B3CAA920ULL, 0xF2A5A8C566E9DEA5ULL, 0x8D7D23321D053FE1ULL, 0x5DF865F72D4BA07FULL, 
            0xC7BFE7DD00627624ULL, 0x122F3B8BA2D91243ULL, 0xDA71CD66873A0427ULL, 0xB028E2D5564A4E58ULL, 
            0x89F0AD0EEBEA6939ULL, 0x9BB144DEAB3391D9ULL, 0x9DC49BEBCFC015B3ULL, 0x8B3C82384A8946B7ULL, 
            0x9C9C944C6AFBCB6FULL, 0x928029917B1A8C82ULL, 0xC39BB8702DF73723ULL, 0x1063B2E5F9BFF73BULL, 
            0x14C79CAD18D21048ULL, 0xCBC077EE1B4FB3C4ULL, 0x9C0F14C640AD7386ULL, 0x98FA3D8CACDD1AA7ULL, 
            0x34B5EBE7723E6E25ULL, 0x6FD4EA2794342EF3ULL, 0xD62C0DADC56A2CDEULL, 0x8DE09CD383094A0BULL, 
            0xBD35E26015E1D08DULL, 0x3BE4D4EFF32DF463ULL, 0x7FEF74DE058C2276ULL, 0x85DD3A59BEF551C1ULL, 
            0xD4552D0DCDCD22D8ULL, 0x1D6AC4FC94065C11ULL, 0x07E612A465258AF6ULL, 0xE6F1B84766F57EF8ULL
        },
        {
            0x541EE0A3350487B3ULL, 0x6D3C7479B149BAF6ULL, 0x476FB925F1F561BFULL, 0x04DD9976FC84A32BULL, 
            0xA5CA34DABA443181ULL, 0x60EA52C773CEEC61ULL, 0x12A4649FC5EFA1C8ULL, 0x92B8BAB874EFCA60ULL, 
            0x3588076FBEDC4131ULL, 0xFE47541E2F7AA825ULL, 0x9BCA8957B4A0CB5AULL, 0xDF457E5877E47D6EULL, 
            0xF273957BC6B10804ULL, 0x5D19D8188A813B32ULL, 0xC93391A3BF541E23ULL, 0xB98F0FF40CDA2298ULL, 
            0xDB71AC6056C593A5ULL, 0x32465A0D564617DFULL, 0x57BD34ADC80833E8ULL, 0x22BB847572CD1CC1ULL, 
            0x36B7A7A496E526F7ULL, 0x91E05ABB850F8534ULL, 0x157C2EE864CF388DULL, 0xC63CBC634BA8C551ULL, 
            0x74E91DEC930A090CULL, 0xAD97193F99225E9EULL, 0x6E88176D8CC962B8ULL, 0x266652169C819A72ULL, 
            0xEA42A7DDC781DBD6ULL, 0x0F01F7645E321882ULL, 0x20C42A2BCE2B28E6ULL, 0xC58AAC5DCADDC723ULL
        },
        {
            0x3ABFE28AA0F2B409ULL, 0xB51E2D6F44E80730ULL, 0xB9E0705C0904B22FULL, 0x0C9C1D7C37009FACULL, 
            0x336E871E468162E3ULL, 0x1FE4B9E5757F69F5ULL, 0x62A0C7A86115431AULL, 0x868EC9B75AC214A7ULL, 
            0xB0586885F8026B93ULL, 0x17685C46FE93C943ULL, 0x8C98CB433B02EA09ULL, 0xC648E10DA73CB5C5ULL, 
            0x35BF00AF6DC59F18ULL, 0xBE4CE70AD8419453ULL, 0xAAF29A7E46AE2C00ULL, 0x3DA0E8F77B40B178ULL, 
            0xD8A66A20533CCCC2ULL, 0x4F75B5FCCF6BF2FEULL, 0x923A0AB0BE050889ULL, 0xE0963C48AE0010CBULL, 
            0x8C0F4DF53F2049BCULL, 0x5B04AEEBDBABC968ULL, 0x0429F093A1275380ULL, 0x2C3B2CE0C76AB7BFULL, 
            0x6D2013ADDEB0E30FULL, 0x14FB99C24CCD8964ULL, 0x36D00B351A3ACD38ULL, 0x4C12B7E2F1C3409AULL, 
            0x2A4A698F75ED21E6ULL, 0xB2B538979F7B80D4ULL, 0x2C53CF2CDD77E247ULL, 0x4D8895264D8384E7ULL
        },
        {
            0xFB2FA1B71CEBF67CULL, 0x14DEA235073983AAULL, 0x33B77311EF032F44ULL, 0x1EDD4DAD5D2FA7ADULL, 
            0x214751F675E119F8ULL, 0xC72B91C1F69CD5E1ULL, 0x0FE798001FFFB3DBULL, 0x803D911C4FC93959ULL, 
            0xB693643501794922ULL, 0x55161AD5D5A1AF4EULL, 0xAC84D384573F2D5AULL, 0x02756396BBC94FA1ULL, 
            0x2BE1F650CCEBDE62ULL, 0xBB26185BEFE8EEDBULL, 0xD632C262ED5E4713ULL, 0x78B7C7DF019CEE9EULL, 
            0x036716A0CD70E584ULL, 0x663845E74EC2563AULL, 0x6E6E6551F08909B1ULL, 0xDFB8E16F90D35655ULL, 
            0x8D2B50209E41FC67ULL, 0xD3B9A9063C0F2965ULL, 0x9F653B98D82E700EULL, 0xC3CDC78164B1CB82ULL, 
            0x28EECC2CEEC10614ULL, 0x7E58B79C9B0AD7AEULL, 0xCCC92668D7FBE1BEULL, 0x4D0384411E3A2707ULL, 
            0xA121F5D5A313A62AULL, 0xAAFBD243B2A097F6ULL, 0xE7D4802A201DEEC3ULL, 0x084EEB9468B1F68FULL
        },
        {
            0x7B5919EC91D3553BULL, 0x79F740CCD856F5D7ULL, 0xABB97F1C2B3E0E47ULL, 0x1C55217900ECB8C3ULL, 
            0x7BB9BFD9CE9300E2ULL, 0xA9AE61A3804866ADULL, 0x62798934072C3875ULL, 0xC3C3E938C1963765ULL, 
            0x894AFEF1336B9F59ULL, 0xA933C4814DEDE3DFULL, 0x8D50C941A4562DD0ULL, 0x572AA37388D7B5A2ULL, 
            0x3D435883C5936C9FULL, 0xBB1C94C85FF66DD5ULL, 0x8D92BFA9CF43FCCCULL, 0xED18F5F5D15A3E88ULL, 
            0xEA0ECC9E246AAB25ULL, 0xDBF403A929CD8453ULL, 0x3F582B1C57731E6AULL, 0x11CFE8379917BD6CULL, 
            0x8658BD71F5F4CEACULL, 0x2472065CC1F5EE75ULL, 0xD7CE9DCA7098F755ULL, 0x8F4DE2C569E081FAULL, 
            0x788E3D62B89D9BBCULL, 0xC028B25404E88C8CULL, 0x93C0030C04B2B45AULL, 0x840D037814B23D7EULL, 
            0x1BC5520770A15BA1ULL, 0xBEF32CF9800DD849ULL, 0x0D8173DAAA9A0CEBULL, 0x1506A26C4337885FULL
        },
        {
            0xCE78CA13333A3348ULL, 0xBA280ADDCEBA2E9BULL, 0xA7DF8F64B2621AE3ULL, 0x009A6885B0E65326ULL, 
            0x37F450D816C5EB44ULL, 0x5CB717C37B06EDB0ULL, 0xE4D85193C073E679ULL, 0x22872DEA7368E91CULL, 
            0x8B0CA08BBC5C6302ULL, 0x8BA2A781257E522CULL, 0xB9ABC69281AB13B7ULL, 0x815980061D05B414ULL, 
            0x2F88E070FED0DB52ULL, 0x79A0393B98BE0D31ULL, 0x679D50CF7AF10523ULL, 0xFBFC3C193D8E6C03ULL, 
            0xA14F5046A80CCFE5ULL, 0x5EA0601FD9DD6928ULL, 0xD9F5210F6681A6A7ULL, 0x46DC55E913C54107ULL, 
            0x713C3F3EADD18CE6ULL, 0x6E4554AC9331CBABULL, 0x5DF9E2F8E7AD3CBBULL, 0xF937F3E315BA92D6ULL, 
            0x7D6D3CDDDBCE1E76ULL, 0xAAF053A7FBAE5A81ULL, 0x26E50892BDDAAF00ULL, 0x347E02E3B677489CULL, 
            0xB5F7F0045F0DB43FULL, 0x62C5B22865EF2A4EULL, 0x0B9FD7E2C46AEF90ULL, 0x841433791274D2F8ULL
        }
    },
    {
        {
            0x74C4EB6E0A04DA2AULL, 0x51EB92C818951E11ULL, 0x44AB9CC224A6604DULL, 0x9680F8840DFC47D4ULL, 
            0x04C8DAA25EE77113ULL, 0x29864812709D93E0ULL, 0x8761C3D1B43A8CCCULL, 0xCBEE17873324AF4BULL, 
            0x330FF97BB1CEFE3BULL, 0xF401259B8973816AULL, 0xE85A51DF91EFDD93ULL, 0xED4B03A0FBDFC417ULL, 
            0x94DE1F3D193A65D2ULL, 0x682D7AE4825DA99FULL, 0x48AB56E51E9BB89CULL, 0x09B5699F2B450A21ULL, 
            0xEFC367A5CE3B8640ULL, 0xAF37E8A492F4F34DULL, 0x6604FD5E0296F358ULL, 0x2CAACC88326A66B8ULL, 
            0xFB9A2F40A1C35E92ULL, 0x7FD9C798DA5F5260ULL, 0x4394DE761CBB3160ULL, 0xAF1A24A3D2CD6AB9ULL, 
            0x672F36DDAAD1BB6FULL, 0xC686479CFE219871ULL, 0x15B5703EE1CC7D64ULL, 0xD138C5440D245CAAULL, 
            0x0264BD01C4E4A8EFULL, 0xDA762E090A64B92EULL, 0xADDD406512B75798ULL, 0x8ACE43C17F0B58DDULL
        },
        {
            0xB41818C964A0E568ULL, 0xE3307DA107F62E38ULL, 0x20F6475E3F3BD016ULL, 0x8CB72AB648AB6314ULL, 
            0x838552846B7CFC95ULL, 0xA508AE816C48C314ULL, 0x4431BE16030A036DULL, 0x5A5BCEC5B6702990ULL, 
            0x002924349A9325F2ULL, 0x42546AA86194E274ULL, 0x35FE94F0CDBBDF61ULL, 0xA482F9D4D2774327ULL, 
            0x3D032135EB4C732DULL, 0x793CE12581E9649EULL, 0xD47715733F2B442CULL, 0xB6B509B9CDD0712FULL, 
            0xF5826B899F1939ACULL, 0x571001C05147ABACULL, 0x2096042EE96A1A2CULL, 0xC0C6797DE1888C19ULL, 
            0x9DFF0217CB31E1C1ULL, 0xFDE3F2DEFDD81460ULL, 0xCF2C83271DFBA44CULL, 0xB4558AF41C6D5B9EULL, 
            0x996005E4FFF88D57ULL, 0x9843EDBD88A86CE7ULL, 0xBF16724F56102ACCULL, 0xBA18BD9836583AEFULL, 
            0xF32BA68A26ED575DULL, 0x44E3A6531D834A04ULL, 0x01D6E4FCEC02F73CULL, 0x62DCA40CB19DF22DULL
        },
        {
            0x001BCAF18CF386F8ULL, 0x789FF990B5BF66A6ULL, 0xAEC8EDEF4EFC2785ULL, 0x730B5FAD733A3815ULL, 
            0xCD456A8BA81686E6ULL, 0x1E4E8BC142455354ULL, 0x847211FE3229D3F8ULL, 0xC6998A62006C141CULL, 
            0x20902ACC2BB3B29EULL, 0xEC992E217091AE31ULL, 0x89315F771F40041BULL, 0xC387D3A724426004ULL, 
            0x5007B64DD6058348ULL, 0x21B5961A19416D66ULL, 0x71E86448BEEF37FAULL, 0x8AED901BF2FEB354ULL, 
            0xC812846F152EE266ULL, 0xE4DAD1420B400BE8ULL, 0x704408094ED57D82ULL, 0xD2C23A3006A077DFULL, 
            0xDD79873FEF90BCA4ULL, 0x74A86DE6D35A34BBULL, 0xC88CCAEE50171BF0ULL, 0xC55716D3EAC52CADULL, 
            0x24B4A2CD14D070AAULL, 0xDA3DD658EA0C21C3ULL, 0xDC8742CC0EF4EC48ULL, 0xB4422AC73BFB7E11ULL, 
            0xD7644C31A3F3425EULL, 0x1A347C45C5D2C7C8ULL, 0x09D07EE83EA4B4C4ULL, 0x595C653200BE6514ULL
        },
        {
            0x674A995582928A9BULL, 0x2D5A351E328995B3ULL, 0x819A7A2D5EEFAC08ULL, 0xAE46EABC3FA0AA36ULL, 
            0xB25DACC10F0B3305ULL, 0xABDD9FAAE297430EULL, 0x53E9D95A760419C0ULL, 0x5403083581A5653CULL, 
            0x424D89FD6B0AD941ULL, 0xC64BD08A919E3152ULL, 0xAD005DB045B09B40ULL, 0x235F99F1494FC138ULL, 
            0xB027A6A4BA8C768FULL, 0x86298E2A472A8D31ULL, 0xEC1F66DBBDF015AAULL, 0xF431AE31CD0E50CCULL, 
            0x7CE329C525A9DE5DULL, 0x81EE603366C79952ULL, 0x2893820F5F9FC1DCULL, 0x728DE58FC6D6AD92ULL, 
            0x336575ACBC5118EAULL, 0x49B27080CD397422ULL, 0x129A90905A4B0797ULL, 0xA972682E4EBFED69ULL, 
            0xA2FE690A2D67C547ULL, 0x33D9D5947ADA33D3ULL, 0x4266CDF756381205ULL, 0x9C7C37317CD64FE5ULL, 
            0xEA80340CA21A8068ULL, 0x466BAC0C821598B2ULL, 0x365A4F7BF914376AULL, 0xCE5662866028090CULL
        },
        {
            0xA2824702E592E38FULL, 0x86FDFFA9B9B4B278ULL, 0x1121879B14568F12ULL, 0xF7294CE7497B8B31ULL, 
            0xFC9690DF01D2353BULL, 0x108774FEAF1D620EULL, 0x7D1382F048B3E31BULL, 0x24853EB2C57D1DEBULL, 
            0x8B849ECF8E5498FAULL, 0x8B4C712B81BD7F1EULL, 0x87DC33A1DEE82706ULL, 0x7D29CA448E695A73ULL, 
            0xD2FF62928FD49741ULL, 0xD263B4B87EF68DD4ULL, 0xDBF4F058616E9766ULL, 0xCCF8D947977F0D76ULL, 
            0x0E7FBB2419D51734ULL, 0xB718356DFC947697ULL, 0xC077C76E0B109B15ULL, 0x45D0D9962AA5BCBCULL, 
            0xBE837FBA5EB37606ULL, 0x28E502C234013FE8ULL, 0x8E902E9001D4DC7FULL, 0xCBCCFEA0D779AD0EULL, 
            0x82080F653804122CULL, 0x8382F539499FED5DULL, 0x93B541C37733D3FFULL, 0x3AE2B4E84D3AB171ULL, 
            0x8BF7302D0AC3033EULL, 0xCB8C8D19914C4911ULL, 0x82CD510BB4E7DAB7ULL, 0x96AA1FAE7DD8B3E1ULL
        },
        {
            0xE4C48B7FFA4BC670ULL, 0x9741AD8AF3C65017ULL, 0x2764EAF31AAAC205ULL, 0xB96A20702A0DC975ULL, 
            0x5B259B769CD08705ULL, 0x60073EFA750339BAULL, 0x50725F5DF15A52A5ULL, 0xD9CBE8CA8927E138ULL, 
            0xA5B8827BF0EFDB3AULL, 0x202C0C2AC89959F0ULL, 0x451DFE4B26899A94ULL, 0xB19D026996DE0CB8ULL, 
            0x5037B29D4A71D18DULL, 0x187B09E8CF53B194ULL, 0x4FFB8494DE399B14ULL, 0x5378DB2145CF02E7ULL, 
            0xBC403D0E6C134E6AULL, 0xDFDA09CB3AD04201ULL, 0x642EA7CB504986C9ULL, 0x2A9FCD9BAA0EE2BBULL, 
            0x92CB39D012B6B56BULL, 0x7C9AF6BC85787D99ULL, 0x66DCB73D09C51E4CULL, 0x71089182E252AF86ULL, 
            0x0C8C865E546B4CDCULL, 0x0EF0157BD9613D9EULL, 0x140820A0A5476754ULL, 0x7564DE500D3F9336ULL, 
            0xD24169FBA5D24F68ULL, 0x35EB41F9D07B3CCEULL, 0xA2A6688E94E6015DULL, 0x1A4B8E2849F36BDAULL
        }
    },
    {
        {
            0x6946C05A4FC98154ULL, 0x64CA3AC1C84B140CULL, 0x964626DF9AB34741ULL, 0xAE779B332700C090ULL, 
            0xE36F9AE32759D9BBULL, 0x03B434F8522754B7ULL, 0xE0010EE37B3CEA76ULL, 0x71D9C8CC3074A986ULL, 
            0x3D4E017154F8179AULL, 0x5876149A7D3B1902ULL, 0x1468311AD786AD6AULL, 0x108CB81308C17A74ULL, 
            0x4DA24EE3F64BB210ULL, 0xF836C66C54EEA128ULL, 0xB8B83CE8F0DEFC13ULL, 0x49681FB34846E20EULL, 
            0x44AFFEA44360CDE8ULL, 0x899E4B3E50291854ULL, 0x5B0E047DBBFEA7F0ULL, 0x1A3C220CF33EC047ULL, 
            0xF8753ED571CB7E5DULL, 0x009905F03D50196BULL, 0x7A9F3D23B4DB0C7AULL, 0xB8B2D1BDC51595A8ULL, 
            0xF7AC4CC45F35265DULL, 0x4533B27CE824D1A6ULL, 0x5E9B4DC81F179B6CULL, 0x520E2EAE444C8402ULL, 
            0x5E37308FBDC57758ULL, 0x8F8B9D54978D025BULL, 0x4C9165180E6A7A1DULL, 0x0A877355BA1FAE48ULL
        },
        {
            0xB9A729730D61D52FULL, 0x852EFDE048B7A863ULL, 0x5B6E69604C3643A8ULL, 0x1DFDFC21E05ECC71ULL, 
            0x19D371B65FAE0065ULL, 0xB8FD7BCD9BDB9630ULL, 0x378020A76E4A9D5AULL, 0x615A0E01C418F609ULL, 
            0x078BDDD908FDA0B7ULL, 0x203CDC12E2A8D938ULL, 0xD56D5E6B119A7A26ULL, 0x68354F2C6A18511FULL, 
            0x8A98D7A9DEB5648BULL, 0x0789A11C0A839151ULL, 0x4EBB9A1D43CCA069ULL, 0xB2C6A2481A273D7AULL, 
            0xC5A520D88835A1E9ULL, 0x812BEBA6D49519A6ULL, 0x395C427B7B4089B6ULL, 0x7A67ED6BD5524AEEULL, 
            0x47E0CD274F00F00CULL, 0xFD1C1300CF01E689ULL, 0x41813478455F87FCULL, 0x52423A192986DF8BULL, 
            0x17A3426AEDD56875ULL, 0x735A34221971EA85ULL, 0x2B209070801F7D49ULL, 0x4B9101C398231631ULL, 
            0xCCA1695968DDE15CULL, 0x8523B76D5DB16951ULL, 0xADA15EA99F9907E4ULL, 0xF30CC4681B57D957ULL
        },
        {
            0x0F246C91C35DB057ULL, 0x5FC2494FC524D1A8ULL, 0x69FB5E4917BDEF0DULL, 0xB49F4E63C6B7C8DCULL, 
            0x8DC7B80CC595FD9EULL, 0xBDE405B3782D3785ULL, 0x946D13AD5CE4642CULL, 0xB72C9C312170C730ULL, 
            0xEE3CBB2B5D42476AULL, 0xA694E10A6C79D159ULL, 0x18D3E7A5381C63D8ULL, 0xF5AEF06BFE738ED0ULL, 
            0xB2BD9CC4EB14210AULL, 0xBE43BCBB425D53E5ULL, 0x0DE5459A2201F596ULL, 0x4D90F348B30328B7ULL, 
            0xAF1BCDAA6E48B65AULL, 0xCB11D4F6089FE168ULL, 0x02377A8DF1772E5EULL, 0x05FDA34C16383626ULL, 
            0x96A3E3E519AD9DE1ULL, 0x93FB401E47449379ULL, 0xF79308A2E78A233EULL, 0x25A905142A44F938ULL, 
            0xDC1D625BE7601E82ULL, 0x0E92D80614FD1018ULL, 0x87BBFCAE938C7EF7ULL, 0x53980D4AE1E85C59ULL, 
            0xF5E8FE027C165552ULL, 0x6E3E07A4F2059580ULL, 0x517A54A9B0E3C070ULL, 0xBCA4E0E283A8885FULL
        },
        {
            0xCDDB751C60BF6D04ULL, 0x6DD0F8547A124FAEULL, 0x188925012ACBBAD0ULL, 0x7B5D024129825649ULL, 
            0x4BD3C52BC31AC38FULL, 0x692D885DA3FD01BAULL, 0xD88907BAFEEBA95EULL, 0x462F057150A36A5DULL, 
            0x814CB26540E3CA35ULL, 0x20874968C25E6836ULL, 0x74D2AEE66749FE98ULL, 0xA4F33A1F1B3C45DDULL, 
            0xF6BE8C2C84392CA4ULL, 0xC6382A8FF017C9BCULL, 0x275AA0DD20B6226CULL, 0x5D8B20BE47CE55F6ULL, 
            0xDC9D2B816E8764AEULL, 0x6A0C0E4B16CBDD9DULL, 0x7D7154E503BE377DULL, 0x08B6D6A14A2BC845ULL, 
            0xD1EA6A0E0FF01ECDULL, 0xBEF1864943C267C0ULL, 0x5A6B0CEF7BD769B1ULL, 0x4F207954FF284088ULL, 
            0xB9FCB7A63A335A27ULL, 0x4681C5A35F6204ABULL, 0x896BAB1226E61756ULL, 0xB46A9979EE8CC9C9ULL, 
            0xE0511C52AA47870AULL, 0xEA76A3218C87DADAULL, 0xF5951B79FD54D1CBULL, 0x7F22A8D9D3F5AFA1ULL
        },
        {
            0x4D142878296630EAULL, 0x04D185AFD1ABF83FULL, 0xDAE2604384677C55ULL, 0x30F00BA34AEFAC28ULL, 
            0xEDB20E52D4867896ULL, 0xF66F58D1B5C2DD7DULL, 0xB9B8B85611091A9BULL, 0x2CBA4AD793A1FCDEULL, 
            0x78483AD02EB48805ULL, 0xFECB282799917426ULL, 0x615C3D770944E2A4ULL, 0x98A8C632D954DADCULL, 
            0x5365C00DA9BA2DF2ULL, 0x132446525ED0ED60ULL, 0xAF9C03C402760543ULL, 0xA6F9EE11E80EC7ABULL, 
            0xCFA6BA1F66EEE9B9ULL, 0x4BD2CC5F57D83BB8ULL, 0xA73E1868E26B9634ULL, 0x0FA4CC0D986F6304ULL, 
            0x5636FE2CE4F14C19ULL, 0x0E06CE9C66C496E0ULL, 0x32EA6FD48DBACDFCULL, 0x3C52E95F805183C9ULL, 
            0x0AFA5ACD2325B768ULL, 0x72524AD1C9574F1BULL, 0x18C0006BBC105636ULL, 0x85C9C9F4A4B234DAULL, 
            0xEDB406F0D45E6238ULL, 0xF72CE05690D19EF5ULL, 0x2BA394FA89C5F0FAULL, 0xBB83A05FCA32D348ULL
        },
        {
            0x51B4267A8B5DC834ULL, 0xC0C658752A8FD842ULL, 0xBCB70758265DAAEBULL, 0xBBC0B1491FA71CF0ULL, 
            0x2E555E618E3A2FEBULL, 0xA4ED2D96CB7C6461ULL, 0x9482A4A058B1E048ULL, 0x4FCE951AC554CFE3ULL, 
            0x033EF3043EFE67A4ULL, 0x3D1A7B8760FC86A9ULL, 0x9C812A4B670F439FULL, 0x24424BB2AE622267ULL, 
            0xC3AF157B479D65B5ULL, 0xA7DCD500A9D75280ULL, 0x0AAEB0AEF2CCB306ULL, 0x303D1F342E2921A4ULL, 
            0xEC4E05C9D4B8755EULL, 0x3099569B49E70F5EULL, 0x7A86344EFD6B7687ULL, 0x58ACFC8DE80A239FULL, 
            0x07479D5B2B7D2E9BULL, 0xC61B55F289A558ABULL, 0xD9511D99585DD690ULL, 0x64DD1CAF1E0638E7ULL, 
            0x16021F6F724971CEULL, 0x8F92D4A1C58727D0ULL, 0xE40CE0C9691979C9ULL, 0x5803480E0F7F3CD8ULL, 
            0xF13CB3EFB2BCD1DAULL, 0x38B947A5EE81BC42ULL, 0xA21FEF78D7D04078ULL, 0x4001620A02D8F204ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseCConstants = {
    0xF2F20A2DAACC53EDULL,
    0x78F344F99EC1C7F0ULL,
    0xF7328879770D4E58ULL,
    0xF2F20A2DAACC53EDULL,
    0x78F344F99EC1C7F0ULL,
    0xF7328879770D4E58ULL,
    0xF67D1F47A0327123ULL,
    0xE9636D1FE2DEFE79ULL,
    0x99,
    0x0D,
    0xF8,
    0xFD,
    0x7C,
    0x79,
    0x34,
    0xFD
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseDSalts = {
    {
        {
            0x785B527C10F667C5ULL, 0xCD0BED3D7A468992ULL, 0x76CDEABC261257DDULL, 0xF468ED915E312463ULL, 
            0x9C62CBB76E7C9243ULL, 0xEF12D67A89A6B854ULL, 0x66F48C23E0CCBF39ULL, 0xB58EB95BB1EFE657ULL, 
            0x08D0A1035A294BA3ULL, 0xAE79E31258A7C95AULL, 0xCCD165CA8999D22DULL, 0xFD52B9FF620B1254ULL, 
            0x80A1FDB604C65418ULL, 0x6511ABFC855B3613ULL, 0xE31CF6671B859FDFULL, 0xB277B69CBB499A57ULL, 
            0xA5FAF3425176880EULL, 0x698DFBB4FFB6F25FULL, 0x9E6B2FEE3D994634ULL, 0xE4D97C8F092309A6ULL, 
            0x0D91910A6B6F3D4DULL, 0x321A473B2A7007EEULL, 0x0F952E214F1C0865ULL, 0x796D31A439648384ULL, 
            0xBE466E1A3ED50652ULL, 0x1139E3567835E0D2ULL, 0xEB7D451CAB8B6CEFULL, 0x677072A6B7FD2BDEULL, 
            0x095A5F77DAE849DEULL, 0x289417B6C7968F09ULL, 0xA5229E1984D1D1AFULL, 0xA0EFF49F16180696ULL
        },
        {
            0xC08F0EB1F2AB4610ULL, 0xACE8E3D10936D2E3ULL, 0x9390D2A031C1639FULL, 0xA749F826E8D38B4CULL, 
            0x5FDD8CFA4171D12FULL, 0xA664F7F4A9429613ULL, 0xDF667D42DC4F62B0ULL, 0xC2C2B4A1911FB63AULL, 
            0x2D371F18EA4648A1ULL, 0x7BCE4FA170E431F6ULL, 0x9EBB2C7DD0981645ULL, 0xEBC6C873526FD9C1ULL, 
            0x90D06D397EC4672BULL, 0x1862A028132EEE8EULL, 0x1EC702F410309921ULL, 0x3BB08B6FAA6AD22CULL, 
            0x053DCCD663D853FBULL, 0x503BA6BD8871AA61ULL, 0xDDF6104B9315CBD8ULL, 0x05957ECEC8CA46E6ULL, 
            0x602C8678DA484A01ULL, 0x62631E5644075093ULL, 0x983DC728DE44C560ULL, 0xF59A8648352F832EULL, 
            0x0A136991465EA740ULL, 0x6812351EC2C72805ULL, 0x76AAB7542233627CULL, 0x7E7A366C0E17A8F5ULL, 
            0xE94DF5BB24E6DD4AULL, 0x821CD3135E0D1DACULL, 0x6766B87F8E044209ULL, 0xE60D526EC82D1D8EULL
        },
        {
            0xC9D28719E19C5F38ULL, 0xEFDA684A55AE6A08ULL, 0x6F6E0751703355C1ULL, 0x0D7F8C2BCB1E9D93ULL, 
            0x86A981A26E72BDFDULL, 0x88931BE181C4E148ULL, 0x72164365A9E556A4ULL, 0x4FC926C6558E18BCULL, 
            0x086C19BC8E61C049ULL, 0x8167C43E567F876AULL, 0x8D862FE5817E6895ULL, 0x38C41055BCE82BB0ULL, 
            0x642C177EDC38B795ULL, 0x0C6BE7E12DA31ECCULL, 0x599016A0FCDB2A82ULL, 0xBBE3809A049831A3ULL, 
            0x1D7B7ED09A61DBE5ULL, 0x03646C7FCB9B63E1ULL, 0x51FCF3A01A3B7A0EULL, 0xD2230CB2DBD1E901ULL, 
            0xBB8C2E3CABD0B507ULL, 0x1DF2082233F6C85BULL, 0xBC555C6E4DD006E0ULL, 0xA6BB3E718F4709B9ULL, 
            0x0FBE0DF2B45C174EULL, 0xFDFFBE8A792F4973ULL, 0x155417749E5C289DULL, 0x227997FBCCA4BC8AULL, 
            0x98BEE0248CE39C36ULL, 0xE23973BE8D2EFA1CULL, 0x1DABEEC6F6C28BAAULL, 0xD30DF9DF9A17D02AULL
        },
        {
            0x27A649AA3E9CBB91ULL, 0xFA2C409ACE73B251ULL, 0x231D103DCC4D1206ULL, 0x4077D94E0F0CDC10ULL, 
            0x784DAE82F39AAA16ULL, 0x5E9B9FFD4DCE5B99ULL, 0xD57BF32195673988ULL, 0x627DFD7B3C0B5EDCULL, 
            0xA3CE1ADD24E71FB0ULL, 0xC9EA495F301CDF67ULL, 0x0CC06F94C385ED65ULL, 0x545E6B97EACD2D41ULL, 
            0xC8B39DD04C04C01FULL, 0x336DB1E94CA5C2B0ULL, 0x5EE1AB7A0771422BULL, 0x308907CC2164C942ULL, 
            0x91E070BC513F6F51ULL, 0xD082BB235B98CFD9ULL, 0xFE64A9FC1230747AULL, 0x9A4872AFFC3E571EULL, 
            0x99C583FB08B9F6CAULL, 0x59E7367B0047AEDFULL, 0xE3860FD3FAA16331ULL, 0x168DC665AD5FCE19ULL, 
            0xD1522E3AC1E1A2F1ULL, 0xDAC0E69F5E1B252DULL, 0x23762A400F5E1160ULL, 0xE9E28C5135A30226ULL, 
            0xF30417F75EC7FA08ULL, 0x6195DA41E2441FCDULL, 0x9717353690290F88ULL, 0x133CB8E4D490B591ULL
        },
        {
            0x050D95CB3FC1153FULL, 0xB063AAD90666D4E0ULL, 0xEF862F90EF856A47ULL, 0xAF5CED443D5EFA7AULL, 
            0x679CBFAB43E5599FULL, 0x3B5535118C1BCE6EULL, 0x1F9E71F333E1B5D3ULL, 0x39371A68A5A5DF55ULL, 
            0x2BD000ACE1ED452BULL, 0x253E769D5A18F033ULL, 0x203A1AC55FC5B442ULL, 0xD4C9ECE1A5C4ACA8ULL, 
            0x7B4B85833F34957BULL, 0xF97241B6A97872D6ULL, 0x2AE1D6F11F80DB55ULL, 0x400B18B70AE74DC7ULL, 
            0x0B5DC7CDBF485ED1ULL, 0xDB8BC6E58AF46AFCULL, 0x0A074AF25CF7BE39ULL, 0xCA5C860F39EAC6A6ULL, 
            0x3BA8CC3DFC5E53F5ULL, 0x3B40A43D887C1931ULL, 0x497B9749723780FAULL, 0xCD2C4F71F2B0F357ULL, 
            0xEFFBBAC0AFF58B37ULL, 0xC5730457ECB6FD92ULL, 0x56371C77C690321BULL, 0x7931EA844BF35996ULL, 
            0x368088A0094729CAULL, 0x54332EA864FB6232ULL, 0x88DE400AEEB31BCEULL, 0x4CAF817BA7A2C50EULL
        },
        {
            0xD5711CD079E6BC25ULL, 0x38F0D5EA3B29A3AFULL, 0x0D50F6956A272AE1ULL, 0xEE50D73CFE0FF66AULL, 
            0x6157B0F929E87F55ULL, 0x71CC8B461214FDDCULL, 0x6C80C0FD647B6DF4ULL, 0x02E183EF82AF7862ULL, 
            0x607303C2690D8C3EULL, 0x31E2662DEE7B06D1ULL, 0x020CA197D1745F36ULL, 0x658EDBD219388357ULL, 
            0x6048D03F9F48E479ULL, 0x37F8503206120D00ULL, 0x65DB86A11895E68BULL, 0x06C8CBEF35D986DDULL, 
            0x1D50D84577C61845ULL, 0xE67D1BB2BC242F54ULL, 0x274691B7F4629F31ULL, 0x8D4A5F6EFDE5AEF3ULL, 
            0x55DC7C59F6EB6090ULL, 0xF799968881730BA5ULL, 0x7715D12FCED35EDAULL, 0x2BACF579B006EADAULL, 
            0x3296AC0302B608CDULL, 0xAF766D4AB3E4C6B9ULL, 0xBDB7D8E531F516F2ULL, 0xB31830EA8D6FDBDCULL, 
            0xB08686A53C2272AEULL, 0x6C6D8EA03829BE8DULL, 0xF846F4CAE56F3D8FULL, 0x1FE7B8EC706396DBULL
        }
    },
    {
        {
            0xA1F0A811535A6E50ULL, 0xBF6BBF0A60039EADULL, 0x043052849470AFC9ULL, 0xCCBA5517F6ADC729ULL, 
            0x55183302D452E0BCULL, 0xCCC29442C3D72DD2ULL, 0xC149D316D9C94AA2ULL, 0x6C570CAEE05167F5ULL, 
            0x0CFE0E35A2BBC11AULL, 0x1E12A9D75B8F4D85ULL, 0x46FC0EDC99BF50A3ULL, 0xF4CE8F6318B455ABULL, 
            0x68267B3F7EF14899ULL, 0xCE8957A827359D5EULL, 0xF070213B2D69967EULL, 0xDEE519F5AD0F6B30ULL, 
            0x5C8FC8E210594288ULL, 0x48AD9D25624003D2ULL, 0x3F715B487C6A0B18ULL, 0xA6366B156830FBADULL, 
            0x418DDB7B5CF9BC3AULL, 0xC7630B67ABF5D99EULL, 0x0AC4E872BBC70706ULL, 0x0A870CB1792622AEULL, 
            0x97B039C51ED5E0EFULL, 0x9A8B022D03B42DAEULL, 0xB33569CFA22028D5ULL, 0x2E694A7CE47E7A8FULL, 
            0x12EECDDB95180178ULL, 0xEB0757BC5B54BF2FULL, 0x527D6F90C42BC93AULL, 0x1C3FF671905A1B58ULL
        },
        {
            0x9E205F056E784411ULL, 0x41AFEBCA997CA8DBULL, 0x7249A96AAB2C7374ULL, 0x9638A1A50F400C79ULL, 
            0xE9FA1AFAF1731BCCULL, 0x7587195ECC773A29ULL, 0xEFD38E33DF58BEF8ULL, 0x78946F2003CD3446ULL, 
            0x3585E46442AC06E5ULL, 0x00BDB4BD1A4CE8CEULL, 0x2CE0851AC3E42151ULL, 0xA6FAB1F168935063ULL, 
            0x5B7F13999D6184D8ULL, 0x6416441F32643F2DULL, 0xBEAEF4EC44F49CA3ULL, 0x9121A68AFE221552ULL, 
            0x10116F4400F5A36FULL, 0x69A6398A307C632AULL, 0x975257284B9C17DDULL, 0x877B4C13B4DC6ECBULL, 
            0xE2D5538EA31616AAULL, 0x895D4081E8D2F2BAULL, 0x9AB7A5AB11422950ULL, 0xD2B56AD99F9FC657ULL, 
            0xA887278CF961D102ULL, 0xB6B6B2429CBA5B95ULL, 0x59AB9AEA2C2D4475ULL, 0xA69302F6381122DAULL, 
            0x30FF3A41D52DD6C1ULL, 0x73810442C4C71A26ULL, 0x9B0255A8FB7CCEE7ULL, 0xB1B87D01B0DF58E9ULL
        },
        {
            0xC30EE3E78A1D901CULL, 0x9FAA3A23C7C67399ULL, 0x7D0F186F98F7D923ULL, 0xABB0D6AE211E9A6CULL, 
            0x34A7D144712A107CULL, 0x60B1177997B36284ULL, 0x01AFF95DE60DEB8EULL, 0xA927D34503AFCC9DULL, 
            0x73D054E2554A273FULL, 0xB0250B3B6E1E6493ULL, 0x239A5EC455974182ULL, 0x6BCFF829A75AB554ULL, 
            0x5DE8A9EB0AA6EFA4ULL, 0xF338AC8BCB1C9D7EULL, 0x6CA12A9858CE1340ULL, 0x6FC2BEB8D6D44D07ULL, 
            0x7734A7A90ADF7D36ULL, 0xCF535CB616A9A860ULL, 0x0D8AFF4BD02684E8ULL, 0x4D254A1600E9301BULL, 
            0x047BF16AB105FBBBULL, 0x952BF12FEC67466EULL, 0x38DA556FFFFED58CULL, 0x71385B1216962614ULL, 
            0xB025C663779FA4EAULL, 0xDB1D49CCFE142BE3ULL, 0xC9F08638F24767B6ULL, 0xEBF003137EF078C9ULL, 
            0x8873E2D1F7E593A0ULL, 0xA92B8A8D80DF064DULL, 0x4C4A118D4E4C2FB3ULL, 0xCCED9AACCA2FA808ULL
        },
        {
            0x7F41E49A91D68A26ULL, 0x3AE60E27A43CCC58ULL, 0xD1AA56975ED63AC2ULL, 0x0762773EB51AE57EULL, 
            0xF4CF8BE01D65C887ULL, 0x02AA01A4E8F7A99BULL, 0x29C67DD7E2F11F1DULL, 0xA60B77F357FBE514ULL, 
            0xF68CB19CE93DC817ULL, 0xA8908C0D69B46503ULL, 0x5FFCA8AA70A11A71ULL, 0xC1851D7594BEE9F6ULL, 
            0xB1F90DB765752D1CULL, 0xD8BCAE85266714EBULL, 0xE813FA7BB9C0E03AULL, 0x388B01CC9818343EULL, 
            0x137F4AAD3883F300ULL, 0xF564078CA035AB54ULL, 0xD8E72FA5DA0B97ACULL, 0x4C9EDA783AE2651FULL, 
            0xC4A368A4C1FC051BULL, 0xE0C0FC4A588EBA83ULL, 0xB83941AC87961D0AULL, 0xCCB71DA38F616773ULL, 
            0x0AA8E42C6EA1692DULL, 0xEFBBA6C1D37A814CULL, 0xDB8BF9CA080E41EDULL, 0xE8C4D680E73A4E35ULL, 
            0x845E184D0F666FDBULL, 0xDB2FBF3A7E8A2E40ULL, 0x5F2FB5315D037741ULL, 0xF96013219AFFC99BULL
        },
        {
            0x710A6B96BC3CA22FULL, 0x757D3D79908B297DULL, 0x4A1624AB577DCC06ULL, 0x5776D2ACFF24B05AULL, 
            0xC2EC276AD7F8C058ULL, 0x6544D4DD4753D93DULL, 0x0462A02078C889EEULL, 0x999B4A98504735F0ULL, 
            0xF8192E6E541067A7ULL, 0x4C7513E087C6562EULL, 0xD54EF6F2EA3A1098ULL, 0xE1AF2DA925565E1EULL, 
            0x40D58B3B3CB200AFULL, 0x05C3F1C94FECAC2CULL, 0x50F081D83855E75AULL, 0x0AAF748F780D3DE4ULL, 
            0x7168EA9D92254C35ULL, 0xC2FEAF8F18F9D658ULL, 0x7B7806196E75EE2EULL, 0xCD022F3ECF4FCE06ULL, 
            0xDD8A4F333598F8F7ULL, 0xFF190A28F3350CE9ULL, 0xBAB5F25E65C54B95ULL, 0x99B0EEA2A4B6F719ULL, 
            0x3FCE7775C8BD9122ULL, 0xCCBB5179E928FE6BULL, 0x462E154A2ABCA675ULL, 0x39CBD46EE207FADCULL, 
            0xB42B08A0B71868D3ULL, 0x39A0B5D1CC64CE5CULL, 0x7C37C1FE7F504FFDULL, 0xF94F4AD49BFF5839ULL
        },
        {
            0x32F10E18FDCCD67AULL, 0x168EB21BD20A4F8CULL, 0x2F0272ED94DBFA53ULL, 0xE0FD2F6D143E48C1ULL, 
            0x6F20E4312E260775ULL, 0xA6083786E27D4952ULL, 0x76F75E3578850CD4ULL, 0x19A5970DF042704CULL, 
            0x297FB8B71FA20129ULL, 0xE3DE7A1AE4B57672ULL, 0x23AD6D3B6D6B02AFULL, 0xF3680301BC2E31F9ULL, 
            0x7C6A65F8A3380749ULL, 0x6A89D03E5EA9705EULL, 0x96CD2C39C52B3738ULL, 0x53C91C0385AEEA09ULL, 
            0x65BF3E2D40FD4E7FULL, 0x75A47FEF194D6F9DULL, 0x32EAAA0E495DAF7AULL, 0x1F63C656DABF9052ULL, 
            0x0ED1B22956E9F929ULL, 0x4D4A25D90DB75FB0ULL, 0x99160F12C1F53F99ULL, 0x297CA36DBFD84820ULL, 
            0x88C1917609F4EF36ULL, 0x884D0F30D2E94465ULL, 0x9C94C8B9125604FDULL, 0x16CFC6C9DAE72CCDULL, 
            0xEF4665CD1DD618F2ULL, 0x42815BB4272FBA1DULL, 0x6934AAB1B0373DFAULL, 0x3760C4D7E8472E6FULL
        }
    },
    {
        {
            0xC53D50A517F96875ULL, 0xF96EAE57D9C4BED2ULL, 0x233D08303EF4E9D4ULL, 0xBA1663DD8B90AEA8ULL, 
            0xD3898D21AE7FDEE4ULL, 0xCDB521BE355AEB13ULL, 0xA7396C1B141D615BULL, 0x56E44C3A094C15B0ULL, 
            0x7228AC084E553F1AULL, 0xD4C39E783CDD9F48ULL, 0x1B99A777C2B30DFEULL, 0x6758520D569F6B40ULL, 
            0x102D3D53B67F4B71ULL, 0xF01A50BA16AD4F8EULL, 0x32B4BAC3F8A3E2DEULL, 0x0B5BBB00FFA51742ULL, 
            0xDB16A09F82ACA553ULL, 0xEB421C45605217A8ULL, 0x5A3058D6F7FF6700ULL, 0xF5E25A281A0E75D2ULL, 
            0xCA3C9FB7F47F2C52ULL, 0x374AE0C376154E52ULL, 0x8F503ECA75C4794AULL, 0xFC0F71CA1AA33475ULL, 
            0x715B8816D2DCA770ULL, 0x76DBE4DB1536C2BFULL, 0xE312B49378480715ULL, 0x7577A477E5A7CBEFULL, 
            0xC85FEEDD11CD15C8ULL, 0x6A42BC5875EA34EAULL, 0x310DCA8DCB73FEEFULL, 0x49078A339FD45AC7ULL
        },
        {
            0xCD0E9251E1E03051ULL, 0x9A33204329A1338FULL, 0x1ABF4AEA52F43B1DULL, 0xDC343070A86B3B4AULL, 
            0x70BBFFC54510149BULL, 0x32EF319A3074CF16ULL, 0xFA3A33A27FC76D5CULL, 0xA88FC8A197390B95ULL, 
            0x03ECF90E8A2CCB08ULL, 0xF536877D12E3668CULL, 0x3E72A491951F9718ULL, 0x1C499BEE9AD2040BULL, 
            0xDA866FFE2283BB00ULL, 0x91AE78EDC0D0D779ULL, 0x770832480194DCC6ULL, 0xA52EFF87C2674404ULL, 
            0x7A7E079773B2443AULL, 0x44CCFB1DAEFFD3C7ULL, 0x15F63F54E078831FULL, 0x3CF009D6344BE328ULL, 
            0x8C2D236271D017BCULL, 0x555A8435512B9E07ULL, 0xAF00F34A36E91480ULL, 0xFCB01F7F1EF07047ULL, 
            0xE1F41DC63EE7ADF9ULL, 0x796962ED90021523ULL, 0x3D5949918830523BULL, 0x6A1862A1453AF7C5ULL, 
            0x7FADDD2077B6826EULL, 0x1DCCDC23C3CE10C3ULL, 0xF93DAC6C18B6F178ULL, 0x7CA57FABE6DF2BD1ULL
        },
        {
            0xA6BE8180919CA359ULL, 0x0BC01658BE673EFEULL, 0x1A6A7288DFCACF12ULL, 0xCDE6E20F02A90541ULL, 
            0xCB7C0079EB19A545ULL, 0x7D6AF943C0631F4AULL, 0xAC59A39222AC0661ULL, 0x4F0F96C86A9A87C8ULL, 
            0x0254B9EEB8F04746ULL, 0x0CA604E63D058507ULL, 0xE11716357C570EB2ULL, 0x0590FABCA67C608BULL, 
            0x385029244D839C7DULL, 0x4740B217C5B232A7ULL, 0x377D220039859518ULL, 0x03D80A97680B515FULL, 
            0xF51CD02A0BF4EDB5ULL, 0x67836F93EE67CE05ULL, 0x24499F4D3E0731EBULL, 0x5FE20595203EBB1EULL, 
            0x16B45A39B5BC9D95ULL, 0x62BD7FB755D712A2ULL, 0x9DC1CAF5821FEB10ULL, 0xA23215359647E0F1ULL, 
            0x187B73E084FCBDEFULL, 0xE32DBB650E4CA8B7ULL, 0x14B22FC8485FC3CFULL, 0x7C556B1EF58F651DULL, 
            0xCEF1E6410C3091DBULL, 0x7599A9DF4859243DULL, 0xEAA639680B6C6A35ULL, 0xD8CBC9F629E1DC6AULL
        },
        {
            0x66AA404D4343885FULL, 0xA4A5853F28820FA8ULL, 0x65625AA9910081CCULL, 0xF6BAB3750A3D2FBCULL, 
            0xC1926B038E6178C1ULL, 0xD076284B7FE480E6ULL, 0xAC6E2D52B895FBFCULL, 0xBF8D68781559177CULL, 
            0xE253F5641531A48AULL, 0x1AA3FCBD7E515D9AULL, 0xBA8A5BF91A68476BULL, 0x85B4F922C6A39B54ULL, 
            0x51E17657DB8B7E51ULL, 0x3B9FCAD791ACADEFULL, 0x9D968D737659335BULL, 0x8FEC9E4084F401D1ULL, 
            0xE1245459B911CDD6ULL, 0x89813734DDCDC6A7ULL, 0xD97B47A31444A6FDULL, 0x05BAF2E4FCA76A0BULL, 
            0x30011EFEE0CA6374ULL, 0xAB1D9E690DD4B250ULL, 0x61EFFA4E1A3907A4ULL, 0xB8BCA9CE09E194C4ULL, 
            0xCB4787F47705654EULL, 0xBDFD74B37460B332ULL, 0xEDF556789289D000ULL, 0x033BB4692F13F152ULL, 
            0x4AA2B5BE7B61BA7CULL, 0x705560DD9A02C45CULL, 0x60ABBDC85B7AB931ULL, 0x76A101A8316B714DULL
        },
        {
            0x6046955FC26BE281ULL, 0xD8AC5262C77ED5B3ULL, 0xA7BE96D1DDD4238AULL, 0xFC8B7E3D3B455B7BULL, 
            0xE94A1F700FBE49FAULL, 0xCF2BD781C4DB272AULL, 0x36A85957CF0D763CULL, 0x205823AD86D20269ULL, 
            0x1F0CD8171B5E0EFEULL, 0x49EA9C351B149CD0ULL, 0x386DB5E5315208A0ULL, 0x55A5089D55A10754ULL, 
            0x9DCCB4ECB7CB544FULL, 0xE483D834C14B457FULL, 0x0C841B022421EFE2ULL, 0x1CB40FCBE948E702ULL, 
            0x9D2F6D243205AC26ULL, 0xB1A6D5FA51B6B3DEULL, 0xECFC3ECF06656887ULL, 0xFCECDAA3CCAC1CB7ULL, 
            0x7942F80C6D7BA1C1ULL, 0x3956B3D836CABDD5ULL, 0x8825CD35FC9B7271ULL, 0xCF49DA6210EEC47CULL, 
            0x295F3D035A4063FEULL, 0x75A104D9F6F2F38DULL, 0x38030FB05B491116ULL, 0x03075B92C8A9D7CDULL, 
            0xA753ECB99E70E6A6ULL, 0x44DE3F2A45062389ULL, 0x57974D18075919BBULL, 0x8449FD54FAC4E543ULL
        },
        {
            0xABE21533C8E52E74ULL, 0xDDC76FA264138544ULL, 0xD40F1D9D9575FD1BULL, 0x88302F1068C58BF4ULL, 
            0x5DF8190B169CA311ULL, 0xF04F2A8E6519BF71ULL, 0xE4A0C2B05A4E2A65ULL, 0x3FB616563003D6F4ULL, 
            0xB25F1DF61A1871B1ULL, 0x45034EA8DE3C4150ULL, 0xCC3842169F222433ULL, 0xFF1A62AB1AB86534ULL, 
            0x0031A65567D691B2ULL, 0xC82A41EF233A8F80ULL, 0x22B4BD3052AAFC58ULL, 0xED715D6B29D19761ULL, 
            0xF3498EA080DEF372ULL, 0x1D086F7ED01BDCABULL, 0xE13AE3335CA05C86ULL, 0xE252D73B449532F2ULL, 
            0x47BEFD8D6902BC27ULL, 0xD8626B0608768EE2ULL, 0xDA16B564F6ED9786ULL, 0x1C344CBCF16D945CULL, 
            0x99E93B72137ABC57ULL, 0x96A893A392859576ULL, 0x2EBBF649BC2A4264ULL, 0xD71CA72663A7B899ULL, 
            0x15F0B3022CCA3A37ULL, 0xD160E71E08D842F0ULL, 0xC768D51C72AB3818ULL, 0xDB19C436861BC801ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseDConstants = {
    0x89EF48D6B8383E93ULL,
    0x10ECBAC8DBC5FF33ULL,
    0xD7A7D9030C33A9D6ULL,
    0x89EF48D6B8383E93ULL,
    0x10ECBAC8DBC5FF33ULL,
    0xD7A7D9030C33A9D6ULL,
    0x93733F74ED54652EULL,
    0xB696B5FFEB9F0A22ULL,
    0x15,
    0x1C,
    0xCF,
    0x5A,
    0xC6,
    0xFB,
    0x3B,
    0xA3
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseESalts = {
    {
        {
            0x0AE9320C65AA3265ULL, 0x40A48AD975970DD4ULL, 0x14C91CCB9B067765ULL, 0x006D88C4278972F4ULL, 
            0xFE707D95FD250FFCULL, 0x80412E35E1338596ULL, 0xCC63DB8603D55309ULL, 0x6B1ED8262A704962ULL, 
            0xEDE9C453FA628E33ULL, 0x878DA083DEA376E4ULL, 0x476555A92B2ECC6FULL, 0xE545023F4BF48886ULL, 
            0xB2D754A34DF1C52CULL, 0x0CE011D814154559ULL, 0x255C8FD0802D4469ULL, 0xC0BA3DE79F5326BDULL, 
            0x2F50E8FA93F2D6C2ULL, 0x5809C6183FC139C2ULL, 0xB7E39A3E267125DAULL, 0x57816738BF5CA6CEULL, 
            0x3229C5CBC63D9721ULL, 0x0CC9571580A499A5ULL, 0xB5E9B702C72265E6ULL, 0x0DEAFAFC23B3B270ULL, 
            0x8D8F4BD10A43AD7DULL, 0xD727B9A8C5D06A80ULL, 0xF3781DD73609277BULL, 0x120470ADA755C1F3ULL, 
            0x779ED83AA507BA76ULL, 0x9626C280DAC268A3ULL, 0xA387A8C79AB64ACDULL, 0x62E84EDB18401EF5ULL
        },
        {
            0x1E2DAE2A0AFE0F63ULL, 0x62ACB9D1F3D483F0ULL, 0xB9D84EDD10ED3895ULL, 0xA6A35C0EC985BAFBULL, 
            0x1D204129AF94CB91ULL, 0xE61978595DA571AFULL, 0x5B8A5363F16F6A60ULL, 0xF3393EEE2D98383EULL, 
            0x9668DCE4373FB440ULL, 0xAABA3A97F14F1523ULL, 0x724D6999637B5C58ULL, 0xEBA3CCE002B51003ULL, 
            0xDDC17E27710C9E8FULL, 0x315B540508596EE3ULL, 0xFA8D087F24D5FBAAULL, 0x92FCAE5EB6BC05F0ULL, 
            0x19FFB5F88D6DD02AULL, 0xD6419A7494CC33DAULL, 0x8B25E7BC4BD95E41ULL, 0x462D301DF410AC27ULL, 
            0xEB6B07F01045B9E7ULL, 0xEE49CC7ADAFEADE8ULL, 0x3D35902BDF15DB48ULL, 0xD4171A593DAB58D2ULL, 
            0xE0AC5B5E165C133FULL, 0x4A9BD06E90A7FCACULL, 0x36C60833806D27C5ULL, 0x63B252577E6B7E72ULL, 
            0xD1F3B381BFC7BF0FULL, 0x9C7C79185604A7A8ULL, 0xB93ECE554BFC48B4ULL, 0xB12426138313D1A9ULL
        },
        {
            0xDE279E72BFABF075ULL, 0xFE069267FDB3490CULL, 0x1448A014A83DF48DULL, 0xE7A29933A40A82A8ULL, 
            0xAA2044A348F86910ULL, 0xB4B3492FBA08D3ECULL, 0x6DD6A0116B33A78EULL, 0xCC0C72226C1AA448ULL, 
            0xD81D536AB1B49D02ULL, 0xCD1CBE066ECCABB9ULL, 0x4C0B6A8B88C839F9ULL, 0x26112E2A2AC4822BULL, 
            0x69689BA408D9563EULL, 0xBFB3BA83DEA6F3C8ULL, 0xF6E01B320330B9ACULL, 0x8E0A1A829B9599E8ULL, 
            0x74B79E3ED677D242ULL, 0xBE0521BC7B669D58ULL, 0x1216A766DF93E221ULL, 0xDD0CE0889B8886BAULL, 
            0x35ED2743CA1FADC7ULL, 0xE6727D124F6A9928ULL, 0xD3D4906A0259DE40ULL, 0x2767D7F6E13DDA83ULL, 
            0xCBBD3C1815C5AD90ULL, 0x2A871378E0C9188DULL, 0xF11C025466AD187FULL, 0xE48B4E73AA2D2378ULL, 
            0x0B5FB6F7FF31DADDULL, 0x4C64F17B5485B13CULL, 0x501B6D9C356CDAF2ULL, 0xDA7C8EDD4A1D41DEULL
        },
        {
            0xBABA001E0756341EULL, 0x11DAF31C6262CD62ULL, 0x0FA868B4A61A2E5EULL, 0x9510BD8B976233CEULL, 
            0x5C0AD3EEE49BE8B1ULL, 0xDB108C27BA279FBAULL, 0xB99CA7E92B9038FFULL, 0xD93F9F01BC1AE3AFULL, 
            0xF219C2DE1763E523ULL, 0x643D6D0F257CC432ULL, 0x07EFAA693D5F4346ULL, 0xA7C369145A8A0288ULL, 
            0xFEA93F745D7D5EFEULL, 0x2020EE46B027675EULL, 0x1E3AA9E0200CCD88ULL, 0x208EEBFB24468D46ULL, 
            0x150772DC75188771ULL, 0xC8CAD513073FDD34ULL, 0xCE989D2F7CF56721ULL, 0x39FF2A778760D261ULL, 
            0x0B72102884D14A2DULL, 0xE194D4144D8F8F45ULL, 0xD436F545FF11D66FULL, 0x6D46E1F4E04BB7FEULL, 
            0xDA156AC0F381060FULL, 0xFD7FB250673075ACULL, 0x4AC4B568292DBB07ULL, 0x0ABD14986831677DULL, 
            0x354106C84E98E7B8ULL, 0x9EB10CBA1534CF65ULL, 0x349D2A50C86FC489ULL, 0x9F140E6D5A0F4CA3ULL
        },
        {
            0x47C0D319978E5B9BULL, 0x24C43DBEB2C5FB59ULL, 0xA2EB4EAD71ED62F0ULL, 0x7998BDB22EF1E065ULL, 
            0x3EC80C277D6C6DF4ULL, 0xD4A32C3FA82293FCULL, 0x1207AD4EDF954200ULL, 0x0DC572EEE9305955ULL, 
            0xF51FD51D04495BD2ULL, 0xBF90C92E3DACD52DULL, 0x5F9124F5594AB3FCULL, 0xF0227AA737E1AD2FULL, 
            0xBAA3C823644FC4E2ULL, 0x1A252DEF43096205ULL, 0xE7DBF5DF501CC4D6ULL, 0x01BDA7FC41C964F4ULL, 
            0xC51442E1DDFF2E76ULL, 0xA15D3B505AC5FAB0ULL, 0xAF9E314FCEC44190ULL, 0xFB753B0AE27A5F46ULL, 
            0x4B342888C1985707ULL, 0x84A4C56F9E364CB2ULL, 0x732BC4096A4CAF22ULL, 0x6D7CF9240D1482ECULL, 
            0xA8E0E6E3B63B7EE2ULL, 0xE6A50D54F5BBBEA4ULL, 0xC58884AE3099A82DULL, 0x5280024919FBBFFCULL, 
            0xE9E993DBE3C13DBEULL, 0x37A09A42E0DF02C0ULL, 0xDA285C195F6C7828ULL, 0xB8A2BE77362C3DDEULL
        },
        {
            0x83B13A993D062198ULL, 0x95116337BA66287BULL, 0xC63B5B272815253BULL, 0x68859A6402272B63ULL, 
            0x913A6EC595F3BD1BULL, 0x1D264D3408FABCECULL, 0x4D9688FB589A2F6BULL, 0x120B0E698F1FC920ULL, 
            0x3DB0E47A9817C880ULL, 0x693AACA014237631ULL, 0x7F05839B420711E2ULL, 0x7997F19637E339D3ULL, 
            0xA1003BCB671FDB28ULL, 0x7BB92ACD9AFB3723ULL, 0x174185C5BBFB7CE1ULL, 0x546998DA3B673D7BULL, 
            0x9B2AAE972F6927CCULL, 0x249E12EE728117DCULL, 0x355228BD4FE43956ULL, 0x11FCB0B424EB5221ULL, 
            0xA1777C9512597DA8ULL, 0x462420ED71ED3EA8ULL, 0xA3886AFA8B013D2EULL, 0xAEAA09E30D9DB107ULL, 
            0xE91D07D37F492DB7ULL, 0x5BF489944DC913C4ULL, 0x4E9BF5E5391D5588ULL, 0xE14698E6047FEFFBULL, 
            0x551FF27D6688B7B2ULL, 0x734AADD1094B975EULL, 0x26B9A500DF4DDED3ULL, 0x926145E73BCE035EULL
        }
    },
    {
        {
            0x2DBA88FB75B67351ULL, 0xE35AE68F5E444294ULL, 0x609493BDF47E86E9ULL, 0x64FD35383E4B0981ULL, 
            0x60D2E0BC9423EC89ULL, 0xAAA173EDFC5842A0ULL, 0xFA0C8E44CDED5981ULL, 0x3C4C1F1BC51F17F1ULL, 
            0xFE77DEBF677EF770ULL, 0xBC544CADF0B445DBULL, 0xC7FDEC4992D0C538ULL, 0x92609DE06A268FE3ULL, 
            0x26A3F886369DEF2CULL, 0x85AFF475603941E6ULL, 0x80C2F5BFB99E389CULL, 0xDB05C47F732FFB0CULL, 
            0x5A34C4EAE4F31A1DULL, 0xCB229F8CE28AF3DFULL, 0x90ABBDEE2B353F1EULL, 0x971D48C9EB3CED36ULL, 
            0x5621A502F22ED366ULL, 0x933D5B28BC2AF4C5ULL, 0xC54911E2DAD5D41DULL, 0x984D81336991180BULL, 
            0x8CDCD20DD785B4F4ULL, 0x31C30F288BB5689AULL, 0xEBE406268286E520ULL, 0x93B597105A8105CEULL, 
            0xC6B08EA54D9294B6ULL, 0x0A0AC26BA8BA497BULL, 0xADE2E2233FCA3CCDULL, 0xDC2CF874D8E984FBULL
        },
        {
            0x2EE698966F918B2AULL, 0x4C1D71CAAF6F5AD9ULL, 0x2C860B1EDE4B57ACULL, 0xB13CC726EE40FF81ULL, 
            0x19D4591D512F0BEEULL, 0x1FAED96C3EBBF04BULL, 0xA69387DAC069C5DDULL, 0xF460D06CD77FDEF4ULL, 
            0x93F2A1A3F83C85FAULL, 0x72B485A231540F2EULL, 0xC30F553FB64E08F0ULL, 0xE70B927850DE6D0DULL, 
            0xC6F1AB12C325F232ULL, 0x34327846CC0453F8ULL, 0xF3C3796B930DDC61ULL, 0x49A12FD78FD801B8ULL, 
            0x40F5FD77BDA4EA55ULL, 0xEA8A2E01734B1253ULL, 0xCA25D63151CEEB86ULL, 0x5A1DD0720FF417DBULL, 
            0x4C5DF2936493D210ULL, 0x2CBAC8302E808205ULL, 0x7536E0785E409A80ULL, 0x842FA85D6FCF0FB5ULL, 
            0xE0A96BD30750999AULL, 0xB17631379B3864ECULL, 0xA32BBBE7A7A75CFEULL, 0x0A412DAE71441128ULL, 
            0x04A429B101A8F339ULL, 0xE1C0F747FBE2A310ULL, 0xF4A3628F1DD32341ULL, 0xD98DC728994BB74AULL
        },
        {
            0x61A6499FF2D1716FULL, 0xB72EEB085DC68E4BULL, 0x09FF35D71013034AULL, 0x18FB8EFA7F9E44EDULL, 
            0xB8BE9B412AFBDDAAULL, 0xFA861241044BC68CULL, 0xA0153CE7D71EFD45ULL, 0x8869AE892BC5637FULL, 
            0xF69A6A576AE2B2CDULL, 0x78FF22264C0BE6F4ULL, 0xE92423C19BD260F4ULL, 0xF5744114B039FAB8ULL, 
            0x4AB11C501F055FF7ULL, 0xC4D0F63F7F94AEE3ULL, 0x8C2F1987C6BAF208ULL, 0xE50AFA3BD0D7F72EULL, 
            0x7EFC2D56041A22BDULL, 0x71E599BBCFC5DF06ULL, 0xEDF348EBBE1A2CAFULL, 0x2E488A87D12A6FDAULL, 
            0xE5958AA3527D84B5ULL, 0x337E7C56C0C600F9ULL, 0x56BF32D70523A631ULL, 0xE0FF6EF64C0CC8F1ULL, 
            0xEBF1308038D61C30ULL, 0xA8A3E15DF220E954ULL, 0x97CB38BC5179BDDAULL, 0xF7D91CC65A26E31AULL, 
            0xB884BA4A8C782C4EULL, 0xE84BB8ECE5704EC9ULL, 0x29E97F5F16333BE3ULL, 0xF76B685A0D3501E8ULL
        },
        {
            0x29DAFF89ED58B307ULL, 0x53E21214434F2336ULL, 0xF44AF45B0E3A20FFULL, 0x91255E89FFACBC67ULL, 
            0xC9508C9080DDD2BEULL, 0x48A9E87EFF9D5F1FULL, 0xC3A9645139275475ULL, 0xD23E41E1C4C569F6ULL, 
            0x7E3A082E107FA92CULL, 0x4427F8660043A6CFULL, 0x3C77515FD224A5B1ULL, 0x80EC2A4694636EFFULL, 
            0xA5017272A0094F14ULL, 0x3540A0F6C9D6F07AULL, 0x51BAF2DFB5E14DEAULL, 0xCEBF9D951811A16FULL, 
            0x26F88F6D7B8A5D1AULL, 0x47DA347FCD5C4883ULL, 0x3F9EFE3267FCC2D7ULL, 0xCA8A839A112B92E0ULL, 
            0xF0FF82D809F0E57FULL, 0xAF44F44921715FC2ULL, 0x164BAD1F00BB2AC0ULL, 0xB2FA84ECCA498E91ULL, 
            0x0279C7A65DF8C7EEULL, 0xFD58B1E9257BAA0DULL, 0xEBB4CF96D0FC6F82ULL, 0x232127006F716D25ULL, 
            0xF00A680B43B4333BULL, 0x519795D5C9A925E4ULL, 0xD8D8690A42C04AAFULL, 0x6B86788F3C3F9D25ULL
        },
        {
            0x327A654B912576BAULL, 0xC14026C0D72A8C51ULL, 0x5C365B47CDD27E0AULL, 0xE04848514540DE79ULL, 
            0x2A1D299C52D8580AULL, 0x4CAF847D829C187AULL, 0x799C935CFC370C59ULL, 0x3B5C430E26053363ULL, 
            0x33D813D6422C6E60ULL, 0x94B72A6C48C4AD1DULL, 0xC13D868D54BC0E63ULL, 0xC3FD00D3A13B951BULL, 
            0x0B93334ACD1B70DAULL, 0xDDA389783747F2FBULL, 0x89DF4AED8709DBD9ULL, 0xBBECA8929A2EE843ULL, 
            0x07D7197613F85E6EULL, 0xC397B2469686A241ULL, 0x94990BE50BFA1F28ULL, 0xD380147CC54BB331ULL, 
            0xFF129ED03524927BULL, 0x1E561D971668CFDAULL, 0xEFEECE5156624A57ULL, 0xFD3437602CDDA788ULL, 
            0xF39EC4DAA91CF167ULL, 0x91F8D10D9A39B0C7ULL, 0x08527DF6F56AA139ULL, 0xF0770433F1E372FFULL, 
            0xA3FAE937F5123FB7ULL, 0x6C54B24C9141E053ULL, 0xB695C9097D019E02ULL, 0x91009DDD49192694ULL
        },
        {
            0xF017CCC3CDA88AD3ULL, 0x4865AAD65C08A00EULL, 0xAE9B91AD376D0185ULL, 0x2EAFEA1AF0C5E4A0ULL, 
            0x01FCF2ECC60F46B9ULL, 0xE1CF9E76C29DBD63ULL, 0xF2CDDED78D77EF6BULL, 0x152921376674A4B3ULL, 
            0x441684C4843FA1E2ULL, 0x1D275D944253D6F8ULL, 0xD3F1C7E29712FFBBULL, 0x559B5C8440D8E775ULL, 
            0xA31CC184E721B7A4ULL, 0x842A55179863F386ULL, 0x78DF8CB155825DF5ULL, 0xE0B07C9BA8F6F7CFULL, 
            0xDA3B12CD8BAA8FCFULL, 0xABC86D694410F828ULL, 0xA6E288AAC8B7A869ULL, 0x6FF28EC4F7BCF35EULL, 
            0x4F6838B8E825FFE4ULL, 0xC1E641E4F0A65D9FULL, 0x9D6BDE6EDDED6A01ULL, 0x2071B3E44B8F6480ULL, 
            0xF571321838E8A542ULL, 0x136E6F8CA570E269ULL, 0xD9DF795687E0D708ULL, 0x17D5E2942B6B939BULL, 
            0x0E2C9A1837EB42B4ULL, 0xD3F6C9C404AC3A07ULL, 0xDFAC751A2BB7177CULL, 0xDE43DE0D7EC2D4F2ULL
        }
    },
    {
        {
            0x54ACBD377B799214ULL, 0xA3838A7D45B051CDULL, 0x53CD0B11A5294295ULL, 0xFDE29C67440B1FAAULL, 
            0x8E8CD82D989D7D43ULL, 0xDC7EAAFD8D83B2A3ULL, 0x9354FB3D67E28E51ULL, 0x3C72D8C04AC67F1CULL, 
            0xB74165B3812583F8ULL, 0x1C6A02450D7D1063ULL, 0xD6A6D111EF03807EULL, 0x7E3D5D774CE38333ULL, 
            0x92A889DDC0AE598AULL, 0x8B8B510083C3F242ULL, 0x593E76BB5FA81E12ULL, 0x7E93A36A589BE58CULL, 
            0x5A0E24ADD1A8FAA6ULL, 0x6B1546D273DCC24AULL, 0x2F530253D90D33EDULL, 0xBA4F3808B31D076FULL, 
            0x850CECCC47FAA243ULL, 0x55E81299DF8D1F98ULL, 0xA7A8E8777FA79328ULL, 0x2C203B9787DC5E88ULL, 
            0x7A929D9127CD9C71ULL, 0xFCEBF3C572A2FA23ULL, 0x137CC2A690D1B1AEULL, 0x4CFCC8691E795F81ULL, 
            0xE902145659107D02ULL, 0x05A945D7C6F241DCULL, 0x847A9CD80F7651C8ULL, 0x2714108098F798B7ULL
        },
        {
            0xC91405E859F52749ULL, 0x2B9AB6F24FD38AF0ULL, 0x4792BB1DDEFE81C6ULL, 0x34ADB5690EBA1ADEULL, 
            0x647DA43422942E71ULL, 0x253934FEEB89AEC0ULL, 0x06545D4214165D6AULL, 0xCE7B1F4D2EBE13ECULL, 
            0x9BED3199532F69F8ULL, 0xF66369B4C5797042ULL, 0xDC6FE78B06E6A427ULL, 0xF6398702A317695EULL, 
            0x4CCE977C5859C89AULL, 0x1E7277D9DF36D491ULL, 0x9C5092DF67B656D6ULL, 0x1466CDF4A501B2E4ULL, 
            0x45260F21C5B58171ULL, 0x6BA708AA555100E5ULL, 0x377A0F09A97E47B3ULL, 0x68A22D3317D85CBFULL, 
            0x0CA2D97DD3A1C65FULL, 0x55E6C7CD6CDF65ABULL, 0xC335E95A09A309FEULL, 0xD021D8087AC3E906ULL, 
            0x94628D642E1B7349ULL, 0xF5E2584DC4ADF250ULL, 0x1795A534D0E919B7ULL, 0xD1DF6B86409E3B73ULL, 
            0xE7503B14B5C44FEEULL, 0xD3A6550AFAF892F8ULL, 0xC6DBD746E57020ADULL, 0xEFD876BE16B07F5AULL
        },
        {
            0x08F197B0ECE8E2D6ULL, 0x99982BEAACCCA4F7ULL, 0x7B12F737D2BC8BBAULL, 0x3C2292D23FD6721BULL, 
            0xCE5CE8DA8F5D5D09ULL, 0x12CDCEE8F75D72F1ULL, 0x1C4D9DF2C07FE1A3ULL, 0x0BA9E9BE7086E8AAULL, 
            0x050E3C7E7061F55BULL, 0x9DDC78046DE8F614ULL, 0x8DAEA2EEEF6E17C5ULL, 0x3245B38B3B279E44ULL, 
            0x4A11C49F8C82AB0AULL, 0x92289B65EC902FEDULL, 0xF26B199F8403264AULL, 0x1C93FFADD3957994ULL, 
            0xFDB2F8C5C4F810F7ULL, 0x2E7059BDDDDD0E76ULL, 0x5081944F1C20D7F0ULL, 0xA409142D98D8E90DULL, 
            0x6A5372153C75D2C8ULL, 0xAE612F7053362094ULL, 0x93C1AB495903FB57ULL, 0xC3AE18224F6BB145ULL, 
            0x53C274E375323DB2ULL, 0x6F56BC86E99FCDB4ULL, 0x283A28C4B6753E46ULL, 0x610D525D09032B37ULL, 
            0x059814B3EF73F4C4ULL, 0x85351EE8E20A0162ULL, 0xC0932E98C546DB54ULL, 0x803A96A1DD441658ULL
        },
        {
            0x8CA71F5AB7A865C3ULL, 0x383428EB9E19194DULL, 0x1DF84E78CA43E098ULL, 0xFA4149A8A03586DBULL, 
            0xBDF9012AD92F96B4ULL, 0xBD4B6D20806CF937ULL, 0x3B43CE24F59E9A0EULL, 0x163B39916A0B71F1ULL, 
            0xD1BAD96C3D099C26ULL, 0xAFC2129C2FD75531ULL, 0xDC1794CDEB0623EFULL, 0x225CFA4AA58B09F8ULL, 
            0x41EC36C386A2D3A2ULL, 0x7B714C4D2A3AB01CULL, 0xB686BB7AE30316E0ULL, 0x190ADF30F4E062A4ULL, 
            0xA2229D17912A0E32ULL, 0x8BA9BBB1343E395DULL, 0xF5E24632FC09649CULL, 0xC8BA97C62CC55AF9ULL, 
            0x273E8757B6A18301ULL, 0xA62C280E23E2DC13ULL, 0x7BF2B9ADD24B76F6ULL, 0x8D9D0051BE4C2A14ULL, 
            0xC50F89C4F3BCAA7DULL, 0xF138260F697DE588ULL, 0x164BB08D8890EF42ULL, 0x7D85A24356E945D1ULL, 
            0x273A3601ED0134D0ULL, 0xEBB623D46EEB3DE2ULL, 0xB77A97094821A482ULL, 0x6ADFC2F6D602E9D9ULL
        },
        {
            0x963E29CE0685655CULL, 0xED5918D94942C03DULL, 0x2938FDF09D3AAC5DULL, 0xD34571E4A6208721ULL, 
            0x5DAAF3858A971C2FULL, 0x530A8270287707F8ULL, 0x8CDEC78363E2024FULL, 0x2FF63952BF4E9FECULL, 
            0x72A42BA241B1D2E4ULL, 0xC5BB9759CAFFB361ULL, 0xF1F3DF46F57D3E02ULL, 0xEE48D4F43A8991D3ULL, 
            0xA30E20AE3A0C6217ULL, 0x5A4F634D4BFB84D6ULL, 0x712EB90989BF683AULL, 0xFFB536F433F1279FULL, 
            0x6D25722137F32686ULL, 0x2E68B9F54286454BULL, 0xF2E30CAA7672F5B5ULL, 0x7624275F09749FAAULL, 
            0xF9A98341ADD90093ULL, 0xDC75D87BEA109177ULL, 0x4727A213B55DA034ULL, 0x6FFCF620D48FDBDEULL, 
            0x98D16F8A4EB03CE9ULL, 0xAEFEE01317AFE979ULL, 0x4C2822115BA779B2ULL, 0xDAE3765E75D67D14ULL, 
            0x98B7E5F388785B09ULL, 0x610B7E281E3C28DBULL, 0xFDF73924865D209FULL, 0xA9CD13C2EC28EA81ULL
        },
        {
            0x1E674004266FB946ULL, 0x0E3D86E7436A869CULL, 0x3977E484C23706C2ULL, 0xC4E76328508506F3ULL, 
            0x7EC0350B1A1B79D1ULL, 0x28969D0B3E2CA337ULL, 0xBDA4EBABEAADE6A4ULL, 0x611BFDBCEDBC09DDULL, 
            0xE18B2709FF8F504EULL, 0xECDB68E175336187ULL, 0x0A5E8A9DA2804BD5ULL, 0x7E981CA1DF742BCDULL, 
            0x7896C72D57201169ULL, 0x0179D7DF94F03A81ULL, 0x6B18F981F460AF49ULL, 0xD0258C7F7C7AE84DULL, 
            0xBC2BE438186F06C1ULL, 0xA2DDE58A2E76EFE0ULL, 0x2E345CB56231F80BULL, 0x279345D88736659CULL, 
            0x8F8C1FB158B8D9FFULL, 0x267CDF03C50F8F7BULL, 0xE86571EBA905F3E6ULL, 0xEFEBF2E12C65F0CEULL, 
            0x7FCA1D4BA1CEEC96ULL, 0x582365D3199D40B5ULL, 0xD705D75D2907F91AULL, 0x1A7405A0A0F517A0ULL, 
            0x6815AB5C963FCB96ULL, 0x63B879050D98E88DULL, 0xFAA4CF6E79DCA39AULL, 0x6EF942EB8701CBFAULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseEConstants = {
    0x6E981D6A5E7C5158ULL,
    0x05C02D6D35EF7FC7ULL,
    0x43AF7BDD82AC713EULL,
    0x6E981D6A5E7C5158ULL,
    0x05C02D6D35EF7FC7ULL,
    0x43AF7BDD82AC713EULL,
    0x613DCB58B765CB5AULL,
    0xE82BC593A0D05D34ULL,
    0xFB,
    0xC3,
    0x01,
    0x68,
    0x16,
    0x4D,
    0x7F,
    0x40
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseFSalts = {
    {
        {
            0xAC7E5FC80A2F5536ULL, 0x6BA4819FFC337D63ULL, 0xB012128E99C15A95ULL, 0x1E67C7DFAAFE7E31ULL, 
            0x5304E8B87E2208A8ULL, 0x3099FBA7C9224951ULL, 0x24593C555A65A7EFULL, 0x93827B66F80D2342ULL, 
            0x5240973ACA7C8A91ULL, 0xC7BCBDA1DCC064FAULL, 0xC3FB6C587331EC77ULL, 0xF5CE0543E5031879ULL, 
            0x6DCFDA6F3B07AE4DULL, 0xD2ADAE4A3306DFAAULL, 0x8ABEC72FBA87A4C4ULL, 0x28A02C78DFD1DEA2ULL, 
            0x8C085795E58C0193ULL, 0x79F98266048171B7ULL, 0x54D334B5D65A7F7DULL, 0x2516D3665F177206ULL, 
            0xF38C5686E1190C31ULL, 0xE5054D24654443F7ULL, 0xB1D164A6543A2B37ULL, 0xB20C93EC08143DECULL, 
            0x50D0582D37F8D89CULL, 0x8DA2A6DE28C6F15FULL, 0xAC7032CBF3AA3329ULL, 0xFF52C4B12774DC65ULL, 
            0xC3B6F384E1DD49A2ULL, 0xACCB5B7B88D03AD5ULL, 0x03F41E3670EE0AF2ULL, 0x6AE2A2BF455A2787ULL
        },
        {
            0x713F1E82EE0A879FULL, 0x3A154505FC977521ULL, 0xB695B17B22A6D767ULL, 0xFF6A73BCF110FD5BULL, 
            0x02BEAD5CCCBFCBB7ULL, 0x696918D5BF0F418EULL, 0x63E45211BFAC810CULL, 0x057E29DF0BE4B642ULL, 
            0xDFD1902B20305B5BULL, 0xEBCEFA8C01B15CF1ULL, 0xFC88E306BCFEBE53ULL, 0xF86F6F60ABD6BD7FULL, 
            0x0B04933281BA4415ULL, 0xE42B09DF905ACD55ULL, 0x17E83E9FC545BEA0ULL, 0x31B17B7D1A7B5682ULL, 
            0xF2C6CB7C3D13A6C6ULL, 0x064CE417704F875DULL, 0x853DACB0577943A6ULL, 0x38DE0F5332F24E54ULL, 
            0x73E9DBB8F58B2A85ULL, 0x913D21D7EFD599D0ULL, 0x69B9B4351C82D05FULL, 0x2507707065898B83ULL, 
            0x4E5D1621A689949CULL, 0xC883ABD94E33FA55ULL, 0xDEF14BF97F1D3441ULL, 0x67220EBB9825C61BULL, 
            0x10916F9FD94900F5ULL, 0xC42AB39A194F873FULL, 0x9576738818FAF9E0ULL, 0x0FD741E1C30792E8ULL
        },
        {
            0xACF52398452015CDULL, 0xCD4019E0A7BDBD59ULL, 0x9A04D708BF1D02D8ULL, 0x1700BC4B69CA9AF9ULL, 
            0x1295E6A2A7763462ULL, 0x4390E0E21EB586C9ULL, 0x1991C8FEFA23D284ULL, 0x831777530AD0DF5BULL, 
            0x834D069007869181ULL, 0xF85FC9EFDAD59CFCULL, 0x3DC0B3BBA4EE549AULL, 0x211E56A0F9C5B2D4ULL, 
            0x97ED630D0FC323AEULL, 0x9600BCC1AE515635ULL, 0x8CB0AC6845BDEA50ULL, 0x618A6BF708230321ULL, 
            0xF5639166924AF340ULL, 0xDBDD544CF12DBBA0ULL, 0x818A097856FC4215ULL, 0xD47FD31BD44B54B1ULL, 
            0x5CB11B8DD63E6F14ULL, 0x2DCC08C08125D473ULL, 0xB2D5EAC0872F42E8ULL, 0x766A99C75A5650F4ULL, 
            0x5578FB399297358FULL, 0xCC9EDC52D6924072ULL, 0xC1E9C32E9F040E3DULL, 0xBC65F7528F3BD32FULL, 
            0xC405ED2609B9FB49ULL, 0x385865AB6B131452ULL, 0x892006DDECC2B635ULL, 0x586ACCC71ED5E95AULL
        },
        {
            0x791794F017F5A94FULL, 0xFCDC696E40C8107FULL, 0x89532C281199A526ULL, 0x5178CB0E8FE3D250ULL, 
            0x1701FF252AE2B7CDULL, 0x5BA61D35948EE288ULL, 0x0063B4BCD353ACC2ULL, 0xF386D1270F2FF1F5ULL, 
            0xB06D300CED19E9CDULL, 0x82C78D45E5368254ULL, 0x89EA7AB3F46C2274ULL, 0xC94444B2785A7C73ULL, 
            0x8CB12175F1517672ULL, 0x83BCE7C0E23F736CULL, 0x4726C67C9C3B7DA3ULL, 0x242920928659DF5DULL, 
            0x2A0C4A1DD7EDDAD6ULL, 0x23854A3CD55B34DBULL, 0xE1571B367AD99465ULL, 0x7F911A979F74912AULL, 
            0x18530D6ABDAD9F22ULL, 0x28A294220F4C2F0EULL, 0x7B6D94ADA677514DULL, 0x07769D3B36A24D2FULL, 
            0x5E34D2F9D60C94FCULL, 0xB75B436D296AEB28ULL, 0x4F79010A22E326EBULL, 0x998F2A7B3FD68B37ULL, 
            0xC50EAC57D72A4356ULL, 0xCA85B946F1DEB7A4ULL, 0x152724B635C1E20EULL, 0x2FC59336832F1C83ULL
        },
        {
            0xBF7743F05448393CULL, 0x9DA0E7A7C9AE952BULL, 0xBEA8402E32445594ULL, 0xBFC0ED947D58443BULL, 
            0x636851804E65F737ULL, 0x38B0CE1A3F83CE4FULL, 0x5BF74763812D2EA3ULL, 0xCE2C722B57496AA3ULL, 
            0x4DA2C68211DD5065ULL, 0x0925431279FB337DULL, 0xF6B0473705126911ULL, 0x50B4CD40C891338BULL, 
            0x2982D6C776A3FCD5ULL, 0x55F15E2529753AB3ULL, 0x131C7C66C7E9D54DULL, 0xEA32FB0EB5D701BCULL, 
            0x1F5062865A3F509DULL, 0xCD329CC5DFA65F7DULL, 0xBF4A208262B197E4ULL, 0xBF6E475A65C47811ULL, 
            0x4D1F5F46071A71B4ULL, 0xE1FC8EED21EFBDDBULL, 0xBF5C2E142EC994D2ULL, 0x7E57903AC01F095FULL, 
            0x2FD163A9ECA93DBEULL, 0xE8A415583ABF3A5DULL, 0x05999FD7CD4488DFULL, 0x8CD5902F6A707E6BULL, 
            0x65FF5A6F95BD6357ULL, 0x17D32577339A95CCULL, 0x487AF124C8D11360ULL, 0x0A3EAEF82E1285C2ULL
        },
        {
            0xA85F9807CE12D6AFULL, 0x3DD283DBDE170110ULL, 0x76DD517CC6680792ULL, 0x8AD287C004D272CDULL, 
            0x462481B4AFF98650ULL, 0xCB385C172857BAC5ULL, 0xF25082176546BD84ULL, 0xBE43B676F679CB19ULL, 
            0x09C106EA2CDB4C19ULL, 0x07F43552792C9C74ULL, 0x2C468B6669303ED3ULL, 0xA5A546BB2F93C4E6ULL, 
            0x1D564160EBD1DBC7ULL, 0xFC8B0EE9478F668DULL, 0xA74E3A57E02B8602ULL, 0x3AAABED95424799DULL, 
            0x50FFD5C799B61D82ULL, 0xAE6E0B18F6C40606ULL, 0x75F38E21F60207E2ULL, 0x21C80023DC3F942CULL, 
            0x27C18744870999B1ULL, 0x4E7840D42275DD98ULL, 0xB4E273F1D9BBDDC1ULL, 0x0C6678D6BDD69278ULL, 
            0x314224C4C515FC5FULL, 0x30400C46E7A552D0ULL, 0xFEB564073EB28641ULL, 0x86CFEF129D07E240ULL, 
            0x82FE5D00B7CF06A1ULL, 0xAFCC845F96CB3C37ULL, 0x99AA1BD210CBB517ULL, 0x822469FBD0799639ULL
        }
    },
    {
        {
            0x57D12A8E72ED3844ULL, 0xCE56AA1DC35A6D98ULL, 0xAC9FF6EC1C1E7488ULL, 0xBC9AF249888C092BULL, 
            0x3D46BB4852AA0F70ULL, 0xED43AE087BA9512AULL, 0xC812AF58434EE347ULL, 0x32194E40FE586362ULL, 
            0xA0A0A2AF880B60E6ULL, 0x98CC929EB4ADA62CULL, 0xE74E22640AB16A2BULL, 0x777DBDB0BCD765CFULL, 
            0x797A026A8ADD24A8ULL, 0xCEF5D05CE462D7B1ULL, 0x3D90549D4014B06AULL, 0x576D5DAF65E80891ULL, 
            0xB7E2CD25F7585F39ULL, 0x48FDE4212FD6DD12ULL, 0x52F85411F8561440ULL, 0x0759C422392ECEECULL, 
            0xBA8E4688233E51A0ULL, 0x4BA96E0007B36EEBULL, 0xE704DF4615EC460CULL, 0x6DDE2E18D034F21FULL, 
            0x860F95B689D5AE10ULL, 0x91E110B62E95EB1BULL, 0xBE93CBC9D0D752A7ULL, 0x7EFDA28341CCFDB4ULL, 
            0x94E718A33AACB7EFULL, 0x0D37E6089867E903ULL, 0x1319E3B77D80002CULL, 0xEA45514DD72F7BD4ULL
        },
        {
            0x1A9A833BCE2325B9ULL, 0xA2AF46FA72E72CBCULL, 0xB1AD11CEF4876B4EULL, 0xCB450199C6EF68CDULL, 
            0x124BF42A40D2BD0CULL, 0x9A107F3CD02B2F58ULL, 0x5DB671BC6A04DFD8ULL, 0x50F70199DA46C8EAULL, 
            0xBC9580222A3D4523ULL, 0x6630C5099921B467ULL, 0xECEF0B5BC8A34EBEULL, 0xB10B9B9062897A9BULL, 
            0xCA605C7F91886889ULL, 0x95F8FB8D801DF27BULL, 0x54CA5285A765411BULL, 0xA385BFA1C4BDD88EULL, 
            0x5851B471FF0ECC7BULL, 0x1238E642FA58438BULL, 0xDB8E0BB12861D5EAULL, 0xCA955AE3A69FFC7EULL, 
            0x2EB1C192CD0DEFF2ULL, 0x2AC94AA834AEF18AULL, 0x3E7ED24FC735D3BDULL, 0xD9A54F6FB787F1AEULL, 
            0x3778FF260B5A7B3BULL, 0x6C4B2E78438140EAULL, 0x32D5335BE1293304ULL, 0x4AD18DD7BCDFA7A8ULL, 
            0xCD45FD5F2CA46AFFULL, 0x81434CE24B8315E9ULL, 0x49EC8FB9E5968180ULL, 0xB0D045C07952AC74ULL
        },
        {
            0x5191F5DA0BA66F00ULL, 0xCC57885FEF363292ULL, 0xF76A287A2CF99BDDULL, 0xECCFE00314F97E64ULL, 
            0xD1858C0909ED1C35ULL, 0x53BCB9768FA7F41FULL, 0x69367771C633299DULL, 0x59A4D01472C8EE39ULL, 
            0xC3C3DA731B8C9887ULL, 0xB6714B2A3ADD4B47ULL, 0xA03A61516FE29FF9ULL, 0xC799208AF010C3C1ULL, 
            0x424BEDCA34AA75A0ULL, 0x150B0D400BD8E61AULL, 0x4E682429B596D6B2ULL, 0xEC4274A08E610FFEULL, 
            0x3D2CE8C46CCEBBB7ULL, 0x6D62C9F597EBC4FEULL, 0xF3E22DF9492F8BF5ULL, 0x8DDAC53AEA5E1527ULL, 
            0xB1F35EA03052416DULL, 0x1F4D50F74E39DA65ULL, 0x842F5E44225A842FULL, 0xD704ED96B74BC84CULL, 
            0xE31941269E983FF6ULL, 0x60FD2FEB81E4A482ULL, 0x56082E3AFA5DF515ULL, 0x5A01ACC148A94833ULL, 
            0xE6B04117B4003311ULL, 0x17DB27AD82DD6A3EULL, 0x96D10A3EF845867AULL, 0xCAC7681DA591AC7DULL
        },
        {
            0xB1AD8C33FD372164ULL, 0x3B09D0CDD7144843ULL, 0x288EDC1B2D8FA9E7ULL, 0xF48030B220DF4DD8ULL, 
            0xCD48DD52D9A61385ULL, 0xAE9C41DEF391B9CCULL, 0xE2C1D8F822FAD7E7ULL, 0x3F772B0F2ABA5831ULL, 
            0x9CF31A7AAF8682EEULL, 0x76BAB95F5043AA3EULL, 0xC99370AADDD6C217ULL, 0x345990C35EC17828ULL, 
            0xD7E9B48B966E2A6EULL, 0xCE769BE132D10BB1ULL, 0xE534E719B9383646ULL, 0x78462FF503DD582EULL, 
            0x3DB10F87503F7402ULL, 0xBBEFC14C8DE67E8EULL, 0xE472C7A53895BF8AULL, 0x7DAB49F0DF6D6FE4ULL, 
            0x5BBE6B8A25DCC503ULL, 0x7361EFEFDAEF30B2ULL, 0x259ABD88B4BABC05ULL, 0x9F47495DE269713AULL, 
            0x049971B5857FBECCULL, 0xEC4EA1171973D901ULL, 0xBFA8144EAD437511ULL, 0x49CBEB18DF0682C1ULL, 
            0x7FA9B2C9C1A6E217ULL, 0x7BCC10D45FA927A4ULL, 0xC4ACA09B9653DBF0ULL, 0x20E6B42D5D583C9BULL
        },
        {
            0xA812EBFBF075AFD2ULL, 0x0CE87122208AEA75ULL, 0x63D089C4783BBFAFULL, 0xE327F778E0C4A4A1ULL, 
            0x69B77928E3785363ULL, 0x59A0EF3963AA97F2ULL, 0xCFF2EC4F748CC5E3ULL, 0xDD202AB40FF5D97CULL, 
            0x93674503582CD80BULL, 0x4BAF12C98631F323ULL, 0x35EEB3AC10676BD9ULL, 0x495E6E255E0C98C9ULL, 
            0xAA5F6E9D055A15A0ULL, 0x0EEBAF316B77A9EBULL, 0x458E0D7CC4BE6205ULL, 0x883AA45502012E4EULL, 
            0xD494A464B8E31165ULL, 0x26A4CA14211DEF58ULL, 0x38445AAE1DE7B9FCULL, 0xEFFF4BBC6CCC27DDULL, 
            0x48903C5774CDD1E4ULL, 0xEE1A7BDD803BFCE9ULL, 0xE83E92F68F2DB79BULL, 0xACC2F6752684209CULL, 
            0x9992F92A4C8398E1ULL, 0xE41DF3BDCBF08AACULL, 0x2BA4C7F478815F9CULL, 0xD4C30E293D189F06ULL, 
            0xC29A9F6348C93670ULL, 0x94F9850FC1326F6FULL, 0x0DB1D4E600BB62E0ULL, 0xD6240085CABE5415ULL
        },
        {
            0x4B626C91660EF9C3ULL, 0x15394EF1B7A71A9DULL, 0x4C2CD6BA73C2C2B8ULL, 0x5837A9EDEAFF011CULL, 
            0xC53AFD1ED4D23592ULL, 0x521AF5F31A6B721EULL, 0x9155CB5180516205ULL, 0x2D1EE4B2201DA912ULL, 
            0x25AC54109FCB651DULL, 0xEA83FE4D1544FA92ULL, 0x8E6455A7B9724312ULL, 0x330331C3A8DB9056ULL, 
            0xE0D862F7080A4B12ULL, 0xBC8AE257B07D4728ULL, 0xAF26F0EA956A5609ULL, 0x8577FF7197DEDBADULL, 
            0x81CA6B26049D4060ULL, 0xD15DD56406043B29ULL, 0x77DD50F1E957809CULL, 0x6820A9100504C0A3ULL, 
            0xCF09241FE62449A2ULL, 0x154E77C4810115F2ULL, 0x1825AA54D27CD95EULL, 0x4FE6841EF20F43A3ULL, 
            0x21C12B4A92DCFE20ULL, 0xAE9CC2B12A4D2F0EULL, 0x098614DC7CC60948ULL, 0x35D0F7F7096BA23BULL, 
            0xD6A3AE98739015B8ULL, 0x37D1FDA14353F007ULL, 0xB0CC7F5B894421C5ULL, 0x94C6F9BB1812888FULL
        }
    },
    {
        {
            0x9A79F503AEA21A9CULL, 0x8D5C9FB36B91758BULL, 0x4C9CFD87474F15CEULL, 0xB84A827AE9BD8F83ULL, 
            0xB9E1AFB93046E639ULL, 0xBF6B531673F0BAD2ULL, 0x5886016A46F55742ULL, 0x463891AE6F17F1AFULL, 
            0xCD162E39661D4023ULL, 0xCFB2173A21B89818ULL, 0x1422195177690050ULL, 0x04C373F5253334A8ULL, 
            0x5C14D1CCF56AA6DAULL, 0xA94FD1CF47A34A5EULL, 0xCA4D8F516AF88024ULL, 0xEB307D29E4192718ULL, 
            0x7E89360852A01165ULL, 0x3606A8B38CF6888BULL, 0x5C0928A06619BCE4ULL, 0x00029658458963FBULL, 
            0x763B9F3B33AFDDE6ULL, 0xE37ED87E49AD39C9ULL, 0x7D31EB81A90BEBB9ULL, 0x562CB66083675F3BULL, 
            0xA9B07999792320E3ULL, 0xCD343E9B5BE45AAEULL, 0x45AFE90B387AE9B0ULL, 0x34ADC0E63BA4AF23ULL, 
            0x04630EFFE700C8CCULL, 0x47B91A83C31A035CULL, 0x5994325E1EE4B321ULL, 0xB1DEBFCC659CB735ULL
        },
        {
            0xE1D5A87677880C6AULL, 0x9A5CE506743259D4ULL, 0x0FB4FF3D4647F8A9ULL, 0xC9DC327C7B837520ULL, 
            0x305AB2A3AAD852D8ULL, 0x954E479EEE746625ULL, 0xE3CE0A556605B3B4ULL, 0x8C32F614355B3DD3ULL, 
            0x003D378B5D227AA7ULL, 0xD621F3BEA8772994ULL, 0x144C678676D46352ULL, 0x0A28C9DDD590C01FULL, 
            0x943F68AD93D507FBULL, 0xDD2CD70AAD3D94C4ULL, 0x9353E6E79D056966ULL, 0xB4DEC5F9C37D1AEBULL, 
            0x032917899EA83E25ULL, 0x60AA1D2864098978ULL, 0xCD9AECDF63289A7AULL, 0xE56879D36244985CULL, 
            0xE096E802C370F0E4ULL, 0x60D807BC255AAAEDULL, 0xA3E0137001338012ULL, 0xFA4754414CD19AAAULL, 
            0x4F3773DCB9B04B09ULL, 0x56B15B111A045862ULL, 0x26FC50211DE172EDULL, 0xA937FC6949272388ULL, 
            0xA8F363F16E7FEFAFULL, 0x5A4821803E4A52E3ULL, 0xD4ED2B4747362765ULL, 0x1C097E48D28A944DULL
        },
        {
            0x9A28BFB6D5D19310ULL, 0xD518FFCDECC214CAULL, 0xD462F58CE4FA88B9ULL, 0x679F6155D7D7EEC0ULL, 
            0xBA148AAF617F6256ULL, 0x4A49FC8BEF9C88A1ULL, 0x877F641FFD0DA984ULL, 0x172AAD35D4A4906DULL, 
            0xAA8132942E2E14F1ULL, 0xD6C06B71DE233A6CULL, 0x801387071F9E67C8ULL, 0x057F9D401640466FULL, 
            0x8049ADE15A494334ULL, 0x9BD2C9CDCE743B07ULL, 0x8E06D59ACEF9A8BFULL, 0xD2D93B30D35729BCULL, 
            0x4CFDC8AC05214F90ULL, 0x790901690E8ACED3ULL, 0x65FEEC9952D570D7ULL, 0xCE19FDB4F3A291E1ULL, 
            0xA858253A111891FFULL, 0xADB247D7193D71DDULL, 0x43F41FE00D529DE8ULL, 0xE38B8DC455E2B601ULL, 
            0xF6B2B1D5A14CA31DULL, 0x2903E24C7B15FE84ULL, 0x3D67FCB638661915ULL, 0x0C724C4025974F5FULL, 
            0xEDA17C9701643CD8ULL, 0x665DFE7F9E3C90FCULL, 0x36B2007FB3B87BDFULL, 0x57628A9006230CCDULL
        },
        {
            0xC0110315E63E8BCCULL, 0x5627C927934193DDULL, 0x14B171110153E31AULL, 0xEAEA793A21FE2BABULL, 
            0xDD914FEFC4E842DDULL, 0xB997402E0BF5BC6BULL, 0x468CC8D3D1FC7C19ULL, 0x63907862605FFA02ULL, 
            0xBB75FFFC2BA074CFULL, 0x96A9692C7D3AC478ULL, 0x712A561B735B6E9BULL, 0xB19480F085DA8697ULL, 
            0xDA02EC5613C9F572ULL, 0xF720B22CA6588298ULL, 0x049B123872952074ULL, 0x6394A476D9EC0343ULL, 
            0x37F8C2F3567104A7ULL, 0x4AC26C12B8ABAB57ULL, 0xA17F0E7AF05D1A0BULL, 0xB2B9A5943E32F5F5ULL, 
            0x8E90E4F91EFD6E91ULL, 0xD72CF730BFE21AD2ULL, 0x76F0ED8D92207ECBULL, 0xF4144E106EA785BBULL, 
            0xEF581CECBFED1999ULL, 0x9D2ECCB8C27AB9CAULL, 0x79BAA8549D3CC0B6ULL, 0x4A254FD7A06167D6ULL, 
            0x5D79B22DDC0278E4ULL, 0x720596DE424A0CD9ULL, 0xDD231021BD3AA0DFULL, 0x36768A42D3032FD1ULL
        },
        {
            0xA1C2D4FE367776A0ULL, 0x18C58938F9051ADAULL, 0xE7F2BF6751B6287EULL, 0x32A183DD92885506ULL, 
            0xF234621F351ED6D3ULL, 0x334B76BAFE767E6FULL, 0x3361AE357AA5E4A7ULL, 0x28700C9CC27FF944ULL, 
            0x366E96DB1EADAF67ULL, 0x00519F1D50A858F0ULL, 0x236210FC5755621EULL, 0x73BAA78F4E733024ULL, 
            0x07D53720D48DCA47ULL, 0x1E17C36657CE9B53ULL, 0xA1FA3F16174362E4ULL, 0x8236433C49FB2D3FULL, 
            0x793E516D4EB24013ULL, 0xEE258EDE5564F8D5ULL, 0x1C13BDC39C5C6713ULL, 0xF955454C12E05296ULL, 
            0x5D826DE7715B4A2CULL, 0xE233A71B8E33BA40ULL, 0xCB6FC07FFD0A5D7EULL, 0x19F083ABD887D9BFULL, 
            0x5CFF3F0433629689ULL, 0xE0350BEA5B4377EAULL, 0xE908D504145F1D7AULL, 0x4AEF6439DD342FD6ULL, 
            0x32F1F33284A5DC57ULL, 0xBD07D5979369C568ULL, 0xFC3DFF9DFF11C7D7ULL, 0xC482A15FBAAA1697ULL
        },
        {
            0x8FFDAA49D1C202DDULL, 0x7BCA46CF7F0585B6ULL, 0x681970A5F7FD58BAULL, 0x733BAF536F23257BULL, 
            0x393D949EA3EA28ABULL, 0xBDF9E62A634FBE33ULL, 0x00EFCEEED4464041ULL, 0x117CBCF2818FE7F3ULL, 
            0x5B0FB164B752F9B7ULL, 0x3341B9A1719EA47BULL, 0x2A5A783E2F4EC2C1ULL, 0x3306473B0693A1ECULL, 
            0x5DFC010B4B6EC894ULL, 0x8947954AFF77F36DULL, 0xA0D78F1AC29BFEE8ULL, 0x7FC1097FC968017EULL, 
            0xC41B78106DD09574ULL, 0x83240FA2CA4EB085ULL, 0xD48B4D7069F2ECFFULL, 0x911EFAEEC2CA49B3ULL, 
            0x8B526761CD3B135DULL, 0x36F84EE822FF3659ULL, 0xE7F7A18D961B96BEULL, 0xF1D59371301FE197ULL, 
            0x34421E413AF21A93ULL, 0x579229FA22BFB645ULL, 0xB49D99273DAB6889ULL, 0xC2155C2A1E08F782ULL, 
            0xB64A4E438274A7AEULL, 0x0C7875ACDA323831ULL, 0x729EA6456972746AULL, 0x4E8BD314A5D73494ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseFConstants = {
    0x60F0DD1845F7FE11ULL,
    0x0099C36578E854ECULL,
    0x681A3160210DD7D7ULL,
    0x60F0DD1845F7FE11ULL,
    0x0099C36578E854ECULL,
    0x681A3160210DD7D7ULL,
    0x3EA6F88F4C4F69F9ULL,
    0xAA68C612E5DBF85BULL,
    0x81,
    0x6E,
    0x3C,
    0x71,
    0x54,
    0x0D,
    0x7F,
    0xCB
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseGSalts = {
    {
        {
            0x44A4712B2EF6BA98ULL, 0x4EE0C2E89C2703D2ULL, 0x24996284CFA46353ULL, 0x8855BA1B48D34A08ULL, 
            0xF31EACE3FFD8C35DULL, 0xA2630E283CC7E2B1ULL, 0x8EC3A9B9553C4D20ULL, 0x34CB3ABE1F69F1C6ULL, 
            0x16BDE01A8E80C41CULL, 0xD33876EC0E45D844ULL, 0x4FFF4DAD135DD1E3ULL, 0x5E53F89B091B8318ULL, 
            0xD427B0508D3C7D64ULL, 0xA991FBD973442DA1ULL, 0xA189AF11F8821364ULL, 0x612B501DE2130129ULL, 
            0xBC1EC5CF9AEB7D4EULL, 0xE785A8E44F251712ULL, 0x6E1FA3FE470D3088ULL, 0x8D28C48BC2660B24ULL, 
            0x44D6CE8F804A9E31ULL, 0x48EAD64849CBEF5FULL, 0xA5B4578330748355ULL, 0x07DFE60B5F98EABFULL, 
            0x388483EC859C5544ULL, 0xD546A6D58F461127ULL, 0xBFDEC754E889FB26ULL, 0x47A73FC4A6927853ULL, 
            0x830D76EC85D0D90EULL, 0x5141D5BCD23805F1ULL, 0x9EDD2BDABA2E15E9ULL, 0xEA1644FD8FF8D3B1ULL
        },
        {
            0xB2694899CDA2260DULL, 0x54C78EA043443F6DULL, 0x421E0DD4F9AF61F8ULL, 0x04F0C4BB61182CA3ULL, 
            0x4ED0B029D6B41F9FULL, 0x79FE6F5FBE952772ULL, 0x96A2B49C9887EDC5ULL, 0x69537C9BFA4ED69AULL, 
            0xC63C623BC2F1A3C6ULL, 0x1D7611FFAD2CF47BULL, 0x401AD277CB38216DULL, 0x8ED77F3E96CA3D0AULL, 
            0xF512BC7DFB93A883ULL, 0x7ED702B404158BF7ULL, 0xBFA5A8B2DCCE282CULL, 0xA9CF7D92C7DB8016ULL, 
            0x6F3221BB997C5327ULL, 0xD82BF54321F3047AULL, 0x6A308EDAA728C6DAULL, 0x1AAB32B8A7C20384ULL, 
            0x54DD97188F489852ULL, 0xC91D5CBD9C4D584AULL, 0x6655241DC625F8C9ULL, 0x6DC070FD6222A3F8ULL, 
            0x59E153C7464F2958ULL, 0x50E27A99120E1C72ULL, 0xDAA2785F27B29C7AULL, 0xA9DF565F88F67D34ULL, 
            0xB899B90D9D251B66ULL, 0x864F6F7366EE748AULL, 0xD100344EB95D003DULL, 0x35DAC907492FBE4DULL
        },
        {
            0x2345D4097F6D771FULL, 0xA86DEFFC94FBB81FULL, 0x50AED5D62AD0D28CULL, 0xD46980D81F205A23ULL, 
            0x5C6B352F0582A39BULL, 0x4FA76A43DC91ECF4ULL, 0xC9FE5796866E94B5ULL, 0xE4FA4AB7DDE4DAC0ULL, 
            0x700787DB6A58B8C2ULL, 0x3CAEE62C8EC12A83ULL, 0x4AA76C2ABB7B6892ULL, 0x7EE297652A072B70ULL, 
            0x83390E0855D8D107ULL, 0xFECF9B54784005EFULL, 0x43B7A54A284FD3CAULL, 0xC1187B56B1289B7BULL, 
            0xA65DF5C22542D122ULL, 0x2B9B4FABD2325CF5ULL, 0x1D359494856D1BC9ULL, 0x0116DF85817DA356ULL, 
            0x05536B92A2173941ULL, 0x5746D71640709215ULL, 0x54779A460EA593B1ULL, 0x41C54DDBEF9A8572ULL, 
            0x3005E2015912DE44ULL, 0x8DE177120B1E7F98ULL, 0xFACAD9B93DE8E884ULL, 0x079E74B7A07D5BC2ULL, 
            0x5F2AB8855E2E6B42ULL, 0x593829350BD56C7CULL, 0x5812C88E88ABA70DULL, 0xF5061131DF7293B0ULL
        },
        {
            0xB8ECAF28C8C78511ULL, 0xC3CB13171F6EAE8AULL, 0xD7CFE82CB9BBF822ULL, 0xF15444038A95F242ULL, 
            0xDF345A88704A9763ULL, 0x071E092B8C44EFC5ULL, 0x9040709A1AC395E0ULL, 0x1359C2B99F08260DULL, 
            0x1D2C5A60E6D6098DULL, 0x04CE2D99DD50B6A0ULL, 0x5655957539B890F0ULL, 0x65BB7276C161EE4CULL, 
            0x5D83E09CFFDE6C23ULL, 0x5DF1E8CD94AC0E4EULL, 0xB91607D7F6F7E0BCULL, 0x73207232A6C2DD23ULL, 
            0x0F5B7325275C7BACULL, 0x47E54C29E1599CC2ULL, 0xB7A9B99033277441ULL, 0x20DA334D126825E9ULL, 
            0x448F20A5A720D21CULL, 0xF6868E6AF1B09861ULL, 0xE71080FD790DD73DULL, 0x562B095D2887B28EULL, 
            0xBE010006DE854D03ULL, 0x69822725BF69619AULL, 0xAB01FBC7AAADB07CULL, 0xF3D75B762BFB9A23ULL, 
            0x04711CC4134B96C3ULL, 0x1BB3189B22E32E88ULL, 0x45CABF8C50E3BD1BULL, 0x9115E2F19F429661ULL
        },
        {
            0x705851A16005CD2BULL, 0xB958889CB19A4C68ULL, 0x745C931A367119EBULL, 0x6231A71AA0B68AD3ULL, 
            0x3BD340D3100283FBULL, 0xEEED54477E3F0326ULL, 0x5E95EF1E4C7FB3A7ULL, 0x76ABA39A0580808EULL, 
            0x64513C4BC465F5D8ULL, 0x6A72D45CAEB14C3FULL, 0x62C29F16F0F5C628ULL, 0x7D1F75596098F928ULL, 
            0x4CF59D54F4658E7CULL, 0x10CC471C008E9CE8ULL, 0x6A8FA0111AE40444ULL, 0x692D28F0201C8321ULL, 
            0xE7B0627F1023841DULL, 0xBA81C90434704CF5ULL, 0xDAA229B036095957ULL, 0xF2CE501ABE29BD81ULL, 
            0xDD22F338D6447EC6ULL, 0xC3549FF1545B37E6ULL, 0xEB92E4465E9E9EE7ULL, 0x40DE80592FE7C3EFULL, 
            0x5967D7DED0A50D02ULL, 0x49A7ADF87661A861ULL, 0x3987D66613D71F39ULL, 0x6A317AC3B2F5CFF9ULL, 
            0x00FEA318A673107DULL, 0x280C204E87C14194ULL, 0x632598DDBD20D19FULL, 0xB8FB3BB95FB0524EULL
        },
        {
            0xF761EB672294DB8FULL, 0xF0BF100ADE891C55ULL, 0x51571A35B6A5095CULL, 0xE23FF08D18A763C3ULL, 
            0xACFC0054ADF0DE33ULL, 0xF8D69F35C6B981A1ULL, 0x77DC4B72D753BCB5ULL, 0x036CEBA0105312C5ULL, 
            0xEEABD62D63E50358ULL, 0x102B82049B80DE8DULL, 0x1414325148AE376BULL, 0x07852A67365E4428ULL, 
            0xFF6EB8F90B3A6EE3ULL, 0xC5E47CA677444F07ULL, 0xFAA5CC16E2071053ULL, 0x9DFFDA0081F34B96ULL, 
            0x5609F70392164E53ULL, 0xB0C6EA8B52410021ULL, 0x0B32ECF0F3882016ULL, 0xCF1F9944EF68861EULL, 
            0x6AA4D01BDC531DEDULL, 0x065D3EA71C5788D6ULL, 0xEA10B658C93D646EULL, 0xD1F56ADE62DEE56EULL, 
            0x2645E673CDFCC6C8ULL, 0x99ADFC434903FC96ULL, 0x12FB02B51AC2B0BFULL, 0x43B3AD8714077EFFULL, 
            0x7459F668CD99A5ADULL, 0x5D08F1F25B872DD1ULL, 0x12F2465F60AA0819ULL, 0x4EDE63D8743D857AULL
        }
    },
    {
        {
            0x79169279847E7D01ULL, 0x8B256BA3EE87A605ULL, 0x548F4B7C03926D14ULL, 0x95C72BC7BACD7522ULL, 
            0xA674D457719133A5ULL, 0x5E46688EA6806DB3ULL, 0x825512E06029A576ULL, 0x1063CAA20E829987ULL, 
            0xCE01A9BD81245BA7ULL, 0x8EB10E3ED144D09BULL, 0xA041901854F1B7CFULL, 0x13A1B68B0DE41CDFULL, 
            0x0F5FC7716198A6B9ULL, 0x06A676EC0EC67653ULL, 0x7AD44E5FC6AA315AULL, 0x98BAE9BACFE022CEULL, 
            0x03A38F69CE865B35ULL, 0xBDA335976536E43FULL, 0x11DC5911430F729EULL, 0xEBFF9ADE247CFD42ULL, 
            0x9D32FE2946580263ULL, 0x4788DDE7FDDC441CULL, 0x006576EB91FDB5B0ULL, 0x5B528D27C015FB80ULL, 
            0x0588FEF45C517F34ULL, 0x42B910EEC5D501BCULL, 0xED27FF84A39337E9ULL, 0x069C96DCFFAC61FFULL, 
            0x8D700A4526581F12ULL, 0x0313EB5A5277B2CDULL, 0x50769D80FDB68652ULL, 0xF1646ECA9EF62FE4ULL
        },
        {
            0xECB5B670175F255EULL, 0xAAC4898CAE5D8AEDULL, 0x50BEE7364C054C76ULL, 0x8DBC787DB451E475ULL, 
            0x34A1D8F4EED1F7B3ULL, 0xF8AFB93AA1479CAFULL, 0x3710FB9BC2252B7BULL, 0xF1F3F40C6CF02C6FULL, 
            0x6C91D9FBBBA74736ULL, 0x961838C429000D52ULL, 0xAEEDA6DDFC4536D4ULL, 0xFE39D1291F99333FULL, 
            0xD2076A51E31AC7DFULL, 0xA8279BCF0869EF6EULL, 0x2D45133201C035F3ULL, 0x479B80E539AC8914ULL, 
            0x2C65CF7ADFC722A7ULL, 0x633F5C37CBC77FA6ULL, 0xB5811594FF64FA98ULL, 0xB13E77B5FB56AEA3ULL, 
            0xC07A0B5AE92264A1ULL, 0xE977E131668E67EBULL, 0xDFA5E759A1EA5A02ULL, 0xDF9442661B8EFBFAULL, 
            0x4B5897ED2F8179C1ULL, 0xE3AC7D53C8550B2DULL, 0x82EC255794772879ULL, 0xF0D364EB7FFE97A4ULL, 
            0x07A069CD2FD58CCCULL, 0x00C82CF5112C4438ULL, 0xD33308F57472C13DULL, 0x1C58C258A933DABBULL
        },
        {
            0x54E2C70AC6A7ACA0ULL, 0x2E41E12D61D900F6ULL, 0x95B0085572296176ULL, 0xCC55386FF1AED639ULL, 
            0xD0B2CD08F4114611ULL, 0xCB523BDC9B0BEF00ULL, 0x4D4A8C1C23FFEB74ULL, 0xA914C854BAE43A6DULL, 
            0xA5608BDFB65A9193ULL, 0x940F258A3A68E30EULL, 0xF5ED63BB37884C80ULL, 0x2E09EAC04C6F2C3EULL, 
            0x0A03E84110D1BB02ULL, 0xB3083F5AD70BFD77ULL, 0x13F073C32588BC1AULL, 0xC292A5D43598A52AULL, 
            0x8CB3D4D366F71528ULL, 0xF9A91DC9744902B3ULL, 0xF7E5985FEC449B99ULL, 0x98E906DC2E1D51C1ULL, 
            0xD8CC82B2FF5CE463ULL, 0xAEDD75475A942DC6ULL, 0x8C399956B63949CCULL, 0x75D75D61992CFE08ULL, 
            0x14FF7D7759502A19ULL, 0xBBC4C866D2E42178ULL, 0x52F802C8D2BA5F0CULL, 0xD1B615C64C34E197ULL, 
            0x0ECB5CDD12DBF0FAULL, 0xAF4D10BCD2F4C76DULL, 0x3231DF171C694D57ULL, 0x76969E5DDB1B615FULL
        },
        {
            0x0FA81C9D1BE65995ULL, 0x56D5B5275596C0B9ULL, 0x071C2CA2CEE36878ULL, 0xF6C53600509ACAC5ULL, 
            0x849A6B970E53BEB3ULL, 0x2B0DE3368A098784ULL, 0xF1A8739EE8E7DCACULL, 0x9F85CF11EC81FA91ULL, 
            0xCF553647F82563D5ULL, 0x89B434153F419A2FULL, 0x503C589F57987314ULL, 0x21139155A085F58AULL, 
            0x5A37E224AC2119DBULL, 0xA250637836807AD8ULL, 0x90FE0D4CCAAEEEE1ULL, 0x746307F13F997530ULL, 
            0x4912C6CC63D48E4BULL, 0xD530F60861E7C5FAULL, 0xBCD106C8BAFE9104ULL, 0x902D0CD7CDF0F853ULL, 
            0x703FC84D5F284278ULL, 0xF5C35DBC4BEB0271ULL, 0xC07A441EFD2A2BADULL, 0x09F59C373D937078ULL, 
            0xB2676FF4D109BBE5ULL, 0xBF26C250A0ABED24ULL, 0x8E5745DD019A4549ULL, 0xC462596BAA208E12ULL, 
            0x1555B895C9047DC4ULL, 0x2AAE101057A29A92ULL, 0x697B9A305DFA6E43ULL, 0x4AE9D0733C870874ULL
        },
        {
            0x4E810A70B22F297CULL, 0x9F0C2F9111AC8100ULL, 0x5C122FE1F9341F48ULL, 0x6C7C7FDBA7939650ULL, 
            0xAA22E12542853132ULL, 0x4CC9DBB4B9AAFF2DULL, 0x0D8A73A319ED371AULL, 0xC1EAE564B7F0D493ULL, 
            0xED2D9DA9944F72CFULL, 0x02400BB2D1A06B6FULL, 0x3F48C0E0C1396472ULL, 0x51D037C24D418F46ULL, 
            0x375B16AC47884EB7ULL, 0xEA7653F2E5B20544ULL, 0x5762C3A6AEDA5F0CULL, 0x1A9EE5A9C76F6F1DULL, 
            0xCF1683CCB621FDEAULL, 0xE2F22A1DA9752CFEULL, 0x4B0C8A5D76943DC7ULL, 0x1BC1062C0253A533ULL, 
            0x63920981D271BEF9ULL, 0x8EE68F11DFF70F66ULL, 0x1C462ECB1A6C15EAULL, 0x0F5408B00F9DA5EAULL, 
            0xCD93270E3115C51FULL, 0x739BC83558C9565AULL, 0xC03DB5918E217620ULL, 0x8ADC1C45FF3BE0D1ULL, 
            0x1C25885C04CCF973ULL, 0x391DD69883ABF138ULL, 0xE3AD438D24E05D02ULL, 0x4288636F37225DC0ULL
        },
        {
            0x4FA70912142C8913ULL, 0x3926D94012C716ABULL, 0xC6F7CC50477E87B6ULL, 0x4AB6269F1FCDA104ULL, 
            0xD17698C69921D5C7ULL, 0x1490B4108ECAFE02ULL, 0x4143CBC403ED8741ULL, 0xCA62324B79163C3FULL, 
            0x2441A08480692A96ULL, 0xDB15896558397B41ULL, 0x847552CA6B31FBB0ULL, 0xF0D35C7CC4D998CEULL, 
            0x2B71401F85BD13DFULL, 0xE2E3258BF208D541ULL, 0xB9F1F421E6BBFB75ULL, 0xD6DBAA6D005FEC8BULL, 
            0x1116437BBCCE133CULL, 0x9DC85DF90EA61E2DULL, 0xCC003E3DC11961A3ULL, 0x379C73BE913DB9B9ULL, 
            0x8C1E582312BD4DB9ULL, 0x7BCC9139C2686DAFULL, 0xB63B4EA657F35623ULL, 0xD29CF2E7A298DB98ULL, 
            0xDD6C602DF41E54B9ULL, 0x14073A32244DEE98ULL, 0x6D49D27F5031B323ULL, 0x4BEBA922762779CDULL, 
            0xFDA89269C9C2585FULL, 0x3451372A70ACEC7CULL, 0x93C5C18F2132CC8FULL, 0xB2BC5CAE0B1CC948ULL
        }
    },
    {
        {
            0xF104C3CAA7B175FEULL, 0x13D24A171CEE8593ULL, 0x5EB5A68B44C56B29ULL, 0x9C185939F1C25B85ULL, 
            0x773524AACBDB49C0ULL, 0x7083446C0488F24DULL, 0x6B41EA2BD74170ECULL, 0xAA93D35407745726ULL, 
            0x1D1894CC810B1DC4ULL, 0x78F6ED68C8836772ULL, 0xEF407A5453794587ULL, 0xA25F7D254D1D19A6ULL, 
            0xCEE645E2660684A3ULL, 0xBFE7AD46B771628BULL, 0x55A830E11CCBB382ULL, 0x81020DF5692FF0FAULL, 
            0x86F4DD67AC2846CFULL, 0xEF6E29708BADD347ULL, 0x753D237A9AC8AC83ULL, 0x0399F523C89BE6E3ULL, 
            0x5B3933C027BDEB21ULL, 0x128014E5B13F3FB5ULL, 0x2E747F2B5D0A793FULL, 0xED81CC84A4E37A74ULL, 
            0x0E7AC9C1FAAF8BABULL, 0x030EE757FBDAC1B5ULL, 0x65307C2BCD521CD5ULL, 0xDBAAF95931FEAD14ULL, 
            0xB7057F3106401B17ULL, 0x20FBC86D4A106329ULL, 0x565867467C627910ULL, 0x8375863946D9F5A8ULL
        },
        {
            0x31A9FEC6F9C61DC2ULL, 0x3E382308304B3A29ULL, 0x75D87152DFBFD7BFULL, 0xE9E0D91225DCF481ULL, 
            0x70416C9BA4770608ULL, 0xA03E97DD7DE85412ULL, 0x5D92940BC6DA38A9ULL, 0x3A6BA33EB242F1A4ULL, 
            0x6BFDC5EFB6F2E7FDULL, 0x19C907EF2E37D73CULL, 0xCF82AC4C8BA5A26DULL, 0xDB3DCCAF68BED825ULL, 
            0xEDD24CB11F29C5D3ULL, 0x0194495E1537A4F2ULL, 0x3C606EA978A43E34ULL, 0xB557C9A93A16DEAAULL, 
            0x935B24BD875916B8ULL, 0xA060307366E3DF65ULL, 0x31A77D9CACFCCC08ULL, 0x9ED9B05561DB2400ULL, 
            0xAD7EEBA7F7828C0FULL, 0xB8FABB5D4949BFA8ULL, 0x7982C13AABBC6EF7ULL, 0x0CE5ED700E4781C7ULL, 
            0xE9B620B0996DFD56ULL, 0x1A7A75CDC3F87898ULL, 0x45A0316FD5C58C22ULL, 0xA56F230F0D326CECULL, 
            0x3E575EC480FBE999ULL, 0x107A366666628715ULL, 0x8DDBD6C0735F5D02ULL, 0x3DBDB680ACBC141CULL
        },
        {
            0x2EEA96F5A6AB66FDULL, 0x9F001B1FAE397052ULL, 0x2E2C0683A318E6B4ULL, 0xBF5CC96EFD68849DULL, 
            0x13090AD346BF7EB6ULL, 0x542296A1341D4131ULL, 0x6E271C0A47586D95ULL, 0x84D8E9C48E786588ULL, 
            0x7761D3FAFD1E612EULL, 0xCC17821AACAC942FULL, 0xC3FBBA10EA67D533ULL, 0x5638CF503A9F11BAULL, 
            0x236932DAF3A34304ULL, 0x3C337015FA288DA3ULL, 0x44C6C38A32ACAB92ULL, 0x7379B7AB40953C48ULL, 
            0x6EF4FCA91C226251ULL, 0x3B55B4A78D173D44ULL, 0xDB2315D72EF9FEB9ULL, 0xA1784307286D5E55ULL, 
            0xD78A547336A1AFE7ULL, 0xC11867CFF7FB7FE8ULL, 0x7CCA8BAB621C9155ULL, 0xFCE586F08148A6E4ULL, 
            0x726E44577843686DULL, 0xEB03EE889356D340ULL, 0x0A437842F2BFDDEFULL, 0x5D9CC4EF862AA24FULL, 
            0x87809DA27D6F18FAULL, 0x8175A60765C75042ULL, 0x7A764D6690C7FC0EULL, 0xE13E4A237B5B667CULL
        },
        {
            0x873410BF23176D3DULL, 0x1E1CCE710C268BFBULL, 0x9F5543CDC26A6AD0ULL, 0x3800A5ED68F2A487ULL, 
            0x0FE4537BF3F241E4ULL, 0x2C40B0694B32E7DBULL, 0x10FA95318602679BULL, 0x0FE9E2B1043905B6ULL, 
            0x54ABD9E2BECE6451ULL, 0xEECDAD340DF52A14ULL, 0x9B430786BA6DEF0DULL, 0x3C4A256F717E1007ULL, 
            0x757C33CC702D2FDEULL, 0x9CC66D02DA24C7C5ULL, 0x1C09515EAAEC05BAULL, 0xA4BE8AC03E7D5BE4ULL, 
            0x9F9A95F53CB161B0ULL, 0xC3E9A4F508B80526ULL, 0x41D12311EB715F5FULL, 0x37DCCBCD9401BA3EULL, 
            0xC440F4C7C96EBF83ULL, 0x69B5CCEB1E542A9BULL, 0x1FD1FDDC04E81399ULL, 0x8224E66CDF60D6FCULL, 
            0xD9B77D898CA06B9CULL, 0xB73F1AC7A7F759A5ULL, 0x3BC033378AFD5124ULL, 0x1B4388E04EFDFA77ULL, 
            0xD066531FD54866ECULL, 0x760984224E07880CULL, 0x34445186EBDC1B33ULL, 0xB4DE5F7E3CDA400AULL
        },
        {
            0x1FBFFF2B108F7143ULL, 0xC1BAAAB031438542ULL, 0x945F1B112A26106CULL, 0x1EE1665B5CDADEB8ULL, 
            0x829E586B38DD46EBULL, 0x6C9E5F0B4C08EBC5ULL, 0xB7FD44988AD98A8EULL, 0xEF121B3E7A546173ULL, 
            0xF7148B0F8D88CD5AULL, 0xE2FCB7C4BA295AE7ULL, 0x4CF92BF45DBC732BULL, 0x5E5B3D5CC0D611BFULL, 
            0xF83E435508119FEDULL, 0xE3B94D677377221DULL, 0x3798CFAE94CF426DULL, 0xEDB6D0E5809A8198ULL, 
            0x0FB077980C04B1A7ULL, 0xDE391CD9068E17CAULL, 0x48C78FB228E5527CULL, 0x96F30061E5CABAA6ULL, 
            0x242D94789E8A71F9ULL, 0xD1CC2D6DFC8198CDULL, 0x3D0EF1698A8F0A09ULL, 0x51FE706B1F7EFEA3ULL, 
            0xCFD43DA100300A79ULL, 0xCCB2CDD0BEC9A391ULL, 0x37029CE7BF4FE517ULL, 0x113B1C334B3FC8D9ULL, 
            0xEE5A1DD374D1AC4AULL, 0x73AB12ECD381CD8CULL, 0xDFC309F2394DB113ULL, 0x459771CED60FE5EEULL
        },
        {
            0x73694C18B2C6A029ULL, 0x638B424C45718808ULL, 0xECF115EEF8D06702ULL, 0xF69F7B01C01B3402ULL, 
            0x40BA6B1C7031A4E4ULL, 0xF1AF716D662E57DDULL, 0x5DDC2796394D1BE8ULL, 0x6490D0E5D5F13C69ULL, 
            0xE389243B2CDF3BAAULL, 0x1A30457F90333F65ULL, 0xE64840FF6242179AULL, 0xBBD7F0E704DD6746ULL, 
            0xAD4447C01DD2E6C6ULL, 0x24F2932D42EED5A5ULL, 0x940A23A97A88FAF1ULL, 0xAA108A465AFAE4D9ULL, 
            0x84936B8C5E755E4BULL, 0x561F7F7E9AE386D4ULL, 0x01AF0772EB469831ULL, 0xA6E1EC02F6C041DFULL, 
            0x66112573F1519DA4ULL, 0x64D34117C1FC5A6BULL, 0x0C3D354AB3822729ULL, 0x68A62C3B1458FE0EULL, 
            0xBBECA877AB4B043AULL, 0x493536D599DCDD66ULL, 0x33047F48980ACEEDULL, 0x129C7563CE968D79ULL, 
            0x43C674C525ED791CULL, 0xC0A9F3B3F12BE4BBULL, 0xC0FE510AEF56A59EULL, 0x48E9C89A97627EC9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseGConstants = {
    0xC586582BAA202728ULL,
    0x3FD13E3FD8003819ULL,
    0x3404A95E67B4C561ULL,
    0xC586582BAA202728ULL,
    0x3FD13E3FD8003819ULL,
    0x3404A95E67B4C561ULL,
    0xF1717B41EEF32FBDULL,
    0x3E249EF679158AF9ULL,
    0x51,
    0x0A,
    0x3A,
    0xBF,
    0xF7,
    0x86,
    0x96,
    0x02
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseHSalts = {
    {
        {
            0xA69CD27674AEA683ULL, 0xBB7BA7247909B2ACULL, 0x789D71F506996AA9ULL, 0x656D6CC9FAE7A1FEULL, 
            0x1ABBF6B0F187B3CBULL, 0x717F99501769D310ULL, 0xCF502DEBBE6ACF03ULL, 0x72EA2F64F23A3764ULL, 
            0x3B13D8FFAFE6DD9BULL, 0x304BFE29D323C884ULL, 0xBA0156DD3A9ADC11ULL, 0xF551C7703FF4E77EULL, 
            0x0C6C000A6B33760AULL, 0x8C28A950544B3EB8ULL, 0xDABCCB2F21CBE837ULL, 0x4192CC1353EF16E6ULL, 
            0xF2A8B72210832D8DULL, 0xD6934804DB912A6EULL, 0xCE552A6C57117011ULL, 0x502BBFC529547DD6ULL, 
            0xF28B8070D875DF2CULL, 0x2AE8A872D1230B75ULL, 0x5B913E3C6AAF3254ULL, 0x510BDFA37FD030E8ULL, 
            0xE2B23C20CFD7F93EULL, 0x32A707CC996916F2ULL, 0x15732ADC8495320BULL, 0x7E09E022A27B9E72ULL, 
            0x5A6D697E2DA6EFF3ULL, 0xAF406A0E6D477642ULL, 0x1BF9870BFFDCD084ULL, 0xAF4A6362B65DB1E2ULL
        },
        {
            0x2242A8CDAD4C12BEULL, 0xB606EC2D57C54D5FULL, 0x977C603579E99FD5ULL, 0xB8F1C16AE3B4AF1DULL, 
            0x2CF0D9B91C2E0B07ULL, 0x4821208D670A7950ULL, 0x9C0CB8FD999416C8ULL, 0xA4FC115979B03F9DULL, 
            0xB60B68ECDDFC19D6ULL, 0xD55A9F9055818712ULL, 0xBC8A8ABDBB4B6464ULL, 0x9D244C3CE2D36038ULL, 
            0x4235AC7AE8AB861FULL, 0x532D6F05DBC7C47EULL, 0x9E8C52C67E81708FULL, 0xAF6132B3DE7E121CULL, 
            0x497955B96357F62EULL, 0x87720A3411D7C87AULL, 0xDCB1CCEF2093D52EULL, 0x9C9978AB1E312BF5ULL, 
            0xC7F8EB49BF4258D7ULL, 0xC5CE8729BB42865DULL, 0x26735013B9AF0835ULL, 0x07B63D223ECE9329ULL, 
            0x352C4D5083CCB4E9ULL, 0x720F6202A342AD37ULL, 0x681E31388A31E9C5ULL, 0xFFA5AD97649EB5BCULL, 
            0x6E8D48ACBFF4A765ULL, 0xD8BC59B2D54C0458ULL, 0xC365FFC0E53E651CULL, 0x83A090F1F3B68365ULL
        },
        {
            0xE1806F5FD9667744ULL, 0xE1F044FC0794FFCBULL, 0x2BF8A6B978017F47ULL, 0xCC7D81340A8A9DE5ULL, 
            0x4E6B2244358353FBULL, 0xF62CBA99CB9C67FBULL, 0x970F19AF6DB641A4ULL, 0x5750E7466DE33950ULL, 
            0xA609B73A99E81FA1ULL, 0x3CE1F6E9BD76947DULL, 0xBDC8D5A1642F89E2ULL, 0x18C4D0BBF2174F78ULL, 
            0xB01F5199ECDAA090ULL, 0x2ADC4562748AAA60ULL, 0x0D61A90A69EB583CULL, 0xD4884379F9C5742EULL, 
            0xE38D44590A19CACCULL, 0xC78E697838570D8EULL, 0x23A589158904132AULL, 0x5806F55222416866ULL, 
            0x283A4E9656F1B12DULL, 0xECFFD47CA5D6B8D8ULL, 0x5EE974B64C60A134ULL, 0x73ED746D15273437ULL, 
            0x83AFDBDA29F48C19ULL, 0xFE45594A7FA4481EULL, 0x5F3390F5919A61E6ULL, 0x61C58CBF81674E39ULL, 
            0xA34144047ED08264ULL, 0xEDCBE91BA98706ECULL, 0x92E16F4B478C7B2CULL, 0xA9312A36B90AEFE6ULL
        },
        {
            0x08AD767591F0F830ULL, 0xD9DD29C90BDE10FBULL, 0x8ADE937AA5C88BC5ULL, 0xA25288448355CF6CULL, 
            0x9667FB2C46D6CFE2ULL, 0x12E9DE6955553219ULL, 0xA47C5DB0DE68AF2EULL, 0x923B43D3940CE4F6ULL, 
            0xD94205E10CCA8D19ULL, 0x1D3C7A9C87A5DCE3ULL, 0xACA8AC4DE4B03E7EULL, 0x8D52B2D37A8A396BULL, 
            0x661AB4529EB2B861ULL, 0xCABFCB42BFAA15A1ULL, 0x3AC9E53F69D313A5ULL, 0x886EDE8913FE8729ULL, 
            0x32A7404CB1181DFFULL, 0x3BD950D1F43B962BULL, 0x05A63B45776EEFFFULL, 0xFD923EDE0AEF98EFULL, 
            0xB04C73B89F427C0AULL, 0x3F920728C3F99476ULL, 0xD1A6C01D540D91D9ULL, 0x85B0AB833C0B44E4ULL, 
            0xA31A882D49178B0EULL, 0xB4094E4BF744D5A6ULL, 0x9466509E6C030D71ULL, 0x9ED4A3E685680AA7ULL, 
            0xCD888D672B6C6072ULL, 0x966FEFB5A8F2880FULL, 0x1173970B87A0B0A7ULL, 0xA93B39D017E42128ULL
        },
        {
            0x9424F89E5E1BF100ULL, 0x55BFC2765CD87256ULL, 0xA883CB8935B33CCCULL, 0xB9049138BE41AA3AULL, 
            0xFB69B83AF9929C76ULL, 0x4F5E789EF9219A69ULL, 0xB22BCFBAC735CCADULL, 0x4EE7ECA5D9710115ULL, 
            0xCDE6E01A082F5D58ULL, 0x696D5C0C8B2FE514ULL, 0x974BEC122207A6A3ULL, 0xFBC531A7E3F96871ULL, 
            0xD7193E5F074AA3EEULL, 0xE4FE5132C5F67FEAULL, 0x0F8EBC2CA5BA812DULL, 0xC2E925C1DA37A29AULL, 
            0x59B5A5E4A9786CB0ULL, 0x5C817D0F9FC88D4DULL, 0x5C9E5B6C3A5A6055ULL, 0x995A91165F9D96C3ULL, 
            0xC0707CAF99FDA36BULL, 0xB948F3D0834D73E5ULL, 0x702B24E377C84BFCULL, 0xF28D0D4CCEB3C202ULL, 
            0x628C8D1E3734B675ULL, 0x1FDBEAF026B6D968ULL, 0xD700B617A37491E9ULL, 0xC6CA48FA373A38BEULL, 
            0x4CF3519084F7E364ULL, 0xC097102CF2A19D93ULL, 0x7A1D194810A5F10CULL, 0x5453DF37F246090CULL
        },
        {
            0x9C47DE26A2B6FDACULL, 0xA0235E66B86A1A4EULL, 0x01BF31131DCBFED6ULL, 0x802A94FAEBD329B5ULL, 
            0x405CB2C71581F94DULL, 0xBAB876B470080D83ULL, 0x77A1F993023B8B3CULL, 0x9C91D3576C710566ULL, 
            0x12EA598C57861C15ULL, 0x47260E5E69C614F1ULL, 0x13FED4E794E714E2ULL, 0x590314E5A8A26ECCULL, 
            0x222D27E8A6FBB11AULL, 0x0D8C095B5D705C36ULL, 0x48269A0E93A52CC3ULL, 0x71F2233FE58DBF01ULL, 
            0x5F34A85023466DAAULL, 0xAD929191FE1C6C4BULL, 0x2BDC7434017CD20FULL, 0x1B9D5EA2E4E50855ULL, 
            0xFA6A83364D31F0D5ULL, 0x6817DC28581F9F16ULL, 0x4819A14A873E6727ULL, 0x5CE58CEF9DAA9E91ULL, 
            0x064F89A8893ACE84ULL, 0x540BC3D17C82A6B4ULL, 0x80207A669FA2EA4BULL, 0xBCD7C71DC60CA71EULL, 
            0x97E25E2267CEEF42ULL, 0xF1F8075A9741DBFCULL, 0x849D15B2919A26C1ULL, 0x2AAB59631277C488ULL
        }
    },
    {
        {
            0x1ADC182F4B6D5457ULL, 0x88414F9949A78B67ULL, 0xC50F64D2DD094B61ULL, 0x8FE483A3B2E7F82FULL, 
            0x6DDE263666C94F0DULL, 0xF7E1565E2313C30BULL, 0x70E8EC4D10F11F89ULL, 0x0E72D1FDE21C3D48ULL, 
            0x533908056742148DULL, 0xB181CDBE2BE0D3FDULL, 0x2EADD8379B21230AULL, 0x1AC6223D5588DAB5ULL, 
            0x73E2A01041EA65D4ULL, 0xB98CD6B666D661C4ULL, 0xAD744F8FEBA9AC36ULL, 0xB8B797C14FECAC89ULL, 
            0x56791BF1C793F161ULL, 0x9EF7DE9F72D7AD2AULL, 0x2376AEA53E4035A1ULL, 0x713D6E9840E5F16AULL, 
            0x573D4CE421FDC251ULL, 0x719AADF7E11CDB80ULL, 0x12353CA56E2AC340ULL, 0x42F626D0043EC872ULL, 
            0x8F027E700B299DC4ULL, 0x5A6C5BA915F6A600ULL, 0x84D16A2B77EDAB90ULL, 0x5227D3CD06EAB7FFULL, 
            0xEBBA9681B12D507FULL, 0xC313B1805E637A5BULL, 0x51F707E12D8D98A7ULL, 0xAD5632CCAB5ED31BULL
        },
        {
            0x074F0F3872A18836ULL, 0xD46F6A64EDEED05AULL, 0x4FC824EF5C0A23A5ULL, 0xF2D393D61A39620DULL, 
            0x34AB4844259E625FULL, 0xE8B2D00BD3E93788ULL, 0x9ECA9E19BB4CBC37ULL, 0x319449B9DFEA9D02ULL, 
            0x2C9DE984B8D8C0AAULL, 0x37B8709719B619C1ULL, 0x99CA686002DC6FAFULL, 0x5275020F2B071C8CULL, 
            0xB31C7B9C90EFF130ULL, 0x1DD4B14520DCC723ULL, 0x062E14850D159622ULL, 0xD5CB4CF3C67C7023ULL, 
            0x3E6FCB79B1BBCCE7ULL, 0x1E6C0CEEDFBAF3A7ULL, 0xC1FF1E7C1B09BFCDULL, 0xF1CF70988F5C02DEULL, 
            0xE83BB44C3D16312CULL, 0xFC44A12B7B9247C1ULL, 0x2B42416C351B0E7EULL, 0x0461CFFBA2B0C4ECULL, 
            0x8F0A9D75BBF06686ULL, 0x7B3FEFD6EC752E89ULL, 0x7F2C2C48BB222850ULL, 0xBD34535E15D6FAE9ULL, 
            0x65935737AB1EF8A6ULL, 0x19F6CD928131A5E5ULL, 0x0D05DBFFC377A0C7ULL, 0x788169DF143FE9B3ULL
        },
        {
            0xE7FD076A1918898EULL, 0x0659F18A490984A2ULL, 0xBB8D2D416E21EA75ULL, 0xC1452BACBD30EFC4ULL, 
            0x863EE747FD8AC6A9ULL, 0x1B7E59053149A5B9ULL, 0x435A29F688CC4881ULL, 0x00F210A150574F23ULL, 
            0xB68EFAC8D3166181ULL, 0x2CADD7F62E015EE8ULL, 0x90CEACF0241B7672ULL, 0x2D4515B0AA65AF6CULL, 
            0x0DC662203A08195FULL, 0x72211D929BC5FBCCULL, 0x9AE5F5307CA64149ULL, 0xC255A09DAD918D9CULL, 
            0x15BBB67CDDC9CE2AULL, 0x125BB89229E21AF7ULL, 0x4D04BCD265066C0FULL, 0x55BF5B63E2799ECDULL, 
            0xF88B8DF16E0666F7ULL, 0x35350D9E5A7019E7ULL, 0x4B7ABF4331681293ULL, 0x97688E2B99D10207ULL, 
            0x2B136FE5CD66F38AULL, 0x8AD620963F351093ULL, 0x5767FCD01373BB5FULL, 0x098F310DF110D0BBULL, 
            0x036C453192FB0AD7ULL, 0x6A5D09342C43BA89ULL, 0xCFE6DF785EAC0A03ULL, 0xB1100038CDB1D7D5ULL
        },
        {
            0xB960014E9BB0E6ABULL, 0x102A1F0097B87BF9ULL, 0x932CE24F5557CEF8ULL, 0x7B7C61D569056040ULL, 
            0xEBB01692914F77C5ULL, 0x39525BB8FF141BF4ULL, 0x07ECA343114E37F3ULL, 0x2BFCC465ABEB534BULL, 
            0x96162B18D3E7B6EFULL, 0x52BE8CA24DDB3040ULL, 0xF01B151D295019AFULL, 0x8E908437C7DBFE6FULL, 
            0xEF5B7082ABDF67DCULL, 0x292E96CC4BC0E76DULL, 0x29345BDE1461A180ULL, 0x9759A3A071FB503FULL, 
            0xBAC04E4832E08E25ULL, 0xF45A203E2B3B6AD7ULL, 0xD2CE17DEF3D0F5B0ULL, 0xDFB17497483F18AAULL, 
            0x29DFD8F271F302A3ULL, 0x6850AEE71B5CCA3DULL, 0x45241852BC80F91BULL, 0xC785AA56F7EF3438ULL, 
            0x7BF89E452058E334ULL, 0xEB041D65E33CB67BULL, 0xBD7303A9478E4F98ULL, 0xE3B776C074250DC3ULL, 
            0x5AFF1D2706E5CB36ULL, 0x9550B8DCB4404336ULL, 0x82C2C7D5C665AF0BULL, 0x2990DFB8C885EF5EULL
        },
        {
            0xCB9942118CA86FDAULL, 0x1DA6B6278427C757ULL, 0xCDB972DDF2A971F9ULL, 0xF1C4AA747EEF0369ULL, 
            0xE807B4BFBA66A8F4ULL, 0xC44367E9C2208852ULL, 0x0E066450898B72D5ULL, 0xC77AB67F2D505FA3ULL, 
            0x11F0B0E7002BAF96ULL, 0x64690F799A615114ULL, 0xCE073380113C7887ULL, 0xEBC181CD5B944EECULL, 
            0x65E288DEE6C24815ULL, 0xB84E6B5783847AC7ULL, 0x3E06C6910E1C0850ULL, 0xB0E56E699CB9CC64ULL, 
            0x4B6CC297C048E4C2ULL, 0x877B10FE1C61090FULL, 0x1EC417482A687D55ULL, 0x83785E30A975E996ULL, 
            0x00104173497C9756ULL, 0xC73B3A2BF7FDDE4CULL, 0x2F83363F7F5F8FC3ULL, 0x48847143398E9B85ULL, 
            0xF6ACBBC0CDC86634ULL, 0xA65CC5231B9DEEF0ULL, 0x12437DCB14BDF54EULL, 0x6806EB0C7EFB33E5ULL, 
            0xA5546703FD4FB799ULL, 0xA1735A4E89129B5DULL, 0xD66E43D43780E153ULL, 0x19537B45687476D1ULL
        },
        {
            0x5817F4F836470ABDULL, 0x1FD5DA14A190230AULL, 0x260D94DA7E9EB14BULL, 0x80CD71EC5FB117ABULL, 
            0x0AA83820D3E50C6AULL, 0xC973549552F6568EULL, 0x12D1BBB462EEE018ULL, 0xAAE16FA28C75D2ECULL, 
            0xE0B7B65975ED8344ULL, 0xDCC12916133DCA25ULL, 0x57A037A03009A586ULL, 0x8733BEC6051DEA2DULL, 
            0x2C7078FBDD5C5397ULL, 0x5DE2BA105DBFA257ULL, 0x08CD59B42143E168ULL, 0xADA2333E41F394FAULL, 
            0x59891C4501E795E2ULL, 0xE9453371DB99AC93ULL, 0x8F3C2B5E2800169AULL, 0xF0DF60BC56280A97ULL, 
            0x6E5FB62F9923DB2FULL, 0x002F8D60116DE9F6ULL, 0xBBAF21F3D6580A27ULL, 0x0F9C9B7205E51E0DULL, 
            0xEB2C48D99BEE068CULL, 0xE41B694F811A1CA2ULL, 0x8191D0CDB8037A65ULL, 0xEB6C07051DCE87C1ULL, 
            0x47AED564453B7AB0ULL, 0xEBEB12BAEC26F45EULL, 0x43BA9DA2338C3008ULL, 0x93728204AAA134A4ULL
        }
    },
    {
        {
            0x9D4A30A2A58CB812ULL, 0x1F633CF594E415B7ULL, 0x5900E2D937ADA589ULL, 0xE3C6DA4CFF2E44C9ULL, 
            0x56DB9DFA4B1006AFULL, 0x2FE6714A6F47CACBULL, 0xAF35BF8AE9E33131ULL, 0xC9E89C0339A44F62ULL, 
            0xA3608079AB6C90E0ULL, 0x2830F2738BEA8D54ULL, 0xC604BC0E35CA631DULL, 0x564F56E96B8B5431ULL, 
            0xC5907836AED84F67ULL, 0x1542887A35AD898CULL, 0x2C57EA26CF4CFE6AULL, 0x03E46197940D98DEULL, 
            0xEFA0FFB27B4DDEC6ULL, 0x739B9E9795DB598BULL, 0xB2B8008CEF8910D4ULL, 0x601017BB26678132ULL, 
            0x882EAD5D7C2F555CULL, 0x69FAF89AC5F22345ULL, 0x1D972412ABE4E0AFULL, 0x4D95D81C26A6BC7EULL, 
            0x1AF9356CC2432455ULL, 0xC2396E7B7B1716D3ULL, 0x2CFDAD9F13A2DB44ULL, 0xBA4E71AB1A450278ULL, 
            0x759586D44ECFEA1CULL, 0x004E55DAE9E1E00CULL, 0xE0F7931BACBA216CULL, 0x407795D8829DCF9BULL
        },
        {
            0x7579A23259FB80EFULL, 0xC602A7F9B08C16DAULL, 0x0FAE26FEF03DE88AULL, 0xF1C78C3E37F403FCULL, 
            0x8CE17F97CCE356F5ULL, 0xD0DE2DB92FF14141ULL, 0x25B58B7F10314C7DULL, 0xDE793124CF7500D4ULL, 
            0xA346AB963B4BCCE4ULL, 0x1E52ED78240832B3ULL, 0xE73D6C9960D30746ULL, 0x88A8F73F4D94D7C6ULL, 
            0x62DBFE0E683EDFE6ULL, 0x72908E83E87C95A2ULL, 0xB4807A427A6AEC23ULL, 0x976E73617C7B6B1FULL, 
            0x600141B74560C18CULL, 0x9E81C7B4FBBB1A3EULL, 0xA3D6EB21FC9B4166ULL, 0xAF00B0D9EF97BA09ULL, 
            0x1F18A0CAD77CF43DULL, 0x65DD4286D95DAC31ULL, 0x26FB2DD8CCF9540FULL, 0x9A6DA30D144A709BULL, 
            0x5BB37FC3B35F2410ULL, 0xECB9A01E4DA8DF4BULL, 0x2A103B3EE67681E8ULL, 0xDB3E5866A211D826ULL, 
            0x050029A996A7DD72ULL, 0x6B1DD75AE925867DULL, 0x0111990C77E5325CULL, 0x8459C5B47E5B2147ULL
        },
        {
            0x3E3C47C20B8CDE5EULL, 0xB9F103F4EC7034FBULL, 0xFD5EBEED638FFE2FULL, 0xC9A84F73DD68A266ULL, 
            0x79960D90E4AD5294ULL, 0xD1204B22C3F86572ULL, 0x82C1E24BEEB55120ULL, 0x22A5E42435D96CACULL, 
            0x61ED87D673834A1DULL, 0x9B74676BCF423D70ULL, 0xFF45B7A60469DDB9ULL, 0x9A6D47BA453886E0ULL, 
            0xFB3F648086E77704ULL, 0x2066F055261943C8ULL, 0x685ECDBAE676EC7BULL, 0x90EAFEE0908765DEULL, 
            0x877DBF81D1E52E36ULL, 0x50EECA0682293203ULL, 0xBD69173DC1B038ECULL, 0xC651FFF980427D1AULL, 
            0xACB5F20F107232ADULL, 0xD04DFF4FACC18E40ULL, 0x53572B8F3CA3642CULL, 0x0DF7F679970DF852ULL, 
            0x979911C1D6F9A3E9ULL, 0x03A0B46F21BA5128ULL, 0x65BAD14CE0F65332ULL, 0xF2F9E6B0FE718159ULL, 
            0x9F3BC542B5C5D1A0ULL, 0x8F244430EE35F35AULL, 0x212838C99FD3CD38ULL, 0x78FB452525F3B36EULL
        },
        {
            0x816456DE2233A042ULL, 0x5CA5FF9179C06136ULL, 0x3B3DABA53BBC5062ULL, 0xBF92F1F3CB21690AULL, 
            0x3EE15A512F63F91DULL, 0x6F9E9916A7730AA1ULL, 0x2EBF60D1645CA37DULL, 0x310D65508BEB795AULL, 
            0xAB0C8AEBC3E73CD8ULL, 0x452E4C428AF8E327ULL, 0x4805BD32B4768350ULL, 0x94A9B137B36CF8B1ULL, 
            0x3BD87DD49CDB53ACULL, 0x3F57B54369D0E8AAULL, 0x250A799547DCD34AULL, 0x1A13C5016B0FE55FULL, 
            0xC9F6C30E32BECCE3ULL, 0x067D00AA053EE6AFULL, 0x593905F8DB715698ULL, 0x0AD74A1875A25AD7ULL, 
            0xF8F14EFBB2706D6AULL, 0x614DB5E2FB0AD143ULL, 0x2585122311C70A82ULL, 0x9BDC005B9F9B22A8ULL, 
            0x0965750BB00FACA2ULL, 0x3B754326A45CCCB4ULL, 0xC555A19CCDE87552ULL, 0xE63DD15F2A150759ULL, 
            0x33B4F675871DC5F3ULL, 0xD2A0F8A68F7543A3ULL, 0x8B9738BC9DD6FC44ULL, 0xF9442BEEB3A2CF6DULL
        },
        {
            0xCD296ED3990796BCULL, 0x8845FB5147A9D1E6ULL, 0xF9453517928868D3ULL, 0xD0B0804E558C245AULL, 
            0xF85C1D18A413902EULL, 0x453133896D5DA059ULL, 0x272DD75FB49871EDULL, 0x1DA14D85D8D4325AULL, 
            0xD8769E9FF7538C11ULL, 0xC1F85801500C330AULL, 0x1E3A15ADD21F0E1EULL, 0x8342978BADB91C5BULL, 
            0xA035DACEB19FFD99ULL, 0xD54A02F76848F35EULL, 0x03C96E882BD14D84ULL, 0x72CFFEB45BA32017ULL, 
            0x465A20B4C43C61A0ULL, 0x89C424F529FB5FA3ULL, 0xEA4D30A29D7155D9ULL, 0x670658ADF7CAB41AULL, 
            0x9DD1A237A10A2379ULL, 0x8BD306097FFA8EF7ULL, 0x39C112EEC54281F0ULL, 0x80AD7E295B6C438EULL, 
            0x6DC4EC4C552314F8ULL, 0x291BECCB6637BD3CULL, 0x3405DEBDEF08170CULL, 0x9A11AE123F6CD8DBULL, 
            0x264ECEE5070FB050ULL, 0x755BC59BDBEC6C13ULL, 0xD397364F3363870CULL, 0x1C1202571AB60765ULL
        },
        {
            0xE01CE791F267D709ULL, 0xB3DD4DD49C2FC6E5ULL, 0xA6485DD06EB9356BULL, 0x7244E1E3460B9909ULL, 
            0x9A0CB50049002A16ULL, 0x3260C95A30F4BB56ULL, 0x06DAAE33308BFC4BULL, 0x17E0CB9E1389548BULL, 
            0x750BC4EAD7CDBE54ULL, 0xB5818A60776052F6ULL, 0x06A2F2AA8D94BDF1ULL, 0xA8ACB506878BD357ULL, 
            0x6DC4CAB2155D08E7ULL, 0xE58EDAC487B9A081ULL, 0xEE7E1D2565B112AEULL, 0x5749586D8390966BULL, 
            0x173AB68F4454F6E4ULL, 0x9C46EB96C81DB1CCULL, 0xCF58E6BC68E77A49ULL, 0x5AFA3F984A08B170ULL, 
            0x5E8F49279D2F8D95ULL, 0x7CCB6767B1AC69ABULL, 0x806C6423C4F828FEULL, 0x01C34EE5A5A6E60DULL, 
            0x1B050C68274E3730ULL, 0x9240E3A43D359335ULL, 0x6D4FF3C600CD1FF1ULL, 0x5B69D3C6FD032236ULL, 
            0xC6C98044549B93D6ULL, 0xC7B5E71E93D5AC94ULL, 0xA5EBD6C24CD16F93ULL, 0xA08016EAE3ED212CULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseHConstants = {
    0x8040277A5B731057ULL,
    0xD7872FB735D0F3AAULL,
    0x64EFF29BD0216BFFULL,
    0x8040277A5B731057ULL,
    0xD7872FB735D0F3AAULL,
    0x64EFF29BD0216BFFULL,
    0xBF84EC9735EB6CBEULL,
    0x454E6E8786D5D6ACULL,
    0xC4,
    0x32,
    0x16,
    0x9F,
    0x65,
    0x81,
    0x99,
    0xE1
};

