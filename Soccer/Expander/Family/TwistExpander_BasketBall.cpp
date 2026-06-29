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
    std::uint64_t aPrevious = 0xA925F20F2FCFA91AULL; std::uint64_t aIngress = 0xEABF72E7D23B931CULL; std::uint64_t aCarry = 0xA948DB61843E51C9ULL;

    std::uint64_t aWandererA = 0xA58F6EBD47238B12ULL; std::uint64_t aWandererB = 0xD69B7DDEF3085814ULL; std::uint64_t aWandererC = 0xB00CC45CCBB9D3DCULL; std::uint64_t aWandererD = 0xCA022BB2DCEFCE5DULL;
    std::uint64_t aWandererE = 0xEFCC46BAEFD38F58ULL; std::uint64_t aWandererF = 0xA3AF017DD30F37C4ULL; std::uint64_t aWandererG = 0xB66B6A6933A5124AULL; std::uint64_t aWandererH = 0xD431EC465963625FULL;
    std::uint64_t aWandererI = 0x960DBF16C9A3FB6CULL; std::uint64_t aWandererJ = 0xBE141DEA313F78B8ULL; std::uint64_t aWandererK = 0x8E92B93AE97DBD6DULL;

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
        aPrevious = 10999616136972731751U;
        aCarry = 10426171822121799708U;
        aWandererA = 13939710679966084877U;
        aWandererB = 13636274055499830140U;
        aWandererC = 17476022643709160496U;
        aWandererD = 16041966639205341921U;
        aWandererE = 18394991883955500455U;
        aWandererF = 16568166803336512403U;
        aWandererG = 17439992613875006776U;
        aWandererH = 9953822277736070517U;
        aWandererI = 15271704038618952127U;
        aWandererJ = 15341484995864248158U;
        aWandererK = 12800147434308550885U;
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
    std::uint64_t aPrevious = 0xCAD93930EB993319ULL; std::uint64_t aIngress = 0xB55F845586101928ULL; std::uint64_t aCarry = 0xDBEDA43B4EFB834BULL;

    std::uint64_t aWandererA = 0xF0631DA185F26011ULL; std::uint64_t aWandererB = 0xC2DB319A3126B319ULL; std::uint64_t aWandererC = 0x92039CBC46131B59ULL; std::uint64_t aWandererD = 0xE0F48032BE1FC57CULL;
    std::uint64_t aWandererE = 0xA42D5A7E3D9B7C38ULL; std::uint64_t aWandererF = 0xFD69E1DF7B85664EULL; std::uint64_t aWandererG = 0xB1014BF014BAE235ULL; std::uint64_t aWandererH = 0xC4CB265C935221C3ULL;
    std::uint64_t aWandererI = 0xC3615DE6D30842C0ULL; std::uint64_t aWandererJ = 0xCD25FBF8DDF60FF6ULL; std::uint64_t aWandererK = 0xBE99B8119E900357ULL;

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
        aPrevious = 12044649426904460407U;
        aCarry = 11800463015725385973U;
        aWandererA = 17936748220740782422U;
        aWandererB = 10531836142015709938U;
        aWandererC = 18019443502708969744U;
        aWandererD = 15695379578583942734U;
        aWandererE = 10145972239592015547U;
        aWandererF = 14154506484345852275U;
        aWandererG = 11270035499384827081U;
        aWandererH = 11404347838051045869U;
        aWandererI = 15583400214699245542U;
        aWandererJ = 15080764077294542531U;
        aWandererK = 15585060111861310122U;
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
    std::uint64_t aPrevious = 0xCCB6CB2C1423A973ULL;
    std::uint64_t aIngress = 0x889BC75DFD01AB35ULL;
    std::uint64_t aCarry = 0x99DC212A094F411CULL;

    std::uint64_t aWandererA = 0xA7C5707235A8C8CCULL;
    std::uint64_t aWandererB = 0xDC5FF8D13E0F9C33ULL;
    std::uint64_t aWandererC = 0xEFB375B925E5926FULL;
    std::uint64_t aWandererD = 0x981A289E1153EC83ULL;
    std::uint64_t aWandererE = 0xB7E3CD66C2FB5D22ULL;
    std::uint64_t aWandererF = 0xA10B44F5381FE82CULL;
    std::uint64_t aWandererG = 0xEE571CBB7B23301FULL;
    std::uint64_t aWandererH = 0xCAB4A7FFF4A08A07ULL;
    std::uint64_t aWandererI = 0xC4E93C1AFE52BA4CULL;
    std::uint64_t aWandererJ = 0xFF93451B28DF4A5EULL;
    std::uint64_t aWandererK = 0xE0022081DFFEF11DULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
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
    std::uint64_t aPrevious = 0xA822C852A7A01763ULL; std::uint64_t aIngress = 0xDFD76DF4A219B7ABULL; std::uint64_t aCarry = 0x959F07006A4723E4ULL;

    std::uint64_t aWandererA = 0xD0A7A99C3167FBF3ULL; std::uint64_t aWandererB = 0xEF6F348B2767BD46ULL; std::uint64_t aWandererC = 0xF1B0153493D4455DULL; std::uint64_t aWandererD = 0xB26C9D17F0C24687ULL;
    std::uint64_t aWandererE = 0x81FF73B8C46E393AULL; std::uint64_t aWandererF = 0xAB43642893B87170ULL; std::uint64_t aWandererG = 0xC5D6E5557AB85036ULL; std::uint64_t aWandererH = 0xADB25F056020404BULL;
    std::uint64_t aWandererI = 0xF3994F1F9B9940CFULL; std::uint64_t aWandererJ = 0x8AFED1454C4B75D4ULL; std::uint64_t aWandererK = 0xA4DEAAD5077887A4ULL;

    // [seed]
    {
        aPrevious = 15656037436495135448U;
        aCarry = 15966987754156067593U;
        aWandererA = 10365990340640463013U;
        aWandererB = 11599389880086312393U;
        aWandererC = 9542132352705906427U;
        aWandererD = 11102838907748760534U;
        aWandererE = 9417725051623542416U;
        aWandererF = 12839552326494085347U;
        aWandererG = 18374494216361718183U;
        aWandererH = 13433495999842014857U;
        aWandererI = 14452725350022713541U;
        aWandererJ = 12019366166209267211U;
        aWandererK = 11739481007865727115U;
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
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 3, 0 with offsets 1007U, 5172U, 7741U, 1704U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1007U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5172U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7741U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1704U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 1 with offsets 6334U, 4849U, 4910U, 462U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6334U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4849U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4910U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 462U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 2, 3 with offsets 6897U, 5637U, 2068U, 7456U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6897U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5637U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2068U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7456U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 2 with offsets 8041U, 3276U, 6U, 1607U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8041U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3276U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1607U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 3, 2 with offsets 1370U, 1824U, 1349U, 2030U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1370U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1824U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1349U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2030U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 1630U, 835U, 1551U, 170U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1630U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1551U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 170U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 3, 1 with offsets 804U, 1672U, 1034U, 1636U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1672U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1034U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1636U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 703U, 1963U, 1078U, 1791U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 703U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1963U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1078U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1791U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1502U, 1825U, 230U, 1899U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1502U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 230U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1899U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 3 with offsets 5296U, 3558U, 2651U, 4774U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5296U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2651U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4774U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 0 with offsets 7170U, 4427U, 1509U, 5134U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7170U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4427U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1509U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5134U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 3, 2 with offsets 5447U, 795U, 4318U, 5906U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5447U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 795U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4318U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5906U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 0, 1 with offsets 925U, 6993U, 5544U, 4375U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6993U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5544U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4375U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6861U, 4430U, 3352U, 837U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6861U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4430U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3352U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 837U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 261U, 1030U, 1963U, 783U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 261U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1030U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1963U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 783U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1691U, 155U, 913U, 1836U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 155U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 913U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 105U, 1026U, 181U, 358U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 105U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1026U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 181U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 358U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 957U, 928U, 1449U, 504U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 957U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 928U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1449U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 504U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 431U, 43U, 863U, 409U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 43U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 863U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 409U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseASalts = {
    {
        {
            0xC23ED64D5C956F98ULL, 0x84E5A0BDA6F11570ULL, 0xD4823E87D93843F6ULL, 0x8221FFEAE14E4C03ULL, 
            0x947B2235B744B8BFULL, 0x8EEF0CF6DC945E1DULL, 0x5A1EFFC9647ED5DDULL, 0xCAEB16664681A87CULL, 
            0xD615819A8EC81041ULL, 0x26CEBFCBAD44E706ULL, 0x3A5FBECF3BB0309BULL, 0x3E20F593BB7D2E17ULL, 
            0x1C215CC6125EAFABULL, 0x4D2A28C2322E58C9ULL, 0x6AA0900DEF106C17ULL, 0x93075FE07CCB81C8ULL, 
            0x0BBC2DBBAE660118ULL, 0x4BC4F61610AA0F2BULL, 0x5E9163D4E44FA166ULL, 0xE87D99A5C1450ACDULL, 
            0xD68243C0CC478808ULL, 0xEADF0F3AACB46912ULL, 0xEBE3D5B62F1EBF78ULL, 0x725608EC8FDFA3B0ULL, 
            0xE02D32E4CE7BD4A7ULL, 0x6A1C011137084C24ULL, 0x66BAFB98222669AAULL, 0x5F09C7A1ECB683CCULL, 
            0x7B886040CADD6E63ULL, 0x4F6563FDCA7A9DFEULL, 0xC65DA9C3C24D33ABULL, 0xC34DAE2AE56268FEULL
        },
        {
            0x335157E29F49E31AULL, 0xD1DDD50E33FC27B9ULL, 0x12F39EBD6F3E1F0FULL, 0x555FAA74ABDCAEEEULL, 
            0x9D2CB59E8B8DC170ULL, 0xA5E484E298FA0B2DULL, 0xDC50F36869BA350AULL, 0xF4769CBFAD6CFC2DULL, 
            0xC5000ADCA3AC7FB2ULL, 0xD3DC70C02888C225ULL, 0x7FE417004FD174ADULL, 0xAFCA61CA15ECCD05ULL, 
            0xA960F6D07B022D26ULL, 0x29035D23EBBC1774ULL, 0x80567684A9BA95D6ULL, 0x77BBBB17AB9B5B42ULL, 
            0x8A0C5719A1783509ULL, 0xB437DC65AE965CE2ULL, 0xE39E2751C2A35DE6ULL, 0x0D41970B121011F3ULL, 
            0xC6CB526B0DC470EFULL, 0x8465ED95168B8696ULL, 0x58D11D653E6863EDULL, 0xE429B10BA6908E31ULL, 
            0x66BEE163C24663CCULL, 0xA7946F807001ABF5ULL, 0x9279D04D15F69EC1ULL, 0x72BBA194E69335B7ULL, 
            0x7E636FFA4340FAC8ULL, 0xC9DE7272391311E3ULL, 0x6C39281FCCB2F8E2ULL, 0xD2DD66978E213ED5ULL
        },
        {
            0x9A4A37877BB0C3DDULL, 0xF9B6736AAC54348AULL, 0x43C18F2FC24A31A7ULL, 0xF291AFF59D253D7AULL, 
            0x1AD9245377FC2687ULL, 0x0953820506BF9ACAULL, 0x07731B824A3F7E10ULL, 0xA0FBA1B8E1E28289ULL, 
            0xA9909B46CA54CF65ULL, 0x5AFA82E535FED929ULL, 0x285A26DE54EE70F7ULL, 0xE0198DC167E7EF9BULL, 
            0x8390AE7840614573ULL, 0x5542B8E03E339B06ULL, 0x15A3DC58F5CDF4B5ULL, 0x29C1C7CB76AD3A6FULL, 
            0x5120E8CDDBB658E3ULL, 0x57FA1F33B47EC456ULL, 0xB2092ADB3DE88C80ULL, 0x6764B2A571907404ULL, 
            0x55784D8B94E30857ULL, 0x1F0F3426418D0627ULL, 0xC16472BF73547BF6ULL, 0x3E1DF5086D4B4BAEULL, 
            0x108A5F08F50EB5E9ULL, 0x0DABBE343FE7BF71ULL, 0x976B371C6B78AE11ULL, 0x5F4131F35980B5BCULL, 
            0x62BEF85F549AFD7CULL, 0x672D29D246636159ULL, 0xDD8BAB673D78CD32ULL, 0x70E514FAC788C42BULL
        },
        {
            0x47E6E261D8E8076FULL, 0x26419BC7ED4C37D9ULL, 0x1D69A7D77F22643CULL, 0xA11F199E7CB3F4ADULL, 
            0x1CD157AA936BEE3FULL, 0x2CA1C7172C4FA5EBULL, 0x21C034C28CD431B6ULL, 0x477F0E90E3FDAB01ULL, 
            0x366C6FDE9FABFA47ULL, 0x4E5DBC046B40AF1EULL, 0xCDBB452327FA6D5CULL, 0xD7000A9095ECC192ULL, 
            0xA0B09989610C0ECEULL, 0xC0B504C7BE0B4E10ULL, 0x3D40E449FC8E97BCULL, 0xE11ADB2C8BDD6BAAULL, 
            0x965F4C8BB4B5F0BDULL, 0x4C5FF1062132B945ULL, 0x97E5AB6D1DE6B212ULL, 0xE483B11E173B4A3BULL, 
            0xF95709928886C4AEULL, 0xC993D3F594A320F7ULL, 0x0E8F1A8C3528D917ULL, 0x8146C3159AB41614ULL, 
            0x28DF64677D787F85ULL, 0xB866BD92FEF81CA1ULL, 0x8D366B994CE9934CULL, 0xDFDDEA15FA46EDF9ULL, 
            0xF9CA808FA1F207B8ULL, 0x1A87401F0F852C41ULL, 0x2C1DA4DF6727FD14ULL, 0xDEB4CDAEDCDC0992ULL
        },
        {
            0xAB96193F42F7C5EAULL, 0xF2124003425667B9ULL, 0x84DF3F680436CB4AULL, 0x4A2B09650C871C50ULL, 
            0x64B8BF8318AC26A3ULL, 0x4CE9A657CB0F1FE5ULL, 0x920737DDBFBC32A8ULL, 0x0878D79B249DA180ULL, 
            0xF997F61514DEDBF2ULL, 0xE9F2BA5216FA7387ULL, 0x56936251FC27A0B8ULL, 0xBF95C338ECC49807ULL, 
            0x194FE711F5D651DFULL, 0x5CC25A7A285DE2E4ULL, 0xBA7556DE78EC735DULL, 0x848127D0E524E2CDULL, 
            0x5AECCC4A0F3C039FULL, 0x31005DBC81DBC036ULL, 0x3B1D8D24039B5423ULL, 0xB6EF64AFDB48C203ULL, 
            0x0BFA1343E835B94CULL, 0x3C2E8AEDFC49D148ULL, 0x7333D68154707A23ULL, 0xE97F04D8C11EB900ULL, 
            0x2E0951730C69D629ULL, 0x055B9706F7B75EF0ULL, 0x2FC387C219CB4C96ULL, 0x1C62B8FD0B29A0B1ULL, 
            0x23EDBDD18DC93C04ULL, 0x4B39FACC241B965DULL, 0x39C3A7006053CBE3ULL, 0x36D495B798D2B88BULL
        },
        {
            0x5F45CCD8E51260D0ULL, 0xB1691D4A0D462062ULL, 0x7F0F10A94A37563AULL, 0xDA2A1B653B827003ULL, 
            0x3B89E3F8EC0B0CD1ULL, 0x18EFB4D3405236BAULL, 0xC6D5F2D950F6281DULL, 0xF7ED42D7872003BCULL, 
            0xF5B4270DA30E2C8EULL, 0x80E38F658D17AE60ULL, 0x8BAB59661FB6CFD8ULL, 0x86AAB5C65CB4E3C6ULL, 
            0x5A5D81F919222493ULL, 0xFB153D7CA2D284EFULL, 0x14E99DB80DCA98F7ULL, 0x17B8E78598485A5CULL, 
            0xB1DC4F220D162AF4ULL, 0x457A88DA954D6292ULL, 0xAD2046FF8F4336D5ULL, 0x42953F179DF7ED27ULL, 
            0xC49362749486B2C0ULL, 0x57B2057A0A8D4553ULL, 0x6ECFEA117026F20DULL, 0xEBEF86505974265AULL, 
            0x51810F1A3CD8AEF6ULL, 0x4004EE77E43C3BD4ULL, 0xFA5F9F3B09868A19ULL, 0x0D8D4D2FF33AD1D8ULL, 
            0x1C03CB1A08E21E85ULL, 0xCBF5FA1C6D88E664ULL, 0xC6EB7A3FDDE54DBEULL, 0x71CE38695EE762D9ULL
        }
    },
    {
        {
            0x81DF39EA2AFCC124ULL, 0xAD0429EC3781CB6AULL, 0xF0F1798A174A4178ULL, 0xBA17F6DE35829C77ULL, 
            0x91C3ED3654D45D67ULL, 0xC2F3737179DC3F39ULL, 0x4DFBCDFE302419F8ULL, 0x07FC2A2C959A4026ULL, 
            0x11E5796A03416B41ULL, 0x704335E0172B14F3ULL, 0x27D4E2872C354CA3ULL, 0xE70501A782970214ULL, 
            0xBC4794E4A703CF37ULL, 0x559759DD50AEC761ULL, 0x9D87D60D5B198C67ULL, 0xB2084C69CF81ED7BULL, 
            0x3DBC9D92A69CB305ULL, 0xC118AF9FED103A0EULL, 0x6ADD0C72BE82BE22ULL, 0x36A0C1A4F9F01612ULL, 
            0xD8A841CC8047E716ULL, 0xAB67F10AE724DD3CULL, 0xDC35860C858877EBULL, 0x778BC8A6E2B7A30BULL, 
            0x6059AE8E94E84F06ULL, 0xE44FB37AA8958E64ULL, 0xB47754B5B0386EC1ULL, 0xBD10393859A1B3E8ULL, 
            0x352F548F26891105ULL, 0xCF605B516045D5E5ULL, 0xC6A78C951E0B2228ULL, 0xD8105F2084B629F7ULL
        },
        {
            0x099F0E1BB976D41FULL, 0x40CE5BE4714B55A0ULL, 0x14EF1F15D3999727ULL, 0x56AA4C76B072B77FULL, 
            0xE41278A8D54BEE4DULL, 0x8D36E3DD75CAEA8CULL, 0xE7DE8940E2AE989EULL, 0x7EFA3EDD30FA890BULL, 
            0x9FDB7457A4D124D1ULL, 0x2E52F461ABC8ED73ULL, 0x06ADF5FFA9031DB1ULL, 0xB13E6C86C014C79FULL, 
            0x42DC619E26FE8E7AULL, 0xEF595F7AB91AC492ULL, 0xD284E36611F30F9DULL, 0xE0301E88B36651D9ULL, 
            0x8FA0DCBA886C15AAULL, 0x95CE68D548546DC6ULL, 0xD75B782A112A8255ULL, 0xB347B77EED874B27ULL, 
            0x480733E7A1E11EDAULL, 0x50D33A52581E5449ULL, 0x31CD3AB5BE36F0D5ULL, 0x0229FB5FDE06476BULL, 
            0x6295E31ED58FC054ULL, 0x65B0B01289096906ULL, 0x46B17D6B717E2A12ULL, 0x2F969E551B9FF9E4ULL, 
            0xA3E531BCF2FAC4F9ULL, 0x7EA4734DF6A19595ULL, 0x98E163E0682902AFULL, 0x1B69252F08DBD02DULL
        },
        {
            0x7427F9BA63F67BCDULL, 0x9A1B1F24DD3C6CEEULL, 0x49F5462FCB295824ULL, 0x81DC0039B85E14CCULL, 
            0xB6990DB7AC10D833ULL, 0xDC7C1983DE7CBB90ULL, 0xA436F97BF9BD08A8ULL, 0xA269B920CDEF3447ULL, 
            0x87574504540A9E85ULL, 0xD895BE2033606994ULL, 0x1047C38C89006BA1ULL, 0x6B946553BE13953EULL, 
            0xC8AD677AC5408A44ULL, 0x224FFC281AE734DEULL, 0x2DC60DDE92E5E3F6ULL, 0xAE0810928C4B3010ULL, 
            0x9A50340A566BD5BEULL, 0x35644CC0A8C31101ULL, 0xAAD6B24AFE71C569ULL, 0xCC6294B50454E73BULL, 
            0xC4E0A87ACEB76DDEULL, 0xBA3CE553DB8F9937ULL, 0xF29AF6275FCBACF7ULL, 0xB06C1D509926888BULL, 
            0x44A0AC318E2AFF4FULL, 0xA8ED8D2B3D4321F8ULL, 0xDB9C0B7F23F35EA3ULL, 0x7F58F46CB02A709DULL, 
            0x3933F354A7BB59CCULL, 0x756F80046652F393ULL, 0x94FEFA430B3AECDCULL, 0x978731601C519CACULL
        },
        {
            0xDF83606EDAB93A04ULL, 0x3DBC8E0794ACEDC1ULL, 0xD47269D4B2BE550AULL, 0x8B045FE226A2756BULL, 
            0x0CC7B7425CE1F6C3ULL, 0x535FF0D87940B557ULL, 0x8FC13A1F53D2F58CULL, 0x275EDAD5C3380C1CULL, 
            0x015D4AC4F8E5352BULL, 0xAA22C299F4C7B734ULL, 0x50A3610B032056B0ULL, 0xAA776B0E8E1A0948ULL, 
            0x22CDE7FB4650C48AULL, 0xA88E253718E88D78ULL, 0x589059C49AD71A64ULL, 0xC8EC759375F94328ULL, 
            0x9121D6D967591E0FULL, 0x06CAE01EC76EF30BULL, 0x54ADE4994B0BD27FULL, 0xE4062EA507F75EDDULL, 
            0x16A4A60BB2AAD4ADULL, 0xCF28BD85C837DB48ULL, 0x7A614720868CDCA4ULL, 0xF13C019FE0895925ULL, 
            0xCC208E3674EEB80DULL, 0x87FB18121983D99AULL, 0x6587506160A12A8CULL, 0xF275604B8278E0EBULL, 
            0x08193E448AC0B8A0ULL, 0xA64759D56C9E5A5DULL, 0xF502DC29B4EE1BD3ULL, 0x40AEE607E8E3CF96ULL
        },
        {
            0x02F29031954F10DEULL, 0x04ADB9C425C4380AULL, 0x3E6A72BFCA2DA89EULL, 0xFF4939D7D3A84DF1ULL, 
            0xE08FA497BE68900FULL, 0xAE654DA107A6E5A1ULL, 0x841F42645564B693ULL, 0x05A30CED9146D536ULL, 
            0xDE1A4EB1CD40F359ULL, 0xB83B2083C7492316ULL, 0x91029213500D5E53ULL, 0xDF9BE1C909B58E97ULL, 
            0x894CEB44E0C68775ULL, 0x03B44421EB18190FULL, 0xAA0E43212CF8BC85ULL, 0x672AE918456EB483ULL, 
            0x1C5B9324D91CB7DDULL, 0x4D8A7B64E1A2F0F4ULL, 0x5AD159697698B0BEULL, 0x626CD1FBBDEF6B70ULL, 
            0x7B95DB95AF3687FFULL, 0x1B278B7B48FBE729ULL, 0xFA2BCF2C55D17310ULL, 0xADBD8E5726E31363ULL, 
            0x4427C4C193D742A5ULL, 0x124090702185A97AULL, 0x71B6FC792D16A559ULL, 0x2B55B92219459123ULL, 
            0xE2AD52E840B5BD0BULL, 0xC0AC3725FAED5025ULL, 0x03CCE240064208EEULL, 0x1C680BBABF953ADDULL
        },
        {
            0xFA3C4D7B4D5F5983ULL, 0xCAD01E1A12B2BC08ULL, 0x922E4BA3ECA56D2BULL, 0xECA3B63302D11C16ULL, 
            0x7D56A51162D24C51ULL, 0x302CCB4EB4543BD0ULL, 0xB7D5E532FA446743ULL, 0xF26AD6DF792064C1ULL, 
            0x5D76342C96526F9EULL, 0x7A93411D21560971ULL, 0xE89D69619083FD28ULL, 0xB9386F834A380034ULL, 
            0xA8A214BDD9108DDCULL, 0xEEF70A758805D566ULL, 0x0BD380049AEC9997ULL, 0x5068F2646AE11710ULL, 
            0xE1938A6759024401ULL, 0xB8F976797A315286ULL, 0xC8ABA0E83C8D89FDULL, 0x7C19349AC6F6F0FDULL, 
            0x46CE8E50CF85643CULL, 0x741D5AF710B0DF80ULL, 0x93EF7EFB2946A64AULL, 0xEDC5EEFD7DC6240DULL, 
            0x5C2240C80A2974A4ULL, 0x92280EC8232223FBULL, 0xD7DD868149577B6BULL, 0xFDC751F02492020EULL, 
            0x91135671DEBA05B9ULL, 0xC1C65F34D40F6CF3ULL, 0x548A6CF10D784308ULL, 0xC5F1EDAFE8C04EF5ULL
        }
    },
    {
        {
            0xA4F2FFE214C67B21ULL, 0xFC18FC1DE3F0C8C3ULL, 0x9A691AF70BC0F560ULL, 0xC1152BBCA593EB13ULL, 
            0x2F098440DBD288E5ULL, 0xA3DD0C9B2639FFDEULL, 0x2794336E39DB3BAAULL, 0xC1AAC34AE83E86A1ULL, 
            0xB065116B1741AD0AULL, 0xE80B5EEE5C08F1B0ULL, 0x57C7A44DD2481B54ULL, 0x1A60AE2B77F9EF61ULL, 
            0x7D216ED406E8B0FAULL, 0x9C079533689EB9D2ULL, 0x710F5606FA2D1A1CULL, 0x91F616AD68AF5FABULL, 
            0x96F7516A32F1362EULL, 0xA815CFF11567A2C6ULL, 0x417D9C34351E551EULL, 0xDFED625C6F465EFCULL, 
            0xBAC55EB90A2AE474ULL, 0xF86402C41C0CBBCFULL, 0x83121C03C75ECA7CULL, 0x878F22CC66B12931ULL, 
            0xAFA83107096ED582ULL, 0x3C5B3865E42FACB9ULL, 0xF8767D56AEAEE95CULL, 0xAFDA356D16602C77ULL, 
            0x06C8D7444B0D8976ULL, 0xFCC203EAF6D19FA0ULL, 0x28D430F11B0DF470ULL, 0x490617443D8B71F7ULL
        },
        {
            0x63845F602184B159ULL, 0xAA2C55A7C107B8A8ULL, 0x98F0CD29C985542EULL, 0x815F0506E4FFC1CBULL, 
            0x65515D219897EEFEULL, 0xE257A2B914438EBBULL, 0xA634548BBBB6C1DEULL, 0x0235F1E37F5D1BC3ULL, 
            0xD838C05D88BD483BULL, 0xE5422F1A24894A4FULL, 0x52E946E4CCD39EA4ULL, 0x298815CA0D80CD3FULL, 
            0x940E7A86A1C5D81EULL, 0xC60622F637D1C709ULL, 0x34653D8A67060BD2ULL, 0x10B548F536E1DCEBULL, 
            0xF010ED1024C09740ULL, 0xB0D7CA374C01E92DULL, 0xEDFC603207469B66ULL, 0x620760B59425D26CULL, 
            0x59A27D364CD047DFULL, 0x48816479EDFE510DULL, 0x92D44226D66B91D9ULL, 0x40BF5E1E56B9D7DFULL, 
            0xABB13A77115168A0ULL, 0x77087A4A0B61C28FULL, 0xD3A450E8B2AE3157ULL, 0xFF1ADE195EDDBBA5ULL, 
            0x87DECB3E569099ACULL, 0x466482DC97F8FB50ULL, 0x06953BAA637A74E1ULL, 0xD22C26ABE7AB09E7ULL
        },
        {
            0xFB827A86DD352641ULL, 0x7B97C203BAED2AE7ULL, 0x6474F877520B01BDULL, 0xA22232B8E1A16B70ULL, 
            0x99B4BC494734AB0FULL, 0xC5E7B37C3843BF68ULL, 0xD34FD22831331F60ULL, 0x4107848DF22851D6ULL, 
            0x2AC1FEA470955D05ULL, 0xF819EC4BD608DBACULL, 0x12154417B71C1E48ULL, 0x329D3E88A6FB06C4ULL, 
            0x9323D941B9169485ULL, 0x7FE6955D88FF59EBULL, 0xD43A09C2B7660510ULL, 0xB6124748197DD879ULL, 
            0x7BB9AB205140C3DBULL, 0xC06BB44B5AAA2402ULL, 0x331CF1F397826328ULL, 0x840B013A31D327F1ULL, 
            0xC035CC3EAD2A8103ULL, 0x4F94E5A758166BDDULL, 0x6B0C418AD03DC29AULL, 0xC69591DF02E5B507ULL, 
            0xD5A46878D4640560ULL, 0xA4D9AC85071AF1D1ULL, 0xDFE2C25FC64D63E0ULL, 0x582846CB99CAF26EULL, 
            0x7807A0169D58325EULL, 0x5956EC85F9FCE524ULL, 0x7D940CBEBDCA8CD1ULL, 0x31AE836E61B1DBF2ULL
        },
        {
            0x5BA841C6A7C6EAD3ULL, 0x2B84CE82C968B312ULL, 0x10B9B7B2BC592349ULL, 0xD787B2B4EC330BBDULL, 
            0xA7DAA4C87217E892ULL, 0x4CD892B0811D4A9DULL, 0xBB9EF3C83D5D5866ULL, 0xA37B363FCE5DCDFFULL, 
            0xF70F9B6BEE30CC3EULL, 0x4D708D49ECD3B250ULL, 0x0F9FF6F45533E1D8ULL, 0xA7315D7E74121CCEULL, 
            0xA707597D93C52CF8ULL, 0x5B253FBAD7DA166CULL, 0x0338B02EAEEC7B8AULL, 0x5B040DF7C62D6B4BULL, 
            0x4A066DDC35F28D67ULL, 0x4735224A4CFA0004ULL, 0x34510E4252A9AE84ULL, 0x85B37457AFB88F8DULL, 
            0x58552770947D646BULL, 0x4B2AC03D4BF8A502ULL, 0xD45A5E03F3A8EB29ULL, 0x4D2CE26D409EC8B5ULL, 
            0x5CABDD7D94C0EE48ULL, 0xBC854EE06636FC08ULL, 0xEC601B3D78F7E594ULL, 0xC7A8A6369FE83E81ULL, 
            0xC93C4D70ACC1C4EDULL, 0xEE1ECD2E7BF3B035ULL, 0x878678D9AFA7A8CBULL, 0x3B15E12AB26BCFF9ULL
        },
        {
            0xF56D7285A08DDA48ULL, 0xAEA858D551FB58BAULL, 0xF2ED559CDCD8F389ULL, 0xE2F120437A38DDBFULL, 
            0xAB20515CA2623061ULL, 0x951611482933EEDAULL, 0x42B1A613F5D74D31ULL, 0xB68AD923CCC29AB9ULL, 
            0x95EB3EF346FE4A4DULL, 0x90716399C7863E9FULL, 0x08FFBE325B4273E4ULL, 0xCA414A69BE10CAC9ULL, 
            0x9A83084B28EDE9CCULL, 0x474B6C6CF1998C5AULL, 0x033CA4EA1BD34609ULL, 0x3822FB58937EF5B8ULL, 
            0x52897E5227E838F9ULL, 0xF89FDC60C0976EA3ULL, 0x555E22AB85328D3FULL, 0x7594C518944A98CCULL, 
            0xF89C306F52DAD2DDULL, 0x85453CEFCC015FB6ULL, 0xEBF062E437A8DABDULL, 0xFFA133081D662C35ULL, 
            0x991024F740601BF9ULL, 0x5BD1814641C5BE39ULL, 0x0FDD7C40C1A0F7DDULL, 0xD08885C929DA6985ULL, 
            0xCC6AFDE5B141EC28ULL, 0x6AF1A5275FDDAFC1ULL, 0x638CFFEFB508120FULL, 0x8ABE0CA4D5606CF2ULL
        },
        {
            0x949CD6CEF6D6578BULL, 0x91F3774F0D554B0CULL, 0x6A029CEEB61D3B8AULL, 0x012DB70B7B9A2552ULL, 
            0x75A7ACD11C0125D4ULL, 0x167FA2AE049FC473ULL, 0xD4FFB5C508B1CF51ULL, 0xB0952742870FA03EULL, 
            0x48FAC9D008C4203CULL, 0xDAAFC2A3471CD659ULL, 0x1BB010F129CC6E09ULL, 0x5D5B92DD52E9BC98ULL, 
            0x1A22627C14AC6DA2ULL, 0x0768DA34E7DBF4AEULL, 0x8CB39E24E6152D29ULL, 0xAD7EEB423B1A6776ULL, 
            0x5A5EE2C320184B27ULL, 0xF781797322FF24BDULL, 0x0834331E8F486C77ULL, 0x5F174F031E0C6268ULL, 
            0x2E7A750C8EFE1116ULL, 0x4EE183FF069316DCULL, 0x7D53ABAE1546CD45ULL, 0xFE4BF9420FA86693ULL, 
            0xE726742881E9E8B4ULL, 0x92F1F4E1FD62988BULL, 0x0899E279AA4681ADULL, 0x0F613E51A5A7818DULL, 
            0x202A9E7DFA30DD97ULL, 0xC3FD944F7A674D2DULL, 0x1B56E280B2A1BAE3ULL, 0x527E2C1BF1CBEB3EULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseAConstants = {
    0x937CAEC63BF1A95EULL,
    0xFBE9D885D03801E5ULL,
    0x0248C811F5D94F70ULL,
    0x937CAEC63BF1A95EULL,
    0xFBE9D885D03801E5ULL,
    0x0248C811F5D94F70ULL,
    0xA4F2ACDBC9C823A3ULL,
    0xBD76F4BBC3AD3017ULL,
    0xD1,
    0x23,
    0x64,
    0xDC,
    0x7C,
    0x1A,
    0xF3,
    0x57
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseBSalts = {
    {
        {
            0x5E016F872170A78AULL, 0x3B8180D0CC908ABEULL, 0x97DD2EC5EFF059CCULL, 0xD8E1565D7997A609ULL, 
            0xEF139DF1900BEFF8ULL, 0xB4B6607EFECE1AA0ULL, 0xD572632A85AA8CF7ULL, 0xF0D0C54683F73443ULL, 
            0xDAB71B2E132A6C0EULL, 0xAC4683F409ACE12EULL, 0x922D2421B15F8326ULL, 0x5DC02F31A50E111DULL, 
            0xCBACEC8830FA98F9ULL, 0xC229929EACAA4EBBULL, 0xA4CDBADD8F711A6EULL, 0xEEEA33787AC9359BULL, 
            0x1B5A31A908A7A5FEULL, 0x1D154AD3019ED727ULL, 0xF72F8B471E297D2AULL, 0xF672A55FBB473793ULL, 
            0x3DADCA2D7C38C447ULL, 0x7FC6B4118F60D0AAULL, 0x6DC2304300D3480BULL, 0x06558A0F9FCAC4BAULL, 
            0x15F398826B63859DULL, 0x9154C9B29492FA11ULL, 0x909CB2BEE6061899ULL, 0x8AF186D5E9AEE734ULL, 
            0xE3FA5F13834A837AULL, 0x0B0F33EADD531D4CULL, 0x7F090B4EE335F554ULL, 0x9E99CCBFB707194AULL
        },
        {
            0xF2E411ACF6332064ULL, 0x5CE4CA73FE589323ULL, 0x982F66E67A761D53ULL, 0x376C588C111C0FA4ULL, 
            0x9A4B7A651FB21069ULL, 0x5BC01349593AAE7BULL, 0xDE7AE80D848C440AULL, 0x0F03253536DE0916ULL, 
            0x55B96D8A2FCA01E9ULL, 0x3FEE2EACFCE51DA6ULL, 0x72EA2985A81D0C98ULL, 0x248E9EA05CC74BF4ULL, 
            0xF846BF06F0545C5DULL, 0xE081403BEE112DBBULL, 0xCE778DFB45D0E76FULL, 0x0E59CFDF92610288ULL, 
            0xBF63872A2CFEAB13ULL, 0xAFA750190FD70238ULL, 0x58044077EE8B5C6FULL, 0xB3C2E75919B5CBCEULL, 
            0xA7BC192633F1271FULL, 0x929F105585AF86F4ULL, 0x98ED3B7E590A5CCEULL, 0x0D011FFFD58EC9ABULL, 
            0x38DFA764BE607F14ULL, 0x7D7072A525DDBFE0ULL, 0x0A8E62B4CE0A27DBULL, 0x5479E6B9C1C72724ULL, 
            0xB67840889242009DULL, 0xED0C95DF1FE5DC78ULL, 0xFB1DD9F4B98E0B27ULL, 0x0B69BC8A4341BA0AULL
        },
        {
            0xB269B6C57FDA3BC9ULL, 0x389408C484D0E10EULL, 0x394CAF77B6216ABDULL, 0x7C1815512412BBBBULL, 
            0xA258046F9834976CULL, 0x2A750F6F7DF113A1ULL, 0x228B9D5FA37E3A65ULL, 0x5A7E28D61886D468ULL, 
            0xB8B7FE0461AD08D5ULL, 0x40D9EC0EC5B47E64ULL, 0x313F693E6A42222CULL, 0x89CA6DBE1F9EFA2FULL, 
            0x1E829A25221F5D9FULL, 0x465C6EBAFD82C278ULL, 0xAC2A9A28C4725DEDULL, 0x54AE03D25B3F65AEULL, 
            0x34FEE522D51381E8ULL, 0x764C15D05B25E859ULL, 0xF727EA093D6EF812ULL, 0x8F8C6B65B9AE51D0ULL, 
            0xADAE192439A99683ULL, 0x357D4ED37B92E5E1ULL, 0x0D793566450974B3ULL, 0x6EE0FEE1FF919EDEULL, 
            0xBA5363F46C6DEE39ULL, 0x17F0C7990DE2FEA8ULL, 0xFE74763FC6AFF4FEULL, 0xF360AAF4FF1BEB09ULL, 
            0x3DA3363102FB86BAULL, 0xBE15AA96FB6FECC1ULL, 0x96654DCA4CE147AEULL, 0x12F68D08142808B3ULL
        },
        {
            0x25D5E1E2249F5B48ULL, 0x9D027302103837D9ULL, 0xCD3696CCD2BDF2DBULL, 0xCBFFB0E12AADFA9AULL, 
            0x9E76DA7E2A623A60ULL, 0x13F56296E177B018ULL, 0x3070E26A128492DBULL, 0x35059F8BFE53E033ULL, 
            0xD7CB7FB6B91F2404ULL, 0xF7703EA906CDBEB5ULL, 0xB5A1E0BF3789C4EFULL, 0xE7727257E1171598ULL, 
            0xAF92457721C50C6EULL, 0x04CBC86FB7A8920DULL, 0xFD97A48F67047AC0ULL, 0x75F27F498795493FULL, 
            0x54875F08453A4FC1ULL, 0xB6F0AFEB6298DBB3ULL, 0x7D63322DAE5614C8ULL, 0xCACA40F33F09ADB7ULL, 
            0xF5C9813BCB7EC3C7ULL, 0x1C8885EE18658AF8ULL, 0x24A2B2390D43C1DCULL, 0x2158E7DB7E2C2552ULL, 
            0xF18FB7D9192805FCULL, 0xD92CF181CD5B832EULL, 0x25336C89E8097132ULL, 0xBB360D01B17762FFULL, 
            0x8B0573E9291AAE32ULL, 0xE0ADAE781055582DULL, 0xAEE04997999290A5ULL, 0x963BA6462F730F6BULL
        },
        {
            0x69DFB9AE960BE8FAULL, 0x5D5C210C96662591ULL, 0x1FDBC95C63F58E4FULL, 0x4494AD2373D9361AULL, 
            0x5ABCF742C733C112ULL, 0xFF1145C3119F52B4ULL, 0x292CC6176E0C3644ULL, 0x2AAD3E5A6C56206FULL, 
            0x3ECAC0665EE6FE73ULL, 0x9BBBBC763C3B58A8ULL, 0xFD883384964B80F3ULL, 0xA54CA6BB080FDB39ULL, 
            0xEA9759CF2E49CA7BULL, 0x4A61FA72F63B9A73ULL, 0xD758B5DC9D491333ULL, 0xC5453F1FB6703E05ULL, 
            0xD24B451E7A13598FULL, 0x0115344253170605ULL, 0xA7F7699B686F06ACULL, 0x32CF01FBBB1047D6ULL, 
            0xF62540F547C22306ULL, 0x6A8F87CF3F4F9B7AULL, 0xE7C2116566F57AA8ULL, 0x39C9D0E9ACA79024ULL, 
            0x9162370178477A42ULL, 0x164C24B9DB25D496ULL, 0xFFD4231A46998F33ULL, 0xD078814505E19A48ULL, 
            0xC0A3961AF5D48267ULL, 0xAA46801B4DF0E2BBULL, 0x9D58C477708E23F0ULL, 0xF095678ED6761AADULL
        },
        {
            0x1D574682620F2C1BULL, 0xB53F894C96977AB0ULL, 0x9F20759F7DA865E5ULL, 0x95588E21C639FC02ULL, 
            0x2091DD6E145B47D5ULL, 0xF6BFC81DF232BB26ULL, 0x3CF7AB29F1277EDDULL, 0xB5252EDFB1BFDA78ULL, 
            0xB86B588286E1C19BULL, 0x78BF401BE46ABEE6ULL, 0xD73C659B04581A75ULL, 0x6451D037867979A1ULL, 
            0x74D139B096B18259ULL, 0x524B590CCC0FF34CULL, 0x6607C7E0FC5438CFULL, 0x0B4DD807B8C0CE8CULL, 
            0xD87B7DD5255B3A51ULL, 0xBE3DAA2399158AA1ULL, 0x7C8796B6BDC5DC47ULL, 0x732CC103B40E0735ULL, 
            0x4F8F8F96AB15BA27ULL, 0x05EAB61364517E02ULL, 0x377B72DBA46482F2ULL, 0x8CEE52EC7E139252ULL, 
            0xC92EF5688C7B0991ULL, 0x709D767922F7536CULL, 0xBCD5542F573B766BULL, 0xD1AD3CF173267E53ULL, 
            0x4B8751757CACE4F4ULL, 0xBF85835C974EB7EFULL, 0x6B81B97339411779ULL, 0x3DCBD1F747C15061ULL
        }
    },
    {
        {
            0xE7BF362689D7B243ULL, 0x0E61A0BCF432B025ULL, 0x92FF7E26C71BCAAFULL, 0x2FD93F34CCAA058DULL, 
            0xFFF9EF8005A21555ULL, 0x336237E5109EFD82ULL, 0x2A3C3EF4B1643079ULL, 0x5F6ECB2504A54B25ULL, 
            0x0392289BA12911A1ULL, 0x092554D95CEE365FULL, 0x9232453D958A70F9ULL, 0x351B9330DFEFA24EULL, 
            0x961477C732927F27ULL, 0xAEFB00D7BDD94E10ULL, 0x2F8F68EDE6B7F851ULL, 0x1061B51BFB0CB29AULL, 
            0x7B6D710FA2FDAF71ULL, 0xE975945900872046ULL, 0x2B145BBAA392ACA0ULL, 0xE9ACF310CCCCDC05ULL, 
            0x4922C262F1C3D4D8ULL, 0x45D75CBA6D60D649ULL, 0x6B7C295C7B5A083CULL, 0x8A5FD7915CCEE723ULL, 
            0x6DDAC9B537A9912CULL, 0x5B9C1C2B32F75C36ULL, 0x422D6D30D7C13F88ULL, 0xF7C683241A3C6E15ULL, 
            0xDA5BB9E989F0567CULL, 0xA2CBF2E2D162838DULL, 0x0E0A3DBC243ACA6EULL, 0x42C97DC5C1FE206AULL
        },
        {
            0xDC2A416500D44C4CULL, 0x75AD4220D641A90BULL, 0x9EE0C7F49D727082ULL, 0xB33A974A5F2357AEULL, 
            0x02A7ED6C21199A6FULL, 0x2B26D047FA3F558CULL, 0x92AE961FCF0D47B3ULL, 0x56D405BF25D27149ULL, 
            0xF104936B43036A3AULL, 0xF8EA583F9A03F546ULL, 0xCCEB199D58838DBBULL, 0x2811AB61387ED7FAULL, 
            0xE5AC95BAACF6084CULL, 0x5596BC2C4EF60611ULL, 0x4AB674B5AFB7435CULL, 0x5EE16EED0901F155ULL, 
            0x9BC917EA193BBBECULL, 0xA9FE56C7D683AACFULL, 0x56A6ABDF0279E6ABULL, 0x63A2223581479E15ULL, 
            0x89E72119D9D6C7B1ULL, 0xF87E5015CBD95CD0ULL, 0xB05A81328E31D5CDULL, 0x6470D1269A77C1C7ULL, 
            0x1FAD03E92C1408F0ULL, 0x875C32B30F3EBB4AULL, 0xE4176166536029B5ULL, 0xD5E9108B67FD7E5BULL, 
            0x962CCBB861307C3BULL, 0xCDEA55B9070F25FDULL, 0x75C533A76AEA399DULL, 0x5948143417311850ULL
        },
        {
            0xBBF18C7A87F60E28ULL, 0xB17331D7E647A70AULL, 0x676ECFEA3404E1A8ULL, 0x5F3A834E621D5B24ULL, 
            0x21D26FD263AB04E1ULL, 0x2DEDF7280829D948ULL, 0x0EB1336183849B29ULL, 0xD3E8B16CEE9DF6BAULL, 
            0x1E62F51F9D5F25AFULL, 0x3C9B35B07843BAD9ULL, 0xD93A9B2C80F5C72DULL, 0x00CE2885C44CF063ULL, 
            0x87567719726D8ECFULL, 0xF310DC78172144BDULL, 0x11FA1E28AC56B33FULL, 0x00688B9904AB3F45ULL, 
            0x7C9EC6FF95F1F46BULL, 0xF6ADDF6CED829D68ULL, 0x08F6D7EC349D2536ULL, 0xFFED2F14E2289374ULL, 
            0xAD31485CDD66E13FULL, 0x5C7B066B704068CFULL, 0xEB1DCEDCE53D0369ULL, 0x61919F534157699DULL, 
            0x9E3CE1B0B38D8FC8ULL, 0x184E3F3DD7C9312AULL, 0x19B5750631AF9712ULL, 0xA5DD8A2E2885E034ULL, 
            0xD2FC8FFADB903704ULL, 0xAF02E5CD08E1B802ULL, 0x9C484CF05E3EF0B8ULL, 0xAEE2E88FCB208589ULL
        },
        {
            0x5A4A0127D31368F5ULL, 0x91A24F2D5BFF9A60ULL, 0xCD6240143CE1B0DDULL, 0x6FD3CDBD3AF80A8AULL, 
            0xDEA4E63D4544E325ULL, 0xF816318C204804D8ULL, 0xAB5B2A569F26CC21ULL, 0xBA07914C3475D858ULL, 
            0x34CFB75361A808EAULL, 0x83827E4717D66A8DULL, 0xCDF35B1C16B21D99ULL, 0x426BA359450E47FAULL, 
            0x26F860F5DEA358E1ULL, 0xB04D8D3D46F9F4BBULL, 0x4DE14576DCBD6236ULL, 0x39446511444F178BULL, 
            0x9F4BF98F8AC54B1EULL, 0x6FE0F1EF1A9B4ECEULL, 0xC8C1FA02DEB89391ULL, 0x62A4A01DEA2331E8ULL, 
            0x86096B5AA7CF2C94ULL, 0xD8F46A6F37D2ED10ULL, 0x0D6C04670CBE6A60ULL, 0x32C9C060C37FA4F0ULL, 
            0x4A0C0A9262AE07E0ULL, 0x869F8BB7844BC76EULL, 0x2A332E6800A0CC6CULL, 0xF140E7168F19BED1ULL, 
            0xC23AFD71809290E4ULL, 0xF9A8CFB8509EA820ULL, 0xC865ECD33BAF810DULL, 0x960345C7157E98CBULL
        },
        {
            0x2503E75D910DDE2FULL, 0x56660898047569BEULL, 0xF3AB06006DC17B91ULL, 0x65AFC2AD7DF56AE3ULL, 
            0xB41D15C840F1BC27ULL, 0x62DF36DC0E6AF27AULL, 0x500647894F7F30A0ULL, 0xC62C4EF8629E322BULL, 
            0x202BD0130F3AB0D1ULL, 0x927E52AA8CBF23B5ULL, 0x2882434B52255A31ULL, 0x0130C261B74EB867ULL, 
            0xE05BE66102064E78ULL, 0x7D4F62BD168A0F61ULL, 0xBA4056C8EC4A81B1ULL, 0x1613BCD4690F67E5ULL, 
            0x9614DC3DC18DF2BBULL, 0x879FF80D88E17888ULL, 0xFB5B972C09C714C6ULL, 0xB97504AEC894A417ULL, 
            0xAA76B0D4ABFAB4B5ULL, 0x4F719F1639630FC1ULL, 0xADF589FF07C430F4ULL, 0x88C8C9255AC56F7BULL, 
            0xF49398492B4EAE2CULL, 0x6A84BD867DBFEA20ULL, 0x93829CBFC2CC907EULL, 0xE4D6DF5778C18EC5ULL, 
            0x96DF2532ED852D29ULL, 0xB5B6519B0CC39403ULL, 0xA2A4D65568D75E56ULL, 0xFB1F6246BA601341ULL
        },
        {
            0x5A41F4B1B4332049ULL, 0xE1208BC2B4A9EC58ULL, 0x7D397BFA01250666ULL, 0x2D09DFA6F2566A44ULL, 
            0x3E933E501A59CFC0ULL, 0x55FAD13101799359ULL, 0xF38107014C640567ULL, 0xD02D32FFEA307E1CULL, 
            0x2D8DBB69081BCE85ULL, 0x053AEB0EF9757DA6ULL, 0xA0A4630A0D91C2BEULL, 0xB3A23DC3C09264C3ULL, 
            0xAF5D87E17295294AULL, 0x63974D8DA9BE7AC0ULL, 0x16C361880F2A1B30ULL, 0xDB4FD62CBD93A506ULL, 
            0x38AA5B089D4243FDULL, 0xC29912E1D89AD00AULL, 0xF355C8AE41A511DEULL, 0x20E96408404466A1ULL, 
            0x93ACDF1C7A970A4EULL, 0xDDD8E4D1E7C55E35ULL, 0x11ED82ED8E6C921DULL, 0x49D32AE5C718AF9DULL, 
            0x4A91A4D441EA2A0FULL, 0x8156B8D54F07CEF7ULL, 0x13C45F87322A42A2ULL, 0x4EA55FBEA14FEE4DULL, 
            0x590AFCF6E61CDC74ULL, 0xADD09AA936A1B265ULL, 0x3BE9D3900161193BULL, 0xE182270A21E7335CULL
        }
    },
    {
        {
            0x175CCE804416BB20ULL, 0xF83270909AADC352ULL, 0xD3946C78B2689D80ULL, 0x11AFA10B308326B2ULL, 
            0x87BE4D9DA48543F1ULL, 0xA5AE4DE5EA0B290FULL, 0x6E3D37EC819567C8ULL, 0xB89F446111B33258ULL, 
            0x54793F40E2212461ULL, 0x37A73FF71724EB2EULL, 0xE6B2F78DD6761218ULL, 0xD4543E21DAA06F46ULL, 
            0x69E914EF0244EAB5ULL, 0xCFDCC0E8C3174735ULL, 0xC5EF02664BA15E35ULL, 0x42D4186F015EBD45ULL, 
            0x55A930BE546C1334ULL, 0x2CF9909FA00F9FCDULL, 0xAAB142EE564BDD61ULL, 0x12CC86D12756148AULL, 
            0x36200493B8FF2699ULL, 0x7D5448FA7E3362DDULL, 0xD524678DA38A89FCULL, 0x3F5FE926336E7B3BULL, 
            0x553D7D009FD99786ULL, 0x8FFA8DBD44F2673CULL, 0x4D76C56CA3C02A0AULL, 0xCDCEDADDC0BC17C9ULL, 
            0xE189BCA198E15D19ULL, 0x15D57F926AB8D2FCULL, 0x00059DFE170C2300ULL, 0x7DEFDFB6BB5E58A7ULL
        },
        {
            0xA4A588FB84577F47ULL, 0x52C22D4DEDC3294BULL, 0xE1D23E5EE822F7E3ULL, 0x6DFC0B912B554E7DULL, 
            0x2A09E0D4E09ACB10ULL, 0x50E6F3D0AB80CC62ULL, 0xF7485186E522F534ULL, 0xF711CEAE529E233BULL, 
            0xD0954553E8D3836EULL, 0x07D688D95BF2D38CULL, 0x7937DF483943F10CULL, 0xCA1C3DE7C8619F17ULL, 
            0x667B37D609CBD74BULL, 0xC8C371512B659D12ULL, 0xEB0B0D070770C1F1ULL, 0xCE955175D9D83796ULL, 
            0xC6F25734DE3BDFB8ULL, 0xD36BFE329BF6907AULL, 0xF4254A2D55501550ULL, 0x87176AA215960902ULL, 
            0x6F2CCD26A1C9E66CULL, 0xC8EB0F999FAD3FABULL, 0x0918249A9EF393B5ULL, 0x302846EF63BCE57BULL, 
            0x950C6D4C0FB52E77ULL, 0x6E49445150282D77ULL, 0x61699E43B81DB939ULL, 0xDE3C7C6DA8C9B77CULL, 
            0xF7FF74B8C1E74C10ULL, 0xD1C29D7A7E9FC00EULL, 0x42E03CEC43558F27ULL, 0x6F5B3C76BAF8D09FULL
        },
        {
            0xD4285FA7E4127248ULL, 0x19396DF0F38083DBULL, 0x8C40F410DA08C24AULL, 0xDE208D043E7A163BULL, 
            0x679692B5FB6FA6A4ULL, 0x9B8D3834FCFCAEDEULL, 0x5696F3F8A6869BAAULL, 0x29F5D518DEC6B567ULL, 
            0xCE042E2B25F41377ULL, 0x14B7B80943FB04CFULL, 0xB1DBEAFBDDBB0069ULL, 0x9E27EB4683C07565ULL, 
            0xC156535B5293CC89ULL, 0x13B8B15FAFBA95DBULL, 0x1F659A4E01A3965FULL, 0x4A8ABD4433B20B11ULL, 
            0x280B95C5DF135293ULL, 0x6F938ECDE5BE99B0ULL, 0x4A53171E4B611FB6ULL, 0x8569DEE71F97DF44ULL, 
            0xC516BB751EE695B7ULL, 0x7A571B87BF4A4378ULL, 0x0E4CC1CC6972BB1BULL, 0x60D713063549A401ULL, 
            0x2C50275B8FB6ACF0ULL, 0x5F4FE96B742A3664ULL, 0x0C1976F906B02C4EULL, 0xB3A9E3546A8AFB8DULL, 
            0x341385D99A2077FFULL, 0x383B2EC0E5D97DBFULL, 0x6951FBF07B41972EULL, 0xCF1AE69F0D71BB43ULL
        },
        {
            0xBBECB8D58CBE7657ULL, 0xDAA527D629BB0FF8ULL, 0x7EB3C44EF65DFA14ULL, 0xBA949D8EEDBD8821ULL, 
            0xA8BE6A69779CB724ULL, 0x0E871A2D3EFE9303ULL, 0xF0D6BBD44D88566FULL, 0x6DA274ACFCF8EE87ULL, 
            0xD4B2E15623CD11F5ULL, 0xA78EB9FDC03F70CBULL, 0x755A5204B2A7AEB9ULL, 0x3208EC3B39CF1888ULL, 
            0x060E588C9EA614C5ULL, 0xB3CBBA145F4F4608ULL, 0x4E353E128DAF246CULL, 0x73ECA4533AB35804ULL, 
            0x4243F7A0A7BB68A6ULL, 0xDF1F719F8298A95BULL, 0x1F122FCAADACE8ECULL, 0xE7328280D97B2DC8ULL, 
            0xCEA5331EEF7CEAB0ULL, 0x04290E5DBEAE6D5CULL, 0x58FEDB5DCC3113E0ULL, 0x09BA9219F50215F0ULL, 
            0xBDE1350DF92040ACULL, 0x7D987AD95D753276ULL, 0x487AAA465269289EULL, 0x1BDDEF22D0E95FB7ULL, 
            0xFAD8E85A97D7EB25ULL, 0x8C3246A3FFCE3E9DULL, 0x5D6DD45BBF647129ULL, 0x7A354E1CF1AD2765ULL
        },
        {
            0x28A1D05B045295A9ULL, 0xA27418DD143C6539ULL, 0xD50ED1AC7959E396ULL, 0x0A958D700D28A4E5ULL, 
            0x7CE8C80CA1A7DF03ULL, 0xF2301AF9EF0332E8ULL, 0x2032359E34622D1EULL, 0x6F8FE62C27BC23F0ULL, 
            0x9A0E84D8B4F4D38CULL, 0xE8F99B81F6E4C397ULL, 0x0A154BD998B39624ULL, 0x7410503AABED0A7BULL, 
            0xFEF4BD365F4C0152ULL, 0x4A1F66FEF7D8D131ULL, 0xBFD63F6742DC7DA9ULL, 0x1A6D58CBFAB2F59AULL, 
            0x4D7297E1C6AA5D23ULL, 0x6315F5D819C51601ULL, 0x253F5576F281559EULL, 0x61BFF1D31AA58EDFULL, 
            0xD58D2AD050549F41ULL, 0x4A8DD631776C2FEDULL, 0x7C1AB85F3439BE5AULL, 0x7744048816EB6930ULL, 
            0xDA2F90CA1D0FA37EULL, 0x7F7B5D17464985D8ULL, 0x2E5A490A6CB2DB86ULL, 0x0972456F2857A624ULL, 
            0x5C90F83F6D0439FAULL, 0xB07645488FE00BA4ULL, 0xEB41CC0FC90A2561ULL, 0x69A75B4F8E177D11ULL
        },
        {
            0xAC0DE7A803BB291AULL, 0x4873E3C0B21072C2ULL, 0xC8A4F1CFE0B6CE75ULL, 0xBACD4FDE24A08DFFULL, 
            0xFE5029A43B35C7E2ULL, 0x432D0780C17592D1ULL, 0xE07EF62A311B2CADULL, 0xB37505ADF9428A40ULL, 
            0x5B4784E1A8FD78EEULL, 0x0C4EC71AC5E675A6ULL, 0x7D174027F42F92E3ULL, 0xB5FC459B26845F1DULL, 
            0xFF513F1A37EC6BB6ULL, 0x3C7C1B6CE2E0BF2EULL, 0x286402FB8852E751ULL, 0x5AB3907C9579FDA1ULL, 
            0xD11BD30AD3D58A41ULL, 0x9394B61B02D382F7ULL, 0x9A751684B42BE2E1ULL, 0xCA79E0C2A59E3E08ULL, 
            0xCCFB69D7EDEFF4D1ULL, 0xD27AEDFE688C0394ULL, 0xE876A7635B3D10A6ULL, 0x8EF8EE21139A976DULL, 
            0x5085AD0F68929C1DULL, 0xAAF599C2C402C0CEULL, 0x91D2B86FBBD218A8ULL, 0x8770C9B8DCFEF3F9ULL, 
            0x54C352A4F299A593ULL, 0x5746B63D68D5AA93ULL, 0x64269FBAFB68785AULL, 0x27652645B61A8679ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseBConstants = {
    0x353A1F8A7BBABE4DULL,
    0xA8911D6958E14CD3ULL,
    0xF6C846B95FEFDEECULL,
    0x353A1F8A7BBABE4DULL,
    0xA8911D6958E14CD3ULL,
    0xF6C846B95FEFDEECULL,
    0x9EF38AC59809C49CULL,
    0x9ECA509A1A6B3664ULL,
    0x65,
    0xF3,
    0xD8,
    0xDC,
    0xE2,
    0x6E,
    0xBA,
    0x93
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseCSalts = {
    {
        {
            0x050BE6B37D93CCE4ULL, 0xE1F210ADEBB337CAULL, 0x90F6831D7931A800ULL, 0xBB0A7F6494411084ULL, 
            0x83D84EAD0360D662ULL, 0x44A52D6768C8BED9ULL, 0x74E14633CB42CC7FULL, 0x3B91C517301DCBA6ULL, 
            0x785AE4D8DB22DE13ULL, 0xDFC5423CF421FC1BULL, 0x7BF4684A3BC5315BULL, 0xFE1662FACB6E60D8ULL, 
            0x0D164F6418F9888DULL, 0xF510985A9E838A40ULL, 0x1937979030C2D57CULL, 0x2D66E53DB498D649ULL, 
            0x5F3ACC9AACAAFEDBULL, 0x373CCA4567B8F930ULL, 0xF06DB3689FE12159ULL, 0x7AFCB8EFAAD221CFULL, 
            0x57D7CFED7784B4FFULL, 0xBDC27386FEECA633ULL, 0xBB5534413CDEC775ULL, 0xD3760AA19A82B9BCULL, 
            0x017FDC1157AD711DULL, 0xCEC5F4820E7394F0ULL, 0x6AEC56A73A9EE1B6ULL, 0xB07E189664BCAFA9ULL, 
            0x6E19CCC087D47B0AULL, 0xDE709F53D9A440C8ULL, 0x0845CD44B1106A67ULL, 0x3C7FE99FB2E69E36ULL
        },
        {
            0x95CE2247C249313FULL, 0xDF16F20F883A3A06ULL, 0xB9E449594FE0061FULL, 0x53F37E2F7085281DULL, 
            0x44ECCE3586A9FBB2ULL, 0x89F99800872332C0ULL, 0xF6E44F6FD39F1B42ULL, 0x135FAD1EA8329B61ULL, 
            0xE40239CA06B53DE1ULL, 0x75EFEA22DE639B20ULL, 0x1A7584DC86A1F5A7ULL, 0xBB9C9314A49A1745ULL, 
            0xDD100685A565B85DULL, 0xDAAE022054D1B755ULL, 0x2F5EA668DC201C48ULL, 0x8A10A1061152A59DULL, 
            0x6A1958107D56718CULL, 0xDEE1AB186F82CD92ULL, 0x93B8C4AF0D585EDEULL, 0x07C357D8A2A1EE59ULL, 
            0x2881BCC381736155ULL, 0xA29484D922CC9FC5ULL, 0x92EF56ACF97B811DULL, 0xC78DEB373045D5C6ULL, 
            0x2FAEF7F53A16EDBBULL, 0x9F4573BC6A662BCAULL, 0x93C20FC4B032EF4DULL, 0x6E16A152AA35DD4FULL, 
            0x7DB60B457E3508B6ULL, 0xD859B569221C29C1ULL, 0xB6056DA77B6987C5ULL, 0xA1AD2AD0F79D1EDCULL
        },
        {
            0x8446237D9B332404ULL, 0x6235253B3E093745ULL, 0x39DA47FDD3088597ULL, 0xD709A752715F9C0AULL, 
            0x3408B8D347F69C09ULL, 0xBD86A9ADAC0D9A1CULL, 0xC8072285168B78ACULL, 0xB8B07306FDC3D735ULL, 
            0x844790205C149899ULL, 0xD7736A6B914A74D5ULL, 0x04765660E5A45BEFULL, 0x8EC130987A5D8BBFULL, 
            0xE5EF9BCD629E1BF7ULL, 0x30F72514E20B524AULL, 0xD5C1952E7C6923D7ULL, 0x72BD3B983E75841FULL, 
            0x86D6965A0FD4F1C3ULL, 0xE2C6B6A020102076ULL, 0xCB1C551AA7F1F5B7ULL, 0x742AA0BB298544CCULL, 
            0xCB0C457021301648ULL, 0xF334B3D9F0C710A2ULL, 0xFACABDE93B99ED47ULL, 0xD775E061D393BC44ULL, 
            0x4AF0884FB4748569ULL, 0x7F3CFD0E9E67D623ULL, 0xF6C9EA0AA2B77BC5ULL, 0x655568A1D867AECCULL, 
            0x88AB31D0A7E1A1B5ULL, 0xC430449BD66CF91DULL, 0xC9C74C5489BE9C4BULL, 0x1CCC2E7599FD82F7ULL
        },
        {
            0x93652F6BC4D8EEC4ULL, 0xEB565FD464D1E8EAULL, 0xE62B5170FDD11EF3ULL, 0xE29475E17C2B1402ULL, 
            0xA15FFE784DBEA2E1ULL, 0x5AD66273EE1C10CEULL, 0xB0518167485406FDULL, 0x325FF2A9E791DBEFULL, 
            0x989E6B60181CCFB5ULL, 0x68051FF301E4A5C1ULL, 0xF15238483B28C6CFULL, 0xDE9D58351C76A0EAULL, 
            0xBD0D1738F85EDF6FULL, 0xAFB7BEF97093C7AFULL, 0xE9E26B8348C31C38ULL, 0x5D5920895E922D67ULL, 
            0xF92EE0E10AC65FA0ULL, 0xF75FE8811160706DULL, 0xEA027FBD45D7920DULL, 0xDFE4C298F71B6B95ULL, 
            0x4DCDD448E53FA1CFULL, 0x0358741DCA95AB8BULL, 0x133364E2E91E9281ULL, 0xA1FC0C79EF528B13ULL, 
            0x4238DE1B781BA0E5ULL, 0x3EB780925A92A607ULL, 0xC67090AF3997E0DEULL, 0xBB1CC9EC3A4375F6ULL, 
            0x4A69461B7349D2E3ULL, 0x93739ECAD8178724ULL, 0x03FC02FD146973E8ULL, 0xEB40B592EC0E800EULL
        },
        {
            0x91C75CD9E4FC3CFDULL, 0xED35F4220568B798ULL, 0xCFB55ED29550B887ULL, 0x1A3EF5B7D8BBE13EULL, 
            0x8398C6724E6C1A17ULL, 0x8E108EF9D66680DEULL, 0xB41AAE50D3AEA714ULL, 0xD3900EEC1869C17CULL, 
            0x818F964D16DC3CC9ULL, 0xDB5F6853B4473114ULL, 0x303D0FAF0FDF7928ULL, 0x381D14A1B936294DULL, 
            0xA8E097D7533D93CBULL, 0x20E73E64CDBD3342ULL, 0xDE3FB7E739EE6300ULL, 0xB400C759EB00467FULL, 
            0x1C333726FAF82FFAULL, 0x040C1A26AF3CF1B4ULL, 0x37599D29613163F2ULL, 0x9569C8F27E416D65ULL, 
            0x64B976C690AEB922ULL, 0xB129854A0DEB3175ULL, 0x1AAF5FD8FF777888ULL, 0x46F5034D6242E73EULL, 
            0x3E466078BF437721ULL, 0xDCA339629FDD959AULL, 0x897597778CB615D5ULL, 0x73929536906311B5ULL, 
            0x033792CAA1B0E1A1ULL, 0x80C1A251B8967064ULL, 0x7EC0DF433B4C98CFULL, 0x69D1A71E2D698A45ULL
        },
        {
            0xC27BE86066CB307FULL, 0xA4799EA958EEEE83ULL, 0xCF2DC16A54706ED4ULL, 0xE00F5543C2838C4DULL, 
            0x428E4417048B703AULL, 0xCFD789AEE4B84B86ULL, 0x922FC07D0DC38F5EULL, 0x52A0312544F4E464ULL, 
            0xEDE726AB612CC200ULL, 0xDEEB7201307F2671ULL, 0x9DD1DCEF4FBBD697ULL, 0xCE7489B8C0417A92ULL, 
            0xB1786A0760972F92ULL, 0xF283E2AB9657042DULL, 0x7A854379F897D971ULL, 0x6F76877394E009C0ULL, 
            0xE5FA421E88950B91ULL, 0x87400ED4B327502BULL, 0x545D31C5233909A3ULL, 0x6B1B04CFC4807E0DULL, 
            0x66CEEA8C917DF8EDULL, 0xEEB8B35F83AAFB78ULL, 0xC69CA555B8D4FBBEULL, 0xE502551E6DD2B857ULL, 
            0xBE3E8097AE2C4392ULL, 0xE3129B818D44111DULL, 0x5B8E39A3F1878CA1ULL, 0x46030E1DB81B3671ULL, 
            0x0A23AE077585B5E3ULL, 0x064E285AC08606D4ULL, 0x28779E8B1E849BBBULL, 0x80CB0C38462C00AAULL
        }
    },
    {
        {
            0xCD5EF13FA4DFB551ULL, 0x628AD7463AEB792BULL, 0x09CB5E2436D1D567ULL, 0xA5D2B4DC41556A0BULL, 
            0x3BE07FC721672802ULL, 0x17965AFCCD22DC3BULL, 0xC9CAFAF874EA7FBBULL, 0x5E2478CE90428628ULL, 
            0x81BBFCDDA5CADB21ULL, 0x2763D81B3CDE5E57ULL, 0x50ABD758167FF36BULL, 0xBB66CE917A9AA02BULL, 
            0xC6EE84DF13631B13ULL, 0x4218AC9759A0FB68ULL, 0xD9A9B917C7EF1BD5ULL, 0xFF302A89638956FDULL, 
            0x9CB4F896D47B1896ULL, 0xC881AFF841C5240EULL, 0xF79C11CDD11FD219ULL, 0x3F2F39DC9DE62594ULL, 
            0x7F325AEE4BC3CE97ULL, 0x5598399EDF3B2207ULL, 0x660D1E4E43B1D17EULL, 0xC01BFFCF6F54A1BBULL, 
            0x503A8761F64114ABULL, 0x84D68A72720A534CULL, 0x5DDDDD5D3C6B70D7ULL, 0xD06E7C1179CC0FADULL, 
            0xD09F10EDEE37FF67ULL, 0xF9A81461A5F2F3A5ULL, 0x1D10F891D2BC9FE6ULL, 0x7544613249112CBFULL
        },
        {
            0xEE88EE8D93DF589AULL, 0xAFA8C1D64E3AC4C6ULL, 0xD57802D53893D4FAULL, 0x53F4DF63DE4D6D62ULL, 
            0xAD69C33B76CF8505ULL, 0x4C03DA1034FB5C11ULL, 0x33B45BEBF1A0ED6AULL, 0x6ABD31F6C1F809FCULL, 
            0x77DCDF8036E8820AULL, 0x49EFFBC0F6BB9181ULL, 0x0A241D2FFF70A0CEULL, 0x8818A7DA05191458ULL, 
            0x8F717539A7308672ULL, 0x45F142C1173E4200ULL, 0x063FC9A74EE1F51AULL, 0xB740A804392F0C8EULL, 
            0xD6D0D3365CE135AEULL, 0x5F8D8DC2C0E071B9ULL, 0x1887760F604F1D39ULL, 0x19241DF580067246ULL, 
            0x3C9A2D8E9EBAD0CAULL, 0x8CF4DBA98220958BULL, 0x97E4D7286BD77A34ULL, 0x84041D02480AAC03ULL, 
            0x16E2DFCD8731BC4DULL, 0xA556C7054D113FE9ULL, 0xE829C9FDB84A95FFULL, 0x35D0BC1736EEC3F2ULL, 
            0x414B1524910A2B14ULL, 0x4FD2DCE6E5362C99ULL, 0x6F5CEF6888AC9C61ULL, 0xC9086FB414D1A0D1ULL
        },
        {
            0xD657ED7C9B02E8C0ULL, 0xAD6424A29AE3D3F3ULL, 0x79C9C1D1C911F822ULL, 0x9F9A6CB2ACF4822FULL, 
            0x3324311033C304F7ULL, 0xA15BDEB7B68C358CULL, 0xD01FC3FA777EFEC8ULL, 0xB03F21648B8F969EULL, 
            0x0D650DC7DB3D6372ULL, 0xC440A239CC0AE9F8ULL, 0xED6868C43ED9122BULL, 0x4EE690264E97DD89ULL, 
            0xB56F4BAD38F7A6D5ULL, 0xDED33093FE38E1C3ULL, 0xEE89344FF7E7B9CCULL, 0x787B055AD03587FBULL, 
            0xC2E8583C2EF3E320ULL, 0xE8C5D3CFCB27A1AAULL, 0x6F97FD426D0CF5B0ULL, 0x01D26916701688BEULL, 
            0xAD34E15F135AA692ULL, 0x05F61D3497EBEC62ULL, 0x204F88F4FBEA5173ULL, 0x6A72B60DFD391097ULL, 
            0x409562ABA6FFEB8FULL, 0x4E6D3264BF785AC3ULL, 0x3069FAF5A1AD457EULL, 0x08DCB98468620E0FULL, 
            0x767D1459A813FD13ULL, 0x6721EC6EE07A8C1EULL, 0x998451DF7A124171ULL, 0x2B484358B5BF805AULL
        },
        {
            0xC1056FDE3D1A7BEFULL, 0xA39AACD479E17180ULL, 0xAF5096FCB07D4C5DULL, 0xAD2AFC369BD4EBE3ULL, 
            0xDA192F8E94FE5003ULL, 0x1FB1BE7269076C4EULL, 0xC251F54AB99C326BULL, 0x347AC449217A8C4EULL, 
            0xBC95CF98520FE35BULL, 0xBF8102058F848639ULL, 0x93ECF2D6E159001CULL, 0xFEF071AB5C037E0CULL, 
            0xFEDD93AA789FC691ULL, 0xE79BC4C30E6C29DCULL, 0x3D1A45668AEC780AULL, 0x9FC17EE9E8CAA0A8ULL, 
            0xDAEB6002298CE478ULL, 0xD73C379E70745FE0ULL, 0x988365E88C71C790ULL, 0x214EDA2DDAB3AD77ULL, 
            0xD340A5AF16B2DBF1ULL, 0x602EDD2BEC7E6AC6ULL, 0xEEC933744DA83C71ULL, 0x21CBEFCF76B46945ULL, 
            0xE122129D8D6014FFULL, 0xE0628EDA75B2D35AULL, 0x6836FF0B69B380ADULL, 0xF6484A399F55E51DULL, 
            0x3678AAA4B9CE8370ULL, 0x20F066BA40A1B485ULL, 0x58286FC5965884B4ULL, 0xD10FC9CE738AD562ULL
        },
        {
            0x08F423657B0D3854ULL, 0x044ACC7AD5AA4D18ULL, 0x72781424939D40DBULL, 0x22F39C8C691F4713ULL, 
            0xF6CA9956BA909E83ULL, 0x6E14D85AA04FEACBULL, 0x06AE1009E52446DEULL, 0x4983313E6CF030EFULL, 
            0xD3BD13E6B74F4662ULL, 0x5EF7B2327010E074ULL, 0xDD9D6B495272F473ULL, 0x9DF20108E4AE1FF1ULL, 
            0xA2F5AF50BCF21D34ULL, 0x4A3C06786C883433ULL, 0xC35A0041809B1926ULL, 0x0839867CC15FEDC2ULL, 
            0xEACFA19B0D33C86CULL, 0x6572F43C0912C7AFULL, 0xDCEB824EBB6A317AULL, 0x337DDCF194207CF7ULL, 
            0xC45368E6CE08D39EULL, 0x939F8200724F6C4BULL, 0xEEA9ADABD29722B7ULL, 0xF12BFF4B6944A4EEULL, 
            0x122B11E03CC9B4DFULL, 0xC8406CBEEE8331A5ULL, 0xDF652376BFAD893BULL, 0x475788387C84BE3CULL, 
            0x3428364874BCC1C6ULL, 0xE240700527541387ULL, 0x43D8B08C6E00F6DCULL, 0xDFBEFE61615347F4ULL
        },
        {
            0xFE1F1B5D6919677DULL, 0x07EC2FFC92F1EDE2ULL, 0x0465E6A2E091FB19ULL, 0xA13D48379C2A1830ULL, 
            0xC57FA14DD47B23BFULL, 0x97E9FF1A77B2A969ULL, 0xE923ECCD408CDAD7ULL, 0xABBE75927601E124ULL, 
            0x5D0D9B98CD44432EULL, 0x7F5EA18257A7324CULL, 0xF6C59A5F27AB924BULL, 0xD47CB4DD87B33B9AULL, 
            0x5A8F2473B8B0F0DFULL, 0x8507BA10CAA2BB4FULL, 0x399FADE7A9C9EDD3ULL, 0xB2CDA1CE8BDCDD8EULL, 
            0x7735E77227817879ULL, 0xC9B894CB33065328ULL, 0x41603FD3D4DE380FULL, 0xBABE6D74B0F4AF26ULL, 
            0xD829307313CA956FULL, 0xA901B91DE49DC03CULL, 0x0DFE8FCFE5B2C739ULL, 0xFA2F1AF205C5EF44ULL, 
            0xCFD612ED5378F4EFULL, 0xE6C9C60933F5D61EULL, 0x22A15C857C4B25A4ULL, 0xEE7C7009581DE10DULL, 
            0x9F1B8A53FC88C90FULL, 0x84F14F5B98C6C799ULL, 0x2D2F144C305C66DCULL, 0xB75482D45CB69E28ULL
        }
    },
    {
        {
            0x50435CF699C373CDULL, 0xFE155D13E60ED26AULL, 0x9B8A505ED32519B7ULL, 0x16EA941BFB6270D3ULL, 
            0x0058436759FE0024ULL, 0x6366434F764743ABULL, 0x15D6AE50D91F3632ULL, 0x3A3D62B0FDF60251ULL, 
            0x1BA226F0728454C9ULL, 0x6F8F51BDB36E494DULL, 0x9944A2F2DCB85ADBULL, 0x7C62BFEB9D4115A1ULL, 
            0x233E894BF8D7E0C5ULL, 0xC3591F17A515E5A5ULL, 0xF97A7FB4C81804AFULL, 0x5D3E9FA5636B13F2ULL, 
            0xF2B8B3E952974A46ULL, 0x431FC1047BEA1176ULL, 0x5A03812672BB90A2ULL, 0x13301F1CE0BB03A3ULL, 
            0x7288D7C56958B121ULL, 0x3FA84CA2E330A840ULL, 0xFEDA4624885891F3ULL, 0xCD5F4371BD830695ULL, 
            0x72CF43D6F10A138CULL, 0x41542508E242F83DULL, 0x191924FBDC6E9512ULL, 0xA561B2780B500C97ULL, 
            0x459718A17B03E5BAULL, 0x41F3214D409AFE49ULL, 0xFB5C7406BAA6599FULL, 0x821E18E89443036EULL
        },
        {
            0x9CB64C81006405C4ULL, 0x26591360BBCE342DULL, 0xD8271B85AB20B8DEULL, 0x0D9CBB3401E77473ULL, 
            0x94A2BFBE26F06942ULL, 0xE942F4784BB21AD9ULL, 0xF7A8EF8CA3F26F37ULL, 0xA735432A80C96A02ULL, 
            0x4C3D4554988EE9B0ULL, 0x378E431CCC6E29C9ULL, 0xF72FFBDE7E873B7AULL, 0xB38878ABAE3582C6ULL, 
            0xEEBA560DC9158435ULL, 0x4DF14F76FD406762ULL, 0xFA1545B6C3BE1C79ULL, 0xC9D0037B46F41CA6ULL, 
            0xE1D796573CCB2D1AULL, 0xC79FBCE11676077FULL, 0xB9003A74D57C76F4ULL, 0x4913FE28E8B9135FULL, 
            0x85B298844B6318AAULL, 0xC5258EB11BD530E8ULL, 0x4576D52A798E7E6AULL, 0x633BB5BA46AC6DD3ULL, 
            0x354F4C7FE37425DCULL, 0xBAB551322E8BB9CEULL, 0x91D261CC839F151CULL, 0x150E913F4BFA927EULL, 
            0x7D468DF01A9A6D6BULL, 0x15183D54624AD58BULL, 0xA7378C40BE7F0D1EULL, 0x15D7EE3CAB9A03B3ULL
        },
        {
            0x046E654C25A19F86ULL, 0xBEBF292562539CFEULL, 0x2A42900A26ED04BBULL, 0xCCFF54C7950A1A7EULL, 
            0x61EDE1845AC44896ULL, 0x6362744753E5F672ULL, 0x04D8BF23830BAADBULL, 0x2FD446F86CA56EBAULL, 
            0x68DCEF47F564AD29ULL, 0xE79C3928D5BD0F19ULL, 0x95F866C6DB088899ULL, 0x863B99E54FF9977BULL, 
            0x7AE87071CC175646ULL, 0x06B0E41E7284B81BULL, 0x90B1D7517A4ACFF9ULL, 0xE215F32D40D33EB9ULL, 
            0x5FC7A3846DFD794DULL, 0x385EA39725F7DC22ULL, 0xFB091DBDF3421CD5ULL, 0xAD01A9B53FD24443ULL, 
            0x03558CFB1AD47355ULL, 0x0F3C756D56BA7E74ULL, 0x6A3AF72E72F57837ULL, 0xCF758324940CDBF8ULL, 
            0xD3084473238797EEULL, 0x5DAB6F3288FB4417ULL, 0x1D658951BFDB41B6ULL, 0x907C7AC955548088ULL, 
            0x1EDA9E0B653AB06DULL, 0x354AF3C882AFF480ULL, 0xF24F534F3B94F650ULL, 0x8269EAA7FFC6A8B6ULL
        },
        {
            0x971D7ABFA574EA37ULL, 0x1B0E79325917EC41ULL, 0xD0990D8562FD7AB8ULL, 0x32B1530DB2BA83BCULL, 
            0x9012EE5696DCA9F4ULL, 0x1E8C048E53A4010FULL, 0x1571DB07E7FC1A13ULL, 0x9D2F1A72E8BF1F9EULL, 
            0x316D45DE06BB5D3BULL, 0x826BBEF53AD306F7ULL, 0xD798BB16B5D12CC1ULL, 0x9989D75663319927ULL, 
            0x3BBC22E4A0A55153ULL, 0x8FD6FE6923AC8A69ULL, 0xDC0580DA6D7E255FULL, 0x2AABF550A7D2F6B4ULL, 
            0xCDAE35E61EECAE47ULL, 0xDFBFF4450ECA8FB9ULL, 0xE9A8226DD1820331ULL, 0x73D35399C05BBF9DULL, 
            0xA17CFD93364360BEULL, 0x88AA3B101FB7BD36ULL, 0xF0F79D91B0B1E505ULL, 0xB74625E1BA3A1BEEULL, 
            0x37F7A2867AA8E162ULL, 0x1BC86CF3604425EAULL, 0xA85C61674D348BCBULL, 0xF0ADE39E3043E2A2ULL, 
            0x43F80A002A11CF19ULL, 0xB64AF4FD042735FFULL, 0x91B40741C53AC1AAULL, 0xAD08B01C33FEA856ULL
        },
        {
            0xFEC9758171B3AD06ULL, 0x53026012BE6F897EULL, 0x2E20FDDB8F33B9D6ULL, 0xDF931C56D08D7B2AULL, 
            0x0A3013DEE27A5EB0ULL, 0x9076973F324F59DBULL, 0xA811EFD30C1D4D64ULL, 0x9FA0778D942D98CCULL, 
            0xC89DF60FDB3E263BULL, 0x701723C582EB9250ULL, 0x121D7C344713CCF6ULL, 0x8813393F7F5D2F0CULL, 
            0x4432606DC9BD7781ULL, 0x78B9D9D6334E8739ULL, 0xC4A02D585E7F7E5DULL, 0x06D9AEE36B06114BULL, 
            0xAE8D655D261E65F7ULL, 0x4DBFD9C2F7B07860ULL, 0xD44DB214F93DCC74ULL, 0xFDD1323970C95AAAULL, 
            0xFA0795CB3E42D0F2ULL, 0x63E7F38C5F12C072ULL, 0xD1F496AA735C976AULL, 0xC32563136F28FC58ULL, 
            0x068757DC333B0989ULL, 0xF27CD5D17524A3A3ULL, 0xDEE8CDC1200665B9ULL, 0x2D11D603E080E131ULL, 
            0x99A316261AD700B3ULL, 0xFC0089B7FBD4D8D2ULL, 0xD7C056C2D2B471B3ULL, 0x5C2F8B39075C336EULL
        },
        {
            0x30CA088E20E5B99EULL, 0xA709CB892F397DF6ULL, 0x31AA6A9C8FD1CFE7ULL, 0xEE7D876C804B4117ULL, 
            0xFC63160D2B981CAFULL, 0x2D238F4A5B64E4A3ULL, 0x692226B3C0F2AB0FULL, 0xCF2C7EA75BE12575ULL, 
            0xC14DC3D6B3BEC573ULL, 0x812B6A6C29AD5FA9ULL, 0xCA77E24AE72B18EFULL, 0x7505785F7128AC36ULL, 
            0x40A4D1E6992D1551ULL, 0x400D54AF7D99605CULL, 0x3B64B24FD0EA44EFULL, 0x0425A0F33592A111ULL, 
            0x6E989B837638024DULL, 0x3B8475E077F66D58ULL, 0x5A180D754C0D1A2EULL, 0xB3219D4DA57B3C19ULL, 
            0xC699AEE0AC3F8D0DULL, 0x82BB77B119CB29CFULL, 0x0D914F2C3EC5F0EFULL, 0x88CDAEACE061CC7EULL, 
            0xF817E7FF8C2ADEF2ULL, 0x650AC1870DA69644ULL, 0x15114EAD1976CF9FULL, 0x11757C0C5A1AB6DCULL, 
            0x5CA195B16770AF1AULL, 0xC83328470E88B9DFULL, 0xD9C16286CE3DC05AULL, 0x0122995C21225395ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseCConstants = {
    0x29136FD330EB8499ULL,
    0x9C761790D9B4BF44ULL,
    0x7CE68D617B01FB2AULL,
    0x29136FD330EB8499ULL,
    0x9C761790D9B4BF44ULL,
    0x7CE68D617B01FB2AULL,
    0xC2D9318EE9443B89ULL,
    0x0AED6FCB975AF850ULL,
    0x3E,
    0xB2,
    0x5C,
    0x64,
    0x75,
    0x10,
    0x4A,
    0x71
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseDSalts = {
    {
        {
            0x7EE5C7841734684BULL, 0xB2E7B4884FE404EEULL, 0xB1A0D0F83517DC49ULL, 0xDB78DECD791D2DB0ULL, 
            0x74008D603F0E2220ULL, 0xC7AAA54D0C03C9EBULL, 0xA0B455C195D4AC71ULL, 0x010491FBF115090DULL, 
            0x5865342C57189E43ULL, 0x9555127848850A94ULL, 0x65970A32692C3451ULL, 0xC56EDDD2DAB662C6ULL, 
            0x434F4E315319BDC0ULL, 0x76093427D466AF38ULL, 0xA5EA4ACE941CC552ULL, 0x4123D89CF0C2D2B9ULL, 
            0x765F01568DE8CAF2ULL, 0x3D9F829DCC428561ULL, 0x6DFE8A3758727868ULL, 0x7D7406B765ACBA31ULL, 
            0x9F9EA0CED96BF59FULL, 0x5A37DF38F41DD9D7ULL, 0xDDFA3BB36B0F5083ULL, 0xCB49BBB53474C6A3ULL, 
            0x118B92B18E81A862ULL, 0x0640F08217B9D878ULL, 0x4F29E6BA76F42407ULL, 0x9B07AD9833D5A4A1ULL, 
            0x03ACD3C323A39C9DULL, 0xF6048F7EE7D724FEULL, 0x3D624758150335E2ULL, 0x91ACB20B252DADB6ULL
        },
        {
            0x4CCA6D488465D775ULL, 0xFBD1AA3B4F285DA8ULL, 0xECDEC35402BB4B9FULL, 0xD932D4819410C8EDULL, 
            0x1D00E813149DC659ULL, 0x9F31160D4AD109C3ULL, 0x614F12E0A7CD54DEULL, 0xBF186B6E406735B0ULL, 
            0x0F600892DAA57999ULL, 0xFFE9850D3D5118FCULL, 0x5D060A1BD5755BF4ULL, 0xFEB7C0942916CED2ULL, 
            0xD4C853EF5A96AE7AULL, 0x78E582B3FAEB91BFULL, 0x6116CF13E69A3B37ULL, 0x4792EDC4E3BD5178ULL, 
            0x4D0A308928A4DA6EULL, 0xCA33D39AAC8D9790ULL, 0x353A37E0D32C1586ULL, 0xD3B6AD239851DE00ULL, 
            0x1A7B3B3CB4556D77ULL, 0xFAD05FA46B69FCE5ULL, 0xB9498CA4170D15A9ULL, 0xAA616B76BE8129B9ULL, 
            0x2C15DC806B8C5B2DULL, 0x036B1962434B5E09ULL, 0x7C201BDF9F5F800FULL, 0xBC72F7D5950F95C1ULL, 
            0x4F8DBB212C2C5659ULL, 0xED567950F5180334ULL, 0xCAEEAC9CDEEEB586ULL, 0x1BF31FF7274E2FEFULL
        },
        {
            0xAE0B7D0164555152ULL, 0x9598438E8A2032F8ULL, 0x73B68ED8B7879A4FULL, 0x7D9C0102FE6161C8ULL, 
            0xF699F684D223051AULL, 0xD1FFD595A0D0F791ULL, 0x2B7B7ECBDB7D01C4ULL, 0x628E39BB85F43F94ULL, 
            0xDF94F224BA35F779ULL, 0xC3E13EF466AC7E17ULL, 0x57AB70692D20BA91ULL, 0xD96F3017396BBF50ULL, 
            0xAD0EFFF3765AB3EFULL, 0x1850BA5AA184AC5DULL, 0x6CA603309B983D6BULL, 0x6D45F035C966AC6BULL, 
            0xF66DFCADB3EE0001ULL, 0xF72AC7427547E8E2ULL, 0x67F72C7205B1662EULL, 0x95F39BB7FF8924DFULL, 
            0x6D4419BCCD29980EULL, 0x610DDEDA3A2C5EE5ULL, 0xABD30BA4A2246F14ULL, 0xE40C94FFAE6E9046ULL, 
            0x9238392AC248DC48ULL, 0x1E434F8477472251ULL, 0xD0F09E57445D5119ULL, 0x76B4DD2B113A2BF4ULL, 
            0x01DEC8DFB64EFAECULL, 0x39F82B10AC262F1BULL, 0x3AEDF59DC7129587ULL, 0xC483551A9963DC67ULL
        },
        {
            0x68E32BB668307425ULL, 0x2C06664448DA2ACEULL, 0x1A5AD3B478DF2B34ULL, 0x881113F9BBBDD613ULL, 
            0x974FB5FC73EE1781ULL, 0xD39ADDA20704D134ULL, 0x3CFE7C9482F0A9FBULL, 0x4BDBF03AA6E186B2ULL, 
            0x8C64801EC5BDD548ULL, 0x9CEAE848852C6036ULL, 0x3F2727BBC95C1815ULL, 0x45AB386BEA7AC3DFULL, 
            0xF4536BFE65F1EC6AULL, 0xDE1EC83ED2A2C209ULL, 0xB654BAD01D9991CDULL, 0x669974DDDA766B38ULL, 
            0xF2DC1D9B63AD2F5BULL, 0x9E33B7875BCA30E8ULL, 0x2E3F9C32FBE98EEEULL, 0x710AB261FF996BEEULL, 
            0x28142FA256320335ULL, 0xABF57796062ECB7CULL, 0x0EB915E72939FD8FULL, 0xF4C3DBFF3AA4B76AULL, 
            0x30FCDBBF8133D411ULL, 0xFDBDD07F28687553ULL, 0x0CF5B89B15DBBB18ULL, 0x6145D60C7C11879BULL, 
            0x225344C2343DB379ULL, 0xC523D9BA157848BEULL, 0xF4F24CFD76F1D7DCULL, 0xB845D6578868249FULL
        },
        {
            0x4066607A16829B77ULL, 0x77A09A09A55FF01FULL, 0xC3C1BE9B268C689DULL, 0x3A20E989754FBF4DULL, 
            0xEE5BFB94EED92E96ULL, 0x206B0789C5657151ULL, 0xE40F8BD2195A79FBULL, 0x50288C843D80C6AEULL, 
            0x853EDD2410BA974CULL, 0x872D1BABA0CFB610ULL, 0x611678E3F3710658ULL, 0x17AD13E0DC0C9E80ULL, 
            0xEE0D6D41FC7CD38CULL, 0x31B6E01DE5CDDD13ULL, 0xD7E9434D10F0F92FULL, 0x08741E28222FFC75ULL, 
            0x47D0CB97BA190D8BULL, 0x3E9974A4953B6DABULL, 0x651F5B52CC1E786EULL, 0x6859241EF0D1CDE4ULL, 
            0xB716F22D1168CE55ULL, 0x07F5E7F69427BB66ULL, 0x7131A04F0E2BF6F4ULL, 0x55E486973D209526ULL, 
            0x9EDCCEC73DBD0A0AULL, 0x921CDFA483A7AFEFULL, 0x7C34D0F1AFBF4432ULL, 0x357370D979464AD8ULL, 
            0xC1F4278A805D9B17ULL, 0x4721C3E43953545BULL, 0x9BEA8C7966758C68ULL, 0x3AB17059F1EA775AULL
        },
        {
            0x9A3DD192527484D9ULL, 0x6027C2195661FCBDULL, 0x47D4C515E36CEBDFULL, 0x68DD9ECB244813ABULL, 
            0x72FBA55A6509C411ULL, 0x90421948717B67CCULL, 0xC442C0346F463F29ULL, 0xE1D2EB8041F476FDULL, 
            0xF22C0AAED01F82C5ULL, 0xEED81F04F0C50884ULL, 0xCF03217295039214ULL, 0x781959C199572FC2ULL, 
            0x5071E4A06ABF0412ULL, 0x7C65505ED95BF483ULL, 0xAEB0CB860EEDA866ULL, 0x1758D32B9ACE31C2ULL, 
            0x0AEC7F4FADFF86D6ULL, 0xFB244DFCE73B54B6ULL, 0x6CF58984B3EEDD97ULL, 0x67E9751C8D72F657ULL, 
            0x9FD3424D4B9C7D74ULL, 0xEBC49D10DAA3D964ULL, 0x79E70635662743C8ULL, 0x54D01C8724792ADBULL, 
            0x59944AE7BC8E6AD5ULL, 0x0BFB6B4074847938ULL, 0x7110D62B10F1E5F3ULL, 0xFDC970BA8521614CULL, 
            0xDC1A0C39A32BBAD1ULL, 0xB4635A521E905B69ULL, 0xD5E24640B6468549ULL, 0x352F9E7D8BFDB722ULL
        }
    },
    {
        {
            0x5CA4E3F3D1B5AA0CULL, 0x52C69AAD0F55F2A0ULL, 0x341E043398624F23ULL, 0xAD01BE9B1B9AFD29ULL, 
            0xC18D524F740727E2ULL, 0xF59132C07C4B0B42ULL, 0x71A750617AA14001ULL, 0xDDBF8A014A24430AULL, 
            0x3135C0CD19CA5D08ULL, 0x154EE3439BF93C19ULL, 0x999F39CB701E26C6ULL, 0xA347B37D190CEB26ULL, 
            0x28FA9399784660C7ULL, 0x53878E834FEFF728ULL, 0xFB1CE17BCAC59977ULL, 0x45E2E7456A34AFFAULL, 
            0x0F1A681E2DADAFB8ULL, 0x8233D9333DAD8192ULL, 0x99200CC4F2851333ULL, 0x6907E98B1602A14BULL, 
            0x89E581A1D48416D7ULL, 0xF5B0ED3AABF77867ULL, 0xFAC2ACB45084DD71ULL, 0x8576F9CD7B24ACBEULL, 
            0x7705A31DC4FBCAC5ULL, 0x89A30E04B1EB5A81ULL, 0xDA7C128F20D653E1ULL, 0x3FB2319DA4F6C8DFULL, 
            0xB3C6F171C783E51EULL, 0xEECEB566660A4527ULL, 0x33A87F0006C8C671ULL, 0x13CCF2014980B57AULL
        },
        {
            0xC38F90355852A1D1ULL, 0xB32C9E1F4B425184ULL, 0xE7160EF987F46FF9ULL, 0xD4B28CFA09224E2DULL, 
            0xE4A2E0D89A518903ULL, 0xB34BE8E3CA20B8F1ULL, 0xF54CB669EC3FE8A2ULL, 0x02511311F5ADC9A9ULL, 
            0x3392334EAA9095D5ULL, 0xE9CC64287A11F347ULL, 0xDEB91C6984EE1194ULL, 0xBAEB3397465D3970ULL, 
            0x95B87B2F69B49473ULL, 0x1C7F5BA74B85E633ULL, 0xB0D8E9F5A9BDD0E6ULL, 0x70AF024529FA568BULL, 
            0x5FD8C048F89D4D26ULL, 0x5C9B21120D60086CULL, 0x49CCD279477FD3DDULL, 0x9EE949F26871A2B2ULL, 
            0x668AE2A36A070B1AULL, 0x21045DED9AED6B5BULL, 0xC81F810CFE0D1AB0ULL, 0x64D46223295E38D4ULL, 
            0xD1DB2073C1625DB1ULL, 0xD0C73C62A7CA2792ULL, 0xD6AFAF44E5419670ULL, 0x5121E9C7C99FBF8AULL, 
            0xA540469029A76B67ULL, 0x2E76C89D3710D187ULL, 0x5076385198AFF57EULL, 0xDAA3824F0DD4D141ULL
        },
        {
            0x3D37A41FF4F89564ULL, 0xE6D58670E30A93BEULL, 0x207AC19F9B4D653FULL, 0x301D8FBD40079D01ULL, 
            0x40000B2E334B4CACULL, 0x37E712894FCEA10DULL, 0x32284B28E5A1841EULL, 0xD90D1403EF61BAD7ULL, 
            0xEC221476BA9E7A7EULL, 0x41470C69F60FE476ULL, 0x6D25556D7A9B80F5ULL, 0xD47A956E9FC62B4CULL, 
            0x9465C074024FE132ULL, 0xF0D026621E4F6C79ULL, 0x13B82A8AFE633CFBULL, 0x1F8F29CA339C0648ULL, 
            0xD78179D609CAE1B0ULL, 0x3EC45DD9B388B351ULL, 0x5974E72B71EBCBB3ULL, 0x84C9B4470D51CAD8ULL, 
            0xD3DBEC8D20CE8CC9ULL, 0xCD2A5823DB56327BULL, 0xE6DD95EDA59664F2ULL, 0xC834E3FFF6A3A219ULL, 
            0xF2DDE7B7E965A2E7ULL, 0xCC9A9E8C57D8885DULL, 0x271FD45D1ECA8718ULL, 0xA7E28B74E1DCBEEFULL, 
            0xA76D11B1D5328F04ULL, 0x623DC08A0A764D5BULL, 0xED9032AAB88689D5ULL, 0x50D9D16715811029ULL
        },
        {
            0x8E52894475BA5385ULL, 0x56E7E5E1768D8E62ULL, 0x01BB352D696CF7F1ULL, 0x74016B5723E75B1AULL, 
            0x31CACA97828327A5ULL, 0xF3626686373EEC86ULL, 0x791FD093619F7CC8ULL, 0xCFC4A06B75F9E4F1ULL, 
            0xA611CF9E16F96E5DULL, 0x9AC74663B1E635C5ULL, 0x9A9301BDC47883D5ULL, 0x20629A722EE9FF6EULL, 
            0x93DC846ABE79AE77ULL, 0x07FB91611CD5D86EULL, 0xE4A69DAA11D13219ULL, 0x2132F1475F7B375CULL, 
            0x46692B6A0796175CULL, 0x31F7B705917B19C3ULL, 0x13CF17B98068BF71ULL, 0xE6467F25AA701A23ULL, 
            0xAD87369570ACEA6AULL, 0xBAC3BFA829ECC6E3ULL, 0x60A6DA999C376627ULL, 0x16948C51783835A2ULL, 
            0x2B997DAB75073347ULL, 0x05060F914069955EULL, 0x668236F131FAE9FAULL, 0xB621CAC0B5E73E99ULL, 
            0x10234C1D4C312570ULL, 0xE63D88385279208CULL, 0x2FB003B98CCABAE7ULL, 0xA0F6C5D393AF2470ULL
        },
        {
            0x05087669039537DFULL, 0xB6453462CBCF0083ULL, 0x0D30A4B6F1845628ULL, 0x45076718CE103B08ULL, 
            0xFE1C12E02277D709ULL, 0x5EB107BE3BB5183CULL, 0x2FC7977088B082F0ULL, 0x8C99940BD0240A3DULL, 
            0xA8F5F0374116EC05ULL, 0x80D4DD62E7CA1BA8ULL, 0xDE5D6236D221740FULL, 0xE59EA2605201457FULL, 
            0x9845AFC3A51C7C2FULL, 0x8437E0B115984104ULL, 0x0D0E756863CE2F24ULL, 0x03446CEF254159F4ULL, 
            0x1A7FE0D78BF20CCDULL, 0xEA744569765120F6ULL, 0x54F0B2F0AD472BE4ULL, 0xF4B9490772D3A337ULL, 
            0x29FEF4F221345557ULL, 0xB3F28B4BB4CB8199ULL, 0xEA180B65120F357FULL, 0x2702326D7E9015C2ULL, 
            0x9B7F87CDD2582D5EULL, 0x1AD939650322A45FULL, 0x12DDCD64AFAE9337ULL, 0x889F31A756FD1FF7ULL, 
            0x860030A65231F7C6ULL, 0xDEBB6345B17FE0E7ULL, 0xF74EC6DDE5737F39ULL, 0xEBFBC64DD2686617ULL
        },
        {
            0x30B6AEC69D4C012DULL, 0x687C5EDC2EBB88FEULL, 0xDBD04F59E3876DA6ULL, 0x4235EE762567C535ULL, 
            0x2923221306BB7FD8ULL, 0xF099E76992F07532ULL, 0xD5AEB2A0878CD4C1ULL, 0xD3EAA5F5A6489A57ULL, 
            0x125457929C2E734AULL, 0x46A311506AD1B17AULL, 0x8D2CF0D869B90DDCULL, 0xE681411AA5C6434AULL, 
            0xD8054AF1E63C7955ULL, 0xBA106172DA2E76EEULL, 0xDB1EEC09C653353FULL, 0x48941413E539337DULL, 
            0xA48CEBFEB649DF58ULL, 0x63F3C9F5789A0D01ULL, 0x96927014B880DED5ULL, 0x04CBC16B69756B3CULL, 
            0x820BE65A92BDE429ULL, 0x8AF9724FDB0A888AULL, 0x7B4F5180D40DB877ULL, 0xB27A3EDA2E542CEBULL, 
            0xD89DF2E738A85E66ULL, 0xBEC7C65848B4BE73ULL, 0x13145407C9220783ULL, 0x8F0952ECC5522148ULL, 
            0x31D60D9E1B0CB48CULL, 0x8E5242E45B1D7FA2ULL, 0xCF3665803398CAB6ULL, 0x54E35F9BC12CB127ULL
        }
    },
    {
        {
            0xC9D31CE7A2258FA8ULL, 0x7169F68CE905942AULL, 0x50F038BA80E7D505ULL, 0x174E4F7AA9284F42ULL, 
            0xF9F1D7EFD6C1BFB2ULL, 0x32B1292FACD0AB57ULL, 0x7448A7C0DC5C26D6ULL, 0xF5AB4283C70190B3ULL, 
            0x2A37EE3FA9A365BBULL, 0x1BACC4B5A79D0DB1ULL, 0x9ECC084A4C07FA1BULL, 0x86A04EB2D30FAC11ULL, 
            0x9E39DE8DFCAC93C8ULL, 0x8045AB3ECD22986EULL, 0x3AE1AACBAF9E850CULL, 0x423A7DE56F9D7F5BULL, 
            0x1B5941353ADD9B45ULL, 0x7FC787A1B61FA513ULL, 0x8E3DAB43249816D5ULL, 0x4CBE59227D085707ULL, 
            0xF872624E9994CB35ULL, 0xD0C93B0BC106CC74ULL, 0x70DF5BB48F5A2159ULL, 0x92D7D23C47EA13B0ULL, 
            0x46B0C344CFC923D2ULL, 0x9CA0DEEECA2AB27CULL, 0x29D6B29C7C3A6463ULL, 0xD0384146570ABA43ULL, 
            0x871D22D62C02EECAULL, 0xEAB15C54BB9A4F69ULL, 0x02FCD2A8891C29D1ULL, 0x5CF88F2F351A1449ULL
        },
        {
            0xBDF8996D8C240CA3ULL, 0xA70786740DD59D70ULL, 0x330CF5757FE9A6B7ULL, 0xF8BA27A2F2A3018AULL, 
            0xAAF92E40CDEFB06FULL, 0x917D5192F8A83559ULL, 0x31FB7A9978ED91ECULL, 0xDBF32D7965B6B128ULL, 
            0xCE82FF030262033AULL, 0xD781FF1A1B462D6CULL, 0x232767CA8340A27DULL, 0xD22AE6B45F6F1FEEULL, 
            0x2C7D4FFF0B569090ULL, 0x968B4E87E9F5632DULL, 0x16FF54ECD183FF8BULL, 0x7F22A8326C69C306ULL, 
            0xA60A50CBC7016985ULL, 0xB2FDEF3A2E406098ULL, 0x5FC020F9F5A5294DULL, 0xE5725EFD6B0603C0ULL, 
            0x6A80A9FE1CAA1EE0ULL, 0xCA12E997297550F5ULL, 0x6ADFD893F4720D32ULL, 0x693F5609809F6085ULL, 
            0x591372FF0905C675ULL, 0x4D87C7F2BDE46971ULL, 0x2913B2D83ABD3A6BULL, 0x9D69B4065B3EE71CULL, 
            0x6E2DFA9920C1DDCDULL, 0xB7F3DA213E1E4332ULL, 0x8F8A408CD042BB44ULL, 0x36516455A8F22A97ULL
        },
        {
            0x789D18A7AE591267ULL, 0x3C887B0D7C33A73BULL, 0x2F20C5B9FFC973ADULL, 0x54AA85DEF4D4324DULL, 
            0x1B3F5E851B827FBEULL, 0xA21B4403C82EF023ULL, 0x002AA550920DBC29ULL, 0xE07D246476672097ULL, 
            0x8A67753FC575A17CULL, 0x5123C9BB5EC5275BULL, 0xE26C2B171B426BDCULL, 0x5D6EB3248094630FULL, 
            0xE96755470511D2AAULL, 0xD38CD72EDFDFC56EULL, 0x1B53388D392BE2BEULL, 0x8FC42AA8C9C42CFBULL, 
            0xDEE12585562C4254ULL, 0xDB2BE4E06B015271ULL, 0x06FB4213FC4DB4A2ULL, 0x0751C308587594DBULL, 
            0x937FF0A0A02B7230ULL, 0xD1CF223936A64EA8ULL, 0xEE43498BF994D6BDULL, 0x5A0ADC3C06A4D034ULL, 
            0xEC38D5434F4E6C78ULL, 0xE9BFD01928EB2D82ULL, 0x95879025480AE914ULL, 0x1BB4811383BBD810ULL, 
            0x4A3C463257B97DEAULL, 0xEA4081C55BE458E1ULL, 0x94407060F4241947ULL, 0x5B9704D2F1F2A499ULL
        },
        {
            0x8B0520F4B06D9620ULL, 0x5BA5426686AE9B0DULL, 0x65BA0B96A4D4567AULL, 0x46467D60BCDD9B83ULL, 
            0xF70D95E78FE45D98ULL, 0xF5FCDB2B1FF6F771ULL, 0x08B94628C55564A2ULL, 0xECCB09DA76D31B4CULL, 
            0x864BB459C6F8525BULL, 0xCD63B4AAF8BCEF05ULL, 0x772F2E610F07805CULL, 0x5494F6E65A7649DBULL, 
            0x780478F569C37BEFULL, 0x741037370264AB3AULL, 0x6EAFDB042FBFF3F8ULL, 0xA25A7EA60FF324B7ULL, 
            0x8AFBEB9E945AF9D0ULL, 0x729C7F6080B9721AULL, 0x100C1BAA37FC208AULL, 0x586488DB4C9EF86FULL, 
            0x89C09652E14D340EULL, 0x388BF4A6222A4EDBULL, 0x598321E8E9FEF1B7ULL, 0xED91CB851B9BF89EULL, 
            0x3C682C794E24CD41ULL, 0x5A9E2A1AE7EA3E4EULL, 0x5BF823C3DC83D365ULL, 0x5C69F0CBB4214030ULL, 
            0x70C3B3F1CE58BCF6ULL, 0x21246CD65BF8A584ULL, 0x47C2082290EB712CULL, 0xE3D1AAD0D79D55E4ULL
        },
        {
            0x86E19EF9535D5086ULL, 0xF2FF7B8A6D8FDE21ULL, 0xF0349DB56776A3EAULL, 0x56C09897D9D62276ULL, 
            0x3E342D271BF9BC8AULL, 0x5FD48C77A1B1A31DULL, 0x5CADDAA318026CCEULL, 0x2B1FD436321627A6ULL, 
            0x8A5A4558ACB21785ULL, 0xA6F935452F83A0F9ULL, 0x86F856530A805B9AULL, 0x444831AF826E660FULL, 
            0x27009AD4EC3CD7B6ULL, 0xC89D5891A8422231ULL, 0x3A0792C43964EE9AULL, 0x491FC9E9A17C82BBULL, 
            0xE994F7935EC10571ULL, 0xD20656314F501364ULL, 0x68DC84E570164AA0ULL, 0xF7758040F051E38BULL, 
            0x77D42BB0F9987566ULL, 0x1AF61E95BE5015B0ULL, 0xD074060EE82C09CFULL, 0x095572BCEB758FF3ULL, 
            0x1685D05F770E9C6DULL, 0xA8144DDD23E57389ULL, 0x834429CF99CE96CEULL, 0x45F0EE4BCE720778ULL, 
            0xC602F63A37EFBB44ULL, 0xCEE0EDDE3D2D6F0DULL, 0x73E9C0A73FE13248ULL, 0x4B1A140F76ED9C30ULL
        },
        {
            0x779C8D3FA9DC2822ULL, 0xE507E2D9473C2D11ULL, 0x6F5E7DA36E7AAF98ULL, 0x7474BE3EBFAFF2F2ULL, 
            0x8FEBD17A48C0932BULL, 0x1D77666567AA91FAULL, 0xC19AB8C87859F3A0ULL, 0xF21A1073346B22D1ULL, 
            0x93765553B7F7C1BDULL, 0x11B058AD5BF5CA1FULL, 0x80758E20C159EF20ULL, 0x2EA02D8C47A4A3B3ULL, 
            0xC926BE7B6BCAF0DAULL, 0x072C092B1830CE77ULL, 0x6EB005562E95ED21ULL, 0xDFFA954241C1331CULL, 
            0x78022EA352B42D1EULL, 0x6ABAE406A1C0860DULL, 0xB122F55E55EF1338ULL, 0x066082A97548BDEDULL, 
            0x89EA8812A1ED0D85ULL, 0x86C0031A1D11C326ULL, 0x121999E0B777BC65ULL, 0xF90BDF06D2277984ULL, 
            0x7798CB43D65E4E9AULL, 0x6DF5193B02168968ULL, 0x0FEB4E43C08A037CULL, 0xF17E54CB4368EED7ULL, 
            0x87C87CCF926A13B3ULL, 0xEDA2815C37142A27ULL, 0x4ED175DA4779F338ULL, 0x51BB2F8EB486F731ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseDConstants = {
    0x447E431375B37DFCULL,
    0xC1C509093FCF6689ULL,
    0x063B683A046B52B6ULL,
    0x447E431375B37DFCULL,
    0xC1C509093FCF6689ULL,
    0x063B683A046B52B6ULL,
    0xF59180343E351370ULL,
    0x69527A2E24AD5635ULL,
    0x62,
    0x07,
    0x62,
    0xB6,
    0xE0,
    0x87,
    0x87,
    0xA5
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseESalts = {
    {
        {
            0x29E1C0C90E85B54CULL, 0x53DF2B99295FE567ULL, 0x0106113FBB171F3FULL, 0x910FF88E5765A2D5ULL, 
            0x4669E0AF8583C7D3ULL, 0x5945A606F2AABD8AULL, 0xB3195758D8EA6400ULL, 0xA60EB7052A5ECCB6ULL, 
            0xCCB7E6A09CDFEE85ULL, 0x8A74D0FD0EB55ED6ULL, 0xEB70DA03F58B6AB2ULL, 0x45403DE222EDC34BULL, 
            0x424104F9969A31D6ULL, 0xD724BB65660A3B48ULL, 0x2F0C9DD20C308487ULL, 0x1393F60D661BF851ULL, 
            0xF235A0F903495F45ULL, 0xF8A5BC650843FE29ULL, 0x76DAD1B519AF8C5FULL, 0xF728A62EBDD60F48ULL, 
            0x39EBDFA0D4A97F7EULL, 0x25E8F48D74CCA442ULL, 0xABA89BC241CA8517ULL, 0x2F2C495E27D99BF3ULL, 
            0x23B102F44C2648C2ULL, 0x90E3569370E538DCULL, 0xBBA92D29FFC88B3EULL, 0x2075D3984819EC2BULL, 
            0xFC9B45B6DD526773ULL, 0xD1AC7EA9FF4CD9FCULL, 0xDD4B6F86C4021119ULL, 0xCBD40132F4015883ULL
        },
        {
            0xCFCD0CA1DFE9A472ULL, 0x7D27BEF7DEB9A93BULL, 0xC3D2B01FA374DF4FULL, 0xA0EA25630E59D3B8ULL, 
            0xFB7DAC2811AB530CULL, 0x2ED904F09B695710ULL, 0x355028C3EB6948C0ULL, 0x6F0B60498C8C2060ULL, 
            0xAEDB11AD29939385ULL, 0x1C1172C53BB0CF7AULL, 0xD71213ED3E2EF60DULL, 0xA7B6983B84A38AC2ULL, 
            0x6BCFE7621A7FAF36ULL, 0xB5EE0870D8D6A0B1ULL, 0x062C3981D6B86024ULL, 0x8BC8486E94D892FEULL, 
            0xDF5E7D20E65E45EAULL, 0xE58DA982EA93DC67ULL, 0xCD9B9D4CAFF9D5CAULL, 0x30C4417C125A75F0ULL, 
            0xA32571FE1431E3D8ULL, 0xD409EB182CD5BC4BULL, 0x649DE894F7F43218ULL, 0xF958E5DDBF55ADBEULL, 
            0x2A82480F106AC76FULL, 0xD251C724795CC95BULL, 0x7A0FE7B44128E7EBULL, 0x6DBCFB03805FC20CULL, 
            0xBCA7F90CED39C348ULL, 0xC3E9EE6A0421715EULL, 0xB92B9163E070A205ULL, 0x7D61387134A1FC30ULL
        },
        {
            0xBD0F8D808E84AAC1ULL, 0x5A55B093D755EBCFULL, 0x37FEC8AD10A00418ULL, 0x63EFA6FDDCE990AAULL, 
            0x435AF09DA1AB67CAULL, 0x3C98EC1B400F4439ULL, 0xBA919D77769E90C5ULL, 0xB929F1D140380671ULL, 
            0x188AE2D4956E5643ULL, 0x199E007472F98F5AULL, 0x669C5C8E2EA9EE18ULL, 0xF0FF2A6014C4E07BULL, 
            0xDCF6463788B3DDFFULL, 0x8264C4389A8C068FULL, 0x80CFA12C7D6BDC3AULL, 0x56D673D9F5A94117ULL, 
            0x6E742E49A3284861ULL, 0xB7B64D29B418D6CFULL, 0xB265080A4CE3D403ULL, 0x156B7ACFCA85AC1FULL, 
            0x5BE4432B3D62BE41ULL, 0x9CD7F79202CC7A86ULL, 0xD830D810A4DC8C81ULL, 0x2FD1CA5339E127F9ULL, 
            0x23A927C1B7AE344DULL, 0x3FE029333349D968ULL, 0xD49704BEEBCFA800ULL, 0x8B7D3216A6D7F7EFULL, 
            0xFE14357770B474C8ULL, 0x8EBE3BC90594CD48ULL, 0x3ECBA99B5AC01C28ULL, 0xBD5658EFF45F4C49ULL
        },
        {
            0x006FE2E84CDFDD49ULL, 0xB638B4F87614BA79ULL, 0xB3121BB4176E0673ULL, 0x431CBE8CB8438931ULL, 
            0x30258D3702BDA6B3ULL, 0xD742095718AC94AAULL, 0xDD02BF59BD65F648ULL, 0x89023B135CA0C051ULL, 
            0x81CEC6A2D46B7E2BULL, 0x497749013B44DFC6ULL, 0x607B584EF3ECE580ULL, 0x31874BAA17E2E060ULL, 
            0x5CBD9B0B832449C4ULL, 0x6C7E49EC72D3A810ULL, 0x4E30718633DC3A32ULL, 0xF5000606512F57ECULL, 
            0xE490BD2E0C0449FDULL, 0xCDE58D31EED5560EULL, 0xBE05BC9374A9EDD5ULL, 0xF313C85F99A26AE4ULL, 
            0x7E1A2E8E11E95601ULL, 0xD9BE6F9423E09151ULL, 0x255383214A213AD6ULL, 0x70F94425729E20C5ULL, 
            0x2BA0C28C72456139ULL, 0x29E7040A77E99E12ULL, 0x532E69803B88ACA5ULL, 0xAAAD1D9F6449E10FULL, 
            0x9B780F25E3397CD3ULL, 0x7761FEE6AC9C7246ULL, 0x0211B91346B3D3C6ULL, 0x5A0F3BDA0578674CULL
        },
        {
            0xD72E1378B74BA29CULL, 0x4C5F4F162650079EULL, 0xF74B74DF2563D230ULL, 0x1617F6B7684E3E4AULL, 
            0xC2AE3FE9FF245AB6ULL, 0x98D916E8DCFFBC01ULL, 0x5BA13C57A93D13C7ULL, 0x861AC69354B52EBEULL, 
            0xB04678ED2BB6D2F7ULL, 0x9066EBCC920736CCULL, 0xE42E9639B5C63AECULL, 0x0A50E469C8B1C816ULL, 
            0x830BA7F43036379CULL, 0x83A55CD7FDA9818AULL, 0x6B3033E2FF714607ULL, 0x6EC2FFB27E36767AULL, 
            0xCB9DA9F1987E5680ULL, 0xCCABEE13ED1B6DB1ULL, 0x34A78B02136F1F60ULL, 0x3F274E4EFFC7F60CULL, 
            0xB50E901CCFAE2E66ULL, 0xFA5CE28FEA16E077ULL, 0xB3A18CA16D790CC8ULL, 0xA583659F6F667C6FULL, 
            0x4FCF36250B3A1E54ULL, 0x322EA210C731DE4EULL, 0x574FE3CC1FB61F35ULL, 0x581B98C99D67DD9AULL, 
            0x53E46D8B3DD277D5ULL, 0xF41B80DC323951EAULL, 0xF67AA0BDA728D958ULL, 0xC176A4A5DBF4B38DULL
        },
        {
            0x5B045E1A4061072CULL, 0xFA3ED273FE05C348ULL, 0xA3FF05E438140BB0ULL, 0xC36D2A3A4429F645ULL, 
            0x2055D85F3A7B77A4ULL, 0x540D47FC414EB6DCULL, 0xC8F07708B3756BECULL, 0x2547F122ED694AEDULL, 
            0x85826EF297B783FCULL, 0xED7C4C0E8C2CB510ULL, 0x0EBDC4B2D9F9BA27ULL, 0xDDE6E36A1F77A727ULL, 
            0x4344AABFC4C941F6ULL, 0xFC44ECBFCCEDDED3ULL, 0xDD89B4E0E7A4269CULL, 0xB311C6476F59D495ULL, 
            0x0CFA9C85F97234B3ULL, 0xC32C47D083568EB4ULL, 0xF2473F2247A1C0B1ULL, 0xBA00161BAD6F7BD8ULL, 
            0x5F46898848B68A57ULL, 0x98E96720E1CD0328ULL, 0x5F11A7D999CF04D3ULL, 0xFC4D3993EC18F61DULL, 
            0x0C16884F52E1B9B7ULL, 0x09451616408EC4DCULL, 0xDDCA97BEE4100B94ULL, 0x9EC5CBDF200D54A9ULL, 
            0x0BB88BB840FFAB70ULL, 0xD3076D63F826163DULL, 0x9A102E5A8CED52B4ULL, 0x13C997F4FC32EEADULL
        }
    },
    {
        {
            0x46C98D0A798FDE60ULL, 0xEB1F7B20D9837CE7ULL, 0x60AA2C7EC03A0A33ULL, 0x253459224B78E730ULL, 
            0x3801F9F6FBCFE93EULL, 0x7B9B832BAD835477ULL, 0xEB7745EAF8692866ULL, 0x1CA2DFD09B9F9485ULL, 
            0x93CC23DBD0112261ULL, 0x6D62D45AE466D983ULL, 0xEF6D9680ABD14E4EULL, 0x7C59881DEB433FC2ULL, 
            0x8FBA35915A890670ULL, 0x7EDF43A53F140A8EULL, 0x579DAE8B7490F5BAULL, 0xB37F3C31D8473A6AULL, 
            0x547940ACA649EFB2ULL, 0x0FF584A52549EC7DULL, 0xB0F6E45F53D740B3ULL, 0x47CE8BF7F8841C10ULL, 
            0x0C5EDBB999C119EEULL, 0x9D722E31C785AF17ULL, 0xD6F7165FD456F5FEULL, 0x4B4BFDB294EC388DULL, 
            0x76107D49E36EB1E9ULL, 0xF54F8396886E75C4ULL, 0xA31DFDD6A34B515BULL, 0xE5BDF2C02EFD48DAULL, 
            0xB346F1186AF3AFEEULL, 0xACA21EBBE0009406ULL, 0x250F06C2111340C7ULL, 0x3FB0B0813D9ACD7DULL
        },
        {
            0x8976B569B8C5638BULL, 0xA4E7D84655075CE9ULL, 0xC46D70626A9C634DULL, 0x0F8016F3F656524AULL, 
            0xCE5DDC74BB67080EULL, 0xE6BBC0276F9D50EEULL, 0x08CCE03F4EFFFC6AULL, 0x9533701EBCB2EB8BULL, 
            0x951FAFC766314DD5ULL, 0xD704B95712BB7060ULL, 0xBEA10B6A9FD9ADF0ULL, 0x02FF092EBEFF40FBULL, 
            0x326F73AE1D64515BULL, 0xE78E64346FBA9F15ULL, 0xD181673E2F3324CCULL, 0xC02632DB46041162ULL, 
            0xA8420A75BD5E2E10ULL, 0x967CE52D1527F56EULL, 0x9028C21C55B4FD1CULL, 0xC08252D27F7A6C86ULL, 
            0x88B3F2F073F43CC6ULL, 0xEC6084E626FE7BAFULL, 0x491F894BA52843B7ULL, 0x369FB430433C5032ULL, 
            0x7CE02E662C97D4D1ULL, 0xD3E4B6E6F98C0FC5ULL, 0x10B573DE247E9045ULL, 0xFDC4EC34A344966BULL, 
            0x665DBE2D72C294A9ULL, 0x8798E1EC5854DB42ULL, 0x57E03E07A7815E6AULL, 0xCC149A86410F1C53ULL
        },
        {
            0x28B3DAF6BDE1005AULL, 0xA5CB205C0A64DAAAULL, 0xBAC570CF7F61A73CULL, 0xFAC0ADBEB9143D37ULL, 
            0xD8DBD536BFD8D277ULL, 0x3DA96C406C0674AEULL, 0xD30E3EEC236D1747ULL, 0x3E7F2B55B16B4413ULL, 
            0xC982C1DE1CD3A207ULL, 0x4D9FE88E376BB7D1ULL, 0x3ECC64487760A6F4ULL, 0x73EEE39BEB509319ULL, 
            0x39DB3A7265B4E9AFULL, 0xB1916850E44FF59EULL, 0x0A0B4D96F6A4F5C0ULL, 0x5A1A248C94033528ULL, 
            0xF4532F9FC83C26D7ULL, 0x3FF9F40529E7C261ULL, 0x3CFCBB41B52A454DULL, 0x87E98C4F60BA29F1ULL, 
            0x882242532D1C6E66ULL, 0x3634988130D21E2DULL, 0xB865981EAF1FBFA9ULL, 0x4E3FB7B34CC259D0ULL, 
            0xF8228EDBA6233371ULL, 0x90C41A5E771AD7BAULL, 0x8B886D01C793E181ULL, 0x875811FE08288080ULL, 
            0x99867EB1D6FA143DULL, 0xA1AC06DD733DFA9CULL, 0x91218CE1A002F0E3ULL, 0x821038CBDE6A0862ULL
        },
        {
            0xB0788F3B72009E1BULL, 0xE80E7E9F278F3DF0ULL, 0x9D7BB82CC7B0CAC9ULL, 0x01B0D13C9D85C261ULL, 
            0x2BB920F4CF0E86D4ULL, 0x18837C765EF289C2ULL, 0x9B7702ED30D76106ULL, 0xD60AD62B7FB904E0ULL, 
            0xFC0E7329013888DAULL, 0x56110D6B7AE02BA2ULL, 0x86CC01338ADE587DULL, 0x0710BA3E83BAF43BULL, 
            0x3876DA9B1AA6657DULL, 0x3519E1A13E5CF91BULL, 0x113ABB36BD160950ULL, 0xF4CF6007CCB40872ULL, 
            0xF14B7807A7795975ULL, 0x9CC8B58AC4B8BF79ULL, 0x644A08F3CFAD364BULL, 0xCCE83E9D487DB8E7ULL, 
            0x8EA002543DC57B12ULL, 0x9197B1E774C29766ULL, 0x71834CA65475B891ULL, 0x7655001B6FB01706ULL, 
            0xAAC3230F2D230380ULL, 0xAFA85725D9F5287BULL, 0x9CE11D4CAE597E3EULL, 0xBD878E0FD548506AULL, 
            0x66CBF5FB6567D03EULL, 0x24D86F112541FC28ULL, 0xC59EC74EA125416DULL, 0xD573C1C5470CF8ACULL
        },
        {
            0x20567F5C6712EC8BULL, 0x43AAA92E3916AA55ULL, 0x5AE63DFCCDFB73C9ULL, 0x1C932E9E6D4C256FULL, 
            0xACB37C43DAE368C7ULL, 0x76F5DA15A1206D42ULL, 0x383B40D4A2259798ULL, 0xF2E8C396DE2C6B09ULL, 
            0x48D172078A68DB4DULL, 0x8BDDB88123856A20ULL, 0x6EC8D1593CEE06A7ULL, 0xFD0DB38BC9BDB5A0ULL, 
            0xF73C7AA08C572315ULL, 0x8E52D9F8925A04D2ULL, 0x87C13D1F364E71B0ULL, 0x636D71CED77E57DAULL, 
            0x7DAF219D53DF8AFFULL, 0xFEA2FBE9870EF2D5ULL, 0xB4AF6DD2D2322490ULL, 0x5C9D7C24BDBD1365ULL, 
            0x1184B2F77D2A776EULL, 0x791C5C7302D722BCULL, 0xB60E9BAAA356AF97ULL, 0xFFDBE579F46C0B2DULL, 
            0x7A9532DFBDA2E12CULL, 0xD43B56CC6FCB1F07ULL, 0xA61EE9A475920C16ULL, 0xB09CF9B9AA62CE3FULL, 
            0x6E7597D1CED988D1ULL, 0xAD7C90D1634AEBD5ULL, 0x43E8AB29D8C9A6D3ULL, 0x0A5A1B2E11D0E729ULL
        },
        {
            0xF79354826B9BADB6ULL, 0x7E5F382D6324109CULL, 0x8DD1B3DE10C31B40ULL, 0x718D533BD186FA67ULL, 
            0x19072A461EF1A77BULL, 0x7F36F0FD6592254EULL, 0xD262C61495EEE02EULL, 0x2C48E62A92564336ULL, 
            0xE0A9417D0E1EBD4CULL, 0x5703DAA510563F76ULL, 0x2B097B14574CCD51ULL, 0x44A44B48778CF3B6ULL, 
            0x39D365BA7A20B02BULL, 0x9580060C9F1FE67EULL, 0x350C17DE080974E6ULL, 0x0822593B81581465ULL, 
            0xF6DAC49C51BEDC4DULL, 0x15F40B9791357C1DULL, 0x07B99A89A759A030ULL, 0xFD50CF414F489322ULL, 
            0x135DC01DAA88D42EULL, 0x84516FD6DE3D0BCDULL, 0xEA4319614D46AC1BULL, 0x6C5D9AC40EC0FDDFULL, 
            0x1ABCE5052A79057DULL, 0xEC1105655E28A0E6ULL, 0x216B5F58F6A668D0ULL, 0xBFA0F5F03C1E1119ULL, 
            0x55887D6570DB1C68ULL, 0x929F24BD320ED631ULL, 0xA95A16E408E7384FULL, 0xB18A87241160357FULL
        }
    },
    {
        {
            0x3EDF7BE913AD007EULL, 0xC18B0001861D3A09ULL, 0x16A31FCA6F1C9792ULL, 0xA47C160CCDCB1FA9ULL, 
            0x53DA58F5D7A265EDULL, 0xF365F596D9BE1C05ULL, 0xA6F337F1BB958937ULL, 0xC6A13297BB352FAFULL, 
            0xF037ECB28D458A64ULL, 0xD9D82AB8260DC5EEULL, 0xD0212C50D59DA3E2ULL, 0x45A3B18FFE4E47ADULL, 
            0xE593160C8030B9D0ULL, 0xA8FAFDADA3A8188FULL, 0x0DF35D48044962B4ULL, 0x322FDF89599003C5ULL, 
            0xA58D88AFAF6BE8D5ULL, 0x76A2A0586DD3CA9DULL, 0x6E46091007D0B216ULL, 0xDA691C2BD386FD5DULL, 
            0x26E0635DB68C2A74ULL, 0x33B349B4C2A7E71FULL, 0x3D28E26E842D491AULL, 0x58E9ED34A4B370D7ULL, 
            0x4C85458A1D654CB0ULL, 0x9FE8462B39254167ULL, 0xA07969A9D710AFAAULL, 0xF1A2DAFAAB3C5822ULL, 
            0x9FC308ED123118DDULL, 0x00775006ADB84732ULL, 0xBADFD5C21C04F691ULL, 0x0514B7EBDBCF6C7CULL
        },
        {
            0xD52B878EEB53219EULL, 0x2B3821DD0591ABFDULL, 0x83EDB7A0B7BAF959ULL, 0xC805BC5C73F03F9DULL, 
            0xB36AA38C7D2D5538ULL, 0x33FF7AB427A84C1AULL, 0x5E3B2632CD852BB8ULL, 0x87025CFBC7076F99ULL, 
            0x49F4658C7820042CULL, 0x516767A31168400BULL, 0x2DE3E748A2787BBBULL, 0xDE7E32C3EDB75C30ULL, 
            0x28A1F21C8304A715ULL, 0xB31ED13774A3E173ULL, 0x0F3182DD01738AD1ULL, 0xEDB4C0C8BCB3D2A2ULL, 
            0x701152B008BC54F2ULL, 0x48B56DD0BEAEAAB4ULL, 0xFE26B04E2F7E6696ULL, 0x9BFA6070E8745024ULL, 
            0x856064510F89CABDULL, 0x29DE69F5DD0BB9E5ULL, 0xC6935B15D58E72C4ULL, 0xC56EBCE324F097F6ULL, 
            0x354E11E99D98FBA3ULL, 0x6043480583B56414ULL, 0xB00903DD6208FD3DULL, 0x1BBE3361A49BD3B2ULL, 
            0x877BB558D8FFE00AULL, 0x0757218ABF0AF847ULL, 0x337BE8B392B2A07DULL, 0xEA5A2978166371FFULL
        },
        {
            0x92AE2C0DDE1EFAFBULL, 0x8B06770991528FAFULL, 0x0807CDA792EB8EA7ULL, 0x074D7D0DFA0C29EAULL, 
            0x70597FD068ECEFEBULL, 0x36C7DCE1FBE6473AULL, 0x490A2A3A0106B10FULL, 0xF50E022565366198ULL, 
            0xF4CBAF5B847EB6C4ULL, 0xE32D8AA051271746ULL, 0x78FFDB5685644DF9ULL, 0xBDF2697DB9BE1885ULL, 
            0xDF6E3034358BF67BULL, 0xF5A511BDB0B6FAD2ULL, 0x7A5D624112ECED41ULL, 0x230FF06F4DC4F049ULL, 
            0x566264F8CCC8F7EBULL, 0xADEBDDD46D33FC2CULL, 0xB6CF86EC8B38C08FULL, 0x895588551DF88288ULL, 
            0x0F1A690EBA9A2EE3ULL, 0x59CC646759EB9B3DULL, 0x3F11C05C97B8FA14ULL, 0x126F06EA0023B646ULL, 
            0x666FF399A02D0361ULL, 0x2970E7EE391815C9ULL, 0x5B40F85B6F1DA581ULL, 0x70FC854A14BEC581ULL, 
            0xAB1B26DE27C3FC3EULL, 0x1B25D4DB96928F3DULL, 0xD2227C320E700477ULL, 0xFB762B69D449453DULL
        },
        {
            0xBA76738F31E8793CULL, 0x6841B908493F7B30ULL, 0xCF25A51D35A9D3E3ULL, 0xFEC5A15C5473B8A6ULL, 
            0xE456D4E869B12217ULL, 0x559953A24B604B03ULL, 0xB123DCC7BBCA5195ULL, 0x90C80ECD78179AFAULL, 
            0xBC893D8E1A6149C0ULL, 0x06B02CB2BCDFB822ULL, 0xB49EBA1AB90E8FF0ULL, 0xA7DACBD6F4E7B8BDULL, 
            0x56302C8670ECEBF3ULL, 0xBD0C5BC7337967B2ULL, 0xC0DED0AFCC56F710ULL, 0x90C87438E2FFA837ULL, 
            0xF16AEE20D8CBE265ULL, 0xB555FFA1E256B15EULL, 0x0A92F8B80CF65C7DULL, 0xDAF188D8F72B2F95ULL, 
            0xDC1B7B5C043EC9FFULL, 0x94711E7924F3C063ULL, 0xFBC00BE0810DA5E0ULL, 0x785E12C2BE74977EULL, 
            0xD05443DB397655B5ULL, 0xBEBFDFFE92E432BCULL, 0xFB04E8A45F1F36CAULL, 0x7BA31319FFE7402AULL, 
            0x600AC2FCC4DC7993ULL, 0x6B416F9D67BCBC93ULL, 0x3FAFE6392728D06DULL, 0x4EE76D1B21D78668ULL
        },
        {
            0xA528053AABF6DA65ULL, 0xEFA8375943D1BB0BULL, 0x7163E2CBD0B229EFULL, 0x3085EFBCD4DAF42CULL, 
            0x7FD540588B3C0BB2ULL, 0x30A6C36494F95CECULL, 0x33757B0B7FF3CC55ULL, 0x1D74F0A95CD41C28ULL, 
            0x7D604552BE4DD81FULL, 0x1F8144673D93EC42ULL, 0x509FE734EA517658ULL, 0x1A473FB1E8AC7CC6ULL, 
            0x43A929CAFF11698FULL, 0x351C9BBF2365D2A0ULL, 0x6857565B81C0A4C9ULL, 0x692AF8E915E4C4EBULL, 
            0x6CCF08D3F0522B9BULL, 0x033806434728FABFULL, 0x497D6217424D619DULL, 0x6FB15F8F44412608ULL, 
            0xF33D3C13A8052B4FULL, 0x0EBE4E817B4A5DF1ULL, 0x17073290A88936BDULL, 0xCA395777D4CB3AFCULL, 
            0x5C312E901C245099ULL, 0xBF79BDF7811CA18EULL, 0xBC72D95C94647BEEULL, 0x79E8FDA98E44D936ULL, 
            0x1487C5C299308D79ULL, 0xDD8A48DDCE5A62DEULL, 0x45A289C06B41D3F7ULL, 0xE7035AFAEDC43C62ULL
        },
        {
            0xFA1FF6E2D657B27CULL, 0x91067AD999C551B5ULL, 0x197072BB7D2E27C5ULL, 0x606C80058B077ABDULL, 
            0xA3635AC005D84E67ULL, 0xF975C75AB7E2DF98ULL, 0xC6674692BE0A75F2ULL, 0x10EE8FDB326EFBD4ULL, 
            0xC07A67A148D2C3AFULL, 0xDFC27D916D9D09D0ULL, 0xE6779429D1FE2219ULL, 0x735FE312BA8BF0AEULL, 
            0xC26A90F80DE4E7A9ULL, 0x6DFEC318692CDB3BULL, 0xCEED7EFB0D7F14E1ULL, 0x5AD20B7C8D23AA30ULL, 
            0x2FFE7D791C4A5119ULL, 0x405D1F7C2A8E5D8FULL, 0x2671AF8CE3A46C3FULL, 0x26FED6188899EA17ULL, 
            0xFA02F31F5F7B1BEEULL, 0xAAAF71F13FFF6B85ULL, 0x76427EA6F2442388ULL, 0x1F4A7598D7873B65ULL, 
            0xB2FB6D43EA76D62CULL, 0x2531E57A93813175ULL, 0x1217671A1997BEFDULL, 0x322BD82A81155158ULL, 
            0xBF6E5C3B2E97D150ULL, 0xEE31CF715168B24FULL, 0xE12F0D6ABC0BA2E0ULL, 0xEB2428D58DC2B510ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseEConstants = {
    0x4F29E4371700FB56ULL,
    0x64619D5290B02B1CULL,
    0x68A133144B3A8573ULL,
    0x4F29E4371700FB56ULL,
    0x64619D5290B02B1CULL,
    0x68A133144B3A8573ULL,
    0x966CAB7FBE8594A3ULL,
    0xCE381A498DC842CBULL,
    0xD6,
    0x42,
    0x0C,
    0xF8,
    0xDD,
    0xE5,
    0xF0,
    0x64
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseFSalts = {
    {
        {
            0x3285DAFE0B0FA60BULL, 0x1585BF346AD59675ULL, 0xBDC95958D32A59EEULL, 0x0BB7084F6AA4FDA8ULL, 
            0x4CA7A8E67CDF762AULL, 0x9031E7089E25C9E3ULL, 0x1EFBBDB5F64F6A44ULL, 0xAF40E9CB6C1B1B5BULL, 
            0xF005F2D6126858C0ULL, 0x442F20C940E11763ULL, 0x3AA88328485E0127ULL, 0x30BD2B29DED43121ULL, 
            0x883EE3FE0AE293EBULL, 0xF947686BDD19D621ULL, 0xB02A7C23B41FB441ULL, 0xC1E32EDE886B21A5ULL, 
            0xC635C8333BF4A9A2ULL, 0x239CEC01D806C3DAULL, 0x669F9C760F54D052ULL, 0x1212333AC2B0C279ULL, 
            0x3D10EB0BEF03051BULL, 0xE2314ABC71AEE6D9ULL, 0xA799270234DEAD04ULL, 0xD8B23396473B976CULL, 
            0x3038C55E28B87E51ULL, 0xCB1E80268FD7D87DULL, 0x6BD2789DB0BBD528ULL, 0x6F9EC1C7BF38B089ULL, 
            0x46AD7EA1C70D8DE4ULL, 0xBA72C321D4086647ULL, 0x7BA405D01A3860EAULL, 0x3062C4FB499C4662ULL
        },
        {
            0x8661AA79D169A202ULL, 0xAE7E924D54F29640ULL, 0xF92E7069500574F3ULL, 0xE96058F4ECE209B7ULL, 
            0x7F1FD8381E9F98CBULL, 0xC89EFC708D261F3FULL, 0x8A2020B64A64B03BULL, 0xA51740541A376921ULL, 
            0xC28525DD7357D590ULL, 0x12D440349A5BD380ULL, 0xD688FAAB5EF1153FULL, 0x3ABCEC1472FBBF13ULL, 
            0x43F4BCB747459FE3ULL, 0x4917695E5D4A661BULL, 0x628CBAFD522CF414ULL, 0x12EF7838A36E1954ULL, 
            0xEEA344A55033C034ULL, 0xD306D17C47657C5FULL, 0xA227458F7FDD8243ULL, 0xB700AAD122DBBF02ULL, 
            0xB8EDA20374B9E7FAULL, 0x4120C5AE0468B1FBULL, 0x7FC634111CB882C5ULL, 0xB775F3E8E84B6D7AULL, 
            0x6B75819EE4949759ULL, 0xEB5A712B53FADF0EULL, 0x2FCD358DCC72F725ULL, 0x29DE44AADD5D4F7CULL, 
            0x7425A47B6A043DD0ULL, 0xB9C14EA25506AAA2ULL, 0xBB5DA3B999A09EF9ULL, 0x76F75A5143315375ULL
        },
        {
            0x8999F3CC1080A8B6ULL, 0xD97FAFC6E06D30DCULL, 0xABA43828205B8AA9ULL, 0x5DEBE866BAADB03AULL, 
            0x0512D5C754E71CC6ULL, 0x1A0F12D5A907800FULL, 0x6CFF2D159B892E73ULL, 0xEBFEC1E4C32726DAULL, 
            0xBC074195C457F522ULL, 0xB20C5180F11D0880ULL, 0x65BE66A17468D5C4ULL, 0x81811499A5B0BCF5ULL, 
            0xBA5FE3CF4DFBB738ULL, 0x7CA6B373E9B8694BULL, 0x83F77BDFAD28CE35ULL, 0x591F9707F7567356ULL, 
            0x5E41AE3C4523B0FAULL, 0x5A196C7E62A753D9ULL, 0x593D1BB0B7D8DF4AULL, 0xBAFEC418FA289C3DULL, 
            0x36C83A8D05E6FCF2ULL, 0xBDC166A858F1002AULL, 0x83F0A2C19EE9C837ULL, 0x908D852A0CDE227EULL, 
            0xDE3F5F2F834163CFULL, 0x4AC4675B83A2D745ULL, 0xBF7773AA35F46C5BULL, 0xA6B26A7904E30610ULL, 
            0x0C8FC5C04FF157D2ULL, 0x6485B911F1743FFCULL, 0x576723C85DFB87B9ULL, 0x39CD3942D75948FBULL
        },
        {
            0x3DCDCFEAD75D1651ULL, 0x5F6B843F9715031BULL, 0xCA38FB7F998CC422ULL, 0x1287529C706E9EF1ULL, 
            0xD91CF801AE5FA759ULL, 0xEAFECB025C04D97DULL, 0xDFD9DAA00382175AULL, 0x89886A85705F3BAAULL, 
            0x8A8BEE9F89048B38ULL, 0x0BAF305F4538B0E9ULL, 0x1FE521C0253832FAULL, 0xB2A2A54F8BA9F83EULL, 
            0x3780429EACF145CDULL, 0xCC657A34B7EB6F72ULL, 0x30423597462E23DCULL, 0x14CD27760CFB0DECULL, 
            0xBC582DB792BDF313ULL, 0x4B8725C7325344ADULL, 0x83D08A9696178A79ULL, 0x0ACAB1FE956D8147ULL, 
            0x151E60BC2EF5C4DFULL, 0x6413111FCF602420ULL, 0x8569906A975B038FULL, 0xE4C617AB8BFCA791ULL, 
            0xDC1C8EA85469C5A6ULL, 0xDBEC2A6E5CB4BC4FULL, 0x79DE4AC807CA5CC3ULL, 0x5C746DA8A7B34A06ULL, 
            0x595F7B5C779EC985ULL, 0x330CB8E471E13BA4ULL, 0xAE2BC9DB3CB141CCULL, 0x291EA72D9CA5D921ULL
        },
        {
            0x4B871EDA219BD58EULL, 0x6A155E5FFE221F65ULL, 0x71AA3AD0CF5D7E23ULL, 0xA9B192830972A449ULL, 
            0xD96040DB1483FED2ULL, 0x51A1844EE31614AEULL, 0x5864FEEE74C9EC54ULL, 0x52FFE84BE4065C17ULL, 
            0x28EA7BB5738EB23BULL, 0x8B7B3CF15FC6836DULL, 0xDE9D6FF9033061B1ULL, 0x565B6CDAACD9EC95ULL, 
            0x0B1F22649ED57318ULL, 0xB9F326FA6782DF1FULL, 0xD12A401204C59DC3ULL, 0x09B34EFFF7CB0965ULL, 
            0xAF4587BFCAB93C7AULL, 0x44618099EDCF6103ULL, 0x3203A6E89CEFF798ULL, 0xF2489C97552D48C2ULL, 
            0x22B1D96793DD3C55ULL, 0xAB799063508DB8C2ULL, 0x3BCC9A86195740A1ULL, 0xA424326611648F68ULL, 
            0x6F772B2E44B1D1C3ULL, 0x58A46F9561343CCBULL, 0x20016F67EFC209EDULL, 0x83F412188BA61591ULL, 
            0x2F96314559C0F176ULL, 0x25A4FCDE8F4572A4ULL, 0xA08856C6EA1CC15EULL, 0x8631E69240DEFD4DULL
        },
        {
            0xC3D6B59DC5409BCAULL, 0x31C941B3BD82979FULL, 0x1041DD56CF8B7FDDULL, 0x2E327050BC837CDFULL, 
            0x565C8B1D64804FF9ULL, 0xDAB83158C595D93EULL, 0xD2FAE0A6E1D2A4CBULL, 0xFEA90D264939D220ULL, 
            0x986C252895008C7EULL, 0xDB90781156764225ULL, 0xA5207CCBEC9CAA69ULL, 0x87A7CE13C95554BDULL, 
            0xD3F22546AF4BE492ULL, 0xE32D0A7A8FC1E299ULL, 0xE4A02C0D424AD465ULL, 0x689BB6160511C694ULL, 
            0xDED1485B0793F817ULL, 0x32ACCE7D2C2CBD80ULL, 0xD1C4B441799F2EA7ULL, 0xFEE25761C2E07F86ULL, 
            0xD7F5BB0EFCF70A87ULL, 0x9186EA00391067DDULL, 0xE4BF4EF2D2453CD9ULL, 0x4C30DD93CA487598ULL, 
            0x07A3660B5FB7261AULL, 0x46664858660F2E92ULL, 0x6BF1A7EE791BD635ULL, 0x8B6734C12BCAECDEULL, 
            0xF20D87D386C082C6ULL, 0xAD4448AFA367B761ULL, 0xCAA1533FE5680CE0ULL, 0xD1F3603743E5D84EULL
        }
    },
    {
        {
            0x80E338C9A3AF6092ULL, 0x52D2833EB9A7A1C8ULL, 0xBDEAE3C27017D0B5ULL, 0xCB06323E4FA53488ULL, 
            0xD831AACA469D77F3ULL, 0xFAB9BC7EF3586509ULL, 0x641DF91F287BD3EBULL, 0x43D7C695A86136FAULL, 
            0x10C1C1F626675ECEULL, 0x6ED825BDCA9EE1AEULL, 0xEFF21DE6A8FC0BC6ULL, 0x5F475809B61D4C5AULL, 
            0x6EE91C8E768C7B43ULL, 0x811E0CFCE8C8F0BEULL, 0x223471D8DF31C66BULL, 0xC26E81153AB1EACBULL, 
            0x001ACC14EFA7DF4CULL, 0x3C4082B7C4618D1DULL, 0x8B9EF54D6B4031F6ULL, 0x9E00ED58321DA4EBULL, 
            0xAB6D1996D1759D6FULL, 0x8B2FA76396F149F3ULL, 0x530BE690AB7EEDE6ULL, 0x7953EF75452FCE5CULL, 
            0x01A8612423F959D0ULL, 0x2F1C92D186AAD3BBULL, 0x054D115426B02B25ULL, 0xAADF6573078BD564ULL, 
            0x8E0134D58D0B7786ULL, 0xB787F0E4A6002E42ULL, 0x9B47CBF83738239BULL, 0x0DA6D07292735155ULL
        },
        {
            0x334656B64742A7C0ULL, 0x67AFF69A9D0743C3ULL, 0x96C07198B010717DULL, 0x56A6E0B2480D01EEULL, 
            0x450C1D77BA3E96D8ULL, 0x57227D5AD24917EEULL, 0x0887762717BA4F92ULL, 0x1005A68E68957DF4ULL, 
            0x3339685501605A3DULL, 0x8559B6A112D1A9A3ULL, 0x192F09F885191D02ULL, 0xA6C12DF3BFEFC546ULL, 
            0xCE7CC0DE5A704DEEULL, 0x1DDE468EE3E33732ULL, 0xF38A87EA73A4D4A2ULL, 0xFEB4AC1A8E9483E0ULL, 
            0x9DDC90910BA32C36ULL, 0x36335EE6988BE602ULL, 0x49DA0C65C551F9E6ULL, 0x017FDF99640F1723ULL, 
            0x7C3BDF8BF2ABA371ULL, 0x3D10B52746160BD9ULL, 0xA8728B1A48B9BB0FULL, 0x87EFFAD7112EED69ULL, 
            0xF4A2090A0D0EA716ULL, 0xC455885B1312D737ULL, 0x7117599720FFAFFEULL, 0x2596D987ADA424E3ULL, 
            0x4DA325F8A18283FDULL, 0x6A7A6CF187B9A59CULL, 0x7464DD51F7726569ULL, 0x53407CCF871AC019ULL
        },
        {
            0x4F8DE3660E8364FEULL, 0x47EC419B6E42C205ULL, 0xEA6317DA70B30E7FULL, 0xC9AD0D5ED8502A85ULL, 
            0x8D05FD3A06D4BE66ULL, 0xC7B163E543135C8DULL, 0xAA21A617C885452AULL, 0xB7F942761BB801A0ULL, 
            0x31196691254726CEULL, 0x27D85DCB441F02CBULL, 0xFF8F6952A5243761ULL, 0x48F8450D0A07D22EULL, 
            0x9A54C3AA01D6AA68ULL, 0x6900B989140256C1ULL, 0x5F372E882373DABFULL, 0x86431C01552A7641ULL, 
            0x1EAD7D63FBE0124AULL, 0xFC909FC7E55A3C73ULL, 0x0842B92480389CB2ULL, 0x71F87A0FFBC4405BULL, 
            0xFB7D21DD7CE14698ULL, 0x2F494799F68C4CA7ULL, 0x0CBC7D935AA7DE8FULL, 0xF02E123F05389904ULL, 
            0x9E2E6384915D4198ULL, 0xCCE3DC1621BC9D44ULL, 0xBF4FB4B2A8E13A34ULL, 0xBED0888F00CF479BULL, 
            0xD86ED0152AC78488ULL, 0x5CDAB711055803E4ULL, 0x3956D405141B6CE6ULL, 0xF199251C352608D5ULL
        },
        {
            0x996CD4BCF59ADC7FULL, 0xA7BAC6D934E21F55ULL, 0x77CA4537212E99E2ULL, 0x6C137B5DCACFD347ULL, 
            0x6444FE71F3EF433EULL, 0x0021A918EC4E32A7ULL, 0x4AD20A02568D63B9ULL, 0x29DCAD32B8A81644ULL, 
            0x26A828D527049FD4ULL, 0x0616E734629D20AFULL, 0xEF8B7AA69B5EB2D9ULL, 0x901402D7ABE69637ULL, 
            0x796E1B1D6D986D56ULL, 0x1769FB758EB95D3FULL, 0x847970FDB23C5F7DULL, 0x429DCE0E06CD62F0ULL, 
            0x39BC69C499E556F0ULL, 0xDD1C1333A19AC54DULL, 0xBF0FA6FF24B63D0CULL, 0x2B82A6B03DC1C967ULL, 
            0x4FBEA1EE9494A131ULL, 0x1DD59048138424AEULL, 0x75C37AB8B507153EULL, 0xA209C8BC7400C262ULL, 
            0xE94A29382B886552ULL, 0x12DD568C21668A19ULL, 0x743733B8E79277E7ULL, 0x6C1313BE222502E3ULL, 
            0x891C2F7EF3118341ULL, 0x2FC2E110D8B3B067ULL, 0x304CFCE0BB2A714AULL, 0xE264EDB898922681ULL
        },
        {
            0x9A3D561D1CD4C528ULL, 0xF9D8E2165801FD07ULL, 0xF2B64F6701F4A9B7ULL, 0xC04B235640B76669ULL, 
            0xA23C9200F7C94885ULL, 0x5C9FC11DCE4BDB34ULL, 0x466DA44C0F745613ULL, 0x874B850F9B205E79ULL, 
            0x57C65FFE2EA16FDDULL, 0x8560EE7DBE54467EULL, 0x2697F433E19BA6BDULL, 0x00E1777B0DBEB420ULL, 
            0x3DDC2E3622BB8E65ULL, 0xCD1589AC49F48E88ULL, 0xCF913791F35A05CFULL, 0xDB323010BCA6EBDBULL, 
            0xD51913E84F72B347ULL, 0x4F7359AAD6E551E1ULL, 0x53F33AC10D8DC849ULL, 0xF603C4DC439F48DCULL, 
            0x6BD3E0286EE6CC65ULL, 0x5AC20797E1BA68A8ULL, 0xCFDE2CCE499862F0ULL, 0xA2A03A80FC87F2D3ULL, 
            0x547465B13A5305ECULL, 0xE99B1735195631C7ULL, 0xC018ACAE0A5A025AULL, 0x1C13173E18B32137ULL, 
            0xCFF52FC40166E1ABULL, 0xAB5957A1CEA6DEF1ULL, 0x2D6B459F3218A6FBULL, 0x39A8D6F81A8D5DDBULL
        },
        {
            0xF240701F794136A0ULL, 0x1B2C7C2C1A339C90ULL, 0x695B7C6D95160A89ULL, 0xC7D3D9DCD53D0E2BULL, 
            0x024B94529DEE1700ULL, 0xA94995D577D38A3DULL, 0x30B26232C5657385ULL, 0x95611EA15CBF8209ULL, 
            0xF551B8F05ED042B1ULL, 0xDECF2C60554CA873ULL, 0xA60561991ACA518DULL, 0x0A00CB0DF79188A3ULL, 
            0x2AAAF7FA631CBA13ULL, 0x0D861A04824E9CDAULL, 0xA58E1D6047704626ULL, 0xBDCDAD79F1934D11ULL, 
            0xBF2B318C198F6039ULL, 0x3FA69E6BE36D41F8ULL, 0x185FEAF3509608F4ULL, 0x6B896E2AED07CF8CULL, 
            0x8B5C613108194728ULL, 0x8274C8A0200B6436ULL, 0xF7C8F13803F0A5A4ULL, 0xBE9F195DF6CC48D2ULL, 
            0x29C43E7C57AD354FULL, 0x922D5506A87B9485ULL, 0x5B014A6965F63970ULL, 0xF834EF7521EB83ECULL, 
            0x042CC7CB6DBE5D95ULL, 0xE00A85F608185902ULL, 0x531D0F4A89925CF9ULL, 0xDB65FDE84FAE82B0ULL
        }
    },
    {
        {
            0x681A026C5C3645A1ULL, 0xB9E7D07888CAA1D8ULL, 0xFC46C41CB538BC1DULL, 0xAD71863231D63C51ULL, 
            0x6BE9D52C70FEDCDAULL, 0x8DE849C86ECBC9BCULL, 0x6739C31217353DFBULL, 0xD19D4E6CD7552B63ULL, 
            0x344410DB6B469418ULL, 0x4C53564875D11637ULL, 0x4380259685D3D36DULL, 0x34B8EBE046F64788ULL, 
            0xE48B6E433D8F702AULL, 0xE0A74D6E8C1A0CDCULL, 0x1BE5FB6DEC792154ULL, 0x16B88A4D151EA698ULL, 
            0x1A4A01AAECE88DAAULL, 0x83011D4C4909801FULL, 0xB552D81EA96A6D55ULL, 0x7B4DF676177589C3ULL, 
            0x179271A4F4311B50ULL, 0x4C1E411AC7E16327ULL, 0x982C50996D9B72A3ULL, 0xFB9EA2CC208CD778ULL, 
            0x9B5A41E5F5EE4E1CULL, 0xE74D3FA4A6426C51ULL, 0x711EBF2C7FFFA5F2ULL, 0x7C56F67928863331ULL, 
            0x8146B05F2F3A939BULL, 0xA58CDDEEF5C910E3ULL, 0x105073286BDB6EDBULL, 0x215A4D3C0FA731AAULL
        },
        {
            0x4C2245F5B88FAD44ULL, 0x21A02F0FD8D79169ULL, 0x747E07C8ACA1B691ULL, 0xF41DC4A7B04BEB29ULL, 
            0x32C2A36F77DF4696ULL, 0x7CD69B488E6D2BF7ULL, 0xF420F4A719974079ULL, 0x4FABF77EDEA9D1E5ULL, 
            0x206F47CFBDBC7EB0ULL, 0x81744C568605896CULL, 0x273F220D520D0D7EULL, 0x4CADF80B184E1158ULL, 
            0x396EA19B18C573FBULL, 0xF2D44B51B2D97360ULL, 0xA0C48E5382823909ULL, 0x89D8AA0D855F53C2ULL, 
            0x374A06D902D2171BULL, 0x6B4C75C7C891394EULL, 0x7AB8F552431C2AF8ULL, 0xB8D1AD3D7B9FBBF9ULL, 
            0x9A0436BC70816139ULL, 0x3FB1DDBACC1A5F3FULL, 0x97870E03117F63F5ULL, 0x9E881595B5AD2A87ULL, 
            0xC37908FCEA8B8EC8ULL, 0xBCF0BC69F3E9321CULL, 0xD3C6F51F6F9153E1ULL, 0xD79542EBBD295B03ULL, 
            0x0E5990816F21DB18ULL, 0xF8E73486F4C4D07FULL, 0x9DE1E1D024626FDFULL, 0x9E1B1DA675F29E90ULL
        },
        {
            0x393E1BFE68F6FAC7ULL, 0xD2F0E28EF2C198A0ULL, 0x20476CB85DAE0904ULL, 0xB2F8AA11DE602A33ULL, 
            0x7BFD9D6B9921B5F7ULL, 0x148A739D40572C84ULL, 0x09186B341F48EEF3ULL, 0xE1600E24DC501EB9ULL, 
            0x1B3F925C160A7612ULL, 0xAC7263CE591315D0ULL, 0x4AD2676B773F94F3ULL, 0x359B8587E029F033ULL, 
            0xB52E19EB183D8624ULL, 0x7F6DBE24EB4FC941ULL, 0x28116FBD78D8A8F5ULL, 0xE7710207C774E6D6ULL, 
            0x8D5D077DF00604C2ULL, 0x53E4BF5BD5ED0241ULL, 0x66915D0F07F0F1BEULL, 0x26B9004FCD60A1E5ULL, 
            0x0691CFEB714F764DULL, 0x6853169122C65B1DULL, 0x826483DB52EE61CEULL, 0xDEF594DF2DF815C8ULL, 
            0x533DE3BAA85AEFA0ULL, 0x5A77B27F8E351864ULL, 0x39D5806BC17AB063ULL, 0x3540F6AEE54F4026ULL, 
            0x32C1D046B45D2E24ULL, 0x6523F298A2195538ULL, 0x8F93E5933177DDA4ULL, 0x570FB36591A6CFA9ULL
        },
        {
            0x8A6B056B6531D085ULL, 0xB6457E0D9353DD1FULL, 0x268F89A44A10696CULL, 0x15EC85BF502D666FULL, 
            0x98FEED73F80AF41BULL, 0xE500599E2A2F5DE3ULL, 0x5A63C4F3FB38F7B9ULL, 0xB6920ABE936947C4ULL, 
            0x3D9927941C54114EULL, 0xF50B1771CDB64545ULL, 0x010F51B45EF4CADCULL, 0x888BC21B50C2D1E5ULL, 
            0x70B2E63286A98383ULL, 0x783CD3EE2D83C327ULL, 0x11A3F9185526371BULL, 0xC80EBAA6FFD4B42FULL, 
            0xB597A5087F7888EAULL, 0x64FC7B017CFA79E3ULL, 0x9DFE9B4B76821ECBULL, 0x7134DE9B3C22905EULL, 
            0xDD9023A5BDED835FULL, 0x95956795DE4A6DD2ULL, 0x915D17A1233B3C2AULL, 0x7CF910E5FEBE9EFAULL, 
            0x14C66FE7F7FEF2C8ULL, 0x0A2CE03E65F21645ULL, 0xBB3B740789456838ULL, 0xEA3932DEDE17397DULL, 
            0x849B3245ED220CBBULL, 0xCD50B08A51774DD0ULL, 0x8042E0D8DE4D673CULL, 0x32026409C74C49F3ULL
        },
        {
            0x0EDDA708A3691AA0ULL, 0x809C98FD50F63E7EULL, 0x2A757C93D2C2068CULL, 0xFA60CC67CC7B4B18ULL, 
            0x7522318B3550FE69ULL, 0x2E542B4BB2101186ULL, 0x00B61333C2E39610ULL, 0x799FE4947D09A46CULL, 
            0x37E096DC9E7F9C24ULL, 0xF5B076AED58544C5ULL, 0x34896DC526CB6D4BULL, 0x0F5BE6EBD4244FD9ULL, 
            0x9AED41135D2F6EAFULL, 0xABCA0A94EE3494EDULL, 0x971FB30B8858B57FULL, 0x62938F51F08C9AF1ULL, 
            0x8E937A6208BB0E56ULL, 0xD5D1EAF057C84CF7ULL, 0x53C3E0268B7E89B1ULL, 0xDC4EEF8E032DA11FULL, 
            0x3DD1D5296E93A49BULL, 0x74F6E7C0702D2ABFULL, 0xE8E1ECEAF6FE2C32ULL, 0x649F0138EFDD4139ULL, 
            0x1FC495535E29A917ULL, 0x24D7BEE85E3CEC86ULL, 0xE77EE520E1E05DFFULL, 0xFFC4D15E4A144A48ULL, 
            0x9573479BB973AF8CULL, 0x689F4988D4230941ULL, 0x12EB4CE1C0854325ULL, 0x3B5EE45ED34323B5ULL
        },
        {
            0x8B91EEC1A771185DULL, 0xD6F0B2CA01970613ULL, 0xAE63C9676CE3842AULL, 0x498509B1F2CE2B61ULL, 
            0x0E596613B68DA45CULL, 0x32022E972AB15200ULL, 0x9BA2AE1C86222C42ULL, 0xB5688A0C0BBB752AULL, 
            0xAD4322F60AE1ED78ULL, 0x0070355395E164C4ULL, 0xBFC0ABCE3A784F85ULL, 0xAF034656947C6D97ULL, 
            0x1E4EDFABFA6FE7D6ULL, 0xB76351086445B544ULL, 0xEBC6896D8A98703CULL, 0xF108865B0678AB33ULL, 
            0x45A24E323DEBE03CULL, 0x4019C02B7473EC44ULL, 0x10BD6BEDDFDEDBD4ULL, 0xAC682BFA2DE55D22ULL, 
            0x6A1441DC7716E5A5ULL, 0x19E3A328A9989409ULL, 0x627236A07BBE9C1EULL, 0x6780727994DC232DULL, 
            0x2C94B01089A5C1FEULL, 0x766F8578BE8EFD07ULL, 0x00DE1D9824F2F12EULL, 0x674FF57FBF63BD4EULL, 
            0x718A015A99AEE1A9ULL, 0xE68E46366D83B29BULL, 0xF9F9F77601072D45ULL, 0xBDCD3DA5DB41A4EBULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseFConstants = {
    0xAA96857182872D76ULL,
    0xFFA848F6F490E9E8ULL,
    0x2E5FADD9023DF511ULL,
    0xAA96857182872D76ULL,
    0xFFA848F6F490E9E8ULL,
    0x2E5FADD9023DF511ULL,
    0x5080DDAB4B41AE63ULL,
    0xB6EA73E36CF2F8A0ULL,
    0x67,
    0x68,
    0x30,
    0x33,
    0xFD,
    0x5E,
    0x43,
    0xA9
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseGSalts = {
    {
        {
            0xBF4B7A9321F13CDEULL, 0x3A09EDD190347A55ULL, 0x17B2E0ACD8C556E3ULL, 0xE34BB2191E4BE9CEULL, 
            0x8B5A8F57E950FBEDULL, 0xA86A09389E60C601ULL, 0xB25A12598C29DABEULL, 0x2EF623592C9E7030ULL, 
            0x010F0D110CF44B7BULL, 0x23729A4E2A179931ULL, 0xAED3909B54079DAFULL, 0x94FDED3AAFC2C6CCULL, 
            0x82C5EBC682D85888ULL, 0xA41D8648D96F19BEULL, 0x4FAD565ECF5CAEACULL, 0x2B07B919803966B2ULL, 
            0x716AE1FD3AC11F7BULL, 0xF11FD15EA861340EULL, 0x649E153A22FFC3A6ULL, 0x543E2D02AC65A4BFULL, 
            0x0C379EC61DE42EA5ULL, 0x1462FDE589F92B9CULL, 0xD90C2FCAF3AE57A9ULL, 0x50E89D2A0AE44444ULL, 
            0xA8EFC13D8780EE5DULL, 0x3DC19695F1F91779ULL, 0xEB2B14329D2F96A9ULL, 0x5F7930773B9841C2ULL, 
            0xF7848C43154A4AB9ULL, 0xD3DC40833F680E64ULL, 0xFD68EBE71AEEACBEULL, 0xC6A718096AFD6508ULL
        },
        {
            0xCCE895B79BDF21AAULL, 0x527B18B9D6562A1AULL, 0x33F436A3EA6D9C85ULL, 0xB935C8B6A356EB50ULL, 
            0xBD609C25B238BC7EULL, 0xAAAA35B80CDBD4A3ULL, 0x54193739F604A019ULL, 0x1A2A76F83691B35FULL, 
            0x5791CE055D543DD8ULL, 0x84B665419C173CEEULL, 0xC3B390529F62A8D6ULL, 0x251ADF5A6B541F7EULL, 
            0x39E5C0195067C0CEULL, 0xA4BB040240E380D1ULL, 0x491F376FA7913293ULL, 0x49FCE873E6F27177ULL, 
            0x9CA85CDD955BC6FBULL, 0x6087584CB7C268CEULL, 0x29DF27538ED32EEAULL, 0x446A50ED09AD538DULL, 
            0xFCDEB24A4E5298E4ULL, 0x8B6DC74AC63F9D7BULL, 0x65903C213DCF71ACULL, 0x7AA8BCFC2411CA8FULL, 
            0xF73472EB263DFA47ULL, 0xE138D3D808025962ULL, 0x48C1DDF69EA6D0B6ULL, 0x93C7671012BDB973ULL, 
            0xC9A6447F6EEB0862ULL, 0xB990E24D70583C7AULL, 0x533D5891C17F9F2CULL, 0x497E7CB8C092FE79ULL
        },
        {
            0x1FF0B2C9B0B25997ULL, 0xBD3CF59520370C01ULL, 0x156D3E03A94180D7ULL, 0xE456FE5313F3AB68ULL, 
            0x58D379F5D3423426ULL, 0x58737CC7EF650142ULL, 0x8B917019F62DA84DULL, 0x27CF2602FD0DC8D3ULL, 
            0x4A8ADEB0C90C6FEDULL, 0x54B3D87B65254A57ULL, 0x6AB3919C304D17CEULL, 0x9F0F384A513ED265ULL, 
            0x215E332B445AB3BBULL, 0x9D10BAA736F86447ULL, 0xE61DBEF24D9B6111ULL, 0x441BCC5EB3A5B9C3ULL, 
            0x595E164978715A62ULL, 0xBEB42E9F141894E7ULL, 0x3F670CDE76DFCF87ULL, 0xE84E8CDBB17EFBA2ULL, 
            0x945EC1AA6EF34F1AULL, 0xDC62FD9075DEF381ULL, 0x7A4C466AB87B9C9DULL, 0x165CDD0D8317D497ULL, 
            0xF7CE9A55D4CB30D2ULL, 0xCDC072F9BCAA6C62ULL, 0x4808D39FA6A279CBULL, 0xF4C69CD1A8858E06ULL, 
            0x83D0A2D3DD980BBDULL, 0x991DE5A26DEC8095ULL, 0x09420C039AC89C55ULL, 0x73E756D38F2F0B56ULL
        },
        {
            0x39B3622E7D21F550ULL, 0xA349410693501BEAULL, 0x726097CE543D4D4FULL, 0x10F37377B31F2191ULL, 
            0x33407E77576CAB89ULL, 0x9DB38304BDE07CA0ULL, 0x7E214ACC7515F12DULL, 0xB343049AAAA1983CULL, 
            0x2D7FC4A4205733B1ULL, 0x03BECFB7A8D5C384ULL, 0xA7A889A122206129ULL, 0x35E3B5D9110EC737ULL, 
            0xB1D13D4EBE051250ULL, 0x1492323A750DC981ULL, 0x1C69F082F9BEBC8DULL, 0xF767932AB651B461ULL, 
            0xA410200AC0FB32F6ULL, 0xFC4FC8A4946A280BULL, 0x09465600494AA00FULL, 0xAA8DD7A6BFFA48F5ULL, 
            0xE505AB87EDDBB359ULL, 0x239582E1A0E44753ULL, 0xCA9FA0B2F30C2D5CULL, 0xE99D2E96BA03E94DULL, 
            0x25B141E6CCBED46CULL, 0xB0F0FD77ECE553DCULL, 0x73A33086594F6E86ULL, 0x91D8380E506B2CE6ULL, 
            0x2DC3E5732BD40193ULL, 0x58126A3EB66CEFDEULL, 0xE681811F5F866C75ULL, 0x3D262DFE2F733C21ULL
        },
        {
            0x99FFDBE7317A9238ULL, 0x1AAFF097E2494947ULL, 0x76E24D3E8B342AB0ULL, 0x46C0EAF50F51661EULL, 
            0xEF243C9BAB983CF6ULL, 0xFA4BA159D0770DC4ULL, 0x733B609B3C1A915DULL, 0x70710ECF0AB6242EULL, 
            0xB47D307D83FD77CDULL, 0x3ACADF2C1B7EAB79ULL, 0x226071A106C6071EULL, 0x195DB23A04E5755EULL, 
            0x81E9F323816A3981ULL, 0x89650F872F02F8B5ULL, 0x67D3FE4EC071ECABULL, 0x9A02BF24E90775FAULL, 
            0x4C35707329C770E6ULL, 0x8D3AF4A6EDF6C360ULL, 0x307072BD9A902371ULL, 0x7F75A912B8E885DBULL, 
            0x4F3BA1EBA148AC4BULL, 0x85A1787791B2BBECULL, 0xD3B9980023891341ULL, 0xB7F45098B1A77B9EULL, 
            0x61971E8718B02CAAULL, 0x41FC9F59F5B93CB6ULL, 0x0A4BCDF49B1312B3ULL, 0x62502618996722B5ULL, 
            0x75730DCF9E6478D3ULL, 0x4EC66DACAFC54208ULL, 0xFBDCA92A295D0928ULL, 0x237534A167C8420AULL
        },
        {
            0x42F0639AC5A12D09ULL, 0x1803FEAC29C2E891ULL, 0x940EC219942A010EULL, 0xD1D12EFAAB463582ULL, 
            0xC6FE5D1E16BE0FDEULL, 0x7DE904B0752AB606ULL, 0xF572263CEF6D9D7BULL, 0x3EAA431C8E7A1074ULL, 
            0xCAB385A651D069CCULL, 0x1EFBED7122764DCDULL, 0xBF6E3D963A68AFCFULL, 0xBE684B1C5387AC8DULL, 
            0xAFF847D04B2C7CF8ULL, 0x9E9B05EDC3C51508ULL, 0xDD8F272DD52733F0ULL, 0xF28345AE293DFF16ULL, 
            0xABB8E78C4CB77111ULL, 0x45EAA29AB4218D64ULL, 0x0C86BEB1B12CF0DCULL, 0x21E6B4DBB8895334ULL, 
            0x90AD7E5BDF70B2FEULL, 0x1CA73DA94ABAC686ULL, 0x15FFB8B4528C4DDBULL, 0xA0BA897A53264821ULL, 
            0x8ADFD7B8AB3C6302ULL, 0x8B8E35E116A923C4ULL, 0xE71ADDEE348D5715ULL, 0xDEFFE5867D7B3D0CULL, 
            0x3DB5742AC405EA90ULL, 0x1E2D6C3E68CF7603ULL, 0x5820C6985DEA307FULL, 0x30920631430F6621ULL
        }
    },
    {
        {
            0x6620002CF35EA9CAULL, 0xC8FA651E1CB173A4ULL, 0x226C01B64524DF80ULL, 0xE645D85F36EB0951ULL, 
            0x028A6B76096F2CF3ULL, 0x853B4C458E5F9C15ULL, 0xD19C07FF26D66DA6ULL, 0x4BE0B5CC71D7FFADULL, 
            0xDBE07B8F9CC18362ULL, 0xEFFF0B47F4C232E5ULL, 0x2B54185CB53BC201ULL, 0xAC5319FDFB537D6FULL, 
            0x5E40FB937C05DA2DULL, 0xF8B40BA215FCC317ULL, 0xD09A126BBDA9DC8CULL, 0x25D2E227B57E33EAULL, 
            0xA9390286E1577850ULL, 0x93B99758D581C571ULL, 0x723A9DC7FCD3227DULL, 0xAC723731F04832ADULL, 
            0x86590BD1B2BD891DULL, 0x6B54658FB5157292ULL, 0xC48F424CF8E3164CULL, 0xE1946352F60C8177ULL, 
            0x74892AF7AED6B31DULL, 0x95FCDCA8C86B4255ULL, 0x6EFC1C9EB29536C6ULL, 0x89D4A9B1987C0EFAULL, 
            0xF6C39C5C3746D25CULL, 0xD44E57EA7EA81431ULL, 0xDD9A39ECC1FC6F40ULL, 0x3CEE4BDFB86CE3A8ULL
        },
        {
            0xC6D850D5AAE64DF4ULL, 0x83979D7168036652ULL, 0x1E0E123A7AAB980EULL, 0x5AC8AB9C93B1C89BULL, 
            0x3A139FCC7F358EB8ULL, 0x4B581211F60598FCULL, 0xC5D0B583D60CE83EULL, 0x865D7971077E640AULL, 
            0xAF9213B8A98B2439ULL, 0xFE1623577109DEF3ULL, 0xF67CF6481AB51438ULL, 0x08A902F7153100F0ULL, 
            0x81AAC16BD2799010ULL, 0x3BB4C67D232C89D9ULL, 0x0FD31B4508388717ULL, 0x6E9C5CCED6D757FAULL, 
            0x19585AB3D2360E33ULL, 0x8275BD5873165077ULL, 0xFE1C335F09FA1499ULL, 0x7B0FD6E7D2054F6EULL, 
            0xEE3935423BD5F66CULL, 0x7D1406393D56CB9DULL, 0xF2801CFE401BE1ACULL, 0xAF44002E0A5E9F10ULL, 
            0x1C4BB43E151FC52CULL, 0xF352D7E3D249A83DULL, 0x7FF16142EBDD46F8ULL, 0xB96B9B7CC3CC19CBULL, 
            0xA0E1031305CFC8D6ULL, 0x4A34AF3C400A48E7ULL, 0x25FCAC9406A15549ULL, 0xD02853F598F8B5A9ULL
        },
        {
            0x48697D19BD4532F8ULL, 0xE7ADB2C4D72F64B0ULL, 0x189AE951D3D1DFC0ULL, 0x409D1DA525CC7D80ULL, 
            0x002ECD905F69BF15ULL, 0xDB0B15BCDFF006BEULL, 0x392B7C8B11F71F84ULL, 0x2FDAD052F42FEAE3ULL, 
            0xB3EEB408AD4A2864ULL, 0xA4D173CCC4A6B25FULL, 0x225E594C62FE49EBULL, 0x9D31C33BA1981B93ULL, 
            0xB265A564CD6C4F38ULL, 0xA31FC4F76E60F35BULL, 0xBE5295FBD67CE350ULL, 0xEE5825CBFEBEED5EULL, 
            0x4FD4C94BCC41A137ULL, 0x64AC8C7A3F4C2574ULL, 0xF0F06DA79B796858ULL, 0xF5B2474FA7BF7B95ULL, 
            0x5538BE70AFD6CCA3ULL, 0x41C68A17D8DF7EB4ULL, 0xC981B7BEB6884A00ULL, 0xAE9C8AA3EC4F6ED5ULL, 
            0xD609973C53F2C695ULL, 0x243E46BF1A90A464ULL, 0x76DCFF04F61737F4ULL, 0xE75AE12A7B2F8C20ULL, 
            0xABC3837688D877F8ULL, 0xDAA3A72FDEF7C138ULL, 0xD3C1D4311E157B82ULL, 0x8080C7CBA7E34472ULL
        },
        {
            0x219BDEB12229AFF0ULL, 0xE7EFD06189D57320ULL, 0x25C9A028F4516D13ULL, 0x91331EE09A4F85BDULL, 
            0xB2D8CEF4FF1ABBE3ULL, 0x49C33318BE9030B8ULL, 0x7D28EBA2C84B77FCULL, 0x76FB7D145AAFB15AULL, 
            0x1C421AD375D795BDULL, 0xACA06C83CC2D8180ULL, 0x48B6467DC48A53C3ULL, 0x0604497D62BDF650ULL, 
            0x321762C92B39F2D6ULL, 0x9FE436F66A371976ULL, 0xC0BA7F5FAB91F984ULL, 0x5C76678945C7136AULL, 
            0x913B335F89DAFB08ULL, 0x6639DBF56721D13FULL, 0xC3FF0C09BBB30F88ULL, 0x203E6C8EFF10D7CDULL, 
            0x4F46DA7D5A1F5380ULL, 0x296C8F9F3042395FULL, 0x89BDC8EE024A44F5ULL, 0x84E2DB3460EFFA72ULL, 
            0xBEDD6F6274107689ULL, 0x9C41BF96F286B090ULL, 0x5A688EC03FD6537BULL, 0xFEFD619F2A082147ULL, 
            0x499583CBDEA52BFDULL, 0x6C1597792421CACEULL, 0x3B380F06E48FDE8AULL, 0x5FF0097C2FE1AD40ULL
        },
        {
            0x928CD7A207C8DB35ULL, 0x22865ECEAB9692E9ULL, 0x95CFBD0FD981A6F1ULL, 0x02E51FA9925C502BULL, 
            0xCAE1B8D1D14620F8ULL, 0xBB394A1F7C83E298ULL, 0xCBFE84698227F9C4ULL, 0x589DA32BDDFC322EULL, 
            0x9631CA845FC0DBC1ULL, 0x67C6ED21BA2304ADULL, 0x8BE6538993E72EC0ULL, 0x02CDA4E84AF0EB86ULL, 
            0xFAFC36134DAAF68CULL, 0xCF6ABE52C37AABD4ULL, 0x138BDF8CE46F5896ULL, 0xA63306756F03C80FULL, 
            0x9B7C4AC8F016593CULL, 0xAA470E295E241DC2ULL, 0x46C2441D78EE1A34ULL, 0xE060C07E2C8AF23AULL, 
            0x05F5D6757B25A673ULL, 0x51298505CFAB442EULL, 0xF73E1B386BD834FCULL, 0x6D3697A96CC21197ULL, 
            0xDA8A55BAB81A5BA6ULL, 0x4F0E68E58D166C02ULL, 0x6E19C6AC9E65D7D8ULL, 0x6B48556C4F1DB539ULL, 
            0x29161F9E989A6A10ULL, 0x08A3958B5418B75FULL, 0x111B287A0A958627ULL, 0x5EBF903752D19BE9ULL
        },
        {
            0xAC0B96745525BA1BULL, 0x1104EDD669056F5FULL, 0x10AD1E799E9430ADULL, 0xA85798DF62D5ECC5ULL, 
            0xE73C2F005B3A4283ULL, 0xAF408517487C953EULL, 0x0F5890A18C667B48ULL, 0xDA96AE607897E4ECULL, 
            0xED49B43542A76332ULL, 0xEB4CA8CB6080C324ULL, 0x668BB344D17C122BULL, 0xE89CDF6CBF242C7CULL, 
            0x8C720DC912008E48ULL, 0xD5DF55A43005F877ULL, 0x18884A0EFC1CD76FULL, 0xD68628CDDB6BCF09ULL, 
            0xA43061319EB162C7ULL, 0x520291992A95CC61ULL, 0x01CFF700FA0D75F9ULL, 0x0F678EBA5D1C3D8DULL, 
            0x4AE48CBF4CA1FCBFULL, 0x688941224BF6C057ULL, 0x2AD3E2127BC77FF2ULL, 0xC82226DC354DCE72ULL, 
            0xD60F32EADDCCCCEEULL, 0x3E6C4C56586406C3ULL, 0x4215939E72F7C32DULL, 0xE29417C9959156D9ULL, 
            0x6C23652A62866068ULL, 0xE0DAA567E21C334DULL, 0x6826A746C2F825C1ULL, 0x1F4F0EF4C27490F5ULL
        }
    },
    {
        {
            0x0DFE4665A2286EA6ULL, 0x683E41BBD193ECEEULL, 0x84D68BD643678E48ULL, 0x775F6BB87F49B560ULL, 
            0xDD1D3B2A1E4636B5ULL, 0x042ABBAAA64EAABEULL, 0x06F5780E8BE373F5ULL, 0x97E3562883F3B922ULL, 
            0xC5A2E7FA393C2E8EULL, 0x755D3E797E02B6D4ULL, 0xF7CC940E0315E0E6ULL, 0x2F86B8565B1F2236ULL, 
            0x523B093494B12F57ULL, 0xB453DE471464533FULL, 0x7209D3533BAED083ULL, 0xC1A81BCA07FC3267ULL, 
            0x45AA872DDFBDA6F4ULL, 0xFA6DDE7843CE33D3ULL, 0xA0C0940FAAE3CA57ULL, 0x73E8DD6931C650FDULL, 
            0x7E5A98F87230194CULL, 0x0BF68B6220AC9F20ULL, 0xDDDFB6BDA6D58A2FULL, 0x85856B1589E2537FULL, 
            0x3BD0D94C4D3452A0ULL, 0x87693F341974D794ULL, 0x7A807C77275C1B21ULL, 0xB6D86C5803810922ULL, 
            0x0A2F75BD5CAFB90DULL, 0xCF8000A7F2A9530AULL, 0x3391115A69A3B1A5ULL, 0x79D2AEF2E0FF2C3FULL
        },
        {
            0xD3BA1B3C659E06D9ULL, 0xB6024BECCA59530DULL, 0x067405563ACC4D4CULL, 0x0E3EB89E23AC8B40ULL, 
            0x89E0EEEC8E6B7498ULL, 0x4E79BD67B75286D7ULL, 0xE180945B82B45DEBULL, 0xD538E71C056C7822ULL, 
            0x9BFCC9E9F4058047ULL, 0x558ADFC870934E8BULL, 0xED4FC776D10EC773ULL, 0xBCDF9BDACD705192ULL, 
            0xBD4C7D9BF48BB35CULL, 0xC5625D5C0E05AC16ULL, 0xA9551DA735129C4AULL, 0xA421E975CE751358ULL, 
            0x9063C5D4A90873B8ULL, 0x20A46598EAEB6305ULL, 0xB70608C6D1360DF8ULL, 0x93131954610C8A87ULL, 
            0xBCFA259585E7DC69ULL, 0x0FA9480C7A18B01CULL, 0xA79358C7A2C74363ULL, 0xCCB4DE400488C667ULL, 
            0x58E714CABD718ACDULL, 0xD1E87ADA55BF13DBULL, 0xEA1382BFD9CB5040ULL, 0x47EC049F3E4A13D6ULL, 
            0x191687705BB95080ULL, 0x9B9647F57D8AC65BULL, 0x6813B768D0D4DD07ULL, 0xF3BF4E3E728845A7ULL
        },
        {
            0x2AE9E4991BCCFB02ULL, 0x54AB4339E71FA387ULL, 0xF62DEFF645F50EA2ULL, 0x3FB6D753F86AA837ULL, 
            0xDAF790722573E442ULL, 0x38A756FDA6609C78ULL, 0xD70EC0116F26B5C8ULL, 0x952001CA9C11E941ULL, 
            0x29B88D7A25887EC6ULL, 0xA355A34FFEC5B6D6ULL, 0x4A84728055B1DEE1ULL, 0x18E5DC4804853711ULL, 
            0xCE0A7E96B95002D4ULL, 0x0F5591D8FA3BCEE0ULL, 0xC86C9C4C954D25EEULL, 0x228BB13B15101665ULL, 
            0xA2ADA855A045DBD1ULL, 0xB16A0AAF85581283ULL, 0x6A82C628ED47A5B8ULL, 0x39BFEB5BBB765055ULL, 
            0x4DB0371570AFD3B8ULL, 0x3D9E0BD84C00E930ULL, 0x95BC7D1340006B1AULL, 0x186C2EF61B3A38A7ULL, 
            0xFF9E195431129A91ULL, 0x3F96976B06B26A12ULL, 0x8004642831F8C909ULL, 0xB2744D2C499483ADULL, 
            0x5EA4F15A325EC698ULL, 0x43FF43FADF48E346ULL, 0x78DBF2E157EF1392ULL, 0x2169F6C7374275A3ULL
        },
        {
            0xE131D622B94E4B20ULL, 0x32E0FC291023E76AULL, 0x8713B08A7C2236ACULL, 0x6DB35BEA09813724ULL, 
            0xA7E741D20D7EEE8CULL, 0x008AE1F74F36E815ULL, 0x321868501BA7EB90ULL, 0x1F9DDF0240CF52B8ULL, 
            0x7E92E7345BF3A2A4ULL, 0x4CF7972CD96ACB88ULL, 0xBDD75F1800534696ULL, 0xDC6B0CE1A6D88110ULL, 
            0xD03B0AFD80E35E6EULL, 0x9D9981C8FF006753ULL, 0x11AC7FB548D5BE70ULL, 0x6D4454A7FA3D34EAULL, 
            0xB1EBE0AB5C081B98ULL, 0x338B12AD5ACA66B3ULL, 0x1E1887BC32514B33ULL, 0xB4338582F467FD77ULL, 
            0x4077052F9503DEA8ULL, 0x21D06117085DB4BCULL, 0x3AF8BD72055DD3C3ULL, 0x6AF77F3242A50420ULL, 
            0x0D970250DE5888E9ULL, 0x540113E6D8D7FFE8ULL, 0x8EF0CD6F4C669CDBULL, 0x05428F5647368918ULL, 
            0x9A86B9EAC433C672ULL, 0x6B138B5CA324F54EULL, 0x595B48807FAF8579ULL, 0xA79A5449E9A72D4EULL
        },
        {
            0x6BF46C5A737AE2AFULL, 0x9924AE512D206186ULL, 0x92D3E9E236DABA74ULL, 0x52A5FAB1A73E8B7EULL, 
            0x7D4AA7E5F2885941ULL, 0xBDE09440BB60D946ULL, 0xB7E996BC9F1E3718ULL, 0x9A1E90EB656A6AA7ULL, 
            0xEB33CEAFFAFA5E93ULL, 0x054FFD6004121701ULL, 0x805736D508F669D8ULL, 0xA94A53789CFBE336ULL, 
            0xE3B84F476079E167ULL, 0x8AAE6784CFCD5CF1ULL, 0xA6CB31AA4EFFCCA1ULL, 0x55FE17D7C7E2B5CCULL, 
            0x35C72985EAFE3FECULL, 0x2E47650BB3A04852ULL, 0xBBD6E7F890BD4917ULL, 0x66F8EE3FF8740199ULL, 
            0x6052DC5CFD87D0F2ULL, 0x7B98D9868D3AAD0FULL, 0x952BE92C997C36B2ULL, 0xB2388C4045F0C47CULL, 
            0xC32933D1EAC36AAFULL, 0x9E5A4BC379B036CDULL, 0xAB0E690AF7D918C4ULL, 0xAE91FA458B3083A3ULL, 
            0xB2541D829A08E45CULL, 0x5E32A6CD4A9DFE37ULL, 0xA9496224AB3CAF0CULL, 0x287A3F538DF74FC1ULL
        },
        {
            0x1DE6E71FE6BC5A8EULL, 0x43B4B791260AE885ULL, 0x16A4DC0CFEDFE3C7ULL, 0x93563E78C11441A3ULL, 
            0x2A3358FD330B1BF3ULL, 0x322F6AB22E4943EAULL, 0xBC562D2C029893CBULL, 0x03E7E2DC8A951FA6ULL, 
            0xD8DF68C1E40EBE20ULL, 0x1103BAFE69ADE8A4ULL, 0x5B1958C54E6B141FULL, 0x5BCA2887F7A14476ULL, 
            0xBC06C0FDEA39CA29ULL, 0x5FE16FC7B06C51EAULL, 0xDE8271D6237FFE26ULL, 0x17380CAE7A91D63FULL, 
            0x7189713BDAB94070ULL, 0x58AC3D7D10E9C11DULL, 0xF85D5EC2FEA391B2ULL, 0x924F3A7497558C61ULL, 
            0xE058914A8B09AED3ULL, 0x63E356EFCE61A862ULL, 0xDA464B2B157F57DAULL, 0xDE4F7028AD7FE863ULL, 
            0x1A21E9909AC86E8CULL, 0xAE2929204C51B1F2ULL, 0xBE72C773F844AC67ULL, 0x4B5BA725CAA6DA99ULL, 
            0xE25A11F059229E4EULL, 0x44569976D284C576ULL, 0xB8F58D69DF5743BEULL, 0x75516ED2A690DC29ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseGConstants = {
    0xF656CC7D586995D6ULL,
    0xCA07B52EEF594482ULL,
    0x4392474018B13D14ULL,
    0xF656CC7D586995D6ULL,
    0xCA07B52EEF594482ULL,
    0x4392474018B13D14ULL,
    0x59FACC0F09976E4FULL,
    0x6EBF40F65AEB9A9DULL,
    0x57,
    0x5E,
    0x68,
    0xA3,
    0x2A,
    0x90,
    0x78,
    0x41
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseHSalts = {
    {
        {
            0x6AD2ECCE16BB2CD8ULL, 0x8483DE32376A39DEULL, 0xB48066E936ABC65DULL, 0xCA4F6BBE4F8ED006ULL, 
            0x68839AAAE93D5ADBULL, 0xF843C89252F97D6AULL, 0x57201C3E7AA060BFULL, 0x31843B631C7986DCULL, 
            0x2E341B9C55BC90E2ULL, 0x3973CF6682CF4E5AULL, 0x5B94B50C619DA0F8ULL, 0x33CDE419756A72E1ULL, 
            0x8B238101CF2BB636ULL, 0x70C7F11A07A3EA01ULL, 0xD828D03068124D02ULL, 0x0026FA88F8033575ULL, 
            0xA744C621FC1044FBULL, 0x05CB89173113329CULL, 0xAB865F4B969D7085ULL, 0x04B4FE230F434F02ULL, 
            0x45E4851AB950E5AAULL, 0x3D99CBF2A358EC73ULL, 0xE358CE4417D60747ULL, 0x43D624D3B468E909ULL, 
            0x55C26A06D39382EAULL, 0xE2C08329A036C6A1ULL, 0xCD35E4C75ADA8E60ULL, 0x3AF4ACE1A029C4BDULL, 
            0x62559BD498D05ED3ULL, 0x8D4CE44EFEAA6BDFULL, 0x39884D1E60AA01FCULL, 0x0E97640D0A104191ULL
        },
        {
            0xB14EE89F7E2685E4ULL, 0xA691DC957AE77B88ULL, 0x825AD39F03933BDFULL, 0xE1544752E3F5532AULL, 
            0x7F8B191DAAE10112ULL, 0xCA8BFD0054DD6C6FULL, 0x615A5E6F9CF052D5ULL, 0xA7B599B6568C6E46ULL, 
            0x73BA7E1B12DFED60ULL, 0x412F479BFC2932F2ULL, 0x968AC1E05F8FA563ULL, 0x13087566A5008273ULL, 
            0xB8358AEC29E99F54ULL, 0x658CE18322FC1D15ULL, 0xCFA1ADAD1ACD6BD2ULL, 0xFD53C4873A37BB86ULL, 
            0xDB969F28EB12CBEBULL, 0x9BFFCFC15FCFBA78ULL, 0x186C99094D20F418ULL, 0x0FE728D427E8C77CULL, 
            0xB74231B72C52D020ULL, 0x3E0D620557BBEF5BULL, 0xEF225EF651B36A2AULL, 0x26B879124CD4DBEBULL, 
            0x7E229E9776C9F16BULL, 0x4316856F79220005ULL, 0x91CDE347685FC3E4ULL, 0x60CFBE5321465277ULL, 
            0x05855D9B54D265B7ULL, 0xD216545560A5DB49ULL, 0x252680337B536405ULL, 0x8006337FF11EC390ULL
        },
        {
            0xA3E253725D03A48BULL, 0x5DB842BAF29C9E34ULL, 0xDF1BD8FF899138A9ULL, 0xBF8574D4A333CE4BULL, 
            0x8C6EEE675E861BC0ULL, 0xF9AD34301664D646ULL, 0xFB54965ED48C8FB9ULL, 0x0004606334900FD7ULL, 
            0x060A3B5B79F230AEULL, 0x7F17DC0788EECCEEULL, 0xBEDF2EDD9E3E733BULL, 0x8CD8A4C5CCF630E0ULL, 
            0xB6952BB32859805AULL, 0x5F987C7859BB918CULL, 0x0229AF714330E916ULL, 0xAEEAACD8C48A75A7ULL, 
            0x5744A1D6D336984AULL, 0xD17CFAE09A75118BULL, 0xF754E5E2D3334D54ULL, 0x4DA42294A400D9FEULL, 
            0x2713FC577A306B86ULL, 0xE64B629715A36618ULL, 0xC1FC49B2D01D99DCULL, 0xDED21F9066FEC40CULL, 
            0x57B4BFB8B36D22A6ULL, 0x9C8B09309793F24BULL, 0xE871992DBB0B507EULL, 0x635A7024022AD8B7ULL, 
            0x75E195233EF4D65FULL, 0x8EC1DAD8AF455410ULL, 0x629B7AE6E2D36CA6ULL, 0xCA21F74079E2C10AULL
        },
        {
            0x00C5FB567F45F75FULL, 0x680E8BF660200CCCULL, 0x5A2FDF38D1A2B0F3ULL, 0x54C7DC72780FD273ULL, 
            0x59C2B9786CAD6332ULL, 0xB919EC8C7B94A751ULL, 0xB2A713812A3F0881ULL, 0x21E9ACC96905BC5BULL, 
            0x10B70A7AC87BC4C0ULL, 0xA2E63F07EA68C836ULL, 0xD77683D7D51C343EULL, 0x5EB79AD821D092BEULL, 
            0x69B34024F1BEC76EULL, 0x2FE94FEE87EB8B00ULL, 0x79F66E1B3364A904ULL, 0xFB3E3987EAF8D8B1ULL, 
            0xA48D4A72A9B1AF73ULL, 0x0BA7FDE8DBE825DEULL, 0x165EA1392405E086ULL, 0xEB56CFFBDF5C698EULL, 
            0x4D7D664C3EBA1757ULL, 0xA5AF4B4FC96140EDULL, 0xA1635888B9011D7FULL, 0x8CD1BCD8FCA3F7D9ULL, 
            0x78A09FD1E532D773ULL, 0x0F31C7419D614A3BULL, 0x79343F159ED673DAULL, 0xF3758B336A6E2917ULL, 
            0x5CE1D4022989501FULL, 0xC3D2F771D1D511D4ULL, 0x665B11D663474C17ULL, 0xC2DD64100F89278AULL
        },
        {
            0x09D10A9B7370C1EFULL, 0xA9DACB0A9796A1F6ULL, 0xDB624A22395FDE4BULL, 0xA1B811004701B04EULL, 
            0xA67FEBFADF2D5F00ULL, 0x7D4EA5260739A1D1ULL, 0xCA388821A1D12C6DULL, 0x6023E3536A4ACFECULL, 
            0xF6D291C616B6F2F9ULL, 0x9D8BC8A002C5E395ULL, 0xD34BB8F4E688BBE0ULL, 0x7153974702A059C6ULL, 
            0x2C18F4A245C94A26ULL, 0x31E176C010F33EA4ULL, 0x845AC41E5431C4CAULL, 0xBB11D619F772660AULL, 
            0xDB7AD127A899A5F3ULL, 0xBF16B33B7281082FULL, 0xBF5E87E61B5A666CULL, 0x7A2EBA505D886953ULL, 
            0x2FFC4947819B9BE6ULL, 0xA42FFF432927629EULL, 0x7959718A5E9DB441ULL, 0x3DBF4CC189D59C84ULL, 
            0xF6A14F2F40903582ULL, 0x3702CEA57C4DAFD8ULL, 0x94C4780B4CB8E9E3ULL, 0xF7C5B33039D94C1AULL, 
            0x3D7F56AA3C61B7A2ULL, 0xE180AB0272A28F5CULL, 0x4F07AACC2A0B1065ULL, 0x270345CF78EEF498ULL
        },
        {
            0xCBDC252306F831ECULL, 0xECAD5836E114758AULL, 0x048B54F5887C5852ULL, 0x5E92FDC1A59DD68CULL, 
            0x79E3B0DBD0D0C6D3ULL, 0xDEB84A2081AA4A3DULL, 0xE97510B3DBB0C9EBULL, 0xDA50E56A0CD9369EULL, 
            0x9FF319C99CFE37EBULL, 0x65AC6D44B9EC6EA9ULL, 0x1142D63D4E06A033ULL, 0x53C3E712B6E155C8ULL, 
            0xF84C7E9020D35AB4ULL, 0x0C7104C30E5EEBE7ULL, 0x08C79BDA59562928ULL, 0x73156A8C3456F389ULL, 
            0x0666EC19EECE990AULL, 0x2976E0A16E4259E7ULL, 0xF563AB9C266D8A42ULL, 0xEF62C37E6DBE21AFULL, 
            0xC7667D915749F00AULL, 0xEFF4AC1D90630487ULL, 0x483FFEB97CF9F73FULL, 0x07850D4F3E681E6FULL, 
            0xE3FDD026BB1303EDULL, 0xC702536872E18858ULL, 0x7F775BFE12D61430ULL, 0x09F72D5BDAEA1960ULL, 
            0x9579F10E4AAC06C6ULL, 0xF48FCE94C78DDB3CULL, 0xEEE128C96581D68BULL, 0x3B91DA9A9DA86C5EULL
        }
    },
    {
        {
            0x637EFDFEB152BA89ULL, 0x98703015917FD8FFULL, 0x92D331FA8055A51BULL, 0xC9E4CCA4189EA1E5ULL, 
            0xC7A9D9E873AFCFCCULL, 0xEE3A509651A8B150ULL, 0xA0FA7221AD0131A6ULL, 0x900A5EE6199ADB18ULL, 
            0x2AC63F50F7021CA7ULL, 0xAFD7A8397BC1AAA7ULL, 0x0E64AF22A10A1C1EULL, 0xDC54806DEEBEAB99ULL, 
            0x0B56F9DBB73A6E3DULL, 0xD14E4810AAF717ECULL, 0x87B76E6FDFAF4E06ULL, 0x542AFB72B5DE312AULL, 
            0x5D4E433534534A83ULL, 0x48831A7DFB9C25C3ULL, 0x5C331A57ED2AC32EULL, 0xE745B1EB0F3CE07AULL, 
            0x8123625FFDA66237ULL, 0x12A8D792E983FA32ULL, 0x42861DD5C06A09BBULL, 0xA74E51A7F47784D5ULL, 
            0xCE2F9ED1D5CF24CDULL, 0x37259389116DB078ULL, 0x0E3EDE7852175CA9ULL, 0x86B42D0E53F9C61DULL, 
            0x872F52E104CA4FAFULL, 0xD2A95DCFACA7A5C0ULL, 0xE301AE847371F582ULL, 0xE1F764ED598B3BBAULL
        },
        {
            0x7E9AAB64E946DDE7ULL, 0x0B8764CA31016199ULL, 0x8FB23E18189D7312ULL, 0x0A1CB9A247B79DE6ULL, 
            0xA6F49A680480F905ULL, 0xD40628A46235D536ULL, 0x6005C9480BDFB61FULL, 0xA9EB4C99F9CFD829ULL, 
            0x6CE1270DEEC34F92ULL, 0x277E0E9B7ED2583EULL, 0x6B5DE9A8DEA6B54DULL, 0xEA075BDE3641C56BULL, 
            0xAD867209969B875AULL, 0x88903A7A89EFD292ULL, 0x5EB01B4990ECC9B9ULL, 0x2570B03E136C7BB5ULL, 
            0xAC026EA17A741D3FULL, 0xAD5FB97ABDA968CEULL, 0xD44CC1610EF46E1BULL, 0xE08D91ABDDCA6990ULL, 
            0xC2C224D9023A143CULL, 0xF8AD44BC1D5B3378ULL, 0xE9EE87E31CAE1531ULL, 0xD796E92D38A09C5AULL, 
            0x5A5CC8ED3792DC47ULL, 0x46F6ABB976565CC7ULL, 0x6D2FC4ECC96AE0E9ULL, 0xFDFDCF1355853BC4ULL, 
            0xA117490BC1374E24ULL, 0x1F439C5EBE48FB87ULL, 0x775C2380D6451570ULL, 0x30495885A26DC4B8ULL
        },
        {
            0x8E1C0A24CCE4636FULL, 0x18ED3B048BB5C30EULL, 0xB8C88AECD09DFD2CULL, 0x64E74A8FC6616F98ULL, 
            0x6702692BE4B8FDCCULL, 0xF6B66D2AB1C02D04ULL, 0x1D46C77B29A41270ULL, 0xA5238C0F30750275ULL, 
            0xBF5C31AA3D60B5D2ULL, 0x3C4B5A3F114521A3ULL, 0xE136D4CCC240A215ULL, 0x1EAEB9A11A1F1B15ULL, 
            0x4AD4824C7CB69D3EULL, 0xD3ACABF96B66A414ULL, 0x54A97FCE03ADD7CFULL, 0xD32D78A189A8FAE0ULL, 
            0xCE16E71CC1E3F3ADULL, 0xD6072BCF265C9635ULL, 0x10C6B2705BFF8845ULL, 0xA1D3F25AF5513772ULL, 
            0x8276FF886550DAE0ULL, 0x68627D80F149EBDBULL, 0x1720963337614ECCULL, 0x02E19D1EBF77D5FAULL, 
            0x78856AA1C9E6BE72ULL, 0x5B83ED0A88FFDA7BULL, 0x3A381239D3684185ULL, 0xC28619FA3ADD34C3ULL, 
            0x780C7E7A737952DDULL, 0xD1A6BA6BD6594790ULL, 0x9C857E81D964936CULL, 0x0D979D33399FF0E5ULL
        },
        {
            0x75ED86D14A1D5428ULL, 0xADDC07A6BD1E102CULL, 0x6C8BFFA20A9CD3F1ULL, 0x8DE5736FFC368BF8ULL, 
            0xEA12B2EFFC84BB08ULL, 0xC69B5E06D98E76ADULL, 0x3B7AEC343C9595A2ULL, 0x67BD3C3C8E99A0ADULL, 
            0x25147B5A45946502ULL, 0x20CE7F1CD24E5BB0ULL, 0x3A766CE05732AAEEULL, 0x12F035713D3C3BDFULL, 
            0xF665378E67F82DA6ULL, 0x92329CE1D3859C1BULL, 0x839909A105032D85ULL, 0x15521D13F2E804DFULL, 
            0xB7D9711B08E72988ULL, 0xFB1FD50C94EA4364ULL, 0x865B134E957D31F7ULL, 0xC9440E8CDEBD0301ULL, 
            0x3333417392B17745ULL, 0x12B4E85818BAB2DEULL, 0x6C1B730AFE9F8E89ULL, 0xCE757780BDEF3091ULL, 
            0x3B78D5D9577F4457ULL, 0xBCDB6700E7A11B4CULL, 0xC2FC63AB0A78801FULL, 0xC723E50BD12D1190ULL, 
            0x0A10FCEB8C9A5B34ULL, 0x08DA4EB7B5D23DB2ULL, 0x7EB348C972E6FF75ULL, 0xB9FD70E60B7A224AULL
        },
        {
            0xADF6A1C472B53332ULL, 0x1395218005763271ULL, 0x8090980E8FE1259AULL, 0x65D1A21A0A2D0907ULL, 
            0x86DE97F1FEB46385ULL, 0x5FEF897A22A536DCULL, 0x7DBC2AD2DA70EFACULL, 0xCF8FF4CEBE663479ULL, 
            0xC69558290DF2AB2BULL, 0xAE2428BB9933CD99ULL, 0x9AE843FC80A1B47EULL, 0x8FD965F6D43719F7ULL, 
            0x2D3EE289A5EBC6CAULL, 0x81B0EA06C8D231F3ULL, 0x790B995E4223FFC9ULL, 0x7DCF6724360F7BEDULL, 
            0x65001D6488D69DF2ULL, 0x9FC5BBB2CAB23327ULL, 0x518A230EFAD0D070ULL, 0x8C2F2F51E7F681D2ULL, 
            0x572F02E161127BDBULL, 0x93FA4630922BF920ULL, 0x05B157AFC1DDBBC2ULL, 0x56F4F8BFADDDE825ULL, 
            0x1B0BF681ED039430ULL, 0x3A5AD71C084087C6ULL, 0xE525999588E1FDE5ULL, 0x57500C3D66250151ULL, 
            0x25F1F444905F8072ULL, 0x15309183FE20A215ULL, 0x10B59816183F3A14ULL, 0xF0BBF7B416F2DD83ULL
        },
        {
            0x4D4BADAFBF4AD863ULL, 0x5A5720DFEAB23F97ULL, 0xD950B45BEBC41BF7ULL, 0xCE998F2458D1267BULL, 
            0x8FBA41465AD115E7ULL, 0xA98E1B3935EC1233ULL, 0xC52EDBB5660E7C65ULL, 0x45FF5EDB4CAB7142ULL, 
            0xE13F638A6E90F014ULL, 0xCBD63EF4A93978F0ULL, 0x81D5E30CA9777DDEULL, 0x7A7C6E07456CB30AULL, 
            0xA43D0E40AE59B4F5ULL, 0x7F71153EDD234C9DULL, 0x21AF4DC58F2B2E9EULL, 0x9D6599605D10260EULL, 
            0x64A7C5F57630A8F6ULL, 0x2C2F82E2D10DAD7AULL, 0x76166735AF2455D3ULL, 0x11E8F8D8546459FAULL, 
            0xC8F96736E24D62B9ULL, 0xECC07011E885DE56ULL, 0x0713AB74929AB214ULL, 0x370A88C0C088345FULL, 
            0xF7BDC8BF0E4E8548ULL, 0xC00901ED217EC089ULL, 0x4838CDE69CB8C271ULL, 0xE5CDA89787EBA1D0ULL, 
            0x15D4B0A955C9A50FULL, 0x95267D586535EDEFULL, 0x158A11FA35E6BBA7ULL, 0x97EF49672E4EE347ULL
        }
    },
    {
        {
            0xEC641419D0FCCBC6ULL, 0xD5B9B243E4C3BC46ULL, 0x436A15351B94DAD1ULL, 0xA7AE65E3F318EE32ULL, 
            0x39B49EF490698CF7ULL, 0xB0ED6D9141EE1DF9ULL, 0x307E6E237FFBEE2EULL, 0x733AA0CFA2D3AB85ULL, 
            0x509B46113F69C4E3ULL, 0x413C977F7ADAE95AULL, 0x9372485EFAA71960ULL, 0xBDFF4E81B956DB5AULL, 
            0xC96BD70A24539934ULL, 0x93B278F521A6C848ULL, 0x588593D4322F3207ULL, 0xA444C7EF37C69C61ULL, 
            0x2883BE0149006A82ULL, 0xBC818CE81D1784E5ULL, 0xD2F1DD1010F5C704ULL, 0x35C09B35C97C5459ULL, 
            0x0B121B45A9F24EB9ULL, 0xE11997062900C1CEULL, 0xC42363ECBC212065ULL, 0x2FA2114F06BADEBDULL, 
            0x094AB713FD305E05ULL, 0x12A0918E10AEFB6CULL, 0xD756F871B2BAFF38ULL, 0x275F814DB21B9270ULL, 
            0xEC0D2BC36039A220ULL, 0xD2E44E964304CCE2ULL, 0x3514FEC12A941094ULL, 0x2F055B88FA0E6EDDULL
        },
        {
            0x185154471FF3E3C3ULL, 0xAA8E501E88C80513ULL, 0xF8EDECD968490C66ULL, 0x77DB735169245F31ULL, 
            0xD6EE702651903CABULL, 0x793940D7785E9E39ULL, 0x59FD91A9CB403853ULL, 0xBC68690CC55E44BBULL, 
            0x1BAC906B68A9FEE3ULL, 0xB8D4C7806B76B514ULL, 0x05234C05778279E4ULL, 0xFD42C09A5876EA3CULL, 
            0x84275635E9906D0DULL, 0x9EA0A17CF191C9BDULL, 0xB96DE99E611EC676ULL, 0x4D3918591450CF91ULL, 
            0x50EBB2D7A5C648C6ULL, 0x85BA2F8CD8D28C64ULL, 0x2071E973DBD03B4AULL, 0xFDE594635BF8D933ULL, 
            0x7ABE627FB2F9414DULL, 0x6B4AA1AE26871ACBULL, 0x456A7C19C925A0B3ULL, 0x15183ABA18573F34ULL, 
            0x4BDCF0709AF0F601ULL, 0xE46DFF455729C60CULL, 0x4BA88276A7750083ULL, 0xE61944C02A25AD3DULL, 
            0x9047F53178AA5397ULL, 0xD4E7C158BFF4BB6BULL, 0xDCC74D4C14EBB527ULL, 0xC7891678D278AEAAULL
        },
        {
            0x3D1889237F61C2F3ULL, 0x46F0398BCE045A7DULL, 0x4CD79E968672EF79ULL, 0x7CE81AEF04E438ECULL, 
            0xE0EF0259AAF61F3CULL, 0xFC54913E050F2198ULL, 0xCB1E9C24B3859A79ULL, 0x3F70A540B36308D1ULL, 
            0xD82D28E8C6D3407BULL, 0x63EB309AAE3E3B55ULL, 0x153AB0BE7D7B908CULL, 0xE784BB84E2237388ULL, 
            0x8E6DFA37AAFC9AB2ULL, 0xC7792A44BA025483ULL, 0x47DA524F6FF2F6D1ULL, 0xA5AC8D3FC4FB24D3ULL, 
            0x45FF51F440308284ULL, 0xBC45B782B1D769A0ULL, 0x1A071C8058392F1EULL, 0xE01BFF3F2F688F9BULL, 
            0x47E7A3864D29D3D3ULL, 0x0A2CCC28926CB278ULL, 0xEE16DD860A4178EEULL, 0x92BDC19EE4B0765BULL, 
            0xEEEE8497652A76F3ULL, 0xE5C0F054E38484E5ULL, 0x0E2339A2827C673FULL, 0x48F73DBF1DD9F363ULL, 
            0x9CFBF2E6371482F7ULL, 0x16EC3DCA009B2D2EULL, 0x2D668E40505E28C6ULL, 0xDF26344584B3BC66ULL
        },
        {
            0xD6D835AA3C9D0E3DULL, 0x81A3B2DE72A167B8ULL, 0x29D5A2176E9C9DD6ULL, 0x0C4A9503B10673ADULL, 
            0x08185409FA5BFE46ULL, 0x60F53F2DADF653F7ULL, 0xF0FFDE653B75F1A6ULL, 0xD3E8ED0B6D14D3ABULL, 
            0x159FB37365A1D8DDULL, 0xEC971FA7D1268128ULL, 0xAEE89D98EE9BE6E7ULL, 0xD918016E1FEAF9E9ULL, 
            0xAAD00C5B719EF42BULL, 0x87CD1E081D745928ULL, 0x965E77EAECE7EED3ULL, 0x04620D98A99A1317ULL, 
            0x9E082BC9550A77A2ULL, 0xBE90F91084F01229ULL, 0xBAE1ED69FEFB71BFULL, 0xEA2CEC75967D9F59ULL, 
            0x60B529B39666CA91ULL, 0x14AA96457BEEB0EAULL, 0x720B464AD8185B14ULL, 0x8E34ABD3C232714BULL, 
            0xD926F413C2FB5E21ULL, 0x3F6BBE2193D3C91CULL, 0x2D0C8E78A73ECCDCULL, 0x94D98A75EA6D3EB2ULL, 
            0xF699FAE1CC826539ULL, 0x44E3286B8EB8E255ULL, 0xEEB549788C20FC01ULL, 0xD07EA8059431B613ULL
        },
        {
            0x07C8C23D2A29229BULL, 0x6A1FB94A5D75D747ULL, 0x80B8D49A4F1601D1ULL, 0xB4EB677DE31F2D12ULL, 
            0x4648C5A112F0E79CULL, 0xE31B36055B7BDF26ULL, 0x8D75EF4B45781E2FULL, 0x43CDC19372A3EB67ULL, 
            0xFDD9C1710804863FULL, 0x1DF49DB2B855227FULL, 0xB3B1FB15792621C9ULL, 0x82A5C6F2C6F7E85FULL, 
            0x997EFD1BD327300FULL, 0xF8B31EABAC85A400ULL, 0x1B8F068CD73B73D3ULL, 0xF03E736495A0665CULL, 
            0xB7BA8F32612D36FCULL, 0x105B613C505ADF7FULL, 0x600063CDA106476BULL, 0xEEEEEEADE254DDABULL, 
            0xF43DFB8353852997ULL, 0x630EBC378C552FEEULL, 0xC8C8770A283CE1ABULL, 0x9792A0D97B779A00ULL, 
            0x71EB29E96C4B7555ULL, 0xCC0247235F747A73ULL, 0x5CDF45C9395480EFULL, 0x8C57F689AC69A23DULL, 
            0xE25D095B2F03EE22ULL, 0x9348D47050CA1127ULL, 0x82AFCA0EE3919CD6ULL, 0xF4ED9130FE1D4F43ULL
        },
        {
            0x5486A23F22DD4C9DULL, 0xD422C3553198975BULL, 0x6E14E225DF500583ULL, 0x69F4FED75F054869ULL, 
            0xE21AB0A8D75DAAA6ULL, 0xBF4213E3FE92DC30ULL, 0xFAF04401852A2AB9ULL, 0x6A8D912D439EEEB2ULL, 
            0xF99A639A27963B7BULL, 0x2B5908929D949A94ULL, 0xA601EABDE8BE48DDULL, 0xC681A4520052A594ULL, 
            0xE846B707D03EF831ULL, 0x62F0E97B48B558C7ULL, 0x29855CF7AFE7DDE6ULL, 0xDC0DCFFBB223E467ULL, 
            0x74D740B3406149B8ULL, 0x0832D4BDB659A4C4ULL, 0x9E10D48A5A77BF67ULL, 0xACD2033118D7C1DDULL, 
            0x42F27A47D4C77871ULL, 0x98CD9D34A62B5F3CULL, 0xF582E15D29EAFE20ULL, 0x16FC097439F31AA0ULL, 
            0x2CCC3DC602596B2EULL, 0xBC2076CE7F19BC14ULL, 0xFE55F48834474A86ULL, 0x3CEA79866F615413ULL, 
            0xFBF113CDA24263B8ULL, 0x5D950E1BC8304B80ULL, 0x3830AC2C322FC57AULL, 0xF3815C1FC9BAD34AULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseHConstants = {
    0xA0A055C47F3A10E2ULL,
    0x09876F4ECE5D30F4ULL,
    0x6BD6E72166BD33B5ULL,
    0xA0A055C47F3A10E2ULL,
    0x09876F4ECE5D30F4ULL,
    0x6BD6E72166BD33B5ULL,
    0xEE740EE0CA2B2F66ULL,
    0x932A970CA759A10FULL,
    0xEC,
    0xE6,
    0x3A,
    0x50,
    0x32,
    0x41,
    0x91,
    0xE6
};

