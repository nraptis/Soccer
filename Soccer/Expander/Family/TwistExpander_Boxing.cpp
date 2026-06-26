#include "TwistExpander_Boxing.hpp"
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

TwistExpander_Boxing::TwistExpander_Boxing()
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

void TwistExpander_Boxing::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15943330402423362308U;
        aCarry = 17664886329860958411U;
        aWandererA = 11080295888258455821U;
        aWandererB = 11809783529317013157U;
        aWandererC = 17790783941630545118U;
        aWandererD = 11484604644847347491U;
        aWandererE = 13700719888666276438U;
        aWandererF = 14958530240094856461U;
        aWandererG = 17278132448246020713U;
        aWandererH = 16069089780305006381U;
        aWandererI = 15962073950060622916U;
        aWandererJ = 13256387170884242032U;
        aWandererK = 11002473519233951148U;
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
    TwistExpander_Boxing_Arx aArx;
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
    TwistExpander_Boxing_Arx aKDF_A_BArx;
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
    TwistExpander_Boxing_Arx aKDF_A_CArx;
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
    TwistExpander_Boxing_Arx aKDF_A_DArx;
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

void TwistExpander_Boxing::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 13774014151684950900U;
        aCarry = 18439769123673821099U;
        aWandererA = 14074990659184890765U;
        aWandererB = 17258858055747980432U;
        aWandererC = 16428815188466026172U;
        aWandererD = 12455674102051758699U;
        aWandererE = 11528034889872343551U;
        aWandererF = 10513207940945665317U;
        aWandererG = 11635259139925082729U;
        aWandererH = 14076157415349841609U;
        aWandererI = 10457097620633807513U;
        aWandererJ = 13434228579761402665U;
        aWandererK = 12103983638048843590U;
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
    TwistExpander_Boxing_Arx aKDF_B_AArx;
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
    TwistExpander_Boxing_Arx aKDF_B_BArx;
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
    TwistExpander_Boxing_Arx aKDF_B_CArx;
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

void TwistExpander_Boxing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAC7E3FCFE2C3A35BULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0x928DC2E2D6F73BBFULL;

    std::uint64_t aWandererA = 0x9FB5F1D2F01C9F35ULL;
    std::uint64_t aWandererB = 0xCB5959BF653A8B14ULL;
    std::uint64_t aWandererC = 0xF0694EA778CC5CDBULL;
    std::uint64_t aWandererD = 0x81EB875F236D6A96ULL;
    std::uint64_t aWandererE = 0x9FE2D13FAECCF71DULL;
    std::uint64_t aWandererF = 0xC9F3B87D264F82EDULL;
    std::uint64_t aWandererG = 0xD6326E17295D39E8ULL;
    std::uint64_t aWandererH = 0xD7BBF6C2EC2B0499ULL;
    std::uint64_t aWandererI = 0x8B3C32921F281624ULL;
    std::uint64_t aWandererJ = 0x875E0683CD0BDF61ULL;
    std::uint64_t aWandererK = 0xC63B6ECACF8AA7C5ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneF);
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Boxing_Arx aSeed_AArx;
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
    TwistExpander_Boxing_Arx aSeed_BArx;
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
    TwistExpander_Boxing_Arx aSeed_CArx;
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
    TwistExpander_Boxing_Arx aSeed_DArx;
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
    TwistExpander_Boxing_Arx aSeed_EArx;
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
    TwistExpander_Boxing_Arx aSeed_FArx;
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
    TwistExpander_Boxing_Arx aSeed_GArx;
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
    TwistExpander_Boxing_Arx aGrow_AArx;
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
    TwistExpander_Boxing_Arx aGrow_BArx;
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

void TwistExpander_Boxing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Boxing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 14703103592008095276U;
        aCarry = 17178199090959516002U;
        aWandererA = 13616127075009546931U;
        aWandererB = 17226438471098917191U;
        aWandererC = 9479058093297011471U;
        aWandererD = 13675870359598895950U;
        aWandererE = 16102908892853587970U;
        aWandererF = 17604450129589527385U;
        aWandererG = 10590666026191828667U;
        aWandererH = 14345543015356584718U;
        aWandererI = 12276610942316862967U;
        aWandererJ = 16945080917377191681U;
        aWandererK = 14148027515446771806U;
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
    TwistExpander_Boxing_Arx aTwist_AArx;
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
    TwistExpander_Boxing_Arx aTwist_BArx;
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
    TwistExpander_Boxing_Arx aTwist_CArx;
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
    TwistExpander_Boxing_Arx aTwist_DArx;
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
        TwistExpander_Boxing_Arx aGrow_AArx;
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
        TwistExpander_Boxing_Arx aGrow_BArx;
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

void TwistExpander_Boxing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 3 with offsets 3516U, 1754U, 2985U, 4022U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3516U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1754U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2985U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4022U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 3, 0 with offsets 3634U, 184U, 7046U, 4045U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3634U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 184U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7046U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4045U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 1 with offsets 615U, 192U, 4814U, 3607U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 615U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 192U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4814U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3607U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 2 with offsets 5045U, 502U, 3449U, 3545U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5045U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 502U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3449U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3545U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 with offsets 341U, 1277U, 376U, 374U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1277U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 374U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 0, 3 with offsets 361U, 1662U, 763U, 1087U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 361U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1662U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 763U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1087U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 3, 2 with offsets 1051U, 1150U, 957U, 2013U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1051U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 957U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2013U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 1184U, 1013U, 1012U, 643U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1184U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1013U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1012U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 643U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1779U, 1056U, 1208U, 1936U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1779U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1056U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1208U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1936U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Boxing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 3, 1 with offsets 7810U, 4207U, 5367U, 1840U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7810U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4207U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5367U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1840U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 3 with offsets 7012U, 7955U, 3569U, 2112U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7012U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7955U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3569U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2112U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 0 with offsets 6008U, 904U, 7330U, 7632U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6008U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7330U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7632U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 2 with offsets 2378U, 3750U, 5166U, 1985U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2378U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3750U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5166U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1985U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7049U, 4462U, 301U, 3194U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7049U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4462U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 301U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3194U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 180U, 1388U, 1608U, 867U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 180U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1388U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1608U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 867U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1483U, 1674U, 566U, 1932U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1483U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1674U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1932U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1127U, 348U, 93U, 1129U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1127U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 348U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1788U, 204U, 103U, 1993U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1788U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 204U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 103U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 0, 2 [0..<W_KEY]
        // offsets: 482U, 1360U, 1272U, 1377U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 482U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1360U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1272U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1377U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseASalts = {
    {
        {
            0xF7CAD2136A3EBF4EULL, 0x1F8BA5FF28B7D5FFULL, 0x01266A0D9FF466B9ULL, 0x62A32881993FCC87ULL, 
            0x5647D03154DE8AF9ULL, 0x677B231C5DD2195AULL, 0x584FBCD47D0EF231ULL, 0xBA3C2870C2FAD61BULL, 
            0x0ECB06D535303E4DULL, 0x3479FCC0FAF1AE0EULL, 0x30D9C0F554D6D84BULL, 0xC408BDFB85324E13ULL, 
            0x01BB382BFF29C33AULL, 0x1CD3D1E055681CB9ULL, 0xBE80C38843869816ULL, 0x21C4D6731B3A1E1AULL, 
            0x7D49FE11B2BB3B81ULL, 0x64EFB798337DC27DULL, 0x313F9A68687E3713ULL, 0xB27758877E6A9D2AULL, 
            0x232F801D59DC2291ULL, 0x54757C7CDD5F76AEULL, 0x958D7EE44B2830D3ULL, 0xAF072BCA4396015DULL, 
            0xBF4A35615E25F063ULL, 0xC48299886156BDA4ULL, 0x7CAEC7106586C6EEULL, 0xE5058EEDCDA37332ULL, 
            0x2ABD08F6CDE49039ULL, 0x0AC5B5A6636E49C8ULL, 0xD2FA8059738B10BEULL, 0x206077D843C4BF53ULL
        },
        {
            0xA1A8EA895FAD9C23ULL, 0x5B0777E6E8618AA1ULL, 0xAB4E0737A2234248ULL, 0xBC9743506D94B930ULL, 
            0x77B8769A710CBC09ULL, 0x7AE847F1141DF6ADULL, 0xE4AAEE85672ECEADULL, 0x511A4DDB324BBD8BULL, 
            0xF88AA05D422165CFULL, 0x5C9A64EA1FF12546ULL, 0x23E9A79F26C1F253ULL, 0x1ADA853F4ED5D113ULL, 
            0x2B54589B75E9CFDFULL, 0xE91A185A439CE8C2ULL, 0xCCCA9F6D7F1B419AULL, 0xB12CCA45E24EFF85ULL, 
            0x047ACAB2079B3A78ULL, 0x2289A3FA2C6BCA1FULL, 0x470A983443D80AC6ULL, 0x1746C2DCF53B76FDULL, 
            0x9E3267A76354B9BEULL, 0x108DEAE33AC8091AULL, 0xA27674482F7DDA13ULL, 0xEAE9C9871BA7129DULL, 
            0x8ECA24477AE30CADULL, 0x036AF689A162B745ULL, 0xF4B7218E5FE0B166ULL, 0xDEDC8DCF5A99B528ULL, 
            0xD302C7EF65576EBDULL, 0xD1258A5C78C06452ULL, 0x1A9ED8602FEC57A5ULL, 0x4E3BAFF451937F2AULL
        },
        {
            0x3C9DE5DDA61AA1FDULL, 0xFEBB0CC237CFBF63ULL, 0xEEC313A2AE23FF58ULL, 0xBDED1290E0CAA7C3ULL, 
            0xD0A08964DC6278AAULL, 0x529C34056892AE65ULL, 0x134AFF12459ED3A1ULL, 0xB081DA71F73D041BULL, 
            0x5CFABDD64AC183BAULL, 0x19D879B224F329D1ULL, 0x2D6C8F332FD2ED57ULL, 0x44E1ED3DD4889EADULL, 
            0xAE06398389DB8200ULL, 0x5DBFDD5340B83135ULL, 0x8FE257E8E1AF3AEDULL, 0x37FA873E68F10005ULL, 
            0xA7D16C81E52AB1DEULL, 0x49B90DEA0CA9E8C0ULL, 0x2C02B03BABE5696CULL, 0x3217F1F737FBB0EEULL, 
            0xDE754CABD366F2F9ULL, 0x22EA2BD66ECB0C48ULL, 0x023BFB28D55CE9F2ULL, 0xF23ED1409B648B39ULL, 
            0xAF2929A6415A7378ULL, 0xF303D701A9DCC403ULL, 0xDCFBC416B597B878ULL, 0x9DA73E93911EC017ULL, 
            0x7895F03CA1AF49F8ULL, 0x8C121E0D149D0F62ULL, 0x8C017B89D017C9BFULL, 0x72FC5D632B90D034ULL
        },
        {
            0x1061BF371C80E7C4ULL, 0xDFBC40BCA5B081E9ULL, 0x338E66209D33C8F7ULL, 0xC7A5420136B73656ULL, 
            0x28AD73C8DEDEA2FBULL, 0xA59051192FD235C5ULL, 0x00A487777BA361B8ULL, 0xCA11C9DFBF1C3405ULL, 
            0x03EE077B1BF84F8DULL, 0xA9BC0058E9EF6D03ULL, 0xDC8070D225487C96ULL, 0x26115E2B6A6A8909ULL, 
            0x8FEFA835C8D14F1FULL, 0x65ECE3C4F23E065FULL, 0x6F6F03D1E0256F56ULL, 0xF3FA5FB2299FDB5BULL, 
            0x8DB1B060B710B1EEULL, 0xD68EFE3C05E9259AULL, 0x8605DC96DA14843CULL, 0x7C7CF87A2E9D56C0ULL, 
            0xAF837F7CCAB10097ULL, 0xC4B9687569F55656ULL, 0x32F02FD5CB94877FULL, 0xC1E57384EADEBFC1ULL, 
            0xFE071C26FE169AE4ULL, 0x55E25B0BACC818B4ULL, 0x66E4E278A3825B67ULL, 0x4568F0BDA19DC4A8ULL, 
            0x74B9B5B340012906ULL, 0xE6EC794DFE2DA053ULL, 0xA9CFD437A0124D57ULL, 0xA6CE158C941569A7ULL
        },
        {
            0x52687B95DA7A11E3ULL, 0x3F03321748EF50E9ULL, 0x6110DF6506694823ULL, 0xDFD9B63921807DCFULL, 
            0xC27DEA9A820B5EA3ULL, 0x3E7B62991F6F04B1ULL, 0x83880D82B789E6C8ULL, 0x724A8AA86BCBB380ULL, 
            0x35F8F0115E3F9BDAULL, 0xF3C33D12C077A79FULL, 0x94443FB8FC0380B6ULL, 0x09A82A39665F3F48ULL, 
            0x58D6FF5A13E70FC6ULL, 0x6D83FF8B5D25E185ULL, 0x9ABAD4BBC7299418ULL, 0x26652DA49C98C47DULL, 
            0x39D12C755CBB9678ULL, 0xCC92D45FEB59DE03ULL, 0x8B7BFD09119E36DFULL, 0xB23001170F210341ULL, 
            0x6A1D46FEE4FF82D7ULL, 0xF2F5394931311BBAULL, 0x6B6B1C4AE3B39CE9ULL, 0x5A4897248E0A78B0ULL, 
            0x47614C406777FD4DULL, 0x009022DF5078A09BULL, 0x87BA969457D3B3B9ULL, 0xDFB3209DD3EE1040ULL, 
            0x3D5B2FBEACEF50ADULL, 0x71E308DC94BAF74DULL, 0xB3F26EC2614AAF6DULL, 0x103933C13D18A98EULL
        },
        {
            0xFFF2D088525FA738ULL, 0x9A11C72DBB9AB53CULL, 0x2F8E306344357941ULL, 0xCE8E942E6B5C5F55ULL, 
            0x4C76A1129F86B5CBULL, 0x67DA7135221FA5C3ULL, 0xEDE699A5711A7E4DULL, 0x7C08472AEE79A136ULL, 
            0x39F4F2F34040DE54ULL, 0x1210B04D7EF5AC91ULL, 0xE6056F5190E86AFCULL, 0x4D8DDD69682A8EB5ULL, 
            0xEABD6A222012A050ULL, 0x4BDD138ECDC4C6C6ULL, 0xC2FF2ACD3D4AF830ULL, 0x638EC3F8DAAB0C63ULL, 
            0x6A87D4BD968F3235ULL, 0xA407CB5BC824A8DFULL, 0x6E5791CA0069455DULL, 0x609B7354481BA18DULL, 
            0xA0F12218C9A10946ULL, 0x0FD50128EF43AEBFULL, 0x92B82632BEC633B1ULL, 0x6BC24EA11702918DULL, 
            0x77B3E7D5CB766F0BULL, 0x328E448B874DC208ULL, 0xD29A93D947AB8FB6ULL, 0xFDFC9C6714C5ADF7ULL, 
            0xFEB4B967736D5F18ULL, 0x1115DFAA80F7699BULL, 0x0784C57373856887ULL, 0xF8D1F9788CE8690DULL
        }
    },
    {
        {
            0xF13764C12D2ED2E5ULL, 0x2F871506D91E375CULL, 0x543B034E392FB75AULL, 0xA883A034A499AA76ULL, 
            0xB55190DC26F48BEDULL, 0xC0E15FDE29511DD9ULL, 0x0B1F36597C618139ULL, 0x3CFAB24D6B0B6877ULL, 
            0xE123E216094D2B73ULL, 0xCB539313B6588C41ULL, 0xFBE87C877F0410E0ULL, 0x842EFD0A24C4C319ULL, 
            0xDEBEB922CE560049ULL, 0x6AA6C9CFCB5084FBULL, 0xBC0900805B91BD7DULL, 0x97745E4A3596E515ULL, 
            0x450605C2FABD6F12ULL, 0x30BE24A0BABD6654ULL, 0x96C99AD63CFC07EAULL, 0xD198E1A0BBF543B0ULL, 
            0xF92DF036C78A084FULL, 0x7E4B7FF0FB1FB4EAULL, 0x7D3531C6F692B18AULL, 0xE436F8C6C5D035B4ULL, 
            0x687A651EF31055B7ULL, 0x1282B2920359AA4BULL, 0x58571694B4A564F3ULL, 0x8BCDBE053E584919ULL, 
            0xA7180245CC0DC964ULL, 0xBBF24A4414B42F5DULL, 0x676B082CA0FD460DULL, 0x8E5170AA4198A66DULL
        },
        {
            0x8BE4F9F21B7264F3ULL, 0x540FE264B7E95A38ULL, 0x172B7C28450536A9ULL, 0xB5C29D94861D5B59ULL, 
            0x2F78AF0F52EABF1FULL, 0x0A69078BBC28C1F7ULL, 0xC2D07E0E84DE4963ULL, 0xD0517E6BB2F906E9ULL, 
            0xE1CA1B64DE19C92FULL, 0x81BF41BF7EEF2635ULL, 0x39545A7FBFB6F382ULL, 0xFC391118430AEB8FULL, 
            0x3CEF2CCE5AABE620ULL, 0xDE6CCE2113E0C0CCULL, 0xDB3E10A96578BE92ULL, 0xF53BBAE1397CE85CULL, 
            0x141C999B75A6422FULL, 0x2290272DB0CF8BA2ULL, 0x4C1A494CA26411DFULL, 0x730390B9CC60D1D7ULL, 
            0xF77353FBC1164080ULL, 0xACFDA33C96C5BC33ULL, 0xABB283C10E7E3991ULL, 0x0545B700EC60C05FULL, 
            0x4D377BFF4C303FB0ULL, 0xC64239D25706E3A1ULL, 0x6C88382E45C93263ULL, 0xBAD8B81202C2246BULL, 
            0x571D7E26196CA4DCULL, 0x1316DE289B1D2538ULL, 0xB1585B5546DBD42CULL, 0xDDA28CB0554E3BCDULL
        },
        {
            0x978169DBE3B156FCULL, 0x88760EF672B2211BULL, 0xABDA5CC59E0E7E50ULL, 0x990FBB94BA2E6345ULL, 
            0x9F79EAFA208E9A0DULL, 0x58C4B36D648AA5D6ULL, 0x16F50A286D1C6602ULL, 0xC0A40EE190F9CDC1ULL, 
            0x2D6B6210FBC2384CULL, 0x93518E647B7CF7CCULL, 0x4DF758FBA7D588D6ULL, 0x181C963F20C97D24ULL, 
            0x3F3CC6DFE367C0A4ULL, 0x996ADCB9020E43E1ULL, 0x0D3E645A9F8EA03DULL, 0x48DD3F3381727F12ULL, 
            0x2DBE93AF90103A00ULL, 0x326E41E037FBF204ULL, 0x939E5FA4AC209D2BULL, 0xBB48B05CD686B4C4ULL, 
            0x9EAEB11CA8D0ED32ULL, 0xEB01E0A739982B6AULL, 0xF848862FACD4767BULL, 0x2887CD73E0762A3AULL, 
            0x0CB5C99F390B08D8ULL, 0x7CC31EC05D0556CAULL, 0xFCB7FACFA95D7959ULL, 0xAA64DE5560394D68ULL, 
            0xA8F0BDA58055BD01ULL, 0x9B5F28BD2CBC0226ULL, 0xB475AA9B1357FCBCULL, 0x172215C3B1D8374FULL
        },
        {
            0xE583C8848285E8FEULL, 0x02E8A2F88ED75D5EULL, 0x488B08DB7775A62EULL, 0x7C7607E68108E033ULL, 
            0x00B06A639E1817ACULL, 0x2A1AF631CE802706ULL, 0x24111A59BEF2438DULL, 0xDFC56350AAE4CE92ULL, 
            0xAAAC4D235FAA4D11ULL, 0x4996B1226C9EE90DULL, 0x7ACAE4AFCAB83059ULL, 0xDD6BCCEF3A011CB8ULL, 
            0x9B7650A6DF72E233ULL, 0x85E708B37002808EULL, 0xAAB36E88F8D0845CULL, 0xEB8E4B32DFF3F766ULL, 
            0x655AF0A57EF75559ULL, 0x0B69748071743CC6ULL, 0x3C9F929218C8ED55ULL, 0x76B024515943C986ULL, 
            0x3B922D5A384D24CCULL, 0x082F3557269B40BCULL, 0xF4F78B2AD0F29E2BULL, 0x605D8A2F2A60AD6BULL, 
            0x8F26613A4FE0D419ULL, 0x98C1D9B9E696CB1AULL, 0x7AD082127B18E66EULL, 0x2C15FA103CF8C90AULL, 
            0x16355358B0E178B1ULL, 0x8EED8366B89F5566ULL, 0xD86A0321157C8680ULL, 0xFEF8776A536FE9D3ULL
        },
        {
            0xEE8325FFD11BA8F9ULL, 0xC417BE9EA25695A7ULL, 0xBADB31EF14E65D0DULL, 0x76FF2E6336098AE2ULL, 
            0xA3E41CF82B3C5844ULL, 0xC6C5F45ED1A656BEULL, 0xC5697BD11235F4F7ULL, 0x7F7173A697BDDB5AULL, 
            0xD828ECBE2AE4BA97ULL, 0x8C49F8591470795BULL, 0xDDBC654821134EBAULL, 0x4102AF566017D414ULL, 
            0x577DB4AA95364A44ULL, 0xE82F151579FBFC46ULL, 0x800D1A87A6CD4341ULL, 0x8F2FAAF6D5B4D54FULL, 
            0x43B004800E6505E5ULL, 0x3F321E9AAC81EABDULL, 0xBD8D52C4F34A58EDULL, 0x779B545F91CD089CULL, 
            0xD8F39F97296A05C0ULL, 0x616EE134AC69292AULL, 0xC048B87091D90A9BULL, 0x91A9F5EC7D027354ULL, 
            0x2F99168851180E99ULL, 0x3BDF7D4CDC73DC2DULL, 0xE544973E33FFED1BULL, 0x36A7194C4559E730ULL, 
            0x0D12FB541385F140ULL, 0x359FB5D91B0367A3ULL, 0xD773A764C48FDAF3ULL, 0x96763741EC8286AAULL
        },
        {
            0xEEEE8FB767707383ULL, 0x7BE2535E983950BEULL, 0x07584105768D24AEULL, 0x5F280A5BDE086B6CULL, 
            0x00BEF367924A7F37ULL, 0x9DF32B06E410BB26ULL, 0xFAB5CE06DB83AC01ULL, 0x0E130125065677B4ULL, 
            0x21A4A31C99951E04ULL, 0x6DFE8B70B060E16DULL, 0xF19716707D76D026ULL, 0x055BFDCD92B6FFE9ULL, 
            0x01755584896C0AB8ULL, 0xE824B18589D1B839ULL, 0xBB606D49D8F81168ULL, 0x3AA8DA208D62BE1EULL, 
            0x3CC08A9AE7215BC3ULL, 0x7A9E8CEA39F679A3ULL, 0x6492888748712252ULL, 0x25351C5E56301622ULL, 
            0xFC25DF544EFB280BULL, 0xDDD431502482A2EEULL, 0x948C84FFF1AFB48EULL, 0x12AF2B8F390333B2ULL, 
            0x0760F6743C9C995CULL, 0xD4250DAEA89EB4D5ULL, 0x7C16AB6339956751ULL, 0x4062CDB62C050A41ULL, 
            0x4687D7E5B4233824ULL, 0x6EBBB574E903E59DULL, 0x14EA753549FC5D7EULL, 0xAD007A5122E7631FULL
        }
    },
    {
        {
            0x66F2F5E5FAFDE94BULL, 0x362F57503042CD27ULL, 0xFCF4D2B2CDCE5DDBULL, 0xD6B729DDC6E333E0ULL, 
            0x5BF3679FAAC1284FULL, 0xBFC9492D664931B6ULL, 0x2651E6BC65486C71ULL, 0xC52D4F24DDBED791ULL, 
            0xCD84BB11048FD576ULL, 0x92EC0CD7C1D957F2ULL, 0xD89D89E0FF3AA8BFULL, 0xC17D5AD0AF815347ULL, 
            0x480A7A6EB1A74268ULL, 0x5DF74345D4DC11ACULL, 0x9FE3ADFDD3950D76ULL, 0xC35A8188E207E6B2ULL, 
            0x3AEEEC76EF2BD73EULL, 0x11B27DE5088E29BEULL, 0x0850BE616F64C9E3ULL, 0xBE91C8BB8EB59845ULL, 
            0xF731632D2A347D12ULL, 0x1820AD05501A3D1CULL, 0xAB02E01C7AD3A0ACULL, 0xC93CBF0EA0A31956ULL, 
            0x850D966ADD043517ULL, 0x22B4DF2B0072D453ULL, 0xE2204EEC2C53FF49ULL, 0x8CB365A600A65DCCULL, 
            0xA0E8328456FE1881ULL, 0x1C05D969A637BBB2ULL, 0x1F8D837CE4BDC155ULL, 0x72CADB342A07DEB0ULL
        },
        {
            0x1D28CBF06D71209FULL, 0xEFF3D95ABF697963ULL, 0xE94B3459CD742CA7ULL, 0x0F81667C8E883DB6ULL, 
            0xB84737BEDA602798ULL, 0x77B8EE64324648C7ULL, 0x2F6805A78A6CDCA9ULL, 0x02907132FE4E784AULL, 
            0x39430BDBB1BED8F2ULL, 0x925329D7F04AA891ULL, 0xB1024A0D2B2588C2ULL, 0x80493C0EDF7ADB9EULL, 
            0xFBC0AF9E80AE2D0CULL, 0xCF795220EDE0AED6ULL, 0x84884297A41C1336ULL, 0x819FC029644B1F58ULL, 
            0x5FE397457D08DDB9ULL, 0xF533FA90E43631D4ULL, 0xCC165F56E71CF8E6ULL, 0x259BFB14FD08DC20ULL, 
            0xD5757FEF2DEE2D3EULL, 0x195347AA0200FBC6ULL, 0xAA29E7C96ECDBC82ULL, 0x38EFC376669B4E36ULL, 
            0x89472BBC809CF892ULL, 0x209B8C50D4A4826AULL, 0x9B9E4BCF69475894ULL, 0xF2465E79E2A451B3ULL, 
            0x82EC3132E94F7FD7ULL, 0x562F4478427C914EULL, 0xB64C41CD3EC69405ULL, 0xD290CFC58D1AD1FEULL
        },
        {
            0x145CA671CCF7FABFULL, 0x77C172F20E39DB6EULL, 0x64E05A13E6E7938AULL, 0x7EBBE2BAA5F88EECULL, 
            0x1194D906265413FFULL, 0x39503A4171E2435FULL, 0x2459B6A2192696D9ULL, 0xF37CB836C7A98147ULL, 
            0xC319563F74CF1F99ULL, 0x338A54AEEA9DFD34ULL, 0xB7F4603E57629289ULL, 0x5087863CFF0233CEULL, 
            0xFE243A39B62B9330ULL, 0x5FDDDC2D827C8101ULL, 0x70711E511B4F7BF8ULL, 0x85EF47303178E536ULL, 
            0xC2D35CEA7D77ED33ULL, 0x4533F33FF1992399ULL, 0xF1229184AAD5DB8FULL, 0xB8B6FBDF75C4A141ULL, 
            0xC35C3C702FE3F7F2ULL, 0x8ED50523AE4DFB97ULL, 0x1AD9A9A0E906CEFAULL, 0x4490D047325FD0AEULL, 
            0x37B5D44F5EC625E0ULL, 0xF646043F166123DDULL, 0xF1432156651570C4ULL, 0x236B33A789B5D694ULL, 
            0x53373B27723F78AFULL, 0xA469D3EE8F4247A5ULL, 0x1951AFD9A07096D9ULL, 0x7A6974F005A59CFCULL
        },
        {
            0xB1B9B8369C6A450CULL, 0x3827A1B3CEE8F3A6ULL, 0x6338DE1920D86E1DULL, 0xF9C949777930CCDFULL, 
            0x1CA579253478DFECULL, 0x3623DAB1119F35D6ULL, 0x8B8D123FB99401C5ULL, 0xAF6407840CC0339AULL, 
            0x9A954B00A29FBB82ULL, 0x3F81E56DA9D23ED8ULL, 0x781040A0528516D4ULL, 0x3A9B939BF4D044ADULL, 
            0x434598D40F27A296ULL, 0x07F4761F58AED89BULL, 0x2A1D052DD2E13507ULL, 0x8EE11FC3B182E508ULL, 
            0x78737537718A6D45ULL, 0xCECAF9D83F8241E1ULL, 0x43848F94B6B0F761ULL, 0x4325EBF634495C58ULL, 
            0xDDE14F425C4E0881ULL, 0xB72272CEE04820C3ULL, 0xAC6AA464B6A7A257ULL, 0x8788E0618BAEB84CULL, 
            0x5003B50AB6AD4C00ULL, 0x3D5121659FCA4D2BULL, 0xF555902CEFFEBC9CULL, 0xE81B8523D10B161DULL, 
            0x745088676C3C9642ULL, 0x728783CEC794873EULL, 0x6E6EC41B9C2D5BC3ULL, 0x22B0DA8B525745AEULL
        },
        {
            0x469F8433B403F52DULL, 0x6BB588703EF0BA2BULL, 0xA51286F467C50586ULL, 0xCA5A755AC3024863ULL, 
            0xDAB198AFA6AE099EULL, 0x813D78B8B56F181FULL, 0xC4F31E8C1CADCFDDULL, 0x5F916C3D949500ABULL, 
            0x988CA91567FEFC12ULL, 0xE60A3CDD93949F63ULL, 0xBD98DA3E72EB4555ULL, 0x1F8C86B67F4CABB5ULL, 
            0x60F5C12C630A755EULL, 0x75B503CBA1E588C3ULL, 0x4E6011746B585BC6ULL, 0x93FF1E1FC607C50DULL, 
            0xA38E3FC83758928EULL, 0x7AB2FBA0AC524CF8ULL, 0x77FEDBEC70425CEFULL, 0xC3E55A99F35C6C9AULL, 
            0xAAA5E1B9C9DC905FULL, 0xBB1C22A780AB861BULL, 0x3552623EFD6671BCULL, 0x41166527B29DF42BULL, 
            0x1A0100CFEB6C8968ULL, 0x906B86C0A9DBA3A9ULL, 0xACAF978315B8E804ULL, 0x1B0A8F5808558B72ULL, 
            0x88D413AD76DD85E9ULL, 0x8042103D7AFD2680ULL, 0x94AB45C26ABB512CULL, 0x8C624FD109FE2A81ULL
        },
        {
            0x9541E9CF098578D5ULL, 0xF7EC785AF3CF7FF8ULL, 0xA609AC129FDB458EULL, 0x987D2D6BD5F0F9AFULL, 
            0xECB08CB45248D834ULL, 0x480E6BEF6F05B0EEULL, 0xDFC690A7C4965BBFULL, 0x7F3F5B4CE585F776ULL, 
            0xC07BA6183E936B1CULL, 0xC6513B92605E1345ULL, 0x8BE70E2E0A4D37B5ULL, 0x89FEF13C8511478CULL, 
            0x8309857B15AF4F28ULL, 0x089CDFF1FF6CE83EULL, 0x84AC687D6FE05AEEULL, 0xB66D1BE8A157E81AULL, 
            0x9BD20EED2B59A13DULL, 0x535B915A8C659736ULL, 0x2EE5582D5C33B6BEULL, 0xAE3BC77629FD1868ULL, 
            0xC061DDC05C478312ULL, 0xD3CF216640988C59ULL, 0xAE0919FC4AD0C5A6ULL, 0x65FCE6517E2F0371ULL, 
            0xAF04D77D2111A626ULL, 0xE7E8497183629F73ULL, 0xC599E148313218CCULL, 0xCB78C70ECC25EB45ULL, 
            0x03FD5AFCC65FF34CULL, 0x924AC90062F7107AULL, 0x269E2D6CA4B604EDULL, 0xB983EC205E2A5AFEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseAConstants = {
    0xBFD17D0AC0B4F1F4ULL,
    0x000729A56FA91B21ULL,
    0x6A131868DE7A65D0ULL,
    0xBFD17D0AC0B4F1F4ULL,
    0x000729A56FA91B21ULL,
    0x6A131868DE7A65D0ULL,
    0x85EC6F3AC1AF1F7EULL,
    0xB523E382BA23C6FFULL,
    0x75,
    0x78,
    0x51,
    0x12,
    0x90,
    0x92,
    0x1C,
    0xC1
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseBSalts = {
    {
        {
            0x41DB50F396CD8A71ULL, 0x30C7C8DD3B51CBC3ULL, 0x10A5727316B63358ULL, 0x4ED2BBC80233B8C5ULL, 
            0x1F7F2E8DBF0E0F95ULL, 0xC517DAD02D8AF44AULL, 0xEEBFE41B2D5F4C38ULL, 0x433BBFA205EBA072ULL, 
            0x34C813649D79AFA1ULL, 0x1BDFF5674B2DB1E5ULL, 0xA04DBD4CCBCA14D3ULL, 0xD980CDE74F62AB64ULL, 
            0x9D8DFCDDFDACF098ULL, 0xC345F3A02395F28CULL, 0x48A27E55728E7142ULL, 0x884E68E762410210ULL, 
            0xF148C7D17428DF3DULL, 0x9F50062AC280E9B5ULL, 0xDAB432CF67DBA972ULL, 0x2C56792E4DC4153EULL, 
            0x59E5F42647E46299ULL, 0x1003C9FC95B8A96EULL, 0xCE8AD1FE85D6D8BEULL, 0x45F3EFBD294B9E10ULL, 
            0xC36BADB661C9265CULL, 0xD2725CF87FEF7292ULL, 0x5ADFC8CB7E5E4D6CULL, 0x6DA03CD574E039E0ULL, 
            0x8E7F8976D205E974ULL, 0x8D8DF5B7B4578E47ULL, 0x039B52024430424BULL, 0xD7E342DC524DC3C9ULL
        },
        {
            0xCC7864B2E935EBDBULL, 0x9888536EFC39CD26ULL, 0xCC28756881C4112BULL, 0x234859FC6AD02FD7ULL, 
            0x699863DD6E149477ULL, 0x9594F1D2A29130FFULL, 0xA656ACB14404DECCULL, 0xA945D7C250F97822ULL, 
            0x58DBA587816ADC8AULL, 0xEFF414FC24E0CE7FULL, 0x08F59F4F55573DCAULL, 0x32A166227A598785ULL, 
            0x217FB2A5C4A3B267ULL, 0x5260A6F13385BED1ULL, 0xF7D5CD1F6A32FA3AULL, 0xCCFCC4FA128EF50EULL, 
            0x1CDA1D9AA36A31DEULL, 0x31507F8C9A834019ULL, 0x5B1FF3CCEBBD52E5ULL, 0xA709F268912FAAA7ULL, 
            0x68DEBC8DA16189BBULL, 0x4D112B233EE96A3EULL, 0xA8EAD26697F665FAULL, 0xFB7175739750FE73ULL, 
            0x1B8A727A5CEDC860ULL, 0xAFC1D550F66F13ECULL, 0x52D7725910DB0BC5ULL, 0x58D08B2A8A60B96FULL, 
            0x76CC5FBEECC65AE5ULL, 0x22740324A506F43CULL, 0xBF91193FF16C0852ULL, 0x4BE3A7BFA70A8501ULL
        },
        {
            0x7B46458B4AB844FDULL, 0x9030D5B532FBE268ULL, 0x59E8B776487C4E68ULL, 0x38D3E03AEFB9E3BCULL, 
            0x9FA7D54DE33AA155ULL, 0xCD7D99ADDB13AE6EULL, 0xDE88DB5E6373529CULL, 0x8F28DBEFCD811F16ULL, 
            0x9674F1084536D05BULL, 0x9E43B751FAFB0199ULL, 0xB2A1709B6AB99EFFULL, 0x9141D2CB9200BD2AULL, 
            0xBBD76438BB8F1131ULL, 0x8B5FBBD07074581DULL, 0xBA9EAE130D038829ULL, 0x8766EB204B7122FDULL, 
            0x88D0E0E0081493FBULL, 0x28CFC30B82884270ULL, 0x6BDDFBD4225E63D8ULL, 0xFBEEF23EADCB4453ULL, 
            0xB3BD507750126BFCULL, 0xCF40F2E7B30788A3ULL, 0x54AF8E3455E992B4ULL, 0xA1996A8C6248F69DULL, 
            0xA62FCEAB43E6F29BULL, 0x90FC2C29E77A55D2ULL, 0x81335887260F47CDULL, 0xD8D95D1E33F132E2ULL, 
            0xF1D3B33CBFA745F0ULL, 0xF08C87A102A56069ULL, 0x129A6228F1574E13ULL, 0xC0C7EFBCEC40731BULL
        },
        {
            0x81DF9337D856896AULL, 0x21844A23E7BAA557ULL, 0x0B3343DC8B42AF80ULL, 0x938FB273D14591B4ULL, 
            0xB5A224904516F45BULL, 0x7A85C8A433192A95ULL, 0x927A25FDF4BD70F6ULL, 0xF9AE51C2A487B057ULL, 
            0xB1C6433562F265A3ULL, 0xFE966567C615F294ULL, 0x5A1F88E7EF77BE87ULL, 0x799B2CA7F36BCD65ULL, 
            0x8777E62575DBDFADULL, 0xB5FA40D72357DB4FULL, 0xD1C74388D50941C3ULL, 0x86276151E197ADC4ULL, 
            0x5C78834C8A12D487ULL, 0x5ADE84EF3642B888ULL, 0x43A81E40A44F61BBULL, 0x757D8721A811AC90ULL, 
            0xE825E56C9F99C4BFULL, 0x3DAF281D8D1AD496ULL, 0x3694D6B976E19F61ULL, 0x617AFAD5EF30A57DULL, 
            0xE255C043175A30C4ULL, 0xCE39F1A28970AD19ULL, 0x9C552459EA221B0AULL, 0xE4AB56DECAA9EAF8ULL, 
            0xCB473FC508D3F830ULL, 0x82904B885C8AFEA9ULL, 0xEB5B4FE16514B106ULL, 0xDC653DA35FD14803ULL
        },
        {
            0x783DE3EB2CAA17B3ULL, 0x9EBC16F0EF2B0EA2ULL, 0x520D19740A0BD678ULL, 0x9845FD421E79559EULL, 
            0x4C732839EC34B67DULL, 0x039CE387EED69FC8ULL, 0xF42162EED56FD7D2ULL, 0xC3F531A1D2164DB1ULL, 
            0xB2813DF50E8FD16EULL, 0xD511D053DD38D26CULL, 0x91865D9B9690150CULL, 0x0CCF8BFDE2088075ULL, 
            0xA1DADD4840EB226DULL, 0x5F498317BF6398ECULL, 0x647654D18E6608ECULL, 0x2C1F18CF4F8814A8ULL, 
            0xEC13D24201377701ULL, 0xF5700131C0ECE71AULL, 0x56DD0B3FF23A50D9ULL, 0xE1F9ACAB1A54D0C3ULL, 
            0xEC4523A35941C41BULL, 0x13D041106433E319ULL, 0xCA65F3C600976A65ULL, 0xDCDC844737CAB2DEULL, 
            0x952C55F458488938ULL, 0xB2A013943B72A669ULL, 0x98ACCE021A7865D2ULL, 0xD3EB09FADC206835ULL, 
            0xEA294EAC484D1F4FULL, 0x341CD11591D59C11ULL, 0x5C60632334A92993ULL, 0x2474AF16F7EB0630ULL
        },
        {
            0xAA45C62FF037CF67ULL, 0x0682053DB81A3B9DULL, 0xFA63835DA48D41DFULL, 0x95725FBE0749CC2EULL, 
            0x29B690CAE1082713ULL, 0x176D9DEECBBEB32BULL, 0x3EF73E906444563BULL, 0xE5D51A4C35FDA287ULL, 
            0x443CFB17BFAC877DULL, 0xC170B0C51DDCB008ULL, 0xCDFEDC51C387EC44ULL, 0xAD81826483968E28ULL, 
            0xDC6060946EC2669CULL, 0x84FEA61F7FCA875CULL, 0x5834911E0A56150AULL, 0x71B3585FBBF79F36ULL, 
            0x3B4A5353F46608C6ULL, 0xD22635610854B084ULL, 0x2C3E335BF328CB2BULL, 0x9CFD27717B0E338BULL, 
            0xCEF4A8C234FB4A82ULL, 0x2502FF6F1009D550ULL, 0x7F6150D1ACF00EE6ULL, 0x0E80C754EDE7B331ULL, 
            0x7FF283B418FDDE45ULL, 0x205B29A68F5AF124ULL, 0x0F02F675BCCFB803ULL, 0x2EADC07C40D0BCABULL, 
            0x2385730821FDB8F2ULL, 0x86F1BCF7276E55E7ULL, 0x23070A334D458A91ULL, 0x98C9A22EB4C49BD3ULL
        }
    },
    {
        {
            0xD7F8E6FC2D9471E4ULL, 0xA219E08E19180145ULL, 0x9A1228A33DF4E129ULL, 0x656095DE4981D4C9ULL, 
            0x98D52B74460CBB12ULL, 0x7B74CEBDF135B65DULL, 0x1FE26E425BB25D69ULL, 0x9B601B771695304BULL, 
            0x1AB5CDCE36648708ULL, 0x5288E5BAD874FE99ULL, 0xA9370DEB2EC1ED6FULL, 0x0824AB4481577408ULL, 
            0x870F71C54CF0EAAFULL, 0xB8B7C792EF28D0E0ULL, 0xDC6AC59955FB3E41ULL, 0xD516E5C64D51EC2BULL, 
            0x4985C73E9E2B88AFULL, 0x708CBCAFCE48055EULL, 0x04770380BD1201ADULL, 0xF9579AC3E71F8C5AULL, 
            0x319AF754C0917947ULL, 0x1D2B1A738CC48701ULL, 0x4578E481AF54634BULL, 0xE34E97130D8827AFULL, 
            0x616457B295E19387ULL, 0x10A4D83DA340D067ULL, 0xB6268DD60FA25E51ULL, 0xDAE12A48ED86F695ULL, 
            0x3721ED63817049B8ULL, 0xE279F943D55C34C8ULL, 0x1EBFE4D6C22BE1FAULL, 0x5A36F7F5EABC5320ULL
        },
        {
            0x34E30AF19D81F445ULL, 0xFC6A6BC643FDE9FFULL, 0x9F7FD29C7C4249EFULL, 0x4FA6E05DFDA58760ULL, 
            0x231318F473F86418ULL, 0xF01C892B7BD7705EULL, 0xC386C1BD3CEB92E9ULL, 0x3C3CFDBF105A7FC2ULL, 
            0x5B9E54B894A2B418ULL, 0xDF50DA22136CB879ULL, 0x7496F5D1BABB7CB7ULL, 0x2E6A7D7ABCEA964EULL, 
            0x29832A415AF611F4ULL, 0x91190F44BEB4FE2CULL, 0x6CD88DE4D472B4C4ULL, 0xB0DADF33525FBF68ULL, 
            0x7C068FFB20EED3F7ULL, 0x7DE06C25FB305BE0ULL, 0x94AFE2C3A2507BE2ULL, 0x5DF4197B1D7F93ABULL, 
            0x3A32BD8A39AE9AD6ULL, 0x94C44B0604E4266EULL, 0xF4E9FC2FDBA6DA36ULL, 0x0390DA3F238783BAULL, 
            0xCF866989E29C2AD3ULL, 0x30AD91E77DA8A023ULL, 0xE0479A13B57D3B5FULL, 0xAEB46693992972A1ULL, 
            0xE7C4B19773730062ULL, 0x0881CA5864002F52ULL, 0x9C9C7E288CC502A9ULL, 0x442946DE2E59653FULL
        },
        {
            0x78B5DE34A07D2679ULL, 0x13C9507737D6B76EULL, 0x3801C1E3F86B3016ULL, 0x974D1CAC3A1FB88BULL, 
            0x5163B4354789B82DULL, 0x38E461F6F909ACD1ULL, 0xC2E6C0B1420B4D62ULL, 0xF790E30ED1E4F1B4ULL, 
            0x70A9729EB14E6380ULL, 0x421B3821793E895EULL, 0xC6C2FA8C7CF72DA7ULL, 0x39E09C6F89F6E3FDULL, 
            0x40BF802A3CF30A7AULL, 0xDE6FC6487C19C7C1ULL, 0xF0F07C7F9FE98C95ULL, 0x25E5C9EA17756D71ULL, 
            0x27B497D35F0FA7BFULL, 0xA3F78FB54AB43A7EULL, 0x837D6086EA834D5CULL, 0x9F1893EB0695A2FFULL, 
            0xD5B6B40E92D5F15FULL, 0x1F552CBC823D7268ULL, 0x06C0D67279BE7B00ULL, 0xFB433F11F7F0C284ULL, 
            0xBA2E7E9B51FC1408ULL, 0x3F957DEC2C4EB578ULL, 0xF69C9D846639050DULL, 0x52005B397BC84FB7ULL, 
            0xF9CF8CB23D8E690AULL, 0xEB13CD26F3544483ULL, 0xDF3C2615AD7ADCD6ULL, 0xBBB481003DA86A58ULL
        },
        {
            0x400AF752C2C1C952ULL, 0x2ED48798FA00FA23ULL, 0xBB8EC5E9C4125582ULL, 0xD47FBF9BCF8746EDULL, 
            0x5BB38133B54E1787ULL, 0x616E06270F62439EULL, 0x475A0547748A22F1ULL, 0x37E3F0C5305A77A5ULL, 
            0xA2BEDA9AE3FDC27FULL, 0x5EA3DC8E9B8B2EE4ULL, 0xE8664490E8CCBC45ULL, 0xDE8E683585BC3CB9ULL, 
            0xDBA56D4434F00795ULL, 0xD49F76C909633289ULL, 0x197E47C5C5230AD0ULL, 0x4208D373048CBA65ULL, 
            0x3F0A13F0491944B9ULL, 0x64094EC9FE8A3AADULL, 0x7E61DF233CF3AB84ULL, 0x0DC4217019D4EC3DULL, 
            0xB815F165D86CC306ULL, 0x1D3C7D68730E34DCULL, 0xB42A480C752D27BFULL, 0xBAC9ED543BE0C367ULL, 
            0x722130E53021DB0AULL, 0x2C3274D64B393490ULL, 0x8828775CB107085EULL, 0x9F64E38C36FC2110ULL, 
            0xB230E8227618975CULL, 0xF91837947784D32EULL, 0x8648B773A9EEFD6AULL, 0x9FC7B35B99EA4698ULL
        },
        {
            0x356835E499EC4703ULL, 0x16C7057416D8B481ULL, 0x924FDDEE47A17548ULL, 0xA27EB1B99BD6520AULL, 
            0xA9C5521F3B5BF904ULL, 0xCE346F7819390175ULL, 0xED4DE2B21F12B027ULL, 0x8A15F5F9DD395293ULL, 
            0xDD62B9ACBAB94820ULL, 0xFA132702C41AD083ULL, 0x429DA8AC700F5735ULL, 0xFEB9598645466842ULL, 
            0xC190B362355ACFC8ULL, 0x2C462F51926C2233ULL, 0x6D9C75C43E948920ULL, 0x683CDCB67D5DDCBEULL, 
            0xFED7E8233C594940ULL, 0x16D95127D1DA612CULL, 0x437C469230FC87A5ULL, 0x9364DA08A8577585ULL, 
            0xFCF7F1589C594021ULL, 0x56859461951BD302ULL, 0xEECF5B1895071BFEULL, 0xA4835626644F5193ULL, 
            0x5B6FDC2174C4C932ULL, 0x8199C24702374188ULL, 0x03B5F2F74E8A4650ULL, 0x9DB115860D2DBF0FULL, 
            0xEEDF7C79FF35CBA0ULL, 0xD804F39F269BE05DULL, 0xA93164CF9627214BULL, 0x451FFB1BE5504145ULL
        },
        {
            0xBAA09A8D101B4911ULL, 0xA1FD301A01254F2CULL, 0xD09BDA76BDC18E6BULL, 0x948086F1CB83D892ULL, 
            0x0684A4A151C9C47DULL, 0xAF26FEB8E181D274ULL, 0xBC0EA1AABD53A78AULL, 0xCC2484B0C4F0FE0CULL, 
            0xB33ABC06B61DE92FULL, 0xD2697D9CFCDF97E2ULL, 0xAE8FF11750EA4062ULL, 0xBEB354F48AE8459EULL, 
            0xBC6792DC1915D0CEULL, 0xE55A1B3F9DA17768ULL, 0x7547EC58FC7DFF10ULL, 0x33B927DD6213E054ULL, 
            0xE8ECBFFDBB3849E9ULL, 0x7BBD102ECDDD7772ULL, 0x8B5C6FA456DD3F07ULL, 0xED8617AD90BDBF13ULL, 
            0x155B13C1BEB3CC31ULL, 0xF79F8CD467D7DEB8ULL, 0x11D664063B844BC4ULL, 0x130A10FE26D02433ULL, 
            0xF9E123F630CC28E3ULL, 0x77C6949402A91778ULL, 0x6D53B6376188787CULL, 0x13E5EA5014501C49ULL, 
            0x63B5CDB07AE943C5ULL, 0x663213F4E567D992ULL, 0x49FF8422046AEE70ULL, 0x38124C1E3C851FCCULL
        }
    },
    {
        {
            0x062034D8E6AA556EULL, 0x071B10BB45E49605ULL, 0xBD30984B08974C56ULL, 0x52DB9B20F8640787ULL, 
            0x455E0886D9489BD3ULL, 0xA0DA28DBBEADB27BULL, 0x968D5A32C8DCBDA4ULL, 0xE5A1C0D8055789CCULL, 
            0xBA72E17EE82A3577ULL, 0xEB3D89BBFD8A773EULL, 0x354AD34F5CE76546ULL, 0x526F32B52B5F0417ULL, 
            0xC78420934C1CC898ULL, 0x85213A3439F2FBCCULL, 0xB1FDDA5F8B87D105ULL, 0x2F249F91BC4669CAULL, 
            0x145AA6C0CC136749ULL, 0x30386BE6E848853AULL, 0x950EA5874BA3A3CAULL, 0x01A63B06B6958D53ULL, 
            0xE53C717AD50B9AC4ULL, 0xFB372BB4AE3ADAF6ULL, 0xBB785B786B1338A9ULL, 0x583285A649653225ULL, 
            0xCFB8385F7DD71CBFULL, 0x54F6BE04B4B923E2ULL, 0xAA15F89748C3E61BULL, 0xD629B4FE7D86846DULL, 
            0x11D5AA207046EE20ULL, 0x0345DAE5E7BDE7FCULL, 0x482359716FF23764ULL, 0xCE752DBBA61AD042ULL
        },
        {
            0x8F294688582F168DULL, 0xBC57A722E628C66FULL, 0xF51EEE5B560D83ADULL, 0x26D1A9349C4752BCULL, 
            0x701538DD30ECE63DULL, 0x9B803390B8B03863ULL, 0x3D12E4ED58C98ABDULL, 0x2D5A6CE968BD0F71ULL, 
            0x1A675ABB44C8A051ULL, 0x8B3B67A490C12612ULL, 0x44923EEB7A7E0079ULL, 0x42EBB0450B7F94E5ULL, 
            0xF6DAA91449B53749ULL, 0x693D1A68C58F2F04ULL, 0x5D93D0098873DA7BULL, 0xA11D9308AF8BAE97ULL, 
            0xE64196D6B66B6E62ULL, 0xE1058D25D5C2A8B7ULL, 0xC59A96AD7AA6C7A1ULL, 0x6FFD8BA44BB136FAULL, 
            0x7BB84ABC482B46C3ULL, 0xB9D6D1BB03EEB066ULL, 0x700B5B13873DA4A2ULL, 0xB2A7D58E7FD7E073ULL, 
            0xE569FA6F7D2A4D74ULL, 0x27578F5FC8207070ULL, 0xA930ADE2041B0879ULL, 0xC5274E4908A01DFAULL, 
            0x9D4CC98324905CA3ULL, 0xFEB71EAF5A5317C8ULL, 0x24FFF96115B23D17ULL, 0xDA0ECE06E583637FULL
        },
        {
            0xD010145BED3BBC87ULL, 0x0C15E26911447859ULL, 0xD425AB0D8F241FD1ULL, 0x66D91ACB07E9250EULL, 
            0x31E9134D094FBC17ULL, 0x925FD5F8F2F5ECD8ULL, 0xF58D6926BD960A59ULL, 0xD36D1EAECD7DD14EULL, 
            0xA1970D22B6E6EC58ULL, 0xE39AC6040039C7F9ULL, 0x0FC7BDD99E0C94EEULL, 0x0E79DAAC4E78F177ULL, 
            0x23829883BE8E6D93ULL, 0x382BA8D299AAB381ULL, 0x336E0D2FBFF9E084ULL, 0x8DDB0B411F2494EFULL, 
            0xD84D76078D84DDDEULL, 0xB62A09752BF5D149ULL, 0xDA3FDDCD4B4D5A14ULL, 0x859DC4BFD429F3C4ULL, 
            0xC2AB9CAA991834E7ULL, 0x794C076F359014DFULL, 0x6ADFE78D0F4B4767ULL, 0x8736C0379C9A7D37ULL, 
            0xA275667B911F8771ULL, 0x01280FE13B998F0EULL, 0x1E2A6BCC9EFE90E9ULL, 0xEA32B02BB686A13CULL, 
            0x67B2E1BF20E4B069ULL, 0x9FEDA3CE0A780B7DULL, 0x90CEB49358BF31A6ULL, 0x9DB7803D6793648AULL
        },
        {
            0xA98B846CDE366276ULL, 0xE64BFB3EFB3C2F9BULL, 0xC321121F570A83FEULL, 0x3AE0381F5548BB85ULL, 
            0xC9A603FC22F2A5F9ULL, 0xA32821107D569FBBULL, 0x6C80B4ADCA5F8F10ULL, 0xDB7F4BF8020E85B2ULL, 
            0x218F1DBF1222DE67ULL, 0xD539BBD210F214ECULL, 0xA107D493C3B95C0FULL, 0x54809F52DFC7B66DULL, 
            0x0F47CAC76B6CE6A8ULL, 0x14BE4F6AB8A1E86AULL, 0xFFA97CFE0F718C8CULL, 0x892AB3113B56C29FULL, 
            0x330F18DADBE1347BULL, 0xADA6BDCB217E1A4BULL, 0xC373194C5FC56249ULL, 0xE39C8AA02AD5C085ULL, 
            0x8A344019ABC5709BULL, 0x2FE931816F76C943ULL, 0x2D8C5265B702EDCCULL, 0x08696C2D1F8E0255ULL, 
            0xC615776D9B654068ULL, 0xC2E22020F86785BBULL, 0x5226BED519BB5111ULL, 0xA61303436634CA4DULL, 
            0x91A12351C3FB0F08ULL, 0x71548BDAAFB076D3ULL, 0x4D695F86F9C9AACCULL, 0x21BDDD928D108517ULL
        },
        {
            0x97B7BB8616904BE5ULL, 0xD6C55DF58FEF4D67ULL, 0x5936A27131FB9883ULL, 0x733D0DA62463E298ULL, 
            0x69BACBA7EA205E3AULL, 0x30CF9FA347443CA5ULL, 0x4B573E9830C31EA6ULL, 0x773C88C89ECDFF22ULL, 
            0xCCCB4FCA1F597207ULL, 0x884594FB35CBA754ULL, 0x19DCFC35B3347C30ULL, 0xF0C8CC7A072B437FULL, 
            0xCAA84CF9BBE56BF8ULL, 0xE7540AD5A81878A1ULL, 0xC8CDB227342F33E0ULL, 0xC2A26D4ED482FACEULL, 
            0x784C9D4BD9FE094BULL, 0xD99EF0DAD332CD20ULL, 0xEBADF52E94FF34ECULL, 0xF3706A48837088CDULL, 
            0x4EF80CADCC8351E3ULL, 0x66D0F382D4A48BD7ULL, 0xADFC6C01FA4376B1ULL, 0x0CCBD8BEA448215DULL, 
            0x3433951BC4AF131FULL, 0x896D22B4A96411C8ULL, 0x9B622E16DD59607BULL, 0x2E2A82E69A04DE76ULL, 
            0xD7F99E7FC5BAC858ULL, 0x6D23473BE9CD2C10ULL, 0x16881394DE93C8B4ULL, 0xAC19A74F18A7AAE1ULL
        },
        {
            0xFEFC1232A2C683E9ULL, 0xDADFF87788A0C724ULL, 0x76EC60BCBBDD33B7ULL, 0x04EF733AD856FAD6ULL, 
            0xF4FD0EE85B253213ULL, 0x552B5EA0FC930493ULL, 0x8DFA2C80466080EEULL, 0x640F552BE9938D06ULL, 
            0xECFE35BC1519AA65ULL, 0x1871FD0A67728210ULL, 0xAF6CD135B3426B6FULL, 0x462B14490ADEA35EULL, 
            0xFDEE68969C5CF5D4ULL, 0x88BBB73D41CA62F4ULL, 0xF04E4CDE378D63D8ULL, 0x89FFBAB1B29A39D6ULL, 
            0x677F262E22956C68ULL, 0xCEF80C14A8166E1BULL, 0xA1EE55EDCB4F7A95ULL, 0xECF26A7C87F6A7ECULL, 
            0x8A3FBCDE00668A97ULL, 0xC3063AAEBAF07BF0ULL, 0xF0E23065E7A3C97CULL, 0x7369FFA125E62D3DULL, 
            0xAD33C609B7A3F966ULL, 0x07D161A09F7D30F3ULL, 0xC784DB347B7DBEE2ULL, 0x3D14F82C0350B48DULL, 
            0xB2208CD1B5176726ULL, 0xA0CBDA4B89D42D13ULL, 0x7683BF283A5EC3B5ULL, 0xB946CC08B6C493B9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseBConstants = {
    0x4EFE48D97907AC0EULL,
    0xEF3C200B49ABD8F1ULL,
    0x7D9603193D0CB2AFULL,
    0x4EFE48D97907AC0EULL,
    0xEF3C200B49ABD8F1ULL,
    0x7D9603193D0CB2AFULL,
    0x3E9E76A2E0F25320ULL,
    0x31F466EA33C83360ULL,
    0xA4,
    0x0D,
    0x08,
    0x4A,
    0xE6,
    0xCF,
    0x10,
    0x52
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseCSalts = {
    {
        {
            0x132CFD81E0C8A535ULL, 0xEBD4091F181671D3ULL, 0xAD6AF3D07682650AULL, 0x113153A9B240DA29ULL, 
            0x6D8125108875FA17ULL, 0xD486CBD856E1FA6FULL, 0xF35DC771438E2896ULL, 0x5CBF54572542EC01ULL, 
            0x84D9DDE2DC9D08E7ULL, 0xA4AD450A8AF72931ULL, 0x8F5CAE125E75ACCCULL, 0x176D6492248E1934ULL, 
            0x26221D93DF9218BEULL, 0xA05B835190D2A6B1ULL, 0x0D5804978130AF0AULL, 0x5ADCB2BB2537C2C1ULL, 
            0x52BCEBA164870478ULL, 0xFA677239EF0B4B6EULL, 0x5C1883E0CB2ED7C8ULL, 0xFB44530E381EF831ULL, 
            0xCD8931ACBE679621ULL, 0x33E35F471A3335D6ULL, 0x870E6A0686013A1EULL, 0xB00B443B32C5002FULL, 
            0xFC2B6714ECEF6D2DULL, 0xF42C19359F1E79BBULL, 0x066ACE97E6292DC2ULL, 0x0511F35C512E42CAULL, 
            0xB9F6295BA641AC11ULL, 0x4719CA44180F37CAULL, 0xC7A0587FC66DE217ULL, 0xADE0773D4618EFDEULL
        },
        {
            0xCDAC677C7FFB015CULL, 0x0DC66670C0155F57ULL, 0xBBD448121B65FE50ULL, 0xB7D56261C630BE5BULL, 
            0x476E4E26AE2EA326ULL, 0xEDBFE5C17E810D11ULL, 0xC1170922FD567855ULL, 0x610570F809505439ULL, 
            0x2BD6CFB8C5A086C4ULL, 0xF883DD9B2545976AULL, 0x731034F90F342034ULL, 0x665AB4841D0CC454ULL, 
            0xEEA034BABCF36C42ULL, 0x2BCA41DC25737CCDULL, 0x1FB5A7C597F8E8C9ULL, 0x9E0657EC40B00DF3ULL, 
            0xDB155C532A91674CULL, 0x2C974A2B7C4FD76DULL, 0xE6BC69E14F4AEB30ULL, 0xD6E66108FC4E0C6AULL, 
            0x77657F87C32D18CBULL, 0x966E1EB6169BC62BULL, 0x572055BA64E6162AULL, 0xA00BBC4ABC24B684ULL, 
            0x39FB2AB99C11F946ULL, 0x22D458C65595DF8AULL, 0xBBA6AA7A9FEE36FAULL, 0x602A510DFCDBE443ULL, 
            0x7A2380CA38AD2C32ULL, 0x20701BB135F38305ULL, 0x2582255095E86376ULL, 0x385AC44ADD493252ULL
        },
        {
            0xDE9DDBD6E26E7A58ULL, 0xDA42B12EA09B1824ULL, 0x6261BA48023272CDULL, 0xD8AF6F4FC715262CULL, 
            0x6C29059F3BE54C13ULL, 0xAC92823F3ECEC70DULL, 0x2FD3AB2B312A060EULL, 0xE1662595FEE3FF8AULL, 
            0xFE815E07A800026FULL, 0x85BF51DCF22A980DULL, 0x8615074BE48E8F47ULL, 0xF1EA1C6C3D604696ULL, 
            0xC4A44BC0F5234464ULL, 0xD2D7F1035431C0F3ULL, 0xA9B0FAB3A0C7AB1BULL, 0x326BD26E93F887FCULL, 
            0x08619150FAFEAF7CULL, 0x2EA7DA491E5EDB42ULL, 0x6BA756E9A20E7921ULL, 0x9943216FCEC72932ULL, 
            0xCC653A5B0FAE63BAULL, 0x095867F0FD0941DAULL, 0x737772A2923E8DF3ULL, 0xB43E96383809D72BULL, 
            0xBD96E262FD0C4633ULL, 0xADF80FF1400A0DB3ULL, 0x01076F213DF03B70ULL, 0x2BFF8EA43E47D23CULL, 
            0xACD9037FD144F31EULL, 0xDADADBB2DF0822C5ULL, 0xF4AC6D9CBAEDF52FULL, 0x1AD6B3ECA92593A0ULL
        },
        {
            0x7CEDD32F217A063CULL, 0x9020B7C83F6FADDAULL, 0xBCD93B15BD2B968EULL, 0x81214FCEDCFE4068ULL, 
            0x9EF1754F4F040087ULL, 0x073790F0A371EABFULL, 0xC0EE19451AA416E0ULL, 0x9C4105515D907EC7ULL, 
            0x015693F18CA045DEULL, 0x1063AE7171988E16ULL, 0xF86275BD459ED783ULL, 0xAFD7A8FD04E4E1B8ULL, 
            0x3E8C2D1C3DE0A208ULL, 0x0AF4FA6507469F19ULL, 0x1783CE64FFD0885EULL, 0x436A7A4A240B9475ULL, 
            0x8E19B25E1D93DA1CULL, 0x2DA9FA24B8B4A05DULL, 0x64757027DEC94589ULL, 0x072BA6F8F12DAF3CULL, 
            0x39B4319BFE51772BULL, 0x33BF8A29E68E7C31ULL, 0x9CBD39B01F6A411CULL, 0x1D0165F9E429F28EULL, 
            0xF313637C574691E9ULL, 0x00C51B5C1B3CA217ULL, 0x829B8228A27D341FULL, 0x98BCD8AB3AAF9483ULL, 
            0xFF82DD382989A449ULL, 0x7229715D80101DBBULL, 0x6C4F5D2834715D5AULL, 0x0D1FF7367178A0CDULL
        },
        {
            0x3E11ED9E3673BF60ULL, 0x66EB2164F92A410AULL, 0x75CEA3AD9935652DULL, 0xDD9B364A816B8784ULL, 
            0x855FD7434FB1666EULL, 0xBA35B3D6FDDFDD0CULL, 0x1BE2782AF2C6C1E4ULL, 0xEED8D8771F953FE2ULL, 
            0x4B462FADB6D338C5ULL, 0xA4A4BFE7EEC02432ULL, 0x2ED8AFAF1683125CULL, 0x4E0FF38B80B3A5CFULL, 
            0x801370CA59A80347ULL, 0x32DDD465BC8F701FULL, 0x555A97B02473A321ULL, 0x907CB12AB03CF2CEULL, 
            0x93582B010149A64EULL, 0x261F577EF1EA2A9AULL, 0x88FF0DC8DB385EB6ULL, 0xFBC920A71B0C2FE5ULL, 
            0xC2305B2CD6EB7251ULL, 0x85758ABF65F9893EULL, 0x3C1966EEF5BE6661ULL, 0x7E71EE2E88E30DD0ULL, 
            0x4029D073F69A8316ULL, 0x999B727A6578B353ULL, 0x9FF8DDCFCEB0B3ABULL, 0x27AE963CC51897CFULL, 
            0xAD5086F7BC86CF17ULL, 0x324920194FDF86C3ULL, 0x53B63D8238198791ULL, 0xC421E3747D97FA3EULL
        },
        {
            0xFBF9360E12B15AB2ULL, 0x9253B8D560AC4BE4ULL, 0xBFE54ECDCDAC2539ULL, 0x47207ABC357D614CULL, 
            0xBD6AEE2E0EEFE05EULL, 0x4D10B993B82E25A8ULL, 0xCF1C4A919D9A96C9ULL, 0x76C0C12F5DC54CADULL, 
            0xDF716BB0A17430E4ULL, 0x92A51CB064BDCA58ULL, 0xF2E010B673880E2FULL, 0xCB76B61C12B644F2ULL, 
            0xDA2B9C84239BFAC8ULL, 0x8C8C1F70E7656E87ULL, 0x1ADE856DCE1E585BULL, 0xDE32F8568F2986D0ULL, 
            0xAADCD42011A21297ULL, 0x6D5413945359FE5EULL, 0x5DF04B61E88BCC3FULL, 0xF79330283BAF57F2ULL, 
            0xE33F65459F428459ULL, 0x5C11DAE2B39DAD51ULL, 0xE7B5117CD7F02749ULL, 0x7E1EAE5FD9735CEAULL, 
            0x82FFC8511599E8F9ULL, 0x4F6C02C61498C8C1ULL, 0x76BBDBE0964543B7ULL, 0xF64274517CC8A01BULL, 
            0x807BB9598DAC848AULL, 0x5356197E287C8E14ULL, 0xF9CD7D67D4D109B2ULL, 0x5A1A1495C1AA0709ULL
        }
    },
    {
        {
            0x43AD7177BA09663DULL, 0x29DA56FA80479FE0ULL, 0x3D51A2F1470EF5D6ULL, 0x7E14CA5A8AA97A24ULL, 
            0xE7CCC48C7191A9DDULL, 0x15B695C8271D66D3ULL, 0x312CEF70F41E0FC6ULL, 0xF39F29674D1C5FC2ULL, 
            0xD9CDB09447BEA5C6ULL, 0x8A573C31079C3086ULL, 0x2ED2004134E9594FULL, 0x273A1C82BF063A27ULL, 
            0x22098D4F41CA44E7ULL, 0x497055A9FCCB1A11ULL, 0x860C7CBF191FF381ULL, 0xE1FCB183AA6436C2ULL, 
            0x3BC487B6582CE2F5ULL, 0x242995A5CABE27C9ULL, 0xB48F57F20187BDC5ULL, 0xE652B4E2EE03F722ULL, 
            0xC408A99C581523B6ULL, 0x31B6877597B1EAE5ULL, 0x3E8BAA015D4F3F59ULL, 0xD45A73A21FF42E61ULL, 
            0xAF0C33F37CFD1764ULL, 0x5F87C6BDA7BADC0CULL, 0xC3B92314CFD5B053ULL, 0xA42D3BC314C1382DULL, 
            0x9EBF32CCABC2A80BULL, 0xCB9CF0B9AB5133C3ULL, 0x5E547355B21CAE04ULL, 0x8C843B8743D7FA47ULL
        },
        {
            0x1D723C2D5A09EB50ULL, 0xAB329F13A95A8BB6ULL, 0xBBB353AC47C00A0DULL, 0x5C4CB97F8698086EULL, 
            0x720E2C0A65BCFD27ULL, 0x9CFC16C40E7F7CC7ULL, 0xC8B6E70D74321881ULL, 0xCCBA4BC27171DA70ULL, 
            0xD048C413097B2419ULL, 0x1E35146B0401F7AAULL, 0xAA0D903B1B07CB25ULL, 0x6F6B0362A4809870ULL, 
            0x5DAC601AEA37AA8CULL, 0x1C663D430BA7AF96ULL, 0xE39479E012B19EE1ULL, 0x4523ABEE2C830BC9ULL, 
            0xB5BC8914AFD723A5ULL, 0x589774D91522B481ULL, 0x1F980E1076A5F61DULL, 0xD17E549F469C5A21ULL, 
            0x2A76DAECA5D6FAC4ULL, 0xE638A8264D98CDA7ULL, 0xDC4F290584ECDE3FULL, 0xB770DFA4C1CA3FF4ULL, 
            0xADC49B80D988BD00ULL, 0x3B2B68A49276CA64ULL, 0x817108924397C06FULL, 0x5AA87706E0B81F7CULL, 
            0xA7D0927AF0A2C075ULL, 0x2BD746BDFAA1D68CULL, 0xC9BE5FB2996DF5A4ULL, 0x6003B758EB666896ULL
        },
        {
            0x718C1392244B2D18ULL, 0x03424933BDACF04FULL, 0x9D45217BAF43B616ULL, 0xC7BFD8657B41A7C9ULL, 
            0x4AA987CF9EB78A86ULL, 0x4C2C54960EAF7562ULL, 0xF0FA711565CBAD5CULL, 0xEE1068FE2AEA653AULL, 
            0xB1FCCC37B8604F4BULL, 0x6182F7859534070BULL, 0xEE02427FB501BC52ULL, 0xD65A2A9C8FFF5560ULL, 
            0xC8230C185191F942ULL, 0xAB28D962951CEA63ULL, 0x79BB60B7C81A2F79ULL, 0x648AC058BD09ED73ULL, 
            0x8F39E7C73A3897A1ULL, 0xDE0B7982B10E11A9ULL, 0x8F48C00E7BC93537ULL, 0xC41D80A55E4DD764ULL, 
            0xCA0E46DA9FE2948AULL, 0xBB045176DA9F04B9ULL, 0x0305890A62FCF252ULL, 0x154ED7B1E09B9097ULL, 
            0xFF1FB99318DF0AE3ULL, 0x21DB36894D0A2FA1ULL, 0x41BBAE405FB4CBB3ULL, 0xEA304ED79128B7F9ULL, 
            0x1FF6623AC82D5957ULL, 0xB6220FD9B5D75E56ULL, 0x31735CC5E79DA83BULL, 0x0705BF775D8191B8ULL
        },
        {
            0x2574D99CBFC9FD4BULL, 0xEE48BCE786A0E6B6ULL, 0xDEE5A91E205DBC34ULL, 0xBCB9812AF1D67393ULL, 
            0xC81EA85D0426B0D5ULL, 0xFC7458403E8C8307ULL, 0x6F8B75CC177E5538ULL, 0x5781E190CC7662DDULL, 
            0x7C401295862BB9FBULL, 0x638B2396FC44FC35ULL, 0xDBF51340675187EFULL, 0x43D6BBAB42CC6013ULL, 
            0xFD735911F36FDF83ULL, 0xA501B73E9F4332F4ULL, 0x4F5CAB0D562DD87EULL, 0xDF87F7FDA8890787ULL, 
            0x656C6E545AD90F4FULL, 0x0A85574E70D4E25DULL, 0x18D285021BD4F7B2ULL, 0xA84D63F65E088456ULL, 
            0x93416B86856ABCE6ULL, 0x8639AA2655ABD260ULL, 0x65C3A66F88B6DA1BULL, 0xFED1FE273B3A61F7ULL, 
            0x388E424B934A1790ULL, 0x544924F9D130E07DULL, 0xB0D75D59C9FE4BCCULL, 0x3FE28A5BEFC18E4CULL, 
            0xF2758FF5B5AAF68AULL, 0x3D3A042422969A92ULL, 0x3F1C5F7366C97575ULL, 0xBC595CC6FE9BE23AULL
        },
        {
            0xEF40F2D855F982B7ULL, 0x1BA2ADA4E283DF01ULL, 0xFD281C72D39796EFULL, 0xA3604959D2D450DEULL, 
            0x0168E55BB07376E2ULL, 0xFE9DA213A1958999ULL, 0xEB73668EA89625C1ULL, 0x72E0401211ED968BULL, 
            0x291F68A643A8C42AULL, 0x33368023EF47100BULL, 0xC96CEF30308D14EDULL, 0x8991618CD42D4F78ULL, 
            0x08C18284A07B7CA1ULL, 0x8BCAD1547324B0B8ULL, 0xE24E00C8B296F4BFULL, 0x2292461FC441BA47ULL, 
            0x9C2992453830FD4BULL, 0xC8D652062A1FA785ULL, 0xF6FE85A738AD87A2ULL, 0xBA0272BF119B1C3DULL, 
            0xCCFA3511E9320AA1ULL, 0x5C02B6B0F1841292ULL, 0xB5AD1C73398044E6ULL, 0x346EE5D5983BAE57ULL, 
            0xBB573E7CB2BAE02AULL, 0xAC8C7333447D7BE5ULL, 0x3FF13C14A372C156ULL, 0x4FEEB28C168A006FULL, 
            0xE61C02677ADB97B1ULL, 0xDA5D26E6A1624332ULL, 0xF25F7F5DD675F75DULL, 0x7F7FF2246CEA8001ULL
        },
        {
            0x0AEC9938A89C443EULL, 0x9775D63BE6BD286FULL, 0xF953BAADF51A41ECULL, 0x4D8F2A3CB82AAC5AULL, 
            0x44A8CE91C20D26FBULL, 0x1F22D878D27F1E29ULL, 0xEB713E00A64594DFULL, 0x62562223B3362AEDULL, 
            0x481603CCA90B7A55ULL, 0xD46997960A16E4E6ULL, 0xC854F415BBD8064EULL, 0xF4D919A4606A5CABULL, 
            0xF773CDDD094C5FE8ULL, 0xE717620176D9A966ULL, 0x6677A84404A2C90FULL, 0xB549C323436122A5ULL, 
            0x8619C0E0FB506496ULL, 0xDB61724B4892CA4BULL, 0x4972CCD67F4FD85DULL, 0x46AA25D0EA57E59FULL, 
            0xAF67277B6EEB5C1BULL, 0xE4D7E7D73380E656ULL, 0xA69ECA07231764DCULL, 0x53451B0EA8E5F957ULL, 
            0x9BD8A23905598D8FULL, 0x4C256EAC36D45842ULL, 0x6A01003AF65E8874ULL, 0xF32FDDA4F93B9717ULL, 
            0xC45424893D2E6426ULL, 0x82AF6E827B4CEC19ULL, 0x3B17675319BECE42ULL, 0x674A19ACDBD29A77ULL
        }
    },
    {
        {
            0x713A82005674FE64ULL, 0x954E116C41D2B428ULL, 0xEEE0D1C1C47E019AULL, 0x57F85B1372FB9A27ULL, 
            0x629C4344D9F863B0ULL, 0xC37338426CF81A2DULL, 0x7D62D698A7D6141EULL, 0x2301D034C9622DE7ULL, 
            0x64112D3A25175AC8ULL, 0xD767E30C274BB7A3ULL, 0x167B67B9F9FD1F05ULL, 0x59831F3ECF036038ULL, 
            0x88A1CD20F069DBE5ULL, 0xE9A2213419B0ECF5ULL, 0xE7A8378B7B4F73F3ULL, 0xAAE5971966D17ABDULL, 
            0x5290215DA575FA2EULL, 0xC9F002E1C1D7BB22ULL, 0xE81966A67A3EBCD3ULL, 0x709BF47756829B91ULL, 
            0x57829CFF85098531ULL, 0x961F266CA9B70F90ULL, 0x2B60C439934957C4ULL, 0xFD3DECF018E8A57BULL, 
            0xAFBEAF63E7B6B02DULL, 0xCB86257288DFB6D1ULL, 0xFCAA14A327CF825EULL, 0x4175B6B669055FEDULL, 
            0xAD705D8B8807E779ULL, 0xAA6EF057053B92DCULL, 0x19AADBA2F2BD1B6FULL, 0xE48CAB19EA1C3C89ULL
        },
        {
            0x342B75D4B7271857ULL, 0xC0679D0BAF2865D8ULL, 0x5FB2CE63680EE88BULL, 0x8BA0ECA59FF43896ULL, 
            0x2BCC6E9CC4DB5197ULL, 0xEBA89A6A8AD4A6DFULL, 0x26844AF83CEEB842ULL, 0xC9DE704A3B3BBE04ULL, 
            0x7CA8A0CCFAD7C0EDULL, 0x52F9BCA719050349ULL, 0x4694C611AE4B0E3DULL, 0x8DAC027FDFA0A5A7ULL, 
            0x326BC7CDFDD41FF5ULL, 0x33B52D58E01DA5F7ULL, 0x9C7515CCE535985BULL, 0x2A3D5344BB57F741ULL, 
            0x4DFB716FC1BB9FBAULL, 0x0D34448BF6A5D2C5ULL, 0x137195DA8162BD67ULL, 0xF03E95B8EF8F0C78ULL, 
            0x90B6A11F97AC0851ULL, 0xF8880112B5DBC3D2ULL, 0x7BCD6FB6CB578512ULL, 0x4814059D251A4C81ULL, 
            0x1A8998FD31D4E4F2ULL, 0x16C05E9BD6E0EC9DULL, 0x43882A2B7CC71C48ULL, 0x7D70DB2B82ABE495ULL, 
            0xF44687F292F20DE2ULL, 0xBB04808A219F0614ULL, 0xD7C16883298A276AULL, 0x2CCD2F0D62CCB924ULL
        },
        {
            0x205383FF0FF51BFAULL, 0x4B83790A1445D6A4ULL, 0xFC88EF57BC2971C0ULL, 0xDC1E3AE21ACF556DULL, 
            0xB8C5D17382848213ULL, 0xB424B26A60D76FB4ULL, 0x5330A1866E5202A5ULL, 0x72829E0A6F416113ULL, 
            0xC79F58F554F9CEF5ULL, 0x8057E3A03B1A0775ULL, 0x716C3D40783C09BCULL, 0x3E417366525AA177ULL, 
            0xEFBB9DE31BEFA9FDULL, 0x3BC3F8B2C44C844EULL, 0x1A11C830CB4E7491ULL, 0x4E341A40584B2F6EULL, 
            0x4946BC2F5760EFB7ULL, 0x5D579878EC32B4FAULL, 0xB865512B6C2CD68AULL, 0x33743F019BB8BCD2ULL, 
            0x2A9C329B007C3FFDULL, 0xDE9633E09790D415ULL, 0xAF87ED9974D9D1D8ULL, 0x8D0722EF8F1E4CF5ULL, 
            0x408BAAD42AE5AF4BULL, 0x701ED78EA441A38EULL, 0x1F89B4D7167B873EULL, 0x0AD48AF0CA2FCC24ULL, 
            0xF681FF358924D1CFULL, 0xBA3FBE45D2F935D9ULL, 0x51094453DE32F33AULL, 0x17FA34FF0D61F622ULL
        },
        {
            0x180AADEFD67AC4AEULL, 0x4CC9ABE7576DDF86ULL, 0x61966261AE99CA38ULL, 0x65DAF7A24F7B1E4FULL, 
            0x33E92BAE6E7979E6ULL, 0x78EC2342A2D12177ULL, 0x2DDC43A8309B6C31ULL, 0x7DAF76E851FDCC7DULL, 
            0x9FA97A1C77E48A56ULL, 0xFB348EC5E7AB64B3ULL, 0xC07D0526FAB3A283ULL, 0x41CA96CC790051C5ULL, 
            0x11F5FD49D739226BULL, 0xBD20896507FF638EULL, 0xBF66F40EC318DFF4ULL, 0x168E157D5B1F81C2ULL, 
            0x1ECF5EFD4E7EA659ULL, 0x8E13FA33891F6D5BULL, 0xBF52C97E5E29B93BULL, 0xA501900DB794632EULL, 
            0x0E0A9CCF9D56648BULL, 0xA45B2D0C4E0E8301ULL, 0xF92440924EBA4D99ULL, 0xBE1236B9EE19A846ULL, 
            0xD980B270EA92FAFEULL, 0x79337D3B89EB6E6DULL, 0x6DDAACD13DF867CFULL, 0xBA8A53C90D2953F6ULL, 
            0x0F2EE556333658B4ULL, 0x74FFF79EA4CC0D42ULL, 0x2B2FB204C2F9F02CULL, 0x20FAD119586DA290ULL
        },
        {
            0x145A74FD6AF53798ULL, 0x716206FB53103D9FULL, 0xCCF097BB39F0BCAFULL, 0x47B52831DC156C00ULL, 
            0x7C75885316B25D84ULL, 0xE5569DFEF4284427ULL, 0x2F04A6A13F8B6B52ULL, 0x689EE657BAB13A6CULL, 
            0x3DD9F2217274E8E6ULL, 0xAF10ED12819030E5ULL, 0x9E2515F0BD4F6ECAULL, 0xE1606A50CCCCF5F6ULL, 
            0x9876A64ADBEAC281ULL, 0xB705D6D4550613DFULL, 0x3FC24D273D4D6598ULL, 0x9F4EE0272AC7C0B7ULL, 
            0x375B7D381337DA8AULL, 0x2153D5B1E883D367ULL, 0x06357B1F451AE66BULL, 0xED08AE73B3301174ULL, 
            0x12DC7F2AD0C743E8ULL, 0xE6B93CB1D64D2924ULL, 0x97452847F0D6DB54ULL, 0x0D66E77A342714A9ULL, 
            0xFB971FEDA2994283ULL, 0x977A0A95BF5C2A94ULL, 0x26EF64B29FFDA388ULL, 0xAB63FC1989B15AC8ULL, 
            0x75541C717B9C776AULL, 0x75F9644DE40303B9ULL, 0x0BD7CFE58F9D83B4ULL, 0xE7D14D35945F8E36ULL
        },
        {
            0x06F79F6D793A35B4ULL, 0x54DCE4E5DBA0B61BULL, 0x21AA69EA9C321821ULL, 0xFE6F012D05F028FAULL, 
            0x74F9B44EC2D27B12ULL, 0x4C40D4941C5BDB8EULL, 0x7B625B090AFA25BDULL, 0x7E18028890DB6AFFULL, 
            0xF6A2CC86C1032323ULL, 0x6B563BE22A98C000ULL, 0xE01BACFB97AB96FEULL, 0x42C41F691A5488F3ULL, 
            0xD9B5DDAD6FD0E932ULL, 0xA922937D6C0DED96ULL, 0x77C44A177D39B517ULL, 0x989F2CEE4C754787ULL, 
            0xF05513B453713205ULL, 0xABFF982149D2237BULL, 0xA119D11F39ABF74FULL, 0x4890B964CA908597ULL, 
            0x189F78ACABE70E78ULL, 0xDFB865BBBADDBC50ULL, 0xC59D0ACCFD037A45ULL, 0x4417C54908C3AAC5ULL, 
            0x58565D0986BAEE6DULL, 0xE122C93ACFBBDF8EULL, 0xAB8658D138F27A26ULL, 0x93404AD25AF3E356ULL, 
            0x731AF7F5ABD305E3ULL, 0x7628B243592FE297ULL, 0xD38B9FB259C5B8F6ULL, 0xFAE18964F4317015ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseCConstants = {
    0x7BA4FBDB6F758E2FULL,
    0xAD7909C477849B19ULL,
    0x3EBF38D618C3C104ULL,
    0x7BA4FBDB6F758E2FULL,
    0xAD7909C477849B19ULL,
    0x3EBF38D618C3C104ULL,
    0x48ECD4FD70805267ULL,
    0xAEAE99604E114271ULL,
    0xDF,
    0xF6,
    0x83,
    0x98,
    0xC2,
    0x97,
    0x60,
    0xDA
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseDSalts = {
    {
        {
            0x030DFB0B92EECEDFULL, 0x4CA9DE1A98605EC8ULL, 0xC906987C7F619159ULL, 0x20ED798DCC73F8CBULL, 
            0xB779CE12B897A8DBULL, 0xCD7B2B0EB44FF15BULL, 0x631A69248C7ECD08ULL, 0x42E8CB20F38EDD3DULL, 
            0xF035704B72BA3F64ULL, 0xF6F22D89F6FA247BULL, 0xADEB5B69D775A09CULL, 0x3F8292CF5BCB7F6FULL, 
            0xBC9A3CF181B4D209ULL, 0xFBCA1DC3E43B3D38ULL, 0xF28011D731A507C9ULL, 0x2EC820EC8E79D090ULL, 
            0xF27CAB6FD7369544ULL, 0x9E24EDB84A64A7A0ULL, 0x98A4A05B7BBF4EB8ULL, 0x07B752A5D5BA8BC6ULL, 
            0x7FB7873D60F7A553ULL, 0x300FBC7B479912C2ULL, 0xF90A5A9E876C10A8ULL, 0xE6EE818275E01C32ULL, 
            0x02717AC80EFB7789ULL, 0x080169B9EE09B1FBULL, 0x1B11E09D497BA75FULL, 0x22DC5A0CFF737B16ULL, 
            0x260CFC56BC829D36ULL, 0xFCB7A90E0421577FULL, 0x2D2A3FA4068C58C2ULL, 0x91FE6F17BBA684FAULL
        },
        {
            0x5036066399970BB6ULL, 0xC004CE4D4BA14389ULL, 0xC45EF612FAFB2C32ULL, 0xE527FC119E3BD76CULL, 
            0x4CAB97DF8FE74DFEULL, 0x05C29249A45EB987ULL, 0xC3EEF605AF08D385ULL, 0x6C07BCD3591A7D16ULL, 
            0xB2A15C9EA60E66C5ULL, 0x4B901B27119D7DC9ULL, 0x46C67B8388D59DDDULL, 0x8094E5F98BC71354ULL, 
            0xA805B9BF8A93C02AULL, 0x5AD7D1011433C86DULL, 0x3D8A986F0F8C8FF4ULL, 0x2E3B33B5E5D9C9D1ULL, 
            0x1C087C9E9813F0F6ULL, 0x901B89638E2BA56EULL, 0xB1105E40F970E65BULL, 0x0A8232785196A809ULL, 
            0x6CF1A507F2027170ULL, 0xCBA79D0D025874F4ULL, 0x1769BCE69214762FULL, 0xB0FBF971D509E9EDULL, 
            0xE5C3357F1A081346ULL, 0xE11A832B04EDE982ULL, 0xAEC66D07F4E3E8B0ULL, 0x04E22E040D123710ULL, 
            0x9E3208E40FBCB9C5ULL, 0xFF18D5F3B20F8AEFULL, 0x0DC0ECFFDB994142ULL, 0x93B4C6A60C29E230ULL
        },
        {
            0x75B8D57C1D9014E1ULL, 0xA41F0C52DAA5B180ULL, 0xE3D909B292E1B8C2ULL, 0xF017FC8E89FA04BEULL, 
            0xA150EE24D210AA93ULL, 0x0A49302BBC5391AEULL, 0x6D3FC5005B725C9EULL, 0x8C0E6E0E8FA5F93EULL, 
            0x9AF73D1497E5E31FULL, 0x12701804027D9EE8ULL, 0xBBB0988702789FBCULL, 0x95FC6AB75CBA0669ULL, 
            0xE817B75D94FDB2EEULL, 0x3F2A2513C08F42C8ULL, 0x0CC7699040441C10ULL, 0x483C88CF7E74F5E9ULL, 
            0x8D5CD37983279FE2ULL, 0xD8377C5C3DF46F70ULL, 0xA7D9D296380DE299ULL, 0xAA8E686A11337FAAULL, 
            0x70644E26FB25FDFFULL, 0xC2AFDCD56070FB57ULL, 0x5FA7BA6F7539EA94ULL, 0xED40E7175EEEF171ULL, 
            0x6BB63651BE8E659BULL, 0x9930FDA1A8ED6ABFULL, 0x1468C8598286D0B6ULL, 0x2F7B47163E259E49ULL, 
            0x9964612E6D42EEC4ULL, 0x4DF4E0EB5AB6ECCEULL, 0x20005C8600D6C060ULL, 0xFA38F75EBA22597FULL
        },
        {
            0xC7B543C486AC7B47ULL, 0x60B12978D9E01743ULL, 0x2B6E98B184317FBCULL, 0xD8F9ABCA392345B8ULL, 
            0xAF7C1A71ACAD448DULL, 0x32EA50F4FDBB3616ULL, 0x9AC8F523BCF22394ULL, 0xB01AE83B900EA8D8ULL, 
            0x62CF40F861580CCAULL, 0x783F1277FAEA4840ULL, 0x370DEF152A19B781ULL, 0x9F3F7C2CE0E2455FULL, 
            0x84E7C92FF4B30E9EULL, 0x40A2C242E1F80CF2ULL, 0xB5BFDE5C3FFB1292ULL, 0x006012979049D3C7ULL, 
            0xA1E223FC3893B08EULL, 0x65C5BFF1E7E94898ULL, 0xB4D800ED624160FDULL, 0x2050088C37678466ULL, 
            0x00FF28C4C39D8148ULL, 0xB9B2F4D4F5A12F7EULL, 0x21EA6BC75A4246D6ULL, 0x994582E11E533322ULL, 
            0x64903FCF0EB81C47ULL, 0x34EADC3E16A462E8ULL, 0xFC780F2E180A7A47ULL, 0xDDA7C2A8D6339849ULL, 
            0xD41C7593E7BA21DFULL, 0x1C8610AF2A6829EDULL, 0x620E9B8F0BDFE912ULL, 0xD621C7B864874F11ULL
        },
        {
            0x5D00B76046639DF2ULL, 0xC75A9A46A9F4FB2DULL, 0x1E85BC65C2F8D5A9ULL, 0xB3C417168F6E6DAFULL, 
            0x8023255211DBB362ULL, 0x59B0270FE8D5DBE9ULL, 0x7E6BA0DDC6F17C94ULL, 0x98BA956FE23A306CULL, 
            0x4EBD4EAA726FFFABULL, 0xCF8E5BD7A15E1998ULL, 0xA2894E732F4B222DULL, 0xED99E72E4671912DULL, 
            0xA0C6D1ACF23F4D5EULL, 0x24AD1C9BD6725A44ULL, 0x94CBB2512A88250CULL, 0x5C32F96D2C7FCE15ULL, 
            0x83F9904154377990ULL, 0x6A1C45106F4CF1CEULL, 0x47A24B341EA52737ULL, 0xC6FD61859A708792ULL, 
            0xAD664DB06DFD7290ULL, 0x5F9E012A597D045EULL, 0xD8F5156E6C7BCDC0ULL, 0x191AB615217F9C99ULL, 
            0xAD6E62872D34BEC9ULL, 0x23B9AACC46120F76ULL, 0x70650EC57CE1749DULL, 0xE475664213AB5FABULL, 
            0x1D79E3205296280CULL, 0x91F327E3D6F25C72ULL, 0xC9F0B3285FB61A2BULL, 0x1EAFD108C154CF5EULL
        },
        {
            0x9819E009C68AFA5DULL, 0x60A455560F5C22DFULL, 0x618C8D574762F2D3ULL, 0x8957A46AE127DD92ULL, 
            0x02BE3FC4B9CA054CULL, 0xD278819735004FB3ULL, 0x73BB93C43C4CC159ULL, 0xAE5350AD0F593347ULL, 
            0x77979BBA61A5C78BULL, 0x0C7FF5369652936FULL, 0x67C1A431A44A3A71ULL, 0xC5A7D8B1F32D3CE9ULL, 
            0xB1F7F1B3891580B1ULL, 0xFEDEA574C7FCA4E1ULL, 0xD8BF01761FA3F6ADULL, 0x7D8C8303FBCB8AE6ULL, 
            0xF46892894ABA7A3BULL, 0xE3BC6AD2C3F3E613ULL, 0x14679AC7D613A496ULL, 0xCDCE1031B79BBFD2ULL, 
            0x34C18780C99B69CCULL, 0xC847663F091FE2B3ULL, 0x73B387A1C308D147ULL, 0x9AC5810C76116710ULL, 
            0x5A3B1C77C9D74AEBULL, 0x9E5759EC6C38294BULL, 0x733D11635FE9B4A8ULL, 0x28D2F10F794B9E7AULL, 
            0x39CE7FAF895783A4ULL, 0x1F00C43D6634E60DULL, 0xC5F62C00C5160DB1ULL, 0x676375BD8FC7F893ULL
        }
    },
    {
        {
            0xD6A43278134E2F0AULL, 0xA7244319CEA32845ULL, 0x25F74947E042C650ULL, 0x5F139E9D3914A9D2ULL, 
            0xFB34BD004D470934ULL, 0x640FA0CAA54FB7BBULL, 0x7154E5FB0F35EF67ULL, 0xB144FC5CA84D0160ULL, 
            0x1D11163C08BCC41DULL, 0x2EB34FF9903C35FDULL, 0xE050B0DBF4B45033ULL, 0x45026B662CDD990EULL, 
            0xAA2901438EF9506EULL, 0xE69E8E4C2F304661ULL, 0x926AE462527F8BF3ULL, 0x53E964FE93D7CDACULL, 
            0x77D949301AA8067AULL, 0xC67584E244767C44ULL, 0x6B0290470A4C5840ULL, 0xD4EB5F6FC9A51403ULL, 
            0xF9BBBC31C2281152ULL, 0xEE62747AD450C692ULL, 0xF38D7872889F9C0EULL, 0x7245F810683FC2A4ULL, 
            0x792591B920753487ULL, 0x9BC38DD625B79569ULL, 0x7F97B979E0FDB37DULL, 0xA8855B8BC3CB0229ULL, 
            0x47B565A971B5C719ULL, 0x333323A35387299EULL, 0x6E3B3DA83CE195A8ULL, 0x64016C546869FAEFULL
        },
        {
            0xF8D7365B16AB6D9DULL, 0x6E00196A2DCF6452ULL, 0x7BEE1E7CAFBC94A2ULL, 0x09BF7223F5C8167DULL, 
            0xFEFCA94515BA6AA5ULL, 0xA0A7A6AB59CB535CULL, 0x6F7DEB3278343189ULL, 0xA17B48FCEE4F0268ULL, 
            0xB7B884866C255A7AULL, 0x55CE194312481EF0ULL, 0x19C48AEC9A2B13C3ULL, 0x5D1982BD798F575AULL, 
            0x5AEFC03BCE944B33ULL, 0x8A82226236E00C0FULL, 0xB22038B9F680E247ULL, 0xEF669BA6D40CE2F7ULL, 
            0x12512311D665CE62ULL, 0x723DA1D84BC6FCC3ULL, 0x30899C4C0113F7B7ULL, 0x588467C83DAB5273ULL, 
            0xFE2F9A30F1FAE995ULL, 0xD313330272ECF33CULL, 0x7BF94EAA7F85D135ULL, 0xEA889D62C5289FA1ULL, 
            0x80B92D470CDE1427ULL, 0x79A9EAEB93E6DAFEULL, 0xD74AD96AEFA945F6ULL, 0xB7B0BBD15F6192E7ULL, 
            0x8705A2AE23980803ULL, 0xB8C8F456E4DB5636ULL, 0x31CF5359A8B87ADCULL, 0x00684EA349036389ULL
        },
        {
            0x1E69D9699401F6ACULL, 0x7C075CABD948F253ULL, 0xBDD49AEBDBA55249ULL, 0xBBCEDF0C8D5D3FDBULL, 
            0x0A5ED4319DC64CF4ULL, 0xEBDEBE983E69F95AULL, 0x1A6FDA31684F1822ULL, 0x98820707F0A52499ULL, 
            0x26F19EAC4F5528E8ULL, 0xD13C42A0F8D290D9ULL, 0x5DDEE138E50B0FD3ULL, 0xAEE7929FCE8D7852ULL, 
            0xCAC1145D446F5450ULL, 0x3E96ED2C0DDFBE6DULL, 0x7DBACF6FDED5591EULL, 0x596EDCF79FA9052FULL, 
            0x3CD7E1972B5DC866ULL, 0xDBE0D0E648F511BAULL, 0xDD939DB778200E2CULL, 0x6F687AF7266C46B5ULL, 
            0xD40376159716EE3FULL, 0x6C2A0D140F423A07ULL, 0x2D344B6A6DF7C0D0ULL, 0xF978E69876D896E9ULL, 
            0x0CB298B49CF29811ULL, 0xC32D83AA0DE81575ULL, 0x621E9DD255E3D211ULL, 0xF50E790B4737BDD8ULL, 
            0xA1749D9E43823141ULL, 0xBB98BAD12A9D2F93ULL, 0x239DD5822251980BULL, 0x578E2194B35FEFB6ULL
        },
        {
            0x4FD11225607B3BCDULL, 0x6627EF88307527FEULL, 0xDF6028AEB39C2D91ULL, 0xDD8B3A5BE604E29BULL, 
            0x287F32CCE9BDE217ULL, 0x9ABED5674359C45BULL, 0x79D6A8DA55DAFDE2ULL, 0x01F39E67064266EDULL, 
            0x2423644C85CEC2ADULL, 0xD7497BADEA440EDAULL, 0xA2EDFDBB9ABC0B05ULL, 0x129D2A302B14300AULL, 
            0xA1AC41509001DB7AULL, 0x257641C4BD73C4D6ULL, 0x0FD8CA9B52E993EAULL, 0xCB47ED833A727B2EULL, 
            0xFC56F1F1B46AC0A6ULL, 0x1BDE9130BCD9A7B7ULL, 0xE76DFAEF4DC18D11ULL, 0xC4C0F5067E9505C3ULL, 
            0xC42D5939C7E31B61ULL, 0x3BD3BB8DC0721BEBULL, 0x16EC7AF08C388715ULL, 0xFD81284E2AE60C8CULL, 
            0x344B60832A3C5A5FULL, 0x97297C66340ED2DFULL, 0x1068627C14BB7ADEULL, 0x799C8740F4117C01ULL, 
            0x710EC1B84730A770ULL, 0xCDE92642B160E9B3ULL, 0xD5A4A3C074079580ULL, 0x7F0F0232FF956886ULL
        },
        {
            0x517F31A1C3CF1FA8ULL, 0xC861A4C0C4C097E8ULL, 0x7582638E094ADAD2ULL, 0x9891AFA1858CC13AULL, 
            0x16BA854410EB21B4ULL, 0x45CBE5178CE07092ULL, 0xF3F5C2C75675F308ULL, 0x947437E56CB2988CULL, 
            0x0FE8F68223BD45CAULL, 0x9668B54DACEB5708ULL, 0x3740A407746C7434ULL, 0xBC946B599C8A13DCULL, 
            0x5F070B58195E930CULL, 0x9DD1D72DDCFA34A8ULL, 0x476B8749E7B479F7ULL, 0x5D7A390C43934357ULL, 
            0xC85196B133AE98F2ULL, 0x190A82D1CCEEBB5CULL, 0x84A1ABE042AA82FBULL, 0xCA4B2B39DC8CD4E7ULL, 
            0xC4B571BFF5BF0087ULL, 0x7B24C26D586D6954ULL, 0xF8CD00F928DEC997ULL, 0x8CAAB2FD60BB2B0CULL, 
            0x69DB27FBFA645933ULL, 0xF94614A45885BDD2ULL, 0x2CE99AA0E27A4609ULL, 0x1E17252A68309170ULL, 
            0xB396878E763C7ED2ULL, 0x79B2BA2FA6178222ULL, 0x3CAE578244C93108ULL, 0x01CD5F1860AE8E6CULL
        },
        {
            0x9D6775DB8DEFEA17ULL, 0xA78AFDF6236FD87BULL, 0xF87BA7A0DC3C934BULL, 0xD585E917B6E5DF9EULL, 
            0x9B8B29C60D7A9BD8ULL, 0xB7306E7E3918FB0CULL, 0x3DEAA977A524653BULL, 0x337571C4B0A413C2ULL, 
            0xB51AAA875029CCA4ULL, 0xCE4064104D8E017EULL, 0x3EBB22CD7F293E43ULL, 0xC6F2FC2EAC3CBC9CULL, 
            0xE1FA3F8FE4C9CB77ULL, 0xB59769CB1C01346AULL, 0xED7388435CE258A0ULL, 0xEE77A4FEE8A1AF91ULL, 
            0x9AEBB3E60E096465ULL, 0x88DFF1D8794FA112ULL, 0xFD00ED05B7F6E7D9ULL, 0x2FC7F7A3C4D6ECECULL, 
            0x0832F09BAEEEF2D7ULL, 0xA5449AD2A3055932ULL, 0xB6B2B1A2F37577B8ULL, 0xC4AD90397018E8C6ULL, 
            0x4788D9C8FD4CF12EULL, 0x80C9EF3DBD38CDA2ULL, 0x7F7432CE288351EEULL, 0x7E38E31C00751ABDULL, 
            0x3FD86F89324AE592ULL, 0xC34D27937DD80AF1ULL, 0x64DC54E33EE9895BULL, 0x6D339C353428AD2DULL
        }
    },
    {
        {
            0x392289C1E26E1917ULL, 0x83748DCD26682733ULL, 0x109CD0B9A4F9CDD5ULL, 0xC10616F99F3FC888ULL, 
            0xD9F93031255D4D92ULL, 0x54BF5DF20DEF9C68ULL, 0x206DE262D83AF571ULL, 0x9DC98F881C2640F6ULL, 
            0xA77767CB1B3B8D35ULL, 0x5C91F83E8DDABD5FULL, 0x6637212371F2802AULL, 0x685E25F8342AFD8CULL, 
            0xD344BB91FC67E0CDULL, 0x14CFE4A8C9AAB249ULL, 0xF93A847818F14350ULL, 0x388737E7A35A538FULL, 
            0x59106AC319BE0352ULL, 0xE2AD3DC3A409584AULL, 0x84A6A657C2275077ULL, 0x77512C663988BCCBULL, 
            0x0A89F0AF73D7EE61ULL, 0x78A836E1FFF97617ULL, 0xB29EA1C11557EE97ULL, 0xEF4430ADF417FCC7ULL, 
            0xD91216B921551154ULL, 0xCD070E0994268E61ULL, 0x3AA616D07F4B517CULL, 0xDDF8119346FD891EULL, 
            0xE4D32B10A098195FULL, 0x08F55F8D16ED79DEULL, 0x55FFB69D9EB52133ULL, 0xD1ABAF1D9D5BCC2DULL
        },
        {
            0x1886A236F8A95E04ULL, 0xA24C89F3E3A8E3C0ULL, 0x005E41B2199DBBCCULL, 0xE9A1CC3580E1111DULL, 
            0x4661B814995D493BULL, 0x0ADD8E70C1AD4D88ULL, 0x059743149149B6F0ULL, 0xD65710F2A80E9F75ULL, 
            0x2A7A0D1902B9A5E6ULL, 0xA634A50750179DE6ULL, 0xFD1420F17C38F96AULL, 0xCF67D9D548A2A7D6ULL, 
            0x1D607E246316913DULL, 0xDCF225CFBD6934A1ULL, 0xE5D670EBD5558527ULL, 0xD65B01457A685671ULL, 
            0x2DD74D428A166E99ULL, 0x444543EF087F42BAULL, 0xDD9FE56028FF70F2ULL, 0x316B66AA3940CA3AULL, 
            0x9BB1359A358B87D4ULL, 0xB6710B97B8B1C07AULL, 0x32C0DDD8C6182940ULL, 0xC355B0BA34E9EB47ULL, 
            0xEC19AFED1241FB72ULL, 0xDA93D17980A320DFULL, 0xDDC7B82E14098AC1ULL, 0xD3796D1B43D5BB04ULL, 
            0xD58DC0121747DB8CULL, 0x69F1BC3E37162F93ULL, 0x5EB65F7DAA55B337ULL, 0xD37FC49C977F8280ULL
        },
        {
            0xC9204EAB59B7A757ULL, 0x3B2826A33832377CULL, 0xB2FAA1270A4B5070ULL, 0x1AE3F46B986B6D01ULL, 
            0xADC109C3E15C12D2ULL, 0x02B0AAC02B95175BULL, 0x5AF69D1BEB1717CAULL, 0xDFF4D165BFC22FE1ULL, 
            0x9F01D4AAAA066602ULL, 0x5C67F74A6A99D845ULL, 0xCC8040A99FFF6A81ULL, 0x610B577715E017CAULL, 
            0xB27FBE8CDE9BB4B2ULL, 0xC34A3D5AEC8F7A9CULL, 0x101911EF4917E563ULL, 0x0CF25FBA5F0980BEULL, 
            0x3481D3F529A4F30BULL, 0x87A3588A852D4E9BULL, 0xCA89C3480427727DULL, 0x34C3264BA89BEBDBULL, 
            0xBD12CA2D21DBF1EFULL, 0x1ECC80DB7DAABE1DULL, 0x93D07E635CD1D289ULL, 0x89DF142B6D8503C8ULL, 
            0x728BB8A466288A2FULL, 0x52B6073194A11089ULL, 0x1E9678A009C432BAULL, 0x6111D31FED849677ULL, 
            0x9735F5ED0E2C8421ULL, 0x23313DD82E0C6597ULL, 0xF8B5E2B5DE1848BDULL, 0xD77A1E54E22C1762ULL
        },
        {
            0x7E065DC8EE172F50ULL, 0x581CA1A8B65913EFULL, 0xFB830300BC09B299ULL, 0x3BB8DBE03EC258E3ULL, 
            0x4139DC27518D5A5DULL, 0x702F364CB57D8B3EULL, 0x8BB64DA621227B73ULL, 0xB4DA5EA1BB015DB1ULL, 
            0xDD4041425112894DULL, 0x8D9D3F1D37C05F10ULL, 0xEC018C0FA5A635E5ULL, 0xC8D1876253498239ULL, 
            0x98BE49DD90D3BF5CULL, 0xB7926255CA9E1688ULL, 0x10B4422070577580ULL, 0x8E1EF5F7664676FFULL, 
            0x4C75B98ADB518F75ULL, 0x3DD4F342930A24A1ULL, 0x8BB0887DFF9BC19AULL, 0x36FFCE0FCF6DB9E9ULL, 
            0x39AC97F5E2433254ULL, 0x980440945E9FF018ULL, 0x0D51BDD29A542483ULL, 0xF915EF7492D3FCE0ULL, 
            0x1DB953A762DD4F63ULL, 0xDB460943B06BB656ULL, 0x3C160003DE7014C5ULL, 0xC060A1A2945D40C2ULL, 
            0x00DE29CA7CC323ACULL, 0x0C89C5865AC615FBULL, 0x7F28596AAFE95839ULL, 0x00CF765AF6974078ULL
        },
        {
            0x8894F06F76893AF9ULL, 0x3DEA8DA2FB99C406ULL, 0xA5BAAC7BBB0687C7ULL, 0xA3EB891B2B7CE17AULL, 
            0x96D1A41371AA7F92ULL, 0x07DBD9E5189C37B7ULL, 0xB0510AAB781F61E6ULL, 0x029D0F7F1120B8B9ULL, 
            0x4E8A12C64303CB84ULL, 0xE5D0EF2F27E778F8ULL, 0x7F08DA04CD6B41E0ULL, 0x0E7A038947FE9B0DULL, 
            0x8E7C6CC8DC632F32ULL, 0xFC8E76A9AA57710CULL, 0xE39AD8760EDBB943ULL, 0x5430BFDE5DE2B45DULL, 
            0xF7C784E7A6A524CAULL, 0xBD5B727A30013257ULL, 0x0206C747B563C147ULL, 0x2CAE36CDD4E6BDEFULL, 
            0x58E222892BE592A2ULL, 0x19B2B8FF76EAA49FULL, 0xF12CEF59633F8676ULL, 0x59C79EFB5D125B90ULL, 
            0x00B018A7058263EEULL, 0x06674DB025AC8646ULL, 0x988A3FF2C6B30A39ULL, 0xFEA79CEB6768011EULL, 
            0x53CE8E83ECF89CD6ULL, 0x89FB4A67B732562AULL, 0x3E7483EB6FC83871ULL, 0xC35088275F74F25CULL
        },
        {
            0x5195D31C13439C73ULL, 0xB009DE88B6151F86ULL, 0xA257B3C7761B001CULL, 0xBEE0B02EC40E127FULL, 
            0xD9532A51BDFC5461ULL, 0xC65C2950B87C01AFULL, 0x8EA20FDF195AB289ULL, 0x7B04517063BFD634ULL, 
            0x181CE592DC422970ULL, 0x6F9D12048D3EDA03ULL, 0x40AE87566C4D9C86ULL, 0x284525A50EC935C4ULL, 
            0x3E7B936E7AC1A0A1ULL, 0xA3B6312382D735CCULL, 0x6CE723D06CD46043ULL, 0xA81545AC26D9D098ULL, 
            0x946DB411974AB9ECULL, 0x40FFBF89652F423FULL, 0x1C3D23CAB9EE32C0ULL, 0x7AF129D1E4CE8C75ULL, 
            0xD0C926809314320CULL, 0xAA94DB88B3B60EC2ULL, 0x708446350F48F42DULL, 0xE13227C188C46AFEULL, 
            0xD0A9210600427F61ULL, 0x9347474882134186ULL, 0x03A1C1531C91AB25ULL, 0x6F75B8F5B5859CCEULL, 
            0x1A5C3DB27F0FDA7CULL, 0x1EE92D07F386CE0EULL, 0xCB75F2BFF358FCCEULL, 0xA8A684468197F714ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseDConstants = {
    0x95AC5BCB2D3E9F1AULL,
    0x92898A4EA98DD7BEULL,
    0xD4557517DC5C7F98ULL,
    0x95AC5BCB2D3E9F1AULL,
    0x92898A4EA98DD7BEULL,
    0xD4557517DC5C7F98ULL,
    0x2D3EDB63F6834E6CULL,
    0x1BC184AB319E57BEULL,
    0x3A,
    0x97,
    0x6D,
    0xD0,
    0x83,
    0x32,
    0x0B,
    0x0F
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseESalts = {
    {
        {
            0xA68AB7C234291CFFULL, 0xA45E601C486B142EULL, 0xD8C4377742FE2AE2ULL, 0xC3E192E5C61F677BULL, 
            0xF32F5B2CC3F8FA00ULL, 0x23F6D4D7E299CF90ULL, 0x7F9F5DC1A3F35ECAULL, 0xD547F34015BB452AULL, 
            0xB973A45C84176832ULL, 0xF505B53341C4781BULL, 0x2466AEC5ED35891EULL, 0x29502E3F5F534EF8ULL, 
            0x180D32C5364EA02EULL, 0x54DCCBD0B97C868EULL, 0xCDFFB93449AC5E2EULL, 0x7C50DDE96F272361ULL, 
            0x8C12BDCF9F76E603ULL, 0x7CA1F1FD0C33A6A6ULL, 0x9AFD5A78A4C40939ULL, 0x7C9B895C3EAE8C95ULL, 
            0xF21BFE6D350C2809ULL, 0xE4F8F726B0DB1D15ULL, 0x62C8DF74260B9420ULL, 0x997A5A74080248A5ULL, 
            0x256E7A9839447F94ULL, 0x081DF3B70CF90030ULL, 0x53C0C6A55DF3643DULL, 0xB98E60B97FB666F4ULL, 
            0xEAF6CF08E7178EC9ULL, 0x995D70A078874B78ULL, 0x32A54484C6ED249AULL, 0xF5BBF6DE7668CAC4ULL
        },
        {
            0xBDC728323440B2E0ULL, 0x9C81EA0A37912785ULL, 0x0807B0AE82A8E2C4ULL, 0x16BCF65B4C388B6DULL, 
            0x5D1B03CE7CCBA7CCULL, 0x50C70824EE96FF44ULL, 0xE701D16E2BB9DDE3ULL, 0xF5B324068754402FULL, 
            0xC6094CC2EC31BC71ULL, 0xD6752DB02A9CECCEULL, 0x6BDA759D4E0A7242ULL, 0x8D2894A29AF5EC48ULL, 
            0x0FE65A79A824B464ULL, 0x2920EA33DA49D738ULL, 0xA84C407A9AAED0E6ULL, 0x9D915D1596ACCBDFULL, 
            0x29C6B2883B830F44ULL, 0x74E97B6B54D745FBULL, 0xB1AD2C62819F5CE0ULL, 0xA116A3E37C7F3298ULL, 
            0xDB2F9C53754D1F41ULL, 0x1AF678D8BC9684C6ULL, 0x2F25E6E29F374E55ULL, 0x5D13EF8E9B904012ULL, 
            0xF8E1F8DBD8B3AA0FULL, 0x27F23D9D8E33F3FFULL, 0xA495DEBCCD773C06ULL, 0x72BF97A815A89C06ULL, 
            0xC2FC55F46B50D60EULL, 0xD192F1BB9FD2358FULL, 0x9ED4DB9041814DE7ULL, 0xAD8577E08BFB0745ULL
        },
        {
            0x2FDF9F1CB54F4ACAULL, 0x4F953624FD10C0AEULL, 0xE30CABC8035B7301ULL, 0xBEE4A908E16669A6ULL, 
            0xC8375DF787F168AFULL, 0x32AC8E266782D952ULL, 0xE2B8B368B5B26BD9ULL, 0x4F43DEAB415F3D6EULL, 
            0x3123DCE8D0DC9F4EULL, 0x7FC56977481693DAULL, 0xDC46F6445B837ADDULL, 0xDFBB2C0CBE7A8E69ULL, 
            0x0AE7E1E64348CABEULL, 0x47F6EDAB5C2AF0A5ULL, 0x76CEC2CE6B6B94DAULL, 0xD35153F5AD2E941FULL, 
            0x0B80F3F10D2A3930ULL, 0x4D0233D306430C52ULL, 0x756519A10B2F1BBDULL, 0x142D43033D3EC6F6ULL, 
            0xE4C42D0E6369127AULL, 0xB56A844EEA1DA945ULL, 0xF6FEDCC6046CFF93ULL, 0x726831F8080038CFULL, 
            0xCCECB9079FE7933AULL, 0x2159957793BC70E0ULL, 0x76313331A2557425ULL, 0x3A954B277BF92155ULL, 
            0xB6370185E16509CEULL, 0xF72F69B6BB34B83DULL, 0x652BA79ECE8AC353ULL, 0xA79F8A0DFDD72C9EULL
        },
        {
            0xD13805723F4A31F2ULL, 0x3C8E9758CB302A05ULL, 0xC907B1DA0EBF40DBULL, 0x016649C8508D0C5CULL, 
            0x563132B6670367FAULL, 0xDD8C91B205CD6885ULL, 0x216B0899C56F8C83ULL, 0xD3614CA37B054A87ULL, 
            0xC501AE3A97713BC4ULL, 0x6C6411CDDE1EDAC7ULL, 0x33AFA299EBE52BF3ULL, 0x95A18C241BAF3C29ULL, 
            0x123EFDFD653CA2C1ULL, 0x8573C92B2E3F41B7ULL, 0xB7D2103081E3DE5AULL, 0xC4E1A65022FB5DE2ULL, 
            0x84B0433851DB703EULL, 0xC50836984EB7AF58ULL, 0x0710A13B94FC49A1ULL, 0x61901EB83D9A4458ULL, 
            0xD01D05F94C3D9F79ULL, 0xF264693633943EA7ULL, 0xFD467842153811F3ULL, 0x22E725E6A4C1BEE0ULL, 
            0xCE4D54015E6DCDC5ULL, 0xC49B807896337B38ULL, 0x437821EB235F67F0ULL, 0xE7BE9554E77789C0ULL, 
            0xFDB7C11753453C74ULL, 0x5DA79CAB9F27643AULL, 0xF624839D76418276ULL, 0x0AB212BB7CB023FAULL
        },
        {
            0x6C1002033BA2749AULL, 0x7FA2ED959898E907ULL, 0x6F754AC76A8FFF51ULL, 0xA0B8D6ABE1CD7CE0ULL, 
            0xBBE520290B18194DULL, 0x02B71BF8132B82F9ULL, 0x22ACF0FBAE942DD3ULL, 0x385EC42F673C26D4ULL, 
            0x693C493A090379DEULL, 0x3B1610D7C9DD84F0ULL, 0xAE8D37E80F98EF71ULL, 0xA955EAC1339BA161ULL, 
            0x9D876ED5380BDD72ULL, 0xE783DE3FB37265C7ULL, 0x4C16CBED40C89265ULL, 0xF4CDD320349F2DEEULL, 
            0xF0553DADF2B5D675ULL, 0x2AF303636EFCB832ULL, 0x193A17895DAC4742ULL, 0xE049FB6B9268493DULL, 
            0x235B3794F8A78DCCULL, 0x48629EB13D937C05ULL, 0x8CE30AD7B2C5000AULL, 0xE118B86CC7315442ULL, 
            0x4A96542944890E4FULL, 0x016D6865EA5F4FD8ULL, 0x03D70E396D666667ULL, 0x2B13513ED040701BULL, 
            0xED2AC98C439C81B2ULL, 0x71D336093B2EE2D2ULL, 0x46A6C7EEB102B27DULL, 0xE6F495B83985F00EULL
        },
        {
            0x8FF00614BB101FEBULL, 0xB8C98CD69A68A50BULL, 0xA98804DF506CBCE5ULL, 0x78EB1A74A04E5EB9ULL, 
            0x06818015A4129DB6ULL, 0xB55B76AD76449D27ULL, 0xCE1875DD4664832CULL, 0x7CD8D18EA044F94CULL, 
            0xAA67D79DD7350B3DULL, 0x9D7631F6CDFE769DULL, 0x6A499FA92C55F06BULL, 0xB40C1245FB68F4ECULL, 
            0x8B59B6DC0638386BULL, 0xD06F9C0B032C77FAULL, 0xDF9EED6082590E5DULL, 0xE00D89AB36C083FAULL, 
            0xFD7924FC1199864DULL, 0xE3EEE8681AC75421ULL, 0x155AC0941DFFF37DULL, 0x7246AC4A6FC13F67ULL, 
            0xF020F735744B16C7ULL, 0xC58A92101BF19955ULL, 0xBA4E533D001BADF9ULL, 0xF5E55A12094576CEULL, 
            0xABD056E0DA7D039CULL, 0x534678196F78F69EULL, 0x2A7DF0D278F6B1EDULL, 0xD2471B68E1F78D22ULL, 
            0x78E2800FBBD7B508ULL, 0xFBB8F085878637C4ULL, 0xC56577134131B882ULL, 0x9ACB6B42EF9BDE62ULL
        }
    },
    {
        {
            0x14FF6961763B1B09ULL, 0xA5CD5CF33E7305ECULL, 0xAC22491B3260375DULL, 0x0A8CB232AF5B26F7ULL, 
            0x8FC7FFBF751C65F5ULL, 0xD6159BC5CE97483FULL, 0xFA079EF70693F44CULL, 0xCF02CDC419735AE4ULL, 
            0x11FE072705735657ULL, 0x541DF4CA61F35988ULL, 0x69774B8E14B924A5ULL, 0x5CDD7093183912A6ULL, 
            0x58D31EB3B7256C33ULL, 0xE67FDE9594A0E463ULL, 0x0AC5D89A443E5A05ULL, 0xCF0A7900E87A2730ULL, 
            0x46DC45F9D75884CBULL, 0xA91C35E8AF5DB7A1ULL, 0xE5DE944BCBD99482ULL, 0xB96A11039E8A6A3CULL, 
            0x38EA1A2F6A808EDCULL, 0x782D5F529EBE446EULL, 0xEF206B7835DCB210ULL, 0x67C28A9E2A0CF049ULL, 
            0x82B7AE2E334DC7BEULL, 0xFD85F8DD4A57589AULL, 0xB7486DB20B0BCB82ULL, 0x861E5C92ED570267ULL, 
            0x466696B957A35F2AULL, 0x0B927130BEF50FBAULL, 0xE0730C77B0CDC5FCULL, 0x897622B075DCC996ULL
        },
        {
            0x5BED37FA30B946ABULL, 0x6CBF6793DABD584EULL, 0x511F73B07316B6BBULL, 0x35DAC0CA5D3F68CDULL, 
            0x563DA6B4D4852A8BULL, 0x822D61371BF9EB46ULL, 0xB7AEB7601F5F3590ULL, 0xACBAD89F1818EFB6ULL, 
            0x76D5B7CADAA61F61ULL, 0xAF32C7314A75EDF2ULL, 0xC06DE52D27BAF9F9ULL, 0xBCC21CE0B0F4C1B0ULL, 
            0x7EEFAD4C0A447ECEULL, 0x147BB6FDBD4F062EULL, 0xC85E1AAC8BFF9B46ULL, 0xFB56983E70274E16ULL, 
            0x8220709274040DF7ULL, 0xBC02EAE6ECBAA78CULL, 0xE018424C04057465ULL, 0x954E1AD6D704C520ULL, 
            0xFF58976DAC5C1D92ULL, 0x057256AC5643D5E0ULL, 0x356384AE301A0BBBULL, 0xFACCD5C224CF0BABULL, 
            0x21120BE673D915D4ULL, 0x169E96288FCE42EDULL, 0x6EABAC5F864F111FULL, 0x5458A9E57C1886A2ULL, 
            0x38C5D6018A723A9CULL, 0x921C030E3A533B2EULL, 0x23E763C592F01569ULL, 0xE636D4E88AF2A04BULL
        },
        {
            0xCDCDF99F8994C37CULL, 0xC6A0816297FFB6D5ULL, 0x5DBE7396BC413323ULL, 0xD78BA2AB68BD4385ULL, 
            0x9732D3C03DAD5BD5ULL, 0x0680BA84C3F82C75ULL, 0xAC9CA839E9E09D2DULL, 0xC06D63E0EA96EF2BULL, 
            0xD524896E5F9F000BULL, 0xA8BAB9C79D8D2E5CULL, 0x006D19D7C6D89177ULL, 0xF6DE7C077948AEDCULL, 
            0x9140B348B3D27670ULL, 0xF9E3A78982F33138ULL, 0x7D6FCEA63D9B9383ULL, 0x48D1B61F8AAAC4A7ULL, 
            0xB71D6E75B9EA472BULL, 0x3732BF92C80A618AULL, 0x0AA0030B7BFA835FULL, 0x82907283BFD4F0BEULL, 
            0x97DAC7F890458DD9ULL, 0x9033A808E850C253ULL, 0x3CA9F708FCAB8B95ULL, 0x52E5A840A1E232C1ULL, 
            0x3F63B43802371C02ULL, 0x0DDE977C60B79B79ULL, 0xB4026A85F3835F7EULL, 0xA5B82A225634A7F0ULL, 
            0xC2933A86B43F371AULL, 0x90A24C5F2DEB4EC9ULL, 0x1E39340230498839ULL, 0x328F61BC42BC5209ULL
        },
        {
            0xD3C7DACF7F84E2F4ULL, 0x0B70FAC203A161A2ULL, 0xF6A458CB0C1203DBULL, 0xEA453A9BF02C62ADULL, 
            0x78874351C716DD16ULL, 0x1436F2592EBC8C3FULL, 0xE785F2917D71E10EULL, 0x6B048B6127491FB2ULL, 
            0x66697C3E9E5BD3F2ULL, 0x99DBD3351DC4A99AULL, 0x2119EA2632D6D91FULL, 0x394E67358FF6B461ULL, 
            0x00566B9F63490225ULL, 0x6592A620DC01D587ULL, 0x6CBEF66A7F54C092ULL, 0x10567814AE65C986ULL, 
            0xB51EEEAAAC9DC0D7ULL, 0x4B84E26D218F3795ULL, 0xE4F01599D4D1E490ULL, 0x37EE70DF8061311CULL, 
            0x036B3CA1B3EC8825ULL, 0x624EC9614F72A99AULL, 0x0604FC8A52A37806ULL, 0x002A7B85450FA88BULL, 
            0xC39501140ECB5103ULL, 0x5FD0F2E58C5DD844ULL, 0xD417910CE904F2F8ULL, 0x1BD4140682B74AC6ULL, 
            0x52DDA2FF5A12D1BAULL, 0xA18965F8EC50C3A7ULL, 0x6B80AF8B6E7B3BB9ULL, 0xD15853848A670150ULL
        },
        {
            0x7C7185BBC0B8DD89ULL, 0xAF59A9B2E5C4DB12ULL, 0x2863CDB4F1DA732FULL, 0x0B034B109FB14995ULL, 
            0x64F99A7070CCE643ULL, 0x226FEF414CF90DA3ULL, 0xED401671D1AEBF12ULL, 0x53774E2A4790803EULL, 
            0x872167089082B721ULL, 0x524F8BA5DDFBE87CULL, 0x3FFDA8F2575AEDF5ULL, 0xD182E4E3DCC55551ULL, 
            0xE7434FA09535DF38ULL, 0x2FA5E3183256AEA3ULL, 0x15C8DF80772641B4ULL, 0xF80D567847A8A406ULL, 
            0xD6AA97C0EB093B23ULL, 0x9906C405D00D3F1DULL, 0x4A5D054717764FB7ULL, 0xA5308CFE168B173FULL, 
            0x56DDA4BA84167C70ULL, 0xC8C7E1A4296DD09CULL, 0x5B8C14FCFF1FB293ULL, 0xB9CF6BAE05A93E28ULL, 
            0xA4D4ED5B4DDE8DEAULL, 0x5D9D855DF8B584A5ULL, 0xE77CDD4192CE990EULL, 0x5D32038B3464A5A4ULL, 
            0x9B8374478AD7E704ULL, 0x5ADC63021D8F0261ULL, 0xBD6640DB98FDD7B9ULL, 0x4F84F48ED61957C4ULL
        },
        {
            0xE803011B41E44290ULL, 0xC01537BC9E8AB22AULL, 0x55982FF2401BA1DDULL, 0x361F91832AC73121ULL, 
            0x844730F780D7B601ULL, 0xE65B15CBD020C111ULL, 0x57D883000041D6D2ULL, 0x58ECFB18FEA6D315ULL, 
            0xC62EBE1702489FAFULL, 0xB69CCBB7E86EE525ULL, 0xFCB7CC1338972964ULL, 0xEA562111B65768C5ULL, 
            0x2C2A0933E9138750ULL, 0x96A17B359A66B0C7ULL, 0x6AEFDB45BEBC6D10ULL, 0x4857BDB5E76C698AULL, 
            0x4ADFA1B01B79D8A3ULL, 0x3F828E48A7495405ULL, 0x0D24920264315D56ULL, 0x5A8A2EF8B9B3CD16ULL, 
            0xDC3435DF3D89FF38ULL, 0x81F0CB1971A0A119ULL, 0xE1AE81240E3417A6ULL, 0xCAB79D039162C16CULL, 
            0x732F0BCB4DA1B6F9ULL, 0xA526816CE5852EF2ULL, 0x7C7F4E629C3196C5ULL, 0xC817F961D309DB2DULL, 
            0x3C42AF65254F5957ULL, 0x604184AE5EF5FCFCULL, 0xF8335BA53C5264F7ULL, 0x7C416D7F123E4F34ULL
        }
    },
    {
        {
            0x21BD9A1C595E83B9ULL, 0xA3DDD44FE556DE50ULL, 0xEC01E3D24BD8A79AULL, 0x702581FD33CD3F92ULL, 
            0xE395B66A2FA636A7ULL, 0xAD04A62B14562363ULL, 0x633A9B049042DE83ULL, 0x0C03E4D944B2862EULL, 
            0xE1B41121DE78A6F5ULL, 0x8B440BE35C24CD61ULL, 0x49A2D3C57AFFA40BULL, 0x6501BE0B8904721AULL, 
            0x109B2CD3A446DDC3ULL, 0x86CF9260DAAF1A95ULL, 0x790E35DC14F937F0ULL, 0x1FC880941B6BCED4ULL, 
            0x6061E050B2183607ULL, 0x0B43FADA63FC3988ULL, 0x03F79A45F731B87EULL, 0xB272E5830890B056ULL, 
            0x23D51864280A2C94ULL, 0x4F0A487F43DF67CBULL, 0xBDCA422E0B289D52ULL, 0x9B29923268469C96ULL, 
            0xF9650D42C586C8C5ULL, 0xFEF5EDDF4FFC65BDULL, 0xB8A695B13BE18917ULL, 0xABF927C12C1635ADULL, 
            0xAE00D8F55A5CE1A5ULL, 0x6CA69EE188B3C7DBULL, 0x25AE070765C8D7C5ULL, 0x886690A00F8CD4F6ULL
        },
        {
            0x226DECF3C9B6D54CULL, 0x6253C6ADC0A2B717ULL, 0xDBBE902CD6F59986ULL, 0x322561E029A649A8ULL, 
            0xB235C80D9CDD5704ULL, 0x016A31691B44A3A3ULL, 0x46C5213DD5D9E0BBULL, 0xDFF3AF8D03C0FD3CULL, 
            0x0EC71E6A8178D134ULL, 0x457D0ABB1AE58FE4ULL, 0x22D38E8D15F4DE76ULL, 0x6411462E24333E1CULL, 
            0x5ACBB95C07986EE7ULL, 0x49C64E7E6EBBF450ULL, 0x1E91337A63E92C88ULL, 0xE713ACF28041F609ULL, 
            0x1C868E89A2A89BD0ULL, 0x24F145DF9E5F9B78ULL, 0x339A6E6BE10DB8B2ULL, 0x99907BADA45A0399ULL, 
            0x600985DFA1167362ULL, 0x6414A152053C01DEULL, 0xB341AD6DE6A67E30ULL, 0x002BA62C8E18B352ULL, 
            0x56BA6AC436BB5B80ULL, 0xA650229B1D15589DULL, 0xE6C1D5B797BD50BFULL, 0x8F746C2AAD07621FULL, 
            0xDBA3499BD4EA545FULL, 0x31887F03F26CC5D5ULL, 0x250520571F7FCCF6ULL, 0xC91905B8649D8BE7ULL
        },
        {
            0xB44C10BE910C6077ULL, 0xFA84FB9F3BA650E2ULL, 0xDAC2EC1625C650A6ULL, 0xB53A1D4D9CA7C69EULL, 
            0x76743F2AA6D1BE80ULL, 0xA02717429ADB77B9ULL, 0xF045F6F3D19003A7ULL, 0xAFE972A830256CDEULL, 
            0x410C1FED3828C58DULL, 0xF751FD2418D705A9ULL, 0x1A9C16F5BBB6876BULL, 0xACFF8117A2EF3A23ULL, 
            0xE4098E3957C01035ULL, 0x136435841837450AULL, 0x543B355161954A8EULL, 0x074F62A76981C127ULL, 
            0x50554A57461D2165ULL, 0x8BDA09DFDBEC060AULL, 0xF13E9515D4EA76DAULL, 0x7766891F7FC9CD68ULL, 
            0xE20D00534F7A5158ULL, 0x811471F60CAC78FBULL, 0x693CD5501FB68C2EULL, 0x070ACF4FD1039B28ULL, 
            0x0EB2D4847244B284ULL, 0x479B4F9CA05FB379ULL, 0x4FBE722DC14E7C00ULL, 0x1DC83AE5B841F67CULL, 
            0x01F70477C85AF733ULL, 0x0453ABE3253A01F1ULL, 0xDAAB430F713FCF28ULL, 0x15D25A2282FC6BB4ULL
        },
        {
            0x4F9E2EA44835847BULL, 0x98A21719345F9E5FULL, 0x0994474305F62B00ULL, 0x8BF5D2B5BBEA20A4ULL, 
            0x36B3ADB54AA39AC6ULL, 0x62111F986595DFB7ULL, 0x5FF1DAFFA37AE130ULL, 0xA4D899E8862DFFBCULL, 
            0xF74F8C4E611899B8ULL, 0x95A24F7654D149C1ULL, 0x7441BFBF07CC486EULL, 0x30C1961A80E9785AULL, 
            0xA874E55DA98F1285ULL, 0x578B4EE63C31901FULL, 0x06985BA67892EF11ULL, 0x392E4A3BA24138F5ULL, 
            0xB345CC9820E19CA9ULL, 0x3145D4B208031D41ULL, 0x2EA94F12FC973401ULL, 0x98FD05BB611FC32AULL, 
            0x5ABE647BFF7962ACULL, 0xBF5B74093EB8CA60ULL, 0x18C83D657A70FA62ULL, 0x09D8294398A752C6ULL, 
            0xAB6646701739D427ULL, 0xAA0B4206DE4700F1ULL, 0x73C46D74F4F6EA1CULL, 0xC21CA7D23F2CA212ULL, 
            0xD6B8F6D88503B3F4ULL, 0x938245BCF51F0F15ULL, 0xE7BEB6E1E50B9FBEULL, 0xF51D3399906FEC02ULL
        },
        {
            0xF8F72AF608FF7DBBULL, 0xC2B2742BDB26ED19ULL, 0x2D44004B27AFF190ULL, 0x028C204FD0EEEDF2ULL, 
            0x81E396617CF9E6BFULL, 0x36BB96FD4D8F2F5CULL, 0x1573C2391DC5407EULL, 0x2E81D100E324FD5FULL, 
            0xBD42C7243BAD8393ULL, 0xEEEE727341EA7ACCULL, 0xAEED2544C4AB00B8ULL, 0xF3B4B8F044DD88A5ULL, 
            0x403F120F5ECAE950ULL, 0xE5BE65D93F48AD89ULL, 0x236327A4642ADD52ULL, 0x8753D9EBE49081DDULL, 
            0xBF81D00564C7A109ULL, 0x6B271BB934D42F11ULL, 0xB5F0EBF0F937FF84ULL, 0xBD4326F0FDFEE7A2ULL, 
            0xA19E1B3785220084ULL, 0xC255ABD88E1BFAB5ULL, 0x29C1A804685148F0ULL, 0xA99027ED04D6F9DAULL, 
            0xDACB29ECACFFB790ULL, 0x3156283426D7CBFAULL, 0x1F5CD0B1CAE1F922ULL, 0x1F470CFA247C0743ULL, 
            0xA570F7897BB1E336ULL, 0x3E90E7568FA31C93ULL, 0x8B41A8DB2B3E611AULL, 0xA8A83E0918E20FE6ULL
        },
        {
            0x723707ECD77CFA8CULL, 0x6F81E3F9F4C6A99CULL, 0xBA4F26A5A10D7DC3ULL, 0x62C6304F23BC676DULL, 
            0xC7EEF733EC01AD71ULL, 0xEA26C631C0ED1076ULL, 0x27ACC04A6F61C5F3ULL, 0x495E977AC2622857ULL, 
            0x8B51588DA55DBF0EULL, 0xB34ED7F74CBCBE60ULL, 0xCC8964EAF168F782ULL, 0xDC0EE0B47BF054E5ULL, 
            0x2A4034C82424C997ULL, 0x3953ACE7F7B3CA70ULL, 0x18A24B9C89EAE021ULL, 0x666A403357E3D6F6ULL, 
            0xCDB7AB323F2A5FA8ULL, 0xFF6F0A9FC51C7484ULL, 0xBB4CAAB7A33C2773ULL, 0x4FB22F9C015CC823ULL, 
            0x20ABEF9B0E73AC3CULL, 0x5EE2375BFD5BDDB6ULL, 0x6FD522F4E87FF1D4ULL, 0x4A546CA38604C202ULL, 
            0xB47453A61A3ECA9BULL, 0x867119CAD4DB0B0BULL, 0x90972138B625847AULL, 0xD191DF12D0824FBBULL, 
            0x9DF48E321681784BULL, 0xCCFE1F46D0D80F07ULL, 0xDC24B81225DE50BCULL, 0x54B1C66460FCDB0CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseEConstants = {
    0x5A592CE0B3EC4320ULL,
    0x6918A153A2D2C9B9ULL,
    0xBBDD52B3B3DD36F6ULL,
    0x5A592CE0B3EC4320ULL,
    0x6918A153A2D2C9B9ULL,
    0xBBDD52B3B3DD36F6ULL,
    0xA84729879AA1E2D9ULL,
    0xC3B3E31A5397B854ULL,
    0x91,
    0x64,
    0x84,
    0x42,
    0xF1,
    0x28,
    0x1F,
    0xEF
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseFSalts = {
    {
        {
            0xA9155C3DE5730A2AULL, 0x48A8F792E8F91728ULL, 0x72355BC5D402F21EULL, 0xF07F4B44F75D79B7ULL, 
            0x024FD13485DDA841ULL, 0x4AA504A066D07354ULL, 0x58590866EC2A77BAULL, 0x97B009FD142EE2F1ULL, 
            0xEBFBC7E70BCFAA08ULL, 0xC282F78409265245ULL, 0x3EE640E19540AAFCULL, 0xBB23D8115290506AULL, 
            0xAB0E57DDD24EBEFFULL, 0xC612A0B0E76DEB99ULL, 0xEAC29498A056BD40ULL, 0x7A44F99142CF5B27ULL, 
            0x71376CC12FCCE6D2ULL, 0x35125A99CEB89BE4ULL, 0x29541934CAB55A70ULL, 0xBFE594048F9E5BE9ULL, 
            0xFA06A604F363AD2BULL, 0xB77B56AD1BDB3175ULL, 0xA1205108E321140EULL, 0x0B14589370C031C9ULL, 
            0xAF2427C2DED4A276ULL, 0x722C395C459735E2ULL, 0x66DDB4DC3C557A81ULL, 0xB14541CC9FB8C791ULL, 
            0xEA669E825F307CE8ULL, 0x06843DFE050EBC87ULL, 0xDFF11948C824D2B0ULL, 0x7B632EA1F8EB29A6ULL
        },
        {
            0x1114BED756D9B26EULL, 0x6F19DEE403F9AD68ULL, 0x36A5599486C2470CULL, 0x867855328476A795ULL, 
            0x56C976C844C57C86ULL, 0x5872473CD287C42DULL, 0x6EFA5D93665B442CULL, 0x43865C720B7FAC36ULL, 
            0x9754D12D7C974099ULL, 0xD66983A7CBB7F7C6ULL, 0x7D7584A8FF6BDFA1ULL, 0x9BCB0B691BE9755BULL, 
            0x82DA8572523D4928ULL, 0x0602DFF81EDC526AULL, 0x17CEC6F71BF976E9ULL, 0x9EFFEF8B4961AE4AULL, 
            0x470F6F68F91163B2ULL, 0xE6AE021C9FD38C29ULL, 0xC6D9CF1F7061204EULL, 0x2741D091F2608880ULL, 
            0x279790A9384F6AB6ULL, 0x6CF04222EACF381EULL, 0xB66BB731437C24CFULL, 0x675C1FBEE95DF914ULL, 
            0x3D36C1DBB675232FULL, 0x35BFED0B741C1054ULL, 0x565955F006501DD5ULL, 0xE109FC7A05926FB9ULL, 
            0x0BA39DCC9115245BULL, 0x0BAB6CB4B22CB5FAULL, 0x27CC59B83CD7DEBBULL, 0x040512250334CEA1ULL
        },
        {
            0xA9A13670A120B470ULL, 0xE430BC60CA103C35ULL, 0x0383D26273942F1AULL, 0xCB373E7A79984D62ULL, 
            0x79BD0C919D428D4EULL, 0xCEA11471C9A9302BULL, 0xA5F87366AB91B04AULL, 0x47F84C73A63E2C63ULL, 
            0x7C828D69A82C05F4ULL, 0x29A23ABEE1A2A76BULL, 0x983D6A26D66D2160ULL, 0xED7DDE5659A7E7A1ULL, 
            0xA3D305E69BC4CEE5ULL, 0x9E739AD3544D8270ULL, 0xBB883A7FB87CF741ULL, 0xED33861E0A98B6ADULL, 
            0x067E2B1D40EBEB2BULL, 0x0467AD4098D85A53ULL, 0xE85503BA52869F60ULL, 0x7A61C9F75D7459A4ULL, 
            0xC0E8A51FBB9203C6ULL, 0x326E7EA509AA41F2ULL, 0xF09FB1DE7AFDD29DULL, 0x39957ED82FFB4ED5ULL, 
            0x45540B6237D75561ULL, 0x592E3F677C15872EULL, 0x66FC60651AA79523ULL, 0xF8E84331477901F5ULL, 
            0xD73AE6EC2BD48800ULL, 0x81F741F456DFA8B8ULL, 0x6B24D51DF21FC938ULL, 0xFF2275C318CF1238ULL
        },
        {
            0x81EA5D41EBF21C47ULL, 0x70C88C3AB4D32B35ULL, 0xA25B1A530FF71484ULL, 0xB85F47B82258E8BCULL, 
            0xEFDCA723406D6337ULL, 0xD8F16E5E09498F69ULL, 0xE9FC09F50F818299ULL, 0x96AABB43E3233A54ULL, 
            0x70F748EE9FB11C27ULL, 0x79C2F2CE1C5E737AULL, 0x5EC07FF7EE953B6DULL, 0x412E0CC9E03948CEULL, 
            0xC5243BEDE8E05CDBULL, 0xF0F25FBDE95E8F99ULL, 0xD4380DDF1C9A0617ULL, 0x74C1C78525E10B34ULL, 
            0xD456B4AF60BD7E8BULL, 0xC8D35AE9D2F8C9D7ULL, 0x5BFF94FFF3AE5EC4ULL, 0x15949DC925237BE4ULL, 
            0xB42AF899AE9D1FC9ULL, 0xD617B26B7A56F842ULL, 0x272878E5CBC95140ULL, 0xD1822AB8CCE99EF1ULL, 
            0x098A7F8340623A29ULL, 0xED2E1CBE280FD5A0ULL, 0xFEF914E524BBADB4ULL, 0xA33A41FC257786B9ULL, 
            0x3DBD306E447A8271ULL, 0x106BD7CB72E3ACFFULL, 0xC71F8A569FA3842DULL, 0xE839EC307A94614DULL
        },
        {
            0x1693DDF737430C25ULL, 0x440E17142BACD2DBULL, 0xF8B062900403C8DFULL, 0x97B70B10ECED81FBULL, 
            0x745561BBFC835E51ULL, 0x1B8583A77E87B9D6ULL, 0xDA716599D36B32BBULL, 0x4991A9BC99C4C212ULL, 
            0x809D8F56020C1E10ULL, 0x191E283E266A0254ULL, 0x0A2CEE455DDD5946ULL, 0x5EEA6072CAE4009DULL, 
            0xE6C579866A4BD4F0ULL, 0x571BA8BE97EDE6B0ULL, 0x1057122809A5D7DEULL, 0x1B1C47A847D4144BULL, 
            0x26096063AC3BA835ULL, 0x67A7A1A9E8593A0AULL, 0x8AC398435B344BD9ULL, 0xE711565256ECFB9AULL, 
            0xEF484B97013B951DULL, 0xD3589C7CB6A77618ULL, 0x51E84D977FB60FAFULL, 0xB678F18819F37BDDULL, 
            0x2DACA367506D218BULL, 0xB0D70BFF17333760ULL, 0xB6D9C09942E9AE59ULL, 0x949ADAEED8B4E920ULL, 
            0xD09EE14EC8A6B906ULL, 0x20CB3FA15BE855C3ULL, 0x167A4824189831E1ULL, 0x7408F43DD94DE229ULL
        },
        {
            0x10CCCE9AE36540D8ULL, 0xA4BBED7F3DB00D61ULL, 0x54A5D48EA2048557ULL, 0x38F6033305274CE9ULL, 
            0x45B23A1ACE0F6D9BULL, 0x554179A25909A50FULL, 0xDF49F7C20400BC6CULL, 0x357C3B803A3D6F14ULL, 
            0xDF2E2F2272170431ULL, 0x973F807A9894256AULL, 0x16199F6CE74FE817ULL, 0xE3A863A893C760EEULL, 
            0x735BF68120F73002ULL, 0x23C2E78AA42E2C83ULL, 0x52EC041A98785D34ULL, 0x11E8A467E8EAD5D7ULL, 
            0x0035D4D11893B9DCULL, 0xE709AEFC22D01319ULL, 0x9B4026870C5FD462ULL, 0x2441A9215FD252FFULL, 
            0x7317AE9EB33AE924ULL, 0x1F5FF1269CB9183AULL, 0x77D5FC98E5CAB0BCULL, 0x77566383CD50423CULL, 
            0x3895E4A91CE45614ULL, 0x6686442277C20203ULL, 0x419D14A752AC7433ULL, 0x639ADF3EA96C7376ULL, 
            0xB2C6C7D6CE5817C6ULL, 0x94CE429474A75A50ULL, 0xAF3505BD09669D2EULL, 0x67D1E4C73B1CDA95ULL
        }
    },
    {
        {
            0xC8C0C4613DEB23D0ULL, 0x7EF967DAF82A0BF4ULL, 0x89CDAFC6AD2FFDF2ULL, 0xD748813A34D12F5AULL, 
            0xC6EA62873B241C4BULL, 0x5E895ABB6909197AULL, 0xF46C523248575DA2ULL, 0x093E7851374801BAULL, 
            0xCE567755B665E2FFULL, 0x956CEECE622F4762ULL, 0x3CE67182A8723B1EULL, 0x2797447C7CC9243BULL, 
            0x7C78AA47F6CB9C8BULL, 0x47B4BED9969AE573ULL, 0xDE62074E46BD2A78ULL, 0x216190CF36950E86ULL, 
            0xFE437462557DFDABULL, 0x1052940ED8492449ULL, 0x93B62F55B5F7D1D4ULL, 0xB3A42FCEDA1EF141ULL, 
            0x9BFA2E18B757847DULL, 0x7C9525B6FA6E582CULL, 0x2F105B850544798EULL, 0x6FBAA9E3495ACB20ULL, 
            0x50214905BBAC19E0ULL, 0x7A8A4A83B0E7C028ULL, 0x613A4ECC29D4F2DCULL, 0x5DCF5D3281326ABFULL, 
            0xD5953AA9D692C0DEULL, 0x66396DAA5714E632ULL, 0xF20A2CFB12997F01ULL, 0xFB385302ADBAF509ULL
        },
        {
            0x0D49FEE059599692ULL, 0x21B7FED80A20EB64ULL, 0x3FC90F13F8DE040AULL, 0x7C098F4A31A39873ULL, 
            0x99C1B68081B4E1B2ULL, 0xCE7399C2FC8AEDFBULL, 0xB29434C9BEABF9E6ULL, 0xC75AC749BD84C7D2ULL, 
            0x55F022BA8D681214ULL, 0xC84A5EBEB7872BB6ULL, 0xF339605DCB7DB85DULL, 0x25C400EF2BF71A0DULL, 
            0x51D6AE7E15FDBCF9ULL, 0x585935C3E6DC8862ULL, 0x689BCC6FF3242860ULL, 0x56FFBA82FF7776C4ULL, 
            0xA8D1C4BBAA4041EAULL, 0x9F2B213BE7F94503ULL, 0x2631F07F3EB77C6FULL, 0xDB1C45105A6D9D0EULL, 
            0x87AD1A5BAE19CE9DULL, 0xAB2E2671ABFB0346ULL, 0x5EA57E8811E18B36ULL, 0xB9E157A574997A0BULL, 
            0xA7C4E5399C9B1982ULL, 0xCF332265D02C666EULL, 0xBCA3C33EEAACC884ULL, 0xD731926B7E83429AULL, 
            0x5898F46767F76E3BULL, 0xA9AB6D99E0B73EADULL, 0x444E3E642826B096ULL, 0x8A1EB071C18CFF46ULL
        },
        {
            0x7A2F690072F8758DULL, 0x9E62F6D580870847ULL, 0xCC5BF511ED4A1CEAULL, 0x08C544811F72022CULL, 
            0xF84EB3927248C80BULL, 0x675D8D34BFE38DD1ULL, 0x924843E01B8BEC28ULL, 0x8F83433BFDB2C480ULL, 
            0x9717D1EA02C9F4EFULL, 0x52F82E576D36397FULL, 0x15CBD6E69BDCF04AULL, 0xDE4186F71C63BD26ULL, 
            0xDA9B788140306F41ULL, 0x78E822E860DB8024ULL, 0x622C67AA1D2DE580ULL, 0x33F3A8D406F22AAFULL, 
            0x0783A5FBCD933B4FULL, 0xB516B8FB74EB3CC5ULL, 0xA50FF4B953555B40ULL, 0x0F2A1357548AD594ULL, 
            0x906FF44E69E15E83ULL, 0x5441336A6CC4C99AULL, 0xB3A96D4F0BF5BC03ULL, 0x14576CC9F319A845ULL, 
            0x8B01E005613C3950ULL, 0x8AB4B6BB264E300FULL, 0x8A8D8A418CF2B945ULL, 0xCBE17BFF95662C09ULL, 
            0x872770F25013B027ULL, 0x46FDD2AA60A53797ULL, 0x2C9DF5F57278F705ULL, 0x35BDB2EBB030AEACULL
        },
        {
            0xFFE21FEBEF771936ULL, 0x57A552F707097AF1ULL, 0x434B3A585D34F1E0ULL, 0x0D0E71405DF41C63ULL, 
            0xD7AFF926E485E2C6ULL, 0xA08830C9BD38748EULL, 0x83E0512D3015B219ULL, 0xC2272A34E777FEBEULL, 
            0x477B956E39A4B70FULL, 0x15C95C0E3D871109ULL, 0x1AD07DF1E3C15D73ULL, 0xA2869BCE1B2A5DD8ULL, 
            0xDDD226453BA52BF3ULL, 0xE4D21AEC7466582DULL, 0x2CF90C9CF76E87E7ULL, 0x0F366287EEB4DF2EULL, 
            0x2C82C03A42B12A14ULL, 0x942D895DB7097097ULL, 0x57EE2277FB2E0550ULL, 0x3A25896AE0528314ULL, 
            0xA07225CD22B62631ULL, 0x1DC226646FAAEC44ULL, 0x94FEC0D5C93DCBD7ULL, 0x5311842C392FA0E5ULL, 
            0x16C83C7DE9633ACFULL, 0x34301CCC0AE829CCULL, 0xFDC009DE462C6AF2ULL, 0xC36B3525053109FDULL, 
            0x05634C66E4F0E80EULL, 0x2CFACA0DE3E6D18BULL, 0x71CB676C1941DF83ULL, 0xCAA99B32550961EBULL
        },
        {
            0xF0AD07D6FAC75C18ULL, 0x4600BB2D263077EFULL, 0x1D529EA8B64603FBULL, 0x340653CA73A5B2B2ULL, 
            0xD3803F15A8D2F285ULL, 0x82B432FDA740AB8FULL, 0x99E5FC69F8C530A6ULL, 0xA4A5C81825E35968ULL, 
            0xD58AC664100375DFULL, 0xFC625B2C74DFD477ULL, 0xB648C3773AFCFA7DULL, 0x675C9F9ED4F2CEBEULL, 
            0xDFA2E37779FDB1CEULL, 0x385ADABFEACB1AB1ULL, 0x8EBF5BEC87C7EDF8ULL, 0x1B8AD0C5D936F933ULL, 
            0x56489E1B34696806ULL, 0x44419263E65B665EULL, 0x126204E6072B5361ULL, 0xFC277259BC9C73DEULL, 
            0x92E968099DAF38BEULL, 0xF2CDAE7B95F3D92CULL, 0x8E80DBE64B2BD5D8ULL, 0x1F45449761365895ULL, 
            0xE886FD9029834C20ULL, 0x6841372F16A5130AULL, 0x7BC915CC6D9FF80FULL, 0xC0F0F289E398793DULL, 
            0xEBC80AB52A6963B4ULL, 0xE9B7A02A6DF7D802ULL, 0xC26CDFDA1B688CD0ULL, 0x1359553FE5BAD63FULL
        },
        {
            0xB8E4C4F650B2FDBDULL, 0x9A6B0F7DADDB5D46ULL, 0x46464017B2FF1C78ULL, 0x81B59349AF1AB37FULL, 
            0xB169122F3BA8D156ULL, 0x872E552281ADF52EULL, 0x109EC74F14AE7A04ULL, 0x6FBC464B25C14E53ULL, 
            0x38DDE140654729C2ULL, 0x13175A53B9B7AEA4ULL, 0xEF8793D6AEB952A6ULL, 0x5AA3750D0A516547ULL, 
            0xE0492D7D948017F0ULL, 0x679FC55A5A5361F4ULL, 0xB53473E6782DA265ULL, 0x372C5C4F18F574E5ULL, 
            0x84A9C33F739749EDULL, 0xA9460D1D4F0E9FE3ULL, 0x57EBB5FA8D706019ULL, 0xE7F8DF8F675DF05BULL, 
            0x275132B047C91C5EULL, 0x378D88B84ED08CE1ULL, 0x01A83B6450CE87BDULL, 0xD9149032DB91773AULL, 
            0x3C9E2F471550E753ULL, 0x1E8F59467B68438AULL, 0xA2DCC4E401B892F6ULL, 0x1EBD40CE03E415CEULL, 
            0xD0AA9FCF249DC647ULL, 0x113F3F982EEBDF0EULL, 0x14B0320F41265EE9ULL, 0x08ACB5FAED1C2B4DULL
        }
    },
    {
        {
            0x3C9E947C03A36663ULL, 0xDF57408374A695E7ULL, 0x9E427B9F56CA4360ULL, 0xACD1ABF76D8817A6ULL, 
            0x1657783DBAF20E07ULL, 0x612CC8DC6CC2DE4DULL, 0xABB46BEFDFDF499EULL, 0x5B2CFD724E219A8FULL, 
            0x4D1395A3300D10C5ULL, 0xB3104794A23EB48DULL, 0x7A8EDC6A4F1C104FULL, 0xB91BF274FA6090EDULL, 
            0x6F998E5478EA5D3FULL, 0xE194F070B4BD57C2ULL, 0x11474585D90246C8ULL, 0x0774BE71B95306DBULL, 
            0xC8EEC75C23271D90ULL, 0x627D6E5C60F15C09ULL, 0xD7581A90C5108E8DULL, 0x9727FC200B28EB12ULL, 
            0x2B12FF72C84F926EULL, 0x537D0C590CA6012FULL, 0xFD3D88CE95BAB17CULL, 0x157285AA442AE592ULL, 
            0xD3E21E8F06175A6CULL, 0xBC12C65C93124808ULL, 0x33BDC1C89BA6BCBFULL, 0x2510976F10C418C0ULL, 
            0xB0A077A77276F381ULL, 0x413ED3DB03B66AA6ULL, 0x0671BA2AF91B6213ULL, 0xA71326D47B084531ULL
        },
        {
            0x7DA95E756BBFD061ULL, 0xEBC6EB2B19CEDE30ULL, 0x2B3160D913EFE195ULL, 0xDA9F45510B079D20ULL, 
            0xD5E9C0BB1F795BDFULL, 0xED8737D3CD2B9A17ULL, 0x54509EDA6025E6B7ULL, 0x38FDD695B773E1A4ULL, 
            0x3BDCC44AE3D900C4ULL, 0xF33C371D92AF0640ULL, 0xE944180485F5934CULL, 0x32AA90F501B9978EULL, 
            0x24AB0D83B09C63FEULL, 0x4D391B3454FC2054ULL, 0x36822241A9069E8BULL, 0xBBA988CB098780B5ULL, 
            0x8643352FE743CFABULL, 0x0AD71D09BC400EE2ULL, 0xF9EA939BBAFE6697ULL, 0xEFBE2C6FF7AEC1A5ULL, 
            0xEAA396F17B1B512EULL, 0x271924A0BA54A375ULL, 0x5A794237B6791F5EULL, 0x5BAF13D403BC62DBULL, 
            0xB61A1F171FA6ABD3ULL, 0xBBAA3D447079569AULL, 0x14DEFAC4B5A74444ULL, 0x67EED82D9B86EBE2ULL, 
            0x209E1E8F43328C63ULL, 0x367D9573BF2B5992ULL, 0xEF2043AB5C9EAB65ULL, 0x2A33C0CBBE11D623ULL
        },
        {
            0x7371312CE189D7B3ULL, 0xED2A950A4B2FE982ULL, 0x7149E1806E50AA56ULL, 0xA5762203A1A72F81ULL, 
            0x7988C338AF6805E3ULL, 0x313F0F2FF619B733ULL, 0x0B5F13FC4EBD6587ULL, 0x4E0E2B08CE97073AULL, 
            0xDADA98CE15D063B8ULL, 0x01F9E751FC5936F8ULL, 0xFD60F9A92091259AULL, 0x0EAAB1B96BF65B7CULL, 
            0xEB2C6100576E973FULL, 0x0DB7A49EC8CF285FULL, 0x1BA923298A83F815ULL, 0x547DBF740E032BDFULL, 
            0xF9C7F628C63798E8ULL, 0xA64EB043BD02DC8DULL, 0x8F8428D3B2179EDCULL, 0x5024E80E0D6A42DEULL, 
            0xE67C2BDF512A0797ULL, 0x5A98CF9F77EA229EULL, 0x78A92E6741032D16ULL, 0x65D259CCFA3FEEA9ULL, 
            0x279ACEDB0F164549ULL, 0xF3E192753B096008ULL, 0x1F68FF7A3F037DCDULL, 0x733D201BA9838830ULL, 
            0xFD7F6C4321447E3EULL, 0x794EE01CB92DC4F2ULL, 0xE2148728ED7C0916ULL, 0x97FE04CC99E937B9ULL
        },
        {
            0xECC7F2B988F85EECULL, 0x901968E61753A18CULL, 0x673346A22D4429C7ULL, 0x61CA7BD514BD618CULL, 
            0xAE14A77728538DF0ULL, 0x81BDC5DCC4AD4023ULL, 0xDC767802731DDDF1ULL, 0x090C87D96042569CULL, 
            0xD304EC86646DD32EULL, 0xEF54A867B960F7F1ULL, 0xDB02616221345A1FULL, 0x2E64FC082C75BC1DULL, 
            0x10D9F7CB7C8440F2ULL, 0x9ECC5564E2D5F7E8ULL, 0xA987CA1B32E3F620ULL, 0xBC8F4D6F9B923E5AULL, 
            0xD131684C6FFF6432ULL, 0xC0C124E5FF60A2E6ULL, 0x1D9C9C90D4EE98FCULL, 0xA5FB5AE705CC7A5FULL, 
            0x6507435F5A69BD01ULL, 0x2B24E2397C954D51ULL, 0x7CA9E1D17035A15EULL, 0xE52910E44364E9DAULL, 
            0xD5E4927D8679E5A1ULL, 0xDD5D6A08A5A75285ULL, 0x76804B536824A2D4ULL, 0x465FA1F0F1E9DA8BULL, 
            0x545B59542079827AULL, 0x2B889181D754844DULL, 0xB6DD7BFC73DD03A4ULL, 0x2B076F10A03F32F6ULL
        },
        {
            0x94A700BEDC5143D7ULL, 0x74826A289ABF344BULL, 0x4F276DF686D46C8DULL, 0x11434FF7B98F3663ULL, 
            0x62AE7FD184E0C3DAULL, 0x3BDF360A2863CF9BULL, 0x527DE8DCC2E87FC7ULL, 0x35465DF5F05C79A2ULL, 
            0xA75532B0A82F5EDEULL, 0x0D382B7F7E0E769BULL, 0xA184E332F38045E8ULL, 0x2A4C80586CAC3F3BULL, 
            0xD8198581FCA4B272ULL, 0x48CE51F9B4638462ULL, 0xE585976DDBA6FA40ULL, 0x205A39C0DA27AB58ULL, 
            0x2209E2179E238278ULL, 0x143F43C4BD60C190ULL, 0x331AE1D802055D21ULL, 0xDA279561FD3239DEULL, 
            0x21BB485CDAA99555ULL, 0xF574EEC507D09400ULL, 0xBC56D32462338BF4ULL, 0x0D53A307676F31B8ULL, 
            0xD0EE55A18349BB98ULL, 0x680AADE38AF14683ULL, 0x5FA5074DF5900AB3ULL, 0xDE64D0C0AAD7B6BEULL, 
            0x9A89EC1F4060EA56ULL, 0xE19A293C034B022AULL, 0x873ACCECCD9D2C47ULL, 0x828F433276207DE5ULL
        },
        {
            0x520D1B7C042D24CEULL, 0x4EDD1E7285185012ULL, 0x372F189A152DB17CULL, 0xDB851ED2BFCAFD6FULL, 
            0xBC521B358399324AULL, 0x7212F308CC546C6DULL, 0xC5566EE9458A6848ULL, 0x87FF95D97DC4499CULL, 
            0xBD34B3A3E83BC9D5ULL, 0xE37118A90A4BDBDEULL, 0xB637B2E06C693215ULL, 0x9423087BE3A7D21AULL, 
            0xF8144D61D34C55DEULL, 0x1974F6A67DF836FBULL, 0xBEDA46943D1986A7ULL, 0x502D9A8F6FF637DAULL, 
            0x9ED8C2B2C027249BULL, 0x26121991A22682EFULL, 0x9DF8DC1B248BF71FULL, 0xFD2AFCF034071AB0ULL, 
            0x7F1A6FCF7815306DULL, 0xBF3B7696D47FD191ULL, 0xD7D59A3834342181ULL, 0xA2545BBB636D95CBULL, 
            0xC4940455A93EA482ULL, 0xCF39ABDCE2FF8653ULL, 0x309B5452CCE907AFULL, 0xB0EB5D1D448FEE13ULL, 
            0x3DA3B439B1977EC6ULL, 0xEAC9AE858475B932ULL, 0x335D3EDD1310AE20ULL, 0xFF060A9EABA113DBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseFConstants = {
    0x736601DA23798249ULL,
    0xBE5952D25968D4A1ULL,
    0x5F7AA45F98F0685DULL,
    0x736601DA23798249ULL,
    0xBE5952D25968D4A1ULL,
    0x5F7AA45F98F0685DULL,
    0x6A075B99AB3C1105ULL,
    0xD0B1537ED19F050EULL,
    0x6A,
    0x31,
    0x1E,
    0x12,
    0x48,
    0xC3,
    0xF0,
    0xD1
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseGSalts = {
    {
        {
            0xEF906D34FADABB86ULL, 0xFFBD0B2FCCCAD40DULL, 0x8138D06784C1ECBAULL, 0xC36F6F421F7D99E9ULL, 
            0x7E713ADED33ED729ULL, 0x0BDE85B9FFC79B66ULL, 0x35638719B621E264ULL, 0xEF75588F942A52D1ULL, 
            0xD307119FF8A61C51ULL, 0x8233D8A80AA16181ULL, 0xA7871E5FAE52298AULL, 0xBC53925D561F84F3ULL, 
            0x8EAEDFF8A63F464EULL, 0x6C3DF3F75B7FF53BULL, 0xB19BF39BF9C80CF9ULL, 0xA98E39664CFAFB53ULL, 
            0x44C195DF014DCA06ULL, 0x3277D2C3EFA47BFFULL, 0xB691F1B136F8C7C7ULL, 0xD661D44E31FA54C1ULL, 
            0xBF9373D59610A76AULL, 0x624E3DC82E599728ULL, 0xAFD31F08BB6FABDAULL, 0x86429106BD396A5CULL, 
            0x46578A603AF99AB3ULL, 0x8B25936D3640CA12ULL, 0x3A1519CEEE056791ULL, 0x04828A34A4129E3BULL, 
            0xE79A244BA869689DULL, 0xB20629E9970A9814ULL, 0xC82D2B0B4353A942ULL, 0xDB93D6BAC5ADE9F5ULL
        },
        {
            0x4EC52F27717A5C4DULL, 0xEA90596B29114295ULL, 0x3FC6390F6CCC3366ULL, 0x852E26B678D55E0CULL, 
            0xF52723858189BB28ULL, 0x48354E3423923A6BULL, 0x0A0A7354BB9D09C3ULL, 0x65883BE749F274F4ULL, 
            0x97D3C9897950BAC1ULL, 0x3FBFB6A338DE0471ULL, 0x3D55AB386AC3AECEULL, 0xEE51DA206E41514EULL, 
            0xEB3A2F1DF94229EEULL, 0xFCBD2C995A8A5868ULL, 0x2533CF51DB72043EULL, 0xA733E26C873FB66BULL, 
            0xEE7543D648785F22ULL, 0x6A26773B77838BB6ULL, 0xBA30CBA7DE831669ULL, 0x7DB750A6685B9F7FULL, 
            0xC68B7097992C7E75ULL, 0x73AEA41762ADA280ULL, 0x9135825894CC46AAULL, 0x821BA72E37C61D1BULL, 
            0x5879821EEF71D97AULL, 0x19D3DD1FB1E4E6D4ULL, 0xE9A42178832E2CF4ULL, 0x116917C180D94FBFULL, 
            0x9F8686BE1DAD926DULL, 0xC16AF7928BA960C7ULL, 0x2B0C242DA2F7AED2ULL, 0xD65E9B6E9E133199ULL
        },
        {
            0x95A51756AD27CD64ULL, 0x741869DD63D3A9C9ULL, 0xEF976223A3C1C57FULL, 0x509CD939A6186864ULL, 
            0x4F775A20F4BC1488ULL, 0x2CF9D75DFBA8D560ULL, 0x8B970E2CA386C4CAULL, 0x78827FF953A6C31BULL, 
            0x33ABA56A8A28BA86ULL, 0x93B4AFFA935BD20CULL, 0x77A2D5AFB0D83A19ULL, 0x47F256966F4D2014ULL, 
            0x9E38B153D53ABF91ULL, 0x103C1DEEF0FCD15AULL, 0x53510C6818586CCCULL, 0x29E3CA3B1AD2B085ULL, 
            0x6D5FB65E719A2DDCULL, 0x970725DF08A4FFBDULL, 0x0CDC8C975DAA6673ULL, 0x1F9CFE0947F73317ULL, 
            0x3E1AF8E00011780BULL, 0x7FC6C4531F52BEA2ULL, 0x4C80FF06F94B9E1BULL, 0x35CEBDFE33E8233CULL, 
            0x4251BC6B876AC327ULL, 0xBC180789FB389CFBULL, 0x83AC25D8FA747CAEULL, 0x4DA312A003574C30ULL, 
            0x7F25DE3BE017C68DULL, 0x10746671F8616FC1ULL, 0xF20FA36A45F70E1BULL, 0xE91F54CDEE3A5898ULL
        },
        {
            0x35ECF16C57F38B5DULL, 0x2B54BA8C1F371D0BULL, 0x3FCC1EA4F63F1055ULL, 0xB7B7D0A527B65AB5ULL, 
            0xB375BEC06B93F581ULL, 0xBFEC89BB34572910ULL, 0x760EBECBFEB68BB8ULL, 0x18EF660A8EF39EAAULL, 
            0x188C5E8E43BA7071ULL, 0xCBC9B876FB27D2A5ULL, 0x97A116031817D4C6ULL, 0x10623D8DF0CC9198ULL, 
            0x33E4888D0DC822B2ULL, 0x3D13C658D9787ED0ULL, 0x253C0426A6791A06ULL, 0x2D4854E16599DE00ULL, 
            0x336D2DA93570E77BULL, 0xD1C9931A72B713E9ULL, 0x4A5580E032A4ED95ULL, 0x4D30ED407F48E094ULL, 
            0x90E1BE0BD7D0FAB4ULL, 0x3BB9788C3DA5EE0DULL, 0xFF5AF184946BAA53ULL, 0xE68EDB8294C85329ULL, 
            0xF3EAC07AC3286858ULL, 0x6F3591E8D321140AULL, 0x1A3AAD532323C7C8ULL, 0x32BA4585B29F2787ULL, 
            0x122E6617ADE0467EULL, 0x5BC67879E0860910ULL, 0x8B8548268D34CD07ULL, 0xA6E6020A4AF2DCD6ULL
        },
        {
            0x557862455F536D81ULL, 0xEE2F0DD1B001A643ULL, 0xF12AE8FE90BD62C3ULL, 0x4D0F076063B219CEULL, 
            0x04BDEC46184D021FULL, 0xCBCCAD61DC0974F6ULL, 0x889628D28C44FBB2ULL, 0xB63F3DCD90F77B3FULL, 
            0x654596CD273B643CULL, 0x3355ABE976A95495ULL, 0xDB7E2167DA2E30ABULL, 0xDE93132F7DEA8327ULL, 
            0x485B3620B6E6D959ULL, 0xED8E02025FEC932AULL, 0xE9F166F6119B9A4CULL, 0x46A8A4A6DCF21EA6ULL, 
            0x830EA03311BB70BAULL, 0x3381B28E2438BF47ULL, 0x8BAA5DCE4E28A09EULL, 0x2776483617E0397EULL, 
            0xCA464102C2A852C2ULL, 0xB2E5FD0DE2E4EB02ULL, 0x99C2A5E331BD3F39ULL, 0x17AE8D07735D996BULL, 
            0x9F78135B6B80301EULL, 0xF4A64E5995A97D1CULL, 0x4F84C51FF65BCA5BULL, 0x21E26010000D666BULL, 
            0x7A603E66115B03FBULL, 0x19CC19228F92FB3CULL, 0xFFB75F045BC7834EULL, 0x6A55467808C8D891ULL
        },
        {
            0x40E5246DA446EFF6ULL, 0xBBE75B1411D93F56ULL, 0x5F7FF21BF5D891B3ULL, 0x5BFBEDFDC0464657ULL, 
            0x583E5CA64DF53B10ULL, 0xEE670EE5CDE267C3ULL, 0xB862B3E48F6E4487ULL, 0xAA9FB7D87A2CC949ULL, 
            0x189F140AFAA2D263ULL, 0x66234D2A2E97F0CDULL, 0xA446E315A109F66DULL, 0x761CEE2B2A342026ULL, 
            0x0F0CEED90BD11D99ULL, 0xB84E9710A5D29040ULL, 0xFF7F0955332B5459ULL, 0x538F69CD1753EBE2ULL, 
            0x35ED538B3314AC2EULL, 0x3A231732D55455ABULL, 0x98A134A83ED08877ULL, 0x9FDC281E9C857F7EULL, 
            0x1288D661402B1AD7ULL, 0x7C801DE26331BD5AULL, 0xC9768A27D464EFF2ULL, 0x5061DB4699669953ULL, 
            0xA0C1331942D7B104ULL, 0x86C6AFC5704DCE70ULL, 0xC2025FC48A50070AULL, 0xAD7F11FA03492232ULL, 
            0xFE8C93242CF02F75ULL, 0xD32F1142C33261E2ULL, 0x75ED2048B1EAD655ULL, 0x56581499B4C72698ULL
        }
    },
    {
        {
            0xD2F9E6392F7A1388ULL, 0x4021847C57C5BE24ULL, 0x11F2305AFD2662EDULL, 0x86E603F9561718A4ULL, 
            0x5069584751F9F77BULL, 0x09A032A584211059ULL, 0x2163CCF17AF9B955ULL, 0x251D80FAB82C8501ULL, 
            0x73B41E6A423442B3ULL, 0x5BCBABDF86C93AC2ULL, 0x94CAC018222DBB4EULL, 0xD40693915ECD85E3ULL, 
            0x8812B6C978B1AE80ULL, 0xF38348A83BF8EEDBULL, 0xD9C7C032E7FC37EEULL, 0xC4AE99579ADD34F6ULL, 
            0x440A19EA83B07BC4ULL, 0xC1F525267F568891ULL, 0xBFDDF3207449FD48ULL, 0x2E3EB19C24C08F8AULL, 
            0xFD078573A416CE20ULL, 0xDC0D421D06F70753ULL, 0x1FBFB7890E9B8059ULL, 0x933DA5561F91E4F9ULL, 
            0x237866ACC1D78B1FULL, 0xB3701475369630D4ULL, 0xBE14FC219F0493AEULL, 0x091060D75EFD5B5FULL, 
            0xE2FD63A81B9532D0ULL, 0xDCC9F0CFABA65FE4ULL, 0x8580794FBE0DD5C6ULL, 0xF9F8405DAB36344BULL
        },
        {
            0xFC57752623D113C0ULL, 0x20B9CC06B3BF00E8ULL, 0x533767A3E214EC9CULL, 0x975A8856AF6DC86DULL, 
            0x54443029D60AF4C0ULL, 0xA8AD4FAFABF0F82CULL, 0x571F9D9EE7F102BCULL, 0x121A63868CDB5A4FULL, 
            0x937F13044D7D0B88ULL, 0x006EF5E36C40ED34ULL, 0x96D52BA53881E2CAULL, 0xEB5E77FBD81CACCCULL, 
            0x324DE36F0BBBAEF2ULL, 0x3A3F671BA24725BAULL, 0x2C7549B5F1FBF195ULL, 0x1EE1B7AE713442CCULL, 
            0x8BF43CE542C0D505ULL, 0xBB57E327B65A16F8ULL, 0x894893AFD33C1343ULL, 0x4BDD59021DA82861ULL, 
            0xD0C01283E6BA661EULL, 0x8EF89444D1C147D0ULL, 0xBF325C129F75A46CULL, 0xCD1A92409563BEECULL, 
            0x88AD02D6FC22ED98ULL, 0xA9821F70ACF70092ULL, 0xB1E15CE1981CB5CFULL, 0x66C216CDE0A3E9DEULL, 
            0xD12BD8BA2F2C7C6BULL, 0xA8D8D2FBD95A4508ULL, 0x9C955BFCE060501CULL, 0x7600BFF1763104F0ULL
        },
        {
            0xA85A660F09CFF6C2ULL, 0xE0CFC936FF4BA6E4ULL, 0x35CFA2673D3A493EULL, 0x008DBC20C0D16D52ULL, 
            0x5019893A6D15F7AEULL, 0xBFC23A91625ACC03ULL, 0xB2A2B78E4CE1974EULL, 0x7DF948500FE7A6DFULL, 
            0xAA2CE58B40BDF78CULL, 0xB57A098FF1DC6AC2ULL, 0xB70CC12AE926E8A4ULL, 0x79B4236CD2D54FB5ULL, 
            0xB1D728BCBE6802DCULL, 0xE39B5502DDE8878DULL, 0x6654E963D3DAA2DAULL, 0x955988EB9CCBF5EFULL, 
            0xA49086AFFB70DCC8ULL, 0x7D05939F837B9F13ULL, 0x3B5917804211EFE2ULL, 0xD285723840BEC099ULL, 
            0x1F9DCD66A27BB68CULL, 0x8417F62F6AA3BB20ULL, 0x82CD6B656FF11F94ULL, 0xFF4A8445764B99DAULL, 
            0x4E2B3A3E586B4294ULL, 0x926D3667313CC4BAULL, 0x972A7E826672FF01ULL, 0xD124135D1D3475A0ULL, 
            0x6545FE54C5DF95AEULL, 0x247C7AEE8869E31AULL, 0x7959BDD3B609F603ULL, 0x4EE58DE5AA28E534ULL
        },
        {
            0xD90FB6D98C3D6389ULL, 0x30B7CF1C8B82948FULL, 0xD7E9541AF803F461ULL, 0x56A1D5E75F8F9E70ULL, 
            0x6DF4151BB9239D95ULL, 0xE0773B5AD9393EDFULL, 0xE168C097ADFCD480ULL, 0xB4B198572E73591BULL, 
            0x4D7438F70A80046BULL, 0xFAB2E69E3B92FD9AULL, 0xE1AD6D10C38CF294ULL, 0x2BF8F19EBB15A995ULL, 
            0x7EA2FA3A4E72D665ULL, 0x77B8E6A4066744B8ULL, 0x633CCEB25EE45B8CULL, 0x67E951D9C1BF5C6BULL, 
            0x79EB20B891CB9F36ULL, 0xDA632A5F62AFEF75ULL, 0x6855163907E80E89ULL, 0x4657AFB2C2DEEA94ULL, 
            0xF86D32BF7BA68171ULL, 0x41F138F5710FC855ULL, 0xB9C695EA10AA2CC9ULL, 0xBFA97B5A34D451D2ULL, 
            0xE75A5209FF44AC98ULL, 0x11193894E3247654ULL, 0x5C693D9E0973C25CULL, 0x83849BE8CD6AAEF0ULL, 
            0x66EC79EF09352942ULL, 0x45B57A184F663DB4ULL, 0x0DCBBDE9CC0D1327ULL, 0xB6152F7CD80BFB33ULL
        },
        {
            0x7132AD9ECFD881AEULL, 0xB0EA735D0A559619ULL, 0x17C07132803AB500ULL, 0xAB13A09EB3841378ULL, 
            0x5B404F4BFC508545ULL, 0x3B11F5E8985A396BULL, 0x8A7C474F55623DC0ULL, 0x8C577D69C3150BE5ULL, 
            0xEB76052E76318DFEULL, 0xCF3300C2E6A9CC40ULL, 0xAA322A46C5BE30A3ULL, 0xE3CD1ABB979B3B58ULL, 
            0xE9725D02C70E869EULL, 0x8FF86343E180B459ULL, 0x0DAF697FE6969C55ULL, 0xCD4E671B13CCBDB2ULL, 
            0x5C0E644B6DBF0AB3ULL, 0xE4EDEE59289AD5FDULL, 0x3EA4DEC67B29850EULL, 0xF0CDF6F71BA00EEEULL, 
            0x7F3C7150035B229BULL, 0x3AD0E4EF1C42B2EBULL, 0xD716B24F7FF7E859ULL, 0xCC9C6FABD9EEDBF8ULL, 
            0xFEC0A6A91E1755EEULL, 0x6CC8BC09750FA7F0ULL, 0x7D29D7CD31348DB3ULL, 0x9BC5DC9D52904470ULL, 
            0x1A1D52E5A9C7C9C2ULL, 0x192FC617870666FAULL, 0xBCAD6040634EDBB7ULL, 0x435BDDF97BE6EACFULL
        },
        {
            0x50C1B242FAB92AE8ULL, 0xE9AF9611696A1E5DULL, 0xF7D70F5D6B5DF0ECULL, 0x32173B191AB60C39ULL, 
            0x05420896DDFAC4CAULL, 0xECA22691E17EB163ULL, 0x527E6642C4CF980EULL, 0x47BE01E5F5DB9B00ULL, 
            0xBE0C365C7CD138E7ULL, 0x8C6A3DBC070B25E7ULL, 0xFB0860A6585E565DULL, 0x90414CB9DC6D82CCULL, 
            0x5B3E2DC21CCE8151ULL, 0xB17F8DF5BAEFADECULL, 0x57C89859B83F0C4AULL, 0x9C322890A008701AULL, 
            0xF07BB3F09DD56F1AULL, 0x6FAA93D87EE69EB9ULL, 0x93309648866F4757ULL, 0x9CEC25CB9B0054D5ULL, 
            0x1F6771D8AE58E29FULL, 0xAD57D46894BB8B17ULL, 0x049747F48646289EULL, 0xD9222C0ADCD2FE2AULL, 
            0xB2DDC5AFCEEBFB1FULL, 0x8C0749EC01A31FADULL, 0x58C04D5F47742465ULL, 0xCB33E2A09E321775ULL, 
            0x10DE4F8410292E71ULL, 0x5727D8D0C94F4779ULL, 0xDC27A7F7A88F352EULL, 0xB2648C7A494D0CC9ULL
        }
    },
    {
        {
            0x86E98997F6C10A51ULL, 0xB145ADC3C1E742D3ULL, 0xE22438AF7BE4C2F1ULL, 0xA27C30BAA50E0CF2ULL, 
            0xD57BE3C23471F5B6ULL, 0x7BFF5E994957356AULL, 0x45AF8FB775295D80ULL, 0x71FC65323D441142ULL, 
            0xC89199CA72009196ULL, 0xE017D85D215ED084ULL, 0x75960DF60EAA43EEULL, 0x3D38CCF0EB59E5A8ULL, 
            0xAB9886719F39D4B1ULL, 0xBBCCAF7B601766F1ULL, 0x7ED66E9AB2C7B922ULL, 0xA4C424DA4004FB22ULL, 
            0x53F5D717FC125D16ULL, 0x50CA952A80286168ULL, 0x02FD097C10401499ULL, 0x23973B0F7510C231ULL, 
            0xC4B64D017ADB895CULL, 0x0564B4B74EDDC621ULL, 0x2859F244CFB99F03ULL, 0x02758DB978560479ULL, 
            0x701294B8A57D6B26ULL, 0xBAA8BF980185D0FBULL, 0x692E89EC0DF783CBULL, 0xEB689CFD7EB2CFB5ULL, 
            0xD0A0AC09F47A3BA2ULL, 0x93BD07E1D45143A0ULL, 0xEBCBC4DE935EC9B9ULL, 0x3AD0E9EC1146E38FULL
        },
        {
            0x3A0C1BB2BB51798FULL, 0x738F73A42482433DULL, 0x21DF1002246BCB0FULL, 0x8D8F669421962F63ULL, 
            0x55F1B19C00A70050ULL, 0xFA7DB7AD15A179C9ULL, 0xC41C7901A3C75139ULL, 0x1F27D3724C52EDA0ULL, 
            0x34FE265398D7A43CULL, 0x829211C8CD65B206ULL, 0xBB99505D19EA01FDULL, 0xB20102B25A513A67ULL, 
            0x9EAB312BD5A437C4ULL, 0x4CD60193CB507A3AULL, 0x37FD2E98E0B156A2ULL, 0x3DAB67EF35B9DC85ULL, 
            0x24C74DC3969CD3D4ULL, 0x4F84C9D65AE139F2ULL, 0x3F6CEF9B4167D0FEULL, 0xF3AC382CD9C686BBULL, 
            0x04C34F043F8FA7F7ULL, 0x726F0F2C78D23C2FULL, 0x5F493BCCDF91DAD4ULL, 0xEEBC0DFCC923D3DDULL, 
            0xEBC4A6C1BBF7BA8BULL, 0x46100B67B8444199ULL, 0x8B0A81ECD9E6EF5CULL, 0x9A5C4EC1B89DFD48ULL, 
            0x11FE3DF42DA5DB52ULL, 0x93A40252234EDD27ULL, 0x79E4839D30A0B6DCULL, 0x1A9FB412729E217CULL
        },
        {
            0x00B3D5AB82B35E37ULL, 0xBCA79FFD814311AAULL, 0xD69DB8EFFCE36CD8ULL, 0xF648EDADA2AD2BCDULL, 
            0x56CCE0E97EED2F6CULL, 0x99457E786FACF6E2ULL, 0x335E8BFCB7DC5CF6ULL, 0x56E8381A5F2E87CBULL, 
            0x7695DADD22724653ULL, 0xA15B94ECD96758A8ULL, 0x10EC2F421ED56D7CULL, 0x368B975F9AF8B8BAULL, 
            0x2679FCED710CDF8CULL, 0xA192EB7B5002E427ULL, 0x0274D3576D664F20ULL, 0xF5D022E770A2EDDAULL, 
            0x374C60BC7D02E2CEULL, 0x0F23D16CBBE6E6ACULL, 0xEB87FE438B0DB84EULL, 0x1418D7A28B933DF9ULL, 
            0xCDE92652D3F2714BULL, 0x4E3A42C7ED080C9AULL, 0x0FE7C009D66AF351ULL, 0x4DA6DDD88C3A0F3BULL, 
            0xA944744FC21E8EAEULL, 0x6001CFB8F251C810ULL, 0xF3B62CA860C8AF2EULL, 0x3173CF7E7A7172FCULL, 
            0x0CD93D150D2E30AEULL, 0xF8724288E5E4FDE9ULL, 0x7EF0F6EE82A99404ULL, 0x262F8D65476B70F2ULL
        },
        {
            0x0094B4261F862AA5ULL, 0xA90ACF2140275ECEULL, 0xEB2C9DB6C7B5EDF6ULL, 0x787E2CEC7E1268A3ULL, 
            0x5D3723FD85D2FD3FULL, 0x4BF749916C3D425CULL, 0xD2EFC50CAE87C312ULL, 0xF9DEC85E993527B1ULL, 
            0xE814555A57CD6945ULL, 0x662A6A1CF24237FEULL, 0xC391CE6B3116330DULL, 0x71EB12F0AECD98A6ULL, 
            0x21A9FDAF1D7FA033ULL, 0x49FB6203C9F6AA3CULL, 0xA1B0A491287069F8ULL, 0x243C4D0B15CBDD1CULL, 
            0x00B38A586FEDD696ULL, 0xD3703C3CB1D7B595ULL, 0x64DCA2A444CD6005ULL, 0x660A204D8FBC2DF8ULL, 
            0x432A7BE838D5BCEBULL, 0xF7E9670D48141C0EULL, 0x26796FDCA37297DBULL, 0x0BB100C8DAE2C0B6ULL, 
            0xF2C993D9A2725805ULL, 0xF44BCDB4D8F688B4ULL, 0x93B1DA8AF58FEBE7ULL, 0xBD5ACC92452E61B8ULL, 
            0x0518EFA640D4D668ULL, 0xEFCBFCE53DB9FCA5ULL, 0xE3FB414E7AB58867ULL, 0x54DA18ADFEAEB34BULL
        },
        {
            0x658F3CAA3504DD49ULL, 0xB8195219F4C78716ULL, 0x91A2C35031868B73ULL, 0xE1753E666607CC22ULL, 
            0x8A8FA6B5B5B57E3EULL, 0x0E6D2268D1B2A2FBULL, 0x5DC3832F2EDDB418ULL, 0xEBFBC28B1EF87E6AULL, 
            0xCE0906039F29AEAAULL, 0x55157AAB15625F2EULL, 0xBFB4ABB5719A1202ULL, 0xCFFC8A9E59EE61D0ULL, 
            0x42C00119C5EB5126ULL, 0xDDF3D3A3E68AC5B3ULL, 0xE241AB74F12D94D0ULL, 0x79CBA2F607F02D3EULL, 
            0xB55D9FF3D3DD01C4ULL, 0x52BA0B9755DF2BA1ULL, 0xA7214E890C755C41ULL, 0x3E8FD06A71AB61B4ULL, 
            0x01F29D68D1BFA174ULL, 0xC624C9D61EBCA361ULL, 0xDEE3214AC4067A85ULL, 0x26F2CFAA49C3C5B1ULL, 
            0x09897961F39AAD24ULL, 0x19675B8A4C434395ULL, 0x6E2F42B2F54423CEULL, 0xD453CE8FE0F4821BULL, 
            0x79115899B34BB295ULL, 0xB3AB051F25366AF9ULL, 0xA51BC8B18A2775C6ULL, 0x2E1E86CF4C2E5E4BULL
        },
        {
            0x3523F568EA620ADBULL, 0x734E797632FA26DBULL, 0x90D7A27DD7D212CBULL, 0x21E2DE7634060C8DULL, 
            0x88FA05176259F11EULL, 0x15949E728D8CBCA6ULL, 0xC8DF761603543978ULL, 0xE1FECC046713539AULL, 
            0xB7E6CDB83C482963ULL, 0xEE2C23D99DAFDB1AULL, 0x3430C13FF5186398ULL, 0x0C35EBDD8B49683CULL, 
            0xA08F5A0D6B19C030ULL, 0x777AEEC5BF2406D3ULL, 0xCA4B2709838E4280ULL, 0x92D2D826B12FDD89ULL, 
            0x983B1DC45DC82F9EULL, 0xD6ED73C3C6F6BCB3ULL, 0x3230EDB443FCB9AFULL, 0x2A4E9B535FB8447DULL, 
            0x872A528540208AA5ULL, 0x17232B955F948FA4ULL, 0x1127B14C47F378E6ULL, 0x3E12AF1050538B1BULL, 
            0xB70DB93F2904D8B2ULL, 0x13FDFCA2BC107CBEULL, 0xBEEC0D2F44BFF6B1ULL, 0x974951B714A8FE0BULL, 
            0x17A161295BC88A8EULL, 0xE903C00DB304366BULL, 0x3186EEDE365BFB6DULL, 0x990B1F992B7C1594ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseGConstants = {
    0x4918987756A65CBEULL,
    0x3737A2FB4783A3BBULL,
    0x13781B78927DFD2BULL,
    0x4918987756A65CBEULL,
    0x3737A2FB4783A3BBULL,
    0x13781B78927DFD2BULL,
    0x1C91588532A89739ULL,
    0xBC017E4E78420787ULL,
    0xE1,
    0xDF,
    0x01,
    0x70,
    0x85,
    0x3B,
    0x7F,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseHSalts = {
    {
        {
            0xF59EED9920C452DFULL, 0xEA9BEB5F46BF62D0ULL, 0x7896BD88E2226BF4ULL, 0xC8F9032E7E8D90D8ULL, 
            0x9A76FBD18A56183DULL, 0x0C573F3FE2D4E072ULL, 0x55B8B3DD887BC8CFULL, 0xA0DE2B91CE73E400ULL, 
            0xD5C14CFB83EDA263ULL, 0xA754B9B4DEAF68C9ULL, 0x399CC74CCC6E5E4BULL, 0x910C5074A86C338DULL, 
            0xBF356901CAD4B443ULL, 0x36BEB29E6B7F2464ULL, 0xF3237534F11608E6ULL, 0x1AA88063BA80DC11ULL, 
            0x4069757C287ACF8EULL, 0xF3DEF6155E2CD466ULL, 0x6CE423DD2B6E7ABDULL, 0x47AF0EC2ED090455ULL, 
            0x84CDEE09B24A57EBULL, 0x43CBCFA147448BB4ULL, 0xFFF05BD7A5913594ULL, 0xC9C5B8400C2AC555ULL, 
            0x65C42ED1D5625AB1ULL, 0xD8F2E01A30A6D03BULL, 0x0A0E1418695E2817ULL, 0x3102404A8470588FULL, 
            0x54B410DF63BD7A3AULL, 0x0EF149E9B455670FULL, 0xB6E5CCD837120079ULL, 0x23DB02D1DA0F16AAULL
        },
        {
            0xDC48F883128761B7ULL, 0xB2C1B2AFB49EEE82ULL, 0x1027CB5B47F4BB1AULL, 0xE0A024FD39700974ULL, 
            0x0E56958A0CED8CE8ULL, 0x5645CBB34E871B1DULL, 0x9B63EC8018DC82EDULL, 0x8A34A94CD31CA40DULL, 
            0x11B9ED9B2C801C7DULL, 0x0DFFFC64262D594AULL, 0xD2B5324C5388A3B5ULL, 0x09E2C804AED39BFBULL, 
            0x075147A87286B402ULL, 0x4DE8182045FF64A1ULL, 0x7DE97646A38D04B2ULL, 0xAC93D057881DADC1ULL, 
            0xD58416DEA9DD6EF2ULL, 0x90F901249B5D4B17ULL, 0x51DBD15AC330058CULL, 0xC8FDEBA55DA2572DULL, 
            0xDE2C846A15652B83ULL, 0x76DC27C41C99DC6CULL, 0x64CE92A186377126ULL, 0x9D20B9EFBA24BA69ULL, 
            0x957079B915AB2D59ULL, 0xC29A62BF1C2CC182ULL, 0xD9219CD30A092AA5ULL, 0x749D191CC7FD4685ULL, 
            0xA289555CC99D21FFULL, 0xBC0716CFD056E035ULL, 0x3747E21AAC093CA0ULL, 0xF57ACDC39B2D1E32ULL
        },
        {
            0x3DF75D319B70A0B0ULL, 0xD9A4812894F6C030ULL, 0x741F129AAE3A460CULL, 0x960C67DBB7552F75ULL, 
            0x551B8D4560AE3380ULL, 0xD7CB23F561AAC265ULL, 0x0BC40661E9086BA3ULL, 0x0C4BAD3F36AE8070ULL, 
            0xB722AB527D8A7811ULL, 0x68C23D92B861A587ULL, 0xFE8B7C07870749F2ULL, 0x95C9870E0B23FB35ULL, 
            0x7D9F462647623E4DULL, 0x66AA25C1941FABEDULL, 0xC467A4673C878D9EULL, 0xB0D6ECA42B1477ECULL, 
            0x6ED4264BE8A722E9ULL, 0xC8F29F0F0A6DDAC9ULL, 0x6C08EC8425B63329ULL, 0xFDBC4E93188F18DEULL, 
            0x609F84D18867558AULL, 0x565C010FB83D0437ULL, 0xCE185541714EA936ULL, 0xB19C5F5C80A5B849ULL, 
            0x8C0893835784E13AULL, 0xEDC7E1D75FD3F5B1ULL, 0xFF42AE1C839FA4D8ULL, 0x4EC8BF258B9BB3C7ULL, 
            0x403412AB960F3490ULL, 0xC4D2D4AE96A287C7ULL, 0xA211790088A36A2DULL, 0x903228D645B29769ULL
        },
        {
            0xC5535265E5BF7FC6ULL, 0x5B0B26439CA937F2ULL, 0x2249EFB18CFDB87CULL, 0xD1894A47CDDBBC56ULL, 
            0x4EF4A2242CE78C1DULL, 0x5FD0FD1FAAF1D446ULL, 0xE225B9FD26962877ULL, 0x5C7A6C670E4DD57CULL, 
            0x04A37CB8EC83FF7DULL, 0x5F5AB729CA65B3C8ULL, 0xD35DF469967CC204ULL, 0x98CEFF66211B14FBULL, 
            0x04FCD6947E82C307ULL, 0x9652D2444B9106D6ULL, 0xB8840BB52C61563BULL, 0x916240D7BF720173ULL, 
            0x72112F19F110828BULL, 0x2BDE6A265F7E9C15ULL, 0xA1210447845D4784ULL, 0x01F4CD724276FDCCULL, 
            0x295CA589157E4C10ULL, 0x838C8BB6CD159FFFULL, 0xB5BD1ADCC97EBF0AULL, 0xBBFB48C4A5059D3BULL, 
            0x39A5342AF9E723D9ULL, 0x05237F0309117626ULL, 0x6166FED2BCEBA19CULL, 0xCEC7EACBBB4196FEULL, 
            0x8BC0F9A98C8AF874ULL, 0xA62B22E1C2826204ULL, 0x6F4BB257E0D37AE3ULL, 0x24FFADD440CB5D7EULL
        },
        {
            0x2CCA907DCF744E25ULL, 0x2A6B7AC147BE5F49ULL, 0x304B8A10C45A5572ULL, 0x14BCAF62F5582B75ULL, 
            0x85D3130053075007ULL, 0x6CBA72C78F9DF0CBULL, 0xCC9987F9B2CF34CDULL, 0xF39FEFA147F4FB89ULL, 
            0xBAF4DE238CCFE843ULL, 0x18251513A04663B0ULL, 0x86D312163CCA4A06ULL, 0x95D2877106BA0034ULL, 
            0xDDC722868A4375CFULL, 0x4953B7AC398C402CULL, 0x081E8CCFFDC5A247ULL, 0x28F4C091C7343C8EULL, 
            0x84F02754D6279299ULL, 0x646F819D322A51D3ULL, 0x8BBDF42A25C95FDEULL, 0x77177BFCD471FE1CULL, 
            0xC3B72E926913EC27ULL, 0xCBE958F89DB43F7EULL, 0xEC54022643A8E1F5ULL, 0xA0C9E9090CB8F1D8ULL, 
            0x9EED1EBCC1FF967DULL, 0xCE213C2CB299557EULL, 0x81AE31292DD4D8A5ULL, 0x95CB76DD19F3E62AULL, 
            0x8779FFCD718CC04EULL, 0xB9E395640915C6EAULL, 0x5E9CC75FBE364AB3ULL, 0x29F7827210AE15AFULL
        },
        {
            0xC6270D7E6993F022ULL, 0xE8BBE388605B26B6ULL, 0x969AAEEB0B259346ULL, 0x2BC1BDDD6F1DEC9FULL, 
            0x5231DC3AA388AF00ULL, 0x84587F1A8FD482A0ULL, 0x28D00A736A4FEB64ULL, 0xAD1FA9C4162C4D40ULL, 
            0xFB274A8592C6F19AULL, 0xB0B2E61BC9060AB4ULL, 0x82582751779A3048ULL, 0x180CAB793779088AULL, 
            0x0220E53E515C1E8BULL, 0xFD764CE24833D78CULL, 0x48BDD7AABB26DE98ULL, 0xCA898069823B4AE8ULL, 
            0x696195FDC9293626ULL, 0x694E9D85556CEA93ULL, 0xDAF14551C9F20DFEULL, 0x0FD7F493E581D4F5ULL, 
            0x785DB4116F4A2F2BULL, 0x0E2BCAE5682A6E47ULL, 0xFF367B40433230A6ULL, 0x4522326FC33F33BAULL, 
            0xCCD50A99046E16C7ULL, 0xD27AF39CAAFE5F6BULL, 0x1CA12E6C9D495989ULL, 0xD1612EA5862F0098ULL, 
            0x15D9A15EA3CEBD35ULL, 0x6B2798609392A8AFULL, 0x76212C2CE1A46857ULL, 0xA943411168D948E9ULL
        }
    },
    {
        {
            0x7F0CD2D083C3717FULL, 0x0F734D3938BCCCE0ULL, 0x30A8B3E17EAB7CEFULL, 0x0D6E9A88C1963FE3ULL, 
            0x30520F7B53311605ULL, 0xD73F5FD20737A160ULL, 0xFE49B48CE0ABA353ULL, 0x7E16F574F248BB16ULL, 
            0xF2F6B4C976A5208FULL, 0xA148F0B635D9D905ULL, 0xB5E1E5E5A9FD3340ULL, 0x5BDEB230F7C80008ULL, 
            0x36E4F29BDA03C66DULL, 0x83BF7D8A01F17AF0ULL, 0x786A32849266919CULL, 0xCB418E09F1A78A2AULL, 
            0x871EEC3BC5AAEFDCULL, 0x92741E00F762AB0CULL, 0xF2C7C7681D45395BULL, 0x6B8C09ED37562695ULL, 
            0xC3A762E4544707A1ULL, 0xBCA0A05D1FFA9C22ULL, 0x59873E89577925EFULL, 0xBA75758818134591ULL, 
            0x5B76E15A732D79E3ULL, 0xDD082C0C3909A5C1ULL, 0xB28712DB5104A1ECULL, 0x8A730043BA58C761ULL, 
            0x3A8F2A4E84EE66E6ULL, 0x7A29043AE7D2C74FULL, 0xE843A3097E6DB688ULL, 0xE65996D7EA892001ULL
        },
        {
            0x4E2D795C7921BC84ULL, 0xE18510D1742CC40FULL, 0x0DE01754822C8FC7ULL, 0xE139CF6B69B81852ULL, 
            0x74644AD0CA3D5E57ULL, 0x8EC7BEC4C92B35E3ULL, 0xFD60D683CD05BFF1ULL, 0xB11638D0A49B9271ULL, 
            0x1968F0E131CE6EACULL, 0x7F902DA44E74CFA7ULL, 0xF3CB09A5472F891CULL, 0x3B76688DE44E155FULL, 
            0xE62CBEE5469F28D3ULL, 0x3F5E2CA0B59522C1ULL, 0x0A0D074223515B86ULL, 0x80ACC91DDBDDDB34ULL, 
            0x55DAD6A71B913DD4ULL, 0xCC21EFA2EACAAB10ULL, 0xD6BD1EB12F11750AULL, 0xAC419D3DDD395FCBULL, 
            0x5D992BE380DDD69FULL, 0xBAB0FB3D58C160EAULL, 0x01C0B6F5C55C8664ULL, 0x4244974DA335B5C9ULL, 
            0x6F3D2DBC3EB7F215ULL, 0x39B4256A419BF89BULL, 0x03C4BDB089EEFC16ULL, 0x3AE026CCB7D0B649ULL, 
            0x7D6F09BD98EB24A3ULL, 0x4AEC958AB96130E5ULL, 0xD1C7BB445FEE548CULL, 0x6A9760FA535EB0B3ULL
        },
        {
            0xC1A064E91E1EBF2FULL, 0xEF84807FAC62408BULL, 0x9DF2013583027D3DULL, 0x58DED6DA6D41BE6EULL, 
            0xB43ACA1DE077E805ULL, 0xCA0B72651E6D40B8ULL, 0x877F706E369E27BCULL, 0xBC84BD0BF186C8CBULL, 
            0x860DF003AD6BF7F7ULL, 0xE28B19E39108412DULL, 0x470E314D09D2D2B4ULL, 0x3006AFDF54529A8EULL, 
            0xEA81AB6020E14705ULL, 0xF68AC94B326A298BULL, 0xE4E209AE70E28DCDULL, 0x7C605C2490BBF4DEULL, 
            0x6EC3AC69C48EA488ULL, 0x044C00599848F84EULL, 0x2689437391B8F1E3ULL, 0x447A53C00AE60262ULL, 
            0xC81DB3D58CF568DFULL, 0x89BB578AAEC42EC0ULL, 0xDE1BAFBCED116E82ULL, 0xBD08A8217644240DULL, 
            0x3CD31766DB28349DULL, 0xF0CA595FA8B210B6ULL, 0xA6480C0AF4560502ULL, 0x4467A38D9475CB3DULL, 
            0x7CAEE186581698ECULL, 0xC629179DAA1CF1CBULL, 0x72A0D9FFE365D8F1ULL, 0xA369A174F6799B6FULL
        },
        {
            0x92F924518812A67FULL, 0x2831F489DDB31243ULL, 0x51F7070A5AD15190ULL, 0x6B922E1C4F5C9BDAULL, 
            0x4F7D796251A90E07ULL, 0x1D5ABD849CB98675ULL, 0xCA5C3B31BC8B8184ULL, 0x286E57EB47FECDC4ULL, 
            0x704154E6EF35F17FULL, 0x861A9DDDC78099FAULL, 0x903BC7A48417270EULL, 0x012ED5CE9487B54AULL, 
            0x944226643AEADD54ULL, 0xBE2600564D93D586ULL, 0x522A7B0CAB81B478ULL, 0x1ADB68B94B314D98ULL, 
            0xFFB8F1A9E1749E6FULL, 0x6163B22E68E3B891ULL, 0x5BFCA0D7BFA94043ULL, 0xD57626BEC4756532ULL, 
            0xEC9D65EE9640614AULL, 0xE64DF056392DC221ULL, 0xDB0DCD25D01452BDULL, 0x1656BE2B26B7BF8AULL, 
            0x77F15007C89971ABULL, 0x9081D84D8C885103ULL, 0x44C1F3241F5F66D7ULL, 0x4E6464CD1CC88F3BULL, 
            0x98040C0283A8FEF5ULL, 0xAF9510FDD35CCF04ULL, 0x107C14B66A785B5EULL, 0x3A1514F761DDE86AULL
        },
        {
            0x4D178C20874B9A90ULL, 0x7E1BE1F9F530C926ULL, 0x5F1398F5EBDE4682ULL, 0xCFE492F98E0964B6ULL, 
            0x3C987310108F4F6CULL, 0xCF7EC8339C10258BULL, 0x8318F57B768D3DEAULL, 0x3C1E73707DB12FD8ULL, 
            0x4E00FFB381C6395AULL, 0x4A6395B5AAD1CE5EULL, 0xE594B98ACF1887B0ULL, 0xCF22F4316F7099FBULL, 
            0xCDD0990AE65F87BAULL, 0x9101B09F2BF385A7ULL, 0xB129C37C6D955949ULL, 0x3A34795D664C7E97ULL, 
            0x2FEF318AFAAFF301ULL, 0xFBB984A6954DFA0CULL, 0x9D0F68E48C240AF3ULL, 0x6C6F50C9FDE9C547ULL, 
            0x30DD1C4391615A58ULL, 0x60049BBA59830F13ULL, 0xCC01BB69F09B1A0FULL, 0x538F52E57EDE98CEULL, 
            0xF61C546CA825D67EULL, 0x9F9379011DE20351ULL, 0x88C02F72E33AA4E6ULL, 0x793EE2F044CAEA37ULL, 
            0xA0AB4D7D71DA9F92ULL, 0xA5428C82ABD3DC2CULL, 0xD042BEB01112495FULL, 0xDBD9556820960BFAULL
        },
        {
            0x4AD7188273A9F292ULL, 0x1934EDE3F08B8FD3ULL, 0x404EA82A11690760ULL, 0x428A681AD8C4F09BULL, 
            0x698C05931F3970A3ULL, 0x239A67CDBCAB9890ULL, 0x16C51E1EF85658F7ULL, 0xBE6522E9A05D3B82ULL, 
            0xA6AB5BB24CDD3B1CULL, 0xB3BADA08831E9376ULL, 0x703C247DAD4DD1A3ULL, 0xD700B2D350540B5DULL, 
            0x3AC7CAA32B086E4EULL, 0xD52D1CFF890B2B78ULL, 0x3249733D97AFB1B9ULL, 0xACAF16B1C2582409ULL, 
            0x514A648613AEDA9AULL, 0x38E24F7C153F4AEFULL, 0xD64180C7F8FA338CULL, 0x5D619641C55AF96EULL, 
            0x188CAD42B8503CDCULL, 0xE001F3B70B797DA9ULL, 0x2F320E04A67ADD73ULL, 0x95CD89EECE0016DCULL, 
            0x5030F546DFD517A4ULL, 0xDAAB65AECADBEFB8ULL, 0x58579B0A14AD6EB2ULL, 0x1FA5820085259C08ULL, 
            0x6DA4D83E0C7B85A8ULL, 0x6DB83D2CD9699462ULL, 0xF04D462CDE9EBE6CULL, 0x40FEFBDA9DE43608ULL
        }
    },
    {
        {
            0x445A598C5102ACB8ULL, 0xD9E3A4A24D52DE1BULL, 0xA4861C584BAF8B89ULL, 0xDE72ECB64191BF49ULL, 
            0x8DB0FB9EB1FA3CA1ULL, 0x251972E320953548ULL, 0x28AD170ED7C16F38ULL, 0x87A1B48035FB8B6EULL, 
            0x9AF34B83E5A8BD6DULL, 0x3FA5035754C79C8DULL, 0xAC75A8B09966B572ULL, 0x1CA9DC96D1F0C8EEULL, 
            0x7FE18409C7C21E07ULL, 0xE5CA09591607F948ULL, 0x08238266A3D4104BULL, 0x9E8B939B473049E8ULL, 
            0x3946E2F7317292D4ULL, 0x09227656DA734D89ULL, 0xFCB5713D5311E813ULL, 0x8135756DEA5C75AEULL, 
            0x74EDD43E0CBF210BULL, 0xC041B1A8C045598EULL, 0x81973CD4EE8B72D2ULL, 0x3C072C77B01783FEULL, 
            0xAC76385EC5E5810BULL, 0x9E23977F9A383B87ULL, 0x09B91DEAA0A7BA13ULL, 0xC7DD1ABCD9BA5924ULL, 
            0xD18785B1EBC12C3EULL, 0xB9365054C05C934FULL, 0xD7B8130852FC406AULL, 0x98B81FE559A7F5C2ULL
        },
        {
            0x669293BFE82D68C2ULL, 0x5FBB7886195CA6D6ULL, 0xFA72D1BFE923F0CCULL, 0x0671F2D1248178C0ULL, 
            0xE412EA5D4772FB66ULL, 0x2AFBFC4A99523C7CULL, 0x04DE3CE8ABDFFD1FULL, 0x865CF4067DFAD32EULL, 
            0x8BA06241062DC9C1ULL, 0xC07C237A0D4E9A5FULL, 0x082ADECEED174870ULL, 0xD0AAA3CA629B7F2EULL, 
            0xA5D8AF6C122E5E8BULL, 0x057A53709941E820ULL, 0xB543778894BE2599ULL, 0x78B5C7689383B990ULL, 
            0x0222799D12F79178ULL, 0xD224CE94EBB5165AULL, 0xD7A8054DB3F9748CULL, 0x7996ADF25D932E81ULL, 
            0x1ADCE7CF1D291E36ULL, 0x8AD1EFB6D6EF01A7ULL, 0x263F27346886AD3BULL, 0xEAF306F79C828033ULL, 
            0x05C8413C143A59DDULL, 0x0D92A3A73DBF8D91ULL, 0xE20E1A977E6780C1ULL, 0x29E5E69D243D5A8BULL, 
            0x386B32DF9F36B69CULL, 0x8B79836BF216D7BBULL, 0x8B5DA853B1D15732ULL, 0x937A9080B6FEEC72ULL
        },
        {
            0x95378744E60E40ECULL, 0x02FF05283784C18EULL, 0xE4B673239C26E73DULL, 0x52A687E3BF4CE2DBULL, 
            0x48AA213D40B2584BULL, 0x053D6843833A4832ULL, 0x39434EF1FF7455CDULL, 0x457109DD74EE3815ULL, 
            0x0BA0749BAF160D0AULL, 0x94D16A85323E3B95ULL, 0x644B7F78357A7FCAULL, 0x5DB109F2ECEE4433ULL, 
            0x1048EA73F5DF5D9AULL, 0x048B058C47624C81ULL, 0x919667AF41798229ULL, 0x4370DC02CEBA0E72ULL, 
            0x10AF052F145D328FULL, 0xC9F2A5850B608B87ULL, 0x8A37CC488AF95C7FULL, 0x597EF589CE750432ULL, 
            0x9938ECCF778FF634ULL, 0x41D2026CA8EEF370ULL, 0xAB27D39DE77323F5ULL, 0x4FA1B4786D510950ULL, 
            0xFD04028F6CA7069BULL, 0x694F1385583D7844ULL, 0xDFED6854B4B51EFBULL, 0xB227D87FD7D0F0CAULL, 
            0x056EBAA6CF14C693ULL, 0x25C4D0B328F23390ULL, 0x51471A7468C80C38ULL, 0x28835E81C9CC6A2CULL
        },
        {
            0x18275EF429B1682FULL, 0xC128971745576BA8ULL, 0x9E6028DD54AC13D5ULL, 0x3D04F3A00BA43690ULL, 
            0x5DF0AC9DD6D758FAULL, 0x55D130A37167972BULL, 0x4C88EF111C83C9AAULL, 0x6B59291C45CA6813ULL, 
            0x3649C4A24DA5237BULL, 0x60E210FFF31DB09CULL, 0x12AECF4162862C3DULL, 0x782FE5C0B0ACA120ULL, 
            0xF8BA4808C7EF5A94ULL, 0xD6762DD35BFBC731ULL, 0xB9E5CFAB5BF1A92BULL, 0xA499DB64805DBF11ULL, 
            0xBE8D92EDB8EE751FULL, 0x33C150880756470BULL, 0xB088E1831C3935B2ULL, 0x080A559FCD00710CULL, 
            0x8FDA39CBA5163C3FULL, 0xCC788924267D1029ULL, 0xAC82D767FAFA039BULL, 0xD915F9F11BF3291AULL, 
            0xA70BE36133111C16ULL, 0xB59C1A6CE64C61E5ULL, 0x110D042001F68B2DULL, 0x469F73D73BE499ADULL, 
            0xDB5BEBA1CDA21E73ULL, 0xFE2BEF1BBDBF1BF5ULL, 0x884DB95C2174E814ULL, 0xFBC6B79F397BC9A2ULL
        },
        {
            0x1C90136BA66E3170ULL, 0x7E4BCDB7D698F138ULL, 0xA4CAF2A995621A62ULL, 0xC5F4E3A433751947ULL, 
            0xB48370814CCE8FA5ULL, 0x1987E3BA02ED77D8ULL, 0xB383F7C73095EDECULL, 0xFADFBF87005C8FF6ULL, 
            0xCD8D80DDD3E1C492ULL, 0xCC71E84EE2EC00D0ULL, 0xB4AC81214583A0DCULL, 0x4C2F4558D7AAC40BULL, 
            0x4F03D33AB1E00070ULL, 0xDE8F4BC499719399ULL, 0x2EE660EAB3958B6FULL, 0xCC852C97225F376FULL, 
            0xC027291E8B91FFBEULL, 0x5B0D9D8777736B83ULL, 0xB8B8C839D238B21AULL, 0xF848A6EE9BE8C32AULL, 
            0xB93D9F537D5DE2C6ULL, 0x9F0E015C9C499879ULL, 0x4E49B6F39820C11EULL, 0xD9935389A60A2D0FULL, 
            0x98368FB2A4B793ACULL, 0xCA3E2C6EDC95B651ULL, 0xBA2E19861BFCC463ULL, 0x98D6B8378B4E1381ULL, 
            0x7F6C517CB9025252ULL, 0xE98CB6DDD8862ABCULL, 0x9AE281A096AD9CCFULL, 0x5ECC63A9AADC248BULL
        },
        {
            0x98F5936D987628A6ULL, 0xCC80711D4D9C53E7ULL, 0x6EB79E9D560D8802ULL, 0x619D0518FCAE2210ULL, 
            0x59927E42D0693277ULL, 0xB6262AF53D976A30ULL, 0xD08C4051FC45E65EULL, 0xD93DBA3AE5B2802DULL, 
            0xC3B4887163813AB5ULL, 0x17DF44657F1E43B1ULL, 0xF1B2EE096E7FCB30ULL, 0xDEB8FEF544BCE290ULL, 
            0x583F57CC5C6047A3ULL, 0x77DAF4670E2D00B3ULL, 0xA40569B2331A0EF9ULL, 0x6433F4C516B8333BULL, 
            0xB37C3A88DA92E5F8ULL, 0x3BE004055DD9DC90ULL, 0x34348A91011CF1B5ULL, 0x367D2485D4D84CBBULL, 
            0xE986BA48D176C709ULL, 0x15F640761161A21AULL, 0xD4137B00B3C07BF7ULL, 0xBDBEECD3EA19A44AULL, 
            0x70462882FB6362BEULL, 0x44D616EE3318EAEEULL, 0x64ADC15A4340E44AULL, 0x8CEB03DBF4E16AB7ULL, 
            0x6C9CF7197AD585C8ULL, 0x680CC52874038F6BULL, 0xAB33C8050E838043ULL, 0xE7389EF6572D6CA1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseHConstants = {
    0x34A5E2C6F7EDC255ULL,
    0x7A8F1D791759EBD9ULL,
    0x6AA6A6D16C6B04B6ULL,
    0x34A5E2C6F7EDC255ULL,
    0x7A8F1D791759EBD9ULL,
    0x6AA6A6D16C6B04B6ULL,
    0x0CE21FD7D61E848CULL,
    0xBA45E543A7C1BD46ULL,
    0x18,
    0x83,
    0xA3,
    0xDD,
    0x42,
    0x7C,
    0x92,
    0xA1
};

