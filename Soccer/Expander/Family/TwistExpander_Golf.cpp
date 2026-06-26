#include "TwistExpander_Golf.hpp"
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

TwistExpander_Golf::TwistExpander_Golf()
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

void TwistExpander_Golf::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 12660189467019991304U;
        aCarry = 13491013792786102401U;
        aWandererA = 15156489638182907362U;
        aWandererB = 17301150887654757501U;
        aWandererC = 11248736363476521821U;
        aWandererD = 11471777277032901320U;
        aWandererE = 14470114908061453341U;
        aWandererF = 17977796295480901917U;
        aWandererG = 17433460408670294164U;
        aWandererH = 16869596228965614563U;
        aWandererI = 9873845929216290265U;
        aWandererJ = 13362292220104316909U;
        aWandererK = 12537185431024396430U;
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
    TwistExpander_Golf_Arx aArx;
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
    TwistExpander_Golf_Arx aKDF_A_BArx;
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
    TwistExpander_Golf_Arx aKDF_A_CArx;
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
    TwistExpander_Golf_Arx aKDF_A_DArx;
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

void TwistExpander_Golf::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 9633922397176988804U;
        aCarry = 18384434391923160354U;
        aWandererA = 16320054665587785953U;
        aWandererB = 9390611869481878491U;
        aWandererC = 15360538861793640654U;
        aWandererD = 11522469165516792669U;
        aWandererE = 13088396496630875379U;
        aWandererF = 17567199116444582857U;
        aWandererG = 15341671889526151723U;
        aWandererH = 11469944625119666069U;
        aWandererI = 14505721981216593275U;
        aWandererJ = 16033772441999912428U;
        aWandererK = 9781309869690595960U;
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
    TwistExpander_Golf_Arx aKDF_B_AArx;
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
    TwistExpander_Golf_Arx aKDF_B_BArx;
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
    TwistExpander_Golf_Arx aKDF_B_CArx;
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

void TwistExpander_Golf::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD01B7FE9DD33D647ULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xF0D68911D3C91813ULL;

    std::uint64_t aWandererA = 0x92DB3F27C072E9BFULL;
    std::uint64_t aWandererB = 0xE2924FE70DB2C5D1ULL;
    std::uint64_t aWandererC = 0xE17E4ED67C35CD86ULL;
    std::uint64_t aWandererD = 0xEAFA2024F8F739D2ULL;
    std::uint64_t aWandererE = 0xC5FEAD5B927055F7ULL;
    std::uint64_t aWandererF = 0x9DD9DFDD2C4BA2B8ULL;
    std::uint64_t aWandererG = 0x8B60504AF7C45C57ULL;
    std::uint64_t aWandererH = 0xA198DD705C7E26B7ULL;
    std::uint64_t aWandererI = 0x898D75A4DB90166DULL;
    std::uint64_t aWandererJ = 0x84921352B5F0664DULL;
    std::uint64_t aWandererK = 0xA02317554CB35106ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Golf_Arx aSeed_AArx;
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
    TwistExpander_Golf_Arx aSeed_BArx;
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
    TwistExpander_Golf_Arx aSeed_CArx;
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
    TwistExpander_Golf_Arx aSeed_DArx;
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
    TwistExpander_Golf_Arx aSeed_EArx;
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
    TwistExpander_Golf_Arx aSeed_FArx;
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
    TwistExpander_Golf_Arx aSeed_GArx;
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
    TwistExpander_Golf_Arx aGrow_AArx;
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
    TwistExpander_Golf_Arx aGrow_BArx;
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

void TwistExpander_Golf::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Golf::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 12735481125155564080U;
        aCarry = 9404984599325640397U;
        aWandererA = 15860773535485760258U;
        aWandererB = 9766503821839218884U;
        aWandererC = 18006098606765483005U;
        aWandererD = 16022762220350711746U;
        aWandererE = 13742575018433578522U;
        aWandererF = 13280704858855948290U;
        aWandererG = 17097861933203148266U;
        aWandererH = 17853159736138344536U;
        aWandererI = 15648576110082626879U;
        aWandererJ = 13826419757743509532U;
        aWandererK = 14784006883501619323U;
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
    TwistExpander_Golf_Arx aTwist_AArx;
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
    TwistExpander_Golf_Arx aTwist_BArx;
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
    TwistExpander_Golf_Arx aTwist_CArx;
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
    TwistExpander_Golf_Arx aTwist_DArx;
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
        TwistExpander_Golf_Arx aGrow_AArx;
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
        TwistExpander_Golf_Arx aGrow_BArx;
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

void TwistExpander_Golf::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 3 with offsets 2708U, 2845U, 1526U, 2374U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2708U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2845U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1526U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2374U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 3, 0 with offsets 7231U, 3574U, 7979U, 370U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7231U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3574U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7979U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 370U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 1 with offsets 7320U, 5792U, 3645U, 6211U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7320U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5792U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3645U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6211U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 1, 2 with offsets 2115U, 3050U, 367U, 7214U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2115U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3050U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 367U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7214U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 with offsets 1277U, 856U, 1271U, 706U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1277U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 856U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1271U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 706U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 1, 2 with offsets 1523U, 1687U, 1992U, 672U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1523U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1687U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1992U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 672U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 502U, 1222U, 1643U, 602U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 502U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1222U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1643U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 602U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 1, 2 with offsets 14U, 1994U, 1238U, 1808U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 14U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1238U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1808U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 901U, 128U, 1506U, 99U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 901U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 128U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1506U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 99U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Golf::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 1 with offsets 21U, 3370U, 4155U, 5513U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 21U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3370U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4155U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5513U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 0 with offsets 6830U, 5594U, 5383U, 7143U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6830U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5594U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5383U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7143U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 3 with offsets 6828U, 264U, 2014U, 481U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6828U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 264U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2014U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 481U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 2 with offsets 5257U, 1449U, 4044U, 4275U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5257U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1449U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4044U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4275U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1846U, 3566U, 1359U, 4429U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1846U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3566U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1359U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4429U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 978U, 1627U, 632U, 648U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 978U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1627U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 632U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 648U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1194U, 487U, 1637U, 221U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1194U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 487U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1637U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 221U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 591U, 1222U, 1845U, 1014U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 591U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1222U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1845U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1014U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 896U, 1262U, 1180U, 473U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 896U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1262U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1180U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 473U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 0, 3, 2 [0..<W_KEY]
        // offsets: 1344U, 1764U, 52U, 117U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1344U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1764U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 52U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 117U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Golf::kPhaseASalts = {
    {
        {
            0xD760FCD84A292B63ULL, 0xFA8C65B2DEC87317ULL, 0xAFD145BD94C5675EULL, 0x98E0D34148623EA5ULL, 
            0x12042058188774EEULL, 0x1377E1566F18FD4EULL, 0x01D70AD6BB81D91AULL, 0x06DC8B8D8452C9C4ULL, 
            0xCD04E80CFEDD7BD1ULL, 0x7DD812A9F17A2AF8ULL, 0x75E9549B012A549BULL, 0x8130E17BCFD8DD47ULL, 
            0x9229FA50EA616E19ULL, 0x2992FA2AC388F766ULL, 0x8A06110A12A9E795ULL, 0x62BB56208495927AULL, 
            0x583EA81503DE29DEULL, 0x4AAADAB19B081774ULL, 0x3638AC143E582FA4ULL, 0xC5C608A0EE8A085EULL, 
            0x2EE42970574EB2BCULL, 0xB31FA0ABC9E82077ULL, 0x44D8C094108A18AEULL, 0x34882C4BF82CB134ULL, 
            0xECAA4246C55542D0ULL, 0xEED42FF156137EA6ULL, 0x72103D21F25259D0ULL, 0xC3032FD0B55A19BFULL, 
            0x468702A6F8A3A5F7ULL, 0x0495B848B415C163ULL, 0x8086872181721FCFULL, 0xB8BE8CD7914A1EA1ULL
        },
        {
            0xA92EE56F9C9A62B8ULL, 0xD8071E9AEC2B0FD5ULL, 0xC162EF1C7696B92CULL, 0x34302B1111DFC03CULL, 
            0x7EEE3E15F7123EEBULL, 0xF5999D299E865AEDULL, 0x0BB8186AA6105BDFULL, 0xD3B575154B952F46ULL, 
            0x00A419B737670586ULL, 0x29BD3BAA48E5F4ECULL, 0x3EE39606560FAC21ULL, 0xB68C63157A03E739ULL, 
            0xF3EB32A3AC98B773ULL, 0x42A9366380BA0858ULL, 0xB0064C4AFC848DE9ULL, 0xF35EAE5B0DB6750AULL, 
            0xCC39AD9FEC2AA651ULL, 0x8396526CC80507E0ULL, 0x6F683E3293231658ULL, 0xE464E1ECA48CAF86ULL, 
            0xEBA346EE8A686E99ULL, 0x5BD438F287278C74ULL, 0xB64AF908777B9721ULL, 0x7F2404722736FEB7ULL, 
            0x8175A9B13768855FULL, 0xB505B7777030A051ULL, 0x28532FEF9C066E69ULL, 0xF9BB6A2BD302314DULL, 
            0x3A283ABC4AE0DCFBULL, 0x67AB458D4D63E2EDULL, 0x31023A2C228C20FFULL, 0x3F714C4A10D18BC8ULL
        },
        {
            0xE91732B3FD0540C0ULL, 0x77CD3BCA0D4D6988ULL, 0x2099C8813EA49761ULL, 0x4EF3CD059701296FULL, 
            0xD234FE0CCC9902AFULL, 0x09290BC6240B1F25ULL, 0x5DDBA1D8380DB2EEULL, 0xD95DF2F5E7190EB1ULL, 
            0x3851CBF0E599CBC2ULL, 0xCC1B6E82FC585613ULL, 0xEBFAB3FC95295509ULL, 0xF62F0511DCC3FE0AULL, 
            0x58D44BC4E5EB05D7ULL, 0x0307EC0D924EFD05ULL, 0xB25EA3AD0428798EULL, 0x78245C15492D9203ULL, 
            0xBFEEBF6E237F1FA4ULL, 0xD76BC5D292043CBAULL, 0xEFEE90BF0EB5447BULL, 0xDF05D4C36A6DFC49ULL, 
            0x4E154E61833E1F79ULL, 0x64AEBBD2F9CF52F3ULL, 0x8D94F335EA0FA7C5ULL, 0x364E0A4C883C030DULL, 
            0x38C7D3546233A34BULL, 0xD5FAE5898627A110ULL, 0x23FF5CD8E66BBE11ULL, 0x858BAE8E6CF5C8A4ULL, 
            0x785D23883A13E76DULL, 0xFB71A9E875AF8CE4ULL, 0x019FCFAA7CFCBC94ULL, 0xD2CB81DF80485A60ULL
        },
        {
            0x8A411C4A6CBAF400ULL, 0x9BDB9ACB8A483954ULL, 0xB344B39D791C96EBULL, 0x8B0A266529119356ULL, 
            0x6A9FA230E674DCB9ULL, 0x1AD5D7EA83A32340ULL, 0xA55F779C4DA47F0AULL, 0xD2CE37E4A19A6253ULL, 
            0xD8A6966215E111B6ULL, 0xD8AB68BFE3476A17ULL, 0x61F24B8DFCE03E89ULL, 0xA62A744D17E7B87CULL, 
            0x9CEF19A1C6C51FBEULL, 0x9BA3052047E38D0AULL, 0xE54D21FC6C909EDEULL, 0xD6540B70AB635C9BULL, 
            0xCF266F05A9314AEAULL, 0x2C2BC0EE93F4C28AULL, 0x06EED61B4BA7E933ULL, 0x2DFDA13840CD4B64ULL, 
            0x33310758E090397EULL, 0x695EB82778B5591AULL, 0x88BEBF4CED633D24ULL, 0x37B27546722E1D31ULL, 
            0xB84BCFC929D6226AULL, 0xBB2202319DAF02FBULL, 0x21705589B028364DULL, 0x3C734A9E0809EE4CULL, 
            0x43EBA5A81EBA6C75ULL, 0x144D1BF8731E6F9CULL, 0x664280BE69BBE9A7ULL, 0x2E410E9726F35BA4ULL
        },
        {
            0x9A71E2C4982DC2D9ULL, 0x3FBAB857E8CEC101ULL, 0xFA30DF616488194FULL, 0x8E664C08A019014FULL, 
            0xB74D38C1C44FD5E4ULL, 0x0EF7CBC85F6031F0ULL, 0xEB2501159C6B09DDULL, 0x9E6CE17D1A0E268FULL, 
            0xF9E04D42DD60D785ULL, 0xB1AE5C798E340975ULL, 0xBD30B5FB08C5A627ULL, 0x9BAEB34D2BB9E073ULL, 
            0x4E26786277D8FD4FULL, 0x8045B2F4D45E6325ULL, 0xF2F236BC47CCDC85ULL, 0xBE9BB7E9AFB3E94DULL, 
            0x38C6DE229F88A8F9ULL, 0x9DE0E738B525E0C0ULL, 0x608AE867DC511F01ULL, 0x432AE1E4677E0183ULL, 
            0xDBB90678EC3643B4ULL, 0x7552D47466B3D893ULL, 0x3082284653AD20B5ULL, 0x3368405A17A8B634ULL, 
            0xA944DC842FF91558ULL, 0x4966522C26F980C1ULL, 0xB1377C31ECED3582ULL, 0x1CF3522954ABD9A2ULL, 
            0x653A33A4D4F54280ULL, 0x0EE7E9CFDD226D14ULL, 0x4A4D37A4A9C86D73ULL, 0x80F57A3B4E4E75ABULL
        },
        {
            0x74F11470CAF62940ULL, 0x1A6DD4723023686EULL, 0xFAE0B92ACC6728FDULL, 0xA6ABA341BDC0F332ULL, 
            0x0A6A4921D54A389CULL, 0x9A734A9A63719B5AULL, 0xEF8BCA1318CC3607ULL, 0xC7D4252441F5DDAEULL, 
            0x49E3E5067240F447ULL, 0x41F9E9B8C747625FULL, 0x19506D17C2E91246ULL, 0x7B2E559701131E30ULL, 
            0x19552F89C15CAF84ULL, 0x36E17127F9E7E9B5ULL, 0xFC2BA881AEAB503DULL, 0xF29FF83492351A59ULL, 
            0x2FC6813338D30A03ULL, 0x2226C52629FE83B1ULL, 0xF49B2F4E0B15A792ULL, 0xED7613BF655772A0ULL, 
            0xAB71E1FCF7F5095FULL, 0x769320BE6EEF6394ULL, 0x7DF1A594D31337D6ULL, 0xF1D443F7BADBC6F9ULL, 
            0xE8E48377BB59CB1CULL, 0x28388B45E51C7ABBULL, 0x559E75A347C1DDEDULL, 0x2767A9022CD122FEULL, 
            0x11D96EFD396E0ADCULL, 0x84A9B0CBB03147E4ULL, 0x60C78BF9D433DC14ULL, 0x5CC8BD1E7B228F51ULL
        }
    },
    {
        {
            0xF450199759F15AD9ULL, 0x3351653350FB9FC7ULL, 0xA615A2F6F0C1EBD0ULL, 0x39F14A5231948BB0ULL, 
            0x6B19348AC4A1029FULL, 0xCC7407E34543BFFFULL, 0xAFA1E01A3338068EULL, 0x9AD65899DD5F937CULL, 
            0xBBBC96D894CB5234ULL, 0x878720C55244F0DEULL, 0xAF5B30B0212DB8B1ULL, 0xD4CD7906F6C1DFB7ULL, 
            0x8ADD2E2DD5B441BAULL, 0x68F4E2B2467F3035ULL, 0xD3EFC0169FBBFF33ULL, 0x13D3977EBD126503ULL, 
            0xE49F50360240ED3AULL, 0x8FF443804A64401DULL, 0x5C092D0C3DE90EEAULL, 0x59BB144D2A458B12ULL, 
            0x8B736E19ED837401ULL, 0xBEF7E47A0EF9AAC4ULL, 0x1F066BC7E66EAD1BULL, 0xEC83E129E73EC43EULL, 
            0xC8228010C7BE0262ULL, 0x044090832E65EC3DULL, 0x1A52642443DA2702ULL, 0x52179BB3D78DA3C2ULL, 
            0xF92824CA46E47B5DULL, 0xBD5FB1288F612759ULL, 0xC4A352269B2087C5ULL, 0x814446B02A86EEB7ULL
        },
        {
            0x30B5074C566D288CULL, 0x80B35DFE56EDB339ULL, 0x3EE8F2A1C7104307ULL, 0xE9E59D8BFAAB8B9AULL, 
            0x3E7D092556A928BAULL, 0x569C58D25DFE9AD4ULL, 0x06FC2292E9C4D3A6ULL, 0x318EAA2AE77A2C0FULL, 
            0x7CC6CDD71FA2BFB6ULL, 0x6EE6F6BE34F903D4ULL, 0x4E87AA480063D002ULL, 0x0F632A359DB91379ULL, 
            0xB1BFC317D2B3C72AULL, 0xACF85D367A3D03BDULL, 0x93370854530FE4C2ULL, 0xA4B0F7F59382EAC0ULL, 
            0x0318705BD09850ABULL, 0x3A10E62253A2975FULL, 0x19E6B06E5C4B8F93ULL, 0x7595872817B4FF9AULL, 
            0x145B7C7C992CFCC8ULL, 0x84555846EE960B9FULL, 0xE8AEAC13AB368479ULL, 0x13E23BAF8D8FF80FULL, 
            0x215C50BFB7A5AAE5ULL, 0x4A84ADBE5EEE1BD3ULL, 0x3C2EAFEA293500BFULL, 0x564E52DB782977E3ULL, 
            0x601D2BD55A5E89FBULL, 0x463BC56A50597D0DULL, 0x24066B69EB546F57ULL, 0xD7EA210437F38CC9ULL
        },
        {
            0x105BB4B66AECDC92ULL, 0xBCDFB5B480EAB5E1ULL, 0xC59FC60EF2602EFBULL, 0xADBB43A7F1188EEDULL, 
            0x9B5BAE76842736B6ULL, 0x4A4FDDFAB76C3733ULL, 0xDD763258A8868BF7ULL, 0x8ED926E3E0F857C7ULL, 
            0x90BF6AC52D8E2D2CULL, 0xC02EBA3E93771FD3ULL, 0xA2A4A4F54F2047C0ULL, 0x11B8B09937650C85ULL, 
            0x28867F00A077C44BULL, 0x2088C632D1D408C4ULL, 0x1A79F62BB7B1BA1DULL, 0x218B20DDAF78BF00ULL, 
            0x4EB2B882ABBDA053ULL, 0x5E7C727032C99207ULL, 0x1F37AD820F684F2EULL, 0x1CFE54C0C40EC29CULL, 
            0x28A326D87D366234ULL, 0x91BBFC40C8584C9AULL, 0xE03F751154330E67ULL, 0x0CB302929B1007A6ULL, 
            0xC48169E04D01444EULL, 0xD3FD643EFA4F0FFFULL, 0x64594407FFCF2057ULL, 0xC1140F91C6524805ULL, 
            0x556FA44924897C30ULL, 0x5A53D38CBCC71382ULL, 0xD958CA08D074E1C8ULL, 0xB7C7E4497D9C0346ULL
        },
        {
            0x5F1B064EBC6C4A62ULL, 0x653E0814E9C9EC8FULL, 0x0B7D802D2CAAA704ULL, 0xCD695A3B5DA7E94FULL, 
            0x3D3DAC08BF150C28ULL, 0xDA6AE43D1DDF892BULL, 0x029B50A65973EBD3ULL, 0x1704FCE0DFE9C7CEULL, 
            0xE2B2DB6A8949142FULL, 0xE9394385A2564E06ULL, 0x00388C1A4E2F5F69ULL, 0xF8ADC908A642FB42ULL, 
            0xD8B9F1C7C22599A1ULL, 0xCC4CBA3F18F5DD30ULL, 0xA4717141998B3309ULL, 0x6E70B236E5CD0B4FULL, 
            0x7E5D4A64DB2C2566ULL, 0x923E41AF232FEC13ULL, 0xFED524998742CAC9ULL, 0x4FFB1554D4EF20ADULL, 
            0x272ED2AB7080F079ULL, 0x6A7351BD06FDB366ULL, 0x8DD1333C6F7D5FC0ULL, 0x8597C47D31CE7A37ULL, 
            0x1169C10AD4498A19ULL, 0x831BAFF5DCDB12CEULL, 0x5E0C09BEDD1CEDDCULL, 0x1C7E9ADE3A9EC5DAULL, 
            0x20266CE99FF2B512ULL, 0x47AA60EB5C83F7CBULL, 0xB3DA681DA5FFD1C8ULL, 0x864B3DB7CB257BE1ULL
        },
        {
            0x15217323B0FF4C8FULL, 0xFD9AEBB8AF39D096ULL, 0x0186EE2456966EDBULL, 0x02666BA81C121F7CULL, 
            0xE88F9CB2E116761BULL, 0x7A62BFC39913FA16ULL, 0xB4518212C248DB17ULL, 0x3550C6D12CEFAE21ULL, 
            0x995820ECF27D31A8ULL, 0xEFD5855E0B39BC82ULL, 0xC73C6579A245A00FULL, 0x8623BBB4D31A589DULL, 
            0x644F1D3017BB0E23ULL, 0xDB8DC21A356D9B25ULL, 0x961C35065C1227E1ULL, 0xCEC5EE88AFA40E28ULL, 
            0x9218054426445C15ULL, 0x117737ED75A39203ULL, 0x692EB52437648BD8ULL, 0x3A2DB6775AC225EDULL, 
            0xA03E883DD61F2BBAULL, 0x31691EAE598B0E41ULL, 0xD384FFFA808CAAE6ULL, 0x35DE6341E9D03B1EULL, 
            0xE343701530799205ULL, 0xDADB4D7D4FA01FDEULL, 0xA7CB603025ABCFB8ULL, 0xC21054F1EAF1F001ULL, 
            0xCB7CC04473DFB3C7ULL, 0x7E4B6805E5142B4EULL, 0xB4776520B5D819A6ULL, 0x7454F6A3152F9EA4ULL
        },
        {
            0xF4316A71380FE542ULL, 0x05E47EEAE9B688B7ULL, 0x4770608BE2827574ULL, 0xC7A33EDD13FED514ULL, 
            0xA9A7B968BAD5CCEBULL, 0x38682E60D11C38DAULL, 0x3EC93AFDB44508C9ULL, 0x839FFF4D881109B4ULL, 
            0x31286CAF45B99F59ULL, 0x9FC0887EC6FD130DULL, 0xCB9BABAC4A91163AULL, 0xA74EEBCD0EA8681BULL, 
            0xDDF9E809384B1E43ULL, 0x3091F0A87E25BF2EULL, 0x0F06BC88E62F19ABULL, 0x78581FD628F48CF0ULL, 
            0x53A3106A77498E87ULL, 0x615F50DC6426DB98ULL, 0xCF7E422E8B71ED63ULL, 0x4C0E4B28C6BCF64BULL, 
            0x75BEBE465254D5BFULL, 0xFE71DC0F3331EAFFULL, 0xFE72A128A8EDC85CULL, 0x782A215A6CA0C978ULL, 
            0x0AF28394BC17F61FULL, 0x51FA17ED4265CB54ULL, 0xFBAF8729D4503A10ULL, 0xB5287D32FE394B12ULL, 
            0xCDD2875800EC541CULL, 0x67F3C70C8FD0224CULL, 0xB38080FC2CE71876ULL, 0x30450D919766437CULL
        }
    },
    {
        {
            0x0DAEB8E8C1C483E5ULL, 0x963C27EEC11CDA79ULL, 0x1BF8E9E413B6D78AULL, 0x8C860E9AA96AD9A6ULL, 
            0xD2DF7988E1656FABULL, 0x1C0FA2AFE8B4CFDDULL, 0xD48689DEF96809B7ULL, 0xC08628156062E8F1ULL, 
            0x5036FB0E306E57FDULL, 0xF774F8DE9E7B5A5FULL, 0x3AF6AB3892FA90E3ULL, 0x0DD7570A746B8151ULL, 
            0x2B9C34AAA070A7E6ULL, 0x363FECE77FD812BCULL, 0xDE6A628D94918BEAULL, 0x01A34A89D5BDB3B7ULL, 
            0xB0D59CA0E7B68C76ULL, 0x1128442E4BC2C3E9ULL, 0x9220600C893B817AULL, 0x3E994BDFB81E07E2ULL, 
            0x797DB728809A271FULL, 0xCB1632C6A87470D3ULL, 0x494886CF15F8C08BULL, 0x497EFCCA270605F6ULL, 
            0x87245096C331C386ULL, 0xBBAE5A3D5617D337ULL, 0x96F5F92F97389A4BULL, 0xD546D01CAE57492FULL, 
            0x78DB68B927F8FD19ULL, 0xF57FDA810003CBF2ULL, 0x9D81D85335CB4595ULL, 0x04A3A9ACA563709BULL
        },
        {
            0x888F8F28ACCE9CD6ULL, 0x762539A0EB4F3D98ULL, 0xC74805128914D504ULL, 0x4D5DDEF94C10C59CULL, 
            0x48290BD853C8C383ULL, 0x563CC320C3561A42ULL, 0xB48611B25ADA9EA1ULL, 0x188D0E4CB287166EULL, 
            0x2AD9BCD6A0BCAC1EULL, 0x9C3421227A0F318BULL, 0x3CD02E64516B1F39ULL, 0xFCA3C5447657553FULL, 
            0x551518C993287AE7ULL, 0xD72DB062B5FE1F6DULL, 0x52A3B193E5648C60ULL, 0xE13DC6251492FEAEULL, 
            0xAE0F9DF091FD1A83ULL, 0x89DC67B8917E5F2DULL, 0x5D5808F319A5C7C2ULL, 0xCA4EBC44396FA968ULL, 
            0x7BEBCD0E274398BBULL, 0x42758BEFAD4728F4ULL, 0x12D50ADD03FADCA3ULL, 0xBA55085C58211892ULL, 
            0xDB1CB1085E96070FULL, 0x71BC42DFAEECAF98ULL, 0xD59AC0C029740BC0ULL, 0xAED1DE6031D50D2DULL, 
            0xC3F632EB51E0ABAAULL, 0xEDD0D119EBD422A6ULL, 0xCA2C376588E795A4ULL, 0x2E7A0C7C8C7275A4ULL
        },
        {
            0x5D953229339D5B66ULL, 0x82FF1D68B64E1AC2ULL, 0x0E6B3B6CCFA4B983ULL, 0x0E6CBD11BCDE248DULL, 
            0x0CDB8BED5748D15CULL, 0x0398A66FB5574444ULL, 0x170A9F5D6D29F6D2ULL, 0x2E6162D95658E304ULL, 
            0xC56AB668C49D9885ULL, 0x382BC8FD40B8CFF5ULL, 0x5FD66367A198D989ULL, 0x2700F1AF11BE367EULL, 
            0x8EAC39F816E58FD6ULL, 0xD8726E9CA3221DE3ULL, 0xD08819085DE9EA47ULL, 0xD07765575AB6EFCDULL, 
            0x2730AD38AA914333ULL, 0xDF16158B616233C7ULL, 0xB8BC027F5CB61556ULL, 0xD8B6F66B949B2E05ULL, 
            0x74C79E1AC324ADAEULL, 0x06BD3C5C64D02A41ULL, 0x5F1D99C772A154A6ULL, 0xC10B6F4A2EE2CBB1ULL, 
            0x29954C6A569BDAFEULL, 0x38A289523DB0B95AULL, 0x0F723A623C714233ULL, 0xEF823B5CAEC4FC2EULL, 
            0x0DC1DEE6D7874BF5ULL, 0x874AE59E5DD6A231ULL, 0x7B470BFD2A90F914ULL, 0xD3EDA7E76D4BC3F2ULL
        },
        {
            0x0D0CB8123FCA3211ULL, 0x43D70C3F7EDCAA02ULL, 0x9B18F3E8ED063EA3ULL, 0x1E3E1F0B777816E6ULL, 
            0x067B0DD41DF4F94EULL, 0x6C9B545F162B0D3EULL, 0x64B5D53ED3F9C164ULL, 0x065C9C8499C68369ULL, 
            0xC2636323F48A13E9ULL, 0xE6C7795BD81276C9ULL, 0x271EF0B0F3473E63ULL, 0x58DCF32FDD848890ULL, 
            0x6F69DF7EAAE71006ULL, 0x94459B6C63D7E608ULL, 0x22F13ED548E34953ULL, 0x465672F2AF66B8C2ULL, 
            0x9E84EC2855B5F55DULL, 0xA033B1D4B1F52737ULL, 0xE6384F70FF012C42ULL, 0xF8A64A11C8EAB905ULL, 
            0x872F8FCE67CFE259ULL, 0x0036B897B4833761ULL, 0xFE160A95A083E7D8ULL, 0x6649D35A115CBB1DULL, 
            0x464B1FAD95F474CCULL, 0xB5DD7FCA312349B9ULL, 0xAC506B8E9FBDFC46ULL, 0x304F6EC59296D8D7ULL, 
            0xD28EAD76476A921DULL, 0x81AB0FCB9AF8D898ULL, 0xF7D25A25711AA40DULL, 0x27688809AB847D9AULL
        },
        {
            0xD54F4BE1C4503636ULL, 0x50A5404CD7F677BCULL, 0x175FFED63F4A2C9DULL, 0xF465BDF05F92F6BAULL, 
            0xB3A34076603D10DDULL, 0xC07CF93BF7C866B7ULL, 0x2228423FCF7C4C16ULL, 0xFF18B5360F0D93BCULL, 
            0xEF14ED31D658E349ULL, 0xA2928DFFD6564FFEULL, 0xFC8E1D632C02D1BAULL, 0x19BEB7685903FE7AULL, 
            0x179C8FF78D0913B1ULL, 0xE6CA984182154E02ULL, 0xC74184D3345604E6ULL, 0x73CADFEF2418D717ULL, 
            0xA7A36CAD3F5136A0ULL, 0x114106D95F1E5680ULL, 0x5F503081330DDA4DULL, 0x97265502DCD4466EULL, 
            0x45D5D51E571918E4ULL, 0x90E885CDB2A0B036ULL, 0xA375FB1C80AB4D27ULL, 0xC951AAC1F08FA95EULL, 
            0x3C76DD982252CDACULL, 0x132C59C398560665ULL, 0xB23991AF611AFCB4ULL, 0x0F168F0F041B7BAEULL, 
            0xDBF40BCF5EE2427FULL, 0x5C1AD6DA75E7EBC3ULL, 0x771BB044CF04B5C2ULL, 0xA6AA1DD2EB878735ULL
        },
        {
            0xB300C7B4B6BEAFDDULL, 0x77AD2B28A8F4ADA6ULL, 0x912B4C5FB537357FULL, 0x75EDD610041813B3ULL, 
            0x88E911F0A6C6F26CULL, 0xE55E2EE6DFD14006ULL, 0x67CD664A56129B7BULL, 0x14BA202C37DB39DCULL, 
            0xD7D3E423DD0B2149ULL, 0x964AE8B723F23D2BULL, 0xE23C24FA53F70538ULL, 0xED33E4458E82512AULL, 
            0x70569DE7FAEEAE28ULL, 0x8713EA1F2A99B812ULL, 0xECD8451F8C1605B6ULL, 0xC44F446D8A1A7074ULL, 
            0x7E707E642DA0E884ULL, 0x4B33601360DDC746ULL, 0x37C35389D9D22928ULL, 0x99A17DD31F8CFBF8ULL, 
            0x477C2E6F320BA711ULL, 0x62A2B1F108906A5CULL, 0xE6576DD1DC7B8427ULL, 0xA1A8CBA42914D9FCULL, 
            0xAD5E88B7FD972D36ULL, 0xD71AC073EE3CF5B9ULL, 0xD42E0DCDE94279A7ULL, 0xF4A5D909E6AA8669ULL, 
            0xBEE61DBF5B07EEB9ULL, 0xA68890221C26C408ULL, 0x471285176D5EAB12ULL, 0x392B56FD6B3A1EE5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseAConstants = {
    0x8ABDCE88BB68E24AULL,
    0x3A7B277EDF6A2153ULL,
    0x9AC9106EBB75DA59ULL,
    0x8ABDCE88BB68E24AULL,
    0x3A7B277EDF6A2153ULL,
    0x9AC9106EBB75DA59ULL,
    0x27D7E4F4E5ED7232ULL,
    0x03DD537EADA695AAULL,
    0x4A,
    0xAB,
    0x9E,
    0x9C,
    0x54,
    0x08,
    0x85,
    0x65
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseBSalts = {
    {
        {
            0xB6E21FEA917389B8ULL, 0x440E850E59FDAF80ULL, 0x2DABAE1BBFF0B18BULL, 0x2FF3F4397E13F466ULL, 
            0x985A55E7BFCCDE88ULL, 0x5429A7540BE8F3E1ULL, 0x95A1FAE86378309DULL, 0x4218488C73ADF291ULL, 
            0x9FE8CA05AB22F872ULL, 0xE4139F7B4E58E70CULL, 0x7F801B695416DCF5ULL, 0x453FF0E4DB519BD7ULL, 
            0x3C1BA59BF45D86BCULL, 0xD03F60FCCD2F7905ULL, 0x9AC819C88A042134ULL, 0xEA58B46CDD99D2B8ULL, 
            0x3AD8B2A031D5693FULL, 0x73C924F03D184A56ULL, 0x4C3892B9E4212565ULL, 0x544802F3A00678AEULL, 
            0x16EBDFC836A19DC1ULL, 0x0303053775DDFC11ULL, 0xFDD43717410C6770ULL, 0xEE7885A9FBAC403DULL, 
            0x563A13CA40D4A77EULL, 0xB23467845CB99368ULL, 0x942F1F5634FD9BA1ULL, 0x89C3E1648570B9F2ULL, 
            0x895FA69642ED091FULL, 0xE7D6DD9C8CDCAD69ULL, 0xCA01157CF150F536ULL, 0xCF2AD36065E3C8EDULL
        },
        {
            0x4658F1B515AEBED5ULL, 0x1DA05C31E4634241ULL, 0x3C958794593214CEULL, 0xF0654BE1F70B5900ULL, 
            0xB55305B1AE155415ULL, 0xD4C9512A521AF103ULL, 0x8541AAFE0B025C5AULL, 0x3470509F7E275980ULL, 
            0x0BF6C0AB4B2DCBC1ULL, 0x3EAC527D04F2EAE2ULL, 0x3047C5D8BBCC4ACDULL, 0x43825900AE33E9AEULL, 
            0x20D1709B03DE5670ULL, 0x7A0B7882D481EB24ULL, 0xD0AB8BD85ACCEBE1ULL, 0x1735A8114FEBEF35ULL, 
            0x88CE385A0CB6F0A4ULL, 0x86B5A1F771DC0CE3ULL, 0xFC8F9B6FA33E3196ULL, 0xC5935677F84DC106ULL, 
            0x3D10F96489C0B0B8ULL, 0x7E31EC59A40521ADULL, 0x9EC8BC5C6A91EA37ULL, 0x287DB14AA00ECBAEULL, 
            0x11B57DCB62DD7DA6ULL, 0x23C84C54029D4E0FULL, 0x200239E8C3D4A893ULL, 0x75D52BAFFA97FD12ULL, 
            0xF40CC432B0AF1089ULL, 0xD756A2B620E58517ULL, 0x2B5B644DF768E042ULL, 0x0D1C87EA15C65572ULL
        },
        {
            0xACD178473CC65E82ULL, 0x990024A3CE74867DULL, 0xA7985498E0388B2AULL, 0x3B35C0DF95D1CC5FULL, 
            0x4C7DA8B3B8FE8966ULL, 0x70FE2DF311D71B7AULL, 0xB47809A0A502B468ULL, 0x762EB3B0FA46B8BBULL, 
            0x99FE616FA2DF6FADULL, 0xE225A9E4899086B2ULL, 0x592C67E22F3E5158ULL, 0x61384808D5203CEFULL, 
            0x63386A4B677A887AULL, 0xB0A4271D593D7E58ULL, 0x1E3029EDAA61B6AFULL, 0x9D2C5285931F44FFULL, 
            0xD69B8F7C390106A1ULL, 0xF2AA823B52162305ULL, 0xD497FBF465C12A01ULL, 0x1145472CCDB98B52ULL, 
            0x5E71475CBAB8CDCAULL, 0x5BFBA17B7248B3F1ULL, 0x815BF96E87D0CA59ULL, 0x78B9A2D8C79794C2ULL, 
            0x7431BC980AF3BB4DULL, 0x383EB83637AFC8CCULL, 0x2155A4F8C8291C2DULL, 0x3494D640EFB5AFEFULL, 
            0x35ECEBC211DF20A8ULL, 0x001D08A8FDDE3668ULL, 0x7475DAF429F1E959ULL, 0x6B911C214F5B98E0ULL
        },
        {
            0xA278D1797C7A7ECAULL, 0x6B0D43442ACC791BULL, 0x3974BF50D1D46C1AULL, 0x424C26EA60AB24D1ULL, 
            0x4C8E6C20253688E5ULL, 0xE61E39BA65903AA8ULL, 0x27FC350AB166F67DULL, 0x6CBAC4EF7DBCCD9CULL, 
            0x669AA4B0F083AA3FULL, 0x58ABE15CE1F99E7BULL, 0xDDC1564B355BA591ULL, 0x17E78331761A0B74ULL, 
            0x3D168AB64EDE6117ULL, 0x28B66659B9597BD4ULL, 0x68DAA2C66E6402C5ULL, 0x3ADC64C86074F64BULL, 
            0xB006F98BCF409AB2ULL, 0x4B0E75EF5148FC0FULL, 0x1273C16F0B25B417ULL, 0xF71A255213AD74AFULL, 
            0x82FC3568952116B7ULL, 0x38917B25450FE147ULL, 0x45C5562B123A5225ULL, 0x5EBEAE4FDB122DC2ULL, 
            0x822D88565237B446ULL, 0x0A9BDBA6AA9004D0ULL, 0x78CE157633B9F5CAULL, 0x6B852966C6A199EFULL, 
            0x3BB266C6E3AB1AF1ULL, 0x78CBC5A1B0617A4CULL, 0x475479C4E9DABE1AULL, 0x0161F36A00FDDDD9ULL
        },
        {
            0xD54205BCE6EB01EAULL, 0xD81F141A3432900FULL, 0x839EA5F5C0A239C8ULL, 0xDCFB393451FED71EULL, 
            0xE27C799EF2EB5F43ULL, 0xA428A1C482757A9BULL, 0x685AFA644D17E3F3ULL, 0x19D0BA5E4B006440ULL, 
            0x8B6DEF5632D39396ULL, 0x6D9FA016F7737D1EULL, 0xEE35F63B5FEF8432ULL, 0xDEF2086AEF5FED92ULL, 
            0x4DE7059F2EDA319BULL, 0x80C7E12800DCFB85ULL, 0xB923CF10C6781F75ULL, 0xB774030E2CF1190CULL, 
            0xEB2157855585453FULL, 0xA73B5285A8A78321ULL, 0x5E94918A222F9870ULL, 0x5CA8FA3629568ABCULL, 
            0x449B7D616F3C533EULL, 0x782F80AC9AED4D0DULL, 0x3FC060307897A1BBULL, 0x9F073FE5F99D0A4DULL, 
            0xC0596E9928EA435FULL, 0xA429C558A2B340A6ULL, 0xB0B98303B8826002ULL, 0x75D1982A9D067DD7ULL, 
            0xD79C04D314537982ULL, 0x416378BD078FDC7AULL, 0x005E60636E72EC87ULL, 0x2B4646448CA59354ULL
        },
        {
            0x65BA8CFBE5E5DC45ULL, 0x25E66B1938F51AA9ULL, 0x478762657C989DBBULL, 0x28D1AEF11C3D8166ULL, 
            0xFF4ADF3227EDB90AULL, 0xC1AC40B9B65645D0ULL, 0xD26EF1411BBD73EEULL, 0x4EAD1E2DD1DA794FULL, 
            0x9E2D8DDA09190EE4ULL, 0x36D912D5C26797C7ULL, 0x0145E8DCAD0F4AF7ULL, 0xC81BE1DCB1F326ADULL, 
            0x9D925610B8714991ULL, 0xC33B31FCF8C38599ULL, 0x394DA4F175A17A15ULL, 0x7F879030F3AEF7EEULL, 
            0x89AC2DC46D4CC233ULL, 0x0D030AD44B896A30ULL, 0xDB099D3E13D0DBB7ULL, 0x056ED0419BCBE90EULL, 
            0xF451B811C37A4AA3ULL, 0xF1B74B2CCF015F2FULL, 0x6ECEF793E1FB2DEBULL, 0xF90EB29C5F8794E6ULL, 
            0xFC1E0B97D009FFF4ULL, 0xA1EAF4C74ACB5F54ULL, 0x1FAC5E7CCBD6D16FULL, 0x90CB8D6E93E73768ULL, 
            0xEB736C0980F16188ULL, 0xE7B89921D4FD1092ULL, 0x190BB1A5B86A0670ULL, 0xE384367269AFCCD7ULL
        }
    },
    {
        {
            0x95FAABB9F7491C82ULL, 0x021B7AB537F8D42AULL, 0x6F316F155129DE1EULL, 0x0CE81002EDBE2843ULL, 
            0x47F863880BF246A1ULL, 0x3BF40D8E440161D0ULL, 0xF547A2A22DF5629DULL, 0xB223B9B5263899B6ULL, 
            0x4E9BFE1837256988ULL, 0x01B76A6DF7016604ULL, 0x43EE09A0D543FA4EULL, 0x805EF3B106F8FBECULL, 
            0xC37C9B34BE0EDC95ULL, 0x430FB437DE406E57ULL, 0x65DFC82978BC56E2ULL, 0x50F6D5E24F693C65ULL, 
            0x1A26D1ADF7519D34ULL, 0x105EDEA8A2EB297FULL, 0xFC2A648E137523D6ULL, 0x7E3C199D15844DACULL, 
            0x7EC8A21B00E66B21ULL, 0x2DE913922B80C8A5ULL, 0x3CBC0D8287FEC0BBULL, 0xC9BBE932EE6A2BEFULL, 
            0x45D26998DB22DF64ULL, 0xC150B093343608F4ULL, 0xE3135469EAA966FEULL, 0xCFAA80254CCDE432ULL, 
            0xA43D97435F0C7FF2ULL, 0xD915565F78C3CA47ULL, 0xE8411F745A98A5D2ULL, 0x62D521C5D4213102ULL
        },
        {
            0x7F94C3BD333CE33CULL, 0x2EC2F22428179364ULL, 0x645FCABC3515CC1BULL, 0x1EA41CDE48D6485CULL, 
            0x0E174DF2BABDC354ULL, 0x4D0C3A4DE2D26224ULL, 0x2169891D2F20E919ULL, 0x77AC52238700551FULL, 
            0x3907BF8A00BAD594ULL, 0xCB796FAF2976E733ULL, 0x1C02354BAD3A7F46ULL, 0x4B65C054F862E52CULL, 
            0xC5222D5E4A503C16ULL, 0x953974A9AB79E04CULL, 0x13EB56D5B5778886ULL, 0xB68B133E0C9A58C9ULL, 
            0x8E2C3E24E9C022B5ULL, 0x238B039523137847ULL, 0x44C92D675C829563ULL, 0xB582B20E879BD35EULL, 
            0xB9C57ED03F9D954CULL, 0xFB84FC330885DBB1ULL, 0x4035893A8F101E1DULL, 0x804AFE5A07A13F01ULL, 
            0x2EA4EEF3EFCF8EAEULL, 0x534B484DE5823829ULL, 0x4233EE4BF8207489ULL, 0x66DE4BF63E5618DFULL, 
            0x0D25C72CE54179A4ULL, 0x743F216B367633F4ULL, 0xB4DF7794E41C95D7ULL, 0xD8D0B2414FFC1278ULL
        },
        {
            0x6D370213E2E86FFBULL, 0xE4DA2AE5DA8C31E1ULL, 0x1F7525B11E8CE5C7ULL, 0xB4EDE46002F48747ULL, 
            0x3E222601E0AE188EULL, 0xBFEE391DAD58889CULL, 0x8040B5ECF163D8E9ULL, 0xA671925F3B9003CBULL, 
            0x0782D835172AADDEULL, 0x658AB681DE869465ULL, 0x9E922889DC8B299DULL, 0xB62956B14C5E659BULL, 
            0x0B96FE450281C532ULL, 0x910D0F279D15851FULL, 0x96E28EE8C957CDD8ULL, 0x2B79CD25CEB42DE2ULL, 
            0x044D02615D480E87ULL, 0xB1A34D951A7C26A4ULL, 0x9C5FB55DA3C72F31ULL, 0xDE8400E6E5B9A634ULL, 
            0xA84B10B57CB5EA8FULL, 0x01DB351A8E969CADULL, 0x85BDBD7D0B3EEA26ULL, 0xA01CB689C7031FD9ULL, 
            0xE66629C8B6D6EB08ULL, 0xBB89A86D3B61D4A7ULL, 0x4560A9700FF34909ULL, 0x5181D80A32C182CEULL, 
            0x9718FE011DAD6E00ULL, 0x47A0E445E011E51FULL, 0x232FF50B93255F92ULL, 0x568F0DEC0BE5D399ULL
        },
        {
            0xD1C8031E637D99CBULL, 0xC5D6D22AD59C4319ULL, 0x47D3CDC18956E205ULL, 0xBDDF4E5E48B286B9ULL, 
            0xBEDFE0B0181F42B4ULL, 0x4AF28F3D0ABEBCC1ULL, 0x0B6C0438E5D1ECCDULL, 0xBDCB4985A398CC47ULL, 
            0xDF0DD377707258BEULL, 0x66BF671AA0B80EAAULL, 0x4106987BFE54CC41ULL, 0xC1789486B6414D1DULL, 
            0x18D5955CA3700BB0ULL, 0x841C75CBF51C4DCFULL, 0xC082CDAA634333DBULL, 0xDE54B7D071661B90ULL, 
            0xD2C0C28CD9EE899EULL, 0xADEE46B358B9DA45ULL, 0x9174699601A25E9CULL, 0x708AE3E9338C4E51ULL, 
            0xCBC117CEF61D89F4ULL, 0xFFB5BDAEB2FB5250ULL, 0xF612CF7742F80C9BULL, 0xBD45E4FE02968590ULL, 
            0x52A0B082AA5B89FAULL, 0xD8CD1C075CB69FB6ULL, 0x4C3EFD3EC470F58CULL, 0x2E0B4E2A60C91BA6ULL, 
            0x4A4E18A697ECBD60ULL, 0x519150D54DF1E368ULL, 0x6EE2EBD12709C4DEULL, 0x9176739B0A5E3804ULL
        },
        {
            0x10CDE69F3ACFC041ULL, 0x618BFE1EF5ED047DULL, 0x8107867F6C6BC8C9ULL, 0x9DDC1D9309CE3F2DULL, 
            0x9A7C84A0FDA75048ULL, 0xE22C1DCDCF94FCBEULL, 0xF28ACE81E1E31F2FULL, 0xF6EE1B2B88B45823ULL, 
            0x1CB1C9BD462CCD48ULL, 0x23C1D94420F7845CULL, 0x0E1B3D28BF5A2611ULL, 0xAB1F95B910230886ULL, 
            0x96699E36BA5D5BC5ULL, 0xEC983D87C2EA0BA5ULL, 0x1B7CD57738FB60C9ULL, 0x264684BBDB62F21EULL, 
            0x80C2DCE85A9D04F5ULL, 0xD1E1621C9E743D46ULL, 0xA5CA52A0B7A09A61ULL, 0x0E80869F31E0EB6AULL, 
            0xFA836171E288AE18ULL, 0x2328DEFF3B1404B0ULL, 0x63CC9CA399CB90C7ULL, 0x1432FE6B6AAF9D9FULL, 
            0xEFB26FC24A02D876ULL, 0xB6F6398E553E408FULL, 0x8E997853CFEC7C0FULL, 0x20463FCD5419AB32ULL, 
            0x17E2A1EEE7EA8A88ULL, 0xAD6852BEF55FCFB4ULL, 0x680D696A772FC999ULL, 0x6A4FED5309FF961DULL
        },
        {
            0x23BD4C4F4D3E741FULL, 0x8E926DD4F47EB451ULL, 0xCF3649537F5BD309ULL, 0x5C183D530EAD3E63ULL, 
            0x423254D86A720F0FULL, 0x4E9F5B6D97BAFED2ULL, 0x7D594072537EF3C6ULL, 0x99079802774D9A59ULL, 
            0x349C238A2AAD87DEULL, 0x3045C78E80F885E0ULL, 0x7AB800B633F21E0EULL, 0x06CA150CE5D7BBCFULL, 
            0x563A893BE0C8B858ULL, 0x6C90F03E79AEDD36ULL, 0xD5978D82B031BB65ULL, 0x9F904AE7BEEE9111ULL, 
            0x9E13DAAC7AFFE0F0ULL, 0x7206BBE4E75B9BAAULL, 0x9340FCFE7C514F2EULL, 0x03CDA3B8C4C55013ULL, 
            0xC16A18B7F9AD5E43ULL, 0x8A9156E3C59A977BULL, 0x3C58EE84C4469484ULL, 0xDCA14DDD4E3A488FULL, 
            0xFA2DE34460085AFAULL, 0x1FB42E600ADAA74EULL, 0xE412B567D99A8F4FULL, 0x5F197C32E798D80EULL, 
            0x9319EA392C4ED21CULL, 0xFFED59599EDE248AULL, 0xEBDD7EDA301BF7E5ULL, 0x1F630229238819D4ULL
        }
    },
    {
        {
            0x774C2B97E0BBBE12ULL, 0x34648F69F5326A16ULL, 0x33A047A32C265FCCULL, 0x84F5E8B04E1EB317ULL, 
            0x8D0ADDA81FAFF940ULL, 0xF5D18EAE498A807EULL, 0x23C4ACA41F7532F3ULL, 0x5FCD04778E9A4F68ULL, 
            0x7806739FFF32492CULL, 0x53DA62F980CCB84FULL, 0xFD6EEF2CA58DB486ULL, 0xE3EC015AA02C9E85ULL, 
            0x2E16493719D4DEF7ULL, 0x75918B6DCE655376ULL, 0xF7EC6118ECF2F864ULL, 0x347CFEEDF63661F6ULL, 
            0x53DA0843F651ADA7ULL, 0xCA6EB91561566253ULL, 0x05D5B395585CB2CAULL, 0xE82B5E05F34D23C7ULL, 
            0x871E3CDEB69458C6ULL, 0x8A47067062DD85FBULL, 0x17B4BB6B1811E1F7ULL, 0x7E68FF6B3D8C348FULL, 
            0x62C593786C50C301ULL, 0x13B34AF3DF3A2967ULL, 0xECA9D5B255E6538DULL, 0xD7247C8226AB2AE3ULL, 
            0xF54600BFF35F2C1EULL, 0xED621FE41CFF4570ULL, 0xEB2006EDBD1B4A57ULL, 0xDF1F706E597AA8AAULL
        },
        {
            0xAC8FCFCFF6CC55B3ULL, 0xFDA7CA72769A7183ULL, 0xCFA858A8C2F0D343ULL, 0x6B691FD90FA0A5D2ULL, 
            0x0E31EC4F60C57215ULL, 0x8CBE7556DBEF296CULL, 0x6D15E7ED63D401A9ULL, 0x47303DCF1BAF44ABULL, 
            0x3526D2378ABADDF7ULL, 0x7387A817FEA5BF64ULL, 0xE1F089E299AAB5F3ULL, 0x4B6C559D306A4888ULL, 
            0x276B82E11478A6A6ULL, 0x8366BFA1071CDA68ULL, 0x8FD6C2585CE13A79ULL, 0xBEBB067DB9EC30C4ULL, 
            0xB47AB083807B142EULL, 0x06B9C2AC7CD5EA24ULL, 0x46ED22B30CC4013AULL, 0xC4526F4A2DD367F9ULL, 
            0x13B3157377436A8BULL, 0xD56133D033F179D7ULL, 0x456AC575B431D411ULL, 0x98D89FF174C535E4ULL, 
            0xF8C62255F9409331ULL, 0xFD3160F0F191B881ULL, 0x9A186F1381180115ULL, 0x2FF29C5949279699ULL, 
            0xB9698EB7820C5744ULL, 0x457A88FDF7E3B033ULL, 0xCFC028F27D6DDCD9ULL, 0xD813BAEBB35FB971ULL
        },
        {
            0x52F6B7EE36CC8831ULL, 0x21A80D9D8A33ABAFULL, 0xDBFD581161384C05ULL, 0x34B2E8B1D7ED0837ULL, 
            0x7670C3692B6AFF85ULL, 0xE27B829E7037297EULL, 0x0688CFC624D847EBULL, 0xBEEEFFD2BDC390D0ULL, 
            0xAE358C5456D9CB8FULL, 0xEA84D4D3C8B16E59ULL, 0x69025BCC7ACB7CA2ULL, 0x4F7C673B375A5939ULL, 
            0xB2D13050682F3BB9ULL, 0xF48882D139044D58ULL, 0x50CF757E1704BCFCULL, 0xED61B8C0785734BBULL, 
            0x9D20D4667D36AF63ULL, 0xD420F02263455DC7ULL, 0x23C2EF9D02E8317FULL, 0x020B303BC838B4CCULL, 
            0x10647788E725E9BBULL, 0xEA6B9394D9B52618ULL, 0x0DB41810C9FABE47ULL, 0x77389E92F30250A5ULL, 
            0xFE7B6853977EB3E9ULL, 0xF4615F54D4AE9B33ULL, 0x0F07A2085A453C62ULL, 0x2251DBF08136A47FULL, 
            0x29FC02DC1CEC173AULL, 0x45939042DE469133ULL, 0x8A1F66C4A97B7DC9ULL, 0xFCA3236DB0E1CFFCULL
        },
        {
            0x85F16DEFAC83B29AULL, 0xC8EB68B2FB718788ULL, 0xE487BB8636E9F9BCULL, 0x8D6223F6B684FD92ULL, 
            0xCB56B3B41678B95DULL, 0x6F817344078F2E58ULL, 0x5773B482E142F497ULL, 0x6CA3F7CDE279FF18ULL, 
            0xF0EAC9D9ED7984F2ULL, 0x1CDB6F1127CB62B2ULL, 0x035D1BCD48327DF3ULL, 0x14ACACC103192865ULL, 
            0xC5D6AA166678AE21ULL, 0x6090A64576E38383ULL, 0x4B10449B094331F4ULL, 0x76712001E36FA02EULL, 
            0x82F2B036A2E43353ULL, 0x54FB37E48F15D73BULL, 0xA38F79BB6B685595ULL, 0x851E7C4B8AF4C5E5ULL, 
            0xCE7F3876F44C420AULL, 0x276ED51D026D5860ULL, 0xC1A7A980CD185954ULL, 0x4E9B00039DCA005DULL, 
            0x7F986116254AB8BEULL, 0xF0AF889D6F21DB26ULL, 0x6DEC7D02F59CC1F7ULL, 0x11DFE3771CE79B0BULL, 
            0x71E7AC54FCF258FAULL, 0xAA701F234C1C7BADULL, 0xE8B974E0A736E203ULL, 0xF0840F6EEF44C21CULL
        },
        {
            0xBB8C104ACA57C0B7ULL, 0x0C4929ACC4AF94F2ULL, 0xA31DA8FB0384B6B5ULL, 0xF00647E18232F2C0ULL, 
            0x23D9B37BB44A01E5ULL, 0xC86CFF6457D977E7ULL, 0x9BF95A36A8C8087CULL, 0xA5943134B60EDCDCULL, 
            0x3DA468F417BF2C3CULL, 0xAE41477402D7B6A0ULL, 0xCECDB6AF4D9B2C08ULL, 0xA87962EFB8334A72ULL, 
            0x5A51E58F01B14132ULL, 0x4B90281F8CAD2E0AULL, 0x974FE03AFE84F077ULL, 0x9FADBD727B053852ULL, 
            0x842E2430EB55256DULL, 0xDB307F5A1D47FAACULL, 0x83CA30947E0A49A8ULL, 0x5E1505076486F147ULL, 
            0x57EBC67D96D62EDEULL, 0x65CD5274A1E047EFULL, 0x185D0F128B5230FEULL, 0xCC22A7961A9C9122ULL, 
            0x58A11AF8B21CFE96ULL, 0x051ACE054B259B53ULL, 0xC4551F5E6160841EULL, 0xC5A54930DABC8BBEULL, 
            0x46B8F6F01C5B57D0ULL, 0xF69A9DDE62CE73FEULL, 0xD0D0AEE8BB30719AULL, 0xDC39A355E91DED84ULL
        },
        {
            0xF6B88A8D2B677A55ULL, 0xF23AF92EECFC0A42ULL, 0x05EB0E3F6C8C183FULL, 0xA1C8CC9602183636ULL, 
            0x8D4063475ED2F56FULL, 0x7DD0E5344C7F9C24ULL, 0xDE5180E5AC4514D8ULL, 0x300AFC96934936DEULL, 
            0x9B2A7490B088BE03ULL, 0x0A0F691FD02FB395ULL, 0xB3F45F8B2548C52CULL, 0xCB907B10C9B2DD4CULL, 
            0xD7D047309DE5103DULL, 0x65CEA7740B448BE5ULL, 0xE5A12290662361A7ULL, 0xD4B7BD4BD34D6096ULL, 
            0x3F9D376A410F14F6ULL, 0x72ECE6323F486D9BULL, 0x84324FB8B143C5B1ULL, 0x5AC9762EF61D0064ULL, 
            0xF80A8927899FB80AULL, 0x0E9CB7C67A8E8894ULL, 0xD1A8EE887149C071ULL, 0xD9D0C4882CF38AECULL, 
            0xEB6958B2082F0F06ULL, 0x3AEDF5E335193DE1ULL, 0xFD77F04AF13120E2ULL, 0x3EBC5868D7E8B388ULL, 
            0x064ECDE682BA3491ULL, 0x2C89AEA6E25F1A15ULL, 0xBDF3A1B19AC99636ULL, 0x10AEB31F480E2F8FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseBConstants = {
    0x522A875ED58D1A0EULL,
    0xA2E3D77743E8F910ULL,
    0xBB8B8F3F476AED0FULL,
    0x522A875ED58D1A0EULL,
    0xA2E3D77743E8F910ULL,
    0xBB8B8F3F476AED0FULL,
    0xCCB0DA7EA254A2ACULL,
    0xE4A2B08B08BB8CB6ULL,
    0x64,
    0xEA,
    0xC1,
    0xD9,
    0x44,
    0xF1,
    0xE0,
    0x09
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseCSalts = {
    {
        {
            0xF29685969810E8E9ULL, 0x366416AF3B1136F6ULL, 0x5CC4BA74F76BFB30ULL, 0xAD3CB217E1D2F7ADULL, 
            0xAA5C72F2E210A6ACULL, 0xFE27C023A4A4D8E9ULL, 0xAC24C1333EF75948ULL, 0x739C089933A19FD1ULL, 
            0x0785B054EE27C9B8ULL, 0x3E291F2F7F2DF45DULL, 0x4278E62524264A17ULL, 0x4915E0E0763FE1ABULL, 
            0x5EBFDA56A4773850ULL, 0xF9FA760AA7B8E4D8ULL, 0xB78A2A41DC4DF5EBULL, 0xABB7563DE2B5A4FAULL, 
            0x567111D462C5B2DEULL, 0xD94A83AD01105A75ULL, 0x7D8205A895F59AB1ULL, 0x3A3DA42EAB3D4836ULL, 
            0xF286431510084047ULL, 0x469855683C4CC789ULL, 0x14C9B6306B0206E8ULL, 0x5CA5D959BEE2E0D9ULL, 
            0x27D8C5EF6CF41B61ULL, 0x30396E46E1F99129ULL, 0xE58C84F3CB07DDA9ULL, 0xCCCCD80BF3A7448EULL, 
            0x5EBB00E05D93DC2EULL, 0xE7B688D1E7A174E9ULL, 0xB3BE148ACE016ACCULL, 0xEE84224821BF303DULL
        },
        {
            0xBE2902C62B0BB63DULL, 0xBD36A7EB8FEA7FB6ULL, 0x57F469FA554CA44CULL, 0xB301FE9173BFF8C8ULL, 
            0xBD20D592DFD5F002ULL, 0x905EC99607C0F2E8ULL, 0xA95B654C617DCBB7ULL, 0x744E39AD5565C38BULL, 
            0xD02D666B42DAE599ULL, 0x05FEEC1933517FD6ULL, 0x2715E658C5BC0E58ULL, 0xFDD0E9C90A730B05ULL, 
            0x57AC21F807BE81C8ULL, 0x5EED8071CC0138E4ULL, 0x1FEC2E50F6BEE331ULL, 0x000A7B1DB9C3C657ULL, 
            0x3CCEE5740EDB8F26ULL, 0xBA6F5E01E9E7C6C9ULL, 0xBBA953B747A7DB32ULL, 0x960F2FB0C8F5574DULL, 
            0x3AC9F8BA4CCC171FULL, 0xF55BD0ED30F336F5ULL, 0xAAC87A295AD50479ULL, 0xF75A5A6274DD1A5FULL, 
            0x95A687E455ABB451ULL, 0x5EF363BD3C8DE1C7ULL, 0x2AB7E107B1D44AE5ULL, 0x2922AB2AC588F541ULL, 
            0x5FF7D0FF0D20211CULL, 0x15D49BD526AD0033ULL, 0x8378B32E3931B914ULL, 0x329D1D651C4600E6ULL
        },
        {
            0xA6EECD40C7580895ULL, 0x1E7E21D5C7AA9A92ULL, 0x7FE94794212CF1AFULL, 0x8C8551FC3484FEBAULL, 
            0xAC8D212EF6BB4665ULL, 0x62BACA5AB6D77D97ULL, 0x83BD4FB8790461A7ULL, 0x72475BDF80719669ULL, 
            0xB90838C6847126D9ULL, 0xA8C5344F7EEFB5FBULL, 0x222242A2EFDA635CULL, 0x227F6401855F88B8ULL, 
            0xDC6CB7F8CB312277ULL, 0x16AC581908062A23ULL, 0x2E879C7627C639AFULL, 0xAE6FA7D8538E0A3EULL, 
            0xF98E89623ADE2D6CULL, 0x7D3CD63CE449070DULL, 0x0A9AF85499855ABDULL, 0x3EF708DF7F6818E9ULL, 
            0xABB95123ADFCA64CULL, 0x1496DED830CECDE5ULL, 0x9A957A6296AED344ULL, 0xFAEE64FA20E6B888ULL, 
            0x376E27A0E811DF10ULL, 0x9917EFAA8796E155ULL, 0xD5029BA2E4100BC9ULL, 0xE9CC9421678F857DULL, 
            0x35ADB45DEA34CE5FULL, 0x3B98A907CD15CF96ULL, 0x51D40D57C1ED7FF8ULL, 0x8F060112DFF64DBAULL
        },
        {
            0xDD57F62E2736DF99ULL, 0x001A4B3F188749C8ULL, 0xF4708C0FE7040DBEULL, 0xC26E8FDAACA3FB1CULL, 
            0x85EFD16A70193F18ULL, 0x445E960D73D51488ULL, 0xDA6448419A3BCC79ULL, 0xCD70AC8F34D4C675ULL, 
            0x39E4021877B11BE4ULL, 0xFBA7F09B012285F1ULL, 0x5355ABB1E05BBA5DULL, 0x1A6BBF0955AB0FDEULL, 
            0x56588600DF0F6EE9ULL, 0x6E242BEEB6327079ULL, 0xE7C1272B41807726ULL, 0x48B80B9CC9002E94ULL, 
            0xFCFC21F4A87985CFULL, 0x3723D0EC0D05414CULL, 0x159A60CFAC4A3AEBULL, 0x76090CA2571E49D8ULL, 
            0xD5285AC8770FF292ULL, 0x7E5A614BBDD82954ULL, 0x08626A61063E36D5ULL, 0x34E9BF1912C102C4ULL, 
            0xB7157302A6F9E952ULL, 0x5795FD2D614482C9ULL, 0x0F73A30F146DC3D9ULL, 0xA91431325E090744ULL, 
            0xB2D9DC3407D733D3ULL, 0x83E5AD013A33F3DCULL, 0xC64CD0C6BC1D7A88ULL, 0xDAC1EE1F458EB81AULL
        },
        {
            0x26684E29C01A3C4BULL, 0xB0BA21982A5A666AULL, 0x90AE9340F52F51DBULL, 0x160A950922A1D1B3ULL, 
            0xEF3AE9B93BC01E30ULL, 0x7F325427532D1355ULL, 0xC1B48801895EE981ULL, 0x61916D4249E7E9AFULL, 
            0xFC06789D838AAABDULL, 0x6038D41C2C07A52BULL, 0x9544F50B5280EADBULL, 0x4BCBB629C366DCABULL, 
            0x3F56491D592E3F4CULL, 0x0615C1571A2B0622ULL, 0x5B89F53F14B7982FULL, 0xADB85C7D074EBBDAULL, 
            0xCA3CB206E7003A5DULL, 0xA00BB2ED13AC5013ULL, 0xA4042A2C3C5ECACFULL, 0x6EB6009BAD95A221ULL, 
            0xB34BF0F93B68BB4EULL, 0xD04F678F9287B6E9ULL, 0x3D76C862E505CDA4ULL, 0xF3902B360054FF9DULL, 
            0x720BD5503F37FED6ULL, 0xA1778C3A63943556ULL, 0xC4C59372D3813D88ULL, 0x8AC88BD76C58757CULL, 
            0x83CD8730C8271DAAULL, 0x482901116A1B0AC6ULL, 0x3ABF31FB4A051EE9ULL, 0x5A2E015DD3B07F13ULL
        },
        {
            0xF158D5382BE0A69DULL, 0x6A4ECC0205278B16ULL, 0x2683A34ED1058F13ULL, 0x138C7C7693696ED5ULL, 
            0x1D96971E24FB39A3ULL, 0x76CB229C11ACF1A6ULL, 0x7EA53C6796B1E398ULL, 0x7B04CD9E735E836AULL, 
            0xC8C7BBD85FAEB800ULL, 0xBC9E90163D9D973EULL, 0x94C73E5C27FADFFFULL, 0x71307C2D1B417AE3ULL, 
            0xDED98562EC7A2E7DULL, 0x9BE8019E6B83A1A0ULL, 0xA720FDBB2DEC02BAULL, 0xBC8637530D16C003ULL, 
            0xB514B7069552A598ULL, 0xAD8C9DB3920CE729ULL, 0x317D52482562A6D7ULL, 0xAE8556AB3B1AE364ULL, 
            0x955BF57FCDD9824CULL, 0x9E4334D3407C94DFULL, 0x953316141328DD9EULL, 0xDB4F42399767796FULL, 
            0x9B5DB1DD6E480431ULL, 0x5584F9BE287A0482ULL, 0xA00827A42A74ECCCULL, 0x43A916FC6AF7ECD6ULL, 
            0x70870A3A9E6D1F33ULL, 0x4FE16A29BC27A8BCULL, 0xBC2D6D65216AA317ULL, 0x149A5FF1CEF60D14ULL
        }
    },
    {
        {
            0xF28571731736A3DCULL, 0xB44B1C083AB9ED46ULL, 0x63EE25FAE9BF46D9ULL, 0x45538CDD0E03244DULL, 
            0xBF47F9AC1B56126DULL, 0xC37942187998FAC0ULL, 0x038368D77434049DULL, 0xE8922466B5E0FBBAULL, 
            0x84816774AF0E52C3ULL, 0x0EC8E56150F70600ULL, 0x89A4C5D8277C1AC1ULL, 0xD06218007E6AC1D5ULL, 
            0x2D98D91E95855E83ULL, 0xDE3EFC57B70895C6ULL, 0x2D0FC7EA6F5DBA8EULL, 0x6CF032E1987C34C9ULL, 
            0x640544A3EB39AD4DULL, 0xE1D99C7B68B73895ULL, 0x6BDE4D71244B95C5ULL, 0x92EA944899A66DAEULL, 
            0xDD7F3C45647ECF07ULL, 0x8FF211B25F302ADFULL, 0x299AEAA2A036E980ULL, 0xE0B450F655A74935ULL, 
            0xA583DD096C8DC0CAULL, 0xB1C9E0DCAF750720ULL, 0x1E19B075D4B50CBDULL, 0x3840D68CDABBBB1DULL, 
            0xE0BD5851A8D204BEULL, 0x878A75793C1AA66CULL, 0xCAE6646926075ADCULL, 0x898101D0B6222563ULL
        },
        {
            0x95A195AFDDFE0C44ULL, 0x15F4AAEB407870B7ULL, 0xBAD40C6EDF37C75BULL, 0x265A35EBCAF8DA26ULL, 
            0x227CF5060337A3BAULL, 0x1ECC7D6E69A9E86DULL, 0x2A87933EE9BFE8DAULL, 0x8E15B859F97FB9DCULL, 
            0xE257954E629D9C7AULL, 0x74FC9FC5282B9465ULL, 0x659A69FB4B3EAF6AULL, 0x9F2596D6245D4A38ULL, 
            0x8694B7DDE83848FBULL, 0xED989A9904860745ULL, 0xB19574A48916338BULL, 0x33F660C0B190FDCEULL, 
            0x7360D8DC843A7339ULL, 0x4812FFE5A9182A56ULL, 0x72211639CA374745ULL, 0xBCB286CBC638E421ULL, 
            0x975FBA5FE22B7840ULL, 0x2125C254BC19231BULL, 0xDBD94457D236278AULL, 0x67AAB3A9AFD536F3ULL, 
            0x9E49A2845DC7AEFCULL, 0xF5DABDF927D7F2AAULL, 0xC31A525C1E6DC48CULL, 0xD7480B67CA4CF7B2ULL, 
            0xC2D30950BCCA8126ULL, 0x7DB8F277113CCA4EULL, 0x9F9EF02E9A3488F9ULL, 0xF8C62F4EE3179FDBULL
        },
        {
            0x32CAF08406B1AF8EULL, 0x419FC76E9586345FULL, 0xEA3A93B00614D741ULL, 0x6CE71F4D8FE4C35BULL, 
            0x97E5BED24204F058ULL, 0x11A3D97DCF5AABDBULL, 0x40C8A30A69E2DDC1ULL, 0xC8510D600B0103EAULL, 
            0xFE56AC0305C5C5A1ULL, 0x67FB2659C9A2BF41ULL, 0xBE543D210D1ABAF8ULL, 0x0F57FEBC5200CA86ULL, 
            0xEEB8D153EF06D6A5ULL, 0x2CA5CA6590B34A50ULL, 0x422A49C1A757EB6AULL, 0x2555A971DDD4E024ULL, 
            0x34E1A39C7DE363F3ULL, 0x8C181909267C3C94ULL, 0x1478E9F9A16DC79DULL, 0xE55E1F70462020F6ULL, 
            0x9C45ACF9E0ABCA0FULL, 0x176AEE7A276E81FDULL, 0xCBB1E7143EC78B50ULL, 0x3D996E6E566445E4ULL, 
            0xA68626C60523E282ULL, 0x664F221E7AFFDAF3ULL, 0x0E36ABCA679C29D5ULL, 0x0040D09FDDB17DA5ULL, 
            0xD62DC1B5A2275A0AULL, 0xBDA979D68EA6025CULL, 0xE96FC9185AAC9B65ULL, 0x1342644DFF880736ULL
        },
        {
            0x4752A00397959B66ULL, 0x1AADDCE06B6F480BULL, 0xB26573810DF65392ULL, 0xB2C8C9D39E5A2F85ULL, 
            0x8F98EB0C82144214ULL, 0x6D983C6FC08CDFE4ULL, 0x1F928DE50217D213ULL, 0x83D4CD96EB47A6A4ULL, 
            0x6EB8F40C48802480ULL, 0xA73BED32B846DC2FULL, 0x4B95DCD31E18E42FULL, 0x27B321162D293F4DULL, 
            0xDA6C2E28C691908BULL, 0x795F2633E826F451ULL, 0x9D07F8D06E8CEB96ULL, 0x6E014AA5A5EE40FBULL, 
            0xD3353B36FF3A0250ULL, 0x906948F163F0473EULL, 0xDEC426A2AF7F1F1FULL, 0xA5668A7BAE1682BBULL, 
            0x190098E1926F7134ULL, 0x214E55490C73707FULL, 0x84832FB67B55AD19ULL, 0x67C74C7E409C65C4ULL, 
            0x7B5E32530E9F991CULL, 0x3822D7FC611B588DULL, 0xE5D504108C381E4DULL, 0xB4A9219757F8F6B8ULL, 
            0xA6AC821C37C1F8CEULL, 0xE04BD1B58259361BULL, 0xEFA996D355F7B0B4ULL, 0x50F714ED602D0FB0ULL
        },
        {
            0x1CA860A2938CF6BAULL, 0xD697BAECC4A1118EULL, 0x1BCB79E8649D3051ULL, 0xF64D407AC02D6182ULL, 
            0xE7769147EE31D3B4ULL, 0x4AECE59F942BBF57ULL, 0x2C9F87DF3E9BA65FULL, 0x0597AF21E56E960CULL, 
            0xED692A8D356529B9ULL, 0xBC3031DD21965126ULL, 0x551586247CA31882ULL, 0xE9CD0BECEFFAD08FULL, 
            0x6979344B52E84805ULL, 0xD62E43FBEAAD6F74ULL, 0x37572875800A02B5ULL, 0x1F113AD3192AC8CCULL, 
            0x96E606DB80952A42ULL, 0x954A68F844EF26EDULL, 0xC96E99CFEC64F302ULL, 0x299F5C2B34CEB233ULL, 
            0xA3A6F3D129E4D594ULL, 0xF646DFF6CBA45D79ULL, 0x2DB1B0E13F816E8FULL, 0x19BCD41C4C59D112ULL, 
            0xFB32AD5A1EC423EBULL, 0xE471BE58CA4895DCULL, 0x756E07B9035D87A7ULL, 0xD6CAFB628BFAAB85ULL, 
            0xA7F060B0808120D3ULL, 0x807F279861C97A40ULL, 0x4B0C682DFBFFD11EULL, 0xFB77745BAE50F161ULL
        },
        {
            0x4ACEDBC61C160967ULL, 0xB045D6AFC299585DULL, 0x8721E79F88FF9550ULL, 0x49DCF02F254EB50DULL, 
            0x00ADD81B83B439FAULL, 0x3598927B13E79A8EULL, 0x632747682070FA3BULL, 0x5BCFAD999FCBF542ULL, 
            0xD3B6E5E27D236286ULL, 0xE23494A9B154F622ULL, 0xE5E43726FB7EC3F2ULL, 0xA2F5912BC3118ED4ULL, 
            0x6E3D4B7AEA3F1C3CULL, 0x2AD913C3B00DF48CULL, 0x2EA64B7D4EB1181EULL, 0x60D96ED56A8DBDFEULL, 
            0xE364C00084D20C79ULL, 0x1FFB535E1A73E524ULL, 0x0DB3BC9F0AED2366ULL, 0x2A203C61AA7B4CE0ULL, 
            0x57B839BBA1A7AD4DULL, 0x89149B130504D08DULL, 0xD707EDB0C777AA45ULL, 0xC4DB577E17E432B3ULL, 
            0x8DA337756C8037A7ULL, 0xE7C96FCC9E8A59BFULL, 0x3017AC153BBEA534ULL, 0xD5ED476CDB3FBACBULL, 
            0xA4EE7391E60CEFBEULL, 0x978FF0101E849E8DULL, 0x4B20D6C0015B4BF8ULL, 0x677D9A9FC619C89CULL
        }
    },
    {
        {
            0xE9FA8299DE59E1F6ULL, 0x59009DA534A3078FULL, 0x156D810F57B8892AULL, 0x13FE7B7DFC3ADB40ULL, 
            0xBC194AF1EEEDAC9DULL, 0xE11A0BF7CB20B02FULL, 0x7D048B903E9B48B5ULL, 0xAAFB1CF70386EB45ULL, 
            0x4B3BBBF3F27617B6ULL, 0x042FCC5116643102ULL, 0xFF67FCD8C1C13767ULL, 0xB3E5B7D017E967CAULL, 
            0x51F43FDD55FC000BULL, 0x49BAF798134716C6ULL, 0xC2F4B49F998B4688ULL, 0xBDBD394B2BC0FBDFULL, 
            0xD41E12E724127BE2ULL, 0xEFEAA74802331484ULL, 0x10204809E9FD0A4BULL, 0x727ED7E4132537AAULL, 
            0xCA44F2934C9AD67CULL, 0x013C8B181E865115ULL, 0x434C7744C2FD21DAULL, 0x6DD01F4CB1D514ABULL, 
            0x298FB420BA5884DEULL, 0x1692E70585D36C8DULL, 0xD6FE6A77B59034E2ULL, 0xC9F68A953B442CFDULL, 
            0x821DAB481C6E34F7ULL, 0x7BA38591DA985EFCULL, 0xD351376713C0C792ULL, 0x0462FEC2CC0D28B8ULL
        },
        {
            0xD0D8DF706E8DB34BULL, 0xF83D492B2DCDA6D1ULL, 0xF22ACCE8A5DFFF4AULL, 0x26F868705EB3EE83ULL, 
            0x796A7A3D09950915ULL, 0x11B02676DB01B3EFULL, 0xDDC3196BE8B61FCBULL, 0xE6BCD41E2382D13FULL, 
            0x2BD92946069E6065ULL, 0x45F35ABB686A9C33ULL, 0x30E1DA60D418436DULL, 0x437BD90A82FA01E1ULL, 
            0x55067E6C70BC3A55ULL, 0xF1A5625FA2258B13ULL, 0xA34A2142A7EDD62FULL, 0xF48F28C2CB17A00DULL, 
            0xFCFAB2E6DB9190D2ULL, 0xDAE2252983E99639ULL, 0xCE75333DB0F66732ULL, 0x6F9A8141475405F2ULL, 
            0x937E22E81061374EULL, 0xC3C50831680C7C30ULL, 0x2997CEAC5671167BULL, 0xCF87B122C9CC520AULL, 
            0x587F891917CE505FULL, 0x1357C7544A1E0B10ULL, 0x916513CE2F28C5DBULL, 0x0BCA536A0574611DULL, 
            0x0C257B3D1391BE6CULL, 0x40A3B90072D4BF62ULL, 0xAF73914FFA458E1EULL, 0x46EE9BEDA4EF22EAULL
        },
        {
            0x8839BD1FB3E7255CULL, 0x46A6EAFBF76BACB0ULL, 0x80FFD2CE2EEB403AULL, 0xFFA2D2F78DCB0F80ULL, 
            0x2F8530F679D35E7CULL, 0x367B92B629736002ULL, 0xD902924B8B4C4EFBULL, 0x8F3D45AD558A74B4ULL, 
            0x81A6DC2C2A82088BULL, 0x70C2DAF73550E508ULL, 0xCA9D1604766A1E59ULL, 0x50FE6BF588B36742ULL, 
            0xACCEA6CA7F7D78C1ULL, 0xB5F9B1445B7C4B5BULL, 0xF3E4AD009D78DA0DULL, 0x81994AFD29FEA939ULL, 
            0xBDCC1A2BBAE5CA1BULL, 0xC477C19992157292ULL, 0xFE95FF87FD364710ULL, 0xE083CE33B17C91A8ULL, 
            0xE58CFF116061C710ULL, 0xC30C7B5197CD8C50ULL, 0x574054769691324CULL, 0x1E39B8A44E026D0BULL, 
            0xBDDF604FEC968618ULL, 0x778510CCCAE27358ULL, 0x22DA2DB027CDF9D4ULL, 0x283B22E415C85F97ULL, 
            0x52C9A35373B821C1ULL, 0x3D627392FC831BDEULL, 0x835856EF2EF1DBDDULL, 0x4D541AF3D250CF56ULL
        },
        {
            0x42DC3225DC50A8A0ULL, 0x3A4DA9A6A79EDEDAULL, 0x28F5A359C462692EULL, 0x56904D901017EB4AULL, 
            0xF52713D82475A436ULL, 0x2FE4E953367E25B9ULL, 0x2965ECFA0EB2112BULL, 0x1D2A92AD896FF3DEULL, 
            0xB54428358499F9AEULL, 0x9ECB09F44CDF4685ULL, 0x9783ACE81FA458E1ULL, 0xED5FA4BB928F0E9BULL, 
            0x0DDE01C92A4AB68CULL, 0x33AB11AC89C2D410ULL, 0x2169BA96A593E913ULL, 0x71431D4B9C26AAA6ULL, 
            0x6FFA0C64F32349C5ULL, 0x165016AF5182598AULL, 0xF8BFE7EB828ECCEBULL, 0x6C527D02010A3045ULL, 
            0x257E147BFF3BB9C1ULL, 0x6F628C87D66F23F2ULL, 0xC8FD5FEC4B0CCD82ULL, 0xDCCD9BB6477CA590ULL, 
            0x268A7E471022848CULL, 0x480A8E03B14112E3ULL, 0xC11FB7DCD5AE3584ULL, 0x3C5E6F649F257C98ULL, 
            0x00CD8C713E410B3AULL, 0x8BD57CA38FBCFB7AULL, 0xF548B99C072DEAE0ULL, 0xD01546962A460B42ULL
        },
        {
            0xE129B6D24B72D48BULL, 0x4C2954869AD9E011ULL, 0x1BC2E6CFBE5CAB57ULL, 0x6E53EFD33D358D1AULL, 
            0x7CD71D60EF989B85ULL, 0x3AE082A3B10F9DF4ULL, 0xF43189D178B66D95ULL, 0xC58379A085484D9CULL, 
            0x74EC139B530F15ECULL, 0x1AB76314A82B02F3ULL, 0x2C1C5AA0755B4C80ULL, 0x149C46B2F9DF9A3DULL, 
            0xCF4C4E0B973AED63ULL, 0x94445D7AA4712E48ULL, 0x6DFF297EEDB660CBULL, 0xB227FD72511886C9ULL, 
            0x190F34A4D3454785ULL, 0xC838BD5409669AE0ULL, 0x807474C526E4D709ULL, 0xBA54B1C9A02AC137ULL, 
            0x96A1D3EB4BB0AC58ULL, 0x0EBF2CA23C50D533ULL, 0x48C169A4AFC3143BULL, 0xFFD91951BB8BC947ULL, 
            0x654A1326AB7929BAULL, 0xF6E37C3187908F6DULL, 0x37131F7C093DC4A3ULL, 0xD95B3B813965DA88ULL, 
            0xECCB5A3E29B9847CULL, 0x9D355C09A69FD773ULL, 0x5994163F0A6F9BFDULL, 0x403BBC8684D7CC1EULL
        },
        {
            0xF3C9C1467C55F40BULL, 0x0733358F2BA9A138ULL, 0x7E36EB3947FAD046ULL, 0x0F48CCA015D80135ULL, 
            0xDD9D6D020AD8F2CAULL, 0xBD4546A4EDFD312EULL, 0x0B93A3CFCEC8CE5DULL, 0x99F24769AACDE458ULL, 
            0xFDBB488412261DAAULL, 0x1A306A34EE4BFC59ULL, 0x9516B31A0244F5DDULL, 0x78A32FB4E846E5F2ULL, 
            0x9428C7C2D1471FF3ULL, 0xBBBD8A56A372B517ULL, 0x775CA1C0D196EAC0ULL, 0xE16625AD91E9BA4DULL, 
            0xE2991BEC1CB2AD71ULL, 0x59456CE1B8A94C73ULL, 0x0F0EC34049133300ULL, 0xA8491AFA3B806D9BULL, 
            0x327928B699B2678EULL, 0x3D8506128718DE27ULL, 0x21D362FC88EB530DULL, 0x6684753AF1E75E13ULL, 
            0xE240A6A6CBA57C5DULL, 0xB02CBBF7EFCAA101ULL, 0x2C000465176805C5ULL, 0xB368FF61B188220AULL, 
            0x522BC8F91AB325C4ULL, 0xE2623FC61248BE32ULL, 0xA9CD8E619078CA27ULL, 0x623FCC3F90209F73ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseCConstants = {
    0x958506BEAACDC8C7ULL,
    0xAFC1C14140EF7236ULL,
    0xFCE525BE09DEC222ULL,
    0x958506BEAACDC8C7ULL,
    0xAFC1C14140EF7236ULL,
    0xFCE525BE09DEC222ULL,
    0x9C09A6B1CC6ECABCULL,
    0x94466EC95A228AA9ULL,
    0xBD,
    0x6F,
    0x69,
    0xFE,
    0x74,
    0x1F,
    0x40,
    0x8C
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseDSalts = {
    {
        {
            0x06D167E718C89C83ULL, 0x8B7DC422296C0CDFULL, 0x6204DBE1A4FD1C58ULL, 0x1E709B6A7CED6652ULL, 
            0xF7458A6673A101E2ULL, 0xC2EC73E4BF14AD81ULL, 0x8E3BA116E325216DULL, 0x3012BC33826D5EB0ULL, 
            0x96DDEE0688447757ULL, 0xE96AEAE38E12FA5EULL, 0x322E2102E074362CULL, 0xB122F49DEB7CF17BULL, 
            0xCC40ECC48BDBDAC5ULL, 0xB335E1D522035FF8ULL, 0xF2F812B7470B6FFBULL, 0xD6B704F6D1EBD11CULL, 
            0x2FC9100AFF6C5EB7ULL, 0x5D3BB8F5E9DFDF70ULL, 0x72C91706196F8237ULL, 0x4D8A3F2B7910A01FULL, 
            0x3E285D99AF5342C3ULL, 0x71DE9A6BF356E95FULL, 0x0725A90A6B95B985ULL, 0x123B029C2D913815ULL, 
            0x5A8BD2DA99E3FA97ULL, 0x3BA95BDCA3840D01ULL, 0x45D96BC994E215A1ULL, 0xB426F4421CD73B31ULL, 
            0x303B439675E28FBAULL, 0xE55910E62A57E9D0ULL, 0xE0629C2FD9747F3FULL, 0x4CA79EA54CC9FFCBULL
        },
        {
            0x48A504914BF713B2ULL, 0xF13551DCB0CD9E68ULL, 0xADD4E67EF8F5C0F9ULL, 0x0CBDCD9E1BEF2F99ULL, 
            0x95125E26900EA8B8ULL, 0x54064B52168EC279ULL, 0x80405548E3808972ULL, 0x50ED4329C5AF14F8ULL, 
            0xF04DD7E9C14BFBB4ULL, 0xCFDCAE9178390407ULL, 0x3DD1E2C2969A924EULL, 0xBB5AC70AEA9A33EEULL, 
            0x1F81C07547511A88ULL, 0xCD143B1148028FF8ULL, 0xCFB9134E3C841C52ULL, 0x7738ABCBA481B895ULL, 
            0x3F613E22AD2CB308ULL, 0x38905B162EB171EAULL, 0x05320561C7D42464ULL, 0x7D4FC0070A8E7EF7ULL, 
            0xA2329FFC3FE3A10DULL, 0x350B6B4F785BFE9EULL, 0x6F720A9EB68E011AULL, 0x6B8F9751DB1AEF7FULL, 
            0xE336C29AE80AA008ULL, 0x6BAA90E7D553E593ULL, 0x707408042CC1DDB1ULL, 0xCABC8DB68116AD39ULL, 
            0x78F755020008241AULL, 0x8E1650FC75DBB956ULL, 0xECE719CCF4B671D6ULL, 0xDDDF935813859988ULL
        },
        {
            0xA1052C1182E4445DULL, 0x9CD70E40F006A271ULL, 0xD76944905F5FCECAULL, 0xEFA3C1FAE94F87ABULL, 
            0x0ACB44B8DCA18F67ULL, 0x682C5467FA54B740ULL, 0xCDF0F5ED92205536ULL, 0x4A84E4A0EDB23AC6ULL, 
            0xC4F35F694769997AULL, 0xABC02DCE267BED50ULL, 0x2DF230270902857DULL, 0x411B97ED639A1B04ULL, 
            0xDD9FB7354EF46D37ULL, 0x9053E97675A92B44ULL, 0xB1B68044D2604105ULL, 0xA89CDCA4F03EF13FULL, 
            0x7403A56BE3AF23D2ULL, 0x2DC5B03D5B99DA39ULL, 0x55B5A0A7265AC8AFULL, 0x5E9353FB50B00B52ULL, 
            0x9662C470EBC2E12BULL, 0x5307728E607F7C79ULL, 0x73F48C29332CD3E7ULL, 0x10E18D0679E7EBDCULL, 
            0x20E99A873194FBD0ULL, 0x807BB483BCAAB84AULL, 0x8A0AB4AFE683E232ULL, 0x1ED1BC74CD42FC9BULL, 
            0x39918633475F0234ULL, 0xB290156805D5D9B0ULL, 0xFD2D767DDB3B12E4ULL, 0x4AE2B46AE742D2EAULL
        },
        {
            0x5E393E196325FCDEULL, 0xA6FCCCEA04132396ULL, 0xE1ADC53606794257ULL, 0x0F2C41A0319C7A7DULL, 
            0x70EA88E146660A28ULL, 0x5D2836A68C3D35E7ULL, 0xC68B6EB2385319DFULL, 0xC972F7FE3DDA2724ULL, 
            0x018734D327D2E991ULL, 0x04FA1F65CDBAD4C1ULL, 0xD87C5E7C0D1A09C9ULL, 0xF35F2BC573A90BDFULL, 
            0x5C0173252BAEA4EDULL, 0xE96859B6B580FA80ULL, 0xC9B8DBEC410D02CDULL, 0x4D274CC7E2E8DD53ULL, 
            0x796D9AE81A1DE455ULL, 0x4259F62A11F77D75ULL, 0x4541F943622E3931ULL, 0xCF0C96F6E7E7EBBFULL, 
            0xA4C2BDE7ACA1EE85ULL, 0xECDB3F947D1F1841ULL, 0x26795C2E087BB47BULL, 0x10B2DFA257E0899EULL, 
            0x5210599D85C96ECBULL, 0x78F89A7C9C4DA4D5ULL, 0x13424B0EDBC2ADD3ULL, 0xC20BE02D95733862ULL, 
            0xDB0162FC61654782ULL, 0xB44C1394ABD02183ULL, 0xA16655459E03DBA3ULL, 0x68C09ED0F034ECA3ULL
        },
        {
            0x5238390ACBF25702ULL, 0xB439BA35676565E6ULL, 0xA21FAB6A0AAF078DULL, 0x74617000E21B74AFULL, 
            0x1BA7211365D2FE7CULL, 0xD1D38552FD17EEADULL, 0x5FA3099D7F7093A6ULL, 0xB25C01409AAA4CFCULL, 
            0x0DC49896BA47D58AULL, 0xE3BDF0B27AE0F77AULL, 0xF020133CC19AC524ULL, 0x994E596D19F293B9ULL, 
            0x461F15026D4E4AA9ULL, 0x791983CA83162046ULL, 0x3EBBD739AC9CD59DULL, 0x1701FACA189CB96BULL, 
            0x719BFB1B78BCDA15ULL, 0xE4158A1353C468D8ULL, 0x79F7613E622ED85EULL, 0xFD1932EC3D848F16ULL, 
            0xD4D27208F1CFB428ULL, 0x3EE322BCE0A15772ULL, 0x7A292CD837284FF0ULL, 0x73F197C1944129FAULL, 
            0x66F987821154DC86ULL, 0x0E445E5D90EAD249ULL, 0x5698340AAF94D6EAULL, 0x94C0A876893AE161ULL, 
            0xDA04A0DA19C16AC3ULL, 0x997205055EC4C7CAULL, 0x42E7DF9154F008EDULL, 0xE008A05989461384ULL
        },
        {
            0xB7E673E9BB90C8FBULL, 0x322393183E6CF080ULL, 0x5321904557238A9BULL, 0x3340191213772EFDULL, 
            0xCCD3CC01ADF426CDULL, 0xB1531120BE38C4B8ULL, 0x4E64A085C667CA8FULL, 0xBBC81250F0B6FDDCULL, 
            0xADDD40B6641993B6ULL, 0xC00CCDD6CD61F544ULL, 0xB2F078E14AFC70F4ULL, 0xC2E5BB9107E4B0D1ULL, 
            0xF15B1C95F66014B9ULL, 0xE66EE3030920B508ULL, 0xCECCAE3C7AF1FAA0ULL, 0xA088656A16EC0EF2ULL, 
            0xC926B3EE2808F32AULL, 0x7AE9075A70A7DC77ULL, 0xE58061AC856943F5ULL, 0xFE7C622690F4548CULL, 
            0x263A5C7D7F4318AFULL, 0xFC5575F7B12B3A00ULL, 0x7A2BDEBE16A51287ULL, 0xE5935360B0AE3C98ULL, 
            0xA4FF9231F986A97EULL, 0x170AAAE85914DA0EULL, 0x3D60397F5782C8F6ULL, 0xA250A27FF010F025ULL, 
            0x151E1C74E226C95FULL, 0xF9104D842F812433ULL, 0x4AB3096D06B6563DULL, 0xB9A710AE6832BFD2ULL
        }
    },
    {
        {
            0x0A99C7811B349FF4ULL, 0xF24B62D8A2D7A0C5ULL, 0xAFBEFB95D0031B99ULL, 0x0BF5100A3757981BULL, 
            0x57EF55C65B8C656EULL, 0x624450FA2780942CULL, 0xF0F21A728DB7D7E0ULL, 0xF117CCF29B86718FULL, 
            0x907F04C043072D3EULL, 0xB30E4189D22550D7ULL, 0x911B687B637EB261ULL, 0x0AC9790D1722CB0FULL, 
            0xAF8AA08D22BA02CBULL, 0x9145BA4E488FAB60ULL, 0xFF9467ED9F061988ULL, 0x2962D0BFD0984E33ULL, 
            0x8F9FABEBDF4500B2ULL, 0x6E14C8D6ACD9233AULL, 0xD73D252BC8D30B81ULL, 0x899DE09D63A6B6D5ULL, 
            0xE922E93A4747912FULL, 0xEEAB48A0A594B4A9ULL, 0xD6F3E2AD1E26A4B8ULL, 0xF6B2D32373B1B9A1ULL, 
            0x3C65E4169721034AULL, 0xBF78DDBBF415C821ULL, 0x4044E6C64041F310ULL, 0x5700625B891799E0ULL, 
            0xF421ED3B69D6C5D7ULL, 0xB2599BFD1B83A127ULL, 0x7EAD37C07C3243D6ULL, 0x859CD84592D57FADULL
        },
        {
            0xC2B0D758CFDBB098ULL, 0xE47199D7C429F6A4ULL, 0x7A2D6CFB727609DBULL, 0xA4BC2DE172E528F5ULL, 
            0x70D67C14AEFCE5C1ULL, 0x24B07AD26CC68563ULL, 0x75B688AEA90538BEULL, 0xBA2FC73BA73A7146ULL, 
            0x11EF98E6DCF2802EULL, 0x463364E2B6BC13D1ULL, 0x4F2F31D7E144B42BULL, 0x59BE06FE6786EC18ULL, 
            0xD2B365712BC705CDULL, 0x4C92B382A8B1E0CDULL, 0x45CEF0380C8D8653ULL, 0x45BED64DF682CE2DULL, 
            0x45A4272D02977BAEULL, 0x004FB17F488FB980ULL, 0x231CD32EAAB1BAAAULL, 0xEDBBCA5F45671654ULL, 
            0x168ACAE4106AEFA5ULL, 0x350419C6D0A3EACCULL, 0xDD5E2AFFEC0EE99DULL, 0x1210549810EDD8BBULL, 
            0xC9510C5EC542CB08ULL, 0x12FC6514E1FA0CBCULL, 0xAFA3E53B81FB16CEULL, 0x3097935D66AE9CC6ULL, 
            0x8562349106C80951ULL, 0x605F78169C59AADDULL, 0x0414F2F6E9CAC89EULL, 0x4651CA472D3234DEULL
        },
        {
            0x9738A13276A98DF7ULL, 0x0114CCCAB4EE2BB0ULL, 0x209E86D1CC974B41ULL, 0x71ABA26B568FCC1AULL, 
            0xAD837141B6CE7032ULL, 0x3D022DABD91023B2ULL, 0x2890C858F8F59DB9ULL, 0x451E0EDE15C792B6ULL, 
            0x930C31F06F9D9C05ULL, 0xF855DDDFC6079A02ULL, 0x851DC2D71C532B56ULL, 0x0580A21AA3AF52A4ULL, 
            0xE9C791A52849C244ULL, 0x66E9CD8028C3FE5BULL, 0x333B3D07346D2A66ULL, 0x00E512E4CDE70CBEULL, 
            0x268AFB7D6728F4D3ULL, 0xE8465AFC4A787342ULL, 0x77E403D1663A1B9DULL, 0x6FBC3DC4A24C60F1ULL, 
            0xA93A5188ACC55D16ULL, 0x7A02659A675C2B78ULL, 0x03DDBF6F6F9B585BULL, 0xFD66F3877FCB11CBULL, 
            0x2FD43097AD6F2616ULL, 0x69DF88AF6478895BULL, 0x99D70ED89D8D8369ULL, 0xBF4F5DBF30805538ULL, 
            0x3221DB71D223B38DULL, 0x5CE885BECE6A92BDULL, 0x6FD1E6390643ADACULL, 0xD8EE5B987B2B662DULL
        },
        {
            0xB6CD2AC579253231ULL, 0xC24B0E857BBBE6B7ULL, 0xE2A5A67CDFA19686ULL, 0x97707AB37512C243ULL, 
            0x66940C7DA919C71DULL, 0x288198A2BD86139EULL, 0xB1499836C6327206ULL, 0xA864540A1554A990ULL, 
            0x32B70DF2D9D6DC0AULL, 0xEA557744D2C5E9B4ULL, 0xF4565C2270E5DF3FULL, 0x97EB68B74EFDB0C8ULL, 
            0xDEBA9217D25388B2ULL, 0xA2F4FE544C5D4F1BULL, 0xAD83CB01637497CCULL, 0xBE6E8B4EBE8A9AAFULL, 
            0x334994F8AB166CB7ULL, 0xA067D129CC943FE5ULL, 0x2E7E3E51C0328BC5ULL, 0xC5C05A86BB895B50ULL, 
            0xB007498FA17C4DEAULL, 0x49A8E66DA846BAA9ULL, 0x270F2120ED7BFDADULL, 0x2AA8DE6D140DDB04ULL, 
            0xABF6A986FA8C93F3ULL, 0x47C194B429FD200FULL, 0x9DF5A592FA9BE62EULL, 0x4A18356723EFB9D8ULL, 
            0xB37A20BF0A825A9DULL, 0x4B98F7FBB72CEDD8ULL, 0xF90735DA1ABBC52DULL, 0x998E42352382655DULL
        },
        {
            0x44C540F195C452CCULL, 0x9CC028D4060A9107ULL, 0xBE578584E9FC991DULL, 0x388528AE8E26F7A5ULL, 
            0x9D0BBBC84B650395ULL, 0x919A0B29162C0F67ULL, 0xCF13EE98CDC9F161ULL, 0xB5983B1B2650D177ULL, 
            0xCFFCD51F79229ABBULL, 0xA1B821D7EE16246DULL, 0x3ECDCA09CC3ABB76ULL, 0xA323834468D9E95EULL, 
            0x74FDC651C777476FULL, 0xAE0D98745FBE2C15ULL, 0xC3A25DDE79891069ULL, 0x579F5ABF5AE0708CULL, 
            0x40CC4525A42C18FBULL, 0xB307370118D90976ULL, 0x8B92543FAA7DCA95ULL, 0x1CC1EE5F5D52618DULL, 
            0x72D8482A5447D7F6ULL, 0x913F836671EB01ECULL, 0x04E6873514BD0DAAULL, 0xDF14C484B9C04BC1ULL, 
            0xB22621F43DD77C36ULL, 0xEFCEC3B491D1212EULL, 0xCF2CE10CD55341A6ULL, 0xEF68810577D6854FULL, 
            0xA7E37F457A15FD92ULL, 0x02643189C9FA77E5ULL, 0x61EDDF1454155AAEULL, 0x9B7B926756D7CCB8ULL
        },
        {
            0x5E6AECFD0C892D0BULL, 0xC95A5D087A1E2AC5ULL, 0x49E4E25339E16769ULL, 0xD90F04EC6B1AFF40ULL, 
            0x28704A35B5D6D53AULL, 0x104EAAF4CBD4DA86ULL, 0x2A92D2E20508BF83ULL, 0x36A82119AB461DEFULL, 
            0xAC5A2084242BA98BULL, 0xD9743ABFD8E97691ULL, 0x9B25F35C02D99CD4ULL, 0x4618D9941F43CF29ULL, 
            0x13522D2EF3C296B4ULL, 0x624C6E1E7413A178ULL, 0x2C4A85CA4B78FF5AULL, 0xC67BA0FB58DC7341ULL, 
            0xFAC2BF2A19D494C5ULL, 0x97660A93810AD932ULL, 0xE95F8ACB0943C352ULL, 0x8DDB5E61F8BFA516ULL, 
            0x979D178CAE0C1E87ULL, 0xD3B04BEEF250BDADULL, 0x094FAB6616F8F9D3ULL, 0xBE37BCFF50644711ULL, 
            0x62B5388A10BD3281ULL, 0x2E5B6BDF0CD9E646ULL, 0x87D09A95F118314DULL, 0x2A883E2D784624BCULL, 
            0xE215ED1B1A8D20ADULL, 0x4557D89E9FAE1BE0ULL, 0xBB5ADBF7DCBAB92FULL, 0xD95CC0C2F4670FB1ULL
        }
    },
    {
        {
            0xD4971FAD39781DC5ULL, 0xF4D097C8DE375C1CULL, 0xB07FD691DA0D7B1FULL, 0x3B377480AB92FBCAULL, 
            0x026A0550AC7D8566ULL, 0xD97D5DEF0F16CFDAULL, 0x8338636C42CA8410ULL, 0xD54C1E2E997886A7ULL, 
            0x9D47E79A923B976CULL, 0x5A2362D81A9C9B57ULL, 0x6A87399D117978C3ULL, 0x014FDCB85621CEC0ULL, 
            0xED1CC8C421420639ULL, 0x19D3A3116CDAE9B5ULL, 0x5A1440D5D385DC91ULL, 0x46ED601831DC8B55ULL, 
            0x67573A4D93F1DD09ULL, 0xC4202447FB31193AULL, 0x24FD6011E8B5F835ULL, 0xB59F5259F7B2B0E9ULL, 
            0x48BF18173B150867ULL, 0x3B752DCB528B0A2EULL, 0x5F9FC9144C047AF6ULL, 0x0B014B7370CB3C15ULL, 
            0x7998E23244E5B7FAULL, 0x2B86AD3E69D55626ULL, 0x5128159DE25523A0ULL, 0xCE364E60DD31FF11ULL, 
            0xE6DA7685FFA19739ULL, 0x928166A1BBD0076AULL, 0x4B2AFD2D3356F63DULL, 0x8DA04C4132EF9C2CULL
        },
        {
            0x5E8B06294827969FULL, 0x79C85CB618C723CEULL, 0x8110B9304B78DBC3ULL, 0x61FE93783CA160DBULL, 
            0xD8CC1C12817AE176ULL, 0xA9BADA392F9D2305ULL, 0x98A25DEA9F714C54ULL, 0xF822ADECA56580CFULL, 
            0x800E4C5E9659B3E1ULL, 0x4C6074BAC4D6E582ULL, 0x5B6C5A0B1E7CC05EULL, 0xD0156D5FAD58AA10ULL, 
            0xF57B6F64980AE685ULL, 0x5B3A1C7F338171ECULL, 0xFACCA3CBB71AE67FULL, 0x5072DAE2F6602901ULL, 
            0xF991C089C1259528ULL, 0x97C86D3ECF3315AFULL, 0x369F49F0FEF36B3BULL, 0x18E9ACFADC7089EDULL, 
            0xA13EB3CBB67F1C5CULL, 0x30072B93E367DB9CULL, 0x5F2A7A41B5147665ULL, 0x1FE78A269B79F435ULL, 
            0x0D3A9E2A476D344EULL, 0x88D6F57FB8967778ULL, 0x106D262899A747E3ULL, 0x1849CB3C1284611DULL, 
            0xB707DEEDB4964D37ULL, 0xF2542A8D2C8BBE19ULL, 0x76851AE1E8F00FECULL, 0xBFA403243495A789ULL
        },
        {
            0xD349A8A1219EEFB0ULL, 0x505765C14A6D1098ULL, 0xB36D45E2D6710011ULL, 0xD52589584B7D9C93ULL, 
            0x9F5C0AE021418348ULL, 0x0D0C1CC5A56E6643ULL, 0xF73E2A5829F3D457ULL, 0x0057276F00E7243CULL, 
            0x91C9E4C17F08A0EAULL, 0x3133F86798865DBDULL, 0xC4232B4FBAB0C905ULL, 0x0AC612BF8E4EA474ULL, 
            0x5BEAF027186BA566ULL, 0x5A123CDBCA3F05F4ULL, 0xC7CC4A2CA3E7C9F3ULL, 0x3B1C16587688366CULL, 
            0xBF3C5E417D6251CBULL, 0xBE0C8773AB35104CULL, 0x2654046CF759393DULL, 0x2EEED51596022CAFULL, 
            0xD5A31DE8215DEB0FULL, 0xCCAE79B147C2BC85ULL, 0xCC6B2D9770F5B426ULL, 0xDA983E7EA52A6C78ULL, 
            0x45028CE850B62BDAULL, 0x5726C4FBC75416E4ULL, 0x198CDEDB9C9C6E1EULL, 0xAC434CD37FA98B25ULL, 
            0x6B97B1DE5DD30AA0ULL, 0xDDE42B08931C111DULL, 0x8D3D77E3F46080A3ULL, 0x2F9F2923F07C46DFULL
        },
        {
            0x8A176D4DCCE48524ULL, 0x5ABCD754A0DB8553ULL, 0x9D2D0D87FF6F38FBULL, 0x648FA90030B65AAEULL, 
            0xCB8696995D805BFDULL, 0x62B0DD9EA642B9ACULL, 0xCB61F7AAD6F68C9BULL, 0x9FF07BDD9E521709ULL, 
            0xCF7D403F36A569AAULL, 0xF9A79351499CCF32ULL, 0xF8A1ABE40A94A1CDULL, 0x1E99A838E82AEBC2ULL, 
            0x9D06A24043ED8008ULL, 0x2FDEA240A2BAE662ULL, 0xEB41E2A74CF27FA9ULL, 0xE3A9572177EB4DF5ULL, 
            0x31EDAF8C4F531B9EULL, 0xC5B0FD36BA247CABULL, 0x86D0FDB98C3BF38BULL, 0x618354F39E045644ULL, 
            0xF2A77EFD64174442ULL, 0xC7FAA63C38FDBCD3ULL, 0xB068176489073553ULL, 0xBF21A77D058C5B39ULL, 
            0x4817E5EA4DD23309ULL, 0x594F18CC6D28C6C4ULL, 0x05D11EE7E584A381ULL, 0x71CCFC3D69AA679FULL, 
            0xFB588B93C06CEDCCULL, 0x5DDD01AF724AD379ULL, 0xF1FC6E9A459364CAULL, 0x317484EEEEAC7FA5ULL
        },
        {
            0x4624B056E88BCB5DULL, 0xC5AE60E6C6B5CDABULL, 0xD4F725F4B42A6BF1ULL, 0x8602D8335E15EA25ULL, 
            0x1125A4A3226C66D0ULL, 0x9D73E1F76972CF8FULL, 0x2974F72E2EB483EFULL, 0x8B08F75F732E9C66ULL, 
            0x91B1E15D27645718ULL, 0xF853AAC90E7C02E1ULL, 0x30FA94A884CCB1F3ULL, 0x4597F995F8D573D2ULL, 
            0x41C7D1083F5B0820ULL, 0x3EAE8E4E0654A09DULL, 0x7753811825F441E6ULL, 0x2E2352268DA836C5ULL, 
            0xDEA50898BD1E7AFCULL, 0x6B9ECC1366B6A503ULL, 0xD488BCA11FE4C458ULL, 0xD4197D0D96AB93B1ULL, 
            0xD46C2682F64ED1DDULL, 0x75BBDF0CF2EC7FBEULL, 0xDAC6F185130F241BULL, 0xDFF0BBD90FCA7A8DULL, 
            0x0A5F06CE17804F39ULL, 0x21CF338614BDB4D6ULL, 0xD11BD98A3A5B1A33ULL, 0xD0E61165835944F5ULL, 
            0xAA4EB00D655CA81CULL, 0x777CD468E9784F4AULL, 0x1E469216E0AC88AEULL, 0x1972C3476C29BAC6ULL
        },
        {
            0x74761E49079013B2ULL, 0x0334E3F741196485ULL, 0xABCA3049D6F23AF1ULL, 0x1898A1B2741E9BFEULL, 
            0xE8DFB2D613C0E9D6ULL, 0xD62E40992E939641ULL, 0x9FEE8BBAB823F471ULL, 0x558414A5BA494EB0ULL, 
            0xB568C3F603300A3BULL, 0x95DCFE36B005703AULL, 0x2298865B4870C3EFULL, 0x960753928A738520ULL, 
            0x342538BB940698DFULL, 0x21BE197EA1EB2042ULL, 0xE36A0817E41CDD50ULL, 0x21F01F394659CBB9ULL, 
            0x5767D690F5E901A4ULL, 0x6700F036E389B9A0ULL, 0x906A038DE3F1E49DULL, 0xEF50D3C91F1CD517ULL, 
            0x964783F96D54D5FFULL, 0x3B91BF40AD9F885EULL, 0x5529EA284B411418ULL, 0xD570FF773E5BED9DULL, 
            0x3C4B43B78218FF8DULL, 0x1534F7DE6B7C98FBULL, 0xF4475D67EC0FE013ULL, 0x782A316D1D090E1DULL, 
            0x4220ADDAC6438710ULL, 0x9F815FAF02F70C83ULL, 0x50D18867361E3778ULL, 0x4BF549134BBE25D9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseDConstants = {
    0x26CBE9D53FCA84A3ULL,
    0xA97783CCDDE5C29BULL,
    0x5D9DE04B51472E31ULL,
    0x26CBE9D53FCA84A3ULL,
    0xA97783CCDDE5C29BULL,
    0x5D9DE04B51472E31ULL,
    0x2763A9F36CB1E945ULL,
    0x0512AA514F5A2ABFULL,
    0x58,
    0x41,
    0x21,
    0x2B,
    0xB0,
    0x2B,
    0x3C,
    0x1B
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseESalts = {
    {
        {
            0x99A510DE37E76674ULL, 0x9C88F65D20EB20D1ULL, 0x4775EBC66D6D8BFBULL, 0x1EB58A4D0C3C6E6BULL, 
            0x6829E5767491144DULL, 0xBBA3F9859E23CFA4ULL, 0xCB559486C1ACEF8CULL, 0xA3B4BF5D3D1D1B6BULL, 
            0xAFCA59875EF50825ULL, 0xEACAF028398E2D0CULL, 0xD519D60B83D9478CULL, 0x90BB899B4DC61C65ULL, 
            0x28F793816546BDF2ULL, 0x6130DD1E69B508A1ULL, 0x68D398E9312A5318ULL, 0x31295CEA9A9246E3ULL, 
            0xA3C000F2F37CF273ULL, 0xE76DE9B20018E943ULL, 0x51B28D78E0225F33ULL, 0x5CFCEFF8B1EF25B3ULL, 
            0xBF1A7070997A962EULL, 0x0853A71134BF404DULL, 0x658BE52CC3E8D837ULL, 0x7631D771B01C5EDEULL, 
            0x2482108D6376B1E6ULL, 0x6A3288BD0BA85DD3ULL, 0x1B9CC36738FD60A9ULL, 0x5F7566DAB2380D16ULL, 
            0x03D7A75DF40BE144ULL, 0x9D2DEACFE8609346ULL, 0x8783D40A3DB0104FULL, 0x6309D89018D69EB0ULL
        },
        {
            0x94D9B313494CB600ULL, 0xDC7D281989D5E283ULL, 0xC56855C90B1BA55EULL, 0x880DC5BBC9DE6CFCULL, 
            0x7971A788B87A8108ULL, 0x169B94E68172662CULL, 0xC1B9E45C2A1E7CC8ULL, 0xD567F9A87BE5D762ULL, 
            0xB8DD9698216C8226ULL, 0x62CB1919AD2F4C90ULL, 0x626D831B66506BB6ULL, 0xF13CE30994B52705ULL, 
            0xE644C881A79074F9ULL, 0x1D6E688D2A5424F7ULL, 0x023CB49F731959A3ULL, 0xCD2D276DA7F11D63ULL, 
            0xB8812E74528BD422ULL, 0x41C1089B5581BEC5ULL, 0x9124E8E08837B528ULL, 0xB3E84DE5F0F852D9ULL, 
            0xDFC3903D53354E24ULL, 0x64B7F7802864CEF4ULL, 0xA2510F71DA4E574CULL, 0x6EFF99A9369D8439ULL, 
            0xF365422B17D9E378ULL, 0x0D186E1B7AA65CEFULL, 0x8B13CC65161AEF09ULL, 0xE05E08A9915FB7B8ULL, 
            0x3CBB8A0718A3545CULL, 0x92B58B7B48C9FFE5ULL, 0x677BF5235CDA19EBULL, 0xD0A01844CC4225E6ULL
        },
        {
            0xBE4D002562FD4BE3ULL, 0xCF74ED56C8B9BE25ULL, 0x318643D322EBD1F4ULL, 0xF22682E511126232ULL, 
            0x6FB365A6AC8E7496ULL, 0xAB50394EB6BC2B30ULL, 0x61BB494AE8078966ULL, 0xB91E21EF3D10E479ULL, 
            0x3C2C7E62DF119CA9ULL, 0xA5E8B4BD26C4D1D0ULL, 0x42E968E0902A66DFULL, 0x2D3EDEC4D988C9ACULL, 
            0x8B79B4A449DD51F7ULL, 0xA7A3B0B14924E60FULL, 0x38B3D9C9F96ED354ULL, 0x093EF3EBB59D60BCULL, 
            0x0A1C12720A06C491ULL, 0x0895D058C3BD5B40ULL, 0x554B7E15DA924D89ULL, 0x90417E36B717691DULL, 
            0x57F53E5E892B0D02ULL, 0x79E50CC2ADB0FAB1ULL, 0x2837940D606427CEULL, 0x7F23D91725ECCC60ULL, 
            0xB89B0289FB896B4EULL, 0xA1718E81A617F71BULL, 0x46BE5C5FF6FD2E24ULL, 0x75A30DBFC37F385FULL, 
            0x2FECE97D5AE250D4ULL, 0x3A1A6B953B7D0F3FULL, 0x5C1AE5241A18FE68ULL, 0xF75AFEAA803E8021ULL
        },
        {
            0x360734E99B625788ULL, 0xAD932F5B43DEA3C1ULL, 0x63D5F834CAA3BDD2ULL, 0x13C6F9B820DFC871ULL, 
            0xDB1E96A49198CDE8ULL, 0xCCEABBA75DE422D8ULL, 0xFCFDFC6568AFB313ULL, 0x15B3607A298B055BULL, 
            0x1E04391DEAB9F57AULL, 0x435FC2B232112F65ULL, 0x2B237B3924EBB90FULL, 0x4A552C8E2336A3F5ULL, 
            0xE8E0868257366336ULL, 0x4E47A02BD6A60643ULL, 0xD0678F355447A8E8ULL, 0xF1C175EBBDEBEEE4ULL, 
            0xE9060B9DE0C0F4F9ULL, 0x25110965C0D01AE5ULL, 0x1066B0299716A185ULL, 0x3F2C2AAB6E3B79B4ULL, 
            0xBB1CC3799AE63FF0ULL, 0x19EC85B0D1615124ULL, 0xC5C3082771483667ULL, 0x3E30CF2E8E2E4DF0ULL, 
            0x8D422F73F4BEA387ULL, 0x95A9B7F968C52D87ULL, 0xDE472DE869DF07E3ULL, 0x910A5703E9F909FFULL, 
            0x831B4A758AE6EDB6ULL, 0x0F608B13FE04412FULL, 0x692D227B62FAFCC4ULL, 0x79FABA9F6B30DF6EULL
        },
        {
            0x286972520250DC7AULL, 0x6D6E889B47D9F0EFULL, 0x3BF0696E8D226259ULL, 0x8BEEB89D8CCA1C3AULL, 
            0x4BFC0A9EE0507142ULL, 0x6E6FCC92B5E167BFULL, 0x9A445770F635950DULL, 0x559A1AA6FF5BBD17ULL, 
            0x946229CADC5637BFULL, 0x6D5FF448BC15D5FEULL, 0x1840703DB9D17807ULL, 0x1F8058F1D39ED670ULL, 
            0x4D8F93F93BB52441ULL, 0x83DB7C10C58FC726ULL, 0x93253E129EDC1ED6ULL, 0xAC4884226A704096ULL, 
            0xC50C64153AE2828CULL, 0x22E84DE38A653348ULL, 0x59EE2A508AA68D5FULL, 0x9A25FF1BB9E8BEACULL, 
            0x43A0CD427CEB1E8FULL, 0x2D20E426EFC81499ULL, 0x2363C6CFBD892222ULL, 0xC5FA97A55BB2CB63ULL, 
            0x27BA07C57E25693AULL, 0x23B4FDFE39FB4EFEULL, 0xDA205AA8D7838FDBULL, 0x717DBA0FEB638A3CULL, 
            0xAF780EDFE0CBEDF2ULL, 0xB33D7DCF8EEB2881ULL, 0xC40FF38AE60D7AD7ULL, 0xE304722D81954C04ULL
        },
        {
            0x8870E700C4109BA4ULL, 0x53AD5CCA98F075B7ULL, 0xC66AF7380A181B62ULL, 0xDD38D284E36CB73BULL, 
            0x4ACAE2BB7207BB7EULL, 0x9E69ABE415D083DBULL, 0x67710448A7AC488CULL, 0xF689622528BFDEFFULL, 
            0x242F9B16733F4EB9ULL, 0x2C0CC4AC2D6F8A88ULL, 0x46ADF4CD6CD5D1C6ULL, 0xD12D3766DDB8AA7FULL, 
            0x90E0234B21391BC5ULL, 0xDCA663427333349CULL, 0x81CF8A168472C7A9ULL, 0xCD72F929D4843442ULL, 
            0x0E5CAE7C7F01E48AULL, 0x98BC385C41FB2B64ULL, 0x603ABBAB31EFEE06ULL, 0x58FE82A94C7C0D7EULL, 
            0x1853627CC9DDC3ECULL, 0x4FD1CE6E42E735EEULL, 0xECA60EE6845075C8ULL, 0xAE1D035648E55ED0ULL, 
            0xA9EFBC1C8F4AA89AULL, 0x514148BBE8BCE145ULL, 0x714CC15C64728D85ULL, 0x69B2862DE683880DULL, 
            0xAB02CA5133076746ULL, 0xC01A5757D5A810CFULL, 0x653B4D35D4324AB5ULL, 0x5B7CB97567598D77ULL
        }
    },
    {
        {
            0xD895E7D262E0E84BULL, 0x489513E2542EAA24ULL, 0x146083A26EA54A24ULL, 0x5E4E7F1605E942C2ULL, 
            0xCCFB26D945DF9182ULL, 0x9568C5C5998BBD32ULL, 0xE5FBB6D9E7D25125ULL, 0xF6D87C815AC14541ULL, 
            0x47553FBC4A740E58ULL, 0x176BFC86FEACBB0DULL, 0xAD39625D2BF38AA7ULL, 0xAE498CA4605B21B3ULL, 
            0xB3257B2E78AF60DCULL, 0xBF7C118AE5AD878CULL, 0x1821D6EE2221BB69ULL, 0x43390434F498F464ULL, 
            0x03F05C2BB78084D9ULL, 0x1E40480B3CB84190ULL, 0x0BD749FB784DD0CBULL, 0x7B0FA1D01F80056AULL, 
            0x40877A5872E8F38BULL, 0xDA42C1FB22F1185BULL, 0x002865B92527EC93ULL, 0x978A032AFA838284ULL, 
            0xE875B6BB6952531FULL, 0xDD5C6BDD017AE855ULL, 0xF938CBBD771C67D0ULL, 0xA8023D7B3579F0C3ULL, 
            0x38100DBD34A97B64ULL, 0xDEDF6645778E74F0ULL, 0x50E6F541BEDC7022ULL, 0xD7452F57615FFB58ULL
        },
        {
            0x2B19842356A2F490ULL, 0x239C7A63B533F00CULL, 0xCE4C3588C6FCC1EBULL, 0xDA4E13070BF7F7E2ULL, 
            0xEA44CA5A1A547169ULL, 0x6F5DDC1059945F9BULL, 0xCE507AAE085B02BDULL, 0x3DDD9BAD819E7690ULL, 
            0x5F35EDA8FDBF3C32ULL, 0x80569A0B466D7FAFULL, 0x8CE233D9ED8A8DD1ULL, 0xAED7A6BD4FE9718BULL, 
            0x108F5568B51BC012ULL, 0xE8A3727D53F80D38ULL, 0x829C12EBAA37F7CDULL, 0x4070150FCA1E9827ULL, 
            0xF0536845C3AB8D7EULL, 0x70445E8AFBD815FFULL, 0x7C1E32E4D1426009ULL, 0x8C8F1D1169B5F83AULL, 
            0x06F497FC9D65A969ULL, 0xFBB682F676034A5FULL, 0x674A0BFB1896369AULL, 0xCB8F945B2A5B86AAULL, 
            0xD7C9090A9CC585E6ULL, 0x98A96065F94A9531ULL, 0x3C2FD98A0E10FBB9ULL, 0x2C871702BBC966F7ULL, 
            0xB2163132ED73E4BFULL, 0x00E6B706F47B42EAULL, 0x11BB54CC52940215ULL, 0x7A080FDF91275FD4ULL
        },
        {
            0x366E501137BA1FDDULL, 0xDA4E354EBFF0EC6BULL, 0xB72FA31B53F41862ULL, 0x3596095091D2AA3CULL, 
            0x2C1EDD5DED40BCEEULL, 0xB4F5A35A5604AD9EULL, 0x5813ED4CE60A0DDBULL, 0xF186882435AAACB9ULL, 
            0x6CC912B921F0C66CULL, 0xC385E3073A6DCC0CULL, 0xCC3D65E49B1C4CDBULL, 0x9FAE17772A631A07ULL, 
            0x5EEA1863FEF5A161ULL, 0x4FD3DC77E548E82CULL, 0x8F09798B4136A60CULL, 0xCECF60FF9779409CULL, 
            0x12DA6E4DD1E5A13BULL, 0xDF4F236494FD44C1ULL, 0x91708EE13A0F1646ULL, 0xE48582A686C9A705ULL, 
            0x30C32D87DEECC25CULL, 0x20438BE2CC5A21AAULL, 0xD1E59F7CB2F618A9ULL, 0x24FC390C40AA4A49ULL, 
            0xA7E12DE3228103E3ULL, 0x35BD9CCE309EC7B8ULL, 0x365F535E61227AA3ULL, 0xED38439FE6980111ULL, 
            0xFD70ED870117C6D2ULL, 0x4D693FBA2CE82D56ULL, 0x97194647AFCECDADULL, 0x32BC13AFFAA0CEFDULL
        },
        {
            0xEAE7ED5D9C293DD5ULL, 0x412B8DEA922D21DBULL, 0xEC477989477DC6E3ULL, 0xF43B205B6A6035CCULL, 
            0x144E8667952BBDE5ULL, 0x4A3494E9616BC422ULL, 0x4E0638A6B4E9D658ULL, 0x9E51DC98091060E9ULL, 
            0x9C38BB2608C23B96ULL, 0x5FA92B5C40F1016CULL, 0x78C403729B1D20CBULL, 0x682AA13394E8A1E4ULL, 
            0xB35D4675294616B0ULL, 0x35A5C7E072F5C2D0ULL, 0xADEE591B649C3046ULL, 0x5D6F4E158ED7D8D9ULL, 
            0x550CD4979BFE4FA0ULL, 0x21143EF856A7A779ULL, 0xDBD85CD66A144FB8ULL, 0xA74C912765C95DF5ULL, 
            0x34F55696C765D5F4ULL, 0xD78A56476DEEFDAEULL, 0x9344E8D68E672015ULL, 0xCDF250F2A7ED3CC8ULL, 
            0xF2016C40BE5CEDCCULL, 0x3E1885BE46237C21ULL, 0x4370EFC62BF60E9CULL, 0x48F91E6BAD866DD7ULL, 
            0x898B226ADA376F5CULL, 0x748EAD901362F648ULL, 0xB6BCD9B3A40EBA7CULL, 0x22F8130F919B6691ULL
        },
        {
            0xD434692813E43918ULL, 0x31D4FD905F83325EULL, 0x4D3258C43F437899ULL, 0x7853578DB08FBDE6ULL, 
            0x9B074F99E04227C3ULL, 0xCECA7893380D40E6ULL, 0x4A9D526CE0B69592ULL, 0x3BFA883EAE4952D0ULL, 
            0x0C0B436CCA4255A6ULL, 0xFFDAAE34169445F1ULL, 0xF9E397F9D8CEDEF2ULL, 0xE1C31CF5E80103D6ULL, 
            0xD34010CFD681356CULL, 0xA48827D1B6238D0DULL, 0x2945CEC645AAB1ADULL, 0x2E9C5F5D1184228AULL, 
            0x7A8285AEFF605C80ULL, 0xD1B92D67D3CFF774ULL, 0x21D47C67792D8820ULL, 0x99BD37EBA971ED86ULL, 
            0x5B0D311942F1A948ULL, 0x66C1FF613C21D1CAULL, 0x213E5734F3965CBFULL, 0xDAA045C7F2A3A71EULL, 
            0x1416B2E59E0185A2ULL, 0xA6E3A367E55563BFULL, 0x8E5DB417B8F90E26ULL, 0xE7C7CD75E719AC5DULL, 
            0x4A589F10EFC60385ULL, 0x9A742A30EECC2D67ULL, 0x2D859470EE711C91ULL, 0x88A1E4BF7107B95EULL
        },
        {
            0xF870CD4198C93FB0ULL, 0x82D9B11CDF2100B1ULL, 0x24BA0E241195D34EULL, 0x9F61928EF25E2ED7ULL, 
            0x5C939AE06D234F8DULL, 0x674336AD890DBBD1ULL, 0x9ACDD179DBEB1CBBULL, 0xA9DC4C3059CC9DC8ULL, 
            0x5F1613FC58082A5DULL, 0x85F32D14D3CF6750ULL, 0x0782AE8AC0431A6EULL, 0xB6695F518514BB38ULL, 
            0x01A23B63E819264FULL, 0x673D25FAEC371E29ULL, 0x3F9A2C656D5346F2ULL, 0x91E1F59D037A5328ULL, 
            0xAF6F062F16B4B877ULL, 0x68E938B7047E30F5ULL, 0x6A752698C90962D8ULL, 0x95E7CA57FDAEB037ULL, 
            0xED179BD0142A823EULL, 0x1885AF6343DBAD34ULL, 0x545EA43E0755A402ULL, 0x4C1BA79507A5FC04ULL, 
            0x5C60E50EC7E2F41BULL, 0x850827F5255A175AULL, 0x86B0DA26A4B118CFULL, 0xC52B6F986B102992ULL, 
            0x30C12A9C061390ABULL, 0x27D93189DC817244ULL, 0xE17BDE50699968C0ULL, 0x2CF76BDA897C96FFULL
        }
    },
    {
        {
            0xD434147A1849BE46ULL, 0xBD1FF965C4E105DBULL, 0xC626D2BD70FAD2DCULL, 0x13D0A71D711644C3ULL, 
            0x368310D0F31004ECULL, 0x0F5F93BA6A65A3DBULL, 0x149EB75419DD6725ULL, 0xF258F947A4043DBAULL, 
            0xA5DD2664C3EDAE99ULL, 0x5F3137E13120D37BULL, 0x315070D3A4CAD6E0ULL, 0xAF49C2E2CBFBC447ULL, 
            0x0A6E72E49ED4DE1EULL, 0x544D40899D4EAB58ULL, 0x20C9EC039E75BD5BULL, 0xAB587C46E35AA84AULL, 
            0xEE9670CF1BFF761FULL, 0xC8F418A862F64F45ULL, 0x48F301325D89E4B9ULL, 0x3842A624FC249333ULL, 
            0xBB36F008DBC12E1BULL, 0xD3EE289F2347275BULL, 0xF0E2BF66385B7F45ULL, 0xCCC43DC4EDC5CBD9ULL, 
            0x9CBF3EAF6B5373F4ULL, 0x07E6488A99E71AB6ULL, 0xB0E6B3AC786C05AAULL, 0xB7641E91730A3C38ULL, 
            0x87A9B02169FE66E9ULL, 0xE5255952FD59B3E2ULL, 0x38412BA56F04C4A7ULL, 0x77970506EB8D82F1ULL
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
            0x2DFB354F5D5B58D1ULL, 0xF2AC92A0DAA5CFC1ULL, 0xB8D67A2F6EB36B56ULL, 0x8BE5F9E4395FA00CULL, 
            0x9979DBE3F31FDC8CULL, 0xB7CE4AFB661C1C82ULL, 0x259D82036D173ACFULL, 0x4C705D67DA34E65AULL, 
            0x945589D2F45C290DULL, 0x6A25E16E2BD8144FULL, 0x6878DBC096DE1232ULL, 0x52487BB3E7291727ULL, 
            0x09B8039C3735D678ULL, 0x27710F2A0F73A0BEULL, 0x176ED2F4451F0F8DULL, 0x36B72387D7BFBA11ULL, 
            0x5F83E0AC8CFFA15FULL, 0xC67AB0B4EDCA08A1ULL, 0x71AF41FC8BDC85A5ULL, 0x3306995483033B58ULL, 
            0x2DE6D900A4396868ULL, 0x506CB2881A32BA7AULL, 0xCD68915861818342ULL, 0x36B548550D93F26EULL, 
            0x90F081DCEF9674B5ULL, 0x48FA5EEA2128FF43ULL, 0xEDB4A3482D61B438ULL, 0x3CB4B375A05B758EULL, 
            0x5CDF89F987E085E0ULL, 0x31B0A673A0975D80ULL, 0xC6560183C1AB782BULL, 0xF704B5E651F0C603ULL
        },
        {
            0x4EECBAF6A6531C7FULL, 0x38A9D3413AB75BD2ULL, 0xB6875E8A4878A7F0ULL, 0x10579F5FE55614E3ULL, 
            0x6385227445F034DFULL, 0x87687896FF651CEEULL, 0x38C4B3BF764C1E66ULL, 0x208FD583E9AF47FFULL, 
            0x89D08F31A9D745BCULL, 0x429B963B1B53704BULL, 0x84FA446CC3C682BEULL, 0x855C4E77CAB53049ULL, 
            0x03A6E67E6BE01BA5ULL, 0x3E61A2FD2B4B3266ULL, 0x1924DE3CE7C5C0F3ULL, 0x31B0D3855090E6FEULL, 
            0x701553C956A6DE39ULL, 0x98F6DD0BC5DBE633ULL, 0x221B2B8F999BC756ULL, 0x13174F3CC4442B13ULL, 
            0xB5E5E4CBDFDBA7B7ULL, 0x33EDA87664184626ULL, 0x0D0A25E4616EEE91ULL, 0x0B4A83009DEB59ACULL, 
            0x8234E5F9501A4FADULL, 0x4CF7EE6BF393190EULL, 0xADB6CD1A0AE31A82ULL, 0x4C20DEFB5A3153EAULL, 
            0xAAF2040F6956687EULL, 0x0D2D1674E07F554BULL, 0x2AAD1F1CD31D8C2BULL, 0x41CA795491929E19ULL
        },
        {
            0x4529E125062F376FULL, 0x6D7237AC7C90C173ULL, 0x77CD2EECC891E272ULL, 0x68423491796494A0ULL, 
            0xE3AEA233BF9B3A7AULL, 0x3019B130FA9C845CULL, 0x928584F6EB8F5395ULL, 0xE35BF6305CBD409DULL, 
            0x954E72A0851D68E3ULL, 0x407F6A660C5A805EULL, 0x0169A955FEE78B97ULL, 0x759FB87C4C6FAEA5ULL, 
            0x0CC55D85CD2A7A68ULL, 0x77B2B1C1A556E558ULL, 0x0E70507AFFA3EEC8ULL, 0xD139AE5EF43AEF24ULL, 
            0x24B2B7DC68BFAF8FULL, 0x0CC4AF1A324662DCULL, 0x327949A50255FA36ULL, 0xFDC86CF36C295780ULL, 
            0xC7AD0188C6FDC644ULL, 0x957E00D410E5F1E9ULL, 0xD89BF63F061CFB4DULL, 0xD39B3073FB109184ULL, 
            0x6C763D25971D7734ULL, 0x50615B726DCB0271ULL, 0xEBBC0EBFBC893F4AULL, 0xD92C54556CC773C8ULL, 
            0x65EB5BE39B0EAD60ULL, 0xEF3B110536CA8708ULL, 0xCAA844B355A1BAFEULL, 0x9457AFE0A7EEE110ULL
        },
        {
            0x6F9C01BB1036D9CAULL, 0x060ABCBD8322B27CULL, 0xF4370E68BC4E851FULL, 0xAC999F7E8106CF20ULL, 
            0x9EE4F23DA5538DA8ULL, 0x4ADFF24C904516DDULL, 0x24C8776D4B117D27ULL, 0xF488F46904FCF345ULL, 
            0x5C0E8806E25A7B58ULL, 0x07899620AEC3B5F8ULL, 0x8A381233BDB8DCC0ULL, 0x2BB4B6B4BE76C128ULL, 
            0xB92FA6128FF29AFFULL, 0xFB03E2645AA3A6A4ULL, 0x76ADB70EA4D19E5AULL, 0xC8946FA0B638E0CEULL, 
            0x8396120DA8DD9D70ULL, 0xFA5A0645FACC1712ULL, 0x3D406A7085F95597ULL, 0xA1CAAA9AA2281AE6ULL, 
            0x98C417D8AC8DC2A5ULL, 0xC923C6A14A6BAEDFULL, 0x846DABFAD3D08F6EULL, 0x2EDAD4878D8360A3ULL, 
            0x653DA3D4FD3F5B77ULL, 0x8C9998CD73278F8CULL, 0x4FD46E21F64ACF6AULL, 0x80F664D2B7C3DB87ULL, 
            0xE79F8833F5D17A0DULL, 0x83C39B018DB770C5ULL, 0x2CEE82FD5E7D5EA2ULL, 0x2C47CDCD567D3FC7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseEConstants = {
    0x6A74B9F86D4399F8ULL,
    0x65B03679412AC51FULL,
    0xA2175A199FD2C482ULL,
    0x6A74B9F86D4399F8ULL,
    0x65B03679412AC51FULL,
    0xA2175A199FD2C482ULL,
    0x15825A66F26AE599ULL,
    0x051ACDF60026CE08ULL,
    0xA8,
    0x49,
    0xA1,
    0x1B,
    0xC8,
    0xEF,
    0xCF,
    0x51
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseFSalts = {
    {
        {
            0x0C25D6B4D571D4FCULL, 0x32CBC37933B0DBB8ULL, 0x05E0988B1EA8C119ULL, 0x5473C3C0D7676FE0ULL, 
            0x81B4C1720ED72096ULL, 0x9600E6A6EF70620BULL, 0x71DEC1BACBA28CB2ULL, 0x0BFDE28E10800B0AULL, 
            0x2FC6DF01E9C4A93EULL, 0x14B685A0FD917511ULL, 0xD459271F83918A8DULL, 0xA7890F7DBD3680ADULL, 
            0x8947FAE42B172203ULL, 0x61A58E4DB42005EAULL, 0x70C4C29004A49DDAULL, 0x106D98EAAED4FB5EULL, 
            0x1B6847BDC0F477EAULL, 0xB2794C235AA95668ULL, 0x6B5ACABF5FCC9E95ULL, 0x80D48ADA5F257E2DULL, 
            0x61191329483CDF8FULL, 0xAEEB9F7C3CB73E0BULL, 0x3EAAA650796A7E7CULL, 0x09B4CF3D71491A54ULL, 
            0x811C189B055DA026ULL, 0xCFBE2AC2385019A3ULL, 0x8DA23B75B24D80F3ULL, 0x818276DCDA6413F8ULL, 
            0xDEA262F19EAE5D3EULL, 0xC7F3E795DD40FF36ULL, 0x9B51EE2D39C581A1ULL, 0xC3998EEEB5008181ULL
        },
        {
            0xB3D4C9317B0270A7ULL, 0x6807F434B4302B12ULL, 0x78AB24FAC662DC79ULL, 0xB3C39AB536404CF3ULL, 
            0xDF011E6B83860FD6ULL, 0x85EAD034BB108A89ULL, 0x1B2E08BC93CEC6BCULL, 0xCF096EA6CCC40012ULL, 
            0x960F05D7D5640C6AULL, 0x46FB210FB04EAF03ULL, 0x5F0FB696123ADA38ULL, 0x76B9268BE0B96D84ULL, 
            0x23408F2840D2C9F2ULL, 0xB7093407EF1D8DBEULL, 0x684CDBB1C7B70C57ULL, 0x01225CE6A028095EULL, 
            0x9A5C428DE45060F7ULL, 0xD7F90CD0AD12DB4FULL, 0x40B6153E52F12B0BULL, 0x503E7BA1DA3AA8FCULL, 
            0x0FBC3DB504D53AD1ULL, 0xE69B0A93138D41FEULL, 0xCAE5128795FE6E5CULL, 0x92AA1A67F3E17EA1ULL, 
            0x30A83233A22CE63FULL, 0xC3A8410FF9C4F4D3ULL, 0x6398E5A6393C0536ULL, 0x824C62358F5C2A7CULL, 
            0xB88B6A7CCD314B33ULL, 0xD546156A003C9ED0ULL, 0xF25981D629B6B207ULL, 0xCD289DE7FA09167BULL
        },
        {
            0xF4A5880E2BA832B9ULL, 0xF56368F38807B493ULL, 0x4175787E31AD7755ULL, 0xD31425C6CE26347BULL, 
            0x47243E7F747BE2CCULL, 0x269CEF3ADE408619ULL, 0x214108B06873EDA6ULL, 0xE6893D1A8D20B1F8ULL, 
            0x7C258A539984DD1CULL, 0x99186200E8784ACDULL, 0x2289663EB5A3EAC2ULL, 0xD3D0E32245494C15ULL, 
            0xAC388BF9185F6880ULL, 0x327A3FD49FF22BB0ULL, 0x4665D2140B5F0357ULL, 0x4FD3FB376815E1C6ULL, 
            0xE65BF1DA41343B01ULL, 0xEA2F0087B53E53F3ULL, 0xBC54E8BC0069453BULL, 0x7D253A57438AEC44ULL, 
            0xF7AAEAC7A461986EULL, 0x415DAD98497BC0DEULL, 0x88A81CD8119698DBULL, 0xAAE970B2F2882745ULL, 
            0xAE3BED9F7895315BULL, 0xFF8C43AA160CB98AULL, 0x82026CB9B8CA0E8FULL, 0xDCA251DD8C46CA96ULL, 
            0xAA21AB4F9E73F811ULL, 0xF89199915EA509FCULL, 0x878C3CDABEA9880AULL, 0x76C80F9C4547F1EDULL
        },
        {
            0x2AA90E3EF01EFFA6ULL, 0xD2C753C4B0B5D1CFULL, 0xF01349702701316AULL, 0x0A85A615137D9E12ULL, 
            0x8D88F346EB6A3614ULL, 0x7DD2F88CE5C1A1FAULL, 0xB53B75A6548AF3BAULL, 0x5494FB0989FE4475ULL, 
            0xF8580F8E83F36F46ULL, 0x3A0100683757C31CULL, 0x1AA38C50AA14759AULL, 0xCB63D8C0147359B9ULL, 
            0x34D950F541F9B230ULL, 0x3827AE0C506BEDA9ULL, 0xF6C65ACAED3D8F9FULL, 0x9825C84481C486F1ULL, 
            0xD1ABC633CEA07B8BULL, 0xD92EC3D692322187ULL, 0xBECEAC36EC072FD3ULL, 0xD35BDD90800CC8D5ULL, 
            0x0E947F4DB243338CULL, 0x18E86E57F37A9DECULL, 0x78B80574DB95C84BULL, 0x3773B5914F5FA8EFULL, 
            0xFDC9A5ED9A1B43A2ULL, 0xA4D934A809AEF872ULL, 0x0BEE4EEE52D22405ULL, 0x5B969B0DA580DFA6ULL, 
            0x5FCA2F783071C386ULL, 0x545E41A88E281FEAULL, 0x599DD0C8DBACCF34ULL, 0x7E0041AE22A1DFCEULL
        },
        {
            0x70A5BEC3BF391DA7ULL, 0x16F678006BE19DC3ULL, 0x8CC94D11A009BD8DULL, 0xD0C868BF868DC97BULL, 
            0x504406FB5A5EF866ULL, 0x808408EC8B02EE28ULL, 0x9987F35F9BB0B5AAULL, 0xE77D01CD012241F7ULL, 
            0xF26FD1AE79C83848ULL, 0xF4A9AD50031F10F6ULL, 0x39CB4AD9B58D8507ULL, 0xC56E94EEC9BF6C74ULL, 
            0x3CE1ECDBD062C7B8ULL, 0xBA27E6B0141BD601ULL, 0x9543715BAA19EDCDULL, 0x0F873C2BED1480FEULL, 
            0x3FC24F9E694B8896ULL, 0x6B72F69A436FC353ULL, 0xC3D43C1E82D400F1ULL, 0x05F50F7644563E58ULL, 
            0x1FDE193BA6793C3BULL, 0x88DA0F0B80E479B0ULL, 0x405F50B0F95005F6ULL, 0x4A975CB020A3E630ULL, 
            0x6107C1803A44FD87ULL, 0xF5ED4E4E99336233ULL, 0xAFC5D4DF563527A2ULL, 0x78D44B9A2E6BF689ULL, 
            0x4C8910E05DC66DF5ULL, 0x958258B17F7E6CBCULL, 0xBECE1E4330DEAE93ULL, 0x9AA2B431D1A3866EULL
        },
        {
            0x0FEB68705D530167ULL, 0xB2FE1562C0B50261ULL, 0xE867AE83B6FECBDEULL, 0x324E31BDFCC15551ULL, 
            0xE86B5388CD1373B2ULL, 0x8C4708EA597F1D15ULL, 0x10AA3FB5D05C932FULL, 0x0E95F5C918C4A5C7ULL, 
            0xAE3B94503918C852ULL, 0x6DC95271138B3C2CULL, 0x5B653D6F60D1538DULL, 0xCF6AC22E21C8B9E0ULL, 
            0x7AB920B95A6A3269ULL, 0x78A3E2DE3F292731ULL, 0x8A5EFFBE3F83C7CEULL, 0xCA6BE9BA90FFE100ULL, 
            0x112707D9FAF35AFAULL, 0x965364423AAE9A63ULL, 0x28544DC3E518A104ULL, 0x7BB9E61756EFE7D7ULL, 
            0xCFED66C0614CA350ULL, 0x224AD552E3F62428ULL, 0x8BEF48B24FE7CAADULL, 0x0FF4FFAA73EC621CULL, 
            0x34180B59FEB67AA1ULL, 0xC08DEDA9B31FF877ULL, 0x36DEA89065083DD9ULL, 0xAB6D7B0D051E425AULL, 
            0x0C293ABDC705E0EAULL, 0x74554A489CCA16D6ULL, 0x1A2388A542DB539DULL, 0x42E5EA93C8F26E96ULL
        }
    },
    {
        {
            0xAB66A3D1613E9658ULL, 0xD7AD31FE5EBB64DBULL, 0x0F8AAD13B42BED46ULL, 0xD0A1B0C4A7E09086ULL, 
            0x095EF25999C24258ULL, 0x2E49EDE8BEEF04A9ULL, 0x8912D4E84C27FD6FULL, 0xD6B7A371FE7DFD89ULL, 
            0xFC40DD4956E4B09CULL, 0x17BB1C70EC7258FAULL, 0x349E1C784C80E56BULL, 0x3C93EA02817B0105ULL, 
            0xAABAAC3CF51ABFA7ULL, 0x10EC60FD1D0BC543ULL, 0xBE1FC9A5CD577D1BULL, 0x26C32BA3BF71140AULL, 
            0xAB4FC6A9827B7D19ULL, 0x4CC4DF6FD70566EEULL, 0x42F9CE3F9F2B9427ULL, 0xAC98ECD937AF466EULL, 
            0x6E3DE467D2D979AAULL, 0x5086511B2C9E37E7ULL, 0x0210DD74F022A72BULL, 0xD28C3C36377AAA25ULL, 
            0xC02FE52ABDB653CFULL, 0x4CEEC256ACD85E94ULL, 0xCF711345F63B1597ULL, 0x5A1A5972ED63B3FAULL, 
            0xB552B36721140E3EULL, 0x32252DFFBCA44638ULL, 0x0DC0C73113A323B4ULL, 0x5ED8D12DACBFF68BULL
        },
        {
            0x0811F4C382EB8305ULL, 0xDA7F8F11B2EAE2B5ULL, 0x7E338677CEA8E71CULL, 0xA6243FE2DC0DB825ULL, 
            0x54C45651E0113198ULL, 0x97C259EC5A6F8D0CULL, 0xDBA9BC5D9090607CULL, 0xA688CCBD5BF8B234ULL, 
            0x40671CE274882034ULL, 0x2C5E5F29FEBD2964ULL, 0x08D2A7B2BE8FD7A5ULL, 0x3ED1C50670C03B91ULL, 
            0x57C6932235BF75D2ULL, 0x69DC417C00EF7819ULL, 0x0CE1BCACCCF665EEULL, 0x2F9A927941A17C97ULL, 
            0xBA66BAE25A6FBB1FULL, 0xD99CEAE7155F298BULL, 0xFC3876E07D09CFCFULL, 0x6B8AC93431E392FDULL, 
            0x52C4C9FF5C4A1F95ULL, 0x15806897C213E073ULL, 0x416C1B29BE83FC33ULL, 0x9B99E55AAEDFC14FULL, 
            0xC6CF88AACC2C827FULL, 0x781803EE922C9856ULL, 0x859DE5424682A721ULL, 0x27BB786FC5AD5E03ULL, 
            0xEE67285001976E4CULL, 0x83D2BA4A1D8CD34DULL, 0x7A9E350ED4C15150ULL, 0x9D208B5BFD7A02D6ULL
        },
        {
            0x24886409D37F2C07ULL, 0x0925A0C8B85DA5C2ULL, 0xDAD9A221CA0E4E99ULL, 0x1F08154A8FAEC855ULL, 
            0xE252C1C0214B8EA1ULL, 0x7CD25370A1765F9BULL, 0xDE55E3F0CEF568A4ULL, 0x22D0ADFF8D4C32F0ULL, 
            0xF83D2EE3D96B5147ULL, 0x0A152CE819B6C977ULL, 0x31B7424C975572D4ULL, 0xFCD8C6731C5B4D59ULL, 
            0x3B7732D196C9B68BULL, 0x24943740E39B4634ULL, 0xB42E8A4476EAB31AULL, 0x93A62D3FD46D1494ULL, 
            0x46E77B7A080536EBULL, 0x0DF17E3C4ABC34F7ULL, 0x25418383F157A53EULL, 0x6E7A762CD3BA1AEFULL, 
            0xB0E0A4C1E2C227F3ULL, 0x6FD9390687AF446FULL, 0x5A1EDAEB2EC56C08ULL, 0x490E4D1DAB788817ULL, 
            0xDD37649B769A07A3ULL, 0xDDECCEE837EEEEB5ULL, 0x28389477750BA2E8ULL, 0xBB5AA5E4C3802BD3ULL, 
            0xA4110461CE7951FEULL, 0x59C1511415B8BA1FULL, 0xDBE3F2F213A86797ULL, 0xE6A64C6B2910B4B7ULL
        },
        {
            0x5E256AA233686A11ULL, 0x8A7CEE61A0238113ULL, 0xE6C4AA71A621B980ULL, 0x93E3AE96A851D197ULL, 
            0xA84945B628F1E407ULL, 0xE4CD447706AAA3E4ULL, 0x9B67AAE3DCD4348AULL, 0x55C9CEA8E8E18094ULL, 
            0xCC6B513EFAC6D4DDULL, 0x97B118B3099DDE1BULL, 0xE8776CDA3F0B6677ULL, 0x27FCC142D23784C0ULL, 
            0x83C1BC81607BD62AULL, 0xFB8B38882501ED9CULL, 0x410C4111F3C42236ULL, 0x39278AB0A14D932FULL, 
            0x50511BE15C4058FAULL, 0xEE41C669063714B4ULL, 0xDE52EACB49CC3D35ULL, 0xE0D729BDCC4880F5ULL, 
            0xB66B85435B19834DULL, 0x3D043B9BA19CB476ULL, 0x183380EF86865160ULL, 0x77D964B6FB556046ULL, 
            0xC5A8F702351EC9FDULL, 0xFE9EBE6337C40EE5ULL, 0x0A06F902D590EE2BULL, 0xCF0ADE20207F5387ULL, 
            0xB5538527F53B353DULL, 0xD0152C779EF42BD7ULL, 0x9B5F338B9DC834C8ULL, 0x31FFE8DB60211F8CULL
        },
        {
            0xAAC2868F910601EBULL, 0x9E0DBCFEF3C430A2ULL, 0x8ACEC6FB7D93DF66ULL, 0x2F36124807626C65ULL, 
            0xF67AE9A7E1EB96BAULL, 0x38140518FE92132CULL, 0x29889191C34F3718ULL, 0xFFFF5F20D4F7B620ULL, 
            0xC4992B1DF81870AAULL, 0xE9A4F0BAC1E21A20ULL, 0x11D4F2D745E77A05ULL, 0x4265BD76CCFFA3ECULL, 
            0x1B8A6548CF3E15FEULL, 0xCEEBC1972D34332BULL, 0x67362F37FADF837CULL, 0x05D63CCBB5732D2FULL, 
            0xFAD6E342FC0490DAULL, 0x3D773AF3753CDF23ULL, 0xCCDDD2D950A441F3ULL, 0x33FCA2306A6E6787ULL, 
            0x3EA8916678F7D64AULL, 0xC084FB2FE2F1AA51ULL, 0x0BB93F769FF78C47ULL, 0xA2C15DA0BB648B73ULL, 
            0x4909C2A54E6497C7ULL, 0x1366C7D4E62523BAULL, 0x476D8C95E1D5D05AULL, 0x26868CFE07681176ULL, 
            0xD2CF0733AFA72CC8ULL, 0x03FF8B9D85FE9594ULL, 0xA50ADDC7529DE5E2ULL, 0x807AECD1EA22C813ULL
        },
        {
            0x4607C6DD5982397CULL, 0xD663E557E73A5BDAULL, 0x9EE07E28E37C18BBULL, 0x76964FFD5648155FULL, 
            0x21642FF6197275FDULL, 0x8B1F3935ACB7D556ULL, 0x7E7D5E5D18129BB3ULL, 0x251FEFC355369079ULL, 
            0xD181B14ACFCB88ECULL, 0x5D50CB67FC95B5B4ULL, 0xDA5BB7E9E10AE617ULL, 0x631BD74A37DDDB46ULL, 
            0x170C7A34A3136445ULL, 0xBEBEEF11192A7E0CULL, 0xF370DD45A4FBB11AULL, 0xF075B24BFBDD9FFDULL, 
            0x9B9361D1AFF80767ULL, 0xE80E600CC039D915ULL, 0xE5C4D337FE8CBBD3ULL, 0xEB33B95586593C15ULL, 
            0x76607E87FA2B5BAAULL, 0x1CBEF03BB4BEAB17ULL, 0x9B4EFF9E7651EDDDULL, 0xBFA4DC3813743842ULL, 
            0xDD05C824D361721BULL, 0x51F1255D167C2B9EULL, 0x1CD9F763818BA996ULL, 0x3A3F7E80DC5F3EB3ULL, 
            0x6A0C1E94160545AEULL, 0x225DE0B031850BBEULL, 0x21ECCEE56F75501AULL, 0x367C090594F0F442ULL
        }
    },
    {
        {
            0x8494610652D5C631ULL, 0x8D09BDBA98759CBBULL, 0x9BFFC79F5D8330E9ULL, 0x9BA38F8AC23CA860ULL, 
            0xD9737AFF18E8AB64ULL, 0x1AA149AD38E5B53BULL, 0x26D3C3448B731AC7ULL, 0x723E49D913073565ULL, 
            0x766D7A753191A38AULL, 0xEB2D891C3175C5B5ULL, 0x038E153D73F2B44AULL, 0xBC017737DBFC58B7ULL, 
            0xD1AD7D71554D4684ULL, 0xF0CCD153025BA266ULL, 0xB356F9383E80B327ULL, 0xBE678A9F2AE5BB64ULL, 
            0x0FB847FF9D137768ULL, 0x9A16574DC0DBBEF1ULL, 0xABCD0618DC6AB934ULL, 0xD6C4C05483707F35ULL, 
            0x88BE1E490CF99AB0ULL, 0x983F0A1A9A966135ULL, 0x9CC9E9C0336EDBCCULL, 0xA5B725ABE2640087ULL, 
            0xAD4F655CEDBD3ADEULL, 0xAC9A103579752919ULL, 0x94EAF5CA2476245CULL, 0x16DFA61C6368C86CULL, 
            0x440239C64DFCF08DULL, 0x4921A658C2F284B7ULL, 0xAACDDDBBD3D9E8D6ULL, 0xD9DC4BA2DD42F246ULL
        },
        {
            0x16DC4E2AF78D2562ULL, 0x727E8CB40C5E9BFAULL, 0x25CD4A7107D8BBC3ULL, 0xEF6902CB614953F4ULL, 
            0x2ADF490AF427C3D4ULL, 0x2DB320670A02D4F8ULL, 0xD94F6E7A2E5511FBULL, 0x65252C3BB8975D29ULL, 
            0x25838BDEFB411312ULL, 0x880205945FB10443ULL, 0x6595389106556231ULL, 0x964A66843AAFF943ULL, 
            0xB35600A878CC489EULL, 0xEC54AFF0B71ACC46ULL, 0x7802398327745AF2ULL, 0xA296AA77A9EAC7B4ULL, 
            0xDDBF638FFD1B4AA2ULL, 0x78FA884E7CBB35F9ULL, 0xB3FB51C43DC2D8CEULL, 0xD23A4EE9D8DAB414ULL, 
            0xE8ACC1F72B738DC5ULL, 0x33EC0EC8EA3FCA05ULL, 0x463F5B31293BE408ULL, 0xED7339EF9CD11339ULL, 
            0x6CF93D0E9B28F6B5ULL, 0x4F573CA843B65AF3ULL, 0x37CE3E39FFFD6572ULL, 0x85A2FDCB9BCC9B8AULL, 
            0xC8F5E594FBCC9453ULL, 0x372BE63F22D8980CULL, 0xD18912DF993E86EFULL, 0x730DB77F5617D58EULL
        },
        {
            0x8DFB72114B124459ULL, 0x048E2FF5B59D19CCULL, 0xED5FA314184E2506ULL, 0x3E6EABFFD1B1ACDEULL, 
            0x56896AC4B8558A04ULL, 0x9848EB8B778A55D1ULL, 0xE0B045AE83C2F4D0ULL, 0xB4C2EACD2E50C11FULL, 
            0x8ECF2DF23AF6A68AULL, 0xB9A386899CE44449ULL, 0x55B91BF971E191F6ULL, 0x0DF192F9F7764816ULL, 
            0x247D57887E14C570ULL, 0xCA4076CEF7332416ULL, 0xE229DE1F66DD8D19ULL, 0x7CC82B86261B0305ULL, 
            0xA7D142F9C1059D76ULL, 0x5C0BFE313219F0D0ULL, 0x82DB3E1D77030AC2ULL, 0x43475D6142BDB1D0ULL, 
            0x9BAFD746A53DE69FULL, 0x9B463CEB9FE8C62FULL, 0x187124989575105FULL, 0x777EFD9502D1DB66ULL, 
            0x18BCA0F5A5FE3367ULL, 0x98F98FD8145A3955ULL, 0x8049F68425E80616ULL, 0xF962BDF392F49206ULL, 
            0xD3BCEDDEB29A0C24ULL, 0x54290D6E8B2FAB2EULL, 0x898A95597DCD2204ULL, 0xBF0674B0EF89893EULL
        },
        {
            0xBCB6D6F205A7CFBBULL, 0xE45E30D92A06C11CULL, 0x16AE1E33CCFE2376ULL, 0x6C3E6620517B0586ULL, 
            0x9C41945651D97AB1ULL, 0x93A4514414CF94A1ULL, 0xB6F521C166A38825ULL, 0x44ECAB4E75A65618ULL, 
            0x2D532C33B04003FEULL, 0xD539019D68C188D4ULL, 0xDC09453F1216766AULL, 0xFD596BE059E61BA3ULL, 
            0x54DB2660607FB090ULL, 0x3EAEC31FA12B86A6ULL, 0x20CE2A5CB9143F16ULL, 0x8501376BCF93A17DULL, 
            0x873F84BFC889DBCAULL, 0xEB8A752AEA059488ULL, 0xCF98F36E634803C0ULL, 0x83F6D5603FD49810ULL, 
            0x2F4FF6FC9089EC7FULL, 0x99DA2810866F8638ULL, 0x8841C8E4221855B5ULL, 0x3CE35F8450D778F8ULL, 
            0xC57C5BD331A51B49ULL, 0x660B975235F72817ULL, 0xFCFEAD96962A9941ULL, 0x7F7FE6A32E525D65ULL, 
            0x22E815E19383C647ULL, 0xA19C69BF5FC65513ULL, 0xB9F1440580233604ULL, 0xF749B456E7331856ULL
        },
        {
            0xB768DE7B94534B60ULL, 0x9D5CC845C4613A72ULL, 0x14F6F54B4099F40BULL, 0x88F360E82938A0F1ULL, 
            0x0FBD792583E5AC28ULL, 0xB75E59EC21D178F6ULL, 0x43D857A505FD738BULL, 0x2ACB387A2550AE8CULL, 
            0x5DE6EBF8073B8640ULL, 0x17F41F5FD0B053ABULL, 0xB487B879A79D8820ULL, 0xDA77577B94F9B56EULL, 
            0x75E1B338C70BECA6ULL, 0x7BAA75E596AE2B15ULL, 0x0F85EBD8BCF4331BULL, 0xD10D751AC49F9F52ULL, 
            0x1C4B0F39F4EC2DA8ULL, 0x8271CF29B527ADCAULL, 0x7B72ED6EC61E5D9DULL, 0x83FBF6F0D3A74968ULL, 
            0x4EDB23F61A514FDDULL, 0x36575383E25CBBB3ULL, 0x4B0577A364CAB15AULL, 0x6B09CC6FE6EF8943ULL, 
            0xC79C4CECC9717F3EULL, 0xCED67C0E3B4A0CD6ULL, 0x9502BF25BF892358ULL, 0x2799F3526E437102ULL, 
            0x03138D1042F7BCD4ULL, 0xA2DB03D579656832ULL, 0xDAB0E5520B6F1A9AULL, 0x15A626B0FF90EA30ULL
        },
        {
            0x72CDE26DA6AFF72FULL, 0xBB15E160D13902C4ULL, 0x2D6504FB4690ABE0ULL, 0x869177A99CBC0843ULL, 
            0xB986B9A7FBF6906AULL, 0x0CD45E6C8E421C0BULL, 0x4C437C464DB686C0ULL, 0xD68531A645AB9749ULL, 
            0xC31E98707F0FB21CULL, 0xD02C06A922F5228AULL, 0x04A789A80CD349BAULL, 0xA86273EDE238F25FULL, 
            0x08954D8EE15D0A50ULL, 0xC3E6F223239DF2DCULL, 0x40A23B86D31CA08DULL, 0xF9543285CCA83AD6ULL, 
            0x9BDDB3D9434A4A9CULL, 0xF903748C17E10A35ULL, 0x7E9EB7A81A81854BULL, 0x83B22388BFA3C395ULL, 
            0xD75558CCBDE67ED7ULL, 0x40B40E74AD0F8C63ULL, 0x4F2A5CB331EB21F7ULL, 0x778F401CB80AAC12ULL, 
            0x9FCE86BF2C4E76F3ULL, 0x8D3D356A213EF3A7ULL, 0xB71CF73BBFB22705ULL, 0xCAE322D6335B470AULL, 
            0x111B19E0410E66A5ULL, 0xBB13F6E3F47A11B4ULL, 0xCE40A5391CFE85DFULL, 0x8274E6F630319E31ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseFConstants = {
    0xDF73617E4AF86E09ULL,
    0xD94C58F378756F79ULL,
    0xE1725F867F6DFC04ULL,
    0xDF73617E4AF86E09ULL,
    0xD94C58F378756F79ULL,
    0xE1725F867F6DFC04ULL,
    0xBBB6DD301D6E2348ULL,
    0xAC42ED1C5289F222ULL,
    0xCC,
    0xCA,
    0xA4,
    0x3A,
    0x72,
    0x32,
    0x29,
    0xDB
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseGSalts = {
    {
        {
            0x2AC0E27C077F6BB7ULL, 0x4E6DFE29618311EEULL, 0x3B1E3D048D258046ULL, 0xC61241F160C556A7ULL, 
            0x259DFA84AC69AB2AULL, 0x6D4EE9B97D5DF5F5ULL, 0x69DC52C42E931165ULL, 0xE82B866A256E5ED8ULL, 
            0x51BE6372A5E9437FULL, 0x1DD4A04184D4D2A8ULL, 0xD14D8F9EB89F9CD5ULL, 0xFB5C0985B576C915ULL, 
            0x18F7081D9B91520CULL, 0x3C49F43D56FC5C7BULL, 0x1FA6915C1D27DBF3ULL, 0xD2BCD81F8DD31545ULL, 
            0xC6A44546A796A228ULL, 0x5461DBEE3696C6E3ULL, 0x0C0FDE053DCEF49BULL, 0x4F31152CFD985CF2ULL, 
            0x75A9055B9CF195AAULL, 0x9AB8DC8C8971BC5AULL, 0x0DF9B3280F6963B2ULL, 0x79DEEA36B27C6B18ULL, 
            0x28304A5F86166AE6ULL, 0x00BE997CED4B3D24ULL, 0x13FF2F13186E84C9ULL, 0xB00FB9B3C78204E8ULL, 
            0xE56A6A813120980CULL, 0xC2AF1A48C767CCB1ULL, 0x5A3D543FC39E9313ULL, 0x5FAA8F8367F7CE76ULL
        },
        {
            0x25C2E0D4E7D019D5ULL, 0x61031787A78F9D18ULL, 0xDDE8D5A500EA357EULL, 0x7AB8FB95D99E7775ULL, 
            0xD708EAFDC2E6635EULL, 0x76B0ED37CF2802F6ULL, 0x8C1812B69592A6FAULL, 0x20230FB8E54E8053ULL, 
            0xC6B68D7B048EA3D8ULL, 0x2D67B17870A083CEULL, 0x0952DE18A02EC537ULL, 0x2D84A6CB179132A6ULL, 
            0x89FD564C9D6E97E8ULL, 0x16F2387EBED711F6ULL, 0x3A4E9A6439403B37ULL, 0xA220B20463300ACAULL, 
            0x45D5F7A676F002DFULL, 0x7A1781710772A316ULL, 0xAEFFEC21B1B75BA1ULL, 0x05A84362A2471A64ULL, 
            0x73039152623BD09CULL, 0x17074AFE8BE6CCCCULL, 0x24BFFB454A4AA923ULL, 0x7049A297FECA5A31ULL, 
            0x9FDF7CFA35857392ULL, 0xA56BB82C36DF7FC7ULL, 0x7305098E8B44BBFEULL, 0xA68E18F8C897D791ULL, 
            0x0235A1FA0736F36CULL, 0xA41A8C78BD64EFF4ULL, 0xA8ACA0DC77D9F42BULL, 0x8D320E4685ABE1DDULL
        },
        {
            0x11F4B145FB92F9DDULL, 0x8519BAFFDA9D672CULL, 0xD123056B20D8B77BULL, 0xE5C02F5E6986EF43ULL, 
            0xA1270FD27AC6CF1DULL, 0xA890A48559E311ACULL, 0x66691275968BC433ULL, 0xA84FF40F2316C9AEULL, 
            0x88F3DAB66891DF93ULL, 0xEAF28D901C823238ULL, 0x96E25DB01C4C5ECBULL, 0x3BEB20D9E76E7D9AULL, 
            0x843288C36158C3DEULL, 0xEF4C6B3BC2D2A901ULL, 0x37D397F44CE25D35ULL, 0xDFDCFC7A15D578ADULL, 
            0x2CACF16678F3E773ULL, 0xB659800D8A3FA47BULL, 0xF8633020ECD970ECULL, 0x223963FADF02F5B7ULL, 
            0x705C4DEC64555302ULL, 0x3E7CAD722F54D1F6ULL, 0x801F0B17681B3F87ULL, 0x64C4B7D2B93992F9ULL, 
            0xC661F36C9211EB89ULL, 0x4174077D1621FCA8ULL, 0xCAF1F7A94EC59488ULL, 0xC04C399FC5FC4006ULL, 
            0x0B43EA904041635DULL, 0x05349BC73867945CULL, 0x08118B28676B2FB4ULL, 0x50A0B1646E1A98C1ULL
        },
        {
            0x8544608A285891ACULL, 0xD5CCF985265044C5ULL, 0x50C35B0D6F22B825ULL, 0x80C6715FD6E1AA31ULL, 
            0x11B05ABA23A6D527ULL, 0xF7FD6C92B90919C5ULL, 0x8E5AD9B53597FCC4ULL, 0x6989FAC455BD2F4FULL, 
            0x1F30EE1F14EEE8FBULL, 0x4709D59084D56327ULL, 0x67D7D078798DA97EULL, 0x4B9DE3376BA92B09ULL, 
            0xE71271AEFEA8FD40ULL, 0x8AC42A735ECA65A2ULL, 0xADE32E4FCB5031F2ULL, 0x824A0723950C1675ULL, 
            0x12C310B5C0609A60ULL, 0x19682483560383D6ULL, 0xC50A8462A8C41D3CULL, 0xB223440CBAD024A8ULL, 
            0x3F471B5FBAF83D49ULL, 0x7321451A74A522C6ULL, 0xC800653714828E6EULL, 0x2177C868BEB7D285ULL, 
            0x76E5628A75B651B4ULL, 0x63AA572406709B41ULL, 0xD6D3A6E1B73D4B31ULL, 0xE304C254A739ADDFULL, 
            0xD4C80999E0F80447ULL, 0x3441441FFD7111B6ULL, 0x899694BCD29B66B6ULL, 0xBF99A2E4683F82D6ULL
        },
        {
            0x6019F204258A7FC6ULL, 0x991AE473DE4ECC48ULL, 0x3639AA56F8E1B5C9ULL, 0x091F03E3481397CFULL, 
            0xEC7B35B5FB2B906DULL, 0x01A5BB4AA310E71BULL, 0xF4F0CB343AEB54A8ULL, 0x5BB656898D62C529ULL, 
            0x137F955980B9063EULL, 0x0D984773A3DF7AE9ULL, 0xFDC38B115C67B5FFULL, 0xB411DCAC30514A42ULL, 
            0xCFEE1DEC3B72601FULL, 0x604092BE452083E1ULL, 0x4518BA72A151EE50ULL, 0x73F6C75E76FFD6A9ULL, 
            0x07DC7337DADC9E79ULL, 0xFB612FE254D0770EULL, 0xC8DDEA0407D534B0ULL, 0x21BC3F6194B262ECULL, 
            0x000698930860B73CULL, 0xA73BBAB182AEFEE0ULL, 0xE2A24A72B27C972AULL, 0x3487170B9B8EF5B9ULL, 
            0x8C813C40AB026D41ULL, 0xA1626E318B27DD93ULL, 0x0C95E21732C1F695ULL, 0x43B0A127027BF960ULL, 
            0x8A0791C9DDB34E53ULL, 0x87EEAC383284106CULL, 0x73710D35B0487E81ULL, 0x2549371C2E6442C9ULL
        },
        {
            0xD3DAEF25B532943AULL, 0xB845FC5FDE084CFDULL, 0x82D7CAAEA9079051ULL, 0x9CEF23C4ADF3499AULL, 
            0xC0545E58CDD28E64ULL, 0xC65D5E7933A7D37DULL, 0xBBFF0BC4FA76C874ULL, 0x65DA9E65451E1983ULL, 
            0xA74C5047B8207C84ULL, 0x2B42AFE17E2B3AA6ULL, 0x023E10C112C3B1DCULL, 0x56EDB74E5CDE82F0ULL, 
            0xE5911BADF3A13A0BULL, 0xF616C8B918479226ULL, 0x6A5205C4F3A639D6ULL, 0x55D7869779A6E856ULL, 
            0x32DAD8D427254D6AULL, 0x437B351B80FA4C69ULL, 0x2160793C6DE15863ULL, 0xBAAE1B08D5525C7FULL, 
            0xAFF8AF5D07824222ULL, 0xF437086660C7DDD8ULL, 0xD06B1C60D4C5A63FULL, 0x2C6B768C8FFDE581ULL, 
            0xFCAF54EE4F8CD49DULL, 0x792921A515F6BDFFULL, 0x51308B57CF559EBAULL, 0xEE6FC279AA99FE67ULL, 
            0x2C84FACB970B9F23ULL, 0xB7197E8F8485EB11ULL, 0x7A4CF61516E8A24DULL, 0x76CF6E0B1AC471E6ULL
        }
    },
    {
        {
            0xC2F8922C13451680ULL, 0xBC22150CF4D0EDAAULL, 0x5A22513E87FBC088ULL, 0xF17328AB35BD8AC1ULL, 
            0x31DF6334C987F5EDULL, 0xC41D8BF0C6BAD8BBULL, 0x94DF609E67CB78E1ULL, 0xED69452FCA45BA07ULL, 
            0x7C15E8CFF25C895DULL, 0x909B2F4A789D40CBULL, 0xE79CF034202D2A29ULL, 0xA2A498DA29A0987DULL, 
            0x0402DF887A25B5D2ULL, 0xF8DF8294E85AB869ULL, 0x4B1E41D931582E72ULL, 0x7DE133C18873490DULL, 
            0x77D9B2F8E8106312ULL, 0x4BAE5C9FEB84D2C6ULL, 0x9357FABB7613437BULL, 0xE8DB1A790FF873A7ULL, 
            0xA07FB8E474AF2382ULL, 0xC1EB19237A37E39DULL, 0x5F0051865EEE8320ULL, 0xC5CC3402A3B55B3AULL, 
            0x7037EA071B2D5E95ULL, 0xAB47673D36B77248ULL, 0x027847BFD4671286ULL, 0xCAF37F74118129C5ULL, 
            0xFD7804903A14390DULL, 0xB5755C28E478C664ULL, 0x51DD6CE5A7900F51ULL, 0x77BE41722EB39258ULL
        },
        {
            0x904D79663F8C8DD7ULL, 0x14486BD276A40B6FULL, 0x587FCD43C24E57EAULL, 0x36C5EB4ECDC93218ULL, 
            0x1BC704CCEA6CFE56ULL, 0xB5D3AA64BEB3CEBDULL, 0xC65A3008A509388DULL, 0x07DC0AA89B9AFCB3ULL, 
            0x3E7085793A7D53F9ULL, 0xEBFE76B078942EE0ULL, 0x286DB66219A97AF1ULL, 0x967F0137B9B6CAB0ULL, 
            0x19B7013DD77530C4ULL, 0x54B69FB3D9A43573ULL, 0xD1CBD7FE2610223DULL, 0x5A476A5A71F4A708ULL, 
            0xC36D6243B30839F3ULL, 0x3666B086EECAA7B6ULL, 0x350615E13EDE22FCULL, 0xF7E188B23052BF1EULL, 
            0xF31443924FEC3F33ULL, 0x924C7759FECB5268ULL, 0x216055D5C85A6256ULL, 0xDA08E502B71983D8ULL, 
            0x1DF53ED1151098A7ULL, 0xFD6D81B5E7B5DBC2ULL, 0x748BFD698A87089CULL, 0x19618FB853C08350ULL, 
            0x2A61572E09483C9EULL, 0x66C5F19ADA42B741ULL, 0x92AB53FED6F5F8CAULL, 0x5A8290CC170CB53AULL
        },
        {
            0x2359C49DB585CAD3ULL, 0x927744E4A6FD47ADULL, 0x7DBBE4549988A75EULL, 0x3CF6CB9F7533FF6CULL, 
            0xC0CDB75817C5B30EULL, 0x57757D42CAEB697AULL, 0xB7E4190342A27128ULL, 0x295B3885018464B3ULL, 
            0xD5DA25E81BF7A278ULL, 0x37B81909B9FE89E7ULL, 0x301C737228975203ULL, 0xC7EF13D42090D7A5ULL, 
            0x36C6A9B71629D824ULL, 0x5A4970BB2CC4F666ULL, 0xFA18F95232C8F6B9ULL, 0x51CAD26E584B73D0ULL, 
            0xA6D1162285422851ULL, 0x58A4970CEAF65DE9ULL, 0xCAD25CF76ECFDDC6ULL, 0x7AF92A03893739C6ULL, 
            0xC9818AE0DE1D91B1ULL, 0xA03A7E675B9BFEFAULL, 0x5E56BA847911C715ULL, 0x4A0C253FCB6E2101ULL, 
            0xB8F75404839A528BULL, 0x745FA8F99BE4E746ULL, 0xE38E8CF0BC078C0DULL, 0xFFD1D823B2EECC1FULL, 
            0x88B3D094E5514B8BULL, 0x32B84FC3077689A0ULL, 0xC6211261DB6E95EAULL, 0x63953CC0B9CA52E6ULL
        },
        {
            0x19578BE3D3EC448AULL, 0x913606DAD40BD591ULL, 0x15F3A7D1D8E1B497ULL, 0x6DC78E45343629D1ULL, 
            0x9F84A7609B0BDC2DULL, 0xC21D1D8B124A6432ULL, 0xC3606C00E9307DAEULL, 0xDF207EAED284796CULL, 
            0x5AB9E9DC2A0F0EB4ULL, 0xAA9EFA7F0A222425ULL, 0x8E25EC98241CE73CULL, 0x33F5BB1B10293B7DULL, 
            0x55D82E02A7F1EA77ULL, 0xD3C503D2007FBF57ULL, 0xAD04720BBCE537DEULL, 0x9ED135B812EEB79AULL, 
            0x4F561EA72EBA03E5ULL, 0x00DBC5C000BD2336ULL, 0xD69CBFFEC69E5A87ULL, 0x99E266A2A6237DA9ULL, 
            0xCD62A6580D4A8084ULL, 0x14187573C90321AAULL, 0xB3D3C99ADC50B2D1ULL, 0xD9A8689E49ECDAB8ULL, 
            0x60CA4B07E94D93A5ULL, 0xC2E05FA7AC1A25DCULL, 0xD54271C0BE76D058ULL, 0x183567B694B33683ULL, 
            0x0568ED4AFD547A95ULL, 0xFB81E1D240403D85ULL, 0xF3E3396A17263A3FULL, 0xA2B3C7BD2A0F76E7ULL
        },
        {
            0xD7A6D4DBA368D41BULL, 0xFB70CA65FFCE00E5ULL, 0xC0824F10519F57A5ULL, 0x63172C13EFE9B35EULL, 
            0x4087FF52F2D3B4B6ULL, 0x1444D1021F8CBC28ULL, 0xB34C788894470444ULL, 0x67E592D9888DAF57ULL, 
            0x0F5B1D6F0F5D2DE0ULL, 0xCD778F29BA877C2BULL, 0xD5DCCE80AECCF993ULL, 0x02A49441499D90D4ULL, 
            0xE3BAFE806ADA37B1ULL, 0x32FED6E3D6303EC2ULL, 0xCB36313F9BDDAC53ULL, 0xE349CCE1495B419AULL, 
            0xD3272C1F1BF8F020ULL, 0x97AEDB8056356D85ULL, 0x91216F030C1AA6E3ULL, 0x2234A5804B31EF3FULL, 
            0xD789D089972B3FE2ULL, 0x23F989E4C245148EULL, 0x50F9BD3C8C3B5E3CULL, 0x499E8820A93C850CULL, 
            0xD9FE6BA90BE6AF00ULL, 0x2C8965B713EEC1D0ULL, 0xAF64EA5925D48454ULL, 0x0C131FBD16FA2452ULL, 
            0xC92567B7E2D58E0DULL, 0x67373C5790E7ADFCULL, 0x7F231AF193112C5CULL, 0x79670EE741CEECA0ULL
        },
        {
            0x6A3F9B1C8B4CAF80ULL, 0x17D5B94C965F96FFULL, 0x095A84737A9FF3CBULL, 0xA85A30393FA5CC98ULL, 
            0xD0017205ABE9DCA1ULL, 0xFCA0950215D2A31EULL, 0xF3A438D101C560FAULL, 0x4A2A194EDD426FCBULL, 
            0x735D25B30E06FD4FULL, 0x05C6CEF63B311A21ULL, 0x0D560204DD854074ULL, 0x71491E4D6A0E8719ULL, 
            0x5E2F5D8FE7F768ABULL, 0xE91ACB4BB6C4FCFCULL, 0x2B92ABB9D7F4FEBEULL, 0xCEECD55CD98E8FF6ULL, 
            0xAFC99F759C56FE0EULL, 0xB0BBE2FD6DEF4A14ULL, 0xB383726F68C60F0CULL, 0x0D4604DC31D39CA4ULL, 
            0xF44422D01EA30AD8ULL, 0xE4B79FC73EBDF2C7ULL, 0x62E3F6D6A017F0D4ULL, 0xEB01368441E894FCULL, 
            0x90E879285638DD11ULL, 0x5618C7F3D4FD7362ULL, 0xE5796315A6D99036ULL, 0x73C54EC25F6959B6ULL, 
            0xB22C9D0291AA1278ULL, 0x7099924DEC6690D6ULL, 0x6D130C74B73ABCBEULL, 0x7ECB17B28B0E74F2ULL
        }
    },
    {
        {
            0x9AD7045F321BDB87ULL, 0x2FADE4C9CB227E63ULL, 0x93438C74ABBC85DDULL, 0x540D1E5BA3AFC70CULL, 
            0x16E42E8A09F960B9ULL, 0x4C435698F1193AE7ULL, 0xF34D5EA730CADF44ULL, 0xBFF54373C7C719EEULL, 
            0xCB0647B8E103B9CBULL, 0x487F6117909E3CC7ULL, 0x70385472C8B268FBULL, 0xAB7A31AFCCB52F1BULL, 
            0x0A91508D9CE13E77ULL, 0x7BF6E1C0764E0B5DULL, 0xEDAF26B3FE955682ULL, 0x2CBE396EAB4BD0FCULL, 
            0x4181DAABE1796CBAULL, 0x530196B510650C10ULL, 0xF0F59594DFF6BD60ULL, 0x4C7D8287FEB37BE5ULL, 
            0xF946000765EE0642ULL, 0x7010C2348419F2D8ULL, 0x60F474FBD9923821ULL, 0xF4015608E7686651ULL, 
            0xD95C4A304C2DC09FULL, 0x3F8513C0C7AC7B24ULL, 0x2B59AC2FB32B797DULL, 0x849EAB4B3FBBF64AULL, 
            0x1D0E7FB4F9C5E19FULL, 0xF2982A6531A9A31AULL, 0x62C43627EBED7696ULL, 0xA0F51E97F86265A6ULL
        },
        {
            0x491196B9A09252C8ULL, 0x3F04FC12A756F17DULL, 0x833B20774DF8A2E2ULL, 0x84B7D5EC44C603F8ULL, 
            0x73261074887EC821ULL, 0xFF69C58E086897A0ULL, 0x2A8857FD2664A9D1ULL, 0xD7F16559091FC3B5ULL, 
            0xEB5F0069ED1514EBULL, 0x70651062E3010E3EULL, 0x9CA7C0E78CD8B5C6ULL, 0x7638C4AA1E35DD3BULL, 
            0xE7BE8EF8CE0E7071ULL, 0x56666A4D8192FC3CULL, 0x4A29E353DC96E6A2ULL, 0x85E560D2AE94B727ULL, 
            0x92EBF671C09B1919ULL, 0xC022740896CC3167ULL, 0xECE99CBF63D35B49ULL, 0x414F2AAD4E44C24BULL, 
            0x5F2B0CA7B1B35368ULL, 0x3A0F44928633AED4ULL, 0x7E745ED1241CB7A0ULL, 0xAE290C58EFDABCDFULL, 
            0x7D0FF74FFD8F3010ULL, 0xA1B30108D29358BCULL, 0x453B88F88186A17BULL, 0x5920DF520460C5BEULL, 
            0x569C4E04686D55BCULL, 0x26C3E6EA43D39EACULL, 0x03FA753071607F98ULL, 0xA0617C8DD2F03033ULL
        },
        {
            0xA3BE4CAABB175722ULL, 0x41C9812C45E7E25AULL, 0x9D2E3E22F2A5888CULL, 0x0E3D99BA9AC22358ULL, 
            0x23EC465AD6B701EBULL, 0x998047F08AC4522EULL, 0xA7F519D850379C2DULL, 0x663ACF2C10F2A76CULL, 
            0x0D649283166FC7AFULL, 0x0ABEB4FAC4AC9CBDULL, 0x74FDA6D650A974D9ULL, 0x8FA77E8CA3C5AE74ULL, 
            0x1B605A16487D5158ULL, 0x9195EA4DD8E12B0FULL, 0x5E4DD62B8E6B58DFULL, 0x4A43944714B874EEULL, 
            0x55D08BF923627BCEULL, 0xC4B928302808A41EULL, 0x859C502EAA353F99ULL, 0x951346C4F1F9A371ULL, 
            0x0F173A86B1414958ULL, 0x5D86B9EC64E79A54ULL, 0xA16C9E07DEDFA6BFULL, 0xC62652775035C1ABULL, 
            0xCCAA580CCCF8B361ULL, 0x8970595D30BFDD6BULL, 0xBE853017A7BBF4A6ULL, 0x44D5999FB2BEED3AULL, 
            0xFC682F3CDD9F13F7ULL, 0xE6A157F90F01831CULL, 0x0D301AE2975E7E00ULL, 0xF2597C85B96ED605ULL
        },
        {
            0x0FE62EF5B73DAAEAULL, 0x8B56578198C016B3ULL, 0x3EC3E9B33BD23189ULL, 0x7341120000860279ULL, 
            0x588A797511860E94ULL, 0xB0E12B0DD65A75F5ULL, 0x757A3BFE23196EE5ULL, 0x61B4542FFA8B7113ULL, 
            0x9B0E750D4F93F738ULL, 0x8009A9FE0F0B486CULL, 0xD75AF64BAF12C0EBULL, 0x7874F241CAF2926AULL, 
            0xE9BCC8FC9888271AULL, 0x5D77FB43C96462A1ULL, 0x95784C6E9D3458E6ULL, 0x97EFE728346FF406ULL, 
            0xE3B837AC4C684741ULL, 0xA60B39D93B93778CULL, 0xB8537765FF43EA2CULL, 0xB7AFDC3DA6DA39E3ULL, 
            0x48755167DBE6D26BULL, 0xF68510B65D5F2FBCULL, 0xE40CEB5254880D45ULL, 0x906B48607FB0AEA1ULL, 
            0xBC289D07E741D130ULL, 0xB8AB1E8530F70A3DULL, 0x70EFA1582DA539B8ULL, 0xF0A4049AC7E0572CULL, 
            0xC91CCF20609F096CULL, 0x954B6120FAB5F8FFULL, 0x62C8F4CF85646FD5ULL, 0xA3AA8D5933B240AEULL
        },
        {
            0xF5032B36AF1CB8EBULL, 0x095A46096353EAA3ULL, 0x4CBFDF4AFAC3455BULL, 0x75EBB64E2A9CAC31ULL, 
            0x62CBCC922BDA6CC3ULL, 0x82F9892E57017C33ULL, 0xD8902BDB147282B6ULL, 0x45FCB633F57FA0DFULL, 
            0xBB458A1C2405B37AULL, 0x0EB43C8256A88D59ULL, 0x3CB67C4E71DE5C5FULL, 0x7D7D4E5B20C3C1BBULL, 
            0x92050B5A46E5008DULL, 0x1E70D1429FA3B1EBULL, 0x42EF0D8541B6D466ULL, 0x48F512007CC4BAB4ULL, 
            0x4416EBA8518D8537ULL, 0x06256E2A54603E48ULL, 0xD0E1DEAA4D6D4EC6ULL, 0x893CAF0848722D62ULL, 
            0xF653E0348422E2BEULL, 0xE1FF7C2C7998DC5AULL, 0x5A91D650FB3E3FD2ULL, 0x8B5D1D40AF7F30C3ULL, 
            0xC8AC29C772102B08ULL, 0x43CF7391F8AE119FULL, 0x354D8589510FA8E2ULL, 0x522D2AF5031091A3ULL, 
            0x409F0A892AE91DB8ULL, 0x9D48FFEB357EA721ULL, 0x56AA6E7A105265C8ULL, 0xE91C77C5D5C72147ULL
        },
        {
            0x4F1536CF3DAF794AULL, 0xC0B2845AA9FCDB27ULL, 0x0994DF4FE17B7AC8ULL, 0xAEFA35B4D72F26EAULL, 
            0xEE1FA39206C80948ULL, 0xD4D199BB480369F1ULL, 0xE26EC62B1096B6BCULL, 0x1FC56BCA7E0B5464ULL, 
            0x16937EB39E1E7664ULL, 0xCB7B55C79CAD425FULL, 0xD6BEB66492EE3533ULL, 0x82B26B90BBCDC7D8ULL, 
            0x4E88911ABF772F2AULL, 0x120638534182FAB1ULL, 0xAE8D91A6A893A67AULL, 0x33252A2B76402FF7ULL, 
            0xD9D6EB1AC1AD21BFULL, 0x62E256672CF46DA6ULL, 0x9E33E2B35FB3FD33ULL, 0x140EE91FF74B8945ULL, 
            0x7F24959D69B72C05ULL, 0x1ECD5E785AE80DDDULL, 0xE0F5B93E86AAA59CULL, 0x0F7D2E8DB1F52FD0ULL, 
            0x9C859196FDB79726ULL, 0x0E8BFC8D57EAAB66ULL, 0x8DEB8BCE120ABBBAULL, 0xD34C9EF2A9E65041ULL, 
            0x6EB667FD199DD138ULL, 0x2B462A5E67857A29ULL, 0x676FC224A637EC7CULL, 0x0BFD06D48A0C690FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseGConstants = {
    0xE47D77FA440E5ABAULL,
    0x4D6EF95FF54523E6ULL,
    0x9074960FE890D830ULL,
    0xE47D77FA440E5ABAULL,
    0x4D6EF95FF54523E6ULL,
    0x9074960FE890D830ULL,
    0x8D66AF0E227F9C6AULL,
    0x0E0E51302B50D271ULL,
    0x73,
    0xBC,
    0x1A,
    0x5A,
    0xE1,
    0x92,
    0xEF,
    0xDE
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseHSalts = {
    {
        {
            0x103C32BA59ABD758ULL, 0x895277F0B797EC43ULL, 0xD2D735B4F30CEA12ULL, 0xC12816B59A8A51D1ULL, 
            0xC4723668530EC3F5ULL, 0x482122720F55741CULL, 0x446087A3308653FFULL, 0xA216E60D2BAFD3A5ULL, 
            0xBA6E68FE9CFB3A6FULL, 0x511F6E9765748D65ULL, 0x67D190A4A1D7D36EULL, 0x7153778529845880ULL, 
            0x7A21D56AC9CBDBBEULL, 0x5A9ECCCF771781FCULL, 0xD2BF8586F369BCB9ULL, 0xF8DBEF037BF1FB48ULL, 
            0x562DDEE54463EBDEULL, 0x087D328887EDDE63ULL, 0x888D3A82C45BEF67ULL, 0xC8FD4CCE1DE2C1DFULL, 
            0x6C5E7BD394B99B4FULL, 0x50A4C3B879BE308EULL, 0x521CE40B2362684CULL, 0x90DF1C7B9B84E075ULL, 
            0xC06CBCC2E086F6CAULL, 0xF2C5056E62B24D62ULL, 0x9BE9FA05443C776DULL, 0x6B4A061BF8C3F472ULL, 
            0x6FD40764E4646A98ULL, 0xDA998B95167EC4D3ULL, 0xF5539A161CA3ABA2ULL, 0xFBBD5D61B84FE8A4ULL
        },
        {
            0x2D5A9E1B08F1A107ULL, 0xF6300F4DBE6F6479ULL, 0x3F2BCC5262606062ULL, 0x5F813C699D919CD0ULL, 
            0xE810108FA5579265ULL, 0x973007ADF39F2608ULL, 0x729CE54CA386180CULL, 0xCF6D295A0E55F166ULL, 
            0x4EE3D7E366AB621EULL, 0x38E3B0B5A6283F8DULL, 0xB37AAB057CE4B6F4ULL, 0x0B77DBE3F6BA2FE1ULL, 
            0x1EF1AE1E77206A6CULL, 0x99A084FA24966735ULL, 0x0661D2450AFA40F8ULL, 0x904BCCB05D529E10ULL, 
            0x77CB3612E67C3DD4ULL, 0xBEC536268826AD7BULL, 0x09998002FB50B732ULL, 0xF0AED6AA70608499ULL, 
            0xE2F382F863F66447ULL, 0x03AF55A3A1453A5FULL, 0xBF02733D6A9BE7A7ULL, 0xB22B11A76FE8F034ULL, 
            0x8440DA0AB57FA0A4ULL, 0xED87E1D4941FC9D0ULL, 0x39F5CCDA35444926ULL, 0x581F2BEA391E7CDCULL, 
            0xB934B9A61568B682ULL, 0x1EC79AEA1AB36CE9ULL, 0x1A73B8AD5EC2DDB4ULL, 0x648E7BD5A5046ED1ULL
        },
        {
            0x6B655A7C25788BABULL, 0xC7BCA8EB45A8306CULL, 0xE28865289884C68DULL, 0xC99351DF3FB52AE1ULL, 
            0xEBA7538E3CCB44A1ULL, 0xF4E7AA56240D898EULL, 0x8DA479ADC956CD24ULL, 0x94FA11DF85E5A5ABULL, 
            0xD9FFBBCA86CC42C8ULL, 0x1E69BCD075E2C49BULL, 0xD989B0B97F1BF035ULL, 0xFF4D55DDAF8A5B3CULL, 
            0x98ABBE7411EFD4C8ULL, 0xB8C4358EDBE18E87ULL, 0xCE591CD0AD613E17ULL, 0xA327B3F4052660EEULL, 
            0x2970A9CF28461DA3ULL, 0x33C61118877EFFEDULL, 0xC3DFB87563BCD101ULL, 0x2FF4D5B62B44A764ULL, 
            0x7744D65483DA1213ULL, 0x476488C70C2C842BULL, 0x7E43D492B357ABDFULL, 0xFB1674BB5C0D16D4ULL, 
            0xF74B3636E9925DC4ULL, 0x6A644A45592C6294ULL, 0x113637BB1CF3F6B7ULL, 0xEB0033BCDAC262DDULL, 
            0x604F1723A7C5F5C5ULL, 0x891C403F3202A44FULL, 0x83EC363F29262F69ULL, 0xD3CF1B74B802F49EULL
        },
        {
            0xBB0837E7A3B97041ULL, 0xE8C4E4F93C5965FCULL, 0xC6589374C66D15C2ULL, 0x0689A2E08D6260C1ULL, 
            0x612A9C4E4FADE6F7ULL, 0x5F3005C011A846CEULL, 0xE933BD7B0365B178ULL, 0xA217E239AF1F4571ULL, 
            0xAF8D232F119E5E07ULL, 0x9755BE92B998A93DULL, 0xB61ADBC67B424D9AULL, 0xD4215DA74ADDEBB4ULL, 
            0x1E1E906587D0D47FULL, 0xA747EFA7B1E75AADULL, 0xEB1573BE54C93C62ULL, 0x5D92B401DDA0ABF1ULL, 
            0x97F399BCF56EE85BULL, 0xF3F4F677401BB81FULL, 0x4B897D70203D9641ULL, 0x8B503E52E326BC7EULL, 
            0x32B1996665F89DF0ULL, 0x196FE0F5B91B6960ULL, 0x418A312BEBFFD439ULL, 0x74AB0C1BC01468EAULL, 
            0x3D4765E2531CF256ULL, 0xCF09EA0AC2BE765FULL, 0xE06DC53CD3C6CE05ULL, 0xE81D2A77342457F5ULL, 
            0xE37FFD9A0D66204CULL, 0x0C028EDEEC40F831ULL, 0xECB6BD2AD37FEECAULL, 0xACB32467C06BDDC0ULL
        },
        {
            0x8BDAD1EDB6CA47E2ULL, 0x9B8FE4552E664CA2ULL, 0x701A4749023C5200ULL, 0xDE20ED1FA0FD5E9AULL, 
            0x5797F268CC72DD2BULL, 0xD8FEF49C31FBABECULL, 0x4608030DBF3319B0ULL, 0xED2DE32565471AEFULL, 
            0x869D33B16C521C89ULL, 0x5D2EA8F2F77C102BULL, 0xAA4962A59F2B87D1ULL, 0xAF57E9069978CEADULL, 
            0x42B30CBFD9F573D8ULL, 0x82D5A18FCE8ED117ULL, 0xE0642AFDF47B747BULL, 0x604ACDFD2A8C5926ULL, 
            0x0AF0C2C3FB30CE93ULL, 0x4A961995504A4FC9ULL, 0x8C1A32851EFF9C47ULL, 0xA9F52F38FF12E32EULL, 
            0xA73113CADD62F480ULL, 0xB8F5E6B018AC7285ULL, 0x23902E70DF0E6B43ULL, 0xA26CE7DE82EDB57DULL, 
            0xB2069568C78CEF2DULL, 0xA3DCAA4EE8EBD617ULL, 0x15B3BFD771622EA6ULL, 0x3E1884AE41B8357BULL, 
            0xCABFEFB244ABBAADULL, 0xDDAEB1125D1E0831ULL, 0xCB90FC080E99448FULL, 0x3D8FC161DFAB7F85ULL
        },
        {
            0xAEE523675F8A8D3BULL, 0xC2B4487854F9EE08ULL, 0x4895871D6B09D3A5ULL, 0x60F854DE09AB9AABULL, 
            0x16CFD8ED19C76398ULL, 0x82126F7E582AE623ULL, 0xE26D3EA62B5FD6ADULL, 0xB74F64B0178E0B9EULL, 
            0x31F1320A473F9B41ULL, 0x2E5BC6577EEDE6E4ULL, 0x4A7110877298CE3EULL, 0x69C4A43260B53F8BULL, 
            0x7D4C8677669569EEULL, 0xFA0785B88703727DULL, 0x09458CE7127466C0ULL, 0xD8FF4AC827FAA47DULL, 
            0x2DE4D45478E5D4B6ULL, 0x6AAE87F7FF3DF39FULL, 0x8E7FF54AB91D8EE9ULL, 0x2A12E7AE59D88D2AULL, 
            0x8A843DE137905612ULL, 0x50C1B3BC13ABB28DULL, 0x8DC0BB36365F33EEULL, 0x8A4F1E9210BB693BULL, 
            0xC51E09D9C215EF22ULL, 0x7F1D400AAEE6186BULL, 0x9102ADD6D5B5DAAFULL, 0x987AD158F009072EULL, 
            0xFBD49B30BB7B188BULL, 0xFD138F4AF6911FA9ULL, 0xE0215F8FAF11AB12ULL, 0xA195F7489A6476D0ULL
        }
    },
    {
        {
            0x5DCAC1FAD60E71AEULL, 0x60365C2FFC877197ULL, 0xC12F391D64E4DEE5ULL, 0x719BB5770F1490BEULL, 
            0xD32C3BB3532AB58BULL, 0xA2D858BF2601BF7DULL, 0xA32C81BEFB8E8398ULL, 0x6A00DBA26D186C6FULL, 
            0xCB212893F88D5E4AULL, 0x93960E4B5F65DE1AULL, 0x7A40D6131C244F61ULL, 0x9300A527CD83A06EULL, 
            0x5589D6F884746ED3ULL, 0x22055E786A099BF3ULL, 0xC207546A2C8BDC2DULL, 0xFE6E128927CB0D43ULL, 
            0x16F42DA2A9CA1411ULL, 0x182F585BD2F9C803ULL, 0xB82CA91B58FA4255ULL, 0x5A5607A088C8DE85ULL, 
            0x1DD738ED7E42F84FULL, 0x6A8DDF4EC9EB2BF1ULL, 0x5D3B77564E247574ULL, 0xC6DBB90FE98F6A12ULL, 
            0xD6E2EFCED466F0DEULL, 0x4E90597A7FEC8624ULL, 0xEA366B27E53497A0ULL, 0x0D97D0232482DDFCULL, 
            0x480C922601D7A28EULL, 0x182706381C22EE0EULL, 0x84A4AC4BB0F58E9CULL, 0xA1FF27160EA48CF7ULL
        },
        {
            0xD95E17F3C4143B2CULL, 0xD5561CB11815D060ULL, 0xF7EB57A7F25AF757ULL, 0x211A03FF5E2BF28BULL, 
            0xAD323C6FEA1B0666ULL, 0xB6C88EB0913E8F2CULL, 0x41F5AA2309A92E3DULL, 0x708AF8B15C84726AULL, 
            0x17101C9C98DF4078ULL, 0x6E7B02CE1E800675ULL, 0xBB6993A4F879D62DULL, 0x4900989F8528594DULL, 
            0x50A101C7521D32EBULL, 0x30B6EE477AC103C7ULL, 0x8963CBA3745688E9ULL, 0xFAD04E18678ABDBAULL, 
            0x670CE709ED2A6C20ULL, 0x7265E5BB2DC0E487ULL, 0x89046A7C5ADE7E1AULL, 0x5DDA1BBC8D1F084AULL, 
            0x1A8100DD4BEFA735ULL, 0xFEEEE9546FFC9212ULL, 0xB28A980C76247DADULL, 0xBD77B17D442C1E56ULL, 
            0x25E2F13AB3A8770AULL, 0xB5CAE2A2EADA65CDULL, 0xAF495C818EF7831BULL, 0xB58092469241588BULL, 
            0xC0EA51732D96A496ULL, 0xBEBF8A98601958F2ULL, 0x1CFED18F6AB74BAAULL, 0xC55322CEE83BBB54ULL
        },
        {
            0x6405DF57F71C2372ULL, 0x5956433B4E97D4AAULL, 0x350F5FBB443B36CAULL, 0xBDCEB81F6B76933AULL, 
            0x16181E32E5EEF3FBULL, 0xAE979735961691C1ULL, 0x635DF93C2F56F14EULL, 0x3869A5553549165CULL, 
            0x2F19D847AEC1FA5CULL, 0x132509E1A975418CULL, 0x3E7D0284CE041BF5ULL, 0xF4DF0C17A6AA2EF3ULL, 
            0x19B2970A6C954386ULL, 0xC5387AEC8B993913ULL, 0x31F6DD9629CBDA78ULL, 0x48D9365023D3F69DULL, 
            0x4817C118920025F3ULL, 0x5BF090DC75EEDFF6ULL, 0x0CDFC92A20172011ULL, 0x7B25A3FA147C5A60ULL, 
            0x3C93C1807F9F7B05ULL, 0x971B9C76E8DB49B1ULL, 0x69BD53736E1C92B6ULL, 0x26FC1C7BB0762746ULL, 
            0x1FF4AE76DCEC2980ULL, 0xC25379B3B7556E24ULL, 0x4FF421D33B5A124BULL, 0x9C761F2F87CFF296ULL, 
            0x7995FFFD18984F33ULL, 0x9F515ACDB7EE8DFAULL, 0x010244E063537381ULL, 0x0B5AB06D175218FEULL
        },
        {
            0xAAE6D5A2104716A2ULL, 0xBB7CB959ACE170CDULL, 0x7F18F606F6411D61ULL, 0x7D223A02F575452FULL, 
            0x6264F4D04161790FULL, 0xBE7945FF8E58F282ULL, 0x69C02865F3168412ULL, 0x468A42D65873612AULL, 
            0xFF83A9636DB7E65FULL, 0x3BE62D24431095CFULL, 0x100DB805B1B4A57CULL, 0x5DB686DD2277DFA5ULL, 
            0xF9FD5BE85692428AULL, 0x5B637698148292E9ULL, 0xFD20755AA292785EULL, 0x181C00E63A796372ULL, 
            0x9DFB4F8211D3B0ABULL, 0x873E86A53F900429ULL, 0xA54F722451970AEDULL, 0x3BE13F723A7A90CFULL, 
            0x7EB6D5D400F76741ULL, 0x0AFB0C6B9BEEA490ULL, 0xF7546D78EA4C1644ULL, 0xE70F43997790B09DULL, 
            0xA748FAB763B24B4CULL, 0x3DE47FD118EA7FBCULL, 0xBF2A9E5ED8FA0599ULL, 0xFF95021675D05790ULL, 
            0x1AF5116E91E8F22AULL, 0x6E5CE9A35985C50AULL, 0xE83586B6ECBCC780ULL, 0x74A3662A48D6F9F8ULL
        },
        {
            0xB10FBE9CBD81C64CULL, 0x9803703F6E70C080ULL, 0x755811CAEB69F96DULL, 0xF199D405168CFDE4ULL, 
            0x91368F31C9C4FCE1ULL, 0x13FAFEE09B342D8FULL, 0x6AD186D2FF768BC6ULL, 0x1C52D65F571BF462ULL, 
            0x15458483C4A78F70ULL, 0xEFE8749ABFAF38A2ULL, 0x6B7CDADA102805CAULL, 0x8704E5E0D4216E2BULL, 
            0xE42C0243135831D0ULL, 0xE31D4409920FEA0AULL, 0xF6E236F1B054E327ULL, 0xB77F67D2B00203F7ULL, 
            0x066A83E9F31ED185ULL, 0xCDED76BECE21AB0CULL, 0x48777BD5282BFF20ULL, 0xF5D564884246A642ULL, 
            0x0907777E741A8FCDULL, 0x3EC877A36BDC616AULL, 0x2ACFE6ED59F29F83ULL, 0x97CBF884CC07E5BAULL, 
            0xA18C021A97FAB660ULL, 0xF08927850A9C89DAULL, 0x0480C9D0217FDBD3ULL, 0xBC32ECBD6DFE047AULL, 
            0x5706AC3D6C97116FULL, 0x048CE83D3136CE0EULL, 0xDFF6473A6EBE9983ULL, 0x90CB8EA2308A6D6BULL
        },
        {
            0x870C3345FC75CA26ULL, 0x90225DE867C041F4ULL, 0x0EFF9C556921040AULL, 0x69C20E3B875E25E8ULL, 
            0xB9DADF2B390FEB67ULL, 0x90CF5F7738E2C75AULL, 0xD7E1AD2366FA06D6ULL, 0xA9B78E7D961BDCCEULL, 
            0x403B73FDC10BD624ULL, 0xB81427151EA97619ULL, 0x8ABA4B443889C5DAULL, 0x33F7BCCF1D7C12FFULL, 
            0x00AE8F5951EF633AULL, 0x77F7E9399C3EF548ULL, 0xE234800678C9C2A1ULL, 0xC844A72CE4F0B3BDULL, 
            0x39ACA52BFF21AC63ULL, 0x4893FDA607BA5C87ULL, 0xB1ECACE2344D2AEAULL, 0xD5D4D108BC5F4F66ULL, 
            0x7D7C242BFC197E78ULL, 0x1C6C3305B865DF69ULL, 0xA07FF9CF970084FCULL, 0x173663C173526F0DULL, 
            0xEBAD2DA8A54E9212ULL, 0x3C569E85499E64B0ULL, 0xB57415756481ABEDULL, 0x61EA589273C47BC8ULL, 
            0x951D298B2FC9BF4DULL, 0x885373ADF616B809ULL, 0x3A2BEE27AE8AF197ULL, 0xA89402A67D51D340ULL
        }
    },
    {
        {
            0xA482CCC1AE9B8947ULL, 0x87D37301619831FCULL, 0x44C1BCA6A92CC607ULL, 0x0E193642D061CC91ULL, 
            0xD8B34E5B8AEE3AC0ULL, 0x3E41BC2BADB2A082ULL, 0xCF0924B5EB1D3472ULL, 0x5AED4676D034CCD4ULL, 
            0xCC448CEF529DBDE5ULL, 0x05B779DCC674C618ULL, 0x966156923A5CAD57ULL, 0xBAAA943D2AA7B51CULL, 
            0xA910D91C22E4B50CULL, 0x07E5B7C0BBABE312ULL, 0x7A12A3F20A5A6F29ULL, 0x7914320C74D6B88BULL, 
            0xB00C14B5BF9E0B22ULL, 0x50F3511A9EE08A41ULL, 0xD803CD7B1F658CF5ULL, 0xCA3997CAAF57B9BAULL, 
            0x6BAC8F259EDC1CF0ULL, 0x087984C17EDD4429ULL, 0xD16D276D138BA74CULL, 0x0B46257E378804E2ULL, 
            0x8149F98EA171A78BULL, 0xE23278DB67BB36E8ULL, 0xC6B35C62F6808EFBULL, 0x9BE0C7ADC7239F06ULL, 
            0xCBDEEDA9FFAA4CA5ULL, 0x1F8B627EA7FF1147ULL, 0xFF76DC6DA2A9CACFULL, 0xC7B9AE52F04B6396ULL
        },
        {
            0x0860963B6F8530A8ULL, 0xB4FAF1DFCB4EED4EULL, 0x43D19967B054D511ULL, 0x73EC78C26DAED6A9ULL, 
            0xBC5EE15A59A0D1C8ULL, 0xEE276D7F22A9808DULL, 0x14548E86E87A5E8FULL, 0xEF4EFD2871E3B13CULL, 
            0x4623A6C07CA2B1EEULL, 0x64D4CDA9FA83FB53ULL, 0x93046761DB8100F8ULL, 0x0353BA1DD3706DC8ULL, 
            0x5B07FFA3C11979E4ULL, 0xB082FAE6371252CAULL, 0xFF92E81C73D84A93ULL, 0xCA87BC712ED381C6ULL, 
            0x5043B7F301F20821ULL, 0x48E4DD29975A8901ULL, 0x681036D436777204ULL, 0x7485343E65EE5A9AULL, 
            0x93A0AE9B611F6060ULL, 0xF31E38982073B945ULL, 0x6D4D782904C1A8ABULL, 0xCD890B353D7089EEULL, 
            0xD956800A85DC3E01ULL, 0x60798C69C322FB81ULL, 0x85C137A603286ECEULL, 0x7AE8C15AE9594CD0ULL, 
            0x703C69F17B40E6B0ULL, 0x31128A3DC1C7AEC2ULL, 0x1F4E34DD43BFF7F7ULL, 0x321D516FEF583C95ULL
        },
        {
            0x364E46C36E3751C8ULL, 0xC673E50D53E428A8ULL, 0x4ABA7B4D65664707ULL, 0x65ED1D0598B70FB4ULL, 
            0xE11679B6739C46C3ULL, 0x20E17C41E19DFD75ULL, 0x7A57AC5B7B3D8B36ULL, 0x0CC0142258854431ULL, 
            0x2712C72421FA0FB6ULL, 0x12F112D82E27252BULL, 0x7D028D93F911A0ACULL, 0xF65D49EE343B5CE2ULL, 
            0x0488EED1EA6D2C79ULL, 0x494BA29DC04B9D43ULL, 0xF65E44EB0DC887CEULL, 0x1B5F1E266D99584CULL, 
            0x5D0E6E647FA5D63AULL, 0xD5F29FC049007A8CULL, 0x5A560A237FDA848EULL, 0xA7699E1E3D9B1FD6ULL, 
            0x1ECCAA900549A4DDULL, 0x22128019087A56B2ULL, 0x9E9707B1824F7620ULL, 0x7644D5F61E020F81ULL, 
            0xFDF31F3FCBE619D8ULL, 0x76B394D511E22FFDULL, 0x0C2F513471BAD9B6ULL, 0xA24C64D4AF197280ULL, 
            0xF21123F15E0EF782ULL, 0xCE8A63D4F179FFF9ULL, 0x2F8E0A8056A936C2ULL, 0x4B98D7387F461D10ULL
        },
        {
            0xA3242C977577BFC2ULL, 0x11F5CFE1FD571468ULL, 0x3CE57D565B95AC4FULL, 0x859842CADBA4437CULL, 
            0xBF2F59DA5649BEE9ULL, 0x5223C5F3B00982C2ULL, 0x09C982D0160DCEB2ULL, 0x40DD9FA1EEA865CDULL, 
            0x30FC7C50D42A3172ULL, 0x1C37A75931A15692ULL, 0xB653E14ECDCAECF4ULL, 0x40199F93FBD59B47ULL, 
            0x1C9AB990C97CB923ULL, 0x387CDCA2965D2FC1ULL, 0x6560B91AE9DFE69FULL, 0xF91CFACD652D8377ULL, 
            0x083791D1DF13834DULL, 0xB1C71D6CA43C1553ULL, 0x32C4E6A0935320E6ULL, 0x9609E6C43B2DB074ULL, 
            0x16BDD69A61A18E97ULL, 0x9AA45E1D772DE8C9ULL, 0x8F41BDC63BCDD7BDULL, 0x801B0F2DBD41C14BULL, 
            0x3F009D9BBAA2F4CCULL, 0x721374667057AB4CULL, 0xC5884E6F9FD2BCA2ULL, 0x1C000F7CBFA12CA6ULL, 
            0x40E4EF919F48FD3BULL, 0xAF604DB25C7EB92DULL, 0x68445D6831AFE8C6ULL, 0x8347AB01F13811EEULL
        },
        {
            0xCBEA4FD4A009BB5BULL, 0x5753D9EAB7301DFDULL, 0x02F4A768F9F8BD91ULL, 0x3A7B8441F1F11169ULL, 
            0x926619B2A7E7EE5AULL, 0x95E661A5B31E0D2FULL, 0xF7826BC6C62E1832ULL, 0xB2757E64C662C92AULL, 
            0x37F3F962C7C12B00ULL, 0x64F652B2696C5C7DULL, 0x83149EE76052EA60ULL, 0xB1436F0E1C96A266ULL, 
            0xC9B05B62CBC215EBULL, 0x66DAD6AE1AFF5BC8ULL, 0x5E98E23E957D13B7ULL, 0xA2818591C3FB31E7ULL, 
            0xB6F6D4262E8A90A2ULL, 0x1353FAD0D52470ECULL, 0x748D98A5C88A9A01ULL, 0xC324E2CA3F5D0E8FULL, 
            0x9B27EE12C5495F78ULL, 0x54D3862003EADF87ULL, 0x12D32D6832515939ULL, 0xFC7023CC44D34035ULL, 
            0x58F9F94106393618ULL, 0xDA217C799ADB3689ULL, 0x81C9BADF8BFB586BULL, 0x076BB91230EDF31EULL, 
            0x6CAFA0CD4CA4C085ULL, 0xCAF58950A17BB1C6ULL, 0x5626CC4A07E354FCULL, 0x43B96E214FEF4DD2ULL
        },
        {
            0x89BF7B43409A0D63ULL, 0xAEA26AFF6EF166FAULL, 0x843D84956061B31FULL, 0xDB119A034079EC6BULL, 
            0xA65D0A9C82470307ULL, 0x1633B2EC76543737ULL, 0x189FB5BD3CAD8E4EULL, 0x5A3B4E50F2BF1D28ULL, 
            0x840C9CC48DF3D70EULL, 0xFEE0C356596A8D59ULL, 0x0DCCB11F36A6B96EULL, 0x5FF4CC00D106A2EDULL, 
            0x96E23ECCB0C5D4C3ULL, 0x263317BFD04C270AULL, 0xC4F33D10AC66CCF3ULL, 0xA0DD2919FE0A36A8ULL, 
            0xB1DC0A6C9E973945ULL, 0xC5F50457E5555493ULL, 0x1EE5E5F9641853A1ULL, 0x17D7FBC918282F7EULL, 
            0x7D3AE3E22836A7F5ULL, 0x85E6BCEEBC8CE41EULL, 0xC7D2BDDEFB0044E9ULL, 0x895542DF41F7A688ULL, 
            0x6B26BA9206AA98F1ULL, 0xCE57097E2491A193ULL, 0xBD17FF608ECB08F2ULL, 0x4F172680C72DDECDULL, 
            0x2A2B4883265B2AC3ULL, 0x9D282886982DCE8BULL, 0xA035E084C4A449DFULL, 0x1853ECF29FDA528CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseHConstants = {
    0xADF4D344AF344971ULL,
    0x0D7BE01E8F18E04AULL,
    0xE093A5E093C5FCB3ULL,
    0xADF4D344AF344971ULL,
    0x0D7BE01E8F18E04AULL,
    0xE093A5E093C5FCB3ULL,
    0xD353D7E2FA7A1B22ULL,
    0x1E714D0E78E61194ULL,
    0xD0,
    0x9A,
    0x32,
    0x7C,
    0x01,
    0x86,
    0x53,
    0x10
};

