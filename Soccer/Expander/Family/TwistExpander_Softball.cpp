#include "TwistExpander_Softball.hpp"
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

TwistExpander_Softball::TwistExpander_Softball()
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

void TwistExpander_Softball::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 17685118961619552040U;
        aCarry = 15458255155281204377U;
        aWandererA = 10262524477991793484U;
        aWandererB = 9955165220640720963U;
        aWandererC = 12174702757059951174U;
        aWandererD = 13792674917742671568U;
        aWandererE = 15283273115208163760U;
        aWandererF = 10150188103872049479U;
        aWandererG = 14866857871801721875U;
        aWandererH = 15546486098557542745U;
        aWandererI = 16584666693034922797U;
        aWandererJ = 12159050250750028693U;
        aWandererK = 12309142234710126788U;
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
    TwistExpander_Softball_Arx aArx;
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
    TwistExpander_Softball_Arx aKDF_A_BArx;
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
    TwistExpander_Softball_Arx aKDF_A_CArx;
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
    TwistExpander_Softball_Arx aKDF_A_DArx;
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

void TwistExpander_Softball::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 10480033589765287518U;
        aCarry = 14499391079176501942U;
        aWandererA = 15421220186226856407U;
        aWandererB = 18414898189672708977U;
        aWandererC = 11191011817450883422U;
        aWandererD = 16366100346808175357U;
        aWandererE = 14019419694821268833U;
        aWandererF = 9401925201225003655U;
        aWandererG = 15992097555836748041U;
        aWandererH = 17585520483828504620U;
        aWandererI = 14775245544087309042U;
        aWandererJ = 15182013252946096341U;
        aWandererK = 11515831495233825881U;
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
    TwistExpander_Softball_Arx aKDF_B_AArx;
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
    TwistExpander_Softball_Arx aKDF_B_BArx;
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
    TwistExpander_Softball_Arx aKDF_B_CArx;
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

void TwistExpander_Softball::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_AArx;
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
    TwistExpander_Softball_Arx aSeed_BArx;
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
    TwistExpander_Softball_Arx aSeed_CArx;
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
    TwistExpander_Softball_Arx aSeed_DArx;
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
    TwistExpander_Softball_Arx aSeed_EArx;
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
    TwistExpander_Softball_Arx aSeed_FArx;
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
    TwistExpander_Softball_Arx aSeed_GArx;
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
    TwistExpander_Softball_Arx aGrow_AArx;
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
    TwistExpander_Softball_Arx aGrow_BArx;
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

void TwistExpander_Softball::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Softball::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 14488706718959392394U;
        aCarry = 17351029483253256617U;
        aWandererA = 16260763261242357845U;
        aWandererB = 15169748891736426812U;
        aWandererC = 12061970327368985567U;
        aWandererD = 13262296592367579192U;
        aWandererE = 17029668123863066542U;
        aWandererF = 11553554899285078527U;
        aWandererG = 9232174380928855365U;
        aWandererH = 15972577578797289454U;
        aWandererI = 12218325178639768338U;
        aWandererJ = 11300005324088093369U;
        aWandererK = 13420572722629460916U;
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
    TwistExpander_Softball_Arx aTwist_AArx;
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
    TwistExpander_Softball_Arx aTwist_BArx;
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
    TwistExpander_Softball_Arx aTwist_CArx;
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
    TwistExpander_Softball_Arx aTwist_DArx;
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
        TwistExpander_Softball_Arx aGrow_AArx;
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
        TwistExpander_Softball_Arx aGrow_BArx;
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

void TwistExpander_Softball::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 1 with offsets 5559U, 466U, 3670U, 4145U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5559U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 466U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3670U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4145U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 1, 2 with offsets 2814U, 3190U, 3628U, 6621U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2814U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3628U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6621U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 0, 0 with offsets 7758U, 4957U, 2163U, 971U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7758U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4957U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2163U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 2, 3 with offsets 6974U, 7038U, 747U, 3858U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6974U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7038U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 747U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3858U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 2, 3 with offsets 13U, 1198U, 910U, 150U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 13U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1198U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 910U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 1, 3 with offsets 1936U, 1734U, 602U, 182U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1936U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1734U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 602U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 182U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 2, 3 with offsets 917U, 859U, 520U, 485U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 917U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 485U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 1897U, 176U, 1797U, 1690U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1897U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 176U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1797U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 472U, 1952U, 477U, 369U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 472U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1952U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 477U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 369U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Softball::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 3 with offsets 1979U, 4643U, 5047U, 5089U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1979U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4643U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5047U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5089U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 1 with offsets 7611U, 3070U, 4578U, 5415U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7611U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3070U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4578U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5415U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 2, 0 with offsets 1856U, 7658U, 7503U, 324U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1856U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7658U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7503U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 324U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 2925U, 7962U, 1126U, 3618U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2925U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7962U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3618U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3253U, 1701U, 916U, 1867U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3253U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1701U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 916U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1867U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1588U, 1997U, 1599U, 1013U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1588U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1997U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1599U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1013U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1768U, 1546U, 1689U, 265U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1768U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1546U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1689U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 265U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 759U, 573U, 1719U, 188U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 759U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 573U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1719U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 188U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1204U, 948U, 1209U, 192U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1204U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1209U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 192U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 1, 3 [0..<W_KEY]
        // offsets: 2037U, 1747U, 21U, 1673U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2037U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1747U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 21U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1673U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Softball::kPhaseASalts = {
    {
        {
            0x995EE355F5712AD0ULL, 0xA93E8266B42E5759ULL, 0xAA83B73640DE1A08ULL, 0xCC2B9A8817EC5A92ULL, 
            0xA05C6B6B01ADB1F3ULL, 0x8DBBDCBBAF0AB694ULL, 0x97C32144A9A88C14ULL, 0xC278989109885A32ULL, 
            0x099F68E1459206E1ULL, 0x95A6F8DC9065D53BULL, 0xDB58FE00AB8EF096ULL, 0xDA57121C670392ACULL, 
            0x604FF842A1CD91B9ULL, 0x66969798C18B98D4ULL, 0x7AB601C72D1E869CULL, 0x6A11BECE7462F2EAULL, 
            0xFDB7CD6DAD957659ULL, 0xC83734F1DF688904ULL, 0xA2FE4C3009287D1AULL, 0xAE726BFD208B516FULL, 
            0x3DF59F672526D365ULL, 0x0859D4E4788B3754ULL, 0x31D06A7AFDCDE53EULL, 0x9FA1EF2733565E18ULL, 
            0xF663C4945E191F26ULL, 0x928EE92F0E5200D0ULL, 0x53B13D8B2877AA70ULL, 0x0DC4C28651F3E428ULL, 
            0x539B82FBC87484D2ULL, 0x8FBD84EDD62A477FULL, 0x79FDA6CB13BDF589ULL, 0x7F5107166AAC8BB0ULL
        },
        {
            0x3967D7725E02D430ULL, 0x4EF4749E3EF762FAULL, 0xDC760D9564815683ULL, 0x8CC3F044225F3004ULL, 
            0x387D21187B5D1B09ULL, 0x400DDBD857DA46DDULL, 0x655F0B90F246E6F5ULL, 0xFA20750BCFCD0ABAULL, 
            0x311D2F0C9F753F2CULL, 0xE985CCDC93D7B827ULL, 0x86086B2C902C919FULL, 0xA38324B36EB8D36FULL, 
            0x2754ADD72F8C7BA6ULL, 0x1B667838E8233D6CULL, 0xB2A3D479998F4510ULL, 0x536B1CB14DECF5F0ULL, 
            0xD9BBAEEC1FAC5CA0ULL, 0x96E3D3FBF11140ADULL, 0xC19194714FBCFF1BULL, 0x6F38C7DB0D9D2A87ULL, 
            0xD3F13AD963DC99D2ULL, 0xA7E22BCF18E1C8F2ULL, 0x1BCB959B29F88E57ULL, 0xC991E7EE218BAAA8ULL, 
            0xE889ACBF47D31232ULL, 0x21918935E84A75FEULL, 0x0443F29CF87B56C6ULL, 0x4C66FC3F51B6BC30ULL, 
            0x00309A067E20C167ULL, 0x73A74235C88AE51DULL, 0x5E277E746DCA2FEBULL, 0xA6010980E831B4D0ULL
        },
        {
            0x9539402E2243BF82ULL, 0x2A83C9E9E7D9ACB1ULL, 0x760FBEC7EB93764DULL, 0xA58E97074D65786EULL, 
            0xE0B8850A009DE33DULL, 0xA784424D287F7590ULL, 0x94BF66FC024997C3ULL, 0x071E7E2A9E24BA22ULL, 
            0x047E46596A3355FCULL, 0x75F570D3B7E87231ULL, 0xCDB25FC380C7FB7AULL, 0x6C584F72CB6FF3CBULL, 
            0xCDA2F9B910C6390EULL, 0xD6562C1AFDA78569ULL, 0xF10B6729768DB8E1ULL, 0xD72AEF6185DF85A5ULL, 
            0x1FFEABDB8839D182ULL, 0x3EBA395561BCF9DCULL, 0x0481C8FADC076ABBULL, 0x86A90CAB1EF8322EULL, 
            0x49A74D0EE6EBD060ULL, 0x0FBC4A11AD4C3033ULL, 0x802BF3E71DF9196BULL, 0xD666849D3E18CE6EULL, 
            0x047E9F2985EB270AULL, 0x4799A22D4FDE1436ULL, 0x1C5049C64B490DDFULL, 0x9DED62C87358C616ULL, 
            0xED6ED027732531B4ULL, 0x07421B77A806B3ACULL, 0x1B1EFE0C91249A63ULL, 0xA107CAF6DBC7AF65ULL
        },
        {
            0x48A99B9BB04E8893ULL, 0xDB6B75FF888B9FC4ULL, 0x330D0302759B294DULL, 0x9923948FDEB6B207ULL, 
            0xDE15F27DCFB4889EULL, 0x628058B8B00D59C1ULL, 0xD09689056EC4B785ULL, 0x145718638BC5B9DEULL, 
            0x496608B952841741ULL, 0x9BECD9E19523AEEFULL, 0xCB3C7257BFC870E3ULL, 0xCF15AF66D64513C0ULL, 
            0xBAD1098412F2E469ULL, 0x4204E64AC4DDFADDULL, 0x8760B3D97AD5AA48ULL, 0xF7BF53EACEF2D383ULL, 
            0xCA6415AB58F34945ULL, 0x0664C08949A341D5ULL, 0xACA31201D71E55DFULL, 0x9047C8BD6024FC02ULL, 
            0x3DBD00D64B1B5178ULL, 0xD0A9CA4013652FACULL, 0x109F257498E4976BULL, 0x817F6C68B1C27FDFULL, 
            0x936BD280878D7B65ULL, 0xACB7C40E3EA8BF3CULL, 0x1AAC35A71E32830AULL, 0x54BA3EE200B06C8CULL, 
            0xF0C668E73DBAF141ULL, 0x1C9D106A0532C3CFULL, 0xABDE826192F64DF6ULL, 0x5B2B965D3E15CFE8ULL
        },
        {
            0xF68486987BFB4DD1ULL, 0x0300A5DEF3B0DD8DULL, 0x294C26FF8BCF8827ULL, 0x71637DB1942EED37ULL, 
            0x2B2F41C869C646A1ULL, 0x84BAF7F1F6521D6CULL, 0xFF7E4DC34FD0B382ULL, 0xBD55DE2015D87380ULL, 
            0xCEC52B2782851952ULL, 0xB35E2DE7A963D080ULL, 0x7E9E8D2250E2A755ULL, 0x2EEA513C167F9E0AULL, 
            0x7F14A26358381CA7ULL, 0x59B505E9DDDB3537ULL, 0x0754AF824F9BEDE2ULL, 0xC08CD68B70A69509ULL, 
            0xF54D83AE93435DF4ULL, 0xFE1116B7BEC60BAFULL, 0x7F41C7CA1BD6F564ULL, 0x2223052D1BCEE1BFULL, 
            0x0F238D02A14C26D2ULL, 0x959A2FFD8D84D537ULL, 0xB91B25F6005150D2ULL, 0xA948665DD0B5A3CAULL, 
            0xFC3D0D4418D2A413ULL, 0xA0D744CDF6FA3076ULL, 0xE24CC3F300E20922ULL, 0x8A4DAD089C86A4A7ULL, 
            0x0879BC2508CA850AULL, 0x3DDF2CCCE6ECD4FFULL, 0xF8807B3B49C80743ULL, 0xCB6D2FD7FD04AEB2ULL
        },
        {
            0x2FD6E5E8EFC1D4ADULL, 0x74AFB6D1ADB490C8ULL, 0xB5E862176DA0932CULL, 0xD9FCF0F3DD1855A6ULL, 
            0x2347F3AB04545049ULL, 0xE775320B5C1F0D44ULL, 0xE252C5499BCE3FBEULL, 0xA7F9AC6DE73021B3ULL, 
            0xD7FDB80940E95514ULL, 0x836F787DD6AC444EULL, 0xBE2A7B9065A3AE47ULL, 0x804DF1CDA44AC47AULL, 
            0x17E5D97DC415D676ULL, 0x1192810D964A3DE0ULL, 0x5061053BA2772F5AULL, 0x6A5D8684021199A0ULL, 
            0x101EC8A939919896ULL, 0x9C67A6297C25A612ULL, 0x1EEE7F79F989F1A1ULL, 0xDA4916F7E647C7EAULL, 
            0x3D7BB4A60DEE14A1ULL, 0x33D51D6234AED7A7ULL, 0xC2DEE0CAEADA66B0ULL, 0x3F9E7833AD9B8BCCULL, 
            0xFECF48BF64B601F5ULL, 0x1786C385D7BC1E3AULL, 0xE9F957C5412137B5ULL, 0xD888EFAF4A114D2DULL, 
            0xFF58C3C67AEB1883ULL, 0xACA57738887A3558ULL, 0x41A7AF1B685FF8C0ULL, 0x678D07680E282C79ULL
        }
    },
    {
        {
            0x3186BE695436B044ULL, 0x0626BA4DB43202AFULL, 0xEFF0C34DD32E7744ULL, 0x01D3B81519CB6A95ULL, 
            0x3B84E9625C5E00B2ULL, 0x1551AA9D82C32E57ULL, 0x02DC7D580F55C0F6ULL, 0x0F076255DCBB87F9ULL, 
            0x3826A877CE9698B3ULL, 0xE0D86A3C1F3D9362ULL, 0x1043063ACDDB42B5ULL, 0x3BFF726D32806769ULL, 
            0x82B16C055CAE1F71ULL, 0xB8D6D0D9E2A0189FULL, 0x4A6218A51A1FCB10ULL, 0x6C548B387FC8B23DULL, 
            0x44049748B98C6F41ULL, 0xFCED748130125725ULL, 0xAD3263ABC2550EFFULL, 0x8838BBA8B595FDA1ULL, 
            0x9AD24CE75D8D5F07ULL, 0xE6274151A936E4FAULL, 0x8AE0563FFB60D401ULL, 0xCF8B39DD3E7E4A58ULL, 
            0x8CE5093586203DCEULL, 0x7D732308DBE2CF7FULL, 0xC087E57DD6F11EB9ULL, 0x083585E5CBE45D72ULL, 
            0xDEDD49B3E1EB800FULL, 0x94986AEB21ABBCA7ULL, 0xB496C8E76A7E74FFULL, 0x28E60F3ABA1A0DD4ULL
        },
        {
            0xCF0A3C650B149F9CULL, 0x88EE85119089C946ULL, 0x8259A15239EE8AB7ULL, 0xBBE8F2DD1EAB6C93ULL, 
            0x8FF8D548DC847333ULL, 0x88CFDEF507697EDBULL, 0xF2819E75832058E4ULL, 0xFDDEF0D684480C7EULL, 
            0xFF6CE727C2D8817DULL, 0xA8DEC71BDAE3EA6EULL, 0xD1EF74A8A3AF0B07ULL, 0x38206863E5D3D06AULL, 
            0x97312D514BB21855ULL, 0xCE971992FD2F428AULL, 0x085E60EBE36D43A7ULL, 0xFFD089DF0AAECFCDULL, 
            0xDB857BF8E5E839B0ULL, 0xEE6E189A12A7072DULL, 0x600BBFA06C0096B9ULL, 0x10C2AACD2BB9F738ULL, 
            0x800CB7CE62004A21ULL, 0x902D6720FBF20725ULL, 0xF2FC6202315472D2ULL, 0xB40E17E089272995ULL, 
            0xF41CF430E7E61DE2ULL, 0x82F7B1A83D44F36DULL, 0xE10A71E4C067981BULL, 0x2C45EE7B65C2D457ULL, 
            0xC3915DE785F2C123ULL, 0xA23C75BE10BD1241ULL, 0x79B58C11A79E33BAULL, 0x0A848333EC3F19A4ULL
        },
        {
            0x3674D251F57107F0ULL, 0x0B42B088A575A78AULL, 0x9F4F96E64517D907ULL, 0x207D609D1A353D43ULL, 
            0x80081F47FFC69FF4ULL, 0x497B96E379C85A4DULL, 0xB1D2C6261CA24F1AULL, 0xEFA7E44850105A4AULL, 
            0xF1A93A0BF85144A2ULL, 0x0007EF130E6DD40DULL, 0x66A02F290C615753ULL, 0xEEA81FD77013581EULL, 
            0xB60C7F5A845BB5ADULL, 0x3C0F22431A3B0306ULL, 0xB12FE7D70ADE228AULL, 0xEE598DC74CE96F28ULL, 
            0xBC9319C3E2ECF827ULL, 0x106997B3441EF170ULL, 0x64026CF332919ECEULL, 0xFE0AD079FBB9201DULL, 
            0x775242B16D70A3B6ULL, 0x8241AFE395FEC6BEULL, 0xF8C95ABAC4C2597AULL, 0x776F20A69CCA8F50ULL, 
            0xDAF21AE5A47A76FAULL, 0x4D5BFA651DF556FAULL, 0x1343254C8BB5E5DCULL, 0x375DB75ABEE2ECF3ULL, 
            0x3A094E080E13BC14ULL, 0x8D370C76FC2BA679ULL, 0xD682AAA8ABD1D82BULL, 0x7B1043D3FC8D2031ULL
        },
        {
            0x87825129E13A833AULL, 0xDE7CE29A896A323AULL, 0xF9F3D492D3C44781ULL, 0x4D2EEDA6E39D2F64ULL, 
            0xC7E2AD0CF2CC793FULL, 0x3F932D0B7929F76DULL, 0xD0915ED55E2B7E8EULL, 0x079E6C622E6811A5ULL, 
            0x12FC809455685021ULL, 0x29D58F6EFBAD74D8ULL, 0xC61B27D3BB81BFF0ULL, 0xAB12ABB327B7B209ULL, 
            0x5B235923CBC3E543ULL, 0xA70B2C45387EC381ULL, 0x4823BCF56BFE955AULL, 0x1680D4B850E73292ULL, 
            0xE5B67AEA10E7B0B5ULL, 0x311201EBC62D53EBULL, 0x1945261CA2A2BD5CULL, 0x05741C9A41E0C331ULL, 
            0x6E4DA0FBF08E8054ULL, 0xF6D31BB84EFEF6D2ULL, 0xCB26F4E22A08B3EEULL, 0x5F59A45A6201F952ULL, 
            0x4F29D0D04347C883ULL, 0xC12A3628962C7BDFULL, 0xF7D460C1D2EA9A0DULL, 0xC28E053EFB9B975AULL, 
            0x6F17477D3CA53053ULL, 0x75CC6251B21C9C89ULL, 0xEF189245C4477727ULL, 0x805CCF6F51A8C077ULL
        },
        {
            0x350A1FFF0C39EB64ULL, 0x360AA5BE1B70A4E3ULL, 0xB8FD52848F5DDD80ULL, 0x0A224FEEA0224DDDULL, 
            0xB7BB7C8111328059ULL, 0x9BC0514FAB21B423ULL, 0xF685C22F0E69A4D3ULL, 0x7AA73E59EE4547E0ULL, 
            0xB561FB06BCCC919BULL, 0x4E91F698C194B5DFULL, 0xD393818153443282ULL, 0x5004BEF2FDCE67F4ULL, 
            0x03B4350A01C1ECE8ULL, 0xE1291C1DAA0D208DULL, 0x1D826FF46982F8A7ULL, 0x99EA4AA00BF91DD8ULL, 
            0x5BEE91DA4C71D9CBULL, 0x923375086445AAFCULL, 0x194B7E909BD97A22ULL, 0x547C1B0B3208EACBULL, 
            0xEC2C8657B453563CULL, 0x9FE10518D6682ECDULL, 0x1D4AF3BB6F1475BAULL, 0xB4161B6BD8C46310ULL, 
            0x033F6A46F937A3E8ULL, 0xE9259185803AA5C7ULL, 0x299C2680372F0880ULL, 0xAD46F5B44B7C8913ULL, 
            0xD4C672CC00AB0461ULL, 0x0806253970917D81ULL, 0x3F3507CFC956032FULL, 0x8846D1A53F439B65ULL
        },
        {
            0x31C17AACFE015E18ULL, 0xD3135F54F6D75B8CULL, 0x56791E9706045959ULL, 0x3721366BC8EABB0AULL, 
            0x084867BD40B6AFF4ULL, 0x9834E71DF83D2CE2ULL, 0x16080DAA44A8CC20ULL, 0x512111CB90EF8681ULL, 
            0xEA47C095FE1282DFULL, 0x76091103EB6808C9ULL, 0x3EEF083F7C29C998ULL, 0x634C58BD8C8793FCULL, 
            0xF1F38030402C7309ULL, 0xB6C4385E1C295B3AULL, 0x9231D6C36C0B40D4ULL, 0xEDDA57BB4C00CFFEULL, 
            0x2B6D02B06FB0A95EULL, 0x19DE2F6C24FD5D17ULL, 0xF0BC6B2262465A3DULL, 0x4AACDB9A9D7FB467ULL, 
            0x0B95BDCD4E405BEEULL, 0x6D385402D357C25AULL, 0x9D3E3BF08D963316ULL, 0x390D83C87C78E4F3ULL, 
            0xEC968079D8295584ULL, 0x8BC002EE5567D048ULL, 0x264E24D8C3D9C5D3ULL, 0x107AF2C98CE5EA5AULL, 
            0x2CA03EC3D8E39D52ULL, 0x4F93DFF477B8250DULL, 0x593AF2442FB0C429ULL, 0xF1B10B44B8F3CD83ULL
        }
    },
    {
        {
            0x087288CF726E72AFULL, 0x2544865EBDFAFA4FULL, 0xDC994D04E3806C1BULL, 0x61FC2C94D8EB437DULL, 
            0x21369EA356131DFDULL, 0xEAD51EBFA4224184ULL, 0x5ED4ED88D8DB2D39ULL, 0x501091D04D4723A4ULL, 
            0x31D5A1A38B0E305AULL, 0xE9281068B8CF6FE2ULL, 0x47FDA4F33ED3BE85ULL, 0x8FA3F9C2FF83418DULL, 
            0xDA99314D5393E32AULL, 0xC5328175183DA8C0ULL, 0x33F740DCF69751F5ULL, 0x52C3EA2762090959ULL, 
            0x1236C8FAE74CDE81ULL, 0x92F21CC57B5E5914ULL, 0x764C4B34CD8B1554ULL, 0x98827940D2A375FFULL, 
            0x727A5D9356EFB706ULL, 0x91DE16C932A58414ULL, 0x4D724E9FDF95B085ULL, 0xA0967BC9D4CA71CBULL, 
            0x9C3C7CECF76CC0A3ULL, 0xC68914BB9259DAF4ULL, 0x7E91283072183B78ULL, 0x1314944D393C93A3ULL, 
            0xD7969825BDDE1334ULL, 0xCB82D3ADB89A2004ULL, 0xCC82D100DA49D35AULL, 0x0903AF7B05E31874ULL
        },
        {
            0xE94B5BE3D42DFF36ULL, 0x451EA61C255AB6B7ULL, 0xB19E5422C604CAEAULL, 0x0A28AD7DE88F1805ULL, 
            0x564F0B6496CAB601ULL, 0x2BD6AFEF636386ECULL, 0x7717532C7E421D7FULL, 0xAAC0DCB8CEE6C450ULL, 
            0x71041F5DBDBFDDA6ULL, 0xA5C8803ACF05A4C2ULL, 0x8FE9A3437C4E4963ULL, 0x76B505E080B725EFULL, 
            0xC2F04AA9713B0A3CULL, 0xD25A66C8D7572048ULL, 0xB16EEFA65D6CA0E6ULL, 0x77693A328E0158D1ULL, 
            0xA1860FBECC180604ULL, 0xF7F78454786C80B7ULL, 0x02130BB3E39E969FULL, 0xDBECA245A60229E3ULL, 
            0x2E2CE24A82E8CF7DULL, 0x3A7758777AC9CC1BULL, 0xE9D70EF1F03FF02AULL, 0xF116E2CBCB60A367ULL, 
            0x826F6542917B5EE2ULL, 0x8B630EEC64C30C74ULL, 0xE34AADD19001B472ULL, 0x4FAB98BACC89B1F6ULL, 
            0x793EA9D68B3BD482ULL, 0x23A258AC97498C02ULL, 0xC93BEC4F028DF5FCULL, 0xC47BB1428EA46365ULL
        },
        {
            0x6CCCB9BCF21E882DULL, 0x739FE71852776786ULL, 0x430377664789DE00ULL, 0x904F9BCA0B59BF55ULL, 
            0x7D9597AE5F95BC55ULL, 0x8D738844E92B8F31ULL, 0x160B2830A0831244ULL, 0x4AA1BDFC844BE3C6ULL, 
            0x3A1B10CEAFA0B118ULL, 0xFF7A557128C80D39ULL, 0xA7375D9CFBBE3D99ULL, 0x92A5D481E15430FDULL, 
            0x216F21A8988A58FEULL, 0x6D8547BC3307AE45ULL, 0x1822497D2630E0B7ULL, 0x381B85F7B06A1F98ULL, 
            0xF749D641A28F6224ULL, 0xFC791725AF3B79B3ULL, 0xCD5A0C3A4D4A2E18ULL, 0xDC94A85EC4AECD11ULL, 
            0xCB67F882BCB5096FULL, 0xF5950D01CDBA6F0EULL, 0x4FB8D529FE0899F6ULL, 0xC70358ABE4BBF2CDULL, 
            0xCBD9FDAD6701D453ULL, 0xCD57CC2D41A777D6ULL, 0x243E410DFC03FE68ULL, 0x6349C637D782077FULL, 
            0x3BD2B4373BA89E5EULL, 0x9C90A9C22828C63AULL, 0xB450AD4784FAF4B6ULL, 0xCF583263F692DE71ULL
        },
        {
            0x29DB6B6F620CEAEDULL, 0x5BC0DA3174AFEBB6ULL, 0x27F9C37B2E183BBFULL, 0x956F78B1D1F6B1A7ULL, 
            0x7806C2773F079089ULL, 0x8809DAE53EB31C95ULL, 0xF12822D973ED3BBCULL, 0xCE6CC82E727CBD7FULL, 
            0xE0FC45B2898B2FECULL, 0x41B209AF2CCE1B86ULL, 0xBAB43795560C92D0ULL, 0x4A9EC5B6D891902EULL, 
            0x0096D1DB0A4B1133ULL, 0x488C83A641B5CF0DULL, 0x572EC182D5836B83ULL, 0x4B591F2FE29E7DDAULL, 
            0xE927130428F2C327ULL, 0x4270D35EC7EC985BULL, 0xA0C15E762A17C1E7ULL, 0x9AF8FF04F76DA70DULL, 
            0x9BDA7E4422B622E9ULL, 0x772B33C5377A0BB6ULL, 0x0514DEF0007E895AULL, 0x28C9FD46AE9A040EULL, 
            0x35A8895A404940A1ULL, 0x31D9D2EB385B8CF9ULL, 0xAACBBEA7B56E17C6ULL, 0xE2A121A5342D0557ULL, 
            0xAEA34AB614D5D37AULL, 0xDA1D3C470964E4A5ULL, 0xAEE99E98AFDE9B91ULL, 0x0681D7A36AC6A49EULL
        },
        {
            0x13B9DDF29D3052D2ULL, 0xAFF7EF61BA6D024FULL, 0xA577C49B56A3CE19ULL, 0x89C825015AD5A4CDULL, 
            0xD3F69ADE103025F3ULL, 0x24BE7EC88D016F53ULL, 0x1882634B179AB874ULL, 0x3677617D5983D93FULL, 
            0x860C43F4C1605B2DULL, 0x1DE023C96D8FBB54ULL, 0x7598B72D5C44368BULL, 0x92844CDB7A504F04ULL, 
            0x4E3139182A9B965DULL, 0x5CFE6CBFDA8742C3ULL, 0x53EA015B2E0A5EE6ULL, 0x080447B0CE64EDC7ULL, 
            0xFF0A3539B1893127ULL, 0x4CF928BE9F05460BULL, 0xE67B81A2415DC920ULL, 0x0B670FF94B253061ULL, 
            0x4A6186616F33D93EULL, 0x6685E7F82BA4371FULL, 0xC3F162B496DFF579ULL, 0x08D627E994B60D61ULL, 
            0x1014FCC58680D65CULL, 0x0A52EEDEB9A04D53ULL, 0xC340C1B421684073ULL, 0x20888A8AEAD387F6ULL, 
            0xA9E82AC1AB538ABDULL, 0x474549B6EBEA0EFFULL, 0xF3FDEB6022C94BE2ULL, 0x84D3AC9A0F1A3266ULL
        },
        {
            0x702ADA9C8C061DE1ULL, 0x1F989C9073C98838ULL, 0x17AE3631FE9A7E73ULL, 0x4EB959EAFBF1CD48ULL, 
            0xF90B62568A3A865DULL, 0x04CCD04F6434A536ULL, 0xDFBEA181F4180EBAULL, 0x303B5976C124758FULL, 
            0x7ABD5E1ECBD7D0B3ULL, 0xA8D0BC5F8D8567BBULL, 0xE048F0F2F0FBFFADULL, 0xC96FDB617AE3B3AFULL, 
            0x37AA50775946C5A3ULL, 0x796FA94F76BFEA31ULL, 0xDEE38920543AC0B7ULL, 0xAFAFFA4D1AD57279ULL, 
            0xC7D107E1CECA8C24ULL, 0x28FDA02D0BAE8303ULL, 0x3D94FB902709A69BULL, 0x8CCFF8E808B8F824ULL, 
            0x40EC94D3EA18700CULL, 0x8B2154FF4DE6AB9AULL, 0x0604FD98603FF30DULL, 0xCEF19F8568F36EE5ULL, 
            0xE28B5F18A21CC955ULL, 0xF09C6A2EE489492CULL, 0x680C79F7E7CE2CA5ULL, 0xA013F50688D17FE7ULL, 
            0x5182064802E56886ULL, 0x10DA9E9D0FE72237ULL, 0x723B5A350624D0F3ULL, 0x6C00EF3F92AD18FAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseAConstants = {
    0x795E48F475D8CE79ULL,
    0x5A04B5C8E511DC5BULL,
    0xC7EF758E11CB737AULL,
    0x795E48F475D8CE79ULL,
    0x5A04B5C8E511DC5BULL,
    0xC7EF758E11CB737AULL,
    0x2BCD2E031E97C71BULL,
    0xE458616AE6C1AFBCULL,
    0x44,
    0x69,
    0x19,
    0x13,
    0xD4,
    0x0B,
    0xF5,
    0x46
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseBSalts = {
    {
        {
            0x0EC0CA8841DAE832ULL, 0xCE948D8AA92F04A6ULL, 0x454FA9A5E04841C6ULL, 0x91FE8A8F064B3C9DULL, 
            0xFA80FDE61FA87DE7ULL, 0x3046D8AA78DFE58FULL, 0x6A087F65916F7C20ULL, 0xD9D60266635BF10DULL, 
            0x4B1BD5FAA80BB1F8ULL, 0x0377D8FCA4B0CA55ULL, 0xE4595B2050A0BA2CULL, 0x052C2D18F8C065F8ULL, 
            0xAEDC937E84C25B01ULL, 0x20D8494374750521ULL, 0x421DBB654DAE9C35ULL, 0x889D74DE70D1C615ULL, 
            0xFFC398DC05CC4F52ULL, 0xED1F7032D355923DULL, 0xCC606D0AC2C76E4EULL, 0x9195A89A6200DD43ULL, 
            0xFF47787D08AF9EC9ULL, 0x607BACB5090AC464ULL, 0x7FF322CF0737FB6DULL, 0xB4C98AE43EC14F20ULL, 
            0xDD5643E0C8ACA47CULL, 0xF278A9B5BF31ABCDULL, 0xF8F4A5B36853550FULL, 0xC2DC84845D06CB8FULL, 
            0x68161C8E5A7D6ED3ULL, 0x689AEDD860D5D86AULL, 0xD7061948E1A9202AULL, 0xA31A17E3CEF07BD5ULL
        },
        {
            0x3AD0ACB4A3D7481BULL, 0xD644DA5D0D399AB2ULL, 0x9C95BE98E43B01E3ULL, 0xCDA267BB761C4D91ULL, 
            0x47A01C99F793D893ULL, 0x8EB5CD970ED4AE42ULL, 0xF8522EFB10DF4F97ULL, 0x4F23690E205EA95EULL, 
            0xC921A5266845ABADULL, 0xB474F70646FC26F0ULL, 0x3BBB43FDE4333307ULL, 0xC71EA2F94EC2C89BULL, 
            0xD9069E6180AC51A5ULL, 0x76B78680E46AC037ULL, 0xB8C967255767B00FULL, 0xDA40A575D3857334ULL, 
            0xA487B1301FF75461ULL, 0x0252905B2F7FAD21ULL, 0xD7809B7EF18F89DFULL, 0xCD240B79333D596DULL, 
            0xD0563E2DC12B7830ULL, 0x985E178DA6E351C1ULL, 0x789812D26DFB5A0BULL, 0x2C9F7A79138475F3ULL, 
            0xF26F95F70A601494ULL, 0x344E481F5C6135AFULL, 0xD93462AD3434C05BULL, 0x42322DAA62D6920BULL, 
            0x05F30C9D115FB659ULL, 0xF29FAE6733E0F3F4ULL, 0x3F12B8D9945721B9ULL, 0x41F41EE3B8C4785CULL
        },
        {
            0xADD5E183D1E1BCE1ULL, 0x0ED4D10E1D230BBEULL, 0xC1A1329BE9D02745ULL, 0x4BE92BA6D2F3EE71ULL, 
            0x121BA69C7A38BC6FULL, 0x340AF0C4E38360F8ULL, 0x486708F5CAA69FD0ULL, 0xCE3D6DCA7757DC48ULL, 
            0xE7ABA01A77806946ULL, 0xE7A3DC9ED8E428ADULL, 0xC163B731DB7EF3F0ULL, 0xC28AA228ED8FD572ULL, 
            0xC974F68156984116ULL, 0x68D2813E477B7C70ULL, 0x3A5ACB8B3EB8EFDAULL, 0x9B07E20CAE0CA32FULL, 
            0xAE3C69358A7689EFULL, 0xD93EF3C9EAF0D292ULL, 0x6F1FF459DC2AD9D2ULL, 0x4ADCA18DDB183E1AULL, 
            0x5BAC331CC8AF3A31ULL, 0xACA4DB14906BC056ULL, 0x7B82DDC49D9113C7ULL, 0xF44F1248B1A2E49FULL, 
            0xA55360333185515DULL, 0x449F9593E7F8270BULL, 0x5ADC551CF0F16CB9ULL, 0xF867D45E0069B562ULL, 
            0xD6B46F68CB90ED2FULL, 0x0E7A40CC12153B4CULL, 0x7444C33973AB7492ULL, 0x122A168B394EA9D7ULL
        },
        {
            0x9B48A5BBF4D0801AULL, 0x23B4208119056B8FULL, 0x300A2957F8D6AA34ULL, 0xEFABEBEC4EC7BF7AULL, 
            0x653E3BCF12D19206ULL, 0x49F95E42F9CBA5AFULL, 0xA1229ABF9F99075DULL, 0x567FD6710697D2E7ULL, 
            0x65E5474CC6D07B93ULL, 0xD53EE01B9C389B7CULL, 0x0FDAADF3B08C7081ULL, 0x20B0E6544A918752ULL, 
            0x8AB4B7188A6AF42AULL, 0x7496A6B8B2CACD2EULL, 0x0BA5891A4B12FC48ULL, 0x7132DC7F658AB18FULL, 
            0x4D4EF6DFA957C9CFULL, 0x7621DAFF89A743A6ULL, 0x4528BE2261D2D226ULL, 0xB282CC838D9879AFULL, 
            0x2DDFE45737D0A0EFULL, 0x4C35E8599098B829ULL, 0x52AED50AE795F378ULL, 0x7A03DE334BDE55AFULL, 
            0x54015B316E9D7DABULL, 0x37A26134C1463611ULL, 0x99E1BB965EDC0A15ULL, 0xE00797BE01AACB95ULL, 
            0x5607EAA9E49F0988ULL, 0xCAD9CE755BAB78C6ULL, 0x6620E6E54EE1DE5FULL, 0xD3675B1B6B3E8F06ULL
        },
        {
            0xC255C180F0A04DF4ULL, 0xE75FACF22B885E8AULL, 0x35D80E0F71FC9D31ULL, 0x4CDA9B440819ACADULL, 
            0x082368450F1FAE45ULL, 0xA2B399C5F7D43D11ULL, 0x9B9485E4187D6361ULL, 0xD61DADBA8BBA9B51ULL, 
            0x22C65A502980406CULL, 0xC080802A43DB29EAULL, 0x266699D9A8B950BEULL, 0x539A8B5F5EC2F800ULL, 
            0x773CEE9A857ECA49ULL, 0x32376B9F69D5C9C4ULL, 0x2DAA0E8CB8A6F6ABULL, 0x140ABBD20D2D4BFCULL, 
            0x64FD301C7B563DB9ULL, 0x6427EC3BC2549197ULL, 0x3F1CC7E377C44091ULL, 0x7B28D476CFEDEE31ULL, 
            0x9456E9002371557DULL, 0x514B4FD348E7AC5BULL, 0xA0D99A27914F5306ULL, 0x466E3383D6CDDFB6ULL, 
            0xFD30FB3BE382B988ULL, 0xC690B95C91B8ABCBULL, 0xAF7ADD9DAF8B4517ULL, 0xADF8EE9520DE30EBULL, 
            0x31D79F19C742E1B7ULL, 0xEEB40282617323B5ULL, 0x4EF33F0E5931EA59ULL, 0xB17F9FA1D5B131C9ULL
        },
        {
            0x1BE9838BB8993452ULL, 0x1C7F595F5B01C246ULL, 0xE90F2DE4EB5741D2ULL, 0xAC4D8A547764D2CDULL, 
            0x32D8CDABF84C9864ULL, 0xFD381244A5D90F4DULL, 0x18BB0EDD25E6C64DULL, 0xC029181488EA5F7AULL, 
            0xD18E0AD15D376C03ULL, 0x3C3D258D6FF2F514ULL, 0xA66DCFB12C415123ULL, 0xE2EB47659BE773B5ULL, 
            0xA9B70A1D4A93F58CULL, 0x1E7F5EFF32CF6B1CULL, 0x413DA9E23D7BD82DULL, 0xE3B48D33E292BF4AULL, 
            0xC9F6B647B52660D3ULL, 0x737C4F9173500502ULL, 0x98071B8CAAE74A5FULL, 0xED5F5A4E1F666286ULL, 
            0xCE7E658B528563C0ULL, 0x2089982118EDB0B1ULL, 0xC3C8BD309F239E53ULL, 0x7B94CDD8771CB8BCULL, 
            0x7AA43F703CE251CEULL, 0x0C7BB183E2D2707AULL, 0xF260DCE7EAB089D2ULL, 0xBAD9A2FB2DFC5503ULL, 
            0x05A93327F7D1D8C1ULL, 0xE5F883059F0D9C4AULL, 0xAE660D3336CB7693ULL, 0xE0AE645514BF8BB5ULL
        }
    },
    {
        {
            0x4D4AE97DD55621A4ULL, 0xF5098A538EB82600ULL, 0xC398175BDE6624ABULL, 0xE3E5D2A1F145482DULL, 
            0x801389C30354D564ULL, 0xEE372A46CE5819D3ULL, 0x7EB89E790F16B421ULL, 0xA3A81DFC1E377619ULL, 
            0x316A3CE85F618D92ULL, 0x9D3970161FD4C22DULL, 0x292EA062FAE96AAFULL, 0x24AD0BF88B37B6AFULL, 
            0x4DE7D7CA2920C7D9ULL, 0x33DF4875BF19BCC3ULL, 0x182A5D5C73969C95ULL, 0x592B0AAC1CD786F0ULL, 
            0x218A7BB77564C3A0ULL, 0x3DCCD0D3CBA92696ULL, 0xF29B412335DAEA27ULL, 0xDD968AE6981A16C7ULL, 
            0x404BECD4ED57C4A7ULL, 0x0ADAC4A8E784D8EAULL, 0x78731BA4D5B13ACEULL, 0x062494CD15E323FCULL, 
            0x8828CD72C918A78AULL, 0x5736743EC3F670A7ULL, 0x88A0FC0FE3014342ULL, 0x52EAA2B4B7417109ULL, 
            0xE8CF65152C7A4B06ULL, 0x48BAE11A3E5EBD22ULL, 0x9B7AB1E33436F90FULL, 0x647434B698D9AF19ULL
        },
        {
            0x1328DE1B98939BF0ULL, 0xB89545610A8D9E3BULL, 0xD778CD264B4E5C1AULL, 0xBE82FCF614412921ULL, 
            0xCE0D8DB695D6EA8FULL, 0x883C7A4C94BCC32BULL, 0x497D3DC84F396831ULL, 0xC8623B02BE778359ULL, 
            0xD0DFBDBDD69FB1EAULL, 0x65B9F3453052B3E5ULL, 0xB6787DB40B63D2C9ULL, 0xF8790312C3366DE4ULL, 
            0x1764164B67249BDFULL, 0x87BF2D3B6B601283ULL, 0xEC1C713A98EB8BA8ULL, 0x8B162FADDC41B32AULL, 
            0xAC976097D4A72807ULL, 0x228A40DCB37D7491ULL, 0xB495F4957D3B2281ULL, 0x857A9F5F462E0F5EULL, 
            0x9797CF4EA13D7F4BULL, 0xDB793885DE223A19ULL, 0x187FED0558DAFEC4ULL, 0xA9ECE3D46A635EEEULL, 
            0x3F3EF05CA169AF1EULL, 0x69A6A6DA35E3044EULL, 0x48C9B2753286F14DULL, 0xBC11BB29B9994CFEULL, 
            0x3262A8B644D319E6ULL, 0x48169B8B03565A75ULL, 0xE7BEEC8E28A17796ULL, 0x3A25222FC5A2EA4FULL
        },
        {
            0x53032EB814ECE894ULL, 0x3D28A19660AA7DC7ULL, 0xF39AF421C947F65EULL, 0xED33ABBD066699C3ULL, 
            0x5AE0037BFD02E2D9ULL, 0x1DD17DDEA3735D4EULL, 0xFE80B13EACF79BF0ULL, 0xFB2D7AE94E95574AULL, 
            0xA0F7EE29F4CAF99AULL, 0xD21B3D0CFC13E224ULL, 0xA9F697A035D4F71AULL, 0xDB1AE6CEF4AEA309ULL, 
            0x150835E46CFF1F5DULL, 0x851456B21B49B5F5ULL, 0x3C104C7118BF8FDEULL, 0x982F47CDD88AE558ULL, 
            0x61F1C275D8DE481DULL, 0x481CEA5053306FE4ULL, 0x36C558C20813DC63ULL, 0x26FBC276CA5E7E0AULL, 
            0xB75B5542EAE7B31DULL, 0xB1218A115C77B924ULL, 0x9C75354E490B0909ULL, 0x4F262E461271FE5EULL, 
            0x71BA9090493D1B32ULL, 0x0BE5FC875A85DF19ULL, 0x8F544A245F857F6EULL, 0x7444A9A66E2C3E42ULL, 
            0x25C6626FD9C14177ULL, 0xD62A70D6DAA4154BULL, 0xB8B41008F1A28751ULL, 0xFE5E60CAA6730A34ULL
        },
        {
            0x8DCDE4F3B5C590F0ULL, 0xF90D57F8F533F930ULL, 0x09856329C0773694ULL, 0xEBD14BF930BBC299ULL, 
            0xAC57FDB5293603CFULL, 0x9BABF6AF63A9F015ULL, 0x2394DFFF84BBDBA4ULL, 0xCC97988C860891A6ULL, 
            0x1DB66D9CA1837C60ULL, 0xEBAA2CB512DA4CE2ULL, 0xCE963F8E82F899D7ULL, 0x20CD86E12C972E17ULL, 
            0x8E9124FD88716F9FULL, 0x144D4BE5B8FDD10AULL, 0x6BBA88DF441074D9ULL, 0xB79F97E58005B526ULL, 
            0x4FD56A79738150B6ULL, 0x64D37DA18EB0ADE6ULL, 0x3DBE737ABA0ECA48ULL, 0x80EE53003CEC75B9ULL, 
            0x4BCBBA65445799C9ULL, 0x58CD0E70FBC957A8ULL, 0x064D9DCA78D029DAULL, 0x72C83966FFBE81BEULL, 
            0x3F79BCCDAB8CA201ULL, 0xF3A1ACDC2F7FF7C5ULL, 0x7677CC8F61EECC51ULL, 0x4F6FC0A752DE9BC1ULL, 
            0x4C11C710163EF118ULL, 0xE5B133F7EF86526DULL, 0xBCBE5DA1682DF32EULL, 0x755EC3B3CEE7996EULL
        },
        {
            0x46F26977F657E817ULL, 0x174C77072C4F32E9ULL, 0xD927BF8912B26E9CULL, 0xD5FF722FFCE1A547ULL, 
            0x00E0A1554A2D74ACULL, 0xA3C2FB58216C320CULL, 0x1CF9C473BB2BB3BAULL, 0x3846CD3D45F04A24ULL, 
            0x75EE74B233C8A746ULL, 0x62783C367F4A4B39ULL, 0xC5C4152A93DBF09CULL, 0x487EC3D0BA51F461ULL, 
            0xB566812D9AE22E7DULL, 0xCE9ED2570BBA411CULL, 0xF242393CE583A3ECULL, 0x80ABAE3AAB1DDAD2ULL, 
            0x52CE9D7FDE0DC410ULL, 0xF91E5EC7B5E84709ULL, 0xEF251113D6388AD8ULL, 0x3F82E956482F74A7ULL, 
            0x785110CD9BB3E8EBULL, 0xB4C25E44B061EAA7ULL, 0x64434C3FE44C0E5DULL, 0x5527309F99DA141AULL, 
            0xF9903A7474F86A39ULL, 0xBC233FE6182E439BULL, 0xEE7128C652096FECULL, 0x264170D3F073F8F7ULL, 
            0x8AC37D91862C1B65ULL, 0xC705CF8BF8AEAA41ULL, 0x6B283DA376E167B2ULL, 0x2289E6AD06C9E57FULL
        },
        {
            0xE4CF47D849EF3BD3ULL, 0x9856D14F05214ED1ULL, 0xCE78B08F9122C8ABULL, 0x2BE86D904A2202F6ULL, 
            0x8FFF4128178F008FULL, 0xE78CD501E65C7F9FULL, 0x5D9A92590C8F59E1ULL, 0xB14795024848C5FDULL, 
            0xCB76325B2EEA5AF3ULL, 0x48321D0D3D03CE7CULL, 0xA05961794D867CA6ULL, 0xDA0F1296089071BCULL, 
            0xCE0301FB3CB016EDULL, 0x1F3893DB875FC28BULL, 0x83D29413AA9C3D59ULL, 0x7FD2D690F9E56906ULL, 
            0x9C271327035ED538ULL, 0x3ADF0B99FF00013EULL, 0xFA3332551F28B9E7ULL, 0x7D2EE08B7D970D68ULL, 
            0x44E68C4338F436F0ULL, 0x475ACDCA1A27020EULL, 0x6D930A760A90F18EULL, 0x87D9E935450A812AULL, 
            0xD693A31A7949D44EULL, 0xC7AE47B3A9BB8B6AULL, 0xE44B6498B799E25EULL, 0xFEB013B1C94B91C6ULL, 
            0xA2540A6DF4057264ULL, 0xA75E9C7B579E2C9BULL, 0xEA833E4F8A839E36ULL, 0xF9D2E3F97A8A9288ULL
        }
    },
    {
        {
            0xF06C5FC3828B7023ULL, 0xB312B1B012F65B43ULL, 0x908FA70569501C27ULL, 0xAD563716CA160A7FULL, 
            0xCA68EFABBDF1DAF0ULL, 0x0C48888DF8CA5D40ULL, 0x217A181C9AC78A3FULL, 0xC3075985E0A88047ULL, 
            0x6463E119A705099CULL, 0x3D3C44C7E97066CEULL, 0xA1E7A8CD5A878E57ULL, 0xDB6BC5D66741B4AEULL, 
            0x52CE9CE4FA06F18FULL, 0xE70C4F2DC6CD44F1ULL, 0x0F0072A18817CD0CULL, 0x7C9EE81F2B62140EULL, 
            0x25EC70831307E19EULL, 0xFCBFF621DEF45865ULL, 0x81B7667F61388B77ULL, 0xE8D95EC0A33E4C93ULL, 
            0xCC6B89BB6C6290EAULL, 0xAB8451A35F8449F4ULL, 0x83BA55147CDE5E76ULL, 0xAD306BB29DD13F39ULL, 
            0x02A634B520B2D12DULL, 0x3FB89F35E7DE6BE9ULL, 0xA5EF50B27919FBEBULL, 0x47FF6CDF4A000F55ULL, 
            0xD97C524BC7A0EADEULL, 0xA9109B5AF7C60CB8ULL, 0xDC46A7AA4AC6B7CEULL, 0xA4164E266F49C85AULL
        },
        {
            0x2D25904B2AC244C9ULL, 0x6A9962B7911F5EFBULL, 0xE2464AF81DC41B70ULL, 0x085E11E60B209E9DULL, 
            0x554E75EA6D6D2DF8ULL, 0x8E52595E7CD30EA5ULL, 0x8CF143BA5239E25FULL, 0xA2788671430F6506ULL, 
            0x0D9D64AFCD5CB4F6ULL, 0xEC7A8D95BF6F420FULL, 0x3BF5E6E8BB433C26ULL, 0xF9E02588F202775CULL, 
            0x931467BB45BA2271ULL, 0x1FE740C9531FE382ULL, 0x33B2F54E06C1CE9DULL, 0x043D19BF18EDE827ULL, 
            0x3A276194F0C1312FULL, 0x11DF4C0256A45661ULL, 0xB047A12098FDF41FULL, 0xC4E2F05EEAC0127AULL, 
            0xBF4C30341858EC59ULL, 0x61C13AEEBCDE030BULL, 0x864EBB692828D0E5ULL, 0xDBEA6BB13D0C8EC2ULL, 
            0x4C04A77502AF6D08ULL, 0x34E5745133688BAEULL, 0x7050EDFE8D140FDEULL, 0x05DBE2693374FD38ULL, 
            0x8058E8C191A54469ULL, 0x907269AC9A7F16B5ULL, 0x797992D5A7F0DC2CULL, 0x86E6BAD5EE224695ULL
        },
        {
            0x02232E5EBA7374FDULL, 0x77D34EE7B3F48677ULL, 0x6C42CE8B51C3D95BULL, 0x77B73CAFFC69EC29ULL, 
            0x355BC1180E25B41EULL, 0xD7C44818FF87555CULL, 0xF8A88FE370770655ULL, 0x032BAF5762EBEF74ULL, 
            0xEC1BAA6624D1E456ULL, 0x961F8FA101C43B93ULL, 0xB4CE19F9B08C09DBULL, 0x23FB67511DD1D76CULL, 
            0x4F31C1486D795F84ULL, 0x7886B15D86A178A4ULL, 0x7EEBB2A612457100ULL, 0x04EA871D7F0B9451ULL, 
            0x8ABA70842836F9B9ULL, 0xBFAF236E6E233EEBULL, 0x9400D2FECDE3FA9EULL, 0x534A327563FF85E2ULL, 
            0x93465B3B28966D1AULL, 0x0015B325DECDCD29ULL, 0xFA265C2946C5FD65ULL, 0xB06C4C4FEF758F9DULL, 
            0xC01697FAD87631FFULL, 0x154E4326710AB911ULL, 0x14A1FE2F47FFD63FULL, 0x4E24878DFDB80833ULL, 
            0x16B4703C30956E27ULL, 0x5705966A41C5201FULL, 0x82852E7F3E074EA6ULL, 0x77D4BEFC7266000DULL
        },
        {
            0xF3195C9BA0319B2EULL, 0x71CB4EB481044386ULL, 0x7B6496C7C8CE0C4FULL, 0x75375CC6C66DECA5ULL, 
            0x54F83446867A706BULL, 0xA1F8DF0EBDE6E593ULL, 0x8F5D4E40F6307DA4ULL, 0xD665A65C1C6E448BULL, 
            0xA1AD41BFA9A914A4ULL, 0xD79830F442940786ULL, 0x2DD52520F707CEDDULL, 0x8D0BB5183790E1D8ULL, 
            0xFA5A2B940C097576ULL, 0xE4B82510D904D4B3ULL, 0xA78F047FC780DEE0ULL, 0xB127EFD2BEB5BB16ULL, 
            0x7A441319BA0A84CEULL, 0x7D7B9082B1521C2CULL, 0x290A2C290C5ACFB4ULL, 0x9FFBEBEF5519BE17ULL, 
            0xB940643EE1E2BB7AULL, 0x3815E4C3EC7FB9B4ULL, 0xE1FB204AC59DBC5FULL, 0x9AB3DEF394FAC68CULL, 
            0xAE248A6F2D5A7AEFULL, 0xF264D4D911FB9AB8ULL, 0x1C243ED8247D3300ULL, 0x8EC7E25A99A0D301ULL, 
            0x671F74ABC5924BA7ULL, 0xDE621D6F2F45F9ADULL, 0xE5AC43173FD6ED15ULL, 0x616B3655EA426FA9ULL
        },
        {
            0x91B5E85B9C1640ABULL, 0xEC05887E351DE3D5ULL, 0x27B362E8003B4D9AULL, 0x0CA3F4B3CD509795ULL, 
            0xB931548966EF1FDAULL, 0x99F506FC79A06A99ULL, 0xEDF7872B0DEEC451ULL, 0x9F93406ED4536A04ULL, 
            0x45585EC64DF65FDEULL, 0xAD0BB5184655773EULL, 0xB0A74C177242D8EEULL, 0x2EEAA038C1541664ULL, 
            0x07FC4353B8E1E148ULL, 0x66A4A02C97F117DEULL, 0x7AE3D1719CAB6793ULL, 0x8774F74EE7AB5870ULL, 
            0x89032E812D401E39ULL, 0x4C4DA2E91B042981ULL, 0x24D49FED9A5E0AC6ULL, 0x623B8C3C2705884DULL, 
            0x3AA7C6EA014FC768ULL, 0x2E0BBE501D428CECULL, 0x92B9067F7C52E4D8ULL, 0x6B9B72936838459EULL, 
            0x0BD5F035C31E772DULL, 0x451002C979FD7D47ULL, 0x534F8736EAB9146FULL, 0xA45E14D9C1A27013ULL, 
            0x661EBF9F93FEE231ULL, 0x41E26AC8F63D0DA4ULL, 0xD410AC4B95436A27ULL, 0x4C57CCE82F7C9951ULL
        },
        {
            0x92EA474FED4080B5ULL, 0x00050E7CD8EF4042ULL, 0x664A62D48F3CC253ULL, 0xAE834C8315B0097DULL, 
            0xB05A888D47E714EDULL, 0xED64A731D324C831ULL, 0x48BE95008FFA3741ULL, 0xE7AEBF23DF848ACAULL, 
            0x2B64D916161F38FBULL, 0x615EFB07A0027261ULL, 0x322861CA00106757ULL, 0x57EB5DCE1C43C2AFULL, 
            0xF63767B1D97AD0F8ULL, 0x87F8469973853280ULL, 0xF51F0E006BB6A60CULL, 0xE608A4DAAC963106ULL, 
            0x8A8A37EA90C63A67ULL, 0x983A93E32888E736ULL, 0x446C2994CD2DA4C7ULL, 0xAC060F0738AB810EULL, 
            0x366CE248A94BFCE7ULL, 0xF2E3D1DA150E0BA7ULL, 0x0475C4E278D418F5ULL, 0x103276F1539A7EF4ULL, 
            0x9FC2D1690BF88AB9ULL, 0xE5952BC64190FE90ULL, 0x420643311430ACD3ULL, 0xD320D7804EEC0E70ULL, 
            0xA05A133CA0668E01ULL, 0x9AB5C5C271FB194DULL, 0x2B8FEFABC7BBE0D1ULL, 0x168499FD8F73E04AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseBConstants = {
    0xB8E965407C34F974ULL,
    0xD3FA96A004296CD0ULL,
    0x61001E6FF5D31092ULL,
    0xB8E965407C34F974ULL,
    0xD3FA96A004296CD0ULL,
    0x61001E6FF5D31092ULL,
    0x595B97C81F03EF9EULL,
    0x25C03FCB8B664ECCULL,
    0x2E,
    0x59,
    0x6C,
    0x1C,
    0x05,
    0x57,
    0xCD,
    0x70
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseCSalts = {
    {
        {
            0xE3B3140924111CB7ULL, 0xFEF26AEDF7C22EFCULL, 0x91FA213562E54A57ULL, 0xF3E505E1F6CC0000ULL, 
            0x4DBC4D986F597662ULL, 0x61B79DFEC58F3A84ULL, 0xC1B89DE90AADFC49ULL, 0x0D1C9EA41338BC6FULL, 
            0x6F0F730CFE5ABC4BULL, 0xF04970037404AC8FULL, 0x16AEABE74C0E0619ULL, 0x11FAF69501387519ULL, 
            0xFC1FFAC7FB55A760ULL, 0x5838D444C54C1765ULL, 0xC233F40622B71FC9ULL, 0xDA924794999A067CULL, 
            0x70D6E9D6EF644023ULL, 0x74B062A83EF34FFFULL, 0x486B9A6739C09EE4ULL, 0xDFD520295F5FDF55ULL, 
            0xE52ACA17858860CAULL, 0x8F191F772F7BAB10ULL, 0x399C41B9024DB4B1ULL, 0x2D7D671E82FEE157ULL, 
            0x534B1B1E52B04E5AULL, 0xAFAB683B987294A7ULL, 0x3E27F4B16D426A00ULL, 0xF20A8E78234F47FBULL, 
            0x86C4A6E21081BBDEULL, 0xC1A5CE116DDD5026ULL, 0xD368383DE82B5F1CULL, 0xB08DA93012A0A459ULL
        },
        {
            0x7A544B92BEAF2AA0ULL, 0x018BA2B531688DD6ULL, 0x2C828D1223B74010ULL, 0x58454272F4A99B0DULL, 
            0xC966DBDF0D52D1CDULL, 0xFAFBF1463656D609ULL, 0x9A04F5C58FF4ED54ULL, 0x45F19870E7D0F64FULL, 
            0x5E78462E20EDB180ULL, 0x1FB79370278337D5ULL, 0xC11447983EE8DED9ULL, 0xA9E9BE5DCB8C0FE9ULL, 
            0xCE7D5FA108FE6B58ULL, 0xF7B6B283B3E5E695ULL, 0xC5A6A6DE636F2A92ULL, 0xE2BF61F1187037A2ULL, 
            0x62F97F91B3AB95FBULL, 0x0B0EBAB3D7391B9FULL, 0x023E2A81F66CC5DEULL, 0xFC4D54A023461A84ULL, 
            0x299DB9E46D5947D3ULL, 0x7B8B50D440891B88ULL, 0x8E5C23003049F68AULL, 0x4820B9523E52AC61ULL, 
            0x4BEEFD3A20DAC176ULL, 0x251AC7A42D71E973ULL, 0x9B8125BF7164DFEBULL, 0x0D7A79A15D0B0B5CULL, 
            0x2B25F91346F24B31ULL, 0x0DDB5EF54A900797ULL, 0x0827379B7A0699C7ULL, 0x07C5EEA0C2507405ULL
        },
        {
            0x061B58570B26F28CULL, 0xEDE55E16EF406B01ULL, 0xB417E06A061CB9A2ULL, 0x934BEFF5E5AD1C91ULL, 
            0xC5A472AB5B992914ULL, 0x73684D52BE819922ULL, 0xF878E7CDCF222691ULL, 0x7DA455B409F85FBEULL, 
            0x1958CDF17FC16C4DULL, 0x3BFA705408134F0FULL, 0x69E7C58BD6898733ULL, 0x29741E835ADFA945ULL, 
            0x838549775CCEFC9FULL, 0x57936BDAF3E48403ULL, 0x78ADA737BF1AB36EULL, 0xCD03EB521B21AC48ULL, 
            0xEB69C881A6E776D6ULL, 0x3FDCB6FDBF386D78ULL, 0xA2CFA1148AA37137ULL, 0xE0840E3B20FF7773ULL, 
            0x78B443990081C150ULL, 0x8839226C3AB1378CULL, 0x01C0E4FE28AB2371ULL, 0x850431BB50994FD2ULL, 
            0x106ECB85EC5190B7ULL, 0x31E1008D14FC2D2AULL, 0x17875F8CB1386C02ULL, 0xAE162996EA833958ULL, 
            0x9961F5213CEA2FF9ULL, 0x9B8F0ABD7E4CFEA1ULL, 0x6840F85C9C2D0F78ULL, 0x10D2C20F0F7CB375ULL
        },
        {
            0x69A50B55B7C11F54ULL, 0xD5641670A57ACF71ULL, 0x658F80374D457A0BULL, 0x2CEC5AE1BDA29B76ULL, 
            0x7F6A4302EE133A24ULL, 0x5CE4273ADA7351BEULL, 0x7C1110ACC89140F1ULL, 0x06C2E1A61D538298ULL, 
            0x1E0047A1AFB08D56ULL, 0x957535C08019D08AULL, 0x7558CF0B2A26490BULL, 0x713294FF87305F9FULL, 
            0x96F03A38A7271E92ULL, 0x40D0D1F1C7E1D0F0ULL, 0xC1E43F44A061CDC4ULL, 0x2443DA98454C24F4ULL, 
            0x787032F235297D20ULL, 0xD07DB41DF9CB880FULL, 0x35E499925CB86034ULL, 0x35113F59EA4BBD0DULL, 
            0xEE28EA3C0F4A295FULL, 0x258C80975244405FULL, 0xD8037EA58BED6DA2ULL, 0x9C55DD8EB76C1828ULL, 
            0x207D612DD04D6439ULL, 0xE63A87EDF2946E8EULL, 0x531B3AF2E02266E0ULL, 0x62BBA7E368201624ULL, 
            0xA3819CF3C841DDD2ULL, 0x0FF63E8854EB3D36ULL, 0xBE277E7547276FCCULL, 0x90877FB72D6645ACULL
        },
        {
            0x4138198490C9DF9CULL, 0x69148E229E247CA4ULL, 0xD056B13105C64E05ULL, 0x53470A689793103EULL, 
            0x5F6FC4B5BEC72BCCULL, 0xD549E289A7552DBFULL, 0x4CCE107F62EC0076ULL, 0xA90EF6F4C10B62D2ULL, 
            0x7C3672FEBCCA48DFULL, 0x1D34BC8B4CF71868ULL, 0xB8751598F728B95BULL, 0x0017177CA054F690ULL, 
            0x4FF4965AF121BB6FULL, 0xBEC58F55F07EBC23ULL, 0x367B3D66A2ED8A5BULL, 0x892410DBADAD2C15ULL, 
            0x50FB76D5C0DD51EFULL, 0x8B49AD50B4356210ULL, 0xFDFECBC13C982CEDULL, 0xE9B7DA1C9C4399A8ULL, 
            0xC3C8112CAEDC3E26ULL, 0x950561502EBC555AULL, 0x6DFEBFC77A4EE8DAULL, 0xFC51139BFE5C6E77ULL, 
            0x019B811815741306ULL, 0x6665F0DAE5CB4EF9ULL, 0x67F006CB3292B3A8ULL, 0xD93FA53D1E007B76ULL, 
            0x2895EFB6D0F94DB8ULL, 0x14A66B390A6B8116ULL, 0xCB92C1DA27E8BC3FULL, 0x4B627FCFCC01FBA4ULL
        },
        {
            0x841C4E2576892D48ULL, 0x2C9564ABF975606BULL, 0xB0ECC331B45187B9ULL, 0xEBA7957E0B0A12A7ULL, 
            0x67654628C89C33A3ULL, 0xC08300745109874BULL, 0xB554D545846C1971ULL, 0x6D55DB6A817EACF3ULL, 
            0x14E7126507A16B8BULL, 0x24630EC79DF77614ULL, 0x58001D6A621D9413ULL, 0xB230B298DD994079ULL, 
            0x2C1428821FB6EBC7ULL, 0xB15B62C5D4EDF733ULL, 0x08F23AFD6BA4DCB5ULL, 0x4A248756E59A61E8ULL, 
            0x6EA2E4B76EB245D4ULL, 0x4D83B94473F6E4D0ULL, 0x06855161BB3528CCULL, 0x7B588668BE32C331ULL, 
            0x2151D5E8B454193DULL, 0xB47091F104996AD8ULL, 0x5C861D03624ADC04ULL, 0x4E4699962E707D32ULL, 
            0x32761F5DA5E889EEULL, 0xF94B3EE31D2EA7B2ULL, 0xDD1405D5A1805970ULL, 0x9B468D2BC734E202ULL, 
            0x436EC37A2D018076ULL, 0x82AD5EC88F447D7AULL, 0x9282B13F7BAF8725ULL, 0x5873A8B6E85020FEULL
        }
    },
    {
        {
            0xE2E7805F80480D33ULL, 0x215FB50FD59AC0FFULL, 0x4AC6B10AFC58FFE8ULL, 0xB1C4049BF38EB50DULL, 
            0xBD5EFFCAF4B5E9FBULL, 0x40FC1A63C02DE263ULL, 0xE4EE812B651068EDULL, 0x35B3D19EE788A0FEULL, 
            0xD26AA46E0C164DF5ULL, 0x84D238E083DB072AULL, 0x5B4F8A2AEEACC9C4ULL, 0xC47910DA724A4058ULL, 
            0xA0DCE1CC01932810ULL, 0x2B33D90D88A5FFE0ULL, 0xBD10573D5CF7434BULL, 0xED940F94CAB3B507ULL, 
            0xCDD7FEA2D25D66C2ULL, 0xE4178094FC28BAADULL, 0x4827DD9568B8EC19ULL, 0x165C7509E6CC2059ULL, 
            0xE3C7889E2078C6C0ULL, 0xB1335B2D69C74F06ULL, 0xB1926C9E9289A294ULL, 0x576C290AF7B353AEULL, 
            0x916D4D1933AA336FULL, 0x9010D70622EF4DDDULL, 0x776ACACBC31E7E42ULL, 0xF296B4C21CCA5938ULL, 
            0x8B5BEAA52965A927ULL, 0x23865AA20725663EULL, 0x2588AA3FD788CCF1ULL, 0xA0E41A1F65B657D6ULL
        },
        {
            0xAF4BB752A3C67614ULL, 0x4F8E4FCF24DF1FCAULL, 0x5D950C5055A8C678ULL, 0x1FA70647B331D4D7ULL, 
            0x8F7674B87162E116ULL, 0x93D4FA17ECCA0FB7ULL, 0x683C70B1FCDDB275ULL, 0x8437DAB70C5744B2ULL, 
            0xAD10A6DAF53CA771ULL, 0x5DB4AC7E76B6199DULL, 0xAED91D8DD6856876ULL, 0x2AAF0ACC01F538FFULL, 
            0x6307DD14F5F8BD90ULL, 0x0C1B93DF4C5B65EAULL, 0xFA754C235C4A990CULL, 0x537ABCEA9FC74346ULL, 
            0x353493B269CF718CULL, 0x53F03818ABD60101ULL, 0x7D4E52F2CC3404A8ULL, 0x6D52CA131D7FAFA6ULL, 
            0x9022DA9ED90A35A6ULL, 0x54400B275C9823D8ULL, 0x4278541D67C85104ULL, 0xE509147275E86ABEULL, 
            0xB36F7ECAB9AC9881ULL, 0x4225311D75CC99F5ULL, 0x75EE5EABBD2ECDF9ULL, 0x0EF8571F56E42BD2ULL, 
            0xCF6A6F66056BA82FULL, 0xA01DEAB77A49FBA1ULL, 0x80E841893AECBAA1ULL, 0x05D8CEC52BC25D6FULL
        },
        {
            0xD6248090E208B625ULL, 0x5BE90DD3AF5E7DADULL, 0xBCD2E0D4635EDA76ULL, 0x0F4FFDE85A4387BCULL, 
            0x1F78F0C377B084A8ULL, 0x29EFD6BEDE28FFD6ULL, 0xE4418D3069A1F3CCULL, 0x88C99BFB23E92BE6ULL, 
            0x3300F85D59210F4DULL, 0x80BA249464C09D75ULL, 0x9F6FF231087E70FFULL, 0xDBFF42B67AE89F74ULL, 
            0xC63F0AF113A6B5E8ULL, 0xEF201F7B8A759EF3ULL, 0x76371700DCCA1485ULL, 0x9B855E6B0A839F6FULL, 
            0x6C7C7BAF4FBD0059ULL, 0xF97C422ED232ED88ULL, 0x10DB104096C4A206ULL, 0xBA46CE2765D6E98CULL, 
            0x21FA90D74F0AA26EULL, 0x3A34FC787D19A91CULL, 0x905A70A455B38D6DULL, 0xE57777C3C2D147E9ULL, 
            0xB89C742A03D0F59AULL, 0x71D49AF604D0945AULL, 0xCC47388F1EB47EEFULL, 0xF64853D93390172FULL, 
            0xDACAD21333204E73ULL, 0x24A98C773AA3AEC7ULL, 0xB8D09A48E5225D50ULL, 0xB1FF5B4F1DD0DF20ULL
        },
        {
            0xB88D88E13B55E5DBULL, 0xF9ED9A01667E1E57ULL, 0x2C7C9A8AFEB58FFAULL, 0x769E7F22D3A30499ULL, 
            0x9A440FF5911F9607ULL, 0x866041ED3467FC66ULL, 0xE3523AC57522F483ULL, 0x3EC6F0A59B1DBEA0ULL, 
            0x6BC0D68483032045ULL, 0x9F6284ECA722CA82ULL, 0xD988AA8A3C42BA58ULL, 0xC55BB171AE1C2883ULL, 
            0x755617F260058001ULL, 0x4FDA7750F807360CULL, 0xF0DC54C761FC0F62ULL, 0xC19B75C73A9A381DULL, 
            0x9A6AB952F456522DULL, 0xAABD003D1B45857EULL, 0x64BBFB44DCA57075ULL, 0x3AA4124CE471AC27ULL, 
            0x796EB1DC2F03CC38ULL, 0xDD834C0E915FFFD2ULL, 0x914F636C967202BBULL, 0x1D0C620BB45B5B49ULL, 
            0xDD0109C558AC5144ULL, 0xFAF4D2EC69AE7232ULL, 0x94C511EEBD43C2C7ULL, 0xE0B56E5377B6E3C8ULL, 
            0x89424E23FCF01E38ULL, 0xBD627E4FA3208091ULL, 0x16F0DAF2D59314C4ULL, 0xF99D7E60AB8C4224ULL
        },
        {
            0x503622BD82A45955ULL, 0xF2EB5304D269F8A6ULL, 0x1A57726218124A25ULL, 0x4741887A6DD05C8CULL, 
            0x85D559986590CDAEULL, 0x5D68B7B36D7729C3ULL, 0xC022B1BB7B3F7903ULL, 0xAF7F4E3FA801E949ULL, 
            0xEF13CF2AA1FBD0F8ULL, 0xCBB909A8E07A8E44ULL, 0x43D804A723400815ULL, 0x2FD9588114C9AE2EULL, 
            0x1DB9D46892ECE7DDULL, 0xA726AB0FFAB049D0ULL, 0xECCB0F4002E62BF3ULL, 0x4D0ACCCF3084F70BULL, 
            0x9E50835806E3C29AULL, 0x494598ED00A43601ULL, 0x7BF9176CE9A16D9FULL, 0xCA02E3BD0D135B72ULL, 
            0xDD40AA86D4D3C242ULL, 0xE8A045C2DEF3FCD9ULL, 0x54916B5BDD35B497ULL, 0x672198968C48AB49ULL, 
            0xFC62D21F4CB0BCE2ULL, 0xDBFA65129A7DAD95ULL, 0x2C2D352A79177C81ULL, 0x82C7A28005583CAEULL, 
            0x88199865E1C71162ULL, 0x3BAFAEDBDFF58F86ULL, 0x00A9EFE0717FB986ULL, 0xABC771FD2B66FFBEULL
        },
        {
            0x2A014BB017BCA64BULL, 0x1D7C71BE939DBC76ULL, 0x25C25BA00A4F3965ULL, 0x78E232C81FFF354EULL, 
            0xEFF80BBA6B600157ULL, 0xCA9471DEFACC474DULL, 0x1F3553F67A773E03ULL, 0x4626989E6F944125ULL, 
            0xA19D904ED744DA5EULL, 0x0AB5EBE3B4A5506EULL, 0xF42EB7CD7A2CCBA3ULL, 0x15A4149EAC379212ULL, 
            0x87CF3DA7B9DCDE1DULL, 0x422859AC0E3F183EULL, 0xEEEC402BED852874ULL, 0xD406D58AEF274056ULL, 
            0x95166D39173C95ABULL, 0x818BD3CA30C985E5ULL, 0x644FC254C3D55CDFULL, 0x6AFDCF29F8DCFAC6ULL, 
            0xD55F800E389B0F89ULL, 0xE5DA24932B1B4D2EULL, 0x0A939FE8E17ABE26ULL, 0x9D4FB9601666D525ULL, 
            0x11B7C81CE275EC44ULL, 0x6F1BA703E6549813ULL, 0x0C81EF718451EF83ULL, 0x8AC4AB16FB605A5CULL, 
            0xE3A602C1ECA158E0ULL, 0x29C434636F5E92CDULL, 0xFFF6E8C187EC3408ULL, 0x2548050EA6D4EB02ULL
        }
    },
    {
        {
            0x529D54D7A3EE49FFULL, 0x57B6599D9374B387ULL, 0xF652FAC535D03479ULL, 0xD535B17465FB5B7FULL, 
            0x7F2FF7AC5C01245AULL, 0xDFC3896EBA33775BULL, 0x5C7F4904E47EFFD8ULL, 0x247A9848D5C5C66FULL, 
            0xA48F8C19C60F6E23ULL, 0x03BD8CAB74D3B87CULL, 0xA223E9DAFBD1EAF3ULL, 0x2F2023654C892404ULL, 
            0x1EFB016F295373FFULL, 0x704C02AEB64CA24FULL, 0xC4A8EA5F0484D4E1ULL, 0xEB19F6DDD3E289D4ULL, 
            0xD080E77F9D60D057ULL, 0x9FDE80DF14A785ADULL, 0x79A9FDDD5634F6AAULL, 0x0B89C3A44F53BDBFULL, 
            0x1EEC457A9A6C4711ULL, 0x3E5A76D5C361DB95ULL, 0x9DA4B6766D816E9AULL, 0x75A9349DC0BE4CB9ULL, 
            0x9D97B4EB4F361153ULL, 0x259FE6F5784864C1ULL, 0x6E0456400F9ED737ULL, 0x24BF4D1DE944503DULL, 
            0x0FC46B41674DB2BCULL, 0x985BF3A403E5024EULL, 0xEF231DA35D4B77B2ULL, 0x6BECCDE550BFAA31ULL
        },
        {
            0x692D48CD3AD96003ULL, 0x830D1EA857058729ULL, 0xD102637F37689F36ULL, 0xB429417BBDB93D44ULL, 
            0x18F08F7CBE67AF9EULL, 0x80B815FDFABD553CULL, 0x3A4C2A10FBCD0BB0ULL, 0xD5A5317E1FA8C544ULL, 
            0xF463FF32E9E11A0CULL, 0x308952B77162A022ULL, 0xB424DE0734CA8FBFULL, 0x8EE154F45A3896FDULL, 
            0xE4FC98F5C8155C0FULL, 0x31F20A2DADC805ACULL, 0xBD60E3D4E693F0E3ULL, 0xE23AE372C6684C1AULL, 
            0x632B2A24633388B2ULL, 0xBCCB4727390F0E6AULL, 0x65405DDFC41F2A9CULL, 0x44DCF641F8C119C2ULL, 
            0xA97BC75E2BBDA83BULL, 0x1F3ACE361182E890ULL, 0xC28C1DFEF2B3FED4ULL, 0xD91D49F38F007867ULL, 
            0x61F33377B358F7A5ULL, 0xEABD4CA674E21E43ULL, 0xFD6A4820609BCCF5ULL, 0x60B7F1FE9CF991A1ULL, 
            0xA231210B9D25EE55ULL, 0x12F3455C9325B7BEULL, 0x5903CFFB55DEA9BBULL, 0x95B7241139BED683ULL
        },
        {
            0x9624CB7EA27C1FA8ULL, 0x9D3360D5754F3804ULL, 0xED453FD1BC40B7F8ULL, 0x5B35FE4893934679ULL, 
            0x52B4684323F410F2ULL, 0xDDD2779E18118882ULL, 0x31A5998187E66D23ULL, 0x02E786A59727AF21ULL, 
            0xC13A937C22AC76F0ULL, 0x3BDD4D06AB8093CFULL, 0xA74F2E5924D2A5FFULL, 0xF36621E629268F2FULL, 
            0xD285436FA7CC0C38ULL, 0x56A24B614653CADBULL, 0x46B15BD9934A4B1FULL, 0xCEF33E20179F15CBULL, 
            0x345B4AFC3010FD33ULL, 0xE3D8948E2CB99379ULL, 0x25F2FDB22E5189F0ULL, 0x0824CD334FADC1A6ULL, 
            0xD919BA0E213353B2ULL, 0xF3F132235FD4FE3FULL, 0x31383824C79D3A55ULL, 0x00F864B1459C2EE8ULL, 
            0x4DA57C45CAC0E533ULL, 0xF7A26842DA9AE51FULL, 0xA33B08B80A8048FBULL, 0x920155D44D30DD4DULL, 
            0xF91D6581EC734802ULL, 0x28441AF85E8DDE0CULL, 0xE4B4AA554BDF0E65ULL, 0x9FDE172B360F62B3ULL
        },
        {
            0x0552E4DCCFDF1842ULL, 0x4A64BF3209EBF628ULL, 0xBFA9313ED792FF1DULL, 0x1A5A0039EEC23EBCULL, 
            0x6D68C4966657BE70ULL, 0x1C7E535AD6040192ULL, 0xCEFAE382F8B55D14ULL, 0x45182A125A1B313FULL, 
            0xF90399CEEDC91ABEULL, 0x1D228225EB93EA65ULL, 0x4614FA491B719D78ULL, 0xEAD3537AC60E6CD7ULL, 
            0x56296A3BF86FB4A7ULL, 0x01379898DCBF8EF9ULL, 0xCEB550AA1311CD67ULL, 0x9003E1ADFCC7F90EULL, 
            0x3FED59E0D1B6D2DFULL, 0x68493C746849B36FULL, 0x3F50D13A20DED48BULL, 0xF6BF6A26B56EC9EAULL, 
            0x45CA75CDC88F1FAEULL, 0x9E4882B98D5A1814ULL, 0xC7C2CAFD2728BA34ULL, 0x2A84AE7276B4B886ULL, 
            0xD193821CD9C4CB81ULL, 0x27321381637DDFEFULL, 0xD632E64CA0AD85A5ULL, 0x31F8145345124192ULL, 
            0xFB86A321A5987E70ULL, 0x26A772DB184CBB1FULL, 0x2E4B157C12A5E90EULL, 0xF854BA70B3D2C3F3ULL
        },
        {
            0x7DFDECE9F2752123ULL, 0xC942FF4674AA3BB8ULL, 0xA3A77D64A2C93DD8ULL, 0x2228E4A111026DF7ULL, 
            0x3C44AE7BE9A64FF3ULL, 0xA2A337E102B74E01ULL, 0x7BFBD1E636ADF085ULL, 0x33368FE2B5F79CEAULL, 
            0xF3CB95304B1E1C30ULL, 0x22E2D0476BD9D8C9ULL, 0x5DA9061843CC7FD9ULL, 0x5FC87272C0EEA411ULL, 
            0x466C80AA02CFD6C6ULL, 0x125F2EE5B298F812ULL, 0xCE371CF471423FA6ULL, 0x420BFCF053BBC8BAULL, 
            0xBDFF21E4E6BA21ADULL, 0xFC1F7885F94070F2ULL, 0x45B99F4EE1E9E306ULL, 0xD111B9E3EC225E14ULL, 
            0x1A72B28688B14FE0ULL, 0x6A53F19BC5E16DC4ULL, 0x64342F6F23B9CB5BULL, 0x96B99B4459FA8D24ULL, 
            0xCD28B3A967699F92ULL, 0x0A2D5939EC809A76ULL, 0xB5261EB149F80ADDULL, 0xA98CB3CCF3AFBC3AULL, 
            0xDFD61D9149ED70C5ULL, 0x0C7030B27E971508ULL, 0xE98D7730DB92FEBDULL, 0xDEB8D5C7B6A90DCCULL
        },
        {
            0xAB2DBB414138B7F1ULL, 0x3A7D6DB8648C64C1ULL, 0x531D9D1F47F46588ULL, 0x596171AE27A93EA1ULL, 
            0xD5383E35341E7527ULL, 0x90443143855D39C2ULL, 0xE4E4A1F0FC0D6B4CULL, 0xE897241351344B60ULL, 
            0xEA3C6702B4CB1A2FULL, 0x35FB053F901C5068ULL, 0xB62C33FDF233C56AULL, 0xB7FD761786E14670ULL, 
            0x6B521B31225F1FF9ULL, 0xC169D0497F055FCAULL, 0xE8ADDFA7A7B64E72ULL, 0xCB56D1353E069387ULL, 
            0x3A877F7BEA02C6B2ULL, 0x4D149B52B2469D2CULL, 0xD0CFEAB3619D3740ULL, 0xA1C777078C3DDE4AULL, 
            0xD7E720CB0B92DB6DULL, 0x8B24222B4CF05494ULL, 0x24BFCE64D71CD24DULL, 0x26EE1A1FFA160922ULL, 
            0x570B8FCAA8DB709EULL, 0x34E9EA8275AC606AULL, 0x7AA8140D917C704BULL, 0x3AE125368B57E97FULL, 
            0x2BAAF251CBC83181ULL, 0x81D2630467A0A375ULL, 0x5C0FC1DBC3A47414ULL, 0x00C80F9EC6F61C39ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseCConstants = {
    0x3E389A18E12C3CFDULL,
    0x275518C3DFEC2CBFULL,
    0x86F206D1050BAD18ULL,
    0x3E389A18E12C3CFDULL,
    0x275518C3DFEC2CBFULL,
    0x86F206D1050BAD18ULL,
    0x2EC01B7CEB3A27B4ULL,
    0x01EDEED0D4217A54ULL,
    0x62,
    0x71,
    0x20,
    0xE6,
    0x84,
    0x5B,
    0x9A,
    0x3F
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseDSalts = {
    {
        {
            0x5C5A46E8AB4D000BULL, 0x83EAD6BE3F88BB62ULL, 0x98806317F700D5FDULL, 0xA907D53534290B98ULL, 
            0x475B1E9931BC49B6ULL, 0x2867BA38B4292E5AULL, 0x79255CDE273116CFULL, 0x844481536DAE289BULL, 
            0xA42C2AE5320A80CCULL, 0x5F1D7E7F8B4B14E8ULL, 0xDB696044A363E42FULL, 0xD6081C1EA3190FEBULL, 
            0x4533F6CC91CD5C25ULL, 0x01BE736586A497F2ULL, 0x7B4DA22878B12FD7ULL, 0x1DCF0F67A0740D90ULL, 
            0xD2B9FAA530AA2CC6ULL, 0x740F798274635F7EULL, 0xA4AAB45C79338D0AULL, 0xAB4F3974C8FC17B9ULL, 
            0x99A3AB93D0C461FEULL, 0x5AB864BF69C2F94FULL, 0xBC8790DFF4BE7B15ULL, 0x3E1185F36CA770D3ULL, 
            0x4E0FB26ED14AA7C4ULL, 0xA9414D4C668B0028ULL, 0x764EFFE9FFE8A789ULL, 0xEDE795829250ED48ULL, 
            0xC2CC221FF42D13A1ULL, 0x4EEE8BDD1BCE4674ULL, 0xF147D41147C0103DULL, 0xCB14759DE6E99B94ULL
        },
        {
            0xB4DFE96CC4F4FC7AULL, 0x70325097A3D91D40ULL, 0x16870FC83BEF18CDULL, 0x0052387D7DBF57D9ULL, 
            0x3A799936575418C9ULL, 0x0958BAD9C2ED53E9ULL, 0x403E7B2E7E82213EULL, 0xF45C8EA62452CD17ULL, 
            0xDAC2B70B66B9771CULL, 0x670A1DDDE73E1927ULL, 0x356EB5F85D10A0C9ULL, 0xB28884701F7139F6ULL, 
            0x8F0E4D32DADD7DCEULL, 0x013036565F8B330CULL, 0x57D0B193DFA0FDCDULL, 0x075F3D69F50FB7BBULL, 
            0x8272E56D68D63CA0ULL, 0x8F84BE291B993EA3ULL, 0x7E48E90A20EFBA8BULL, 0x4AED8C925488FA4AULL, 
            0x95B070B9BF01CC28ULL, 0xF761BB10D0C8B503ULL, 0xA213C519B13B2BFEULL, 0x1FAFDBE4520F2098ULL, 
            0x7BD99E3546C049A1ULL, 0x05C297EB20965F50ULL, 0x59307EB9776D66A7ULL, 0x87C24A5103CDCEA8ULL, 
            0x46F11AC0BFFABD40ULL, 0xDD982411F5F1D417ULL, 0x1A2E393A1F7DD605ULL, 0xFD10DD3165736103ULL
        },
        {
            0xCBBF6AFCF2021BE1ULL, 0xDF18B7C5376C7DC6ULL, 0x51C94F82F8E64A1AULL, 0xFF8B145C5934B4C5ULL, 
            0xF8BED08D0CE3C8A6ULL, 0x506A5D37DF37281BULL, 0x4B7097F57E0E6DC7ULL, 0x3F269CA42FE4E63DULL, 
            0x4E97B6028BF66E5BULL, 0x8F28839421BE2712ULL, 0x65CFA18B9723CE42ULL, 0x4B1E49B8E6DBC0CAULL, 
            0xA9FD6B3D3EF319E9ULL, 0x33D512A0707B3A4DULL, 0x62DFCD67393D9325ULL, 0x0B9E06BD0E0F4443ULL, 
            0x8CEA227F622BFCA2ULL, 0x73453C4053918E93ULL, 0x31CE843B616E2400ULL, 0xFA7158665EFED2E1ULL, 
            0x0EB7742942D35CE6ULL, 0x0802A904AB0BF60FULL, 0xB1D84666388C0DE3ULL, 0xE5EC6D7A071E34E4ULL, 
            0xF475167C7465650EULL, 0xB8945170477F3331ULL, 0xCBA91D7289046FADULL, 0x53BA1D2838CCE7B2ULL, 
            0xE7F630422E414DCAULL, 0x1BF497B039E9FFE7ULL, 0xAFCD88DF29BA1299ULL, 0xF2E515BA344AC54DULL
        },
        {
            0x3379DA1EBC1BC067ULL, 0x9574A655BB64C43BULL, 0x0050F6D16E9733C5ULL, 0xE9EAC4C4B2495CBEULL, 
            0xE76B857FB6570E8AULL, 0x4E31D9B487528648ULL, 0x12B7E67114239EECULL, 0x11D937FFB5AA7269ULL, 
            0x8782CEE1DD08E6AFULL, 0x023984B822FAC0E4ULL, 0xCB3F634B6C37DD17ULL, 0x7ED49A0339A89687ULL, 
            0xB13C6945D664BC57ULL, 0x1C40DDE861C5530AULL, 0x685ADDCFB6A4F095ULL, 0x65A37BF5B526A895ULL, 
            0x93C3240CF38D1F7CULL, 0x058D0592EDFAE408ULL, 0x5009402BACDFF071ULL, 0xA1F72DE6802E12C3ULL, 
            0x7F9DCA9D125FF89FULL, 0x932DF473C685AB49ULL, 0x7E5B89447C69DD64ULL, 0x07E4E57A36FAFE47ULL, 
            0x1B4848B294280315ULL, 0x8FF5C6EA9AB3CD32ULL, 0xF3E54CFA8FD8D6D5ULL, 0xB18EC9570C858D05ULL, 
            0x4125461A1FD8AE02ULL, 0x8535067D161C9DF4ULL, 0x9E10F5F4E51DFB73ULL, 0x49BF723BF2C387FBULL
        },
        {
            0x14EB9ADECB6CE8B7ULL, 0xC2CFDDD4F33E0541ULL, 0x2651B91C0CE54FB1ULL, 0x4B3282DC5E647D59ULL, 
            0x06A8AF3C543322FCULL, 0x42CD5788A26A52CEULL, 0x35EDF7BFC5BAC032ULL, 0xB910DA1F75EE1390ULL, 
            0x1B495E44D18AB89FULL, 0xF78B23D1F0B8197EULL, 0x6433207BBF9236ABULL, 0xA31C42549DAA0195ULL, 
            0xD3B0F575098CD261ULL, 0x8816A894FB5A2E5DULL, 0x9B800D1B69FCABCDULL, 0x9568556286041AA4ULL, 
            0x9F433889AC924C56ULL, 0xDBF20186647640CCULL, 0xC78AE517930FDD5FULL, 0xFFCDA7D2737FE6EFULL, 
            0x51DA86F4D69B6849ULL, 0x5DF2B5AF88D5026BULL, 0x24608531558F8764ULL, 0xFA6027F663252ED9ULL, 
            0xFA3267ABAB3F6D14ULL, 0x33F23F8F169F46F6ULL, 0xB900DF72DACF84E4ULL, 0x8AF56BAAA7AF290FULL, 
            0x66BA833DA3569665ULL, 0xFBFA798978FBD070ULL, 0x293593FED40D43B9ULL, 0x80540855A06F078DULL
        },
        {
            0x51209FEFE05A2FDEULL, 0x8D14367320ED1F5EULL, 0x14896B2A2F406F2CULL, 0x1CE95088FA6CD8FCULL, 
            0x93F42132663768E4ULL, 0x8ECEC59F65778D94ULL, 0xC477800775F31661ULL, 0x8BC331CFA76C980FULL, 
            0x5737DF6AC486062AULL, 0x8C1B03569DC06C29ULL, 0xE6C26B0C561DE5BCULL, 0xBA6BAEDBA7BB1715ULL, 
            0x8927BB966877CD41ULL, 0x3A0B37DA97E87FEDULL, 0xCED9F898DF8D4E97ULL, 0xA1FECAC0FEFB7065ULL, 
            0xA1BC5D26F0A53A3AULL, 0x5A5DD5B58DBF9444ULL, 0xB2CDDE5D4E30C8A8ULL, 0xB1F3A2F60DD12041ULL, 
            0xB7C7A5705F211599ULL, 0x33500929EE258890ULL, 0xC74C8A665EF3A222ULL, 0xD275AC06424B8DF4ULL, 
            0x7CE99AA43C38CA40ULL, 0x94BB033552A9528CULL, 0x1C42AE2F61441541ULL, 0x46EC967092F18E30ULL, 
            0xBA9F7A374310B990ULL, 0x4302D4F5CCF13539ULL, 0x5A9C3B948BC84311ULL, 0xAEF9D8FBD6106B1BULL
        }
    },
    {
        {
            0x9AD939B371EB5EAAULL, 0x4DC078F0C100675FULL, 0x9405D91F78BAFCC7ULL, 0x049B5D16D18E7234ULL, 
            0x833642B41F596032ULL, 0x0984C7BF203CEFC8ULL, 0x5ED6E29950C2E92AULL, 0xE05BE6C89AB91629ULL, 
            0x7873FDFBC7368360ULL, 0x3953E1A451446940ULL, 0xF1E3CE0701AD20BBULL, 0x2875074A282A5C77ULL, 
            0x6F76A60FC8ACAF7CULL, 0x1F44E7446EA2E6F6ULL, 0x3D0386AAA46BABE6ULL, 0xA8D23CB6C0A3FB07ULL, 
            0x408DC121D029A3F0ULL, 0xAD83438AE1730429ULL, 0x82C49F987FE60497ULL, 0x0D837B4C0FA1F27EULL, 
            0x3A39BAC0F252AC07ULL, 0x0E8EC2EE86E15D7FULL, 0xB8FF0FCD0979D1C8ULL, 0x563016C5A77E73ECULL, 
            0xF671A7EBF8E6103CULL, 0x09EF91DC9EF87F1FULL, 0xF5782FBCB6B50953ULL, 0xE0D964A3FF426251ULL, 
            0x989E7D002985E2A1ULL, 0x4EBA2F3E350C23BFULL, 0x4A49616CE9ACA9DBULL, 0x2B04F49A33115281ULL
        },
        {
            0xB013D38FE59D05D8ULL, 0x87CB4CA85C9E461AULL, 0xEB617FDD23C0A51DULL, 0xA9960D50630861FBULL, 
            0xE9F8C8168A8645A6ULL, 0xA68C7EF18C7EA773ULL, 0xEDE02711B88A69DDULL, 0x6175485F1DA59A6CULL, 
            0xFDD709A3ADD0B791ULL, 0xF92CCBA48C26B0BDULL, 0xB1A6A8E271B44254ULL, 0x5F4952A1247A83B0ULL, 
            0xBAEEA1FBE3292B63ULL, 0x605157ADB1E924F9ULL, 0xE99AFD343E62D2CFULL, 0x7275410ED055B018ULL, 
            0xF6A932D2E680A6B6ULL, 0x518E901448DC2662ULL, 0x574E70C4C2B2E672ULL, 0xCC3D5E61BEE781EFULL, 
            0x9062E84FF5F675B0ULL, 0x2144350F8E0053E1ULL, 0xBE1DABB1F4A47294ULL, 0xA6651AF1A5B4E8E6ULL, 
            0xBB896DC23825EDD3ULL, 0xC53FEA5161BC4C06ULL, 0x6224B8E1579F5C68ULL, 0x72BB0CAB85210BEAULL, 
            0x37634B373C09ABACULL, 0xE55BFDA1459FF89CULL, 0x8793EAB00B0E13CFULL, 0x18D1C49199B9E447ULL
        },
        {
            0x5DF9B6EF6F18597AULL, 0x7E0DACEB50041ABAULL, 0x0E285D8BC6D8B566ULL, 0x6B72486172233E71ULL, 
            0x5AD9787F8BB4C963ULL, 0x475BDAB22B1244AAULL, 0x60380D8BFA6FE63AULL, 0x231A5E21E9541009ULL, 
            0xF8883DC3C061B3FBULL, 0xB561E4E4550AEB92ULL, 0xE16BCFA0F4E38E96ULL, 0xFACB24804AE8F974ULL, 
            0x5F07333EC3C75A8AULL, 0x693337D1DF9A5610ULL, 0xFC73D1853831382BULL, 0x8C54B3ED1A05FE55ULL, 
            0xA81DA8B164C28A55ULL, 0xC130D427D8D7C665ULL, 0x7EFD4731F75F0883ULL, 0x50DCBBCD7D42D964ULL, 
            0x341D6AE47DAEC685ULL, 0xA514F29249534A01ULL, 0x49EB97001B0BCEA3ULL, 0x11BD11445E30DA1CULL, 
            0x48CA690D11517D06ULL, 0x93FEF31098933187ULL, 0xADB44326FC2C7969ULL, 0xC0C71E2FBE8C5E12ULL, 
            0x23FDF5BAC5385155ULL, 0xCE854AB8E71EE015ULL, 0x26577636D42EB3B9ULL, 0x3E49CD1716B1B885ULL
        },
        {
            0xCE2F6B8532FBD351ULL, 0x36DCA03D29A47DDEULL, 0x7AE25094EECE5F4CULL, 0x8B4DBA01AB12DED2ULL, 
            0x7D80DF1B635CA52EULL, 0xF889266A36F6FAF1ULL, 0x397D8DD8C36083F7ULL, 0x4A72425026D598F6ULL, 
            0x23946803C31602DCULL, 0x20928152FD15959FULL, 0x2EAFC6634B106E76ULL, 0xF16DF3DB7EC90107ULL, 
            0xEA1AF864A35FAE53ULL, 0x4B9F8D43830761D5ULL, 0x27065748872B1953ULL, 0x0EA3EAAA98A155F1ULL, 
            0x498C654FE2890B35ULL, 0x2AFA23C57B2EACDCULL, 0xD16398449952242AULL, 0xB1AFA768467CADFCULL, 
            0x14BCCC5C3955D8A2ULL, 0x2777AAEA79A002A8ULL, 0x228F6850D12CA54BULL, 0x447829F42A0B6FA6ULL, 
            0x96C34375DB066EC5ULL, 0x1563B1616E5A7F79ULL, 0x5F83E6DEC518EE66ULL, 0xC6AA552A06BA0886ULL, 
            0xBF75AE5DC78BFD61ULL, 0x5EF17D2D43D7D9C9ULL, 0x2332FECA3F3D27A3ULL, 0x77A42E838A32D319ULL
        },
        {
            0x285D56D31706EA54ULL, 0xC032BCE3D6E81149ULL, 0x09006A76493F392BULL, 0x342EC4CB7FA51337ULL, 
            0x110F1C270B9712E2ULL, 0xD3851BA63AB1CE90ULL, 0x424B2108FAD97F06ULL, 0x960C72241731C5ACULL, 
            0xEF26CE70886C5921ULL, 0x5EC5C5AA49320BA2ULL, 0xC070A85963C8CD8FULL, 0x6C6B176A3D000D2EULL, 
            0x4FC2C2BE82BEE1F8ULL, 0xE983C8E487592BCAULL, 0xE7C2E627FBFE3B0CULL, 0x96C4C3387F3E9CAEULL, 
            0x412269E1863683F3ULL, 0xC21032F1ED8B0CB4ULL, 0x2A35886F9E479967ULL, 0x4DEC8E92551DD0BCULL, 
            0x174F504300AB77EDULL, 0x769020E03C2B95A4ULL, 0x9FC9330FA63C620CULL, 0xAE8E87BDE218B9F0ULL, 
            0xFDE0AD81F5E40A91ULL, 0xC60D040F823E9443ULL, 0xE26F9535BFC79ACAULL, 0x837AB1729FF0E926ULL, 
            0x6E6698F913D896AAULL, 0x7C7F1E8EC5A12F5FULL, 0xE8724410E4A785CAULL, 0xC383B0C21A586E4EULL
        },
        {
            0xBA34BA2F7560AFD6ULL, 0xBF73D8C2B6B43F5CULL, 0x1BC139C85F983F76ULL, 0xF87BB05C670F4E5DULL, 
            0xD8BCE477F59D41CBULL, 0x0676163901092DAEULL, 0xC34B113EB3D87A40ULL, 0x08D4ED5C3E4C3147ULL, 
            0x83CB74BE91BC1250ULL, 0xDAA9208EF19AC98CULL, 0xE397A1CD5A862424ULL, 0xAEEAA3CA17F21C3EULL, 
            0x4677A1CF516C7C6DULL, 0x4E828EC01A321DC5ULL, 0xCF53C3BD924E527FULL, 0xDC6F18CAC102C5B9ULL, 
            0x9C6A1D236B54CCF4ULL, 0x21880FE002964AD3ULL, 0x2836C725FD3737BCULL, 0x1481F1062B87BBDAULL, 
            0x467C521D79AD5FC8ULL, 0x1BD6E1FDBDF20620ULL, 0x8349D3D695B4874CULL, 0x553E014BD5D36F94ULL, 
            0xA2896509D5A33159ULL, 0x7D37742BFA5033F2ULL, 0xF917191E389CCFEDULL, 0x85D6C2604D480262ULL, 
            0xCC6B8367CA245650ULL, 0x004ED5E2A45B0F70ULL, 0x70EC847FE1EFDD25ULL, 0x9B3FF71830748040ULL
        }
    },
    {
        {
            0x92F01A078E046F08ULL, 0x7964E5719A17F2AAULL, 0x6ED7004A6D9CAD5AULL, 0x20817E42D8035CD5ULL, 
            0x2FCAF5ED1253BDBDULL, 0x54B23E852ECDD00BULL, 0x8930F83311024CA4ULL, 0xC6A303864D093D66ULL, 
            0xDDFEDEB358865069ULL, 0x1A7B38EB41E2E96CULL, 0x14BBA95BA21917F3ULL, 0xD60691EA12B2C560ULL, 
            0xF0E62A1454CF4731ULL, 0xBD19573683E4CC71ULL, 0x5DEF59585C8B424FULL, 0x27584B6D017A6BE1ULL, 
            0xA0868BAAA40D70A8ULL, 0x559F6EBAD1CEF845ULL, 0xC2FBA1797424EBF0ULL, 0x58A3DD9B1D2C8D1FULL, 
            0x37C54F1AA4714E67ULL, 0xCEE124FE7CD7501DULL, 0xB5FD0395ABA68B5CULL, 0x495DE406BB048096ULL, 
            0xDEC0E0BA6A5367DFULL, 0x894EB5D3107A2007ULL, 0x54C800F9CCD4F069ULL, 0x51E120FA17BF034DULL, 
            0x6668AF27D04A2AA8ULL, 0xEFFAFA26E892FD5BULL, 0x219AC02D8774D97EULL, 0x0AE050D212CF9471ULL
        },
        {
            0x0454B627DB22C1C0ULL, 0xFBA8F34156DE1B31ULL, 0x69C99F5DE5D6B7C9ULL, 0xA5CB71F19308DE8DULL, 
            0x3218F059C41405A2ULL, 0xC612B5F8E4CCF8A0ULL, 0x064590E4E5AB449AULL, 0x455B09920763AF76ULL, 
            0xFCC8790D33931483ULL, 0xA052E2E8F3B7ECF3ULL, 0xA65EC5A9E132F4E4ULL, 0x9687762391580284ULL, 
            0x84E87681A9532A2BULL, 0xA6CEF5149E513AC2ULL, 0xEE499EBC6C0BFA3FULL, 0x16A2232662974241ULL, 
            0xE0A47F34CB007BA5ULL, 0x1DE3ADE318E2531BULL, 0x05C7F6362B43BAA5ULL, 0x43D6EB787E15957EULL, 
            0x62F973F18217429BULL, 0x215498155AF89D9CULL, 0x880154EC8B7136B8ULL, 0xA9E737C60DA564E6ULL, 
            0xFE0AA2468E42EF7FULL, 0x951FF282983D4DB0ULL, 0xDDBCFA8D4FF02EA4ULL, 0x92727385CAFD9A3EULL, 
            0xE27F7FFC6B14635AULL, 0x150A9F765CDA0CAAULL, 0xBB991E061D0AE505ULL, 0x00FEFAA2790796F1ULL
        },
        {
            0x18CF332E9FB0C8B3ULL, 0x188573885ABF3A55ULL, 0xED1494D766DBDE76ULL, 0x849827B318923936ULL, 
            0xB42AC456FE4D5E1CULL, 0x33AAE22D5301BF76ULL, 0x3FE23D289B7E7CA4ULL, 0xE153F9D9BC87FFEEULL, 
            0x504F3EF4E1CA6A09ULL, 0x0ABC408243069087ULL, 0x231C5A875EF2F663ULL, 0x3E890DA39987803DULL, 
            0x360B45A656CE4517ULL, 0x67569B05580C3319ULL, 0xB5FD2E5FC2808E0BULL, 0xF0E4BAA1C6F82F4CULL, 
            0xCA4D4DBF16D968DBULL, 0x6FD7ACEBCAAC7690ULL, 0xCE348C570ACE3855ULL, 0x2637A46D77125B28ULL, 
            0x0935CE6083E728E2ULL, 0x0CE4BEA9F55F879CULL, 0x43657B32F5C7A224ULL, 0xC75808C707F5CC6EULL, 
            0xB4137443761A9F71ULL, 0xD49DEFA0E2B45C01ULL, 0xAE56FEC048E90CEDULL, 0xACDFE5A69C8D1B20ULL, 
            0x7BFA1D7B5DDFE420ULL, 0x0F12148319927AE7ULL, 0x97124855C9E5793EULL, 0xF6A87409424547B2ULL
        },
        {
            0x542F7527FE53B6A0ULL, 0xB73EFE65D54F6165ULL, 0x477D705937B50D49ULL, 0x7101FD773CCE7753ULL, 
            0x0E44759BB0257E9EULL, 0x16EC617B6E2E915BULL, 0x458CDD8F5D669559ULL, 0xF0891A3DE057460FULL, 
            0xE7488FE937FDFE84ULL, 0xC59F2AA54D6EF2A7ULL, 0xD8ED044F57465499ULL, 0xFBFC93BCDC33C149ULL, 
            0xA8F35D3A0034FD99ULL, 0x81E198F2F428800EULL, 0xA066FDD9C5A91C39ULL, 0x3A6D3477F2B548F4ULL, 
            0x554B41F41BD909B1ULL, 0x786C0B47223A2BD6ULL, 0x2E52A75289F37F2DULL, 0x11DF9D34A364DB55ULL, 
            0x0775E2CABBBFE429ULL, 0x592830A93F2AD595ULL, 0x45435F96CBDA48FAULL, 0xD13F23C945C75537ULL, 
            0x1F69C9949A8A3A3CULL, 0xDBC704324B2403B6ULL, 0x912ED8227ACCC174ULL, 0x63D3FAC5A219E1C4ULL, 
            0x9DB53A40E5FAE0A3ULL, 0xC48D76A169EDA90EULL, 0xCF7D37D7E05F03B8ULL, 0x13FA32E214CABB93ULL
        },
        {
            0xC48CD161CB2E6E15ULL, 0xF6939FC1C3CCF2AFULL, 0xD854D6D1F61CDD7AULL, 0x719C5219B2F6CDCEULL, 
            0x30438BB35F7606A1ULL, 0xAB6BE645FC621A47ULL, 0x5512558681AD43D5ULL, 0x7A8CD9F6185DAA2DULL, 
            0xA0BD3F767E78A1A1ULL, 0xED7037D9FF9C64A6ULL, 0xD70388CA6F9DB96FULL, 0x22D4ACC82878EBCCULL, 
            0x884CE8F585519DA0ULL, 0xC2C936E59BFFEFA5ULL, 0xF476468B9C1E4DC4ULL, 0x339AC8217F0F3995ULL, 
            0xD5FAEE0B0FEFBAC1ULL, 0xE0C5CD5000B07528ULL, 0x47A9E3A88D8C4C02ULL, 0xC01F4A8748091FF7ULL, 
            0x4D9222EFE251E565ULL, 0xDA8A7EB9A9202C97ULL, 0x6FE3AC6D8C4D4C0BULL, 0x1454008EB11440F4ULL, 
            0x6E2445970FE8C720ULL, 0xD1ED701F03487CD3ULL, 0xB6A912A6630AD45DULL, 0xB9300B07A23638D2ULL, 
            0xE1CE7CA5FC9E754AULL, 0xFD926806A09962C8ULL, 0xB3A14C44BF7B50E2ULL, 0x4C34BF8C45A87CF4ULL
        },
        {
            0x216340FCC907C55FULL, 0x8B8A5C7410B14545ULL, 0x4888EA87CDEEACE3ULL, 0x47C84ABBDF3B3A38ULL, 
            0x8F967832E829BD12ULL, 0xD46563D5B88082C7ULL, 0x63AC1CF06106F73AULL, 0x63C1C16897AEC95AULL, 
            0x395B1986AD800C2FULL, 0xCED077BE90D1F433ULL, 0x423CDAE48A5D81B1ULL, 0x4D8995AC731F767EULL, 
            0x28F10E808045572BULL, 0xA8E18FBB068E2D41ULL, 0x3B5AFCB1076DA111ULL, 0x7D0FEA8D1D167354ULL, 
            0x1B2EDD02B014B51BULL, 0x0341C7B3BB3E0364ULL, 0x51781ED82BBCFDAAULL, 0x5417829FF8FEE3E0ULL, 
            0x8A9B669781249A10ULL, 0xF2CADDF7E9BD9CBAULL, 0xEB2869CD05E4A3FDULL, 0xDB13870B0173584EULL, 
            0x29A484C1B3776FA5ULL, 0xDF4BD681F797BD12ULL, 0x0DC57716D39FDDE7ULL, 0x24C5953F5A2A4FBDULL, 
            0x8FD519182519D786ULL, 0xD983CA9F27712F27ULL, 0x15FE5F977FFF1436ULL, 0x3502E128FB5EBB37ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseDConstants = {
    0x0668CD3F76271E69ULL,
    0xFCBD1FCFE06CAEABULL,
    0xB655F655215E1385ULL,
    0x0668CD3F76271E69ULL,
    0xFCBD1FCFE06CAEABULL,
    0xB655F655215E1385ULL,
    0xEB804EA58A7CB845ULL,
    0xF036A6F9EE0DDFCCULL,
    0x97,
    0x0D,
    0xCD,
    0x9D,
    0x31,
    0x44,
    0xBA,
    0x44
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseESalts = {
    {
        {
            0xC14E60647D3651FFULL, 0x138333D34DAD2941ULL, 0x84DC752A1695B89AULL, 0x08C2EE04ABD8B7DDULL, 
            0x7B5850A04722C88FULL, 0x95CBE3E7416F1045ULL, 0xAB83A5164D7A865FULL, 0x34FB9A5DE5E73C45ULL, 
            0x25B850FAD6680F25ULL, 0x5D4BC11E85F398DEULL, 0x71F8F0CD7E70DFA1ULL, 0xBE85B62B681FC583ULL, 
            0xBD2DECE56CB88243ULL, 0x9161EC106F6E7DB4ULL, 0x69958173C206DC51ULL, 0xB3C50CE23D09B949ULL, 
            0xADBAC8AA38486ED0ULL, 0x39A9D68107562D88ULL, 0x2DA84421B07D65A7ULL, 0xE40BAE1F22DF9B19ULL, 
            0xAE37F5CA262DE7AFULL, 0x65B93FD19B32D435ULL, 0x48905967ECC7D4D0ULL, 0x40E1BC4360995B84ULL, 
            0x1729EE70AAD2DB92ULL, 0xBF1AB0EAB8B55E7FULL, 0x2AFC272C49792606ULL, 0x6B9374FE4C9D1692ULL, 
            0xF9ED355DB600ED38ULL, 0x65C0328AD688ED65ULL, 0x55B6601E75B5C18DULL, 0xDB3868ABCCF7A9BDULL
        },
        {
            0xE66D9F8BB667F182ULL, 0xBBFBE26811E491ECULL, 0x250BCCDFD1367DDEULL, 0x10520344DE6E3FC5ULL, 
            0xD73A762827628932ULL, 0x47D8A8CADD030D46ULL, 0xC2584CAC486CFDCFULL, 0x7D0409CE47CB0858ULL, 
            0x19C57C6FA3B5EEB9ULL, 0x75B41BBE31A28B83ULL, 0xEB85C1CDD1C10089ULL, 0x86B0FB0CD9C21ACDULL, 
            0x0756E8CDB949196CULL, 0x7DB6A1D3E3072A6AULL, 0xF45F2E67C11102C2ULL, 0xA05E7BC9CC3E2EE1ULL, 
            0xC158D9721AD5D64FULL, 0x001A7F1DADB02156ULL, 0x1B748A33011725ACULL, 0x5664A190EDB1961CULL, 
            0xD362721DBB003290ULL, 0xA0D0663B582315E6ULL, 0x431B6E3F8720AA77ULL, 0xA50ECFCF2A91FB25ULL, 
            0x41A83480C1FE4C79ULL, 0x46D2EB4CF957AE6DULL, 0x8007AE203A27A81EULL, 0x8C4539AFC977358FULL, 
            0x0B7F90FB3E6F16E9ULL, 0x504CC70697070B0CULL, 0xC26321EBDCEBB3F5ULL, 0x7342C7850A6A31E9ULL
        },
        {
            0xEBB97F7298E37A40ULL, 0xD852D5D14B4738F1ULL, 0xC81EEE3F46EA0702ULL, 0xA40AB423E5E5133AULL, 
            0x6DA800D64B969F86ULL, 0xFE8C128FB5D8B016ULL, 0x3C3C5287F8A79EA3ULL, 0xBD602125A161B990ULL, 
            0x0C61EE09C8489810ULL, 0x0BE0A4738E592A56ULL, 0xB4AB74568FFCD74DULL, 0xD5588C28DC0454A9ULL, 
            0x8B84B6A539F1B655ULL, 0x1EF8A295AEDADC62ULL, 0x06185636C48D69A3ULL, 0xC7418D217FC7312DULL, 
            0x653866D2A2FC5D46ULL, 0x0F8F97FC6E821426ULL, 0x379DCF8029B73C4FULL, 0xEA0A7CEE526AA701ULL, 
            0xD7C84A90868F8DE5ULL, 0x34747C3E9F3B2C1CULL, 0x90AE919A265F3500ULL, 0x6651E8C715A21214ULL, 
            0xB31964ED85382284ULL, 0xA04D18AFE985FD43ULL, 0x5ACD3D25FA970426ULL, 0xCEDCFF516BD568E2ULL, 
            0x8D3FDD0433ED227CULL, 0xD7D1C8F7CDCB29CBULL, 0xC5513927C2BAFE2FULL, 0xEF82AFC3C4FEB009ULL
        },
        {
            0x8F010DCD5FC67EABULL, 0x674E49A48FB43ADBULL, 0x65BA27BF7EF4703EULL, 0x8A0CFC0045424AACULL, 
            0x958AA17BEC9FA6EAULL, 0x6693183007960152ULL, 0x8C41A8706AE8DA75ULL, 0x6BFB43BB2AA9D71DULL, 
            0xD93E335B01CE36C8ULL, 0x93627F1C727B09ACULL, 0x8890248276694834ULL, 0x4EB042679027393DULL, 
            0xE3CDC9D0510AA7AFULL, 0xB91F513B3EEB743DULL, 0x7A7C2C2C075106A5ULL, 0xDA34DA8F33E03C5FULL, 
            0x8BE6FD870519D751ULL, 0x99BE9E04D1792CC6ULL, 0x3F1F3DA18E3F5EB1ULL, 0xF8221CD88B357E02ULL, 
            0xCEBCDBCA12C48822ULL, 0x871AA0422982A43BULL, 0x3350E6CC1753F78EULL, 0xB0ECE5EA8AC9D229ULL, 
            0xB07823EA1AC5DFF2ULL, 0x4833E35DFE5612ADULL, 0x8368649F5C6FE5D1ULL, 0x5890018134979BBAULL, 
            0xEE0802AE807FE44CULL, 0x26BA3B31E737D459ULL, 0x82A8B6BA46446EF8ULL, 0x572EF067D63D889FULL
        },
        {
            0xD04412D158216BF6ULL, 0x142EB9715A9D188DULL, 0x00E3DFF102A187C5ULL, 0xC13D2037DD04FC52ULL, 
            0xF9E2911D27CA7123ULL, 0xCE3B1C4E1A032307ULL, 0x4A827C0A508932E9ULL, 0xE49001F092C4D672ULL, 
            0x51433752F71144E0ULL, 0x5DB3A0DFF93A1862ULL, 0x3E13314E50FBE87DULL, 0x6D0A1CA085977C4CULL, 
            0x2DA35FD031203BF1ULL, 0xE98041C7875FCF60ULL, 0xB231B7184F3395B8ULL, 0x872A8C4D16E2167BULL, 
            0x426A3C737BE5CF02ULL, 0x0EF61AA06A07B8ACULL, 0xCC4E976E3774916EULL, 0x10D8498A9E8EB104ULL, 
            0x92285C33E9275CFAULL, 0x095411546DBB9DAFULL, 0x0D27230801635FA4ULL, 0xEBA327E7A2735693ULL, 
            0x0BACD93C0D12EF67ULL, 0x7967C2E778A13B42ULL, 0xF26561D1E3F32465ULL, 0xD10B3CDC4E1D70B4ULL, 
            0x6E3656262385C8CAULL, 0x0708C5A3EABC802EULL, 0xD278D898BDBE59BEULL, 0xA2798678BFC9BB3FULL
        },
        {
            0x8CEBDA7FBA89FE6FULL, 0xE3F02B098CCCA1C8ULL, 0x020D939772C87CE1ULL, 0x857791876ED4D9F6ULL, 
            0x521C1B2BB478FA21ULL, 0x860B4DD4342D7BD2ULL, 0x39CCF1B5F8088C91ULL, 0x12D18E1EF47DE304ULL, 
            0xB4A65E94594F0088ULL, 0x467A939330F48503ULL, 0x2F7E2A3FBF8A3464ULL, 0x242C1F3D856EBF6AULL, 
            0x32866C7A079DFB19ULL, 0xC917A68BF99F569CULL, 0x089229D40CCAC1BAULL, 0x2B9264372A953FABULL, 
            0x0274EDAAD8BF529FULL, 0xF50CE91502FB7DBAULL, 0x4CA8E4C002DC6C40ULL, 0x34770DA9C6A0098EULL, 
            0x9012561697C591CBULL, 0xBC6E48492580F995ULL, 0x02FB380AEAB7D4D2ULL, 0xF96A4DFC7EB6B039ULL, 
            0x5AB4DC6929E287DBULL, 0x90CF3A52F5DC060DULL, 0x77A306738FE203D0ULL, 0x4BAE0CD1FCF84B00ULL, 
            0x9EF1676BFDDB2D2CULL, 0x361315B51EDFCBD7ULL, 0x809015ECE1E82F6AULL, 0x864FF618493DB134ULL
        }
    },
    {
        {
            0xAFF692D3EE519E54ULL, 0x8E8098C294AA0CF0ULL, 0x568D4B4E8821E7A9ULL, 0x84E2411DBD0F5452ULL, 
            0x11B79070A961CCEFULL, 0xCBFE5A38BB283BE5ULL, 0xD82338FFD7853BF0ULL, 0xFD04D4DAE845FE80ULL, 
            0xFDFAD093BA74917BULL, 0x7B6613B082F0E423ULL, 0x69B52FCA41782A8EULL, 0x421F623E9448C426ULL, 
            0xD788FFAC4C8F5627ULL, 0x02E8DF718205E8FFULL, 0xA921A9014500B953ULL, 0xBA4AF5480B704735ULL, 
            0xF97C6534867844E6ULL, 0x04DFFDB98754573DULL, 0x95155842CDE6377CULL, 0xDF06DC86CC207AD1ULL, 
            0x1937FEC0AD51083AULL, 0x265C6B24E5817C79ULL, 0xF13C1092B39DCEC1ULL, 0xC69D9E70AB1542EAULL, 
            0x7E71AE259D338F94ULL, 0x1E00372F9535CFEFULL, 0x5C0AD01D81A26F5EULL, 0x1A475D479BF30330ULL, 
            0x0614F14544D69B98ULL, 0xCB561C379E6E5BDAULL, 0xE707AA975C7A37A4ULL, 0x6C24F4587D9DDC4FULL
        },
        {
            0xD4600E5BE7D26EA1ULL, 0x60FF94BD4BE9FDA3ULL, 0x93EC41916B26E038ULL, 0xC05F605F2B403D59ULL, 
            0x917B77EE0DC1D8ADULL, 0x026EBECE2D5DBC16ULL, 0x6AA99B95CC80C0DDULL, 0x9F5DDC01A6C96D5BULL, 
            0x274475EFC631A8C0ULL, 0xF56D25701BE91CA0ULL, 0xE320F62154FA8371ULL, 0x451622CF29103359ULL, 
            0x55118F47B6106323ULL, 0x06A3A8BEED1127A8ULL, 0xF913605F2756AA27ULL, 0xEE7355939D3C150CULL, 
            0xCE78E5D93A2E48D5ULL, 0xCFC79D4E8102B53BULL, 0xF7F786B07B959523ULL, 0xA2870067A73666ECULL, 
            0x0DF4865E3FCEAA56ULL, 0xE92EE44E11C7DD8AULL, 0xAB3F2ABF89CEA82CULL, 0xF699344FCC3410A8ULL, 
            0x51A2A36F830C3599ULL, 0x2702D91E2CD78821ULL, 0x67EB0A992805E5F2ULL, 0x28C195BBA09229F8ULL, 
            0x842C93E20598BACFULL, 0xA032DA901F8A6356ULL, 0xA790AEEB0F8394AAULL, 0x5C62485E80AE4398ULL
        },
        {
            0xF4DDD2093A736364ULL, 0x613215412697024EULL, 0xB24A0AF3026AC07CULL, 0x6D3FBF165A6F1C73ULL, 
            0x2460F442EB1E8762ULL, 0x99B76AD3845295E7ULL, 0x23DD5EBB0D16BDC0ULL, 0x06D376E7D92467D5ULL, 
            0xA3063AA27395E35BULL, 0xD156B58271A273CAULL, 0xC6BFDE47863C2A2FULL, 0x411FC23E1B79FB3FULL, 
            0x2125EB61D3434A98ULL, 0xFD078B56CFF665BAULL, 0xFB3AFC9FC504C3BFULL, 0x812D02B290B83336ULL, 
            0xF158E2EBB583A2C4ULL, 0x84F72BE0D27E0ADBULL, 0x2307017294CB13E6ULL, 0xF0C8B75A0DD2FE99ULL, 
            0x7E79E97380F49883ULL, 0x2041C53F05A5D79DULL, 0x3C4277EC455582F8ULL, 0x448A9ED2A8CCA15CULL, 
            0x8AA32BE9B2F8FFB1ULL, 0xDFBC65124FC337DEULL, 0xA61FF04955FE6206ULL, 0x1460E802E6EE465FULL, 
            0x35E8E79AF7D09577ULL, 0x88BE3889FC33DF9AULL, 0x0396E9DA5219665EULL, 0xF20761E099AD6F1EULL
        },
        {
            0xCDA7E4E9A9E3D41FULL, 0x86D807A30DE33290ULL, 0xEF40E331A8384A7DULL, 0xC55B8C81D907D761ULL, 
            0xEC0864AE9C7026CCULL, 0xBD7C5C06E167C142ULL, 0xC264B90DA3C38220ULL, 0xA5244722FF08A23FULL, 
            0x96DB99E1043CF84BULL, 0xB75C512609E0F36EULL, 0x9E94096B3F30DF92ULL, 0xB4AF25C5CF3BBD9DULL, 
            0xBA25A3E298F98C30ULL, 0xBDB8096E3D1E28DAULL, 0x5757281B371E7288ULL, 0x21B3BD99C989C091ULL, 
            0x456BC9F2C58F9290ULL, 0x0C37CCDD74B62D68ULL, 0x3F7006A9BE999423ULL, 0x13FAA63D13D2508FULL, 
            0x2F3D649B14E41B6BULL, 0x58B7033B7EA767D4ULL, 0xFDC1F04183D9B46BULL, 0x352AAF1C1A971E1BULL, 
            0x6EE26AC2F419CF1EULL, 0x4EFFBB1307B67167ULL, 0x31B158FCFC9F2D19ULL, 0x44303BF5961CF24BULL, 
            0xE31E6DC3B9EB914CULL, 0x059C4A3A313E1DCDULL, 0x4DF11AD68F99DD46ULL, 0xE690A8CCE9904361ULL
        },
        {
            0x4D83ED8C568FFA2FULL, 0x05283D1F7E7D11C5ULL, 0xAA59B6A31D7A8F9CULL, 0xC59D0C53D5931EF9ULL, 
            0x126EA0ECFF3BA0CEULL, 0x7BC31255AE1F1E87ULL, 0x85A1A642E9DB5129ULL, 0x6304B86904C891A2ULL, 
            0xE1A6963D37CDE20CULL, 0xE9C4BDCEF2600F8CULL, 0x39185C7A6A73767EULL, 0xB9C84695C02F61B0ULL, 
            0x5310118BE5F834B4ULL, 0xA67FB3454AFF7136ULL, 0x395F51B170282A0AULL, 0x495E113438028624ULL, 
            0xBA5A65A993B74730ULL, 0x45BF24CFD5836A04ULL, 0xEDB334F0090052ECULL, 0x76A62981A394750DULL, 
            0x45044B8AACAA91CBULL, 0x701315AACEE106DEULL, 0x2619BF2CEBF89482ULL, 0x5A43786B7391A9DBULL, 
            0x2AE87508038DD94BULL, 0x1EF786E6A43A8FA2ULL, 0x867F8F84F19B7998ULL, 0xE55A5648D38EF95DULL, 
            0xB972EA41A09036ABULL, 0xB3F509C8BAD471D8ULL, 0xA4670A216D2CF73EULL, 0xFB60CF2A380C89A8ULL
        },
        {
            0xA9B6357E20B2125DULL, 0x891F7F26FEE57923ULL, 0xA78F4B7A27AE2021ULL, 0x03164EF2EDE3580BULL, 
            0x5513CBF672AF970CULL, 0xED0A073D52550E9CULL, 0x3D122C8D06A73441ULL, 0xE14890A088085E49ULL, 
            0x36A95BEAB0BA0A2FULL, 0xD5F1C31C78CBF60DULL, 0x96DD95A6E1805E71ULL, 0x12ED33D4C831613AULL, 
            0x55C2B34C945B61C8ULL, 0x53AFA4092423AB79ULL, 0x58321D65B273C377ULL, 0xD0BEDD719E1A2CCEULL, 
            0x502F722BE843A8CAULL, 0x1D60099298CE42C2ULL, 0xADA553B513BCBAC1ULL, 0xBEACBF3DE36199F7ULL, 
            0x54AAAED6A50E165AULL, 0xF98CF1F29B0BFB0EULL, 0xDCAC9DCC33A09202ULL, 0xB3735036E1033D11ULL, 
            0xDB33C702183B918FULL, 0x354B8217CF26F308ULL, 0xE8F2E1E9ECD7D7B3ULL, 0xF17AB18D821368C1ULL, 
            0xC206DD3F444B1278ULL, 0xEC24F3D67CE340BFULL, 0x5E29B6A753B967D6ULL, 0x964180B7109249ECULL
        }
    },
    {
        {
            0xDCD947036AA0350FULL, 0x0CC035B934FCBA4BULL, 0x114EDFA47544DA32ULL, 0x1DBB33B6C8AAD353ULL, 
            0x252F6AFC047A35D5ULL, 0xB3B06B2DC8AE06D4ULL, 0x985BE19768321F0AULL, 0xBA2B2699F9555C58ULL, 
            0xB61CAFE95D647EA3ULL, 0x6AF31C1951AAD804ULL, 0xBD07BBF2B6E696B8ULL, 0x3954A11E1E6FE6D7ULL, 
            0x652FD8F1DC61DEF4ULL, 0xE52B56FBC91045CEULL, 0xF9CAF98D2D24124AULL, 0xCCAD34FEB7CCC26FULL, 
            0x590E5C4B109CA94AULL, 0x5332171A4BAED7A7ULL, 0xA6B36A2DA3108A74ULL, 0xD06626A5632ADDD1ULL, 
            0x1BE6B8A8AECA57EDULL, 0xC5F126A739913D06ULL, 0x1E062589233157F1ULL, 0x68CECEE7F133331AULL, 
            0xF6381412356D1432ULL, 0x4BDA0ED613C946C6ULL, 0x4E666D33FE4C296FULL, 0x71790AD5BFED3518ULL, 
            0x1778D64548A464F1ULL, 0xD111987FA3C98B4DULL, 0x3386B2E70F304826ULL, 0xA560E8AC803EB3C5ULL
        },
        {
            0x6775F4980BBC2F5AULL, 0xDFF97F1B73AD7B68ULL, 0xC2E6B72ECFF4D2E4ULL, 0x67C3532885045175ULL, 
            0xABAEFC34B72F115DULL, 0xE3E190A7705E168EULL, 0x22F793925C0B4030ULL, 0x246C0AE45F2EF31AULL, 
            0x03FAF541E8AB0D5BULL, 0x51C8BA232597E049ULL, 0x05C3FD010B65B2C8ULL, 0x6FC3B32A002B47BFULL, 
            0x3B6F7197755A3E97ULL, 0x81678476CA3775D1ULL, 0x346780FAB9D683FFULL, 0xFA268FD20915D206ULL, 
            0x2D673B7120DC7E26ULL, 0xF744F642B35E62E5ULL, 0xB39A17AAE43B91B3ULL, 0xB5133BA3BAECC993ULL, 
            0xFD0ABEC51F682ACEULL, 0x14920E36F5B42047ULL, 0xC1BB16B647EAA529ULL, 0xD0CB7CF9AF82A513ULL, 
            0x1768C545648353E3ULL, 0x41976601AC869B59ULL, 0x978175105E314EC7ULL, 0x02B13FBB603DE72AULL, 
            0x7EE1DB8C1FD0796FULL, 0x4DCA95AA3679322BULL, 0xAB46F05763608C86ULL, 0x415727B55BA6A38EULL
        },
        {
            0xFBA02495D3623C03ULL, 0x1EE3C6AC72DE4281ULL, 0xD1D9448E0ED43B48ULL, 0xDBDC03A066CE9AA0ULL, 
            0x95DC3CDA82348760ULL, 0x8E69EEA5B67E0056ULL, 0x44AD790774BCAC8EULL, 0x467143B1508FA954ULL, 
            0x027E09B6AF66B9C7ULL, 0x5F8B1856D03CCB34ULL, 0x4294AD033EBEB5AEULL, 0xEBADD0069FE3C57AULL, 
            0x70026D0759C4AFB2ULL, 0x7167D4B09BE5D247ULL, 0xBFD98BF46294C6E3ULL, 0xDE9394FAF6881C0EULL, 
            0x6E3FC67868FE0DCAULL, 0x4917178BCC04B241ULL, 0x885499C7B9489865ULL, 0xA00CCA391CCC5651ULL, 
            0xD5ED4320F6645430ULL, 0xB1CEE34FA752B7D4ULL, 0xF3CF46B6B7ADFC1FULL, 0x27F912F2AF6F27D4ULL, 
            0x2A251D21E1D3DCE3ULL, 0x9B1D6B2179D70ED6ULL, 0xED2DE16BFE8E9E73ULL, 0x66DB9A17B5CDEA4DULL, 
            0xB26328C0B961476FULL, 0x224CD2AFD14EDAF1ULL, 0x497701F8C804B26BULL, 0xD33709773BEBDB46ULL
        },
        {
            0xA754D0BBCDA79BF8ULL, 0x7F515654024F3699ULL, 0xEC2F8BBC1D048D6DULL, 0xF63733B0FFF8174EULL, 
            0xE6FCEC027DCCEBFCULL, 0x2EF1FA06E53BB5D2ULL, 0xFBA7387254D7FF53ULL, 0x2FD616C819E330ACULL, 
            0xE98EA711BEFCDA0CULL, 0x80606D5F7BF44767ULL, 0xE4DEC03F5483AEA9ULL, 0x8E93F353AF1F3B95ULL, 
            0x036F9FD8CD4A323FULL, 0xEC9E849F66A563C1ULL, 0x5CAC6D9CBFCAF6BAULL, 0x33973932EC8912E3ULL, 
            0x1E7A4592CCDBFABDULL, 0x34E20176C37D33BDULL, 0xC6BB2B10DBB89851ULL, 0xCCBC8DE7EC5F940EULL, 
            0xDE2AD84EFD4A7937ULL, 0x95A49FACF86209C7ULL, 0x9DC95AA935CB106EULL, 0x18CBB826C0AF66D1ULL, 
            0x8161CACB035F1112ULL, 0xC66FBD70CCCF89DFULL, 0xFAD70B7DC002003FULL, 0x6647D54412B599B6ULL, 
            0x43F0AAB21A898D7BULL, 0xF534E7B307D31223ULL, 0x81630D8E2E5C9D98ULL, 0xF970F0D43EE82528ULL
        },
        {
            0x0CF155931857C9EDULL, 0x5A4F98FAED8C3D9CULL, 0xFE38BDA217DAFC2EULL, 0x5416043BDC27285AULL, 
            0x42E5D21CE18712F8ULL, 0xA7602AB75197EF1FULL, 0x6196701687F7DE4EULL, 0x63D67CDF30C77AE9ULL, 
            0xE10FCE9C7E7E117FULL, 0xDDA273748D41A7E2ULL, 0xC91D6C3016B6080FULL, 0xB0D794BEB7DDA37DULL, 
            0x03F742A8E1D7C25AULL, 0x32881E51574DE462ULL, 0x408F45C29B69E0F1ULL, 0xC6F08738C438C164ULL, 
            0x6358F92BAAE758D6ULL, 0xCC927DDB35769295ULL, 0x0B63002EEC7FCCB5ULL, 0xEE6CF33CB7BA30BBULL, 
            0x23265CD9017EE576ULL, 0xA0113C2F05A623CCULL, 0x187AE5C30BFCAAC6ULL, 0xE4E754FF1F24592EULL, 
            0xC9E82CF5278166F1ULL, 0x193992443986AB41ULL, 0xBF241E69316E8C88ULL, 0xAE929BA5B480DC35ULL, 
            0x1283499A69C30990ULL, 0x36280E8DB86405D3ULL, 0x7E3CB80F106C20EAULL, 0xB8A0FA4E4DA914BFULL
        },
        {
            0x6AEDE259FEBE5CEAULL, 0x27BB903DA14E187BULL, 0xEE3E518D979EA5AAULL, 0x4B102D64CEB719EAULL, 
            0xE0B420D3FA61A0D0ULL, 0x52EF40E26B0EC530ULL, 0xC60FCFDD050E0DD5ULL, 0x06A574664954B611ULL, 
            0xB6F79A9BB25B6DC5ULL, 0x73D042A43AA9998EULL, 0xC72F6A5881D511B9ULL, 0x12220CF8123C2E07ULL, 
            0x0DE99C000C864580ULL, 0x54DD7636EC787229ULL, 0xD54DA566A29501F8ULL, 0xC91DA3043FEB708DULL, 
            0xD4524AF368EDCDF8ULL, 0xB64BBCCFB8405D31ULL, 0x06B091191D4BCF50ULL, 0xE56DCB704946F8A4ULL, 
            0x9F76AABC97FA38CAULL, 0x19DEA15A3056B79AULL, 0xEB92FCA63B0CDD35ULL, 0x10D73B4FBF77F201ULL, 
            0x791338A11AFC69F8ULL, 0x5DD983767E01681DULL, 0x435BF75DBE43B1EBULL, 0x51FE5B86D57F94ADULL, 
            0x5DA1053D35266FA4ULL, 0x393D2849AEA666A5ULL, 0x4B6520A5BEFBAFFEULL, 0xC0419BCBC0563ABBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseEConstants = {
    0x47FCDF798AA69362ULL,
    0xC5840BDF552F1800ULL,
    0x75C5717FADCEC9FDULL,
    0x47FCDF798AA69362ULL,
    0xC5840BDF552F1800ULL,
    0x75C5717FADCEC9FDULL,
    0x8DAD56E1F358FF9EULL,
    0xDDC759B8BDD607CEULL,
    0x08,
    0x82,
    0x25,
    0x77,
    0x33,
    0x53,
    0x0A,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseFSalts = {
    {
        {
            0xFDDDF07343CF79AEULL, 0x9EF0A5FAE3BEF362ULL, 0xA835DFD3AA536E65ULL, 0xA2548A37521F5AE0ULL, 
            0xDE55ADF49144E8E1ULL, 0x02DA0B7FBF518B66ULL, 0xD14090010F43381DULL, 0x484FE5F5A79AE476ULL, 
            0xDEB107375AE470A4ULL, 0xF6D3422E65807173ULL, 0x27BE6B3F0E34155BULL, 0x4903E3ABC1F31B30ULL, 
            0x2AE90F60C96B6B32ULL, 0xBBA3D16DE1C95387ULL, 0x7BCD143950288266ULL, 0x2BA4EB38A73BB1F5ULL, 
            0x351BD67395597B00ULL, 0x287B638C3964E92AULL, 0x5B5F685596BFB889ULL, 0x62DC3EC77377730BULL, 
            0x012B9B044AF54BEFULL, 0x78B550B46A50F037ULL, 0x0078AE2BBE56D119ULL, 0x6D6126E9F0DD897EULL, 
            0xCB9C98F0860FBAE1ULL, 0x3F33BF7034722264ULL, 0x2BBED210B7710E67ULL, 0x2D869C3226CC791BULL, 
            0xA88CF88A95F46FE2ULL, 0x7C1CFAFA5E2DE56AULL, 0x1BC5D2795D25CA23ULL, 0x6A05DC201AC1E00CULL
        },
        {
            0xFD84121DCA6CC467ULL, 0xD801914DE4DFF9C7ULL, 0xCA9B9EDDF548AE64ULL, 0xEDD76262706DDE39ULL, 
            0xC46DE2642B984A8BULL, 0x8070F6CC92E812AAULL, 0x6F38468E64774563ULL, 0xC3FD18825266A5B3ULL, 
            0x13988799426A4F6DULL, 0xB020CD30953C1DEAULL, 0x49FF37774C4F2194ULL, 0xF631165ADFE6EF59ULL, 
            0xBD1724B63686EA81ULL, 0x90401BBCF47B5274ULL, 0x97CF2080AFC141FFULL, 0xABDE63EC73CD2DBFULL, 
            0x0EADC7EC7C58874CULL, 0xE46428634DEFE683ULL, 0xF8718C97583F24F6ULL, 0x5E87C8C20F64A240ULL, 
            0x2BCC90CED021EECEULL, 0xC4ABAF8AEAEEA9DDULL, 0xB490C345D048DC14ULL, 0x5ACBF75B2F1F90BBULL, 
            0x3163F2115B9C684AULL, 0x004CF0BCF4C1275EULL, 0x975855DEFE609568ULL, 0x29769FF3831027AAULL, 
            0xCF4057E3C35DAE2CULL, 0x39F510E1B01C8DFAULL, 0x7712D845CFCA543EULL, 0xAF81F411BF0702C3ULL
        },
        {
            0x7B7453F9D678A09EULL, 0xF862167334999AC1ULL, 0x6C563434D6FDB320ULL, 0x8C50DD5534133813ULL, 
            0xBE03268214CA6B9BULL, 0xB5263CE1D86CE3C7ULL, 0xD54EABFA21B92CFEULL, 0xF1CC338373B98B6FULL, 
            0x268497416492D407ULL, 0x83243CD7EAC56A5FULL, 0xB3A453C878DEA5DDULL, 0xF260311D041AE219ULL, 
            0x88EB31D2CFCDE6C1ULL, 0x5B60843C96903883ULL, 0x1E3899BC2614071FULL, 0x7053B7FFE05AF268ULL, 
            0xAE244F4B3FBADC69ULL, 0xD9D668B3CFB4F0C3ULL, 0x4D25F05DC4010CD6ULL, 0x8F293C80C0CF7EE7ULL, 
            0x72B065E585D7ADA4ULL, 0xEC09CB967C356393ULL, 0x3D894064BDA560BDULL, 0xCCFD71DAD3C4FC64ULL, 
            0x98818D1C8457352EULL, 0x97A182554A40D6DDULL, 0x10311864D213EBEAULL, 0xA5436AB0B6C3C356ULL, 
            0x7D16922FDDFB532EULL, 0x1D84B74D7BB046BEULL, 0x1DF281E569514D5AULL, 0x42CBCFED1E82C328ULL
        },
        {
            0x13D4A9BCC0FFEB19ULL, 0xB8D41901F0F4362AULL, 0xD51797587AAF88C1ULL, 0x1885F573FB17292FULL, 
            0x406F1BF6F870723AULL, 0x60BC714C03D55F84ULL, 0x62663E71B3A51321ULL, 0x5E8A7F948E746C91ULL, 
            0xCAEC03197A3FC17EULL, 0xA498A76410F1B87CULL, 0x7D462006808D42C9ULL, 0x6E19791172D9E629ULL, 
            0xC870471E7973973EULL, 0xD1E9785CF2A559D4ULL, 0x7DC60F231182A187ULL, 0xBD88F266CFD434CFULL, 
            0x467DF4440751D1FCULL, 0x049788D0D9D519F5ULL, 0x979F1C39887CDF12ULL, 0xCAD0CE2455C8B581ULL, 
            0xAC7F1ED61ACDCC3FULL, 0x944B7B5974365045ULL, 0xADA6F50516C17C5CULL, 0xED721AF4EE5D78D9ULL, 
            0xA492D2A9A8E61AD3ULL, 0xC6E86A9E513B298AULL, 0x26A667034300CC38ULL, 0x4A2A83FA53EB1805ULL, 
            0xBE12475B28FB68B8ULL, 0x98DA92C5BECBCA5DULL, 0x19733890A6307288ULL, 0xD37F546AF47EABC1ULL
        },
        {
            0x3EB32D6400FAABB6ULL, 0x18D58E9969308013ULL, 0x19A403585EF39890ULL, 0x855BEBA144F402A6ULL, 
            0x446DE1F2335B8226ULL, 0x56F60B1C4E5F70D9ULL, 0x6ECDFAAA01D99496ULL, 0xD4E3CD08C56CC5B2ULL, 
            0x01F73EC16AA6F247ULL, 0x024224505BFE6971ULL, 0xC8FF43ED534D1D38ULL, 0x9F5742380BDC15FEULL, 
            0xD1BC6C19DA52F0F9ULL, 0xA004B5A16E78E423ULL, 0xB4E62F7331B84594ULL, 0x570B4A1E5208D0BBULL, 
            0x0029F5560D2653FDULL, 0x6F4CB796A3EAA3E4ULL, 0x1D17E81257905647ULL, 0xFF01E22B92937B8BULL, 
            0xE7D86E9909AE446DULL, 0x333DD103F638877EULL, 0xDF63C3EB3C1E173EULL, 0x33F4F7781681818EULL, 
            0xE6F0B733F04DD3CCULL, 0x79C29BAAF6D25CFCULL, 0x8079B661DFFE4E8FULL, 0xD7DAE7C516B10B99ULL, 
            0xEE23387F646B1684ULL, 0x96001CBE972362ADULL, 0x99F4581C136E73A1ULL, 0xC6A81D9BA5BDDF9FULL
        },
        {
            0x1F633112DA056174ULL, 0xD91691A0CFE1E15FULL, 0x7EDE571E0C4DD132ULL, 0x36DD94B05765B46FULL, 
            0x9F2370BA2A85B2C4ULL, 0x13DDA9779A22F847ULL, 0x15881942F7600B3CULL, 0xDADE4CE07F53F924ULL, 
            0x1907380787BB4F40ULL, 0xBE34466AA0D081F3ULL, 0xC88D7BA5D2B0C7ACULL, 0xDD73F2ABB1E1F057ULL, 
            0x520D16C396F731E7ULL, 0x0D4710EEFBFA3A56ULL, 0x859DA1DEEAEBD6CEULL, 0x103E80933BD9F2D7ULL, 
            0x29CE5A62F7CE5FE2ULL, 0xFD5E63F4412F0706ULL, 0x8013E66352FD0153ULL, 0x1401AEDA8F5EAFE8ULL, 
            0x24F6FCD4090545B8ULL, 0x11C2F3B045426448ULL, 0x036744AB6B04E65CULL, 0x9C2ECCA63B027B18ULL, 
            0xCE511860E46473C9ULL, 0xF74A464437512743ULL, 0xABAEDEA4C8ED28FEULL, 0x29BE784F5E6D2C7FULL, 
            0xF680C7A0E3BC3721ULL, 0x7E1780662467FB8FULL, 0x3F754AC008A1BB11ULL, 0x0AE2C66F2EB5D0DCULL
        }
    },
    {
        {
            0x0379179EA0236E7EULL, 0x153239EC9BE9AA56ULL, 0x6AF68A7093C321B1ULL, 0x882EC91A7960386CULL, 
            0xEFAFED4A729DE046ULL, 0x2C94A53695053960ULL, 0x0A5550577B73286BULL, 0xE8AEE76BFCF9FE70ULL, 
            0x1D051A9C1D40E137ULL, 0x04507A290FB890FAULL, 0xC583759D90CAF64AULL, 0x55FE3DD3E448A9A8ULL, 
            0x4E120DB1071D7037ULL, 0xB2A4D6F50E251676ULL, 0x79CD007B6E95DD4BULL, 0xF001223D453160A8ULL, 
            0xEB5D009AF167CB2FULL, 0x2F871AAEE5A3EC3AULL, 0x12714890BE3484F9ULL, 0x2A35E920ABE925F5ULL, 
            0x3D397701E81AF715ULL, 0xCF16FC7C0CE7B628ULL, 0x881BB7374DC877CDULL, 0x3686BF95A050A1BDULL, 
            0x2AAA5C6A339D57D2ULL, 0x949D4D38C7503D16ULL, 0xE6A9FE8FB80C65A1ULL, 0xA05BF0FCEA889CB1ULL, 
            0x082E49CFA1D7CD77ULL, 0x31319D4DC13C6088ULL, 0x737C35A87B778BC8ULL, 0x1D850C53F76355BAULL
        },
        {
            0xE49B6FFB815A84C8ULL, 0x7D9364956405793EULL, 0xBA7307392D4C88D6ULL, 0x9CA8BF88E7EDFAC7ULL, 
            0x20F3B1F559A75B3AULL, 0x566C2DA05C341B4CULL, 0xBA817D10C082DAE4ULL, 0x1C1F805D14F141A2ULL, 
            0x43AA4556CEEA312CULL, 0xCC92A4E7747991FDULL, 0xD3B4F5F174316722ULL, 0x03C0821A19D40C9EULL, 
            0x0D6D3BFCF1C05832ULL, 0xF9FF627124EE42A1ULL, 0x5C97E48B19312B62ULL, 0xC1CEFD50B2930F3BULL, 
            0xBDB4FCDE131E1C93ULL, 0x54707E79F00A7C11ULL, 0x298B4B7B469B505CULL, 0x755584ADE84A947CULL, 
            0x7292436698497F9AULL, 0xDBBA7272E37A4C20ULL, 0xD8910ED28F6F6F43ULL, 0x10A383112B5C9F58ULL, 
            0xF58850261933B0A5ULL, 0xB40DAC244B952618ULL, 0x2FF730B7E945A898ULL, 0x959E1D30A4FC6542ULL, 
            0xEF14EB1B95B0DFB7ULL, 0xB96E5F2A93808E5BULL, 0x84EDDC927D8C7C8DULL, 0xE86300E0C75F9E48ULL
        },
        {
            0x1D2C06ECE208AB2DULL, 0x0BCC42B487B9A2BCULL, 0x1890574CCC160A9EULL, 0x8F466807C62D32B9ULL, 
            0x79AD448A4C69ED38ULL, 0x87BF8AFE67525D07ULL, 0x0962DB83F96E0E62ULL, 0x6AA5B31C7315D296ULL, 
            0x7DE58D9615B79962ULL, 0x425A9C70222F6782ULL, 0x235CD2D1076DFE37ULL, 0x2BC911F043FD8063ULL, 
            0x6EDF5253C4BCE334ULL, 0xCAF224FDF2B2A805ULL, 0x05AE24A61DBDC943ULL, 0xEF7493D9F4BA260DULL, 
            0x08C49C5FC1A3DAF5ULL, 0xD0CD908F2E9D9403ULL, 0x1BDF10709F52FF0DULL, 0xF07466F54C955348ULL, 
            0x41A19215BFFA75FAULL, 0x6F3688D93F249F65ULL, 0xA1F719A03B49E622ULL, 0xF58D1D17675E6858ULL, 
            0x37868900C3D966A7ULL, 0xC1BB1BB35EDA31B4ULL, 0x1CBBFFE49280EC54ULL, 0x20458E1FB4D9BBB6ULL, 
            0xA0F9405F4118670CULL, 0xEC9B8AC8E2C23540ULL, 0xA07DA5EE2FB257E2ULL, 0x30D89DA21D642EA1ULL
        },
        {
            0x4DE9D41E65CF8EA0ULL, 0xFE69006BED7D8D08ULL, 0xD8BB6F468FF043D6ULL, 0x12EAECC2B4EE330AULL, 
            0x41617AEE427D396AULL, 0xA0AFE04037CDFC4FULL, 0xD423C57208E034A6ULL, 0x1C035FD0EC629CE7ULL, 
            0x6E1476654F25EEEBULL, 0x9F4D679849ADB137ULL, 0x80AFBBDBDC672091ULL, 0x3E5E7D70DF41909DULL, 
            0xDA4F301CDB09A70DULL, 0xBCFEA95B10377305ULL, 0x9A03B8BE5D1CD45EULL, 0x4CCBE7594D7997E8ULL, 
            0xB101DB909CD18DF9ULL, 0x556479B52AAFE509ULL, 0xD57BA22C3BDBE59BULL, 0x8D43FB625E06F59DULL, 
            0xB658A81D30E045E1ULL, 0x6DA31D5D4529D8E5ULL, 0x182C0547B6123773ULL, 0xD5E86A8A931FE028ULL, 
            0x6B905AE55CBB98F9ULL, 0x36235815796FF369ULL, 0xF2579BBBDF98A71CULL, 0x51119AED79A0F7E5ULL, 
            0xB8BDB11E41A4AFDDULL, 0x64FAF7A1611A8095ULL, 0xAA54838B1F12A1F7ULL, 0xD549C8D9CD6C1963ULL
        },
        {
            0xF58B2EB3CD657EE2ULL, 0xA4CC02A9E335DD7EULL, 0x193AE20F3AACAD5FULL, 0x64F2F6A1146964E3ULL, 
            0x481C98AC593BBD07ULL, 0x3ACC94FB910494A6ULL, 0xD80ED22BFE692BE2ULL, 0xCA5DEB694589E08EULL, 
            0x3A2B6BBC805530C7ULL, 0x43716D32BA61F982ULL, 0xACDDD1D9B00517B6ULL, 0x92BA00154DF4875CULL, 
            0x542026A72CFC9446ULL, 0x1D33C489592ACAAEULL, 0x2E2255B6203FD4ABULL, 0x73420EE69E890029ULL, 
            0x4B55041AA77220F5ULL, 0x231EA3F8AF0DA7EBULL, 0xF2DA60E5012985B2ULL, 0xC5636F28AAFB4284ULL, 
            0xCBF160BB626F955AULL, 0x6CBCA760FEBFE111ULL, 0x6E998B75693DC15BULL, 0x1AD2C829AD81D358ULL, 
            0x264F6D61BF04ADDCULL, 0xA1ED673B62F75EBCULL, 0x64A9B5A779CF57EBULL, 0xB565BB7E1C245266ULL, 
            0x994FCBDF323705B3ULL, 0x8AE037AC42A69354ULL, 0xC93A5ACE68BCB119ULL, 0x7A58B6D1751650E9ULL
        },
        {
            0x81085FED037FF631ULL, 0x7B25242D4119952BULL, 0x40A87410E5014B66ULL, 0xFCAC2B2E2AC42A20ULL, 
            0x5201DA5FD826D493ULL, 0xCF3E15C7424826E1ULL, 0x16AA43C5F0750AE5ULL, 0xAEF98B1D1E09D5D7ULL, 
            0x56046FB7A06B8C3BULL, 0x8407D5AE5A0F0A79ULL, 0xF1B8552EAF520223ULL, 0xCF5926F899F43213ULL, 
            0x1D63330B90647264ULL, 0x120AC3106DF3A01AULL, 0x8818FCAABE2FAED5ULL, 0x027E220786681757ULL, 
            0xB36C4F9A445850D4ULL, 0x65D59324AB682E1BULL, 0x7D4F8D6F2AA704D9ULL, 0x7A446602C4186438ULL, 
            0xE765BDAEC9451135ULL, 0x15046B29C019034DULL, 0x881E97766CED7EF0ULL, 0x583B8485D3E14232ULL, 
            0xA0D010D1CACD7F9BULL, 0x72B8F82471548EB6ULL, 0xB6C54A18A3AC1022ULL, 0xBEE603B428AC09B7ULL, 
            0x8162F5680155F8FDULL, 0xC4694F1155C610DEULL, 0xED03B235FCC29ECDULL, 0xCC06DAAE8BC8C580ULL
        }
    },
    {
        {
            0xB468F07E52593ACDULL, 0xAD00CB4EB7FB0EC5ULL, 0xA1A9E71648AB11B8ULL, 0x9449E1E3E9891215ULL, 
            0x84EEDA8A19BEAB3BULL, 0x3264F87D047DF770ULL, 0xDFC526AB3CD9291AULL, 0x6E922D27345E3F7CULL, 
            0x764057F36A3A5866ULL, 0xCA0E49F025316764ULL, 0x056054348463FE34ULL, 0x46E813C1AB13B0D6ULL, 
            0x1355E2CC1C40AFF7ULL, 0x9029D436655C03A2ULL, 0x6AAA188F3A36C0D5ULL, 0x249FEAB4C5B97508ULL, 
            0xAB0C11B181F6CAC2ULL, 0xEEF82E3CD85E6674ULL, 0xA3619264E47C5A90ULL, 0x8F055BA0C431954DULL, 
            0x7CF011C0A4E45267ULL, 0x6309DB880AB03C25ULL, 0xB3952EC38F05DF9BULL, 0xFED17D6AB446CD15ULL, 
            0x6F2C3B5E6A3E9437ULL, 0x468D2B24B0A48BF2ULL, 0xF2036FBCB0E12BD9ULL, 0x49135ED84A0B025EULL, 
            0xBB1B6DD8C216212DULL, 0x5785B127322E943AULL, 0x384A83008C9D8059ULL, 0x13D282F3D5173AB4ULL
        },
        {
            0x661D7EAD96B63026ULL, 0x6F8008CC264678FDULL, 0x8C729D173D66E081ULL, 0x84BF203FE7E05C98ULL, 
            0xBD2422DACE93A2DFULL, 0x56BE9A793DE72248ULL, 0xA0F475A475DA6CA8ULL, 0x33113840E78833CAULL, 
            0x570204DAB666B37CULL, 0x20CD4B79FBA51847ULL, 0x124D3520EB7EDDACULL, 0x9FA4D3BACE7247DDULL, 
            0x31E02562869BC8A3ULL, 0x5D61DF86BE696EF0ULL, 0xE0F5C8A045F49753ULL, 0xC115F4469702B4F1ULL, 
            0x09BF3A8CA8A8C1A5ULL, 0xD97CB570648DC941ULL, 0x993074BA50D42C96ULL, 0x27284AC1BFF1251CULL, 
            0xEEF6BA4817777DA3ULL, 0x8099BF61306BA883ULL, 0x85EF387D781A550EULL, 0x96768F75670A4A0FULL, 
            0x4F0DBCEA8FC589A0ULL, 0x0D6B2D9176B4AF7FULL, 0xB4CCA55661467F9CULL, 0xFCB0CE043EDFE2B3ULL, 
            0x14640A5CD6BAC356ULL, 0x2E2B8BB7069EBE4CULL, 0x2F738C0BCF349BFBULL, 0x7219E2B298B3E51FULL
        },
        {
            0xA6314702AC81D50DULL, 0x122BC0373FC46239ULL, 0x98CF7EF7E53CB209ULL, 0xEB620069342C9F59ULL, 
            0xB7AD7DFABF3643C2ULL, 0x44159933C997C886ULL, 0x2DC5D79957244595ULL, 0x4AD9EB1F42B65975ULL, 
            0x43CA7E2D3F4453B5ULL, 0xB17D273785339D04ULL, 0x6E1B1A6B122DC7B5ULL, 0x2BA1EAFEF52717ABULL, 
            0x3C61CF975A897DD1ULL, 0x8A8F7DD6FFDFD077ULL, 0xC419A858B2011B80ULL, 0x62656D54E381BBB4ULL, 
            0x7C5CE461239B2944ULL, 0x5543DDB2AB9B8CF5ULL, 0xC19D31B60B75EFE1ULL, 0xB89E4D14D0BDA71BULL, 
            0x8EA4CA6E18C91A3CULL, 0xC5B74F31014F79D6ULL, 0xF76603DC134FB0E5ULL, 0x8E4D33BA403A0D27ULL, 
            0xB53BB9BB32E848BFULL, 0xC832928313EA12CEULL, 0x9AB55FBABCA94965ULL, 0xFD1E8E60F6E0A60FULL, 
            0xFC9AF1505E9E7FCAULL, 0xC8451A268772D981ULL, 0x4C8616C636360DD5ULL, 0x9FDF4BD3076551E7ULL
        },
        {
            0x69A4D83119920A6AULL, 0x02473DDEA07758A9ULL, 0x46BA5174FD71DB91ULL, 0x12ACC9602E429EC6ULL, 
            0x063A860D7205E757ULL, 0xDD03CBCE3A2F2925ULL, 0xD3DBA3F782CD4476ULL, 0x5E8CC6A9FCF76D25ULL, 
            0x786A1065EA509594ULL, 0xBDF5BF5187E85C74ULL, 0xBD7D1DEB93E50D40ULL, 0x14EA8F94D39541CDULL, 
            0xD1A45C46A224181AULL, 0x2F8BCAEF9D1BABC0ULL, 0xB57B6F5CED919556ULL, 0xEB45F3466707DC3BULL, 
            0xC4FF4C5279B51DFDULL, 0x51E88C4107DD15A0ULL, 0x34E201AE1D1A1E44ULL, 0xC873EEB063155B9EULL, 
            0x33F1D510935DFDC5ULL, 0xC42AADA81B8C183AULL, 0xD75C377BB2F666BCULL, 0x67D1D18ADBA7298BULL, 
            0x897233F975952189ULL, 0x311BD89A662885A9ULL, 0xCBBA12044E15F7E1ULL, 0x4B192E1A396BD488ULL, 
            0xCB50631B3E33DE78ULL, 0xD48E49ABA27CD276ULL, 0xBB097505930EEEF0ULL, 0x82505960C0C31CA5ULL
        },
        {
            0x8F9DACE99686DF0DULL, 0x519A982D70B7C698ULL, 0xC1C375CB745A6661ULL, 0x207A34F1E6CFFA25ULL, 
            0x3F2EB640F4B48279ULL, 0x8345660D0903F10FULL, 0xD8A43893CC66CC49ULL, 0x6262B838A49DEBA3ULL, 
            0x92CE350AF8E74602ULL, 0x42895329556E264CULL, 0x54FDD6E78F44C15AULL, 0x7DC74886DCC20FDCULL, 
            0x92BF3C0C0B933093ULL, 0xC3831C65E70CFEC4ULL, 0x868C5327959D09D1ULL, 0x3A16AACE8CBE9C07ULL, 
            0x8B429CEBAD80D399ULL, 0x1C13333CC92AB66AULL, 0x41F87E0D9F898827ULL, 0x53CE98C42AEE989BULL, 
            0x61DEAF4E07B3DAB7ULL, 0x7FBD41F27635F653ULL, 0x1AE397D9A0DC8299ULL, 0xC2C25C9DF9251EA7ULL, 
            0xDC72B0DB04FEA826ULL, 0x53DD059CA29A0455ULL, 0x1A22CFCD279943DBULL, 0xE085A833C3D28C61ULL, 
            0x9FF204261A7B3EA2ULL, 0x9F699271B12B88D5ULL, 0x11554300AB835B9EULL, 0x9160E072B50B1541ULL
        },
        {
            0x3DD74C77715BD7FCULL, 0x013F89D932D21E95ULL, 0xB0212412CD8E7292ULL, 0xCBB4A6421314F651ULL, 
            0x570917D2303F83BFULL, 0x9E8AA7E7C0DAFEA0ULL, 0xA4FC96A33C7E6DD6ULL, 0x0B9B4799DE98F270ULL, 
            0xE024E97B91E9BDBCULL, 0x21ABB14219FBA3B4ULL, 0x82E6236DF0E0E19BULL, 0x0CD68381E9BCD308ULL, 
            0x175BBAB52358D9F5ULL, 0xE0CE362F6F6FD72AULL, 0xDDF15C21A350D683ULL, 0xE2BE995ED7E3F989ULL, 
            0x4B2CEEADFC1F8B89ULL, 0x6D702366762E5056ULL, 0xEF8E2D8D442586F4ULL, 0x21DF5EB2D62344FCULL, 
            0xA41820FF3C01325DULL, 0x3CC3EBA77326FCC2ULL, 0x8110A5DD1918BC65ULL, 0xB6663A064DBF7134ULL, 
            0x7B14914A0741B617ULL, 0x73B54D6EDE59E98AULL, 0x8D500B7B1287A518ULL, 0x290361FC8F6AC9F3ULL, 
            0x5A34C58B71644EA6ULL, 0x373BC1657682D2FDULL, 0xF9ED659B9DB1EF66ULL, 0x6268DCE95B1C59B1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseFConstants = {
    0x5B8EF469AF6BFB00ULL,
    0x57A241B101E19064ULL,
    0x9E402345DCB38164ULL,
    0x5B8EF469AF6BFB00ULL,
    0x57A241B101E19064ULL,
    0x9E402345DCB38164ULL,
    0x80B041FC9A5A53F3ULL,
    0x8C1FD5FD54E018A8ULL,
    0xD5,
    0x65,
    0xD2,
    0x84,
    0xDA,
    0xD0,
    0xF7,
    0x94
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseGSalts = {
    {
        {
            0x066E12EF4F753D32ULL, 0x0326D5F2AE4D8894ULL, 0x443FF4E2FA427BDFULL, 0x4BA31E148F44D393ULL, 
            0x246E2496807B0614ULL, 0x9C7B49E16408ABB8ULL, 0xB2E437F90095A920ULL, 0x86434C11FA4AF768ULL, 
            0xD9F3013704A9BCDBULL, 0x5ACCE7C6E790A08AULL, 0x8A92C8BEF3D5B970ULL, 0xFC99D2C5CB10554AULL, 
            0xE7EA262F910A7229ULL, 0x38D5C9CFCA63A7B5ULL, 0xC0232A280BFC41EFULL, 0x31A094009FC8D276ULL, 
            0xCE47F1EE50FBDE98ULL, 0xD925A9003D3BB4B2ULL, 0x0D738AF096EA353CULL, 0x920BD3AB738366C0ULL, 
            0xB87EA9119A35975CULL, 0x905D65265D7A5F57ULL, 0x16651E32900D2518ULL, 0xEB4B1D1E12D06B5CULL, 
            0x84D28AC0428EDDB9ULL, 0xC5912A34145D5D67ULL, 0x2AA6412F8D353F11ULL, 0x6C16AD54FAD7F9E9ULL, 
            0x1282F0E767C53EFDULL, 0x297C91B15CA374D1ULL, 0xA9FFFF72DEB7973AULL, 0xDF8647446B0E85CCULL
        },
        {
            0x727F49F8B8B5CE8EULL, 0xCB4A428AB8B9AD2BULL, 0xA281BC9CF56A6D91ULL, 0x96AEA306082F4836ULL, 
            0x1B97E586F9B89595ULL, 0x9864124EB7ADB29CULL, 0x548AE8E46AF8FEAAULL, 0x1A40632F05C8233EULL, 
            0xF32AE51BF563EBD6ULL, 0x118585D6C7E3E9A2ULL, 0x39B144E999F0E229ULL, 0x99F65A3A820060B0ULL, 
            0x8F22CACFE78AD8B3ULL, 0x6C05BDDE2FEFFB90ULL, 0x2DA93BFEFD378E9FULL, 0x9435910AE5C99B33ULL, 
            0x6128E7A35D7F7FFDULL, 0x493704210DA9174AULL, 0x343BFED82FA73CD5ULL, 0x5E8659A8CED599CEULL, 
            0x9FA07B0FBF0DD450ULL, 0x38E3555F65DBB8F2ULL, 0x1A1BCFDDD81F7E1DULL, 0x8CAA9D62EAA114E2ULL, 
            0x0CEC915CFDDDC165ULL, 0x294612EBDCC1B907ULL, 0x3A03E7B09F79B74CULL, 0x0AE575B03CDE0E4CULL, 
            0xAA3E6FBF99F0A8E7ULL, 0xD540D615C774AAF4ULL, 0x92B791DFE91CFC66ULL, 0x186594AAE69050CBULL
        },
        {
            0xABA4FD06F10BE929ULL, 0x3D0A19D3C61206FBULL, 0xEB6DD8E2CE263AF7ULL, 0xE81D092CC6A12164ULL, 
            0x263FF81339A326AAULL, 0xA4D3A4203CCD7971ULL, 0x64CED9DE5025EB70ULL, 0x1E2EA95F3B0C4A85ULL, 
            0x2CBCAEF41ACECC36ULL, 0x55F5438F625F803DULL, 0x85DEC49ABA9E68F2ULL, 0x8880EC801F7926E9ULL, 
            0xD96A1219B86272F9ULL, 0xE0C3732EF34DB634ULL, 0x5E12C27F0C76F37DULL, 0x57E72EEFAD02EF9AULL, 
            0x37C8B694958965B6ULL, 0xF296B9F293E25095ULL, 0x432EDB2D0CC5725FULL, 0x2C22226359BB961FULL, 
            0xD46AAC53DAA5AD5DULL, 0xB15C42E0BFBD1345ULL, 0xA4D310949E8C0B8AULL, 0x5861D051378C9D23ULL, 
            0x67E45B2B8AE670F4ULL, 0x5D91589B44AB6FC3ULL, 0x6D8363D27D38E5B9ULL, 0x1F44B91117D47303ULL, 
            0x2826378E438A94EAULL, 0x9FF2C6E5ED143A94ULL, 0x1D132364311CC473ULL, 0xDFDD17CA861E0635ULL
        },
        {
            0xAB74AAC1F9980ED2ULL, 0xDB05EBD7BC48C83AULL, 0x239EDB56F02A2970ULL, 0x4C6A32C394F3689AULL, 
            0xC8A865383625AD97ULL, 0x31516A2D28025E25ULL, 0x157E571AC1E99CE9ULL, 0x9C9A492D59FC0460ULL, 
            0x44D104E0D001FD9FULL, 0x52014785F0446E65ULL, 0x86FE54F9C07F8089ULL, 0x3186775C0DE76832ULL, 
            0x02E67AD601961744ULL, 0xEAC383728BA19613ULL, 0x333B237E88804724ULL, 0x6563040D8046FB54ULL, 
            0xA5F8EFDD7D62F0AAULL, 0x1212D1AB7B4400A0ULL, 0xA4505B6BA5C183CEULL, 0xF17D1FDFB62E4612ULL, 
            0xF4E638CBCA4B95E1ULL, 0xC82F8764B50D1234ULL, 0x46B2418F1E4B96CEULL, 0xE4CB1EC3B7BE04CEULL, 
            0x070EB67ABF9CEFC2ULL, 0x3AFEA92A60843A9AULL, 0xD7FBB9E552FFA14AULL, 0xB660EA498540C062ULL, 
            0x78842E9F46592B72ULL, 0x14D33B9901EC5A37ULL, 0x8FBD994C7B13F8E1ULL, 0x286217E3E69FC0B6ULL
        },
        {
            0x8E6E5218DE32FD81ULL, 0x48D97DEF9F4F1AACULL, 0x9A8E566381C4BB21ULL, 0xD3B7E0EA7AE91330ULL, 
            0xA9FF63EA0DAD02A5ULL, 0xDBCC753FAC0D6DA8ULL, 0xBA84029915717AF8ULL, 0x1E72AEDF7A435D75ULL, 
            0xF10390D25E30C216ULL, 0xA44D31DF37F75D24ULL, 0xB93FA7A847F27784ULL, 0xA0EB3688ACA8CD30ULL, 
            0xBBB25166C1DDC910ULL, 0x3C8D8CA6C3C5900EULL, 0xFD346443BA2DA2B3ULL, 0x2B44D8DA0306DAB6ULL, 
            0x9C703302C3376435ULL, 0xC6549FB48BF45D58ULL, 0x575413D8AD37E85AULL, 0x1309122B48E2602EULL, 
            0x5D83E49819D8C885ULL, 0x3853B34F03E91F4DULL, 0x8A3041146CDA7729ULL, 0x985066BB844A5970ULL, 
            0xA49051EFED23FF79ULL, 0x8B3538F0692DFF9CULL, 0x747A8BD6D572C991ULL, 0x4E65D0F9847BDA1BULL, 
            0xED393D70CDEF92AFULL, 0x831B32FA69CDD4E4ULL, 0xD9CA112B27C3E46CULL, 0xADABCAE99B66C07AULL
        },
        {
            0x8EAA5372A00E7312ULL, 0xD18DEFA3AFF6A676ULL, 0x36284B4EFBBD52E9ULL, 0x509F3AA4B2747A49ULL, 
            0x6D8C3DDE6D184265ULL, 0xF11E707190A1E81BULL, 0x89886CE08A849C1EULL, 0xE90A63CBCB349538ULL, 
            0x283D5EC053BA4CB1ULL, 0x98840EC9297783B4ULL, 0x03ACA1092AE21C15ULL, 0xAA61A102CD1E395BULL, 
            0x5323578D80FE0E8CULL, 0x99B0232D6F0988FDULL, 0xFEC464D9B326104DULL, 0x7BD3B549ACA995C2ULL, 
            0x56EE81D405508C4DULL, 0xF71DB553B9D5FEB6ULL, 0x4572EB94CE9EC74DULL, 0x9C84E7E033C9DEAAULL, 
            0x8B630C674148E4B6ULL, 0x63F866B62E31FA75ULL, 0x303ED62D40DA18E8ULL, 0xE08B6D1E9D6FF183ULL, 
            0x128690FF43A56BABULL, 0x6BCFCA55FD8E2E03ULL, 0x96672CAF2CE19D47ULL, 0xCF6560FDC418B6FAULL, 
            0x43F6B69D7CC5D02AULL, 0xA2A6C9CD7C508872ULL, 0xFA2DEC50D540B2F8ULL, 0x40A394FE8F205591ULL
        }
    },
    {
        {
            0xA7B0E09F8C964749ULL, 0x8095849CEC4B6B10ULL, 0x0AD38C5D5DAF1CF0ULL, 0xE95948F57CF990CAULL, 
            0x5A61A4723F50FA7BULL, 0x6B2CFD3EDC031D26ULL, 0x0466764185285484ULL, 0x68D73746F2D1A450ULL, 
            0x349D6E050F82FF59ULL, 0xE03944BB81A47E6DULL, 0xA8385D52D7FE38F4ULL, 0xFC27A9853FF5AAE2ULL, 
            0x46F0F6E3BD6F8F12ULL, 0x5109436B522EA6E0ULL, 0xDB45C57BD9D60459ULL, 0x63BFD93560AC4EB5ULL, 
            0x73090A91FC0E0D69ULL, 0x1D637E4714FF70CFULL, 0x3A794544B576837FULL, 0x8E053C33F903B96AULL, 
            0xB26B8B13375D8A5DULL, 0x986732399EAC22E3ULL, 0x866C4652BDD3CA96ULL, 0xF28C96161B818111ULL, 
            0x65E5A2546BF8C788ULL, 0xD65F160E0BD7E52DULL, 0x9633CE7F1CB0E7BFULL, 0x368B23B715624D2BULL, 
            0x5F0299745EF86D8DULL, 0x0FA029B61BD4288FULL, 0xFE814683FBD7F8B1ULL, 0x9A078ADFA595A6B9ULL
        },
        {
            0x841ACFB307C112ABULL, 0x96CB222A5EDF582DULL, 0x69E5527D27802C41ULL, 0xE2E91FE997F9D4A0ULL, 
            0xEF7419DEE8E104A3ULL, 0x64310B7886C2BD2BULL, 0xCC03A5C6BE3AA0E4ULL, 0x78ACFFF9B704C8BAULL, 
            0x07D4469EFEA7A4E9ULL, 0x2BEF35FD8FBA7339ULL, 0xD82FDDA4272DCB96ULL, 0x3390310C1E19C124ULL, 
            0x968A901F99F5D8E2ULL, 0x86E893C65BC77FAAULL, 0x93691BEBA937C2D2ULL, 0x07F77E7F4C119382ULL, 
            0x0057CF7C5F6D8AA4ULL, 0xFA452D914AC4A598ULL, 0xD85927B00CFDCF63ULL, 0x9EE1B3676FA4889CULL, 
            0xC1E10C0FADAFC31EULL, 0x14D66173670496FCULL, 0x9B09D8C1384EBCD0ULL, 0x0D69462FD4EE32A7ULL, 
            0xEAA2172452A0EDA1ULL, 0xC89B5A7C0B0FD634ULL, 0x92076AD0AB217D19ULL, 0x5100D51226F16137ULL, 
            0x60DB60E80A27A62AULL, 0x01CDB7749112F6B4ULL, 0x862A3DBBED0AA56BULL, 0xF346302E387C7530ULL
        },
        {
            0x4DFBEA3158E0C5CDULL, 0xE43BCAD2EA12B2C6ULL, 0x040ABF8DBECA5A8BULL, 0xFB2CBC5240AC2677ULL, 
            0x364E4EA24740198DULL, 0xC890D6956941967CULL, 0x1B91BC6493EEF77FULL, 0xEFB0DBA922AB14F1ULL, 
            0x908BF7B705F4EB80ULL, 0xAC602CC123369316ULL, 0xE740EE0309CD61C2ULL, 0xB2AFEF416C77DAD7ULL, 
            0x74255B90AB807235ULL, 0x2B20E710DE4A1734ULL, 0x4A293C26DED33DB9ULL, 0x6BDC87C96765609FULL, 
            0x2FED33C621E4357AULL, 0xC54855FEB2F91A2BULL, 0xF390E12F5D28DF9BULL, 0x24AFCFA4A8B66212ULL, 
            0x644EDE5993ECA11DULL, 0x62EC57527C8AE26FULL, 0xBDA77F3A432B0089ULL, 0xCB486319D6141557ULL, 
            0x8ACC1DF4526098F4ULL, 0xBFE10918C1CCD835ULL, 0x44901E9354B3B4B0ULL, 0x8953F9B8005CD3C7ULL, 
            0x1DAA423AEBA1AA01ULL, 0xABE942DE00379BACULL, 0x880AA72E228101FEULL, 0x2788A614D4F63FF2ULL
        },
        {
            0x40B5993624D16B68ULL, 0x4FE76CD595DF9FF0ULL, 0x689811C1FC63F236ULL, 0x1D76C71AC2148116ULL, 
            0x6EBA92C33B800450ULL, 0x97AE8B37C7631F74ULL, 0x1ACB567623D7854CULL, 0x6FAE3D11675DB7FBULL, 
            0x8C6757B03A9BAA4DULL, 0x1C314D453FEFE178ULL, 0xD1D992A531CD365BULL, 0xD3793F7E05AAE44EULL, 
            0xAD9F357B9B37DE15ULL, 0x7DE464AA1E18DB5DULL, 0x0838A908C575357AULL, 0xC9F2814F23EF9CCCULL, 
            0x6EE7DA209D555DF9ULL, 0x1A322A800858B910ULL, 0x78034F781FC6C955ULL, 0x7234F4881C5CD9F4ULL, 
            0xA8C00165C561192FULL, 0xA5645116A4653F05ULL, 0x14B6D2B9D570D641ULL, 0x2F78CDA630C026A3ULL, 
            0xD20A1FA055BE0561ULL, 0x1960681011D802C4ULL, 0x47F2C77617D194EFULL, 0xD48C6C9B4C1101EBULL, 
            0x49AC06C6694FADA5ULL, 0x1439DFBBE092B48CULL, 0x1CC60747FBF08456ULL, 0xE5A46C76AA44C648ULL
        },
        {
            0x213391A6928483DAULL, 0xC091313CDA04E5FDULL, 0x0EFEDDC43C116A39ULL, 0xDC7119301336D26AULL, 
            0xF94A2693DA062CC3ULL, 0x5675CC563BD9B8DFULL, 0x5C6D79B7BF553ED3ULL, 0x7D52A9207B1E4F59ULL, 
            0xFB2EC8AC7C9F8986ULL, 0x2DADC7543A8E1F3EULL, 0x0D5FA6BF6089B3F4ULL, 0x0A3FC48DE620DB55ULL, 
            0xED3D157D8158868EULL, 0x4CC697EC6B1C6937ULL, 0x0951ACE4E5C4A43AULL, 0x469B1701986D00C6ULL, 
            0x364C2633EDBFAAF6ULL, 0x292DA7684EA73EA3ULL, 0x67A6873282167A1AULL, 0x44CC85C21AFC42DBULL, 
            0xB94E6E65A1079169ULL, 0x85A12417D9E4C27EULL, 0x25277EACB83B877BULL, 0xC28BB1002F7C9B97ULL, 
            0xE6733911891897FEULL, 0x169D7923D8F1069BULL, 0xAB5390C4731EAFD2ULL, 0xF0DA8918F612664BULL, 
            0x264610255C683E92ULL, 0x84265CE30A0A554FULL, 0xA871BFEA541C27BDULL, 0xEF152824DBA028C2ULL
        },
        {
            0x289675C01E922477ULL, 0x7ED578A91E34EE5EULL, 0xD725FA1290CF5657ULL, 0x0E0920D302ABF51FULL, 
            0x9239C2A0CA348A8DULL, 0x8858BABA6926A097ULL, 0x374621321330E597ULL, 0x51CEB4D032F57325ULL, 
            0xD3E28615E2C14C14ULL, 0xBFFE3F0A56B8241BULL, 0x16E4E4F215840248ULL, 0x6500198B800C1ECCULL, 
            0x0CAB36CF4F77E400ULL, 0xFB16718A8990DD0FULL, 0x848A6F87D9820CE2ULL, 0x2A64E859D363BCE7ULL, 
            0x98709182C8C2A9BAULL, 0xFAB7032945EE6A9EULL, 0xC82B5433F05ABE80ULL, 0xF0E3453F780D27ECULL, 
            0x6D2262C1E3D7C61CULL, 0x3EA8335E605BDB96ULL, 0x301FF439801D8446ULL, 0x2F2D004C00FE79ADULL, 
            0x7552DA8917588992ULL, 0xF26E956EF8B9BF21ULL, 0xC2B67E689F477C84ULL, 0xD32BA6487AF54B61ULL, 
            0x5F6C5D2856270526ULL, 0x28F5C190E194B410ULL, 0x8790FE29CB71FFD8ULL, 0x2521C3C46F1859A5ULL
        }
    },
    {
        {
            0x9003834776090BF8ULL, 0xE9AAE5DAF5C55D93ULL, 0x4643511EE23B2B83ULL, 0xF33C4685F3185B2AULL, 
            0x2AA0C538A3C5F5B8ULL, 0x3C4B9F4B131C81CAULL, 0x528CB4A3D964D7EEULL, 0x603A9630A7BEB68BULL, 
            0x8C35854412D04DFCULL, 0x4C73A945753D1876ULL, 0x43FADE3AF632FE4BULL, 0x20BD80039BA63003ULL, 
            0xA171534B2D420DD0ULL, 0xDA87FE1659952515ULL, 0xC873C90C8E2429DEULL, 0xD70BD68A507B5C12ULL, 
            0xCDE7A3DC28C2141DULL, 0x97B1604ECD24FEC6ULL, 0xDF1E60D52417D81AULL, 0x0ECA121B048CC602ULL, 
            0x8E7F068EDB56FED8ULL, 0x1D824C424D19B57FULL, 0x5E5BA2EC08BE4EE4ULL, 0xDAA7DDD4E35C3072ULL, 
            0x8A3676E54A291A9DULL, 0x40766845A8F162DCULL, 0xBE4698BFD5BDCCD2ULL, 0x7860C9701A101304ULL, 
            0xB3D6CFEC1B02231AULL, 0xF68273BFA77C0768ULL, 0x6933537CA45BFFBAULL, 0xC8EAB36EFE08DB0FULL
        },
        {
            0x2316C43181CCCFF1ULL, 0xD8245C51F9BE985EULL, 0x1C57CFB0933F0A9AULL, 0x54FEF3A78D1D402AULL, 
            0x4FAEA46159713E97ULL, 0xA4E5CCCE70F723D2ULL, 0x69D719F8E3D7EFAAULL, 0xC2C4E134A737C01AULL, 
            0x1481B06484853CAAULL, 0x5654AC90CC4BFA79ULL, 0xC7A52886C4F0BC55ULL, 0x261F119BEA235733ULL, 
            0x7DD3683F7EE8CC2FULL, 0x03652FFE2A7B182EULL, 0x890ED0108650827CULL, 0x0B1A3A2FD3C0D5DCULL, 
            0xA62EB6B0C1010ED2ULL, 0xEFF2A259BA90D680ULL, 0x5BD0A378E260666AULL, 0xA83592FC5F4D074AULL, 
            0x0143BEBD019016EDULL, 0x9DE09BC8F314DA1AULL, 0x4F833883B5CBECADULL, 0xBBF150545897B66FULL, 
            0x9B8C6AD69534DFB8ULL, 0x1CF4534A5C12146EULL, 0x55A3120C46D9DC45ULL, 0xA0D4BC1D34BBDABDULL, 
            0x0938718B77F38765ULL, 0x00FA2371567A5FFFULL, 0x51613B170EE530C4ULL, 0xABEB95F9ABC592F7ULL
        },
        {
            0xEBF09B716A403874ULL, 0xD961A06CA2FDC3C2ULL, 0x9A8F6A1B8FA89903ULL, 0x77B77005A07DE4DCULL, 
            0x01D263919D355DF2ULL, 0x0D62D8E7EE1AD88AULL, 0x557F0547D4C1E4D3ULL, 0x54502139FAD087D1ULL, 
            0xC41446C68C576D4CULL, 0x16E19C29080A894AULL, 0xAB7DEDF6354DA17FULL, 0x162C63577B9C98A8ULL, 
            0x3BE641C690BB4E8AULL, 0x4134B9D584CB0B97ULL, 0x4F88949C822A3582ULL, 0x32A1BDC270783636ULL, 
            0xCFAD71418DCEB7EBULL, 0x8DE93A790AFC14F3ULL, 0xE5DEE1C1DA3BE2BAULL, 0x68165B378E8081FCULL, 
            0x448E4AA4FE78AD8FULL, 0x366D609AF62697E2ULL, 0xA512F2BD4167BFE6ULL, 0xC06152EDA886B372ULL, 
            0x8FACA5E58B6ABBAEULL, 0x81B3DEC807F39B10ULL, 0x72F056C6D70F0E70ULL, 0x75DE17220C0DB4FDULL, 
            0xDA7731991695E867ULL, 0xA74BD9B392F645F5ULL, 0x357F5DA24B2A26D0ULL, 0x223F5592C2720223ULL
        },
        {
            0xFEA08AD681A01EF0ULL, 0x622309A91B4D7B1AULL, 0xD4A43A89F3529B23ULL, 0xA8AA8C80CE03C218ULL, 
            0x2144B4511EA0B748ULL, 0xABF9C0FF30A562F4ULL, 0x0C4C30558AC21BE4ULL, 0x3445EC95079E6EA1ULL, 
            0x5CFE0E98B19F25F8ULL, 0x767A7546BEA670E6ULL, 0xEBAC13C2D5FF51DFULL, 0x1472EBB2E37E0EA8ULL, 
            0xDB7A096090E1D993ULL, 0x46684C5963638317ULL, 0x2610962BE62F7A9AULL, 0x7FCEEB6DD39F7B3FULL, 
            0x06DB1678CC6D003AULL, 0x82436D7EE8CBE9B9ULL, 0x095FA6DE0ABD3804ULL, 0xA4D808163BFCA8F3ULL, 
            0x5E197651B02726A6ULL, 0x99D397BE8EAE2E57ULL, 0x4A0098AD6C891706ULL, 0xC0BFDAFA2D011FC5ULL, 
            0x1F7E30EBBE9ECCC6ULL, 0xA4DA86E116F6E63EULL, 0x52EAEE0925A6CB1CULL, 0x45A91234E8BC6401ULL, 
            0x4379EFFF14EB5ACBULL, 0x043229C68A5228CDULL, 0x522071AD444094CBULL, 0xCE4F4757E1218997ULL
        },
        {
            0xC09D9A8F4F1B3F07ULL, 0x9375C02B88C56634ULL, 0x18E25E6933917496ULL, 0x5E836F2099015141ULL, 
            0x79D8CC9CB5F41C5CULL, 0xD370FB36C89C9206ULL, 0x0461F3341F38CDACULL, 0xA98DAFAB5AE347EDULL, 
            0x352F8C3890BE94A5ULL, 0x1D7503D17B8F6CFDULL, 0x9314DE37217859F6ULL, 0x443B3BECBDBE22A4ULL, 
            0x41B9751E41A298CBULL, 0x514D3C1A440D87DAULL, 0xB626705A2662826FULL, 0x99E9F2B6FF0CD020ULL, 
            0xEA7D1E9285ECC80CULL, 0x5DDF70D52B702B8EULL, 0xC923AD8F113291E2ULL, 0xD531DF371560455DULL, 
            0x5C73AAE74125A0FCULL, 0x8F5EC992F3A978AAULL, 0xFE76D44A28F1CEAAULL, 0x290B45ABE957E9CEULL, 
            0x63D2C53137988C45ULL, 0x622083A4ADD14E88ULL, 0x1934E1CE60387DC0ULL, 0x8661173C461FA1EBULL, 
            0x785DBBF554EFE4DCULL, 0xCDB48A9EB1343596ULL, 0xCB13F2DDE2D61CFEULL, 0x7BA056766BCCEC97ULL
        },
        {
            0x5217DA0989ADB879ULL, 0x7739F00034FBF2E9ULL, 0x013E23A3DCB9EC4DULL, 0xB5E8534DC82E33BDULL, 
            0xF2B0157548ED4DA5ULL, 0x4D1C39443ABDBA72ULL, 0x6EAA805486AA9334ULL, 0x41FF3318F13E91E3ULL, 
            0x7B766AF9FC3E629FULL, 0x34FFA11355B005D4ULL, 0xC3865CC9CE34972AULL, 0x88614CA5A94D1AC1ULL, 
            0xE4465F3085923EF3ULL, 0x1D7E3D9B18F4D0E0ULL, 0x9125AB106AC92FF5ULL, 0xAA424F071D84351DULL, 
            0x868ACF4AED4CB74AULL, 0xB50E27AB811A13DFULL, 0x0112686CC5A1340CULL, 0x86EA4B0A951B0D0CULL, 
            0xB6F91AAA58B8388BULL, 0x16F34E7612F15EABULL, 0x543DAAB9AC707C86ULL, 0x6C57FF0F12CC9E81ULL, 
            0x3C84B345BC101E34ULL, 0x6D6881E5BFFE9F78ULL, 0xFE9129641C8170DFULL, 0x2761D9B242D10B36ULL, 
            0x73D5F9F590038ECFULL, 0x4423B855F399A985ULL, 0xCAFFA98B063630BFULL, 0x1ABD6C124CF04422ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseGConstants = {
    0xB3071BF7006D4F25ULL,
    0x82DCFEAE6E839F3BULL,
    0xF56DB7328F5CB6BAULL,
    0xB3071BF7006D4F25ULL,
    0x82DCFEAE6E839F3BULL,
    0xF56DB7328F5CB6BAULL,
    0xC513186F9563343DULL,
    0x9046C221614EA89CULL,
    0x5E,
    0x99,
    0x5F,
    0x4F,
    0xA2,
    0xAF,
    0x02,
    0x7E
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseHSalts = {
    {
        {
            0xB15741905959285DULL, 0x06FF354F311FE329ULL, 0x00B25E3F0F880747ULL, 0x41C6C6609EF2D724ULL, 
            0x2BAB642356CEEF20ULL, 0xD07266F74DBC0B42ULL, 0x0C0DB1B7ECAEA9F8ULL, 0x041BC4B9AE9A6303ULL, 
            0xB1366C9933ED8206ULL, 0xF9C65DE2971118A0ULL, 0x02964D5E57F72B98ULL, 0x3E3CC7570ED1F1CFULL, 
            0x4E909F0E488AD1C2ULL, 0xDDFBB3D5584AE670ULL, 0x67298C51C7A0749FULL, 0xC472ED249217EAE6ULL, 
            0xF6D6FF40058D0A2CULL, 0x0B2E72E0BA354ADBULL, 0xDB919BCA212ADB3DULL, 0x0224A242E36DD328ULL, 
            0xD1B4D28AC259ADBCULL, 0xD8EFD7131AF9C13FULL, 0x150F157D6B8C2B47ULL, 0xD90AA78B6B3FB5E8ULL, 
            0x987949E7C3FEFB59ULL, 0x25201306BC9A143BULL, 0xF93BE724F7FF357EULL, 0x5648FC44B72D96D4ULL, 
            0x4FAEA2C2C7BA5A5CULL, 0x4CB574D4022AD388ULL, 0x5DF72BCA09DB9CCFULL, 0xD88A35AEDE62A631ULL
        },
        {
            0x38B261E1DA9BC2A5ULL, 0x46B70FD9A08C51ADULL, 0xD5042B44B4BEAC5EULL, 0x2CB28B8A75409115ULL, 
            0xBB1DAC1F358E90B1ULL, 0x47810C00FB272F61ULL, 0x35A64CAD8DD632BDULL, 0xBEB3B53E77166547ULL, 
            0xEEAB68228F6580D7ULL, 0x7176C4BC6FE2C94DULL, 0x2BCD5748A332A4FFULL, 0xA0C6A7A106A7A484ULL, 
            0x90AC7C61B34C86E6ULL, 0xDFDDC3B572985EE9ULL, 0x2C258826570A05A6ULL, 0xF7D61583AF8165C1ULL, 
            0x3E9AF25FA4849AD7ULL, 0x48CBE60E2BB516C3ULL, 0x430AAA2F22BA6E86ULL, 0x1B9349EE28A23A45ULL, 
            0xE768AEB689A58263ULL, 0x92D15BE07FFDEF19ULL, 0xB0E2477EC513E360ULL, 0x8115938EE96D0997ULL, 
            0x4AD8B5B9369A70FCULL, 0x11400347DED17A13ULL, 0x3D66E34FCC019E5FULL, 0xE5DBB742B97BE26DULL, 
            0x019F153FA092484FULL, 0x02AFE3D8E7CEADB3ULL, 0xF707AA5458887D53ULL, 0xF33402CA8FB57B2BULL
        },
        {
            0xBADA1FE7A093D495ULL, 0xC3F308C97148E45EULL, 0x6AC5C77448FCE64EULL, 0xDBF909B73C1BB89DULL, 
            0x217FF7E45603969EULL, 0x88C0F7DE6B6F65BEULL, 0xBD566DAEB1A6393AULL, 0x92A43DFE13B80E5BULL, 
            0xF3411507B7449322ULL, 0xB049732064695738ULL, 0x53EFCED1684DB109ULL, 0xFAB230F3AA9BC09BULL, 
            0x700A0E28C54E06CAULL, 0x3DBD9BB964F010F7ULL, 0x2006B8449B2B230BULL, 0x8980F2F3E84FEFA8ULL, 
            0x5B8CC2C3F4E15EF9ULL, 0x10AC08A90D31A98CULL, 0xD368E1C8427D181CULL, 0x63ED3979DBAD9A7FULL, 
            0x0FF1AE02F1192356ULL, 0x9D2BAFEA5DE12676ULL, 0x3FBCEA1EF1D3C010ULL, 0xE48DD136CA24896BULL, 
            0x32AAEF64B2091CDCULL, 0xA4E1BAE19115BC66ULL, 0xC0A038FE0E6FC0E8ULL, 0x03586B724B878D31ULL, 
            0x0813F7874E6B57DFULL, 0xC00AD15BBC917E4FULL, 0x0CF016ACFCF26841ULL, 0x2B0ED6DB97D9F3FCULL
        },
        {
            0x7456D09B4F6F3969ULL, 0x68A793BF29BEF737ULL, 0x48D0E1A5CFF97FD6ULL, 0x0665A87A8D762711ULL, 
            0x82AB5A17C34BD829ULL, 0xCB66BCE1819FCB7AULL, 0xC81E45A2A3CC67FFULL, 0x318C74E74CB36A0FULL, 
            0xD6612F04940B4992ULL, 0xB0AA97013B44AFBAULL, 0x3C438D69BE6BD9C0ULL, 0xB6B4C68AAA7AA65BULL, 
            0x38837D311EDCEAECULL, 0x6B03D00B9C345B10ULL, 0x5B4D63AF02B13112ULL, 0xABC5010A5AD7E0F3ULL, 
            0xFBC29A3100EB3012ULL, 0xCA244DB2DCD46420ULL, 0x24BD883BB33170A1ULL, 0xA640C2F04291560EULL, 
            0xBF33D7712ACEC400ULL, 0x747536B973C1FC72ULL, 0x7813B7C32C8C313CULL, 0x0729A0624AD6CDC2ULL, 
            0x6FA588A44E10F424ULL, 0x16AFB239CCFDD95AULL, 0x53E57340F7902C6FULL, 0x2E682BFC316453E3ULL, 
            0xA93A80BC276BCD45ULL, 0x406487A7D0A6E7A4ULL, 0x76037342F7EDF767ULL, 0x6BD4CBF87FC815A1ULL
        },
        {
            0xE409778699A118BEULL, 0x2E44D2B21E88BF58ULL, 0xCB041B435088D6F8ULL, 0x7A472C3D24C261CCULL, 
            0x22A688D7F8DEFE80ULL, 0x7EE2643B70DDBF44ULL, 0x33A4631E7D3E78B3ULL, 0xC864A7FCB96B5879ULL, 
            0xA34945D27EB927BCULL, 0x790CF675C4B1BCADULL, 0x4F400836753AE265ULL, 0x74F84F74686BAECAULL, 
            0xE71E8464EEF7DEA6ULL, 0x73B4037581EB0A47ULL, 0x63E704BA0A5B6B54ULL, 0x7798A4CEF0467BAFULL, 
            0xF2305925577F4D87ULL, 0x5E220DDD5860940DULL, 0xD254B2A28DBD4843ULL, 0x749ABA8F0E127E5FULL, 
            0x4E19FC09B7B2FC92ULL, 0xBC6110B426CA1C9EULL, 0x3CDA91A6F379D44CULL, 0xE840773074C54747ULL, 
            0x744E1F460893FD07ULL, 0x634F60718474DB9EULL, 0x8E236C021078937AULL, 0x6E6C0FEB7A393C54ULL, 
            0xB97E8F987140E1D2ULL, 0x42824CCF9B934D38ULL, 0xEE50866D9CDA4615ULL, 0x4C5F089F4A1AEECFULL
        },
        {
            0xAAD28235709AACA9ULL, 0x08E81E93C031E608ULL, 0x9B9F1FD10B348500ULL, 0xECD41D2B9E393E58ULL, 
            0xA45436654023D6DFULL, 0x457E541DE8BB4B82ULL, 0xF56561E71D8E1012ULL, 0x722DAF3AC7FA8A03ULL, 
            0xB455CFD4884629AEULL, 0xF5DF1A1254ED6334ULL, 0x5F000B3CCFFFE2A2ULL, 0xD204F1525C2B888BULL, 
            0x6A9EE226DE595C54ULL, 0x5BFAC3AC33912796ULL, 0x9E8767148D28E567ULL, 0xEB0BD66248BA6384ULL, 
            0x3BEB3C019EBB8044ULL, 0x693E409536B714F2ULL, 0xE0CF6155902F7A7BULL, 0xF435AF61BB64EF75ULL, 
            0xF27E0EAF768C46C4ULL, 0xCE777FFDDA20413DULL, 0xFB0FFE11702B7B23ULL, 0xC688B5A598FF5DC8ULL, 
            0x20AE3C04E9F42740ULL, 0x3DA252A663239214ULL, 0x8955DD6B7107DAB7ULL, 0x4C074E56194333C1ULL, 
            0x492ACF1EBDCB2F78ULL, 0xC79440C2C8BCA394ULL, 0x0BAD2593DAD84AC3ULL, 0xF33E782235F337BBULL
        }
    },
    {
        {
            0x11CADB177B03BC16ULL, 0x4ED5259A77989251ULL, 0x242E8198D4F4A402ULL, 0x4736FA13E7B77856ULL, 
            0x779F36ADD2E11CCFULL, 0xE669CDA9A444A846ULL, 0xC30F99AAC7F791C1ULL, 0xAC7D9FB108BC01B9ULL, 
            0x4371DE28DDC79625ULL, 0x912FDDE37572940CULL, 0x90EB81CB84121C88ULL, 0x6FEFF3F078201C59ULL, 
            0x66636DCE42509D57ULL, 0x869CD2475BA65745ULL, 0x7FB15A82A3890789ULL, 0x168BDB94619A0EA0ULL, 
            0xBB74C638F9456506ULL, 0x06D35B226607BC94ULL, 0x7505954F3B736A87ULL, 0x60763F33F6AB76EFULL, 
            0x9508DA653DB06A73ULL, 0x4DB8C063268C5ED6ULL, 0x9EED251852B46B42ULL, 0x4DEACB89FDC25C7FULL, 
            0xEBF9F6F24D361E3DULL, 0x15351F393E1D17D8ULL, 0x3248E43CC1720D8EULL, 0xA415F3C7CA244CD7ULL, 
            0x898B66B36CD8C1B4ULL, 0x73C2D75EFC38C2A0ULL, 0x3D13EF477547C2C5ULL, 0x0C4D77B2C0699E5BULL
        },
        {
            0x44961CCABD7EAFA3ULL, 0x9A5656BD10DFB886ULL, 0x4C0B2147D6DA3AF0ULL, 0xF16F0BC139C37EA6ULL, 
            0x1000B932502EB5DDULL, 0x117CCBC11C52F71AULL, 0x9C07FE792517B3F2ULL, 0xD59D372E154671FBULL, 
            0xD2369FE268CC3243ULL, 0x254897C404F880DFULL, 0xC2F60127A124351BULL, 0xB4BDDF7CDCB0DC74ULL, 
            0xEBD52C8468E57DE1ULL, 0x34AA36F1DFACDC88ULL, 0xA49ED2B029AB46ABULL, 0x4B47241C155C08F8ULL, 
            0xB0F2DEFD9E8902ABULL, 0xCD95615EF7B8227AULL, 0x659B4A8638F778EEULL, 0x64FA6FB269FE7AE3ULL, 
            0xBE9E6BF3C5C762A3ULL, 0x4A8ADAEAF467D1BCULL, 0xBB28EDC1011ACD07ULL, 0x13C28B8E9E3D1EB2ULL, 
            0x1638D0BA49EAECEBULL, 0x6F0AA8C328A54BCCULL, 0xDD150DB13306E4E3ULL, 0xDDF53B06B09978DBULL, 
            0x45402A671CB17FD1ULL, 0xAA41E6000CCFD68CULL, 0xF293DD5FA1C43E8EULL, 0xBD982A54BE8CA336ULL
        },
        {
            0xD248458796FE0629ULL, 0x10A90C3EDED74847ULL, 0xD6E801696FA56345ULL, 0x4C88AFD2647E3175ULL, 
            0x09690852D4C9C8DCULL, 0xF31327D6EA6298F4ULL, 0xC8D3D21A313E2531ULL, 0x27009E392168D66EULL, 
            0x1301EA2DC7F93619ULL, 0xE9AABF3322F8DBCAULL, 0xE2C460233EFB1FEAULL, 0xD37481D2B97827CEULL, 
            0xA82CDF83A534C9EAULL, 0xC8D55A363614E749ULL, 0xEC2F314F2B5421F8ULL, 0x577D816E05678A0CULL, 
            0xF62C4F62F9C877FFULL, 0xE507E1E7580773A4ULL, 0x8024B833803B3BB8ULL, 0x474D9FB5D2E1297FULL, 
            0xB371C3B11DC75054ULL, 0xEB45047A770623F0ULL, 0xE374F23C9EC56942ULL, 0x710E5381B96CD7A5ULL, 
            0x6205F8A2BA377421ULL, 0x5A0466819D706FF1ULL, 0x35DDBE44B5A1C6A7ULL, 0x8E84ED7A2D73F599ULL, 
            0x52AA3D001E686617ULL, 0xF6F417C55A1D3D4FULL, 0x16218C84648099FBULL, 0x0F5F563B90A81C77ULL
        },
        {
            0x333739D7A97A8D4CULL, 0xDA09B83EA0E87494ULL, 0x70115668B0237D69ULL, 0xE69457DDF077565AULL, 
            0xA3F8423560158119ULL, 0x0AD16D57766236EEULL, 0x41A9A45BC4089A89ULL, 0x4BACE92B103DB29DULL, 
            0x3BBF1CB8F582D692ULL, 0xEBA6C9504A704FB1ULL, 0x67B4A52DF80419F0ULL, 0xF43BCED1E12BF546ULL, 
            0x75A2EBABE3C21DA4ULL, 0x60E13B6A1A24E63CULL, 0x79B0C5CC87294192ULL, 0x31A33628D8B69E9AULL, 
            0xAD8FFDA697892C1AULL, 0xB9AA13FD18DD5878ULL, 0xB405BB4F8F50E568ULL, 0x8D0AAD764627816BULL, 
            0x5CD7837C6C9ACF92ULL, 0xB3C97D39A7E5D80BULL, 0x184A36B3E8E5C536ULL, 0x140B3CEA646FF111ULL, 
            0xB58AB0CDB8586A01ULL, 0x6EEA1E14CD02DF5FULL, 0xECD16851776FF344ULL, 0xA67CB943DD17067EULL, 
            0xF436BC489697E2F7ULL, 0x77168B610983F7A2ULL, 0xFD27013D07BC4E1AULL, 0x78BDDD460D9D00FBULL
        },
        {
            0x1D0E47C9426522CAULL, 0x6CD1D7DAE0508C62ULL, 0x0DEA742C4E62E1B8ULL, 0x49495219D3BE05E6ULL, 
            0xAFE1B8F28B68AA52ULL, 0xE459726E42FED9C0ULL, 0x06A0D6AB83307F52ULL, 0xCFD50460AF407F07ULL, 
            0xD7793CF3F43F5A87ULL, 0x2536C7881037991EULL, 0x949EE6E11E965871ULL, 0xD02267270DAF7F8BULL, 
            0xEB0A4F2D8363C4E8ULL, 0xB204FFEFB617D629ULL, 0x4C102D3124DA3948ULL, 0x59623213FF93BD56ULL, 
            0xAA4A0EBAA769ECAFULL, 0x7D7BD9178F641A35ULL, 0x3967676BAF104F8BULL, 0xCAD0368795BDF07EULL, 
            0x8D60E28DAEE4CDE5ULL, 0xC407D915DD27D9A6ULL, 0xEF098C6400A4F749ULL, 0x0F6EB129057A3862ULL, 
            0x3056D365AAD2BA23ULL, 0x8457E3AC3CC4F4BDULL, 0x2B41ED97592F34ACULL, 0x5BEFD99585451584ULL, 
            0x0FA1B6A6EAA5BB83ULL, 0xFFF6296B7FCBAA2DULL, 0x6D40BABFEFE47211ULL, 0x7D4E62D0A0EA1159ULL
        },
        {
            0x21A97C6474D69F96ULL, 0x5EDEB27BC8E71A5DULL, 0x84C0DDEFBD90AC6AULL, 0x985A73280240024DULL, 
            0x1B8E7BF549656459ULL, 0xD0304500A63E44CBULL, 0x59AFB5D409E47533ULL, 0xAB4B61D4E7AF4420ULL, 
            0xF87431E92B6243E3ULL, 0xEC0FF5F11BF8E86AULL, 0x589001D4A8662BD7ULL, 0x47E82C8BAD26F5E0ULL, 
            0x8F68DAAD8EB42167ULL, 0x1FE887566122C12EULL, 0x9831BD7D32C5387BULL, 0x7ABF9EFC103D0D49ULL, 
            0x78C515FB7FD50EDAULL, 0xE5C6C4CC3624A129ULL, 0xC788475EE6BB48FAULL, 0x0F7D385560AAE271ULL, 
            0x64A8FD6F423936DAULL, 0x0D32956A4A18FC6BULL, 0xAE0DCE92CBCA2D21ULL, 0x7722D1108C9779BBULL, 
            0xB8166A338BECF20CULL, 0x37AB316310069749ULL, 0x14604C972263C2EAULL, 0x5859C85214DCD57EULL, 
            0x4F9B3A7A663F9E2EULL, 0x6B64665DE6C20C21ULL, 0xFDD3FC56F6CB6B6AULL, 0x207D98BB03D19B1EULL
        }
    },
    {
        {
            0xED903839C0D1FDDCULL, 0xA960A6EB9083D19BULL, 0x55938B56AE02E77FULL, 0x2BD7DB1DA6FE0E5DULL, 
            0x3E62F1204243D84AULL, 0x5187D2933C49C0DCULL, 0xD644DF857847B9B6ULL, 0x406D54C234FE4570ULL, 
            0x3B78D747EFEAB18FULL, 0xDC1548AA2C99C8A1ULL, 0x9DE12426C7C1459EULL, 0x1454CAE707942223ULL, 
            0x8620373BAA7D8DD1ULL, 0x18C615A4F20E243AULL, 0x2F70D7D3B0CD9CFDULL, 0xF3E2CD9A852A7A4CULL, 
            0x7FAD2634F571AC0AULL, 0xE6E8AAE6EF5AEE81ULL, 0x86E70B135CAFAA19ULL, 0x9E7184C5EA37DF1AULL, 
            0xF648DA44C017EBB8ULL, 0x3F18FA8B935E3875ULL, 0x870F7BA5DA81903EULL, 0xB244005C60A99691ULL, 
            0x1625DE607B83D82BULL, 0x8875EE2DA623A2E6ULL, 0x0364500E3D54B607ULL, 0x0A6B1EE89031B201ULL, 
            0x65A0595C84E30615ULL, 0x506923E72B18684DULL, 0x7B5D88D18F9D00F3ULL, 0x45E11CF5A2E62129ULL
        },
        {
            0xDFCB8991EEC4855BULL, 0xDD0742F27FD0CFB1ULL, 0x91D96101A9F16B49ULL, 0xFD226B2268AE473AULL, 
            0x835B0DDFAC5524C2ULL, 0xC5ED171ED65ACBDCULL, 0xFF174F5013E910A4ULL, 0x195CC5AB79C6C3FCULL, 
            0x8A3E417AC7C91F7DULL, 0x1CEF01465F93F252ULL, 0x25B7E98EC248367AULL, 0x9D2C7D82CA69F6E7ULL, 
            0xE6DB2AAFC12AFD0DULL, 0x25D9351878A509F2ULL, 0xB84B90F0F7ACC0ADULL, 0x81336E11B1D28E69ULL, 
            0x0085D045E1333E8EULL, 0x7BF9273145E129E4ULL, 0xA5A3F9453820A52DULL, 0xB3D8EC60B0FA0DF4ULL, 
            0x9DDF633874D4CED5ULL, 0xFD9277C22193492BULL, 0x4F98E26AE57E717DULL, 0x4E8AFEDD1D838B60ULL, 
            0xE601C036E516581BULL, 0x90E2FD5709A6B579ULL, 0xDFB3C0ACF6C02DECULL, 0xC8BDC55A59885CA0ULL, 
            0xDBAA8DC1ED05BB49ULL, 0x250F8C9A3A38CF66ULL, 0x2307F0B35E221C21ULL, 0x7EC293C28AF5552FULL
        },
        {
            0x5839AB3B22419A61ULL, 0x1A8C8B01AAE88384ULL, 0xCAF9F2A8D986CABCULL, 0x53FE7EE079A1C3C8ULL, 
            0xF501654D8007FF29ULL, 0x0FF54E0B32350BB9ULL, 0xC2CDB507BA6C49D2ULL, 0x5A18C562E2F68496ULL, 
            0xCCF0069383C952BDULL, 0x24BA8D0D1929F1F9ULL, 0x94E27AE7E7121C0AULL, 0x9CF552A4D1C142AFULL, 
            0x7B692199CF190B3BULL, 0xED2ACBD572E30194ULL, 0x8E1243D37B2294B6ULL, 0xFA9AB7514C3D254AULL, 
            0x0C5C72465568FC64ULL, 0xC459BCFFC3018C49ULL, 0x2C5D5EBA657386EBULL, 0x5A1FF846F66E6D18ULL, 
            0xA387873281B593F8ULL, 0x4BF29B55B021B904ULL, 0x8A9DA689FF72FDD0ULL, 0xD3B7F34D555AB5B0ULL, 
            0xA97D6B28AEC27BAFULL, 0x5615344DCAE4EFEAULL, 0x4A94DEA87D308F6DULL, 0xE16F08A0BDE7A3E9ULL, 
            0x8F4EBFB7B190E0CDULL, 0x60ADF575AB23A59EULL, 0x74357F9ABBD4C755ULL, 0x01E3D40B4F2A0E85ULL
        },
        {
            0x02FF0DAAA6610FA6ULL, 0x083C6A49A0B41AA1ULL, 0x128B27A9E0006749ULL, 0x0AC18F73E276A270ULL, 
            0xAB705EA9B7FEF5D1ULL, 0x655049CEE74CE978ULL, 0x16A0795A22AE4876ULL, 0xCD3FEC463F603E7AULL, 
            0x0F3D5B8AAEF04692ULL, 0x49E692D27820833EULL, 0x310EECFA5089D39FULL, 0x515C3FE723799A5FULL, 
            0x86881097610483EAULL, 0xAB8834F1E0320D1FULL, 0xF8326316FEE7FE95ULL, 0x6F2324E8ED8316ABULL, 
            0x5AAE32D7920815A1ULL, 0xB6B95C6A6864D782ULL, 0x8DC5FB8B5661D34FULL, 0xDA9DA5121A769F54ULL, 
            0x2277E9BA0F08A198ULL, 0x1769AB998C7735C9ULL, 0x3C6148B4917E4BA9ULL, 0x700398E073F10E59ULL, 
            0xD8AB8A232EA7D5C6ULL, 0x366E4B9B13281275ULL, 0x48583FF85B340CFCULL, 0x2CFC693D7C2BDC1CULL, 
            0xEB69069EC9E7861AULL, 0xECBAAAA3239D0384ULL, 0x20DC7C6103DFF874ULL, 0x40091BD5F0C47B96ULL
        },
        {
            0x2D87FA0E1903CD8BULL, 0x0A52AA4C6F7D95BEULL, 0x3D9C414482D0883EULL, 0x2C257AC52A71C236ULL, 
            0x4D55B9935A0512DFULL, 0x679C5E7424BC2324ULL, 0x4F0A3ACF20979798ULL, 0x397225E548FB7564ULL, 
            0x1AD3C13710012E98ULL, 0x99320607025B8FF6ULL, 0x36D8F1D1D5FBC0E7ULL, 0x16667DC1DE3D0AB8ULL, 
            0x9F40585F67A4FDEFULL, 0x6068AD9F566925CDULL, 0xFCA77E5800677F45ULL, 0x901AF5ACC6C87EBCULL, 
            0xED57DB590DA3B32CULL, 0x060DFDAADD1A56D2ULL, 0x31FC8ECC0109408AULL, 0x2526F315E7A2C970ULL, 
            0x409E0708B2957FDAULL, 0xEA732CE9F803F029ULL, 0xE7F5A5A53BE4AC58ULL, 0x10F3F54EB2A55B25ULL, 
            0xEE4F62694D040553ULL, 0xCC505B27A5A46CCDULL, 0xAB187F56B0C19D4BULL, 0x6BBB215E3111F871ULL, 
            0x26809F0AD5A95D49ULL, 0x961E9DC2CADC3FD7ULL, 0xC9A1134ABF92C3F1ULL, 0xFA5479112C4DACC2ULL
        },
        {
            0x7DF6B4F43802CD33ULL, 0x76C5619AAAE71CBAULL, 0x2F8EF193083ED686ULL, 0xD079DBEED70D7D6EULL, 
            0x15FB7B783514B31DULL, 0x83A35854AF733613ULL, 0xBFC1A936928D5AADULL, 0xB5B77A4BA31792C3ULL, 
            0xBA44A05FF8906628ULL, 0x46ED1A228B1F12D1ULL, 0x395900CD4C1F5E62ULL, 0x3EBB005351641728ULL, 
            0x170C61F5F4EA866DULL, 0x94D6900747D9CCABULL, 0xDE3E4EC988B3FDABULL, 0x307EA95DCB49B334ULL, 
            0xB6A59F84F9BE681EULL, 0xECB3268763A7D3C4ULL, 0x1EC6CB8D6A6ED878ULL, 0xF2E6DFE7C5E6A423ULL, 
            0x9D3D11B3F4D7786AULL, 0x5454F138BEB947EEULL, 0xF379F7F0BCB5ACC9ULL, 0x33CFDEDD25E48FA7ULL, 
            0x9CC02D762968A0F8ULL, 0x0C09C1AA8A845CC8ULL, 0x9AF9E9F9814643C8ULL, 0x72B6DC4378A92456ULL, 
            0x10DF4EA7708A1772ULL, 0x102808BED5C93C36ULL, 0xE37FE9BA6295B7B4ULL, 0xF784EBD43E531051ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseHConstants = {
    0x5B458154BF278DFEULL,
    0x2CA27EA248074A2BULL,
    0x983B330992C112ACULL,
    0x5B458154BF278DFEULL,
    0x2CA27EA248074A2BULL,
    0x983B330992C112ACULL,
    0x039579CB01266FDAULL,
    0x347CF3B61E4C85B0ULL,
    0x99,
    0x82,
    0x1A,
    0xA0,
    0x13,
    0x6C,
    0x8F,
    0x3F
};

