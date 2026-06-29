#include "TwistExpander_Archery.hpp"
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

TwistExpander_Archery::TwistExpander_Archery()
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

void TwistExpander_Archery::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC6D6BF3A2F848536ULL; std::uint64_t aIngress = 0x82ACDE43EDD83432ULL; std::uint64_t aCarry = 0xCC4BCA14280EA55CULL;

    std::uint64_t aWandererA = 0xBF2DD736D89D5B21ULL; std::uint64_t aWandererB = 0xDF2A463212960F3CULL; std::uint64_t aWandererC = 0x8D7BB2F44921024EULL; std::uint64_t aWandererD = 0xCB95932557FB623DULL;
    std::uint64_t aWandererE = 0xC408C76065984F8CULL; std::uint64_t aWandererF = 0xA7E6446B770648E5ULL; std::uint64_t aWandererG = 0x91C7310796A1D19FULL; std::uint64_t aWandererH = 0xFF4FB8823E0478F8ULL;
    std::uint64_t aWandererI = 0xF1B492A51B46AFADULL; std::uint64_t aWandererJ = 0xCC9B80B4BAF14B68ULL; std::uint64_t aWandererK = 0x9928F140D0A9B0F8ULL;

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
        aPrevious = 17344201087594921540U;
        aCarry = 11972643493616477167U;
        aWandererA = 11211686774625842638U;
        aWandererB = 17443520090422068791U;
        aWandererC = 17544987287365677754U;
        aWandererD = 11163323920972770597U;
        aWandererE = 10935948711894181795U;
        aWandererF = 9858078510164591180U;
        aWandererG = 18065981557865483547U;
        aWandererH = 18278541454320347388U;
        aWandererI = 10544352427172963208U;
        aWandererJ = 12536200145056282918U;
        aWandererK = 13919266323232190041U;
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
    TwistExpander_Archery_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Archery::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x8D5914154E1335A6ULL; std::uint64_t aIngress = 0xFC7E2DAA7E4C13D3ULL; std::uint64_t aCarry = 0xA728DD9F4034112DULL;

    std::uint64_t aWandererA = 0x9731177FB10E5833ULL; std::uint64_t aWandererB = 0xD9E57F3E6FA798BBULL; std::uint64_t aWandererC = 0xA067E12B18710856ULL; std::uint64_t aWandererD = 0xA41D6B0E95B9867BULL;
    std::uint64_t aWandererE = 0xDEE659379780A545ULL; std::uint64_t aWandererF = 0xBCD7990CED4E9196ULL; std::uint64_t aWandererG = 0xD01268BC221B7BE6ULL; std::uint64_t aWandererH = 0xDB4E5613F4B325DBULL;
    std::uint64_t aWandererI = 0x953080541A16E756ULL; std::uint64_t aWandererJ = 0xCA1F19896A54BDA7ULL; std::uint64_t aWandererK = 0xA556B9D216F13538ULL;

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
        aPrevious = 18096932842402924114U;
        aCarry = 16319084808863207041U;
        aWandererA = 12370903749800238899U;
        aWandererB = 13660658314715394141U;
        aWandererC = 16120184731868061223U;
        aWandererD = 15226397778991462733U;
        aWandererE = 10762815197723235035U;
        aWandererF = 10133847688288740806U;
        aWandererG = 13925268709974601390U;
        aWandererH = 14726525210238889269U;
        aWandererI = 9836880847362571306U;
        aWandererJ = 17105122635318044119U;
        aWandererK = 16899139449095344965U;
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
    TwistExpander_Archery_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Archery::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC83AC5B34014F0BAULL;
    std::uint64_t aIngress = 0x9467CC98EB3C3E1CULL;
    std::uint64_t aCarry = 0x839535E41DE5D09FULL;

    std::uint64_t aWandererA = 0xEEADAB6FFE453D54ULL;
    std::uint64_t aWandererB = 0xFE82FDE02B54D8C6ULL;
    std::uint64_t aWandererC = 0x8DF2E8B5DDA6C5C4ULL;
    std::uint64_t aWandererD = 0xEA1BD558110723B4ULL;
    std::uint64_t aWandererE = 0xC17B855847AF14EFULL;
    std::uint64_t aWandererF = 0xE67FD93FA4F2AC01ULL;
    std::uint64_t aWandererG = 0xD394A8463D2A65DDULL;
    std::uint64_t aWandererH = 0x97D787278FF698D1ULL;
    std::uint64_t aWandererI = 0xD95D4968C7CAA569ULL;
    std::uint64_t aWandererJ = 0xE0CA606956CBA912ULL;
    std::uint64_t aWandererK = 0xAEE87E519B363D2CULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_Archery_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Archery::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8B8B63973DAADCD0ULL; std::uint64_t aIngress = 0xB21F9014FAAA9F3BULL; std::uint64_t aCarry = 0xFF04140B016FF75BULL;

    std::uint64_t aWandererA = 0xB426CFEFA18FECEEULL; std::uint64_t aWandererB = 0xDC3F5EC5C8C2C9F9ULL; std::uint64_t aWandererC = 0x8CED659149D10EF4ULL; std::uint64_t aWandererD = 0xF0DAD048E7EE89B4ULL;
    std::uint64_t aWandererE = 0x921A0148C8D73B98ULL; std::uint64_t aWandererF = 0xD8FE0C1B1C5073E6ULL; std::uint64_t aWandererG = 0xEFA977486E1622EFULL; std::uint64_t aWandererH = 0xC3225C182E922ECCULL;
    std::uint64_t aWandererI = 0xB42E9D1E3BA2294BULL; std::uint64_t aWandererJ = 0x80636C1F8F65F29FULL; std::uint64_t aWandererK = 0xB73DB39C272D1BF2ULL;

    // [seed]
    {
        aPrevious = 13005051069658469329U;
        aCarry = 13392502809666393911U;
        aWandererA = 9924202287002612375U;
        aWandererB = 17769561140100183227U;
        aWandererC = 12159730043439783870U;
        aWandererD = 12614913583379922777U;
        aWandererE = 14228572807166483662U;
        aWandererF = 17845622629014934245U;
        aWandererG = 16798799613491078050U;
        aWandererH = 10884604804354143777U;
        aWandererI = 13338929897436119989U;
        aWandererJ = 9609477529560331319U;
        aWandererK = 16461711757766289228U;
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
    TwistExpander_Archery_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 2, 0 with offsets 6750U, 1778U, 783U, 7924U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6750U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1778U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 783U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7924U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 3 with offsets 5725U, 6856U, 4520U, 964U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5725U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6856U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4520U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 964U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 1 with offsets 4539U, 1833U, 5048U, 5524U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4539U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1833U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5048U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5524U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 0, 2 with offsets 2538U, 4941U, 2327U, 5835U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2538U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4941U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2327U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5835U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 with offsets 1936U, 1289U, 1143U, 609U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1936U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1289U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1143U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 609U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 0, 3, 1 with offsets 470U, 378U, 1561U, 773U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 470U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 378U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1561U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 773U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 0, 3 with offsets 679U, 1429U, 980U, 1149U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 679U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1429U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 980U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1149U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 1, 0, 3 with offsets 1242U, 1511U, 1707U, 1600U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1242U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1707U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 665U, 1235U, 220U, 1084U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 665U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1235U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 220U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1084U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Archery::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 2 with offsets 2991U, 7830U, 3842U, 6071U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2991U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7830U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3842U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6071U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 1 with offsets 2521U, 2230U, 5050U, 1629U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2521U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2230U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5050U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1629U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 0 with offsets 4944U, 5337U, 3382U, 5610U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4944U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5337U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3382U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5610U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 3 with offsets 3044U, 2797U, 1122U, 58U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3044U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2797U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1122U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 58U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2220U, 4899U, 158U, 1712U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2220U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4899U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 158U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1712U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1248U, 213U, 1368U, 56U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1248U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 213U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1368U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 56U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 712U, 643U, 1510U, 1678U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 712U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 643U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1624U, 943U, 61U, 1282U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 61U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1282U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 852U, 1062U, 396U, 450U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 852U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1062U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 396U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 450U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 199U, 758U, 18U, 230U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 199U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 18U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 230U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Archery::kPhaseASalts = {
    {
        {
            0xEE8B03143E191E82ULL, 0x2D322303C7E2B50EULL, 0xC8603D8E0FBC0E1FULL, 0xBC4D1DCAE6E61C25ULL, 
            0x8FD2F187451E8057ULL, 0xEAD95A739A02488FULL, 0x1160324967B227F6ULL, 0xBDD9E17969C8F7A5ULL, 
            0x77D8A50179BB472FULL, 0x3B4886F612690836ULL, 0xEE5B2C7E8FD78179ULL, 0xAAA749DAB1F99819ULL, 
            0x1DF78D05BEDDCA74ULL, 0x79B5A5C77A0B0D5FULL, 0x86C685FAC8C26E1FULL, 0x2505D57E5EC26B37ULL, 
            0x5189EC86E339B5B0ULL, 0x4C659FE70734BDA9ULL, 0x70202FEF2EA1303AULL, 0x73B86BB4A8AC497AULL, 
            0xCE3BB2F66F076A2BULL, 0xBDF8D993846C626FULL, 0xEA8E9CE764A1EE40ULL, 0x689EC7D9F09C8D92ULL, 
            0x2B919FD9CFACE9A2ULL, 0x21ED0FD10C012E83ULL, 0xE0CD514BE5C47457ULL, 0xECE7B4FB72E6B57CULL, 
            0x5F5D9BD55C7121F8ULL, 0xBBD5732E42FFE969ULL, 0x5E948CCA114C63C7ULL, 0x68EE8337BF1D801FULL
        },
        {
            0x0DE5E987FE91B72CULL, 0x8E6638B6C697EF44ULL, 0x4F91C86ABD33DF94ULL, 0xFDBFD976A59FCC82ULL, 
            0xFA892062E3680DA4ULL, 0xDE379828C24C1E75ULL, 0xFCC8A9C6964CBB4EULL, 0xB68078ED29A039C9ULL, 
            0x4CB0A57DBADADFCBULL, 0xC793D26ED974D186ULL, 0x3DF836D48A7F0302ULL, 0xE62E4F9BFFE7CD47ULL, 
            0x554FB841F86CA300ULL, 0x56766CAC3840D51BULL, 0x52AD24BFAFA91748ULL, 0x3A620EEFC4494171ULL, 
            0x7F98FB0D81C4E1D7ULL, 0xE57EB4311A82A931ULL, 0x61468B98F4A5AEE0ULL, 0x4D060D3C58E03689ULL, 
            0x82458377356E22FCULL, 0xB030BBA439EC8E8BULL, 0x2076800AA46F1903ULL, 0xD7D8E95CA93E4267ULL, 
            0x0794D9106A848D2AULL, 0xA1FAA484AB32BBCFULL, 0x3CB788D32FB165E9ULL, 0xE665EDC85E504BC2ULL, 
            0xF51CD2896BB2D8AEULL, 0xCA90A7E8D7EB5CC8ULL, 0xD35636B385EE0348ULL, 0xDCC3B45446E52C92ULL
        },
        {
            0x30B54EF8C89EB06EULL, 0x97479BE7FF62C661ULL, 0x2A94E415E7BE73B1ULL, 0xDD834B33B590DB9AULL, 
            0xABB6C0FB28E1E5D1ULL, 0xF994C4BEACC6285EULL, 0x2051F79B619FAB92ULL, 0x8F6A6A79FF13B354ULL, 
            0xC144D493B0DA365EULL, 0x83BE8CABA056ABF0ULL, 0xFEB751F01A97657EULL, 0x1024D256670BC2DAULL, 
            0x0A55CC0C64AC6E05ULL, 0xEEB81A6EABFCAB3DULL, 0xC4EC9C9AD0BBDA51ULL, 0x8BFB3F8EBC489CBCULL, 
            0x7ED8667A864B2B37ULL, 0x352AEF9895D9574BULL, 0x67A2E2B37829B53CULL, 0x2765D464415AA04BULL, 
            0x98CB14F939B5A655ULL, 0x49BC7D6274A1A7D9ULL, 0xCFBC6A22120DBD8DULL, 0xA86C7F0F3146766DULL, 
            0xA771581BE7E585DFULL, 0xA54C4AAD688CE322ULL, 0x362AA39A55405A2BULL, 0xCE865763E8F2F954ULL, 
            0x66969DBF726F945CULL, 0xEB5A5AB8EC1C9344ULL, 0x6FA1676CB795065DULL, 0xD10C0AB7EEA02784ULL
        },
        {
            0x03EA95519922273FULL, 0x54794645C3AC635AULL, 0x38FF896C7D150AFAULL, 0x8C20078D0FE7D97DULL, 
            0xC2EB2297F6B03FC4ULL, 0x8704E627A3D91E06ULL, 0x7DC56980C9D0CE1DULL, 0xEB70C3864539DB13ULL, 
            0xCEC1794111F74FF1ULL, 0xF3D1A5D59376E922ULL, 0x4177F6546D25EB18ULL, 0x1BB0689444E1A41EULL, 
            0xDE47E43B4910AE1BULL, 0x4CFA8FBC3E5EEC9FULL, 0x07B36977A2EBF132ULL, 0x3773EEDCEC88FD70ULL, 
            0x6EEB41B8C7BA0C35ULL, 0x53CAE1891B0CF40FULL, 0xA945278F1D336003ULL, 0xA0E3B073BC3A6861ULL, 
            0xED45897221EAFEA8ULL, 0xB6E7CB16F89C4910ULL, 0xDEF005D1413F2C57ULL, 0x733EC8861AC7EC89ULL, 
            0x08063AB6D787FA02ULL, 0xFC1DA37B6D526A09ULL, 0x84FE1956D5B1EFFFULL, 0xF035EC8782BB8733ULL, 
            0x96AE6FF9C814533BULL, 0xB243281823A65591ULL, 0xA90EBD738FE0FB58ULL, 0x28D668B1A1BA4462ULL
        },
        {
            0x2E5EC43CC0275113ULL, 0x7213934CACC1E615ULL, 0x53D887032DD0D07DULL, 0xE56073294ADE2B0FULL, 
            0x9D90AF665D23310FULL, 0x08318B2BDCC29757ULL, 0xA7808F16621D3154ULL, 0xBA6FE5ABF610AB39ULL, 
            0x706E58B41791B2C7ULL, 0x0C3B83C5709D9517ULL, 0x7E0B745F53777A53ULL, 0x6DFE67C9697793CCULL, 
            0xD92AC9194A92D67EULL, 0xF4778FB13D1F41CEULL, 0x18B53299EB94997CULL, 0x88D21F457783D0CEULL, 
            0x0C64FE29F1DB0B44ULL, 0xE9185A44D3F22202ULL, 0x9D7374117B9E8A83ULL, 0x8B45837BE99DD126ULL, 
            0x4E4347E3279FBE76ULL, 0x74888E93BC657C68ULL, 0xCC5E411F5C12DD9BULL, 0xA8DAB7525CAEF687ULL, 
            0xA295539B1D312706ULL, 0x322D91862764DADEULL, 0xDFCCBA1529634AA9ULL, 0x05B1DFAAEEC928F5ULL, 
            0x113EA344D6C4869BULL, 0xDA482F1641CE6747ULL, 0xE821433934552B14ULL, 0xCB3D73B4362068CFULL
        },
        {
            0x74E20C88A0D688A8ULL, 0xC91D6913E7FFD262ULL, 0x72765DB270AA2528ULL, 0xFF4C67AA7DB9D9E4ULL, 
            0xEEE9B40B3777EADCULL, 0x7C40EC6431D6341BULL, 0x74F79366BCA91F73ULL, 0xA57AA69A2266BA1DULL, 
            0x013D13F3DED8AFE4ULL, 0x0DA41C321F12D198ULL, 0x372FE903AD7843B0ULL, 0xF5D61E199ECF2D90ULL, 
            0x77D0126A07AE2EDBULL, 0x5E18F199E1089A56ULL, 0x30C8B96C66EEBFB9ULL, 0xB8F4B10274366089ULL, 
            0x52B3C23099C5934DULL, 0xDDDD041726DE2BBEULL, 0x21E6BAA059EB259BULL, 0x9AFCA7698D32F617ULL, 
            0xA2D3608F21C1012EULL, 0x3643303ADD57B8CDULL, 0xBFC7380FC4DD4FE4ULL, 0x76766B9AC3F19B17ULL, 
            0xAF5756F4A0217E8EULL, 0x11018A68002F0C5EULL, 0x7D22F9C3EF9F12B9ULL, 0xBC85C14CC8CBB13EULL, 
            0xCCA3466CFA03DEA7ULL, 0x9976E84F608A1891ULL, 0x2089B169A14BBF9EULL, 0x8830ABD856A9CE97ULL
        }
    },
    {
        {
            0xB56DE42A77E89164ULL, 0xEE830DC47EFC5AADULL, 0x24997F5702BC73F6ULL, 0x1B9AC3D3D39BE2C8ULL, 
            0x7B1BACCD67C8DC71ULL, 0x2DD82390A690A34AULL, 0xE42E1E26DE1895A3ULL, 0x671F141104124A17ULL, 
            0xC1F26404234DEF16ULL, 0xBC1E0BA6F3963CB0ULL, 0xE0495769B802E15EULL, 0xC5A62AE2A2DB40BEULL, 
            0x2D45323795680055ULL, 0x7F2B592775F62D54ULL, 0x29893FAADB5E3499ULL, 0xEA57D501A52C8C14ULL, 
            0xA508ABDFD8EEE106ULL, 0x000C2C6A54605DECULL, 0xC97A7163915C2BC3ULL, 0x55527BCFB2D651D0ULL, 
            0xECB9E37A17D1BFD6ULL, 0xC1435848D9049FFDULL, 0x44868575266DDD2EULL, 0x8334BE849B62215EULL, 
            0xA8452444239EC92FULL, 0x9B328BCBA2B95B94ULL, 0x2508CFC192B33DE9ULL, 0x0397C6002ADCCA5DULL, 
            0x40C4DE3440687256ULL, 0x93F9DAEE528E8D15ULL, 0xEBABFEB29FC0E23BULL, 0x55FDA5E1F297EF37ULL
        },
        {
            0x4A37F500922AB053ULL, 0x82CEF0A166AC0D47ULL, 0x40B2D585EE4A8CF6ULL, 0x858021A839DC877CULL, 
            0x75A5D41003E6F0CAULL, 0x6B8BACE55E35167CULL, 0xB782B15C562152D4ULL, 0x24A2310B58BD7697ULL, 
            0x0288F9A270765826ULL, 0x723163783F12D1C0ULL, 0xD473B3320286F4E6ULL, 0x22FB4C44FA6E5FCEULL, 
            0x9F0EBA4753ED0981ULL, 0xDAB1FA0237CA039DULL, 0x92663E0A55417F53ULL, 0xD04677AE7AD410C9ULL, 
            0x6B376C47463DC66AULL, 0x1ED76C9D493FEC2FULL, 0xADF728E72EC68CF3ULL, 0xD5857B8DBD412F67ULL, 
            0x6BBC2FC9687A496EULL, 0xAA205D2C16262A27ULL, 0x90D2268AF479A289ULL, 0xC3D40D9E9941BBB6ULL, 
            0x242EFB83A7656D10ULL, 0x774F9F6181A73D7FULL, 0xCDD6FB66B06FB766ULL, 0xD43BCE5553ED3772ULL, 
            0x4B675A7D0C13D62BULL, 0xED1AF7EC7EA31152ULL, 0xEEA47AA25883422BULL, 0x3CC32B12EA6BCF23ULL
        },
        {
            0x4005B6FCA263623EULL, 0xEEC8D7B37947AEB5ULL, 0x0746637CB852F226ULL, 0x897E3D1BA77579CCULL, 
            0x40F14A7271539709ULL, 0x6B9DD0B603C4A31EULL, 0x157B370ACA084F09ULL, 0x01040507713281FAULL, 
            0xFA23A1470B666493ULL, 0x73613D4CAC62CBADULL, 0x7C558D77D4E75F30ULL, 0x8D683F023DF7DAA1ULL, 
            0x490919A6E6DC4C1DULL, 0x45FB4730E765DA7DULL, 0x880EFE674254D54AULL, 0x7585F65C434B5A1EULL, 
            0xB0CF3DEC80D250CEULL, 0xFA59C9C2B363D1E7ULL, 0x7C3821324EF40969ULL, 0x2D568D43A9DFF213ULL, 
            0x20BEEDE53D414F44ULL, 0xC4956022784BDA20ULL, 0x677DEB06081C276EULL, 0xA4D7023108BDE789ULL, 
            0x668FBE3F3D6E0C3BULL, 0x8C8759E19649E98EULL, 0xDFB096743BE277E9ULL, 0xB94F4557D13980AEULL, 
            0xEF1434C3C37A9992ULL, 0xF04446FEF4162C11ULL, 0x111B3BCE90A382A2ULL, 0x3CB52A4C18D6F027ULL
        },
        {
            0x279F6182F2C89509ULL, 0x056A65B1616F3730ULL, 0x459B8BEF7C641F8FULL, 0x7B1CB02FD286DEC1ULL, 
            0x08A5486733B2C15FULL, 0x6CCD492CB511FA55ULL, 0xB6F81F9BD2E2024BULL, 0x0021F7C9817EF0BBULL, 
            0x21EE694297CBF405ULL, 0x5697AE2E0B439CB5ULL, 0x77ACCDAB368746CAULL, 0x228084F42F049371ULL, 
            0xCE4404EF1C3E7DA7ULL, 0x507E34F9F11CFBB5ULL, 0xBF085D057660ED15ULL, 0x3E00C1A5380D0EE3ULL, 
            0x43565C930FFFC901ULL, 0xE29F5BCD33039DF4ULL, 0x2CD8E09F1ECDA5DFULL, 0x091228583C94D730ULL, 
            0xD69DB145FFF9BD83ULL, 0x7AF7693747B2673AULL, 0x4881C1B07F1C09E1ULL, 0x9A411DB988557436ULL, 
            0xF1148BE4EC7B0463ULL, 0x6CD76C01C24949A9ULL, 0xB05764D8C7035980ULL, 0x9EDAEC1CCFCBABB4ULL, 
            0xC442A19343B457EBULL, 0x578D5448EA898F8AULL, 0x2946315F23D06F3CULL, 0x2FCAF55E4FDBB7F6ULL
        },
        {
            0x4925ECCA84900AA2ULL, 0xCC33EE9E2CBA50C3ULL, 0x63E7D813ADECDEAFULL, 0x47045E2C80615959ULL, 
            0x5F21EC2FE70C82FCULL, 0xE9A7C61FCA55CB82ULL, 0xD065E697F2863ED1ULL, 0xE51412B190ABA274ULL, 
            0x76F9F0D2B93BCBFCULL, 0xB3CCEF5CC22B8807ULL, 0xCAF516A70B005FC1ULL, 0x291138A6AAE30845ULL, 
            0xE54BC1E28018A601ULL, 0xFD8724A62C15B296ULL, 0x169F88EBE8F7D639ULL, 0xFB89D6E6568C615EULL, 
            0x0CA1EB84BD331D68ULL, 0x5FF996020C272EACULL, 0x28BFDFE7B5FBEADEULL, 0x0E9721038074AA82ULL, 
            0xB18067FB4944B63FULL, 0xF7191B1AF0FD3088ULL, 0x578245809E52D47CULL, 0x9297390BCD23DD0BULL, 
            0x68D68C85FDA93988ULL, 0x83E536031F82B3CBULL, 0x1C32CCA8ADE0DB1FULL, 0xC86EF4B610FB328FULL, 
            0xE94D0CDD329D6649ULL, 0x62007E3EB724C917ULL, 0xEFD91177E90DECB1ULL, 0x94B362FE572254A1ULL
        },
        {
            0x86684399A814C3A4ULL, 0x17E650D3AECC940EULL, 0x67FE411068B270BEULL, 0x9380D60BC3CA095AULL, 
            0xDDD0C5A183209D2CULL, 0xCD1882BAB55F9DEEULL, 0xC9F32776B5790C2AULL, 0x35B1463F2B1EF31CULL, 
            0x63FA5337B54C59AAULL, 0x320DEE7CD2D28FEBULL, 0x8E58C1FD53BAED30ULL, 0x7CA508E44CF1222EULL, 
            0xB667B4F48DB5501FULL, 0x329BA9FB9D30A405ULL, 0x25BD3E96F82211F5ULL, 0x5E84347EFEDE9AF7ULL, 
            0xEDCC6296CE253E66ULL, 0x63A8D8C2E7BB97BAULL, 0x12C106940F7E8671ULL, 0xE0F0016A0611DA9CULL, 
            0xB6B78E4BC1ECC1DCULL, 0x2457AD41178327ACULL, 0xE61CBD351D605FD5ULL, 0xC218C139630828F0ULL, 
            0x5A74758C8F5AAA4BULL, 0x75CAF018EE825B0AULL, 0x3F6A7C50433140BAULL, 0x167636EE0C27BC1CULL, 
            0x369EDADA2D99D9F7ULL, 0x0BCC043E3BD709EBULL, 0x9D62F7E294F36114ULL, 0x526C0985D7DF1006ULL
        }
    },
    {
        {
            0x8519AEF73898A875ULL, 0xB3CF868EEC46A93AULL, 0x2ACFB95DC2A07519ULL, 0x155BC5C991842CDBULL, 
            0xBFD70AA8E9080621ULL, 0x473ADA6C09008D6AULL, 0xDF04BB174733EC86ULL, 0xD72904827ABFC05EULL, 
            0x34B9671420885D6FULL, 0xF8960E5ABD76F948ULL, 0xF878CF119901711DULL, 0xDF876DD9577CA40FULL, 
            0x5E33CE01BD184ECCULL, 0x5D30EAE41D8348DFULL, 0x6C6D1F006E7179F9ULL, 0x2E4BB6CB37430549ULL, 
            0xFA5E5151D1835C27ULL, 0xB97432F15E2CC40BULL, 0xADE26DA2149EEAAFULL, 0x35EDE19F049B718DULL, 
            0x9F940E189E8BE204ULL, 0xD91493C3DA2F2902ULL, 0xF07184F363FF278DULL, 0xAB06E220670D8BA2ULL, 
            0x1B56DDB2C882A686ULL, 0xE84181078EA18900ULL, 0x27A26641673BB990ULL, 0xA1CE539287B59A9BULL, 
            0x534E983CB2E56A4AULL, 0xC7242FD531E18A08ULL, 0x109F5C2517ABDC91ULL, 0xC7FE75BC5D85531EULL
        },
        {
            0x5900758CC2931E91ULL, 0x3247E34B2C8D87D1ULL, 0x20C115D012BB9D03ULL, 0x5087859F3B9E99C8ULL, 
            0x6E0E75ADD890BD60ULL, 0x7DEDDB29BB5C89F9ULL, 0xCAEBC1459D7982E1ULL, 0xAC541FD8C013892CULL, 
            0x7BD3DBC78BE0DC69ULL, 0xD0A21CE844FFA5AEULL, 0x51AFBAC47EFA8575ULL, 0xDB8FA4E066CCEF4FULL, 
            0xA2B1408671744094ULL, 0xB68AE097CB78403DULL, 0xB3AE8E114772682BULL, 0x40996D5EC2D9FA2AULL, 
            0x789FB17ED5CA1F82ULL, 0xD80AC36A8870CF87ULL, 0x3841758E21191C94ULL, 0x10BF7D90B0D7B848ULL, 
            0xCDC9C2CD4F9A47EDULL, 0x57725CC3A375C4D3ULL, 0x83B5D6037ACABE74ULL, 0xC240A1B80B4D39D9ULL, 
            0x0830E6CB0BE34684ULL, 0xED356A2854DF78F9ULL, 0x025371D0EECCF8DBULL, 0x7DE841642FEFCFEEULL, 
            0x9E0CA340987D3922ULL, 0x26E659F292A2BB16ULL, 0xB328E962C175525BULL, 0x1A4D071278751556ULL
        },
        {
            0x81B052AAE182CD93ULL, 0x46C6A87FDCF306B0ULL, 0xBDE7F9B4A1692C4AULL, 0xA3A4B3EB47D9AE28ULL, 
            0xB7B1DB9CBCA5A611ULL, 0xA17530E897773AD3ULL, 0xC57EC88E96573E9AULL, 0xD6D31E3FC463AEA8ULL, 
            0xFB10C6D545A19986ULL, 0x6930598969C717E3ULL, 0xDD5D7C5007A75CB2ULL, 0xE54C088E9B075908ULL, 
            0x821DE0984706B395ULL, 0x6733E5C2BC994003ULL, 0x1B8A034FAB9E308FULL, 0xE63E4ABE7FC700D2ULL, 
            0xC6150275515B9030ULL, 0xBFB2A17011E64D5FULL, 0x36038EC9B5158CBCULL, 0xC4CCC958C597D30CULL, 
            0x30101EF21603AEFAULL, 0xB4F1CE557594126FULL, 0xD7E607242B1E6F2DULL, 0x0147EC216B1D6505ULL, 
            0x3E11E9859B52B577ULL, 0xC9343693B8F09379ULL, 0x028E2233560C3F57ULL, 0xD7B6DBD63924FE61ULL, 
            0xCA470532511F65B5ULL, 0x026CB2D9671CFDABULL, 0xF01A191B8EC740FAULL, 0xEAA745ADCF7DC200ULL
        },
        {
            0x8E00EE4DC7685EABULL, 0x34E840F057EFC301ULL, 0x6C59CEDECF40FDFEULL, 0xEA0A2D27D4991431ULL, 
            0x8D1004C19F9E32B1ULL, 0x75DF2365FFBDC52DULL, 0xC4674ACADE12E682ULL, 0x119CBCD8A51954E9ULL, 
            0xC2D446D6B1F9A1D9ULL, 0xF465742532577B2AULL, 0x239DA65B9076FCE1ULL, 0x7FFD035170B20247ULL, 
            0xCC2CA9489C4A0DA1ULL, 0xAFF3CEB48D2E831DULL, 0x7C27EC6BBFF05FE2ULL, 0xBD99F1EB30649320ULL, 
            0x49DD63158FC31102ULL, 0x4F9B4B350D1A64DBULL, 0xC44479D2B9763C3FULL, 0xBBA0E1341746FAFBULL, 
            0x4CDB3F3EF89F225BULL, 0x65DC465C538FB24CULL, 0x1E9887E29C064249ULL, 0x35E3C7069F2BAC3CULL, 
            0xE350DD5D8BE49D0EULL, 0x275732A96358638FULL, 0xF43225FF656C4E7FULL, 0xD7FC60FBFC0189F7ULL, 
            0x133860671C0E4114ULL, 0xD39A50E6881296B9ULL, 0x1E6D4EDA6854D6B7ULL, 0x9E615C0B72CA4099ULL
        },
        {
            0x55A831EB50D221DBULL, 0x418844798E3FD866ULL, 0xE33F012A010D6A8EULL, 0xE7119CFEE0E2C0FBULL, 
            0x07A54577DE6591D3ULL, 0xA48C965862D11ADDULL, 0x01E3DDC5B50D2AF5ULL, 0x1317DA127A47A20DULL, 
            0xA963F1268AF0136AULL, 0xF3973FF117EC2984ULL, 0xEC36C6D9027CF389ULL, 0x91A141BA70D0157EULL, 
            0x5CF8B3F6F9C363BDULL, 0x7F1B10C34AF82562ULL, 0x995665454E771332ULL, 0x8C561D57A061ED75ULL, 
            0x2B962BC5EC7FCF57ULL, 0x02D1CDF9B99BDEBCULL, 0x1884DCE09035BE21ULL, 0x741B7F27949978BAULL, 
            0x5CBC1B4F7A32DDF8ULL, 0xDCFA7C46E1F6E04BULL, 0x11CF821066CF32CCULL, 0x2722981A8AD7D203ULL, 
            0x41F2A8D2A6F7C3ECULL, 0xE5504E7E95097BE7ULL, 0x74B5A053DB8C01E4ULL, 0x6AED7BF0EBB8DA3DULL, 
            0x9EE8C0ECB89B4FBFULL, 0x715131E7E521E4E0ULL, 0x4D75EF36B8EB31AFULL, 0xDA56A0030B422A55ULL
        },
        {
            0x6F0F5CC78729F377ULL, 0x13F50FFB4E992B27ULL, 0x7086942801D99A43ULL, 0x6B5200D838BD5D4CULL, 
            0xF4D986AB2B312278ULL, 0x7048DC74B36A7534ULL, 0x98DF509B441098F3ULL, 0xD4D5424CAE12B65BULL, 
            0x6666F8E4E27ABD3AULL, 0x7757B57A26C6A0A5ULL, 0x665C6C8D96D0CD51ULL, 0x5AA83FBF35D6E4EFULL, 
            0x6F1ACD4FB8811B1BULL, 0xB2E5F53528FE5829ULL, 0xCE170B1FB6B6EF37ULL, 0x73A489AF2D42FCBFULL, 
            0x00CED5BA98FF378EULL, 0x299F3FCACB568374ULL, 0xA568493DE63551ACULL, 0xD19C5CEE6993A09FULL, 
            0x7CEAE850EB8E1451ULL, 0x16B8EB7D84186EF6ULL, 0x1C790CC30AC12DD2ULL, 0x6D07B11F4D54FC24ULL, 
            0x2CE94743C28996DAULL, 0x270C4512A41B5E87ULL, 0x10105916702A4FAEULL, 0x393F380039CDBB99ULL, 
            0x1345B1159519E446ULL, 0xF224FD8661938E1BULL, 0x0C1021B5141C9787ULL, 0xADEACA427D1FDFA6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseAConstants = {
    0x7D9DABBFAC16653AULL,
    0xF667091674D4FA8FULL,
    0x2001900E2A204A53ULL,
    0x7D9DABBFAC16653AULL,
    0xF667091674D4FA8FULL,
    0x2001900E2A204A53ULL,
    0x2B8635B4D6762583ULL,
    0x38B86EA923E2FDB0ULL,
    0x41,
    0x3E,
    0x4E,
    0x78,
    0xAD,
    0x8B,
    0x67,
    0x66
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseBSalts = {
    {
        {
            0xD2CA2417147246C1ULL, 0xC0E76D0B51542E94ULL, 0x0FA1AA187DB0B828ULL, 0x7D10B75E0F9C0AF6ULL, 
            0x299E9EF19572B53BULL, 0x758B4A3E02A73F9AULL, 0xA284F167C9DF6682ULL, 0x670060AC7B727C0EULL, 
            0x3AC937F06A56CCA7ULL, 0xDAC66D21354BD570ULL, 0xDF5C33B5F7AF66ECULL, 0x1A51FD7E436E6807ULL, 
            0x3B949E59FC5DD793ULL, 0x73FEF159A04936BEULL, 0xC6AB0028EABDD248ULL, 0xDDA904CBB57EAA59ULL, 
            0xEDA4C6118C3B086FULL, 0x839E26FF79E86EEFULL, 0x4E993EA45670D84BULL, 0x57FD38C82DC69B29ULL, 
            0x659F6D9A79FE54C9ULL, 0x12C722732542FB24ULL, 0x3349F7D64449A20AULL, 0x8B0E192F933F74B7ULL, 
            0xC728DE19B569F3C9ULL, 0x19A24FCC736BE68FULL, 0xD2E7F211181BC43DULL, 0x445AD942636504FAULL, 
            0x016B6C8CE03BE0A3ULL, 0x59B23307DEDB4BB2ULL, 0x750BF0274375243FULL, 0x81E33CAC0502FD1BULL
        },
        {
            0xB9DF087A3FA328D7ULL, 0xB3B1084CDA555601ULL, 0x241F97D445893123ULL, 0x4F9F10BB79B01184ULL, 
            0x118F075FE0E7AF56ULL, 0xCE89CA507045CF66ULL, 0xF083545A470E575FULL, 0x0124DDAD3A7DA265ULL, 
            0xB544300AACC6EF00ULL, 0x7A7E4BCAA185668DULL, 0xB0B575C0FF67D6A0ULL, 0x593536CAE63D3938ULL, 
            0x06C24021BA7751DEULL, 0x8254481189C8965DULL, 0x318FF9237320E9EDULL, 0x1294D1244AD15996ULL, 
            0xF3AB344925850152ULL, 0x52CA00494C355C7BULL, 0xEBB5BED865A26911ULL, 0x5A60A857C91C475CULL, 
            0x3775F4B250167068ULL, 0x3D567D22F36AA481ULL, 0xB1B5A35509C72E1AULL, 0x55EF05E08AA73311ULL, 
            0xF01969E6CD972FFDULL, 0xA2A4791785E1AEA4ULL, 0x6F0F47EBECC81703ULL, 0xA05864B22F162D4BULL, 
            0x7C757C1E94E4C91BULL, 0x0BB578CFF1ABAE9DULL, 0x4EAE4957C981C55AULL, 0x971A64011AC02DD7ULL
        },
        {
            0x5D754645D35E1D30ULL, 0x1E804890E7FE6EC2ULL, 0x82B3E1439C92642FULL, 0xF8DE7E175B33C3F0ULL, 
            0x7D1552835D936546ULL, 0xC0DB9E99EBEAC721ULL, 0xE52045EA02F4EB7BULL, 0x6DBAC55E9E2CDF98ULL, 
            0x014B3B4CB66FEF92ULL, 0x7DAAD74B4D8634AAULL, 0x0F95B2F432D005ABULL, 0xE002415B6DEC95B4ULL, 
            0xD80089AED9B06586ULL, 0x72C01ED7940E17CBULL, 0xA0732112C4C16416ULL, 0xB9F2DDD99DF8A4C5ULL, 
            0x9B75942EE0A8ED7FULL, 0x0D2E0BD6AB19A24DULL, 0x99BD126C0AC04764ULL, 0x075C7FC13428705BULL, 
            0x3163D86D015AC144ULL, 0xD185566D94EC0354ULL, 0x270B88DBCA021500ULL, 0xFC92E9D83D40A093ULL, 
            0x43AA7286E1764B6AULL, 0x38ECB94F17A39507ULL, 0xA1114252F42C4E14ULL, 0xC311BFC6A1026F63ULL, 
            0x6ACE0141429BF243ULL, 0x83F2B5F56103C2DAULL, 0xDA4F4AEB0F437FFAULL, 0x6DCF885B00CAD45DULL
        },
        {
            0xF784FE7D11258178ULL, 0x4B6DEACB2ADCE2D2ULL, 0x7974CEED6D1BD76AULL, 0x2C587F51ABDCA932ULL, 
            0x205EC308AB5450FAULL, 0xAABBC65786601C22ULL, 0xBE500CE2596F6FE5ULL, 0xF9CA830F030C0B83ULL, 
            0x0130A87F69BC8CE1ULL, 0x643A40947BDC9857ULL, 0x48E768F5C950378AULL, 0x7C5821247597F9AEULL, 
            0xF79556308F35E405ULL, 0xC12F83036F60CA52ULL, 0x216A2DDA31BF6692ULL, 0x814E5F9D8AE52944ULL, 
            0x63167C2074F189BEULL, 0x28683869CEFF989BULL, 0x20D90228635344D8ULL, 0x124EA03290500737ULL, 
            0x72A913F337FEFC3BULL, 0x0202A788A4572997ULL, 0xDF61D1283EE16042ULL, 0xEAF1232AC850BC92ULL, 
            0x41943AF0D981829CULL, 0x648620399C28C91DULL, 0x38DC2BE9091232CFULL, 0x93F997B9B53E86E4ULL, 
            0xEC08247446BC4B26ULL, 0xECCFEC308AB89C58ULL, 0xE86E7E0EA11AD5D0ULL, 0xFFC9BABCA6BB1567ULL
        },
        {
            0x8C2AC9C4CED32255ULL, 0xA492EA9441034010ULL, 0xBCE819A1A1D7FB46ULL, 0x7A08501E5267921CULL, 
            0x38F2370F069491A9ULL, 0x461ADD39CA060E85ULL, 0x609C80485FDBB3A6ULL, 0x87A6E6FE3FA9A187ULL, 
            0x1A6F5BC4096985D1ULL, 0x88C2074907031ACDULL, 0x33F73866C73F974CULL, 0x5487B4D3FE05884CULL, 
            0xD3E335D0497C8BCAULL, 0x3EAA9D416A3E0BBDULL, 0x0C5E4005D8D04D72ULL, 0xA1B070E56C2EFC8FULL, 
            0xBE96F7D2AB3FD484ULL, 0x1860E8731EC27327ULL, 0xAAF9FDD1F165DB97ULL, 0x3807D08F52317F7DULL, 
            0x31597AA452751517ULL, 0x1D8E6417BAB17B73ULL, 0x590CBECC50E439C6ULL, 0xEEBDBE547FF95697ULL, 
            0xF5EFAA80E8D58280ULL, 0x56B46797FF12A963ULL, 0x44D894B8377518B7ULL, 0x37A2BC18422C2E56ULL, 
            0xEEC5423E8151BF79ULL, 0x681438C4A7DDC540ULL, 0xA140DD51C4B960F8ULL, 0x6B61BAD1001A9DD1ULL
        },
        {
            0x7D210E3D73D4FE35ULL, 0x9CC886E90E1BF39BULL, 0x019A8AB34D027054ULL, 0xAADC92FEEF16C38FULL, 
            0xA02CA15D08CBD4E3ULL, 0x9971B3C1D298B47AULL, 0xD18CC35D4DA349DBULL, 0x3A4D426BAB6DF859ULL, 
            0xDB76B840FBDB3700ULL, 0x5A3F4B148597C7CAULL, 0x53E9FE09829DCE68ULL, 0x064AE0CFCA9EE14DULL, 
            0x82DAF1EC084BEAC6ULL, 0x82DC67BC9A64EDDDULL, 0x1D93991917B4AA39ULL, 0xA3E18E41808123F2ULL, 
            0xBFC47996D94572C9ULL, 0xB7CF3653A5075F96ULL, 0xB25B6D7F1F39411DULL, 0xA21CEA17C091DB7BULL, 
            0x726C430CE9BA67FBULL, 0x07FEE319C9C81B51ULL, 0x1387591F009D1461ULL, 0x5113A49AC704C7E8ULL, 
            0xA6D69727E9B569F6ULL, 0x93C19E93CB71802DULL, 0xF4C6B6D38C7794ABULL, 0x8CB012E6EA60CAE3ULL, 
            0x37B8FF534CC95555ULL, 0x5E1DFF3E77CD14DCULL, 0xB0B27124740C8106ULL, 0x7F2177BEB805675EULL
        }
    },
    {
        {
            0xFE83F3F8C97C2689ULL, 0xF46000510A72B0CFULL, 0xF1BFCAE255679A75ULL, 0xF5CD01D61577DC32ULL, 
            0xD875FF8972685D7DULL, 0x88CD50596E79E2CBULL, 0xEB63AC3EE7804451ULL, 0xA17E43878701CEFEULL, 
            0xBFD6E9C8B2A8F168ULL, 0xD0793ED3456DA2B6ULL, 0x7B27A6080595DD4DULL, 0x4C48CD4202FF74AEULL, 
            0x934EC36A856496D9ULL, 0x2BC25EEE604518B9ULL, 0x35BF0F134993542FULL, 0x58385433CE642B08ULL, 
            0x758800F36F80A607ULL, 0xB495E617F3F14A44ULL, 0x3B0FE98CA3AB30CEULL, 0xF6700243A9F34468ULL, 
            0xEE3A7A9245717695ULL, 0x13D83A35D3FDA8EAULL, 0xEF2033686E57FB8EULL, 0xE38EA2E611DF690AULL, 
            0x836338F7803D5CC0ULL, 0x579C17DDA390B0B5ULL, 0x8CFD1F1C178EB96DULL, 0xB1DD02989E0A796FULL, 
            0x6F69C98DAA94B8A3ULL, 0x6A72B7B8F0DF35D3ULL, 0x5440CEBE0F46D4C2ULL, 0xC07BD08725C1C73AULL
        },
        {
            0x0082E8A7ABAE7B74ULL, 0xF4DE6241DD4C2F53ULL, 0x89BDC0FABFE03365ULL, 0x0C8E61325D674707ULL, 
            0x6962D0542533E531ULL, 0xF1C4D4AA0C3BCE39ULL, 0x9A437DED4D666370ULL, 0x0D521653D182BB10ULL, 
            0x378A7595A24DC371ULL, 0x9FCC72D24217BEEDULL, 0x0A36E167283F0F32ULL, 0x99AE1F6789395C59ULL, 
            0xF75A691C8D8CC61DULL, 0x73B4D597F53A5A91ULL, 0x35E6ED61DD42BF01ULL, 0xDB24FB2FCDC630CDULL, 
            0x72C70B12EE52E4E4ULL, 0x249174B55EF10135ULL, 0xDFA9A35A4C333474ULL, 0x4D24B61C6FFD1659ULL, 
            0xBB1E2C0A377C5FAAULL, 0x0C910BD1EC6D6905ULL, 0x673E1752D11BE9C4ULL, 0x8E2B6E94675AC24FULL, 
            0xFFA4DC5086C1FC34ULL, 0xC74EC0090390655DULL, 0x40DF39298449E91FULL, 0x9AF0C3A51E8E0362ULL, 
            0x7E3905075A430748ULL, 0x88318A6CA7ADB688ULL, 0x8C4A4DE178D397CEULL, 0x349B513FD6D48C0DULL
        },
        {
            0x0BBE58E2DAE3DFC5ULL, 0x5176D741C139882EULL, 0x8B991FC88A3ECDC7ULL, 0x55C9ED5522D45582ULL, 
            0x91AE050C9AD3B3D8ULL, 0xB34DBB0E93003E3BULL, 0x0295EEC5D87944F8ULL, 0xBDEA2E4D6C1C74E6ULL, 
            0x81CFA1DF44B2C17FULL, 0x9FFC26293D88DB63ULL, 0xA41218707BB60260ULL, 0xF798C672F35D81A6ULL, 
            0xAB4761A7A9952888ULL, 0xFC0FF938A9C0D5D5ULL, 0x79D580249BF637DDULL, 0x407FD8939470AFEAULL, 
            0xDB90DAA516C09AA6ULL, 0x3AD594EC227844D1ULL, 0xAF80F40F23623626ULL, 0x096C48105A4B83C9ULL, 
            0xD9991E1289F05287ULL, 0x24996A45BDB2A4E7ULL, 0xF23C88790D9B6437ULL, 0x6D402B090EF85D1CULL, 
            0x52C2E187F1B2F30BULL, 0xE6D24E366C394F55ULL, 0x29A955E74875706EULL, 0x4FEDE58BD9549F92ULL, 
            0x1BABE3A48F0A0DC2ULL, 0x219D862635BEFC6BULL, 0xF5F36EDA0DD7C47EULL, 0xAEC69A072F76272BULL
        },
        {
            0x4B867102FCE308C1ULL, 0xDBD497D0E2C43909ULL, 0xABDD065DDFE5FBAAULL, 0xBB29D98C799D1DE4ULL, 
            0xAE3718327275433FULL, 0xC5502097DF6F52B8ULL, 0xC600FD1068540F63ULL, 0xC6739952660E4904ULL, 
            0xDB8F25FCA82EF65DULL, 0xC9DB3368970EE548ULL, 0x34E4CDE98F3D2893ULL, 0xA37DF0BA6CC147C1ULL, 
            0x4DC35D962F051D5FULL, 0x2E07B438F91D0E4AULL, 0xEFD4B83CE76C3F68ULL, 0xDD7D7B4DCE0163F3ULL, 
            0xCF50D31452A0DF0EULL, 0xF5C64B1EB45EA595ULL, 0xE99647CA3356FE3CULL, 0xF82AC587499A9DD3ULL, 
            0x11AB39B981D5AC43ULL, 0x19AF493149193BACULL, 0x0467B3DD380A8404ULL, 0xC9B0805CE39CBA52ULL, 
            0x73E18B95B17C3E38ULL, 0x799AC7A79571C040ULL, 0x08AB6ED0BA9F799EULL, 0x4C57005F389B5791ULL, 
            0x96DB2884C25FD2D6ULL, 0xE6766CD71E97289AULL, 0xD1852AE9195AB1CCULL, 0xF0B68E88269F2BFCULL
        },
        {
            0xEB7AC9805BF00309ULL, 0x205FB9F12132FE21ULL, 0x508CDBBDDA289857ULL, 0x2E14DB72FA2F9D3DULL, 
            0xA9C9DE0D05F93FDBULL, 0xE45A8820D0A03CD6ULL, 0x41E9F5E7A309B08FULL, 0x92655C1864A50B33ULL, 
            0x2E8C8B4A74105857ULL, 0x7469726C28BE522DULL, 0x1BE4AFBE6D42D93BULL, 0x9C6FDFB694CE8138ULL, 
            0x259ED1DC771A735CULL, 0x57E774520D1EBFFDULL, 0x901A4A09F27819A2ULL, 0x5D62A54D89A56923ULL, 
            0x292F730BD6B79297ULL, 0xC18860A12C2D98EEULL, 0x4DD30905B44ED042ULL, 0x6E2FF0534E965110ULL, 
            0xFC14FAA4FDBC3AFEULL, 0x1259DE974FE310DFULL, 0x4B59F8F69C1B7348ULL, 0x98DDB8922C2AEEC2ULL, 
            0xE54E9893E3499E46ULL, 0x7E37AD95DBE55592ULL, 0x07AA6DB4F5F20D67ULL, 0xD9A153C8F0B3AC8EULL, 
            0x7CEB1218967CA997ULL, 0x279F99BD342420FBULL, 0x0F77AC299E09A2A9ULL, 0x77F4526C7061A116ULL
        },
        {
            0x0F79E1B1975A3686ULL, 0xD1B0800159148C9AULL, 0x7081964F1FE068D6ULL, 0x26DA4898CD5BC909ULL, 
            0x78AA71CEA48DB189ULL, 0x431C207A7AB343DFULL, 0x61EE3BFDDDFAADA5ULL, 0x01E59BDA1D44112DULL, 
            0x57D66DFD0321DE0AULL, 0x35FDDB0E38DA4A0DULL, 0xB9CF66BEF4071F3DULL, 0x8DE726952B66C3B6ULL, 
            0xE4EAC5CC0F4EC002ULL, 0x01C68F0AF123E428ULL, 0x73BF4836818E683BULL, 0xC30263B85ACAEF08ULL, 
            0x6CD4478C84C73A14ULL, 0xDE0371D6F1541241ULL, 0x4A606382F31855EFULL, 0x8764FE0FA9854295ULL, 
            0xCE03AF7C64309A7BULL, 0x50FC41DACA7F38C7ULL, 0xD51C8E8AB63A2835ULL, 0xD8D896539F853E92ULL, 
            0x7EE2238720676BB2ULL, 0xB48EEED4434CA914ULL, 0xC350BA31EDFC4787ULL, 0xA405B9522312D55BULL, 
            0xEC7DBB5AE17FD980ULL, 0xE517E5E57E14F620ULL, 0x36B7D87992A9B098ULL, 0x7517D25D99318354ULL
        }
    },
    {
        {
            0xF1C2806AD8C53059ULL, 0x2F289E33B18388FFULL, 0xF4ECFD87307E8F96ULL, 0x056814A8F819D822ULL, 
            0x007F383E0CE61AB3ULL, 0x1D4AE1AAEDFA7130ULL, 0x66D1591CEACADE4FULL, 0x5D1272A3D34B9846ULL, 
            0xC71B4F1EBB668E1DULL, 0xCFA0ACE3A019A5ADULL, 0xD35B132016292601ULL, 0xC7ACC38C051F640FULL, 
            0x73CC5C206746EDC3ULL, 0xC8549F91FFE4E22CULL, 0x4646E29C6D858E35ULL, 0x57EFA4BF6E07EF52ULL, 
            0xE0A304F957F302FDULL, 0x722CE75B2532F548ULL, 0xCE3CCB8DCE026CA8ULL, 0xEBAAFD507B258520ULL, 
            0xA80CEACC4193A397ULL, 0x095D6E0DF2B86666ULL, 0xEC20C2C86B78BE3FULL, 0xBC0DC62BDFB61CDFULL, 
            0xEB6FFE4D8BD303BAULL, 0x5A20D5F730A0DD4EULL, 0xA7440DF50AE4C3D1ULL, 0x542686B00BBE9FEAULL, 
            0x32A6E7D19885CEF5ULL, 0x501FE4C262B21466ULL, 0xA4CEAE15E12A16C2ULL, 0x2ADC2CD4C13719C4ULL
        },
        {
            0x7436771525223060ULL, 0xE35FECBD8DBE9BF0ULL, 0x0DA989D22C42D9DAULL, 0xB977E0493918AAD2ULL, 
            0x8DB2955AE3AD49A1ULL, 0x101C2A9A872EF397ULL, 0xD04D3C46F750FFC6ULL, 0x3C2B28A8CA597A0CULL, 
            0x722BBC0057031EAFULL, 0x0E982AADC201049CULL, 0xC7804AEF7DA29A30ULL, 0x222C2026CD1C5C36ULL, 
            0x3676FD3E64C735DAULL, 0xA6A0EBC6B12CA302ULL, 0x8F368FA499EF2093ULL, 0x43A521E2F0B14D58ULL, 
            0xEE6EFD9C81434524ULL, 0x75533DE5FE38C222ULL, 0xE04F8C1E67CDDED1ULL, 0xE8D7B395F757F1E1ULL, 
            0x384F843C5B5E0A82ULL, 0x3A700F9C62E83D47ULL, 0x6BD6724F1242CC2AULL, 0xB9D48D4FFCAC6E29ULL, 
            0xC7A45D96DAA64DE8ULL, 0x36B288830A485E9EULL, 0xDF074C7C1BD54586ULL, 0x8F96DCD7EA4123C1ULL, 
            0xF2C81785B71F656FULL, 0x6680B23E30A17C11ULL, 0xBBFED602335BF74CULL, 0xB2E15807BC32803BULL
        },
        {
            0xD71F229DC9FBD7F5ULL, 0xD5A9DA13AFCAF684ULL, 0xDCB09BE276D7F30CULL, 0x20E31CE14B344115ULL, 
            0x3FAF8B4268B89C6BULL, 0xA50336427E9E4D86ULL, 0xC888E8C212CA61A3ULL, 0x8F673E3229FE3F36ULL, 
            0x9F5993754FA4146CULL, 0xF24EDE4B9B2343C1ULL, 0x85032E7600D3A431ULL, 0x82C2911AF786D619ULL, 
            0xAF5925C087C3FDB3ULL, 0xF040D4960BB46DD4ULL, 0xDC0DABF1D854126EULL, 0x5949DB50605E75C8ULL, 
            0x8FEF3635B6F79856ULL, 0xD6070A8F6FA97768ULL, 0xFB842B87D644C3FCULL, 0xB918ACCDD65303C1ULL, 
            0x27F642966090DCCAULL, 0x82C71AEE294DA19EULL, 0x2D4EB63B438213B1ULL, 0xAAD87AA9494DAB5CULL, 
            0xE6408E58BB452246ULL, 0x6813E52F0A92BB24ULL, 0x42DBC2AF02B85B2CULL, 0x1D2DC3E4AF39D75AULL, 
            0x7581BBD1AFB7E948ULL, 0xCB634ED60768343AULL, 0x6BBC4B62E02E80CDULL, 0xC3A0D23ABBF05D5BULL
        },
        {
            0x75599FCF39CE95B1ULL, 0x2445FBEF0B05B596ULL, 0x1BF57244CE448455ULL, 0x727C3134FC3C7C53ULL, 
            0xBA6DD545501A3CF4ULL, 0xF0657FD1C9D77737ULL, 0x15FC8DCBA3F860DCULL, 0xEA7B1C7A49004E71ULL, 
            0x15633D8958470930ULL, 0x4F2A15A12A7D4520ULL, 0xA459A1D779E7F29EULL, 0x4C433980BE54744CULL, 
            0xED0E39C9C35A7D83ULL, 0xA5EC2273D9373F2EULL, 0x541E14CB91F222BDULL, 0xFB3FBD6BAB71BFF5ULL, 
            0x87541FF38E930E4FULL, 0x887053447965306CULL, 0x05780A94D637B583ULL, 0xFC64731D46BD2390ULL, 
            0x807C8911EF6E29A2ULL, 0x7A4DDE5FC488D560ULL, 0x3B707337AFD52ACDULL, 0x0723B08459A33C95ULL, 
            0xF4455A25F317508DULL, 0x409E71493F414FE6ULL, 0xFAD428F928E1351DULL, 0x4438DAB034559CA3ULL, 
            0x402AC00DB8198102ULL, 0x1A476096BFD3E0A2ULL, 0x086CA81CD11547E6ULL, 0xDD5D88FCB86DB5B7ULL
        },
        {
            0x540197972FC042BFULL, 0xE44CA07D1A4B38D9ULL, 0xB6473FA6A2B343B1ULL, 0x4A9EAAA0A9FAD9C4ULL, 
            0x7E4446A02F837118ULL, 0xC3919720CA74DD50ULL, 0x3E51F0A8A7E6F81AULL, 0x030D5D1C63BFA9FAULL, 
            0xF31D3D927B5A846AULL, 0x0B43789D4DFADBEEULL, 0x42860EF294A46234ULL, 0x7784494CA3CB7EDEULL, 
            0x8E465BCAC017BA97ULL, 0x8E1D55E6F33DC4ADULL, 0x5919920670AF0526ULL, 0x2EF17F4B3C940CE7ULL, 
            0xAF0C062A8AC9EACBULL, 0xFD21EB75FCA3A53BULL, 0xB72A48F89761F214ULL, 0x78BEFB3E189C0DAAULL, 
            0x0C2EB88AF486BB76ULL, 0xD7892DBF71E4711EULL, 0x742B936F0D2CE3ADULL, 0x797BBD75A5ED5B25ULL, 
            0x100CDD44D8FEAEF3ULL, 0xF015C62241B515D7ULL, 0xE41DFC9F21C5A759ULL, 0xFF138BF28E2B7931ULL, 
            0x2778CE55FC9E6F5CULL, 0xD390DCFF2867160FULL, 0x52F066E2294D30E4ULL, 0xB977BFE505427ED1ULL
        },
        {
            0x9F2CBE4775B932DAULL, 0xCA40C0A68AB969CEULL, 0x5E082E527020329AULL, 0x0048AFBF59212EF5ULL, 
            0xF5EA5E0272C35142ULL, 0x5779DF0AE80135C0ULL, 0x2031F2DD23233B51ULL, 0xFF687264754DE827ULL, 
            0x036AD45E84D1948CULL, 0x2C9714A4DC92E847ULL, 0x85225ECA6C0A13DAULL, 0xA894ACE37FF7E9F1ULL, 
            0xAEC0CFD704A8DD57ULL, 0x12686E33225B6859ULL, 0x2FC1A522318D9CA7ULL, 0xDCBC9082B2041D03ULL, 
            0xE73BB8A9A9F7A107ULL, 0x17AD2A1EF86495E5ULL, 0x3CD0CE1152F121F6ULL, 0xFF7C5A70E586B55FULL, 
            0x9084D808D88E4166ULL, 0x17114CB7080CB5DCULL, 0x17EFD39E26065779ULL, 0x2BE8D11B18A84E95ULL, 
            0x9A5507986133D59EULL, 0xDE6E72B140AEE9BBULL, 0x96FE296E866F0B72ULL, 0xF5A6D485FFA7040AULL, 
            0x7AE3A2E322F0F7ABULL, 0xC38A0DD0F263D541ULL, 0x517F462C4CEADC0CULL, 0x238245D22B3D817CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseBConstants = {
    0xA773CF3F93C7760AULL,
    0x984927A2858DF9DCULL,
    0xC593D353E608E296ULL,
    0xA773CF3F93C7760AULL,
    0x984927A2858DF9DCULL,
    0xC593D353E608E296ULL,
    0x40E816094BE86DB6ULL,
    0x988C43EA3D8838FAULL,
    0x8E,
    0xF2,
    0x4E,
    0xA9,
    0xB6,
    0xB7,
    0x8C,
    0xF8
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseCSalts = {
    {
        {
            0xCE37745A1DD1D8E4ULL, 0xC8835061687C2A5DULL, 0x77285B55A076E54DULL, 0x961824A057FED873ULL, 
            0x6A74A5BC67AE1BFFULL, 0xA17909AAFE411C62ULL, 0x5F29B43A76093367ULL, 0x9A021B58CD12CB62ULL, 
            0xB4134ADCB51A122FULL, 0x03F3E8FBE5A3AE7AULL, 0x3ECDA07BFE355D64ULL, 0x6244BD20D97544B8ULL, 
            0xD7FCFA1B2685F079ULL, 0x3C3899237A92ABBFULL, 0xCF5C52A9E8E2C437ULL, 0xEC33AC6A718B9A96ULL, 
            0x8039F4F27B245974ULL, 0x3408FAF6B0FBE22EULL, 0x870F81ADA493DF59ULL, 0xE7FB1208C8D34DCBULL, 
            0xBA3BD8F9D7E83CBAULL, 0x966151885C499664ULL, 0x7755DCFB1546CE19ULL, 0x0AD2A25F84EA33F3ULL, 
            0x2859C023D80955BCULL, 0xB042B981114F7B7FULL, 0x595AC6C74457E1D9ULL, 0x2A91F5E5B4902381ULL, 
            0xC3F6B4FDADBB7E75ULL, 0x8684EA40079A1808ULL, 0x2912142F63615828ULL, 0xF3D9396E0A51EE0FULL
        },
        {
            0xDEEDC88F0B8A849BULL, 0x4900174645CF5F09ULL, 0x0BC0F3D53FAB833EULL, 0x88607EE74E79265DULL, 
            0x208BDA041FD07FB1ULL, 0xD5CCB66486C6BB99ULL, 0x475E00F48F401F68ULL, 0x895ECA6512DEB10EULL, 
            0x02AAA02084607CC2ULL, 0x564F72E7B9777280ULL, 0x345A65C160DCCA10ULL, 0x6AC481AE87AF1AA0ULL, 
            0xC51698119B2C6321ULL, 0x2B583EACF2A8AC23ULL, 0x357D13978C0646EBULL, 0xB6AA5BCA25B8F166ULL, 
            0x03339C451CB4BFD3ULL, 0x8A554773EAD30A54ULL, 0x168B88EE1E936400ULL, 0x8FA6A814453654F1ULL, 
            0xDC895757C9695245ULL, 0x2272743C066EC0D3ULL, 0x718D95E468BB97C9ULL, 0x029BE9DE58007FB6ULL, 
            0x204D3F65E83A6BBCULL, 0x702D0C42D0963038ULL, 0x3DCD381F0B4744D7ULL, 0x263B5E6742AE90E9ULL, 
            0x6366B5DF1144A5A1ULL, 0xB9CA0173133666CBULL, 0x20AC851C4112C6F2ULL, 0xFAA9B7FF5591400FULL
        },
        {
            0xD0C886F06F6A2816ULL, 0x500856C17478F33CULL, 0x48FCB3EC795BD783ULL, 0x3F8D607B8EE8E504ULL, 
            0x6A734A3FEEDD433AULL, 0x071C6B19F99180F7ULL, 0xBD103F120883BCC6ULL, 0x3AECF4434D327BE7ULL, 
            0x0BF98C206780C5E4ULL, 0x37DBD15D45C100B4ULL, 0xEF5F769506806DCCULL, 0xBE3A7AA81E48F91CULL, 
            0x71DFE30E615603EAULL, 0x9BB5CAF547DCA46BULL, 0xC292CDBC832E14F7ULL, 0x46FC1271E52DCECBULL, 
            0xEA2BD6E504A8A0DAULL, 0xC7EA9048859003D7ULL, 0xA6E16E7E5A4FA304ULL, 0x9DB998CFFF106924ULL, 
            0xBB5DD486D2AEC562ULL, 0x1CAC1A88B4122680ULL, 0x46429D6A244779C4ULL, 0xD63FFB5A1242621DULL, 
            0xB2B06A77D1BAAF23ULL, 0xF27524E4C76C59F2ULL, 0x93B4406FE40ECB47ULL, 0xFF04222091377FE8ULL, 
            0xEACFF1A1F4751A8CULL, 0xA6C0084E33131458ULL, 0x91CBC832B7637601ULL, 0xA77C014E72BCA733ULL
        },
        {
            0xE5AD77E0520CAA87ULL, 0xF36CECFAB98AF764ULL, 0x532151DA20996C35ULL, 0x8D254C2ECF826C62ULL, 
            0x8153901B809D78AEULL, 0xB0AA66F3F7FF4FB7ULL, 0x408584D8054FFAD6ULL, 0x6D78486C569B6C15ULL, 
            0xD10CF375639CE2F5ULL, 0xB6102F4EDF32F831ULL, 0xAA19C62C6D54E139ULL, 0x62E6F74AAE562E71ULL, 
            0x8014752E658E12C7ULL, 0xE3E143723EDF38C0ULL, 0x39357D5C282789F5ULL, 0x0F04898C94F985EFULL, 
            0x7F65D7419245F247ULL, 0x11C50B2F3158F9E2ULL, 0xEC7568731B92C4ABULL, 0xB5DAE7CF2BF237E9ULL, 
            0xCC55E095B667C594ULL, 0x9B15D6E5978D3370ULL, 0x6E2F67316E53411DULL, 0xE09D9C8FFD3F9BE2ULL, 
            0xCABDEE4DD68FBFB5ULL, 0xA717333A602DB1FCULL, 0x85AD800154C195E7ULL, 0x8CE983E1E840207EULL, 
            0x1A42F6FEC3926F20ULL, 0x70C272B9D116604FULL, 0x3DA300B6F69378DEULL, 0x20CC4BB80ADE7CB4ULL
        },
        {
            0x54367F96A2D47E4AULL, 0xCE94E38E6B81C23DULL, 0x28619017033A98C8ULL, 0xF49C974FCA2BC84DULL, 
            0x98CE078F3F5478D2ULL, 0xB0B1AF46390C4228ULL, 0xF0D5A3083824EA00ULL, 0x8AC5B9DC83D73D67ULL, 
            0xF69611DEE15E66CBULL, 0x6DF2A317FC9407DDULL, 0xED3C8E82A756EE27ULL, 0x72C616E02CCBF2A2ULL, 
            0xF08832C260AEC4FBULL, 0x8F9D061DF3F1C73EULL, 0x27D77A8EE18C3DB9ULL, 0xF370402172B99326ULL, 
            0x0C12A84A7F53E0FEULL, 0xFD81C20E202029B6ULL, 0xBFD9B942A4C93C8EULL, 0x8246A8E73C838C78ULL, 
            0x13756815999040F8ULL, 0x2ED2118C017BBB1FULL, 0xD520A4F83E1EF78DULL, 0xFDB01F47B129F755ULL, 
            0x960915264C83A94EULL, 0x566B3F1E2C0F8D1CULL, 0xD22E28D875BA71F1ULL, 0x654A7B8F6469C6DFULL, 
            0x7138E82A86C6660FULL, 0xE4C5B51748E2FB3BULL, 0x930C404E58D7AD72ULL, 0x3EF6E50E58B9BE85ULL
        },
        {
            0x297DF3745EF048A7ULL, 0x42A0F1904176FE19ULL, 0x1017FD86C0002DD6ULL, 0x3BA35642A53DC027ULL, 
            0x6D75722EFDE5D980ULL, 0x86ADA06789C904EDULL, 0x196C8540525E132FULL, 0x977A1B8303EB19D7ULL, 
            0x0276DB5C1392094AULL, 0xDF59FB03F6339A48ULL, 0xCA2F3D3B03AE11C5ULL, 0x5DF7C0E36BCC53A2ULL, 
            0x156D4EA344181E89ULL, 0xB2F4820D3F6B1C1BULL, 0x12A267DD8F5296C1ULL, 0xAA8C0582CFC0CC13ULL, 
            0xAD21D9A1EC7052D0ULL, 0x50368A4D9787EA81ULL, 0x12AC5871356C47B9ULL, 0x3B54D977341CDBAAULL, 
            0x53C0319C4FF4ADB5ULL, 0xC44CD568F92843E9ULL, 0x1C1C705F749099BAULL, 0xF503964762F91BECULL, 
            0xDCB4867690871489ULL, 0x58199B65D802F1E0ULL, 0x3C7C4199831F3EA0ULL, 0xA4DC7A1D48412C9EULL, 
            0x3E5EE8630298609AULL, 0x12F2DA35B43FC531ULL, 0x2B444B119AA5EE55ULL, 0x26AB342CC2DF785AULL
        }
    },
    {
        {
            0x821B65E8CB0225F8ULL, 0x3CB0025F2C1BAF61ULL, 0x04C7F55BAA3FD85CULL, 0xDC6AE07AC0A21E6CULL, 
            0x5990797E8DAC98A4ULL, 0xC6911D991CD13D10ULL, 0x4ACAB130BD4A438BULL, 0x5611E9E1C9FD80D2ULL, 
            0x4DB523529FF85956ULL, 0x1B9224066F738FE7ULL, 0xDDEF6B8D68389E23ULL, 0xE2AC13579649A56CULL, 
            0x268B4BFC190B6685ULL, 0x9E083FEE58CF59E7ULL, 0xDD303650E4C26CADULL, 0x34B41E9FB9349B4EULL, 
            0x463EEA7CDE9A18BCULL, 0x8FFD6D021CFAD086ULL, 0x3535FE40C03287B3ULL, 0x90F3EF1778D8EEF1ULL, 
            0xB00F0656F63FB912ULL, 0x3BC71D740A78825DULL, 0x00AD906C647C4142ULL, 0xC1D4194108AD58DBULL, 
            0x3B98484873F36B46ULL, 0xC1F7110060099C3FULL, 0xD78FA9F0E4447525ULL, 0x12E55DEADD3DFCE6ULL, 
            0xDCE905E63976A4D3ULL, 0x4803DA300CA2D86DULL, 0xD2A66B07D344C367ULL, 0x89D9517B2C4323B0ULL
        },
        {
            0x921066F262B7D5C8ULL, 0x687C7F7EF4F59DC5ULL, 0xF8B93D6CC4649B23ULL, 0x48A79DBADA72F55EULL, 
            0xA2BF2D16ED7B873AULL, 0xB636F597113EC951ULL, 0x1EE117C02FE37679ULL, 0x4E4447EE03E1950EULL, 
            0x6C38FAF86159858AULL, 0x0B50ADE834702859ULL, 0x3D199B8F35FC13C2ULL, 0x5A4212CAA2FCDE34ULL, 
            0x62D905C3395F2EE8ULL, 0xAEA2B93753A9A289ULL, 0x814E2BE21C21D7C6ULL, 0xA655226C20C2B550ULL, 
            0x9A73AE6F3D661DD4ULL, 0xF2E1FAF1B2D03E9EULL, 0xE5EDD40D7AD159DEULL, 0x67A912B4C99FB34BULL, 
            0xEB8906A018A7750DULL, 0x5D3DAD3010C02623ULL, 0x2967D91F2BA53B51ULL, 0xC2B2BDEB359B2362ULL, 
            0x2A651CF927E26367ULL, 0x04137A8008C4456EULL, 0x8588F95734E7E96BULL, 0x2433DD35A1D0B47DULL, 
            0x2CC7BC91D47E8973ULL, 0x56C23AB1753F81C2ULL, 0x01F923B783773593ULL, 0xC2C2073BFE174D8CULL
        },
        {
            0x644719E12F7F9803ULL, 0xABDEC0B092F0A0F5ULL, 0xE474104055618DEBULL, 0x7F1583798101A432ULL, 
            0x3B4C628820AC43C7ULL, 0x8791381173B3127BULL, 0x810A2F8E6368968EULL, 0xFC147C4D18757FAEULL, 
            0x1B9D0EAEC0716B7CULL, 0x78072E5DE63A75EBULL, 0x33F5D39D0D5F1C3DULL, 0xDF23D75731ECF562ULL, 
            0x204FFD09B232B8E1ULL, 0x8A9EF99E4E76FEE8ULL, 0xF4E9C37B0F25796BULL, 0x1AD9B9FF43B69330ULL, 
            0x58C7F4631353E6CBULL, 0xDA909E287D9A1C78ULL, 0x41046611E4A3575FULL, 0x9DAFCBC1C97D0244ULL, 
            0xD719AF5E3720D6F7ULL, 0x45A16A2269631494ULL, 0x4E24F97F9BECE31FULL, 0x0AEBEECEC44C2C40ULL, 
            0x0554518E08D4C49CULL, 0x3DA53A8583C99603ULL, 0x195FF84CEBF46AB4ULL, 0x89DE7527AB67C438ULL, 
            0x58834C2582796F4DULL, 0xAA0019E003F9A0CDULL, 0x25671A3B9BEBDFE8ULL, 0xB1E9198A081CBBE6ULL
        },
        {
            0x38C99C1F60D94C68ULL, 0xDDDCC4180D2BA269ULL, 0xF0E04A82F40E8FBBULL, 0x89A7B6029498FB80ULL, 
            0x5CFC4C4915B17F51ULL, 0xF6241DD76CCE10B7ULL, 0x58E5250498DD37A6ULL, 0x24022EE05A91300BULL, 
            0xB1F18B3ECA273B7AULL, 0x695A83F8C4A83CFBULL, 0x50B4CA9FD2347A77ULL, 0x0BD696C4DA6E1B97ULL, 
            0xD2C90C74E599AC88ULL, 0x0FD6FB7F24DA932CULL, 0xF15C6312E3B3FCA4ULL, 0xDBC44ED7AB70CBEEULL, 
            0xD2A4634B0055C84AULL, 0x8C80A0C25944E148ULL, 0x732F2FEB0599A736ULL, 0x079B052F4F2847DDULL, 
            0x56FB9BFFBDB365FEULL, 0x4F72BC81B4DB6B7EULL, 0x32412313199A2967ULL, 0x9CAA9C46327DD251ULL, 
            0xDEBB8D8D6A33BE9FULL, 0x50B0989A0A1C3E64ULL, 0xE6912C843F170DFAULL, 0x747FCDEA70EE259EULL, 
            0x06EF4848E1858BB0ULL, 0x72986F306EFFDB54ULL, 0x06B21A6CB651EC48ULL, 0xEB63E49687632132ULL
        },
        {
            0xEB8787C8D19CC6E8ULL, 0x0AF1F6D5A0B81E13ULL, 0xE9E56D7B1AA65FFDULL, 0xBEA2E06E5F7C6F6EULL, 
            0x71B983025F45C580ULL, 0x3B8B84274801B4B7ULL, 0xF1B63F8375BB5951ULL, 0xBED0BC52B9999B67ULL, 
            0xD8CDBF5A15B8DF04ULL, 0xE6CF2F14894258D4ULL, 0xD5E67A35CAEA2706ULL, 0x4A0BA4A4C646FA7BULL, 
            0x32AF5C2C06E1D206ULL, 0x961CB8E2D8BC063DULL, 0xD7786A4D0F9F5FAEULL, 0x773B45C1E12AE6DBULL, 
            0xDF90E4504779FC91ULL, 0xA0B18D8FF8C3CAD2ULL, 0xE57808E144953131ULL, 0x487D3AEFCE255C38ULL, 
            0xBE2DA5C5B04223F4ULL, 0x48206A70FDAAB05DULL, 0x73FABCC072CB153EULL, 0x5B2D121DA5CAE7D1ULL, 
            0x905020BEAAFAC9E9ULL, 0x45C4636C85F16469ULL, 0x9955318D417CB39FULL, 0x3D748F5A97B2882FULL, 
            0x65EDBBFF84127875ULL, 0x5C27A8FD2866F6F9ULL, 0x05018CA022E71D77ULL, 0x8A053949A77B4A54ULL
        },
        {
            0xC29348151D5ED4F2ULL, 0x791D83EF10A4A154ULL, 0xEFAC7A8CFC31B73AULL, 0x3E20019C564D22E1ULL, 
            0xAE38FD0D4AC2C41DULL, 0x17CF5F05FAC3457BULL, 0xA5152184A3F41A7DULL, 0x5F585E217FC91701ULL, 
            0x29DD9A02A62A8D33ULL, 0xD92BC3F94D1D48C2ULL, 0xE98E79681ABA9C88ULL, 0xCE0140B157576CD6ULL, 
            0x62DB7E8A9C1CA969ULL, 0xEBCEF7E22A7AA342ULL, 0xA0B374E8C105D843ULL, 0xC689F3B3676A1795ULL, 
            0x9C23CA9C5FE4F138ULL, 0x7F4422580A326671ULL, 0x60F1433A9B960DCBULL, 0x081B04A61F883344ULL, 
            0x1E0D46F61AA2E841ULL, 0x8698AF4880212F30ULL, 0x86F51212167A7D64ULL, 0xB3039E5FA8A738FDULL, 
            0x93821D8119BF361CULL, 0xD11A1A645A97CB8DULL, 0x708734F044B812E8ULL, 0x79AB5B30B34C66A6ULL, 
            0xB677284614E4DD1DULL, 0x684489FE1341CA24ULL, 0x5CF4800E350D41D4ULL, 0x277686DE696E67E1ULL
        }
    },
    {
        {
            0x2329132E5546E31DULL, 0x2EF38C4E179C7691ULL, 0x055AD9B0A34D4067ULL, 0xDF3228970E3DDAF3ULL, 
            0xDE4F5D0665DF9961ULL, 0xE6DFD2ABABF0BF2BULL, 0x8373CEDB35D90FDCULL, 0xEBF6D63443C9F9CCULL, 
            0x2B3801B8360B23F9ULL, 0x82B89BBC98A2434EULL, 0x7606F5D286664221ULL, 0x6B859E045B2B0594ULL, 
            0xC1E9E0AB3AE42D50ULL, 0x4CBF566CA7BF5944ULL, 0x778453135F4B36DFULL, 0x22101806CF0146B9ULL, 
            0x89FCCE7CDCA43C5DULL, 0xDDB687CD7D431C0CULL, 0x537226615FDC8041ULL, 0x7E838452D1C51B39ULL, 
            0x9E43AB7C1386E2A5ULL, 0x93462E0DD32901D5ULL, 0xC1FDDC559020C6C6ULL, 0x39B6D456AAD82073ULL, 
            0x4DBBE9DEDCC1283AULL, 0x2F0B8035356211AFULL, 0x55F2FFA7757195BBULL, 0x04C7D7E478825218ULL, 
            0x979B618D95093C68ULL, 0x33EF0E398060CEA3ULL, 0x50CD881B8429AA5AULL, 0x2E898554011F9945ULL
        },
        {
            0x6286B1B5D88D9F00ULL, 0x91661295818ABB89ULL, 0xCFD871D61FE75D82ULL, 0x7416C2C8FAE1F79DULL, 
            0x28C0CCF28280C33DULL, 0xBB25A164631D4A8DULL, 0x44697EA0B8EEC893ULL, 0x1600B1D95E7C1DB3ULL, 
            0x847514DE622672D0ULL, 0x799DE8B40710909DULL, 0xE5971925CC4A97F0ULL, 0xF989938BFF4FB610ULL, 
            0x47E73DF7A6531E21ULL, 0xD148B380DCEF419AULL, 0x27C0D010440B196CULL, 0xD8F72D2E348A545BULL, 
            0xD446585FC66057BFULL, 0xA7EF2F2B7DBC91B9ULL, 0xD31E3A16BFD0679CULL, 0xBB745207FAEEE115ULL, 
            0x4218BD66D5873E26ULL, 0xE3185B9DB598D903ULL, 0xB1A584E66F08CDB5ULL, 0xB7A806596B3D16D9ULL, 
            0xE07613467B5B2DDFULL, 0x2A67F86002B136E2ULL, 0xB21667B33DBEA449ULL, 0x272A8B709EAB3392ULL, 
            0x69E7A20D5DF024ACULL, 0x2015AE0377A483B5ULL, 0x4A5A51570599AFA5ULL, 0x2E47D97473BB8E80ULL
        },
        {
            0xCA2766C30F864E8BULL, 0x26DC87D364F0FD82ULL, 0x65EA85DC7B826682ULL, 0xBD0E8F6F21D20D7BULL, 
            0x417C55B2673B5846ULL, 0x208206EECF22A3D3ULL, 0x885C63241CD6D08BULL, 0x24FD75DD0871AC20ULL, 
            0xDF81B4D65D5F8CADULL, 0x6F0724CDAB5FE137ULL, 0x6FB69E1315CF512DULL, 0x38D91960C4D79DDCULL, 
            0x8571504F13265B31ULL, 0xBD6552CF2E8F32DDULL, 0xEC123CA73B3D969BULL, 0x937E1CA6AD6CE571ULL, 
            0xB60BB0B57E02DAC3ULL, 0x77E590A03B97F773ULL, 0x5E1E0494E4F29EE0ULL, 0x7EDAFA736527B894ULL, 
            0x778EA789E971F04AULL, 0x570E4C19D3EE8106ULL, 0x6057782C79F66F8DULL, 0x7911419E2FE890C1ULL, 
            0x17F3847DA421C47AULL, 0xCCC6D0D655F6CC73ULL, 0xC028D8FF9A8868ECULL, 0xE52FF76E2DDC73F8ULL, 
            0xBDFB0A9B62748030ULL, 0x3B76730D9D7D6B7AULL, 0xCB6932A37047FC27ULL, 0x9F4CB3932800C454ULL
        },
        {
            0xA42313E1DC9C6283ULL, 0x0B7EEFE2463A5211ULL, 0xEA176972D90422ABULL, 0xB390C30F7B3FB2BCULL, 
            0x907B582EF1619E5BULL, 0x5583B3B315A5F48CULL, 0xDC3D6194D04444CCULL, 0x5E7AD17AA2FA5A12ULL, 
            0x729E3F853E4B2F0FULL, 0x9AC5DECD264DB5B8ULL, 0x4F51B018150AB65CULL, 0xCF1E522774170B09ULL, 
            0xD9BA8BCD5398C580ULL, 0x9D7172FEB2DD90F8ULL, 0xDF8029439F261296ULL, 0x852BEBAA45CBF802ULL, 
            0x8DF5C1B067C70B12ULL, 0xC6997A2724F4FCAFULL, 0x57A0C1B7520C8972ULL, 0xE9CFC292B5C31DAFULL, 
            0x7668177AA19A201CULL, 0xB3E1C137EC1772CEULL, 0x3BEDDA6E523979CEULL, 0xA91F4F238C1CEE16ULL, 
            0x1540071236043E42ULL, 0xFA906CF3543D81C7ULL, 0x798835044094E032ULL, 0x62A0AD079004F7E0ULL, 
            0xFB6CF56C30DAC35DULL, 0x5E19218D868997D3ULL, 0x29948DEEB14D97F1ULL, 0x11265CFF949D3823ULL
        },
        {
            0x66DDEB35E769F4CAULL, 0x033E8423E22368A7ULL, 0xA324CB43658C0B37ULL, 0xF94759D58832F216ULL, 
            0x3516A215EA1AA3B6ULL, 0x66FEA9533B0745AAULL, 0x5C259CCA78A4296BULL, 0x15D35862057AD15CULL, 
            0x8DC813D749A9721AULL, 0xA786A6C64769B843ULL, 0x7DF05637CA7505E1ULL, 0xF78BDB64CB916A9BULL, 
            0xFCB532A1CC05B629ULL, 0x112B4F424C142B44ULL, 0x7193DA89D9F42332ULL, 0x12E0404537DE63F4ULL, 
            0x1157C5823310CC33ULL, 0x002E7B1258455D74ULL, 0xE9E509FA1E547691ULL, 0xE06E64B54898FAB2ULL, 
            0xF953C40F9E4889D3ULL, 0x37B316A7B995E6B5ULL, 0xFF9D2D7F9F83EC13ULL, 0xCBC3FBFE2CE73D7AULL, 
            0xFF868F6E0615A0FCULL, 0x2E5CA4C44C1C871EULL, 0x2FDCB43AB33AA2DBULL, 0xEFDFE352721A2404ULL, 
            0x2DEF40B0D2336558ULL, 0x7C2211AEB154C888ULL, 0xC9EE4BC805F2610AULL, 0x189C28A1ED2AC96FULL
        },
        {
            0x6F65741CD08D804FULL, 0xAC30D77538B627DBULL, 0x32C07F72F8DCEA43ULL, 0x714B8F987CBD6145ULL, 
            0x45B052313E120980ULL, 0x9ECE17A5BEFCB03EULL, 0xB621FFCEB5682DF8ULL, 0xA95F722DEB49A565ULL, 
            0x1BFDB537430ED56CULL, 0x48A35CC402CB7AAEULL, 0x7B22D774779766DAULL, 0x085C7DD409973567ULL, 
            0x66CABCBD96B4FA23ULL, 0xFB4436C390B72E0AULL, 0x13FFA58ED0847FAFULL, 0x0862EFA22010FDFAULL, 
            0x725D31657C61B6D0ULL, 0x4D903237F730F034ULL, 0xE1275FEE17979F37ULL, 0x030915C2CF6084BCULL, 
            0x8A33AE70160C4AB0ULL, 0x87E2E5A51D405C6DULL, 0x35363C16741BE64CULL, 0xCF6212832CBCF247ULL, 
            0x185EF9EA38BCD039ULL, 0x41A92CEDD5517614ULL, 0xACD429DA7B1FDB0EULL, 0x5A30B8E00454E53BULL, 
            0xE18F8B29CFE68BCDULL, 0x16C6B6AC8FA71974ULL, 0x79DAE3F6EF02AA7CULL, 0x612AD996FB10F15CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseCConstants = {
    0x167020FC912330A5ULL,
    0x6AE42669A9EE6FB8ULL,
    0x5B21364827AD0CFBULL,
    0x167020FC912330A5ULL,
    0x6AE42669A9EE6FB8ULL,
    0x5B21364827AD0CFBULL,
    0x870C4688A8B80BA4ULL,
    0xADFD89E26C046BD1ULL,
    0xAF,
    0x10,
    0x47,
    0xA9,
    0xA6,
    0x5D,
    0xAB,
    0x83
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseDSalts = {
    {
        {
            0x188982F29A686A2AULL, 0xE9B7986FABE2A142ULL, 0x17E2A6DF2428C5B5ULL, 0xA8657BF7AA3D4090ULL, 
            0x25B82E3011BFEB98ULL, 0x7F3F1A0B5A193401ULL, 0xD79BB28FC7BE6F13ULL, 0xC526CBA48C1F9479ULL, 
            0x48A0D828D89636A3ULL, 0x24CFDED6EC548A6EULL, 0x018487C930F62DAAULL, 0xA79C1BFDD4738517ULL, 
            0xE11B079668EEF4AAULL, 0xCC3667202E323570ULL, 0x5EC49F32BFA972F5ULL, 0x8D1103F1500816B8ULL, 
            0xFF52FF88A3ADC131ULL, 0x9EF4FEE4E89AEE7FULL, 0xE04341D278F9E166ULL, 0xB5B91BCA87C4094DULL, 
            0x600D75DCFE854A69ULL, 0x6ADBEC58575BF36AULL, 0xC495653CA0EAA602ULL, 0xE1FCA06195B18F12ULL, 
            0xBDA5FAD1B924E37BULL, 0x0970DBF9304614C4ULL, 0x20BEDE25E681FBACULL, 0x1644384A99C0AA57ULL, 
            0xA410DBE81CF7410AULL, 0x895793260584E296ULL, 0x45DE6E13A8316D82ULL, 0x3472A7BDD3A64794ULL
        },
        {
            0xFAF49E2074CF042CULL, 0x08CC74B2A1B56413ULL, 0xE269959B60E1A559ULL, 0x11C7148DA43FD3EEULL, 
            0x0C185D6F924DE7FAULL, 0xFA2E1106D50AAC2AULL, 0x8CED5CA5F79171C9ULL, 0x5DE6B81C56FCA903ULL, 
            0x06CF410F51B991F8ULL, 0x31EC4A716C1E873EULL, 0xAC52B12F7A5F7620ULL, 0x4D8DFE8343E33FD3ULL, 
            0xD51D6C0D40566BCAULL, 0x073E45501188F46EULL, 0xE45F923A31E2C819ULL, 0xE2FB69C1F9A3DEC9ULL, 
            0x682092A678690986ULL, 0x87C59D47C69F9A42ULL, 0xFE53E3C368872BEDULL, 0x25286743FC33C360ULL, 
            0xD13ECB3DA7883B2AULL, 0x1A2A6E70A678BC4BULL, 0x6AAE69978E7CBB3EULL, 0xDC76363B2D5F4C71ULL, 
            0x3B8F698AEFEEC944ULL, 0x0CB352E09B006FF1ULL, 0xC5F77356C799F1B7ULL, 0xAD48EBF47091DE17ULL, 
            0xC23359F0C551DC13ULL, 0x9B84D8D234EBC6B4ULL, 0xBD2FC14FEEF6511DULL, 0xA8276FA382FE04F8ULL
        },
        {
            0x17A5259B4D3CBB4CULL, 0x796AD62EE7F45F43ULL, 0xCBE33EFE1EEA1650ULL, 0x64FFA09419784B90ULL, 
            0x8196108CBB5F0B4AULL, 0x0AD31F50433EF7FDULL, 0xCDFB8E921E67AD59ULL, 0xFDA1A9E85F5BCE04ULL, 
            0x38DE0CB16F506592ULL, 0x562EAFE4E24240A4ULL, 0xAF221A671F850527ULL, 0x989EEC36C26925F8ULL, 
            0x8CF26688AE0C23B1ULL, 0xA02EA6AF25429650ULL, 0xF2C1D49FADE563D4ULL, 0x5EBA100139F06F06ULL, 
            0x0DA059700D1A9015ULL, 0xF22C1A3A4DDD5D2AULL, 0x6031F1ADF8E35BC8ULL, 0xF4D8A1A1378842E3ULL, 
            0x4F2C2B7902A9095AULL, 0x6CA27B881814C4B1ULL, 0x9324880D0D3A33C1ULL, 0x4FE2E7B7DABF6F0EULL, 
            0x7A51451806079536ULL, 0x38DC89A8DD965574ULL, 0x189E0E03CB22D8AAULL, 0xEA8F84618E64D464ULL, 
            0x3F2785C07E4E2C28ULL, 0x8A953AE35EAAA544ULL, 0xAF882C575E5322A6ULL, 0xAA40C3DF8AFC606CULL
        },
        {
            0x4209C170A54F9BFCULL, 0xB963D2CF9F0CA259ULL, 0xC874AED5A9978860ULL, 0x626312FAE81B243EULL, 
            0x23686B50ABC739D8ULL, 0x7FCCBA52BBE9927DULL, 0x6C9A2C5C674EEF66ULL, 0x6B732E6FBE542B46ULL, 
            0x3361AE32FAFA2494ULL, 0xD799E266F27771CCULL, 0x8427C78CFE1149F7ULL, 0x64FBCBA854BB7F0EULL, 
            0x3CB6612FAE561D32ULL, 0x0077A5801ADDD829ULL, 0x0ADB55A0147469A0ULL, 0x803897152E7F1C9DULL, 
            0xC646724560688731ULL, 0x0A16C543979A14E8ULL, 0x13F9DBF03D64FE23ULL, 0x9BD570A4DDB3C648ULL, 
            0x92E759B0508B0486ULL, 0xAB108F8914DA06B8ULL, 0x42593B26B0E04B8EULL, 0x0F9959B2458B5728ULL, 
            0xFED27DEDC5303B07ULL, 0xA66B216A38D928B3ULL, 0x08288408D14C73DAULL, 0xD78236E07700E76FULL, 
            0xF6863E434D5B2201ULL, 0xC52B5D71D6EEB806ULL, 0x30C89760CEBC18C6ULL, 0xE03C9A60A5918993ULL
        },
        {
            0x44A337B4A2C34CECULL, 0x939D06904D6A7229ULL, 0xB91459487ED361A8ULL, 0x729BF8BC23B79DC8ULL, 
            0xD275BF3783B0B764ULL, 0xC6B3BB1944EA3A1CULL, 0x843DD615BFE10F7EULL, 0xDB0991608798A8B7ULL, 
            0x15C34CF04685F452ULL, 0x609D27726CD5F8BCULL, 0xB34B3FDAD54051BFULL, 0x11914477BBF26FA6ULL, 
            0xA2861381CC70D21EULL, 0xED41EA8EFFA7ED89ULL, 0x58208B70B9632D41ULL, 0x96CADA971D4AF4E7ULL, 
            0x8B0D75B419BB5E61ULL, 0xFEAEF879C1D94266ULL, 0xA3A07F15EEA306A4ULL, 0xCBEB96387CFA7FBFULL, 
            0x107E208B95E566AEULL, 0x33CF72D4A7FA45BAULL, 0x325892189475EEBEULL, 0xD3560E5DE3CEDA7BULL, 
            0x883B10016E6649DCULL, 0xE017BCB392560F34ULL, 0xF9B65C6634933B14ULL, 0xD43342FDBD53AEF9ULL, 
            0x12315DEF8791C7F7ULL, 0x4656C58EAD8F0845ULL, 0x2614BE89C75D27D0ULL, 0xB341DD1B570651E7ULL
        },
        {
            0xFAA2A7E03A9A4C1FULL, 0xD64434B0D2614FE2ULL, 0xE31E49243E06E6CBULL, 0x65FC7ED02A13EBD0ULL, 
            0x2E4D4AB4AA51F6BBULL, 0xD142031551D15625ULL, 0x3ABFC8834E1C1898ULL, 0xBF77005211DC0E43ULL, 
            0xDF55CA8BA1510BF8ULL, 0xBA071BFB2FBE701CULL, 0xED4EBEC632644F39ULL, 0x6DFEB8B87173E6D4ULL, 
            0x416F38A74A253D1EULL, 0x060F3E1ADA8EBC2FULL, 0x9F28D6408628FC95ULL, 0x0A7EF22DF30228FFULL, 
            0x72BA82E8FF116BC0ULL, 0xCEE7D6B2DEB533D1ULL, 0xAC6692B2A649E6BDULL, 0x665085817B22188CULL, 
            0x412445176E4B305FULL, 0x17B928DDF97913CEULL, 0x7E809B2E721456D4ULL, 0x4EDEFD4C54F1339EULL, 
            0x520E9B90062B3898ULL, 0x3ABA2A9155460B6FULL, 0xF63042AEE82B17C8ULL, 0x3B96EA2DF83C0C63ULL, 
            0xA0D5E2DC1F8B7628ULL, 0x66FA1FF74AF67736ULL, 0x1AC1D4D20AD5A0B9ULL, 0x591815ED3A9A96EAULL
        }
    },
    {
        {
            0x71A7B56DD8A174FBULL, 0xE4BCC0ADAA5600D5ULL, 0x95C973620834F717ULL, 0x7DCB0B4C186C609EULL, 
            0x522912052B13A180ULL, 0x3C1C2BEAB55D28A1ULL, 0x0B3E5F700DACFD75ULL, 0x32B104A703700D4FULL, 
            0xA1C861ECA42C46ABULL, 0x286051CDE773DEC3ULL, 0xD444DD28F55837F2ULL, 0x146D0286BF7B31D6ULL, 
            0x2923FD973D58C983ULL, 0xB1065F03EF695E5DULL, 0xFD6C934CE4057889ULL, 0x5BD045E271C2E719ULL, 
            0x4854B23053D37582ULL, 0xFF75E13731967EFCULL, 0x662F44BD8BDACAADULL, 0x92D9CBB422C760AFULL, 
            0x2A09E37FD74D6C1AULL, 0x678238D2A218EE8BULL, 0x369240CDB69BE926ULL, 0x0A09B9D4FC1015FBULL, 
            0x05C3F1CC390CF110ULL, 0x1404FAAC40B34786ULL, 0x3739A4B412484097ULL, 0x947D30F079E75C56ULL, 
            0x88A3042B4EB40F24ULL, 0x558F05D6955B9991ULL, 0xDEACCC1358EEF27BULL, 0x40A81D5BD7817DC8ULL
        },
        {
            0xA1B3371AEA45DF80ULL, 0xDB4B01E7B5E4C91FULL, 0x7F6B9E27A4B8142DULL, 0x7D5D79107AE67BA3ULL, 
            0x94277A427A9CD440ULL, 0x6A8BC1E754D94436ULL, 0xC8FE916E2CBBB3ACULL, 0x4D356FD5549D5202ULL, 
            0x668B5CBB1657E972ULL, 0x7094D60954D96852ULL, 0xAC8AFCBE85A978B9ULL, 0x1A51981D5FDF0715ULL, 
            0x45DF640031DFF1F6ULL, 0xFCB6998B136CBBA6ULL, 0xD4CC3D3E2EF0FA29ULL, 0xCB057DAFA2742760ULL, 
            0x6D5FC42426D48250ULL, 0x61AC3FB33E74DE56ULL, 0x8F7C4ABB34C31565ULL, 0xD8A2969E3256D5CCULL, 
            0x5215E631734F6BDEULL, 0x77EC0162C01416CDULL, 0xF2B2EC5C2868422BULL, 0x77860D3E409AE09FULL, 
            0x143181A1F2EC9F90ULL, 0xE0B42CE8B27CC078ULL, 0x0DEFD2818568477FULL, 0x9B3A4B36F5FA7C46ULL, 
            0x7639675D02E9E263ULL, 0x714E94F679B6F828ULL, 0x7CDA189488BACE71ULL, 0x247DB78C7145D047ULL
        },
        {
            0x62692F8CEA144E1FULL, 0x77A1B8923B7C7E4EULL, 0xD374375AE8C4DDA1ULL, 0x9E5B074CE5DFC11BULL, 
            0xCADCD3BE46622596ULL, 0xD2F8763D3233634BULL, 0xAB5C787D08323064ULL, 0x7A7AB7CD9A74E484ULL, 
            0x10B7A0E4E1E2029CULL, 0x581FFFFDF9F67F2CULL, 0xB9C30571DA54EFD8ULL, 0x57E8A888E50482D7ULL, 
            0x01F56B7803DF3DF3ULL, 0x38EEB5C0FD6E6EF6ULL, 0x2D7A4394B2EC738FULL, 0xC94C9F413725D50AULL, 
            0xDD0A52587DFEBB5DULL, 0xBF584C5A42A2ED57ULL, 0xAC83615EE5ED9DB8ULL, 0x471C578F9A67487DULL, 
            0xB64A8D0A2258645EULL, 0x515E46A666500254ULL, 0x39D7605A5B54DD96ULL, 0xBBA9A0D1F82E86B5ULL, 
            0x8E5AE1CF2AA04237ULL, 0xDFAE05A4843501F5ULL, 0xE2BD74C3A2D4CD1EULL, 0x68AF0908AB9650E8ULL, 
            0xD968D982EA069CA6ULL, 0x4CCEFBEE17F736F9ULL, 0x7A0E8AF4D5187A6CULL, 0x7A88C2A1D16999E0ULL
        },
        {
            0x736E893160A6FD91ULL, 0x6C52E32612D3946BULL, 0xEBFE468E8974020CULL, 0x5EAD43E0AEE5052CULL, 
            0x5BF577582C07B4F6ULL, 0xFD4BDBC4DB1FF2E0ULL, 0x13CBB47317F694EDULL, 0xB11A55AA267855DEULL, 
            0x4E49F59EBFFF4186ULL, 0xBA7FF747F29B8805ULL, 0xAB9B5C1D91DD383EULL, 0x327780711DB7DEDEULL, 
            0x614BC2093E2C0806ULL, 0x3BBDAED4802376E7ULL, 0x328BB728609A3200ULL, 0xD4C55193D3EACA27ULL, 
            0xAE6EC18E68339124ULL, 0x5544AF318F93A06AULL, 0x0FBE7E47CCDC9F42ULL, 0xCC38373986924AA7ULL, 
            0xFEE1A976AD381EF6ULL, 0xCD075FB1307AA57CULL, 0xF514E5E218655DE9ULL, 0x3FBEF88235DE0BD9ULL, 
            0x2F61D150790459EBULL, 0x9BFDBD6D6F463C87ULL, 0x5BB6BCDFF74245A7ULL, 0x0DD885E428C7F70CULL, 
            0x3A4DE73544918E8CULL, 0xF8B87A19256C6B1FULL, 0x9601581BCDDABB91ULL, 0x460760F8FB0F67C2ULL
        },
        {
            0xC4D3EE0F5A9390E4ULL, 0xD655BC1EE5F7346EULL, 0xE037C2955D7894F4ULL, 0xE25804D82136DB3BULL, 
            0x9DA0D72C21F4675BULL, 0x133D0E2BD07C3867ULL, 0x37640B94A22A8AEDULL, 0x2BA65622C54FFDFEULL, 
            0xB50EBEDE5B2C0842ULL, 0x4AAB81B1329FDE79ULL, 0x92F6800C9119BA1DULL, 0x1BD1B4FF0DD05825ULL, 
            0xF3D524EEE901DC52ULL, 0xDBE9AFBFE17A0302ULL, 0x1E4EC79425FD1997ULL, 0x321AE408E6373129ULL, 
            0x8DEB8A1D38632D78ULL, 0xFE484F8921AE190DULL, 0x75BF7B342E800FA2ULL, 0xB8964A25F53769B3ULL, 
            0xD15E4FF7321FB391ULL, 0x3C38EFF270F79943ULL, 0xA48ADD0CBE5D0712ULL, 0x63A7A823C67C1808ULL, 
            0x8C34892B6BCB6442ULL, 0x13C483E3F2ACB78EULL, 0x05AEF7D7EA021DF3ULL, 0x6177526D9E5EBA3CULL, 
            0x3367AF26186B69FAULL, 0xEB78F9FB1B196081ULL, 0xF94545B31DAA4308ULL, 0x0B814FD31681A313ULL
        },
        {
            0xDB2DD8966D0179B3ULL, 0xB3F7F2D2D179789BULL, 0x661AEE2D805D4C86ULL, 0x8BA601FAF631F76FULL, 
            0x24D0618EC5C86975ULL, 0xBE8181089ACDF44BULL, 0x970049E181C975F9ULL, 0xDD9A8ACDBEF96C16ULL, 
            0x76513425318105EEULL, 0xB65D62311F3F6514ULL, 0xCD82CE7039BCCE18ULL, 0x46C98175C22E2230ULL, 
            0x26A37C69E7ED001BULL, 0x9341960DA97E676FULL, 0x1BFFA2C6A02DB317ULL, 0x0A003006F62F0660ULL, 
            0x89C820CAAB0248B7ULL, 0x0C762359C2A3EBBCULL, 0xC5D0BD2F8DAC6E61ULL, 0x18416730D65CE8C4ULL, 
            0xC7F2C2DA953ABD53ULL, 0xD2FD4DF0AF5D23E9ULL, 0x75A10157C9BFD811ULL, 0xA3506DC23F7DE9FEULL, 
            0x3E476EB8FEBD7788ULL, 0x7558F257B35BB274ULL, 0x78DD6F7EAE56A5D3ULL, 0xF76AF4D0E147FBA2ULL, 
            0x57CA337C0C0CEA9DULL, 0xFA9BB08D06EAA1F2ULL, 0x25BDE1F2BEDABECBULL, 0x2EBFCB58479CE4B7ULL
        }
    },
    {
        {
            0x3E3FB7014121308FULL, 0xA01E41AE67A32C29ULL, 0x45E07C66A29F99DAULL, 0xD0605BA22A2A20DEULL, 
            0x5057E96A517DF170ULL, 0x9959FEDEF95C2556ULL, 0x303FF4F495B862D1ULL, 0x45C364B7A8D8028CULL, 
            0x22AC129FB261DEE1ULL, 0xA46F4985EB1DA626ULL, 0x73F216D8376E369BULL, 0xF9ED05FB70920C72ULL, 
            0xD9313C3695E5638BULL, 0xB793DB5785311E66ULL, 0x54CFBC5319116900ULL, 0x936EC2EB14BDB596ULL, 
            0x36E18CEF15571497ULL, 0x92B5A24BDF31295EULL, 0x0DF83D7F80C89BF9ULL, 0x65A06030F194FB19ULL, 
            0x38092394CBE4D099ULL, 0x6B278D51E7F293BAULL, 0x9A64A8AF27EE6954ULL, 0x01AA27E9F76E208BULL, 
            0xAF519D1E083217A9ULL, 0xA2EE992E19406833ULL, 0x6ECB4BE0F4E34412ULL, 0x2DC1F774F46D3831ULL, 
            0x4AD4F9DACCA54FE6ULL, 0x489EB79E7422FCDFULL, 0x2F949DD892495C5AULL, 0x5AF4818C64DE7B77ULL
        },
        {
            0xDAE97326380DCB5DULL, 0x9CF54DB577AF3646ULL, 0x4918ED32FE6FEAF8ULL, 0x2E90E94D23F450C9ULL, 
            0x8DD0EC6AB5CD154AULL, 0xF891C01862354054ULL, 0xB128B41499EB872FULL, 0xFCB73C2795B659DAULL, 
            0x2FB9099CBD476AC9ULL, 0x3371F7D05E4AE239ULL, 0x369241B8F692AF45ULL, 0x3153EFA007F1E0B5ULL, 
            0x35B834B103378440ULL, 0xE1251458C6D06FA7ULL, 0xF9A82F69F93524CCULL, 0x430DE3B57B47FA4AULL, 
            0x9F3EC44D52C8B96BULL, 0xC209FA96367AD95FULL, 0xA20C8E4319B6B8BFULL, 0xB47390D09AEC4268ULL, 
            0x01418382795B5636ULL, 0x1B118DAE1AAEE05EULL, 0x6E35196E6E489CFCULL, 0x165622EC0E417ECFULL, 
            0xBC0DACD13F3F8741ULL, 0x79DCE6B4CAE18385ULL, 0x848264862C1A8ADCULL, 0xA917246BF588CE57ULL, 
            0x8847FF7789B5EA1CULL, 0xDC4BE1E53ED397DCULL, 0xC7DDCCD436E4EC3FULL, 0x8A54E45D3CFC130DULL
        },
        {
            0xCDFD58B16D09631CULL, 0x9869FF1A2F3CA753ULL, 0x47F2592A29758C15ULL, 0xB425B87E164BDFB6ULL, 
            0x699A0B41EEE71589ULL, 0xD4BBBCDF39CAF0E9ULL, 0xAB5CDA5DC48CD193ULL, 0x9D03EF68700EFD68ULL, 
            0x2D9204C60DD2BA1FULL, 0xB575FFFB239149C9ULL, 0x632F7EA058F1EA52ULL, 0x224109C165AC4A83ULL, 
            0xFF9C5A45F3A41F03ULL, 0x3E996FB2893858EDULL, 0x04C769A7806A14D0ULL, 0x33DE523F8F2DC5CCULL, 
            0x5D58562134433311ULL, 0x84DBFF083E7E4BD7ULL, 0x8FED28EF9C85FA82ULL, 0xA24B0AF83DFDD329ULL, 
            0x006FD0E3F94435D5ULL, 0x23BB0467F3663504ULL, 0x6D1FF7039F690042ULL, 0x59B6CEB0D9B5AF06ULL, 
            0xBC9C100D2C3D91A8ULL, 0x062C1F056B5FFAD9ULL, 0xFC7DC5DFE4F621E5ULL, 0x906BDFA6A12D6E92ULL, 
            0x58E66D726B68F818ULL, 0xDFCF75B54F00B211ULL, 0x0B4B1DA128BE1383ULL, 0x680FC805E18FA8D3ULL
        },
        {
            0x9251ACD4B34A334EULL, 0xDB65A2A940B0D175ULL, 0x3D804013433183F2ULL, 0xB2229CD45220C45FULL, 
            0x8DC1BCE59FC3169BULL, 0xE2801004B99DEA0EULL, 0xD2C7EF93551A8F32ULL, 0x35C13A2D2A809A9FULL, 
            0xACA0B87415A9DAAFULL, 0xBA053AE92BA5715AULL, 0xF5112657E4EABA13ULL, 0x8393D14870008EF8ULL, 
            0x10EB2CD2A305CA36ULL, 0xD8C3117D8F518B75ULL, 0xFC67B9611A0384B9ULL, 0x733D8E758E04B1E2ULL, 
            0x912DD7FA43A8FBA6ULL, 0x989C695CB1CD6701ULL, 0xB65903403396851FULL, 0x2B427666A0295DC0ULL, 
            0xB9D5423F4EB25F6BULL, 0xE3DC2E2DDB81D160ULL, 0xC75B9BCF1F6BE764ULL, 0x8F78C841893B065AULL, 
            0xB6A24C722F73FB34ULL, 0x71A344D718E3CEBDULL, 0x08D777FA40FD0F11ULL, 0xF1B48E5F59A93530ULL, 
            0xFB187AEF8B92929AULL, 0x37EA4505BAA0FF41ULL, 0xFE2712E1FF5FE2BCULL, 0xC6B046BE26EF932FULL
        },
        {
            0xBBD9C0F12AFCDBB2ULL, 0x69C8FE528FCB9CF2ULL, 0x5ADCFF1A5E0BE8C4ULL, 0x5101220B87F4623DULL, 
            0xE9B0E00FB06D8C3EULL, 0xFA56F8B9D39F8545ULL, 0x486760C780738634ULL, 0x48EFA5C0CD719E2DULL, 
            0x4E2E24F6479804C8ULL, 0x5267E2275F05D34FULL, 0xCAC56655EE562892ULL, 0xC4E315DFC8454DF3ULL, 
            0x16EE397AF60D4AB0ULL, 0x3EF65FA9B1E55665ULL, 0x4A7117926D97A53CULL, 0xB45526E398F10FBDULL, 
            0xCC4D93EC16B5DD17ULL, 0x2E071C2B5A48EC17ULL, 0xBD4F78AC2AE44C54ULL, 0xD1122A5F8DAC204DULL, 
            0xCE011FEF7B1D7BB6ULL, 0x7B6DA7AC6F06576AULL, 0x3161EE7675A6B7F3ULL, 0x3097D7274FE6904AULL, 
            0x87FDB43A30EE46D3ULL, 0x2E7B148347A4A90AULL, 0xFC4CA8D825111E93ULL, 0xBE1B806E0D93A60BULL, 
            0x8308FB0B3927819DULL, 0xBB5D8C5D416C89CCULL, 0x4B786D06BBBB943FULL, 0xD74C8F1AFDB29E64ULL
        },
        {
            0xBEFB869E183F9A8DULL, 0xA4CE2E438717F32CULL, 0x453FC333CFDE6E70ULL, 0x5FA31739712A6A4CULL, 
            0x6783231A29AA5372ULL, 0xAA3147DD6D677B18ULL, 0x55B0E1C34AFD9741ULL, 0xD88D519064F96C62ULL, 
            0x7D641954F9D9F0BDULL, 0xC4B9E12A8AEA77D8ULL, 0x578678C75687398CULL, 0x004266AEDCACFE81ULL, 
            0x9D60A6C4668EA841ULL, 0xAD60CBC6450764B4ULL, 0x49920D3EAD5A1B61ULL, 0xF8500E742D18BE5CULL, 
            0xE7A5E3DB6047BADCULL, 0xA34CE59BFBE08766ULL, 0x145020F5216E9608ULL, 0xC12436F3C56139B5ULL, 
            0x4FC5EC86031B0634ULL, 0x7EB8F4CFC74F483FULL, 0x6C56943DA58E75D2ULL, 0x1CAFB8A59585BB9EULL, 
            0x4DAF826DC745AAC4ULL, 0xFB853B0D58DE31B2ULL, 0xB7E24111C3BB1A6BULL, 0x03C9B10C5F6AC50FULL, 
            0x2589016E91B425DFULL, 0xBB39BE7E68317058ULL, 0xB37A60B633C53F4EULL, 0x700D6A2355845E40ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseDConstants = {
    0x21B0811FE8DA6D61ULL,
    0xA56C3D49A1248D0AULL,
    0xA327C9A4670926BBULL,
    0x21B0811FE8DA6D61ULL,
    0xA56C3D49A1248D0AULL,
    0xA327C9A4670926BBULL,
    0xA113FCF64692E3E7ULL,
    0x27734CC802BEC300ULL,
    0x6E,
    0x0C,
    0xED,
    0xC0,
    0xF8,
    0x5D,
    0x10,
    0xA8
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseESalts = {
    {
        {
            0x63374EA29BF40460ULL, 0xAA5C141D6FED7141ULL, 0x78A427259EA38E8CULL, 0x924E1AB9C4E47D14ULL, 
            0x43505521A46FA82DULL, 0xDCC168B01A889B7CULL, 0x2D488E0293386FE2ULL, 0xF7BD3809C4BC1911ULL, 
            0x5B339DCF365DC0F2ULL, 0xEEBF61E8B924B42FULL, 0xAD48BEE58657BBA4ULL, 0x6863CB7873472929ULL, 
            0x1BD91ED8917E8172ULL, 0x8737950A06D6069AULL, 0xD10CF4861D10D85BULL, 0x56CD26707B3321B7ULL, 
            0x152B820436DF263EULL, 0xEA3EF7BE27CBF2DDULL, 0xC59B745E78917629ULL, 0x9F035ADA76F8029BULL, 
            0xBEEC6B266086CD5EULL, 0xE550FA25911880AAULL, 0xF41EF4C35D301471ULL, 0x06AC3691DE6EA2D8ULL, 
            0x32956511103B70D5ULL, 0x3B9BBD257CEDE584ULL, 0x54E9E3E3816752C9ULL, 0x70E3610AD2599C66ULL, 
            0x712A1B2F0CE399FEULL, 0x1B8FC467BF76BF60ULL, 0xE54C80FFD56A4228ULL, 0xA3A595AC96BC0FB9ULL
        },
        {
            0xE7197E2D0900BD7CULL, 0x18DD983E64A994B8ULL, 0x7C55DADB4FDE90B3ULL, 0xA3181F14F5789C3BULL, 
            0x37FD0AC481B59C8DULL, 0xD91250341F1E435CULL, 0x6DE146E97F77434BULL, 0x201AA0F6F9F7E080ULL, 
            0x2C9A00DCD2244823ULL, 0x92D5D4B4B1F4E19BULL, 0xDEB4117711000061ULL, 0x01722665DEC22CDEULL, 
            0xA4E3168DAB2EC93CULL, 0xA6997FECFF4ECABBULL, 0x9E4F6F8C92B62FD6ULL, 0x04309250A48443CBULL, 
            0x09AA1E95B47EDC8AULL, 0x3B288A516C9F0359ULL, 0x4012FD6EF9B31F93ULL, 0xE20FEEB7C5B33B4DULL, 
            0x7E0C6BBE1D80E090ULL, 0xC819012E4370900FULL, 0x95C0D50BFA1068F3ULL, 0x9D5624BC0EE00F1AULL, 
            0x268C536F52219087ULL, 0x6327FD58D396CB2CULL, 0xE8C4584BA59D7C54ULL, 0x5F91FF244E3A76D9ULL, 
            0xB9A0CA23429AF256ULL, 0x6B9B742906A96FF5ULL, 0x38D371C9B89A15FCULL, 0xCB67CC9586F894C1ULL
        },
        {
            0x4E388C8DFB3F1135ULL, 0x0F3FB0EE6295D164ULL, 0x341EF28704ED45D3ULL, 0x4C181D37DE347A7DULL, 
            0xD673A5622BFA8FEFULL, 0x488A50FA120E56BEULL, 0x0DA474CDF3E7EB51ULL, 0xAC95363E791C7AB4ULL, 
            0x6ACDF002F368D3A6ULL, 0x5ED4BF5AFCD73D45ULL, 0x20F99B9529D8CECCULL, 0x31E14E8E671F4876ULL, 
            0x3F69C19AF1A044F2ULL, 0x20F58A4342B6E749ULL, 0x81F9EB4294465750ULL, 0xC58BE2F80EB9CF1EULL, 
            0x95A398AC9CC7FA66ULL, 0xC4F881FCCF9BFC2FULL, 0x6EBF2F4F1E1BA27AULL, 0x88614C1F813FCD97ULL, 
            0xC627B7C9DBE52A16ULL, 0xAC9762503535D43FULL, 0x1F4155F7C768A13AULL, 0xC2060DB3AFF78A1EULL, 
            0x3154AECA40BECFA0ULL, 0x86CCBEA77F6834DDULL, 0x8FC3783ADAEBC609ULL, 0x9C265AE17CA65F10ULL, 
            0xE4E1F7EA25E3B037ULL, 0x89D8FB892AA6C706ULL, 0x3A09EEC499634F65ULL, 0x622E77FA38743C83ULL
        },
        {
            0x9F759E74D9C8E918ULL, 0x2D461D92901CF656ULL, 0x49C56A46B3FB895CULL, 0x5ECB6CDDA2D3BA29ULL, 
            0x5CD476D18C9B87E3ULL, 0xFD07A17704775B77ULL, 0xD036FF30934669B9ULL, 0x1228DAB38FD45C5CULL, 
            0x590976BB1E37AEA7ULL, 0x0CF2A0283DF7D02FULL, 0x972CE906F75B9F77ULL, 0xB2D2BD6120CA10CAULL, 
            0x51189623AC3E16B0ULL, 0x4A451A22405F60DCULL, 0xF2DC365AB9F7D5A1ULL, 0x536E7593DD78C1A3ULL, 
            0xAE18F5706F171E78ULL, 0xC42972E05C0E01C9ULL, 0x6145F08FB0397D89ULL, 0x72233BB8C7DC4BCEULL, 
            0x232A23CA2553F1F3ULL, 0x5D843F1206F25819ULL, 0x70FB5A2D137C36A5ULL, 0x0C957923BD0B739CULL, 
            0x36201B8F6F1A2E80ULL, 0x35402592BB72E635ULL, 0xD00E6321BE123F46ULL, 0x6D754E0EC7151CB3ULL, 
            0x9107A5C9679B1C18ULL, 0x6C79B3D1AF68DF47ULL, 0x19AF4AF88506B046ULL, 0x1E7B9A5EAF197430ULL
        },
        {
            0xAF2B02DCBE58F859ULL, 0x808AD629905001D4ULL, 0x62E4E350BE00A0CDULL, 0x1D1BCF6CE6ACFBCEULL, 
            0xCE5F6372ECC1EBF3ULL, 0x44702BD93F04A9FEULL, 0x446AE78D4A753303ULL, 0x0F7B2F7E4E34E4E1ULL, 
            0xCF8A7F087DE68819ULL, 0xA9B4AFDF24F39FC6ULL, 0x2A1F507506458B25ULL, 0xCD2F4C11D1FE5DE4ULL, 
            0xCF2E0EA22F91589BULL, 0x797707B0AE13E558ULL, 0x2B1C14122D389D7DULL, 0x543682277BC4F864ULL, 
            0x3C925F0FCF6F4DCAULL, 0x65A4938FC4749023ULL, 0x38C48EB487322D5BULL, 0x482DF280264BFC8CULL, 
            0x94F5F7C45497F3E6ULL, 0x226341A3364790B3ULL, 0xACBE4D56C83AC154ULL, 0xB74511F642853B5CULL, 
            0xA5DE5C6D20DEA9B1ULL, 0x0F2E2E269D581EE3ULL, 0x0DBD7454050EA6D1ULL, 0x22E0314A1E054DBEULL, 
            0xFEEE2F8FCC40CC98ULL, 0xD9CFEED751FFF751ULL, 0xF88BF62FE1AD3398ULL, 0x24CAA6E040E645A2ULL
        },
        {
            0xFC10DC7A5964430AULL, 0xB26FD02ECCC076C2ULL, 0x9242449DDEB2F25FULL, 0xB06F445250C58B77ULL, 
            0xDAD0153E770D9DBAULL, 0xDB4BCD64E2F4466CULL, 0x76DA22483231BE19ULL, 0x6651A82087CC876CULL, 
            0x72FBE14924843F1DULL, 0x0BC5AD6D26CD08BAULL, 0xDA31A2C2760E3090ULL, 0x2D8ADF9926D59743ULL, 
            0xC18EAE0B812A0F09ULL, 0x8610D12AF2C97582ULL, 0x07386E47EBFD3C25ULL, 0x9BED5B8AE2054040ULL, 
            0x85E13A5DAE4005B0ULL, 0xEC0630BCB5942854ULL, 0x435156DF35551CD0ULL, 0x8A0335D56669C155ULL, 
            0x6BA5F7EF98558469ULL, 0x9057320028BCC515ULL, 0x3C1C359962259830ULL, 0xF54BFD8D1520BA7CULL, 
            0xAE9F90B5FE4687AAULL, 0xB445B9E7CD886ACDULL, 0xB5877DA07A58A560ULL, 0x68B7F2766AF092A7ULL, 
            0x55A8B35051082E5DULL, 0xC37197818CA45B68ULL, 0x531424C50CB19F74ULL, 0xD49EFC7CD290B7E8ULL
        }
    },
    {
        {
            0x9CCE98AAF7D3EEF0ULL, 0xDC0B41BE925D34DEULL, 0x2200AF0BF6444F0AULL, 0xBA44608D79DDA391ULL, 
            0xA29709ABEAAF480FULL, 0xCBAD81E10E721DAAULL, 0x2F87B3FB4A1C255CULL, 0xAFB8D851801A2384ULL, 
            0xABCA5570D13E8930ULL, 0xAA3DD08349AE0604ULL, 0x91760DBA5021A16EULL, 0x0B8CA0069AA330D3ULL, 
            0xC6637CEFCC35F9A7ULL, 0x449C2889FD0301BFULL, 0x41F258E52CD289AFULL, 0x01DDEDCFC5B76A80ULL, 
            0x0C66C8FF6FBE5884ULL, 0xAD30B95048D79A1EULL, 0xCE132CCA00A4EB26ULL, 0x8110333F77EFF7DFULL, 
            0xF7A02046C3153AA7ULL, 0x1F2399F8C3C8D227ULL, 0xC79930314FED53CEULL, 0x628C1EDAE614FB2AULL, 
            0x14048A2BE8864780ULL, 0x9E0FE86AE699DDF4ULL, 0x4C227DE2A61050B5ULL, 0xD95A41FF77C5C571ULL, 
            0x537EDE32FE1ADC96ULL, 0xB856396ECE08EBCFULL, 0xD51F467BED35550CULL, 0xE0350037AC05DB7BULL
        },
        {
            0x848493C81845DB92ULL, 0xD1A90A00242622EFULL, 0xD0139B443C1C48DCULL, 0x7B8B543877E5F9F3ULL, 
            0x7BBB1E83DCAFD584ULL, 0xEA31A176260A9046ULL, 0x14814BA49E901461ULL, 0x3C06DDDFB4D1C9AFULL, 
            0x54860FA744909D96ULL, 0x8F5A36050DF9DA25ULL, 0xB51D726922B7B46DULL, 0x6012F4FF19613430ULL, 
            0x722645BBFF8CFBC7ULL, 0x2C123E6992433293ULL, 0x32D02CC60245FAB1ULL, 0xE60160CDEACA8789ULL, 
            0xB727BFE7600F1D60ULL, 0xB62450E9116ADE11ULL, 0x7E2904ED00CC92D5ULL, 0x589BF921158FF2D8ULL, 
            0xCE9B5DD9BDF18743ULL, 0xDB7F1902B0AF4775ULL, 0xEDE1DE632B6216B5ULL, 0x624BFA95A0A68CD4ULL, 
            0xE4C83D6495B9C3A6ULL, 0x414313AD950880AEULL, 0x7B689D0D92A96F1EULL, 0x893DFEB1AEE2742CULL, 
            0x597AA3C1DF1787AEULL, 0xC89FD0E423CCC73DULL, 0x0594009A02BAC9E2ULL, 0x6B1981F1C5345922ULL
        },
        {
            0x6141EEAC1C7DE139ULL, 0x303654FC42C609DDULL, 0x42932D65C81F3949ULL, 0x4503BCD92C6F21A3ULL, 
            0x87118ED92531F67EULL, 0x17CC91049AF35F44ULL, 0x440DC3C9EF3109DCULL, 0x8F8FFAD68E800117ULL, 
            0x050E48CDFB5D341EULL, 0xA10FB899A02B7F86ULL, 0x3608DEF57D7DA695ULL, 0x514C9D0AC56C4BFEULL, 
            0x209BAE78E0840BEAULL, 0x4FBDEB264DFA216EULL, 0x42393ADEE4050735ULL, 0x342D122C0A5DBF6BULL, 
            0xA64E6FF7455624DDULL, 0x964698FD344A0730ULL, 0x87102259C22F6BB7ULL, 0x7EFEA774A87D1704ULL, 
            0x49F0BFF04A4EA806ULL, 0x7F094407FEE6A2DCULL, 0xB7DD46164BD53AD2ULL, 0x1021672D44CD9915ULL, 
            0x32DE60E5F87F8C03ULL, 0xF7CAF14315014929ULL, 0x96D0BA142ED8EF46ULL, 0x2915FA7F679DCF45ULL, 
            0xC39CBAEE1175AA7FULL, 0xCE2963B68D9F1ECBULL, 0x7B7D415A7FE0087EULL, 0x16E1B4871C170632ULL
        },
        {
            0x2B6832DDED58BEB0ULL, 0x66B35A149FD7F89CULL, 0xCF89FE6F9EB3CB93ULL, 0x67A244E7ECBDC0AEULL, 
            0x78EEEFF282F7B958ULL, 0x0CFD892A8005781CULL, 0x5766638C84B2E911ULL, 0x7C4127D03AB500DDULL, 
            0x24D4F0A3AB993985ULL, 0x6ACAAD5CC9FC36B0ULL, 0xE2F3D50CC2EA158FULL, 0x05B8D9321C5FB5FBULL, 
            0x72B4D5ED85988F90ULL, 0xAD04757C56634F34ULL, 0x624E6617DC458AD7ULL, 0x8697D2D6548B0ED5ULL, 
            0x8593CEFDD1BA6A03ULL, 0x4C23A5371BF2EC02ULL, 0x4F9389E60AD269FCULL, 0x3AA9ABF68B19AECFULL, 
            0xAF392D623A7770A4ULL, 0x19339F9C35521BECULL, 0x5959F3FEB784D57BULL, 0xF498EBCA4E6F4DBFULL, 
            0x1735AE26A0484461ULL, 0x7451F7951CC36186ULL, 0xC771C081255B52F3ULL, 0x95DA66B078BF4F05ULL, 
            0x26CD8967D91F7D28ULL, 0x2F84E8EE451A2938ULL, 0x8E7DBE5EFED039BAULL, 0x81FE1FF14020089FULL
        },
        {
            0xD8F4A52F83F95AC6ULL, 0x6E2344AE036A69A2ULL, 0xADC027F0B2895708ULL, 0xF3684FA62E757C32ULL, 
            0x5A3584899E1361C3ULL, 0x83924B75BD17156CULL, 0x8965A2F661B49C67ULL, 0x42471AC377F3DD59ULL, 
            0x398C58A125CED7E9ULL, 0xB3D687D842ADCB7EULL, 0x132F152A4A5BF306ULL, 0xB4288E8C5B1DA14AULL, 
            0xAC0E1C7E3FDE174DULL, 0x09D2D8E3B5FD88DFULL, 0xE742EF183C2ABF7DULL, 0xDBBF4A549AD44BA8ULL, 
            0xE770C13E95721284ULL, 0x06C4CA38B4CE4CE1ULL, 0x82886F1640F07FC3ULL, 0x895FC03557C78D68ULL, 
            0xD8A294D7707756E8ULL, 0xF992DB6A6DB21CD2ULL, 0x1970C002B610FA88ULL, 0xD0F68B15199039DAULL, 
            0x10409F115DCF7D32ULL, 0x5492F00EF6600C3CULL, 0x2689552CC6D019AAULL, 0x071E33DA73430B07ULL, 
            0x10FA138EF14A927BULL, 0xD7CEBB2EB5BD6A26ULL, 0xAFF5F83CD983717CULL, 0xB5EF29F797168224ULL
        },
        {
            0xA783FD2DDFBA6804ULL, 0xA791BF6A01661440ULL, 0x9F50D416EEC538EFULL, 0xB43F96EE823758FBULL, 
            0x34F458084B21EBB3ULL, 0xAF3FC23719239020ULL, 0xA490324C700A8F27ULL, 0x3CC16A9074481481ULL, 
            0x7C67E40A94B553DEULL, 0xDEF5591C676FF123ULL, 0xE3A01E2B75CDDF09ULL, 0x87949B00643C6044ULL, 
            0x857A1F1105721F45ULL, 0x15390BF3C7DD4D06ULL, 0x2F601E322AF72117ULL, 0x8779D7139EF6D62CULL, 
            0x1774BAEB6ECB1EC0ULL, 0x707DC9FB5AE31D1FULL, 0x4E733928A2F5EC40ULL, 0x4B465759D03A2FE6ULL, 
            0xD0AF34019828D2B4ULL, 0x25D8CA884B48E3BCULL, 0xCB28210998C42BCDULL, 0x2C5E17D7281A3C7AULL, 
            0x47F4184664671B8DULL, 0xF4AE4CC8820C36E7ULL, 0x147D0E018061B747ULL, 0xF17425E793F885B3ULL, 
            0x19C0FF56B44347EBULL, 0xE7E7A0501D6CE17CULL, 0x05CD9BCC276312D8ULL, 0x2E517073951A3AB1ULL
        }
    },
    {
        {
            0x771984821022FE2DULL, 0x3B05F1841F71F301ULL, 0x9205C03110036937ULL, 0x2899232366A01001ULL, 
            0x94A2EA68B2347379ULL, 0x4524C997ADEF626DULL, 0xEC5E9166FD752DACULL, 0xE88695D6B7B23245ULL, 
            0x586BEDF455C3EB0BULL, 0x44F4F29B1720483CULL, 0xE36FFCBED16307EFULL, 0xC7222F80E220F7D2ULL, 
            0x050E7998D44148D0ULL, 0x9FF4FBC3624C30FDULL, 0x9ABA3878FDB62093ULL, 0xE99043EBF3A0043FULL, 
            0x9B2467B35E4A789CULL, 0xDA3EB8CBBF8DE5B0ULL, 0x24B8824189CE6ED6ULL, 0xDE6AAD2AAD267850ULL, 
            0x7899CA2D32BA4052ULL, 0xCA53EB402DC2A6EDULL, 0x578AD738E4E9BF97ULL, 0xE849CF4953EEB937ULL, 
            0xFF0989E29BC1F8BFULL, 0xC4928C4ADBFCF838ULL, 0x421D9702F6823770ULL, 0x209A39932C8ABEACULL, 
            0x10082411031CB196ULL, 0x2FC23DB70F9D67ABULL, 0x03A7877A6EB9F737ULL, 0x2AED0898064A6232ULL
        },
        {
            0x3D8A38025EAA2A4CULL, 0x8B6770E778916BBCULL, 0x40ED4FC924509B70ULL, 0x3992326E880F324DULL, 
            0x588141382D3925E8ULL, 0x32C222D907FB5081ULL, 0x735C08A95B98E07FULL, 0x84E61F1A43201814ULL, 
            0x243E0928FA0A35B5ULL, 0x8897CB7252C3B664ULL, 0x660A7D3223141AACULL, 0x15271DB5E538CA2EULL, 
            0x1866D60CB06AE172ULL, 0x11693E2008C826F8ULL, 0xFF6E3ED32DE9732DULL, 0xE6802B0D155939F1ULL, 
            0x46BBAACB8F605033ULL, 0x89A6408782622181ULL, 0x03274759A4ECAF37ULL, 0xD176F7B7C07E1473ULL, 
            0x1646ED6E6D857A32ULL, 0x3A5733F8B6E2EBD5ULL, 0x5AA78899C2B9F81DULL, 0xF39F783D3B916366ULL, 
            0x8F323BAA7B89CF6EULL, 0xDEDA3A1816E6ADB0ULL, 0x4C6E3A95C345CC95ULL, 0x5C13F80E8628BB89ULL, 
            0x1A7C35E97C5C3838ULL, 0xC455F2A6C6661AC7ULL, 0x407AF7A14BCE035AULL, 0xF4763B6EA4190F5AULL
        },
        {
            0x0440A3AA4766D287ULL, 0x1A950DA165F36CB2ULL, 0x9C754E0B9145724BULL, 0x58503271C4E0B395ULL, 
            0x31923FFE5A2A181BULL, 0xF2D009ED4727F701ULL, 0x2BF3216D9CB4824DULL, 0x997CB08650856237ULL, 
            0xA169C4C93293375FULL, 0x46DE0469B0EEF90AULL, 0x66BD19BDAE528E0BULL, 0xB2D45C61971A659CULL, 
            0x282A929C14CC2BA1ULL, 0x0FEF1BD085047EF7ULL, 0xCB2115ACD92E77FFULL, 0xF4B534453EB6F0CEULL, 
            0xA2FB6CE94CB9E030ULL, 0xB4DAEB0D3DFB25DFULL, 0xEA619EB5AFE1B4F9ULL, 0x63E89458DCFC385EULL, 
            0xC684D626D5837698ULL, 0x1C181A6710C2AF2AULL, 0x1CC7D6813012C935ULL, 0x30E17AB40B573CC3ULL, 
            0x0BF0D72F732FEB14ULL, 0x22385C6581753FCCULL, 0x68FA9D3EDA5AF436ULL, 0xE60A42F62EB47D4EULL, 
            0xE4565793A245541EULL, 0xD3C8E961EF4F8848ULL, 0x36B936179378FC58ULL, 0xBBEF038EB1E700E9ULL
        },
        {
            0xA087DA024DE4552AULL, 0x8E5A6C6B87C7B484ULL, 0x988E8021999469A2ULL, 0x49998F7C129961F9ULL, 
            0xB46382E19543B8F1ULL, 0x69D6EC97F9A2DD62ULL, 0xDDCC2C5487CADA01ULL, 0xCAC989D6A9EDD7E8ULL, 
            0xCAD5D561C3084D85ULL, 0x58AE347DAFAF487AULL, 0xFB0492FDF1E89088ULL, 0x66260449FB34770EULL, 
            0x5092D944ABCE2B51ULL, 0x1EC39264724CD1E3ULL, 0x67D237AE387324BEULL, 0xEBAFBABA030FD4C6ULL, 
            0x66A3FF9C6D8AC5C3ULL, 0xDFD35CE68E3AFD16ULL, 0x7D3005DF1B3453BCULL, 0xAB13F3DBB6F2A0C2ULL, 
            0xFC1B98F76154DF98ULL, 0x890801E4CFB14CD0ULL, 0xB07CD981A037B0B9ULL, 0x120158C2547CC9E0ULL, 
            0x5BA1F92C0714EB32ULL, 0xEF19F1875E43D763ULL, 0x95085750F4A05E86ULL, 0x92F99E769B08CC75ULL, 
            0x5487A5CA04BCDD3FULL, 0x6108C00ADA182D3DULL, 0x1BF477C774B6D46FULL, 0x7E51FCA892ED42BDULL
        },
        {
            0x9D6CD051EEB8823EULL, 0x98FC4F97973FA135ULL, 0x615C70D816A0BF64ULL, 0x67B5E19C3B85FE16ULL, 
            0x5D589E88E417C19FULL, 0xC867B6DD5B87B730ULL, 0xE6F2318EEE98AF48ULL, 0xF911621DD52C8C73ULL, 
            0x59491E8D7375AA11ULL, 0x7E5962C6588060E3ULL, 0x8865FEFAAB922205ULL, 0x4810917C97362986ULL, 
            0x50420D89511A6451ULL, 0xC42D76217BCE282DULL, 0x0D61467D081ABD66ULL, 0xA6726F8FC12F2D40ULL, 
            0x8F951E39742B8071ULL, 0x7D8BD403EBCF7680ULL, 0x7B28DF162FC16A96ULL, 0xB2D5C66130D5331BULL, 
            0x8A4E049A78D47B62ULL, 0x38DA4FCF147F8DD6ULL, 0xD3277F9E4C806E17ULL, 0xE86C7E38A9952CB1ULL, 
            0xFE2ADB1B0472C20CULL, 0xCC2F5B7ACEE05CD4ULL, 0x7DB23233E996AF28ULL, 0x68C2289AEECC78A4ULL, 
            0x944783BF68E23C7BULL, 0x96A322377FF3512FULL, 0x5E7E0842D331D074ULL, 0x6FBEED1E0567B548ULL
        },
        {
            0xBB7B2E12C2A4B168ULL, 0x328D21D31B7DE3BEULL, 0x378876672C9EEEDDULL, 0xC1199239A42C7F43ULL, 
            0xA7B14C823E3BFD78ULL, 0x91F0438B42B337DCULL, 0x41D5CB95C05F5F52ULL, 0xC90B3E9066A73553ULL, 
            0x9A54E721221DC1A5ULL, 0x8915C0708C989217ULL, 0xC871B5BB272439C0ULL, 0x6F2E7F3166F2A2D7ULL, 
            0x7E045ACB1AC6C3C8ULL, 0x6A5CEFDF21B1E5A4ULL, 0x18044D40369653D9ULL, 0xABF63E2481A3519FULL, 
            0xBCBDD96BA2C9421BULL, 0xE1CBC97C783CBD5AULL, 0x1CB15C19C35B93BCULL, 0xA1AA1D07CB4D7706ULL, 
            0x42800E23903BB501ULL, 0x6AD917B48027E69FULL, 0xC2D716AB9560D6AFULL, 0xAA29A2AC189E689FULL, 
            0x7F62AC303F0172ABULL, 0x3D9FEFF2B00C5215ULL, 0x5ADB42854CEC3FC9ULL, 0x1538D48F1871820BULL, 
            0xB9E8DA506864BAAEULL, 0x3B8CFF949DB84344ULL, 0x5A847E3D64ABD90CULL, 0x8C2992BFF7D6CB10ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseEConstants = {
    0x00CFA10657C8AF92ULL,
    0xDAF4951DFB35799BULL,
    0x34D9379749E2A1B1ULL,
    0x00CFA10657C8AF92ULL,
    0xDAF4951DFB35799BULL,
    0x34D9379749E2A1B1ULL,
    0xF108889FC3622E8CULL,
    0x0D3B7E3D51F79BD1ULL,
    0xCD,
    0x99,
    0xE6,
    0x24,
    0x05,
    0x0A,
    0xE1,
    0x7E
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseFSalts = {
    {
        {
            0xE3A2F4E6C6B0E2D7ULL, 0xAFB9CF760811C649ULL, 0x0173BB9766B02B08ULL, 0x4160077BF8F7DFCAULL, 
            0xE4487E1C0664B508ULL, 0x1FEB520ACF5548B7ULL, 0x93352C1823799149ULL, 0x65210B5AE72DD968ULL, 
            0xDF166E2E17AF2237ULL, 0xDFCAFFBA9FC500A2ULL, 0x7E6A6FCE9B735175ULL, 0x8725FE2F75A75A3FULL, 
            0x1FAD37F27F6A53ABULL, 0x89D4AFBF3A4829CFULL, 0xAC180E2DDC829EB5ULL, 0xE4F25C42B196A8D4ULL, 
            0x83B018F9C3D42A84ULL, 0x10ADCAF9853F7C77ULL, 0x7A7809DDE25D501FULL, 0x66513C4C6DB8CE17ULL, 
            0x1EB343452FDDD05AULL, 0x65ECB38BBEB43746ULL, 0xBB2F7D7B93FB9F78ULL, 0x2A61BA1E62FD37BAULL, 
            0xAF846275A10A387EULL, 0x3F717B45BF9A9AB9ULL, 0x06F835A0A138A382ULL, 0xE019CBE48C3DFC3CULL, 
            0x72A271C6120B5D9DULL, 0xA8ED311E7D2C19E9ULL, 0x10B9276A066C430CULL, 0x4C3C4B62BC80DBDFULL
        },
        {
            0xB9A65C41A9E63CC8ULL, 0xD5AE1CEE2DFF9DB5ULL, 0xC1BB41C2266C0501ULL, 0x0CF02B4C7FEA5106ULL, 
            0xA24C954C5B87266BULL, 0x90141A81B3A52AA7ULL, 0xB6392CD0E152A446ULL, 0x7B5EA5A1DE9F47F8ULL, 
            0x12FB626006315FE4ULL, 0x02E6B03E3F62AD5DULL, 0x9E9BA3CFD21DC58AULL, 0xA7D2AB05E1BB556FULL, 
            0x7FA2702998A8D3E9ULL, 0x6CFA5560B01D55F0ULL, 0x0DEDD423A9DABA63ULL, 0xE6058216720344F8ULL, 
            0x2030E0AFAB3C13D5ULL, 0xC7DFCDDF0ADAF1D5ULL, 0x8EAF6F42B13D3A65ULL, 0xB5E6700DB3EDC917ULL, 
            0x262339652C821844ULL, 0x94C1FAA9C6C81FF6ULL, 0xC132A2139CA0E245ULL, 0x8963462D4672EB46ULL, 
            0x6E11E8686D781ECAULL, 0x180981740A09D578ULL, 0xCF65A5A7AF7894B8ULL, 0x66F6F95E83E64F18ULL, 
            0x8C6F64A12E085FDAULL, 0x32E30130AD6F0E38ULL, 0x4A95D86464CFC313ULL, 0x4D5AE15E6D564F98ULL
        },
        {
            0xCB1008EFBAEF5B03ULL, 0x6293F9AEBF5888CEULL, 0x2C2FE05A33B50C7DULL, 0xDC6FD858AF0154CEULL, 
            0xA5AEFE420697DB9FULL, 0x7304404B4EA124D9ULL, 0x421A2D632D54CA93ULL, 0x8ED972C7EE4970D9ULL, 
            0xB925181F2DBD1214ULL, 0x00E0400BD15CB57EULL, 0xC6278E8F0818D2ACULL, 0x4CD4A6A9877AEAFCULL, 
            0xA66B53A0B8CCC6E6ULL, 0xC397DD19D6D06431ULL, 0xBD978B4737B8C5C0ULL, 0x2463AECFF00BDD87ULL, 
            0x549E5722F9526821ULL, 0x6CE8490767C8F32CULL, 0xE56015BD3DDE6CAFULL, 0xF6393CF7844C1CB6ULL, 
            0x9E4D5028BFD0126FULL, 0xB26824C1CDDDB51CULL, 0xA9C5091487768B72ULL, 0x0B21A528DDA8F257ULL, 
            0x246C7AD786A878D0ULL, 0x0B6F1AF8E9A3D8A9ULL, 0xA5ACD2D05D1C4A0AULL, 0xB8C9396DD7CB7940ULL, 
            0x92699945471513CDULL, 0x33A30EF6944AFA1FULL, 0x425F0E0E766B12EDULL, 0x388A06CDB295193EULL
        },
        {
            0xA61C58879B25AA36ULL, 0xEC74E0DDC2E8BEA8ULL, 0xD0DFD15A3A2F4432ULL, 0xD9ADB023B31B94CEULL, 
            0xC5FEFB31AFDE0EE2ULL, 0x4AF17620A6042E3EULL, 0xAC2E13EC61C2EBE2ULL, 0x65335725A157BE53ULL, 
            0x6DD4312919062B91ULL, 0xC5B53EA46B8EF9F4ULL, 0x0B3AE6BF1DC39AE1ULL, 0xC55607B7BF851A00ULL, 
            0xD51A55A6EF1F9C46ULL, 0x44562771A0ED62A9ULL, 0x06A047CC1508613BULL, 0xB8F41B8A7FE846D5ULL, 
            0xC9C3F5731FB83795ULL, 0x28C4855C8B71472FULL, 0xAF22DECACDD49960ULL, 0x0C0809E149EB58D4ULL, 
            0x0D53B3E3251D62C1ULL, 0xECF246BA0E2F2965ULL, 0xC11F7D7DFE58BCB1ULL, 0xCDFAAC559F080474ULL, 
            0x54C6EBC2A7185766ULL, 0x8134A7A79E1483CDULL, 0x9B27D19CD8A61B10ULL, 0x35A51EEDF7D53FE0ULL, 
            0xE5BBFB4A09BF13F8ULL, 0x50599B12822E97B5ULL, 0xABACA1ABA613A9F2ULL, 0x839331C1C10DF62BULL
        },
        {
            0xD88166458FD7EBCFULL, 0xA86C095DC8B694D2ULL, 0xF982B4A6AB2F8C82ULL, 0x11FFB6D3F4EE8E91ULL, 
            0x8F569C390BA31BFEULL, 0x18B13974C3A29ED4ULL, 0x0154381017F25119ULL, 0xFBD868E83AADB5E2ULL, 
            0x787FEE76FF207646ULL, 0x1B1514ECBFBA1367ULL, 0x970C42392D93AFC8ULL, 0xB791CFBFC087ED74ULL, 
            0x25A95028C7DFF1B3ULL, 0x433306B65AF5788AULL, 0x5922356CC28BC0BCULL, 0x1FF0E0796538C181ULL, 
            0x2737C3792EFA9896ULL, 0xBB22ED89E8CF6F07ULL, 0x5412EFFABF994D47ULL, 0x2FC5DD9CF18D4ED5ULL, 
            0xF085033E6DB3D1F8ULL, 0x57620AA4192DA79EULL, 0xCF06E12D0B349334ULL, 0xEDFA2DE308951853ULL, 
            0x6EB7EC0C2AC00FFEULL, 0x5E4697C2CE799CE4ULL, 0x6DA41645BBD4B4DFULL, 0xDE21C960B646CD09ULL, 
            0xE0A204E38335EBE5ULL, 0x3C69A646259967FDULL, 0x94BAAC60A591EF81ULL, 0x1FA5F722E5859D54ULL
        },
        {
            0xFB1A807299BF6CB4ULL, 0xB0B709A500946F02ULL, 0xDF3890B04A1EBA26ULL, 0xF645569C058BBCD3ULL, 
            0x90941B14009DA2EDULL, 0x07B29B087C92EE72ULL, 0x2A1A7E4A6B0C7AF5ULL, 0xE635C548E16811A4ULL, 
            0x480881BEE29C9C5BULL, 0x2FC361003CCAD310ULL, 0x6B1C899A411761AAULL, 0x4A1351391C9824E8ULL, 
            0x71AED9E39909F1DBULL, 0xC4DB3A98310261E3ULL, 0x737091A4F98C8EA9ULL, 0x4036F70EDB641954ULL, 
            0x55466E8D72083259ULL, 0xF891A01E447DA12DULL, 0xFFDA5246C13E5FBEULL, 0xD08DD4CB18498EF3ULL, 
            0x29E6EF90FEFC0A4CULL, 0xDB25AB452A7FEC1CULL, 0xEC527FE5045DFFE4ULL, 0xB859E03CD7335B75ULL, 
            0x2037FCAEE3308466ULL, 0xF9ADB43A716D6D5CULL, 0x60D00F213DFF4129ULL, 0xFB8FA556E0FD98D8ULL, 
            0xC990F368E6CA9F38ULL, 0x0CC4E6D25235D7A6ULL, 0x816C2DEB07E7C2BBULL, 0x21BEF43B553D6D93ULL
        }
    },
    {
        {
            0x762FD874938E9B97ULL, 0xAE9BCF0272B84F28ULL, 0x95D74D278BFBE6E0ULL, 0x2B9196B6541F22BDULL, 
            0xEFC086A0577B58C9ULL, 0xEAD0B3413800CB37ULL, 0x963F32DD4AB8D900ULL, 0xB27625E8FD797BA4ULL, 
            0xA4E37FA7820B0D51ULL, 0x81A78358B7476ADCULL, 0x587392C49BD026BEULL, 0x41A26E4C8973F5E3ULL, 
            0x59ED8F082B7CEA0BULL, 0x2D0F3D8B1174A121ULL, 0xCCB6A45D56DEF2BEULL, 0x35A199BB1A6FEA88ULL, 
            0x7851B274A8220957ULL, 0xE3AC0BF59985A382ULL, 0x9CA70B5CB0646237ULL, 0x01615F13953E8B64ULL, 
            0x5D3E9DB614C14DF8ULL, 0x26EDE4CBFE5860F2ULL, 0xE4FE7FA07C07EA27ULL, 0xBAFDD614924AD943ULL, 
            0xB55EFEE4967C2603ULL, 0x54D38112FC192FD4ULL, 0x3017E1DE888ACD4BULL, 0xBCF4B3F98C70EF75ULL, 
            0x5E4E972D76E3AF5CULL, 0x1608B291DBED24A4ULL, 0xA283736249DE51C9ULL, 0x8C829283681FA2D2ULL
        },
        {
            0x5060ABFF4DFD50F8ULL, 0x1BB026CCDBAD3E35ULL, 0x91E98CB59E7C7591ULL, 0x1E51C93CA0C8159CULL, 
            0xACDEC92EC6FE8E1BULL, 0x1D7E194615D1EC3AULL, 0x3495277CBC874DA1ULL, 0x5CCD862E278A9D20ULL, 
            0xF21EB2CCA4321B1EULL, 0x922928B8B42730D7ULL, 0xDAB27B5E46AB042CULL, 0xDC8BDA1F1BFB4643ULL, 
            0x9B9C8847E7EA047FULL, 0x2F59210EC9EEEB41ULL, 0x382954134DD94C3EULL, 0x1363D0D1F112683CULL, 
            0x722083DE81B7A9CEULL, 0xB64B69C363B96E4EULL, 0xBAC4B7456914E829ULL, 0xCAC9E3B6398CE8D2ULL, 
            0x610CDBB9E0363301ULL, 0xCD7C8429A924E1F6ULL, 0xB9B5CC3A5D531331ULL, 0x19617FA667328D6EULL, 
            0x1D93848F9536674FULL, 0x9C9DCD4EFDF3BF92ULL, 0x3FCB41C6DF1B70E9ULL, 0x0DC3CA93FEE450FFULL, 
            0xD44E6F0DF0AF7C92ULL, 0xA45BCD7584585046ULL, 0xCC1909318BFF41B6ULL, 0x6391F161B11CE5D6ULL
        },
        {
            0xCCAAC8361B04477CULL, 0x36D9F788444457ACULL, 0x032CC1ADBCB90771ULL, 0xB8C3D058D613EFB6ULL, 
            0xB22C4783EC09E172ULL, 0x2BADBD35CE56DB7EULL, 0x963C0B0BE74B7F91ULL, 0xC14D8A3C16C7C033ULL, 
            0xEF8AC821089A615AULL, 0xA74A77227D33D238ULL, 0x71F54EE713627D1FULL, 0xC27E6D6FBFC41294ULL, 
            0xA957276DAAF564B3ULL, 0xC82D72C780B6A1D1ULL, 0xE55BC42CF479E8E5ULL, 0xB58D17829B75B79DULL, 
            0xC699FA300E944EF6ULL, 0x5108559F07DDBE09ULL, 0x4AD655F48CB70934ULL, 0x93305C2EAD0E6AD4ULL, 
            0xEFD4934E5E0BEEE3ULL, 0xF88D894EE310B1E5ULL, 0x720A3666D676CA7CULL, 0x97D3EF6198ACBC3CULL, 
            0xB5A1098D430DE1CCULL, 0x71047D5BC30910DCULL, 0xEDD7185167E6F728ULL, 0xCF5092D726F199ABULL, 
            0x9635E1DF5C80F50DULL, 0x9E7E196714CEEF92ULL, 0xB71CCE2A4576358EULL, 0x51FCB49040BF72A3ULL
        },
        {
            0x9E4655F0A67232A3ULL, 0x15607F3FA02D5BE0ULL, 0x5B8075A226B58889ULL, 0x3E19CF96644A6067ULL, 
            0xB2FA05E61C4FD58AULL, 0xFDB1EB46B2D5EEAAULL, 0x7C43C83946A7E395ULL, 0x30A0079A0A2743B7ULL, 
            0x04012459E9956906ULL, 0x7086F147641CC617ULL, 0x7B00F6EB55E9C989ULL, 0xC1AEA5F366189338ULL, 
            0xFA2C6E3F4DA43984ULL, 0xAEF370BB629DEDA4ULL, 0xF8F44FE0E38CD3D4ULL, 0x439F26FED597627CULL, 
            0x7F0B60053AE5CABDULL, 0xC5FFB21F053E9013ULL, 0x3AFC0C206B1AB7B6ULL, 0x4224281D3683B7E3ULL, 
            0xC7865D9163ACBB9FULL, 0x6E1F339F98F72E19ULL, 0x976EAB66A118D3DEULL, 0x70B4BDE0D480481BULL, 
            0xD4658DF6B86EB612ULL, 0x5C0561919EDC81D6ULL, 0xB0271DE00CE2BD9DULL, 0x9666D67C72337BFDULL, 
            0x10328D2BD7196EBAULL, 0xC9FC280CACB2A7B7ULL, 0x73C65E28E625FFD3ULL, 0xFFAE50F8AC245640ULL
        },
        {
            0x0D3084DCBBD7145FULL, 0xD1975A0EA80129EDULL, 0xC4FF189092361F02ULL, 0x29A915DA570ECD73ULL, 
            0x190BB035C0F68EE7ULL, 0x4AA88F3FFC973236ULL, 0x9DBAE82DB9068E4BULL, 0x24939A3855EA1BB5ULL, 
            0xA9367E18314748F9ULL, 0xF8A18A4681C3DC11ULL, 0xCBA0675E4CA19ED6ULL, 0xAF53B3166C93599EULL, 
            0x571F934486AB5709ULL, 0x86CD8DE6A8906D3BULL, 0x584C41178926F6A1ULL, 0x940A37599CDFDA13ULL, 
            0x7B42A9FC6F1F83A1ULL, 0x6E77B270DBF8423BULL, 0x9681E8A28A5734BEULL, 0xE5822F993986600CULL, 
            0x972FD312871A5954ULL, 0x733C856C9AD701B1ULL, 0xDB913DFD2C25C39DULL, 0xE71DFA7B74701D1CULL, 
            0x5440BBEB88DE8568ULL, 0x84E969F31D51C877ULL, 0x1503B82E79DC0A75ULL, 0x1E34E6D89CA18AECULL, 
            0xDF6EB5C39B53D030ULL, 0x2EEA5E01A4457B58ULL, 0x1E964C1F588079EFULL, 0xD7F76C12B654D29BULL
        },
        {
            0x3A65B105982F02B4ULL, 0x1583FA66706472C8ULL, 0x52E3BCDD137BB44AULL, 0xC86E3534D7B839D1ULL, 
            0x7D1F0399EAEC3496ULL, 0xE6A37F80FD5E6BD1ULL, 0x38E9991CC7CFD72EULL, 0xDEF4B97760A3AE1CULL, 
            0xAE9A3A54706E374AULL, 0x794AAAAB7B7AA51DULL, 0xDDD7891B3F612F4DULL, 0xDCFE1195860930F9ULL, 
            0xE9E4D9194BDA81E5ULL, 0x12F17FF4C72E1268ULL, 0x862D90ABA582CE0CULL, 0x5047B75EA952C1F8ULL, 
            0xA4AEA57CA5A20359ULL, 0xB8907D0840DCDCC7ULL, 0x456ACB53D797349EULL, 0x9DE041561A7BCAABULL, 
            0x6490F848693CAC72ULL, 0xABF594B369F2ACF7ULL, 0x4B3C706D4A0FFFE7ULL, 0xBB1B6C2F79A53914ULL, 
            0xB95F70D957B54419ULL, 0x79979453B2EB5258ULL, 0x57A9865E6F583ED4ULL, 0xCC81F626054B506FULL, 
            0xA9B6F58C9CBADF6DULL, 0x03026082F09A99D2ULL, 0x33B0C3D76B9843CBULL, 0x026C2F8DE0055862ULL
        }
    },
    {
        {
            0x13BB5039E8BBF04DULL, 0x7563A7A7F44A3800ULL, 0x40A4334C18BF7301ULL, 0xF32A7492EAE48EF4ULL, 
            0xF09C0D56F5B7DBCCULL, 0x67F89050BE8E5D44ULL, 0xA85ECD2B34598B4EULL, 0x14F2080F6A01FF66ULL, 
            0xFB98BC44DEF69752ULL, 0x3A79F35FD4B8FB35ULL, 0x40C8321469D31C72ULL, 0xD38B12C37501FD24ULL, 
            0x82AD1AD4F15A54C6ULL, 0xB90AB26CD19451DBULL, 0xCA78130A4E4043BAULL, 0xC9548ADD612E427CULL, 
            0x6D8E62E720FC6667ULL, 0xC426A83E8987DA2CULL, 0x8A8D95440E58700EULL, 0x6293D84B0A523230ULL, 
            0xB14BA11B3115390FULL, 0x07976117B56F4F51ULL, 0x920EA73AD784DB1DULL, 0xC2013211516E2FEBULL, 
            0x0EAA266747675056ULL, 0xEB2F5DABB2E266FDULL, 0x63BB66EF27EF791FULL, 0xEA7629337741722BULL, 
            0xFD68BF1850F2BCB1ULL, 0x117DD931ACE47507ULL, 0xCC482AF98E151134ULL, 0xF9EDE7698412A8D4ULL
        },
        {
            0xF4B48E5B1D4CBB10ULL, 0xD26DB5F6D4261287ULL, 0x6A686724F9BBB84DULL, 0x306074FAFEF2051AULL, 
            0x5E4AD442F9295669ULL, 0x1F231224CFC984CBULL, 0x4F6DED8EB9F079EBULL, 0x2346ADE5F628E53EULL, 
            0x4327C76F0727952CULL, 0xF8CD72A9B13F4724ULL, 0xCBA48BF7B08138F7ULL, 0x2E9134C3373F558EULL, 
            0xA156F61F384D5CF6ULL, 0xDCD95D47527FFB4FULL, 0xC7AB8E123B7B7648ULL, 0xCACC2288ECA57A97ULL, 
            0x85144B7665589B4FULL, 0x50D39D1C16115DBFULL, 0x1163035E3729704FULL, 0x2446E55EBAB0C2F9ULL, 
            0x23D31CCAE5B101C5ULL, 0x2E37C73F92FEA8D0ULL, 0x1F6E79DE18CD5B03ULL, 0x14E8E9CAC3809603ULL, 
            0xDD9CC5058CE579D9ULL, 0x935F8924FA7D6104ULL, 0xDE44D1D42BE34E48ULL, 0xAE608C24105E7118ULL, 
            0x2FDB10E3CDC5920BULL, 0x688F5646828570C4ULL, 0x494DEE06ADE4EEBDULL, 0x75D25553A23DA6FDULL
        },
        {
            0x225A6987D98E196EULL, 0xED5B5BF63A413F5DULL, 0xB63C8F380B9BB4EEULL, 0x24307A8CD75CBEAAULL, 
            0x265CF464972F851AULL, 0x086E962CF0B01CEDULL, 0x1E209839D90086A3ULL, 0xE5F0ECF8219C29ECULL, 
            0x5DD897668E26254BULL, 0xA527C571AB31E0AEULL, 0x45ADC6FAE506D130ULL, 0x4C090707B7625535ULL, 
            0xDF8D59C65DCE4376ULL, 0x9E5D2B9F1D01D54AULL, 0x8238D0B626442D4FULL, 0x56C5CF67F7144C3BULL, 
            0x9361D86E18529891ULL, 0x518C8BDC98F4FFA3ULL, 0x5800FE70CCCE9713ULL, 0xE7C3E80C62C54185ULL, 
            0xF1CF4A3786DF2ABEULL, 0x810005B7E2450725ULL, 0xA79923C3DEA5F0A9ULL, 0x40B24CF5A75FB8A4ULL, 
            0x7E770EA74739027EULL, 0xD44BC755DA32C190ULL, 0xD74931A12FC4769DULL, 0x73265DC5B0F2CCBEULL, 
            0x9D55C78A2ED33920ULL, 0x2FA409D5F3B26BD0ULL, 0x3260FF754FE0506BULL, 0x6CE0C0D5D7D20699ULL
        },
        {
            0xBDD6170BDC54109FULL, 0xC4CFF4866AD425E1ULL, 0x6A91B6F44225B943ULL, 0xD0A10F29679738E0ULL, 
            0x9A3489D2B4F7E235ULL, 0xC284D791B401413DULL, 0x16F3A1CBC0E9CDC4ULL, 0x4CD5A93A14B432EBULL, 
            0x170DD826BF74E40DULL, 0xFF0BDFFE8F6FD278ULL, 0xEDCEAD4A43FDFA32ULL, 0xC5D23410A1960D90ULL, 
            0x4588C53245FAD42CULL, 0x944ACE06BEF8E11BULL, 0xA2CE3BACDBF97B11ULL, 0xDDAD86C2677879C4ULL, 
            0x6B5160F51398FD6FULL, 0x5C49FAEC2F970880ULL, 0x9B6552DB046FE144ULL, 0x1823B65A226A2D2CULL, 
            0x3DCD71C85C611511ULL, 0x22867BB103A4F86FULL, 0x0B7AE534000C75BCULL, 0x5C8AE08E11C04631ULL, 
            0x87E02E75817CDC48ULL, 0x2648CE1CFDD5BEF2ULL, 0xB02D0C0AB00B8FF4ULL, 0xC25ED8C1DB35D61CULL, 
            0xFD4348969088759FULL, 0x46BBD091C046D135ULL, 0x024A37DBE92675B8ULL, 0x96549706F985CA06ULL
        },
        {
            0x66067A14941FD9E9ULL, 0xE74C5329FE97D961ULL, 0xE94B4025A194D5E0ULL, 0xB4AF1F294C4EC8D9ULL, 
            0xAA855BC8E0379A12ULL, 0x103C9A1554E130DBULL, 0x22CF5BB6C36DFDBFULL, 0xE4AF9D62CFE4A7E6ULL, 
            0x84AED65CBAB4CD37ULL, 0x03D0610504E0E0BBULL, 0xCA1D72F71B525D97ULL, 0x9B8F5BE6AB176A88ULL, 
            0x10D982533F1BFCB9ULL, 0x60748D6C9AF20FD5ULL, 0xCA8BD2FF680277C2ULL, 0x832B2B333ECF87CDULL, 
            0x9DD7015D6DF91532ULL, 0x08FA85F0B7FAD17EULL, 0xE7047AAF2EFA6A2EULL, 0x7A72185887E6ACEFULL, 
            0x0B8502AEA9C8A9DAULL, 0x10F17628CE57952FULL, 0x0C2E5C40ABE2DDBDULL, 0xE2C18F63C84BC8DBULL, 
            0xCECBE79CB409EADDULL, 0xA919B559B1D037C9ULL, 0x688204CB63531FE2ULL, 0x82308A0B65B13914ULL, 
            0xB18D8FB7BF66F582ULL, 0xDCA5B48163B686FDULL, 0x962E184942ECB33FULL, 0x4880975E49A405F2ULL
        },
        {
            0xBBAAAFCDCEF46710ULL, 0x9DC0E50BCAD1FCF0ULL, 0x9A5A7CBA47838F0AULL, 0x592E1D887F6B7F93ULL, 
            0xF0AE58DCA3D12591ULL, 0x023021B1550B7640ULL, 0xEBDD7DCDEDC97F6EULL, 0x642429726932C41FULL, 
            0xABFEE353309F9773ULL, 0xFA1C8039E94AB61FULL, 0xA1034052BFF46A73ULL, 0x340C2C677BC73F5AULL, 
            0xC648852709349399ULL, 0x195ED57713FF3D50ULL, 0x8D50376E49AE7D77ULL, 0x314DC542E02C3F48ULL, 
            0xE033E6974CB5519BULL, 0x8469B812BC0CF9B0ULL, 0xAC2BB0FE7996B3DBULL, 0x4446504A39ADDD3CULL, 
            0xFA52FC3C6613DCF9ULL, 0x133C30C5A27BE316ULL, 0x592B6BBBA2F00AEBULL, 0xCB63D0EB8B6D2AA5ULL, 
            0x0F993CA4B9C79069ULL, 0x39F1F1B19DF8CA52ULL, 0xAE952EEF0CFB5BF0ULL, 0x5209E79663B90781ULL, 
            0x3C8DC33F8247216EULL, 0x3443D89036A26A9BULL, 0x11B383EA6AF49E9AULL, 0x97951C39AA8128ABULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseFConstants = {
    0x352ED28341D60249ULL,
    0x9AEA357D52A19888ULL,
    0x05CAB0D0E43A0307ULL,
    0x352ED28341D60249ULL,
    0x9AEA357D52A19888ULL,
    0x05CAB0D0E43A0307ULL,
    0xC3B5DDCC2F2C9DCBULL,
    0x9E6659D3267329E0ULL,
    0x25,
    0x17,
    0xC3,
    0x55,
    0xB9,
    0x82,
    0x4C,
    0x19
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseGSalts = {
    {
        {
            0xB27A82D829848243ULL, 0xE239B2CBF58AA2C1ULL, 0x33885D77753EA11BULL, 0xD613220E1CC0D90EULL, 
            0x6C1B9C2164EADFC3ULL, 0xBD8A85FA44F6D3A1ULL, 0xB6FE7CDB8802E2E1ULL, 0x1C8EF421558FBA9FULL, 
            0x015B6C946DDE7410ULL, 0x07A59E456456CEE5ULL, 0xE7C94F12990DDFD6ULL, 0x250E7FD24ED21FCFULL, 
            0xCED21B99258AF9C8ULL, 0x1770C7EA76C086FEULL, 0x3F12DC1AEDBA5443ULL, 0xB8172D2BD3CA7C43ULL, 
            0x59E401185C34C5BFULL, 0x05656C5311DEE8C1ULL, 0x0EB6BA43C5557C57ULL, 0xCEE15C3AF314948AULL, 
            0x47AB2DE857C7E944ULL, 0xCA57B047B68BECA8ULL, 0x8DAAE94E0C5B652EULL, 0xE104D25AB2E95251ULL, 
            0xE8E6C058B555402BULL, 0xD3D893F0D338D2B2ULL, 0x9F34668E0EC657F6ULL, 0x9D65E5F7F44DE7CAULL, 
            0x309CA3B2C3EF8F8FULL, 0x5C91DFC22D390AE1ULL, 0x9A3D16BBF1A35C45ULL, 0xC1CEDB80BCB119C2ULL
        },
        {
            0x6A716F55D68AE6E2ULL, 0xE273D43C07D7D8E3ULL, 0x5625D76232DE205EULL, 0x922D22B4CD57BA0DULL, 
            0xB532B29FE53F474DULL, 0x0A02B2D6C999F0F3ULL, 0x4FF73A3AA83B5CA0ULL, 0x0950156AFB19AF07ULL, 
            0x665A0130283A896FULL, 0xF8C4967530A5F81BULL, 0xBF5450C2E898C1E9ULL, 0x5F51BFC0FBF7B921ULL, 
            0x1442FF6C6E265497ULL, 0x369C4E4AF0644063ULL, 0x6C163688259B4658ULL, 0xDEC6012CF39734F7ULL, 
            0x5A6D42176ABDC64EULL, 0x012CA82BF2F5BC56ULL, 0x01F7E93FF8F19CECULL, 0xCF1DFB11369528B3ULL, 
            0x5696C2F511C007E5ULL, 0x065541C218CD7451ULL, 0x9E268BA358DF1593ULL, 0x1F25E90E7A1964E0ULL, 
            0x5B049F87CB261A02ULL, 0x0CEE910477F1B152ULL, 0x4789549C8FF9B2D3ULL, 0x0F6C9325B2EECDB8ULL, 
            0x78CA75CCBD1AD8E1ULL, 0xBFDDFB0369F08A81ULL, 0x2ABF9EC5318030EEULL, 0x5A8715EC1E01DFA5ULL
        },
        {
            0xB5B399D9C1824CD8ULL, 0x77DF3C3F7A666C57ULL, 0x19285C6A42311006ULL, 0x4F3B8A9582E0320FULL, 
            0x1A0AAAC3B2BD37E5ULL, 0xB469FE7BBCC0C024ULL, 0x72D428A4BFD850BDULL, 0x158497F32BA5F72BULL, 
            0x552E590768CB9892ULL, 0xE5D5FE05CA6198FBULL, 0x16B4205F26DF27FFULL, 0xD8FD8303C37C8385ULL, 
            0xA89EDC8F08576F57ULL, 0x76FE56573A7E4B01ULL, 0x86C088AEEAD5A7FDULL, 0xB15074DBC17BC0ADULL, 
            0xCD224033165DB1F7ULL, 0x1E5FA2E479087FDEULL, 0x705CD3160A0CB08FULL, 0xC65ACD05BD195D21ULL, 
            0xA5685AA6A3C21D5CULL, 0x3E3CA7597686EEAAULL, 0xBC3E05B6AD3D1188ULL, 0x6609754810DA71F9ULL, 
            0xC6B0039602D8624DULL, 0x249D8CB37A59C559ULL, 0xEF473E506D0F98F8ULL, 0x87ADE9C67CA48CE0ULL, 
            0x2D041CE8643A0B46ULL, 0x460ECD81333B16BBULL, 0xE85B0B200DCA03CEULL, 0xE0C83E71215FD28BULL
        },
        {
            0xEB9BC32BBD92B651ULL, 0xA11BAF55B39E3845ULL, 0x611B71C0EB4DC927ULL, 0x370A2E8DD5D08648ULL, 
            0xAD1A33EAD20156A5ULL, 0x264909A80E276641ULL, 0x69007C8EA87861ABULL, 0xD6AA1C519F202D72ULL, 
            0x978E92478EBCA4A1ULL, 0x1845DF83716AABC3ULL, 0x0D9691B27A856E4AULL, 0x4E9AFD056FC28F56ULL, 
            0xA4397D2F5F8FF983ULL, 0x2641D4150079D9D0ULL, 0x332AC4B80147C438ULL, 0xE48DD21C6E43FED2ULL, 
            0xF1D9B2EE646A34BEULL, 0x532C6EA3A43B8560ULL, 0x827B09D310FD6272ULL, 0x44D2CE5E64FEA435ULL, 
            0x26AA07F321E47A7EULL, 0x56474946A568ABE9ULL, 0x1CBC565868DFE651ULL, 0x5EE549FA6633DE90ULL, 
            0x5675758B444EC4C7ULL, 0xD220F7334CE8C5F2ULL, 0xE239C06357BF886EULL, 0x165ECB12E6353BEFULL, 
            0x4DA8B39294B3ADFCULL, 0x1A0CD6E69AF1ECB5ULL, 0x2B3AE005E2D57588ULL, 0xB59E8CCA1ACF22CDULL
        },
        {
            0x6AB5EDEEDC256E74ULL, 0x349A68AE94EC9FF4ULL, 0x8439FB867127195CULL, 0x392825526E00DDD6ULL, 
            0x7E02A1792271FFFFULL, 0xA93854B7549B72B1ULL, 0xE9155AD4716E2EA3ULL, 0xB67DB4B993B3D514ULL, 
            0xE3D5F59A61EEC0CAULL, 0xC6818C1F93A9090FULL, 0x187663692063A1B2ULL, 0xC5A362237C178AE6ULL, 
            0x14FCE3118FB605ABULL, 0x891D4DA80AF6EF78ULL, 0x109A4371BE48F228ULL, 0x385FB2443F76E9F9ULL, 
            0x04985BA01712ECF6ULL, 0x66A81D8E265F9B14ULL, 0x9B8C88EDF2F8B9B1ULL, 0x001A715867548D01ULL, 
            0xCF72D1DB0B972CBAULL, 0xA896E671DC372686ULL, 0x6A37EF42105ACC60ULL, 0xDE22159C4826E4EEULL, 
            0xD42934B52EB82746ULL, 0x800046C44FAC4443ULL, 0x88358029399E3FA4ULL, 0x85BD96F484469156ULL, 
            0xF5576AACBE79094DULL, 0x4AFF62869C0573E1ULL, 0x9A599A751776A120ULL, 0xE46A5445F657B7E8ULL
        },
        {
            0x4582D7D946FE43CBULL, 0x9E58CB06341B8586ULL, 0x168C3D0CCCE2D050ULL, 0xF66FC289EBD8E6C8ULL, 
            0x3C37C7FB3AE4BE9DULL, 0xDB43E00F795FB80CULL, 0xF23414F9612810BEULL, 0xF0A5A2A3FED77AA5ULL, 
            0xB47C38F967BBBE31ULL, 0x603F3D62FE74E5F0ULL, 0xD525F5771C81C709ULL, 0x9E3660EE23860DB3ULL, 
            0x779A585A46327721ULL, 0x842D8CEAA938E45DULL, 0xDF0040EDE1A0287BULL, 0xAED9388874D7C321ULL, 
            0xE5FA9A4FAE16EC1FULL, 0xEC144340E6ED9964ULL, 0xF17F00D53046011EULL, 0x958951C89FCB9590ULL, 
            0xEAD8C2BF8A73BF59ULL, 0x3B99D766046DAA04ULL, 0x2782C56FAB744214ULL, 0x18E6949348693B1AULL, 
            0x1B6127F407D2F77CULL, 0xCDDC71C332DA60A7ULL, 0xAB586FEB6F1DA810ULL, 0x56575963389C5454ULL, 
            0xC04C31714B88A651ULL, 0x6F7C16242780BAB8ULL, 0xEEB166FC63EE6209ULL, 0x23075B8ADEA1B283ULL
        }
    },
    {
        {
            0xD4BA4A741DB7B370ULL, 0xB994BE6206D2F04DULL, 0xC9A7147352AFAACDULL, 0xCAB9C330DF2E7A47ULL, 
            0x89CB4D59BC679F93ULL, 0x127CF37245DEAF3EULL, 0x626CAF185AE75263ULL, 0x6E3BBF46BB71B8C7ULL, 
            0x9340BA7ABF03CD7FULL, 0xA2BBAE22F6BEFDD2ULL, 0x0DD4A502A306029CULL, 0x37633DC6BBA0B1DEULL, 
            0xDC88B8B15597ABE9ULL, 0x034EF38FA8CCC6E5ULL, 0x2AA551A201ACBEB7ULL, 0x0DC71731931FC09CULL, 
            0xCCF40C784A9AD3A8ULL, 0x2DA18B8676066A43ULL, 0x2A5F0B3022E119C5ULL, 0xD5A8CB55E86C040AULL, 
            0x87495E5B2FB44DF1ULL, 0x313A8A4176B40AE6ULL, 0x20CF94BBDD7947DEULL, 0x2203888D764C2D6DULL, 
            0xDD8EC7BBD0477D89ULL, 0x6AA2D58DD203DCCFULL, 0xC12ABEFCB8D82023ULL, 0x88DC0AB75CA69147ULL, 
            0x76649EB6CDF6F58CULL, 0x49FF9325BA07063CULL, 0x41A7624EE7E9C8E9ULL, 0xF971D3BD7617DD41ULL
        },
        {
            0x7BC1A67417B1D3B7ULL, 0xBB07483642CC7C50ULL, 0xB8BF6A437726F06FULL, 0xB95D5CEEA067AF9AULL, 
            0x52E632628614FDA4ULL, 0xCA3874E2C4385C11ULL, 0xC141D1061E4D8F29ULL, 0x3ECB609198D0D2DFULL, 
            0x9B3FB2D2D90A3C69ULL, 0x9AD725240C6776D0ULL, 0x10A3BA6CAA18191BULL, 0xF77401DBC9AF9715ULL, 
            0xAE08F1DBBA6242EFULL, 0xD4060E274E439471ULL, 0x3A6CB819E169228AULL, 0x66FF82CDAC645A2DULL, 
            0x99C3BAC241877802ULL, 0x4606887407CB9773ULL, 0xC934286D58B77EB3ULL, 0x3C700B9660EE3D11ULL, 
            0x798E8C354C36380BULL, 0x0F6D30A7B79BC588ULL, 0x91D45D5A60ADC9ACULL, 0x3845BB5D0E05BA17ULL, 
            0xD637A0917CD135E7ULL, 0xD586AEC20630BE7AULL, 0xBD03DC7AD5E7C3D5ULL, 0xD2EF32921656571DULL, 
            0x0FBA9F4BE984A509ULL, 0xDCD07D81A3BE1180ULL, 0xE2D9594EBE20BC9DULL, 0x0963021B4D18CE9DULL
        },
        {
            0x813B54D6B75A39FAULL, 0xD77C63B8895ACC35ULL, 0x5FDEB329294012E4ULL, 0x2943B61166F68521ULL, 
            0x82AE397B2E8BDBF0ULL, 0xC48E4214E6C1BE9EULL, 0xB539464D97CF6518ULL, 0x599E0D0596809C62ULL, 
            0xD273DB4BBD59422CULL, 0xBB710D167DE89FD7ULL, 0x96B88EECFF11FEAAULL, 0x3AEDC88C889BABAEULL, 
            0x8F441F55845E83E8ULL, 0xD03281A84E963796ULL, 0xFD48745B27E09D65ULL, 0xAF37D61BFD0A59BDULL, 
            0x4D060C11EFBA1494ULL, 0x5D5E0742C843F677ULL, 0xBC5BC1A1DE1E676CULL, 0x90E814A8B401CEB9ULL, 
            0x4802B9BFBB3B7C5AULL, 0x45C83B8E5C74DC37ULL, 0xAE2E75AC316E1E29ULL, 0x8DAB1F27E410F866ULL, 
            0x3AF71158B4808B0AULL, 0x777CAB056691BAA3ULL, 0x438589FF23A7EDC3ULL, 0xFED108F41A2275FDULL, 
            0xFF4CDEE3DD1E1BA1ULL, 0x82D83FDD6B0D5C07ULL, 0x072AE7B66A9B8116ULL, 0x8AB175D6F12347EBULL
        },
        {
            0x6F3B4BDD6F49C24BULL, 0x7D87599605B1AEE6ULL, 0x103C9970A4A578DBULL, 0xA92CA316F22C514EULL, 
            0x0AA1F58AF6100711ULL, 0x28A6CE6724CA4439ULL, 0xA4C5A3C28CE88499ULL, 0x64549AEFE8DAF602ULL, 
            0xDC52480E8F458954ULL, 0xB9F5DBCE6FE6159BULL, 0x40A690B47784414CULL, 0xD9D8CDF4CFB1E6C9ULL, 
            0xF08E7D94D27BF3D2ULL, 0x980DCA40E0858481ULL, 0xCCEAAACEA26379BAULL, 0x13070357BDAE78A9ULL, 
            0x4B059F7F5D53B331ULL, 0xE16FA45F3E168800ULL, 0x2C0200830677CA9DULL, 0xD449A46D40FCA50DULL, 
            0xCCB88F07448E02E9ULL, 0x266AECDF9B87653CULL, 0xE62EF904C5E3FDE9ULL, 0x90E7AC52713A0EA6ULL, 
            0xC60D210D3B39A8F8ULL, 0x9063C223B03EDD21ULL, 0x448ECCA732786FEDULL, 0xBFC674B4CFAC5CFFULL, 
            0xAA3CF14611A36999ULL, 0x0A28E6456371A3AEULL, 0xFCC33C24EC593FE1ULL, 0xF4EBD941ABF6BD81ULL
        },
        {
            0xFC467341B0BAA358ULL, 0x25BFF3E087F9AA6AULL, 0x1606504E4775C206ULL, 0x233A92FD01BA6797ULL, 
            0xEF8ECD76B68A00D9ULL, 0x3BB39A267CDD33E5ULL, 0xB95AA5E81764459EULL, 0xB75488E74ED860C9ULL, 
            0xB0C3B1372B74DD52ULL, 0x71B22FB8BB93004BULL, 0x94C81C1619F84EB7ULL, 0x7EC2090E04115BB4ULL, 
            0x4A1DE4A2B6CED742ULL, 0x2176532D23E16D4FULL, 0xB6B61107D5190D41ULL, 0x3DEACA714DA4D74DULL, 
            0xF79B0D547B532E6BULL, 0xDD6D6A3DC3A3A21AULL, 0xDD64F7B9D2571DFBULL, 0xB8E363DE656B0F3DULL, 
            0x5B71863E4AF869FEULL, 0x9B925E9538646E39ULL, 0x3C4BD862F77C3A38ULL, 0xA9F84C4C733628D2ULL, 
            0x6F462DF867FDB4A3ULL, 0x9BC423D135A0CC2AULL, 0x9EA296A823F282F4ULL, 0x6CA5E42E8A4AFA5FULL, 
            0x76E6E17E44273122ULL, 0xE2F6F7C13AD2008DULL, 0x8C6E80675D7F20C4ULL, 0xF8CBFFECECD7BDAAULL
        },
        {
            0x2D97090BB975A6EBULL, 0x3B9B955CA58217FEULL, 0xEE1A2931A13E1481ULL, 0x23B8CF1228EAFA96ULL, 
            0x829F752660589582ULL, 0x87C3ED69439C6C21ULL, 0xB2684445DE0543E8ULL, 0xEA1C15B4993D3C4CULL, 
            0xC5ACD2C563E99295ULL, 0xA6DF92474BEFF870ULL, 0x154B044A63FB47ABULL, 0x841850945E09932EULL, 
            0x27E4CAD323BB9747ULL, 0xE2A8C39812E34436ULL, 0xDAEF36B9E22F6171ULL, 0xC9A1BCA0EA614825ULL, 
            0x69AE3934CE23F789ULL, 0xB521FBCC3347821AULL, 0x5E7F2FB395E3DFF8ULL, 0x1C86300603D31228ULL, 
            0xF354C40D52008A0BULL, 0x154BE028706A3195ULL, 0x966CE32AAFC93594ULL, 0x708FEFB12D22C6E0ULL, 
            0x98704631C68C5746ULL, 0xB3C81EFE23DE08C8ULL, 0xC0B119AEC80914CDULL, 0xCB015AA0A06F80CDULL, 
            0x57306E4EA3375A3FULL, 0x4E5A2AC714042CA6ULL, 0x2536F72A8313D082ULL, 0xC858E29FC9FA71B7ULL
        }
    },
    {
        {
            0xC06674E55F990B5AULL, 0xFCF558F98718E36BULL, 0xA24E5C3F6F73D059ULL, 0xF8E27D69F13D2835ULL, 
            0xFC34D358D7362254ULL, 0x55B7E10B8DF0E257ULL, 0xE6180AAE5B8B4804ULL, 0xF6A7B62075CB2600ULL, 
            0x91161118A7C26EA0ULL, 0xC8A84323E3D195A2ULL, 0x4704C0B10E0587E8ULL, 0xE3B01CB0D01B6E3AULL, 
            0x168CBBE26B4D57A7ULL, 0xF13CB286450D09F5ULL, 0x7A3857AA880A0B29ULL, 0x246740241B565E3BULL, 
            0x9338F14D9FC742ECULL, 0xDCC9697C5C554169ULL, 0xAB71B52930882FFBULL, 0xFFF697197DA2D394ULL, 
            0x5454653542F6D417ULL, 0x046F4B93AEF5BB16ULL, 0x1C6F99F489DBEE73ULL, 0xEE2EFF73AF1F2FD9ULL, 
            0x416E63E1FC5A3CE0ULL, 0x678D880382D5041EULL, 0xC46090B919403880ULL, 0x4CA8CDF4D20E3BE7ULL, 
            0xCD549AEE00745DF4ULL, 0x982C043A19114F4AULL, 0x562C7F0CE9076BEFULL, 0x53299F28943FDFA0ULL
        },
        {
            0x972BAF30780A98ADULL, 0xD3DFA6164614B7A0ULL, 0xC219086BA3423F36ULL, 0x2262FF17940C0F38ULL, 
            0xA23BD8B56B28E33BULL, 0x15F4460D0768954EULL, 0xA779B5DBA54EA85DULL, 0x4254BE0ADDF0E3DFULL, 
            0x60C89668BD783A11ULL, 0x7DB213DF7305B342ULL, 0x4B02CAC75AD60A31ULL, 0x76609B38F4F05D47ULL, 
            0xBA1889841828C8BBULL, 0xCF94649FA8C69B08ULL, 0xA513425A6A232DB0ULL, 0xA6CAECAD6E82C787ULL, 
            0x5F803D2173E538FEULL, 0x78D08BA9BF6C77D0ULL, 0x69D865424E7703D3ULL, 0x3B5D0300214DB577ULL, 
            0xE148D00380DE9B38ULL, 0x9BDE4504D4D6075AULL, 0x82AEC2A143A20DCEULL, 0x20003B76737DFB03ULL, 
            0x6DF030C4756D4FCCULL, 0xB19C4572A1BC04DDULL, 0xD556BB9473E8C6D5ULL, 0x24F62D88F1D30C3FULL, 
            0x54D966764767E39BULL, 0x05E28AE39CFA41E0ULL, 0xA7A02B869D4B671CULL, 0xE17F89E22FBEF241ULL
        },
        {
            0xA9CF09940F294D31ULL, 0xFEF721B992526C84ULL, 0x683F359C6C131EE5ULL, 0xCE3B2CA0D4AAC651ULL, 
            0x969A09B1F44AFE2AULL, 0xB6DCF1D0E3289F9AULL, 0x96020A9B9A3FE180ULL, 0xA7B92AE5A2366A41ULL, 
            0xE5E83BE2EFEE7B9EULL, 0x9ED38B3B30DE6F0EULL, 0xD3233EBE713AD9E2ULL, 0x3AC930D073E310A2ULL, 
            0x95ABC8A6FBEBC9C6ULL, 0x6AA4FBD99B94AB1DULL, 0x1104DCA26DFAC0B2ULL, 0xB2D4332B72B98EA8ULL, 
            0x5ED82F66FA7A7EC5ULL, 0x3BB9AE45132FED6BULL, 0xF87AD68DDC090548ULL, 0x57660B079D43E0C6ULL, 
            0x347D885A92ABD1E4ULL, 0x3770F5D616E0A573ULL, 0x7CCE29A85790EBD0ULL, 0x67C33BFCB3AED7BCULL, 
            0xA4C17330B1A8F2A5ULL, 0x200732FD37D1E666ULL, 0x8C95F844F40642C1ULL, 0x16DE4D9B8A95AEF8ULL, 
            0x8BEDDC9686BA4035ULL, 0x35B1C1098E7DB423ULL, 0x20ED0F666C939FF4ULL, 0xDFDC1C4D6A17CEC2ULL
        },
        {
            0xC9367216E8CD6692ULL, 0x1DAA0F5C598C3EEBULL, 0x4D6D751D934342E4ULL, 0x05B2F6782C87734EULL, 
            0xEE588AF991AD6349ULL, 0x7FDA687096F8D404ULL, 0x4AB292E50BD30C83ULL, 0xC13ECA331171C18BULL, 
            0xA7B529131434628AULL, 0x1E90FBBAFC330882ULL, 0x5263975D18F8147CULL, 0xDAE040F11CF01BFBULL, 
            0x192067B061EBE936ULL, 0xEA2F60D3BA21BC9EULL, 0xEBDDEE989BF80D03ULL, 0x50106BAA5787F8DCULL, 
            0x37721387003EF193ULL, 0x1C6A6D0E5A16608FULL, 0x81A042DC79FF8B5DULL, 0x12C44F8B95F83D62ULL, 
            0x4F0177AD4C0D1A15ULL, 0x42D464407B302517ULL, 0xC8B18D91FE650BB8ULL, 0x44D931E752FD0712ULL, 
            0x61428DD904FAC97EULL, 0xD7055B6E13ACFB40ULL, 0x58A100C105B8581CULL, 0xDA761AAA1C76849AULL, 
            0xFB29DCA734F245D8ULL, 0xA97F0396E4B3A5A7ULL, 0x551A9BC8646F80BAULL, 0x8FDBB7905E28AF53ULL
        },
        {
            0x7129F3E8185D2D43ULL, 0x79813343EBD8B5EEULL, 0xC02747220FE5A5FEULL, 0xFA2BBF137C7FC63DULL, 
            0x29E4CBB07D339E1DULL, 0xAED4101834E14611ULL, 0x68AACCA72CED93A8ULL, 0x2560EDB485BABBDFULL, 
            0xB88238DF0CAB96B1ULL, 0xC4EC346D07A0608DULL, 0x118232F85755514BULL, 0x02B786F6AF424F02ULL, 
            0xDA4474CAC38168FBULL, 0x1FAB644887EBD452ULL, 0xCE827F8789590E67ULL, 0x5E16CA4BF2687639ULL, 
            0x29996F6C72649A7DULL, 0xEFD7355CDF1F0F20ULL, 0xBFD178E9A3A1910FULL, 0xE06EDE4F6CB24280ULL, 
            0x204B25AE72B38E12ULL, 0x2CA73CBC67DC2BB2ULL, 0x8BCF09DA210EAFF7ULL, 0x3014EA7C77059AB3ULL, 
            0xB25197B0C70DBC57ULL, 0x1CD863EC58F23D86ULL, 0xF7B4E736D9156F0AULL, 0x9AF6D9D9C17A5B03ULL, 
            0x75038055349DB0D0ULL, 0x06E9DAD231048BAEULL, 0xCAF6911470822AA2ULL, 0x9BEBB1FB8C476F27ULL
        },
        {
            0xFAF2880E5C3ED831ULL, 0x75FFA02ECB5429EEULL, 0x1D8D64818C415BCFULL, 0x3F9B21D7B2573447ULL, 
            0xDE858549CF71FE97ULL, 0xA30082B488BCEE73ULL, 0x67B4DBAC548C840BULL, 0x37D1DAD66167AAEEULL, 
            0x6071483634D22B6FULL, 0xC16A5308DCF89AA0ULL, 0xAAC8914A2234E83EULL, 0xC65C29E9B1BF3B50ULL, 
            0x2EB98B2FA8B5646AULL, 0xCA9858D96DF08EECULL, 0xAF112177C31B99EDULL, 0xBF3BAA8E6360F667ULL, 
            0xCD65B737ED711A61ULL, 0x0062BA21C813531DULL, 0x67A31669191CE3C7ULL, 0x7DB488F384AE7E58ULL, 
            0x5D8A905918B359D8ULL, 0x117C1C7463E2AA65ULL, 0x37260A935EB052B2ULL, 0x6FAA628CC9082F4AULL, 
            0xA0D56D6844D4528BULL, 0xBACC5327BB2B9A83ULL, 0x6DECADCE45804110ULL, 0x40284CBC0E27A4ACULL, 
            0xD4084F1F83F7A785ULL, 0x54F504F5872E0FCDULL, 0xC26BD600C962D246ULL, 0x07E143F88518EE5FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseGConstants = {
    0xF18A48280894AD01ULL,
    0x2B2C08262DF10B6DULL,
    0xD6D7FD8D62AB070CULL,
    0xF18A48280894AD01ULL,
    0x2B2C08262DF10B6DULL,
    0xD6D7FD8D62AB070CULL,
    0x93913F3EA40E6AF5ULL,
    0x96F8549AAAFAAC71ULL,
    0x4C,
    0xFC,
    0x6A,
    0x7C,
    0x14,
    0xD4,
    0x0D,
    0xF9
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseHSalts = {
    {
        {
            0xBA51FDEC78B9D86BULL, 0x3D9867AE87249940ULL, 0xE186BF286AA1D544ULL, 0x4F27C781FC237E47ULL, 
            0x271C873ECC04BA4AULL, 0xE06C95A9F1CE75E2ULL, 0xA2AA27B215219601ULL, 0xB57628A6B96D9EB6ULL, 
            0x12C84ADF063E225DULL, 0x374FEC92242CE0E5ULL, 0xB6E2D99B0F256E99ULL, 0x9CB5751D76B54D6DULL, 
            0xF55B876AB0DAE89FULL, 0xD5B0003A512035CCULL, 0x7D7BC7FDE6FEE84DULL, 0x87409B942CCDE3B4ULL, 
            0x64B8BDD3A868DAC9ULL, 0xCD9ACF1622C61F2DULL, 0xC0A6A1B6990364A9ULL, 0xF59F5A3E9CB3CD90ULL, 
            0x7F29BE46E42F3D78ULL, 0xEC92E8B210000B10ULL, 0xFA5BD9283F9676E3ULL, 0x10B7CC0028FF2C0DULL, 
            0x350BBD77C30366D8ULL, 0xD6B1BC2E70B40A9BULL, 0x0A265D0B92E59F85ULL, 0x4248A258D9924B71ULL, 
            0xC639A9E6C9C47F6FULL, 0x0B2D9BE49AAAC859ULL, 0xA766CB8263A40A7EULL, 0xD53930DA0EB08F41ULL
        },
        {
            0x6F6647331E31166BULL, 0x72C60E4FE417036DULL, 0x6BF7FA660B36E57DULL, 0x377C81D07E4A12E0ULL, 
            0xB2F3E79F1276ACE1ULL, 0x9300899FE989C353ULL, 0x9D7AF5751E586CC1ULL, 0x8A9F8CD15492C9E0ULL, 
            0x3D59AE7FC7DFD9ECULL, 0x062278799915282AULL, 0x2D05BABCD530B851ULL, 0x46662D554E27E07BULL, 
            0x97D42E317F8D29C8ULL, 0x655252DBC4E52633ULL, 0x11604BDB1A8ABD13ULL, 0xF567CFC3158C1FD9ULL, 
            0x7D6ED05FB62BC649ULL, 0x07C60D5EF8793592ULL, 0x6AFB7328C411C69EULL, 0x498CA11B568FC308ULL, 
            0x3A843001326CFA71ULL, 0xA046CA7AF4999691ULL, 0x451F839FD8DEF488ULL, 0xB5CE00A63745D876ULL, 
            0xFDCEC5397E44704CULL, 0x8E5CC446EC82C66EULL, 0x6F3CE623C9D73C73ULL, 0x67B5D0C24E583A8EULL, 
            0xFC14955FBB07B127ULL, 0x5C357BBD64B05537ULL, 0x41CBE603BEA70946ULL, 0x51A173A5FB87D983ULL
        },
        {
            0x56CC40537B77E7BDULL, 0x45B5929E442CAF1BULL, 0x4BB9F06C007109B7ULL, 0xD055D5FF4AC4A45AULL, 
            0x9EEFBE363EDD18C9ULL, 0x101DDA547DCAD49EULL, 0xFD690A4A1541B118ULL, 0xD50D133A69051E94ULL, 
            0x2295F396882E4191ULL, 0x83EB2382AD3DD218ULL, 0x6546061873A7420FULL, 0xA949F3EEABA400E6ULL, 
            0x85DFBB19750A7082ULL, 0x892A0FDD8F66CAE1ULL, 0x153BE83320BC3B75ULL, 0x46E862AB3522547EULL, 
            0xF5F88E7F40D16803ULL, 0xBE04AB0F48A54478ULL, 0xF977498638D5E33DULL, 0x82ED43C7DF7B2B1DULL, 
            0x47FB2AFFFC475217ULL, 0x87AC9DC7BD365DECULL, 0xE52980178889990DULL, 0x32803C3119874921ULL, 
            0x1FB4D4C5109993DBULL, 0x094E753F57B11EDEULL, 0x9CD15CF1C28161F2ULL, 0x3108D9BA9632EE9FULL, 
            0xD5D34FE89D3A42C5ULL, 0xAA9FB253351A496BULL, 0x87C413CAB1352D54ULL, 0x56F193AAFAFF2BEAULL
        },
        {
            0xE34805EF8C7AF97CULL, 0xBC32741E3AF836ADULL, 0x26BEF6C2BF4F5AB1ULL, 0xA319B34742EEF7A4ULL, 
            0x13723B7E92D7B6EBULL, 0xA931FF8DA9989920ULL, 0xF3D569B0B16D9441ULL, 0xCB6DD891A0B2F821ULL, 
            0x650308526196603DULL, 0xE40EDAA6D8334484ULL, 0xD8EDFA4DD71F43FFULL, 0x0B2189BC10EB775AULL, 
            0x439DE339F8ADF9C7ULL, 0xB0324D6B4684CCA1ULL, 0x4C0D6C9DEA522335ULL, 0xC0DB2592AA56C392ULL, 
            0x407894E51DA9D810ULL, 0xB2F24B76105BF952ULL, 0x8ECBEAE846F73C9CULL, 0x99D0764F46629D0EULL, 
            0x9E016398563BB0C4ULL, 0xF070A96DB7EEED2CULL, 0xB36B5697C51FFAFFULL, 0xD377A86C9B500AF5ULL, 
            0x0F52E6F3CD48F217ULL, 0x7825CE6D6470DF79ULL, 0xB7452E7BA170A299ULL, 0x00FCF273B8C85446ULL, 
            0xDDE9E8FF575E38A4ULL, 0xEE3F2FE133D23126ULL, 0x2AD71E35C6EBF7DCULL, 0x2E24A6FD13367F29ULL
        },
        {
            0xC9DB815676A37B06ULL, 0xC0ADED74982D6933ULL, 0xF500ED6537EF58A4ULL, 0xA4FC9652AAF76DE2ULL, 
            0x994CD85AF2710D04ULL, 0x2022F91A8DCE9F26ULL, 0xB42AB3C6ACB671E8ULL, 0x51650A97E2275DB6ULL, 
            0x6EE84089C0D9E73EULL, 0xE545C722E5BCBD3FULL, 0x121D10F57FF3F88AULL, 0x12835B4845680589ULL, 
            0x73C2684B81AEA7BFULL, 0x882953903C2F7A91ULL, 0x205F8BC6B3C4CFF9ULL, 0x59AE8487FBE58718ULL, 
            0x467F18516DC18ABEULL, 0x034F7FD2A91EE99AULL, 0xC27E2FB2EE38CFF9ULL, 0xC919CB971DA3844AULL, 
            0x9F13734A381D8DD7ULL, 0x519C2FD2A3592C6AULL, 0x68F58D94FF0618A3ULL, 0x3705D4E01C464502ULL, 
            0x95705B1FC5CAE3C7ULL, 0xCCB155086743C9DCULL, 0x935498EB964EBF87ULL, 0xD64E8095D74F429CULL, 
            0x376FB87ECCEA63C6ULL, 0x389DCE5380377422ULL, 0x836956ADA6128FC6ULL, 0x0E02AB1BF77D69A4ULL
        },
        {
            0xFD5D8DE72AE6D069ULL, 0x516E7C68D34BE3E0ULL, 0xDBDFD1A0FD2C7B33ULL, 0xF87EFFB7CDF03B63ULL, 
            0xE8DA585576C4BAA8ULL, 0x1B12B0038CFE2A6AULL, 0xFD843D87940FB53BULL, 0x4959DE37F70BA76BULL, 
            0xB12E3230E5F4E594ULL, 0x90D7294785E39E7DULL, 0xFAA7140B8DC12BDFULL, 0x5713DA2D4BCCAFF1ULL, 
            0x0BE56BD807F0C09CULL, 0x24C1680CD7157FCEULL, 0x9000A28315AD4028ULL, 0x433FFA0BA8F92467ULL, 
            0x5647412D70B496B2ULL, 0x2002B9EAE8C1C3C8ULL, 0x4E7E00EB194A281BULL, 0x017F932867824B3FULL, 
            0xBB4C70B132365BDDULL, 0x7B2BC50AB9D6C1F8ULL, 0x0E7683B0D9B79887ULL, 0x3CED559672E21EE4ULL, 
            0xE34BC8B033D0E455ULL, 0x2A562ED8CFD663DAULL, 0x7FEA463B135543E1ULL, 0x7E0F770C45606411ULL, 
            0x201AEC8340F70B98ULL, 0x2989A8FB4BDD6425ULL, 0x4B4101240A7ACAFFULL, 0xA39077C171C1DBBAULL
        }
    },
    {
        {
            0x2D7B390233505C82ULL, 0x2575F7D0EE69FF3DULL, 0xB4B58FC0215936E4ULL, 0x2C15A1BA51EF2597ULL, 
            0x9D780E25AB0173AAULL, 0xC3FE7D4D6E55D9E7ULL, 0x72C72D1C5851FE9DULL, 0x8983B1F4DA7651C0ULL, 
            0xD36719B586D60DEAULL, 0xC261C912CA9C297EULL, 0x04C3290F7DF7FEC5ULL, 0x3D45DF2903E5D8BDULL, 
            0xA15D6A35F3F0C837ULL, 0x5D62C2AA54E1441AULL, 0x5C0A8A5538B1E617ULL, 0x11517A1D01F99CE8ULL, 
            0x0EB9C54E4A576C14ULL, 0x9431689CCFE6AF27ULL, 0x53347ECA26F32750ULL, 0xD48FCD6DA882783FULL, 
            0x080C20B9FB2CC524ULL, 0x837A518897514076ULL, 0xA247D9AD82E8C822ULL, 0x1ABFBDE0933E8D7FULL, 
            0x6555ED0A813F6BBDULL, 0x843E539464DC060DULL, 0xF233E1A5BC9AE310ULL, 0xD83A48514AF24034ULL, 
            0x8D5D7E4F36B8C9DDULL, 0x50EB8DEDAFC2C4A8ULL, 0x2F25372315E99CC5ULL, 0x6A7D255F63AC5702ULL
        },
        {
            0xEE56160D8D236606ULL, 0xFF56FC856BF3FDB1ULL, 0xC5888A316EB8C0CBULL, 0xEFA4CA72735D8F7EULL, 
            0x5E638466D1313AECULL, 0x9F328BB82AAD48EEULL, 0x3878BFBFD2EE252FULL, 0xDB1F4D05E2993B0FULL, 
            0x3AFC2A02C1EC231AULL, 0x88A16A14ACE79829ULL, 0xCCC8A4092E5E0F42ULL, 0xFBE8748A189E4EE5ULL, 
            0xC9C0C6FB483382B3ULL, 0x474890EA77DFBD35ULL, 0x0D576659BC53779FULL, 0x671448F884919C6AULL, 
            0xF88B370813C03D43ULL, 0xE2810265404DB2F4ULL, 0x72BFC0110CF6F8B0ULL, 0xC444648531A56DDCULL, 
            0xBAD01DB87448FCCAULL, 0xCA8ADE94A11BC083ULL, 0x73F0539F9863CF0DULL, 0x44DBE9257491EA89ULL, 
            0xEF9A0974EF4947ACULL, 0x55363D357BD7FABFULL, 0x0885E4B691F5F7F6ULL, 0x7C5292FCCEF46FC3ULL, 
            0xC8F08F10659F9404ULL, 0x409D314C9A625DCFULL, 0x3813DE815EDCE10FULL, 0xBBF3DB4D5D2310B8ULL
        },
        {
            0x4E5637EEC922CC24ULL, 0xE2DC55840CF6C029ULL, 0x14C8F43BA795E926ULL, 0x6FE99AD7072685E5ULL, 
            0x1B151DCEF34B5E7AULL, 0x3451084616A3AB03ULL, 0xE6B80978A9A5CD51ULL, 0x526E340E51E22D19ULL, 
            0x4BEB93E7996203E5ULL, 0x53CD587C0765FA86ULL, 0xEA973408502B621FULL, 0x51D3A7A074FACA79ULL, 
            0x17CAD323F48F712DULL, 0x3904454FEE4862AFULL, 0x4A58432E2A3884F9ULL, 0x73785A363E4A747CULL, 
            0xDC9A317237D0AE9EULL, 0x8B47FE22FEBDC40FULL, 0x77FFA2A41EAAD620ULL, 0xC7FE3F0032342589ULL, 
            0xA2384DB152EC1EEEULL, 0xCE09A7A3BF2E06C2ULL, 0xDA1F26AD6C0E4471ULL, 0xC875883FAC7B60ACULL, 
            0x251F60DA4D30D0A6ULL, 0x2E249DE261EDB9DFULL, 0x252CD98B77A8CC42ULL, 0x7DFF35702C761E2EULL, 
            0x211DE7E104DA73B0ULL, 0x62E5146BA92A49D8ULL, 0x9E01B393117892FAULL, 0x0DB192B00C876EB4ULL
        },
        {
            0xD4C605022F15020EULL, 0xC28AC7094954743EULL, 0x0A77A44FB23F5891ULL, 0xF3A3BA7BD7C43E7BULL, 
            0x70A549A1FA5F4395ULL, 0xB041D2DB492B1B75ULL, 0xEBEC518C7A146BC8ULL, 0x7ADF577174E07F7DULL, 
            0x9CD8E3D5558D03BDULL, 0xBD803B4F5AD7AB10ULL, 0x2B4A9F3F1EF1DBA9ULL, 0x1FB4736739366E6EULL, 
            0x6434A6DB84BC1424ULL, 0x7E95E7EF7480C749ULL, 0xCD3BB2142826406EULL, 0x7D9C3CE146135829ULL, 
            0xD3FF66A2BEE88444ULL, 0x7A0C406AD4F17949ULL, 0x2D4E763F07889513ULL, 0x6B42C19B4B2D8442ULL, 
            0x9A3AAB9CE3926C2BULL, 0xECD170318B8FB496ULL, 0x86985F142195E9E4ULL, 0x4F990DCCE9C86C59ULL, 
            0xFE199AE54F15FCC5ULL, 0x0BBD4EAC10ECF3A4ULL, 0x82890B074B353AA0ULL, 0xB891D8D150CD02CEULL, 
            0x3B743CF7086AC22CULL, 0x6C589FD9E3E8A1DBULL, 0x9E262A7D75DED847ULL, 0xCE3D795CF4F0ACE5ULL
        },
        {
            0xAC41B4C6556BB9EFULL, 0x4DE26E78A73235B3ULL, 0x8E6C609AF14AC4C9ULL, 0x6AD30A73119FDE13ULL, 
            0xECBF0E17B40E6541ULL, 0x2DD23B522BF54435ULL, 0x2CED0172F990EBF0ULL, 0x63CCD8677235E8E5ULL, 
            0x7E65D5F7E504849EULL, 0xAF52A5AEF38DF9BAULL, 0x5A867591E54726A6ULL, 0x8403AF504C8C4A99ULL, 
            0xFDD7C76924DF50ADULL, 0x2E9B839B911C16A5ULL, 0xF60B77C8DB247E8FULL, 0x4D719BDBB19B177CULL, 
            0x8A65B2C4687BC2D1ULL, 0xB8054774CF3F6595ULL, 0x487B2D909BD39048ULL, 0xAF2CF17BAD1EE759ULL, 
            0x965CD0D5DDEF21C6ULL, 0xD79738615F4973B4ULL, 0xA8C880A5508303AEULL, 0x116568F3C66325EFULL, 
            0x3C727AE5213203D5ULL, 0x543DAC05944DAAB6ULL, 0x597D77347AEDB696ULL, 0x6D00862A6877442DULL, 
            0xB2CB73F0D62424C8ULL, 0x357CDE1901AF2265ULL, 0x6DEBBE70FA2ED15DULL, 0x6AA7505B1905442CULL
        },
        {
            0x0F353427324ECD1DULL, 0x971B04C3F6FC4D9EULL, 0xA22AD608C4ADF595ULL, 0xE142C6A3C7F49972ULL, 
            0x28F0DA0F617724EAULL, 0xC78328A6AF633699ULL, 0x984A093079EDD20AULL, 0x2FB4CEE8FF7110E1ULL, 
            0x50F9AEA41860D0F8ULL, 0xE89EB56787CD5F5DULL, 0x747EB5031DD7F4EDULL, 0xF1F49EBBE89A1145ULL, 
            0x48B2EB053993CD1CULL, 0xA233F2C7CBC6CB05ULL, 0xB0205EC5B1EC7C0BULL, 0x24496D8DF2494CF7ULL, 
            0x2663F8E5CF6AAD2FULL, 0x77B89EF1F1103532ULL, 0x74B781CE2191FE92ULL, 0x492F17DB842A09E5ULL, 
            0x388257D4712AF700ULL, 0x14F4A1FD4C40912CULL, 0x469D48164A64E878ULL, 0x291CBA3CFA9B4FE2ULL, 
            0xDE74FE57CB216D69ULL, 0x02A2B943787D0BAEULL, 0xC42A09D3D62F8B56ULL, 0x440A24F76EB507F9ULL, 
            0xB59065985B80FCAEULL, 0xC5354A3EFABB8B20ULL, 0xC634B2938BA98DC6ULL, 0x9F080A4A2E5855FEULL
        }
    },
    {
        {
            0xA53C58D0004964C0ULL, 0x93A7132CFDC322ADULL, 0x4EF3E16A339A89A7ULL, 0xDF97C542AED87968ULL, 
            0xD2CBF8AD3BBD801FULL, 0x668105A89866BB5AULL, 0x5AD23394F17C5377ULL, 0x88E4791A891FDFD3ULL, 
            0x9F054B4C96788D2FULL, 0xFC370473F93BAA4CULL, 0xFEB60F53793DE392ULL, 0x319C44D3E7F287E0ULL, 
            0xD0EEC29126A60A62ULL, 0x12B32239DDDAB748ULL, 0xDBD934A3674EF25FULL, 0x0B5C1155DB89D493ULL, 
            0xAA99045A3DA755C5ULL, 0xA663C0057513DAC7ULL, 0x2C513D4FAADDB7B8ULL, 0x69351C252D940410ULL, 
            0x66E22776D4659999ULL, 0xF0006DE376758A38ULL, 0xD9DEC169663D48C2ULL, 0x3E09CB0147D33FEAULL, 
            0xF58C03913FA9FAF1ULL, 0x173FAD4F28FA5C37ULL, 0xDC1EEA858E7B5A65ULL, 0x3A34CDB865452D5BULL, 
            0xD90D822CF08DC874ULL, 0x9B62F57B7CF210A9ULL, 0xAD36845DB77EADEAULL, 0x4C516207DC830487ULL
        },
        {
            0x6DAC18AD7940A16BULL, 0x4C30E32043A04EBEULL, 0x7853978FFAA3ED62ULL, 0x40C18F047B73DCEFULL, 
            0xBE24C3C0A187DEEDULL, 0xD042D9B5FB813304ULL, 0xE9EF043CB1872924ULL, 0xFC384C84114839D5ULL, 
            0xFBB52855B423B9D0ULL, 0x249D89517E0EBF5BULL, 0x02926615C6E5F7CCULL, 0x610D6D886FA2A9C6ULL, 
            0xA21CC8DA6E07C97DULL, 0x276C408E88A09F48ULL, 0xCB69AD1D7E7BDA71ULL, 0xAD86861F4A05B472ULL, 
            0x8657714D01A3A3D5ULL, 0x3FDCB4DA2021A8C0ULL, 0x749B7572F2B58320ULL, 0xF859767186EA344EULL, 
            0x8E5AE6A077C7A2B9ULL, 0x69A49CFEFFBAFEFAULL, 0x30D9711FB22AA140ULL, 0xB9AD0EADA2127419ULL, 
            0xF0685DE52FC5101BULL, 0xCE6AB2638C433059ULL, 0xBF8FC99F2EBA6100ULL, 0x06C9AC9A2AB22845ULL, 
            0x2978A927FEF6B36DULL, 0x1E3F40725E243E7EULL, 0x825C7E0E8A3C0FA9ULL, 0x836BB22741490C22ULL
        },
        {
            0x7DD29F72DDB16671ULL, 0x63CDA45F6ABCBAB8ULL, 0xED2993B128E3B737ULL, 0x78F4D4E7572523DAULL, 
            0xBF12283D79226176ULL, 0x89DDB75D9958486EULL, 0x0FC5D0D17D8AB630ULL, 0xFE833660F0312B75ULL, 
            0x9953703374DCC7A0ULL, 0x5DB8135E0031D551ULL, 0xF104E180BF18E3D3ULL, 0x7C15D347D180316BULL, 
            0x18252BB4C6CC4FD1ULL, 0x8165D331B852D38DULL, 0xDFFB98B31389DC17ULL, 0x28C02DA83B54E442ULL, 
            0x2AE5318D0AE07B50ULL, 0x9A4715424480CBABULL, 0x17726959E19D262FULL, 0xCABF442A32C2BDABULL, 
            0xEA7DD24B56E02822ULL, 0xA39B272E4E20CF90ULL, 0x64CFFCE6C77E6250ULL, 0x04670D8CF66C169CULL, 
            0xE2D8E2FCE5927EA3ULL, 0x8BAED5807FC0A744ULL, 0x27B42C1AC3715324ULL, 0x9B90725D920502ACULL, 
            0xD004FE2417ADD680ULL, 0x59CDC8D1B15D9866ULL, 0x0DFD5B5CE7A82DD9ULL, 0x274FDA189947D0D3ULL
        },
        {
            0x2DE6ED1B221B8CDDULL, 0xB04746A306B2BFC4ULL, 0x7D290A9E82C55946ULL, 0x1E4D864ECFD6DA9FULL, 
            0x4640808C12A9C17FULL, 0xEA87B59CAB1B0F19ULL, 0x41C960D08B42313EULL, 0x45DE171C667A820DULL, 
            0x8C28A1C0CF94221DULL, 0x6B5934832A6E1D91ULL, 0x8692CCCEE3334E7AULL, 0xBFD32A07D59AB918ULL, 
            0x6A27F0D975417CCEULL, 0xD7E7CDA08E701B31ULL, 0xA3BC1935B5C84D64ULL, 0x035C75F9771E655BULL, 
            0xFBF5B4488DED5FBAULL, 0xC8D352F0885FCC67ULL, 0xC9A073D84D891F1BULL, 0x0099CB6B7A0FE60EULL, 
            0x5ACA0EF5A66CFD5AULL, 0x93D645B180807AD6ULL, 0x95636CD4A312C19CULL, 0x3C217346D5AACC3EULL, 
            0xC06EFD7075A2E641ULL, 0xE5AB9FD94ABB6196ULL, 0x3D9F4D6B2325F970ULL, 0xCD92B93394D89FFBULL, 
            0x7323887CD4FFBF95ULL, 0xEED5451FDDD84535ULL, 0x349C9F15C4EC4964ULL, 0x84C14B73BE78DE94ULL
        },
        {
            0x71E5996BFDB62BECULL, 0xDE2E09A75B4C0004ULL, 0xA58E6D02F164505AULL, 0xAFD6FF30B4AECB29ULL, 
            0x43677B4E07FDD0A1ULL, 0x5C2AD5ABE3E8F361ULL, 0x594C577A2B75B2D1ULL, 0xE6D58F1874E06E6CULL, 
            0xE7C6DCBEE6E9C105ULL, 0x7C8F99B3C6F5FA18ULL, 0xFCC0FC17D02C2DEBULL, 0x5EE066F2281A53D0ULL, 
            0x03571AE9CD757D49ULL, 0x4B29BA1164E2361FULL, 0x3B929DAF58434FE7ULL, 0xC6C72BE8AD3556DDULL, 
            0x148E99BFC3AA1CC7ULL, 0x47D94D5CB9FE00E0ULL, 0xB05FF0CBA9EBDFFAULL, 0xB0C39F7DBAA8F8EFULL, 
            0x4A222A7BCBF40BBDULL, 0x4188487A3B8EBFA4ULL, 0x49B5C6334E1BF851ULL, 0xEEC52A366652E095ULL, 
            0x68CF0C95E66302DAULL, 0x780EE84CB2678C6AULL, 0xBD4D2F56BB91E115ULL, 0x2C7B2B4D7E6F7FFAULL, 
            0x9A0246656C947F7AULL, 0x601747D54ABF2A79ULL, 0xAC50F1B43854B1E2ULL, 0xF7D17E369FB1097DULL
        },
        {
            0x66BB26902420B5F0ULL, 0x0137A01E7FF9A204ULL, 0x24873E92995E5E6CULL, 0xF136BDDCC27703F0ULL, 
            0x491A87291A3AA8B8ULL, 0x883F3D302F6F2889ULL, 0xE8B0CB2D9B7602B7ULL, 0xE9EED1FC11DA876DULL, 
            0x1A26551777247F07ULL, 0x87C1491C87A65CD3ULL, 0xC56971A8DFAB01BAULL, 0x300B3D3518D1B275ULL, 
            0x18F982C7CD6407EFULL, 0xA645305AA2D265B9ULL, 0x23092222DA185D4CULL, 0x996294843D94086FULL, 
            0x4444FCA3F48BA183ULL, 0x8DEC47D69DC29A7CULL, 0x9E1E1F070D5B63F9ULL, 0x2030CC8143B8DCC6ULL, 
            0x2D2829E1FCD7586EULL, 0x7B62DD0EE4819B02ULL, 0x2DDC5F03E15555A1ULL, 0x1136D7509A4EA5FDULL, 
            0xB9A500E4B5B9FE5BULL, 0x4967AD138FEDEC42ULL, 0x5D93CA640FCCC63EULL, 0x9F7D592460725566ULL, 
            0x0514FE42D31992CEULL, 0xA8EAD21E333DB542ULL, 0xAB60A5AC6554D7FCULL, 0xD2C3CDDDC10D5557ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseHConstants = {
    0xA04CCCA92CC7E1AFULL,
    0xB3B6F572B0C64ED1ULL,
    0x8FFA38A19BF9CCB8ULL,
    0xA04CCCA92CC7E1AFULL,
    0xB3B6F572B0C64ED1ULL,
    0x8FFA38A19BF9CCB8ULL,
    0xEBB79464631759C1ULL,
    0x33B0011347A66576ULL,
    0xEC,
    0xA8,
    0x88,
    0x6C,
    0x01,
    0x73,
    0xFE,
    0x72
};

