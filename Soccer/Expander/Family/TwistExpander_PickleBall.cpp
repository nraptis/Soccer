#include "TwistExpander_PickleBall.hpp"
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

TwistExpander_PickleBall::TwistExpander_PickleBall()
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

void TwistExpander_PickleBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xEB00A17B54941A5AULL; std::uint64_t aIngress = 0xDB11F00FDF63D199ULL; std::uint64_t aCarry = 0x88B41A34D72E4370ULL;

    std::uint64_t aWandererA = 0xCB2E4F9E237095C1ULL; std::uint64_t aWandererB = 0xA8A9B699599928B3ULL; std::uint64_t aWandererC = 0xC468DF3CCF91B322ULL; std::uint64_t aWandererD = 0xAFB7C76881033628ULL;
    std::uint64_t aWandererE = 0xF35CB677846D05C9ULL; std::uint64_t aWandererF = 0xDD8CE614C0D2788AULL; std::uint64_t aWandererG = 0xCCBAF685B00A1D33ULL; std::uint64_t aWandererH = 0xCEF8941F55286203ULL;
    std::uint64_t aWandererI = 0xB622DE5D5E8AB435ULL; std::uint64_t aWandererJ = 0xD80C561E035279F5ULL; std::uint64_t aWandererK = 0xEDDA89C87D160655ULL;

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
        aPrevious = 11015948125441815804U;
        aCarry = 11269233975613510428U;
        aWandererA = 15438514187509456813U;
        aWandererB = 9794045410504249013U;
        aWandererC = 17228998845572036557U;
        aWandererD = 15123152525266121318U;
        aWandererE = 15078217128233181891U;
        aWandererF = 15994362867443523081U;
        aWandererG = 10297080291995368955U;
        aWandererH = 17513605628048317222U;
        aWandererI = 14213218893677673684U;
        aWandererJ = 12424962694852533137U;
        aWandererK = 13072028304980887011U;
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
    TwistExpander_PickleBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_PickleBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xBBFAC43762C1B575ULL; std::uint64_t aIngress = 0x9F3DEED322ECBECBULL; std::uint64_t aCarry = 0xDEFCD6C6AA511D2FULL;

    std::uint64_t aWandererA = 0xE9CB3D5C696B3B89ULL; std::uint64_t aWandererB = 0xC70E5E3F317A3854ULL; std::uint64_t aWandererC = 0x8727E050A95699B2ULL; std::uint64_t aWandererD = 0xEF5BD7948749842BULL;
    std::uint64_t aWandererE = 0x890C6E0340949DB8ULL; std::uint64_t aWandererF = 0xF251949CA4DB9AE0ULL; std::uint64_t aWandererG = 0xD04A9EE8FA8559FBULL; std::uint64_t aWandererH = 0xD09ED11FEA8E0333ULL;
    std::uint64_t aWandererI = 0x8DA65302E6233080ULL; std::uint64_t aWandererJ = 0xF8953DB916249FEBULL; std::uint64_t aWandererK = 0x8DCBE5729AD4784DULL;

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
        aPrevious = 14972248979476395658U;
        aCarry = 14285257647199774795U;
        aWandererA = 14738830915047049048U;
        aWandererB = 13873230860739201282U;
        aWandererC = 14838607116793346294U;
        aWandererD = 16456540004629551580U;
        aWandererE = 13949858328674866296U;
        aWandererF = 14344826032836201260U;
        aWandererG = 10584338332699300572U;
        aWandererH = 11538279757194590498U;
        aWandererI = 9748530487341855064U;
        aWandererJ = 17255244988474156194U;
        aWandererK = 12533620735926432425U;
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
    TwistExpander_PickleBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_PickleBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x99BB96B3FE1D8597ULL;
    std::uint64_t aIngress = 0xE16EF08B8E843D2BULL;
    std::uint64_t aCarry = 0xF0604D692DB7EB5AULL;

    std::uint64_t aWandererA = 0xA0305DD20A9120D5ULL;
    std::uint64_t aWandererB = 0x925D463D74FEAAE2ULL;
    std::uint64_t aWandererC = 0x9FA9B13EBBF2BF3AULL;
    std::uint64_t aWandererD = 0x8B3DD464BE755813ULL;
    std::uint64_t aWandererE = 0x803774558064DFF1ULL;
    std::uint64_t aWandererF = 0xA75CE668094B3FDCULL;
    std::uint64_t aWandererG = 0x8CD63E5C07692F7AULL;
    std::uint64_t aWandererH = 0xF7B2A78D036C92F7ULL;
    std::uint64_t aWandererI = 0xA14C505497DB9915ULL;
    std::uint64_t aWandererJ = 0x94DD19362B33CBFDULL;
    std::uint64_t aWandererK = 0x9845219DCE326EF0ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneF);
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD, 3);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD, 7);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneH);
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_PickleBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PickleBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_PickleBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x840BE21E323F9135ULL; std::uint64_t aIngress = 0xE168ACC116897014ULL; std::uint64_t aCarry = 0x887220632982E1B0ULL;

    std::uint64_t aWandererA = 0xDBD67CA86EB0B575ULL; std::uint64_t aWandererB = 0xC85B7D0FC4424F3EULL; std::uint64_t aWandererC = 0xF97F13A0B6191432ULL; std::uint64_t aWandererD = 0xA005B1DF4160E33FULL;
    std::uint64_t aWandererE = 0xC94199BEE9D36BD2ULL; std::uint64_t aWandererF = 0xA1650275353891E2ULL; std::uint64_t aWandererG = 0x8CB822FD4ADFA520ULL; std::uint64_t aWandererH = 0x9F3D019B630FB9E9ULL;
    std::uint64_t aWandererI = 0xC4432C0E9BDEA109ULL; std::uint64_t aWandererJ = 0x8D30C92D8FC4380BULL; std::uint64_t aWandererK = 0xA1122C95EEA6E281ULL;

    // [seed]
    {
        aPrevious = 12537727148164834702U;
        aCarry = 16681314169736374720U;
        aWandererA = 11663949762213388443U;
        aWandererB = 16805885196654488790U;
        aWandererC = 16609357068034854416U;
        aWandererD = 9888824117624140830U;
        aWandererE = 10958646440157175373U;
        aWandererF = 12392266173120539004U;
        aWandererG = 16272855900168520741U;
        aWandererH = 13438481909326664759U;
        aWandererI = 15343736907476047970U;
        aWandererJ = 12975986494602982116U;
        aWandererK = 11057647310405998942U;
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
    TwistExpander_PickleBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_PickleBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_PickleBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PickleBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 3 with offsets 1217U, 3183U, 3927U, 1691U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1217U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3183U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3927U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 1, 0 with offsets 6877U, 7053U, 6414U, 3093U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6877U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7053U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6414U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3093U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 1 with offsets 3030U, 6770U, 4832U, 511U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3030U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6770U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4832U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 511U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 2 with offsets 5927U, 3605U, 126U, 654U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5927U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3605U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 654U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 with offsets 973U, 596U, 1358U, 567U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 973U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 596U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1358U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 567U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 1276U, 1663U, 360U, 1657U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1276U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1663U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 360U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1657U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 1, 3 with offsets 224U, 2019U, 1439U, 1857U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 224U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2019U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1439U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1857U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 1, 2 with offsets 606U, 1351U, 918U, 1286U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 606U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1351U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 918U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 72U, 1945U, 616U, 662U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 72U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1945U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 616U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 662U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PickleBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 3 with offsets 7300U, 5594U, 5924U, 88U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7300U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5594U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5924U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 88U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 0, 1 with offsets 6696U, 2882U, 5520U, 5123U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6696U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2882U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5520U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5123U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 0 with offsets 4594U, 5872U, 1659U, 7587U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4594U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5872U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1659U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7587U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 2 with offsets 3309U, 4472U, 6119U, 4271U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3309U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4472U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6119U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4271U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2325U, 4133U, 7600U, 3448U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2325U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4133U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7600U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3448U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1629U, 1145U, 418U, 0U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1629U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1145U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 418U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 0U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 380U, 1217U, 908U, 1748U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 380U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1217U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 908U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1748U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1069U, 1090U, 1052U, 1860U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1069U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1090U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1052U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1860U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1194U, 1740U, 1819U, 788U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1194U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1740U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1819U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 788U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 843U, 600U, 85U, 1624U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 843U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 85U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseASalts = {
    {
        {
            0x07576D34149FFDFAULL, 0x4B33DCD7E7EE9F48ULL, 0x1F214C9E1E773753ULL, 0x7B629CA3D62D3FDBULL, 
            0x45E28E7EDDFBF2CDULL, 0xE5DB408DD624CF96ULL, 0xB3F660C4F9D7950DULL, 0xF8EF5884D03168ABULL, 
            0x9B256B5560995BC2ULL, 0x34D919E1CE6D637EULL, 0x3545470CF6931C0EULL, 0x979B004C00C4E472ULL, 
            0x27F3948D5FB28F34ULL, 0xB85DC53DD82116D8ULL, 0xDE6D4937AA7B7BEEULL, 0x74F295E3EC7F75EBULL, 
            0x22A27DF2F3741805ULL, 0x9654A96F34489126ULL, 0x32ED7C90F3C6D116ULL, 0xFBB0D22519DEE579ULL, 
            0x804CE697BFDE5558ULL, 0x24291ABCFA12C2E2ULL, 0x5ACABF75BAD71E9FULL, 0x2B8A82BA0D3DE0BDULL, 
            0xB8767D650E8D85C8ULL, 0x80A8F59FCA158CCBULL, 0xCA7BB35EC04E0D78ULL, 0xBA70C9E5550FEBB6ULL, 
            0x5DF896A7B85169C1ULL, 0x6D9CA18049059522ULL, 0x8E9CE490943554CBULL, 0xE441F5F9A36CE344ULL
        },
        {
            0xDCC6A1D027254F72ULL, 0xEC8004C9EF9FD054ULL, 0xBD6BD103A258E37BULL, 0x8872D9DFB45EE3B3ULL, 
            0x44CA33231D4E5999ULL, 0x0BC510FE63E04B7EULL, 0x8DE250407FE636C2ULL, 0xE67B1B668A92F9BAULL, 
            0x13FA314EFBC279B9ULL, 0x15791BBDE68FBA7AULL, 0x6F220A05DD856F75ULL, 0x2716739FC1C39126ULL, 
            0x315458D63E6671A6ULL, 0xD7A0A8A299F338F6ULL, 0x4FFA287D4FCAC8B3ULL, 0xBA6FD93B1E23C736ULL, 
            0x327FD77A6255F7A4ULL, 0xA2AF1DDC518394FAULL, 0x735FBDE2C20FC878ULL, 0x9118423AADB6EEC7ULL, 
            0x5990AE47E398FE63ULL, 0xBC6DF2C9EE5D702CULL, 0x89CB96E812B367FBULL, 0x47EE8630C4AF84EBULL, 
            0x121E600BAB012F72ULL, 0x57A4E3BC587ED366ULL, 0xC5162AA41C96EBFEULL, 0xF931D1C38F46FCBAULL, 
            0x7B68B12C71D9FBD5ULL, 0x97D4C4C852A6C21CULL, 0x67B8679F94A20334ULL, 0x12EFFA0D7E88F15EULL
        },
        {
            0x9DBF6FAA2B41280FULL, 0x93BEE057D5547897ULL, 0x40492FC3BDE3CE16ULL, 0x2B556ECAC0643C5DULL, 
            0x55DF1A831499BAFBULL, 0xC3C1EAEE2D94E631ULL, 0x30D7E647F9227705ULL, 0x9D9C12661D477898ULL, 
            0xABBB6C4B4F6DF743ULL, 0xEC348A9DD1BA5CA8ULL, 0xB03F4AEC1801945FULL, 0xF278DE68D5B4C222ULL, 
            0x69A167B0B17C55F5ULL, 0xE3076A738DFC4D5FULL, 0x1F6722116ED98F6BULL, 0xC5ADB901A91DECC7ULL, 
            0x5FE15F10AB919D70ULL, 0xADEA6EADBD3DFB5CULL, 0x219C80A82975B56CULL, 0x546B9F947EF55B99ULL, 
            0xDE29634AF36BFA0EULL, 0x6F5A03FBE4607B32ULL, 0xA07B07D203BF5A6FULL, 0x90CD98B020EBF10CULL, 
            0x14AF3780E7D96447ULL, 0x3D191B24384BE16CULL, 0xAF96132AD32D9ABAULL, 0x1C3D5B7E5747A66FULL, 
            0x23A85FC348FDB16CULL, 0x6805F43EACA162A9ULL, 0x6E19C9A7B8AD4706ULL, 0x11D023AF655475F0ULL
        },
        {
            0xF1980EB39DD5AB5EULL, 0x78B1A0F2E488A74CULL, 0xC88F4B9A84E93165ULL, 0x6E03F64325516227ULL, 
            0xC2294A1590CA3D79ULL, 0x11473B508EA69769ULL, 0x06D034C06B232495ULL, 0xAD8CA28166D3239DULL, 
            0xB22240857BCA5C14ULL, 0x93A2DF854D90B4EEULL, 0x3C62BB3E232D97F4ULL, 0x19C7255F923D688BULL, 
            0x9909790BE6F137BBULL, 0x5E4FAD610D3976BBULL, 0x7505F3961C4A1081ULL, 0x05F846EF515697A2ULL, 
            0xE4024CE58C36CBEBULL, 0x903AB0BAEA1EE30BULL, 0x87827D299872CDC8ULL, 0xA1949F98BD299D83ULL, 
            0xED387F0A996B59FFULL, 0xBCB6EC6EC41EE5ECULL, 0xD7918E7448AF9C3DULL, 0x37054D4454827BBAULL, 
            0x092040036A465CBCULL, 0x7F3DC198BB669B02ULL, 0xA5D98880A914B160ULL, 0x02BBC4229F287443ULL, 
            0x5F3C91A5B5B0182DULL, 0x50B9537C0995EAB4ULL, 0x39F2AFA30C886B94ULL, 0x99E0DA25E7ED8800ULL
        },
        {
            0x30823388D916F8DDULL, 0x73E5B190AD034843ULL, 0x8004F3253047253CULL, 0x4FEF0AE6FA3D5E40ULL, 
            0xEEA6AEAA149F3F41ULL, 0x13524EEA334BE7D7ULL, 0x96153B2DD084C7B9ULL, 0x59005DF00CDC6A8CULL, 
            0x723595D668AF7DCEULL, 0x2AE7F4A28FF8892CULL, 0xF387E161ABAC2F77ULL, 0x4F152EADA2801090ULL, 
            0xBBE72F650C7CD96BULL, 0x7511D80394FEC772ULL, 0x2D330CEE2C3563D8ULL, 0xEFC5B25A90307D40ULL, 
            0x004747720D666EBBULL, 0x19B85396E528912DULL, 0xCDB8F59AF8AB1FEFULL, 0x49897EB80BF8FBA7ULL, 
            0xAD5DF51B53D73F96ULL, 0xC5BD050240D769E7ULL, 0xF6AF57095C929289ULL, 0xFE05C0A5889CDB49ULL, 
            0xF8A934A14471AD91ULL, 0x62D8E745840BEA0CULL, 0xDF42F1C64991AA06ULL, 0xFA3560A154199165ULL, 
            0xC1B92BA31F6E4299ULL, 0xCDBB6E3E88789A8EULL, 0x5E4099D9EC0913FBULL, 0xD2D188B6A3472CCAULL
        },
        {
            0xA719B2567C7285ADULL, 0xA418488CD164FFF9ULL, 0x92C93D6A3976AB46ULL, 0x46DAA71AD3011C08ULL, 
            0xE573403C19FFC80AULL, 0xD9656977084D58F4ULL, 0xBB8B01A2DADB7C59ULL, 0xD63D76EF660FA9EFULL, 
            0xE08EA2B8787D114AULL, 0xD95738086BA213B4ULL, 0xF6F2431E3787F953ULL, 0xD0013F94E01D952CULL, 
            0xF40EA3D7D61DD640ULL, 0xF7FC68CB86B68D80ULL, 0x81B5C5E711580F6DULL, 0x270C4CF320DF944DULL, 
            0x70DF83E9306F78ABULL, 0x42343AFA3A799BD5ULL, 0xD6D948C10ACD99F2ULL, 0xAD488A0FF9DB2A95ULL, 
            0x583264E37590041CULL, 0xE670118C2D9C37A0ULL, 0x559684A0E884008BULL, 0x3B76B62109E7901AULL, 
            0xD442588B1749AB91ULL, 0x8F4DE485FF9534F0ULL, 0xBF48929C6F0E5136ULL, 0x268E70D192D2276CULL, 
            0x93DEA76F8C7B13F9ULL, 0x246304ACD2EE9097ULL, 0xD9C682370035A5ADULL, 0x339D481AE7586BD8ULL
        }
    },
    {
        {
            0x9BDF24FF80F876F3ULL, 0x8959243C3772E601ULL, 0x70B7AF5A7D194D3DULL, 0x1E35FF078E51802FULL, 
            0x570EFFC8984D63CBULL, 0x96B7F3CBDE33542FULL, 0xC756247134D33806ULL, 0x55BC0B59193DC29BULL, 
            0x1D7BCD1F765E2913ULL, 0x55DCDC7ACF662BFCULL, 0x07E54869B887A6EDULL, 0x7DABA4BA9F127E23ULL, 
            0x717DF5997EBFED1BULL, 0x5833A3327A566479ULL, 0x94CECC1A82469275ULL, 0x6A8BBA13AF2EA676ULL, 
            0x937825C43DDDBD6FULL, 0x5BC85286EBAFE2B2ULL, 0x981FF04B45E4F332ULL, 0x58599BAC43F0CB46ULL, 
            0xC547B017B139FDC5ULL, 0x7955A190546D1690ULL, 0x145FAA28BBA24377ULL, 0x0F692CED6F293FC9ULL, 
            0xACF9EADC16502AF1ULL, 0xF35EB51A4751E45EULL, 0x68F29D99B437F0C0ULL, 0x6D8CA2895AE5D485ULL, 
            0x70A04D3945BBC25BULL, 0xD98E78FAFFBB65EDULL, 0x1A1AF57C2E51217AULL, 0xCB78457026BA34D0ULL
        },
        {
            0x9E4C54D669C2FFBDULL, 0x5A7BE683E535E44DULL, 0x245DFC52C3FC5E9DULL, 0xF352C384241CB0A5ULL, 
            0xC69F3EAFAAF53513ULL, 0x0B4F8E4A7F2FBD46ULL, 0x02EF7A4C96CF0242ULL, 0x73B298645C154F1EULL, 
            0x2F30E77362996674ULL, 0x1E408E67E0241C44ULL, 0x64A5376691FF000FULL, 0x73B0520CB6CC1BB8ULL, 
            0xDC387853716AA6E6ULL, 0x19BD3ADDDC89E7C6ULL, 0x68B5200DCEE11C4DULL, 0xB0C885FE28D39F50ULL, 
            0xAC73684BEAFF6CAEULL, 0x4440E9D9B52F294DULL, 0x851B17556D389569ULL, 0x7D27448889A49340ULL, 
            0x33D3E0DBB740CD58ULL, 0x47331A2AFAD561ACULL, 0x9D32535ECB15B32CULL, 0xC91D5151CB4D6C86ULL, 
            0xDED7B200BD339E72ULL, 0xC5FF430AEEFAF1ADULL, 0x88FA174101E4C310ULL, 0x9293BC299C85B71DULL, 
            0x486582897AE45BDFULL, 0x3B8EAEC4B0EDA872ULL, 0xA363CA8640719407ULL, 0xCE861138D1544137ULL
        },
        {
            0x8E3428CB19F651FEULL, 0xBBE135239DAEEF61ULL, 0x729978B1E4E7DC13ULL, 0xCDD1B59BBCEE4313ULL, 
            0xCBD04DE901C221E5ULL, 0x9460B82D74C1647EULL, 0xE6FDB9C4A0274417ULL, 0xDFFD42CD07BB7C91ULL, 
            0x83D8286FF80EF950ULL, 0xB37FB06040FA39B8ULL, 0x1F1375A41E981C78ULL, 0x7286A8AF7FE5C4C6ULL, 
            0x3D8026430ECA389BULL, 0xBC3A4704B339D3C9ULL, 0x575F7AAA805059CAULL, 0x143D9F20260B994DULL, 
            0x17B15CCF247E67C9ULL, 0x19DDE80DB172421FULL, 0x91C95DEEC1EB8BFFULL, 0x9FE7988D326476DDULL, 
            0x75D61D74E1ECA3A2ULL, 0xB1CC344E5386D2D2ULL, 0x5C2D53DC258C452EULL, 0x2CA152A9FED2762CULL, 
            0x8600D4C259735504ULL, 0x3FB66CDDB0B9557EULL, 0x71EF3247ED6073CBULL, 0xB27875551BB4C8CDULL, 
            0xDDE831454DF493D4ULL, 0x3C13678D4A73B9F8ULL, 0x8E1113DBC57BB45DULL, 0x09C9D22803BA0732ULL
        },
        {
            0xDB2DF48927A818C9ULL, 0xDD01E1C137F0F988ULL, 0xAE24298054F51062ULL, 0x84EAFAC4F4600C27ULL, 
            0x41587A444F6334F2ULL, 0x5D4EE96DEF5CBD6CULL, 0x28CB35BDBF7FB424ULL, 0xC3601E1A966F174DULL, 
            0xB9B9D2332266EBCAULL, 0x6AEB1844B3C72CCCULL, 0xD921FC7A80525F2CULL, 0xF851FB7D310D55B2ULL, 
            0x3BD4E7C4A0C0CCE4ULL, 0x8141C89E212C5AE0ULL, 0x11E84BF653D9E096ULL, 0x18B74B8CF2200FF3ULL, 
            0x6D3A3BB91A225049ULL, 0x50D16560DBD694CEULL, 0xD31819279AD5C6F8ULL, 0xF4242C6F9912ACC8ULL, 
            0x7DC45FD45603AA8BULL, 0xD1A055B45B1BE927ULL, 0x811CA9A6D5DFE667ULL, 0x20CBECF844F9C51DULL, 
            0x6F6DF35A169F06DCULL, 0x7712FFD99281F3DBULL, 0xE99196263C23E2E3ULL, 0x4846ABE78925F5FFULL, 
            0x5B3C815C79BE21C5ULL, 0xA1D9F7B6B68DF0C7ULL, 0x58BE49CA8FF73871ULL, 0x524729E502A93407ULL
        },
        {
            0x8A9E06832E6B9D92ULL, 0x485A04EBC4B4FC3AULL, 0xCDD29C467E6B5E8FULL, 0x441917B9DCDE6F4DULL, 
            0x12B6D2A1250D8E47ULL, 0x1DA97A17EA501330ULL, 0x8BA9815B62E2F7C1ULL, 0x3D01185968DB131FULL, 
            0x6B78B31A90E9030EULL, 0x5FE88A532DD0B285ULL, 0x1B62D925988A16A5ULL, 0x394D5814548AB9F1ULL, 
            0xD04C844F9BFEBDBDULL, 0xF64F52151CE68D39ULL, 0x3E2A5B13C373D2FDULL, 0x7557BDE489AF9D4BULL, 
            0xCC6A693F1092769BULL, 0xAD36A993B00053A7ULL, 0xCD84137AC6125282ULL, 0xEB811595E02540FFULL, 
            0xFFEDF77BB6BCC9D6ULL, 0x25C42A7F1FFC72D6ULL, 0x1A0F0396ED24BB4FULL, 0xC890DD9AB464CDBBULL, 
            0x012231AAFB777B53ULL, 0x9FD02CCDE5880928ULL, 0x12B9D934655B76ADULL, 0x8DE7590700A6A9F9ULL, 
            0xBEFFE11252EED925ULL, 0x7B0BE6F234B436A5ULL, 0xEFB4E295D619C726ULL, 0x1B61DEB542AEA1ACULL
        },
        {
            0x5D3EA3BE33D250BAULL, 0x916BA5FC8622F6F1ULL, 0xD02EDEF734EA12F2ULL, 0x5F46F8CED2D7BA2FULL, 
            0x1E4ED1638A0F1926ULL, 0x0821483089AF7707ULL, 0x2221FE8BDC2ABA58ULL, 0x7C0FB89D26A929B7ULL, 
            0x83161B0A91994D61ULL, 0xC7CD7B1F744BA0DEULL, 0xEB2A58B8D4B181F6ULL, 0xC377CBEA53BA98D4ULL, 
            0x3913208C9EA8A3A0ULL, 0x2773068E812DD202ULL, 0x16AD5A06DB647FB1ULL, 0x74B8AAA9389E78F4ULL, 
            0xEF5EBB060C44CA33ULL, 0xB8CBE7A341DB0455ULL, 0x7448C465BCECC376ULL, 0xB729AF60DF2F31F4ULL, 
            0x950EEC9DB54A51CEULL, 0x83A93C4EA05F8791ULL, 0x526029344369D886ULL, 0xE6AAC699EBB4BC87ULL, 
            0x1EC66E116A693676ULL, 0x9D54DDF094D513E1ULL, 0xF923FE5C0A013C9FULL, 0x65A1E9B00DB2C227ULL, 
            0x59E61A031CA6C81FULL, 0x3B0D441FD70FD276ULL, 0x0687356541A759C6ULL, 0xB981422C33EB1DB5ULL
        }
    },
    {
        {
            0x8CEF9937E5FEF45CULL, 0xCC2A4B2BBE77AC6FULL, 0xE35404D7094A9A68ULL, 0x95A76CE89FC7E134ULL, 
            0x1FBD866EA4A3BA91ULL, 0x9462416D7699253DULL, 0x9D85A3D53EB14340ULL, 0x17EFE43C9F357BC0ULL, 
            0x61873CD99AECA918ULL, 0x644977F866ADD353ULL, 0x727F3BD764F7A4DCULL, 0x8E49B70F99F61B91ULL, 
            0xDDC9F9E7F0DA0ACFULL, 0x6528E48440564436ULL, 0xA576F6727E7D84E6ULL, 0x6E5F85A385E0BDD4ULL, 
            0xE39335E7D1AB14C5ULL, 0x3F69CF549B723077ULL, 0x8959C7D197596E1BULL, 0xFEE6F3DE176C200EULL, 
            0x3B059E2491C22A1FULL, 0xD9576AA0A98A2EEBULL, 0x2B23E2AB58684945ULL, 0x229D3F74174B15C5ULL, 
            0x80563BFC02CCC560ULL, 0x26251ED3452A26BCULL, 0x3FAC860F0F8318E5ULL, 0xCBB1C3240C142430ULL, 
            0xE83A0880CB20EDC5ULL, 0xD2461DC9F2208002ULL, 0xE83FDCAB24E237FAULL, 0x05D3178C397325C8ULL
        },
        {
            0x87F091C8CF20BB4CULL, 0x9A49857E042CB0D3ULL, 0xBA4F8AFD4784AB4AULL, 0x30683E47F90321B6ULL, 
            0xA42DEB070E7F5855ULL, 0xFAAEC863B298EA2DULL, 0x90D07A781E3F1D8FULL, 0x5B9BF88C1178A069ULL, 
            0x23DA0DC528DE34B3ULL, 0x3E1104866E61AAA3ULL, 0xB191D8BC62655EA8ULL, 0xFD6514FD51442911ULL, 
            0x842102E6613183CFULL, 0x3C6DEE869301FE46ULL, 0x564160034885D99FULL, 0x28E33B56A8B06F60ULL, 
            0x75D5EC30F806A707ULL, 0xE383D7E860B0D224ULL, 0xEE94064F8099F063ULL, 0xB906DC0036A89507ULL, 
            0x920F9EA47F297031ULL, 0x721BFED608EED65CULL, 0xBFE6F92771AE9419ULL, 0xE71BB44570CAB1DAULL, 
            0xD9BB7BEEB14337E2ULL, 0x7DC6A0C8D794DC9EULL, 0x8E7C9B8FADAA8A04ULL, 0x5AC7888DF425C0DDULL, 
            0xADEF8BA14C242CD9ULL, 0x0052660B5B09F5A6ULL, 0xF256D1BE3E9E2E78ULL, 0x8174F69623E4D72FULL
        },
        {
            0x7EE4A19DF6C6BEE5ULL, 0x94AD4E83A2CC263CULL, 0xEA21C548EA7E6525ULL, 0xFC69AED65AFF5F49ULL, 
            0x31344008AE239E7EULL, 0xDFD9D1693BF02ECDULL, 0xE39C2F12275B03CFULL, 0xF6D0B7E0B7F6D0B1ULL, 
            0xB461A58F1B155271ULL, 0xF2B385B865BD17A9ULL, 0xB05B8D05F46751C6ULL, 0xA584057ED8114443ULL, 
            0x375EA51E2BE15CDBULL, 0xD2E50E85E2D752EBULL, 0x9FB2A1F40580F4A1ULL, 0xF6E0EC2945FFC049ULL, 
            0x62EBBC28EBFE3561ULL, 0xB481DE77C1C5165FULL, 0xA6851D9A54E13BEFULL, 0x207B9DDA6343A4D9ULL, 
            0x868F35CA1B4D36D0ULL, 0x84A0828AF9BF8EFCULL, 0x4C4C7594D13905D9ULL, 0xBB3D69CC667527FCULL, 
            0x4C2C262F308D3BFAULL, 0x4D8B1C5A8D6E2966ULL, 0xC1870BB113496BA0ULL, 0xBC02CC739DF28AEFULL, 
            0xA3D74A8C2B97108EULL, 0x8ECC66EE97BEF547ULL, 0x165045BE4EBC63BBULL, 0xF2875A823526B97AULL
        },
        {
            0xCDC8D584DC3FEBF3ULL, 0xE64D3FA390F3AD8BULL, 0xD630EE541EA04546ULL, 0xA4ACE96F49F6B746ULL, 
            0xB024DAA30781C9E2ULL, 0x39F177E6B6CD05C4ULL, 0xE7836866D536EDA3ULL, 0xBB02DC31922663CFULL, 
            0x70CFE42C517AE6B3ULL, 0x2D1CF34F2C1F2D4EULL, 0xF9ACDE6E8C16A0BFULL, 0xF69B79ABB80AC370ULL, 
            0x0F960EA64544BA76ULL, 0xCC5B41DC4596A910ULL, 0xA1BD126B6662201CULL, 0x1DBFABF9719C913FULL, 
            0xF83228BD82D3BAD0ULL, 0xACB13496EC50146BULL, 0xEB16B3BC13955F97ULL, 0x7A6868D94A1BC17FULL, 
            0x74428F9576410E3AULL, 0xBE1A05FD906CFA74ULL, 0xC9572C1A48530A78ULL, 0x503982D43878485FULL, 
            0xFE90B3BFA6406A6BULL, 0x20280C8453512F74ULL, 0x0EDA809ECD6F8B8DULL, 0x5631B0937A6B4C94ULL, 
            0x01054AEC09571D15ULL, 0x127B4FDE93ADB3ECULL, 0xA7529CA94F0C1DFCULL, 0x1527BBA82B8A9C9EULL
        },
        {
            0x7A672F40FC12553DULL, 0xD92AB4EBCF499405ULL, 0xDC8DB65637C568CBULL, 0xD4F18399A01868A6ULL, 
            0x2D7C48EF422D2195ULL, 0x94EF57EEAEB6C622ULL, 0xA488A36A95759DC9ULL, 0xFC2B0A888B1DE6C2ULL, 
            0xFEBFB1720CD8583DULL, 0xD715CB61F4ED9F7CULL, 0x593DC5FFF3507406ULL, 0xFBEA46FC7BB8081EULL, 
            0x243A235ACEFE264FULL, 0xE19E0CBC00F809DAULL, 0x503316CE1D8B3C76ULL, 0x94959A44FC7AF733ULL, 
            0x3E5E77057B50FF0BULL, 0x67AF048990ECA80AULL, 0xD3EA36B6B6227474ULL, 0x22102444FD987421ULL, 
            0x72650B89785406A9ULL, 0xBBA5ED1F684E981CULL, 0xBB7EBA892D5BFF86ULL, 0x1C384FD7400117EAULL, 
            0x8592D45FB7398F00ULL, 0x4AEE1B41B83270FBULL, 0x8319C5E18AD38FEDULL, 0x1E63A384AAE55DDFULL, 
            0x8E1C206A74D5F50EULL, 0x741A546464DA3F96ULL, 0x9E25BF169519C185ULL, 0x2434DA2110EAF7EBULL
        },
        {
            0xD452D35439040925ULL, 0xF99A3E3E9DEE2FFFULL, 0x34891A0D99646E91ULL, 0x8B72BD609F0F0F83ULL, 
            0xE85CEFF3CB1E697BULL, 0xA7F354C6CC24EF0FULL, 0x4404294F693BE841ULL, 0x3A284800A6AC3910ULL, 
            0x0E36EA1A14638936ULL, 0x5FA5BDBFF4B3B4CDULL, 0x5031E555D8A087D7ULL, 0x54332B657E7D8E15ULL, 
            0x925FC4A6EE0C7FBFULL, 0xE25B633E63EAF7E4ULL, 0x8D28B1DC083D8C41ULL, 0x7D1321EA391F8791ULL, 
            0xA130AA07F9D63131ULL, 0x081D8AE9D1791990ULL, 0x3A42DFC35FA19CA3ULL, 0x3FEC056EA4C609C1ULL, 
            0x8F2DAC16D72A6163ULL, 0xBA1C9E18A007044DULL, 0xB4F2BE6CF9978A78ULL, 0x9CA23BFEA1051FD3ULL, 
            0x77428507617B0EAAULL, 0x0300D625DC984A5AULL, 0x6E1DA44B4974C556ULL, 0x8E0A8C556496EFBAULL, 
            0x379764B9B1C27DF3ULL, 0xC7424E9B6C0D7D42ULL, 0x0DE8028053DDECEEULL, 0x2F92FC1B7BA57CF5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseAConstants = {
    0xCD54A569A92210BBULL,
    0xEAE953D6FADCF70CULL,
    0xCA48898A78D3F2C1ULL,
    0xCD54A569A92210BBULL,
    0xEAE953D6FADCF70CULL,
    0xCA48898A78D3F2C1ULL,
    0x8980AB24CC4541FDULL,
    0x28A1A3B7BE22566AULL,
    0xBA,
    0x0E,
    0xAC,
    0xA5,
    0xFB,
    0xC6,
    0x31,
    0x19
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseBSalts = {
    {
        {
            0xF489A8491F520BD9ULL, 0xFFE656EA3CAE67E3ULL, 0x94CCE2D745140A37ULL, 0x4BA98317612DF50FULL, 
            0x3E6BABB02E90FF25ULL, 0x27B7D265C861BF4DULL, 0xA398ADF561E09A78ULL, 0xC348078D55CC64BBULL, 
            0xB0A47BB097736300ULL, 0xCBC40922C62D6BC0ULL, 0x4A80D1E152A98590ULL, 0x93DDD609B3F15836ULL, 
            0x0B6FA4DA15741242ULL, 0xE65655C6DD17BC83ULL, 0x33B4A8581586C2E9ULL, 0xF5D6AC915B98EBA4ULL, 
            0xD426A96A57BA9AA8ULL, 0x3DC8DF19468A6C3CULL, 0xD316DAEC516C8111ULL, 0xCEF21EC4F8D78890ULL, 
            0xB030D6660A03E214ULL, 0x0E6A3334739099E5ULL, 0x40CC0AD4CE79D640ULL, 0x3710E3DB87FE7AC7ULL, 
            0x4F594A968A7D066FULL, 0x342FBF9FE9DA0CADULL, 0x645234D1AEA64102ULL, 0x2F365DDA7E5B4E3BULL, 
            0x99369E5471E3FE9DULL, 0x2DA5DF999F47A75EULL, 0x264DB3CD19BC8FD3ULL, 0x44E6E837289FA0B5ULL
        },
        {
            0x506AA9BF3BD91AD0ULL, 0x688AC013C43B7BC9ULL, 0x49667F51C49B2808ULL, 0x2FBF541ACC325424ULL, 
            0x8FD97E9A76CC8A26ULL, 0x1829CF79DE315876ULL, 0x8A8CC76CF859D0D0ULL, 0xE532E5DEBBDFCE00ULL, 
            0x319761C35FBD4ADAULL, 0xDA2DAE42D4102013ULL, 0xB24EF72BF304ABD7ULL, 0x2947469C73C0823BULL, 
            0x629A5F52E178E3C6ULL, 0x7DB26A0BBAB3B5AAULL, 0x66EFFFC131277D03ULL, 0x8E56F699778853C7ULL, 
            0x65649597097396E8ULL, 0x3D399D50D3930201ULL, 0xEE8787112DC0D6A0ULL, 0xE077A6857BC79BAAULL, 
            0x0BB1AE59C4C7725EULL, 0x26DA7BC2F4B8F99FULL, 0xC93CBAF955246ACEULL, 0xF490F2767045F8F7ULL, 
            0x209FC506FF9CAD54ULL, 0x05A0650EC71B9F69ULL, 0x7E084CD54403C74DULL, 0xD0B04BDD2398ED89ULL, 
            0xDC54664E0D046D48ULL, 0x265DF885D8CF576FULL, 0x94F0760FF64D74EBULL, 0x58362F526CC7C75DULL
        },
        {
            0x7E95A982A33D375FULL, 0x5551CC856315D25DULL, 0x695C4E1544275FE7ULL, 0x8E5DFED4D2E97986ULL, 
            0xDF5856C1BBFA6AE5ULL, 0x0AC9BBBA67E0117BULL, 0xF2CCC7A433C9E61DULL, 0xE7EC4952E67238CCULL, 
            0x25F7E9DE6EDBCD7DULL, 0xD74B0906188E1539ULL, 0xAEC97576412017F7ULL, 0x5C32A9F1232840A0ULL, 
            0xB8BF6E16A5B1BB73ULL, 0x9A34B412E0CA7BADULL, 0x296DDA6A5E221E02ULL, 0xB4561C495ED4119DULL, 
            0xCB5BDE3702916765ULL, 0xAE15850AF0249D29ULL, 0x17457BE838C69933ULL, 0xE941B46374B92675ULL, 
            0x5CA2CBBC88566D61ULL, 0x1C12389AE948EEB8ULL, 0xD6E215CE707EFB39ULL, 0xC62B941F97E3FCF2ULL, 
            0x6E023672ECF1FE1AULL, 0xC32EAFF419A3ED40ULL, 0x4F7572984621849BULL, 0xEF38AD583131FFDEULL, 
            0x8D798190AA2602BEULL, 0x262214D26B36C2CEULL, 0xE88FE3B861005AB1ULL, 0xCE99963A234465F3ULL
        },
        {
            0xF36C99DA08FE9FE8ULL, 0x419D2873A9370D84ULL, 0xDCC701B8BDD1D9CDULL, 0x06544726165412BCULL, 
            0xEDF7AF5F96EF6FB2ULL, 0xC6E5CB7A2FF9B785ULL, 0xAC1EF3E4935ABD88ULL, 0x39B767AFA068E55DULL, 
            0x97A014018739A3F3ULL, 0xA1421FD0CFECB4ABULL, 0xFE8CEC0EC0886442ULL, 0xCDFE26859188EBCDULL, 
            0xB3FD8A1ED00F329EULL, 0xDFE1E69BAB104969ULL, 0x1EFD681C1FBC4871ULL, 0x5A2BC39627192C8BULL, 
            0x729E977739B0E78FULL, 0x46B14507B4E5E641ULL, 0x10DA48AC1604F683ULL, 0xBD2E4688D85A28D2ULL, 
            0x57BB5D48EB7064F9ULL, 0x2EAEA269E6B6545AULL, 0x5F30EDA9B118DB7DULL, 0x8E3804D06D34B190ULL, 
            0x4230066BDE6C1BA1ULL, 0x889CFCB28105A78BULL, 0x66805FFEC318413DULL, 0xF62DB2F5122F5884ULL, 
            0x7FE62F44F6754B13ULL, 0x3AC740E7F4BE2B41ULL, 0xC0859937B6278FDCULL, 0xF59EFD665B0A977EULL
        },
        {
            0x69B8755CC77518D2ULL, 0x4B13AFE578362421ULL, 0x60575B2E6A70DD53ULL, 0xDE1927CEE99195A2ULL, 
            0xEEFA8A5AD5FBB016ULL, 0x7AFA19C63F83F4C0ULL, 0xBCBB4D4D92BF2308ULL, 0xC525036D6AD581ECULL, 
            0xBE837273808AB2B7ULL, 0x7BB23E496689BBA7ULL, 0xDAA0B949B5FDF7A3ULL, 0x57B0DEC11022F4C5ULL, 
            0x3C2DF7C271908B73ULL, 0xAF88A362D60D03A0ULL, 0xEB5ECDE3BEFFA10BULL, 0x4C8D1CB0A17F1077ULL, 
            0x3A9CBBDA27C5FE7BULL, 0xF018E4D3BA2F4BD6ULL, 0x4E79FA10A01048A7ULL, 0x8B20608C1C899A77ULL, 
            0xDD83ABF24F5DA9A7ULL, 0xEE0823B0B7A65B7FULL, 0xF2572901B8F644F1ULL, 0xCADA7E863A1E92FCULL, 
            0x93E1A3980BA69E77ULL, 0xAE249190C09B2431ULL, 0xB879AB545D0FBB77ULL, 0x511EC5E7092AF5B0ULL, 
            0x63CCC9B5E32CE07CULL, 0xE88B38F505B7351AULL, 0xE8EDE315ED730224ULL, 0xC8493A0D838A67B8ULL
        },
        {
            0x0613EEF1248BAB66ULL, 0xD64E001DA085C13FULL, 0xB9A8808B2118B2EFULL, 0x1DC687C30BC993F0ULL, 
            0xC1EAFED2369F075BULL, 0x19D1167AE3209C95ULL, 0xF172871FCB31B3A7ULL, 0x7032254ABA15F53DULL, 
            0xC9B074CD4717C231ULL, 0x7A3152EC5A03A822ULL, 0x28F3CA51F3C209B6ULL, 0x2616F968FF6310C0ULL, 
            0xD799359271D16701ULL, 0x0E9680B4B0AF2BA3ULL, 0x9902D6215E36C222ULL, 0xB54314CCC3B5C745ULL, 
            0x8378AE27CFA91812ULL, 0x4053CF5ED1110E6DULL, 0x1ACE5D5860337C9DULL, 0x2499267FB002DA17ULL, 
            0xB494B5CE8869B0A5ULL, 0x1616AC367CD21150ULL, 0x20DCB5CFC5A9967FULL, 0x2DC0B1585D719373ULL, 
            0xE576D3D24A04828EULL, 0x5E49A19D5C1048E7ULL, 0x19B69D71EC16E255ULL, 0xEE34C6C7B5785250ULL, 
            0x5CF570FC359F0E41ULL, 0x202E37D8C2487355ULL, 0x67A24792FF94F0E9ULL, 0x841068A1773019CAULL
        }
    },
    {
        {
            0x3CB3666A25A0E30FULL, 0x2A702191FC832994ULL, 0x92FEB646F1640841ULL, 0xA77625BF38F9A8BFULL, 
            0xCB4E6B083C4E8851ULL, 0x45CE8149DC01F0E5ULL, 0x3D3343BD37284100ULL, 0x92A4F6E8C20A5EF0ULL, 
            0xD46C3B91217436B6ULL, 0xBFC91E113BC706F7ULL, 0x2C2B317A86B4D12DULL, 0x42BC9A92F4F304D6ULL, 
            0x545A3094F5832AF5ULL, 0xAE55DDA38E91F092ULL, 0xD70F0E2051B23FC6ULL, 0x0E82C4B92988CAD5ULL, 
            0x04EC2999A125E062ULL, 0x28B5A947DC6B5EBBULL, 0x154BA9946D15F234ULL, 0x4C15208A44602AB7ULL, 
            0xA50B8E3B116048F8ULL, 0x55F165D8BB281879ULL, 0x76CF4A2FD2F5ED64ULL, 0x9C996560DADCD320ULL, 
            0x513A6F31313A813BULL, 0x9BBD8DA88F9F80C0ULL, 0x29CDF8D0CD5B1D1EULL, 0xDC8515A31A75A201ULL, 
            0xF7FCC45BB7DA141DULL, 0xB5D3CB8DCEF4FB6CULL, 0x53866B0487016313ULL, 0x4715400BB6F6E66DULL
        },
        {
            0x956988BB1018D542ULL, 0x3478259C5420B22CULL, 0x03A5E66A07E2DD32ULL, 0x54DACE52FB4251F9ULL, 
            0x5F5071FABC8809EAULL, 0x65FE6A37C7A65E8BULL, 0xD2BD66917056F87DULL, 0x1EAFAA609E3F758EULL, 
            0x5C096C439255ED3CULL, 0xD77AC86DBF707C34ULL, 0x009EB3A47BD492B9ULL, 0x2876FD970BD60AA1ULL, 
            0x9E81B28673B012ADULL, 0xC35F4C5538E3FBA7ULL, 0xA3EF25E564408EF9ULL, 0x98ABA7CF3699A4C8ULL, 
            0x316152F54C34DB20ULL, 0x089B65F1605A27E8ULL, 0xB71682BF0FB34D44ULL, 0x5417DFECA150791DULL, 
            0x0215769938DE31AAULL, 0x1963A725B67FCE42ULL, 0x456BF1D018E241F9ULL, 0x46710CAC5E856127ULL, 
            0x9C3089BB23957A39ULL, 0xC1248868FB6CD8ACULL, 0x04236DABF7CF0022ULL, 0xAB44C9A780B8B348ULL, 
            0xA6985EED54460A83ULL, 0x2E5BCE18FFA76975ULL, 0x0C06772998D52085ULL, 0xFFCB69CE6150B9E0ULL
        },
        {
            0xABD781AC120EBE6EULL, 0x73E94FA1A6536815ULL, 0xB19FF54FA4EA228BULL, 0x5F9E9639AEFF43E8ULL, 
            0xFA342C38873E4173ULL, 0x19136274692D35B3ULL, 0x224F757A1C1F9454ULL, 0x0D6909749F9FED72ULL, 
            0x26E4FCE5234FC699ULL, 0xE4294B4EDF6C7854ULL, 0x7E6E00A6F99758CFULL, 0xE714E1F8CE4DA778ULL, 
            0x9B856713F41FD9FBULL, 0x910968BC9736E95AULL, 0xE5F3758C4C7C9212ULL, 0x977AC04BBDA7CD01ULL, 
            0xAF42D629D0F3C448ULL, 0x733D737C2C1A675CULL, 0xC1D5A0A563D02999ULL, 0x60CC64C974A2DABDULL, 
            0x73860B10C720ED91ULL, 0xF32FDF9E09309359ULL, 0x3D32C108A39C4AAFULL, 0x1DF19106B1798820ULL, 
            0x3FA549DD8D22BF25ULL, 0x015BCCC7B7F3E6DEULL, 0x06A708D464D7CB32ULL, 0x5104D2BF350CF5BCULL, 
            0xFF3CC69B7A0887B0ULL, 0xAC5FFD96C266E5C1ULL, 0xCA6C81B7B2A302C5ULL, 0x36C999AE4F17FDDBULL
        },
        {
            0x5CF07B3D8AC906BCULL, 0x14D64020061D4CBCULL, 0xD2B8AE45472A64C5ULL, 0xEC76F8F4E0F96CA9ULL, 
            0x755EF563C68F5B04ULL, 0xBCDB5C7E1D8618AEULL, 0xAEF10DA5F87A8B0EULL, 0xAE4E9F00348599C4ULL, 
            0xD0DEDEAB30FD184EULL, 0x8DB620CF2CDD7EE3ULL, 0xFB2E67D0186E1A01ULL, 0x3C8CDDF6DD1C6585ULL, 
            0x7B55D691E9CD97C3ULL, 0x59F6140596CB44A8ULL, 0xE813373026EA1438ULL, 0xF7506B363ADEEEB1ULL, 
            0xDEE605C2274745B4ULL, 0xFFD05BA5A4B734CBULL, 0x024D6033E8D5D158ULL, 0x3C425DC4A7C9A835ULL, 
            0x1187475086D92A09ULL, 0xD6E1786FED688E43ULL, 0xC1D1834485F6A6A0ULL, 0x569DC13F064FB40FULL, 
            0x9B4EB82B4D3FE408ULL, 0xACA233F505F7E4ABULL, 0x4556949532C2C706ULL, 0x980463CF1127CE59ULL, 
            0xD98581B163AD51A3ULL, 0x76E1E5EFE1541CE7ULL, 0x87443FA779AEF5ABULL, 0x50449C0936802200ULL
        },
        {
            0x07C56E53B5CD4E31ULL, 0x5B330FA1D4E076A4ULL, 0x59E7D7174D7DC8D9ULL, 0x70A074BDDB399C35ULL, 
            0x3B89FC39872BC468ULL, 0x817F66F76191A0D9ULL, 0x1916D857E1F44E06ULL, 0x08D993CACF0C8982ULL, 
            0xD83596A22FF6F01CULL, 0xF21889933C0730F1ULL, 0x45639E81241A00B2ULL, 0x0461E162A57D3F16ULL, 
            0x1749211849BA198DULL, 0x0DBEDE8E8B6754E2ULL, 0x4D87167D8DC172F8ULL, 0x11C706B46574FD69ULL, 
            0x35BECCF562C29E98ULL, 0x56A211C8B8420EF0ULL, 0x3615AD76BC9F8188ULL, 0x1F3CCB77828CD8B2ULL, 
            0x5D6E7BFD8277AB4AULL, 0x6083065F22E4A50EULL, 0xBE316068EA5340A2ULL, 0x8AB8B73A29A94A6DULL, 
            0xACD98EA188125DA9ULL, 0x28988903B5423FC5ULL, 0xA773C9A6806DC6F1ULL, 0x24808196A3457B31ULL, 
            0xDC936849DC77BA28ULL, 0x333439B107F447B3ULL, 0x40E4D2A6C14DCF84ULL, 0xF9F33B18D892CEBBULL
        },
        {
            0xEE1ECD6B40CDC0ECULL, 0xC3C982317D18F35AULL, 0xE18EDB2B5B3D24DBULL, 0xDB162DFD4B666FBDULL, 
            0xB9977C5C8BED84CBULL, 0x15540081E2016D1DULL, 0x190B8CF46907F332ULL, 0x54B9F45F32CB81CBULL, 
            0x9BFE124AF21E591BULL, 0x2B6F685AADFB180FULL, 0x907E09A7EA439A68ULL, 0x654113E51D983E0CULL, 
            0xD765B9B177B1B148ULL, 0xF0119DB11075DF3EULL, 0xF7BD50EA6EB8E2C8ULL, 0x393D5E68859C366BULL, 
            0x1725517F38EB2F15ULL, 0x97BA96EBFB582A07ULL, 0xD182F27B5493E2DBULL, 0xB4900734D4D9B14DULL, 
            0x8F28A24FF9426247ULL, 0x15F0F299CA7B7A0AULL, 0xEF3F94F8162751BEULL, 0x5766530E26654484ULL, 
            0xBF3CF66CEE41D776ULL, 0xE20D65E005FF0CE1ULL, 0x17A005BF136AA2B5ULL, 0xB40B5534F1CF6E66ULL, 
            0xAE457EBA24AFBF82ULL, 0xBE1C63B0C4610F7EULL, 0x48110E0F37F49462ULL, 0x8E55F92EBA9BF4C1ULL
        }
    },
    {
        {
            0x434AD5F253F3FD7AULL, 0x9B0639B35ED6180CULL, 0x52E974D549DF47F3ULL, 0x58496B4E4FC1E6D0ULL, 
            0xBECA15AFBD946993ULL, 0x465A6EAE8834F65AULL, 0x7E15DA56BD30B781ULL, 0x22C917E809574075ULL, 
            0x33BB1AE5B5F32831ULL, 0xFF522CA2807A735EULL, 0x2906A0D6A2369B88ULL, 0x862B1F67189EC5C8ULL, 
            0x9E9A6D3F48B2496CULL, 0x4C2E3272CEF2A17DULL, 0x65FF5BED3D509D96ULL, 0x017314243739A299ULL, 
            0xA29B3C7F42D94B42ULL, 0xCC33C130013E23FFULL, 0x033A17F313F7BBB3ULL, 0xDBB162435D4108EAULL, 
            0x370D69F9EF1FB7E1ULL, 0x66350BB75B203633ULL, 0x50A6226704031CBCULL, 0x15180DB6DBFC7D41ULL, 
            0x2999BC581A10A1A8ULL, 0x07C4315D9C2E21B7ULL, 0xA7B6016BAB13F269ULL, 0xB057A2517993C69EULL, 
            0x0574A1802DE23CDDULL, 0xF383D81B0AE65006ULL, 0xD87DC5E5DB7679FCULL, 0x59A4454BBD00741EULL
        },
        {
            0xD3DDCBC19BEACEE2ULL, 0x01A494DE6B4B8660ULL, 0xB1EC109FF138F8E8ULL, 0x12FF714737AC56DBULL, 
            0x7808E5496A5FF3ACULL, 0x3ABB512D1DAB8D70ULL, 0x6A7F7EF7C3E112DEULL, 0xAA393EB0FFE4E3F8ULL, 
            0xE666DD287FB1E5BEULL, 0x9C0D70A986D6049EULL, 0x948C7F8E248678B1ULL, 0xF213E71D0C2F7DAAULL, 
            0x6FA6FAE28B5EEEF7ULL, 0x1D10B4AF79D59AAEULL, 0xE686D55777573B3FULL, 0xEDF55566ECADAE1FULL, 
            0x075319A865CA90AFULL, 0x0B4415BD1CA14D82ULL, 0x034A5B4DB86E8385ULL, 0x328FCE985D3B9CB9ULL, 
            0xF69510A2486CE227ULL, 0xE6957FF546E86B8AULL, 0x5418214AC47A67B3ULL, 0x25799E49499FC50BULL, 
            0xAA82D6C6580AB68CULL, 0xBD0653B86FDFF438ULL, 0x2BF7747236AAED38ULL, 0x7050F642B0B8884EULL, 
            0xC5A6070F275A3D8CULL, 0xF82CDF7FD75B9E24ULL, 0xD35B78315F4039C2ULL, 0x4F988CAEFC282A1BULL
        },
        {
            0x750C60BE658E82E9ULL, 0x84D69D4C11409271ULL, 0x10A26E63C0B9820AULL, 0xE6594DB27FD19D2DULL, 
            0x218A9A8B4AE3B6B6ULL, 0x8DC36BEABAFCAA9BULL, 0xB0189B77DD293D8BULL, 0x75FFB0982D5B028DULL, 
            0xC21647679BF7D960ULL, 0xA7C1ADA1B3452BEDULL, 0x36397CD1B2D7FDC1ULL, 0xD3D8975AC8E8A250ULL, 
            0x5A2ACAB28E2FCE55ULL, 0x268577FA554867DFULL, 0x5BDA948776B43E21ULL, 0x3677E37FAFACCFF2ULL, 
            0xF063BC40293EEF7DULL, 0xF79E8F92A0C9EA47ULL, 0x07971B1E9EEC46B8ULL, 0xC80B95368E88317EULL, 
            0x04EB2E1037A3C541ULL, 0xC65E07A92BB284D9ULL, 0x04AB8B3EB4AC9625ULL, 0x7B45B069CCB81FEEULL, 
            0x96DE99EEE13048AFULL, 0x588292F51A2216D1ULL, 0x3CA6490A4D420A34ULL, 0x1D026C73E7F84B52ULL, 
            0xE67195FA7868EF55ULL, 0x139C89F48EF31820ULL, 0x095FD34521E712C9ULL, 0x1C3A762AD28F295FULL
        },
        {
            0xA162A99B6281FD9CULL, 0xD3A91744132EB7F2ULL, 0xE3698E9B4E9BC1E7ULL, 0xE3AFD4F4C7BEBD25ULL, 
            0x5BC655BA18D13B86ULL, 0x8C53222D09F34D60ULL, 0xD2B2FDAFB562C6A1ULL, 0x7131742E4D300634ULL, 
            0x42783753839475D0ULL, 0x1EE3608FF794B37EULL, 0xC942F0BB3B3A29FFULL, 0x42FFF5A5B1A489CBULL, 
            0x1AC8C21EFBF41986ULL, 0x405EC2BA8E0F5646ULL, 0x92E3E92C5076F3B2ULL, 0x5EEFC0F5DD264FE0ULL, 
            0xB5527E68ABD5E405ULL, 0x08494B9609A6648CULL, 0xA432579DF892BC4AULL, 0x02D52A6BE69ACB3DULL, 
            0x6936B9AF7CAB57E6ULL, 0x0D768D3EE07F2513ULL, 0x57E6A4556722D72DULL, 0x40A61B9A3E19DD1FULL, 
            0x69C52F4C9E65A404ULL, 0x0F4E0B6266081B37ULL, 0x8566A20924616B43ULL, 0xFE38772BDA4FBA20ULL, 
            0xADE453A0DC6D0A77ULL, 0xE08A792E31CB3E0AULL, 0x22735537F5BAC43DULL, 0x7EE93BABAAA0D219ULL
        },
        {
            0x2264CD9512E8B7F6ULL, 0x40E875827BEF5859ULL, 0xBB243EC78E286A24ULL, 0x588BF93FCC45EF63ULL, 
            0x213DB30F941CC1E8ULL, 0xD86D9FD8B03D3657ULL, 0x6564C3323BCF350AULL, 0x9515C833721F028BULL, 
            0x7BEBF995E2D05B31ULL, 0xD2374F8D7458215FULL, 0xEC77E1D89F8BE037ULL, 0x517B521186437629ULL, 
            0x1731E1B0962786DBULL, 0xBEBE1E6583FC7ECDULL, 0x0E1AAF65F94B2956ULL, 0x5072A13CB97D9862ULL, 
            0x6D540EDE26C1BB40ULL, 0xCB15F84722B42FAFULL, 0x6394DA13330A11D5ULL, 0x9208C542BFEB4D87ULL, 
            0x93035D71E63BB8B2ULL, 0x10E41D65B1E84671ULL, 0x5AC64578F9FF5BA6ULL, 0x7F1E8117DEC5FE35ULL, 
            0xD984B3010E891471ULL, 0x26D2C63A2E0A5936ULL, 0x58405C76056BDD1AULL, 0xD281681F351E7D4BULL, 
            0xBD194E61024A232BULL, 0xFED0BBE06A8E30ADULL, 0x5799FEBF0EB75735ULL, 0x2FD7469FAFACE0D8ULL
        },
        {
            0xD1CD8C7205C0AB81ULL, 0x4EA4703AC2E022B9ULL, 0x476C07E3ED21BCDBULL, 0x639F897A31565E95ULL, 
            0x439EB3CA00D88BBBULL, 0x7F0B86403EF537FBULL, 0xE380DDA6E10E214BULL, 0xD037C1B0FB6D076EULL, 
            0x52571410DAAC9B2BULL, 0x557F9B0E56F1C429ULL, 0x69F3BBD3938769AFULL, 0x7B91476B8F63CF90ULL, 
            0x7849903745FE79DDULL, 0x65CFEA0C305451F9ULL, 0x8D013095313DA88FULL, 0x6CA009F63D893050ULL, 
            0x56477818542A2F88ULL, 0x5301F0C03FD9B923ULL, 0xF02A37900C7A1FD5ULL, 0xA35BD59391580A54ULL, 
            0x78CEE96933EEDAE4ULL, 0x8CFD7F9E689FCB2DULL, 0x55FE88137A34C77FULL, 0xCEAEB78201802867ULL, 
            0x137B294D7D29FC57ULL, 0xB4DD4687C241445CULL, 0xB142EDD94F0C3B70ULL, 0xF01F0DE82CE39F13ULL, 
            0x687085A4F634495EULL, 0xD7787794A28FDF01ULL, 0x4A75D2181AFA1BA3ULL, 0xFA1CD5B7F751753DULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseBConstants = {
    0x4CB623A02D5781A8ULL,
    0xB0E19EC6B3CF68A9ULL,
    0xB865F21A0A2365D6ULL,
    0x4CB623A02D5781A8ULL,
    0xB0E19EC6B3CF68A9ULL,
    0xB865F21A0A2365D6ULL,
    0x3B2A1E9BC84B5740ULL,
    0x2FB61CED06B290E4ULL,
    0xCC,
    0xE9,
    0x7D,
    0x31,
    0x02,
    0xAE,
    0x8A,
    0xCD
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseCSalts = {
    {
        {
            0x71446DE17EEF2D49ULL, 0x90B633242F4F1D4FULL, 0xF00B665B65A4BEF5ULL, 0x2E9FCC6180A14AC5ULL, 
            0x1CF25412C0444FEAULL, 0xBCCD694514257FFEULL, 0x025D9E54BE81E249ULL, 0xD8B113E68C1B6A69ULL, 
            0x4E2F5B42B9E9379FULL, 0xB996757E7540622AULL, 0x0941DDEDF0F692A1ULL, 0x25DDCA728D9D1ECEULL, 
            0xF6A538208CF577BAULL, 0xF8760D9F8206F4C2ULL, 0xC3D3B3D24D94B2BFULL, 0x192AA3DF47F3E597ULL, 
            0xEC671419671586E8ULL, 0x86744782B9986FDFULL, 0xE80507D8BFFD066EULL, 0x4623DC0F1F5BEAFAULL, 
            0xAFBB812273C21278ULL, 0xCBC61F9A28CD2B7EULL, 0xD9F7F47E7D8F4FF8ULL, 0x8FEDA230789BDEF1ULL, 
            0x9066B35CBFD3A37EULL, 0x87315FA5F02AA554ULL, 0x2ABC1940946E43C5ULL, 0xE788C199D277C229ULL, 
            0x03C193DFD1A231C4ULL, 0xDA6D3601F94F2EDFULL, 0x98478318D9504662ULL, 0x6445A9E7D9959E3DULL
        },
        {
            0x682EFDD2E9F8EE4EULL, 0x3D80072A5B8AA31EULL, 0x80B3CD1DE3B91CBBULL, 0xFFED5EDEBB4C3B2DULL, 
            0x1171C984BFADB715ULL, 0x4DE86ED8FF1F14F1ULL, 0x171167CAE628EA16ULL, 0x2E87E9C413482EB6ULL, 
            0xF8D17544981AE5E7ULL, 0xAA85AF63C21A8391ULL, 0x636E968A2A36F0A3ULL, 0x948FF56BD2AA53A3ULL, 
            0x10CFDF0740EFA20CULL, 0x98801C2C01E10404ULL, 0x929241187C6C9FF4ULL, 0x96FDEFEC6194C3EEULL, 
            0x89E51DD9DCDF01A1ULL, 0x9F4C3B04C795BEE5ULL, 0xCF8C8827681C1114ULL, 0xA27A0CA3E2071441ULL, 
            0x7E905EB58BDF01F7ULL, 0x7C02905F1B4DEA57ULL, 0x0567A7E06862AC87ULL, 0x920CF572D1DC5586ULL, 
            0xA92F3413DDFCEB48ULL, 0x13E07F8E5256335EULL, 0x4C89785337E684AAULL, 0xE8EBAB0BEED59FF6ULL, 
            0x686EC0552302884EULL, 0xABF5CC98FB4E9C5DULL, 0x05F8D6D1BB14B1AFULL, 0x1F21237AEDA4C7FFULL
        },
        {
            0x62F97D19EC383612ULL, 0xB6A97F6ACBF28072ULL, 0x7CB7A2946CB365D8ULL, 0x8C3F3E670059D7CAULL, 
            0x0E6B578874E769E1ULL, 0x5D72A0731974C1E7ULL, 0x7B1054A3597115FBULL, 0xEE0BA8EA1A5B3D05ULL, 
            0xC2D72DF7314E9187ULL, 0x2B7C41B54C465EFBULL, 0x68BB3CA8FCB0F7AFULL, 0x33C1EEA3376610B9ULL, 
            0x57B52A6F5F1E27EBULL, 0x6586468B2E9DFA43ULL, 0xFF77A27D6696834BULL, 0x995A1B402DC0FAF0ULL, 
            0xE8FC8A47848547E9ULL, 0x55CD1FAAD3BC0ED8ULL, 0x06605363858AC149ULL, 0xF9042B2229AAA6B6ULL, 
            0x9963A1A6C3B80E21ULL, 0xD9323EA1FCF8D9A2ULL, 0x79122D2C280E51FBULL, 0x6F189A0D1FB32A71ULL, 
            0xF837A7C7AEE7E944ULL, 0xA2728ED6BB31AABFULL, 0xF1FFC0F71D559117ULL, 0xA86A2E6377194A70ULL, 
            0x642998E86CE9BD33ULL, 0xC689F9E430CA4CCBULL, 0xB453D296866FCA07ULL, 0x54540D92C6B467E4ULL
        },
        {
            0xEA62067ADA67524BULL, 0xB4B1EE8A196E34D9ULL, 0xF8C1B033E3AD8387ULL, 0xBA6568CFA091508BULL, 
            0xFD7EAD89D49F2E80ULL, 0x4E9848E191C2AF8CULL, 0xD6C5A2A808A56301ULL, 0x2B8842B3A0FFF87AULL, 
            0x228787E060A23E32ULL, 0x7BB2A9FFAAB926B0ULL, 0x930F1FF945DF7612ULL, 0x56159C889298A071ULL, 
            0x8F8EE702E5FE1822ULL, 0xAACAE8BE6A86B937ULL, 0x5281E0E028060869ULL, 0x2944B0353F46477DULL, 
            0xA3FDBA38C334D99FULL, 0xDEA18782417E9C1DULL, 0xE56F3FE6E7E256B6ULL, 0x7C7BE2EFF1EDDCDBULL, 
            0xBB87004523D31B31ULL, 0x9EE071CE4ED483ABULL, 0x8AF6B03A69D89E8CULL, 0xF4F3C0F48768153FULL, 
            0x64068BE8C5173662ULL, 0x68D3C8E49A2190EFULL, 0x4C600218E8C49E41ULL, 0x194383A6A6BD8A5DULL, 
            0x49C2BB881E788D8AULL, 0x965AE78642FAA65EULL, 0xEBC955080370A350ULL, 0xDECA50A448B486FDULL
        },
        {
            0x9CFF03B1466F4C1FULL, 0xEFC7464DF0F9245EULL, 0x278C15D6E6C6B137ULL, 0xEC653A0857ACD57CULL, 
            0x86AE0C53DADDF436ULL, 0xB8752AA4DA71AA1EULL, 0xD237C698CE262F90ULL, 0xFD746825BAC08D18ULL, 
            0xDFBE050B4225D471ULL, 0x7BAF0C3281ABEC50ULL, 0xD6EA4605AC8793B4ULL, 0x62E5C8918C021AE6ULL, 
            0x68DBDA88E136E83FULL, 0xCD5BBACB306066B8ULL, 0xEA64E4DB1CEFAEC7ULL, 0x6337DA5B8FFA9FC3ULL, 
            0x2CDCA6B9C795B13BULL, 0x98815F87B9A7BDA9ULL, 0xBEFE0ACA6C8E530FULL, 0x623864568BEA78DFULL, 
            0xF81314F411C8F148ULL, 0xB3FF3617EBEE2488ULL, 0xD202C5D76DA4F02FULL, 0xEC347871C14CBB2DULL, 
            0x3508FE511EDC0423ULL, 0xCB0F03C3BCC1388AULL, 0x4F83CA06322DB6C1ULL, 0x773B0AB9AFC805BDULL, 
            0xA9410B874ED431E6ULL, 0xD1BC539DB6E7902BULL, 0x0C3AC818EF04BA90ULL, 0x0D568692E83E34FBULL
        },
        {
            0x117C32E0D35C7046ULL, 0x0065FE2A90C26568ULL, 0xCB6801E7CEFDF8B7ULL, 0xA6A3219CB554B4A6ULL, 
            0x37529F43DEB80DFFULL, 0x373A502AC89064C2ULL, 0x550A28FBC15C9E34ULL, 0x79BE261D8AF6C566ULL, 
            0x18376546F7B92770ULL, 0x231CDD323C2797DDULL, 0xC44B79C88CF3497EULL, 0x8E90CC007624B6CCULL, 
            0x76761B6DE81F6713ULL, 0x1BA9776AEF2C97E3ULL, 0x9ABEB5CDAEC12ADBULL, 0x9A8F47AF29B4E9F6ULL, 
            0x864E51BBA5F69F73ULL, 0xB206F9EFC3BC77D9ULL, 0x8AABBF184DD59DCAULL, 0x67FF583BD76ADE0DULL, 
            0x4E50BE1A116B8558ULL, 0x99684C6B2CF8480FULL, 0xAC9F48FA391E1F0BULL, 0xC329D85AC6063F34ULL, 
            0xA2412C8F3A2D0F9FULL, 0x92808DDD1A6D5266ULL, 0xCA051CB7249CA8CAULL, 0x1B0666706197C528ULL, 
            0x32DA148AE3D9B510ULL, 0x882A031EDC437CE2ULL, 0xEACD846E83F49F38ULL, 0xFB1B98C9B3CEFEC2ULL
        }
    },
    {
        {
            0x425944658AD315C2ULL, 0x41CE243D417636A2ULL, 0x72ECAE0E83BF74E7ULL, 0x53F205864C853EC3ULL, 
            0x1EDB178C41006D50ULL, 0xF8CDF3E6E7297823ULL, 0x1A8522A8CFADC134ULL, 0x244F120E5805BFE3ULL, 
            0xBE46D397F1FEF711ULL, 0xD719120A2C4A5D7EULL, 0xA480927CCF13B762ULL, 0xE92C1337B762A9BBULL, 
            0x62823EF927096BE4ULL, 0x31AEC52A78F4D1FEULL, 0xD6CD704B0F768F51ULL, 0xFF5B5336C1172A5BULL, 
            0xCCAC3FF54A78D475ULL, 0x83B03DB19DDC8902ULL, 0xEA0860A6FFC0C2B4ULL, 0xA89F96BE5C903489ULL, 
            0x5BA64BBA346A1533ULL, 0xE7F336AD3CD37EFEULL, 0xEE6A80592F1F2C13ULL, 0x19ED6F094F2580F6ULL, 
            0x1FE32A0CE4BB9863ULL, 0xD6062CB7AF4C7C29ULL, 0xDA799A2F21DC0B9BULL, 0xEED0E5475EFB76E0ULL, 
            0xB461EA6C6495991DULL, 0x593F934100BA1B1BULL, 0x4F8A913C2B23A32DULL, 0x7531B3F04AE53479ULL
        },
        {
            0x9C5B7C5C7FC5EB60ULL, 0xE766710D63704948ULL, 0x76CE2A4F995A437EULL, 0xCA57E0A070FB7634ULL, 
            0xCE81FECDED87D8A7ULL, 0xA7FC8CC42C7910DBULL, 0x1671E257E9F0F02AULL, 0x62F8F474778172BEULL, 
            0x34C5787851204DBCULL, 0x312C1E1C53617EFEULL, 0x4B1BF5D37EB8A2BEULL, 0xCE00C601219D5B2BULL, 
            0x76D5CD6C2D2A5073ULL, 0xBFAFD8C074A1E194ULL, 0x199F916D6C938CDFULL, 0xD80540DBB1995F2EULL, 
            0xC123AB9C1AF1AB46ULL, 0x365F61D2796C4F3DULL, 0xA3561AB9A07A0103ULL, 0x34966E6B96FE22A8ULL, 
            0x2D4BDA164E712CF6ULL, 0xA3C3BEB5CDC945D6ULL, 0x5EC49F2D6844CD87ULL, 0xD2873EBBE75984EEULL, 
            0xAAB1ACF5F607F54EULL, 0x1C36BC6965061BBAULL, 0xC5325D08E76C69C1ULL, 0x93D0122D4C706D30ULL, 
            0x8FDA0BDB42264B8BULL, 0x5F5E5710B32B0A38ULL, 0x8BDD44C2EE1EF660ULL, 0x0FB596B4611681F3ULL
        },
        {
            0xA844CDD8996E2452ULL, 0x4F62777B846572C5ULL, 0xA31648210268FB6FULL, 0xF6799BC5C07A47C6ULL, 
            0x538D8D0AB2D0E2E4ULL, 0xD25C71552CB1769EULL, 0x1EE343DB49792413ULL, 0x75DE2FB39F64A3F2ULL, 
            0xFECF9FC92E493EA6ULL, 0xC9D9ECA2D8BF0D0FULL, 0x22CF6970DC9A3DD5ULL, 0x2E1BBF677EFE38D9ULL, 
            0x9BDC2774D9DDEB2FULL, 0xED3D6E50A245A71DULL, 0x324C2EC548461748ULL, 0xF9E43340FCC15F34ULL, 
            0xA128DA1FD063586CULL, 0xF94FBBE519CE09C5ULL, 0x74A2CA5ADAB58441ULL, 0xF43D0180B36D71B3ULL, 
            0x8F9B8177B267D3F7ULL, 0x135DED2DC7451482ULL, 0xEF1B53108563108DULL, 0xACC0BC5450C5C654ULL, 
            0xB76E56B3B37BFE90ULL, 0x9C11B35876A9F37CULL, 0x1156E6DBCD11C95CULL, 0x55FB954D53675453ULL, 
            0x5CD7CB025C87A3CFULL, 0xC6A228B42021520BULL, 0x910EA4F5A15E9DC8ULL, 0x97FB1450C32C65E3ULL
        },
        {
            0xF9F2E7510982A86CULL, 0x8C8681A895D9C984ULL, 0x9FED898725167ACBULL, 0x2D9AC214BD83F411ULL, 
            0xF9E62E1AC8410C10ULL, 0x324F4CD87086B6F6ULL, 0x35C709965EBB44B2ULL, 0xAA1CD1905ABF605EULL, 
            0x728F8BCACB56544BULL, 0xDD3DCB3C3A0D02DCULL, 0xDF0325278332CE6DULL, 0x37056EC4510D4CE0ULL, 
            0x5A03E4B1FB40FFF2ULL, 0x35B3F552DBE3CED7ULL, 0xF35C7F51B674392FULL, 0x8D504DB32AE8A473ULL, 
            0x4689D00D96B5D273ULL, 0x14B242D42EA9F2A1ULL, 0xF6FC14A482D969C2ULL, 0x6D96566851158A6CULL, 
            0x95B8DEC1B8D2CE8AULL, 0xABE04C9B9323CF3BULL, 0xA881D047FD69A20BULL, 0xC13B0090546D1858ULL, 
            0xFBAD47E2F48948A7ULL, 0x7ECF6B3ACC23E6FEULL, 0x0EB96BC997EA4850ULL, 0x2172E7578AC34BBAULL, 
            0x7C95758446A037D5ULL, 0xD9154168EF7600D9ULL, 0x96E06356313E8465ULL, 0x966812E664E12E90ULL
        },
        {
            0xA234B183DF20E0ECULL, 0xB11044A9DBB70410ULL, 0x34ECD500C9F9AA13ULL, 0x92E0240D49190F7FULL, 
            0x79C4DA5F06796CCBULL, 0x8ED431CAF750E6BBULL, 0x499B01820B956A37ULL, 0x6687A6E3D5139B24ULL, 
            0x2B94842AA9FEC95FULL, 0xD27528A615D9794CULL, 0xE4F3E84BA3EA9CC3ULL, 0xCCF64DED5A1FE514ULL, 
            0xFF25D80A7A10CA80ULL, 0x9FC26BC246423A93ULL, 0xCFBBC3817E8F434CULL, 0xDAE209B0D8E80FB1ULL, 
            0xC017357C90A91BB1ULL, 0x4482F7383BE7898BULL, 0x5C6CB848AFEE188DULL, 0x598D1BEE41F9593DULL, 
            0x62B195491AF56FDFULL, 0x6506D2A661E7CA61ULL, 0x07A7DD0DFA2A1EB6ULL, 0xC21B69494DA7B410ULL, 
            0x83F1D24B97E8D535ULL, 0x50F4061C4AB84FCBULL, 0xCE86679A10725CF0ULL, 0x33272A7DC0300E14ULL, 
            0xD2AE72A64CC02D50ULL, 0x529D4F660C580E8EULL, 0xD40EA5334945F3F8ULL, 0x2FA60591E80E9D2CULL
        },
        {
            0x77F6755F99C80FADULL, 0xE2B887E0ED6F68AAULL, 0x1AD6DB9343A7E74CULL, 0xFBBA1DF0BCA0B043ULL, 
            0x857DD9AFBAC7D781ULL, 0x994AE9C8FF6C879DULL, 0x62A3F439A5F5079DULL, 0x595B22D6A53FF55FULL, 
            0x83A8EF79C0181EB0ULL, 0x5F99D7CD0C2A8200ULL, 0x31775B56AB2B76B2ULL, 0x0905793A2F05E6A6ULL, 
            0x0F8FEE68CCDFFE51ULL, 0xDDBCCBE4C30E6195ULL, 0xC0B40F1CD80E7B63ULL, 0x662A86987A40CF30ULL, 
            0x24818F8895721453ULL, 0xAD2A651096983484ULL, 0x4B3D7F517CFF162FULL, 0xE1BD5062DB98416BULL, 
            0xA5BE0F4E125972CAULL, 0xCEC5DA09D99934E4ULL, 0x6C14DA6823A26CF3ULL, 0x7E40356AC538572BULL, 
            0x88E008A61232CC64ULL, 0x5FB8E3CF360C7CA5ULL, 0x1CDB48EFA63C03B6ULL, 0x152558864AE52ADBULL, 
            0x1647871D6F280EE0ULL, 0x57C64158B5A24DE4ULL, 0xB560D5C47FEC505CULL, 0x5EFAC4A5277CBCA6ULL
        }
    },
    {
        {
            0x8CF667C78D44A492ULL, 0x027BAA6DD2973AD7ULL, 0xFC2041825BB25AD1ULL, 0x53BE30DA27F025FAULL, 
            0xD6519BF28F7559EBULL, 0x16BEBCEBEB8B42ECULL, 0x035ADF4E6078B447ULL, 0x7481F00C4741E269ULL, 
            0xB930C29A16FE2EEDULL, 0x63C9F2EA8494A9FEULL, 0xA4008A82A5AA225AULL, 0xCCB9F7F20E126599ULL, 
            0x5C179480CBD14E9EULL, 0x92F44B05DC76D8D3ULL, 0x567EBA7B8F726E0EULL, 0x35BA840659555D62ULL, 
            0x0AE684A4B72ECD0FULL, 0x33D2F3B1A828CBE8ULL, 0x504406B50191AC5EULL, 0x148D6381C5782413ULL, 
            0x6BA28A47FB98B16BULL, 0x0A6BB907FFC70AEFULL, 0xB176D3B543AE2A5DULL, 0x9D366B634FD5BF84ULL, 
            0x651711D8E3EEC69EULL, 0x347DBC9B97DF10AAULL, 0x8A3585864A43EEC4ULL, 0x9783EF033373E2B8ULL, 
            0x049D97E32C4D3C6CULL, 0xD5D79666243D724CULL, 0xCF3E0FBFF1B66698ULL, 0xB9FB2AB702614970ULL
        },
        {
            0xBC1744774DB92B6EULL, 0x83242B4F1241FE06ULL, 0xF7759F259588369AULL, 0x6304A04EBCB58540ULL, 
            0xDA179CB70F0A6204ULL, 0x2B0117D70D71E4DCULL, 0xD348CC29B4EFDA76ULL, 0x53BCEAFCB353A92DULL, 
            0xABB27D77F4D601A2ULL, 0x0FC94A90466F6414ULL, 0x68FB4A030A1B984EULL, 0xED96BE6AFE583C9AULL, 
            0x7A8A5BFA732F7FAFULL, 0x9CE07ADD4E788206ULL, 0x8EE858A2458591BCULL, 0x275B0AE2F3B67B9BULL, 
            0x9BA69E350EF47DF0ULL, 0xD42A3667F23E4F9BULL, 0x1731CA3EB09340B9ULL, 0xBD65E3D1B09E5BC8ULL, 
            0x168C4A54713A0F4AULL, 0x3C1337777CC27868ULL, 0xDCB96FCA53673932ULL, 0xF5A4BBBE7C6DAAAAULL, 
            0x79FEC24536812B06ULL, 0x479EF80E96DFBB57ULL, 0xDF21790810BFC7BBULL, 0x52B8E7A43FA7F915ULL, 
            0x37FB2AD22E8CBA5FULL, 0x00DDE978E4F58A8FULL, 0x1E1F2070DB47CB06ULL, 0xB1DC3C97A09DB13BULL
        },
        {
            0x1466C77C50C57CBEULL, 0x5988F00ACA39FA56ULL, 0x998B9DA6A909D87AULL, 0x9EAC3E3BF2301B9EULL, 
            0x1469D8FAC2AB4A50ULL, 0x5F2A1B706D6F4E56ULL, 0x4EB439BECEDF7865ULL, 0xFD408B79BA9D827BULL, 
            0x6D5F2B318ED6C389ULL, 0x0522CC1A61A9ADBDULL, 0x514BAAF2FB60CBC9ULL, 0xEBF95CE5A8720EADULL, 
            0x3244188BCD6AFC2AULL, 0x2AB46F2CA55A1B7AULL, 0x29B9658E65767630ULL, 0x9A98ADCE61EB845EULL, 
            0x3B6A9514EBE9CC7BULL, 0xF618EC1FD6EA1130ULL, 0x524D573031F8E76DULL, 0x62B84B7BC5E36C34ULL, 
            0xA13F90E0E0D9385FULL, 0x58363F941C799324ULL, 0x9B5371770BCD4A62ULL, 0x83C8CDD50ADE6510ULL, 
            0x86CDEA9B0E93C1EFULL, 0x807897040413E02BULL, 0xEA491A295F0379F1ULL, 0xA0B2B4C2BBA1BB6CULL, 
            0x83D31F5A65FF87F1ULL, 0x017C0B4E93169DA2ULL, 0x6DC1497A2582C2E3ULL, 0x248FD4C83914D919ULL
        },
        {
            0x6667FAB981AFBE2CULL, 0x5761EA500D34EC42ULL, 0xD2EEA1EA6DE983ABULL, 0x3FE7E27F75317D1BULL, 
            0x45A4E87799B3DB4FULL, 0xCF68B907EFD36C95ULL, 0x5A4C8623687F73E1ULL, 0x5001DD35ED8B0F92ULL, 
            0x8032C9A42855AA2BULL, 0x75DC2280C252AABCULL, 0x1FA38BAE860B54BCULL, 0x626B5F2D17F072A7ULL, 
            0x0A277D322CF19F84ULL, 0x062FCD50AA5400AFULL, 0x8AF23E177162BBFFULL, 0x41212FFC0DDEEECEULL, 
            0xCF11857F848F806DULL, 0x8734F0D547FEB86DULL, 0x652B0FFC5419BE4EULL, 0x6023B39875AE1396ULL, 
            0xBB70FDCD7C00E8CFULL, 0xE4D26AD84A0D2D12ULL, 0xBB68CFC08F26FD18ULL, 0xD5EC1D00D28BC76AULL, 
            0xA774D24BC4958FD4ULL, 0x7566060D5DBF4AD2ULL, 0xAF00AE8902D358E8ULL, 0xA19ADC4D816425ACULL, 
            0xACB7D7A33FE85AE8ULL, 0x88B47FC0EEAC12BEULL, 0xFE094E6F36122946ULL, 0x92553C5A57A88A8CULL
        },
        {
            0x0CC53B5A131B6531ULL, 0x8714817A5E274F05ULL, 0x57667445440C4733ULL, 0x8B62635DBE16AE35ULL, 
            0x43CDB050A9A4A0C4ULL, 0xC5E236C33443DE2BULL, 0xCDCD6A12D11C9385ULL, 0x08512717C47F7838ULL, 
            0x2A924E835769C6E5ULL, 0x1E43746685C4A08DULL, 0xD634ABB0E0F95A3DULL, 0xC7806C28161DD9F3ULL, 
            0x49FD4F520EEE8D62ULL, 0x18858B5EF2A0A07FULL, 0xADA99C0F600B774CULL, 0x2FB2EDA84C3DB554ULL, 
            0x72BB8F4DC1D8488CULL, 0xCB41BCDA930FF009ULL, 0xCFE54097583BCF16ULL, 0x343162EF555BA6C2ULL, 
            0x54132732E3A97355ULL, 0x66D655CD5C8B8E5FULL, 0x39E20646B10C09A0ULL, 0xD87A68668951B635ULL, 
            0x5FB268CDAFD6F793ULL, 0x3220B58383C5C6B9ULL, 0xFBB4B0650AC44370ULL, 0xE7CA8FD900169CADULL, 
            0x4ACCFF1105A68C20ULL, 0xBDD67142F38262ABULL, 0x459FC8B492EF1BD1ULL, 0xE8B3A884896376E0ULL
        },
        {
            0x805F2579C2D62B24ULL, 0x7D2CE9116F4A1BF3ULL, 0x591244A928C5AB17ULL, 0x25D0B9FBC39CDF91ULL, 
            0xD495CC5534CB399FULL, 0xB10161470559DD2CULL, 0xC635C621F89D5F7BULL, 0xDD55BB56BF2A88F3ULL, 
            0x1AE2506CC42AA8C6ULL, 0xFF7C545571678BF5ULL, 0x3B9BAAFC9B2A2D6DULL, 0xED980B163CDE2BA5ULL, 
            0xA6B13AF265EB3192ULL, 0x46C90651963AE2A0ULL, 0x8E84C840BDFEF246ULL, 0x5F1555C8F133C3E0ULL, 
            0x7F54BE6B875E0BB0ULL, 0xD03350EE032EFDCDULL, 0x1EF2E0CA20B1BE63ULL, 0x7A19AA0115FAAD87ULL, 
            0xC3A6971C99B51BD0ULL, 0x1612ABC44FB2D15AULL, 0x30C38F56A6738C16ULL, 0xED442FC966C8F8CEULL, 
            0xABEBD7500FEC5C02ULL, 0x1DC5DC23EBD52040ULL, 0xEFC57DBC1FC41A0BULL, 0xC94F3EE2504017BBULL, 
            0x17FC46C73FB39856ULL, 0xEAF6417E1690463EULL, 0x97074F5E63690FCDULL, 0x0B413F07DDF57083ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseCConstants = {
    0x8D3BFC0815CC293FULL,
    0x2242EC31B080F5DCULL,
    0x50E3FE33709B7989ULL,
    0x8D3BFC0815CC293FULL,
    0x2242EC31B080F5DCULL,
    0x50E3FE33709B7989ULL,
    0x561D8E3C214309BCULL,
    0x9D38755608D72114ULL,
    0xC5,
    0x56,
    0x36,
    0xB7,
    0x43,
    0x89,
    0x6E,
    0x03
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseDSalts = {
    {
        {
            0xDBF6C047DFAF44F7ULL, 0x3718114294A30C1AULL, 0xFFCB82247DA38FFFULL, 0xCB144C618AE14413ULL, 
            0x7184942ACE670238ULL, 0x0D333058C2E0787DULL, 0x44A9D764A5980571ULL, 0x06A5512FB0B12BD2ULL, 
            0x0422E48249C34A52ULL, 0x6FBD4BC5A3952383ULL, 0x995BE0D761F332EDULL, 0x260B66410D6DF0D4ULL, 
            0xB0360A7DA58DD865ULL, 0xE558DCDFF8F40CDAULL, 0x152E627EAA10FF30ULL, 0x68AC0AFB19FBE97FULL, 
            0x4EDBD9A6D7788118ULL, 0xAF450DADB94E8FE3ULL, 0x6D35FFD5A07894B8ULL, 0x2D84717AD3255E90ULL, 
            0xB13FC65926CD7D3BULL, 0xCF226C82FF83F997ULL, 0xCF1877DEFE3BBC76ULL, 0xE38ACABC9DB68A6AULL, 
            0xA2C5AFC562676F96ULL, 0x0A35269E62804B8DULL, 0x69DB73AEBE5A125EULL, 0x0CF995BD651A4CD0ULL, 
            0xB1352A9B665EE189ULL, 0x9668F2DE49F78ED5ULL, 0x29FA11C0A0D1E7DAULL, 0x825CBDF4674417C7ULL
        },
        {
            0xA1FE21B99229A65DULL, 0xBFFB7F31996F63E7ULL, 0x52AE627D37C711ABULL, 0x2C3B789BE8544638ULL, 
            0x4DFE3A7614398F84ULL, 0x9BF0CF0BB9B54D35ULL, 0xD5CBD0D512203D6AULL, 0xEB1283AC3B555F63ULL, 
            0xA2AFB53ECD0AD07FULL, 0xCFFC95B6A79EF229ULL, 0x6CE681379031F35FULL, 0x5439E986FA8B5D4AULL, 
            0x6FEA07F86258E0DDULL, 0x0371A90C4E6215B8ULL, 0x609FD15FF1AC7A72ULL, 0xE321F189BB8FC2CEULL, 
            0xFBF3DEF3FC30461EULL, 0x570FAA4B7F4BEEF3ULL, 0xFBDED0BC611ACC33ULL, 0x676CE60A62185885ULL, 
            0xD1980747F1C4D16AULL, 0xC46D3B45EEA82612ULL, 0x76D7AECA0F2AC7DEULL, 0x923C0E6B2F119F3FULL, 
            0x8C540A02F5471252ULL, 0x3E7349FCC65ED663ULL, 0xC90713E951E2EF4AULL, 0xCA31EDBEEBCD43E9ULL, 
            0xD16F6FFEA01DED4AULL, 0x02A77DFB5F6C23B9ULL, 0xF3BDEB1EEE5B485CULL, 0xC6264C541E0C5D7FULL
        },
        {
            0xC88FFC740B9CF7E9ULL, 0x94F6C7085B8B9D98ULL, 0x528C662A50825D8EULL, 0x6B82DDB02562F200ULL, 
            0xAB89F12CFF2AAFD1ULL, 0x1ED6292D3EC62C4EULL, 0x5DD8F70CBF8316FAULL, 0xBC5E6162A6ECB9DAULL, 
            0x72CB30AF33B91730ULL, 0x283A438DF47C5FD1ULL, 0x7DA143EF02C66598ULL, 0x0362C0C26FFF4A44ULL, 
            0x580012F947119E93ULL, 0x2F16E82AFB100C6AULL, 0x0F871E0684FADDBDULL, 0x361F9F0F64BE046CULL, 
            0x2632D5983CD9E68DULL, 0x3133CE6BE806B748ULL, 0x7919CEBE860CBB1BULL, 0xA97AA48910BB4CB1ULL, 
            0x60163944C3088CF1ULL, 0x8DD53005D3E8A2B1ULL, 0x1B0CBB18FCB9A06EULL, 0x6AAAE96B8CE014EAULL, 
            0xAC30580DA4772910ULL, 0xCC067196B1B7625FULL, 0xE5EC5F3578FD5A90ULL, 0x9D6FA2130A5F3152ULL, 
            0x491796C6FB383365ULL, 0x7E6DEFCCCEBAA5F5ULL, 0xA0B6CE095A57834EULL, 0x93F61A2A7C918D1CULL
        },
        {
            0x9D3D73D927616743ULL, 0x64EECE2025A33D52ULL, 0x6FFC0DF480429547ULL, 0x4EE246E3FE9F0DC7ULL, 
            0xD8B0E52A03BD7E0EULL, 0x7DD193FE1C2C5BF8ULL, 0x8B6FEA0C4BF984DAULL, 0x3DC635D268AFCE55ULL, 
            0x681D2B08B69D07E5ULL, 0xD45E117C49C1EE05ULL, 0x19B0E4ACFD23D923ULL, 0x950AEC330782A265ULL, 
            0xDF6943A583023619ULL, 0xB8AAE7CF813F5F42ULL, 0xB11782E221C6BD46ULL, 0x74278182A04425C1ULL, 
            0x08A9E91EB67C907BULL, 0x6F8985CA32905C59ULL, 0x6FBD03D8E57B4C95ULL, 0xBD5F1A3FF983C030ULL, 
            0xC813E2ADCFD7D56BULL, 0x8A3C024804DE7889ULL, 0x0D595006116E81D9ULL, 0x7E575CCC5005A879ULL, 
            0x57962C052BA087D8ULL, 0x98BF4E45CE7F85F8ULL, 0xFDEDCCDA42E27A9AULL, 0xCF45A3A716EEFD92ULL, 
            0xC25C1726FD8D3996ULL, 0xD6A96CC06C19838CULL, 0x5028129CBE07D9B2ULL, 0x4D27C1AD8FBA0D17ULL
        },
        {
            0xB338E59FD2ECC5E1ULL, 0x3EF9F9C7165816BCULL, 0x5858445E3A4610CBULL, 0xEDC36EA33BF9C930ULL, 
            0x97A894FE9A282EA4ULL, 0xC7B7821708587E88ULL, 0x3E4B0D0F96F7707BULL, 0x13BCEFD2B00FB7A7ULL, 
            0xF6F497A119A06695ULL, 0xB50F03E8CC1B814EULL, 0x46EACCF6FCDA4D29ULL, 0x04E9D9DE8767C876ULL, 
            0x0F7CD2AC7C40E6D6ULL, 0x5C9EDE949E641639ULL, 0x5BA96FF0335A8EB2ULL, 0x408D677370D2C10FULL, 
            0x12F2E2EC3E3A578CULL, 0xB8483B567D2F914DULL, 0x1757EF6CED49A8BDULL, 0x34F9065D7C844924ULL, 
            0xA2D09A71A6DB2284ULL, 0x1A803449D550EE8CULL, 0xB5E5D576B125E2B1ULL, 0xC609487855D40B3AULL, 
            0xD8A0A2202FD5B26CULL, 0x01E7A13B90F989DEULL, 0x40B8B4AA301ED8ECULL, 0x8E173B97AE0C8B78ULL, 
            0x46079A8E88B9E0C7ULL, 0x096FB10D9AE01077ULL, 0xCB982AF2834537A3ULL, 0x5184BEC426893B7FULL
        },
        {
            0x4BE4CDD8C337D02EULL, 0x7AC563CBB0F15847ULL, 0x2F882B1338F296FEULL, 0x76079404CC7B2816ULL, 
            0x4B7D3B34E28853DDULL, 0xAEF4A69A2B0648C9ULL, 0x06B8CAEE365E6C2BULL, 0x76936A361CCD94FEULL, 
            0x9F98AA22B40356C9ULL, 0x8F827A77D3C43FC7ULL, 0x517F9DC089B8B28DULL, 0xB6D0377A92C8E959ULL, 
            0x7CCBEBA9EC14F4C3ULL, 0x314699AB2BC5F461ULL, 0x36D27CFDB963CC71ULL, 0xA7396F90603A1262ULL, 
            0x9F3FA888682EFED6ULL, 0xAE349CD49CCF66E6ULL, 0x9BC5D15A84DECAEBULL, 0xF6B832CB2A23B435ULL, 
            0xBEED98D5DF0A7268ULL, 0xD81651DDB9CA2EE5ULL, 0xA89F873C83E0709BULL, 0x5D1E8A0361CD99B6ULL, 
            0x4D4EBF21B0891FF0ULL, 0x273508D2274077ADULL, 0xB378C4907B4F1707ULL, 0xBE24FD82D2461617ULL, 
            0x81088B520BE56DD5ULL, 0x218DBCEF4020DA57ULL, 0xC2FA8F923BB737D3ULL, 0x314A91033632BB90ULL
        }
    },
    {
        {
            0xAC8D1C1A5611E458ULL, 0x0F7011E204E82AE4ULL, 0xF4C1EAE6B93A5319ULL, 0x5D72137B7845A845ULL, 
            0x3519FA1CBCF61378ULL, 0x3899835515F5C5ADULL, 0xDA381A540CE7A466ULL, 0x97B28CEA0B2AAAFEULL, 
            0x2493F110210A3170ULL, 0x16FA9E80331634C7ULL, 0xC8E54E85CD28B08BULL, 0x28476E66B81D6ED4ULL, 
            0x58F2A99DC35DE585ULL, 0x445C5D3B45949C4AULL, 0x4F326D2F61D1A22DULL, 0xE68B847CE0B8C750ULL, 
            0xA597C8121F6C6273ULL, 0x6DFFAFB44CF5242AULL, 0x937F6CF7874347A5ULL, 0x3CC0715E949E5598ULL, 
            0x08E6DA20AFE6509BULL, 0xBDAB9E8CADD3613BULL, 0x6A37A5A2C0CF133AULL, 0x66EA09075E9CE739ULL, 
            0x848E2192B505F988ULL, 0xCA94E82995AA2720ULL, 0x04F2A8D941A2069FULL, 0x8684D79CEBADECC5ULL, 
            0x7EEBB580C62D9F00ULL, 0x0E0CE5198F4D83A8ULL, 0x9F828FC0DE37D0A7ULL, 0xD3518B26053084E2ULL
        },
        {
            0x20541C7134218AB3ULL, 0xBA36EE9CA347D1E0ULL, 0x17B406FEA2A8311EULL, 0xCA05EAFDB2F42438ULL, 
            0xB242FCA2A02D00ABULL, 0xFC31A3701652E723ULL, 0x82C45AD6E98B0064ULL, 0xEB0C73935624DF3AULL, 
            0x4E9C0809283ECAF6ULL, 0x9030BB9D240C747BULL, 0x9F7AB8E45B2190FDULL, 0x799B215FDA606E97ULL, 
            0xD36DCE0F7CDB63B1ULL, 0xAEF8DA20BE4F5084ULL, 0x2303AB3E7F93A035ULL, 0x08B52BA7A4DAF1EFULL, 
            0xFF9DACAE57CCF348ULL, 0x32E61F9DF0582F68ULL, 0x46CB62DC7C835302ULL, 0xA9F5755344D24012ULL, 
            0xDBF559998F6A14F4ULL, 0x5C1698C6F5058B3DULL, 0xE7957E6CA378591EULL, 0x7DB510B7746107F3ULL, 
            0x0A5E3A3769F348BCULL, 0xFAC421C14D88AE75ULL, 0xFA2A2ACC63B088D9ULL, 0x5B8721C4E710519AULL, 
            0xC156B944254BE272ULL, 0x358EC59FAF54BFCDULL, 0x64020799795FE941ULL, 0xE52C1D292935905DULL
        },
        {
            0xD2C9997BCDC3D191ULL, 0xE716849C355A432CULL, 0xFE8490DE04D99CD5ULL, 0x34A867FF1DFEA0D6ULL, 
            0x810D4271E5DB7EACULL, 0xA963E4947302D152ULL, 0x75FBD97BE7CE8FFBULL, 0xB7245BDF60FAAEFBULL, 
            0x2B9C367F47B1BB31ULL, 0x6E12BBC8F018DDCDULL, 0x1CDFB33DD9F73A62ULL, 0x76BF5AAF7AD39BCAULL, 
            0xCD98A551AF9A4E3EULL, 0xD35555EA0220D610ULL, 0xEB156AC2A1E149B6ULL, 0xB14A754B1B0B5433ULL, 
            0x5C1394923B189E51ULL, 0x36F8F81CC7A43B6FULL, 0xCF74CC80FF056781ULL, 0x2666696D9F50EDF7ULL, 
            0x2AD2C8D42400288EULL, 0xBCAEF1B991FD82B8ULL, 0x2EECF053D1236098ULL, 0xC05348BB9DE450F2ULL, 
            0xF5A7CB826E7EAB57ULL, 0x82A951A0031CD6CFULL, 0xA259DB992BA728ACULL, 0xA4420B28D2D4B890ULL, 
            0x75756DAFE06A594BULL, 0x3C1BC7B920BBDB24ULL, 0x16B900F40F2E824DULL, 0xBD6B54B3AF75C6F5ULL
        },
        {
            0x896542292DA595CAULL, 0x9C1EAEF23E035F87ULL, 0x3CD57D204F378C8DULL, 0x20FE9A210ABFD908ULL, 
            0x55ADDC13B3079D40ULL, 0xB21FCB612B54840EULL, 0xBD3AB8D37076EFD3ULL, 0x35C31E390F83A7ACULL, 
            0xBF64E01618510BB1ULL, 0xA1DD8F3C54BA78EEULL, 0xE086228D0E39BED0ULL, 0xD45043CF9E66081BULL, 
            0x9858B88F26784BB9ULL, 0xA231520741828B77ULL, 0xC4CACE87D43E772AULL, 0x5F664FDEB762986BULL, 
            0x154D68E1E6E8E553ULL, 0x4459AF2587A3D26CULL, 0xE81BC0AE432961ABULL, 0x471D97FC2275FDBBULL, 
            0x8A8DB96BC88A8E17ULL, 0x9DC1E2273ED1ACCAULL, 0x4E95EC411397AA68ULL, 0x8210F05AE9396AF9ULL, 
            0xB551F7CF6DB3F1F9ULL, 0x3DF637C36DC65B45ULL, 0x6189EB6D93E428F5ULL, 0x0565C2F4FE7103A2ULL, 
            0xA9C0378D683A2AE2ULL, 0x69F49D78ADEDB889ULL, 0x0EFCC6A7F60E33EAULL, 0xE087199983004A36ULL
        },
        {
            0x4C45A0742E7CCD59ULL, 0xE94ADD5D6D4C2875ULL, 0xEBCEDD5B613FB7A9ULL, 0x62CE1575256F8865ULL, 
            0x7E719D7B59D17362ULL, 0xFF7881E1CF1F9DDDULL, 0x35B3AF549B0EF1E5ULL, 0x7E957CCBB48CE6F5ULL, 
            0xF7964FAB57D22991ULL, 0x4303D70A7D4C5F79ULL, 0x1B80297B3B2DAC51ULL, 0x756523F712572DF6ULL, 
            0xC66660C40FBBA5C5ULL, 0xC2AA12D451CB0594ULL, 0xDAB835011AE8A55DULL, 0x13CD0CF0CFC18DD2ULL, 
            0xC5A367DF80C8674DULL, 0x97872A1C57C9599BULL, 0x4533CA248AA52B34ULL, 0x179CD4EF3FAD5664ULL, 
            0xB4AC6381293AD97DULL, 0x85283510EB1B95E2ULL, 0x60DFF8E11CF504F7ULL, 0xC550473A82D2CDB9ULL, 
            0x5B95F174C958D77BULL, 0xB62EC3A92105EC53ULL, 0xF3DD1DB870E5E63BULL, 0xD114394118DFB356ULL, 
            0x5B5E87D408F9149AULL, 0x3D1D6EED8C354FF3ULL, 0x3D87598F43DF4B17ULL, 0x05D46CB3ABD876E7ULL
        },
        {
            0x9C9E131DF96B312CULL, 0x82860AE86F4E95B3ULL, 0x7D6E096D00C50A8DULL, 0xD122D876A64E31F3ULL, 
            0x33EF38A00B3473D7ULL, 0xC2C03CB2F9F73459ULL, 0x68BB2E674CE5FC22ULL, 0x4069814BC099AAF5ULL, 
            0xC293D5492E89F4DEULL, 0x89D6FD58DA9C0AB8ULL, 0x88DFA6AFC4AA261AULL, 0x6A56C74C17CC0752ULL, 
            0x694C4C9B7909A009ULL, 0x9E43BC986D433CAFULL, 0x24159B662E76092DULL, 0x58C33F27C0EAF002ULL, 
            0x408B40C91AB09137ULL, 0xF397EC5D783D570BULL, 0x047DCDA046C781EEULL, 0x3E9C4B37CC27C14DULL, 
            0x0602EF3A54636EF6ULL, 0xA7BCA4B3D5A9456EULL, 0x51E03D5C6705693FULL, 0x1B8725F65BCA02FBULL, 
            0x3AD25BCE8FCDE2D2ULL, 0x20E7512CB75587C2ULL, 0xB1DCB5C96F9F071EULL, 0x1D07F1EE8923C1F9ULL, 
            0x233B678694CB9D30ULL, 0xC17D566ECD47A5D2ULL, 0xB72D43C0517AC7ECULL, 0x67DAADCC4AFC50B6ULL
        }
    },
    {
        {
            0xB22E6BBB269939EAULL, 0x606595A8892F711EULL, 0x0E7C8B56580A35E0ULL, 0xD7D688A1C1224BEFULL, 
            0x97AB62075D5D8A0EULL, 0x63225CE3C58C0DBCULL, 0xD63EA13756AA0F31ULL, 0x25196FEC74C85996ULL, 
            0x6A2F2187F7131D26ULL, 0x86B3726807754BF9ULL, 0x6781F6F79302F435ULL, 0x00E3F8AB14F0C8BEULL, 
            0xE16E68FE0D275ADFULL, 0x076FB94C47351EA5ULL, 0x1173E6EF117D3E42ULL, 0x7FE296D382D23F32ULL, 
            0x1953E2EF06B9A165ULL, 0x3C665C6C5A5D887BULL, 0x43013544417AD6DCULL, 0x54AE9E2A17BE4175ULL, 
            0x8532AE3E740854F1ULL, 0x15F854B2C42CE73EULL, 0xB772A3DB27777B78ULL, 0x6D023A381FACCD9CULL, 
            0x04F24332F3E0C1EEULL, 0x6025FCD07F4CACD2ULL, 0x07826EFDAC86845CULL, 0x742C8852FBAE45FBULL, 
            0x5F1909228E117DE3ULL, 0xE9DE22482AB5B6F3ULL, 0xAD3E442BA61BAB4EULL, 0x79E0625895675BE2ULL
        },
        {
            0xE93C60EAB708E1C0ULL, 0x921D5324344D03C1ULL, 0x6284F2EA3221F70FULL, 0xAEC6F3FEF3FF8D4BULL, 
            0xE30278C5CEAA32E4ULL, 0x31539B8D4ECBC45CULL, 0xBE6F39725162289EULL, 0x323379591EAB337AULL, 
            0xB9E8799A9D6FA400ULL, 0x24B144D307765B83ULL, 0x8B9C121D3CDB79A6ULL, 0xC3552F3264A53CA3ULL, 
            0x0EC4993725B51864ULL, 0x3519627D796BAF01ULL, 0x640180A842B9B1FEULL, 0x054984FDA5BBB0BCULL, 
            0x2A21F2EE04BDA089ULL, 0xEF08B47E394AEFF6ULL, 0xA1BA43B6600938C9ULL, 0x0DB97FC07F0F9642ULL, 
            0x6A2E00E71BDA3B1BULL, 0x000DDB39C5B5D9A9ULL, 0x07267CF7B2A7B8F4ULL, 0x1F877A677763D678ULL, 
            0xDC39848A059FE6BEULL, 0x7109CBD49407265BULL, 0x1C361FF391E4FDB4ULL, 0x0D119BD94D5C9D3BULL, 
            0x79324889C6FBE63BULL, 0x4E52419BA80454C5ULL, 0x0145D63F83A39F4EULL, 0x25BC24122E3782D2ULL
        },
        {
            0xAE1C3AB50ACD31B2ULL, 0x443F733EDED24F5CULL, 0x33F7C66FF5BC83D1ULL, 0x7AF808BB979E139BULL, 
            0x0B100877072DEBAEULL, 0xECA9FC1627DD13EAULL, 0xC61DAA2AA67B98ECULL, 0x81AF16269883B370ULL, 
            0xEDDD7778AFB3F9C0ULL, 0x07429A8A53240136ULL, 0x2498E847A08B2256ULL, 0xB48A84A08D2EEFF9ULL, 
            0x6D8AA5BCEA1209ECULL, 0x4069E0C58950A87DULL, 0x8328C7A550CD19B9ULL, 0x1BE767D16D301F8DULL, 
            0x664FDD30DE6F41BAULL, 0xA5F024D852C9A952ULL, 0x3B61074EC97B9B68ULL, 0x18719061373A0E2EULL, 
            0x88531C29E9DBB73EULL, 0xD8B34095B0597DC0ULL, 0x39F4220BF118F3E3ULL, 0x347B9E199966450FULL, 
            0x5202EA706A0B5D4FULL, 0xC4E0F26B75D82B09ULL, 0x41A1CE1AA6AFDAA9ULL, 0xBDDD82E8272FA06BULL, 
            0xE4C12714333FE492ULL, 0xE8E411F60B386E61ULL, 0x01ED8048F6A96E68ULL, 0xBC6923129F92F7E3ULL
        },
        {
            0x8AF7C6582FECA05FULL, 0x3602FF6C07AF1D00ULL, 0xFDDFF603C693866FULL, 0xA67E1E69C0E845B6ULL, 
            0x293ACA3A31A2191FULL, 0xB095A7BAA760B9A2ULL, 0xA6C2E92B5A219635ULL, 0x35E4B5D34A425518ULL, 
            0xD4D90215C9DD8A41ULL, 0x1EDA087D485A6442ULL, 0x1E0048F7F2A7AD5EULL, 0xD4FD8C0EFD005DD5ULL, 
            0x267C12050DFB9197ULL, 0x4046D91BE157824CULL, 0xFB12078DBA77177CULL, 0x238FA85BEA8D2C47ULL, 
            0xC6267A76FAE3FDC3ULL, 0x7808884D023C78BBULL, 0xCD1F7F1674F1DD87ULL, 0x37310D8FB371AE3BULL, 
            0x341DB6CA0AFD94BBULL, 0x44768153C3B048A1ULL, 0xEDA6023ABEB2933EULL, 0x554D4801588D9D1DULL, 
            0xFBA08D6CEDBB2B45ULL, 0x0F06A4CCC4C40267ULL, 0xA5B6060E0037351DULL, 0x88592DD972F5DCB9ULL, 
            0xE5E7E57CB7821020ULL, 0x6362C49DD412C99EULL, 0xC5A9AE02DF028E31ULL, 0xAED9A0A70F769036ULL
        },
        {
            0xAE7D4EDF14C51D01ULL, 0xC4B1C94DBC60936EULL, 0x419F86DCF04A0C5AULL, 0x72F38787207CE96EULL, 
            0x11157E314EE3C2DBULL, 0x8D3450DE2A04C3C8ULL, 0x1FF9237D0CD29D2DULL, 0x9FEE0E5D22C6C3C4ULL, 
            0x0A47F63A48DD9E0BULL, 0xE8B02CAFAD67D304ULL, 0xD249364B558E3514ULL, 0x2D438ADD6D1F1B9EULL, 
            0x84353BA1EFE7CE29ULL, 0x503F1D455DBBA9A6ULL, 0xA689836FB8FC7B9BULL, 0x00591A833727B3E0ULL, 
            0x295913E12946E233ULL, 0x6473E195395C107DULL, 0x9706B0D5EA02BA5BULL, 0x46BBEC14EC1F2EA7ULL, 
            0x097133F74A077529ULL, 0xFF0A5A139157EFF6ULL, 0xF1111DA38C3645E2ULL, 0xEE2905F91999F3A7ULL, 
            0xE3DE95E7A0671431ULL, 0x26E75C48F2B71ED7ULL, 0xBE52794BC6F50A15ULL, 0x475DB64B0E18FC66ULL, 
            0x408C3049166E0FA4ULL, 0x59D02A90B4C497E9ULL, 0x08F809986CDE7F39ULL, 0x9EC4E203D94B1D87ULL
        },
        {
            0x7212A946ABBC2645ULL, 0xBA452073DE2B3CDAULL, 0x59E40A864BF9BE49ULL, 0xABD03039F34CD29CULL, 
            0x89DF12D0B394C2C4ULL, 0x22EB50D2BA2CDFD9ULL, 0x40B11FFE32BCBF5BULL, 0xE66395D11BBE8370ULL, 
            0x1B19BC5B5D1E9007ULL, 0xC18266F4106B99C6ULL, 0x112EBE7BE4DFC79BULL, 0xB29B45F69725CF3FULL, 
            0x1A95622A2EFE7437ULL, 0xB25CE37733B4E424ULL, 0xBD5D306A724A1216ULL, 0xC62506F339219001ULL, 
            0xB3FC7D793EB61E75ULL, 0xFA39712AA2EDADC9ULL, 0xE3E1F63220463E15ULL, 0x808530AF02F1E841ULL, 
            0x85EA6F411906F968ULL, 0xC55BB9AA34C9C041ULL, 0x3F9D1EEC30EB7F72ULL, 0x97F07A102FBEA29BULL, 
            0x17A3F27BE3CBC881ULL, 0xBFB8C92AE0F8433EULL, 0xE360651EB3946DD7ULL, 0x63A7675CE0EAB0F8ULL, 
            0x62181BD9BC771A17ULL, 0x878C9F0466160DF0ULL, 0xF4D8CBBD4657C9BAULL, 0x6F6170BD84701F0EULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseDConstants = {
    0x604873EFD0BF1A67ULL,
    0x39213B9C8D88626AULL,
    0x7ADA9F1630158949ULL,
    0x604873EFD0BF1A67ULL,
    0x39213B9C8D88626AULL,
    0x7ADA9F1630158949ULL,
    0x54550EF0CDF790E7ULL,
    0x83DB34C17DA6538DULL,
    0x9F,
    0x25,
    0x16,
    0x71,
    0xF6,
    0x7D,
    0x24,
    0xB6
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseESalts = {
    {
        {
            0xAB2C2766A94C9F9BULL, 0x2F1A7B31BD4A0089ULL, 0xEB9C6575A33D0998ULL, 0x4B3663721AD95390ULL, 
            0x74949A9ECD8A43F9ULL, 0x9E7959FDA567A179ULL, 0xC811B1AB0CED0519ULL, 0x0918B762C79D5D31ULL, 
            0x5D945C369132844CULL, 0xD61AE20852F29C64ULL, 0x417A36593C4E09F7ULL, 0xC0C347DF1E240C2BULL, 
            0xB1D53F113B0B798CULL, 0xB90145B47F20B949ULL, 0xCD268E643AD06AE7ULL, 0x14ECFE55BADC6B50ULL, 
            0x88B5E06095257039ULL, 0x4574F7BD94D8C148ULL, 0xDD7143BDBB399417ULL, 0x9FD3036C37C9495BULL, 
            0x3E2BE696AD807EE9ULL, 0x6BE5F5FA0B5F4C9BULL, 0xF94E064B5FD8EC38ULL, 0xB63251DE5CF97C1CULL, 
            0x559F3002FE16D77BULL, 0xA03C301E8671F08FULL, 0xFD37BD45B83B3E58ULL, 0xF856AF0EB3FFFF41ULL, 
            0x3F7481FCCA741AA2ULL, 0xFE348D203F4E6DEDULL, 0x22CA93A2AB104BB6ULL, 0x828833240B2A79B9ULL
        },
        {
            0x9F9981A1A1A4BF5BULL, 0x12A3E5C27CDFEB9FULL, 0x6E1B8CBE41D0D0CFULL, 0x1CEF010CD8FB6295ULL, 
            0x3A5C0D834E112E0CULL, 0x3F5894F7493F47D3ULL, 0x27A4184F3258EAB9ULL, 0xC3775C75D586A868ULL, 
            0x43B1D649CD2AD28DULL, 0x30A550D640384D22ULL, 0x9EB19543BA75BE30ULL, 0xB8A79DC1578E1BEBULL, 
            0x3872821D7C1DA8AFULL, 0xB908D31CFB82CC85ULL, 0x19D03B615B22A84CULL, 0xC508C9933D79C819ULL, 
            0xD436305BBE0CD5C2ULL, 0xE8091011DCEAC088ULL, 0x0DECEC37BE85B3B1ULL, 0xF239E6ACC003E3A6ULL, 
            0xC1F1F89D5EC3E5CFULL, 0xE46912BBF35A4637ULL, 0x1A60B8C9C9133008ULL, 0x96806363A9C02C6FULL, 
            0x674FFA437179D4D8ULL, 0xBE5749CEF3622EEBULL, 0xF426DA932C71474CULL, 0x027BD20253A76F79ULL, 
            0xE98EA7FA621335C5ULL, 0x9ECF0C0E8FD1F37DULL, 0x43EB535ABFC4AF23ULL, 0x162CD54DCFA9A488ULL
        },
        {
            0x2B646A900091A0B9ULL, 0x64ED9E6C5137FD5FULL, 0x1C8A111F821B173DULL, 0x990F54A79ACAAE63ULL, 
            0xC70BA47BEF5610B5ULL, 0xC5B43479869F16D2ULL, 0xA04EB4F805F9E271ULL, 0xBEFD863C2EE75593ULL, 
            0xAB232C5FF2991141ULL, 0x121AECD83E293218ULL, 0x53C0010C43661497ULL, 0xD7C2158AC75A2ADFULL, 
            0x16EE5132EC5C525EULL, 0x657ECD8E1C09E92BULL, 0xBCD5FB50B47BBC4BULL, 0x5B64C81B509E7636ULL, 
            0x0067E0AF4ADA891CULL, 0xE15BDEF6841DFFF2ULL, 0xC9885131DC64F976ULL, 0x0F037DB7DFA3B042ULL, 
            0xF61E6C9B376A8968ULL, 0x67E167D33E7B603BULL, 0x46EE7EC1B90DBA77ULL, 0x57C01D4518B0B6B8ULL, 
            0x6DA56F39D6FC0B58ULL, 0x1DBFA930139D81DFULL, 0x32C72F4DE0050616ULL, 0x8156EFB0291463DCULL, 
            0xDF22B6B434C34155ULL, 0x2503E557A75ECB4AULL, 0xA79416D92C5EE01DULL, 0xB1B12F4F77FAD68FULL
        },
        {
            0x3F3155286BFA52DFULL, 0x35C5BB4EEC6724E8ULL, 0xBCD373A9EAE83327ULL, 0x205B0966B28E101DULL, 
            0xE32C417737ED2B46ULL, 0x9DAEB7E347B883F4ULL, 0xC6E758D2F617DDF9ULL, 0x3DD785DF6810E0BCULL, 
            0xEEED450429C353B5ULL, 0x12D1FDE53193F115ULL, 0xD5D70428A51F14A6ULL, 0x2FA08E6AB85A5761ULL, 
            0xF87988855A285E5CULL, 0x87A05E9254EF99B3ULL, 0xF8D57B99F0BEAAFBULL, 0x909664678817E6F4ULL, 
            0x19E5EB5038D93740ULL, 0x8B99CCAD7CAB74A8ULL, 0xD39B6B25A4D5B46FULL, 0x696F8548E0DB07F6ULL, 
            0x7084E8060FCB7590ULL, 0x1904C4C205DF53FDULL, 0x5A9A2FCBB04CD6C2ULL, 0xC7827ED6348961A4ULL, 
            0xF793F44BE38E05C4ULL, 0xF120493250CDBD4AULL, 0xD12BC1768795CA24ULL, 0xF96513791A4A3CEAULL, 
            0xF9A4C8B87105F468ULL, 0x5D8C6CFBA2BFDBB0ULL, 0xE54E0D256719E92DULL, 0x4DFF047E25C5D1F3ULL
        },
        {
            0xAD8DC5A45C8A116FULL, 0x104B5084E5C60DA2ULL, 0x38A7156865076171ULL, 0xB25C720B1393EBF5ULL, 
            0x1B37FA7C69D46976ULL, 0x6073811EF52343B3ULL, 0x5FB8BD18D1E9585EULL, 0xFC6CE0F84D819BE5ULL, 
            0x3551FB9C6205B424ULL, 0xCE2457D202360EAEULL, 0xAE4DD258CD5909C2ULL, 0x07BA88560C810D61ULL, 
            0x271875DB784F55EFULL, 0xF271F9B72D2DDC96ULL, 0xAF32537A1A5A6A9DULL, 0xAF5413D02BDA7212ULL, 
            0x3EEB9C0AAC5838A8ULL, 0xB455562D00C013FFULL, 0xF46634A37708FB51ULL, 0x5D65800C9B89757FULL, 
            0x8B5DCCFD3420A02BULL, 0xDB89B4B81E473B76ULL, 0x7A8A114A37100EC0ULL, 0x6FF790705F088049ULL, 
            0xB7A255E102D2FA8EULL, 0x26BD36C3A6B7B2A2ULL, 0x5CFE1F3D1AB9822AULL, 0xE56F6186D419F090ULL, 
            0xC315C23534D3E2F8ULL, 0xA68DD83F2AF3AD9DULL, 0x7C56FAF360AB8195ULL, 0x9D622953910F7896ULL
        },
        {
            0xD2C3B56EF508C5EBULL, 0x082E2AB932E26374ULL, 0xC316A39EF1C560E4ULL, 0xF186462E55FF0A40ULL, 
            0x32AA38BC50472332ULL, 0x89C670B27E63713DULL, 0xD267710D2D890D97ULL, 0xA4CB30DDD9C5E8E0ULL, 
            0x906A5CF6285764D4ULL, 0x4CCBEE49361F4F5EULL, 0xB961753465CBDC18ULL, 0xC34D09911D1D8B08ULL, 
            0x683BA7710FCCE45AULL, 0x2D2EDD85344DDD23ULL, 0x72AD2DD5ACCC305DULL, 0xD3A6429C2ED6D076ULL, 
            0x551DDDDC84B7CB30ULL, 0x229C3F47C6AE4982ULL, 0x53E6D6B5D80A5F9AULL, 0x4DBFBFAB07677E46ULL, 
            0xE3DA0A0035133EEBULL, 0xE52220D515E2187AULL, 0xDD284227D793A74EULL, 0xCDB77F7DED942872ULL, 
            0xFD45BBE2A16D9C13ULL, 0xC9342CF0042E8D77ULL, 0x29C3632A9561D14FULL, 0x4170AD0C8E824588ULL, 
            0x2990DF8C70404BC1ULL, 0x55A104641451490FULL, 0x3A1B497403BB3D80ULL, 0x743286DFB6830B6DULL
        }
    },
    {
        {
            0xE66CB98217D8C067ULL, 0xC6A3406E58E258CBULL, 0x5119F70DE8F2E69CULL, 0x9CEE8312A9A9065FULL, 
            0xA4CF9CC1A953B25DULL, 0xDF8D897A69D1D2B9ULL, 0x13B1F341BCC5B50FULL, 0xEB170452A16DCCD7ULL, 
            0xA6B0680B58BFC01DULL, 0x5B41BB139B3ED1F0ULL, 0xFE2541A382E592C4ULL, 0xC6C7145703B5823BULL, 
            0x395E81CF3AD62A2FULL, 0xD4D5F26ED5D65AD8ULL, 0xB40727E84352783DULL, 0x665F1A38ACD0A272ULL, 
            0x0C71333BEF4A553CULL, 0x55F74EDC6A905699ULL, 0x979425EA673C8FE8ULL, 0xF6F9B39A03E85912ULL, 
            0xB971539EEE60EBFCULL, 0x709E747BA3BC9CEFULL, 0xF68D371372A0297FULL, 0xA8DBF244C2ECC358ULL, 
            0x2997FFEF0F2DEFEAULL, 0x2FEA0866E3E321E5ULL, 0x6A42CE223C4B2C27ULL, 0x0E0E784EE3434555ULL, 
            0xA57CD45296713159ULL, 0x8E3F590AA48C9DF4ULL, 0x466D4C8A11C412F2ULL, 0x6377AB78B281DB99ULL
        },
        {
            0xB7D1DFF90BBA4008ULL, 0x338BDDCFF2DB776FULL, 0x15E2E6DDE7BB4222ULL, 0xBA91E759B218AC34ULL, 
            0xFD782BFFA667C2B4ULL, 0xCF1281C6818DB8C6ULL, 0xDE4518FB6C199651ULL, 0x428C1F08A4AF9276ULL, 
            0x474A9E16D503EBCAULL, 0x5B7E0D2FD38FADF5ULL, 0x9481FE0F021231E1ULL, 0xE7BBB245C21CA367ULL, 
            0x58C01ED8E6036D9FULL, 0xBDBA0A8D9ED166D8ULL, 0xE4E7B3C7CD0E9E10ULL, 0xC2314EA82ABC0B62ULL, 
            0x3BFA4DD0B296DBA5ULL, 0xE391F43547E2A35BULL, 0xB1AFAA1C37D9BF50ULL, 0x157765E147F2B4F1ULL, 
            0xE23D84DECEA28EB0ULL, 0x06A8ECCE97073919ULL, 0x0F886D6A0774A566ULL, 0xD9D40BA2D9F15637ULL, 
            0xAE18AB6F97006468ULL, 0x52A00C92806AB876ULL, 0x886C931DE32A3C5DULL, 0x9F2633E0951093F8ULL, 
            0x7DB47DE12F03F02CULL, 0x1681061297609D91ULL, 0xE0E53ACE8E6C0001ULL, 0xA455367E3F10B31FULL
        },
        {
            0x4C7CF0820F4E5DADULL, 0x33EDC4445ADC61A4ULL, 0x2BBA2AE0D200BCF7ULL, 0xCB1B0B31FF9D3C89ULL, 
            0xB609947C0CA83F41ULL, 0x9E919F260BF434A7ULL, 0x3E5CE9068AD05E63ULL, 0x17B391A994BB5E84ULL, 
            0xB382322BDC041DDBULL, 0x0DAB41C4C2F970F8ULL, 0x74654A6D66809A29ULL, 0x11F35ED3A486181CULL, 
            0xB4B0137566C2C546ULL, 0x1DB023775E350CD2ULL, 0xFC218A368B03413EULL, 0x34A7146DD3C18DB3ULL, 
            0xDA7F35B46D71D8BDULL, 0x939953832A480253ULL, 0x79A4C85D1BE88F0EULL, 0x91ED55A80C900FBBULL, 
            0x1BA504A0EC5A0209ULL, 0x8363A3793C39B76AULL, 0x027FC1F43E29172BULL, 0x95CFC48BE030DFFAULL, 
            0x59E97A89BA2C508DULL, 0xA65F0F56914837DEULL, 0xB0988BF0902C4BF0ULL, 0xE85146821D9D8414ULL, 
            0xF60862140293A270ULL, 0xF305E8063DF0D519ULL, 0x41C056E3CC6CF437ULL, 0xBC15AA3401000920ULL
        },
        {
            0xED662A15837D26C0ULL, 0x165962DA46E942E1ULL, 0x10DC3A4F5311CAA0ULL, 0x704ACC2EB24168E1ULL, 
            0x8319EBD013A66DDBULL, 0xFF54A439B7BA153CULL, 0xDF3A0E44521ACB9DULL, 0x7475D08CC63676ACULL, 
            0x6F7A9E746B5A128DULL, 0xA9531358BBF2D97EULL, 0x95F41108D6AE91D9ULL, 0x7DB83AFB1E7DD08BULL, 
            0xBFFA33BF9D9B9D23ULL, 0xC6FE0869ECF62600ULL, 0xD358096242F2D07AULL, 0x17C29665FF311B08ULL, 
            0x471833ED8F9FFF93ULL, 0x56226C1ADC58A34DULL, 0x41355DA5D5E53167ULL, 0x49635F4AF84BED76ULL, 
            0x679708C8B8414325ULL, 0xE960AF8C47CDBB89ULL, 0x794D7436CA2378F5ULL, 0x4EB0F16BC129EF6AULL, 
            0xAFD394D05EEA7B29ULL, 0x8588BB54E359A2EBULL, 0xEC731566572F0285ULL, 0xE800A498BFFA7DEEULL, 
            0x651F59A5E3F66FEBULL, 0xBF949152B6C956EAULL, 0xA16455F0A3F74618ULL, 0x4757288D7D561B4EULL
        },
        {
            0x31FA8897A7E754CBULL, 0x08012BEDD27A01CDULL, 0x8A096C4B21891483ULL, 0xCD13AD85F58339E1ULL, 
            0x2AC814F2459DAAA1ULL, 0x792D5B60F2F6AE6EULL, 0x156AF7E92A56124AULL, 0x61F3895CEEC689FCULL, 
            0x58F389970536751DULL, 0xEF15A9A518A18114ULL, 0xC858807D3F4572FCULL, 0x784BE64F79855BC5ULL, 
            0x25E7E47A847BD93DULL, 0x17B686B6DEE4CD07ULL, 0xEC209DF3631A1533ULL, 0x6545A4330C1928B1ULL, 
            0xF636056CF763633FULL, 0xEBEA338FD2FED897ULL, 0x51931A1F37C5B49BULL, 0xA9354C0FF6ED9BE7ULL, 
            0x54267C7BDEA74907ULL, 0x60301C9D5FD634CCULL, 0x79BEDC4CA00F49D2ULL, 0xE5FE71B08C8F3822ULL, 
            0xE640012112F38BC3ULL, 0x0560A5B6CF3895EDULL, 0xC2AB504C09FC93E7ULL, 0xC36CA483DCA0C59AULL, 
            0x095FAF79CEAD322FULL, 0x881E41DE285381FFULL, 0xED00930BD34B3787ULL, 0x88BBE2784519FEDFULL
        },
        {
            0x3BE992AF4623437EULL, 0x86E41E61BCD3C108ULL, 0xE2187CA03A5752DCULL, 0xFF172E3F15BE7297ULL, 
            0x2CD946933E23180CULL, 0x1D73BDFACF9DB7B2ULL, 0x2EACD680CFB1B7C4ULL, 0xAD9B29DCEB88E25AULL, 
            0x75CF102E301CBEC9ULL, 0x62E7FA16DCA2CD76ULL, 0x05AE670945F1E705ULL, 0x79DDDD01A1713A54ULL, 
            0x6C758539843742D5ULL, 0x1156352BE7D3254FULL, 0x3D0E698189830A37ULL, 0x664D841857369A21ULL, 
            0x5CE57A68060F5DB2ULL, 0x093ABBA86FC76526ULL, 0x848C1ECB6BA3E99EULL, 0x855D3C75F02C5B53ULL, 
            0x08B107F67529BEDFULL, 0x19BF221E3ED6F379ULL, 0x4E38501A6181F284ULL, 0x4D4989584FEF2AA9ULL, 
            0x3F0F3768342E10D2ULL, 0x489F7F606B1ABBB3ULL, 0xDFD6301694CB6A50ULL, 0xA992AB20FFE43206ULL, 
            0xB4F8C952C3A1C626ULL, 0xC2DB3CC31087A53AULL, 0x35B40025FBEE8304ULL, 0x5D2A9893EBAFCD84ULL
        }
    },
    {
        {
            0x86A0AD39FE9778AFULL, 0xE1594D226D9FF5CEULL, 0x0B6387B087476620ULL, 0x17A7BB106DE58CC4ULL, 
            0xFA867EF6926660C5ULL, 0x89379F9947AE9DBFULL, 0xABEFBA3DD5CE633AULL, 0x41E8462B05425E4AULL, 
            0xC0518AFF1070624DULL, 0xE401959ACC00305BULL, 0xFEF06E9FCBAA8160ULL, 0x69E1CEF3B73D1536ULL, 
            0xBA1FECC4BF430415ULL, 0x1B0EB68AC075D327ULL, 0x6F0AB80BA18D0DA7ULL, 0xBFDA349525F88BFAULL, 
            0xD7385D446DB202B5ULL, 0xB6470196E639F7EFULL, 0xDA5C3C79C63B269FULL, 0x9D61D79C150CD21EULL, 
            0xE9401E5A1A44EA0BULL, 0xEA92414F7D3C72FBULL, 0x72A965E9FB9668F0ULL, 0xD8E6B8C9084288B1ULL, 
            0x6EA7DB8317884B22ULL, 0xC449168011E5A827ULL, 0x3A1E727F88340455ULL, 0xC8D26283017C74AAULL, 
            0x834156CB7CA5A6DEULL, 0x86222298762A2F4FULL, 0xE5EE739A65AF7C06ULL, 0x04567E6B792A09A3ULL
        },
        {
            0x1647B01D96B95666ULL, 0x25D07A09A65E86F7ULL, 0x7BE6BCB5FE66D925ULL, 0xBF10BD2C0BCB8E28ULL, 
            0x06828C1C0A76C407ULL, 0xE268EDE3EA2D01A7ULL, 0x05DE17730708DDEEULL, 0xD423C6941D56DFE1ULL, 
            0xEC440A8627C3BE3FULL, 0x9ABF08C0210C382CULL, 0xD3D2E44E330E4341ULL, 0x2B927E1FA5CCAD2BULL, 
            0x041A87AE8C57C28AULL, 0xA17E15E892E24E39ULL, 0xFE12392CE6E756A7ULL, 0xE03CE46466B56A1DULL, 
            0xB5D017F9ABE359DEULL, 0x608FF45346EF1953ULL, 0x2452565CEDB622E5ULL, 0xE75476B7D0652FDFULL, 
            0x9EFF582B65C2823EULL, 0x9EB7AD957A23E666ULL, 0x5BE8093F8237C30CULL, 0x0D6FDF9C9A6B3E8EULL, 
            0x33911140C6C96DE8ULL, 0x64AA45F555939EBDULL, 0x09BCD93818C5259AULL, 0x71C060F64FEBD007ULL, 
            0xE941EA974C2C0EB2ULL, 0x21B5B405B2834AE5ULL, 0x9B65A9AE55A519D8ULL, 0x541313BB155B2C9AULL
        },
        {
            0xCF328CF5D416CB20ULL, 0xBAD0B0F01453DFCAULL, 0xF5EC970E90F3AE09ULL, 0x569357807A6DF945ULL, 
            0xE1FD2C43009FA3A8ULL, 0x8C72B6163BFB89A4ULL, 0x9F8F843A189C81E9ULL, 0xC7AEC4DB1D1E1E5FULL, 
            0xF9922A85ACA9AF31ULL, 0x003B5CCB137217F6ULL, 0x3F354DD2AE45C9F2ULL, 0xD454AD68FCD11110ULL, 
            0x45572410D294FCBEULL, 0x7F75859A7A682959ULL, 0x993DA47DE51EFAFFULL, 0x8F2530F8026D6CA4ULL, 
            0x07B3E0A55D4F7DECULL, 0x02CD396FF5754E02ULL, 0xFB165A2CEF68DC27ULL, 0x57F100D4F03CA02FULL, 
            0xE418957BFD827311ULL, 0x1BED58BB3CCA261AULL, 0xC0721B2CAD674267ULL, 0x79632D0CDA7A26BAULL, 
            0xC2C4D23B88ADC4BCULL, 0x574013E9AC7600F4ULL, 0xED991D078FC48207ULL, 0x730AF860B2450E64ULL, 
            0x8548A3C833E955ADULL, 0x650A27AC8D41A5F3ULL, 0x5C78D1BA13A06650ULL, 0x4D06FEDA710EC17CULL
        },
        {
            0x611B822F0A554BEAULL, 0xD493855A21DA956AULL, 0x70CA9AE191EC84D1ULL, 0x0A3AE2C27B74F751ULL, 
            0x5249A53E901503D0ULL, 0x805E718C3E8E0300ULL, 0xF23745AA9154BE7EULL, 0x348E493332A82151ULL, 
            0x5BF0EE23FBBE6FF6ULL, 0xA8E56278D6D5E266ULL, 0x74C0BECE5C69153DULL, 0x07305A1FD5CF9571ULL, 
            0x199C40C13889F42DULL, 0x27F0D46F21DD4CA7ULL, 0x78FC4E5F7AEB0E20ULL, 0xA3CE24C004DD3FC0ULL, 
            0xBFBB5D24484AFA38ULL, 0x0F5B371359556DE6ULL, 0x5D602684FFD3C436ULL, 0xE0160D14DF58B68DULL, 
            0xE91806062A8D214CULL, 0xEAF8417BF9AB17DEULL, 0xB9E103A2FAAF7904ULL, 0x8133B80D210B1A74ULL, 
            0xEBA502568CFF6D8AULL, 0xD49087A9449434DBULL, 0x073F032780F0B738ULL, 0x838436B43EEDC31AULL, 
            0x1B88EC5A4D870C54ULL, 0x9A3EDA36459E1089ULL, 0xCE2F5BC2402DE7ADULL, 0x97984D016446AE14ULL
        },
        {
            0x17FBE60150E83AEBULL, 0x0CC2C06B776D62E4ULL, 0x84315D2E94284817ULL, 0xBDAF373F8E4E4C8CULL, 
            0xCC6BAAC3B723F7E4ULL, 0xFF82B09E3E72A261ULL, 0x62E8D7D3887C492CULL, 0x5A40D4025C393DBDULL, 
            0xE56086453C231D74ULL, 0xC0DBE008DA294919ULL, 0x4B25799728F47D9DULL, 0xEED7ADD02E4B99A1ULL, 
            0x89E7A25A91051DF5ULL, 0x47D3CEA34471C3D2ULL, 0x50746EA3B066ED2DULL, 0x44549DD02C2B108BULL, 
            0x4A6E79F7E5499C1CULL, 0x9090AB0A6529B6DEULL, 0x1783FE8C64B95C17ULL, 0x2ACE510505FCA097ULL, 
            0xFFC0E3EBEE9BBE0AULL, 0x14EA282545457165ULL, 0x3E3100DD9BEC253FULL, 0xFDD60746F9497282ULL, 
            0x64F81985788881BEULL, 0x6D1D47B65DA1DDF5ULL, 0x2A425D41BF930314ULL, 0x96229B50D998B519ULL, 
            0x898BD617795C5A06ULL, 0xC46CDE8B489C3F65ULL, 0xAEAC6FB76E41A165ULL, 0x9D2D7CD6F0723CACULL
        },
        {
            0x7235EC35EC94B694ULL, 0xB54D18C1E14BDEAFULL, 0xA86AE149DAE64606ULL, 0x1398271E7EFA2042ULL, 
            0xE9A78FF25863C253ULL, 0xA1FBB6C96557F238ULL, 0xCAEF24E77188CC90ULL, 0xC706571DE288ECCAULL, 
            0x4FD60AB09692575EULL, 0xCB4CF18EE758A0D6ULL, 0x43DA8D3F36630E83ULL, 0x9C50B21B152D89E7ULL, 
            0xBAB6D63C4EF831CFULL, 0x32CFF1BF6A3BE03BULL, 0x092BDA6AF08A7EFFULL, 0x32BFC9211901159DULL, 
            0xED9D441C3FF01F6CULL, 0xF8B9D6544309A360ULL, 0x6B1194866D4E698BULL, 0x2ED6B8E624A14CA3ULL, 
            0x81405E49D6368A5EULL, 0xAB835D698DCBD7A0ULL, 0xCE4BBEEF3C28D05CULL, 0xFEE9AD2D150B5999ULL, 
            0xC38F529D44BB4305ULL, 0xBA1F6CED13EF4C66ULL, 0xDBC22414DF4321BAULL, 0x4F8A0F024D134163ULL, 
            0xBB5C0A30CF61A024ULL, 0xA0EC1595683B6DA9ULL, 0x5050EF09E801840BULL, 0x2B826B0B2BA3A9D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseEConstants = {
    0x6B24299F83BBF29EULL,
    0xBCB32BFCDA2CF1C2ULL,
    0x744D0F6E0324F9E7ULL,
    0x6B24299F83BBF29EULL,
    0xBCB32BFCDA2CF1C2ULL,
    0x744D0F6E0324F9E7ULL,
    0xBE53AF29D90F4F4CULL,
    0xCED97EBE8974A8A3ULL,
    0x14,
    0x5A,
    0xB2,
    0xA7,
    0xD1,
    0x9D,
    0xEE,
    0x2B
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseFSalts = {
    {
        {
            0xEFF9C27AF6BA5883ULL, 0x2134376012AC41D3ULL, 0xFF58920F63A11A54ULL, 0xF68DD77550DD53BEULL, 
            0x4AE997C3A2ED0649ULL, 0x0EE041BB40F6532FULL, 0xF760359146DD5C9EULL, 0x48D39DF5F52E57C7ULL, 
            0xE78A34052CD9DE22ULL, 0x4D9B1719167BE8E8ULL, 0xC7EF9DCF2EADAFFEULL, 0xCE90D46629BC7F79ULL, 
            0x1A64BAFD48E8CC4FULL, 0x45965D7C66C9B650ULL, 0xBD1616DF56181C88ULL, 0x364D9ECE4C954E44ULL, 
            0x5D04CFC0C0EBD437ULL, 0xF0B309FB509F1DEDULL, 0x6ABE9B9AEF9244DCULL, 0xDA3631AFEBDF7E72ULL, 
            0xCD27594D6F86759AULL, 0x0358E5F98302DD01ULL, 0x1B6AAFA730A11931ULL, 0x638528134B819B5EULL, 
            0x762B8E2347162A9DULL, 0x13B14D644C06BF17ULL, 0x1DEA69A49B2FA836ULL, 0x94A83A74E056C99EULL, 
            0x995FCC0547BBEED7ULL, 0x355D77D0E30A2404ULL, 0x2C4F52AA1D837E31ULL, 0x87462636153FC5BBULL
        },
        {
            0xF57958DA6C011DEDULL, 0x82EE526A99838CABULL, 0x2149DF83BFD8325BULL, 0x1BD3B48B92676738ULL, 
            0xF901A470E4DA2E55ULL, 0x26F1744C713E3146ULL, 0x5FD5EECA9D73C2DCULL, 0x9919F0E9600C496CULL, 
            0x026D279C40ED35EAULL, 0x646F2EBB68818D14ULL, 0x3C9114EBF7F31731ULL, 0x310595E251DA2AE3ULL, 
            0xB910FC0207AB549BULL, 0x704AF7D5594749ACULL, 0x5D6AAA5A3D4199D1ULL, 0x4D53044D9A4039AAULL, 
            0xC7148C751F8D2FBBULL, 0xC8DF6378E276016CULL, 0xFC11DF43CC6CD18CULL, 0x1A595FD70141BB7DULL, 
            0xCD49F164E7119162ULL, 0x03CEC61C0828CE78ULL, 0xA63CFC52B2E1234BULL, 0x9D90007DAAA6479FULL, 
            0xA71B0FC027A64DECULL, 0x03762CF9B1883EDEULL, 0x60E44E5E96F18084ULL, 0xD0B118F10744EE03ULL, 
            0xA9BC82F015F01E75ULL, 0x930E3A0EAB538948ULL, 0xB6EDF7A52525B8C1ULL, 0xE2579733035849DEULL
        },
        {
            0x801D25E5826657F7ULL, 0x7E10A2929F182BD0ULL, 0xDB5BFA334A053D8CULL, 0xA3A056612A6B5846ULL, 
            0xAF0BD44131B8AB2CULL, 0xE0F2D269A8341F60ULL, 0x6EFDC7D040370672ULL, 0xF95325F13AFFAB25ULL, 
            0x3FC2CC4F54A3847AULL, 0x1EEF0F384462E12BULL, 0x03506443A890A613ULL, 0xC836CF1864F785F9ULL, 
            0x9AC38593FCA4314FULL, 0x0930E39F5B932D6AULL, 0x3B3A13B9B40D0E55ULL, 0x2CBD3F39AC5C92D3ULL, 
            0x42BB9F28984DCC77ULL, 0x1BD22F1BFF63C426ULL, 0x12CD738E2F3F52A9ULL, 0x6812439D69E2B891ULL, 
            0x8FCB8C1B1C354A44ULL, 0x1CD03435702BBDBDULL, 0xBAA8A117E8B72A0AULL, 0x373A13202BCD1A80ULL, 
            0x39A0D274098BFF21ULL, 0x82584FB1A62BD2DEULL, 0xB94124FF80B2E7AEULL, 0x90A72E3A0FC8AF6BULL, 
            0x0319C23368A5B550ULL, 0x0135C8FB9C51B12BULL, 0x4946D018332D4CAEULL, 0x5FACB99F61C14FFAULL
        },
        {
            0x969EC6A8C70A40F1ULL, 0x23C51DF48E0258F4ULL, 0xA20E50F5A2D597AEULL, 0x0B6EA7218227833FULL, 
            0xD1686FE5874F29F6ULL, 0x71D659A572FF1039ULL, 0x8C1E136398E56787ULL, 0xB294D0689FB6B3CAULL, 
            0x22A3E976130029A6ULL, 0x503A6C93EAD1968CULL, 0x0716D16C5A0C32B0ULL, 0x2FB593DB0AFEF5AEULL, 
            0xC7C4D5FCB1C1900DULL, 0xC9B42B6AED168BE3ULL, 0x9E4462467B0FF495ULL, 0x77289AA7889E015AULL, 
            0x634E1CA119CD1043ULL, 0xFE47FEE630F53082ULL, 0x0DB674092993AE6CULL, 0x3CC5BFF9DFF54B4AULL, 
            0x78D632D8FCE90043ULL, 0xBC8086CFA306F07EULL, 0x75CE6C4106462605ULL, 0xE3D9232F5C58F213ULL, 
            0xFF1A278A513A8028ULL, 0xB3860E89A66BE13DULL, 0x301256138BC24ED0ULL, 0xF556EF6CF12E0EA8ULL, 
            0x824F683A5911088FULL, 0x02DE5849DEDC8F38ULL, 0xCFF2105AA96638D1ULL, 0x209B430900B401BCULL
        },
        {
            0xF14DBE57EAF57188ULL, 0x9620A09F6AA7378DULL, 0x9A9687A516E0F683ULL, 0xF706ECD4EDC5BFBDULL, 
            0x1A6BBFE7EB5CF94FULL, 0xB8333C8DEC44618DULL, 0xA1D74C024522DC54ULL, 0xB7E3CEB32E4BC218ULL, 
            0xE9426DD8764F8C6DULL, 0x0EA7C6C66A1A53FBULL, 0x749ACA238C555225ULL, 0x1FAAA38FDBDBFDAEULL, 
            0x538B19190AB7F7EBULL, 0x2557CE4C9A516579ULL, 0xE7B005B628156E69ULL, 0xC88F589350F39627ULL, 
            0x61DFC0C66E1DE19EULL, 0x9139C95EE08025BCULL, 0x03D9D706463C4A83ULL, 0x8C85BB57CEAD5B0CULL, 
            0x519E0E56296C34A5ULL, 0xA2B01669DD45A408ULL, 0x072A5DBA47C99890ULL, 0xC1F682CAC3AD61DBULL, 
            0x0F917A7BB3F28921ULL, 0x0AF1A5A7AA6A9777ULL, 0x13E1C1E7BF46C4FEULL, 0xBFC49E60B11A8107ULL, 
            0xC018DC86610194BCULL, 0x1D1EC074A385AFEBULL, 0x2AA05C9C44E85DBFULL, 0x92459210F48EB57FULL
        },
        {
            0xD2AFA213CECAFB86ULL, 0xCCD7A587E0ABD536ULL, 0xAAEBA0DFD202CA2FULL, 0xBB46C0E5B17C7B15ULL, 
            0x5D79A4272B1193CBULL, 0x1C19610B730936FDULL, 0xBA84ACE3697AEFB2ULL, 0x16ABA93688F97444ULL, 
            0x03468DC23032A6AEULL, 0xBD3B6909A6EDCF0AULL, 0x71E38C6C4D673BFAULL, 0x292777E03B2B4F23ULL, 
            0x083F4CBF258BF7C5ULL, 0x6DF9675C946D36C4ULL, 0x20260CB9CBE37722ULL, 0xD0BB7634ACD5B3A0ULL, 
            0xEBD8285F1168F9D8ULL, 0x1EA18E00A169D6EBULL, 0x3DDC4AA95614D3ADULL, 0x6C08C99D3AC9243BULL, 
            0x113354D1DC446B45ULL, 0xFC4ACAC64F7F61CCULL, 0xBFE0D5CB1FED9F1AULL, 0x3D2AE302780A619EULL, 
            0x1B553EC01987171AULL, 0x3C268949624B7206ULL, 0x1E89967572639248ULL, 0x1CC3C4472E5F20D8ULL, 
            0x18D54362A035F28AULL, 0xDE22C3AAC40F968FULL, 0xFF7E616E21F3FB9EULL, 0x6ABFB43143BF36A0ULL
        }
    },
    {
        {
            0xCA99869A90B37DFFULL, 0x8E039470077A357BULL, 0xFFD54CB31A8DA73DULL, 0xE06920257920CF14ULL, 
            0xAA71F458993A4952ULL, 0x13A8ADCC3683C840ULL, 0x527E02D9D918B8F2ULL, 0x3A6CB62617AF2731ULL, 
            0x6E1918961024DED7ULL, 0xB34E67D3D2C6E539ULL, 0x47AFB1FF08123FD4ULL, 0x1FF08E2FC67D7A8EULL, 
            0xE681921C4B98FE6AULL, 0x331EEC29B7921BC8ULL, 0x7856A2E6D70A3BEBULL, 0xBF2C380172B5048FULL, 
            0x469E414BD21B06BDULL, 0x48D662C0219C0F9EULL, 0xB39BFD06F5E30EEEULL, 0xE9E11E31F2F19E52ULL, 
            0x302A37917DA4BF08ULL, 0xE1F158ED1F990E04ULL, 0x053225ABCE00B6DCULL, 0xF67A49D5A8BBFE36ULL, 
            0xB91EB52212382A20ULL, 0x7EF97D917577CD08ULL, 0x215C4F4063312082ULL, 0x9339DF934D2B7571ULL, 
            0xACC202C50E76B748ULL, 0x8913AF7732E1FCBBULL, 0xFC2E0ED75933D8FEULL, 0xB3E910CC48FD732BULL
        },
        {
            0x395019CF3ABCA2B3ULL, 0xF6C2BBF9431895A2ULL, 0x004E1A96B154F8D9ULL, 0x50A928C7E5AFFD50ULL, 
            0xCE0468A7556477D5ULL, 0x4E02954C3C4A5E59ULL, 0xB190FCFAE5AD6DBDULL, 0x7E7BB39DD081C637ULL, 
            0x29F020EC055F97CCULL, 0x4A71E956ED16ECBAULL, 0xD3E64EEC061839A7ULL, 0x8038C0B4F4171429ULL, 
            0x1E76B2D045BAE9CDULL, 0x85D7FBA1C3FD4712ULL, 0x4AA1CC75EBC9CF68ULL, 0x2D6DD7CE8E156F00ULL, 
            0xEFA7A3AFFAFC72DFULL, 0xAA1716564526DD6BULL, 0x1B0894667A7CED00ULL, 0x5EAFB57C7F163B40ULL, 
            0x7AFB08213D32C151ULL, 0xDF94E31B6A1B7020ULL, 0x25467E5FC055A020ULL, 0x61E9F618F211A219ULL, 
            0xB83AD36C160A679AULL, 0xE2484048D91881A8ULL, 0xF174397F3482C5B5ULL, 0x88F5012503B24F4BULL, 
            0xFB2E29DFFA2BE365ULL, 0xDA500A278208E002ULL, 0xD2700097C18D7DD5ULL, 0xF0AC79FB5B222D58ULL
        },
        {
            0xC1A00DE5C9C2AB7EULL, 0xDC5A4A1877A10E9DULL, 0x7471DC112DE5D5BFULL, 0x547110C2B096E140ULL, 
            0xEC54A4B872CB97BCULL, 0x49A6E8E52F69F152ULL, 0x5D370057BB55767EULL, 0x425698BAE60A7B94ULL, 
            0x496E5723EE2C2C49ULL, 0x965AFED8476D06E4ULL, 0x5587A0175885C21CULL, 0x1764DDE6E872CA8FULL, 
            0xF27A505962B58476ULL, 0x54CC1F75FDE7F72AULL, 0x3B80DD7921F5A36AULL, 0xA6F866B509A07F90ULL, 
            0x5ECADEE3D2BED967ULL, 0x847D114FD1EAC390ULL, 0xB41A4F68166A554BULL, 0x5C9926311B162711ULL, 
            0x12701D62ACECD8D0ULL, 0x53D0C0AAD00EBF82ULL, 0xBAFECBFFB8B57DF3ULL, 0xC0F8C0DE81BAF6EEULL, 
            0xA507533BE63715D9ULL, 0x4DB71A2198E783D8ULL, 0x873FEBFE6FB3A983ULL, 0x2DF9D4A2437316AEULL, 
            0x5A41DD9BC9B4FF1BULL, 0x4B840D506594FFCFULL, 0x6A82E4AE3DFA1D2AULL, 0xCFF78E2F26CF7727ULL
        },
        {
            0x08AFC1FB3A49094EULL, 0x2AC5799EE0C697FEULL, 0x249334C2125F51CCULL, 0x5E5F172A8BFB596FULL, 
            0x47D2EA26A26C66D9ULL, 0x5C6AAC15FCCBAC10ULL, 0x6F56C4679D1195CAULL, 0xB0670DDBBD0FDCFBULL, 
            0x6AF020591CAB6A8AULL, 0xDE47BC393028C3DEULL, 0x8CF64300A6FFC825ULL, 0xC96DAF8024216F78ULL, 
            0x81209CAEB79C734AULL, 0x5279A5D24F4A6F5BULL, 0xC55A367A36DBC7BAULL, 0xB68EEC6A980F16C7ULL, 
            0x392050DCC9A64153ULL, 0xB0A5D42F935DEDE6ULL, 0x8DE197505A4ADD8FULL, 0x5C0F706DD54011A0ULL, 
            0xC49FAC8279AB2E9AULL, 0x7D17D01EAEB57D66ULL, 0x9CEE8CF169AE671EULL, 0xB8EDC4EBB35EF5C6ULL, 
            0x9A91561947332560ULL, 0xFA5F4AE1F05878BDULL, 0x01D8EA7E6189EFCAULL, 0x0ED13799E1139F45ULL, 
            0x47C12E53C2E33AD1ULL, 0xAFF39AB524BDEECAULL, 0x26EB8FA4D5DECE3EULL, 0x1642F1DF7916E4BBULL
        },
        {
            0xA49E90ADA4B4BDD2ULL, 0x23B9E601E8BA53A0ULL, 0xF7992FC3845D1690ULL, 0x6D00AD0FDFFE77EAULL, 
            0xB508CC2C0A2C61C5ULL, 0xFE132ABE52A86150ULL, 0xEC16489D8477D909ULL, 0xA89047CAB4A8E138ULL, 
            0x086C9356334535B4ULL, 0x629B3AA5FDDE2DFAULL, 0xC9AEF36419E70363ULL, 0x6FF6968043978089ULL, 
            0x07E7CBE99C5901E7ULL, 0xE43C3CE9914A83D1ULL, 0xE02E5FD9EB5F0994ULL, 0x0BDB7A2047E98312ULL, 
            0x08B475CC3DC28636ULL, 0xDFD7D37DB6D9CF76ULL, 0xFEFE006A17245012ULL, 0xF2BCC75D79FE55ABULL, 
            0x70FB31041E8E2EF6ULL, 0xD993EC855E9B83BBULL, 0xF385D6907C6806A1ULL, 0x7B9A8C6FA6186FF0ULL, 
            0xEFB127E8CA21A745ULL, 0xABF075A0F3F733B1ULL, 0xE0FD3810F55C27E1ULL, 0x264DF87BC2730111ULL, 
            0x435F64635D7ED8EAULL, 0xD82D0854DBB67EDBULL, 0xC55B9CC37DD1D253ULL, 0x0391940BE6BB8F2CULL
        },
        {
            0xC0BB44671AC22DE2ULL, 0x19273303B4C3041BULL, 0xE2BF3AFDACF7A1AEULL, 0xF4853D5D683E9C88ULL, 
            0xA98B56C185E99D09ULL, 0xB1AA58C7EC907AB3ULL, 0x6A950A9C239A610BULL, 0x79913977C94AF865ULL, 
            0xB88376E543C79DF6ULL, 0x2025AF0B0F408665ULL, 0xC5AD0DB429719295ULL, 0xCAAFE2642965116CULL, 
            0xB76D7438ABEF137CULL, 0x74E94086956C4A58ULL, 0x2A3A3BE46B338AA3ULL, 0xEA36AC963684257BULL, 
            0x74C76A793512F8FDULL, 0xDBAA75FF1914C1DBULL, 0x8F40FE812B834C08ULL, 0x63609F157323C69AULL, 
            0x5C09D375681E4DC8ULL, 0x38D51B8CD778A208ULL, 0x8D788E18CCB11054ULL, 0x10A0857D64CCB58EULL, 
            0xADB8A37D02C41C5AULL, 0xEBCE5FF802D5840FULL, 0x9AF39268CAB228B2ULL, 0x9AE8D9C167B87198ULL, 
            0xF245DC9AB8C073BDULL, 0x6F247EDC802771FFULL, 0xE282781188CD0578ULL, 0xA7BD7573C0A7948FULL
        }
    },
    {
        {
            0x0CB5EF3FCE1EE5F8ULL, 0xC5D9687D1AF7142AULL, 0x10E297084EA6A8FEULL, 0x30C3C590FA459A8CULL, 
            0x1F1757972E6858E3ULL, 0x52826448C1321149ULL, 0xC76447A5FCBBCA80ULL, 0x5B551FCC670E20C3ULL, 
            0x70F5662DC818C42AULL, 0xB45293EBC2F5C8B1ULL, 0x5FD6DE5EC3D2E964ULL, 0x332F2C4EEEA57FC8ULL, 
            0xD9DADC05A5526278ULL, 0x2DFCCD00C0127599ULL, 0x45E4738D55B15FD1ULL, 0x4677125F9218042FULL, 
            0x5070B3747405CAA9ULL, 0xB5C4D2B0608DC0DDULL, 0x000DCE41636B5808ULL, 0x8E073D48F6D1656AULL, 
            0xC9CAA02D013F304AULL, 0x69245ADA47490020ULL, 0x264143F73285F476ULL, 0x1730FE78AAB9466FULL, 
            0xE07AB261A7971D0FULL, 0xF7DCA61CEE9C138AULL, 0xB527E2EA3FBACCACULL, 0xD9A319461F0E7B35ULL, 
            0x00763AC3555C6884ULL, 0x8335DA25393162E1ULL, 0xC52E37E564ED0C95ULL, 0x5DA66C728EEA21FEULL
        },
        {
            0xE4E94A7DBC0E4C16ULL, 0x1B0374D7E7AEAF24ULL, 0x400449A0412D11D0ULL, 0x6E8BC8DED4895181ULL, 
            0x57EC5FF1FA8BD7C7ULL, 0xA27B17FA11ED950DULL, 0xB9CB9BA2BEE621F8ULL, 0x3A7037352645658CULL, 
            0x3D156CD96AC7EF4EULL, 0xC9FB2A7CB8147C77ULL, 0x2E7C717944737139ULL, 0x1E91273F5F30C39AULL, 
            0x0CF4617DB30E6F33ULL, 0x4FEC994F28F78A7EULL, 0x59ACFA8F35128763ULL, 0x0E61B0F2BB8A0122ULL, 
            0x4C27A132E4F3A52AULL, 0xDCDA9D905196341AULL, 0x527675D85004DADCULL, 0x06BD492A56BB1890ULL, 
            0x464DE8B1AAB95D84ULL, 0xD6EB2C2CECF8BB18ULL, 0x6B1DBB1469CFA0CEULL, 0x5BCFC2A08AA7ED12ULL, 
            0x6E45F0F1DE314462ULL, 0x8D379D5AE04FAA51ULL, 0xB97A7728B81CB333ULL, 0x7B9291B78231C2EBULL, 
            0xD4CD9122BA3A8634ULL, 0x05752E1514FD359FULL, 0x6FCE088099F128C7ULL, 0x5D1824B135E4F6E5ULL
        },
        {
            0xDF7566793E745040ULL, 0xCF161F488F0C3A68ULL, 0x836387AD2E088285ULL, 0x423A09A48DAA594BULL, 
            0xA428E970E3AC8EFBULL, 0x30345B95C949C2EAULL, 0xE99F6C7F0BB951C1ULL, 0x66D137FE67370A10ULL, 
            0x892460675100A514ULL, 0x65723C5E6A90665CULL, 0xAE4F5FF2CE5377FEULL, 0xFF93A6396BD7C742ULL, 
            0x4BA650FBF7B4EFE3ULL, 0xD5B60ED369F075ADULL, 0x78F57E90F4038190ULL, 0xF86970A8FB446FEFULL, 
            0xA6500EB9F36CE303ULL, 0x19A0DE15440ECB84ULL, 0x0C0B3CF47B47C909ULL, 0x5E8329DFFBF38ACBULL, 
            0x8709F78C63676AA1ULL, 0x18E76FB1DC41D1D7ULL, 0x570DAAE46BD653C6ULL, 0x7DA9233ADF214900ULL, 
            0x15BFC3A88BA3CC90ULL, 0x07CC3780CCE21BD9ULL, 0xCFA8837788248959ULL, 0x109EB1A8EE3AA6A1ULL, 
            0x3D5F01B8D4584FC1ULL, 0x41A704BB1BBC386FULL, 0xF97470FC79EEAD0FULL, 0x645C691CCFDFD315ULL
        },
        {
            0x99BAF1E0626CA2B8ULL, 0x80A09383F077C810ULL, 0xA5BD94BFA0BE04F0ULL, 0x25C1793FD7444F51ULL, 
            0x91548DF5EC25977CULL, 0x7C5E0A7405697323ULL, 0xBDA5EDAF4440E2F9ULL, 0xF27D31AD352F55AFULL, 
            0x40F7109E409A36F8ULL, 0x80CB0D851E5086D6ULL, 0x8921118A5F5CA746ULL, 0xE42008032F56214AULL, 
            0xE994A3F8020B9A56ULL, 0x37E1886C4316596AULL, 0xC8B50E3075A95349ULL, 0xDA5407910D3AE361ULL, 
            0xDEBBEBAE5980E3D5ULL, 0x8183D3FFC29601DBULL, 0x84108B27B61C56FDULL, 0xA747DD4C355CF027ULL, 
            0xE5282FB2D8A356AEULL, 0x448700E19A6DAED8ULL, 0xD774882A12F61483ULL, 0x1E1FD5ADC82BA805ULL, 
            0xDA6A79D0D740C0BDULL, 0xC8248FE474CF13D9ULL, 0x6C604A2BAFA8ED56ULL, 0xBA801E072171CAA8ULL, 
            0x767A695CD76DEAE9ULL, 0xED4BF7782683607DULL, 0xA6C6C47292CE805AULL, 0xA1ECF3620FDE8A41ULL
        },
        {
            0x015D611505325761ULL, 0x8B871C31C847957DULL, 0x97541E148E12D97CULL, 0x58B6543D3DF830A4ULL, 
            0xA155235BF301019AULL, 0x24303863BF421140ULL, 0x9FF3D5E98CCFB405ULL, 0xF44FF850EAF7D62DULL, 
            0x5A8033B8AE6594E9ULL, 0x9B8BFB2D7693CF0BULL, 0xFE7F9474EF970A8EULL, 0xC7219A599795182EULL, 
            0xE2ADD233478A3FF3ULL, 0x6AE790B45D562108ULL, 0xF6E745BBC2714CD3ULL, 0x1C46C24F692EBDFBULL, 
            0xCA7341ADFA8746E7ULL, 0xAC45576EEBE503A3ULL, 0xEB322C15D7126B5BULL, 0xB2ECE8C38DE3A55BULL, 
            0x6FEF8E3170B8B6FAULL, 0x9FC9375904640F9AULL, 0xB432B0FA668FAAECULL, 0xD9B64D92216DD4D2ULL, 
            0xD50564D8B64EFE28ULL, 0x894F051E783AD642ULL, 0xD3F3E7819ADB99D3ULL, 0x7FCB6BFF42B623A1ULL, 
            0xBDE0BF3E09EFA870ULL, 0x226B6C3081797E9EULL, 0xD0CA986DD6B37A5BULL, 0xBF3717DADFA86C1BULL
        },
        {
            0x24ED1BA67AE9F802ULL, 0x4F5A8BC97194D78AULL, 0x4C6931CCC969AEFBULL, 0x3BF5CF33326288AAULL, 
            0x1062543192871FC2ULL, 0x45B6594852E3CFDEULL, 0x8BE6760C4B3B979BULL, 0xD1E2629DB6A116F6ULL, 
            0x982A8236C33CCCE0ULL, 0x49A9A2D004722190ULL, 0x37AB9BA175AA8D01ULL, 0xE35D4CB143FC8C12ULL, 
            0xDA82A685B5D0DE79ULL, 0x2367EDB70FDA31FCULL, 0x7CB90E90F0D71F0BULL, 0xF70425F730C8DC25ULL, 
            0x4A22902751990EC3ULL, 0xD968F2812ECAE888ULL, 0x9419981100FBC00DULL, 0x960ACE46DBEB3B44ULL, 
            0x8AE729046C74CDD3ULL, 0xA74692712A0DB000ULL, 0x968CFC1697B14105ULL, 0xF2DE31F79EA816C4ULL, 
            0x64666211069F1638ULL, 0x6BF1CA8F72F8F23EULL, 0x853E101EA6149936ULL, 0x57C913C623B25B86ULL, 
            0x821F54029593B88CULL, 0x35F3F89227E39001ULL, 0x1F46E1251E4371F3ULL, 0x16D5826CF8828DC2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseFConstants = {
    0xB9264E5B44FBBF9EULL,
    0x14E6C4DB683A940BULL,
    0x25F0E8B5D47A802CULL,
    0xB9264E5B44FBBF9EULL,
    0x14E6C4DB683A940BULL,
    0x25F0E8B5D47A802CULL,
    0x6904256C3B6894CBULL,
    0xDE29BBC3639F10C4ULL,
    0x10,
    0xD6,
    0x25,
    0xCC,
    0x76,
    0xFF,
    0xCC,
    0x4E
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseGSalts = {
    {
        {
            0xAA0CA0B763CE82D9ULL, 0xF49DCC2D1269CF58ULL, 0x9EF813242BD4A26FULL, 0x773510D8EB6F3B05ULL, 
            0x4D4FB058FDC73135ULL, 0x75239BD9BE44FA52ULL, 0xCD0226DA98494B24ULL, 0xD5D8849EFBB5C113ULL, 
            0xE7AF305F603AED2DULL, 0xA5893BDB3EFBBFECULL, 0x38A5521396FFCFF5ULL, 0xA5FB3782F4BCEB3AULL, 
            0x6F9C11DB65459F4EULL, 0x8D0CCF48DF511501ULL, 0xE3776E5D03BF3A1CULL, 0xB07FA9C9C00296F4ULL, 
            0x5C46462BADDEB84BULL, 0x6D731DC2BFC74841ULL, 0x3C4EB396BAD5DF40ULL, 0x87CB6D82823482A2ULL, 
            0x1F5B19B55184D00EULL, 0x949B53B10D7CE48CULL, 0x90EB28167F8558CEULL, 0xE25CA9B704E59440ULL, 
            0xCB1DB1D70B52AC12ULL, 0x2982FA8D009D80ABULL, 0x3D740774935EAE9DULL, 0x738E9F55181A9759ULL, 
            0x2096750FDD20F12AULL, 0x088A3DBFBCEC67BBULL, 0x4B8F4B9790EC29E2ULL, 0xEEC6EF26C160E375ULL
        },
        {
            0xBE0E9C8123034822ULL, 0x28AB10B3D6B2B866ULL, 0xA4F5700AB3BC43ECULL, 0x8CE7072DEF7F52A6ULL, 
            0xD46F22C3497EAD83ULL, 0xF6B4611B6EFCBF7FULL, 0x12A083EF95DFA139ULL, 0xA670F579D3B07E78ULL, 
            0x6E29A97295028352ULL, 0x49067D14C2C48143ULL, 0xFA1CB07253316E3AULL, 0x71184201099F6820ULL, 
            0x0C248C6A22FBEBD4ULL, 0x30A15548017D9BBDULL, 0xBDBF080B2735A047ULL, 0x4D3BED3FEF5FEAE4ULL, 
            0x1D56FCF2C5DF3A3CULL, 0x155A6F9951A373CCULL, 0xDCB162897715BED4ULL, 0x193D3D64EB7D960BULL, 
            0xA6415E6838FD063DULL, 0xA82E2CC4B1448AD8ULL, 0x3E156EB5A745AC19ULL, 0xFC60F69C27AADF21ULL, 
            0xD0AF19A5D43074D5ULL, 0x4AAB46497B600F9DULL, 0x864830870C0D6009ULL, 0x92D767F5A132E9D9ULL, 
            0x4E188482901B5A51ULL, 0xB60A67871D96C2EAULL, 0xEC7A5BA27DEF8914ULL, 0x399C052D3F53CC2AULL
        },
        {
            0x92562CF68492C5DDULL, 0xC635F52A0770EBA8ULL, 0xD50925FE2F4B7591ULL, 0x37E89751D9B4CD49ULL, 
            0x8ECAB4B23857845AULL, 0xE5997DB6D0D8B24EULL, 0xA74EBBBE6F9A5472ULL, 0xF215C075A729AD71ULL, 
            0xFF802E479D4D0C43ULL, 0xF0518477AE338523ULL, 0x37C32C7791CDAF9AULL, 0x15656A9E0DAB9757ULL, 
            0x9FF272369DE7E143ULL, 0x5E8CF77929EFC9DCULL, 0x92E92D685401C834ULL, 0xE801221D38DB637CULL, 
            0xAB1E931D916B3F39ULL, 0xDD09D21102470D76ULL, 0x2E854267151A0028ULL, 0xABDE2D60B4233433ULL, 
            0x8D50C5D93FEFB61CULL, 0xF9B0C73197BFA653ULL, 0x22F251F7CAABEFDCULL, 0xDB16DB7FE3C67D2AULL, 
            0x64F8EFCB5DCDBB7EULL, 0x3A0255248B46E463ULL, 0x47E1CD51A45BF865ULL, 0x478492476438CC0DULL, 
            0x7201A3A75B8BA6D2ULL, 0x2FEEF654EC83D256ULL, 0x5161DAF81BC887E8ULL, 0x228B6C5E72F2165AULL
        },
        {
            0x515831B14C184C86ULL, 0x704E7A6B8292889BULL, 0x085A73B6D223B725ULL, 0x190EE7F295185754ULL, 
            0x445C0D95DEC149AAULL, 0x927DAB4197024209ULL, 0xC7E3C2665BE5C816ULL, 0xF897C879E7915235ULL, 
            0xC6DB6B01B02CFF39ULL, 0x173E149231395C57ULL, 0xE238537906B6CF49ULL, 0x5E66984CC393A07CULL, 
            0xE16ABACB7AC897B7ULL, 0xF7C4BD8303DEB856ULL, 0x382314D35E0CB039ULL, 0xE257C1B567A27A06ULL, 
            0xC2A85AD967CD3C3CULL, 0xB3A42E098B8C0E7AULL, 0x5A6ADE93B19460DCULL, 0x9FA0D4C9980ED165ULL, 
            0x6F9CCA9A437C7432ULL, 0xD8F768DBD1CE43CBULL, 0x5DC6A645DBF9011BULL, 0x524701AA926DE76CULL, 
            0x16A103057923A642ULL, 0xD77236B490D18C77ULL, 0x7FA7172E5BF4030DULL, 0x3D935ADBEA612375ULL, 
            0x65B39737DE55AD10ULL, 0x637387FE80346DCBULL, 0xD95B8EBE3B53D2DFULL, 0xAE7D3ED1D7B7AEFFULL
        },
        {
            0x10571B482C3D6600ULL, 0x0FA138FB85552D69ULL, 0xBE78329362C4DAFDULL, 0x12336BCF9EDC74EEULL, 
            0xAD9ACC68F8CC40ABULL, 0x9D2BA1E53ED5FE5FULL, 0xE8CFF9A75C40A7E4ULL, 0xB23BF5CB9D8CCBBBULL, 
            0x4AD09D5FD2D9E44EULL, 0xC0A257BCA20B4D8DULL, 0x2BFE49FD68BE555EULL, 0xAC1EEC1C7035F1F7ULL, 
            0x4FFFD1BB26F3439CULL, 0xC701F417E2194EC9ULL, 0xCFDF87D7A89C2505ULL, 0x9E7DE79AA2CB94CDULL, 
            0x10D0C8E28493ED8FULL, 0x5A044B3FE43046F8ULL, 0xCF1E353BFAA1BFA8ULL, 0xCD491689EB767BBFULL, 
            0xDD20535CF9FE48FFULL, 0x817A2AA777B777F0ULL, 0x57BF84C87957A139ULL, 0x3DFFDDDC46943BFDULL, 
            0xF09C34FC125D8207ULL, 0xE1B6523289862E7BULL, 0x357745545D414E3BULL, 0xE0963D677C110A91ULL, 
            0x626CFD6EBB532EB7ULL, 0x9D507594D32D3B96ULL, 0x08A8F9D8EA870575ULL, 0x163B9F93DC68D998ULL
        },
        {
            0x2D57F4E25D95776DULL, 0xA1AEF02544703F66ULL, 0xB6F152A8440A7110ULL, 0x8D68B06A8A3EC6D5ULL, 
            0x9C0F2090D04CE347ULL, 0x49CA1E9532460471ULL, 0xC52E7A67DA9C85CEULL, 0x3FCC0FD46593A585ULL, 
            0x47DF26E3859DB83EULL, 0x869AAD69120681A9ULL, 0x659FFAE2C1E1C811ULL, 0x3E271EE0D9607B87ULL, 
            0x10C54ACAA5F20E9EULL, 0xE14C98CD1B737472ULL, 0x7C0F066E569F50A3ULL, 0xD81723D90FEEDA0CULL, 
            0xC85185FD25F1AB0DULL, 0xD38C6F7855A7EA04ULL, 0x020C627C84F22229ULL, 0x1E3512CA889BADCCULL, 
            0x5D4A44E4DE100403ULL, 0xE822186DFC2514C6ULL, 0xF4910936E448C310ULL, 0x826518062FDAA694ULL, 
            0x6D08AC92F4FE420BULL, 0x4E5E9F0239ED0F32ULL, 0x6C05D2622471ABAFULL, 0xCA37DB99DD038C3AULL, 
            0xFBA49D891FDFB3A0ULL, 0xD32FB8EB08BAB44EULL, 0x2219BBA09BEFF34AULL, 0xF2BFC8CC70A124C8ULL
        }
    },
    {
        {
            0x74C81AAF5A3A2F8EULL, 0x57556EDF78888678ULL, 0x505E39CE25A775E8ULL, 0x7EBB8814BC1C1BE3ULL, 
            0x440A98B991952ABFULL, 0xD6AECE10E2A1CE72ULL, 0xD36F5EBBBCF27B78ULL, 0x3D8D061B0709CEDCULL, 
            0x74D15EEDA024EFF6ULL, 0xAB3D5AF33CC36749ULL, 0x7799A46223BFEACFULL, 0xD6DEF9638DAA130EULL, 
            0x9A3A0445216B6779ULL, 0x3DF25E1D7F185017ULL, 0x7740A63D2535D1D6ULL, 0xCB11500FA821EF40ULL, 
            0x7CAC3E0D53A35359ULL, 0xAA691DC7D031DA3DULL, 0x3D1D6EACAD6EE3D5ULL, 0xA93EA70685DA2379ULL, 
            0xA5A001E9F1E5D19DULL, 0x0B67D66C3043662FULL, 0x4DE808A7ECA8560AULL, 0xF2CB60654258679DULL, 
            0x75BA99F6EC22FA85ULL, 0x4E7C0358F2B2DFCBULL, 0x12CDA58514DDF714ULL, 0x5E74C58C027D0AC0ULL, 
            0x292D6CE3E88C8F7EULL, 0xAF613BDEC8370170ULL, 0xD64BAFFA5CD9BFF4ULL, 0xA133F9370B66ECD5ULL
        },
        {
            0x50C709D96495E027ULL, 0x164F65B7A6E39009ULL, 0x1F5C7F7F5EC8D338ULL, 0x40AD5CC32935C8BAULL, 
            0x97B884F7ED9755F7ULL, 0x120998F7B0B1F635ULL, 0xBD25B5696729AE4CULL, 0x14F4142CAA57E9D0ULL, 
            0x72055E44BFC597DCULL, 0xEAC4E8F0ADF1EA51ULL, 0xCAC00B25FB22A1CBULL, 0x09F4C42BCBACA569ULL, 
            0xE7A27D10C74B3BFEULL, 0xD90752025D5C1887ULL, 0x4D076E045CF32FE6ULL, 0xE585DB1109CB4497ULL, 
            0xACA0201D5FF6A123ULL, 0x7B65334F41978676ULL, 0x4B04652F7B3A6CF4ULL, 0x1813891EB7DCDA57ULL, 
            0xADB9F8ABF6B817E5ULL, 0x61B1EE0C55D2A7C9ULL, 0xFCC66199D69F24BAULL, 0x9640EC506B7F4179ULL, 
            0xBC18AEE63E5D9588ULL, 0x2EB2AA5146C25E04ULL, 0xF4E73C0D3B2CC4D3ULL, 0x1D0F896192956C18ULL, 
            0xCD261778F23E1E82ULL, 0x739E5547FFFDB594ULL, 0xB2C9F6BBC07FA3F2ULL, 0xAD06FEB17439A1C0ULL
        },
        {
            0xD8F019BD75A6F215ULL, 0x0D722BF5112A5D9BULL, 0x5039C75CCEE6CF54ULL, 0x0BDE7791AF530E6CULL, 
            0xF4BD57720B297DD0ULL, 0xD35AE4B35EC4298EULL, 0x19D3259FC5176D44ULL, 0xDA1F9A03826665A5ULL, 
            0x2FBD274AECFF423AULL, 0xC00EAED99731F830ULL, 0x75A4DA40D3682316ULL, 0x9A161ABA1BF066E8ULL, 
            0x480FE3005BFE7D96ULL, 0x8E1F81B96727D7C9ULL, 0xB8BF783C17869B44ULL, 0x4F396B4A500F3CDBULL, 
            0x9F68EFD815CFD7F6ULL, 0x819B8EB60C089043ULL, 0xDDB805F74434BC46ULL, 0xE2E1C699BDC6BBCAULL, 
            0xDE00166613BBB88EULL, 0xCF13DBFFD93D7E04ULL, 0xE85799E0395889D6ULL, 0x945EA5839DA84FD8ULL, 
            0x84F9F513B2E8E551ULL, 0xEDEF9D573A3E182EULL, 0x484BD5280210D2E1ULL, 0x2A4101DB833BCDCFULL, 
            0x948D0BE45ECABD70ULL, 0x63B320C69B59D4D4ULL, 0x3CD4AB1329D38DBBULL, 0x1C2C451EAEE18D2EULL
        },
        {
            0x7B4F520C1E5C3B15ULL, 0x33863586007BC7A5ULL, 0x584E90400D52BFA8ULL, 0x5755D8CDAC10304DULL, 
            0x774252D75343435EULL, 0x8672AF14F8687244ULL, 0x9C940468FB63E981ULL, 0x7891C9C2C0F932D3ULL, 
            0x5FB3AD3C30B54120ULL, 0x2ABDD4C4A869196CULL, 0x32913C04D8D7B169ULL, 0xBE8F6BA1552BBC08ULL, 
            0xA5FF69DC10CB9D91ULL, 0x71289B3933B156E3ULL, 0x954978ABE3794C8EULL, 0x8B6E34E2BEEEC42AULL, 
            0x38B16D34B75EFE54ULL, 0x3B0075012A93DBF5ULL, 0x04ACD1FD49D97D7CULL, 0xFCB3EE3D22E44B26ULL, 
            0x38C67A0E352A8C67ULL, 0x0FEA5E7D79DF91FDULL, 0x078E024EA8687797ULL, 0x8170948224ED30E0ULL, 
            0x01B1F9A977333013ULL, 0x3CE69D71BD4B10A6ULL, 0x3BC799F29E55EA21ULL, 0x8EFA15807773A360ULL, 
            0xA47DD88C64287CE9ULL, 0x5B64017887CEE8FFULL, 0x11F2EDA07E608E2EULL, 0x118371A86F146C71ULL
        },
        {
            0x8F2AF8EEE84A83ABULL, 0x8721383DCE74B9A9ULL, 0x95FD3FBB63348A49ULL, 0x9B3335D9930CC1C7ULL, 
            0xA4B5DCA5E59EC27BULL, 0xD4D6D23FBDE1095BULL, 0xF2089354DED2A55FULL, 0x619A769E7DDF316CULL, 
            0x6555D43FD317DDAEULL, 0x2C3C5FCF0096F4FEULL, 0x95DE863FC16F3BC0ULL, 0xCCD37F261046EE86ULL, 
            0xA16285BCF2DD6525ULL, 0xD9622864C84CCF91ULL, 0x0612C94C5AC509CFULL, 0xD81E22080BD97DCAULL, 
            0xF513E810D6AF38EDULL, 0x7C44A620BFB862D7ULL, 0x958A736D62EF5421ULL, 0x6128C1C27DF8FB50ULL, 
            0x1F5854D48E88BCC3ULL, 0xFFF16A5C978EED76ULL, 0x84281190921DECF4ULL, 0x5CC703F1995C23DCULL, 
            0x4FF3192468D32B59ULL, 0xAEEF086FDE1DC1D0ULL, 0x248DD2F08623D616ULL, 0x7E7AE2D9E7461890ULL, 
            0xC5FFBEB1BDBB7414ULL, 0x6911AA104EEC45F9ULL, 0xD26382A3582DA0BFULL, 0x7A66E2E1F63F1DA7ULL
        },
        {
            0xEEDB62E015685427ULL, 0xD1D0084077125DBBULL, 0x1539EB349F3EE5F5ULL, 0x7A3029276B0F93A7ULL, 
            0x35A7DF9513EDE172ULL, 0x185DE057805806AAULL, 0x188A8DF08DB50BB5ULL, 0xC1378F55B1929C88ULL, 
            0xBF9CF72EB86BF8CCULL, 0xE4181AE3AFF49A9DULL, 0x63DA5C0148D4CC9BULL, 0x441A9691AD1D8354ULL, 
            0xACF11E116C064C1EULL, 0x639EEF19672A2EA4ULL, 0xD250AF8009037476ULL, 0x18D9BF35D876F839ULL, 
            0x6D912F466CB8C560ULL, 0x046B5E3DACB91D7EULL, 0xAFDEB6A2437B8101ULL, 0xF8D4A3933B18A647ULL, 
            0xC104791F135FF165ULL, 0x5C995BA6060EEB58ULL, 0xE941F7D43AD25BC3ULL, 0xEAD9A2191DB3A068ULL, 
            0x35C155FD6A7C4F62ULL, 0x7A64AD6A013C5A23ULL, 0x34907E1986F5B13AULL, 0xA4E134B61B54D1DAULL, 
            0x68968669F4CFB0B0ULL, 0x00351FC44163DF60ULL, 0xBE826BEF7F16D4F2ULL, 0x40D4C93274BF4200ULL
        }
    },
    {
        {
            0xEC651EC052B1EE88ULL, 0x1664F247ADA7BC63ULL, 0x7F1D258158126CBFULL, 0x11989C59A9BB30C0ULL, 
            0xEF9536B7D5D076B2ULL, 0x3401987AEABCAEFAULL, 0x4AAB7424F109D542ULL, 0x99E0746A0C743B15ULL, 
            0xC818B32C45C49A98ULL, 0xD32DC5B06F3CC351ULL, 0x13E55D3EFC251513ULL, 0x63942D0FF3AE4E81ULL, 
            0x56ABED690090AAC5ULL, 0xCAD1BB1C9F03C37CULL, 0x2534379A71C3147AULL, 0xE55861CB7730FEB1ULL, 
            0xBB373ACEB5AC6E37ULL, 0x3C513F439530281BULL, 0x6E16713D4BCFAFBBULL, 0xC31450C43B69B10DULL, 
            0x0C40451CA030F074ULL, 0xB90D893CD4C26702ULL, 0x3FAC53C1D0FC8F2FULL, 0x0728AAEF44621904ULL, 
            0x2DAAC512711C9B30ULL, 0xC52AD6BDF8635BC3ULL, 0x372BC71C59C387C1ULL, 0x8DED8CC95BB27D56ULL, 
            0xA8A35E5FBF055D54ULL, 0x107B9193DECD0ADAULL, 0x114149CC4AD749C3ULL, 0x95679A9B3C87FEB7ULL
        },
        {
            0x2CB3D21EFC200FE9ULL, 0x07009F3546A90BD4ULL, 0x3210012D43AF9638ULL, 0x25899EA411A08099ULL, 
            0x5D8450D34F898279ULL, 0xDCB2C8C49710F479ULL, 0xAC32BF0535E58EC6ULL, 0x80EBD32310D7F7F4ULL, 
            0x2BA4D8F4A37D2EFAULL, 0x676518CBB21BF466ULL, 0x51A20F51F635863CULL, 0x2E521513128491B5ULL, 
            0xE991AA9742D4E3C6ULL, 0x5191081ED7A1153CULL, 0x6E34E7614A49F3DAULL, 0x8F2C3D19D2995776ULL, 
            0x86D830C8A249F9DCULL, 0x0675E81628C5AD1FULL, 0xEBBB7F21B4E19533ULL, 0x9EA8418043172FF4ULL, 
            0xDF4A1CE4D05BE0DAULL, 0x1377C51016BF49BDULL, 0xA97FB12C2BA98228ULL, 0xE18224ED6FF0FA91ULL, 
            0x93E054D1B9F00B62ULL, 0x81F04DCB0F7049D0ULL, 0x1DC0C86335FDDB33ULL, 0x5A7330B7201DD807ULL, 
            0xA3F929B194C1A80BULL, 0x7AED04C155639D44ULL, 0xD115B579A9BA40BDULL, 0xEFCFCB5BD64A9F65ULL
        },
        {
            0x3E38C1F176926DF8ULL, 0xFAAFB0F5D07B351FULL, 0xADB0CA3CC083D3B5ULL, 0xF9E886E1DFC37CF7ULL, 
            0x013C0BAEB731B077ULL, 0xF137DDBF117FC1B4ULL, 0x6080000A1B1D38C1ULL, 0x2CC248543CB9C9AFULL, 
            0x60B567B468138586ULL, 0xF09C634415A4A3A0ULL, 0xD9B26BF0A31A2BF7ULL, 0xCAED897DFC83CAB2ULL, 
            0x4A747B75F21D1405ULL, 0x5B7F1BCD8CB2E640ULL, 0xEE2B23BE9316B633ULL, 0x446B69548DD525A3ULL, 
            0x4304FB8C4C58CAF0ULL, 0xE1083BE6745A3B32ULL, 0x6988F043EDC4FCBDULL, 0x82F78044E3B640B0ULL, 
            0xF0401FBE84A04939ULL, 0xD75839BAF69C70CDULL, 0x2C4A6E10129F0044ULL, 0x9BFD1A4B33ABB4B3ULL, 
            0x7F423B5C6D19E30AULL, 0x5CEEEE84F7707719ULL, 0x109396117978AD59ULL, 0x7898AE04FF7AC52AULL, 
            0xE7C2EA0EED428D2DULL, 0xA2078159287ED441ULL, 0xF8566C457B18114DULL, 0x19761B98801A7AC7ULL
        },
        {
            0x2E268541155C2BA1ULL, 0x56CFB08C7356BC32ULL, 0xD37177A5B03E1793ULL, 0x53336779BCB054ACULL, 
            0xC618C086695554CBULL, 0xB8CAB70C13329F36ULL, 0x41740904168CF142ULL, 0x9539D8B66A08E87AULL, 
            0xBB0872B7F47361F5ULL, 0x8B3BBD13390CBDA6ULL, 0x1B225F5D94BBB5F1ULL, 0x4431118B689918ACULL, 
            0x1655045682B676E0ULL, 0xEBF6EA4999A2F1CFULL, 0x371FC40F0FB8FD36ULL, 0xBC14E603F1D6DC23ULL, 
            0x7A307807E2EC8503ULL, 0x8825F4F65308B839ULL, 0x255904A9F4B04BFEULL, 0x4E63BC0A707DB940ULL, 
            0xF958402A7A286BB4ULL, 0x0E77A34742F472D2ULL, 0x6FBE335040BBB95FULL, 0xACB5A39AF75BA02DULL, 
            0x037D59D787BAE693ULL, 0x98F746A259BE2095ULL, 0x2E579B6E88C4CD9EULL, 0x8424F76060B948EBULL, 
            0x531BF9EA21700A16ULL, 0xB6C890767AB59292ULL, 0xAA29DB1BBDFBD654ULL, 0xA26236C4543D3B96ULL
        },
        {
            0x66ECAFBAD0AA8174ULL, 0x98B411B9C7620E03ULL, 0xBE48B84033C34A32ULL, 0x69E793927A484721ULL, 
            0x288230522EACD990ULL, 0x492D0D9E68D3C50AULL, 0xF881140A2F0862DCULL, 0xEE6AC789CCC0C481ULL, 
            0x301CA381847EDA94ULL, 0xC0838D56F55EEE29ULL, 0x4B53DDBFF88360F8ULL, 0xE157D5A39DEFC2D2ULL, 
            0xF609E821A782F7EEULL, 0x510FBB7E71D73077ULL, 0xB8634B0B447FE032ULL, 0xC98345321C4F67C4ULL, 
            0xC8A24C991BCCF166ULL, 0x4D3E5646FCAA962CULL, 0xDA812651836651BEULL, 0xB9AE6F32520873B5ULL, 
            0x16F4F8554F001A2AULL, 0xB0EDD98B418B5568ULL, 0x3BFB01675393A38FULL, 0xD91F9A72A81F9E26ULL, 
            0xA8F2983C37FB16B3ULL, 0x20C439C3CCAB9A34ULL, 0x7B6AF565C5BFA568ULL, 0xFC9289CB84611414ULL, 
            0xA8161997E8E75AA4ULL, 0x1E84F1A9D9C02124ULL, 0xE5FB8D245E186F9FULL, 0x83427EBC87FDA8F4ULL
        },
        {
            0x069E8CB7D5D1605CULL, 0xA99FCF2D1EA098F5ULL, 0x883B83B2A97AC894ULL, 0xA68C5B82BEDE8283ULL, 
            0xB7AC75D679B5A142ULL, 0x77E9E3584ED7B9D3ULL, 0xCE4DAE6A004937C2ULL, 0xB077918108AE605BULL, 
            0x0335AD6906F1E5ECULL, 0x5FF32D3BBC2CF7EBULL, 0x48E7DDB2326197A7ULL, 0x02CDBB0A99DD80D2ULL, 
            0x30CAD24B136525C5ULL, 0xF65DBD99096A6405ULL, 0xE3E6F584AEDC2DA8ULL, 0xC8826E85F1863D2CULL, 
            0x64D4FED4353A4CC5ULL, 0x43AC3B9AC8308BD3ULL, 0x96180A27DBB9D039ULL, 0x0686C4FDD1BAA17FULL, 
            0x3F9561BE77F59096ULL, 0xCFADE69583E1B86DULL, 0x528605DA3F3FD04CULL, 0x37AFE070AAE28FD4ULL, 
            0x2C9676E0EFF25063ULL, 0xB6B214996929154BULL, 0x6670A0D3F8BCEEDAULL, 0xDD000CDE99069E07ULL, 
            0x6827FC61E2911DCBULL, 0xB8C72352A5F8F1A2ULL, 0xE985E5F4E8B9742CULL, 0xC055DC50BA533334ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseGConstants = {
    0x635A2081A095B892ULL,
    0xA066FA814BF20743ULL,
    0x1337A1C375363618ULL,
    0x635A2081A095B892ULL,
    0xA066FA814BF20743ULL,
    0x1337A1C375363618ULL,
    0xFBC55CF48EE8F8FEULL,
    0x8A7CA9FE8610A051ULL,
    0x3D,
    0x2B,
    0xF5,
    0xC2,
    0xBE,
    0x29,
    0x3E,
    0xB0
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseHSalts = {
    {
        {
            0x9EC4B25A1E9C3588ULL, 0x3A5690613607E89EULL, 0xFE8BCA8E6071A060ULL, 0xEF234EBD9E509018ULL, 
            0xED7E331968EDC640ULL, 0x3F4FC8BDF68E7C59ULL, 0xAD0A5541EA722F73ULL, 0x3CAD843FEA9EA17DULL, 
            0x3177D271CA72AE28ULL, 0xD5A2BC0894672166ULL, 0xB608F4984CE86348ULL, 0x1FBD428183D1F32CULL, 
            0x2EFF5BD578B69CA8ULL, 0xF0958D05CE766509ULL, 0x8848ACADFA195E26ULL, 0x313AC9665934FAFCULL, 
            0x406BA0934BBD4D0FULL, 0x5F5B74090182B41DULL, 0x277D4D1EFAC96D6DULL, 0xC4A9406213424628ULL, 
            0x68DEC899C7D0B797ULL, 0xB8D405557E7411EBULL, 0xF96C807BC02CFCEFULL, 0xBA178E9A213F65CBULL, 
            0xDC9CEC0E78A13706ULL, 0x8D189C4841B7A22BULL, 0x4074FA86C7C831B8ULL, 0x2A0D64F06420DA62ULL, 
            0x0872EDED2B012D0FULL, 0x7D932753321E27DAULL, 0x3A387E422B317640ULL, 0xE5D6F1345193A3D9ULL
        },
        {
            0xAAA20BFDB1F1738FULL, 0xCE0DBB062942EEBBULL, 0x0ED1CF361C5FDBD7ULL, 0xDC42F5CE7B024832ULL, 
            0xEB834744F2F09AA3ULL, 0x8890B74D5F4E862CULL, 0x0B75EF75FCAAC9EAULL, 0x62397E6CE87F3369ULL, 
            0x0140324442219A01ULL, 0x7D381BDE20C03D52ULL, 0x23458C929F81C9DDULL, 0xBB8CA6B1E39E6826ULL, 
            0xAD1933C059A3F3E0ULL, 0x55C19B2865F9B003ULL, 0x64B2E4F7D68FEE0BULL, 0xAC8F01CC2CDDAC19ULL, 
            0x09CF2BE2D84FCE64ULL, 0xE808297AB10AFB3DULL, 0x77125268D4FD9048ULL, 0x9309F64E90CE60F3ULL, 
            0xF2499BCE38875782ULL, 0x4AD2FF6B5FB6D5FFULL, 0xA0D5E70930D96D0DULL, 0x7CC0427F0CD428F4ULL, 
            0x24274ECCB1EE814CULL, 0xE86B372B18F9BAABULL, 0x13748294A10EAEF6ULL, 0x344B32D1538C566EULL, 
            0x86A976862A398561ULL, 0x95FE87BC600BCD82ULL, 0x0071CD29ECF407A3ULL, 0x8C7AA765E6B83C3EULL
        },
        {
            0x491C792FFA465FC6ULL, 0x9B41316432BD31C2ULL, 0xACD5293B4515DE80ULL, 0x545D9B552209EAA1ULL, 
            0xB9851B6DA5307201ULL, 0x1B68EBF3B9179BB2ULL, 0x7103FC4489B7A28EULL, 0x77C81D3989B32A40ULL, 
            0x54B6ED81F6B5C954ULL, 0xDF2ABF4B62FAFA7EULL, 0x470451880EBD2706ULL, 0xA3F77716B23EE4D5ULL, 
            0x19C61621729D4826ULL, 0x1E5EB478289AA8F1ULL, 0x8C355FCBA60974BDULL, 0xEE5AC85070A58801ULL, 
            0xFA1DC3B07710C810ULL, 0x910342192B627062ULL, 0xBECF90839A59C2BAULL, 0xE7FB00FF909799A0ULL, 
            0x3774BAC3AE7FDD4FULL, 0x647DE4F0C6815727ULL, 0x828DD20BE62FDF0AULL, 0x1EE88CAF457F6BC0ULL, 
            0x8D9375E341DB4258ULL, 0x3A6098720110DABEULL, 0x8FA41440BD32967EULL, 0xAF43DAB1DD04592FULL, 
            0xC406D14FB486C8EBULL, 0x150DD49D49D96C50ULL, 0xA3606ED9C8DDA51DULL, 0x3831A51CCA2E6D08ULL
        },
        {
            0x8868F12F7B3ECE10ULL, 0xBBF4DFF9C96405FBULL, 0x4DAA8696CE89F02EULL, 0x77E2C9858C0141B1ULL, 
            0xCC116D9E99DC4845ULL, 0xF1E06F802B7D4D85ULL, 0xAE54A398DC007C64ULL, 0x17725AAAC07A449AULL, 
            0xB371038F3F9CC803ULL, 0x2891C9A148E42FB7ULL, 0x2FAEBE82E987E401ULL, 0xE1CEEB2741C021A1ULL, 
            0x145D18FB92E238E4ULL, 0x05483F3A35B9F036ULL, 0x45F77559DF7516D6ULL, 0x1EFFFBF32B5457CDULL, 
            0xAD82747413D50356ULL, 0x2B82FD5774CA7068ULL, 0x16E3786F3B22E883ULL, 0x143107363DD5CDF5ULL, 
            0x5F6A1EF7F631BFFDULL, 0xAC4E0221C2DBEB56ULL, 0x8F2704C3444B35BFULL, 0xBA112F734FC25B08ULL, 
            0xB2765ECE4C7A51AFULL, 0xC59D84754E58EA0DULL, 0xFB486BE4DF55C4B4ULL, 0x646E8585F6DCF685ULL, 
            0xEDE2CEC22D687B27ULL, 0x08C90DA03CBEBC74ULL, 0xE9FCE88D3D63F5E9ULL, 0x0AD59E760E8917BCULL
        },
        {
            0xD4828E7FD473B138ULL, 0xDCA12F1C271F7D7EULL, 0xBBD0857CE502FA3EULL, 0xA68CF94AA87E9A08ULL, 
            0x307406C1A3034601ULL, 0xACF2D6B2D03D9E8AULL, 0x7EACB0E5E0C07D10ULL, 0xBBEC4D592503A48CULL, 
            0x52D536C10013D048ULL, 0x02A806F0DD7EEC3DULL, 0xF3ABBEBF97057E08ULL, 0x7EBC6B52F91EEE13ULL, 
            0xDFA6BCEFE35D2EA6ULL, 0xBCDA6AB32CA6F378ULL, 0xE21B7D0F77EBF872ULL, 0x5586F1B398D96642ULL, 
            0x7E7DF799A4B64C2FULL, 0x624649EAD3625E24ULL, 0xCCC5E56E6F907E02ULL, 0x4C6747F3595D0896ULL, 
            0x6CC27B3BE81ECF03ULL, 0xBA0CEC935B312C05ULL, 0x69893BD873FC1DC4ULL, 0x36764E201B7D40E4ULL, 
            0x6EC93F91B9A5E3B8ULL, 0xAA76D649C2EE9A0AULL, 0xA6D15C5766EB3735ULL, 0x82AC17B71E2B2854ULL, 
            0x7E5B7E489BAB20FBULL, 0xE9CE28F9DB520C7CULL, 0xBBDCA2CC715B5304ULL, 0x90A5F30812845852ULL
        },
        {
            0xA4D14ECDFBE343FDULL, 0x7A8627623AA4811AULL, 0x6F94BD119A9F30ECULL, 0x264726502B88A426ULL, 
            0x0B9738A7CE3D5711ULL, 0xD401822F420176E3ULL, 0xA2688F83B18FD08AULL, 0xB0AC7399F6BF36C2ULL, 
            0xDB50CE31BBC15193ULL, 0xD5DF26924F3764D0ULL, 0x1CF8C0770FC5723FULL, 0x1E6ED1022C9AAA92ULL, 
            0x402A253100725802ULL, 0x0164251002DE89DDULL, 0x5333B9DF9CA97D54ULL, 0x039648E1C355482EULL, 
            0xD6EC8C19915747C5ULL, 0xE1FCB4733FF956D3ULL, 0x49F093CF1875F4ADULL, 0xDDF892EE9DB10D80ULL, 
            0x1B48839157B6EBBCULL, 0xFFC6DB0C83FB0D1AULL, 0x810E509C963C0F8DULL, 0xF79CC69A7767704FULL, 
            0x76B577E8EED80BD5ULL, 0xECA277A9013FCB5BULL, 0x0D5429A4E9DBAC2FULL, 0xA0C1A6D9FAB0B8D6ULL, 
            0xB7DFEDB7907F5FE6ULL, 0xEA6B3E72F11FD926ULL, 0xDB975BFA456FF395ULL, 0x3B15215F13EDB1D2ULL
        }
    },
    {
        {
            0x7F35B99C0700DED7ULL, 0x359253AA099BF56CULL, 0xBE12793DB9293002ULL, 0x64BC808C53FAFB00ULL, 
            0x38C1844F368CCB52ULL, 0xE6B55663BC33CF7BULL, 0xE95CA64BA0FD2259ULL, 0x6CE7D411ECEFE6DBULL, 
            0x6C0C4BEAA6817ED0ULL, 0x3A3CEDAE4E555DA5ULL, 0xBBFA1C6C0DFD1116ULL, 0x6DEA7FE4B1394A88ULL, 
            0x613A432A2FC79EA2ULL, 0xF9236601DD0BF9FFULL, 0x0B92A3E82890F8FBULL, 0xE9D7019084E43CCBULL, 
            0xC744A6E807641A01ULL, 0xB8A056F025FCD6E3ULL, 0xA3A03937C30CF9CFULL, 0x937CA361904BBD42ULL, 
            0x2DF0EFAED883D784ULL, 0x57F1E05C5C3BEFEEULL, 0xB99AB7CD23047B7AULL, 0xC53AFD478CE5C49FULL, 
            0xEE7181BA63C1734FULL, 0x47C2A566710B3E94ULL, 0x2C9451952178FE8CULL, 0xBB8909292F2124B7ULL, 
            0xA480A5DC056A40A4ULL, 0xB60824F048412F45ULL, 0xD8C82756E3751840ULL, 0x2A7F535EB1BF69AEULL
        },
        {
            0xA5074702782D5DBEULL, 0xAE58EB3362A7171BULL, 0x17960B2FE0AF0BE5ULL, 0x3EA3BB8E383E9FAEULL, 
            0xE1345A0EFFC41B36ULL, 0xFBF1B87D5C5831C8ULL, 0x8B9EBBB2B595F295ULL, 0x7E36557CF53E8D0EULL, 
            0x7AC674D61166F7C4ULL, 0xA4509329D61047CCULL, 0xE7537B54121BE681ULL, 0x4DB550BF3B495D6BULL, 
            0xD66255B04DE92B2CULL, 0xD3B2B9F434C25D17ULL, 0xC41368BF84912587ULL, 0x30CC6DA305B5D5FBULL, 
            0x4F936A6DDD552B9BULL, 0x8F1154855ECA7E96ULL, 0x3C453A63A3A5A198ULL, 0x63CE6E1656C53FB7ULL, 
            0x2395CA18F6ADA735ULL, 0x8824B6300C07C22DULL, 0x4347028DC4F6DF9BULL, 0x86690D3D8C047813ULL, 
            0x4F94899E558C3694ULL, 0x6CAD64114148D536ULL, 0x54F73B4BB9C50E04ULL, 0x03B73769AB615784ULL, 
            0x148E3B77D63E94D0ULL, 0xFB4AB3ED695523E1ULL, 0x6AC76178789F635CULL, 0xF14A8008357AED7DULL
        },
        {
            0xDFF4778F758A0355ULL, 0x4BC7D3A9EE304D62ULL, 0x60DF14AD2C9FE505ULL, 0x56D83AE9350C01A7ULL, 
            0xB05531EB499EA5AFULL, 0xCB673576273D7D40ULL, 0xD21FD61891EB04A9ULL, 0x024662C734BAD55EULL, 
            0x4EEB6170CED52DEFULL, 0x3303F29AC4DDE3B8ULL, 0x85E107761CEBE8FFULL, 0x699C55EA47874B4FULL, 
            0x51DCEC2BE8E7BBB6ULL, 0x8D383C9BCFE087A3ULL, 0x66DCB79D20A2D4E7ULL, 0xD4A58858F58C45D1ULL, 
            0xD1E9387142366A83ULL, 0xB9F3FEF0EB1FB9D2ULL, 0x2423D92C1BFBAAB2ULL, 0x49AC09F591A441B0ULL, 
            0x8220CACF4488296CULL, 0xF63D40958414EF05ULL, 0xD97285AB6521265CULL, 0xE605CFC6ECA53B72ULL, 
            0x3093D16DE49DD7B0ULL, 0xB2187D47D146E3F0ULL, 0xAC313E8097F3C9C2ULL, 0x99B41B857AB44CD9ULL, 
            0x578FF4907DD599E7ULL, 0x031F97DDDC7D7CF4ULL, 0x390D762D5330ABC4ULL, 0x217D08DE9047C82AULL
        },
        {
            0xEC9D89E8F0177134ULL, 0xD0E963AAAA418164ULL, 0x4A3B220ED0685E3DULL, 0xDC6B5142F3B20653ULL, 
            0x10CF0DCB51EDF82AULL, 0x77D9FC2BCF745CF0ULL, 0x4C525613D067AB15ULL, 0x981C67556CEE67A8ULL, 
            0x22DE332132586B01ULL, 0x18A41CA4CAD242B1ULL, 0xBA39DAD94409186DULL, 0x6AE7719AD0BA84B1ULL, 
            0x97C98413520393D3ULL, 0xBD03F8EEAB066F80ULL, 0xC21A021A18FBE75FULL, 0x72AB216F4F3B8445ULL, 
            0xD6BAC25AEF52909EULL, 0xEA94EC5511710A60ULL, 0xE6CF4A650A9FD46AULL, 0x6B84B1027E63E760ULL, 
            0x1F02E9B3EADE55C5ULL, 0xC2B132B28E36E8E3ULL, 0x162B9D60944E1360ULL, 0x18B19B12C26581B1ULL, 
            0x971D6024D7B8E3B9ULL, 0x9D66DACDD939F89AULL, 0xDCDF519D6F44E21AULL, 0x793117BBFDA60327ULL, 
            0xEBED81B16431D246ULL, 0xE715D8B660662CA4ULL, 0xD85AFE010F17FD49ULL, 0xC5A6BC5409A797A6ULL
        },
        {
            0xAF08FE8FA89EE2ECULL, 0x02191CBC0A7E13C4ULL, 0xE7A5E07F01C15661ULL, 0x729005162614708AULL, 
            0xA2804AB84FCD1FD4ULL, 0x9817CB339158DE31ULL, 0x7D44F1C6EBF09ABFULL, 0x364E8F172A4366B9ULL, 
            0x3AD9099453A1FDAFULL, 0xBF36160680548C72ULL, 0xA575F54C7EDDA622ULL, 0x977F49FF5A670455ULL, 
            0xEBA404A740DAA1F9ULL, 0x43B3CB0E9385D9E4ULL, 0xEE0695991CCF45F9ULL, 0x835DF1B9D5687B73ULL, 
            0x060846DF0775E659ULL, 0xBC1B078156F00958ULL, 0x321453AEECDD3768ULL, 0x706A73C032B39307ULL, 
            0xC4AEFC2FED2F65F5ULL, 0x1D5AF43DD7767FD0ULL, 0x6ACC3F4C4E34C35FULL, 0x7D6EE7ACEAAC48F7ULL, 
            0xBCEFA2E1EC3F8BC1ULL, 0xB2BC4E23FDB16DBDULL, 0x8CE8728BF9AC59CCULL, 0x9F2A77392869C2EDULL, 
            0x87FFDD826F7B0ADBULL, 0x32E6E41281A29A04ULL, 0x1F526999BE3137EDULL, 0xA303534194414F23ULL
        },
        {
            0x3ED0972EC7B1703EULL, 0x056797D9E254C9C1ULL, 0xD65C8292299E598DULL, 0x23989A673D1CEC9BULL, 
            0xC4C1DF474C4CF0FCULL, 0xFD49B027DDACC7A2ULL, 0xCC03924BB183C048ULL, 0x4AD9C0355F474D26ULL, 
            0xB7606966B9C70C8AULL, 0x77E06AEF5B82D820ULL, 0x6E84740F8AFBF49EULL, 0x96F090446C985933ULL, 
            0x0E8D3C902F126F4EULL, 0x327700BF1DBCCC4CULL, 0x443FB2CC3C275227ULL, 0x0BCBBCA15A5A6ECAULL, 
            0xAEB8260FB616BBFFULL, 0x0DB497B4CAA670F1ULL, 0x995A3CA219C695BCULL, 0xF716DE0C1E7EF636ULL, 
            0x6C51FD771CA88C7CULL, 0x5CF87C7D11B203C3ULL, 0x1CB3E9FE5B723EBBULL, 0x5007735398E6E3DFULL, 
            0xCF358338075EA02AULL, 0x9FC170C5053E2A2BULL, 0xB48F14478BB620EBULL, 0xCBF48DCD8CDBA1BDULL, 
            0x3D95790F85F08278ULL, 0xF8CAA0B7A53C74E7ULL, 0x7A5AAA303C4B14AFULL, 0x2E68B882D310DAD8ULL
        }
    },
    {
        {
            0x251BA6CA46D6A2ECULL, 0x0D9AC5549CB38961ULL, 0xCF01662A4E45155EULL, 0x83079277F708A7D4ULL, 
            0x1833EC20A6D1090BULL, 0x4B4F033AD87CBCE8ULL, 0xA7CB61E62C6AC7BEULL, 0x18755D4CE993FA8FULL, 
            0x9E1421E6067EF508ULL, 0x8AF25589F8326BC0ULL, 0x02DA4D5B24C10988ULL, 0x2729EF19308E93B8ULL, 
            0x08FACEE4D5CF921EULL, 0xCA9D99226D5E7B2EULL, 0xF339D71FFDC132C2ULL, 0xD50F3199CE0D1DBEULL, 
            0x3210A549ABA74E02ULL, 0x6EF2F34CCFFFD0BAULL, 0x1131D0527DD434F9ULL, 0x503E29E5CC3FB6BAULL, 
            0xAC49496153D6D32EULL, 0x0E435A674ABBEF2CULL, 0x2470BA7FEABCB31CULL, 0xA2D2E4C113BDA045ULL, 
            0x0F3401AB942EBA08ULL, 0x0F62C18B3ADCECA8ULL, 0xDFAF867E8E71A010ULL, 0xE7ABC511D19D0963ULL, 
            0x7C779B461270F21FULL, 0x72C1223A672EEE0AULL, 0xAF5EFA2E07013FA8ULL, 0x644EC08BEB1D1C46ULL
        },
        {
            0x315D2B56F7FC8E6AULL, 0xCED7C5EB7779B888ULL, 0x9E01E85A523CA6FDULL, 0x38A27E0406281604ULL, 
            0x64722D478817E10BULL, 0x3395BF42BA4695E3ULL, 0x015AF42BB7BE387FULL, 0xF54C681C6D29D7EAULL, 
            0xA07D58C78C41BE94ULL, 0x01834BD2C56D9881ULL, 0xB1B785B687C9B8F7ULL, 0x626349A4676E2803ULL, 
            0x90D3EDC9CBA70810ULL, 0xA16FB00BA9BD22E3ULL, 0x41199E8D0B64569EULL, 0xAE7EEFCB896E2C10ULL, 
            0xD3231682EC697163ULL, 0x3AC48F94F1E78876ULL, 0x739B8BEC07B306B4ULL, 0x614066C9DF9876EAULL, 
            0xA7FFC5383FD9D2F0ULL, 0x04428F7362F6AF83ULL, 0xA8DFFBA9389BDE82ULL, 0xEDE87A9E7903A47FULL, 
            0x3E69CC49E3BDE219ULL, 0xD45B837CE5816466ULL, 0x0889C56F35C7FAACULL, 0x197BEB4A8D039775ULL, 
            0x4F504CCCACE4D4D3ULL, 0xD04527B5B222A45AULL, 0x49A640F7356200C1ULL, 0x6A27C2364AA12B62ULL
        },
        {
            0x492EC10ED39E0530ULL, 0xC05261133DCDD3E9ULL, 0xFAF59B26780DC9C5ULL, 0x82C9FD651C4BD221ULL, 
            0x4FF34F9DFCB151ACULL, 0x07EF29D0338BDEC0ULL, 0x3EE5849826B6B504ULL, 0x846FA4B4F27149F8ULL, 
            0x68159C621A4589E2ULL, 0x4BC154D6C36F7315ULL, 0xDDC6BB7F817E2B44ULL, 0x5B55100B30F82D7FULL, 
            0xABC3FA896DD651CAULL, 0x566B5D83A3658DB8ULL, 0x407560428D2C8844ULL, 0xB5F3D7600A4C1695ULL, 
            0xC5265EF8B4A87D75ULL, 0x299DBA3033D9C287ULL, 0xC6BDFEB70F85F80FULL, 0xEA294C76164C88E2ULL, 
            0xFABBEA7436E04150ULL, 0xDA77A106404D3F21ULL, 0x292FDF0F988C04B4ULL, 0x69B855B9AF62CBFEULL, 
            0x11E580069F02CCBCULL, 0x46DC17F0F2A9EFB9ULL, 0xB1E89E44EFF3F3B6ULL, 0x0E1DC87A717970FBULL, 
            0xB0158B36B6C726AEULL, 0x49D4F998C51128F0ULL, 0x2737E5D356219C48ULL, 0xD45E4EF71FD4A964ULL
        },
        {
            0x0AD3D814C9C6DFA6ULL, 0xD33320E5B87318C5ULL, 0x4F1D984CE5EE6BA9ULL, 0xD2F8E5ACABD9121AULL, 
            0x5A4F7C53E714B8FAULL, 0xF5603DCE3EAF9688ULL, 0x74B37DCFFA82BA07ULL, 0x92485B733456F700ULL, 
            0x6461E0AC01910AB0ULL, 0x718D028D0E0A54EBULL, 0x8995A4B0A27CE904ULL, 0x5E9A8FAE45025522ULL, 
            0x530193B2B05E3263ULL, 0xFD27E8C2153BA44EULL, 0x304468BAC6BEF390ULL, 0x71DFF3E6B0C69913ULL, 
            0xB7DA731DC3094F3EULL, 0xA576430562C2125CULL, 0xD1CF86E53FFBD4A9ULL, 0x85E2BFC3775E80B6ULL, 
            0x62676D10A75DBB13ULL, 0x0CF43DD579B00BDAULL, 0xBFADD7966A1E45FCULL, 0x2A325A6D9B6C7D07ULL, 
            0xD5C9CA799F88F575ULL, 0x65096612D43EFB36ULL, 0xB02DB7275E6F974AULL, 0xC212E92FF3BD0322ULL, 
            0x8138B0DEEDD35573ULL, 0x03F1DFA35BBDB56BULL, 0x479E28CC25CD9A82ULL, 0x7929491CE5E3F06AULL
        },
        {
            0xB0075F1449CB083DULL, 0xAFDB94B54A0B120CULL, 0x2BA80EFCADFFD294ULL, 0x69AC52CE9EF0F9B3ULL, 
            0xDDD7969D7929390CULL, 0xCE9404E88BA5DA11ULL, 0x084AB6C8C4B6A112ULL, 0x9932D04D565C3756ULL, 
            0xA8D186F6786C2ED5ULL, 0xB90B6EC99587D431ULL, 0x6E1E9718F1823CBAULL, 0x91A61B6E406F2EDDULL, 
            0x757B2DEE2335E488ULL, 0xE5DD75F6DF7AC1C8ULL, 0xD33B33FC246FF3E1ULL, 0x2D96ED9A52AEA68EULL, 
            0xD01E2BFE04695F21ULL, 0x41A6E0B7006DA8FDULL, 0xDD1F53103646B050ULL, 0x298981EAECBF0C24ULL, 
            0x5422183F87E7058FULL, 0x9FA10D75532617DBULL, 0x6A5CDC35B1479C87ULL, 0x2DFC5D8E857DD84CULL, 
            0x3222F631A5299DADULL, 0x229642BB7B1F3177ULL, 0x65F48D198BB3FAB9ULL, 0xB7EB9EC10E776692ULL, 
            0x7E73E99B4F962B56ULL, 0x43B4DB4992BBD202ULL, 0x7C48F9EB5838EC79ULL, 0x6E228E1FF0E69C2EULL
        },
        {
            0xEE7CE9835A329E31ULL, 0x6793C62EDA4F5EE9ULL, 0x4B7EC2878E9CBBBCULL, 0x091CC72E05D0ACBCULL, 
            0x12470CF1FF130454ULL, 0x02C95AB20DB5C302ULL, 0x87D0A3047759CC7BULL, 0x8C9E3E52134199F2ULL, 
            0xDB6F872F5BD120E2ULL, 0x6E80BADFE486A848ULL, 0x678901FF9453C14EULL, 0x42514B3764D81A35ULL, 
            0xCDAC38DB954C5988ULL, 0xD5F72FA1FF1F0C2BULL, 0x391C4A733146F3CDULL, 0x9ECC2691E4900793ULL, 
            0x6407423FD68A3EFDULL, 0x5D9E7428F3E7CB5CULL, 0x978143352B7043B4ULL, 0xD0D176D039BF7865ULL, 
            0x6E6F3723231D5CD8ULL, 0x7F9EB071FDA40327ULL, 0x9D980AA02FE0151DULL, 0x931E7C7D5060D861ULL, 
            0xD66F3C7E2289D347ULL, 0x81A5ED679909BCF3ULL, 0x67B05EA2AECA0504ULL, 0xB71725312DC7BDC4ULL, 
            0x0B4A72891B46D6D1ULL, 0x90A0681A144E76A7ULL, 0xF6657B577951012CULL, 0x29C2E0801CF24094ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseHConstants = {
    0xB38B10741C08DEBDULL,
    0x2949FA77C84DF125ULL,
    0x3355029124725D0EULL,
    0xB38B10741C08DEBDULL,
    0x2949FA77C84DF125ULL,
    0x3355029124725D0EULL,
    0x8BFBE2F8A13176F9ULL,
    0x2EF6CF7C8FED8FB3ULL,
    0x77,
    0x7E,
    0x76,
    0x17,
    0x81,
    0xB0,
    0x4D,
    0x30
};

