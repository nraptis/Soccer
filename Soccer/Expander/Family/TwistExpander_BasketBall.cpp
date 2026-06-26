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
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow);
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

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
        aPrevious = 14396513077898330873U;
        aCarry = 11274541830716831617U;
        aWandererA = 11990733241831072794U;
        aWandererB = 17433386847972210939U;
        aWandererC = 11699497620746849429U;
        aWandererD = 17784061408806269122U;
        aWandererE = 10628924597414216873U;
        aWandererF = 11678242903896744343U;
        aWandererG = 15623388722603495001U;
        aWandererH = 16496653591261367954U;
        aWandererI = 17341455354547452645U;
        aWandererJ = 11774976284659861651U;
        aWandererK = 15586086042143769065U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aArx;
    aArx.KDF_A_A(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aKDF_A_BArx;
    aKDF_A_BArx.KDF_A_B(pWorkSpace,
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
    TwistExpander_BasketBall_Arx aKDF_A_CArx;
    aKDF_A_CArx.KDF_A_C(pWorkSpace,
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
    TwistExpander_BasketBall_Arx aKDF_A_DArx;
    aKDF_A_DArx.KDF_A_D(pWorkSpace,
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
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [kdf-b]
    {
        aPrevious = 13844944532445365949U;
        aCarry = 10186139956314434544U;
        aWandererA = 11840761384044591821U;
        aWandererB = 13562446753974332611U;
        aWandererC = 12900328869905953990U;
        aWandererD = 16994277709473722073U;
        aWandererE = 10850883937037231543U;
        aWandererF = 17608637351607374896U;
        aWandererG = 13887309341601309081U;
        aWandererH = 11763987891947442388U;
        aWandererI = 15209439109166583435U;
        aWandererJ = 9469291775140628919U;
        aWandererK = 10734122321176291575U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aKDF_B_AArx;
    aKDF_B_AArx.KDF_B_A(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aKDF_B_BArx;
    aKDF_B_BArx.KDF_B_B(pWorkSpace,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aKDF_B_CArx;
    aKDF_B_CArx.KDF_B_C(pWorkSpace,
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
    std::uint64_t aPrevious = 0xD63BF9D83636B351ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0x9F8465FF22F839B9ULL;

    std::uint64_t aWandererA = 0xA82C87B94B2C778FULL;
    std::uint64_t aWandererB = 0xBB988AD13C0FE02BULL;
    std::uint64_t aWandererC = 0x920B47CFB419CBCCULL;
    std::uint64_t aWandererD = 0xDD9885A3D5B11BC7ULL;
    std::uint64_t aWandererE = 0xA1E91DECE112BA9FULL;
    std::uint64_t aWandererF = 0xA8C0A3E4C356F1AEULL;
    std::uint64_t aWandererG = 0x9FF1631084C21640ULL;
    std::uint64_t aWandererH = 0xB34F9A969C4D847BULL;
    std::uint64_t aWandererI = 0xB4D2FA478D4C0EAAULL;
    std::uint64_t aWandererJ = 0xC6741707E92558C0ULL;
    std::uint64_t aWandererK = 0xDA514161933E29B4ULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneE);
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aSeed_AArx;
    aSeed_AArx.Seed_A(pWorkSpace,
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
    // GSeedRunSeed_B seed_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aSeed_BArx;
    aSeed_BArx.Seed_B(pWorkSpace,
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
    // GSeedRunSeed_C seed_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aSeed_CArx;
    aSeed_CArx.Seed_C(pWorkSpace,
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
    // temp storage: operation_a, operation_b
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aSeed_DArx;
    aSeed_DArx.Seed_D(pWorkSpace,
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
    // read from: work_a, work_b, work_c, work_d
    // temp storage: expand_a, expand_b
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aSeed_EArx;
    aSeed_EArx.Seed_E(pWorkSpace,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aSeed_FArx;
    aSeed_FArx.Seed_F(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aWorkLaneA, aWorkLaneB, // output lanes
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
                         aWorkLaneC, aWorkLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_g:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aSeed_GArx;
    aSeed_GArx.Seed_G(pWorkSpace,
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
    TwistExpander_BasketBall_Arx aGrow_AArx;
    aGrow_AArx.GROW_A(pWorkSpace,
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
    TwistExpander_BasketBall_Arx aGrow_BArx;
    aGrow_BArx.GROW_B(pWorkSpace,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_BasketBall::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSourceInput,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSourceInput, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
    {
        aPrevious = 11927698110839196872U;
        aCarry = 17207166440524206596U;
        aWandererA = 12031275843803543248U;
        aWandererB = 10614951792698132446U;
        aWandererC = 17144728553297844379U;
        aWandererD = 9545759697597581775U;
        aWandererE = 18365131912049922113U;
        aWandererF = 14568637076661363242U;
        aWandererG = 17787947870065136952U;
        aWandererH = 15612109361429977125U;
        aWandererI = 10356902879987290544U;
        aWandererJ = 12077664925387796564U;
        aWandererK = 14274526321071745547U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aTwist_AArx;
    aTwist_AArx.Twist_A(pWorkSpace,
                 pSourceInput,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aTwist_BArx;
    aTwist_BArx.Twist_B(pWorkSpace,
                 pSourceInput,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aTwist_CArx;
    aTwist_CArx.Twist_C(pWorkSpace,
                 pSourceInput,
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
        TwistDiffuse::Diffuse(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
    }
    {
        TwistDiffuse::Diffuse(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_BasketBall_Arx aTwist_DArx;
    aTwist_DArx.Twist_D(pWorkSpace,
                 pSourceInput,
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
        TwistExpander_BasketBall_Arx aGrow_AArx;
        aGrow_AArx.GROW_A(pWorkSpace,
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
        TwistExpander_BasketBall_Arx aGrow_BArx;
        aGrow_BArx.GROW_B(pWorkSpace,
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
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 3, 0 with offsets 4487U, 1982U, 1554U, 6290U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4487U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1982U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1554U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6290U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 2 with offsets 4758U, 3150U, 2404U, 2672U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4758U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3150U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2404U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2672U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 1 with offsets 322U, 1572U, 280U, 643U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 322U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1572U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 280U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 643U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 1, 3 with offsets 637U, 4193U, 8184U, 1531U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 637U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4193U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8184U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1531U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 3, 2 with offsets 1069U, 2042U, 535U, 822U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1069U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2042U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 535U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 822U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 0, 3 with offsets 202U, 247U, 1071U, 350U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 202U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 247U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1071U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 350U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 2, 3 with offsets 1U, 690U, 1229U, 129U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1229U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 0, 2 with offsets 1574U, 575U, 381U, 1644U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1574U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 575U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 381U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1644U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 412U, 383U, 418U, 2045U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 412U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 383U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 418U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2045U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 2 with offsets 2608U, 1676U, 1547U, 3600U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2608U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1676U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1547U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3600U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 1 with offsets 7288U, 3850U, 3853U, 4140U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7288U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3850U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3853U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4140U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 2, 3 with offsets 278U, 6610U, 6680U, 6836U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 278U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6610U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6680U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6836U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 1, 0 with offsets 1688U, 2547U, 1868U, 4848U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1688U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2547U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1868U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4848U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 693U, 3461U, 2916U, 2164U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 693U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3461U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2916U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2164U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1152U, 611U, 876U, 1824U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1152U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 876U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1824U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 655U, 2026U, 2014U, 2032U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2026U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2014U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2032U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1998U, 1676U, 1218U, 1832U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1998U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1676U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1832U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 116U, 439U, 1024U, 1674U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1024U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1674U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 [0..<W_KEY]
        // offsets: 377U, 1335U, 1360U, 527U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 377U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1335U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1360U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 527U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseASalts = {
    {
        {
            0xD143CA08B01619FCULL, 0x4324500E378B8E98ULL, 0x8E8803FF3EE0FBBFULL, 0x4786AF0E5C53381DULL, 
            0x48666ECC59D94C9DULL, 0xACF4A3D2FAFB20BEULL, 0x69FE92B13DD82865ULL, 0x71819850CACB04CEULL, 
            0xE68498A398B81753ULL, 0xED22986A703915A0ULL, 0x1FFCE7FA42F7501CULL, 0xC40C67463CFF4242ULL, 
            0x7E34800D2E3B802FULL, 0xC50A2DA80986594DULL, 0x1FBB7D3FCDF1C329ULL, 0x1645BC611C8EC601ULL, 
            0xBC7758607085A180ULL, 0x502115636164F9A1ULL, 0x99309FFFB748CD2AULL, 0x3D7EBF4FE837C080ULL, 
            0x55540956166AC2ACULL, 0x5CAF251BFCB393EDULL, 0x707061BB70766771ULL, 0xFDC99FFEF4823AF8ULL, 
            0xF10775BF432EAE89ULL, 0x7C31E0FAE7202442ULL, 0x9DD6DE2F63A5C102ULL, 0xFCBE88C7C6E32B9DULL, 
            0x99D35A83D9903C59ULL, 0xCAD3141C5B2599B1ULL, 0xACB8821C2D1A559BULL, 0xA5A0843A28739CB8ULL
        },
        {
            0x70496FB5FEE688B2ULL, 0xA4808681F4C183B9ULL, 0xDC0CF2AEE7001193ULL, 0x9B6B969AC9B053BCULL, 
            0xD9BF11719CFB0B45ULL, 0xF4B179C7F0F043E3ULL, 0x57149D434B1CCF91ULL, 0x55BA248572033A62ULL, 
            0xE7DB0BDBBEF7BD7DULL, 0x7C37170FC493159CULL, 0xFB990B4F413BE794ULL, 0x90D585586233CAA8ULL, 
            0x45E47D29B0C59209ULL, 0xCA13E7D0C3F7A3FCULL, 0x8FF50EB9059CC63AULL, 0xE7C1326D66C2C7A2ULL, 
            0xC2F379AC216FF2B3ULL, 0x02F74E300D9B6798ULL, 0x5927C614709DC4B3ULL, 0x495F13A2146D7B39ULL, 
            0x9C071ACBD99300C7ULL, 0xD90BA51633635CECULL, 0x906105A1F79115EAULL, 0x7F932935CDABA584ULL, 
            0x1E045498758475E8ULL, 0x5CC4BC363B8AB717ULL, 0xEC64A7183763D7C3ULL, 0x9F53C1F1D0F1D5ECULL, 
            0xB885AA2C061677B8ULL, 0x7C99E6CD616F400DULL, 0xB565C25FAA8A0318ULL, 0x167A8C73C0A12AEBULL
        },
        {
            0xA55DF242D874B74DULL, 0xC8BB6D26E4BE74AFULL, 0x0E35A45AFAC8CA60ULL, 0x03C398789B3BA437ULL, 
            0x85D363067F55C66BULL, 0xACEA292C9DEE6DE6ULL, 0x978BACC958A45249ULL, 0x8827B6C37D909E11ULL, 
            0xA8AADDCC21DFC461ULL, 0x7AED07E7AF4867EFULL, 0xDFD5624501DC9528ULL, 0x447CF86C9334478EULL, 
            0x35C979C51F32E846ULL, 0x50F50244DE827231ULL, 0x22D775DC801F8B34ULL, 0x2962328EB43EB299ULL, 
            0xCECFACB8FBAEBED4ULL, 0x1E269559A7249A22ULL, 0xCCC49CA7F54CEA8BULL, 0x7AE5676E09443909ULL, 
            0x0CF16E7A6BB78286ULL, 0xD0F945AB596475C0ULL, 0x38459A91C2424EC6ULL, 0xC7CC69779C39FE00ULL, 
            0x52830A508328A032ULL, 0x247421779AF164F6ULL, 0xDE99DD5D812F8C78ULL, 0x189ACCECCC44A149ULL, 
            0x3444912D8F05DDD9ULL, 0xC79B5D2946B7D898ULL, 0x0178199B68900D3CULL, 0x977D675D2A61FC9DULL
        },
        {
            0x6FA708E9E6D803A5ULL, 0x128541C2BB0350EBULL, 0xB73230D4DCEA2BF8ULL, 0x015F79117F2FC1E1ULL, 
            0x62B31E0FB906C953ULL, 0xBCA1C1E0F6806DD5ULL, 0xE654876386C864E3ULL, 0xBD71DBFBB82C5DB6ULL, 
            0xAAC1553B53B44AB9ULL, 0x26CB0A17106FF699ULL, 0xB0382A2A9C6844DDULL, 0x0FC3CEA0EBA8008BULL, 
            0xACE2CCCA9FF78799ULL, 0xEF38AAB73E07CA06ULL, 0xF2E55A28F9F9F036ULL, 0x1B1B2DD594D5E82DULL, 
            0x8C8CC6B61E75B3A8ULL, 0x64CAE4D86AB6A186ULL, 0x2697B33EB7237247ULL, 0x2E22E05DE9A8DEFEULL, 
            0x1EC09A98F40C505DULL, 0x2713EAD05100E20BULL, 0xE5EA997F06F93C97ULL, 0xAA4FD83B19716204ULL, 
            0xEAD1A64E7F87BDA5ULL, 0xF20C86B9282BA0BEULL, 0x50960214910BED5FULL, 0xA14DD5E68D357D84ULL, 
            0xBEA30E36092884B3ULL, 0xE4727BFA21B9D0BFULL, 0x757F0A17217A3996ULL, 0xB187130C14F00AB4ULL
        },
        {
            0x633BDBCED0F6BBC0ULL, 0xF6745974FFA41B5DULL, 0x26D535A292019538ULL, 0xF86AF5BD4DDBEF06ULL, 
            0x9D8E010F552CC0F4ULL, 0xE58FBB1F61D4AC4BULL, 0xE0D0331997199299ULL, 0x772285465B8BFE84ULL, 
            0xDA703770AF83A5A7ULL, 0x572EAEFE03F18F8FULL, 0x050482AB8C294712ULL, 0x95A918D034C90043ULL, 
            0xB68755B7653D8EBBULL, 0x5BC2154D2D7B36F1ULL, 0x5D4F9F0CF1B30F5CULL, 0x5A66377B539DA065ULL, 
            0x6BF2500C6BE58379ULL, 0x1E44E4F90862CFB5ULL, 0x2D4337ECBCC8090AULL, 0x14101925520378E4ULL, 
            0x28EA98BCCCEAA7E4ULL, 0x2846656B345DBF55ULL, 0x71367E5A0AF71399ULL, 0x306C188D09469239ULL, 
            0x9BE4C6D7DEFA4312ULL, 0x486951FAFC78C337ULL, 0x93028B0DCF325474ULL, 0x3A279619BFEEA7A9ULL, 
            0xA27347A92B6BB13DULL, 0x832CEF71827AD515ULL, 0x1C1CA3355A4BC0ABULL, 0x995472481138AFBBULL
        },
        {
            0xC0072D5D656DAC0AULL, 0xFA2A99E5BBEEA531ULL, 0xB1DE774A5D5D485CULL, 0x92872F6DB84EC451ULL, 
            0x401ADEF37FA1CC0CULL, 0x6D49E6351941C725ULL, 0x870A2CFE8D099A13ULL, 0x2C0F33EBF4E51EE2ULL, 
            0x2871D6455D2C2134ULL, 0x9D9BC76CCFE52FFEULL, 0x9B2263AC704F60C9ULL, 0x37079F9753A14F8BULL, 
            0xEBF6E1696BBC3C00ULL, 0xE433791827409615ULL, 0xA1BC1DA095B7323EULL, 0xAE975123CE0A588CULL, 
            0x5A9FDCA1E6700DDCULL, 0x3FC561CE905BC650ULL, 0x25A55E93FD0ABA3AULL, 0xB4EFECB34AB1D33FULL, 
            0xB599C9AC75B57FFEULL, 0xE6E534D22CA5BBCEULL, 0xEF4E858333EF2AB5ULL, 0x756310C6F2328287ULL, 
            0x5F316AF3443D4FD4ULL, 0xF4A4A2FC18078A6CULL, 0xEE3C6FDC1DE58534ULL, 0xA3D4A69B7736F3ABULL, 
            0x85AA2541702C6E9BULL, 0x2838F58A3857679CULL, 0xB03E9D08A490659FULL, 0xCF4BEBE85C33871DULL
        }
    },
    {
        {
            0xC5BFDCAB6748158AULL, 0x9180F18C9C5CFE60ULL, 0xAE85C9CC0C310FF5ULL, 0x0E503FB9243B458EULL, 
            0xEC9E8E55CA2438DEULL, 0xB7A697E9275F625CULL, 0xC1D1F7978154DD27ULL, 0x8BB99BD55D73C41BULL, 
            0xE7B713339504DF41ULL, 0x3AEE390CB51A7D20ULL, 0x497B6E657ABAE1CAULL, 0xE0BF7827D073E6C4ULL, 
            0xFA726BA3EF73F727ULL, 0x7BBAB45F48636B59ULL, 0x11BDF092791BCABFULL, 0xC6AF16AE101D125BULL, 
            0x7261AAAD95CB9B3BULL, 0xB70C7C5C31CE113DULL, 0xD979864C85F8E828ULL, 0xC43D1BA68ABC5716ULL, 
            0xEB0CA8FA6CA22B1BULL, 0x464C5747D58E3BF0ULL, 0x0D574D43B4B40613ULL, 0x15D1F1909C8464F6ULL, 
            0x8F1FEC6993319C3CULL, 0xA943D78B6F472E93ULL, 0xC4294271FEB04A19ULL, 0x260F90EC4D51E354ULL, 
            0x06959B90C60B1602ULL, 0xF1B0E486ACB8786FULL, 0x08E4DB94DB3D7EC9ULL, 0xD64833086E818A7AULL
        },
        {
            0x722E9F2DFD9A5C3DULL, 0x73B535317F71E7FDULL, 0x26DA4825F2E5D0D3ULL, 0xEB5084C6399F85EAULL, 
            0x491B7E1EB580236DULL, 0xDC317EF7988268B2ULL, 0xFE3133BDC5443E82ULL, 0x9FC5A272307ECBE0ULL, 
            0x1D41B7988EB378C6ULL, 0x45C0F7D6F4601737ULL, 0x4CAAB27B7A1F840FULL, 0xEC1E0455E991F8BEULL, 
            0x5ADDA4AD48256DCBULL, 0x216FA12178A50E55ULL, 0xB37FF94C3FBE5F4FULL, 0x53FA8A0A50E2B24EULL, 
            0x4680222CBD718F71ULL, 0x75B9609D62D3794CULL, 0x5FD841049CBE5DF2ULL, 0xE5A986E7192CC0A1ULL, 
            0x1178CF5117C0A817ULL, 0xCD616A3ACCF82386ULL, 0x3437CA73A0E8F13FULL, 0xB1791766EC8A30F0ULL, 
            0x1DC33EF108110B5BULL, 0x4A3D7C871F063A27ULL, 0xD91788E56B406DF0ULL, 0x3E468BB8175E86E5ULL, 
            0x42D7DB4562C7D3B1ULL, 0x840B7809F40B9482ULL, 0x84A6102425024CC0ULL, 0xB3BCF8814E4AA558ULL
        },
        {
            0xD4E812261051AAEAULL, 0x3B2F47FCFAC70742ULL, 0xBFCFEFFC3366207EULL, 0x6262C7081877597DULL, 
            0xC832C40B8243230FULL, 0x56A20B43942554F9ULL, 0x9DCBED89FFED2C20ULL, 0xCA85CAF31BC1E043ULL, 
            0x8CEE0D2329312912ULL, 0x08673D62131063B8ULL, 0x6847AC8072835D7BULL, 0x05D7B0394B29E8D9ULL, 
            0x87CD579D45A778C0ULL, 0x2ACD077AEE1C1797ULL, 0x15CA8EBDAF860724ULL, 0x769CCA451930CC1EULL, 
            0xB7A8F10C764AAA68ULL, 0x977204E911F19F7CULL, 0x7D58A4406481365CULL, 0x50A8E3FC0B918EB2ULL, 
            0x86B303C669D2A04DULL, 0x6BFE9D2B479E95A3ULL, 0x99F50C806D3FA44DULL, 0x4246801F39368A82ULL, 
            0xBE41EBF539CB35F8ULL, 0x61B62E9B8E17CD6CULL, 0x7D8C47E66A31DAD6ULL, 0x3A93D025E3FA133CULL, 
            0x55889150CC1DA884ULL, 0x3F7634EFE4D9F891ULL, 0xEA53BC28322158EDULL, 0x19E97EE137E28985ULL
        },
        {
            0xE8FBACF5FA15055EULL, 0xBC8F2027A534D19CULL, 0xA84C16DF190C86B0ULL, 0xFE8CA098089081AEULL, 
            0x29EC27DB7906E468ULL, 0xCB22EF0EDBCF3387ULL, 0xC67479CDF7C87DA7ULL, 0x22E004083B618154ULL, 
            0x3FB53E541329BDCAULL, 0xE01AA3F1A6521A5EULL, 0x5080143298C61655ULL, 0xD6560E8A91178BA1ULL, 
            0x00C129CF5052CCEBULL, 0x8204E5496EBBFD6DULL, 0xD3B7775E91231FDBULL, 0x4E37485210F6E833ULL, 
            0xC9BE234CA3076143ULL, 0xBBFEE108215524ECULL, 0xBE205BB998FE6F84ULL, 0x8495F6DAAC989384ULL, 
            0x6470D58E4CB7C60BULL, 0xC4717BC35BA1C424ULL, 0xDBE0846347BA42C6ULL, 0x6C9925AF18C1EECDULL, 
            0x17A8B09C16C6F6FDULL, 0x2FC1143420089CFEULL, 0x9427EAC9F5EBD389ULL, 0x15BF2CDF3190961EULL, 
            0xEE6A6C5E6EE71C97ULL, 0x54C3577D0B6D1222ULL, 0xCBC7A6F4D688015BULL, 0xF7FF8BF9AA611E07ULL
        },
        {
            0xE71D8D78FD353D16ULL, 0x9B6B36E374410074ULL, 0xA80FDF24DC1EDC37ULL, 0x054BA17C71CEBE14ULL, 
            0x2220BB555860DD1AULL, 0x6EAE2FA33DA9E041ULL, 0x2298DC49A7203D3AULL, 0xEB8846A9D6A96A8CULL, 
            0x95F66833C8A47998ULL, 0x62DA46AF8400B064ULL, 0x11C71EE0303039F1ULL, 0x01D798E649890AC0ULL, 
            0x56B1DF085EDE97E3ULL, 0x7043596E7F1B692BULL, 0xB20503725FF8FCFEULL, 0xBFB55C34DF10D848ULL, 
            0xE72A18A382EAD27EULL, 0x23C0DDBDBF11257BULL, 0xF7C22570D6B6CE23ULL, 0x65554481A52B4A16ULL, 
            0x97C1BCD66715772CULL, 0x3F1194C5B989100FULL, 0x3F63D79CDFC110CFULL, 0x8DE372738FC5618EULL, 
            0x3CAEBE11449CFEC1ULL, 0xC2D57A04B67C171BULL, 0x76BF260151A8FD21ULL, 0x826EA5D2C430605EULL, 
            0x9BF1AA201B0697DDULL, 0xD5FC8DBE9984738FULL, 0x9796009EB87254B6ULL, 0x101DB1F225C54A61ULL
        },
        {
            0xBCFF7B93AED839CAULL, 0x45807C6888F6EBC0ULL, 0xAEBE8598B806CAEFULL, 0x29DAA62BF32D055EULL, 
            0xCE3E1BB71DA17D3AULL, 0x1FE469923A5F7BEFULL, 0x84A0344A023B2976ULL, 0x1A460E44B53739F8ULL, 
            0x1AFC02F021592713ULL, 0xBAE626CDB389B973ULL, 0x78C3BE953E36CC9BULL, 0xE8701B03E2675CFAULL, 
            0xA438412E4B1EA76CULL, 0xC2345F9668F2C645ULL, 0x9A88B673024BC36BULL, 0x0EA6B483F103FF5FULL, 
            0xD673CA2743DED957ULL, 0xA1404E39D3C126F7ULL, 0x0F04D7FD7D495090ULL, 0x6BC41E56EE62F8AAULL, 
            0x03AF8FF6FC82175AULL, 0x214AD6900EE5BEABULL, 0xBC884FABD19E261AULL, 0x2F34D863163CD1F7ULL, 
            0x738424C373E43663ULL, 0xBC5211FA73379694ULL, 0x779B6948BB258F3EULL, 0xAB717ED4095B5B9BULL, 
            0xA155BDDD86280A4BULL, 0x2D7F746CF2E60DC3ULL, 0xFA30F5C6E8B5116FULL, 0x7027775EC69882E6ULL
        }
    },
    {
        {
            0x92D21FDC1E293700ULL, 0x6BCC8AAAE2FCF2B0ULL, 0x3A9D872B2B02B2FEULL, 0xEB248CEDE3ABF699ULL, 
            0xC8950783A1CADCA3ULL, 0x45858CD82EA10F83ULL, 0x1A294C629836E3F3ULL, 0xDFFB074C1A1A88A0ULL, 
            0x3089DA2A79780D10ULL, 0x476ACD86DAC6A380ULL, 0x9780A01FDD6BF3FBULL, 0x7451687B87B408CDULL, 
            0xCD6E8573470FE644ULL, 0x3298F413287E1C55ULL, 0xB12C9AC08900E619ULL, 0x1C1772E63DA51B85ULL, 
            0xE72FFAA5BE113009ULL, 0x8DB17CC2D2BA9CC9ULL, 0xDACF3189DAFADBC1ULL, 0x133380839F9E89EEULL, 
            0x986C2E270D6A64C8ULL, 0xA460C32C06057FB2ULL, 0x8B66AB980BBFE55EULL, 0x62ACC20072C9ADE3ULL, 
            0x3B0F24B74C229873ULL, 0xC930E3A0382A0B78ULL, 0x4C4B2307F1D4EDA9ULL, 0x690B11BEFDD73920ULL, 
            0x6FF6F437F557D6B8ULL, 0x514C4AE74FAC76FEULL, 0xB7A6B6BB81B26920ULL, 0x11AF63A9A58743FCULL
        },
        {
            0x7B655FC43430A905ULL, 0x1DCCECFD57D23D23ULL, 0xB93CCCD7441CB922ULL, 0xDD2C0628555A2564ULL, 
            0x23861092BA6AA096ULL, 0x4297A4B6E6790ACBULL, 0x2FEC056F191BA303ULL, 0x675AE7C0B50E8568ULL, 
            0x3CE6047C6A0D0BA9ULL, 0x12279D7417260DFEULL, 0xD59469D91B395B0EULL, 0xC1F2442848E83077ULL, 
            0x1DD7CD1EF3A83F3DULL, 0xAB3FE034EA4FE3FDULL, 0x209E1CE2847D1E1BULL, 0x5BE934FA69F64AF0ULL, 
            0xEB2ADA9FF8738A3DULL, 0x2EFE954B83EAD4EFULL, 0x171F0060157C856FULL, 0x5AF572C9D8999A60ULL, 
            0xCADECC2F534BF61CULL, 0x9B77874894D04340ULL, 0xEE1E28C1600A4D54ULL, 0xFDDC64F82E4A51E9ULL, 
            0xF0D0A89B6E95B5D7ULL, 0x0FC9A6D88D4CF81AULL, 0x6C345F7E4148E694ULL, 0x7B4B76E7D36CFA45ULL, 
            0x8E623A3486086FC3ULL, 0xB64463C52B376B55ULL, 0xD01F15F79E079170ULL, 0xADA2D893A81ECE22ULL
        },
        {
            0x378978D1836425DFULL, 0x6F9713A3E96D4EE5ULL, 0x9D594C1486A61FA7ULL, 0x7816909975EF52D1ULL, 
            0xA216744BA8D016D2ULL, 0xB0EF547C5456A9B6ULL, 0x0AE29A9039A946D0ULL, 0x714B1E2045CF12A4ULL, 
            0x1BE16F1B28A9FB47ULL, 0x2F6BA216DDB7050AULL, 0xE8CDCAF6FC672F13ULL, 0x1C8D207E686B6B9CULL, 
            0xD9502F5074965656ULL, 0xB6BC09362D6FC610ULL, 0xD26C9052E23F3B86ULL, 0x54DB11AE43FF373FULL, 
            0xDDFDBC2EA9960914ULL, 0x72EAFA7D0D52C7BBULL, 0xD8714407BE0624E1ULL, 0x54FDB46102C1C574ULL, 
            0x13AB09837F8783D0ULL, 0xDA75FB25C29DE90FULL, 0x2CADD0AA415F3AA4ULL, 0x254DB18DFA1FEF51ULL, 
            0xB73025E61E438C23ULL, 0x617EE790D829851CULL, 0x859FB4259A223752ULL, 0x5483CA25EFF77714ULL, 
            0x97FED4147930E2CBULL, 0x17B6207B879FB438ULL, 0x8D408A8B09D000BFULL, 0xD52CDFE5F03B492AULL
        },
        {
            0xE1713925647F870AULL, 0xF85ADBB5C6DF4CF6ULL, 0x0FDEFEB7401E19F3ULL, 0xD17F76BA0272CCCFULL, 
            0x43641BC8FCD94A47ULL, 0x29FBA7EBF9E70F83ULL, 0xBA65CE5CC8EE0042ULL, 0x4581AEB02DFEDD44ULL, 
            0x8B56B3D2EC3FF013ULL, 0x4BAA54DD8F46C25DULL, 0xFDDCD1CAAAAA9F2BULL, 0x9AEF8F32A9063F84ULL, 
            0xB00EBF9E62AF8119ULL, 0xA71BFBEFD79EADA2ULL, 0xA155446D0BA53BABULL, 0x0EA310777C401E3AULL, 
            0x624C1872C0A38D30ULL, 0x5767AA100460E6CEULL, 0xF71BD79DC96BE49EULL, 0x1F42561CF5BB54F5ULL, 
            0x1A7B9941AB1DC67AULL, 0xA5044329ACD377E7ULL, 0x4849D01381AF04E5ULL, 0x88B326E98D6CEEEFULL, 
            0x8BBB1D1FCC88CA0DULL, 0x31BACAEAEB2651A1ULL, 0xA2B938614676B00EULL, 0xB2032DF68960A1C2ULL, 
            0x8ED5C50D8CAC39D8ULL, 0x83D0FC9B8A6B8D8CULL, 0x87217152EBD2B20FULL, 0xF3F1D66850B72084ULL
        },
        {
            0xE44058B1B4B13FB5ULL, 0x2A201DBAD3EDAE8AULL, 0xB5E4AB44204A63C0ULL, 0x4618737AF6A5A590ULL, 
            0x93763023BA42E012ULL, 0x293EE7820A2A45C7ULL, 0xABD43540104A1077ULL, 0x1259869D48182B97ULL, 
            0xD12102F8A2D1D3C1ULL, 0x2AA46DAEC3E9E103ULL, 0x3860126C80D576B8ULL, 0xF74A3CDC28734B43ULL, 
            0xB125A6F37C1BE74DULL, 0xB8F73ECEBC2E8044ULL, 0xFA880E0536067F8EULL, 0x2EB4B3DB38F6D4BDULL, 
            0xEA42AFA3E783976AULL, 0x9A340CD2CBD9D330ULL, 0xE7CABF03AE7D7AEEULL, 0xAA090F98F85E8BCDULL, 
            0xF5FEEC0F8FEB0642ULL, 0x7642935B94C36585ULL, 0x7D1FCCBC44E6C9AFULL, 0xE2581061AC5B4582ULL, 
            0x6BDFB8FC0FBD4D7CULL, 0x36492F2B36096449ULL, 0x50B0DD3C5B50ABDBULL, 0x07549E3035580E43ULL, 
            0x53A5E5A2DCE4ADDCULL, 0x4B1E319A7F21B78AULL, 0x7CD82688ADD31AABULL, 0xD56B792916BDED75ULL
        },
        {
            0x8480953D98488694ULL, 0x96D15C3F2CF72B39ULL, 0xD360AF5763994CFCULL, 0x255449DDD2CB835BULL, 
            0x5FBEB973ADD03B00ULL, 0x23836A512A5AE1AAULL, 0xB341BF297790B717ULL, 0x83063294E318A1B2ULL, 
            0x4407A2DAE9F3B705ULL, 0xA42F21CFB522AD7EULL, 0x78A18DC3165C9600ULL, 0x545D6A89CD671008ULL, 
            0xD28F9519E59ED32CULL, 0x4ADB15D753C8D635ULL, 0xFEDAB005FEF28DADULL, 0xE649160FC7576222ULL, 
            0xCBACC396273E6B3BULL, 0xFC6C2EBE24D5C342ULL, 0x28E50CAB2FE456F1ULL, 0x3D0B11F1182115B0ULL, 
            0xACBA509BB2CE5E04ULL, 0x083119824D5A352FULL, 0x17CC816C3F4DEF72ULL, 0x33D5C009FF09092EULL, 
            0xD61AB3D9CC3688EAULL, 0xDABAA3636DED3441ULL, 0xF300831D709B9780ULL, 0xA8D17C9DDE02F784ULL, 
            0xFD464760088E5C8EULL, 0x9E95E7819C2DA994ULL, 0x3F96AAB67115503BULL, 0x688EFC1F5774C9DFULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseAConstants = {
    0x401D5146BD3AFE49ULL,
    0xC3346DB35DCEE631ULL,
    0xABB97722AC8F734AULL,
    0x401D5146BD3AFE49ULL,
    0xC3346DB35DCEE631ULL,
    0xABB97722AC8F734AULL,
    0xF5D81CDE1512B445ULL,
    0xB97211DEBC9A58BFULL,
    0x1E,
    0x02,
    0xB6,
    0xDE,
    0xCB,
    0xA5,
    0xA1,
    0x4C
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseBSalts = {
    {
        {
            0x774701DFB09F0E3AULL, 0xA998B46A2950B015ULL, 0x7C4E3220D1775801ULL, 0xADB10948ADA91646ULL, 
            0x534B354ACAF6E31FULL, 0x980541CD4E5A709CULL, 0xD2A19AE7847B8FDBULL, 0xC6F271B57984AECAULL, 
            0x7C0410EA89E5CF09ULL, 0x3C616575A7C51D08ULL, 0x15C85EDD58F99019ULL, 0xE95976C3F2433DE7ULL, 
            0xC2794DA54B856354ULL, 0xBC5E442C358ADD54ULL, 0x6A7853FFB4A1F41DULL, 0x322285538746B8D8ULL, 
            0x30852D2FC1B91656ULL, 0x19BA8DE146BFD221ULL, 0x418608E08533B262ULL, 0x15BF709C2063C4B0ULL, 
            0x5EA75A390E4A2997ULL, 0x19AD4622DA1EB746ULL, 0x3F498A72349A0F38ULL, 0xB86FF2A22F43A0EEULL, 
            0xF071C0CA28675BAAULL, 0x965C05977BE1EBF5ULL, 0x4D0BF8CE2048B0F7ULL, 0xAAC9A9BF4F14FBD6ULL, 
            0xE0F6F42E1C8216FEULL, 0xDD6D541DBC617E97ULL, 0xEEF8CD38A75F8797ULL, 0x1DB9F1264AF185EBULL
        },
        {
            0x08DD6C4D8C20A656ULL, 0xAC570A1A0E4BAF09ULL, 0x94B4265F1B79421EULL, 0xE5B770747FC2525DULL, 
            0xB96A2D820B5C1FACULL, 0x2EB3A21B89E304CBULL, 0xD9540B32A2DAC08AULL, 0x8F06B128E9B6E454ULL, 
            0xC13E03A47C48D0E1ULL, 0x690920715FC57216ULL, 0x7D158748AD9E7C6DULL, 0xF95C811C8D3161BBULL, 
            0x19730C26C06357AAULL, 0x210273090ABBB3DCULL, 0x48F903C08750191FULL, 0x8DD9B95F8F47693CULL, 
            0x6EA1CE1CF2CB4C52ULL, 0xAAB19CC3C7257487ULL, 0x138276C06ED4A633ULL, 0x436208A741898263ULL, 
            0xEF71BC41B74810EFULL, 0x2139F1780642029CULL, 0xD45E92B7DF61EBCCULL, 0xFC8683C4491AE641ULL, 
            0x6D9EDEC23F3C938EULL, 0x1E9F53816BA3B34DULL, 0x22AEC5BECA5F614FULL, 0xA8256BEF13519BFBULL, 
            0x0A9BCABC56385B0BULL, 0xB281985E4E84749DULL, 0xC50B84C823CEC32DULL, 0xDAA7635C8FBBE0D2ULL
        },
        {
            0xAE551A185693D1F4ULL, 0x9B011B59CC27F723ULL, 0xD56997609551D615ULL, 0xC30DFB41348093FEULL, 
            0x8474E7C835A4C3B7ULL, 0xD154582C80E5EA47ULL, 0xD226CE7BCA549590ULL, 0xD52BA1A800DF0C5EULL, 
            0x4431A90F030C41FFULL, 0x330F1804F687077FULL, 0x0A8386AB7B10AADAULL, 0xC77534E3FDF2B1FBULL, 
            0x2B52471E0889B5F3ULL, 0xAE72F2D447E9133EULL, 0x6A9647351F7DE2FBULL, 0x0F280BD5293FBFADULL, 
            0x2361DE93510042F1ULL, 0xA3534F6C54B636B2ULL, 0x65E90C36F08909BDULL, 0x8CDFE3F39A872407ULL, 
            0x1E6E0CECAC14E60FULL, 0x700CE35C0F738114ULL, 0x0D256F5D9AFAFF77ULL, 0x0E58BD98E9D5A238ULL, 
            0x47B9CDDBC7012D91ULL, 0x7C86D81D53F3DEDEULL, 0x79C98C202FE2ABDFULL, 0x5CFEEAE987BB94ACULL, 
            0x7F35333FDF7D27A2ULL, 0xA37091A735749D26ULL, 0xC87F34264230AE2CULL, 0x0838F4D5D6B637A7ULL
        },
        {
            0x7534A442004626B0ULL, 0xF1603F7B8EC85E1FULL, 0x71143C2395E3FABCULL, 0x0FB5E1B3DC07B89DULL, 
            0xD5EEF414E6A438D3ULL, 0x762204CDC240B857ULL, 0x35B20E68346F3765ULL, 0x1DFBD414775F7BFEULL, 
            0x78446E7B5194091BULL, 0x5DA7C93DC1101364ULL, 0x0DD4D162A25598E2ULL, 0x1678BFB245D2770DULL, 
            0x9C2024C6DE249488ULL, 0xE03BF825CE7E117EULL, 0xF83FA3345CA1498DULL, 0x058179E9C36220BBULL, 
            0xC355D8389FF78B58ULL, 0x3E04355D6CD4B590ULL, 0xCA69627D280D7B2CULL, 0x414C644B6195A5C3ULL, 
            0x08CEFA42583C5A0FULL, 0xF0808D816B3CBCCBULL, 0x351827BEE7F2FA65ULL, 0x7E67322D5DEE841DULL, 
            0xE1561822D09D895BULL, 0x1C1CBA9B952209E8ULL, 0x26BD779DF56E9358ULL, 0xAA7788B7B5233A35ULL, 
            0xAC3DD735DFEE91A8ULL, 0xFC90B96C16E7D79AULL, 0x8C63944E463C4761ULL, 0xB9236C89E031A5A4ULL
        },
        {
            0xCE22D795194E3504ULL, 0xBBA7945F308BF0EEULL, 0x3EBC280445A1F508ULL, 0xAAD512A5BD29CDF5ULL, 
            0x33020AD42DCB1174ULL, 0x336AB43AB001441FULL, 0xE2926FFDC3DEE7CFULL, 0x61CE8B5B6519CB17ULL, 
            0x1D708E8DCB55E11EULL, 0xE3D4ECE9933844B2ULL, 0x493B7C1601E15E59ULL, 0x3986DF6C6BDD0638ULL, 
            0x17254731DCF1E757ULL, 0x8C3192D9D10A3B93ULL, 0xCF7A1BA6C6A4461EULL, 0xEB8F408A9C474E63ULL, 
            0x85D457B68DDF7230ULL, 0x7129C7911E642B0BULL, 0x9BA5C72D67F2C0EEULL, 0x05CBEC1F66F5AD45ULL, 
            0x70211D2C57A84DB0ULL, 0x1A4E17ADBF7B9751ULL, 0x0799F353FFAA9B96ULL, 0x9371885312B33CECULL, 
            0xEC73DEF523310631ULL, 0xA974208E0540E7D7ULL, 0x49E6D59321A1DF86ULL, 0xCB5BC71FE7ED7091ULL, 
            0x12997B9080158D9AULL, 0xE54EFF3B71C3F340ULL, 0x97EFF28B61163EC2ULL, 0xDA18FBFA670BE968ULL
        },
        {
            0x0BAE427FD62F7138ULL, 0x1B38168B4D5E5492ULL, 0x4C12F9B80A91EEB1ULL, 0x4B1B6F6A4250125DULL, 
            0x38993064BD107325ULL, 0xBC38687E0153C728ULL, 0xC64FF09F8026E01AULL, 0x998822D693ABD7C6ULL, 
            0x51D7E0324EED4F07ULL, 0x764E2CDC7B85359AULL, 0xA5F59AFC07A4E190ULL, 0x7B8A04122DEE2244ULL, 
            0x23C1531696B8B682ULL, 0x54976646E0D36DA7ULL, 0xF52020FAD6473D4BULL, 0xC2C8FDCB92846986ULL, 
            0x88ABB788098A65EBULL, 0x460878DFFDB7B5BAULL, 0xE7659B23D0D5AE61ULL, 0x4B3FACB5F300AF08ULL, 
            0xD6564CFE956A17D5ULL, 0x6708609D140B8D0BULL, 0xD89903658FE48160ULL, 0x30BE6593F2D24D47ULL, 
            0x8B90A9EDFE5E8599ULL, 0x442CA5604A014326ULL, 0xE7B2569A9069286AULL, 0x9794D78283EED7B9ULL, 
            0xF0381CDA97EEFA09ULL, 0x137E50FA7B96F3F5ULL, 0xF80447178466964EULL, 0x455184CEDECF7A4EULL
        }
    },
    {
        {
            0x13C076B23EBBEE22ULL, 0xC5D480BBFEC01B8EULL, 0x9FC53A35F6BB86C3ULL, 0x5B081E86C7329628ULL, 
            0xD7A313763C7A01F6ULL, 0x06CAFAB3E6376FC9ULL, 0xF63E8A61D3127881ULL, 0xCADB5DD0DBB834B7ULL, 
            0x30115EC716631ED1ULL, 0x79EC1D73D664FCCBULL, 0x4A848B512D7C064AULL, 0x50D1348940DAB9CEULL, 
            0x02808ECD1A1A64AEULL, 0xBDDE64659C9F6FF6ULL, 0x0E7826DD9AFBDFEFULL, 0xA8CB49A9912307D1ULL, 
            0xFD9322B2F6B3378AULL, 0xB3EE77AD75BE0A23ULL, 0xB89D5BE35A27E246ULL, 0x93800E9D0C39699FULL, 
            0xFA94F506410FDA87ULL, 0x11F7DB6ADA9C7F0AULL, 0xCC1F93B038D81477ULL, 0xB0E943E3CDAD37D3ULL, 
            0x07A963B10ECEA709ULL, 0x2791154F76770D3CULL, 0x8BDB4F8D69E17251ULL, 0x7DEB7FA62C5C17ACULL, 
            0xFC25FD4D2A399CE2ULL, 0xB61667B4540C7ED8ULL, 0xC6E7FFF9DAD44379ULL, 0x1E3C64CB0418FF7DULL
        },
        {
            0x8077AD062795D74DULL, 0x668D27A9D2C6323CULL, 0x41D258457739E8E6ULL, 0xB56D348A90DDC44FULL, 
            0x5E52146C616ADCFBULL, 0xF0E0564F8BBE90C0ULL, 0x5383AB85C80908FEULL, 0xD8573D1C8B6216C3ULL, 
            0xD131A9390A6B7E80ULL, 0x3AF0C75BFF3583AFULL, 0x5F226E7577F6E6F8ULL, 0x9E92DE53EB613B7CULL, 
            0x6A4326B2E732EC53ULL, 0xFC50967EDCD28B22ULL, 0xE9D202CE02614D62ULL, 0xE0BD79EC0072551DULL, 
            0x6887169A040666F6ULL, 0x92A5E06CC27ECB8AULL, 0x50AE1FCD48379E43ULL, 0xD5BBC4B76C3BE7BEULL, 
            0x64DFBF08D3E29CECULL, 0xB868FA83B55DA7D7ULL, 0x9F03ADF7EAFB9C98ULL, 0x2EB9E505442B3F61ULL, 
            0x60AC27853A95E6A3ULL, 0x6845BBF6D532C774ULL, 0x61974302E6E9208FULL, 0xA6E96BFC642EB570ULL, 
            0x9EF005CEBCDCBCDFULL, 0x0613D26774161AC8ULL, 0xCA03A615BF77CA3AULL, 0x5CD754A60FBBB0D9ULL
        },
        {
            0xCD0C3D89A7845DC6ULL, 0xCC873568FD451F4DULL, 0x97D62A871FBAD1E8ULL, 0x91B25D01FE1CB35EULL, 
            0x7521DB828AD66AC2ULL, 0x74477F47AAAD6B71ULL, 0x210F5BAD970A8C55ULL, 0x6DC294A066D10759ULL, 
            0x55D5CC91DAE6227DULL, 0x30D9BCCCF5ECF9FFULL, 0x15DF5BB0528A8779ULL, 0x734F20EDAEF23FC6ULL, 
            0xE06749A42A1691B2ULL, 0xC55B05D97738E4CEULL, 0x49CB30AC99616DDAULL, 0xCF8134B673DE2B95ULL, 
            0x24656FC0B27DACECULL, 0xCD7284584F914059ULL, 0x0FEDA1481C962E30ULL, 0x7AD0C9B8DAEA2E8AULL, 
            0x03E953095C0A7307ULL, 0x8D2F0F7FD48CEA11ULL, 0xF11E03DC97504601ULL, 0x2DE06246DA4AAB19ULL, 
            0xD9EC07B2A94D050EULL, 0x61F94318C2A2F31EULL, 0x02C77A4CEDA7480CULL, 0x5E56EC09CE65D44AULL, 
            0x467A5570D8198636ULL, 0x689D91E32BA4CD8EULL, 0x198AD82E3B3F3FE5ULL, 0x1C350ECF5AB7A564ULL
        },
        {
            0x6978BAA9981A2217ULL, 0x1E347E510E5EC131ULL, 0x0A9A5AB117741766ULL, 0x13C4602517BD5FFDULL, 
            0x5649EFFF2DFF1527ULL, 0xE2E3F53262DD08A0ULL, 0x8681AABD6EEF26B2ULL, 0x57F94E9494A8FF40ULL, 
            0x9BFDA96A7BDF5CF1ULL, 0xEC4F0F028B335B15ULL, 0x797A35CBF09E565BULL, 0x353A08EECC4D22EBULL, 
            0xC397D38C024D297AULL, 0xE7AED666A6B5146EULL, 0x2C037C2018C27023ULL, 0xC17449431ADA2F10ULL, 
            0x75C881D7F12CD6BEULL, 0x975D190A15D70459ULL, 0xAF5ECD98910BA9E2ULL, 0xB931CD443921E41AULL, 
            0xF6AE8AD89BF1F369ULL, 0x28F2CF85F205E348ULL, 0x5C822BAFC7E6AFDCULL, 0xEFABD8138153E5A0ULL, 
            0xAA218562E632DF3AULL, 0xCA69BE518253F564ULL, 0x1701EB245CE56346ULL, 0x61CC6EDF6D006C7AULL, 
            0x7394D2D15597D9ADULL, 0x8D548ADE8D747DDBULL, 0x86B58F0161309D7EULL, 0xC2454FB44C1FF5C8ULL
        },
        {
            0xFACC197B98885E2DULL, 0xD99A4DA330FF6AA8ULL, 0x14811716B226586BULL, 0xB796DFD7DD3F3D86ULL, 
            0xF2582DC04259360CULL, 0xEE96053E947EB755ULL, 0x456314D9F14D8AAAULL, 0x9AA0E9F054B84895ULL, 
            0x789CD8DC0EECD423ULL, 0xCF0322C4DCCA4693ULL, 0x96A6F6F6895B6564ULL, 0xC8A1EBC00A56A67BULL, 
            0x3C6A70B9E3064F50ULL, 0x58A5BDD07782F88BULL, 0x9F7BDCC2A0F7D49CULL, 0x51D6D0ECF03FA64EULL, 
            0xE7604382FD07ED1AULL, 0x117DECB33DE3F8B3ULL, 0x93B74C941E99BA7DULL, 0x01DF3B99EEFD2F39ULL, 
            0x30F51004F1931815ULL, 0x518D598FA04A8A40ULL, 0xFD88D259D22F8FD2ULL, 0xC59DA1788E9CB39FULL, 
            0x916CAD45F37E68B8ULL, 0xDEF0CAC34AA57298ULL, 0x829B48BA918442FDULL, 0x8E9D9EB327283975ULL, 
            0xD01269EDDCA76FA3ULL, 0xBDC769ACE715DB5AULL, 0x02C69FCD673A7E85ULL, 0x20AC6413BF1FF737ULL
        },
        {
            0x96200CF2BC562B06ULL, 0x09C3D9C45C24F310ULL, 0xA2AB9DDA1C833FE2ULL, 0x7F741B183150B8A7ULL, 
            0x659F42703C386459ULL, 0x4F874D71F329DFF9ULL, 0x5A70ABD126AC9988ULL, 0xD2906C35B3ACB649ULL, 
            0x17B73D6DC262C5A7ULL, 0xD4FF2ED50CDE56D5ULL, 0x4C39B578BD4AFF5CULL, 0xD71DFE252BD105B5ULL, 
            0xE1021410FCB851B4ULL, 0x31787EABCEFE1FA5ULL, 0xA2F0ED667F824AE6ULL, 0xFAEA73FC702515EFULL, 
            0x3E2C17A1AE150777ULL, 0x505B22C2F3927035ULL, 0x4CAA29ED4A093430ULL, 0xEE5D1DEB7134F1C8ULL, 
            0x1B88E102393CC186ULL, 0xE2EC9FDA68F49718ULL, 0x8CEF4D745EAAB147ULL, 0x2975E304BDB973D9ULL, 
            0x23D1154B48969E09ULL, 0x79BDFEC7F08CEC17ULL, 0xB4C1D849494049AEULL, 0xF07A0A5D519ACA8EULL, 
            0x07CAD36773F0596AULL, 0x5D321302FAA73D31ULL, 0x791D9034BEB555F2ULL, 0x8E58C451C480974DULL
        }
    },
    {
        {
            0x4A490762C9A49D57ULL, 0xBFB4698008268A72ULL, 0x73DEE4A27388C3A0ULL, 0x38CEC6EF2A0A1CE1ULL, 
            0xDB2F2362664E5CE2ULL, 0x8647EC31300C75EBULL, 0xA31A6A9514DE47F9ULL, 0xC664C5216CC9FE42ULL, 
            0x2C9D490E8589A883ULL, 0x5CC55BAF5833D3D2ULL, 0xA797AE91F35E3D84ULL, 0x3940397968E53BD3ULL, 
            0x50E67F20CBD309DAULL, 0xF937CDC3B8F48EDBULL, 0x04A205419DB92EB1ULL, 0x5F013CA1DE73DAB8ULL, 
            0x6AB6F7927998AD85ULL, 0x80BC4658D255C00CULL, 0x07498CDA2E980B99ULL, 0xBD28F871BAC1B99CULL, 
            0x159ECE21A9A747DDULL, 0xE1DCEA6C5065A142ULL, 0xA1FD0860D42D8613ULL, 0x77FE47F5B3A78833ULL, 
            0xCD15B642B01D3C91ULL, 0xF9F7EC65127D4485ULL, 0xE155E83EECDEC3DFULL, 0x9D6284C3A5FB9A5BULL, 
            0xACD112200DEC6788ULL, 0xC750858608FA85E6ULL, 0xF9BF53796F381231ULL, 0xB6E3567B8B09A79DULL
        },
        {
            0xB75AED8B1BAC222BULL, 0x16EDC3810B57D3CEULL, 0xC2C8EA504704C86FULL, 0x241516DD0C8317BFULL, 
            0x40F55DB86623EA4CULL, 0xCCCDC39D0481E3E4ULL, 0x6FADC634EC6CEA13ULL, 0xEE84F130F65DDFFCULL, 
            0x475C64213BE5151CULL, 0x7947B83AE2C08D8BULL, 0x08BD150E11AC4FDCULL, 0x4031611C266157D0ULL, 
            0x97624CE09387BC02ULL, 0xC5610B36BFD0E5FAULL, 0x5B63F413FD061879ULL, 0x09682E2CBB1607A3ULL, 
            0x3E7ECB124E25718FULL, 0x86F74FFEF45CCD6EULL, 0x110CC9466C6B6A1BULL, 0x6D867AB6EA085850ULL, 
            0xBB67ED3C4C8F8A70ULL, 0x7FD20E6724289848ULL, 0x275D2C5632F7BEA0ULL, 0x04E01FE93BDCC778ULL, 
            0xF61732B9FD5DCA67ULL, 0x2C11B7D780358B8DULL, 0x5B98FD442FC9B287ULL, 0x2A34EAB7C00080D8ULL, 
            0x4977C01C681F83C4ULL, 0x2837339B2ABD2F38ULL, 0xCD6C327DC8227937ULL, 0xDBD731A128E5D1DDULL
        },
        {
            0xCC31E5FA28BAA29BULL, 0x3EA90753E0536762ULL, 0x8BAF9CF6FBF6C588ULL, 0x9C31398310EA71E2ULL, 
            0xF7F2A8FE7B1176DCULL, 0xE9E91E24BA90239EULL, 0x55066C5025F75B7BULL, 0x29FA6B548410B75AULL, 
            0xE8C5FF1FC26AE486ULL, 0x379052645AEC1AB9ULL, 0xAC20C0664141FC87ULL, 0x24CCA8606EE38DB3ULL, 
            0x084B06D08CB4B9DBULL, 0xD11F6C91E7229F9CULL, 0x427146C0A0428B42ULL, 0xFE9E398C0947EEA4ULL, 
            0xC59F126F7C57275DULL, 0x127009211C148669ULL, 0x7024A32D0BE5FB12ULL, 0xAD1F6A29518F5ABAULL, 
            0x816535643ED4C1E8ULL, 0x2EA986C007AA5C9BULL, 0xCC61D82CA18AE4DEULL, 0xE6AB26C730AA3657ULL, 
            0x8625DD5848ED5363ULL, 0xBA8257DE1B83C131ULL, 0x30ED84D9F76DA147ULL, 0x5CCCBDB0AD9B5D9AULL, 
            0x00E1AB3153F2FE4FULL, 0x8F770E4A5408E484ULL, 0x2C7059CAC3D0270DULL, 0xEC0CBB21A2B1B1CFULL
        },
        {
            0x03258C69D389E89AULL, 0x7614F931E6852E68ULL, 0xB456677D7AE8329EULL, 0x7DADA5962CF614FFULL, 
            0xF989411B1929052DULL, 0x0DCE835C7DC3820FULL, 0xA90DA5D35AF38744ULL, 0xA9A7253F13E8F79BULL, 
            0x5B29C0A614F884BDULL, 0x4B639BDA356D9F0CULL, 0x6B04A6F6C0E90CD1ULL, 0x5103C141081838CFULL, 
            0x0DC66EDC126D4863ULL, 0xE3EF0A80B394C819ULL, 0xE8CA8396A2CB5B4CULL, 0x19F7A0A5B7009B2BULL, 
            0xABEB594F81FECFDAULL, 0xE8BFD7596BC67003ULL, 0x42BA3860714C87B7ULL, 0xB7B159C481F90A0BULL, 
            0x2B290E01893632F7ULL, 0x070BB72DF690C197ULL, 0xD035EB8805D0AA58ULL, 0x3CC1DA3B01C336FBULL, 
            0x93C575B141E5FC61ULL, 0xD75770F83DA86AC0ULL, 0x5098AFFAB8DEBCF7ULL, 0xFE674A13C6770C18ULL, 
            0x86ACB836E0F684F4ULL, 0x325CD3E661477637ULL, 0x125CE58FB164C9A3ULL, 0x052747887E9029E4ULL
        },
        {
            0x9BDCAB43B57F40AFULL, 0x8BDCA8ECDA9BD86BULL, 0x8A37FC2806C74F87ULL, 0xBF71C268A966CAA8ULL, 
            0x0B76C5738A0246C0ULL, 0x212F9A8F3877C495ULL, 0xD6310F880EABFBF0ULL, 0x5CD0386A47A50AD3ULL, 
            0x425082172A654481ULL, 0x0DCD50C4D5DE7A59ULL, 0xD385EB05D495C7E5ULL, 0x998F9E90BC3A1D8FULL, 
            0xDFECDA4E9803B223ULL, 0xCABC04F10DDA0FC4ULL, 0x17AF9215B8DCFEBBULL, 0x02F3E072D208C68BULL, 
            0x491576124280AA27ULL, 0x624DB24DF9F4DF43ULL, 0x14D28BA77098E0C0ULL, 0x5567F063E60AAD63ULL, 
            0xFC536A84635F7CB9ULL, 0x78CDC89366C033E3ULL, 0x9C8611590D7A44F3ULL, 0xB231AB9EB3F425A7ULL, 
            0xF531A64122C63134ULL, 0x7E58448AB4BFC076ULL, 0x18EE6FD185726BF0ULL, 0x54D49894519DE588ULL, 
            0x4FCF84EDBFD26E65ULL, 0x1C45DDD532AA38AFULL, 0x91E4639B9EEF0281ULL, 0x9CE1E88758E1A7D4ULL
        },
        {
            0xA74C64B59750C9CFULL, 0xAC80086A16E8DE16ULL, 0x2EAAEDAE3E51AA2DULL, 0x4A4453C219BC1085ULL, 
            0xDDD18C39075BC747ULL, 0xD14C16DD04E56984ULL, 0x528DD08468996E77ULL, 0x496A86F9FF4DEF70ULL, 
            0x1B40A36EB3EF118BULL, 0xD4E96E0DDDD563FDULL, 0x088823072178D1A1ULL, 0x3022A91C31E74823ULL, 
            0x496BB076D5AFFDB1ULL, 0xA1414626CF68173CULL, 0x25A4485378B2E1E4ULL, 0xDA9136F5946E00EFULL, 
            0x5FEF4553D48AAA16ULL, 0xB7BD870218E625DDULL, 0x6BCF8DC92DF7DA86ULL, 0x2502893EC9FA32B3ULL, 
            0x4FC85024F34552C2ULL, 0xC7F73F72DB681AD7ULL, 0x6C8BC51606402FBBULL, 0x15508F92D99B6FC2ULL, 
            0x64B21441E9DE7CDCULL, 0x7BA162E96DFB415EULL, 0x2786E4AE0B6B483DULL, 0xD4D3425D4EEEAD86ULL, 
            0xBBC97A447FFA53E0ULL, 0x26CBD9C7DD289CB4ULL, 0xC344D71F657C34ABULL, 0x5A1FEE2889950B98ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseBConstants = {
    0x6D6BEB290DD32B7EULL,
    0x2E3CCC4B888B00F7ULL,
    0x895BC044D5EB1153ULL,
    0x6D6BEB290DD32B7EULL,
    0x2E3CCC4B888B00F7ULL,
    0x895BC044D5EB1153ULL,
    0x31EA9F4C901FD8B0ULL,
    0x9738864686D46120ULL,
    0x2E,
    0x15,
    0xDC,
    0x2E,
    0xAF,
    0x43,
    0x52,
    0x9F
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseCSalts = {
    {
        {
            0xBA592D0B28459DECULL, 0x2903319568DD6ABCULL, 0xF9BC61318CCD6696ULL, 0x7FAC30F65D5DACF6ULL, 
            0x41C307CB60EEA76BULL, 0x85EB982251D793CBULL, 0x18EFFEAEA215CB4EULL, 0xFB3B8596E3E0B35BULL, 
            0x1955FAD471EA0005ULL, 0x9F3D4221EB2FBA7CULL, 0xED87366D3A5AC612ULL, 0xF407E7BC1CF5E79DULL, 
            0xF3B2106B5DF6DE0AULL, 0x52F685AADA8B6D17ULL, 0x7A2E26B038758BCBULL, 0x232DF96327C21F6FULL, 
            0x3FB7BFAE8F032589ULL, 0x4C702DF85E75C241ULL, 0x22D3145101D48797ULL, 0xEE7898A7D646F6B8ULL, 
            0xA3960F5647D78F1BULL, 0xB5CDBC62DAC7EABBULL, 0xCE851C2824BA8242ULL, 0x541CB1EE0F7C6C3DULL, 
            0xC3535509B26D3675ULL, 0xD360E5F8DF00C5C7ULL, 0x5C062DAF2738D825ULL, 0xF5E17632E92D18C2ULL, 
            0xC09499CE5F9342F1ULL, 0x1E6A366646E7B2F5ULL, 0x66BB874C4F65D78EULL, 0xF22F171E9D5071BCULL
        },
        {
            0xE16DF5407F87D176ULL, 0x146E49E49857FB8AULL, 0x29D73398848A5F2AULL, 0xE188A573F3DAB1F1ULL, 
            0x1A28A982AD654C7BULL, 0x2D94A4B2C5CE8DCEULL, 0xB34FA6F5B498C4D8ULL, 0xCF47EC47D6910BD0ULL, 
            0x3FFD1BC1208B6A96ULL, 0xD3E4B8BF1F7A5382ULL, 0x17031EA9ACB4EB95ULL, 0x2568304F5959D2CDULL, 
            0xF60C8F1C8E4BC149ULL, 0x7DB4457F5C53EABDULL, 0xBCD79E0AD48786F5ULL, 0x8496E67C0DD3368AULL, 
            0xD55519218BDE72A0ULL, 0x4D08677CE80060C5ULL, 0x9D5DA6BFCF225937ULL, 0x2B985D27BAC682AEULL, 
            0xAD4EBFFA94A16E33ULL, 0x05A41A0B0A0EE095ULL, 0xA70FA38172BBBDB1ULL, 0x852D74C7373B2775ULL, 
            0x1562BD1381B70116ULL, 0x258EE35C2C14230AULL, 0x24BB57C9A611CCB3ULL, 0xF237D67C2A63504CULL, 
            0x8CAAA6E4BD6207ADULL, 0xFB5476DEC7247584ULL, 0x85BC544663040FF1ULL, 0x07A2E8094A651E9BULL
        },
        {
            0xB36A37D6C6A255A5ULL, 0x21EE65AA8357CD62ULL, 0x5C9D311CB6562B69ULL, 0x67B5BBC45168AD4EULL, 
            0x8C2D1C49096C1D4EULL, 0x1B6DD7AB6BC2C663ULL, 0x10D1F9E57993BC9FULL, 0xC6E4760631EF525FULL, 
            0x8DCF4628AF238E17ULL, 0x95DF7BF013DD2262ULL, 0xE1CC8878B194E006ULL, 0x144A94C68FBC00FFULL, 
            0x97AE7E1DC4A1051CULL, 0x1F5AA42381045236ULL, 0x344F1EF527A54E3FULL, 0x3AA75F67F7108176ULL, 
            0x4327CDCEA848DAE3ULL, 0xC8B5AB92CCC8EAE1ULL, 0xF66A8806EB2EFFDFULL, 0x72A9C68E447124C0ULL, 
            0x00F4A6D824DE7813ULL, 0x7327623A121940E4ULL, 0xE7D9293F76FF74A6ULL, 0xB057DBD325C7318FULL, 
            0x4F80E0CC0295AFCBULL, 0x2A8BE9A2252B2ED3ULL, 0x98FC2BFBBC50702DULL, 0xDE934EB7CECEA191ULL, 
            0x78D781070A29B3EDULL, 0xAF09EB810EE5821BULL, 0x96F9628433F10566ULL, 0xCE86163EC282B275ULL
        },
        {
            0xD610904EDE4998EBULL, 0xBA84D09099A0E973ULL, 0x76F57BFDF52DB76BULL, 0x49B430D55A181B22ULL, 
            0x46DA29E7C626B593ULL, 0x16801ABAD920243EULL, 0xD265DB3D4CC381DBULL, 0x4005C7FD54E88F66ULL, 
            0x44C198657AA9DA63ULL, 0xF991F6574A846161ULL, 0x2C00C00CA5E89155ULL, 0xC38239A1E0188207ULL, 
            0x5E5726B9CBC61230ULL, 0xD0CC6152D0EA8211ULL, 0xC713586EFC13F84BULL, 0x9E9F8E10E520B141ULL, 
            0x4382E960205D131FULL, 0x0673E32E8E047BC3ULL, 0xBD91CADEC4DE8F33ULL, 0x6DAC0E8568A0D264ULL, 
            0xB9368FDC9C8F44DBULL, 0x81992DD82018A0E3ULL, 0x5DDB62E8A8EF5DD7ULL, 0x3C680ED583577D49ULL, 
            0xBAAA0D4D111B8B69ULL, 0xE6DF506F99F0AE0AULL, 0x51A271548EDF54DCULL, 0xDABF0FACB172BE0AULL, 
            0x3BB06ACE672ABA2CULL, 0xCBF2835F4A3FECC7ULL, 0xE528DC0FE73A78CEULL, 0x3F32EB07322B5D20ULL
        },
        {
            0x987D888748F8AD24ULL, 0x7D826E56CF8E8722ULL, 0x676B4F59275BB766ULL, 0xE1FD20F47044E3E0ULL, 
            0xC1A35F2E33DA8BD2ULL, 0x3B1B96B0BF667EEDULL, 0x4801825EDDBFAD74ULL, 0x19F160611E69EECBULL, 
            0xDFDA9BC2C11B8197ULL, 0x938DB8689EC9A36EULL, 0x9F2E484E7ED921B3ULL, 0xC6F13B8F940AB39CULL, 
            0x0970BF1E8E0887B7ULL, 0x1736D1AE95278C37ULL, 0x4B023452C9A79E95ULL, 0xE3066B6F2CBF98BAULL, 
            0xB3B8BEC2DCD88275ULL, 0x94571858BE5F5FC4ULL, 0xA857CD48C708987CULL, 0xEC3FC84E224CD730ULL, 
            0x367E07E1373151EDULL, 0x6BAB01A632137902ULL, 0xAA29D4524A442161ULL, 0x21B846075B30FB15ULL, 
            0x717824AAD7E13D93ULL, 0x4A521CC27EB93DE7ULL, 0x2183F211301668B1ULL, 0x503E9F30D4A19BB3ULL, 
            0x72BB3EDB1074D4B2ULL, 0xDED098133919C8D8ULL, 0xD9B0A7DE77C9F3EFULL, 0x21C09B3DC05AB31BULL
        },
        {
            0x1FEAE21897E7F8FFULL, 0x52E9BD1B66CB1E23ULL, 0x6EEA89E8DC120636ULL, 0xFD30D2EA30382F0CULL, 
            0x9547675A2F83D0C8ULL, 0xD1375E2664ECF166ULL, 0x3DB90BD60A40C392ULL, 0xE4E5F0070268D162ULL, 
            0x5FBA506E2BB3379FULL, 0x19E65552855F3D39ULL, 0xFEB77B4C17125B55ULL, 0x91B2559078FC3A46ULL, 
            0x625EFD7B054525F1ULL, 0xC4EE4E215E472478ULL, 0xC89D461D58E8847AULL, 0xC1E168755FBDFAD3ULL, 
            0xEA99EF2EAB12DC7EULL, 0x4FB7A8F3E8D3215DULL, 0x3FF39928CE671BF7ULL, 0x62D91AC9FF98CC2CULL, 
            0x3581661A284E6A5DULL, 0xD9E39978EA2968A3ULL, 0xF5FBD372CA9C5253ULL, 0xBC52098AC6588DD1ULL, 
            0xF94FEA705724CEE4ULL, 0x3397052282B8B61EULL, 0xF0A38756821D7FA1ULL, 0xCAD61B8AFAEA97DEULL, 
            0x16BFC797E0178F2EULL, 0x9BB94ED57BEC29ADULL, 0x0A9D4A4712909E1CULL, 0xBA9C22D4DCA3FFE6ULL
        }
    },
    {
        {
            0xD23614AE6C69FE02ULL, 0xC7622A3F2F413CC6ULL, 0x9813BDD3FA37B60CULL, 0xD62E8F637ADE5B07ULL, 
            0x1B4BAE7880921E53ULL, 0x4A8C090BE0102726ULL, 0x11BB8855BA70DECAULL, 0x823846A745C964F6ULL, 
            0x3869DAE87203B3A6ULL, 0x7A2BA8C45770A17AULL, 0x4AC9908128884FBBULL, 0x84B010EFBE85F5F9ULL, 
            0x96C96BD98FD67FC7ULL, 0x81A456F212C8C306ULL, 0x40D4897902241FCDULL, 0xC2038CA030036EA8ULL, 
            0x09BB767BE677D3F7ULL, 0x775B0B92447BBCD7ULL, 0xDC21ADCC6BDDD643ULL, 0x246B3F5AC3A5BEFFULL, 
            0xCC94E8AE442D302CULL, 0x1D2C3F22994E58AAULL, 0x057ACEB07F659EF3ULL, 0xC4C52D12623AF6F4ULL, 
            0x94BBD0FAD4AE2B69ULL, 0x8B4AF70D80EE0800ULL, 0x3AF135533251AAEBULL, 0x1DB9EDB9775F2629ULL, 
            0xE8CC69ECD3EB2264ULL, 0x4050E9B0CF08D32EULL, 0x40DD13E7869DF78EULL, 0xFEFE775DEC4EAA0BULL
        },
        {
            0x7480CCC27E2FF1F9ULL, 0x9289ABAC002FFCF0ULL, 0x4DD34E03D01D16CEULL, 0x63ADAADDA4DFBCFEULL, 
            0xEC18FA921A2ECF85ULL, 0x97CF1F6E4EC15E66ULL, 0x58790695CE84A41DULL, 0x5B291E6B3D3382E5ULL, 
            0xAA7B723C8E3BE574ULL, 0x70C42AD13291BBBCULL, 0x544BF09E0E10B004ULL, 0xB9C1911157E85B14ULL, 
            0xFAB645809F337ACBULL, 0x44BDE171BC3B1B46ULL, 0x7130BDE49E301E2BULL, 0xB2E5E20CF65530DFULL, 
            0xC457391E31DFF437ULL, 0x56C03B8DC3D84DF3ULL, 0x98280B284B0E3A71ULL, 0x3D9A616B4365090BULL, 
            0x42B0C8D7103D62FBULL, 0x8DDD8636E2E10E80ULL, 0xCA2F0D78FD04E1C3ULL, 0x4C294208C9DD8697ULL, 
            0x2B5996E78E0E7A01ULL, 0x497155836803AA64ULL, 0x5A3DE0A0B1D5132AULL, 0x79FA6753209112DEULL, 
            0x111F5548E9395A4EULL, 0x162EFF963B22743DULL, 0xB758C766F436F3E8ULL, 0x995508749D36BE3AULL
        },
        {
            0x40A1FAC719865CA6ULL, 0xF89DC99B9C72E2B6ULL, 0xBA128F71D96580E3ULL, 0x2AC1C566951BE55FULL, 
            0xD6527B230C96DD85ULL, 0x988CE7297351FC12ULL, 0xF98BB14AE3F7908FULL, 0x0F096531D844982DULL, 
            0x78F0AFD1FBDB667EULL, 0xBED3A579E63D206EULL, 0xB60A73C5016D37F3ULL, 0x67E82B7DAEEA3277ULL, 
            0x49F9900A7D273E9CULL, 0xABC0226820A6FB92ULL, 0x479796C114307B26ULL, 0xE2B71D5AC9D19CB4ULL, 
            0x2AA7F38A0B65E0FAULL, 0x6470524EE7308C49ULL, 0x1BAA5071AA0D99F2ULL, 0x80B44A10D6147725ULL, 
            0xACBDD7B413EE217FULL, 0xD9E36BCF5DEE5A82ULL, 0xD5ED9A8EE827A460ULL, 0xE21835436D9A8F2DULL, 
            0xBD46A2C32FD05E9FULL, 0xF394060F3119EC44ULL, 0xCDE686AD7779F1A8ULL, 0x1A4569688D2C8D03ULL, 
            0xB8FA0E680CE53676ULL, 0x6FE311D663F9F00CULL, 0x6A4AC96A21334861ULL, 0x74F16E53C09CCF9EULL
        },
        {
            0xC6F2CE3B64165AADULL, 0xE56F0DC4015994A0ULL, 0xCF8A1354409CB894ULL, 0xFB5D048EB34702EEULL, 
            0x9F4CC57853808384ULL, 0xDC8BFE8C9C70B0C1ULL, 0xDCB23281EE75D88AULL, 0x4B2F7E27F8C440FCULL, 
            0xC50698E6A67958D0ULL, 0x15780E75FD96C106ULL, 0x166D7DF1D2639DDEULL, 0xB09B34372A4314E0ULL, 
            0xA5389E0903F772F8ULL, 0xDA3FA5DF6805B9EEULL, 0x1AF4CBEF91462323ULL, 0x9A8D3EE07DC336F5ULL, 
            0x4004FED8CD561228ULL, 0xE7A4DFBDE4AF001AULL, 0x6D4E9E7D6C29D5C9ULL, 0xF8B169D4F6C1421DULL, 
            0x94898D47C1E70885ULL, 0x0282E8065076B26AULL, 0x6BEFB362B370E31FULL, 0xD7C3471A70C22C2DULL, 
            0xC62583D420F3C964ULL, 0x7932981C1681F743ULL, 0x8A27D148CE2EDF4FULL, 0x0AA328CC54F9B1F8ULL, 
            0xB5573261AA949A25ULL, 0x82731FFCA7AE7C46ULL, 0x2FA1925193D61A92ULL, 0xD6AF3A296ACE0DD2ULL
        },
        {
            0x72C277EA6F318435ULL, 0x4DB75D78A698D992ULL, 0x2557FCF99E112E5BULL, 0x4C6385F6896FA855ULL, 
            0x1144946086939856ULL, 0x8B1F776B713DF02BULL, 0x09745C64C6DC2A07ULL, 0xE6692887DA6FF670ULL, 
            0x1C11E1344C5EFA28ULL, 0xA02FCE15FD0E56FEULL, 0xF9EF599A58278DC5ULL, 0xBC5984336522EEE6ULL, 
            0x5448A1CCC9A22689ULL, 0x60C8C8FBDA6147B3ULL, 0x45EF221C5F9FF17CULL, 0x855B5CCA67936BE5ULL, 
            0x2BFB50629460BA91ULL, 0x059E54149137EE76ULL, 0xF3930AC6EB28BEF2ULL, 0x851BE12BA57212E4ULL, 
            0x190FAA26C73DEBEAULL, 0x332A8D1A97541EDAULL, 0xD4704CD7C220A808ULL, 0x0FE31918D8CD8BB9ULL, 
            0x4622AB80F8057592ULL, 0x8A5D06BCED62F932ULL, 0xFDD07E05FE57559AULL, 0x73EC0FBCD1B0C131ULL, 
            0x61283030D21DA7F8ULL, 0x85F8A2FAC93F8BA6ULL, 0x5A5347B0DF97F62FULL, 0xFDF867B71603BFDDULL
        },
        {
            0x3DB600A834AFD68DULL, 0xB66D69A874161365ULL, 0x6B845C3F18215B68ULL, 0x9ECE979964626012ULL, 
            0x291539EBC7DA099EULL, 0xE507CAFD3029CF8BULL, 0xC17FA6E77A8105E3ULL, 0xBE2A5E90BBCECBD7ULL, 
            0x6213BAC5B68D6C8CULL, 0x25B54A9FD2318FF1ULL, 0x0DD8EB4A41501BD8ULL, 0x9BCC4152F18D1ED8ULL, 
            0xE7DE634181DF694DULL, 0xB20BE8B71149AE43ULL, 0xDC0ADE83EC0E2786ULL, 0x42C290DF044813F3ULL, 
            0x2AF5986150A5679EULL, 0xDD855C1E8B4830A1ULL, 0x0A7390C02D05C461ULL, 0x526AE1FE9EABF9A0ULL, 
            0xAF7F0EA740BD1CAEULL, 0xCA685832EF1EAE3EULL, 0x2B811A6A083F08D1ULL, 0xD0FB81F1DB4340F3ULL, 
            0xBB6350230F3304C0ULL, 0xFEC015774D985878ULL, 0x680E00020C5C16A4ULL, 0x9050ACA5CBAA7D90ULL, 
            0xE718E796173046D3ULL, 0xC988BF5C2447C21AULL, 0x5A3AD05D80703D8CULL, 0xC62F8B561A30F137ULL
        }
    },
    {
        {
            0x1C4597909A75712EULL, 0x07FD92682A8EB1B9ULL, 0xB020A50C8A00970FULL, 0x835E769EF9058842ULL, 
            0x246C0C36540C92CCULL, 0x7ABCFCCD9568B353ULL, 0xD106915F37C3B4E7ULL, 0x8F3FDD8158F24A77ULL, 
            0x296C82D9A38D7D3BULL, 0x9A59E5A83883C128ULL, 0xB5B516E188D45901ULL, 0x94D6D1D4C77B4EB9ULL, 
            0x58556A96376FEF49ULL, 0x0E24E9826DC9C99EULL, 0x22A0FC501F753210ULL, 0xB62F045AB16A71F7ULL, 
            0xF1D89B784853BBC6ULL, 0xD8CC7156143C26C5ULL, 0x541F0C24E3762B09ULL, 0xA4CAB33C5E24188BULL, 
            0x8D5392F5BA3AB807ULL, 0xCFEE99D4135BC16DULL, 0x474125135078EE9DULL, 0x738A5637BCD6C795ULL, 
            0xB7D5BD752CFF3E8CULL, 0x30CC7830D785FFB8ULL, 0xD2305B6B5F56AED4ULL, 0x373C0EA520B3AD0FULL, 
            0xB023E610A8CBC90EULL, 0x689CFBF479128CA3ULL, 0x5FE6C5183A89BB81ULL, 0x3DAC9720A8544866ULL
        },
        {
            0xF06967401518058AULL, 0x870E142B051BA42FULL, 0x65657D254DA34D20ULL, 0xB5BA4D4EAC38DDF1ULL, 
            0xDB8645CD699E1CEEULL, 0x6AF72FB89BACE0DEULL, 0x4BA23D3F8823FE34ULL, 0xC3C690E69CEEAA96ULL, 
            0x2D92CB6A0C3FC6AAULL, 0x00318F7C713E401BULL, 0xB2BCCF34C165CDD9ULL, 0xB7EEF1CAA2B297FCULL, 
            0x5C148430C09D1015ULL, 0x3E99DC869473DDFCULL, 0x2691289CAF9D3463ULL, 0xFA8141A0B13E862CULL, 
            0xF10A34097A2DF525ULL, 0x8E79F3C25CD62BA9ULL, 0x3B676852A82FE305ULL, 0x8E501969C35BD881ULL, 
            0xF5F027770A10A7F2ULL, 0x27D7965C13142452ULL, 0x75DA521A51E3A819ULL, 0x0453F1539EC12294ULL, 
            0x625A781E3EEEF97CULL, 0x1904C93FD7C95DF9ULL, 0xA3F71F163D4A3EECULL, 0x9B08CD4DCDE878F3ULL, 
            0x2837046F820B1831ULL, 0x7087DBD748B62C66ULL, 0x30B8C5E7667A521AULL, 0x06B1E9E3180783B7ULL
        },
        {
            0x605ED87B4D0D5030ULL, 0xFAAD8497A256A91DULL, 0x89D55C9D82298CE3ULL, 0x219DF304E14409B1ULL, 
            0xE6C07B2A5E81FA96ULL, 0x11A4818172268DF3ULL, 0x05C1C09EEEA635B4ULL, 0xFB5EC3D036304D04ULL, 
            0x8108BD1E28CFBFD8ULL, 0x1A6680C21BB81D80ULL, 0x99072DF5D3BA7DFEULL, 0xBA1C7357138881B3ULL, 
            0x73881121E15FEBE1ULL, 0xF183C0C9876427C8ULL, 0x08DAA6B0078ACBF8ULL, 0x2FF6975EDBC7C927ULL, 
            0x3C12259C42FCDAE2ULL, 0xAE37D349B26A3918ULL, 0x479F19E9F057F42BULL, 0x1C644B06DE17F350ULL, 
            0x23D84CE1938DC5F3ULL, 0xF5ECCCCF4F03F38CULL, 0x1E2A5E088E9A1712ULL, 0x76F040D69E4C024FULL, 
            0xBA37DCD50F6744C5ULL, 0xEBBA693D9FC6B46FULL, 0x9248A7EB6E5E9643ULL, 0xC4115BD4B5E925BFULL, 
            0x5AB4CF184988F710ULL, 0x4113036D779169EAULL, 0xB382140F7F059824ULL, 0xAE2A238684FA03BCULL
        },
        {
            0x3841BCBD6F1E25D1ULL, 0xA9C7EF1224B59A2CULL, 0x5998C315323EFCA5ULL, 0xE77C918A7A230EC2ULL, 
            0x1A56B2B05ACCEA80ULL, 0x4ADB3CDDC1C6AB07ULL, 0x2561DA0B636F9457ULL, 0x8CF7BF2A22E6C4C2ULL, 
            0xAC743CF94957AF9AULL, 0x8CB1D16304DFFF5FULL, 0xE52A07F0EE331736ULL, 0x62DE2CA4B61D349EULL, 
            0x3F308D53BBEEC394ULL, 0x2BAABFC1C144182CULL, 0xD64A76ED407DB070ULL, 0x24FA16CE28882EDEULL, 
            0x32E9ABF10B6B7DEFULL, 0xC98F6C33B3D6FB2FULL, 0x3B3E9117FCED547DULL, 0xFC6E299C5BFCA253ULL, 
            0xACC101BE07B6098DULL, 0x7519DB3C3007A711ULL, 0xBC66880B9DEE4B16ULL, 0x15A02D3454E54338ULL, 
            0xAC1984CA3A1E516BULL, 0x4D967FE1BDDA125FULL, 0x300544917387A257ULL, 0x5E319F36AA62AB88ULL, 
            0x4F588D7CA4A10CFEULL, 0x5008B059EBB862A0ULL, 0x71581A21E5B221B7ULL, 0xBD97D22ED0DE91C6ULL
        },
        {
            0xE6A585E2BE7E9B88ULL, 0x3BC2B025C08B16B7ULL, 0xA7811C833BE07EE6ULL, 0xCF109E948F557D6BULL, 
            0x1CE506FEC1B4E437ULL, 0xB6EC0D204353F97EULL, 0x579BCA94A2BD9FFAULL, 0x6B4FC31673C38947ULL, 
            0x0EB9C7E8D4B52E5FULL, 0x4C0D9E974D2C8C17ULL, 0x3B1176A677F2B052ULL, 0x0FFC72C05C5E0930ULL, 
            0xE9640D5B0414DED2ULL, 0x6ED8689D2BAF3E5AULL, 0x522F789F9AEDCE2AULL, 0x47DA4504C53FF91AULL, 
            0x625E79E33232BF27ULL, 0xE441CD25200D0424ULL, 0xBDB32C00FAA723C5ULL, 0x4621FB0B1BE1C45DULL, 
            0x83B3FE1F1842A776ULL, 0x992A18CF896F62F5ULL, 0xAA8AD9210A8614D5ULL, 0xFCF18AB05A60F22AULL, 
            0xE6B4E337B866CBD5ULL, 0x5739B278C3B65258ULL, 0xDDA147688627FB25ULL, 0xA12DF977B0612BD0ULL, 
            0x3157DB6A9857B9B0ULL, 0x6BC6B00DF41AD375ULL, 0xAB76DB43E5813F32ULL, 0xEEA428B8F2E059F0ULL
        },
        {
            0xACA1F34A2A3D13DBULL, 0xDBDD35246CF70B3EULL, 0xBFBF35E32DD87ACBULL, 0x395847778A20D938ULL, 
            0x41B77A31A8A39F77ULL, 0x026BDCEF33C59E3CULL, 0x99AFD40E87B56914ULL, 0xC9D68552321FB1ADULL, 
            0x2351C7F8881B3C7CULL, 0x9AE6499BD3C43877ULL, 0xAE80B11AD7280FAAULL, 0xC3A6416004468C5FULL, 
            0x7B883902A925AFFFULL, 0xB32F30FCA05E4D5AULL, 0xC2AAB29BDD847498ULL, 0xBD1294AB0BBEBE4DULL, 
            0xC69DAE1E7445E35FULL, 0x307139AD1C5FEE62ULL, 0xDFC819ACB30B91CFULL, 0xDFC4BC857BAEBC4FULL, 
            0x2F4BBF0661BE0545ULL, 0x55A4717C5BDCB324ULL, 0xE2AB8669ACEB6A39ULL, 0x6DBD732E1CDE5ECAULL, 
            0x47B7A36802D52557ULL, 0x5677BA3A0C52E6A9ULL, 0x65AA50295BCDBB8BULL, 0x2CA4E7F9ED6E2F9FULL, 
            0xBD3B90801097FE2BULL, 0x908BF3B7388E5FB2ULL, 0xAE80A9E3E39FDBF8ULL, 0x558DD1A8457D6B3AULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseCConstants = {
    0xCD46D180AC966F79ULL,
    0xCABEC307725764CBULL,
    0xDC979A2327C86EC4ULL,
    0xCD46D180AC966F79ULL,
    0xCABEC307725764CBULL,
    0xDC979A2327C86EC4ULL,
    0xFC25E670066109CAULL,
    0xCBFC9A645887A8ABULL,
    0xFC,
    0x0A,
    0x59,
    0xA4,
    0xAC,
    0x2A,
    0xAF,
    0xF8
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseDSalts = {
    {
        {
            0x58E06E5415ABCA04ULL, 0xEA944C4F707992C7ULL, 0xB2310E1E8A8A702CULL, 0x00A294FF259CF150ULL, 
            0x66C5BB17317D2207ULL, 0xC8324064BD0D0833ULL, 0x194281956F325517ULL, 0x0B5E914641AEE06CULL, 
            0x247A55924A1C12D3ULL, 0x126D2A7CA2C2FCEFULL, 0xF90E35BF144295B5ULL, 0x925C88DA349904E8ULL, 
            0x3B48611A88F2876BULL, 0xB22CC90AF24C4FB3ULL, 0x72D8611646B1E804ULL, 0xC301BF75B82C6823ULL, 
            0xA9B5B76FEC99CB95ULL, 0x2258E49ADE1D4CC6ULL, 0x430F28A32D9306BFULL, 0x529C13473F296BE1ULL, 
            0x3F534292B5323974ULL, 0xA46EA6DB3F80DDD8ULL, 0xC2EBE949567D6D83ULL, 0xE3D8705E4AA05F41ULL, 
            0x4E4960DF828BD126ULL, 0xD01D6D789DFCC8D1ULL, 0x3B8315D927E856F3ULL, 0x0387690F1D1E8C2AULL, 
            0xDA4389704FE2F0F4ULL, 0x04C75D97D87A84DAULL, 0x1D0311CF262036E8ULL, 0x7CDB0D617839C5BFULL
        },
        {
            0x30DC850639AD82FCULL, 0x44438B7CF05BCCCAULL, 0x9758D3F01487BBD6ULL, 0x27884C6C7882255FULL, 
            0x5E80CDDDD2619C11ULL, 0x5E075C6994B5B25BULL, 0x073628933CD1E735ULL, 0xA733C6AEB6C5135FULL, 
            0x12F716BACF9D6264ULL, 0x473A6FE9CD00D677ULL, 0xBCA95766D886CECDULL, 0x4F6D9765E429A5F1ULL, 
            0xA8F5FD547C0F05DDULL, 0xB2A8BCBD2D729E82ULL, 0x3DFB135ECF582BC7ULL, 0x38E1F670E1BF86E3ULL, 
            0x82EB10A87EE0ED33ULL, 0x5E3EA5123AAC2E51ULL, 0x2C3650528417D8ACULL, 0xAC3E2E2FB87797C5ULL, 
            0x4B46E52738D2BBC7ULL, 0xD20E5E19FB802E3AULL, 0x08959BF89327CA7AULL, 0x4CB5A5CD7F2E5F52ULL, 
            0xF733FBF6F69C6342ULL, 0x91D9DC32033EC186ULL, 0xBE0C752E6FDFF2F0ULL, 0x0D21BAFF5D71A3A2ULL, 
            0xE46784AC84430B47ULL, 0x060D53572EACA250ULL, 0xA811CC92D4CF0C4FULL, 0xBACA435C7732FB5DULL
        },
        {
            0x348D65A32AECF1A9ULL, 0x546081D046086D63ULL, 0xEE7D037C57982ED6ULL, 0xB93548F8D0E4F564ULL, 
            0x0F57761303E015B7ULL, 0xD96D71E670DAF131ULL, 0xCB987A53495A9684ULL, 0x56611CE83AC13EE0ULL, 
            0xEFAA4C70AD9F6D82ULL, 0x4308E16B3FF9F8D5ULL, 0xF03219AF359565CAULL, 0x9921F87DB5E6BE62ULL, 
            0xE0352210A4CCF8F7ULL, 0x9F2D472F0BD57E88ULL, 0x87F8C939708F967CULL, 0xDD59C1C1C48788DBULL, 
            0xBA8CDF0331459103ULL, 0xAB2911F9D1520B1DULL, 0xE62A8D952A814241ULL, 0xAE22FC1CABB2EA77ULL, 
            0x04E7637ED2EF8887ULL, 0x18138022BA2F4716ULL, 0x7E12CF3B702FD8AFULL, 0xFDB56C6A1BE803ECULL, 
            0x3D82D051A4BCC541ULL, 0x07BFA8A04456B09FULL, 0xD0434E73C3322700ULL, 0x063A217C0DE3A323ULL, 
            0x965C2DF2FB997F3EULL, 0x5BDE3F1610257D3CULL, 0xCFA8E039EFAF7FFAULL, 0x9DE111A661E25FFAULL
        },
        {
            0x016AE4875BD0B2A7ULL, 0x85F44FAE69B60A04ULL, 0x41C4FB6E713A30F0ULL, 0x0960395836C585DCULL, 
            0xBA0F3E84714D44C2ULL, 0x34C2148EAB56B67FULL, 0xC663FC5EA1CFD3A3ULL, 0xB712AE6B7D637013ULL, 
            0xAC996EAEFEDC551DULL, 0x3A6C5AEAC05183B0ULL, 0x5E45AE1AF7EC5718ULL, 0xC9E2E3EA6FD299A3ULL, 
            0x3D88911EA5593918ULL, 0xA1E16CF2DBDFB763ULL, 0xFA316DAB83A9DF42ULL, 0xE599A752B65E8594ULL, 
            0x0BFA38784543E513ULL, 0xBBD30AFA9A5B46C4ULL, 0xE2469B869C689360ULL, 0xC410B0EA88810D6FULL, 
            0xA4C340E9571C10EFULL, 0xDD38CE3ED4B205B9ULL, 0x51865064076802E7ULL, 0xE884EB5AD92BE978ULL, 
            0x0A0FDDAC4264199CULL, 0x71D37E7B5CEC217BULL, 0x0EBDDF30593834DDULL, 0x4DF16AD5FB4292CFULL, 
            0xC835D842C9A0890EULL, 0xDB90B45D5F28BC24ULL, 0xEA71684E43E11C81ULL, 0x1B6A6A3210F21AF6ULL
        },
        {
            0x35AF00D74693B0A7ULL, 0x7E5EC485EBEBED5CULL, 0xC1907EF40D27965FULL, 0x4E8A531ADDCB1737ULL, 
            0x37C3FBBAF2B7EFB9ULL, 0xE41C10F99F2AB5DBULL, 0xDC07A87079F07B3AULL, 0xE4D80439D24961A3ULL, 
            0x8BC5CCDB6064B3AFULL, 0xAAB6EBEC4F9703CBULL, 0xFCD7DFD5FF4BD271ULL, 0x77D9CE8ECC9EA4E7ULL, 
            0xB0C89F590E5EA114ULL, 0xDDA2E0743ADBD5BCULL, 0x1C28E8B656F8164AULL, 0xE331F213FDF5F9FBULL, 
            0x141647A946D3C3D5ULL, 0x415D211B0D368B09ULL, 0x5B343D4CF60D9DCFULL, 0xFA663C2EE79F1994ULL, 
            0xCE3889E9777F1918ULL, 0xE1BFB35199F1B970ULL, 0x6AE7723F08E96DB9ULL, 0x9A606E530D665C23ULL, 
            0x8C2A6A184A368EB8ULL, 0xCA510B8729EC6A07ULL, 0x9C963E7D8AB92375ULL, 0x5454D42C2EB6FEBDULL, 
            0x4779AADF2B9ECAB2ULL, 0x1DE672077ACD5153ULL, 0x194DC2DA22ACA097ULL, 0xE229CE8DD876F664ULL
        },
        {
            0x8E2A4D358E185528ULL, 0x038F9DF1CBD09810ULL, 0xDA1461E2501FF22FULL, 0xD6C28DF20D6F8818ULL, 
            0xD788DADAF4D2F995ULL, 0x151BE564F4A42422ULL, 0x9883E152EC714D98ULL, 0xC9EBFEFDCBE53C20ULL, 
            0xE385245368F07D15ULL, 0xCE020328B45E0BF1ULL, 0x529704CE0AA90441ULL, 0xF4454615C9AF3A96ULL, 
            0x3976EBCD729D7A9BULL, 0x77F841CBA56FCB68ULL, 0xDE8774D920119ED2ULL, 0xA2B6D26B4DC4BA9EULL, 
            0x9ADCE45ACEC48AAEULL, 0xEF92CDB3A2578E89ULL, 0xF27DBFE1AD376806ULL, 0x583EBAC930347885ULL, 
            0xBCD9E8FBB568FBCBULL, 0xD0D8791B762511E7ULL, 0xD1A4A457B5F087BAULL, 0x75D36A7C3D05AAFEULL, 
            0xAA2BF72CC6324E41ULL, 0x57816C78F087FAA2ULL, 0xBA2065060ECE3817ULL, 0x41962AF80AC415D8ULL, 
            0xD7C96CFFEE6F7BCDULL, 0x78E58A358CFDCD68ULL, 0x91A0D1ECC437AFEEULL, 0xFBC76C365E51D971ULL
        }
    },
    {
        {
            0xF33FA03792F059B5ULL, 0x4A362A5870649605ULL, 0x5904CF070B77E85DULL, 0xBC3C1F8B727A2EAAULL, 
            0xFF7FACE6AB4C7E14ULL, 0x61F303355E55357AULL, 0x3A1FB18C4D79AED9ULL, 0x4D0AD824DA2AFA18ULL, 
            0x9F79BAC5E4BDF875ULL, 0x787A36FFE845CDF9ULL, 0x0FD836636AF9D0D6ULL, 0x85B5185CF4D346EDULL, 
            0xE0FA7CFEDAB940A1ULL, 0x05A448051CC84439ULL, 0xFD80F9A8A90EFC66ULL, 0x7DB63CA2EB07AFD8ULL, 
            0x78844B8DB3597B4BULL, 0x66ED22B834AB9825ULL, 0x581772BEE85A3771ULL, 0x0294EE92FD713289ULL, 
            0x65917BAB10C84870ULL, 0x59EB543DB007B374ULL, 0x226A1547B57CF5E9ULL, 0x7A47F7E19E54FEC5ULL, 
            0xAE30E3663158C340ULL, 0xEF710028D1DADB67ULL, 0x7C14D9058EC5771AULL, 0x14FD245948048369ULL, 
            0x7966444F6D160FADULL, 0xCAC2ACFD56475C6BULL, 0xE79F6361AB2388E2ULL, 0x17259DB30BE0B38DULL
        },
        {
            0x623CA31E0D1FA074ULL, 0x11482F6B28FEC4CBULL, 0xCACA7ABDDE382C97ULL, 0xEDB6A254054A5FD5ULL, 
            0x4FA572240287886CULL, 0x844965EDF12E51F6ULL, 0xECD283583E759667ULL, 0x7EC02744E0C3098CULL, 
            0x52D8A380CADEAA7EULL, 0x8338D31397D39D87ULL, 0xC69D48496CEED9CCULL, 0x7C0E5064056E8648ULL, 
            0x2440D4047D9062A3ULL, 0x792DEC2EBE62DD3DULL, 0x747B4AE2DE42257AULL, 0x44576A04BFAF2484ULL, 
            0x28E84CB6855B096BULL, 0x44543CED58D94E5FULL, 0x2261F7BC924D12AEULL, 0xCD2AFC2C8507DB34ULL, 
            0xB03137B167601FF2ULL, 0x324568C13D3D76AAULL, 0x1E2A0CFC13E59465ULL, 0x639D18B0339DB4B7ULL, 
            0x974A15F79AB717DFULL, 0x2BF322D2C1B64977ULL, 0x55E91E94C365FFACULL, 0x962AA92668546E66ULL, 
            0x3715A404F486A385ULL, 0xF785ED877E7DA504ULL, 0xB3E6067A92F53A8DULL, 0xE1F76039924E06DFULL
        },
        {
            0x023F9E29851A5BEFULL, 0x4DEB22A9A6F61CD9ULL, 0x5C04B8F29982EF2FULL, 0x7990C53DE998BF27ULL, 
            0x9ACB8B157CA0F14BULL, 0xF276F742F8BD992FULL, 0x5D05F79A919B7FBAULL, 0x3B27DCB5F02E3CBDULL, 
            0x12CDCAF4BAE3BB34ULL, 0x451D9CAD79995A9EULL, 0x8B9EE535210F8162ULL, 0x39C745527A7567FDULL, 
            0x8EFDA2BCFAE7174CULL, 0xC58F4BD869A8B370ULL, 0xF49E72B09A648B05ULL, 0x573F7994A8CA93A8ULL, 
            0xD71A92640C836977ULL, 0x173F4AADB3377ECEULL, 0xF0CDDEC04892FFFBULL, 0xB25830461C217AF9ULL, 
            0x3A93592C025BBE24ULL, 0xFEBEC7CBFCAECFCAULL, 0x9C22F07BF43CE065ULL, 0x20B8438C13AC2111ULL, 
            0x9F3F7D7C5F58997DULL, 0x0C0F2236ABC5BD6EULL, 0x34089857625D4BE8ULL, 0x1A834302FC7A793AULL, 
            0x307CC2A575A2A231ULL, 0xC83ED6736C8973DCULL, 0x4DC5CF05814DD9E7ULL, 0xAAF473995BEBE0C6ULL
        },
        {
            0xF18C9D72E385EABFULL, 0x9CE53C74313A77ECULL, 0x74598A2E71F2BA6CULL, 0x3E05F301B502BAE5ULL, 
            0xCB7B119DA57DB6E2ULL, 0x44E4149AA6840F8EULL, 0xE046E0C5B3DC4518ULL, 0x5939D42F582771DCULL, 
            0x14E3C13C8EB29153ULL, 0x1FCAD37C6B918837ULL, 0xA9D28063E2A7BB05ULL, 0x17F5B6749E138E75ULL, 
            0x4BB8682C80A9794CULL, 0xBE202F72A6FA3837ULL, 0xA44AA3B9F603066AULL, 0x9D28D15A9D13D207ULL, 
            0x943E8B6863039A56ULL, 0xE137B3FB34E569B9ULL, 0x83CD6A945B36251CULL, 0x2700E9E0FA22D789ULL, 
            0xAF6DAA5F58B5100EULL, 0xD8D04B372424ECE3ULL, 0x1B3676F8E103B595ULL, 0xECE5A1644E1CBBECULL, 
            0x390D43090D6F1809ULL, 0xA59DEBA39C52A3C5ULL, 0xD05B9098CD5AA29FULL, 0x39C805B9C86A1AC7ULL, 
            0x46B27131CAAFEE10ULL, 0x8B46C962A0ED62A6ULL, 0xE410641B94151FC8ULL, 0x499D0F9693E278BDULL
        },
        {
            0xB1CAD87B623CCADEULL, 0xF761B4FF48040CDFULL, 0x9134A207C21E5237ULL, 0x9E4663A4E46195C7ULL, 
            0x6DD6094DC24B36C5ULL, 0x5557FB411250BA97ULL, 0x63D1EFE5ED860EBFULL, 0x8BFE6444E7320469ULL, 
            0xD28E34FE9459E127ULL, 0xC2669F82C72FCD47ULL, 0xBAA190D88C77096BULL, 0x1C70A42C61D2EE98ULL, 
            0x40D3B434B27EBD1BULL, 0x7B99AE65312E14A1ULL, 0x9E337C8680F5861DULL, 0xB5125E45B454E605ULL, 
            0xF051B4056A39BC7FULL, 0xD30C70158F2AD3ADULL, 0x59060F6A03532180ULL, 0x5FAA915157A3E473ULL, 
            0x998297AD8D7E6737ULL, 0x1F30FE30D9E807F4ULL, 0x084A3AC0735A40C2ULL, 0x5C64337A7660854FULL, 
            0x025D57DEF8230691ULL, 0x2C5A84704C4E3A79ULL, 0xB85E3CDB061DC2ADULL, 0xC9A45E38887926ACULL, 
            0xC52804AE79D0A6BAULL, 0x0B7174C4E90A4C47ULL, 0x7D956BDE1B88BC16ULL, 0xAD7B00A78D166BD9ULL
        },
        {
            0xB835BD4AD0559B64ULL, 0x6C8EBBE06652AA5AULL, 0x50D91C70D197B359ULL, 0xA899D99228901131ULL, 
            0x5DD26566BFA5448FULL, 0x5542180E66470D40ULL, 0xEC2CAB7C04FA0A6BULL, 0x84DAE168A0EF7D09ULL, 
            0xB75ECA23CF2ACE40ULL, 0x2A1EBBA150BE8FE5ULL, 0xE418A5E7C6FD8EE1ULL, 0xDE58172507693D13ULL, 
            0x37D8F90CF36E149AULL, 0x77956D21C90E48D2ULL, 0xD6D3BAAD4B10063FULL, 0x4D4A36BEECB68638ULL, 
            0x616E8F2BF430EF3BULL, 0x1A97F3CA9521CDE2ULL, 0x5D304149EBE60C80ULL, 0x269E8251E5425A22ULL, 
            0x1EF3EDC6D1EA34EDULL, 0xAAF1BA9C69A4CC4CULL, 0x6D02EA1E84C3BF59ULL, 0xEDE85D63E9432AE7ULL, 
            0x9C133F8CE4968AACULL, 0xF987D4536ED98F70ULL, 0x8A447DA251735A08ULL, 0x2EC2750FAD901F1EULL, 
            0xC59047824C853B3AULL, 0x97415E5DF71051E0ULL, 0x3FAD90ADBF3C16D2ULL, 0xC34C625CC611B191ULL
        }
    },
    {
        {
            0x1D70B19ECFAFAA70ULL, 0xCA46CA7242E9F3C8ULL, 0x698EFB7C53E5007AULL, 0xD28B3FB17B313F8BULL, 
            0xA45A709BB66F9E81ULL, 0xD9B07533D80D1D9EULL, 0x0083D16DA95EB4E7ULL, 0x4211D60980A1C479ULL, 
            0x58010BE1EC42D472ULL, 0xE0777E5F9C4A4E49ULL, 0x165D49A3FBE85CA0ULL, 0x43437C8D2091C91EULL, 
            0xFD75BF20F4F0754DULL, 0x97535EE7C76B18B8ULL, 0x5AEC1CD8749A6682ULL, 0xA5DF1AA85CF036BCULL, 
            0x1C2755DAB0E2552EULL, 0xC43D3A0F5FBA9D91ULL, 0x36C41894337B6714ULL, 0xE0263C7F4B5BEEE9ULL, 
            0xB6C3AA9AE50C931FULL, 0x9E51057E692F4649ULL, 0xBAACDA902C23097DULL, 0x2866645AE05F1857ULL, 
            0xB692F575F69D7F8BULL, 0x8AC47A30E6A00C85ULL, 0x1EAD950F93661CAFULL, 0xC8B856C29AEDDDF0ULL, 
            0x11C5DCD883361CFBULL, 0xA0E98F30C16570DBULL, 0x48CD61DA0CDE3796ULL, 0xBD67B28A29A3A7CEULL
        },
        {
            0xCD9E65937D744C98ULL, 0x38B5E67E637E4D06ULL, 0xF97460C2B0ECDE83ULL, 0x47D3CAA4D29A1CAAULL, 
            0xF16BDF465961149DULL, 0x291DEBF743618242ULL, 0x5329DF54E462766DULL, 0xD13B5A3649DA4F3AULL, 
            0x1596A9584FC8A8F3ULL, 0x6534F5DCD0B469C1ULL, 0xB6DB27CAB440FBEAULL, 0xD0B4DCF836991878ULL, 
            0x58B22F362ED1E73DULL, 0xD7ED8083A603C7B3ULL, 0xDFB6D6FFCE61D56BULL, 0xE5B488A4C4267973ULL, 
            0xCF400630AD4E1CADULL, 0xB367F6CDF4B693FAULL, 0x1F2FA5D4489F8CC4ULL, 0xF224CA33FAB3B74EULL, 
            0xDED61C67007C1AD0ULL, 0x61728C412F50DE93ULL, 0x6CBEFAAB0C3B07E0ULL, 0x4B258831938B3777ULL, 
            0xA47F5A8FD96D2CD2ULL, 0x54C7B793E5328DB7ULL, 0x7B67B33488C8338FULL, 0xF60982727956164AULL, 
            0x5DFE274E69A630F4ULL, 0x841738EED243F14DULL, 0x6AF916EFCA58F48FULL, 0x5BCA152A88B47167ULL
        },
        {
            0x0D811A964EBA9CACULL, 0x0012C3A9CBD5A79DULL, 0x523F7CC06657BD96ULL, 0x22D7A40FB7CD2B32ULL, 
            0xE809CAC5B218A9FBULL, 0x3EC6DB09D487CD92ULL, 0x470B962C3B1DF86BULL, 0xA0BCCB1F9990AE49ULL, 
            0x0A5846B9F7C64762ULL, 0x90C054B8426AEAD1ULL, 0xF044E00B6806EA6DULL, 0x660982D04C62EF18ULL, 
            0xBD25A1049BD3ED4DULL, 0xF6FD4567A195851DULL, 0x92B69C9A5C0690B9ULL, 0x52E615DE499ECD43ULL, 
            0x555972C92D527721ULL, 0x4D3D467E8CB2BB28ULL, 0x62E6C719BFE530CBULL, 0x06C910A88FCCB7B2ULL, 
            0x7070ED671BC1C701ULL, 0x50792C310B78D344ULL, 0xF0B942460E26D34BULL, 0xCD683F0B2B1E7A63ULL, 
            0x0210B26B6774F639ULL, 0xA98C5D6D20224EC7ULL, 0x4EFEED88FC2B49C5ULL, 0x4F83A7820298F21AULL, 
            0x39952C25272E0F89ULL, 0x24D50EC97F1ED1FCULL, 0x8F3841202657C697ULL, 0x0E9BC0A5F544DFDAULL
        },
        {
            0xC72310A41CCCC93CULL, 0x643E4A4E277FA31BULL, 0x48C7E1EC22AEFADCULL, 0x322E0416CF571397ULL, 
            0xE1DB58D9794C3294ULL, 0xC0E28E1C78761E46ULL, 0xA36F3A9BD51D3B08ULL, 0x0353B8B2FC2C1C44ULL, 
            0xDBB46927FA2F84F6ULL, 0x8335D7F59C8010D6ULL, 0x839B9BFBCC170BACULL, 0xC1A13E97700F8365ULL, 
            0x56F007E35843DE97ULL, 0x47CA8DCF081FDBB6ULL, 0x15AD1878358AE496ULL, 0xCE63D621BB0832FFULL, 
            0xA0F66D12016167E6ULL, 0x095F247C35B97380ULL, 0x3C67076FD8D5D07FULL, 0xD8F51A0561491C4DULL, 
            0x813126449F16CF30ULL, 0x270ECD1B13579F87ULL, 0xBB492875E4F2A012ULL, 0x77DAF8D9A48329A2ULL, 
            0x3FFD4491BA2D3865ULL, 0xBE26215DE7CECEC1ULL, 0x11CCA6F504F9E3AAULL, 0xB4E293FD48F4BC1AULL, 
            0x38FB55022BD12977ULL, 0x8D7D62D87100C4A1ULL, 0xE7895FBE6AA6F61BULL, 0xCE0C414F90DF8C83ULL
        },
        {
            0x08CB0AC0979993EAULL, 0x0B5E21FDBBC84DA9ULL, 0x96263C60CE57D747ULL, 0xF018D4D436947D58ULL, 
            0x61468AFD2BA755D2ULL, 0xF5250E74D261B166ULL, 0xC79C567019A69775ULL, 0x1F366451102DB747ULL, 
            0x5E33B4211C21552BULL, 0xA2EA7D395F2D6D29ULL, 0x27C973C692F41486ULL, 0xA35A2BA950B295D3ULL, 
            0x71366732B93B9DEDULL, 0xE7EB0E59BB53095EULL, 0xBD0954FC37F4E0B4ULL, 0x06447614C5842AC6ULL, 
            0xCA7386428C542D27ULL, 0xA4DCAD26CA4B7023ULL, 0x3EE0C05CF9A49BB0ULL, 0x104761BF3DED6BB0ULL, 
            0x49A9E7CE4D214050ULL, 0x74FA7F270303D7DEULL, 0xABAAC944D2B1ABECULL, 0x400F78AFB29E502FULL, 
            0xC2771FF946900453ULL, 0x81A33D72516CD000ULL, 0xC018A34BB4F6E67FULL, 0x9154F93EB54C190AULL, 
            0xD034ADC158BE04DAULL, 0x563E69C0D9E9F145ULL, 0x74A7E6225486D444ULL, 0x8CCD301CFDB61F2DULL
        },
        {
            0x86CFE32D4A8D5A56ULL, 0xBCA9D88D74876D10ULL, 0x0DE75EB3451A24B1ULL, 0x2C38BAA9756B6BD5ULL, 
            0xFB6855B5398B3B1FULL, 0xF75620F5282AD934ULL, 0x112B46674B611C20ULL, 0x02686DF3A2F84A7AULL, 
            0xC2295611B625B632ULL, 0xF4157850E5BA285EULL, 0x324FBC8B2FB47593ULL, 0xFB10D11E0FEBBABDULL, 
            0xAF85089B859EAB69ULL, 0x7B511C656E176994ULL, 0x6A1245FD02B65F39ULL, 0xA31E5ED4F8B54AA2ULL, 
            0x5EDD47B3F0973D7CULL, 0xB0EED99DA7883017ULL, 0xED7068DB562D4E3BULL, 0x7E597AB63734D818ULL, 
            0x0499968BA57F89F4ULL, 0x64CEFA5B218FD592ULL, 0x212EACAFCA62E3B3ULL, 0xF5FF32FB072602C7ULL, 
            0xB53220BC5C60A68DULL, 0xD69D0780F7E9B899ULL, 0xF224CC614CA7F654ULL, 0x4D301AB2495E843CULL, 
            0x015FA929E92C726DULL, 0x4494D60533D332B4ULL, 0x0FE51CEB9A1B7D26ULL, 0xFDCC0ECBD357E987ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseDConstants = {
    0xE80584962D43EBF5ULL,
    0xA8D2CC09C46AA828ULL,
    0x8A5DF8318B92A86DULL,
    0xE80584962D43EBF5ULL,
    0xA8D2CC09C46AA828ULL,
    0x8A5DF8318B92A86DULL,
    0xC4A9C932E7874818ULL,
    0xC60DAA2BE328ABA3ULL,
    0x96,
    0x49,
    0xD1,
    0x87,
    0x3A,
    0x18,
    0x62,
    0x73
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseESalts = {
    {
        {
            0x38B801C57BC325B5ULL, 0x5E3B2C61FF72E353ULL, 0x0C12980326327AB0ULL, 0x3783141DABBB9CB5ULL, 
            0x24FB2534E648B798ULL, 0x7903009BFE69933AULL, 0x354FE1F675C1BDFFULL, 0x48464D21B8126DE6ULL, 
            0x35D1C4A95D8F8302ULL, 0xFF44F86A1A9E7A85ULL, 0xB549C25A9ECB4BEDULL, 0x6FB65E603F52C385ULL, 
            0xB21B42C10ECDBF32ULL, 0x1BEBF78DD9E423CAULL, 0x5FDE93F9DD0BCF25ULL, 0xDC6E543620B24CEEULL, 
            0xF2890452A16CF793ULL, 0x0F34F2FD027C6193ULL, 0x5A39F92F07F69C4CULL, 0xFBD3ADC3E5002DC2ULL, 
            0xF72C6665389A2EE6ULL, 0x1A87A882DD058015ULL, 0xED00A98EC4B72D30ULL, 0xA1C9661CC795D58CULL, 
            0x8FCE0BFD48310230ULL, 0xAA11F0D1285C4E11ULL, 0x4A2CE162F764537EULL, 0xF0D66CA9D2E8CCB6ULL, 
            0xD19339BCBDCFDABBULL, 0xEBD7B92751608AA8ULL, 0x8A6A99134AF4FAB8ULL, 0xE61AADC3C05EDDF9ULL
        },
        {
            0x421213AA46FABD46ULL, 0x3D96CCF12915EC85ULL, 0x37F5FB6C42DD00FEULL, 0x5CE37473CB912823ULL, 
            0xF66D25D35E55716DULL, 0x226263B48B40DF55ULL, 0x2A4E461EE69AC115ULL, 0x03F3C5FABAA18A61ULL, 
            0xC0D838020CF04D3BULL, 0x3DF9CD33E1A426EAULL, 0xA0B3012D33DFB5A1ULL, 0x56E7855DAD069B5EULL, 
            0xC6A1DD019CB8E6D4ULL, 0xD66AAD80CE3F7951ULL, 0x163746653D00B38FULL, 0xD5F923E6C3DE56D4ULL, 
            0x455DABEFECC7E526ULL, 0x963F0762F811433EULL, 0xB4EC6168A80C2F1CULL, 0xDBD39B7DFB92B84BULL, 
            0xE7B38AD9D6AEB254ULL, 0xB82D8B5967D870E5ULL, 0x03444E196FBB590AULL, 0xA6FF63ECC04F9BD1ULL, 
            0x0D48EF6B61F47190ULL, 0x62E681A1A7EB6D80ULL, 0x8FB2831644F2EBA0ULL, 0xB0CAB77EF05FE623ULL, 
            0x9A382E8D33B2709AULL, 0x11E0A72641C688E5ULL, 0x45803BD7F1CB5545ULL, 0x1BE05FC1102B7847ULL
        },
        {
            0xDA224FDFFE07BBFCULL, 0x0A54FC2C46E64762ULL, 0xFE1AE9FE942948FBULL, 0x6D6D6BEA03FDE83EULL, 
            0xA46B6E05E48D2E63ULL, 0x36CA49A671933E1FULL, 0xA42D680310F130F3ULL, 0x7656EFCE91F1F922ULL, 
            0x3B842842F2FE3A8FULL, 0x26DB73085F177ED0ULL, 0x9583028F428FCEB8ULL, 0x7506D8E610837363ULL, 
            0xCC7A0B6D63E6D625ULL, 0xAE46AC26D800F60CULL, 0x269BBB7F82FD63F4ULL, 0xA4CCE4D53B1169E5ULL, 
            0x63957ABB5E1A623CULL, 0x4ADC6AEC36D0F2AAULL, 0x349972AEC218B0BFULL, 0x1ED063301F4EEB4DULL, 
            0xFF94FA3A1A330886ULL, 0xB6DB3383F0C1DC3DULL, 0x55519B09C7368BE2ULL, 0x5E18D3CDCADB731AULL, 
            0x5776A80B379C69B8ULL, 0x2B7E1CB4E8A85B3BULL, 0x69CDEC9E35DBDB98ULL, 0x92BA1719BFBDD331ULL, 
            0x71779F4B868FD930ULL, 0xD11C626123D8676EULL, 0xCF18D452CDD42ECCULL, 0x12E624202F0BE1ADULL
        },
        {
            0xC3788A41EE814750ULL, 0x63FC9784594C4F73ULL, 0x7C684E2E31291A01ULL, 0x276450F3BC66B9C6ULL, 
            0x3913BB0FB3A10710ULL, 0x676A573551DF0FD5ULL, 0xB4BA0F680DBD43D9ULL, 0x8EA8C244BBFA735DULL, 
            0x49B9C75CE81BACF2ULL, 0x6CB1B6ACE1AA3841ULL, 0xCF52315A894F2A90ULL, 0x45C8DD91E666594AULL, 
            0xA828156B42E6A708ULL, 0xBC4C7A01511DF358ULL, 0xE16D272053133538ULL, 0x04CD7D1E116CE47BULL, 
            0x511EBAD1F4D2B78AULL, 0x42D64FBB99A27416ULL, 0xE9C3937BF58D85A5ULL, 0x7A05B86ECDCBD595ULL, 
            0xFAE372A662C0A0D3ULL, 0xE961B2DC8DA13ED4ULL, 0x248E294C21779D47ULL, 0x77DF8CBDF63671F6ULL, 
            0xA463F42C08B2D6DCULL, 0xD327758A7E0BC140ULL, 0xA3503C380B09107DULL, 0x7326980384A9BEADULL, 
            0x25DCCE31C4642630ULL, 0x00A59254D3C846C9ULL, 0x6B23CEA34A601204ULL, 0xECDDA415E51B8AD2ULL
        },
        {
            0xE00590D69E300542ULL, 0x7403B8EF1872283BULL, 0xC2241490C503C620ULL, 0xB8A5FAEF744DC170ULL, 
            0x62427BA03362D662ULL, 0x81E0ACCEC1ADA3ADULL, 0x08EEA8111EA043B9ULL, 0x1977D11C43F8D367ULL, 
            0x355A49D9D58B4C25ULL, 0x26B4A9A76135ACE3ULL, 0xB073DCE6F2609FA5ULL, 0x048B12A12813D955ULL, 
            0x190AD7AA70FE51D5ULL, 0x5F7C55FA647234A6ULL, 0xE6CF0815D163EA38ULL, 0xE3ABB73298F99682ULL, 
            0x0DF58350699D586EULL, 0x8054D67466217735ULL, 0xDCD2C8C49892F591ULL, 0xF252116401023B8DULL, 
            0x46563CB14C71584AULL, 0xE67A4325EA610C46ULL, 0x4A43DF920F2D2997ULL, 0x863C155D97D462DFULL, 
            0x1E7A07B4B59BB075ULL, 0x8DFFD827EB64896BULL, 0xB0435EEE6157A280ULL, 0x8A3B2AF4C0BA08F4ULL, 
            0xC7E6DCB2AD66F0D4ULL, 0xF6B8B950099496F5ULL, 0xB23B5ED8C6CEA4A9ULL, 0xDA6C0D26A797E242ULL
        },
        {
            0xB983760418FBB99BULL, 0x3C143A498DAFCB40ULL, 0x5FEFDDF8843C8922ULL, 0x833453C4A6838F18ULL, 
            0x4FF6C112BDB7F4A8ULL, 0xA4293C5204DE7E7BULL, 0x8A6C4F877505B054ULL, 0x8EA004057DBFC4F3ULL, 
            0x96F66B402D101740ULL, 0x47F453B5E21FFEC3ULL, 0xE39E5965112CA985ULL, 0x7D17236E2541B26FULL, 
            0xC59CCF1BD3C98DA9ULL, 0x736AA0DA9C73EB4DULL, 0x857130AEBECAD890ULL, 0x4555FE6F7EEA2C66ULL, 
            0x0C572BF2ADCDC0D1ULL, 0xF006466C2E7B4CD0ULL, 0xBAE994167ED2E345ULL, 0x08321B42CF3B9E29ULL, 
            0xEE009F1A7D43B8EBULL, 0x08E6FAD72B4BA9FDULL, 0x192A69598C0BA92FULL, 0xA67F9B7D60695720ULL, 
            0xDBAFEE5C3259E1A5ULL, 0x105AB1C0808648A5ULL, 0xE96052BB69A533A6ULL, 0x75D548E6FD9ED6BEULL, 
            0xCE5141C1281DD785ULL, 0xE7BFD8AB8D8CFABDULL, 0x005046A14C489902ULL, 0x1380A8764BB7D574ULL
        }
    },
    {
        {
            0x5C3A7370A897095DULL, 0xD569CADA6644610EULL, 0x72319D4E85F1721BULL, 0x8B3913BA2A9835EEULL, 
            0x480EEAFA76941952ULL, 0x990CBAF2FC22691DULL, 0x844A422D09EE5D03ULL, 0x4082CACE2081F665ULL, 
            0x4D0123D4E5A9F80AULL, 0xD6095D9EDE6D46D4ULL, 0x07C19865013E001EULL, 0x4A6B409B95D752E7ULL, 
            0x6C9687AFCE0736CFULL, 0xED8B77E435168AF4ULL, 0x10158E62E1CD91CBULL, 0xA6E77F5B943E5A61ULL, 
            0xCADDBC0CF40A974DULL, 0x939EEB5525DD96EFULL, 0x7F7284116D3BE5ABULL, 0x770973BF2F87C84EULL, 
            0xA86C734DD05E51BCULL, 0xF75BA93D50984700ULL, 0x324C2B0F4C8F5481ULL, 0x3743F22160B1DF9DULL, 
            0x469955AF227B8DE5ULL, 0xC5C308172DF3F000ULL, 0x3A671B0A8D8FB64DULL, 0x42B15BF1AC0495E4ULL, 
            0x70A7C57773A86F26ULL, 0x6F758C5843957CC4ULL, 0x56C5021D7137BC18ULL, 0x8A9A2C429EEAD2D2ULL
        },
        {
            0x4DC537DA107A8C5FULL, 0x2C6762316364A8FDULL, 0x0F2D78C4F8802F5FULL, 0x032D59D7928432C1ULL, 
            0xCCFC5A5FB004AFB0ULL, 0x42B4360B7200AA6DULL, 0x5ED3726833B973EEULL, 0x18183007B20C018FULL, 
            0xF7D29AA81C795D9EULL, 0x3C0532C7AC2DE0F4ULL, 0xB04562E18DBE1A6CULL, 0xD6196F06F9F2C39FULL, 
            0x2FAFC2B16988A065ULL, 0x910C330535467007ULL, 0x1EBC5728CA94C237ULL, 0xE93148C6A4C44A0EULL, 
            0x829AA70A10CAEBB1ULL, 0xBB4FE0E7A84A7BE7ULL, 0x69B6DC0C13D362FEULL, 0xF36450DECEB7BD2CULL, 
            0x59435DE6A1C33F99ULL, 0x7FDDF4BB9D230F4AULL, 0x9AB5A36DD9049025ULL, 0x1E6A1B6B9D355D7CULL, 
            0x6409C1EDB7FFDC30ULL, 0x7C74516848FC8996ULL, 0x8DD96B266006F26DULL, 0xDC3E4807801453D4ULL, 
            0x6E199ADD93045194ULL, 0x51E31CF8FDD44097ULL, 0x408D2E0AD7E0C6CBULL, 0xCBA878D5C5D7845AULL
        },
        {
            0x3D577E8E765D1070ULL, 0xECDCB4CF1E3AAA33ULL, 0xD6784A73B18F260FULL, 0xCF6148CF10620B01ULL, 
            0x139D73D9EFCEA090ULL, 0x9E34B9D63C8A32C9ULL, 0xFB47CCA5EA48E396ULL, 0x2E2182B1A932047CULL, 
            0x3B7B6E6D12A24A98ULL, 0x9E93BDBBECB75736ULL, 0x94821A10D0DA09F6ULL, 0xC0E6BAC78E1CAB76ULL, 
            0x92B938BA358C84E7ULL, 0x65E1BC27D0011F17ULL, 0x2FBA09FBC8AF4D66ULL, 0x21269E05E3168F0FULL, 
            0xFA74C559B9D2092BULL, 0x3C249E4B69CA2EFBULL, 0x88AF657A63434CC1ULL, 0x3BA663C6682A5E72ULL, 
            0x083572FBDB790010ULL, 0x00081416F5C1EB81ULL, 0xD0998C73B830E8E6ULL, 0x11392BD773866E07ULL, 
            0x4085F29BDCFF5547ULL, 0xF352065CAC639FD5ULL, 0x048DC5CDA5E2FE6BULL, 0x3030D19FDE63C0FDULL, 
            0xF75372BC3EBA05D1ULL, 0x80E4E0CFE6DEA8B3ULL, 0x239649E1289DBE76ULL, 0x89647D62E702DE07ULL
        },
        {
            0xE2E080F385AD7FEAULL, 0x0F85A4FE75816E19ULL, 0xE4DB5C50614D1480ULL, 0xE8DAA36A4FC30D1EULL, 
            0x8501450E7C44C324ULL, 0xC858A03D668DF13CULL, 0x2E44FC3E7EF1BA94ULL, 0xB81A78B9730768C8ULL, 
            0x1DB368E0197AB172ULL, 0x16F7093F842E5D47ULL, 0x9DD4FFFE3300B6FEULL, 0xA7334536D5E96C9FULL, 
            0xA0FB683179BA1A5DULL, 0xACF1989EA5008986ULL, 0x861E59701469EB6FULL, 0x3304180EF7D575CEULL, 
            0x8EBA568FAD1CF200ULL, 0x5C5B97887BABEC65ULL, 0xC7BAE042B1366683ULL, 0x666DC34CB647C8EDULL, 
            0xD796628D08D0595EULL, 0x8D81001D570B397BULL, 0x961457CEC4D9B18FULL, 0x7158924E8AD7C50DULL, 
            0xC66DA752FC213A05ULL, 0xCFC89A59049911A5ULL, 0xD47970E5614EA2E1ULL, 0x6CA591F0441AF383ULL, 
            0xF3FCAC5281C0815DULL, 0x95B11E3F13047E77ULL, 0xE59752295C94367EULL, 0x0CD56C04A35BC3E1ULL
        },
        {
            0x4BE12E4C06B2F1A8ULL, 0xFBA8CC590C01CC27ULL, 0xE29E728D7506495FULL, 0xD914936805F6C148ULL, 
            0x1736788D9B4CD49CULL, 0xD738A5F21DA051F9ULL, 0xC4D4F5EAF529255CULL, 0x554F062A482DF573ULL, 
            0x3CE40AF8D65684B3ULL, 0x16C01E115CF42A8AULL, 0x750769BC9E417873ULL, 0x9920DD3C751CE529ULL, 
            0x9B1FDA2F4A14B0ACULL, 0xA798499F0BF23ADFULL, 0x05407F897315FCD6ULL, 0xE8EB6C8F49502B16ULL, 
            0x884407F41ADFB575ULL, 0xF7E53F5D27CC7ACEULL, 0x1EB5D40B3A3839C4ULL, 0x7A3FE30742B81CB5ULL, 
            0x10EA38B3EA2B80F8ULL, 0x1E803B195322FF4DULL, 0xBAE87BA6F82AC6C7ULL, 0x138CC73B37F05C51ULL, 
            0x16A9BB376785B637ULL, 0x80D7A113F221801FULL, 0x6EA7D2BCC3916F70ULL, 0x06092F1F61A57D4BULL, 
            0x92F0892D64FEA0E6ULL, 0xE2CFC1F37F8747CBULL, 0xBFC2117F02BA4DB2ULL, 0x601038E65AD0B66DULL
        },
        {
            0x6750A685633E8E3DULL, 0x2E2B637CC163F2FDULL, 0x86963FEB21DA0451ULL, 0x8A2345CCDA8DE23CULL, 
            0x7348AE47442237AAULL, 0x8FC976272B07B124ULL, 0x97959088FBB740EFULL, 0x8A30EEF36B5B8570ULL, 
            0xC67F14B7935D21B9ULL, 0x55F593722D4826E2ULL, 0x1B8C7E4D2666630DULL, 0x9A9539F7DEC2EB69ULL, 
            0xA1F8B0B0416BD21DULL, 0x59C864EEED98F6A1ULL, 0x4600A83055D55E80ULL, 0x9A2A47BDF4906BADULL, 
            0x073353FBCDCEB071ULL, 0x9FB8CC162B5B8B25ULL, 0x7BFAFF52732E66CEULL, 0x27AFA350F4C95F68ULL, 
            0x176942D828EDC91AULL, 0x3DB9C4DB06DAE10BULL, 0x14B843FE6F4EDAD3ULL, 0xF0DA79306A6B9DD4ULL, 
            0xB619E35043DA49FEULL, 0x283CB034F6DD07DDULL, 0x51D5AAC916D4A953ULL, 0xB9354D80F506B8AFULL, 
            0x3319BDC43DAA8E45ULL, 0x80DE72C376791616ULL, 0xA42B183628D9DD3CULL, 0x42E548B5A19BF046ULL
        }
    },
    {
        {
            0xFBE422DE19A486FFULL, 0x2C3B8EA6AB8AD2E6ULL, 0x54461C02C51DE846ULL, 0xAFDAF56004DD90D0ULL, 
            0x28C8BC4F484D067EULL, 0xAF4AF150A8A763BCULL, 0xC4A92F6943C65AE2ULL, 0x19F3D73EA4C3758BULL, 
            0x1743B73C383FE2D2ULL, 0x3392A997131ADC5BULL, 0xDC9DB6C6D2EE5B38ULL, 0xE1D86F2F36B48E7FULL, 
            0x87FE03F17773D1FCULL, 0x39A988C0C45F602AULL, 0x5E29467385D5C6C6ULL, 0x73B302B8BBEBE1D0ULL, 
            0x77CD81E1ADCFFB25ULL, 0xCD5A02C93CEE6F8EULL, 0x436F2D7958B6BA10ULL, 0xCAD2D3DBD4124E3AULL, 
            0xB4F14894187C9CA9ULL, 0x81A313BD46A98F54ULL, 0x9598CC0136625596ULL, 0xAA5A3C1143CE9D6EULL, 
            0xA209D81ECA534D50ULL, 0x291B86BC225F03B9ULL, 0x86C378D8B0BFD03BULL, 0x39C3AC2C5DEFB211ULL, 
            0xF0696C6EB80FF0D2ULL, 0x5088025AF87B942DULL, 0xC2E733E1B1ED5C01ULL, 0xCEFCC6982894DEDCULL
        },
        {
            0x0876842BB8727A27ULL, 0xF2CE3EBB7F507727ULL, 0xAAC5D4E239800B40ULL, 0x1B5613408F403561ULL, 
            0xECE8E59772C07F6AULL, 0x9C205BE8D956A086ULL, 0xB642947398B66253ULL, 0x92258047FA08C3EAULL, 
            0x1CDD530D01DED09BULL, 0xA35767BB532A953AULL, 0x5C37203924B50033ULL, 0x9CD5F8B7A3ED995FULL, 
            0xA5291F9CE14E0360ULL, 0xD13BA00C2401D5A2ULL, 0x0B3C4EADFC3BFA9FULL, 0x467411C72E212E50ULL, 
            0x7BBADE7FA35884FDULL, 0x07A3BE6A569E1A72ULL, 0xF219DAFA824DCCA8ULL, 0x511A82D6C5483364ULL, 
            0x240312D6BA280261ULL, 0xE192BECD04A6E966ULL, 0x4683850193127C87ULL, 0x73EB8C81DD687505ULL, 
            0xA165678D6E755CD0ULL, 0x4E689AC26A69C67BULL, 0xD15F83749001BF64ULL, 0x4CAAE7ECB034F408ULL, 
            0x13A2BF34A2BFE7A1ULL, 0x8242763A6326659DULL, 0x6AF85F662D2BBB8EULL, 0x138A76B3C18F8DBAULL
        },
        {
            0x7FA9AFD97027D369ULL, 0x7AE3A5B5620268D6ULL, 0x219E33EF20D224A5ULL, 0x97E27352A0C53201ULL, 
            0xDFD335F25809721EULL, 0xA5BC885803161FC0ULL, 0x2016CB193718BB96ULL, 0x25750DBAD35ADC6AULL, 
            0x61336AA6B4A79424ULL, 0x5CA2FED5EA3BF8C1ULL, 0x71D6664A78629164ULL, 0xF0465FA6DA9CAB54ULL, 
            0x59253F770F08FA4BULL, 0x449A9D2B2735232AULL, 0x6232EA01D0AD9D0AULL, 0xF41083693276B848ULL, 
            0x1A2611C9FB57E85AULL, 0x210D42E0EA783DEBULL, 0x57407CE1C72A25D3ULL, 0x8B53371357EDB5CEULL, 
            0xE5E5E87BA308E06EULL, 0x320025150E0A9AAFULL, 0x96E18A3F32CE274EULL, 0x1055C50BE01C8E09ULL, 
            0x960EB76730F7FAD1ULL, 0x68E5137900A21E72ULL, 0x48ACBC38CC5F77D7ULL, 0xA83C3458DE56DBEAULL, 
            0x734BF5C839C5D5F7ULL, 0xBDFC9CE382E2B1B1ULL, 0x7F2314DEC11FCD05ULL, 0x857D0959A9CC27D0ULL
        },
        {
            0xCF65ECA41700F154ULL, 0x4A5DBFEAF8F5927EULL, 0x539FEDAF6F20FB2AULL, 0xC7941BA21FFE30E9ULL, 
            0x9D15CC8D846CCC48ULL, 0x0F1F3212B8E76C35ULL, 0x6D042191CDDB896FULL, 0x6D171B2607F72CBBULL, 
            0xC5D0573F70097975ULL, 0xC764F1A2E4688168ULL, 0x1A54C0A325BD6A36ULL, 0x33C087B9CAF248BDULL, 
            0x4A454704043C20D9ULL, 0xE32177CB494249EEULL, 0x4A161679EF0F6E41ULL, 0xD9A35A09ABD109F2ULL, 
            0xB6CAA0FBCA2BD6D0ULL, 0xE04533C1C5547709ULL, 0x7F71F11C4A1544CFULL, 0xC5B2253500092B02ULL, 
            0x0E57C19309D53B0BULL, 0xC87B4A1695745880ULL, 0x377B0051BA0D2D40ULL, 0x3C5EE243C6220A15ULL, 
            0x5AE013974B785270ULL, 0xBDF4D490C52DA308ULL, 0x55F8008EB7518B53ULL, 0xB7F06E07BC904F3EULL, 
            0x330ECDF69245DF70ULL, 0x36DD00DB4AE9219CULL, 0xA0154CDA2C16D549ULL, 0xB50C372AD51E6BC8ULL
        },
        {
            0xB8FCB7FB162BE187ULL, 0xBCEC2B62302F496BULL, 0xC817300C9C905E63ULL, 0x58AFF8F8641DD939ULL, 
            0x68C97E949A36348EULL, 0x82FA34AD656FB716ULL, 0x68D1777997CDBADDULL, 0x61C70DEB5A0A669DULL, 
            0xBD4ED0D981D8BE30ULL, 0xDF1AAB7FEC559CCEULL, 0x9EF518EF9FF80479ULL, 0x85BE52DF37B7DD1DULL, 
            0xFDAC76E2762F6718ULL, 0x28A3DACF2748B8D5ULL, 0xDFC08139805C85A5ULL, 0x8BD64205FED64D29ULL, 
            0x50C6A20A3A4810ADULL, 0x6280E8C3D02F71A6ULL, 0xCFF02D02341BC069ULL, 0xCAF73F07F7E54812ULL, 
            0xF7DCB64C9B14DE59ULL, 0x7F50D016EF426D5FULL, 0x8D9A9EB4ABE30703ULL, 0x7C780F0CB607C3DCULL, 
            0x0DBD2A46B0A2F929ULL, 0x94A37555D8548B8FULL, 0xC96BED645A8348D8ULL, 0x6CF8A83014FEA032ULL, 
            0x88DCE2A3902FDAC1ULL, 0x47D51628147E3770ULL, 0x99BBAB15B82D1AD0ULL, 0x84CC8341A02BD502ULL
        },
        {
            0xBAAC46A655B75F8DULL, 0x576FBD31972B035CULL, 0xCEDF047931AC38F8ULL, 0x656A8676097D2D3CULL, 
            0x0462032E2AC67C93ULL, 0x86535AA5A6279E83ULL, 0xA47F64316E2CEF86ULL, 0xBB986DD2A7064297ULL, 
            0x9D0DB2CCE22EA5C2ULL, 0x0D76495611E0B003ULL, 0x7EA4DF27A1E249ECULL, 0x8E392EE081C3113BULL, 
            0xBAD85A9A147C5281ULL, 0xCB33B97CE403A880ULL, 0x105BE53B818B63A6ULL, 0x2C1153C044ED36E2ULL, 
            0xAF41F9B28233C47BULL, 0x5A942343A1A8D1A8ULL, 0xDDCD93A5A369432BULL, 0xF7DDE9FDB2343BA7ULL, 
            0xDB59B61ACFCA6DFDULL, 0x2A17D442E2781109ULL, 0x4872B1FD74FC8893ULL, 0xB535AC84B32031FBULL, 
            0xECC95A2AE680209DULL, 0x2CD3B6585A75ED06ULL, 0x281AFC76EB695A7CULL, 0x9101FDAE3E56E7C9ULL, 
            0x9EF299D4A885EA8EULL, 0x7653536AD82A8D33ULL, 0x6187A9F606736794ULL, 0xA67C697A895BAC27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseEConstants = {
    0x994627CB3B2D33C8ULL,
    0x6FFF2F91CAAC8BB6ULL,
    0xCB7451D7842F54F2ULL,
    0x994627CB3B2D33C8ULL,
    0x6FFF2F91CAAC8BB6ULL,
    0xCB7451D7842F54F2ULL,
    0x2DE66E98DBC63B86ULL,
    0x772C02E91BA09271ULL,
    0x75,
    0xFC,
    0x5D,
    0x60,
    0x2F,
    0xB8,
    0x72,
    0xF0
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseFSalts = {
    {
        {
            0x5E60DB4E315513F5ULL, 0xC0EDCE11FC4BEB6EULL, 0xDB4A369636FCA8E6ULL, 0x286919AC7736D701ULL, 
            0x497BECDDFB93CDDDULL, 0x3E429F4BE597AC98ULL, 0xD62154C09F99AE7FULL, 0xFD0D08ACBB0A0C6AULL, 
            0x0C8B14B57202280BULL, 0x5275AAD73201CF82ULL, 0x48278D9DED49E869ULL, 0x8DE6CB800E4ABAADULL, 
            0x72651920AF9FB37AULL, 0x6CDE5F93EBAAFE2DULL, 0xE4EE8FB7ACAC0BBDULL, 0x28A7BF7599D743A1ULL, 
            0x35A0B85C8A3E7E89ULL, 0xCF0959A7E02D7EE1ULL, 0xB84F26A97C119D74ULL, 0x093C0535F73EF653ULL, 
            0x7B651101FC7B9895ULL, 0xB049E1308AD2BADBULL, 0x26084B4B9C239E5AULL, 0xF6289621B3BD6678ULL, 
            0x7BD953901A79FA94ULL, 0x8F58DA7B7C57046CULL, 0xE041D029ED20060EULL, 0x657337FE01A7FB93ULL, 
            0x90B4F59AE9698CC8ULL, 0x00120DBEF32F8502ULL, 0x354140A7A1B4EB19ULL, 0x706C598BD814CF04ULL
        },
        {
            0x62F1D9D4F668CD4EULL, 0xE28C357AE9C5F6F6ULL, 0xE76ABFDDEB819237ULL, 0x1FBEAAB49C224C4FULL, 
            0x7EDD9CE04E99A630ULL, 0x85CCE08B3F7B48ACULL, 0xA0849AEF62A2246EULL, 0x456DC7B330EB3198ULL, 
            0x4CF506F7D62E7E24ULL, 0x8E65708DE6C67F64ULL, 0x0D53030267ADAC19ULL, 0x5A6D48999BDE0C94ULL, 
            0x293BE88905D31B96ULL, 0xB1F4D75AFD4BB8CBULL, 0x8DCED7947D6DB510ULL, 0x65939CC758E60700ULL, 
            0xFC524A34E2B7EB1BULL, 0x708073BA11F59966ULL, 0x590D6D283599D2B7ULL, 0xCF41EEA3289D6990ULL, 
            0x21FADA4200F2ECC7ULL, 0x27BC56D41F41C0D9ULL, 0x67D55EAB36C831E5ULL, 0xD945884F8C4EDCCEULL, 
            0x2369348DB481CCFAULL, 0x135F6AC84A7C8DD7ULL, 0x12CBC1207089038FULL, 0xF779E06F33852442ULL, 
            0xDEFF39E44B32C2B0ULL, 0xCD20447E979AE7AEULL, 0xEEAF939B22D29059ULL, 0xA539D809653F38A4ULL
        },
        {
            0x796DD6096621CE91ULL, 0x4BA8077E8A37AE8CULL, 0xB5AE507ADA75879CULL, 0x1F5DDA5EB6DB4762ULL, 
            0x0A5DA39B2A5F32BFULL, 0x67AA3A784AAE34EAULL, 0x56ECBA3A32BAB1F1ULL, 0xBFDFA1DF233A887FULL, 
            0x60A389F3A30BA8FFULL, 0x1D043060B898B667ULL, 0x256214521BFD873AULL, 0xE1172A43A253876BULL, 
            0x29812E6FE51ADDD0ULL, 0xF5243578F3EAE329ULL, 0x677B211A95645625ULL, 0x4990EB6081580CC2ULL, 
            0xFBA3BB1E36662C4FULL, 0x703810C6A70C7F42ULL, 0x1A648E216CF1FCF8ULL, 0x09EA5EF460A8FB35ULL, 
            0x943D0DEBB2E45876ULL, 0xFE6D45D871BF4420ULL, 0xAE5767D4E1EF72A9ULL, 0xBA144634885E4FE0ULL, 
            0x9E3502FAC6CF6279ULL, 0x032D40A07A4F5B13ULL, 0x2005F8A2EEF27C49ULL, 0x8E33ED12CE162AFFULL, 
            0xD3160649E1F16976ULL, 0xEE466D80C2B14054ULL, 0x9D47BFEC7DF1FE06ULL, 0x55E942C5595A90ACULL
        },
        {
            0x949D7862F3F20C0EULL, 0x2A273186CA180F47ULL, 0x94B2F938DA2F8FCDULL, 0x8FFD9C136D065792ULL, 
            0x0413C19280B8AA5DULL, 0xFE0B7A1F2308A48EULL, 0xD559F7C82A06BCF9ULL, 0x5D642A1536290168ULL, 
            0xD35DC890067E1A21ULL, 0x26909AA7D7DED38EULL, 0xEF223504E3EDBDABULL, 0x89EDBD853FBDA5CBULL, 
            0x8377955FA3AB1AEDULL, 0xBEFF320DEC620993ULL, 0x5D4CC1CF13733D1FULL, 0x090A10D1C0865E99ULL, 
            0x03F0D3007EB8D983ULL, 0x11E4E9D0DD8A9EF1ULL, 0x380E5C325955F073ULL, 0xC10F2F653BA82464ULL, 
            0xF59D4900D51055D9ULL, 0x44982BF867DC6856ULL, 0x82CB011FEAA36703ULL, 0xAE7D307E1F3B2034ULL, 
            0x6E5222D6297FE777ULL, 0xDCF355EF87403E05ULL, 0x076F2DBB626AA9A9ULL, 0xA774639133F73C03ULL, 
            0xEAAD158E9153F017ULL, 0xF91C8288BE63DB78ULL, 0x69D470F4303D2038ULL, 0x96DAE4DE9EFB0EB9ULL
        },
        {
            0x275E1C303B8E5A5FULL, 0x4C562A1B8C00AC02ULL, 0x0483D4889D787463ULL, 0xC6E8C4232B8461BBULL, 
            0x22C24B5AF6BEC5F6ULL, 0x4C8ECA4E36925366ULL, 0xAE3C8602A62ED8AEULL, 0x8535CC5092252597ULL, 
            0x92F9B2BBC7C17F22ULL, 0x75DFE9EB97190F0AULL, 0xF2026F7315A77DA7ULL, 0x6866101ECDA5B36EULL, 
            0xA075B99A10B2B10FULL, 0x65D3BC71594328E7ULL, 0xA698AC7FA3D9F0ADULL, 0xA660A93A815400D8ULL, 
            0x5AD39B705F1FA52BULL, 0x60560F91EC5EB05EULL, 0x962B5E1379C1FB8BULL, 0x6823A35A11F3CD70ULL, 
            0x0468EC98154867C1ULL, 0x21D9AB1F681FDA6EULL, 0xCA4A8D154B77450BULL, 0x6668FC6AA0398558ULL, 
            0x9A104CF9374EA555ULL, 0x10932CAE64820F48ULL, 0x35CAB26EE0731077ULL, 0xD89315F9DCE76835ULL, 
            0xBBB2469B27B3F24AULL, 0xCE94A05B4939F3A8ULL, 0x99DCA6EF75A2DE6AULL, 0x5D2FD5E1E711FE6BULL
        },
        {
            0x5E764479B90BD9BCULL, 0x090736C5C18DF670ULL, 0x46606182D118C42EULL, 0x38BDB149973E5687ULL, 
            0x6705CFCF391AF8A3ULL, 0x4604EE5E6710EA06ULL, 0x5B42B17F262A8AEAULL, 0x64D4B8EBE31470A8ULL, 
            0x9E837D3C4E2B01FFULL, 0x1A0A7378784D603EULL, 0x3AE3090954934D1EULL, 0x1A680B721197997CULL, 
            0x6346B8F4B8D2D5C2ULL, 0xF6E1DC67CCCE62DFULL, 0x0E91AB3F447EC88FULL, 0xB22E3EA470052AD1ULL, 
            0x8C447D20EDB4529EULL, 0x47C54A663E4A393DULL, 0x3D18611F10F376A4ULL, 0x8C222DE4D6A81A11ULL, 
            0xAECAE1E7819E9FD7ULL, 0xA95569913D1A027CULL, 0x86BA4D8295716DF8ULL, 0xB090EE44868CB536ULL, 
            0xBE64C2A127000F3DULL, 0x2CCB723AD1071BD0ULL, 0xBBF1ACC038D984BBULL, 0xC1C3722A86614702ULL, 
            0xEE4A77D82F7573E7ULL, 0xEDDC4337A93C2EBEULL, 0x8456B21F4A4CFDDDULL, 0xE9EE8ED785CEF7CCULL
        }
    },
    {
        {
            0x28DEFE08F6256DD7ULL, 0xD77F8A67D4A49292ULL, 0x879011815219749AULL, 0xFDA80D237AB6F851ULL, 
            0xFE7F23D630F5CB92ULL, 0xAD9DF56DEF4FD027ULL, 0x2DD2443AA2D9ACAAULL, 0xB4AC6B80DD0EE3CCULL, 
            0xA31DAAC7D3872180ULL, 0x54D4AD50D9E5F7EAULL, 0x058E676D24870135ULL, 0x7AB953651E24B849ULL, 
            0x30604F25267F29CBULL, 0x1BE969E7A907D978ULL, 0x3C6120E7168F7950ULL, 0x7280978FC3A6A3F0ULL, 
            0x8A044A5E0D7BE5E1ULL, 0xC58D9C4CC5EE92FFULL, 0x35B2532B69D78F90ULL, 0x65590494F82C05A5ULL, 
            0x3F808ED97A643989ULL, 0xED8219B287F49131ULL, 0xE3381A44EA8C6D08ULL, 0xDF3889DA741FB974ULL, 
            0x08B496B393AFB6A4ULL, 0x771D82063B157429ULL, 0x202C9B1AFD67032EULL, 0xDAE2D8898108E4A0ULL, 
            0xCF66C84044CC642DULL, 0xB194A5C63272D0ACULL, 0xAC663D84EA6BA910ULL, 0xF742449BE522200CULL
        },
        {
            0xD4438625505B1B65ULL, 0x77D424547FD06C42ULL, 0xD51C36CDFB9203C4ULL, 0x93B2091062C6E6A2ULL, 
            0xF0D28880AA2A8293ULL, 0x8F1DDCAC2413F38BULL, 0xDF937048B43BA10CULL, 0xFD55388642790E01ULL, 
            0x24E9C342BA365788ULL, 0xF629DDF64D0FD02EULL, 0xE1E371F33777B958ULL, 0x7AAFD11F41446109ULL, 
            0x7754F12722A27A2AULL, 0xF46C97F06C728CF0ULL, 0x4C7A8648F373F7BDULL, 0xE8F2B5F4343C2169ULL, 
            0x14B0D2EF27C7D265ULL, 0x0FE79AA634E17B3BULL, 0x465CEBC74C3DA64FULL, 0xBC280316A425A9BCULL, 
            0x7355C92232745E1EULL, 0x60B2B77063F6374DULL, 0xAB270E0DED7726C1ULL, 0x564464E51A30D484ULL, 
            0x52CC4161B2C5331BULL, 0x7A125F2791C16EE6ULL, 0x42AD02AD3064143FULL, 0xD72006EFC314D5F8ULL, 
            0x4FED38612542F2A6ULL, 0xC793539341A1BA59ULL, 0xA6C5DAB6CFF93A51ULL, 0xD0EEF8DBD8CAF54BULL
        },
        {
            0xA49C1EA75C841192ULL, 0x053AEC9C18F5A374ULL, 0x0D61BDCB70649B0BULL, 0x6AB8E0F5DFB88D37ULL, 
            0xF0C1C88AC4134DDDULL, 0x66E41D6B9A659333ULL, 0x1DA45B009661F307ULL, 0x503AD219F4484157ULL, 
            0xB4B39F40E09D0A96ULL, 0xC155F1F2686FDEB2ULL, 0xD081CB9C103307F8ULL, 0x2900DF98B8ABBAF0ULL, 
            0xDBA662B794117D8CULL, 0xA7C3531516647175ULL, 0x1B0D69980E954C15ULL, 0x81FFFEE9963328F0ULL, 
            0xF43AE21E76487C72ULL, 0x847BF53FF5B6CE76ULL, 0xD57F462170524B44ULL, 0x88FD43FA775945E8ULL, 
            0x1C2BE2502793DECCULL, 0x01BF6EDE3667AE37ULL, 0x8CD82B1D578721DBULL, 0xD69938E1CC599257ULL, 
            0xB15B4AFCD22F7996ULL, 0x097997B652084DA6ULL, 0x0349E0DB0C81AFE5ULL, 0x43579C6F3A6ED910ULL, 
            0x143E5DFF0CD37E5DULL, 0x257866BE820570F6ULL, 0x629D948ED3382701ULL, 0x5EF5ADDB124BB8C3ULL
        },
        {
            0x3E971E1962E567CBULL, 0x9AADFC70FB6D907CULL, 0x5DA802E3D7F11E6AULL, 0xC5BFFA0EF0069C31ULL, 
            0x32F6D1274586091EULL, 0x342ABCF3129E29E6ULL, 0x1D9084F3CCA1EF5AULL, 0xB3413A50C8FE5171ULL, 
            0xD437DBC2985BC92EULL, 0xC785A5FF7A393885ULL, 0x8BACDC2A58B22D79ULL, 0xBB0BB0F4BE619844ULL, 
            0x3730685C0E3DC9C6ULL, 0x2D26BF6CC198A559ULL, 0x6A1F453ACBCCDFC5ULL, 0x7EF8AB2C87F3AA6CULL, 
            0xF4034ACD051A5672ULL, 0x5E4772C785D4ABB1ULL, 0xF293DD394DBE09E2ULL, 0xE21095D870F8D660ULL, 
            0x931FF9ED69500FEBULL, 0x8B36D9E650B186FBULL, 0x75D2F05737FC74C5ULL, 0x1725E1C95D898807ULL, 
            0xC34C9109458AD61EULL, 0xCACF9FE92E988CB9ULL, 0xE64AF0D27965E175ULL, 0xF7DDA8FAD2C1C4EAULL, 
            0x5B45BDB00843F542ULL, 0x2364944AAAC33CE5ULL, 0xC1A2C62D3C693263ULL, 0x5E548335FF14D428ULL
        },
        {
            0x616F9C612A40054CULL, 0x24C1A42459903C72ULL, 0x9B235A134A8A5F9FULL, 0x46E9A0051834C7FFULL, 
            0x87872DBCED7E3150ULL, 0x0C1B4CECFA81E144ULL, 0xAEB11BB07DAC2849ULL, 0xAB62B9EE4B9D17C6ULL, 
            0x79DA4AF6405C1DC8ULL, 0x9B268C6C37546910ULL, 0x3AC75545AB70175BULL, 0x92DF0407E84E8A3AULL, 
            0x42C342F6B54B960AULL, 0xE10C46C58DCCA030ULL, 0xB8ACEB10DAC76D4EULL, 0xBC9FBFB7C4030880ULL, 
            0xFDA0887151916976ULL, 0x95C1D3186E40876DULL, 0xE1A96511D501CFAAULL, 0xE559B3614F511625ULL, 
            0x73C45F075946135EULL, 0x025219A29CDAF4C1ULL, 0x889A229A61724C64ULL, 0xC9F82A1519980A55ULL, 
            0x0A59C8300743842DULL, 0x16259E669605B1F2ULL, 0x9A07D9B1FF69EB3BULL, 0x5ABA44AC986154A8ULL, 
            0x73D2CB2712CAE3BFULL, 0xEB4E8AEBD04249C0ULL, 0x58A7A21D94A493CAULL, 0x3A1F6D2B647082E4ULL
        },
        {
            0x6E93DC15A68ACA13ULL, 0x94C13678F6E8F52DULL, 0xD6BBA2ACAB8E76CBULL, 0xEC27CD10A381DA41ULL, 
            0xFA97B0A0F62BEDCAULL, 0xBAB38B992F53F534ULL, 0x7A07551CA533D450ULL, 0x3B2706FD409DA36AULL, 
            0x9F886B6AC03B227AULL, 0xE2703D3174059EF9ULL, 0x0ED0C23F94B10BB4ULL, 0x585970D5AAA917CEULL, 
            0xA508FAC7E9CB2779ULL, 0xAAA6C8595CFFCAAEULL, 0x75F58398D2312B65ULL, 0xA82F8B0FB254AE79ULL, 
            0x25A50826C92E5A48ULL, 0x28FA66F60401A2D8ULL, 0xCA638A305F951BECULL, 0x86C19DACDC8E36E5ULL, 
            0x53D2045BE574B828ULL, 0x08065AF73B325F9AULL, 0x865E1EE244DB6AA9ULL, 0x5D84E66E3C8BEEDFULL, 
            0xE1D3ECB505B30ADBULL, 0xED88ED6C850C6A76ULL, 0x3943B6691038D151ULL, 0x6B5CD526825EA0ADULL, 
            0xE0DFF2A47CACFD73ULL, 0x8F3CFDF44F9C6A00ULL, 0x967E025219A5F9DCULL, 0x8C0C3466560BB3DDULL
        }
    },
    {
        {
            0xAE1A4EFFB6D6C5F6ULL, 0x23B386CA96A3A9F3ULL, 0xE14F49F79575A193ULL, 0xD73554D41FB67A4DULL, 
            0xD77803BD22E975CDULL, 0xA9F5DC5C1AEC10F3ULL, 0x33C4DC47F0B0BD34ULL, 0x51CDF1A64363F93CULL, 
            0xB9C288F03E2AA8DCULL, 0x7754F2F7F3A8ECE2ULL, 0x861DF4BF14278B28ULL, 0xBEBA5D18DBAE9F69ULL, 
            0xD74B75464F91A978ULL, 0x12CCB0CF9641DDA9ULL, 0x22A6116C91F6A8B3ULL, 0xF829935BC9DDB0EEULL, 
            0x5EE84537594E8A6AULL, 0xEE55C1630D30766BULL, 0x980A0367E040F78BULL, 0x1DAC97F118C35041ULL, 
            0x110A4B2A759E1977ULL, 0xA10BAFE5C7223521ULL, 0xC59538F929BB3811ULL, 0xC183CC22611E437AULL, 
            0x3918E4B287D13C86ULL, 0x08DC38C18B2B925AULL, 0xFF01838D2EF9711BULL, 0xEAD5844F9228056AULL, 
            0xC139A6C4430F5552ULL, 0xE4F32374E5F29371ULL, 0x4A37686BA2DD6ACEULL, 0xE41520C6328E04CBULL
        },
        {
            0xC1A29A694122834BULL, 0xF21FF7DFF2916D48ULL, 0x992865DCAEE0814BULL, 0x46C370019DD46979ULL, 
            0xD1E3C564A3F6F893ULL, 0xA1FA948DD9DD52EDULL, 0xFA10B551FC7D6E35ULL, 0x09FC7AFD04F15D77ULL, 
            0xA7D7B8E3E9429F84ULL, 0x60B520293BC7F3B6ULL, 0x4FCE8EBBE4587D78ULL, 0x0184B07B09D57E9FULL, 
            0x3044FFD3D63611AAULL, 0x53CCBAC27242A4D4ULL, 0x177E82863AB12E66ULL, 0x491DEA171C27FCD0ULL, 
            0xC77E839966B1A353ULL, 0xCDCB6C93037CCCFAULL, 0xC548710BE1D55E5CULL, 0x21821B5B1BE54825ULL, 
            0xEEA31B17BD0161F4ULL, 0xD164D557CE35D019ULL, 0x717466E95880801CULL, 0xC796C983FB40D387ULL, 
            0x29ABD19E3A017566ULL, 0x2151B7A7EA10DCE8ULL, 0x4E35C360640A0C9CULL, 0xEB4B2C9D336181F0ULL, 
            0x8E04D1C414C413CBULL, 0x60A79E4C82C0D824ULL, 0xD0795887141FB04AULL, 0x6F081B8FB106CFEDULL
        },
        {
            0xAFD147B4868219CDULL, 0x55216B40D49DBDB3ULL, 0xA756596D8F6069ADULL, 0x78BFA4012407F8E6ULL, 
            0x03F90B3E213D54FFULL, 0x4090FC722CC57B45ULL, 0x1C5991347FE2891EULL, 0x892667543BC18721ULL, 
            0x0BA5056915C027E8ULL, 0xC3D99E973CB85A74ULL, 0x9C4CF0D4E7B7BAE9ULL, 0xFD086A357BEDB9F3ULL, 
            0x1C1219D186A102CEULL, 0x2158E02302432345ULL, 0xFC88F5DA81076B70ULL, 0x804383B5C25BC68DULL, 
            0xBC30E39C9F8E1403ULL, 0x7163A0749A62F701ULL, 0x271F271BC053D1B3ULL, 0x8DA8B3B75BF69D7AULL, 
            0xD77DA5DAF312B7EDULL, 0xB626C7EA2452818EULL, 0x002616CAB2B86530ULL, 0xDC2BA0649836FA58ULL, 
            0x43556C1C07181FD9ULL, 0x685D7199456AC1DDULL, 0x3FED73606B318A25ULL, 0xDC02C6946B6E17B7ULL, 
            0x6D0296E212BE8D51ULL, 0x99FF81A2A7B0021CULL, 0xEF2D3A12F0FEAD19ULL, 0xE585F25E24592D80ULL
        },
        {
            0xB6397C8C84CAB211ULL, 0x2AA930A855FFA9B1ULL, 0xEEE88C835C03CA1FULL, 0x1AE5DBDB05577D10ULL, 
            0x69CB4D87576269E2ULL, 0x49E2D3AB78925E14ULL, 0x17DF82AB11022873ULL, 0x47CD792116AC2CB5ULL, 
            0xB60DD1EB1EF00E8AULL, 0x74174453D2E33E76ULL, 0xFF58CAA57C276997ULL, 0x4ECB7735C888A45CULL, 
            0x7F46349BAD512E20ULL, 0xCD327F6AE1DB7A49ULL, 0xDCD8F81B3C4C97CBULL, 0xC9FA1BCD94827264ULL, 
            0xC97DB97D49632A2BULL, 0x4466AE062D268CF8ULL, 0x74AD0480300F5478ULL, 0x384D94749D658B2CULL, 
            0xF52FF4931EE8A736ULL, 0xAE3563FC892A3EDCULL, 0x7667BEF15C1C5EC5ULL, 0x40E2D55D7BB61AF7ULL, 
            0x9E5ACDA017DF1A1AULL, 0xFFDD3D64583FA3BAULL, 0xD75E39E87E59A945ULL, 0xE198EF0DE7D02D4AULL, 
            0x1E7516BA83FF03CBULL, 0xA4143FCA2095E230ULL, 0x2A3F13B957FAC283ULL, 0x4477131F03CF70F0ULL
        },
        {
            0x925EF712C58D2DBCULL, 0x400EF760393B350AULL, 0x5BB0F7584AF2C04EULL, 0xF39163AC588316C2ULL, 
            0xDA1D712AA63A2076ULL, 0x71286447CF5C29C6ULL, 0x82811E2F6F96FE29ULL, 0x07D2DE7393EC12CCULL, 
            0xEBE4FBFE6D5D4F3FULL, 0xDC015FD6A4ECCA4EULL, 0x8F844EB0CDBCCDDFULL, 0x18FE9684EF214AA3ULL, 
            0x9861C46FF612F6FFULL, 0xB8229A55AEBF1B39ULL, 0x146CB48F32C3AF01ULL, 0x606832B437742984ULL, 
            0xEE127ABE959CDB93ULL, 0x87B81C88407C86AAULL, 0x4A4711B6A66A6414ULL, 0x66938FDEAF2E51C6ULL, 
            0x858A1420C899B80AULL, 0x5E78852DE157FA0FULL, 0x8E4537A4E7470C86ULL, 0xB19506A98A20E243ULL, 
            0xE6EE8F48CCAAAE34ULL, 0x37F8ED2ABEE3D20AULL, 0x87CCAE3CE79A243BULL, 0x67D02C58B3571C98ULL, 
            0x5B1988AD2E98D45BULL, 0xB4FE190629D96152ULL, 0xF576E594B60C4F83ULL, 0x63F375311E598B4AULL
        },
        {
            0x99E8B1A28AED5E52ULL, 0xACAD744D8FF98AFBULL, 0xD0C39A0193C93FBAULL, 0x1C3AF691D87A86F5ULL, 
            0xA9A2E2E18327DA8CULL, 0x35CB924E47CCDA55ULL, 0xB3DC40D2D9B698B7ULL, 0xC0772AD74CAA2A3CULL, 
            0x4DEFE5E48A7E0BA5ULL, 0x1739C6805F6F73EFULL, 0xDB62486198A7DB63ULL, 0xC1F2EBAE48F6DDA5ULL, 
            0x1B369E2E1A721F7FULL, 0x7CED0CDA6F78A21FULL, 0x86878ED9C3F3112CULL, 0x380FC266FB148A46ULL, 
            0xD7AFE216F95ACBE8ULL, 0xBB1FF975D725A299ULL, 0xABD0D16B412E0AF1ULL, 0x62171D3CE79A6075ULL, 
            0x718A42101FB8E782ULL, 0xDF8EC48739C68E66ULL, 0x3F35EBDC00530DC4ULL, 0xBB2573F9EF5DE602ULL, 
            0xA249DE35FDB635C3ULL, 0x46C500DD86E825A2ULL, 0xA280ACFBCA7D100AULL, 0x1DF55A21E9247B83ULL, 
            0x882CB313E5CB1970ULL, 0xCA555C4F0D2A6BDAULL, 0x4786D02155ED7015ULL, 0xB7DF3D4255AD82B4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseFConstants = {
    0xDCF7004F59FB6C11ULL,
    0x259CBAD232BE783EULL,
    0x58337BE2A6B28B93ULL,
    0xDCF7004F59FB6C11ULL,
    0x259CBAD232BE783EULL,
    0x58337BE2A6B28B93ULL,
    0x0B565134DD58EDE1ULL,
    0x61F2D91AC809F936ULL,
    0x5D,
    0x2B,
    0x95,
    0x37,
    0xA6,
    0x36,
    0x0E,
    0x0A
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseGSalts = {
    {
        {
            0x0FA05C8817741E68ULL, 0x8CD860B4F76DB6F5ULL, 0xA2EF25155B04856EULL, 0x18D925FA51A4130BULL, 
            0x4F215DA5B652ABBBULL, 0xC1CCD714FFDFA91CULL, 0x5BFC77A313F7A2B2ULL, 0xB5DF731F0EC406A7ULL, 
            0x8E35B9F72C2066E4ULL, 0xAB6D5B58802CD23CULL, 0xA6FAF0E5BAE316BAULL, 0xACBECF6CA32D712CULL, 
            0xFE00BCCBF77DD7F7ULL, 0x252D8C2F56197AE7ULL, 0x52DA9FC45DB8E4D2ULL, 0xD2E9E08CD2A29872ULL, 
            0xD8D10C14D9D31BA9ULL, 0x1908E615E8278D3CULL, 0x67D35818E4DA8FF9ULL, 0x6287DE4D8342BF88ULL, 
            0xCFF88E807D162FE5ULL, 0x0F11B0A3BB3D8F0FULL, 0x4011BAD9B951301AULL, 0x1CD9A80D6BCB2604ULL, 
            0x3C596DE017B2ED0AULL, 0x31122C958187078BULL, 0x8E9C062F1FA2BC35ULL, 0x6DEA1AD9C44ECE38ULL, 
            0x5A1C313B59CA4761ULL, 0xD2CD868512920C61ULL, 0xCDFEE43A2C1DEDCEULL, 0x24D16334E1EDBB69ULL
        },
        {
            0x93E74623DA9DDD97ULL, 0x9F0FBC370A749F94ULL, 0xFA434EBAE145CC47ULL, 0x75501B71C4306DDEULL, 
            0x4600FFE11F8CBBC6ULL, 0x74BAA0BD6F234A17ULL, 0x3129ED269C644507ULL, 0x7961AA47FA44B00CULL, 
            0x608A92EEEF154011ULL, 0xF4D6B4BC9B30AA70ULL, 0x1FBAD1A28CE32858ULL, 0xEEDB6F10D190A4AEULL, 
            0xED2855E48CB37AECULL, 0xF1478A2D0803D194ULL, 0x8CEBE712688A75ACULL, 0x4120E3DA71685BE8ULL, 
            0xAE6BBCB59BF11ED0ULL, 0x5DA3D40B5AFCB1FDULL, 0x0D71C1292F65851CULL, 0x706CAB693953FE5FULL, 
            0x35FF2814D456B517ULL, 0x2C53943FA266438FULL, 0x7ADC14A0FE5F1F19ULL, 0xFDC291A8BC56BE7BULL, 
            0xC2FC7201951B5953ULL, 0xCB8FA158CF13A97FULL, 0x92BDC0E7CA0023CAULL, 0x2C54E9B2DE330EAEULL, 
            0x5B0681847F9B29F3ULL, 0x2000E4E59EC61ECEULL, 0xCEA9AC4917D619EBULL, 0x7EBF209EECA2A16EULL
        },
        {
            0x7338F3138A8CA51BULL, 0xE8E867F45AB0CE67ULL, 0xB2344B10F015F94AULL, 0x9B09FA3B6EA73C63ULL, 
            0xE541BC2EFE0305ADULL, 0xE55A2C908EE0B054ULL, 0x2798380F6E1EFBA4ULL, 0x55EE718086B58996ULL, 
            0xD37E9B16CAB3476AULL, 0xA3285BF9D43C45ACULL, 0x95A765CBBF19906AULL, 0x1110E15A7A1D7E36ULL, 
            0x86F56C0DBCF33C43ULL, 0xF4180CE30989E60CULL, 0xE07BED1967535F44ULL, 0xBFF80C2A6C869788ULL, 
            0xFF5FE114772231ACULL, 0x806BC0AC07555233ULL, 0xE6263566DCD33BA0ULL, 0x3492A54AD80E4622ULL, 
            0x150867EEA7F8838FULL, 0x94C0BD1F04053582ULL, 0xCD8A7CE2084FBC02ULL, 0x62E1A0D684B5026FULL, 
            0xBCD86CA77E5C6EEDULL, 0x508968D2ECDBDDA7ULL, 0x56E145781A289CAAULL, 0x0E63255B20875294ULL, 
            0x6BBAD4DC01C7770BULL, 0x4C2642F29979AFEBULL, 0xA2B0D9FD6951811AULL, 0xAB760724F013E339ULL
        },
        {
            0xD31684474E1FC973ULL, 0xFE2D1991F726ED17ULL, 0xE7B2EC58EBCC7553ULL, 0x751BA7A8F0724F6DULL, 
            0x06CED94B87BA66C5ULL, 0xAD956939079FA80DULL, 0x2A1A8AA6084C317DULL, 0x1A7EAB53E77191B5ULL, 
            0x7A936988A314E8C8ULL, 0xB58D5B5681E1D4C0ULL, 0x30BAFC8C614A3958ULL, 0xBD147D9A69F577DEULL, 
            0xEA1EDBF09D4FC808ULL, 0x5057F93E6605AAA1ULL, 0x387FA0790F831D7AULL, 0x2EBFB61D27AECD51ULL, 
            0x8B65CFCC8D419DAEULL, 0x43E3AE9347BF7A1FULL, 0x85DF77AC7876730CULL, 0x8D6DE48681E51552ULL, 
            0xF32DE175201750DEULL, 0x15FA58F4CE2B432CULL, 0x8D9758960724B893ULL, 0x4607FC9096C8F22DULL, 
            0x03D181592AB43653ULL, 0x302FA8021990B5AFULL, 0xB6174AC5AD7A4915ULL, 0xC95C98A0E58422E5ULL, 
            0x3CAD0E1E553E0746ULL, 0xF8423C6B9717EBA5ULL, 0xDCFF1AA8C90F17D8ULL, 0x1D6C21ACBF2CD2C2ULL
        },
        {
            0x42399A3282A684F9ULL, 0xB4D43582139E4514ULL, 0xBB04085F0E2F0399ULL, 0x2D074E4CC326FC85ULL, 
            0xB4FE5C761DEB05C5ULL, 0xF1E0DD3122737DB7ULL, 0xFC50B446113E5451ULL, 0x92FBD8887D865EAFULL, 
            0xEBD3F4FC242A5A5EULL, 0xEDDA0A518171DF17ULL, 0xE909AC7151CDD51DULL, 0xA6201F577C5FCCE7ULL, 
            0x63698F74A7EAFE5FULL, 0x329BE7464719F40DULL, 0x62AF4161FCF46446ULL, 0x26F863A2E94C9444ULL, 
            0xAE946B92AD7997B5ULL, 0xE8F05E286DEDA7B3ULL, 0xA82DBCCA16B245F7ULL, 0x15722DB9EF071A3DULL, 
            0xED50D5138D52F53EULL, 0xE11332E046D07E78ULL, 0xBE5D146A2C4F6B2DULL, 0x52436884ABD5379FULL, 
            0x524296574D696240ULL, 0xD39FF31A9F2ABF11ULL, 0x84AD59AE5D6EAAF9ULL, 0x58DB288048506F63ULL, 
            0xBE0BEF335338CFFFULL, 0xCE068B0C1297D38AULL, 0x581E55CF3F394EA2ULL, 0x3AF8FDD91BDD070EULL
        },
        {
            0x3B677F08A659157AULL, 0x8246FAAD0661715AULL, 0x42AA23AB987C2242ULL, 0xC9F420EBEC43008DULL, 
            0xBAB67C8036ADB5A2ULL, 0xEB966CC48CF19597ULL, 0xE3BC61C7DF0213FFULL, 0x7204DC24329DD8C6ULL, 
            0x015A830AEF2C4186ULL, 0x2912AE1F36BC6B14ULL, 0x475DC58279A899F3ULL, 0x679BED169A424CF4ULL, 
            0x71CFF894C4DBD76BULL, 0x314237100601D33CULL, 0xC3A628A29DBE1205ULL, 0xB41EA97006B7E279ULL, 
            0x174F2CD9929CF39BULL, 0x2096FE0EF95B5B36ULL, 0x5E86C3E71303BBFBULL, 0x670B1C7AF0716327ULL, 
            0xE854A295112C1895ULL, 0x27E0F3CA3F387B2AULL, 0x4B8B407258E0DFEEULL, 0xD1FD1EAEC757A846ULL, 
            0xD9F41810818A68DBULL, 0x1822727372BD7FFFULL, 0xBFFF0335FB371CC1ULL, 0x58E803345EB0B175ULL, 
            0x917EF0D98A5E9B69ULL, 0xE9BF28CE8FF5DAA1ULL, 0xB6BBE043D6E3D8CDULL, 0x847F936110B28772ULL
        }
    },
    {
        {
            0x3EA7057AC34FE093ULL, 0xFCFA18F192ACA87DULL, 0xD3F9F099FCA24DA7ULL, 0x5969D63D94657E05ULL, 
            0x496021BE764BF081ULL, 0xE08F652BA3FF5B21ULL, 0xFBF2420494B8EE41ULL, 0xBD7A18FE41DFFF3EULL, 
            0xDACD95393CF6520CULL, 0xAA05CD7E3EEFF08CULL, 0xA684165C499D3779ULL, 0xD4C428E6942DF6FDULL, 
            0xC2108D107A39BA69ULL, 0x69F921D677E63C5AULL, 0x4CD1D53DDF593BC9ULL, 0x3A0B80790F16955EULL, 
            0x23C4920448C83C98ULL, 0xDAAD49ECD4C73F15ULL, 0x6B92886C8CDC8D52ULL, 0x6108148DED89B4DCULL, 
            0x11090CEEC518D420ULL, 0x3CE5D8EA4BE5D818ULL, 0xE8D5559C8DDF1A9FULL, 0xBD3CB3010F6EE66CULL, 
            0x4FF146918072ABF3ULL, 0x83B29ED2D4C981CCULL, 0x68F7E507F7B66FE1ULL, 0xFF37D3C0FF6BB72AULL, 
            0xB00781BE89A99699ULL, 0xF19759E620A94B48ULL, 0x1A163C16B1B0A18DULL, 0xA2C683961D19233BULL
        },
        {
            0x6A2BCEDBC62EEF53ULL, 0x365233F57663FECCULL, 0xC0861C913660C004ULL, 0x876AD7BF2F281389ULL, 
            0xA4147CD9EFDB3517ULL, 0xB64FD5700AC0D491ULL, 0x009BC4435EA87E0AULL, 0x337716D8F8662A21ULL, 
            0xD23D6AE4CC30AFF7ULL, 0xA2622C1008102F3BULL, 0x9000687ECEFC4585ULL, 0x0B5CC223F558BFA6ULL, 
            0x356BBA1FDC1CF4E5ULL, 0x6FA013CA1D72EF2AULL, 0xDE2E190D42BC685AULL, 0xD6BFCA5509885228ULL, 
            0xB183CFBFE37AA215ULL, 0x9866AD0AB0556635ULL, 0xD9F0261D6F34C669ULL, 0xFA1682722ADFA772ULL, 
            0x10E41A93B1C9DEBFULL, 0xDE3A83E5F6CC973AULL, 0xE937CBA9EBECAB2AULL, 0x070641B15B91F269ULL, 
            0x9C9879E70EF77C71ULL, 0x222E67D6E6E9520BULL, 0x4DF7A57655B68C07ULL, 0x31F661C0E4BA31A0ULL, 
            0x2FF2F87206EAFBE2ULL, 0x0A0922106338C0DBULL, 0x76E656D459884AC2ULL, 0x1724811C4CD818C2ULL
        },
        {
            0x825FE4D421024A5DULL, 0x071E78B094B0DF64ULL, 0xBC884A580A9F02A2ULL, 0x5E59EDDF884FA768ULL, 
            0xAD41915C2DD494FFULL, 0xBF672C734C9B33ACULL, 0x6817918C50C0B4CEULL, 0x05EBB93ADF1200A2ULL, 
            0xCEF98C9C0ADCEEB7ULL, 0x595C8A6325D995E2ULL, 0x6CFB3B60911761E1ULL, 0x8131C4328C801682ULL, 
            0x218A4856382E9FCDULL, 0xD7ABFAF825101394ULL, 0x8C28F057CCC5A916ULL, 0xC78920BBD6227355ULL, 
            0xD34BCE3C2C2AC034ULL, 0x0B75F422AB101332ULL, 0xDBA90C0BCF5F8DC7ULL, 0x0C3FF772C3D0DE75ULL, 
            0xD99B254653C1DF96ULL, 0x822F139720C40E34ULL, 0x03C2245B003D40F1ULL, 0x3C4284180EC28E87ULL, 
            0xDA92AE32880CA896ULL, 0x249A210EA7E2AAC3ULL, 0x56E67965F1373DF9ULL, 0xC0F25D8B8F641301ULL, 
            0x61C83894B3F920CCULL, 0xC04257ABB39DA0C0ULL, 0x178902432BC5B5B9ULL, 0x26C039430EBA0D28ULL
        },
        {
            0x20EF709DC15977A8ULL, 0xF72ED686C878AA2CULL, 0xC0A9D105EA044752ULL, 0xA7BB73C0E8369064ULL, 
            0x520A272435EEA0B2ULL, 0xB7D8BCD8AAADF55CULL, 0x6F95072B27FE5937ULL, 0xDC14BA5C46B807A0ULL, 
            0xB3BAB01B37FF95B1ULL, 0xDD84CCF842DBDDCFULL, 0x3F2F0FC9D0FE3827ULL, 0xDFC9BD746B8A57C3ULL, 
            0xC58A5DDE17A0299DULL, 0x604A7B4E00FC55DAULL, 0x36FB48BB6E28F8B5ULL, 0x16453FCE8CCC7C64ULL, 
            0xC64C3BACA37CC8D4ULL, 0x1EAC1E6259A74977ULL, 0x0253DF7E689A4C68ULL, 0xC52807F175D7EB62ULL, 
            0xB0566265858B0CD1ULL, 0x3CFA329561F35A5FULL, 0x2FECF1E3A83A1776ULL, 0x64CF7A182D786BBDULL, 
            0xDAC418DE12F13930ULL, 0x9CBBB420F1B13BACULL, 0x1AC9B5BF205E199CULL, 0x40BF18D26D970914ULL, 
            0x9EA21BE82F5F8204ULL, 0xF1911337D06D391EULL, 0xF20E32FC86D8EA8FULL, 0x56CAA066808C389BULL
        },
        {
            0x1631CFB7235ECB75ULL, 0xA8751FF0D494D109ULL, 0x80759353190F8AEFULL, 0x06471C8D629B0AD0ULL, 
            0xB0B34262A221FC92ULL, 0xA2D90C4239598543ULL, 0x92383FEBA5926D28ULL, 0x2E2EB39045E203DBULL, 
            0xD58B3C90A2737997ULL, 0xA0A8239F90B49890ULL, 0xB0F01C66AAFB044FULL, 0xA8976CA2C37E851AULL, 
            0xDA87771848579276ULL, 0xC6511F8F2CF1D4ABULL, 0x3C302FF3C8560B34ULL, 0x42CE0E5FD7D0EC6AULL, 
            0x437F7C71EB6FA9B6ULL, 0xC1EAF49F1C87E2C5ULL, 0x8F26CCF4CC6527C4ULL, 0x1BA7229D7B2D2CC6ULL, 
            0xC8D69BE7E5D0C201ULL, 0x1763D1B5D498BADFULL, 0x84DCAFF195204284ULL, 0x5CB425FB148A1078ULL, 
            0x1A060A94AE4D3765ULL, 0xCAC06436E706085DULL, 0x46F3FA75C27AA0D3ULL, 0x83670602380BD41EULL, 
            0xACE09DE7F1ADF6F7ULL, 0x1D534330EC182C4BULL, 0x869AA2C6F6B35462ULL, 0xEAA0D078304468B1ULL
        },
        {
            0xC501D5784A10B206ULL, 0xEC568542FB9F0F23ULL, 0x38FBC8BE00530A7EULL, 0x88BE40F0F15A5D34ULL, 
            0xDC161448823656C9ULL, 0x6629634EB0855467ULL, 0xA64F6EFE0D8695EAULL, 0xC0A794800D90337AULL, 
            0xC611569E66064A39ULL, 0xFA56AEEDE454D4A8ULL, 0xDE326F35995E3812ULL, 0xE682C07A3689CC79ULL, 
            0xFA2B672A5F701C0CULL, 0xD7F52E4C106D5A19ULL, 0x0E82DC6723010450ULL, 0x8CFF17E66B041834ULL, 
            0x6D773F8FC259CA86ULL, 0x16009E339B22CA5DULL, 0x0786D8043B56C686ULL, 0x091F1AADC24420C6ULL, 
            0xE1512D5F61FEF385ULL, 0xC66672E7286848E0ULL, 0xD31C19DE2633891CULL, 0xE160E50D34DFC849ULL, 
            0x579A7125AEE3C8A7ULL, 0x79F83BD190AB5A92ULL, 0x189FAAA65E09BAA9ULL, 0xAA24A3E6A2F96A4AULL, 
            0xA9EEB8DD96D21580ULL, 0x810C6EA6F566DD16ULL, 0x8AD618DA0FB75BBEULL, 0x4036D2634184C33EULL
        }
    },
    {
        {
            0x9D069C026B3BB499ULL, 0x31089D780FFA32BFULL, 0xCE60B0872C7DD813ULL, 0x56290A0318F92CA7ULL, 
            0x8ECA5DE2A7D586E9ULL, 0x2972F3AE5E69227FULL, 0x4D01C0AE84B68AD7ULL, 0x9F352B48B990D886ULL, 
            0x40589E0E47A88DA2ULL, 0x7100C7B1B5B36428ULL, 0x8A0DDF355AA8650FULL, 0x7653B8AC0A189738ULL, 
            0x35757E19AD4888C4ULL, 0x7719C96CD9F50885ULL, 0xB2288B016FEB32E6ULL, 0x9DDD7808A9E4ED15ULL, 
            0x3A8301800D061251ULL, 0x8D32AEF0D4239575ULL, 0xABAF4675B980905FULL, 0xEAB489D8028BFD5CULL, 
            0x25EF810BD0E9E01BULL, 0xC328C8B94C619156ULL, 0xB6C40A7684E56EF1ULL, 0x78EAB4917546E587ULL, 
            0x4BB75BE6EEDA6883ULL, 0x14C508A967C06804ULL, 0x6DFA3BE2BB023F33ULL, 0x836947AD7459D421ULL, 
            0x8BB4748F21AB7572ULL, 0x27B760780A587A0BULL, 0xF9F660C6A723C0CBULL, 0xEFC76FD9273EF482ULL
        },
        {
            0x6461ECF796834C1AULL, 0x82BA0EB1049FF8D9ULL, 0x566D68F6B4640616ULL, 0x291637C0CBCAB337ULL, 
            0xB8B3634671D9562DULL, 0xCC33E7A08CE96B32ULL, 0x0E76C71B2B8E90FFULL, 0x7ADA9FB2ED49BB4AULL, 
            0x7BEC036545EA49D8ULL, 0x67674D1D6803359DULL, 0x73606A79490D23DEULL, 0xB49C1D0DF230F150ULL, 
            0x543C0F71BFB8E8E2ULL, 0xAB88C40EFCFFDAB0ULL, 0x22EDBCCA615D1863ULL, 0x3B603DF4376578E5ULL, 
            0xC518FF081FE5D5D4ULL, 0x70B4AD317F45A5B5ULL, 0x28F1BF31A6C9AE89ULL, 0x92C4ABDD5BF0BDD6ULL, 
            0x319DE081E9897C7DULL, 0xA4F2409BBD50282EULL, 0xBD0CC739418C2B1DULL, 0xDB93010B6E962314ULL, 
            0x9863CE1893A3EC9EULL, 0x32E11F83B7EC6978ULL, 0xC69A80D30A60950AULL, 0x97732B12D5DCE968ULL, 
            0x17161A4FCBD3218DULL, 0x72AEFC210C907C4EULL, 0x7D7DD877A60BE808ULL, 0xE90B6936935AD0BEULL
        },
        {
            0x2C7E551C1B16BB2EULL, 0x7F3A15E54B6925CFULL, 0x07E7D6D7C9A06830ULL, 0xF5DB4E7BED2E64FBULL, 
            0x02F81632F6EED620ULL, 0x3102709B160E9031ULL, 0xBCEE825A272D67FEULL, 0xE3BD4A47D92B7794ULL, 
            0x034E40B3C10CC427ULL, 0x45FB0222D81ABDF6ULL, 0xDB696C84D72A4A8EULL, 0x027A30C4E1970A85ULL, 
            0x9B4C4BF2FA03F53FULL, 0xC01410D35B05D541ULL, 0x60A80D3634838CB5ULL, 0x78A034C36B6A9E42ULL, 
            0xDA25F6E9E4A85F9FULL, 0x01197BA02DF1F996ULL, 0x1FB982E62C8ECB17ULL, 0x64D8EE5C76699B4FULL, 
            0x06162FF95AAC3139ULL, 0xF7F54DF8C1E13477ULL, 0xDE3F6DE2DCEB4BBDULL, 0x7FE42C0BFC816295ULL, 
            0x2C22CAB6F543F13FULL, 0xB572816C635029DEULL, 0x444F897BA83519E5ULL, 0x38837C2B980E9BA2ULL, 
            0x7747267521D9189BULL, 0xC0CC8DEB5624921DULL, 0xE65CBD65517D5AFBULL, 0xA7BEF1C592502625ULL
        },
        {
            0x882CF909CDC0FFF0ULL, 0xB8C6563E1F07A08DULL, 0xC790834F1ADC76B8ULL, 0x5C5C89844B354E5BULL, 
            0x67EC8387D730C6A2ULL, 0x97B15B363D455320ULL, 0x8AFDC71157A211A6ULL, 0x216941870BD4961FULL, 
            0x50E8FA4BD72560E2ULL, 0x71408B67BCDFD053ULL, 0x293C43E15E1B112CULL, 0xA0F62D3CF50481BDULL, 
            0x6D3C99CB9B6FBF8AULL, 0x2548B954FBF2E8B3ULL, 0x2E181880C8536B19ULL, 0xA667F4A31CC177C1ULL, 
            0x0A4A2953232B8F36ULL, 0x1BA5003800116E97ULL, 0xD013EE85556FDB87ULL, 0xCA960E2E021818CBULL, 
            0x3DEB578A06471890ULL, 0x75A27F40DF92712FULL, 0x920D37BE6EA7F3FBULL, 0x336BB499A315E59AULL, 
            0x8C8BB563F0BA677DULL, 0x10B54FAF60F5B237ULL, 0x7792176E4D747274ULL, 0x954741D3AD2D0C3CULL, 
            0x0BA5D9BFE4D49FF8ULL, 0x67883F8BDE73734DULL, 0x3DA2FE7319911799ULL, 0xE087AA9F67413C53ULL
        },
        {
            0x5F5115E3FE0C814CULL, 0x5FEAF5F2FBF04DD5ULL, 0xDA4BC12417B6E518ULL, 0x499E01390C0410FDULL, 
            0x25EBCE90A681F65EULL, 0x91AD5AB1667B2893ULL, 0x679F2B1623B480CDULL, 0x0050D0E3BC26DA09ULL, 
            0x8C87A8792E24356CULL, 0x2CF322E2A82DBA67ULL, 0x324D368643437CC7ULL, 0xF08522FF93070A70ULL, 
            0x734982D52384D677ULL, 0x82B7E77D0AA62B10ULL, 0x74827EA39DC55ECEULL, 0xCAF0741F63C55122ULL, 
            0x613A0652A660DC5EULL, 0x3933369FD4554034ULL, 0xF15B8DC034E9E9D5ULL, 0xF166184CD578DB1DULL, 
            0x2CC21C8AE0001A0FULL, 0x2F87E605735A83DEULL, 0x61F52BFE856F27A0ULL, 0x94B72DDBB2FE21DFULL, 
            0x1556E3F75B7A3611ULL, 0xCCC6338C41C4F954ULL, 0xA049E517D30ECCA1ULL, 0x0270C68A9905023FULL, 
            0xC8957262362F89CBULL, 0x1FDDFDF7718A09D6ULL, 0xCBDB949C2E1C6F63ULL, 0x0A189E5A8B92A6A4ULL
        },
        {
            0x321360294A4F9D0FULL, 0x13FCD4D7A62800CDULL, 0xB27F4F2A04702828ULL, 0xF57028E552281F5CULL, 
            0xF349DFE33EA96401ULL, 0xF6BDA7647945B29CULL, 0xC3EF43EBF672D115ULL, 0x993A0C5C600A2283ULL, 
            0x3D9C1A1DCF0C6852ULL, 0x0D1C286503F868C4ULL, 0x608615A3A0321688ULL, 0x56F6723999800D5FULL, 
            0x5A20C69C06A15FCEULL, 0x80B88A14DFE03FCFULL, 0x10B5E172DAC4C4CBULL, 0x9259C8EB3A8196E4ULL, 
            0x750BDA8E4D2B3343ULL, 0xF088D9BE99BDB007ULL, 0xF284BE425FFA6567ULL, 0xAF48483F6EBD8C33ULL, 
            0xB1B533EAE136CAA8ULL, 0x3DB41A44B38CF1F7ULL, 0x35DB5BECBEE785E3ULL, 0x00B48CF37168B761ULL, 
            0x36C7B82512774145ULL, 0xF1CD8C8869C8D5B9ULL, 0x5124621C1A31C886ULL, 0xAE6EECD56BD21B5CULL, 
            0xC7EBEB61BBFC06CDULL, 0xE968660986472B04ULL, 0xB862DFBCE44CD6A4ULL, 0xAB2925ACC2D34DBEULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseGConstants = {
    0x63D35F42F2B910EDULL,
    0x213F641C86FB1E00ULL,
    0xF0507386C37430FDULL,
    0x63D35F42F2B910EDULL,
    0x213F641C86FB1E00ULL,
    0xF0507386C37430FDULL,
    0x3F51A13C18F2D7E5ULL,
    0x40270F51805593E8ULL,
    0xC3,
    0x65,
    0x97,
    0x49,
    0xA2,
    0xFD,
    0x97,
    0x6E
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseHSalts = {
    {
        {
            0xF8633AD5786FEE08ULL, 0xC07354FFE1EF4C42ULL, 0xFFC4535C50496344ULL, 0x772DFDB614F1DF66ULL, 
            0x4102F62994FD5E01ULL, 0x856982C9DCA149CBULL, 0x7EBB3C7018197502ULL, 0xDBDE7765438B758CULL, 
            0x9025E25DB5EB7673ULL, 0x7FF167AA0C3BA66DULL, 0xA8D227F371806C21ULL, 0x11E4C29F3C98BEBBULL, 
            0x8572B40BCD9A1B3EULL, 0xE599FEC1C7E40071ULL, 0x81D99A1C9BE193B8ULL, 0x73A42DE647E3B481ULL, 
            0x0FD6C9B2D398D5CAULL, 0x0023C2C68ABDFE7FULL, 0x5C818D0E4431222DULL, 0xF983A5DA426CFAB2ULL, 
            0x63FAEEE7820BB552ULL, 0x8279981D4A057A79ULL, 0x90D9F5A17960AF9CULL, 0xF6817EADC14DDEA4ULL, 
            0x8901927FD2147983ULL, 0x02EC7585046944C5ULL, 0x421DDBE19BEFA5B1ULL, 0xCEA57E3CE0E17F42ULL, 
            0x2D5B926C5248EC43ULL, 0x254BCDC034074C93ULL, 0x319E3A503F6536BDULL, 0xD9DE5A9DB8B82A77ULL
        },
        {
            0xCE3DCEAB75EF4E2AULL, 0x60CD3C6856D46768ULL, 0xFCF7E51EEB33CB6DULL, 0xE358EB4386D84AE6ULL, 
            0x4421642F42E0B1AFULL, 0xA879A09E9AC1E923ULL, 0xCE43EE2D3FA82F80ULL, 0x0F53579A6F382691ULL, 
            0x928E95DBFAB4815EULL, 0x09D32DA7B5833AE9ULL, 0x7CD2D54F5620A1FCULL, 0xD4111FEDBB346B06ULL, 
            0x4159EAA331336456ULL, 0x7C78B20FE2509652ULL, 0x210EC820F8223580ULL, 0xA87D235D1F8A22B5ULL, 
            0xD200B3E90CCE4D27ULL, 0xA0FDC5A8A05E00EBULL, 0x4D40B4519F85352BULL, 0x1AB47AA1451F6E0BULL, 
            0xB6697C600F654C91ULL, 0x3E39A1AF3B6978D1ULL, 0x77F5E6BA51A2C0DFULL, 0xF4F64B94FCF479EBULL, 
            0x4741527401BF44D3ULL, 0x495ACC5F60B31752ULL, 0xA872EA5EF8A164C9ULL, 0xA73A20BDF1F9C3F3ULL, 
            0x0CAE448AA0A2B240ULL, 0x7A8E66C6ED756296ULL, 0xB209B18A7865D689ULL, 0x79B0769F1236DCE4ULL
        },
        {
            0x9D115BEA8CB65CFBULL, 0xEAF4244D62028C87ULL, 0x6BADB86EC7581440ULL, 0x449AFE6F61E08C00ULL, 
            0x41B377C0F27BF45AULL, 0xA07EFD9DF5F41B44ULL, 0x3C4A7F9F9C6C46B1ULL, 0x13E6488F0F2275C9ULL, 
            0x272A9AC5E08931E8ULL, 0xABCF26D2FCD253AFULL, 0xD93E93443F4715B7ULL, 0x167F0A4B3E1D3C06ULL, 
            0x6FC744D754866D69ULL, 0xFE8509ACD9D504D4ULL, 0x2F92EFEA42341518ULL, 0x511EDB0949092AAAULL, 
            0x792BC5F256646BEDULL, 0x3D66CF47BF1B9FCFULL, 0x8873D7A1E65A2564ULL, 0xFD1946D8D885DDFFULL, 
            0x4CE8D0B625EAFF04ULL, 0x8A1FA768570E651DULL, 0x6035C55A493E4D67ULL, 0xC177194FA766C623ULL, 
            0x2A2B59983744390AULL, 0xD5753F979CB85F43ULL, 0x43E95B6573462723ULL, 0xB10AFDB941DD098BULL, 
            0x72AA4271D01D8B70ULL, 0xA6B980DBACB81715ULL, 0x90032FA7FD4CCBE1ULL, 0x72A7863763A684D2ULL
        },
        {
            0x86412D487A6F4922ULL, 0x8723B254604BF3D3ULL, 0x4135863AFCE43878ULL, 0x7B9C067DF913C1F1ULL, 
            0x8D87EB7963059F0FULL, 0x1C283694B984C5F3ULL, 0x4BE07415C7CD15C6ULL, 0x77B2311E62A7A76FULL, 
            0x4DC6B3605AF95643ULL, 0x8882AEAC47496CD6ULL, 0x8DDB0FC983B03C3BULL, 0x2DCAE2E1598E1329ULL, 
            0x8436F5987A0BCB02ULL, 0xB10570C0987787C5ULL, 0x87512B8106CA2E4AULL, 0x799807E32E8AB567ULL, 
            0xC83EE8680BC3098AULL, 0x6119D4A367703B42ULL, 0x49E77D40B50CDB70ULL, 0x1E40493756358849ULL, 
            0x4118BE1212C127A0ULL, 0x1C4C949FD7E6E037ULL, 0x15590FD3B0B2402FULL, 0xAFCCA558F6EE483DULL, 
            0x9316A4BC6CEE2676ULL, 0xB0CA2DB30BFD8FC9ULL, 0x4F7A888F8A17AD1BULL, 0x91B2A208CD8CA977ULL, 
            0x7FFC2EEC833A51AEULL, 0x7569DE2876C0964BULL, 0xE60064BB4480CC43ULL, 0xAC4FADC80E5FAFBEULL
        },
        {
            0x26125C267BCD7F77ULL, 0x0EA9E1C03471EFC9ULL, 0x4F9924D13A5CC710ULL, 0xDD88CB929C09ADBEULL, 
            0x3EB5A358141B9DADULL, 0xA6223E1F30348B52ULL, 0x3B7BA3C0242FE1AEULL, 0x3B3E8F07C222131DULL, 
            0xB07996437370ACF9ULL, 0x3B2CDD4053116FF5ULL, 0xE034B914CE442B52ULL, 0x97E144B27FF034AEULL, 
            0x549470A004C15D53ULL, 0xDD51DF5BF24B04E9ULL, 0x7896CD4B95035D7AULL, 0x88BE188429DC7003ULL, 
            0x5B5A34A7D13CE0F8ULL, 0x0B359D72303245C5ULL, 0xBA288DDC77DF3622ULL, 0x4A5468A04940610FULL, 
            0xB0CFC883387F6E43ULL, 0x9D1494A4CF362E7EULL, 0x3A2BC1B51F8416D6ULL, 0xD924A0C8CC6DD65DULL, 
            0xA99CA6BD0531302AULL, 0xB449D904D37C1B04ULL, 0xF01701FE98A776C7ULL, 0x10808952358F7EB0ULL, 
            0xF222951E0CA6A14EULL, 0xE32254AB75D94FD3ULL, 0x86B411D3DB7178FBULL, 0x10ABEB417C08E4AEULL
        },
        {
            0xA06477E8BF185052ULL, 0xD7F700910A589326ULL, 0x323C64A75B309B51ULL, 0x6B99C0214373CFA3ULL, 
            0x8666B7EFC7D88733ULL, 0x78A158A812DEB525ULL, 0xE7CBC19F94BAB700ULL, 0xB7A5EC0F414D37C1ULL, 
            0xBC4706458E50EFCFULL, 0x372094262F2A1EC2ULL, 0x9EE47BB7D575DD36ULL, 0x1E49854ABEA316F8ULL, 
            0x42F7FE29B1CB3593ULL, 0x4B6483124C505F4EULL, 0xD0453A6F1E2C08B7ULL, 0xA74A6E9580BAD20FULL, 
            0x96AE971C2CE3269DULL, 0xD8199F66E7485117ULL, 0x27DAA0685F769019ULL, 0x1346D6E55C444D03ULL, 
            0x3B63FB20D9BB5445ULL, 0x82BEB824842F5432ULL, 0xC44044EA94083861ULL, 0xBF4C8AD9D22FE1FCULL, 
            0x3AE8D822928F8B4DULL, 0xADFBE41DAA2CFAF9ULL, 0x2E6B6C59B07A2600ULL, 0x7677EBFB590EE99BULL, 
            0x49140A8A26184AE2ULL, 0xE0FC1D5D68E9633BULL, 0x96B36EB18DBDE153ULL, 0x2728F950F73F5D0FULL
        }
    },
    {
        {
            0x36C5F0568FC8E0C0ULL, 0x715BB3A6013484C4ULL, 0x4BB7F10FEBB964C5ULL, 0x7552BC6C4DE80258ULL, 
            0x248CE5471F1E20DEULL, 0x1C18B5F67161CAAFULL, 0xE3C983A689A99D73ULL, 0x00365EC20EC50CAEULL, 
            0x084F84E025FD9196ULL, 0xE6D5E3EF7384A919ULL, 0xAA89B8E357160F13ULL, 0xA10C315E3CD3F16AULL, 
            0xF9926088893239D1ULL, 0xB1CD22CA01E83C69ULL, 0x56B07023C71ECFACULL, 0x67EE0F4553469219ULL, 
            0x8C5117C8A9A15485ULL, 0xAF8C7EE24B121644ULL, 0x235F7641AD1E0F04ULL, 0x92D2894BEBC25005ULL, 
            0xE4A3A9D5C6A06C59ULL, 0x386EB008405BEBDEULL, 0xAC07F71DD4423D97ULL, 0x7901D4F6F42E2AEEULL, 
            0x4DC13ACA5F652AACULL, 0x49AB366DB3AE569BULL, 0x75B698E1A918848CULL, 0xFB15B3525D400928ULL, 
            0x24B5C357A4F3C1CFULL, 0xA27F1DD6AD407D4BULL, 0x1B96F393755F9185ULL, 0xECC0A361840B96D2ULL
        },
        {
            0xA12961F085233AD8ULL, 0xE4808F83DB630B34ULL, 0x954C7213A5A0C677ULL, 0x96C679FB4C6F70C5ULL, 
            0x9E0BBAE2FB46B0B0ULL, 0xE3FBABAB65614A74ULL, 0xACB346BAD13A246EULL, 0xCB7EF4563C5FAE74ULL, 
            0x74C7782606912624ULL, 0x64F018BAE7C971A6ULL, 0x5CE5AB4B002AD841ULL, 0x03849CA619DD3445ULL, 
            0xE3670A619E953CA6ULL, 0xFA0E3A899622E219ULL, 0x976CE553A904B247ULL, 0x37CF96E29D78C7BBULL, 
            0x655F1FC723D5194BULL, 0x1E34FAF4E3D43534ULL, 0x73F92FF9E5FCE357ULL, 0x931EE89CD3C46301ULL, 
            0xD2DC5F4842FB558CULL, 0xDAB1F9B240706EFBULL, 0x5C7012FB15BC6657ULL, 0x450C0F3BCABFBC8AULL, 
            0x55C0BC7739C251CBULL, 0x39DD690EC556EA1EULL, 0x0BA3E20F19B53C38ULL, 0xC55669EAD9EF9DEBULL, 
            0xC761A3BF73292A89ULL, 0x9A3242A027C1663AULL, 0x9DA673CFBEC13FF8ULL, 0x758DD96A63FAE646ULL
        },
        {
            0x30D407672B02D282ULL, 0x8C589E5E4E74BCD8ULL, 0xC4F5A29CFCE8E632ULL, 0x4A3E4BD8F768B7DDULL, 
            0xB489362827425F35ULL, 0x1CBAF65306B3E72FULL, 0xBBD21F789A6A21AAULL, 0x9662AE3D7B41C661ULL, 
            0xFEAE5B5CE43E2E3BULL, 0x0ABDF570F433A238ULL, 0xB01AC2A8A3F33767ULL, 0x796735FD1491C949ULL, 
            0x01A27839B2517BE0ULL, 0xA1E0699627A149D3ULL, 0x48FC9F5A58FC0FD8ULL, 0x9755D24C3E9DCCCCULL, 
            0xC3C442217946F940ULL, 0xC0E65CF67B7A0063ULL, 0xCCE1CCBB167EC15EULL, 0xDF17466160A93044ULL, 
            0x8A6207B2514866A0ULL, 0x1F627C236A0A3294ULL, 0x6704EFA70FD7C1F3ULL, 0x36364477EB5A4442ULL, 
            0xC82162910B63462CULL, 0xE705FE1299342FBBULL, 0x0D5E091A30C32B5CULL, 0x8F21BC681DEAE92FULL, 
            0x4C1100A1DDA9461FULL, 0x802CFA962C6522F0ULL, 0xC0E7E3C3EE96CFC7ULL, 0x62D1B7F7C0DBF519ULL
        },
        {
            0xBE5399B6DF5CF0EAULL, 0xF6824468F64C590CULL, 0xBD27AD9C6675C714ULL, 0x4829BA809D29759DULL, 
            0xE245BBE4B35B4968ULL, 0x611A562A3D8F1BEFULL, 0x8E0EDF7A31DE7785ULL, 0xC5E4AB89F7A5CF24ULL, 
            0x530D018613306319ULL, 0x7D50829A1C44F461ULL, 0xDACA81F1ACE85E4DULL, 0x92932FB3D5ED00E4ULL, 
            0x5775F47B34CAF9DAULL, 0x0F8C9B9D9434830FULL, 0x60B01F044EC74387ULL, 0x263470F1BD7B38FDULL, 
            0xA6442079DF975F3AULL, 0x5E9C62D388FD6B96ULL, 0x916A71983A7BE78EULL, 0x1B834B100821AFF6ULL, 
            0xBD2F0612D45887FAULL, 0x7EF7BCDADCCE3011ULL, 0x665BB0AB402C9A62ULL, 0x486A19E97B9D1DCDULL, 
            0xE94EBE2EF00557E7ULL, 0x8DACD66F9D0F5901ULL, 0x957367D36011DFD6ULL, 0x6CB56BCB4D347AFFULL, 
            0xAC6BF30DC3023AD8ULL, 0x746CBBA2EA761265ULL, 0x43AEB02708B55270ULL, 0xC7D4B9F263C695FEULL
        },
        {
            0x312E8A8C934FB709ULL, 0xA44D909A51C344D1ULL, 0x9C0E7E38DBA39699ULL, 0x4F0BD2A90BEC0BB2ULL, 
            0x86A8F68D9CD537D8ULL, 0xD82BC9D52C9B3A47ULL, 0xED8E264315272F3CULL, 0x1DCB289FC4D714CCULL, 
            0x863546906D729FCAULL, 0x28A7EA20D9629DEAULL, 0xA7A2073EAF66F02FULL, 0x448DD2B7FDBF3578ULL, 
            0x004C9B858D41C231ULL, 0xF3CF875E9EE0D1A1ULL, 0x4E07DAD59E91CE4DULL, 0x8F999F61F4B65798ULL, 
            0x5128DB13AAD0FA19ULL, 0xA10BDA373BEE67B8ULL, 0xD9F03CDD58AAAD29ULL, 0xA5A9B8EA71B2C23EULL, 
            0x0C583FCBA840E10FULL, 0xE58673FF1AC574A0ULL, 0x016C1F732977CCAAULL, 0xA6F51F693AF22668ULL, 
            0x316C6D4DF4B61524ULL, 0xDD0CCFA8B9D737C1ULL, 0x116C6D2AA3123F16ULL, 0x184F35A5C5B147C5ULL, 
            0x805DBE87E73B537AULL, 0x52AB67A760597723ULL, 0x09EDA812637FB258ULL, 0x125657C0D38F3280ULL
        },
        {
            0xB83159BAD9036B73ULL, 0x7AE7622BF8886220ULL, 0x7B3CA3F542F8777FULL, 0x6263AF211502175DULL, 
            0x97AAEFD989F87951ULL, 0xA4517A106C90DF62ULL, 0x9BD2534B732A0979ULL, 0x1D8CD0BD45F5DC0BULL, 
            0x25AC36F4A93C11C6ULL, 0x98B0A14D4FE43A71ULL, 0x290BA89DE70B77FAULL, 0xCDB87C3ACEA6CF5BULL, 
            0x795AF090661ADB3AULL, 0x83E634D6F59BFD19ULL, 0x5129BB513291C33FULL, 0x0E6C017B2991DB4CULL, 
            0x65A4FC0C9E65E2A5ULL, 0xF991E265D1C55CACULL, 0x796BD36B1BCB8981ULL, 0x8839FB3D2BAA7E37ULL, 
            0x05E5F64648F9A76AULL, 0x5F904E6A3231E860ULL, 0x511E234C9C989D86ULL, 0x1B419F76CDED8C45ULL, 
            0xBC127396E55CD631ULL, 0x0EF67F658FB9E2CBULL, 0x6A90DA7F200D0CA9ULL, 0x7012C57B07EA231DULL, 
            0xD09A44BA6C989FD7ULL, 0x95BF2E207AAEBAD3ULL, 0xE7CA6CDCAA22E407ULL, 0xAA6C66D83FA62799ULL
        }
    },
    {
        {
            0xCDA64B1206B50932ULL, 0x71E98875F7DBDBD2ULL, 0x39C3CA7404204777ULL, 0xEE3AE4BF45CF3A5FULL, 
            0x740F428B1D921105ULL, 0xC0A42D25125D451BULL, 0x7F75E6EA3275DDF1ULL, 0xFB8E243DC8A3DFE7ULL, 
            0xF80B2C97A1DD61C9ULL, 0xAFC3D252AEFF91C7ULL, 0x4C1979E33A68E5E0ULL, 0x5E24CC73CE0F422DULL, 
            0x469C59E5D8904F4EULL, 0xECF84AACBD2BA690ULL, 0x3B94746C1E5ED599ULL, 0x3580371DE1D22844ULL, 
            0x3480D7D9786203C4ULL, 0xD2D261A66F13D490ULL, 0x901E878B2F3E8122ULL, 0x1649FFEE21B91FF8ULL, 
            0xF7D96335A4D8C18DULL, 0x6C3BAAB7702BE276ULL, 0x3B5A75D871ED1649ULL, 0x63B4EBA945DDD8C5ULL, 
            0x58A0130601C66362ULL, 0xC5C9029CDF3EC84EULL, 0x610F60D282D76119ULL, 0x06804E0F8E818A59ULL, 
            0x618D889E661B4289ULL, 0x84B904277125AE14ULL, 0x68E025E134DF4DB2ULL, 0xBB1D6D298A55F3F4ULL
        },
        {
            0xC180A04EC685E8B9ULL, 0x6EF83B405CEECB5EULL, 0x0AEFE2B737557937ULL, 0xA261A1E0919DA77DULL, 
            0xE79FF64A6F348C66ULL, 0xD4C6BB06965844F6ULL, 0xDDBFCB778DDBAF63ULL, 0xA27F78149827234BULL, 
            0x9B9A015CBA2CE5D5ULL, 0x8F546AB53B0D05BAULL, 0x76E0394CBB1DC199ULL, 0xB9F90765DA5A66C5ULL, 
            0x4D026A156C5C2D87ULL, 0x8EC4F84778F0CFD8ULL, 0xAF8F6397F101A537ULL, 0x90592BFE907DDE20ULL, 
            0x8DE8FD6E86CED48AULL, 0x7AA145A9123E253DULL, 0xF0D2A29D89A093C3ULL, 0x68B61ABEB6D9C2BFULL, 
            0x8C039B083CFC7AF0ULL, 0xBBCCF1CBB4F39F2FULL, 0xD3239C7D62EAE2A8ULL, 0xD93FF003E0FCE69DULL, 
            0x9657FCF74A8331D4ULL, 0x32DCE01F81ACFFF0ULL, 0xDD0D2C7E19AFC19DULL, 0x52130C7A87798889ULL, 
            0x708844BE6ED6E172ULL, 0x3F7BF47034C09338ULL, 0x272F7270982F41C4ULL, 0x1FFE5057CADC48D3ULL
        },
        {
            0x36B4845BEB25E862ULL, 0x265E5494E7B2E63AULL, 0x0E0F3DBDA081C7CEULL, 0x91A4768868C8E5FAULL, 
            0xDC7BC03C8F55A531ULL, 0x36E711F94F97F09CULL, 0x86F0CBAEE1FC0E8BULL, 0x80E9C56148418F1DULL, 
            0x6B36C7307B140418ULL, 0xE7DBF4A8AAC2FBB7ULL, 0x338E9102202E4131ULL, 0xA6F55E2A5FD2D5E6ULL, 
            0xF36B757517F6F0E6ULL, 0x0E43955E9D08424CULL, 0xDBCA49EB9BC7409BULL, 0x94EAF6B0A739EC2CULL, 
            0xAF092DF34BC7F10BULL, 0x8F51AA329494C996ULL, 0xD9FD5F4EA73AC027ULL, 0x66D20E505F7197BEULL, 
            0xE884E7191E0E7F62ULL, 0x96C2EFE0036A851AULL, 0x78F9FC6EDE529B36ULL, 0x8A59D022E6C47335ULL, 
            0x7DEA48671852E404ULL, 0x2A7081584F2C10FBULL, 0x78E5364A5E4D4E95ULL, 0x22012B8E7BB08923ULL, 
            0x05B3AA0FDE3989B8ULL, 0x4326E4628327FB84ULL, 0xBE61B3AA2F223FA7ULL, 0xC4F295AF43B0EDA0ULL
        },
        {
            0x72EB10CFEF51EA94ULL, 0x3994BABE7ACE3D3BULL, 0x8F04F59D793C5A89ULL, 0x0C8B7EF1E039E747ULL, 
            0x059FC03E8AD227D8ULL, 0xA7C0FF6E0BAAF544ULL, 0x60420F61D4123979ULL, 0x7D784C5F91498BC7ULL, 
            0x0726AA8E98EDE818ULL, 0x6C2FA7216442E42EULL, 0x981F70FC768BD27AULL, 0xDFD54C217A20555FULL, 
            0x0D00516D53060494ULL, 0x173AF4E8909054B1ULL, 0x8E09633082E7AE7EULL, 0xE4CE38781276F6F9ULL, 
            0xE3179B0C81FAED3BULL, 0x707CF6F794846DD1ULL, 0x2021643549DF5661ULL, 0x685C32778D6A3E04ULL, 
            0x8E8115D2428B451BULL, 0x4111049471174FEEULL, 0x2B5D6EA97DC692EEULL, 0x4779EBDCE8CF1D31ULL, 
            0x3A6849C877ED1F28ULL, 0xF38082FC1A78906EULL, 0x14726BED031DB62FULL, 0x3ACC1429D55D61F1ULL, 
            0x7ABDE03B121D4F63ULL, 0xADF2D578DE074940ULL, 0x2CE9C641F932E821ULL, 0x40F9AE8FAC6F7E67ULL
        },
        {
            0x7B973403CFAF00B4ULL, 0xDC229FEC604F2ED0ULL, 0x75CB94139DFEBE01ULL, 0x01D7CA350256234AULL, 
            0xD581FFC222535150ULL, 0xEC0D562B6D788801ULL, 0xB52B96F6863769AFULL, 0x9E8360CDAEB4B6B6ULL, 
            0x84E919F010728425ULL, 0x903E551261CBCD04ULL, 0x093648491D16AB1AULL, 0x0313C8C62EB11DBBULL, 
            0x1B3BB909D0A4BEEAULL, 0x3505D356CA567BC9ULL, 0xAAFFB35DE62CBA6BULL, 0xE24E0A0A611BCDAEULL, 
            0xFC351FE2E81C9BA3ULL, 0x04D1420987A4E835ULL, 0xE628F4EA0C9439B3ULL, 0xA02A3B7DF27BCA90ULL, 
            0xC3FEA8F66610FF90ULL, 0x1C97EC1AA8127B78ULL, 0x00FB94E82301B660ULL, 0x35F261692318978EULL, 
            0x0333739186A3F990ULL, 0xAEBD605713547C71ULL, 0x9826057985AEF5FAULL, 0x0DDDBA0540854240ULL, 
            0xB604A148CC96FF1DULL, 0xEDDAFD731DF400EDULL, 0x37874A4434453E1CULL, 0x9F4AE8FA5AD0EC8EULL
        },
        {
            0xB07F80483582ED5CULL, 0xD01186F9871B1147ULL, 0xE3EB8D3FA30D7D59ULL, 0x93C1C5DB1361D09AULL, 
            0x804045B82E7C3A6BULL, 0x08BF4D48CCAE56B2ULL, 0x6ACD3AE2D622877FULL, 0x2869227A7B66C68DULL, 
            0x14E6DEEC5F0B4CE1ULL, 0x9316888930C5630AULL, 0x9DA33D7623B85B59ULL, 0xF866E3B629F8544CULL, 
            0xA028FE17D44297D3ULL, 0xD8470C7760802D99ULL, 0x91B2FC0B9F8E2100ULL, 0x60B30976810E133BULL, 
            0x4917D42394C2DCD7ULL, 0x27E1B1E37FDBB6BEULL, 0x0F10285C0127A6B4ULL, 0x67CB858EBC6D20DDULL, 
            0x9308AC7FFC4D9797ULL, 0x74EA55C8AE9250F0ULL, 0x49696DAC1D167577ULL, 0x61FDF9C0D24BC5DDULL, 
            0x7B2D3AB774A55EBEULL, 0xFB7E935DA4EF64EEULL, 0x7306DC7D952BFEAFULL, 0x70E52CD972653171ULL, 
            0x44D4C2187B4F7AA9ULL, 0xFD9A263037D4170BULL, 0x39BE78D4A42C90A0ULL, 0x6B3AF579CB2503B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseHConstants = {
    0xDCB39C19AE22ADD9ULL,
    0x33190816F7A07773ULL,
    0x5B20D9801CFB136BULL,
    0xDCB39C19AE22ADD9ULL,
    0x33190816F7A07773ULL,
    0x5B20D9801CFB136BULL,
    0x44895F85B73B1E9FULL,
    0xBB93EA4572ADDD4CULL,
    0x61,
    0x8B,
    0x4B,
    0x3F,
    0x85,
    0x45,
    0xA8,
    0x4E
};

